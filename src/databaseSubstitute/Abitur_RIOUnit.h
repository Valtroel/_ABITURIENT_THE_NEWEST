#pragma once
#ifndef ABITUR_RIO_UNIT_H
#define ABITUR_RIO_UNIT_H


#define TARGETED_TRAINING_ENROLLMENT
/* -----------------------------------------------------------------------------
 * !!!IMPORTANT NOTE !!!
 *
 * To activate the distribution of points for applicants for targeted training,
 * it is necessary to modify the stored procedure
 * KOL_SUMM_BALL3 in the database
 *     abitura.konkurs IN (0)
 * and change it to
 *     abitura.konkurs IN (0,3)
 * -----------------------------------------------------------------------------
 */

#define USE_SHORT_NCRB011_2022_PROFILING_NAME

#define DEBUG
#define TEST_FEATURE
//#define DEBUG_CHECK_VARIABLE_VALUES

//#define CHECK
//#define CHECK_ACCUMULATOR
//#define CHECK_GET_NUMBER
//#define CHECK_NUMBER_OF_RECORDS

//#define BUFFER_OUTPUT
//#define BUFFER_OUTPUT_FOR_SHORT
//#define BUFFER_OUTPUT_CALC_FOR_TOTAL_AND_BORDERING

//#define OTHER_SHEET_GENERATOR_IMPLEMENTATION

//#define SHOW_EXCEL_APPLICATION

//#define REFACTORING
//#ifndef REFACTORING
//#else
//#endif  // REFACTORING


#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.FB.hpp>
#include <FireDAC.Phys.FBDef.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.IBBase.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <System.Classes.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>

#include "func.h"


#include "Buffer.h"
#include "enums.hpp"
#include "properties.hpp"
#include "Ncrb011Handler.h"


class TForm3
    : public TForm
{
__published:
    TFDConnection       * FDConnection1;
    TFDConnection       * FDConnection2;

    TFDPhysFBDriverLink * FDPhysFBDriverLink1;

    TFDQuery            * QCK_Kol_Plan;
    TFDQuery            * QPlan_Priem_Konk_All_Param;
    TFDQuery            * QSpecializ;
    TFDQuery            * QStatistic_Every_Day_Ball_Price;
    TFDQuery            * Stat3hAll1Qr;
    TFDQuery            * Stat3hAll2Qr;
    TFDQuery            * Stat3hAll2Qr2;

    TFDStoredProc       * RaspredBall12StrdPrc;
    TFDStoredProc       * RaspredBall34StrdPrc;
    TFDStoredProc       * RaspredBallStrdPrc;

    TFDTable            * TFaculty;

    TLargeintField      * QStatistic_Every_Day_Ball_PriceCOUNT;
    TLargeintField      * Stat3hAll1QrCOUNT;
    TLargeintField      * Stat3hAll2Qr2COUNT;
    TLargeintField      * Stat3hAll2QrCOUNT;

    TSmallintField      * QCK_Kol_PlanKOL_PLACE;
    TSmallintField      * QPlan_Priem_Konk_All_ParamKOL_PLACE;
    TSmallintField      * QPlan_Priem_Konk_All_ParamN_SPECIALIZ;
    TSmallintField      * QSpecializN_FAC;
    TSmallintField      * QSpecializN_SPEC;
    TSmallintField      * QSpecializN_SPECIALIZ;
    TSmallintField      * QStatistic_Every_Day_Ball_PriceKONKURS;
    TSmallintField      * Stat3hAll1QrKONKURS;
    TSmallintField      * Stat3hAll2Qr2KONKURS;
    TSmallintField      * Stat3hAll2QrKONKURS;
    TSmallintField      * TFacultyKOD_FAC;
    TSmallintField      * TFacultyN_FAC;

    TStringField        * QPlan_Priem_Konk_All_ParamSPECIALIZ2;
    TStringField        * QSpecializCODE_SPECIALIZ;
    TStringField        * QSpecializSPECIAL_DIRECTION;
    TStringField        * QSpecializSPECIAL;
    TStringField        * TFacultyDEAN;
    TStringField        * TFacultyFAC_RP;
    TStringField        * TFacultyFAC;
    TStringField        * TFacultyFAC1;
private:
    AnsiString
        _fileName,
        _sheetName;
    int *
        _kos        [Default::MAX_NUMBER_OF_ITEMS];
    int
        _matrix     [Default::KINDS_OF_SPORT_LENGTH]
                    [Default::MAX_NUMBER_OF_ITEMS],

        _general    [Default::SECTIONS_ARRAY_LENGTH],
        _outOf      [Default::SECTIONS_ARRAY_LENGTH],
        _sections   [Default::SECTIONS_ARRAY_LENGTH],
        _target     [Default::SECTIONS_ARRAY_LENGTH],
        _targetPlan [Default::SECTIONS_ARRAY_LENGTH],
        _totalPlan  [Default::SECTIONS_ARRAY_LENGTH],
        _without    [Default::SECTIONS_ARRAY_LENGTH],

        _coaching   [Default::ACCUM_ARRAY_LENGTH],
        _improving  [Default::ACCUM_ARRAY_LENGTH],
        _management [Default::ACCUM_ARRAY_LENGTH],
        _physical   [Default::ACCUM_ARRAY_LENGTH],
        _spreader   [Default::ACCUM_ARRAY_LENGTH],
        _tourism    [Default::ACCUM_ARRAY_LENGTH],

//        _kos        [Default::MAX_NUMBER_ROW_ITEMS],
        _amountByContest,
        _columnNumber,
        _contestType,
        _counter,
        _educationType,
        _facultyNumber,
        _gainersNumber,
        _kindOfSportCode,
        _numberOfRecords,
        _numberOfSeats,
        _paymentType,
        _profilingCode,
        _recordsAmount,
        _rowNumber,
        _sectionIndex,
        _studyPeriod,
        _tergetsByPlan;
    Variant
        _excelApp,
        _selectedSheet,
        _workbook;
public:
    __fastcall TForm3 (TComponent * Owner);

    // GETTERS
    AnsiString   __fastcall getFileName        () const;
    AnsiString   __fastcall getSheetName       () const;

//    const int &  __fastcall getKOSAccum        ();

    const int *  __fastcall getCoachingAccum   ();
    const int *  __fastcall getGeneralAccum    ();
    const int *  __fastcall getImprovingAccum  ();
//    const int *  __fastcall getKOSAccum        ();
    const int *  __fastcall getManagmentAccum  ();
    const int *  __fastcall getOutOfAccum      ();
    const int *  __fastcall getPhysicalAccum   ();
    const int *  __fastcall getSectionAccum    ();
    const int *  __fastcall getSpreaderAccum   ();
    const int *  __fastcall getTargetAccum     ();
    const int *  __fastcall getTargetPlanAccum ();
    const int *  __fastcall getTotalPlanAccum  ();
    const int *  __fastcall getTourismAccum    ();
    const int *  __fastcall getWithoutAccum    ();

    int          __fastcall getAmountByContest () const;
    int          __fastcall getColumnNumber    () const;
    int          __fastcall getContestType     () const;
    int          __fastcall getCounter         () const;
    int          __fastcall getEducationType   () const;
    int          __fastcall getFacultyNumber   () const;
    int          __fastcall getGainersNumber   () const;
    int          __fastcall getKindOfSportCode () const;
    int          __fastcall getNumberOfRecords () const;
    int          __fastcall getNumberOfSeats   () const;
    int          __fastcall getPaymentType     () const;
    int          __fastcall getProfilingCode   () const;
    int          __fastcall getRecordsAmount   () const;
    int          __fastcall getRowNumber       () const;
    int          __fastcall getSectionIndex    () const;
    int          __fastcall getStudyPeriod     () const;
    int          __fastcall getTargetsByPlan   () const;

    Variant      __fastcall getExcelApp        () const;
    Variant      __fastcall getSelectedSheet   () const;
    Variant      __fastcall getWorkbook        () const;
    // SETTERS
    void __fastcall setFileName        (const AnsiString & fileName);
    void __fastcall setSheetName       (const AnsiString & sheetName);

    void __fastcall setAmountByContest (const int amountByContest);
    void __fastcall setColumnNumber    (const int columnNumber);
    void __fastcall setContestType     (const int contestType);
    void __fastcall setCounter         (const int number);
    void __fastcall setEducationType   (const int educationType);
    void __fastcall setFacultyNumber   (const int facultyCode);
    void __fastcall setGainersNumber   (const int amountWhoScored);
    void __fastcall setKindOfSportCode (const int kindOfSportCode);
    void __fastcall setNumberOfRecords (const int amount);
    void __fastcall setNumberOfSeats   (const int amount);
    void __fastcall setPaymentType     (const int payment);
    void __fastcall setProfilingCode   (const int nSpecDirCode);
    void __fastcall setRecordsAmount   (const int recordsAmount);
    void __fastcall setRowNumber       (const int lineNumber);
    void __fastcall setSectionIndex    (const int index);
    void __fastcall setStudyPeriod     (const int studyPeriod);
    void __fastcall setTargetsByPlan   (const int amountTargets);

    void __fastcall setExcelApp        (const Variant & excelApp);
    void __fastcall setSelectedSheet   (const Variant & selectedSheet);
    void __fastcall setWorkbook        (const Variant & workbook);


    // DATE & TIME
    AnsiString getCurrentDate                     ();
    AnsiString getCurrentHours                    ();
    AnsiString timeToPath                         (const AnsiString & time);


    // AUXILIARY
    AnsiString getFacultyName                     (const int facultyCode);
    AnsiString getFacultyShortName                (const int facultyCode);

    AnsiString getPartOfSheetNameForStudyPeriod   ();
    AnsiString getPartOfSheetNameForEducationType ();
    AnsiString getPartOfSheetNameForPayment       ();

    AnsiString getReportName                      ();


    //ACCUMULATORS
    void __fastcall activateSectionsAccum         (const int section2022Code);
    bool __fastcall checkBounds                   (
            const int position,
            const int length
        ) const;
    void __fastcall fillAccumBySection            (
                  int * arr,
            const int   index,
            const int   value
        );
    void __fastcall fillGainersByProfiling        (const int index);

    int  __fastcall getValueFromKOS               (
            const int rowIndex,
            const int columnIndex
        );

    int  __fastcall getValueBySection             (
            const int * arr,
            const int   index
        );
    int  __fastcall getValueFromCoaching          (const int index);
    int  __fastcall getValueFromGeneral           (const int index);
    int  __fastcall getValueFromImproving         (const int index);
    int  __fastcall getValueFromManagement        (const int index);
    int  __fastcall getValueFromOutOf             (const int index);
    int  __fastcall getValueFromPhysical          (const int index);
    int  __fastcall getValueFromSection           (const int index);
    int  __fastcall getValueFromSpreader          (const int index);
    int  __fastcall getValueFromTarget            (const int index);
    int  __fastcall getValueFromTargetPlan        (const int index);
    int  __fastcall getValueFromTotalPlan         (const int index);
    int  __fastcall getValueFromTourism           (const int index);
    int  __fastcall getValueFromWithout           (const int index);

    void __fastcall resetAccumulator              (
                  int * arr,
            const int   length
        );
    void __fastcall resetAllGainersAccum          ();
    void __fastcall resetAllSectionsAccum         ();
    void __fastcall resetSectionAccum             (const int section2022Code);

    void __fastcall setValueToCoaching            (
            const int index,
            const int value
        );
    void __fastcall setValueToGeneral             (
            const int index,
            const int value
        );
    void __fastcall setValueToImproving           (
            const int index,
            const int value
        );
    void __fastcall setValueToManagement          (
            const int index,
            const int value
        );
    void __fastcall setValueToOutOf               (
            const int index,
            const int value
        );
    void __fastcall setValueToPhysical            (
            const int index,
            const int value
        );
    void __fastcall setValueToSection             (
            const int index,
            const int value
        );
    void __fastcall setValueToSpreader            (
            const int index,
            const int value
        );
    void __fastcall setValueToTarget              (
            const int index,
            const int value
        );
    void __fastcall setValueToTargetPlan          (
            const int index,
            const int value
        );
    void __fastcall setValueToTotalPlan           (
            const int index,
            const int value
        );
    void __fastcall setValueToTourism             (
            const int index,
            const int value
        );
    void __fastcall setValueToWithout             (
            const int index,
            const int value
        );


    // EXCEL
    Variant __fastcall createExcelApp             ();
    void    __fastcall deleteExtraSheets          ();
    void    __fastcall deleteSteet                (const AnsiString & sheetName);
    void    __fastcall finalClear                 ();
    void    __fastcall initBook                   ();
    void    __fastcall initSheet                  ();
    Variant __fastcall openExcelBook              ();
    void    __fastcall quitExcelApp               ();
    Variant __fastcall saveExcelApp               ();
    Variant __fastcall saveWorkbookAs             ();
    Variant __fastcall selectSheet                ();


    // OUTPUT
    void       writeAmountByContest               ();
    void       writeCalcForTotalApplicants        ();
    void       writeDataBordering                 ();
    void       writeDateAndHours                  ();
    void       writeFacultyName                   ();
    void       writeFacultyNameSMAWithMS          ();
    void       writeGatheredNumberOfGainers       (const int * arr);
    void       writeGatheredSectionsName          (const int * arr);
    void       writeNumberOfGainers               ();
    void       writeSportNAmountByPlan            ();
    void       writeTargetedByPlan                ();
    void       writeTotalsForFullCourse           ();
    void       writeTotalsForShortExceptSMA       ();
    void       writeTotalsForShortSMAWithSM       ();
    void       writeUniqueFacultyNameForShort     ();

    // OVERLOADING
//    int && operator [] (const int index)
//    {
//        if (checkBounds (
//                index,
//                Default::MAX_NUMBER_OF_ITEMS
//            )
//           )
//            return
//                this -> _kos [index];
//    }

    int * operator () (                                                           //GET value
            const int rowIndex,
            const int columnIndex
        ) const
    {
        return
            this ->
                _kos [
                        (
                            Default::MAX_NUMBER_OF_ITEMS
                          * rowIndex
                        )
                    +   columnIndex
                ];
    }
//    int & operator () (                                                         //SET value
//            const int rowIndex,
//            const int columnIndex
//        )
//    {
//        return
//            this ->
//                _kos [
//                        (
//                            Default::MAX_NUMBER_OF_ITEMS
//                          * rowIndex
//                        )
//                    +   columnIndex
//                ];
//    }

    int ( & operator [] (const int row ) )[Default::MAX_NUMBER_OF_ITEMS]
    {
        return
            this -> _matrix [row];
    }

    // LOGIC
    void __fastcall getNumberOfApplicants         ();
    void __fastcall distributingScores            ();

    #ifdef DEBUG_CHECK_VARIABLE_VALUES
    void showVariablesValue ();
    #endif // DEBUG_CHECK_VARIABLE_VALUES
};

extern PACKAGE TForm3 * Form3;

#endif  // ! ABITUR_RIO_UNIT_H