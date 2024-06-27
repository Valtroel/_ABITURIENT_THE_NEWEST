#pragma once
#ifndef NOTICE_UNIT_H
#define NOTICE_UNIT_H


#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxPreview.hpp"


#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>



class TNoticeForm
    : public TForm
{
__published:
    TfrxDBDataset * frxDBDataset1;

    TfrxPreview   * frxPrvNotice;

    TfrxReport    * frxRepNotice;

    void __fastcall frxRepNoticeAfterPrintReport (TObject * Sender);
private:
public:
    __fastcall TNoticeForm (TComponent * Owner);
};

extern PACKAGE TNoticeForm * NoticeForm;

#endif  // NOTICE_UNIT_H