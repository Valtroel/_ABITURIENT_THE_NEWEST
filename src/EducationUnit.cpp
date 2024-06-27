// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EducationUnit.h"
#include "DMUnit.h"
#include "AbiturUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEducationForm *EducationForm;
bool state_document = false; // ���� ��������� ��� �� ����, �� false
int nom; // ����� �����������

// ---------------------------------------------------------------------------
__fastcall TEducationForm::TEducationForm(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TEducationForm::BitBtn1Click(TObject *Sender) {
	// if (DM->QSertificat->State==dsInactive) DM->QSertificat->Open();
	TLocateOptions sss;
	if (DM->QEducation->Locate("NOMER_AB;N_EDU_DOC",
		VarArrayOf(OPENARRAY(Variant, (nom, DBLookupComboBox1->KeyValue))
		), sss)) {
		ShowMessage(
			"� ����������� ��� ���� �������� � ����� �����������, ��������� ����������!");
	}
	try { // try

		DM->QEducation->ApplyUpdates();
		DM->QEducation->CommitUpdates();
		state_document = true;

		TLocateOptions flag;
		if (!DM->QResult_Exam->Active)
			DM->QResult_Exam->Open();

	}
	catch (...) {
		DM->QEducation->CancelUpdates();
		ShowMessage("��������� ���� ��� ����������, ���������� ��� ���!");
	}
	// ������ ����������� ��������� ���������
	DBLookupComboBox1->Enabled = false;
	EducationForm->Close();
}

// ---------------------------------------------------------------------------
void __fastcall TEducationForm::BitBtn3Click(TObject *Sender) {
	// ������ ������� ����������

	TLocateOptions Opts;
	Opts.Clear();
	Variant locvalues[3];
	locvalues[0] = Variant(nom); // ����� �����������
	locvalues[1] = Variant(DBLookupComboBox1->KeyValue); // �������
	locvalues[2] = Variant(1);
	// ������ ���������� ������  1 - ��� ����������������� ������������

	// if(Application->MessageBox("    �� ������������� ������ ������� ���� ����������?", "", MB_YESNO) == mrYes)
	AnsiString ansi_string1 =
		"    �� ������������� ������ ������� ���� �������� �� �����������?";
	/* ���� ������ */
	wchar_t * UnicodeString1 = new wchar_t[ansi_string1.WideCharBufSize()];
	/* ������-���������� */
	ansi_string1.WideChar(UnicodeString1, ansi_string1.WideCharBufSize());
	ansi_string1 = ""; /* ���� ������ */
	wchar_t * UnicodeString2 = new wchar_t[ansi_string1.WideCharBufSize()];
	/* ������-���������� */
	ansi_string1.WideChar(UnicodeString2, ansi_string1.WideCharBufSize());
	if (Application->MessageBox(UnicodeString1, UnicodeString2,
		MB_YESNO) == mrYes) { // if  MessageBox==Yes

		// �������� ������� � �����������
		if (DM->QEducation->Locate("NOMER_AB;N_EDU_DOC", VarArrayOf(locvalues,
			1), Opts)) { // if ����� QEducation ������ - �������
			DM->QEducation->Delete();
			DM->QEducation->ApplyUpdates();
			DM->QEducation->CommitUpdates();
		} // end if ����� QEducation ������ - �������

	} // end if  MessageBox==Yes
	delete[]UnicodeString1;
	delete[]UnicodeString2;
}

// ---------------------------------------------------------------------------
void __fastcall TEducationForm::FormActivate(TObject *Sender) {
	if (DM->QEducation->State == dsEdit) {
		DBLookupComboBox1->DataSource = DM->DSEducation;
		DBLookupComboBox1->DataField = DM->DSEducation->DataSet->FieldByName
			("N_EDU_DOC")->FieldName;
	}
}
// ---------------------------------------------------------------------------


