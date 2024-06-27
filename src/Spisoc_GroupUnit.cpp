//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Spisoc_GroupUnit.h"
#include "DMUnit.h"
#include "Func.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TSpisoc_GroupForm *Spisoc_GroupForm;
AnsiString Str_Line;

//---------------------------------------------------------------------------
 void __fastcall TSpisoc_GroupForm::Konkurs(int kon)
 {
 switch (kon)
  {
   case 0: Str_Line+=" Город "+AnsiString( DM->QStatistic_Every_DayCOUNT->Value);
   break;
   case 1: Str_Line+=" Село "+AnsiString(DM->QStatistic_Every_DayCOUNT->Value);
   break;
   case 2: Str_Line+=" КЦ "+AnsiString(DM->QStatistic_Every_DayCOUNT->Value);
   break;
   case 3: Str_Line+=" На 2 курс "+AnsiString(DM->QStatistic_Every_DayCOUNT->Value);
   break;
  }
 }

//---------------------------------------------------------------------------
 void __fastcall TSpisoc_GroupForm::Stroka()
{
int rec_count=DM->QStatistic_Every_Day->RecordCount;

int n_spec=DM->QStatistic_Every_DayN_SPECIALIZ->Value;
 Str_Line+=AnsiString(n_spec);
  Konkurs(DM->QStatistic_Every_DayKONKURS->Value);

for (int i=1;i<rec_count;i++)
 {
  DM->QStatistic_Every_Day->Next();
  if (DM->QStatistic_Every_DayN_SPECIALIZ->Value==n_spec)
  {
  Konkurs(DM->QStatistic_Every_DayKONKURS->Value);
  }           //if
  else
  {
   R1->Lines->Add(Str_Line);
   Str_Line="";
   n_spec=DM->QStatistic_Every_DayN_SPECIALIZ->Value;
   Str_Line+=AnsiString(n_spec);
  Konkurs(DM->QStatistic_Every_DayKONKURS->Value);
  }       //else
 } //while
 R1->Lines->Add(Str_Line);
}
//---------------------------------------------------------------------------
__fastcall TSpisoc_GroupForm::TSpisoc_GroupForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSpisoc_GroupForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this -> Close ();
}
//---------------------------------------------------------------------------


void __fastcall TSpisoc_GroupForm::Button1Click(TObject *Sender)
{
Str_Line="";

DM->QStatistic_Every_Day->Close();
DM->QStatistic_Every_Day->ParamByName("N_FAC")->AsInteger=nom_fac;
DM->QStatistic_Every_Day->ParamByName("VID_EDU")->AsInteger=0;
DM->QStatistic_Every_Day->Open();

R1->Lines->Add("Дневная форма получения образования");

Stroka();

Str_Line="";

DM->QStatistic_Every_Day->Close();
DM->QStatistic_Every_Day->ParamByName("N_FAC")->AsInteger=nom_fac;
DM->QStatistic_Every_Day->ParamByName("VID_EDU")->AsInteger=1;
DM->QStatistic_Every_Day->Open();

R1->Lines->Add("Заочная форма получения образования");

Stroka();

}
//---------------------------------------------------------------------------


