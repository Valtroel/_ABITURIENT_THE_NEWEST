// ---------------------------------------------------------------------------

#include <vcl.h>
#include <systdate.h>
#include <jpeg.hpp>
#include <graphics.hpp>
#include <Classes.hpp>
#pragma hdrstop
#include "AbiturUnit.h"
#include "DMUnit.h"
#include "Priv_EnterUnit.h"
#include "ListDlgUnit.h"
#include "Undo_Ab_Unit.h"
#include "MainUnit.h"
#include "SertificatUnit.h"
#include "EducationUnit.h"
#include "SredBalUnit.h"
#include "Undo_Ab_1Unit.h"
#include "DMStatUnit.h"
#include "DMVedUnit.h"
#include "Rep_Sel_Exerc.h"
#include "DUALLISTDOC.h"
#include "AddressUnit.h"
#include "AddressLifeUnit.h"
#include "SplashUnit.h"
// ---------------------------------------------------------------------------
// #pragma package(smart_init)
#pragma resource "*.dfm"
TAbiturForm *AbiturForm;

// ��� ������������ ���������� �� ������ ��������

TMemoryStream* pms;
Jpeg::TJPEGImage *jp;
// ���������� ��� ����������� �������� �������� � OpenDialog
bool ForceCurrentDirectory = true;

bool st_ins = false; // ���������� ��� �������� ���������� �����������

int mas_sel_exerc[3][2]; // ������ ��������� ����������� ����������

AnsiString SQLText = "SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
            ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
            D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
            EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
            N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
            N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
            NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
            NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
            PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
            STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
            VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
            WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, DISABLED, \
            STREET, HOUSE, FLAT, POSTCODE \
            FROM ABITURA WHERE (N_FAC=:N_FAC) AND (STATUS=0) ";

bool mess; // ���������� ��� ����������� ������ ���������
int ChangLog; // ������ ��������� ������� ����������� ����������� � ������
// -1 - ��������� ���������
// 0 - ��������� �� ������ ���
// 1 - ������������ ��������� � ������������� �����������
// 2 - ����� ����������

int AddAbiturPerm, TookDoc1Perm, TookDoc2Perm, ReInsideFacPerm, RestorListPerm;
// ������ 0 - ��������, 1- �� ��������
// �������� ������ ����������� (AddBtBtn)
// ������ ��������� �� ��������� ����� ���������� (TookDocBtBtn1)
// ������ ��������� �� ����� ��������� (TookDocBtBtn2)
// ���������� ���������� ������ ���������� (ReInsideFacBtBtn)
// ������������ � ������ (RestorlistBtBtn)

struct OldKonkurs // ��������� ��� ������������� ���������� �������� �����������
{
    int FormEduIndex;
    int SpecializDBLookupIndex;
    int CategoryAbIndex;
    int SngFrgIndex;
    int EducatIndex;
    int TermEduIndex;
    int PriceIndex;
    int KonkursIndex;
};

OldKonkurs OldKonkursVal;

bool pan1,
     pan2,
     pan3,
     pan4,
     pan5,
     pan6,
     pan7;


int  region_id,                                                                 // ������ �������� ����� ���������
     panH1     = 220,                                                           // Unrolled 'CONDITIONS' Panel  220px
     panH2     = 80,                                                            // Unrolled 'ADDRESS'    Panel   80px
     panH3     = 80,                                                            // Unrolled 'PASSPORT'   Panel   80px
     panH4     = 245,                                                           // Unrolled 'EDUCATION'  Panel  300px
     panH5     = 55,                                                            // Unrolled 'JOB'        Panel   60px
     panH6     = 130,                                                           // Unrolled 'RELATIVES'  Panel  130px
     panH7     = 477;                                                           // Unrolled 'BENEFITS'   Panel  400px

// ---------------------------------------------------------------------------
__fastcall TAbiturForm::TAbiturForm (TComponent * Owner)
    : TForm (Owner)
{
    DM -> QAbitura -> Open ();
}

// ---------------------------------------------------------------------------
/* void __fastcall TAbiturForm::VidKonkurs()
 {//��������� ��������� �������� �����������
 //������� ���������� ���� � ��������� ����� ������� (�.�. oplata_konkurs==0)

 KonkursRdGrp->Enabled=true;

 price = PriceRdGrp->ItemIndex;    //������/�� ������
 //vid_edu = ComboBox1->ItemIndex;    //�������/�������
 vid_edu = FormEduCmbBx->Text; //�������/�������

 switch (price)
 {
 case 0: //������
 KonkursRdGrp->Items->Strings[0] = "���������";
 KonkursRdGrp->Controls[1]->Enabled = true;            //���� ���� (�� � ����)

 if (vid_edu=="�������" & nom_fac!=4)
 KonkursRdGrp->Controls[2]->Enabled = true;            //�� �� ���� (����� ��)
 else KonkursRdGrp->Controls[2]->Enabled = false;      //�� ���� ���

 if (vid_edu=="�������" & (nom_fac==1 || nom_fac==2)) //�� 2 ���� ������ ���� � ���
 KonkursRdGrp->Controls[3]->Enabled = true;            //2 ����  ��  ����
 else KonkursRdGrp->Controls[3]->Enabled = false;      //2 ���� ����  ���

 KonkursRdGrp->Controls[6]->Enabled = false;           //���������� ���
 break;

 case 1: //�� ������
 KonkursRdGrp->Items->Strings[0] = "�����";
 KonkursRdGrp->Controls[1]->Enabled = false;  //���� ���
 KonkursRdGrp->Controls[2]->Enabled = false;  //�� ���
 if (nom_fac==1 || nom_fac==2)               //�� 2 ���� ������ ���� � ���
 KonkursRdGrp->Controls[3]->Enabled = true;   //2 ���� ����
 KonkursRdGrp->Controls[6]->Enabled = true;   //���������� ����
 break;
 }

 }//end ��������� ��������� �������� ����������� */
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::NameBtn()
{ // ��������� ���������� ���� ��������� ������� � ����������� �� ����������
    // ��� ��������� ������� ������ ��������
    if (nom_fac != 4) {
        TookDocBtBtn1->Hint = "�� 17.07.2019!";
        RestorlistBtBtn->Hint = "�� 17.07.2019!";
        TookDocBtBtn2->Hint = "� 18.07.2019!";
        ReInsideFacBtBtn->Hint = "����� ����������!";
    }
    else {
        TookDocBtBtn1->Hint =
            "�� ������ �� 17.07.2019!   �� ������ �� 04.08.2019!";
        RestorlistBtBtn->Hint =
            "�� ������ �� 17.07.2019!   �� ������ �� 04.08.2019!";
        TookDocBtBtn2->Hint =
            "�� ������ � 18.07.2019!   �� ������ c 05.08.2019!!"; /* */
        ReInsideFacBtBtn->Hint = "����� ����������!";
    }
} // end ��������� ���������� ���� ��������� ������� � ����������� �� ����������

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::PressBtn(int press_btn) { // ������� ������
    switch (press_btn) { // switch
        // case 0:
    case 1:
        // ����� �����������
        /* ExitBitBtn->Enabled = true;
         ExitBitBtn->Visible = true; */
        press = 1;

        break;
    case 2:
        // ���� ������ ������ ��������
        /* ExitBitBtn->Enabled = false; // �����
		 ExitBitBtn->Visible = false; // ����� */
		KonkursCmbBx->Enabled = false; // �������
        /* HMENU MenuHandle = GetSystemMenu(Handle, false);
         if(MenuHandle)
         DeleteMenu(MenuHandle, SC_CLOSE, MF_BYCOMMAND); */
        press = 2;
        break;
    case 3:
        // ���� ������ ������ ����������� � ������
        press = 3;
        break;
    case 4:
        // ���� ������ ������ ���������� ����������
        press = 4;
        break;
    } // end switch
}

// ----------------------------------------------------------------------------
void __fastcall TAbiturForm::BitBtnShow() {
    /* PoleBlock(); // ��������� �������� ����� BLOCK � PEREPODACHA
     if (!st_developer) { // �� �����������
     if (pole_block == 1) {
     if (nom_fac != 4) {
     TookDocBtBtn1->Enabled = false; // ������ ������ ���������
     RestorlistBtBtn->Enabled = false; // ������ ������������ � ������
     // ���� - ������� �� ����� ���������� ����������
     // BitBtn5->Enabled = true; // ������ ����������
     // BitBtn7->Enabled = true; // ������ ������ ���������
     // BitBtn8->Enabled = true; // ������ ������������ � ������
     // BitBtn10->Enabled = false; // ������ ������
     // ����� ������� ��� ����������
     }
     ReInsideFacBtBtn->Enabled = true; // ������ ���������� ����������
     TookDocBtBtn2->Enabled = true; // ���������������� ��� ����������
     // if (nom_fac == 4) BitBtn10->Enabled = true;   // ��� ����������
     // else BitBtn10->Enabled = false;   // ��� ����������
     // ������ ������ ��������� ����� ��������� ������
     }
     else {
     TookDocBtBtn1->Enabled = true; // ������ ������ ���������
     RestorlistBtBtn->Enabled = true; // ������ ������������ � ������
     ReInsideFacBtBtn->Enabled = false; // ������ ���������� ����������
     TookDocBtBtn2->Enabled = false;
     // ������ ������ ��������� ����� ��������� ������
     }
     } // and �� ����������� */

    if (!TookDoc1Perm || st_developer)
        TookDocBtBtn1->Enabled = true;
    else
        TookDocBtBtn1->Enabled = false;

    if (!TookDoc2Perm || st_developer)
        TookDocBtBtn2->Enabled = true;
    else
        TookDocBtBtn2->Enabled = false;

    if (!ReInsideFacPerm || st_developer)
        ReInsideFacBtBtn->Enabled = true;
    else
        ReInsideFacBtBtn->Enabled = false;

    if (!RestorListPerm || st_developer)
        RestorlistBtBtn->Enabled = true;
    else
        RestorlistBtBtn->Enabled = false;
}

// ----------------------------------------------------------------------------
void __fastcall TAbiturForm::PoleBlock()                                        // ��������� �������� ���� BLOCK
{
    DM->BlockQ->Close();
    DM->BlockQ->ParamByName("fac")->AsInteger = nom_fac;
    DM->BlockQ->Open();

    pole_block = DM->BlockQBLOCK->Value;
    perepodacha = DM->BlockQPEREPODACHA->Value;
}

// ----------------------------------------------------------------------------
void __fastcall TAbiturForm::MsgEdit() { // ��������� ������� ��������� ������
    PoleBlock();
    // int pr = DM->QAbituraPRICE->Value;

    if (!st_developer & pole_block == 1) {
        ShowMessage("�������� ������ ���������! ���������� � ������������!");
        ExitBitBtn->SetFocus();

    }
    // else if (!st_developer & pole_block==1 & nom_fac==4 & pr!=0)
    // {}

} // end ��������� ������� ��������� ������

// ----------------------------------------------------------------------------
void __fastcall TAbiturForm::EnabledTrue()
{ // ����� ����������� ��� ��������� ������ (������� �� ���� � ��)
    /* PriceRdGrp->Enabled=true; //����� ����� ������
     KonkursRdGrp->Enabled=true; //�������
     BitBtn7->Enabled=true;     //������ ������ ���������
     BitBtn8->Enabled=true;     //������ ������������ � ������
     BitBtn5->Enabled=true;    //������ ���������� ����������
     BitBtn10->Enabled=true;   //������ ������ ��������� ����� ��������� ������

     ComboBox2->Enabled=true;   //�����������
     //��� ���������� �����������
     Ch4->Enabled=true;
     Ch5->Enabled=true;
     //���������
     Ch3->Enabled=true;
     Ch6->Enabled=true;
     Ch7->Enabled=true;
     Ch8->Enabled=true;
     Ch9->Enabled=true;

     DBEdit23->Enabled=true; //������� ����
     SpeedButton1->Enabled=true; //������ �������� �����
     DBGrid3->Enabled=true;      //�����������
     //��� �������� (�������� �������������� ��������)
     Vk1->Enabled=true;
     Vk2->Enabled=true;
     Vk3->Enabled=true;
     Vk4->Enabled=true;
     Vk5->Enabled=true;
     Vk6->Enabled=true;
     //��� ���������(�������� �������������� ��������)
     Wo1->Enabled=true;
     Wo2->Enabled=true;
     Wo3->Enabled=true;
     Wo4->Enabled=true;
     Wo5->Enabled=true; */
} // end ����� ����������� ��� ��������� ������ �� �����������

// ----------------------------------------------------------------------------
void __fastcall TAbiturForm::EnableDate ()
{ // ����� ����������� ��� ������������ ������
    // ----
    // ������ ������������ �� ����
    // ��������� ������� ���� �������
    // -----------------------------
    // DMVed->QDate->Close();
    // DMVed->QDate->Open();
    // DateServer=DMVed->QDateCAST->Value.DateTimeString(); //�������� ���� � �������
    // dateOkonch = "26.07.2010";
    // ----

    // PoleBlock();
    /* DM->BlockQ->Close();
     DM->BlockQ->ParamByName("fac")->AsInteger=nom_fac;
     DM->BlockQ->Open();

     int pole_block = DM->BlockQBLOCK->Value; */

    /* if (!st_developer | !st_asu &  pole_block==1)
     {//if ������������ �� ����������� � ���� BLOCK=1 � ��
     //if (DateServer==dateOkonch & mess==false)
     if (mess==false)
     {
     ShowMessage("��������! � "+DateServer+" �������� �������� ��������� ����������!");
     //ShowMessage("��������! � ������������ ��� �������� �������� ��������� ����������!");
     mess=true;
     }

     //������ ���������!!!
     PriceRdGrp->Enabled=false; //����� ����� ������
     KonkursRdGrp->Enabled=false; //�������

     if (!st_developer | !st_asu & nom_fac!=4)
     {
     BitBtn7->Enabled=false;     //������ ������ ���������
     BitBtn8->Enabled=false;     //������ ������������ � ������
     }



     //if (nom_fac!=4)
     //{
     if (!st_developer | !st_asu)
     {
     BitBtn5->Enabled=true;      //������ ���������� ����������
     BitBtn10->Enabled=true;   //������ ������ ��������� ����� ��������� ������
     }
     //} */
    // -----------

    // if (/*!st_developer */ !st_asu)
    // {//if ������������ �� �����������
    // BitBtn5->Enabled=false;     //������ ���������� ����������
    // BitBtn10->Enabled=false;   //������ ������ ��������� ����� ��������� ������

    // if (pole_block==1)
    // {//if ���� BLOCK=1 � ��
    /* if (mess==false)
     {//if mess==false
     //ShowMessage("��������! � "+DateServer+" �������� �������� ��������� ����������!");
     //ShowMessage("��������! � ������������ ��� �������� �������� ��������� ����������!");
     ShowMessage("��������! �������� �������� ��������� ����������!");
     mess=true;
     }//end if mess==false

     if (nom_fac!=4)
     {
     BitBtn7->Enabled=false;     //������ ������ ���������
     BitBtn8->Enabled=false;     //������ ������������ � ������
     }
     else
     {
     BitBtn7->Enabled=true;     //������ ������ ���������
     BitBtn8->Enabled=true;     //������ ������������ � ������
     } */

    // ������ ���������!!!
    /* PriceRdGrp->Enabled=false; //����� ����� ������
     KonkursRdGrp->Enabled=false; //�������
     ComboBox2->Enabled=false;   //�����������
     //��� ���������� �����������
     Ch4->Enabled=false;
     Ch5->Enabled=false;
     //���������
     Ch3->Enabled=false;
     Ch6->Enabled=false;
     Ch7->Enabled=false;
     Ch8->Enabled=false;
     Ch9->Enabled=false;

     Ch3->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Ch4->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Ch5->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Ch6->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Ch7->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Ch8->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Ch9->Font->Style=TFontStyles()<< fsBold << fsUnderline;

     AveragScoreDBEdt->Enabled=false; //������� ����
     SpeedButton1->Enabled=false; //������ �������� �����
     DBGrid3->Enabled=false;      //�����������
     //��� �������� (�������� �������������� ��������)
     Vk1->Enabled=false;
     Vk2->Enabled=false;
     Vk3->Enabled=false;
     Vk4->Enabled=false;
     Vk5->Enabled=false;
     Vk6->Enabled=false;

     Vk1->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Vk2->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Vk3->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Vk4->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Vk5->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Vk6->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     //��� ���������(�������� �������������� ��������)
     Wo1->Enabled=false;
     Wo2->Enabled=false;
     Wo3->Enabled=false;
     Wo4->Enabled=false;
     Wo5->Enabled=false;
     }
     }//end if ������������ �� ����������� � block � �� �� 1
     else
     {
     EnabledTrue();
     } */
}


AnsiString __fastcall TAbiturForm::Chek_Vid_Edu ()                              // ������� ��� ������ ������������ ������ ������������� ���� ��������
{
    switch (RadioGroup1->ItemIndex)
    {
        case 2:                                                                 // ���
            return
                "";

        default:
            return
                " AND (VID_EDU="                    +
                    AnsiString (
                        RadioGroup1 -> ItemIndex
                    )                               +
                ") ";
    }
}
void __fastcall TAbiturForm::max_nom_dela ()                                    // !!! �������, ������� ���������� ������������ ����� ����
{
    // int temp;                                                                   // ������ ������������ ����� ����

    // DM -> QMax_Nom_Dela -> Close ();
    // DM -> QMax_Nom_Dela ->
    //    ParamByName ("N_FAC") -> AsInteger = nom_fac;
    // DM -> QMax_Nom_Dela -> Open ();

    // if (DM -> QMax_Nom_Dela -> RecordCount)                                    // ���� �� �����������
    //    temp = DM -> QMax_Nom_DelaMAX -> Value;
    // else                                                                       // ��� �� ������
    //    temp = 0;

    // return
    //     temp;                                                                   // ���������� ������������ ����� ����

    int i = 1;

    for ( int v = 0;
              v < 2;
              ++v
        )
    {
        for ( int t = 0;
                  t < 2;
                  ++t
            )
        {
            for (int p = 0;
                     p < 2;
                     ++p
                )
            {
                DM -> MaxNumDelaStrdPrc -> Close ();
                DM -> MaxNumDelaStrdPrc ->
                    ParamByName ("n_fac")    -> AsSmallInt = nom_fac;
                DM -> MaxNumDelaStrdPrc ->
                    ParamByName ("vid_edu")  -> AsSmallInt = v;
                DM -> MaxNumDelaStrdPrc ->
                    ParamByName ("term_edu") -> AsSmallInt = t;
                DM -> MaxNumDelaStrdPrc ->
                    ParamByName ("price")    -> AsSmallInt = p;

                DM -> MaxNumDelaStrdPrc -> Prepare ();
                DM -> MaxNumDelaStrdPrc -> ExecProc ();

                switch (i)
                {
                    case 1:
                            MainForm -> NumDelaLbl1 -> Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 2:
                            MainForm -> NumDelaLbl2 -> Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 3:
                            MainForm -> NumDelaLbl3->Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 4:
                            MainForm -> NumDelaLbl4->Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 5:
                            MainForm -> NumDelaLbl5 -> Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 6:
                            MainForm -> NumDelaLbl6 -> Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 7:
                            MainForm -> NumDelaLbl7 -> Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 8:
                            MainForm -> NumDelaLbl8 -> Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                }

                ++i;
            }
        }
    }
}

// ---------------------------------------------------------------------------
/* int __fastcall TAbiturForm::langv_ball(int ind, int fl)
 { // �������, ������� ���������� ������ �� ������������ �����, � ����������� ��  fl
 // ind - �������� ��� ���� ��� ItemIndex
 // fl - 0 ��������� ������ � ComboBox , 1 - �������� ���� � ������ ������ � ��������

 int rez; // ���������� ����������

 if (fl) {
 // if �������  ����� � ������ ������ � �������� (�������� LangRatCmbBx->ItemIndex)
 switch (ind) { // switch  �������� ������ � LangRatCmbBx
 case -1:
 rez = 0; // �� ������� ������
 break;
 case 10:
 rez = 5; // ���
 break;
 case 11:
 rez = 4; // ���
 break;
 case 12:
 rez = 3; // �����
 break;
 case 13:
 rez = 7; // �� ������, � � �������� ����������
 break;
 default:
 rez = 20 - LangRatCmbBx->ItemIndex;
 // ���������� ���� ��� ������������� �������
 break;
 } // end switch  �������� ������ � LangRatCmbBx
 } // end if �������  ����� � ������ ������ � �������� (�������� LangRatCmbBx->ItemIndex)
 else { // else �������  ������� � ComboBox (�������� ����������� ������)
 switch (ind) { // switch  �������� ������
 case 0:
 rez = -1; // ��� ������� ������
 break;
 case 5:
 rez = 10; // ���
 break;
 case 4:
 rez = 11; // ���
 break;
 case 3:
 rez = 12; // �����
 break;
 case 7:
 rez = 13; // �� ������, � � �������� ����������
 break;
 default:
 rez = 20 - ind; // ���������� ������ ��� ������������� �������
 break;
 } // end switch �������� ������ */

// } // end else �������  ������� � ComboBox (�������� ����������� ������)

// return rez;
/* ItemIndex    Ball
 10         0           20
 9          1           19
 8          2           18
 7          3           17
 6          4           16
 5          5           15
 4          6           14
 3          7           13
 2          8           12
 1          9           11
 ���        10          5
 ���        11          4
 �����      12          3
 �� ������  13          7
 */
// }         */



// void __fastcall ClearCheck (TRxCheckListBox * cList)                            // �������, ������� ��������� ���  Check
// {
//     int i;
//     for (int i =  0;
//              i < cList -> Items -> Count;
//              ++i
//         )
//         cList -> State[i] = cbUnchecked;
// }
void __fastcall TAbiturForm::UncheckCh ()                                       // !!! �������, ������� ��������� ��� Check
{
    // Ch3 -> Checked = false;                                                  // �����
    // Ch4 -> Checked = false;
    // Ch5 -> Checked = false;
    // Ch6 -> Checked = false;
    // Ch7 -> Checked = false;
    // Ch8 -> Checked = false;
    // Ch9 -> Checked = false;

    TownVillageCmbBx -> ItemIndex = -1;
    SchoolCmbBx      -> ItemIndex = -1;

    CheckBox1 -> Checked = false;
    Panel5    -> Visible = false;

    ComboBox1        -> ItemIndex = -1;
    ComboBox2        -> ItemIndex = -1;

    DM -> WithoutCntQr -> Close ();                                             // ����� ������ ���������� (���)
    DM -> WithoutCntQr -> Open ();
    int WithoutCnt =
        DM -> WithoutCntQrCOUNT -> Value;
    DM -> WithoutCntQr -> Close ();

    TComboBox * EditlnstanceCB;

    for (int i = 0;
             i < WithoutCnt;
             ++i
        )
    {
        EditlnstanceCB =
            (TComboBox *)
                FindComponent (
                        "WithOutCmboBx"
                    +   IntToStr (
                            i + 1
                        )
                );
        EditlnstanceCB -> ItemIndex = 0;
    }

    DM -> OutCntQr -> Close();                                                  // ����� ������ ���������� (��)
    DM -> OutCntQr -> Open();
    int OutCnt =
        DM -> OutCntQrCOUNT -> Value;
    DM -> OutCntQr -> Close ();

    for (int i = 0;
             i < OutCnt;
             ++i
        )
    {
        EditlnstanceCB =
            (TComboBox *)
                FindComponent (
                        "OutCmboBx"
                    +   IntToStr (
                            i + 1
                        )
                );
        EditlnstanceCB->ItemIndex = 0;
    }

    InfChekLstBx ->                                                             // �������������� ����������
        CheckAll (
            cbUnchecked,
            true,
            true
        );
}
int __fastcall TAbiturForm::NewWo ()                                            // ������ � �� ������ ����������
{
    int ret_val = 0;

    DM -> PrivDelStrdPrc ->                                                     // ������� ��� ���������� ������� �����������
        ParamByName ("NOMER_AB") -> AsInteger =
            DM -> QAbituraNOMER_AB -> AsInteger;

    DM -> PrivDelStrdPrc -> Prepare ();
    DM -> PrivDelStrdPrc -> ExecProc ();

    DM -> WithoutCntQr -> Close ();                                             // �������� ����� ��� ����� ���������
    DM -> WithoutCntQr -> Open ();
    int WithoutCnt =
        DM -> WithoutCntQrCOUNT -> Value;
    DM -> WithoutCntQr -> Close ();

    TComboBox * EditlnstanceCB;

    int j = 0;

    for (int i = 1;
             i <= WithoutCnt;
             ++i
        )
    {
        EditlnstanceCB =
            (TComboBox *)
                FindComponent (
                        "WithOutCmboBx"
                    +   IntToStr (i)
                );
        if (EditlnstanceCB -> ItemIndex > 0)
        {
            j = 1;

            DM -> PrivInsStrdPrc ->
                ParamByName ("NOMER_AB") -> AsInteger =
                    DM -> QAbituraNOMER_AB -> AsInteger;
            DM -> PrivInsStrdPrc ->
                ParamByName ("N_PRIV")   -> AsSmallInt = 0;                     // ���
            DM -> PrivInsStrdPrc ->
                ParamByName ("SEL_PRIV") -> AsSmallInt = i;
            DM -> PrivInsStrdPrc ->
                ParamByName ("DAT_PRIV") -> AsSmallInt =
                    EditlnstanceCB -> ItemIndex;

            DM -> PrivInsStrdPrc -> Prepare ();
            DM -> PrivInsStrdPrc -> ExecProc ();
        }
    }

    if (    KonkursCmbBx -> ItemIndex == 1
         && j                         == 0
       )
        ret_val = 1;

	if (    (    TermEduCmbBx -> ItemIndex == 1
              || TermEduCmbBx -> ItemIndex == 2
            )
         && (    EducatCmbBx  -> ItemIndex == 2
              || EducatCmbBx  -> ItemIndex == 3
            )
       )
        ret_val = 0;

    if (ret_val)
        return
            1;

    DM -> OutCntQr -> Close ();                                                 // �������� ����� �� ����� ���������
    DM -> OutCntQr -> Open ();
    WithoutCnt =
        DM -> OutCntQrCOUNT -> Value;
    DM -> OutCntQr -> Close ();

    j = 0;

    for (int i =  1;
             i <= WithoutCnt;
             ++i
        )
    {
        EditlnstanceCB =
            (TComboBox *)
                FindComponent (
                        "OutCmboBx"
                    +   IntToStr (i)
                );

        if (EditlnstanceCB -> ItemIndex > 0)
        {
            j = 1;

            DM -> PrivInsStrdPrc ->
                ParamByName ("NOMER_AB") -> AsInteger =
                    DM -> QAbituraNOMER_AB -> AsInteger;
            DM -> PrivInsStrdPrc ->
                ParamByName ("N_PRIV")   -> AsSmallInt = 1;                     // ��
            DM -> PrivInsStrdPrc ->
                ParamByName ("SEL_PRIV") -> AsSmallInt = i;
            DM -> PrivInsStrdPrc ->
                ParamByName ("DAT_PRIV") -> AsSmallInt =
                    EditlnstanceCB -> ItemIndex;

            DM -> PrivInsStrdPrc -> Prepare ();
            DM -> PrivInsStrdPrc -> ExecProc ();
        }
    }
    if (    KonkursCmbBx->ItemIndex == 2
         && j                       == 0
       )
        return
            2;


    DM -> InfCntQr -> Close ();                                                 // �������� ����� ������������ ����� ���������
    DM -> InfCntQr -> Open ();
    WithoutCnt =
        DM -> InfCntQrCOUNT -> Value;
    DM -> InfCntQr -> Close ();

    for (int i = 0;
             i < WithoutCnt;
             ++i
        )
    {
        if (InfChekLstBx -> Checked[i])
        {
            DM -> PrivInsStrdPrc ->
                ParamByName ("NOMER_AB") -> AsInteger =
                    DM -> QAbituraNOMER_AB -> AsInteger;
            DM -> PrivInsStrdPrc ->
                ParamByName ("N_PRIV")   -> AsSmallInt = 2;                     // ������
            DM -> PrivInsStrdPrc ->
                ParamByName ("SEL_PRIV") -> AsSmallInt = i + 1;
            DM -> PrivInsStrdPrc ->
                ParamByName ("DAT_PRIV") -> AsSmallInt =
                    InfChekLstBx -> Checked[i];

            DM -> PrivInsStrdPrc -> Prepare ();
            DM -> PrivInsStrdPrc -> ExecProc ();
        }
    }

    return
        0;
}
void __fastcall TAbiturForm::RefreshCh ()                                       // �������, ������� ������������� ��� Check � ������ ��������� (���������� �������������� ����������)
{
    TownVillageCmbBx -> ItemIndex =                                             // ���������� �����/����
        DM -> QAbituraTOWN_VILLAGE -> Value;
    // AnsiString Stat_ab = DM -> QAbituraSTAT_AB -> Value;
    SchoolCmbBx      -> ItemIndex =
        DM -> QAbituraTYPE_SCHOOL  -> Value;                                    // ��� �����

    if (DM -> QAbituraDISABLED -> Value > 0)                                    // ������������
    {
        Panel5    -> Visible = true;
        CheckBox1 -> Checked = true;

        if (DM -> QAbituraDISABLED -> Value % 3)
        {
            ComboBox2 -> ItemIndex =
                  DM -> QAbituraDISABLED -> Value
                % 3
                - 1;
            ComboBox1 -> ItemIndex =
                (   DM -> QAbituraDISABLED -> Value
                  - DM -> QAbituraDISABLED -> Value
                  % 3
                ) / 3;
        }
        else
        {
            ComboBox2 -> ItemIndex = 2;
            ComboBox1 -> ItemIndex =
                (   DM -> QAbituraDISABLED -> Value
                  - 3
                ) / 3;
        }
    }
    else
    {
        Panel5    -> Visible = false;
        CheckBox1 -> Checked = false;

        ComboBox1 -> ItemIndex = -1;
        ComboBox2 -> ItemIndex = -1;
    }

    TComboBox * EditlnstanceCB;                                                 // ���������� ���

    DM -> PrivQr -> Close ();
    DM -> PrivQr ->
        ParamByName ("nomer_ab") -> AsInteger =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> PrivQr ->
        ParamByName ("n_priv")   -> AsInteger = 0;                              // ���
    DM -> PrivQr -> Open ();

    while (!DM -> PrivQr -> Eof)
    {
        EditlnstanceCB =
            (TComboBox *)
                FindComponent (
                        "WithOutCmboBx"
                    +   IntToStr (
                            DM -> PrivQrSEL_PRIV -> Value
                        )
                );
        EditlnstanceCB -> ItemIndex =
            DM -> PrivQrDAT_PRIV -> Value;

        DM -> PrivQr -> Next ();
    }
    DM -> PrivQr -> Close();


    DM -> PrivQr -> Close ();                                                   // ���������� ��� ��������
    DM -> PrivQr ->
        ParamByName ("nomer_ab") -> AsInteger =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> PrivQr ->
        ParamByName ("n_priv")   -> AsInteger = 1;                              // ��
    DM -> PrivQr -> Open ();

    while (!DM -> PrivQr -> Eof)
    {
        EditlnstanceCB =
            (TComboBox *)
                FindComponent (
                        "OutCmboBx"
                    +   IntToStr (
                            DM -> PrivQrSEL_PRIV -> Value
                        )
                );
        EditlnstanceCB -> ItemIndex =
            DM -> PrivQrDAT_PRIV -> Value;

        DM -> PrivQr->Next();
    }
    DM -> PrivQr -> Close ();


    DM -> PrivQr -> Close();                                                    // ������������ ��� ����������
    DM -> PrivQr -> ParamByName ("nomer_ab") -> AsInteger =
        DM -> QAbituraNOMER_AB -> Value;
    DM -> PrivQr -> ParamByName ("n_priv")   -> AsInteger = 2;                  // ������
    DM -> PrivQr -> Open ();

    while (!DM -> PrivQr -> Eof)
    {
        InfChekLstBx -> Checked[DM -> PrivQrSEL_PRIV -> Value - 1] =
            DM -> PrivQrDAT_PRIV -> Value;

        DM -> PrivQr -> Next ();
    }
    DM -> PrivQr -> Close ();
}
void __fastcall TAbiturForm::RefreshControl ()                                  // ������� ������������� ������ �� ���� � ������������ ����������� � ������ ��������
{
    FormEduCmbBx -> Clear ();
    FormEduCmbBx -> Items -> Add ("�������");
    FormEduCmbBx -> Items -> Add ("�������");

    // if (!DM -> QAbitura -> RecordCount)                                         // �������2019
    // {
    //     // FormEduCmbBx -> ItemIndex = -1;

    //     LangRatCmbBx -> ItemIndex = -1;                                         // ���� �� ������������ �����

    //     return
    //         ShowMessage (
    //             "��� ���������� ������������, "        \
    //             "�� �������� ������ ������ ��������!"
    //         );
    // }

    UncheckCh ();                                                               // UPDATE (���������� ���� Check)
    RefreshCh ();                                                               // UPDATE (������������� ���� Check)

    FormEduCmbBx -> ItemIndex = DM -> QAbituraVID_EDU -> Value;                 // ��������� ��������� �������� ���� ��������

    if (ChangLog == -1)
        FormEduCmbBx -> Enabled = false;
    else
        FormEduCmbBx -> Enabled = true;

    // OldKonkursVal.FormEduIndex =
    //     FormEduCmbBx -> ItemIndex;

    DM -> QSpecializPlan_Priem -> Close ();                                     // ����������� �������������
    DM -> QSpecializPlan_Priem ->
        ParamByName ("VID_EDU") -> AsSmallInt =
            DM -> QAbituraVID_EDU -> Value;
    DM -> QSpecializPlan_Priem ->
        ParamByName ("FAC") -> AsSmallInt = nom_fac;
    DM -> QSpecializPlan_Priem -> Open ();

    if (ChangLog == -1)
        SpecializDBLookupCmbBx->Enabled = false;
    else
        SpecializDBLookupCmbBx->Enabled = true;

    // OldKonkursVal.SpecializDBLookupIndex =
    //     SpecializDBLookupCmbBx -> KeyValue;

    CategoryAbCmbBx -> ItemIndex =                                              // ��������� �����������
        DM -> QAbituraCATEGORY_AB -> Value;

    if (ChangLog == -1)
        CategoryAbCmbBx -> Enabled = false;
    else
        CategoryAbCmbBx -> Enabled = true;

    // OldKonkursVal.CategoryAbIndex =
    //     SngFrgCmbBx -> ItemIndex;

    SngFrgCmbBx -> ItemIndex =
        DM -> QAbituraCATEGORY_IF -> Value;

    if (ChangLog == -1)
        SngFrgCmbBx -> Enabled = false;
    else
        SngFrgCmbBx -> Enabled = true;

    // OldKonkursVal.SngFrgIndex =
    //     SngFrgCmbBx -> ItemIndex;

    if (CategoryAbCmbBx -> ItemIndex == 0)
    {
        SngFrgLbl   -> Visible = false;
        SngFrgCmbBx -> Visible = false;
    }
    else
    {
        SngFrgLbl   -> Visible = true;
        SngFrgCmbBx -> Visible = true;
    }

    EducatCmbBx -> ItemIndex =                                                  // ����������� � �������
        DM -> QAbituraEDUCATION -> Value;

    if (ChangLog == -1)
        EducatCmbBx -> Enabled = false;
    else
        EducatCmbBx -> Enabled = true;

    OldKonkursVal.EducatIndex =
        EducatCmbBx -> ItemIndex;

	KonkursCmbBx -> ItemIndex =
        DM -> QAbituraKONKURS -> Value;

    if (ChangLog == -1)
		KonkursCmbBx -> Enabled = true;
    else
		KonkursCmbBx -> Enabled = true;

    if (KonkursCmbBx -> ItemIndex == 3)
    {
        CkRegionDBLkpCmbBx -> Visible = true;
        CkRegionDBLkpCmbBx -> Enabled = true;

        Label29 -> Visible = true;
    }

    // OldKonkursVal.KonkursIndex =
    //     KonkursCmbBx -> ItemIndex;

    PriceCmbBx -> ItemIndex =                                                   // ����� ������
        DM -> QAbituraPRICE -> Value;

    if (ChangLog == -1)
        PriceCmbBx -> Enabled = false;
    else
        PriceCmbBx -> Enabled = true;

    // OldKonkursVal.PriceIndex =
    //     PriceCmbBx -> ItemIndex;

    if (    DM->QAbituraEDUCATION->Value == 2                                  // ���� �������� / ���� �����������
         || DM->QAbituraEDUCATION->Value == 3
       )
        TermEduCmbBx -> ItemIndex =
            DM -> QAbituraTERM_EDU -> Value - 3;
    else
        TermEduCmbBx -> ItemIndex =
            DM -> QAbituraTERM_EDU -> Value;

    if (ChangLog == -1)
        TermEduCmbBx -> Enabled = false;
    else
        TermEduCmbBx -> Enabled = true;

    // OldKonkursVal.TermEduIndex =
    //     TermEduCmbBx -> ItemIndex;

    DM -> CountryQr      -> Close ();                                           // �����������
    DM -> CountryQr      -> Open ();


    DM -> QPersonalDocum -> Close ();                                           // ��������
    DM -> QPersonalDocum -> Open ();


    NomGroupCmbBx -> Clear ();                                                  // ����� ������ �����������
    NomGroupCmbBx -> Items ->
        Add (
            DM -> QAbituraNOM_GROUP -> Value
        );
    NomGroupCmbBx -> ItemIndex = 0;


    if (KonkursCmbBx -> ItemIndex == 3)                                         // �������� (������ QCk)
    {
        Label29            -> Visible = true;
        CkRegionDBLkpCmbBx -> Visible = true;

        DM -> CkRegionQr -> Close ();
        DM -> CkRegionQr -> Open ();
    }
    else
    {
        Label29            -> Visible = false;
        CkRegionDBLkpCmbBx -> Visible = false;
    }


    AdressRegEdt -> Text =                                                      // ����� �����������
        DM -> QAbituraADDRESS_BEFORE -> Value;
    AdressLifeEdt -> Text =                                                     // ����� ����������
        DM -> QAbituraADDRESS_LIFE -> Value;

    DM -> QAdress -> Close ();
    DM -> QAdress ->
        ParamByName ("ID") -> AsInteger =
            DM -> QAbituraSTREET -> Value;
    DM -> QAdress -> Active = true;


    // if (!DM -> QAbituraSTREET -> IsNull)
    // {
    //     DM -> QDistrict -> Close ();
    //     DM -> QDistrict ->
    //         ParamByName ("REGION") -> AsInteger =
    //             DM -> QAdressN_REGION -> Value;
    //     DM -> QDistrict -> Open ();


    //     DM -> QType_locality -> Close ();
    //     DM -> QType_locality -> Open ();


    //     DM -> QLocality -> Close ();
    //     if (    DistrictDBLkCmbBx      -> KeyValue
    //          && Type_localityDBLkCmbBx -> KeyValue
    //        )
    //     {
    //         DM -> QLocality ->
    //             ParamByName ("DISTRICT") -> AsInteger =
    //                 DM -> QAdressN_DISTRICT ->Value;
    //         DM -> QLocality ->
    //             ParamByName ("N_TYPE")   -> AsInteger =
    //                 DM -> QAdressN_TYPE     -> Value;
    //         DM -> QLocality -> Open ();
    //     }

    //     DM -> QType_street -> Close ();
    //     DM -> QType_street -> Open ();

    //     DM -> QStreet -> Close ();
    //     DM -> QStreet ->
    //         ParamByName ("TYPE_STREET") -> AsInteger =
    //             DM -> QAdressTYPE_STREET -> Value;
    //     DM -> QStreet ->
    //         ParamByName ("ID_LOCALITY") -> AsInteger =
    //             DM -> QAdressLOCAL_ID    ->Value;
    //     DM -> QStreet -> Open ();
    // }

    // DM -> QRegion_Center -> Close();                                         // �����
    // DM -> QRegion_Center ->
    //    ParamByName ("REGION") -> AsInteger =
    //        DM -> QAbituraN_REGION -> Value;
    // DM -> QRegion_Center -> Open ();


    // LangRatCmbBx -> ItemIndex =                                              // ���� �� ������������ �����
    //     langv_ball (
    //         DM -> QAbituraLANGV_BALL -> Value,
    //         0
    //     );


    DM -> QSertificat -> Close ();                                              // ����������� �����������
    DM -> QSertificat ->
        ParamByName ("NOMER") -> AsInteger =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> QSertificat -> Open ();


    DM -> QEducation -> Close ();                                               // ����������� �����������
    DM -> QEducation ->
        ParamByName ("NOMER") -> AsInteger =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> QEducation -> Open ();
    DM -> TEduDoc -> Close ();
    DM -> TEduDoc -> Open ();

    DM -> QFotoSign -> Close ();                                                // ����
    DM -> QFotoSign ->
        ParamByName ("N_AB")  -> AsInteger =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> QFotoSign ->
        ParamByName ("N_FAC") -> AsInteger =
            DM -> QAbituraN_FAC    -> Value;
    DM -> QFotoSign -> Open ();

    Variant photo =
        & (DM -> QFotoSignPHOTO -> Value);

    if (!DM -> QFotoSignPHOTO -> IsNull)
    {
        pms    -> Clear ();

        DM -> QFotoSignPHOTO -> SaveToStream (pms);

        pms    -> Position = 0;
        jp     -> LoadFromStream (pms);
        Image1 -> Picture -> Assign (jp);
    }
    else
    {
        Image1 -> Picture = NULL;

        TMemoryStream    * pms;                                                 // ������� ����
        Jpeg::TJPEGImage * jp;

        if (!(TBlobField*)DM->FIOSearchQrPHOTO->IsNull)
        {
            pms = new TMemoryStream;
            jp  = new TJPEGImage;

            DM -> FIOSearchQrPHOTO -> SaveToStream (pms);

            pms ->
                Seek (
                    0,
                    0
                );

            Image1 -> Picture -> Graphic = jp;
            Image1 -> Picture -> Graphic -> LoadFromStream (pms);

            Image1 -> Visible = True;

            delete pms;
            delete jp;

            if (    Image1 -> Picture -> Width  == 0
                 || Image1 -> Picture -> Height == 0
               )
                Image1 -> Picture = NULL;
        }
        else
            Image1 -> Picture = NULL;
    }
    // DM -> QAbitura -> Cancel ();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::FormClose(TObject *Sender, TCloseAction &Action)
{ // �������� �����

    if (DM->QAbitura->State != dsBrowse) { // if  !=dsBrowse
        // int fl=Application->MessageBox("    ��������� ��������� � ������ �������� �����������?", "", MB_YESNOCANCEL);
        AnsiString ansi_string1 =
            "    ��������� ��������� � ������ �������� �����������?";
        // ���� ������
        wchar_t * UnicodeString1 = new wchar_t[ansi_string1.WideCharBufSize()];
        // ������-����������
        ansi_string1.WideChar(UnicodeString1, ansi_string1.WideCharBufSize());
        ansi_string1 = ""; // ���� ������
        wchar_t * UnicodeString2 = new wchar_t[ansi_string1.WideCharBufSize()];
        // ������-����������
        ansi_string1.WideChar(UnicodeString2, ansi_string1.WideCharBufSize());
        int fl = Application->MessageBox(UnicodeString1, UnicodeString2,
            MB_YESNOCANCEL);
        delete[]UnicodeString1;
        delete[]UnicodeString2;

        if (fl == 6) { // if fl==6  -yes   ��������� ������ � ��������� �����
            // �������� ��� �������� ���� ����� ���������� ������ ��������
            // if (st_ins)
            // {
            // BitBtn1Click(this);
            // }//end �������� ��� �������� ���� ����� ���������� ������ �������� *

            SaveBtBtnClick(this); // ???? ��������������!!!

            DM->QAbitura->ApplyUpdates();
            DM->QAbitura->CommitUpdates();
            delete pms;
            delete jp;
            DM->QLangvich->Close();
            // Action = caFree;
        } // end if fl==6  -yes   ��������� ������ � ��������� �����
        else if (fl == 7)
        { // if  fl== 7  - no �������� ��������� � ��������� �����
            DM->QAbitura->CancelUpdates();
            delete pms;
            delete jp;
            DM->QLangvich->Close();
            // Action = caFree;
        } // end if  fl== 7  - no �������� ��������� � ��������� �����
        else { // else   cancel   - �� ��������� �����
            // Action = caNone;
        } // end else   cancel   - �� ��������� �����
    } // end if != dsBrowse
    else { // else Browse
        // if(Application->MessageBox("    ������� ����� �� �����������?", "", MB_YESNO) == mrYes)
        AnsiString ansi_string1 = "    ������� ����� �� �����������?";
        // ���� ������
        wchar_t * UnicodeString1 = new wchar_t[ansi_string1.WideCharBufSize()];
        // ������-����������
        ansi_string1.WideChar(UnicodeString1, ansi_string1.WideCharBufSize());
        ansi_string1 = ""; // ���� ������
        wchar_t * UnicodeString2 = new wchar_t[ansi_string1.WideCharBufSize()];
        // ������-����������
        ansi_string1.WideChar(UnicodeString2, ansi_string1.WideCharBufSize());
        /* if (Application->MessageBox(UnicodeString1, UnicodeString2,
         MB_YESNO) == mrYes)
         Action = caFree;
         else
         Action = caNone; */
        delete[]UnicodeString1;
        delete[]UnicodeString2;
    } // end else Browse   */
    // delete pms;
    // delete jp;

    // �������� ���
    /* if (st_ins)
     {
     Application->MessageBox("�� ���������� � ������ ���������� ������ �����������! ������� ������ ���� ��������� , ���� �������� ", "", MB_OK);
     Action = caNone;

     } */
}


void __fastcall TAbiturForm::TabSheet1Enter (TObject * Sender)                  // ������� �� �������� ������ ������
{
    // ExitBitBtn -> Enabled = false;
    // ExitBitBtn -> Visible = false;

    // SaveBtBtn   -> Enabled = false;
    // CancelBtBtn -> Enabled = false;
    // SaveBtBtn   -> Visible = false;
    // CancelBtBtn -> Visible = false;

    AbiturForm->Height = 700;
}

void __fastcall TAbiturForm::TabSheet2Enter (TObject * Sender)                  // ������� �� ��������  ������ ����
{
    //ExitBitBtn -> Enabled = true;
    //ExitBitBtn -> Visible = true;

    // SaveBtBtn   -> Enabled = true;
    // CancelBtBtn -> Enabled = true;
    // SaveBtBtn   -> Visible = true;
    // CancelBtBtn -> Visible = true;

    if (DM -> QAbitura -> State != dsInsert)
        RefreshControl ();

    ActionList1 -> State = asNormal;

    if (! st_developer & pole_block == 1)                                       // �������� ��������� ����� ������ ����������
		KonkursCmbBx -> Enabled = true;

    // EnableDate();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TabSheet3Enter(TObject *Sender)
{ // ������� �� �������� �������������� ��������
    /* ExitBitBtn->Enabled=true;
     ExitBitBtn->Visible=true; */
    /* SaveBtBtn->Enabled = true;
     CancelBtBtn->Enabled = true;
     SaveBtBtn->Visible = true;
     CancelBtBtn->Visible = true;
     PrintBtBtn->Visible = true; */
    if (DM->QAbitura->State != dsInsert)
        RefreshControl();
    // EnableDate();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TabSheet1Show (TObject * Sender)                   // ����� �������� ������ ������
{
    Edit1 -> SetFocus();

    ActionList1 -> State = asSuspended;
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TabSheet3Show (TObject * Sender)                   // ����� ��������  �������������� ��������
{
    /* SaveBtBtn->Enabled = true;
     CancelBtBtn->Enabled = true;
     SaveBtBtn->Visible = true;
     CancelBtBtn->Visible = true;
     PrintBtBtn->Visible = true; */
    WorkBeforeDBEdt -> SetFocus();

    ActionList1 -> State = asSuspended;
}


void __fastcall TAbiturForm::ExitBitBtnClick (TObject * Sender)                  // ������ �����
{
    this -> Close ();
}


void __fastcall TAbiturForm::SaveBtBtnClick (TObject * Sender)                  // ������   ���������
{
    if (DM -> QAbitura -> State != dsBrowse)
    {
        try
        {
            //------------------------------CONDITIONS----------------------------------------//
            #ifdef NEW_CHECKS
            if (    PriceCmbBx   -> ItemIndex == -1                             // Check chapter ENROLLMENT CONDITIONS
                 || KonkursCmbBx -> ItemIndex == -1
               )
            {
                return
                    ShowMessage (
                        "�� �� ������� ������� ��� ����� ������!!!"
                    );
            }
            #endif
            if (    PriceCmbBx   -> ItemIndex == -1                             // Check chapter ENROLLMENT CONDITIONS
                 || KonkursCmbBx -> ItemIndex == -1
               )
                return
                    ShowMessage (
                        "�� �� ������� ������� ��� ����� ������!!!"
                    );
            //-----------------------------END-CONDITIONS----------------------------------------//


            //-------------------------------ADDRESS----------------------------------------// Check chapter ADDRESS
            //------------------------------END-ADDRESS----------------------------------------//


            //-------------------------------PERSONAL_ID----------------------------------------//
            if (DocumDBLkCmbBx -> Text == "")                                   // Check document type
                return
                    ShowMessage (
                        "�� �� ������� �������� �������������� ��������!!!"
                    );

            AnsiString personal = PersonNumDBEdt -> Text;                       // read PERSONAL NUMBER

            if (    SitizenshipDBLkCmbBx -> KeyValue == 112                     // Check BELARUSSIAN
                 && personal.Length ()               != 14                      // Check length (14 characters)
                 //&& DocumDBLkCmbBx -> Text           != "�������������� �������"
                 && DocumDBLkCmbBx -> KeyValue       != 6                       // Check not a biometric passport
               )
                return
                    ShowMessage (
                        "������ ����� ���������� ���������� �������� " \
                        "������ ��������� 14 ��������!"
                    );
            //------------------------------END-PERSONAL_ID----------------------------------------//




           //------------------------------EDUCATION----------------------------------------//
            #ifndef ENROLLMENT_PEOPLE_WITHOUT_CERTIFICATES
            if (    AveragScoreDBEdt -> Text      == ""                         // �������� ������� ���� ��� ������������� SngFrgCmbBx
                 && SngFrgCmbBx      -> ItemIndex != 1
               )
                return
                    ShowMessage (
                        "�� �� ����� ������� ��� ���������!!!"
                    );
            if (LangvDBLkpCmbBx -> Text == "")                                  // �������� ����������� ����
                return
                    ShowMessage (
                        "�������� ����������� ����!"
                    );
            //#else
            //    AveragScoreDBEdt -> Text = "20";
            //    LangvDBLkpCmbBx  -> ItemIndex = 5;    // "����������"
            #endif
            //-----------------------------END-EDUCATION----------------------------------------//




            //#ifdef NEW_CHECKS
            //if (FormEduCmbBx -> Text == "")                                     // Check EDUCATION TYPE
            //    return
            //        ShowMessage (
            //            "������� ��� ��������!\n"  \
            //            "������ �� ���������!"
            //        );
            //#endif
            if (FormEduCmbBx -> Text != "")                                     // Check EDUCATION TYPE (0 - Intramural, 1 - extramural)
            {
                //#ifdef NEW_CHECKS
                //if (SpecializDBLookupCmbBx -> Text == "")                       // Check SPECIALITY
                //    return
                //        ShowMessage (
                //            "������� ����������� �������������!\n"  \
                //            "������ �� ���������!"
                //        );
                //#endif
                if (SpecializDBLookupCmbBx -> Text != "")                       // ����������� �������������
                {
                    //#ifdef NEW_CHECKS
                    //if (    CategoryAbCmbBx -> ItemIndex == -1                  // Check GROUP OF NATIONALITY
                    //     && SngFrgCmbBx     -> ItemIndex == -1                  // Check ENROLLMENT TYPE
                    //   )
                    //    return
                    //        ShowMessage (
                    //            "������� ��������� ����������� "    \
                    //            "��� ������� �����������!\n"        \
                    //            "������ �� ���������!"
                    //        );
                    //#endif
                    if (    CategoryAbCmbBx -> ItemIndex != -1                  // Check GROUP OF NATIONALITY (0 - RB, 1 - Foreign, 2 - CIS, 3 - LNR)
                         && SngFrgCmbBx     -> ItemIndex != -1                  // Check ENROLLMENT TYPE (0 - as RB, 1 - as Foreign)
                       )
                    {
                        int tmp_s =
                            DM -> QSpecializPlan_PriemN_SPEC_DIR -> Value;
                        //#ifdef NEW_CHECKS
                        //if (    tmp_s                     == 1                                      // ��� ������ � ������
                        //     && DM -> QAbituraCATEGORY_IF == 0
                        //     || (    tmp_s                                   != 1
                        //          && VidSportDBLookupCmbBx       -> KeyValue == 121
                        //          && VidSportDBLookupCmbBx       -> KeyValue == 33
                        //          && SportCategoryDBLookupCmboBx -> KeyValue == 12
                        //        )
                        //   )
                        //    return
                        //        ShowMessage (
                        //            "������� ��� ������ � ������!\n"    \
                        //            "������ �� ���������!"
                        //        );
                        //#endif
                        if (    tmp_s                     != 1                        // ��� ������ � ������
                             && DM -> QAbituraCATEGORY_IF != 0
                             || (    tmp_s                                   == 1
                                  && VidSportDBLookupCmbBx       -> KeyValue != 121
                                  && VidSportDBLookupCmbBx       -> KeyValue != 33
                                  && SportCategoryDBLookupCmboBx -> KeyValue != 12
                                )
                           )
                        {
                            // �� ���������� ������ ��� ���������� � ������
                            //#ifdef NEW_CHECKS
                            //if (SitizenshipDBLkCmbBx -> KeyValue == 0)            // �����������
                            //    return
                            //        ShowMessage (
                            //            "������� �����������!\n"    \
                            //            "������ �� ���������!"
                            //        );
                            //#endif  // NEW_CHECKS
                            if (SitizenshipDBLkCmbBx->KeyValue != 0)            // �����������
                            {
                                //#ifdef NEW_CHECKS
                                //if (RegionDBLookupCmbBx -> Text == "")            // ������
                                //    return
                                //        ShowMessage (
                                //        "������� ������!\n" \
                                //        "������ �� ���������!"
                                //    );
                                //#endif  // NEW_CHECKS
                                if (RegionDBLookupCmbBx -> Text != "")            // ������
                                {
                                    //#ifdef NEW_CHECKS
                                    //if (NomGroupCmbBx -> Text == "")              // Check GROUP NUMBER
                                    //    return
                                    //        ShowMessage (
                                    //            "������� ����� ������!\n"   \
                                    //            "������ �� ���������!"
                                    //        );
                                    //#endif  // NEW_CHECKS
                                    if (NomGroupCmbBx->Text != "")              // ����� ������
                                    {
                                        //#ifdef NEW_CHECKS
                                        //if (    FamDBEdt  -> Text == ""           // Check LAST  NAME
                                        //     || NameDBEdt -> Text == ""           // Check FIRST NAME
                                        //   )
                                        //#endif  // NEW_CHECKS
                                        if (    FamDBEdt  -> Text != ""           // Check LAST  NAME
                                             && NameDBEdt -> Text != ""           // Check FIRST NAME
                                           )
                                        {
                                            //#ifdef NEW_CHECKS
                                            //if (PolDBCmbBx -> Text == "")           // Check GENDER
                                            //    return
                                            //        ShowMessage (
                                            //            "������� ��� ��� ����� ��������!\n"     \
                                            //            "������ �� ���������!"
                                            //        );
                                            //#endif  // NEW_CHECKS
                                            if (PolDBCmbBx -> Text != "")           // Check GENDER
                                            {
                                                //#ifdef NEW_CHECKS
                                                //if (DM -> QAbituraDATE_R -> IsNull)    // D.O.B not NULL OR more than 01.01.1935 (is: > 12785) AND less than 01.01.1992 (is: < 35065)
                                                //    return
                                                //        ShowMessage (
                                                //            "������� ��������� ���� ��������!\n"    \
                                                //            "������ �� ���������!"
                                                //        );
                                                //#endif  // NEW_CHECKS
                                                if (!DM -> QAbituraDATE_R -> IsNull)    // D.O.B not NULL OR more than 01.01.1935 (is: > 12785) AND less than 01.01.1992 (is: < 35065)
                                                {
                                                    //#ifdef NEW_CHECKS
                                                    //if (    SngFrgCmbBx -> ItemIndex == -1  // �� ����������        // if �����
                                                    //     && SchoolCmbBx -> ItemIndex == 1   // � ������� �����
                                                    //     || SngFrgCmbBx -> ItemIndex != 1   // ��� ����������
                                                    //   )
                                                    //    return
                                                    //       ShowMessage (
                                                    //                "������� ���������!\n"  \
                                                    //                "������ �� ���������!"
                                                    //            );
                                                    //#endif  // NEW_CHECKS
                                                    if (    SngFrgCmbBx -> ItemIndex != -1  // Check ENROLLMENT TYPE (-1 - enmpty, 0 - as RB, 1 - as Foreign)
                                                         || SngFrgCmbBx -> ItemIndex == 1   // ��� ����������
                                                         && SchoolCmbBx -> ItemIndex != 1   // � ������� �����
                                                       )
                                                    {
                                                        //#ifdef NEW_CHECKS
                                                        //if (    SngFrgCmbBx      -> ItemIndex == -1 // �� ����������        // if �����/����
                                                        //     && TownVillageCmbBx -> ItemIndex != 0  // � ������ �����/����
                                                        //     || SngFrgCmbBx      -> ItemIndex != 1  // ��� ����������
                                                        //   )
                                                        //    return
                                                        //        ShowMessage (
                                                        //            "������� ���������� �����������!\n" \
                                                        //            "������ �� ���������!"
                                                        //        );
                                                        //#endif  // NEW_CHECKS
                                                        if (    SngFrgCmbBx      -> ItemIndex != -1 // �� ����������        // if �����/����
                                                             || SngFrgCmbBx      -> ItemIndex == 1  // ��� ����������
                                                             && TownVillageCmbBx -> ItemIndex == 0  // � ������ �����/����
                                                           )
                                                        {
                                                            //#ifdef NEW_CHECKS
                                                            //if (EducatCmbBx -> ItemIndex == -1)         // ������� �����������
                                                            //    return
                                                            //        ShowMessage (
                                                            //            "������� ���� ��������� �����������!\n"   \
                                                            //            "������ �� ���������!"
                                                            //        );
                                                            //#endif  // NEW_CHECKS
                                                            if (EducatCmbBx -> ItemIndex != -1)         // ������� �����������
                                                            {
                                                                //#ifdef NEW_CHECKS
                                                                //if (TermEduCmbBx -> ItemIndex == -1)    // ������ ���� ��������� �����������
                                                                //    return
                                                                //        ShowMessage (
                                                                //            "������� ���� ��������� �����������!\n"   \
                                                                //            "������ �� ���������!"
                                                                //        );
                                                                //#endif  // NEW_CHECKS
                                                                if (TermEduCmbBx -> ItemIndex != -1)    // ������ ���� ��������� �����������
                                                                {
                                                                    //#ifdef NEW_CHECKS
                                                                    //if (PriceCmbBx -> ItemIndex == -1)  // ������� ����� ������
                                                                    //    ShowMessage (
                                                                    //        "������� ����� ������!\n"   \
                                                                    //        "������ �� ���������!"
                                                                    //    );
                                                                    //#endif  // NEW_CHECKS
                                                                    if (PriceCmbBx -> ItemIndex != -1)  // ������� ����� ������
                                                                    {
                                                                        //#ifdef NEW_CHECKS
                                                                        //if (KonkursCmbBx -> ItemIndex == -1)                                        // ������ �������
                                                                        //    return
                                                                        //        ShowMessage (
                                                                        //            "������� �������!\n"    \
                                                                        //            "������ �� ���������!"
                                                                        //        );
                                                                        //#endif  // NEW_CHECKS
                                                                        if (KonkursCmbBx -> ItemIndex != -1)                                        // ������ �������
                                                                        {
                                                                            int nom_abit = DM -> QAbituraNOMER_AB -> Value;
                                                                            // if (DM -> QAbitura -> State == dsInsert)
                                                                            if (    ChangLog == 1                                                   // ����� ����������
                                                                                 || ChangLog == 2                                                   // ��� ��������� ��������
                                                                               )
                                                                            {
                                                                                DM -> QAbituraSTATUS -> Value = 0;                                  // ����� ����!

                                                                                DM -> MaxNumDelaStrdPrc ->
                                                                                    ParamByName ("n_fac")   -> AsSmallInt =
                                                                                        nom_fac;
                                                                                DM -> MaxNumDelaStrdPrc ->
                                                                                    ParamByName ("vid_edu") -> AsSmallInt =
                                                                                        FormEduCmbBx -> ItemIndex;

                                                                                if (    EducatCmbBx -> ItemIndex == 2
                                                                                     || EducatCmbBx -> ItemIndex == 3
                                                                                   )
                                                                                    DM -> MaxNumDelaStrdPrc ->
                                                                                        ParamByName ("term_edu") -> AsSmallInt =
                                                                                            TermEduCmbBx -> ItemIndex + 3;
                                                                                else
                                                                                    DM -> MaxNumDelaStrdPrc ->
                                                                                        ParamByName ("term_edu") -> AsSmallInt =
                                                                                            TermEduCmbBx -> ItemIndex;

                                                                                DM -> MaxNumDelaStrdPrc ->
                                                                                    ParamByName ("price") -> AsSmallInt =
                                                                                        PriceCmbBx -> ItemIndex;


                                                                                DM -> MaxNumDelaStrdPrc -> Prepare ();
                                                                                DM -> MaxNumDelaStrdPrc -> ExecProc ();


                                                                                if (DM -> MaxNumDelaStrdPrc ->
                                                                                        ParamByName ("MX_NUM_DELA") -> Value > 0
                                                                                   )
                                                                                    DM -> QAbituraNOM_DELA -> Value =
                                                                                        DM -> MaxNumDelaStrdPrc ->
                                                                                            ParamByName ("MX_NUM_DELA") -> Value + 1;
                                                                                else
                                                                                    DM -> QAbituraNOM_DELA -> Value = 1;

                                                                                DM -> QAbituraNOM_GROUP -> Value = NomGroupCmbBx -> Text;
                                                                            }

                                                                            // DM -> QAbituraN_SPEC         -> Value     = DM -> QSpecializN_SPEC                -> Value;
                                                                            DM -> QAbituraN_SPEC         -> Value     = DM -> QSpecializPlan_PriemN_SPEC      -> Value;
                                                                            DM -> QAbituraN_SPECIALIZ    -> Value     = DM -> QSpecializPlan_PriemN_SPECIALIZ -> Value;
                                                                            DM -> QAbituraCITIZENSHIP    -> Value     = DM -> CountryQrDIGITAL_CODE           -> Value;
                                                                            DM -> QAbituraID_TYPE        -> Value     = DM -> QPersonalDocumID_TYPE           -> Value;
                                                                            DM -> QAbituraN_FAC          -> Value     = nom_fac;
                                                                            DM -> QAbituraCATEGORY_AB    -> Value     = CategoryAbCmbBx  -> ItemIndex;
                                                                            DM -> QAbituraCATEGORY_IF    -> Value     = SngFrgCmbBx      -> ItemIndex;
                                                                            DM -> QAbituraVID_EDU        -> Value     = FormEduCmbBx     -> ItemIndex;
                                                                            DM -> QAbituraADDRESS_BEFORE -> Value     = AdressRegEdt     -> Text;       // ����� �����������
                                                                            DM -> QAbituraADDRESS_LIFE   -> Value     = AdressLifeEdt    -> Text;       // ����� ����������
                                                                            DM -> QAbituraTOWN_VILLAGE   -> AsInteger = TownVillageCmbBx -> ItemIndex;  // �����/����
                                                                            DM -> QAbituraTYPE_SCHOOL    -> AsInteger = SchoolCmbBx      -> ItemIndex;  // ��� �����
                                                                            DM -> QAbituraEDUCATION      -> Value     = EducatCmbBx      -> ItemIndex;
                                                                            DM -> QAbituraKONKURS        -> Value     = KonkursCmbBx     -> ItemIndex;
                                                                            DM -> QAbituraPRICE          -> Value     = PriceCmbBx->ItemIndex;


                                                                            int disabilityGroup    = ComboBox1 -> ItemIndex + 1;                        // ������������
                                                                            int disabilityCategory = ComboBox2 -> ItemIndex + 1;

                                                                            if (    disabilityGroup
                                                                                 || disabilityCategory
                                                                               )
                                                                                DM -> QAbituraDISABLED -> Value =
                                                                                      (disabilityGroup - 1) * 3
                                                                                    + disabilityCategory;
                                                                            else
                                                                                DM -> QAbituraDISABLED -> Value = 0;

                                                                            if (    EducatCmbBx -> ItemIndex == 2
                                                                                 || EducatCmbBx -> ItemIndex == 3
                                                                               )
                                                                                DM -> QAbituraTERM_EDU -> Value = TermEduCmbBx -> ItemIndex + 3;
                                                                            else
                                                                                DM -> QAbituraTERM_EDU -> Value = TermEduCmbBx -> ItemIndex;

                                                                            // #ifndef ENROLLMENT_PEOPLE_WITHOUT_CERTIFICATES
                                                                            // DM -> QAbituraLANGV_BALL -> Value =                                      // ���������� ����� �� ������������ �����
                                                                            //    langv_ball (
                                                                            //        LangRatCmbBx -> ItemIndex,
                                                                            //        1
                                                                            //    );
                                                                            // #endif


                                                                            if (KonkursCmbBx -> ItemIndex < 3)                  // check none of those who are the TARGETED
                                                                                DM  -> QAbituraN_CK  -> Value = -1;             // set (-1) in N_CK for people who are not a TARGETED

                                                                            int Pr_Priv = NewWo ();

                                                                            if (    Pr_Priv                   == 2              // check the reason for OUT OF CONTEST
                                                                                 && TermEduCmbBx -> ItemIndex != 0
                                                                                 && PriceCmbBx   -> ItemIndex != 1
                                                                                 && (    EducatCmbBx -> ItemIndex == 2
                                                                                      || EducatCmbBx -> ItemIndex == 3
                                                                                    )
                                                                               )
                                                                            {
                                                                                return
                                                                                    ShowMessage (
                                                                                        "�������� ���������, �� "  \
                                                                                        "�������� ���������� "      \
                                                                                        "��������� ��� ��������!"   \
                                                                                        "\n������ �� ���������!"
                                                                                    );
                                                                            }

                                                                            if (Pr_Priv == 1)                                   // check the reason for WITHOUT TEST
                                                                            {
                                                                                return
                                                                                    ShowMessage (
                                                                                        "�������� ���������, "      \
                                                                                        "�� �������� ���������� "   \
                                                                                        "��������� ��� ���������!"  \
                                                                                        "\n������ �� ���������!"
                                                                                    );
                                                                            }


                                                                            try
                                                                            {
                                                                                DM -> QAbitura  -> ApplyUpdates ();
                                                                                DM -> QAbitura  -> CommitUpdates ();

                                                                                DM -> QFotoSign -> Close ();

                                                                                TLocateOptions Flags;

                                                                                DM  -> QAbitura  ->
                                                                                    Locate (
                                                                                        "NOMER_AB",
                                                                                        nom_abit,
                                                                                        Flags
                                                                                    );

                                                                                DM -> QFotoSign -> ParamByName ("N_FAC") -> AsInteger =
                                                                                    DM -> QAbituraN_FAC    -> Value;
                                                                                DM -> QFotoSign -> ParamByName ("N_AB")  -> AsInteger =
                                                                                    DM -> QAbituraNOMER_AB -> Value;
                                                                                DM -> QFotoSign -> Open ();
                                                                                DM -> QFotoSign -> Edit ();

                                                                                pms -> Clear ();

                                                                                jp  -> Assign (Image1 -> Picture);
                                                                                jp  -> SaveToStream (pms);

                                                                                pms -> Position = 0;

                                                                                DM -> QFotoSignPHOTO -> LoadFromStream (pms);

                                                                                DM -> QFotoSign -> ApplyUpdates ();
                                                                                DM -> QFotoSign -> CommitUpdates ();

                                                                                // ChangLog - ������ � ������.
                                                                                // -1 - ��������� ���������
                                                                                // 0  - ��������� �� ������ ���
                                                                                // 1  - ��������� �������� � ������������� �����������
                                                                                // 2  - ����� ����������
                                                                                if (ChangLog < 1)                               // �������������� ���������
                                                                                {
                                                                                    DM -> LogLastQr -> Close ();                // ����� ������ � ��������� ��� // ��������� �� DATE_IN ������ ��� NOMER_AB

                                                                                    DM -> LogLastQr -> ParamByName ("nomer_ab") -> AsInteger =
                                                                                        DM -> QAbituraNOMER_AB -> AsInteger;
                                                                                    DM -> LogLastQr -> Open ();

                                                                                    if (    !DM -> LogLastQrID_LOG         -> IsNull
                                                                                         || DM  -> FIOSearchQrSTATUS_QUEUE -> Value == 304
                                                                                       )
                                                                                    {
                                                                                        DM -> AdresOutQr -> Close ();
                                                                                        DM -> AdresOutQr -> ParamByName ("id_log")         -> AsInteger =
                                                                                            DM -> LogLastQrID_LOG        -> AsInteger;
                                                                                        DM -> AdresOutQr -> ParamByName ("address_before") -> AsString  =
                                                                                            DM -> QAbituraADDRESS_BEFORE -> Value;
                                                                                        DM -> AdresOutQr -> Prepare ();
                                                                                        DM -> AdresOutQr -> ExecSQL ();
                                                                                        DM -> AdresOutQr -> Close ();
                                                                                    }
                                                                                    else
                                                                                        ShowMessage (
                                                                                            "������ � ������� ��� ������� " \
                                                                                            "� �������� ���������� �� "     \
                                                                                            "�������!"
                                                                                        );

                                                                                    DM -> LogLastQr -> Close ();
                                                                                }

                                                                                if (ChangLog == 1)                                                      // ��������� �������� � ������������� �����������
                                                                                {
                                                                                    DM -> LogLastQr -> Close ();
                                                                                    DM -> LogLastQr -> ParamByName ("nomer_ab") -> AsInteger =          // get NOMER_AB
                                                                                        DM -> QAbituraNOMER_AB -> AsInteger;
                                                                                    DM -> LogLastQr -> Open ();

                                                                                    if (    !DM -> LogLastQrID_LOG         -> IsNull
                                                                                         || DM  -> FIOSearchQrSTATUS_QUEUE -> Value == 304              // check state
                                                                                       )
                                                                                    {
                                                                                        DM -> UpDateOutQr -> Close ();
                                                                                        DM -> UpDateOutQr -> ParamByName ("id_log")   -> AsInteger  =  // ���� �������� ���������� DATE_OUT
                                                                                            DM -> LogLastQrID_LOG -> AsInteger;
                                                                                        DM -> UpDateOutQr -> ParamByName ("date_out") -> AsDateTime =  // ��������� �� DATE_IN
                                                                                            cur_d.CurrentDateTime ();


                                                                                        DM -> UpDateOutQr -> Prepare ();
                                                                                        DM -> UpDateOutQr -> ExecSQL ();

                                                                                        DM -> UpDateOutQr -> Close ();
                                                                                    }
                                                                                    else
                                                                                        ShowMessage (
                                                                                            "������ � ������� ��� ������� "     \
                                                                                            "� �������� ���������� �� �������!"
                                                                                        );

                                                                                    DM -> LogLastQr -> Close ();
                                                                                }

                                                                                if (    ChangLog == 1                                                   // ��������� �������� ��� ����� ����������
                                                                                     || ChangLog == 2
                                                                                   )
                                                                                {
                                                                                    DM -> AbiturLogInsQr -> Close ();                                                                                  // ������� ����� ������ � ���
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("nom_dela")       -> AsSmallInt = DM -> QAbituraNOM_DELA         -> Value;    // ����� ������� ���� NOM_DELA
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("nomer_ab")       -> AsInteger  = DM -> QAbituraNOMER_AB         -> Value;    // ����� ����������� NOMER_AB
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("date_in")        -> AsDateTime = cur_d.CurrentDateTime ();                   // ���� ����� - �������
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("vid_edu")        -> AsSmallInt = DM -> QAbituraVID_EDU          -> Value;    // ����� �������� VID_EDU
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("price")          -> AsSmallInt = DM -> QAbituraPRICE            -> Value;    // ����� ������ PRICE
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("term_edu")       -> AsSmallInt = DM -> QAbituraTERM_EDU         -> Value;    // ���� �������� TERM_EDU
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("address_before") -> AsString   = DM -> QAbituraADDRESS_BEFORE   -> Value;    // ����� ADDRESS_BEFORE
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("n_ck")           -> AsSmallInt = DM -> QAbituraN_CK             -> Value;    // ������� N_CK
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("n_specializ")    -> AsSmallInt = DM -> QAbituraN_SPECIALIZ      -> Value;    // ����������� ������������� N_SPECIALIZ
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("n_fac")          -> AsSmallInt = nom_fac;
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("konkurs")        -> AsSmallInt = DM -> QAbituraKONKURS          -> Value;
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("category")       -> AsSmallInt = DM -> QAbituraN_SPORT_CATEGORY -> Value;

                                                                                    DM -> AbiturLogInsQr -> Prepare ();
                                                                                    DM -> AbiturLogInsQr -> ExecSQL ();

                                                                                    DM -> AbiturLogInsQr -> Close ();


                                                                                    DM -> StatusQueueQr -> Close ();
                                                                                    DM -> StatusQueueQr -> ParamByName ("fam")          -> AsString   = DM -> QAbituraFAM         -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("name")         -> AsString   = DM -> QAbituraNAME        -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("otch")         -> AsString   = DM -> QAbituraOTCH        -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("status_queue") -> AsSmallInt = 105;                                    // !!!!������� � ������ ������� � 105
                                                                                    DM -> StatusQueueQr -> ParamByName ("specializ")    -> AsSmallInt = DM -> QAbituraN_SPECIALIZ -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("n_spec")       -> AsSmallInt = DM -> QAbituraN_SPEC      -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("vid_edu")      -> AsSmallInt = DM -> QAbituraVID_EDU     -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("category_ab")  -> AsSmallInt = DM -> QAbituraCATEGORY_AB -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("category_if")  -> AsSmallInt = DM -> QAbituraCATEGORY_IF -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("category_edu") -> AsSmallInt = DM -> QAbituraEDUCATION   -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("term_edu")     -> AsSmallInt = DM -> QAbituraTERM_EDU    -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("price")        -> AsSmallInt = DM -> QAbituraPRICE       -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("konkurs")      -> AsSmallInt = DM -> QAbituraKONKURS     -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("id_ab")        -> AsInteger  = DM -> ID_from_QUEUE;

                                                                                    DM -> StatusQueueQr -> Prepare ();
                                                                                    DM -> StatusQueueQr -> ExecSQL ();

                                                                                    DM -> StatusQueueQr -> Close ();


                                                                                    DM -> IdAbQueueQr -> Close ();
                                                                                    DM -> IdAbQueueQr -> ParamByName ("id_ab_queue") -> AsInteger = DM -> ID_from_QUEUE;
                                                                                    DM -> IdAbQueueQr -> ParamByName ("nomer_ab")    -> AsInteger = DM -> QAbituraNOMER_AB -> Value;

                                                                                    DM -> IdAbQueueQr -> Prepare ();
                                                                                    DM -> IdAbQueueQr -> ExecSQL ();

                                                                                    DM -> FIOSearchQr -> Close ();

                                                                                    DM -> ID_from_QUEUE = -1;
                                                                                }

                                                                                ChangLog = -1;                          // ���������� �������������� ��������

                                                                                DM -> LogLastQr -> Close ();
                                                                                DM -> LogLastQr -> ParamByName ("nomer_ab") -> AsInteger =  // ��������� �� DATE_IN ������ ��� NOMER_AB
                                                                                    DM -> QAbituraNOMER_AB -> AsInteger;
                                                                                DM -> LogLastQr -> Open ();

                                                                                if (!DM -> LogLastQrID_LOG -> IsNull)                       // � ������ ������� ������� � ������� ������� ��
                                                                                {
                                                                                    DM -> PrivilegLogDelStrdPrc ->
                                                                                        ParamByName ("id_log") -> AsInteger =
                                                                                            DM -> LogLastQrID_LOG -> AsInteger;

                                                                                    DM -> PrivilegLogDelStrdPrc -> Prepare ();
                                                                                    DM -> PrivilegLogDelStrdPrc -> ExecProc ();
                                                                                }

                                                                                DM -> PrivilegLogSelQr -> Close ();
                                                                                DM -> PrivilegLogSelQr ->                                   // �������� �� ABITUR_PRIVILEG ��� NOMER_AB
                                                                                    ParamByName ("nomer_ab") -> AsInteger =
                                                                                        DM -> QAbituraNOMER_AB -> AsInteger;
                                                                                DM -> PrivilegLogSelQr -> Open ();


                                                                                while (!DM -> PrivilegLogSelQr -> Eof)
                                                                                {
                                                                                    DM -> PrivilegLogInsStrdPrc -> ParamByName ("id_log")   -> AsInteger  = DM -> LogLastQrID_LOG          -> AsInteger;
                                                                                    DM -> PrivilegLogInsStrdPrc -> ParamByName ("n_priv")   -> AsSmallInt = DM -> PrivilegLogSelQrN_PRIV   -> Value;
                                                                                    DM -> PrivilegLogInsStrdPrc -> ParamByName ("sel_priv") -> AsSmallInt = DM -> PrivilegLogSelQrSEL_PRIV -> Value;
                                                                                    DM -> PrivilegLogInsStrdPrc -> ParamByName ("dat_priv") -> AsSmallInt = DM -> PrivilegLogSelQrDAT_PRIV -> Value;

                                                                                    DM -> PrivilegLogInsStrdPrc -> Prepare ();
                                                                                    DM -> PrivilegLogInsStrdPrc -> ExecProc ();

                                                                                    DM -> PrivilegLogSelQr -> Next ();
                                                                                }

                                                                                DM -> PrivilegLogSelQr -> Close ();
                                                                                DM -> LogLastQr -> Close ();


                                                                                #ifndef ENROLLMENT_PEOPLE_WITHOUT_CERTIFICATES
                                                                                SertificatForm -> summa_b (nom_abit);
                                                                                DM -> SumBallCalculateQr -> Active = true;
                                                                                DM -> SumBallCalculateQr -> Open ();
                                                                                DM -> SumBallCalculateQr -> Active = false;
                                                                                //if (!SertificatForm -> summa_b (nom_abit))      // ���������� ������  //can't work because SertificatForm was closed and doesn't exists
                                                                                //    ShowMessage (
                                                                                //        "�� ������� �������������� ������"
                                                                                //    );
                                                                                #endif  // ! ENROLLMENT_PEOPLE_WITHOUT_CERTIFICATES

                                                                                DM -> QAbitura -> Close ();
                                                                                DM -> QAbitura -> SQL -> Clear ();
                                                                                DM -> QAbitura ->
                                                                                    SQL -> Add (
                                                                                        " SELECT"                   \
                                                                                        "     address_before,"      \
                                                                                        "     address_life,"        \
                                                                                        "     address_mama,"        \
                                                                                        "     address_papa,"        \
                                                                                        "     category_ab,"         \
                                                                                        "     category_if,"         \
                                                                                        "     citizenship,"         \
                                                                                        "     d_prikaz_include,"    \
                                                                                        "     date_priem,"          \
                                                                                        "     date_r,"              \
                                                                                        "     date_v,"              \
                                                                                        "     date_vozvrat,"        \
                                                                                        "     education,"           \
                                                                                        "     fam,"                 \
                                                                                        "     gragdan,"             \
                                                                                        "     konkurs,"             \
                                                                                        "     mama,"                \
                                                                                        "     middle_ball,"         \
                                                                                        "     n_centre,"            \
                                                                                        "     n_ck,"                \
                                                                                        "     n_fac,"               \
                                                                                        "     n_found,"             \
                                                                                        "     n_langvich,"          \
                                                                                        "     n_prikaz_include,"    \
                                                                                        "     n_region,"            \
                                                                                        "     n_spec,"              \
                                                                                        "     n_specializ,"         \
                                                                                        "     n_sport_category,"    \
                                                                                        "     n_vid_sport,"         \
                                                                                        "     name,"                \
                                                                                        "     name_edu_middle,"     \
                                                                                        "     name_edu_spec,"       \
                                                                                        "     nom_attest,"          \
                                                                                        "     nom_dela,"            \
                                                                                        "     nom_diplom,"          \
                                                                                        "     nom_group,"           \
                                                                                        "     nomer_ab,"            \
                                                                                        "     organ_v,"             \
                                                                                        "     otch,"                \
                                                                                        "     papa,"                \
                                                                                        "     pasport,"             \
                                                                                        "     personal_nomer,"      \
                                                                                        "     phone,"               \
                                                                                        "     place_r,"             \
                                                                                        "     pol,"                 \
                                                                                        "     price,"               \
                                                                                        "     rus_bel,"             \
                                                                                        "     stag,"                \
                                                                                        "     stag_spec,"           \
                                                                                        "     status,"              \
                                                                                        "     sum_ball,"            \
                                                                                        "     term_edu,"            \
                                                                                        "     town_village,"        \
                                                                                        "     type_school,"         \
                                                                                        "     vid_edu,"             \
                                                                                        "     when_edu_middle,"     \
                                                                                        "     when_edu_spec,"       \
                                                                                        "     where_edu_middle,"    \
                                                                                        "     where_edu_spec,"      \
                                                                                        "     work_before,"         \
                                                                                        "     work_mama,"           \
                                                                                        "     work_papa,"           \
                                                                                        "     id_type,"             \
                                                                                        "     date_ok,"             \
                                                                                        "     disabled,"            \
                                                                                        "     street,"              \
                                                                                        "     house,"               \
                                                                                        "     flat,"                \
                                                                                        "     postcode"             \
                                                                                        " FROM"                     \
                                                                                        "     abitura"              \
                                                                                        " WHERE"                    \
                                                                                        "     n_fac = :N_FAC"       \
                                                                                        " AND"                      \
                                                                                        "     ("                    \
                                                                                        "         status = 0"       \
                                                                                        "     OR"                   \
                                                                                        "         status = 6"       \
                                                                                        "     )"                    \
                                                                                        " ORDER BY"                 \
                                                                                        "     fam,"                 \
                                                                                        "     name,"                \
                                                                                        "     otch"
                                                                                    // "SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
                                                                                    // ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
                                                                                    // D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
                                                                                    // EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
                                                                                    // N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
                                                                                    // N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
                                                                                    // NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
                                                                                    // NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
                                                                                    // PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
                                                                                    // STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
                                                                                    // VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
                                                                                    // WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, DISABLED, STREET, \
                                                                                    // HOUSE, FLAT, POSTCODE FROM ABITURA WHERE (N_FAC=:N_FAC) AND (STATUS=0 OR STATUS=6)ORDER BY FAM, NAME, OTCH"
                                                                                );

                                                                                DM -> QAbitura -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
                                                                                DM -> QAbitura -> Open ();

                                                                                RadioGroup1 -> ItemIndex = 2;               // �� �������� '������ ������' ��� ��������: '���'

                                                                                // ������� �� ���������� ����������� ��� �� �������� ����� �������� ���������
                                                                                // TLocateOptions Flags;
                                                                                if (st_ins)                                 // ����� �������
                                                                                    max_nom_dela ();                        // !!! ����� ���������� ������ ���� �� �����. �����

                                                                                DM -> FIOSearchQr -> Close ();

                                                                                DM -> QAbitura ->
                                                                                    Locate (
                                                                                        "NOMER_AB",
                                                                                        nom_abit,
                                                                                        Flags
                                                                                    );


                                                                                RefreshControl ();


                                                                                DM -> QGroup_Count -> Close ();
                                                                                DM -> QGroup_Count -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
                                                                                DM -> QGroup_Count -> Open ();

                                                                                DBDateEdit1            -> Enabled    = true;
                                                                                SpecializDBLookupCmbBx -> Enabled    = false;
                                                                                // NomDelaDBEdt           -> Enabled    = false;
                                                                                TabSheet1              -> TabVisible = true;
                                                                                TabSheet5              -> TabVisible = true;
                                                                                TabSheet2              -> TabVisible = true;
                                                                                // TabSheet3              -> TabVisible = true;
                                                                                // DBNavigator1           -> Enabled    = true;
                                                                                // DBNavigator3           -> Enabled    = true;
                                                                                // DBNavigator4           -> Enabled    = true;
                                                                                // PrintBtBtn             -> Visible    = true;

                                                                                // if (    !AddAbiturPerm
                                                                                //      || st_developer
                                                                                //    )
                                                                                //     AddBtBtn -> Enabled = true;
                                                                                // else
                                                                                //     AddBtBtn -> Enabled = false;

                                                                                st_ins = false;
                                                                            }
                                                                            catch (...)
                                                                            {
                                                                                ShowMessage (
                                                                                    "��������� ������!\n"       \
                                                                                    "������ �� ���������.\n"    \
                                                                                    "�������� ������������!"
                                                                                );
                                                                            }
                                                                        }
                                                                        else
                                                                            ShowMessage (
                                                                                "������� �������!\n"    \
                                                                                "������ �� ���������!"
                                                                            );
                                                                    }
                                                                    else
                                                                        ShowMessage (
                                                                            "������� ����� ������!\n"   \
                                                                            "������ �� ���������!"
                                                                        );
                                                                }
                                                                else
                                                                    ShowMessage (
                                                                        "������� ���� ��������� �����������!\n"   \
                                                                        "������ �� ���������!"
                                                                    );
                                                            }
                                                            else
                                                                ShowMessage (
                                                                    "������� �����������!\n"    \
                                                                    "������ �� ���������!"
                                                                );
                                                        }
                                                        else
                                                            ShowMessage (
                                                                "������� ���������� �����������!\n" \
                                                                "������ �� ���������!"
                                                            );
                                                    }
                                                    else
                                                        ShowMessage (
                                                            "������� ���������!\n"  \
                                                            "������ �� ���������!"
                                                        );
                                                }
                                                else
                                                    ShowMessage (
                                                        "������� ��������� ���� ��������!\n"    \
                                                        "������ �� ���������!"
                                                    );
                                            }
                                            else
                                                ShowMessage (
                                                    "������� ��� ��� ����� ��������!\n"     \
                                                    "������ �� ���������!"
                                                );
                                        }
                                        else
                                            ShowMessage (
                                                "������� �������, ���!\n"   \
                                                "������ �� ���������!"
                                            );
                                    }
                                    else
                                        ShowMessage (
                                            "������� ����� ������!\n"   \
                                            "������ �� ���������!"
                                        );
                                }
                                else
                                    ShowMessage (
                                        "������� ������!\n" \
                                        "������ �� ���������!"
                                    );
                            }
                            else
                                ShowMessage (
                                    "������� �����������!\n"    \
                                    "������ �� ���������!"
                                );
                        }
                        else
                            ShowMessage (
                                "������� ��� ������ � ������!\n"    \
                                "������ �� ���������!"
                            );
                    }
                    else
                        ShowMessage (
                            "������� ��������� ����������� "    \
                            "��� ������� �����������!\n"  \
                            "������ �� ���������!"
                        );
                }
                else
                    ShowMessage (
                        "������� ����������� �������������!\n"  \
                        "������ �� ���������!"
                    );
            }
            else
                ShowMessage (
                    "������� ��� ��������!\n"  \
                    "������ �� ���������!"
                );
        }
        catch (...)
        {
            ShowMessage (
                "������� �� ��� ������ ��� ������ ����������!"
            );
        }
    }
    else
    {
        ShowMessage (
            "�� ������ �� ��������!"
        );
    }

    // SaveBtBtn   -> Enabled = true;                                           // Activate and Show button 'Save'
    // SaveBtBtn   -> Visible = true;
    // CancelBtBtn -> Enabled = true;                                           // Activate and Show button 'Cancel'
    // CancelBtBtn -> Visible = true;
    // ExitBitBtn  -> Enabled = true;                                           // Activate and Show button 'Exit'
    // ExitBitBtn  -> Visible = true;

    // DBNavigator4 -> Enabled = true;                                          // Activate and Show button 'Navigator'
    // DBNavigator4 -> Visible = true;

    PressBtn (1);                                                               // ����� ������ �����

    // EnableDate ();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::CancelBtBtnClick(TObject * Sender)
{ // ������ ��������

    PressBtn(1); // ����� ������ �����
    ChangLog = -1;

    if (DM->QAbitura->State == dsInsert) { // if ��������� � ������ �������
        // ---����� ������������ ����� �����������
        DM->QSertificat->Close();
        DM->QSertificat->ParamByName("NOMER")->AsInteger =
            DM->QAbituraNOMER_AB->Value;
        DM->QSertificat->Open();
        int rec_sert = DM->QSertificat->RecordCount;
        // �������� ������� �� ����������� ���������
        DM->QDelite->Close();
        DM->QDelite->SQL->Clear();
        DM->QDelite->SQL->Add("Delete from Examen where Nomer_Ab=:NOMER");
        DM->QDelite->ParamByName("NOMER")->AsInteger =
            DM->QAbituraNOMER_AB->Value;
        DM->QDelite->Prepare();
        DM->QDelite->ExecSQL();
        DM->QDelite->Close();

        if (rec_sert) { // if ��� ������� �����������
            for (int i = 0; i < rec_sert; i++)
            { // for ��� �������� ������������

                DM->QSertificat->Delete();
                DM->QSertificat->Next();
            } // end for ��� �������� ������������

            DM->QSertificat->ApplyUpdates();
            DM->QSertificat->CommitUpdates();
        } // end if ��� ������� �����������
    } // end if ��������� � ������ �������

    DM->QAbitura->CancelUpdates();
    RefreshControl();

    DBDateEdit1->Enabled = true;
    SpecializDBLookupCmbBx->Enabled = false;
    // NomDelaDBEdt->Enabled = false;
    TabSheet1->TabVisible = true;
    TabSheet5->TabVisible = true;
    TabSheet2->TabVisible = true;
    // TabSheet3->TabVisible = true;

    // DBNavigator1->Enabled = true;
    // DBNavigator3->Enabled = true;
    // DBNavigator4->Enabled = true;
    // PrintBtBtn->Visible = true;
    /* if (!AddAbiturPerm || st_developer)
     AddBtBtn->Enabled = true;
     else
     AddBtBtn->Enabled = false; */

    st_ins = false;
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Edit1Change(TObject * Sender)
{ // ����� �� ������� - ���� �����
    Set<TLocateOption, 0, 1>flags;
    flags << loCaseInsensitive << loPartialKey;
    DM->QAbitura->Locate("FAM", Edit1->Text, flags);
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::RadioGroup1Click(TObject * Sender)
{ // ��� ��������
    if (RadioGroup1->ItemIndex != 2) { // if ������� ��� �������
        DM->QAbitura->Close();
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + "AND (VID_EDU=" +
            AnsiString(RadioGroup1->ItemIndex) + ") ORDER BY FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QAbitura->Open();
    } // end if ������� ��� �������
    else { // else ���
        DM->QAbitura->Close();
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + "ORDER BY FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QAbitura->Open();
    } // end else ���
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::FormActivate(TObject * Sender)
{ // ����� �������� �����

    AbiturForm->Height = 700;
    PageControl1->ActivePage = TabSheet5;
    if (DM->QAbitura->State != dsInsert)
    { // if  ����� ����� �� � ������ ���������� ����� ������
        DM->QAbitura->Close();
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
            ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
            D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
            EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
            N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
            N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
            NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
            NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
            PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
            STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
            VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
            WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
            DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA \
        WHERE (N_FAC=:N_FAC) AND (STATUS=0)ORDER BY FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QAbitura->Open();
        if (DM->QAbitura->RecordCount != 0)
            RefreshControl();

        if (DateServer >= dateOkonch)
            KonkursCmbBx->Enabled = false;

        DM->QAdress->Close();
        DM->QAdress->ParamByName("ID")->AsInteger = DM->QAbituraSTREET->Value;
        DM->QAdress->Open();
    } // end  if  ����� ����� �� � ������ ���������� ����� ������

    ActionList1->State = asSuspended;

    DM->QSpecializPlan_Priem->Open();

    // �����������
    DM->CountryQr->Close();
    DM->CountryQr->Open();

    // �����
    if (region_id == 7) {
        AdressRegEdt->ReadOnly = false;
    }
    else
        AdressRegEdt->ReadOnly = true;

    // ��������� ������ ����������
    // ���
    DM->WithoutQr->Close();
    DM->WithoutCntQr->Close();
    DM->WithoutCntQr->Open();
    int WithoutCnt = DM->WithoutCntQrCOUNT->Value;
    DM->WithoutCntQr->Close();
    DM->WithoutQr->Open();
    TLabel *EditlnstanceL;
    TComboBox *EditlnstanceCB;
    for (int i = 0; i < WithoutCnt; i++) {
        EditlnstanceL = (TLabel*)FindComponent("WithOutLbl" + IntToStr(i + 1));
        EditlnstanceCB = (TComboBox*)FindComponent
            ("WithOutCmboBx" + IntToStr(i + 1));
        EditlnstanceL->Caption = DM->WithoutQrNAME_PRIV->AsString;
        DM->WithoutDetQr->Close();
        DM->WithoutDetQr->ParamByName("id_priv")->AsSmallInt =
            DM->WithoutQrID_PRIV->Value;
        DM->WithoutDetQr->Open();
        EditlnstanceCB->Clear();
        EditlnstanceCB->Items->Add("�");
        while (!DM->WithoutDetQr->Eof) {
            EditlnstanceCB->Items->Add(DM->WithoutDetQrNAME_DETAIS->AsString);
            DM->WithoutDetQr->Next();
        }
        EditlnstanceCB->ItemIndex = 0;
        DM->WithoutDetQr->Close();
        DM->WithoutQr->Next();
    }
    DM->WithoutQr->Close();

    // ��
    DM->OutQr->Close();
    DM->OutCntQr->Close();
    DM->OutCntQr->Open();
    int OutCnt = DM->OutCntQrCOUNT->Value;
    DM->OutCntQr->Close();
    DM->OutQr->Open();
    for (int i = 0; i < OutCnt; i++) {
        EditlnstanceL = (TLabel*)FindComponent("OutLbl" + IntToStr(i + 1));
        EditlnstanceCB = (TComboBox*)FindComponent
            ("OutCmboBx" + IntToStr(i + 1));
        EditlnstanceL->Caption = DM->OutQrNAME_PRIV->AsString;
        DM->OutDetQr->Close();
        DM->OutDetQr->ParamByName("id_priv")->AsSmallInt =
            DM->OutQrID_PRIV->Value;
        DM->OutDetQr->Open();
        EditlnstanceCB->Clear();
        EditlnstanceCB->Items->Add("�");
        while (!DM->OutDetQr->Eof) {
            EditlnstanceCB->Items->Add(DM->OutDetQrNAME_DETAIS->AsString);
            DM->OutDetQr->Next();
        }
        EditlnstanceCB->ItemIndex = 0;
        DM->OutDetQr->Close();
        DM->OutQr->Next();
    }
    DM->OutQr->Close();

    // �������������� ����������
    DM->InfCntQr->Close();
    DM->InfCntQr->Open();
    int InfCnt = DM->InfCntQrCOUNT->Value;
    DM->InfCntQr->Close();
    DM->InfQr->Close();
    DM->InfQr->Open();
    InfChekLstBx->Items->Clear();
    for (int i = 0; i < InfCnt; i++) {
        InfChekLstBx->Items->Add(DM->InfQrNAME_PRIV->AsString);
        DM->InfQr->Next();
    }
    DM->InfQr->Close();

    BitBtnShow(); // ����� ������

    // ���������� ���������� ��� ������
    DM->BlockBtnQr->Close();
    DM->BlockBtnQr->ParamByName("n_fac")->AsSmallInt = nom_fac;
    DM->BlockBtnQr->Open();
    AddAbiturPerm = DM->BlockBtnQrADD_ABITUR->Value;
    TookDoc1Perm = DM->BlockBtnQrTOOK_DOC1->Value;
    TookDoc2Perm = DM->BlockBtnQrTOOK_DOC2->Value;
    ReInsideFacPerm = DM->BlockBtnQrRE_INSIDE_FAC->Value;
    RestorListPerm = DM->BlockBtnQrRESTOR_LIST->Value;
    DM->BlockBtnQr->Close();

    /* if (!AddAbiturPerm || st_developer)
     AddBtBtn->Enabled = true;
     else
     AddBtBtn->Enabled = false; */

    if (!TookDoc1Perm || st_developer)
        TookDocBtBtn1->Enabled = true;
    else
        TookDocBtBtn1->Enabled = false;

    if (!TookDoc2Perm || st_developer)
        TookDocBtBtn2->Enabled = true;
    else
        TookDocBtBtn2->Enabled = false;

    if (!ReInsideFacPerm || st_developer)
        ReInsideFacBtBtn->Enabled = true;
    else
        ReInsideFacBtBtn->Enabled = false;

    if (!RestorListPerm || st_developer)
        RestorlistBtBtn->Enabled = true;
    else
        RestorlistBtBtn->Enabled = false;

    // EnableDate();//����� ����������� ��� ������������ ����� 25.07.2010

    /* DM->QDistrict->Close();
     DM->QDistrict->Open();
     DM->QType_locality->Close();
     DM->QType_locality->Open();
     DM->QLocality->Close();
     DM->QLocality->Open();
     DM->QType_street->Close();
     DM->QType_street->Open();
     DM->QStreet->Close();
     DM->QStreet->Open(); */

    /* if (SplashUnit->loginUser != "DEVELOPER") {
     GroupBox2->Visible = false;
     GroupBox3->Visible = false;
     GroupBox4->Visible = false;
     } */
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::KonkursRdGrpClick(TObject * Sender)
{ // ��������� �� ������ �������
    if (DM->QAbitura->State == dsBrowse)
        DM->QAbitura->Edit();
    switch (KonkursCmbBx->ItemIndex) { // switch

    case 3: // ��
        if (SpecializDBLookupCmbBx->Text != "") { // if ������� �������������
            // ���������� ���-�� ���� �� �������������� �-��� � ������������ - ������!!!
            DM->QCk->Close();
            DM->QCk->ParamByName("N_SPEC")->AsInteger =
                DM->QAbituraN_SPECIALIZ->Value;
            DM->QCk->Open();
            Label29->Visible = true;
            CkRegionDBLkpCmbBx->Visible = true;
        } // end if ������� �������������
        else { // else ������
            ShowMessage("�� ������� �������������!");
            KonkursCmbBx->ItemIndex = -1;
        } // end else ������

        break;
    default:
        Label29->Visible = false;
        CkRegionDBLkpCmbBx->Visible = false;
        break;
    } // end switch
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::AddBtBtnClick(TObject * Sender)
{ // ������ ��������
    NewAbitur(0);
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::DBNavigator1Click(TObject * Sender,
    TNavigateBtn Button) { // ���������
    RefreshControl();
    // ������������� ��
    TabSheet4Show(Sender);
    // �������� ��������� ����� ������ ����������
    if (!st_developer & pole_block == 1)
        KonkursCmbBx->Enabled = false;
    // ��������� Helpa
    WhereEduMiddleDBEdtClick(Sender);
    // ��������� ������ ����
    NumDelaLbl->Caption = DM->NumDelaString(DM->QAbituraVID_EDU->Value,
        DM->QAbituraTERM_EDU->Value, DM->QAbituraPRICE->Value,
        DM->QAbituraNOM_DELA->Value);
    ChangLog = -1;
}
void __fastcall TAbiturForm::DBGrid1DblClick (TObject * Sender)                 // Grid  �� �������� ������ ������
{
    PageControl1 -> ActivePage = TabSheet2;

    ChangLog = -1;

    RefreshControl ();
}
void __fastcall TAbiturForm::PrintBtBtnClick (TObject * Sender)                  // ������ ������
{
    SaveBtBtnClick (this);

    ListDlgForm = new TListDlgForm (this);

    ListDlgForm -> ListBox1 -> Items -> Clear ();
    ListDlgForm -> ListBox2 -> Items -> Clear ();

    DM -> ListDocFDQ -> Close ();
    DM -> DocumFDQ   -> Close ();
    DM -> ListDocFDQ ->
        ParamByName ("NOMER_AB") -> Value =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> DocumFDQ   ->
        ParamByName ("NOMER_AB") -> Value =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> ListDocFDQ -> Open();
    DM -> DocumFDQ   -> Open();

    for (int i = 0;
             i < DM -> ListDocFDQ -> RecordCount;
             ++i
        )
    {
        ListDlgForm -> ListBox2 -> Items ->
            AddObject (
                DM -> ListDocFDQTEXT_DOC -> Value,
                (TObject *) (
                    DM -> ListDocFDQN_DOC -> Value
                )
            );

        DM -> ListDocFDQ -> Next ();
    }

    for (int i = 0;
             i < DM -> DocumFDQ -> RecordCount;
             ++i
        )
    {
        ListDlgForm -> ListBox1 -> Items ->
            AddObject (
                DM -> DocumFDQTEXT_DOC -> Value,
                (TObject *) (
                    DM -> DocumFDQN_DOC -> Value
                )
            );

        DM -> DocumFDQ -> Next();
    }

    if (!ListDlgForm -> ListBox2 -> Items -> Count)
    {
        ListDlgForm -> ListBox2 -> Items ->
            AddObject (
                ListDlgForm -> ListBox1 -> Items -> Strings[0],
                ListDlgForm -> ListBox1 -> Items -> Objects[0]
            );

        ListDlgForm -> ListBox1 -> Items -> Delete (0);                         // ���������� ��������� � ������ ����������
        ListDlgForm -> ListBox2 -> Items ->
            AddObject (
                ListDlgForm -> ListBox1 -> Items -> Strings[0],
                ListDlgForm -> ListBox1 -> Items -> Objects[0]
            );

        ListDlgForm -> ListBox1 -> Items -> Delete (0);                         // ���������� ������� � ������ ����������
        ListDlgForm -> ListBox2 -> Items ->
            AddObject (
                ListDlgForm -> ListBox1 -> Items -> Strings[6],
                ListDlgForm -> ListBox1 -> Items -> Objects[6]
            );

        ListDlgForm -> ListBox1 -> Items -> Delete (6);                         // ���������� ����������� ������� � ������ ����������
    }

    ListDlgForm -> ShowModal ();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::RestorlistBtBtnClick (TObject * Sender)            // ������ ������������ � ������ (��� ������������, ������� �������� ���������)
{
    PressBtn (3);

    DBGrid1->Visible = false;
    Undo_Ab_Form = new TUndo_Ab_Form(this);

    DM->QAbitura->Close();
    DM->QAbitura->SQL->Clear();
    DM->QAbitura->SQL->Add("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
            ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
            D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
            EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
            N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
            N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
            NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
            NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
            PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
            STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
            VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
            WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
            DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA WHERE (STATUS=1) ORDER BY FAM, NAME, OTCH"
        );
    DM->QAbitura->Open();

    Undo_Ab_Form->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TookDocBtBtn1Click(TObject * Sender)
{ // ������ ������ ��������� �� ��������� ����� ����������

    PoleBlock(); // ��������� �������� � ���������� pole_block �� ��

    AnsiString fio_ab = DM->QAbituraFAM->Value + " " + DM->QAbituraNAME->Value +
        " " + DM->QAbituraOTCH->Value;
    int price = DM->QAbituraPRICE->Value;

    /* if (!st_developer) {
     if (pole_block == 1 & price != 1) // pole_block==1, price=������
     {
     ShowMessage(
     "���������� ������� � ���������� � �� ����� �������� ���������! ���������� � ������������!");
     return;
     }
     } */

    if (MessageDlg("���������� �������� ���������?", mtConfirmation, mbOKCancel,
        0) == 1) {
        DM->QAbitura->Edit();
        DM->QAbituraSTATUS->Value = 1;
        DM->QAbituraDATE_VOZVRAT->Value =
            DateTimeToSQLTimeStamp(StrToDate(cur_d.CurrentDate()));
        DM->QAbituraN_CK->Value = 0;
        // DM->QAbituraN_PRIVILEGE_EXAM->Value = 1;
        // DM->QAbituraKONKURS->Value=0;

        // ���������� ���������
        DM->QAbitura->ApplyUpdates();
        DM->QAbitura->CommitUpdates();

        // ���������  QAbitura
        DM->QAbitura->Close();
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
            ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
            D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
            EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
            N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
            N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
            NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
            NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
            PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
            STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
            VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
            WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
            DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA WHERE (N_FAC=:N_FAC) AND (STATUS=0)ORDER BY FAM, NAME, OTCH"
            );
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QAbitura->Open();

        if (DM->QAbitura->RecordCount != 0)
            RefreshControl();

        DM->QGroup_Count->Close();
        DM->QGroup_Count->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QGroup_Count->Open();
    } // end MessageDlg=OK

}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::FormEduCmbBxChange(TObject * Sender)
{ // ��� ��������
    bool FormEduChange = false;
    if (ChangLog == 0) {
        if (MessageDlg("��������� ������� ��������� �������� ������� � �������� ����������\n \
         � ���������� ����� ������ � ������� ����� ������������.\n�� ������ ����������?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            FormEduChange = true;
        }
    }
    else
        FormEduChange = true;
    if (FormEduChange == true) {
        if (DM->QAbitura->State == dsBrowse)
            DM->QAbitura->Edit();
        if (oplata_konkurs == 0 && PriceCmbBx->ItemIndex != -1)
            VidKonkurs(KonkursCmbBx, PriceCmbBx, FormEduCmbBx);
        if (ChangLog != 2)
            ChangLog = 1;
    }

    // ������������ �� �� ������
    // ���������������� � ����� � �������
    // TabSheet4Show(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::EducatCmbBxChange(TObject * Sender) {
    bool EducatChange = false;
    // ��������� �����������
    if (ChangLog == 0) {
        if (MessageDlg("��������� ������� ��������� �������� ������� � �������� ����������\n \
         � ���������� ����� ������ � ������� ����� ������������.\n�� ������ ����������?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            EducatChange = true;
        }
    }
    else
        EducatChange = true;
    if (EducatChange == true) {
        if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
            DM->QAbitura->Edit();
        } // end if dsBrowse

        TermEduCmbBx->ItemIndex = -1;
        PriceCmbBx->ItemIndex = -1;
        KonkursCmbBx->ItemIndex = -1;
        TermEduCmbBx->Clear();

        int pr_edu; // 0 - ��/���, 1 - ��
        switch (EducatCmbBx->ItemIndex) {
        case 0: // ��
            {
                pr_edu = 0;
                break;
            }
        case 1: // ���
            {
                pr_edu = 0;
                break;
            }
        case 2: // ������������� ��
            {
                pr_edu = 1;
                break;
            }
        case 3: // ��
            {
                pr_edu = 1;
                break;
            }
        case 4: // ���
            {
                pr_edu = 0;
                break;
            }
        }

        switch (pr_edu) {
        case 0: // ��/���
            {
                // ���� ��������� �����������
                Label64->Caption = "���� ��������� �����������:";
                TermEduCmbBx->Clear();
                TermEduCmbBx->Items->Add("������");
                if ((pr_KategIf == 0) && (EducatCmbBx->ItemIndex == 1))
                { // ������ ��� �� + ��� �.�. � �����������
                    TermEduCmbBx->Items->Add("����������� 2 ����");
                    TermEduCmbBx->Items->Add("����������� 3 ����");
                    TermEduCmbBx->ItemIndex = -1;
                    if (EducatCmbBx->ItemIndex > -1)
                        TermEduCmbBx->Enabled = true;
                    else
                        TermEduCmbBx->Enabled = false;
                }
                else { // ��, ���
                    // ��/���, ��� ����������� � ��� - ������ ������
                    TermEduCmbBx->ItemIndex = 0;
                    TermEduCmbBx->Enabled = false;
                }
                break;
            }
        case 1: // ��
            {
                // ���� �����������
                Label64->Caption = "���� �����������:";
                TermEduCmbBx->Items->Clear();
                TermEduCmbBx->Items->Add("1 ����");
                if (((pr_KategIf == 0) || (pr_KategIf == 2)) &&
                    (EducatCmbBx->ItemIndex == 3)) {
                    // ��, �� ����������
                    TermEduCmbBx->Items->Add("2 ����");
                    TermEduCmbBx->Items->Add("3 ����");
                    TermEduCmbBx->ItemIndex = -1;
                    if (EducatCmbBx->ItemIndex > -1)
                        TermEduCmbBx->Enabled = true;
                    else
                        TermEduCmbBx->Enabled = false;
                }
                else {
                    // ��, ����������
                    // ������ ������
                    TermEduCmbBx->ItemIndex = 0;
                    TermEduCmbBx->Enabled = false;
                }
                break;
            }
        default:
            TermEduCmbBx->Enabled = false;
        }

        TermEduCmbBxChange(this);
        if (ChangLog != 2)
            ChangLog = 1;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::FamDBEdtKeyDown(TObject * Sender, WORD & Key,
    TShiftState Shift) { // �������
    /* if (Key==32)
     { //if ����� ������
     DBEdit4->SetFocus();
     }//end if ����� ������ */ }

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::NameDBEdtKeyDown(TObject * Sender, WORD & Key,
    TShiftState Shift) { // ���
    /* if (Key==32)
     {//if ����� ������
     DBEdit5->SetFocus();
     }//end if ����� ������ */ }

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::DBGrid1TitleClick(TColumn * Column)
{ // ������ �� ������  Grid�, ��� ����������

    DM->QAbitura->Close();

    AnsiString sql_temp_1 = Chek_Vid_Edu();
    AnsiString ttl;
    ttl = Column->Title->Caption;
    if (ttl == "�������") {
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + sql_temp_1 +
            " ORDER BY FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    }
    if (ttl == "� ��.") {
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + sql_temp_1 +
            " ORDER BY NOM_GROUP, FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    }
    if (ttl == "� ����") {
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + sql_temp_1 + " ORDER BY NOM_DELA");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    }
    if (ttl == "�������. �������������") {
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + sql_temp_1 +
            " ORDER BY N_SPECIALIZ, FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    }
    if (ttl == "�������") {
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + sql_temp_1 +
            " ORDER BY KONKURS, FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    }
    if (ttl == "���� ������") {
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + sql_temp_1 +
            " ORDER BY DATE_PRIEM, NOM_DELA");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    }

    DM->QAbitura->Open();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TookDocBtBtn2Click(TObject * Sender)
{ // ������ ������ ��������� �� ����� ���������
    AnsiString fio_ab = DM->QAbituraFAM->Value + " " + DM->QAbituraNAME->Value +
        " " + DM->QAbituraOTCH->Value;

    if (MessageDlg
        ("���������� ������������� ����� ������� ��������� � ���� �� ������ ����?",
        mtConfirmation, mbOKCancel, 0) == 1) {

        DM->QAbitura->Edit();
        // DM->QAbituraSTATUS->Value = 4; // ������ ��������� �� ����� ���������
        DM->QAbituraSTATUS->Value = 1;
        // �������, ��� �� ����� ���� ������������
        DM->QAbituraDATE_VOZVRAT->Value =
            DateTimeToSQLTimeStamp(StrToDate(cur_d.CurrentDate()));

        DM->QAbitura->ApplyUpdates();
        DM->QAbitura->CommitUpdates();

        DM->QAbitura->Close();
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
            ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
            D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
            EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
            N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
            N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
            NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
            NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
            PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
            STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
            VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
            WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
            DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA WHERE (N_FAC=:N_FAC) AND (STATUS=0)ORDER BY FAM, NAME, OTCH"
            );
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QAbitura->Open();

        if (DM->QAbitura->RecordCount != 0)
            RefreshControl();

        DM->QGroup_Count->Close();
        DM->QGroup_Count->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QGroup_Count->Open();
    } // end if MessageDlg=OK
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::DBGrid3DblClick(TObject * Sender)                  // ������� ������ �� Grid-� � �������������
{
    SertificatForm = new TSertificatForm(this);
    SertificatForm->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::WhereEduMiddleDBEdtClick(TObject * Sender) {

    WhereEduMiddleDBEdt->HelpContext = 10; // ����� ������ ��������
    // ��� ����������� �� ���� �� ���� ��� �������� ������� ����������� - �������� Help  � ��������
    if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
        (WhereEduMiddleDBEdt->Text.Pos("�����")))
        WhereEduMiddleDBEdt->HelpContext = 20;
    if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
        (WhereEduMiddleDBEdt->Text.Pos("�������")))
        WhereEduMiddleDBEdt->HelpContext = 40;
    if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
        (WhereEduMiddleDBEdt->Text.Pos("������")))
        WhereEduMiddleDBEdt->HelpContext = 70;
    if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
        (WhereEduMiddleDBEdt->Text.Pos("�����")))
        WhereEduMiddleDBEdt->HelpContext = 100;
    if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
        (WhereEduMiddleDBEdt->Text.Pos("�����")))
        WhereEduMiddleDBEdt->HelpContext = 120;
    if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
        (WhereEduMiddleDBEdt->Text.Pos("�������")))
        WhereEduMiddleDBEdt->HelpContext = 150;

    switch (WhereEduMiddleDBEdt->HelpContext) {
    case 20: // �����
        // ��������� �������
        if ((WhereEduMiddleDBEdt->Text.Pos("���������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("���������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 21;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 22;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 23;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 24;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 25;
        if ((WhereEduMiddleDBEdt->Text.Pos("���������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("���������")))
            WhereEduMiddleDBEdt->HelpContext = 26;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 27;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 28;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 29;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 30;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 31;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 32;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 33;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 34;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 35;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 35;
        break;

    case 40: // �������
        // ������ ��������� �������
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 41;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 42;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����������")))
            WhereEduMiddleDBEdt->HelpContext = 43;
        if ((WhereEduMiddleDBEdt->Text.Pos("���������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("���������")))
            WhereEduMiddleDBEdt->HelpContext = 44;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 45;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 46;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 47;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 48;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 49;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 50;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            WhereEduMiddleDBEdt->HelpContext = 51;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            WhereEduMiddleDBEdt->HelpContext = 52;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 53;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 54;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 55;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            WhereEduMiddleDBEdt->HelpContext = 56;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 57;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            WhereEduMiddleDBEdt->HelpContext = 58;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 59;
        if ((WhereEduMiddleDBEdt->Text.Pos("���������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("���������")))
            WhereEduMiddleDBEdt->HelpContext = 60;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 61;
        break;
    case 70: // ������
        // ������ ���������� �������
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 71;
        if ((WhereEduMiddleDBEdt->Text.Pos("����-�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����-�������")))
            WhereEduMiddleDBEdt->HelpContext = 72;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            WhereEduMiddleDBEdt->HelpContext = 73;
        if ((WhereEduMiddleDBEdt->Text.Pos("����������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����������")))
            WhereEduMiddleDBEdt->HelpContext = 74;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 75;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 76;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 77;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 78;
        if ((WhereEduMiddleDBEdt->Text.Pos("����������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����������")))
            WhereEduMiddleDBEdt->HelpContext = 79;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            WhereEduMiddleDBEdt->HelpContext = 80;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 81;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            WhereEduMiddleDBEdt->HelpContext = 82;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 83;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 84;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 85;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 86;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 87;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 88;
        if ((WhereEduMiddleDBEdt->Text.Pos("���������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("���������")))
            WhereEduMiddleDBEdt->HelpContext = 89;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 90;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 91;
        break;
    case 100: // �����
        // ����������� �������
        if ((WhereEduMiddleDBEdt->Text.Pos("����������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����������")))
            WhereEduMiddleDBEdt->HelpContext = 101;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 102;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 103;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����������")))
            WhereEduMiddleDBEdt->HelpContext = 104;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 105;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 106;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            WhereEduMiddleDBEdt->HelpContext = 117;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 107;
        if ((WhereEduMiddleDBEdt->Text.Pos("���")) ||
            (WhereEduMiddleDBEdt->Text.Pos("���")))
            WhereEduMiddleDBEdt->HelpContext = 108;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            WhereEduMiddleDBEdt->HelpContext = 109;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 110;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 111;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 112;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 113;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 114;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 115;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 116;
        break;
    case 120: // �����
        // ������� �������
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 121;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 122;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 123;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 104;
        if ((WhereEduMiddleDBEdt->Text.Pos("���������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("���������")))
            WhereEduMiddleDBEdt->HelpContext = 125;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 126;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 127;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            WhereEduMiddleDBEdt->HelpContext = 128;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 129;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 130;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 131;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 132;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 133;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 134;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 135;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 136;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 137;
        if ((WhereEduMiddleDBEdt->Text.Pos("���������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("���������")))
            WhereEduMiddleDBEdt->HelpContext = 138;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            // ��������������
                WhereEduMiddleDBEdt->HelpContext = 139;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 140;
        if ((WhereEduMiddleDBEdt->Text.Pos("���")) ||
            (WhereEduMiddleDBEdt->Text.Pos("���")))
            // ���������
                WhereEduMiddleDBEdt->HelpContext = 141;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 142;
        break;
    case 150: // �������
        // ����������� �������
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 151;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 152;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 153;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            // ��������
                WhereEduMiddleDBEdt->HelpContext = 154;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 155;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 156;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 157;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 158;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 159;
        if ((WhereEduMiddleDBEdt->Text.Pos("����������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����������")))
            WhereEduMiddleDBEdt->HelpContext = 160;
        if ((WhereEduMiddleDBEdt->Text.Pos("����������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����������")))
            WhereEduMiddleDBEdt->HelpContext = 161;
        if ((WhereEduMiddleDBEdt->Text.Pos("������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("������")))
            WhereEduMiddleDBEdt->HelpContext = 162;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            // �����������
                WhereEduMiddleDBEdt->HelpContext = 163;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����������")))
            WhereEduMiddleDBEdt->HelpContext = 164;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 165;
        if ((WhereEduMiddleDBEdt->Text.Pos("��������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("��������")))
            WhereEduMiddleDBEdt->HelpContext = 166;
        if ((WhereEduMiddleDBEdt->Text.Pos("���������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("���������")))
            WhereEduMiddleDBEdt->HelpContext = 167;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 168;
        if ((WhereEduMiddleDBEdt->Text.Pos("����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("����")))
            // ��������
                WhereEduMiddleDBEdt->HelpContext = 169;
        if ((WhereEduMiddleDBEdt->Text.Pos("�������")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�������")))
            WhereEduMiddleDBEdt->HelpContext = 170;
        if ((WhereEduMiddleDBEdt->Text.Pos("�����")) ||
            (WhereEduMiddleDBEdt->Text.Pos("�����")))
            WhereEduMiddleDBEdt->HelpContext = 171;
        break;
    default:
        WhereEduMiddleDBEdt->HelpContext = 10;
        break;
    } // end switch

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::SpecializDBLookupCmbBxExit(TObject * Sender) {
    // ����� �������������
    NomGroupCmbBx->ItemIndex = -1;

    if (FormEduCmbBx->ItemIndex == -1 || FormEduCmbBx->Text == "")
    { // if �������� �� ��� ��������
        ShowMessage("������� ������� ����� ��������� �����������!!!!");
        return;
    } // end if �������� �� ��� ��������
    if (SpecializDBLookupCmbBx->Text == "") { // if �������� �� �������������
        ShowMessage("������� ������� ����������� �������������!!!!");
        return;
    } // end if �������� �� �������������

    // ���������� ��� ����� ��������� ������ ��������� �������������
    AnsiString sp = "." + SpecializDBLookupCmbBx->KeyValue;
    sp += ".";

    // �������� Query �� ���������� ���� �������� � ������������� - �������� ������ ������
    DM->QN_group->Close();
    DM->QN_group->ParamByName("FAC")->AsSmallInt = nom_fac;
    DM->QN_group->ParamByName("EDU")->AsSmallInt = FormEduCmbBx->ItemIndex;
    DM->QN_group->ParamByName("SPEC")->AsString = sp;
    DM->QN_group->Open();

    // �������� Query ���������� ������� � ������ ������
    DM->QGroup_Count->Close();
    DM->QGroup_Count->ParamByName("N_FAC")->AsInteger = nom_fac;
    DM->QGroup_Count->Open();

    // ������� ������ �����
    NomGroupCmbBx->Clear();

    for (int i = 0; i < DM->QN_group->RecordCount; i++)
    { // for ���� �� ������� ������� ���� �������� � �������������

        int kol = 0; // ���������� ������� � ������
        Variant nnn = DM->QGroup_Count->Lookup("NOM_GROUP",
            DM->QN_groupNOM_GROUP->Value, "COUNT");
        if (!nnn.IsNull()) { // if ����� ��� ������
            kol = nnn;
        } // end if ����� ��� ������
        else
            kol = 0;
        if (kol < DM->QN_groupN_COUNT->Value)
        { // if ��������� �� ���������� ������� � ������, ����������� � ���������� � ��������
            NomGroupCmbBx->Items->Add(DM->QN_groupNOM_GROUP->Value);
        } // end if ��������� �� ���������� ������� � ������, ����������� � ���������� � ��������
        DM->QN_group->Next();
    } // end for ���� �� ������� ������� ���� �������� � �������������

    if (ChangLog != 2)
        ChangLog = 1;

    // ������������ �� �� ������
    // ���������������� � ����� � �������
    // TabSheet4Show(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Image1Click(TObject * Sender) {
    if (OpenPictureDialog1->Execute()) {
        try {
            DM->QAbitura->Edit();
        }
        catch (...) {
            DM->QAbitura->Insert();
        }

        Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
        pms->Clear();
        jp->Assign(Image1->Picture);
        jp->SaveToStream(pms);
        pms->Position = 0;
        DM->QFotoSignPHOTO->LoadFromStream(pms);

    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::FormCreate(TObject * Sender) {
    pms = new TMemoryStream();
    jp = new Jpeg::TJPEGImage();
    DM->QLangvich->Open();
    DM->QPersonalDocum->Open();
    ChangLog = 0;

    PageControl1->ActivePage = TabSheet5;

    NameBtn(); // ����� ��������� �������� ������

}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::FormEduCmbBxExit(TObject * Sender) {
    // ����� �� �������� ������ ����� ��������
    NomGroupCmbBx->ItemIndex = -1;
    if (SpecializDBLookupCmbBx->Text == "" && DM->QAbitura->State == dsInsert &&
        FormEduCmbBx->Text != "") {
        // if ���� ����������� ������������� ������, � ����� �������� �������
        /// �� ������������ Query ��� ����������� ����. �� �����

        DM->QSpecializPlan_Priem->Close();
        DM->QSpecializPlan_Priem->ParamByName("VID_EDU")->AsSmallInt =
            FormEduCmbBx->ItemIndex;
        DM->QSpecializPlan_Priem->ParamByName("FAC")->AsSmallInt = nom_fac;
        DM->QSpecializPlan_Priem->Open();

    }
    if (SpecializDBLookupCmbBx->Text != "" && DM->QAbitura->State == dsInsert &&
        NomGroupCmbBx->Text == "") {
        // if ���� ����������� ������������� �������
        // � ���� ����� ������
        SpecializDBLookupCmbBxExit(this);
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::SpeedButton1Click(TObject * Sender)                // ����� ����� �� �������� ����� ���������
{
    if (press != 2)
        MsgEdit ();

    SredBalForm =  new TSredBalForm(this);
    SredBalForm -> ShowModal();

//    DM->QEducation->Close();
//    DM->QEducation->Open();
//    EducationForm = new TEducationForm(this);
//    EducationForm->ShowModal();
//    DM->QEducation->Insert();
    //DM->QEducationNOMER_AB->Value = DM->QAbituraNOMER_AB->Value;
}
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::SpeedButton2Click(TObject * Sender)                // ����� ����� �� ���������� ������������ ��� ������� �������� �����
{
    if (press != 2)
        MsgEdit ();
    #ifndef ADD_SERTIFICATE_INSTEAD_COUNT_MIDDLE_BALL
    SredBalForm    =  new TSredBalForm (this);
    SredBalForm    -> ShowModal ();
    #else
    SertificatForm =  new TSertificatForm (this);
    SertificatForm -> ShowModal ();
    #endif  // ! ADD_SERTIFICATE_INSTEAD_COUNT_MIDDLE_BALL
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::FormCanResize(TObject * Sender, int &NewWidth,
    int &NewHeight, bool &Resize) {

    /* SaveBtBtn->Top = 8;
     CancelBtBtn->Top = 8;
     ExitBitBtn->Top=8;
     PrintBtBtn->Top=8; */
    // DBNavigator4 ->Top=AbiturForm->Height-62;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::ReInsideFacBtBtnClick(TObject * Sender)
{ // ��������� ���������
    PressBtn(4);

    Undo_Ab_1Form = new TUndo_Ab_1Form(this);
    Undo_Ab_1Form->Caption = "���������� ����������";
    Undo_Ab_1Form->Edit2->Text = DM->QAbituraNOM_DELA->Value; // � ����
    Undo_Ab_1Form->ComboBox1->ItemIndex = DM->QAbituraVID_EDU->Value;
    // ��� ��������
    Undo_Ab_1Form->DBLookupComboBox1->KeyValue = DM->QAbituraN_SPECIALIZ->Value;
    // ��������� �����������
    Undo_Ab_1Form->CategoryAbCmbBx->ItemIndex = DM->QAbituraCATEGORY_AB->Value;
    Undo_Ab_1Form->SngFrgCmbBx->ItemIndex = DM->QAbituraCATEGORY_IF->Value;

    // �������������
    // Undo_Ab_1Form->ComboBox2->Text=DM->QAbituraNOM_GROUP->Value;  //� ������
    Undo_Ab_1Form->ComboBox2->Items->Add(DM->QAbituraNOM_GROUP->Value);
    Undo_Ab_1Form->ComboBox2->ItemIndex = 0;
    Undo_Ab_1Form->KonkursCmbBx->ItemIndex = DM->QAbituraKONKURS->Value;
    // �������

    Undo_Ab_1Form->DBLookupComboBox2->KeyValue = DM->QAbituraN_VID_SPORT->Value;
    // ��� ������
    Undo_Ab_1Form->DBLookupComboBox3->KeyValue =
        DM->QAbituraN_SPORT_CATEGORY->Value; // ������

    if (DM->QAbituraN_CK->Value) { // if ���� ������� ��������
        Undo_Ab_1Form->Label29->Visible = true;
        Undo_Ab_1Form->DBLookupComboBox4->Visible = true;
        Undo_Ab_1Form->DBLookupComboBox4->KeyValue = DM->QAbituraN_CK->Value;
        // ������ ��
    } // end if ���� ������� ��������
    else { // else ��� ���������
        Undo_Ab_1Form->Label29->Visible = false;
        Undo_Ab_1Form->DBLookupComboBox4->Visible = false;
        Undo_Ab_1Form->DBLookupComboBox4->KeyValue = -1; // ������ ��
    } // end else ��� ���������

    Undo_Ab_1Form->Label4->Caption =
        SQLTimeStampToDateTime(DM->QAbituraDATE_PRIEM->Value);
    // ���� ������ ����������
    Undo_Ab_1Form->ShowModal();

}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Vk1Click(TObject * Sender)
{ // ��������� ����������� ��� ���������� ����� ���������� �����������
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::ApplicationEvents1Message(tagMSG & Msg,
    bool &Handled) {
    // ������������ ���������� ������ �������� �������� � DBGrid

    if (DBGrid1->Focused() && AbiturForm->Active && TabSheet1->Focused()) {
        if (Msg.message == WM_MOUSEWHEEL) {
            Msg.message = WM_KEYDOWN;
            Msg.lParam = 0;
            short int i = HIWORD(Msg.wParam);
            Msg.wParam = (i > 0) ? VK_UP : VK_DOWN;
            Handled = false;
        }
    }

}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::PersonNumDBEdtExit (TObject * Sender)              // WARNING: BE CAREFUL!!!! Works only for personal numbers until 2012.
{
    #ifdef DEEP_CHECK_PERSONAL_NUMBER
    if (DM -> QAbitura -> State == dsInsert)                                    // ����� ���������� ��������
    {

        AnsiString lich_nomer = PersonNumDBEdt -> Text;

        if (lich_nomer != "")
        {
            AnsiString
                dat  = "",
                temp =
                    lich_nomer.SubString (
                        1,                                                      // start character position (from 1)
                        1                                                       // number of characters starting at position
                    );

            // if (    StrToInt (temp) < 3
            //      || StrToInt (temp) > 7
            //    )
            //     ShowMessage (
            //         "��������!\n\n"                     \
            //         "� ������ ������ ������� ������ "       \
            //         "������ ��������!\n\n"                   \
            //         "������: 3------------- (�� 3 �� 7)"
            //     );

            // if (StrToInt (temp) == 3)
            // {
            //     PolDBCmbBx -> ItemIndex = 0;

            //     DM -> QAbituraPOL -> Value = "�";
            // }
            // if (StrToInt (temp) == 4)
            // {
            //     PolDBCmbBx -> ItemIndex = 1;

            //     DM -> QAbituraPOL -> Value = "�";
            // }


            try
            {
                int x = 0;

                if (    lich_nomer.SubString (1, 1) == 3                        // ������ �����
                     || lich_nomer.SubString (1, 1) == 4
                   )
                {
                    temp =                                                      // ������ ����
                        lich_nomer.SubString (
                            2,
                            2
                        );
                    x    = temp.ToInt ();

                    if (x < 1 || x > 31)
                        return
                            ShowMessage (
                                "��������!\n\n"                         \
                                "� ������ ������ ������� ������ "       \
                                "���� ��������!\n\n"                    \
                                "������: -25----------- (�� 1 �� 31)"
                            );
                    else
                        dat += temp + ".";

                    temp = lich_nomer.SubString (4, 2);                         // �����
                    x = temp.ToInt ();
                    if (x < 1 || x > 12)
                        return
                            ShowMessage (
                                "��������!\n\n"                         \
                                "� ������ ������ ������� ������ "       \
                                "����� ��������!\n\n"                   \
                                "������: ---05--------- (�� 1 �� 12)"
                            );
                    else
                        dat += temp + ".";

                    temp = lich_nomer.SubString (6, 2);                         // ���
                    x = temp.ToInt ();

                    if (x < 35 || x > 99)
                        return
                            ShowMessage (
                                "��������!\n\n"                         \
                                "� ������ ������ ������� ������ "       \
                                "��� ��������!\n\n"                   \
                                "������: -----06------- (�� 1 �� 99)"
                            );
                    else
                        dat += "19" + temp;

                    BirthdayDBDateEdit -> Text = StrToDateTime (dat);
                    DM -> QAbituraDATE_R -> Text = BirthdayDBDateEdit -> Text;
                }
            }
            catch (...)
            {
                ShowMessage (
                    "�������� ������ � ������ ������!"
                );
            }
        }
    }
    #endif  // DEEP_CHECK_PERSONAL_NUMBER
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::FamDBEdtExit(TObject * Sender) { // FAM
    if (DM->QAbitura->State == dsInsert) { // if � ������ ���������� ��������
        // ��������� ��� � ����������� ��� � ������ ������
        // DMStat->FIO(AnsiString text, TQuery* q, AnsiString pole)
        DMStat->FIO(FamDBEdt->Text, DM->QAbitura, "FAM");
        FamDBEdt->Text = DM->QAbituraFAM->Value;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::NameDBEdtExit(TObject * Sender) { // NAME
    if (DM->QAbitura->State == dsInsert) { // if � ������ ���������� ��������
        // ��������� ��� � ����������� ��� � ������ ������
        // DMStat->FIO(AnsiString text, TQuery* q, AnsiString pole)
        DMStat->FIO(NameDBEdt->Text, DM->QAbitura, "NAME");
        NameDBEdt->Text = DM->QAbituraNAME->Value;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OtchDBEdtExit(TObject * Sender) { // OTCH
    if (DM->QAbitura->State == dsInsert) { // if � ������ ���������� ��������
        // ��������� ��� � ����������� ��� � ������ ������
        // DMStat->FIO(AnsiString text, TQuery* q, AnsiString pole)
        DMStat->FIO(OtchDBEdt->Text, DM->QAbitura, "OTCH");
        OtchDBEdt->Text = DM->QAbituraOTCH->Value;
    }
}
// ---------------------------------------------------------------------------

// ������ ��������� ������!!! ����� ��������� � �� BLOCK=1
// --------------------------------------------------------------------------
void __fastcall TAbiturForm::Ch5Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Ch6Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Ch3Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Ch7Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Ch8Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Ch9Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::PriceRdGrpEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::KonkursRdGrpEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::EducatCmbBxEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::DBGrid3Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::NomGroupCmbBxEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Vk1Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Vk4Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Vk6Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Vk5Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Wo1Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Wo2Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Wo3Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Wo4Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Wo5Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr1Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr4Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr21Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr2Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr3Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr5Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr6Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr7Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr19Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr8Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr9Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr10Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr11Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr12Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr13Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr23Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr17Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr14Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr22Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr20Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr18Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr16Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr15Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clictNotConcoursEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistAddAwardsEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistNotExamsEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistGIACEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistddEnrollingEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clictNotConcoursClickCheck(TObject * Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistNotExamsClickCheck(TObject * Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistAddAwardsClickCheck(TObject * Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistddEnrollingClickCheck(TObject * Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistGIACClickCheck(TObject * Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::StagSpecDBEdtEhExit(TObject * Sender) {
    if (StagSpecDBEdtEh->Text == "   ") {
        StagSpecDBEdtEh->Text = 0;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TabSheet4Show(TObject * Sender) {
    // ��� ����������� ������� "����� ��"
    if (nom_fac != 4) {

        RdGrpCtrlExerc1->Items->Clear();
        RdGrpCtrlExerc2->Items->Clear();
        RdGrpCtrlExerc3->Items->Clear();

        int KuGrp, KuAb; // ���������� ��� ���������� ID ��


        if (    DBEditSpec -> Text != ""                                        // ������ ��
             && DBEditPol  -> Text != ""
           )
        {

            for (int j = 0;                                                     // ���� �� ������ ��
                     j < 3;
                     ++j
                )
            {
                DM -> QExerc_Grp -> Close();

                DM -> QExerc_Grp -> ParamByName ("n_specializ") -> AsInteger =
                    StrToInt(DBEditSpec->Text);
                DM->QExerc_Grp->ParamByName("pol")->AsAnsiString = Caption =
                    DBEditPol->Text;
                DM->QExerc_Grp->ParamByName("num_exerc_grp")->AsInteger = j + 1;
                DM->QExerc_Grp->Open();

                int num_rec = DM -> QExerc_Grp -> RecordCount;                  // ���������� �� � ��������� ����� ��

                switch (j)                                                      // ����� �� ������ ��
                {
                    case 0:
                            for (int i = 0;
                                     i < num_rec;
                                     ++i)
                            {
                                RdGrpCtrlExerc1 -> Items ->
                                    Add (
                                        DM -> QExerc_GrpNAME_EXERC -> AsString
                                    );
                                DM -> QFindAbiturExerc -> Close ();

                                DM -> QFindAbiturExerc ->
                                    ParamByName ("NOMER_AB") ->AsString =
                                        DBEditNumAb -> Text;
                                DM -> QFindAbiturExerc ->
                                    ParamByName ("NUM_EXERC_GRP") -> AsInteger =
                                        j + 1;
                                DM -> QFindAbiturExerc -> Open ();

                                KuGrp = DM -> QExerc_GrpID_EXERC -> AsInteger;
                                KuAb  = DM -> QFindAbiturExercID_EXERC -> AsInteger;

                                mas_sel_exerc[j][i] = KuGrp;

                                if (KuGrp == KuAb)
                                    RdGrpCtrlExerc1 -> ItemIndex = i;

                                DM -> QFindAbiturExerc -> Close();
                                DM -> QExerc_Grp -> Next();
                            }
                        break;
                    case 1:
                            for (int i = 0;
                                     i < num_rec;
                                     ++i)
                            {
                                RdGrpCtrlExerc2 -> Items ->
                                    Add (
                                        DM -> QExerc_GrpNAME_EXERC -> AsString
                                    );
                                DM -> QFindAbiturExerc -> Close ();
                                DM -> QFindAbiturExerc ->
                                    ParamByName ("NOMER_AB") -> AsString =
                                        DBEditNumAb -> Text;
                                DM -> QFindAbiturExerc ->
                                    ParamByName ("NUM_EXERC_GRP") -> AsInteger =
                                        j + 1;
                                DM -> QFindAbiturExerc -> Open ();

                                KuGrp = DM -> QExerc_GrpID_EXERC -> AsInteger;
                                KuAb  = DM -> QFindAbiturExercID_EXERC -> AsInteger;

                                mas_sel_exerc[j][i] = KuGrp;

                                if (KuGrp == KuAb)
                                    RdGrpCtrlExerc2 -> ItemIndex = i;

                                DM -> QFindAbiturExerc -> Close ();
                                DM -> QExerc_Grp -> Next ();
                            }
                        break;
                    case 2:
                            for (int i = 0;
                                     i < num_rec;
                                     ++i
                                )
                            {
                                RdGrpCtrlExerc3 -> Items ->
                                    Add (
                                        DM -> QExerc_GrpNAME_EXERC -> AsString
                                    );
                                DM -> QFindAbiturExerc -> Close();
                                DM -> QFindAbiturExerc ->
                                    ParamByName("NOMER_AB") -> AsString =
                                        DBEditNumAb -> Text;
                                DM -> QFindAbiturExerc ->
                                    ParamByName ("NUM_EXERC_GRP") -> AsInteger =
                                    j + 1;
                                DM -> QFindAbiturExerc -> Open ();

                                KuGrp = DM -> QExerc_GrpID_EXERC -> AsInteger;
                                KuAb  = DM -> QFindAbiturExercID_EXERC -> AsInteger;

                                mas_sel_exerc[j][i] = KuGrp;

                                if (KuGrp == KuAb)
                                    RdGrpCtrlExerc3 -> ItemIndex = i;

                                DM -> QFindAbiturExerc -> Close ();
                                DM -> QExerc_Grp -> Next ();
                            }
                        break;

                    default: ;
                }
            }
        }

        DM->QExerc_Grp->Close();
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::BitBtn9Click(TObject *Sender) {
    DM->QRep_Sel_Exerc->Close();
    DM->QRep_Sel_Exerc->ParamByName("NOMER_AB")->AsString = DBEditNumAb->Text;
    DM->QRep_Abitura->Close();
    DM->QRep_Abitura->ParamByName("NOMER_AB")->AsString = DBEditNumAb->Text;
    DM->QRep_Sel_Exerc->Open();
    DM->QRep_Abitura->Open();
    DM->QKod_Spec->Close();
    DM->QKod_Spec->ParamByName("N_SPECIALIZ")->AsInteger =
        StrToInt(DBEditSpec->Text);
    DM->QKod_Spec->Open();
    DM->QKod_Fac->Close();
    DM->QKod_Fac->ParamByName("N_FAC")->AsInteger = nom_fac;
    DM->QKod_Fac->Open();
    FormRepSelExerc->frxRep_Sel_Exerc->ShowReport();
    DM->QRep_Sel_Exerc->Close();
    DM->QRep_Abitura->Close();
    DM->QKod_Spec->Close();
    DM->QKod_Fac->Close();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TabSheet4Enter(TObject *Sender) {
    /* SaveBtBtn->Enabled = true;
     CancelBtBtn->Enabled = true;
     SaveBtBtn->Visible = true;
     CancelBtBtn->Visible = true; */
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::RdGrpSchoolClick(TObject *Sender) {
    // ��������� ���� �������� ���������
    if (DM->QAbitura->State == dsBrowse)
        DM->QAbitura->Edit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::RGrpVillageClick(TObject *Sender) {
    // ��������� �����/����
    if (DM->QAbitura->State == dsBrowse)
        DM->QAbitura->Edit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::CategoryAbCmbBxChange(TObject *Sender) {
    bool CategoryAbChange = false;
    // ��������� ��������� �����������
    if (ChangLog == 0) {
        if (MessageDlg("��������� ������� ��������� �������� ������� � �������� ����������\n \
         � ���������� ����� ������ � ������� ����� ������������.\n�� ������ ����������?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            CategoryAbChange = true;
        }
    }
    else
        CategoryAbChange = true;
    if (CategoryAbChange == true) {
        if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
            DM->QAbitura->Edit();
        } // end if dsBrowse

        // ������� �����������
        SngFrgCmbBx->ItemIndex = -1;
        EducatCmbBx->ItemIndex = -1;
        TermEduCmbBx->ItemIndex = -1;
        PriceCmbBx->ItemIndex = -1;
        KonkursCmbBx->ItemIndex = -1;
        SngFrgCmbBx->Enabled = true;
        switch (CategoryAbCmbBx->ItemIndex) {
        case 0: // ��������
            {
                pr_KategIf = 0; // ��������
                SitizenshipDBLkCmbBx->KeyValue = 22;
                DocumDBLkCmbBx->KeyValue = 1;
                SngFrgCmbBx->ItemIndex = 0;
                SngFrgCmbBx->Visible = false;
                SngFrgCmbBx->ItemIndex = 0;
                SngFrgLbl->Visible = false;
                EducatCmbBx->Enabled = true;
                EducatCmbBxChange(this);
                break;
            }
        case 1: // ����������
            {
                pr_KategIf = 1; // ����������
                SitizenshipDBLkCmbBx->KeyValue = NULL;
                DocumDBLkCmbBx->KeyValue = 2;
                SngFrgCmbBx->Visible = true;
                SngFrgCmbBx->ItemIndex = 1;
                SngFrgLbl->Visible = true;
                SngFrgCmbBxChange(this);
                break;
            }
        case 2: // ���
            {
                pr_KategIf = 2; // ���
                SitizenshipDBLkCmbBx->KeyValue = NULL;
                DocumDBLkCmbBx->KeyValue = NULL;
                SngFrgCmbBx->Visible = true;
                SngFrgLbl->Visible = true;
                SngFrgCmbBxChange(this);
                break;
            }
        case 3: // ���/���
            {
                pr_KategIf = 2; // ���
                SitizenshipDBLkCmbBx->KeyValue = NULL;
                DocumDBLkCmbBx->KeyValue = NULL;
                SngFrgCmbBx->Visible = true;
                SngFrgLbl->Visible = true;
                SngFrgCmbBxChange(this);
                break;
            }
        default:
            SngFrgCmbBx->Enabled = false;
        }
        if (ChangLog != 2)
            ChangLog = 1;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::TermEduCmbBxChange(TObject *Sender) {
    bool TermEduChange = false;
    // ��������� ����� ��������� �����������
    if (ChangLog == 0) {
        if (MessageDlg("��������� ������� ��������� �������� ������� � �������� ����������\n \
         � ���������� ����� ������ � ������� ����� ������������.\n�� ������ ����������?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            TermEduChange = true;
        }
    }
    else
        TermEduChange = true;
    if (TermEduChange == true) {
        if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
            DM->QAbitura->Edit();
        } // end if dsBrowse

        PriceCmbBx->ItemIndex = -1;
        KonkursCmbBx->ItemIndex = -1;
        PriceCmbBx->Items->Clear();
        PriceCmbBx->Items->Add("������");
        PriceCmbBx->Items->Add("�� ������");

        if ((pr_KategIf == 1) && (EducatCmbBx->ItemIndex == 3)) {
            // �� + �� = ������ �� ������
            PriceCmbBx->ItemIndex = 1;
            PriceCmbBx->Enabled = false;
        }
        else {
            PriceCmbBx->ItemIndex = -1;
            if (TermEduCmbBx->ItemIndex > -1)
                PriceCmbBx->Enabled = true;
            else
                PriceCmbBx->Enabled = false;
        }

        PriceCmbBxChange(this);
        if (ChangLog != 2)
            ChangLog = 1;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::PriceCmbBxChange(TObject *Sender) {
    bool PriceChange = false;
    // ��������� ����� ������
    if (ChangLog == 0) {
        if (MessageDlg("��������� ������� ��������� �������� ������� � �������� ����������\n \
         � ���������� ����� ������ � ������� ����� ������������.\n�� ������ ����������?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            PriceChange = true;
        }
    }
    else
        PriceChange = true;
    if (PriceChange == true) {
        if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
            DM->QAbitura->Edit();
        } // end if dsBrowse

        // �������
        KonkursCmbBx->ItemIndex = -1;
        KonkursCmbBx->Items->Clear();
        KonkursCmbBx->Items->Add("�����");
        KonkursCmbBx->Items->Add("��� ������������� ���������");
        // KonkursCmbBx->Items->Add("��� ��������");
        if (PriceCmbBx->ItemIndex > -1)
            KonkursCmbBx->Enabled = true;
        else
            KonkursCmbBx->Enabled = false;

        int pr_edu;
        switch (EducatCmbBx->ItemIndex) {
        case 0: // ��
            {
                pr_edu = 0;
                break;
            }
        case 1: // ���
            {
                pr_edu = 0;
                break;
            }
        case 2: // ������������� ��
            {
                pr_edu = 1;
                break;
            }
        case 3: // ��
            {
                pr_edu = 1;
                break;
            }
        case 4: // ���
            {
                pr_edu = 0;
                break;
            }
        }
        switch (pr_KategIf) {
            // ������� �����������
        case 0: // ��
            {
                switch (pr_edu) {
                    // �����������
                case 0: // ��/���
                    {
                        switch (TermEduCmbBx->ItemIndex) {
                            // ���� ��������� �����������
                        case 0: // ������
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("��� ��������");
                                        KonkursCmbBx->Items->Add("�������");
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("��� ��������");
                                        break;
                                    }
                                }
                                break;
                            }
                        case 1: // ����������� 2 ����
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("��� ��������");
                                        KonkursCmbBx->Items->Add("�������");
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("��� ��������");
                                        break;
                                    }
                                }
                                break;
                            }
                        case 2: // ����������� 3 ����
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("��� ��������");
                                        KonkursCmbBx->Items->Add("�������");
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("��� ��������");
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                case 1: // ��
                    {
                        switch (TermEduCmbBx->ItemIndex) {
                            // ���� ��������� �����������
                        case 0: // 1-� ����
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("��� ��������");
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("��� ��������");
                                        break;
                                    }
                                }
                                break;
                            }
                        case 1: // 2-1 � ����
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        KonkursCmbBx->ItemIndex = 1; // ���
                                        KonkursCmbBx->Enabled = false;
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        KonkursCmbBx->ItemIndex = 1; // ���
                                        KonkursCmbBx->Enabled = false;
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        case 1: // ����������
            {
                switch (pr_edu) {
                    // �����������
                case 0: // ��/���
                    {
                        switch (TermEduCmbBx->ItemIndex) {
                            // ���� ��������� �����������
                        case 0: // ������
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        KonkursCmbBx->ItemIndex = 0; // �����
                                        KonkursCmbBx->Enabled = false;
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        break;
                                    }
                                }
                                break;
                            }
                        case 1: // ����������� 2 ����
                        case 2: // ����������� 3 ����
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                case 1: // ��
                    {
                        switch (TermEduCmbBx->ItemIndex) {
                            // ���� ��������� �����������
                        case 0: // 1-� ����
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        break;
                                    }
                                }
                                break;
                            }
                        case 1: // 2-1 � ����
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        case 2: // ���
            {
                switch (pr_edu) {
                    // �����������
                case 0: // ��/���
                    {
                        switch (TermEduCmbBx->ItemIndex) {
                            // ���� ��������� �����������
                        case 0: // ������
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("��� ��������");
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("��� ��������");
                                        break;
                                    }
                                }
                                break;
                            }
                        case 1: // ����������� 2 ����
                        case 2: // ����������� 3 ����
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                case 1: // ��
                    {
                        switch (TermEduCmbBx->ItemIndex) {
                            // ���� ��������� �����������
                        case 0: // 1-� ����
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("��� ��������");
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("��� ��������");
                                        break;
                                    }
                                }
                                break;
                            }
                        case 1: // 2-1 � ����
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // ������
                                case 0: // ������
                                    {
                                        KonkursCmbBx->ItemIndex = 1; // ���
                                        KonkursCmbBx->Enabled = false;
                                        break;
                                    }
                                case 1: // �� ������
                                    {
                                        KonkursCmbBx->ItemIndex = 1; // ���
                                        KonkursCmbBx->Enabled = false;
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }

        KonkursCmbBxChange(this);
        if (ChangLog != 2)
            ChangLog = 1;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::TabSheet5Show(TObject *Sender) {
    // ������� �� �������� ������ ����������
    /* ExitBitBtn->Enabled = true;
     ExitBitBtn->Visible = true;
     SaveBtBtn->Enabled = false;
     CancelBtBtn->Enabled = false;
     SaveBtBtn->Visible = false;
     CancelBtBtn->Visible = false; */
    FIOReBitBtn->Caption = "";
    FIOSearchEdtChange(this);
    AbiturForm->Height = 700;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::FIOSearchEdtChange(TObject *Sender) {
    DM->FIOSearchQr->Close();
    // DM->FIOSearchQr->ParamByName("fio")->AsString = FIOSearchEdt->Text;
    DM->FIOSearchQr->ParamByName("n_fac")->AsSmallInt = nom_fac;
    DM->FIOSearchQr->Open();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::ReLoadAbiturPhoto() {
    // ������� ������ ����
    TMemoryStream* pms;
    Jpeg::TJPEGImage *jp;

    // ����� ����
    if (!(TBlobField*)DM->FIOSearchQrPHOTO->IsNull) {
        pms = new TMemoryStream;
        jp = new TJPEGImage;
        DM->FIOSearchQrPHOTO->SaveToStream(pms);
        pms->Seek(0, 0);
        FIOSearchPhImg->Picture->Graphic = jp;
        FIOSearchPhImg->Picture->Graphic->LoadFromStream(pms);
        FIOSearchPhImg->Visible = True;
        delete pms;
        delete jp;
        if ((FIOSearchPhImg->Picture->Width == 0) ||
            (FIOSearchPhImg->Picture->Height == 0))
            FIOSearchPhImg->Picture = NULL;
    }
    else
        FIOSearchPhImg->Picture = NULL;
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::DBGrid2DblClick(TObject *Sender) {
    int r;

    DM->QAbitura->Close();
    DM->QAbitura->SQL->Clear();
    DM->QAbitura->SQL->Add("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
            ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
            D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
            EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
            N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
            N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
            NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
            NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
            PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
            STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
            VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
            WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
            DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA \
        WHERE (N_FAC=:N_FAC) AND (STATUS=0 or STATUS=6) ORDER BY FAM, NAME, OTCH"
        );
    DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    DM->QAbitura->Open();

    // ������� ���� �� ����������� �� ������ �� ������
    // ����� �������� ����������� � ABITURA
    // !!! ����������? ����? �����?
    // �������� ���������? �����?

    FIOSearchEdt->Text = DM->FIOSearchQrFIO->AsString;
    DM->ID_from_QUEUE = DM->FIOSearchQrID_AB->Value;
    // DM->FIOSearchQrFAM->AsString + " " +
    // DM->FIOSearchQrNAME->AsString + " " + DM->FIOSearchQrOTCH->AsString;

    DM->AbiturCompQr->Close();
    DM->AbiturCompQr->ParamByName("id_ab_queue")->Value = DM->ID_from_QUEUE;
    DM->AbiturCompQr->Open();
    if (DM->AbiturCompQrNOMER_AB->Value > 0) { // ���������� ��� ���� � ABITURA
        Set<TLocateOption, 0, 1>flags;
        // flags << loCaseInsensitive << loPartialKey;
        DM->QAbitura->Locate("NOMER_AB", DM->AbiturCompQrNOMER_AB->Value,
            flags);
        if (DM->QAbituraNOMER_AB->Value != DM->AbiturCompQrNOMER_AB->Value) {
            ShowMessage(
                "��������� ������ ��� ������ �����������!\n���������� � ������������!");
        }
        else {
            if ((DM->FIOSearchQrN_FAC->Value == DM->AbiturCompQrN_FAC->Value) &&
                (DM->FIOSearchQrVID_EDU->Value ==
                DM->AbiturCompQrVID_EDU->Value) &&
                (DM->FIOSearchQrN_SPECIALIZ->Value ==
                DM->AbiturCompQrN_SPECIALIZ->Value) &&
                (DM->FIOSearchQrN_SPEC->Value == DM->AbiturCompQrN_SPEC->Value)
                && (DM->FIOSearchQrVID_EDU->Value ==
                DM->AbiturCompQrVID_EDU->Value) &&
                (DM->FIOSearchQrCATEGORY_AB->Value ==
                DM->AbiturCompQrCATEGORY_AB->Value) &&
                (DM->FIOSearchQrCATEGORY_IF->Value ==
                DM->AbiturCompQrCATEGORY_IF->Value) &&
                (DM->FIOSearchQrCATEGORY_EDU->Value ==
                DM->AbiturCompQrEDUCATION->Value) &&
                (DM->FIOSearchQrTERM_EDU->Value ==
                DM->AbiturCompQrTERM_EDU->Value) &&
                (DM->FIOSearchQrPRICE->Value == DM->AbiturCompQrPRICE->Value) &&
                (DM->FIOSearchQrKONKURS->Value ==
                DM->AbiturCompQrKONKURS->Value) &&
                (DM->AbiturCompQrSTATUS->Value != 6)) {
                // !!!��������� ������������� - ��� ������ � ������
                // ������� ������ � ������ - � 0
                ChangLog = -1;
            }
            else {
                ChangLog = 1;
            }
            // Set<TLocateOption, 0, 1>flags;

            // ���� - �� ��� ���������� ��� ������� ����� � ������ ������

            PageControl1->ActivePage = TabSheet2;
            RefreshControl();

            if (DM->QAbitura->State == dsBrowse)
                DM->QAbitura->Edit();

            // -----------------------------------------
            if (ChangLog == 1) {
                // �� �������� ������ ����������
                // ����� ��������� �����������
                FormEduCmbBx->ItemIndex = DM->FIOSearchQrVID_EDU->AsInteger;
                // ����������� �������������
                DM->QSpecializPlan_Priem->Close();
                DM->QSpecializPlan_Priem->ParamByName("VID_EDU")->AsSmallInt =
                    FormEduCmbBx->ItemIndex;
                DM->QSpecializPlan_Priem->ParamByName("FAC")->AsSmallInt =
                    nom_fac;
                DM->QSpecializPlan_Priem->Open();
                SpecializDBLookupCmbBx->KeyValue =
                    DM->FIOSearchQrN_SPECIALIZ->AsInteger;
                SpecializDBLookupCmbBx->Enabled = true;
                // ��������� �����������
                CategoryAbCmbBx->ItemIndex =
                    DM->FIOSearchQrCATEGORY_AB->AsInteger;
                // ��������� �����������
                if (DM->FIOSearchQrCATEGORY_IF->Value > -1)
                    SngFrgCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_IF->Value;
                else
                    SngFrgCmbBx->ItemIndex = -1;
                if (SngFrgCmbBx->ItemIndex == 0) {
                    SngFrgCmbBx->Visible = false;
                    SngFrgLbl->Visible = false;
                }
                else {
                    SngFrgCmbBx->Visible = true;
                    SngFrgLbl->Visible = true;
                }

                int CATEGORY_EDU_tmp = DM->FIOSearchQrCATEGORY_EDU->AsInteger;
                int TERM_EDU_tmp = DM->FIOSearchQrTERM_EDU->AsInteger;
                int PRICE_tmp = DM->FIOSearchQrPRICE->AsInteger;
                int KONKURS_tmp = DM->FIOSearchQrKONKURS->AsInteger;

                // EducatCmbBx->OnChange(this);

                // �����������
                EducatCmbBx->ItemIndex = CATEGORY_EDU_tmp;
                EducatCmbBx->Enabled = true;
                // ���� ��������� �����������
                if ((CATEGORY_EDU_tmp == 2) || (CATEGORY_EDU_tmp == 3)) {
                    Label64->Caption = "���� �����������:";
                    TermEduCmbBx->ItemIndex = TERM_EDU_tmp - 3;
                }
                else {
                    Label64->Caption = "���� ��������� �����������:";
                    TermEduCmbBx->ItemIndex = TERM_EDU_tmp;
                }
                TermEduCmbBx->Enabled = true;
                // ����� ������
                PriceCmbBx->ItemIndex = PRICE_tmp;
                PriceCmbBx->Enabled = true;
                // �������
                KonkursCmbBx->ItemIndex = KONKURS_tmp;
                KonkursCmbBx->Enabled = true;
                // ������� �������
                if (KonkursCmbBx->ItemIndex == 3) {
                    Label29->Visible = true;
                    CkRegionDBLkpCmbBx->Visible = true;
                }
                else {
                    Label29->Visible = false;
                    CkRegionDBLkpCmbBx->Visible = false;
                }
            }
        }
        // -------------------------
        if (DM->AbiturCompQrSTATUS->Value == 6) {
            /* FormEduCmbBx->Clear();
             FormEduCmbBx->Items->Add("�������");
             FormEduCmbBx->Items->Add("�������");

             CategoryAbCmbBx->Clear();
             CategoryAbCmbBx->Items->Add("��������");
             CategoryAbCmbBx->Items->Add("����������");
             CategoryAbCmbBx->Items->Add("���");
             CategoryAbCmbBx->Items->Add("���/���");

             SngFrgCmbBx->Clear();
             SngFrgCmbBx->Items->Add("��");
             SngFrgCmbBx->Items->Add("��");
             SngFrgCmbBx->Visible = false;
             SngFrgLbl->Visible = false;

             EducatCmbBx->Clear();
             EducatCmbBx->Items->Add("�������");
             EducatCmbBx->Items->Add("������� �����������");
             EducatCmbBx->Items->Add("������������� ������");
             EducatCmbBx->Items->Add("������");
             EducatCmbBx->Items->Add("���������������-�����������");

             TermEduCmbBx->Clear();
             TermEduCmbBx->Items->Add("������");
             TermEduCmbBx->Items->Add("����������� 2 ����");
             TermEduCmbBx->Items->Add("����������� 3 ����");

             PriceCmbBx->Clear();
             PriceCmbBx->Items->Add("������");
             PriceCmbBx->Items->Add("�� ������");

             KonkursCmbBx->Clear();
             KonkursCmbBx->Items->Add("�����");
             KonkursCmbBx->Items->Add("��� ������������� ���������");
             KonkursCmbBx->Items->Add("��� ��������");
             KonkursCmbBx->Items->Add("�������"); */

            // ������� ����
            TMemoryStream* pms;
            Jpeg::TJPEGImage *jp;
            if (!(TBlobField*)DM->FIOSearchQrPHOTO->IsNull) {
                pms = new TMemoryStream;
                jp = new TJPEGImage;
                DM->FIOSearchQrPHOTO->SaveToStream(pms);
                pms->Seek(0, 0);
                Image1->Picture->Graphic = jp;
                Image1->Picture->Graphic->LoadFromStream(pms);
                Image1->Visible = True;
                delete pms;
                delete jp;
                if ((Image1->Picture->Width == 0) ||
                    (Image1->Picture->Height == 0))
                    Image1->Picture = NULL;
            }
            else
                Image1->Picture = NULL;
            // �� �������� ������ ����������
            FamDBEdt->Text = DM->FIOSearchQrFAM->AsString;
            // �������
            NameDBEdt->Text = DM->FIOSearchQrNAME->AsString; // ���
            OtchDBEdt->Text = DM->FIOSearchQrOTCH->AsString;
            // ��������
            // ����� ��������� �����������
            FormEduCmbBx->ItemIndex = DM->FIOSearchQrVID_EDU->AsInteger;
            // ����������� �������������
            DM->QSpecializPlan_Priem->Close();
            DM->QSpecializPlan_Priem->ParamByName("VID_EDU")->AsSmallInt =
                FormEduCmbBx->ItemIndex;
            DM->QSpecializPlan_Priem->ParamByName("FAC")->AsSmallInt = nom_fac;
            DM->QSpecializPlan_Priem->Open();
            SpecializDBLookupCmbBx->KeyValue =
                DM->FIOSearchQrN_SPECIALIZ->AsInteger;
            SpecializDBLookupCmbBx->Enabled = true;
            // ��������� �����������
            CategoryAbCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_AB->AsInteger;
            // ��������� �����������
            if (DM->FIOSearchQrCATEGORY_IF->Value > -1)
                SngFrgCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_IF->Value;
            else
                SngFrgCmbBx->ItemIndex = -1;
            if (SngFrgCmbBx->ItemIndex == 0) {
                SngFrgCmbBx->Visible = false;
                SngFrgLbl->Visible = false;
            }
            else {
                SngFrgCmbBx->Visible = true;
                SngFrgLbl->Visible = true;
            }
            // �����������
            EducatCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_EDU->AsInteger;
            EducatCmbBx->Enabled = true;
            // ���� ��������� �����������
            if ((DM->FIOSearchQrCATEGORY_EDU->AsInteger == 2) ||
                (DM->FIOSearchQrCATEGORY_EDU->AsInteger == 3)) {
                Label64->Caption = "���� �����������:";
                TermEduCmbBx->ItemIndex =
                    DM->FIOSearchQrTERM_EDU->AsInteger - 3;
            }
            else {
                Label64->Caption = "���� ��������� �����������:";
                TermEduCmbBx->ItemIndex = DM->FIOSearchQrTERM_EDU->AsInteger;
            }
            TermEduCmbBx->Enabled = true;
            // ����� ������
            PriceCmbBx->ItemIndex = DM->FIOSearchQrPRICE->AsInteger;
            PriceCmbBx->Enabled = true;
            // �������
            KonkursCmbBx->ItemIndex = DM->FIOSearchQrKONKURS->AsInteger;
            KonkursCmbBx->Enabled = true;
            // ������� �������
            if (KonkursCmbBx->ItemIndex == 3) {
                Label29->Visible = true;
                CkRegionDBLkpCmbBx->Visible = true;
            }
            else {
                Label29->Visible = false;
                CkRegionDBLkpCmbBx->Visible = false;
            }

            // ���������� �� ��������� ������� ���� ������ ����������
            DM->QAbituraDATE_PRIEM->Value =
                DateTimeToSQLTimeStamp(StrToDate(cur_d.CurrentDate()));
            DBDateEdit1->Enabled = false;
            //

            NomGroupCmbBx->Clear();

            TabSheet1->TabVisible = false;
            TabSheet5->TabVisible = false;
            // DBNavigator1->Enabled = false;
            // DBNavigator3->Enabled = false;
            // DBNavigator4->Enabled = false;
            // PrintBtBtn->Visible = false;
            AddBtBtn->Enabled = false;

            FormEduCmbBx->SetFocus();

        }
    }
    else { // ����������� ��� � ABITURA
        // ������� ������ � ������ - � 2
        ChangLog = 2;
        NewAbitur(1);
    }
}

// ---------------------------------------------------------------------------
void __fastcall TDM::FIOSearchDSDataChange(TObject *Sender, TField *Field) {
    AbiturForm->ReLoadAbiturPhoto();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::NewAbitur(int pr_w) {
    // ����� ����������

    // pr_w = 0 - �� ������ ��������, 1 - �� �������� ������ ����������

    PageControl1->ActivePage = TabSheet2;
    // RefreshControl();  // !!! ���� - ��� ����������� � �������
    // if ���� �� ������� ������ dateOkonch - �������� ������ ���������!    ����������!!!
    // if (DateServer>=dateOkonch) EnabledTrue();

    /* if (nom_fac==4)
     {
     try
     {
     DM->BlockQ->Edit();
     DM->BlockQBLOCK->Value=0;
     DM->BlockQNOTE->Value="���������� ����������� " + DateServer;
     }
     catch(...)
     {
     ShowMessage("��������� ����! ��������� ��������!");
     }
     } */
    // PoleBlock();//��������� �������� ���� BLOCK

    // PressBtn(2); // ������� ������ ����� � ������ ������ �������
    st_ins = true; // ����� �������

    DM->QAbitura->Insert();

    FormEduCmbBx->Clear();
    FormEduCmbBx->Items->Add("�������");
    FormEduCmbBx->Items->Add("�������");

    CategoryAbCmbBx->Clear();
    CategoryAbCmbBx->Items->Add("��������");
    CategoryAbCmbBx->Items->Add("����������");
    CategoryAbCmbBx->Items->Add("���");
    CategoryAbCmbBx->Items->Add("���/���");

    SngFrgCmbBx->Clear();
    SngFrgCmbBx->Items->Add("��");
    SngFrgCmbBx->Items->Add("��");
    SngFrgCmbBx->Visible = false;
    SngFrgLbl->Visible = false;

    EducatCmbBx->Clear();
    EducatCmbBx->Items->Add("�������");
    EducatCmbBx->Items->Add("������� �����������");
    EducatCmbBx->Items->Add("������������� ������");
    EducatCmbBx->Items->Add("������");
    EducatCmbBx->Items->Add("���������������-�����������");

    TermEduCmbBx->Clear();
    TermEduCmbBx->Items->Add("������");
    TermEduCmbBx->Items->Add("����������� 2 ����");
    TermEduCmbBx->Items->Add("����������� 3 ����");

    PriceCmbBx->Clear();
    PriceCmbBx->Items->Add("������");
    PriceCmbBx->Items->Add("�� ������");

    KonkursCmbBx->Clear();
    KonkursCmbBx->Items->Add("�����");
    KonkursCmbBx->Items->Add("��� ������������� ���������");
    KonkursCmbBx->Items->Add("��� ��������");
    KonkursCmbBx->Items->Add("�������");

    if (pr_w) {
        // ������� ����
        TMemoryStream* pms;
        Jpeg::TJPEGImage *jp;
        if (!(TBlobField*)DM->FIOSearchQrPHOTO->IsNull) {
            pms = new TMemoryStream;
            jp = new TJPEGImage;
            DM->FIOSearchQrPHOTO->SaveToStream(pms);
            pms->Seek(0, 0);
            Image1->Picture->Graphic = jp;
            Image1->Picture->Graphic->LoadFromStream(pms);
            Image1->Visible = True;
            delete pms;
            delete jp;
            if ((Image1->Picture->Width == 0) || (Image1->Picture->Height == 0))
                Image1->Picture = NULL;
        }
        else
            Image1->Picture = NULL;
        // �� �������� ������ ����������
        FamDBEdt->Text = DM->FIOSearchQrFAM->AsString; // �������
        NameDBEdt->Text = DM->FIOSearchQrNAME->AsString; // ���
        OtchDBEdt->Text = DM->FIOSearchQrOTCH->AsString; // ��������
        // ����� ��������� �����������
        FormEduCmbBx->ItemIndex = DM->FIOSearchQrVID_EDU->AsInteger;
        // ����������� �������������
        DM->QSpecializPlan_Priem->Close();
        DM->QSpecializPlan_Priem->ParamByName("VID_EDU")->AsSmallInt =
            FormEduCmbBx->ItemIndex;
        DM->QSpecializPlan_Priem->ParamByName("FAC")->AsSmallInt = nom_fac;
        DM->QSpecializPlan_Priem->Open();
        SpecializDBLookupCmbBx->KeyValue =
            DM->FIOSearchQrN_SPECIALIZ->AsInteger;
        SpecializDBLookupCmbBx->Enabled = true;
        // ��������� �����������
        CategoryAbCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_AB->AsInteger;
        // ��������� �����������
        if (DM->FIOSearchQrCATEGORY_IF->Value > -1)
            SngFrgCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_IF->Value;
        else
            SngFrgCmbBx->ItemIndex = -1;
        if (SngFrgCmbBx->ItemIndex == 0) {
            SngFrgCmbBx->Visible = false;
            SngFrgLbl->Visible = false;
        }
        else {
            SngFrgCmbBx->Visible = true;
            SngFrgLbl->Visible = true;
        }
        // �����������
        EducatCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_EDU->AsInteger;
        EducatCmbBx->Enabled = true;
        // ���� ��������� �����������
        if ((DM->FIOSearchQrCATEGORY_EDU->AsInteger == 2) ||
            (DM->FIOSearchQrCATEGORY_EDU->AsInteger == 3)) {
            Label64->Caption = "���� �����������:";
            TermEduCmbBx->ItemIndex = DM->FIOSearchQrTERM_EDU->AsInteger - 3;
        }
        else {
            Label64->Caption = "���� ��������� �����������:";
            TermEduCmbBx->ItemIndex = DM->FIOSearchQrTERM_EDU->AsInteger;
        }
        TermEduCmbBx->Enabled = true;
        // ����� ������
        PriceCmbBx->ItemIndex = DM->FIOSearchQrPRICE->AsInteger;
        PriceCmbBx->Enabled = true;
        // �������
        KonkursCmbBx->ItemIndex = DM->FIOSearchQrKONKURS->AsInteger;
        KonkursCmbBx->Enabled = true;
        // ������� �������
        if (KonkursCmbBx->ItemIndex == 3) {
            Label29->Visible = true;
            CkRegionDBLkpCmbBx->Visible = true;
        }
        else {
            Label29->Visible = false;
            CkRegionDBLkpCmbBx->Visible = false;
        }
    }
    else {
        // �� ������ ��������
        // �������� ����������
        Image1->Picture = NULL;
        FamDBEdt->Text = ""; // �������
        NameDBEdt->Text = ""; // ���
        OtchDBEdt->Text = ""; // ��������
        // ����� ��������� �����������
        FormEduCmbBx->ItemIndex = -1;
        FormEduCmbBx->Enabled = true;
        // ��������� �����������
        CategoryAbCmbBx->ItemIndex = -1;
        CategoryAbCmbBx->Enabled = true;
        // ������� �����������
        SngFrgCmbBx->ItemIndex = -1;
        SngFrgCmbBx->Enabled = false;
        // �����������
        EducatCmbBx->ItemIndex = -1;
        EducatCmbBx->Enabled = false;
        // ���� ��������� �����������
        TermEduCmbBx->ItemIndex = -1;
        TermEduCmbBx->Enabled = false;
        // ����� ������
        PriceCmbBx->ItemIndex = -1;
        PriceCmbBx->Enabled = false;
        // �������
        KonkursCmbBx->ItemIndex = -1;
        KonkursCmbBx->Enabled = false;
        // ������� �������
        Label29->Visible = false;
        CkRegionDBLkpCmbBx->Visible = false;
    }

    // ��� add new record � ���� ����������� �������� ��
    // DM->QAbituraCITIZENSHIP->Value = 22;
    SitizenshipDBLkCmbBx->KeyValue = 22;
    // DM->QAbituraGRAGDAN->Value = "��";
    /* // ��� add new record �������� ���� ��������.
     DM->QAbituraOTCH->Value = ""; */
    // �������� ������ ������ �� ������������
    DM->QSertificat->Close();
    // ��� add new record � ���� Priv_One_Exam �������� ���
    // DM->QAbituraN_PRIVILEGE_EXAM->Value = 1;
    //
    UncheckCh();
    //
    // ���������� �� ��������� ������� ���� ������ ����������
    DM->QAbituraDATE_PRIEM->Value =
        DateTimeToSQLTimeStamp(StrToDate(cur_d.CurrentDate()));
    DBDateEdit1->Enabled = false;
    //
    // SpecializDBLookupCmbBx->Enabled = true;
    // DBEdit1->Enabled=true;
    // DBEdit2->SetFocus();

    // �������� ���� ������
    AdressRegEdt->Text = "";
    AdressLifeEdt->Text = "";
    // ������ ���������

    // LangRatCmbBx->ItemIndex = -1;

    /* FormEduCmbBx->Clear();
     FormEduCmbBx->Items->Add("�������");
     FormEduCmbBx->Items->Add("�������");
     FormEduCmbBx->ItemIndex = -1;
     ComboBox2->ItemIndex = -1; */
    NomGroupCmbBx->Clear();

    if (!pr_w) { // �� ������ ��������
        // ���
        KonkursCmbBx->ItemIndex = -1;
        PriceCmbBx->ItemIndex = -1;
        KonkursCmbBx->Enabled = false;

        Label29->Visible = false; // ��
        CkRegionDBLkpCmbBx->Visible = false;
    }
    // BitBtn5->Visible=false;
    if (nom_fac == 4) { // if �������� �������
        // �������������
        if (!pr_w) { // �� ������ ��������
            SpecializDBLookupCmbBx->KeyValue = 61;
            DM->QAbituraN_SPECIALIZ->Value = 61;
        }
        // ��� ������
        VidSportDBLookupCmbBx->KeyValue = 33; // �� ����������
    } // end if �������� �������

    else
        // else �������� ���
    {
        if (!pr_w) { // �� ������ ��������
            // �������������
            SpecializDBLookupCmbBx->Text == "";
        }
    } // end else
    // ������
    SportCategoryDBLookupCmboBx->KeyValue = 12;
    // DM->QAbituraN_SPORT_CATEGORY->Value = 12;

    TabSheet1->TabVisible = false;
    TabSheet5->TabVisible = false;
    // DBNavigator1->Enabled = false;
    // DBNavigator3->Enabled = false;
    // DBNavigator4->Enabled = false;
    // PrintBtBtn->Visible = false;
    AddBtBtn->Enabled = false;

    FormEduCmbBx->SetFocus();

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::FIOReBitBtnClick(TObject *Sender) {
    FIOSearchEdt->Text = "";
    DM->FIOSearchQr->Close();
    DM->FIOSearchQr->ParamByName("fio")->AsString = "";
    DM->FIOSearchQr->ParamByName("n_fac")->AsSmallInt = nom_fac;
    DM->FIOSearchQr->Open();
    FIOSearchEdt->Focused();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::SngFrgCmbBxChange(TObject *Sender) {
    bool SngFrgChange = false;
    // ��������� ������� �����������
    if (ChangLog == 0) {
        if (MessageDlg("��������� ������� ��������� �������� ������� � �������� ����������\n \
         � ���������� ����� ������ � ������� ����� ������������.\n�� ������ ����������?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            SngFrgChange = true;
        }
    }
    else
        SngFrgChange = true;
    if (SngFrgChange == true) {
        if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
            DM->QAbitura->Edit();
        } // end if dsBrowse

        switch (SngFrgCmbBx->ItemIndex) {
        case 0: // ���
            {
                pr_KategIf = 2;
                break;
            }
        case 1: // ����������
            {
                pr_KategIf = 1;
                break;
            }
        }

        // �����������
        EducatCmbBx->ItemIndex = -1;
		TermEduCmbBx->ItemIndex = -1;
        PriceCmbBx->ItemIndex = -1;
        KonkursCmbBx->ItemIndex = -1;
        if (SngFrgCmbBx->ItemIndex > -1)
            EducatCmbBx->Enabled = true;
        else
            EducatCmbBx->Enabled = false;

        EducatCmbBxChange(this);
        if (ChangLog != 2)
            ChangLog = 1;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::KonkursCmbBxChange(TObject *Sender) {
    bool KonkursChange = false;
    // ��������� ��������
    if (ChangLog == 0) { // �������������� ���������
        if (MessageDlg("��������� ������� ��������� �������� ������� � �������� ����������\n \
         � ���������� ����� ������ � ������� ����� ������������.\n�� ������ ����������?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            KonkursChange = true;
        }
    }
    else
        KonkursChange = true;
    if (KonkursChange == true) {
        if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
            DM->QAbitura->Edit();
        } // end if dsBrowse

        if (KonkursCmbBx->ItemIndex == 3) {
            DM->CkRegionQr->Close();
            DM->CkRegionQr->Open();
            Label29->Visible = true;
            CkRegionDBLkpCmbBx->Visible = true;
            CkRegionDBLkpCmbBx->Enabled = true;
        }
        else {
            Label29->Visible = false;
            CkRegionDBLkpCmbBx->Visible = false;
            CkRegionDBLkpCmbBx->Enabled = false;
        }
        if (ChangLog != 2)
            ChangLog = 1;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::DBGrid2DrawColumnCell(TObject *Sender,
    const TRect &Rect, int DataCol, TColumn *Column,
    Grids::TGridDrawState State) {
    // ��������� ����� ������
    if (DM->FIOSearchQrSTATUS_QUEUE->Value == 202) {
        // ��������� ������ ����������� ���������
        DBGrid2->Canvas->Brush->Color = clYellow;
        DBGrid2->Canvas->FillRect(Rect);
        if (Column->Alignment == taRightJustify) {
            DBGrid2->Canvas->TextOutA
                (Rect.Right - 2 - DBGrid2->Canvas->TextWidth
                (Column->Field->Text), Rect.Top + 2, Column->Field->Text);
        }
        else {
            DBGrid2->Canvas->TextOutA(Rect.Left + 2, Rect.Top + 2,
                Column->Field->Text);
        }
    }
    // ��������� ����� ������
    if (DM->FIOSearchQrSTATUS_QUEUE->Value == 304) {
        // ��������� ������ ����������� ���������
        DBGrid2->Canvas->Brush->Color = clLime;
        DBGrid2->Canvas->FillRect(Rect);
        if (Column->Alignment == taRightJustify) {
            DBGrid2->Canvas->TextOutA
                (Rect.Right - 2 - DBGrid2->Canvas->TextWidth
                (Column->Field->Text), Rect.Top + 2, Column->Field->Text);
        }
        else {
            DBGrid2->Canvas->TextOutA(Rect.Left + 2, Rect.Top + 2,
                Column->Field->Text);
        }
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::WithOutCmboBx1Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx2Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx3Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx4Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx5Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx6Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx7Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx8Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx9Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx10Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx11Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx12Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx13Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx14Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx15Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx16Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::OutCmboBx1Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OutCmboBx2Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OutCmboBx3Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OutCmboBx4Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OutCmboBx5Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OutCmboBx6Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OutCmboBx7Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::InfChekLstBxClickCheck(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::SchoolCmbBxChange(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::TownVillageCmbBxChange(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::AdressRegEdtChange(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::PlaceRDBEdtChange(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::AdressRegEdtExit(TObject *Sender) {
    if (ChangLog < 1) {
        // ������ � ��� ����� �� � ������ ��������� ��������
        DM->AdrLogLastQr->Close();
        DM->AdrLogLastQr->ParamByName("nomer_ab")->AsInteger =
            DM->QAbituraNOMER_AB->Value;
        DM->AdrLogLastQr->Open();
        DM->AddrLogUpQr->Close();
        DM->AddrLogUpQr->ParamByName("id_log")->AsInteger =
            DM->AdrLogLastQrID_LOG->Value;
        DM->AddrLogUpQr->ParamByName("address")->AsString = AdressRegEdt->Text;
        DM->AddrLogUpQr->Prepare();
        DM->AddrLogUpQr->ExecSQL();
        DM->AddrLogUpQr->Close();
        DM->AdrLogLastQr->Close();
    }
    AdresPapaDBEdt->Text = AdressRegEdt->Text;
    AdresMamaDBEdt->Text = AdressRegEdt->Text;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::NomDelaDBEdtChange(TObject *Sender) {
    // ��������� ������ ����
    NumDelaLbl->Caption = DM->NumDelaString(DM->QAbituraVID_EDU->Value,
        DM->QAbituraTERM_EDU->Value, DM->QAbituraPRICE->Value,
        DM->QAbituraNOM_DELA->Value);
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::SportCategoryDBLookupCmboBxExit(TObject *Sender) {
    if (ChangLog < 1) {
        // ������ � ��� ����� �� � ������ ��������� ��������
        DM->AdrLogLastQr->Close();
        DM->AdrLogLastQr->ParamByName("nomer_ab")->AsInteger =
            DM->QAbituraNOMER_AB->Value;
        DM->AdrLogLastQr->Open();
        DM->CategUpQr->Close();
        DM->CategUpQr->ParamByName("id_log")->AsInteger =
            DM->AdrLogLastQrID_LOG->Value;
        DM->CategUpQr->ParamByName("category")->AsString =
            SportCategoryDBLookupCmboBx->KeyValue;
        DM->CategUpQr->Prepare();
        DM->CategUpQr->ExecSQL();
        DM->CategUpQr->Close();
        DM->AdrLogLastQr->Close();
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::CkRegionDBLkpCmbBxExit(TObject *Sender) {
    if (ChangLog < 1) {
        // ������ � ��� ����� �� � ������ ��������� ��������
        DM->AdrLogLastQr->Close();
        DM->AdrLogLastQr->ParamByName("nomer_ab")->AsInteger =
            DM->QAbituraNOMER_AB->Value;
        DM->AdrLogLastQr->Open();
        DM->RegionUpCKQr->Close();
        DM->RegionUpCKQr->ParamByName("id_log")->AsInteger =
            DM->AdrLogLastQrID_LOG->Value;
        DM->RegionUpCKQr->ParamByName("n_ck")->AsString =
            CkRegionDBLkpCmbBx->KeyValue;
        DM->RegionUpCKQr->Prepare();
        DM->RegionUpCKQr->ExecSQL();
        DM->RegionUpCKQr->Close();
        DM->AdrLogLastQr->Close();
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::DBDateEdit1Change(TObject *Sender) {
    // DBDateEdit1->Time = StrToTime("00:00");
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::DBGrid2CellClick(TColumn *Column) {
    DM->FIOSearchQr->ParamByName("fio")->AsString =
		DM->FIOSearchQrFAM->Value + " " + DM->FIOSearchQrNAME->Value
	    + " " + DM -> FIOSearchQrOTCH->Value;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::PersonNumDBEdtChange (TObject * Sender)
{
    AnsiString
        personal =
            PersonNumDBEdt -> Text,
        key      =
            personal.SubString (
                personal.Length (),
                1
            );

    if (    key >= '�'
         && key <= '�'
       )
    {
        personal =
            personal.SubString (
                1,
                personal.Length() - 1
            );

        PersonNumDBEdt -> Text = personal;

        ShowMessage (
            "������ ����� ������ ��������� ������ ��������� �����!"
        );
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::BitBtn1Click(TObject *Sender) {
    DualListDlgDoc = new TDualListDlgDoc(this);
    DualListDlgDoc->SrcList->Items->Clear();
    DualListDlgDoc->DstList->Items->Clear();
    DM->ListDocFDQ->Close();
    DM->DocumFDQ->Close();
    DM->ListDocFDQ->ParamByName("NOMER_AB")->Value =
        DM->QAbituraNOMER_AB->Value;
    DM->DocumFDQ->ParamByName("NOMER_AB")->Value = DM->QAbituraNOMER_AB->Value;
    DM->ListDocFDQ->Open();
    DM->DocumFDQ->Open();
    // ��� ���������
    for (int i = 0; i < DM->ListDocFDQ->RecordCount; i++) {
        DualListDlgDoc->DstList->Items->AddObject(DM->ListDocFDQTEXT_DOC->Value,
            (TObject *)(DM->ListDocFDQN_DOC->Value));
        DM->ListDocFDQ->Next();
    } // for
    for (int i = 0; i < DM->DocumFDQ->RecordCount; i++) {
        DualListDlgDoc->SrcList->Items->AddObject(DM->DocumFDQTEXT_DOC->Value,
            (TObject *)(DM->DocumFDQN_DOC->Value));
        DM->DocumFDQ->Next();
    } // for

    DualListDlgDoc->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::CheckBox1Click(TObject *Sender) {
    if (CheckBox1->Checked) {
        Panel5->Visible = true;
        InfChekLstBx->Checked[7] = true;
    }
    else {
        Panel5->Visible = false;
        ComboBox1->ItemIndex = -1;
        ComboBox2->ItemIndex = -1;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::PageControl1Change(TObject *Sender) {
    if (ComboBox1->ItemIndex == 0 || ComboBox1->ItemIndex == 1) {
        InfChekLstBx->Checked[7] = true;
    }
    else
        InfChekLstBx->Checked[7] = false;

}



void __fastcall TAbiturForm::DistrictDBLkCmbBxExit (TObject * Sender)
{
    DM -> QType_locality -> Close();

    DM -> QType_locality -> Open();

    // if (DM -> QAbitura -> State == dsInsert)
    //     LocalityDBLkCmbBx -> KeyValue = -1;
}



void __fastcall TAbiturForm::TabSheet2Show (TObject * Sender)                   // ������� �� ��������  ������ ����
{
    /*
    ExitBitBtn->Enabled=true;
    ExitBitBtn->Visible=true;
    */
    /*
    SaveBtBtn->Enabled = true;
    CancelBtBtn->Enabled = true;
    SaveBtBtn->Visible = true;
    CancelBtBtn->Visible = true;
    */
    if (DM->QAbitura->State != dsInsert)
        RefreshControl();
    ActionList1->State = asNormal;
    // �������� ��������� ����� ������ ����������
    if (!st_developer & pole_block == 1)
        KonkursCmbBx->Enabled = false;
    // EnableDate();

    Image2->Visible = false;
    Image3->Visible = true;
    Panel6->Height = 220;                                                       // was 200 MOD HEIGHT HERE!!!!!!!
    Panel6->Top = 0;
    pan1 = true;

    Image4->Visible = true;
    Image5->Visible = false;
    Panel2->Height = 22;
    Panel2->Top = Panel6->Height;
    pan2 = false;

    Image6->Visible = true;
    Image7->Visible = false;
    Panel1->Height = 22;
    Panel1->Top = Panel2->Height + Panel2->Top;
    pan3 = false;

    Image8->Visible = true;
    Image9->Visible = false;
    Panel4->Height = 22;
    Panel4->Top = Panel1->Height + Panel1->Top;
    pan4 = false;

    Image10->Visible = true;
    Image11->Visible = false;
    Panel7->Height = 22;
    Panel7->Top = Panel4->Height + Panel4->Top;
    pan5 = false;

    Image12->Visible = true;
    Image13->Visible = false;
    Panel3->Height = 22;
    Panel3->Top = Panel7->Height + Panel7->Top;
    pan6 = false;

    Image14->Visible = true;
    Image15->Visible = false;
    Panel18->Height = 22;
    Panel18->Top = Panel3->Height + Panel3->Top;
    pan7 = false;

    AbiturForm->Height = Panel18->Top + Panel18->Height + 110;                  // HEIGHT HERE !!!!!!!!!!!!!!!!!!
}



void __fastcall TAbiturForm::RegionDBLookupCmbBxCloseUp (TObject * Sender)
{
    if (region_id != RegionDBLookupCmbBx -> KeyValue)
    {
        AddressForm -> DistrictDBLkCmbBx      -> KeyValue = 0;
        AddressForm -> Type_localityDBLkCmbBx -> KeyValue = 0;
        AddressForm -> LocalityDBLkCmbBx      -> KeyValue = 0;
        AddressForm -> Type_streetDBLkCmbBx   -> KeyValue = 0;
        AddressForm -> StreetDBLkCmbBx        -> KeyValue = 0;
    }

    if (RegionDBLookupCmbBx -> KeyValue == 8)                                   // Select '������ ����������'
        AdressRegEdt -> ReadOnly = false;
    else
    {
        AdressRegEdt -> ReadOnly = true;

        AddressForm =
            new TAddressForm(
                this,
                RegionDBLookupCmbBx
            );

        AddressForm -> ShowModal();

        if (AddressForm -> isAddressSaved ())
        {
            AdressRegEdt   -> Text = AddressForm  -> getAddress ();

            AdresPapaDBEdt -> Text = AdressRegEdt -> Text;
            AdresMamaDBEdt -> Text = AdressRegEdt -> Text;
        }
    }
}



void __fastcall TAbiturForm::CheckBox2Click (TObject * Sender)
{
    if (CheckBox2 -> Checked)
        AdressLifeEdt -> Text = AdressRegEdt -> Text;
    else
    {
        if (region_id != RegionDBLookupCmbBx -> KeyValue)
        {
            AddressLifeForm -> DistrictDBLkCmbBx      -> KeyValue = 0;
            AddressLifeForm -> Type_localityDBLkCmbBx -> KeyValue = 0;
            AddressLifeForm -> LocalityDBLkCmbBx      -> KeyValue = 0;
            AddressLifeForm -> Type_streetDBLkCmbBx   -> KeyValue = 0;
            AddressLifeForm -> StreetDBLkCmbBx        -> KeyValue = 0;
        }

        if (RegionDBLookupCmbBx -> KeyValue == 8)
            AdressLifeEdt -> ReadOnly = false;
        else
        {
            AdressLifeEdt -> ReadOnly = true;

            AddressForm =
                new TAddressForm(
                    this,
                    RegionDBLookupCmbBx
                );

//            AddressLifeForm = new TAddressLifeForm(this);
//
//            if (RegionDBLookupCmbBx -> KeyValue == 5)
//            {
//                AddressLifeForm -> Label48                     -> Visible = false;
//                AddressLifeForm -> Notice_RequiredRegion       -> Visible = false;
//
//                AddressLifeForm -> Label51                     -> Visible = false;
//                AddressLifeForm -> Notice_RequiredDistrict     -> Visible = false;
//
//                AddressLifeForm -> Label54                     -> Visible = false;
//                AddressLifeForm -> Notice_RequiredTypeLocality -> Visible = false;
//
//                AddressLifeForm -> Notice_RequiredLocality     -> Visible = false;
//                AddressLifeForm -> Type_streetDBLkCmbBx        -> Visible = true;
//                AddressLifeForm -> Type_streetDBLkCmbBx        -> Enabled = true;
//
//                DM -> QType_street -> Close();
//                DM -> QType_street -> Open();
//
//                AddressLifeForm -> Type_streetDBLkCmbBx -> KeyValue = 1;
//            }
//            else
//            {
//                AddressLifeForm -> Label48                     -> Visible = true;
//                AddressLifeForm -> Notice_RequiredRegion       -> Visible = true;
//
//                AddressLifeForm -> Label51                     -> Visible = true;
//                AddressLifeForm -> Notice_RequiredDistrict     -> Visible = true;
//
//                AddressLifeForm -> Label54                     -> Visible = true;
//                AddressLifeForm -> Notice_RequiredTypeLocality -> Visible = true;
//
//                AddressLifeForm -> Notice_RequiredLocality     -> Visible = true;
//                AddressLifeForm -> Type_streetDBLkCmbBx        -> Visible = false;
//                AddressLifeForm -> Type_streetDBLkCmbBx        -> Enabled = false;
//
//                DM -> QDistrict -> Close();
//                DM -> QDistrict ->
//                    ParamByName ("REGION") -> AsInteger =
//                            RegionDBLookupCmbBx -> KeyValue;
//                DM -> QDistrict -> Open();
//
//                if (DM -> QAbitura -> State == dsInsert)
//                    AddressLifeForm -> DistrictDBLkCmbBx -> KeyValue = -1;
//            }

            AddressLifeForm -> ShowModal();

            if (AddressLifeForm -> isAddressSaved ())
                AdressLifeEdt -> Text = AddressLifeForm -> getAddress ();
        }
    }
}



void __fastcall TAbiturForm::AdressLifeEdtClick (TObject * Sender)
{
    if (CheckBox2 -> Checked)
        AdressLifeEdt -> Text = AdressRegEdt -> Text;
    else
    {
        if (region_id != RegionDBLookupCmbBx -> KeyValue)
        {
            AddressLifeForm -> DistrictDBLkCmbBx      -> KeyValue = 0;
            AddressLifeForm -> Type_localityDBLkCmbBx -> KeyValue = 0;
            AddressLifeForm -> LocalityDBLkCmbBx      -> KeyValue = 0;
            AddressLifeForm -> Type_streetDBLkCmbBx   -> KeyValue = 0;
            AddressLifeForm -> StreetDBLkCmbBx        -> KeyValue = 0;
        }

        AddressLifeForm = new TAddressLifeForm(this);

        if (RegionDBLookupCmbBx -> KeyValue == 5)
        {
            AddressLifeForm -> Label48 -> Visible = false;
            AddressLifeForm -> Label51 -> Visible = false;
            AddressLifeForm -> Label54 -> Visible = false;

            AddressLifeForm -> DistrictDBLkCmbBx      -> Visible = false;
            AddressLifeForm -> Type_localityDBLkCmbBx -> Visible = false;
            AddressLifeForm -> LocalityDBLkCmbBx      -> Visible = false;

            AddressForm -> DistrictDBLkCmbBx      -> Visible = false;
            AddressForm -> Type_localityDBLkCmbBx -> Visible = false;
            AddressForm -> LocalityDBLkCmbBx      -> Visible = false;

            AddressForm -> Type_streetDBLkCmbBx   -> KeyValue = 1;
            AddressForm -> LocalityDBLkCmbBx      -> KeyValue = 1;

            DM -> QType_street -> Close();
            DM -> QType_street -> Open();
        }
        else
        {
            AddressLifeForm -> Label48 -> Visible = true;
            AddressLifeForm -> Label51 -> Visible = true;
            AddressLifeForm -> Label54 -> Visible = true;

            AddressLifeForm -> DistrictDBLkCmbBx      -> Visible = true;
            AddressLifeForm -> Type_localityDBLkCmbBx -> Visible = true;
            AddressLifeForm -> LocalityDBLkCmbBx      -> Visible = true;

            DM -> QDistrict -> Close();
            DM -> QDistrict ->
                ParamByName ("REGION") -> AsInteger =
                        RegionDBLookupCmbBx -> KeyValue;

            DM -> QDistrict -> Open();

            if (DM -> QAbitura -> State == dsInsert)
                AddressLifeForm -> DistrictDBLkCmbBx -> KeyValue = -1;
        }

        AddressLifeForm -> ShowModal();

        if (AddressLifeForm -> isAddressSaved ())
            AdressLifeEdt -> Text = AddressLifeForm -> getAddress ();
    }
}



void __fastcall TAbiturForm::Panel13Click (TObject * Sender)
{
    if (    AbiturForm -> Height + panH1 <= 1000
         || pan1                         == true
       )
    {
        Image2 -> Visible = !Image2 -> Visible;
        Image3 -> Visible = !Image3 -> Visible;

        pan1 = !pan1;

        Timer1 -> Enabled = true;
    }
}



void __fastcall TAbiturForm::Panel14Click (TObject * Sender)
{
    if (    AbiturForm -> Height + panH2 <= 1000
         || pan2                         == true
       )
    {
        Image4 -> Visible = !Image4 -> Visible;
        Image5 -> Visible = !Image5 -> Visible;

        pan2 = !pan2;

        Timer2 -> Enabled = true;
    }
}



void __fastcall TAbiturForm::Panel15Click(TObject *Sender) {
    if (AbiturForm->Height + panH3 <= 1000 || pan3 == true) {
        Image6->Visible = !Image6->Visible;
        Image7->Visible = !Image7->Visible;
        pan3 = !pan3;
        Timer3->Enabled = true;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel17Click(TObject *Sender) {
    if (AbiturForm->Height + panH4 <= 1000 || pan4 == true) {
        Image8->Visible = !Image8->Visible;
        Image9->Visible = !Image9->Visible;
        pan4 = !pan4;
        Timer4->Enabled = true;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel19Click(TObject *Sender) {
    if (AbiturForm->Height + panH5 <= 1000 || pan5 == true) {
        Image10->Visible = !Image10->Visible;
        Image11->Visible = !Image11->Visible;
        pan5 = !pan5;
        Timer5->Enabled = true;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel20Click(TObject *Sender) {
    if (AbiturForm->Height + panH6 <= 1000 || pan6 == true) {
        Image12->Visible = !Image12->Visible;
        Image13->Visible = !Image13->Visible;
        pan6 = !pan6;
        Timer6->Enabled = true;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel21Click(TObject *Sender) {
    if (AbiturForm->Height + panH7 <= 1000 || pan7 == true) {
        Image14->Visible = !Image14->Visible;
        Image15->Visible = !Image15->Visible;
        pan7 = !pan7;
        Timer7->Enabled = true;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Timer1Timer(TObject *Sender) {
    if (pan1 && Panel6->Height < panH1) {
        Panel6->Height += 10;
        Panel2->Top += 10;
        Panel1->Top += 10;
        Panel4->Top += 10;
        Panel7->Top += 10;
        Panel3->Top += 10;
        Panel18->Top += 10;
        AbiturForm->Height += 10;
    }
    if (!pan1 && Panel6->Height > 22) {
        Panel6->Height -= 10;
        Panel2->Top -= 10;
        Panel1->Top -= 10;
        Panel4->Top -= 10;
        Panel7->Top -= 10;
        Panel3->Top -= 10;
        Panel18->Top -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan1 && Panel6->Height < panH1) && !(!pan1 && Panel6->Height > 22)) {
        Timer1->Enabled = false;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Timer2Timer(TObject *Sender) {
    if (pan2 && Panel2->Height < panH2) {
        Panel2->Height += 10;
        Panel1->Top += 10;
        Panel4->Top += 10;
        Panel7->Top += 10;
        Panel3->Top += 10;
        Panel18->Top += 10;
        AbiturForm->Height += 10;
    }
    if (!pan2 && Panel2->Height > 22) {
        Panel2->Height -= 10;
        Panel1->Top -= 10;
        Panel4->Top -= 10;
        Panel7->Top -= 10;
        Panel3->Top -= 10;
        Panel18->Top -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan2 && Panel2->Height < panH2) && !(!pan2 && Panel2->Height > 22)) {
        Timer2->Enabled = false;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Timer3Timer(TObject *Sender) {
    if (pan3 && Panel1->Height < panH3) {
        Panel1->Height += 10;
        Panel4->Top += 10;
        Panel7->Top += 10;
        Panel3->Top += 10;
        Panel18->Top += 10;
        AbiturForm->Height += 10;
    }
    if (!pan3 && Panel1->Height > 22) {
        Panel1->Height -= 10;
        Panel4->Top -= 10;
        Panel7->Top -= 10;
        Panel3->Top -= 10;
        Panel18->Top -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan3 && Panel1->Height < panH3) && !(!pan3 && Panel1->Height > 22)) {
        Timer3->Enabled = false;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Timer4Timer(TObject *Sender) {
    if (pan4 && Panel4->Height < panH4) {
        Panel4->Height += 10;
        Panel7->Top += 10;
        Panel3->Top += 10;
        Panel18->Top += 10;
        AbiturForm->Height += 10;
    }
    if (!pan4 && Panel4->Height > 22) {
        Panel4->Height -= 10;
        Panel7->Top -= 10;
        Panel3->Top -= 10;
        Panel18->Top -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan4 && Panel4->Height < panH4) && !(!pan4 && Panel4->Height > 22)) {
        Timer4->Enabled = false;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Timer5Timer(TObject *Sender) {
    if (pan5 && Panel7->Height < panH5) {
        Panel7->Height += 10;
        Panel3->Top += 10;
        Panel18->Top += 10;
        AbiturForm->Height += 10;
    }
    if (!pan5 && Panel7->Height > 22) {
        Panel7->Height -= 10;
        Panel3->Top -= 10;
        Panel18->Top -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan5 && Panel7->Height < panH5) && !(!pan5 && Panel7->Height > 22)) {
        Timer5->Enabled = false;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Timer6Timer(TObject *Sender) {
    if (pan6 && Panel3->Height < panH6) {
        Panel3->Height += 10;
        Panel18->Top += 10;
        AbiturForm->Height += 10;
    }
    if (!pan6 && Panel3->Height > 22) {
        Panel3->Height -= 10;
        Panel18->Top -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan6 && Panel3->Height < panH6) && !(!pan6 && Panel3->Height > 22)) {
        Timer6->Enabled = false;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Timer7Timer(TObject *Sender) {
    if (pan7 && Panel18->Height < panH7) {
        Panel18->Height += 10;
        AbiturForm->Height += 10;
    }
    if (!pan7 && Panel18->Height > 22) {
        Panel18->Height -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan7 && Panel18->Height < panH7) && !(!pan7 && Panel18->Height > 22))
    {
        Timer7->Enabled = false;
    }

}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::WithOutCmboBx19Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::WithOutCmboBx20Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::WithOutCmboBx21Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::WithOutCmboBx22Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
void __fastcall TAbiturForm::WithOutCmboBx23Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Panel15DblClick(TObject *Sender) {
    Image4->Visible = !Image4->Visible;
    Image5->Visible = !Image5->Visible;
    if (pan2)
        pan2 = !pan2;
    Timer2->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel17DblClick(TObject *Sender) {
    Image6->Visible = !Image6->Visible;
    Image7->Visible = !Image7->Visible;
    if (pan3)
        pan3 = !pan3;
    Timer3->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel19DblClick(TObject *Sender) {
    Image8->Visible = !Image8->Visible;
    Image9->Visible = !Image9->Visible;
    if (pan4)
        pan4 = !pan4;
    Timer4->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel20DblClick(TObject *Sender) {
    Image10->Visible = !Image10->Visible;
    Image11->Visible = !Image11->Visible;
    if (pan5)
        pan5 = !pan5;
    Timer5->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel21DblClick(TObject *Sender) {
    Image12->Visible = !Image12->Visible;
    Image13->Visible = !Image13->Visible;
    if (pan6)
        pan6 = !pan6;
    Timer6->Enabled = true;
}
