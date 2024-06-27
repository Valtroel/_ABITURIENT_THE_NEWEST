#pragma once
#ifndef PASS_DLG_UNIT_H
#define PASS_DLG_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <StdCtrls.hpp>
#include <System.hpp>
#include <SysUtils.hpp>
#include <Windows.hpp>


#include "properties.hpp"


class TPassDlg
    : public TForm
{
__published:
    TBitBtn * BitBtn1;
    TBitBtn * BitBtn2;

    TEdit   * Password;
    TEdit   * User;

    TLabel  * Label1;
    TLabel  * Label2;

    void __fastcall BitBtn1Click (TObject * Sender);
    void __fastcall BitBtn2Click (TObject * Sender);
    void __fastcall FormActivate (TObject * Sender);
    void __fastcall FormClose    (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    virtual __fastcall TPassDlg (TComponent * AOwner);
};

extern PACKAGE TPassDlg * PassDlg;

#endif  // PASS_DLG_UNIT_H