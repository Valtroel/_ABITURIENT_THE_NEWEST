#pragma once
#ifndef DUAL_LIST_H
#define DUAL_LIST_H


#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>



class TDualListDlg
    : public TForm
{
__published:
    TButton      * CancelBtn;
    TButton      * HelpBtn;
    TButton      * OKBtn;

    TLabel       * DstLabel;
    TLabel       * SrcLabel;

    TListBox     * DstList;
    TListBox     * SrcList;

    TSpeedButton * ExAllBtn;
    TSpeedButton * ExcludeBtn;
    TSpeedButton * IncAllBtn;
    TSpeedButton * IncludeBtn;

    void    __fastcall DstListDblClick   (TObject        * Sender);
    void    __fastcall ExAllBtnClick     (TObject        * Sender);
    void    __fastcall ExcludeBtnClick   (TObject        * Sender);
    Integer __fastcall GetFirstSelection (TCustomListBox * List  );
    void    __fastcall IncAllBtnClick    (TObject        * Sender);
    void    __fastcall IncludeBtnClick   (TObject        * Sender);
    void    __fastcall MoveSelected      (
            TCustomListBox * List,
            TStrings       * Items
        );
    void    __fastcall OKBtnClick        (TObject        * Sender);
    void    __fastcall SetButtons        ();
    void    __fastcall SetItem           (
            TListBox * List,
            int        Index
        );
    void    __fastcall SrcListDblClick   (TObject        * Sender);
private:
public:
    __fastcall TDualListDlg (TComponent * Owner);
};

extern PACKAGE TDualListDlg * DualListDlg;

#endif  // DUAL_LIST_H