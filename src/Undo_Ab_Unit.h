#pragma once
#ifndef UNDO_AB_UNIT_H
#define UNDO_AB_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>



class TUndo_Ab_Form
    : public TForm
{
__published:
    TBitBtn * BitBtn2;
    TBitBtn * BitBtn3;

    TDBGrid * DBGrid1;

    TEdit   * Edit1;

    TLabel  * Label1;
    TPanel  * Panel1;
    TPanel  * Panel2;
    TPanel  * Panel3;
    TLabel  * Label35;

    void __fastcall BitBtn2Click (TObject * Sender);
    void __fastcall BitBtn3Click (TObject * Sender);
    void __fastcall Edit1Change  (TObject * Sender);
    void __fastcall FormActivate (TObject * Sender);
    void __fastcall FormClose    (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TUndo_Ab_Form (TComponent * Owner);
};

extern PACKAGE TUndo_Ab_Form * Undo_Ab_Form;

#endif  // UNDO_AB_UNIT_H