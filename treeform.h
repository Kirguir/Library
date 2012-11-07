//---------------------------------------------------------------------------

#ifndef treeformH
#define treeformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBCtrlsEh.hpp"
#include "DBGridEh.hpp"
#include "DBLookupEh.hpp"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TDBGridEh *GridBook;
    TPanel *Panel;
    TTreeView *Tree;
    TToolBar *ToolBar1;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TToolButton *ToolButton5;
    TStatusBar *StatusBar1;
    TImageList *ImageList1;
    TPopupMenu *PM1;
    TMenuItem *N1;
    TMenuItem *N2;
    TToolButton *ToolButton6;
    TToolButton *ToolButton7;
    TToolButton *ToolButton8;
    TMenuItem *N3;
    TDBMemo *DBMemo1;
    TPopupMenu *PM2;
    TMenuItem *N4;
    TMenuItem *N5;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall TreePaint();
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall TreeChange(TObject *Sender, TTreeNode *Node);
    void __fastcall PutBook(TObject *Sender);
    void __fastcall FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall ExitClick(TObject *Sender);
    void __fastcall GetBook(TObject *Sender);
    void __fastcall GridBookKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall DeleteBook(TObject *Sender);
    void __fastcall PM2Popup(TObject *Sender);
    void __fastcall N5Click(TObject *Sender);
    void __fastcall GridBookMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
private:	// User declarations
public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
typedef struct MyRec{
    short int otd,obu,kurs;
} TMyRec;
typedef TMyRec *PMyRec;
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
