// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Exam_List_AllUnit.h"
#include "Exam_ListUnit.h"
#include "Exam_List_obUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "QuickRpt"
#pragma resource "*.dfm"
TExam_List_AllForm *Exam_List_AllForm;

// ---------------------------------------------------------------------------
__fastcall TExam_List_AllForm::TExam_List_AllForm(TComponent* Owner)
	: TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TExam_List_AllForm::QRCompositeReport1AddReports
	(TObject *Sender)

{
	QRCompositeReport1->Reports->Add(Exam_ListForm->QuickRep1);
	QRCompositeReport1->Reports->Add(Exam_List_obForm->QuickRep1);
}
// ---------------------------------------------------------------------------
