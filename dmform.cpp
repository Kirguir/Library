//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "dmform.h"
#include "bokform.h"
#include "treeform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma link "FIBDatabase"
#pragma resource "*.dfm"
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
    : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDM::dsOtdelBeforePost(TDataSet *DataSet){
    if(dsOtdel->Fields->Fields[3]->AsString=="")Abort();
}
//---------------------------------------------------------------------------
void __fastcall TDM::dsOtdelBeforeEdit(TDataSet *DataSet){
    DM->truOtdel->StartTransaction();
}
//---------------------------------------------------------------------------
//Если при добавлении новой книги не было выбранно файл архива с книгой, то
//данные невозможно записать в базу. Если файл выбран - данные архива и данные
//о книге заносяться в базу
void __fastcall TDM::dsBookBeforePost(TDataSet *DataSet){
    if(dsBook->State==dsInsert)InsertBook();
}
//----------------------------------------------------------------------------
void __fastcall TDM::InsertBook(){
    BookDlg->DefaultExt = "RAR";
    BookDlg->FileName = "*.rar";
    if (BookDlg->Execute()){
        HANDLE hFile;
        hFile = CreateFile(BookDlg->FileName.c_str(),GENERIC_READ, FILE_SHARE_READ,\
             NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        LONGLONG nFileLen = 0;
        if (hFile != INVALID_HANDLE_VALUE){
            DWORD dwSizeHigh=0, dwSizeLow=0;
            dwSizeLow = GetFileSize(hFile, &dwSizeHigh);
            nFileLen = (dwSizeHigh * (MAXDWORD+1)) + dwSizeLow;
            CloseHandle(hFile);
        }
        if (nFileLen > 52428800){
            Application->MessageBox("Размер файла должен быть меньше 50Мб.", "Ошибка", MB_OK);
            Abort();
        }
        TBlobField *bl = (TBlobField *)dsBook->FieldByName("BOOK");
        bl->LoadFromFile(BookDlg->FileName);
    }
    else
        Abort();
}
//---------------------------------------------------------------------------
void __fastcall TDM::qInsertBeforeExecute(TObject *Sender){
    DM->truOtdel->StartTransaction();
}
//---------------------------------------------------------------------------
void __fastcall TDM::dsOtdelAfterPost(TDataSet *DataSet){
    MainForm->Tree->Tag=-1;
}
//---------------------------------------------------------------------------
void __fastcall TDM::dsPredAfterPost(TDataSet *DataSet){
    MainForm->Tree->Tag=-1;
    dsSpis->FullRefresh();
}
//---------------------------------------------------------------------------
void __fastcall TDM::dsBookPostError(TDataSet *DataSet, EDatabaseError *E,
      TDataAction &Action){
    Application->MessageBox("Заполните все поля.", "Ошибка", MB_OK);
    Abort();
}
//---------------------------------------------------------------------------

void __fastcall TDM::dsBookAfterPost(TDataSet *DataSet){
    dsTree->FullRefresh();
}
//---------------------------------------------------------------------------

