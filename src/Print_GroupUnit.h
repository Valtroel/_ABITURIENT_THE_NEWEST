#pragma once
#ifndef PRINT_GROUP_UNIT_H
#define PRINT_GROUP_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Qrctrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <StdCtrls.hpp>



class TPrint_GroupForm
    : public TForm
{
__published:
    TQRBand   * DetailBand1;

    TQRDBText * QRDBText1;
    TQRDBText * QRDBText2;
    TQRDBText * QRDBText3;
    TQRDBText * QRDBText4;
    TQRDBText * QRDBText5;
    TQRDBText * QRDBText6;
    TQRDBText * QRDBText7;
    TQRDBText * QRDBText8;
    TQRDBText * QRDBText9;
    TQRDBText * QRDBText10;
    TQRDBText * QRDBText11;
    TQRDBText * QRDBText12;
    TQRDBText * QRDBText13;
    TQRDBText * QRDBText14;
    TQRDBText * QRDBText15;

    TQRLabel  * QRLabel1;
    TQRLabel  * QRLabel2;
    TQRLabel  * QRLabel3;
    TQRLabel  * QRLabel4;
    TQRLabel  * QRLabel5;
    TQRLabel  * QRLabel6;
    TQRLabel  * QRLabel7;
    TQRLabel  * QRLabel8;
    TQRLabel  * QRLabel9;
    TQRLabel  * QRLabel10;
    TQRLabel  * QRLabel11;
    TQRLabel  * QRLabel12;
    TQRLabel  * QRLabel13;
    TQRLabel  * QRLabel14;
    TQRLabel  * QRLabel15;
    TQRLabel  * QRLabel16;
    TQRLabel  * QRLabel17;
    TQRLabel  * QRLabel18;
    TQRLabel  * QRLabel19;
    TQRLabel  * QRLabel20;
    TQRLabel  * QRLabel21;
    TQRLabel  * QRLabel22;
    TQRLabel  * QRLabel23;
    TQRLabel  * QRLabel24;
    TQRLabel  * QRLabel25;
    TQRLabel  * QRLabel26;
    TQRLabel  * QRLabel27;
    TQRLabel  * QRLabel28;
    TQRLabel  * QRLabel29;
    TQRLabel  * QRLabel30;
    TQRLabel  * QRLabel31;
    TQRLabel  * QRLabel32;
    TQRLabel  * QRLabel33;
    TQRLabel  * QRLabel34;
    TQRLabel  * QRLabel35;
    TQRLabel  * QRLabel36;
    TQRLabel  * QRLabel37;
    TQRLabel  * QRLabel38;
    TQRLabel  * QRLabel39;
    TQRLabel  * QRLabel40;
    TQRLabel  * QRLabel41;
    TQRLabel  * QRLabel42;
    TQRLabel  * QRLabel43;
    TQRLabel  * QRLabel44;
    TQRLabel  * QRLabel45;
    TQRLabel  * QRLabel46;
    TQRLabel  * QRLabel47;
    TQRLabel  * QRLabel48;
    TQRLabel  * QRLabel49;
    TQRLabel  * QRLabel50;
    TQRLabel  * QRLabel51;
    TQRLabel  * QRLabel52;

    TQRShape  * QRShape1;

    TQuickRep * QuickRep1;

    void __fastcall FormClose (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TPrint_GroupForm (TComponent * Owner);
};

extern PACKAGE TPrint_GroupForm * Print_GroupForm;

#endif  // PRINT_GROUP_UNIT_H