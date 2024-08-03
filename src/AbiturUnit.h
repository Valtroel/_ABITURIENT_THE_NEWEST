#pragma once
#ifndef ABITUR_UNIT_H
#define ABITUR_UNIT_H

#include <ActnList.hpp>
#include <AppEvnts.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
#include <System.Actions.hpp>
#include <Vcl.CheckLst.hpp>
// #include <Vcl.DBLookup.hpp>
#include <Vcl.Imaging.jpeg.hpp>


#include "properties.hpp"


void __fastcall VidKonkurs (                                                    // установка конкурса (вызывается если у платников общий конкурс (т.е. oplata_konkurs == 0))
        TComboBox * KonkursCmbBx,
        TComboBox * PriceCmbBx,
        TComboBox * ComboBox1
    );



class TAbiturForm
    : public TForm
{
__published:
    TAction            * Action1;
    TAction            * Action2;

    TActionList        * ActionList1;

    TApplicationEvents * ApplicationEvents1;

    TBevel             * Bevel1;

    TBitBtn            * AddBtBtn;
    TBitBtn            * BitBtn3;
    TBitBtn            * BitBtn9;
    TBitBtn            * CancelBtBtn;
    TBitBtn            * ExitBitBtn;
    TBitBtn            * FIOReBitBtn;
    TBitBtn            * PrintBtBtn;
    TBitBtn            * ReInsideFacBtBtn;
    TBitBtn            * RestorlistBtBtn;
    TBitBtn            * SaveBtBtn;
    TBitBtn            * TookDocBtBtn1;
    TBitBtn            * TookDocBtBtn2;

    TButton            * AbitSelBtn;

    TCheckBox          * CheckBox1;
    TCheckBox          * CheckBox2;

    TCheckListBox      * InfChekLstBx;

    TComboBox          * CategoryAbCmbBx;
    TComboBox          * ComboBox1;
    TComboBox          * ComboBox2;
    TComboBox          * EducatCmbBx;
    TComboBox          * FormEduCmbBx;
    TComboBox          * KonkursCmbBx;
    TComboBox          * NomGroupCmbBx;
    TComboBox          * OutCmboBx1;
    TComboBox          * OutCmboBx2;
    TComboBox          * OutCmboBx3;
    TComboBox          * OutCmboBx4;
    TComboBox          * OutCmboBx5;
    TComboBox          * OutCmboBx6;
    TComboBox          * OutCmboBx7;
    TComboBox          * PriceCmbBx;
    TComboBox          * SchoolCmbBx;
    TComboBox          * SngFrgCmbBx;
    TComboBox          * TermEduCmbBx;
    TComboBox          * TownVillageCmbBx;
    TComboBox          * WithOutCmboBx1;
    TComboBox          * WithOutCmboBx2;
    TComboBox          * WithOutCmboBx3;
    TComboBox          * WithOutCmboBx4;
    TComboBox          * WithOutCmboBx5;
    TComboBox          * WithOutCmboBx6;
    TComboBox          * WithOutCmboBx7;
    TComboBox          * WithOutCmboBx8;
    TComboBox          * WithOutCmboBx9;
    TComboBox          * WithOutCmboBx10;
    TComboBox          * WithOutCmboBx11;
    TComboBox          * WithOutCmboBx12;
    TComboBox          * WithOutCmboBx13;
    TComboBox          * WithOutCmboBx14;
    TComboBox          * WithOutCmboBx15;
    TComboBox          * WithOutCmboBx16;
    TComboBox          * WithOutCmboBx17;
    TComboBox          * WithOutCmboBx18;
    TComboBox          * WithOutCmboBx19;
    TComboBox          * WithOutCmboBx20;
    TComboBox          * WithOutCmboBx21;
    TComboBox          * WithOutCmboBx22;
    TComboBox          * WithOutCmboBx23;

    TDBComboBox        * PolDBCmbBx;

    TDBEdit            * AdresMamaDBEdt;
    TDBEdit            * AdresPapaDBEdt;
    TDBEdit            * AveragScoreDBEdt;
    TDBEdit            * BirthdayDBDateEdit;
    TDBEdit            * DateOKBDtEdt;
    TDBEdit            * DateVDBDtEdt;
    TDBEdit            * DBDateEdit1;
    TDBEdit            * DBEditNumAb;
    TDBEdit            * DBEditPol;
    TDBEdit            * DBEditSpec;
    TDBEdit            * FamDBEdt;
    TDBEdit            * MamaDBEdt;
    TDBEdit            * NameDBEdt;
    TDBEdit            * NameEduMiddleDBEdt;
    TDBEdit            * NameEduSpecDBEdt;
    TDBEdit            * NomAttestDBEdt;
    TDBEdit            * NomDelaDBEdt;
    TDBEdit            * NomDiplomDBEdt;
    TDBEdit            * OrganVDBEdt;
    TDBEdit            * OtchDBEdt;
    TDBEdit            * PapaDBEdt;
    TDBEdit            * PasportDBEdt;
    TDBEdit            * PersonNumDBEdt;
    TDBEdit            * PhoneDBEdt;
    TDBEdit            * StagSpecDBEdtEh;
    TDBEdit            * WhenEduMiddleDBEdt;
    TDBEdit            * WhenEduSpecDBEdt;
    TDBEdit            * WhereEduMiddleDBEdt;
    TDBEdit            * WhereEduSpecDBEdt;
    TDBEdit            * WorkBeforeDBEdt;

    TDBGrid            * DBGrid1;
    TDBGrid            * DBGrid2;
    TDBGrid            * DBGrid3;

    TDBLookupComboBox  * CkRegionDBLkpCmbBx;
    TDBLookupComboBox  * DocumDBLkCmbBx;
    TDBLookupComboBox  * LangvDBLkpCmbBx;
    TDBLookupComboBox  * RegionDBLookupCmbBx;
    TDBLookupComboBox  * SitizenshipDBLkCmbBx;
    TDBLookupComboBox  * SpecializDBLookupCmbBx;
    TDBLookupComboBox  * SportCategoryDBLookupCmboBx;
    TDBLookupComboBox  * VidSportDBLookupCmbBx;

    TDBNavigator       * DBNavigator2;

    TEdit              * AdressLifeEdt;
    TEdit              * AdressRegEdt;
    TEdit              * Edit1;
    TEdit              * FIOSearchEdt;

    TGroupBox          * GroupBox1;
    TGroupBox          * GroupBox2;
    TGroupBox          * GroupBox3;
    TGroupBox          * GroupBox4;

    TImage             * FIOSearchPhImg;
    TImage             * Image1;
    TImage             * Image2;
    TImage             * Image3;
    TImage             * Image4;
    TImage             * Image5;
    TImage             * Image6;
    TImage             * Image7;
    TImage             * Image8;
    TImage             * Image9;
    TImage             * Image10;
    TImage             * Image11;
    TImage             * Image12;
    TImage             * Image13;
    TImage             * Image14;
    TImage             * Image15;

    TLabel             * FIOSearchLbl;
    TLabel             * Label1;
    TLabel             * Label2;
    TLabel             * Label3;
    TLabel             * Label4;
    TLabel             * Label5;
    TLabel             * Label6;
    TLabel             * Label7;
    TLabel             * Label8;
    TLabel             * Label9;
    TLabel             * Label10;
    TLabel             * Label12;
    TLabel             * Label14;
    TLabel             * Label15;
    TLabel             * Label16;
    TLabel             * Label17;
    TLabel             * Label19;
    TLabel             * Label20;
    TLabel             * Label21;
    TLabel             * Label22;
    TLabel             * Label23;
    TLabel             * Label24;
    TLabel             * Label25;
    TLabel             * Label26;
    TLabel             * Label28;
    TLabel             * Label29;
    TLabel             * Label30;
    TLabel             * Label32;
    TLabel             * Label33;
    TLabel             * Label35;
    TLabel             * Label36;
    TLabel             * Label37;
    TLabel             * Label38;
    TLabel             * Label39;
    TLabel             * Label41;
    TLabel             * Label43;
    TLabel             * Label44;
    TLabel             * Label45;
    TLabel             * Label46;
    TLabel             * Label47;
    TLabel             * Label49;
    TLabel             * Label50;
    TLabel             * Label52;
    TLabel             * Label55;
    TLabel             * Label58;
    TLabel             * Label59;
    TLabel             * Label61;
    TLabel             * Label63;
    TLabel             * Label64;
    TLabel             * Label65;
    TLabel             * Label66;
    TLabel             * Label67;
    TLabel             * Lbl_14_symbols;
    TLabel             * NumDelaLbl;
    TLabel             * OutLbl1;
    TLabel             * OutLbl2;
    TLabel             * OutLbl3;
    TLabel             * OutLbl4;
    TLabel             * OutLbl5;
    TLabel             * OutLbl6;
    TLabel             * OutLbl7;
    TLabel             * SchoolLbl;
    TLabel             * SngFrgLbl;
    TLabel             * SportcategLbl;
    TLabel             * TownVillageLbl;
    TLabel             * VidSportLbl;
    TLabel             * WithOutLbl1;
    TLabel             * WithOutLbl2;
    TLabel             * WithOutLbl3;
    TLabel             * WithOutLbl4;
    TLabel             * WithOutLbl5;
    TLabel             * WithOutLbl6;
    TLabel             * WithOutLbl7;
    TLabel             * WithOutLbl8;
    TLabel             * WithOutLbl9;
    TLabel             * WithOutLbl10;
    TLabel             * WithOutLbl11;
    TLabel             * WithOutLbl12;
    TLabel             * WithOutLbl13;
    TLabel             * WithOutLbl14;
    TLabel             * WithOutLbl15;
    TLabel             * WithOutLbl16;
    TLabel             * WithOutLbl17;
    TLabel             * WithOutLbl18;
    TLabel             * WithOutLbl19;
    TLabel             * WithOutLbl20;
    TLabel             * WithOutLbl21;
    TLabel             * WithOutLbl22;
    TLabel             * WithOutLbl23;

    TOpenPictureDialog * OpenPictureDialog1;

    TPageControl       * PageControl1;

    TPanel             * Panel1;
    TPanel             * Panel2;
    TPanel             * Panel3;
    TPanel             * Panel4;
    TPanel             * Panel5;
    TPanel             * Panel6;
    TPanel             * Panel7;
    TPanel             * Panel8;
    TPanel             * Panel9;
    TPanel             * Panel10;
    TPanel             * Panel11;
    TPanel             * Panel13;
    TPanel             * Panel14;
    TPanel             * Panel15;
    TPanel             * Panel16;
    TPanel             * Panel17;
    TPanel             * Panel18;
    TPanel             * Panel19;
    TPanel             * Panel20;
    TPanel             * Panel21;
    TPanel             * PanelCtrlGrp;

    TPrintDialog       * PrintDialog1;
    TPrintDialog       * PrintDialog2;

    TRadioGroup        * RadioGroup1;
    TRadioGroup        * RdGrpCtrlExerc1;
    TRadioGroup        * RdGrpCtrlExerc2;
    TRadioGroup        * RdGrpCtrlExerc3;

    TScrollBar         * ScrollBar1;

    TShape             * Shape4;
    TShape             * Shape5;
    TShape             * Shape7;

    TSpeedButton       * SpeedButton1;
    TSpeedButton       * SpeedButton2;

    TTabSheet          * TabSheet1;
    TTabSheet          * TabSheet2;
    TTabSheet          * TabSheet4;
    TTabSheet          * TabSheet5;

    TTimer             * Timer1;
    TTimer             * Timer2;
    TTimer             * Timer3;
    TTimer             * Timer4;
    TTimer             * Timer5;
    TTimer             * Timer6;
    TTimer             * Timer7;

    void __fastcall AddBtBtnClick                   (TObject * Sender);
    void __fastcall AdressLifeEdtClick              (TObject * Sender);
    void __fastcall AdressRegEdtChange              (TObject * Sender);
    void __fastcall AdressRegEdtExit                (TObject * Sender);
    void __fastcall ApplicationEvents1Message       (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn1Click                    (TObject * Sender);
    void __fastcall BitBtn9Click                    (TObject * Sender);
    void __fastcall CancelBtBtnClick                (TObject * Sender);
    void __fastcall CategoryAbCmbBxChange           (TObject * Sender);
    void __fastcall Ch3Enter                        (TObject * Sender);
    void __fastcall Ch5Enter                        (TObject * Sender);
    void __fastcall Ch6Enter                        (TObject * Sender);
    void __fastcall Ch7Enter                        (TObject * Sender);
    void __fastcall Ch8Enter                        (TObject * Sender);
    void __fastcall Ch9Enter                        (TObject * Sender);
    void __fastcall CheckBox1Click                  (TObject * Sender);
    void __fastcall CheckBox2Click                  (TObject * Sender);
    void __fastcall CkRegionDBLkpCmbBxExit          (TObject * Sender);
    void __fastcall clictNotConcoursClickCheck      (TObject * Sender);
    void __fastcall clictNotConcoursEnter           (TObject * Sender);
    void __fastcall clistAddAwardsClickCheck        (TObject * Sender);
    void __fastcall clistAddAwardsEnter             (TObject * Sender);
    void __fastcall clistddEnrollingClickCheck      (TObject * Sender);
    void __fastcall clistddEnrollingEnter           (TObject * Sender);
    void __fastcall clistGIACClickCheck             (TObject * Sender);
    void __fastcall clistGIACEnter                  (TObject * Sender);
    void __fastcall clistNotExamsClickCheck         (TObject * Sender);
    void __fastcall clistNotExamsEnter              (TObject * Sender);
    void __fastcall DBDateEdit1Change               (TObject * Sender);
    void __fastcall DBGrid1DblClick                 (TObject * Sender);
    void __fastcall DBGrid1TitleClick               (TColumn * Column);
    void __fastcall DBGrid2CellClick                (TColumn * Column);
    void __fastcall DBGrid2DblClick                 (TObject * Sender);
    void __fastcall DBGrid2DrawColumnCell           (
                  TObject               * Sender,
            const TRect                 & Rect,
                  int                     DataCol,
                  TColumn               * Column,
                  Grids::TGridDrawState   State
        );
    void __fastcall DBGrid3DblClick                 (TObject * Sender);
    void __fastcall DBGrid3Enter                    (TObject * Sender);
    //void __fastcall DBGrid4DblClick                 (TObject * Sender);
    void __fastcall DBNavigator1Click               (
            TObject      * Sender,
            TNavigateBtn   Button
        );
    void __fastcall DistrictDBLkCmbBxExit           (TObject * Sender);
    void __fastcall Edit1Change                     (TObject * Sender);
    void __fastcall EducatCmbBxChange               (TObject * Sender);
    void __fastcall EducatCmbBxEnter                (TObject * Sender);
    void __fastcall ExitBitBtnClick                 (TObject * Sender);
    void __fastcall FamDBEdtExit                    (TObject * Sender);
    void __fastcall FamDBEdtKeyDown                 (
            TObject     * Sender,
            WORD        & Key,
            TShiftState   Shift
        );
    void __fastcall FIOReBitBtnClick                (TObject * Sender);
    void __fastcall FIOSearchEdtChange              (TObject * Sender);
    void __fastcall FormActivate                    (TObject * Sender);
    void __fastcall FormCanResize                   (
            TObject * Sender,
            int     & NewWidth,
            int     & NewHeight,
            bool    & Resize
        );
    void __fastcall FormClose                       (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate                      (TObject * Sender);
    void __fastcall FormEduCmbBxChange              (TObject * Sender);
    void __fastcall FormEduCmbBxExit                (TObject * Sender);
    void __fastcall Image1Click                     (TObject * Sender);
    void __fastcall InfChekLstBxClickCheck          (TObject * Sender);
    void __fastcall KonkursCmbBxChange              (TObject * Sender);
    void __fastcall KonkursRdGrpClick               (TObject * Sender);
    void __fastcall KonkursRdGrpEnter               (TObject * Sender);
    void __fastcall NameDBEdtExit                   (TObject * Sender);
    void __fastcall NameDBEdtKeyDown                (
            TObject     * Sender,
            WORD        & Key,
            TShiftState   Shift
        );
    void __fastcall NomDelaDBEdtChange              (TObject * Sender);
    void __fastcall NomGroupCmbBxEnter              (TObject * Sender);
    void __fastcall OtchDBEdtExit                   (TObject * Sender);
    void __fastcall OutCmboBx1Change                (TObject * Sender);
    void __fastcall OutCmboBx2Change                (TObject * Sender);
    void __fastcall OutCmboBx3Change                (TObject * Sender);
    void __fastcall OutCmboBx4Change                (TObject * Sender);
    void __fastcall OutCmboBx5Change                (TObject * Sender);
    void __fastcall OutCmboBx6Change                (TObject * Sender);
    void __fastcall OutCmboBx7Change                (TObject * Sender);
    void __fastcall PageControl1Change              (TObject * Sender);
    void __fastcall Panel13Click                    (TObject * Sender);
    void __fastcall Panel14Click                    (TObject * Sender);
    void __fastcall Panel15Click                    (TObject * Sender);
    void __fastcall Panel15DblClick                 (TObject * Sender);
    void __fastcall Panel17Click                    (TObject * Sender);
    void __fastcall Panel17DblClick                 (TObject * Sender);
    void __fastcall Panel19Click                    (TObject * Sender);
    void __fastcall Panel19DblClick                 (TObject * Sender);
    void __fastcall Panel20Click                    (TObject * Sender);
    void __fastcall Panel20DblClick                 (TObject * Sender);
    void __fastcall Panel21Click                    (TObject * Sender);
    void __fastcall Panel21DblClick                 (TObject * Sender);
    void __fastcall PersonNumDBEdtChange            (TObject * Sender);
    void __fastcall PersonNumDBEdtExit              (TObject * Sender);
    void __fastcall PlaceRDBEdtChange               (TObject * Sender);
    void __fastcall Pr1Enter                        (TObject * Sender);
    void __fastcall Pr2Enter                        (TObject * Sender);
    void __fastcall Pr3Enter                        (TObject * Sender);
    void __fastcall Pr4Enter                        (TObject * Sender);
    void __fastcall Pr5Enter                        (TObject * Sender);
    void __fastcall Pr6Enter                        (TObject * Sender);
    void __fastcall Pr7Enter                        (TObject * Sender);
    void __fastcall Pr8Enter                        (TObject * Sender);
    void __fastcall Pr9Enter                        (TObject * Sender);
    void __fastcall Pr10Enter                       (TObject * Sender);
    void __fastcall Pr11Enter                       (TObject * Sender);
    void __fastcall Pr12Enter                       (TObject * Sender);
    void __fastcall Pr13Enter                       (TObject * Sender);
    void __fastcall Pr14Enter                       (TObject * Sender);
    void __fastcall Pr15Enter                       (TObject * Sender);
    void __fastcall Pr16Enter                       (TObject * Sender);
    void __fastcall Pr17Enter                       (TObject * Sender);
    void __fastcall Pr18Enter                       (TObject * Sender);
    void __fastcall Pr19Enter                       (TObject * Sender);
    void __fastcall Pr20Enter                       (TObject * Sender);
    void __fastcall Pr21Enter                       (TObject * Sender);
    void __fastcall Pr22Enter                       (TObject * Sender);
    void __fastcall Pr23Enter                       (TObject * Sender);
    void __fastcall PriceCmbBxChange                (TObject * Sender);
    void __fastcall PriceRdGrpEnter                 (TObject * Sender);
    void __fastcall PrintBtBtnClick                 (TObject * Sender);
    void __fastcall RadioGroup1Click                (TObject * Sender);
    void __fastcall RdGrpSchoolClick                (TObject * Sender);
    void __fastcall RegionDBLookupCmbBxCloseUp      (TObject * Sender);
    void __fastcall ReInsideFacBtBtnClick           (TObject * Sender);
    void __fastcall RestorlistBtBtnClick            (TObject * Sender);
    void __fastcall RGrpVillageClick                (TObject * Sender);
    void __fastcall SaveBtBtnClick                  (TObject * Sender);
    void __fastcall SchoolCmbBxChange               (TObject * Sender);
    void __fastcall SngFrgCmbBxChange               (TObject * Sender);
    void __fastcall SpecializDBLookupCmbBxExit      (TObject * Sender);
    void __fastcall SpeedButton1Click               (TObject * Sender);         // new TSredBalForm (this)
    void __fastcall SpeedButton2Click               (TObject * Sender);         // new TSertificatForm (this)
    void __fastcall SportCategoryDBLookupCmboBxExit (TObject * Sender);
    void __fastcall StagSpecDBEdtEhExit             (TObject * Sender);
    void __fastcall TabSheet1Enter                  (TObject * Sender);
    void __fastcall TabSheet1Show                   (TObject * Sender);
    void __fastcall TabSheet2Enter                  (TObject * Sender);
    void __fastcall TabSheet2Show                   (TObject * Sender);
    void __fastcall TabSheet3Enter                  (TObject * Sender);
    void __fastcall TabSheet3Show                   (TObject * Sender);
    void __fastcall TabSheet4Enter                  (TObject * Sender);
    void __fastcall TabSheet4Show                   (TObject * Sender);
    void __fastcall TabSheet5Show                   (TObject * Sender);
    void __fastcall TermEduCmbBxChange              (TObject * Sender);
    void __fastcall Timer1Timer                     (TObject * Sender);
    void __fastcall Timer2Timer                     (TObject * Sender);
    void __fastcall Timer3Timer                     (TObject * Sender);
    void __fastcall Timer4Timer                     (TObject * Sender);
    void __fastcall Timer5Timer                     (TObject * Sender);
    void __fastcall Timer6Timer                     (TObject * Sender);
    void __fastcall Timer7Timer                     (TObject * Sender);
    void __fastcall TookDocBtBtn1Click              (TObject * Sender);
    void __fastcall TookDocBtBtn2Click              (TObject * Sender);
    void __fastcall TownVillageCmbBxChange          (TObject * Sender);
    void __fastcall Vk1Click                        (TObject * Sender);
    void __fastcall Vk1Enter                        (TObject * Sender);
    void __fastcall Vk4Enter                        (TObject * Sender);
    void __fastcall Vk5Enter                        (TObject * Sender);
    void __fastcall Vk6Enter                        (TObject * Sender);
    void __fastcall WhereEduMiddleDBEdtClick        (TObject * Sender);
    void __fastcall WithOutCmboBx1Change            (TObject * Sender);
    void __fastcall WithOutCmboBx2Change            (TObject * Sender);
    void __fastcall WithOutCmboBx3Change            (TObject * Sender);
    void __fastcall WithOutCmboBx4Change            (TObject * Sender);
    void __fastcall WithOutCmboBx5Change            (TObject * Sender);
    void __fastcall WithOutCmboBx6Change            (TObject * Sender);
    void __fastcall WithOutCmboBx7Change            (TObject * Sender);
    void __fastcall WithOutCmboBx8Change            (TObject * Sender);
    void __fastcall WithOutCmboBx9Change            (TObject * Sender);
    void __fastcall WithOutCmboBx10Change           (TObject * Sender);
    void __fastcall WithOutCmboBx11Change           (TObject * Sender);
    void __fastcall WithOutCmboBx12Change           (TObject * Sender);
    void __fastcall WithOutCmboBx13Change           (TObject * Sender);
    void __fastcall WithOutCmboBx14Change           (TObject * Sender);
    void __fastcall WithOutCmboBx15Change           (TObject * Sender);
    void __fastcall WithOutCmboBx16Change           (TObject * Sender);
    void __fastcall WithOutCmboBx19Change           (TObject * Sender);
    void __fastcall WithOutCmboBx20Change           (TObject * Sender);
    void __fastcall WithOutCmboBx21Change           (TObject * Sender);
    void __fastcall WithOutCmboBx22Change           (TObject * Sender);
    void __fastcall WithOutCmboBx23Change           (TObject * Sender);
    void __fastcall Wo1Enter                        (TObject * Sender);
    void __fastcall Wo2Enter                        (TObject * Sender);
    void __fastcall Wo3Enter                        (TObject * Sender);
    void __fastcall Wo4Enter                        (TObject * Sender);
	void __fastcall Wo5Enter                        (TObject * Sender);

private:
    AnsiString __fastcall Chek_Vid_Edu ();                                      // возвращает вид обучения
    // int        __fastcall langv_ball   (                                        // возврат оценки по иностранному языку (зависит от fl)
    //         int ind,
    //         int
    //     );
public:
    __fastcall TAbiturForm (TComponent * Owner);

    void __fastcall max_nom_dela      ();
    int  __fastcall NewWo             ();                                       // процедура записывает БВИ,ВК и др. в БД
    void __fastcall RefreshCh         ();
    void __fastcall RefreshControl    ();
    void __fastcall BitBtnShow        ();
    void __fastcall EnableDate        ();                                       // Показ компонентов для разработчика c 26.07.2010
    void __fastcall EnabledTrue       ();                                       // показ компонентов для изменения данных по абитуриенту
    void __fastcall MsgEdit           ();                                       // запрет изменения данных
    void __fastcall NameBtn           ();                                       // назначение имен кнопкам в зависимости от факультета (у Института туризма другие названия)
    void __fastcall NewAbitur         (int pr_w     );
    void __fastcall PoleBlock         ();                                       // получение значения поля BLOCK
    void __fastcall PressBtn          (int press_btn);
    void __fastcall ReLoadAbiturPhoto ();
    void __fastcall UncheckCh         ();
};

extern PACKAGE TAbiturForm * AbiturForm;

#endif  // ABITUR_UNIT_H
