//---------------------------------------------------------------------------

#ifndef bokformH
#define bokformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <Buttons.hpp>
#include "DBGridEh.hpp"
#include <DBCtrls.hpp>

//---------------------------------------------------------------------------
class TBookForm : public TForm
{
__published:	// IDE-managed Components
    TDBGridEh *DBGridEh1;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TBitBtn *BitBtn3;
    TComboBox *FilterBox;
    TEdit *FilterEdit;
    TDBMemo *DBMemo1;
    void __fastcall DBGridEh1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall BitBtn2Click(TObject *Sender);
    void __fastcall BitBtn3Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FilterEditChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TBookForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBookForm *BookForm;
//---------------------------------------------------------------------------
#endif
