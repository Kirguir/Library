//---------------------------------------------------------------------------

#ifndef PredmetformH
#define PredmetformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include "DBGridEh.hpp"
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TPredForm : public TForm
{
__published:	// IDE-managed Components
    TDBGridEh *DBGridEh1;
    TPanel *Panel1;
    TButton *Button1;
    TBitBtn *BitBtn1;
    void __fastcall DBGridEh1DblClick(TObject *Sender);
    void __fastcall DBGridEh1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TPredForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPredForm *PredForm;
//---------------------------------------------------------------------------
#endif
