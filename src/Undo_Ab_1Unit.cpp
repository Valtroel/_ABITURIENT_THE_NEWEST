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
// переменная для определения для чего используется форма 0-восстановление, 1-переподача

// ---------------------------------------------------------------------------
__fastcall TUndo_Ab_1Form::TUndo_Ab_1Form(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::Grupp(AnsiString sp)
{ // функция проверки на возможные номера групп, в зависимости от специализации и вида обучения
	// AnsiString sp - параметр специализации
	// открытие Query по параметрам вида обучения и специализации - выбираем нужные группы
	DM->QN_group->Close();
	DM->QN_group->ParamByName("FAC")->AsSmallInt = nom_fac;
	DM->QN_group->ParamByName("EDU")->AsSmallInt = ComboBox1->ItemIndex;
	DM->QN_group->ParamByName("SPEC")->AsString = sp;
	DM->QN_group->Open();

	// открытие Query количества человек в каждой группе
	DM->QGroup_Count->Close();
	DM->QGroup_Count->ParamByName("N_FAC")->AsInteger = nom_fac;
	DM->QGroup_Count->Open();

	// очищаем номера групп
	ComboBox2->Clear();

	for (int i = 0; i < DM->QN_group->RecordCount; i++)
	{ // for цикл по группам нужного вида обучения и специализации

		int kol = 0; // количество человек в группе
		Variant nnn = DM->QGroup_Count->Lookup("NOM_GROUP",
			DM->QN_groupNOM_GROUP->Value, "COUNT");
		if (!nnn.IsNull()) { // if нашли эту группу
			kol = nnn;
		} // end if нашли эту группу
		else
			kol = 0;
		if (kol < DM->QN_groupN_COUNT->Value)
		{ // if проверяем на количество человек в группе, разрешенное и сравниваем с реальным
			ComboBox2->Items->Add(DM->QN_groupNOM_GROUP->Value);
		} // end if проверяем на количество человек в группе, разрешенное и сравниваем с реальным
		DM->QN_group->Next();
	} // end for цикл по группам нужного вида обучения и специализации
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::FormClose(TObject *Sender, TCloseAction &Action)
{
    this -> Close ();
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::BitBtn2Click(TObject *Sender) { // кнопка ВЫХОД
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::FormActivate(TObject *Sender) {
	if (Undo_Ab_1Form->Caption == "Восстановление") {
		// № дела
		Edit2->Text = "";
		Edit2->SetFocus();
		// вид обучения
		ComboBox1->ItemIndex = DM->QAbituraVID_EDU->Value;
		KonkursCmbBx->ItemIndex = DM->QAbituraKONKURS->Value;
		PriceCmbBx->ItemIndex = DM->QAbituraPRICE->Value;
		// переменная для ввода параметра только выбранной специализации
		AnsiString sp = "." + DBLookupComboBox1->KeyValue;
		sp += ".";
		// функция выбора возможных номеров групп
		Grupp(sp);

		// Направление специальности
		DM->QSpecializPlan_Priem->Close();
		DM->QSpecializPlan_Priem->ParamByName("VID_EDU")->AsSmallInt =
			DM->QAbituraVID_EDU->Value;
		DM->QSpecializPlan_Priem->ParamByName("FAC")->AsSmallInt = nom_fac;
		DM->QSpecializPlan_Priem->Open();

		// Дата приема документов - текущая дата
		Label4->Caption = cur_d.CurrentDate();
		ab_p = 0;
		// переменная для определения для чего используется форма 0-восстановление
	}
	else
		ab_p = 1;
	// переменная для определения для чего используется форма 1-переподача
	// открытие Query для выбора ЦК по специализациям
	DM->QCk->Close();
	DM->QCk->ParamByName("N_SPEC")->AsInteger = DM->QAbituraN_SPECIALIZ->Value;
	DM->QCk->Open();
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::DBLookupComboBox1CloseUp(TObject *Sender)
{ // изменение значения специализации
	// перечитка Query для выбора ЦК по специализациям
	DM->QCk->Close();
	DM->QCk->ParamByName("N_SPEC")->AsInteger = DM->QAbituraN_SPECIALIZ->Value;
	DM->QCk->Open();

	// функция выбора возможных номеров групп, которая перечитывает по изменению
	// вида обучения
	ComboBox1Change(this);
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::BitBtn1Click(TObject *Sender)
{ // кнопка ОК - для восстановления абитуриента

	// для Институа туризма - Оля
	AbiturForm->PoleBlock();
	int price = DM->QAbituraPRICE->Value;
	/* //11.07.2014 расдокументировать когда переподаа запрещена
	 if(!st_developer)
	 {//не разработчик

	 if (perepodacha!=0)
	 {//if  perepodacha запрещена
	 if(price!=1)
	 {//бюджет
	 if(press==3 & RadioGroup3->ItemIndex!=1)
	 {
	 ShowMessage("Абитуриента восстановить нельзя, т.к. набор на БЮДЖЕТ окончен! Обратитесь к программисту!");
	 return;
	 }
	 if(press==4)
	 {
	 ShowMessage("Переподача документов возможна только после зачисления на БЮДЖЕТ! Обратитесь к программисту!");
	 return;
	 }
	 }//бюджет
	 //если платник хочет на бюджет
	 else if(RadioGroup3->ItemIndex!=1)
	 {
	 ShowMessage("Переподать документы на БЮДЖЕТ нельзя, т.к. набор уже окончен!");
	 return;
	 }
	 }//if  perepodacha запрещена
	 }//and не разработчик
	 */
	// Проверка на конкурс
	// if (RadioGroup2->ItemIndex==3 && nom_fac==3)
	// {//if
	// ShowMessage("У вас не может быть конкурс: 2 курс!");
	// RadioGroup2->ItemIndex=0;
	// Undo_Ab_1Form->ModalResult=0;
	// return;
	// }//end if

	// Проверка на вне конкурса в 2008 году зачисление вне конкурса не будет
	// дневная - Менеджмент  в туризме 51, Менеджмент в спорте  48
	// заочная - Физическая реабилитация 3, Тренерская работа по футболу 32
	// 2009 -- заочная - Физическая реабилитация 3
	// --------Оля---------
	// Проверка на вне конкурса  в 2010 году зачисление вне конкурса не будет
	// заочная - тренерская работа по футболу 32
	// дневная - Туризм и гостеприимство 61
	// --------------------
	// Проверка на вне конкурса  в 2011 году зачисление вне конкурса не будет
	// заочная - Физическая реабилитация 3
	// дневная - Туризм и гостеприимство 61
	// -------Галя-----
	// Проверка на вне конкурса  в 2012 году зачисление вне конкурса не будет
	// заочная - Физическая реабилитация 3
	// -------Галя-----
	// Проверка на вне конкурса  в 2014 году зачисление вне конкурса не будет

	// if ((ComboBox1->Text=="Заочное")&& (DBLookupComboBox1->KeyValue==3)&& (RadioGroup2->ItemIndex==4))
	// {//if
	// ShowMessage("На это направление специальности в 2017 году не берут ВНЕ КОНКУРСА!");
	// RadioGroup2->ItemIndex=0;
	// return;
	// }//end if

	// if ((ComboBox1->Text=="Дневное")&& (DBLookupComboBox1->KeyValue==61)&& (RadioGroup2->ItemIndex==4))
	// {//if
	// ShowMessage("На это направление специальности в 2011 году не берут ВНЕ КОНКУРСА!");
	// RadioGroup2->ItemIndex=0;
	// return;
	// }//end if

	if ((Edit2->Text != "") && (ComboBox2->Text != ""))
	{ // if № дела и № группы не пустые

		if (ab_p) { // if - переподача документов
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
		} // end if - переподача документов
		// переводим  QAbitura в режим редактирования
		DM->QAbitura->Edit();
		// факультет
		DM->QAbituraN_FAC->Value = nom_fac;
		// статус 0 - для действующего
		DM->QAbituraSTATUS->Value = 0;
		// дата приема документов - текущая дата
		if (!ab_p)
			DM->QAbituraDATE_PRIEM->Value = DateTimeToSQLTimeStamp(StrToDate(cur_d.CurrentDate()));
		// вид обучения
		DM->QAbituraVID_EDU->Value = ComboBox1->ItemIndex;
		// номер дела
		DM->QAbituraNOM_DELA->Value = Edit2->Text.ToInt();
		// номер группы
		DM->QAbituraNOM_GROUP->Value = ComboBox2->Text;
		// конкурс
		DM->QAbituraKONKURS->Value = KonkursCmbBx->ItemIndex;
		// форма оплаты
		DM->QAbituraPRICE->Value = PriceCmbBx->ItemIndex;

		// специализация
		DM->QAbituraN_SPECIALIZ->Value = DBLookupComboBox1->KeyValue;
		// специальность
		DM->QAbituraN_SPEC->Value = DM->QSpecializ->Lookup("N_SPECIALIZ",
			DBLookupComboBox1->KeyValue, "N_SPEC");
		// очищение поля даты возврата документов
		DM->QAbitura->FieldByName("DATE_VOZVRAT")->Clear();

		// сохранения данных
		try {
			DM->QAbitura->ApplyUpdates();
			DM->QAbitura->CommitUpdates();
			if (ab_p) { // if - переподача документовDM->QAb_P->ApplyUpdates();
				DM->QAb_P->CommitUpdates();
			}
		}
		catch (...) {
			DM->QAbitura->CancelUpdates();
			if (ab_p) { // if - переподача документов
				DM->QAb_P->CancelUpdates();
			}
			ShowMessage("Произошел сбой при сохранении. Поробуйте еще раз!");
		}
		// перечитывание тех, кто забрал документы  STATUS=1
		DM->QAbitura->Close();
		DM->QAbitura->SQL->Clear();

		if (ab_p) { // if - переподача документов
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

		// количество человек в группе
		DM->QGroup_Count->Close();
		DM->QGroup_Count->ParamByName("N_FAC")->AsInteger = nom_fac;
		DM->QGroup_Count->Open();

		// максимальный номер дела
		DM->QMax_Nom_Dela->Close();
		DM->QMax_Nom_Dela->ParamByName("N_FAC")->AsInteger = nom_fac;
		DM->QMax_Nom_Dela->Open();

		AbiturForm->max_nom_dela();
	} // end if № дела и № группы не пустые
	else { // else № дела и № группы  пустые
		ShowMessage("Не введен номер дела или номер группы");
		Edit2->SetFocus();
	} // end else № дела и № группы  пустые
}

// ---------------------------------------------------------------------------
void __fastcall TUndo_Ab_1Form::ComboBox1Change(TObject *Sender)
{ // изменения вида обучения
	// переменная для ввода параметра только выбранной специализации
	AnsiString sp = "." + DBLookupComboBox1->KeyValue;
	sp += ".";
	// функция выбора возможных номеров групп
	Grupp(sp);

	// Направление специальности
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
