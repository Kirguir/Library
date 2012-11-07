//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "login.h"
#include "mform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLoginForm *LoginForm;
//---------------------------------------------------------------------------
__fastcall TLoginForm::TLoginForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TLoginForm::RGClick(TObject *Sender){
    switch(RG->ItemIndex){
        case 0: Edit1->Visible=false;break;
        case 1: Edit1->Visible=true;break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::BitBtn1Click(TObject *Sender){
    if((RG->ItemIndex==1)&&(Edit1->Text!="w9klpl219")){
        Application->MessageBox("Пароль неправильный!", "Внимание!", MB_OK);
    }else{
        if((RG->ItemIndex==0)||((RG->ItemIndex==1)&&(Edit1->Text=="w9klpl219"))){
            LoginForm->Hide();
            FirstForm->ShowModal();
            Close();
        }
    }
}
//---------------------------------------------------------------------------
