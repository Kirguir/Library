//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mform.h"
#include "otdform.h"
#include "Predmetform.h"
#include "bokform.h"
#include "dmform.h"
#include "WaitFr.h"
#include "treeform.h"
#include "flogin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBCtrlsEh"
#pragma link "DBLookupEh"
#pragma resource "*.dfm"
TFirstForm *FirstForm;
//---------------------------------------------------------------------------
__fastcall TFirstForm::TFirstForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFirstForm::N6Click(TObject *Sender){
    Close();
}
//---------------------------------------------------------------------------
//Обработчик меню главного окна
void __fastcall TFirstForm::N2Click(TObject *Sender){
    switch (((TComponent *)Sender)->Tag){
        case 1:OtdelForm->ShowModal();break;
        case 2:PredForm->ShowModal();break;
        case 3:BookForm->ShowModal();
    }
}
//---------------------------------------------------------------------------
void __fastcall TFirstForm::N8Click(TObject *Sender){
    MainForm->Show();
}
//---------------------------------------------------------------------------
//Если осуществленн вход под пользователем, то блокуруюься кнопки доступа к
//справочникам
void __fastcall TFirstForm::FormShow(TObject *Sender){
    if(Login->Tag==0){
        ToolButton2->Visible=false;
        ToolButton3->Visible=false;
        ToolButton4->Visible=false;
        ToolButton5->Visible=false;
        N1->Visible=false;
    }
}
//---------------------------------------------------------------------------

