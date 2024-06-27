#pragma once
#ifndef SERTIFICAT_UNIT_H
#define SERTIFICAT_UNIT_H


#include <ActnList.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
#include <System.Actions.hpp>
#include <Vcl.ComCtrls.hpp>


#include "properties.hpp"


class TSertificatForm
    : public TForm
{
__published:
    TAction           * Action1;

    TActionList       * ActionList1;

    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;
    TBitBtn           * BitBtn3;

    TComboBox         * ComboBox1;

    TDBLookupComboBox * DBLookupComboBox1;

    TDBNavigator      * DBNavigator1;

    TEdit             * Edit1;
    TEdit             * Edit2;
    TEdit             * Edit3;
    TEdit             * Edit4;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TLabel            * Label4;
    TLabel            * Label5;
    TLabel            * Label6;
    TLabel            * Label7;
    TLabel            * Label8;
    TLabel            * Label9;
    TLabel            * Label10;
    TLabel            * Label11;
    TLabel            * Label12;
    TLabel            * Label13;
    TLabel            * Label14;
    TLabel            * Label15;

    TMaskEdit         * MaskEdit1;

    TPanel            * Panel1;
    TPanel            * Panel2;

    TSpeedButton      * SpeedButton1;

    TUpDown           * UpDown1;

    void __fastcall BitBtn1Click             (TObject * Sender);
    void __fastcall BitBtn2Click             (TObject * Sender);
    void __fastcall BitBtn3Click             (TObject * Sender);
    void __fastcall DBLookupComboBox1CloseUp (TObject * Sender);
    void __fastcall DBNavigator1Click        (
            TObject      * Sender,
            TNavigateBtn   Button
        );
    void __fastcall Edit1Exit                (TObject * Sender);
    void __fastcall FormActivate             (TObject * Sender);
    void __fastcall FormClose                (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall MaskEdit1Exit            (TObject * Sender);
    void __fastcall SpeedButton1Click        (TObject * Sender);
private:
public:
    __fastcall TSertificatForm (TComponent * Owner);

    bool __fastcall summa_b            (int        n    );                      // СУММИРОВАНИЕ РЕЗУЛЬТАТОВ ЭКЗАМЕНОВ, с учетом введенного сертификата
    void __fastcall refrech_sertificat ();                                      // процедура для поиска был ли уже сертификат у данного абитуриента
    void __fastcall seria_sertificat   (AnsiString seria);                      // функция возвращает по серии сертификата предмет
};

extern PACKAGE TSertificatForm * SertificatForm;

#endif  // SERTIFICAT_UNIT_H