#pragma once
#ifndef SPRAV_UNIT_H
#define SPRAV_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
//#include "MyList.h"
//#include "RxLogin.hpp"
#include <StdCtrls.hpp>



class TSpravForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;
    TBitBtn           * BitBtn3;
    TBitBtn           * BitBtn4;
    TBitBtn           * BitBtn5;
    TBitBtn           * BitBtn6;
    TBitBtn           * BitBtn7;
    TBitBtn           * BitBtn8;
    TBitBtn           * BitBtn9;
    TBitBtn           * BitBtn10;
    TBitBtn           * BitBtn11;
    TBitBtn           * BitBtn12;
    TBitBtn           * BitBtn13;
    TBitBtn           * BitBtn14;
    TBitBtn           * BitBtn15;
    TBitBtn           * BitBtn16;
    TBitBtn           * BitBtn17;
    TBitBtn           * BitBtn18;
    TBitBtn           * BitBtn19;
    TBitBtn           * BitBtn20;
    TBitBtn           * BitBtn21;
    TBitBtn           * BitBtn22;
    TBitBtn           * BitBtn23;
    TBitBtn           * BitBtn24;
    TBitBtn           * BitBtn25;
    TBitBtn           * BitBtn26;
    TBitBtn           * BitBtn27;
    TBitBtn           * BitBtn30;
    TBitBtn           * BitBtn31;
    TBitBtn           * BitBtn32;
    TBitBtn           * BitBtn33;
    TBitBtn           * BitBtn34;
    TBitBtn           * BitBtn35;
    TBitBtn           * BitBtn36;

    TComboBox         * ComboBox1;
    TComboBox         * ComboBox2;
    TComboBox         * ComboBox3;
    TComboBox         * GrpCmbBx;
    TComboBox         * PolCmbBx;

    TDBEdit           * DBEdit1;

    TDBGrid           * DBGrid1;
    TDBGrid           * DBGrid2;
    TDBGrid           * DBGrid3;
    TDBGrid           * DBGrid4;
    TDBGrid           * DBGrid5;
    TDBGrid           * DBGrid6;
    TDBGrid           * DBGrid7;
    TDBGrid           * DBGrid9;
    TDBGrid           * DBGrid11;
    TDBGrid           * DBGrid12;
    TDBGrid           * DBGrid13;
    TDBGrid           * KUDBGrd;

    TDBLookupComboBox * DBLookupComboBox1;
    TDBLookupComboBox * DBLookupComboBox2;
    TDBLookupComboBox * KUDBLkpCmbBx;
    TDBLookupComboBox * SpecializDBLkpCmbBx;

    TDBNavigator      * DBNavigator1;

    TEdit             * Edit1;
    TEdit             * Edit2;
    TEdit             * Edit3;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TLabel            * Label4;
    TLabel            * Label5;
    TLabel            * Label6;
    TLabel            * Label7;
    TLabel            * Label9;
    TLabel            * Label10;
    TLabel            * Label11;
    TLabel            * Label12;
    TLabel            * Label13;
    TLabel            * Label14;
    TLabel            * Label15;
    TLabel            * Label16;
    TLabel            * Label17;
    TLabel            * Label18;
    TLabel            * Label19;
    TLabel            * Label20;
    TLabel            * Label21;
    TLabel            * Label22;
    TLabel            * Label23;
    TLabel            * Label24;
    TLabel            * Label25;
    TLabel            * Label26;

    // TMyList           * MyList1;

    TPageControl      * PageControl1;

    TPanel            * Panel1;
    TPanel            * Panel2;
    TPanel            * Panel3;
    TPanel            * Panel4;
    TPanel            * Panel5;
    TPanel            * Panel6;
    TPanel            * Panel7;
    TPanel            * Panel8;
    TPanel            * Panel11;
    TPanel            * Panel12;
    TPanel            * Panel13;
    TPanel            * Panel14;
    TPanel            * Panel15;
    TPanel            * Panel16;
    TPanel            * Panel17;
    TPanel            * Panel18;
    TPanel            * Panel19;
    TPanel            * Panel20;
    TPanel            * Panel21;
    TPanel            * Panel22;
    TPanel            * Panel23;
    TPanel            * Panel24;
    TPanel            * Panel25;
    TPanel            * Panel26;
    TPanel            * Panel27;
    TPanel            * Panel28;
    TPanel            * Panel29;
    TPanel            * Panel30;
    TPanel            * Panel31;
    TPanel            * Panel32;
    TPanel            * Panel33;
    TPanel            * Panel34;
    TPanel            * Panel35;

    TRadioGroup       * RadioGroup1;
    TRadioGroup       * RadioGroup2;

    TSpeedButton      * SpeedButton1;

    TTabSheet         * TabSheet1;
    TTabSheet         * TabSheet2;
    TTabSheet         * TabSheet4;
    TTabSheet         * TabSheet5;
    TTabSheet         * TabSheet6;
    TTabSheet         * TabSheet7;
    TTabSheet         * TabSheet8;
    TTabSheet         * TabSheet9;
    TTabSheet         * TabSheet10;
    TTabSheet         * TabSheet11;

    void __fastcall BitBtn1Click           (TObject * Sender);
    void __fastcall BitBtn2Click           (TObject * Sender);
    void __fastcall BitBtn3Click           (TObject * Sender);
    void __fastcall BitBtn4Click           (TObject * Sender);
    void __fastcall BitBtn5Click           (TObject * Sender);
    void __fastcall BitBtn6Click           (TObject * Sender);
    void __fastcall BitBtn7Click           (TObject * Sender);
    void __fastcall BitBtn8Click           (TObject * Sender);
    void __fastcall BitBtn9Click           (TObject * Sender);
    void __fastcall BitBtn10Click          (TObject * Sender);
    void __fastcall BitBtn11Click          (TObject * Sender);
    void __fastcall BitBtn12Click          (TObject * Sender);
    void __fastcall BitBtn13Click          (TObject * Sender);
    void __fastcall BitBtn14Click          (TObject * Sender);
    void __fastcall BitBtn15Click          (TObject * Sender);
    void __fastcall BitBtn16Click          (TObject * Sender);
    void __fastcall BitBtn17Click          (TObject * Sender);
    void __fastcall BitBtn18Click          (TObject * Sender);
    void __fastcall BitBtn19Click          (TObject * Sender);
    void __fastcall BitBtn20Click          (TObject * Sender);
    void __fastcall BitBtn21Click          (TObject * Sender);
    void __fastcall BitBtn22Click          (TObject * Sender);
    void __fastcall BitBtn23Click          (TObject * Sender);
    void __fastcall BitBtn24Click          (TObject * Sender);
    void __fastcall BitBtn25Click          (TObject * Sender);
    void __fastcall BitBtn26Click          (TObject * Sender);
    void __fastcall BitBtn27Click          (TObject * Sender);
    void __fastcall BitBtn30Click          (TObject * Sender);
    void __fastcall BitBtn31Click          (TObject * Sender);
    void __fastcall BitBtn32Click          (TObject * Sender);
    void __fastcall BitBtn33Click          (TObject * Sender);
    void __fastcall BitBtn35Click          (TObject * Sender);
    void __fastcall BitBtn36Click          (TObject * Sender);
    void __fastcall DBGrid1DblClick        (TObject * Sender);
    void __fastcall DBGrid1Enter           (TObject * Sender);
    void __fastcall DBGrid2Enter           (TObject * Sender);
    void __fastcall DBGrid3Enter           (TObject * Sender);
    void __fastcall DBGrid4Enter           (TObject * Sender);
    void __fastcall DBGrid5Enter           (TObject * Sender);
    void __fastcall DBGrid6Enter           (TObject * Sender);
    void __fastcall DBGrid7DblClick        (TObject * Sender);
    void __fastcall DBGrid7Enter           (TObject * Sender);
    void __fastcall DBGrid9EditButtonClick (TObject * Sender);
    void __fastcall DBGrid9Enter           (TObject * Sender);
    void __fastcall DBGrid11Enter          (TObject * Sender);
    void __fastcall DBGrid12DblClick       (TObject * Sender);
    void __fastcall DBGrid12Enter          (TObject * Sender);
    void __fastcall FormActivate           (TObject * Sender);
    void __fastcall FormClose              (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall KUDBGrdDblClick        (TObject * Sender);
    void __fastcall SpeedButton1Click      (TObject * Sender);
    void __fastcall TabSheet1Show          (TObject * Sender);
    void __fastcall TabSheet4Show          (TObject * Sender);
    void __fastcall TabSheet5Show          (TObject * Sender);
    void __fastcall TabSheet6Show          (TObject * Sender);
    void __fastcall TabSheet7Show          (TObject * Sender);
    void __fastcall TabSheet8Show          (TObject * Sender);
    void __fastcall TabSheet9Show          (TObject * Sender);
    void __fastcall TabSheet10Show         (TObject * Sender);
    void __fastcall TabSheet11Show         (TObject * Sender);
private:
public:
    __fastcall TSpravForm (TComponent * Owner);

    AnsiString search_nomer (                                                   // Поиск номера специализации по названию
            int        rec_sp,
            AnsiString name
        );
};

extern PACKAGE TSpravForm * SpravForm;

#endif  // SPRAV_UNIT_H