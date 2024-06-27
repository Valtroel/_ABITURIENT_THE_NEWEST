// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Undo_Ab_1Unit.h"
#include "DMUnit.h"
#include "Priv_EnterUnit.h"
#include "MainUnit.h"
#include "AbiturUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TUndo_Ab_1Form *Undo_Ab_1Form;
int ab_p;
// ���������� ��� ����������� ��� ���� ������������ ����� 0-��������������, 1-����������

// ---------------------------------------------------------------------------
__fastcall TUndo_Ab_1Form::TUndo_Ab_1Form(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::Grupp(AnsiString sp)
{ // ������� �������� �� ��������� ������ �����, � ����������� �� ������������� � ���� ��������
	// AnsiString sp - �������� �������������
	// �������� Query �� ���������� ���� �������� � ������������� - �������� ������ ������
	DM->QN_group->Close();
	DM->QN_group->ParamByName("FAC")->AsSmallInt = nom_fac;
	DM->QN_group->ParamByName("EDU")->AsSmallInt = ComboBox1->ItemIndex;
	DM->QN_group->ParamByName("SPEC")->AsString = sp;
	DM->QN_group->Open();

	// �������� Query ���������� ������� � ������ ������
	DM->QGroup_Count->Close();
	DM->QGroup_Count->ParamByName("N_FAC")->AsInteger = nom_fac;
	DM->QGroup_Count->Open();

	// ������� ������ �����
	ComboBox2->Clear();

	for (int i = 0; i < DM->QN_group->RecordCount; i++)
	{ // for ���� �� ������� ������� ���� �������� � �������������

		int kol = 0; // ���������� ������� � ������
		Variant nnn = DM->QGroup_Count->Lookup("NOM_GROUP",
			DM->QN_groupNOM_GROUP->Value, "COUNT");
		if (!nnn.IsNull()) { // if ����� ��� ������
			kol = nnn;
		} // end if ����� ��� ������
		else
			kol = 0;
		if (kol < DM->QN_groupN_COUNT->Value)
		{ // if ��������� �� ���������� ������� � ������, ����������� � ���������� � ��������
			ComboBox2->Items->Add(DM->QN_groupNOM_GROUP->Value);
		} // end if ��������� �� ���������� ������� � ������, ����������� � ���������� � ��������
		DM->QN_group->Next();
	} // end for ���� �� ������� ������� ���� �������� � �������������
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::FormClose(TObject *Sender, TCloseAction &Action)
{
    this -> Close ();
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::BitBtn2Click(TObject *Sender) { // ������ �����
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::FormActivate(TObject *Sender) {
	if (Undo_Ab_1Form->Caption == "��������������") {
		// � ����
		Edit2->Text = "";
		Edit2->SetFocus();
		// ��� ��������
		ComboBox1->ItemIndex = DM->QAbituraVID_EDU->Value;
		KonkursCmbBx->ItemIndex = DM->QAbituraKONKURS->Value;
		PriceCmbBx->ItemIndex = DM->QAbituraPRICE->Value;
		// ���������� ��� ����� ��������� ������ ��������� �������������
		AnsiString sp = "." + DBLookupComboBox1->KeyValue;
		sp += ".";
		// ������� ������ ��������� ������� �����
		Grupp(sp);

		// ����������� �������������
		DM->QSpecializPlan_Priem->Close();
		DM->QSpecializPlan_Priem->ParamByName("VID_EDU")->AsSmallInt =
			DM->QAbituraVID_EDU->Value;
		DM->QSpecializPlan_Priem->ParamByName("FAC")->AsSmallInt = nom_fac;
		DM->QSpecializPlan_Priem->Open();

		// ���� ������ ���������� - ������� ����
		Label4->Caption = cur_d.CurrentDate();
		ab_p = 0;
		// ���������� ��� ����������� ��� ���� ������������ ����� 0-��������������
	}
	else
		ab_p = 1;
	// ���������� ��� ����������� ��� ���� ������������ ����� 1-����������
	// �������� Query ��� ������ �� �� ��������������
	DM->QCk->Close();
	DM->QCk->ParamByName("N_SPEC")->AsInteger = DM->QAbituraN_SPECIALIZ->Value;
	DM->QCk->Open();
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::DBLookupComboBox1CloseUp(TObject *Sender)
{ // ��������� �������� �������������
	// ��������� Query ��� ������ �� �� ��������������
	DM->QCk->Close();
	DM->QCk->ParamByName("N_SPEC")->AsInteger = DM->QAbituraN_SPECIALIZ->Value;
	DM->QCk->Open();

	// ������� ������ ��������� ������� �����, ������� ������������ �� ���������
	// ���� ��������
	ComboBox1Change(this);
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::BitBtn1Click(TObject *Sender)
{ // ������ �� - ��� �������������� �����������

	// ��� �������� ������� - ���
	AbiturForm->PoleBlock();
	int price = DM->QAbituraPRICE->Value;
	/* //11.07.2014 ������������������ ����� ��������� ���������
	 if(!st_developer)
	 {//�� �����������

	 if (perepodacha!=0)
	 {//if  perepodacha ���������
	 if(price!=1)
	 {//������
	 if(press==3 & RadioGroup3->ItemIndex!=1)
	 {
	 ShowMessage("����������� ������������ ������, �.�. ����� �� ������ �������! ���������� � ������������!");
	 return;
	 }
	 if(press==4)
	 {
	 ShowMessage("���������� ���������� �������� ������ ����� ���������� �� ������! ���������� � ������������!");
	 return;
	 }
	 }//������
	 //���� ������� ����� �� ������
	 else if(RadioGroup3->ItemIndex!=1)
	 {
	 ShowMessage("���������� ��������� �� ������ ������, �.�. ����� ��� �������!");
	 return;
	 }
	 }//if  perepodacha ���������
	 }//and �� �����������
	 */
	// �������� �� �������
	// if (RadioGroup2->ItemIndex==3 && nom_fac==3)
	// {//if
	// ShowMessage("� ��� �� ����� ���� �������: 2 ����!");
	// RadioGroup2->ItemIndex=0;
	// Undo_Ab_1Form->ModalResult=0;
	// return;
	// }//end if

	// �������� �� ��� �������� � 2008 ���� ���������� ��� �������� �� �����
	// ������� - ����������  � ������� 51, ���������� � ������  48
	// ������� - ���������� ������������ 3, ���������� ������ �� ������� 32
	// 2009 -- ������� - ���������� ������������ 3
	// --------���---------
	// �������� �� ��� ��������  � 2010 ���� ���������� ��� �������� �� �����
	// ������� - ���������� ������ �� ������� 32
	// ������� - ������ � �������������� 61
	// --------------------
	// �������� �� ��� ��������  � 2011 ���� ���������� ��� �������� �� �����
	// ������� - ���������� ������������ 3
	// ������� - ������ � �������������� 61
	// -------����-----
	// �������� �� ��� ��������  � 2012 ���� ���������� ��� �������� �� �����
	// ������� - ���������� ������������ 3
	// -------����-----
	// �������� �� ��� ��������  � 2014 ���� ���������� ��� �������� �� �����

	// if ((ComboBox1->Text=="�������")&& (DBLookupComboBox1->KeyValue==3)&& (RadioGroup2->ItemIndex==4))
	// {//if
	// ShowMessage("�� ��� ����������� ������������� � 2017 ���� �� ����� ��� ��������!");
	// RadioGroup2->ItemIndex=0;
	// return;
	// }//end if

	// if ((ComboBox1->Text=="�������")&& (DBLookupComboBox1->KeyValue==61)&& (RadioGroup2->ItemIndex==4))
	// {//if
	// ShowMessage("�� ��� ����������� ������������� � 2011 ���� �� ����� ��� ��������!");
	// RadioGroup2->ItemIndex=0;
	// return;
	// }//end if

	if ((Edit2->Text != "") && (ComboBox2->Text != ""))
	{ // if � ���� � � ������ �� ������

		if (ab_p) { // if - ���������� ����������
			DM->QAb_P->Open();
			DM->QAb_P->Insert();
			DM->QAb_PNOMER_AB->Value = DM->QAbituraNOMER_AB->Value;
			DM->QAb_PVID_EDU_DO->Value = DM->QAbituraVID_EDU->Value;
			DM->QAb_PVID_EDU_PO->Value = ComboBox1->ItemIndex;
			DM->QAb_PNOM_DELA_DO->Value = DM->QAbituraNOM_DELA->Value;
			DM->QAb_PNOM_DELA_PO->Value = Edit2->Text.ToInt();
			DM->QAb_PNOM_GROUP_DO->Value = DM->QAbituraNOM_GROUP->Value;
			DM->QAb_PNOM_GROUP_PO->Value = ComboBox2->Text;
			DM->QAb_PN_SPECIALIZ_DO->Value = DM->QAbituraN_SPECIALIZ->Value;
			DM->QAb_PN_SPECIALIZ_PO->Value = DBLookupComboBox1->KeyValue;
			DM->QAb_PN_SPEC_DO->Value = DM->QAbituraN_SPEC->Value;
			DM->QAb_PN_SPEC_PO->Value =
				DM->QSpecializ->Lookup("N_SPECIALIZ",
				DBLookupComboBox1->KeyValue, "N_SPEC");
			if (DM->QAbituraN_CK->Value)
				DM->QAb_PN_CK->Value = DM->QAbituraN_CK->Value;
			DM->QAb_PKONKURS_DO->Value = DM->QAbituraKONKURS->Value;
			DM->QAb_PKONKURS_PO->Value = KonkursCmbBx->ItemIndex;
			DM->QAb_PDATE_P->Value = DateTimeToSQLTimeStamp(StrToDate(cur_d.CurrentDate()));
			DM->QAb_PPRICE_DO->Value = DM->QAbituraPRICE->Value;
			DM->QAb_PPRICE_PO->Value = PriceCmbBx->ItemIndex;

			DM->QAb_P->Post();
		} // end if - ���������� ����������
		// ���������  QAbitura � ����� ��������������
		DM->QAbitura->Edit();
		// ���������
		DM->QAbituraN_FAC->Value = nom_fac;
		// ������ 0 - ��� ������������
		DM->QAbituraSTATUS->Value = 0;
		// ���� ������ ���������� - ������� ����
		if (!ab_p)
			DM->QAbituraDATE_PRIEM->Value = DateTimeToSQLTimeStamp(StrToDate(cur_d.CurrentDate()));
		// ��� ��������
		DM->QAbituraVID_EDU->Value = ComboBox1->ItemIndex;
		// ����� ����
		DM->QAbituraNOM_DELA->Value = Edit2->Text.ToInt();
		// ����� ������
		DM->QAbituraNOM_GROUP->Value = ComboBox2->Text;
		// �������
		DM->QAbituraKONKURS->Value = KonkursCmbBx->ItemIndex;
		// ����� ������
		DM->QAbituraPRICE->Value = PriceCmbBx->ItemIndex;

		// �������������
		DM->QAbituraN_SPECIALIZ->Value = DBLookupComboBox1->KeyValue;
		// �������������
		DM->QAbituraN_SPEC->Value = DM->QSpecializ->Lookup("N_SPECIALIZ",
			DBLookupComboBox1->KeyValue, "N_SPEC");
		// �������� ���� ���� �������� ����������
		DM->QAbitura->FieldByName("DATE_VOZVRAT")->Clear();

		// ���������� ������
		try {
			DM->QAbitura->ApplyUpdates();
			DM->QAbitura->CommitUpdates();
			if (ab_p) { // if - ���������� ����������DM->QAb_P->ApplyUpdates();
				DM->QAb_P->CommitUpdates();
			}
		}
		catch (...) {
			DM->QAbitura->CancelUpdates();
			if (ab_p) { // if - ���������� ����������
				DM->QAb_P->CancelUpdates();
			}
			ShowMessage("��������� ���� ��� ����������. ��������� ��� ���!");
		}
		// ������������� ���, ��� ������ ���������  STATUS=1
		DM->QAbitura->Close();
		DM->QAbitura->SQL->Clear();

		if (ab_p) { // if - ���������� ����������
			DM->QAbitura->SQL->Add
				("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
			ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
			D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
			EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
			N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
			N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
			NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
			NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
			PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
			STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
			VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
			WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
			DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA WHERE (N_FAC=:N_FAC) AND (STATUS=0) ORDER BY FAM, NAME, OTCH"
				);
			DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;

		}
		else
			DM->QAbitura->SQL->Add
				("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
			ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
			D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
			EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
			N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
			N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
			NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
			NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
			PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
			STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
			VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
			WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
			DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA WHERE (STATUS=1) ORDER BY FAM, NAME, OTCH"
				);

		DM->QAbitura->Open();

		// ���������� ������� � ������
		DM->QGroup_Count->Close();
		DM->QGroup_Count->ParamByName("N_FAC")->AsInteger = nom_fac;
		DM->QGroup_Count->Open();

		// ������������ ����� ����
		DM->QMax_Nom_Dela->Close();
		DM->QMax_Nom_Dela->ParamByName("N_FAC")->AsInteger = nom_fac;
		DM->QMax_Nom_Dela->Open();

		AbiturForm->max_nom_dela();
	} // end if � ���� � � ������ �� ������
	else { // else � ���� � � ������  ������
		ShowMessage("�� ������ ����� ���� ��� ����� ������");
		Edit2->SetFocus();
	} // end else � ���� � � ������  ������
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::ComboBox1Change(TObject *Sender)
{ // ��������� ���� ��������
	// ���������� ��� ����� ��������� ������ ��������� �������������
	AnsiString sp = "." + DBLookupComboBox1->KeyValue;
	sp += ".";
	// ������� ������ ��������� ������� �����
	Grupp(sp);

	// ����������� �������������
	DM->QSpecializPlan_Priem->Close();
	DM->QSpecializPlan_Priem->ParamByName("VID_EDU")->AsSmallInt =
		ComboBox1->ItemIndex;
	DM->QSpecializPlan_Priem->ParamByName("FAC")->AsSmallInt = nom_fac;
	DM->QSpecializPlan_Priem->Open();

	if (oplata_konkurs == 0)
		VidKonkurs(KonkursCmbBx, PriceCmbBx, ComboBox1);
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::RadioGroup3Click(TObject *Sender) {
	if (oplata_konkurs == 0)
		VidKonkurs(KonkursCmbBx, PriceCmbBx, ComboBox1);
}
// ---------------------------------------------------------------------------
