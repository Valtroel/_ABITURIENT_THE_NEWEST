//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Print_GroupUnit.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPrint_GroupForm *Print_GroupForm;
//---------------------------------------------------------------------------
__fastcall TPrint_GroupForm::TPrint_GroupForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrint_GroupForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this -> Close ();
}
//---------------------------------------------------------------------------

