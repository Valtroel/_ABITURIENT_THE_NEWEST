#pragma once
#ifndef SPISOC_GROUP_UNIT_H
#define SPISOC_GROUP_UNIT_H


#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>



class TSpisoc_GroupForm
    : public TForm
{
__published:
    TButton           * Button1;

    TDBLookupComboBox * DBLookupComboBox1;

    TRichEdit         * R1;

    void __fastcall Button1Click (TObject * Sender);
    void __fastcall FormClose    (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TSpisoc_GroupForm (TComponent * Owner);

    void __fastcall Konkurs (int kon);
    void __fastcall Stroka  ();
};

extern PACKAGE TSpisoc_GroupForm * Spisoc_GroupForm;

#endif  // SPISOC_GROUP_UNIT_H