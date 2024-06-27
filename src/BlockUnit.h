#pragma once
#ifndef BLOCK_UNIT_H
#define BLOCK_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>



class TBlockForm
    : public TForm
{
__published:
    TBitBtn      * BitBtn1;
    TBitBtn      * BitBtn2;

    TPageControl * PageControl1;

    TPanel       * Panel1;
    TPanel       * Panel2;

    TRadioGroup  * RadioGroup1;
    TRadioGroup  * RadioGroup2;

    TTabSheet    * TabSheet1;
    TTabSheet    * TabSheet2;

    void __fastcall BitBtn1Click (TObject * Sender);
    void __fastcall BitBtn2Click (TObject * Sender);
    void __fastcall FormClose    (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TBlockForm (TComponent * Owner);

    void __fastcall TBlockForm::PressBtn (int pressBtn);        // определяет какая нажата кнопка (0 - Разрешить, 1 - Запретить)
};

extern PACKAGE TBlockForm * BlockForm;

#endif  // BLOCK_UNIT_H