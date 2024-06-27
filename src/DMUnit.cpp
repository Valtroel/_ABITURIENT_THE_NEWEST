#include <vcl.h>
#pragma hdrstop


#include <math.h>


#include "AbiturUnit.h"
#include "DMUnit.h"
#include "SplashUnit.h"


// #pragma link "RxLogin"
#pragma resource "*.dfm"


TDM * DM;


AnsiString
    cur_dir,                                                                    // ������� ����������
    dateOkonch,                                                                 // ���� ��������� ��������� ����������� ��� ����������
    DateServer,                                                                 // ���� � �������
    fac1,                                                                       // �������� ���������� (�����������)
    out_dir,                                                                    // ���������� ��� ���������� �������� ������
    TextTest       = "",                                                        // ������� � ��������� ���� � ������ � ������� �����
    Us_Name,
    Us_Pas;


bool
    st_asu,                                                                     // ���������� ������� asu
    st_developer;                                                               // ���������� ������� ������������


int
    ID_from_QUEUE,                                                              // ID � �������
    IdEdu,
    n_menu         = 0,
    n_specializ,
    nom_fac,                                                                    // ����� ����������
    oplata_konkurs = 0,                                                         // (0 - ����� ������� ��� ���������; 1 - ���������� ������� (�����/����) ��� ���������)
    perepodacha,                                                                // ���������� �� ����������
    pole_block     = 0,                                                         // ����������� ���� ������� ������������� (0 - ������ ������; 1 - ������������)
    pr_KategIf,                                                                 // ��������� �����������: 0 - ��, 1 - ��, 2 - ���
    press;                                                                      // ��� ����������� ����� ������ ������


TDateTime
    cur_d;



void __fastcall VidKonkurs (                                                    // ��������� ��������� �������� �����������
        TComboBox * KonkursCmbBx,
        TComboBox * PriceCmbBx,
        TComboBox * ComboBox1
    )
{
    /***************************************************************
    * @brief ��������� ��������� �������� �����������               *
    *                                                               *
    * @details ������� ���������� ���� � ��������� ����� �������    *
    * (�.�. oplata_konkurs == 0)                                    *
    *****************************************************************/

    // KonkursCmbBx -> Enabled = true;

    // AnsiString vid_edu = "";
    // int        price   = -1;

    // price   = PriceCmbBx -> ItemIndex;                                          // ������ / �� ������
    // vid_edu = ComboBox1  -> Text;                                               // ������� / �������

    // switch (price)
    // {
    //     case 0:                                                                 // ������
    //             RadioGroup2 ->
    //                 Items ->
    //                     Strings[0] = "�����";

    //             RadioGroup2 ->                                                  // ����� ���� (�� � ����)
    //                 Controls[0] ->
    //                     Enabled    = true;


    //             if (vid_edu == "�������")
    //                 RadioGroup2 ->                                              // �� �� ����
    //                     Controls[1] ->
    //                         Enabled = true;
    //             else
    //                 RadioGroup2 ->                                              // �� ���� ���
    //                     Controls[1] ->
    //                         Enabled = false;

    //             RadioGroup2 ->                                                  // ���������� ���
    //                 Controls[5] ->
    //                     Enabled    = false;

    //         break;
    //     case 1:                                                                 // �� ������
    //             RadioGroup2 ->
    //                 Items ->
    //                     Strings[0] = "�����";

    //             RadioGroup2 ->                                                  // �� ���
    //                 Controls[1] ->
    //                     Enabled    = false;

    //             RadioGroup2 ->                                                  // ���������� ����
    //                 Controls[5] ->
    //                     Enabled    = true;
    //         break;
    // }
}



__fastcall TDM::TDM (TComponent * AOwner)
    : TDataModule (AOwner)
{ }



void __fastcall TDM::AbiturLogInsStrdPrcCalcFields (TDataSet * DataSet)
{
    int vid_ed = DM -> QSpisoc_Group_PolVID_EDU -> Value;

    switch (vid_ed)
    {
        case 0:
                DataSet -> FieldValues["VID_EDU1"] = "�������";
            break;
        case 1:
                DataSet -> FieldValues["VID_EDU1"] = "�������";
            break;
    }
}
double TDM::ball_result (                                                       // �������, ������� ���������� ��������� �����������
        int b,                                                                  // int b - ���������� ������
        int f                                                                   // int f - ���������
    )
{
    double b_10;

    if (f != 4)
    {
        // if (b >= 1  && b <= 7)   b_10 = 1;
        // if (b >= 8  && b <= 14)  b_10 = 2;

        // if (b >= 15 && b <= 16)  b_10 = 2.1;
        // if (b >= 17 && b <= 18)  b_10 = 2.2;
        // if (b >= 19 && b <= 20)  b_10 = 2.3;
        // if (b >= 21 && b <= 22)  b_10 = 2.4;
        // if (b >= 23 && b <= 24)  b_10 = 2.5;
        // if (b >= 25 && b <= 26)  b_10 = 2.6;


        if (b >= 1  && b <  20)
            b_10                = 1;

        if (b >= 20 && b <= 21)
            b_10                = 2.1;

        if (b >= 22)
            b_10                = (double) b / 10;

        int n = 1;                                                              // ��������!!!! ���������� �� n ������ ����� �������

        if (b_10 > 0)
            b_10 = floor (b_10 * pow10 (n) + 0.5) * pow10 (-n);
    }
    else
        b_10 = b;

    return b_10;
}
float TDM::ball_result_float (                                                  // ������������ ������ �����������
        int b,                                                                  // ���������� �������
        int predmet,                                                            // �������
        int rus_bel,                                                            // ��������� ���� (0 - ���, 1 - ���, 2 - ���������)
        int k
    )
{
    float b_10;

    // if (f != 4)
    // {
    //     if (b >= 1  && b <= 7 )  b_10 = 1;
    //     if (b >= 8  && b <= 14)  b_10 = 2;

    //     if (b >= 15 && b <= 16)  b_10 = 2.1;
    //     if (b >= 17 && b <= 18)  b_10 = 2.2;
    //     if (b >= 19 && b <= 20)  b_10 = 2.3;
    //     if (b >= 21 && b <= 22)  b_10 = 2.4;
    //     if (b >= 23 && b <= 24)  b_10 = 2.5;
    //     if (b >= 25 && b <= 26)  b_10 = 2.6;

    //     if (b >= 1  && b <  20)  b_10 = 1;
    //     if (b >= 20 && b <= 21)  b_10 = 2.1;

    //     if (b >= 22)             b_10 = (float) b / 10;

    //     int n = 1;                                                              // ���������� �� n ������ ����� �������

    //     if (b_10 > 0)
    //         b_10 = floor (b_10 * pow10 (n) + 0.5) * pow10 (-n);
    // }
    // else
    //     b_10 = b;

    TFDStoredProc * pr;                                                         // ���������

    pr = DM -> StoredProcBall_Sertifikat;

    pr -> ParamByName ("PR")  -> AsInteger  = predmet;
    pr -> ParamByName ("B_S") -> AsSmallInt = b;                                // ���� �����������
    pr -> ParamByName ("R_B") -> AsSmallInt = rus_bel;

    pr -> Prepare ();
    pr -> ExecProc ();

    b_10 = pr -> ParamByName ("B") -> AsFloat;                                  // AsDouble;

    int n = 1;                                                                  // ���������� �� n ������ ����� �������
    if (b_10 > 0)
        b_10 = floor (b_10 * pow10 (n) + 0.5) * pow10 (-n);

    if (nom_fac == 4 && k != 2)
        b_10 = b;

    pr -> Unprepare ();
    pr -> Close ();

    return b_10;
}
AnsiString TDM::get_version ()                                                  // ������� ���������� ������ ���������
{
    const AnsiString sFileName = Application -> ExeName;
          AnsiString ver;
          DWORD      h,
                     Size      =
                                GetFileVersionInfoSize (
                                    sFileName.c_str (),
                                    & h
                                );
          char *     buf;

    if (Size == 0)
        return "";

    buf =
        (char *)
        GlobalAlloc (
            GMEM_FIXED,
            Size
        );

    if (    GetFileVersionInfo (
                sFileName.c_str (),
                h,
                Size,
                buf
            ) != 0
       )
    {
        char * ValueBuf;
        UINT   Len;

        VerQueryValue (
            buf,
            "\\VarFileInfo\\Translation",
            & (void *) ValueBuf,
            & Len
        );

        if (Len >= 4)
        {
            AnsiString CharSet =
                IntToHex (
                    (int)
                    MAKELONG (
                        * (int *)
                        (   ValueBuf
                          + 2
                        ),
                        * (int *)
                        ValueBuf
                    ),
                    8
                );

            if (    VerQueryValue (
                        buf,
                        AnsiString (
                            "\\StringFileInfo\\"    +
                            CharSet                 +
                            "\\FileVersion"
                        )
                        .c_str (),

                        & (void *)
                        ValueBuf,

                        & Len
                    ) != 0
               )
                ver = ValueBuf;
        }
    }

    GlobalFree (buf);

    return ver;
}
void __fastcall TDM::Increment_GroupTableNewRecord (TDataSet * DataSet)
{
    DM -> Increment_GroupTableINC_GROUP -> Value = 32000;
}
String TDM::NumDelaString (                                                     // ������� ���������� ��������� ����� ����
        int vid_edu,
        int term_edu,
        int price,
        int nom_dela
    )
{
    int
        num,
        term_ed;
    String
        num_dela_str;

    switch (term_edu)
    {
        case 0:
                term_ed = 0;
            break;
        case 1:
                term_ed = 1;
            break;
        case 2:
                term_ed = 1;
            break;
        case 3:
                term_ed = 2;
            break;
        case 4:
                term_ed = 3;
            break;
        case 5:
                term_ed = 3;
            break;
    }

    if (nom_dela > 0)
    {
        num =
                vid_edu       * 4
            +   (term_ed % 2) * 2
            +   price         + 1;

        num_dela_str =
                IntToStr (
                    nom_dela
                )               +
            "/"                 +
                IntToStr (
                    num
                );
    }
    else
        num_dela_str = "";

    return
        num_dela_str;
}
void __fastcall TDM::QAbituraAfterInsert (TDataSet * DataSet)
{
    vozvrat_inc_ab ();
}
void __fastcall TDM::QAbituraCalcFields (TDataSet * DataSet)
{
    int kkk = DM -> QAbituraKONKURS -> Value;

    switch (kkk)
    {
        case 0:
                DataSet -> FieldValues["KONKURS1"] = "�����";
            break;
        case 1:
                DataSet -> FieldValues["KONKURS1"] = "���";
            break;
        case 2:
                DataSet -> FieldValues["KONKURS1"] = "��";
            break;
        case 3:
                DataSet -> FieldValues["KONKURS1"] = "�������";
            break;
    }


    int ppp = DM -> QAbituraPRICE -> Value;

    switch (ppp)
    {
        case 0:
                DataSet -> FieldValues["PRICE1"] = "������";
            break;
        case 1:
                DataSet -> FieldValues["PRICE1"] = "�� ������";
            break;
    }


    DataSet -> FieldValues["NOM_DELA1"] =
        NumDelaString (
            DM -> QAbituraVID_EDU  -> Value,
            DM -> QAbituraTERM_EDU -> Value,
            DM -> QAbituraPRICE    -> Value,
            DM -> QAbituraNOM_DELA -> Value
        );
}
void __fastcall TDM::QAdd_N_GroupCalcFields (TDataSet * DataSet)
{
    int vid_ed = DM -> QAdd_N_GroupVID_EDU -> Value;                            // ��� ��������

    switch (vid_ed)
    {
        case 0:
                DataSet -> FieldValues["VID_EDU1"] = "�������";
            break;
        case 1:
                DataSet -> FieldValues["VID_EDU1"] = "�������";
            break;
    }


    AnsiString Stat_ab   = DM -> QAdd_N_GroupDESCRIBE -> Value,                 // �������������
               stroka_sp = "";

    int len     = Stat_ab.Length (),
        len_old = len,
        p       = 1;                                                            // ������� ������� ������� ��������� �����

    Stat_ab.Delete (
        1,
        p
    );

    for ( int i =  1;
              i <= len_old;
              i++
        )
    {
        if (len != 0)                                                           // if ���� ��� ������
        {
            p = Stat_ab.Pos (".");

            int Priv =
                StrToInt (
                    Stat_ab.SubString (
                        1,
                        p - 1
                    )
                );

            stroka_sp +=
                DM -> QSpecializ ->
                    Lookup (
                        "N_SPECIALIZ",
                        Priv,
                        "SPECIAL"
                    );

            stroka_sp += ", ";
        }
        else
            break;

        Stat_ab.Delete (
            1,
            p
        );

        len = Stat_ab.Length ();
    }

    DataSet -> FieldValues["SPEC1"] =
        stroka_sp.SetLength (
            stroka_sp.Length () - 2
        );
}
void __fastcall TDM::QCenterCalcFields (TDataSet * DataSet)
{
    Variant f = DM -> QCenterFLAG -> AsVariant;

    if ( ! f.IsNull ())                                                         // if �������� �� ������� � ��������
    {
        int fl = f.AsType (varInteger);

        switch (fl)                                                             // switch
        {
            case 0:
                    DataSet -> FieldValues["FLAG1"] = " ";
                break;
            case 1:
                    DataSet -> FieldValues["FLAG1"] = "�.";
                break;
            case 2:
                    DataSet -> FieldValues["FLAG1"] = "�-�";
                break;
            case 3:
                    DataSet -> FieldValues["FLAG1"] = "�.�.";
                break;
            case 4:
                    DataSet -> FieldValues["FLAG1"] = "�.�.";
                break;
        }
    }
}
void __fastcall TDM::QExamCalcFields (TDataSet * DataSet)
{
    Variant bbb = DataSet -> FieldValues["BALL"];

    if ( ! bbb.IsNull ())
    {
        float b = bbb;

        if (nom_fac != 4)
            DataSet -> FieldValues["BALL1"] =
                FloatToStrF (
                    b,
                    ffFixed,
                    4,
                    1
                );
        else
            if (DM -> QAbituraKONKURS -> Value == 3)
                DataSet -> FieldValues["BALL1"] =
                    FloatToStrF (
                        b,
                        ffFixed,
                        4,
                        1
                    );
            else
                DataSet -> FieldValues["BALL1"] =
                    FloatToStrF (
                        b,
                        ffFixed,
                        3,
                        0
                    );
    }
}
void __fastcall TDM::QLittle_Spisoc_GRCalcFields (TDataSet * DataSet)
{
    // AnsiString fio =
    //     " " + DataSet -> FieldValues["FAM"]  +
    //     " " + DataSet -> FieldValues["NAME"] +
    //     " " + DataSet -> FieldValues["OTCH"];

    // DataSet -> FieldValues["FIO"] = fio;

    DataSet -> FieldValues["FIO"] =
        " "                                 +
            DataSet -> FieldValues["FAM"]   +
        " "                                 +
            DataSet -> FieldValues["NAME"]  +
        " "                                 +
            DataSet -> FieldValues["OTCH"];

}
void __fastcall TDM::QReport_RaspCalcFields (TDataSet * DataSet)
{
    int vid_ed = DM -> QReport_RaspVID_EDU -> Value;

    switch (vid_ed)
    {
        case 0:
                DataSet -> FieldValues["VID_EDU1"] = "�������";
            break;
        case 1:
                DataSet -> FieldValues["VID_EDU1"] = "�������";
            break;
    }
}
void __fastcall TDM::QSertificat_ResCalcFields (TDataSet * DataSet)
{
    // AnsiString fio =
    //         DataSet -> FieldValues["FAM"]   +
    //     " "                                 +
    //         DataSet -> FieldValues["NAME"]  +
    //     " "                                 +
    //         DataSet -> FieldValues["OTCH"];

    // DataSet -> FieldValues["FIO"] =
    //     " " + fio;

    DataSet -> FieldValues["FIO"] =
        " "                                 +
            DataSet -> FieldValues["FAM"]   +
        " "                                 +
            DataSet -> FieldValues["NAME"]  +
        " "                                 +
            DataSet -> FieldValues["OTCH"];
}
void __fastcall TDM::QSertificatCalcFields (TDataSet * DataSet)
{
    Variant v = DM -> QSertificatRUS_BEL -> AsVariant;

    if ( ! v.IsNull ())                                                         // if �������� �� ������� � ��������
    {
        int rus_bel = DM -> QSertificatRUS_BEL -> Value;

        switch (rus_bel)                                                        // ���� �����������
        {
            case 0:
                    DataSet -> FieldValues["RUS_BEL1"] = "���.";
                break;
            case 1:
                    DataSet -> FieldValues["RUS_BEL1"] = "���.";
                break;
        }
    }
}
void __fastcall TDM::QSpisoc_GroupCalcFields (TDataSet * DataSet)
{
    int vid_ed = DM -> QSpisoc_GroupVID_EDU -> Value;

    switch (vid_ed)
    {
        case 0:
                DataSet -> FieldValues["VID_EDU1"] = "�������";
            break;
        case 1:
                DataSet -> FieldValues["VID_EDU1"] = "�������";
            break;
    }
}
void __fastcall TDM::QSpisok_SpecCalcFields (TDataSet * DataSet)
{
    int vid_ed = DM -> QSpisok_SpecVID_EDU -> Value;

    switch (vid_ed)
    {
        case 0:
                DataSet -> FieldValues["VID_EDU1"] = "�������";
            break;
        case 1:
                DataSet -> FieldValues["VID_EDU1"] = "�������";
            break;
    }
}
void __fastcall TDM::QToDekanatAfterInsert (TDataSet * DataSet)
{
    vozvrat_inc_people ();
}
void __fastcall TDM::TCategoryNewRecord (TDataSet * DataSet)
{
    DM -> TCategoryN_SPORT_CATEGORY -> Value = 32000;
}
void __fastcall TDM::TCkNewRecord (TDataSet * DataSet)
{
    DM -> TCkN_CK -> Value                   = 32000;
}
void __fastcall TDM::TDocumNewRecord (TDataSet * DataSet)
{
    DM -> TDocumN_DOC -> Value               = 32000;
}
void __fastcall TDM::TFacultyNewRecord (TDataSet * DataSet)
{
    DM -> TFacultyN_FAC -> Value             = 32000;
}
void __fastcall TDM::TFoundationNewRecord (TDataSet * DataSet)
{
    DM -> TFoundationN_FOUND -> Value        = 32000;
}
void __fastcall TDM::TKol_PlaceCalcFields (TDataSet * DataSet)
{
    int ttt = DM -> TKol_PlaceTEXT -> Value;

    switch (ttt)
    {
        case 0:
                DataSet -> FieldValues["TEXT1"] = "��";
            break;
        case 1:
                DataSet -> FieldValues["TEXT1"] = "2 ����";
            break;
        case 2:
                DataSet -> FieldValues["TEXT1"] = "3 ����";                     // ������!!!
            break;
        case 3:
                DataSet -> FieldValues["TEXT1"] = "-�� ������";                 // ������!!!
            break;
    }


    int vid_ed = DM -> TKol_PlaceVID_EDU -> Value;

    switch (vid_ed)
    {
        case 0:
                DataSet -> FieldValues["VID_EDU1"] = "�������";
            break;
        case 1:
                DataSet -> FieldValues["VID_EDU1"] = "�������";
            break;
    }


    int price_tmp = DM -> TKol_PlacePRICE -> Value;

    switch (price_tmp)
    {
        case 0:
                DataSet -> FieldValues["PRICE1"] = "������";
            break;
        case 1:
                DataSet -> FieldValues["PRICE1"] = "�� ������";
            break;
    }
}
void __fastcall TDM::TKol_PlaceNewRecord (TDataSet * DataSet)
{
    DM -> TKol_PlaceN_KOL_PLACE -> Value = 32000;
}
void __fastcall TDM::TPredmetNewRecord (TDataSet * DataSet)
{
    DM -> TPredmetN_PREDMET -> Value     = 32000;
}
void __fastcall TDM::TRegionAfterOpen (TDataSet * DataSet)
{
    SplashForm -> ProgressBar1 -> StepBy (8);
}
void __fastcall TDM::TRegionNewRecord (TDataSet * DataSet)
{
    DM -> TRegionN_REGION -> Value       = 32000;
}
void __fastcall TDM::TVid_SportNewRecord (TDataSet * DataSet)
{
    DM -> TVid_SportN_VID_SPORT -> Value = 32000;
}
void __fastcall TDM::vozvrat_inc_ab ()                                          // ������� ���������� ��������� ������ �����������
{
    DM -> StoredProcN_AB -> Prepare ();
    DM -> StoredProcN_AB -> ExecProc ();

    DM -> QAbituraNOMER_AB -> Value =
            DM -> StoredProcN_AB ->
                ParamByName ("NAB") -> AsInteger;
}
void __fastcall TDM::vozvrat_inc_people ()                                      // ������� ���������� ��������� ������ ��������
{
    DM -> StoredProcN_People -> Prepare ();
    DM -> StoredProcN_People -> ExecProc ();

    DM -> QToDekanatNOMER  -> Value =
            DM -> StoredProcN_People ->
                ParamByName ("NP") -> AsInteger;

    DM -> QToDekanatNUMBER -> Value =
            DM -> StoredProcN_People ->
                ParamByName ("ND") -> AsInteger;
}
AnsiString TDM::vozvrat_spec (int spec)                                         // ������� ���������� �������� ����������� �������������
{
    AnsiString spec_name = "";

    if (DM -> QSpecializ -> State == dsInactive)
    {
        DM -> QSpecializ ->
            ParamByName ("N_FAC") -> AsInteger =
                    nom_fac;

        DM -> QSpecializ -> Open ();
    }

    spec_name =
        DM -> QSpecializ ->
            Lookup (
                "N_SPECIALIZ",
                spec,
                "SPECIAL_DIRECTION"
            );

    return
        spec_name;
}

