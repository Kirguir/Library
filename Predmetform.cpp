//---------------------------------------------------------------------------
//перерисовывать дерево после редактирования предметов
//Общеобразовательные предметы
#include <vcl.h>
#pragma hdrstop

#include "Predmetform.h"
#include "dmform.h"
#include "treeform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBGridEh"
#pragma resource "*.dfm"
TPredForm *PredForm;
//---------------------------------------------------------------------------
__fastcall TPredForm::TPredForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//Обработчик двойного клика на гриде с предметами. Передает в форму с TreeView
//код предмета
void __fastcall TPredForm::DBGridEh1DblClick(TObject *Sender){
    if(PredForm->Tag==1){
        MainForm->Tree->Tag=DM->dsPred->FieldByName("KOD")->AsInteger;
        ModalResult=mrOk;
        PredForm->Tag=0;
    }
}
//---------------------------------------------------------------------------
//Обработчик нажатия клавиши DELETE. Удаляет запись если DataSourse не в
//режиме редактирования
void __fastcall TPredForm::DBGridEh1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift){
    if((Key == VK_DELETE)&&!(DM->dsPred->State==dsEdit))
        try{
            DM->dsPred->Delete();
        }
        catch(const Exception &E){
            Application->MessageBox("Невозможно удалить предмет. Предмет используется.", "Ошибка", MB_OK);
        }
}
//---------------------------------------------------------------------------


void __fastcall TPredForm::FormClose(TObject *Sender, TCloseAction &Action){
    if(DM->dsPred->State==dsEdit)DM->dsPred->Post();
    if(DM->dsPred->State==dsInsert)DM->dsPred->Cancel();
    Button1->Visible=false;
}
//---------------------------------------------------------------------------

