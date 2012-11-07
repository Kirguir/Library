//---------------------------------------------------------------------------
//удаление предметов из дерева
#include <vcl.h>
#pragma hdrstop

#include "treeform.h"
#include "dmform.h"
#include "bokform.h"
#include "Predmetform.h"
#include "flogin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBCtrlsEh"
#pragma link "DBGridEh"
#pragma link "DBLookupEh"
#pragma resource "*.dfm"
TMainForm *MainForm;
int create=0;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//Если форма отображается впервые вызывает функцию генерации древа.
//Если вход не под администратором прячет кнопки доступа к справочникам.
void __fastcall TMainForm::FormShow(TObject *Sender){
    if(!create){
        TreePaint();
        create=1;
    }
    if(Login->Tag==0){
        ToolButton2->Visible=false;
        ToolButton3->Visible=false;
        ToolButton4->Visible=false;
        ToolButton5->Visible=false;
        N1->Visible=false;
        N3->Visible=false;
    }
}
//---------------------------------------------------------------------------
//Функция генерации древа с предметами и специальностями.
void __fastcall TMainForm::TreePaint(){
    TTreeNode *Node,*Node1,*Node2,*Node3;
    PMyRec MyRecPtr;
    AnsiString filter;
    int otd,obu;
    Tree->Items->Clear(); // remove any existing nodes
    DM->dsLookup->First();
    //просматриваем таблицу ВУЗов и создаем корневые узлы древа
    while(!DM->dsLookup->Eof){
        Node=Tree->Items->AddObject(NULL,DM->dsLookup->FieldByName("VUZ")->AsString,\
        (void*)DM->dsLookup->FieldByName("ID")->AsInteger);
        DM->dsOtdel->First();
        //просматриваем таблицу специальностей и добавляем в древо специальности
        //соответственно ВУЗам
        while(!DM->dsOtdel->Eof){
            if(DM->dsOtdel->FieldByName("TVUZ")->AsInteger==DM->dsLookup->FieldByName("ID")->AsInteger){
                Node1=Tree->Items->AddChildObject(Node,DM->dsOtdel->FieldByName("N_OTDEL")->AsString,\
                (void*)DM->dsOtdel->FieldByName("KOD")->AsInteger);
                otd=DM->dsOtdel->FieldByName("KOD")->AsInteger;
                //Добавляем дочерний узел к специальности -"Денна форма навяання"
                Node2=Tree->Items->AddChild(Node1,"Денна");
                obu=1;
                for(int i=1;i<7;i++){
                    MyRecPtr=new TMyRec;
                    MyRecPtr->otd=otd;
                    MyRecPtr->obu=obu;
                    MyRecPtr->kurs=i;
                    //Добавляем в древо узлы соответствующие курсам с 1 по 5
                    Node3=Tree->Items->AddChildObject(Node2,"Курс "+AnsiString(i),MyRecPtr);
                    //Отфильтровуем в таблице связей специальностей, курса и предметов
                    //нужные записи
                    filter.printf("KOTD=%d and FOBUCH=%d and KURS=%d",otd,obu,i);
                    DM->dsSpis->Filter=filter;
                    //добавляем оставшиеся записи в древо
                    while(!DM->dsSpis->Eof){
                        Tree->Items->AddChildObject(Node3,DM->dsSpis->FieldByName("N_PREDMET")->AsString,\
                        (void*)DM->dsSpis->FieldByName("ID")->AsInteger);
                        DM->dsSpis->Next();
                    }
                }
                //То же для "Денноъ форми навчання"
                Node2=Tree->Items->AddChild(Node1,"Заочна");
                obu=2;
                for(int i=1;i<7;i++){
                    MyRecPtr=new TMyRec;
                    MyRecPtr->otd=otd;
                    MyRecPtr->obu=obu;
                    MyRecPtr->kurs=i;
                    Node3=Tree->Items->AddChildObject(Node2,"Курс "+AnsiString(i),MyRecPtr);
                    filter.printf("KOTD=%d and FOBUCH=%d and KURS=%d",otd,obu,i);
                    DM->dsSpis->Filter=filter;
                    while(!DM->dsSpis->Eof){
                        Tree->Items->AddChildObject(Node3,DM->dsSpis->FieldByName("N_PREDMET")->AsString,\
                        (void*)DM->dsSpis->FieldByName("ID")->AsInteger);
                        DM->dsSpis->Next();
                    }
                }
            }
            DM->dsOtdel->Next();
        }
        DM->dsLookup->Next();
    }
}
//-----------------------------------------------------------------------------------------------
//Функция создания связки предмета с нужной специальностью и курсом
void __fastcall TMainForm::Button3Click(TObject *Sender){
    PredForm->Tag=1;
    PredForm->Button1->Visible=true;
    if(PredForm->ShowModal()==mrOk){
        TTreeNode *Node;
        AnsiString filter;
        int otd,obu,kurs,pred;
        //Выбираем мз выбранного узла древа значения курса, специальности и
        //формы обучения
        otd=PMyRec(Tree->Selected->Data)->otd;
        obu=PMyRec(Tree->Selected->Data)->obu;
        kurs=PMyRec(Tree->Selected->Data)->kurs;
        pred=Tree->Tag;
        Tree->Tag=0;
        //Проверяем нет ли такого предмета на данном курсе выбранной специальности
        filter.printf("KOTD=%d and FOBUCH=%d and KURS=%d and KPRED=%d",otd,obu,kurs,pred);
        DM->dsSpis->Filter=filter;
        //если есть выводим предупреждающее сообщение и завершаем процедуру
        if(DM->dsSpis->RecNo!=0){
            Application->MessageBox("Такая связка уже есть.", "Look", MB_OK);
        }else{
        //если нет - создаем нужную связку в таблице
            AnsiString sql;
            sql.printf("insert into spis2 (kotd,kpred,kurs,fobuch) values (%d,%d,%d,%d)",otd,pred,kurs,obu);
            DM->qInsert->SQL->Clear();
            DM->qInsert->SQL->Add(sql);
            DM->qInsert->Prepare();
            DM->qInsert->ExecQuery();
            DM->dsSpis->Close();
            DM->dsSpis->Open();
            //Добавляем в древо новый узел
            Tree->Items->AddChildObject(Tree->Selected,DM->dsSpis->FieldByName("N_PREDMET")->AsString,\
            (void*)DM->dsSpis->FieldByName("ID")->AsInteger);
        }
    }
}
//---------------------------------------------------------------------------
//При перемещении по древу опеределяем уровень выбранного узла
//и блокуриуем или разблокуруем кнопки панели инструментов
void __fastcall TMainForm::TreeChange(TObject *Sender, TTreeNode *Node){
    AnsiString filter;
    ToolButton2->Enabled=false;
    ToolButton4->Enabled=false;
    ToolButton5->Enabled=false;
    ToolButton6->Enabled=false;
    switch(Node->Level){
        case 4: filter.printf("ID=%d",(int*)Node->Data);
                DM->dsTree->Filter=filter;
                ToolButton4->Enabled=true;
                if(DM->dsTree->RecNo!=0){
                    ToolButton5->Enabled=true;
                    ToolButton6->Enabled=true;
                }
                break;
        case 3: ToolButton2->Enabled=true;
        default:filter.printf("ID=%d",9999);
                DM->dsTree->Filter=filter;
    }
}
//---------------------------------------------------------------------------
//Процедура добавления книги выбранному предмету
void __fastcall TMainForm::PutBook(TObject *Sender){
    BookForm->BitBtn2->Visible=true;
    if(BookForm->ShowModal()==mrOk){
        int bkod,sid,upkod,uid;
        AnsiString sql;
        bkod=Tree->Tag;
        sid=(int)Tree->Selected->Data;
        uid=Login->Tag;
        //Проверяем это добавление новой книги или замена
        switch(((TComponent *)Sender)->Tag){
            case 0: sql.printf("insert into spisbook (id,kbook,iduser) values (%d,%d,%d)",sid,bkod,uid);
                    break;
            case 1: upkod=DM->dsTree->FieldByName("KBOOK")->Value;
                    sql.printf("update spisbook set kbook=%d, iduser=%d where id=%d and kbook=%d",bkod,uid,sid,upkod);
        }
        DM->dsTree->First();
        //Проверка если данная книга в выбранном разделе
        while(!DM->dsTree->Eof){
            if(DM->dsTree->FieldByName("KBOOK")->AsInteger==bkod){
                Application->MessageBox("Эта книга здесь уже есть!", "Look", MB_OK);
                return;
            }
            DM->dsTree->Next();
        }
        DM->qInsert->SQL->Clear();
        DM->qInsert->SQL->Add(sql);
        DM->qInsert->Prepare();
        DM->qInsert->ExecQuery();
        DM->dsTree->Close();
        DM->dsTree->Open();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize){
    if(NewWidth!=MainForm->Width)MainForm->Align=alClient;
    if(NewWidth<MainForm->Width)MainForm->Align=alNone;
}
//---------------------------------------------------------------------------
//Если в таблицах которые используються для построения древа были изменения
//вызывается функция перерисовки древа
void __fastcall TMainForm::FormActivate(TObject *Sender){
    if(Tree->Tag==-1){
        TreePaint();
        Tree->Tag=0;
    }
}
//---------------------------------------------------------------------------
//Процедура получения книги из базы
void __fastcall TMainForm::GetBook(TObject *Sender){
    HWND hWnd;
    AnsiString filter,path;
    path=getenv("TEMP");
    path+="\\temp.rar";
    int bkod=DM->dsTree->FieldByName("KBOOK")->Value;
    filter.printf("KOD=%d",bkod);
    DM->dsBook->Filter=filter;
    DM->dsBook->Filtered=true;
    TBlobField *bl = (TBlobField *)DM->dsBook->FieldByName("BOOK");
    bl->SaveToFile(path);
    ShellExecute(hWnd, "open",path.c_str(), NULL, NULL, SW_SHOWNORMAL);
    DM->dsBook->Filtered=false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExitClick(TObject *Sender){
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GridBookKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift){
if(Key == VK_DELETE)
    DeleteBook(this);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DeleteBook(TObject *Sender){
    int id, kbook;
    AnsiString sql;
    id=DM->dsTree->FieldByName("ID")->AsInteger;
    kbook=DM->dsTree->FieldByName("KBOOK")->AsInteger;
    sql.printf("delete from spisbook where id=%d and kbook=%d",id,kbook);
    DM->qInsert->SQL->Clear();
    DM->qInsert->SQL->Add(sql);
    //DM->qInsert->Prepare();
    DM->qInsert->ExecQuery();
    DM->dsTree->FullRefresh();
    //DM->dsTree->Close();
    //DM->dsTree->Open();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PM2Popup(TObject *Sender){
    N5->Visible=true;
    N4->Visible=true;
    switch(Tree->Selected->Level){
        case 3:N5->Visible=false;break;
        case 4:N4->Visible=false;break;
        default:N5->Visible=false;N4->Visible=false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N5Click(TObject *Sender){
    AnsiString sql;
    sql.printf("delete from spis2 where id=%d",(int)Tree->Selected->Data);
    try{
        DM->qInsert->SQL->Clear();
        DM->qInsert->SQL->Add(sql);
        DM->qInsert->ExecQuery();
        DM->dsSpis->FullRefresh();
        TreePaint();
    }catch(const Exception &E){
        Application->MessageBox("Удалите сначала книги.", "Ошибка", MB_OK);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::GridBookMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y){
TGridCoord Cell = GridBook->MouseCoord(X,Y);
try{
    GridBook->Hint = "";
    GridBook->ShowHint = false;
    if ((Cell.X <= 0)||(Cell.Y <= 0)) return;
    GridBook->ShowHint = true;
    GridBook->Hint="Последний раз запись редактировалась: "+DM->dsTree->FieldByName("LOGIN")->AsString;
//    if (GridBook->Columns->Items[Cell.X-1]->Title->Caption == "Название"){
//     GridBook->ShowHint = true;
//     GridBook->Hint = "Количество оказанной амбулаторно-поликлинической помощи";
//   DBGrid_Med->Hint =
//   Tbl_Med->FieldByName(DBGrid_Med->Columns->Items[Cell.X-1]->FieldName)->AsInteger;
//  }
//    if (GridBook->Columns->Items[Cell.X-1]->Title->Caption == "Автор"){
//     GridBook->ShowHint = true;
//     GridBook->Hint = "Количество оказанной стационарной помощи";
//   DBGrid_Med->Hint =
//   Tbl_Med->FieldByName(DBGrid_Med->Columns->Items[Cell.X-1]->FieldName)->AsInteger;
//    }
 }
 catch(...) {}
}
//---------------------------------------------------------------------------

