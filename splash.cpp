//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "splash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSplashForm *SplashForm;
//---------------------------------------------------------------------------
__fastcall TSplashForm::TSplashForm(TComponent* Owner)
    : TForm(Owner){
    DWORD h;
    DWORD Size=GetFileVersionInfoSize(Application->ExeName.c_str(), &h);
    if(Size==0) return;
    char *buf;
    buf=(char*)GlobalAlloc(GMEM_FIXED, Size);
    if(GetFileVersionInfo(Application->ExeName.c_str(), h, Size, buf)!=0)
    {
       char *ValueBuf;
       UINT Len;
       VerQueryValue(buf, "\\VarFileInfo\\Translation", &(void*)ValueBuf, &Len);
       if(Len>=4)
       {
          AnsiString CharSet=IntToHex((int)MAKELONG(*(int*)(ValueBuf+2), *(int*)ValueBuf), 8);

          if(VerQueryValue(buf,
                        AnsiString("\\StringFileInfo\\"+CharSet+"\\FileVersion").c_str(),
                        &(void*)ValueBuf,
                        &Len)!=0){
             Label3->Caption = ValueBuf;
          }
        }
    }
    GlobalFree(buf);
}
//---------------------------------------------------------------------------
void __fastcall TSplashForm::Timer1Timer(TObject *Sender){
    Close();
    Free();
}
//---------------------------------------------------------------------------

