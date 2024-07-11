#include <vcl.h>
#pragma hdrstop


#include <comobj.hpp>


#include "AbituraLogDlg.h"
#include "AbiturUnit.h"
#include "ApellUnit.h"
#include "Dlg_ProtokolUnit.h"
#include "DMStatUnit.h"
#include "DMUnit.h"
#include "DMVedUnit.h"
#include "Dop_ResultUnit.h"
#include "ExamenSpecUnit.h"
#include "ExamenUnit.h"
#include "Func.h"
#include "Group_FacUnit.h"
#include "LETTERDUALLIST.h"
#include "MainUnit.h"
#include "PassDlgUnit.h"
#include "PersonalDocUnit.h"
#include "Resuilt_ExamUnit.h"
#include "Sertificat_ResultUnit.h"
#include "Spisoc_GroupUnit.h"
#include "SpravUnit.h"
#include "Stat_Result_examUnit.h"
#include "Undo_SpravkaUnit.h"


#pragma package (smart_init)
// #pragma link     "RXCtrls"
#pragma resource "*.dfm"



TMainForm  * MainForm;


AnsiString * mas_pr;                                                            // массив предметов для сводных ведомостей

AnsiString   S1,                                                                // переменные для формирования строки привилегий S1-1 колонка  ,
             S2,                                                                // S2-последняя колонка
             S3;                                                                // S3-разряд

int        * mas_all;                                                           // массив всех абитуриентов по специализации дошедших до зачисления
int        * mas_spec_str[2];                                                   // массив для хранения номера специальности и строки,в которой она находится
int        * nom_pr;                                                            // массив для занесения номеров предметов

int          col_rec,
             konk,                                                              // (competitionType) для определения конкурса
             nom_row,                                                           // (rowCounter) счетчик строк
             rec_q_all,                                                         // (amountItemsInAllArray) переменная для определения кол-ва элементов в массиве all
             spec;                                                              // (specializationCode) определение номера специализации

TFDQuery   * qq;                                                                // переменная для определения Query

Variant      ExApp1,                                                            // переменные для Excel
             ExcelApplication,
             startMerging,
             endMerging,
             selectedRange,
             Sheet,
             V;                                                                 // для Lookup



__fastcall TMainForm::TMainForm (TComponent * Owner)
    : TForm (Owner)
{
    #ifdef TEST_MAIN_UNIT
    AnsiString err_access_denied =
        KindOfSportCode::TOURISM_HOSPITALITY
        /*
        " SELECT"                     \
        "     nomer_ab,"              \
        "     fam,"                   \
        "     name,"                  \
        "     otch,"                  \
        "     address_before"         \
        " FROM"                       \
        "     abitura"                \
        " WHERE"                      \
        "         n_fac   = :n_fac"   \
        "     AND"                    \
        "         price   = "       + static_cast <AnsiString> (0)    +
        "     AND"                    \
        "         vid_edu = "       + static_cast <AnsiString> (0)    +
        "     AND"                    \
        "         status  = 5"        \
        " ORDER BY"                   \
        "     fam,"                   \
        "     name,"                  \
        "     otch"//;
        */
            //DocumentFile::PROTOCOL::admitted
            /*
            + "\n\n" +
            DocumentFile::PROTOCOL::daily
            + "\n\n" +
            DocumentFile::PROTOCOL::exam
            + "\n\n" +
            DocumentFile::PROTOCOL::GIRLS_TESTS
            + "\n\n" +
            DocumentFile::REGISTRY::BOOK
            + "\n\n" +
            DocumentFile::REPORT::FORM_1
            + "\n\n" +
            DocumentFile::REPORT::FORM_2
            + "\n\n" +
            DocumentFile::REPORT::SUBMITTED
            + "\n\n" +
            DocumentFile::STATISTIC::cert_result_hundred
            + "\n\n" +
            DocumentFile::STATISTIC::cert_result_ten
            + "\n\n" +
            DocumentFile::STATISTIC::exam_result
            + "\n\n" +
            DocumentFile::STATISTIC::ADMISSION_PROGRESS
            + "\n\n" +
            DocumentFile::STATISTIC::CONTEST
            + "\n\n" +
            DocumentName::SUMMARY_LIST::ENTRANCE_EXAMS
            */
        ;

        //switch (static_cast <Subject> (subject))
        //{
        //    case Subject::RUS:
        //        //return
        //            err_access_denied = "Русский язык";
        //        break;
        //    case Subject::BEL:
        //        //return
        //            err_access_denied = "Белорусский язык";
        //        break;
        //    default:
        //        //return
        //            err_access_denied = DM -> QSertificat_ex_listTEXT_PREDMET -> Value;
        //}
    ShowMessage (
        //"Неверное имя пользователя " \
        //"или пароль "
        err_access_denied
    );
    #endif
}



void __fastcall TMainForm::alignHVCells (
        int startColumn,
        int endColumn,
        int row,
        int alignHType,
        int alignVType
    )
{
    startMerging =
        SelectCell (
            startColumn,
            row
        );
    endMerging =
        SelectCell (
            endColumn,
            row
        );
    selectedRange =
        Range (
            Sheet,
            startMerging,
            endMerging
        );

    HorizontalAlign (
        selectedRange,
        alignHType
    );
    VerticalAlign (
        selectedRange,
        alignVType
    );
}


void __fastcall TMainForm::AllCount_spec (                                      // общего количества абитуриентов по специализации по плану
        int indexNumber
    )
{
    int column;


    if (indexNumber)                                                            // TODO: Add check: N bigger than ZERO!!!
        column = 1;
    else
        column = 0;

    if (DM -> QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value != 0)
    {
        spec =                                                                  // номер направления специальности
            DM -> QPlan_Priem_Konk_All_ParamN_SPECIALIZ -> Value;

        CellValue (                                                             // вывод полного названия направления специальности
            DM -> QPlan_Priem_Konk_All_ParamSPECIALIZ2 -> Value,
            column,
            nom_row
        );
        CellValue (                                                             // вывод общего количества мест по специализации по плану
            DM -> QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value,
            column + 1,
            nom_row
        );
    }
}
void __fastcall TMainForm::CellValue_Ball (                                     // Занесение всех оценок по эkзаменам для одного абитуриента
        int col_pred,
        int nom_stroka
    )
{
    for ( int i =  1;
              i <= col_pred;
              ++i
        )
    {
        Variant Res_look =
            DM -> QResult_Exam ->
                Lookup (
                    "NOMER_AB;N_PREDMET",
                    VarArrayOf (
                        OPENARRAY (
                            Variant,
                            (
                                DM -> QSpisoc_GroupNOMER_AB -> Value,
                                nom_pr[i - 1]
                            )
                        )
                    ),
                    "BALL"
                );


        if ( ! Res_look.IsNull ())
        {
            if (    nom_fac                             == 1
                 || nom_fac                             == 2
                 || nom_fac                             == 3
                 || nom_fac                             == 4
                 && DM -> QSpisoc_GroupKONKURS -> Value == 3
               )
            {
                Variant Ce1 =
                    SelectCell (
                        4 + i,
                        nom_stroka
                    );
                SheetFormat (
                    Ce1,
                    "0,0"                                                       // 0.0 в самом Excel пишет такой формат
                );
            }

            CellValue (
                Res_look,
                4 + i,
                nom_stroka
            );
        }

        BorderCell (
            4 + i,
            nom_stroka,
            1,
            2
        );
    }
}
void __fastcall TMainForm::Cicle_ball (
        int edu,
        int konk_place,
        int price
    )
{
    int cel_kol;                                                                // кол-во целевиков по плану
    int c;
    int q;

    for ( int i =  1;                                                           // 'ПЛАН ПРИЕМА' статистика по сумме баллов
              i <= col_rec;
              ++i
        )
    {
        if (DM -> QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value != 0)
        {
            AllCount_spec (i);                                                  // плановое количество абитуриентов (по специализации из плана)

            if (    konk_place == 1
                 && (    nom_fac == 1
                      || nom_fac == 2
                    )
               )
                CellValue (                                                     // сокращёнка СИиЕ и МВС общее название направления специальности
                    "Спортивно-педагогическая деятельность "        \
                    "(тренерская работа с указанием вида спорта)",
                    1,
                    nom_row
                );


            if (    konk_place == 1
                 && konk_place == 2
                 && nom_fac    == 3
               )
                CellValue (                                                     // сокращёнка ОФКиТ общее название направления специальности
                    "Физическая культура (дошкольников)",
                    1,
                    nom_row
                );


            if (    konk_place == 1
                 && nom_fac    == 4
               )
                CellValue (                                                     // для сокращёнки ОФКиТ общее название направления специальности
                    "Туризм и гостеприимство",
                    1,
                    nom_row
                );


            if (konk_place == 0)                                                // konk_place - конкурс в плане
                konk = 0;                                                       // для поступающих на 1-ый курс (t_abitura.konkurs)
            else
                konk = 2;                                                       // для поступающих на 2-ой курс (t_abitura.konkurs)


            if (konk_place == 0)                                                // полный срок
            {
                DM -> Stat3hAll1Qr -> Close ();
                DM -> Stat3hAll1Qr ->
                    ParamByName ("n_fac")       -> AsSmallInt = nom_fac;
                DM -> Stat3hAll1Qr ->
                    ParamByName ("vid_edu")     -> AsSmallInt = edu;
                DM -> Stat3hAll1Qr ->
                    ParamByName ("price")       -> AsSmallInt = price;
                DM -> Stat3hAll1Qr ->
                    ParamByName ("n_specializ") -> AsSmallInt = spec;
                DM -> Stat3hAll1Qr -> Open ();


                while ( ! DM -> Stat3hAll1Qr -> Eof)                            // Количество поданных
                {
                    switch (DM -> Stat3hAll1QrKONKURS -> Value)
                    {
                        case 0:                                                 // общий
                                c = DM -> Stat3hAll1QrCOUNT -> Value;

                                if (DM -> Stat3hAll1QrCOUNT -> Value)
                                    CellValue (
                                        c,
                                        8,
                                        nom_row
                                    );
                            break;
                        case 1:                                                 // БВИ
                                c = DM -> Stat3hAll1QrCOUNT -> Value;

                                if (DM -> Stat3hAll1QrCOUNT -> Value)
                                    CellValue (
                                        c,
                                        6,
                                        nom_row
                                    );
                            break;
                        case 2:                                                 // ВК
                                c = DM -> Stat3hAll1QrCOUNT -> Value;

                                if (DM -> Stat3hAll1QrCOUNT -> Value)
                                    CellValue (
                                        c,
                                        7,
                                        nom_row
                                    );
                            break;
                        case 3:                                                 // ЦК
                                c = DM -> Stat3hAll1QrCOUNT -> Value;

                                if (DM -> Stat3hAll1QrCOUNT -> Value)
                                    CellValue (
                                        c,
                                        5,
                                        nom_row
                                    );
                            break;
                    }

                    DM -> Stat3hAll1Qr -> Next ();
                }

                DM -> Stat3hAll1Qr -> Close ();
            }
            else                                                                // сокращённый
            {
                if (nom_fac != 1)                                               // для не СИиЕ
                {
                    DM -> Stat3hAll2Qr -> Close ();
                    DM -> Stat3hAll2Qr ->
                        ParamByName ("n_fac")   -> AsSmallInt = nom_fac;
                    DM -> Stat3hAll2Qr ->
                        ParamByName ("vid_edu") -> AsSmallInt = edu;
                    DM -> Stat3hAll2Qr ->
                        ParamByName ("price")   -> AsSmallInt = price;
                    DM -> Stat3hAll2Qr -> Open ();


                    while (!DM -> Stat3hAll2Qr -> Eof)
                    {
                        switch (DM -> Stat3hAll2QrKONKURS -> Value)
                        {
                            case 0:                                             // общий
                                    q = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (DM -> Stat3hAll2QrCOUNT -> Value)
                                        CellValue (
                                            q,
                                            8,
                                            nom_row
                                        );
                                break;
                            case 1:                                             // БВИ
                                    q = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (DM -> Stat3hAll2QrCOUNT -> Value)
                                        CellValue (
                                            q,
                                            6,
                                            nom_row
                                        );
                                break;
                            case 2:                                             // ВК
                                    q = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (DM -> Stat3hAll2QrCOUNT -> Value)
                                        CellValue (
                                            q,
                                            7,
                                            nom_row
                                        );
                                break;
                            case 3:                                             // ЦК
                                    q = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (DM -> Stat3hAll2QrCOUNT -> Value)
                                        CellValue (
                                            q,
                                            5,
                                            nom_row
                                        );
                                break;
                        }

                        DM -> Stat3hAll2Qr -> Next ();
                    }

                    DM -> Stat3hAll2Qr -> Close ();
                }
                else                                                            // в СИиЕ сокращёнка + МВС
                {
                    int  s1 = 0,
                         s2 = 0,
                         s3 = 0,
                         s4 = 0;


                    DM -> Stat3hAll2Qr -> Close ();
                    DM -> Stat3hAll2Qr ->
                        ParamByName ("n_fac")   -> AsSmallInt = 1;
                    DM -> Stat3hAll2Qr ->
                        ParamByName ("vid_edu") -> AsSmallInt = edu;
                    DM -> Stat3hAll2Qr ->
                        ParamByName ("price")   -> AsSmallInt = price;
                    DM -> Stat3hAll2Qr -> Open ();


                    while (!DM -> Stat3hAll2Qr -> Eof)
                    {
                        switch (DM -> Stat3hAll2QrKONKURS -> Value)
                        {
                            case 0:                                             // общий
                                    s1 = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s1)
                                        CellValue (
                                            s1,
                                            8,
                                            nom_row
                                        );
                                break;
                            case 1:                                             // БВИ
                                    s2 = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s2)
                                        CellValue (
                                            s2,
                                            6,
                                            nom_row
                                        );
                                break;
                            case 2:                                             // ВК
                                    s3 = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s3)
                                        CellValue (
                                            s3,
                                            7,
                                            nom_row
                                        );
                                break;
                            case 3:                                             // ЦК
                                    s4 = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s4)
                                        CellValue (
                                            s4,
                                            5,
                                            nom_row
                                        );
                                break;
                        }

                        DM -> Stat3hAll2Qr -> Next ();
                    }


                    DM -> Stat3hAll2Qr -> Close ();
                    DM -> Stat3hAll2Qr ->
                        ParamByName ("n_fac")   -> AsSmallInt = 2;
                    DM -> Stat3hAll2Qr ->
                        ParamByName ("vid_edu") -> AsSmallInt = edu;
                    DM -> Stat3hAll2Qr ->
                        ParamByName ("price")   -> AsSmallInt = price;
                    DM -> Stat3hAll2Qr -> Open ();


                    while (!DM -> Stat3hAll2Qr -> Eof)
                    {
                        switch (DM -> Stat3hAll2QrKONKURS -> Value)
                        {
                            case 0:                                             // общий
                                    s1 =
                                    s1 + DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s1)
                                        CellValue (
                                            s1,
                                            8,
                                            nom_row
                                        );
                                break;
                            case 1:                                             // БВИ
                                    s2 =
                                    s2 + DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s2)
                                        CellValue (
                                            s2,
                                            6,
                                            nom_row
                                        );
                                break;
                            case 2:                                             // ВК
                                    s3 =
                                    s3 + DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s3)
                                        CellValue (
                                            s3,
                                            7,
                                            nom_row
                                        );
                                break;
                            case 3:                                             // ЦК
                                    s4 =
                                    s4 + DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s4)
                                        CellValue (
                                            s4,
                                            5,
                                            nom_row
                                        );
                                break;
                        }
                        DM -> Stat3hAll2Qr -> Next ();
                    }
                    DM -> Stat3hAll2Qr -> Close ();
                }
            }


            DM -> QCK_Kol_Plan -> Close ();                                     // План целевиков
            DM -> QCK_Kol_Plan ->
                ParamByName ("N_SPECIALIZ") -> AsInteger = spec;
            DM -> QCK_Kol_Plan -> Open ();


            if (    edu        == 0                                             // Занесение планового числа целевиков
                 && konk_place == 0                                             // Только для дневного, 1-ый курс,бюджет
                 && price      == 0
               )
            {
                cel_kol = DM -> QCK_Kol_PlanKOL_PLACE -> Value;                 // Запрос на количество целевиков по плану

                if (cel_kol)
                    CellValue (
                        cel_kol,
                        3,
                        nom_row
                    );
            }


            Run_ProcBall (                                                      // Занесение распределения заявлений по баллам
                nom_fac,
                edu,
                konk,
                price,
                9,
                nom_row
            );


            CellFormula (                                                       // Расчёт общего числа подавших заявления по специализации (=СУММ(E1:H1))
                "=СУММ(E"                   +
                    AnsiString (nom_row)    +
                ":H"                        +
                    AnsiString (nom_row),
                4,
                nom_row
            );


            for ( int j = 1;                                                    // Обрамление ячеек строки
                      j < 47;
                      ++j
                )
                BorderCell (
                    j,
                    nom_row,
                    1,
                    2
                );

            ++nom_row;
        }
        DM -> QPlan_Priem_Konk_All_Param -> Next ();
    }
    DM -> QStatistic_Every_Day_Ball_Price -> Close ();
    DM -> QCK_Kol_Plan                    -> Close ();
}
void __fastcall TMainForm::Cicle_ball_konk (                                    // 'ПЛАН ПРИЕМА' статистика по конкурсу
        int edu,
        int konk_place,
        int price
    )
{
    int cel_kol;                                                                // кол-во целевиков по плану

    for ( int i =  1;                                                           // статистики по баллам из 'план приёма'
              i <= col_rec;
              ++i
        )
    {
        AllCount_spec (i);                                                      // Плановое количество абитуриентов по специализации

        if (    konk_place == 1
             && (    nom_fac == 1
                  || nom_fac == 2
                )
           )
            CellValue (                                                         // для сокращёнки СИиЕ и МВС общее название направления специальности
                "Спортивно-педагогическая деятельность "    \
                "(тренерская работа с указанием вида спорта)",
                1,
                nom_row
            );


        if (konk_place == 0)                                                    // конкурс в плане
            konk = 0;                                                           // Поступающие на 1-ый курс (из abitura.konkurs)
        else
            konk = 2;                                                           // Поступающие на 2-ой курс (из abitura.konkurs)


        DM -> QStatistic_Every_Day_Ball_Price -> Close ();                      // Количество поданных
        DM -> QStatistic_Every_Day_Ball_Price ->
            ParamByName ("N_FAC")   -> AsInteger = nom_fac;
        DM -> QStatistic_Every_Day_Ball_Price ->
            ParamByName ("VID_EDU") -> AsInteger = edu;
        DM -> QStatistic_Every_Day_Ball_Price ->
            ParamByName ("PRICE")   -> AsInteger = price;
        DM -> QStatistic_Every_Day_Ball_Price ->
            ParamByName ("N_SP")    -> AsInteger = spec;
        DM -> QStatistic_Every_Day_Ball_Price -> Open ();


        DM -> QCK_Kol_Plan -> Close ();                                         // План целевиков  __declspec (uuid ("{83CCF233-FF44-4CFC-8525-6F6028460C85}"))
        DM -> QCK_Kol_Plan ->
            ParamByName ("N_SPECIALIZ") -> AsInteger = spec;
        DM -> QCK_Kol_Plan -> Open ();


        Run_ProcBall (                                                          // Занесение распределения заявлений по баллам
            nom_fac,
            edu,
            konk,
            price,
            9,
            nom_row
        );


        CellFormula (                                                           // Расчёт суммы по конкурсу для направления специализации (=СУММ(I1:AT1))
            "=СУММ(I"                   +
                AnsiString (nom_row)    +
            ":AT"                       +
                AnsiString (nom_row),
            8,
            nom_row
        );


        if (    edu        == 0                                                 // Целевики только дневное
             && konk_place == 0                                                 // Целевики только 1-ый курс
             && price      == 0                                                 // Целевики только бюджет
           )
        {
            cel_kol =                                                           // Запрос на количество целевиков по плану
                DM -> QCK_Kol_PlanKOL_PLACE -> Value;

            if (cel_kol)
                CellValue (
                    cel_kol,
                    3,
                    nom_row
                );
        }


        if (konk == 0)                                                          // Кол-во подавших заявления на 1-ый курс
        {
            for ( int j = 0;                                                    // Проход по специализации
                      j < DM -> QStatistic_Every_Day_Ball_Price -> RecordCount;
                      ++j
                )
            {
                int BVI     = 0,
                    konk_ab =
                        DM -> QStatistic_Every_Day_Ball_PriceKONKURS -> Value;

                switch (konk_ab)                                                // KONKURS
                {
                    case 1:
                            cel_kol =
                                DM -> QStatistic_Every_Day_Ball_PriceCOUNT ->
                                    Value;
                            CellValue (                                         // ЦК
                                cel_kol,
                                5,
                                nom_row
                            );
                        break;
                    // case 2:
                    //             CellValue (                                     // на 2 курс
                    //                 DM -> QStatistic_Every_Day_BallCOUNT ->
                    //                     Value,
                    //                 13,
                    //                 nomer_stroki
                    //             );
                    //     break;
                    case 3:
                            cel_kol =
                                DM -> QStatistic_Every_Day_Ball_PriceCOUNT ->
                                    Value;
                            CellValue (                                         // вне конкурса
                                cel_kol,
                                7,
                                nom_row
                            );
                        break;
                    case 4:
                            cel_kol =
                                DM -> QStatistic_Every_Day_Ball_PriceCOUNT ->
                                    Value;
                            CellValue (                                         // без экзаменов
                                cel_kol,
                                6,
                                nom_row
                            );

                            BVI =
                                DM -> QStatistic_Every_Day_Ball_PriceCOUNT ->
                                    Value;
                        break;
                }


                DMVed -> QKonkPlus -> Close ();                                 // выдержали ВИ
                DMVed -> QKonkPlus ->
                    ParamByName ("vid_edu") -> AsInteger = edu;
                DMVed -> QKonkPlus ->
                    ParamByName ("price")   -> AsInteger = price;
                DMVed -> QKonkPlus ->
                    ParamByName ("n_spec")  -> AsInteger = spec;
                DMVed -> QKonkPlus -> Open ();


                int InPlus =
                    DMVed -> QKonkPlusCOUNT -> Value;

                CellValue (
                    InPlus,
                    47,
                    nom_row
                );

                DMVed -> QKonkPlus -> Close ();


                AnsiString
                    s_tmp1;
                float
                    konk_stat;                                                  // конкурс
                int
                    AllPlan   =                                                 // всего по плану приёма
                        DM -> QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value;


                if (AllPlan - BVI > 0)
                {
                    konk_stat = (InPlus - BVI) / (AllPlan - BVI);

                    s_tmp1 =
                        FloatToStrF (
                            konk_stat,
                            ffFixed,
                            4,
                            2
                        );
                    CellValue (
                        s_tmp1,
                        48,
                        nom_row
                    );
                }
                else
                {
                    konk_stat = BVI / AllPlan;

                    s_tmp1 =
                        "только без ВИ\n" +
                        FloatToStrF (
                            konk_stat,
                            ffFixed,
                            4,
                            2
                        );
                    CellValue (
                        s_tmp1,
                        48,
                        nom_row
                    );
                }
                DM -> QStatistic_Every_Day_Ball_Price -> Next ();
            }
        }
        else                                                                    // Для поступающих на 2-ый курс
        {
            int BVI         = 0,
                sum_v_k,
                sum_without;

            if (nom_fac != 1)                                                   // Для МВС,ОФКиТ и ИТ
            {
                DM -> StoredProcStatistic_Konk ->
                    ParamByName ("IN_FAC")     -> AsInteger = nom_fac;
                DM -> StoredProcStatistic_Konk ->
                    ParamByName ("IN_VID_EDU") -> AsInteger = edu;
                DM -> StoredProcStatistic_Konk ->
                    ParamByName ("IN_KONKURS") -> AsInteger = konk;
                DM -> StoredProcStatistic_Konk ->
                    ParamByName ("IN_PRICE")   -> AsInteger = price;

                DM -> StoredProcStatistic_Konk -> Prepare ();
                DM -> StoredProcStatistic_Konk -> ExecProc ();

                sum_without =
                    DM -> StoredProcStatistic_Konk ->
                        Params -> Items[4] -> AsInteger;

                sum_v_k =
                    DM -> StoredProcStatistic_Konk ->
                        Params -> Items[5] -> AsInteger;

                if (sum_without)
                {
                    CellValue (                                                 // без экзаменов
                        sum_without,
                        6,
                        nom_row
                    );

                    BVI = sum_without;
                }

                if (sum_v_k)
                    CellValue (                                                 // вне конкурса
                        sum_v_k,
                        7,
                        nom_row
                    );


                DM -> StoredProcStatistic_Konk -> Unprepare ();
                DM -> StoredProcStatistic_Konk -> Close ();


                DMVed -> QKonkPlus2 -> Close ();                                // выдержали ВИ
                DMVed -> QKonkPlus2 ->
                    ParamByName ("vid_edu") -> AsInteger = edu;
                DMVed -> QKonkPlus2 ->
                    ParamByName ("price")   -> AsInteger = price;
                DMVed -> QKonkPlus2 ->
                    ParamByName ("n_fac")   -> AsInteger = nom_fac;
                DMVed -> QKonkPlus2 -> Open ();

                int InPlus = DMVed -> QKonkPlus2COUNT -> Value;

                CellValue (
                    InPlus,
                    47,
                    nom_row
                );

                DMVed -> QKonkPlus -> Close ();


                int AllPlan =                                                   // всего по плану приёма
                    DM -> QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value;


                AnsiString s_tmp1;
                float      konk_stat;                                           // конкурс

                if (AllPlan - BVI > 0)
                {
                    konk_stat = (InPlus - BVI) / (AllPlan - BVI);

                    s_tmp1 =
                        FloatToStrF (
                            konk_stat,
                            ffFixed,
                            4,
                            2
                        );
                    CellValue (
                        s_tmp1,
                        48,
                        nom_row
                    );
                }
                else
                {
                    konk_stat = BVI / AllPlan;

                    s_tmp1 =
                        "только без ВИ\n" +
                        FloatToStrF (
                            konk_stat,
                            ffFixed,
                            4,
                            2
                        );
                    CellValue (
                        s_tmp1,
                        48,
                        nom_row
                    );
                }
            }
            else                                                                // Для совместного СИиЕ и МВС
            {
                int BVI = 0;                                                    // Для СИиЕ

                DM -> StoredProcStatistic_Konk ->
                    ParamByName ("IN_FAC")     -> AsInteger = 1;
                DM -> StoredProcStatistic_Konk ->
                    ParamByName ("IN_VID_EDU") -> AsInteger = edu;
                DM -> StoredProcStatistic_Konk ->
                    ParamByName ("IN_KONKURS") -> AsInteger = konk;
                DM -> StoredProcStatistic_Konk ->
                    ParamByName ("IN_PRICE")   -> AsInteger = price;

                DM -> StoredProcStatistic_Konk -> Prepare ();
                DM -> StoredProcStatistic_Konk -> ExecProc ();

                sum_without =
                    DM -> StoredProcStatistic_Konk ->
                        Params -> Items[4] -> AsInteger;

                sum_v_k =
                    DM -> StoredProcStatistic_Konk ->
                        Params -> Items[5] -> AsInteger;

                DM -> StoredProcStatistic_Konk -> Unprepare ();
                DM -> StoredProcStatistic_Konk -> Close ();

                DM -> StoredProcStatistic_Konk ->                               // Добавляем МВС
                    ParamByName ("IN_FAC")     -> AsInteger = 2;
                DM -> StoredProcStatistic_Konk ->
                    ParamByName ("IN_VID_EDU") -> AsInteger = edu;
                DM -> StoredProcStatistic_Konk ->
                    ParamByName ("IN_KONKURS") -> AsInteger = konk;
                DM -> StoredProcStatistic_Konk ->
                    ParamByName ("IN_PRICE")   -> AsInteger = price;

                DM -> StoredProcStatistic_Konk -> Prepare ();
                DM -> StoredProcStatistic_Konk -> ExecProc ();

                sum_without +=
                    DM -> StoredProcStatistic_Konk ->
                        Params -> Items[4] -> AsInteger;

                sum_v_k +=
                    DM -> StoredProcStatistic_Konk ->
                        Params -> Items[5] -> AsInteger;

                if (sum_without)
                {
                    CellValue (                                                 // без экзаменов
                        sum_without,
                        6,
                        nom_row
                    );

                    BVI = sum_without;
                }

                if (sum_v_k)
                    CellValue (
                        sum_v_k,                                                // вне конкурса
                        7,
                        nom_row
                    );

                DM -> StoredProcStatistic_Konk -> Unprepare ();
                DM -> StoredProcStatistic_Konk -> Close ();


                int InPlus = 0;                                                 // ВЫДЕРЖАЛИ ВИ

                DMVed -> QKonkPlus2 -> Close ();
                DMVed -> QKonkPlus2 ->
                    ParamByName ("vid_edu") -> AsInteger = edu;
                DMVed -> QKonkPlus2 ->
                    ParamByName ("price")   -> AsInteger = price;
                DMVed -> QKonkPlus2 ->
                    ParamByName ("n_fac")   -> AsInteger = 1;
                DMVed -> QKonkPlus2 -> Open ();

                InPlus =
                    DMVed -> QKonkPlus2COUNT -> Value;

                DMVed -> QKonkPlus  -> Close ();


                DMVed -> QKonkPlus2 -> Close ();
                DMVed -> QKonkPlus2 ->
                    ParamByName ("vid_edu") -> AsInteger = edu;
                DMVed -> QKonkPlus2 ->
                    ParamByName ("price")   -> AsInteger = price;
                DMVed -> QKonkPlus2 ->
                    ParamByName ("n_fac")   -> AsInteger = 2;

                DMVed -> QKonkPlus2 -> Open ();

                InPlus +=
                    DMVed -> QKonkPlus2COUNT -> Value;

                CellValue (
                    InPlus,
                    47,
                    nom_row
                );

                DMVed -> QKonkPlus -> Close ();


                int   AllPlan =                                                 // всего по плану приёма
                    DM -> QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value;

                float konk_stat;                                                // конкурс

                AnsiString s_tmp1;


                if (AllPlan - BVI > 0)
                {
                    konk_stat = (InPlus - BVI) / (AllPlan - BVI);

                    s_tmp1 =
                        FloatToStrF (
                            konk_stat,
                            ffFixed,
                            4,
                            2
                        );
                    CellValue (
                        s_tmp1,
                        48,
                        nom_row
                    );
                }
                else
                {
                    konk_stat = BVI / AllPlan;

                    s_tmp1 =
                        "только без ВИ\n" +
                        FloatToStrF (
                            konk_stat,
                            ffFixed,
                            4,
                            2
                            );
                    CellValue (
                        s_tmp1,
                        48,
                        nom_row
                    );
                }
            }
        }


        CellFormula (                                                           // Расчёт общего числа подавших заявления по специализации (-СУММ(E1:H1))
            "=СУММ(E"                   +
                AnsiString (nom_row)    +
            ":H"                        +
                AnsiString (nom_row),
            4,
            nom_row
        );


        for ( int j = 1;                                                        // Обрамление ячеек строки
                  j < 52;
                  ++j
            )
            BorderCell (
                j,
                nom_row,
                1,
                2
            );

        DM -> QPlan_Priem_Konk_All_Param -> Next ();

        ++nom_row;
    }
    DM -> QStatistic_Every_Day_Ball_Price -> Close ();
    DM -> QCK_Kol_Plan                    -> Close ();
}
void __fastcall TMainForm::Cicle_Report (int edu)
{
    int val;

    for ( int i =  1;
              i <= col_rec;
              ++i
        )
    {
        AllCount_spec (i);                                                      // Запись общего количества абитуриентов по специализации


        DM -> QPlan_Priem_Konk -> Close ();                                     // Количество мест по каждому конкурсу
        DM -> QPlan_Priem_Konk ->
            ParamByName ("N_FAC")   -> AsInteger = nom_fac;
        DM -> QPlan_Priem_Konk ->
            ParamByName ("VID_EDU") -> AsInteger = edu;
        DM -> QPlan_Priem_Konk ->
            ParamByName ("N_SP")    -> AsInteger = spec;
        DM -> QPlan_Priem_Konk -> Open ();


        int kol_g_s = 0;                                                        // Общее кол-во мест города и села

        for ( int s = 0;                                                        // Проход по кол-ву мест выбранной специализации
                  s < DM -> QPlan_Priem_Konk -> RecordCount;
                  ++s
            )
        {
            switch (DM -> QPlan_Priem_KonkTEXT -> Value)                        // конкурс в KOL_PLACE
            {
                case 0:                                                         // город
                        if (DM -> QPlan_Priem_KonkKOL_PLACE -> Value)
                            kol_g_s +=
                                DM -> QPlan_Priem_KonkKOL_PLACE -> Value;

                        CellFormula (                                           // Пропорционально поданных заявлений на город (=D1-I1-J1)
                            "=D"                            +
                                AnsiString (nom_row)        +
                            "-I"                            +
                                AnsiString (nom_row)        +
                            "-J"                            +
                                AnsiString (nom_row),
                            8,
                            nom_row
                        );
                        CellFormula (                                           // (=F1-I2-J2)
                            "=F"                            +
                                AnsiString (nom_row)        +
                            "-I"                            +
                                AnsiString (nom_row + 1)    +
                            "-J"                            +
                                AnsiString (nom_row + 1),
                            8,
                            nom_row + 1
                        );
                    break;
                // case 1:                                                         // село
                //         kol_g_s +=
                //             DM -> QPlan_Priem_KonkKOL_PLACE -> Value;
                //     break;
                case 2:                                                         // ЦК
                        CellValue (
                            DM -> QPlan_Priem_KonkKOL_PLACE -> Value,
                            5,
                            nom_row
                        );
                    break;
                case 3:                                                         // платники
                        CellValue (
                            DM -> QPlan_Priem_KonkKOL_PLACE -> Value,
                            6,
                            nom_row
                        );
                        CellFormula (                                           // (=F1-I2-J2)
                            "=F"                            +
                                AnsiString (nom_row)        +
                            "-I"                            +
                                AnsiString (nom_row + 1)    +
                            "-J"                            +
                                AnsiString (nom_row + 1),
                            8,
                            nom_row + 1
                        );
                    break;
            }
            DM -> QPlan_Priem_Konk -> Next ();
        }


        if (kol_g_s != -1)                                                      // города + села
            CellValue (
                kol_g_s,
                4,
                nom_row
            );

        CellValue (
            "бюджет",
            7,
            nom_row
        );
        CellValue (
            "за оплату",
            7,
            nom_row + 1
        );


        if (spec == DM -> QStatistic_Every_DayN_SPECIALIZ -> Value)
        {
            while (spec == DM -> QStatistic_Every_DayN_SPECIALIZ -> Value)
            {
                    konk = DM -> QStatistic_Every_DayKONKURS -> Value;
                int p    = DM -> QStatistic_Every_DayPRICE   -> Value;          // форма оплаты

                switch (konk)
                {
                    case 0:                                                     // город (количество)
                            if (oplata_konkurs == 0)
                            {
                                if (!p)
                                {
                                    val =
                                        DM -> QStatistic_Every_DayCOUNT ->
                                            Value;

                                    if (val)
                                        CellValue (
                                            val,
                                            12,
                                            nom_row + p
                                        );

                                    CellFormula (                                   // (=L'1+p'/H'1+p')
                                        "=L"                            +
                                            AnsiString (nom_row + p)    +
                                        "/H"                            +
                                            AnsiString (nom_row + p),
                                        18,
                                        nom_row + p
                                    );
                                }
                                else
                                    CellValue (
                                        val,
                                        12,
                                        nom_row + p
                                    );
                            }
                            else
                            {
                                CellValue (
                                    val,
                                    12,
                                    nom_row + p
                                );
                                CellFormula (                                   // (=L'1+p'/H'1+p')
                                    "=L"                            +
                                        AnsiString (nom_row + p)    +
                                    "/H"                            +
                                        AnsiString (nom_row + p),
                                    18,
                                    nom_row + p
                                );
                            }
                        break;
                    case 1:                                                     // ЦК (количество)
                            CellValue (
                                DM -> QStatistic_Every_DayCOUNT -> Value,
                                13,
                                nom_row + p
                            );
                            CellFormula (                                       // конкурс  (=M'1+p'/E'1+p')
                                "=M"                            +
                                    AnsiString (nom_row + p)    +
                                "/E"                            +
                                    AnsiString (nom_row + p),
                                19,
                                nom_row + p
                            );
                        break;
                    case 2:                                                     // 2-3 курс (количество)
                            CellValue (
                                DM -> QStatistic_Every_DayCOUNT -> Value,
                                14,
                                nom_row + p
                            );
                        break;
                    case 3:                                                     // вне конкурса (количество)
                            CellValue (
                                DM -> QStatistic_Every_DayCOUNT -> Value,
                                9,
                                nom_row + p
                            );
                            CellValue (
                                DM -> QStatistic_Every_DayCOUNT -> Value,
                                15,
                                nom_row + p
                            );
                        break;
                    case 4:                                                     // без экзаменов (количество)
                            CellValue (
                                DM -> QStatistic_Every_DayCOUNT -> Value,
                                10,
                                nom_row + p
                            );
                            CellValue (
                                DM -> QStatistic_Every_DayCOUNT -> Value,
                                16,
                                nom_row + p
                            );
                        break;
                    case 5:                                                     // иностранцы (количество)
                            CellValue (
                                DM -> QStatistic_Every_DayCOUNT -> Value,
                                17,
                                nom_row + p
                            );
                        break;
                }


                if (!DM -> QStatistic_Every_Day -> Eof)
                    DM -> QStatistic_Every_Day -> Next ();
                else
                    break;
            }


            CellFormula (                                                       // Всего поданных заявлений  (=СУММ(L1:Q1))
                "=СУММ(L"                       +
                    AnsiString (nom_row)        +
                ":Q"                            +
                    AnsiString (nom_row)        +
                ")",
                11,
                nom_row
            );
            CellFormula (                                                       // Общий конкурс на бюджет  (=СУММ(L2:Q2))
                "=СУММ(L"                       +
                    AnsiString (nom_row + 1)    +
                ":Q"                            +
                    AnsiString (nom_row + 1)    +
                ")",
                11,
                nom_row + 1
            );
            CellFormula (                                                       // Общий конкурс на бюджет  (=(K1-N1-Q1)/(D1+E1))
                "=(K"                           +
                    AnsiString (nom_row)        +
                "-N"                            +
                    AnsiString (nom_row)        +
                "-Q"                            +
                    AnsiString (nom_row)        +
                ")/(D"                          +
                    AnsiString (nom_row)        +
                "+E"                            +
                    AnsiString (nom_row)        +
                ")",
                18,
                nom_row
            );
            CellFormula (                                                       // Общий конкурс платники (=(K2-N2-Q2)/(F1))
                "=(K"                           +
                    AnsiString (nom_row + 1)    +
                "-N"                            +
                    AnsiString (nom_row + 1)    +
                "-Q"                            +
                    AnsiString (nom_row + 1)    +
                ")/(F"                          +
                    AnsiString (nom_row)        +
                ")",
                18,
                nom_row + 1
            );
        }

        DM -> QPlan_Priem_All -> Next ();


        for ( int i =  1;
                  i <= 6;
                  ++i
            )
        {
            if (i == 2)
            {
                MergeCell (                                                     // Объединение ячеек
                    i,                                                          // int col_nom1
                    i,                                                          // int col_nom2
                    nom_row,                                                    // int row_nom1
                    nom_row + 1,                                                // int row_nom2
                    2                                                           // int align
                );
                // AutoFitRow (                                                    // SET ROW HEIGHT AND WIDTH
                //     Sheet,
                //     nom_row
                // );
            }
            else
                MergeCell (
                    i,
                    i,
                    nom_row,
                    nom_row + 1,
                    3
                );
        }
        nom_row += 2;
    }
}
void __fastcall TMainForm::Cicle_Report_special (int edu)
{
    int sum,
        val;

    for ( int i = 1;
              i <= col_rec;
              ++i
        )
    {
        spec = DM -> QPlan_Priem_All_SpecialN_SPEC -> Value;                    // общее количество абитуриентов по направлению


        DM -> QPlan_Priem_Konk_Special -> Close ();
        DM -> QPlan_Priem_Konk_Special ->
            ParamByName ("vid_edu") -> AsInteger = edu;
        DM -> QPlan_Priem_Konk_Special ->
            ParamByName ("n_sp")    -> AsInteger = spec;
        DM -> QPlan_Priem_Konk_Special -> Open ();                              // получаем кол-во мест по каждому конкурсу


        DM -> QStatistic_Every_Day_Special -> Close ();
        DM -> QStatistic_Every_Day_Special ->
            ParamByName ("vid_edu") -> AsInteger = edu;
        DM -> QStatistic_Every_Day_Special ->
            ParamByName ("n_spec")  -> AsInteger = spec;
        DM -> QStatistic_Every_Day_Special -> Open ();


        CellValue (
                AnsiString (i)  +
            ".",
            1,
            nom_row
        );

        if (DM -> QPlan_Priem_Konk_SpecialTEXT -> Value != 0)
            CellValue (                                                             // полное название специальности
                DM -> QPlan_Priem_All_SpecialSPEC -> Value,
                2,
                nom_row
            );
        else
            CellValue (                                                             // полное название специальности
                DeleteAfterDatabaseChange::getNcrb2022QualificationByNSpec (
                    DM -> QPlan_Priem_All_SpecialN_SPEC -> Value
                ),
                2,
                nom_row
            );


        int sum =
            DM -> QPlan_Priem_All_Special ->
                Lookup (
                    "n_spec",
                    spec,
                    "sum1"
            );

        if (sum > 0)
            CellValue (
                sum,
                3,
                nom_row
            );


        int kol_g_s = 0;                                                        // переменная для суммирования мест города и села

        for ( int s = 0;                                                        // Проход по кол-ву мест выбранной специализации
                  s < DM -> QPlan_Priem_Konk_Special -> RecordCount;
                  ++s
            )
        {
            switch (DM -> QPlan_Priem_Konk_SpecialTEXT -> Value)                // конкурс в KOL_PLACE (СТАЛО: 0 - полный срок, 1 - сокращёнка)
            {
                case 0:                                                         // город
                        if (DM -> QPlan_Priem_Konk_SpecialSUM1 -> Value)
                            kol_g_s +=
                                DM -> QPlan_Priem_Konk_SpecialSUM1 -> Value;

                        CellFormula (                                           // Пропорционально поданных заявлений на город  (=D1-I1-J1)
                            "=D"                            +
                                AnsiString (nom_row)        +
                            "-I"                            +
                                AnsiString (nom_row)        +
                            "-J"                            +
                                AnsiString (nom_row),
                            8,
                            nom_row
                        );
                        CellFormula (                                           // (=F1-I2-J2)
                            "=F"                            +
                                AnsiString (nom_row)        +
                            "-I"                            +
                                AnsiString (++nom_row)      +
                            "-J"                            +
                                AnsiString (++nom_row),
                            8,
                            ++nom_row
                        );
                    break;
                // case 1:                                                         // село
                //         kol_g_s +=
                //             DM -> QPlan_Priem_Konk_SpecialSUM1 -> Value;
                //     break;
                case 2:                                                         // ЦК
                        sum =
                            DM -> QPlan_Priem_Konk_SpecialSUM1 -> Value;

                        CellValue (
                            sum,
                            5,
                            nom_row
                        );
                    break;
                case 3:                                                         // за оплату
                        sum =
                            DM -> QPlan_Priem_Konk_SpecialSUM1 -> Value;

                        CellValue (
                            sum,
                            6,
                            nom_row
                        );
                        CellFormula (                                           // (=F1-I2-J2)
                            "=F"                            +
                                AnsiString (nom_row)        +
                            "-I"                            +
                                AnsiString (++nom_row)      +
                            "-J"                            +
                                AnsiString (++nom_row),
                            8,
                            ++nom_row
                        );
                    break;
            }

            DM -> QPlan_Priem_Konk_Special -> Next ();
        }

        if (kol_g_s != -1)                                                      // города + села
            CellValue (
                kol_g_s,
                4,
                nom_row
            );

        CellValue (
            "бюджет",
            7,
            nom_row
        );
        CellValue (
            "за оплату",
            7,
            nom_row + 1
        );

        if (spec == DM -> QStatistic_Every_Day_SpecialN_SPEC -> Value)
        {
            while ( spec ==
                        DM -> QStatistic_Every_Day_SpecialN_SPEC -> Value
                  )
            {
                konk =
                    DM -> QStatistic_Every_Day_SpecialKONKURS -> Value;

                int p =                                                         // форма оплаты
                    DM -> QStatistic_Every_Day_SpecialPRICE   -> Value;

                switch (konk)
                {
                    case 0:                                                     // город (количество)
                            if (oplata_konkurs == 0)
                            {
                                if ( ! p)
                                {
                                    val =
                                        DM -> QStatistic_Every_Day_SpecialCOUNT ->
                                            Value;

                                    if (val)                                    // количество
                                        CellValue (
                                            val,
                                            12,
                                            nom_row + p
                                        );

                                    CellFormula (                               // конкурс город        (=M'1+p'/H'1+p')
                                        "=M"                            +
                                            AnsiString (nom_row + p)    +
                                        "/H"                            +
                                            AnsiString (nom_row + p),
                                        18,
                                        nom_row + p
                                    );
                                }
                                else                                            // общий конкурс
                                    CellValue (
                                        val,
                                        12,
                                        nom_row + p
                                    );
                            }
                            else
                            {
                                val =                                           // количество
                                    DM -> QStatistic_Every_Day_SpecialCOUNT ->
                                        Value;

                                if (val)
                                    CellValue (
                                        val,
                                        12,
                                        nom_row + p
                                    );

                                CellFormula (                                   // конкурс город        (=M'1+p'/H'1+p')
                                    "=M"                            +
                                        AnsiString (nom_row + p)    +
                                    "/H"                            +
                                        AnsiString (nom_row + p),
                                    18,
                                    nom_row + p
                                );
                            }
                        break;
                    case 1:                                                     // ЦК (количество)
                            val =
                                DM -> QStatistic_Every_Day_SpecialCOUNT ->
                                    Value;

                            if (val)
                                CellValue (
                                    val,
                                    13,
                                    nom_row + p
                                );

                            CellFormula (                                       // конкурс  (=O'1+p'/E'1+p')
                                "=O"                            +
                                    AnsiString (nom_row + p)    +
                                "/E"                            +
                                    AnsiString (nom_row + p),
                                19,
                                nom_row + p
                            );
                        break;
                    case 2:                                                     // 2-3 курс (кол-во)
                            CellValue (
                                val,
                                14,
                                nom_row + p
                            );
                        break;
                    case 3:                                                     // вне конкурса (количество)
                            CellValue (
                                val,
                                9,
                                nom_row + p
                            );
                            CellValue (
                                val,
                                15,
                                nom_row + p
                            );
                        break;
                    case 4:                                                     // без экзаменов (количество)
                            CellValue (
                                val,
                                10,
                                nom_row + p
                            );
                            CellValue (
                                DM -> QStatistic_Every_Day_SpecialCOUNT ->
                                    Value,
                                16,
                                nom_row + p
                            );
                        break;
                    case 5:                                                     // иностранцы
                            CellValue (
                                val,
                                17,
                                nom_row + p
                            );
                        break;
                }


                if (!DM -> QStatistic_Every_Day_Special -> Eof)
                    DM -> QStatistic_Every_Day_Special -> Next ();
                else
                    break;
            }


            CellFormula (                                                       // Всего поданных заявлений (=СУММ(L1:Q1))
                "=СУММ(L"                       +
                    AnsiString (nom_row)        +
                ":Q"                            +
                    AnsiString (nom_row)        +
                ")",
                11,
                nom_row
            );
            CellFormula (                                                       //                          (=СУММ(L2:Q2))
                "=СУММ(L"                       +
                    AnsiString (nom_row + 1)    +
                ":Q"                            +
                    AnsiString (nom_row + 1)    +
                ")",
                11,
                nom_row + 1
            );
            CellFormula (                                                       // Общий конкурс бюджет     (=(K1-N1-Q1)/(D1+E1))
                "=(K"                           +
                    AnsiString (nom_row)        +
                "-N"                            +
                    AnsiString (nom_row)        +
                "-Q"                            +
                    AnsiString (nom_row)        +
                ")/(D"                          +
                    AnsiString (nom_row)        +
                "+E"                            +
                    AnsiString (nom_row)        +
                ")",
                18,
                nom_row
            );
            CellFormula (                                                       // Общий конкурс платники   (=(K2-N2-Q2)/(F1))
                "=(K"                           +
                    AnsiString (nom_row + 1)    +
                "-N"                            +
                    AnsiString (nom_row + 1)    +
                "-Q"                            +
                    AnsiString (nom_row + 1)    +
                ")/(F"                          +
                    AnsiString (nom_row)        +
                ")",
                18,
                nom_row + 1
            );
        }


        DM -> QPlan_Priem_All_Special -> Next ();


        for ( int i =  1;
                  i <= 6;
                  ++i
            )
        {
            if (i == 2)
            {
                MergeCell (                                                     // MERGE CELLS
                    i,                                                          // col_nom1
                    i,                                                          // col_nom2
                    nom_row,                                                    // row_nom1
                    nom_row + 1,                                                // row_nom2
                    2                                                           // align
                );
                // AutoFitRow (                                                    // SET ROW HEIGHT AND WIDTH
                //     Sheet,
                //     nom_row
                // );
            }
            else
                MergeCell (
                    i,
                    i,
                    nom_row,
                    nom_row + 1,
                    3
                );
        }
        nom_row += 2;
    }
}
void __fastcall TMainForm::CicleSum (                                           // Подсчет суммы по ячейкам
        int n_r,                                                                // номер строки начальный
        int nom_row,                                                            // номер строки текущий
        int st1,                                                                // номер столбца первый для начала суммирования
        int st2,                                                                // номер столбца последний для окончания суммирования
        int index                                                               // 0 - диапазон суммирования (=СУММ(B1:B9)) 1 - формула (= B1 + B9)
    )
{
    AnsiString form = "";

    for ( int i =  st1;
              i <= st2;
              ++i
        )
    {
        if (! index)                                                            // сумма через диапазон (=СУММ(B1:B9))
            form =
                "=СУММ("                        +
                    mas_column[i - 1]           +
                    AnsiString (n_r)            +
                ":"                             +
                    mas_column[i - 1]           +
                    AnsiString (nom_row - 1)    +
                ")";
        else                                                                    //  сумма через формулу (=B1+B9)
            form =
                "="                             +
                    mas_column[i - 1]           +
                    AnsiString (n_r - 2)        +
                "+"                             +
                    mas_column[i - 1]           +
                    AnsiString (nom_row - 1);

        Variant R2 =
            SelectCell (
                i,
                nom_row
            );
        CellFormula (
            form,
            i,
            nom_row
        );
        BorderCell (
            i,
            nom_row,
            1,
            2
        );
        CellFont (
            "Arial",
            10,
            true,
            false,
            1,
            R2
        );
    }
}
bool __fastcall TMainForm::Clear_mas (int n_ab)                                 // Поиск номера абитуриента в массиве all и обнуление этой записи
{
    for ( int i = 0;
              i < rec_q_all;
              ++i
        )
        if (mas_all[i] == n_ab)
        {
            mas_all[i] = 0;

            return
                true;
        }

    return false;
}
void __fastcall TMainForm::Create_mas_all (                                     // Создание массива всех абитуриентов на конкурс
        int n_spec,
        int vid_edu
    )
{
    DMVed -> QAll_Mas -> Close ();
    DMVed -> QAll_Mas ->
        ParamByName ("N_SP") -> Value = n_spec;
    DMVed -> QAll_Mas ->
        ParamByName ("V_ED") -> Value = vid_edu;
    DMVed -> QAll_Mas -> Open ();


    rec_q_all = DMVed -> QAll_Mas -> RecordCount;

    mas_all = new int [rec_q_all];

    for ( int i = 0;
              i < rec_q_all;
              ++i
        )
    {
        mas_all[i] =
            DMVed -> QAll_MasOUT_N_AB_ALL_M -> Value;

        DMVed -> QAll_Mas -> Next ();
    }
}
void __fastcall TMainForm::Create_Svod_ved (                                    // функция формирования сводной ведомости
        int edu,                                                                // вид обучения:   0 - дневное, 1 - заочное
        int price                                                               // финансирование: 0 - бюджет,  1 - платники
    )
{
    ExcelApplication =
        Variant::CreateObject (
            "Excel.Application"
        );

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir                                     +
            DocumentFile::SUMMARY_LIST::ENTRANCE_EXAMS
        );
    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );

    OVisible (ExcelApplication);

    CellValue (                                                                 // факультет
        fac1,
        3,
        6
    );

    DMVed -> QPredm -> Close ();                                                // Запись 'названий предметов'
    DMVed -> QPredm -> Open ();

    int
        rec_pred = 3,
        spec     = DM -> QSpecializN_SPECIALIZ -> Value;                        // IMPORTANT!!! I added initialization because there is no value for if statement

    mas_pr = new AnsiString[rec_pred];

    mas_pr[0] = "Белорусский (русский) язык";

    CellValue (
        "Бел. (рус.) яз",
        9,
        12
    );


    //if (spec != 61)
    if (spec == KindOfSportCode::TOURISM_HOSPITALITY)                           // институт туризма
    {
        mas_pr[1] = "Математика";

        CellValue (
            "Матем.",
            10,
            12
        );

        mas_pr[2] = "География";

        CellValue (
            "Геогр.",
            11,
            12
        );
    }
    else
    {
        mas_pr[1] = "Биология";

        CellValue (
            "Биол.",
            10,
            12
        );
    }

    DM -> QSpecializ -> Close ();
    DM -> QSpecializ -> Open ();
    DM -> QSpecializ -> First ();

    int rec_special = DM -> QSpecializ -> RecordCount;

    for ( int i = 0;                                                            // Проход по специализациям
              i < rec_special;
              ++i
        )
    {
        Create_mas_all (
            DM -> QSpecializN_SPECIALIZ -> Value,
            edu
        );


        spec = DM -> QSpecializN_SPECIALIZ -> Value;                            // План по специальности


        DMVed -> QKol_Place15 -> Close ();
        DMVed -> QKol_Place15 ->
            ParamByName ("SP")    -> Value =
                    DM -> QSpecializN_SPECIALIZ -> Value;
        DMVed -> QKol_Place15 ->
            ParamByName ("V_E")   -> Value =
                    edu;
        DMVed -> QKol_Place15 ->
            ParamByName ("kurs")  -> Value =
                    0;
        DMVed -> QKol_Place15 ->
            ParamByName ("price") -> Value =
                    price;
        DMVed -> QKol_Place15 -> Open ();

        int col_gorod = -1;
            col_gorod = DMVed -> QKol_Place15KOL_PLACE -> Value;

        DMVed -> QKol_Place15 -> Close ();

        int nom_str = 13;                                                       // Номер начальной строки в Excel

        if (col_gorod > 0)                                                      // Проверка есть ли конкурс по данной специализации
        {
            Sheet =
                SelectSheet (
                    Workbook,
                    "Лист1"
                );

            CopySheet (Sheet);

            Sheet =
                SelectSheet (
                    Workbook,
                    "Лист1 (2)"
                );
            NameSheet1 (
                Sheet,
                DM -> QSpecializSPECIAL -> Value.SetLength (30)
            );


            if (spec != 61)
            {
                mas_pr[1] = "Биология";

                CellValue (
                    "Биол.",
                    10,
                    12
                );
            }
            else                                                                // институт туризма
            {
                mas_pr[1] = "Математика";

                CellValue (
                    "Матем.",
                    10,
                    12
                );


                mas_pr[2] = "География";

                CellValue (
                    "Геогр.",
                    11,
                    12
                );
            }


            if (spec != 61)
            {
                mas_pr[2] = "Физическая культура и спорт";

                CellValue (
                    "ФКиС",
                    11,
                    12
                );
            }


            AnsiString cod_specializ1;


            DM -> KodSpecializQr -> Close ();
            DM -> KodSpecializQr ->
                ParamByName ("n_specializ") -> AsSmallInt =
                        DM -> QSpecializN_SPECIALIZ -> Value;
            DM -> KodSpecializQr -> Open ();


            CellValue (
                DeleteAfterDatabaseChange::getNcrb2022CodeNameSportStrByNSpecializ (
                    DM -> QSpecializN_SPECIALIZ    -> Value
                ),
//                    DeleteAfterDatabaseChange::getNcrb2022CodeByNSpecDir (
//                        DM -> KodSpecializQrN_SPEC_DIR -> Value
//                    )                                               +
//                    //DM -> KodSpecializQrCODE_SPEC_DIR -> Value  +
//                " "                                             +
//                    DeleteAfterDatabaseChange::getDirectionName2022ByNSpecDirNSpecializ (
//                        DM -> KodSpecializQrN_SPEC_DIR -> Value,
//                        DM -> QSpecializN_SPECIALIZ    -> Value
//                    ),
                3,
                7
            );

            DM -> KodSpecializQr -> Close ();

            if (edu)
                CellValue (
                    "заочная",
                    3,
                    8
                );
            else
                CellValue (
                    "дневная",
                    3,
                    8
                );

            if (price)
                CellValue (
                    "на платной основе",
                    3,
                    9
                );
            else
                CellValue (
                    "за счет средств "          \
                    "республиканского бюджета",
                    3,
                    9
                );


            int kkk = 3;                                                        // Конкурс 'Целевой'

            DMVed -> QKonkurs -> Close ();
            DMVed -> QKonkurs ->
                ParamByName ("in_sp")      -> Value =
                        DM -> QSpecializN_SPECIALIZ -> Value;
            DMVed -> QKonkurs ->
                ParamByName ("in_vid_edu") -> Value =
                        edu;
            DMVed -> QKonkurs ->
                ParamByName ("in_konk")    -> Value =
                        kkk;
            DMVed -> QKonkurs ->
                ParamByName ("in_price")   -> Value =
                        price;
            DMVed -> QKonkurs -> Open ();

            int rec = DMVed -> QKonkurs -> RecordCount;

            if (rec)                                                            // if есть такие люди
                nom_str =
                    Svod_ved (
                        nom_str,
                        kkk,
                        edu,
                        rec_pred,
                        price,
                        0
                    );


            kkk = 1;                                                            // Конкурс 'БВИ'

            DMVed -> QKonkurs -> Close ();
            DMVed -> QKonkurs ->
                ParamByName ("IN_SP")      -> Value =
                        DM -> QSpecializN_SPECIALIZ -> Value;
            DMVed -> QKonkurs ->
                ParamByName ("IN_VID_EDU") -> Value =
                        edu;
            DMVed -> QKonkurs ->
                ParamByName ("IN_KONK")    -> Value =
                        kkk;
            DMVed -> QKonkurs ->
                ParamByName ("IN_PRICE")   -> Value =
                        price;
            DMVed -> QKonkurs -> Open ();

            rec = DMVed -> QKonkurs -> RecordCount;

            if (rec)                                                            // if есть такие люди
                nom_str =
                    Svod_ved (
                        nom_str,
                        kkk,
                        edu,
                        rec_pred,
                        price,
                        0
                    );


            kkk = 2;                                                            // Конкурс 'ВК'

            DMVed -> QKonkurs -> Close ();

            DMVed -> QKonkurs ->
                ParamByName ("IN_SP")      -> Value =
                        DM -> QSpecializN_SPECIALIZ -> Value;
            DMVed -> QKonkurs ->
                ParamByName ("IN_VID_EDU") -> Value =
                        edu;
            DMVed -> QKonkurs ->
                ParamByName ("IN_KONK")    -> Value =
                        kkk;
            DMVed -> QKonkurs ->
                ParamByName ("IN_PRICE")   -> Value =
                        price;
            DMVed -> QKonkurs -> Open ();

            rec = DMVed -> QKonkurs -> RecordCount;

            if (rec)                                                            // if есть такие люди
                nom_str =
                    Svod_ved (
                        nom_str,
                        kkk,
                        edu,
                        rec_pred,
                        price,
                        0
                    );


            kkk = 0;                                                            // Конкурс 'Общий'

            DMVed -> QKonkurs -> Close ();
            DMVed -> QKonkurs ->
                ParamByName ("IN_SP")      -> Value =
                        DM -> QSpecializN_SPECIALIZ -> Value;
            DMVed -> QKonkurs ->
                ParamByName ("IN_VID_EDU") -> Value =
                        edu;
            DMVed -> QKonkurs ->
                ParamByName ("IN_KONK")    -> Value =
                        kkk;
            DMVed -> QKonkurs ->
                ParamByName ("IN_PRICE")   -> Value =
                        price;
            DMVed -> QKonkurs -> Open ();

            rec = DMVed -> QKonkurs -> RecordCount;

            if (rec)                                                            // if есть такие люди
                nom_str =
                    Svod_ved (
                        nom_str,
                        kkk,
                        edu,
                        rec_pred,
                        price,
                        0
                    );
        }

        DM -> QSpecializ -> Next ();

        if (mas_all)
            delete [] mas_all;
    }

    if (mas_pr)
        delete [] mas_pr;

    AnsiString n_file =
        getSummaryListNameByPeriod (
            StudyPeriod::HIGH::FULL,                                            // "Высшее образование",
            edu,
            price
        );

    DMVed -> QKonkurs   -> Close ();
    DM    -> QSpecializ -> Close ();
    DMVed -> QGorod     -> Close ();
    DMVed -> QKol_Place -> Close ();

    OVisible (ExcelApplication);

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );

    ExcelApplication.Clear ();
}
void __fastcall TMainForm::Create_Svod_ved_2VO2K (                              // функция формирования сводной ведомости 2 курс ВО
        int edu,                                                                // вид обучения:   0 - дневное, 1 - заочное
        int price                                                               // финансирование: 0 - бюджет,  1 - платники
    )
{
    ExcelApplication =
        Variant::CreateObject (
            "Excel.Application"
        );
    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir                                     +
            DocumentFile::SUMMARY_LIST::ENTRANCE_EXAMS
        );
    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );
    OVisible (ExcelApplication);

    CellValue (                                                                 // факультет
        fac1,
        3,
        6
    );

    int rec_pred = 0;

    DM -> QSpecializ -> Close ();
    DM -> QSpecializ -> Open ();
    DM -> QSpecializ -> First ();

    int rec_special = DM -> QSpecializ -> RecordCount;

    for ( int i = 0;                                                            // for цикл по специализациям
              i < rec_special;
              ++i
        )
    {
        Create_mas_all (
            DM -> QSpecializN_SPECIALIZ -> Value,
            edu
        );

        DM -> VO2KSpecializQr -> Close ();                                      // План по специальности
        DM -> VO2KSpecializQr ->
            ParamByName ("SP")    -> Value =
                    DM -> QSpecializN_SPECIALIZ -> Value;
        DM -> VO2KSpecializQr ->
            ParamByName ("V_E")   -> Value =
                    edu;
        DM -> VO2KSpecializQr ->
            ParamByName ("n_fac") -> Value =
                    nom_fac;
        DM -> VO2KSpecializQr ->
            ParamByName ("price") -> Value =
                    price;
        DM -> VO2KSpecializQr -> Open ();


        int col_gorod = -1,
            nom_str   = 13;                                                     // Начальная переменная дла номера строки в Excel

        col_gorod = DMVed -> QKol_Place15KOL_PLACE -> Value;

        if (DM -> VO2KSpecializQrNOMER_AB -> Value > 0)                         // if проверки есть ли конкурс на данную специализацию
        {
            Sheet =
                SelectSheet (
                    Workbook,
                    "Лист1"
                );

            CopySheet (
                Sheet
            );

            Sheet =
                SelectSheet (
                    Workbook,
                    "Лист1 (2)"
                );
            NameSheet1 (
                Sheet,
                DM -> QSpecializSPECIAL -> Value.SetLength (30)
            );

            AnsiString cod_specializ1;

            DM -> KodSpecializQr -> Close ();
            DM -> KodSpecializQr ->
                ParamByName ("n_specializ") -> AsSmallInt =
                        DM -> QSpecializN_SPECIALIZ -> Value;
            DM -> KodSpecializQr -> Open ();

            CellValue (
                DeleteAfterDatabaseChange::getNcrb2022CodeNameSportStrByNSpecializ (
                    DM -> QSpecializN_SPECIALIZ    -> Value
                ),
//                DeleteAfterDatabaseChange::getNcrb2022CodeByNSpecDir (
//                        DM -> KodSpecializQrN_SPEC_DIR -> Value
//                    )                                           +
//                    //DM -> KodSpecializQrCODE_SPEC_DIR -> Value  +
//                " "                                             +
//                    DeleteAfterDatabaseChange::getDirectionName2022ByNSpecDirNSpecializ (
//                        DM -> KodSpecializQrN_SPEC_DIR -> Value,
//                        DM -> QSpecializN_SPECIALIZ    -> Value
//                    ),
                //    DM -> KodSpecializQrCODE_SPEC_DIR -> Value  +
                //" "                                             +
                //    DM -> QSpecializSPECIAL_DIRECTION -> Value,
                3,
                7
            );

            DM -> KodSpecializQr -> Close ();

            if (edu)
                CellValue (
                    "заочная",
                    3,
                    8
                );
            else
                CellValue (
                    "дневная",
                    3,
                    8
                );

            if (price)
                CellValue (
                    "высшего образования на платной основе",
                    3,
                    9
                );
            else
                CellValue (
                    "высшего образования за счет средств "  \
                    "республиканского бюджета",
                    3,
                    9
                );


            int kkk = 3;                                                        // конкурс (Целевой)

            DMVed -> QKonkurs2V -> Close ();
            DMVed -> QKonkurs2V ->
                ParamByName ("in_sp")      -> Value =
                        DM -> QSpecializN_SPECIALIZ -> Value;
            DMVed -> QKonkurs2V ->
                ParamByName ("in_vid_edu") -> Value =
                        edu;
            DMVed -> QKonkurs2V ->
                ParamByName ("in_konk")    -> Value =
                        kkk;
            DMVed -> QKonkurs2V ->
                ParamByName ("in_price")   -> Value =
                        price;
            DMVed -> QKonkurs2V -> Open ();

            int rec = DMVed -> QKonkurs2V -> RecordCount;

            if (rec)
                nom_str =
                    Svod_ved (
                        nom_str,
                        kkk,
                        edu,
                        rec_pred,
                        price,
                        2
                    );


            kkk = 1;                                                            // конкурс (БВИ)

            DMVed -> QKonkurs2V -> Close ();
            DMVed -> QKonkurs2V ->
                ParamByName ("IN_SP")      -> Value =
                        DM -> QSpecializN_SPECIALIZ -> Value;
            DMVed -> QKonkurs2V ->
                ParamByName ("IN_VID_EDU") -> Value =
                        edu;
            DMVed -> QKonkurs2V ->
                ParamByName ("IN_KONK")    -> Value =
                        kkk;
            DMVed -> QKonkurs2V ->
                ParamByName ("IN_PRICE")   -> Value =
                        price;
            DMVed -> QKonkurs2V -> Open ();

            rec = DMVed -> QKonkurs2V -> RecordCount;

            if (rec)
                nom_str =
                    Svod_ved (
                        nom_str,
                        kkk,
                        edu,
                        rec_pred,
                        price,
                        2
                    );


            kkk = 2;                                                            // конкурс (ВК)

            DMVed -> QKonkurs2V -> Close ();
            DMVed -> QKonkurs2V ->
                ParamByName ("IN_SP")      -> Value =
                        DM -> QSpecializN_SPECIALIZ -> Value;
            DMVed -> QKonkurs2V ->
                ParamByName ("IN_VID_EDU") -> Value =
                        edu;
            DMVed -> QKonkurs2V ->
                ParamByName ("IN_KONK")    -> Value =
                        kkk;
            DMVed -> QKonkurs2V ->
                ParamByName ("IN_PRICE")   -> Value =
                        price;
            DMVed -> QKonkurs2V -> Open ();

            rec = DMVed -> QKonkurs2V -> RecordCount;

            if (rec)
                nom_str =
                    Svod_ved (
                        nom_str,
                        kkk,
                        edu,
                        rec_pred,
                        price,
                        2
                    );


            kkk = 0;                                                            // конкурс (Общий)

            DMVed -> QKonkurs2V -> Close ();
            DMVed -> QKonkurs2V ->
                ParamByName ("IN_SP")      -> Value =
                        DM -> QSpecializN_SPECIALIZ -> Value;
            DMVed -> QKonkurs2V ->
                ParamByName ("IN_VID_EDU") -> Value =
                        edu;
            DMVed -> QKonkurs2V ->
                ParamByName ("IN_KONK")    -> Value =
                        kkk;
            DMVed -> QKonkurs2V ->
                ParamByName ("IN_PRICE")   -> Value =
                        price;
            DMVed -> QKonkurs2V -> Open ();

            rec = DMVed -> QKonkurs2V -> RecordCount;

            if (rec)
                nom_str =
                    Svod_ved (
                        nom_str,
                        kkk,
                        edu,
                        rec_pred,
                        price,
                        2
                    );
        }

        DM -> VO2KSpecializQr -> Close ();

        DM -> QSpecializ -> Next ();

        if (mas_all)
            delete [] mas_all;
    }

    AnsiString n_file =
        getSummaryListNameByPeriod (
            StudyPeriod::HIGH::NAME,                                            // "Высшее образование",
            edu,
            price
        );

    DMVed -> QKonkurs   -> Close ();
    DM    -> QSpecializ -> Close ();
    DMVed -> QGorod     -> Close ();
    DMVed -> QKol_Place -> Close ();

    OVisible (ExcelApplication);

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );

    ExcelApplication.Clear ();
}
void __fastcall TMainForm::Create_Svod_ved_short (                              // функция формирования сводной ведомости сокращённый срок
        int edu,                                                                // вид обучения:   0 - дневное, 1 - заочное
        int price                                                               // финансирование: 0 - бюджет,  1 - платники
    )
{
    ExcelApplication =
        Variant::CreateObject (
            "Excel.Application"
        );
    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir                                     +
            DocumentFile::SUMMARY_LIST::ENTRANCE_EXAMS
        );
    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );

    OVisible (ExcelApplication);

    CellValue (                                                                 // факультет
        fac1,
        3,
        6
    );

    DMVed -> QPredm -> Close ();                                                // Запись названий предметов
    DMVed -> QPredm -> Open ();


    int rec_pred = 3;

    mas_pr    = new AnsiString[rec_pred];
    mas_pr[0] = "";

    CellValue (
        "",
        9,
        12
    );

    if (nom_fac == 3)
    {
        mas_pr[2] =
            "Физическая культура и спорт";

        CellValue (
            "ФКиС",
            11,
            12
        );

        mas_pr[1] =
            "Теория и методика физического воспитания";

        CellValue (
            "ТиМФВ",
            10,
            12
        );
    }


    if (    nom_fac == 1                                                        // СИиЕ, МВС
         || nom_fac == 2
       )
    {
        mas_pr[2] =
            "Физическая культура и спорт";

        CellValue (
            "ФКиС",
            11,
            12
        );

        mas_pr[1] =
            "Основы теории и методики спортивной тренировки";

        CellValue (
            "ОТиМСТ",
            10,
            12
        );
    }


    if (nom_fac == 4)                                                           // ИТ Галя
    {
        mas_pr[2] =
            "Маркетинг туризма";

        CellValue (
            "Маркет. тур",
            11,
            12
        );

        mas_pr[1] =
            "Организация туризма";

        CellValue (
            "Организ. тур.",
            10,
            12
        );
    }

    int nom_str = 13;                                                           // Номер начальной строки в Excel

    Sheet =
       SelectSheet (
           Workbook,
           "Лист1"
       );

    if (nom_fac != 4)
    {
        mas_pr[2] =
            "Физическая культура и спорт";

        CellValue (
            "ФКиС",
            11,
            12
        );
    }


    switch (nom_fac)
    {
        case 1:
                CellValue (
                    //"1-88 02 01-01 "+
                    NCRB_011::_2022::CODE::COACHING                 +
                    " "                                             +
                    NCRB_011::_2022::NAME::COACHING                 +
                    " "                                             +
                    NCRB_011::_2022::NAME::COACH::DEFAULT,
                    //"Спортивно-педагогическая деятельность "  \
                    //"(тренерская работа с указанием вида спорта)",
                    3,
                    7
                );
            break;
        case 2:
                CellValue (
                    //"1-88 02 01-01 Спортивно-педагогическая деятельность "  \
                    //"(тренерская работа с указанием вида спорта)",
                    NCRB_011::_2022::CODE::COACHING                 +
                    " "                                             +
                    NCRB_011::_2022::NAME::COACHING                 +
                    " "                                             +
                    NCRB_011::_2022::NAME::COACH::DEFAULT,
                    3,
                    7
                );
            break;
        case 3:
                CellValue (
                    //"1-88 01 01-02 Физическая культура (дошкольников), "     \
                    //"1-88 01 02-01 Оздоровительная и адаптивная "           \
                    //"физическая культура (оздоровительная)",
                    NCRB_011::_2022::CODE::PHYSICAL_CULTURE         +
                    " "                                             +
                    NCRB_011::_2022::NAME::PHYSICAL_CULTURE         +
                    " "                                             +
                    NCRB_011::_2022::NAME::PHYSICAL::PRESCHOOLERS   +
                    ", "                                            +
                    NCRB_011::_2022::CODE::PHYSICAL_CULTURE         +
                    " "                                             +
                    NCRB_011::_2022::NAME::PHYSICAL_CULTURE         +
                    " "                                             +
                    NCRB_011::_2022::NAME::PHYSICAL::IMPROVING,

                    3,
                    7
                );
            break;
        case 4:
                CellValue (
                    //"1-89 01 01 Туризм и гостеприимство)",
                        NCRB_011::_2022::CODE::TOURISM         +
                    " "                                        +
                        NCRB_011::_2022::NAME::TOURISM         +
                    ")",
                    3,
                    7
                );
            break;
    }


    if (edu)
        CellValue (
            "заочная",
            3,
            8
        );
    else
        CellValue (
            "дневная",
            3,
            8
        );


    if (price)
        CellValue (
            "на платной основе",
            3,
            9
        );
    else
        CellValue (
            "за счет средств республиканского бюджета",
            3,
            9
        );


    if (    nom_fac == 1
         || nom_fac == 2
       )
    {
        int kkk = 3;                                                            // Конкурс 'Целевой'


        DMVed -> QKonkurs12 -> Close ();
        DMVed -> QKonkurs12 ->
            ParamByName ("in_vid_edu") -> Value = edu;
        DMVed -> QKonkurs12 ->
            ParamByName ("in_konk")    -> Value = kkk;
        DMVed -> QKonkurs12 ->
            ParamByName ("in_price")   -> Value = price;
        DMVed -> QKonkurs12 -> Open ();


        int rec = DMVed -> QKonkurs12 -> RecordCount;

        if (rec)                                                                // есть ли такие люди
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );


        kkk = 1;                                                                // Конкурс 'БВИ'

        DMVed -> QKonkurs12 -> Close ();
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_VID_EDU") -> Value = edu;
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_KONK")    -> Value = kkk;
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_PRICE")   -> Value = price;
        DMVed -> QKonkurs12 -> Open ();

        rec = DMVed -> QKonkurs12 -> RecordCount;

        if (rec)                                                                // if есть такие люди
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );


        kkk = 2;                                                                // Конкурс 'ВК'

        DMVed -> QKonkurs12 -> Close ();
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_VID_EDU") -> Value = edu;
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_KONK")    -> Value = kkk;
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_PRICE")   -> Value = price;
        DMVed -> QKonkurs12 -> Open ();

        rec = DMVed -> QKonkurs12 -> RecordCount;

        if (rec)                                                                // if есть такие люди
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );


        kkk = 0;                                                                // Конкурс 'Общий'

        DMVed -> QKonkurs12 -> Close ();
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_VID_EDU") -> Value = edu;
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_KONK")    -> Value = kkk;
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_PRICE")   -> Value = price;
        DMVed -> QKonkurs12 -> Open ();

        rec = DMVed -> QKonkurs12 -> RecordCount;

        if (rec)                                                                // if есть такие люди
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );
    }
    else                                                                        // ОФКиТ, ТиГ QKonkurs34
    {
        int kkk = 3;                                                            // Конкурс 'Целевой'

        DMVed -> QKonkurs34 -> Close ();
        DMVed -> QKonkurs34 ->
            ParamByName ("n_fac")      -> Value = nom_fac;
        DMVed -> QKonkurs34 ->
            ParamByName ("in_vid_edu") -> Value = edu;
        DMVed -> QKonkurs34 ->
            ParamByName ("in_konk")    -> Value = kkk;
        DMVed -> QKonkurs34 ->
            ParamByName ("in_price")   -> Value = price;
        DMVed -> QKonkurs34 -> Open ();

        int rec = DMVed -> QKonkurs34 -> RecordCount;

        if (rec)                                                                // if есть такие люди
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );


        kkk = 1;                                                                // Конкурс 'БВИ'

        DMVed -> QKonkurs34 -> Close ();
        DMVed -> QKonkurs34 ->
            ParamByName ("n_fac")      -> Value = nom_fac;
        DMVed -> QKonkurs34 ->
            ParamByName ("IN_VID_EDU") -> Value = edu;
        DMVed -> QKonkurs34 ->
            ParamByName ("IN_KONK")    -> Value = kkk;
        DMVed -> QKonkurs34 ->
            ParamByName ("IN_PRICE")   -> Value = price;
        DMVed -> QKonkurs34 -> Open ();

        rec = DMVed -> QKonkurs34 -> RecordCount;

        if (rec)                                                                // if есть такие люди
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );


        kkk = 2;                                                                // Конкурс 'ВК'

        DMVed -> QKonkurs34 -> Close ();
        DMVed -> QKonkurs34 ->
            ParamByName ("n_fac")      -> Value = nom_fac;
        DMVed -> QKonkurs34 ->
            ParamByName ("IN_VID_EDU") -> Value = edu;
        DMVed -> QKonkurs34 ->
            ParamByName ("IN_KONK")    -> Value = kkk;
        DMVed -> QKonkurs34 ->
            ParamByName ("IN_PRICE")   -> Value = price;
        DMVed -> QKonkurs34 -> Open ();

        rec = DMVed -> QKonkurs34 -> RecordCount;

        if (rec)                                                                // if есть такие люди
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );


        kkk = 0;                                                                // Конкурс 'Общий'

        DMVed -> QKonkurs34 -> Close ();
        DMVed -> QKonkurs34 ->
            ParamByName ("n_fac")      -> Value = nom_fac;
        DMVed -> QKonkurs34 ->
            ParamByName ("IN_VID_EDU") -> Value = edu;
        DMVed -> QKonkurs34 ->
            ParamByName ("IN_KONK")    -> Value = kkk;
        DMVed -> QKonkurs34 ->
            ParamByName ("IN_PRICE")   -> Value = price;
        DMVed -> QKonkurs34 -> Open ();

        rec = DMVed -> QKonkurs34 -> RecordCount;

        if (rec)                                                                // if есть такие люди
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );
    }

    if (mas_all)
        delete [] mas_all;

    if (mas_pr)
        delete [] mas_pr;

    AnsiString n_file =
        getSummaryListNameByPeriod (
            StudyPeriod::SHORT::NAME,                                           // "Cокращённый срок",
            edu,
            price
        );

    DMVed -> QKonkurs12 -> Close ();
    DM    -> QSpecializ -> Close ();
    DMVed -> QGorod     -> Close ();
    DMVed -> QKol_Place -> Close ();

    OVisible (ExcelApplication);

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );

    ExcelApplication.Clear ();
}
void __fastcall TMainForm::Data_spisok (                                        // формирует строки S1,S2,S3 (преимуществ и спортивного разряда) списока абитуриентов
        int col_pred,                                                           // количество предметов
        int nom_stroka,                                                         // номер строки
        int j                                                                   // номер по порядку
    )
{
    Priv_Str (10);                                                              // параметр 10 - формирует полный списка абитуриентов


    CellValue (                                                                 // занесение льгот на экзаменах (конкурс)
        S1,
        1,
        nom_stroka
    );
    BorderCell (
        1,
        nom_stroka,
        1,
        2
    );


    CellValue (                                                                 // занесение № п/п
            AnsiString (j) +
        ".",
        2,
        nom_stroka
    );
    BorderCell (
        2,
        nom_stroka,
        1,
        2
    );


    CellValue (                                                                 // занесение ФИО
            DM -> QSpisoc_GroupFAM  -> Value    +
        " "                                     +
            DM -> QSpisoc_GroupNAME -> Value    +
        " "                                     +
            DM -> QSpisoc_GroupOTCH -> Value,
        3,
        nom_stroka
    );
    BorderCell (
        3,
        nom_stroka,
        1,
        2
    );


    CellValue (                                                                 // занесение спортивного разряда
        S3,
        4,
        nom_stroka
    );
    BorderCell (
        4,
        nom_stroka,
        1,
        2
    );


    CellValue_Ball (                                                            // занесение оценок по всем экзаменам для одного абитуриента
        col_pred,
        nom_stroka
    );


    if (    nom_fac                             == 1
         || nom_fac                             == 2
         || nom_fac                             == 3
         || nom_fac                             == 4
         && DM -> QSpisoc_GroupKONKURS -> Value == 3
       )
    {
        Variant Ce1 =
            SelectCell (
                5           +
                col_pred,
                nom_stroka
            );
        SheetFormat (
            Ce1,
            "0,0"                                                               // 0.0 в самом Excel пишет такой формат
        );


        Ce1 =
            SelectCell (
                6           +
                col_pred,
                nom_stroka
            );
        SheetFormat (
            Ce1,
            "0,0"
        );
    }


    CellValue (                                                             // занесение среднего балла аттестата
        DM -> QSpisoc_GroupMIDDLE_BALL -> Value,
        5                                       +
        col_pred,
        nom_stroka
    );

    BorderCell (
        5           +
        col_pred,
        nom_stroka,
        1,
        2
    );

    if (    nom_fac                             == 4
         && DM -> QSpisoc_GroupKONKURS -> Value != 3
       )
        CellValue (
            DM -> QSpisoc_GroupSUM_BALL -> Value,
            6                                       +
            col_pred,
            nom_stroka
        );
    BorderCell (
        6           +
        col_pred,
        nom_stroka,
        1,
        2
    );


    CellValue (                                                                 // занесение Примечания (преимущества при зачислении)
        S2,
        7           +
        col_pred,
        nom_stroka
    );
    BorderCell (
        7           +
        col_pred,
        nom_stroka,
        1,
        2
    );
}
void __fastcall TMainForm::Data_spisok_Pol (
        int nom_stroka,
        int j
    )
{
    CellValue (                                                                 // занесение № п/п
        AnsiString (j) + ".",
        2,
        nom_stroka
    );
    BorderCell (
        2,
        nom_stroka,
        1,
        2
    );

    CellValue (                                                                 // занесение ФИО
            DM -> QSpisoc_Group_PolFAM  -> Value    +
        " "                                         +
            DM -> QSpisoc_Group_PolNAME -> Value    +
        " "                                         +
            DM -> QSpisoc_Group_PolOTCH -> Value,
        3,
        nom_stroka
    );
    BorderCell (
        3,
        nom_stroka,
        1,
        2
    );
}
int  __fastcall TMainForm::Find_nom_spec_str (                                  // Поиск индекса записи в массиве mas_spec_str по номеру специальности
        int n_spec,
        int rec_count
    )
{
    for ( int i = 0;
              i < rec_count;
              ++i
        )
        if (mas_spec_str[0][i] == n_spec)
            return
                mas_spec_str[1][i];

    return 0;
}
void __fastcall TMainForm::Forma_Giac (                                         // Форма для ГИАЦ
        int form,                                                               // номер Формы для ГИАЦ: 1 - приём, 2 - зачисление
        int vid_educ                                                            // вид обучения
    )
{
    ExcelApplication =
        Variant::CreateObject (
            "Excel.Application"
        );

    AnsiString
        report_type;

    if (form == 1)
        report_type = DocumentFile::REPORT::FORM_1;
    else
        report_type = DocumentFile::REPORT::FORM_2;

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir             +                                               // "D:\\Документы приемной конпании\\1\\"
            report_type
        );
    OVisible (ExcelApplication);

    int
        giac_val,                                                               // значение для вывода в таблицу I
        N_Spec[6],
        razd1     = 10;                                                         // номер строки для формирования раздела

    N_Spec[0]        = 8;                                                       // Физическая культура (по направлениям)
    N_Spec[1]        = 5;                                                       // Оздоровительная и адаптивная физическая культура (по направлениям)
    N_Spec[2]        = 9;                                                       // Физическая реабилитация и эрготерапия (по направлениям)
    N_Spec[3]        = 6;                                                       // Спортивно-педагогическая деятельность (по направлениям)
    N_Spec[4]        = 10;                                                      // Туризм и гостеприимство
    N_Spec[5]        = 7;                                                       // Спортивно-туристская деятельность (по направлениям)

    if (form == 1)                                                              // форма 1 - приём документов
    {
        Sheet =
            SelectSheet (
                Workbook,
                "ОТЧЕТ"
            );

        if (vid_educ)
        {
            CellValue (
                "в заочной форме получения образования",
                3,
                17
            );
            CellValue (
                "в заочной форме получения образования",
                3,
                24
            );
        }
        else
            CellValue (
                "в дневной форме получения образования",
                3,
                17
            );


        CellValue (
            "в дневной форме получения образования",
            3,
            24
        );


        Sheet =
            SelectSheet (
                Workbook,
                "РАЗДЕЛ I"
            );


        DM -> QGIACAllSpec -> Close ();                                         // (ПЛАН ВСЕГО) Физическая культура (по направлениям) n_spec = 8
        DM -> QGIACAllSpec -> SQL -> Clear ();
        DM -> QGIACAllSpec ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     SUM"                          \
                    "     ("                            \
                    "         kol_place"                \
                    "     )"                            \
                    " FROM"                             \
                    "     kol_place"                    \
                    " WHERE"                            \
                    "         vid_edu = :vid_edu"       \
                    "     AND"                          \
                    "         price   = :price"         \
                    "     AND"                          \
                    "         ("                        \
                    "             n_specializ = 4"      \
                    "         OR"                       \
                    "             n_specializ = 57"     \
                    "         )"
                );

        DM -> QGIACAllSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;
        DM -> QGIACAllSpec ->
            ParamByName ("price")   -> AsInteger = 0;
        DM -> QGIACAllSpec -> Open ();

        giac_val = DM -> QGIACAllSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                3,
                10
            );

        DM -> QGIACAllSpec -> Close ();



        DM -> QGIACAllSpec -> Close ();

        DM -> QGIACAllSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACAllSpec ->
            ParamByName ("price")   -> AsInteger = 1;

        DM -> QGIACAllSpec -> Open ();

        giac_val = DM -> QGIACAllSpecSUM -> Value;

        if (giac_val)                                                           // ?????? NEED OR NOT ???????
            CellValue (
                giac_val,
                6,
                10
            );

        CellValue (                                                             // ?????? NEED OR NOT ???????
            giac_val,
            6,
            10
        );

        DM -> QGIACAllSpec -> Close ();



        DM -> QGIACAllSpec -> Close ();                                         // Оздоровительная и адаптивная физическая культура (по направлениям) n_spec = 5
        DM -> QGIACAllSpec -> SQL -> Clear ();
        DM -> QGIACAllSpec ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     SUM"                          \
                    "     ("                            \
                    "         kol_place"                \
                    "     )"                            \
                    " FROM"                             \
                    "     kol_place"                    \
                    " WHERE"                            \
                    "         vid_edu = :vid_edu"       \
                    "     AND"                          \
                    "         price   = :price"         \
                    "     AND"                          \
                    "         ("                        \
                    "             n_specializ = 38"     \
                    "         OR"                       \
                    "             n_specializ = 39"     \
                    "         )"
                );

        DM -> QGIACAllSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACAllSpec ->
            ParamByName ("price")   -> AsInteger = 0;

        DM -> QGIACAllSpec -> Open ();

        giac_val = DM -> QGIACAllSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                3,
                11
            );

        DM -> QGIACAllSpec -> Close ();



        DM -> QGIACAllSpec -> Close ();

        DM -> QGIACAllSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACAllSpec ->
            ParamByName ("price")   -> AsInteger = 1;

        DM -> QGIACAllSpec -> Open ();

        giac_val = DM -> QGIACAllSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                6,
                11
            );

        DM -> QGIACAllSpec -> Close ();



        DM -> QGIACAllSpec -> Close ();                                         // Физическая реабилитация и эрготерапия (по направлениям) n_spec = 9
        DM -> QGIACAllSpec -> SQL -> Clear ();
        DM -> QGIACAllSpec ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     SUM"                          \
                    "     ("                            \
                    "         kol_place"                \
                    "     )"                            \
                    " FROM"                             \
                    "     kol_place"                    \
                    " WHERE"                            \
                    "         vid_edu = :vid_edu"       \
                    "     AND"                          \
                    "         price   = :price"         \
                    "     AND"                          \
                    "         ("                        \
                    "             n_specializ = 3"      \
                    "          OR"                      \
                    "             n_specializ = 47"     \
                    "         )"
                );

        DM -> QGIACAllSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACAllSpec ->
            ParamByName ("price")   -> AsInteger = 0;

        DM -> QGIACAllSpec -> Open ();

        giac_val = DM -> QGIACAllSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                3,
                12
            );

        DM -> QGIACAllSpec -> Close ();



        DM -> QGIACAllSpec -> Close ();

        DM -> QGIACAllSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACAllSpec ->
            ParamByName ("price")   -> AsInteger = 1;

        DM -> QGIACAllSpec -> Open ();

        giac_val = DM -> QGIACAllSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                6,
                12
            );

        DM -> QGIACAllSpec -> Close ();



        DM -> QGIACAllSpec -> Close ();                                         // Спортивно-педагогическая деятельность (по направлениям) n_spec = 6
        DM -> QGIACAllSpec -> SQL -> Clear ();
        DM -> QGIACAllSpec ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     SUM"                          \
                    "     ("                            \
                    "         kol_place"                \
                    "     )"                            \
                    " FROM"                             \
                    "     kol_place"                    \
                    " WHERE"                            \
                    "         vid_edu = :vid_edu"       \
                    "     AND"                          \
                    "         price   = :price"         \
                    "     AND"                          \
                    "         ("                        \
                    "             n_specializ = 1"      \
                    //+    KindOfSportCode::GYMNASTICS    +
                    "          OR"                      \
                    "             n_specializ = 7"      \
                    //+   KindOfSportCode::DANCE_SPORT    +
                    "          OR"                      \
                    "             n_specializ = 8"      \
                    // + KindOfSportCode::AEROBICS         +
                    "          OR"                      \
                    "             n_specializ = 9"      \
                    // + KindOfSportCode::ROWING_OTHER     +
                    "          OR"                      \
                    "             n_specializ = 10"     \
                    // + KindOfSportCode::SWIMMING         +
                    "          OR"                      \
                    "             n_specializ = 12"     \
                    // + KindOfSportCode::ATHLETICS        +
                    "          OR"                      \
                    "             n_specializ = 13"     \
                    // + KindOfSportCode::CROSS_COUNTRY_SKIING +
                    "          OR"                      \
                    "             n_specializ = 15"     \
                    // + KindOfSportCode::HAND_TO_HAND_COMBAT +
                    "          OR"                      \
                    "             n_specializ = 16"     \
                    // + KindOfSportCode::TAEKWONDO        +
                    "          OR"                      \
                    "             n_specializ = 17"     \
                    // + KindOfSportCode::KARATE           +
                    "          OR"                      \
                    "             n_specializ = 20"     \
                    // + KindOfSportCode::BASKETBALL       +
                    "          OR"                      \
                    "             n_specializ = 21"     \
                    // + KindOfSportCode::BOXING           +
                    "          OR"                      \
                    "             n_specializ = 23"     \
                    // + KindOfSportCode::CYCLING          +
                    "          OR"                      \
                    "             n_specializ = 24"     \
                    // + KindOfSportCode::VOLLEYBALL       +
                    "          OR"                      \
                    "             n_specializ = 25"     \
                    // + KindOfSportCode::HANDBALL         +
                    "          OR"                      \
                    "             n_specializ = 26"     \
                    // + KindOfSportCode::EQUESTRIAN       +
                    "          OR"                      \
                    "             n_specializ = 27"     \
                    // + KindOfSportCode::SPEED_SKATING    +
                    "          OR"                      \
                    "             n_specializ = 28"     \
                    // + KindOfSportCode::TENNIS           +
                    "          OR"                      \
                    "             n_specializ = 29"     \
                    // + KindOfSportCode::WEIGHTLIFTING    +
                    "          OR"                      \
                    "             n_specializ = 30"     \
                    // + KindOfSportCode::FENCING          +
                    "          OR"                      \
                    "             n_specializ = 32"     \
                    // + KindOfSportCode::FOOTBALL         +
                    "          OR"                      \
                    "             n_specializ = 33"     \
                    // + KindOfSportCode::HOCKEY           +
                    "          OR"                      \
                    "             n_specializ = 35"     \
                    // + KindOfSportCode::WRESTLING        +
                    "          OR"                      \
                    "             n_specializ = 37"     \
                    // + KindOfSportCode::BIATHLON         +
                    "          OR"                      \
                    "             n_specializ = 42"     \
                    // + KindOfSportCode::FREESTYLE_WRESTLING +
                    "          OR"                      \
                    "             n_specializ = 43"     \
                    // + KindOfSportCode::GRECO_ROMAN_WRESTLING +
                    "          OR"                      \
                    "             n_specializ = 44"     \
                    // + KindOfSportCode::SAMBO            +
                    "          OR"                      \
                    "             n_specializ = 45"     \
                    // + KindOfSportCode::JUDO             +
                    "          OR"                      \
                    "             n_specializ = 48"     \
                    // + KindOfSportCode::MANAGEMENT_SPORTS +
                    "          OR"                      \
                    "             n_specializ = 52"     \
                    // + KindOfSportCode::SPORTS_PSYCHOLOGY +
                    "          OR"                      \
                    "             n_specializ = 53"     \
                    // + KindOfSportCode::BILLIARD_SPORTS  +
                    "          OR"                      \
                    "             n_specializ = 54"     \
                    // + KindOfSportCode::ACROBATICS       +
                    "          OR"                      \
                    "             n_specializ = 55"     \
                    // + KindOfSportCode::ORIENTEERING     +
                    "          OR"                      \
                    "             n_specializ = 66"     \
                    // + KindOfSportCode::WUSHU            +
                    "          OR"                      \
                    "             n_specializ = 68"     \
                    // + KindOfSportCode::CHESS            +
                    "          OR"                      \
                    "             n_specializ = 69"     \
                    // + KindOfSportCode::THAI_BOXING      +
                    "          OR"                      \
                    "             n_specializ = 79"     \
                    // + KindOfSportCode::BULLET_SHOOTING  +
                    "          OR"                      \
                    "             n_specializ = 80"     \
                    // + KindOfSportCode::FIELD_HOCKEY     +
                    "          OR"                      \
                    "             n_specializ = 84"     \
                    // + KindOfSportCode::FIGURE_SKATING   +
                    "          OR"                      \
                    "             n_specializ = 87"     \
                    // + KindOfSportCode::ROWING_AND_CANOEING +
                    "          OR"                      \
                    "             n_specializ = 88"     \
                    // + KindOfSportCode::ACADEMIC_ROWING  +
                    "          OR"                      \
                    "             n_specializ = 94"     \
                    // + KindOfSportCode::WITHOUT_SPECIALIZATION +
                    "          OR"                      \
                    "             n_specializ = 96"     \
                    // + KindOfSportCode::MODERN_PENTATHLON +
                    "          OR"                      \
                    "             n_specializ = 120"    \
                    // + KindOfSportCode::SPORT_CLIMBING   +
                    "         )"
                );

        DM -> QGIACAllSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACAllSpec ->
            ParamByName ("price")   -> AsInteger = 0;

        DM -> QGIACAllSpec -> Open ();

        giac_val = DM -> QGIACAllSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                3,
                13
            );

        DM -> QGIACAllSpec -> Close ();



        DM -> QGIACAllSpec -> Close ();

        DM -> QGIACAllSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACAllSpec ->
            ParamByName ("price")   -> AsInteger = 1;

        DM -> QGIACAllSpec -> Open ();

        giac_val = DM -> QGIACAllSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                6,
                13
            );

        DM -> QGIACAllSpec -> Close ();



        DM -> QGIACAllSpec -> Close ();                                         // Туризм и гостеприимство  n_spec=10
        DM -> QGIACAllSpec -> SQL -> Clear ();
        DM -> QGIACAllSpec ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     SUM"                          \
                    "     ("                            \
                    "         kol_place"                \
                    "     )"                            \
                    " FROM"                             \
                    "     kol_place"                    \
                    " WHERE"                            \
                    "         vid_edu     = :vid_edu"   \
                    "     AND"                          \
                    "         price       = :price"   \
                    "     AND"                          \
                    "         n_specializ = 61"
                );

        DM -> QGIACAllSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACAllSpec ->
            ParamByName ("price")   -> AsInteger = 0;

        DM -> QGIACAllSpec -> Open ();

        giac_val = DM -> QGIACAllSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                3,
                14
            );

        DM -> QGIACAllSpec -> Close ();



        DM -> QGIACAllSpec -> Close ();

        DM -> QGIACAllSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACAllSpec ->
            ParamByName ("price")   -> AsInteger = 1;

        DM -> QGIACAllSpec -> Open ();

        giac_val = DM -> QGIACAllSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                6,
                14
            );

        DM -> QGIACAllSpec -> Close ();



        DM -> QGIACAllSpec -> Close ();                                         // Спортивно-туристская деятельность (по направлениям) n_spec = 7
        DM -> QGIACAllSpec -> SQL -> Clear ();
        DM -> QGIACAllSpec ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     SUM"                          \
                    "     ("                            \
                    "         kol_place"                \
                    "     )"                            \
                    " FROM"                             \
                    "     kol_place"                    \
                    " WHERE"                            \
                    "         vid_edu = :vid_edu"       \
                    "     AND"                          \
                    "         price   = :price"         \
                    "     AND"                          \
                    "         ("                        \
                    "             n_specializ = 51"     \
                    "          OR"                      \
                    "             n_specializ = 100"    \
                    "         )"
                );

        DM -> QGIACAllSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACAllSpec ->
            ParamByName ("price")   -> AsInteger = 0;

        DM -> QGIACAllSpec -> Open ();

        giac_val = DM -> QGIACAllSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                3,
                15
            );

        DM -> QGIACAllSpec -> Close ();



        DM -> QGIACAllSpec -> Close ();

        DM -> QGIACAllSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACAllSpec ->
            ParamByName ("price")   -> AsInteger = 1;

        DM -> QGIACAllSpec -> Open ();

        giac_val = DM -> QGIACAllSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                6,
                15
            );

        DM -> QGIACAllSpec -> Close ();



        DM -> QGIACCKSpec -> Close ();                                          // ПЛАН 'ЦЕЛЕВЫХ'  Физическая культура (по направлениям)
        DM -> QGIACCKSpec -> SQL -> Clear ();
        DM -> QGIACCKSpec ->
            SQL ->
                Add (
                    " SELECT"                       \
                    "     SUM"                      \
                    "     ("                        \
                    "         -- kol_p"             \
                    "         kol_place"            \
                    "     )"                        \
                    " FROM"                         \
                    "     -- ck"                    \
                    "     ck_plan"                  \
                    " WHERE"                        \
                    "         n_specializ = 4"      \
                    "     OR"                       \
                    "         n_specializ = 57"
                );

        DM -> QGIACCKSpec -> Open ();

        giac_val = DM -> QGIACCKSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                4,
                10
            );

        DM -> QGIACCKSpec -> Close ();



        DM -> QGIACCKSpec -> Close ();                                          //  ПЛАН 'ЦЕЛЕВЫХ'  Оздоровительная и адаптивная физическая культура (по направлениям)
        DM -> QGIACCKSpec -> SQL -> Clear ();
        DM -> QGIACCKSpec ->
            SQL ->
                Add (
                    " SELECT"                       \
                    "     SUM"                      \
                    "     ("                        \
                    "         kol_place"            \
                    "     )"                        \
                    " FROM"                         \
                    "     ck_plan"                  \
                    " WHERE"                        \
                    "         n_specializ = 38"     \
                    "     OR"                       \
                    "         n_specializ = 39"
                );

        DM -> QGIACCKSpec -> Open ();

        giac_val = DM -> QGIACCKSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                4,
                11
            );

        DM -> QGIACCKSpec -> Close ();



        DM -> QGIACCKSpec -> Close ();                                          // ПЛАН 'ЦЕЛЕВЫХ'  Физическая реабилитация и эрготерапия (по направлениям)
        DM -> QGIACCKSpec -> SQL -> Clear ();
        DM -> QGIACCKSpec ->
            SQL ->
                Add (
                    " SELECT"                   \
                    "     SUM"                  \
                    "     ("                    \
                    "         kol_place"        \
                    "     )"                    \
                    " FROM"                     \
                    "     ck_plan"              \
                    " WHERE"                    \
                    "     n_specializ = 3"
                );

        DM -> QGIACCKSpec -> Open ();

        giac_val = DM -> QGIACCKSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                4,
                12
            );

        DM -> QGIACCKSpec -> Close ();



        DM -> QGIACCKSpec -> Close ();                                          // ПЛАН 'ЦЕЛЕВЫХ'  Спортивно-педагогическая деятельность (по направлениям)
        DM -> QGIACCKSpec -> SQL -> Clear ();
        DM -> QGIACCKSpec ->
            SQL ->
                Add (
                    " SELECT"                       \
                    "     SUM"                      \
                    "     ("                        \
                    "         kol_place"            \
                    "     )"                        \
                    " FROM"                         \
                    "     ck_plan"                  \
                    " WHERE"                        \
                    "         n_specializ = 1"      \
                    "     OR"                       \
                    "         n_specializ = 7"      \
                    "     OR"                       \
                    "         n_specializ = 9"      \
                    "     OR"                       \
                    "         n_specializ = 10"     \
                    "     OR"                       \
                    "         n_specializ = 11"     \
                    "     OR"                       \
                    "         n_specializ = 12"     \
                    "     OR"                       \
                    "         n_specializ = 13"     \
                    "     OR"                       \
                    "         n_specializ = 15"     \
                    "     OR"                       \
                    "         n_specializ = 16"     \
                    "     OR"                       \
                    "         n_specializ = 17"     \
                    "     OR"                       \
                    "         n_specializ = 19"     \
                    "     OR"                       \
                    "         n_specializ = 20"     \
                    "     OR"                       \
                    "         n_specializ = 21"     \
                    "     OR"                       \
                    "         n_specializ = 23"     \
                    "     OR"                       \
                    "         n_specializ = 24"     \
                    "     OR"                       \
                    "         n_specializ = 25"     \
                    "     OR"                       \
                    "         n_specializ = 26"     \
                    "     OR"                       \
                    "         n_specializ = 27"     \
                    "     OR"                       \
                    "         n_specializ = 28"     \
                    "     OR"                       \
                    "         n_specializ = 29"     \
                    "     OR"                       \
                    "         n_specializ = 30"     \
                    "     OR"                       \
                    "         n_specializ = 32"     \
                    "     OR"                       \
                    "         n_specializ = 33"     \
                    "     OR"                       \
                    "         n_specializ = 35"     \
                    "     OR"                       \
                    "         n_specializ = 37"     \
                    "     OR"                       \
                    "         n_specializ = 42"     \
                    "     OR"                       \
                    "         n_specializ = 43"     \
                    "     OR"                       \
                    "         n_specializ = 44"     \
                    "     OR"                       \
                    "         n_specializ = 45"     \
                    "     OR"                       \
                    "         n_specializ = 48"     \
                    "     OR"                       \
                    "         n_specializ = 52"     \
                    "     OR"                       \
                    "         n_specializ = 54"     \
                    "     OR"                       \
                    "         n_specializ = 55"     \
                    "     OR"                       \
                    "         n_specializ = 66"     \
                    "     OR"                       \
                    "         n_specializ = 68"     \
                    "     OR"                       \
                    "         n_specializ = 69"     \
                    "     OR"                       \
                    "         n_specializ = 79"     \
                    "     OR"                       \
                    "         n_specializ = 80"     \
                    "     OR"                       \
                    "         n_specializ = 84"     \
                    "     OR"                       \
                    "         n_specializ = 87"     \
                    "     OR"                       \
                    "         n_specializ = 88"     \
                    "     OR"                       \
                    "         n_specializ = 94"     \
                    "     OR"                       \
                    "         n_specializ = 96"     \
                    "     OR"                       \
                    "         n_specializ = 115"    \
                    "     OR"                       \
                    "         n_specializ = 120"
                );

        DM -> QGIACCKSpec -> Open ();

        giac_val = DM -> QGIACCKSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                4,
                13
            );

        DM -> QGIACCKSpec -> Close ();



        DM -> QGIACCKSpec -> Close ();                                          // ПЛАН 'ЦЕЛЕВЫХ'  Туризм и гостеприимство
        DM -> QGIACCKSpec -> SQL -> Clear ();
        DM -> QGIACCKSpec ->
            SQL ->
                Add (
                    " SELECT"                   \
                    "     SUM"                  \
                    "     ("                    \
                    "         kol_place"        \
                    "     )"                    \
                    " FROM"                     \
                    "     ck_plan"              \
                    " WHERE"                    \
                    "     n_specializ = 61"
                );

        DM -> QGIACCKSpec -> Open ();

        giac_val = DM -> QGIACCKSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                4,
                14
            );

        DM -> QGIACCKSpec -> Close ();



        DM -> QGIACCKSpec -> Close ();                                          // ПЛАН 'ЦЕЛЕВЫХ'  Спортивно-туристская деятельность (по направлениям)
        DM -> QGIACCKSpec -> SQL -> Clear ();
        DM -> QGIACCKSpec ->
            SQL ->
                Add (
                    " SELECT"                       \
                    "     SUM"                      \
                    "     ("                        \
                    "         kol_place"            \
                    "     )"                        \
                    " FROM"                         \
                    "     ck_plan"                  \
                    " WHERE"                        \
                    "         n_specializ = 51"     \
                    "     OR"                       \
                    "         n_specializ = 100"
                );

        DM -> QGIACCKSpec -> Open ();

        giac_val = DM -> QGIACCKSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                4,
                15
            );

        DM -> QGIACCKSpec -> Close ();



        DM -> QGIAC2kSpec -> Close ();                                          // ПЛАН '2 курс'  Физическая культура (по направлениям)
        DM -> QGIAC2kSpec -> SQL -> Clear ();
        DM -> QGIAC2kSpec ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     SUM"                          \
                    "     ("                            \
                    "         kol_place"                \
                    "     )"                            \
                    " FROM"                             \
                    "     kol_place"                    \
                    " WHERE"                            \
                    "         vid_edu = :vid_edu"       \
                    "     AND"                          \
                    "         price   = :price"         \
                    "     AND"                          \
                    "         ("                        \
                    "             text = 1"             \
                    "          OR"                      \
                    "             text = 2"             \
                    "         )"                        \
                    "     AND"                          \
                    "         ("                        \
                    "             n_specializ = 4"      \
                    "          OR"                      \
                    "             n_specializ = 57"     \
                    "         )"
                );

        DM -> QGIAC2kSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIAC2kSpec ->
            ParamByName ("price")   -> AsInteger = 0;

        DM -> QGIAC2kSpec -> Open ();

        giac_val = DM -> QGIAC2kSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                5,
                10
            );

        DM -> QGIAC2kSpec -> Close ();



        DM -> QGIAC2kSpec -> Close ();

        DM -> QGIAC2kSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIAC2kSpec ->
            ParamByName ("price")   -> AsInteger = 1;

        DM -> QGIAC2kSpec -> Open ();

        giac_val = DM -> QGIAC2kSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                7,
                10
            );

        DM -> QGIAC2kSpec -> Close ();



        DM -> QGIAC2kSpec -> Close ();                                          // ПЛАН '2 курс'  Оздоровительная и адаптивная физическая культура (по направлениям)
        DM -> QGIAC2kSpec -> SQL -> Clear ();
        DM -> QGIAC2kSpec ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     SUM"                          \
                    "     ("                            \
                    "         kol_place"                \
                    "     )"                            \
                    " FROM"                             \
                    "     kol_place"                    \
                    " WHERE"                            \
                    "         vid_edu = :vid_edu"       \
                    "     AND"                          \
                    "         price   = :price"         \
                    "     AND"                          \
                    "         ("                        \
                    "             text = 1"             \
                    "          OR"                      \
                    "             text = 2"             \
                    "         )"                        \
                    "     AND"                          \
                    "         ("                        \
                    "             n_specializ = 38"     \
                    "          OR"                      \
                    "             n_specializ = 39"     \
                    "         )"
                );

        DM -> QGIAC2kSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIAC2kSpec ->
            ParamByName ("price")   -> AsInteger = 0;

        DM -> QGIAC2kSpec -> Open ();

        giac_val = DM -> QGIAC2kSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                5,
                11
            );

        DM -> QGIAC2kSpec -> Close ();



        DM -> QGIAC2kSpec -> Close ();

        DM -> QGIAC2kSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIAC2kSpec ->
            ParamByName ("price")   -> AsInteger = 1;

        DM -> QGIAC2kSpec -> Open ();

        giac_val = DM -> QGIAC2kSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                7,
                11
            );

        DM -> QGIAC2kSpec -> Close ();



        DM -> QGIAC2kSpec -> Close ();                                          // ПЛАН '2 курс'  Физическая реабилитация и эрготерапия (по направлениям)
        DM -> QGIAC2kSpec -> SQL -> Clear ();
        DM -> QGIAC2kSpec ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     SUM"                          \
                    "     ("                            \
                    "         kol_place"                \
                    "     )"                            \
                    " FROM"                             \
                    "     kol_place"                    \
                    " WHERE"                            \
                    "         vid_edu     = :vid_edu"   \
                    "     AND"                          \
                    "         price       = :price"     \
                    "     AND"                          \
                    "         text        = 1"          \
                    "     AND"                          \
                    "         n_specializ = 3"
                );

        DM -> QGIAC2kSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIAC2kSpec ->
            ParamByName ("price")   -> AsInteger = 0;

        DM -> QGIAC2kSpec -> Open ();

        giac_val = DM -> QGIAC2kSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                5,
                12
            );

        DM -> QGIAC2kSpec -> Close ();



        DM -> QGIAC2kSpec -> Close ();

        DM -> QGIAC2kSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIAC2kSpec ->
            ParamByName ("price")   -> AsInteger = 1;

        DM -> QGIAC2kSpec -> Open ();

        giac_val = DM -> QGIAC2kSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                7,
                12
            );

        DM -> QGIAC2kSpec -> Close ();



        DM -> QGIAC2kSpec -> Close ();                                          // ПЛАН '2 курс'  Спортивно-педагогическая деятельность (по направлениям)
        DM -> QGIAC2kSpec -> SQL -> Clear ();
        DM -> QGIAC2kSpec ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     SUM"                          \
                    "     ("                            \
                    "         kol_place"                \
                    "     )"                            \
                    " FROM"                             \
                    "     kol_place"                    \
                    " WHERE"                            \
                    "         vid_edu = :vid_edu"       \
                    "     AND"                          \
                    "         price   = :price"         \
                    "     AND"                          \
                    "         text    = 1"              \
                    "     AND"                          \
                    "         ("                        \
                    "             n_specializ = 1"      \
                    "          OR"                      \
                    "             n_specializ = 7"      \
                    "          OR"                      \
                    "             n_specializ = 9"      \
                    "          OR"                      \
                    "             n_specializ = 10"     \
                    "          OR"                      \
                    "             n_specializ = 11"     \
                    "          OR"                      \
                    "             n_specializ = 12"     \
                    "          OR"                      \
                    "             n_specializ = 13"     \
                    "          OR"                      \
                    "             n_specializ = 15"     \
                    "          OR"                      \
                    "             n_specializ = 16"     \
                    "          OR"                      \
                    "             n_specializ = 17"     \
                    "          OR"                      \
                    "             n_specializ = 19"     \
                    "          OR"                      \
                    "             n_specializ = 20"     \
                    "          OR"                      \
                    "             n_specializ = 21"     \
                    "          OR"                      \
                    "             n_specializ = 23"     \
                    "          OR"                      \
                    "             n_specializ = 24"     \
                    "          OR"                      \
                    "             n_specializ = 25"     \
                    "          OR"                      \
                    "             n_specializ = 26"     \
                    "          OR"                      \
                    "             n_specializ = 27"     \
                    "          OR"                      \
                    "             n_specializ = 28"     \
                    "          OR"                      \
                    "             n_specializ = 29"     \
                    "          OR"                      \
                    "             n_specializ = 30"     \
                    "          OR"                      \
                    "             n_specializ = 32"     \
                    "          OR"                      \
                    "             n_specializ = 33"     \
                    "          OR"                      \
                    "             n_specializ = 35"     \
                    "          OR"                      \
                    "             n_specializ = 37"     \
                    "          OR"                      \
                    "             n_specializ = 42"     \
                    "          OR"                      \
                    "             n_specializ = 43"     \
                    "          OR"                      \
                    "             n_specializ = 44"     \
                    "          OR"                      \
                    "             n_specializ = 45"     \
                    "          OR"                      \
                    "             n_specializ = 48"     \
                    "          OR"                      \
                    "             n_specializ = 52"     \
                    "          OR"                      \
                    "             n_specializ = 54"     \
                    "          OR"                      \
                    "             n_specializ = 55"     \
                    "          OR"                      \
                    "             n_specializ = 66"     \
                    "          OR"                      \
                    "             n_specializ = 68"     \
                    "          OR"                      \
                    "             n_specializ = 69"     \
                    "          OR"                      \
                    "             n_specializ = 79"     \
                    "          OR"                      \
                    "             n_specializ = 80"     \
                    "          OR"                      \
                    "             n_specializ = 84"     \
                    "          OR"                      \
                    "             n_specializ = 87"     \
                    "          OR"                      \
                    "             n_specializ = 88"     \
                    "          OR"                      \
                    "             n_specializ = 94"     \
                    "          OR"                      \
                    "             n_specializ = 96"     \
                    "          OR"                      \
                    "             n_specializ = 115"    \
                    "          OR"                      \
                    "             n_specializ = 120"    \
                    "         )"
                );

        DM -> QGIAC2kSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;
        DM -> QGIAC2kSpec ->
            ParamByName ("price")   -> AsInteger = 0;
        DM -> QGIAC2kSpec -> Open ();

        giac_val = DM -> QGIAC2kSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                5,
                13
            );

        DM -> QGIAC2kSpec -> Close ();



        DM -> QGIAC2kSpec -> Close ();
        DM -> QGIAC2kSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;
        DM -> QGIAC2kSpec ->
            ParamByName ("price")   -> AsInteger = 1;
        DM -> QGIAC2kSpec -> Open ();

        giac_val = DM -> QGIAC2kSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                7,
                13
            );

        DM -> QGIAC2kSpec -> Close ();



        DM -> QGIAC2kSpec -> Close ();                                          // ПЛАН '2 курс'  Туризм и гостеприимство
        DM -> QGIAC2kSpec -> SQL -> Clear ();
        DM -> QGIAC2kSpec ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     SUM"                          \
                    "     ("                            \
                    "         kol_place"                \
                    "     )"                            \
                    " FROM"                             \
                    "     kol_place"                    \
                    " WHERE"                            \
                    "         vid_edu     = :vid_edu"   \
                    "     AND"                          \
                    "         price       = :price"     \
                    "     AND"                          \
                    "         text        = 1"          \
                    "     AND"                          \
                    "         n_specializ = 61"
                );


        DM -> QGIAC2kSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;
        DM -> QGIAC2kSpec ->
            ParamByName ("price")   -> AsInteger = 0;
        DM -> QGIAC2kSpec -> Open ();

        giac_val = DM -> QGIAC2kSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                5,
                14
            );

        DM -> QGIAC2kSpec -> Close ();



        DM -> QGIAC2kSpec -> Close ();

        DM -> QGIAC2kSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIAC2kSpec ->
            ParamByName ("price")   -> AsInteger = 1;

        DM -> QGIAC2kSpec -> Open ();

        giac_val = DM -> QGIAC2kSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                7,
                14
            );

        DM -> QGIAC2kSpec -> Close ();



        DM -> QGIAC2kSpec -> Close ();                                          // ПЛАН '2 курс'  Спортивно-туристская деятельность (по направлениям)
        DM -> QGIAC2kSpec -> SQL -> Clear ();
        DM -> QGIAC2kSpec ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     SUM"                          \
                    "     ("                            \
                    "         kol_place"                \
                    "     )"                            \
                    " FROM"                             \
                    "     kol_place"                    \
                    " WHERE"                            \
                    "         vid_edu = :vid_edu"       \
                    "     AND"                          \
                    "         price   = :price"         \
                    "     AND"                          \
                    "         text    = 1"              \
                    "     AND"                          \
                    "         ("                        \
                    "             n_specializ = 100"    \
                    "          OR"                      \
                    "             n_specializ = 51"     \
                    "         )"
                );

        DM -> QGIAC2kSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIAC2kSpec ->
            ParamByName ("price")   -> AsInteger = 0;

        DM -> QGIAC2kSpec -> Open ();

        giac_val = DM -> QGIAC2kSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                5,
                15
            );

        DM -> QGIAC2kSpec -> Close ();


        DM -> QGIAC2kSpec -> Close ();

        DM -> QGIAC2kSpec ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIAC2kSpec ->
            ParamByName ("price")   -> AsInteger = 1;

        DM -> QGIAC2kSpec -> Open ();

        giac_val = DM -> QGIAC2kSpecSUM -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                7,
                15
            );

        DM -> QGIAC2kSpec -> Close ();


        TDateTime date_in =                                                     // SECTION: ПОДАНО ВСЕГО
            StrToDateTime (
                Admissions::DEADLINE::FOR_RECEIVING_PART_1
            );


        DMStat -> Giaz01SP -> Close ();                                         // Физическая культура (по направлениям)

        DMStat -> Giaz01SP ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;

        DMStat -> Giaz01SP ->
            ParamByName ("n_spec")  -> AsSmallInt = 8;

        DMStat -> Giaz01SP ->
            ParamByName ("date_in") -> AsDateTime = date_in;

        DMStat -> Giaz01SP -> Prepare ();
        DMStat -> Giaz01SP -> ExecProc ();

        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_ALL") -> AsInteger,
            8,
            10
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_P")     -> AsInteger,
            11,
            10
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_CK")  -> AsInteger,
            9,
            10
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_2")   -> AsInteger,
            10,
            10
            );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_3S")    -> AsInteger,
            12,
            10
        );

        DMStat -> Giaz01SP -> Unprepare ();
        DMStat -> Giaz01SP -> Close ();



        DMStat -> Giaz01SP -> Close ();                                         // Оздоровительная и адаптивная физическая культура (по направлениям)

        DMStat -> Giaz01SP ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;

        DMStat -> Giaz01SP ->
            ParamByName ("n_spec")  -> AsSmallInt = 5;

        DMStat -> Giaz01SP ->
            ParamByName ("date_in") -> AsDateTime = date_in;

        DMStat -> Giaz01SP -> Prepare ();
        DMStat -> Giaz01SP -> ExecProc ();

        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_ALL") -> AsInteger,
            8,
            11
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_P")     -> AsInteger,
            11,
            11
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_CK")  -> AsInteger,
            9,
            11
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_2")   -> AsInteger,
            10,
            11
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_3S")    -> AsInteger,
            12,
            11
        );

        DMStat -> Giaz01SP -> Unprepare ();
        DMStat -> Giaz01SP -> Close ();



        DMStat -> Giaz01SP -> Close ();                                         // Физическая реабилитация и эрготерапия (по направлениям)

        DMStat -> Giaz01SP ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;

        DMStat -> Giaz01SP ->
            ParamByName ("n_spec")  -> AsSmallInt = 9;

        DMStat -> Giaz01SP ->
            ParamByName ("date_in") -> AsDateTime = date_in;

        DMStat -> Giaz01SP -> Prepare ();
        DMStat -> Giaz01SP -> ExecProc ();

        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_ALL") -> AsInteger,
            8,
            12
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_P")     -> AsInteger,
            11,
            12
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_CK")  -> AsInteger,
            9,
            12
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_2")   -> AsInteger,
            10,
            12
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_3S")    -> AsInteger,
            12,
            12
        );

        DMStat -> Giaz01SP -> Unprepare ();
        DMStat -> Giaz01SP -> Close ();



        DMStat -> Giaz01SP -> Close ();                                         // Спортивно-педагогическая деятельность (по направлениям)

        DMStat -> Giaz01SP ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;

        DMStat -> Giaz01SP ->
            ParamByName ("n_spec")  -> AsSmallInt = 6;

        DMStat -> Giaz01SP ->
            ParamByName ("date_in") -> AsDateTime = date_in;

        DMStat -> Giaz01SP -> Prepare ();
        DMStat -> Giaz01SP -> ExecProc ();

        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_ALL") -> AsInteger,
            8,
            13
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_P")     -> AsInteger,
            11,
            13
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_CK")  -> AsInteger,
            9,
            13
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_2")   -> AsInteger,
            10,
            13
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_3S")    -> AsInteger,
            12,
            13
        );

        DMStat -> Giaz01SP -> Unprepare ();
        DMStat -> Giaz01SP -> Close ();



        DMStat -> Giaz01SP -> Close ();                                         // Туризм и гостеприимство

        DMStat -> Giaz01SP ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;

        DMStat -> Giaz01SP ->
            ParamByName ("n_spec")  -> AsSmallInt = 10;

        DMStat -> Giaz01SP ->
            ParamByName ("date_in") -> AsDateTime = date_in;

        DMStat -> Giaz01SP -> Prepare ();
        DMStat -> Giaz01SP -> ExecProc ();

        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_ALL") -> AsInteger,
            8,
            14
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_P")     -> AsInteger,
            11,
            14
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_CK")  -> AsInteger,
            9,
            14
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_2")   -> AsInteger,
            10,
            14
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_3S")    -> AsInteger,
            12,
            14
        );

        DMStat -> Giaz01SP -> Unprepare ();
        DMStat -> Giaz01SP -> Close ();



        DMStat -> Giaz01SP -> Close ();                                         // Спортивно-туристская деятельность (по направлениям)

        DMStat -> Giaz01SP ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;

        DMStat -> Giaz01SP ->
            ParamByName ("n_spec")  -> AsSmallInt = 7;

        DMStat -> Giaz01SP ->
            ParamByName ("date_in") -> AsDateTime = date_in;

        DMStat -> Giaz01SP -> Prepare ();
        DMStat -> Giaz01SP -> ExecProc ();

        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_ALL") -> AsInteger,
            8,
            15
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_P")     -> AsInteger,
            11,
            15
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_CK")  -> AsInteger,
            9,
            15
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_B_2")   -> AsInteger,
            10,
            15
        );
        CellValue (
            DMStat -> Giaz01SP ->
                ParamByName ("S_3S")    -> AsInteger,
            12,
            15
        );

        DMStat -> Giaz01SP -> Unprepare ();
        DMStat -> Giaz01SP -> Close ();



        Sheet =                                                                 // РАЗДЕЛ II.1
            SelectSheet (
                Workbook,
                "РАЗДЕЛ II.1"
            );


        DMStat -> GIAZ021SP -> Close ();                                        // Всего подано

        DMStat -> GIAZ021SP ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;

        DMStat -> GIAZ021SP ->
            ParamByName ("date_in") -> AsDateTime = date_in;

        DMStat -> GIAZ021SP -> Prepare ();
        DMStat -> GIAZ021SP -> ExecProc ();

        CellValue (
            DMStat -> GIAZ021SP ->
                ParamByName ("S_ALL") -> AsInteger,
            8,
            11
        );
        CellValue (
            DMStat -> GIAZ021SP ->
                ParamByName ("S_17")  -> AsInteger,
            4,
            11
        );
        CellValue (
            DMStat -> GIAZ021SP ->
                ParamByName ("S_16")  -> AsInteger,
            6,
            11
        );

        DMStat -> GIAZ021SP -> Unprepare ();
        DMStat -> GIAZ021SP -> Close ();



        Sheet =                                                                 // РАЗДЕЛ II.2
            SelectSheet (
                Workbook,
                "РАЗДЕЛ II.2"
            );


        DMStat -> Giaz022SP -> Close ();

        DMStat -> Giaz022SP ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;

        DMStat -> Giaz022SP ->
            ParamByName ("date_in") -> AsDateTime = date_in;

        DMStat -> Giaz022SP -> Prepare ();
        DMStat -> Giaz022SP -> ExecProc ();

        CellValue (
            DMStat -> GIAZ021SP ->
                ParamByName ("S_ALL") -> AsInteger,
            3,
            11
        );

        DMStat -> Giaz022SP -> Unprepare ();
        DMStat -> Giaz022SP -> Close ();



        Sheet =                                                                 // РАЗДЕЛ III
            SelectSheet (
                Workbook,
                "РАЗДЕЛ III"
            );



        // DM -> QGIACEdOSred -> Close ();                                         // Общее среднее QGIACEdOSred  !

        // DM -> QGIACEdOSred ->
        //     ParamByName ("vid_edu")   -> AsInteger = vid_educ;

        // DM -> QGIACEdOSred ->
        //     ParamByName ("education") -> AsInteger = 0;

        // DM -> QGIACEdOSred -> Open ();

        // CellValue (
        //     DM -> QGIACEdOSredCOUNT -> Value,
        //     2,
        //     9
        // );

        // DM -> QGIACEdOSred -> Close ();



        DM -> QGIACEdOSredCity -> Close ();                                     // Общее среднее город

        DM -> QGIACEdOSredCity ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACEdOSredCity -> Open ();

        giac_val = DM -> QGIACEdOSredCityCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                2,
                9
            );

        DM -> QGIACEdOSredCity -> Close ();


        DM -> QGIACEdOSredVil -> Close ();                                      // Общее среднее село

        DM -> QGIACEdOSredVil ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;

        DM -> QGIACEdOSredVil -> Open ();

        giac_val = DM -> QGIACEdOSredVilCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                4,
                9
            );

        DM -> QGIACEdOSredVil -> Close ();


        DM -> QGIACYearSredCity -> Close ();                                    // Год окончания среднего город QGIACYearSred  !
        DM -> QGIACYearSredCity ->
            ParamByName ("vid_edu") -> AsInteger =
                vid_educ;
        DM -> QGIACYearSredCity ->
            ParamByName ("year") -> AsInteger =
                StrToInt (
                    Admissions::TIME::YEAR
                );
        DM -> QGIACYearSredCity -> Open ();

        giac_val = DM -> QGIACYearSredCityCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                3,
                9
            );

        DM -> QGIACYearSredCity -> Close ();



        DM -> QGIACYearSredVil -> Close ();                                     // Год окончания среднего село QGIACYearSred  !
        DM -> QGIACYearSredVil ->
            ParamByName ("vid_edu") -> AsInteger =
                vid_educ;
        DM -> QGIACYearSredVil ->
            ParamByName ("year")    -> AsInteger =
                StrToInt (
                    Admissions::TIME::YEAR
                );
        DM -> QGIACYearSredVil -> Open ();

        giac_val = DM -> QGIACYearSredVilCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                5,
                9
            );

        DM -> QGIACYearSredVil -> Close ();



        DM -> QGIACEdLic -> Close ();                                           // Среднее лицеи QGIACEdLic !
        DM -> QGIACEdLic ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;
        DM -> QGIACEdLic -> Open ();

        giac_val = DM -> QGIACEdLicCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                6,
                9
            );

        DM -> QGIACEdLic -> Close ();



        DM -> QGIACEdOSred -> Close ();                                         // Среднее специальное QGIACEdOSred !
        DM -> QGIACEdOSred ->
            ParamByName ("vid_edu")   -> AsInteger = vid_educ;
        DM -> QGIACEdOSred ->
            ParamByName ("education") -> AsInteger = 1;

        DM -> QGIACEdOSred -> Open ();

        giac_val = DM -> QGIACEdOSredCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                7,
                9
            );

        DM -> QGIACEdOSred -> Close ();



        DM -> QGIACYearSredSpec -> Close ();                                    // Год окончания средне-специального QGIACYearSredSpec  !
        DM -> QGIACYearSredSpec ->
            ParamByName ("vid_edu") -> AsInteger =
                vid_educ;
        DM -> QGIACYearSredSpec ->
            ParamByName ("year")    -> AsInteger =
                StrToInt (
                    Admissions::TIME::YEAR
                );
        DM -> QGIACYearSredSpec ->
            ParamByName ("education") -> AsInteger = 1;
        DM -> QGIACYearSredSpec -> Open ();

        giac_val = DM -> QGIACYearSredSpecCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                8,
                9
            );

        DM -> QGIACYearSredSpec -> Close ();


        DM -> QGIACEdOSred -> Close ();                                         // ПТУ QGIACEdOSred  !
        DM -> QGIACEdOSred ->
            ParamByName ("vid_edu")   -> AsInteger = vid_educ;
        DM -> QGIACEdOSred ->
            ParamByName ("education") -> AsInteger = 4;
        DM -> QGIACEdOSred -> Open ();

        giac_val = DM -> QGIACEdOSredCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                9,
                9
            );

        DM -> QGIACEdOSred -> Close ();


        DM -> QGIACYearSredSpec -> Close ();                                    // Год окончания ПТУ QGIACYearSredSpec   !
        DM -> QGIACYearSredSpec ->
            ParamByName ("vid_edu") -> AsInteger =
                vid_educ;
        DM -> QGIACYearSredSpec ->
            ParamByName ("year")    -> AsInteger =
                StrToInt (
                    Admissions::TIME::YEAR
                );
        DM -> QGIACYearSredSpec ->
            ParamByName ("education") -> AsInteger = 4;
        DM -> QGIACYearSredSpec -> Open ();

        giac_val = DM -> QGIACYearSredSpecCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                10,
                9
            );

        DM -> QGIACYearSredSpec -> Close ();


        DM -> QGIACEdOSred -> Close ();                                         // ВУЗ QGIACEdOSred  !
        DM -> QGIACEdOSred ->
            ParamByName ("vid_edu")   -> AsInteger = vid_educ;
        DM -> QGIACEdOSred ->
            ParamByName ("education") -> AsInteger = 3;
        DM -> QGIACEdOSred -> Open ();

        giac_val = DM -> QGIACEdOSredCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                11,
                9
            );

        DM -> QGIACEdOSred -> Close ();


        DM -> QGIACForeigner -> Close ();                                       // Иностранцы QGIACForeigner
        DM -> QGIACForeigner ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;
        DM -> QGIACForeigner -> Open ();
        giac_val = DM -> QGIACForeignerCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                12,
                9
            );

        DM -> QGIACForeigner -> Close ();
    }
    else                                                                        // ФОРМА 2 - зачисление абитуриентов
    {
        Sheet =                                                                 // ТИТУЛЬНЫЙ ЛИСТ
            SelectSheet (
                Workbook,
                "ОТЧЕТ"
            );


        if (vid_educ)
        {
            CellValue (
                "в заочной форме получения образования",
                3,
                18
            );
            CellValue (
                "в заочной форме получения образования",
                3,
                28
            );
        }
        else
        {
            CellValue (
                "в дневной форме получения образования",
                3,
                18
            );
            CellValue (
                "в дневной форме получения образования",
                3,
                28
            );
        }



        Sheet =                                                                 // ТАБЛИЦА 1
            SelectSheet (
                Workbook,
                "РАЗДЕЛ I"
            );



        for ( int i = 0;                                                        // Сдававшие и выдержавшие вступительные испытания (int Kol_VI;)
                  i < 6;
                  ++i
            )
        {
            DMVed -> GIAZ2_1_1StrdPrc -> Close ();                              // Сдававшие вступительные испытания
            DMVed -> GIAZ2_1_1StrdPrc ->
                ParamByName ("VID_EDU") -> AsSmallInt =
                        vid_educ;
            DMVed -> GIAZ2_1_1StrdPrc ->
                ParamByName ("N_SPEC") -> AsSmallInt =
                        N_Spec[i];
            DMVed -> GIAZ2_1_1StrdPrc -> Prepare ();
            DMVed -> GIAZ2_1_1StrdPrc -> ExecProc ();

            giac_val =
                DMVed -> GIAZ2_1_1StrdPrc ->
                    ParamByName ("SUM1") -> Value;

            CellValue (
                giac_val,
                3,
                razd1 + i
            );
        }



        DMVed -> GIAZ2_1_3Qr -> Close ();                                       // 'Туризм и гостеприимство' зачисленных по 3-м сертификатам (ИТ and 1 курс)
        DMVed -> GIAZ2_1_3Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_1_3Qr -> Open ();

        giac_val = DMVed -> GIAZ2_1_3QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                5,
                14
            );

        DMVed -> GIAZ2_1_3Qr -> Close ();



        for ( int i = 0;                                                        // зачислены БВИ
                  i < 6;
                  ++i
            )
        {
            int bvi = 0;

            DMVed -> GIAZ2_1_4Qr -> Close ();                                   // БВИ по конкурсу
            DMVed -> GIAZ2_1_4Qr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_4Qr ->
                ParamByName ("n_spec")  -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_4Qr -> Open ();

            bvi = DMVed -> GIAZ2_1_4QrCOUNT -> Value;

            DMVed -> GIAZ2_1_4Qr -> Close ();


            DMVed -> GIAZ2_1_4_ckQr -> Close ();                                // ЦК с признаками БВИ
            DMVed -> GIAZ2_1_4_ckQr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_4_ckQr ->
                ParamByName ("n_spec")  -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_4_ckQr -> Open ();

            bvi += DMVed -> GIAZ2_1_4_ckQrCOUNT -> Value;

            CellValue (
                bvi,
                6,
                razd1 + i
            );

            DMVed -> GIAZ2_1_4_ckQr -> Close ();
        }



        for ( int i = 0;                                                        // зачислены ВК
                  i < 6;
                  ++i
            )
        {
            int vk = 0;

            DMVed -> GIAZ2_1_5Qr -> Close ();                                   // ВК по конкурсу
            DMVed -> GIAZ2_1_5Qr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_5Qr ->
                ParamByName ("n_spec")  -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_5Qr -> Open ();

            vk = DMVed -> GIAZ2_1_5QrCOUNT -> Value;

            DMVed -> GIAZ2_1_5Qr -> Close ();



            DMVed -> GIAZ2_1_5_ckQr -> Close ();                                // ЦК с признаками ВК
            DMVed -> GIAZ2_1_5_ckQr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_5_ckQr ->
                ParamByName ("n_spec")  -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_5_ckQr -> Open ();

            vk += DMVed -> GIAZ2_1_5_ckQrCOUNT -> Value;

            CellValue (
                vk,
                7,
                razd1 + i
            );

            DMVed -> GIAZ2_1_5_ckQr -> Close ();
        }



        for ( int i = 0;                                                        // зачислены всего на бюджет
                  i < 6;
                  ++i
            )
        {
            DMVed -> GIAZ2_1_6Qr -> Close ();
            DMVed -> GIAZ2_1_6Qr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_6Qr ->
                ParamByName ("n_spec") -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_6Qr -> Open ();

            giac_val = DMVed -> GIAZ2_1_6QrCOUNT -> Value;

            if (giac_val)
                CellValue (
                    giac_val,
                    8,
                    razd1 + i
                );

            DMVed -> GIAZ2_1_6Qr -> Close ();
        }



        for ( int i = 0;                                                        // зачислены по доп. набору
                  i < 6;
                  ++i
            )
        {
            DMVed -> GIAZ2_1_7Qr -> Close ();

            DMVed -> GIAZ2_1_7Qr ->
                ParamByName ("vid_edu")          -> AsSmallInt   =
                        vid_educ;
            DMVed -> GIAZ2_1_7Qr ->
                ParamByName ("n_spec")           -> AsSmallInt   =
                        N_Spec[i];
            DMVed -> GIAZ2_1_7Qr ->                                             // !!! Дата приказа доп. набора
                ParamByName ("d_prikaz_include") -> AsAnsiString =
                        Admissions::ADDITIONAL::ORDER_DATE_PART_1;

            DMVed -> GIAZ2_1_7Qr -> Open ();

            giac_val = DMVed -> GIAZ2_1_7QrCOUNT -> Value;

            if (giac_val)
                CellValue (
                    giac_val,
                    9,
                    razd1 + i
                );

            DMVed -> GIAZ2_1_7Qr -> Close ();
        }

                                                                                // Донец-кой и Луганс-кой 2017 - нет!!!

        for ( int i = 0;                                                        // зачислены целевая подготовка
                  i < 6;
                  ++i
            )
        {
            DMVed -> GIAZ2_1_9Qr -> Close ();
            DMVed -> GIAZ2_1_9Qr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_9Qr ->
                ParamByName ("n_spec")  -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_9Qr -> Open ();

            giac_val = DMVed -> GIAZ2_1_9QrCOUNT -> Value;

            if (giac_val)
                CellValue (
                    giac_val,
                    11,
                    razd1 + i
                );

            DMVed -> GIAZ2_1_9Qr -> Close ();
        }



        for ( int i = 0;                                                        // зачислены бюджет,сокращённая форма
                  i < 6;
                  ++i
            )
        {
            DMVed -> GIAZ2_1_10Qr -> Close ();
            DMVed -> GIAZ2_1_10Qr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_10Qr ->
                ParamByName ("n_spec")  -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_10Qr -> Open ();

            giac_val = DMVed -> GIAZ2_1_10QrCOUNT -> Value;

            if (giac_val)
                CellValue (
                    giac_val,
                    12,
                    razd1 + i
                );

            DMVed -> GIAZ2_1_10Qr -> Close ();
        }



        for ( int i = 0;                                                        // Для получения 2-го высшего
                  i < 6;
                  ++i
            )
        {
            DMVed -> GIAZ2_1_11Qr -> Close ();
            DMVed -> GIAZ2_1_11Qr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_11Qr ->
                ParamByName ("n_spec")  -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_11Qr -> Open ();

            giac_val = DMVed -> GIAZ2_1_11QrCOUNT -> Value;

            if (giac_val)
                CellValue (
                    giac_val,
                    13,
                    razd1 + i
                );

            DMVed -> GIAZ2_1_11Qr -> Close ();
        }



        for ( int i = 0;                                                        // зачислены всего за оплату
                  i < 6;
                  ++i
            )
        {
            DMVed -> GIAZ2_1_12Qr -> Close ();
            DMVed -> GIAZ2_1_12Qr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_12Qr ->
                ParamByName ("n_spec")  -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_12Qr -> Open ();

            giac_val = DMVed -> GIAZ2_1_12QrCOUNT -> Value;

            if (giac_val)
                CellValue (
                    giac_val,
                    14,
                    razd1 + i
                );

            DMVed -> GIAZ2_1_12Qr -> Close ();
        }



        for ( int i = 0;                                                        // зачислены за оплату,сокращённая форма
                  i < 6;
                  ++i
            )
        {
            DMVed -> GIAZ2_1_13Qr -> Close ();
            DMVed -> GIAZ2_1_13Qr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_13Qr ->
                ParamByName ("n_spec")  -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_13Qr -> Open ();

            giac_val = DMVed -> GIAZ2_1_13QrCOUNT -> Value;

            if (giac_val)
                CellValue (
                    giac_val,
                    15,
                    razd1 + i
                );

            DMVed -> GIAZ2_1_13Qr -> Close ();
        }



        for ( int i = 0;                                                        // зачислены за оплату, 2-ое высшее
                  i < 6;
                  ++i
            )
        {
            DMVed -> GIAZ2_1_14Qr -> Close ();
            DMVed -> GIAZ2_1_14Qr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_14Qr ->
                ParamByName ("n_spec")  -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_14Qr -> Open ();

            giac_val = DMVed -> GIAZ2_1_14QrCOUNT -> Value;

            if (giac_val)
                CellValue (
                    giac_val,
                    16,
                    razd1 + i
                );

            DMVed -> GIAZ2_1_14Qr -> Close ();
        }



        Sheet =                                                                 // ТАБЛИЦА 2 - сведения о категориях зачисленных
            SelectSheet (
                Workbook,
                "РАЗДЕЛ II т.2"
            );


        int bvi = 0;                                                            // Всего БВИ


        DMVed -> GIAZ2_2_1Qr -> Close ();                                       // БВИ по конкурсу
        DMVed -> GIAZ2_2_1Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_2_1Qr -> Open ();

        bvi = DMVed -> GIAZ2_2_1QrCOUNT -> Value;

        DMVed -> GIAZ2_2_1Qr -> Close ();


        DMVed -> GIAZ2_2_1ckQr -> Close ();                                     // ЦК с БВИ
        DMVed -> GIAZ2_2_1ckQr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_2_1ckQr -> Open ();

        bvi += DMVed -> GIAZ2_2_1ckQrCOUNT -> Value;

        CellValue (
            bvi,
            2,
            9
        );

        DMVed -> GIAZ2_2_1ckQr -> Close ();


        DMVed -> GIAZ2_2_2Qr -> Close ();                                       // Победители межд. и респ. олимпиад по учебным предметам
        DMVed -> GIAZ2_2_2Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_2_2Qr -> Open ();

        giac_val = DMVed -> GIAZ2_2_2QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                3,
                9
            );

        DMVed -> GIAZ2_2_2Qr -> Close ();


        DMVed -> GIAZ2_2_4Qr -> Close ();                                       // лауреаты спец. фондов Президента РБ
        DMVed -> GIAZ2_2_4Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_2_4Qr -> Open ();

        giac_val = DMVed -> GIAZ2_2_4QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                5,
                9
            );

        DMVed -> GIAZ2_2_4Qr -> Close ();


        DMVed -> GIAZ2_2_6Qr -> Close ();                                       // на специальность физической культуры и спорта
        DMVed -> GIAZ2_2_6Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_2_6Qr -> Open ();

        giac_val = DMVed -> GIAZ2_2_6QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                7,
                9
            );

        DMVed -> GIAZ2_2_6Qr -> Close ();



        Sheet =                                                                 // ТАБЛИЦА 3 - сведения о категориях зачисленных
            SelectSheet (
                Workbook,
                "РАЗДЕЛ II т.3"
            );


        int vk = 0;                                                             // Вне конкурса


        DMVed -> GIAZ2_3_1Qr -> Close ();                                       // БВИ по конкурсу
        DMVed -> GIAZ2_3_1Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_3_1Qr -> Open ();

        vk = DMVed -> GIAZ2_3_1QrCOUNT -> Value;

        DMVed -> GIAZ2_3_1Qr -> Close ();


        DMVed -> GIAZ2_3_1ckQr -> Close ();                                     // ЦК с признаками БВИ
        DMVed -> GIAZ2_3_1ckQr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_3_1ckQr -> Open ();

        vk += DMVed -> GIAZ2_3_1ckQrCOUNT -> Value;

        CellValue (
            vk,
            2,
            9
        );

        DMVed -> GIAZ2_3_1ckQr -> Close ();



        DMVed -> GIAZ2_3_2Qr -> Close ();                                       // Дети-сироты GIAZ2_3_2Qr
        DMVed -> GIAZ2_3_2Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_3_2Qr -> Open ();

        giac_val = DMVed -> GIAZ2_3_2QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                3,
                9
            );

        DMVed -> GIAZ2_3_2Qr -> Close ();


        DMVed -> GIAZ2_3_3Qr -> Close ();                                       // Почётный караул GIAZ2_3_3Qr
        DMVed -> GIAZ2_3_3Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_3_3Qr -> Open ();

        giac_val = DMVed -> GIAZ2_3_3QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                4,
                9
            );

        DMVed -> GIAZ2_3_3Qr -> Close ();


        DMVed -> GIAZ2_3_4Qr -> Close ();                                       // На спец физ.культ. GIAZ2_3_4Qr
        DMVed -> GIAZ2_3_4Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_3_4Qr -> Open ();

        giac_val = DMVed -> GIAZ2_3_4QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                5,
                9
            );

        DMVed -> GIAZ2_3_4Qr -> Close ();


        DMVed -> GIAZ2_3_6Qr -> Close ();                                       // Дети-инвалиды I и II групп  GIAZ2_3_6Qr
        DMVed -> GIAZ2_3_6Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_3_6Qr -> Open ();

        giac_val = DMVed -> GIAZ2_3_6QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                7,
                9
            );

        DMVed -> GIAZ2_3_6Qr -> Close ();


        DMVed -> GIAZ2_3_7Qr -> Close ();                                       // С медалью УСО
        DMVed -> GIAZ2_3_7Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_3_7Qr -> Open ();

        giac_val = DMVed -> GIAZ2_3_7QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                8,
                9
            );

        DMVed -> GIAZ2_3_7Qr -> Close ();


        DMVed -> GIAZ2_3_8Qr -> Close ();                                       // С медалью УССО
        DMVed -> GIAZ2_3_8Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_3_8Qr -> Open ();

        giac_val = DMVed -> GIAZ2_3_8QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                9,
                9
            );

        DMVed -> GIAZ2_3_8Qr -> Close ();


        DMVed -> GIAZ2_3_9Qr -> Close ();                                       // С медалью ПТУ
        DMVed -> GIAZ2_3_9Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_3_9Qr -> Open ();

        giac_val = DMVed -> GIAZ2_3_9QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                10,
                9
            );

        DMVed -> GIAZ2_3_9Qr -> Close ();


        Sheet =                                                                 // ТАБЛИЦА 4 - сведения о количестве зачисленных (проходной балл)
            SelectSheet (
                Workbook,
                "РАЗДЕЛ III"
            );


        DMVed -> GIAZ2_4_1Qr -> Close ();                                       // УСО город всего
        DMVed -> GIAZ2_4_1Qr -> SQL -> Clear ();
        DMVed -> GIAZ2_4_1Qr ->
            SQL -> Add (
                    " SELECT"                           \
                    "     COUNT"                        \
                    "     ("                            \
                    "         nomer_ab"                 \
                    "     )"                            \
                    " FROM"                             \
                    "     abitura"
                );
        DMVed -> GIAZ2_4_1Qr ->
            SQL -> Add (
                    " WHERE"                            \
                    "         status      = 5"
                );
        DMVed -> GIAZ2_4_1Qr ->
            SQL -> Add (
                    "     AND"                          \
                    "         vid_edu     = :vid_edu"   \
                );
        DMVed -> GIAZ2_4_1Qr ->
            SQL -> Add (
                    "     AND"                          \
                    "         category_if = 0"          \
                );
        DMVed -> GIAZ2_4_1Qr ->
            SQL -> Add (
                    "     AND"                          \
                    "         term_edu    < 5"          \
                );
        DMVed -> GIAZ2_4_1Qr ->
            SQL -> Add (
                    "     AND"                          \
                    "         town_village = 0"         \
                );
        DMVed -> GIAZ2_4_1Qr ->
            SQL -> Add (
                    "     AND"                          \
                    "         ("                        \
                    "             type_school = 0"      \
                    "          OR"                      \
                    "             type_school = 3"      \
                    "         )"                        \
                );

        DMVed -> GIAZ2_4_1Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_4_1Qr -> Open ();

        giac_val = DMVed -> GIAZ2_4_1QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                2,
                9
            );

        DMVed -> GIAZ2_4_1Qr -> Close ();


        DMVed -> GIAZ2_4_1Qr -> Close ();                                       // УСО город в этом году
        DMVed -> GIAZ2_4_1Qr ->
            SQL -> Add (
                    "     AND"                          \
                    "         when_edu_middle = "     +
                        Admissions::TIME::YEAR
                );
        DMVed -> GIAZ2_4_1Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_4_1Qr -> Open ();

        giac_val = DMVed -> GIAZ2_4_1QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                3,
                9
            );

        DMVed -> GIAZ2_4_1Qr -> Close ();


        DMVed -> GIAZ2_4_3Qr -> Close ();                                       // УСО село всего
        DMVed -> GIAZ2_4_3Qr -> SQL -> Clear ();
        DMVed -> GIAZ2_4_3Qr ->
            SQL -> Add (
                    " SELECT"                           \
                    "     COUNT"                        \
                    "     ("                            \
                    "         nomer_ab"                 \
                    "     )"                            \
                    " FROM"                             \
                    "     abitura"
                );
        DMVed -> GIAZ2_4_3Qr ->
            SQL -> Add (
                    " WHERE"                            \
                    "         status       = 5"
                );
        DMVed -> GIAZ2_4_3Qr ->
            SQL -> Add (
                    "     AND"                          \
                    "         vid_edu      = :vid_edu"
                );
        DMVed -> GIAZ2_4_3Qr ->
            SQL -> Add (
                    "     AND"                          \
                    "         category_if  = 0"
                );
        DMVed -> GIAZ2_4_3Qr ->
            SQL -> Add (
                    "     AND"                          \
                    "         term_edu     < 5"
                );
        DMVed -> GIAZ2_4_3Qr ->
            SQL -> Add (
                    "     AND"                          \
                    "         town_village = 1"
                );
        DMVed -> GIAZ2_4_3Qr ->
            SQL -> Add (
                    "     AND"                          \
                    "         ("                        \
                    "             type_school = 0"      \
                    "          OR"                      \
                    "             type_school = 3"      \
                    "         )"
                );
        DMVed -> GIAZ2_4_3Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_4_3Qr -> Open ();

        giac_val = DMVed -> GIAZ2_4_3QrCOUNT -> Value;

            CellValue (
                giac_val,
                4,
                9
            );

        DMVed -> GIAZ2_4_3Qr -> Close ();


        DMVed -> GIAZ2_4_3Qr -> Close ();                                       // УСО село в этом году
        DMVed -> GIAZ2_4_3Qr ->
            SQL -> Add (
                    "     AND"                          \
                    "         when_edu_middle = "     +
                            Admissions::TIME::YEAR
                );
        DMVed -> GIAZ2_4_3Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_4_3Qr -> Open ();

        giac_val = DMVed -> GIAZ2_4_3QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                5,
                9
            );

        DMVed -> GIAZ2_4_3Qr -> Close ();


        DMVed -> GIAZ2_4_5Qr -> Close ();                                       // лицеи и гимназии
        DMVed -> GIAZ2_4_5Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_4_5Qr -> Open ();

        giac_val = DMVed -> GIAZ2_4_5QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                6,
                9
            );

        DMVed -> GIAZ2_4_5Qr -> Close ();


        DMVed -> GIAZ2_4_6Qr -> Close ();                                       // УССО город всего
        DMVed -> GIAZ2_4_6Qr -> SQL -> Clear ();
        DMVed -> GIAZ2_4_6Qr ->
            SQL -> Add (
                    " SELECT"                               \
                    "     COUNT"                            \
                    "     ("                                \
                    "         nomer_ab"                     \
                    "     )"                                \
                    " FROM"                                 \
                    "     abitura"
                );
        DMVed -> GIAZ2_4_6Qr ->
            SQL -> Add (
                    " WHERE"                                \
                    "         status        = 5"
                );
        DMVed -> GIAZ2_4_6Qr ->
            SQL -> Add (
                    "     AND"                              \
                    "         vid_edu       = :vid_edu"
                );
        DMVed -> GIAZ2_4_6Qr ->
            SQL -> Add (
                    "     AND"                              \
                    "         category_if   = 0"
                );
        DMVed -> GIAZ2_4_6Qr ->
            SQL -> Add (
                    "     AND"                              \
                    "         term_edu      < 5"
                );
        DMVed -> GIAZ2_4_6Qr ->
            SQL -> Add (
                    "     AND"                              \
                    "         type_school   = 1"
                );
        DMVed -> GIAZ2_4_6Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_4_6Qr -> Open ();

        giac_val = DMVed -> GIAZ2_4_6QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                7,
                9
            );

        DMVed -> GIAZ2_4_6Qr -> Close ();


        DMVed -> GIAZ2_4_6Qr -> Close ();                                       // УССО город в этом году
        DMVed -> GIAZ2_4_6Qr ->
            SQL -> Add (
                    "     AND"                              \
                    "         when_edu_spec = "             +
                            Admissions::TIME::YEAR
                );
        DMVed -> GIAZ2_4_6Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_4_6Qr -> Open ();

        giac_val = DMVed -> GIAZ2_4_6QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                8,
                9
            );

        DMVed -> GIAZ2_4_6Qr -> Close ();


        DMVed -> GIAZ2_4_8Qr -> Close ();                                       // ПТУ город всего
        DMVed -> GIAZ2_4_8Qr -> SQL -> Clear ();
        DMVed -> GIAZ2_4_8Qr ->
            SQL -> Add (
                    " SELECT"                               \
                    "     COUNT"                            \
                    "     ("                                \
                    "         nomer_ab"                     \
                    "     )"                                \
                    " FROM"                                 \
                    "     abitura"
                );
        DMVed -> GIAZ2_4_8Qr ->
            SQL -> Add (
                    " WHERE"                                \
                    "         status   = 5"
                );
        DMVed -> GIAZ2_4_8Qr ->
            SQL -> Add (
                    "     AND"                              \
                    "         vid_edu     = :vid_edu"
                );
        DMVed -> GIAZ2_4_8Qr ->
            SQL -> Add (
                    "     AND"                              \
                    "         category_if = 0"
                );
        DMVed -> GIAZ2_4_8Qr ->
            SQL -> Add (
                    "     AND"                              \
                    "         term_edu    < 5"
                );
        DMVed -> GIAZ2_4_8Qr ->
            SQL -> Add (
                    "     AND"                              \
                    "         type_school = 2"
                );
        DMVed -> GIAZ2_4_8Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_4_8Qr -> Open ();

        giac_val = DMVed -> GIAZ2_4_8QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                9,
                9
            );

        DMVed -> GIAZ2_4_8Qr -> Close ();


        DMVed -> GIAZ2_4_8Qr -> Close ();                                       // ПТУ город в этом году
        DMVed -> GIAZ2_4_8Qr ->
            SQL -> Add (
                    "     AND"                              \
                    "         when_edu_spec = "             +
                            Admissions::TIME::YEAR
                );
        DMVed -> GIAZ2_4_8Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_4_8Qr -> Open ();

        giac_val = DMVed -> GIAZ2_4_8QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                10,
                9
            );

        DMVed -> GIAZ2_4_8Qr -> Close ();


        DMVed -> GIAZ2_4_10Qr -> Close ();                                      // УВО город всего
        DMVed -> GIAZ2_4_10Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_4_10Qr -> Open ();

        giac_val = DMVed -> GIAZ2_4_10QrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                11,
                9
            );

        DMVed -> GIAZ2_4_10Qr -> Close ();


        DMVed -> GIAZInQr -> Close ();
        DMVed -> GIAZInQr ->
            ParamByName ("vid_edu") -> AsInteger = vid_educ;
        DMVed -> GIAZInQr -> Open ();

        giac_val = DMVed -> GIAZInQrCOUNT -> Value;

        if (giac_val)
            CellValue (
                giac_val,
                12,
                9
            );

        DMVed -> GIAZInQr -> Close ();
    }


    AnsiString n_file = "Ведомственная отчетность БГУФК ";


    switch (form)
    {
        case 1:
                n_file += " прием ";
            break;
        case 2:
                n_file += " зачисление ";
            break;
        case 3:
                n_file += " зачисление бюджет ";
            break;
    }

    if (vid_educ)
        n_file += " заочная ";
    else
        n_file += " дневная ";

    n_file +=
        "за "                                   +
            AnsiToUtf8 (cur_d.CurrentDate ())   +
        ".xls";

    OVisible (ExcelApplication);

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );

    ExcelApplication.Clear ();
}
void __fastcall TMainForm::FormActivate (TObject * Sender)
{
    if (nom_fac != 3)
        N26 -> Enabled = true;                                                  // Сводная ведомость на 2 курс [INVISIBLE]

    #ifndef NEW_EXAM_SUMMARY_LISTS
    N33 -> Caption = "Ведомости по направлениям";
    #else
    #ifndef TEST_EXAMEN_UNIT
    N4  -> Visible = false;
    #else
    N4  -> Visible = true;
    #endif  // ! TEST_EXAMEN_UNIT
    N33 -> Caption = "Вед., инстр., контр. упр";
    #endif  // ! NEW_EXAM_SUMMARY_LISTS

    #ifndef SHOW_EXTRA_BUTTONS
    N32 -> Visible = false;                                                     // Статистика -> Формы для отчетов -> Подано заявлений (итоговая)       [TODO: create distribute method as N43]
    N44 -> Visible = false;                                                     // Статистика -> Формы для отчетов -> Подано заявлений по направлениям  [TODO: create distribute method as N43]
    N55 -> Visible = false;                                                     // Статистика - Конкурс     [Use Abitur_RIO instead!!!]
    #endif  // ! SHOW_EXTRA_BUTTONS

    if (nom_fac == 4)
    {
        // N4  -> Enabled = false;                                                 // Ведомости
        N5  -> Enabled = true;                                                  // Результаты
        N6  -> Enabled = false;                                                 // Аппеляции
        N16 -> Enabled = true;                                                  // Восстановление по справке
        // N22 -> Enabled = false;                                                 // Сводная ведомость дневная
        N26 -> Enabled = true;                                                  // Ведомость на МвТ и ЭВ
        N27 -> Enabled = false;                                                 // Сводная ведомость заочная
        N33 -> Enabled = true;                                                  // Ведомость на СФП и ОФП
    }


    MainForm -> Caption =
        "Абитуриент  - "            +
            DM -> TFaculty ->
                Lookup (
                    "N_FAC",
                    nom_fac,
                    "FAC"
                )                   +
        "       (версия "           +
            DM -> get_version ()    +
        ")   "                      +
        TextTest;


    if (st_developer)                                                           // Приказ на зачисление только для программиста
    {
        N35 -> Enabled = true;                                                  // Приказ на зачисление
        N20 -> Enabled = true;                                                  // Министерство образования
        N9  -> Enabled = true;                                                  // ГИАЦ
        N36 -> Enabled = true;                                                  // Результаты экзаменов
        N40 -> Enabled = true;                                                  // Результаты изложения
        N26 -> Enabled = true;                                                  // Ведомость на МвТ и ЭВ
        N33 -> Enabled = true;                                                  // Ведомость на СФП и ОФП
        N4  -> Enabled = true;                                                  // Ведомости
        N5  -> Enabled = true;                                                  // Результаты
        N6  -> Enabled = true;                                                  // Аппеляции
        N16 -> Enabled = true;                                                  // Восстановление по справке
        N22 -> Enabled = true;                                                  // Сводная ведомость дневная
        N27 -> Enabled = true;                                                  // Сводная ведомость заочная
        N42 -> Enabled = true;                                                  // список по направлениям
        N44 -> Enabled = true;                                                  // Итоговая по направлениям
        N49 -> Visible = true;                                                  // Протоколы

        SpeedButton1 -> Visible = true;                                         // Кнопка сменить факультет
        SpeedButton3 -> Visible = true;                                         // Сертификаты по критериям
        SpeedButton4 -> Visible = true;                                         // Отчет об итогах приемной компании
    }
    else
    {
        N9  -> Enabled = false;                                                 // ГИАЦ
        N20 -> Enabled = false;                                                 // Министерство образования
        N23 -> Visible = false;                                                 // Просуммировать экз. оценки (I added this to creation buttons)

        #ifdef SHOW_EXAM_RESULTS_ONLY_FOR_ADMISSIONS_COMMITTEE
        if (st_asu)                                                             // Результаты экзаменов
            N36 -> Enabled = true;
        else
            N36 -> Enabled = false;
        #else
        N36 -> Enabled = true;
        #endif  // SHOW_EXAM_RESULTS_ONLY_FOR_ADMISSIONS_COMMITTEE

        N40 -> Enabled = false;                                                 // Результаты изложения
        N42 -> Enabled = false;                                                 // список по направлениям
        N44 -> Enabled = false;                                                 // Итоговая по направлениям
        N35 -> Visible = false;                                                 // Приказ на зачисление
        N49 -> Visible = false;                                                 // Протоколы

        SpeedButton1 -> Visible = false;                                        // Кнопка сменить факультет
        SpeedButton3 -> Visible = false;                                        // Кнопка сменить факультет
        SpeedButton4 -> Visible = false;                                        // Кнопка сменить факультет
    }


    SpeedButton2Click (this);                                                   // Обновить максимальный номер дела


    DM -> QSpecializ -> Close ();
    DM -> QSpecializ ->
        ParamByName ("N_FAC") -> AsSmallInt = nom_fac;
    DM -> QSpecializ -> Open ();


    DM -> Selection_CommitteeFDTable -> Active = false;
    DM -> Selection_CommitteeFDTable -> Active = true;
}
void __fastcall TMainForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}
void __fastcall TMainForm::FormCloseQuery (
        TObject * Sender,
        bool    & CanClose
    )
{
    DM -> FDConnection2 -> Connected = false;
    DM -> FDConnection1 -> Connected = false;
}
void __fastcall TMainForm::FormCreate (TObject * Sender)
{
    LoadKeyboardLayout (                                                        // Русская
        "00000419",
        KLF_ACTIVATE
    );

    FormatSettings.DecimalSeparator = '.';                                      // Устанвка разделителя даты
    FormatSettings.ShortDateFormat  = "dd.mm.yyyy";                             // Устанвка формата даты
}
AnsiString TMainForm::getPartOfSheetNameForEducationType (const int eduTypeCode)
{
    switch (static_cast <EducationTypeCode> (eduTypeCode))
    {
        case EducationTypeCode::INTRAMURAL:
            return
                "Д.";
        case EducationTypeCode::EXTRAMURAL:
            return
                "З.";
        default:
            return
                "Д.";
    }
}
AnsiString TMainForm::getPartOfSheetNameForStudyPeriod (const int studyPeriod)
{
    switch (static_cast <StudyPeriodCode> (studyPeriod))
    {
        case StudyPeriodCode::FULL:
            return
                "П.";
        case StudyPeriodCode::SHORT_SECOND_COURSE:
            return
                "С.";
        case StudyPeriodCode::SHORT_THIRD_COURSE:
            return
                "С.";
        default:
            return
                "П.";
    }
}
AnsiString TMainForm::getPartOfSheetNameForPayment (const int payment)
{
    switch (static_cast <PaymentCode> (payment))
    {
        case PaymentCode::BUDGET:
            return
                "Б.";
        case PaymentCode::BUYERS:
            return
                "О.";
        default:
            return
                "Б.";
    }
}
AnsiString TMainForm::getReportName (
        const AnsiString & documentName
    )
{
    return
            documentName                        +
        ", за "                                 +
            AnsiToUtf8 (cur_d.CurrentDate ())   +
        ".xls";
}
AnsiString TMainForm::getReportName (
        const AnsiString & documentName,
              bool         isFormatDateUsed
    )
{
    AnsiString date = "";

    if (isFormatDateUsed)
        date =
            AbiturLogDate.FormatString (
                "yyyy-mm-dd"
            );
    else
        date =
            AnsiToUtf8 (
                cur_d.CurrentDate ()
            );

    return
            documentName    +
        ", за "             +
            date            +
        ".xls";
}
AnsiString TMainForm::getReportName (
        const AnsiString & facultyName,
        const AnsiString & documentName
    )
{
    return
            facultyName                         +
        ". "                                    +
            documentName                        +
        ", за "                                  +
            AnsiToUtf8 (cur_d.CurrentDate ())   +
        ".xls";
}
AnsiString TMainForm::getReportName (
        const AnsiString & facultyName,
        const AnsiString & documentName,
        const AnsiString & currentHours
    )
{
    return
            facultyName                         +
        ". "                                    +
            documentName                        +
        ", за "                                 +
            AnsiToUtf8 (cur_d.CurrentDate ())   +
        ", на "                                 +
            currentHours                        +
        " часов"                                +
        ".xls";
}
AnsiString TMainForm::getReportNameWithCourseNumber (
        const AnsiString & facultyName,
        const AnsiString & documentName,
        const AnsiString & courseNumber
    )
{
    return
            facultyName                         +
        ". "                                    +
            documentName                        +
        ", на "                                 +
            courseNumber                        +
        " курс за "                             +
            AnsiToUtf8 (cur_d.CurrentDate ())   +
        ".xls";
}
AnsiString TMainForm::getSummaryListNameByPeriod (
        const AnsiString & period,
              int          educationType,
              int          price
    )
{
    AnsiString
        eduType = "",
        payment = "";

    switch (static_cast <EducationTypeCode> (educationType))
    {
        case EducationTypeCode::INTRAMURAL:
                if (price)
                {
                    eduType = "Дневное";
                    payment = "Платники";
                }
                else
                {
                    eduType = "Дневное";
                    payment = "Бюджет";
                }
            break;
        case EducationTypeCode::EXTRAMURAL:
                if (price)
                {
                    eduType = "Заочное";
                    payment = "Платники";
                }
                else
                {
                    eduType = "Заочное";
                    payment = "Бюджет";
                }
            break;
    }

    return
        "ВЕДОМОСТЬ - ("                         +
            period                              +
        ", "                                    +
            eduType                            +
        ", "                                    +
            payment                             +
        ") Факульт - "                          +
            fac1                                +
        " за "                                  +
            AnsiToUtf8 (cur_d.CurrentDate ())   +
        ".xls";
}
void __fastcall TMainForm::Itog_podano (                                        // Сумма 'Подано заявлений' по виду обучения или факультету
        int edu,                                                                // вид обучения 0 - дневное, 1 - заочное
        int n_r,                                                                // номер строки начала цикла
        int itog                                                                // итоговые цифры 0 - по виду обучения 1 - по факультету
    )
{
    if ( ! itog)
        CellValue (
            "ВСЕГО:",
            2,
            nom_row
        );
    else
    {
        if (nom_fac != FacultyCode::MSTH)
            CellValue (
                "Итого по факультету:",
                2,
                nom_row
            );
        else
            CellValue (
                "Итого по институту:",
                2,
                nom_row
            );
    }

    for ( int k = 2;                                                            // общая сумма
              k < 17;
              ++k
        )
    {
        if (k != 6)
            if (itog)
                CellFormula (                                                   // (=([A-Z][0-9]-2)+([A-Z][0-9]-1))
                    "="                             +
                        mas_column[k]               +
                        AnsiString (n_r - 2)        +
                    "+"                             +
                        mas_column[k]               +
                        AnsiString (nom_row - 1),
                    k + 1,
                    nom_row
                );
            else
                CellFormula (                                                   //(=СУММ(([A-Z][0-9]):([A-Z][0-9]-1)))
                    "=СУММ("                        +
                        mas_column[k]               +
                        AnsiString (n_r)            +
                    ":"                             +
                        mas_column[k]               +
                        AnsiString (nom_row - 1)    +
                    ")",
                    k + 1,
                    nom_row
                );
    }


    CellFormula (                                                               // Общий конкурс (=(H1-M1-Q1)/(C1))
        "=(H"                       +
            AnsiString (nom_row)    +
        "-M"                        +
            AnsiString (nom_row)    +
        "-Q"                        +
            AnsiString (nom_row)    +
        ")/(C"                      +
            AnsiString (nom_row)    +
        ")",
        18,
        nom_row
    );


    if ( ! edu)
        CellFormula (                                                           // конкурс ЦК
            "=M"                        +
                AnsiString (nom_row)    +
            "/E"                        +
                AnsiString (nom_row),
            19,
            nom_row
        );
}
void __fastcall TMainForm::MergeCell (
        int startColumn,
        int endColumn,
        int row
    )
{
    startMerging =
        SelectCell (
            startColumn,
            row
        );
    endMerging =
        SelectCell (
            endColumn,
            row
        );
    selectedRange =
        Range (
            Sheet,
            startMerging,
            endMerging
        );

    mergeCell (selectedRange);
}
void __fastcall TMainForm::MergeCell (
        int startColumn,
        int endColumn,
        int row,
        int alignHType                                                          // 3 - по центру
    )
{
    startMerging =
        SelectCell (
            startColumn,
            row
        );
    endMerging =
        SelectCell (
            endColumn,
            row
        );
    selectedRange =
        Range (
            Sheet,
            startMerging,
            endMerging
        );

    mergeCell (selectedRange);

    HorizontalAlign (
        selectedRange,
        3
    );
}
void __fastcall TMainForm::MergeCell (
        int startColumn,
        int endColumn,
        int startRow,
        int endRow,
        int alignHType                                                          // 3 - по центру
    )
{
    startMerging =
        SelectCell (
            startColumn,
            startRow
        );
    endMerging =
        SelectCell (
            endColumn,
            endRow
        );
    selectedRange =
        Range (
            Sheet,
            startMerging,
            endMerging
        );

    mergeCell (selectedRange);

    HorizontalAlign (
        selectedRange,
        alignHType
    );
    CellFont (
        "Arial",                                                                // Name
        11,                                                                     // Size
        false,                                                                  // Bold
        false,                                                                  // Italic
        1,                                                                      // Underline
        selectedRange                                                           // Range
    );
}
void __fastcall TMainForm::MergeCellCenter (
        int startColumn,
        int endColumn,
        int row
    )
{
    startMerging =
        SelectCell (
            startColumn,
            row
        );
    endMerging =
        SelectCell (
            endColumn,
            row
        );
    selectedRange =
        Range (
            Sheet,
            startMerging,
            endMerging
        );

    mergeCell (selectedRange);

    HorizontalAlign (
        selectedRange,
        3
    );
    CellFont (
        "Arial",
        11,
        true,
        false,
        1,
        selectedRange
    );
}
void TMainForm::printEnvelope (
              PaymentCode         payment,
              EducationTypeCode   educationType,
        const AnsiString        & message
    )
{
    LetterDualListDlg = new TLetterDualListDlg (this);

    DM -> QLetterSource -> Close ();
    DM -> QLetterSource -> SQL -> Clear ();
    DM -> QLetterSource -> SQL ->
        Add (
            " SELECT"                       \
            "     nomer_ab,"                \
            "     fam,"                     \
            "     name,"                    \
            "     otch,"                    \
            "     address_before"           \
            " FROM"                         \
            "     abitura"                  \
            " WHERE"                        \
            "         n_fac   = :n_fac"     \
            "     AND"                      \
            "         price   = "           +
                static_cast <AnsiString> (
                    payment
                )                           +
            "     AND"                      \
            "         vid_edu = "           +
                static_cast <AnsiString> (
                    educationType
                )                           +
            "     AND"                      \
			"         status  = 0"          \
            " ORDER BY"                     \
            "     fam,"                     \
            "     name,"                    \
            "     otch"
        );

    DM -> QLetterSourceKol -> Close ();
    DM -> QLetterSourceKol -> SQL -> Clear ();
    DM -> QLetterSourceKol -> SQL ->
        Add (
            " SELECT"                       \
            "     COUNT"                    \
            "     ("                        \
            "         nomer_ab"             \
            "     )"                        \
            " FROM"                         \
            "     abitura"                  \
            " WHERE"                        \
			"         n_fac   = :n_fac"     \
            "     AND"                      \
            "         price   = "           +
                static_cast <AnsiString> (
                    payment
                )                           +
            "     AND"                      \
            "         vid_edu = "           +
                static_cast <AnsiString> (
                    educationType
                )                           +
            "     AND"                      \
			"         status  = 0"
        );

    LetterDualListDlg -> Caption =
        "Выбор студентов для печати конвертов ("    +
            message                                 +
        ")";

    LetterDualListDlg -> ShowModal ();

    if (LetterDualListDlg)
        delete LetterDualListDlg;
}


void __fastcall TMainForm::N1Click (TObject * Sender)
{
    AbiturForm = new TAbiturForm (this);

    AbiturForm -> ShowModal ();
}
void __fastcall TMainForm::N4Click (TObject * Sender)
{
    ExamenForm = new TExamenForm (this);

    ExamenForm -> ShowModal ();
}
void __fastcall TMainForm::N5Click (TObject * Sender)
{
    Result_ExamForm = new TResult_ExamForm (this);

    Result_ExamForm -> ShowModal ();
}
void __fastcall TMainForm::N6Click (TObject * Sender)
{
    ApellForm = new TApellForm (this);

    DM -> QUndo_Abit -> Close ();
    DM -> QUndo_Abit ->
        ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DM -> QUndo_Abit ->
        ParamByName ("ST")    -> AsInteger = 2;
    DM -> QUndo_Abit -> Open ();


    if (DM -> QUndo_Abit -> RecordCount)
        ApellForm -> ShowModal ();
    else
    {
        ApellForm -> Close ();

        ShowMessage (
            "На вашем факультете нет абитуриентов " \
            "с отрицательными оценками!!!"
        );
    }
}
void __fastcall TMainForm::N10Click (TObject * Sender)                          // Сводная ведомость (Дневное -> Платники)
{
    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N12Click (TObject * Sender)
{
    Application  ->  Terminate ();
}
void __fastcall TMainForm::N13Click (TObject * Sender)
{
    Variant V =
        CreateOleObject ("Word.Basic");

    V.Exec (
        Procedure ("FileNew") <<
            AnsiToUtf8 ("Normal")
    );

    // V.Exec (Procedure ("AppShow"));                                          // УБРАТЬ! Нужно только для отладки, т.к. показывает ворму при выводе данных


    DM -> QSpisoc_Group -> Close ();
    DM -> QSpisoc_Group ->
        ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DM -> QSpisoc_Group -> Open ();


    AnsiString n_gr =
        DM -> QSpisoc_GroupNOM_GROUP -> Value;

    int j    = 1,                                                               // порядковый номер

        rec  =
            DM -> QSpisoc_Group            -> RecordCount,

        spec =
            DM -> QSpisoc_GroupN_SPECIALIZ -> Value;

    V.Exec (                                                                    // Начало формирования списка
        Procedure ("Bold")   << true
    );
    V.Exec (
        Procedure ("Font")   <<
            AnsiToUtf8 ("Arial") << 24
    );
    V.Exec (
        Procedure ("Insert") <<
            "Группа № " +
                n_gr    +
            "\n"
    );
    V.Exec (
        Procedure ("Bold")   << true
    );
    V.Exec (
        Procedure ("Italic") << true
    );
    V.Exec (
        Procedure ("Font")   <<
            AnsiToUtf8 ("Arial") << 16
    );
    V.Exec (
        Procedure ("Insert") <<
            DeleteAfterDatabaseChange::getNcrb2022NameSportStrByNSpecializ (    //  TODO: TERM_EDU
                spec
            )                                                               +
            //DM -> QSpisoc_GroupSPECIALIZ2 -> Value +
            "\n"
    );
    V.Exec (
        Procedure ("Font")   <<
            AnsiToUtf8 ("Arial") << 14
    );

    V.Exec (                                                                    // ФИО
        Procedure ("Insert") <<
                AnsiString (j)                      +
            ". "                                    +
                DM -> QSpisoc_GroupFAM  -> Value    +
            " "                                     +
                DM -> QSpisoc_GroupNAME -> Value    +
            " "                                     +
                DM -> QSpisoc_GroupOTCH -> Value    +
            "\n"
    );

    for ( int i =  2;
              i <= rec;
              ++i
        )
    {
        DM -> QSpisoc_Group -> Next ();

        if (DM -> QSpisoc_GroupNOM_GROUP -> Value == n_gr)
        {
            if (DM -> QSpisoc_GroupN_SPECIALIZ -> Value == spec)
            {
                V.Exec (
                    Procedure ("Font") <<
                        AnsiToUtf8 ("Arial") << 14
                );
                V.Exec (
                    Procedure ("Insert") <<
                            AnsiString (++j)                    +
                        ". "                                    +
                            DM -> QSpisoc_GroupFAM  -> Value    +
                        " "                                     +
                            DM -> QSpisoc_GroupNAME -> Value    +
                        " "                                     +
                            DM -> QSpisoc_GroupOTCH -> Value    +
                        "\n"
                );
            }
            else
            {
                j    = 1;

                spec =
                    DM -> QSpisoc_GroupN_SPECIALIZ -> Value;

                V.Exec (
                    Procedure ("Bold")   << true
                );
                V.Exec (
                    Procedure ("Italic") << true
                );
                V.Exec (
                    Procedure ("Font") <<
                        AnsiToUtf8 ("Arial") << 16
                );
                V.Exec (
                    Procedure ("Insert") <<
                        "\n"                                    +
                        DeleteAfterDatabaseChange::getNcrb2022NameSportStrByNSpecializ (    //  TODO: TERM_EDU
                            spec
                        )                                                               +
                        //DM -> QSpisoc_GroupSPECIALIZ2 -> Value  +
                        "\n"
                    );
                V.Exec (
                    Procedure ("Font") <<
                        AnsiToUtf8 ("Arial") << 14
                );
                V.Exec (
                    Procedure ("Insert") <<
                            AnsiString (j)                      +
                        ". "                                    +
                            DM -> QSpisoc_GroupFAM  -> Value    +
                        " "                                     +
                            DM -> QSpisoc_GroupNAME -> Value    +
                        " "                                     +
                            DM -> QSpisoc_GroupOTCH -> Value    +
                        "\n"
                );
            }
        }
        else
        {
            V.Exec (
                Procedure ("InsertBreak") << false
            );

            j    = 1;

            n_gr =
                DM -> QSpisoc_GroupNOM_GROUP   -> Value;

            spec =
                DM -> QSpisoc_GroupN_SPECIALIZ -> Value;

            V.Exec (
                Procedure ("Bold")   << true
            );
            V.Exec (
                Procedure ("Font") <<
                    AnsiToUtf8 ("Arial") << 24
            );
            V.Exec (
                Procedure ("Insert") <<
                    "Группа № " +
                        n_gr    +
                    "\n"
            );
            V.Exec (
                Procedure ("Bold")   << true
            );
            V.Exec (
                Procedure ("Italic") << true
            );
            V.Exec (
                Procedure ("Font") <<
                    AnsiToUtf8 ("Arial") << 16
            );
            V.Exec (
                Procedure ("Insert") <<
                    DeleteAfterDatabaseChange::getNcrb2022NameSportStrByNSpecializ (    //  TODO: TERM_EDU
                        spec
                    )                                                               +
                    //DM -> QSpisoc_GroupSPECIALIZ2 -> Value +
                    "\n"
            );
            V.Exec (
                Procedure ("Font") <<
                    AnsiToUtf8 ("Arial") << 14
            );
            V.Exec (
                Procedure ("Insert") <<
                        AnsiString (j)                      +
                    ". "                                    +
                        DM -> QSpisoc_GroupFAM  -> Value    +
                    " "                                     +
                        DM -> QSpisoc_GroupNAME -> Value    +
                    " "                                     +
                        DM -> QSpisoc_GroupOTCH -> Value    +
                    "\n"
            );
        }
    }

    V.Exec (                                                                    // конец формирования списка
        Procedure ("AppShow")
    );
}
void __fastcall TMainForm::N14Click (TObject * Sender)
{
    int col_pred =                                                              // Определение кол-ва экзамен. предметов
        DM -> TPredmet -> RecordCount;

    DM -> QResult_Exam -> Close ();                                             // Считывание оценок по предметам
    DM -> QResult_Exam -> Open ();

    DM -> QSpisoc_Group -> Close ();
    DM -> QSpisoc_Group ->
        ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DM -> QSpisoc_Group -> Open ();

    AnsiString n_gr =
        DM -> QSpisoc_GroupNOM_GROUP -> Value;

    int j   = 1;                                                                // Порядковый номер

    int rec =                                                                   // Количество человек в группе
        DM -> QSpisoc_Group -> RecordCount;

    if (n_gr == "")                                                             // ФОРМИРОВАНИЯ СПИСКА
        return;

    int spec = DM -> QSpisoc_GroupN_SPECIALIZ -> Value;


    ExcelApplication = Variant::CreateObject ("Excel.Application");             // создание объекта и открытие созданного файла

    // OVisible (ExcelApplication);

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir                     +
            DocumentFile::LIST::GROUPS
        );

    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );

    // DisplayAlert (ExcelApplication); // !!!

    AnsiString n_file =
        getReportName (
            fac1,
            DocumentName::LIST::GROUPS
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );
    OVisible (ExcelApplication);


    MergeCellCenter (                                                           // ШАПКА с факультетом, видом обучения и номером группы
        1,
        7           +
        col_pred,
        2
    );
    CellValue (                                                                 // Название факультета
        DM -> TFaculty ->
            Lookup (
                "N_FAC",
                nom_fac,
                "FAC"
            ),
        1,
        2
    );


    MergeCellCenter (                                                           // Вид обучения
        1,
        7           +
        col_pred,
        4
    );
    CellValue (
        DM -> QSpisoc_GroupVID_EDU1 -> Value,
        1,
        4
    );


    MergeCellCenter (                                                           // Номер группы
        1,
        7           +
        col_pred,
        5
    );
    CellValue (
        "Группа № " +
            n_gr,
        1,
        5
    );


    NameSheet1 (                                                                // Переименование листа
        Sheet,
        n_gr
    );


    Shapka_spisok (col_pred);                                                   // Функция формирования шапки таблицы


    MergeCellCenter (                                                           // Форматирование ячейки для занесения специализации
        1,
        7           +
        col_pred,
        8
    );

    AnsiString
        directionSpecialityName;

    if (    DM -> QSpisoc_GroupTERM_EDU -> Value != StudyPeriodCode::HIGH_SECOND_COURSE
         && DM -> QSpisoc_GroupTERM_EDU -> Value != StudyPeriodCode::HIGH_THIRD_COURSE
         //   DM -> QSpisoc_GroupTERM_EDU -> Value == StudyPeriodCode::FULL
         //|| DM -> QSpisoc_GroupTERM_EDU -> Value == StudyPeriodCode::HIGH_FIRST_COURSE
       )
    {
        directionSpecialityName =
            DeleteAfterDatabaseChange::getNcrb2022NameSportStrByNSpecializ (
                spec
            );
    }
    else
    {
         directionSpecialityName = DM -> QSpisoc_GroupSPECIALIZ2 -> Value;
    }
    #ifdef TEST_MAIN_UNIT
        ShowMessage (
            directionSpecialityName
        );
    #endif
    CellValue (
        directionSpecialityName,
        1,
        8
    );

    int nom_stroka = 9;                                                         // номер строки


    Data_spisok (                                                               // Создаем полный список абитуриентов
        col_pred,
        nom_stroka,
        j
    );

    ++nom_stroka;

    for ( int i =  2;                                                           // Проход по абитуриентам (с учетом номера группы и специализации)
              i <= rec;
              ++i
        )
    {
        DM -> QSpisoc_Group -> Next ();

        if (DM -> QSpisoc_GroupNOM_GROUP -> Value == n_gr)
        {
            if (DM -> QSpisoc_GroupN_SPECIALIZ -> Value == spec)
            {
                Data_spisok (
                    col_pred,
                    nom_stroka,
                    ++j
                );

                ++nom_stroka;
            }
            else
            {
                j = 1;

                spec =
                    DM -> QSpisoc_GroupN_SPECIALIZ -> Value;


                MergeCellCenter (                                               // Форматирование ячейки для занесения специализации
                    1,
                    7           +
                    col_pred,
                    nom_stroka
                );

                if (    DM -> QSpisoc_GroupTERM_EDU -> Value != StudyPeriodCode::HIGH_SECOND_COURSE
                     && DM -> QSpisoc_GroupTERM_EDU -> Value != StudyPeriodCode::HIGH_THIRD_COURSE
                     //   DM -> QSpisoc_GroupTERM_EDU -> Value == StudyPeriodCode::FULL
                     //|| DM -> QSpisoc_GroupTERM_EDU -> Value == StudyPeriodCode::HIGH_FIRST_COURSE
                   )
                {
                    directionSpecialityName =
                        DeleteAfterDatabaseChange::getNcrb2022NameSportStrByNSpecializ (
                            spec
                        );
                }
                else
                {
                    directionSpecialityName = DM -> QSpisoc_GroupSPECIALIZ2 -> Value;
                }

                #ifdef TEST_MAIN_UNIT
                    ShowMessage (
                        directionSpecialityName
                    );
                #endif
                CellValue (
                    directionSpecialityName,
                    1,
                    nom_stroka++
                );

                Data_spisok (
                    col_pred,
                    nom_stroka,
                    j
                );

                ++nom_stroka;
            }
        }
        else
        {
            for ( int i =  1;                                                   // Автоподбор ширины столбца
                      i <= col_pred + 7;
                      ++i
                )
                AutoFitColumn (
                    Sheet,
                    i
                );


            j = 1;

            n_gr =
                DM -> QSpisoc_GroupNOM_GROUP   -> Value;

            spec =
                DM -> QSpisoc_GroupN_SPECIALIZ -> Value;

            Sheet = NewSheet1 (Workbook);

            NameSheet1 (
                Sheet,
                n_gr
            );
            SelectSheet (
                Workbook,
                n_gr
            );


            MergeCellCenter (                                                   // Название факультета
                1,
                7           +
                col_pred,
                2
            );
            CellValue (
                DM -> TFaculty ->
                    Lookup (
                        "N_FAC",
                        nom_fac,
                        "FAC"
                    ),
                1,
                2
            );


            MergeCellCenter (                                                   // Ячейки 'вид обучения'
                1,
                7           +
                col_pred,
                4
            );
            CellValue (
                DM -> QSpisoc_GroupVID_EDU1 -> Value,
                1,
                4
            );


            MergeCellCenter (                                                   // Ячейка с 'номером группы'
                1,
                7           +
                col_pred,
                5
            );
            CellValue (
                "Группа № " +
                    n_gr,
                1,
                5
            );


            Shapka_spisok (col_pred);                                           // 'Шапка таблицы'


            MergeCellCenter (                                                   // Ячейка 'специализация'
                1,
                7           +
                col_pred,
                8
            );

            if (    DM -> QSpisoc_GroupTERM_EDU -> Value != StudyPeriodCode::HIGH_SECOND_COURSE
                 && DM -> QSpisoc_GroupTERM_EDU -> Value != StudyPeriodCode::HIGH_THIRD_COURSE
                 //   DM -> QSpisoc_GroupTERM_EDU -> Value == StudyPeriodCode::FULL
                 //|| DM -> QSpisoc_GroupTERM_EDU -> Value == StudyPeriodCode::HIGH_FIRST_COURSE
               )
            {
                directionSpecialityName =
                    DeleteAfterDatabaseChange::getNcrb2022NameSportStrByNSpecializ (
                        spec
                    );
            }
            else
            {
                directionSpecialityName = DM -> QSpisoc_GroupSPECIALIZ2 -> Value;
            }

            #ifdef TEST_MAIN_UNIT
                ShowMessage (
                    directionSpecialityName
                );
            #endif

            CellValue (
                directionSpecialityName,
                1,
                8
            );


            nom_stroka = 9;


            Data_spisok (
                col_pred,
                nom_stroka,
                j
            );

            ++nom_stroka;
        }
    }


    DM -> QAb_Pr_Enter -> Close ();


    for ( int i =  1;                                                           // Автоподбор ширины столбца
              i <= col_pred + 7;
              ++i
        )
        AutoFitColumn (
            Sheet,
            i
        );


    OVisible (ExcelApplication);                                                // сохранение
    DisplayAlert (ExcelApplication);

    WorkSaveAs = SaveBook (Workbook);

    if (nom_pr)
        delete [] nom_pr;

    DM -> QResult_Exam -> Close ();
}
void __fastcall TMainForm::N15Click (TObject * Sender)                          // Статистика  ->  Кол-во поданных заявлений (ежедневная)
{
    int k;                                                                      // переменная для обрамления ячеек
        nom_row = 8;                                                            // счетчик строк

    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir                         +
            DocumentFile::STATISTIC::DAILY
        );
    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );

    DisplayAlert (ExcelApplication);                                            // убирает запросы Excela на подтверждения действия


    AnsiString hour_cur =
        AnsiToUtf8 (
            cur_d.CurrentTime ()
        )
        .SetLength (
            2
        );


    if (    hour_cur.IsDelimiter (
                "\\:",
                2
            )
       )
        hour_cur = hour_cur.SetLength (1);

    AnsiString n_file =
        getReportName (
            fac1,
            DocumentName::STATISTIC::DAILY,
            hour_cur
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            out_dir     +
            n_file
        );

    // OVisible (ExcelApplication);                                             // УБРАТЬ! Только для отладки, т.к. показывает форму

    CellValue (                                                                 // Вывод названия факультета
        DM -> TFaculty ->
            Lookup (
                "N_FAC",
                nom_fac,
                "FAC"
            ),
        1,
        1
    );
    CellValue (                                                                 // Вывод даты и времени
        cur_d.CurrentDateTime (),
        7,
        3
    );


    int kc_kol,                                                                 // значения контрольной цифры
        kc_kol_fin,
        n_r;                                                                    // начало обрамления

    for ( int edu = 0;                                                          // проход по видам обучения: 0 - дневное, 1 - заочное
              edu < 2;
              ++edu
        )
    {
        int cel_kol = 0;                                                        // переменная для количества целевиков

        DM -> QStatisticEveryDay -> Close ();
        DM -> QStatisticEveryDay ->                                             // номер факультета
            ParamByName ("N_FAC")   -> AsInteger = nom_fac;
        DM -> QStatisticEveryDay ->                                             // форма обучения
            ParamByName ("VID_EDU") -> AsInteger = edu;
        DM -> QStatisticEveryDay -> Open ();

        col_rec =
            DM -> QStatisticEveryDay -> RecordCount;

        if (edu)
            CellValue (
                "Заочная форма получения образования",
                1,
                nom_row
            );
        else
            CellValue (
                "Дневная форма получения образования",
                1,
                nom_row
            );

        MergeCellCenter (
            1,
            19,
            nom_row++
        );

        n_r = nom_row;                                                          // переменная для начала обрамления

        for ( int n_rec = 0;
                  n_rec < col_rec;
                  ++n_rec
            )
        {
            if (DM -> QStatisticEveryDaySUM -> Value != 0)
            {
                spec = DM -> QStatisticEveryDayN_SPECIALIZ -> Value;            // номер по порядку

                CellValue (                                                     // вывод полного названия направления специальности
                    n_rec + 1,
                    1,
                    nom_row
                );
                CellValue (                                                     // вывод полного названия направления специальности
                    DM -> QStatisticEveryDaySPECIALIZ2 -> Value,
                    2,
                    nom_row
                );


                DM -> QPlanPriemPrice -> Close ();                              // КЦ бюджет
                DM -> QPlanPriemPrice ->
                    ParamByName ("N_FAC")   -> AsInteger = nom_fac;
                DM -> QPlanPriemPrice ->
                    ParamByName ("SPEC")    -> AsInteger = spec;
                DM -> QPlanPriemPrice ->
                    ParamByName ("VID_EDU") -> AsInteger = edu;
                DM -> QPlanPriemPrice ->
                    ParamByName ("PRICE")   -> AsInteger = 0;
                DM -> QPlanPriemPrice -> Open ();


                // CellValue (
                //     DM -> QPlanPriemPriceKOL_PLACE -> Value,
                //     4,
                //     nom_row
                // );


                kc_kol = DM -> QPlanPriemPriceKOL_PLACE -> Value;               // КЦ


                DM -> QPlanPriemPrice -> Close ();                              // КЦ внебюджет
                DM -> QPlanPriemPrice ->
                    ParamByName ("N_FAC")   -> AsInteger = nom_fac;
                DM -> QPlanPriemPrice ->
                    ParamByName ("SPEC")    -> AsInteger = spec;
                DM -> QPlanPriemPrice ->
                    ParamByName ("VID_EDU") -> AsInteger = edu;
                DM -> QPlanPriemPrice ->
                    ParamByName ("PRICE")   -> AsInteger = 1;
                DM -> QPlanPriemPrice -> Open ();


                kc_kol_fin = DM -> QPlanPriemPriceKOL_PLACE -> Value;

                if (    nom_fac == 4
                    // && edu     != 1
                   )
                {
                    DM -> QPlanPriem2Price -> Close ();
                    DM -> QPlanPriem2Price ->
                        ParamByName ("N_FAC")   -> AsInteger = nom_fac;
                    DM -> QPlanPriem2Price ->
                        ParamByName ("SPEC")    -> AsInteger = spec;
                    DM -> QPlanPriem2Price ->
                        ParamByName ("VID_EDU") -> AsInteger = edu;
                    DM -> QPlanPriem2Price ->
                        ParamByName ("PRICE")   -> AsInteger = 1;
                    DM -> QPlanPriem2Price -> Open ();

                    //kc_kol_fin +=                                               // КЦ
                    //     DM -> QPlanPriem2PriceKOL_PLACE -> Value;

                    DM -> QPlanPriem2Price -> Close ();
                }

                CellValue (
                    kc_kol_fin,
                    6,
                    nom_row
                );

                DM -> QPlanPriemPrice -> Close ();


                DM -> QCK_Kol_Plan -> Close ();                                 // План целевиков
                //DM -> QCK_Kol_Plan ->
                //    ParamByName ("N_FAC")       -> AsInteger = nom_fac;
                DM -> QCK_Kol_Plan ->
                    ParamByName ("N_SPECIALIZ") -> AsInteger = spec;
                DM -> QCK_Kol_Plan -> Open ();


                cel_kol = 0;                                                    // Занесение планового числа целевиков

                if (edu == 0)                                                   // Количество целевиков по плану (только дневное)
                {
                    cel_kol = DM -> QCK_Kol_PlanKOL_PLACE -> Value;

                    if (cel_kol)
                        CellValue (
                            cel_kol,
                            5,
                            nom_row
                        );
                }


                //if (    nom_fac != 4                                            // Занесение КЦ без целевиков
                    // && edu     != 1
                //   )
                //{
                    kc_kol -= cel_kol;                                          // КЦ без целевиков

                    if(kc_kol)
                        CellValue (
                            kc_kol,
                            4,
                            nom_row
                        );
                //}


                CellFormula (                                                   // Общее число по плану с целевиками и внебюджетом (=СУММ(D1:F1))
                    "=СУММ(D"                   +
                        AnsiString (nom_row)    +
                    ":F"                        +
                        AnsiString (nom_row)    +
                    ")",
                    3,
                    nom_row
                );


                DM -> StoredProcKolk_Konk1 -> Close ();                         // Занесение поданых заявлений по категориям
                DM -> StoredProcKolk_Konk1 ->
                    ParamByName ("IN_FAC")     -> AsInteger = nom_fac;
                DM -> StoredProcKolk_Konk1 ->
                    ParamByName ("IN_VID_EDU") -> AsInteger = edu;
                DM -> StoredProcKolk_Konk1 ->
                    ParamByName ("IN_SPEC")    -> AsInteger = spec;

                DM -> StoredProcKolk_Konk1 -> Prepare ();
                DM -> StoredProcKolk_Konk1 -> ExecProc ();


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_ALL_0") -> AsInteger;
                if (cel_kol)                                                    // бюджет,общий
                        CellValue (
                            cel_kol,
                            7,
                            nom_row
                        );

                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_CEL") -> AsInteger;
                if (cel_kol)                                                    // целевики
                        CellValue (
                            cel_kol,
                            8,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_2_0") -> AsInteger;
                if (cel_kol)                                                    // бюджет,сокращёнка
                        CellValue (
                            cel_kol,
                            9,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_VK_0") -> AsInteger;
                if (cel_kol)                                                    // бюджет,ВК
                        CellValue (
                            cel_kol,
                            10,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_WO_0") -> AsInteger;
                if (cel_kol)                                                    // БВИ
                        CellValue (
                            cel_kol,
                            11,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_ALL_1") -> AsInteger;
                if (cel_kol)                                                    // оплата,общий
                        CellValue (
                            cel_kol,
                            12,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_2_1") -> AsInteger;
                if (cel_kol)                                                    // оплата,сокращёнка
                        CellValue (
                            cel_kol,
                            13,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_VK_1") -> AsInteger;
                if (cel_kol)                                                    // оплата ВК
                        CellValue (
                            cel_kol,
                            14,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_WO_1") -> AsInteger;
                if (cel_kol)                                                    // оплата БВИ
                        CellValue (
                            cel_kol,
                            15,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_ING") -> AsInteger;
                if (cel_kol)                                                    // оплата,иностранцы
                        CellValue (
                            cel_kol,
                            16,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_2V") -> AsInteger;
                if (cel_kol)                                                    // оплата,2 курс
                        CellValue (
                            cel_kol,
                            17,
                            nom_row
                        );

                DM -> StoredProcKolk_Konk1 -> Unprepare ();
                DM -> StoredProcKolk_Konk1 -> Close ();

                CellFormula (                                                   // Общее число поданых заявлений (=СУММ(G1:Q1))
                    "=СУММ(G"                   +
                        AnsiString (nom_row)    +
                    ":Q"                        +
                        AnsiString (nom_row)    +
                    ")",
                    18,
                    nom_row
                );
            }

            DM -> QStatisticEveryDay -> Next ();

            ++nom_row;
        }

        DM -> QCK_Kol_Plan       -> Close ();
        DM -> QStatisticEveryDay -> Close ();


        CellValue (                                                             // ИТОГО под формой обучения
            "ВСЕГО:",
            2,
            nom_row
        );
        Variant R2 =
            SelectCell (
                2,
                nom_row
            );
        CellFont (
            "Arial",
            10,
            true,
            false,
            1,
            R2
        );


        CicleSum (                                                              // суммирование с 3 по 17 столбец
            n_r,
            nom_row,
            3,
            17,
            0
        );
        R2 =
            SelectCell (
                18,
                nom_row
            );
        CellFormula (                                                           // Общее число поданых заявлений (=СУММ(G1:Q1))
            "=СУММ(G"                   +
                AnsiString (nom_row)    +
            ":Q"                        +
                AnsiString (nom_row)    +
            ")",
            18,
            nom_row
        );

        k = 19;

        CellFont (
            "Arial",
            10,
            true,
            false,
            1,
            R2
        );

        ++nom_row;

        for ( int i = 1;                                                        // обрамление оставшихся ячеек
                  i < k;
                  ++i
            )
        {
            for ( int j =  n_r;
                      j <= nom_row;
                      ++j
                )
                BorderCell (
                    i,
                    j,
                    1,
                    2
                );
        }
    }


    if (nom_fac != FacultyCode::MSTH)
        CellValue (
            "Итого по факультету: ",
            2,
            nom_row
        );
    else
        CellValue (
            "Итого по институту: ",
            2,
            nom_row
        );


    Variant R2 =
        SelectCell (
            2,
            nom_row
        );
    CellFont (
        "Arial",
        10,
        true,
        false,
        1,
        R2
    );
    CicleSum (
        n_r,
        nom_row,
        3,
        17,
        1
    );
    R2 =
        SelectCell (
            17,
            nom_row
        );
    CellFormula (                                                               // Общее число поданых заявлений (=СУММ(G1:Q1))
        "=СУММ(G"                   +
            AnsiString (nom_row)    +
        ":Q"                        +
            AnsiString (nom_row)    +
        ")",
        18,
        nom_row
    );
    CellFont (
        "Arial",
        10,
        true,
        false,
        1,
        R2
    );

    ++nom_row;

    CellValue (
        "Ответственный секретарь приемной комиссии ",
        2,
        ++nom_row
    );
    CellValue (
        LegallyAuthorizedPerson::SECRETARY,
        7,
        nom_row
    );

    WorkSaveAs = SaveBook (Workbook);                                           // сохранение
    OVisible (ExcelApplication);                                                // Показывает объект Excel

    ExcelApplication.Clear ();

    DM -> QPlan_Priem_All -> Close ();
}
void __fastcall TMainForm::N16Click (TObject * Sender)
{
    Undo_SpravkaForm = new TUndo_SpravkaForm (this);

    DM -> QUndo_Abit -> Close ();
    DM -> QUndo_Abit ->
        ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DM -> QUndo_Abit ->
        ParamByName ("ST")    -> AsInteger = 3;
    DM -> QUndo_Abit -> Open ();

    Undo_SpravkaForm -> ShowModal ();
}
void __fastcall TMainForm::N17Click (TObject * Sender)                          // РЕЗУЛЬТАТЫ победителей олимпиады
{
    DM -> QLittle_Spisoc_GR -> Close ();
    DM -> QLittle_Spisoc_GR ->
        ParamByName ("FAC") -> AsString = nom_fac;
    DM -> QLittle_Spisoc_GR -> Open ();

    if (DM -> QLittle_Spisoc_GR -> RecordCount)
    {
        Dop_ResultForm = new TDop_ResultForm (this);                            // форма добавления языка победителей олимпиад БГУ

        Dop_ResultForm -> ShowModal ();
    }
    else                                                                        // таких людей просто нет
    {
        ShowMessage (
            "На вашем факультете нет абитуриентов, "    \
            "которым надо засчитать высший балл"
        );
    }
}
void __fastcall TMainForm::N21Click (TObject * Sender)                          // (CAN'T OPERATE!!!!) Форма 2 (результаты экзаменов и зачисление студентов)
{
    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir                         +
            DocumentFile::REPORT::FORM_2
        );
    Sheet =
        SelectSheet (
            Workbook,
            "Форма 2"
        );

    DMStat -> QSpecial -> Open ();


    int rec_spec = DMStat -> QSpecial -> RecordCount;


    for ( int k = 0;                                                            // ???? WHY ????
              k < 2;
              ++k
        )
        mas_spec_str[k] = new int[rec_spec];


    for ( int i = 0;                                                            // Проход по специальностям
              i < rec_spec;
              ++i
        )
    {
        mas_spec_str[0][i] =
            DMStat -> QSpecialN_SPEC -> Value;

        mas_spec_str[1][i] =
            i + 16;

        DMStat -> QSpecial -> Next ();
    }


    DMStat -> QF2_All_Sdal ->                                                   // сдавали экзамены (без учета с тремя сертификатами) (действующие (0), отриц.оценка (2), забрал док-ты во время экз (4) и зачисленные (5))
        ParamByName ("V_E") -> AsInteger = 0;                                   // только дневное
    DMStat -> QF2_All_Sdal -> Open ();

    for ( int j = 0;                                                            // общее количество сдававших вступительные экзамены
              j < DMStat -> QF2_All_Sdal -> RecordCount;                        // for сдавали вступительные экзамены
              ++j
        )
    {
        CellValue (
            DMStat -> QF2_All_SdalCOUNT -> Value,
            4,
            Find_nom_spec_str (
                DMStat -> QF2_All_SdalN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QF2_All_Sdal -> Next ();
    }


    DMStat -> QF2_Sdal ->                                                       // Выдержали вступительные экзамены (без учета абитуриентов с тремя сертификатами) действующие (0) и зачисленные (5)
        ParamByName ("V_E") -> AsInteger = 0;                                   // только дневное
    DMStat -> QF2_Sdal -> Open ();

    for ( int j = 0;                                                            // for Выдержали вступительные экзамены
              j < DMStat -> QF2_Sdal -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QF2_SdalCOUNT -> Value,
            5,
            Find_nom_spec_str (
                DMStat -> QF2_SdalN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QF2_Sdal -> Next ();
    }


    DMStat -> QCount_Medal ->                                                   // Медалисты школ, которые получили отрицательные оценки
        ParamByName ("ST")  -> AsInteger = 2;
    DMStat -> QCount_Medal ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Medal -> Open ();

    for ( int j = 0;                                                            // Расчет кол-ва окончивших школу с медалью и получивших "2"
              j < DMStat -> QCount_Medal -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_MedalCOUNT -> Value,
            6,
            Find_nom_spec_str (
                DMStat -> QCount_MedalN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Medal -> Next ();
    }


    DMStat -> QF2_Zach ->                                                       // Всего зачисленных на бюджет
        ParamByName ("V_E") -> AsInteger = 0;                                   // только дневное
    DMStat -> QF2_Zach -> Open ();

    for ( int j = 0;                                                            // for Всего зачисленных на бюджет
              j < DMStat -> QF2_Zach -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QF2_ZachCOUNT -> Value,
            7,
            Find_nom_spec_str (
                DMStat -> QF2_ZachN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QF2_Zach -> Next ();
    }


    DMStat -> QCount_PO ->                                                      // прошли ПО
        ParamByName ("ST") -> AsInteger = 5;
    DMStat -> QCount_PO -> Open ();

    for ( int j = 0;                                                            // Расчет кол-ва окончивших ПО
              j < DMStat -> QCount_PO -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_POCOUNT -> Value,
            9,
            Find_nom_spec_str (
                DMStat -> QCount_PON_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_PO -> Next ();
    }


    DMStat -> QF2_CK -> Open ();

    for ( int j = 0;                                                            // Расчет кол-ва с ЦК (на дневной форме обечения)
              j < DMStat -> QF2_CK -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QF2_CKCOUNT -> Value,
            10,
            Find_nom_spec_str (
                DMStat -> QF2_CKN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QF2_CK -> Next ();
    }


    DMStat -> QCount_Medal -> Close ();                                         // Медалисты школ, которые поступили
    DMStat -> QCount_Medal ->
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Medal ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Medal -> Open ();

    for ( int j = 0;                                                            // Расчет кол-ва окончивших школу с медалью
              j < DMStat -> QCount_Medal -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_MedalCOUNT -> Value,
            11,
            Find_nom_spec_str (
                DMStat -> QCount_MedalN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Medal -> Next ();
    }


    DMStat -> QCount_Diplom ->                                                  // Дипломы с отличием,которые поступили
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Diplom ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Diplom -> Open ();

    for ( int j = 0;                                                            // Расчет кол-ва окончивших ССУЗ и т.д. с отличием
              j < DMStat -> QCount_Diplom -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_DiplomCOUNT -> Value,
            12,
            Find_nom_spec_str (
                DMStat -> QCount_DiplomN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Diplom -> Next ();
    }


    AnsiString SQL1 =                                                           // РАСЧЕТ ПОСТУПАЮЩИХ БЕЗ ЭКЗАМЕНОВ (П.21 ПРАВИЛ ПРИЕМА)
        " SELECT"                           \
        "     COUNT"                        \
        "     ("                            \
        "         fam"                      \
        "     ),"                           \
        "     n_spec"                       \
        " FROM"                             \
        "     abitura"                      \
        " WHERE";
    AnsiString SQL2 = "";
    AnsiString SQL3 =
        "     AND"                          \
        "         status  =      :ST"       \
        "     AND"                          \
        "         vid_edu =      :EDU"      \
        "     AND"                          \
        "         konkurs NOT IN (4)"       \
        "     AND"                          \
        "         n_spec  <>     1"         \
        "     AND"                          \
        "         ("                        \
        "             n_found <> 2"         \
        "          OR"                      \
        "             n_found IS NULL"      \
        "         )"                        \
        " GROUP BY"                         \
        "     n_spec";

    SQL2 =                                                                      // Победители и призеры чемп. мира и Европы, участники Олимпийских игр (Wo = 1 или 2)
        "         ("                        \
        "             without LIKE '1'"     \
        "          OR"                      \
        "             without LIKE '2'"     \
        "         )";


    DMStat -> QCount_Olimp -> Close ();
    DMStat -> QCount_Olimp -> SQL -> Clear ();
    DMStat -> QCount_Olimp -> SQL ->
        Add (
            SQL1    +
            SQL2    +
            SQL3
        );
    DMStat -> QCount_Olimp ->
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Olimp ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Olimp -> Open ();

    for ( int j = 0;                                                            // Расчет кол-ва победителей и призеров чемп. Мира и Европы, участники Олимпийских игр
              j < DMStat -> QCount_Olimp -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_OlimpCOUNT -> Value,
            14,
            Find_nom_spec_str (
                DMStat -> QCount_OlimpN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Olimp -> Next ();
    }


    SQL2 =                                                                      // Лауреаты фондов Президента РБ (Wo = 3)
        "         without LIKE '3'";


    DMStat -> QCount_Olimp -> Close ();
    DMStat -> QCount_Olimp -> SQL -> Clear ();
    DMStat -> QCount_Olimp -> SQL ->
        Add (
            SQL1    +
            SQL2    +
            SQL3
        );
    DMStat -> QCount_Olimp ->
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Olimp ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Olimp -> Open ();

    for ( int j = 0;                                                            // for Лауреаты фондов Президента РБ
              j < DMStat -> QCount_Olimp -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_OlimpCOUNT -> Value,
            15,
            Find_nom_spec_str (
                DMStat -> QCount_OlimpN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Olimp -> Next ();
    }


    DMStat -> QCount_Gimn ->                                                    // закончили лицеии и гимназии
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Gimn ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Gimn -> Open ();

    for ( int j = 0;                                                            // Расчет кол-ва окончивших лицей или гимназию
              j < DMStat -> QCount_Gimn -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_GimnCOUNT -> Value,
            16,
            Find_nom_spec_str (
                DMStat -> QCount_GimnN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Gimn -> Next ();
    }


    DMStat -> QCount_Gorod -> Close ();                                         // ВЫПУСКНИКИ СЕЛЬСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ - ВСЕХ
    DMStat -> QCount_Gorod ->
        ParamByName ("N")   -> AsString   = "4";                                // сельские
    DMStat -> QCount_Gorod ->
        ParamByName ("ST")  -> AsSmallInt = 5;
    DMStat -> QCount_Gorod ->
        ParamByName ("EDU") -> AsSmallInt = 0;
    DMStat -> QCount_Gorod ->
        ParamByName ("GOD") -> AsString   = "%";
    DMStat -> QCount_Gorod -> Open ();

    for ( int j = 0;                                                            // Расчет кол-ва окончивших сельские УО
              j < DMStat -> QCount_Gorod -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_GorodCOUNT -> Value,
            17,
            Find_nom_spec_str (
                DMStat -> QCount_GorodN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Gorod -> Next ();
    }


    DMStat -> QCount_Gorod -> Close ();                                         // ВЫПУСКНИКИ СЕЛЬСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ - Только текущего года
    DMStat -> QCount_Gorod ->
        ParamByName ("N")   -> AsString   = "4";                                // сельские
    DMStat -> QCount_Gorod ->
        ParamByName ("ST")  -> AsSmallInt = 5;
    DMStat -> QCount_Gorod ->
        ParamByName ("EDU") -> AsSmallInt = 0;
    DMStat -> QCount_Gorod ->
        ParamByName ("GOD") -> AsString   = "2006";
    DMStat -> QCount_Gorod -> Open ();

    for ( int j = 0;                                                            // вычисление количества абитуриентов,окончивших сельские УО
              j < DMStat -> QCount_Gorod -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_GorodCOUNT -> Value,
            18,
            Find_nom_spec_str (
                DMStat -> QCount_GorodN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Gorod -> Next ();
    }


    DMStat -> QCount_Gorod -> Close ();                                         // ВЫПУСКНИКИ ГОРОДСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ - ВСЕХ
    DMStat -> QCount_Gorod ->
        ParamByName ("N")   -> AsString   = "5";                                // городские
    DMStat -> QCount_Gorod ->
        ParamByName ("ST")  -> AsSmallInt = 5;
    DMStat -> QCount_Gorod ->
        ParamByName ("EDU") -> AsSmallInt = 0;
    DMStat -> QCount_Gorod ->
        ParamByName ("GOD") -> AsString   = "%";
    DMStat -> QCount_Gorod -> Open ();

    for ( int j = 0;                                                            // вычисление количества абитуриентов,окончивших городские УО
              j < DMStat -> QCount_Gorod -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_GorodCOUNT -> Value,
            19,
            Find_nom_spec_str (
                DMStat -> QCount_GorodN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Gorod -> Next ();
    }


    DMStat -> QCount_Gorod -> Close ();                                         // ВЫПУСКНИКИ ГОРОДСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ - Только текущего года
    DMStat -> QCount_Gorod ->
        ParamByName ("N")   -> AsString   = "5";                                // городские
    DMStat -> QCount_Gorod ->
        ParamByName ("ST")  -> AsSmallInt = 5;
    DMStat -> QCount_Gorod ->
        ParamByName ("EDU") -> AsSmallInt = 0;
    DMStat -> QCount_Gorod ->
        ParamByName ("GOD") -> AsString   = "2006";
    DMStat -> QCount_Gorod -> Open ();

    for ( int j = 0;                                                            // вычисление количества абитуриентов,окончивших городские УО
              j < DMStat -> QCount_Gorod -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_GorodCOUNT -> Value,
            20,
            Find_nom_spec_str (
                DMStat -> QCount_GorodN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Gorod -> Next ();
    }


    DMStat -> QCount_Stag ->                                                    // СТАЖ БОЛЕЕ 2-х ЛЕТ
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Stag ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Stag -> Open ();

    for ( int j = 0;                                                            // Расчет кол-ва имеющих стаж более 2-х лет
              j < DMStat -> QCount_Stag -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_StagCOUNT -> Value,
            21,
            Find_nom_spec_str (
                DMStat -> QCount_StagN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Stag -> Next ();
    }


    DMStat -> QCount_Region ->                                                  // ГРАЖДАНЕ РФ, КАЗАХСТАНА, КЫРГЫЗТАНА, ТАДЖЫКИСТАНА
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Region ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Region -> Open ();

    for ( int j = 0;                                                            // Расчет кол-ва из других республик
              j < DMStat -> QCount_Region -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_RegionCOUNT -> Value,
            22,
            Find_nom_spec_str (
                DMStat -> QCount_RegionN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Region -> Next ();
    }


    DMStat -> QCount_Test ->                                                    // СЕРТИФИКАТЫ ЦЕНТРАЛИЗОВАННОГО ТЕСТИРОВАНИЯ ЦТ = 3 (с 2003 введен, с 2006 - 2 рез-та обязательно + 1)
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Test ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Test -> Open ();

    for ( int j = 0;                                                            // Расчет кол-ва на платное ЦТ
              j < DMStat -> QCount_Test -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_TestCOUNT -> Value,
            23,
            Find_nom_spec_str (
                DMStat -> QCount_TestN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_Test -> Next ();
    }


    DMStat -> QF2_Sdal -> Close ();                                             // Зачислены по испытанию в данном вузе (зачисленные (5))
    DMStat -> QF2_Sdal -> SQL -> Clear ();
    DMStat -> QF2_Sdal ->
        SQL ->
            Add (
                " SELECT"                                                      \
                "     abitura.n_spec,"                                         \
                "     COUNT"                                                   \
                "     ("                                                       \
                "         abitura.nomer_ab"                                    \
                "     )"                                                       \
                " FROM"                                                        \
                "     abitura"                                                 \
                " WHERE"                                                       \
                "         abitura.status  IN (5)"                              \
                "     AND"                                                     \
                "         abitura.konkurs <> 5"                                \
                "     AND"                                                     \
                "         abitura.vid_edu =  :V_E"                             \
                "     AND"                                                     \
                "         abitura.n_spec  <> 1"                                \
                "     AND"                                                     \
                "         ("                                                   \
                "             abitura.n_found <> 2"                            \
                "          OR"                                                 \
                "             abitura.n_found IS NULL"                         \
                "         )"                                                   \
                "     AND"                                                     \
                "         NOT EXISTS"                                          \
                "         ("                                                   \
                "             SELECT"                                          \
                "                 sertificat.nomer_ab"                         \
                "             FROM"                                            \
                "                 sertificat"                                  \
                "             WHERE"                                           \
                "                 sertificat.nomer_ab = abitura.nomer_ab"      \
                "             GROUP BY"                                        \
                "                 sertificat.nomer_ab"                         \
                "             HAVING COUNT"                                    \
                "             ("                                               \
                "                 sertificat.n_predmet"                        \
                "             ) = 3"                                           \
                "         )"                                                   \
                "     AND"                                                     \
                "         EXISTS"                                              \
                "         ("                                                   \
                "             SELECT"                                          \
                "                 distinct"                                    \
                "                     examen.nomer_ab"                         \
                "             FROM"                                            \
                "                 examen"                                      \
                "             WHERE"                                           \
                "                     examen.nomer_ab    = abitura.nomer_ab"   \
                "                 AND"                                         \
                "                     examen.status_ball = 0"                  \
                "             GROUP BY"                                        \
                "                 examen.nomer_ab"                             \
                "         )"                                                   \
                " GROUP BY"                                                    \
                "     abitura.n_spec"
            );
    DMStat -> QF2_Sdal ->
        ParamByName ("V_E") -> AsInteger = 0;                                   // дневное
    DMStat -> QF2_Sdal -> Open ();

    for ( int j = 0;                                                            // Зачислены по испытанию в данном вузе
              j < DMStat -> QF2_Sdal -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QF2_SdalCOUNT -> Value,
            24,
            Find_nom_spec_str (
                DMStat -> QF2_SdalN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QF2_Sdal -> Next ();
    }


    DMStat -> QCount_RUOR ->                                                    // НА СОКРАЩЕННЫЙ СРОК ОБУЧЕНИЯ (2 курс - РУОР)
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_RUOR ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_RUOR -> Open ();

    for ( int j = 0;                                                            // Расчет кол-ва на 2 курс
              j < DMStat -> QCount_RUOR -> RecordCount;
              ++j
        )
    {
        CellValue (
            DMStat -> QCount_RUORCOUNT -> Value,
            25,
            Find_nom_spec_str (
                DMStat -> QCount_RUORN_SPEC -> Value,
                rec_spec
            )
        );

        DMStat -> QCount_RUOR -> Next ();
    }

    DMStat -> QCount_Test   -> Close ();
    DMStat -> QCount_RUOR   -> Close ();
    DMStat -> QCount_Region -> Close ();
    DMStat -> QCount_Stag   -> Close ();
    DMStat -> QCount_Gorod  -> Close ();
    DMStat -> QCount_Gimn   -> Close ();
    DMStat -> QCount_Olimp  -> Close ();
    DMStat -> QCount_Diplom -> Close ();
    DMStat -> QCount_Medal  -> Close ();
    DMStat -> QCount_PO     -> Close ();
    DMStat -> QF2_CK        -> Close ();
    DMStat -> QF2_Zach      -> Close ();
    DMStat -> QF2_Sdal      -> Close ();
    DMStat -> QF2_All_Sdal  -> Close ();
    DMStat -> QSpecial      -> Close ();

    for ( int i = 0;
              i < 2;
              ++i
        )
        if (mas_spec_str)
            delete [] mas_spec_str[i];

    if (mas_spec_str)
        delete [] mas_spec_str;

    AnsiString n_file =
        getReportName (
            DocumentName::REPORT::FORM_2
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );

    OVisible (ExcelApplication);

    // ExcelApplication.Clear ();
}
void __fastcall TMainForm::N22Click (TObject * Sender)                          // Сводная ведомость (Дневное -> Бюджет)
{
    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N23Click (TObject * Sender)                          // СУММИРОВАНИЕ РЕЗУЛЬТАТОВ ЭКЗАМЕНОВ
{
    try
    {
        DM -> QSum_Ball -> Close ();
        DM -> QSum_Ball -> SQL -> Clear ();
        DM -> QSum_Ball -> SQL ->
            Add (
                " SELECT"                                              \
                "     abitura.nomer_ab,"                               \
                "     SUM"                                             \
                "     ("                                               \
                "         examen.ball"                                 \
                "     ),"                                              \
                "     abitura.sum_ball,"                               \
                "     abitura.middle_ball"                             \
                " FROM"                                                \
                "     abitura"                                         \
                "         INNER JOIN"                                  \
                "             examen"                                  \
                "         ON"                                          \
                "             abitura.nomer_ab = examen.nomer_ab"      \
                " WHERE"                                               \
                "         abitura.status = 0"                          \
                "     AND"                                             \
                "         abitura.n_fac  = :N_FAC"                     \
                " GROUP BY"                                            \
                "     abitura.nomer_ab,"                               \
                "     abitura.sum_ball,"                               \
                "     abitura.middle_ball"
            );
        DM -> QSum_Ball ->
            ParamByName ("N_FAC") -> AsInteger = nom_fac;
        DM -> QSum_Ball -> Open ();

        int rec = DM -> QSum_Ball -> RecordCount;

        for ( int i = 0;
                  i < rec;
                  ++i
            )
        {
            DM -> QSum_Ball -> Edit ();

            DM -> QSum_BallSUM_BALL -> Value =
                DM -> QSum_BallSUM         -> Value +
                DM -> QSum_BallMIDDLE_BALL -> Value;

            DM -> QSum_Ball -> Next ();
        }

        DM -> QSum_Ball -> ApplyUpdates ();
        DM -> QSum_Ball -> CommitUpdates ();

        ShowMessage (
            "Суммирование результатов прошло успешно!"
        );
    }
    catch (...)
    {
        ShowMessage (
            "В результате суммирования произошла "  \
            "ошибка.\nПовторите суммирование!"
        );
    }
}
void __fastcall TMainForm::N26Click (TObject * Sender)                          // Формирование сводной ведомости для 2 курса
{
    AnsiString k_f      = "",                                                   // Номер курса
               n_file   = "";                                                   // Название генерируемого файла

    if (nom_fac != FacultyCode::MSTH)
    {
        ExcelApplication = Variant::CreateObject ("Excel.Application");

        Variant Workbook =
            OpenBook (
                ExcelApplication,
                cur_dir                                     +
                DocumentFile::SUMMARY_LIST::ENTRANCE_EXAMS
            );
        Sheet =
            SelectSheet (
                Workbook,
                "Лист1"
            );

        // OVisible (ExcelApplication);

        CellValue (
            fac1,
            3,
            6
        );

        DMVed -> QPredm -> Close ();
        DMVed -> QPredm -> Open ();

        int rec_pred = 3;                                                       // количество предметов

        mas_pr   = new AnsiString[rec_pred];                                    // Названия предметов

        mas_pr[0] =
            "Белорусский (русский) язык";

        CellValue (
            "Бел. (рус.) яз",
            9,
            12
        );


        if (nom_fac == FacultyCode::RPC)
        {
            mas_pr[2] =
                "Физическая культура и спорт";

            CellValue (
                "ФКиС",
                11,
                12
            );

            mas_pr[1] =
                "Основы теории и методики спортивной тренировки";

            CellValue (
                "ОТиМСТ",
                10,
                12
            );

            k_f = "3";
        }


        if (    nom_fac == FacultyCode::SMA
             || nom_fac == FacultyCode::MS
           )
        {
            mas_pr[2] =
                "Физическая культура и спорт";

            CellValue (
                "ФКиС",
                11,
                12
            );

            mas_pr[1] =
                "Основы теории и методики спортивной тренировки";

            CellValue (
                "ОТиМСТ",
                10,
                12
            );

            k_f = "2";
        }


        if (nom_fac == FacultyCode::MSTH)
        {
            mas_pr[2] =
                "Менеджмент в туризме";

            CellValue (
                "Менедж. в тур.",
                11,
                12
            );


            mas_pr[1] =
                "Экскурсоведение";

            CellValue (
                "Экскурсов.",
                10,
                12
            );

            k_f = "2";
        }


        DM -> QSpecializ -> Close ();
        DM -> QSpecializ -> Open ();


        for ( int j = 0;                                                        // Проход по виду обучения
                  j < 2;
                  ++j
            )
        {
            for ( int k = 0;                                                    // Проход по форме оплаты
                      k < 2;
                      ++k
                )
            {
                DM -> QSpecializ -> First ();

                int rec_special = DM -> QSpecializ -> RecordCount;

                for ( int i = 0;                                                // Проход по специализациям
                          i < rec_special;
                          ++i
                    )
                {
                    DMVed -> QKonkurs -> Close ();
                    DMVed -> QKonkurs ->
                        ParamByName ("IN_SP")      -> Value =
                                DM -> QSpecializN_SPECIALIZ -> Value;
                    DMVed -> QKonkurs ->
                        ParamByName ("IN_VID_EDU") -> Value = j;
                    DMVed -> QKonkurs ->
                        ParamByName ("IN_KONK")    -> Value = 2;
                    DMVed -> QKonkurs ->
                        ParamByName ("IN_PRICE")   -> Value = k;
                    DMVed -> QKonkurs -> Open ();

                    int nom_str        = 13;
                    int rec_q_two_kurs = DMVed -> QKonkurs -> RecordCount;

                    if (rec_q_two_kurs)                                         // НОмкр начальной строки в Excel
                    {
                        Sheet =
                            SelectSheet (
                                Workbook,
                                "Лист1"
                            );

                        CopySheet (Sheet);

                        Sheet =
                            SelectSheet (
                                Workbook,
                                "Лист1 (2)"
                            );

                        AnsiString //cod_specializ1 = "1-88 02 01-01 ";
                        cod_specializ1 = NCRB_011::_2022::CODE::PHYSICAL_CULTURE;// + " ",

                        switch (DM -> QSpecializN_SPECIALIZ -> Value)           // специализация
                        {
                            case 4:
                                    //cod_specializ1 = "1-88 01 01-01 ";
                                    cod_specializ1 = NCRB_011::_2022::CODE::PHYSICAL_CULTURE + " ";
                                break;
                            case 57:
                                    //cod_specializ1 = "1-88 01 01-02 ";
                                    cod_specializ1 = NCRB_011::_2022::CODE::PHYSICAL_CULTURE + " ";
                                break;
                            case 38:
                                    //cod_specializ1 = "1-88 01 02-01 ";
                                    cod_specializ1 = NCRB_011::_2022::CODE::PHYSICAL_CULTURE + " ";
                                break;
                            case 39:
                                    //cod_specializ1 = "1-88 01 02-02 ";
                                    cod_specializ1 = NCRB_011::_2022::CODE::PHYSICAL_CULTURE + " ";
                                break;
                            case 3:
                                    //cod_specializ1 = "1-88 01 03-01 ";
                                    cod_specializ1 = NCRB_011::_2022::CODE::REHABILITATION + " ";
                                break;
                            case 47:
                                    //cod_specializ1 = "1-88 01 03-02 ";
                                    cod_specializ1 = NCRB_011::_2022::CODE::REHABILITATION + " ";
                                break;
                            case 48:
                                    //cod_specializ1 = "1-88 02 01-02 ";
                                    cod_specializ1 = NCRB_011::_2022::CODE::MANAGEMENT + " ";
                                break;
                            case 52:
                                    //cod_specializ1 = "1-88 02 01-03 ";
                                    cod_specializ1 = NCRB_011::_2022::CODE::PHYSICAL_CULTURE + " ";
                                break;
                            case 56:
                                    //cod_specializ1 = "1-88 02 01-04 ";
                                    cod_specializ1 = NCRB_011::_2022::CODE::PHYSICAL_CULTURE + " ";
                                break;
                            case 61:
                                    //cod_specializ1 = "1-89 01 01 ";
                                    cod_specializ1 = NCRB_011::_2022::CODE::TOURISM + " ";
                                break;
                            case 50:
                                    //cod_specializ1 = "1-89 02 01-01 ";
                                    cod_specializ1 = NCRB_011::_2022::CODE::PHYSICAL_CULTURE + " ";
                                break;
                            case 51:
                                    //cod_specializ1 = "1-89 02 01-02 ";
                                    cod_specializ1 = NCRB_011::_2022::CODE::MANAGEMENT + " ";
                                break;
                        }

                        CellValue (
                            cod_specializ1                              +
                            DM -> QSpecializSPECIAL_DIRECTION -> Value,
                            3,
                            7
                        );

                        AnsiString vid,
                                   pr;

                        switch (j)
                        {
                            case 0:
                                    vid = "дн ";

                                    CellValue (
                                        "дневная",
                                        3,
                                        8
                                    );
                                break;
                            case 1:
                                    vid = "заоч ";

                                    CellValue (
                                        "заочная",
                                        3,
                                        8
                                    );
                        }

                        switch (k)
                        {
                            case 0:
                                    pr = "";

                                    CellValue (
                                        "за счет средств республиканского " \
                                        "бюджета",
                                        3,
                                        9
                                    );
                                break;
                            case 1:
                                    pr = " опл ";

                                    CellValue (
                                        "на платной основе",
                                        3,
                                        9
                                    );
                        }

                        AnsiString sp1 =
                            vid                             +
                            pr                              +
                            DM -> QSpecializSPECIAL ->
                                Value.SetLength (24);

                        NameSheet1 (
                            Sheet,
                            sp1
                        );
                        nom_str =
                            Svod_ved (                                          // функция формирования сводной ведомости
                                nom_str,
                                2,
                                j,
                                rec_pred,
                                j,
                                1
                            );
                    }

                    DM -> QSpecializ -> Next ();
                }
            }
        }

        if (mas_pr)
            delete [] mas_pr;

        DM -> QSpecializ -> Close ();

        n_file =
            getReportNameWithCourseNumber (
                fac1,
                DocumentName::SUMMARY_LIST::ENROLLMENT,
                k_f
            );

        Variant WorkSaveAs =
            SaveBookAs (
                Workbook,
                PathTo::OUTPUT_DOCUMENTS_SLASH  +
                n_file
            );

        OVisible (ExcelApplication);

        ExcelApplication.Clear ();
    }
    else
    {
        ExcelApplication = Variant::CreateObject ("Excel.Application");

        Variant Workbook =
            OpenBook (
                ExcelApplication,
                cur_dir                                     +
                DocumentFile::SUMMARY_LIST::ENTRANCE_EXAMS
            );
        Sheet =
            SelectSheet (
                Workbook,
                "Лист1"
            );
        CellValue (
            "МСТиГ",
            3,
            6
        );


        DMVed -> QPredm -> Close ();                                            // Занесение названий предметов
        DMVed -> QPredm -> Open ();


        int rec_pred = 3;                                                       // количество предметов

        mas_pr = new AnsiString[rec_pred];

        mas_pr[0] = "Белорусский (русский) язык";

        CellValue (
            "Бел. (рус.) яз",
            9,
            12
        );


        mas_pr[2] = "Менеджмент в туризме";

        CellValue (
            "Менедж. в тур.",
            11,
            12
        );


        mas_pr[1] = "Экскурсоведение";

        CellValue (
            "Экскурсов.",
            10,
            12
        );


        DMVed -> QKonkurs -> Close ();                                          // дневное
        DMVed -> QKonkurs ->
            ParamByName ("IN_SP")      -> Value = 61;
        DMVed -> QKonkurs ->
            ParamByName ("IN_VID_EDU") -> Value = 0;
        DMVed -> QKonkurs ->
            ParamByName ("IN_KONK")    -> Value = 1;
        DMVed -> QKonkurs ->
            ParamByName ("IN_PRICE")   -> Value = 1;
        DMVed -> QKonkurs -> Open ();

        int nom_str1        = 13,                                               // Начальная переменная дла номера строки в Excel
            rec_q_two_kurs1 = DMVed -> QKonkurs -> RecordCount;

        if (rec_q_two_kurs1)
        {
            Sheet =
                SelectSheet (
                    Workbook,
                    "Лист1"
                );
            CopySheet (Sheet);
            Sheet =
                SelectSheet (
                    Workbook,
                    "Лист1 (2)"
                );
            CellValue (
                //"1-89 01 01 Туризм и гостериимство",
                    NCRB_011::_2022::CODE::TOURISM  +
                " "                                 +
                    NCRB_011::_2022::NAME::TOURISM,
                3,
                7
            );

            AnsiString vid = "дн ",
                       pr  = " опл ";

            CellValue (
                "дневная",
                3,
                8
            );
            CellValue (
                "на платной основе",
                3,
                9
            );

            AnsiString sp1 =
                vid                         +
                pr                          +
                "Туризм и гостеприимство";

            NameSheet1 (
                Sheet,
                sp1
            );
            nom_str1 =
                Svod_ved (                                                      // функция формирования сводной ведомости
                    nom_str1,
                    2,
                    0,
                    rec_pred,
                    1,
                    1
                );
        }


        DMVed -> QKonkurs -> Close ();                                          // заочное
        DMVed -> QKonkurs ->
            ParamByName ("IN_SP")      -> Value = 61;
        DMVed -> QKonkurs ->
            ParamByName ("IN_VID_EDU") -> Value = 1;
        DMVed -> QKonkurs ->
            ParamByName ("IN_KONK")    -> Value = 2;
        DMVed -> QKonkurs ->
            ParamByName ("IN_PRICE")   -> Value = 1;
        DMVed -> QKonkurs -> Open ();

        int nom_str2        = 13,                                               // Начальная переменная дла номера строки в Excel
            rec_q_two_kurs2 = DMVed -> QKonkurs -> RecordCount;

        if (rec_q_two_kurs2)
        {
            Sheet =
                SelectSheet (
                    Workbook,
                    "Лист1"
                );
            CellValue (
                //"1-89 01 01 Туризм и гостериимство",
                    NCRB_011::_2022::CODE::TOURISM  +
                " "                                 +
                    NCRB_011::_2022::NAME::TOURISM,
                3,
                7
            );

            AnsiString vid = "з ",
                       pr  = " опл ";

            CellValue (
                "заочная",
                3,
                8
            );
            CellValue (
                "платной основе",
                3,
                9
            );

            AnsiString sp1 =
                vid                         +
                pr                          +
                "Туризм и гостеприимство";

            NameSheet1 (
                Sheet,
                sp1
            );
            nom_str2 =
                Svod_ved (                                                      // функция формирования сводной ведомости
                    nom_str2,
                    2,
                    1,
                    rec_pred,
                    1,
                    1
            );
        }


        if (mas_pr)
            delete [] mas_pr;

        DM -> QSpecializ -> Close ();

        n_file =
            getReportNameWithCourseNumber (
                fac1,
                DocumentName::SUMMARY_LIST::ENTRANCE_EXAMS,
                k_f
            );

        Variant WorkSaveAs =
            SaveBookAs (
                Workbook,
                PathTo::OUTPUT_DOCUMENTS_SLASH  +
                n_file
            );
        OVisible (ExcelApplication);

        ExcelApplication.Clear ();
    }
}
void __fastcall TMainForm::N27Click (TObject * Sender)                          // Сводная ведомость (Заочка -> Бюджет)
{
    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N28Click (TObject * Sender)
{
    Dlg_ProtokolForm = new TDlg_ProtokolForm (this);

    TDateTime dat_prot;

    Dlg_ProtokolForm -> DateTimePicker1 -> Date =
        dat_prot.CurrentDate ();

    Dlg_ProtokolForm -> ShowModal ();
}
void __fastcall TMainForm::N30Click (TObject * Sender)                          // (CAN'T OPERATE!!!!) Подача заявлений по регионам
{
    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir                         +
            DocumentFile::REPORT::SUBMITTED
        );

    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );

    DisplayAlert (ExcelApplication);

    AnsiString n_file =
        getReportName (
            fac1,
            DocumentName::REPORT::SUBMITTED
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );
    OVisible (ExcelApplication);


    CellValue (                                                                 // факультет и дата
        fac1,
        1,
        4
    );
    CellValue (
        cur_d.CurrentDate (),
        22,
        3
    );

    nom_row = 9;
    int n_r;

    for ( int i = 0;                                                            // цикл по виду обучения
              i < 2;
              ++i
        )
    {
        if (!i)
            CellValue (
                "Дневное отделение",
                1,
                nom_row
            );
        else
            CellValue (
                "Заочное отделение",
                1,
                nom_row
            );

        MergeCellCenter (
            1,
            46,
            nom_row++
        );

        n_r = nom_row;


        DMStat -> QRegion_Stat -> Close ();                                     // количество абитуриентов по регионам (без 2-го курса)
        DMStat -> QRegion_Stat ->
            ParamByName ("N_FAC")   -> Value = nom_fac;
        DMStat -> QRegion_Stat ->
            ParamByName ("VID_EDU") -> Value = i;
        DMStat -> QRegion_Stat -> Open ();


        DM -> QPlan_Priem_All -> Close ();
        DM -> QPlan_Priem_All ->
            ParamByName ("N_FAC")   -> AsInteger = nom_fac;
        DM -> QPlan_Priem_All ->
            ParamByName ("VID_EDU") -> AsInteger = i;
        DM -> QPlan_Priem_All -> Open ();

        col_rec = DM -> QPlan_Priem_All -> RecordCount;

        for ( int j =  1;
                  j <= col_rec;
                  j++
            )
        {
            AllCount_spec (0);                                                  // Занесения абитуриентов по специализации (0 - чтоб не печатался № п/п в специализациях)

            DM -> QPlan_Priem_Konk -> Close ();                                 // Количество мест по каждому конкурсу
            DM -> QPlan_Priem_Konk ->
                ParamByName ("N_FAC")   -> AsInteger = nom_fac;
            DM -> QPlan_Priem_Konk ->
                ParamByName ("VID_EDU") -> AsInteger = i;
            DM -> QPlan_Priem_Konk ->
                ParamByName ("N_SP")    -> AsInteger = spec;
            DM -> QPlan_Priem_Konk -> Open ();

            for ( int s = 0;                                                    // Проход по местам выбранной специализации (конкурс в KOL_PLACE)
                      s < DM -> QPlan_Priem_Konk -> RecordCount;
                      ++s
                )
            {
                switch (DM -> QPlan_Priem_KonkTEXT -> Value)
                {
                    case 0:                                                     // город
                        if (DM -> QPlan_Priem_KonkKOL_PLACE -> Value)
                            CellFormula (                                       // Пропорционально поданных заявлений на город
                                "=B"                        +
                                    AnsiString (nom_row)    +
                                "-D"                        +
                                    AnsiString (nom_row)    +
                                "-E"                        +
                                    AnsiString (nom_row)    +
                                "-F"                        +
                                    AnsiString (nom_row),
                                3,
                                nom_row
                            );
                        break;
                    case 1:                                                     // село
                        break;
                    case 2:                                                     // ЦК
                            CellValue (
                                DM -> QPlan_Priem_KonkKOL_PLACE -> Value,
                                5,
                                nom_row
                            );
                        break;
                    case 3:                                                     // за оплату
                            CellValue (
                                DM -> QPlan_Priem_KonkKOL_PLACE -> Value,
                                6,
                                nom_row
                            );
                        break;
                }

                DM -> QPlan_Priem_Konk -> Next ();
            }


            int c = 0;                                                          // номера столбца, куда заносить кол-во поданных заявлений

            while (DMStat -> QRegion_StatN_SPECIALIZ -> Value == spec)          // Проход по регионам и конкурсам
            {
                switch (DMStat -> QRegion_StatN_REGION -> Value)                // номер региона
                {
                    case 1:                                                     // г.Минск
                            switch (DMStat -> QRegion_StatKONKURS -> Value)
                            {
                                case 0:                                         // 0 - город
                                        c = 7;
                                    break;
                                // case 1:                                         // 1 - село
                                //     break;
                                // case 2:                                         // 2 - КЦ
                                //     break;
                                // case 3:                                         // 3 - 2 курс (в этой статистике не используется)
                                //     break;
                                case 4:                                         // 4 - за оплату
                                        c = 9;                                  // c = 8;
                                    break;
                                case 5:                                         // 5 - Без экзаменов
                                        c = 10;                                 // c = 9;
                                    break;
                            }
                        break;
                    case 2:                                                     // Минская область
                            if (DMStat -> QRegion_StatKONKURS -> Value != 3)
                                c =
                                    10                                      +
                                    DMStat -> QRegion_StatKONKURS -> Value;
                        break;
                    case 3:                                                     // Брестская обл.
                            if (DMStat -> QRegion_StatKONKURS -> Value != 3)
                                c =
                                    15                                      +
                                    DMStat -> QRegion_StatKONKURS -> Value;
                        break;
                    case 4:                                                     // Гомельская обл.
                            if (DMStat -> QRegion_StatKONKURS -> Value != 3)
                                c =
                                    20                                      +
                                    DMStat -> QRegion_StatKONKURS -> Value;
                        break;
                    case 5:                                                     // Гродненская обл.
                            if (DMStat -> QRegion_StatKONKURS -> Value != 3)
                                c =
                                    25                                      +
                                    DMStat -> QRegion_StatKONKURS -> Value;
                        break;
                    case 6:                                                     // Витебская обл.
                            if (DMStat -> QRegion_StatKONKURS -> Value != 3)
                                c =
                                    30                                      +
                                    DMStat -> QRegion_StatKONKURS -> Value;
                        break;
                    case 7:                                                     // Могилевская обл.
                            if (DMStat -> QRegion_StatKONKURS -> Value != 3)
                                c =
                                    35                                      +
                                    DMStat -> QRegion_StatKONKURS -> Value;
                        break;
                    case 8:
                            c = 40;                                             // Другие республики
                        break;
                }


                if (    DMStat -> QRegion_StatN_REGION -> Value != 8            // из-за пропуска 2-го курса конкурс 4-5 уменьшаем на 1
                     && (   DMStat -> QRegion_StatKONKURS -> Value == 4
                         || DMStat -> QRegion_StatKONKURS -> Value == 5
                        )
                   )
                    c--;


                if (c)
                    CellValue (
                        DMStat -> QRegion_StatCOUNT -> Value,
                        c,
                        nom_row
                    );

                if ( ! DMStat -> QRegion_Stat -> Eof)
                    DMStat -> QRegion_Stat -> Next ();
                else
                    break;
            }


            AnsiString n_row = AnsiString (nom_row);                            // ALIAS


            CellFormula (                                                       // Графа (итого) по городу
                "=СУММ(G"   +
                    n_row   +
                ";J"        +
                    n_row   +
                ";O"        +
                    n_row   +
                ";T"        +
                    n_row   +
                ";Y"        +
                    n_row   +
                ";AD"       +
                    n_row   +
                ";AI"       +
                    n_row   +
                ")",
                41,
                nom_row
            );

            CellFormula (                                                       // Графа (итого) по селу
                "=СУММ(K"   +
                    n_row   +
                ";P"        +
                    n_row   +
                ";U"        +
                    n_row   +
                ";Z"        +
                    n_row   +
                ";AE"       +
                    n_row   +
                ";AJ"       +
                    n_row   +
                ")",
                42,
                nom_row
            );


            int all_selo =
                GetCellValue (
                    42,
                    nom_row
                )
                .AsType (varInteger);


            if (all_selo)                                                       // Расчет мест для сельчан
            {
                CellFormula (
                    "=ОКРУГЛВВЕРХ(((B"          +
                        AnsiString (nom_row)    +
                    "-E"                        +
                        AnsiString (nom_row)    +
                    "-F"                        +
                        AnsiString (nom_row)    +
                    ")*AP"                      +
                        AnsiString (nom_row)    +
                    "/(AO"                      +
                        AnsiString (nom_row)    +
                    "+AP"                       +
                        AnsiString (nom_row)    +
                    "+AS"                       +
                        AnsiString (nom_row)    +
                    "));0)"                     ,
                    4,
                    nom_row
                );
            }


            CellFormula (                                                       // по ЦК
                "=СУММ(L"       +
                    n_row       +
                ";Q"            +
                    n_row       +
                ";V"            +
                    n_row       +
                ";AA"           +
                    n_row       +
                ";AF"           +
                    n_row       +
                ";AK"           +
                    n_row       +
                ")",
                43,
                nom_row
            );

            CellFormula (                                                       // по конкурсу: за оплату
                "=СУММ(H"       +
                    n_row       +
                ";M"            +
                    n_row       +
                ";R"            +
                    n_row       +
                ";W"            +
                    n_row       +
                ";AB"           +
                    n_row       +
                ";AG"           +
                    n_row       +
                ";AL"           +
                    n_row       +
                ")",
                44,
                nom_row
            );

            CellFormula (                                                       // по конкурсу: БЕЗ ЭКЗАМЕНОВ
                "=СУММ(I"       +
                n_row           +
                ";N"            +
                    n_row       +
                ";S"            +
                    n_row       +
                ";X"            +
                    n_row       +
                ";AC"           +
                    n_row       +
                ";AH"           +
                    n_row       +
                ";AM"           +
                    n_row       +
                ")",
                45,
                nom_row
            );

            CellFormula (                                                       // всего (город + село + ЦК + без экзаменов+за оплату + др.республики)
                "=СУММ(AN"      +
                    n_row       +
                ":AS"           +
                    n_row       +
                ")",
                46,
                nom_row
            );

            DM -> QPlan_Priem_All -> Next ();

            ++nom_row;
        }


        for ( int i = 1;                                                        // Обрамление всех ячеек
                  i < 47;
                  ++i
            )
            for ( int j =  n_r;
                      j <= nom_row;
                      ++j
                )
                BorderCell (
                    i,
                    j,
                    1,
                    2
                );


        CellValue (
            "ИТОГО:",
            1,
            nom_row
        );
        CicleSum (
            n_r,
            nom_row,
            2,
            46,
            0
        );

        nom_row++;
    }


    CellValue (
        "Итого по ф-ту:",
        1,
        nom_row
    );
    BorderCell (
        1,nom_row,
        1,
        2
    );
    CicleSum (
        n_r,
        nom_row,
        2,
        46,
        1
    );


    CellValue (
        "Ответственный секретарь приемной комиссии:",
        1,
        nom_row + 2
    );
    CellValue (
        LegallyAuthorizedPerson::SECRETARY,
        21,
        nom_row + 2
    );

    WorkSaveAs = SaveBook (Workbook);                                           // сохранение
}
void __fastcall TMainForm::N31Click (TObject * Sender)                          // Форма 3 (дневная и заочная) (CAN'T OPERATE!!!!)
{
    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir             +
            DocumentFile::REPORT::FORM_2
        );

    Sheet =
        SelectSheet (
            Workbook,
            "Дневное"
        );

    int vid_educ;                                                               // переменная вида обучения

    for ( vid_educ = 0;                                                         // цикл для дневного и заочного обучения
          vid_educ < 2;
          ++vid_educ
        )
    {
        if (vid_educ)                                                           // заочное
            Sheet =
                SelectSheet (
                    Workbook,
                    "Заочное"
                );

        DMStat -> QSpecial -> Open ();


        int rec_spec = DMStat -> QSpecial -> RecordCount;


        for ( int k = 0;
                  k < 2;
                  ++k
            )
            mas_spec_str[k] = new int[rec_spec];


        for ( int i = 0;                                                        // массив специальностей
                  i < rec_spec;
                  ++i
            )
        {
            mas_spec_str[0][i] =
                DMStat -> QSpecialN_SPEC -> Value;

            mas_spec_str[1][i] =
                i + 17;

            DMStat -> QSpecial -> Next ();
        }


        DMStat -> QF2_All_Sdal ->                                               // сдавали вступительные экзамены (действующие (0), отриц.оценка (2), забрал док-ты во время экз (4) и зачисленные (5))
            ParamByName ("V_E") -> AsInteger = vid_educ;
        DMStat -> QF2_All_Sdal -> Open ();


        for ( int j = 0;                                                        // общее количество сдававших вступительные экзамены
                  j < DMStat -> QF2_All_Sdal -> RecordCount;
                  ++j
            )
        {
            CellValue (
                DMStat -> QF2_All_SdalCOUNT -> Value,
                4,
                Find_nom_spec_str (
                    DMStat -> QF2_All_SdalN_SPEC -> Value,
                    rec_spec
                )
            );

            DMStat -> QF2_All_Sdal -> Next ();
        }


        DMStat -> QF2_Sdal ->                                                   // Выдержали вступительные экзамены (действующие (0) и зачисленные (5))
            ParamByName ("V_E") -> AsInteger = vid_educ;
        DMStat -> QF2_Sdal -> Open ();

        for ( int j = 0;                                                        // for Выдержали вступительные экзамены
                  j < DMStat -> QF2_Sdal -> RecordCount;
                  j++
            )
        {
            CellValue (
                DMStat -> QF2_SdalCOUNT -> Value,
                5,
                Find_nom_spec_str (
                    DMStat -> QF2_SdalN_SPEC -> Value,
                    rec_spec
                )
            );

            DMStat -> QF2_Sdal -> Next ();
        }


        DMStat -> QF2_Zach -> Close ();                                         // ГРАФА 3 (Усяго гр 4+гр 5) Всего зачисленных
        DMStat -> QF2_Zach -> SQL -> Clear ();
        DMStat -> QF2_Zach -> SQL ->
            Add (
                " SELECT"                       \
                "     n_spec,"                  \
                "     COUNT"                    \
                "     ("                        \
                "         nomer_ab"             \
                "     )"                        \
                " FROM"                         \
                "     abitura"                  \
                " WHERE"                        \
                "         status  =  5"         \
                "     AND"                      \
                "         vid_edu =  :V_E"      \
                "     AND"                      \
                "         n_spec  <> 1"         \
                " GROUP BY"                     \
                "     n_spec"
            );
        DMStat -> QF2_Zach ->                                                   // Всего зачисленных (дневное или заочное)
            ParamByName ("V_E") -> AsInteger = vid_educ;
        DMStat -> QF2_Zach -> Open ();

        for ( int j = 0;                                                        // for Всего зачисленных
                  j < DMStat -> QF2_Zach -> RecordCount;
                  j++
            )
        {
            CellValue (
                DMStat -> QF2_ZachCOUNT -> Value,
                6,
                Find_nom_spec_str (
                    DMStat -> QF2_ZachN_SPEC -> Value,
                    rec_spec
                )
            );

            DMStat -> QF2_Zach -> Next ();
        }


        DMStat -> QF2_Zach -> Close ();                                         // ГРАФА 4 по плану приема
        DMStat -> QF2_Zach -> SQL -> Clear ();
        DMStat -> QF2_Zach -> SQL ->
            Add (
                " SELECT"                       \
                "     n_spec,"                  \
                "     COUNT"                    \
                "     ("                        \
                "         nomer_ab"             \
                "     )"                        \
                " FROM"                         \
                "     abitura"                  \
                " WHERE"                        \
                "         status  =  5"         \
                "     AND"                      \
                "         konkurs <> 4"         \
                "     AND"                      \
                "         vid_edu =  :V_E"      \
                "     AND"                      \
                "         n_spec  <> 1"         \
                "     AND"                      \
                "         n_found <> 2"         \
                " GROUP BY"                     \
                "     n_spec"
            );
        DMStat -> QF2_Zach ->                                                   // Всего зачисленных на бюджет (дневное или заочное)
            ParamByName ("V_E") -> AsInteger = vid_educ;
        DMStat -> QF2_Zach -> Open ();

        for ( int j = 0;                                                        // for Всего зачисленных на бюджет
                  j < DMStat -> QF2_Zach -> RecordCount;
                  ++j
            )
        {
            CellValue (
                DMStat -> QF2_ZachCOUNT -> Value,
                7,
                Find_nom_spec_str (
                    DMStat -> QF2_ZachN_SPEC -> Value,
                    rec_spec
                )
            );

            DMStat -> QF2_Zach -> Next ();
        }


        DMStat -> QF2_Zach -> Close ();                                         // ГРАФА 5  зачисленные за оплату
        DMStat -> QF2_Zach -> SQL -> Clear ();
        DMStat -> QF2_Zach ->
            SQL ->
                Add (
                    " SELECT"                       \
                    "     n_spec,"                  \
                    "     COUNT"                    \
                    "     ("                        \
                    "         nomer_ab"             \
                    "     )"                        \
                    " FROM"                         \
                    "     abitura"                  \
                    " WHERE"                        \
                    "         status  =  5"         \
                    "     AND"                      \
                    "         vid_edu =  :V_E"      \
                    "     AND"                      \
                    "         n_spec  <> 1"         \
                    "     AND"                      \
                    "         n_found =  2"         \
                    " GROUP BY"                     \
                    "     n_spec"
                );


        DMStat -> QF2_Zach ->                                                   // Всего зачисленных  за оплату (дневное или заочное)
            ParamByName ("V_E") -> AsInteger = vid_educ;
        DMStat -> QF2_Zach -> Open ();


        for ( int j = 0;                                                        // for Всего зачисленных  за оплату
                  j < DMStat -> QF2_Zach -> RecordCount;
                  ++j
            )
        {
            CellValue (
                DMStat -> QF2_ZachCOUNT -> Value,
                8,
                Find_nom_spec_str (
                    DMStat -> QF2_ZachN_SPEC -> Value,
                    rec_spec
                )
            );

            DMStat -> QF2_Zach -> Next ();
        }


        if ( ! vid_educ)                                                        // только для дневной формы обучения (прошли ПО)
        {
            DMStat -> QCount_PO -> Close ();
            DMStat -> QCount_PO -> SQL -> Clear ();
            DMStat -> QCount_PO ->
                SQL ->
                    Add (
                        " SELECT"                       \
                        "     COUNT"                    \
                        "     ("                        \
                        "         fam"                  \
                        "     ),"                       \
                        "     n_spec"                   \
                        " FROM"                         \
                        "     abitura"                  \
                        " WHERE"                        \
                        "         priv    LIKE '15.'"   \
                        "     AND"                      \
                        "         status  =    :ST"     \
                        "     AND"                      \
                        "         vid_edu =    0"       \
                        "     AND"                      \
                        "         n_spec  <>   1"       \
                        " GROUP BY"                     \
                        "     n_spec"
                    );


            DMStat -> QCount_PO ->
                ParamByName ("ST") -> AsInteger = 5;
            DMStat -> QCount_PO -> Open ();


            for ( int j = 0;                                                    // вычисление количества абитуриентов, окончивших ПО
                      j < DMStat -> QCount_PO -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_POCOUNT -> Value,
                    9,
                    Find_nom_spec_str (
                        DMStat -> QCount_PON_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_PO -> Next ();
            }
        }


        DMStat -> QCount_Medal -> Close ();                                     // ГРАФА 7 (Медалисты школ, которые поступили)
        DMStat -> QCount_Medal -> SQL -> Clear ();
        DMStat -> QCount_Medal ->
            SQL ->
                Add (
                    " SELECT"                       \
                    "     COUNT"                    \
                    "     ("                        \
                    "         fam"                  \
                    "     ),"                       \
                    "     n_spec"                   \
                    " FROM"                         \
                    "     abitura"                  \
                    " WHERE"                        \
                    "         status  =    :ST"     \
                    "     AND"                      \
                    "         vid_edu =    :EDU"    \
                    "     AND"                      \
                    "         n_spec  <>   1"       \
                    "     AND"                      \
                    "         priv    LIKE '12.'"   \
                    " GROUP BY"                     \
                    "     n_spec"
                );


        DMStat -> QCount_Medal ->
            ParamByName ("ST")  -> AsInteger = 5;

        DMStat -> QCount_Medal ->
            ParamByName ("EDU") -> AsInteger = vid_educ;

        DMStat -> QCount_Medal -> Open ();


        for ( int j = 0;                                                        // Расчет кол-ва окончивших школу с медалью (поступили)
                  j < DMStat -> QCount_Medal -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_MedalCOUNT -> Value,
                    9,
                    Find_nom_spec_str (
                        DMStat -> QCount_MedalN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_MedalCOUNT -> Value,
                    10,
                    Find_nom_spec_str (
                        DMStat -> QCount_MedalN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Medal -> Next ();
        }


        DMStat -> QCount_Diplom -> Close ();                                    // ГРАФА 8 Дипломы с отличием, которые поступили
        DMStat -> QCount_Diplom -> SQL -> Clear ();
        DMStat -> QCount_Diplom ->
            SQL ->
                Add (
                    " SELECT"                       \
                    "     COUNT"                    \
                    "     ("                        \
                    "         fam"                  \
                    "     ),"                       \
                    "     n_spec"                   \
                    " FROM"                         \
                    "     abitura"                  \
                    " WHERE"                        \
                    "         status  =    :ST"     \
                    "     AND"                      \
                    "         vid_edu =    :EDU"    \
                    "     AND"                      \
                    "         n_spec  <>   1"       \
                    "     AND"                      \
                    "         priv    LIKE '13.'"   \
                    " GROUP BY"                     \
                    "     n_spec"
                );


        DMStat -> QCount_Diplom ->
            ParamByName ("ST")  -> AsInteger = 5;
        DMStat -> QCount_Diplom ->
            ParamByName ("EDU") -> AsInteger = vid_educ;
        DMStat -> QCount_Diplom -> Open ();


        for ( int j = 0;                                                        // Расчет количества окончивших ССУЗ и т.д. с отличием
                  j < DMStat -> QCount_Diplom -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_DiplomCOUNT -> Value,
                    10,
                    Find_nom_spec_str (
                        DMStat -> QCount_DiplomN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_DiplomCOUNT -> Value,
                    11,
                    Find_nom_spec_str (
                        DMStat -> QCount_DiplomN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Diplom -> Next ();
        }


        if ( ! vid_educ)                                                        // ГРАФА 9  закончили лицеии и гимназии (только дневное)
        {
            DMStat -> QCount_Gimn -> Close ();
            DMStat -> QCount_Gimn -> SQL -> Clear ();
            DMStat -> QCount_Gimn ->
                SQL ->
                    Add (
                        " SELECT"                       \
                        "     COUNT"                    \
                        "     ("                        \
                        "         fam"                  \
                        "     ),"                       \
                        "     n_spec"                   \
                        " FROM"                         \
                        "     abitura"                  \
                        " WHERE"                        \
                        "         stat_ab LIKE '3'"     \
                        "     AND"                      \
                        "         status  =    :ST"     \
                        "     AND"                      \
                        "         vid_edu =    :EDU"    \
                        "     AND"                      \
                        "         n_spec  <>   1"       \
                        " GROUP BY"                     \
                        "     n_spec"
                    );


            DMStat -> QCount_Gimn ->
                ParamByName ("ST")  -> AsInteger = 5;
            DMStat -> QCount_Gimn ->
                ParamByName ("EDU") -> AsInteger = 0;
            DMStat -> QCount_Gimn -> Open ();


            for ( int j = 0;                                                    // Расчет кол-ва окончивших лицей или гимназию
                      j < DMStat -> QCount_Gimn -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_GimnCOUNT -> Value,
                    12,
                    Find_nom_spec_str (
                        DMStat -> QCount_GimnN_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_Gimn -> Next ();
            }
        }
        else                                                                    // только заочное п.21 складывается
        {
            DMStat -> QCount_Olimp -> Close ();
            DMStat -> QCount_Olimp -> SQL -> Clear ();
            DMStat -> QCount_Olimp ->
                SQL ->
                    Add (
                        " SELECT"                           \
                        "     COUNT"                        \
                        "     ("                            \
                        "         fam"                      \
                        "     ),"                           \
                        "     n_spec"                       \
                        " FROM"                             \
                        "     abitura"                      \
                        " WHERE"                            \
                        "         ("                        \
                        "             without LIKE '1'"     \
                        "          OR"                      \
                        "             without LIKE '2'"     \
                        "          OR"                      \
                        "             without LIKE '3'"     \
                        "          OR"                      \
                        "             without LIKE '4'"     \
                        "         )"                        \
                        "     AND"                          \
                        "         status  =  :ST"           \
                        "     AND"                          \
                        "         vid_edu =  :EDU"          \
                        "     AND"                          \
                        "         n_spec  <> 1"             \
                        " GROUP BY"                         \
                        "     n_spec"
                    );


            DMStat -> QCount_Olimp ->
                ParamByName ("ST")  -> AsInteger = 5;
            DMStat -> QCount_Olimp ->
                ParamByName ("EDU") -> AsInteger = vid_educ;
            DMStat -> QCount_Olimp -> Open ();


            for ( int j = 0;
                      j < DMStat -> QCount_Olimp -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_OlimpCOUNT -> Value,
                    11,
                    Find_nom_spec_str (
                        DMStat -> QCount_OlimpN_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_Olimp -> Next ();
            }
        }


        AnsiString SQL_Gorod =                                                  // ВЫПУСКНИКИ СЕЛЬСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ - ВСЕХ
            " SELECT"                                   \
            "     COUNT"                                \
            "     ("                                    \
            "         fam"                              \
            "     ),"                                   \
            "     n_spec"                               \
            " FROM"                                     \
            "     abitura"                              \
            " WHERE"                                    \
            "         stat_ab LIKE :N"                  \
            "     AND"                                  \
            "         status  =    :ST"                 \
            "     AND"                                  \
            "         vid_edu =    :EDU"                \
            "     AND"                                  \
            "         n_spec  <>   1"                   \
            "     AND"                                  \
            "         ("                                \
            "             when_edu_middle LIKE :GOD"    \
            "          OR"                              \
            "             when_edu_spec   LIKE :GOD"    \
            "         )"                                \
            " GROUP BY"                                 \
            "     n_spec";

        DMStat -> QCount_Gorod -> Close ();
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add
                (
                    SQL_Gorod
                );


        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "4";                        // сельские
        DMStat -> QCount_Gorod ->
            ParamByName ("ST")  -> AsSmallInt = 5;
        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;
        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "%";

        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // Расчет кол-ва окончивших сельские УО
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    12,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    13,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Gorod -> Next ();
        }


        DMStat -> QCount_Gorod -> Close ();                                     // ВЫПУСКНИКИ СЕЛЬСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ - Только текущего года
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add
                (
                    SQL_Gorod
                );

        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "4";                            // сельские

        DMStat -> QCount_Gorod ->
            ParamByName ("ST")  -> AsSmallInt = 5;

        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;

        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "2006";

        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // Расчет кол-ва окончивших сельские УО
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    13,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    14,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Gorod -> Next ();
        }


        DMStat -> QCount_Gorod -> Close ();                                     // ВЫПУСКНИКИ ГОРОДСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ - ВСЕХ
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add
                (
                    SQL_Gorod
                );


        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "5";                            // городские

        DMStat -> QCount_Gorod ->
            ParamByName ("ST")  -> AsSmallInt = 5;

        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;

        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "%";

        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // Расчет кол-ва окончивших городские УО
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    14,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    15,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Gorod -> Next ();
        }


        DMStat -> QCount_Gorod -> Close ();                                     // ВЫПУСКНИКИ ГОРОДСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ - Только текущего года
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add
                (
                    SQL_Gorod
                );


        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "5";                            // городские

        DMStat -> QCount_Gorod ->
            ParamByName ("ST")  -> AsSmallInt = 5;

        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;

        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "2006";

        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // вычисление количества абитуриентов, окончивших городские УО
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    15,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    16,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Gorod -> Next ();
        }


        DMStat -> QCount_Stag -> Close ();                                      // СТАЖ БОЛЕЕ 2-х ЛЕТ
        DMStat -> QCount_Stag -> SQL -> Clear ();
        DMStat -> QCount_Stag ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     COUNT"                        \
                    "     ("                            \
                    "         fam"                      \
                    "     ),"                           \
                    "     n_spec"                       \
                    " FROM"                             \
                    "     abitura"                      \
                    " WHERE"                            \
                    "         ("                        \
                    "             stag      >= 24"      \
                    "          OR"                      \
                    "             stag_spec >= 24"      \
                    "         )"                        \
                    "     AND"                          \
                    "         status  =  :ST"           \
                    "     AND"                          \
                    "         vid_edu =  :EDU"          \
                    "     AND"                          \
                    "         n_spec  <> 1"             \
                    " GROUP BY"                         \
                    "     n_spec"
                );


        DMStat -> QCount_Stag ->
            ParamByName ("ST")  -> AsInteger = 5;
        DMStat -> QCount_Stag ->
            ParamByName ("EDU") -> AsInteger = vid_educ;
        DMStat -> QCount_Stag -> Open ();


        for ( int j = 0;                                                        // вычисление количества абитуриентов,имеющих стаж более 2-х лет
                  j < DMStat -> QCount_Stag -> RecordCount;
                  ++j
                  )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_StagCOUNT -> Value,
                    16,
                    Find_nom_spec_str (
                        DMStat -> QCount_StagN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_StagCOUNT -> Value,
                    17,
                    Find_nom_spec_str (
                        DMStat -> QCount_StagN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Stag -> Next ();
        }


        if ( ! vid_educ)                                                        // if только дневное
        {
            DMStat -> QCount_Region -> Close ();                                // ГРАЖДАНЕ РФ, КАЗАХСТАНА, КЫРГЫЗТАНА, ТАДЖЫКИСТАНА
            DMStat -> QCount_Region -> SQL -> Clear ();
            DMStat -> QCount_Region ->
                SQL ->
                    Add (
                        " SELECT"                                   \
                        "     COUNT"                                \
                        "     ("                                    \
                        "         --   fam"                         \
                        "         nomer_ab"                         \
                        "     ),"                                   \
                        "     n_spec"                               \
                        " FROM"                                     \
                        "     abitura"                              \
                        " WHERE"                                    \
                        "         gragdan  <> 'РБ'"                 \
                        "     AND"                                  \
                        "         status   =  :ST"                  \
                        "     AND"                                  \
                        "         vid_edu  =  :EDU"                 \
                        "     AND"                                  \
                        "         n_spec   <> 1"                    \
                        "     AND"                                  \
                        "         n_centre in (122,123,124,125)"    \
                        " GROUP BY"                                 \
                        "     n_spec"                               \
                        " ORDER BY"                                 \
                        "     n_spec"
                    );


            DMStat -> QCount_Region ->
                ParamByName ("ST")  -> AsInteger = 5;
            DMStat -> QCount_Region ->
                ParamByName ("EDU") -> AsInteger = 0;
            DMStat -> QCount_Region -> Open ();


            for ( int j = 0;                                                    // вычисление количества абитуриентов из других республик
                      j < DMStat -> QCount_Region -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_RegionCOUNT -> Value,
                    18,
                    Find_nom_spec_str (
                        DMStat -> QCount_RegionN_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_Region -> Next ();
            }
        }
        else                                                                    // только заочное
        {
            DMStat -> QCount_High -> Close ();                                  // ДЛЯ ПОЛУЧЕНИЕ ВТОРОГО ВЫСШЕГО ОБРАЗОВАНИЯ
            DMStat -> QCount_High -> SQL -> Clear ();
            DMStat -> QCount_High ->
                SQL ->
                    Add (
                        " SELECT"                           \
                        "     COUNT"                        \
                        "     ("                            \
                        "         fam"                      \
                        "     ),"                           \
                        "     n_spec"                       \
                        " FROM"                             \
                        "     abitura"                      \
                        " WHERE"                            \
                        "         status  = :ST"            \
                        "     AND"                          \
                        "         vid_edu = :EDU"           \
                        "     AND"                          \
                        "         ("                        \
                        "             without LIKE '5'"     \
                        "          OR"                      \
                        "             v_k     LIKE '5'"     \
                        "          OR"                      \
                        "             stat_ab LIKE '8'"     \
                        "         )"                        \
                        "     AND"                          \
                        "         n_spec <> 1"              \
                        " GROUP BY"                         \
                        "     n_spec"
                    );


            DMStat -> QCount_High ->
                ParamByName ("ST")  -> AsInteger = 5;
            DMStat -> QCount_High ->
                ParamByName ("EDU") -> AsInteger = vid_educ;
            DMStat -> QCount_High -> Open ();


            for ( int j = 0;                                                    // вычисление количества абитуриентов на 2-ое высшее
                      j < DMStat -> QCount_High -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_HighCOUNT -> Value,
                    21,
                    Find_nom_spec_str (
                        DMStat -> QCount_HighN_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_High -> Next ();
            }
        }


        DMStat -> QCount_Test -> Close ();                                      // СЕРТИФИКАТЫ ЦЕНТРАЛИЗОВАННОГО ТЕСТИРОВАНИЯ ЦТ = 3
        DMStat -> QCount_Test -> SQL -> Clear ();
        DMStat -> QCount_Test ->
            SQL ->
                Add (
                    " SELECT"                                                     \
                    "     COUNT"                                                  \
                    "     ("                                                      \
                    "         abitura.nomer_ab"                                   \
                    "     ),"                                                     \
                    "     abitura.n_spec"                                         \
                    " FROM"                                                       \
                    "     abitura"                                                \
                    " WHERE"                                                      \
                    "         EXISTS"                                             \
                    "         ("                                                  \
                    "             SELECT"                                         \
                    "                 sertificat.nomer_ab"                        \
                    "             FROM"                                           \
                    "                 sertificat"                                 \
                    "             WHERE"                                          \
                    "                 sertificat.nomer_ab =  abitura.nomer_ab"    \
                    "             GROUP BY"                                       \
                    "                 sertificat.nomer_ab"                        \
                    "             HAVING COUNT"                                   \
                    "             ("                                              \
                    "                 sertificat.n_predmet"                       \
                    "             ) = 3"                                          \
                    "         )"                                                  \
                    "     AND"                                                    \
                    "         abitura.status  =  :ST"                             \
                    "     AND"                                                    \
                    "         abitura.vid_edu =  :EDU"                            \
                    "     AND"                                                    \
                    "         abitura.n_spec  <> 1"                               \
                    " GROUP BY"                                                   \
                    "     abitura.n_spec"
                );


        DMStat -> QCount_Test ->
            ParamByName ("ST")  -> AsInteger = 5;
        DMStat -> QCount_Test ->
            ParamByName ("EDU") -> AsInteger = vid_educ;
        DMStat -> QCount_Test -> Open ();


        for ( int j = 0;                                                        // вычисление количества абитуриентов на платное ЦТ = 3
                  j < DMStat -> QCount_Test -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_TestCOUNT -> Value,
                    17,
                    Find_nom_spec_str (
                        DMStat -> QCount_TestN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_TestCOUNT -> Value,
                    19,
                    Find_nom_spec_str (
                        DMStat -> QCount_TestN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Test -> Next ();
        }


        DMStat -> QF2_Sdal -> Close ();                                         // Зачислены по испытанию в данном вузе (зачисленные (5))
        DMStat -> QF2_Sdal -> SQL -> Clear ();
        DMStat -> QF2_Sdal ->
            SQL ->
                Add (
                    " SELECT"                                                          \
                    "     abitura.n_spec,"                                             \
                    "     COUNT"                                                       \
                    "     ("                                                           \
                    "         abitura.nomer_ab"                                        \
                    "     )"                                                           \
                    " FROM"                                                            \
                    "     abitura"                                                     \
                    " WHERE"                                                           \
                    "         abitura.status  IN (5)"                                  \
                    "     AND"                                                         \
                    "         abitura.konkurs <> 5"                                    \
                    "     AND"                                                         \
                    "         abitura.vid_edu =  :V_E"                                 \
                    "     AND"                                                         \
                    "         abitura.n_spec  <> 1"                                    \
                    "     AND"                                                         \
                    "         NOT EXISTS"                                              \
                    "         ("                                                       \
                    "             SELECT"                                              \
                    "                 sertificat.nomer_ab"                             \
                    "             FROM"                                                \
                    "                 sertificat"                                      \
                    "             WHERE"                                               \
                    "                 sertificat.nomer_ab = abitura.nomer_ab"          \
                    "             GROUP BY"                                            \
                    "                 sertificat.nomer_ab"                             \
                    "             HAVING COUNT"                                        \
                    "             ("                                                   \
                    "                 sertificat.n_predmet"                            \
                    "             ) = 3"                                               \
                    "         )"                                                       \
                    "     AND"                                                         \
                    "         EXISTS"                                                  \
                    "         ("                                                       \
                    "             SELECT"                                              \
                    "                 DISTINCT"                                        \
                    "                     examen.nomer_ab"                             \
                    "             FROM"                                                \
                    "                 examen"                                          \
                    "             WHERE"                                               \
                    "                     examen.nomer_ab    = abitura.nomer_ab"       \
                    "                 AND"                                             \
                    "                     examen.status_ball = 0"                      \
                    "             GROUP BY"                                            \
                    "                 examen.nomer_ab"                                 \
                    "         )"                                                       \
                    " GROUP BY"                                                        \
                    "     abitura.n_spec"
                );


        DMStat -> QF2_Sdal ->
            ParamByName ("V_E") -> AsInteger = vid_educ;
        DMStat -> QF2_Sdal -> Open ();


        for ( int j = 0;                                                        // for  Зачислены по испытанию в данном вузе
                  j < DMStat -> QF2_Sdal -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QF2_SdalCOUNT -> Value,
                    18,
                    Find_nom_spec_str (
                        DMStat -> QF2_SdalN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QF2_SdalCOUNT -> Value,
                    20,
                    Find_nom_spec_str (
                        DMStat -> QF2_SdalN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QF2_Sdal -> Next ();
        }


        DMStat -> QF2_Sdal -> Close ();                                         // Зачислены по испытанию в другом вузе (зачисленные (5))
        DMStat -> QF2_Sdal -> SQL -> Clear ();
        DMStat -> QF2_Sdal ->
            SQL ->
                Add (
                    " SELECT"                                                          \
                    "     abitura.n_spec,"                                             \
                    "     COUNT"                                                       \
                    "     ("                                                           \
                    "         abitura.nomer_ab"                                        \
                    "     )"                                                           \
                    " FROM"                                                            \
                    "     abitura"                                                     \
                    " WHERE"                                                           \
                    "         abitura.status  IN (5)"                                  \
                    "     AND"                                                         \
                    "         abitura.konkurs <> 5"                                    \
                    "     AND"                                                         \
                    "         abitura.vid_edu =  :V_E"                                 \
                    "     AND"                                                         \
                    "         abitura.n_spec  <> 1"                                    \
                    "     AND"                                                         \
                    "         NOT EXISTS"                                              \
                    "         ("                                                       \
                    "             SELECT"                                              \
                    "                 sertificat.nomer_ab"                             \
                    "             FROM"                                                \
                    "                 sertificat"                                      \
                    "             WHERE"                                               \
                    "                 sertificat.nomer_ab =  abitura.nomer_ab"         \
                    "             GROUP BY"                                            \
                    "                 sertificat.nomer_ab"                             \
                    "             HAVING COUNT"                                        \
                    "             ("                                                   \
                    "                 sertificat.n_predmet"                            \
                    "             ) = 3"                                               \
                    "         )"                                                       \
                    "     AND"                                                         \
                    "         EXISTS"                                                  \
                    "         ("                                                       \
                    "             SELECT"                                              \
                    "                 DISTINCT"                                        \
                    "                     examen.nomer_ab"                             \
                    "             FROM"                                                \
                    "                 examen"                                          \
                    "             WHERE"                                               \
                    "                     examen.nomer_ab    = abitura.nomer_ab"       \
                    "                 AND"                                             \
                    "                     examen.status_ball = 3"                      \
                    "             GROUP BY"                                            \
                    "                 examen.nomer_ab"                                 \
                    "         )"                                                       \
                    " GROUP BY"                                                        \
                    "     abitura.n_spec"
                );


        DMStat -> QF2_Sdal ->
            ParamByName ("V_E") -> AsInteger = vid_educ;

        DMStat -> QF2_Sdal -> Open ();


        for ( int j = 0;                                                        // Зачислены по испытанию в другом вузе (дневное или заочное)
                  j < DMStat -> QF2_Sdal -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QF2_SdalCOUNT -> Value,
                    19,
                    Find_nom_spec_str (
                        DMStat -> QF2_SdalN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QF2_SdalCOUNT -> Value,
                    21,
                    Find_nom_spec_str (
                        DMStat -> QF2_SdalN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QF2_Sdal -> Next ();
        }


        DMStat -> QCount_RUOR -> Close ();                                      // НА СОКРАЩЕННЫЙ СРОК ОБУЧЕНИЯ (2 курс - РУОР, 3 курс - ОФКиТ (с 2005))
        DMStat -> QCount_RUOR -> SQL -> Clear ();
        DMStat -> QCount_RUOR ->
            SQL ->
                Add (
                    " SELECT"                       \
                    "     COUNT"                    \
                    "     ("                        \
                    "         fam"                  \
                    "     ),"                       \
                    "     n_spec"                   \
                    " FROM"                         \
                    "     abitura"                  \
                    " WHERE"                        \
                    "         status  =  :ST"       \
                    "     AND"                      \
                    "         vid_edu =  :EDU"      \
                    "     AND"                      \
                    "         konkurs =  3"         \
                    "     AND"                      \
                    "         n_spec  <> 1"         \
                    " GROUP BY"                     \
                    "     n_spec"
                );


        DMStat -> QCount_RUOR ->
            ParamByName ("ST")  -> AsInteger = 5;
        DMStat -> QCount_RUOR ->
            ParamByName ("EDU") -> AsInteger = vid_educ;
        DMStat -> QCount_RUOR -> Open ();


        for ( int j = 0;                                                        // кол-во абитуриентов на 2 курс РУОР
                  j < DMStat -> QCount_RUOR -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_RUORCOUNT -> Value,
                    20,
                    Find_nom_spec_str (
                        DMStat -> QCount_RUORN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_RUORCOUNT -> Value,
                    22,
                    Find_nom_spec_str (
                        DMStat -> QCount_RUORN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_RUOR -> Next ();
        }


        DMStat -> QCount_High   -> Close ();
        DMStat -> QCount_RUOR   -> Close ();
        DMStat -> QCount_Test   -> Close ();
        DMStat -> QCount_Region -> Close ();
        DMStat -> QCount_Stag   -> Close ();
        DMStat -> QCount_Gorod  -> Close ();
        DMStat -> QCount_Gimn   -> Close ();
        DMStat -> QCount_Olimp  -> Close ();
        DMStat -> QCount_Diplom -> Close ();
        DMStat -> QCount_Medal  -> Close ();
        DMStat -> QCount_PO     -> Close ();
        DMStat -> QF2_Zach      -> Close ();
        DMStat -> QF2_Sdal      -> Close ();
        DMStat -> QF2_All_Sdal  -> Close ();
        DMStat -> QSpecial      -> Close ();


        for ( int i = 0;
                  i < 2;
                  ++i
            )
            if (mas_spec_str)
                delete [] mas_spec_str[i];

        if (mas_spec_str)
            delete [] mas_spec_str;
    }

    AnsiString n_file =
        "ОТЧЕТ - Форма 3 за "                   +
            AnsiToUtf8 (cur_d.CurrentDate ())   +
        ".xls";

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );

    OVisible (ExcelApplication);
}
void __fastcall TMainForm::N32Click (TObject * Sender)                          // Отчет Подано заявлений (итоговая)
{
    ExcelApplication =
        Variant::CreateObject (
            "Excel.Application"
        );

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir                             +
            DocumentFile::REPORT::SUBMITTED
        );
    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );
    DisplayAlert (ExcelApplication);

    AnsiString n_file =
        getReportName (
            fac1,
            DocumentName::REPORT::SUBMITTED
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );
    OVisible (ExcelApplication);


    CellValue (                                                                 // факультет и дата
        DM -> TFaculty ->
            Lookup (
                "N_FAC",
                nom_fac,
                "FAC"
            ),
        1,
        2
    );
    CellValue (
        cur_d.CurrentDate (),
        4,
        1
    );

    nom_row = 6;
    int n_r;                                                                    // переменная для формирования цикла

    for ( int i = 0;                                                            // for по виду обучения
              i < 2;
              ++i
        )
    {
        DM -> QStatistic_Every_Day -> Close ();

        DM -> QStatistic_Every_Day ->
            ParamByName ("N_FAC")   -> AsInteger = nom_fac;

        DM -> QStatistic_Every_Day ->
            ParamByName ("VID_EDU") -> AsInteger = i;

        DM -> QStatistic_Every_Day -> Open ();



        DM -> QPlan_Priem_All -> Close ();

        DM -> QPlan_Priem_All ->
            ParamByName ("N_FAC")   -> AsInteger = nom_fac;

        DM -> QPlan_Priem_All ->
            ParamByName ("VID_EDU") -> AsInteger = i;

        DM -> QPlan_Priem_All -> Open ();


        col_rec = DM -> QPlan_Priem_All -> RecordCount;


        if (!i)
            CellValue (
                "Дневная форма получения образования",
                1,
                nom_row
            );
        else
            CellValue (
                "Заочная форма получения образования",
                1,
                nom_row
            );

        MergeCellCenter (
            1,
            19,
            nom_row++
        );

        n_r = nom_row;

        Cicle_Report (i);

        Itog_podano (                                                           // Всего по виду обучения
            i,
            n_r,
            0
        );

        ++nom_row;


        for ( int i =  1;                                                       // обрамление оставшихся ячеек
                  i <= 19;
                  ++i
            )
            for ( int j =  n_r;
                      j <= nom_row;
                      ++j
                )
                BorderCell (
                    i,
                    j,
                    1,
                    2
                );
    }

    Itog_podano (                                                               // Итого по факультету
        0,
        n_r,
        1
    );

    nom_row += 2;

    MergeCell (
        2,
        10,
        nom_row,
        2
    );

    CellValue (
        "Председатель факульетсткой комиссии  ",
        2,
        nom_row
    );

    AnsiString dec_f = "";

    switch (nom_fac)                                                            // декан факультета
    {
        case 1:
                dec_f = LegallyAuthorizedPerson::DEAN_FACULTY_1;                // СИиЕ
            break;
        case 2:
                dec_f = LegallyAuthorizedPerson::DEAN_FACULTY_2;                                         // МВС
            break;
        case 3:
                dec_f = LegallyAuthorizedPerson::DEAN_FACULTY_3;                                         // ОФКиТ
            break;
        case 4:
                dec_f = LegallyAuthorizedPerson::DEAN_FACULTY_4;                                         // МСиТ
            break;
    }

    CellValue (
        dec_f,
        12,
        nom_row
    );


    nom_row += 2;

    MergeCell (
        2,
        10,
        nom_row,
        2
    );

    CellValue (
        "Ответственный секретарь приемной комиссии  ",
        2,
        nom_row
    );
    CellValue (
        IOF,
        12,
        nom_row
    );

    WorkSaveAs = SaveBook (Workbook);                                           // сохранение

    ExcelApplication.Clear ();

    DM -> QPlan_Priem_All -> Close ();
    DM -> QPlan_Priem_CK  -> Close ();
}
void __fastcall TMainForm::N33Click (TObject * Sender)
{
    ExamenSpecForm = new TExamenSpecForm (this);

    ExamenSpecForm -> Height = 163;

    ExamenSpecForm -> ShowModal ();
}
void __fastcall TMainForm::N35Click (TObject * Sender)
{
    Group_FacForm = new TGroup_FacForm (this);

    Group_FacForm -> ShowModal ();
}
void __fastcall TMainForm::N36Click (TObject * Sender)
{
    Stat_Result_examForm = new TStat_Result_examForm (this);

    Stat_Result_examForm -> Height = 132;

    Stat_Result_examForm -> ShowModal ();
}
void __fastcall TMainForm::N37Click (TObject * Sender)                          // Статистики по уровню спортивной подготовки
{
    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir                         +
            DocumentFile::STATISTIC::LEVEL_OF_SPORTS
        );

    Sheet =
        SelectSheet (
            Workbook,
            "Спортивная подготовленность"
        );

    DisplayAlert (ExcelApplication);

    AnsiString n_file =
        getReportName (
            fac1,
            DocumentName::STATISTIC::LEVEL_OF_SPORTS
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );
    OVisible (ExcelApplication);


    CellValue (                                                                 // факультет
        fac1,
        1,
        5
    );

    Variant v1 = cur_d.CurrentDate ();

    if (v1 > 39664)                                                             // дата 04.08.2008
        CellValue (
            "сдавших вступительные экзамены в БГУФК в " +
                Admissions::TIME::YEAR                  +
            " году",
            1,
            3
        );
    else
        CellValue (
            "подавших документы в БГУФК в " +
                Admissions::TIME::YEAR      +
            " году",
            1,
            3
        );



    int n_r2,
        nom_r = 9,
        v;


    for ( int i = 0;                                                            // for по виду обучения
              i < 2;
              ++i
        )
    {
        int pp = 1;                                                             // номер по порядку


        DMStat -> QSport_Categ -> Close ();

        DMStat -> QSport_Categ ->
            ParamByName ("V_E")   -> Value = i;

        DMStat -> QSport_Categ ->
            ParamByName ("N_FAC") -> Value = nom_fac;

        DMStat -> QSport_Categ -> Open ();


        if ( ! i)
            CellValue (
                "Дневная форма получения образования",
                1,
                nom_r
            );
        else
            CellValue (
                "Заочная форма получения образования",
                1,
                nom_r
            );


        MergeCellCenter (
            1,
            8,
            nom_r++
        );

        n_r2 = nom_r;

        while ( ! DMStat -> QSport_Categ -> Eof)
        {
            int n_sp = DMStat -> QSport_CategN_SPECIALIZ -> Value,
                sum  = 0;                                                       // подсчета суммы по массовым разрядам

            v = DMStat -> QSport_CategCOUNT -> Value;

            CellValue (
                pp++,
                1,
                nom_r
            );
            CellValue (
                DMStat -> QSport_CategSPEC1 -> Value,
                2,
                nom_r
            );

            while (    DMStat -> QSport_CategN_SPECIALIZ -> Value == n_sp
                    && ! DMStat -> QSport_Categ -> Eof
                  )
            {
                if (    DMStat -> QSport_CategSPORT_CATEGORY -> Value
                     == "ЗМС"
                   )
                    CellValue (
                        v,
                        3,
                        nom_r
                    );
                else if (    DMStat -> QSport_CategSPORT_CATEGORY -> Value
                          == "МСМК"
                        )
                    CellValue (
                        v,
                        4,
                        nom_r
                    );
                else if (    DMStat -> QSport_CategSPORT_CATEGORY -> Value
                          == "МС"
                        )
                    CellValue (
                        v,
                        5,
                        nom_r
                    );
                else if (    DMStat -> QSport_CategSPORT_CATEGORY -> Value
                          == "КМС"
                        )
                    CellValue (
                        v,
                        6,
                        nom_r
                    );
                else if (    DMStat -> QSport_CategSPORT_CATEGORY -> Value
                          == "1 разряд"
                        )
                    CellValue (
                        v,
                        7,
                        nom_r
                    );
                else
                    sum += DMStat -> QSport_CategCOUNT -> Value;

                DMStat -> QSport_Categ -> Next ();
            }

            if (sum)                                                            // заносим сумму по другим разрядам
                CellValue (
                    sum,
                    8,
                    nom_r
                );

            ++nom_r;
        }


        for ( int i = 1;                                                        // Обрамление всех ячеек
                  i < 9;
                  ++i
            )
            for ( int j =  n_r2;
                      j <= nom_r;
                      ++j
                )
                BorderCell (
                    i,
                    j,
                    1,
                    2
                );

        CellValue (
            "ВСЕГО:",
            2,
            nom_r
        );
        CicleSum (
            n_r2,
            nom_r,
            3,
            8,
            0
        );

        ++nom_r;
    }

    BorderCell (
        1,
        nom_r,
        1,
        2
    );
    BorderCell (
        2,
        nom_r,
        1,
        2
    );
    CellValue (
        "ИТОГО по ф-ту:",
        2,
        nom_r
    );
    CicleSum (
        n_r2,
        nom_r,
        3,
        8,
        1
    );


    WorkSaveAs = SaveBook (Workbook);                                           // сохранение

    ExcelApplication.Clear ();
}
void __fastcall TMainForm::N39Click (TObject * Sender)                          // "Информация о ходе приема (госконтроль)
{
    Variant Ex = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            Ex,
            cur_dir                             +
            DocumentFile::STATISTIC::ADMISSION_PROGRESS
        );

    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );

    CellValue (
        cur_d.CurrentDate (),
        7,
        2
    );

    int strok = 6;

    for ( int i = 1;
              i < 4;
              ++i
        )
    {
        CellValue (                                                             // занесение названия факультета
            DM -> TFaculty ->
                Lookup (
                    "N_FAC",
                    i,
                    "FAC1"
                ),
            1,
            strok
        );


        DMStat -> Q_GK_Plan -> Close ();                                        // подсчет плана приема по факультету

        DMStat -> Q_GK_Plan ->
            ParamByName ("FAC") -> AsInteger = i;

        DMStat -> Q_GK_Plan -> Open ();


        CellValue (
            DMStat -> Q_GK_PlanSUM -> Value,
            2,
            strok
        );


        DMStat -> Q_GK_All -> Close ();                                         // кол-ва поданных заявлений по факультету на все виды обучения

        DMStat -> Q_GK_All ->
            ParamByName ("FAC") -> AsInteger = i;

        DMStat -> Q_GK_All -> Open ();


        CellValue (                                                             // занесение данных в ячейку Excel
            DMStat -> Q_GK_AllCOUNT -> Value,
            3,
            strok
        );


        for ( int k = 0;                                                        // цикл для подсчета конкурсов
                  k < 4;                                                        // (0 - город, 1 - село, 2 - ЦК, 3 - 2-ой курс)
                  ++k
            )
        {
            DMStat -> Q_GK_Konkurs -> Close ();

            DMStat -> Q_GK_Konkurs ->
                ParamByName ("FAC") -> AsInteger = i;

            DMStat -> Q_GK_Konkurs ->
                ParamByName ("KON") -> AsInteger = k;

            DMStat -> Q_GK_Konkurs -> Open ();


            switch (k)
            {
                case 0:
                        CellValue (                                             // город
                            DMStat -> Q_GK_KonkursCOUNT -> Value,
                            4,
                            strok
                        );
                    break;
                case 1:
                        CellValue (                                             // село
                            DMStat -> Q_GK_KonkursCOUNT -> Value,
                            5,
                            strok
                        );
                    break;
                case 2:
                        CellValue (                                             // факт по ЦК
                            DMStat -> Q_GK_KonkursCOUNT -> Value,
                            12,
                            strok
                        );
                    break;
                case 3:
                        CellValue (                                             // на 2 курс
                            DMStat -> Q_GK_KonkursCOUNT -> Value,
                            9,
                            strok
                        );
                break;
            }
        }


        DMStat -> Q_GK_Plan_CK -> Close ();                                     // План ЦК

        DMStat -> Q_GK_Plan_CK ->
            ParamByName ("FAC") -> AsInteger = i;

        DMStat -> Q_GK_Plan_CK -> Open ();


        CellValue (
            DMStat -> Q_GK_Plan_CKSUM -> Value,
            11,
            strok
        );


        int sum = 0;

        for ( int m = 2;                                                        // цикл для подсчета медалистов
                  m < 5;
                  ++m
            )
        {
            DMStat -> Q_GK_Medal -> Close ();

            DMStat -> Q_GK_Medal ->
                ParamByName ("FAC")  -> AsInteger = i;

            DMStat -> Q_GK_Medal ->
                ParamByName ("PRIV") -> AsInteger = m;

            DMStat -> Q_GK_Medal -> Open ();


            if (m == 4)
                CellValue (                                                     // диплом с отличием
                    DMStat -> Q_GK_MedalCOUNT -> Value,
                    7,
                    strok
                );
            else
                sum += DMStat -> Q_GK_MedalCOUNT -> Value;
        }

        CellValue (                                                             // медалисты с золотой и серебряной медалью
            sum,
            6,
            strok
        );

        ++strok;
    }

    AnsiString n_file =
        getReportName (
            DocumentName::STATISTIC::ADMISSION_PROGRESS
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );
    OVisible (Ex);

    Ex.Clear ();
}
void __fastcall TMainForm::N41Click (TObject * Sender)                          // Сводная ведомость Заочка Платники
{
    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N42Click (TObject * Sender)                          // СПИСОК - По направлениям
{
    int col_pred = DM -> TPredmet -> RecordCount;                               // Определение кол-ва экзамен. предметов

    DM -> QResult_Exam -> Close ();
    DM -> QResult_Exam -> Open ();


    DM -> QSpisoc_Group -> Close ();                                            // открытие Query c абитуриентами
    DM -> QSpisoc_Group -> SQL -> Clear ();
    DM -> QSpisoc_Group ->
        SQL ->
            Add (
                " SELECT"                       \
                "     fam,"                     \
                "     name,"                    \
                "     otch,"                    \
                "     n_specializ,"             \
                "     nom_group,"               \
                "     n_privilege_exam,"        \
                "     n_ck,"                    \
                "     nomer_ab,"                \
                "     gragdan,"                 \
                "     vid_edu,"                 \
                "     konkurs,"                 \
                "     n_sport_category,"        \
                "     v_k,"                     \
                "     priv,"                    \
                "     without,"                 \
                "     n_fac,"                   \
                "     middle_ball,"             \
                "     price,"                   \
                "     sum_ball,"                \
                "     term_edu"                 \
                " FROM"                         \
                "     abitura"                  \
                " WHERE"                        \
                "         n_fac  = :N_FAC"      \
                "     AND"                      \
                "         status = 0"           \
                " ORDER BY"                     \
                "     vid_edu,"                 \
                "     n_specializ,"             \
                "     fam,"                     \
                "     name,"                    \
                "     otch"
            );


    DM -> QSpisoc_Group ->
        ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DM -> QSpisoc_Group -> Open ();


    ExcelApplication =                                                          // создание объекта и открытие созданного файла
        Variant::CreateObject (
            "Excel.Application"
        );

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir                     +
            DocumentFile::LIST::GROUPS
        );

    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );

    // DisplayAlert (ExcelApplication);

    AnsiString n_file =
        getReportName (
            fac1,
            DocumentName::LIST::BY_DESTINATIONS
        );

    Variant    WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );

    // OVisible (ExcelApplication);


    AnsiString name_spec = "";

    int j          = 0,                                                         // переменная  порядковый номер
        nom_stroka = 8,                                                         // переменная номера строки
        rec        = DM -> QSpisoc_Group -> RecordCount,                        // количество человек в группе
        spec       = 0,
        vid_e      = -1;

    for ( int i =  1;                                                           // цикл по абитуриентам (с учетом номера группы и специализации)
              i <= rec;
              ++i
        )
    {
        if (    spec  != DM -> QSpisoc_GroupN_SPECIALIZ -> Value
             || vid_e != DM -> QSpisoc_GroupVID_EDU     -> Value
           )
        {
            if (j)                                                              // не первый лист
                for ( int i = 1;                                                // Автоподбор ширины столбца
                          i <= col_pred + 7;
                          ++i
                    )
                    AutoFitColumn (
                        Sheet,
                        i
                    );


            spec      = DM -> QSpisoc_GroupN_SPECIALIZ -> Value;
            name_spec = DM -> QSpisoc_GroupSPECIALIZ1  -> Value;
            vid_e     = DM -> QSpisoc_GroupVID_EDU     -> Value;


            Sheet = NewSheet1 (Workbook);


            AnsiString list =
                name_spec.SubString (
                    1,
                    23
                )                                       +
                " "                                     +
                DM -> QSpisoc_GroupVID_EDU1 -> Value;


            NameSheet1 (
                Sheet,
                list
            );
            SelectSheet (
                Workbook,
                list
            );


            MergeCellCenter (                                                   // ШАПКА (факульт, вид обучения и номер группы)
                1,
                7 + col_pred,
                2
            );
            CellValue (                                                         // Ячейка с названием факультета
                DM -> TFaculty ->
                    Lookup (
                        "N_FAC",
                        nom_fac,
                        "FAC"
                    ),
                1,
                2
            );


            MergeCellCenter (                                                   // Форматирование ячейки для занесения вида обучения
                1,
                7 + col_pred,
                4
            );
            CellValue (
                DM -> QSpisoc_GroupVID_EDU1 -> Value,
                1,
                4
            );


            MergeCellCenter (                                                   // Ячейка со специализацией
                1,
                7 + col_pred,
                5
            );
            CellValue (
                DM -> QSpisoc_GroupSPECIALIZ2 -> Value,
                1,
                5
            );

            Shapka_spisok (col_pred);                                           // Функция формирования шапки таблицы

            nom_stroka = 8;                                                     // номер строки
            j          = 1;                                                     // порядковый номер
        }


        Priv_Str (10);                                                      // Формирует строки S1, S2, S3 - преимущества и спорт. разряд (10 - полный списк абитуриентов)


        CellValue (                                                             // льготы на экзаменах (конкурс)
            S1,
            1,
            nom_stroka
        );
        BorderCell (
            1,
            nom_stroka,
            1,
            2
        );

        CellValue (                                                             // № п/п
            AnsiString (j) + ".",
            2,
            nom_stroka
        );
        BorderCell (
            2,
            nom_stroka,
            1,
            2
        );

        CellValue (                                                             // ФИО
                DM -> QSpisoc_GroupFAM  -> Value    +
            " " +
                DM -> QSpisoc_GroupNAME -> Value    +
            " " +
                DM -> QSpisoc_GroupOTCH -> Value,
            3,
            nom_stroka
        );
        BorderCell (
            3,
            nom_stroka,
            1,
            2
        );

        CellValue (                                                             // спортивный разряд
            S3,
            4,
            nom_stroka
        );
        BorderCell (
            4,
            nom_stroka,
            1,
            2
        );

        CellValue_Ball (                                                        // оценоки по всем экзаменам для одного абитуриента
            col_pred,
            nom_stroka
        );

        if (    nom_fac                             == 1
             || nom_fac                             == 2
             || nom_fac                             == 3
             || nom_fac                             == 4
             && DM -> QSpisoc_GroupKONKURS -> Value == 3
           )
        {
            Variant Ce1 =
                SelectCell (
                    5 + col_pred,
                    nom_stroka
                );
                SheetFormat (
                    Ce1,
                    "0,0"                                                       // 0.0 в самом Excel пишет такой формат
                );

            Ce1 =
                SelectCell (
                    6 + col_pred,
                    nom_stroka
                );
            SheetFormat (
                Ce1,
                "0,0"
            );
        }


        CellValue (                                                             // занесение среднего балла аттестата
            DM -> QSpisoc_GroupMIDDLE_BALL -> Value,
            5 + col_pred,
            nom_stroka
        );
        BorderCell (
            5 + col_pred,
            nom_stroka,
            1,
            2
        );


        CellValue (                                                             // обрамление ячейки с суммой баллов
            DM -> QSpisoc_GroupSUM_BALL -> Value,
            6 + col_pred,
            nom_stroka
        );
        BorderCell (
            6 + col_pred,
            nom_stroka,
            1,
            2
        );


        CellValue (                                                             // занесение Примечания (преимущества при зачислении)
            S2,
            7 + col_pred,
            nom_stroka
        );
        BorderCell (
            7 + col_pred,
            nom_stroka,
            1,
            2
        );

        ++nom_stroka;
        ++j;

        DM -> QSpisoc_Group -> Next ();
    }


    DM -> QAb_Pr_Enter -> Close ();


    for ( int i =  1;                                                           // Автоподбор ширины столбца
              i <= col_pred + 7;
              ++i
        )
        AutoFitColumn (
            Sheet,
            i
        );


    DisplayAlert (ExcelApplication);                                            // сохранение
    OVisible (ExcelApplication);

    WorkSaveAs = SaveBook (Workbook);

    if (nom_pr)
        delete [] nom_pr;

    DM -> QResult_Exam -> Close ();
}
void __fastcall TMainForm::N43Click (TObject * Sender)                          // Статистика  ->  Кол-во поданных заявлений по баллам
{
    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir             +
            DocumentFile::STATISTIC::SCORES
        );

    OVisible (ExcelApplication);                                                // удалить т.к. показывает форму при заполнении таблицы,нужно только для отладки

    DisplayAlert (ExcelApplication);                                            // убрать запросы Excela на подтверждения действия


    AnsiString hour_cur = AnsiToUtf8 (cur_d.CurrentTime ()).SetLength (2);

    if (    hour_cur.IsDelimiter ("\\:",2))
        hour_cur = hour_cur.SetLength (1);

    AnsiString n_file =
        getReportName (
            fac1,
            DocumentName::STATISTIC::SCORES,
            hour_cur
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );

    AnsiString SheetName;

    int d_st = 7,                                                               // столбец для даты
        n_r;                                                                    // переменная для начала обрамления.

    for ( int edu = 0;                                                          // Цикл по формам обучения
              edu < 2;
              ++edu
        )
    {
        for ( int konk_place = 0;                                               // Цикл по срокам обучения
                  konk_place < 3;
                  ++konk_place
            )
        {
            for ( int price = 0;                                                // Цикл по финансирлованию
                      price < 2;
                      ++price
                )
            {
                SheetName =
                    getPartOfSheetNameForEducationType (edu)        +
                    getPartOfSheetNameForStudyPeriod   (konk_place) +
                    getPartOfSheetNameForPayment       (price);

                nom_row = 15;                                                   // первая строка данных

                Sheet =                                                         // Выбор листа Excel
                    SelectSheet (
                        Workbook,
                        SheetName
                    );
                CellValue (
                    DM -> TFaculty ->
                        Lookup (
                            "N_FAC",
                            nom_fac,
                            "FAC"
                        ),
                    1,                                                          // 1 колонка - для отладки
                    14                                                          // 14 строка - для отладки
                );

                CellValue (                                                     // Вывод даты (d_st - можно удалить?)
                    cur_d.CurrentDate (),
                    7,                                                          // 7 кол
                    5                                                           // 5 строка
                );

                CellValue (                                                     // Вывод времени
                    cur_d.CurrentTime (),
                    11,                                                         // 11 кол
                    5                                                           // 5 строка
                );


                DM -> QPlan_Priem_Konk_All_Param -> Close ();                   // Для AllCount - общее число из плана

                DM -> QPlan_Priem_Konk_All_Param ->                             // номер факультета
                    ParamByName ("N_FAC")   -> AsInteger = nom_fac;

                DM -> QPlan_Priem_Konk_All_Param ->                             // форма обучения
                    ParamByName ("VID_EDU") -> AsInteger = edu;

                DM -> QPlan_Priem_Konk_All_Param ->                             // курс обучения
                    ParamByName ("TEXT")    -> AsInteger = konk_place;

                DM -> QPlan_Priem_Konk_All_Param ->                             // финансирование
                    ParamByName ("PRICE")   -> AsInteger = price;

                DM -> QPlan_Priem_Konk_All_Param -> Open ();


                if (    konk_place ==                                           // количество записей в плане приёма
                            static_cast <int> (
                                StudyPeriodCode::SHORT_SECOND_COURSE
                            )
                     && konk_place ==
                            static_cast <int> (
                                StudyPeriodCode::SHORT_THIRD_COURSE
                            )
                   )
                    col_rec = 1;                                                // для сокращёнки только одно направление специализации
                else
                    col_rec =                                                   // в остальных случаях
                        DM -> QPlan_Priem_Konk_All_Param -> RecordCount;

                n_r = nom_row;                                                  // начало обрамления

                Cicle_ball (
                    edu,
                    konk_place,
                    price
                );
            }
        }
    }


    if (nom_fac == 2)                                                           // Удаление лишних листов Excel (Для МВС)
    {
        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
                "Д.С.Б."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа

        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
                "Д.С.О."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа

        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
                "З.С.Б."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа

        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
                "З.С.О."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа
    }


    // if (nom_fac == 3)                                                           // Удаление лишних листов Excel (Для ОФКиТ)
    // {
    //     Sheet =                                                                 // Выбор листа Excel
    //         SelectSheet (
    //             Workbook,
    //             "Д.С.Б."
    //         );
    //     DeleteSheet (Sheet);                                                    // Удаление выбранного листа

    //     Sheet =                                                                 // Выбор листа Excel
    //         SelectSheet (
    //             Workbook,
    //             "Д.С.О."
    //         );
    //     DeleteSheet (Sheet);                                                    // Удаление выбранного листа

    //     Sheet =                                                                 // Выбор листа Excel
    //         SelectSheet (
    //             Workbook,
    //             "З.С.Б."
    //         );
    //     DeleteSheet (Sheet);                                                    // Удаление выбранного листа

    //     Sheet =                                                                 // Выбор листа Excel
    //         SelectSheet (
    //             Workbook,
    //             "З.С.О."
    //         );
    //     DeleteSheet (Sheet);                                                    // Удаление выбранного листа
    // }


    if (nom_fac == 4)                                                           // Удаление лишних листов Excel (Для ИТ)
    {
        // Sheet =                                                                 // Выбор листа Excel
        //     SelectSheet (
        //         Workbook,
        //         "Д.С.Б."
        //     );
        // DeleteSheet (Sheet);                                                    // Удаление выбранного листа

        // Sheet =                                                                 // Выбор листа Excel
        //     SelectSheet (
        //         Workbook,
        //         "Д.С.О."
        //     );
        // DeleteSheet (Sheet);                                                    // Удаление выбранного листа

        // Sheet =                                                                 // Выбор листа Excel
        //     SelectSheet (
        //         Workbook,
        //         "З.П.Б."
        //     );
        // DeleteSheet (Sheet);                                                    // Удаление выбранного листа

        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
                "З.С.Б."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа
    }


    WorkSaveAs = SaveBook (Workbook);                                           // сохранение

    OVisible (ExcelApplication);                                                // Показывает объект Excel

    ExcelApplication.Clear ();

    DM -> QPlan_Priem_Konk_All_Param -> Close ();
}
void __fastcall TMainForm::N44Click (TObject * Sender)                          // Отчет Подано заявлений (итоговая)  по направлениям
{
    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir             +
            DocumentFile::REPORT::SUBMITTED
        );
    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );

    DisplayAlert (ExcelApplication);

    AnsiString n_file =
        getReportName (
            DocumentName::REPORT::SUBMITTED
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );
    OVisible (ExcelApplication);


    CellValue (                                                                 // факультет и дата
        "Белорусский государственный университет "  \
        "физической культуры",
        1,
        2
    );

    CellValue (
        cur_d.CurrentDate (),
        4,
        1
    );

    int n_r;
        nom_row = 6;

    for ( int i = 0;                                                            // for по виду обучения
              i < 2;
              ++i
        )
    {
        DM -> QPlan_Priem_All_Special -> Close ();

        DM -> QPlan_Priem_All_Special ->
            ParamByName ("VID_EDU") -> AsInteger = i;

        DM -> QPlan_Priem_All_Special -> Open ();


        col_rec = DM -> QPlan_Priem_All_Special -> RecordCount;


        if ( ! i)
            CellValue (
                "Дневная форма получения образования",
                1,
                nom_row
            );
        else
            CellValue (
                "Заочная форма получения образования",
                1,
                nom_row
            );


        MergeCellCenter (
            1,
            19,
            nom_row++
        );

        n_r = nom_row;

        Cicle_Report_special (i);

        Itog_podano (                                                           // Всего по виду обучения
            i,
            n_r,
            0
        );

        ++nom_row;


        for ( int i =  1;                                                       // обрамление оставшихся ячеек
                  i <= 19;
                  ++i
            )
        {
            for ( int j = n_r;
                      j <= nom_row;
                      ++j
                )
                BorderCell (
                    i,
                    j,
                    1,
                    2
                );
        }

    }


    Itog_podano (                                                               // Итого по факультету
        0,
        n_r,
        1
    );


    nom_row += 2;

    MergeCell (
        2,
        10,
        nom_row
    );

    CellValue (
        "Ответственный секретарь приемной комиссии ",
        2,
        nom_row
    );
    CellValue (
        IOF,
        12,
        nom_row
    );


    WorkSaveAs = SaveBook (Workbook);                                           // сохранение

    ExcelApplication.Clear ();

    DM -> QPlan_Priem_All_Special -> Close ();
}
void __fastcall TMainForm::N45Click (TObject * Sender)                          // 'Форма 1' Подали на Дневное
{
    Forma_Giac (
        static_cast <int> (FormTypeCode::REGISTRATION),
        static_cast <int> (EducationTypeCode::INTRAMURAL)
    );
}
void __fastcall TMainForm::N46Click (TObject * Sender)                          // 'Форма 2' Зачислены на Дневное
{
    Forma_Giac (
        static_cast <int> (FormTypeCode::ENROLLMENT),
        static_cast <int> (EducationTypeCode::INTRAMURAL)
    );
}
void __fastcall TMainForm::N47Click (TObject * Sender)                          // 'Форма 1' Подали на Заочное
{
    Forma_Giac (
        static_cast <int> (FormTypeCode::REGISTRATION),
        static_cast <int> (EducationTypeCode::EXTRAMURAL)
    );
}
void __fastcall TMainForm::N48Click (TObject * Sender)                          // 'Форма 2' Зачислены на Заочное
{
    Forma_Giac (
        static_cast <int> (FormTypeCode::ENROLLMENT),
        static_cast <int> (EducationTypeCode::EXTRAMURAL)
    );
}
//void __fastcall TMainForm::N50Click (TObject * Sender)                        // Instead it use N311Click
//{
//    Protokol4_J (2);
//}
void __fastcall TMainForm::N52Click (TObject * Sender)
{
    n_menu  = 52;

    PassDlg = new TPassDlg (this);

    PassDlg -> ShowModal ();
}
void __fastcall TMainForm::N53Click (TObject * Sender)
{
    n_menu = 53;

    PassDlg = new TPassDlg (this);

    PassDlg -> ShowModal ();
}
void __fastcall TMainForm::N54Click (TObject * Sender)
{
    ExamenSpecForm = new TExamenSpecForm (this);

    ExamenSpecForm -> Caption =
        "Формирование протокола с КУ по ФКиС";

    ExamenSpecForm -> DBLookupComboBox1 -> Visible = true;
    ExamenSpecForm -> DBLookupComboBox1 -> KeyValue = 2;
    ExamenSpecForm -> DBLookupComboBox1 -> Enabled = false;

    ExamenSpecForm -> Height = 163;

    ExamenSpecForm -> ShowModal ();
}
void __fastcall TMainForm::N55Click (TObject * Sender)                          // Статистика  ->  Конкурс
{
    //  NOTE: Use AbiturRIO instead !!!

    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir                             +
            DocumentFile::STATISTIC::CONTEST
        );

    OVisible (ExcelApplication);                                                // удалить т.к. показывает форму при заполнении таблицы, нужно только для отладки

    // DisplayAlert (ExcelApplication);                                            // убрать запросы Excela на подтверждения действия


    AnsiString
        hour_cur =
            AnsiToUtf8 (
                cur_d.CurrentTime ()
            ).SetLength (
                2
            );


    if (    hour_cur.IsDelimiter (
                "\\:",
                2
            )
       )
        hour_cur = hour_cur.SetLength (1);


    AnsiString n_file =
        getReportName (
            fac1,
            DocumentName::STATISTIC::CONTEST
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );


    AnsiString
        SheetName;

    int
        d_st = 7,                                                               // столбец для даты
        n_r;                                                                    // переменная для начала обрамления.

    for ( int edu = 0;
              edu < 2;
              ++edu
        )
    {
        for ( int konk_place = 0;
                  konk_place < 3;
                  ++konk_place
            )
        {
            for ( int price = 0;
                      price < 2;
                      ++price
                )
            {
                SheetName =
                    getPartOfSheetNameForEducationType (edu)        +
                    getPartOfSheetNameForStudyPeriod   (konk_place) +
                    getPartOfSheetNameForPayment       (price);

                nom_row = 15;                                                   // первая строка данных

                Sheet =                                                         // Выбор листа Excel
                    SelectSheet (
                        Workbook,
                        SheetName
                    );
                CellValue (
                    DM -> TFaculty ->
                        Lookup (
                            "N_FAC",
                            nom_fac,
                            "FAC"
                        ),
                    1,                                                          // 1 колонка - для отладки
                    14                                                          // 14 строка - для отладки
                );

                CellValue (                                                     // Вывод даты
                    cur_d.CurrentDate (),
                    6,
                    4
                );

                // CellValue (                                                     // Вывод времени
                //     cur_d.CurrentTime (),
                //     11,                                                         // 11 кол
                //     5                                                           // 5 строка
                // );


                DM -> QPlan_Priem_Konk_All_Param -> Close ();                   // Для AllCount - общее число из плана
                DM -> QPlan_Priem_Konk_All_Param ->                             // номер факультета
                    ParamByName ("N_FAC")   -> AsInteger = nom_fac;
                DM -> QPlan_Priem_Konk_All_Param ->                             // форма обучения
                    ParamByName ("VID_EDU") -> AsInteger = edu;
                DM -> QPlan_Priem_Konk_All_Param ->                             // курс обучения
                    ParamByName ("TEXT")    -> AsInteger = konk_place;
                DM -> QPlan_Priem_Konk_All_Param ->                             // финансирование
                    ParamByName ("PRICE")   -> AsInteger = price;
                DM -> QPlan_Priem_Konk_All_Param -> Open ();


                if (    konk_place == 1                                         // количество записей в плане приёма
                     && (    nom_fac == 1
                          || nom_fac == 2
                        )
                   )
                    col_rec = 1;                                                // для сокращёнки СИиЕ и МВС только одно направление специализации
                else                                                            // в остальных случаях
                    col_rec =
                        DM -> QPlan_Priem_Konk_All_Param -> RecordCount;


                n_r = nom_row;                                                  // переменная для начала обрамления

                Cicle_ball_konk (
                    edu,
                    konk_place,
                    price
                );
            }
        }
    }


    if (nom_fac == 2)                                                           // УДАЛЕНИЕ ЛИШНИХ ЛИСТОВ EXCEL 'Для МВС'
    {
        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
                "Д.С.Б."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа

        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
               "Д.С.О."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа

        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
              "З.С.Б."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа

        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
              "З.С.О."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа
    }


    // if (nom_fac == 3)                                                           // УДАЛЕНИЕ ЛИШНИХ ЛИСТОВ EXCEL 'Для ОФКиТ'
    // {
    //     Sheet =                                                                 // Выбор листа Excel
    //         SelectSheet (
    //             Workbook,
    //             "Д.С.Б."
    //         );
    //     DeleteSheet (Sheet);                                                    // Удаление выбранного листа

    //     Sheet =                                                                 // Выбор листа Excel
    //         SelectSheet (
    //             Workbook,
    //            "Д.С.О."
    //         );
    //     DeleteSheet (Sheet);                                                    // Удаление выбранного листа

    //     Sheet =                                                                 // Выбор листа Excel
    //         SelectSheet (
    //             Workbook,
    //           "З.С.Б."
    //         );
    //     DeleteSheet (Sheet);                                                    // Удаление выбранного листа

    //     Sheet =                                                                 // Выбор листа Excel
    //         SelectSheet (
    //             Workbook,
    //           "З.С.О."
    //         );
    //     DeleteSheet (Sheet);                                                    // Удаление выбранного листа
    // }


    if (nom_fac == 4)                                                           // УДАЛЕНИЕ ЛИШНИХ ЛИСТОВ EXCEL 'Для ИТ'
    {
        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
                "Д.С.Б."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа

        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
               "Д.С.О."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа

        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
              "З.П.Б."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа

        Sheet =                                                                 // Выбор листа Excel
            SelectSheet (
                Workbook,
              "З.С.Б."
            );
        DeleteSheet (Sheet);                                                    // Удаление выбранного листа
    }


    WorkSaveAs = SaveBook (Workbook);                                           // сохранение

    OVisible (ExcelApplication);                                                // Показывает объект Excel

    ExcelApplication.Clear ();

    DM -> QPlan_Priem_Konk_All_Param -> Close ();
}
void __fastcall TMainForm::N58Click (TObject * Sender)                          // Печать конвертов бюджет,дневняя форма
{
    printEnvelope (
        PaymentCode::BUDGET,
        EducationTypeCode::INTRAMURAL,
        EnvelopeMessage::BUDGET::INTRAMURAL
    );
}
void __fastcall TMainForm::N59Click (TObject * Sender)                          // Печать конвертов бюджет,заочняая форма
{
    printEnvelope (
        PaymentCode::BUDGET,
        EducationTypeCode::EXTRAMURAL,
        EnvelopeMessage::BUDGET::EXTRAMURAL
    );
}
void __fastcall TMainForm::N62Click (TObject * Sender)                          // Печать конвертов за оплату, дневная форма
{
    printEnvelope (
        PaymentCode::BUYERS,
        EducationTypeCode::INTRAMURAL,
        EnvelopeMessage::BUYERS::INTRAMURAL
    );
}
void __fastcall TMainForm::N63Click (TObject * Sender)                          // Печать конвертов за оплату,заочнаая форма
{
    printEnvelope (
        PaymentCode::BUYERS,
        EducationTypeCode::EXTRAMURAL,
        EnvelopeMessage::BUYERS::EXTRAMURAL
    );
}
void __fastcall TMainForm::N64Click (TObject * Sender)                          // Журнал регистрации документов абитуриентов
{
    AbiturLogDlg = new TAbiturLogDlg (this);

    AbiturLogDlg -> ShowModal ();

    if (AbiturLogDlg)
        delete AbiturLogDlg;


    if (AbiturLogDate.Val > 0)
    {
        ExcelApplication =
            Variant::CreateObject (
                "Excel.Application"
            );

        Variant Workbook =
            OpenBook (
                ExcelApplication,
                cur_dir                         +
                DocumentFile::REGISTRY::BOOK
            );

        Sheet =
            SelectSheet (
                Workbook,
                "ДПБ"
            );

        DisplayAlert (ExcelApplication);

        // OVisible (ExcelApplication);

        String n_file =
            getReportName (
                DocumentName::REGISTRY::BOOK,
                true
            );

        Variant WorkSaveAs =
            SaveBookAs (
                Workbook,
                out_dir +
                n_file
            );

        int    leng_str,
               start_row       = 2;

        String FIO,
               NameSertificat,
               SheetName       = "   ";


        for ( int VidEdu = 0;
                  VidEdu < 2;
                  ++VidEdu
            )
        {
            if (VidEdu)
                SheetName.Insert (
                    "З",
                    1
                );
            else
                SheetName.Insert (
                    "Д",
                    1
                );


            SheetName.Delete (
                4,
                1
            );


            for ( int TermEdu = 0;
                      TermEdu < 2;
                      ++TermEdu
                )
            {
                 if (TermEdu)
                    SheetName =
                        SheetName.Insert (
                            "С",
                            2
                        );
                else
                    SheetName =
                        SheetName.Insert (
                            "П",
                            2
                        );

                SheetName.Delete (
                    4,
                    1
                );

                for ( int Price = 0;
                          Price < 2;
                          ++Price
                    )
                {
                    if (Price)
                        SheetName =
                            SheetName.Insert (
                                "О",
                                3
                            );
                    else
                        SheetName =
                            SheetName.Insert (
                                "Б",
                                3
                            );

                    SheetName.Delete (
                        4,
                        1
                    );

                    Sheet =
                        SelectSheet (
                            Workbook,
                            SheetName
                        );
                    String date_t =
                        AbiturLogDate.FormatString (
                            "dd/mm/yyyy"
                        );
                    TDate d1 =
                        StrToDate (
                            date_t
                        );
                    TDate d2 = d1 + 1;


                    DM -> SelectLogAbiturQr -> Close ();

                    DM -> SelectLogAbiturQr ->
                        ParamByName ("n_fac")    -> AsSmallInt = nom_fac;

                    DM -> SelectLogAbiturQr ->
                        ParamByName ("date_in1") -> AsDateTime = d1;

                    DM -> SelectLogAbiturQr ->
                        ParamByName ("date_in2") -> AsDateTime = d2;

                    DM -> SelectLogAbiturQr ->
                        ParamByName ("vid_edu")  -> AsSmallInt = VidEdu;

                    DM -> SelectLogAbiturQr ->
                        ParamByName ("term_edu") -> AsSmallInt = TermEdu;

                    DM -> SelectLogAbiturQr ->
                        ParamByName ("price")    -> AsSmallInt = Price;

                    DM -> SelectLogAbiturQr -> Open ();


                    int i = start_row;

                    while ( ! DM -> SelectLogAbiturQr -> Eof)                   // заполнение журнала
                    {
                        CellValue (                                             // 1. Номер дела
                            "'"                     +
                            DM ->
                                NumDelaString (
                                    VidEdu,
                                    TermEdu,
                                    Price,
                                    DM -> SelectLogAbiturQrNOM_DELA -> Value
                                ),
                            1,
                            i
                        );


                        if (    TermEdu == 1
                             && VidEdu  == 1
                             && Price   == 0
                           )
                        {
                            CellValue (
                                "'"                 +
                                DM ->
                                    NumDelaString (
                                        VidEdu,
                                        TermEdu,
                                        Price,
                                        DM -> SelectLogAbiturQrNOM_DELA -> Value
                                    ),
                                1,
                                i
                            );
                        }


                        BorderCell (                                            // обрамление ячейки
                            1,                                                  // столбец
                            i,                                                  // строка
                            1,                                                  // обычная линия
                            2                                                   // толщина
                        );


                        CellValue (                                             // 2. Дата приема документов
                            SQLTimeStampToDateTime (
                                DM -> SelectLogAbiturQrDATE_IN -> Value
                            ),
                            2,                                                  // столбец
                            i                                                   // строка
                        );
                        BorderCell (                                            // обрамление ячейки
                            2,                                                  // столбец
                            i,                                                  // строка
                            1,                                                  // обычная линия
                            2                                                   // толщина
                        );


                        FIO =                                                   // 3. ФИО
                            DM -> SelectLogAbiturQrFAM  -> Value + " " +
                            DM -> SelectLogAbiturQrNAME -> Value + " " +
                            DM -> SelectLogAbiturQrOTCH -> Value;


                        DM -> SpecQr -> Close ();                               // 3.1. Направление специальности

                        DM -> SpecQr ->
                            ParamByName ("n_specializ") -> AsSmallInt =
                                    DM -> SelectLogAbiturQrN_SPECIALIZ -> Value;

                        DM -> SpecQr -> Open ();


                        FIO +=
                             "\n ("                                          +
                                DM -> SpecQrSPECIAL -> AsString.LowerCase () +
                            ")";


                        CellValue (
                            FIO,
                            3,                                                  // столбец
                            i                                                  // строка
                        );
                        BorderCell (                                            // обрамление ячейки
                            3,                                                  // столбец
                            i,                                                  // строка
                            1,                                                  // обычная линия
                            2                                                   // толщина
                        );


                        DM -> ContrySelQr -> Close ();                          // 4. Гражданство

                        DM -> ContrySelQr ->
                            ParamByName ("id") -> AsSmallInt =
                                    DM -> SelectLogAbiturQrCITIZENSHIP -> Value;

                        DM -> ContrySelQr -> Open ();


                        CellValue (
                            DM -> ContrySelQrSHORT_NAME -> Value,
                            4,                                                  // столбец
                            i                                                  // строка
                        );
                        BorderCell (                                            // обрамление ячейки
                            4,                                                  // столбец
                            i,                                                  // строка
                            1,                                                  // обычная линия
                            2                                                   // толщина
                        );


                        DM -> ContrySelQr -> Close ();

                        NameSertificat = "";                                    // 5. Перечень принятых сертификатов ЦТ

                        DM -> SertSelLogQr -> Close ();

                        DM -> SertSelLogQr ->
                            ParamByName ("nomer_ab") -> AsInteger =
                                    // DM -> SelectLogAbiturQrID_LOG -> Value;
                                    DM -> SelectLogAbiturQrNOMER_AB -> Value;

                        DM -> SertSelLogQr -> Open ();

                        while ( ! DM -> SertSelLogQr -> Eof)
                        {
                            if (DM -> SertSelLogQrRUS_BEL -> Value < 2)
                                if (DM -> SertSelLogQrRUS_BEL -> Value == 0)
                                    NameSertificat += "Русский язык ";
                                else
                                    NameSertificat += "Белорусский язык ";
                            else
                                NameSertificat +=
                                    DM -> SertSelLogQrTEXT_PREDMET -> AsString  +
                                    " ";

                            NameSertificat +=
                                DM -> SertSelLogQrSERIA_S -> AsString;

                            NameSertificat +=
                                " №"                                    +
                                    DM -> SertSelLogQrNOMER_S -> Value  +
                                ","                                     +
                                    DM -> SertSelLogQrBALLS   -> Value  +
                                "балл";

                            DM -> SertSelLogQr -> Next ();

                            if ( ! DM -> SertSelLogQr -> Eof)
                                NameSertificat += "\n";
                        }

                        DM -> SertSelLogQr -> Close ();

                        CellValue (
                            NameSertificat,
                            5,                                                  // столбец
                            i                                                   // строка
                        );
                        BorderCell (                                            // обрамление ячейки
                            5,                                                  // столбец
                            i,                                                  // строка
                            1,                                                  // обычная линия
                            2                                                   // толщина
                        );



                        switch (DM -> SelectLogAbiturQrKONKURS -> Value)        // 6. Отметка о льготах
                        {
                            case 1:                                             // БВИ
                                    NameSertificat = "БВИ";
                                break;
                            case 2:                                             // ВК
                                    NameSertificat = "ВК";
                                break;
                            default:
                                    NameSertificat = "";
                        }


                        switch (DM -> SelectLogAbiturQrTERM_EDU -> Value)
                        {
                            case 3:                                             // ВО 1 курс
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "ВО 1к.";
                                break;
                            case 4:                                             // ВО 2 курс
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "ВО 2к.";
                                break;
                            case 5:                                             // ВО 3 курс
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "ВО 3к.";
                                break;
                        }


                        switch (DM -> SelectLogAbiturQrCATEGORY -> Value)
                        {
                            case 1:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "3разр.";
                                break;
                            case 2:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "2разр.";
                                break;
                            case 3:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "1разр.";
                                break;
                            case 4:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "КМС";
                                break;
                            case 5:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "МС";
                                break;
                            case 6:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "МСМК";
                                break;
                            case 7:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "ЗМС";
                                break;
                            case 8:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "3кю";
                                break;
                            case 9:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "2кю";
                                break;
                            case 10:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "1кю";
                                break;
                            case 11:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "1юн.р";
                                break;
                        }


                        DM -> SelPrivLogQr -> Close ();

                        DM -> SelPrivLogQr ->
                            ParamByName ("id_log") -> AsInteger =
                                    DM -> SelectLogAbiturQrID_LOG -> Value;

                        DM -> SelPrivLogQr -> Open ();


                        while ( ! DM -> SelPrivLogQr -> Eof)
                        {
                            switch (DM -> SelPrivLogQrN_PRIV -> Value)
                            {
                                case 0:                                         // БВИ
                                        DM -> WithOutTestLogQr -> Close ();

                                        DM -> WithOutTestLogQr ->
                                            ParamByName ("sel_priv") -> AsSmallInt =
                                                    DM -> SelPrivLogQrSEL_PRIV -> Value;

                                        DM -> WithOutTestLogQr ->
                                            ParamByName ("dat_priv") -> AsSmallInt =
                                                    DM -> SelPrivLogQrDAT_PRIV -> Value;

                                        DM -> WithOutTestLogQr -> Open ();


                                        while ( ! DM -> WithOutTestLogQr -> Eof)
                                        {
                                            if (NameSertificat != "")
                                                NameSertificat += ",";

                                            NameSertificat +=
                                                DM -> WithOutTestLogQrSHORT_NAME -> Value;

                                            if (    DM -> WithOutTestLogQrSHORT_NAME_1 -> Value
                                                 != "да"
                                               )
                                                NameSertificat +=
                                                    " - "                               +
                                                    DM ->
                                                        WithOutTestLogQrSHORT_NAME_1 ->
                                                            Value;

                                            DM -> WithOutTestLogQr -> Next ();
                                        }

                                        DM -> WithOutTestLogQr -> Close ();
                                    break;
                                case 1:                                         // ВК
                                        // DM -> OutTestQr

                                        DM -> OutTestQr -> Close ();

                                        DM -> OutTestQr ->
                                            ParamByName ("sel_priv") -> AsSmallInt =
                                                    DM -> SelPrivLogQrSEL_PRIV -> Value;

                                        DM -> OutTestQr ->
                                            ParamByName ("dat_priv") -> AsSmallInt =
                                                    DM -> SelPrivLogQrDAT_PRIV -> Value;

                                        DM -> OutTestQr -> Open ();


                                        while ( ! DM -> OutTestQr -> Eof)
                                        {
                                            if (NameSertificat != "")
                                                NameSertificat += ",";

                                            NameSertificat +=
                                                DM -> OutTestQrSHORT_NAME -> Value;

                                            if (    DM -> OutTestQrSHORT_NAME_1 -> Value
                                                 != "да"
                                               )
                                                NameSertificat +=
                                                    " - " +
                                                    DM -> OutTestQrSHORT_NAME_1 -> Value;

                                            DM -> OutTestQr -> Next ();
                                        }

                                        DM -> OutTestQr -> Close ();
                                    break;
                                case 2:                                         // Другие
                                        // OtherPrivQr

                                        DM -> OtherPrivQr -> Close ();

                                        DM -> OtherPrivQr ->
                                            ParamByName ("sel_priv") -> AsSmallInt =
                                                    DM -> SelPrivLogQrSEL_PRIV -> Value;

                                        DM -> OtherPrivQr -> Open ();


                                        while ( ! DM -> OtherPrivQr -> Eof)
                                        {
                                            if (NameSertificat != "")
                                                NameSertificat += ",";

                                            NameSertificat +=
                                                DM -> OtherPrivQrSHORT_NAME -> Value;

                                            DM -> OtherPrivQr -> Next ();
                                        }

                                        DM -> OtherPrivQr -> Close ();
                                    break;
                            }

                            DM -> SelPrivLogQr -> Next ();
                        }

                        DM -> SelPrivLogQr -> Close ();

                        CellValue (
                            NameSertificat,
                            6,                                                  // столбец
                            i                                                   // строка
                        );
                        BorderCell (                                            // обрамление ячейки
                            6,                                                  // столбец
                            i,                                                  // строка
                            1,                                                  // обычная линия
                            2                                                   // толщина
                        );


                        CellValue (                                             // 7. Адрес места жительства
                            DM ->
                                SelectLogAbiturQrADDRESS_BEFORE ->
                                    Value,
                            7,                                                  // столбец
                            i                                                   // строка
                        );
                        BorderCell (                                            // обрамление ячейки
                            7,                                                  // столбец
                            i,                                                  // строка
                            1,                                                  // обычная линия
                            2                                                   // толщина
                        );


                        if (DM -> SelectLogAbiturQrN_CK -> Value > -1)          // 8. Целевой конкурс
                        {
                            DM -> RegionQr -> Close ();

                            DM -> RegionQr ->
                                ParamByName ("n_centre") -> AsSmallInt =
                                        DM -> SelectLogAbiturQrN_CK -> Value;

                            DM -> RegionQr -> Open ();


                            CellValue (
                                DM -> RegionQrCENTRE -> Value,
                                8,
                                i
                            );
                        }

                        BorderCell (                                            // обрамление ячейки
                            8,                                                  // столбец
                            i,                                                  // строка
                            1,                                                  // обычная линия
                            2                                                   // толщина
                        );

                        DM -> RegionQr -> Close ();

                        BorderCell (                                            // 9. Отметка о зачислении!!!
                            9,                                                  // столбец
                            i,                                                  // строка
                            1,                                                  // обычная линия
                            2                                                   // толщина
                        );
                        DM -> RegionQr -> Close ();


                        if (DM -> SelectLogAbiturQrDATE_OUT -> IsNull)          // 10. Отметка о возврате документов (vd = "01.01.2015";)
                            CellValue (
                                "",
                                10,
                                i
                            );
                        else
                            CellValue (
                                SQLTimeStampToDateTime (
                                    DM -> SelectLogAbiturQrDATE_OUT -> Value
                                ),
                                10,
                                i
                            );


                        BorderCell (                                            // обрамление ячейки
                            10,                                                 // столбец
                            i,                                                  // строка
                            1,                                                  // обычная линия
                            2                                                   // толщина
                        );

                        DM -> SelectLogAbiturQr -> Next ();                     // Переход к новой записи

                        ++i;
                    }

                    DM -> SelectLogAbiturQr -> Close ();

                    Variant CC1 =                                               // Форматируем строки листа по центру
                        SelectCell (
                            1,
                            start_row
                        );
                    Variant CC2 =
                        SelectCell (
                            10,
                            i - 1
                        );
                    Variant RCC =
                        Range (
                            Sheet,
                            CC1,
                            CC2
                        );
                    wrapWord (RCC);                                             // пернос по словам
                    HorizontalAlign (                                           // по центру
                        RCC,
                        3
                    );
                    VerticalAlign (                                             // по центру
                        RCC,
                        2
                    );
                    CellFont (
                        "Times New Roman",                                      // Name
                        14,                                                     // Size
                        false,                                                  // Bold
                        false,                                                  // Italic
                        1,                                                      // Underline
                        RCC                                                     // Range
                    );


                    for ( int j = 1;
                              j < i;
                              ++j
                        )
                        AutoFitRow (                                            // SET ROW HEIGHT AND WIDTH
                            Sheet,                                              // sheet
                            i                                                   // nom_row
                        );
                }
            }
        }

        OVisible (ExcelApplication);

        WorkSaveAs = SaveBook (Workbook);

        ExcelApplication.Clear ();
    }
}
void __fastcall TMainForm::N68Click (TObject * Sender)                          // Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Полный срок, Дневное, Бюджет"
{
    N23Click (this);

    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N69Click (TObject * Sender)                          // Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Полный срок, Дневное, Платники"
{
    N23Click (this);

    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N70Click (TObject * Sender)                          // Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Полный срок, Заочка,  Бюджет"
{
    N23Click (this);

    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N71Click (TObject * Sender)                          // Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Полный срок, Заочка,  Платники"
{
    N23Click (this);

    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N75Click (TObject * Sender)                          // Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Сокращенка,  Дневное, Бюджет"
{
    N23Click (this);

    Create_Svod_ved_short (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N76Click (TObject * Sender)                          // Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Сокращенка,  Дневное, Платники"
{
    N23Click (this);

    Create_Svod_ved_short (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N77Click (TObject * Sender)                          // Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Сокращенка,  Заочка,  Бюджет"
{
    N23Click (this);

    Create_Svod_ved_short (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N78Click (TObject * Sender)                          // Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Сокращенка,  Заочка,  Платники"
{
    N23Click (this);

    Create_Svod_ved_short (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N81Click (TObject * Sender)                          // Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. 2-е высшее,  Дневное, Бюджет"
{
    N23Click (this);

    Create_Svod_ved_2VO2K (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N82Click (TObject * Sender)                          // Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. 2-е высшее,  Заочка,  Бюджет"
{
    N23Click (this);

    Create_Svod_ved_2VO2K (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N83Click (TObject * Sender)                          // Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. 2-е высшее,  Дневное, Платники"
{
    N23Click (this);

    Create_Svod_ved_2VO2K (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N84Click (TObject * Sender)                          // Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. 2-е высшее,  Заочка,  Платники"
{
    N23Click (this);

    Create_Svod_ved_2VO2K (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N85Click (TObject * Sender)                          // Печать 'титульных листов' личного дела
{
    PersonalDocFrm = new TPersonalDocFrm (this);

    PersonalDocFrm -> ShowModal ();
}
void __fastcall TMainForm::N86Click (TObject * Sender)                          // Формирует: СПИСОК - Группы по полу
{
    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook = NewBook (ExcelApplication);

    Sheet =                                                                     // Показываем Excel
        SelectSheet (
            Workbook,
            "Лист1"
        );

    AnsiString n_file =
        getReportName (
            fac1,
            DocumentName::LIST::BY_GENDER
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );

    OVisible (ExcelApplication);

    Spisok_Pol (
        "М",
        Workbook
    );
    Spisok_Pol (
        "Ж",
        Workbook
    );

    // OVisible (ExcelApplication);
    // DisplayAlert (ExcelApplication);
}
void __fastcall TMainForm::N110Click (TObject * Sender)                         // 'Формы 1-К' для Министерства образования
{
    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir             +
            DocumentFile::REPORT::FORM_1
            // "Форма 1-К в Министерство образования.xls"
        );
    Sheet =
        SelectSheet (
            Workbook,
            "форма 1-К"
        );


    AnsiString sp;
               nom_row = 8;


    for ( int j = 0;                                                            // проход по виду обучения
              j < 2;
              ++j
        )
    {
        DMStat -> QF1kKol -> Close ();

        DMStat -> QF1kKol ->
            ParamByName ("EDU")  -> Value = j;

        DMStat -> QF1kKol -> Open ();


        DMStat -> QF1kAb -> Close ();

        // DMStat -> QF1kAb ->
        //     ParamByName ("konk") -> Value = 3;                                  // убрала в 2004 году т.к. конкурс стал 3 (2 курс), 4 (2-го В/О) непосредственно в SQL

        DMStat -> QF1kAb ->
            ParamByName ("STAT") -> Value = 0;

        DMStat -> QF1kAb ->
            ParamByName ("VID")  -> Value = j;

        DMStat -> QF1kAb -> Open ();


        if (j)
            CellValue (
                "Заочное",
                1,
                nom_row
            );
        else
            CellValue (
                "Дневное",
                1,
                nom_row
            );

        ++nom_row;


        int rec_kol = DMStat -> QF1kKol -> RecordCount;

        for ( int i = 0;
                  i < rec_kol;
                  ++i
            )
        {
            int all_sum = 0;                                                    // нужна в 2003 году, т.к. не учитывается копии аттестата

            sp = DMStat -> QF1kKolSPECIAL -> Value;

            CellValue (
                i + 1,
                1,
                nom_row
            );
            BorderCell (
                1,
                nom_row,
                1,
                2
            );
            CellValue (
                sp,
                2,
                nom_row
            );
            BorderCell (
                2,
                nom_row,
                1,
                2
            );
            CellValue (
                DMStat -> QF1kKolFAC1 -> Value,
                3,
                nom_row
            );
            BorderCell (
                3,
                nom_row,
                1,
                2
            );


            if (DMStat -> QF1kKolSUM_KOL_PLACE -> Value > 0)
            {
                CellValue (
                    DMStat -> QF1kKolSUM_KOL_PLACE -> Value,
                    4,
                    nom_row
                );
                BorderCell (
                    4,
                    nom_row,
                    1,
                    2
                );
            }
            else
            {
                CellValue (
                    " - ",
                    4,
                    nom_row
                );
                BorderCell (
                    4,
                    nom_row,
                    1,
                    2
                );
            }


            if (DMStat -> QF1kAbSPECIAL -> Value == sp)
            {
                if (!DMStat -> QF1kAbCOPY_AT -> Value)
                {
                    all_sum =
                        DMStat -> QF1kAbCOUNT_NOMER_AB -> Value;

                    DMStat -> QF1kAb -> Next ();

                    if (    DMStat -> QF1kAbSPECIAL -> Value == sp
                         && DMStat -> QF1kAbCOPY_AT -> Value
                        )
                    {
                        all_sum +=
                            DMStat -> QF1kAbCOUNT_NOMER_AB -> Value;

                        DMStat -> QF1kAb -> Next ();
                    }
                }
                else
                {
                    all_sum =
                        DMStat -> QF1kAbCOUNT_NOMER_AB -> Value;

                    DMStat -> QF1kAb -> Next ();
                }
            }

            CellValue (
                all_sum,
                5,
                nom_row
            );
            BorderCell (
                5,
                nom_row,
                1,
                2
            );
            BorderCell (
                6,
                nom_row,
                1,
                2
            );
            CellFormula (                                                       // (=E1/D1)
                "=E"                        +
                    AnsiString (nom_row)    +
                "/D"                        +
                    AnsiString (nom_row),
                6,
                nom_row
            );

            DMStat -> QF1kKol -> Next ();

            ++nom_row;
        }
    }

    AutoFitColumn (
        Sheet,
        2
    );


    AnsiString n_file =
        getReportName (
            DocumentName::REPORT::FORM_1
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );
    OVisible (ExcelApplication);

    // ExcelApplication.Clear ();

    DMStat -> QF1kKol -> Close ();
    DMStat -> QF1kAb -> Close ();
}
void __fastcall TMainForm::N112Click (TObject * Sender)
{
    int price,
        vid_educ;

    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir             +
            DocumentFile::REPORT::FORM_1
        );
    Sheet =
        SelectSheet (
            Workbook,
            "Дневное"
        );


    for ( vid_educ = 0;                                                         // проход по дневникам и заочникам
          vid_educ < 2;
          ++vid_educ
        )
    {
        if (vid_educ)                                                           // заочное
            Sheet =
                SelectSheet (
                    Workbook,
                    "Заочное"
                );

        DMStat -> QSpecial -> Open ();

        int rec_spec =
            DMStat -> QSpecial -> RecordCount;

        for ( int k = 0;
                  k < 2;
                  ++k
            )
            mas_spec_str[k] = new int[rec_spec];


        for ( int i = 0;                                                        // for массив специальностей
                  i < rec_spec;
                  ++i
            )
        {
            mas_spec_str[0][i] =
                DMStat -> QSpecialN_SPEC -> Value;
            mas_spec_str[1][i] =
                i + 15;

            DMStat -> QSpecial -> Next ();
        }


        // if (vid_educ)
        //     CellValue (                                                         // в 2004 году используем шаблон
        //         "заочная",
        //         8,
        //         5
        //     );
        // else
        //     CellValue (                                                         // в 2004 году используем шаблон
        //         "дневная",
        //         8,
        //         5
        //     );


        DMStat -> QCount_special_ab -> Close ();                                // ПОДАНО ЗАЯВЛЕНИЙ ВСЕГО
        DMStat -> QCount_special_ab -> SQL -> Clear ();
        DMStat -> QCount_special_ab ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     n_spec,"                      \
                    "     COUNT"                        \
                    "     ("                            \
                    "         nomer_ab"                 \
                    "     )"                            \
                    " FROM"                             \
                    "     abitura"                      \
                    " WHERE"                            \
                    "         status  IN (0,2,3,4,5)"   \
                    "     AND"                          \
                    "         vid_edu =  :EDU"          \
                    "     AND"                          \
                    "         n_spec  <> 1"             \
                    " GROUP BY"                         \
                    "     n_spec"
                );

        DMStat -> QCount_special_ab ->
            ParamByName ("EDU") -> AsInteger = vid_educ;
        DMStat -> QCount_special_ab -> Open ();


        for ( int j = 0;                                                        // общее количество поданных заявлений по специальности
                  j < DMStat -> QCount_special_ab -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_special_abCOUNT -> Value,
                    5,
                    Find_nom_spec_str (
                        DMStat -> QCount_special_abN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_special_abCOUNT -> Value,
                    6,
                    Find_nom_spec_str (
                        DMStat -> QCount_special_abN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_special_ab -> Next ();
        }


        if ( ! vid_educ)                                                        // ПО И ЦЕЛЕВЫЕ - ТОЛЬКО ДЛЯ ДНЕВНОГО
        {
            DMStat -> QCount_PO -> Close ();                                    // в 2004 году есть на форме информации о ПО
            DMStat -> QCount_PO -> SQL -> Clear ();
            DMStat -> QCount_PO ->
                SQL ->
                    Add (
                        " SELECT"                               \
                        "     COUNT"                            \
                        "     ("                                \
                        "         fam"                          \
                        "     ),"                               \
                        "     n_spec"                           \
                        " FROM"                                 \
                        "     abitura"                          \
                        " WHERE"                                \
                        "         priv    LIKE '15.'"           \
                        "     AND"                              \
                        "         status  IN   (0,2,3,4,5)"     \
                        "     AND"                              \
                        "         vid_edu =    0"               \
                        "     AND"                              \
                        "         n_spec  <>   1"               \
                        "     GROUP BY"                         \
                        "         n_spec"
                    );

            DMStat -> QCount_PO -> Open ();

            for ( int j = 0;                                                    // вычисление количества абитуриентов,окончивших ПО
                      j < DMStat -> QCount_PO -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_POCOUNT -> Value,
                    7,
                    Find_nom_spec_str (
                        DMStat -> QCount_PON_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_PO -> Next ();
            }


            DMStat -> QCount_CK -> Close ();
            DMStat -> QCount_CK -> SQL -> Clear ();
            DMStat -> QCount_CK ->
                SQL ->
                    Add (
                        " SELECT"                           \
                        "     COUNT"                        \
                        "     ("                            \
                        "         fam"                      \
                        "     ),"                           \
                        "     n_spec"                       \
                        " FROM"                             \
                        "     abitura"                      \
                        " WHERE"                            \
                        "         status  IN (0,2,3,4,5)"   \
                        "     AND"                          \
                        "         vid_edu =  0"             \
                        "     AND"                          \
                        "         konkurs =  2"             \
                        "     AND"                          \
                        "         n_spec  <> 1"             \
                        " GROUP BY"                         \
                        "     n_spec"
                    );

            DMStat -> QCount_CK -> Open ();


            for ( int j = 0;                                                    // вычисление количества абитуриентов с ЦК
                      j < DMStat -> QCount_CK -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_CKCOUNT -> Value,
                    8,
                    Find_nom_spec_str (
                        DMStat -> QCount_CKN_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_CK -> Next ();
            }
        }


        DMStat -> QCount_Medal -> Close ();                                     // МЕДАЛИСТЫ-ШКОЛЬНИКИ
        DMStat -> QCount_Medal -> SQL -> Clear ();
        DMStat -> QCount_Medal ->
            SQL ->
                Add (
                    " SELECT"                               \
                    "     COUNT"                            \
                    "     ("                                \
                    "         fam"                          \
                    "     ),"                               \
                    "     n_spec"                           \
                    " FROM"                                 \
                    "     abitura"                          \
                    " WHERE"                                \
                    "         status  IN   (0,2,3,4,5)"     \
                    "     AND"                              \
                    "         vid_edu =    :EDU"            \
                    "     AND"                              \
                    "         n_spec  <>   1"               \
                    "     AND"                              \
                    "         priv    LIKE '12.'"           \
                    " GROUP BY"                             \
                    "     n_spec"
                );

        DMStat -> QCount_Medal ->
            ParamByName ("EDU") -> AsInteger = vid_educ;
        DMStat -> QCount_Medal -> Open ();


        for ( int j = 0;                                                        // Подсчет общего кол-ва школьников с медалью
                  j < DMStat -> QCount_Medal -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_MedalCOUNT -> Value,
                    6,
                    Find_nom_spec_str (
                        DMStat -> QCount_MedalN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_MedalCOUNT -> Value,
                    9,
                    Find_nom_spec_str (
                        DMStat -> QCount_MedalN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Medal -> Next ();
        }


        DMStat -> QCount_Diplom -> Close ();                                    // ДИПЛОМЫ С ОТЛИЧИЕМ - ТОЛЬКО ДЛЯ ССУЗ И ПТУ
        DMStat -> QCount_Diplom -> SQL -> Clear ();
        DMStat -> QCount_Diplom ->
            SQL ->
                Add (
                    " SELECT"                               \
                    "     COUNT"                            \
                    "     ("                                \
                    "         fam"                          \
                    "     ),"                               \
                    "     n_spec"                           \
                    " FROM"                                 \
                    "     abitura"                          \
                    " WHERE"                                \
                    "         status  IN   (0,2,3,4,5)"     \
                    "     AND"                              \
                    "         vid_edu =    :EDU"            \
                    "     AND"                              \
                    "         n_spec  <>   1"               \
                    "     AND"                              \
                    "         priv    LIKE '13.'"           \
                    " GROUP BY"                             \
                    "     n_spec"
                );

        DMStat -> QCount_Diplom ->
            ParamByName ("EDU") -> AsInteger = vid_educ;
        DMStat -> QCount_Diplom -> Open ();


        for ( int j = 0;                                                        // Подсчет кол-ва окончивших ССУЗ и т.д. с отличием
                  j < DMStat -> QCount_Diplom -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_DiplomCOUNT -> Value,
                    7,
                    Find_nom_spec_str (
                        DMStat -> QCount_DiplomN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_DiplomCOUNT -> Value,
                    10,
                    Find_nom_spec_str (
                        DMStat -> QCount_DiplomN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Diplom -> Next ();
        }


        AnsiString SQL1 =                                                       // ПОДСЧЕТ ВСЕХ 'БЕЗ ЭКЗАМЕНОВ' (П.21 ПРАВИЛ ПРИЕМА)
            " SELECT"                           \
            "     COUNT"                        \
            "     ("                            \
            "         fam"                      \
            "     ),"                           \
            "     n_spec"                       \
            " FROM"                             \
            "     abitura"                      \
            " WHERE";
        AnsiString SQL2 = "";
        AnsiString SQL3 =
            "     AND"                          \
            "         status IN (0,2,3,4,5)"    \
            "     AND"                          \
            "         vid_edu = :EDU"           \
            "     AND"                          \
            "         n_spec <> 1"              \
            "     AND"                          \
            "         ("                        \
            "             n_found <> 2"         \
            "          OR"                      \
            "             n_found IS NULL"      \
            "         )"                        \
            " GROUP BY"                         \
            "     n_spec";



        if ( ! vid_educ)                                                        // Только дневное
        {
            SQL2 =                                                              // Победители и призеры чемпионатов Мира и Европы, участники Олимпийских игр ( WO = 1 или 2)
                "         ("                        \
                "             without LIKE '1'"     \
                "          OR"                      \
                "             without LIKE '2'"     \
                "         )";

            DMStat -> QCount_Olimp -> Close ();
            DMStat -> QCount_Olimp -> SQL -> Clear ();
            DMStat -> QCount_Olimp ->
                SQL ->
                    Add (
                        SQL1 +
                        SQL2 +
                        SQL3
                    );

            DMStat -> QCount_Olimp ->
                ParamByName ("EDU") -> AsInteger = vid_educ;
            DMStat -> QCount_Olimp -> Open ();


            for ( int j = 0;                                                    // Кол-во победителей и призеров ЧМ и Европы, участников Олимпийских игр
                      j < DMStat -> QCount_Olimp -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_OlimpCOUNT -> Value,
                    12,
                    Find_nom_spec_str (
                        DMStat -> QCount_OlimpN_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_Olimp -> Next ();
            }


            SQL2 =                                                              // Лауреаты фондов Президента РБ (WO = 3)
                "         without LIKE '3'";

            DMStat -> QCount_Olimp -> Close ();
            DMStat -> QCount_Olimp -> SQL -> Clear ();
            DMStat -> QCount_Olimp ->
                SQL ->
                    Add (
                        SQL1    +
                        SQL2    +
                        SQL3
                    );

            DMStat -> QCount_Olimp ->
                ParamByName ("EDU") -> AsInteger = vid_educ;
            DMStat -> QCount_Olimp -> Open ();


            for ( int j = 0;                                                    // Лауреаты фондов Президента РБ
                      j < DMStat -> QCount_Olimp -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_OlimpCOUNT -> Value,
                    13,
                    Find_nom_spec_str (
                        DMStat -> QCount_OlimpN_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_Olimp -> Next ();
            }


            DMStat -> QCount_Gimn -> Close ();                                  // ЗАКОНЧИВШИЕ ЛИЦЕИ, ГИМНАЗИИ (в 2004-2006 году только для дневного)
            DMStat -> QCount_Gimn -> SQL -> Clear ();
            DMStat -> QCount_Gimn ->
                SQL ->
                    Add (
                        " SELECT"                               \
                        "     COUNT"                            \
                        "     ("                                \
                        "         fam"                          \
                        "     ),"                               \
                        "     n_spec"                           \
                        " FROM"                                 \
                        "     abitura"                          \
                        " WHERE"                                \
                        "         stat_ab LIKE '3'"             \
                        "     AND"                              \
                        "         status  IN   (0,2,3,4,5)"     \
                        "     AND"                              \
                        "         vid_edu =    :EDU"            \
                        "     AND"                              \
                        "         n_spec  <>   1"               \
                        " GROUP BY"                             \
                        "     n_spec"
                    );

            DMStat -> QCount_Gimn ->
                ParamByName ("EDU") -> AsInteger = vid_educ;
            DMStat -> QCount_Gimn -> Open ();


            for ( int j = 0;                                                    // Подсчет кол-ва окончивших лицей или гимназию
                      j < DMStat -> QCount_Gimn -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_GimnCOUNT -> Value,
                    14,
                    Find_nom_spec_str (
                        DMStat -> QCount_GimnN_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_Gimn -> Next ();
            }
        }
        else                                                                    // заочное обучение п.21 складывается
        {
            SQL2 =
                "         ("                        \
                "             without LIKE '1'"     \
                "          OR"                      \
                "             without LIKE '2'"     \
                "          OR"                      \
                "             without LIKE '3'"     \
                "          OR"                      \
                "             without LIKE '4'"     \
                "         )";

            DMStat -> QCount_Olimp -> Close ();
            DMStat -> QCount_Olimp -> SQL -> Clear ();
            DMStat -> QCount_Olimp ->
                SQL ->
                    Add (
                        SQL1    +
                        SQL2    +
                        SQL3
                    );

            DMStat -> QCount_Olimp ->
                ParamByName ("EDU") -> AsInteger = vid_educ;
            DMStat -> QCount_Olimp -> Open ();


            for ( int j = 0;
                      j < DMStat -> QCount_Olimp -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_OlimpCOUNT -> Value,
                    8,
                    Find_nom_spec_str (
                        DMStat -> QCount_OlimpN_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_Olimp -> Next ();
            }
        }


        AnsiString SQL_Gorod =                                                  // ВЫПУСКНИКИ ВСЕХ СЕЛЬСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ
            " SELECT"                                   \
            "     COUNT"                                \
            "     ("                                    \
            "         fam"                              \
            "     ),"                                   \
            "     n_spec"                               \
            " FROM"                                     \
            "     abitura"                              \
            " WHERE"                                    \
            "         stat_ab LIKE :N"                  \
            "     AND"                                  \
            "         status  IN   (0,2,3,4,5)"         \
            "     AND"                                  \
            "         vid_edu =    :EDU"                \
            "     AND"                                  \
            "         n_spec  <>   1"                   \
            "     AND"                                  \
            "         ("                                \
            "             when_edu_middle LIKE :GOD"    \
            "          OR"                              \
            "             when_edu_spec   LIKE :GOD"    \
            "         )"                                \
            " GROUP BY"                                 \
            "     n_spec";

        DMStat -> QCount_Gorod -> Close ();
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add (
                    SQL_Gorod
                );


        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "4";                            // сельские
        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;
        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "%";
        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // Расчет кол-ва окончивших сельские УО
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    9,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    15,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Gorod -> Next ();
        }


        DMStat -> QCount_Gorod -> Close ();                                     // ВЫПУСКНИКИ СЕЛЬСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ - Только текущего года
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add (
                    SQL_Gorod
                );


        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "4";                            // сельские
        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;
        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "2006";
        DMStat -> QCount_Gorod -> Open ();



        for ( int j = 0;                                                        // Расчет кол-ва окончивших сельские УО
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    10,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    16,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Gorod -> Next ();
        }


        DMStat -> QCount_Gorod -> Close ();                                     // ВЫПУСКНИКИ ГОРОДСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ - ВСЕХ
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add (
                    SQL_Gorod
                );


        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "5";                            // городские
        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;
        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "%";
        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // Расчет кол-ва окончивших городские УО
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    11,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    17,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Gorod -> Next ();
        }


        DMStat -> QCount_Gorod -> Close ();                                     // ВЫПУСКНИКИ ГОРОДСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ - Только текущего года
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add (
                    SQL_Gorod
                );


        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "5";                            // городские
        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;
        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "2006";
        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // Расчет кол-ва окончивших городские УО
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    12,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    18,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Gorod -> Next ();
        }


        DMStat -> QCount_Stag -> Close ();                                      // СТАЖ БОЛЕЕ 2-х ЛЕТ
        DMStat -> QCount_Stag -> SQL -> Clear ();
        DMStat -> QCount_Stag ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     COUNT"                        \
                    "     ("                            \
                    "         fam"                      \
                    "     ),"                           \
                    "     n_spec"                       \
                    " FROM"                             \
                    "     abitura"                      \
                    " WHERE"                            \
                    "         ("                        \
                    "             stag      >= 24"      \
                    "          OR"                      \
                    "             stag_spec >= 24"      \
                    "         )"                        \
                    "     AND"                          \
                    "         status  IN (0,2,3,4,5)"   \
                    "     AND"                          \
                    "         vid_edu =  :EDU"          \
                    "     AND"                          \
                    "         n_spec  <> 1"             \
                    " GROUP BY"                         \
                    "     n_spec"
                );

        DMStat -> QCount_Stag ->
            ParamByName ("EDU") -> AsInteger = vid_educ;
        DMStat -> QCount_Stag -> Open ();


        for ( int j = 0;                                                        // Расчет кол-ва имеющих стаж более 2-х лет
                  j < DMStat -> QCount_Stag -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_StagCOUNT -> Value,
                    13,
                    Find_nom_spec_str (
                        DMStat -> QCount_StagN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_StagCOUNT -> Value,
                    19,
                    Find_nom_spec_str (
                        DMStat -> QCount_StagN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Stag -> Next ();
        }


        DMStat -> QCount_Test -> Close ();                                      // СЕРТИФИКАТЫ ЦЕНТРАЛИЗОВАННОГО ТЕСТИРОВАНИЯ (3 штуки) (с 2003 года введен, с 2006 2ЦТ (обязательно) + 1)
        DMStat -> QCount_Test -> SQL -> Clear ();
        DMStat -> QCount_Test ->
            SQL ->
                Add (
                    " SELECT"                                                  \
                    "     COUNT"                                               \
                    "     ("                                                   \
                    "         abitura.nomer_ab"                                \
                    "     ),"                                                  \
                    "     abitura.n_spec"                                      \
                    " FROM"                                                    \
                    "     abitura"                                             \
                    " WHERE"                                                   \
                    "         EXISTS"                                          \
                    "         ("                                               \
                    "             SELECT"                                      \
                    "                 sertificat.nomer_ab"                     \
                    "             FROM"                                        \
                    "                 sertificat"                              \
                    "             WHERE"                                       \
                    "                 sertificat.nomer_ab = abitura.nomer_ab"  \
                    "             GROUP BY"                                    \
                    "                 sertificat.nomer_ab"                     \
                    "             HAVING"                                      \
                    "                 COUNT"                                   \
                    "                 ("                                       \
                    "                     sertificat.n_predmet"                \
                    "                 ) = 3"                                   \
                    "         )"                                               \
                    "     AND"                                                 \
                    "         abitura.status  IN (0,2,3,4,5)"                  \
                    "     AND"                                                 \
                    "         abitura.vid_edu =  :EDU"                         \
                    "     AND"                                                 \
                    "         abitura.n_spec  <> 1"                            \
                    " GROUP BY"                                                \
                    "     abitura.n_spec"
                );

        DMStat -> QCount_Test ->
            ParamByName ("EDU") -> AsInteger = vid_educ;
        DMStat -> QCount_Test -> Open ();


        for ( int j = 0;                                                        // Расчет кол-ва абитуриентов с ЦТ = 3
                  j < DMStat -> QCount_Test -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_TestCOUNT -> Value,
                    14,
                    Find_nom_spec_str (
                        DMStat -> QCount_TestN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_TestCOUNT -> Value,
                    21,
                    Find_nom_spec_str (
                        DMStat -> QCount_TestN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_Test -> Next ();
        }


        DMStat -> QCount_RUOR -> Close ();                                      // НА СОКРАЩЕННЫЙ СРОК ОБУЧЕНИЯ (2 курс - РУОР)
        DMStat -> QCount_RUOR -> SQL -> Clear ();
        DMStat -> QCount_RUOR ->
            SQL ->
                Add (
                    " SELECT"                           \
                    "     COUNT"                        \
                    "     ("                            \
                    "         fam"                      \
                    "     ),"                           \
                    "     n_spec"                       \
                    " FROM"                             \
                    "     abitura"                      \
                    " WHERE"                            \
                    "         status  IN (0,2,3,4,5)"   \
                    "     AND"                          \
                    "         vid_edu =  :EDU"          \
                    "     AND"                          \
                    "         konkurs =  3"             \
                    "     AND"                          \
                    "         n_spec  <> 1"             \
                    " GROUP BY"                         \
                    "     n_spec"
                );

        DMStat -> QCount_RUOR ->
            ParamByName ("EDU") -> AsInteger = vid_educ;
        DMStat -> QCount_RUOR -> Open ();


        for ( int j = 0;                                                        // Расчет кол-ва абитуриентов на 2 курс
                  j < DMStat -> QCount_RUOR -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // заочное
                CellValue (
                    DMStat -> QCount_RUORCOUNT -> Value,
                    15,
                    Find_nom_spec_str (
                        DMStat -> QCount_RUORN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // дневное
                CellValue (
                    DMStat -> QCount_RUORCOUNT -> Value,
                    22,
                    Find_nom_spec_str (
                        DMStat -> QCount_RUORN_SPEC -> Value,
                        rec_spec
                    )
                );

            DMStat -> QCount_RUOR -> Next ();
        }


        if ( ! vid_educ)                                                        // только дневная форма обучения
        {
            DMStat -> QCount_Region -> Close ();                                // ГРАЖДАНЕ РФ, КАЗАХСТАНА, КЫРГЫЗТАНА, ТАДЖЫКИСТАНА
            DMStat -> QCount_Region -> SQL -> Clear ();
            DMStat -> QCount_Region ->
                SQL ->
                    Add (
                        " SELECT"                                   \
                        "     COUNT"                                \
                        "     ("                                    \
                        "         nomer_ab"                         \
                        "     ),"                                   \
                        "     n_spec"                               \
                        " FROM"                                     \
                        "     abitura"                              \
                        " WHERE"                                    \
                        "         gragdan  <> 'РБ'"                 \
                        "     AND"                                  \
                        "         n_centre IN (122,123,124,125)"    \
                        "     AND"                                  \
                        "         status   IN (0,2,3,4,5)"          \
                        "     AND"                                  \
                        "         vid_edu  =  :EDU"                 \
                        "     AND"                                  \
                        "         n_spec   <> 1"                    \
                        " GROUP BY"                                 \
                        "     n_spec"
                    );

            DMStat -> QCount_Region ->
                ParamByName ("EDU") -> AsInteger = vid_educ;
            DMStat -> QCount_Region -> Open ();


            for ( int j = 0;                                                    // Расчет кол-ва абитуриентов из других республик
                      j < DMStat -> QCount_Region -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_RegionCOUNT -> Value,
                    20,
                    Find_nom_spec_str (
                        DMStat -> QCount_RegionN_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_Region -> Next ();
            }
        }
        else
        {
            DMStat -> QCount_High -> Close ();
            DMStat -> QCount_High -> SQL -> Clear ();
            DMStat -> QCount_High ->
                SQL ->
                    Add (
                        " SELECT"                           \
                        "     COUNT"                        \
                        "     ("                            \
                        "         fam"                      \
                        "     ),"                           \
                        "     n_spec"                       \
                        " FROM"                             \
                        "     abitura"                      \
                        " WHERE"                            \
                        "         status  in (0,2,3,4,5)"   \
                        "     AND"                          \
                        "         vid_edu =  :EDU"          \
                        "     AND"                          \
                        "         n_spec  <> 1"             \
                        "     AND"                          \
                        "         ("                        \
                        "             without LIKE '5'"     \
                        "          OR"                      \
                        "             v_k     LIKE '5'"     \
                        "          OR"                      \
                        "             stat_ab LIKE '8'"     \
                        "         )"                        \
                        " GROUP BY"                         \
                        "     n_spec"
                    );

            DMStat -> QCount_High ->
                ParamByName ("EDU") -> AsInteger = vid_educ;
            DMStat -> QCount_High -> Open ();


            for ( int j = 0;                                                    // Расчет кол-ва абитуриентов на 2-ое высшее
                      j < DMStat -> QCount_High -> RecordCount;
                      ++j
                )
            {
                CellValue (
                    DMStat -> QCount_HighCOUNT -> Value,
                    16,
                    Find_nom_spec_str (
                        DMStat -> QCount_HighN_SPEC -> Value,
                        rec_spec
                    )
                );

                DMStat -> QCount_High -> Next ();
            }
        }


        DMStat -> QCount_High       -> Close ();
        DMStat -> QCount_RUOR       -> Close ();
        // DMStat -> QCount_Platn      -> Close ();
        DMStat -> QCount_Test       -> Close ();

        DMStat -> QCount_Region     -> Close ();
        DMStat -> QCount_Stag       -> Close ();
        DMStat -> QCount_Gorod      -> Close ();

        DMStat -> QCount_Gimn       -> Close ();
        DMStat -> QCount_Olimp      -> Close ();
        DMStat -> QCount_Diplom     -> Close ();
        DMStat -> QCount_Medal      -> Close ();
        DMStat -> QCount_CK         -> Close ();
        DMStat -> QCount_PO         -> Close ();
        DMStat -> QCount_special_ab -> Close ();
        DMStat -> QSpecial          -> Close ();

        for ( int i = 0;
                  i < 2;
                  ++i
            )
            if (mas_spec_str)
                delete [] mas_spec_str[i];

        if (mas_spec_str)
            delete [] mas_spec_str;
    }


    AnsiString n_file =
        getReportName (
            DocumentName::REPORT::FORM_1
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );

    OVisible (ExcelApplication);

    // ExcelApplication.Clear ();
}
void __fastcall TMainForm::N310Click (TObject * Sender)                         // 'Форма 3' Дневная форма обучения
{
    Forma_Giac (
        static_cast <int> (FormTypeCode::ENROLLMENT),
        static_cast <int> (EducationTypeCode::INTRAMURAL)
    );
}
void __fastcall TMainForm::N311Click(TObject *Sender)
{
    Protokol4_J (2);
}
void __fastcall TMainForm::Priv_Str (int par)                                   // строка с привилегиями (par = 10 - полный список абитуриентов)
{
    // int        n_ab;                                                            // номер абитуриента

               S1         = "";                                                 // по конкурсу
               S2         = "";                                                 // все привилегии и преимущества
               S3         = "";                                                 // спортивный разряд
    AnsiString Stat_ab_vk = "",                                                 // Вне конкурса
               Stat_ab_pr = "",                                                 // Привилегии
               Stat_ab_wo = "";                                                 // Без экзаменов


    DMStat -> FullGrpS1Qr -> Close ();

    DMStat -> FullGrpS1Qr ->
        ParamByName ("nomer_ab") -> AsInteger =
                DM -> QSpisoc_GroupNOMER_AB -> Value;

    DMStat -> FullGrpS1Qr -> Open ();


    if (DMStat -> FullGrpS1QrCATEGORY_IF -> Value)
        S1 = "Иностранец";


    if (DMStat -> FullGrpS1QrCITIZENSHIP -> Value != 22)
    {
        DMStat -> CitizenQr -> Close ();

        S1 =
            DMStat -> CitizenQrNAME -> AsString;

        DMStat -> CitizenQr -> Close ();
    }


    switch (DMStat -> FullGrpS1QrKONKURS -> Value)
    {
        case 1:
                if (S1 == "")
                    S1 = "БВИ";
                else
                    S1 += ",БВИ";
            break;
        case 2:
                if (S1 == "")
                    S1 = "ВК";
                else
                    S1 += ",ВК";
            break;
        case 3:
                if (S1 == "")
                    S1 = "ЦК";
                else
                    S1 += ",ЦК";
            break;
    }


    switch (DMStat -> FullGrpS1QrTERM_EDU -> Value)
    {
        case 1:
                if (S1 == "")
                    S1 = "ССО 2к.";
                else
                    S1 += ",ССО 2к.";
            break;
        case 2:
                if (S1 == "")
                    S1 = "ССО 3к.";
                else
                    S1 += ",ССО 3к.";
            break;
        case 3:
                if (S1 == "")
                    S1 = "ВО 1к.";
                else
                    S1 += ",ВО 1к.";
            break;
        case 4:
                if (S1 == "")
                    S1 = "ВО 2к.";
                else
                    S1 += ",ВО 2к.";
            break;
        case 5:
                if (S1 == "")
                    S1 = "ВО 3к.";
                else
                    S1 += ",ВО 3к.";
            break;
    }


    if (DMStat -> FullGrpS1QrPRICE -> Value)
        if (S1 == "")
            S1 = "за опл. ";
        else
            S1 += ",за опл. ";


    DMStat -> FullGrpS1Qr -> Close ();


    switch (par)
    {
        case 10:                                                                // полный список
                Stat_ab_wo = DM -> QSpisoc_GroupWITHOUT -> Value;
                Stat_ab_vk = DM -> QSpisoc_GroupV_K     -> Value;
                Stat_ab_pr = DM -> QSpisoc_GroupPRIV    -> Value;
            break;
        default:                                                                // 0-город, 1-село, 2-ЦК, 3-второй курс, 4-вне конкурса, 5-без экзаменов, 6-иностранцы
                Stat_ab_wo =
                    ReturnField (
                        "OUT_WITHOUT"
                    );
                Stat_ab_vk =
                    ReturnField (
                        "OUT_V_K"
                    );
                Stat_ab_pr =
                    ReturnField (
                        "OUT_PRIV"
                    );
            break;
    }


    if (par == 10)                                                              // полный список абитуриентов
    {
        // switch (DM -> QSpisoc_GroupKONKURS -> Value)                            // конкурс
        // {
        //     case 1:
        //             S1 += AnsiString ("цк ");
        //         break;
        //     case 2:
        //             // if (DM -> QSpisoc_GroupN_FAC -> Value == 3)
        //             //     S1 += "3 курс ";
        //             // else
        //                 S1 += "2 курс ";
        //         break;
        //     case 3:
        //             S1 += AnsiString ("вне конк. ");
        //         break;
        //     case 4:
        //             S1 += AnsiString ("без экз. ");
        //         break;
        //     case 5:
        //             S1 += AnsiString ("иностранец ");
        //         break;
        // }

        // if (DM -> QSpisoc_GroupPRICE -> Value)                                  // Форма оплаты
        //     S1 += AnsiString ("за опл. ");

        // if (DM -> QSpisoc_GroupGRAGDAN -> Value != "РБ")
        //     S2 +=
        //         DM -> QSpisoc_GroupGRAGDAN -> Value + " ";


        if (DM -> QSpisoc_GroupN_SPORT_CATEGORY -> Value > 0)                   // разряд
            S3 =
                DM -> TCategory ->
                    Lookup (
                        "N_SPORT_CATEGORY",
                        DM -> QSpisoc_GroupN_SPORT_CATEGORY -> Value,
                        "SPORT_CATEGORY"
                    );
    }


    if (    par == 1                                                            // для ЦК в сводную ведомость
         && DMVed -> QKonkursOUT_N_CK -> Value
       )
    {
        S2 += AnsiString ("Целевой договор (");

        Variant ck =
            DM -> TCk ->
                Lookup (
                    "N_CK",
                    DMVed -> QKonkursOUT_N_CK -> Value,
                    "TEXT_DEP"
                );

        if (ck.IsNull ())
            S2 += "????";
        else
            S2 += ck.AsType (varString);

        S2 += AnsiString (" р-н) ");
    }

    // int len = Stat_ab_wo.Length ();                                             // 'без экзаменов'

    // for ( int i =  1;
    //           i <= len;
    //           ++i
    //     )
    // {
    //     int el_str = StrToInt (Stat_ab_wo[i]);

    //     switch (el_str)
    //     {
    //         case 1:
    //                 S2 +=
    //                     AnsiString (
    //                         "Победители (дипломы I,II,III степени) международных олимпиад и "
    //                     )                               +
    //                     AnsiString (
    //                         "республиканской олимпиады по учебным предметам (ТиГ география) "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 2:
    //                 S2 +=
    //                     AnsiString (
    //                         "Победители,призеры и участники Олимпийских, Паралимпийских и Дефлимпий"
    //                     )                               +
    //                     AnsiString (
    //                         "ских игр,"
    //                     )                               +
    //                     AnsiString (
    //                         " победители и призеры Юношеских Олимпийских игр "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 3:
    //                 S2 +=
    //                     AnsiString (
    //                         "Победители и призеры чемпионатов,финалов розыгрышей кубков, первенств "
    //                     )                               +
    //                     AnsiString (
    //                         "мира и Европы, Олимпийских фестивалей молодежи Европы "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 4:
    //                 S2 +=
    //                     AnsiString (
    //                         "Победители официальных чемпионатов Республики Беларусь,включенным в "
    //                     )                               +
    //                     AnsiString (
    //                         "программу летних и зимних Олимпийских игр "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 5:
    //                 S2 +=
    //                     AnsiString (
    //                         "Победители и призеры чемпионатов, первенств мира и Европы среди "
    //                     )                               +
    //                     AnsiString (
    //                         "инвалидов "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 6:
    //                 S2 +=
    //                     AnsiString (
    //                         "Второе в/о на платной основе на 2 и старшие курсы "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //     }
    // }

    // len = Stat_ab_vk.Length ();                                                 // 'вне конкурса'

    // for ( int i =  1;
    //           i <= len;
    //           ++i
    //     )
    // {
    //     int el_str = StrToInt (Stat_ab_vk[i]);

    //     switch (el_str)
    //     {
    //         case 1:
    //                 S2 += AnsiString ("Дети-сироты ");
    //             break;
    //         case 2:
    //                 S2 +=
    //                     AnsiString (
    //                         "Призеры официальных чемпионатов,победители и призеры розыгрышей кубков,"
    //                     )                               +
    //                     AnsiString (
    //                         " первенств Республики Беларусь "
    //                     )                               +
    //                     (char) (13);
    //         // case 2:
    //         //         S2 +=
    //         //             "Инвалид 1 или 2 гр. ";
    //         //     break;
    //         case 3:
    //                 S2 +=
    //                     AnsiString (
    //                         "Победители официальных чемпионатов,розыгрышей кубков Республики Беларусь"
    //                     )                               +
    //                     AnsiString (
    //                         " по остальным видам спорта "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 4:
    //                 S2 +=
    //                     AnsiString (
    //                         "Выпускники УОР, получившие в год приема среднее специальное образование "
    //                     )                               +
    //                     AnsiString (
    //                         "за счет средств бюджета "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 5:
    //                 S2 +=
    //                     AnsiString (
    //                         "Уволенные со срочной военной службы в запас в год приема (почетн. караул "
    //                     )                               +
    //                     AnsiString (
    //                         "ВС,погран. служба,ВВ МВД) "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 6:                                                             // Оля в 2011 году
    //                 S2 +=
    //                     AnsiString (
    //                         "Второе в/о на платной основе на 1 курс "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //     }
    // }


    // len = Stat_ab_pr.Length ();                                                 // преимущества при зачислении

    // int len_old = len,
    //     p       = 0;                                                            // позиция символа первого вхождения точки

    // for ( int i =  1;                                                           // for Priv
    //           i <= len_old;
    //           ++i
    //     )
    // {
    //     if (len != 0)                                                           // if есть еще строка
    //     {
    //         p = Stat_ab_pr.Pos (".");

    //         if (p != 1)
    //         {
    //             int Priv =
    //                 StrToInt (
    //                     Stat_ab_pr.SubString (
    //                         1,
    //                         p - 1
    //                     )
    //                 );

    //             switch (Priv)                                                   // Vk
    //             {
    //                 case 1:
    //                         S2 +=
    //                             AnsiString (
    //                                 "Выпускники УОР,пед. колледжей "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 2:
    //                         S2 +=
    //                             AnsiString (
    //                                 "Выпускники профильных учебн. заведений "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 3:
    //                         S2 +=
    //                             AnsiString (
    //                                 "Стаж практической работы не менее 6 месяцев по специальности "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 4:
    //                         S2 +=
    //                             AnsiString (
    //                                 "Выпускники ФДП БГУФК "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 5:
    //                         S2 +=
    //                             AnsiString (
    //                                 "Победители ( I степени ) 3-го этапа респ. олимпиады "
    //                             );
    //                     break;
    //                 case 6:
    //                         S2 +=
    //                             AnsiString (
    //                                 "Победителя (I ,II,III степени) респ. олимпиады (бел. и русск. яз) "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 7:
    //                         S2 +=
    //                             AnsiString (
    //                                 "МС РБ,МСМК РБ "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 8:
    //                         S2 +=
    //                             AnsiString (
    //                                 "Золотая и серебряная медаль "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 9:
    //                         S2 +=
    //                             AnsiString (
    //                                 "Диплом с отличием проф-тех. образ-я "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 10:
    //                         S2 +=
    //                             AnsiString (
    //                                 "Диплом с отличием ССУЗ "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 11:
    //                         S2 +=
    //                             AnsiString (
    //                                 "Свидетельство с отличием о баз. образ-я "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 12:
    //                         S2 +=
    //                             AnsiString (
    //                                 "Подготов. отд. Дневная форма (другое УВО) "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 // case 13:
    //                 //         S2 +=
    //                 //             "Диплом с отл. (базовое образование) ";
    //                 //     break;
    //                 // case 14:
    //                 //         S2 += "Выпускник УОР ";
    //                 //     break;
    //                 // case 15:
    //                 //         S2 +=
    //                 //             "Выпускник ПО БГУФК (6 мес.) ";
    //                 //     break;
    //                 // case 16:
    //                 //         S2 += "Неполная семья ";
    //                 //     break;
    //                 // case 17:
    //                 //         S2 +=
    //                 //             "Диплом с отл. (высшее образование) ";
    //                 //     break;
    //                 // case 18:
    //                 //         S2 += "Выпускник ПО БГУФК ";
    //                 //     break;
    //                 // case 19:
    //                 //         S2 +=
    //                 //             "Стаж более 2-х лет (род. специальность) ";
    //                 //     break;
    //                 // case 20:                                                    // Закончили ПО дневной формы другого ВУЗА
    //                 //         S2 += "";
    //                 //     break;
    //                 // case 21:
    //                 //         S2 +=
    //                 //             "Уволенные со срочн. службы в год приема (почетн.караул: ВС, погран.служба, ВВ МВД)";
    //                 //     break;
    //                 // case 22:                                                    // Закончили ПО дневной формы другого ВУЗА
    //                 //         S2 +=
    //                 //             "Выпускник профильных учебных заведений";
    //                 //     break;
    //                 // case 23:                                                    // Диплом с отл. (на базе среднего образования)
    //                 //         S2 += "";
    //                 //     break;
    //             }
    //         }
    //     }
    //     else
    //         break;

        String NameSertificat;                                                  // 'ПРИВИЛЕГИИ'

        DMStat -> LastLogQr -> Close ();

        DMStat -> LastLogQr ->
            ParamByName ("nomer_ab") -> AsInteger =
                    DM -> QSpisoc_GroupNOMER_AB -> Value;
        DMStat -> LastLogQr -> Open ();


        DM -> SelPrivLogQr -> Close ();

        DM -> SelPrivLogQr ->
            ParamByName ("id_log")   -> AsInteger =
                    DMStat -> LastLogQrID_LOG -> Value;

        DM     -> SelPrivLogQr -> Open ();


        DMStat -> LastLogQr    -> Close ();

        while ( ! DM -> SelPrivLogQr -> Eof)
        {
            switch (DM -> SelPrivLogQrN_PRIV -> Value)
            {
                case 0:                                                         // БВИ
                        DM -> WithOutTestLogQr -> Close ();

                        DM -> WithOutTestLogQr ->
                            ParamByName ("sel_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrSEL_PRIV -> Value;

                        DM -> WithOutTestLogQr ->
                            ParamByName ("dat_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrDAT_PRIV -> Value;

                        DM -> WithOutTestLogQr -> Open ();


                        while ( ! DM -> WithOutTestLogQr -> Eof)
                        {
                            if (NameSertificat != "")
                                NameSertificat += ",";

                            NameSertificat +=
                                DM -> WithOutTestLogQrSHORT_NAME -> Value;

                            if (    DM -> WithOutTestLogQrSHORT_NAME_1 -> Value
                                 != "да"
                               )
                                NameSertificat +=
                                    " - "                                           +
                                    DM -> WithOutTestLogQrSHORT_NAME_1 -> Value;

                            DM -> WithOutTestLogQr -> Next ();
                        }

                        DM -> WithOutTestLogQr -> Close ();
                    break;
                case 1:                                                         // ВК
                        DM -> OutTestQr -> Close ();

                        DM -> OutTestQr ->
                            ParamByName ("sel_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrSEL_PRIV -> Value;

                        DM -> OutTestQr ->
                            ParamByName ("dat_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrDAT_PRIV -> Value;

                        DM -> OutTestQr -> Open ();

                        while (!DM -> OutTestQr -> Eof)
                        {
                            if (NameSertificat != "")
                                NameSertificat +=
                                    ",";

                            NameSertificat +=
                                DM -> OutTestQrSHORT_NAME -> Value;

                            if (    DM -> OutTestQrSHORT_NAME_1 -> Value
                                 != "да"
                               )
                                NameSertificat +=
                                    " - "                                   +
                                    DM -> OutTestQrSHORT_NAME_1 -> Value;

                            DM -> OutTestQr -> Next ();
                        }

                        DM -> OutTestQr -> Close ();
                    break;
                case 2:                                                         // Другие
                        DM -> OtherPrivQr -> Close ();

                        DM -> OtherPrivQr ->
                            ParamByName ("sel_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrSEL_PRIV -> Value;

                        DM -> OtherPrivQr -> Open ();

                        while ( ! DM -> OtherPrivQr -> Eof)
                        {
                            if (NameSertificat != "")
                                NameSertificat += ",";

                            NameSertificat +=
                                DM -> OtherPrivQrSHORT_NAME -> Value;

                            DM -> OtherPrivQr -> Next ();
                        }

                        DM -> OtherPrivQr -> Close ();
                    break;
            }

            DM -> SelPrivLogQr -> Next ();
        }

        DM -> SelPrivLogQr -> Close ();

        S2 += NameSertificat;


    //     Stat_ab_pr.Delete (
    //         1,
    //         p
    //     );

    //     len = Stat_ab_pr.Length ();
    // }
}
void __fastcall TMainForm::Protokol4_J (int pol)                                // Для девочек 4 вида
{
    DMVed -> QGroupProtokol -> Close ();
    DMVed -> QGroupProtokol ->
        ParamByName ("fac") -> Value = nom_fac;
    DMVed -> QGroupProtokol -> Open ();


    ExcelApplication = Variant::CreateObject ("Excel.Application");             // Открытие шаблона

    Variant Workbook;

    if (    nom_fac != 4
         && pol     == 2
       )
        Workbook =
            OpenBook (
                ExcelApplication,
                cur_dir                             +
                DocumentFile::PROTOCOL::GIRLS_TESTS
            );
    if (    nom_fac != 4
         && pol     == 1
       )
        Workbook =
            OpenBook (
                ExcelApplication,
                cur_dir                             +
                DocumentFile::PROTOCOL::GIRLS_TESTS
            );

    OVisible (ExcelApplication);                                                // удалить
    DisplayAlert (ExcelApplication);

    AnsiString n_file =
        getReportName (
            fac1,
            DocumentName::PROTOCOL::GIRLS_TESTS
        );

    Variant WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );

    for ( int i = 0;                                                            // Выделяю лист
              i < DMVed -> QGroupProtokol -> RecordCount;
              ++i
        )
    {
        Sheet =                                                                 // Копирую лист с номером группы
            SelectSheet (
                Workbook,
                "Пустой"
            );

        CopySheet (Sheet);

        Sheet =
            SelectSheet (
                Workbook,
                "Пустой (2)"
            );

        NameSheet1 (
            Sheet,
            DMVed -> QGroupProtokolNOM_GROUP -> Value.SetLength (30)
        );

        DMVed -> QPeopleProtocol -> Close ();

        DMVed -> QPeopleProtocol ->
            ParamByName ("fac") -> Value =
                    nom_fac;

        DMVed -> QPeopleProtocol ->
            ParamByName ("n_gr") -> Value =
                    DMVed -> QGroupProtokolNOM_GROUP -> Value;

        if (pol == 2)                                                           // Выбираю из группы девочек
            DMVed -> QPeopleProtocol ->
                ParamByName ("pol") -> Value = "Ж";

        if (pol == 1)
            DMVed -> QPeopleProtocol ->
                ParamByName ("pol") -> Value = "М";

        DMVed -> QPeopleProtocol -> Open ();

        CellValue (                                                             // становлюсь в ячейку и набираю номер группы
            DMVed -> QGroupProtokolNOM_GROUP -> Value,
            3,
            3
        );

        int k = 6;

        for ( int j = 0;                                                        // Иду по Query
                  j < DMVed -> QPeopleProtocol -> RecordCount;
                  ++j
            )
        {
            CellValue (
                DMVed -> QPeopleProtocolFIO -> Value,
                2,
                k
            );

            if (pol == 2)
                CellValue (
                    "Ж",
                    3,
                    k++
                );

            if (pol == 1)
                CellValue (
                    "М",
                    3,
                    k++
                );

            DMVed -> QPeopleProtocol -> Next ();
        }

        DMVed -> QGroupProtokol -> Next ();
    }

    WorkSaveAs = SaveBook (Workbook);                                           // сохранение

    ExcelApplication.Clear ();
}
AnsiString TMainForm::ReturnField (AnsiString f)                                // возвращает значение поля
{
    Variant rez =
        qq -> Fields -> FieldByName (f) -> Value;

    if (rez.IsNull ())
        return
            "";

    return
        rez.AsType (varString);
}
AnsiString TMainForm::ReturnField_IT (AnsiString f)                             // возвращает значение поля
{
    Variant rez =
        qq -> Fields -> FieldByName (f) -> Value;

    if (rez.IsNull ())
        return
            "";

    return
        rez.AsType (varString);
}
void __fastcall TMainForm::Run_ProcBall (                                       // вызов процедуры с расчетом количества по сумме баллов
        int fac,
        int ed,
        int konk,
        int price,
        int kolon,
        int stroka_n
    )
{
    if (konk == 0)                                                              // для поступающих на 1-ый курс
    {
        DM -> RaspredBallStrdPrc ->
            ParamByName ("N_FAC")   -> AsSmallInt = fac;

        DM -> RaspredBallStrdPrc ->
            ParamByName ("N_SP")    -> AsSmallInt = spec;

        DM -> RaspredBallStrdPrc ->
            ParamByName ("VID_EDU") -> AsSmallInt = ed;

        DM -> RaspredBallStrdPrc ->
            ParamByName ("PRICE")   -> AsSmallInt = price;

        DM -> RaspredBallStrdPrc -> Prepare ();
        DM -> RaspredBallStrdPrc -> ExecProc ();

        int temp  = 0;                                                           // временная переменная
            kolon = 46;

        for ( int i = 4;                                                        // проходим по параметрм - диапазонам баллов
                  i < DM -> RaspredBallStrdPrc -> ParamCount;
                  ++i
            )
        {
            temp =
                DM -> RaspredBallStrdPrc ->
                    Params -> Items[i] -> AsInteger;

            if (temp)
                CellValue (
                    temp,
                    kolon,
                    stroka_n
                );

            --kolon;
        }
        DM -> RaspredBallStrdPrc -> Unprepare ();
        DM -> RaspredBallStrdPrc -> Close ();
    }
    else                                                                        // для поступающих на 2-ый курс
    {
        if (fac == 1)                                                           // СИиЕ + МВС
        {
            DM -> RaspredBall12StrdPrc -> Close ();

            DM -> RaspredBall12StrdPrc ->
                ParamByName ("VID_EDU") -> AsSmallInt = ed;

            DM -> RaspredBall12StrdPrc ->
                ParamByName ("PRICE")   -> AsSmallInt = price;

            DM -> RaspredBall12StrdPrc -> Prepare ();
            DM -> RaspredBall12StrdPrc -> ExecProc ();


            int temp  = 0;                                                      // временная переменная
                kolon = 46;

            for ( int i = 2;                                                    // проходим по параметрм - диапазонам баллов
                      i < DM -> RaspredBall12StrdPrc -> ParamCount;
                      ++i
                )
            {
                temp =
                    DM -> RaspredBall12StrdPrc ->
                        Params -> Items[i] -> AsInteger;

                if (temp)
                    CellValue (
                        temp,
                        kolon,
                        stroka_n
                    );

                kolon--;
            }

            DM -> RaspredBall12StrdPrc -> Unprepare ();
            DM -> RaspredBall12StrdPrc -> Close ();

            CellValue (
                "Спортивно-педагогический факультет спортивных игр "    \
                "и единоборств\n\nСпортивно-педагогический факультет "  \
                "массовых видов спорта",
                1,
                14
            );
        }


        if (    fac == 3                                                        // ОФКиТ,ТиГ
             || fac == 4
           )
        {
            DM -> RaspredBall34StrdPrc -> Close ();

            DM -> RaspredBall34StrdPrc ->
                ParamByName ("VID_EDU") -> AsSmallInt = ed;

            DM -> RaspredBall34StrdPrc ->
                ParamByName ("N_FAC")   -> AsSmallInt = fac;

            DM -> RaspredBall34StrdPrc ->
                ParamByName ("PRICE")   -> AsSmallInt = price;

            DM -> RaspredBall34StrdPrc -> Prepare ();
            DM -> RaspredBall34StrdPrc -> ExecProc ();

            int temp  = 0;
                kolon = 46;

            for ( int i = 3;                                                    // проходим по параметрм - диапазонам баллов
                      i < DM -> RaspredBall34StrdPrc -> ParamCount;
                      ++i
                )
            {
                temp =
                    DM -> RaspredBall34StrdPrc ->
                        Params -> Items[i] -> AsInteger;

                if (temp)
                    CellValue (
                        temp,
                        kolon,
                        stroka_n
                    );

                --kolon;
            }

            DM -> RaspredBall34StrdPrc -> Unprepare ();
            DM -> RaspredBall34StrdPrc -> Close ();
        }
    }
}
void __fastcall TMainForm::Shapka_spisok (                                      // Шапка полного 'списока абитуриентов'
        int col_pred                                                            // количество предметов
    )
{
    BorderCell (
        1,                                                                      // 1-ая пустая ячейка только обрамляется
        7,
        1,
        2
    );


    CellValue (
        "№ п/п",
        2,                                                                      // 2-ая ячейка с № п/п
        7
    );
    BorderCell (
        2,
        7,
        1,
        2
    );
    CellOrient (
        2,
        7,
        90
    );


    CellValue (
        "Фамилия Имя Отчество",
        3,                                                                      // 3-яя ячейка с ФИО
        7
    );
    BorderCell (
        3,
        7,
        1,
        2
    );


    CellValue (
        "Разряд",
        4,                                                                      // 4-ая ячейка (добавлен разряд в 2004 г)
        7
    );
    BorderCell (
        4,
        7,
        1,
        2
    );

    DM -> TPredmet -> First ();                                                 // 5-ая - i-тая ячейка для предметов

    nom_pr = new int [col_pred];

    for ( int i =  1;
              i <= col_pred;
              ++i
        )
    {
        nom_pr [i - 1] = DM -> TPredmetN_PREDMET -> Value;

        if (     DM -> TPredmetTEXT_PREDMET -> Value
             ==  "Белорусский язык (русский язык) изложение"
           )
            CellValue (
                "Изложение",
                4 + i,
                7
            );
        else
            CellValue (
                DM -> TPredmetTEXT_PREDMET -> Value,
                4 + i,
                7
            );


        BorderCell (
            i + 4,
            7,
            1,
            2
        );
        CellOrient (
            4 + i,
            7,
            90
        );

        DM -> TPredmet -> Next ();
    }


    CellValue (
        "Средний балл",
        5 + col_pred,                                                           // 5 + i -- ячейка для подсчета суммы полученных баллов
        7
    );
    BorderCell (
        5 + col_pred,
        7,
        1,
        2
    );
    CellOrient (
        5 + col_pred,
        7,
        90
    );


    CellValue (
        "Сумма баллов",
        6 + col_pred,                                                           // 6 + i -- ячейка для подсчета суммы полученных баллов
        7
    );
    BorderCell (
        6 + col_pred,
        7,
        1,
        2
    );
    CellOrient (
        6 + col_pred,
        7,
        90
    );


    CellValue (
        "Примечание",
        7 + col_pred,                                                           // 7 + i -- ячейка для примечания,все преимущества при зачислении
        7
    );
    BorderCell (
        7 + col_pred,
        7,
        1,
        2
    );

    alignHVCells (                                                              // Шапка форматируется по центру
        1,
        6 + col_pred,
        7,
        3,
        2
    );
}
void __fastcall TMainForm::Shapka_spisok_Pol (
        AnsiString n_gr,
        String     pol
    )
{
    MergeCellCenter (                                                           // Форматирование 'факультета'
        1,
        7,
        2
    );
    CellValue (
        DM -> TFaculty ->
            Lookup (
                "N_FAC",
                nom_fac,
                "FAC"
            ),
        1,
        2
    );


    MergeCellCenter (                                                           // Форматирование 'вида обучения'
        1,
        7,
        4
    );
    CellValue (
        DM -> QSpisoc_Group_PolVID_EDU1 -> Value,
        1,
        4
    );


    MergeCellCenter (                                                           // Форматирование 'номера группы'
        1,
        7,
        5
    );
    CellValue (
        "Группа № " +
            n_gr    +
        " ("        +
            pol     +
        ")",
        1,
        5
    );


    BorderCell (                                                                // Формирование 'шапки таблицы' (1-ая пустая ячейка только обрамляется)
        1,
        7,
        1,
        2
    );


    CellValue (                                                                 // 2-ая ячейка с '№ п/п'
        "№ п/п",
        2,
        7
    );
    BorderCell (
        2,
        7,
        1,
        2
    );
    CellOrient (
        2,
        7,
        90
    );


    CellValue (                                                                 // 3-яя ячейка с 'ФИО'
        "Фамилия Имя Отчество",
        3,
        7
    );
    BorderCell (
        3,
        7,
        1,
        2
    );

    alignHVCells (                                                              // 'Шапка' форматируется по центру
        1,
        6,
        7,
        3,
        2
    );


    MergeCellCenter (                                                           // Форматирование 'специализации'
        1,
        7,
        8
    );
    CellValue (
        DM -> QSpisoc_Group_PolSPECIALIZ2 -> Value,
        1,
        8
    );
}
void __fastcall TMainForm::SpeedButton1Click (TObject * Sender)
{
    AnsiString
        InputString = "";

    UnicodeString
        Str1 = "Смена факультета",
        Str2 = "Введите новый факультет",
        Str3 = "";

    if (    InputQuery (
                Str1,
                Str2,
                Str3
            )
       )
    {
        try
        {
            // nom_fac = InputString.ToInt ();
            nom_fac = Str3.ToInt ();

            fac1 =
                DM -> TFaculty ->
                    Lookup (
                        "N_FAC",
                        nom_fac,
                        "FAC1"
                    );

            FormActivate (this);
        }
        catch (...)
        {
            ShowMessage (
                "Получено исключение при смене факультета!\n"       \
                "Проверьте код в MainUnit -> SpeedButton1Click ()"
            );
        }
    }
}
void __fastcall TMainForm::SpeedButton2Click (TObject * Sender)                 // Обновить 'Максимальный номер дела'
{
    DM -> QGroup_Count -> Close ();
    DM -> QGroup_Count ->
        ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DM -> QGroup_Count -> Open ();



    DM -> QMax_Nom_Dela -> Close ();
    DM -> QMax_Nom_Dela ->
        ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DM -> QMax_Nom_Dela -> Open ();


    AbiturForm -> max_nom_dela ();
}
void __fastcall TMainForm::SpeedButton3Click (TObject * Sender)
{
    AnsiString
        InputString = "";

    int
        fac,
        s,
        v;

    UnicodeString
        Str1 = "Факультет",
        Str2 = "Введите факультет",
        Str3 = "";

    if (    InputQuery (
                Str1,
                Str2,
                Str3
            )
        )
    {
        try
        {
            fac = Str3.ToInt ();

            InputString = "";

            UnicodeString
                Str1 = "Вид обучения",
                Str2 = "Введите вид обучения",
                Str3 = "";

            if (    InputQuery (
                        Str1,
                        Str2,
                        Str3
                    )
               )
            {
                try
                {
                    v = Str3.ToInt ();

                    InputString = "";

                    UnicodeString
                        Str1 = "Статус абитуриента",
                        Str2 = "Введите статус абитуриента",
                        Str3 = "";

                    if (    InputQuery (
                                Str1,
                                Str2,
                                Str3
                            )
                       )
                    {
                        try
                        {
                            s = Str3.ToInt ();

                            Zachisl_Sertificat (
                                fac,
                                v,
                                s,
                                false
                            );
                        }
                        catch (...)
                        {
                            return
                                ShowMessage (
                                    "Получено исключение при создание " \
                                    "отчета!\nСмотри MainUnit -> "      \
                                    "SpeedButton3Click () -> "          \
                                    "Zachisl_Sertificat ()"
                                );
                        }
                    }
                }
                catch (...)
                {
                    return
                        ShowMessage (
                            "Получено исключение при передаче статуса " \
                            "абитуриента!\nСмотри MainUnit -> "         \
                            "SpeedButton3Click ()"
                        );
                }
            }
        }
        catch (...)
        {
            return
                ShowMessage (
                    "Получено исключение при передаче вида обучения!\n" \
                    "Смотри MainUnit -> SpeedButton3Click ()"
                );
        }
    }
}
void __fastcall TMainForm::SpeedButton4Click (TObject * Sender)                 // сертификаты всех
{
    Zachisl_Sertificat (
        0,
        0,
        5,
        true
    );
}
void __fastcall TMainForm::Spisok_Pol (
        String  pol,
        Variant Workbook
    )
{
    DM -> QSpisoc_Group_Pol -> Close ();
    DM -> QSpisoc_Group_Pol ->
        ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DM -> QSpisoc_Group_Pol ->
        ParamByName ("POL")   -> Value     = pol;
    DM -> QSpisoc_Group_Pol -> Open ();


    AnsiString n_gr = DM -> QSpisoc_Group_PolNOM_GROUP -> Value;

    int        j    = 1;                                                        // порядковый номер
    int        rec  = DM -> QSpisoc_Group_Pol -> RecordCount;                   // количество человек в группе


    if (n_gr == "")                                                             // begin формирования списка
        return;

    Shapka_spisok_Pol (
        n_gr,
        pol
    );


    int nom_stroka = 9;                                                         // номер строки
    int spec       = DM -> QSpisoc_Group_PolN_SPECIALIZ -> Value;


    Data_spisok_Pol (
        nom_stroka,
        j
    );

    ++nom_stroka;


    for ( int i =  2;                                                           // цикл по абитуриентам (с учетом номера группы и специализации)
              i <= rec;
              ++i
        )
    {
        DM -> QSpisoc_Group_Pol -> Next ();

        if (DM -> QSpisoc_Group_PolNOM_GROUP -> Value == n_gr)
        {
            if (DM -> QSpisoc_Group_PolN_SPECIALIZ -> Value == spec)
            {
                Data_spisok_Pol (
                    nom_stroka,
                    ++j
                );

                ++nom_stroka;
            }
            else
            {
                spec =
                    DM -> QSpisoc_Group_PolN_SPECIALIZ -> Value;


                MergeCellCenter (                                               // Форматирование ячейки для занесения специализации
                    1,
                    7,
                    nom_stroka
                );
                CellValue (
                    DM -> QSpisoc_Group_PolSPECIALIZ2 -> Value,
                    1,
                    nom_stroka++
                );

                j = 1;

                Data_spisok_Pol (
                    nom_stroka,
                    j
                );

                ++nom_stroka;
            }
        }
        else
        {
            for ( int i =  1;                                                   // Автоподбор ширины столбца
                      i <= 7;
                      ++i
                )
                AutoFitColumn (
                    Sheet,
                    i
                );

            n_gr =
                DM -> QSpisoc_Group_PolNOM_GROUP   -> Value;

            spec =
                DM -> QSpisoc_Group_PolN_SPECIALIZ -> Value;

            Sheet = NewSheet1 (Workbook);

            NameSheet1 (
                Sheet,
                    n_gr    +
                " ("        +
                    pol     +
                ")"
            );
            SelectSheet (
                Workbook,
                    n_gr    +
                " ("        +
                    pol     +
                ")"
            );

            Shapka_spisok_Pol (
                n_gr,
                pol
            );

            nom_stroka = 9;
            j          = 1;

            Data_spisok_Pol (
                nom_stroka,
                j
            );

            ++nom_stroka;
        }
    }

    for ( int i =  1;
              i <= 7;
              ++i
        )
        AutoFitColumn (
            Sheet,
            i
        );


    if (nom_pr)
        delete [] nom_pr;
}
int __fastcall TMainForm::Svod_ved (                                            // Сводная ведомость
        int nom_str,                                                            // счетчик строк
        int konk,                                                               // конкурс, параметр для определения какую процедуру использовать
        int vid_edu,                                                            // вид обучения
        int rec_pred,                                                           // количество предметов
        int price,                                                              // условия финансирования 0-бюджет 1-за оплату
        int pr_ved                                                              // 0 - полный срок, 1 - сокр. СИиЕ + МВС, 2 - 2 ВО 2 курс
    )
{
    AnsiString
        Addres       = "",                                                      // домашний адрес
        date_r       = "",                                                      // дата рождения
        dogovor      = "",                                                      // обучение за оплату
        Fio          = "",                                                      // фамилия Имя Отчество
        konk_str     = "",                                                      // строка для вывода конкурса
        Mid_ball     = "",                                                      // средний балл аттестата
        n_delo       = "",                                                      // номер дела
        Name_mid     = "",                                                      // наименование образования среднего
        Name_spec    = "",                                                      // наименование образования специального
        pol          = "",                                                      // пол
        shapka       = "",                                                      // шапка (тип конкурса)
        Sport        = "",                                                      // спортивный разряд
        Stag         = "",                                                      // общий стаж
        Stag_sp      = "",                                                      // стаж по специальности
        Sum_ball     = "",                                                      // сумма баллов на экзаменах
        When_mid     = "",                                                      // когда закончил  образование среднее
        When_spec    = "";                                                      // когда закончил образование специальное

    double
        Sum_ball_Fiz = 0;

    int
        nomer_ab,                                                               // номер абитуриента
        rec          = 0;                                                       // количество записей


    if (price)
        dogovor = " на платной основе";


    switch (pr_ved)
    {
        case 0:                                                                 // полный срок
                qq =
                    DMVed -> QKonkurs;
            break;
        case 1:                                                                 // сокращёнка СИиЕ + МВС
                if (    nom_fac == 1
                     || nom_fac == 2
                   )
                    qq = DMVed -> QKonkurs12;
                else
                    qq = DMVed -> QKonkurs34;
            break;
        case 2:                                                                 // полный срок
                qq = DMVed -> QKonkurs2V;
            break;
    }


    switch (konk)
    {
        case 0:                                                                 // общий конкурс
                shapka =
                    "Подлежат зачислению по общему конкурсу"                +
                        dogovor;
            break;
        case 1:                                                                 // БВИ
                shapka =
                    "Подлежат зачислению без вступительный испытаний"       +
                        dogovor;
            break;
        case 2:                                                                 // второй курс
                shapka =
                    "Подлежат зачислению вне конкурса"                      +
                        dogovor;
            break;
        case 3:                                                                 // вне конкурса
                shapka =
                    "Подлежат зачислению на условиях целевой подготовки"    +
                        dogovor;
            break;
    }


    CellValue (                                                                 // занесение шапки
        shapka,
        1,
        nom_str
    );
    MergeCellCenter (
        1,
        17,
        nom_str++
    );


    rec = qq -> RecordCount;

    int n_spisok = 1;


    for ( int k = 0;                                                            // цикл по абитуриентам
              k < rec;
              ++k
        )
    {
        nomer_ab =                                                              // номер абитуриента
            qq -> FieldByName ("out_nomer_ab") -> Value;

        Fio = ReturnField ("out_FIO");                                          // Фамилия Имя  Отчество

        if (pr_ved == 1)                                                        // сокращёнка СИиЕ + МВС
        {
            DM -> SpecializNameQr -> Close ();
            DM -> SpecializNameQr ->
                ParamByName ("n_specializ") -> AsSmallInt =
                        qq -> FieldByName ("OUT_N_SPECIALIZ") -> Value;
            DM -> SpecializNameQr -> Open ();


            Fio +=
                "\n ("                                                      +
                    DM -> SpecializNameQrSPECIAL -> AsString.LowerCase ()   +
                ")";

            DM -> SpecializNameQr -> Close ();
        }

        n_delo    =                                                             // номер дела
            "'"                                             +
            DM -> NumDelaString (
                vid_edu,
                qq -> FieldByName ("out_term_edu") -> Value,
                price,
                qq -> FieldByName ("out_n_dela")   -> Value
            );

        date_r    = ReturnField ("out_date_r");                                 // дата рождения

        pol       = ReturnField ("out_pol");                                    // пол

        Name_mid  = ReturnField ("out_name_edu_middle");                        // наименование образования среднего

        Name_spec = ReturnField ("out_name_edu_spec");                          // наименование образования специального

        When_mid  = ReturnField ("out_when_edu_middle");                        // когда закончил  образование среднее

        When_spec = ReturnField ("out_when_edu_spec");                          // когда закончил образование специальное

        Stag      = ReturnField ("out_stag");                                   // общий стаж

        Stag_sp   = ReturnField ("out_stag_spec");                              // стаж по специальности

        Sport     = ReturnField ("out_sport_category");                         // спортивный разряд

        Sum_ball  = ReturnField ("out_sum_ball");                               // сумма баллов на экзаменах


        if (    nom_fac == 4
             && konk    == 3
           )
            Mid_ball = ReturnField_IT ("out_middle_ball");                      // средний балл аттестата
        else
            Mid_ball = ReturnField ("out_middle_ball");                         // средний балл аттестата


        Addres    = ReturnField ("out_address_before");                         // домашний адрес


        CellValue (
            AnsiString (n_spisok++),
            1,
            nom_str
        );
        CellValue (
            Fio,
            2,
            nom_str
        );
        CellValue (
            n_delo,
            3,
            nom_str
        );
        CellValue (
            date_r,
            4,
            nom_str
        );
        CellValue (
            pol,
            5,
            nom_str
        );


        AnsiString edu = "";                                                    // для формирования строки в поле образование

        if (Name_mid != "")
            edu +=
                    Name_mid    +
                " "             +
                    When_mid;

        if (Name_spec != "")
            edu +=
                " "             +
                    Name_spec   +
                " "             +
                    When_spec;


        CellValue (
            edu,
            6,
            nom_str
        );
        CellValue (
            Stag_sp,
            7,
            nom_str
        );
        CellValue (
            Sport,
            8,
            nom_str
        );


        DMVed -> QPredmet_Ball -> Close ();                                     // предметы

        DMVed -> QPredmet_Ball ->
            ParamByName ("NOM_AB") -> Value = nomer_ab;

        DMVed -> QPredmet_Ball -> Open ();


        int start_col = 9;

        for ( int i = 0;
                  i < rec_pred;
                  ++i
            )
        {
            DMVed -> QPredmet_Ball -> First ();

            for ( int j = 0;
                      j < 8;
                      ++j
                )
            {
                if (    mas_pr[i]
                     == DMVed -> QPredmet_BallOUT_TEXT_PREDMET -> Value
                   )
                {
                    if (DMVed -> QPredmet_BallOUT_BALL -> Value)
                    {
                        if (    nom_fac == 1
                             || nom_fac == 2
                             || nom_fac == 3
                             || nom_fac == 4
                           )
                        {
                            Variant Ce1 =
                                SelectCell (
                                    start_col,
                                    nom_str
                                );
                            SheetFormat (
                                Ce1,
                                "0,0"                                           // 0.0 в самом Excel пишет такой формат
                            );
                        }

                        CellValue (
                            DMVed -> QPredmet_BallOUT_BALL -> Value,
                            start_col,
                            nom_str
                        );
                    }
                    break;
                }
                else
                    if ( ! DMVed -> QPredmet_Ball -> Eof)
                        DMVed -> QPredmet_Ball -> Next ();
                    else
                        break;
            }

            ++start_col;
        }


        if (    nom_fac == 1                                                    // Для всех факльтетов и (Тиг с ВК?)
             || nom_fac == 2
             || nom_fac == 3
             || nom_fac == 4
             && konk    == 3
           )
        {
            Variant Ce1 =
                SelectCell (
                    12,
                    nom_str
                );
            SheetFormat (
                Ce1,
                "0,0"                                                           // 0.0 в самом Excel пишет такой формат
            );


            Ce1 =
                SelectCell (
                    13,
                    nom_str
                );
            SheetFormat (
                Ce1,
                "0,0"
            );
        }


        CellValue (
            Mid_ball,                                                           // Средний балл
            12,
            nom_str
        );


        if (Sum_ball == "")
            Sum_ball = "0";


        CellFormula (                                                           // сумма баллов - высчитывается (=СУММ(I1+J1+K1+L1))
            "=СУММ(I"                   +
                AnsiString (nom_str)    +
            "+J"                        +
                AnsiString (nom_str)    +
            "+K"                        +
                AnsiString (nom_str)    +
            "+L"                        +
                AnsiString (nom_str)    +
            ")",
            13,
            nom_str
        );


        CellValue (
            Addres,                                                             // адрес
            14,
            nom_str
        );


        switch (konk)
        {
            case 0:
                    CellValue (
                        "Общий",
                        15,
                        nom_str
                    );
                break;
            case 1:
                    CellValue (
                        "БВИ",
                        15,
                        nom_str
                    );
                break;
            case 2:
                    CellValue (
                        "ВК",
                        15,
                        nom_str
                    );
                break;
            case 3:
                    CellValue (
                        "ЦК",
                        15,
                        nom_str
                    );
                break;
        }



        S2 = "";                                                                // 'ПРИВЕЛЕГИИ' все привилегии и преимущества

        AnsiString
            Stat_ab_vk = "",                                                    // Вне конкурса
            Stat_ab_pr = "",                                                    // Привилегии
            Stat_ab_wo = "";                                                    // Без экзаменов

        // int        n_ab;                                                        // номер абитуриента


        switch (konk)
        {
            case 1:
                    if (S2 == "")
                        S2 = "БВИ";
                    else
                        S2 += ", БВИ";
                break;
            case 2:
                    if (S2 == "")
                        S2 = "ВК";
                    else
                        S2 += ", ВК";
                break;
            case 3:
                    if (S2 == "")
                        S2 = "ЦК";
                    else
                        S2 += ", ЦК";
                break;
        }


        switch ((int)qq -> FieldByName ("out_term_edu") -> Value)
        {
            case 1:
                    if (S2 == "")
                        if (    nom_fac == 3
                             && vid_edu == 1
                           )
                            S2 = "ССО 3к.";
                        else
                            S2 = "ССО 2к.";
                    else
                        if (    nom_fac == 3
                             && vid_edu == 1
                           )
                            S2 += ", ССО 3к.";
                        else
                            S2 += ", ССО 2к.";
                break;
            case 2:
                    if (S2 == "")
                        S2 = "ВО 1к.";
                    else
                        S2 += ", ВО 1к.";
                break;
            case 3:
                    if (S2 == "")
                        S2 = "ВО 2к.";
                    else
                        S2 += ", ВО 2к.";
                break;
        }


        if (qq -> FieldByName ("out_n_ck") -> Value > -1)                       // ЦК
        {
            if (S2 == "")
                S2 = "Целевой договор (";
            else
                S2 += ", Целевой договор (";


            DM -> RegionNameQr -> Close ();
            DM -> RegionNameQr ->
                ParamByName ("n_centre") -> AsSmallInt =
                        qq -> FieldByName ("out_n_ck") -> Value;
            DM -> RegionNameQr -> Open ();


            Variant ck =
                DM -> RegionNameQrCENTRE -> Value;


            if (ck.IsNull ())
                S2 += "????";
            else
                S2 += ck.AsType (varString);


            S2 += AnsiString (" р-н) ");

            DM -> RegionNameQr -> Close ();
        }


        int
            pr_bvi = 0,
            pr_vk  = 0;

        DMStat -> LastLogQr -> Close ();
        DMStat -> LastLogQr ->
            ParamByName ("nomer_ab") -> AsInteger =
                    nomer_ab;
        DMStat -> LastLogQr -> Open ();


        DM -> SelPrivLogQr -> Close ();
        DM -> SelPrivLogQr ->
            ParamByName ("id_log") -> AsInteger =
                    DMStat -> LastLogQrID_LOG -> Value;
        DM -> SelPrivLogQr -> Open ();


        DMStat -> LastLogQr -> Close ();

        while ( ! DM -> SelPrivLogQr -> Eof)
        {
            switch (DM -> SelPrivLogQrN_PRIV -> Value)
            {
                case 0:                                                         // БВИ
                        DM -> WithOutTestLogQr -> Close ();
                        DM -> WithOutTestLogQr ->
                            ParamByName ("sel_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrSEL_PRIV -> Value;
                        DM -> WithOutTestLogQr ->
                            ParamByName ("dat_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrDAT_PRIV -> Value;
                        DM -> WithOutTestLogQr -> Open ();

                        while ( ! DM -> WithOutTestLogQr -> Eof)
                        {
                            if (    pr_bvi == 0
                                 && konk   == 4
                               )
                            {
                                if (S2 != "")
                                    S2 = "БВИ";
                                else
                                    S2 += ", БВИ";
                            }

                            pr_bvi = 1;

                            if (S2 != "")
                                S2 += ", ";

                            S2 +=
                                DM -> WithOutTestLogQrSHORT_NAME -> Value;

                            if (    DM -> WithOutTestLogQrSHORT_NAME_1 -> Value
                                 != "да"
                               )
                                S2 +=
                                    " - "                                       +
                                    DM -> WithOutTestLogQrSHORT_NAME_1 -> Value;

                            DM -> WithOutTestLogQr -> Next ();
                        }

                        DM -> WithOutTestLogQr -> Close ();
                    break;
                case 1:                                                         // ВК
                        DM -> OutTestQr -> Close ();
                        DM -> OutTestQr ->
                            ParamByName ("sel_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrSEL_PRIV -> Value;
                        DM -> OutTestQr ->
                            ParamByName ("dat_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrDAT_PRIV -> Value;
                        DM -> OutTestQr -> Open ();

                        while ( ! DM -> OutTestQr -> Eof)
                        {
                            if (    pr_vk == 0
                                 && konk  == 4
                               )
                            {
                                if (S2 != "")
                                    S2 = "ВК";
                                else
                                    S2 += ", ВК";
                            }

                            pr_vk = 1;

                            if (S2 != "")
                                S2 += ",";

                            S2 +=
                                DM -> OutTestQrSHORT_NAME -> Value;

                            if (    DM -> OutTestQrSHORT_NAME_1 -> Value
                                 != "да"
                               )
                                S2 +=
                                    " - "                                   +
                                    DM -> OutTestQrSHORT_NAME_1 -> Value;

                            DM -> OutTestQr -> Next ();
                        }

                        DM -> OutTestQr -> Close ();

                        pr_vk = 1;
                    break;
                case 2:                                                         // Другие
                        DM -> OtherPrivQr -> Close ();
                        DM -> OtherPrivQr ->
                            ParamByName ("sel_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrSEL_PRIV -> Value;
                        DM -> OtherPrivQr -> Open ();

                        while ( ! DM -> OtherPrivQr -> Eof)
                        {
                            if (S2 != "")
                                S2 += ", ";

                            S2 +=
                                DM -> OtherPrivQrSHORT_NAME -> Value;

                            DM -> OtherPrivQr -> Next ();
                        }

                        DM -> OtherPrivQr -> Close ();
                    break;
            }
            DM -> SelPrivLogQr -> Next ();
        }

        DM -> SelPrivLogQr -> Close ();


        // Priv_Str (konk);

        CellValue (
            S2,
            16,
            nom_str
        );
        AutoFitRow (                                                            // SET ROW HEIGHT AND WIDTH
            Sheet,                                                              // sheet
            nom_str                                                             // nom_row
        );

        ++nom_str;

        if (konk != 2)                                                          // не РУОР
            Clear_mas (nomer_ab);


        qq -> Next ();                                                          // Переход к новой записи
    }

    return
        nom_str++;
}
void __fastcall TMainForm::Zachisl_Sertificat (                                 // Сертификаты
        int  f,
        int  v,
        int  s,
        bool all                                                                // true - все зачисленные
    )
{
    DMStat -> QZachisl_Sertificat -> Close ();

    if (all)
    {
        DMStat -> QZachisl_Sertificat -> SQL -> Clear ();
        DMStat -> QZachisl_Sertificat ->
            SQL ->
                Add (
                    " SELECT"                                                  \
                    "     abitura.nomer_ab,"                                   \
                    "     abitura.konkurs,"                                    \
                    "     abitura.fam,"                                        \
                    "     abitura.name,"                                       \
                    "     abitura.otch,"                                       \
                    "     abitura.pasport,"                                    \
                    "     abitura.n_found,"                                    \
                    "     sertificat.n_predmet,"                               \
                    "     sertificat.rus_bel,"                                 \
                    "     predmet.text_predmet,"                               \
                    "     sertificat.seria_s,"                                 \
                    "     sertificat.nomer_s,"                                 \
                    "     sertificat.balls"                                    \
                    " FROM"                                                    \
                    "     abitura"                                             \
                    "         LEFT JOIN"                                       \
                    "             sertificat"                                  \
                    "         ON"                                              \
                    "             sertificat.nomer_ab  = abitura.nomer_ab"     \
                    "         LEFT JOIN"                                       \
                    "             predmet"                                     \
                    "         ON"                                              \
                    "             predmet.n_predmet = sertificat.n_predmet"    \
                    " WHERE"                                                   \
                    "         abitura.status  =  5"                            \
                    "     AND"                                                 \
                    "         abitura.vid_edu IN (0, 1)"                       \
                    "     AND"                                                 \
                    "         abitura.n_fac   IN (1, 2, 3, 4)"                 \
                    " ORDER BY"                                                \
                    "     abitura.fam,"                                        \
                    "     abitura.name,"                                       \
                    "     abitura.otch"
                );
    }
    else
    {
        DMStat -> QZachisl_Sertificat ->
            ParamByName ("f") -> AsSmallInt = f;
        DMStat -> QZachisl_Sertificat ->
            ParamByName ("v") -> AsSmallInt = v;
        DMStat -> QZachisl_Sertificat ->
            ParamByName ("s") -> AsSmallInt = s;
    }

    DMStat -> QZachisl_Sertificat -> Open ();

    int rec =
        DMStat -> QZachisl_Sertificat -> RecordCount;


    if ( ! rec)
        return
            ShowMessage (
                "Нет таких абитуриентов"
            );


    int
        n_ab = 0,
        str  = 5;


    ExcelApplication = Variant::CreateObject ("Excel.Application");             // создание объекта и открытие созданного файла

    Variant Workbook = NewBook (ExcelApplication);

    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );

    DisplayAlert (ExcelApplication);
    OVisible (ExcelApplication);


    AnsiString zagolovok = "Информация по ";                                    // Заголовок

    switch (s)
    {
        case 0:
                zagolovok += "подавшим документы ";
            break;
        case 1:
                zagolovok += "недопущенным к экзаменам ";
            break;
        case 2:
                zagolovok += "не выдержавшим экзамены ";
            break;
        case 3:
                zagolovok += "неявившимся на экзамен ";
            break;
        case 4:
                zagolovok += "забравшим документы во время экзамена ";
            break;
        case 5:
                zagolovok += " зачисленным ";
            break;
    }

    zagolovok +=
        "в УО БГУФК в "             +
            Admissions::TIME::YEAR  +
        " году";

    CellValue (
        zagolovok,
        1,
        1
    );

    if ( ! all)
    {
        zagolovok =
            DM -> TFaculty ->
                Lookup (
                    "N_FAC",
                    f,
                    "FAC"
                );


        CellValue (
            zagolovok,
            1,
            2
        );


        if (v)
            CellValue (
                "заочная форма получения образования",
                1,
                3
            );
        else
            CellValue (
                "дневная форма получения образования",
                1,
                3
            );
    }


    CellValue (                                                                 // Шапка
        "Фамилия",
        1,
        str
    );
    CellValue (
        "Имя",
        2,
        str
    );
    CellValue (
        "Отчество",
        3,
        str
    );
    CellValue (
        "Серия паспорта",
        4,
        str
    );
    CellValue (
        "№ паспорта",
        5,
        str
    );
    CellValue (
        "Балл Рус.яз (Бел.яз)",
        6,
        str
    );
    CellValue (
        "Балл Биология",
        7,
        str
    );
    CellValue (
        "Балл Математика",
        8,
        str
    );
    CellValue (
        "Балл География",
        9,
        str
    );
    CellValue (
        "Конкурс",
        10,
        str
    );
    CellValue (
        "Примечание",
        11,
        str
    );


    for ( int i = 0;
              i < rec;
              ++i
        )
    {
        if (n_ab != DMStat -> QZachisl_SertificatNOMER_AB -> Value)             // 1 ФИО
        {
            ++str;

            CellValue (
                DMStat -> QZachisl_SertificatFAM  -> Value,
                1,
                str
            );
            CellValue (
                DMStat -> QZachisl_SertificatNAME -> Value,
                2,
                str
            );
            CellValue (
                DMStat -> QZachisl_SertificatOTCH -> Value,
                3,
                str
            );

            n_ab = DMStat -> QZachisl_SertificatNOMER_AB -> Value;
        }


        AnsiString pasp =                                                       // 4 и 5 Паспорт
            DMStat -> QZachisl_SertificatPASPORT -> Value.Trim ();

        Variant Ce1 =
            SelectCell (
                4,
                str
            );
        SheetFormat (
            Ce1,
            "@"
        );
        CellValue (                                                             // Серия паспорта
            pasp.SubString (
                1,
                2
            ),
            4,
            str
        );


        Ce1 =
            SelectCell (
                5,
                str
            );
        SheetFormat (
                Ce1,
                "@"
            );
        CellValue (                                                             // Номер паспорта
            pasp.SubString (
                3,
                pasp.Length () - 2
            ),
            5,
            str
        );


        int stolb;

        switch (DMStat -> QZachisl_SertificatRUS_BEL -> Value)
        {
            case 0:
                    stolb = 6;                                                  // 6 - Рус
                break;
            case 1:
                    stolb = 6;                                                  // 6 - Бел
                break;
            case 2:
                    stolb = 7;                                                  // 7 - Биол
                break;
            case 3:
                    stolb = 8;                                                  // 8 - Матем
                break;
            case 4:
                    stolb = 9;                                                  // 9 - Геогр
                break;
        }

        int b = DMStat -> QZachisl_SertificatBALLS -> Value;

        if (b)
            CellValue (
                b,
                stolb,
                str
            );

        AnsiString k = "";                                                      // Конкурс

        switch (DMStat -> QZachisl_SertificatKONKURS -> Value)
        {
            case 0:
                    k = "Общий";
                break;
            case 1:
                    k = "Целевой договор";
                break;
            case 2:
                    k = "Сокращенный срок обучения";
                break;
            case 3:
                    k = "Вне конкурса";
                break;
            case 4:
                    k = "Без экзаменов";
                break;
            case 5:
                    k = "Иностранные граждане";
                break;
        }

        CellValue (
            k,
            10,
            str
        );

        Variant prim =                                                          // Примечание
            DM -> TFoundation ->
                Lookup (
                    "N_FOUND",
                    DMStat -> QZachisl_SertificatN_FOUND -> Value,
                    "VID_FOUND"
                );

        if ( ! prim.IsNull ())
            CellValue (
                prim,
                11,
                str
            );

        DMStat -> QZachisl_Sertificat -> Next ();
    }


    for ( int i =  1;                                                           // ---обрамление оставшихся ячеек
              i <= 11;
              ++i
        )
        for ( int j =  5;
                  j <= str;
                  ++j
            )
            BorderCell (
                i,
                j,
                1,
                2
            );


    for ( int i =  1;                                                           // Автоподбор ширины столбца
              i <= 11;
              ++i
        )
        AutoFitColumn (
            Sheet,
            i
        );


    ExcelApplication.Clear ();
}
