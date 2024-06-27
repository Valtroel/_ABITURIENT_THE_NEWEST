// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <comobj.hpp>

#include "Dlg_ProtokolUnit.h"
#include "DMStatUnit.h"
#include "DMUnit.h"
#include "Func.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
//#pragma link "RXToolEdit"
#pragma resource "*.dfm"
TDlg_ProtokolForm * Dlg_ProtokolForm;
Variant ExcApp;
Variant Vv;

// ---------------------------------------------------------------------------
__fastcall TDlg_ProtokolForm::TDlg_ProtokolForm (TComponent * Owner)
    : TForm(Owner)
{ }

// ---------------------------------------------------------------------------
void __fastcall TDlg_ProtokolForm::FormClose(
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}

// ---------------------------------------------------------------------------
void __fastcall TDlg_ProtokolForm::BitBtn1Click(TObject *Sender) {

    // Формирование протокола
    TDate dat_prot;
   //    if ( DateTimePicker1-> DateEdit1->Text == "  .  .    ")
   //        dat_prot = dat_prot.CurrentDate();
   //    else
        dat_prot = DateTimePicker1->Date;
    String date_t = dat_prot.FormatString("dd/mm/yyyy");
    TDate d1 = StrToDate(date_t);
    TDate d2 = d1 + 1;

    // AnsiString ex_name = "Ежедневный протокол 2021.xls";
    AnsiString ex_name = DocumentFile::PROTOCOL::daily;

    // открытие Excel и показ
    ExcApp = Variant::CreateObject("Excel.Application");
    Variant Workbook = OpenBook(ExcApp, cur_dir + ex_name);
    Variant Sheet = SelectSheet(Workbook, "Лист1");
    // DisplayAlert(ExcApp);

    AnsiString n_file =
            DocumentName::PROTOCOL::daily   +
        " факультета "                      +
            fac1                            +
        " за "                              +
            AnsiToUtf8 (date_t)             +
        ".xls";
    Variant WorkSaveAs = SaveBookAs(Workbook, out_dir + n_file);
    // OVisible(ExcApp);

    // Шапка приложения
    CellValue("Приложение\nк протоколу заседания\nприёмной комиссии\n" +
        date_t + " №" + Edit1->Text, 10, 1);

    CellValue(Edit1->Text, 3, 3); // номер протокола
    CellValue(fac1, 7, 3); // название факультета
    CellValue(date_t, 5, 3); // дата протокола

    int beg_nom_str = 5;
    int max_nom_str = beg_nom_str;
    // определение номера строки для занесения формы обучения
    String FIOstr;
    int cnt_str[12];
    Variant Cell1;
    Variant Cell2;
    Variant Range1;
    for (int vid_edu = 0; vid_edu < 2; vid_edu++) {
        // обнуление нумерации
        for (int i = 0; i < 12; i++)
            cnt_str[i] = 0;
        max_nom_str++;
        beg_nom_str = max_nom_str;
        // Заголовок формы обучения
        Cell1 = SelectCell(1, max_nom_str);
        Cell2 = SelectCell(12, max_nom_str);
        Range1 = Range(Sheet, Cell1, Cell2);
        mergeCell(Range1); // объединение ячеек
        HorizontalAlign(Cell1, 3);
        if (vid_edu)
            CellValue("заочная форма получения образования", 1, max_nom_str);
        else
            CellValue("дневная форма получения образования", 1, max_nom_str);
        //
        CellFont("Arial", 12, true, false, 3, Cell1);
        DMStat->ProtokolQr->Close();
        DMStat->ProtokolQr->ParamByName("n_fac")->AsSmallInt = nom_fac;
        DMStat->ProtokolQr->ParamByName("vid_edu")->AsSmallInt = vid_edu;
        DMStat->ProtokolQr->ParamByName("date_in1")->AsDateTime = d1;
        DMStat->ProtokolQr->ParamByName("date_in2")->AsDateTime = d2;
        DMStat->ProtokolQr->Open();
        while (!DMStat->ProtokolQr->Eof) {
            FIOstr =
                DMStat->ProtokolQrFAM->AsString +
            " " +
                DMStat->ProtokolQrNAME->AsString.SubString(1, 1) +
            ".";
            
            if (DMStat->ProtokolQrOTCH->AsString != "")
                FIOstr += DMStat->ProtokolQrOTCH->AsString.SubString(1, 1) + ".";
            
            if (DMStat->ProtokolQrCATEGORY_IF->Value) // иностранец----------------
            {
                cnt_str[10]++;

                if (beg_nom_str + cnt_str[10] > max_nom_str)
                    max_nom_str = beg_nom_str + cnt_str[10];
        
                if (    DMStat->ProtokolQrTERM_EDU->Value == 4
                     || DMStat->ProtokolQrTERM_EDU->Value == 5
                   )
                    FIOstr += "(2ВО)";
        
                CellValue(IntToStr(cnt_str[10]) + "." + FIOstr, 11,
                    beg_nom_str + cnt_str[10]);
            }
            else // РБ---------------------------------------------------------
            {
                if (    (   DMStat->ProtokolQrTERM_EDU->Value == 4 // 2-е высшее 2 курс платно
                         || DMStat->ProtokolQrTERM_EDU->Value == 5
                        )
                     && DMStat->ProtokolQrPRICE->Value
                   )
                {
                    cnt_str[11]++;

                    if (beg_nom_str + cnt_str[11] > max_nom_str)
                        max_nom_str = beg_nom_str + cnt_str[11];

                    CellValue(
                        IntToStr(cnt_str[11]) + "." + FIOstr,
                        12,
                        beg_nom_str + cnt_str[11]
                    );
                }
                else
                {
                    if (    DMStat->ProtokolQrTERM_EDU->Value == 1 // сокращёнка
                         || DMStat->ProtokolQrTERM_EDU->Value == 2
                       )
                    {
                        if (DMStat->ProtokolQrPRICE->Value) // оплата-----------------------
                        {
                            cnt_str[7]++;

                            if (beg_nom_str + cnt_str[7] > max_nom_str)
                                max_nom_str = beg_nom_str + cnt_str[7];
                
                            switch (DMStat->ProtokolQrKONKURS->Value)
                            {
                                case 1: // БВИ
                                        FIOstr += "(БВИ)";
                                    break;
                                case 2: // ВК
                                        FIOstr += "(ВК)";
                                    break;
                                case 3: // ЦК
                                        FIOstr += "(ЦК)";
                                    break;
                            }
                            CellValue(IntToStr(cnt_str[7]) + "." + FIOstr, 8,
                                beg_nom_str + cnt_str[7]);
                        }
                        else { // бюджет----------------------------------------------
                            cnt_str[3]++;
                            if (beg_nom_str + cnt_str[3] > max_nom_str)
                                max_nom_str = beg_nom_str + cnt_str[3];
                            switch (DMStat->ProtokolQrKONKURS->Value) {
                            case 1: // БВИ
                                FIOstr = FIOstr + "(БВИ)";
                                break;
                            case 2: // ВК
                                FIOstr = FIOstr + "(ВК)";
                                break;
                            case 3: // ЦК
                                FIOstr = FIOstr + "(ЦК)";
                                break;
                            }
                            CellValue(IntToStr(cnt_str[3]) + "." + FIOstr, 4,
                                beg_nom_str + cnt_str[3]);
                        }
                    }
                    else { // полный срок
                        if (DMStat->ProtokolQrKONKURS->Value == 0)
                        { // общий конкурс
                            if (DMStat->ProtokolQrPRICE->Value) { // платно
                                cnt_str[6]++;
                                if (beg_nom_str + cnt_str[6] > max_nom_str)
                                    max_nom_str = beg_nom_str + cnt_str[6];
                                if (DMStat->ProtokolQrTERM_EDU->Value > 2)
                                    FIOstr = FIOstr + "(2ВО)";
                                CellValue(IntToStr(cnt_str[6]) + "." + FIOstr,
                                    7, beg_nom_str + cnt_str[6]);
                            }
                            else { // бюджет
                                cnt_str[1]++;
                                if (beg_nom_str + cnt_str[1] > max_nom_str)
                                    max_nom_str = beg_nom_str + cnt_str[1];
                                if (DMStat->ProtokolQrTERM_EDU->Value > 2)
                                    FIOstr = FIOstr + "(2ВО)";
                                CellValue(IntToStr(cnt_str[1]) + "." + FIOstr,
                                    2, beg_nom_str + cnt_str[1]);
                            }
                        }
                        if (DMStat->ProtokolQrKONKURS->Value == 2)
                        { // вне конкурса
                            if (DMStat->ProtokolQrPRICE->Value) { // платно
                                cnt_str[8]++;
                                if (beg_nom_str + cnt_str[8] > max_nom_str)
                                    max_nom_str = beg_nom_str + cnt_str[8];
                                if (DMStat->ProtokolQrTERM_EDU->Value > 2)
                                    FIOstr = FIOstr + "(2ВО)";
                                CellValue(IntToStr(cnt_str[8]) + "." + FIOstr,
                                    9, beg_nom_str + cnt_str[8]);
                            }
                            else { // бюджет
                                cnt_str[4]++;
                                if (beg_nom_str + cnt_str[4] > max_nom_str)
                                    max_nom_str = beg_nom_str + cnt_str[4];
                                if (DMStat->ProtokolQrTERM_EDU->Value > 2)
                                    FIOstr = FIOstr + "(2ВО)";
                                CellValue(IntToStr(cnt_str[4]) + "." + FIOstr,
                                    5, beg_nom_str + cnt_str[4]);
                            }
                        }
                        if (DMStat->ProtokolQrKONKURS->Value == 1) { // БВИ
                            if (DMStat->ProtokolQrPRICE->Value) { // платно
                                cnt_str[9]++;
                                if (beg_nom_str + cnt_str[9] > max_nom_str)
                                    max_nom_str = beg_nom_str + cnt_str[9];
                                if (DMStat->ProtokolQrTERM_EDU->Value > 2)
                                    FIOstr = FIOstr + "(2ВО)";
                                CellValue(IntToStr(cnt_str[9]) + "." + FIOstr,
                                    10, beg_nom_str + cnt_str[9]);
                            }
                            else { // бюджет
                                cnt_str[5]++;
                                if (beg_nom_str + cnt_str[5] > max_nom_str)
                                    max_nom_str = beg_nom_str + cnt_str[5];
                                if (DMStat->ProtokolQrTERM_EDU->Value > 2)
                                    FIOstr = FIOstr + "(2ВО)";
                                CellValue(IntToStr(cnt_str[5]) + "." + FIOstr,
                                    6, beg_nom_str + cnt_str[5]);
                            }
                        }
                        if (DMStat->ProtokolQrKONKURS->Value == 3) { // ЦК
                            cnt_str[2]++;
                            if (beg_nom_str + cnt_str[2] > max_nom_str)
                                max_nom_str = beg_nom_str + cnt_str[2];
                            if (DMStat->ProtokolQrTERM_EDU->Value > 2)
                                FIOstr = FIOstr + "(2ВО)";
                            CellValue(IntToStr(cnt_str[2]) + "." + FIOstr, 3,
                                beg_nom_str + cnt_str[2]);
                        }
                    }
                }
            }
            DMStat->ProtokolQr->Next();
        }

    }

    for (int j = 2; j < 12; j++)
    { // цикл по столбцам протокола  для установки ширины столбца
        AutoFitColumn(Sheet, j);
    }

    // сохранение
    DisplayAlert(ExcApp);
    OVisible(ExcApp);
    WorkSaveAs = SaveBook(Workbook);
    //
    ExcApp.Clear();
    Close();
}

// ---------------------------------------------------------------------------
void __fastcall TDlg_ProtokolForm::Panel1DblClick(TObject *Sender) {

    TDate dat_prot;
    //if (DateEdit1->Text == "  .  .    ")
   //        dat_prot = dat_prot.CurrentDate();
  //    else
        dat_prot = DateTimePicker1->Date;
    //
    AnsiString name_doc;
    // if (oplata_konkurs == 0)
        name_doc = DocumentFile::PROTOCOL::admitted;
    // else
    //     name_doc = "Протокол для Грасс.doc";
    Vv = CreateOleObject("Word.Basic");
    Vv.Exec(Procedure("FileOpen") << cur_dir + name_doc);
    // Vv.Exec(Procedure("GoBack"));
    // ---
    AnsiString plata = "";

    // Vv.Exec(Procedure("Insert") << AnsiToUtf8("1. Нижеперечисленных абитуриентов допустить к вступительным испытаниям после прохождения медицинского освидетельствования:\n"));
    String s_priv;
    for (int k = 0; k < 2; k++) { // k цикл по виду обучения
        if (!k)
            Vv.Exec(Procedure("Insert") << AnsiToUtf8
            ("\nДНЕВНАЯ ФОРМА ПОЛУЧЕНИЯ ОБРАЗОВАНИЯ\n"));
        else
            Vv.Exec(Procedure("Insert") << AnsiToUtf8
            ("\nЗАОЧНАЯ ФОРМА ПОЛУЧЕНИЯ ОБРАЗОВАНИЯ\n"));

        for (int p = 0; p < 2; p++) { // p цикл по форме оплаты
            if (!p)
                plata = " за счет средств республиканского бюджета\n";
            else
                plata = " на платной основе\n";

            Vv.Exec(Procedure("Insert") << AnsiToUtf8("\nОбщий конкурс" +
                plata));

            for (int l = 1; l <= 3; l++) { // l цикл по всем факультетам
                DMStat->ProtokolAllQr->Close();
                DMStat->ProtokolAllQr->ParamByName("n_fac")->AsSmallInt = l;
                DMStat->ProtokolAllQr->ParamByName("dtate_priem")->AsDateTime =
                    dat_prot;
                DMStat->ProtokolAllQr->ParamByName("vid_edu")->AsSmallInt = k;
                DMStat->ProtokolAllQr->ParamByName("price")->AsSmallInt = p;
                DMStat->ProtokolAllQr->Open();
                while (!DMStat->ProtokolAllQr->Eof) {
                    AnsiString s_priv = "";
                    if (DMStat->ProtokolAllQrTERM_EDU->Value > 2)
                        s_priv = s_priv + "(2ВО)";
                    Vv.Exec(Procedure("Insert")
                        << DMStat->ProtokolAllQrFAM->Value + " " +
                        DMStat->ProtokolAllQrNAME->Value.SetLength(1) + "." +
                        DMStat->ProtokolAllQrOTCH->Value.SetLength(1) + "." +
                        s_priv + "\n");
                    DMStat->ProtokolAllQr->Next();
                }
                DMStat->ProtokolAllQr->Close();

            } // l  цикл по всем факультетам

            if (!p) {
                Vv.Exec(Procedure("Insert") << AnsiToUtf8
                    ("\nКонкурс на целевые места\n"));
                for (int l = 1; l <= 3; l++) { // l цикл по всем факультетам
                    // DMStat->ProtokolCkQr-
                    DMStat->ProtokolCkQr->Close();
                    DMStat->ProtokolCkQr->ParamByName("n_fac")->AsSmallInt = l;
                    DMStat->ProtokolCkQr->ParamByName("dtate_priem")
                        ->AsDateTime = dat_prot;
                    DMStat->ProtokolCkQr->ParamByName("vid_edu")
                        ->AsSmallInt = k;
                    DMStat->ProtokolCkQr->Open();
                    while (!DMStat->ProtokolCkQr->Eof) {
                        AnsiString s_priv = "";
                        if (DMStat->ProtokolCkQrTERM_EDU->Value == 4)
                            s_priv = s_priv + "(2ВО 1к)";
                        if (DMStat->ProtokolCkQrTERM_EDU->Value == 5)
                            s_priv = s_priv + "(2ВО 2к)";
                        // --------------------------------------------------------------
                        /* int pr_ck = 0;
                         DM->LogIDSelQr->Close();
                         DM->LogIDSelQr->ParamByName("nomer_ab")->AsInteger =
                         DMStat->ProtokolCkQrNOMER_AB->Value;
                         DM->LogIDSelQr->Open();
                         DM->SelPrivLogQr->Close();
                         DM->SelPrivLogQr->ParamByName("id_log")->AsInteger =
                         DM->LogIDSelQrID_LOG->Value;
                         DM->SelPrivLogQr->Open();
                         while (!DM->SelPrivLogQr->Eof) {
                         switch (DM->SelPrivLogQrN_PRIV->Value) {
                         case 0: // БВИ
                         DM->WithOutTestLogQr->Close();
                         DM->WithOutTestLogQr->ParamByName("sel_priv")->AsSmallInt =
                         DM->SelPrivLogQrSEL_PRIV->Value;
                         DM->WithOutTestLogQr->ParamByName("dat_priv")->AsSmallInt =
                         DM->SelPrivLogQrDAT_PRIV->Value;
                         DM->WithOutTestLogQr->Open();
                         while (!DM->WithOutTestLogQr->Eof) {
                         pr_ck = pr_ck++;
                         DM->WithOutTestLogQr->Next();
                         }
                         DM->WithOutTestLogQr->Close();
                         pr_ck = -1;
                         break;
                         case 1: // ВК
                         // DM->OutTestQr
                         DM->OutTestQr->Close();
                         DM->OutTestQr->ParamByName("sel_priv")->AsSmallInt =
                         DM->SelPrivLogQrSEL_PRIV->Value;
                         DM->OutTestQr->ParamByName("dat_priv")->AsSmallInt =
                         DM->SelPrivLogQrDAT_PRIV->Value;
                         DM->OutTestQr->Open();
                         while (!DM->OutTestQr->Eof) {
                         if (text_tmp.SubString(text_tmp.Length(),1) !=" ")
                         text_tmp = text_tmp + ", ";
                         text_tmp = text_tmp + DM->OutTestQrSHORT_NAME->Value;
                         if (DM->OutTestQrSHORT_NAME_1->Value != "да")
                         text_tmp =
                         text_tmp + " - " + DM->OutTestQrSHORT_NAME_1->Value;
                         if (pr_ck > -1)
                         pr_ck = pr_ck++;
                         DM->OutTestQr->Next();
                         }
                         DM->OutTestQr->Close();
                         if ((pr_ck > 0) && (DM->QAbituraKONKURS->Value == 3)) {
                         CellValue("Вид конкурса: вне конкурса", 1, 41);
                         pr_ck = -1;
                         }
                         break; */
                        // -----------------------------------------------------------------------

                        Vv.Exec(Procedure("Insert")
                            << DMStat->ProtokolCkQrFAM->Value + " " +
                            DMStat->ProtokolCkQrNAME->Value.SetLength(1) + "." +
                            DMStat->ProtokolCkQrOTCH->Value.SetLength(1) + "." +
                            s_priv + "\n");
                        DMStat->ProtokolCkQr->Next();
                    }
                }
                DMStat->ProtokolCkQr->Close();
            }

            Vv.Exec(Procedure("Insert") << AnsiToUtf8
                ("\nНа сокращенный срок обучения" + plata));

            Vv.Exec(Procedure("Insert") << AnsiToUtf8("\nВне конкурса" +
                plata));

            Vv.Exec(Procedure("Insert") << AnsiToUtf8("\nБез экзаменов" +
                plata));

            Vv.Exec(Procedure("Insert") << AnsiToUtf8
                ("\nГраждане иностранных государств\n"));

            /* for (int j = 0; j < 6; j++) { // j цикл по столбцам протокола

             switch (j) { // switch j (цикл по разным видам конкурса)
             case 0: // Город  (Общий - если не делим платников на город/село)
             // if (!oplata_konkurs & p)
             Vv.Exec(Procedure("Insert") << AnsiToUtf8
             ("\nОбщий конкурс" + plata));
             break;
             case 1: // Целевое направление
             if (!p) {
             Vv.Exec(Procedure("Insert") << AnsiToUtf8
             ("\nКонкурс на целевые места\n"));
             }
             break;
             case 2: // На 2 курс
             Vv.Exec(Procedure("Insert") << AnsiToUtf8
             ("\nНа сокращенный срок обучения" + plata));
             break;
             case 3: // Вне конкурса
             Vv.Exec(Procedure("Insert") << AnsiToUtf8("\nВне конкурса" +
             plata));
             break;
             case 4: // Без экзаменов
             Vv.Exec(Procedure("Insert") << AnsiToUtf8
             ("\nБез экзаменов" + plata));
             break;
             case 5: // Иностранцы
             if (p) {
             Vv.Exec(Procedure("Insert") << AnsiToUtf8
             ("\nГраждане иностранных государств\n"));
             }
             break;
             } // switch j (цикл по разным видам конкурса)

             for (int l = 1; l <= 3; l++) { // l цикл по всем факультетам
             Protokol_FIO(l, dat_prot, k, j, p);
             } // l  цикл по всем факультетам
             } // j цикл по столбцам протокола */

        } // p цикл по форме оплаты
    } // k цикл по виду обучения

    Vv.Exec (
        Procedure ("Insert")
            << AnsiToUtf8 (
                "\n2. СЛУШАЛИ:\n        "                       +
                    LegallyAuthorizedPerson::edu_head_desc      +
                " – абитуриентов, которые представили три "     \
                "сертификата централизованного тестирования, "  \
                "допустить к участию в конкурсе.\n")
        );
    Vv.Exec (
        Procedure ("Insert")
            << AnsiToUtf8 (
                "\РЕШИЛИ:\n        2.1. Нижеперечисленных "     \
                "абитуриентов, представивших три сертификата "  \
                "централизованного тестирования, допустить к "  \
                "участию в конкурсе:\n")
        );
    for ( int k = 0;                                                            // k цикл по виду обучения
              k < 2;
              ++k
        )
    {
        if (!k)
            Vv.Exec(Procedure("Insert") << AnsiToUtf8
            ("\nДНЕВНАЯ ФОРМА ПОЛУЧЕНИЯ ОБРАЗОВАНИЯ\n"));
        else
            Vv.Exec(Procedure("Insert") << AnsiToUtf8
            ("\nЗАОЧНАЯ ФОРМА ПОЛУЧЕНИЯ ОБРАЗОВАНИЯ\n"));

        Vv.Exec(Procedure("Insert") << AnsiToUtf8
            ("\nОбщий конкурс за счет средств республиканского бюджета\n"));
        Protokol_FIO(4, dat_prot, k, 0, 0);

        if (!k) {
            Vv.Exec(Procedure("Insert") << AnsiToUtf8
                ("\nКонкурс на целевые места\n"));
            Protokol_FIO(4, dat_prot, k, 2, 0);
        }

        Vv.Exec(Procedure("Insert") << AnsiToUtf8
            ("\nВне конкурса за счет средств республиканского бюджета\n"));
        Protokol_FIO(4, dat_prot, k, 3, 0);

        Vv.Exec(Procedure("Insert") << AnsiToUtf8
            ("\nБез экзаменов за счет средств республиканского бюджета\n"));
        Protokol_FIO(4, dat_prot, k, 4, 0);

        Vv.Exec(Procedure("Insert") << AnsiToUtf8
            ("\nОбщий конкурс на платной основе\n"));
        Protokol_FIO(4, dat_prot, k, 0, 1);

        Vv.Exec(Procedure("Insert") << AnsiToUtf8
            ("\nНа сокращенный срок обучения на платной основе\n"));
        Protokol_FIO(4, dat_prot, k, 2, 1);

        Vv.Exec(Procedure("Insert") << AnsiToUtf8
            ("\nВне конкурса на платной основе\n"));
        Protokol_FIO(4, dat_prot, k, 3, 1);

        Vv.Exec(Procedure("Insert") << AnsiToUtf8
            ("\nБез экзаменов на платной основе\n"));
        Protokol_FIO(4, dat_prot, k, 4, 1);

        Vv.Exec(Procedure("Insert") << AnsiToUtf8
            ("\nГраждане иностранных государств на платной основе\n"));
        Protokol_FIO(4, dat_prot, k, 5, 1);
    }

    Vv.Exec (
        Procedure ("Insert")
            << AnsiToUtf8 (
                "\nПредседатель                                          "  \
                "                                     "                     \
                "С.Б.Репкин\n\nОтветственный секретарь"                     \
                "                                                      "    +
                    IOF                                                     +
                "\n"
            )
        );
    // ---
    AnsiString s_tmp1 = DateTimePicker1 -> Date;

    Vv.Exec (
        Procedure ("FileSaveAs")
            <<
                PathTo::OUTPUT_DOCUMENTS_SLASH  +
            "Протокол "                         +
                s_tmp1                          +
            " №"                                +
                AnsiString (Edit1 -> Text)      +
           ".doc"
    );

    Vv.Exec (
        Procedure ("AppShow")
    );

    Vv.Clear ();
}

// ---------------------------------------------------------------------------
bool __fastcall TDlg_ProtokolForm::Protokol_FIO(int f, TDateTime dat_p, int v,
    int k, int pr)
{ // f - факультет, dat_p - дата анализа, v - дневное/заочное, pr - бюджет/за оплату
    DMStat->QProtokol->Close();
    DMStat->QProtokol->ParamByName("N_FAC")->AsInteger = f;
    DMStat->QProtokol->ParamByName("DATA")->AsDateTime = dat_p;
    DMStat->QProtokol->ParamByName("VID_EDU")->AsInteger = v;
    DMStat->QProtokol->ParamByName("KONK")->AsInteger = k;
    DMStat->QProtokol->ParamByName("PRICE")->AsInteger = pr;
    DMStat->QProtokol->Open();
    int col = DMStat->QProtokol->RecordCount;

    if (!col)
        return false;
    AnsiString priv = ""; // привелегии

    for (int i = 0; i < col; i++) { // i цикл по количеству

        priv = "";
        if (DMStat->QProtokolOUT_VK->Value != "" && k != 3)
            priv = " (вк) "; // если конкурс не вне конкурса, но есть привелегия
        if (DMStat->QProtokolOUT_WITHOUT->Value != "" && k != 4)
            priv += "(без экз)";
        // если конкурс не без экзаменов, но есть привелегия
        Vv.Exec(Procedure("Insert") << DMStat->QProtokolOUT_FAM->Value + " " +
            DMStat->QProtokolOUT_NAME->Value.SetLength(1) + ". " +
            DMStat->QProtokolOUT_OTCH->Value.SetLength(1) + "." + priv + "\n");
        DMStat->QProtokol->Next();
    } // i цикл по количеству

    return true;

}

// ----------------------------------------------------------------------------
void __fastcall TDlg_ProtokolForm::FormActivate(TObject *Sender) {
    DateTimePicker1->Date = cur_d.CurrentDate();
}
// ---------------------------------------------------------------------------
void __fastcall TDlg_ProtokolForm::DateTimePicker1Change(TObject *Sender)
{
  DateTimePicker1->Time = StrToTime("00:00");
}
//---------------------------------------------------------------------------

