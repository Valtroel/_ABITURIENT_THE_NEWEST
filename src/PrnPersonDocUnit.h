#pragma once
#ifndef PRN_PERSON_DOC_UNIT_H
#define PRN_PERSON_DOC_UNIT_H


#include "frxClass.hpp"
#include "frxPreview.hpp"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>



class TPrnPersonDocForm
    : public TForm
{
__published:
    TfrxPreview * frxPreview1;

    TfrxReport  * frxReport1;

    void __fastcall frxReport1AfterPrintReport (TObject * Sender);
private:
public:
    __fastcall TPrnPersonDocForm (TComponent * Owner);
};

extern PACKAGE TPrnPersonDocForm * PrnPersonDocForm;

#endif  // PRN_PERSON_DOC_UNIT_H