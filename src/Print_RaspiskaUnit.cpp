//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Print_RaspiskaUnit.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//#pragma link "RxGIF"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
TPrint_RaspiskaForm *Print_RaspiskaForm;
//---------------------------------------------------------------------------
__fastcall TPrint_RaspiskaForm::TPrint_RaspiskaForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrint_RaspiskaForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this -> Close ();
}
//---------------------------------------------------------------------------




