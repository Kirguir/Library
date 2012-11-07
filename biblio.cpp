//---------------------------------------------------------------------------

#include <vcl.h>
#include "splash.h"
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("bokform.cpp", BookForm);
USEFORM("dmform.cpp", DM); /* TDataModule: File Type */
USEFORM("mform.cpp", FirstForm);
USEFORM("otdform.cpp", OtdelForm);
USEFORM("Predmetform.cpp", PredForm);
USEFORM("treeform.cpp", MainForm);
USEFORM("flogin.cpp", Login);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
         Application->Initialize();
         Application->Title = "Библиотека";
         SplashForm = new TSplashForm(Application);
         SplashForm->Show();
         SplashForm->Update();
         Application->CreateForm(__classid(TLogin), &Login);
         Application->CreateForm(__classid(TFirstForm), &FirstForm);
         Application->CreateForm(__classid(TBookForm), &BookForm);
         Application->CreateForm(__classid(TDM), &DM);
         Application->CreateForm(__classid(TOtdelForm), &OtdelForm);
         Application->CreateForm(__classid(TPredForm), &PredForm);
         Application->CreateForm(__classid(TMainForm), &MainForm);
         //SplashForm->Free();
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
