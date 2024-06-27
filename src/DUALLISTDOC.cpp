// ---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "DMUnit.h"
#include "DUALLISTDOC.h"
#include "AbiturUnit.h"
// ---------------------------------------------------------------------
#pragma resource "*.dfm"
TDualListDlgDoc *DualListDlgDoc;

bool conf;

// ---------------------------------------------------------------------
__fastcall TDualListDlgDoc::TDualListDlgDoc(TComponent* AOwner) : TForm(AOwner)
{
}

// ---------------------------------------------------------------------
void __fastcall TDualListDlgDoc::IncludeBtnClick(TObject *Sender) {
	int Index;

	Index = GetFirstSelection(SrcList);
	MoveSelected(SrcList, DstList->Items);
	SetItem(SrcList, Index);
}

// ---------------------------------------------------------------------
void __fastcall TDualListDlgDoc::ExcludeBtnClick(TObject *Sender) {
	int Index;

	Index = GetFirstSelection(DstList);
	MoveSelected(DstList, SrcList->Items);
	SetItem(DstList, Index);
}

// ---------------------------------------------------------------------
void __fastcall TDualListDlgDoc::IncAllBtnClick(TObject *Sender) {
	int i;

	for (i = 0; i < SrcList->Items->Count; i++)
		DstList->Items->AddObject(SrcList->Items->Strings[i],
		SrcList->Items->Objects[i]);
	SrcList->Items->Clear();
	SetItem(SrcList, 0);
}

// ---------------------------------------------------------------------
void __fastcall TDualListDlgDoc::ExcAllBtnClick(TObject *Sender) {
	int i;

	for (i = 0; i < DstList->Items->Count; i++)
		SrcList->Items->AddObject(DstList->Items->Strings[i],
		DstList->Items->Objects[i]);

	DstList->Items->Clear();
	SetItem(DstList, 0);
}

// ---------------------------------------------------------------------
void __fastcall TDualListDlgDoc::MoveSelected(TCustomListBox *List,
	TStrings *Items) {
	int i;

	for (i = List->Items->Count - 1; i >= 0; i--) {
		if (List->Selected[i]) {
			Items->AddObject(List->Items->Strings[i], List->Items->Objects[i]);
			List->Items->Delete(i);
		}
	}
}

// ---------------------------------------------------------------------
void __fastcall TDualListDlgDoc::SetButtons() {
	bool SrcEmpty, DstEmpty;

	SrcEmpty = (SrcList->Items->Count == 0);
	DstEmpty = (DstList->Items->Count == 0);
	IncludeBtn->Enabled = (!SrcEmpty);
	IncAllBtn->Enabled = (!SrcEmpty);
	ExcludeBtn->Enabled = (!DstEmpty);
	ExAllBtn->Enabled = (!DstEmpty);
}

// ---------------------------------------------------------------------
int __fastcall TDualListDlgDoc::GetFirstSelection(TCustomListBox *List) {
	int i;

	for (i = 0; i < List->Items->Count; i++) {
		if (List->Selected[i])
			return i;
	}

	return LB_ERR;
}

// ---------------------------------------------------------------------
void __fastcall TDualListDlgDoc::SetItem(TListBox *List, int Index) {
	int MaxIndex;

	List->SetFocus();
	MaxIndex = List->Items->Count - 1;

	if (Index == LB_ERR)
		Index = 0;
	else if (Index > MaxIndex)
		Index = MaxIndex;
	List->Selected[Index] = true;

	SetButtons();
}

// ---------------------------------------------------------------------
void __fastcall TDualListDlgDoc::OKBtnClick(TObject *Sender) {
	DM->ListDocFDQ->Close();
	DM->ListDocFDQ->ParamByName("NOMER_AB")->Value =
		DM->QAbituraNOMER_AB->Value;
	DM->ListDocFDQ->Open();
	DM->ListDocFDQ->First();
	for (int j = 0; j < DM->ListDocFDQ->RecordCount; j++) {
		conf = false;
		for (int i = 0; i < DstList->Items->Count; i++) {
			if (DM->ListDocFDQN_DOC->Value == (int)(DstList->Items->Objects[i]))
			{
				conf = true;
			}
		}
		if (!conf) {
			DM->ListDocFDQ->Delete();
			DM->ListDocFDQ->ApplyUpdates();
			DM->ListDocFDQ->CommitUpdates();
		}
		DM->ListDocFDQ->Next();
	}
	DM->ListDocFDQ->Close();
	DM->ListDocFDQ->ParamByName("NOMER_AB")->Value =
		DM->QAbituraNOMER_AB->Value;
	DM->ListDocFDQ->Open();
    for (int i = 0; i < DstList->Items->Count; i++) {
		conf = false;
		DM->ListDocFDQ->First();
		for (int j = 0; j < DM->ListDocFDQ->RecordCount; j++) {
			if (DM->ListDocFDQN_DOC->Value == (int)(DstList->Items->Objects[i]))
			{
				conf = true;
			}
			DM->ListDocFDQ->Next();
		}
		if (!conf) {
			DM->ListDocFDQ->Insert();
			DM->ListDocFDQNOMER_AB->Value = DM->QAbituraNOMER_AB->Value;
			DM->ListDocFDQN_DOC->Value = (int)(DstList->Items->Objects[i]);
			DM->ListDocFDQ->ApplyUpdates();
			DM->ListDocFDQ->CommitUpdates();
		}
	}

}

// ---------------------------------------------------------------------------
void __fastcall TDualListDlgDoc::SrcListDblClick(TObject *Sender) {
	int Index;

	Index = GetFirstSelection(SrcList);
	MoveSelected(SrcList, DstList->Items);
	SetItem(SrcList, Index);
}
// ---------------------------------------------------------------------------

void __fastcall TDualListDlgDoc::DstListDblClick(TObject *Sender) {
	int Index;

	Index = GetFirstSelection(DstList);
	MoveSelected(DstList, SrcList->Items);
	SetItem(DstList, Index);
}
// ---------------------------------------------------------------------------
