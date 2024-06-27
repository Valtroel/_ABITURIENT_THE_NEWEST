
#include <vcl.h>
#pragma hdrstop

#include "AbituraLogDlg.h"
#include "DMUnit.h"
#include "MainUnit.h"

#pragma resource "*.dfm"

TAbiturLogDlg * AbiturLogDlg;
 
__fastcall TAbiturLogDlg::TAbiturLogDlg (TComponent * AOwner)
    : TForm (AOwner)
{ }

void __fastcall TAbiturLogDlg::CancelBtnClick (TObject * Sender)
{
    MainForm -> AbiturLogDate = 0;
}

void __fastcall TAbiturLogDlg::FormActivate   (TObject * Sender)
{
    MainForm -> AbiturLogDate = 0;

    DateTimePicker1 -> Date =
        cur_d.CurrentDate ();
}

void __fastcall TAbiturLogDlg::OKBtnClick     (TObject * Sender)
{
    MainForm -> AbiturLogDate =
        DateTimePicker1 -> Date;
}