#pragma once
#ifndef EXAM_LIST_OB_UNIT_H
#define EXAM_LIST_OB_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include "frxClass.hpp"
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
// #include "RxGIF.hpp"
#include <StdCtrls.hpp>



class TExam_List_obForm
    : public TForm
{
__published:
    TfrxReport * frxRepExamOb;

    void __fastcall FormClose (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TExam_List_obForm (TComponent * Owner);
};

extern PACKAGE TExam_List_obForm * Exam_List_obForm;

#endif  // EXAM_LIST_OB_UNIT_H