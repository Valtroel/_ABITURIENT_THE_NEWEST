//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoginPassUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLoginPass *LoginPass;

__fastcall TLoginPass::TLoginPass(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TLoginPass::Button2Click(TObject *Sender)
{
   Application -> Terminate ();
}

void __fastcall TLoginPass::FormActivate(TObject *Sender)
{
    if (Login->Text != "") {
        LoginPass->Password->SetFocus();
    }
    else {
        LoginPass->Login->SetFocus();
    }
}

