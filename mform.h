//---------------------------------------------------------------------------

#ifndef mformH
#define mformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include "DBCtrlsEh.hpp"
#include "DBLookupEh.hpp"
#include <Mask.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include "DBGridEh.hpp"
#include <ToolWin.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TFirstForm : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *N4;
    TMenuItem *N5;
    TMenuItem *N6;
    TMenuItem *N7;
    TMenuItem *N8;
    TToolBar *ToolBar1;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TToolButton *ToolButton5;
    TToolButton *ToolButton6;
    TToolButton *ToolButton7;
    TToolButton *ToolButton8;
    TStatusBar *StatusBar1;
    TToolButton *ToolButton9;
    TImageList *ImageList1;
    void __fastcall N6Click(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall N8Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFirstForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFirstForm *FirstForm;
//---------------------------------------------------------------------------
#endif
