#pragma once
#ifndef GROUP_FAC_UNIT_H
#define GROUP_FAC_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
// #include "RxToolEdit.hpp"
#include <StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>


#include "properties.hpp"



class TGroup_FacForm
    : public TForm
{
__published:
    TBevel            * Bevel1;
    TBevel            * Bevel2;

    TButton           * Button1;
    TButton           * Button2;

    TCheckBox         * CheckBox1;
    TComboBox         * ComboBox1;

    TDateTimePicker   * DateTimePicker1;

    TDBGrid           * DBGrid1;

    TDBLookupComboBox * LookFound;
    TDBLookupComboBox * LookNewSp;
    TDBLookupComboBox * LookSp;

    TEdit             * Edit1;
    TEdit             * Edit2;
    TEdit             * Edit3;

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

    TListBox          * List1;

    TPanel            * Panel1;
    TPanel            * Panel2;
    TPanel            * Panel3;

    TRadioGroup       * RadioGroup1;

    TSpeedButton      * SpeedButton1;
    TSpeedButton      * SpeedButton2;
    TSpeedButton      * SpeedButton3;
    TSpeedButton      * SpeedButton4;

    void __fastcall Button1Click          (TObject * Sender);
    void __fastcall Button2Click          (TObject * Sender);
    void __fastcall DateTimePicker1Change (TObject * Sender);
    void __fastcall DBGrid1DblClick       (TObject * Sender);
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall LookFoundCloseUp      (TObject * Sender);
    void __fastcall LookSpCloseUp         (TObject * Sender);
    void __fastcall SpeedButton1Click     (TObject * Sender);
    void __fastcall SpeedButton2Click     (TObject * Sender);
    void __fastcall SpeedButton3Click     (TObject * Sender);
    void __fastcall SpeedButton4Click     (TObject * Sender);
private:
    void __fastcall Save_Priv (                                                 // функция, которая сохраняет привелегии (сирота, Чаэс, инвалид)
        int        people,
        int        priv,
        AnsiString text,
        AnsiString year_cur
    );
public:
    __fastcall TGroup_FacForm (TComponent * Owner);
};

extern PACKAGE TGroup_FacForm * Group_FacForm;

#endif  // GROUP_FAC_UNIT_H