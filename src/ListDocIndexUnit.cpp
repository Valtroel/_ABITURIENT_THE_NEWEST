// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "DMUnit.h"
#include "ListDocIndexUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TListDocIndexForm *ListDocIndexForm;

// ---------------------------------------------------------------------------
__fastcall TListDocIndexForm::TListDocIndexForm(TComponent* Owner)
	: TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TListDocIndexForm::BitBtn1Click(TObject *Sender) {
	try {
		DM->ListDocFDQDOC_INDEX->Value = IndexEdit->Text;
		DM->ListDocFDQDATE_DOC->AsDateTime = StrToDate(DateEdit->Text);
		Close();
	}
	catch (...) {
		DateEdit->Text = "";
	}
}

// ---------------------------------------------------------------------------

void __fastcall TListDocIndexForm::DateEditClick(TObject *Sender) {
	ListDocIndexForm->DateEdit->SelStart = 0;
	ListDocIndexForm->DateEdit->SelLength = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TListDocIndexForm::FormShow(TObject *Sender) {
	if (ListDocIndexForm->DateEdit->Visible == true) {
		ListDocIndexForm->DateEdit->SetFocus();
		ListDocIndexForm->DateEdit->SelStart = 0;
		ListDocIndexForm->DateEdit->SelLength = 0;
	}
}
// ---------------------------------------------------------------------------
