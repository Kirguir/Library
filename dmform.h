//---------------------------------------------------------------------------

#ifndef dmformH
#define dmformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include <DBTables.hpp>
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include <Dialogs.hpp>
#include "FIBDatabase.hpp"
#include <IBEvents.hpp>
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
    TDataSource *dsoLookup;
    TDataSource *dsoOtdel;
    TpFIBTransaction *trsOtdel;
    TpFIBTransaction *truOtdel;
    TpFIBDataSet *dsOtdel;
    TStringField *dsOtdelvuz;
    TFIBIntegerField *dsOtdelKOD;
    TFIBIntegerField *dsOtdelTVUZ;
    TFIBStringField *dsOtdelN_OTDEL;
    TpFIBDatabase *dbOtdel;
    TpFIBDataSet *dsPred;
    TDataSource *dsoPred;
    TpFIBDataSet *dsBook;
    TDataSource *dsoBook;
    TFIBIntegerField *dsBookKOD;
    TFIBStringField *dsBookF_AUTHOR;
    TFIBStringField *dsBookN_AUTHOR;
    TFIBStringField *dsBookT_AUTHOR;
    TFIBStringField *dsBookFULL_AUTHOR;
    TFIBStringField *dsBookBOOKNAME;
    TFIBIntegerField *dsBookTYPEBOOK;
    TDataSource *dsoTree;
    TpFIBDataSet *dsTree;
    TpFIBDataSet *dsLookup;
    TDataSource *dsoLookOtdel;
    TpFIBDataSet *dsLookOtdel;
    TpFIBQuery *qInsert;
    TOpenDialog *BookDlg;
    TFIBIntegerField *dsTreeID;
    TFIBStringField *dsTreeBOOKNAME;
    TFIBStringField *dsTreeFULL_AUTHOR;
    TFIBIntegerField *dsTreeTYPEBOOK;
    TpFIBDataSet *dsSpis;
    TFIBIntegerField *dsSpisID;
    TFIBStringField *dsSpisN_PREDMET;
    TFIBIntegerField *dsSpisKOTD;
    TFIBIntegerField *dsSpisKURS;
    TFIBSmallIntField *dsSpisFOBUCH;
    TFIBIntegerField *dsSpisKPRED;
    TDataSource *DataSource1;
    TFIBIntegerField *dsTreeKBOOK;
    TFIBBlobField *dsBookBOOK;
    TFIBBlobField *dsBookABOUT;
    TIBEvents *IBEvents1;
    TFIBBlobField *dsTreeABOUT;
        TDataSource *dsoLogin;
        TpFIBDataSet *dsLogin;
    TFIBStringField *dsTreeLOGIN;
    void __fastcall dsOtdelBeforePost(TDataSet *DataSet);
    void __fastcall dsOtdelBeforeEdit(TDataSet *DataSet);
    void __fastcall dsBookBeforePost(TDataSet *DataSet);
    void __fastcall qInsertBeforeExecute(TObject *Sender);
    void __fastcall dsOtdelAfterPost(TDataSet *DataSet);
    void __fastcall dsPredAfterPost(TDataSet *DataSet);
    void __fastcall InsertBook(void);
    void __fastcall dsBookPostError(TDataSet *DataSet, EDatabaseError *E,
          TDataAction &Action);
    void __fastcall dsBookAfterPost(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
    __fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
