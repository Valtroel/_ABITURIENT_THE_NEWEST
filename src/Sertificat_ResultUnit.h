#pragma once
#ifndef SERTIFICAT_RESULT_UNIT_H
#define SERTIFICAT_RESULT_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>



class TSertificat_ResultForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;

    TButton           * Button1;
    TButton           * Button2;

    TDBLookupComboBox * LookFIO;
    TDBLookupComboBox * LookPred;

    TEdit             * Edit1;

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

    TPanel            * Panel1;

    void __fastcall BitBtn1Click   (TObject * Sender);
    void __fastcall Button1Click   (TObject * Sender);
    void __fastcall Button2Click   (TObject * Sender);
    void __fastcall Edit1Change    (TObject * Sender);
    void __fastcall FormClose      (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormShow       (TObject * Sender);
    void __fastcall LookFIOCloseUp (TObject * Sender);
private:
public:
    __fastcall TSertificat_ResultForm (TComponent * Owner);
};

extern PACKAGE TSertificat_ResultForm * Sertificat_ResultForm;

#endif  // SERTIFICAT_RESULT_UNIT_H