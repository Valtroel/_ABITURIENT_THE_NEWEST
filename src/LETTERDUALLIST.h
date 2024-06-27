#pragma once
#ifndef LETTER_DUAL_LIST_H
#define LETTER_DUAL_LIST_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <StdCtrls.hpp>
#include <System.hpp>
#include <SysUtils.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Windows.hpp>



class TLetterDualListDlg
    : public TForm
{
__published:
    TButton      * CancelBtn;
    TButton      * OKBtn;

    TDBImage     * DBImage1;

    TLabel       * DstLabel;
    TLabel       * SrcLabel;

    TListBox     * DstList;
    TListBox     * DstListI;
    TListBox     * SrcList;
    TListBox     * SrcListI;

    TSpeedButton * ExAllBtn;
    TSpeedButton * ExcludeBtn;
    TSpeedButton * IncAllBtn;
    TSpeedButton * IncludeBtn;

    void    __fastcall ExcAllBtnClick    (TObject        * Sender);
    void    __fastcall ExcludeBtnClick   (TObject        * Sender);
    void    __fastcall FormActivate      (TObject        * Sender);
    Integer __fastcall GetFirstSelection (TCustomListBox * List  );
    void    __fastcall IncAllBtnClick    (TObject        * Sender);
    void    __fastcall IncludeBtnClick   (TObject        * Sender);
    void    __fastcall MoveSelected      (
            TCustomListBox * List1,
            TStrings       * Items1,
            TCustomListBox * List2,
            TStrings       * Items2
        );
    void    __fastcall OKBtnClick        (TObject        * Sender);
    void    __fastcall SetButtons        ();
    void    __fastcall SetItem           (
            TListBox       * List,
            int              Index
        );
private:
public:
    virtual __fastcall TLetterDualListDlg (TComponent * AOwner);
};

extern PACKAGE TLetterDualListDlg * LetterDualListDlg;

#endif  // LETTER_DUAL_LIST_H