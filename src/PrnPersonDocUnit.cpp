//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PrnPersonDocUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxPreview"
#pragma resource "*.dfm"
TPrnPersonDocForm *PrnPersonDocForm;
//---------------------------------------------------------------------------
__fastcall TPrnPersonDocForm::TPrnPersonDocForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrnPersonDocForm::frxReport1AfterPrintReport(TObject *Sender)
{
	// После окончания печати отчёта
	if (frxReport1 != 0)
		frxReport1->PreviewForm->Close();
}
//---------------------------------------------------------------------------

