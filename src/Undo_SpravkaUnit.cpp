//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Undo_SpravkaUnit.h"
#include "DMUnit.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TUndo_SpravkaForm *Undo_SpravkaForm;

//---------------------------------------------------------------------------
__fastcall TUndo_SpravkaForm::TUndo_SpravkaForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TUndo_SpravkaForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this -> Close ();
}
//---------------------------------------------------------------------------
void __fastcall TUndo_SpravkaForm::BitBtn1Click(TObject *Sender)
{
int n_a=DM->QUndo_AbitNOMER_AB->Value;
DM->QUndo_Abit->Edit();
DM->QUndo_AbitSTATUS->Value=0;
DM->QUndo_Abit->ApplyUpdates();
DM->QUndo_Abit->CommitUpdates();

TLocateOptions fl;
 if (!DM->QResult_Exam->Active) DM->QResult_Exam->Open();

  if (DM->QResult_Exam->Locate("NOMER_AB;BALL",VarArrayOf(OPENARRAY(Variant,(n_a,0))),fl))
   {
    DM->QResult_Exam->Delete();
    DM->QResult_Exam->ApplyUpdates();
    DM->QResult_Exam->CommitUpdates();
   }


  DM->QGroup_Count->Close();
  DM->QGroup_Count->ParamByName("N_FAC")->AsInteger=nom_fac;
  DM->QGroup_Count->Open();
  
DM->QUndo_Abit->Close();
DM->QUndo_Abit->ParamByName("N_FAC")->AsInteger=nom_fac;
DM->QUndo_Abit->ParamByName("ST")->AsInteger=3;
DM->QUndo_Abit->Open();
}
//---------------------------------------------------------------------------
