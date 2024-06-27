#pragma once
#ifndef LIST_DOC_INDEX_UNIT_H
#define LIST_DOC_INDEX_UNIT_H


#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.StdCtrls.hpp>



class TListDocIndexForm
    : public TForm
{
__published:
    TBitBtn   * BitBtn1;

    TEdit     * IndexEdit;

    TLabel    * Label1;
    TLabel    * Label2;
    TLabel    * Text_doc;

    TMaskEdit * DateEdit;

    void __fastcall BitBtn1Click  (TObject * Sender);
    void __fastcall DateEditClick (TObject * Sender);
    void __fastcall FormShow      (TObject * Sender);
private:
public:
    __fastcall TListDocIndexForm (TComponent* Owner);
};

extern PACKAGE TListDocIndexForm * ListDocIndexForm;

#endif  // LIST_DOC_INDEX_UNIT_H