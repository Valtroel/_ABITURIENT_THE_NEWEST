#pragma once
#ifndef DLG_PROTOKOL_UNIT_H
#define DLG_PROTOKOL_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
// #include "RxToolEdit.hpp"
#include <StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>


#include "properties.hpp"



class TDlg_ProtokolForm
    : public TForm
{
__published:
    TBitBtn         * BitBtn1;

    TDateTimePicker * DateTimePicker1;

    TEdit           * Edit1;

    TLabel          * Label1;
    TLabel          * Label2;
    TPanel          * Panel1;

    void __fastcall BitBtn1Click          (TObject * Sender);
    void __fastcall DateTimePicker1Change (TObject * Sender);
    void __fastcall FormActivate          (TObject * Sender);
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall Panel1DblClick        (TObject * Sender);
private:
public:
    __fastcall TDlg_ProtokolForm (TComponent * Owner);
    
    bool __fastcall Protokol_FIO (
            int       f,
            TDateTime dat_p,
            int       v,
            int       k,
            int       pr
        );
};

extern PACKAGE TDlg_ProtokolForm * Dlg_ProtokolForm;

#endif  // DLG_PROTOKOL_UNIT_H