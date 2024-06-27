//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Undo_Ab_Unit.h"
#include "DMUnit.h"
#include "Undo_Ab_1Unit.h"
#include "AbiturUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TUndo_Ab_Form *Undo_Ab_Form;
//---------------------------------------------------------------------------
__fastcall TUndo_Ab_Form::TUndo_Ab_Form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TUndo_Ab_Form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
DM->QAbitura->Close();
DM->QAbitura->SQL->Clear();
DM->QAbitura->SQL->Add("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
			ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
			D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
			EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
			N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
			N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
			NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
			NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
			PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
			STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
			VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
			WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
			DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA WHERE (N_FAC=:N_FAC) AND (STATUS=0)ORDER BY NOM_DELA");
DM->QAbitura->ParamByName("N_FAC")->AsInteger=nom_fac;
DM->QAbitura->Open();
AbiturForm->DBGrid1->Visible=true;
    this -> Close ();
}
//---------------------------------------------------------------------------
void __fastcall TUndo_Ab_Form::BitBtn2Click(TObject *Sender)
{
 Undo_Ab_1Form=new TUndo_Ab_1Form (this);
 Undo_Ab_1Form->DBLookupComboBox1->KeyValue=DM->QAbituraN_SPECIALIZ->Value;
 Undo_Ab_1Form->ShowModal();
 Undo_Ab_1Form->Caption="Восстановление";
 
}
//---------------------------------------------------------------------------
void __fastcall TUndo_Ab_Form::BitBtn3Click(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TUndo_Ab_Form::Edit1Change(TObject *Sender)
{
 Set<TLocateOption,0,1> flags;
    flags << loCaseInsensitive << loPartialKey;
  DM->QAbitura->Locate("FAM", Edit1->Text, flags);        
}
//---------------------------------------------------------------------------

void __fastcall TUndo_Ab_Form::FormActivate(TObject *Sender)
{
Edit1->SetFocus();
}
//---------------------------------------------------------------------------

