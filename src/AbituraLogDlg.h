#pragma once
#ifndef ABITURA_LOG_DLG_H
#define ABITURA_LOG_DLG_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <StdCtrls.hpp>
#include <System.hpp>
#include <SysUtils.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Windows.hpp>



class TAbiturLogDlg
    : public TForm
{
__published:
    TBevel          * Bevel1;

    TButton         * CancelBtn;
    TButton         * OKBtn;

    TDateTimePicker * DateTimePicker1;

    TLabel          * Label1;
    TLabel          * Label2;

    void __fastcall CancelBtnClick (TObject * Sender);
    void __fastcall FormActivate   (TObject * Sender);
    void __fastcall OKBtnClick     (TObject * Sender);
private:
public:
    virtual __fastcall TAbiturLogDlg (TComponent * AOwner);
};

extern PACKAGE TAbiturLogDlg * AbiturLogDlg;

#endif  // ABITURA_LOG_DLG_H