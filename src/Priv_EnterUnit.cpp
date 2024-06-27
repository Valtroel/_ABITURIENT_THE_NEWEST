//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Priv_EnterUnit.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPriv_EnterForm *Priv_EnterForm;
//---------------------------------------------------------------------------
__fastcall TPriv_EnterForm::TPriv_EnterForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPriv_EnterForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this -> Close ();
}
//---------------------------------------------------------------------------
void __fastcall TPriv_EnterForm::BitBtn4Click(TObject *Sender)
{
if (DM->QAbitur_Priv_Enter->State==dsInsert)
{
 try
 {
 DM->QAbitur_Priv_EnterNOMER_AB->Value=DM->QAbituraNOMER_AB->Value;
 DM->QAbitur_Priv_Enter->ApplyUpdates();
 DM->QAbitur_Priv_Enter->CommitUpdates();
 }
 catch(...)
 {
  ShowMessage("Нажмите кнопку ОТМЕНИТЬ и попробуйте еще раз!");
 }
}
DM->QAbitur_Priv_Enter->Insert();

}
//---------------------------------------------------------------------------
void __fastcall TPriv_EnterForm::BitBtn1Click(TObject *Sender)
{

if (DM->QAbitur_Priv_Enter->State!=dsBrowse)
{
DM->QAbitur_Priv_EnterNOMER_AB->Value=DM->QAbituraNOMER_AB->Value;
DM->QAbitur_Priv_Enter->ApplyUpdates();
DM->QAbitur_Priv_Enter->CommitUpdates();
}
}
//---------------------------------------------------------------------------
void __fastcall TPriv_EnterForm::BitBtn2Click(TObject *Sender)
{
DM->QAbitur_Priv_Enter->CancelUpdates();        
}
//---------------------------------------------------------------------------
void __fastcall TPriv_EnterForm::BitBtn3Click(TObject *Sender)
{
if (DM->QAbitur_Priv_Enter->State!=dsBrowse)
{
DM->QAbitur_Priv_EnterNOMER_AB->Value=DM->QAbituraNOMER_AB->Value;
DM->QAbitur_Priv_Enter->ApplyUpdates();
DM->QAbitur_Priv_Enter->CommitUpdates();
}

Close();
}
//---------------------------------------------------------------------------
void __fastcall TPriv_EnterForm::FormActivate(TObject *Sender)
{
DM->QAbitur_Priv_Enter->Close();
DM->QAbitur_Priv_Enter->ParamByName("N_AB")->AsInteger=DM->QAbituraNOMER_AB->Value;
DM->QAbitur_Priv_Enter->Open();
}
//---------------------------------------------------------------------------
void __fastcall TPriv_EnterForm::BitBtn5Click(TObject *Sender)
{
DM->QAbitur_Priv_Enter->Delete();
 DM->QAbitur_Priv_Enter->ApplyUpdates();
 DM->QAbitur_Priv_Enter->CommitUpdates();
DM->QAbitur_Priv_Enter->Close();
DM->QAbitur_Priv_Enter->ParamByName("N_AB")->AsInteger=DM->QAbituraNOMER_AB->Value;
DM->QAbitur_Priv_Enter->Open();
}
//---------------------------------------------------------------------------

