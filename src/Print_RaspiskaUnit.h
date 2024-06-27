#pragma once
#ifndef PRINT_RASPISKA_UNIT_H
#define PRINT_RASPISKA_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
// #include "RxGIF.hpp"
#include <StdCtrls.hpp>



class TPrint_RaspiskaForm
    : public TForm
{
__published:
    TfrxDBDataset * frxDBDataset1;

    TfrxReport    * frxRepRaspiska;

    void __fastcall FormClose (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TPrint_RaspiskaForm (TComponent * Owner);
};

extern PACKAGE TPrint_RaspiskaForm * Print_RaspiskaForm;

#endif  // PRINT_RASPISKA_UNIT_H