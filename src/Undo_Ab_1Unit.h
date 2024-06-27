#pragma once
#ifndef UNDO_AB_1_UNIT_H
#define UNDO_AB_1_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>



void __fastcall VidKonkurs (                                                    // установка конкурса (вызывается если у платников общий конкурс (т.е. oplata_konkurs == 0))
        TRadioGroup * RadioGroup2,
        TComboBox   * PriceCmbBx,
        TComboBox   * ComboBox1
    );



class TUndo_Ab_1Form
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;

    TComboBox         * CategoryAbCmbBx;
    TComboBox         * ComboBox1;
    TComboBox         * ComboBox2;
    TComboBox         * KonkursCmbBx;
    TComboBox         * PriceCmbBx;
    TComboBox         * SngFrgCmbBx;

    TDBLookupComboBox * DBLookupComboBox1;
    TDBLookupComboBox * DBLookupComboBox2;
    TDBLookupComboBox * DBLookupComboBox3;
    TDBLookupComboBox * DBLookupComboBox4;

    TDBText           * DBText1;
    TDBText           * DBText2;
    TDBText           * DBText3;

    TEdit             * Edit2;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TLabel            * Label4;
    TLabel            * Label5;
    TLabel            * Label6;
    TLabel            * Label7;
    TLabel            * Label8;
    TLabel            * Label29;

    TPanel            * Panel1;
    TPanel            * Panel2;

    void __fastcall BitBtn1Click             (TObject * Sender);
    void __fastcall BitBtn2Click             (TObject * Sender);
    void __fastcall ComboBox1Change          (TObject * Sender);
    void __fastcall DBLookupComboBox1CloseUp (TObject * Sender);
    void __fastcall FormActivate             (TObject * Sender);
    void __fastcall FormClose                (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall RadioGroup3Click         (TObject * Sender);
private:
public:
    __fastcall TUndo_Ab_1Form (TComponent * Owner);

    void __fastcall Grupp (AnsiString sp);                                      // проверка возможных номеров групп (зависит от специализации и вида обучения)
};

extern PACKAGE TUndo_Ab_1Form * Undo_Ab_1Form;

#endif  // UNDO_AB_1_UNIT_H