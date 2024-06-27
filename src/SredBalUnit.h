#pragma once
#ifndef SRED_BAL_UNIT_H
#define SRED_BAL_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>



double Round (                                                                  // функция округления
        double Argument,
        int    Precision
    );



class TSredBalForm
    : public TForm
{
__published:
    TBitBtn     * BitBtn1;
    TBitBtn     * BitBtn2;
    TBitBtn     * BitBtn3;
    TBitBtn     * BitBtn4;

    TEdit       * Edit1;
    TEdit       * Edit2;

    TGroupBox   * GroupBox1;

    TLabel      * Label1;
    TLabel      * Label2;
    TLabel      * Label3;
    TLabel      * Label4;
    TLabel      * Label5;
    TLabel      * Label6;
    TLabel      * Label7;
    TLabel      * Label8;
    TLabel      * Label9;
    TLabel      * Label10;
    TLabel      * Label11;
    TLabel      * Label12;
    TLabel      * Label16;

    TMaskEdit   * MaskEdit1;
    TMaskEdit   * MaskEdit2;
    TMaskEdit   * MaskEdit3;
    TMaskEdit   * MaskEdit4;
    TMaskEdit   * MaskEdit5;
    TMaskEdit   * MaskEdit6;
    TMaskEdit   * MaskEdit7;
    TMaskEdit   * MaskEdit8;
    TMaskEdit   * MaskEdit9;
    TMaskEdit   * MaskEdit10;

    TPanel      * Panel1;
    TPanel      * Panel2;
    TPanel      * Panel3;

    TRadioGroup * RadioGroup1;

    void __fastcall BitBtn1Click     (TObject * Sender);
    void __fastcall BitBtn2Click     (TObject * Sender);
    void __fastcall BitBtn3Click     (TObject * Sender);
    void __fastcall BitBtn4Click     (TObject * Sender);
    void __fastcall FormActivate     (TObject * Sender);
    void __fastcall FormClose        (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall RadioGroup1Click (TObject * Sender);
private:
    void __fastcall RadioSetup       (int       ind   );                        // функция выбора системы оценок
public:
    __fastcall TSredBalForm (TComponent * Owner);

    void       __fastcall Ball_5     (                                          // расчета среднего балла по 5-бальной системе
            AnsiString p5,
            AnsiString p4,
            AnsiString p3
        );
    AnsiString            Ball_5_10  (double    ball  );                        // перевода 5-бальной системы в 10-бальную
    void       __fastcall Ball_10    (                                          // рачтета среднего балла по 10-быльной системе
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
        );
};

extern PACKAGE TSredBalForm * SredBalForm;

#endif  // SRED_BAL_UNIT_H