#pragma once
#ifndef REP_SEL_EXERC_H
#define REP_SEL_EXERC_H


#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxPreview.hpp"
#include "frxRich.hpp"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>



class TFormRepSelExerc
    : public TForm
{
__published:
    TfrxDBDataset * frxDBDataset1;
    TfrxDBDataset * frxDBDataset2;
    TfrxDBDataset * frxDBDataset3;
    TfrxDBDataset * frxDBDataset4;

    TfrxPreview   * frxPreview1;

    TfrxReport    * frxRep_Sel_Exerc;
private:
public:
    __fastcall TFormRepSelExerc (TComponent * Owner);
};

extern PACKAGE TFormRepSelExerc * FormRepSelExerc;

#endif  // REP_SEL_EXERC_H