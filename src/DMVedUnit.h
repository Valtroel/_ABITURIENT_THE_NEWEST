#pragma once
#ifndef DM_VED_UNIT_H
#define DM_VED_UNIT_H


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



class TDMVed
    : public TDataModule
{
__published:
    TDataSource        * DSGorod;
    TDataSource        * DSPredm;
    TDataSource        * DSPredmet_Ball;
    TDataSource        * DSQ_All_Mas;
    TDataSource        * DSQKol_Place;

    TDateField         * QDateCAST;

    TFDQuery           * GIAZ2_1_3Qr;
    TFDQuery           * GIAZ2_1_4_ckQr;
    TFDQuery           * GIAZ2_1_4Qr;
    TFDQuery           * GIAZ2_1_5_ckQr;
    TFDQuery           * GIAZ2_1_5Qr;
    TFDQuery           * GIAZ2_1_6Qr;
    TFDQuery           * GIAZ2_1_7Qr;
    TFDQuery           * GIAZ2_1_9Qr;
    TFDQuery           * GIAZ2_1_10Qr;
    TFDQuery           * GIAZ2_1_11Qr;
    TFDQuery           * GIAZ2_1_12Qr;
    TFDQuery           * GIAZ2_1_13Qr;
    TFDQuery           * GIAZ2_1_14Qr;
    TFDQuery           * GIAZ2_2_1ckQr;
    TFDQuery           * GIAZ2_2_1Qr;
    TFDQuery           * GIAZ2_2_2Qr;
    TFDQuery           * GIAZ2_2_4Qr;
    TFDQuery           * GIAZ2_2_6Qr;
    TFDQuery           * GIAZ2_3_1ckQr;
    TFDQuery           * GIAZ2_3_1Qr;
    TFDQuery           * GIAZ2_3_2Qr;
    TFDQuery           * GIAZ2_3_3Qr;
    TFDQuery           * GIAZ2_3_4Qr;
    TFDQuery           * GIAZ2_3_6Qr;
    TFDQuery           * GIAZ2_3_7Qr;
    TFDQuery           * GIAZ2_3_8Qr;
    TFDQuery           * GIAZ2_3_9Qr;
    TFDQuery           * GIAZ2_4_1Qr;
    TFDQuery           * GIAZ2_4_3Qr;
    TFDQuery           * GIAZ2_4_5Qr;
    TFDQuery           * GIAZ2_4_6Qr;
    TFDQuery           * GIAZ2_4_8Qr;
    TFDQuery           * GIAZ2_4_10Qr;
    TFDQuery           * GIAZInQr;
    TFDQuery           * QAll_Mas;
    TFDQuery           * QDate;
    TFDQuery           * QGIAC3Sert;
    TFDQuery           * QGIACBvi;
    TFDQuery           * QGIACInAll;
    TFDQuery           * QGIACInDate;
    TFDQuery           * QGIACMinBall;
    TFDQuery           * QGIACViIn;
    TFDQuery           * QGIACViPlus;
    TFDQuery           * QGorod;
    TFDQuery           * QGroupProtokol;
    TFDQuery           * QKol_Place;
    TFDQuery           * QKol_Place15;
    TFDQuery           * QKonkPlus;
    TFDQuery           * QKonkPlus2;
    TFDQuery           * QKonkurs;
    TFDQuery           * QKonkurs2V;
    TFDQuery           * QKonkurs12;
    TFDQuery           * QKonkurs34;
    TFDQuery           * QPeopleProtocol;
    TFDQuery           * QPredm;
    TFDQuery           * QPredmet_Ball;
    TFDQuery           * QSpec1;

    TFDStoredProc      * GIAZ2_1_1StrdPrc;

    TFloatField        * QGIACMinBallMIN;
    TFloatField        * QGorodOUT_MID_B;
    TFloatField        * QGorodOUT_STAG_SP;
    TFloatField        * QGorodOUT_STAG;
    TFloatField        * QGorodOUT_SUM_BALL;
    TFloatField        * QKonkurs2VOUT_MIDDLE_BALL;
    TFloatField        * QKonkurs2VOUT_STAG_SPEC;
    TFloatField        * QKonkurs2VOUT_STAG;
    TFloatField        * QKonkurs2VOUT_SUM_BALL;
    TFloatField        * QKonkurs12OUT_MIDDLE_BALL;
    TFloatField        * QKonkurs12OUT_STAG_SPEC;
    TFloatField        * QKonkurs12OUT_STAG;
    TFloatField        * QKonkurs12OUT_SUM_BALL;
    TFloatField        * QKonkurs34OUT_MIDDLE_BALL;
    TFloatField        * QKonkurs34OUT_STAG_SPEC;
    TFloatField        * QKonkurs34OUT_STAG;
    TFloatField        * QKonkurs34OUT_SUM_BALL;
    TFloatField        * QKonkursOUT_MIDDLE_BALL;
    TFloatField        * QKonkursOUT_STAG_SPEC;
    TFloatField        * QKonkursOUT_STAG;
    TFloatField        * QKonkursOUT_SUM_BALL;
    TFloatField        * QPredmet_BallOUT_BALL;

    TIntegerField      * GIAZ2_1_1StrdPrcSUM1;
    TIntegerField      * QAll_MasOUT_N_AB_ALL_M;
    TIntegerField      * QGIAC3SertCOUNT;
    TIntegerField      * QGIACBviCOUNT;
    TIntegerField      * QGIACInAllCOUNT;
    TIntegerField      * QGIACInDateCOUNT;
    TIntegerField      * QGIACViInCOUNT;
    TIntegerField      * QGIACViPlusCOUNT;
    TIntegerField      * QGorodOUT_CENTRE;
    TIntegerField      * QGorodOUT_NOMER_AB;
    TIntegerField      * QKonkurs2VOUT_N_DELA;
    TIntegerField      * QKonkurs2VOUT_NOMER_AB;
    TIntegerField      * QKonkurs12OUT_N_DELA;
    TIntegerField      * QKonkurs12OUT_NOMER_AB;
    TIntegerField      * QKonkurs34OUT_N_DELA;
    TIntegerField      * QKonkurs34OUT_NOMER_AB;
    TIntegerField      * QKonkursOUT_N_DELA;
    TIntegerField      * QKonkursOUT_NOMER_AB;

    TLargeintField     * GIAZ2_1_3QrCOUNT;
    TLargeintField     * GIAZ2_1_4_ckQrCOUNT;
    TLargeintField     * GIAZ2_1_4QrCOUNT;
    TLargeintField     * GIAZ2_1_5_ckQrCOUNT;
    TLargeintField     * GIAZ2_1_5QrCOUNT;
    TLargeintField     * GIAZ2_1_6QrCOUNT;
    TLargeintField     * GIAZ2_1_7QrCOUNT;
    TLargeintField     * GIAZ2_1_9QrCOUNT;
    TLargeintField     * GIAZ2_1_10QrCOUNT;
    TLargeintField     * GIAZ2_1_11QrCOUNT;
    TLargeintField     * GIAZ2_1_12QrCOUNT;
    TLargeintField     * GIAZ2_1_13QrCOUNT;
    TLargeintField     * GIAZ2_1_14QrCOUNT;
    TLargeintField     * GIAZ2_2_1ckQrCOUNT;
    TLargeintField     * GIAZ2_2_1QrCOUNT;
    TLargeintField     * GIAZ2_2_2QrCOUNT;
    TLargeintField     * GIAZ2_2_4QrCOUNT;
    TLargeintField     * GIAZ2_2_6QrCOUNT;
    TLargeintField     * GIAZ2_3_1ckQrCOUNT;
    TLargeintField     * GIAZ2_3_1QrCOUNT;
    TLargeintField     * GIAZ2_3_2QrCOUNT;
    TLargeintField     * GIAZ2_3_3QrCOUNT;
    TLargeintField     * GIAZ2_3_4QrCOUNT;
    TLargeintField     * GIAZ2_3_6QrCOUNT;
    TLargeintField     * GIAZ2_3_7QrCOUNT;
    TLargeintField     * GIAZ2_3_8QrCOUNT;
    TLargeintField     * GIAZ2_3_9QrCOUNT;
    TLargeintField     * GIAZ2_4_1QrCOUNT;
    TLargeintField     * GIAZ2_4_3QrCOUNT;
    TLargeintField     * GIAZ2_4_5QrCOUNT;
    TLargeintField     * GIAZ2_4_6QrCOUNT;
    TLargeintField     * GIAZ2_4_8QrCOUNT;
    TLargeintField     * GIAZ2_4_10QrCOUNT;
    TLargeintField     * GIAZInQrCOUNT;
    TLargeintField     * QKonkPlus2COUNT;
    TLargeintField     * QKonkPlusCOUNT;
    TSmallintField     * QGorodOUT_COPY_AT;
    TSmallintField     * QGorodOUT_N_CK;
    TSmallintField     * QGorodOUT_N_DELO;
    TSmallintField     * QGorodOUT_REGION;
    TSmallintField     * QGorodOUT_WHEN_E_M;
    TSmallintField     * QGorodOUT_WHEN_E_S;
    TSmallintField     * QGroupProtokolN_COUNT;
    TSmallintField     * QGroupProtokolN_FAC;
    TSmallintField     * QGroupProtokolN_GROUP;
    TSmallintField     * QGroupProtokolN_SPECIALIZ;
    TSmallintField     * QGroupProtokolVID_EDU;
    TSmallintField     * QKol_Place15KOL_PLACE;
    TSmallintField     * QKol_PlaceKOL_PLACE;
    TSmallintField     * QKol_PlaceTEXT;
    TSmallintField     * QKonkurs2VOUT_CATEGORY_AB;
    TSmallintField     * QKonkurs2VOUT_KONKURS;
    TSmallintField     * QKonkurs2VOUT_N_CK;
    TSmallintField     * QKonkurs2VOUT_TERM_EDU;
    TSmallintField     * QKonkurs2VOUT_WHEN_EDU_MIDDLE;
    TSmallintField     * QKonkurs2VOUT_WHEN_EDU_SPEC;
    TSmallintField     * QKonkurs12OUT_CATEGORY_AB;
    TSmallintField     * QKonkurs12OUT_KONKURS;
    TSmallintField     * QKonkurs12OUT_N_CK;
    TSmallintField     * QKonkurs12OUT_N_SPECIALIZ;
    TSmallintField     * QKonkurs12OUT_TERM_EDU;
    TSmallintField     * QKonkurs12OUT_WHEN_EDU_MIDDLE;
    TSmallintField     * QKonkurs12OUT_WHEN_EDU_SPEC;
    TSmallintField     * QKonkurs34OUT_CATEGORY_AB;
    TSmallintField     * QKonkurs34OUT_KONKURS;
    TSmallintField     * QKonkurs34OUT_N_CK;
    TSmallintField     * QKonkurs34OUT_N_SPECIALIZ;
    TSmallintField     * QKonkurs34OUT_TERM_EDU;
    TSmallintField     * QKonkurs34OUT_WHEN_EDU_MIDDLE;
    TSmallintField     * QKonkurs34OUT_WHEN_EDU_SPEC;
    TSmallintField     * QKonkursOUT_CATEGORY_AB;
    TSmallintField     * QKonkursOUT_KONKURS;
    TSmallintField     * QKonkursOUT_N_CK;
    TSmallintField     * QKonkursOUT_TERM_EDU;
    TSmallintField     * QKonkursOUT_WHEN_EDU_MIDDLE;
    TSmallintField     * QKonkursOUT_WHEN_EDU_SPEC;
    TSmallintField     * QPredmet_BallOUT_N_PREDMET;
    TSmallintField     * QSpec1N_SPECIALIZ;

    TSQLTimeStampField * QGorodOUT_DATE_R;
    TSQLTimeStampField * QKonkurs2VOUT_DATE_R;
    TSQLTimeStampField * QKonkurs12OUT_DATE_R;
    TSQLTimeStampField * QKonkurs34OUT_DATE_R;
    TSQLTimeStampField * QKonkursOUT_DATE_R;
    TSQLTimeStampField * QPeopleProtocolDATE_R;

    TStringField       * QGorodOUT_ADDRESS;
    TStringField       * QGorodOUT_F;
    TStringField       * QGorodOUT_FIO;
    TStringField       * QGorodOUT_N;
    TStringField       * QGorodOUT_NAME_E_M;
    TStringField       * QGorodOUT_NAME_E_S;
    TStringField       * QGorodOUT_O;
    TStringField       * QGorodOUT_POL;
    TStringField       * QGorodOUT_PRIV;
    TStringField       * QGorodOUT_SPORT;
    TStringField       * QGorodOUT_V_K;
    TStringField       * QGorodOUT_WITHOUT;
    TStringField       * QGroupProtokolDESCRIBE;
    TStringField       * QGroupProtokolNOM_GROUP;
    TStringField       * QKonkurs2VOUT_ADDRESS_BEFORE;
    TStringField       * QKonkurs2VOUT_FIO;
    TStringField       * QKonkurs2VOUT_NAME_EDU_MIDDLE;
    TStringField       * QKonkurs2VOUT_NAME_EDU_SPEC;
    TStringField       * QKonkurs2VOUT_POL;
    TStringField       * QKonkurs2VOUT_SPORT_CATEGORY;
    TStringField       * QKonkurs12OUT_ADDRESS_BEFORE;
    TStringField       * QKonkurs12OUT_FIO;
    TStringField       * QKonkurs12OUT_NAME_EDU_MIDDLE;
    TStringField       * QKonkurs12OUT_NAME_EDU_SPEC;
    TStringField       * QKonkurs12OUT_POL;
    TStringField       * QKonkurs12OUT_SPORT_CATEGORY;
    TStringField       * QKonkurs34OUT_ADDRESS_BEFORE;
    TStringField       * QKonkurs34OUT_FIO;
    TStringField       * QKonkurs34OUT_NAME_EDU_MIDDLE;
    TStringField       * QKonkurs34OUT_NAME_EDU_SPEC;
    TStringField       * QKonkurs34OUT_POL;
    TStringField       * QKonkurs34OUT_SPORT_CATEGORY;
    TStringField       * QKonkursOUT_ADDRESS_BEFORE;
    TStringField       * QKonkursOUT_FIO;
    TStringField       * QKonkursOUT_NAME_EDU_MIDDLE;
    TStringField       * QKonkursOUT_NAME_EDU_SPEC;
    TStringField       * QKonkursOUT_POL;
    TStringField       * QKonkursOUT_SPORT_CATEGORY;
    TStringField       * QPeopleProtocolFIO;
    TStringField       * QPeopleProtocolNOM_GROUP;
    TStringField       * QPeopleProtocolPOL;
    TStringField       * QPredmet_BallOUT_TEXT_PREDMET;
    TStringField       * QPredmTEXT_PREDMET;
private:
public:
    __fastcall TDMVed (TComponent * Owner);
};

extern PACKAGE TDMVed * DMVed;

#endif  // DM_VED_UNIT_H