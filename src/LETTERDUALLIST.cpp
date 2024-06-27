#include <vcl.h>
#pragma hdrstop


#include <jpeg.hpp>
#include <graphics.hpp>


#include "DMUnit.h"
#include "LETTERDUALLIST.h"
#include "LetterUnit.h"
#include "MainUnit.h"
#include "NoticeUnit.h"


#pragma resource "*.dfm"


TLetterDualListDlg * LetterDualListDlg;


TfrxPictureView  * pic;
TFDBlobStream    * pot;
Jpeg::TJPEGImage * jpga;



__fastcall TLetterDualListDlg::TLetterDualListDlg (TComponent * AOwner)
    : TForm (AOwner)
{ }



void __fastcall TLetterDualListDlg::ExcAllBtnClick (TObject * Sender)
{
    for (int i = 0;
             i < DstList -> Items -> Count;
             ++i
        )
    {
        SrcList -> Items ->
            AddObject (
                DstList -> Items -> Strings[i],
                DstList -> Items -> Objects[i]
            );
        SrcListI -> Items ->
            AddObject (
                DstListI -> Items -> Strings[i],
                DstListI -> Items -> Objects[i]
            );
    }

    DstList  -> Items -> Clear ();
    DstListI -> Items -> Clear ();

    SetItem (
        DstList,
        0
    );
    SetItem (
        DstListI,
        0
    );

    SrcLabel -> Caption =
        "������ ����������� ("                      +
            IntToStr (SrcList -> Items -> Count)    +
        " ���.)";
    DstLabel -> Caption =
        "������ ��� ������ (0 ���.)";
}
void __fastcall TLetterDualListDlg::ExcludeBtnClick (TObject * Sender)
{
    int Index = GetFirstSelection (DstList);

    MoveSelected (
        DstList,
        SrcList  -> Items,
        DstListI,
        SrcListI -> Items
    );
    SetItem (
        DstList,
        Index
    );

    SrcLabel -> Caption =
        "������ ����������� ("                      +
            IntToStr (SrcList -> Items -> Count)    +
        " ���.)";

    DstLabel -> Caption =
        "������ ��� ������ ("                       +
            IntToStr (DstList -> Items -> Count)    +
        " ���.)";
}
void __fastcall TLetterDualListDlg::FormActivate (TObject * Sender)
{
    DM -> QLetterSource    -> Close ();
    DM -> QLetterSourceKol -> Close ();

    SrcList  -> Items -> Clear ();
    SrcListI -> Items -> Clear ();

    DM -> QLetterSource    -> ParamByName ("n_fac") -> AsSmallInt = nom_fac;
    DM -> QLetterSourceKol -> ParamByName ("n_fac") -> AsSmallInt = nom_fac;

    DM -> QLetterSource    -> Open ();
    DM -> QLetterSourceKol -> Open ();

    int num_list = DM -> QLetterSourceKolCOUNT -> Value;

    for (int i = 0;
             i < num_list;
             ++i
        )
    {
        SrcList -> Items ->
            Add (
                    DM -> QLetterSourceFAM            -> AsString   +
                " "                                                 +
                    DM -> QLetterSourceNAME           -> AsString   +
                " "                                                 +
                    DM -> QLetterSourceOTCH           -> AsString   +
                ",   "                                              +
                    DM -> QLetterSourceADDRESS_BEFORE -> AsString
            );

        SrcListI -> Items -> Add (DM -> QLetterSourceNOMER_AB -> AsInteger);

        DM -> QLetterSource -> Next ();
    }

    DM -> QLetterSource    -> Close ();
    DM -> QLetterSourceKol -> Close ();

    SrcLabel -> Caption =
        "������ ����������� ("                      +
            IntToStr (SrcList -> Items -> Count)    +
        " ���.)";
    DstLabel -> Caption =
        "������ ��� ������ ("                       +
            IntToStr (DstList -> Items -> Count)    +
        " ���.)";
}
int __fastcall TLetterDualListDlg::GetFirstSelection (TCustomListBox * List)
{
    for (int i = 0;
             i < List -> Items -> Count;
             ++i
        )
    {
        if (List -> Selected[i])
            return
                i;
    }

    return
        LB_ERR;
}
void __fastcall TLetterDualListDlg::IncAllBtnClick (TObject * Sender)
{
    for (int i = 0;
             i < SrcList -> Items -> Count;
             ++i
        )
    {
        DstList -> Items ->
            AddObject (
                SrcList -> Items -> Strings[i],
                SrcList -> Items -> Objects[i]
            );
        DstListI -> Items ->
            AddObject (
                SrcListI -> Items -> Strings[i],
                SrcListI -> Items -> Objects[i]
            );
    }

    SrcList  -> Items -> Clear ();
    SrcListI -> Items -> Clear ();

    SetItem (
        SrcList,
        0
    );
    SetItem (
        SrcListI,
        0
    );

    SrcLabel -> Caption =
        "������ ����������� (0 ���.)";
    DstLabel -> Caption =
        "������ ��� ������ ("                       +
            IntToStr (DstList -> Items -> Count)    +
        " ���.)";
}
void __fastcall TLetterDualListDlg::IncludeBtnClick (TObject * Sender)
{
    int Index = GetFirstSelection (SrcList);                                    // ����� ������� ����������

    MoveSelected (
        SrcList,
        DstList  -> Items,
        SrcListI,
        DstListI -> Items
    );
    SetItem (
        SrcList,
        Index
    );

    SrcLabel -> Caption =
        "������ ����������� ("                      +
            IntToStr (SrcList -> Items -> Count)    +
        " ���.)";

    DstLabel -> Caption =
        "������ ��� ������ ("                       +
            IntToStr (DstList -> Items -> Count)    +
        " ���.)";
}
void __fastcall TLetterDualListDlg::MoveSelected (
        TCustomListBox * List1,
        TStrings       * Items1,
        TCustomListBox * List2,
        TStrings       * Items2
    )
{
    for (int i =  List1 -> Items -> Count - 1;
             i >= 0;
             --i
        )
    {
        if (List1 -> Selected[i])
        {
            Items1 -> AddObject (
                List1 -> Items -> Strings[i],
                List1 -> Items -> Objects[i]
            );
            Items2 -> AddObject (
                List2 -> Items -> Strings[i],
                List2 -> Items -> Objects[i]
            );
            List1 -> Items -> Delete (i);
            List2 -> Items -> Delete (i);
        }
    }
}
void __fastcall TLetterDualListDlg::OKBtnClick (TObject * Sender)
{
    if (    MessageDlg (                                                        // ������ ���������
                "�������� ��������?",
                mtCustom,
                mbOKCancel,
                0
            ) == 1
       )
    {
        AnsiString
            IndexStr1,
            IndexStr2,
            IndexStr3,
            IndexStr4,
            IndexStr5,
            IndexStr6;
        int
            PosSign;

        for (int i = 0;                                                         // ���� �� ������� ���������� �������
                 i < DstList -> Items -> Count;
                 ++i
            )
        {
            LetterForm = new TLetterForm (this);

            TfrxMemoView * MemoI1 =
                dynamic_cast <TfrxMemoView *>
                (
                    LetterForm -> frxReport1 ->
                        FindObject ("MemoI1")
                );
            TfrxMemoView * MemoI2 =
                dynamic_cast <TfrxMemoView *>
                (
                    LetterForm -> frxReport1 ->
                        FindObject ("MemoI2")
                );
            TfrxMemoView * MemoI3 =
                dynamic_cast <TfrxMemoView *>
                (
                    LetterForm -> frxReport1 ->
                        FindObject ("MemoI3")
                );
            TfrxMemoView * MemoI4 =
                dynamic_cast <TfrxMemoView *>
                (
                    LetterForm -> frxReport1 ->
                        FindObject ("MemoI4")
                );
            TfrxMemoView * MemoI5 =
                dynamic_cast <TfrxMemoView *>
                (
                    LetterForm -> frxReport1 ->
                        FindObject ("MemoI5")
                );
            TfrxMemoView * MemoI6 =
                dynamic_cast <TfrxMemoView *>
                (
                    LetterForm -> frxReport1 ->
                        FindObject ("MemoI6")
                );
            TfrxMemoView * MemoPeople =
                dynamic_cast <TfrxMemoView *>
                (
                    LetterForm -> frxReport1 ->
                        FindObject ("MemoPeople")
                );
            TfrxMemoView * MemoAdr =
                dynamic_cast <TfrxMemoView *>
                (
                    LetterForm -> frxReport1 ->
                        FindObject ("MemoAdr")
                );
            TfrxMemoView * MemoAdrCity =
                dynamic_cast <TfrxMemoView *>
                (
                    LetterForm -> frxReport1 ->
                        FindObject ("MemoAdrCity")
                );

            String TempStr = DstList->Items->Strings[i];

            IndexStr1      = TempStr[TempStr.Length()];

            while (IndexStr1 == " ")
            {
                TempStr.Delete (
                    TempStr.Length (),
                    1
                );

                IndexStr1 = TempStr[TempStr.Length ()];
            }

            IndexStr1 = TempStr[TempStr.Length () - 5];
            IndexStr2 = TempStr[TempStr.Length () - 4];
            IndexStr3 = TempStr[TempStr.Length () - 3];
            IndexStr4 = TempStr[TempStr.Length () - 2];
            IndexStr5 = TempStr[TempStr.Length () - 1];
            IndexStr6 = TempStr[TempStr.Length ()];

            if (    StrToInt (IndexStr1) >= 0 && StrToInt (IndexStr1) <= 9      // �������� �� ����� � �������
                 && StrToInt (IndexStr2) >= 0 && StrToInt (IndexStr2) <= 9
                 && StrToInt (IndexStr3) >= 0 && StrToInt (IndexStr3) <= 9
                 && StrToInt (IndexStr4) >= 0 && StrToInt (IndexStr4) <= 9
                 && StrToInt (IndexStr5) >= 0 && StrToInt (IndexStr5) <= 9
                 && StrToInt (IndexStr6) >= 0 && StrToInt (IndexStr6) <= 9
               )
            {
                MemoI1 -> Text = IndexStr1;
                MemoI2 -> Text = IndexStr2;
                MemoI3 -> Text = IndexStr3;
                MemoI4 -> Text = IndexStr4;
                MemoI5 -> Text = IndexStr5;
                MemoI6 -> Text = IndexStr6;

                TempStr.Delete (                                                // ��� ������� ������� ������� ��� �� ������ ������
                    TempStr.Length () - 5,
                    6
                );
            }
            else
            {
                MemoI1 -> Text = "";                                            // ��� ���������� ������� �������� ��� �� ��������
                MemoI2 -> Text = "";
                MemoI3 -> Text = "";
                MemoI4 -> Text = "";
                MemoI5 -> Text = "";
                MemoI6 -> Text = "";
            }


            IndexStr1 = TempStr[1];                                             // ������� ������� � ������

            while (IndexStr1 == " ")
            {
                TempStr.Delete (
                    1,
                    1
                );

                IndexStr1 = TempStr[1];
            }


            PosSign = TempStr.Pos (",");                                        // ���

            MemoPeople -> Text =
                TempStr.SubString (
                    1,
                    PosSign - 1
                );


            TempStr.Delete (                                                    // ����� ������� ������� � ������� � ������
                1,
                PosSign
            );

            IndexStr1 = TempStr[1];

            while (IndexStr1 == " ")
            {
                TempStr.Delete (
                    1,
                    1
                );

                IndexStr1 = TempStr[1];
            }

            PosSign = TempStr.Pos (",");

            MemoAdrCity -> Text =
                TempStr.SubString (
                    1,
                    PosSign - 1
                );


            TempStr.Delete(                                                     // ����� - ������� ������� � ������� � ������
                1,
                PosSign
            );

            IndexStr1 = TempStr[1];

            while (IndexStr1 == " ")
            {
                TempStr.Delete (
                    1,
                    1
                );

                IndexStr1 = TempStr[1];
            }

            IndexStr1 = TempStr[TempStr.Length ()];

            while (    IndexStr1 == " "                                         // ������� ������� � ������� � �����
                    || IndexStr1 == ","
                  )
            {
                TempStr.Delete (
                    TempStr.Length (),
                    1
                );

                IndexStr1 = TempStr[TempStr.Length ()];
            }

            MemoAdr -> Text = TempStr;

            LetterForm -> frxReport1 -> ShowReport();

            if (LetterForm)
                delete LetterForm;
        }
    }

    if (    MessageDlg (
                "�������� ���������?",
                mtCustom,
                mbOKCancel,
                0
            ) == 1
        )
    {
        ShowMessage(                                                            // ������ ���������
            "��������!\n��������� �������� "    \
            "�� �������� ����� ��������!"
        );

        NoticeForm = new TNoticeForm (this);

        String memo_text;

        for ( int i = 0;                                                        // ���� �� ��������� ������������
                  i < DstListI -> Items -> Count;
                  ++i
            )
        {
            DM -> QNoticeFIO -> Close ();                                       // ������ � ����������
            DM -> QNoticeFIO -> ParamByName ("nomer_ab")     -> AsInteger =
                DstListI -> Items -> Strings[i].ToInt ();
            DM -> QNoticeFIO -> Open ();


            DM -> QNoticeFac -> Close ();                                       // ������ � �������
            DM -> QNoticeFac -> ParamByName ("n_fac")        -> AsInteger =
                DM -> QNoticeFION_FAC -> AsInteger;
            DM -> QNoticeFac -> Open ();

            DM -> QNoticeSpec -> Close ();
            DM -> QNoticeSpec -> ParamByName ("n_specializ") -> AsInteger =
                DM -> QNoticeFION_SPECIALIZ -> AsInteger;
            DM -> QNoticeSpec -> Open ();

            TfrxMemoView * MemoFIO =                                            // ���
                dynamic_cast <TfrxMemoView *>
                (
                    NoticeForm -> frxRepNotice ->
                        FindObject ("MemoFIO")
                );
            MemoFIO -> Text =
                    DM -> QNoticeFIOFAM  -> AsString    +
                " "                                     +
                    DM -> QNoticeFIONAME -> AsString    +
                " "                                     +
                    DM -> QNoticeFIOOTCH -> AsString;

            MemoFIO -> Lines -> Add ("");


            MemoFIO -> Lines ->                                                 // �����
                Add (
                    DM -> QNoticeFIOADDRESS_BEFORE -> AsString
                );

            pic =                                                               // �������
                dynamic_cast <TfrxPictureView *>
                (
                    NoticeForm -> frxRepNotice ->
                        FindObject ("Picture3")
                );

            pic ->
                SetBounds(
                    273,
                    734,
                    178,
                    102
                );

            pic -> Transparent = true;
            pic -> Center      = true;

            if ( !  (TBlobField *)
                    DM -> Selection_CommitteeFDTableSIGNATURE -> IsNull
               )
                pic -> Picture -> Graphic =
                    DBImage1 -> Picture -> Graphic;

            memo_text =
                "������� �������� ��������, ��� �������� �� ���������� "   \
                "����������� ������������ ��������������� ����������� "     \
                "���������� ��������� � ";

            if (DM -> QNoticeFION_PRIKAZ_INCLUDE -> AsInteger > 0)              // � ������� � ����������
                memo_text +=
                        DM -> QNoticeFION_PRIKAZ_INCLUDE -> AsString    +
                    " �� �� ";
            else
                memo_text += "____�� �� ";


            if (DM -> QNoticeFIOD_PRIKAZ_INCLUDE -> AsDateTime > "01.01.2015")  // ���� ������� � ����������
                memo_text +=
                        DM -> QNoticeFIOD_PRIKAZ_INCLUDE -> AsString    +
                    "�. �� ��������� � ����� ��������� ";
            else
                memo_text += "________�. �� ��������� � ����� ��������� ";

            AnsiString
                spec_str = "(������������)";


            if (    DM -> QNoticeFIOTERM_EDU -> Value == StudyPeriodCode::FULL  // ����
                 || DM -> QNoticeFIOTERM_EDU -> Value == StudyPeriodCode::HIGH_FIRST_COURSE
               )
                memo_text += "1 ����� �� ";

            if (    DM -> QNoticeFIOTERM_EDU -> Value == StudyPeriodCode::SHORT_SECOND_COURSE
                 || DM -> QNoticeFIOTERM_EDU -> Value == StudyPeriodCode::HIGH_SECOND_COURSE
               )
                memo_text += "2 ����� �� ";

            if (    DM -> QNoticeFIOTERM_EDU -> Value == StudyPeriodCode::SHORT_THIRD_COURSE
                 || DM -> QNoticeFIOTERM_EDU -> Value == StudyPeriodCode::HIGH_THIRD_COURSE
               )
            {
                memo_text +=
                    "3 ����� �� ";
                spec_str  =
                    "(����������� �������������, �������������)";
            }


            if (DM -> QNoticeFIOVID_EDU -> AsInteger == 0)                      // ��� ��������
                memo_text += "������� ����� ��������� ����������� �� ";
            else
                memo_text += "������� ����� ��������� ����������� �� ";



            if (    DM -> QNoticeFION_SPECIALIZ -> AsInteger                    // ���������
                 != KindOfSportCode::TOURISM_HOSPITALITY
               )
                memo_text +=
                        DM -> QNoticeFacFAC -> AsString.LowerCase ()    +
                    " �� ������������� "                                +
                        spec_str                                        +
                    " ";
            else
                memo_text +=
                        DM -> QNoticeFacFAC -> AsString                 +
                    " �� ������������� ";

            int nSpecDir   = DM -> QNoticeSpecN_SPEC_DIR -> AsInteger;
            int nSpecializ = DM -> QNoticeFION_SPECIALIZ -> AsInteger;

            if (    //DM -> QNoticeFIOTERM_EDU -> Value == 0)
                    DM -> QNoticeFIOTERM_EDU -> Value != StudyPeriodCode::HIGH_SECOND_COURSE
                 && DM -> QNoticeFIOTERM_EDU -> Value != StudyPeriodCode::HIGH_THIRD_COURSE
               )
                memo_text +=
                    DeleteAfterDatabaseChange::getNcrb2022CodeNameSportStrByNSpecializ (
                        nSpecializ
                    );
            else
                memo_text +=
                        DM -> QNoticeSpecCODE_SPEC_DIR     -> AsString  +       // ��� �������������
                    " �"                                                +
                        DM -> QNoticeSpecSPECIAL_DIRECTION -> AsString  +       // ������������ �������������
                    "�";

            if (DM -> QNoticeFIOVID_EDU -> AsInteger == 0)                      // ��� ��������
                memo_text +=
                    " � ����������� (��� ����������) � ��������� � ";
            else
                memo_text +=
                    " ��� ���������� � ��������� � ";

            memo_text += "������ ������� � ���������� ����������� ";


            if (DM -> QNoticeFIOVID_EDU -> AsInteger == 0)                      // ���� �������� (�������)
                memo_text +=
                        Admissions::ARRIVAL::DATE::INTRAMURAL::ALL +
                    " �. � "                                        +
                        Admissions::ARRIVAL::TIME::EVERYONE         +
                    " (������� ������).";
            else                                                                // ���� �������� (�������)
            {
                if (    DM -> QNoticeFIOTERM_EDU -> AsInteger == StudyPeriodCode::FULL
                     || DM -> QNoticeFIOTERM_EDU -> AsInteger == StudyPeriodCode::HIGH_FIRST_COURSE
                   )
                {
                    switch (DM -> QNoticeFION_FAC -> AsInteger)
                    {
                        case FacultyCode::MSTH:
                                if (nSpecializ == KindOfSportCode::TOURISM_HOSPITALITY)
                                    memo_text +=
                                        Admissions::ARRIVAL::DATE::EXTRAMURAL::FULL::MSTH_TOURISM;
                                else
                                    memo_text +=
                                        Admissions::ARRIVAL::DATE::EXTRAMURAL::FULL::MSTH_MNG;
                            break;

                        default:
                                memo_text +=
                                    Admissions::ARRIVAL::DATE::EXTRAMURAL::FULL::OTHER;
                            break;
                    }
                }

                if (    DM -> QNoticeFIOTERM_EDU -> AsInteger == StudyPeriodCode::SHORT_SECOND_COURSE
                     || DM -> QNoticeFIOTERM_EDU -> AsInteger == StudyPeriodCode::HIGH_SECOND_COURSE
                   )
                {
                    switch (DM -> QNoticeFION_FAC -> AsInteger)
                    {
                        case FacultyCode::SMA:
                                memo_text +=
                                        Admissions::ARRIVAL::DATE::EXTRAMURAL::SECOND_COURSE::SMA            +
                                    " (������� �������� �� ������� ������ c "                                +
                                        Admissions::ARRIVAL::DATE::EXTRAMURAL::SECOND_COURSE::SKIING::SMA    +
                                    ")";
                            break;
                        case FacultyCode::MS:
                                memo_text +=
                                        Admissions::ARRIVAL::DATE::EXTRAMURAL::SECOND_COURSE::MS             +
                                    " (������� �������� �� ������� ������ c "                                +
                                        Admissions::ARRIVAL::DATE::EXTRAMURAL::SECOND_COURSE::SKIING::MS     +
                                    ")";
                            break;
                        case FacultyCode::RPC:
                                memo_text +=
                                        Admissions::ARRIVAL::DATE::EXTRAMURAL::SECOND_COURSE::RPC            +
                                    " (������� �������� �� ������� ������ c "                                +
                                        Admissions::ARRIVAL::DATE::EXTRAMURAL::SECOND_COURSE::SKIING::RPC    +
                                    ")";
                            break;
                        case FacultyCode::MSTH:
                                if (nSpecializ == KindOfSportCode::TOURISM_HOSPITALITY)
                                    memo_text +=
                                        Admissions::ARRIVAL::DATE::EXTRAMURAL::SECOND_COURSE::MSTH_TOURISM;
                                else
                                    memo_text +=
                                        Admissions::ARRIVAL::DATE::EXTRAMURAL::SECOND_COURSE::MSTH_MNG;
                            break;
                    }
                }

                if (    DM -> QNoticeFIOTERM_EDU -> AsInteger == StudyPeriodCode::SHORT_THIRD_COURSE
                     || DM -> QNoticeFIOTERM_EDU -> AsInteger == StudyPeriodCode::HIGH_THIRD_COURSE
                   )
                {
                    switch (DM -> QNoticeFION_FAC -> AsInteger)
                    {
                        case FacultyCode::SMA:
                                memo_text +=
                                    Admissions::ARRIVAL::DATE::EXTRAMURAL::THIRD_COURSE::SMA;
                            break;
                        case FacultyCode::MS:
                                memo_text +=
                                    Admissions::ARRIVAL::DATE::EXTRAMURAL::THIRD_COURSE::MS;
                            break;
                        case FacultyCode::RPC:
                                memo_text +=
                                    Admissions::ARRIVAL::DATE::EXTRAMURAL::THIRD_COURSE::RPC;
                            break;
                        case FacultyCode::MSTH:
                                if (nSpecializ == KindOfSportCode::TOURISM_HOSPITALITY)
                                    memo_text +=
                                        Admissions::ARRIVAL::DATE::EXTRAMURAL::THIRD_COURSE::MSTH_TOURISM;
                                else
                                    memo_text +=
                                        Admissions::ARRIVAL::DATE::EXTRAMURAL::THIRD_COURSE::MSTH_MNG;
                            break;
                    }
                }
            }

            TfrxMemoView * Memo2 =
                dynamic_cast <TfrxMemoView *>
                (
                    NoticeForm -> frxRepNotice ->
                        FindObject ("Memo2")
                );

            Memo2 -> Text = memo_text;

            TfrxMemoView * Memo4 =
                dynamic_cast <TfrxMemoView *>
                (
                    NoticeForm -> frxRepNotice ->
                        FindObject ("Memo4")
                );

            Memo4 -> Text = LegallyAuthorizedPerson::SECRETARY;


            TfrxMemoView * MemoLetterDate =                                     // ���� ������
                dynamic_cast <TfrxMemoView *>
                (
                    NoticeForm -> frxRepNotice ->
                        FindObject ("MemoLetterDate")
                );

            if (DM -> QNoticeFIOD_PRIKAZ_INCLUDE -> AsDateTime > "01.01.2015")
                MemoLetterDate -> Text =
                        DM -> QNoticeFIOD_PRIKAZ_INCLUDE -> AsString    +
                    " �.";
            else
                MemoLetterDate -> Text = "__________�.";

            NoticeForm -> frxRepNotice -> PrepareReport (False);                // ���������� �������� ������
        }

        DM -> QNoticeFIO  -> Close();
        DM -> QNoticeFac  -> Close();
        DM -> QNoticeSpec -> Close();

        NoticeForm -> frxRepNotice -> ShowPreparedReport ();

        if (NoticeForm)
            delete NoticeForm;
    }

    MainForm -> Show ();
}
void __fastcall TLetterDualListDlg::SetButtons ()
{
    if (SrcList -> Items -> Count == 0)
    {
        IncludeBtn -> Enabled = false;
        IncAllBtn  -> Enabled = false;
    }
    else
    {
        IncludeBtn -> Enabled = true;
        IncAllBtn  -> Enabled = true;
    }

    if (DstList -> Items -> Count == 0)
    {
        ExcludeBtn -> Enabled = false;
        ExAllBtn   -> Enabled = false;
    }
    else
    {
        ExcludeBtn -> Enabled = true;
        ExAllBtn   -> Enabled = true;
    }
}
void __fastcall TLetterDualListDlg::SetItem (
        TListBox * List,
        int        Index
    )
{
    List -> SetFocus ();

    int MaxIndex = List -> Items -> Count - 1;

    if (Index == LB_ERR)
        Index = 0;
    else
        if (Index > MaxIndex)
            Index = MaxIndex;

    List -> Selected[Index] = true;

    SetButtons ();
}
