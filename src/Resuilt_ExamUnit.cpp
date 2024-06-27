// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Resuilt_ExamUnit.h"
#include "DMUnit.h"
#include "Ball_Unit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TResult_ExamForm *Result_ExamForm;

// ---------------------------------------------------------------------------
__fastcall TResult_ExamForm::TResult_ExamForm(TComponent* Owner) : TForm(Owner)
{
}
// ---------------------------------------------------------------------------

void __fastcall TResult_ExamForm::FormClose(TObject *Sender,
	TCloseAction &Action) {
    this -> Close ();
}

// ---------------------------------------------------------------------------
void __fastcall TResult_ExamForm::Button1Click(TObject *Sender) {

	if (Edit1->Text != "" && DBLookupComboBox1->Text != "") {

		DM->QShow_Result_Exam->Close();
		DM->QShow_Result_Exam->ParamByName("N_GR")->AsString = Edit1->Text;
		DM->QShow_Result_Exam->ParamByName("PR")->AsString =
			DBLookupComboBox1->KeyValue;
		if (DBLookupComboBox1->Text == "‘изическа€ культура и спорт") {
			DBGrid1->Visible = false;
			DBGrid2->Visible = true;
		}
		else {
			DBGrid1->Visible = true;
			DBGrid2->Visible = false;
		}
		DM->QShow_Result_Exam->Open();
	}
	else {
		ShowMessage("¬ведите все данные!");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TResult_ExamForm::DBGrid1DblClick(TObject *Sender) {

	Ball_Form = new TBall_Form(this);
	Ball_Form->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TResult_ExamForm::FormActivate(TObject *Sender) {
	DM->QShow_Result_Exam->Close();
}
// ---------------------------------------------------------------------------
