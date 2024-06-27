#include <vcl.h>
#pragma hdrstop


#include <math.h>


#include "DMUnit.h"
#include "SredBalUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"



double Round (
        double Argument,
        int    Precision
    )
{
    #ifndef USE_OLD_IF_DOES_NOT_WORK_SRED_BAL_UNIT
    return
        floor (Argument * pow10 (Precision) + 0.5) * pow10 (-Precision);
    #else // delete OLD IMPLEMENTATION below
        double div = 1.0;

        if (Precision >= 0)
            while (Precision--)
                div *= 10.0;
        else
            while (Precision++)
                div /= 10.0;
        return
            floor (Argument * div + 0.5) / div;
    #endif // !USE_OLD_IF_DOES_NOT_WORK
}



TSredBalForm * SredBalForm;



__fastcall TSredBalForm::TSredBalForm (TComponent * Owner)
    : TForm (Owner)
{ }


void __fastcall TSredBalForm::Ball_5 (                                          // расчет среднего балла дл€ 5-бальной системы
        AnsiString p5,
        AnsiString p4,
        AnsiString p3
    )
{
    int
        count = 0,
        i     = 0,
        sum   = 0;

    double
        rez = 0;

    if (p5 != "  ")
    {
        i     =  StrToInt (p5.Trim ());
        count += i;
        sum   += i * 5;
    }

    if (p4 != "  ")
    {
        i     =  StrToInt (p4.Trim ());
        count += i;
        sum   += i * 4;
    }

    if (p3 != "  ")
    {
        i     =  StrToInt (p3.Trim ());
        count += i;
        sum   += i * 3;
    }


    if (count)
        rez = (double) sum / count;


    int n = 1;                                                                  // округление до n знаков после зап€той

    if (rez > 0)
        rez =
            Round (
                rez,
                n
            );

    rez = rez * 10;                                                             // добавил 01.07.2017 умножение на 10 или нужно 20?

    Edit2 -> Text =
        Ball_5_10 (
            rez
        );
    Edit1 -> Text =
        FloatToStrF (
            rez,
            ffFixed,
            5,
            1
        );

    Label16 -> Caption =
        " ол-во : "             +
            AnsiString (count);
}
AnsiString TSredBalForm::Ball_5_10 (double ball)                                //функци€ перевода 5-бальной системы в 10-бальную
{
    #ifndef USE_OLD_IF_DOES_NOT_WORK_SRED_BAL_UNIT
    switch (static_cast <int> (ball))
    {
        case 30: return "30";
        case 31: return "34";
        case 32: return "37";
        case 33: return "40";
        case 34: return "44";
        case 35: return "48";
        case 36: return "51";
        case 37: return "55";
        case 38: return "58";
        case 39: return "62";
        case 40: return "65";
        case 41: return "69";
        case 42: return "72";
        case 43: return "76";
        case 44: return "79";
        case 45: return "83";
        case 46: return "86";
        case 47: return "90";
        case 48: return "93";
        case 49: return "97";
        case 50: return "100";
    }
    #else   // delete OLD IMPLEMENTATION below
    AnsiString b = "";

    switch (static_cast <int> (ball))
    {
        case 30: b = "30"; break;
        case 31: b = "34"; break;
        case 32: b = "37"; break;
        case 33: b = "40"; break;
        case 34: b = "44"; break;
        case 35: b = "48"; break;
        case 36: b = "51"; break;
        case 37: b = "55"; break;
        case 38: b = "58"; break;
        case 39: b = "62"; break;
        case 40: b = "65"; break;
        case 41: b = "69"; break;
        case 42: b = "72"; break;
        case 43: b = "76"; break;
        case 44: b = "79"; break;
        case 45: b = "83"; break;
        case 46: b = "86"; break;
        case 47: b = "90"; break;
        case 48: b = "93"; break;
        case 49: b = "97"; break;
        case 50: b = "100";break;
    }

    return b;
    #endif // !USE_OLD_IF_DOES_NOT_WORK_SRED_BAL_UNIT
}
void __fastcall TSredBalForm::Ball_10 (                                         // рачтет среднего балла дл€ 10-быльной системы
        AnsiString v10,
        AnsiString v9,
        AnsiString v8,
        AnsiString v7,
        AnsiString v6,
        AnsiString v5,
        AnsiString v4,
        AnsiString v3,
        AnsiString v2,
        AnsiString v1
    )
{
    #ifdef TEST_SRED_BAL_UNIT
        ShowMessage (
            "Ball_10 reseived 10 x: "   +
                v10                     +
            "\n"                        +
            "Ball_10 reseived 9 x: "    +
                v9                      +
            "\n"                        +
            "Ball_10 reseived 8 x: "    +
                v8                      +
            "\n"                        +
            "Ball_10 reseived 7 x: "    +
                v7                      +
            "\n"                        +
            "Ball_10 reseived 6 x: "    +
                v6                      +
            "\n"                        +
            "Ball_10 reseived 5 x: "    +
                v5                      +
            "\n"                        +
            "Ball_10 reseived 4 x: "    +
                v4                      +
            "\n"                        +
            "Ball_10 reseived 3 x: "    +
                v3                      +
            "\n"                        +
            "Ball_10 reseived 2 x: "    +
                v2                      +
            "\n"                        +
            "Ball_10 reseived 1 x: "    +
                v1
        );
    #endif
    int
        count = 0,
        i     = 0,
        sum   = 0;

    double
        rez = 0;

    if (    v10 != "  "
         && !v10.IsEmpty ()
       )
    {
        #ifdef TEST_SRED_BAL_UNIT
        ShowMessage (
            "Ball_10 if (v10 != "  ") is TRUE and reseived 10 x: "  +
                v10                     +
            "\n"
        );
        #endif
        i     =  StrToInt (v10.Trim ());
        count += i;
        sum   += i * 10;
    }

    if (v9 != "  ")
    {
        #ifdef TEST_SRED_BAL_UNIT
        ShowMessage (
            "Ball_10 if (v9 != "  ") is TRUE and reseived 9 x: "    +
                v9
        );
        #endif
        i     =  StrToInt (v9.Trim ());
        count += i;
        sum   += i * 9;
    }

    if (v8 != "  ")
    {
        #ifdef TEST_SRED_BAL_UNIT
        ShowMessage (
            "Ball_10 if (v8 != "  ") is TRUE and reseived 8 x: "    +
                v8
        );
        #endif
        i     =  StrToInt (v8.Trim ());
        count += i;
        sum   += i * 8;
    }

    if (v7 != "  ")
    {
        #ifdef TEST_SRED_BAL_UNIT
        ShowMessage (
            "Ball_10 if (v7 != "  ") is TRUE and reseived 7 x: "    +
                v7
        );
        #endif
        i     =  StrToInt (v7.Trim ());
        count += i;
        sum   += i * 7;
    }

    if (v6 != "  ")
    {
        #ifdef TEST_SRED_BAL_UNIT
        ShowMessage (
            "Ball_10 if (v6 != "  ") is TRUE and reseived 6 x: "    +
                v6
        );
        #endif
        i     =  StrToInt (v6.Trim ());
        count += i;
        sum   += i * 6;
    }

    if (v5 != "  ")
    {
        #ifdef TEST_SRED_BAL_UNIT
        ShowMessage (
            "Ball_10 if (v5 != "  ") is TRUE and reseived 5 x: "    +
                v5
        );
        #endif
        i     =  StrToInt (v5.Trim ());
        count += i;
        sum   += i * 5;
    }

    if (v4 != "  ")
    {
        #ifdef TEST_SRED_BAL_UNIT
        ShowMessage (
            "Ball_10 if (v4 != "  ") is TRUE and reseived 4 x: "    +
                v4
        );
        #endif
        i     =  StrToInt (v4.Trim ());
        count += i;
        sum   += i * 4;
    }

    if (v3 != "  ")
    {
        #ifdef TEST_SRED_BAL_UNIT
        ShowMessage (
            "Ball_10 if (v3 != "  ") is TRUE and reseived 3 x: "    +
                v3
        );
        #endif
        i     =  StrToInt (v3.Trim ());
        count += i;
        sum   += i * 3;
    }

    if (v2 != "  ")
    {
        #ifdef TEST_SRED_BAL_UNIT
        ShowMessage (
            "Ball_10 if (v2 != "  ") is TRUE and reseived 2 x: "    +
                v2
        );
        #endif
        i     =  StrToInt (v2.Trim ());
        count += i;
        sum   += i * 2;
    }

    if (v1 != "  ")
    {
        #ifdef TEST_SRED_BAL_UNIT
        ShowMessage (
            "Ball_10 if (v1 != "  ") is TRUE and reseived 1 x: "    +
                v1
        );
        #endif
        i     =  StrToInt (v1.Trim ());
        count += i;
        sum   += i * 1;
    }


    if (count)
        rez = (double) sum / count;



    int n = 1;                                                                // округление до n знаков после зап€той

    if (rez > 0)
        rez =
            Round (
                rez,
                n
            );


    rez = rez * 10;

    Edit2 -> Text =
        FloatToStrF (
            rez,
            ffFixed,
            5,
            0
        );

    Label16 -> Caption =
        " ол-во : "             +
            AnsiString (count);
}
void __fastcall TSredBalForm::BitBtn1Click (TObject * Sender)
{
    this -> Close ();
}
void __fastcall TSredBalForm::BitBtn2Click (TObject * Sender)                   // —охран€ет средний балл аттестата
{
    if (Edit2 -> Text == "")                                                   // проверка выполнени€ рассчета
        return
            ShowMessage (
                "Ќе выполнен расчет среднего балла!"
            );


    if (DM -> QAbitura -> State != dsInsert)                                    // если данные редактируютс€ - перевходим в Edit
        DM -> QAbitura -> Edit ();

    DM -> QAbituraMIDDLE_BALL -> Value =                                        // сохран€ем балл в поле
        Edit2 -> Text.ToDouble ();

    if (DM -> QAbitura -> State == dsEdit)                                      // при редактировании данных - сразу сохран€ем
    {
        DM -> QAbitura -> ApplyUpdates ();
        DM -> QAbitura -> CommitUpdates ();
    }

    this -> Close ();
}
void __fastcall TSredBalForm::BitBtn3Click (TObject * Sender)
{
    #ifdef TEST_SRED_BAL_UNIT
    ShowMessage (
        AnsiString (RadioGroup1 -> ItemIndex)
    );
    #endif
    if (!RadioGroup1 -> ItemIndex)
    {
        #ifdef TEST_SRED_BAL_UNIT
        ShowMessage (
            "10 x: "                              +
                AnsiString (MaskEdit1  -> Text)   +
            "\n"                                  +
            "9 x: "                               +
                AnsiString (MaskEdit2  -> Text)   +
            "\n"                                  +
            "8 x: "                               +
                AnsiString (MaskEdit3  -> Text)   +
            "\n"                                  +
            "7 x: "                               +
                AnsiString (MaskEdit4  -> Text)   +
            "\n"                                  +
            "6 x: "                               +
                AnsiString (MaskEdit5  -> Text)   +
            "\n"                                  +
            "5 x: "                               +
                AnsiString (MaskEdit6  -> Text)   +
            "\n"                                  +
            "4 x: "                               +
                AnsiString (MaskEdit7  -> Text)   +
            "\n"                                  +
            "3 x: "                               +
                AnsiString (MaskEdit8  -> Text)   +
            "\n"                                  +
            "2 x: "                               +
                AnsiString (MaskEdit9  -> Text)   +
            "\n"                                  +
            "1 x: "                               +
                AnsiString (MaskEdit10 -> Text)   +
            "\n"
        );
        #endif
        Ball_10 (
            MaskEdit1  -> Text,                                                 // "10 x"
            MaskEdit2  -> Text,                                                 // "9 x"
            MaskEdit3  -> Text,                                                 // "8 x"
            MaskEdit4  -> Text,                                                 // "7 x"
            MaskEdit5  -> Text,                                                 // "6 x"
            MaskEdit6  -> Text,                                                 // "5 x"
            MaskEdit7  -> Text,                                                 // "4 x"
            MaskEdit8  -> Text,                                                 // "3 x"
            MaskEdit9  -> Text,                                                 // "2 x"
            MaskEdit10 -> Text                                                  // "1 x"
        );
    }
    else
        Ball_5 (
            MaskEdit1 -> Text,                                                  // "5 x"
            MaskEdit2 -> Text,                                                  // "4 x"
            MaskEdit3 -> Text                                                   // "3 x"
        );
}
void __fastcall TSredBalForm::BitBtn4Click (TObject * Sender)                   // clear all
{
    Edit1      -> Text    = "";
    Edit2      -> Text    = "";

    Label16    -> Caption = "";

    MaskEdit1  -> Text    = "";
    MaskEdit2  -> Text    = "";
    MaskEdit3  -> Text    = "";
    MaskEdit4  -> Text    = "";
    MaskEdit5  -> Text    = "";
    MaskEdit6  -> Text    = "";
    MaskEdit7  -> Text    = "";
    MaskEdit8  -> Text    = "";
    MaskEdit9  -> Text    = "";
    MaskEdit10 -> Text    = "";
}
void __fastcall TSredBalForm::FormActivate (TObject * Sender)
{
    MaskEdit1 -> SetFocus ();

    SredBalForm -> Height = 300;

    Edit1   -> Visible = false;
    Label11 -> Visible = false;
}
void __fastcall TSredBalForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}
void __fastcall TSredBalForm::RadioGroup1Click (TObject * Sender)
{
    RadioSetup (RadioGroup1 -> ItemIndex);
}
void __fastcall TSredBalForm::RadioSetup (int ind)                              // выбора системы оценок
{
    switch (ind)
    {
        case 0:                                                                 // дес€тибальна€
                SredBalForm -> Height  = 340;

                Label1      -> Left    = 15;

                Edit1       -> Visible = false;
                Label11     -> Visible = false;                                  // "—р.балл '5'" for "Edit1"

                Label4      -> Visible = true;
                Label5      -> Visible = true;
                Label6      -> Visible = true;
                Label7      -> Visible = true;
                Label8      -> Visible = true;
                Label9      -> Visible = true;
                Label10     -> Visible = true;
                MaskEdit4   -> Visible = true;
                MaskEdit5   -> Visible = true;
                MaskEdit6   -> Visible = true;
                MaskEdit7   -> Visible = true;
                MaskEdit8   -> Visible = true;
                MaskEdit9   -> Visible = true;
                MaskEdit10  -> Visible = true;

                Label1      -> Caption = "10 x";
                Label2      -> Caption = "9 x";
                Label3      -> Caption = "8 x";
                Label16     -> Caption = "";

                Edit1       -> Text    = "";                                     // Input of "—р.балл '5'"
                Edit2       -> Text    = "";
                MaskEdit1   -> Text    = "";
                MaskEdit2   -> Text    = "";
                MaskEdit3   -> Text    = "";
                MaskEdit4   -> Text    = "";
                MaskEdit5   -> Text    = "";
                MaskEdit6   -> Text    = "";
                MaskEdit7   -> Text    = "";
                MaskEdit8   -> Text    = "";
                MaskEdit9   -> Text    = "";
                MaskEdit10  -> Text    = "";

                MaskEdit1   -> SetFocus ();
            break;
        case 1:                                                                 // п€тибальна€
                SredBalForm -> Height  = 340;

                Label1      -> Left    = 22;

                Edit1       -> Visible = true;
                Label11     -> Visible = true;                                   // "—р.балл '5'"" for Input "Edit1"

                Label4      -> Visible = false;
                Label5      -> Visible = false;
                Label6      -> Visible = false;
                Label7      -> Visible = false;
                Label8      -> Visible = false;
                Label9      -> Visible = false;
                Label10     -> Visible = false;
                MaskEdit4   -> Visible = false;
                MaskEdit5   -> Visible = false;
                MaskEdit6   -> Visible = false;
                MaskEdit7   -> Visible = false;
                MaskEdit8   -> Visible = false;
                MaskEdit9   -> Visible = false;
                MaskEdit10  -> Visible = false;

                Label1      -> Caption = "5 x";
                Label2      -> Caption = "4 x";
                Label3      -> Caption = "3 x";
                Label16     -> Caption = "";

                Edit2       -> Text    = "";
                MaskEdit1   -> Text    = "";
                MaskEdit2   -> Text    = "";
                MaskEdit3   -> Text    = "";

                MaskEdit1   -> SetFocus();
            break;
    }
}
