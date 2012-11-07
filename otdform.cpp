//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "otdform.h"
#include "dmform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "DBCtrlsEh"
#pragma link "DBLookupEh"
#pragma link "DBGridEh"
#pragma resource "*.dfm"
TOtdelForm *OtdelForm;
static bool FirstTime = true;
//---------------------------------------------------------------------------
__fastcall TOtdelForm::TOtdelForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TOtdelForm::GridOtdelKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift){
    if((Key == VK_DELETE)&&!(DM->dsOtdel->State==dsEdit))
        try{
            DM->dsOtdel->Delete();
        }
        catch(const Exception &E){
            Application->MessageBox("Невозможно удалить специальность.", "Ошибка", MB_OK);
        }
}
//---------------------------------------------------------------------------
void __fastcall TOtdelForm::FormClose(TObject *Sender,
      TCloseAction &Action){
    if(DM->dsOtdel->State==dsEdit)DM->dsOtdel->Post();
    if(DM->dsOtdel->State==dsInsert)DM->dsOtdel->Cancel();
}
//---------------------------------------------------------------------------

