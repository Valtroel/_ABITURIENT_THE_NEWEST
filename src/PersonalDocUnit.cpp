// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PersonalDocUnit.h"
#include "PrnPersonDocUnit.h"
#include "DMUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxRich"
#pragma resource "*.dfm"
TPersonalDocFrm *PersonalDocFrm;

// ---------------------------------------------------------------------------
__fastcall TPersonalDocFrm::TPersonalDocFrm(TComponent* Owner) : TForm(Owner) {
}

int n_spec[50];

// ---------------------------------------------------------------------------
void __fastcall TPersonalDocFrm::FormActivate(TObject *Sender) {
	// Àêòèâàöèÿ ôîðìû
	VidEduCmbBx->ItemIndex = -1;
	SpecializCmbBx->Items->Clear();
	SpecializCmbBx->ItemIndex = -1;

	DM->SpecFacQr->Close();
	DM->SpecFacQr->ParamByName("n_fac")->AsSmallInt = nom_fac;
	DM->SpecFacQr->Open();
	int i = 0;
	while (!DM->SpecFacQr->Eof) {
		SpecializCmbBx->Items->Add(DM->SpecFacQrSPECIAL->Value);
		n_spec[i] = DM->SpecFacQrN_SPECIALIZ->Value;
		DM->SpecFacQr->Next();
		i++;
	}

}

// ---------------------------------------------------------------------------
void __fastcall TPersonalDocFrm::Button1Click(TObject *Sender) {
	// Ïå÷àòü òèòóëüíûõ ëèñòîâ
	if ((VidEduCmbBx->ItemIndex > -1) && (SpecializCmbBx->ItemIndex > -1)) {
		DM->PrintDocQr->Close();
		DM->PrintDocQr->ParamByName("n_fac")->AsSmallInt = nom_fac;
		DM->PrintDocQr->ParamByName("vid_edu")->AsSmallInt =
			VidEduCmbBx->ItemIndex;
		DM->PrintDocQr->ParamByName("n_specializ")->AsSmallInt =
			n_spec[SpecializCmbBx->ItemIndex];
		DM->PrintDocQr->Open();
		while (!DM->PrintDocQr->Eof) {
			PrnPersonDocForm = new TPrnPersonDocForm(this);

			TfrxMemoView * FamMemo =
				dynamic_cast<TfrxMemoView*>
				(PrnPersonDocForm->frxReport1->FindObject("FamMemo"));
			TfrxMemoView * NameMemo =
				dynamic_cast<TfrxMemoView*>
				(PrnPersonDocForm->frxReport1->FindObject("NameMemo"));
			TfrxMemoView * OtchMemo =
				dynamic_cast<TfrxMemoView*>
				(PrnPersonDocForm->frxReport1->FindObject("OtchMemo"));
			TfrxMemoView * FacMemo =
				dynamic_cast<TfrxMemoView*>
				(PrnPersonDocForm->frxReport1->FindObject("FacMemo"));
			TfrxMemoView * DateMemo =
				dynamic_cast<TfrxMemoView*>
				(PrnPersonDocForm->frxReport1->FindObject("DateMemo"));

			FamMemo->Text = DM->PrintDocQrFAM->Value;
			NameMemo->Text = DM->PrintDocQrNAME->Value;
			OtchMemo->Text = DM->PrintDocQrOTCH->Value;

			String s_fac = "";
			switch (nom_fac) {
			case 1:
				s_fac = "ÑÏÔ ÑÈèÅ\n";
				break;
			case 2:
				s_fac = "ÑÏÔ ÌÂÑ\n";
				break;
			case 3:
				s_fac = "Ô ÎÔÊ\n";
				break;
			case 4:
				s_fac = "Èíñòèòóò ìåíåäæìåíòà\nñïîðòà è òóðèçìà\n";
				break;
			}

			if (VidEduCmbBx->ItemIndex == 0)
				s_fac += "ÄÔÏÎ\n" + SpecializCmbBx->Items->Strings
					[SpecializCmbBx->ItemIndex];
			else
				s_fac += "ÇÔÏÎ\n" + SpecializCmbBx->Items->Strings
					[SpecializCmbBx->ItemIndex];

			FacMemo->Text = s_fac;

			DateMemo->Text = "02.09." + FormatDateTime("yyyy", Now());

			PrnPersonDocForm->frxReport1->ShowReport();

			delete PrnPersonDocForm;

			DM->PrintDocQr->Next();
		}
		DM->PrintDocQr->Close();
		VidEduCmbBx->ItemIndex = -1;
		SpecializCmbBx->ItemIndex = -1;
	}
}
// ---------------------------------------------------------------------------


