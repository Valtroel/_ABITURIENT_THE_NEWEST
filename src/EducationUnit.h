#pragma once
#ifndef EDUCATION_UNIT_H
#define EDUCATION_UNIT_H


#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.StdCtrls.hpp>



class TEducationForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;
    TBitBtn           * BitBtn3;

    TDBEdit           * NameEduMiddleDBEdt;
    TDBEdit           * NomAttestDBEdt;
    TDBEdit           * WhenEduMiddleDBEdt;
    TDBEdit           * WhereEduMiddleDBEdt;

    TDBLookupComboBox * DBLookupComboBox1;

    TLabel            * Label1;
    TLabel            * Label14;
    TLabel            * Label21;
    TLabel            * Label23;
    TLabel            * Label25;

    TPanel            * Panel2;

    void __fastcall BitBtn1Click (TObject * Sender);
    void __fastcall BitBtn3Click (TObject * Sender);
    void __fastcall FormActivate (TObject * Sender);
private:
public:
    __fastcall TEducationForm (TComponent * Owner);
};

extern PACKAGE TEducationForm * EducationForm;

#endif  // EDUCATION_UNIT_H