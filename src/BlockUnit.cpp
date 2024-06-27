//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "BlockUnit.h"
#include "DMUnit.h"
#include "DMVedUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBlockForm *BlockForm;
int pressBtn=0;
//1-Запретить
//0-Разрешить
  TDateTime w;
AnsiString mes = ""; //переменная для сообщений
//---------------------------------------------------------------------------
__fastcall TBlockForm::TBlockForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBlockForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this -> Close ();
}
//---------------------------------------------------------------------------
void __fastcall TBlockForm::BitBtn2Click(TObject *Sender)
{
PressBtn(1);
}
//---------------------------------------------------------------------------
void __fastcall TBlockForm::BitBtn1Click(TObject *Sender)
{
PressBtn(0);
}
//---------------------------------------------------------------------------
void __fastcall TBlockForm::PressBtn(int pressBtn)
{//функция определения какая нажата кнопка (0-Разрешить, 1-Запретить)
int block=0, per=0, rg=0;
bool tab_sheet; //true-изменение, false=переподача
//---изменение основных данных
if (PageControl1->ActivePageIndex==0)
{
   if (RadioGroup1->ItemIndex==-1)
   {
      mes="Выберите факультет!";
      ShowMessage(mes);
   }
   else
   {//открываем Q
      DM->BlockQ->Close();
      DM->BlockQ->ParamByName("fac")->AsInteger=RadioGroup1->ItemIndex+1;
      DM->BlockQ->Open();

      block=DM->BlockQBLOCK->Value;     //запоминаем поле BLOCK
      rg = RadioGroup1->ItemIndex+1;    //определения ItemIndex
      tab_sheet=true;
   }
}
else
{//---переподача документов
   if (RadioGroup2->ItemIndex==-1)
   {
       mes="Выберите факультет!";
       ShowMessage(mes);
   }
   else
   {
       DM->BlockQ->Close();
       DM->BlockQ->ParamByName("fac")->AsInteger=RadioGroup2->ItemIndex+1;
       DM->BlockQ->Open();

       per=DM->BlockQPEREPODACHA->Value; //запоминаем поле PEREPODACHA
       rg = RadioGroup2->ItemIndex+1;    //определения ItemIndex
       tab_sheet=false;
   }
}
//получение даты сервера
DMVed->QDate->Close();
DMVed->QDate->Open();
//DateServer=DateTimeToStr(SQLTimeStampToDateTime(DMVed->QDateCAST->Value));
 //w = SQLTimeStampToDateTime(DMVed->QDateCAST->Value);
DateServer=DateToStr(DMVed->QDateCAST->Value);



switch (pressBtn)
{
	case 0://0-полный доступ
                if (tab_sheet==true)
                {//if tab_sheet1
                   if (block==0)
                   {//if в БД есть разрешение
                        mes="Факультету " + IntToStr(rg) + " изменять статистику УЖЕ РАЗРЕШЕНО!";
                        ShowMessage(mes);
                        RadioGroup1->ItemIndex=-1;
                   }//end в БД есть разрешение
                   else
                   {//else даем разрешение
                         DM->BlockQ->Edit();
                         DM->BlockQBLOCK->Value=0;
                         DM->BlockQNOTE->Value="РАЗРЕШЕНО изменять данные с "+ DateServer;
                   }//and else даем разрешение
                }//and if tab_sheet1
                else
                {//else tab_sheet2
                   if (per==0)
                   {//if в БД есть разрешение
                        mes="Факультету " + IntToStr(rg) + " переподача документов УЖЕ РАЗРЕШЕНА!";
                        ShowMessage(mes);
                        RadioGroup1->ItemIndex=-1;
                   }//end в БД есть разрешение
                   else
                   {//else даем разрешение
                         DM->BlockQ->Edit();
                         DM->BlockQPEREPODACHA->Value=0;
                         DM->BlockQNOTE_PEREPODACHA->Value="РАЗРЕШЕНА переподача документов с "+ DateServer;
                   }//and else даем разрешение
                }//and if tab_sheet2
	        break;

	case 1://1-ограничение доступа
	        if (tab_sheet==true)
                {//if tab_sheet1
                   if (block==1)
                   {//if в БД есть запрет
                        mes="Факультету " + IntToStr(rg) + " изменять статистику УЖЕ ЗАПРЕЩЕНО!";
                        ShowMessage(mes);
                        RadioGroup1->ItemIndex=-1;
                   }//end в БД есть запрет
                   else
                   {//else даем запрет
                         DM->BlockQ->Edit();
                         DM->BlockQBLOCK->Value=1;
                         DM->BlockQNOTE->Value="ЗАПРЕЩЕНО изменять данные с "+ DateServer;
                   }//and else даем запрет
                }//and if tab_sheet1
                else
                {//else tab_sheet2
                    if (per==1)
                    {//if в БД есть разрешение
                        mes="Факультету " + IntToStr(rg) + " переподача документов УЖЕ ЗАПРЕЩЕНА!";
                        ShowMessage(mes);
                        RadioGroup1->ItemIndex=-1;
                    }//end в БД есть разрешение
                    else
                    {//else даем разрешение
                         DM->BlockQ->Edit();
                         DM->BlockQPEREPODACHA->Value=1;
                         DM->BlockQNOTE_PEREPODACHA->Value="ЗАПРЕЩЕНА переподача документов с "+ DateServer;
                    }//and else даем разрешение
                }//else tab_sheet2
        	break;
}
if (DM->BlockQ->State==dsEdit)
{
     try
     {
        DM->BlockQ->ApplyUpdates();
        DM->BlockQ->CommitUpdates();
        DM->BlockQ->Close();
        mes="Обновление прошло успешно!";
        ShowMessage(mes);
     }
     catch(...)
     {
        mes="Произошел сбой! Повторите операцию!";
        ShowMessage(mes);
     }
}
}//end функция определения какая нажата кнопка (0-Разрешить, 1-Запретить)
//---------------------------------------------------------------------------

