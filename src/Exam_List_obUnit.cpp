#include <vcl.h>
#pragma hdrstop


#include "Exam_List_obUnit.h"


#pragma package(smart_init)
//#pragma link "RxGIF"
#pragma link "frxClass"
#pragma resource "*.dfm"


TExam_List_obForm * Exam_List_obForm;



__fastcall TExam_List_obForm::TExam_List_obForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TExam_List_obForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}
