#pragma once
#ifndef DUAL_LIST_DOC_H
#define DUAL_LIST_DOC_H


#include <System.Classes.hpp>
#include <System.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Winapi.Windows.hpp>



class TDualListDlgDoc
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
    void    __fastcall ExcAllBtnClick    (TObject        * Sender);
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
    virtual __fastcall TDualListDlgDoc (TComponent * AOwner);
};

extern PACKAGE TDualListDlgDoc * DualListDlgDoc;

#endif  // DUAL_LIST_DOC_H