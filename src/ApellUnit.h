#pragma once
#ifndef APELL_UNIT_H
#define APELL_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>


class TApellForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;

    TDBLookupComboBox * LookB;
    TDBLookupComboBox * LookF;
    TDBLookupComboBox * LookP;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TPanel            * Panel1;

    void __fastcall BitBtn1Click (TObject * Sender);
    void __fastcall FormClose    (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TApellForm (TComponent * Owner);
};

extern PACKAGE TApellForm * ApellForm;

#endif  // APELL_UNIT_H