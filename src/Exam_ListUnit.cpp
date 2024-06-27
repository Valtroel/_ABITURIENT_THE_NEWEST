#include <vcl.h>
#pragma hdrstop

#include "Exam_ListUnit.h"
#include "DMUnit.h"


#pragma package (smart_init)
#pragma link     "frxClass"
#pragma link     "frxDBSet"
#pragma resource "*.dfm"



TExam_ListForm * Exam_ListForm;



__fastcall TExam_ListForm::TExam_ListForm (TComponent * Owner)
    : TForm(Owner)
{ }



void __fastcall TExam_ListForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}
