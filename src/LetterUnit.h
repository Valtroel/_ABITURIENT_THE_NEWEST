#pragma once
#ifndef LETTER_UNIT_H
#define LETTER_UNIT_H


#include "frxClass.hpp"
#include "frxPreview.hpp"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>



class TLetterForm
    : public TForm
{
__published:
    TfrxPreview * frxPreview1;

    TfrxReport  * frxReport1;

    void __fastcall frxReport1AfterPrintReport (TObject * Sender);
private:
public:
    __fastcall TLetterForm (TComponent * Owner);
};

extern PACKAGE TLetterForm * LetterForm;

#endif  // LETTER_UNIT_H