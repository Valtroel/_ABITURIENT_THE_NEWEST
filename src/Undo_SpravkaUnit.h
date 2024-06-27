#pragma once
#ifndef UNDO_SPRAVKA_UNIT_H
#define UNDO_SPRAVKA_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <Data.DB.hpp>



class TUndo_SpravkaForm
    : public TForm
{
__published:
    TBitBtn * BitBtn1;

    TDBGrid * DBGrid1;

    TPanel  * Panel1;
    TPanel  * Panel2;

    void __fastcall BitBtn1Click (TObject * Sender);
    void __fastcall FormClose    (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TUndo_SpravkaForm (TComponent * Owner);
};

extern PACKAGE TUndo_SpravkaForm * Undo_SpravkaForm;

#endif  // UNDO_SPRAVKA_UNIT_H