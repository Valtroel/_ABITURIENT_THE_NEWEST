#include <vcl.h>
#pragma hdrstop


#include "Ball_Unit.h"
#include "DMUnit.h"
#include "Resuilt_ExamUnit.h"


#pragma package (smart_init)
// #pragma link     "RXCtrls"
#pragma resource "*.dfm"


TBall_Form * Ball_Form;



__fastcall TBall_Form::TBall_Form (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TBall_Form::ball_check ()                                       // установка RadioGroup 1 или 2 в нужное значение балла
{
    Variant ball_result = DM -> QShow_Result_ExamNOM_BALL -> AsVariant;         // tyt

    if (DM -> QShow_Result_ExamN_PREDMET -> Value == 2)                         // if если предмет = ФКиС
    {
        Edit1       -> Visible = true;
        CheckBox1   -> Visible = true;

        RadioGroup2 -> Visible = false;
        RadioGroup1 -> Visible = false;

        if (!ball_result.IsNull ())                                              // проверка на наличие оценки
        {
            Edit1 -> Text = DM -> QShow_Result_ExamBALL -> AsInteger;
            // RadioGroup2 -> ItemIndex = ball_result - 12;
        }
        else
        {
            Edit1 -> Text = 0;

            if (ball_result == 12)
            {
                CheckBox1 -> Checked = true;
                Edit1     -> Enabled = false;
            }
        }

        // RadioGroup2 -> ItemIndex = -1;
    }                                                                           // предмет = плавание
    else                                                                        // другой предмет
    {
        Edit1       -> Visible = false;
        CheckBox1   -> Visible = false;
        RadioGroup2 -> Visible = false;
        RadioGroup1 -> Visible = true;

        if ( ! ball_result.IsNull ())                                           // проверка на наличие оценки
        {
            if (ball_result == 12)                                              // не явился: NOM_BALL = 12 и RadioGroup1 -> ItemIndex = 0
                RadioGroup1 -> ItemIndex = 0;
            else
                RadioGroup1 -> ItemIndex = ball_result;
        }
        else
            RadioGroup1 -> ItemIndex = -1;
    }

    DBNavigator1 -> Enabled = true;

    if (DM -> QShow_Result_Exam -> State == dsEdit)
        DM -> QShow_Result_Exam -> Cancel ();
}



void __fastcall TBall_Form::BitBtn1Click (TObject * Sender)
{
    if (DM -> QShow_Result_Exam -> State != dsBrowse)
    {
        Variant stat = DM -> QShow_Result_ExamSTATUS_BALL -> AsVariant;

        // try
        // {
        //     DM -> QShow_Result_ExamBALL -> Value =
        //         DBLookupComboBox1 -> Text.ToInt ();
        // }
        // catch (EConvertError &)
        // {
        //     DM -> QShow_Result_ExamBALL -> Value = 0;
        // }

        if (DM -> QShow_Result_ExamN_PREDMET -> Value != 2)                     // выбран предмет не ФКиС
        {
            switch (RadioGroup1 -> ItemIndex)
            {
                case 0:
                        DM -> QShow_Result_ExamNOM_BALL -> Value = 12;          // не явился
                        DM -> QShow_Result_ExamBALL     -> Value = 0;           // для общей суммы 0
                    break;
                default:
                        DM -> QShow_Result_ExamNOM_BALL -> Value =
                            RadioGroup1 -> ItemIndex;                           // tyt
                        DM -> QShow_Result_ExamBALL -> Value =
                            (RadioGroup1 -> ItemIndex - 1) * 10;                // переводим в 100-бальную
                    break;
            }
        }
        else                                                                    // выбран предмет ФКиС
        {
            if (CheckBox1 -> Checked == false)                                  // получил оценку
            {
                DM -> QShow_Result_ExamNOM_BALL -> Value =                      // это не явился, зачет, незачет
                    Edit1 -> Text.ToInt () + 1;
                DM -> QShow_Result_ExamBALL     -> Value =
                    Edit1 -> Text.ToInt ();
            }
            else                                                                // не явился
            {
                DM -> QShow_Result_ExamNOM_BALL -> Value = 12;
                DM -> QShow_Result_ExamBALL     -> Value = 0;
            }
        }

        if (stat.IsNull ())                                                      // оценка получена: 0 - за экзамен 1 - по ЦТ
        {
            DM -> QShow_Result_ExamSTATUS_BALL -> Value = 0;
        }

        DM -> QShow_Result_Exam -> ApplyUpdates ();
        DM -> QShow_Result_Exam -> CommitUpdates ();

        Proverka ();

        // DM -> QShow_Result_Exam -> Next ();
        DBNavigator1 -> Enabled = true;
    }
}



void __fastcall TBall_Form::BitBtn2Click (TObject * Sender)
{
    this -> Close ();
}



void __fastcall TBall_Form::BitBtn3Click (TObject * Sender)
{
    DM -> QShow_Result_Exam -> CancelUpdates ();

    DBNavigator1 -> Enabled = true;
}



void __fastcall TBall_Form::CheckBox1Click (TObject * Sender)
{
    if (CheckBox1 -> Checked == true)
    {
        Edit1 -> Text    = 0;
        Edit1 -> Enabled = false;
    }
    else
        Edit1 -> Enabled = true;

    DM -> QShow_Result_Exam -> Edit ();

    DBNavigator1 -> Enabled = false;
}



void __fastcall TBall_Form::DBLookupComboBox1CloseUp (TObject * Sender)
{
    // DM -> QShow_Result_Exam -> Edit ();

    // DBNavigator1 -> Enabled = false;
}



void __fastcall TBall_Form::DBNavigator1Click (
        TObject      * Sender,
        TNavigateBtn   Button
    )
{
    ball_check ();                                                              // проверка уже полученной оценки
}



void __fastcall TBall_Form::Edit1Change (TObject * Sender)
{
    DM -> QShow_Result_Exam -> Edit ();

    DBNavigator1 -> Enabled = false;
}



void __fastcall TBall_Form::FormActivate (TObject * Sender)
{
    ball_check ();                                                              // проверка уже полученной оценки
}



void __fastcall TBall_Form::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    if (DM -> QShow_Result_Exam -> State != dsBrowse)
    {
        // if (    Application ->
        //             MessageBox (
        //                 "Данные не были сохранены. Сохранить?",
        //                 "",
        //                 MB_YESNO
        //             )
        //    )

        AnsiString ansi_string1 = "Данные не были сохранены. Сохранить?";

        wchar_t * UnicodeString1 = new wchar_t[ansi_string1.WideCharBufSize ()];

        ansi_string1.WideChar (
            UnicodeString1,
            ansi_string1.WideCharBufSize ()
        );

        ansi_string1 = "";

        wchar_t * UnicodeString2 = new wchar_t[ansi_string1.WideCharBufSize ()];

        ansi_string1.WideChar (
            UnicodeString2,
            ansi_string1.WideCharBufSize ()
        );

        if (    Application ->
                    MessageBox (
                        UnicodeString1,
                        UnicodeString2,
                        MB_YESNO
                    )
           )
            delete[] UnicodeString1;

        delete[] UnicodeString2;
        {
            BitBtn1Click (this);
        }
    }

    this -> Close ();
}



void __fastcall TBall_Form::Proverka ()                                          // изменение статуса абитуриента при получении отрицательной оценки
{
    DM -> QAbitura -> Close ();
    DM -> QAbitura -> SQL -> Clear ();
    DM -> QAbitura -> SQL ->
        Add ("                      \
            SELECT                  \
                address_before,     \
                address_life,       \
                address_mama,       \
                address_papa,       \
                category_ab,        \
                category_if,        \
                citizenship,        \
                d_prikaz_include,   \
                date_priem,         \
                date_r,             \
                date_v,             \
                date_vozvrat,       \
                education,          \
                fam,                \
                gragdan,            \
                konkurs,            \
                mama,               \
                middle_ball,        \
                n_centre,           \
                n_ck,               \
                n_fac,              \
                n_found,            \
                n_langvich,         \
                n_prikaz_include,   \
                n_region,           \
                n_spec,             \
                n_specializ,        \
                n_sport_category,   \
                n_vid_sport,        \
                name,               \
                name_edu_middle,    \
                name_edu_spec,      \
                nom_attest,         \
                nom_dela,           \
                nom_diplom,         \
                nom_group,          \
                nomer_ab,           \
                organ_v,            \
                otch,               \
                papa,               \
                pasport,            \
                personal_nomer,     \
                phone,              \
                place_r,            \
                pol,                \
                price,              \
                rus_bel,            \
                stag,               \
                stag_spec,          \
                status,             \
                sum_ball,           \
                term_edu,           \
                town_village,       \
                type_school,        \
                vid_edu,            \
                when_edu_middle,    \
                when_edu_spec,      \
                where_edu_middle,   \
                house,              \
                flat,               \
                postcode,           \
                address_life,       \
                where_edu_spec,     \
                work_before,        \
                work_mama,          \
                work_papa,          \
                id_type,            \
                date_ok,            \
                disabled,           \
                street,             \
                house,              \
                flat,               \
                postcode            \
            FROM                    \
                abitura             \
            WHERE                   \
                n_fac = :n_fac      \
            ORDER BY                \
                nom_dela            \
        ");
    DM -> QAbitura -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DM -> QAbitura -> Open ();

    TLocateOptions fl;

    int nom_ab = DM -> QShow_Result_ExamNOMER_AB -> Value;

    DM ->
        QAbitura ->
            Locate (
                "NOMER_AB",
                nom_ab,
                fl
            );

    if (    RadioGroup1 -> ItemIndex == 0
         || RadioGroup2 -> ItemIndex == 0
         || CheckBox1   -> Checked                                              // "Не явился"
       )
    {
        DM -> QAbitura -> Edit ();
        DM -> QAbituraSTATUS -> Value = 3;
    }
    else
        if (    RadioGroup1 -> ItemIndex == 1                                   // оценка "0"
             || RadioGroup1 -> ItemIndex == 2                                   // оценка "1"
             || RadioGroup1 -> ItemIndex == 3                                   // оценка "2"
             || RadioGroup2 -> ItemIndex == 2                                   // оценка "незачет"
             || (    Edit1 -> Text.ToInt () > 0                                 // оценка "неуд" (по 100-бальной)
                  && Edit1 -> Text.ToInt () < 30
                )
           )
    {
        DM -> QAbitura -> Edit ();

        DM -> QAbituraSTATUS -> Value = 2;
    }
    else
    {
        if (DM -> QAbituraSTATUS -> Value)
        {
            DM -> QAbitura -> Edit ();
            DM -> QAbituraSTATUS -> Value = 0;
        }
    }

    if (DM -> QAbitura -> State == dsEdit)
    {
        DM -> QAbitura -> ApplyUpdates ();
        DM -> QAbitura -> CommitUpdates ();

        DM -> QGroup_Count -> Close ();
        DM -> QGroup_Count -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
        DM -> QGroup_Count -> Open ();
    }
}



void __fastcall TBall_Form::RadioGroup1Click (TObject * Sender)
{
    DM -> QShow_Result_Exam -> Edit ();

    DBNavigator1 -> Enabled = false;
}