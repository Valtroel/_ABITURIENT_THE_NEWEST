#pragma once
#ifndef EXAM_LIST_UNIT_H
#define EXAM_LIST_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <Qrctrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <StdCtrls.hpp>



class TExam_ListForm
    : public TForm
{
__published:
    TfrxDBDataset * frxDBDataset1;

    TfrxReport    * frxRepExam;

    void __fastcall FormClose (
        TObject      * Sender,
        TCloseAction & Action
    );
private:
public:
    __fastcall TExam_ListForm (TComponent * Owner);
};

extern PACKAGE TExam_ListForm * Exam_ListForm;

#endif  // EXAM_LIST_UNIT_H