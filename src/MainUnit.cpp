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


AnsiString * mas_pr;                                                            // ������ ��������� ��� ������� ����������

AnsiString   S1,                                                                // ���������� ��� ������������ ������ ���������� S1-1 �������  ,
             S2,                                                                // S2-��������� �������
             S3;                                                                // S3-������

int        * mas_all;                                                           // ������ ���� ������������ �� ������������� �������� �� ����������
int        * mas_spec_str[2];                                                   // ������ ��� �������� ������ ������������� � ������,� ������� ��� ���������
int        * nom_pr;                                                            // ������ ��� ��������� ������� ���������

int          col_rec,
             konk,                                                              // (competitionType) ��� ����������� ��������
             nom_row,                                                           // (rowCounter) ������� �����
             rec_q_all,                                                         // (amountItemsInAllArray) ���������� ��� ����������� ���-�� ��������� � ������� all
             spec;                                                              // (specializationCode) ����������� ������ �������������

TFDQuery   * qq;                                                                // ���������� ��� ����������� Query

Variant      ExApp1,                                                            // ���������� ��� Excel
             ExcelApplication,
             startMerging,
             endMerging,
             selectedRange,
             Sheet,
             V;                                                                 // ��� Lookup



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
        //            err_access_denied = "������� ����";
        //        break;
        //    case Subject::BEL:
        //        //return
        //            err_access_denied = "����������� ����";
        //        break;
        //    default:
        //        //return
        //            err_access_denied = DM -> QSertificat_ex_listTEXT_PREDMET -> Value;
        //}
    ShowMessage (
        //"�������� ��� ������������ " \
        //"��� ������ "
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


void __fastcall TMainForm::AllCount_spec (                                      // ������ ���������� ������������ �� ������������� �� �����
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
        spec =                                                                  // ����� ����������� �������������
            DM -> QPlan_Priem_Konk_All_ParamN_SPECIALIZ -> Value;

        CellValue (                                                             // ����� ������� �������� ����������� �������������
            DM -> QPlan_Priem_Konk_All_ParamSPECIALIZ2 -> Value,
            column,
            nom_row
        );
        CellValue (                                                             // ����� ������ ���������� ���� �� ������������� �� �����
            DM -> QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value,
            column + 1,
            nom_row
        );
    }
}
void __fastcall TMainForm::CellValue_Ball (                                     // ��������� ���� ������ �� �k������� ��� ������ �����������
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
                    "0,0"                                                       // 0.0 � ����� Excel ����� ����� ������
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
    int cel_kol;                                                                // ���-�� ��������� �� �����
    int c;
    int q;

    for ( int i =  1;                                                           // '���� ������' ���������� �� ����� ������
              i <= col_rec;
              ++i
        )
    {
        if (DM -> QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value != 0)
        {
            AllCount_spec (i);                                                  // �������� ���������� ������������ (�� ������������� �� �����)

            if (    konk_place == 1
                 && (    nom_fac == 1
                      || nom_fac == 2
                    )
               )
                CellValue (                                                     // ���������� ���� � ��� ����� �������� ����������� �������������
                    "���������-�������������� ������������ "        \
                    "(���������� ������ � ��������� ���� ������)",
                    1,
                    nom_row
                );


            if (    konk_place == 1
                 && konk_place == 2
                 && nom_fac    == 3
               )
                CellValue (                                                     // ���������� ����� ����� �������� ����������� �������������
                    "���������� �������� (������������)",
                    1,
                    nom_row
                );


            if (    konk_place == 1
                 && nom_fac    == 4
               )
                CellValue (                                                     // ��� ���������� ����� ����� �������� ����������� �������������
                    "������ � ��������������",
                    1,
                    nom_row
                );


            if (konk_place == 0)                                                // konk_place - ������� � �����
                konk = 0;                                                       // ��� ����������� �� 1-�� ���� (t_abitura.konkurs)
            else
                konk = 2;                                                       // ��� ����������� �� 2-�� ���� (t_abitura.konkurs)


            if (konk_place == 0)                                                // ������ ����
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


                while ( ! DM -> Stat3hAll1Qr -> Eof)                            // ���������� ��������
                {
                    switch (DM -> Stat3hAll1QrKONKURS -> Value)
                    {
                        case 0:                                                 // �����
                                c = DM -> Stat3hAll1QrCOUNT -> Value;

                                if (DM -> Stat3hAll1QrCOUNT -> Value)
                                    CellValue (
                                        c,
                                        8,
                                        nom_row
                                    );
                            break;
                        case 1:                                                 // ���
                                c = DM -> Stat3hAll1QrCOUNT -> Value;

                                if (DM -> Stat3hAll1QrCOUNT -> Value)
                                    CellValue (
                                        c,
                                        6,
                                        nom_row
                                    );
                            break;
                        case 2:                                                 // ��
                                c = DM -> Stat3hAll1QrCOUNT -> Value;

                                if (DM -> Stat3hAll1QrCOUNT -> Value)
                                    CellValue (
                                        c,
                                        7,
                                        nom_row
                                    );
                            break;
                        case 3:                                                 // ��
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
            else                                                                // �����������
            {
                if (nom_fac != 1)                                               // ��� �� ����
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
                            case 0:                                             // �����
                                    q = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (DM -> Stat3hAll2QrCOUNT -> Value)
                                        CellValue (
                                            q,
                                            8,
                                            nom_row
                                        );
                                break;
                            case 1:                                             // ���
                                    q = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (DM -> Stat3hAll2QrCOUNT -> Value)
                                        CellValue (
                                            q,
                                            6,
                                            nom_row
                                        );
                                break;
                            case 2:                                             // ��
                                    q = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (DM -> Stat3hAll2QrCOUNT -> Value)
                                        CellValue (
                                            q,
                                            7,
                                            nom_row
                                        );
                                break;
                            case 3:                                             // ��
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
                else                                                            // � ���� ���������� + ���
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
                            case 0:                                             // �����
                                    s1 = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s1)
                                        CellValue (
                                            s1,
                                            8,
                                            nom_row
                                        );
                                break;
                            case 1:                                             // ���
                                    s2 = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s2)
                                        CellValue (
                                            s2,
                                            6,
                                            nom_row
                                        );
                                break;
                            case 2:                                             // ��
                                    s3 = DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s3)
                                        CellValue (
                                            s3,
                                            7,
                                            nom_row
                                        );
                                break;
                            case 3:                                             // ��
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
                            case 0:                                             // �����
                                    s1 =
                                    s1 + DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s1)
                                        CellValue (
                                            s1,
                                            8,
                                            nom_row
                                        );
                                break;
                            case 1:                                             // ���
                                    s2 =
                                    s2 + DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s2)
                                        CellValue (
                                            s2,
                                            6,
                                            nom_row
                                        );
                                break;
                            case 2:                                             // ��
                                    s3 =
                                    s3 + DM -> Stat3hAll2QrCOUNT -> Value;

                                    if (s3)
                                        CellValue (
                                            s3,
                                            7,
                                            nom_row
                                        );
                                break;
                            case 3:                                             // ��
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


            DM -> QCK_Kol_Plan -> Close ();                                     // ���� ���������
            DM -> QCK_Kol_Plan ->
                ParamByName ("N_SPECIALIZ") -> AsInteger = spec;
            DM -> QCK_Kol_Plan -> Open ();


            if (    edu        == 0                                             // ��������� ��������� ����� ���������
                 && konk_place == 0                                             // ������ ��� ��������, 1-�� ����,������
                 && price      == 0
               )
            {
                cel_kol = DM -> QCK_Kol_PlanKOL_PLACE -> Value;                 // ������ �� ���������� ��������� �� �����

                if (cel_kol)
                    CellValue (
                        cel_kol,
                        3,
                        nom_row
                    );
            }


            Run_ProcBall (                                                      // ��������� ������������� ��������� �� ������
                nom_fac,
                edu,
                konk,
                price,
                9,
                nom_row
            );


            CellFormula (                                                       // ������ ������ ����� �������� ��������� �� ������������� (=����(E1:H1))
                "=����(E"                   +
                    AnsiString (nom_row)    +
                ":H"                        +
                    AnsiString (nom_row),
                4,
                nom_row
            );


            for ( int j = 1;                                                    // ���������� ����� ������
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
void __fastcall TMainForm::Cicle_ball_konk (                                    // '���� ������' ���������� �� ��������
        int edu,
        int konk_place,
        int price
    )
{
    int cel_kol;                                                                // ���-�� ��������� �� �����

    for ( int i =  1;                                                           // ���������� �� ������ �� '���� �����'
              i <= col_rec;
              ++i
        )
    {
        AllCount_spec (i);                                                      // �������� ���������� ������������ �� �������������

        if (    konk_place == 1
             && (    nom_fac == 1
                  || nom_fac == 2
                )
           )
            CellValue (                                                         // ��� ���������� ���� � ��� ����� �������� ����������� �������������
                "���������-�������������� ������������ "    \
                "(���������� ������ � ��������� ���� ������)",
                1,
                nom_row
            );


        if (konk_place == 0)                                                    // ������� � �����
            konk = 0;                                                           // ����������� �� 1-�� ���� (�� abitura.konkurs)
        else
            konk = 2;                                                           // ����������� �� 2-�� ���� (�� abitura.konkurs)


        DM -> QStatistic_Every_Day_Ball_Price -> Close ();                      // ���������� ��������
        DM -> QStatistic_Every_Day_Ball_Price ->
            ParamByName ("N_FAC")   -> AsInteger = nom_fac;
        DM -> QStatistic_Every_Day_Ball_Price ->
            ParamByName ("VID_EDU") -> AsInteger = edu;
        DM -> QStatistic_Every_Day_Ball_Price ->
            ParamByName ("PRICE")   -> AsInteger = price;
        DM -> QStatistic_Every_Day_Ball_Price ->
            ParamByName ("N_SP")    -> AsInteger = spec;
        DM -> QStatistic_Every_Day_Ball_Price -> Open ();


        DM -> QCK_Kol_Plan -> Close ();                                         // ���� ���������  __declspec (uuid ("{83CCF233-FF44-4CFC-8525-6F6028460C85}"))
        DM -> QCK_Kol_Plan ->
            ParamByName ("N_SPECIALIZ") -> AsInteger = spec;
        DM -> QCK_Kol_Plan -> Open ();


        Run_ProcBall (                                                          // ��������� ������������� ��������� �� ������
            nom_fac,
            edu,
            konk,
            price,
            9,
            nom_row
        );


        CellFormula (                                                           // ������ ����� �� �������� ��� ����������� ������������� (=����(I1:AT1))
            "=����(I"                   +
                AnsiString (nom_row)    +
            ":AT"                       +
                AnsiString (nom_row),
            8,
            nom_row
        );


        if (    edu        == 0                                                 // �������� ������ �������
             && konk_place == 0                                                 // �������� ������ 1-�� ����
             && price      == 0                                                 // �������� ������ ������
           )
        {
            cel_kol =                                                           // ������ �� ���������� ��������� �� �����
                DM -> QCK_Kol_PlanKOL_PLACE -> Value;

            if (cel_kol)
                CellValue (
                    cel_kol,
                    3,
                    nom_row
                );
        }


        if (konk == 0)                                                          // ���-�� �������� ��������� �� 1-�� ����
        {
            for ( int j = 0;                                                    // ������ �� �������������
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
                            CellValue (                                         // ��
                                cel_kol,
                                5,
                                nom_row
                            );
                        break;
                    // case 2:
                    //             CellValue (                                     // �� 2 ����
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
                            CellValue (                                         // ��� ��������
                                cel_kol,
                                7,
                                nom_row
                            );
                        break;
                    case 4:
                            cel_kol =
                                DM -> QStatistic_Every_Day_Ball_PriceCOUNT ->
                                    Value;
                            CellValue (                                         // ��� ���������
                                cel_kol,
                                6,
                                nom_row
                            );

                            BVI =
                                DM -> QStatistic_Every_Day_Ball_PriceCOUNT ->
                                    Value;
                        break;
                }


                DMVed -> QKonkPlus -> Close ();                                 // ��������� ��
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
                    konk_stat;                                                  // �������
                int
                    AllPlan   =                                                 // ����� �� ����� �����
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
                        "������ ��� ��\n" +
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
        else                                                                    // ��� ����������� �� 2-�� ����
        {
            int BVI         = 0,
                sum_v_k,
                sum_without;

            if (nom_fac != 1)                                                   // ��� ���,����� � ��
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
                    CellValue (                                                 // ��� ���������
                        sum_without,
                        6,
                        nom_row
                    );

                    BVI = sum_without;
                }

                if (sum_v_k)
                    CellValue (                                                 // ��� ��������
                        sum_v_k,
                        7,
                        nom_row
                    );


                DM -> StoredProcStatistic_Konk -> Unprepare ();
                DM -> StoredProcStatistic_Konk -> Close ();


                DMVed -> QKonkPlus2 -> Close ();                                // ��������� ��
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


                int AllPlan =                                                   // ����� �� ����� �����
                    DM -> QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value;


                AnsiString s_tmp1;
                float      konk_stat;                                           // �������

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
                        "������ ��� ��\n" +
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
            else                                                                // ��� ����������� ���� � ���
            {
                int BVI = 0;                                                    // ��� ����

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

                DM -> StoredProcStatistic_Konk ->                               // ��������� ���
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
                    CellValue (                                                 // ��� ���������
                        sum_without,
                        6,
                        nom_row
                    );

                    BVI = sum_without;
                }

                if (sum_v_k)
                    CellValue (
                        sum_v_k,                                                // ��� ��������
                        7,
                        nom_row
                    );

                DM -> StoredProcStatistic_Konk -> Unprepare ();
                DM -> StoredProcStatistic_Konk -> Close ();


                int InPlus = 0;                                                 // ��������� ��

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


                int   AllPlan =                                                 // ����� �� ����� �����
                    DM -> QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value;

                float konk_stat;                                                // �������

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
                        "������ ��� ��\n" +
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


        CellFormula (                                                           // ������ ������ ����� �������� ��������� �� ������������� (-����(E1:H1))
            "=����(E"                   +
                AnsiString (nom_row)    +
            ":H"                        +
                AnsiString (nom_row),
            4,
            nom_row
        );


        for ( int j = 1;                                                        // ���������� ����� ������
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
        AllCount_spec (i);                                                      // ������ ������ ���������� ������������ �� �������������


        DM -> QPlan_Priem_Konk -> Close ();                                     // ���������� ���� �� ������� ��������
        DM -> QPlan_Priem_Konk ->
            ParamByName ("N_FAC")   -> AsInteger = nom_fac;
        DM -> QPlan_Priem_Konk ->
            ParamByName ("VID_EDU") -> AsInteger = edu;
        DM -> QPlan_Priem_Konk ->
            ParamByName ("N_SP")    -> AsInteger = spec;
        DM -> QPlan_Priem_Konk -> Open ();


        int kol_g_s = 0;                                                        // ����� ���-�� ���� ������ � ����

        for ( int s = 0;                                                        // ������ �� ���-�� ���� ��������� �������������
                  s < DM -> QPlan_Priem_Konk -> RecordCount;
                  ++s
            )
        {
            switch (DM -> QPlan_Priem_KonkTEXT -> Value)                        // ������� � KOL_PLACE
            {
                case 0:                                                         // �����
                        if (DM -> QPlan_Priem_KonkKOL_PLACE -> Value)
                            kol_g_s +=
                                DM -> QPlan_Priem_KonkKOL_PLACE -> Value;

                        CellFormula (                                           // ��������������� �������� ��������� �� ����� (=D1-I1-J1)
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
                // case 1:                                                         // ����
                //         kol_g_s +=
                //             DM -> QPlan_Priem_KonkKOL_PLACE -> Value;
                //     break;
                case 2:                                                         // ��
                        CellValue (
                            DM -> QPlan_Priem_KonkKOL_PLACE -> Value,
                            5,
                            nom_row
                        );
                    break;
                case 3:                                                         // ��������
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


        if (kol_g_s != -1)                                                      // ������ + ����
            CellValue (
                kol_g_s,
                4,
                nom_row
            );

        CellValue (
            "������",
            7,
            nom_row
        );
        CellValue (
            "�� ������",
            7,
            nom_row + 1
        );


        if (spec == DM -> QStatistic_Every_DayN_SPECIALIZ -> Value)
        {
            while (spec == DM -> QStatistic_Every_DayN_SPECIALIZ -> Value)
            {
                    konk = DM -> QStatistic_Every_DayKONKURS -> Value;
                int p    = DM -> QStatistic_Every_DayPRICE   -> Value;          // ����� ������

                switch (konk)
                {
                    case 0:                                                     // ����� (����������)
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
                    case 1:                                                     // �� (����������)
                            CellValue (
                                DM -> QStatistic_Every_DayCOUNT -> Value,
                                13,
                                nom_row + p
                            );
                            CellFormula (                                       // �������  (=M'1+p'/E'1+p')
                                "=M"                            +
                                    AnsiString (nom_row + p)    +
                                "/E"                            +
                                    AnsiString (nom_row + p),
                                19,
                                nom_row + p
                            );
                        break;
                    case 2:                                                     // 2-3 ���� (����������)
                            CellValue (
                                DM -> QStatistic_Every_DayCOUNT -> Value,
                                14,
                                nom_row + p
                            );
                        break;
                    case 3:                                                     // ��� �������� (����������)
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
                    case 4:                                                     // ��� ��������� (����������)
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
                    case 5:                                                     // ���������� (����������)
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


            CellFormula (                                                       // ����� �������� ���������  (=����(L1:Q1))
                "=����(L"                       +
                    AnsiString (nom_row)        +
                ":Q"                            +
                    AnsiString (nom_row)        +
                ")",
                11,
                nom_row
            );
            CellFormula (                                                       // ����� ������� �� ������  (=����(L2:Q2))
                "=����(L"                       +
                    AnsiString (nom_row + 1)    +
                ":Q"                            +
                    AnsiString (nom_row + 1)    +
                ")",
                11,
                nom_row + 1
            );
            CellFormula (                                                       // ����� ������� �� ������  (=(K1-N1-Q1)/(D1+E1))
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
            CellFormula (                                                       // ����� ������� �������� (=(K2-N2-Q2)/(F1))
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
                MergeCell (                                                     // ����������� �����
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
        spec = DM -> QPlan_Priem_All_SpecialN_SPEC -> Value;                    // ����� ���������� ������������ �� �����������


        DM -> QPlan_Priem_Konk_Special -> Close ();
        DM -> QPlan_Priem_Konk_Special ->
            ParamByName ("vid_edu") -> AsInteger = edu;
        DM -> QPlan_Priem_Konk_Special ->
            ParamByName ("n_sp")    -> AsInteger = spec;
        DM -> QPlan_Priem_Konk_Special -> Open ();                              // �������� ���-�� ���� �� ������� ��������


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
            CellValue (                                                             // ������ �������� �������������
                DM -> QPlan_Priem_All_SpecialSPEC -> Value,
                2,
                nom_row
            );
        else
            CellValue (                                                             // ������ �������� �������������
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


        int kol_g_s = 0;                                                        // ���������� ��� ������������ ���� ������ � ����

        for ( int s = 0;                                                        // ������ �� ���-�� ���� ��������� �������������
                  s < DM -> QPlan_Priem_Konk_Special -> RecordCount;
                  ++s
            )
        {
            switch (DM -> QPlan_Priem_Konk_SpecialTEXT -> Value)                // ������� � KOL_PLACE (�����: 0 - ������ ����, 1 - ����������)
            {
                case 0:                                                         // �����
                        if (DM -> QPlan_Priem_Konk_SpecialSUM1 -> Value)
                            kol_g_s +=
                                DM -> QPlan_Priem_Konk_SpecialSUM1 -> Value;

                        CellFormula (                                           // ��������������� �������� ��������� �� �����  (=D1-I1-J1)
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
                // case 1:                                                         // ����
                //         kol_g_s +=
                //             DM -> QPlan_Priem_Konk_SpecialSUM1 -> Value;
                //     break;
                case 2:                                                         // ��
                        sum =
                            DM -> QPlan_Priem_Konk_SpecialSUM1 -> Value;

                        CellValue (
                            sum,
                            5,
                            nom_row
                        );
                    break;
                case 3:                                                         // �� ������
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

        if (kol_g_s != -1)                                                      // ������ + ����
            CellValue (
                kol_g_s,
                4,
                nom_row
            );

        CellValue (
            "������",
            7,
            nom_row
        );
        CellValue (
            "�� ������",
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

                int p =                                                         // ����� ������
                    DM -> QStatistic_Every_Day_SpecialPRICE   -> Value;

                switch (konk)
                {
                    case 0:                                                     // ����� (����������)
                            if (oplata_konkurs == 0)
                            {
                                if ( ! p)
                                {
                                    val =
                                        DM -> QStatistic_Every_Day_SpecialCOUNT ->
                                            Value;

                                    if (val)                                    // ����������
                                        CellValue (
                                            val,
                                            12,
                                            nom_row + p
                                        );

                                    CellFormula (                               // ������� �����        (=M'1+p'/H'1+p')
                                        "=M"                            +
                                            AnsiString (nom_row + p)    +
                                        "/H"                            +
                                            AnsiString (nom_row + p),
                                        18,
                                        nom_row + p
                                    );
                                }
                                else                                            // ����� �������
                                    CellValue (
                                        val,
                                        12,
                                        nom_row + p
                                    );
                            }
                            else
                            {
                                val =                                           // ����������
                                    DM -> QStatistic_Every_Day_SpecialCOUNT ->
                                        Value;

                                if (val)
                                    CellValue (
                                        val,
                                        12,
                                        nom_row + p
                                    );

                                CellFormula (                                   // ������� �����        (=M'1+p'/H'1+p')
                                    "=M"                            +
                                        AnsiString (nom_row + p)    +
                                    "/H"                            +
                                        AnsiString (nom_row + p),
                                    18,
                                    nom_row + p
                                );
                            }
                        break;
                    case 1:                                                     // �� (����������)
                            val =
                                DM -> QStatistic_Every_Day_SpecialCOUNT ->
                                    Value;

                            if (val)
                                CellValue (
                                    val,
                                    13,
                                    nom_row + p
                                );

                            CellFormula (                                       // �������  (=O'1+p'/E'1+p')
                                "=O"                            +
                                    AnsiString (nom_row + p)    +
                                "/E"                            +
                                    AnsiString (nom_row + p),
                                19,
                                nom_row + p
                            );
                        break;
                    case 2:                                                     // 2-3 ���� (���-��)
                            CellValue (
                                val,
                                14,
                                nom_row + p
                            );
                        break;
                    case 3:                                                     // ��� �������� (����������)
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
                    case 4:                                                     // ��� ��������� (����������)
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
                    case 5:                                                     // ����������
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


            CellFormula (                                                       // ����� �������� ��������� (=����(L1:Q1))
                "=����(L"                       +
                    AnsiString (nom_row)        +
                ":Q"                            +
                    AnsiString (nom_row)        +
                ")",
                11,
                nom_row
            );
            CellFormula (                                                       //                          (=����(L2:Q2))
                "=����(L"                       +
                    AnsiString (nom_row + 1)    +
                ":Q"                            +
                    AnsiString (nom_row + 1)    +
                ")",
                11,
                nom_row + 1
            );
            CellFormula (                                                       // ����� ������� ������     (=(K1-N1-Q1)/(D1+E1))
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
            CellFormula (                                                       // ����� ������� ��������   (=(K2-N2-Q2)/(F1))
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
void __fastcall TMainForm::CicleSum (                                           // ������� ����� �� �������
        int n_r,                                                                // ����� ������ ���������
        int nom_row,                                                            // ����� ������ �������
        int st1,                                                                // ����� ������� ������ ��� ������ ������������
        int st2,                                                                // ����� ������� ��������� ��� ��������� ������������
        int index                                                               // 0 - �������� ������������ (=����(B1:B9)) 1 - ������� (= B1 + B9)
    )
{
    AnsiString form = "";

    for ( int i =  st1;
              i <= st2;
              ++i
        )
    {
        if (! index)                                                            // ����� ����� �������� (=����(B1:B9))
            form =
                "=����("                        +
                    mas_column[i - 1]           +
                    AnsiString (n_r)            +
                ":"                             +
                    mas_column[i - 1]           +
                    AnsiString (nom_row - 1)    +
                ")";
        else                                                                    //  ����� ����� ������� (=B1+B9)
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
bool __fastcall TMainForm::Clear_mas (int n_ab)                                 // ����� ������ ����������� � ������� all � ��������� ���� ������
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
void __fastcall TMainForm::Create_mas_all (                                     // �������� ������� ���� ������������ �� �������
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
void __fastcall TMainForm::Create_Svod_ved (                                    // ������� ������������ ������� ���������
        int edu,                                                                // ��� ��������:   0 - �������, 1 - �������
        int price                                                               // ��������������: 0 - ������,  1 - ��������
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
            "����1"
        );

    OVisible (ExcelApplication);

    CellValue (                                                                 // ���������
        fac1,
        3,
        6
    );

    DMVed -> QPredm -> Close ();                                                // ������ '�������� ���������'
    DMVed -> QPredm -> Open ();

    int
        rec_pred = 3,
        spec     = DM -> QSpecializN_SPECIALIZ -> Value;                        // IMPORTANT!!! I added initialization because there is no value for if statement

    mas_pr = new AnsiString[rec_pred];

    mas_pr[0] = "����������� (�������) ����";

    CellValue (
        "���. (���.) ��",
        9,
        12
    );


    //if (spec != 61)
    if (spec == KindOfSportCode::TOURISM_HOSPITALITY)                           // �������� �������
    {
        mas_pr[1] = "����������";

        CellValue (
            "�����.",
            10,
            12
        );

        mas_pr[2] = "���������";

        CellValue (
            "�����.",
            11,
            12
        );
    }
    else
    {
        mas_pr[1] = "��������";

        CellValue (
            "����.",
            10,
            12
        );
    }

    DM -> QSpecializ -> Close ();
    DM -> QSpecializ -> Open ();
    DM -> QSpecializ -> First ();

    int rec_special = DM -> QSpecializ -> RecordCount;

    for ( int i = 0;                                                            // ������ �� ��������������
              i < rec_special;
              ++i
        )
    {
        Create_mas_all (
            DM -> QSpecializN_SPECIALIZ -> Value,
            edu
        );


        spec = DM -> QSpecializN_SPECIALIZ -> Value;                            // ���� �� �������������


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

        int nom_str = 13;                                                       // ����� ��������� ������ � Excel

        if (col_gorod > 0)                                                      // �������� ���� �� ������� �� ������ �������������
        {
            Sheet =
                SelectSheet (
                    Workbook,
                    "����1"
                );

            CopySheet (Sheet);

            Sheet =
                SelectSheet (
                    Workbook,
                    "����1 (2)"
                );
            NameSheet1 (
                Sheet,
                DM -> QSpecializSPECIAL -> Value.SetLength (30)
            );


            if (spec != 61)
            {
                mas_pr[1] = "��������";

                CellValue (
                    "����.",
                    10,
                    12
                );
            }
            else                                                                // �������� �������
            {
                mas_pr[1] = "����������";

                CellValue (
                    "�����.",
                    10,
                    12
                );


                mas_pr[2] = "���������";

                CellValue (
                    "�����.",
                    11,
                    12
                );
            }


            if (spec != 61)
            {
                mas_pr[2] = "���������� �������� � �����";

                CellValue (
                    "����",
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
                    "�������",
                    3,
                    8
                );
            else
                CellValue (
                    "�������",
                    3,
                    8
                );

            if (price)
                CellValue (
                    "�� ������� ������",
                    3,
                    9
                );
            else
                CellValue (
                    "�� ���� ������� "          \
                    "���������������� �������",
                    3,
                    9
                );


            int kkk = 3;                                                        // ������� '�������'

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

            if (rec)                                                            // if ���� ����� ����
                nom_str =
                    Svod_ved (
                        nom_str,
                        kkk,
                        edu,
                        rec_pred,
                        price,
                        0
                    );


            kkk = 1;                                                            // ������� '���'

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

            if (rec)                                                            // if ���� ����� ����
                nom_str =
                    Svod_ved (
                        nom_str,
                        kkk,
                        edu,
                        rec_pred,
                        price,
                        0
                    );


            kkk = 2;                                                            // ������� '��'

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

            if (rec)                                                            // if ���� ����� ����
                nom_str =
                    Svod_ved (
                        nom_str,
                        kkk,
                        edu,
                        rec_pred,
                        price,
                        0
                    );


            kkk = 0;                                                            // ������� '�����'

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

            if (rec)                                                            // if ���� ����� ����
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
            StudyPeriod::HIGH::FULL,                                            // "������ �����������",
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
void __fastcall TMainForm::Create_Svod_ved_2VO2K (                              // ������� ������������ ������� ��������� 2 ���� ��
        int edu,                                                                // ��� ��������:   0 - �������, 1 - �������
        int price                                                               // ��������������: 0 - ������,  1 - ��������
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
            "����1"
        );
    OVisible (ExcelApplication);

    CellValue (                                                                 // ���������
        fac1,
        3,
        6
    );

    int rec_pred = 0;

    DM -> QSpecializ -> Close ();
    DM -> QSpecializ -> Open ();
    DM -> QSpecializ -> First ();

    int rec_special = DM -> QSpecializ -> RecordCount;

    for ( int i = 0;                                                            // for ���� �� ��������������
              i < rec_special;
              ++i
        )
    {
        Create_mas_all (
            DM -> QSpecializN_SPECIALIZ -> Value,
            edu
        );

        DM -> VO2KSpecializQr -> Close ();                                      // ���� �� �������������
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
            nom_str   = 13;                                                     // ��������� ���������� ��� ������ ������ � Excel

        col_gorod = DMVed -> QKol_Place15KOL_PLACE -> Value;

        if (DM -> VO2KSpecializQrNOMER_AB -> Value > 0)                         // if �������� ���� �� ������� �� ������ �������������
        {
            Sheet =
                SelectSheet (
                    Workbook,
                    "����1"
                );

            CopySheet (
                Sheet
            );

            Sheet =
                SelectSheet (
                    Workbook,
                    "����1 (2)"
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
                    "�������",
                    3,
                    8
                );
            else
                CellValue (
                    "�������",
                    3,
                    8
                );

            if (price)
                CellValue (
                    "������� ����������� �� ������� ������",
                    3,
                    9
                );
            else
                CellValue (
                    "������� ����������� �� ���� ������� "  \
                    "���������������� �������",
                    3,
                    9
                );


            int kkk = 3;                                                        // ������� (�������)

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


            kkk = 1;                                                            // ������� (���)

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


            kkk = 2;                                                            // ������� (��)

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


            kkk = 0;                                                            // ������� (�����)

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
            StudyPeriod::HIGH::NAME,                                            // "������ �����������",
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
void __fastcall TMainForm::Create_Svod_ved_short (                              // ������� ������������ ������� ��������� ����������� ����
        int edu,                                                                // ��� ��������:   0 - �������, 1 - �������
        int price                                                               // ��������������: 0 - ������,  1 - ��������
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
            "����1"
        );

    OVisible (ExcelApplication);

    CellValue (                                                                 // ���������
        fac1,
        3,
        6
    );

    DMVed -> QPredm -> Close ();                                                // ������ �������� ���������
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
            "���������� �������� � �����";

        CellValue (
            "����",
            11,
            12
        );

        mas_pr[1] =
            "������ � �������� ����������� ����������";

        CellValue (
            "�����",
            10,
            12
        );
    }


    if (    nom_fac == 1                                                        // ����, ���
         || nom_fac == 2
       )
    {
        mas_pr[2] =
            "���������� �������� � �����";

        CellValue (
            "����",
            11,
            12
        );

        mas_pr[1] =
            "������ ������ � �������� ���������� ����������";

        CellValue (
            "������",
            10,
            12
        );
    }


    if (nom_fac == 4)                                                           // �� ����
    {
        mas_pr[2] =
            "��������� �������";

        CellValue (
            "������. ���",
            11,
            12
        );

        mas_pr[1] =
            "����������� �������";

        CellValue (
            "�������. ���.",
            10,
            12
        );
    }

    int nom_str = 13;                                                           // ����� ��������� ������ � Excel

    Sheet =
       SelectSheet (
           Workbook,
           "����1"
       );

    if (nom_fac != 4)
    {
        mas_pr[2] =
            "���������� �������� � �����";

        CellValue (
            "����",
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
                    //"���������-�������������� ������������ "  \
                    //"(���������� ������ � ��������� ���� ������)",
                    3,
                    7
                );
            break;
        case 2:
                CellValue (
                    //"1-88 02 01-01 ���������-�������������� ������������ "  \
                    //"(���������� ������ � ��������� ���� ������)",
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
                    //"1-88 01 01-02 ���������� �������� (������������), "     \
                    //"1-88 01 02-01 ��������������� � ���������� "           \
                    //"���������� �������� (���������������)",
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
                    //"1-89 01 01 ������ � ��������������)",
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
            "�������",
            3,
            8
        );
    else
        CellValue (
            "�������",
            3,
            8
        );


    if (price)
        CellValue (
            "�� ������� ������",
            3,
            9
        );
    else
        CellValue (
            "�� ���� ������� ���������������� �������",
            3,
            9
        );


    if (    nom_fac == 1
         || nom_fac == 2
       )
    {
        int kkk = 3;                                                            // ������� '�������'


        DMVed -> QKonkurs12 -> Close ();
        DMVed -> QKonkurs12 ->
            ParamByName ("in_vid_edu") -> Value = edu;
        DMVed -> QKonkurs12 ->
            ParamByName ("in_konk")    -> Value = kkk;
        DMVed -> QKonkurs12 ->
            ParamByName ("in_price")   -> Value = price;
        DMVed -> QKonkurs12 -> Open ();


        int rec = DMVed -> QKonkurs12 -> RecordCount;

        if (rec)                                                                // ���� �� ����� ����
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );


        kkk = 1;                                                                // ������� '���'

        DMVed -> QKonkurs12 -> Close ();
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_VID_EDU") -> Value = edu;
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_KONK")    -> Value = kkk;
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_PRICE")   -> Value = price;
        DMVed -> QKonkurs12 -> Open ();

        rec = DMVed -> QKonkurs12 -> RecordCount;

        if (rec)                                                                // if ���� ����� ����
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );


        kkk = 2;                                                                // ������� '��'

        DMVed -> QKonkurs12 -> Close ();
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_VID_EDU") -> Value = edu;
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_KONK")    -> Value = kkk;
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_PRICE")   -> Value = price;
        DMVed -> QKonkurs12 -> Open ();

        rec = DMVed -> QKonkurs12 -> RecordCount;

        if (rec)                                                                // if ���� ����� ����
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );


        kkk = 0;                                                                // ������� '�����'

        DMVed -> QKonkurs12 -> Close ();
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_VID_EDU") -> Value = edu;
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_KONK")    -> Value = kkk;
        DMVed -> QKonkurs12 ->
            ParamByName ("IN_PRICE")   -> Value = price;
        DMVed -> QKonkurs12 -> Open ();

        rec = DMVed -> QKonkurs12 -> RecordCount;

        if (rec)                                                                // if ���� ����� ����
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
    else                                                                        // �����, ��� QKonkurs34
    {
        int kkk = 3;                                                            // ������� '�������'

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

        if (rec)                                                                // if ���� ����� ����
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );


        kkk = 1;                                                                // ������� '���'

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

        if (rec)                                                                // if ���� ����� ����
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );


        kkk = 2;                                                                // ������� '��'

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

        if (rec)                                                                // if ���� ����� ����
            nom_str =
                Svod_ved (
                    nom_str,
                    kkk,
                    edu,
                    rec_pred,
                    price,
                    1
                );


        kkk = 0;                                                                // ������� '�����'

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

        if (rec)                                                                // if ���� ����� ����
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
            StudyPeriod::SHORT::NAME,                                           // "C���������� ����",
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
void __fastcall TMainForm::Data_spisok (                                        // ��������� ������ S1,S2,S3 (����������� � ����������� �������) ������� ������������
        int col_pred,                                                           // ���������� ���������
        int nom_stroka,                                                         // ����� ������
        int j                                                                   // ����� �� �������
    )
{
    Priv_Str (10);                                                              // �������� 10 - ��������� ������ ������ ������������


    CellValue (                                                                 // ��������� ����� �� ��������� (�������)
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


    CellValue (                                                                 // ��������� � �/�
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


    CellValue (                                                                 // ��������� ���
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


    CellValue (                                                                 // ��������� ����������� �������
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


    CellValue_Ball (                                                            // ��������� ������ �� ���� ��������� ��� ������ �����������
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
            "0,0"                                                               // 0.0 � ����� Excel ����� ����� ������
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


    CellValue (                                                             // ��������� �������� ����� ���������
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


    CellValue (                                                                 // ��������� ���������� (������������ ��� ����������)
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
    CellValue (                                                                 // ��������� � �/�
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

    CellValue (                                                                 // ��������� ���
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
int  __fastcall TMainForm::Find_nom_spec_str (                                  // ����� ������� ������ � ������� mas_spec_str �� ������ �������������
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
void __fastcall TMainForm::Forma_Giac (                                         // ����� ��� ����
        int form,                                                               // ����� ����� ��� ����: 1 - ����, 2 - ����������
        int vid_educ                                                            // ��� ��������
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
            cur_dir             +                                               // "D:\\��������� �������� ��������\\1\\"
            report_type
        );
    OVisible (ExcelApplication);

    int
        giac_val,                                                               // �������� ��� ������ � ������� I
        N_Spec[6],
        razd1     = 10;                                                         // ����� ������ ��� ������������ �������

    N_Spec[0]        = 8;                                                       // ���������� �������� (�� ������������)
    N_Spec[1]        = 5;                                                       // ��������������� � ���������� ���������� �������� (�� ������������)
    N_Spec[2]        = 9;                                                       // ���������� ������������ � ����������� (�� ������������)
    N_Spec[3]        = 6;                                                       // ���������-�������������� ������������ (�� ������������)
    N_Spec[4]        = 10;                                                      // ������ � ��������������
    N_Spec[5]        = 7;                                                       // ���������-���������� ������������ (�� ������������)

    if (form == 1)                                                              // ����� 1 - ���� ����������
    {
        Sheet =
            SelectSheet (
                Workbook,
                "�����"
            );

        if (vid_educ)
        {
            CellValue (
                "� ������� ����� ��������� �����������",
                3,
                17
            );
            CellValue (
                "� ������� ����� ��������� �����������",
                3,
                24
            );
        }
        else
            CellValue (
                "� ������� ����� ��������� �����������",
                3,
                17
            );


        CellValue (
            "� ������� ����� ��������� �����������",
            3,
            24
        );


        Sheet =
            SelectSheet (
                Workbook,
                "������ I"
            );


        DM -> QGIACAllSpec -> Close ();                                         // (���� �����) ���������� �������� (�� ������������) n_spec = 8
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



        DM -> QGIACAllSpec -> Close ();                                         // ��������������� � ���������� ���������� �������� (�� ������������) n_spec = 5
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



        DM -> QGIACAllSpec -> Close ();                                         // ���������� ������������ � ����������� (�� ������������) n_spec = 9
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



        DM -> QGIACAllSpec -> Close ();                                         // ���������-�������������� ������������ (�� ������������) n_spec = 6
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



        DM -> QGIACAllSpec -> Close ();                                         // ������ � ��������������  n_spec=10
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



        DM -> QGIACAllSpec -> Close ();                                         // ���������-���������� ������������ (�� ������������) n_spec = 7
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



        DM -> QGIACCKSpec -> Close ();                                          // ���� '�������'  ���������� �������� (�� ������������)
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



        DM -> QGIACCKSpec -> Close ();                                          //  ���� '�������'  ��������������� � ���������� ���������� �������� (�� ������������)
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



        DM -> QGIACCKSpec -> Close ();                                          // ���� '�������'  ���������� ������������ � ����������� (�� ������������)
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



        DM -> QGIACCKSpec -> Close ();                                          // ���� '�������'  ���������-�������������� ������������ (�� ������������)
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



        DM -> QGIACCKSpec -> Close ();                                          // ���� '�������'  ������ � ��������������
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



        DM -> QGIACCKSpec -> Close ();                                          // ���� '�������'  ���������-���������� ������������ (�� ������������)
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



        DM -> QGIAC2kSpec -> Close ();                                          // ���� '2 ����'  ���������� �������� (�� ������������)
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



        DM -> QGIAC2kSpec -> Close ();                                          // ���� '2 ����'  ��������������� � ���������� ���������� �������� (�� ������������)
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



        DM -> QGIAC2kSpec -> Close ();                                          // ���� '2 ����'  ���������� ������������ � ����������� (�� ������������)
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



        DM -> QGIAC2kSpec -> Close ();                                          // ���� '2 ����'  ���������-�������������� ������������ (�� ������������)
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



        DM -> QGIAC2kSpec -> Close ();                                          // ���� '2 ����'  ������ � ��������������
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



        DM -> QGIAC2kSpec -> Close ();                                          // ���� '2 ����'  ���������-���������� ������������ (�� ������������)
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


        TDateTime date_in =                                                     // SECTION: ������ �����
            StrToDateTime (
                Admissions::DEADLINE::FOR_RECEIVING_PART_1
            );


        DMStat -> Giaz01SP -> Close ();                                         // ���������� �������� (�� ������������)

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



        DMStat -> Giaz01SP -> Close ();                                         // ��������������� � ���������� ���������� �������� (�� ������������)

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



        DMStat -> Giaz01SP -> Close ();                                         // ���������� ������������ � ����������� (�� ������������)

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



        DMStat -> Giaz01SP -> Close ();                                         // ���������-�������������� ������������ (�� ������������)

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



        DMStat -> Giaz01SP -> Close ();                                         // ������ � ��������������

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



        DMStat -> Giaz01SP -> Close ();                                         // ���������-���������� ������������ (�� ������������)

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



        Sheet =                                                                 // ������ II.1
            SelectSheet (
                Workbook,
                "������ II.1"
            );


        DMStat -> GIAZ021SP -> Close ();                                        // ����� ������

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



        Sheet =                                                                 // ������ II.2
            SelectSheet (
                Workbook,
                "������ II.2"
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



        Sheet =                                                                 // ������ III
            SelectSheet (
                Workbook,
                "������ III"
            );



        // DM -> QGIACEdOSred -> Close ();                                         // ����� ������� QGIACEdOSred  !

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



        DM -> QGIACEdOSredCity -> Close ();                                     // ����� ������� �����

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


        DM -> QGIACEdOSredVil -> Close ();                                      // ����� ������� ����

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


        DM -> QGIACYearSredCity -> Close ();                                    // ��� ��������� �������� ����� QGIACYearSred  !
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



        DM -> QGIACYearSredVil -> Close ();                                     // ��� ��������� �������� ���� QGIACYearSred  !
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



        DM -> QGIACEdLic -> Close ();                                           // ������� ����� QGIACEdLic !
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



        DM -> QGIACEdOSred -> Close ();                                         // ������� ����������� QGIACEdOSred !
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



        DM -> QGIACYearSredSpec -> Close ();                                    // ��� ��������� ������-������������ QGIACYearSredSpec  !
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


        DM -> QGIACEdOSred -> Close ();                                         // ��� QGIACEdOSred  !
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


        DM -> QGIACYearSredSpec -> Close ();                                    // ��� ��������� ��� QGIACYearSredSpec   !
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


        DM -> QGIACEdOSred -> Close ();                                         // ��� QGIACEdOSred  !
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


        DM -> QGIACForeigner -> Close ();                                       // ���������� QGIACForeigner
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
    else                                                                        // ����� 2 - ���������� ������������
    {
        Sheet =                                                                 // ��������� ����
            SelectSheet (
                Workbook,
                "�����"
            );


        if (vid_educ)
        {
            CellValue (
                "� ������� ����� ��������� �����������",
                3,
                18
            );
            CellValue (
                "� ������� ����� ��������� �����������",
                3,
                28
            );
        }
        else
        {
            CellValue (
                "� ������� ����� ��������� �����������",
                3,
                18
            );
            CellValue (
                "� ������� ����� ��������� �����������",
                3,
                28
            );
        }



        Sheet =                                                                 // ������� 1
            SelectSheet (
                Workbook,
                "������ I"
            );



        for ( int i = 0;                                                        // ��������� � ����������� ������������� ��������� (int Kol_VI;)
                  i < 6;
                  ++i
            )
        {
            DMVed -> GIAZ2_1_1StrdPrc -> Close ();                              // ��������� ������������� ���������
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



        DMVed -> GIAZ2_1_3Qr -> Close ();                                       // '������ � ��������������' ����������� �� 3-� ������������ (�� and 1 ����)
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



        for ( int i = 0;                                                        // ��������� ���
                  i < 6;
                  ++i
            )
        {
            int bvi = 0;

            DMVed -> GIAZ2_1_4Qr -> Close ();                                   // ��� �� ��������
            DMVed -> GIAZ2_1_4Qr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_4Qr ->
                ParamByName ("n_spec")  -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_4Qr -> Open ();

            bvi = DMVed -> GIAZ2_1_4QrCOUNT -> Value;

            DMVed -> GIAZ2_1_4Qr -> Close ();


            DMVed -> GIAZ2_1_4_ckQr -> Close ();                                // �� � ���������� ���
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



        for ( int i = 0;                                                        // ��������� ��
                  i < 6;
                  ++i
            )
        {
            int vk = 0;

            DMVed -> GIAZ2_1_5Qr -> Close ();                                   // �� �� ��������
            DMVed -> GIAZ2_1_5Qr ->
                ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
            DMVed -> GIAZ2_1_5Qr ->
                ParamByName ("n_spec")  -> AsSmallInt = N_Spec[i];
            DMVed -> GIAZ2_1_5Qr -> Open ();

            vk = DMVed -> GIAZ2_1_5QrCOUNT -> Value;

            DMVed -> GIAZ2_1_5Qr -> Close ();



            DMVed -> GIAZ2_1_5_ckQr -> Close ();                                // �� � ���������� ��
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



        for ( int i = 0;                                                        // ��������� ����� �� ������
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



        for ( int i = 0;                                                        // ��������� �� ���. ������
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
            DMVed -> GIAZ2_1_7Qr ->                                             // !!! ���� ������� ���. ������
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

                                                                                // �����-��� � ������-��� 2017 - ���!!!

        for ( int i = 0;                                                        // ��������� ������� ����������
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



        for ( int i = 0;                                                        // ��������� ������,����������� �����
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



        for ( int i = 0;                                                        // ��� ��������� 2-�� �������
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



        for ( int i = 0;                                                        // ��������� ����� �� ������
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



        for ( int i = 0;                                                        // ��������� �� ������,����������� �����
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



        for ( int i = 0;                                                        // ��������� �� ������, 2-�� ������
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



        Sheet =                                                                 // ������� 2 - �������� � ���������� �����������
            SelectSheet (
                Workbook,
                "������ II �.2"
            );


        int bvi = 0;                                                            // ����� ���


        DMVed -> GIAZ2_2_1Qr -> Close ();                                       // ��� �� ��������
        DMVed -> GIAZ2_2_1Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_2_1Qr -> Open ();

        bvi = DMVed -> GIAZ2_2_1QrCOUNT -> Value;

        DMVed -> GIAZ2_2_1Qr -> Close ();


        DMVed -> GIAZ2_2_1ckQr -> Close ();                                     // �� � ���
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


        DMVed -> GIAZ2_2_2Qr -> Close ();                                       // ���������� ����. � ����. �������� �� ������� ���������
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


        DMVed -> GIAZ2_2_4Qr -> Close ();                                       // �������� ����. ������ ���������� ��
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


        DMVed -> GIAZ2_2_6Qr -> Close ();                                       // �� ������������� ���������� �������� � ������
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



        Sheet =                                                                 // ������� 3 - �������� � ���������� �����������
            SelectSheet (
                Workbook,
                "������ II �.3"
            );


        int vk = 0;                                                             // ��� ��������


        DMVed -> GIAZ2_3_1Qr -> Close ();                                       // ��� �� ��������
        DMVed -> GIAZ2_3_1Qr ->
            ParamByName ("vid_edu") -> AsSmallInt = vid_educ;
        DMVed -> GIAZ2_3_1Qr -> Open ();

        vk = DMVed -> GIAZ2_3_1QrCOUNT -> Value;

        DMVed -> GIAZ2_3_1Qr -> Close ();


        DMVed -> GIAZ2_3_1ckQr -> Close ();                                     // �� � ���������� ���
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



        DMVed -> GIAZ2_3_2Qr -> Close ();                                       // ����-������ GIAZ2_3_2Qr
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


        DMVed -> GIAZ2_3_3Qr -> Close ();                                       // �������� ������ GIAZ2_3_3Qr
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


        DMVed -> GIAZ2_3_4Qr -> Close ();                                       // �� ���� ���.�����. GIAZ2_3_4Qr
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


        DMVed -> GIAZ2_3_6Qr -> Close ();                                       // ����-�������� I � II �����  GIAZ2_3_6Qr
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


        DMVed -> GIAZ2_3_7Qr -> Close ();                                       // � ������� ���
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


        DMVed -> GIAZ2_3_8Qr -> Close ();                                       // � ������� ����
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


        DMVed -> GIAZ2_3_9Qr -> Close ();                                       // � ������� ���
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


        Sheet =                                                                 // ������� 4 - �������� � ���������� ����������� (��������� ����)
            SelectSheet (
                Workbook,
                "������ III"
            );


        DMVed -> GIAZ2_4_1Qr -> Close ();                                       // ��� ����� �����
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


        DMVed -> GIAZ2_4_1Qr -> Close ();                                       // ��� ����� � ���� ����
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


        DMVed -> GIAZ2_4_3Qr -> Close ();                                       // ��� ���� �����
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


        DMVed -> GIAZ2_4_3Qr -> Close ();                                       // ��� ���� � ���� ����
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


        DMVed -> GIAZ2_4_5Qr -> Close ();                                       // ����� � ��������
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


        DMVed -> GIAZ2_4_6Qr -> Close ();                                       // ���� ����� �����
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


        DMVed -> GIAZ2_4_6Qr -> Close ();                                       // ���� ����� � ���� ����
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


        DMVed -> GIAZ2_4_8Qr -> Close ();                                       // ��� ����� �����
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


        DMVed -> GIAZ2_4_8Qr -> Close ();                                       // ��� ����� � ���� ����
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


        DMVed -> GIAZ2_4_10Qr -> Close ();                                      // ��� ����� �����
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


    AnsiString n_file = "������������� ���������� ����� ";


    switch (form)
    {
        case 1:
                n_file += " ����� ";
            break;
        case 2:
                n_file += " ���������� ";
            break;
        case 3:
                n_file += " ���������� ������ ";
            break;
    }

    if (vid_educ)
        n_file += " ������� ";
    else
        n_file += " ������� ";

    n_file +=
        "�� "                                   +
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
        N26 -> Enabled = true;                                                  // ������� ��������� �� 2 ���� [INVISIBLE]

    #ifndef NEW_EXAM_SUMMARY_LISTS
    N33 -> Caption = "��������� �� ������������";
    #else
    #ifndef TEST_EXAMEN_UNIT
    N4  -> Visible = false;
    #else
    N4  -> Visible = true;
    #endif  // ! TEST_EXAMEN_UNIT
    N33 -> Caption = "���., �����., �����. ���";
    #endif  // ! NEW_EXAM_SUMMARY_LISTS

    #ifndef SHOW_EXTRA_BUTTONS
    N32 -> Visible = false;                                                     // ���������� -> ����� ��� ������� -> ������ ��������� (��������)       [TODO: create distribute method as N43]
    N44 -> Visible = false;                                                     // ���������� -> ����� ��� ������� -> ������ ��������� �� ������������  [TODO: create distribute method as N43]
    N55 -> Visible = false;                                                     // ���������� - �������     [Use Abitur_RIO instead!!!]
    #endif  // ! SHOW_EXTRA_BUTTONS

    if (nom_fac == 4)
    {
        // N4  -> Enabled = false;                                                 // ���������
        N5  -> Enabled = true;                                                  // ����������
        N6  -> Enabled = false;                                                 // ���������
        N16 -> Enabled = true;                                                  // �������������� �� �������
        // N22 -> Enabled = false;                                                 // ������� ��������� �������
        N26 -> Enabled = true;                                                  // ��������� �� ��� � ��
        N27 -> Enabled = false;                                                 // ������� ��������� �������
        N33 -> Enabled = true;                                                  // ��������� �� ��� � ���
    }


    MainForm -> Caption =
        "����������  - "            +
            DM -> TFaculty ->
                Lookup (
                    "N_FAC",
                    nom_fac,
                    "FAC"
                )                   +
        "       (������ "           +
            DM -> get_version ()    +
        ")   "                      +
        TextTest;


    if (st_developer)                                                           // ������ �� ���������� ������ ��� ������������
    {
        N35 -> Enabled = true;                                                  // ������ �� ����������
        N20 -> Enabled = true;                                                  // ������������ �����������
        N9  -> Enabled = true;                                                  // ����
        N36 -> Enabled = true;                                                  // ���������� ���������
        N40 -> Enabled = true;                                                  // ���������� ���������
        N26 -> Enabled = true;                                                  // ��������� �� ��� � ��
        N33 -> Enabled = true;                                                  // ��������� �� ��� � ���
        N4  -> Enabled = true;                                                  // ���������
        N5  -> Enabled = true;                                                  // ����������
        N6  -> Enabled = true;                                                  // ���������
        N16 -> Enabled = true;                                                  // �������������� �� �������
        N22 -> Enabled = true;                                                  // ������� ��������� �������
        N27 -> Enabled = true;                                                  // ������� ��������� �������
        N42 -> Enabled = true;                                                  // ������ �� ������������
        N44 -> Enabled = true;                                                  // �������� �� ������������
        N49 -> Visible = true;                                                  // ���������

        SpeedButton1 -> Visible = true;                                         // ������ ������� ���������
        SpeedButton3 -> Visible = true;                                         // ����������� �� ���������
        SpeedButton4 -> Visible = true;                                         // ����� �� ������ �������� ��������
    }
    else
    {
        N9  -> Enabled = false;                                                 // ����
        N20 -> Enabled = false;                                                 // ������������ �����������
        N23 -> Visible = false;                                                 // �������������� ���. ������ (I added this to creation buttons)

        #ifdef SHOW_EXAM_RESULTS_ONLY_FOR_ADMISSIONS_COMMITTEE
        if (st_asu)                                                             // ���������� ���������
            N36 -> Enabled = true;
        else
            N36 -> Enabled = false;
        #else
        N36 -> Enabled = true;
        #endif  // SHOW_EXAM_RESULTS_ONLY_FOR_ADMISSIONS_COMMITTEE

        N40 -> Enabled = false;                                                 // ���������� ���������
        N42 -> Enabled = false;                                                 // ������ �� ������������
        N44 -> Enabled = false;                                                 // �������� �� ������������
        N35 -> Visible = false;                                                 // ������ �� ����������
        N49 -> Visible = false;                                                 // ���������

        SpeedButton1 -> Visible = false;                                        // ������ ������� ���������
        SpeedButton3 -> Visible = false;                                        // ������ ������� ���������
        SpeedButton4 -> Visible = false;                                        // ������ ������� ���������
    }


    SpeedButton2Click (this);                                                   // �������� ������������ ����� ����


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
    LoadKeyboardLayout (                                                        // �������
        "00000419",
        KLF_ACTIVATE
    );

    FormatSettings.DecimalSeparator = '.';                                      // �������� ����������� ����
    FormatSettings.ShortDateFormat  = "dd.mm.yyyy";                             // �������� ������� ����
}
AnsiString TMainForm::getPartOfSheetNameForEducationType (const int eduTypeCode)
{
    switch (static_cast <EducationTypeCode> (eduTypeCode))
    {
        case EducationTypeCode::INTRAMURAL:
            return
                "�.";
        case EducationTypeCode::EXTRAMURAL:
            return
                "�.";
        default:
            return
                "�.";
    }
}
AnsiString TMainForm::getPartOfSheetNameForStudyPeriod (const int studyPeriod)
{
    switch (static_cast <StudyPeriodCode> (studyPeriod))
    {
        case StudyPeriodCode::FULL:
            return
                "�.";
        case StudyPeriodCode::SHORT_SECOND_COURSE:
            return
                "�.";
        case StudyPeriodCode::SHORT_THIRD_COURSE:
            return
                "�.";
        default:
            return
                "�.";
    }
}
AnsiString TMainForm::getPartOfSheetNameForPayment (const int payment)
{
    switch (static_cast <PaymentCode> (payment))
    {
        case PaymentCode::BUDGET:
            return
                "�.";
        case PaymentCode::BUYERS:
            return
                "�.";
        default:
            return
                "�.";
    }
}
AnsiString TMainForm::getReportName (
        const AnsiString & documentName
    )
{
    return
            documentName                        +
        ", �� "                                 +
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
        ", �� "             +
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
        ", �� "                                  +
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
        ", �� "                                 +
            AnsiToUtf8 (cur_d.CurrentDate ())   +
        ", �� "                                 +
            currentHours                        +
        " �����"                                +
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
        ", �� "                                 +
            courseNumber                        +
        " ���� �� "                             +
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
                    eduType = "�������";
                    payment = "��������";
                }
                else
                {
                    eduType = "�������";
                    payment = "������";
                }
            break;
        case EducationTypeCode::EXTRAMURAL:
                if (price)
                {
                    eduType = "�������";
                    payment = "��������";
                }
                else
                {
                    eduType = "�������";
                    payment = "������";
                }
            break;
    }

    return
        "��������� - ("                         +
            period                              +
        ", "                                    +
            eduType                            +
        ", "                                    +
            payment                             +
        ") ������� - "                          +
            fac1                                +
        " �� "                                  +
            AnsiToUtf8 (cur_d.CurrentDate ())   +
        ".xls";
}
void __fastcall TMainForm::Itog_podano (                                        // ����� '������ ���������' �� ���� �������� ��� ����������
        int edu,                                                                // ��� �������� 0 - �������, 1 - �������
        int n_r,                                                                // ����� ������ ������ �����
        int itog                                                                // �������� ����� 0 - �� ���� �������� 1 - �� ����������
    )
{
    if ( ! itog)
        CellValue (
            "�����:",
            2,
            nom_row
        );
    else
    {
        if (nom_fac != FacultyCode::MSTH)
            CellValue (
                "����� �� ����������:",
                2,
                nom_row
            );
        else
            CellValue (
                "����� �� ���������:",
                2,
                nom_row
            );
    }

    for ( int k = 2;                                                            // ����� �����
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
                CellFormula (                                                   //(=����(([A-Z][0-9]):([A-Z][0-9]-1)))
                    "=����("                        +
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


    CellFormula (                                                               // ����� ������� (=(H1-M1-Q1)/(C1))
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
        CellFormula (                                                           // ������� ��
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
        int alignHType                                                          // 3 - �� ������
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
        int alignHType                                                          // 3 - �� ������
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
            "         status  = 5"          \
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
            "         status  = 5"
        );

    LetterDualListDlg -> Caption =
        "����� ��������� ��� ������ ��������� ("    +
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
            "�� ����� ���������� ��� ������������ " \
            "� �������������� ��������!!!"
        );
    }
}
void __fastcall TMainForm::N10Click (TObject * Sender)                          // ������� ��������� (������� -> ��������)
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

    // V.Exec (Procedure ("AppShow"));                                          // ������! ����� ������ ��� �������, �.�. ���������� ����� ��� ������ ������


    DM -> QSpisoc_Group -> Close ();
    DM -> QSpisoc_Group ->
        ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DM -> QSpisoc_Group -> Open ();


    AnsiString n_gr =
        DM -> QSpisoc_GroupNOM_GROUP -> Value;

    int j    = 1,                                                               // ���������� �����

        rec  =
            DM -> QSpisoc_Group            -> RecordCount,

        spec =
            DM -> QSpisoc_GroupN_SPECIALIZ -> Value;

    V.Exec (                                                                    // ������ ������������ ������
        Procedure ("Bold")   << true
    );
    V.Exec (
        Procedure ("Font")   <<
            AnsiToUtf8 ("Arial") << 24
    );
    V.Exec (
        Procedure ("Insert") <<
            "������ � " +
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

    V.Exec (                                                                    // ���
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
                    "������ � " +
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

    V.Exec (                                                                    // ����� ������������ ������
        Procedure ("AppShow")
    );
}
void __fastcall TMainForm::N14Click (TObject * Sender)
{
    int col_pred =                                                              // ����������� ���-�� �������. ���������
        DM -> TPredmet -> RecordCount;

    DM -> QResult_Exam -> Close ();                                             // ���������� ������ �� ���������
    DM -> QResult_Exam -> Open ();

    DM -> QSpisoc_Group -> Close ();
    DM -> QSpisoc_Group ->
        ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DM -> QSpisoc_Group -> Open ();

    AnsiString n_gr =
        DM -> QSpisoc_GroupNOM_GROUP -> Value;

    int j   = 1;                                                                // ���������� �����

    int rec =                                                                   // ���������� ������� � ������
        DM -> QSpisoc_Group -> RecordCount;

    if (n_gr == "")                                                             // ������������ ������
        return;

    int spec = DM -> QSpisoc_GroupN_SPECIALIZ -> Value;


    ExcelApplication = Variant::CreateObject ("Excel.Application");             // �������� ������� � �������� ���������� �����

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
            "����1"
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


    MergeCellCenter (                                                           // ����� � �����������, ����� �������� � ������� ������
        1,
        7           +
        col_pred,
        2
    );
    CellValue (                                                                 // �������� ����������
        DM -> TFaculty ->
            Lookup (
                "N_FAC",
                nom_fac,
                "FAC"
            ),
        1,
        2
    );


    MergeCellCenter (                                                           // ��� ��������
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


    MergeCellCenter (                                                           // ����� ������
        1,
        7           +
        col_pred,
        5
    );
    CellValue (
        "������ � " +
            n_gr,
        1,
        5
    );


    NameSheet1 (                                                                // �������������� �����
        Sheet,
        n_gr
    );


    Shapka_spisok (col_pred);                                                   // ������� ������������ ����� �������


    MergeCellCenter (                                                           // �������������� ������ ��� ��������� �������������
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

    int nom_stroka = 9;                                                         // ����� ������


    Data_spisok (                                                               // ������� ������ ������ ������������
        col_pred,
        nom_stroka,
        j
    );

    ++nom_stroka;

    for ( int i =  2;                                                           // ������ �� ������������ (� ������ ������ ������ � �������������)
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


                MergeCellCenter (                                               // �������������� ������ ��� ��������� �������������
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
            for ( int i =  1;                                                   // ���������� ������ �������
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


            MergeCellCenter (                                                   // �������� ����������
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


            MergeCellCenter (                                                   // ������ '��� ��������'
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


            MergeCellCenter (                                                   // ������ � '������� ������'
                1,
                7           +
                col_pred,
                5
            );
            CellValue (
                "������ � " +
                    n_gr,
                1,
                5
            );


            Shapka_spisok (col_pred);                                           // '����� �������'


            MergeCellCenter (                                                   // ������ '�������������'
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


    for ( int i =  1;                                                           // ���������� ������ �������
              i <= col_pred + 7;
              ++i
        )
        AutoFitColumn (
            Sheet,
            i
        );


    OVisible (ExcelApplication);                                                // ����������
    DisplayAlert (ExcelApplication);

    WorkSaveAs = SaveBook (Workbook);

    if (nom_pr)
        delete [] nom_pr;

    DM -> QResult_Exam -> Close ();
}
void __fastcall TMainForm::N15Click (TObject * Sender)                          // ����������  ->  ���-�� �������� ��������� (����������)
{
    int k;                                                                      // ���������� ��� ���������� �����
        nom_row = 8;                                                            // ������� �����

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
            "����1"
        );

    DisplayAlert (ExcelApplication);                                            // ������� ������� Excela �� ������������� ��������


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

    // OVisible (ExcelApplication);                                             // ������! ������ ��� �������, �.�. ���������� �����

    CellValue (                                                                 // ����� �������� ����������
        DM -> TFaculty ->
            Lookup (
                "N_FAC",
                nom_fac,
                "FAC"
            ),
        1,
        1
    );
    CellValue (                                                                 // ����� ���� � �������
        cur_d.CurrentDateTime (),
        7,
        3
    );


    int kc_kol,                                                                 // �������� ����������� �����
        kc_kol_fin,
        n_r;                                                                    // ������ ����������

    for ( int edu = 0;                                                          // ������ �� ����� ��������: 0 - �������, 1 - �������
              edu < 2;
              ++edu
        )
    {
        int cel_kol = 0;                                                        // ���������� ��� ���������� ���������

        DM -> QStatisticEveryDay -> Close ();
        DM -> QStatisticEveryDay ->                                             // ����� ����������
            ParamByName ("N_FAC")   -> AsInteger = nom_fac;
        DM -> QStatisticEveryDay ->                                             // ����� ��������
            ParamByName ("VID_EDU") -> AsInteger = edu;
        DM -> QStatisticEveryDay -> Open ();

        col_rec =
            DM -> QStatisticEveryDay -> RecordCount;

        if (edu)
            CellValue (
                "������� ����� ��������� �����������",
                1,
                nom_row
            );
        else
            CellValue (
                "������� ����� ��������� �����������",
                1,
                nom_row
            );

        MergeCellCenter (
            1,
            19,
            nom_row++
        );

        n_r = nom_row;                                                          // ���������� ��� ������ ����������

        for ( int n_rec = 0;
                  n_rec < col_rec;
                  ++n_rec
            )
        {
            if (DM -> QStatisticEveryDaySUM -> Value != 0)
            {
                spec = DM -> QStatisticEveryDayN_SPECIALIZ -> Value;            // ����� �� �������

                CellValue (                                                     // ����� ������� �������� ����������� �������������
                    n_rec + 1,
                    1,
                    nom_row
                );
                CellValue (                                                     // ����� ������� �������� ����������� �������������
                    DM -> QStatisticEveryDaySPECIALIZ2 -> Value,
                    2,
                    nom_row
                );


                DM -> QPlanPriemPrice -> Close ();                              // �� ������
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


                kc_kol = DM -> QPlanPriemPriceKOL_PLACE -> Value;               // ��


                DM -> QPlanPriemPrice -> Close ();                              // �� ���������
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

                    //kc_kol_fin +=                                               // ��
                    //     DM -> QPlanPriem2PriceKOL_PLACE -> Value;

                    DM -> QPlanPriem2Price -> Close ();
                }

                CellValue (
                    kc_kol_fin,
                    6,
                    nom_row
                );

                DM -> QPlanPriemPrice -> Close ();


                DM -> QCK_Kol_Plan -> Close ();                                 // ���� ���������
                //DM -> QCK_Kol_Plan ->
                //    ParamByName ("N_FAC")       -> AsInteger = nom_fac;
                DM -> QCK_Kol_Plan ->
                    ParamByName ("N_SPECIALIZ") -> AsInteger = spec;
                DM -> QCK_Kol_Plan -> Open ();


                cel_kol = 0;                                                    // ��������� ��������� ����� ���������

                if (edu == 0)                                                   // ���������� ��������� �� ����� (������ �������)
                {
                    cel_kol = DM -> QCK_Kol_PlanKOL_PLACE -> Value;

                    if (cel_kol)
                        CellValue (
                            cel_kol,
                            5,
                            nom_row
                        );
                }


                //if (    nom_fac != 4                                            // ��������� �� ��� ���������
                    // && edu     != 1
                //   )
                //{
                    kc_kol -= cel_kol;                                          // �� ��� ���������

                    if(kc_kol)
                        CellValue (
                            kc_kol,
                            4,
                            nom_row
                        );
                //}


                CellFormula (                                                   // ����� ����� �� ����� � ���������� � ����������� (=����(D1:F1))
                    "=����(D"                   +
                        AnsiString (nom_row)    +
                    ":F"                        +
                        AnsiString (nom_row)    +
                    ")",
                    3,
                    nom_row
                );


                DM -> StoredProcKolk_Konk1 -> Close ();                         // ��������� ������� ��������� �� ����������
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
                if (cel_kol)                                                    // ������,�����
                        CellValue (
                            cel_kol,
                            7,
                            nom_row
                        );

                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_CEL") -> AsInteger;
                if (cel_kol)                                                    // ��������
                        CellValue (
                            cel_kol,
                            8,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_2_0") -> AsInteger;
                if (cel_kol)                                                    // ������,����������
                        CellValue (
                            cel_kol,
                            9,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_VK_0") -> AsInteger;
                if (cel_kol)                                                    // ������,��
                        CellValue (
                            cel_kol,
                            10,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_WO_0") -> AsInteger;
                if (cel_kol)                                                    // ���
                        CellValue (
                            cel_kol,
                            11,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_ALL_1") -> AsInteger;
                if (cel_kol)                                                    // ������,�����
                        CellValue (
                            cel_kol,
                            12,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_2_1") -> AsInteger;
                if (cel_kol)                                                    // ������,����������
                        CellValue (
                            cel_kol,
                            13,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_VK_1") -> AsInteger;
                if (cel_kol)                                                    // ������ ��
                        CellValue (
                            cel_kol,
                            14,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_WO_1") -> AsInteger;
                if (cel_kol)                                                    // ������ ���
                        CellValue (
                            cel_kol,
                            15,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_ING") -> AsInteger;
                if (cel_kol)                                                    // ������,����������
                        CellValue (
                            cel_kol,
                            16,
                            nom_row
                        );


                cel_kol =
                    DM -> StoredProcKolk_Konk1 ->
                        ParamByName ("S_2V") -> AsInteger;
                if (cel_kol)                                                    // ������,2 ����
                        CellValue (
                            cel_kol,
                            17,
                            nom_row
                        );

                DM -> StoredProcKolk_Konk1 -> Unprepare ();
                DM -> StoredProcKolk_Konk1 -> Close ();

                CellFormula (                                                   // ����� ����� ������� ��������� (=����(G1:Q1))
                    "=����(G"                   +
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


        CellValue (                                                             // ����� ��� ������ ��������
            "�����:",
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


        CicleSum (                                                              // ������������ � 3 �� 17 �������
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
        CellFormula (                                                           // ����� ����� ������� ��������� (=����(G1:Q1))
            "=����(G"                   +
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

        for ( int i = 1;                                                        // ���������� ���������� �����
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
            "����� �� ����������: ",
            2,
            nom_row
        );
    else
        CellValue (
            "����� �� ���������: ",
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
    CellFormula (                                                               // ����� ����� ������� ��������� (=����(G1:Q1))
        "=����(G"                   +
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
        "������������� ��������� �������� �������� ",
        2,
        ++nom_row
    );
    CellValue (
        LegallyAuthorizedPerson::SECRETARY,
        7,
        nom_row
    );

    WorkSaveAs = SaveBook (Workbook);                                           // ����������
    OVisible (ExcelApplication);                                                // ���������� ������ Excel

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
void __fastcall TMainForm::N17Click (TObject * Sender)                          // ���������� ����������� ���������
{
    DM -> QLittle_Spisoc_GR -> Close ();
    DM -> QLittle_Spisoc_GR ->
        ParamByName ("FAC") -> AsString = nom_fac;
    DM -> QLittle_Spisoc_GR -> Open ();

    if (DM -> QLittle_Spisoc_GR -> RecordCount)
    {
        Dop_ResultForm = new TDop_ResultForm (this);                            // ����� ���������� ����� ����������� �������� ���

        Dop_ResultForm -> ShowModal ();
    }
    else                                                                        // ����� ����� ������ ���
    {
        ShowMessage (
            "�� ����� ���������� ��� ������������, "    \
            "������� ���� ��������� ������ ����"
        );
    }
}
void __fastcall TMainForm::N21Click (TObject * Sender)                          // (CAN'T OPERATE!!!!) ����� 2 (���������� ��������� � ���������� ���������)
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
            "����� 2"
        );

    DMStat -> QSpecial -> Open ();


    int rec_spec = DMStat -> QSpecial -> RecordCount;


    for ( int k = 0;                                                            // ???? WHY ????
              k < 2;
              ++k
        )
        mas_spec_str[k] = new int[rec_spec];


    for ( int i = 0;                                                            // ������ �� ��������������
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


    DMStat -> QF2_All_Sdal ->                                                   // ������� �������� (��� ����� � ����� �������������) (����������� (0), �����.������ (2), ������ ���-�� �� ����� ��� (4) � ����������� (5))
        ParamByName ("V_E") -> AsInteger = 0;                                   // ������ �������
    DMStat -> QF2_All_Sdal -> Open ();

    for ( int j = 0;                                                            // ����� ���������� ��������� ������������� ��������
              j < DMStat -> QF2_All_Sdal -> RecordCount;                        // for ������� ������������� ��������
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


    DMStat -> QF2_Sdal ->                                                       // ��������� ������������� �������� (��� ����� ������������ � ����� �������������) ����������� (0) � ����������� (5)
        ParamByName ("V_E") -> AsInteger = 0;                                   // ������ �������
    DMStat -> QF2_Sdal -> Open ();

    for ( int j = 0;                                                            // for ��������� ������������� ��������
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


    DMStat -> QCount_Medal ->                                                   // ��������� ����, ������� �������� ������������� ������
        ParamByName ("ST")  -> AsInteger = 2;
    DMStat -> QCount_Medal ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Medal -> Open ();

    for ( int j = 0;                                                            // ������ ���-�� ���������� ����� � ������� � ���������� "2"
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


    DMStat -> QF2_Zach ->                                                       // ����� ����������� �� ������
        ParamByName ("V_E") -> AsInteger = 0;                                   // ������ �������
    DMStat -> QF2_Zach -> Open ();

    for ( int j = 0;                                                            // for ����� ����������� �� ������
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


    DMStat -> QCount_PO ->                                                      // ������ ��
        ParamByName ("ST") -> AsInteger = 5;
    DMStat -> QCount_PO -> Open ();

    for ( int j = 0;                                                            // ������ ���-�� ���������� ��
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

    for ( int j = 0;                                                            // ������ ���-�� � �� (�� ������� ����� ��������)
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


    DMStat -> QCount_Medal -> Close ();                                         // ��������� ����, ������� ���������
    DMStat -> QCount_Medal ->
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Medal ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Medal -> Open ();

    for ( int j = 0;                                                            // ������ ���-�� ���������� ����� � �������
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


    DMStat -> QCount_Diplom ->                                                  // ������� � ��������,������� ���������
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Diplom ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Diplom -> Open ();

    for ( int j = 0;                                                            // ������ ���-�� ���������� ���� � �.�. � ��������
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


    AnsiString SQL1 =                                                           // ������ ����������� ��� ��������� (�.21 ������ ������)
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

    SQL2 =                                                                      // ���������� � ������� ����. ���� � ������, ��������� ����������� ��� (Wo = 1 ��� 2)
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

    for ( int j = 0;                                                            // ������ ���-�� ����������� � �������� ����. ���� � ������, ��������� ����������� ���
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


    SQL2 =                                                                      // �������� ������ ���������� �� (Wo = 3)
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

    for ( int j = 0;                                                            // for �������� ������ ���������� ��
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


    DMStat -> QCount_Gimn ->                                                    // ��������� ������ � ��������
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Gimn ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Gimn -> Open ();

    for ( int j = 0;                                                            // ������ ���-�� ���������� ����� ��� ��������
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


    DMStat -> QCount_Gorod -> Close ();                                         // ���������� �������� ���������� ����������� - ����
    DMStat -> QCount_Gorod ->
        ParamByName ("N")   -> AsString   = "4";                                // ��������
    DMStat -> QCount_Gorod ->
        ParamByName ("ST")  -> AsSmallInt = 5;
    DMStat -> QCount_Gorod ->
        ParamByName ("EDU") -> AsSmallInt = 0;
    DMStat -> QCount_Gorod ->
        ParamByName ("GOD") -> AsString   = "%";
    DMStat -> QCount_Gorod -> Open ();

    for ( int j = 0;                                                            // ������ ���-�� ���������� �������� ��
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


    DMStat -> QCount_Gorod -> Close ();                                         // ���������� �������� ���������� ����������� - ������ �������� ����
    DMStat -> QCount_Gorod ->
        ParamByName ("N")   -> AsString   = "4";                                // ��������
    DMStat -> QCount_Gorod ->
        ParamByName ("ST")  -> AsSmallInt = 5;
    DMStat -> QCount_Gorod ->
        ParamByName ("EDU") -> AsSmallInt = 0;
    DMStat -> QCount_Gorod ->
        ParamByName ("GOD") -> AsString   = "2006";
    DMStat -> QCount_Gorod -> Open ();

    for ( int j = 0;                                                            // ���������� ���������� ������������,���������� �������� ��
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


    DMStat -> QCount_Gorod -> Close ();                                         // ���������� ��������� ���������� ����������� - ����
    DMStat -> QCount_Gorod ->
        ParamByName ("N")   -> AsString   = "5";                                // ���������
    DMStat -> QCount_Gorod ->
        ParamByName ("ST")  -> AsSmallInt = 5;
    DMStat -> QCount_Gorod ->
        ParamByName ("EDU") -> AsSmallInt = 0;
    DMStat -> QCount_Gorod ->
        ParamByName ("GOD") -> AsString   = "%";
    DMStat -> QCount_Gorod -> Open ();

    for ( int j = 0;                                                            // ���������� ���������� ������������,���������� ��������� ��
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


    DMStat -> QCount_Gorod -> Close ();                                         // ���������� ��������� ���������� ����������� - ������ �������� ����
    DMStat -> QCount_Gorod ->
        ParamByName ("N")   -> AsString   = "5";                                // ���������
    DMStat -> QCount_Gorod ->
        ParamByName ("ST")  -> AsSmallInt = 5;
    DMStat -> QCount_Gorod ->
        ParamByName ("EDU") -> AsSmallInt = 0;
    DMStat -> QCount_Gorod ->
        ParamByName ("GOD") -> AsString   = "2006";
    DMStat -> QCount_Gorod -> Open ();

    for ( int j = 0;                                                            // ���������� ���������� ������������,���������� ��������� ��
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


    DMStat -> QCount_Stag ->                                                    // ���� ����� 2-� ���
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Stag ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Stag -> Open ();

    for ( int j = 0;                                                            // ������ ���-�� ������� ���� ����� 2-� ���
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


    DMStat -> QCount_Region ->                                                  // �������� ��, ����������, ����������, ������������
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Region ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Region -> Open ();

    for ( int j = 0;                                                            // ������ ���-�� �� ������ ���������
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


    DMStat -> QCount_Test ->                                                    // ����������� ����������������� ������������ �� = 3 (� 2003 ������, � 2006 - 2 ���-�� ����������� + 1)
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_Test ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_Test -> Open ();

    for ( int j = 0;                                                            // ������ ���-�� �� ������� ��
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


    DMStat -> QF2_Sdal -> Close ();                                             // ��������� �� ��������� � ������ ���� (����������� (5))
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
        ParamByName ("V_E") -> AsInteger = 0;                                   // �������
    DMStat -> QF2_Sdal -> Open ();

    for ( int j = 0;                                                            // ��������� �� ��������� � ������ ����
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


    DMStat -> QCount_RUOR ->                                                    // �� ����������� ���� �������� (2 ���� - ����)
        ParamByName ("ST")  -> AsInteger = 5;
    DMStat -> QCount_RUOR ->
        ParamByName ("EDU") -> AsInteger = 0;
    DMStat -> QCount_RUOR -> Open ();

    for ( int j = 0;                                                            // ������ ���-�� �� 2 ����
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
void __fastcall TMainForm::N22Click (TObject * Sender)                          // ������� ��������� (������� -> ������)
{
    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N23Click (TObject * Sender)                          // ������������ ����������� ���������
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
            "������������ ����������� ������ �������!"
        );
    }
    catch (...)
    {
        ShowMessage (
            "� ���������� ������������ ��������� "  \
            "������.\n��������� ������������!"
        );
    }
}
void __fastcall TMainForm::N26Click (TObject * Sender)                          // ������������ ������� ��������� ��� 2 �����
{
    AnsiString k_f      = "",                                                   // ����� �����
               n_file   = "";                                                   // �������� ������������� �����

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
                "����1"
            );

        // OVisible (ExcelApplication);

        CellValue (
            fac1,
            3,
            6
        );

        DMVed -> QPredm -> Close ();
        DMVed -> QPredm -> Open ();

        int rec_pred = 3;                                                       // ���������� ���������

        mas_pr   = new AnsiString[rec_pred];                                    // �������� ���������

        mas_pr[0] =
            "����������� (�������) ����";

        CellValue (
            "���. (���.) ��",
            9,
            12
        );


        if (nom_fac == FacultyCode::RPC)
        {
            mas_pr[2] =
                "���������� �������� � �����";

            CellValue (
                "����",
                11,
                12
            );

            mas_pr[1] =
                "������ ������ � �������� ���������� ����������";

            CellValue (
                "������",
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
                "���������� �������� � �����";

            CellValue (
                "����",
                11,
                12
            );

            mas_pr[1] =
                "������ ������ � �������� ���������� ����������";

            CellValue (
                "������",
                10,
                12
            );

            k_f = "2";
        }


        if (nom_fac == FacultyCode::MSTH)
        {
            mas_pr[2] =
                "���������� � �������";

            CellValue (
                "������. � ���.",
                11,
                12
            );


            mas_pr[1] =
                "���������������";

            CellValue (
                "���������.",
                10,
                12
            );

            k_f = "2";
        }


        DM -> QSpecializ -> Close ();
        DM -> QSpecializ -> Open ();


        for ( int j = 0;                                                        // ������ �� ���� ��������
                  j < 2;
                  ++j
            )
        {
            for ( int k = 0;                                                    // ������ �� ����� ������
                      k < 2;
                      ++k
                )
            {
                DM -> QSpecializ -> First ();

                int rec_special = DM -> QSpecializ -> RecordCount;

                for ( int i = 0;                                                // ������ �� ��������������
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

                    if (rec_q_two_kurs)                                         // ����� ��������� ������ � Excel
                    {
                        Sheet =
                            SelectSheet (
                                Workbook,
                                "����1"
                            );

                        CopySheet (Sheet);

                        Sheet =
                            SelectSheet (
                                Workbook,
                                "����1 (2)"
                            );

                        AnsiString //cod_specializ1 = "1-88 02 01-01 ";
                        cod_specializ1 = NCRB_011::_2022::CODE::PHYSICAL_CULTURE;// + " ",

                        switch (DM -> QSpecializN_SPECIALIZ -> Value)           // �������������
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
                                    vid = "�� ";

                                    CellValue (
                                        "�������",
                                        3,
                                        8
                                    );
                                break;
                            case 1:
                                    vid = "���� ";

                                    CellValue (
                                        "�������",
                                        3,
                                        8
                                    );
                        }

                        switch (k)
                        {
                            case 0:
                                    pr = "";

                                    CellValue (
                                        "�� ���� ������� ���������������� " \
                                        "�������",
                                        3,
                                        9
                                    );
                                break;
                            case 1:
                                    pr = " ��� ";

                                    CellValue (
                                        "�� ������� ������",
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
                            Svod_ved (                                          // ������� ������������ ������� ���������
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
                "����1"
            );
        CellValue (
            "�����",
            3,
            6
        );


        DMVed -> QPredm -> Close ();                                            // ��������� �������� ���������
        DMVed -> QPredm -> Open ();


        int rec_pred = 3;                                                       // ���������� ���������

        mas_pr = new AnsiString[rec_pred];

        mas_pr[0] = "����������� (�������) ����";

        CellValue (
            "���. (���.) ��",
            9,
            12
        );


        mas_pr[2] = "���������� � �������";

        CellValue (
            "������. � ���.",
            11,
            12
        );


        mas_pr[1] = "���������������";

        CellValue (
            "���������.",
            10,
            12
        );


        DMVed -> QKonkurs -> Close ();                                          // �������
        DMVed -> QKonkurs ->
            ParamByName ("IN_SP")      -> Value = 61;
        DMVed -> QKonkurs ->
            ParamByName ("IN_VID_EDU") -> Value = 0;
        DMVed -> QKonkurs ->
            ParamByName ("IN_KONK")    -> Value = 1;
        DMVed -> QKonkurs ->
            ParamByName ("IN_PRICE")   -> Value = 1;
        DMVed -> QKonkurs -> Open ();

        int nom_str1        = 13,                                               // ��������� ���������� ��� ������ ������ � Excel
            rec_q_two_kurs1 = DMVed -> QKonkurs -> RecordCount;

        if (rec_q_two_kurs1)
        {
            Sheet =
                SelectSheet (
                    Workbook,
                    "����1"
                );
            CopySheet (Sheet);
            Sheet =
                SelectSheet (
                    Workbook,
                    "����1 (2)"
                );
            CellValue (
                //"1-89 01 01 ������ � �������������",
                    NCRB_011::_2022::CODE::TOURISM  +
                " "                                 +
                    NCRB_011::_2022::NAME::TOURISM,
                3,
                7
            );

            AnsiString vid = "�� ",
                       pr  = " ��� ";

            CellValue (
                "�������",
                3,
                8
            );
            CellValue (
                "�� ������� ������",
                3,
                9
            );

            AnsiString sp1 =
                vid                         +
                pr                          +
                "������ � ��������������";

            NameSheet1 (
                Sheet,
                sp1
            );
            nom_str1 =
                Svod_ved (                                                      // ������� ������������ ������� ���������
                    nom_str1,
                    2,
                    0,
                    rec_pred,
                    1,
                    1
                );
        }


        DMVed -> QKonkurs -> Close ();                                          // �������
        DMVed -> QKonkurs ->
            ParamByName ("IN_SP")      -> Value = 61;
        DMVed -> QKonkurs ->
            ParamByName ("IN_VID_EDU") -> Value = 1;
        DMVed -> QKonkurs ->
            ParamByName ("IN_KONK")    -> Value = 2;
        DMVed -> QKonkurs ->
            ParamByName ("IN_PRICE")   -> Value = 1;
        DMVed -> QKonkurs -> Open ();

        int nom_str2        = 13,                                               // ��������� ���������� ��� ������ ������ � Excel
            rec_q_two_kurs2 = DMVed -> QKonkurs -> RecordCount;

        if (rec_q_two_kurs2)
        {
            Sheet =
                SelectSheet (
                    Workbook,
                    "����1"
                );
            CellValue (
                //"1-89 01 01 ������ � �������������",
                    NCRB_011::_2022::CODE::TOURISM  +
                " "                                 +
                    NCRB_011::_2022::NAME::TOURISM,
                3,
                7
            );

            AnsiString vid = "� ",
                       pr  = " ��� ";

            CellValue (
                "�������",
                3,
                8
            );
            CellValue (
                "������� ������",
                3,
                9
            );

            AnsiString sp1 =
                vid                         +
                pr                          +
                "������ � ��������������";

            NameSheet1 (
                Sheet,
                sp1
            );
            nom_str2 =
                Svod_ved (                                                      // ������� ������������ ������� ���������
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
void __fastcall TMainForm::N27Click (TObject * Sender)                          // ������� ��������� (������ -> ������)
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
void __fastcall TMainForm::N30Click (TObject * Sender)                          // (CAN'T OPERATE!!!!) ������ ��������� �� ��������
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
            "����1"
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


    CellValue (                                                                 // ��������� � ����
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

    for ( int i = 0;                                                            // ���� �� ���� ��������
              i < 2;
              ++i
        )
    {
        if (!i)
            CellValue (
                "������� ���������",
                1,
                nom_row
            );
        else
            CellValue (
                "������� ���������",
                1,
                nom_row
            );

        MergeCellCenter (
            1,
            46,
            nom_row++
        );

        n_r = nom_row;


        DMStat -> QRegion_Stat -> Close ();                                     // ���������� ������������ �� �������� (��� 2-�� �����)
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
            AllCount_spec (0);                                                  // ��������� ������������ �� ������������� (0 - ���� �� ��������� � �/� � ��������������)

            DM -> QPlan_Priem_Konk -> Close ();                                 // ���������� ���� �� ������� ��������
            DM -> QPlan_Priem_Konk ->
                ParamByName ("N_FAC")   -> AsInteger = nom_fac;
            DM -> QPlan_Priem_Konk ->
                ParamByName ("VID_EDU") -> AsInteger = i;
            DM -> QPlan_Priem_Konk ->
                ParamByName ("N_SP")    -> AsInteger = spec;
            DM -> QPlan_Priem_Konk -> Open ();

            for ( int s = 0;                                                    // ������ �� ������ ��������� ������������� (������� � KOL_PLACE)
                      s < DM -> QPlan_Priem_Konk -> RecordCount;
                      ++s
                )
            {
                switch (DM -> QPlan_Priem_KonkTEXT -> Value)
                {
                    case 0:                                                     // �����
                        if (DM -> QPlan_Priem_KonkKOL_PLACE -> Value)
                            CellFormula (                                       // ��������������� �������� ��������� �� �����
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
                    case 1:                                                     // ����
                        break;
                    case 2:                                                     // ��
                            CellValue (
                                DM -> QPlan_Priem_KonkKOL_PLACE -> Value,
                                5,
                                nom_row
                            );
                        break;
                    case 3:                                                     // �� ������
                            CellValue (
                                DM -> QPlan_Priem_KonkKOL_PLACE -> Value,
                                6,
                                nom_row
                            );
                        break;
                }

                DM -> QPlan_Priem_Konk -> Next ();
            }


            int c = 0;                                                          // ������ �������, ���� �������� ���-�� �������� ���������

            while (DMStat -> QRegion_StatN_SPECIALIZ -> Value == spec)          // ������ �� �������� � ���������
            {
                switch (DMStat -> QRegion_StatN_REGION -> Value)                // ����� �������
                {
                    case 1:                                                     // �.�����
                            switch (DMStat -> QRegion_StatKONKURS -> Value)
                            {
                                case 0:                                         // 0 - �����
                                        c = 7;
                                    break;
                                // case 1:                                         // 1 - ����
                                //     break;
                                // case 2:                                         // 2 - ��
                                //     break;
                                // case 3:                                         // 3 - 2 ���� (� ���� ���������� �� ������������)
                                //     break;
                                case 4:                                         // 4 - �� ������
                                        c = 9;                                  // c = 8;
                                    break;
                                case 5:                                         // 5 - ��� ���������
                                        c = 10;                                 // c = 9;
                                    break;
                            }
                        break;
                    case 2:                                                     // ������� �������
                            if (DMStat -> QRegion_StatKONKURS -> Value != 3)
                                c =
                                    10                                      +
                                    DMStat -> QRegion_StatKONKURS -> Value;
                        break;
                    case 3:                                                     // ��������� ���.
                            if (DMStat -> QRegion_StatKONKURS -> Value != 3)
                                c =
                                    15                                      +
                                    DMStat -> QRegion_StatKONKURS -> Value;
                        break;
                    case 4:                                                     // ���������� ���.
                            if (DMStat -> QRegion_StatKONKURS -> Value != 3)
                                c =
                                    20                                      +
                                    DMStat -> QRegion_StatKONKURS -> Value;
                        break;
                    case 5:                                                     // ����������� ���.
                            if (DMStat -> QRegion_StatKONKURS -> Value != 3)
                                c =
                                    25                                      +
                                    DMStat -> QRegion_StatKONKURS -> Value;
                        break;
                    case 6:                                                     // ��������� ���.
                            if (DMStat -> QRegion_StatKONKURS -> Value != 3)
                                c =
                                    30                                      +
                                    DMStat -> QRegion_StatKONKURS -> Value;
                        break;
                    case 7:                                                     // ����������� ���.
                            if (DMStat -> QRegion_StatKONKURS -> Value != 3)
                                c =
                                    35                                      +
                                    DMStat -> QRegion_StatKONKURS -> Value;
                        break;
                    case 8:
                            c = 40;                                             // ������ ����������
                        break;
                }


                if (    DMStat -> QRegion_StatN_REGION -> Value != 8            // ��-�� �������� 2-�� ����� ������� 4-5 ��������� �� 1
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


            CellFormula (                                                       // ����� (�����) �� ������
                "=����(G"   +
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

            CellFormula (                                                       // ����� (�����) �� ����
                "=����(K"   +
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


            if (all_selo)                                                       // ������ ���� ��� �������
            {
                CellFormula (
                    "=�����������(((B"          +
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


            CellFormula (                                                       // �� ��
                "=����(L"       +
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

            CellFormula (                                                       // �� ��������: �� ������
                "=����(H"       +
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

            CellFormula (                                                       // �� ��������: ��� ���������
                "=����(I"       +
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

            CellFormula (                                                       // ����� (����� + ���� + �� + ��� ���������+�� ������ + ��.����������)
                "=����(AN"      +
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


        for ( int i = 1;                                                        // ���������� ���� �����
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
            "�����:",
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
        "����� �� �-��:",
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
        "������������� ��������� �������� ��������:",
        1,
        nom_row + 2
    );
    CellValue (
        LegallyAuthorizedPerson::SECRETARY,
        21,
        nom_row + 2
    );

    WorkSaveAs = SaveBook (Workbook);                                           // ����������
}
void __fastcall TMainForm::N31Click (TObject * Sender)                          // ����� 3 (������� � �������) (CAN'T OPERATE!!!!)
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
            "�������"
        );

    int vid_educ;                                                               // ���������� ���� ��������

    for ( vid_educ = 0;                                                         // ���� ��� �������� � �������� ��������
          vid_educ < 2;
          ++vid_educ
        )
    {
        if (vid_educ)                                                           // �������
            Sheet =
                SelectSheet (
                    Workbook,
                    "�������"
                );

        DMStat -> QSpecial -> Open ();


        int rec_spec = DMStat -> QSpecial -> RecordCount;


        for ( int k = 0;
                  k < 2;
                  ++k
            )
            mas_spec_str[k] = new int[rec_spec];


        for ( int i = 0;                                                        // ������ ��������������
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


        DMStat -> QF2_All_Sdal ->                                               // ������� ������������� �������� (����������� (0), �����.������ (2), ������ ���-�� �� ����� ��� (4) � ����������� (5))
            ParamByName ("V_E") -> AsInteger = vid_educ;
        DMStat -> QF2_All_Sdal -> Open ();


        for ( int j = 0;                                                        // ����� ���������� ��������� ������������� ��������
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


        DMStat -> QF2_Sdal ->                                                   // ��������� ������������� �������� (����������� (0) � ����������� (5))
            ParamByName ("V_E") -> AsInteger = vid_educ;
        DMStat -> QF2_Sdal -> Open ();

        for ( int j = 0;                                                        // for ��������� ������������� ��������
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


        DMStat -> QF2_Zach -> Close ();                                         // ����� 3 (����� �� 4+�� 5) ����� �����������
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
        DMStat -> QF2_Zach ->                                                   // ����� ����������� (������� ��� �������)
            ParamByName ("V_E") -> AsInteger = vid_educ;
        DMStat -> QF2_Zach -> Open ();

        for ( int j = 0;                                                        // for ����� �����������
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


        DMStat -> QF2_Zach -> Close ();                                         // ����� 4 �� ����� ������
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
        DMStat -> QF2_Zach ->                                                   // ����� ����������� �� ������ (������� ��� �������)
            ParamByName ("V_E") -> AsInteger = vid_educ;
        DMStat -> QF2_Zach -> Open ();

        for ( int j = 0;                                                        // for ����� ����������� �� ������
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


        DMStat -> QF2_Zach -> Close ();                                         // ����� 5  ����������� �� ������
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


        DMStat -> QF2_Zach ->                                                   // ����� �����������  �� ������ (������� ��� �������)
            ParamByName ("V_E") -> AsInteger = vid_educ;
        DMStat -> QF2_Zach -> Open ();


        for ( int j = 0;                                                        // for ����� �����������  �� ������
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


        if ( ! vid_educ)                                                        // ������ ��� ������� ����� �������� (������ ��)
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


            for ( int j = 0;                                                    // ���������� ���������� ������������, ���������� ��
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


        DMStat -> QCount_Medal -> Close ();                                     // ����� 7 (��������� ����, ������� ���������)
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


        for ( int j = 0;                                                        // ������ ���-�� ���������� ����� � ������� (���������)
                  j < DMStat -> QCount_Medal -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_MedalCOUNT -> Value,
                    9,
                    Find_nom_spec_str (
                        DMStat -> QCount_MedalN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_Diplom -> Close ();                                    // ����� 8 ������� � ��������, ������� ���������
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


        for ( int j = 0;                                                        // ������ ���������� ���������� ���� � �.�. � ��������
                  j < DMStat -> QCount_Diplom -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_DiplomCOUNT -> Value,
                    10,
                    Find_nom_spec_str (
                        DMStat -> QCount_DiplomN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        if ( ! vid_educ)                                                        // ����� 9  ��������� ������ � �������� (������ �������)
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


            for ( int j = 0;                                                    // ������ ���-�� ���������� ����� ��� ��������
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
        else                                                                    // ������ ������� �.21 ������������
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


        AnsiString SQL_Gorod =                                                  // ���������� �������� ���������� ����������� - ����
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
            ParamByName ("N")   -> AsString   = "4";                        // ��������
        DMStat -> QCount_Gorod ->
            ParamByName ("ST")  -> AsSmallInt = 5;
        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;
        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "%";

        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // ������ ���-�� ���������� �������� ��
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    12,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_Gorod -> Close ();                                     // ���������� �������� ���������� ����������� - ������ �������� ����
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add
                (
                    SQL_Gorod
                );

        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "4";                            // ��������

        DMStat -> QCount_Gorod ->
            ParamByName ("ST")  -> AsSmallInt = 5;

        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;

        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "2006";

        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // ������ ���-�� ���������� �������� ��
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    13,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_Gorod -> Close ();                                     // ���������� ��������� ���������� ����������� - ����
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add
                (
                    SQL_Gorod
                );


        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "5";                            // ���������

        DMStat -> QCount_Gorod ->
            ParamByName ("ST")  -> AsSmallInt = 5;

        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;

        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "%";

        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // ������ ���-�� ���������� ��������� ��
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    14,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_Gorod -> Close ();                                     // ���������� ��������� ���������� ����������� - ������ �������� ����
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add
                (
                    SQL_Gorod
                );


        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "5";                            // ���������

        DMStat -> QCount_Gorod ->
            ParamByName ("ST")  -> AsSmallInt = 5;

        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;

        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "2006";

        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // ���������� ���������� ������������, ���������� ��������� ��
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    15,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_Stag -> Close ();                                      // ���� ����� 2-� ���
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


        for ( int j = 0;                                                        // ���������� ���������� ������������,������� ���� ����� 2-� ���
                  j < DMStat -> QCount_Stag -> RecordCount;
                  ++j
                  )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_StagCOUNT -> Value,
                    16,
                    Find_nom_spec_str (
                        DMStat -> QCount_StagN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        if ( ! vid_educ)                                                        // if ������ �������
        {
            DMStat -> QCount_Region -> Close ();                                // �������� ��, ����������, ����������, ������������
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
                        "         gragdan  <> '��'"                 \
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


            for ( int j = 0;                                                    // ���������� ���������� ������������ �� ������ ���������
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
        else                                                                    // ������ �������
        {
            DMStat -> QCount_High -> Close ();                                  // ��� ��������� ������� ������� �����������
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


            for ( int j = 0;                                                    // ���������� ���������� ������������ �� 2-�� ������
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


        DMStat -> QCount_Test -> Close ();                                      // ����������� ����������������� ������������ �� = 3
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


        for ( int j = 0;                                                        // ���������� ���������� ������������ �� ������� �� = 3
                  j < DMStat -> QCount_Test -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_TestCOUNT -> Value,
                    17,
                    Find_nom_spec_str (
                        DMStat -> QCount_TestN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QF2_Sdal -> Close ();                                         // ��������� �� ��������� � ������ ���� (����������� (5))
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


        for ( int j = 0;                                                        // for  ��������� �� ��������� � ������ ����
                  j < DMStat -> QF2_Sdal -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QF2_SdalCOUNT -> Value,
                    18,
                    Find_nom_spec_str (
                        DMStat -> QF2_SdalN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QF2_Sdal -> Close ();                                         // ��������� �� ��������� � ������ ���� (����������� (5))
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


        for ( int j = 0;                                                        // ��������� �� ��������� � ������ ���� (������� ��� �������)
                  j < DMStat -> QF2_Sdal -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QF2_SdalCOUNT -> Value,
                    19,
                    Find_nom_spec_str (
                        DMStat -> QF2_SdalN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_RUOR -> Close ();                                      // �� ����������� ���� �������� (2 ���� - ����, 3 ���� - ����� (� 2005))
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


        for ( int j = 0;                                                        // ���-�� ������������ �� 2 ���� ����
                  j < DMStat -> QCount_RUOR -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_RUORCOUNT -> Value,
                    20,
                    Find_nom_spec_str (
                        DMStat -> QCount_RUORN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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
        "����� - ����� 3 �� "                   +
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
void __fastcall TMainForm::N32Click (TObject * Sender)                          // ����� ������ ��������� (��������)
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
            "����1"
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


    CellValue (                                                                 // ��������� � ����
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
    int n_r;                                                                    // ���������� ��� ������������ �����

    for ( int i = 0;                                                            // for �� ���� ��������
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
                "������� ����� ��������� �����������",
                1,
                nom_row
            );
        else
            CellValue (
                "������� ����� ��������� �����������",
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

        Itog_podano (                                                           // ����� �� ���� ��������
            i,
            n_r,
            0
        );

        ++nom_row;


        for ( int i =  1;                                                       // ���������� ���������� �����
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

    Itog_podano (                                                               // ����� �� ����������
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
        "������������ ������������� ��������  ",
        2,
        nom_row
    );

    AnsiString dec_f = "";

    switch (nom_fac)                                                            // ����� ����������
    {
        case 1:
                dec_f = LegallyAuthorizedPerson::DEAN_FACULTY_1;                // ����
            break;
        case 2:
                dec_f = LegallyAuthorizedPerson::DEAN_FACULTY_2;                                         // ���
            break;
        case 3:
                dec_f = LegallyAuthorizedPerson::DEAN_FACULTY_3;                                         // �����
            break;
        case 4:
                dec_f = LegallyAuthorizedPerson::DEAN_FACULTY_4;                                         // ����
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
        "������������� ��������� �������� ��������  ",
        2,
        nom_row
    );
    CellValue (
        IOF,
        12,
        nom_row
    );

    WorkSaveAs = SaveBook (Workbook);                                           // ����������

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
void __fastcall TMainForm::N37Click (TObject * Sender)                          // ���������� �� ������ ���������� ����������
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
            "���������� ����������������"
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


    CellValue (                                                                 // ���������
        fac1,
        1,
        5
    );

    Variant v1 = cur_d.CurrentDate ();

    if (v1 > 39664)                                                             // ���� 04.08.2008
        CellValue (
            "������� ������������� �������� � ����� � " +
                Admissions::TIME::YEAR                  +
            " ����",
            1,
            3
        );
    else
        CellValue (
            "�������� ��������� � ����� � " +
                Admissions::TIME::YEAR      +
            " ����",
            1,
            3
        );



    int n_r2,
        nom_r = 9,
        v;


    for ( int i = 0;                                                            // for �� ���� ��������
              i < 2;
              ++i
        )
    {
        int pp = 1;                                                             // ����� �� �������


        DMStat -> QSport_Categ -> Close ();

        DMStat -> QSport_Categ ->
            ParamByName ("V_E")   -> Value = i;

        DMStat -> QSport_Categ ->
            ParamByName ("N_FAC") -> Value = nom_fac;

        DMStat -> QSport_Categ -> Open ();


        if ( ! i)
            CellValue (
                "������� ����� ��������� �����������",
                1,
                nom_r
            );
        else
            CellValue (
                "������� ����� ��������� �����������",
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
                sum  = 0;                                                       // �������� ����� �� �������� ��������

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
                     == "���"
                   )
                    CellValue (
                        v,
                        3,
                        nom_r
                    );
                else if (    DMStat -> QSport_CategSPORT_CATEGORY -> Value
                          == "����"
                        )
                    CellValue (
                        v,
                        4,
                        nom_r
                    );
                else if (    DMStat -> QSport_CategSPORT_CATEGORY -> Value
                          == "��"
                        )
                    CellValue (
                        v,
                        5,
                        nom_r
                    );
                else if (    DMStat -> QSport_CategSPORT_CATEGORY -> Value
                          == "���"
                        )
                    CellValue (
                        v,
                        6,
                        nom_r
                    );
                else if (    DMStat -> QSport_CategSPORT_CATEGORY -> Value
                          == "1 ������"
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

            if (sum)                                                            // ������� ����� �� ������ ��������
                CellValue (
                    sum,
                    8,
                    nom_r
                );

            ++nom_r;
        }


        for ( int i = 1;                                                        // ���������� ���� �����
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
            "�����:",
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
        "����� �� �-��:",
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


    WorkSaveAs = SaveBook (Workbook);                                           // ����������

    ExcelApplication.Clear ();
}
void __fastcall TMainForm::N39Click (TObject * Sender)                          // "���������� � ���� ������ (�����������)
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
            "����1"
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
        CellValue (                                                             // ��������� �������� ����������
            DM -> TFaculty ->
                Lookup (
                    "N_FAC",
                    i,
                    "FAC1"
                ),
            1,
            strok
        );


        DMStat -> Q_GK_Plan -> Close ();                                        // ������� ����� ������ �� ����������

        DMStat -> Q_GK_Plan ->
            ParamByName ("FAC") -> AsInteger = i;

        DMStat -> Q_GK_Plan -> Open ();


        CellValue (
            DMStat -> Q_GK_PlanSUM -> Value,
            2,
            strok
        );


        DMStat -> Q_GK_All -> Close ();                                         // ���-�� �������� ��������� �� ���������� �� ��� ���� ��������

        DMStat -> Q_GK_All ->
            ParamByName ("FAC") -> AsInteger = i;

        DMStat -> Q_GK_All -> Open ();


        CellValue (                                                             // ��������� ������ � ������ Excel
            DMStat -> Q_GK_AllCOUNT -> Value,
            3,
            strok
        );


        for ( int k = 0;                                                        // ���� ��� �������� ���������
                  k < 4;                                                        // (0 - �����, 1 - ����, 2 - ��, 3 - 2-�� ����)
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
                        CellValue (                                             // �����
                            DMStat -> Q_GK_KonkursCOUNT -> Value,
                            4,
                            strok
                        );
                    break;
                case 1:
                        CellValue (                                             // ����
                            DMStat -> Q_GK_KonkursCOUNT -> Value,
                            5,
                            strok
                        );
                    break;
                case 2:
                        CellValue (                                             // ���� �� ��
                            DMStat -> Q_GK_KonkursCOUNT -> Value,
                            12,
                            strok
                        );
                    break;
                case 3:
                        CellValue (                                             // �� 2 ����
                            DMStat -> Q_GK_KonkursCOUNT -> Value,
                            9,
                            strok
                        );
                break;
            }
        }


        DMStat -> Q_GK_Plan_CK -> Close ();                                     // ���� ��

        DMStat -> Q_GK_Plan_CK ->
            ParamByName ("FAC") -> AsInteger = i;

        DMStat -> Q_GK_Plan_CK -> Open ();


        CellValue (
            DMStat -> Q_GK_Plan_CKSUM -> Value,
            11,
            strok
        );


        int sum = 0;

        for ( int m = 2;                                                        // ���� ��� �������� ����������
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
                CellValue (                                                     // ������ � ��������
                    DMStat -> Q_GK_MedalCOUNT -> Value,
                    7,
                    strok
                );
            else
                sum += DMStat -> Q_GK_MedalCOUNT -> Value;
        }

        CellValue (                                                             // ��������� � ������� � ���������� �������
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
void __fastcall TMainForm::N41Click (TObject * Sender)                          // ������� ��������� ������ ��������
{
    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N42Click (TObject * Sender)                          // ������ - �� ������������
{
    int col_pred = DM -> TPredmet -> RecordCount;                               // ����������� ���-�� �������. ���������

    DM -> QResult_Exam -> Close ();
    DM -> QResult_Exam -> Open ();


    DM -> QSpisoc_Group -> Close ();                                            // �������� Query c �������������
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


    ExcelApplication =                                                          // �������� ������� � �������� ���������� �����
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
            "����1"
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

    int j          = 0,                                                         // ����������  ���������� �����
        nom_stroka = 8,                                                         // ���������� ������ ������
        rec        = DM -> QSpisoc_Group -> RecordCount,                        // ���������� ������� � ������
        spec       = 0,
        vid_e      = -1;

    for ( int i =  1;                                                           // ���� �� ������������ (� ������ ������ ������ � �������������)
              i <= rec;
              ++i
        )
    {
        if (    spec  != DM -> QSpisoc_GroupN_SPECIALIZ -> Value
             || vid_e != DM -> QSpisoc_GroupVID_EDU     -> Value
           )
        {
            if (j)                                                              // �� ������ ����
                for ( int i = 1;                                                // ���������� ������ �������
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


            MergeCellCenter (                                                   // ����� (�������, ��� �������� � ����� ������)
                1,
                7 + col_pred,
                2
            );
            CellValue (                                                         // ������ � ��������� ����������
                DM -> TFaculty ->
                    Lookup (
                        "N_FAC",
                        nom_fac,
                        "FAC"
                    ),
                1,
                2
            );


            MergeCellCenter (                                                   // �������������� ������ ��� ��������� ���� ��������
                1,
                7 + col_pred,
                4
            );
            CellValue (
                DM -> QSpisoc_GroupVID_EDU1 -> Value,
                1,
                4
            );


            MergeCellCenter (                                                   // ������ �� ��������������
                1,
                7 + col_pred,
                5
            );
            CellValue (
                DM -> QSpisoc_GroupSPECIALIZ2 -> Value,
                1,
                5
            );

            Shapka_spisok (col_pred);                                           // ������� ������������ ����� �������

            nom_stroka = 8;                                                     // ����� ������
            j          = 1;                                                     // ���������� �����
        }


        Priv_Str (10);                                                      // ��������� ������ S1, S2, S3 - ������������ � �����. ������ (10 - ������ ����� ������������)


        CellValue (                                                             // ������ �� ��������� (�������)
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

        CellValue (                                                             // � �/�
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

        CellValue (                                                             // ���
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

        CellValue (                                                             // ���������� ������
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

        CellValue_Ball (                                                        // ������� �� ���� ��������� ��� ������ �����������
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
                    "0,0"                                                       // 0.0 � ����� Excel ����� ����� ������
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


        CellValue (                                                             // ��������� �������� ����� ���������
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


        CellValue (                                                             // ���������� ������ � ������ ������
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


        CellValue (                                                             // ��������� ���������� (������������ ��� ����������)
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


    for ( int i =  1;                                                           // ���������� ������ �������
              i <= col_pred + 7;
              ++i
        )
        AutoFitColumn (
            Sheet,
            i
        );


    DisplayAlert (ExcelApplication);                                            // ����������
    OVisible (ExcelApplication);

    WorkSaveAs = SaveBook (Workbook);

    if (nom_pr)
        delete [] nom_pr;

    DM -> QResult_Exam -> Close ();
}
void __fastcall TMainForm::N43Click (TObject * Sender)                          // ����������  ->  ���-�� �������� ��������� �� ������
{
    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir             +
            DocumentFile::STATISTIC::SCORES
        );

    OVisible (ExcelApplication);                                                // ������� �.�. ���������� ����� ��� ���������� �������,����� ������ ��� �������

    DisplayAlert (ExcelApplication);                                            // ������ ������� Excela �� ������������� ��������


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

    int d_st = 7,                                                               // ������� ��� ����
        n_r;                                                                    // ���������� ��� ������ ����������.

    for ( int edu = 0;                                                          // ���� �� ������ ��������
              edu < 2;
              ++edu
        )
    {
        for ( int konk_place = 0;                                               // ���� �� ������ ��������
                  konk_place < 3;
                  ++konk_place
            )
        {
            for ( int price = 0;                                                // ���� �� ���������������
                      price < 2;
                      ++price
                )
            {
                SheetName =
                    getPartOfSheetNameForEducationType (edu)        +
                    getPartOfSheetNameForStudyPeriod   (konk_place) +
                    getPartOfSheetNameForPayment       (price);

                nom_row = 15;                                                   // ������ ������ ������

                Sheet =                                                         // ����� ����� Excel
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
                    1,                                                          // 1 ������� - ��� �������
                    14                                                          // 14 ������ - ��� �������
                );

                CellValue (                                                     // ����� ���� (d_st - ����� �������?)
                    cur_d.CurrentDate (),
                    7,                                                          // 7 ���
                    5                                                           // 5 ������
                );

                CellValue (                                                     // ����� �������
                    cur_d.CurrentTime (),
                    11,                                                         // 11 ���
                    5                                                           // 5 ������
                );


                DM -> QPlan_Priem_Konk_All_Param -> Close ();                   // ��� AllCount - ����� ����� �� �����

                DM -> QPlan_Priem_Konk_All_Param ->                             // ����� ����������
                    ParamByName ("N_FAC")   -> AsInteger = nom_fac;

                DM -> QPlan_Priem_Konk_All_Param ->                             // ����� ��������
                    ParamByName ("VID_EDU") -> AsInteger = edu;

                DM -> QPlan_Priem_Konk_All_Param ->                             // ���� ��������
                    ParamByName ("TEXT")    -> AsInteger = konk_place;

                DM -> QPlan_Priem_Konk_All_Param ->                             // ��������������
                    ParamByName ("PRICE")   -> AsInteger = price;

                DM -> QPlan_Priem_Konk_All_Param -> Open ();


                if (    konk_place ==                                           // ���������� ������� � ����� �����
                            static_cast <int> (
                                StudyPeriodCode::SHORT_SECOND_COURSE
                            )
                     && konk_place ==
                            static_cast <int> (
                                StudyPeriodCode::SHORT_THIRD_COURSE
                            )
                   )
                    col_rec = 1;                                                // ��� ���������� ������ ���� ����������� �������������
                else
                    col_rec =                                                   // � ��������� �������
                        DM -> QPlan_Priem_Konk_All_Param -> RecordCount;

                n_r = nom_row;                                                  // ������ ����������

                Cicle_ball (
                    edu,
                    konk_place,
                    price
                );
            }
        }
    }


    if (nom_fac == 2)                                                           // �������� ������ ������ Excel (��� ���)
    {
        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
                "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����

        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
                "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����

        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
                "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����

        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
                "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����
    }


    // if (nom_fac == 3)                                                           // �������� ������ ������ Excel (��� �����)
    // {
    //     Sheet =                                                                 // ����� ����� Excel
    //         SelectSheet (
    //             Workbook,
    //             "�.�.�."
    //         );
    //     DeleteSheet (Sheet);                                                    // �������� ���������� �����

    //     Sheet =                                                                 // ����� ����� Excel
    //         SelectSheet (
    //             Workbook,
    //             "�.�.�."
    //         );
    //     DeleteSheet (Sheet);                                                    // �������� ���������� �����

    //     Sheet =                                                                 // ����� ����� Excel
    //         SelectSheet (
    //             Workbook,
    //             "�.�.�."
    //         );
    //     DeleteSheet (Sheet);                                                    // �������� ���������� �����

    //     Sheet =                                                                 // ����� ����� Excel
    //         SelectSheet (
    //             Workbook,
    //             "�.�.�."
    //         );
    //     DeleteSheet (Sheet);                                                    // �������� ���������� �����
    // }


    if (nom_fac == 4)                                                           // �������� ������ ������ Excel (��� ��)
    {
        // Sheet =                                                                 // ����� ����� Excel
        //     SelectSheet (
        //         Workbook,
        //         "�.�.�."
        //     );
        // DeleteSheet (Sheet);                                                    // �������� ���������� �����

        // Sheet =                                                                 // ����� ����� Excel
        //     SelectSheet (
        //         Workbook,
        //         "�.�.�."
        //     );
        // DeleteSheet (Sheet);                                                    // �������� ���������� �����

        // Sheet =                                                                 // ����� ����� Excel
        //     SelectSheet (
        //         Workbook,
        //         "�.�.�."
        //     );
        // DeleteSheet (Sheet);                                                    // �������� ���������� �����

        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
                "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����
    }


    WorkSaveAs = SaveBook (Workbook);                                           // ����������

    OVisible (ExcelApplication);                                                // ���������� ������ Excel

    ExcelApplication.Clear ();

    DM -> QPlan_Priem_Konk_All_Param -> Close ();
}
void __fastcall TMainForm::N44Click (TObject * Sender)                          // ����� ������ ��������� (��������)  �� ������������
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
            "����1"
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


    CellValue (                                                                 // ��������� � ����
        "����������� ��������������� ����������� "  \
        "���������� ��������",
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

    for ( int i = 0;                                                            // for �� ���� ��������
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
                "������� ����� ��������� �����������",
                1,
                nom_row
            );
        else
            CellValue (
                "������� ����� ��������� �����������",
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

        Itog_podano (                                                           // ����� �� ���� ��������
            i,
            n_r,
            0
        );

        ++nom_row;


        for ( int i =  1;                                                       // ���������� ���������� �����
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


    Itog_podano (                                                               // ����� �� ����������
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
        "������������� ��������� �������� �������� ",
        2,
        nom_row
    );
    CellValue (
        IOF,
        12,
        nom_row
    );


    WorkSaveAs = SaveBook (Workbook);                                           // ����������

    ExcelApplication.Clear ();

    DM -> QPlan_Priem_All_Special -> Close ();
}
void __fastcall TMainForm::N45Click (TObject * Sender)                          // '����� 1' ������ �� �������
{
    Forma_Giac (
        static_cast <int> (FormTypeCode::REGISTRATION),
        static_cast <int> (EducationTypeCode::INTRAMURAL)
    );
}
void __fastcall TMainForm::N46Click (TObject * Sender)                          // '����� 2' ��������� �� �������
{
    Forma_Giac (
        static_cast <int> (FormTypeCode::ENROLLMENT),
        static_cast <int> (EducationTypeCode::INTRAMURAL)
    );
}
void __fastcall TMainForm::N47Click (TObject * Sender)                          // '����� 1' ������ �� �������
{
    Forma_Giac (
        static_cast <int> (FormTypeCode::REGISTRATION),
        static_cast <int> (EducationTypeCode::EXTRAMURAL)
    );
}
void __fastcall TMainForm::N48Click (TObject * Sender)                          // '����� 2' ��������� �� �������
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
        "������������ ��������� � �� �� ����";

    ExamenSpecForm -> DBLookupComboBox1 -> Visible = true;
    ExamenSpecForm -> DBLookupComboBox1 -> KeyValue = 2;
    ExamenSpecForm -> DBLookupComboBox1 -> Enabled = false;

    ExamenSpecForm -> Height = 163;

    ExamenSpecForm -> ShowModal ();
}
void __fastcall TMainForm::N55Click (TObject * Sender)                          // ����������  ->  �������
{
    //  NOTE: Use AbiturRIO instead !!!

    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir                             +
            DocumentFile::STATISTIC::CONTEST
        );

    OVisible (ExcelApplication);                                                // ������� �.�. ���������� ����� ��� ���������� �������, ����� ������ ��� �������

    // DisplayAlert (ExcelApplication);                                            // ������ ������� Excela �� ������������� ��������


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
        d_st = 7,                                                               // ������� ��� ����
        n_r;                                                                    // ���������� ��� ������ ����������.

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

                nom_row = 15;                                                   // ������ ������ ������

                Sheet =                                                         // ����� ����� Excel
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
                    1,                                                          // 1 ������� - ��� �������
                    14                                                          // 14 ������ - ��� �������
                );

                CellValue (                                                     // ����� ����
                    cur_d.CurrentDate (),
                    6,
                    4
                );

                // CellValue (                                                     // ����� �������
                //     cur_d.CurrentTime (),
                //     11,                                                         // 11 ���
                //     5                                                           // 5 ������
                // );


                DM -> QPlan_Priem_Konk_All_Param -> Close ();                   // ��� AllCount - ����� ����� �� �����
                DM -> QPlan_Priem_Konk_All_Param ->                             // ����� ����������
                    ParamByName ("N_FAC")   -> AsInteger = nom_fac;
                DM -> QPlan_Priem_Konk_All_Param ->                             // ����� ��������
                    ParamByName ("VID_EDU") -> AsInteger = edu;
                DM -> QPlan_Priem_Konk_All_Param ->                             // ���� ��������
                    ParamByName ("TEXT")    -> AsInteger = konk_place;
                DM -> QPlan_Priem_Konk_All_Param ->                             // ��������������
                    ParamByName ("PRICE")   -> AsInteger = price;
                DM -> QPlan_Priem_Konk_All_Param -> Open ();


                if (    konk_place == 1                                         // ���������� ������� � ����� �����
                     && (    nom_fac == 1
                          || nom_fac == 2
                        )
                   )
                    col_rec = 1;                                                // ��� ���������� ���� � ��� ������ ���� ����������� �������������
                else                                                            // � ��������� �������
                    col_rec =
                        DM -> QPlan_Priem_Konk_All_Param -> RecordCount;


                n_r = nom_row;                                                  // ���������� ��� ������ ����������

                Cicle_ball_konk (
                    edu,
                    konk_place,
                    price
                );
            }
        }
    }


    if (nom_fac == 2)                                                           // �������� ������ ������ EXCEL '��� ���'
    {
        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
                "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����

        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
               "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����

        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
              "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����

        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
              "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����
    }


    // if (nom_fac == 3)                                                           // �������� ������ ������ EXCEL '��� �����'
    // {
    //     Sheet =                                                                 // ����� ����� Excel
    //         SelectSheet (
    //             Workbook,
    //             "�.�.�."
    //         );
    //     DeleteSheet (Sheet);                                                    // �������� ���������� �����

    //     Sheet =                                                                 // ����� ����� Excel
    //         SelectSheet (
    //             Workbook,
    //            "�.�.�."
    //         );
    //     DeleteSheet (Sheet);                                                    // �������� ���������� �����

    //     Sheet =                                                                 // ����� ����� Excel
    //         SelectSheet (
    //             Workbook,
    //           "�.�.�."
    //         );
    //     DeleteSheet (Sheet);                                                    // �������� ���������� �����

    //     Sheet =                                                                 // ����� ����� Excel
    //         SelectSheet (
    //             Workbook,
    //           "�.�.�."
    //         );
    //     DeleteSheet (Sheet);                                                    // �������� ���������� �����
    // }


    if (nom_fac == 4)                                                           // �������� ������ ������ EXCEL '��� ��'
    {
        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
                "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����

        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
               "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����

        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
              "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����

        Sheet =                                                                 // ����� ����� Excel
            SelectSheet (
                Workbook,
              "�.�.�."
            );
        DeleteSheet (Sheet);                                                    // �������� ���������� �����
    }


    WorkSaveAs = SaveBook (Workbook);                                           // ����������

    OVisible (ExcelApplication);                                                // ���������� ������ Excel

    ExcelApplication.Clear ();

    DM -> QPlan_Priem_Konk_All_Param -> Close ();
}
void __fastcall TMainForm::N58Click (TObject * Sender)                          // ������ ��������� ������,������� �����
{
    printEnvelope (
        PaymentCode::BUDGET,
        EducationTypeCode::INTRAMURAL,
        EnvelopeMessage::BUDGET::INTRAMURAL
    );
}
void __fastcall TMainForm::N59Click (TObject * Sender)                          // ������ ��������� ������,�������� �����
{
    printEnvelope (
        PaymentCode::BUDGET,
        EducationTypeCode::EXTRAMURAL,
        EnvelopeMessage::BUDGET::EXTRAMURAL
    );
}
void __fastcall TMainForm::N62Click (TObject * Sender)                          // ������ ��������� �� ������, ������� �����
{
    printEnvelope (
        PaymentCode::BUYERS,
        EducationTypeCode::INTRAMURAL,
        EnvelopeMessage::BUYERS::INTRAMURAL
    );
}
void __fastcall TMainForm::N63Click (TObject * Sender)                          // ������ ��������� �� ������,�������� �����
{
    printEnvelope (
        PaymentCode::BUYERS,
        EducationTypeCode::EXTRAMURAL,
        EnvelopeMessage::BUYERS::EXTRAMURAL
    );
}
void __fastcall TMainForm::N64Click (TObject * Sender)                          // ������ ����������� ���������� ������������
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
                "���"
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
                    "�",
                    1
                );
            else
                SheetName.Insert (
                    "�",
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
                            "�",
                            2
                        );
                else
                    SheetName =
                        SheetName.Insert (
                            "�",
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
                                "�",
                                3
                            );
                    else
                        SheetName =
                            SheetName.Insert (
                                "�",
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

                    while ( ! DM -> SelectLogAbiturQr -> Eof)                   // ���������� �������
                    {
                        CellValue (                                             // 1. ����� ����
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


                        BorderCell (                                            // ���������� ������
                            1,                                                  // �������
                            i,                                                  // ������
                            1,                                                  // ������� �����
                            2                                                   // �������
                        );


                        CellValue (                                             // 2. ���� ������ ����������
                            SQLTimeStampToDateTime (
                                DM -> SelectLogAbiturQrDATE_IN -> Value
                            ),
                            2,                                                  // �������
                            i                                                   // ������
                        );
                        BorderCell (                                            // ���������� ������
                            2,                                                  // �������
                            i,                                                  // ������
                            1,                                                  // ������� �����
                            2                                                   // �������
                        );


                        FIO =                                                   // 3. ���
                            DM -> SelectLogAbiturQrFAM  -> Value + " " +
                            DM -> SelectLogAbiturQrNAME -> Value + " " +
                            DM -> SelectLogAbiturQrOTCH -> Value;


                        DM -> SpecQr -> Close ();                               // 3.1. ����������� �������������

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
                            3,                                                  // �������
                            i                                                  // ������
                        );
                        BorderCell (                                            // ���������� ������
                            3,                                                  // �������
                            i,                                                  // ������
                            1,                                                  // ������� �����
                            2                                                   // �������
                        );


                        DM -> ContrySelQr -> Close ();                          // 4. �����������

                        DM -> ContrySelQr ->
                            ParamByName ("id") -> AsSmallInt =
                                    DM -> SelectLogAbiturQrCITIZENSHIP -> Value;

                        DM -> ContrySelQr -> Open ();


                        CellValue (
                            DM -> ContrySelQrSHORT_NAME -> Value,
                            4,                                                  // �������
                            i                                                  // ������
                        );
                        BorderCell (                                            // ���������� ������
                            4,                                                  // �������
                            i,                                                  // ������
                            1,                                                  // ������� �����
                            2                                                   // �������
                        );


                        DM -> ContrySelQr -> Close ();

                        NameSertificat = "";                                    // 5. �������� �������� ������������ ��

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
                                    NameSertificat += "������� ���� ";
                                else
                                    NameSertificat += "����������� ���� ";
                            else
                                NameSertificat +=
                                    DM -> SertSelLogQrTEXT_PREDMET -> AsString  +
                                    " ";

                            NameSertificat +=
                                DM -> SertSelLogQrSERIA_S -> AsString;

                            NameSertificat +=
                                " �"                                    +
                                    DM -> SertSelLogQrNOMER_S -> Value  +
                                ","                                     +
                                    DM -> SertSelLogQrBALLS   -> Value  +
                                "����";

                            DM -> SertSelLogQr -> Next ();

                            if ( ! DM -> SertSelLogQr -> Eof)
                                NameSertificat += "\n";
                        }

                        DM -> SertSelLogQr -> Close ();

                        CellValue (
                            NameSertificat,
                            5,                                                  // �������
                            i                                                   // ������
                        );
                        BorderCell (                                            // ���������� ������
                            5,                                                  // �������
                            i,                                                  // ������
                            1,                                                  // ������� �����
                            2                                                   // �������
                        );



                        switch (DM -> SelectLogAbiturQrKONKURS -> Value)        // 6. ������� � �������
                        {
                            case 1:                                             // ���
                                    NameSertificat = "���";
                                break;
                            case 2:                                             // ��
                                    NameSertificat = "��";
                                break;
                            default:
                                    NameSertificat = "";
                        }


                        switch (DM -> SelectLogAbiturQrTERM_EDU -> Value)
                        {
                            case 3:                                             // �� 1 ����
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "�� 1�.";
                                break;
                            case 4:                                             // �� 2 ����
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "�� 2�.";
                                break;
                            case 5:                                             // �� 3 ����
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "�� 3�.";
                                break;
                        }


                        switch (DM -> SelectLogAbiturQrCATEGORY -> Value)
                        {
                            case 1:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "3����.";
                                break;
                            case 2:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "2����.";
                                break;
                            case 3:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "1����.";
                                break;
                            case 4:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "���";
                                break;
                            case 5:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "��";
                                break;
                            case 6:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "����";
                                break;
                            case 7:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "���";
                                break;
                            case 8:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "3��";
                                break;
                            case 9:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "2��";
                                break;
                            case 10:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "1��";
                                break;
                            case 11:
                                    if (NameSertificat != "")
                                        NameSertificat += ",";

                                    NameSertificat += "1��.�";
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
                                case 0:                                         // ���
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
                                                 != "��"
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
                                case 1:                                         // ��
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
                                                 != "��"
                                               )
                                                NameSertificat +=
                                                    " - " +
                                                    DM -> OutTestQrSHORT_NAME_1 -> Value;

                                            DM -> OutTestQr -> Next ();
                                        }

                                        DM -> OutTestQr -> Close ();
                                    break;
                                case 2:                                         // ������
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
                            6,                                                  // �������
                            i                                                   // ������
                        );
                        BorderCell (                                            // ���������� ������
                            6,                                                  // �������
                            i,                                                  // ������
                            1,                                                  // ������� �����
                            2                                                   // �������
                        );


                        CellValue (                                             // 7. ����� ����� ����������
                            DM ->
                                SelectLogAbiturQrADDRESS_BEFORE ->
                                    Value,
                            7,                                                  // �������
                            i                                                   // ������
                        );
                        BorderCell (                                            // ���������� ������
                            7,                                                  // �������
                            i,                                                  // ������
                            1,                                                  // ������� �����
                            2                                                   // �������
                        );


                        if (DM -> SelectLogAbiturQrN_CK -> Value > -1)          // 8. ������� �������
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

                        BorderCell (                                            // ���������� ������
                            8,                                                  // �������
                            i,                                                  // ������
                            1,                                                  // ������� �����
                            2                                                   // �������
                        );

                        DM -> RegionQr -> Close ();

                        BorderCell (                                            // 9. ������� � ����������!!!
                            9,                                                  // �������
                            i,                                                  // ������
                            1,                                                  // ������� �����
                            2                                                   // �������
                        );
                        DM -> RegionQr -> Close ();


                        if (DM -> SelectLogAbiturQrDATE_OUT -> IsNull)          // 10. ������� � �������� ���������� (vd = "01.01.2015";)
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


                        BorderCell (                                            // ���������� ������
                            10,                                                 // �������
                            i,                                                  // ������
                            1,                                                  // ������� �����
                            2                                                   // �������
                        );

                        DM -> SelectLogAbiturQr -> Next ();                     // ������� � ����� ������

                        ++i;
                    }

                    DM -> SelectLogAbiturQr -> Close ();

                    Variant CC1 =                                               // ����������� ������ ����� �� ������
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
                    wrapWord (RCC);                                             // ������ �� ������
                    HorizontalAlign (                                           // �� ������
                        RCC,
                        3
                    );
                    VerticalAlign (                                             // �� ������
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
void __fastcall TMainForm::N68Click (TObject * Sender)                          // ���������: "��������� - ������������� ���������. ������ ����, �������, ������"
{
    N23Click (this);

    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N69Click (TObject * Sender)                          // ���������: "��������� - ������������� ���������. ������ ����, �������, ��������"
{
    N23Click (this);

    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N70Click (TObject * Sender)                          // ���������: "��������� - ������������� ���������. ������ ����, ������,  ������"
{
    N23Click (this);

    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N71Click (TObject * Sender)                          // ���������: "��������� - ������������� ���������. ������ ����, ������,  ��������"
{
    N23Click (this);

    Create_Svod_ved (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N75Click (TObject * Sender)                          // ���������: "��������� - ������������� ���������. ����������,  �������, ������"
{
    N23Click (this);

    Create_Svod_ved_short (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N76Click (TObject * Sender)                          // ���������: "��������� - ������������� ���������. ����������,  �������, ��������"
{
    N23Click (this);

    Create_Svod_ved_short (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N77Click (TObject * Sender)                          // ���������: "��������� - ������������� ���������. ����������,  ������,  ������"
{
    N23Click (this);

    Create_Svod_ved_short (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N78Click (TObject * Sender)                          // ���������: "��������� - ������������� ���������. ����������,  ������,  ��������"
{
    N23Click (this);

    Create_Svod_ved_short (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N81Click (TObject * Sender)                          // ���������: "��������� - ������������� ���������. 2-� ������,  �������, ������"
{
    N23Click (this);

    Create_Svod_ved_2VO2K (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N82Click (TObject * Sender)                          // ���������: "��������� - ������������� ���������. 2-� ������,  ������,  ������"
{
    N23Click (this);

    Create_Svod_ved_2VO2K (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUDGET)
    );
}
void __fastcall TMainForm::N83Click (TObject * Sender)                          // ���������: "��������� - ������������� ���������. 2-� ������,  �������, ��������"
{
    N23Click (this);

    Create_Svod_ved_2VO2K (
        static_cast <int> (EducationTypeCode::INTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N84Click (TObject * Sender)                          // ���������: "��������� - ������������� ���������. 2-� ������,  ������,  ��������"
{
    N23Click (this);

    Create_Svod_ved_2VO2K (
        static_cast <int> (EducationTypeCode::EXTRAMURAL),
        static_cast <int> (PaymentCode::BUYERS)
    );
}
void __fastcall TMainForm::N85Click (TObject * Sender)                          // ������ '��������� ������' ������� ����
{
    PersonalDocFrm = new TPersonalDocFrm (this);

    PersonalDocFrm -> ShowModal ();
}
void __fastcall TMainForm::N86Click (TObject * Sender)                          // ���������: ������ - ������ �� ����
{
    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook = NewBook (ExcelApplication);

    Sheet =                                                                     // ���������� Excel
        SelectSheet (
            Workbook,
            "����1"
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
        "�",
        Workbook
    );
    Spisok_Pol (
        "�",
        Workbook
    );

    // OVisible (ExcelApplication);
    // DisplayAlert (ExcelApplication);
}
void __fastcall TMainForm::N110Click (TObject * Sender)                         // '����� 1-�' ��� ������������ �����������
{
    ExcelApplication = Variant::CreateObject ("Excel.Application");

    Variant Workbook =
        OpenBook (
            ExcelApplication,
            cur_dir             +
            DocumentFile::REPORT::FORM_1
            // "����� 1-� � ������������ �����������.xls"
        );
    Sheet =
        SelectSheet (
            Workbook,
            "����� 1-�"
        );


    AnsiString sp;
               nom_row = 8;


    for ( int j = 0;                                                            // ������ �� ���� ��������
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
        //     ParamByName ("konk") -> Value = 3;                                  // ������ � 2004 ���� �.�. ������� ���� 3 (2 ����), 4 (2-�� �/�) ��������������� � SQL

        DMStat -> QF1kAb ->
            ParamByName ("STAT") -> Value = 0;

        DMStat -> QF1kAb ->
            ParamByName ("VID")  -> Value = j;

        DMStat -> QF1kAb -> Open ();


        if (j)
            CellValue (
                "�������",
                1,
                nom_row
            );
        else
            CellValue (
                "�������",
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
            int all_sum = 0;                                                    // ����� � 2003 ����, �.�. �� ����������� ����� ���������

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
            "�������"
        );


    for ( vid_educ = 0;                                                         // ������ �� ��������� � ���������
          vid_educ < 2;
          ++vid_educ
        )
    {
        if (vid_educ)                                                           // �������
            Sheet =
                SelectSheet (
                    Workbook,
                    "�������"
                );

        DMStat -> QSpecial -> Open ();

        int rec_spec =
            DMStat -> QSpecial -> RecordCount;

        for ( int k = 0;
                  k < 2;
                  ++k
            )
            mas_spec_str[k] = new int[rec_spec];


        for ( int i = 0;                                                        // for ������ ��������������
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
        //     CellValue (                                                         // � 2004 ���� ���������� ������
        //         "�������",
        //         8,
        //         5
        //     );
        // else
        //     CellValue (                                                         // � 2004 ���� ���������� ������
        //         "�������",
        //         8,
        //         5
        //     );


        DMStat -> QCount_special_ab -> Close ();                                // ������ ��������� �����
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


        for ( int j = 0;                                                        // ����� ���������� �������� ��������� �� �������������
                  j < DMStat -> QCount_special_ab -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_special_abCOUNT -> Value,
                    5,
                    Find_nom_spec_str (
                        DMStat -> QCount_special_abN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        if ( ! vid_educ)                                                        // �� � ������� - ������ ��� ��������
        {
            DMStat -> QCount_PO -> Close ();                                    // � 2004 ���� ���� �� ����� ���������� � ��
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

            for ( int j = 0;                                                    // ���������� ���������� ������������,���������� ��
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


            for ( int j = 0;                                                    // ���������� ���������� ������������ � ��
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


        DMStat -> QCount_Medal -> Close ();                                     // ���������-���������
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


        for ( int j = 0;                                                        // ������� ������ ���-�� ���������� � �������
                  j < DMStat -> QCount_Medal -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_MedalCOUNT -> Value,
                    6,
                    Find_nom_spec_str (
                        DMStat -> QCount_MedalN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_Diplom -> Close ();                                    // ������� � �������� - ������ ��� ���� � ���
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


        for ( int j = 0;                                                        // ������� ���-�� ���������� ���� � �.�. � ��������
                  j < DMStat -> QCount_Diplom -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_DiplomCOUNT -> Value,
                    7,
                    Find_nom_spec_str (
                        DMStat -> QCount_DiplomN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        AnsiString SQL1 =                                                       // ������� ���� '��� ���������' (�.21 ������ ������)
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



        if ( ! vid_educ)                                                        // ������ �������
        {
            SQL2 =                                                              // ���������� � ������� ����������� ���� � ������, ��������� ����������� ��� ( WO = 1 ��� 2)
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


            for ( int j = 0;                                                    // ���-�� ����������� � �������� �� � ������, ���������� ����������� ���
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


            SQL2 =                                                              // �������� ������ ���������� �� (WO = 3)
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


            for ( int j = 0;                                                    // �������� ������ ���������� ��
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


            DMStat -> QCount_Gimn -> Close ();                                  // ����������� �����, �������� (� 2004-2006 ���� ������ ��� ��������)
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


            for ( int j = 0;                                                    // ������� ���-�� ���������� ����� ��� ��������
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
        else                                                                    // ������� �������� �.21 ������������
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


        AnsiString SQL_Gorod =                                                  // ���������� ���� �������� ���������� �����������
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
            ParamByName ("N")   -> AsString   = "4";                            // ��������
        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;
        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "%";
        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // ������ ���-�� ���������� �������� ��
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    9,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_Gorod -> Close ();                                     // ���������� �������� ���������� ����������� - ������ �������� ����
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add (
                    SQL_Gorod
                );


        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "4";                            // ��������
        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;
        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "2006";
        DMStat -> QCount_Gorod -> Open ();



        for ( int j = 0;                                                        // ������ ���-�� ���������� �������� ��
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    10,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_Gorod -> Close ();                                     // ���������� ��������� ���������� ����������� - ����
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add (
                    SQL_Gorod
                );


        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "5";                            // ���������
        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;
        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "%";
        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // ������ ���-�� ���������� ��������� ��
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    11,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_Gorod -> Close ();                                     // ���������� ��������� ���������� ����������� - ������ �������� ����
        DMStat -> QCount_Gorod -> SQL -> Clear ();
        DMStat -> QCount_Gorod ->
            SQL ->
                Add (
                    SQL_Gorod
                );


        DMStat -> QCount_Gorod ->
            ParamByName ("N")   -> AsString   = "5";                            // ���������
        DMStat -> QCount_Gorod ->
            ParamByName ("EDU") -> AsSmallInt = vid_educ;
        DMStat -> QCount_Gorod ->
            ParamByName ("GOD") -> AsString   = "2006";
        DMStat -> QCount_Gorod -> Open ();


        for ( int j = 0;                                                        // ������ ���-�� ���������� ��������� ��
                  j < DMStat -> QCount_Gorod -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_GorodCOUNT -> Value,
                    12,
                    Find_nom_spec_str (
                        DMStat -> QCount_GorodN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_Stag -> Close ();                                      // ���� ����� 2-� ���
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


        for ( int j = 0;                                                        // ������ ���-�� ������� ���� ����� 2-� ���
                  j < DMStat -> QCount_Stag -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_StagCOUNT -> Value,
                    13,
                    Find_nom_spec_str (
                        DMStat -> QCount_StagN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_Test -> Close ();                                      // ����������� ����������������� ������������ (3 �����) (� 2003 ���� ������, � 2006 2�� (�����������) + 1)
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


        for ( int j = 0;                                                        // ������ ���-�� ������������ � �� = 3
                  j < DMStat -> QCount_Test -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_TestCOUNT -> Value,
                    14,
                    Find_nom_spec_str (
                        DMStat -> QCount_TestN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        DMStat -> QCount_RUOR -> Close ();                                      // �� ����������� ���� �������� (2 ���� - ����)
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


        for ( int j = 0;                                                        // ������ ���-�� ������������ �� 2 ����
                  j < DMStat -> QCount_RUOR -> RecordCount;
                  ++j
            )
        {
            if (vid_educ)                                                       // �������
                CellValue (
                    DMStat -> QCount_RUORCOUNT -> Value,
                    15,
                    Find_nom_spec_str (
                        DMStat -> QCount_RUORN_SPEC -> Value,
                        rec_spec
                    )
                );
            else                                                                // �������
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


        if ( ! vid_educ)                                                        // ������ ������� ����� ��������
        {
            DMStat -> QCount_Region -> Close ();                                // �������� ��, ����������, ����������, ������������
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
                        "         gragdan  <> '��'"                 \
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


            for ( int j = 0;                                                    // ������ ���-�� ������������ �� ������ ���������
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


            for ( int j = 0;                                                    // ������ ���-�� ������������ �� 2-�� ������
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
void __fastcall TMainForm::N310Click (TObject * Sender)                         // '����� 3' ������� ����� ��������
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
void __fastcall TMainForm::Priv_Str (int par)                                   // ������ � ������������ (par = 10 - ������ ������ ������������)
{
    // int        n_ab;                                                            // ����� �����������

               S1         = "";                                                 // �� ��������
               S2         = "";                                                 // ��� ���������� � ������������
               S3         = "";                                                 // ���������� ������
    AnsiString Stat_ab_vk = "",                                                 // ��� ��������
               Stat_ab_pr = "",                                                 // ����������
               Stat_ab_wo = "";                                                 // ��� ���������


    DMStat -> FullGrpS1Qr -> Close ();

    DMStat -> FullGrpS1Qr ->
        ParamByName ("nomer_ab") -> AsInteger =
                DM -> QSpisoc_GroupNOMER_AB -> Value;

    DMStat -> FullGrpS1Qr -> Open ();


    if (DMStat -> FullGrpS1QrCATEGORY_IF -> Value)
        S1 = "����������";


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
                    S1 = "���";
                else
                    S1 += ",���";
            break;
        case 2:
                if (S1 == "")
                    S1 = "��";
                else
                    S1 += ",��";
            break;
        case 3:
                if (S1 == "")
                    S1 = "��";
                else
                    S1 += ",��";
            break;
    }


    switch (DMStat -> FullGrpS1QrTERM_EDU -> Value)
    {
        case 1:
                if (S1 == "")
                    S1 = "��� 2�.";
                else
                    S1 += ",��� 2�.";
            break;
        case 2:
                if (S1 == "")
                    S1 = "��� 3�.";
                else
                    S1 += ",��� 3�.";
            break;
        case 3:
                if (S1 == "")
                    S1 = "�� 1�.";
                else
                    S1 += ",�� 1�.";
            break;
        case 4:
                if (S1 == "")
                    S1 = "�� 2�.";
                else
                    S1 += ",�� 2�.";
            break;
        case 5:
                if (S1 == "")
                    S1 = "�� 3�.";
                else
                    S1 += ",�� 3�.";
            break;
    }


    if (DMStat -> FullGrpS1QrPRICE -> Value)
        if (S1 == "")
            S1 = "�� ���. ";
        else
            S1 += ",�� ���. ";


    DMStat -> FullGrpS1Qr -> Close ();


    switch (par)
    {
        case 10:                                                                // ������ ������
                Stat_ab_wo = DM -> QSpisoc_GroupWITHOUT -> Value;
                Stat_ab_vk = DM -> QSpisoc_GroupV_K     -> Value;
                Stat_ab_pr = DM -> QSpisoc_GroupPRIV    -> Value;
            break;
        default:                                                                // 0-�����, 1-����, 2-��, 3-������ ����, 4-��� ��������, 5-��� ���������, 6-����������
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


    if (par == 10)                                                              // ������ ������ ������������
    {
        // switch (DM -> QSpisoc_GroupKONKURS -> Value)                            // �������
        // {
        //     case 1:
        //             S1 += AnsiString ("�� ");
        //         break;
        //     case 2:
        //             // if (DM -> QSpisoc_GroupN_FAC -> Value == 3)
        //             //     S1 += "3 ���� ";
        //             // else
        //                 S1 += "2 ���� ";
        //         break;
        //     case 3:
        //             S1 += AnsiString ("��� ����. ");
        //         break;
        //     case 4:
        //             S1 += AnsiString ("��� ���. ");
        //         break;
        //     case 5:
        //             S1 += AnsiString ("���������� ");
        //         break;
        // }

        // if (DM -> QSpisoc_GroupPRICE -> Value)                                  // ����� ������
        //     S1 += AnsiString ("�� ���. ");

        // if (DM -> QSpisoc_GroupGRAGDAN -> Value != "��")
        //     S2 +=
        //         DM -> QSpisoc_GroupGRAGDAN -> Value + " ";


        if (DM -> QSpisoc_GroupN_SPORT_CATEGORY -> Value > 0)                   // ������
            S3 =
                DM -> TCategory ->
                    Lookup (
                        "N_SPORT_CATEGORY",
                        DM -> QSpisoc_GroupN_SPORT_CATEGORY -> Value,
                        "SPORT_CATEGORY"
                    );
    }


    if (    par == 1                                                            // ��� �� � ������� ���������
         && DMVed -> QKonkursOUT_N_CK -> Value
       )
    {
        S2 += AnsiString ("������� ������� (");

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

        S2 += AnsiString (" �-�) ");
    }

    // int len = Stat_ab_wo.Length ();                                             // '��� ���������'

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
    //                         "���������� (������� I,II,III �������) ������������� �������� � "
    //                     )                               +
    //                     AnsiString (
    //                         "��������������� ��������� �� ������� ��������� (��� ���������) "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 2:
    //                 S2 +=
    //                     AnsiString (
    //                         "����������,������� � ��������� �����������, �������������� � ���������"
    //                     )                               +
    //                     AnsiString (
    //                         "���� ���,"
    //                     )                               +
    //                     AnsiString (
    //                         " ���������� � ������� ��������� ����������� ��� "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 3:
    //                 S2 +=
    //                     AnsiString (
    //                         "���������� � ������� �����������,������� ���������� ������, ��������� "
    //                     )                               +
    //                     AnsiString (
    //                         "���� � ������, ����������� ���������� �������� ������ "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 4:
    //                 S2 +=
    //                     AnsiString (
    //                         "���������� ����������� ����������� ���������� ��������,���������� � "
    //                     )                               +
    //                     AnsiString (
    //                         "��������� ������ � ������ ����������� ��� "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 5:
    //                 S2 +=
    //                     AnsiString (
    //                         "���������� � ������� �����������, ��������� ���� � ������ ����� "
    //                     )                               +
    //                     AnsiString (
    //                         "��������� "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 6:
    //                 S2 +=
    //                     AnsiString (
    //                         "������ �/� �� ������� ������ �� 2 � ������� ����� "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //     }
    // }

    // len = Stat_ab_vk.Length ();                                                 // '��� ��������'

    // for ( int i =  1;
    //           i <= len;
    //           ++i
    //     )
    // {
    //     int el_str = StrToInt (Stat_ab_vk[i]);

    //     switch (el_str)
    //     {
    //         case 1:
    //                 S2 += AnsiString ("����-������ ");
    //             break;
    //         case 2:
    //                 S2 +=
    //                     AnsiString (
    //                         "������� ����������� �����������,���������� � ������� ���������� ������,"
    //                     )                               +
    //                     AnsiString (
    //                         " ��������� ���������� �������� "
    //                     )                               +
    //                     (char) (13);
    //         // case 2:
    //         //         S2 +=
    //         //             "������� 1 ��� 2 ��. ";
    //         //     break;
    //         case 3:
    //                 S2 +=
    //                     AnsiString (
    //                         "���������� ����������� �����������,���������� ������ ���������� ��������"
    //                     )                               +
    //                     AnsiString (
    //                         " �� ��������� ����� ������ "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 4:
    //                 S2 +=
    //                     AnsiString (
    //                         "���������� ���, ���������� � ��� ������ ������� ����������� ����������� "
    //                     )                               +
    //                     AnsiString (
    //                         "�� ���� ������� ������� "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 5:
    //                 S2 +=
    //                     AnsiString (
    //                         "��������� �� ������� ������� ������ � ����� � ��� ������ (������. ������ "
    //                     )                               +
    //                     AnsiString (
    //                         "��,������. ������,�� ���) "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //         case 6:                                                             // ��� � 2011 ����
    //                 S2 +=
    //                     AnsiString (
    //                         "������ �/� �� ������� ������ �� 1 ���� "
    //                     )                               +
    //                     (char) (13);
    //             break;
    //     }
    // }


    // len = Stat_ab_pr.Length ();                                                 // ������������ ��� ����������

    // int len_old = len,
    //     p       = 0;                                                            // ������� ������� ������� ��������� �����

    // for ( int i =  1;                                                           // for Priv
    //           i <= len_old;
    //           ++i
    //     )
    // {
    //     if (len != 0)                                                           // if ���� ��� ������
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
    //                                 "���������� ���,���. ��������� "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 2:
    //                         S2 +=
    //                             AnsiString (
    //                                 "���������� ���������� �����. ��������� "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 3:
    //                         S2 +=
    //                             AnsiString (
    //                                 "���� ������������ ������ �� ����� 6 ������� �� ������������� "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 4:
    //                         S2 +=
    //                             AnsiString (
    //                                 "���������� ��� ����� "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 5:
    //                         S2 +=
    //                             AnsiString (
    //                                 "���������� ( I ������� ) 3-�� ����� ����. ��������� "
    //                             );
    //                     break;
    //                 case 6:
    //                         S2 +=
    //                             AnsiString (
    //                                 "���������� (I ,II,III �������) ����. ��������� (���. � �����. ��) "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 7:
    //                         S2 +=
    //                             AnsiString (
    //                                 "�� ��,���� �� "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 8:
    //                         S2 +=
    //                             AnsiString (
    //                                 "������� � ���������� ������ "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 9:
    //                         S2 +=
    //                             AnsiString (
    //                                 "������ � �������� ����-���. �����-� "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 10:
    //                         S2 +=
    //                             AnsiString (
    //                                 "������ � �������� ���� "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 11:
    //                         S2 +=
    //                             AnsiString (
    //                                 "������������� � �������� � ���. �����-� "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 case 12:
    //                         S2 +=
    //                             AnsiString (
    //                                 "��������. ���. ������� ����� (������ ���) "
    //                             ) +
    //                             (char) (13);
    //                     break;
    //                 // case 13:
    //                 //         S2 +=
    //                 //             "������ � ���. (������� �����������) ";
    //                 //     break;
    //                 // case 14:
    //                 //         S2 += "��������� ��� ";
    //                 //     break;
    //                 // case 15:
    //                 //         S2 +=
    //                 //             "��������� �� ����� (6 ���.) ";
    //                 //     break;
    //                 // case 16:
    //                 //         S2 += "�������� ����� ";
    //                 //     break;
    //                 // case 17:
    //                 //         S2 +=
    //                 //             "������ � ���. (������ �����������) ";
    //                 //     break;
    //                 // case 18:
    //                 //         S2 += "��������� �� ����� ";
    //                 //     break;
    //                 // case 19:
    //                 //         S2 +=
    //                 //             "���� ����� 2-� ��� (���. �������������) ";
    //                 //     break;
    //                 // case 20:                                                    // ��������� �� ������� ����� ������� ����
    //                 //         S2 += "";
    //                 //     break;
    //                 // case 21:
    //                 //         S2 +=
    //                 //             "��������� �� �����. ������ � ��� ������ (������.������: ��, ������.������, �� ���)";
    //                 //     break;
    //                 // case 22:                                                    // ��������� �� ������� ����� ������� ����
    //                 //         S2 +=
    //                 //             "��������� ���������� ������� ���������";
    //                 //     break;
    //                 // case 23:                                                    // ������ � ���. (�� ���� �������� �����������)
    //                 //         S2 += "";
    //                 //     break;
    //             }
    //         }
    //     }
    //     else
    //         break;

        String NameSertificat;                                                  // '����������'

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
                case 0:                                                         // ���
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
                                 != "��"
                               )
                                NameSertificat +=
                                    " - "                                           +
                                    DM -> WithOutTestLogQrSHORT_NAME_1 -> Value;

                            DM -> WithOutTestLogQr -> Next ();
                        }

                        DM -> WithOutTestLogQr -> Close ();
                    break;
                case 1:                                                         // ��
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
                                 != "��"
                               )
                                NameSertificat +=
                                    " - "                                   +
                                    DM -> OutTestQrSHORT_NAME_1 -> Value;

                            DM -> OutTestQr -> Next ();
                        }

                        DM -> OutTestQr -> Close ();
                    break;
                case 2:                                                         // ������
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
void __fastcall TMainForm::Protokol4_J (int pol)                                // ��� ������� 4 ����
{
    DMVed -> QGroupProtokol -> Close ();
    DMVed -> QGroupProtokol ->
        ParamByName ("fac") -> Value = nom_fac;
    DMVed -> QGroupProtokol -> Open ();


    ExcelApplication = Variant::CreateObject ("Excel.Application");             // �������� �������

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

    OVisible (ExcelApplication);                                                // �������
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

    for ( int i = 0;                                                            // ������� ����
              i < DMVed -> QGroupProtokol -> RecordCount;
              ++i
        )
    {
        Sheet =                                                                 // ������� ���� � ������� ������
            SelectSheet (
                Workbook,
                "������"
            );

        CopySheet (Sheet);

        Sheet =
            SelectSheet (
                Workbook,
                "������ (2)"
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

        if (pol == 2)                                                           // ������� �� ������ �������
            DMVed -> QPeopleProtocol ->
                ParamByName ("pol") -> Value = "�";

        if (pol == 1)
            DMVed -> QPeopleProtocol ->
                ParamByName ("pol") -> Value = "�";

        DMVed -> QPeopleProtocol -> Open ();

        CellValue (                                                             // ���������� � ������ � ������� ����� ������
            DMVed -> QGroupProtokolNOM_GROUP -> Value,
            3,
            3
        );

        int k = 6;

        for ( int j = 0;                                                        // ��� �� Query
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
                    "�",
                    3,
                    k++
                );

            if (pol == 1)
                CellValue (
                    "�",
                    3,
                    k++
                );

            DMVed -> QPeopleProtocol -> Next ();
        }

        DMVed -> QGroupProtokol -> Next ();
    }

    WorkSaveAs = SaveBook (Workbook);                                           // ����������

    ExcelApplication.Clear ();
}
AnsiString TMainForm::ReturnField (AnsiString f)                                // ���������� �������� ����
{
    Variant rez =
        qq -> Fields -> FieldByName (f) -> Value;

    if (rez.IsNull ())
        return
            "";

    return
        rez.AsType (varString);
}
AnsiString TMainForm::ReturnField_IT (AnsiString f)                             // ���������� �������� ����
{
    Variant rez =
        qq -> Fields -> FieldByName (f) -> Value;

    if (rez.IsNull ())
        return
            "";

    return
        rez.AsType (varString);
}
void __fastcall TMainForm::Run_ProcBall (                                       // ����� ��������� � �������� ���������� �� ����� ������
        int fac,
        int ed,
        int konk,
        int price,
        int kolon,
        int stroka_n
    )
{
    if (konk == 0)                                                              // ��� ����������� �� 1-�� ����
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

        int temp  = 0;                                                           // ��������� ����������
            kolon = 46;

        for ( int i = 4;                                                        // �������� �� ��������� - ���������� ������
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
    else                                                                        // ��� ����������� �� 2-�� ����
    {
        if (fac == 1)                                                           // ���� + ���
        {
            DM -> RaspredBall12StrdPrc -> Close ();

            DM -> RaspredBall12StrdPrc ->
                ParamByName ("VID_EDU") -> AsSmallInt = ed;

            DM -> RaspredBall12StrdPrc ->
                ParamByName ("PRICE")   -> AsSmallInt = price;

            DM -> RaspredBall12StrdPrc -> Prepare ();
            DM -> RaspredBall12StrdPrc -> ExecProc ();


            int temp  = 0;                                                      // ��������� ����������
                kolon = 46;

            for ( int i = 2;                                                    // �������� �� ��������� - ���������� ������
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
                "���������-�������������� ��������� ���������� ��� "    \
                "� �����������\n\n���������-�������������� ��������� "  \
                "�������� ����� ������",
                1,
                14
            );
        }


        if (    fac == 3                                                        // �����,���
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

            for ( int i = 3;                                                    // �������� �� ��������� - ���������� ������
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
void __fastcall TMainForm::Shapka_spisok (                                      // ����� ������� '������� ������������'
        int col_pred                                                            // ���������� ���������
    )
{
    BorderCell (
        1,                                                                      // 1-�� ������ ������ ������ �����������
        7,
        1,
        2
    );


    CellValue (
        "� �/�",
        2,                                                                      // 2-�� ������ � � �/�
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
        "������� ��� ��������",
        3,                                                                      // 3-�� ������ � ���
        7
    );
    BorderCell (
        3,
        7,
        1,
        2
    );


    CellValue (
        "������",
        4,                                                                      // 4-�� ������ (�������� ������ � 2004 �)
        7
    );
    BorderCell (
        4,
        7,
        1,
        2
    );

    DM -> TPredmet -> First ();                                                 // 5-�� - i-��� ������ ��� ���������

    nom_pr = new int [col_pred];

    for ( int i =  1;
              i <= col_pred;
              ++i
        )
    {
        nom_pr [i - 1] = DM -> TPredmetN_PREDMET -> Value;

        if (     DM -> TPredmetTEXT_PREDMET -> Value
             ==  "����������� ���� (������� ����) ���������"
           )
            CellValue (
                "���������",
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
        "������� ����",
        5 + col_pred,                                                           // 5 + i -- ������ ��� �������� ����� ���������� ������
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
        "����� ������",
        6 + col_pred,                                                           // 6 + i -- ������ ��� �������� ����� ���������� ������
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
        "����������",
        7 + col_pred,                                                           // 7 + i -- ������ ��� ����������,��� ������������ ��� ����������
        7
    );
    BorderCell (
        7 + col_pred,
        7,
        1,
        2
    );

    alignHVCells (                                                              // ����� ������������� �� ������
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
    MergeCellCenter (                                                           // �������������� '����������'
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


    MergeCellCenter (                                                           // �������������� '���� ��������'
        1,
        7,
        4
    );
    CellValue (
        DM -> QSpisoc_Group_PolVID_EDU1 -> Value,
        1,
        4
    );


    MergeCellCenter (                                                           // �������������� '������ ������'
        1,
        7,
        5
    );
    CellValue (
        "������ � " +
            n_gr    +
        " ("        +
            pol     +
        ")",
        1,
        5
    );


    BorderCell (                                                                // ������������ '����� �������' (1-�� ������ ������ ������ �����������)
        1,
        7,
        1,
        2
    );


    CellValue (                                                                 // 2-�� ������ � '� �/�'
        "� �/�",
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


    CellValue (                                                                 // 3-�� ������ � '���'
        "������� ��� ��������",
        3,
        7
    );
    BorderCell (
        3,
        7,
        1,
        2
    );

    alignHVCells (                                                              // '�����' ������������� �� ������
        1,
        6,
        7,
        3,
        2
    );


    MergeCellCenter (                                                           // �������������� '�������������'
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
        Str1 = "����� ����������",
        Str2 = "������� ����� ���������",
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
                "�������� ���������� ��� ����� ����������!\n"       \
                "��������� ��� � MainUnit -> SpeedButton1Click ()"
            );
        }
    }
}
void __fastcall TMainForm::SpeedButton2Click (TObject * Sender)                 // �������� '������������ ����� ����'
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
        Str1 = "���������",
        Str2 = "������� ���������",
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
                Str1 = "��� ��������",
                Str2 = "������� ��� ��������",
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
                        Str1 = "������ �����������",
                        Str2 = "������� ������ �����������",
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
                                    "�������� ���������� ��� �������� " \
                                    "������!\n������ MainUnit -> "      \
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
                            "�������� ���������� ��� �������� ������� " \
                            "�����������!\n������ MainUnit -> "         \
                            "SpeedButton3Click ()"
                        );
                }
            }
        }
        catch (...)
        {
            return
                ShowMessage (
                    "�������� ���������� ��� �������� ���� ��������!\n" \
                    "������ MainUnit -> SpeedButton3Click ()"
                );
        }
    }
}
void __fastcall TMainForm::SpeedButton4Click (TObject * Sender)                 // ����������� ����
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

    int        j    = 1;                                                        // ���������� �����
    int        rec  = DM -> QSpisoc_Group_Pol -> RecordCount;                   // ���������� ������� � ������


    if (n_gr == "")                                                             // begin ������������ ������
        return;

    Shapka_spisok_Pol (
        n_gr,
        pol
    );


    int nom_stroka = 9;                                                         // ����� ������
    int spec       = DM -> QSpisoc_Group_PolN_SPECIALIZ -> Value;


    Data_spisok_Pol (
        nom_stroka,
        j
    );

    ++nom_stroka;


    for ( int i =  2;                                                           // ���� �� ������������ (� ������ ������ ������ � �������������)
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


                MergeCellCenter (                                               // �������������� ������ ��� ��������� �������������
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
            for ( int i =  1;                                                   // ���������� ������ �������
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
int __fastcall TMainForm::Svod_ved (                                            // ������� ���������
        int nom_str,                                                            // ������� �����
        int konk,                                                               // �������, �������� ��� ����������� ����� ��������� ������������
        int vid_edu,                                                            // ��� ��������
        int rec_pred,                                                           // ���������� ���������
        int price,                                                              // ������� �������������� 0-������ 1-�� ������
        int pr_ved                                                              // 0 - ������ ����, 1 - ����. ���� + ���, 2 - 2 �� 2 ����
    )
{
    AnsiString
        Addres       = "",                                                      // �������� �����
        date_r       = "",                                                      // ���� ��������
        dogovor      = "",                                                      // �������� �� ������
        Fio          = "",                                                      // ������� ��� ��������
        konk_str     = "",                                                      // ������ ��� ������ ��������
        Mid_ball     = "",                                                      // ������� ���� ���������
        n_delo       = "",                                                      // ����� ����
        Name_mid     = "",                                                      // ������������ ����������� ��������
        Name_spec    = "",                                                      // ������������ ����������� ������������
        pol          = "",                                                      // ���
        shapka       = "",                                                      // ����� (��� ��������)
        Sport        = "",                                                      // ���������� ������
        Stag         = "",                                                      // ����� ����
        Stag_sp      = "",                                                      // ���� �� �������������
        Sum_ball     = "",                                                      // ����� ������ �� ���������
        When_mid     = "",                                                      // ����� ��������  ����������� �������
        When_spec    = "";                                                      // ����� �������� ����������� �����������

    double
        Sum_ball_Fiz = 0;

    int
        nomer_ab,                                                               // ����� �����������
        rec          = 0;                                                       // ���������� �������


    if (price)
        dogovor = " �� ������� ������";


    switch (pr_ved)
    {
        case 0:                                                                 // ������ ����
                qq =
                    DMVed -> QKonkurs;
            break;
        case 1:                                                                 // ���������� ���� + ���
                if (    nom_fac == 1
                     || nom_fac == 2
                   )
                    qq = DMVed -> QKonkurs12;
                else
                    qq = DMVed -> QKonkurs34;
            break;
        case 2:                                                                 // ������ ����
                qq = DMVed -> QKonkurs2V;
            break;
    }


    switch (konk)
    {
        case 0:                                                                 // ����� �������
                shapka =
                    "�������� ���������� �� ������ ��������"                +
                        dogovor;
            break;
        case 1:                                                                 // ���
                shapka =
                    "�������� ���������� ��� ������������� ���������"       +
                        dogovor;
            break;
        case 2:                                                                 // ������ ����
                shapka =
                    "�������� ���������� ��� ��������"                      +
                        dogovor;
            break;
        case 3:                                                                 // ��� ��������
                shapka =
                    "�������� ���������� �� �������� ������� ����������"    +
                        dogovor;
            break;
    }


    CellValue (                                                                 // ��������� �����
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


    for ( int k = 0;                                                            // ���� �� ������������
              k < rec;
              ++k
        )
    {
        nomer_ab =                                                              // ����� �����������
            qq -> FieldByName ("out_nomer_ab") -> Value;

        Fio = ReturnField ("out_FIO");                                          // ������� ���  ��������

        if (pr_ved == 1)                                                        // ���������� ���� + ���
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

        n_delo    =                                                             // ����� ����
            "'"                                             +
            DM -> NumDelaString (
                vid_edu,
                qq -> FieldByName ("out_term_edu") -> Value,
                price,
                qq -> FieldByName ("out_n_dela")   -> Value
            );

        date_r    = ReturnField ("out_date_r");                                 // ���� ��������

        pol       = ReturnField ("out_pol");                                    // ���

        Name_mid  = ReturnField ("out_name_edu_middle");                        // ������������ ����������� ��������

        Name_spec = ReturnField ("out_name_edu_spec");                          // ������������ ����������� ������������

        When_mid  = ReturnField ("out_when_edu_middle");                        // ����� ��������  ����������� �������

        When_spec = ReturnField ("out_when_edu_spec");                          // ����� �������� ����������� �����������

        Stag      = ReturnField ("out_stag");                                   // ����� ����

        Stag_sp   = ReturnField ("out_stag_spec");                              // ���� �� �������������

        Sport     = ReturnField ("out_sport_category");                         // ���������� ������

        Sum_ball  = ReturnField ("out_sum_ball");                               // ����� ������ �� ���������


        if (    nom_fac == 4
             && konk    == 3
           )
            Mid_ball = ReturnField_IT ("out_middle_ball");                      // ������� ���� ���������
        else
            Mid_ball = ReturnField ("out_middle_ball");                         // ������� ���� ���������


        Addres    = ReturnField ("out_address_before");                         // �������� �����


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


        AnsiString edu = "";                                                    // ��� ������������ ������ � ���� �����������

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


        DMVed -> QPredmet_Ball -> Close ();                                     // ��������

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
                                "0,0"                                           // 0.0 � ����� Excel ����� ����� ������
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


        if (    nom_fac == 1                                                    // ��� ���� ���������� � (��� � ��?)
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
                "0,0"                                                           // 0.0 � ����� Excel ����� ����� ������
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
            Mid_ball,                                                           // ������� ����
            12,
            nom_str
        );


        if (Sum_ball == "")
            Sum_ball = "0";


        CellFormula (                                                           // ����� ������ - ������������� (=����(I1+J1+K1+L1))
            "=����(I"                   +
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
            Addres,                                                             // �����
            14,
            nom_str
        );


        switch (konk)
        {
            case 0:
                    CellValue (
                        "�����",
                        15,
                        nom_str
                    );
                break;
            case 1:
                    CellValue (
                        "���",
                        15,
                        nom_str
                    );
                break;
            case 2:
                    CellValue (
                        "��",
                        15,
                        nom_str
                    );
                break;
            case 3:
                    CellValue (
                        "��",
                        15,
                        nom_str
                    );
                break;
        }



        S2 = "";                                                                // '����������' ��� ���������� � ������������

        AnsiString
            Stat_ab_vk = "",                                                    // ��� ��������
            Stat_ab_pr = "",                                                    // ����������
            Stat_ab_wo = "";                                                    // ��� ���������

        // int        n_ab;                                                        // ����� �����������


        switch (konk)
        {
            case 1:
                    if (S2 == "")
                        S2 = "���";
                    else
                        S2 += ", ���";
                break;
            case 2:
                    if (S2 == "")
                        S2 = "��";
                    else
                        S2 += ", ��";
                break;
            case 3:
                    if (S2 == "")
                        S2 = "��";
                    else
                        S2 += ", ��";
                break;
        }


        switch ((int)qq -> FieldByName ("out_term_edu") -> Value)
        {
            case 1:
                    if (S2 == "")
                        if (    nom_fac == 3
                             && vid_edu == 1
                           )
                            S2 = "��� 3�.";
                        else
                            S2 = "��� 2�.";
                    else
                        if (    nom_fac == 3
                             && vid_edu == 1
                           )
                            S2 += ", ��� 3�.";
                        else
                            S2 += ", ��� 2�.";
                break;
            case 2:
                    if (S2 == "")
                        S2 = "�� 1�.";
                    else
                        S2 += ", �� 1�.";
                break;
            case 3:
                    if (S2 == "")
                        S2 = "�� 2�.";
                    else
                        S2 += ", �� 2�.";
                break;
        }


        if (qq -> FieldByName ("out_n_ck") -> Value > -1)                       // ��
        {
            if (S2 == "")
                S2 = "������� ������� (";
            else
                S2 += ", ������� ������� (";


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


            S2 += AnsiString (" �-�) ");

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
                case 0:                                                         // ���
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
                                    S2 = "���";
                                else
                                    S2 += ", ���";
                            }

                            pr_bvi = 1;

                            if (S2 != "")
                                S2 += ", ";

                            S2 +=
                                DM -> WithOutTestLogQrSHORT_NAME -> Value;

                            if (    DM -> WithOutTestLogQrSHORT_NAME_1 -> Value
                                 != "��"
                               )
                                S2 +=
                                    " - "                                       +
                                    DM -> WithOutTestLogQrSHORT_NAME_1 -> Value;

                            DM -> WithOutTestLogQr -> Next ();
                        }

                        DM -> WithOutTestLogQr -> Close ();
                    break;
                case 1:                                                         // ��
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
                                    S2 = "��";
                                else
                                    S2 += ", ��";
                            }

                            pr_vk = 1;

                            if (S2 != "")
                                S2 += ",";

                            S2 +=
                                DM -> OutTestQrSHORT_NAME -> Value;

                            if (    DM -> OutTestQrSHORT_NAME_1 -> Value
                                 != "��"
                               )
                                S2 +=
                                    " - "                                   +
                                    DM -> OutTestQrSHORT_NAME_1 -> Value;

                            DM -> OutTestQr -> Next ();
                        }

                        DM -> OutTestQr -> Close ();

                        pr_vk = 1;
                    break;
                case 2:                                                         // ������
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

        if (konk != 2)                                                          // �� ����
            Clear_mas (nomer_ab);


        qq -> Next ();                                                          // ������� � ����� ������
    }

    return
        nom_str++;
}
void __fastcall TMainForm::Zachisl_Sertificat (                                 // �����������
        int  f,
        int  v,
        int  s,
        bool all                                                                // true - ��� �����������
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
                "��� ����� ������������"
            );


    int
        n_ab = 0,
        str  = 5;


    ExcelApplication = Variant::CreateObject ("Excel.Application");             // �������� ������� � �������� ���������� �����

    Variant Workbook = NewBook (ExcelApplication);

    Sheet =
        SelectSheet (
            Workbook,
            "����1"
        );

    DisplayAlert (ExcelApplication);
    OVisible (ExcelApplication);


    AnsiString zagolovok = "���������� �� ";                                    // ���������

    switch (s)
    {
        case 0:
                zagolovok += "�������� ��������� ";
            break;
        case 1:
                zagolovok += "������������ � ��������� ";
            break;
        case 2:
                zagolovok += "�� ����������� �������� ";
            break;
        case 3:
                zagolovok += "����������� �� ������� ";
            break;
        case 4:
                zagolovok += "��������� ��������� �� ����� �������� ";
            break;
        case 5:
                zagolovok += " ����������� ";
            break;
    }

    zagolovok +=
        "� �� ����� � "             +
            Admissions::TIME::YEAR  +
        " ����";

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
                "������� ����� ��������� �����������",
                1,
                3
            );
        else
            CellValue (
                "������� ����� ��������� �����������",
                1,
                3
            );
    }


    CellValue (                                                                 // �����
        "�������",
        1,
        str
    );
    CellValue (
        "���",
        2,
        str
    );
    CellValue (
        "��������",
        3,
        str
    );
    CellValue (
        "����� ��������",
        4,
        str
    );
    CellValue (
        "� ��������",
        5,
        str
    );
    CellValue (
        "���� ���.�� (���.��)",
        6,
        str
    );
    CellValue (
        "���� ��������",
        7,
        str
    );
    CellValue (
        "���� ����������",
        8,
        str
    );
    CellValue (
        "���� ���������",
        9,
        str
    );
    CellValue (
        "�������",
        10,
        str
    );
    CellValue (
        "����������",
        11,
        str
    );


    for ( int i = 0;
              i < rec;
              ++i
        )
    {
        if (n_ab != DMStat -> QZachisl_SertificatNOMER_AB -> Value)             // 1 ���
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


        AnsiString pasp =                                                       // 4 � 5 �������
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
        CellValue (                                                             // ����� ��������
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
        CellValue (                                                             // ����� ��������
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
                    stolb = 6;                                                  // 6 - ���
                break;
            case 1:
                    stolb = 6;                                                  // 6 - ���
                break;
            case 2:
                    stolb = 7;                                                  // 7 - ����
                break;
            case 3:
                    stolb = 8;                                                  // 8 - �����
                break;
            case 4:
                    stolb = 9;                                                  // 9 - �����
                break;
        }

        int b = DMStat -> QZachisl_SertificatBALLS -> Value;

        if (b)
            CellValue (
                b,
                stolb,
                str
            );

        AnsiString k = "";                                                      // �������

        switch (DMStat -> QZachisl_SertificatKONKURS -> Value)
        {
            case 0:
                    k = "�����";
                break;
            case 1:
                    k = "������� �������";
                break;
            case 2:
                    k = "����������� ���� ��������";
                break;
            case 3:
                    k = "��� ��������";
                break;
            case 4:
                    k = "��� ���������";
                break;
            case 5:
                    k = "����������� ��������";
                break;
        }

        CellValue (
            k,
            10,
            str
        );

        Variant prim =                                                          // ����������
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


    for ( int i =  1;                                                           // ---���������� ���������� �����
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


    for ( int i =  1;                                                           // ���������� ������ �������
              i <= 11;
              ++i
        )
        AutoFitColumn (
            Sheet,
            i
        );


    ExcelApplication.Clear ();
}
