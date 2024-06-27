#pragma once
#ifndef BALL_UNIT_H
#define BALL_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
// #include "RXCtrls.hpp"
#include <StdCtrls.hpp>


class TBall_Form
    : public TForm
{
__published:
    TBitBtn      * BitBtn1;
    TBitBtn      * BitBtn2;
    TBitBtn      * BitBtn3;

    TCheckBox    * CheckBox1;

    TDBNavigator * DBNavigator1;

    TDBText      * DBText1;
    TDBText      * DBText2;
    TDBText      * DBText3;

    TEdit        * Edit1;

    TLabel       * Label1;

    TPanel       * Panel1;

    TRadioGroup  * RadioGroup1;
    TRadioGroup  * RadioGroup2;

    void __fastcall BitBtn1Click             (TObject * Sender);
    void __fastcall BitBtn2Click             (TObject * Sender);
    void __fastcall BitBtn3Click             (TObject * Sender);
    void __fastcall CheckBox1Click           (TObject * Sender);
    void __fastcall DBLookupComboBox1CloseUp (TObject * Sender);
    void __fastcall DBNavigator1Click        (
            TObject      * Sender,
            TNavigateBtn   Button
        );
    void __fastcall Edit1Change              (TObject * Sender);
    void __fastcall FormActivate             (TObject * Sender);
    void __fastcall FormClose                (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall RadioGroup1Click         (TObject * Sender);
private:
public:
    __fastcall TBall_Form (TComponent * Owner);

    void __fastcall ball_check ();                                              // установка RadioGroup 1 или 2 в нужное значение балла
    void __fastcall Proverka   ();                                              // изменение статуса абитуриента при получении отрицательной оценки
};

extern PACKAGE TBall_Form * Ball_Form;

#endif  // BALL_UNIT_H