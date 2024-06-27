#pragma once
#ifndef EXAM_LIST_ALL_UNIT_H
#define EXAM_LIST_ALL_UNIT_H


#include "QuickRpt.hpp"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>



class TExam_List_AllForm
    : public TForm
{
__published:
    TQRCompositeReport * QRCompositeReport1;

    void __fastcall QRCompositeReport1AddReports (TObject * Sender);
private:
public:
    __fastcall TExam_List_AllForm (TComponent * Owner);
};

extern PACKAGE TExam_List_AllForm * Exam_List_AllForm;

#endif  // EXAM_LIST_ALL_UNIT_H