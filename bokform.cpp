//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "bokform.h"
#include "dmform.h"
#include "treeform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBGridEh"
#pragma resource "*.dfm"
TBookForm *BookForm;
//---------------------------------------------------------------------------
__fastcall TBookForm::TBookForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBookForm::DBGridEh1KeyDown(TObject *Sender, WORD &Key,TShiftState Shift){
    if((Key == VK_DELETE)&&!(DM->dsBook->State==dsEdit))
        try{
            DM->dsBook->Delete();
        }
        catch(const Exception &E){
            Application->MessageBox("Невозможно удалить книгу. Книга используется.", "Ошибка", MB_OK);
        }
}
//---------------------------------------------------------------------------
void __fastcall TBookForm::BitBtn2Click(TObject *Sender){
    MainForm->Tree->Tag=DM->dsBook->FieldByName("KOD")->AsInteger;
    ModalResult=mrOk;
    BookForm->BitBtn2->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TBookForm::BitBtn3Click(TObject *Sender){
    DM->dsBook->Edit();
    DM->InsertBook();
    DM->dsBook->Post();
}
//---------------------------------------------------------------------------
void __fastcall TBookForm::FormClose(TObject *Sender, TCloseAction &Action){
    DM->dsBook->Cancel();
    BookForm->BitBtn2->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TBookForm::FilterEditChange(TObject *Sender){
    AnsiString filter,str;
    int indx,i=0;
    indx=FilterBox->ItemIndex;
    str=FilterEdit->Text;
    if(indx>0)i=2;
    if(str!="")i++;
    switch(i){
        case 1:filter.printf("F_AUTHOR LIKE '%s%%'",str);break;
        case 2:filter.printf("TYPEBOOK=%d",indx);break;
        case 3:filter.printf("TYPEBOOK=%d AND F_AUTHOR LIKE '%s%%'",indx,str);break;
        default:filter="";
    }
    DM->dsBook->Filter=filter;
}
//---------------------------------------------------------------------------


