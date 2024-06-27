#pragma once
#ifndef DM_STAT_UNIT_H
#define DM_STAT_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <Db.hpp>
#include <DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>



class TDMStat
    : public TDataModule
{
__published:
    TDataSource    * DSCount_Ball_Examen;
    TDataSource    * DSCount_CK;
    TDataSource    * DSCount_Diplom;
    TDataSource    * DSCount_Gimn;
    TDataSource    * DSCount_Gorod;
    TDataSource    * DSCount_Medal;
    TDataSource    * DSCount_Olimp;
    TDataSource    * DSCount_Platn;
    TDataSource    * DSCount_PO;
    TDataSource    * DSCount_Region;
    TDataSource    * DSCount_Selo;
    TDataSource    * DSCount_special_ab;
    TDataSource    * DSCount_Stag;
    TDataSource    * DSCount_Test;
    TDataSource    * DSF1kAb;
    TDataSource    * DSF1kKol;
    TDataSource    * DSProtokol;
    TDataSource    * DSQ_GK_All;
    TDataSource    * DSQ_GK_Konkurs;
    TDataSource    * DSQ_GK_Medal;
    TDataSource    * DSQ_GK_Plan_CK;
    TDataSource    * DSQ_GK_Plan;
    TDataSource    * DSQCount_Ball_Rus_Bel_old;
    TDataSource    * DSQCount_Ball_Rus_Bel;
    TDataSource    * DSQF2_All_Sdal;
    TDataSource    * DSQF2_CK;
    TDataSource    * DSQF2_Sdal;
    TDataSource    * DSQF2_Zach;
    TDataSource    * DSQSpecial;
    TDataSource    * DSRegion_Stat;
    TDataSource    * DSSpecial;
    TDataSource    * DSSport_Categ;
    TDataSource    * DSSvod_Ved;
    TDataSource    * DSSvod_Ved2;

    TFDQuery       * CitizenQr;
    TFDQuery       * FullGrpS1Qr;
    TFDQuery       * LastLogQr;
    TFDQuery       * ProtokolAllQr;
    TFDQuery       * ProtokolCkQr;
    TFDQuery       * ProtokolQr;
    TFDQuery       * Q_GK_All;
    TFDQuery       * Q_GK_Konkurs;
    TFDQuery       * Q_GK_Medal;
    TFDQuery       * Q_GK_Plan_CK;
    TFDQuery       * Q_GK_Plan;
    TFDQuery       * QBall_prohod;
    TFDQuery       * QCount_Ball_Examen;
    TFDQuery       * QCount_Ball_Rus_Bel_old;
    TFDQuery       * QCount_Ball_Rus_Bel;
    TFDQuery       * QCount_Ball;
    TFDQuery       * QCount_CK;
    TFDQuery       * QCount_Diplom;
    TFDQuery       * QCount_Gimn;
    TFDQuery       * QCount_Gorod;
    TFDQuery       * QCount_High;
    TFDQuery       * QCount_Medal;
    TFDQuery       * QCount_Olimp;
    TFDQuery       * QCount_Platn;
    TFDQuery       * QCount_PO;
    TFDQuery       * QCount_Region;
    TFDQuery       * QCount_RUOR;
    TFDQuery       * QCount_Selo;
    TFDQuery       * QCount_special_ab;
    TFDQuery       * QCount_Stag;
    TFDQuery       * QCount_Test;
    TFDQuery       * QCount_VK;
    TFDQuery       * QCountAll;
    TFDQuery       * QCountSpecNapravl;
    TFDQuery       * QF1kAb;
    TFDQuery       * QF1kKol;
    TFDQuery       * QF2_All_Sdal;
    TFDQuery       * QF2_CK;
    TFDQuery       * QF2_Sdal;
    TFDQuery       * QF2_Zach;
    TFDQuery       * QProtokol;
    TFDQuery       * QRegion_Stat;
    TFDQuery       * QSpec_Dir;
    TFDQuery       * QSpecial;
    TFDQuery       * QSpecializ_for_Spec_Dir;
    TFDQuery       * QSpecializ_for_Spec;
    TFDQuery       * QSport_Categ;
    TFDQuery       * QSvod_Ved;
    TFDQuery       * QSvod_Ved2;
    TFDQuery       * QZachisl_Sertificat;

    TFDStoredProc  * Giaz01SP;
    TFDStoredProc  * GIAZ021SP;
    TFDStoredProc  * Giaz022SP;

    TFDTable       * TSpecial;

    TFloatField    * QBall_prohodMIN;

    TIntegerField  * Giaz01SPS_3S;
    TIntegerField  * Giaz01SPS_B_2;
    TIntegerField  * Giaz01SPS_B_ALL;
    TIntegerField  * Giaz01SPS_B_CK;
    TIntegerField  * Giaz01SPS_P;
    TIntegerField  * GIAZ021SPS_16;
    TIntegerField  * GIAZ021SPS_17;
    TIntegerField  * GIAZ021SPS_ALL;
    TIntegerField  * Giaz022SPS_21;
    TIntegerField  * Giaz022SPS_22_26;
    TIntegerField  * Giaz022SPS_27;
    TIntegerField  * Giaz022SPS_ALL;
    TIntegerField  * LastLogQrID_LOG;
    TIntegerField  * ProtokolCkQrNOMER_AB;
    TIntegerField  * ProtokolQrNOMER_AB;
    TIntegerField  * Q_GK_AllCOUNT;
    TIntegerField  * Q_GK_KonkursCOUNT;
    TIntegerField  * Q_GK_MedalCOUNT;
    TIntegerField  * Q_GK_Plan_CKSUM;
    TIntegerField  * Q_GK_PlanSUM;
    TIntegerField  * QCount_Ball_ExamenCOUNT;
    TIntegerField  * QCount_Ball_Rus_Bel_oldCOUNT;
    TIntegerField  * QCount_Ball_Rus_BelCOUNT;
    TIntegerField  * QCount_BallN_YA;
    TIntegerField  * QCount_BallN0;
    TIntegerField  * QCount_BallN1;
    TIntegerField  * QCount_BallN10_9;
    TIntegerField  * QCount_BallN2;
    TIntegerField  * QCount_BallN3_2;
    TIntegerField  * QCount_BallN4_3;
    TIntegerField  * QCount_BallN5_4;
    TIntegerField  * QCount_BallN6_5;
    TIntegerField  * QCount_BallN7_6;
    TIntegerField  * QCount_BallN8_7;
    TIntegerField  * QCount_BallN9_8;
    TIntegerField  * QCount_CKCOUNT;
    TIntegerField  * QCount_DiplomCOUNT;
    TIntegerField  * QCount_GimnCOUNT;
    TIntegerField  * QCount_GorodCOUNT;
    TIntegerField  * QCount_HighCOUNT;
    TIntegerField  * QCount_MedalCOUNT;
    TIntegerField  * QCount_OlimpCOUNT;
    TIntegerField  * QCount_PlatnCOUNT;
    TIntegerField  * QCount_POCOUNT;
    TIntegerField  * QCount_RegionCOUNT;
    TIntegerField  * QCount_RUORCOUNT;
    TIntegerField  * QCount_SeloCOUNT;
    TIntegerField  * QCount_special_abCOUNT;
    TIntegerField  * QCount_StagCOUNT;
    TIntegerField  * QCount_TestCOUNT;
    TIntegerField  * QCount_VKCOUNT;
    TIntegerField  * QCountAllCOUNT;
    TIntegerField  * QCountSpecNapravlSUM;
    TIntegerField  * QF1kAbCOUNT_NOMER_AB;
    TIntegerField  * QF1kKolSUM_KOL_PLACE;
    TIntegerField  * QF2_All_SdalCOUNT;
    TIntegerField  * QF2_CKCOUNT;
    TIntegerField  * QF2_SdalCOUNT;
    TIntegerField  * QF2_ZachCOUNT;
    TIntegerField  * QRegion_StatCOUNT;
    TIntegerField  * QSpec_DirN_SPEC_DIR;
    TIntegerField  * QSpec_DirN_SPEC;
    TIntegerField  * QSpecializ_for_Spec_DirN_SPEC_DIR;
    TIntegerField  * QSpecializ_for_SpecN_SPEC_DIR;
    TIntegerField  * QZachisl_SertificatNOMER_AB;

    TLargeintField * QSport_CategCOUNT;

    TSmallintField * FullGrpS1QrCATEGORY_IF;
    TSmallintField * FullGrpS1QrCITIZENSHIP;
    TSmallintField * FullGrpS1QrKONKURS;
    TSmallintField * FullGrpS1QrN_SPORT_CATEGORY;
    TSmallintField * FullGrpS1QrPRICE;
    TSmallintField * FullGrpS1QrTERM_EDU;
    TSmallintField * ProtokolAllQrTERM_EDU;
    TSmallintField * ProtokolCkQrTERM_EDU;
    TSmallintField * ProtokolQrCATEGORY_IF;
    TSmallintField * ProtokolQrKONKURS;
    TSmallintField * ProtokolQrNOM_DELA;
    TSmallintField * ProtokolQrPRICE;
    TSmallintField * ProtokolQrTERM_EDU;
    TSmallintField * QCount_Ball_ExamenN_SPECIALIZ;
    TSmallintField * QCount_Ball_ExamenVID_EDU;
    TSmallintField * QCount_Ball_Rus_Bel_oldN_SPECIALIZ;
    TSmallintField * QCount_Ball_Rus_Bel_oldVID_EDU;
    TSmallintField * QCount_Ball_Rus_BelN_SPECIALIZ;
    TSmallintField * QCount_Ball_Rus_BelVID_EDU;
    TSmallintField * QCount_CKN_SPEC;
    TSmallintField * QCount_DiplomN_SPEC;
    TSmallintField * QCount_GimnN_SPEC;
    TSmallintField * QCount_GorodN_SPEC;
    TSmallintField * QCount_HighN_SPEC;
    TSmallintField * QCount_MedalN_SPEC;
    TSmallintField * QCount_OlimpN_SPEC;
    TSmallintField * QCount_PlatnN_SPEC;
    TSmallintField * QCount_PON_SPEC;
    TSmallintField * QCount_RegionN_SPEC;
    TSmallintField * QCount_RUORN_SPEC;
    TSmallintField * QCount_SeloN_SPEC;
    TSmallintField * QCount_special_abN_SPEC;
    TSmallintField * QCount_special_abPRICE;
    TSmallintField * QCount_StagN_SPEC;
    TSmallintField * QCount_TestN_SPEC;
    TSmallintField * QCountSpecNapravlTEXT;
    TSmallintField * QF1kAbCOPY_AT;
    TSmallintField * QF2_All_SdalN_SPEC;
    TSmallintField * QF2_CKN_SPEC;
    TSmallintField * QF2_SdalN_SPEC;
    TSmallintField * QF2_ZachN_SPEC;
    TSmallintField * QProtokolOUT_N_DEL;
    TSmallintField * QRegion_StatKONKURS;
    TSmallintField * QRegion_StatN_REGION;
    TSmallintField * QRegion_StatN_SPECIALIZ;
    TSmallintField * QSpecializ_for_Spec_DirN_FAC;
    TSmallintField * QSpecializ_for_Spec_DirN_SPEC;
    TSmallintField * QSpecializ_for_Spec_DirN_SPECIALIZ;
    TSmallintField * QSpecializ_for_SpecN_FAC;
    TSmallintField * QSpecializ_for_SpecN_SPEC;
    TSmallintField * QSpecializ_for_SpecN_SPECIALIZ;
    TSmallintField * QSpecialN_SPEC;
    TSmallintField * QSport_CategN_SPECIALIZ;
    TSmallintField * QZachisl_SertificatBALLS;
    TSmallintField * QZachisl_SertificatKONKURS;
    TSmallintField * QZachisl_SertificatN_FOUND;
    TSmallintField * QZachisl_SertificatN_PREDMET;
    TSmallintField * QZachisl_SertificatRUS_BEL;
    TSmallintField * TSpecialN_SPEC;
    TSmallintField * TSpecialOLD_NUM;

    TStringField   * CitizenQrNAME;
    TStringField   * ProtokolAllQrFAM;
    TStringField   * ProtokolAllQrNAME;
    TStringField   * ProtokolAllQrOTCH;
    TStringField   * ProtokolCkQrFAM;
    TStringField   * ProtokolCkQrNAME;
    TStringField   * ProtokolCkQrOTCH;
    TStringField   * ProtokolQrFAM;
    TStringField   * ProtokolQrNAME;
    TStringField   * ProtokolQrOTCH;
    TStringField   * QCount_Ball_ExamenBALL;
    TStringField   * QCount_Ball_Rus_Bel_oldBALL;
    TStringField   * QCount_Ball_Rus_BelBALL;
    TStringField   * QF1kAbFAC1;
    TStringField   * QF1kAbSPECIAL;
    TStringField   * QF1kKolFAC1;
    TStringField   * QF1kKolSPECIAL;
    TStringField   * QProtokolOUT_FAM;
    TStringField   * QProtokolOUT_NAME;
    TStringField   * QProtokolOUT_OTCH;
    TStringField   * QProtokolOUT_VK;
    TStringField   * QProtokolOUT_WITHOUT;
    TStringField   * QSpec_DirCODE_SPEC_DIR;
    TStringField   * QSpec_DirSPEC_DIR_FULL;
    TStringField   * QSpec_DirSPEC_DIR;
    TStringField   * QSpecialCODE_SPEC;
    TStringField   * QSpecializ_for_Spec_DirCODE_SPECIALIZ;
    TStringField   * QSpecializ_for_Spec_DirSPECIAL_DIRECTION;
    TStringField   * QSpecializ_for_Spec_DirSPECIAL_SKLON;
    TStringField   * QSpecializ_for_Spec_DirSPECIAL;
    TStringField   * QSpecializ_for_SpecCODE_SPECIALIZ;
    TStringField   * QSpecializ_for_SpecSPECIAL_DIRECTION;
    TStringField   * QSpecializ_for_SpecSPECIAL_SKLON;
    TStringField   * QSpecializ_for_SpecSPECIAL;
    TStringField   * QSpecialSPEC;
    TStringField   * QSport_CategSPEC1;
    TStringField   * QSport_CategSPORT_CATEGORY;
    TStringField   * QZachisl_SertificatFAM;
    TStringField   * QZachisl_SertificatNAME;
    TStringField   * QZachisl_SertificatNOMER_S;
    TStringField   * QZachisl_SertificatOTCH;
    TStringField   * QZachisl_SertificatPASPORT;
    TStringField   * QZachisl_SertificatSERIA_S;
    TStringField   * QZachisl_SertificatTEXT_PREDMET;
    TStringField   * TSpecialCODE_SPEC;
    TStringField   * TSpecialSPEC;
private:
public:
    __fastcall TDMStat (TComponent * Owner);

    float            SQL_Min_Ball   (                                           // выдать проходной балл
            int vid_educ,
            int sp,
            int price,
            int konkurs
        );
    void  __fastcall FIO            (                                           // Обработка ФИО с приведением его в нужный формат
            AnsiString   text,
            TFDQuery   * q,
            AnsiString   pole
        );
    void  __fastcall Prohod_Ball    (                                           // определить какой балл занести (общий или раздельный конкурс)
            float gorod,
            float selo,
            int   stroka,
            int   price_twokurs
        );
    void  __fastcall SQL_Build      (
            int form,
            int vid,
            int param
        );
    void  __fastcall SQL_BuildCycle (                                           // создать Query
            int form,
            int vid,
            int rec_spec,
            int param
        );
    void  __fastcall SQL_Run        (
            TFDQuery   * q,
            AnsiString   sql,
            int          vid_educ,
            int          stb,
            int          str
        );
    void  __fastcall SQL_RunCycle   (                                           // выполнить Query и занести данные в Excel
            TFDQuery   * q,
            AnsiString   sql,
            int          vid_educ,
            int          rec_spec,
            int          stb
        );
};

extern PACKAGE TDMStat * DMStat;

#endif  // DM_STAT_UNIT_H