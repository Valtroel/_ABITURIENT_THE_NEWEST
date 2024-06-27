#pragma once
#ifndef RESUILT_EXAM_UNIT_H
#define RESUILT_EXAM_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>



class TResult_ExamForm
    : public TForm
{
__published:
    TButton           * Button1;

    TDBGrid           * DBGrid1;
    TDBGrid           * DBGrid2;

    TDBLookupComboBox * DBLookupComboBox1;

    TEdit             * Edit1;

    TLabel            * Label1;
    TLabel            * Label2;

    TPanel            * Panel1;
    TPanel            * Panel2;

    void __fastcall Button1Click    (TObject * Sender);
    void __fastcall DBGrid1DblClick (TObject * Sender);
    void __fastcall FormActivate    (TObject * Sender);
    void __fastcall FormClose       (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TResult_ExamForm (TComponent * Owner);
};

extern PACKAGE TResult_ExamForm * Result_ExamForm;

#endif  // RESUILT_EXAM_UNIT_H