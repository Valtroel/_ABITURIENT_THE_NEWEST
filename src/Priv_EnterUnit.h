#pragma once
#ifndef PRIV_ENTER_UNIT_H
#define PRIV_ENTER_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>



class TPriv_EnterForm
    : public TForm
{
__published:
    TBitBtn * BitBtn1;
    TBitBtn * BitBtn2;
    TBitBtn * BitBtn3;
    TBitBtn * BitBtn4;
    TBitBtn * BitBtn5;

    TDBGrid * DBGrid1;

    TDBText * DBText1;
    TDBText * DBText2;
    TDBText * DBText3;

    TPanel  * Panel1;
    TPanel  * Panel2;
    TPanel  * Panel3;

    void __fastcall BitBtn1Click (TObject * Sender);
    void __fastcall BitBtn2Click (TObject * Sender);
    void __fastcall BitBtn3Click (TObject * Sender);
    void __fastcall BitBtn4Click (TObject * Sender);
    void __fastcall BitBtn5Click (TObject * Sender);
    void __fastcall FormActivate (TObject * Sender);
    void __fastcall FormClose    (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TPriv_EnterForm (TComponent * Owner);
};

extern PACKAGE TPriv_EnterForm * Priv_EnterForm;

#endif  // PRIV_ENTER_UNIT_H