#include <vcl.h>
#pragma hdrstop


#include "AbiturUnit.h"
#include "DMUnit.h"
#include "SertificatUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TSertificatForm * SertificatForm;


bool state_sertificat = false;                                                  // ���� ����������� ��� �� ����, �� false
int  nom;                                                                       // ����� �����������



__fastcall TSertificatForm::TSertificatForm (TComponent * Owner)
    : TForm (Owner)
{ }


void __fastcall TSertificatForm::BitBtn1Click (TObject * Sender)                // ������ ���������
{
    int n_specializ =
        DM -> QSpecializPlan_PriemN_SPECIALIZ -> Value;

    if (    Edit1 -> Text == ""                                                 // �����
         || Edit2 -> Text == ""                                                 // �����
         || Edit3 -> Text == ""                                                 // ��������
       )
        return
            ShowMessage (
                "���������, ������������ ��������� ������!\n"       \
                "\t1. C���� �����������,\n"                         \
                "\t2. ����� �����������,\n"                         \
                "\t3. ������ ��������� ��������������� ��������"
            );

    if (DBLookupComboBox1 -> Text == "")
        return
            ShowMessage (
                "�� ������ ������� ����������������� ������������!"
            );

    if (    DBLookupComboBox1 -> KeyValue != 1
         && DBLookupComboBox1 -> KeyValue != 4
         && DBLookupComboBox1 -> KeyValue != 2
         && n_specializ                   != 61
       )
        return
            ShowMessage (
                "������� ����������������� ������������ ������ "            \
                "����:\n\t1. ��������\n\t2. ����������� (�������) ����!"
            );

    if (    DBLookupComboBox1 -> KeyValue != 9
         && DBLookupComboBox1 -> KeyValue != 10
         && DBLookupComboBox1 -> KeyValue != 4
         && nom_fac                       == 4
         && n_specializ                   != 48
         && n_specializ                   != 51
         && n_specializ                   != 50
       )
        return
            ShowMessage (
                "������� ����������������� ������������ ������ ���� "       \
                "����������, ��������� ��� ����������� (�������) ����!"
            );

    if (    DBLookupComboBox1 -> KeyValue  == 4
         && ComboBox1         -> ItemIndex == -1                                // ������ ������� �� ������
       )
        return
            ShowMessage (
                "��� ������������ �� ��������: ����������� (�������) "      \
                "����, ���� ����������� ������� ����!"
            );

    if (MaskEdit1 -> Text ==  "   ")                                            // ����������� ��������� ����� �� ������������
        return
            ShowMessage (
                "������� ��������� �� ������������ �����!"
            );

    double ozenka = StrToFloat (Label14 -> Caption);

    if (    ozenka  <  2.1                                                      // ����������� ��������� ����� �� ������������
         && nom_fac != 4
       )
        return
            ShowMessage (
                "�����, ���������� �� ������������ �� �������� "            \
                "������������� �������!!"
            );

    int b_t = StrToInt (MaskEdit1 -> Text.Trim ());


    //if (    b_t < 10                                                            // � 2014 ���� 10 - ����������� ���� ��� ����������� � ��� �� �����
    //     && DBLookupComboBox1 -> KeyValue == 4
    //   )
    //    return
    //        ShowMessage (
    //            "�����, ���������� �� ������������, �� ������ ���� "        \
    //            "������ 10!"
    //        );

    //if (    b_t < 15                                                            // � 2014 ���� 15 - ���������� � ��������
    //     && (   DBLookupComboBox1 -> KeyValue == 9
    //         || DBLookupComboBox1 -> KeyValue == 1
    //        )
    //   )
    //    return
    //        ShowMessage (
    //            "�����, ���������� �� ������������, �� ������ ���� "        \
    //            "������ 15!"
    //        );

    //if (    b_t < 20                                                            // � 2014 ���� 20 - ���������
    //     && DBLookupComboBox1 -> KeyValue == 10
    //   )
    //    return
    //        ShowMessage (
    //            "�����, ���������� �� ������������, �� ������ ���� "        \
    //            "������ 20!"
    //        );


    if (b_t > 100)                                                              // �������� �� ���� ������ �� ����� 100
        return
            ShowMessage (
                "�����, ���������� �� ������������, �� ������ ���� "    \
                "������ 100!"
            );

    // if (DM -> QSertificat -> State == dsInactive)
    //    DM -> QSertificat -> Open ();

    TLocateOptions sss;

    if (    DM -> QSertificat -> Locate (                                       // if ����� ���������� �� ������� ��������
                "NOMER_AB;N_PREDMET",
                VarArrayOf (
                    OPENARRAY (
                        Variant,
                        (
                            nom,
                            DBLookupComboBox1 -> KeyValue
                        )
                    )
                ),
                sss
            )
       )
        ShowMessage (
            "� ����������� ��� ���� ���������� �� ����� ��������, " \
            "��������� ����������!"
        );


    try
    {
        if (! state_sertificat)                                                 // false - ��� �����������, true - ����
        {
            DM -> QSertificat -> Insert ();                                     // ���������
            DM -> QSertificatNOMER_AB  -> Value = nom;                          // ����� �����������
            DM -> QSertificatN_PREDMET -> Value =                               // �������
                DBLookupComboBox1 -> KeyValue;
        }
        else
            DM -> QSertificat -> Edit ();

        DM -> QSertificatSERIA_S -> Value = Edit1 -> Text;                      // ����� �����������
        DM -> QSertificatNOMER_S -> Value = Edit2 -> Text;                      // ����� �����������
        DM -> QSertificatBALLS   -> Value = b_t;                                // ����� �� ������������
        DM -> QSertificatYEAR_S  -> Value = StrToInt (Edit4 -> Text);
        DM -> QSertificatPRICE   -> Value = 0;                                  // 0-������������, 1-������� ������������

        int c = DBLookupComboBox1 -> KeyValue,
            r;                                                                  // ��� ���������� �������

        switch (c)
        {
            case 1:  r = 2;                      break;                         // ��������
            case 2:  r = 5;                      break;                         // ���������
            case 4:  r = ComboBox1 -> ItemIndex; break;                         // ����
            case 9:  r = 3;                      break;                         // ����������
            case 10: r = 4;                      break;                         // ���������
        }

        DM -> QSertificatRUS_BEL  -> Value = r;
        DM -> QSertificatDESCRIBE -> Value = Edit3 -> Text;                     // �������� �������������� ��������

        DM -> QSertificat -> ApplyUpdates ();
        DM -> QSertificat -> CommitUpdates ();

        state_sertificat = true;


        TLocateOptions flag;                                                    // ����� ������ � ���������� ����������� �� ���������� ������������

        if (! DM -> QResult_Exam -> Active)
            DM -> QResult_Exam -> Open ();

        if (    DM -> QResult_Exam ->
                    Locate (
                        "NOMER_AB;N_PREDMET",
                        VarArrayOf (
                            OPENARRAY (
                                Variant,
                                (
                                    nom,
                                    DBLookupComboBox1 -> KeyValue
                                )
                            )
                        ),
                        flag
                    )
           )
        {
            if (DM -> QResult_ExamNOM_BALL -> Value !=  0)                      // if ����� ������ �� ������� ��������, �������� �� 0
            {
                if (DM -> QResult_ExamBALL -> Value != ozenka)                  // if �������� ����� � ����������� � ���� �������� ������ �� ��������
                {
                    // if (    Application -> MessageBox (
                    //             "� ����� ����������� ��� ���� ������ �� "   \
                    //             "������� ��������! �������� ��!",
                    //             "",
                    //             MB_YESNO
                    //         ) == mrYes
                    //    )

                    AnsiString ansi_string1 =
                        "� ����� ����������� ��� ���� ������ �� ������� "   \
                        "��������!\n������� ����������?";

                    wchar_t * UnicodeString1 =
                        new wchar_t[ansi_string1.WideCharBufSize ()];

                    ansi_string1.WideChar (
                        UnicodeString1,
                        ansi_string1.WideCharBufSize ()
                    );


                    ansi_string1 = "";

                    wchar_t * UnicodeString2 =
                        new wchar_t[ansi_string1.WideCharBufSize ()];

                    ansi_string1.WideChar (
                        UnicodeString2,
                        ansi_string1.WideCharBufSize ()
                    );

                    if (    Application -> MessageBox (                         // ������ ������ �� �����������
                                UnicodeString1,
                                UnicodeString2,
                                MB_YESNO
                            ) ==  mrYes
                       )
                    {
                        DM -> QResult_Exam -> Edit ();

                        if (    nom_fac                                 == 4
                             && AbiturForm -> TermEduCmbBx -> ItemIndex != 1
                             && AbiturForm -> TermEduCmbBx -> ItemIndex != 2
                           )
                            DM -> QResult_ExamNOM_BALL -> Value = 13;           // ��������
                        else
                        {
                            AnsiString z =
                                FloatToStrF (
                                    ozenka,
                                    ffFixed,
                                    5,
                                    0
                                );

                            DM -> QResult_ExamNOM_BALL -> Value =
                                z.ToInt () + 1;
                        }

                        DM -> QResult_ExamBALL        -> Value = ozenka;
                        DM -> QResult_ExamSTATUS_BALL -> Value = 1;

                        try
                        {
                            DM -> QResult_Exam -> ApplyUpdates ();
                            DM -> QResult_Exam -> CommitUpdates ();

                            ShowMessage (
                                "���������� ����������� ������ �������!"
                            );

                            DM -> QResult_Exam -> Close ();
                        }
                        catch (...)
                        {
                            DM -> QResult_Exam -> CancelUpdates ();

                            ShowMessage (
                                "��������� ���� ��� ����������, "       \
                                "���������� ��� ���!"
                            );
                        }
                    }
                    else
                        ShowMessage (
                            "�������� ����� � �����������, ��� �� "     \
                            "������������� ������ �� ��������!"
                        );

                    if (UnicodeString1)
                        delete [] UnicodeString1;

                    if (UnicodeString2)
                        delete [] UnicodeString2;
                }
            }
            else
                ShowMessage (
                    "���� ���������� ��� ��� ������� � ��������� �� "   \
                    "������� �� ������� ��������"
                );
        }
        else
        {
            DM -> QResult_Exam -> Insert ();

            DM -> QResult_ExamNOMER_AB  -> Value = nom;
            DM -> QResult_ExamN_PREDMET -> Value =
                DBLookupComboBox1 -> KeyValue;

            if (    nom_fac                                 == 4
                 && AbiturForm -> TermEduCmbBx -> ItemIndex != 1
                 && AbiturForm -> TermEduCmbBx -> ItemIndex != 2
               )
                DM -> QResult_ExamNOM_BALL -> Value = 13;                       // ��������
            else
            {
                AnsiString z =
                    FloatToStrF (
                        ozenka,
                        ffFixed,
                        5,
                        0
                    );

                DM -> QResult_ExamNOM_BALL -> Value =
                    z.ToInt () + 1;
            }

            DM -> QResult_ExamBALL -> Value = ozenka;


            DM -> QResult_ExamSTATUS_BALL -> Value = 1;                         // ������ ���������� ������ (0 - ������ ��������, 1 - ������ �� ��)

            try
            {
                DM -> QResult_Exam -> ApplyUpdates ();
                DM -> QResult_Exam -> CommitUpdates ();

                ShowMessage (
                    "���������� ����������� ������ �������!"
                );

                DM -> QResult_Exam -> Close ();
            }
            catch (...)
            {
                DM -> QResult_Exam -> CancelUpdates ();

                ShowMessage (
                    "��������� ���� ��� ����������, ���������� ��� ���!"
                );
            }
            DM -> QResult_Exam -> Close ();
        }

        if (DM -> QAbitura -> State != dsInsert)
            if (!summa_b (nom))
                ShowMessage (
                    "�� ������� �������������� ������"
                );

        // TLocateOptions Op;

        // DM -> QSertificat ->
        //     Locate (
        //         "NOMER_AB",
        //         nom,
        //         Op
        //     );

        // TLocateOptions Flags;

        // DM -> QAbitura ->
        //     Locate (
        //         "NOMER_AB",
        //         nom,
        //         Flags
        //     );

        // this -> Close ();
    }
    catch (...)
    {
        DM -> QSertificat -> CancelUpdates ();

        ShowMessage (
            "��������� ���� ��� ����������, ���������� ��� ���!"
        );
    }

    DBLookupComboBox1 -> Enabled = false;                                       // ������ ����������� ��������� ��������
}
void __fastcall TSertificatForm::BitBtn2Click (TObject * Sender)
{
    if (DM -> QSertificat -> State == dsInsert)
        DM -> QSertificat -> CancelUpdates ();

    this -> Close ();
}
void __fastcall TSertificatForm::BitBtn3Click (TObject * Sender)                // ������ ������� ����������
{
    TLocateOptions Opts;

    Opts.Clear ();

    Variant locvalues[3];

    locvalues[0] = Variant (nom);                                               // ����� �����������
    locvalues[1] = Variant (DBLookupComboBox1 -> KeyValue);                     // �������
    locvalues[2] = Variant (1);                                                 // ������ (1 - ������ �� ��)


    AnsiString ansi_string1 =                                                   // ������� ������
        "\t�� ������������� ������ ������� ���� ����������?";

    wchar_t * UnicodeString1 = new wchar_t[ansi_string1.WideCharBufSize ()];    // ������-����������

    ansi_string1.WideChar (                                                     // ��������
        UnicodeString1,
        ansi_string1.WideCharBufSize ()
    );

    ansi_string1 = "";                                                          // ������� ������� ������

    wchar_t * UnicodeString2 = new wchar_t[ansi_string1.WideCharBufSize ()];    // ������-����������

    ansi_string1.WideChar (
        UnicodeString2,
        ansi_string1.WideCharBufSize ()
    );


    if (    Application -> MessageBox (                                         // MessageBox == Yes
                UnicodeString1,
                UnicodeString2,
                MB_YESNO
            ) == mrYes
       )
    {

        if (DM -> QResult_Exam -> State == dsInactive)
            DM -> QResult_Exam -> Open ();


        if (    DM -> QResult_Exam -> Locate (                                  // ����� � ����������� ��������� ������ �� �����������
                    "NOMER_AB;N_PREDMET;STATUS_BALL",
                    VarArrayOf (
                        locvalues,
                        2
                    ),
                    Opts
                )
           )
        {
            DM -> QResult_Exam -> Delete ();                                    // ����� QResult_Exam ������ - �������
            DM -> QResult_Exam -> ApplyUpdates ();
            DM -> QResult_Exam -> CommitUpdates ();
        }


        if (    DM -> QSertificat -> Locate (                                   // �������� ������� � �����������
                    "NOMER_AB;N_PREDMET",
                    VarArrayOf (
                        locvalues,
                        1
                    ),
                    Opts
                )
           )
        {
            DM -> QSertificat -> Delete ();                                     // ����� QSertificat ������ - �������
            DM -> QSertificat -> ApplyUpdates ();
            DM -> QSertificat -> CommitUpdates ();
        }
    }

    if (UnicodeString1)
        delete [] UnicodeString1;

    if (UnicodeString2)
        delete [] UnicodeString2;
}
void __fastcall TSertificatForm::DBLookupComboBox1CloseUp (TObject * Sender)
{
    if (DBLookupComboBox1 -> KeyValue == 4)                                     // ����������� (������� ����)
    {
        Label5    -> Visible = true;
        ComboBox1 -> Visible = true;

        ComboBox1 -> SetFocus ();
    }
    else                                                                        // ��������, ����������, ���������
    {
        Label5    -> Visible = false;
        ComboBox1 -> Visible = false;

        MaskEdit1 -> SetFocus ();
    }
}
void __fastcall TSertificatForm::DBNavigator1Click (
        TObject      * Sender,
        TNavigateBtn   Button
    )
{
    switch (Button)
    {
        case nbFirst:   refrech_sertificat (); break;
        case nbPrior:   refrech_sertificat (); break;
        case nbNext:    refrech_sertificat (); break;
        case nbLast:    refrech_sertificat (); break;
        case nbInsert:
                Edit1             -> Text      = "";                            // ����� �����������
                Edit2             -> Text      = "";                            // ����� �����������
                // Edit3             -> Text      = "";                            // �������� �������������� ��������
                MaskEdit1         -> Text      = "";                            // ����� �� ������������
                DBLookupComboBox1 -> KeyValue  = -1;                            // �������
                DBLookupComboBox1 -> Enabled   = true;                          // ������ ��������� ��������� ��������
                Label14           -> Caption   = "";                            // �������� ������
                Label5            -> Visible   = false;                         // �������� ����� �����
                ComboBox1         -> Visible   = false;
                ComboBox1         -> Text      = "";
                ComboBox1         -> ItemIndex = -1;

                state_sertificat = false;                                       // ����� ���� ����� ��� �����������

                Edit1 -> SetFocus ();
            break;
        case nbDelete:                         break;
        case nbEdit:                           break;
        case nbCancel:  refrech_sertificat (); break;
        case nbRefresh:                        break;
    }
}
void __fastcall TSertificatForm::Edit1Exit (TObject * Sender)
{
    // if (DM -> QSertificat -> State == dsInsert)
    if (! state_sertificat)
        seria_sertificat (
            Edit1 -> Text
        );
}
void __fastcall TSertificatForm::FormActivate (TObject * Sender)
{
    if (DM -> QSertificat -> State == dsInactive)                               // ��������� �����������
    {
        DM -> QSertificat ->
            ParamByName ("NOMER") -> AsInteger =
                    DM -> QAbituraNOMER_AB -> Value;

        DM -> QSertificat -> Open ();
    }

    refrech_sertificat ();

    Label9  -> Caption = DM -> QAbituraFAM  -> Value;                           // �������
    Label10 -> Caption = DM -> QAbituraNAME -> Value;                           // ���
    Label11 -> Caption = DM -> QAbituraOTCH -> Value;                           // ��������

    Label14 -> Caption = MaskEdit1 -> Text;

    UpDown1 -> Max = StrToInt (Admissions::TIME::YEAR);
    UpDown1 -> Min = StrToInt (Admissions::TIME::YEAR) - 1;
}
void __fastcall TSertificatForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}
void __fastcall TSertificatForm::MaskEdit1Exit (TObject * Sender)               // ���� � ���� � ������� �� ������������
{
    if (MaskEdit1 -> Text != "   ")
    {
        int bal_t = 0;

        try                                                                     // �������� ������������ ����� ������
        {
            bal_t =
                StrToInt (
                    MaskEdit1 -> Text.Trim ()
                );
        }
        catch (...)
        {
            ShowMessage (
                "���������, ������������ ��������� ������ " \
                "�� ������������!"
            );
            bal_t =
                StrToInt (
                    MaskEdit1 -> Text.Trim ()
                );
        }


        // DM -> QShkala -> Close ();                                              // �������� �� ����� �� ���������� ����
        // DM -> QShkala ->
        //     ParamByName ("N_PR")    -> AsSmallInt =
        //             DBLookupComboBox1 -> KeyValue;
        // DM -> QShkala ->
        //     ParamByName ("N_BALL")  -> AsSmallInt =
        //             bal_t;
        // DM -> QShkala ->
        //     ParamByName ("N_BALLS") -> AsSmallInt =
        //             bal_t;
        // DM -> QShkala -> Open ();

        // if (DBLookupComboBox1 -> KeyValue == 4)                                 // ��������� ����� ��� ������������ � �������� TLocateOptions fl1;
        //     DM -> QShkala ->
        //         Locate (
        //             "RUS_BEL",
        //             ComboBox1 -> ItemIndex,
        //             fl1
        //         );

        // if (nom_fac == 4)
        //     Label14 -> Caption =
        //         IntToStr (
        //             bal_t
        //         );
        // else
        //     Label14 -> Caption =
        //         IntToStr (
        //             DM -> QShkalaBALL -> Value
        //         );

        // Label14 -> Caption =
        //     DM -> ball_result (                                                 // ������� ���������� ��������� �����������
        //         bal_t,
        //         nom_fac
        //     );
        // if (nom_fac != 4)
        //     Label14 -> Caption =
        //         FloatToStrF (
        //             DM -> ball_result_float (
        //                 bal_t,
        //                 nom_fac
        //             ),
        //             ffFixed,
        //             4,
        //             1
        //         );
        // else
        //     Label14 -> Caption =
        //         FloatToStrF (
        //             DM -> ball_result_float (
        //                 bal_t,
        //                 nom_fac
        //             ),
        //             ffFixed,
        //             3,
        //             0
        //         );

        int rus_b;

        if (DBLookupComboBox1 -> KeyValue == 4)                                 // ������� ������� ��� ����������� ����
            rus_b = ComboBox1 -> ItemIndex;
        else
            rus_b = 2;

        if (nom_fac != 4)
            Label14 -> Caption =
                FloatToStrF (
                    bal_t,
                    ffFixed,
                    4,
                    1
                );
        else
            if (    AbiturForm -> TermEduCmbBx -> ItemIndex == 1
                 || AbiturForm -> TermEduCmbBx -> ItemIndex == 2
               )
                Label14 -> Caption =
                    FloatToStrF (
                        bal_t,
                        ffFixed,
                        4,
                        1
                    );
        else
            Label14 -> Caption =
                FloatToStrF (
                    bal_t,
                    ffFixed,
                    3,
                    0
                );

        if (    DBLookupComboBox1 -> KeyValue == 2
             && bal_t                         <  101
           )
            Label14 -> Caption =
                FloatToStrF (
                    bal_t,
                    ffFixed,
                    3,
                    0
                );
    }
    else
    {
        Label14 -> Caption = "";
        // MaskEdit1 -> SetFocus ();
    }
}
void __fastcall TSertificatForm::refrech_sertificat ()                          // �������� ������� �����������
{
    nom = DM -> QAbituraNOMER_AB -> Value;

    if (DM -> QSertificat -> RecordCount)                                       // ���������� ������ ����������� ����������� � Gride
    {

        Edit1             -> Text     = DM -> QSertificatSERIA_S   -> Value;    // ����� �����������
        Edit2             -> Text     = DM -> QSertificatNOMER_S   -> Value;    // ����� �����������
        Edit3             -> Text     = DM -> QSertificatDESCRIBE  -> Value;    // �������� �������������� ��������
        Edit4             -> Text     = DM -> QSertificatYEAR_S    -> Value;    // ��� ������
        DBLookupComboBox1 -> KeyValue = DM -> QSertificatN_PREDMET -> Value;    // �������

        if (DM -> QSertificatN_PREDMET -> Value == 4)                           // ������� ������� ��� �����������
        {
            Label5    -> Visible = true;
            ComboBox1 -> Visible = true;

            Variant v =
                DM -> QSertificatRUS_BEL -> AsVariant;

            if (! v.IsNull ())
                ComboBox1 -> ItemIndex =
                    DM -> QSertificatRUS_BEL -> Value;
            else
                ComboBox1 -> ItemIndex = -1;
        }
        else
        {
            Label5    -> Visible = false;
            ComboBox1 -> Visible = false;

            ComboBox1 -> Text = "";
        }

        MaskEdit1 -> Text =                                                     // ����� �� ������������
            DM -> QSertificatBALLS -> Value;
        /*
         if (nom_fac!= 4)
         {
         //�������� �� ����� �� ���������� ����
         DM -> QShkala -> Close ();
         DM -> QShkala -> ParamByName ("N_PR") -> AsSmallInt = DBLookupComboBox1 -> KeyValue;
         DM -> QShkala -> ParamByName ("N_BALL") -> AsSmallInt = DM -> QSertificatBALLS -> Value;
         DM -> QShkala -> ParamByName ("N_BALLS") -> AsSmallInt = DM -> QSertificatBALLS -> Value;
         DM -> QShkala -> Open ();

         Label14 -> Caption = IntToStr (DM -> QShkalaBALL -> Value);
         }
         else Label14 -> Caption = DM -> QSertificatBALLS -> Value;

         //�������, ������� ���������� ��������� �����������
         //Label14 -> Caption = DM -> ball_result (DM -> QSertificatBALLS -> Value,
         nom_fac);
         */

        int rus_b;

        if (DM -> QSertificatN_PREDMET -> Value == 4)                           // ����������� ��� �������
            rus_b = DM -> QSertificatRUS_BEL -> Value;
        else
            rus_b = 2;


        // DM -> ball_result_float (                                               // �������, ������� ���������� ��������� �����������
        //     int b,                                                              // ���������� ������
        //     int predmet,                                                        // �������
        //     int rus_bel                                                         // ���� (0 - ���, 1- ���, 2 - ���������)
        // )


        if (nom_fac != 4)
            Label14 -> Caption =
                FloatToStrF (
                    DM -> ball_result_float (
                        DM -> QSertificatBALLS     -> Value,
                        DM -> QSertificatN_PREDMET -> Value,
                        rus_b,
                        AbiturForm -> KonkursCmbBx -> ItemIndex
                    ),
                    ffFixed,
                    4,
                    1
                );
        else
            if (    AbiturForm -> TermEduCmbBx -> ItemIndex == 1
                 || AbiturForm -> TermEduCmbBx -> ItemIndex == 2
               )
                Label14 -> Caption =
                    FloatToStrF (
                        DM -> ball_result_float (
                            DM -> QSertificatBALLS     -> Value,
                            DM -> QSertificatN_PREDMET -> Value,
                            rus_b,
                            AbiturForm -> KonkursCmbBx -> ItemIndex
                        ),
                        ffFixed,
                        4,
                        1
                    );
        else
            Label14 -> Caption =
                FloatToStrF (
                    DM -> ball_result_float (
                        DM -> QSertificatBALLS     -> Value,
                        DM -> QSertificatN_PREDMET -> Value,
                        rus_b,
                        AbiturForm -> KonkursCmbBx -> ItemIndex
                    ),
                    ffFixed,
                    3,
                    0
                );

        DBLookupComboBox1 -> Enabled = false;                                   // ������ ����������� ��������� ��������
        state_sertificat             = true;                                    // ����� ���������� ����� ���� ��� ����������
    }
    else
    {
        Edit1 -> Text = "";                                                     // ����� �����������
        Edit2 -> Text = "";                                                     // ����� �����������

        if (AbiturForm -> PasportDBEdt -> Text != "")                          // �������� �������������� ��������
            Edit3 -> Text =
                "������� "                              +
                    AbiturForm -> PasportDBEdt -> Text;
        else
            Edit3 -> Text = "";

        DBLookupComboBox1 -> KeyValue = -1;                                     // �������
        DBLookupComboBox1 -> Enabled  = true;                                   // ������ ��������� ��������� ��������
        Label5            -> Visible  = false;                                  // ����
        ComboBox1         -> Visible  = false;
        MaskEdit1         -> Text     = "";                                     // ����� �� ������������
        ComboBox1         -> Text     = "";

        state_sertificat = false;                                               // ����� ���������� ����� ��� �����������
    }
}
void __fastcall TSertificatForm::seria_sertificat (AnsiString seria)            // ������� ���������� �� ����� ����������� �������
{
    seria =
        seria.SubString (
            1,
            2
        );

    DBLookupComboBox1 -> KeyValue = -1;

    if (    seria == "01"                                                       // "01" - �������
         || seria == "02"                                                       // "02" - �����������
       )
    {
        DBLookupComboBox1 -> KeyValue = 4;

        Label5    -> Visible = true;
        ComboBox1 -> Visible = true;

        if (seria == "01")
            ComboBox1 -> ItemIndex = 0;
        else
            ComboBox1 -> ItemIndex = 1;
    }
    else
    {
        Label5    -> Visible = false;
        ComboBox1 -> Visible = false;

        ComboBox1 -> Text = "";

        if (seria == "04")                                                      // "04" - ����������
            DBLookupComboBox1 -> KeyValue = 9;
        if (seria == "06")                                                      // "06" - ��������
            DBLookupComboBox1 -> KeyValue = 1;
        if (seria == "13")                                                      // "13" - ���������
            DBLookupComboBox1 -> KeyValue = 10;
    }
}
void __fastcall TSertificatForm::SpeedButton1Click (TObject * Sender)
{
    DBNavigator1 -> BtnClick (nbInsert);
}
bool __fastcall TSertificatForm::summa_b (int n)                                // ������������ ����������� ��������� (� ������ �����������) (n - ����� �����������)
{
    try
    {
        DM -> QSum_Ball_Nomer -> Close ();
        DM -> QSum_Ball_Nomer ->
            ParamByName ("NOMER") -> AsInteger = n;
        DM -> QSum_Ball_Nomer -> Open ();

        if (!DM -> QSum_Ball_Nomer -> RecordCount)
            return
                false;

        DM -> QSum_Ball_Nomer -> Edit ();                                       // �����������

        DM -> QSum_Ball_NomerSUM_BALL -> Value =
              DM -> QSum_Ball_NomerSUM         -> Value
            + DM -> QSum_Ball_NomerMIDDLE_BALL -> Value;

        DM -> QSum_Ball_Nomer -> ApplyUpdates ();                               // ���������
        DM -> QSum_Ball_Nomer -> CommitUpdates ();

        return
            true;
    }
    catch (...)
    {
        return
            false;
    }
}

