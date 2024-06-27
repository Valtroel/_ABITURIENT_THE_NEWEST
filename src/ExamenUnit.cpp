#include <vcl.h>
#pragma hdrstop


#include "DMUnit.h"
#include "ExamenUnit.h"
#include "Func.h"


#pragma package (smart_init)
//#pragma link "RXToolEdit"
#pragma resource "*.dfm"


TExamenForm * ExamenForm;


AnsiString *
    mas_fio_nomdela[3];

AnsiString
    vid_ed;                                                                     // ���������� ��� ��������� � ��������� ���� ��������

int
    col_ab,
    mas_v   = 0;                                                                // ������� ������ � ������� 0 - ���, 1 - ����

Variant
    ExcelApp;



__fastcall TExamenForm::TExamenForm (TComponent * Owner)
    : TForm (Owner)
{ }


void __fastcall TExamenForm::Button1Click (TObject * Sender)
{
    String
        new_num_dela;

    AnsiString
        text_soch_bel   = "���. ���.",
        text_soch_rus   = "���. ���.",
        text_spec       = "���������.",
        text_test_bel   = "���� ���.",
        text_test_biol  = "���� ����.",
        text_test_geogr = "���� �����.",
        text_test_matem = "���� �����.",
        text_test_rus   = "���� ���.";

    if (Edit1 -> Text != "")
    {
        SG1          -> Visible = true;
        SpeedButton1 -> Visible = true;
        SpeedButton2 -> Visible = true;
        SpeedButton3 -> Visible = true;
        SpeedButton4 -> Visible = true;
        SpeedButton5 -> Visible = true;
        Panel2       -> Visible = true;
        ListBox1     -> Visible = true;

        for (int i = 1;                                                         // ������� StringGrid
                 i < SG1 -> RowCount;
                 ++i
            )
            for (int j = 0;
                     j < 3;
                     ++j
                )
                SG1 -> Cells[j][i] = "";

        ListBox1 -> Clear ();

        try
        {
            Variant ca =
                DM -> QGroup_Count ->
                    Lookup (
                        "NOM_GROUP",
                        Edit1 -> Text,
                        "COUNT"
                    );

            if (ca.IsNull ())
            {
                Edit1Change (
                    this
                );

                return
                    ShowMessage (
                        "��� ������������ � ���� ������!"
                    );
            }
            else
                col_ab =
                    ca.AsType (
                        varInteger
                    );

            // col_ab =
            //     int (
            //         DM -> QGroup_Count ->
            //             Lookup (
            //                 "NOM_GROUP",
            //                 Edit1 -> Text,
            //                 "COUNT"
            //             )
            //         );
            // if (!col_ab)
            // {
            //     return
            //         ShowMessage (
            //             "����������� ������ ����� ������!"
            //         );
            // }
        }
        catch (...)
        {
            Edit1Change (
                this
            );

            return;
                ShowMessage (
                    "����������� ������ ����� ������!"
                );
        }

        if (mas_v)                                                              // clear previous values
        {
            for (int i = 0;
                     i < 3;
                     ++i
                )
                delete [] mas_fio_nomdela[i];

            if (mas_fio_nomdela)
                delete [] mas_fio_nomdela;

            mas_v = 0;
        }

        for (int i = 0;                                                         // create new array
                 i < 3;
                 ++i
            )
            mas_fio_nomdela[i] = new AnsiString[col_ab];

        mas_v = 1;

        SG1 -> RowCount = col_ab + 1;

        DM -> QExam -> Close ();
        DM -> QExam ->
            ParamByName ("N_GR")  -> AsString =
                Edit1 -> Text;
        DM -> QExam ->
            ParamByName ("N_FAC") -> Value    =
                nom_fac;
        DM -> QExam -> Open ();

        if (!DM -> QExamVID_EDU -> Value)
            vid_ed = "������� ����� ��������� �����������";
        else
            vid_ed = "������� ����� ��������� �����������";

        AnsiString
            bal,
            fam,
            str = "";

        int
            n_abit;

        for (int i =  1;
                 i <= col_ab;
                 ++i
            )
        {
            new_num_dela =
                DM -> NumDelaString (
                    DM -> QExamVID_EDU  -> Value,
                    DM -> QExamTERM_EDU -> Value,
                    DM -> QExamPRICE    -> Value,
                    DM -> QExamNOM_DELA -> Value
                );
            n_abit =
                DM -> QExamNOMER_AB -> Value;
            fam    =
                DM -> QExamFAM -> Value;
            str    =
                    fam                     +
                " "                         +
                    DM -> QExamNAME ->
                        Value.SubString (
                            1,
                            1
                        )                   +
                ".";

            if (    DM -> QExamOTCH -> Value != ""
                 || DM -> QExamOTCH -> Value != "-"
               )
                str +=
                    " "                         +
                        DM -> QExamOTCH ->
                            Value.SubString (
                                1,
                                1
                            )                   +
                    ". ["                       +
                        new_num_dela            +
                    "]";

            mas_fio_nomdela[0][i - 1] = str;
            mas_fio_nomdela[1][i - 1] = "'" + new_num_dela;
            mas_fio_nomdela[2][i - 1] = DM -> QExamNOMER_AB -> Value;

            SG1 -> Cells[0][i] = str;                                           // StringGrid 1-�� �������

            switch (DM -> QExamTERM_EDU -> Value)                               // StringGrid 2-�� �������
            {
                case 1:
                        SG1 -> Cells[1][i] =
                            "��� 2�.";
                    break;
                case 2:
                        SG1 -> Cells[1][i] =
                            "��� 3�.";
                    break;
                case 3:
                        SG1 -> Cells[1][i] =
                            "�� 1�.";
                    break;
                case 4:
                        SG1 -> Cells[1][i] =
                            "�� 2�.";
                    break;
                case 5:
                        SG1 -> Cells[1][i] =
                            "�� 3�.";
                    break;

                default:
                        SG1 -> Cells[1][i] = "";
            }

            switch (DM -> QExamKONKURS -> Value)
            {
                case 1:
                        if (SG1 -> Cells[1][i] == "")
                            SG1 -> Cells[1][i] =
                                "���";
                        else
                            SG1 -> Cells[1][i] =
                                    SG1 -> Cells[1][i]  +
                                ", ���";
                    break;
                case 2:
                        if (SG1 -> Cells[1][i] == "")
                            SG1 -> Cells[1][i] =
                                "��";
                        else
                            SG1 -> Cells[1][i] =
                                    SG1 -> Cells[1][i]  +
                                ", ��";
                    break;
                case 3:
                        if (SG1 -> Cells[1][i] == "")
                            SG1 -> Cells[1][i] =
                                "��";
                        else
                            SG1 -> Cells[1][i] =
                                    SG1 -> Cells[1][i]  +
                                ", ��";
                    break;
            }

            switch (DM -> QExamN_SPORT_CATEGORY -> Value)
            {
                case 5:
                        if (SG1 -> Cells[1][i] == "")
                            SG1 -> Cells[1][i] =
                                "��";
                        else
                            SG1 -> Cells[1][i] =
                                    SG1 -> Cells[1][i]  +
                                ", ��";
                    break;
                case 6:
                        if (SG1 -> Cells[1][i] == "")
                            SG1 -> Cells[1][i] =
                                "����";
                        else
                            SG1 -> Cells[1][i] =
                                    SG1 -> Cells[1][i]  +
                                ", ����";
                    break;
                case 7:
                        if (SG1 -> Cells[1][i] == "")
                            SG1 -> Cells[1][i] =
                                "���";
                        else
                            SG1 -> Cells[1][i] =
                                    SG1 -> Cells[1][i]  +
                                ", ���";
                    break;
            }

            if (DM -> QExamCATEGORY_IF -> Value)
                if (SG1 -> Cells[1][i] == "")
                    SG1 -> Cells[1][i] =
                        "����������";
                else
                    SG1 -> Cells[1][i] =
                            SG1 -> Cells[1][i]  +
                        ", ����������";


            if (DM -> QExamN_PREDMET -> Value)
            {
                AnsiString
                    text_pr = DM -> QExamPREDM -> Value;

                // if (text_pr == "����������� ���� (������� ����) ���������")     // RUS_BEL = 0 - ������� ����, 1- ����������� ����
                if (    text_pr == "����������� (�������) ����"
                     || text_pr == "��������"
                     || text_pr == "����������"
                     || text_pr == "���������"
                   )
                {
                    switch (DM -> QExamSTATUS_BALL -> Value)                     // 0 - �������, 1 - ������������, 2 - ���������
                    {
                        case 0:                                                 // �������
                                if (DM -> QExamN_PREDMET -> Value == 4)         // �����
                                {
                                    if (DM -> QExamRUS_BEL -> Value)
                                        bal =
                                                text_soch_bel                   +
                                            " - "                               +
                                                AnsiString (
                                                    DM -> QExamBALL1 -> Value
                                                );
                                    else
                                        bal =
                                                text_soch_rus                   +
                                            " - "                               +
                                                AnsiString (
                                                    DM -> QExamBALL1 -> Value
                                                );
                                }

                                if (    DM -> QExamN_PREDMET -> Value == 1      // ��������
                                     || DM -> QExamN_PREDMET -> Value == 9      // ����������
                                     || DM -> QExamN_PREDMET -> Value == 10     // ���������
                                   )
                                    bal =
                                            DM -> QExamPREDM -> Value       +
                                        " - "                               +
                                            AnsiString (
                                                DM -> QExamBALL1 -> Value
                                            );
                            break;
                        case 2:                                                 // ���������
                                bal =
                                        DM -> QExamPREDM -> Value       +
                                    " (�����.) - "                      +
                                        AnsiString (
                                            DM -> QExamBALL1 -> Value
                                        );
                            break;
                        case 1:                                                 // ������������

                                DM -> QSertificat -> Close ();
                                DM -> QSertificat ->
                                    ParamByName ("NOMER") -> AsInteger =
                                        DM -> QExamNOMER_AB -> Value;
                                DM -> QSertificat -> Open ();

                                int
                                    st_test =
                                        DM -> QSertificat ->
                                            Lookup (
                                                "NOMER_AB;N_PREDMET",
                                                VarArrayOf (
                                                    OPENARRAY (
                                                        Variant,
                                                        (
                                                            DM -> QExamNOMER_AB  -> Value,
                                                            DM -> QExamN_PREDMET -> Value
                                                        )
                                                    )
                                                ),
                                                "RUS_BEL"
                                            );

                                switch (st_test)
                                {
                                    case 0:                                     // �������
                                            bal =
                                                    text_test_rus       +
                                                " - "                   +
                                                    AnsiString (
                                                        DM -> QExamBALL1 -> Value
                                                    );
                                        break;
                                    case 1:                                     // �����������
                                            bal =
                                                    text_test_bel       +
                                                " - "                   +
                                                    AnsiString (
                                                        DM -> QExamBALL1 -> Value
                                                    );
                                        break;
                                    case 2:                                     // ��������
                                            bal =
                                                    text_test_biol      +
                                                " - "                   +
                                                    AnsiString (
                                                        DM -> QExamBALL1 -> Value
                                                    );
                                        break;
                                    case 3:                                     // ����������
                                            bal =
                                                    text_test_matem     +
                                                " - "                   +
                                                    AnsiString (
                                                        DM -> QExamBALL1 -> Value
                                                    );
                                        break;
                                    case 4:                                     // ���������
                                            bal =
                                                    text_test_geogr     +
                                                " - "                   +
                                                    AnsiString (
                                                        DM -> QExamBALL1 -> Value
                                                    );
                                        break;
                                }
                            break;
                    }

                    // bal =
                    //         text_soch                       +
                    //     " - "                               +
                    //         AnsiString (
                    //             DM -> QExamBALL1 -> Value
                    //         );
                }
                else
                {
                    // if (text_pr == "���������� �������� (���������� �������������)")
                    //     bal =
                    //             text_spec   +
                    //         " - "           +
                    //             AnsiString (
                    //                 DM -> QExamBALL1 -> Value
                    //             );
                    // else
                        bal =
                                DM -> QExamPREDM -> Value       +
                            " - "                               +
                                AnsiString (
                                    DM -> QExamBALL1 -> Value
                                );
                }

                DM -> QExam -> Next ();

                while (     n_abit == DM -> QExamNOMER_AB -> Value
                        && ! DM -> QExam -> Eof
                      )
                {
                    text_pr = DM -> QExamPREDM -> Value;

                    // if (text_pr == "����������� ���� (������� ����) ���������")
                    if (    text_pr == "����������� (�������) ����"
                         || text_pr == "��������"
                         || text_pr == "����������"
                         || text_pr == "���������")
                    { // RUS_BEL = 0 - ������� ����, 1- ����������� ����
                        switch (DM -> QExamSTATUS_BALL -> Value)                // 0 - ���������, 1 - ������������, 2 - ��������� ���
                        {
                        case 0:                                                 // �������
                                if (DM -> QExamN_PREDMET -> Value == 4)         // �����
                                {
                                    if (DM -> QExamRUS_BEL -> Value)
                                        bal +=
                                            "; "                            +
                                                text_soch_bel               +
                                            " - "                           +
                                                AnsiString (
                                                    DM -> QExamBALL1 -> Value
                                                );
                                    else
                                        bal +=
                                            "; "                            +
                                                text_soch_rus               +
                                            " - "                           +
                                                AnsiString (
                                                    DM -> QExamBALL1 -> Value
                                                );
                                }
                                if (    DM -> QExamN_PREDMET -> Value == 1      // ��������
                                     || DM -> QExamN_PREDMET -> Value == 9      // ����������
                                     || DM -> QExamN_PREDMET -> Value == 10     // ���������
                                )
                                    bal +=
                                        "; "                            +
                                            DM -> QExamPREDM -> Value   +
                                        " - "                           +
                                            AnsiString (
                                                DM -> QExamBALL1 -> Value
                                            );
                            break;
                        case 2:
                                bal +=
                                    "; "                                +
                                        DM -> QExamPREDM -> Value       +
                                    " (�����.) - "                      +
                                        AnsiString (
                                            DM -> QExamBALL1 -> Value
                                        );
                            break;
                        case 1:                                                 // ������������
                                DM -> QSertificat -> Close ();
                                DM -> QSertificat ->
                                    ParamByName ("NOMER") -> AsInteger =
                                        DM -> QExamNOMER_AB -> Value;
                                DM -> QSertificat -> Open ();

                                int
                                    st_test =
                                        DM -> QSertificat ->
                                            Lookup (
                                                "NOMER_AB;N_PREDMET",
                                                VarArrayOf (
                                                    OPENARRAY (
                                                        Variant,
                                                        (
                                                            DM -> QExamNOMER_AB  -> Value,
                                                            DM -> QExamN_PREDMET -> Value
                                                        )
                                                    )
                                                ),
                                                "RUS_BEL"
                                            );

                                switch (st_test)
                                {
                                    case 0:                                     // �������
                                            bal +=
                                                "; "                    +
                                                    text_test_rus       +
                                                " - "                   +
                                                    AnsiString (
                                                        DM -> QExamBALL1 -> Value
                                                    );
                                        break;
                                    case 1:                                     // �����������
                                            bal +=
                                                "; "                    +
                                                    text_test_bel       +
                                                " - "                   +
                                                    AnsiString (
                                                        DM -> QExamBALL1 -> Value
                                                    );
                                        break;
                                    case 2:                                     // ��������
                                            bal +=
                                                "; "                    +
                                                    text_test_biol      +
                                                " - "                   +
                                                    AnsiString (
                                                        DM -> QExamBALL1 -> Value
                                                    );
                                        break;
                                    case 3:                                     // ����������
                                            bal +=
                                                "; "                    +
                                                    text_test_matem     +
                                                " - "                   +
                                                    AnsiString (
                                                        DM -> QExamBALL1 -> Value
                                                    );
                                        break;
                                    case 4:                                     // ���������
                                            bal +=
                                                "; "                    +
                                                    text_test_geogr     +
                                                " - "                   +
                                                AnsiString (
                                                    DM -> QExamBALL1 -> Value
                                                );
                                        break;
                                }
                            break;
                        }

                        // bal  +=
                        //     ", "                                +
                        //         text_soch                       +
                        //     " - "                               +
                        //         AnsiString (
                        //             DM -> QExamBALL1 -> Value
                        //         );
                    }
                    else
                    {
                        // if (text_pr == "���������� �������� (���������� �������������)")
                        //     bal +=
                        //         ", "                                +
                        //             text_spec                       +
                        //         " - "                               +
                        //             AnsiString (
                        //                 DM -> QExamBALL1 -> Value
                        //             );
                        // else

                        bal +=
                            "; "                                +
                                DM -> QExamPREDM -> Value       +
                            " - "                               +
                                AnsiString (
                                    DM -> QExamBALL1 -> Value
                                );
                    }

                    DM -> QExam -> Next ();
                }
                SG1 -> Cells[2][i] = bal;
            }
            else
                DM -> QExam -> Next ();
        }

        ExamenForm -> Height = 585;

        // Button2 -> Visible = true;
    }
    else
    {
        ShowMessage (
            "������� ����� ������"
        );

        Edit1 -> SetFocus ();
    }

}
void __fastcall TExamenForm::Button2Click (TObject * Sender)
{
    if (ListBox1 -> Items -> Count)
    {
        int list_count =
            ListBox1 -> Items -> Count;

        AnsiString list_fio = "";

        for (int i = 0;
                 i < list_count - 1;
                 ++i
            )
        {
            if (    ListBox1 -> Items -> Strings[i]
                 == ListBox1 -> Items -> Strings[i + 1]
               )
            {
                list_fio =
                    "����������\n"                      +
                        ListBox1 -> Items -> Strings[i] +
                    "\n��� ������ � ������";
                AnsiString ansi_string1 =
                    "������� �� ������ ������ �����?";

                wchar_t * UnicodeString1 =
                    new wchar_t[ansi_string1.WideCharBufSize ()];

                ansi_string1.WideChar (
                    UnicodeString1,
                    ansi_string1.WideCharBufSize ()
                );
                ansi_string1 =
                    list_fio.c_str ();

                wchar_t * UnicodeString2 =
                    new wchar_t[ansi_string1.WideCharBufSize ()];

                ansi_string1.WideChar (
                    UnicodeString2,
                    ansi_string1.WideCharBufSize ()
                );

                if (    Application -> MessageBox (                             // ������� �� ������ ������ �����
                            UnicodeString1,
                            UnicodeString2,
                            MB_YESNO
                        ) == IDYES
                   )
                {
                    ListBox1 -> ItemIndex = i;
                    ListBox1 -> Items ->
                        Delete (
                            ListBox1 -> ItemIndex
                        );

                    --list_count;
                    --i;
                }

                if (UnicodeString1)
                    delete [] UnicodeString1;
                if (UnicodeString2)
                    delete [] UnicodeString2;
            }
        }

        if (    DBLookupComboBox1 -> Text != ""
            // && DateEdit1 -> Text != "  .  .    "
           )
        {
            int n_pr = DBLookupComboBox1 -> KeyValue;                           // ���������� ��� ��������� � EXAMEN ������ ��������

            if ( MaskEdit1 -> EditText != "  .  ")                                // if ���� ��������� �� ��������� - �� ���� ������� ���� ������ ��������
            {
                if (!DM -> QResult_Exam -> Active)
                    DM -> QResult_Exam -> Open ();

                TLocateOptions
                    flag;

                AnsiString
                    sss = "";                                                   // --- �������� ������������ �� ������� � ������� ����������� ���������

                for (int i = 0;
                         i < ListBox1 -> Items -> Count;
                         ++i
                    )
                {
                    if (    DM -> QResult_Exam ->
                                Locate (
                                    "NOMER_AB;N_PREDMET",
                                    VarArrayOf (
                                        OPENARRAY (
                                            Variant,
                                            (
                                                StrToInt (
                                                    search_nomdela (
                                                        col_ab,
                                                        ListBox1 -> Items ->
                                                            Strings[i],
                                                        2
                                                    )
                                                ),
                                                n_pr
                                            )
                                        )
                                    ),
                                    flag
                                )
                       )
                        sss += ListBox1 -> Items -> Strings[i] + ". ";
                }

                if (sss == "")                                                  // if  �������� �� ������� � ������� ����������� ���������
                {
                    ExcelApp =
                        Variant::CreateObject (
                            "Excel.Application"
                        );
                    Variant Workbook =
                        OpenBook (
                            ExcelApp,
                            cur_dir                         +
                            DocumentFile::PROTOCOL::exam
                        );

                    Variant Sheet =
                        SelectSheet (
                            Workbook,
                            "��������������� ���������"
                        );

                    CellValue (                                                 // ���������
                        fac1,
                        3,
                        10
                    );

                    if (nom_fac == 4)                                           // ��� ��������� �������
                        CellValue (
                            " ���������� ��������, �������� ����",
                            1,
                            2
                        );
                    CellValue (                                                 // ��� ��������
                        vid_ed,
                        1,
                        4
                    );
                    CellValue (                                                 // ���� ���.
                        DateTimePicker1 -> Date,
                        3,
                        12
                    );
                    CellValue (                                                 // ������
                        "������ � "     +
                            Edit1 -> Text,
                            7,
                            10
                    );
                    CellValue (                                                 // �������
                        DBLookupComboBox1 -> Text,
                        4,
                        8
                    );

                    if (n_pr != 4)
                        CellValue (
                            MaskEdit1 -> EditText,                              // ������ ���.
                            3,
                            13
                        );

                    if (!RG1 -> ItemIndex)                                        // if ���� ������ ���������, �� ������� ��� � ���������
                    {
                        int n_st = 19;                                          // ������ ������ ��� ��������� �������

                        for (int i = 0; i < ListBox1 -> Items -> Count; i++)
                        {
                            AnsiString List_text = ListBox1 -> Items -> Strings[i];

                            int j = List_text.Pos ('[');                         // ������� ������ �� ������ ��� ���� ������

                            List_text =
                                List_text.SubString (
                                    1,
                                    j - 1
                                );

                            CellValue (
                                search_nomdela (
                                    col_ab,
                                    ListBox1 -> Items -> Strings[i],
                                    1
                                ),
                                3,
                                n_st
                            );
                            CellValue (
                                List_text,
                                2,
                                n_st++
                            );


                            DM -> QResult_Exam -> Insert ();                    // ��������� � EXAMEN ������� [N_AB,N_PR]

                            DM -> QResult_ExamNOMER_AB -> Value =
                                StrToInt (
                                    search_nomdela (
                                        col_ab,
                                        ListBox1 -> Items -> Strings[i],
                                        2
                                    )
                                );
                            DM -> QResult_ExamN_PREDMET -> Value = n_pr;

                            DM -> QResult_Exam          -> ApplyUpdates ();
                            DM -> QResult_Exam          -> CommitUpdates ();
                        }


                        /*
                        String vid_ed2;

                        if (!DM -> QExamSpecVID_EDU -> Value)
                            vid_ed2 = "������� ����� ��������� �����������";
                        else
                            vid_ed2 = "������� ����� ��������� �����������";

                        Variant Sheet2 =
                            SelectSheet (
                                Workbook,
                                "����������"
                            );
                        CellValue (                                             // ���������
                            fac1,
                            3,
                            10
                        );
                        CellValue (                                             // ��� ��������
                            vid_ed2,
                            1,
                            4
                        );
                        CellValue (                                             // ���� ���.
                            DateEdit1 -> Text,
                            3,
                            12
                        );
                        CellValue (                                             // ������
                            "������ � " +
                                Edit1 -> Text,
                            7,
                            10
                        );
                        CellValue (
                            DM -> vozvrat_spec (
                                LookSP -> KeyValue
                            ),
                            3,
                            11
                        );
                        */

                        int stroka = 19;                                        // ������ ������ ��� ��������� �������

                        for (int i = 0;
                                 i < ListBox1 -> Items -> Count;
                                 ++i
                            )
                        {
                            AnsiString List_text =
                                ListBox1 -> Items -> Strings[i];

                            int j = List_text.Pos ('[');                         // ������� ������ �� ������ ��� ���� ������

                            List_text =
                                List_text.SubString (
                                    1,
                                    j - 1
                                );
                            CellValue (
                                List_text,
                                2,
                                stroka++
                            );
                        }


                        if (n_pr == 4)                                          // ��� ���������
                        {
                            Variant Sheet =                                     // ���� ��������� ��� ���������, �� ��� �� ��������� ���� Excel
                                NewSheet1 (
                                    Workbook
                                );
                            NameSheet1 (
                                Sheet,
                                "������ ������������ �� �������"
                            );
                            Sheet =
                                SelectSheet (
                                    Workbook,
                                    "������ ������������ �� �������"
                                );

                            Variant Cell1 =
                                SelectCell (
                                    2,
                                    1
                                );
                            Variant Cell2 =
                                SelectCell (
                                    5,
                                    1
                                );
                            CellFont (
                                "Arial",
                                14,
                                true,
                                false,
                                2,
                                Cell1
                            );
                            CellFont (
                                "Arial",
                                14,
                                true,
                                false,
                                2,
                                Cell2
                            );
                            CellValue (                                         // ������
                                "������ �  "        +
                                    Edit1 -> Text,
                                2,
                                1
                            );
                            CellValue (                                         // ������
                                "������ �  "        +
                                    Edit1 -> Text,
                                5,
                                1
                            );

                            // CellFont (
                            //     "Arial",
                            //     14,
                            //     true,
                            //     false,
                            //     2,
                            //     2
                            // );
                            // CellFont (
                            //     "Arial",
                            //     14,
                            //     true,
                            //     false,
                            //     5,
                            //     2
                            // );
                            CellValue (                                         // ����
                                " (������� ����)",
                                2,
                                2
                            );
                            CellValue (                                         // ����
                                " (����������� ����)",
                                5,
                                2
                            );

                            int
                                rus = 0,
                                bel = 0;

                            for (int i = 0;
                                     i < ListBox1 -> Items -> Count;
                                     ++i
                                )
                            {
                                AnsiString List_text =
                                    ListBox1 -> Items -> Strings[i];

                                int j = List_text.Pos ('[');                    // ������� ������ �� ������ ��� ���� ������

                                List_text =
                                    List_text.SubString (
                                        1,
                                        j - 1
                                    );
                                Variant izl =
                                    DM -> QExam ->
                                        Lookup (
                                            "NOMER_AB",
                                            StrToInt (
                                                search_nomdela (
                                                    col_ab,
                                                    ListBox1 -> Items -> Strings[i],
                                                    2
                                                )
                                            ),
                                            "RUS_BEL"
                                        );
                                if (izl == 1)                                   // �����������
                                {
                                    CellValue (
                                        bel + 1,
                                        4,
                                        bel + 4
                                    );
                                    CellValue (
                                        List_text,
                                        5,
                                        bel + 4
                                    );
                                    ++bel;
                                }
                                else                                            // �������
                                {
                                    CellValue (
                                        rus + 1,
                                        1,
                                        rus + 4
                                    );
                                    CellValue (
                                        List_text,
                                        2,
                                        rus + 4
                                    );

                                    ++rus;
                                }
                            }

                            AutoFitColumn (
                                Sheet,
                                1
                            );
                            AutoFitColumn (
                                Sheet,
                                2
                            );
                            AutoFitColumn (
                                Sheet,
                                4
                            );
                            AutoFitColumn (
                                Sheet,
                                5
                            );
                        }
                    }
                    else                                                        // ���� ��������� ��������, �� ��� �� ��������� ���� Excel
                    {
                        Variant Sheet =
                            NewSheet1 (
                                Workbook
                            );
                        NameSheet1 (
                            Sheet,
                            "������ ������������ �� �������"
                        );
                        Sheet =
                            SelectSheet (
                                Workbook,
                                "������ ������������ �� �������"
                            );
                        Variant
                            Cell1,                                          // =SelectCell (1, 2);
                            Cell2 =
                                SelectCell (
                                    2,
                                    2
                                );
                        HorizontalAlign (
                            Cell2,
                            3
                        );
                        CellFont (
                            "Arial",
                            18,
                            true,
                            false,
                            1,
                            Cell2
                        );
                        CellValue (                                             // ������
                            "������ �  "        +
                                Edit1 -> Text,
                                2,
                                2
                        );

                        int
                            rus = 0,
                            bel = 0;

                        for (int i = 0;
                                 i < ListBox1 -> Items -> Count;
                                 ++i
                            )
                        {
                            if (n_pr == 4)                                      // ���������
                            {
                                Cell1 =
                                    SelectCell (
                                        1,
                                        i + 4
                                    );
                                CellFont (
                                    "Arial",
                                    14,
                                    false,
                                    false,
                                    1,
                                    Cell1
                                );
                                Cell1 =
                                    SelectCell (
                                        2,
                                        i + 4
                                    );
                                CellFont (
                                    "Arial",
                                    14,
                                    false,
                                    false,
                                    1,
                                    Cell1
                                );
                                Cell1 =
                                    SelectCell (
                                        4,
                                        i + 4
                                    );
                                CellFont (
                                    "Arial",
                                    14,
                                    false,
                                    false,
                                    1,
                                    Cell1
                                );
                                Cell1 =
                                    SelectCell (
                                        5,
                                        i + 4
                                    );
                                CellFont (
                                    "Arial",
                                    14,
                                    false,
                                    false,
                                    1,
                                    Cell1
                                );

                                AnsiString List_text =
                                    ListBox1 -> Items -> Strings[i];

                                int j = List_text.Pos ('[');                     // ������� ������ �� ������ ��� ���� ������

                                List_text =
                                    List_text.SubString (
                                        1,
                                        j - 1
                                    );
                                Variant izl =
                                    DM -> QExam ->
                                        Lookup (
                                            "NOMER_AB",
                                            StrToInt (
                                                search_nomdela (
                                                    col_ab,
                                                    ListBox1 -> Items -> Strings[i],
                                                    2
                                                )
                                            ),
                                            "RUS_BEL"
                                        );
                                if (izl == 1)                                   // �����������
                                {
                                    CellValue (
                                        bel + 1,
                                        4,
                                        bel + 4
                                    );
                                    CellValue (
                                        List_text,
                                        5,
                                        bel + 4
                                    );

                                    ++bel;
                                }
                                else                                            // �������
                                {
                                    CellValue (
                                        rus + 1,
                                        1,
                                        rus + 4
                                    );
                                    CellValue (
                                        List_text,
                                        2,
                                        rus + 4
                                    );

                                    ++rus;
                                }
                            }
                            else
                            {
                                Cell1 =
                                    SelectCell (
                                        1,
                                        i + 4
                                    );
                                CellFont (
                                    "Arial",
                                    14,
                                    false,
                                    false,
                                    1,
                                    Cell1
                                );
                                CellValue (
                                    AnsiString (i + 1),
                                    1,
                                    i + 4
                                );
                                Cell1 =
                                    SelectCell (
                                        2,
                                        i + 4
                                    );
                                CellFont (
                                    "Arial",
                                    14,
                                    false,
                                    false,
                                    1,
                                    Cell1
                                );

                                AnsiString List_text =
                                    ListBox1 -> Items -> Strings[i];

                                int j = List_text.Pos ('[');                    // ������� ������ �� ������ ��� ���� ������

                                List_text =
                                    List_text.SubString (
                                        1,
                                        j - 1
                                    );

                                CellValue (
                                    List_text,
                                    2,
                                    i + 4
                                );
                            }


                            DM -> QResult_Exam -> Insert ();                    // ��������� � EXAMEN ������� [N_AB,N_PR]

                            DM -> QResult_ExamNOMER_AB -> Value =
                                StrToInt (
                                    search_nomdela (
                                        col_ab,
                                        ListBox1 -> Items -> Strings[i],
                                        2
                                    )
                                );
                            DM -> QResult_ExamN_PREDMET -> Value = n_pr;

                            DM -> QResult_Exam -> ApplyUpdates ();
                            DM -> QResult_Exam -> CommitUpdates ();
                        }

                        AutoFitColumn (
                            Sheet,
                            1
                        );
                        AutoFitColumn (
                            Sheet,
                            2
                        );
                    }


                    AnsiString n_file =                                         // �������
                            DocumentName::SUMMARY_LIST::ENTRANCE_EXAMS  +
                        " "                                             +
                            Edit1             -> Text                   +
                        ", �� "                                         +
                            DBLookupComboBox1 -> Text                   +
                        ", �� "                                         +
                            DateToStr (
                                DateTimePicker1 -> Date
                            )                                           +
                        ".xls";

                    Variant WorkSaveAs =
                        SaveBookAs (
                            Workbook,
                            PathTo::OUTPUT_DOCUMENTS_SLASH +
                            n_file
                        );
                    OVisible (ExcelApp);
                    ExcelApp.Clear ();

                    Edit1Change (ExamenForm);

                    if (mas_v)
                    {
                        for (int i = 0;
                                 i < 3;
                                 ++i
                            )
                            if (mas_fio_nomdela)
                                delete [] mas_fio_nomdela[i];

                        mas_v = 0;
                    }
                }
                else
                    ShowMessage (
                        "����������� "                                  +
                            sss                                         +
                        "��� ���� �������� � ��������� �� ����� "       \
                        "��������. �������� ������ ������������ "       \
                        "�� �������!"
                    );
            }
            else
                ShowMessage (
                    "��� ��������� ����� ������ �������� �� ��������, " \
                    "� ��� ��������� ��������� ������� ������ ��������!"
                );
        }
        else
            ShowMessage (
                "������� ��� ������!"
            );
    }
    else
        ShowMessage (
            "�������� ������������ � ������ �� �������"
        );

    ExcelApp.Clear ();
    // delete[] mas_fio_nomdela;
}
void __fastcall TExamenForm::DateTimePicker1Change (TObject * Sender)
{
    DateTimePicker1 -> Time = StrToTime ("00:00");
}
void __fastcall TExamenForm::Edit1Change (TObject * Sender)
{
    Button2      -> Visible = false;

    ExamenForm -> Height = 152;

    SG1          -> Visible = false;
    SpeedButton1 -> Visible = false;
    SpeedButton2 -> Visible = false;
    SpeedButton3 -> Visible = false;
    SpeedButton4 -> Visible = false;
    SpeedButton5 -> Visible = false;
    Panel2       -> Visible = false;
    ListBox1     -> Visible = false;
}
void __fastcall TExamenForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    // DM -> TPredmet -> Filtered = false;

    if (mas_v)
    {
        for (int i = 0;
                 i < 3;
                 ++i
            )
            if (mas_fio_nomdela)
                delete [] mas_fio_nomdela[i];

        if (mas_fio_nomdela)
            delete [] mas_fio_nomdela;

        mas_v = 0;
    }

    // Quit_ex (ExcelApp);

    this -> Close ();
}
void __fastcall TExamenForm::FormCreate (TObject * Sender)
{
    SG1 -> Font -> Style =
        TFontStyles () << fsBold;

    SG1 -> Cells[0][0] = "���";
    SG1 -> Cells[1][0] = "�������";
    SG1 -> Cells[2][0] = "������ �� ���.";

    // DM -> TPredmet -> Filtered = true;
}
AnsiString TExamenForm::search_nomdela (
        int        col_ab,
        AnsiString fam,
        int        ind
    )
{
    AnsiString nomdel;

    for (int i = 0;
             i < col_ab;
             ++i
        )
    {
        if (mas_fio_nomdela[0][i] == fam)
            if (ind == 1)
                nomdel = mas_fio_nomdela[1][i];                                 // �����. ����� ����
            else if (ind == 2)
                nomdel = mas_fio_nomdela[2][i];                                 // �����. ����� ����.
    }

    return
        nomdel;
}
void __fastcall TExamenForm::SG1DblClick (TObject * Sender)
{
    ListBox1 -> Items ->
        Add (
            SG1 -> Cells[0][SG1 -> Row]
        );
}
void __fastcall TExamenForm::SpeedButton2Click (TObject * Sender)
{
    for (int i = 1;
             i < SG1 -> RowCount;
             ++i
        )
        ListBox1 -> Items ->
            Add (
                SG1 -> Cells[0][i]
            );
}
void __fastcall TExamenForm::SpeedButton3Click (TObject * Sender)
{
    ListBox1 -> Items ->
        Delete (
            ListBox1 -> ItemIndex
        );
}
void __fastcall TExamenForm::SpeedButton4Click (TObject * Sender)
{
    ListBox1 -> Clear ();
}


















/*
#define NEW_EXAMEN_UNIT

#ifndef NEW_EXAMEN_UNIT
AnsiString *
    mas_fio_nomdela[3];

AnsiString
    vid_ed;                                                                     // ���������� ��� ��������� � ��������� ���� ��������

int
    col_ab,
    mas_v   = 0;                                                                // ������� ������ � ������� 0 - ���, 1 - ����

Variant
    ExcelApp;


__fastcall TExamenForm::TExamenForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TExamenForm::Button1Click (TObject * Sender)                    // TODO: refactoring
{
    String
        new_num_dela;

    AnsiString text_test_rus = "���� ���.";
    AnsiString text_test_bel = "���� ���.";
    AnsiString text_test_biol = "���� ����.";
    AnsiString text_test_matem = "���� �����.";
    AnsiString text_test_geogr = "���� �����.";
    AnsiString text_soch_rus = "���. ���.";
    AnsiString text_soch_bel = "���. ���.";
	AnsiString text_spec = "���������.";

	if (Edit1->Text != "") {
		SG1->Visible = true;
		SpeedButton1->Visible = true;
		SpeedButton2->Visible = true;
		SpeedButton3->Visible = true;
		SpeedButton4->Visible = true;
		SpeedButton5->Visible = true;
		Panel2->Visible = true;
		ListBox1->Visible = true;

		for (int i = 1; i < SG1->RowCount; i++) // ������� StringGrid
			for (int j = 0; j < 3; j++) {
				SG1->Cells[j][i] = "";
			}
		ListBox1->Clear();

		try {
			Variant ca = DM->QGroup_Count->Lookup("NOM_GROUP", Edit1->Text,
				"COUNT");
			if (!ca.IsNull())
				col_ab = ca.AsType(varInteger);
			else {
				ShowMessage("��� ������������ � ���� ������!");
				Edit1Change(this);
				return;
			}

			// col_ab=int(DM->QGroup_Count->Lookup("NOM_GROUP",Edit1->Text,"COUNT"));
			// if (!col_ab)
			// {
			// ShowMessage("����������� ������ ����� ������!");
			// return;
			// }
		}
		catch (...) {
			ShowMessage("����������� ������ ����� ������!");
			Edit1Change(this);
			return;
		}

		if (mas_v) {
			for (int i = 0; i < 3; i++)
				delete[]mas_fio_nomdela[i];
			// delete[] mas_fio_nomdela;

			mas_v = 0;
		}

		for (int i = 0; i < 3; i++) {
			mas_fio_nomdela[i] = new AnsiString[col_ab];
		}
		mas_v = 1;

		SG1->RowCount = col_ab + 1;

		DM->QExam->Close();
		DM->QExam->ParamByName("N_GR")->AsString = Edit1->Text;
		DM->QExam->ParamByName("N_FAC")->Value = nom_fac;
		DM->QExam->Open();
		if (!DM->QExamVID_EDU->Value)
			vid_ed = "������� ����� ��������� �����������";
		else
			vid_ed = "������� ����� ��������� �����������";
		AnsiString str = "";
		AnsiString fam;
		AnsiString bal;
		int n_abit;
        for (int i =  1;
                 i <= col_ab;
                 ++i)
        {
            new_num_dela =
                DM -> NumDelaString (
                    DM -> QExamVID_EDU  -> Value,
                    DM -> QExamTERM_EDU -> Value,
                    DM -> QExamPRICE    -> Value,
                    DM -> QExamNOM_DELA -> Value
                );
            n_abit = DM -> QExamNOMER_AB -> Value;
            fam    = DM -> QExamFAM -> Value;
            str    =
                    fam                     +
                " "                         +
                    DM -> QExamNAME ->
                        Value.SubString (
                            1,
                            1
                        )                   +
                ".";

            if (    DM -> QExamOTCH -> Value != ""
                 || DM -> QExamOTCH -> Value != "-"
               )
                str +=
                    " "                         +
                        DM -> QExamOTCH ->
                            Value.SubString (
                                1,
                                1
                            )                   +
                    ". ["                       +
                        new_num_dela            +
                    "]";

            mas_fio_nomdela[0][i - 1] = str;
            mas_fio_nomdela[1][i - 1] = "'" + new_num_dela;
            mas_fio_nomdela[2][i - 1] = DM -> QExamNOMER_AB -> Value;

            SG1 -> Cells[0][i] = str;                                           // StringGrid 1-�� �������

            switch (DM -> QExamTERM_EDU -> Value)                               // StringGrid 2-�� �������
            {
                case 1:
                        SG1 -> Cells[1][i] = "��� 2�.";
                    break;
                case 2:
                        SG1 -> Cells[1][i] = "��� 3�.";
                    break;
                case 3:
                        SG1 -> Cells[1][i] = "�� 1�.";
                    break;
                case 4:
                        SG1 -> Cells[1][i] = "�� 2�.";
                    break;
                case 5:
                        SG1 -> Cells[1][i] = "�� 3�.";
                    break;

                default:
                        SG1 -> Cells[1][i] = "";
            }

			switch (DM->QExamKONKURS->Value) {
			case 1:
				if (SG1->Cells[1][i] == "")
					SG1->Cells[1][i] = "���";
				else
					SG1->Cells[1][i] = SG1->Cells[1][i] + ", ���";
				break;
			case 2:
				if (SG1->Cells[1][i] == "")
					SG1->Cells[1][i] = "��";
				else
					SG1->Cells[1][i] = SG1->Cells[1][i] + ", ��";
				break;
			case 3:
				if (SG1->Cells[1][i] == "")
					SG1->Cells[1][i] = "��";
				else
					SG1->Cells[1][i] = SG1->Cells[1][i] + ", ��";
				break;
			}

			switch (DM->QExamN_SPORT_CATEGORY->Value) {
			case 5:
				if (SG1->Cells[1][i] == "")
					SG1->Cells[1][i] = "��";
				else
					SG1->Cells[1][i] = SG1->Cells[1][i] + ", ��";
				break;
			case 6:
				if (SG1->Cells[1][i] == "")
					SG1->Cells[1][i] = "����";
				else
					SG1->Cells[1][i] = SG1->Cells[1][i] + ", ����";
				break;
			case 7:
				if (SG1->Cells[1][i] == "")
					SG1->Cells[1][i] = "���";
				else
					SG1->Cells[1][i] = SG1->Cells[1][i] + ", ���";
				break;
			}

			if (DM->QExamCATEGORY_IF->Value) {
				if (SG1->Cells[1][i] == "")
					SG1->Cells[1][i] = "����������";
				else
					SG1->Cells[1][i] = SG1->Cells[1][i] + ", ����������";
			}

			if (DM->QExamN_PREDMET->Value) {
				AnsiString text_pr = DM->QExamPREDM->Value;
				// if (text_pr=="����������� ���� (������� ����) ���������")
				if (text_pr == "����������� (�������) ����" ||
					text_pr == "��������" || text_pr == "����������" ||
					text_pr == "���������")
				{ // RUS_BEL = 0 - ������� ����, 1- ����������� ����
					switch (DM->QExamSTATUS_BALL->Value)
						// 0 - �������, 1 - ������������, 2 - ���������
					{ // switch
					case 0: // �������
						if (DM->QExamN_PREDMET->Value == 4) // �����
						{ // if �����
							if (DM->QExamRUS_BEL->Value)
								bal = text_soch_bel + " - " +
									AnsiString(DM->QExamBALL1->Value);
							else
								bal = text_soch_rus + " - " +
									AnsiString(DM->QExamBALL1->Value);
						} // end  if �����
						if (DM->QExamN_PREDMET->Value == 1 ||
							DM->QExamN_PREDMET->Value == 9 ||
							DM->QExamN_PREDMET->Value == 10)
							// ��������, ����������, ���������
								bal = DM->QExamPREDM->Value + " - " +
								AnsiString(DM->QExamBALL1->Value);
						break;
					case 2: // ���������
						bal = DM->QExamPREDM->Value + " (�����.) - " +
							AnsiString(DM->QExamBALL1->Value);
						break;
					case 1: // ������������

						DM->QSertificat->Close();
						DM->QSertificat->ParamByName("NOMER")->AsInteger =
							DM->QExamNOMER_AB->Value;
						DM->QSertificat->Open();

						int st_test =
							DM->QSertificat->Lookup("NOMER_AB;N_PREDMET",
							VarArrayOf(OPENARRAY(Variant,
							(DM->QExamNOMER_AB->Value,
							DM->QExamN_PREDMET->Value))), "RUS_BEL");
						switch (st_test) { // switch
						case 0: // �������
							bal = text_test_rus + " - " +
								AnsiString(DM->QExamBALL1->Value);
							break;
						case 1: // �����������
							bal = text_test_bel + " - " +
								AnsiString(DM->QExamBALL1->Value);
							break;
						case 2: // ��������
							bal = text_test_biol + " - " +
								AnsiString(DM->QExamBALL1->Value);
							break;
						case 3: // ����������
							bal = text_test_matem + " - " +
								AnsiString(DM->QExamBALL1->Value);
							break;
						case 4: // ���������
							bal = text_test_geogr + " - " +
								AnsiString(DM->QExamBALL1->Value);
							break;
						} // end switch
						break;

					} // end switch

					// bal=text_soch+" - "+AnsiString(DM->QExamBALL1->Value);
				}
				else {
					// if (text_pr=="���������� �������� (���������� �������������)") bal=text_spec+" - "+AnsiString(DM->QExamBALL1->Value);
					// else
					bal = DM->QExamPREDM->Value + " - " +
						AnsiString(DM->QExamBALL1->Value);

				}
				DM->QExam->Next();
				while (n_abit == DM->QExamNOMER_AB->Value && !DM->QExam->Eof) {
					text_pr = DM->QExamPREDM->Value;
					// if (text_pr=="����������� ���� (������� ����) ���������")
					if (text_pr == "����������� (�������) ����" ||
						text_pr == "��������" || text_pr == "����������" ||
						text_pr == "���������")
					{ // RUS_BEL = 0 - ������� ����, 1- ����������� ����

						switch (DM->QExamSTATUS_BALL->Value)
							// 0 - ���������, 1 - ������������, 2 - ��������� ���
						{ // switch
						case 0: // �������
							if (DM->QExamN_PREDMET->Value == 4) // �����
							{ // if �����
								if (DM->QExamRUS_BEL->Value)
									bal += "; " + text_soch_bel + " - " +
										AnsiString(DM->QExamBALL1->Value);
								else
									bal += "; " + text_soch_rus + " - " +
										AnsiString(DM->QExamBALL1->Value);
							} // end  if �����
							if (DM->QExamN_PREDMET->Value == 1 ||
								DM->QExamN_PREDMET->Value == 9 ||
								DM->QExamN_PREDMET->Value == 10)
								// �������� , ���������� , ���������
									bal += "; " + DM->QExamPREDM->Value +
									" - " + AnsiString(DM->QExamBALL1->Value);
							break;
						case 2:
							bal += "; " + DM->QExamPREDM->Value +
								" (�����.) - " +
								AnsiString(DM->QExamBALL1->Value);
							break;
						case 1: // ������������
							DM->QSertificat->Close();
							DM->QSertificat->ParamByName("NOMER")->AsInteger =
								DM->QExamNOMER_AB->Value;
							DM->QSertificat->Open();

							int st_test =
								DM->QSertificat->Lookup("NOMER_AB;N_PREDMET",
								VarArrayOf(OPENARRAY(Variant,
								(DM->QExamNOMER_AB->Value,
								DM->QExamN_PREDMET->Value))), "RUS_BEL");
							switch (st_test) { // switch
							case 0: // �������
								bal += "; " + text_test_rus + " - " +
									AnsiString(DM->QExamBALL1->Value);
								break;
							case 1: // �����������
								bal += "; " + text_test_bel + " - " +
									AnsiString(DM->QExamBALL1->Value);
								break;
							case 2: // ��������
								bal += "; " + text_test_biol + " - " +
									AnsiString(DM->QExamBALL1->Value);
								break;
							case 3: // ����������
								bal += "; " + text_test_matem + " - " +
									AnsiString(DM->QExamBALL1->Value);
								break;
							case 4: // ���������
								bal += "; " + text_test_geogr + " - " +
									AnsiString(DM->QExamBALL1->Value);
								break;
							} // end switch
							break;

						} // end switch

						// bal+=", "+text_soch+" - "+AnsiString(DM->QExamBALL1->Value);
					}
					else {
						// if (text_pr=="���������� �������� (���������� �������������)") bal+=", "+text_spec+" - "+AnsiString(DM->QExamBALL1->Value);
						// else

						bal += "; " + DM->QExamPREDM->Value + " - " +
							AnsiString(DM->QExamBALL1->Value);

					}

					DM->QExam->Next();
				} // while
				SG1->Cells[2][i] = bal;
			} // if
			else
				DM->QExam->Next();
		} // end for

		ExamenForm->Height = 585;
		// Button2->Visible=true;
	} // if !" " Edit1
	else {
		ShowMessage("������� ����� ������");
		Edit1->SetFocus();
	}

}
void __fastcall TExamenForm::FormCreate (TObject * Sender)
{
    SG1 -> Font -> Style =
        TFontStyles () << fsBold;

    SG1 -> Cells[0][0] = "���";
    SG1 -> Cells[1][0] = "�������";
    SG1 -> Cells[2][0] = "������ �� ���.";

    // DM -> TPredmet -> Filtered = true;
}
AnsiString TExamenForm::search_nomdela (
        int        col_ab,
        AnsiString fam,
        int        ind
    )
{
    AnsiString nomdel;

    for (int i = 0;
             i < col_ab;
             ++i
        )
    {
        if (mas_fio_nomdela[0][i] == fam)
            if (ind == 1)
                nomdel = mas_fio_nomdela[1][i];                                 // �����. ����� ����
            else if (ind == 2)
                nomdel = mas_fio_nomdela[2][i];                                 // �����. ����� ����.
    }

    return
        nomdel;
}
void __fastcall TExamenForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    // DM->TPredmet->Filtered=false;
    if (mas_v)
    {
        for (int i = 0;
                 i < 3;
                 ++i
            )
            if (mas_fio_nomdela)
                delete [] mas_fio_nomdela [i];

        // delete [] mas_fio_nomdela;

        mas_v = 0;
    }

    // Quit_ex(ExcelApp);

    this -> Close ();
}
void __fastcall TExamenForm::SG1DblClick (TObject * Sender)
{
    ListBox1 -> Items ->
        Add (
            SG1 -> Cells[0][SG1 -> Row]
        );
}
void __fastcall TExamenForm::Button2Click (TObject * Sender)
{
    if (ListBox1 -> Items -> Count)
    {
        int list_count =
            ListBox1 -> Items -> Count;

        AnsiString list_fio = "";

        for (int i = 0;
                 i < list_count - 1;
                 ++i
            )
        {
            if (    ListBox1 -> Items -> Strings[i]
                 == ListBox1 -> Items -> Strings[i + 1]
               )
            {
                list_fio =
                    "����������\n"                      +
                        ListBox1 -> Items -> Strings[i] +
                    "\n��� ������ � ������";
                AnsiString ansi_string1 =
                    "������� �� ������ ������ �����?";

                wchar_t * UnicodeString1 =
                    new wchar_t[ansi_string1.WideCharBufSize ()];

                ansi_string1.WideChar (
                    UnicodeString1,
                    ansi_string1.WideCharBufSize ()
                );
                ansi_string1 =
                    list_fio.c_str ();

                wchar_t * UnicodeString2 =
                    new wchar_t[ansi_string1.WideCharBufSize ()];

                ansi_string1.WideChar (
                    UnicodeString2,
                    ansi_string1.WideCharBufSize ()
                );

                if (    Application -> MessageBox (                             // ������� �� ������ ������ �����
                            UnicodeString1,
                            UnicodeString2,
                            MB_YESNO
                        ) == IDYES
                   )
                {
                    ListBox1 -> ItemIndex = i;
                    ListBox1 -> Items ->
                        Delete (
                            ListBox1 -> ItemIndex
                        );

                    --list_count;
                    --i;
                }
                if (UnicodeString1)
                    delete [] UnicodeString1;
                if (UnicodeString2)
                    delete [] UnicodeString2;
            }
        }

        if (    DBLookupComboBox1 -> Text != ""
            // && DateEdit1 -> Text != "  .  .    "
           )
        {
            int n_pr = DBLookupComboBox1 -> KeyValue;                           // ���������� ��� ��������� � EXAMEN ������ ��������

            if ( MaskEdit1->EditText != "  .  ")                                // if ���� ��������� �� ��������� - �� ���� ������� ���� ������ ��������
            {
                if (!DM -> QResult_Exam -> Active)
                    DM -> QResult_Exam -> Open ();

                TLocateOptions
                    flag;

                AnsiString
                    sss = "";                                                   // --- �������� ������������ �� ������� � ������� ����������� ���������

                for (int i = 0;
                         i < ListBox1 -> Items -> Count;
                         ++i
                    )
                {
                    if (    DM -> QResult_Exam ->
                                Locate (
                                    "NOMER_AB;N_PREDMET",
                                    VarArrayOf (
                                        OPENARRAY (
                                            Variant,
                                            (
                                                StrToInt (
                                                    search_nomdela (
                                                        col_ab,
                                                        ListBox1 -> Items ->
                                                            Strings[i],
                                                        2
                                                    )
                                                ),
                                                n_pr
                                            )
                                        )
                                    ),
                                    flag
                                )
                       )
                        sss += ListBox1 -> Items -> Strings[i] + ". ";
                }

                if (sss == "")                                                  // if  �������� �� ������� � ������� ����������� ���������
                {
                    ExcelApp =
                        Variant::CreateObject (
                            "Excel.Application"
                        );
                    Variant Workbook =
                        OpenBook (
                            ExcelApp,
                            cur_dir                         +
                            DocumentFile::PROTOCOL::exam
                        );

                    Variant Sheet =
                        SelectSheet (
                            Workbook,
                            "��������������� ���������"
                        );

                    CellValue (                                                 // ���������
                        fac1,
                        3,
                        10
                    );

                    if (nom_fac == 4)                                           // ��� ��������� �������
                        CellValue (
                            " ���������� ��������, �������� ����",
                            1,
                            2
                        );
                    CellValue (                                                 // ��� ��������
                        vid_ed,
                        1,
                        4
                    );
                    CellValue (                                                 // ���� ���.
                        DateTimePicker1 -> Date,
                        3,
                        12
                    );
                    CellValue (                                                 // ������
                        "������ � "     +
                            Edit1 -> Text,
                            7,
                            10
                    );
                    CellValue (                                                 // �������
                        DBLookupComboBox1 -> Text,
                        4,
                        8
                    );

                    if (n_pr != 4)
                        CellValue (
                            MaskEdit1 -> EditText,                              // ������ ���.
                            3,
                            13
                        );

                    if (!RG1->ItemIndex)                                        // if ���� ������ ���������, �� ������� ��� � ���������
                    {
                        int n_st = 19;                                          // ������ ������ ��� ��������� �������

                        for (int i = 0; i < ListBox1->Items->Count; i++)
                        {
                            AnsiString List_text = ListBox1->Items->Strings[i];

                            int j = List_text.Pos('[');                         // ������� ������ �� ������ ��� ���� ������

                            List_text =
                                List_text.SubString (
                                    1,
                                    j - 1
                                );

                            CellValue (
                                search_nomdela (
                                    col_ab,
                                    ListBox1 -> Items -> Strings[i],
                                    1
                                ),
                                3,
                                n_st
                            );
                            CellValue (
                                List_text,
                                2,
                                n_st++
                            );


                            DM -> QResult_Exam -> Insert ();                    // ��������� � EXAMEN ������� [N_AB,N_PR]

                            DM -> QResult_ExamNOMER_AB -> Value =
                                StrToInt (
                                    search_nomdela (
                                        col_ab,
                                        ListBox1 -> Items -> Strings[i],
                                        2
                                    )
                                );
                            DM -> QResult_ExamN_PREDMET -> Value = n_pr;

                            DM -> QResult_Exam          -> ApplyUpdates ();
                            DM -> QResult_Exam          -> CommitUpdates ();
                        }



                        //String vid_ed2;

                        //if (!DM->QExamSpecVID_EDU->Value)
                        //    vid_ed2 = "������� ����� ��������� �����������";
                        //else
                        //    vid_ed2 = "������� ����� ��������� �����������";

                        //Variant Sheet2 =
                        //    SelectSheet (
                        //        Workbook,
                        //        "����������"
                        //    );
                        //CellValue (                                             // ���������
                        //    fac1,
                        //    3,
                        //    10
                        //);
                        //CellValue (                                             // ��� ��������
                        //    vid_ed2,
                        //    1,
                        //    4
                        //);
                        //CellValue (                                             // ���� ���.
                        //    DateEdit1 -> Text,
                        //    3,
                        //    12
                        //);
                        //CellValue (                                             // ������
                        //    "������ � " +
                        //        Edit1 -> Text,
                        //    7,
                        //    10
                        //);
                        //CellValue (
                        //    DM -> vozvrat_spec (
                        //        LookSP -> KeyValue
                        //    ),
                        //    3,
                        //    11
                        //);


                        int stroka = 19;                                        // ������ ������ ��� ��������� �������

                        for (int i = 0;
                                 i < ListBox1 -> Items -> Count;
                                 ++i
                            )
                        {
                            AnsiString List_text =
                                ListBox1 -> Items -> Strings[i];

                            int j = List_text.Pos ('[');                         // ������� ������ �� ������ ��� ���� ������

                            List_text =
                                List_text.SubString (
                                    1,
                                    j - 1
                                );
                            CellValue (
                                List_text,
                                2,
                                stroka++
                            );
                        }


                        if (n_pr == 4)                                          // ��� ���������
                        {
                            Variant Sheet =                                     // ���� ��������� ��� ���������, �� ��� �� ��������� ���� Excel
                                NewSheet1 (
                                    Workbook
                                );
                            NameSheet1 (
                                Sheet,
                                "������ ������������ �� �������"
                            );
                            Sheet =
                                SelectSheet (
                                    Workbook,
                                    "������ ������������ �� �������"
                                );

                            Variant Cell1 =
                                SelectCell (
                                    2,
                                    1
                                );
                            Variant Cell2 =
                                SelectCell (
                                    5,
                                    1
                                );
                            CellFont (
                                "Arial",
                                14,
                                true,
                                false,
                                2,
                                Cell1
                            );
                            CellFont (
                                "Arial",
                                14,
                                true,
                                false,
                                2,
                                Cell2
                            );
                            CellValue (                                         // ������
                                "������ �  "        +
                                    Edit1 -> Text,
                                2,
                                1
                            );
                            CellValue (                                         // ������
                                "������ �  "        +
                                    Edit1 -> Text,
                                5,
                                1
                            );

                            // CellFont (
                            //     "Arial",
                            //     14,
                            //     true,
                            //     false,
                            //     2,
                            //     2
                            // );
                            // CellFont (
                            //     "Arial",
                            //     14,
                            //     true,
                            //     false,
                            //     5,
                            //     2
                            // );
                            CellValue (                                         // ����
                                "(������� ����)",
                                2,
                                2
                            );
                            CellValue (                                         // ����
                                "(����������� ����)",
                                5,
                                2
                            );

                            int
                                rus = 0,
                                bel = 0;

                            for (int i = 0;
                                     i < ListBox1 -> Items -> Count;
                                     ++i
                                )
                            {
                                AnsiString List_text =
                                    ListBox1 -> Items -> Strings[i];

                                int j = List_text.Pos ('[');                    // ������� ������ �� ������ ��� ���� ������

                                List_text =
                                    List_text.SubString (
                                        1,
                                        j - 1
                                    );
                                Variant izl =
                                    DM -> QExam ->
                                        Lookup (
                                            "NOMER_AB",
                                            StrToInt (
                                                search_nomdela (
                                                    col_ab,
                                                    ListBox1 -> Items -> Strings[i],
                                                    2
                                                )
                                            ),
                                            "RUS_BEL"
                                        );
                                if (izl == 1)                                   // �����������
                                {
                                    CellValue (
                                        bel + 1,
                                        4,
                                        bel + 4
                                    );
                                    CellValue (
                                        List_text,
                                        5,
                                        bel + 4
                                    );
                                    ++bel;
                                }
                                else                                            // �������
                                {
                                    CellValue (
                                        rus + 1,
                                        1,
                                        rus + 4
                                    );
                                    CellValue (
                                        List_text,
                                        2,
                                        rus + 4
                                    );

                                    ++rus;
                                }
                            }

                            AutoFitColumn (
                                Sheet,
                                1
                            );
                            AutoFitColumn (
                                Sheet,
                                2
                            );
                            AutoFitColumn (
                                Sheet,
                                4
                            );
                            AutoFitColumn (
                                Sheet,
                                5
                            );
                        }
                    }
                    else                                                        // ���� ��������� ��������, �� ��� �� ��������� ���� Excel
                    {
                        Variant Sheet =
                            NewSheet1 (
                                Workbook
                            );
                        NameSheet1 (
                            Sheet,
                            "������ ������������ �� �������"
                        );
                        Sheet =
                            SelectSheet (
                                Workbook,
                                "������ ������������ �� �������"
                            );
                        Variant
                            Cell1,                                          // =SelectCell(1, 2);
                            Cell2 =
                                SelectCell (
                                    2,
                                    2
                                );
                        HorizontalAlign (
                            Cell2,
                            3
                        );
                        CellFont (
                            "Arial",
                            18,
                            true,
                            false,
                            1,
                            Cell2
                        );
                        CellValue (                                             // ������
                            "������ �  "        +
                                Edit1 -> Text,
                                2,
                                2
                        );

                        int
                            rus = 0,
                            bel = 0;

                        for (int i = 0;
                                 i < ListBox1 -> Items -> Count;
                                 ++i
                            )
                        {
                            if (n_pr == 4)                                      // ���������
                            {
                                Cell1 =
                                    SelectCell (
                                        1,
                                        i + 4
                                    );
                                CellFont (
                                    "Arial",
                                    14,
                                    false,
                                    false,
                                    1,
                                    Cell1
                                );
                                Cell1 =
                                    SelectCell (
                                        2,
                                        i + 4
                                    );
                                CellFont (
                                    "Arial",
                                    14,
                                    false,
                                    false,
                                    1,
                                    Cell1
                                );
                                Cell1 =
                                    SelectCell (
                                        4,
                                        i + 4
                                    );
                                CellFont (
                                    "Arial",
                                    14,
                                    false,
                                    false,
                                    1,
                                    Cell1
                                );
                                Cell1 =
                                    SelectCell (
                                        5,
                                        i + 4
                                    );
                                CellFont (
                                    "Arial",
                                    14,
                                    false,
                                    false,
                                    1,
                                    Cell1
                                );

                                AnsiString List_text =
                                    ListBox1 -> Items -> Strings[i];

                                int j = List_text.Pos ('[');                     // ������� ������ �� ������ ��� ���� ������

                                List_text =
                                    List_text.SubString (
                                        1,
                                        j - 1
                                    );
                                Variant izl =
                                    DM -> QExam ->
                                        Lookup (
                                            "NOMER_AB",
                                            StrToInt (
                                                search_nomdela (
                                                    col_ab,
                                                    ListBox1 -> Items -> Strings[i],
                                                    2
                                                )
                                            ),
                                            "RUS_BEL"
                                        );
                                if (izl == 1)                                   // �����������
                                {
                                    CellValue (
                                        bel + 1,
                                        4,
                                        bel + 4
                                    );
                                    CellValue (
                                        List_text,
                                        5,
                                        bel + 4
                                    );

                                    ++bel;
                                }
                                else                                            // �������
                                {
                                    CellValue (
                                        rus + 1,
                                        1,
                                        rus + 4
                                    );
                                    CellValue (
                                        List_text,
                                        2,
                                        rus + 4
                                    );

                                    ++rus;
                                }
                            }
                            else
                            {
                                Cell1 =
                                    SelectCell (
                                        1,
                                        i + 4
                                    );
                                CellFont (
                                    "Arial",
                                    14,
                                    false,
                                    false,
                                    1,
                                    Cell1
                                );
                                CellValue (
                                    AnsiString (i + 1),
                                    1,
                                    i + 4
                                );
                                Cell1 =
                                    SelectCell (
                                        2,
                                        i + 4
                                    );
                                CellFont (
                                    "Arial",
                                    14,
                                    false,
                                    false,
                                    1,
                                    Cell1
                                );

                                AnsiString List_text =
                                    ListBox1 -> Items -> Strings[i];

                                int j = List_text.Pos ('[');                    // ������� ������ �� ������ ��� ���� ������

                                List_text =
                                    List_text.SubString (
                                        1,
                                        j - 1
                                    );

                                CellValue (
                                    List_text,
                                    2,
                                    i + 4
                                );
                            }


                            DM -> QResult_Exam -> Insert ();                    // ��������� � EXAMEN ������� [N_AB,N_PR]

                            DM -> QResult_ExamNOMER_AB -> Value =
                                StrToInt (
                                    search_nomdela (
                                        col_ab,
                                        ListBox1 -> Items -> Strings[i],
                                        2
                                    )
                                );
                            DM -> QResult_ExamN_PREDMET -> Value = n_pr;

                            DM -> QResult_Exam -> ApplyUpdates ();
                            DM -> QResult_Exam -> CommitUpdates ();
                        }

                        AutoFitColumn (
                            Sheet,
                            1
                        );
                        AutoFitColumn (
                            Sheet,
                            2
                        );
                    }


                    AnsiString n_file =                                         // �������
                            DocumentName::SUMMARY_LIST::ENTRANCE_EXAMS  +
                        " "                                             +
                            Edit1             -> Text                   +
                        ", �� "                                         +
                            DBLookupComboBox1 -> Text                   +
                        ", �� "                                         +
                            DateToStr (
                                DateTimePicker1 -> Date
                            )                                           +
                        ".xls";

                    Variant WorkSaveAs =
                        SaveBookAs (
                            Workbook,
                            PathTo::OUTPUT_DOCUMENTS_SLASH +
                            n_file
                        );
                    OVisible (ExcelApp);
                    ExcelApp.Clear ();

                    Edit1Change (ExamenForm);

                    if (mas_v)
                    {
                        for (int i = 0;
                                 i < 3;
                                 ++i
                            )
                            if (mas_fio_nomdela)
                                delete [] mas_fio_nomdela[i];

                        mas_v = 0;
                    }
                }
                else
                    ShowMessage (
                        "����������� "                                  +
                            sss                                         +
                        "��� ���� �������� � ��������� �� ����� "       \
                        "��������. �������� ������ ������������ "       \
                        "�� �������!"
                    );
            }
            else
                ShowMessage(
                    "��� ��������� ����� ������ �������� �� ��������, " \
                    "� ��� ��������� ��������� ������� ������ ��������!"
                );
        }
        else
            ShowMessage (
                "������� ��� ������!"
            );
    }
    else
        ShowMessage (
            "�������� ������������ � ������ �� �������"
        );

    ExcelApp.Clear ();
    // delete[] mas_fio_nomdela;
}
void __fastcall TExamenForm::SpeedButton2Click (TObject * Sender)
{
    for (int i = 1;
             i < SG1 -> RowCount;
             ++i
        )
        ListBox1 -> Items ->
            Add (
                SG1 -> Cells[0][i]
            );
}
void __fastcall TExamenForm::SpeedButton3Click (TObject * Sender)
{
    ListBox1 -> Items ->
        Delete (
            ListBox1 -> ItemIndex
        );
}
void __fastcall TExamenForm::SpeedButton4Click (TObject * Sender)
{
    ListBox1 -> Clear ();
}
void __fastcall TExamenForm::Edit1Change (TObject * Sender)
{
    Button2      -> Visible = false;

    ExamenForm -> Height = 152;

    SG1          -> Visible = false;
    SpeedButton1 -> Visible = false;
    SpeedButton2 -> Visible = false;
    SpeedButton3 -> Visible = false;
    SpeedButton4 -> Visible = false;
    SpeedButton5 -> Visible = false;
    Panel2       -> Visible = false;
    ListBox1     -> Visible = false;
}
void __fastcall TExamenForm::DateTimePicker1Change (TObject * Sender)
{
    DateTimePicker1 -> Time = StrToTime ("00:00");
}

#endif  // ! NEW_EXAMEN_UNIT
*/
