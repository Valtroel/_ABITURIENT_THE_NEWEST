// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SpravUnit.h"
#include "DMUnit.h"
#include "DualList.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
//#pragma link "RxLogin"
//#pragma link "MyList"
//#pragma link "MyList"
#pragma resource "*.dfm"
TSpravForm *SpravForm;
// ������������ ������� �������������
AnsiString *mas_spec[2]; // ������ ������� � �������� �������������
AnsiString all_spec = ""; // ��� �������������, ��������� � ����������
int raion = 0; // ����� ��� ��

// ---------------------------------------------------------------------------
__fastcall TSpravForm::TSpravForm(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
// --------------����� ������ ������������� �� ��������
AnsiString TSpravForm::search_nomer(int rec_sp, AnsiString name) {
	AnsiString nomer;
	for (int i = 0; i < rec_sp; i++) {
		if (mas_spec[0][i] == name)
			nomer = mas_spec[1][i]; // ���������� ����� �������������
	}
	return nomer;
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::FormClose(TObject *Sender, TCloseAction &Action) {
    this -> Close ();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn1Click(TObject *Sender) {
	DM->TRegion->ApplyUpdates();
	DM->TRegion->CommitUpdates();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn3Click(TObject *Sender) {
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn2Click(TObject *Sender) {
	DM->TRegion->CancelUpdates();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::TabSheet1Show(TObject *Sender) {
	DBGrid1->SetFocus();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::DBGrid2Enter(TObject *Sender) {
	DBNavigator1->DataSource = DM->DSVid_Sport;
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::DBGrid3Enter(TObject *Sender) {
	DBNavigator1->DataSource = DM->DSCategory;
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::TabSheet7Show(TObject *Sender) {
	DBGrid2->SetFocus();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn4Click(TObject *Sender) {
	if (DM->TVid_Sport->State != dsBrowse) {
		DM->TVid_Sport->ApplyUpdates();
		DM->TVid_Sport->CommitUpdates();
	}
	if (DM->TCategory->State != dsBrowse) {
		DM->TCategory->ApplyUpdates();
		DM->TCategory->CommitUpdates();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn5Click(TObject *Sender) {
	DM->TVid_Sport->CancelUpdates();
	DM->TCategory->CancelUpdates();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::TabSheet8Show(TObject *Sender) {
	DBGrid4->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::DBGrid4Enter(TObject *Sender) {
	DBNavigator1->DataSource = DM->DSFaculty;
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn6Click(TObject *Sender) {
	DM->TFaculty->ApplyUpdates();
	DM->TFaculty->CommitUpdates();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn7Click(TObject *Sender) {
	DM->TFaculty->CancelUpdates();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet9Show(TObject *Sender) {
	DBGrid5->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::DBGrid5Enter(TObject *Sender) {
	DBNavigator1->DataSource = DM->DSSpecializ;
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn8Click(TObject *Sender) {
	DM->QSpecializN_FAC->Value = nom_fac;
	DM->QSpecializ->ApplyUpdates();
	DM->QSpecializ->CommitUpdates();
	DM->QSpecializ->Close();
	DM->QSpecializ->ParamByName("N_FAC")->AsSmallInt = nom_fac;
	DM->QSpecializ->Open();

	DM->CntrlExrcQr->Close();
    DM->CntrlExrcQr->Open();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn9Click(TObject *Sender) {
	DM->QSpecializ->CancelUpdates();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet4Show(TObject *Sender) {
	DBGrid6->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::DBGrid6Enter(TObject *Sender) {
	DBNavigator1->DataSource = DM->DSPredmet;
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn11Click(TObject *Sender) {
	DM->TPredmet->ApplyUpdates();
	DM->TPredmet->CommitUpdates();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn10Click(TObject *Sender) {
	DM->TPredmet->CancelUpdates();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet5Show(TObject *Sender) {
	DBGrid7->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::DBGrid7Enter(TObject *Sender) {
	DBNavigator1->DataSource = DM->DSKol_Place;
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn12Click(TObject *Sender)
{ // ������ "���������"
	DM->TKol_PlaceTEXT->Value = ComboBox1->ItemIndex;
	DM->TKol_PlacePRICE->Value = RadioGroup2->ItemIndex;
	DM->TKol_PlaceN_FAC->Value = nom_fac;
	DM->TKol_PlaceVID_EDU->Value = ComboBox2->ItemIndex;
	DM->TKol_Place->ApplyUpdates();
	DM->TKol_Place->CommitUpdates();
	Panel1->Visible = false;

}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn13Click(TObject *Sender) {
	DM->TKol_Place->CancelUpdates();
	Panel1->Visible = false;
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn14Click(TObject *Sender) {
	Panel1->Visible = true;
	ComboBox1->ItemIndex = 0;
	ComboBox1->Text = "";
	DM->TKol_Place->Insert();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn15Click(TObject *Sender) {
	DM->TRegion->Insert();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn18Click(TObject *Sender) {
	DM->TPredmet->Insert();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn19Click(TObject *Sender) {
	DBNavigator1->DataSource->DataSet->Insert();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn20Click(TObject *Sender) {
	DM->TFaculty->Insert();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn21Click(TObject *Sender) {
	DM->QSpecializ->Insert();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::TabSheet6Show(TObject *Sender) {
	DBGrid9->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::DBGrid9Enter(TObject *Sender) {
	DBNavigator1->DataSource = DM->DSCk;
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn25Click(TObject *Sender) {
	DM->TCk->Insert();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn26Click(TObject *Sender) {
	/* ��������������� �������� �� �����
	 if (DBGrid9->Columns->Items[4]->Field->Value==DBGrid9->Columns->Items[4]->PickList->Strings[0]) DM->TCkCUSTOMER->Value=0;
	 else DM->TCkCUSTOMER->Value=1; */

	if (DM->TCkN_REGION->Value == 5) {
		raion = 0;
	}

	if ((raion) || (DM->TCkN_REGION->Value == 5))
		DM->TCkN_CENTRE->Value = raion;
	else {
		ShowMessage("�� ����������� �����, ���������� ��� ��� ��� �������!");
		return;
	}

	DM->TCkN_FAC->Value = nom_fac;
	DM->TCk->ApplyUpdates();
	DM->TCk->CommitUpdates();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn27Click(TObject *Sender) {
	DM->TCk->CancelUpdates();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn22Click(TObject *Sender) {
	DM->TFoundation->Insert();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn30Click(TObject *Sender) {
	DM->TFoundation->ApplyUpdates();
	DM->TFoundation->CommitUpdates();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn31Click(TObject *Sender) {
	DM->TFoundation->CancelUpdates();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet10Show(TObject *Sender) {
	DBGrid11->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::DBGrid11Enter(TObject *Sender) {
	DBNavigator1->DataSource = DM->DSFoundation;
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::DBGrid1Enter(TObject *Sender) {
	DBNavigator1->DataSource = DM->DSRegion;
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::DBGrid7DblClick(TObject *Sender)
{ // ���������� ���������� ��������� ������ � ���� ��������������
	Panel1->Visible = true;
	// ������ ��� ������������� �� ������ �����! ������!!!
	if (DM->TKol_PlaceTEXT->Value == 3) {
		DM->TKol_Place->Edit();
		DM->TKol_PlacePRICE->Value = 1;
		DM->TKol_PlaceTEXT->Value = 0;
		DM->TKol_Place->ApplyUpdates();
		DM->TKol_Place->CommitUpdates();
	}
	ComboBox1->ItemIndex = DM->TKol_PlaceTEXT->Value;
	RadioGroup2->ItemIndex = DM->TKol_PlacePRICE->Value;
	ComboBox2->ItemIndex = DM->TKol_PlaceVID_EDU->Value;

	DM->TKol_Place->Edit();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::FormActivate(TObject *Sender) {
	DM->TKol_Place->Filter = "N_FAC=" + AnsiString(nom_fac);
	DM->TKol_Place->Filtered = true;

	DM->TCk->Filter = "N_FAC=" + AnsiString(nom_fac);
	DM->TCk->Filtered = true;

	DM->QCenter->Open();

	//!!!
	DM->CntrExrcTbl->Filter = "N_FAC=" + AnsiString(nom_fac);
	DM->CntrExrcTbl->Filtered = true;

	DM->CntrlExrcQr->Open();
	DM->SpecializQr->Close();
//	DM->SpecializQr->ParamByName("n_fac")->AsSmallInt = nom_fac;
	DM->SpecializQr->Open();
	DM->CntrExrcTbl->Active = true;
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn32Click(TObject *Sender)
{ // ������ �������� �� �������� ������
	all_spec = ""; // ������ �������������
	DM->QAdd_N_Group->Insert();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn33Click(TObject *Sender)
{ // ����� ��������� �� �������� ������
	if (Edit1->Text == "" || Edit2->Text == "" || ComboBox3->Text == "")
	{ // if �������� �� ������ ����
		ShowMessage("�� ��������� ��� ����!");
		return;
	} // end �������� �� ������ ����
	if (all_spec != "") { // if ������������� �������
		DM->QAdd_N_GroupNOM_GROUP->Value = Edit1->Text; // ����� ������
		DM->QAdd_N_GroupVID_EDU->Value = ComboBox3->ItemIndex; // ��� ��������
		DM->QAdd_N_GroupDESCRIBE->Value = all_spec; // ������ �������������
		DM->QAdd_N_GroupN_FAC->Value = nom_fac; // ���������
		DM->QAdd_N_GroupN_COUNT->Value = StrToInt(Edit2->Text);
		// ������������ ���������� ������� � ������

		try { // try ����������
			DM->QAdd_N_Group->ApplyUpdates();
			DM->QAdd_N_Group->CommitUpdates();
			Edit1->Text = ""; // ����� ������
			Edit2->Text = ""; // ���������� ������� � ������
			ComboBox3->ItemIndex = -1; // ��� ��������
		} // end try ����������
		catch (...) { // catch �������� �������
			ShowMessage("��������� ���� ��� ����������!");
			DM->QAdd_N_Group->CancelUpdates();
		} // end catch �������� �������
	} // end if ������������� �������
	else { // else �� ������� �� ���� �������������
		ShowMessage("�� ������� �������������!");
		return;
	} // end else �� ������� �� ���� �������������
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::SpeedButton1Click(TObject *Sender)
{ // ����� �������������

	DualListDlg = new TDualListDlg(this);
	DualListDlg->SrcList->Items->Clear();
	DualListDlg->DstList->Items->Clear();
     if (DM->QSpecializ->State == dsInactive) { // if ��������� �������������
		DM->QSpecializ->ParamByName("N_FAC")->AsInteger = nom_fac;
		DM->QSpecializ->Open();
	} // end if ��������� �������������
	DM->QSpecializ->First(); // �� ������ ������
	int rec_sp = DM->QSpecializ->RecordCount;
	for (int i = 0; i < 2; i++) { // for1
		mas_spec[i] = new AnsiString[rec_sp];
	}

	for (int i = 0; i < rec_sp; i++) // ������������ ������� �������������
	{ // for ������������ �������
		// ��� �������� � ����� ������
		mas_spec[0][i] = DM->QSpecializSPECIAL->Value;
		mas_spec[1][i] = AnsiString(DM->QSpecializN_SPECIALIZ->Value);
		DualListDlg->SrcList->Items->Add(DM->QSpecializSPECIAL->Value);
		// ����� ��������
	   //	mas_spec[1][i] = AnsiString(DM->QSpecializN_SPECIALIZ->Value);
		DM->QSpecializ->Next();
	} // end for ������������ �������
     DualListDlg->ShowModal();

	if (DM->printdlg == true) {
        all_spec += ".";
		for (int i = 0; i < DualListDlg->DstList->Count; i++)
		{ // for �������������
			all_spec += search_nomer(rec_sp, DualListDlg->DstList->Items->Strings[i]);
			all_spec += ".";
		} // end for �������������

		// �������� ������� ���������
		for (int i = 0; i < 2; i++)
			delete[]mas_spec[i];

	} // end if Execute  DualListDialog1
	else { // else Execute  DualListDialog1
		ShowMessage("�� �������� ����� �������������!!!");
	} // end else Execute  DualListDialog1


	// �������� ����������
  /*	MyList1->SourceList->Clear();
	MyList1->FOutList->Clear();

	if (DM->QSpecializ->State == dsInactive) { // if ��������� �������������
		DM->QSpecializ->ParamByName("N_FAC")->AsInteger = nom_fac;
		DM->QSpecializ->Open();
	} // end if ��������� �������������
	DM->QSpecializ->First(); // �� ������ ������
	int rec_sp = DM->QSpecializ->RecordCount;
	for (int i = 0; i < 2; i++) { // for1
		mas_spec[i] = new AnsiString[rec_sp];
	}

	for (int i = 0; i < rec_sp; i++) // ������������ ������� �������������
	{ // for ������������ �������
		// ��� �������� � ����� ������
		mas_spec[0][i] = DM->QSpecializSPECIAL->Value;
		MyList1->SourceList->Add(DM->QSpecializSPECIAL->Value);
		// ����� ��������
		mas_spec[1][i] = AnsiString(DM->QSpecializN_SPECIALIZ->Value);
		DM->QSpecializ->Next();
	} // end for ������������ �������

	if (MyList1->Execute(MyList1)) { // if Execute  DualListDialog1
		all_spec += ".";
		for (int i = 0; i < MyList1->FOutList->Count; i++)
		{ // for �������������
			all_spec += search_nomer(rec_sp, MyList1->FOutList->Strings[i]);
			all_spec += ".";
		} // end for �������������

		// �������� ������� ���������
		for (int i = 0; i < 2; i++)
			delete[]mas_spec[i];

	} // end if Execute  DualListDialog1
	else { // else Execute  DualListDialog1
		ShowMessage("�� �������� ����� �������������!!!");
	} // end else Execute  DualListDialog1   */
	delete DualListDlg;
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::DBGrid12Enter(TObject *Sender) {
	DBNavigator1->DataSource = DM->DSAdd_N_Group;
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::TabSheet11Show(TObject *Sender) {
	DM->QAdd_N_Group->Close();
	DM->QAdd_N_Group->ParamByName("FAC")->AsSmallInt = nom_fac;
	DM->QAdd_N_Group->Open();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravForm::DBGrid12DblClick(TObject *Sender) {
	DM->QAdd_N_Group->Edit();
	Edit1->Text = DM->QAdd_N_GroupNOM_GROUP->Value; // ����� ������
	Edit2->Text = IntToStr(DM->QAdd_N_GroupN_COUNT->Value);
	// ���������� ������� � ������
	ComboBox3->ItemIndex = DM->QAdd_N_GroupVID_EDU->Value; // ��� ��������
	all_spec = ""; // ������ �������������
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::DBGrid9EditButtonClick(TObject *Sender) {
	if (DBGrid9->SelectedField->DisplayLabel == "TEXT_DEP")
	{ // if ������� ���� � ��������� (�� ���� ������)
		DM->QRegion_Center->Close();
		DM->QRegion_Center->ParamByName("REGION")->AsSmallInt =
			DM->TCkN_REGION->Value;
		DM->QRegion_Center->Open();

		DualListDlg = new TDualListDlg(this);
		DualListDlg->SrcList->Items->Clear();
		DualListDlg->DstList->Items->Clear();
		for (int i = 0; i < DM->QRegion_Center->RecordCount; i++)
		{ // for  �� ���������� �������
			DualListDlg->SrcList->Items->Add(DM->QRegion_CenterCENTRE->Value);
			DM->QRegion_Center->Next();
		} // end for  �� ���������� �������
        DualListDlg->ShowModal();

		if (DM->printdlg == true) {
		 for (int i = 0; i < DualListDlg->DstList->Count; i++)
			{ // for �������������
				DBGrid9->SelectedField->Value = DualListDlg->DstList->Items->Strings[i];
				raion = DM->QRegion_Center->Lookup("CENTRE",
					DualListDlg->DstList->Items->Strings[i], "N_CENTRE");
			} // end for �������������
		} // end if Execute  DualListDialog1
	} // end if ������� ���� � ��������� (�� ���� ������)


		// �������� ����������
  /*		MyList1->SourceList->Clear();
		MyList1->FOutList->Clear();

		for (int i = 0; i < DM->QRegion_Center->RecordCount; i++)
		{ // for  �� ���������� �������
			MyList1->SourceList->Add(DM->QRegion_CenterCENTRE->Value);
			DM->QRegion_Center->Next();
		} // end for  �� ���������� �������

		if (MyList1->Execute(MyList1)) { // if Execute  DualListDialog1
			for (int i = 0; i < MyList1->FOutList->Count; i++)
			{ // for �������������
				DBGrid9->SelectedField->Value = MyList1->FOutList->Strings[i];
				raion = DM->QRegion_Center->Lookup("CENTRE",
					MyList1->FOutList->Strings[i], "N_CENTRE");
			} // end for �������������
		} // end if Execute  DualListDialog1
	} // end if ������� ���� � ��������� (�� ���� ������)       */
	delete DualListDlg;
}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn35Click(TObject *Sender) {
	DM->TKol_Place->Delete();
	DM->TKol_Place->ApplyUpdates();
	DM->TKol_Place->CommitUpdates();
	Panel1->Visible = false;

}

// ---------------------------------------------------------------------------
void __fastcall TSpravForm::BitBtn36Click(TObject *Sender)
{ // ������ ��������� �����
	if (DBLookupComboBox2->Text != "" && Edit3->Text != "" &&
		RadioGroup1->ItemIndex != -1) {
		DM->QCenter->Insert();
		DM->QCenterN_REGION->Value = DBLookupComboBox2->KeyValue;
		DM->QCenterCENTRE->Value = Edit3->Text;
		DM->QCenterFLAG->Value = RadioGroup1->ItemIndex;
		DM->QCenter->ApplyUpdates();

	}

	Edit3->Text = "";
	// Panel35->Visible=false;
}


void __fastcall TSpravForm::DBGrid1DblClick (TObject * Sender)
{
    Panel35 -> Visible = true;
    Edit3   -> Text    = "";

    // RadioGroup1 -> ItemIndex = -1;
}
void __fastcall TSpravForm::KUDBGrdDblClick (TObject * Sender)                  // ���������� ���������� ��������� ������ � ���� ��������������
{
    Panel8 -> Visible = true;

    if (DM -> CntrExrcTblPOL -> Value == "�")
        PolCmbBx -> ItemIndex = 0;
    else
        PolCmbBx -> ItemIndex = 1;

    GrpCmbBx -> ItemIndex =
        DM -> CntrExrcTblNUM_EXERC_GRP -> Value - 1;

    DM -> CntrExrcTbl -> Edit ();
}
void __fastcall TSpravForm::BitBtn17Click (TObject * Sender)                    // ������ "���������"
{
    if (PolCmbBx -> ItemIndex)
        DM -> CntrExrcTblPOL -> Value = "�";
    else
        DM -> CntrExrcTblPOL -> Value = "�";

    DM -> CntrExrcTblNUM_EXERC_GRP -> Value = GrpCmbBx -> ItemIndex + 1;
    DM -> CntrExrcTblN_FAC         -> Value = nom_fac;

    DM -> CntrExrcTbl -> ApplyUpdates ();
    DM -> CntrExrcTbl -> CommitUpdates ();

    Panel8 -> Visible = false;
}


void __fastcall TSpravForm::BitBtn16Click(TObject *Sender)
{// ��������
	Panel8->Visible = true;
	PolCmbBx->ItemIndex = 0;
	GrpCmbBx->ItemIndex = 0;
	DM->CntrExrcTbl->Insert();
	DM->MaxExrcQr->Close();
	DM->MaxExrcQr->Open();
	if (DM->MaxExrcQrMAX->Value < 1)
		DM->CntrExrcTblID_CONTROL_EXERC->Value = 1;
	else
		DM->CntrExrcTblID_CONTROL_EXERC->Value = DM->MaxExrcQrMAX->Value + 1;
	DM->MaxExrcQr->Close();
	SpecializDBLkpCmbBx->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn24Click(TObject *Sender)
{ // �������
	DM->CntrExrcTbl->Delete();
	DM->CntrExrcTbl->ApplyUpdates();
	DM->CntrExrcTbl->CommitUpdates();
	Panel8->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::BitBtn23Click(TObject *Sender)
{  // ������
	DM->CntrExrcTbl->CancelUpdates();
	Panel8->Visible = false;
}
//---------------------------------------------------------------------------




