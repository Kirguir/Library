//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "flogin.h"
#include "mform.h"
#include "dmform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLogin *Login;
//---------------------------------------------------------------------------
__fastcall TLogin::TLogin(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLogin::RGClick(TObject *Sender){
if(RG->ItemIndex==1){
    Pass->Visible=1;
    Name->Visible=1;
    Label1->Visible=1;
    Label2->Visible=1;
}
else{
    Pass->Visible=0;
    Name->Visible=0;
    Label1->Visible=0;
    Label2->Visible=0;
}
}
//---------------------------------------------------------------------------
void __fastcall TLogin::BitBtn1Click(TObject *Sender){
AnsiString sql;
int id, ver;
if(RG->ItemIndex==1){
    sql.printf("select id, pass, version from login where login='%s'",Name->Text);
    DM->dsLogin->Close();
    DM->dsLogin->SelectSQL->Clear();
    DM->dsLogin->SelectSQL->Add(sql);
    DM->dsLogin->Open();
    sql=DM->dsLogin->FieldByName("PASS")->AsString;
    id=DM->dsLogin->FieldByName("ID")->AsInteger;
    ver=DM->dsLogin->FieldByName("VERSION")->AsInteger;
    if (ver!=104){
        Application->MessageBox("Текущая версия программы устарела. Обновите программу.", "Ошибка", MB_OK);
        return;
    }
    if(Pass->Text==sql){
        Login->Tag=id;
        Hide();
        FirstForm->ShowModal();
        Close();
    }else{
        Application->MessageBox("Неправильный пароль!", "Ошибка", MB_OK);
        return;
    }
}
Hide();
FirstForm->ShowModal();
Close();
}
//---------------------------------------------------------------------------




