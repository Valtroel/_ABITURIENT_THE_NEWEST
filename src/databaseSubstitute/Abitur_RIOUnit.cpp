#include <vcl.h>
#pragma hdrstop


#include "Abitur_RIOUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"



TForm3 * Form3;



// GETTERS
AnsiString   __fastcall TForm3::getFileName        () const
{
    return
        this -> _fileName;
}
AnsiString   __fastcall TForm3::getSheetName       () const
{
    return
        this -> _sheetName;
}
//const int & __fastcall TForm3::getKOSAccum        ()
//{
//    return
//        this -> _kos;
//}
const int *  __fastcall TForm3::getCoachingAccum   ()
{
    return
        this -> _coaching;
}
const int *  __fastcall TForm3::getGeneralAccum    ()
{
    return
        this -> _general;
}
const int *  __fastcall TForm3::getImprovingAccum  ()
{
    return
        this -> _improving;
}
const int *  __fastcall TForm3::getManagmentAccum  ()
{
    return
        this -> _management;
}
const int *  __fastcall TForm3::getOutOfAccum      ()
{
    return
        this -> _outOf;
}
const int *  __fastcall TForm3::getPhysicalAccum   ()
{
    return
        this -> _physical;
}
const int *  __fastcall TForm3::getSectionAccum    ()
{
    return
        this -> _sections;
}
const int *  __fastcall TForm3::getSpreaderAccum   ()
{
    return
        this -> _spreader;
}
const int *  __fastcall TForm3::getTargetAccum     ()
{
    return
        this -> _target;
}
const int *  __fastcall TForm3::getTargetPlanAccum ()
{
    return
        this -> _targetPlan;
}
const int *  __fastcall TForm3::getTotalPlanAccum  ()
{
    return
        this -> _totalPlan;
}
const int *  __fastcall TForm3::getTourismAccum    ()
{
    return
        this -> _tourism;
}
const int *  __fastcall TForm3::getWithoutAccum    ()
{
    return
        this -> _without;
}
int          __fastcall TForm3::getAmountByContest () const
{
    return
        this -> _amountByContest;
}
int          __fastcall TForm3::getColumnNumber    () const
{
    return
        this -> _columnNumber;
}
int          __fastcall TForm3::getContestType     () const
{
    return
        this -> _contestType;
}
int          __fastcall TForm3::getCounter         () const
{
    return
        this -> _counter;
}
int          __fastcall TForm3::getEducationType   () const
{
    return
        this -> _educationType;
}
int          __fastcall TForm3::getFacultyNumber   () const
{
    return
        this -> _facultyNumber;
}
int          __fastcall TForm3::getGainersNumber   () const
{
    return
        this -> _gainersNumber;
}
int          __fastcall TForm3::getKindOfSportCode () const
{
    return
        this -> _kindOfSportCode;
}
int          __fastcall TForm3::getNumberOfRecords () const
{
    return
        this -> _numberOfRecords;
}
int          __fastcall TForm3::getNumberOfSeats   () const
{
    return
        this -> _numberOfSeats;
}
int          __fastcall TForm3::getPaymentType     () const
{
    return
        this -> _paymentType;
}
int          __fastcall TForm3::getProfilingCode   () const
{
    return
        this -> _profilingCode;
}
int          __fastcall TForm3::getRecordsAmount   () const
{
    return
        this -> _recordsAmount;
}
int          __fastcall TForm3::getRowNumber       () const
{
    return
        this -> _rowNumber;
}
int          __fastcall TForm3::getStudyPeriod     () const
{
    return
        this -> _studyPeriod;
}
int          __fastcall TForm3::getTargetsByPlan   () const
{
    return
        this -> _tergetsByPlan;
}
Variant      __fastcall TForm3::getExcelApp        () const
{
    return
        this -> _excelApp;
}
Variant      __fastcall TForm3::getSelectedSheet   () const
{
    return
        this -> _selectedSheet;
}
Variant      __fastcall TForm3::getWorkbook        () const
{
    return
        this -> _workbook;
}
// SETTERS
void __fastcall TForm3::setFileName        (const AnsiString & fileName)
{
    this -> _fileName = fileName;
}
void __fastcall TForm3::setSheetName       (const AnsiString & sheetName)
{
    this -> _sheetName = sheetName;
}
void __fastcall TForm3::setAmountByContest (const int amountByContest)
{
    this -> _amountByContest = amountByContest;
}
void __fastcall TForm3::setColumnNumber    (const int columnNumber)
{
    this -> _columnNumber = columnNumber;
}
void __fastcall TForm3::setContestType     (const int contestType)
{
    this -> _contestType = contestType;
}
void __fastcall TForm3::setCounter         (const int number)
{
    this -> _counter = number;
}
void __fastcall TForm3::setEducationType   (const int educationType)
{
    this -> _educationType = educationType;
}
void __fastcall TForm3::setFacultyNumber   (const int facultyCode)
{
    this -> _facultyNumber = facultyCode;
}
void __fastcall TForm3::setGainersNumber   (const int amountWhoScored)
{
    this -> _gainersNumber = amountWhoScored;
}
void __fastcall TForm3::setKindOfSportCode (const int kindOfSportCode)
{
    this -> _kindOfSportCode = kindOfSportCode;
}
void __fastcall TForm3::setNumberOfRecords (const int amount)
{
    this -> _numberOfRecords = amount;
}
void __fastcall TForm3::setNumberOfSeats   (const int amount)
{
    this -> _numberOfSeats = amount;
}
void __fastcall TForm3::setPaymentType     (const int payment)
{
    this -> _paymentType = payment;
}
void __fastcall TForm3::setProfilingCode   (const int nSpecDirCode)
{
    this -> _profilingCode = nSpecDirCode;
}
void __fastcall TForm3::setRecordsAmount   (const int recordsAmount)
{
    this -> _recordsAmount = recordsAmount;
}
void __fastcall TForm3::setRowNumber       (const int lineNumber)
{
    this -> _rowNumber = lineNumber;
}
void __fastcall TForm3::setSectionIndex    (const int index)
{
    this -> _sectionIndex = index;
}
void __fastcall TForm3::setStudyPeriod     (const int studyPeriod)
{
    this -> _studyPeriod = studyPeriod;
}
void __fastcall TForm3::setTargetsByPlan   (const int amountTargets)
{
    this -> _tergetsByPlan = amountTargets;
}
void __fastcall TForm3::setExcelApp        (const Variant & excelApp)
{
    this -> _excelApp = excelApp;
}
void __fastcall TForm3::setSelectedSheet   (const Variant & selectedSheet)
{
    this -> _selectedSheet = selectedSheet;
}
void __fastcall TForm3::setWorkbook        (const Variant & workbook)
{
    this -> _workbook = workbook;
}


// DATE & TIME
AnsiString TForm3::getCurrentDate ()
{
    TDateTime
        currentDate;

    return
        AnsiToUtf8 (
            currentDate.CurrentDate ()
        );
}
AnsiString TForm3::getCurrentHours ()
{
   TDateTime
        currentDate;

    AnsiString
        currentHours =
            AnsiToUtf8 (
                currentDate.CurrentTime ()
            )
            .SetLength (2);

    if (currentHours.IsDelimiter ("\\:", 2))
        currentHours = currentHours.SetLength (1);

    return
        currentHours + ":00";
}
AnsiString TForm3::timeToPath (const AnsiString & time)
{
    return
        StringReplace (
            time,
            ":",
            ".",
            TReplaceFlags () << rfReplaceAll
        );
}


// AUXILIARY
AnsiString TForm3::getFacultyName (const int facultyCode)
{
    switch (static_cast <FacultyCode> (facultyCode))
    {
        case FacultyCode::SMA:                                                  // 1, -> Sports and Marital Arts (СИиЕ)
            return
                Faculty::NAME::SMA;                                             // 1, -> "Спортивно-педагогический факультет спортивных игр и единоборств",
        case FacultyCode::MS:                                                   // 2, -> Mass Sports (МВС)
            return
                Faculty::NAME::MS;                                              // 2, -> "Спортивно-педагогический факультет массовых видов спорта",
        case FacultyCode::RPC:                                                  // 3, -> Recreational Physical Culture (ОФКиТ)
            return
                Faculty::NAME::RPC;                                             // 3, -> "Факультет оздоровительной физической культуры",
        case FacultyCode::MSTH:                                                 // 4, -> Management of Sports, Tourism and Hospitality (МСиТ)
            return
                Faculty::NAME::MSTH;                                            // 4, -> "Факультет менеджмента спорта, туризма и гостеприимства",
        case FacultyCode::MD:                                                   // 5, -> Master's Degree (Магстратура)
            return
                Faculty::NAME::MD;                                              // 5, -> "Магстратура",
        case FacultyCode::PGS:                                                  // 6, -> PostGraduate Studies (Аспирантура)
            return
                Faculty::NAME::PGS;                                             // 6, -> "Аспирантура",
        case FacultyCode::DOC:                                                  // 7  -> DOCtorate (Докторантура)
            return
                Faculty::NAME::DOC;                                             // 7  -> "Докторантура";

        default:
            ShowMessage (
                "ERROR:\n"                              \
                "The getFacultyName (int facultyCode) " \
                "method returns:\n"                     \
                "Value: "                               +
                    AnsiString (facultyCode)            +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    facultyCode
                );
    }
}
AnsiString TForm3::getFacultyShortName (
        const int facultyCode
    )
{
    switch (static_cast <FacultyCode> (facultyCode))
    {
        case FacultyCode::SMA:                                                  // 1, -> Sports and Marital Arts (СИиЕ)
            return
                Faculty::SHORT::SMA;                                            // 1, -> "СИиЕ",
        case FacultyCode::MS:                                                   // 2, -> Mass Sports (МВС)
            return
                Faculty::SHORT::MS;                                             // 2, -> "МВС",
        case FacultyCode::RPC:                                                  // 3, -> Recreational Physical Culture (ОФКиТ)
            return
                Faculty::SHORT::RPC;                                            // 3, -> "ОФК",
        case FacultyCode::MSTH:                                                 // 4, -> Management of Sports, Tourism and Hospitality (МСиТ)
            return
                Faculty::SHORT::MSTH;                                           // 4, -> "МСТиГ",
        case FacultyCode::MD:                                                   // 5, -> Master's Degree (Магстратура)
            return
                Faculty::SHORT::MD;                                             // 5, -> "Магстратура",
        case FacultyCode::PGS:                                                  // 6, -> PostGraduate Studies (Аспирантура)
            return
                Faculty::SHORT::PGS;                                            // 6, -> "Аспирантура",
        case FacultyCode::DOC:                                                  // 7  -> DOCtorate (Докторантура)
            return
                Faculty::SHORT::DOC;                                            // 7  -> "Докторантура";

        default:
            ShowMessage (
                "ERROR:\n"                                      \
                "The getFacultyShortName (int facultyCode) "    \
                "method returns:\n"                             \
                "Value: "                                       +
                    AnsiString (facultyCode)                    +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    facultyCode
                );
    }
}

AnsiString TForm3::getPartOfSheetNameForStudyPeriod ()
{
    switch (static_cast <StudyPeriodCode> (getStudyPeriod ()))
    {
        case StudyPeriodCode::FULL:
            return
                "П.";
        case StudyPeriodCode::SHORT_SECOND_COURSE:
            return
                "С.";
        case StudyPeriodCode::SHORT_THIRD_COURSE:
            return
                "С.";
        default:
            return
                "П.";
    }
}
AnsiString TForm3::getPartOfSheetNameForEducationType ()
{
    switch (static_cast <EducationTypeCode> (getEducationType ()))
    {
        case EducationTypeCode::INTRAMURAL:
            return
                "Д.";
        case EducationTypeCode::EXTRAMURAL:
            return
                "З.";
        default:
            return
                "Д.";
    }
}
AnsiString TForm3::getPartOfSheetNameForPayment ()
{
    switch (static_cast <PaymentCode> (getPaymentType ()))
    {
        case PaymentCode::BUDGET:
            return
                "Б.";
        case PaymentCode::BUYERS:
            return
                "О.";
        default:
            return
                "Б.";
    }
}

AnsiString TForm3::getReportName ()
{
    return
            getFacultyShortName (
                getFacultyNumber ()
            )                                   +
        ". "                                    +
            Document::STATISTIC::NAME::SCORES   +
        " за "                                 +
            getCurrentDate ()                   +
        ", на "                                 +
            timeToPath (
                getCurrentHours ()
            )                                   +
        ".xls";
}


// ACCUMULATORS
void __fastcall TForm3::activateSectionsAccum  (const int section2022Code)
{
    switch (static_cast <Section2022Code> (section2022Code))
    {
        case Section2022Code::PHYSICAL_CULTURE_2022:                            // 0 -> 6-05-1012-01
                setValueToSection (
                    Section2022Code::PHYSICAL_CULTURE_2022,                     // _sections[0]
                    Default::ENABLE
                );
            break;
        case Section2022Code::COACHING_2022:                                    // 1 -> 6-05-1012-02
                setValueToSection (
                    Section2022Code::COACHING_2022,                             // _sections[1]
                    Default::ENABLE
                );
            break;
        case Section2022Code::REHABILITATION_2022:                              // 2 -> 6-05-1012-03
                setValueToSection (
                    Section2022Code::REHABILITATION_2022,                       // _sections[2]
                    Default::ENABLE
                );
            break;
        case Section2022Code::MANAGEMENT_2022:                                  // 3 -> 6-05-1012-04
                setValueToSection (
                    Section2022Code::MANAGEMENT_2022,                           // _sections[3]
                    Default::ENABLE
                );
            break;
        case Section2022Code::TOURISM_2022:                                     // 4 -> 6-05-1013-01
                setValueToSection (
                    Section2022Code::TOURISM_2022,                              // _sections[4]
                    Default::ENABLE
                );
            break;
    }
}
bool __fastcall TForm3::checkBounds            (
        const int position,
        const int length
    ) const
{
    if (    position >= 0
         && position <  length
       )
        return
            true;
    return
        false;
}
void __fastcall TForm3::fillAccumBySection     (
              int * arr,
        const int   index,
        const int   value
    )
{
    switch (static_cast <Section2022Code> (index))
    {
        case Section2022Code::PHYSICAL_CULTURE_2022:                            // 0 -> 6-05-1012-01
                arr[Section2022Code::PHYSICAL_CULTURE_2022] += value;           // arr[0]
            break;
        case Section2022Code::COACHING_2022:                                    // 1 -> 6-05-1012-02
                arr[Section2022Code::COACHING_2022]         += value;           // arr[1]
            break;
        case Section2022Code::REHABILITATION_2022:                              // 2 -> 6-05-1012-03
                arr[Section2022Code::REHABILITATION_2022]   += value;           // arr[2]
            break;
        case Section2022Code::MANAGEMENT_2022:                                  // 3 -> 6-05-1012-04
                arr[Section2022Code::MANAGEMENT_2022]       += value;           // arr[3]
            break;
        case Section2022Code::TOURISM_2022:                                     // 4  -> 6-05-1013-01
                arr[Section2022Code::TOURISM_2022]          += value;           // arr[4]
            break;

        default:
            ShowMessage (
                "ERROR:\n"                          \
                "The fillAccumBySection (\n"        \
                "\t\tconst int * arr,\n"            \
                "\t\tconst int   index,\n"          \
                "\t\tconst int   value\n"           \
                "\t)\n"                             \
                "method returns:\n"                 \
                "The index: \""                     +
                    AnsiString (index)              +
                "\"\t is out of bounds and the "    \
                " value: \""                        +
                    AnsiString (value)              +
                "\"\t cannot be set!"
            );
    }
}
void __fastcall TForm3::fillGainersByProfiling (const int index)
{
    switch (    static_cast <ProfilingCode> (
                    InsteadDb::getProfilingCodeByNSpecializ (
                        getKindOfSportCode ()
                    )
                )
        )
    {
        case ProfilingCode::NSPECDIR_SPORT_COACHING:                            // 1,  -> "Тренерская работа по",
                if (getGainersNumber ())
                    setValueToCoaching (
                        index,
                        getValueFromCoaching (index) +
                        getGainersNumber ()
                    );
            break;
        case ProfilingCode::NSPECDIR_SPORT_PSYCHOLOGY:                          // 2,  -> "Спортивная психология",
            if (getGainersNumber ())
                    setValueToPhysical (
                        index,
                        getValueFromPhysical (index) +
                        getGainersNumber ()
                    );
            break;
        case ProfilingCode::NSPECDIR_SPORT_DIRECTING:                           // 3,  -> "Спортивная режиссура",
            if (getGainersNumber ())
                    setValueToPhysical (
                        index,
                        getValueFromPhysical (index) +
                        getGainersNumber ()
                    );
            break;
        case ProfilingCode::NSPECDIR_SPORT_MANAGEMENT:                          // 4,  -> "Менеджмент в спорте",
            if (getGainersNumber ())
                    setValueToManagement (
                        index,
                        getValueFromManagement (index) +
                        getGainersNumber ()
                    );
            break;
        case ProfilingCode::NSPECDIR_MANAGEMENT_RECREATIONAL:                   // 5,  -> "Спортивный и рекреационный туризм",
            if (getGainersNumber ())
                    setValueToPhysical (
                        index,
                        getValueFromPhysical (index) +
                        getGainersNumber ()
                    );
            break;
        case ProfilingCode::NSPECDIR_MANAGEMENT_TOURISM_MNG:                    // 6,  -> "Менеджмент в туризме",
            if (getGainersNumber ())
                    setValueToManagement (
                        index,
                        getValueFromManagement (index) +
                        getGainersNumber ()
                    );
            break;
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_MEDICAL:                  // 7,  -> "Лечебная",
            if (getGainersNumber ())
                    setValueToPhysical (
                        index,
                        getValueFromPhysical (index) +
                        getGainersNumber ()
                    );
            break;
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS:             // 8,  -> "Дошкольников",
            if (getGainersNumber ())
                    setValueToPhysical (
                        index,
                        getValueFromPhysical (index) +
                        getGainersNumber ()
                    );
            break;
        case ProfilingCode::NSPECDIR_IMPROVING_HEALTH:                          // 9,  -> "Оздоровительная",
            if (getGainersNumber ())
                    setValueToPhysical (
                        index,
                        getValueFromPhysical (index) +
                        getGainersNumber ()
                    );
            break;
        case ProfilingCode::NSPECDIR_IMPROVING_ADAPTIVE:                        // 10, -> "Адаптивная",
            if (getGainersNumber ())
                    setValueToPhysical (
                        index,
                        getValueFromPhysical (index) +
                        getGainersNumber ()
                    );
            break;
        case ProfilingCode::NSPECDIR_REHABILITATION_REHABILITATION:             // 11, -> "Физическая реабилитация",
            if (getGainersNumber ())
                    setValueToImproving (
                        index,
                        getValueFromImproving (index) +
                        getGainersNumber ()
                    );
            break;
        case ProfilingCode::NSPECDIR_REHABILITATION_ERGOTHERAPY:                // 12, -> "Эрготерапия",
            if (getGainersNumber ())
                    setValueToImproving (
                        index,
                        getValueFromImproving (index) +
                        getGainersNumber ()
                    );
            break;
        case ProfilingCode::NSPECDIR_TOURISM_HOSPITALITY:                       // 13, -> "Туризм и гостеприимство",
            if (getGainersNumber ())
                    setValueToTourism (
                        index,
                        getValueFromTourism (index) +
                        getGainersNumber ()
                    );
            break;
    }
}

int  __fastcall TForm3::getValueFromKOS        (
            const int rowIndex,
            const int columnIndex
        )
{
//    if (    checkBounds (
//                rowIndex,
//                sizeof (getKOSAccum ()/soizeof (int *))
//            )
//         && checkBounds (
//                columnIndex,
//                Default::ACCUM_ARRAY_LENGTH
//            )
//
//       )
//        return
//            this -> _coaching [index];
//    else
//        return
//            Default::EMPTY;
}


int  __fastcall TForm3::getValueBySection      (
        const int * arr,
        const int   index
    )
{
    if (!checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
    {
        ShowMessage (
            "WARNING:\n"                        \
            "The getValueBySection (\n"         \
            "\t\tconst int * arr,\n"            \
            "\t\tconst int   index\n"           \
            "\t)\n"                             \
            "warns about:\n"                    \
            "The index: \""                     +
                AnsiString (index)              +
            "\"\t is out of bounds and the "    \
            "method returns the default "       \
            "value of zero!"
        );
        return
            Default::EMPTY;
    }

    switch (static_cast <Section2022Code> (index))
    {
        case Section2022Code::PHYSICAL_CULTURE_2022:                            // 0 -> 6-05-1012-01
            return
                arr[Section2022Code::PHYSICAL_CULTURE_2022];                    // arr[0]
        case Section2022Code::COACHING_2022:                                    // 1 -> 6-05-1012-02
            return
                arr[Section2022Code::COACHING_2022];                            // arr[1]
        case Section2022Code::REHABILITATION_2022:                              // 2 -> 6-05-1012-03
            return
                arr[Section2022Code::REHABILITATION_2022];                      // arr[2]
        case Section2022Code::MANAGEMENT_2022:                                  // 3 -> 6-05-1012-04
            return
                arr[Section2022Code::MANAGEMENT_2022];                          // arr[3]
        case Section2022Code::TOURISM_2022:                                     // 4  -> 6-05-1013-01
            return
                arr[Section2022Code::TOURISM_2022];                             // arr[4]
    }
}
int  __fastcall TForm3::getValueFromCoaching   (const int index)
{
    if (checkBounds (
            index,
            Default::ACCUM_ARRAY_LENGTH
        )
       )
        return
            this -> _coaching [index];
    else
        return
            Default::EMPTY;
}
int  __fastcall TForm3::getValueFromGeneral    (const int index)
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        return
            this -> _general [index];
    else
        return
            Default::EMPTY;
}
int  __fastcall TForm3::getValueFromImproving  (const int index)
{
    if (checkBounds (
            index,
            Default::ACCUM_ARRAY_LENGTH
        )
       )
        return
            this -> _improving [index];
    else
        return
            Default::EMPTY;
}
int  __fastcall TForm3::getValueFromManagement (const int index)
{
    if (checkBounds (
            index,
            Default::ACCUM_ARRAY_LENGTH
        )
       )
        return
            this -> _management [index];
    else
        return
            Default::EMPTY;
}
int  __fastcall TForm3::getValueFromOutOf      (const int index)
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        return
            this -> _outOf [index];
    else
        return
            Default::EMPTY;
}
int  __fastcall TForm3::getValueFromPhysical   (const int index)
{
    if (checkBounds (
            index,
            Default::ACCUM_ARRAY_LENGTH
        )
       )
        return
            this -> _physical [index];
    else
        return
            Default::EMPTY;
}
int  __fastcall TForm3::getValueFromSection    (const int index)
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        return
            this -> _sections [index];
    else
        return
            Default::EMPTY;
}
int  __fastcall TForm3::getValueFromSpreader   (const int index)
{
    if (checkBounds (
            index,
            Default::ACCUM_ARRAY_LENGTH
        )
       )
        return
            this -> _spreader [index];
    else
        return
            Default::EMPTY;
}
int  __fastcall TForm3::getValueFromTarget     (const int index)
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        return
            this -> _target [index];
    else
        return
            Default::EMPTY;
}
int  __fastcall TForm3::getValueFromTargetPlan (const int index)
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        return
            this -> _targetPlan [index];
    else
        return
            Default::EMPTY;
}
int  __fastcall TForm3::getValueFromTotalPlan  (const int index)
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        return
            this -> _totalPlan [index];
    else
        return
            Default::EMPTY;
}
int  __fastcall TForm3::getValueFromTourism    (const int index)
{
    if (checkBounds (
            index,
            Default::ACCUM_ARRAY_LENGTH
        )
       )
        return
            this -> _tourism [index];
    else
        return
            Default::EMPTY;
}
int  __fastcall TForm3::getValueFromWithout    (const int index)
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        return
            this -> _without [index];
    else
        return
            Default::EMPTY;
}

void __fastcall TForm3::resetAccumulator       (
        int * arr,
        const int   length
    )
{
    for (int index = Default::START;
             index < length;
             ++index
        )
    {
        arr[index] = 0;
    }
}
void __fastcall TForm3::resetAllGainersAccum   ()
{
    for (int index = Default::START;
             index < Default::ACCUM_ARRAY_LENGTH;
             ++index
        )
    {
        setValueToCoaching   (index, Default::DISABLE);
        setValueToImproving  (index, Default::DISABLE);
        setValueToManagement (index, Default::DISABLE);
        setValueToPhysical   (index, Default::DISABLE);
        setValueToSpreader   (index, Default::DISABLE);
        setValueToTourism    (index, Default::DISABLE);
    }
}
void __fastcall TForm3::resetAllSectionsAccum  ()
{
    for (int index = Default::START;
             index < Default::SECTIONS_ARRAY_LENGTH;
             ++index
        )
    {
        setValueToGeneral    (index, Default::DISABLE);
        setValueToOutOf      (index, Default::DISABLE);
        setValueToSection    (index, Default::DISABLE);
        setValueToTarget     (index, Default::DISABLE);
        setValueToTargetPlan (index, Default::DISABLE);
        setValueToTotalPlan  (index, Default::DISABLE);
        setValueToWithout    (index, Default::DISABLE);
    }
}
void __fastcall TForm3::resetSectionAccum      (const int section2022Code)
{
    switch (static_cast <Section2022Code> (section2022Code))
    {
        case Section2022Code::PHYSICAL_CULTURE_2022:                            // 0 -> 6-05-1012-01
                setValueToSection (
                    Section2022Code::PHYSICAL_CULTURE_2022,                     // _sections[0]
                    Default::DISABLE
                );
            break;
        case Section2022Code::COACHING_2022:                                    // 1 -> 6-05-1012-02
                setValueToSection (
                    Section2022Code::COACHING_2022,                             // _sections[1]
                    Default::DISABLE
                );
            break;
        case Section2022Code::REHABILITATION_2022:                              // 2 -> 6-05-1012-03
                setValueToSection (
                    Section2022Code::REHABILITATION_2022,                       // _sections[2]
                    Default::DISABLE
                );
            break;
        case Section2022Code::MANAGEMENT_2022:                                  // 3 -> 6-05-1012-04
                setValueToSection (
                    Section2022Code::MANAGEMENT_2022,                           // _sections[3]
                    Default::DISABLE
                );
            break;
        case Section2022Code::TOURISM_2022:                                     // 4 -> 6-05-1013-01
                setValueToSection (
                    Section2022Code::TOURISM_2022,                              // _sections[4]
                    Default::DISABLE
                );
            break;
    }
}

void __fastcall TForm3::setValueToCoaching     (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::ACCUM_ARRAY_LENGTH
        )
       )
        this -> _coaching [index] = value;
    else
        this -> _coaching [index] = Default::EMPTY;
}
void __fastcall TForm3::setValueToGeneral      (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        this -> _general [index] = value;
    else
        this -> _general [index] = Default::EMPTY;
}
void __fastcall TForm3::setValueToImproving    (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::ACCUM_ARRAY_LENGTH
        )
       )
        this -> _improving [index] = value;
    else
        this -> _improving [index] = Default::EMPTY;
}
void __fastcall TForm3::setValueToManagement   (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::ACCUM_ARRAY_LENGTH
        )
       )
        this -> _management [index] = value;
    else
        this -> _management [index] = Default::EMPTY;
}
void __fastcall TForm3::setValueToOutOf        (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        this -> _outOf [index] = value;
    else
        this -> _outOf [index] = Default::EMPTY;
}
void __fastcall TForm3::setValueToPhysical     (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::ACCUM_ARRAY_LENGTH
        )
       )
        this -> _physical [index] = value;
    else
        this -> _physical [index] = Default::EMPTY;
}
void __fastcall TForm3::setValueToSection      (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        this -> _sections [index] = value;
    else
        this -> _sections [index] = Default::EMPTY;
}
void __fastcall TForm3::setValueToSpreader     (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::ACCUM_ARRAY_LENGTH
        )
       )
        this -> _spreader [index] = value;
    else
        this -> _spreader [index] = Default::EMPTY;
}
void __fastcall TForm3::setValueToTarget       (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        this -> _target [index] = value;
    else
        this -> _target [index] = Default::EMPTY;
}
void __fastcall TForm3::setValueToTargetPlan   (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        this -> _targetPlan [index] = value;
    else
        this -> _targetPlan [index] = Default::EMPTY;
}
void __fastcall TForm3::setValueToTotalPlan    (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        this -> _totalPlan [index] = value;
    else
        this -> _totalPlan [index] = Default::EMPTY;
}
void __fastcall TForm3::setValueToTourism      (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::ACCUM_ARRAY_LENGTH
        )
       )
        this -> _tourism [index] = value;
    else
        this -> _tourism [index] = Default::EMPTY;
}
void __fastcall TForm3::setValueToWithout      (
        const int index,
        const int value
    )
{
    if (checkBounds (
            index,
            Default::SECTIONS_ARRAY_LENGTH
        )
       )
        this -> _without [index] = value;
    else
        this -> _without [index] = Default::EMPTY;
}


// EXCEL
Variant __fastcall TForm3::createExcelApp ()
{
    return
        Variant::CreateObject (
            "Excel.Application"
        );
}
void    __fastcall TForm3::deleteExtraSheets ()
{
    if (getFacultyNumber () == FacultyCode::SMA)
    {
        // deleteSteet ("П.Д.Б.");
        // deleteSteet ("П.Д.О.");
        // deleteSteet ("П.З.Б.");
        // deleteSteet ("П.З.О.");
        // deleteSteet ("С.Д.Б.");
        deleteSteet ("С.Д.О.");
        deleteSteet ("С.З.Б.");
        deleteSteet ("С.З.О.");
    }

    if (getFacultyNumber () == FacultyCode::MS)
    {
        // deleteSteet ("П.Д.Б.");
        // deleteSteet ("П.Д.О.");
        // deleteSteet ("П.З.Б.");
        // deleteSteet ("П.З.О.");
        deleteSteet ("С.Д.Б.");
        deleteSteet ("С.Д.О.");
        deleteSteet ("С.З.Б.");
        deleteSteet ("С.З.О.");
    }

    if (getFacultyNumber () == FacultyCode::RPC)
    {
        // deleteSteet ("П.Д.Б.");
        // deleteSteet ("П.Д.О.");
        // deleteSteet ("П.З.Б.");
        // deleteSteet ("П.З.О.");
        // deleteSteet ("С.Д.Б.");
        deleteSteet ("С.Д.О.");
        deleteSteet ("С.З.Б.");
        deleteSteet ("С.З.О.");
    }

    if (getFacultyNumber () == FacultyCode::MSTH)
    {
        // deleteSteet ("П.Д.Б.");
        // deleteSteet ("П.Д.О.");
        deleteSteet ("П.З.Б.");
        // deleteSteet ("П.З.О.");
        deleteSteet ("С.Д.Б.");
        deleteSteet ("С.Д.О.");
        deleteSteet ("С.З.Б.");
        // deleteSteet ("С.З.О.");
    }
}
void    __fastcall TForm3::deleteSteet (const AnsiString & sheetName)
{
    DeleteSheet (
        SelectSheet (
            getWorkbook (),
            sheetName
        )
    );
}
void    __fastcall TForm3::finalClear ()
{
    deleteExtraSheets ();

    saveExcelApp ();

    #ifdef SHOW_EXCEL_APPLICATION
    OVisible (
        getExcelApp ()
    );
    #endif  // SHOW_EXCEL_APPLICATION

    quitExcelApp ();
}
void    __fastcall TForm3::initBook ()
{
    setFileName (
        getReportName ()
    );
    setExcelApp (
        createExcelApp ()
    );
    setWorkbook (
        openExcelBook ()
    );

    #ifdef DEBUG
    OVisible (getExcelApp ());                                                  // show excel document when populating table
    #endif // DEBUG

    DisplayAlert (getExcelApp ());                                              // delete excel prompts to confirm action

    saveWorkbookAs ();
}
void    __fastcall TForm3::initSheet ()
{
    setSheetName (
        getPartOfSheetNameForStudyPeriod   ()   +
        getPartOfSheetNameForEducationType ()   +
        getPartOfSheetNameForPayment       ()
    );
    setSelectedSheet (
        selectSheet ()
    );
}
Variant __fastcall TForm3::openExcelBook ()
{
    return
        OpenBook (
            getExcelApp (),
            PathTo::TEMPLATES                   +
            Document::STATISTIC::FILE::SCORES
        );
}
void    __fastcall TForm3::quitExcelApp ()
{
    Quit_ex (
        getExcelApp ()
    );

    getExcelApp ().Clear ();
}
Variant __fastcall TForm3::saveExcelApp ()                                      // I'm not sure I will use this
{
    return
        SaveBook (
            getWorkbook ()
        );
}
Variant __fastcall TForm3::saveWorkbookAs ()
{
    return
        SaveBookAs (
            getWorkbook (),
            PathTo::OUTPUT_DOCUMENTS    +
            getFileName ()
        );
}
Variant __fastcall TForm3::selectSheet ()
{
    return
        SelectSheet (
            getWorkbook (),
            getSheetName ()
        );
}

// OUTPUT
void TForm3::writeAmountByContest ()
{
    switch (getContestType ())
    {
        case ContestTypeCode::GENERAL:
                #ifndef BUFFER_OUTPUT
                CellValue (
                    getAmountByContest (),
                    ColumnFor::TOTAL_GENERAL_CONTEST,
                    getRowNumber ()
                );
                #else

                #endif  // ! BUFFER_OUTPUT
            break;
        case ContestTypeCode::WITHOUT_ENTRANCE_EXAMS:
                #ifndef BUFFER_OUTPUT
                CellValue (
                    getAmountByContest (),
                    ColumnFor::TOTAL_WITHOUT_EXAMS,
                    getRowNumber ()
                );
                #else

                #endif  // ! BUFFER_OUTPUT
            break;
        case ContestTypeCode::OUT_OF_COMPETITION:
                #ifndef BUFFER_OUTPUT
                CellValue (
                    getAmountByContest (),
                    ColumnFor::TOTAL_OUT_OF_COMPETITION,
                    getRowNumber ()
                );
                #else

                #endif  // ! BUFFER_OUTPUT
            break;
        case ContestTypeCode::TARGETED_TRAINING:
                #ifndef BUFFER_OUTPUT
                CellValue (
                    getAmountByContest (),
                    ColumnFor::TOTAL_TARGETED_TRAINING,
                    getRowNumber ()
                );
                #else

                #endif  // ! BUFFER_OUTPUT
            break;
    }
}
void TForm3::writeCalcForTotalApplicants ()
{
    #ifndef BUFFER_OUTPUT
    CellFormula (
        "=СУММ(E"               +
            AnsiString (
                getRowNumber ()
            )                   +
        ":H"                    +
            AnsiString (
                getRowNumber ()
            )                   +
        ")",
        ColumnFor::TOTAL_APPLICANTS,
        getRowNumber ()
    );
    #else

    #endif  // ! BUFFER_OUTPUT
}
void TForm3::writeDataBordering ()
{
    for (int i = ColumnFor::NAMES;
             i < ColumnFor::OUTER_BORDER;
             ++i
        )
        BorderCell (
            i,
            getRowNumber (),
            TypeLineCode::REGULAR_LINE,
            LineThicknessCode::MEDIUM
        );
}
void TForm3::writeDateAndHours ()
{
    CellValue (
        getCurrentDate (),
        ColumnFor::CURRENT_DATE,
        RowFor::DATE_AND_HOURS
    );
    CellValue (
        getCurrentHours (),
        ColumnFor::CURRENT_HOURS,
        RowFor::DATE_AND_HOURS
    );
}
void TForm3::writeFacultyName ()
{
    if (    getStudyPeriod ()   == StudyPeriodCode::SHORT_SECOND_COURSE
         && getFacultyNumber () == FacultyCode::SMA
       )
        CellValue (
                getFacultyName (getFacultyNumber ())    +
            ", "                                        +
                getFacultyName (FacultyCode::MS),
            ColumnFor::NAMES,
            RowFor::FACULTY_NAME
        );
    else
        CellValue (
            getFacultyName (getFacultyNumber ()),
            ColumnFor::NAMES,
            RowFor::FACULTY_NAME
        );
}
void TForm3::writeFacultyNameSMAWithMS ()
{
    CellValue (
            Faculty::NAME::SMA  +
        ",\n"                   +
            Faculty::NAME::MS,
        ColumnFor::NAMES,
        RowFor::FACULTY_NAME
    );
}
void TForm3::writeGatheredNumberOfGainers (const int * arr)
{
writeDataBordering ();
    for (int index = Default::START;
             index < Default::ACCUM_ARRAY_LENGTH;
             ++index
        )
    {
        #ifndef BUFFER_OUTPUT
        if(arr[index])
            CellValue (
                arr[index],
                ScoresRange::_31_35 - index,
                //getRowNumber ()
                RowFor::START_DATA
            );
        #else

        #endif  // ! BUFFER_OUTPUT
    }
}
void TForm3::writeGatheredSectionsName (const int * arr)
{
    setCounter (
        Default::START
    );

    for (int index = Default::START;
             index < Default::SECTIONS_ARRAY_LENGTH;
             ++index
        )
    {
        if (arr[index])
        {
            #ifndef BUFFER_OUTPUT
            CellValue (
                InsteadDb::getSection2022CodeNameById (
                    arr[index]
                ),
                ColumnFor::NAMES,
                RowFor::START_DATA + getCounter ()
            );
            #else

            #endif  // ! BUFFER_OUTPUT

            setCounter (
                getCounter () + Default::STEP
            );
        }
    }
}
void TForm3::writeNumberOfGainers ()
{
    #ifndef BUFFER_OUTPUT
    if (getGainersNumber ())
        CellValue (
            getGainersNumber (),
            getColumnNumber (),
            getRowNumber ()
        );
    #else

    #endif  // ! BUFFER_OUTPUT
}
void TForm3::writeSportNAmountByPlan ()
{

    if (QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value != 0)
    {
        setKindOfSportCode (
            QPlan_Priem_Konk_All_ParamN_SPECIALIZ -> Value
        );
        #ifndef BUFFER_OUTPUT
        CellValue (
            InsteadDb::getKindOfSportNameByNSpecializ (
                getKindOfSportCode ()
            ),
            //QPlan_Priem_Konk_All_ParamSPECIALIZ2 -> Value,
            ColumnFor::NAMES,
            getRowNumber ()
        );
        #else

        #endif  // ! BUFFER_OUTPUT

        setNumberOfSeats (
            QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value
        );

        #ifndef BUFFER_OUTPUT
        CellValue (
            getNumberOfSeats (),
            ColumnFor::NAMES + Default::STEP,
            getRowNumber ()
        );
        #else

        #endif  // ! BUFFER_OUTPUT
    }
}
void TForm3::writeTargetedByPlan ()
{
    QCK_Kol_Plan -> Close ();
    QCK_Kol_Plan -> ParamByName ("N_SPECIALIZ") ->
        AsInteger = getKindOfSportCode ();

    if (getStudyPeriod ())
        setStudyPeriod (
            getStudyPeriod () + Default::STEP
        );

    QCK_Kol_Plan -> ParamByName ("TERM_EDUC") ->
        AsInteger = getStudyPeriod ();
    QCK_Kol_Plan -> Open ();


    if (    getEducationType () == EducationTypeCode::INTRAMURAL
         && getStudyPeriod ()   == StudyPeriodCode::FULL
         && getPaymentType ()   == PaymentCode::BUDGET
       )
    {
        setTargetsByPlan (
            QCK_Kol_PlanKOL_PLACE -> Value
        );

        if (getTargetsByPlan ())
            #ifndef BUFFER_OUTPUT
            CellValue (
                getTargetsByPlan (),
                ColumnFor::TOTAL_TARGETED_TRAINING_BY_PLAN,
                getRowNumber ()
            );
            #else

            #endif  // ! BUFFER_OUTPUT
    }

    if (    getEducationType () == EducationTypeCode::INTRAMURAL
         && getStudyPeriod ()   == StudyPeriodCode::SHORT_SECOND_COURSE
         && getPaymentType ()   == PaymentCode::BUDGET
       )
    {
        setTargetsByPlan (
            QCK_Kol_PlanKOL_PLACE -> Value
        );

        if (getTargetsByPlan ())
            #ifndef BUFFER_OUTPUT
            CellValue (
                getTargetsByPlan (),
                ColumnFor::TOTAL_TARGETED_TRAINING_BY_PLAN,
                getRowNumber ()
            );
            #else

            #endif  // ! BUFFER_OUTPUT
    }
}
void TForm3::writeTotalsForFullCourse ()
{
    Stat3hAll1Qr -> Close ();
    Stat3hAll1Qr -> ParamByName ("n_fac")       ->
        AsSmallInt = getFacultyNumber ();
    Stat3hAll1Qr -> ParamByName ("vid_edu")     ->
        AsSmallInt = getEducationType ();
    Stat3hAll1Qr -> ParamByName ("price")       ->
        AsSmallInt = getPaymentType ();
    Stat3hAll1Qr -> ParamByName ("n_specializ") ->
        AsSmallInt = getKindOfSportCode ();
    Stat3hAll1Qr -> Open ();

    while (!Stat3hAll1Qr -> Eof)
    {
        if (Stat3hAll1QrCOUNT -> Value)
        {
            setAmountByContest (
                Stat3hAll1QrCOUNT -> Value
            );
            setContestType (
                Stat3hAll1QrKONKURS -> Value
            );

            writeAmountByContest ();
        }

        Stat3hAll1Qr -> Next ();
    }
    Stat3hAll1Qr -> Close ();
}
void TForm3::writeTotalsForShortExceptSMA ()
{
    Stat3hAll2Qr -> Close ();
    Stat3hAll2Qr -> ParamByName ("n_fac")       ->
        AsSmallInt = getFacultyNumber ();
    Stat3hAll2Qr -> ParamByName ("vid_edu")     ->
        AsSmallInt = getEducationType ();
    Stat3hAll2Qr -> ParamByName ("price")       ->
        AsSmallInt = getPaymentType ();
    Stat3hAll2Qr -> ParamByName ("n_specializ") ->
        AsSmallInt = getKindOfSportCode ();
    Stat3hAll2Qr -> Open ();

    while (!Stat3hAll2Qr -> Eof)
    {
        if (Stat3hAll1QrCOUNT -> Value)
        {
            setAmountByContest (
                Stat3hAll2QrCOUNT -> Value
            );

            setContestType (
                Stat3hAll2QrKONKURS -> Value
            );

            writeAmountByContest ();
        }

        Stat3hAll2Qr -> Next ();
    }
    Stat3hAll2Qr -> Close ();
}
void TForm3::writeTotalsForShortSMAWithSM ()
{
    Stat3hAll2Qr2 -> Close ();
    Stat3hAll2Qr2 -> ParamByName ("vid_edu") ->
        AsSmallInt = getEducationType ();
    Stat3hAll2Qr2 -> ParamByName ("price")   ->
        AsSmallInt = getPaymentType ();
    Stat3hAll2Qr2 -> Open ();

    while (!Stat3hAll2Qr2 -> Eof)
    {
        if (Stat3hAll2Qr2KONKURS -> Value)
        {
            setAmountByContest (
                Stat3hAll2Qr2COUNT -> Value
            );

            setContestType (
                Stat3hAll2Qr2KONKURS -> Value
            );

            writeAmountByContest ();
        }
        Stat3hAll2Qr2 -> Next ();
    }
    Stat3hAll2Qr2 -> Close ();
}
void TForm3::writeUniqueFacultyNameForShort ()                                  // StudyPeriodCode::SHORT
{
    if (    getFacultyNumber () == FacultyCode::SMA                             // NOTE: common name for SMA and MS
//         || getFacultyNumber () == FacultyCode::MS
       )
        CellValue (
            InsteadDb::getSection2009NameByNSpec (
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING
            )                                               +
            "\n(тренерская работа с указанием вида спорта)",
            ColumnFor::NAMES,
            getRowNumber ()
        );
    // if (getFacultyNumber () == FacultyCode::RPC)
    //     CellValue (
    //         InsteadDb::getNcrb2009FullNameByNSpecializ (
    //             KindOfSportCode::PRESCHOOLERS
    //         ),
    //         ColumnFor::NAMES,
    //         getRowNumber ()
    //     );

    if (getFacultyNumber () == FacultyCode::MSTH)
        CellValue (
            InsteadDb::getSection2009NameByNSpec (
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM
            ),
            ColumnFor::NAMES,
            getRowNumber ()
        );
}


#ifdef DEBUG_CHECK_VARIABLE_VALUES
showVariablesValue ();
#endif // DEBUG_CHECK_VARIABLE_VALUES


// LOGIC
__fastcall TForm3::TForm3 (TComponent * Owner)
    : TForm (Owner)
{
    #ifdef TEST_FEATURE
//        setValueToPhysical (
//            3,
//            20
//        );
//        setValueToPhysical (
//            5,
//            234
//        );

//        ShowMessage (
//            sizeof (getKOSAccum ()/soizeof (int *))
//                AnsiString (
//                    getValueFromPhysical (0)
//                )                               +
//            "\n"                                +
//                AnsiString (
//                    getValueFromPhysical (3)
//                )                               +
//            "\n"                                +
//                AnsiString (
//                    getValueFromPhysical (5)
//                )
//        );
    #else
    for (setFacultyNumber (FacultyCode::MSTH);                                  // (nFac) 4 - MSTH, 3 - RPC, 2 - MS, 1 - SMA
         getFacultyNumber () >= FacultyCode::SMA;
         setFacultyNumber (
            getFacultyNumber () - Default::STEP
         )
        )
    {
        initBook ();

        QSpecializ -> Active                         = false;
        QSpecializ -> ParamByName ("N_FAC") -> Value = getFacultyNumber ();
        QSpecializ -> Active                         = true;

        for (setStudyPeriod (StudyPeriodCode::FULL);                            // (text) 0- full / 1 - short
             getStudyPeriod () < Default::LOOPS_MAX_ITERATIONS;
             setStudyPeriod (
                getStudyPeriod () + Default::STEP
             )
            )
        {
            for (setEducationType (EducationTypeCode::INTRAMURAL);              // (vidEdu) 0 - intramural / 1 - extramural
                 getEducationType () < Default::LOOPS_MAX_ITERATIONS;
                 setEducationType (
                    getEducationType () + Default::STEP
                 )
                )
            {
                for (setPaymentType (PaymentCode::BUDGET);                      // (price) 0 - budget / 1 - buyer
                     getPaymentType () < Default::LOOPS_MAX_ITERATIONS;
                     setPaymentType (
                        getPaymentType () + Default::STEP
                     )
                    )
                {
                    initSheet ();

                    writeFacultyName ();
                    writeDateAndHours ();
                    #ifdef CHECK_ACCUMULATOR
                    setValueToPhysical (
                        3,
                        20
                    );
                    setValueToPhysical (
                        23,
                        34
                    );
                        writeGatheredNumberOfGainers (
                            getPhysicalAccum ()
                        );
                    #else
                    getNumberOfApplicants ();
                    #endif

                }
            }
        }
        finalClear ();

        QPlan_Priem_Konk_All_Param -> Close ();
    }
    #endif  // TEST_FEATURE

    ShowMessage (
        "Статистика создана и сохренена в папке:\n" +
        PathTo::OUTPUT_DOCUMENTS
    );

    exit (0);
}
void __fastcall TForm3::getNumberOfApplicants ()
{
    QPlan_Priem_Konk_All_Param -> Close ();
    QPlan_Priem_Konk_All_Param ->
        ParamByName ("N_FAC")   -> AsInteger =
            getFacultyNumber ();
    QPlan_Priem_Konk_All_Param ->
        ParamByName ("VID_EDU") -> AsInteger =
            getEducationType ();
    QPlan_Priem_Konk_All_Param ->
        ParamByName ("TEXT")    -> AsInteger =
            getStudyPeriod ();
    QPlan_Priem_Konk_All_Param ->
        ParamByName ("PRICE")   -> AsInteger =
            getPaymentType ();
    QPlan_Priem_Konk_All_Param -> Open ();

    setNumberOfRecords (
        QPlan_Priem_Konk_All_Param -> RecordCount
    );

    #ifdef CHECK_NUMBER_OF_RECORDS
    ShowMessage (
        getNumberOfRecords ()
    );
    #endif // CHECK_NUMBER_OF_RECORDS

    setRowNumber (
        RowFor::START_DATA
    );

    #ifndef OTHER_SHEET_GENERATOR_IMPLEMENTATION
    for (int i = Default::START;
             i < getNumberOfRecords ();
             ++i
        )
    {
        if (QPlan_Priem_Konk_All_ParamKOL_PLACE -> Value != 0)
        {
            if (   getStudyPeriod () == StudyPeriodCode::FULL
                || getStudyPeriod () == StudyPeriodCode::HIGH_FIRST_COURSE      // IMPORTANT!!! NEED CHECK
               )
            {
                #ifndef BUFFER_OUTPUT
                writeSportNAmountByPlan ();

                #ifdef TARGETED_TRAINING_ENROLLMENT
                writeTargetedByPlan ();
                #endif // TARGETED_TRAINING_ENROLLMENT

                writeTotalsForFullCourse ();
                #else
                #endif  // ! BUFFER_OUTPUT
            }
            else                                                                // StudyPeriodCode::SHORT
            {
                #ifdef BUFFER_OUTPUT_FOR_SHORT
                // NOTE: If necessary, do it here
                #else
                writeSportNAmountByPlan ();

                #ifdef TARGETED_TRAINING_ENROLLMENT
                writeTargetedByPlan ();
                #endif // TARGETED_TRAINING_ENROLLMENT

                writeUniqueFacultyNameForShort ();

                if (getFacultyNumber () != FacultyCode::SMA)
                    writeTotalsForShortExceptSMA ();
                else
                    writeTotalsForShortSMAWithSM ();
                #endif  // BUFFER_OUTPUT_FOR_SHORT
            }

            #ifndef BUFFER_OUTPUT_CALC_FOR_TOTAL_AND_BORDERING
            writeCalcForTotalApplicants ();
            writeDataBordering ();
            #else
            // NOTE:
            // To output the buffer, it is necessary
            // to change the number of iterations
            #endif  // ! BUFFER_OUTPUT_CALC_FOR_TOTAL_AND_BORDERING

            distributingScores ();

            setRowNumber (
                getRowNumber () + Default::STEP
            );
        }
        QPlan_Priem_Konk_All_Param -> Next ();
    }
    #else

    // NOTE: Here you can test different logic

    #endif // ! OTHER_SHEET_GENERATOR_IMPLEMENTATION

    #ifdef BUFFER_OUTPUT
    #endif  // BUFFER_OUTPUT

    QStatistic_Every_Day_Ball_Price -> Close ();
    QCK_Kol_Plan                    -> Close ();
}


void __fastcall TForm3::distributingScores ()
{
    if (getStudyPeriod () == StudyPeriodCode::FULL)
    {
        RaspredBallStrdPrc -> ParamByName ("N_FAC")   ->
            AsSmallInt = getFacultyNumber ();
        RaspredBallStrdPrc -> ParamByName ("N_SP")    ->
            AsSmallInt = getKindOfSportCode ();
        RaspredBallStrdPrc -> ParamByName ("VID_EDU") ->
            AsSmallInt = getEducationType ();
        RaspredBallStrdPrc -> ParamByName ("PRICE")   ->
            AsSmallInt = getPaymentType ();

        RaspredBallStrdPrc -> Prepare ();
        RaspredBallStrdPrc -> ExecProc ();

        setRecordsAmount (
           RaspredBallStrdPrc -> ParamCount
        );
        setColumnNumber (
            ScoresRange::_LESS_31
        );

        for (int index = Default::SHIFT_FOR_SPREAD_FULL;                            // array index - Items[0] -> nFac, [1] -> nSp, [2] -> vidEdu, [3] -> price, [4...78] -> n2_3 ... n75_76
                 index < getRecordsAmount ();
                 ++index
            )
        {
            setGainersNumber (
                RaspredBallStrdPrc -> Params -> Items[index] -> AsInteger
            );

            #ifndef BUFFER_OUTPUT
            writeNumberOfGainers ();
            #else
            if (getGainersNumber)
                setValueToSpreader (
                        Default::ACCUM_ARRAY_LENGTH
                    -   Default::STEP
                    -   index
                    +   Default::SHIFT_FOR_SPREAD_FULL,
                    getGainersNumber ()
                );
            #endif  // ! BUFFER_OUTPUT

            setColumnNumber (
                getColumnNumber () - Default::STEP
            );
        }

        RaspredBallStrdPrc -> Unprepare ();
        RaspredBallStrdPrc -> Close ();
    }
    else                                                                        // StudyPeriodCode::SHORT
    {
        if (getFacultyNumber () == FacultyCode::SMA)                            // SMA + MS
        {
            RaspredBall12StrdPrc -> Close ();
            RaspredBall12StrdPrc -> ParamByName ("VID_EDU") ->
                AsSmallInt = getEducationType ();
            RaspredBall12StrdPrc -> ParamByName ("PRICE")   ->
                AsSmallInt = getPaymentType ();

            RaspredBall12StrdPrc -> Prepare ();
            RaspredBall12StrdPrc -> ExecProc ();

            setRecordsAmount (
                RaspredBall12StrdPrc -> ParamCount
            );
            setColumnNumber (
                ScoresRange::_LESS_31
            );

            for (int i = Default::SHIFT_FOR_SPREAD_SHORT_SMA_SM;                // array index - Items[0] -> vidEdu, [1] -> price, [2...76] -> n2_3 ... n75_76
                     i < getRecordsAmount ();
                     ++i
                )
            {
                setGainersNumber (
                    RaspredBall12StrdPrc -> Params -> Items[i] -> AsInteger
                );

                #ifdef BUFFER_OUTPUT_FOR_SHORT
                // NOTE: If necessary, do it here
                #else
                writeNumberOfGainers ();
                #endif  // BUFFER_OUTPUT_FOR_SHORT

                setColumnNumber (
                    getColumnNumber () - Default::STEP
                );
            }

            RaspredBall12StrdPrc -> Unprepare ();
            RaspredBall12StrdPrc -> Close ();

            #ifdef BUFFER_OUTPUT_FOR_SHORT
            // NOTE: If necessary, do it here
            #else
            writeFacultyNameSMAWithMS ();
            #endif  // BUFFER_OUTPUT_FOR_SHORT
        }

        if (    getFacultyNumber () == FacultyCode::RPC
             || getFacultyNumber () == FacultyCode::MSTH
           )
        {
            RaspredBall34StrdPrc -> Close ();
            RaspredBall34StrdPrc -> ParamByName ("VID_EDU") ->
                AsSmallInt = getEducationType ();
            RaspredBall34StrdPrc -> ParamByName ("N_FAC")   ->
                AsSmallInt = getFacultyNumber ();
            RaspredBall34StrdPrc -> ParamByName ("PRICE")   ->
                AsSmallInt = getPaymentType ();
            RaspredBall34StrdPrc -> ParamByName ("N_SP")    ->
                AsSmallInt = getKindOfSportCode ();

            RaspredBall34StrdPrc -> Prepare ();
            RaspredBall34StrdPrc -> ExecProc ();

            setRecordsAmount (
                RaspredBall34StrdPrc -> ParamCount
            );
            setColumnNumber (
                ScoresRange::_LESS_31
            );

            for (int i = Default::SHIFT_FOR_SPREAD_SHORT_OTHER;                 // array index - Items[0] -> nFac, [1] -> vidEdu, [2] -> price, [3] -> nSp, [4...78] -> n2_3 ... n75_76
                     i < getRecordsAmount ();
                     ++i
                )
            {
                setGainersNumber (
                    RaspredBall34StrdPrc -> Params -> Items[i] -> AsInteger
                );

                #ifdef BUFFER_OUTPUT_FOR_SHORT
                // NOTE: If necessary, do it here
                #else
                writeNumberOfGainers ();
                #endif  // BUFFER_OUTPUT_FOR_SHORT

                setColumnNumber (
                    getColumnNumber () - Default::STEP
                );
            }

            RaspredBall34StrdPrc -> Unprepare ();
            RaspredBall34StrdPrc -> Close ();
        }
    }
}

#ifdef DEBUG_CHECK_VARIABLE_VALUES
void TForm3::showVariablesValue ()
{
    ShowMessage (
        "\nTotal amount by contest is:  "       +
            AnsiString (getAmountByContest ())  +
        "\nCurrent coulumn number is:   "       +
            AnsiString (getColumnNumber    ())  +
        "\nContest is:                  "       +
            AnsiString (getContestType     ())  +
        "\nEducation type is:           "       +
            AnsiString (getEducationType   ())  +
        "\nFaculty is:                  "       +
            AnsiString (getFacultyNumber   ())  +
        "\nKind of sport is:            "       +
            AnsiString (getKindOfSportCode ())  +
        "\nNumber of records is:        "       +
            AnsiString (getNumberOfRecords ())  +
        "\nNumber of seats is:          "       +
            AnsiString (getNumberOfSeats   ())  +
        "\nPayment type is:             "       +
            AnsiString (getPaymentType     ())  +
        "\nCurrent row number is:       "       +
            AnsiString (getRowNumber       ())  +
        "\nStudy course is:             "       +
            AnsiString (getStudyCourse     ())  +
        "\nAmount of targeted is:       "       +
            AnsiString (getTargetsByPlan   ())
    );
}
#endif // DEBUG_CHECK_VARIABLE_VALUES
