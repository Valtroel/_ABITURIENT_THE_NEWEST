// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Group_FacUnit.h"
#include "DMUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
// #pragma link "RXToolEdit"
#pragma resource "*.dfm"
TGroup_FacForm *Group_FacForm;
int *n_ab;
int p_n = 0; // порядковый номер для массива
int year_include = 0;
int mon_include = 0;
AnsiString series;
AnsiString number;

AnsiString note1 = "Выдан на руки (смотреть отметку о выдаче), в деле копия";
AnsiString note3 =
	"Передан в ОМС по акту приёма-передачи от __.__.____ №___, в деле копия";
AnsiString note2 = "Выдан на руки (смотреть отметку о выдаче)";
AnsiString note5 = "Передана в медпункт по акту";
// AnsiString note4 = "ЗФПО (хранится в деле)";

// ---------------------------------------------------------------------------
__fastcall TGroup_FacForm::TGroup_FacForm(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TGroup_FacForm::Save_Priv(int people, int priv, AnsiString text,
	AnsiString year_cur)
{ // функция, которая сохраняет привелегии (сирота, Чаэс, инвалид)
	// int people - номер студента
	// int priv  - номер привелегии (1 - сирота, 2 - ЧАЭС, 3 - инвалид)
	// AnsiString text - текст привелегии ЧАЭС (ст. 18, или ст. др, инвалид - 1,2 гр. или 3 гр.)
	// AnsiString year_cur - текущий учебный год

	if (DM->QPrivToDekanat->State == dsInactive)
		DM->QPrivToDekanat->Open();
	DM->QPrivToDekanat->Insert();
	DM->QPrivToDekanatNOMER->Value = people;
	DM->QPrivToDekanatVID_PRIV->Value = priv;
	DM->QPrivToDekanatUCH_GOD->Value = year_cur.ToInt();
	DM->QPrivToDekanatTEXT_PRIV->Value = text;
	DM->QPrivToDekanatDATA_C->Value =
		DateTimeToSQLTimeStamp(StrToDate("01.09." + year_cur));
	DM->QPrivToDekanatDATA_PO->Value =
		DateTimeToSQLTimeStamp(StrToDate("30.06." +
		AnsiString(year_cur.ToInt() + 1)));
	DM->QPrivToDekanatDOC_PRIV->Value = "Приемная комиссия";
	DM->QPrivToDekanat->ApplyUpdates();
	DM->QPrivToDekanat->CommitUpdates();

}

// ---------------------------------------------------------------------------
void __fastcall TGroup_FacForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    this -> Close ();
}

// ---------------------------------------------------------------------------
void __fastcall TGroup_FacForm::Button1Click (TObject * Sender)                 // по кнопке Выбрать абитуриентов выбираем с видом обучения и специализацией
{
	DM->QSelect_ab->Close();
	DM->QSelect_ab->ParamByName("EDU")->Value = ComboBox1->ItemIndex;
	DM->QSelect_ab->ParamByName("FAC")->AsInteger = nom_fac;
	DM->QSelect_ab->ParamByName("N_SP")->Value = LookSp->KeyValue;
	DM->QSelect_ab->ParamByName("P")->Value = RadioGroup1->ItemIndex;
	DM->QSelect_ab->Open();
	// создаем массив по количеству абитуриетов со значением элемента =0
	n_ab = new int[DM->QSelect_ab->RecordCount];
	for (int i = 0; i < DM->QSelect_ab->RecordCount; i++) {
		n_ab[i] = 0;
	}
	p_n = 0;
	List1->Clear(); // очищаем

}

// ---------------------------------------------------------------------------
void __fastcall TGroup_FacForm::DBGrid1DblClick(TObject *Sender)
{ // по двойному щелчку в  ListBox  заносится ФИО абитуриента
	List1->Items->Add(DM->QSelect_abFAM->Value + " " +
		DM->QSelect_abNAME->Value + " " + DM->QSelect_abOTCH->Value);
	// в массив заносится номер абитуриента
	n_ab[p_n] = DM->QSelect_abNOMER_AB->Value;
	p_n++;
}

// ---------------------------------------------------------------------------
void __fastcall TGroup_FacForm::Button2Click(TObject *Sender)
{ // по кнопке Зачислить в студенты
	try {
		TLocateOptions fl;
		// ищем в массиве номера абитуриентов, которых надо зачислить
		for (int i = 0; i < DM->QSelect_ab->RecordCount; i++) {

			if (n_ab[i] != 0)
				// если номер не 0, то начинаем перегонять данные в Деканат
			{
				DM->QSelect_ab->Locate("NOMER_AB", n_ab[i], fl);
				DM->QToDekanat->Close();
				DM->QToDekanat->Open();
				DM->QToDekanat->Insert();
				DM->PasportFDQ->Close();
				DM->PasportFDQ->Open();
				DM->PasportFDQ->Insert();
				// определение группы
				// Поиск существующего номера группы
				DM->Increment_GroupTable->Open();
				Variant locvalues[] = {Edit1->Text, ComboBox1->ItemIndex};
				Variant i_gr = DM->Increment_GroupTable->Lookup
					("N_GROUP;VID_EDU", VarArrayOf(locvalues, 1), "INC_GROUP");
				if (!i_gr.IsNull())
					DM->QToDekanatINC_GROUP->Value = i_gr;
				else {
					// if(Application->MessageBox("Такого номера группы нет. Создать группу с таким номером?", "Предупреждение", MB_YESNO) == mrYes)
					AnsiString ansi_string1 =
						"Такого номера группы нет. Создать группу с таким номером?";
					/* наша строка */
					wchar_t * UnicodeString1 =
						new wchar_t[ansi_string1.WideCharBufSize()];
					/* массив-получатель */
					ansi_string1.WideChar(UnicodeString1,
						ansi_string1.WideCharBufSize());
					ansi_string1 = "Предупреждение"; /* наша строка */
					wchar_t * UnicodeString2 =
						new wchar_t[ansi_string1.WideCharBufSize()];
					/* массив-получатель */
					ansi_string1.WideChar(UnicodeString2,
						ansi_string1.WideCharBufSize());
					if (Application->MessageBox(UnicodeString1, UnicodeString2,
						MB_YESNO) == mrYes)
					{ // if если такой группы нет, то создаем её
						DM->Increment_GroupTable->Insert();
						DM->Increment_GroupTableN_GROUP->Value = Edit1->Text;
						DM->Increment_GroupTableVID_EDU->Value =
							ComboBox1->ItemIndex;
						// год обучения!!!

						TDateTime ddd;
						TDateTime ggg = ddd.CurrentDate();
						// находим текущую дату
						AnsiString year_cur = AnsiToUtf8(ggg).SubString(7, 4);
						// находим текущий год
						DM->Increment_GroupTableGOD->Value =
							year_cur.ToInt() + 1;

						DM->Increment_GroupTable->ApplyUpdates();
						DM->Increment_GroupTable->CommitUpdates();

						DM->Increment_GroupTable->Active = false;
						DM->Increment_GroupTable->Active = true;
						DM->Increment_GroupTable->Last();

						// сохранение информации по инкрементам групп (ПО ГОДАМ)
						if (DM->QInc_Gr_Old->State == dsInactive)
							DM->QInc_Gr_Old->Open();
						DM->QInc_Gr_Old->Insert();

						DM->QInc_Gr_OldINC_GROUP->Value =
							DM->Increment_GroupTableINC_GROUP->Value;
						// инкремент группы
						DM->QInc_Gr_OldN_GROUP->Value = Edit1->Text;
						// номер группы
						DM->QInc_Gr_OldVID_EDU->Value = ComboBox1->ItemIndex;
						// вид обучения
						DM->QInc_Gr_OldGOD->Value =
							DM->Increment_GroupTableGOD->Value;
						// год (последняя цифра учебного года)
						if (ComboBox1->ItemIndex) // заочное
								DM->QInc_Gr_OldDESCRIBE->Value =
								"1 курс заочного в " + year_cur + "/" +
								IntToStr(year_cur.ToInt() + 1) +
								" учебном году"; // пометки что на 1 курс
						else
							DM->QInc_Gr_OldDESCRIBE->Value =
								"1 курс дневного в " + year_cur + "/" +
								IntToStr(year_cur.ToInt() + 1) +
								" учебном году"; // пометки что на 1 курс

						DM->QInc_Gr_Old->ApplyUpdates();
						DM->QInc_Gr_Old->CommitUpdates();

						// сохранение в деканат инкремента группы
						DM->QToDekanatINC_GROUP->Value =
							DM->Increment_GroupTableINC_GROUP->Value;

					} // end if если такой группы нет, то создаем её
					else { // else ошибка
						ShowMessage("Введите другой номер группы");
						Edit1->Text = "";
						Edit1->SetFocus();
						DM->QToDekanat->CancelUpdates();
						return;
					} // end else ошибка
					delete[]UnicodeString1;
					delete[]UnicodeString2;
				} // else i_gr.IsNull
				// ---------------------------
				Variant v1, v2; // переменные для переноса даты в тип Date

				// сохранение данных в деканат
				DM->QToDekanatMARIAGE->Value = 0; // кол-во детей
				DM->QToDekanatVID_EDU->Value = ComboBox1->ItemIndex;
				// вид обучения
				DM->QToDekanatVID_EDU_INCLUDE->Value = ComboBox1->ItemIndex;
				// вид обучения при зачислении
				DM->QToDekanatN_FAC->Value = nom_fac; // факультет
				DM->QToDekanatKURS->Value = Edit2->Text.ToInt();
				// курс -это поле в процессе обучения изменяется
				DM->QToDekanatN_PRIKAZ_KURS->Value = Edit2->Text.ToInt();
				// курс - для отслеживания студентов после РУОР
				DM->QToDekanatN_GROUP->Value = Edit1->Text; // номер группы
				DM->QToDekanatSTATUS_PEOPLE->Value = 1;
				// статус студента, по умолчанию действующий 1

				DM->QToDekanatFAM->Value = DM->QSelect_abFAM->Value; // фамилия
				DM->QToDekanatNAME->Value = DM->QSelect_abNAME->Value; // имя
				DM->QToDekanatOTCH->Value = DM->QSelect_abOTCH->Value;
				// отчество
				DM->QToDekanatPOL->Value = DM->QSelect_abPOL->Value; // пол
				// DM->QToDekanatPLACE_R->Value = DM->QSelect_abPLACE_R->Value;
				// место рождения
				// DM->QToDekanatNAZ->Value = DM->QSelect_abNAZ->Value;
				// !!! национальность не пишем !!!
				DM->QToDekanatPAPA->Value = DM->QSelect_abPAPA->Value;
				// ФИО отца
				DM->QToDekanatMAMA->Value = DM->QSelect_abMAMA->Value;
				// ФИО матери
				DM->QToDekanatEDUCATION->Value =
					DM->QSelect_abEDUCATION->Value + 1;
				// образование
				DM->QToDekanatPHONE->Value = DM->QSelect_abPHONE->Value;
				// телефон
				DM->QToDekanatPHONE_POSLE->Value =
					DM->QSelect_abPHONE->Value; // телефон  после окончания ВУЗа

				// адреса родителей
				DM->QToDekanatADDRESS_PAPA->Value =
					DM->QSelect_abADDRESS_PAPA->Value;
				DM->QToDekanatADDRESS_MAMA->Value =
					DM->QSelect_abADDRESS_MAMA->Value;
				/* DM->QToDekanatWORK_PAPA->Value =
				 DM->QSelect_abWORK_PAPA->Value; // место работы отца
				 DM->QToDekanatWORK_MAMA->Value =
				 DM->QSelect_abWORK_MAMA->Value; // место работы матери */
				DM->QToDekanatSCHOLARSHIP->Value =
					DM->QSelect_abN_REGION->Value; // регион
				DM->QToDekanatN_CENTRE->Value =
					DM->QSelect_abN_CENTRE->Value; // район
				// если занесено только специальное образование,
				// то сохраняем его, если есть среднее образование-тогда среднее
				if (!DM->QSelect_abNAME_EDU_SPEC->IsNull) {
					DM->QToDekanatNAME_EDUC->Value =
						DM->QSelect_abNAME_EDU_SPEC->Value; // спец.образование
					DM->QToDekanatWHEN_EDUC->Value =
						DM->QSelect_abWHEN_EDU_SPEC->Value; // что закончил
					DM->QToDekanatWHERE_EDUC->Value =
						DM->QSelect_abWHERE_EDU_SPEC->Value; // когда закончил
				}
				else {
					DM->QToDekanatNAME_EDUC->Value =
						DM->QSelect_abNAME_EDU_MIDDLE->Value;
					// среднее образование
					DM->QToDekanatWHEN_EDUC->Value =
						DM->QSelect_abWHEN_EDU_MIDDLE->Value; // что закончил
					DM->QToDekanatWHERE_EDUC->Value =
						DM->QSelect_abWHERE_EDU_MIDDLE->Value; // когда закончил
				}
				DM->QToDekanatMIDDLE_B->Value =
					DM->QSelect_abMIDDLE_BALL->Value; // средний балл аттестата
				if (!DM->QSelect_abN_VID_SPORT->IsNull)
					DM->QToDekanatN_VID_SPORT->Value =
						DM->QSelect_abN_VID_SPORT->Value; // вид спорта
				else
					DM->QToDekanatN_VID_SPORT->Value = 121;
				DM->QToDekanatN_SPECIALIZ->Value = LookNewSp->KeyValue;
				// специализация
				if (CheckBox1->Checked) { // if Договор
					DM->QToDekanatN_FOUND->Value = 2;
				}
				else
					DM->QToDekanatN_FOUND->Value = 6; // бюджет

				DM->QToDekanatN_FOUND_INCLUDE->Value = LookFound->KeyValue;
				// причина зачисления (конкурс, котракт и т.д.)

				DM->QToDekanatN_PRIKAZ_INCLUDE->Value = Edit3->Text.ToInt();
				v1 = DateTimePicker1->Date;
				v2 = v1.AsType(varDate);
				DM->QToDekanatD_PRIKAZ_INCLUDE->Value = VarToSQLTimeStamp(v2);
				// по специализации ищем специальность
				DM->QToDekanatN_SPEC->Value =
					DM->QSpecializ->Lookup("N_SPECIALIZ", LookNewSp->KeyValue,
					"N_SPEC");
				DM->QToDekanatWORK_BEFORE->Value =
					DM->QSelect_abWORK_BEFORE->Value; // работа до поступления
				DM->QToDekanatADDRESS_BEFORE->Value =
					DM->QSelect_abADDRESS_BEFORE->Value;
				DM->QToDekanatADDRESS_LIFE->Value =
					DM->QSelect_abADDRESS_LIFE->Value; // домашний адрес
				DM->QToDekanatADDRESS->Value =
					DM->QSelect_abADDRESS_BEFORE->Value;
				// адрес в настоящее время такой же как до поступления
				DM->QToDekanatADDRESS_POSLE->Value =
					DM->QSelect_abADDRESS_BEFORE->Value;
				// адрес после окончания ВУЗа
				DM->QToDekanatID_STREET->Value = DM->QSelect_abSTREET->Value;
				// адрес при поступлении по ID улицы Черепанов
				DM->QToDekanatHOUSE->Value = DM->QSelect_abHOUSE->Value;
				// номер дома Черепанов
				DM->QToDekanatFLAT->Value = DM->QSelect_abFLAT->Value;
				// номер квартиры Черепанов
				DM->QToDekanatPOSTCODE->Value = DM->QSelect_abPOSTCODE->Value;
				// индекс Черепанов

				DM->QToDekanatDATA_R->Value = DM->QSelect_abDATE_R->Value;
				// дата рождения

				// !!! гражданство Когда изменят в деканате на индекс - передавать только его!!!
				DM->GrazdanToDekanatQr->Close();
				DM->GrazdanToDekanatQr->ParamByName("id")->AsSmallInt =
					DM->QSelect_abCITIZENSHIP->Value;
				DM->GrazdanToDekanatQr->Open();
				DM->QToDekanatGRAGDAN->Value =
					DM->GrazdanToDekanatQrSHORT_NAME->AsString;
				// DM->QToDekanatNAZ->Value = DM->GrazdanToDekanatQrNAME->AsString;
				DM->GrazdanToDekanatQr->Close();

				DM->QToDekanatPASPORT->Value = DM->QSelect_abPASPORT->Value;
				// паспорт
				DM->QToDekanatPERSONAL_NOMER->Value =
					DM->QSelect_abPERSONAL_NOMER->Value; // личный номер

				// фотография
				DM->QToDekanatPHOTO->Value = DM->QSelect_abPHOTO->Value;
				// Цифровая подпись!!!
				DM->QToDekanatDIGIT_SIGN->Value =
					DM->QSelect_abDIGIT_SIGN->Value;

				// Паспорт
				AnsiString pasport = DM->QSelect_abPASPORT->Value;
				series = pasport.SubString(1, 2);
				number = pasport.SubString(3, 7);
				DM->PasportFDQNOMER->Value = DM->QToDekanatNOMER->Value;
				DM->PasportFDQID_TYPE->Value = DM->QSelect_abID_TYPE->Value;
				DM->PasportFDQSERIES->Value = series;
				DM->PasportFDQNUMBER->Value = number;
				DM->PasportFDQPERSONAL_NUMBER->Value =
					DM->QSelect_abPERSONAL_NOMER->Value;
				DM->PasportFDQDATE_GIVE->Value = DM->QSelect_abDATE_V->Value;
				DM->PasportFDQDATE_VALID->Value = DM->QSelect_abDATE_OK->Value;
				DM->PasportFDQWHO_GIVE->Value = DM->QSelect_abORGAN_V->Value;
				DM->PasportFDQN_REGION->Value = DM->QSelect_abN_REGION->Value;

				AnsiString date_include = DateTimePicker1->Date;

				mon_include = date_include.SubString(4, 2).ToInt();
				year_include = date_include.SubString(7, 4).ToInt();
				// DM->TrStudFDQADD_YEAR->Value=year_include;
				AnsiString date_zac = "";
				int zach;
				if (mon_include == 7 || mon_include == 8) {
					date_zac = "01.09." + IntToStr(year_include);
					// year_include из приказа о зачислении!!!!
				}
				else {
					date_zac = date_include;
				}
                DM -> QToDekanatD_INCLUDE -> Value =
                    DateTimeToSQLTimeStamp(
                        StrToDate (
                            date_zac
                        )
                    );
				// !!! Каждый год меняется
                int year_add = Admissions::TIME::YEAR.ToInt ();

                AnsiString
                    kurs_uch = "",
                    year_end = "",
                    date_end = "";

                int vid_edu = DM->QToDekanatVID_EDU->Value;

                AnsiString kurs = Edit2->Text;

                kurs_uch = 5 + vid_edu - kurs; // сколько курсов учиться
                year_end = year_add + kurs_uch; // год окончания

                if (kurs_uch == 0)
                    year_end = year_add + 1; // год окончания

                if (vid_edu == 1)
                    date_end = "30.04." + year_end;
                else
                    date_end = "30.06." + year_end;

                DM->QToDekanatDATE_END->Value =
                    DateTimeToSQLTimeStamp(StrToDate(date_end));

				// !!! Номер студента в деканате !!!
				int nomer_people = DM->QToDekanatNOMER->Value;

				DM->QToDekanat->ApplyUpdates();
				DM->QToDekanat->CommitUpdates();
				DM->PasportFDQ->ApplyUpdates();
				DM->PasportFDQ->CommitUpdates();
				// DM->QToDekanat->Close();
				// DM->QToDekanat->Open();
				// DM->QToDekanat->Last();

				// при добавлении нового студента в табл. Спорт заносится осн.вид спорта без разряда
				// if (nom_fac != 4) { // if факультет не Институт туризма
				DM->SportQuery->Close();
				// Закрытие Query для установки параметров
				DM->SportQuery->Params->Items[0]->AsInteger = nomer_people;
				DM->SportQuery->Open(); // Выполнение запроса
				DM->SportQuery->Insert();
				DM->SportQueryNOMER->Value = nomer_people;
				if (!DM->QSelect_abN_VID_SPORT->IsNull)
					DM->SportQueryN_VID_SPORT->Value =
						DM->QSelect_abN_VID_SPORT->Value; // вид спорта
				else
					DM->SportQueryN_VID_SPORT->Value = 121; // нет
				if (!DM->QSelect_abN_SPORT_CATEGORY->IsNull)
					DM->SportQuerySPORT_CATEGORY->Value =
						DM->QSelect_abN_SPORT_CATEGORY->Value;
				else
					DM->SportQuerySPORT_CATEGORY->Value = 12;
				// спортивный разряд по умолчанию ставим - нет
				DM->SportQuery->ApplyUpdates();
				DM->SportQuery->CommitUpdates();
				// } //  if факультет не Институт туризма
				// DM->SportQuery->Close();

				// надо сделать:
				// 1. целевые контракты  !!!
				if ((LookFound->KeyValue == 1 || LookFound->KeyValue == 7 ||
					LookFound->KeyValue == 8) && DM->QSelect_abN_CK->Value > -1)
				{ // if целевые контракты (или ВК или БВИ но с целевым)
					// только если основание зачисления Целевой контракт и он есть
					if (DM->QCkToDekanat->State == dsInactive)
						DM->QCkToDekanat->Open();
					DM->QCkToDekanat->Insert();
					DM->QCkToDekanatNOMER->Value = nomer_people;
					// !!!  Закрытая БД!!!
					if (!DM->RegCentrTbl->Active)
						DM->RegCentrTbl->Active = true;
					Variant ck = DM->RegCentrTbl->Locate("N_CENTRE",
						DM->QSelect_abN_CK->Value, fl);
					// DM->TCk->Locate("N_CK", DM->QSelect_abN_CK->Value, fl);
					if (ck) {

						// !!! REGIONAL_CENTRE.N_Region
						DM->QCkToDekanatN_REGION->Value =
							DM->RegCentrTbl->FieldByName("N_REGION")->Value;
						// DM->TCkN_REGION->Value;
						// !!! REGIONAL_CENTRE.N_Centre
						DM->QCkToDekanatN_CENTRE->Value =
							DM->RegCentrTbl->FieldByName("N_CENTRE")->Value;
						// DM->TCkN_CENTRE->Value;
						// !!! LookSp->KeyValue Связь с таблицей Specializ - специализация
						DM->QCkToDekanatN_SPECIALIZ->Value = LookSp->KeyValue;
						// DM->TCkN_SPECIALIZ->Value;
						// !!!Кто дал контракт: 0 - ОФКСиТ, 1- РОО, 2 - РУО, 3 - ГОО, 4 - ГУО
						// !!!CUSTOMER в ABITURIENT не записан
						/* DM->QCkToDekanatCUSTOMER->Value =
						 DM->TCkCUSTOMER->Value; */
						DM->QCkToDekanatCUSTOMER->Value = -1;
						// действующий контракт
						DM->QCkToDekanatSTATUS_CK->Value = 0;
						DM->QCkToDekanat->ApplyUpdates();
						DM->QCkToDekanat->CommitUpdates();
					}
				} // end if целевые контракты только если основание зачисления Целевой контракт и он есть

				AnsiString ab_vk = DM->QSelect_abV_K->Value;
				AnsiString ab_pr = DM->QSelect_abPRIV->Value;

				// 2. Сироты и ЧАЭС и инвалиды
				AnsiString year = ""; // учебный год
				year = AnsiToUtf8(cur_d.CurrentDate()).SubString(7, 4);
				// !!! Переделать! Актуально для 2017 !!!
				// Инвалид 1 или 2 гр.
				DM->AbiturInvTmpQr->Close();
				DM->AbiturInvTmpQr->ParamByName("nomer_ab")->AsString =
					DM->QSelect_abNOMER_AB->Value;
				DM->AbiturInvTmpQr->Open();
				if (DM->AbiturInvTmpQrDAT_PRIV->Value)
					Save_Priv(nomer_people, 1, "Инвалид 1 или 2 гр.", year);
				DM->AbiturInvTmpQr->Close();
				// Сирота
				DM->AbiturSirTmpQr->Close();
				DM->AbiturSirTmpQr->ParamByName("nomer_ab")->AsString =
					DM->QSelect_abNOMER_AB->Value;
				DM->AbiturSirTmpQr->Open();
				if (DM->AbiturSirTmpQrDAT_PRIV->Value)
					Save_Priv(nomer_people, 1, "Сирота", year);
				DM->AbiturSirTmpQr->Close();

				/* if (ab_vk != "" || ab_pr != "") { // if ищем привелегии
				 AnsiString year = ""; // учебный год
				 year = AnsiToUtf8(cur_d.CurrentDate()).SubString(7, 4);
				 int len; // длина текста

				 // Save_Priv(nomer_people, n_priv, text_priv, year); //функция, которая сохраняет привелегии (сирота, Чаэс, инвалид)
				 // номер студента, номер привелегии (1 - сирота, 2 - ЧАЭС, 3 - инвалид),
				 // текст привелегии ЧАЭС (ст. 18, или ст. др, инвалид - 1,2 гр. или 3 гр.), текущий учебный год

				 // ---------- вне конкурса
				 len = ab_vk.Length();
				 for (int i = 1; i <= len; i++) { // for Vk
				 int el_str = StrToInt(ab_vk[i]);
				 switch (el_str) { // switch Vk
				 case 1:
				 Save_Priv(nomer_people, 1, "Сирота", year);
				 break;
				 case 2:
				 Save_Priv(nomer_people, 3,
				 "Инвалид 1 или 2 гр.", year);
				 break;

				 } // end switch Vk
				 } // end for Vk

				 // ----преимущества при зачислении
				 len = ab_pr.Length();
				 int len_old = len;
				 int p = 0; // позиция символа первого вхождения точки
				 for (int i = 1; i <= len_old; i++) { // for Priv
				 if (len != 0) { // if есть еще строка
				 p = ab_pr.Pos(".");

				 if (p != 1) {
				 int Priv = StrToInt(ab_pr.SubString(1, p - 1));
				 switch (Priv) { // switch Vk
				 case 1:
				 Save_Priv(nomer_people, 1, "Сирота", year);
				 break;
				 case 2:
				 Save_Priv(nomer_people, 3,
				 "Инвалид 1 или 2 гр.", year);
				 break;
				 case 5:
				 Save_Priv(nomer_people, 2,
				 "ЧАЭС ст.18", year);
				 break;
				 case 6:
				 Save_Priv(nomer_people, 3,
				 "Инвалид 3 гр.", year);
				 break;
				 case 7:
				 Save_Priv(nomer_people, 2,
				 "ЧАЭС ст.", year);
				 break;

				 } // end switch Vk
				 }
				 } // end if есть еще строка
				 else
				 break;
				 ab_pr.Delete(1, p);
				 len = ab_pr.Length();
				 } // end for Priv
				 } // if ищем привелеги */

				// 3. Иностранны  язык
				if (!DM->QSelect_abN_LANGVICH->IsNull)
				{ // if есть оценка по языку
					if (DM->QLangvichToDekanat->State == dsInactive)
						DM->QLangvichToDekanat->Open();
					DM->QLangvichToDekanat->Insert();
					DM->QLangvichToDekanatNOMER->Value = nomer_people;
					DM->QLangvichToDekanatN_LANGVICH->Value =
						DM->QSelect_abN_LANGVICH->Value;
					DM->QLangvichToDekanat->ApplyUpdates();
					DM->QLangvichToDekanat->CommitUpdates();
				} // end if есть оценка по языку
				// -----------------------

				// ----передаем статус абитуриенту: 5- поступившему
				DM->QSelect_ab->Edit();
				DM->QSelect_abSTATUS->Value = 5; // зачисленные
				DM->QSelect_abN_FOUND->Value = LookFound->KeyValue;
				// причина зачисления (конкурс, котракт и т.д.)
				DM->QSelect_abN_PRIKAZ_INCLUDE->Value = Edit3->Text.ToInt();
				DM->QSelect_abD_PRIKAZ_INCLUDE->Value = VarToSQLTimeStamp(v2);
				DM->QSelect_ab->ApplyUpdates();
				DM->QSelect_ab->CommitUpdates();
				// сохраняем изменения в статусе абитуриента для последующей статистики

				// ----передаем опись документов
				DM->ListDocFDQ->Close();
				DM->ListDocFDQ->ParamByName("NOMER_AB")->Value = n_ab[i];
				DM->ListDocFDQ->Open();
				DM->QListDocToDekanat->Close();
				DM->QListDocToDekanat->Open();
				for (int i = 0; i < DM->ListDocFDQ->RecordCount; i++) {
					DM->QListDocToDekanat->Insert();
					DM->QListDocToDekanatNOMER->Value = nomer_people;
					DM->QListDocToDekanatNAME_DOC->Value =
						DM->ListDocFDQN_DOC->Value;
					if (!DM->ListDocFDQDATE_DOC->IsNull) {
						DM->QListDocToDekanatDOC_DATE->Value =
							DM->ListDocFDQDATE_DOC->Value;
					}
					DM->QListDocToDekanatDOC_INDEX->Value =
						DM->ListDocFDQDOC_INDEX->Value;
					switch (DM->ListDocFDQN_DOC->Value) {
					case 1:
					case 2:
					case 3:
					case 4:
					case 6:
					case 82:
						DM->QListDocToDekanatNOTE->Value = note1;
						break;
					case 85:
						DM->QListDocToDekanatNOTE->Value = note3;
						break;
					case 7:
						DM->QListDocToDekanatNOTE->Value = note2;
						break;
					case 8:
						if (!ComboBox1->ItemIndex) {
							DM->QListDocToDekanatNOTE->Value = note5;
						}
						break;
					}
					DM->QListDocToDekanat->ApplyUpdates();
					DM->QListDocToDekanat->CommitUpdates();
					DM->ListDocFDQ->Next();
				}

				DM->QSertificat->Close();
				DM->QSertificat->ParamByName("NOMER")->Value = n_ab[i];
				DM->QSertificat->Open();
				for (int i = 0; i < DM->QSertificat->RecordCount; i++) {
					DM->QSertificatToDekanat->Close();
					DM->QSertificatToDekanat->Open();
					DM->QSertificatToDekanat->Insert();
					DM->QSertificatToDekanatNOMER->Value = nomer_people;
					DM->QSertificatToDekanatNAME_DOC->Value = 5;
					DM->QSertificatToDekanatDOC_INDEX->Value =
						DM->QSertificatSERIA_S->Value + " " +
						DM->QSertificatNOMER_S->Value;
					DM->QSertificatToDekanat->ApplyUpdates();
					DM->QSertificatToDekanat->CommitUpdates();
					DM->QSertificat->Next();
				}
			}
		}

		DM->QSelect_ab->Close();
		delete n_ab;
		List1->Clear();
		ShowMessage("Занесение в деканат прошло удачно!");
	}
	catch (...) {
		ShowMessage("Ошибка!");
	}
}
// ---------------------------------------------------------------------------

void __fastcall TGroup_FacForm::SpeedButton1Click(TObject *Sender)
{ // действие как и по двойному щелчку - занесение ФИО абитуриента в ListBox
	DBGrid1DblClick(this);
}
// ---------------------------------------------------------------------------

void __fastcall TGroup_FacForm::SpeedButton3Click(TObject *Sender)
{ // удаление из ListBox выбранного абитуриента
	int i = List1->ItemIndex;
	AnsiString stroka = List1->Items->Strings[i];
	// нахождение строки с выбранным абитуриентом
	int j = stroka.AnsiPos(' '); // ищем позицию первого пробела в строке
	AnsiString f = stroka.SubString(1, j - 1);
	// запоминаем подстроку с фамилий абитуриента
	stroka.Delete(1, j); // урезаем строку до пробела включительно
	j = stroka.AnsiPos(' '); // ищем позицию следующего пробела в строке
	AnsiString n = stroka.SubString(1, j - 1); // запоминаем подстроку с именем
	stroka.Delete(1, j); // урезаем строку до следующего пробела
	AnsiString o = stroka; // оставшуюся часть запоминаем отчество
	// очищаем  ListBox
	List1->Items->Delete(List1->ItemIndex);
	// создаем массив для поиска удаленного абитуриента в QSelect_ab,
	// чтобы очистить массив n_ab от данной записи
	Variant loc[3];
	loc[0] = Variant(f);
	loc[1] = Variant(n);
	loc[2] = Variant(o);

	Variant nom = DM->QSelect_ab->Lookup("FAM;NAME;OTCH", VarArrayOf(loc, 2),
		"NOMER_AB");
	if (nom) // если такой абитуриент найден
	{
		for (int q = 0; q < DM->QSelect_ab->RecordCount; q++) {
			if (n_ab[q] == nom) {
				n_ab[q] = 0;
				break;
			} // очищаем массив, присваивая элементу 0
		}

	}
	else // это действие быть не должно, но на всякий случай
	{
		ShowMessage("Ничего не вышло!");
	}

}
// ---------------------------------------------------------------------------

void __fastcall TGroup_FacForm::SpeedButton4Click(TObject *Sender)
{ // удаление всех выбранных абитуриентов из ListBoxa
	// и очищение массива
	for (int i = 0; i < DM->QSelect_ab->RecordCount; i++) {
		n_ab[i] = 0;
	}
	p_n = 0;
	List1->Clear();

}
// ---------------------------------------------------------------------------

void __fastcall TGroup_FacForm::SpeedButton2Click(TObject *Sender)
{ // занесение всех абитуриентов из Grida в ListBox, с запоминанием в массиве
	// номеров абитуриентов
	DM->QSelect_ab->First();
	for (int i = 0; i < DM->QSelect_ab->RecordCount; i++) {
		List1->Items->Add(DM->QSelect_abFAM->Value + " " +
			DM->QSelect_abNAME->Value + " " + DM->QSelect_abOTCH->Value);
		n_ab[i] = DM->QSelect_abNOMER_AB->Value;
		DM->QSelect_ab->Next();
	}

}
// ---------------------------------------------------------------------------

void __fastcall TGroup_FacForm::LookSpCloseUp(TObject *Sender) {
	LookNewSp->KeyValue = LookSp->KeyValue;
}
// ---------------------------------------------------------------------------

void __fastcall TGroup_FacForm::LookFoundCloseUp(TObject *Sender) {
	if (LookFound->KeyValue == 2 || LookFound->KeyValue == 14 ||
		LookFound->KeyValue == 14) { // if Договор
		CheckBox1->Checked = true;
	}
	else
		CheckBox1->Checked = false;
}

// ---------------------------------------------------------------------------
void __fastcall TGroup_FacForm::DateTimePicker1Change(TObject *Sender) {
	DateTimePicker1->Time = StrToTime("00:00");
}
// ---------------------------------------------------------------------------
