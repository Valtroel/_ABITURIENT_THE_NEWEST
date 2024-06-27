#pragma once
#ifndef PRINT_OPIS_UNIT_H
#define PRINT_OPIS_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <StdCtrls.hpp>



class TPrint_OpisForm
    : public TForm
{
__published:
    TfrxDBDataset * frxDBDataset1;

    TfrxReport    * frxRepOpis;

    void __fastcall FormClose (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TPrint_OpisForm (TComponent * Owner);
};

extern PACKAGE TPrint_OpisForm * Print_OpisForm;

#endif  // PRINT_OPIS_UNIT_H