//---------------------------------------------------------------------------

#ifndef otdformH
#define otdformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <DBTables.hpp>
#include "DBCtrlsEh.hpp"
#include "DBLookupEh.hpp"
#include <Mask.hpp>
#include "DBGridEh.hpp"
//---------------------------------------------------------------------------
class TOtdelForm : public TForm
{
__published:	// IDE-managed Components
    TDBGridEh *GridOtdel;
    void __fastcall GridOtdelKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TOtdelForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOtdelForm *OtdelForm;
//---------------------------------------------------------------------------
#endif
