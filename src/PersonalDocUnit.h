#pragma once
#ifndef PERSONAL_DOC_UNIT_H
#define PERSONAL_DOC_UNIT_H


#include "frxRich.hpp"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>



class TPersonalDocFrm
    : public TForm
{
__published:
    TButton        * Button1;

    TComboBox      * SpecializCmbBx;
    TComboBox      * VidEduCmbBx;

    TfrxRichObject * frxRichObject1;

    TLabel         * Label1;
    TLabel         * Label2;

    void __fastcall Button1Click (TObject * Sender);
    void __fastcall FormActivate (TObject * Sender);
private:
public:
    __fastcall TPersonalDocFrm (TComponent * Owner);
};

extern PACKAGE TPersonalDocFrm * PersonalDocFrm;

#endif  // PERSONAL_DOC_UNIT_H