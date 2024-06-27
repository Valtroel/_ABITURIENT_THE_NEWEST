#pragma once
#ifndef STAT_RESULT_EXAM_UNIT_H
#define STAT_RESULT_EXAM_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>


#include "properties.hpp"
#include "enums.hpp"


class TStat_Result_examForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;                                                // CAN BE DELETED

    TComboBox         * ComboBox1;
    TComboBox         * Vid_edu;

    TDBGrid           * DBGrid1;

    TDBLookupComboBox * LookPredm;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;

    TPanel            * Panel1;

    TRadioGroup       * RadioGroup1;

    void __fastcall BitBtn1Click     (TObject * Sender);
    void __fastcall BitBtn2Click     (TObject * Sender);
    void __fastcall FormClose        (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall LookPredmCloseUp (TObject * Sender);
    void __fastcall Vid_eduChange    (TObject * Sender);
private:
    // int
    //     col_rec_ex,
    //     nom_r,                                                              // счетчик строк                    // _rowCounter,
    //     rec_stat,                                                           // Количество записей               // _recordNumber,
    //     spec_ex;                                                            // определение номера специализации // _kindOfSportCode;

    // TFDQuery *
    //     q;                                                                  // запрос с которым будем работать  // _query;

    // Variant
    //     ExcelApp_ex;                                                         // _excelApp;
public:
    __fastcall TStat_Result_examForm (TComponent * Owner);


    enum CharacterCode
    {
        RESULTS_CHAR_C             = 2,
        RESULTS_CHAR_D             = 3,
        RESULTS_CHAR_F             = 5,
        RESULTS_CHAR_H             = 7,
        RESULTS_CHAR_J             = 9,
        RESULTS_CHAR_L             = 11,
        RESULTS_CHAR_N             = 13,
        RESULTS_CHAR_P             = 15,
        RESULTS_CHAR_R             = 17,
        RESULTS_CHAR_T             = 19,
        RESULTS_CHAR_V             = 21,
        RESULTS_CHAR_X             = 23
    };
    enum ColumnFor
    {
        RESULTS_TOTAL              = 2,
        RESULTS_PASSED             = 3,
        RESULTS_10                 = 4,
        RESULTS_10_PERCENTAGES     = 5,
        RESULTS_9                  = 6,
        RESULTS_9_PERCENTAGES      = 7,
        RESULTS_8                  = 8,
        RESULTS_8_PERCENTAGES      = 9,
        RESULTS_7                  = 10,
        RESULTS_7_PERCENTAGES      = 11,
        RESULTS_6                  = 12,
        RESULTS_6_PERCENTAGES      = 13,
        RESULTS_5                  = 14,
        RESULTS_5_PERCENTAGES      = 15,
        RESULTS_4                  = 16,
        RESULTS_4_PERCENTAGES      = 17,
        RESULTS_3                  = 18,
        RESULTS_3_PERCENTAGES      = 19,
        RESULTS_CERT_END_DATA      = 19,
        RESULTS_2                  = 20,
        RESULTS_2_PERCENTAGES      = 21,
        RESULTS_CERT_END_DATA_MSTH = 21,
        RESULTS_1                  = 22,
        RESULTS_1_PERCENTAGES      = 23,
        RESULTS_0                  = 24,
        RESULTS_0_PERCENTAGES      = 25,
        RESULTS_DC                 = 26,
        RESULTS_EXAMEN_END_DATA    = 26
    };
    enum Default
    {
        RESULTS_STEP               = 1,
        RESULTS_DATA_SHIFT         = 2
    };
    enum RowFor
    {
        RESULTS_TITLE              = 2,
        RESULTS_EDU_TYPE           = 3,
        RESULTS_FACULTY_NAME       = 5,
        RESULTS_START_DATA         = 9,
    };
    enum TypeOfTestCode
    {
        RESULTS_EXAMS              = 0,                                         // 0 -> экзамены
        RESULTS_CERTS              = 1,                                         // 1 -> сертификаты
        RESULTS_CONTESTS           = 2,                                         // 2 -> Олимпиады
        RESULTS_OTHER              = 3                                          // 3 -> Экзамены в др. Вузах
    };


    void       __fastcall borderingCells                      (
            const int numberOfColums,
            const int numberOfRows
        );
    void       __fastcall checkRequiredParameters             ();
    void       __fastcall distributeData                      ();
    AnsiString __fastcall getFileName                         (
            const int educationTypeCode,
            const int typeOfTestCode,
            const int subjectCode
        );
    int        __fastcall getNumberOfLastColumn               (
            const int typeOfTestCode
        );
    AnsiString __fastcall getSubjectName                      (
            const int subjectCode
        );
    AnsiString __fastcall getTitle                            (
            const int typeOfTestCode
        );
    void       __fastcall writeCalcForPassedCerts             (
            const int rowNumber
        );
    void       __fastcall writeCalcForPassedCertsMSTH         (
            const int rowNumber
        );
    void       __fastcall writeCalcForPassedCertsMSTHTargeted (
            const int rowNumber
        );
    void       __fastcall writeCalcForPassedExams             (
            const int rowNumber
        );
    void       __fastcall writeCalcForTotalPassedExams        (
            const int rowNumber
        );
    void       __fastcall writeFooter                         (
            const int rowNumber
        );
    void       __fastcall writeParticipants                   (
            const int amountParticipants,
            const int amountColumn,
            const int rowNumber,
            const int characterCode,
            const int percentColumn
        );
    void       __fastcall writeTotals                         (
            const int numberOfColums,
            const int rowNumber
        );
};

extern PACKAGE TStat_Result_examForm * Stat_Result_examForm;

#endif  // STAT_RESULT_EXAM_UNIT_H
