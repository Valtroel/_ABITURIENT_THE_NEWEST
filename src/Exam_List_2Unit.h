#pragma once
#ifndef EXAM_LIST_2_UNIT_H
#define EXAM_LIST_2_UNIT_H


#include "QRCtrls.hpp"
#include "QuickRpt.hpp"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>



class TExam_List_2Form
    : public TForm
{
__published:
    TQRBand     * DetailBand1;

    TQRDBText   * QRDBText1_1;
    TQRDBText   * QRDBText2_1;
    TQRDBText   * QRDBText3_1;
    TQRDBText   * QRDBText4_1;
    TQRDBText   * QRDBText5_1;
    TQRDBText   * QRDBText6_1;
    TQRDBText   * QRDBText7_1;
    TQRDBText   * QRDBText8_1;

    TQRImage    * QRImage1_1;

    TQRLabel    * QRLabel1_1;
    TQRLabel    * QRLabel2_1;
    TQRLabel    * QRLabel3_1;
    TQRLabel    * QRLabel4_1;
    TQRLabel    * QRLabel5_1;
    TQRLabel    * QRLabel6_1;
    TQRLabel    * QRLabel7_1;
    TQRLabel    * QRLabel8_1;
    TQRLabel    * QRLabel9_1;
    TQRLabel    * QRLabel10_1;
    TQRLabel    * QRLabel11_1;
    TQRLabel    * QRLabel12_1;
    TQRLabel    * QRLabel13_1;
    TQRLabel    * QRLabel14_1;
    TQRLabel    * QRLabel15_1;
    TQRLabel    * QRLabel16_1;
    TQRLabel    * QRLabel17_1;
    TQRLabel    * QRLabel18_1;
    TQRLabel    * QRLabel19_1;
    TQRLabel    * QRLabel20_1;
    TQRLabel    * QRLabel21_1;
    TQRLabel    * QRLabel22_1;
    TQRLabel    * QRLabel23_1;
    TQRLabel    * QRLabel24_1;
    TQRLabel    * QRLabel25_1;
    TQRLabel    * QRLabel26_1;
    TQRLabel    * QRLabel27_1;
    TQRLabel    * QRLabel28_1;
    TQRLabel    * QRLabel29_1;
    TQRLabel    * QRLabel30_1;
    TQRLabel    * QRLabel31_1;
    TQRLabel    * QRLabel32_1;
    TQRLabel    * QRLabel33_1;
    TQRLabel    * QRLabel34_1;
    TQRLabel    * QRLabel35_1;
    TQRLabel    * QRLabel36_1;
    TQRLabel    * QRLabel37_1;
    TQRLabel    * QRLabel38_1;
    TQRLabel    * QRLabel39_1;
    TQRLabel    * QRLabel40_1;
    TQRLabel    * QRLabel41_1;

    TQRRichText * QRRichText1_1;

    TQRShape    * QRShape1_1;
    TQRShape    * QRShape2_1;
    TQRShape    * QRShape3_1;

    TQuickRep   * QuickRep1;
private:
public:
    __fastcall TExam_List_2Form (TComponent * Owner);
};

extern PACKAGE TExam_List_2Form * Exam_List_2Form;

#endif  // EXAM_LIST_2_UNIT_H