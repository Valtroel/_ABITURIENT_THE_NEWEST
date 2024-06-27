#pragma once
#ifndef EXAMEN_UNIT_H
#define EXAMEN_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
// #include "RXToolEdit.hpp"
#include <StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>


#include "properties.hpp"



class TExamenForm
    : public TForm
{
__published:
    TButton           * Button1;
    TButton           * Button2;

    TDateTimePicker   * DateTimePicker1;

    TDBLookupComboBox * DBLookupComboBox1;

    TEdit             * Edit1;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TLabel            * Label4;

    TListBox          * ListBox1;

    TMaskEdit         * MaskEdit1;

    TPanel            * Panel1;
    TPanel            * Panel2;
    TPanel            * Panel3;
    TPanel            * Panel4;
    TPanel            * Panel5;

    TRadioGroup       * RG1;

    TSpeedButton      * SpeedButton1;
    TSpeedButton      * SpeedButton2;
    TSpeedButton      * SpeedButton3;
    TSpeedButton      * SpeedButton4;
    TSpeedButton      * SpeedButton5;

    TSplitter         * Splitter1;

    TStringGrid       * SG1;

    void __fastcall Button1Click          (TObject * Sender);
    void __fastcall Button2Click          (TObject * Sender);
    void __fastcall DateTimePicker1Change (TObject * Sender);
    void __fastcall Edit1Change           (TObject * Sender);
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate            (TObject * Sender);
    void __fastcall SG1DblClick           (TObject * Sender);
    void __fastcall SpeedButton2Click     (TObject * Sender);
    void __fastcall SpeedButton3Click     (TObject * Sender);
    void __fastcall SpeedButton4Click     (TObject * Sender);
private:
public:
    __fastcall TExamenForm (TComponent * Owner);

    AnsiString search_nomdela (
            int        col_ab,
            AnsiString fam,
            int        ind
        );
};

extern PACKAGE TExamenForm * ExamenForm;

#endif  // EXAMEN_UNIT_H