#include <vcl.h>
#pragma hdrstop

#include "Stat_Result_examUnit.h"

#include "Func.h"
#include "DMUnit.h"
#include "DMStatUnit.h"

#pragma package (smart_init)
#pragma resource "*.dfm"


TStat_Result_examForm * Stat_Result_examForm;


int
    col_rec_ex,
    nom_r,                                                                      // счетчик строк                    // _rowCounter
    rec_stat,                                                                   // Количество записей               // _recordNumber
    spec_ex;                                                                    // определение номера специализации // _kindOfSportCode

TFDQuery *
    q;                                                                          // запрос с которым будем работать  // _query

Variant
    ExcelApp_ex;                                                                // _excelApp



__fastcall TStat_Result_examForm::TStat_Result_examForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TStat_Result_examForm::borderingCells (
        const int numberOfColums,
        const int numberOfRows
    )
{
    for (int i = 0;
             i < numberOfColums;
             ++i
        )
        for (int j =  RowFor::RESULTS_START_DATA;
                 j <= numberOfRows;
                 ++j
            )
            BorderCell (
                i + 1,
                j,
                1,
                2
            );
}
void __fastcall TStat_Result_examForm::checkRequiredParameters ()
{
    if (RadioGroup1 -> ItemIndex == -1)
        return
            ShowMessage (
                "Выберите Вид испытания!"
            );
    if (Vid_edu     -> ItemIndex == -1)
        return
            ShowMessage (
                "Выберите Вид обучения!"
            );
    if (LookPredm   -> KeyValue  == -1)
        return
            ShowMessage (
                "Выберите Предмет!"
            );
    if (    LookPredm -> KeyValue  == 4
         && ComboBox1 -> ItemIndex == -1
    )
        return
            ShowMessage (
                "Выберите Язык предмета (Русский или Белорусский)!"
            );
}
void __fastcall TStat_Result_examForm::distributeData ()
{
    for (int i = 0;                                                             // spreading
             i < q -> Fields -> Count;
             ++i
        )
    {
        int count =
            q -> Fields -> Fields[i] -> Value;

        if (count)
        {
            switch (i)
            {
                case 0:
                        writeParticipants (
                            count,
                            ColumnFor::RESULTS_10,
                            nom_r,
                            CharacterCode::RESULTS_CHAR_D,
                            ColumnFor::RESULTS_10_PERCENTAGES
                        );
                    break;
                case 1:
                        writeParticipants (
                            count,
                            ColumnFor::RESULTS_9,
                            nom_r,
                            CharacterCode::RESULTS_CHAR_F,
                            ColumnFor::RESULTS_9_PERCENTAGES
                        );
                    break;
                case 2:
                        writeParticipants (
                            count,
                             ColumnFor::RESULTS_8,
                            nom_r,
                            CharacterCode::RESULTS_CHAR_H,
                            ColumnFor::RESULTS_8_PERCENTAGES
                        );
                    break;
                case 3:
                        writeParticipants (
                            count,
                            ColumnFor::RESULTS_7,
                            nom_r,
                            CharacterCode::RESULTS_CHAR_J,
                            ColumnFor::RESULTS_7_PERCENTAGES
                        );
                    break;
                case 4:
                        writeParticipants (
                            count,
                            ColumnFor::RESULTS_6,
                            nom_r,
                            CharacterCode::RESULTS_CHAR_L,
                            ColumnFor::RESULTS_6_PERCENTAGES
                        );
                    break;
                case 5:
                        writeParticipants (
                            count,
                            ColumnFor::RESULTS_5,
                            nom_r,
                            CharacterCode::RESULTS_CHAR_N,
                            ColumnFor::RESULTS_5_PERCENTAGES
                        );
                    break;
                case 6:
                        writeParticipants (
                            count,
                            ColumnFor::RESULTS_4,
                            nom_r,
                            CharacterCode::RESULTS_CHAR_P,
                            ColumnFor::RESULTS_4_PERCENTAGES
                        );
                    break;
                case 7:
                        writeParticipants (
                            count,
                            ColumnFor::RESULTS_3,
                            nom_r,
                            CharacterCode::RESULTS_CHAR_R,
                            ColumnFor::RESULTS_3_PERCENTAGES
                        );
                    break;
                case 8:
                        if (    RadioGroup1 -> ItemIndex != TypeOfTestCode::RESULTS_EXAMS
                             && nom_fac                  != FacultyCode::MSTH
                           )
                            break;

                        writeParticipants (
                            count,
                            ColumnFor::RESULTS_2,
                            nom_r,
                            CharacterCode::RESULTS_CHAR_T,
                            ColumnFor::RESULTS_2_PERCENTAGES
                        );
                    break;
                case 9:
                        if (RadioGroup1 -> ItemIndex != TypeOfTestCode::RESULTS_EXAMS)
                            break;

                        writeParticipants (
                            count,
                            ColumnFor::RESULTS_1,
                            nom_r,
                            CharacterCode::RESULTS_CHAR_V,
                            ColumnFor::RESULTS_1_PERCENTAGES
                        );
                    break;
                case 10:
                        if (RadioGroup1 -> ItemIndex != TypeOfTestCode::RESULTS_EXAMS)
                            break;

                        writeParticipants (
                            count,
                            ColumnFor::RESULTS_0,
                            nom_r,
                            CharacterCode::RESULTS_CHAR_X,
                            ColumnFor::RESULTS_0_PERCENTAGES
                        );
                    break;

                case 11:
                        if (RadioGroup1 -> ItemIndex != TypeOfTestCode::RESULTS_EXAMS)
                            break;

                        CellValue (
                            count,
                            ColumnFor::RESULTS_DC,
                            nom_r
                        );
                    break;
            }
        }
    }


    if (!RadioGroup1 -> ItemIndex)                                              // output CALCS
    {
        writeCalcForTotalPassedExams (nom_r);
        writeCalcForPassedExams (nom_r);
    }
    else
        if (nom_fac != FacultyCode::MSTH)
            writeCalcForPassedCerts (nom_r);
        else
            if (    DM -> QAbituraKONKURS -> Value
                 == ContestTypeCode::TARGETED_TRAINING
               )
                writeCalcForPassedCertsMSTHTargeted (nom_r);
            else
                writeCalcForPassedCertsMSTH (nom_r);
}
AnsiString __fastcall TStat_Result_examForm::getFileName (
        const int educationTypeCode,
        const int typeOfTestCode,
        const int subjectCode
    )
{
    AnsiString
        n_file = fac1;

    if (educationTypeCode == EducationTypeCode::EXTRAMURAL)
        n_file += " з_о ";
    else
        n_file += " дн_о ";

    switch (typeOfTestCode)
    {
        case TypeOfTestCode::RESULTS_EXAMS:
                n_file   +=
                    ". СТАТИСТИКА - Результаты сдачи экзаменов ";
            break;
        case TypeOfTestCode::RESULTS_CERTS:
                n_file +=
                    ". СТАТИСТИКА - Результаты ЦТ ";
            break;
        case TypeOfTestCode::RESULTS_CONTESTS:
                n_file  +=
                    ". СТАТИСТИКА - Результаты Олимпиад ";
            break;
        case TypeOfTestCode::RESULTS_OTHER:
                n_file  +=
                    ". СТАТИСТИКА - Результаты из других ВУЗов ";
            break;
    }

    return
        n_file +=
                getSubjectName (
                    subjectCode
                )                   +
            ".xls";
}
int __fastcall TStat_Result_examForm::getNumberOfLastColumn (const int typeOfTestCode)
{
    switch (typeOfTestCode)
    {
        case TypeOfTestCode::RESULTS_EXAMS:
            return
                ColumnFor::RESULTS_EXAMEN_END_DATA;
        case TypeOfTestCode::RESULTS_CERTS:
            if (nom_fac == FacultyCode::MSTH)
                return
                    ColumnFor::RESULTS_CERT_END_DATA_MSTH;
            else
                return
                    ColumnFor::RESULTS_CERT_END_DATA;
        case TypeOfTestCode::RESULTS_CONTESTS:
            return
                ColumnFor::RESULTS_EXAMEN_END_DATA;
        case TypeOfTestCode::RESULTS_OTHER:
            return
                ColumnFor::RESULTS_EXAMEN_END_DATA;
    }
}
AnsiString __fastcall TStat_Result_examForm::getSubjectName (const int subjectCode)
{
    if (subjectCode != 4)
        return
            DM -> TPredmet ->
                Lookup (
                    "N_PREDMET",
                    subjectCode,
                    "TEXT_PREDMET"
                );
    else
        return
                ComboBox1 -> Text   +
            " язык";
}
AnsiString __fastcall TStat_Result_examForm::getTitle (const int typeOfTestCode)
{
    switch (typeOfTestCode)
    {
        case TypeOfTestCode::RESULTS_EXAMS:
            return
                "вступительных экзаменов по предмету  ";
        case TypeOfTestCode::RESULTS_CERTS:
            return
                "поданных сертификатов централизованного "  \
                "тестирования по предмету  ";
        case TypeOfTestCode::RESULTS_CONTESTS:
            return
                "победителей республиканской олимпиады "    \
                "по предмету  ";
        case TypeOfTestCode::RESULTS_OTHER:
            return
                "вступительных экзаменов, проведенных в "   \
                "других ВУЗах по предмету  ";
    }
}
void __fastcall TStat_Result_examForm::writeCalcForPassedCerts (
        const int rowNumber
    )
{
    CellFormula (
        "="                                             +
            mas_column[CharacterCode::RESULTS_CHAR_D]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_F]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_H]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_J]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_L]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_N]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_P]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_R]   +
            AnsiString (rowNumber),
        ColumnFor::RESULTS_TOTAL,
        rowNumber
    );
}
void __fastcall TStat_Result_examForm::writeCalcForPassedCertsMSTH (
        const int rowNumber
    )
{
    CellFormula (
        "="                                             +
            mas_column[CharacterCode::RESULTS_CHAR_D]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_F]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_H]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_J]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_L]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_N]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_P]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_R]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_T]   +
            AnsiString (rowNumber),
        ColumnFor::RESULTS_TOTAL,
        rowNumber
    );
}
void __fastcall TStat_Result_examForm::writeCalcForPassedCertsMSTHTargeted (
        const int rowNumber
    )
{
    CellFormula (
        "="                                             +
            mas_column[CharacterCode::RESULTS_CHAR_D]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_F]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_H]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_J]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_L]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_N]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_P]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_R]   +
            AnsiString (rowNumber),
        ColumnFor::RESULTS_TOTAL,
        rowNumber
    );
}
void __fastcall TStat_Result_examForm::writeCalcForPassedExams (
        const int rowNumber
    )
{
    CellFormula (
        "="                                             +
            mas_column[CharacterCode::RESULTS_CHAR_D]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_F]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_H]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_J]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_L]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_N]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_P]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_R]   +
            AnsiString (rowNumber),
        ColumnFor::RESULTS_PASSED,
        rowNumber
    );
}
void __fastcall TStat_Result_examForm::writeCalcForTotalPassedExams (
        const int rowNumber
    )
{
    CellFormula (
        "="                                             +
            mas_column[CharacterCode::RESULTS_CHAR_C]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_T]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_V]   +
            AnsiString (rowNumber)                      +
        "+"                                             +
            mas_column[CharacterCode::RESULTS_CHAR_X]   +
            AnsiString (rowNumber),
        ColumnFor::RESULTS_TOTAL,
        rowNumber
    );
}
void __fastcall TStat_Result_examForm::writeFooter (const int rowNumber)
{
    CellValue (
        "ВСЕГО:",
        1,
        rowNumber
    );
    CellValue (
        "Ответственный секретарь приемной комиссии",
        1,
        rowNumber + 3
    );
    CellValue (
        LegallyAuthorizedPerson::SECRETARY,
        10,
        rowNumber + 3
    );
}
void __fastcall TStat_Result_examForm::writeParticipants (
        const int amountParticipants,
        const int amountColumn,
        const int rowNumber,
        const int characterCode,
        const int percentColumn
    )
{
    CellValue (
        amountParticipants,
        amountColumn,
        rowNumber
    );
    CellFormula (
        "="                             +
            mas_column[characterCode]   +
            AnsiString (rowNumber)      +
        "*100/B"                        +
            AnsiString (rowNumber),
        percentColumn,
        rowNumber
    );
}
void __fastcall TStat_Result_examForm::writeTotals (
        const int numberOfColums,
        const int rowNumber
    )
{
    for (int i =  numberOfColums;
             i >= ColumnFor::RESULTS_TOTAL;
             i -= Default::RESULTS_DATA_SHIFT
        )
    {
        CellFormula (                                                           // output TOTAL
            "=СУММ("                                                +
                mas_column[i - Default::RESULTS_STEP]               +
                RowFor::RESULTS_START_DATA                          +
            ":"                                                     +
                mas_column[i - Default::RESULTS_STEP]               +
                AnsiString (
                    rowNumber - Default::RESULTS_STEP
                )                                                   +
            ")",
            i,
            rowNumber
        );

        if (    i != ColumnFor::RESULTS_EXAMEN_END_DATA                         // output PERCENTAGES
             && i != ColumnFor::RESULTS_TOTAL
           )
            CellFormula (
                "="                                                 +
                    mas_column[i - Default::RESULTS_STEP]           +
                    AnsiString (
                        rowNumber
                    )                                               +
                "*100/B"                                            +
                    AnsiString (
                        rowNumber
                    ),
                i + Default::RESULTS_STEP,
                rowNumber
            );
        if (i == ColumnFor::RESULTS_TOTAL)
            CellFormula (
                "=СУММ("                                            +
                    mas_column[i]                                   +
                    RowFor::RESULTS_START_DATA                      +
                ":"                                                 +
                    mas_column[i]                                   +
                    AnsiString (
                        rowNumber - Default::RESULTS_STEP
                    )                                               +
                ")",
                i + Default::RESULTS_STEP,
                rowNumber
            );
    }
}


void __fastcall TStat_Result_examForm::BitBtn1Click (TObject * Sender)          //кнопка ПОКАЗАТЬ
{
    checkRequiredParameters ();

    AnsiString
        n_file   =
            getFileName (
                Vid_edu     -> ItemIndex,
                RadioGroup1 -> ItemIndex,
                LookPredm   -> KeyValue
            ),
        text_pr  =
            getTitle (
                RadioGroup1 -> ItemIndex
            )                               +
            getSubjectName (
                LookPredm   -> KeyValue
            );
    int
        col_bord =
            getNumberOfLastColumn (
                RadioGroup1 -> ItemIndex
            );
    Variant
        Sheet,
        Workbook,
        WorkSaveAs;


    ExcelApp_ex =
        Variant::CreateObject (
            "Excel.Application"
        );
    OVisible (
        ExcelApp_ex
    );

    if (RadioGroup1 -> ItemIndex == TypeOfTestCode::RESULTS_CERTS)
        if (nom_fac != FacultyCode::MSTH)
            Workbook =
                OpenBook (
                    ExcelApp_ex,
                    cur_dir                                         +
                    DocumentFile::STATISTIC::cert_result_ten
                );
        else
            Workbook =
                OpenBook (
                    ExcelApp_ex,
                    cur_dir                                         +
                    DocumentFile::STATISTIC::cert_result_hundred
                );
    else
        Workbook =
            OpenBook (
                ExcelApp_ex,
                cur_dir                                 +
                DocumentFile::STATISTIC::exam_result
            );

    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );
    DisplayAlert (
        ExcelApp_ex
    );
    WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );
    OVisible (
        ExcelApp_ex
    );


    CellValue (                                                                 // output TITLE
        text_pr,
        1,
        RowFor::RESULTS_TITLE
    );
    CellValue (                                                                 // output FACULTY NAME
        DM -> TFaculty ->
            Lookup (
                "N_FAC",
                nom_fac,
                "FAC"
            ),
        1,
        RowFor::RESULTS_FACULTY_NAME
    );

    if (Vid_edu -> ItemIndex)                                                   // output EDUCATION TYPE
        CellValue (
            "на заочной форме получения образования",
            1,
            RowFor::RESULTS_EDU_TYPE
        );
    else
        CellValue (
            "на дневной форме получения образования",
            1,
            RowFor::RESULTS_EDU_TYPE
        );


    DM -> QPlan_Priem_All -> Close ();
    DM -> QPlan_Priem_All ->
        ParamByName ("N_FAC")   -> AsInteger = nom_fac;
    DM -> QPlan_Priem_All ->
        ParamByName ("VID_EDU") -> AsInteger = Vid_edu -> ItemIndex;
    DM -> QPlan_Priem_All -> Open ();

    col_rec_ex =
        DM -> QPlan_Priem_All -> RecordCount;                                   // подсчитываем план приема по специализациям
    q          =
        DMStat -> QCount_Ball;
    nom_r      =
        RowFor::RESULTS_START_DATA;


    for (int i = 0;                                                             // output KIND OF SPORTS NAMES
             i < col_rec_ex;
             ++i
        )
    {
        spec_ex =
            DM -> QPlan_Priem_AllN_SPECIALIZ -> Value;

        CellValue (
            DM -> QPlan_Priem_AllSPECIALIZ2 -> Value,
            1,
            nom_r
        );

        q -> Close ();
        q -> ParamByName ("N_SP")      -> Value = spec_ex;                      // kind of sport
        q -> ParamByName ("N_VID_EDU") -> Value = Vid_edu     -> ItemIndex;     // education type
        q -> ParamByName ("N_FAC")     -> Value = nom_fac;                      // faculty code
        q -> ParamByName ("PREDM")     -> Value = LookPredm   -> KeyValue;      // subject
        q -> ParamByName ("ST_BALL")   -> Value = RadioGroup1 -> ItemIndex;     // type of test code

        switch (static_cast <int> (LookPredm -> KeyValue))                             // предмет
        {
            case 1:                                                             // биология
                    q -> ParamByName ("R_B") -> Value = 2;
                break;
            case 4:                                                             // язык 0 - русский, 1 - белорусский
                    q -> ParamByName ("R_B") -> Value =
                        ComboBox1 -> ItemIndex;
                break;
            case 9:                                                             // математика
                    q -> ParamByName ("R_B") -> Value = 3;
                break;
            case 10:                                                            // география
                    q -> ParamByName ("R_B") -> Value = 4;
                break;

            default:                                                            // любой другой
                    q -> ParamByName ("R_B") -> Value = 10;
                break;
        }

        q -> Open ();

        distributeData ();                                                      // spreading NUMBER OF PEOPLE

        DM -> QPlan_Priem_All -> Next ();

        ++nom_r;
    }

    borderingCells (                                                            // BORDERING
        col_bord,
        nom_r
    );

    int st_col;                                                                 // Подсчет значений всего по листу

    if (RadioGroup1 -> ItemIndex)
        st_col = col_bord - 1;                                                  // shift only for exams - the last column isn't for percentages it for 'didn't come' 19 or 26
    else
        st_col = col_bord;

    writeTotals (                                                               // output TOTAL and PERCENTAGES
        st_col,
        nom_r
    );
    writeFooter (                                                               // output FOOTER
        nom_r
    );

    WorkSaveAs =
        SaveBook (
            Workbook
        );
    ExcelApp_ex.Clear ();
}
void __fastcall TStat_Result_examForm::BitBtn2Click (TObject * Sender)          // создание результатов экзаменов в excel
{
    checkRequiredParameters ();

    AnsiString
        n_file   =
            getFileName (
                Vid_edu     -> ItemIndex,
                RadioGroup1 -> ItemIndex,
                LookPredm   -> KeyValue
            ),
        text_pr  =
            getTitle (
                RadioGroup1 -> ItemIndex
            );
    int
        col_bord =
            getNumberOfLastColumn (
                RadioGroup1 -> ItemIndex
            );
    Variant
        Sheet,
        Workbook,
        WorkSaveAs;


    ExcelApp_ex =
        Variant::CreateObject (
            "Excel.Application"
        );

    if (RadioGroup1 -> ItemIndex  == TypeOfTestCode::RESULTS_CERTS)
        if (nom_fac != FacultyCode::MSTH)
            Workbook =
                OpenBook (
                    ExcelApp_ex,
                    cur_dir                                         +
                    DocumentFile::STATISTIC::cert_result_ten
                );
        else
            Workbook =
                OpenBook (
                    ExcelApp_ex,
                    cur_dir                                         +
                    DocumentFile::STATISTIC::cert_result_hundred
                );
    else
        Workbook =
            OpenBook (
                ExcelApp_ex,
                cur_dir                                 +
                DocumentFile::STATISTIC::exam_result
            );

    Sheet =
        SelectSheet (
            Workbook,
            "Лист1"
        );
    DisplayAlert (
        ExcelApp_ex
    );
    WorkSaveAs =
        SaveBookAs (
            Workbook,
            PathTo::OUTPUT_DOCUMENTS_SLASH  +
            n_file
        );
    OVisible (
        ExcelApp_ex
    );


    CellValue (                                                                 // output TITLE
        text_pr,
        1,
        RowFor::RESULTS_TITLE
    );
    CellValue (                                                                 // output FACULTY NAME
        DM -> TFaculty ->
            Lookup (
                "N_FAC",
                nom_fac,
                "FAC"
            ),
        1,
        RowFor::RESULTS_FACULTY_NAME
    );

    if (Vid_edu -> ItemIndex)                                                   // output EDUCATION TYPE
        CellValue (
            "на заочной форме обучения",
            1,
            RowFor::RESULTS_EDU_TYPE
        );
    else
        CellValue (
            "на дневной форме обучения",
            1,
            RowFor::RESULTS_EDU_TYPE
        );



    DM -> QPlan_Priem_All -> Close ();
    DM -> QPlan_Priem_All ->
        ParamByName ("N_FAC")   -> AsInteger = nom_fac;
    DM -> QPlan_Priem_All ->
        ParamByName ("VID_EDU") -> AsInteger = Vid_edu -> ItemIndex;
    DM -> QPlan_Priem_All -> Open ();

    col_rec_ex =
        DM -> QPlan_Priem_All -> RecordCount;                                   // подсчитываем план приема по специализациям
    q          =
        DMStat -> QCount_Ball;
    nom_r      =
        RowFor::RESULTS_START_DATA;


    for (int i = 0;                                                             // output KIND OF SPORTS NAMES
             i < col_rec_ex;
             ++i
        )
    {
        spec_ex =
            DM -> QPlan_Priem_AllN_SPECIALIZ -> Value;

        CellValue (
            DM -> QPlan_Priem_AllSPECIALIZ2 -> Value,
            1,
            nom_r
        );

        q -> First ();

        for (int j = 0;                                                         // WHAT THIS ???????????????????????????????????????
                 j < rec_stat;
                 ++j
            )
        {
            if (spec_ex == q -> FieldByName ("N_SPECIALIZ") -> Value)           // если строка специализации совпала с выбранной специализацией
            {
                // int bal   =
                //     DM -> TBall ->
                //         Lookup (
                //             "BALL",
                //             q -> FieldByName ("BALL") -> Value,
                //             "NOM_BALL"
                //         );
                // int count =
                //     q -> FieldByName ("COUNT") -> Value;

                q -> Next ();
            }
            else
                q -> Next ();
        }

        DM -> QPlan_Priem_All -> Next ();
        ++nom_r;
    }


    borderingCells (                                                            // BORDERING
        col_bord,
        nom_r
    );

    int st_col;                                                                 // Подсчет значений всего по листу

    if (RadioGroup1 -> ItemIndex)
        st_col = col_bord - 1;                                                  // shift only for exams - the last column isn't for percentages it for 'didn't come' 19 or 26
    else
        st_col = col_bord;

    writeTotals (                                                               // output TOTAL and PERCENTAGES
        st_col,
        nom_r
    );
    writeFooter (                                                               // output FOOTER
        nom_r
    );

    WorkSaveAs =
        SaveBook (
            Workbook
        );
    ExcelApp_ex.Clear ();
}
void __fastcall TStat_Result_examForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    DMStat -> QCount_Ball_Examen -> Close ();

    this -> Close ();
}
void __fastcall TStat_Result_examForm::LookPredmCloseUp (TObject * Sender)
{
    if (LookPredm -> KeyValue == 4)                                             // Белорусский / Русский язык
    {
        Label3    -> Visible = true;
        ComboBox1 -> Visible = true;

        ComboBox1 -> SetFocus ();
    }
    else                                                                        // Биология, Математика, География
    {
        Label3    -> Visible = false;
        ComboBox1 -> Visible = false;
    }
}
void __fastcall TStat_Result_examForm::Vid_eduChange (TObject * Sender)
{
    // DMStat -> QCount_Ball_Examen -> Close ();

    // BitBtn2 -> Visible = false;
    // DBGrid1 -> Visible = false;

    // Stat_Result_examForm -> Height = 132;

    // if (Stat_Result_examForm -> Position != poScreenCenter)
    //     Stat_Result_examForm -> Position = poScreenCenter;
}
