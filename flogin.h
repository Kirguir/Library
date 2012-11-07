//---------------------------------------------------------------------------

#ifndef floginH
#define floginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TLogin : public TForm
{
__published:	// IDE-managed Components
    TRadioGroup *RG;
    TMaskEdit *Pass;
    TBitBtn *BitBtn1;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *Name;
    void __fastcall RGClick(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLogin *Login;
//---------------------------------------------------------------------------
#endif
