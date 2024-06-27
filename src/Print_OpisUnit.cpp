//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Print_OpisUnit.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
TPrint_OpisForm *Print_OpisForm;
//---------------------------------------------------------------------------
__fastcall TPrint_OpisForm::TPrint_OpisForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrint_OpisForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this -> Close ();
}
//---------------------------------------------------------------------------


