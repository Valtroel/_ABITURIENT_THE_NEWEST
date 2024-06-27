// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LetterUnit.h"
#include "MainUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxPreview"
#pragma resource "*.dfm"
TLetterForm *LetterForm;

// ---------------------------------------------------------------------------
__fastcall TLetterForm::TLetterForm(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TLetterForm::frxReport1AfterPrintReport(TObject *Sender) {
	// После окончания печати отчёта
	if (frxReport1 != 0)
		frxReport1->PreviewForm->Close();
}
// ---------------------------------------------------------------------------
