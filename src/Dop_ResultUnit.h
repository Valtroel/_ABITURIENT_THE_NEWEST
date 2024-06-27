#pragma once
#ifndef DOP_RESULT_UNIT_H
#define DOP_RESULT_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>



class TDop_ResultForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TButton           * Button1;

    TDBLookupComboBox * LookFIO;
    TDBLookupComboBox * LookPred;

    TEdit             * Edit1;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TLabel            * Label4;
    TLabel            * Label5;

    TPanel            * Panel1;

    TRadioGroup       * RadioGroup1;

    void __fastcall BitBtn1Click (TObject * Sender);
    void __fastcall FormClose    (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate   (TObject * Sender);
private:
public:
    __fastcall TDop_ResultForm (TComponent * Owner);
};

extern PACKAGE TDop_ResultForm * Dop_ResultForm;

#endif  // DOP_RESULT_UNIT_H