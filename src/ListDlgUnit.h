#pragma once
#ifndef LIST_DLG_UNIT_H
#define LIST_DLG_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>

#include "enums.hpp"
#include "properties.hpp"
#include "Ncrb011TemporaryConverter.h"


//#define TESTING_LIST_DLG_UNIT

class TListDlgForm
    : public TForm
{
__published:
    TBitBtn      * BitBtn2;
    TBitBtn      * BitBtn3;
    TBitBtn      * BitBtn5;
    TBitBtn      * ContractBtBtn;
    TBitBtn      * ExamSht1BtBtn;
    TBitBtn      * ExamSht2BtBtn;
    TBitBtn      * ExamShtAllBtBtn;

    TLabel       * FIOLbl;
    TLabel       * Label1;
    TLabel       * Label2;
    TLabel       * Label4;

    TListBox     * ListBox1;
    TListBox     * ListBox2;

    TSpeedButton * PleaSpdBtn;
    TSpeedButton * SpeedButton1;
    TSpeedButton * SpeedButton2;
    TSpeedButton * SpeedButton3;
    TSpeedButton * SpeedButton4;

    void    __fastcall BitBtn2Click         (TObject        * Sender);
    void    __fastcall BitBtn3Click         (TObject        * Sender);
    void    __fastcall BitBtn5Click         (TObject        * Sender);
    void    __fastcall ContractBtBtnClick   (TObject        * Sender);
    void    __fastcall DBEdit1KeyPress      (
            TObject * Sender,
            char    & Key
        );
    void    __fastcall Exam_list_first      ();
    void    __fastcall Exam_list_two        ();
    void    __fastcall ExamSht1BtBtnClick   (TObject        * Sender);
    void    __fastcall ExamSht2BtBtnClick   (TObject        * Sender);
    void    __fastcall ExamShtAllBtBtnClick (TObject        * Sender);
    void    __fastcall FormActivate         (TObject        * Sender);
    void    __fastcall FormClose            (
            TObject      * Sender,
            TCloseAction & Action
        );
    void    __fastcall FormCreate           (TObject        * Sender);
    Integer __fastcall GetFirstSelection    (TCustomListBox * List  );
    void    __fastcall ListBox1DblClick     (TObject        * Sender);
    void    __fastcall ListBox2DblClick     (TObject        * Sender);
    void    __fastcall MoveSelected         (
            TCustomListBox * List,
            TStrings       * Items
        );
    void    __fastcall PleaSpdBtnClick      (TObject        * Sender);
    void    __fastcall SetButtons           ();
    void    __fastcall SetItem              (
            TListBox * List,
            int        Index
        );
    void    __fastcall SpeedButton1Click    (TObject        * Sender);
    void    __fastcall SpeedButton2Click    (TObject        * Sender);
    void    __fastcall SpeedButton3Click    (TObject        * Sender);
    void    __fastcall SpeedButton4Click    (TObject        * Sender);
    void    __fastcall StringSertificat     ();
private:
    static const int        ELIMINATE_PRIMES            = 18;                   // shift to eliminate primes (exp: digit_names [18 + 20 / 10] -> "двадцать")
    static const int        INDEX_VALUE_ONE_HUNDRED     = 28;                   // index pointing to 100 as a word
    static const AnsiString DIGIT_NAMES_FRACTIONAL_PART [11];
    static const AnsiString DIGIT_NAMES_INTEGER_PART    [29];
public:
    __fastcall TListDlgForm (TComponent * Owner);

    AnsiString decimalStrToWord                    (AnsiString decimalAsString);// example: "54,8" -> "пятьдесят четыре целых восемь десятых"
    AnsiString numberToWords                       (                            // converter logic
            int  number,
            bool isIntegerPart
        );
    AnsiString scoresToWords                       (                            // main method for converting scores to words (previously was text_ball())
            double scores,
            bool   isIntegerPart
        );
    AnsiString doubleToStringWithFractionalPart    (double     scores);         // example: 34.3553 -> "34,4"
    AnsiString doubleToStringWithoutFractionalPart (double     scores);         // example: 34.4553 -> "34"
    AnsiString getDigitNameOfFractionalPart        (int        digit);          // example: 21 -> "тридцать" (see: convertNumberToWords ())
    AnsiString getDigitNameOfIntegerPart           (int        digit);          // example: 1 -> "одна" (see: convertNumberToWords ())
    AnsiString getInfoAboutDocumentOnEducation     (
            const AnsiString & documentNumber,
            const AnsiString & organization,
            const AnsiString & location,
            const AnsiString & issueYear
        );
    AnsiString getSubjectNameFromCode              (int        subjectCode);    // convert the subject code to subject name as string (previously was text_predm ())
};

extern PACKAGE TListDlgForm * ListDlgForm;

#endif  // LIST_DLG_UNIT_H