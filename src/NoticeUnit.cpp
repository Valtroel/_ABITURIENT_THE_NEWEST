#include <vcl.h>
#pragma hdrstop


#include "AbiturUnit.h"
#include "DMUnit.h"
#include "MainUnit.h"
#include "NoticeUnit.h"


#pragma package (smart_init)
#pragma link "frxClass"
#pragma link "frxPreview"
#pragma link "frxDBSet"
#pragma resource "*.dfm"


TNoticeForm * NoticeForm;



__fastcall TNoticeForm::TNoticeForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TNoticeForm::frxRepNoticeAfterPrintReport (TObject * Sender)
{
    if (frxRepNotice)                                                           // После окончания печати отчёта
        frxRepNotice -> PreviewForm -> Close ();
}

