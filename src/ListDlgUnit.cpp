#include <vcl.h>
#pragma hdrstop


#include <comobj.hpp>
#include "DMStatUnit.h"
#include "DMUnit.h"
#include "Exam_List_2Unit.h"
#include "Exam_List_AllUnit.h"
#include "Exam_List_obUnit.h"
#include "Exam_ListUnit.h"
#include "Func.h"
#include <graphics.hpp>
#include <jpeg.hpp>
#include "ListDlgUnit.h"
#include "ListDocIndexUnit.h"
#include "Print_GroupUnit.h"
#include "Print_OpisUnit.h"
#include "Print_RaspiskaUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TListDlgForm * ListDlgForm;


bool               opform;

Jpeg::TJPEGImage * jp_print;

String             index_doc,
                   name_doc;

TfrxMemoView     * Memo_number,
                 * Memo_text_ball,
                 * Memo_text_predm,
                 * MemoBALL,
                 * MemoDATE_PRIEM,
                 * MemoFIO;

TfrxPictureView  * PictureOb;

TMemoryStream    * pms_print;

Variant            Cell_d1,
                   Cell_d2,
                   ExApp_d1,
                   ExcelApplication_d,
                   RangeCell_d,
                   Sheet_d;


const AnsiString TListDlgForm::DIGIT_NAMES_FRACTIONAL_PART [11] =
{
    "ноль",   "одна",   "две",
    "три",    "четыре", "пять",
    "шесть",  "семь",   "восемь",
    "девять", "десять"
};
const AnsiString TListDlgForm::DIGIT_NAMES_INTEGER_PART [29] =
{
    "ноль",        "один",        "два",          "три",
    "четыре",      "пять",        "шесть",        "семь",
    "восемь",      "девять",      "десять",       "одиннадцать",
    "двенадцать",  "тринадцать",  "четырнадцать", "пятнадцать",
    "шестнадцать", "семнадцать",  "восемнадцать", "девятнадцать",
    "двадцать",    "тридцать",    "сорок",        "пятьдесят",
    "шестьдесят",  "семьдесят",   "восемьдесят",  "девяносто",
    "сто"
};

#define OLD



__fastcall TListDlgForm::TListDlgForm (TComponent * Owner)
    : TForm (Owner)
{
    #ifdef TESTING_LIST_DLG_UNIT
    int subject = 1;

    AnsiString err_access_denied;// =
        Specialization::FIELD_HOCKEY
        //"Неверное имя пользователя или пароль"          //\
        //" "                                             +
        //scoresToWords (50.4584)                         +
        //doubleToStringWithFractionalPart (34.3553)      +                     // In this case an example: 34.3553 -> 34,4
        //" "                                             +
        //doubleToStringWithoutFractionalPart (34.4553)                         // In this case an example: 34.4553 -> 34
        //getDigitNameOfIntegerPart (28)              +
        //" "                                         +
        //ROWING_AND_CANOEING
        ;

        //switch (static_cast <Subject> (subject))
        //{
        //    case Subject::RUS:
        //        //return
        //            err_access_denied = "Русский язык";
        //        break;
        //    case Subject::BEL:
        //        //return
        //            err_access_denied = "Белорусский язык";
        //        break;
        //    default:
        //        //return
        //            err_access_denied = DM -> QSertificat_ex_listTEXT_PREDMET -> Value;
        //}
    ShowMessage (
        //"Неверное имя пользователя " \
        //"или пароль "
        err_access_denied
    );
    #endif
}



// -- MY METHODS >> BEGIN >>> --------------------------------------------------
AnsiString TListDlgForm::decimalStrToWord (                                     // example: "54,8" -> "пятьдесят четыре целых восемь десятых"
        AnsiString decimalAsString
    )
{
    int integerPart =                                                           // example: "54,8" -> 54
        StrToFloat (
            decimalAsString
        );

    int fractionalPointPosition =                                               // example: "54,8" -> 3
        decimalAsString
            .Pos (
                ","
            );

    int fractionalPart =                                                        // example: "54,8" -> 8
        StrToInt (
            decimalAsString
                .SubString (
                    ++fractionalPointPosition,
                    decimalAsString.Length ()
                )
            );

    AnsiString outputString =                                                   // example: "54","8" -> "пятьдесят четыре целых восемь"
        numberToWords (
            integerPart,
            true
        )                       +
        " целых "               +
        numberToWords (
            fractionalPart,
            false
        );

    if (fractionalPart == 1)                                                    // example: 8 -> "пятьдесят четыре целых восемь десятых"
        return
             decimalAsString += " десятая";
    else
        return
             decimalAsString += " десятых";
}
AnsiString TListDlgForm::numberToWords (                                        // basic converter logic
        int  number,
        bool isIntegerPart
    )
{
    AnsiString numberInWords  = "";

    if (    ! number
         || number == NULL
       )
        return
            numberInWords;

    if (number > 100)
    {
        ShowMessage (
            "Количество баллов не " \
            "должно быть больше 100!"
        );

        return
            IntToStr (
                number
            );
    }

    if (number == 100)
    {
        return
            getDigitNameOfIntegerPart (
                INDEX_VALUE_ONE_HUNDRED
            );
    }

    if (number >= 20)
    {
        int leftmostDigit =
            static_cast <int> (
                number / 10
            );

        numberInWords =
            getDigitNameOfIntegerPart (
                  ELIMINATE_PRIMES
                + leftmostDigit
            );

        numberInWords += " ";

        number -= leftmostDigit * 10;                                           // remove leftmost digit from scores
    }

    if (! isIntegerPart)                                                        // for number less than 20
        numberInWords += getDigitNameOfFractionalPart (number);
    else
        if (number)
            numberInWords += getDigitNameOfIntegerPart (number);
        else
            numberInWords                                                       // example: "пятьдесят " -> "пятьдесят"
                .SetLength (
                    numberInWords.Length () - 1
                );

    return
        numberInWords;
}
AnsiString TListDlgForm::scoresToWords (                                        // main method for converting scores to words
        double scores,
        bool isIntegerPart
    )
{
    AnsiString decimalAsString =                                                // example: 54.7553 -> "54,8"
        doubleToStringWithFractionalPart (
            scores
        );

    int integerPart =                                                           // example: 54.7553 -> 55
        StrToFloat (
            doubleToStringWithoutFractionalPart (
                scores
            )
        );

    if (isIntegerPart)                                                          // difference for Institute of Tourism and Hospitality (ITaH)
    {
        return
            numberToWords (                                                     // example: 55" -> "пятьдесят пять"
                integerPart,
                true
            );
    }
    else
    {
        return
            decimalStrToWord (                                                  // example: "54,8" -> "пятьдесят четыре целых восемь десятых"
                decimalAsString
            );
    }
}
AnsiString TListDlgForm::doubleToStringWithFractionalPart (double scores)       // example: 54.7553 -> "54,8"
{
    return
        FloatToStrF (
            scores,                                                             // value to convert
            ffFixed,                                                            // Format (Embarcadero System.SysUtils.TFloatFormat enum)
            5,                                                                  // the total number of digits (both fractional parts)
            1                                                                   // number of digits after the decimal point
        );
}
AnsiString TListDlgForm::doubleToStringWithoutFractionalPart (double scores)    // example: 54.7553 -> "55"
{
    return
        FloatToStrF (
            scores,
            ffFixed,
            5,
            0
        );
}
AnsiString TListDlgForm::getDigitNameOfFractionalPart (int digit)               // example: 21 -> "тридцать" (see: convertNumberToWords ())
{
    return
        DIGIT_NAMES_FRACTIONAL_PART [digit];
}
AnsiString TListDlgForm::getDigitNameOfIntegerPart (int digit)                  // example: 1 -> "одна" (see: convertNumberToWords ())
{
    return
        DIGIT_NAMES_INTEGER_PART [digit];
}
AnsiString TListDlgForm::getInfoAboutDocumentOnEducation (
        const AnsiString & documentNumber,
        const AnsiString & organization,
        const AnsiString & location,
        const AnsiString & issueYear
    )
{
    return
            documentNumber  +
        " выданный "        +
            organization    +
        " "                 +
            location        +
        " "                 +
            issueYear       +
        " г.";
}
AnsiString TListDlgForm::getSubjectNameFromCode (int subjectCode)               // convert the subject code to subject name as string
{
    switch (static_cast <SubjectCode> (subjectCode))
    {
        case SubjectCode::RUS:
            return
                "Русский язык";
        case SubjectCode::BEL:
            return
                "Белорусский язык";
        default:
            return
                DM -> QSertificat_ex_listTEXT_PREDMET -> Value;
    }
}
// -- MY METHODS << END <<< ----------------------------------------------------




void __fastcall TListDlgForm::BitBtn2Click (TObject * Sender)                   // pass = "dbudfv"
{
    AnsiString
        InputString = "";

    UnicodeString
        Str1 = "Предупреждение",
        Str2 = "Введите пароль на добавление в список:",
        Str3 = InputString;

    if ( InputQuery (                                                           // InputQuery 1
            Str1,
            Str2,
            Str3
         )
       )
    {
        if (InputString == "dbudfv")                                            // InputString 1
        {
            InputString = "";

            Str1 = "";
            Str2 = "Введите название документа:";
            Str3 = InputString;

            if ( InputQuery (                                                   // InputQuery 2
                    Str1,
                    Str2,
                    Str3
                 )
               )
            {
                if (InputString != "")                                          // InputString 2
                {
                    DM -> TDocum         -> Insert ();

                    DM -> TDocumTEXT_DOC -> Value = InputString;

                    DM -> TDocum         -> ApplyUpdates ();
                    DM -> TDocum         -> CommitUpdates ();
                }
            }
        }
        else
            ShowMessage (
                "Неверный пароль!"
            );
    }
}
void __fastcall TListDlgForm::BitBtn3Click (TObject * Sender)
{
    this -> Close ();
}
void __fastcall TListDlgForm::BitBtn5Click (TObject * Sender)                   // pass = "dbudfv"
{
    AnsiString    InputString = "";

    UnicodeString Str1        = "Предупреждение",
                  Str2        = "Введите пароль на изменения в списке:",
                  Str3        = InputString;

    if (    InputQuery (                                                        // InputQuery 1
                Str1,
                Str2,
                Str3
            )
       )
    {
        if (InputString == "dbudfv")                                            // InputString 1
        {
            InputString = DM -> TDocumTEXT_DOC -> Value;

            UnicodeString Str1 = "",
                          Str2 = "Введите название документа:",
                          Str3 = InputString;

            if (    InputQuery (                                                // InputQuery 2
                        Str1,
                        Str2,
                        Str3
                    )
               )
            {
                if (InputString != "")                                          // InputString 2
                {
                    DM -> TDocum -> Edit ();

                    DM -> TDocumTEXT_DOC -> Value = InputString;

                    DM -> TDocum -> ApplyUpdates ();
                    DM -> TDocum -> CommitUpdates ();
                }
            }
        }
        else
            ShowMessage (
                "Неверный пароль!"
            );
    }
}
void __fastcall TListDlgForm::ContractBtBtnClick (TObject * Sender)             // Договор
{
    DMStat -> QSpecializ_for_Spec -> Close ();
    DMStat -> QSpecializ_for_Spec ->
        ParamByName ("N_SPEC") -> AsInteger =
            DM -> QAbituraN_SPEC -> Value;
    DMStat -> QSpecializ_for_Spec -> Open ();

    AnsiString
        cod_specializ1 = "1-88 02 01-01 ",
        excel_name,
        interactive    = "",
        qualific1      = "",
        sp_full        = "",
        spec_str       = "",
        vid_sport      = "";

    int
        n_sp = DM -> QAbituraN_SPECIALIZ -> Value;

	if (
         DM -> QAbituraTERM_EDU -> Value != StudyPeriodCode::HIGH_THIRD_COURSE
         //   DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::FULL
         //|| DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::HIGH_FIRST_COURSE
       )
    {
        cod_specializ1 =
            DeleteAfterDatabaseChange::getNcrb2022CodeByNSpecializ (
                n_sp
                //DM -> QAbituraN_SPECIALIZ -> AsInteger
            )                                                                   +
            " ";
        sp_full        =
            DeleteAfterDatabaseChange::getNcrb2022NameSportStrByNSpecializ (
                n_sp
            );
        qualific1      =
            "«"                                                                 +
            DeleteAfterDatabaseChange::getNcrb2022QualificationNameByNSpecializ (
                n_sp
            )                                                                   +
            "»";
        vid_sport      =
            DeleteAfterDatabaseChange::getKindOfSportNameDativeCaseByNSpecializ (
                n_sp
            );
        spec_str       = "(профилизации)";                                      // Вывод квалификации и названия факультета
    }
    else
    {
        vid_sport =
            DMStat -> QSpecializ_for_Spec ->
                Lookup (
                    "N_SPECIALIZ",
                    n_sp,
                    "SPECIAL_SKLON"
                );
        spec_str  =                                                             // Вывод квалификации и названия факультета
            "(направлению специальности, специализации)";

        if (DM -> QAbituraN_SPEC -> Value == 6)                                 // Спортивно-педагогическая деятельность (по направлениям) 1-88 02 01-01
        {
            switch (n_sp)
            {
                case 48:
                        cod_specializ1 =
                            "1-88 02 01-02 ";
                        qualific1 =
                            "«Менеджер в спорте. Преподаватель физической "     \
                            "культуры»";
                    break;
                case 52:
                        cod_specializ1 =
                            "1-88 02 01-03 ";
                        qualific1 =
                            "«Психолог. Преподаватель физической культуры»";
                    break;
                case 56:
                        cod_specializ1 =
                            "1-88 02 01-04 ";
                        qualific1 =
                            "«Менеджер-режиссер спортивно-массовых "            \
                            "меропрятий. Преподаватель физической культуры»";
                    break;
                default:
                        qualific1 =
                            "«Тренер по "                                       +
                                vid_sport                                       +
                            ". Преподаватель физической культуры»";
            }
        }
        else
        {
            switch (DM -> QAbituraN_SPECIALIZ -> Value)                             // специализация
            {
                case 3:
                        cod_specializ1 =
                            "1-88 01 03-01 ";
                        qualific1 =
                            "«Инструктор-методист по физической реабилитации. " \
                            "Преподаватель физической культуры»";
                    break;
                case 4:
                        cod_specializ1 =
                            "1-88 01 01-01 ";
                        qualific1 =
                            "«Инструктор-методист по лечебной физической "      \
                            "культуре. Преподаватель физической культуры»";
                    break;
                case 38:
                        cod_specializ1 =
                            "1-88 01 02-01 ";
                        qualific1 =
                            "«Инструктор-методист по оздоровительной "          \
                            "физической культуре. Преподаватель физической "    \
                            "культуры»";
                    break;
                case 39:
                        cod_specializ1 =
                            "1-88 01 02-02 ";
                        qualific1 =
                            "«Инструктор-методист по адаптивной физической "    \
                            "культуре. Преподаватель физической культуры»";
                    break;
                case 47:
                        cod_specializ1 =
                            "1-88 01 03-02 ";
                        qualific1 =
                            "«Инструктор-методист по эрготерапии. "             \
                            "Преподаватель физической культуры»";
                    break;
                case 50:
                        cod_specializ1 =
                            "1-89 02 01-01 ";
                        qualific1 =
                            "«Инструктор-методист по туризму. Преподаватель "   \
                            "физической культуры»";
                    break;
                case 51:
                        cod_specializ1 =
                            "1-89 02 01-02 ";
                        qualific1 =
                            "«Менеджер по туризму. Преподаватель физической "   \
                            "культуры»";
                    break;
                case 52:
                        cod_specializ1 =
                            "1-88 02 01-03 ";
                        qualific1 =
                            "«Психолог. Преподаватель физической культуры»";
                    break;
                case 57:
                        cod_specializ1 =
                            "1-88 01 01-02 ";
                        qualific1 =
                            "«Инструктор-методист физического воспитания в "    \
                            "дошкольных учреждениях. Преподаватель физической " \
                            "культуры»";
                    break;
                case 61:
                        cod_specializ1 =
                            "1-89 01 01 ";
                        qualific1 =
                            "«Специалист в сфере туризма и гостеприимства»";
                    break;
            }
        }

        sp_full =                                                               // Направления специальности
            DM -> vozvrat_spec (
                DM -> QAbituraN_SPECIALIZ -> Value
            );
    }

    interactive = spec_str;

    if (    DM -> QAbituraKONKURS     -> Value != 3                             // НЕ ЦЕЛЕВИК
         && DM -> QAbituraCATEGORY_IF -> Value != 1                             // НЕ ИНОСТРАНЕЦ
       )
    {
		if (DM -> QAbituraPRICE -> Value == 0)                                  // БЮДЖЕТ
        {
            ExcelApplication_d = Variant::CreateObject ("Excel.Application");

            Variant Workbook =
                OpenBook (
                    ExcelApplication_d,
                    cur_dir                         +
                    Contract::DOCUMENT_FILE::BUDGET
                );

            Sheet_d =
                SelectSheet (
                    Workbook,
                    "Лист1"
                );

           AnsiString n_file =
                    Contract::DOCUMENT_NAME::BUDGET +
                " "                                 +
                    DM -> QAbituraFAM  -> Value     +
                " "                                 +
                    DM -> QAbituraNAME -> Value     +
                " "                                 +
                    DM -> QAbituraOTCH -> Value     +
                ".xls";

            DisplayAlert (ExcelApplication_d);

            Variant WorkSaveAs =
                SaveBookAs (
                    Workbook,
                    out_dir     +
                    n_file
                );

            CellValue (
                "«____» __________ "        +
                    Admissions::TIME::YEAR  +
                " г.",
                1,
                5
            );
            CellValue (
                "г. Минск",
                12,
                5
            );

            String s_tmp;


            if (nom_fac != 4)
                s_tmp =
                    "лице проректора по учебной работе "                    +
                        Contract::BSUPC::PERSON                             +
                    ", действующего на основании "                          +
                        Contract::BSUPC::BASE_DOCUMENT::NAME                +
                    " от "                                                  +
                        Contract::BSUPC::BASE_DOCUMENT::DATE                +
                    " № "                                                   +
                        Contract::BSUPC::BASE_DOCUMENT::NUMBER;
            else
                s_tmp =
                    "лице декана факультета менеджмента спорта, туризма "   \
                    "и гостеприимства Института менеджмента спорта и "      \
                    "туризма "                                              +
                        Contract::IMS::PERSON                               +
                    ", действующего на основании "                          +
                        Contract::IMS::BASE_DOCUMENT::NAME                  +
                    " от "                                                  +
                        Contract::IMS::BASE_DOCUMENT::DATE                  +
                    " № "                                                   +
                        Contract::IMS::BASE_DOCUMENT::NUMBER;

            s_tmp +=
                ", именуемое в дальнейшем Учреждение образования, с одной " \
                "стороны, и гражданин "                                     +
                    DM -> QAbituraFAM  -> Value     +
                " "                                 +
                    DM -> QAbituraNAME -> Value     +
                " "                                 +
                    DM -> QAbituraOTCH -> Value     +
                ", именуемый в дальнейшем Обучающийся или Иностранный "     \
                "обучающийся (для иностранных граждан и лиц без "           \
                "гражданства, временно пребывающих или временно "           \
                "проживающих в Республике Беларусь) (далее, если не "       \
                "указано иное, – Обучающийся), с другой стороны, "          \
                "заключили настоящий договор о нижеследующем:";

            CellValue (
                s_tmp,
                1,
                8
            );

            spec_str +=                                                         // Вывод квалификации и названия факультета
                " "                                             +
                    cod_specializ1                              +
                " «"                                            +
                    sp_full                                     +
                "» с присвоением квалификации "                 +
                    qualific1;


            switch (nom_fac)                                                    // факультет
            {
                case 1:
                        spec_str +=
                            " на спортивно-педагогическом факультете "      \
                            "спортивных игр и единоборств в ";
                    break;
                case 2:
                        spec_str +=
                            " на спортивно-педагогическом факультете "      \
                            "массовых видов спорта в ";
                    break;
                case 3:
                        spec_str +=
                            " на факультете оздоровительной физической "    \
                            "культуры в ";
                    break;
                case 4:
                        spec_str +=
                            " на факультете менеджмента спорта, туризма и " \
                            "гостеприимства Института менеджмента спорта "  \
                            "и туризма в ";
                    break;
            }


			if (DM -> QAbituraVID_EDU -> Value)
                s_tmp = EducationType::EXTRA_FORM;
            else
                s_tmp = EducationType::INTRA_FORM;


            spec_str +=
                    s_tmp                                       +
                " форме получения образования за счет средств " \
                "республиканского бюджета.";

            CellValue (
                spec_str,
                1,
                10
            );

            Variant CC1 =                                                       // Курс зачисления
                SelectCell (
                    3,
                    24
                );
            Variant CC2 =                                                       // Вывод срока обучения
                SelectCell (
                    15,
                    24
                );
            Variant RCC;


            if ( //   DM -> QAbituraTERM_EDU -> Value == 0                        // Полный срок QAbituraTERM_EDU = 0 или 3
                 //|| DM -> QAbituraTERM_EDU -> Value == 3
                    DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::FULL
                 || DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::HIGH_FIRST_COURSE
               )
            {
                RCC =
                    Range (
                        Sheet_d,
                        CC1,
                        CC2
                    );

                mergeCell (RCC);

                HorizontalAlign (
                    RCC,
                    2
                );
                VerticalAlign (
                    RCC,
                    3
                );
                CellValue (
                    "При зачислении на 1 курс – протокол "  \
                    "приемной комиссии от",
                    3,
                    14
                );

                if (DM -> QAbituraVID_EDU -> Value == 0)                        // дневное - 4 года
                    CellValue (
                        "2. Срок получения образования "    \
                        "составляет четыре года.",
                        3,
                        18
                    );
                else
                    CellValue (                                                 // заочное - 5 лет
                        "2. Срок получения образования "    \
                        "составляет пять лет.",
                        3,
                        18
                    );


                if (DM -> QAbituraVID_EDU -> Value == 1)                        // Вывод стоимости обучения (БЮДЖЕТ, ЗАОЧНОЕ, ПОЛНЫЙ СРОК)
                    CellValue (
                        Contract::COST_FOR::BUDGET::EXTRAMURAL::FULL_COURSE,
                        1,
                        20
                    );

                if (DM -> QAbituraVID_EDU -> Value == 0)                        // Вывод стоимости обучения (БЮДЖЕТ, ДНЕВНОЕ, ПОЛНЫЙ СРОК)
                    CellValue (
                        Contract::COST_FOR::BUDGET::INTRAMURAL::FULL_COURSE,
                        1,
                        20
                    );
            }


            if ( //   DM -> QAbituraTERM_EDU -> Value == 1                        // сокращённый срок 2 курс
                 //|| DM -> QAbituraTERM_EDU -> Value == 4
                    DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::HIGH_SECOND_COURSE
                 || DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::SHORT_SECOND_COURSE
               )
            {
                CellValue (
                    "При зачислении на 2 курс – протокол "  \
                    "приемной комиссии от",
                    3,
                    14
                );
                RCC =
                    Range (
                        Sheet_d,
                        CC1,
                        CC2
                    );
                mergeCell (RCC);
                HorizontalAlign (
                    RCC,
                    2
                );
                VerticalAlign (
                    RCC,
                    3
                );


                if (DM -> QAbituraVID_EDU -> Value == 0)                        // дневное - 3 года
                    CellValue (
                        "2. Срок получения образования "    \
                        "составляет три года.",
                        3,
                        18
                    );
                else                                                            // заочное - 4 года
                    CellValue (
                        "2. Срок получения образования "    \
                        "составляет четыре года.",
                        3,
                        18
                    );


                if (DM -> QAbituraVID_EDU -> Value == 1)                        // БЮДЖЕТ, ЗАОЧНОЕ, СОКРАЩЁННЫЙ СРОК 2 курс
                    CellValue (
                        Contract::COST_FOR::BUDGET::EXTRAMURAL::SECOND_COURSE,
                        1,
                        20
                    );

                if (DM -> QAbituraVID_EDU -> Value == 0)                        // БЮДЖЕТ, ДНЕВНОЕ, СОКРАЩЁННЫЙ СРОК 2 курс
                    CellValue (
                        Contract::COST_FOR::BUDGET::INTRAMURAL::SECOND_COURSE,
                        1,
                        20
                    );
            }


            if ( //   DM -> QAbituraTERM_EDU -> Value == 2                        // сокращённый срок 3 курс
                 //|| DM -> QAbituraTERM_EDU -> Value == 5
                    DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::SHORT_THIRD_COURSE
                 || DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::HIGH_THIRD_COURSE
               )
            {
                CellValue (
                    "При зачислении на 3 курс – протокол "  \
                    "приемной комиссии от",
                    3,
                    14
                );
                CellValue (
                    "2. Срок получения образования "        \
                    "составляет три года.",
                    3,
                    18
                );

                if (DM -> QAbituraVID_EDU -> Value == 1)                        // БЮДЖЕТ, ЗАОЧНОЕ, СОКРАЩЁННЫЙ СРОК
                    CellValue (
                        Contract::COST_FOR::BUDGET::EXTRAMURAL::THIRD_COURSE,
                        1,
                        20
                    );

            }


            CellValue (
                "обеспечить его подготовку по специальности "       +
                    interactive                                     +
                ", указанной(ым)",
                1,
                32
            );
            CellValue (
                    interactive                                     +
                " в соответствии с пунктом 1 настоящего договора;",
                1,
                44
            );


            switch (nom_fac)
            {
                case 1:
                        CellValue (
                            "Проректор по учебной работе:",
                            1,
                            89
                        );
                        CellValue (
                            "______________________ /"                  +
                                LegallyAuthorizedPerson::VICE_RECTOR    +
                            "/",
                            1,
                            90
                        );
                        //CellValue (
                        //    "Декан: ________________/"                  +
                        //        LegallyAuthorizedPerson::DEAN_FACULTY_1 +
                        //    "/",
                        //    1,
                        //    99
                        //);
                    break;
                case 2:
                        CellValue (
                            "Проректор по учебной работе:",
                            1,
                            89
                        );
                        CellValue (
                            "______________________ /"                  +
                                LegallyAuthorizedPerson::VICE_RECTOR    +
                            "/",
                            1,
                            90
                        );
                        //CellValue (
                        //    "Декан: ________________/"                  +
                        //        LegallyAuthorizedPerson::DEAN_FACULTY_2 +
                        //    "/",
                        //    1,
                        //    99
                        //);
                    break;
                case 3:
                        CellValue (
                            "Проректор по учебной работе:",
                            1,
                            89
                        );
                        CellValue (
                            "______________________ /"                  +
                                LegallyAuthorizedPerson::VICE_RECTOR    +
                            "/",
                            1,
                            90
                        );
                        //CellValue (
                        //    "Декан: ________________/"                  +
                        //        LegallyAuthorizedPerson::DEAN_FACULTY_3 +
                        //    "/",
                        //    1,
                        //    99
                        //);
                    break;
                case 4:
                        CellValue (
							"Декан факультета менеджмента спорта, туризма и ",
                            1,
                            89
                        );
                        CellValue (
							"гостеприимства Института менеджмента спорта и туризма:",
                            1,
                            90
						);
                        CellValue (
                            "______________________ /"                  +
                                LegallyAuthorizedPerson::DEAN_FACULTY_4 +
                            "/",
                            1,
                            91
                        );
                    break;
            }


            CellValue (                                                         // Вывод ФИО в подписи
                    DM -> QAbituraFAM  -> Value                 +
                " "                                             +
                    DM -> QAbituraNAME -> Value                 +
                " "                                             +
                    DM -> QAbituraOTCH -> Value,
                10,
                78
            );

            CellValue (
                "Адрес: "                                       +
                    DM -> QAbituraADDRESS_BEFORE -> Value,
                10,
                80
            );


            s_tmp =
                    DM -> QAbituraPASPORT -> Value              +
                ", выдан "                                      +
                    DateTimeToStr (
                        SQLTimeStampToDateTime (
                            DM -> QAbituraDATE_V -> Value
                        )
                    )                                           +
                " "                                             +
                    DM -> QAbituraORGAN_V -> Value;


            if (DM -> QAbituraPERSONAL_NOMER -> Value != "")
                s_tmp +=
                    ", "                                        +
                        DM -> QAbituraPERSONAL_NOMER -> Value;

            CellValue (
                s_tmp,
                10,
                84
            );


            // DisplayAlert (ExcelApplication_d);                               // сохранение

            OVisible (ExcelApplication_d);

            WorkSaveAs = SaveBook (Workbook);

            ExcelApplication_d.Clear ();
        }
        else                                                                    // ПЛАТНИКИ
        {
            ExcelApplication_d = Variant::CreateObject ("Excel.Application");

            Variant Workbook =
                OpenBook (
                    ExcelApplication_d,
                    cur_dir                         +
                    Contract::DOCUMENT_FILE::BUYERS
                );

            Sheet_d =
                SelectSheet (
                    Workbook,
                    "Лист1"
                );

            CellValue (
                "«____» __________ "        +
                    Admissions::TIME::YEAR  +
                " г.",
                1,
                4
            );
            CellValue (
                "г. Минск",
                29,
                4
            );

            AnsiString n_file =
                    Contract::DOCUMENT_NAME::BUYERS +
                " "                                 +
                    DM -> QAbituraFAM -> Value      +
                " "                                 +
                    DM -> QAbituraNAME -> Value     +
                " "                                 +
                    DM -> QAbituraOTCH -> Value     +
                ".xls";

            DisplayAlert (ExcelApplication_d);

            Variant
                WorkSaveAs =
                    SaveBookAs (
                        Workbook,
                        out_dir     +
                        n_file
                    );

            String
                s_tmp;

            if (nom_fac != 4)
            {
                s_tmp =
                    "лице проректора по учебной работе "                    +
                        Contract::BSUPC::PERSON                             +
                    ", действующего на основании "                          +
                        Contract::BSUPC::BASE_DOCUMENT::NAME                +
                    " от "                                                  +
                        Contract::BSUPC::BASE_DOCUMENT::DATE                +
                    " № "                                                   +
                        Contract::BSUPC::BASE_DOCUMENT::NUMBER              +
                    ", именуемое в дальнейшем Учреждение образования, с "   \
                    "одной стороны, и гражданин "                           +
                        DM -> QAbituraFAM  -> Value                         +
                    " "                                                     +
                        DM -> QAbituraNAME -> Value                         +
                    " "                                                     +
                        DM -> QAbituraOTCH -> Value                         +
                    ", именуемый в дальнейшем Обучающийся или Иностранный " \
                    "обучающийся (для иностранных граждан и лиц без "       \
                    "гражданства, временно пребывающих или временно "       \
                    "проживающих в Республике Беларусь) (далее, если не "   \
                    "указано иное, – Обучающийся), с другой стороны, и "    \
                    "___________________________________________________"   \
                    "_____________________";

                CellValue (
                    s_tmp,
                    1,
                    7
                );
            }
            else
            {
                s_tmp =
                    "в лице декана факультета менеджмента спорта, туризма " \
                    "и гостеприимства Института менеджмента спорта и "      \
                    "туризма "                                              +
                        Contract::IMS::PERSON                               +
                    ", действующей на основании "                           +
                        Contract::IMS::BASE_DOCUMENT::NAME                  +
                    " от "                                                  +
                        Contract::IMS::BASE_DOCUMENT::DATE                  +
                    " № "                                                   +
                        Contract::IMS::BASE_DOCUMENT::NUMBER                +
                    ", именуемое в дальнейшем Учреждение образования, с "   \
                    "одной стороны, и гражданин "                           +
                        DM -> QAbituraFAM  -> Value                         +
                    " "                                                     +
                        DM -> QAbituraNAME -> Value                         +
                    " "                                                     +
                        DM -> QAbituraOTCH -> Value                         +
                    ", именуемый в дальнейшем Обучающийся или Иностранный " \
                    "обучающийся (для иностранных граждан и лиц без "       \
                    "гражданства, временно пребывающих или временно "       \
                    "проживающих в Республике Беларусь) (далее, если не "   \
                    "указано иное, – Обучающийся), с другой стороны, и "    \
                    "_________________________________________________";

                CellValue (
                    s_tmp,
                    1,
                    7
                );
            }

            spec_str +=                                                         // Вывод квалификации и названия факультета
                " "                                             +
                    cod_specializ1                              +
                " «"                                            +
                    sp_full                                     +
                "» с присвоением квалификации "                 +
                    qualific1;

            switch (nom_fac)                                                    // факультет
            {
                case 1:
                        spec_str +=
                            " на спортивно-педагогическом факультете "      \
                            "спортивных игр и единоборств";
                    break;
                case 2:
                        spec_str +=
                            " на спортивно-педагогическом факультете "      \
                            "массовых видов спорта";
                    break;
                case 3:
                        spec_str +=
                            " на факультете оздоровительной физической "    \
                            "культуры";
                    break;
                case 4:
                        spec_str +=
                            " на факультете менеджмента спорта, туризма "   \
                            "и гостеприимства Института менеджмента "       \
                            "спорта и туризма";
                    break;
            }


            if (DM -> QAbituraVID_EDU -> Value)
                s_tmp = EducationType::EXTRA_FORM;
            else
                s_tmp = EducationType::INTRA_FORM;


            CellValue (
                spec_str,
                1,
                17
            );
            CellValue (
                "в "                                +
                    s_tmp                           +
                " форме получения образования на "  \
                "платной основе за счет средств",
                1,
                18
            );


            Variant CC1 =
                SelectCell (
                    3,
                    30
                );
            Variant CC2 =
                SelectCell (
                    36,
                    30
                );
            Variant RCC;


            if ( //   DM -> QAbituraTERM_EDU -> Value == 0                        // Полный срок QAbituraTERM_EDU = 0 или 2
                 //|| DM -> QAbituraTERM_EDU -> Value == 3
                    DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::FULL
                 || DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::HIGH_FIRST_COURSE
               )
            {
                RCC =
                    Range (
                        Sheet_d,
                        CC1,
                        CC2
                    );

                mergeCell (RCC);

                HorizontalAlign (
                    RCC,
                    2
                );
                VerticalAlign (
                    RCC,
                    3
                );
                CellValue (
                    "При зачислении на 1 курс – протокол "  \
                    "приемной комиссии от",
                    3,
                    23
                    );

                if (DM -> QAbituraVID_EDU -> Value == 0)
                    CellValue (                                                 // дневное - 4
                        "2. Срок получения образования "    \
                        "составляет четыре года.",
                        3,
                        27
                    );
                else
                    CellValue (                                                 // заочное - 5 лет
                        "2. Срок получения образования "    \
                        "составляет пять лет.",
                        3,
                        27
                    );
            }


            if ( //   DM -> QAbituraTERM_EDU -> Value == 1
                 //|| DM -> QAbituraTERM_EDU -> Value == 4
                    DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::SHORT_SECOND_COURSE
                 || DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::HIGH_SECOND_COURSE
               )
            {
                CellValue (
                    "При зачислении на 2 курс – "       \
                    "протокол приемной комиссии от",
                    3,
                    23
                );

                RCC =
                    Range (
                        Sheet_d,
                        CC1,
                        CC2
                    );

                mergeCell (RCC);

                HorizontalAlign (
                    RCC,
                    2
                );
                VerticalAlign (
                    RCC,
                    3
                );

                if (DM -> QAbituraVID_EDU -> Value == 0)
                    CellValue (                                                 // дневное - 3 года
                        "2. Срок получения образования "    \
                        "составляет три года.",
                        3,
                        27
                    );
                else
                    CellValue (                                                 // заочное - 4 года
                        "2. Срок получения образования "    \
                        "составляет четыре года.",
                        3,
                        27
                    );
            }


            if (    DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::SHORT_THIRD_COURSE
                 || DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::HIGH_THIRD_COURSE
               )
            {
                CellValue (
                    "При зачислении на 3 курс – "       \
                    "протокол приемной комиссии от",
                    3,
                    23
                );

                RCC =
                    Range (
                        Sheet_d,
                        CC1,
                        CC2
                    );

                mergeCell (RCC);

                HorizontalAlign (
                    RCC,
                    2
                );
                VerticalAlign (
                    RCC,
                    3
                );
                CellValue (
                    "2. Срок получения образования "    \
                    "составляет три года.",
                    3,
                    27
                );
            }



            if (DM -> QAbituraVID_EDU -> Value == 0)                            // Вывод стоимости обучения ЗА ГОД и ПОЛГОДА
            {
                CellValue (                                                     // ПЛАТНИКИ, ДНЕВНОЕ, ЗА ГОД
                    Contract::COST_FOR::BUYERS::INTRAMURAL::ANNUAL,
                    1,
                    30
                );


                CellValue (
                    Contract::PAYMENT_TERM::FIRST_SEMESTER,
                    3,
                    48
                );
                CellValue (
                    Contract::PAYMENT_TERM::SECOND_SEMESTER,
                    3,
                    50
                );


                CellValue (                                                     // ПЛАТНИКИ, ДНЕВНОЕ, ПО СЕМЕСТРАМ
                    Contract::COST_FOR::BUYERS::INTRAMURAL::PER_SEMESTER,
                    1,
                    49
                );
                CellValue (                                                     // ПЛАТНИКИ, ДНЕВНОЕ, ПО СЕМЕСТРАМ
                    Contract::COST_FOR::BUYERS::INTRAMURAL::PER_SEMESTER,
                    1,
                    51
                );
            }
            else
            {
                if (n_sp != 61)                                                 // Не ИМСиТ
                {
                    CellValue (                                                 // ЗА ОПЛАТУ, ЗАОЧНОЕ, ЗА ГОД (СИиЕ, МВС, ОФК)
                        Contract::COST_FOR::BUYERS::EXTRAMURAL::ANNUAL,
                        1,
                        30
                    );


                    CellValue (
                        Contract::PAYMENT_TERM::FIRST_SEMESTER,
                        3,
                        48
                    );
                    CellValue (
                        Contract::PAYMENT_TERM::SECOND_SEMESTER,
                        3,
                        50
                    );


                    CellValue (                                                 // ЗА ОПЛАТУ, ЗАОЧНОЕ, ПО СЕМЕСТРАМ (СИиЕ, МВС, ОФК)
                        Contract::COST_FOR::BUYERS::EXTRAMURAL::PER_SEMESTER,
                        1,
                        49
                    );
                    CellValue (                                                 // ЗА ОПЛАТУ, ЗАОЧНОЕ, ПО СЕМЕСТРАМ (СИиЕ, МВС, ОФК)
                        Contract::COST_FOR::BUYERS::EXTRAMURAL::PER_SEMESTER,
                        1,
                        51
                    );
                }
                else                                                            // ИТ
                {
                    CellValue (                                                 // ПЛАТНИКИ, ЗАОЧНОЕ, ЗА ГОД (ИМСиТ)
                        Contract::COST_FOR::BUYERS::EXTRAMURAL::ANNUAL_IMS,
                        1,
                        30
                    );


                    CellValue (
                        Contract::PAYMENT_TERM::FIRST_SEMESTER,
                        3,
                        48
                    );
                    CellValue (
                        Contract::PAYMENT_TERM::SECOND_SEMESTER,
                        3,
                        50
                    );


                    CellValue (                                                 // ПЛАТНИКИ, ЗАОЧНОЕ, ПО СЕМЕСТРАМ (ИМСиТ)
                        Contract::COST_FOR::BUYERS::EXTRAMURAL::PER_SEMESTER_IMS,
                        1,
                        49
                    );
                    CellValue (                                                 // ПЛАТНИКИ, ЗАОЧНОЕ, ПО СЕМЕСТРАМ (ИМСиТ)
                        Contract::COST_FOR::BUYERS::EXTRAMURAL::PER_SEMESTER_IMS,
                        1,
                        51
                    );
                }
            }


            CellValue (
                "и обеспечить его подготовку по "                   \
                "специальности "                                    +
                    interactive                                     +
                ", указанной(ым) в пункте 1 настоящего договора, "  \
                "на русском языке;",
                1,
                79
            );
            CellValue (
                    interactive                                     +
                " в соответствии с пунктом 1 настоящего договора;",
                1,
                87
            );
			int vid_edu = DM -> QAbituraVID_EDU -> Value;
			switch(vid_edu) {
				case 0:
					CellValue (
							"9.6. Расходы бюджета на подготовку специалиста с высшим образованием в год составляют",
							3,
							146
						);
					CellValue (
							"10317,20 (десять тысяч триста семнадцать рублей 20 копеек) белорусских рублей.",
							1,
							147
						);
					break;
				case 1:
					CellValue (
							"9.6. Расходы бюджета на подготовку специалиста с высшим образованием в год составляют",
							3,
							146
						);
					CellValue (
							"4126,88 (четыре тысячи сто двадцать шесть рублей 88 копеек) белорусских рублей.",
							1,
							147
						);
					break;
			}

			switch (nom_fac)
            {
                case 1:
						CellValue (
							"Проректор по учебной работе:",
							1,
							185
						);
                        CellValue (
                            "______________ /"                          +
                                LegallyAuthorizedPerson::VICE_RECTOR    +
                            "/",
                            1,
                            186
                        );
                        //CellValue (
                        //    "Декан: __________/"                        +
                        //        LegallyAuthorizedPerson::DEAN_FACULTY_1 +
                        //    "/",
                        //    1,
                        //    204
                        //);
                    break;
                case 2:
                        CellValue (
                            "Проректор по учебной работе:",
                            1,
                            185
                        );
                        CellValue (
                            "______________ /"                          +
                                LegallyAuthorizedPerson::VICE_RECTOR    +
                            "/",
                            1,
                            186
                        );
                        //CellValue (
                        //    "Декан: ________/"                          +
                        //        LegallyAuthorizedPerson::DEAN_FACULTY_2 +
                        //    "/",
                        //    1,
                        //    204
                        //);
                    break;
                case 3:
                        CellValue (
                            "Проректор по учебной работе:",
                            1,
                            185
                        );
                        CellValue (
                            "______________ /"                          +
                                LegallyAuthorizedPerson::VICE_RECTOR    +
                            "/",
                            1,
                            186
                        );
                        //CellValue (
                        //    "Декан: _______/"                           +
                        //        LegallyAuthorizedPerson::DEAN_FACULTY_3 +
                        //    "/",
                        //    1,
                        //    204
                        //);
                    break;
                case 4:
                        CellValue (
                            "Декан факультета менеджмента",
                            1,
                            184
                        );
                        CellValue (
                            "спорта, туризма и гостеприимства",
                            1,
                            185
                        );
                        CellValue (
                            "Института менеджмента",
                            1,
                            186
                        );
                        CellValue (
                            "спорта и туризма:",
                            1,
                            187
                        );
                        CellValue (
                            "______________________ /"                  +
                                LegallyAuthorizedPerson::DEAN_FACULTY_4 +
                            "/",
                            1,
                            188
                        );
                    break;
            }


            CellValue (                                                         // Вывод ФИО в подписи
                    DM -> QAbituraFAM  -> Value +
                " " +
                    DM -> QAbituraNAME -> Value +
                " " +
                    DM -> QAbituraOTCH -> Value,
                13,
                166
            );

            CellValue (
                "Адрес: "                                   +
                    DM -> QAbituraADDRESS_BEFORE -> Value,
                13,
                170
            );

            s_tmp =
                "личность: " +
                    DM -> QAbituraPASPORT -> Value +
                ", выдан " +
                    DateTimeToStr (
                        SQLTimeStampToDateTime (
                            DM -> QAbituraDATE_V -> Value
                        )
                    ) +
                " " +
                    DM -> QAbituraORGAN_V -> Value;

            if (DM -> QAbituraPERSONAL_NOMER -> Value != "")
                s_tmp =
                        s_tmp                               +
                    ", "                                    +
                    DM -> QAbituraPERSONAL_NOMER -> Value;

            CellValue (
                s_tmp,
                13,
                177
            );

            DisplayAlert (ExcelApplication_d);                                  // сохранение запрос на подтверждение

            OVisible (ExcelApplication_d);

            WorkSaveAs = SaveBook (Workbook);

            ExcelApplication_d.Clear ();
        }
    }


    if (DM -> QAbituraCATEGORY_IF -> Value == 1)
        return
            ShowMessage (
                "Договора с иностранными гражданами "   \
                "заполняют в международном отделе!"
            );


    if (DM -> QAbituraKONKURS -> Value == 3)
        return
            ShowMessage (
                "У абитуриента уже есть договор о "     \
                "целевой подготовке!"
            );
}
void __fastcall TListDlgForm::DBEdit1KeyPress (
        TObject * Sender,
        char    & Key
    )
{
    if (Key == 13)
    {
        DM -> TDocum -> ApplyUpdates ();
        DM -> TDocum -> CommitUpdates ();
    }
    else
        if (Key == 27)
            DM -> TDocum -> CancelUpdates ();
}
void __fastcall TListDlgForm::Exam_list_first ()                                // Печать первой страницы экзаменационного листа
{
    Exam_ListForm = new TExam_ListForm (this);

    DM -> QReport_Rasp -> Close ();

    DM -> QReport_Rasp ->
        ParamByName ("N_AB") -> AsInteger =
                DM -> QAbituraNOMER_AB -> Value;

    DM -> QReport_Rasp -> Open ();

    TfrxMemoView * Memo23 =
        dynamic_cast <TfrxMemoView *>
        (
            Exam_ListForm -> frxRepExam ->
                FindObject (
                    "Memo23"
                )
        );

    Memo23 -> Text =
        DM ->
            NumDelaString (
                DM -> QAbituraVID_EDU  -> Value,
                DM -> QAbituraTERM_EDU -> Value,
                DM -> QAbituraPRICE    -> Value,
                DM -> QAbituraNOM_DELA -> Value
            );



    AnsiString
        cod_specializ,
        sp_full;

	if (    DM -> QAbituraTERM_EDU -> Value != StudyPeriodCode::HIGH_THIRD_COURSE
         //   DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::FULL
         //|| DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::HIGH_FIRST_COURSE
       )
    {
        sp_full =
            DeleteAfterDatabaseChange::getNcrb2022CodeNameSportStrByNSpecializ (
                DM -> QReport_RaspN_SPECIALIZ -> Value
            );
    }
    else
    {
        cod_specializ = "1-88 02 01-01 ";

        if (DM -> QAbituraN_SPEC -> Value == 6)                                 // Спортивно-педагогическая деятельность (по направлениям) 1-88 02 01-01
        {
            switch (DM -> QAbituraN_SPECIALIZ -> Value)
            {
                case 48:
                        cod_specializ = "1-88 02 01-02 ";
                    break;
                case 52:
                        cod_specializ = "1-88 02 01-03 ";
                    break;
                case 56:
                        cod_specializ = "1-88 02 01-04 ";
                    break;
            }
        }
        else
        {
            switch (DM -> QAbituraN_SPECIALIZ -> Value)                         // специализация
            {
                case 3:
                        cod_specializ = "1-88 01 03-01 ";
                    break;
                case 4:
                        cod_specializ = "1-88 01 01-01 ";
                    break;
                case 38:
                        cod_specializ = "1-88 01 02-01 ";
                    break;
                case 39:
                        cod_specializ = "1-88 01 02-02 ";
                    break;
                case 47:
                        cod_specializ = "1-88 01 03-02 ";
                    break;
                case 100:
                        cod_specializ = "1-89 02 01-01 ";
                    break;
                case 51:
                        cod_specializ = "1-89 02 01-02 ";
                    break;
                case 52:
                        cod_specializ = "1-88 02 01-03 ";
                    break;
                case 57:
                        cod_specializ = "1-88 01 01-02 ";
                    break;
                case 61:
                        cod_specializ = "1-89 01 01 ";
                    break;
            }
        }

        sp_full =
                cod_specializ                               +
            "«"                                             +
                DM -> vozvrat_spec (
                    DM -> QReport_RaspN_SPECIALIZ -> Value
                )                                           +
            "»";
    }




    TfrxMemoView * Memo51 =
        dynamic_cast <TfrxMemoView *>
        (
            Exam_ListForm -> frxRepExam ->
                FindObject (
                    "Memo51"
                )
        );

    if (sp_full.Length () < 35)
        Memo51 -> Text = "";

    if (sp_full.Length () > 80)
        Memo51 -> Font -> Size = 10;

    Memo51 -> Text = sp_full;

    TfrxMemoView * Memo21 =
        dynamic_cast <TfrxMemoView *>
        (
            Exam_ListForm -> frxRepExam ->
                FindObject (
                    "Memo21"
                )
        );

    if (nom_fac == 4)
        Memo21 -> Text = "ИНСТИТУТ МЕНЕДЖМЕНТА СПОРТА И ТУРИЗМА";
    else
        Memo21 -> Text = "";

    pms_print = new TMemoryStream ();
    jp_print  = new Jpeg::TJPEGImage ();

    Variant    photo = & (DM -> QReport_RaspPHOTO -> Value);
    AnsiString ph    = photo.AsType (varString);

    TfrxPictureView * Picture =
        dynamic_cast <TfrxPictureView *>
        (
            Exam_ListForm -> frxRepExam ->
                FindObject (
                    "Picture1"
                )
        );


    if (ph != "")                                                               // показ Image картинки из базы
    {
        pms_print -> Clear ();

        DM        -> QReport_RaspPHOTO -> SaveToStream (pms_print);

        pms_print -> Position = 0;

        jp_print  -> LoadFromStream (pms_print);

        Picture   -> Picture -> Assign (jp_print);
    }
    else
        Picture -> Picture = NULL;


    if (pms_print)
        delete pms_print;
    
    if (jp_print)
        delete jp_print;
}
void __fastcall TListDlgForm::Exam_list_two ()
{
    Exam_List_obForm = new TExam_List_obForm (this);

    DM -> QSertificat_ex_list -> Close ();                                      // показ сертификатов только этого абитуриента

    DM -> QSertificat_ex_list ->
        ParamByName ("NOMER") -> AsInteger =
                DM -> QAbituraNOMER_AB -> Value;

    DM -> QSertificat_ex_list -> Open ();


    int rec_sert = DM -> QSertificat_ex_list -> RecordCount;                    // количество сертификатов

    TfrxPictureView * Picture1 =
        dynamic_cast <TfrxPictureView *>
        (
            Exam_List_obForm -> frxRepExamOb ->
                FindObject ("Picture1")
        );
    TfrxPictureView * Picture2 =
        dynamic_cast <TfrxPictureView *>
        (
            Exam_List_obForm -> frxRepExamOb ->
                FindObject ("Picture2")
        );
    TfrxPictureView * Picture3 =
        dynamic_cast <TfrxPictureView *>
        (
            Exam_List_obForm -> frxRepExamOb ->
                FindObject ("Picture3")
        );

    switch (rec_sert)
    {
        case 3:                                                                 // 3 сертификата
                Memo_number =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo32")
                    );
                Memo_text_predm =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo33")
                    );
                MemoDATE_PRIEM =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo34")
                    );
                MemoBALL =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo35")
                    );
                Memo_text_ball =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo36")
                    );
                MemoFIO =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo37")
                    );
                PictureOb =
                    dynamic_cast <TfrxPictureView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Picture4")
                    );

                StringSertificat ();

                rec_sert--;

                DM -> QSertificat_ex_list -> Next ();
        case 2:                                                                 // 2 сертификата
                Memo_number =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo25")
                    );
                Memo_text_predm =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo26")
                    );
                MemoDATE_PRIEM =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo27")
                    );
                MemoBALL =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo28")
                    );
                Memo_text_ball =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo29")
                    );
                MemoFIO =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo30")
                    );
                PictureOb =
                    dynamic_cast <TfrxPictureView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Picture3")
                    );
                Picture3 -> Visible = true;

                StringSertificat ();

                --rec_sert;

                DM -> QSertificat_ex_list -> Next ();
        case 1:                                                                 // 1 сертификат
                Memo_number =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo18")
                    );
                Memo_text_predm =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo19")
                    );
                MemoDATE_PRIEM =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo20")
                    );
                MemoBALL =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo21")
                    );
                Memo_text_ball =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo22")
                    );
                MemoFIO =
                    dynamic_cast <TfrxMemoView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Memo23")
                    );
                PictureOb =
                    dynamic_cast <TfrxPictureView *>
                    (
                        Exam_List_obForm -> frxRepExamOb ->
                            FindObject ("Picture2")
                    );
                Picture2 -> Visible = true;

                StringSertificat ();
            break;
    }


    TfrxMemoView * Memo12 =
        dynamic_cast <TfrxMemoView *>
        (
            Exam_List_obForm -> frxRepExamOb ->
                FindObject ("Memo12")
        );
    TfrxMemoView * Memo45 =
        dynamic_cast <TfrxMemoView *>
        (
            Exam_List_obForm -> frxRepExamOb ->
                FindObject ("Memo45")
        );
    TfrxMemoView * Memo13 =
        dynamic_cast <TfrxMemoView *>
        (
            Exam_List_obForm -> frxRepExamOb ->
                FindObject ("Memo13")
        );
    TfrxMemoView * Memo14 =
        dynamic_cast <TfrxMemoView *>
        (
            Exam_List_obForm -> frxRepExamOb ->
                FindObject ("Memo14")
        );
    TfrxMemoView * Memo15 =
        dynamic_cast <TfrxMemoView *>
        (
            Exam_List_obForm -> frxRepExamOb ->
                FindObject ("Memo15")
        );
    TfrxMemoView * Memo16 =
        dynamic_cast <TfrxMemoView *>
        (
            Exam_List_obForm -> frxRepExamOb ->
                FindObject ("Memo16")
        );


    if (    ! DM -> QAbituraMIDDLE_BALL -> Value                                // иностранцы и без среднего балла аттестата
         &&   DM -> QAbituraKONKURS     -> Value == 6
       )
    {
        Memo12   -> Visible = false;

        Memo45   -> Text    = "";
        Memo13   -> Text    = "";
        Memo14   -> Text    = "";
        Memo15   -> Text    = "";
        Memo16   -> Text    = "";

        Picture1 -> Visible = false;
    }
    else                                                                        // Средний балл аттестата
    {
        Memo12 -> Visible = true;


        Memo45 -> Text =
            "Средний балл док-та об образовании";
        Memo13 -> Text =
            DateTimeToStr (
                SQLTimeStampToDateTime (
                    DM -> QAbituraDATE_PRIEM -> Value
                )
            );


        if (DM -> QAbituraMIDDLE_BALL -> IsNull)
            Memo14 -> Text = "";
        else
        {
            if (    DM -> QAbituraMIDDLE_BALL -> Value
                 && nom_fac                            != 4
               )
                Memo14 -> Text =
                    FloatToStrF (
                        DM -> QAbituraMIDDLE_BALL -> Value,
                        ffFixed,
                        5,
                        1
                    );
            else
                if (DM -> QAbituraKONKURS -> Value == 3)
                    Memo14 -> Text =
                        FloatToStrF (
                            DM -> QAbituraMIDDLE_BALL -> Value,
                            ffFixed,
                            5,
                            1
                        );
            else
                if (DM -> QAbituraMIDDLE_BALL -> Value)
                    Memo14 -> Text =
                        FloatToStrF (
                            DM -> QAbituraMIDDLE_BALL -> Value,
                            ffFixed,
                            5,
                            0
                        );
            else
                Memo14 -> Text = "";
        }


        Memo15   -> Text    =
            scoresToWords (
                DM -> QAbituraMIDDLE_BALL -> Value,
                DM -> QAbituraKONKURS     -> Value != 30                        // difference for Institute of Tourism and Hospitality (ITaH)
            );
        Memo16   -> Text    = FIO;

        #ifndef ENROLLMENT_PEOPLE_WITHOUT_CERTIFICATES
            Picture1 -> Visible = true;
        #else
            Picture1 -> Visible = false;
            Memo45   -> Visible = false;
            Memo13   -> Visible = false;
            Memo16   -> Visible = false;
        #endif
    }
}
void __fastcall TListDlgForm::ExamSht1BtBtnClick (TObject * Sender)
{
    Exam_list_first ();
    
    Exam_ListForm -> frxRepExam -> ShowReport ();
    
    if (Exam_ListForm)
        delete Exam_ListForm;
}
void __fastcall TListDlgForm::ExamSht2BtBtnClick (TObject * Sender)
{
    Exam_list_two ();

    Exam_List_obForm -> frxRepExamOb -> ShowReport ();
    
    if (Exam_List_obForm)
        delete Exam_List_obForm;
}
void __fastcall TListDlgForm::ExamShtAllBtBtnClick (TObject * Sender)
{
    Exam_list_first ();
    Exam_list_two ();

    Exam_ListForm    -> frxRepExam   -> SaveToFile ("1.fr3");
    Exam_List_obForm -> frxRepExamOb -> SaveToFile ("2.fr3");

    Exam_ListForm    -> frxRepExam   -> LoadFromFile ("1.fr3");
    Exam_ListForm    -> frxRepExam   -> PrepareReport (true);

    Exam_ListForm    -> frxRepExam   -> LoadFromFile ("2.fr3");
    Exam_ListForm    -> frxRepExam   -> PrepareReport (false);

    Exam_ListForm    -> frxRepExam   -> ShowPreparedReport ();


    if (Exam_ListForm)
        delete Exam_ListForm;

    if (Exam_List_obForm)
        delete Exam_List_obForm;
}
void __fastcall TListDlgForm::FormActivate (TObject * Sender)
{
    FIOLbl -> Caption =
            DM -> QAbituraFAM  -> Value     +
        " "                                 +
            DM -> QAbituraNAME -> Value     +
        " "                                 +
            DM -> QAbituraOTCH -> Value;
}
void __fastcall TListDlgForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this  ->  Close ();
}
void __fastcall TListDlgForm::FormCreate (TObject * Sender)
{
    // ListBox2 -> Clear ();
    // // ListBox2 -> Items -> Add ("3 фотографии");
    // ListBox2 -> Items -> Add ("Медицинская справка");

    // ListBox2 -> Items ->
    //     Add (
    //         "Аттестат (диплом) о среднем образовании"
    //     );

    // if (DM -> QAbituraPRICE -> Value == 0)
    //     ContractBtBtn -> Caption = "Договор 2 экз.";
    // else
    //     ContractBtBtn -> Caption = "Договор 3 экз.";

    // // if (nom_fac != 4)
    // //     ListBox2 -> Items ->
    // //         Add (
    // //             "Классификационный билет"
    // //         );
}
int __fastcall TListDlgForm::GetFirstSelection (TCustomListBox * List)
{
    for ( int i = 0;
              i < List -> Items -> Count;
              ++i
        )
        if (List -> Selected[i])
            return i;

    return LB_ERR;
}
void __fastcall TListDlgForm::ListBox1DblClick (TObject * Sender)
{
    int Index;

    Index = GetFirstSelection (ListBox1);

    MoveSelected (
        ListBox1,
        ListBox2 -> Items
    );
    SetItem (
        ListBox1,
        Index
    );
}
void __fastcall TListDlgForm::ListBox2DblClick (TObject * Sender)
{
    int Index = GetFirstSelection (ListBox2);

    MoveSelected (
        ListBox2,
        ListBox1 -> Items
    );
    SetItem (
        ListBox2,
        Index
    );
}
void __fastcall TListDlgForm::MoveSelected (
        TCustomListBox * List,
        TStrings       * Items
    )
{
    for ( int i = List -> Items -> Count - 1;
              i >= 0;
              --i
        )
    {
        if (List -> Selected[i])
        {
            Items ->
                AddObject (
                    List -> Items -> Strings[i],
                    List -> Items -> Objects[i]
                );

            List -> Items -> Delete (i);
        }
    }
}
void __fastcall TListDlgForm::PleaSpdBtnClick (TObject * Sender)                // Печать заявления
{
    if (DM -> QAbituraCATEGORY_IF -> Value != 1)                                // Если НЕ ИНОСТРАНЕЦ
    {
        ExcelApplication_d =
            Variant::CreateObject (
                "Excel.Application"
            );
        Variant Workbook =
            OpenBook (
                ExcelApplication_d,
                cur_dir                                         +
                DocumentFile::APPLICATION_FOR::PARTICIPATION
            );
        Sheet_d =
            SelectSheet (
                Workbook,
                "Лист1"
            );

        AnsiString n_file =
                DocumentName::APPLICATION_FOR::PARTICIPATION    +
            " "                                                 +
                DM -> QAbituraFAM  -> Value                     +
            " "                                                 +
                DM -> QAbituraNAME -> Value                     +
            " "                                                 +
                DM -> QAbituraOTCH -> Value                     +
            ".xls";

        Variant WorkSaveAs =
            SaveBookAs (
                Workbook,
                out_dir     +
                n_file
            );

        String
            fac_text,
            spec_text = "по специальности ";

        switch (nom_fac)                                                        // Вывод названия факультета
        {
            case 1:
                    fac_text =
                        "на спортивно-педагогический факультет "    \
                        "спортивных игр и единоборств";
                break;
            case 2:
                    fac_text =
                        "на спортивно-педагогический факультет "    \
                        "массовых видов спорта";
                break;
            case 3:
                    fac_text =
                        "факультет оздоровительной физической "     \
                        "культуры ";
                break;
            case 4:
                    fac_text =
                        "факультет менеджмента спорта, туризма и "  \
                        "гостеприимства Института менеджмента "     \
                        "спорта и туризма";
                    spec_text =
                        "специальность ";
                break;
        }

        CellValue (
            fac_text,
            8,
            2
        );

        AnsiString
            cod_specializ1,
            sp_full;

		if (    DM -> QAbituraTERM_EDU -> Value != StudyPeriodCode::HIGH_THIRD_COURSE
             //   DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::FULL
             //|| DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::HIGH_FIRST_COURSE
           )
        {
            spec_text +=
                "(профилизация)\n";
            sp_full   =
                DeleteAfterDatabaseChange::getNcrb2022CodeNameSportStrByNSpecializ (
                    DM -> QAbituraN_SPECIALIZ -> Value
                );

            CellValue (
                    spec_text   +
                " "             +
                    sp_full,
                8,
                4
            );
        }
        else
        {
            cod_specializ1 = "1-88 02 01-01 ";

            if (DM -> QAbituraN_SPEC -> Value == 6)                             // Спортивно-педагогическая деятельность (по направлениям) 1-88 02 01-01
                switch (DM -> QAbituraN_SPECIALIZ -> Value)
                {
                    case 48:
                            cod_specializ1 = "1-88 02 01-02 ";
                        break;
                    case 52:
                            cod_specializ1 = "1-88 02 01-03 ";
                        break;
                    case 56:
                            cod_specializ1 = "1-88 02 01-04 ";
                        break;
                }
            else
                switch (DM -> QAbituraN_SPECIALIZ -> Value)                         // switch специализация
                {
                    case 3:
                            cod_specializ1 = "1-88 01 03-01 ";
                        break;
                    case 4:
                            cod_specializ1 = "1-88 01 01-01 ";
                        break;
                    case 38:
                            cod_specializ1 = "1-88 01 02-01 ";
                        break;
                    case 39:
                            cod_specializ1 = "1-88 01 02-02 ";
                        break;
                    case 47:
                            cod_specializ1 = "1-88 01 03-02 ";
                        break;
                    case 100:
                            cod_specializ1 = "1-89 02 01-01 ";
                        break;
                    case 51:
                            cod_specializ1 = "1-89 02 01-02 ";
                        break;
                    case 52:
                            cod_specializ1 = "1-88 02 01-03 ";
                        break;
                    case 57:
                            cod_specializ1 = "1-88 01 01-02 ";
                        break;
                    case 61:
                            cod_specializ1 = "1-89 01 01 ";
                        break;
                }

            spec_text +=
                "(направление специальности, специализация)\n";
            sp_full   =                                                         // Наименование специальности (направления специальности)
                DM -> vozvrat_spec (
                    DM -> QAbituraN_SPECIALIZ -> Value
                );

            CellValue (
                    spec_text       +
                    cod_specializ1  +
                "«"                 +
                    sp_full         +
                "»",
                8,
                4
            );
        }


        CellValue (
            "«____» ______________ "    +
                Admissions::TIME::YEAR  +
            " г.",
            1,
            8
        );
        CellValue (
            "Приказ «___» _________ "   +
                Admissions::TIME::YEAR  +
            " г. №_____",
            8,
            8
        );


        String adr =
            "который (ая) проживает по адресу: "        +
                DM -> QAbituraADDRESS_BEFORE -> Value;

        if (DM -> QAbituraPHONE -> Value != "")
            adr +=
                ", тел.: "                          +
                    DM -> QAbituraPHONE -> Value;

        CellValue (
            adr,
            1,
            15
        );

        DM -> LangSelQr -> Close ();
        DM -> LangSelQr ->
            ParamByName ("n_langvich") -> AsSmallInt =
                DM -> QAbituraN_LANGVICH -> Value;
        DM -> LangSelQr -> Open ();

        CellValue (
            "До поступления в учреждение высшего образования изучал (а) "   +
                DM -> LangSelQrLANGV -> AsString.LowerCase ()               +
            " язык.",
            1,
            25
        );

        DM -> LangSelQr -> Close ();

        String text_tmp =
            "   Прошу допустить меня к вступительным испытаниям и участию " \
            "в конкурсе, к участию в конкурсе (подчеркнуть один из "        \
            "перечисленных вариантов); для получения первого, второго, "    \
            "последующего высшего образования (подчеркнуть один "           \
            "из перечисленных вариантов); в ";

        if (DM -> QAbituraVID_EDU -> Value)
            text_tmp +=
                    EducationType::EXTRA_FORM       +
                " форме получения образования ";
        else
            text_tmp +=
                    EducationType::INTRA_FORM       +
                " форме получения образования ";

        if (DM -> QAbituraKONKURS -> Value == 3)                                // целевой
            text_tmp +=
                "на условиях целевой подготовки для получения образования";
        else
        {
            if (!DM -> QAbituraPRICE -> Value)
                text_tmp +=
                    "за счёт республиканского бюджета " \
                    "для получения образования";
            else
                text_tmp +=
                    "на платной основе для получения образования";
        }

        switch (DM -> QAbituraTERM_EDU -> Value)
        {
            case 0:
            case 3:
                    text_tmp += " в полный срок на";
                break;
            case 1:
            case 2:
            case 4:
            case 5:
                    text_tmp += " в сокращённый срок на";
                break;
        }

        switch (nom_fac)                                                        // Вывод названия факультета
        {
            case 1:
                    text_tmp +=
                        " спортивно-педагогическом факультете спортивных "  \
                        "игр и единоборств по специальности ";
                break;
            case 2:
                    text_tmp +=
                        " спортивно-педагогическом факультете массовых "    \
                        "видов спорта по специальности ";
                break;
            case 3:
                    text_tmp +=
                        " факультете оздоровительной физической культуры "  \
                        "по специальности ";
                break;
            case 4:
                    text_tmp +=
                        " факультете менеджмента спорта, туризма и "        \
                        "гостеприимства Института менеджмента спорта "      \
                        "и туризма по специальности ";
                break;
        }

		if (   DM -> QAbituraTERM_EDU -> Value != StudyPeriodCode::HIGH_THIRD_COURSE
             //   DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::FULL
             //|| DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::HIGH_FIRST_COURSE
           )
            text_tmp +=
                " (профилизация) "                              +
                    sp_full                                     +
                ".";
        else
            text_tmp +=
                " (направление специальности, специализация) "  +
                    cod_specializ1                              +
                "«"                                             +
                    sp_full                                     +
                "».";

        CellValue (
            text_tmp,
            1,
            27
        );

        text_tmp =
			"число, месяц, год рождения: "              +
                DateTimeToStr (
                    SQLTimeStampToDateTime (
                        DM -> QAbituraDATE_R -> Value
                    )
            );

        CellValue (
            text_tmp,
            1,
            30
        );

        text_tmp =
            "место работы, занимаемая должность "   \
            "служащего (профессия рабочего) ";

        if (DM -> QAbituraWORK_BEFORE -> Value == "")
            text_tmp += "-";
        else
            text_tmp += DM -> QAbituraWORK_BEFORE -> Value;

        CellValue (
            text_tmp,
            1,
            31
        );

        int st_y =
            DM -> QAbituraSTAG_SPEC -> Value / 12;
        int st_m =
            DM -> QAbituraSTAG_SPEC -> Value - (st_y * 12);

        text_tmp =
            "трудовой стаж по профилю избранной специальности " +
                IntToStr (st_y)                                 +
            " лет "                                             +
                IntToStr (st_m)                                 +
            " месяцев (полных)";

        CellValue (
            text_tmp,
            1,
            32
        );


        CellValue (                                                             // Папа, мама
            "отец: "                                +
                DM -> QAbituraPAPA -> Value,
            1,
            35
        );
        CellValue (
            "проживает по адресу: "                 +
                DM -> QAbituraADDRESS_PAPA -> Value,
            1,
            36
        );
        CellValue (
            "мать: "                            +
                DM -> QAbituraMAMA -> Value,
            1,
            37
        );
        CellValue (
            "проживает по адресу: "             +
                DM -> QAbituraADDRESS_MAMA -> Value,
            1,
            38
        );

        text_tmp =
            "данные документа, удостоверяющего личность: "      +
                DM -> QAbituraPASPORT -> Value                  +
			", выдан "                                          +
                DateTimeToStr (
                    SQLTimeStampToDateTime (
                        DM -> QAbituraDATE_V -> Value
                    )
                )                                               +
            " "                                                 +
                DM -> QAbituraORGAN_V        -> Value           +
            ", "                                                +
                DM -> QAbituraPERSONAL_NOMER -> Value;

        CellValue (
            text_tmp,
            1,
            40
        );


        text_tmp = "Вид конкурса: ";

        switch (DM -> QAbituraKONKURS -> Value)
        {
            case 0:
                    text_tmp += ContestType::GENERAL;
                break;
            case 1:
                    text_tmp += ContestType::WITHOUT_ENTRANCE_EXAMS;
                break;
            case 2:
                    text_tmp += ContestType::OUT_OF_COMPETITION;
                break;
            case 3:
                    text_tmp += ContestType::GENERAL;
                break;
        }

        CellValue (
            text_tmp,
            1,
            41
        );


        text_tmp = "Дополнительные сведения: ";

        switch (DM -> QAbituraN_SPORT_CATEGORY -> Value)
        {
            case 5:
                    text_tmp +=
                        SportsRanks::ABBR::MASTER_OF_SPORT;
                break;
            case 6:
                    text_tmp +=
                        SportsRanks::ABBR::INTERNATIONAL_MASTER_OF_SPORTS;
                break;
        }

        int pr_ck = 0;

        DM -> LogIDSelQr   -> Close ();
        DM -> LogIDSelQr ->
            ParamByName ("nomer_ab") -> AsInteger =
                    DM -> QAbituraNOMER_AB -> Value;
        DM -> LogIDSelQr   -> Open ();


        DM -> SelPrivLogQr -> Close ();
        DM -> SelPrivLogQr ->
            ParamByName ("id_log") -> AsInteger =
                    DM -> LogIDSelQrID_LOG -> Value;
        DM -> SelPrivLogQr -> Open ();

        while ( ! DM -> SelPrivLogQr -> Eof)
        {
            switch (DM -> SelPrivLogQrN_PRIV -> Value)
            {
				case 0:                                                         // БВИ
                        DM -> WithOutTestLogQr -> Close ();
                        DM -> WithOutTestLogQr ->
                            ParamByName ("sel_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrSEL_PRIV -> Value;
                        DM -> WithOutTestLogQr ->
                            ParamByName ("dat_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrDAT_PRIV -> Value;
                        DM -> WithOutTestLogQr -> Open ();

                        while (!DM -> WithOutTestLogQr -> Eof)
                        {
                            if (    text_tmp.SubString (
                                        text_tmp.Length (),
                                        1
                                    ) != " "
                            )
                                text_tmp += ", ";


                            text_tmp +=
                                DM -> WithOutTestLogQrSHORT_NAME -> Value;


                            if (    DM -> WithOutTestLogQrSHORT_NAME_1 -> Value
                                 != "да"
                               )
                                text_tmp +=
                                    " - "                                   +
                                    DM -> WithOutTestLogQrSHORT_NAME_1 ->
                                        Value;
                            ++pr_ck;

                            DM -> WithOutTestLogQr -> Next ();
                        }

                        DM -> WithOutTestLogQr -> Close ();

                        if (    pr_ck                          >  0
                             && DM -> QAbituraKONKURS -> Value == 3
                           )
                        {
                            CellValue (
                                "Вид конкурса: "                            +
                                    ContestType::WITHOUT_ENTRANCE_EXAMS,
                                1,
                                41
                            );

                            pr_ck = -1;
                        }
                    break;
                case 1:                                                         // ВК
                        DM -> OutTestQr -> Close ();
                        DM -> OutTestQr ->
                            ParamByName ("sel_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrSEL_PRIV -> Value;
                        DM -> OutTestQr ->
                            ParamByName ("dat_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrDAT_PRIV -> Value;
                        DM -> OutTestQr -> Open ();

                        while ( ! DM -> OutTestQr -> Eof)
                        {
                            if (    text_tmp.SubString (
                                        text_tmp.Length (),
                                        1
                                    ) != " "
                               )
                                text_tmp += ", ";


                            text_tmp += DM -> OutTestQrSHORT_NAME -> Value;


                            if (DM -> OutTestQrSHORT_NAME_1 -> Value != "да")
                                text_tmp +=
                                    " - "                                   +
                                    DM -> OutTestQrSHORT_NAME_1 -> Value;


                            if (pr_ck > -1)
                                ++pr_ck;

                            DM -> OutTestQr -> Next ();
                        }

                        DM -> OutTestQr -> Close ();

                        if (    pr_ck                          >  0
                             && DM -> QAbituraKONKURS -> Value == 3
                           )
                        {
                            CellValue (
                                "Вид конкурса: "                        +
                                    ContestType::OUT_OF_COMPETITION,
                                1,
                                41
                            );

                            --pr_ck;
                        }
                    break;
                case 2:                                                         // Другие
                        DM -> OtherPrivQr -> Close ();
                        DM -> OtherPrivQr ->
                            ParamByName ("sel_priv") -> AsSmallInt =
                                    DM -> SelPrivLogQrSEL_PRIV -> Value;
                        DM -> OtherPrivQr -> Open ();

                        while (!DM -> OtherPrivQr -> Eof)
                        {
                            if (    text_tmp.SubString (
                                        text_tmp.Length (),
                                        1
                                    ) != " "
                               )
                                text_tmp += ", ";


                            text_tmp += DM -> OtherPrivQrSHORT_NAME -> Value;


                            DM -> OtherPrivQr -> Next ();
                        }

                        DM -> OtherPrivQr -> Close ();
                    break;
            }

            DM -> SelPrivLogQr -> Next ();
        }

        DM -> SelPrivLogQr -> Close ();
        DM -> LogIDSelQr   -> Close ();


        CellValue (
            text_tmp,
            1,
            42
        );


        if (    text_tmp == "Дополнительные сведения: "
             || text_tmp == "Дополнительные сведения: ПОиПК БГУФК"
           )
            CellValue (
                "имею право на льготы: нет",
                1,
                39
            );
        else
            CellValue (
                "имею право на льготы: да",
                1,
                39
            );

        #ifdef TARGETED_CONTRACT_ENROLLMENT
             AnsiString additionalTergeted =
                "Ознакомлен с законодательством о целевой подготовке "      \
                "специалистов и обязуюсь предоставить документы об "        \
                "образовании не позднее "                                   +
                    Admissions::DOCUMENTS::PROVIDE_DATE                     +
                " г. и в случае непредоставления (либо отсутствия в нем "   \
                "необходимых данных, дающих право на льготы) забрать "      \
                "документы.";

            CellValue (
                additionalTergeted,
                1,
                54
            );

            CellValue (
                (cur_d.CurrentDate ())
                    .FormatString (
                        "dd.mm.yyyy"
                    ),
                1,
                56
            );
        #else
            AnsiString additionalTergeted =
                "   С порядком приёма и порядком подачи апелляции "         \
                "(нужное подчеркнуть) в учреждение образования "            \
                "ознакомлен(а).";

            CellValue (
                additionalTergeted,
                1,
                43
            );
        #endif

        CellValue (
                (cur_d.CurrentDate ())
                    .FormatString (
                        "dd.mm.yyyy"
                    ),
                1,
                45
            );
            CellValue (
                (cur_d.CurrentDate ())
                    .FormatString (
                        "dd.mm.yyyy"
                    ),
                1,
                51
            );


        DisplayAlert (                                                          // Сохранение
            ExcelApplication_d
        );
        OVisible (
            ExcelApplication_d
        );

        WorkSaveAs = SaveBook (Workbook);

        ExcelApplication_d.Clear ();
    }
    else
        ShowMessage (
            "Заявления от иностранных гражданан "   \
            "оформляют в международном отделе!"
        );
}
void __fastcall TListDlgForm::SetButtons ()
{
    bool SrcEmpty,
         DstEmpty;

    SrcEmpty = (ListBox1 -> Items -> Count == 0);
    DstEmpty = (ListBox2 -> Items -> Count == 0);

    SpeedButton1 -> Enabled = (!SrcEmpty);
    SpeedButton2 -> Enabled = (!DstEmpty);
}
void __fastcall TListDlgForm::SetItem (
        TListBox * List,
        int        Index
    )
{
    List -> SetFocus ();

    int MaxIndex = List -> Items -> Count - 1;

    if (Index == LB_ERR)
        Index = 0;
    else
        if (Index > MaxIndex)
            Index = MaxIndex;

    List -> Selected[Index] = true;

    SetButtons ();
}
void __fastcall TListDlgForm::SpeedButton1Click (TObject * Sender)
{
    int Index = GetFirstSelection (ListBox1);

    MoveSelected (
        ListBox1,
        ListBox2 -> Items
    );
    SetItem (
        ListBox1,
        Index
    );
}
void __fastcall TListDlgForm::SpeedButton2Click (TObject * Sender)
{
    int Index = GetFirstSelection (ListBox2);

    MoveSelected (
        ListBox2,
        ListBox1 -> Items
    );
    SetItem (
        ListBox2,
        Index
    );
}
void __fastcall TListDlgForm::SpeedButton3Click (TObject * Sender)              // Расписка
{
    Print_RaspiskaForm = new TPrint_RaspiskaForm (this);


    // ALL CODE BELOW THE SAME AS SpeedButton4Click starting from Print_OpisForm


    DM -> QReport_Rasp -> Close ();
    DM -> QReport_Rasp ->
        ParamByName ("N_AB") -> AsInteger =
                DM -> QAbituraNOMER_AB -> Value;
    DM -> QReport_Rasp -> Open ();


    DM -> QSertificat -> Close ();                                              // выбор сертификатов для выбранного абитуриента- они печатаются автоматически!!!!!!!!
    DM -> QSertificat ->
        ParamByName ("NOMER") -> AsInteger =
                DM -> QAbituraNOMER_AB -> Value;
    DM -> QSertificat -> Open ();


    TfrxMemoView * Memo4 =
        dynamic_cast <TfrxMemoView *>
        (
            Print_RaspiskaForm -> frxRepRaspiska ->
                FindObject (
                    "Memo4"
                )
        );

    Memo4 -> Text =
        DM -> NumDelaString (
            DM -> QAbituraVID_EDU  -> Value,
            DM -> QAbituraTERM_EDU -> Value,
            DM -> QAbituraPRICE    -> Value,
            DM -> QAbituraNOM_DELA -> Value
        );

    int  col =
        ListBox2 -> Items -> Count        +
        DM -> QSertificat -> RecordCount;

    int  i   = col - 1;

    bool R   = false;                                                           // переменная, чтобы сертификаты занеслись только 1 раз

    AnsiString list_stroka;                                                     // флаг исключения дубликатов сертификатов

    AnsiString text_at_orig  =
        DM -> TDocum ->
            Lookup (                                                            // "N_DOC" : 1, "TEXT_DOC" : "Аттестат об общем среднем образовании",
                "N_DOC",
                1,
                "TEXT_DOC"
            );

    AnsiString text_dip_prof =
        DM -> TDocum ->
            Lookup (                                                            // "N_DOC" : 2, "TEXT_DOC" : "Диплом о профессионально-техническом образовании",
                "N_DOC",
                2,
                "TEXT_DOC"
            );

    AnsiString text_dip_sred =
        DM -> TDocum ->
            Lookup (                                                            // "N_DOC" : 3, "TEXT_DOC" : "Диплом о среднем специальном образовании",
                "N_DOC",
                3,
                "TEXT_DOC"
            );

    AnsiString text_dip_vys  =
        DM -> TDocum ->
            Lookup (                                                            // "N_DOC" : 4, "TEXT_DOC" : "Копия диплома о высшем образовании",
                "N_DOC",
                4,
                "TEXT_DOC"
            );

    for ( int j = 0;                                                            // Формируем полную строку документа об образовании
              j < col;
              ++j
        )
    {
        list_stroka = ListBox2 -> Items -> Strings[j];


        if (list_stroka == text_at_orig)
            ListBox2 -> Items -> Strings[j] =
                    list_stroka                                     +
                " "                                                 +
                    getInfoAboutDocumentOnEducation (
                        DM -> QAbituraNOM_ATTEST       -> Value,
                        DM -> QAbituraNAME_EDU_MIDDLE  -> Value,
                        DM -> QAbituraWHERE_EDU_MIDDLE -> Value,
                        AnsiString (
                            DM -> QAbituraWHEN_EDU_MIDDLE -> Value
                        )
                    );


        if (list_stroka == text_dip_prof)
        {
            ListBox2 -> Items -> Strings[j] =
                    list_stroka                                     +
                " "                                                 +
                    getInfoAboutDocumentOnEducation (
                        DM -> QAbituraNOM_DIPLOM     -> Value,
                        DM -> QAbituraNAME_EDU_SPEC  -> Value,
                        DM -> QAbituraWHERE_EDU_SPEC -> Value,
                        AnsiString (
                            DM -> QAbituraWHEN_EDU_SPEC -> Value
                        )
                    );

            if (DM -> QAbituraNOM_DIPLOM -> IsNull)
                ListBox2 -> Items -> Strings[j] =
                        list_stroka                                 +
                    " "                                             +
                        getInfoAboutDocumentOnEducation (
                            DM -> QAbituraNOM_ATTEST      -> Value,
                            DM -> QAbituraNAME_EDU_MIDDLE -> Value,
                            DM -> QAbituraWHERE_EDU_SPEC  -> Value,
                            AnsiString (
                                DM -> QAbituraWHEN_EDU_MIDDLE -> Value
                            )
                        );
        }


        if (list_stroka == text_dip_sred)
        {
            ListBox2 -> Items -> Strings[j] =
                    list_stroka                                     +
                " "                                                 +
                    getInfoAboutDocumentOnEducation (
                        DM -> QAbituraNOM_ATTEST       -> Value,
                        DM -> QAbituraNAME_EDU_MIDDLE  -> Value,
                        DM -> QAbituraWHERE_EDU_MIDDLE -> Value,
                        AnsiString (
                            DM -> QAbituraWHEN_EDU_MIDDLE -> Value
                        )
                    );

            if (    ! DM -> QAbituraNOM_DIPLOM -> IsNull
                 ||   DM -> QAbituraNOM_DIPLOM -> Value  != ""
               )
                ListBox2 -> Items -> Strings[j] =
                        list_stroka                                 +
                    " "                                             +
                        getInfoAboutDocumentOnEducation (
                            DM -> QAbituraNOM_DIPLOM     -> Value,
                            DM -> QAbituraNAME_EDU_SPEC  -> Value,
                            DM -> QAbituraWHERE_EDU_SPEC -> Value,
                            AnsiString (
                                DM -> QAbituraWHEN_EDU_SPEC -> Value
                            )
                        );
        }


        if (list_stroka == text_dip_vys)
            ListBox2 -> Items -> Strings[j] =
                    list_stroka                                     +
                " "                                                 +
                    getInfoAboutDocumentOnEducation (
                        DM -> QAbituraNOM_DIPLOM     -> Value,
                        DM -> QAbituraNAME_EDU_SPEC  -> Value,
                        DM -> QAbituraWHERE_EDU_SPEC -> Value,
                        AnsiString (
                            DM -> QAbituraWHEN_EDU_SPEC -> Value
                        )
                    );


        if (    DM -> QSertificat -> RecordCount
             && ! R
           )
        {
            for ( int k = 0;                                                    // если найдена запись по централизованному тестированию
                      k < DM -> QSertificat -> RecordCount;
                      ++k
                )
            {
                AnsiString pr = "";

                switch (DM -> QSertificatRUS_BEL -> Value)                      // предмет
                {
                    case 0:
                            pr = "Русский язык";
                        break;
                    case 1:
                            pr = "Белорусский язык";
                        break;
                    case 2:
                            pr = "Биология";
                        break;
                    case 3:
                            pr = "Математика";
                        break;
                    case 4:
                            pr = "География";
                        break;
                }

                ListBox2 -> Items ->
                    Add (
                        "Сертификат централизованного экзамена "    \
                        "(тестирования) по предмету: "              +
                            pr                                      +
                        " серия "                                   +
                            DM -> QSertificatSERIA_S -> Value       +
                        " № "                                       +
                            DM -> QSertificatNOMER_S -> Value
                    );

                DM -> QSertificat -> Next ();
            }

            R = true;
        }
    }


    TfrxMemoView * Memo16 =
        dynamic_cast <TfrxMemoView *>
        (
            Print_RaspiskaForm -> frxRepRaspiska ->
                FindObject (
                    "Memo16"
                )
        );

    String s_tmp = "";

    for ( i = 0;
          i < col;
          ++i
        )
        s_tmp +=
            "\n"                                +
                IntToStr (i + 1)                +
            ". "                                +
                ListBox2 -> Items -> Strings[i];


    Memo16 -> Text = s_tmp;


    TfrxMemoView * Memo2 =
        dynamic_cast <TfrxMemoView *>
        (
            Print_RaspiskaForm -> frxRepRaspiska ->
                FindObject (
                    "Memo2"
                )
        );


    if (nom_fac == 4)
        Memo2 -> Text = "ИНСТИТУТ МЕНЕДЖМЕНТА СПОРТА И ТУРИЗМА";
    else
        Memo2 -> Text = "";



    AnsiString
        cod_specializ,
        description,
		sp_full;
		//  DM -> QAbituraTERM_EDU -> Value != StudyPeriodCode::HIGH_SECOND_COURSE

	if (    DM -> QAbituraTERM_EDU -> Value != StudyPeriodCode::HIGH_THIRD_COURSE
         //   DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::FULL
		 //|| DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::HIGH_FIRST_COURSE
       )
    {
        description =
            "Специальность (профилизация)";
        sp_full     =
            DeleteAfterDatabaseChange::getNcrb2022CodeNameSportStrByNSpecializ (
                DM -> QReport_RaspN_SPECIALIZ -> Value
            );

            #ifdef TEST_LIST_DLG
            ShowMessage (
                "In method SpeedButton3Click ()\n "                 \
                "QReport_RaspN_SPECIALIZ contains: "                +
                    DM -> QAbituraTERM_EDU -> AsString              +
                "\nQReport_RaspN_SPECIALIZ contains: "              +
                    DM -> QReport_RaspN_SPECIALIZ -> AsString
            );
            #endif
    }
    else
    {
        description   =
            "Специальность (направление специальности, специализация)";
        cod_specializ =
            "1-88 02 01-01 ";

        switch (DM -> QReport_RaspN_SPECIALIZ -> Value)                         // специализация
        {
            case 4:
                    cod_specializ = "1-88 01 01-01 ";
                break;
            case 57:
                    cod_specializ = "1-88 01 01-02 ";
                break;
            case 38:
                    cod_specializ = "1-88 01 02-01 ";
                break;
            case 39:
                    cod_specializ = "1-88 01 02-02 ";
                break;
            case 3:
                    cod_specializ = "1-88 01 03-01 ";
                break;
            case 47:
                    cod_specializ = "1-88 01 03-02 ";
                break;
            case 48:
                    cod_specializ = "1-88 02 01-02 ";
                break;
            case 52:
                    cod_specializ = "1-88 02 01-03 ";
                break;
            case 56:
                    cod_specializ = "1-88 02 01-04 ";
                break;
            case 61:
                    cod_specializ = "1-89 01 01 ";
                break;
            case 100:
                    cod_specializ = "1-89 02 01-01 ";
                break;
            case 51:
                    cod_specializ = "1-89 02 01-02 ";
                break;
        }

        sp_full =
                cod_specializ                               +
            "«"                                             +
                DM -> vozvrat_spec (
                    DM -> QReport_RaspN_SPECIALIZ -> Value
                )                                           +
            "»";
    }

    TfrxMemoView * Memo9 =                                                      // <- THIS IS THE DIFFERENCE FROM SpeedButton3Click
        dynamic_cast <TfrxMemoView *>
        (
            Print_RaspiskaForm -> frxRepRaspiska ->
                FindObject (
                    "Memo9"
                )
        );
    Memo9 -> Text = description;                                                // <- THIS IS THE DIFFERENCE FROM SpeedButton4Click

    TfrxMemoView * Memo17 =                                                     // <- THIS IS THE DIFFERENCE FROM SpeedButton4Click
        dynamic_cast <TfrxMemoView *>
        (
            Print_RaspiskaForm -> frxRepRaspiska ->
                FindObject (
                    "Memo17"
                )
        );

    if (sp_full.Length () < 35)                                                 // <- THIS IS THE DIFFERENCE FROM SpeedButton4Click
        Memo17 -> Text = "";

    if (sp_full.Length () > 80)                                                 // <- THIS IS THE DIFFERENCE FROM SpeedButton4Click
        Memo17 -> Font -> Size = 9;

    Memo17 -> Text = sp_full;                                                   // <- THIS IS THE DIFFERENCE FROM SpeedButton4Click


    TfrxMemoView * Memo30 =                                                     // <- THIS IS THE DIFFERENCE FROM SpeedButton4Click
        dynamic_cast <TfrxMemoView *>
        (
            Print_RaspiskaForm -> frxRepRaspiska ->
                FindObject (
                    "Memo30"
                )
        );

    Memo30 -> Text = Admissions::INVENTORY::DATE;


    Print_RaspiskaForm -> frxRepRaspiska -> ShowReport ();                      // <- THIS IS THE DIFFERENCE FROM SpeedButton4Click


    if (Print_RaspiskaForm)                                                     // <- THIS IS THE DIFFERENCE FROM SpeedButton4Click
        delete
            Print_RaspiskaForm;

    for ( int j =  col;
              j >= col - DM -> QSertificat -> RecordCount;
              --j
        )
        ListBox2 -> Items -> Delete (j);
}
void __fastcall TListDlgForm::SpeedButton4Click (TObject * Sender)              // Опись
{
    bool conf;

    DM -> ListDocFDQ -> Close ();
    DM -> ListDocFDQ ->
        ParamByName ("NOMER_AB") -> Value =
                DM -> QAbituraNOMER_AB -> Value;
    DM -> ListDocFDQ -> Open ();

    DM -> ListDocFDQ -> First ();


    for ( int j = 0;
              j < DM -> ListDocFDQ -> RecordCount;
              ++j
        )
    {
        conf = false;
        
        for ( int i = 0;
                  i < ListBox2 -> Items -> Count;
                  ++i
            )
        {
            if (    DM -> ListDocFDQN_DOC -> Value
                 == (int) (ListBox2 -> Items -> Objects[i])
               )
            {
                conf = true;

                i = ListBox2 -> Items -> Count;
            }
        }

        if ( ! conf)
        {
            DM -> ListDocFDQ -> Delete ();
            DM -> ListDocFDQ -> ApplyUpdates ();
            DM -> ListDocFDQ -> CommitUpdates ();
        }
        
        DM -> ListDocFDQ -> Next ();
    }


    DM -> ListDocFDQ -> Close ();
    DM -> ListDocFDQ ->
        ParamByName ("NOMER_AB") -> Value =
                DM -> QAbituraNOMER_AB -> Value;
    DM -> ListDocFDQ -> Open ();


    for ( int i = 0;
              i < ListBox2 -> Items -> Count;
              ++i
        )
    {
        conf = false;

        DM -> ListDocFDQ -> First ();


        for ( int j = 0;
                  j < DM -> ListDocFDQ -> RecordCount;
                  ++j
            )
        {
            if (    DM -> ListDocFDQN_DOC -> Value
                 == (int)(ListBox2 -> Items -> Objects[i])
               )
            {
                conf = true;
                j    = DM -> ListDocFDQ -> RecordCount;
            }

            DM -> ListDocFDQ -> Next ();
        }


        if ( ! conf)
        {
            DM -> DocumInListQ -> Close ();
            DM -> DocumInListQ ->
                ParamByName ("N_DOC") -> Value =
                        (int) (ListBox2 -> Items -> Objects[i]);
            DM -> DocumInListQ -> Open ();


            if (    DM -> DocumInListQDATE_DOC  -> AsBoolean == true 
                 || DM -> DocumInListQINDEX_DOC -> AsBoolean == true
                )
                opform = true;
            else
                opform = false;


            name_doc = DM -> DocumInListQTEXT_DOC -> Value;

            DM -> ListDocFDQ -> Insert ();

            DM -> ListDocFDQNOMER_AB -> Value = 
                DM -> QAbituraNOMER_AB -> Value;

            DM -> ListDocFDQN_DOC    -> Value = 
                (int)(ListBox2 -> Items -> Objects[i]);


            if (opform)
            {
                index_doc = "";

				if ((int)(ListBox2 -> Items -> Objects[i]) == 1)
                    index_doc = DM -> QAbituraNOM_ATTEST -> Value;


                if (    (int)(ListBox2 -> Items -> Objects[i]) == 2 
					 || (int)(ListBox2 -> Items -> Objects[i]) == 3
                   )
                {
                    index_doc = DM -> QAbituraNOM_DIPLOM -> Value;

                    if (DM -> QAbituraNOM_DIPLOM -> IsNull)
                        index_doc = DM -> QAbituraNOM_ATTEST -> Value;
                }


				if ( (int) (ListBox2 -> Items -> Objects[i]) == 4)
                    index_doc = DM -> QAbituraNOM_DIPLOM -> Value;


                ListDocIndexForm = new TListDocIndexForm (this);


                ListDocIndexForm -> Text_doc  -> Caption = name_doc;
                ListDocIndexForm -> IndexEdit -> Text    = index_doc;

                if (index_doc != "")
                    ListDocIndexForm -> IndexEdit -> ReadOnly = true;


                if (DM -> DocumInListQDATE_DOC -> AsBoolean == true)
                {
                    ListDocIndexForm -> DateEdit -> Visible = true;
                    ListDocIndexForm -> Label1   -> Visible = true;
                }
                else
                {
                    ListDocIndexForm -> DateEdit -> Visible = false;
                    ListDocIndexForm -> Label1   -> Visible = false;
                }


                if (DM -> DocumInListQINDEX_DOC -> AsBoolean == true)
                {
                    ListDocIndexForm -> IndexEdit -> Visible = true;
                    ListDocIndexForm -> Label2    -> Visible = true;
                }
                else
                {
                    ListDocIndexForm -> IndexEdit -> Visible = false;
                    ListDocIndexForm -> Label2    -> Visible = false;
                }

                ListDocIndexForm -> ShowModal ();
            }


            DM -> ListDocFDQ -> ApplyUpdates ();
            DM -> ListDocFDQ -> CommitUpdates ();
        }
    }


    Print_OpisForm = new TPrint_OpisForm (this);


    // ALL CODE BELOW THE SAME AS SpeedButton3Click --------------------------------

    DM -> QReport_Rasp -> Close ();
    DM -> QReport_Rasp ->
        ParamByName ("N_AB") -> AsInteger =
                DM -> QAbituraNOMER_AB -> Value;
    DM -> QReport_Rasp -> Open ();


    DM -> QSertificat -> Close ();                                              // выбор сертификатов - печатаются автоматически!!!!!!!!
    DM -> QSertificat ->
        ParamByName ("NOMER") -> AsInteger =
                DM -> QAbituraNOMER_AB -> Value;
    DM -> QSertificat -> Open ();


    TfrxMemoView * Memo3 =
        dynamic_cast <TfrxMemoView *>
        (
            Print_OpisForm -> frxRepOpis ->
                FindObject (
                    "Memo3"
                )
        );

    Memo3 -> Text =
        DM -> NumDelaString (
            DM -> QAbituraVID_EDU  -> Value,
            DM -> QAbituraTERM_EDU -> Value,
            DM -> QAbituraPRICE    -> Value,
            DM -> QAbituraNOM_DELA -> Value
        );

    int  col =
        ListBox2 -> Items -> Count          +
        DM -> QSertificat -> RecordCount;

    int  i   = col - 1;
    bool R   = false;

    AnsiString list_stroka;                                                     // флаг исключения дубликатов сертификатов

    AnsiString text_at_orig  =
        DM -> TDocum ->
            Lookup (                                                            // "N_DOC" : 1, "TEXT_DOC" : "Аттестат об общем среднем образовании",
                "N_DOC",
                1,
                "TEXT_DOC"
            );

    AnsiString text_dip_prof =
        DM -> TDocum ->
            Lookup (                                                            // "N_DOC" : 2, "TEXT_DOC" : "Диплом о профессионально-техническом образовании",
                "N_DOC",
                2,
                "TEXT_DOC"
            );

    AnsiString text_dip_sred =
        DM -> TDocum ->
            Lookup (                                                            // "N_DOC" : 3, "TEXT_DOC" : "Диплом о среднем специальном образовании",
                "N_DOC",
                3,
                "TEXT_DOC"
            );

    AnsiString text_dip_vys  =
        DM -> TDocum ->
            Lookup (                                                            // "N_DOC" : 4, "TEXT_DOC" : "Копия диплома о высшем образовании",
                "N_DOC",
                4,
                "TEXT_DOC"
            );

    for ( int j = 0;
              j < col;
              ++j
        )
    {
        list_stroka = ListBox2 -> Items -> Strings[j];                          // Формируем полную строку документа об образовании


        if (list_stroka == text_at_orig)
            ListBox2 -> Items -> Strings[j] =
                    list_stroka                                     +
                " "                                                 +
                    getInfoAboutDocumentOnEducation (
                        DM -> QAbituraNOM_ATTEST       -> Value,
                        DM -> QAbituraNAME_EDU_MIDDLE  -> Value,
                        DM -> QAbituraWHERE_EDU_MIDDLE -> Value,
                        AnsiString (
                            DM -> QAbituraWHEN_EDU_MIDDLE -> Value
                        )
                    );


        if (list_stroka == text_dip_prof)
        {
            ListBox2 -> Items -> Strings[j] =
                    list_stroka                                     +
                " "                                                 +
                    getInfoAboutDocumentOnEducation (
                        DM -> QAbituraNOM_DIPLOM     -> Value,
                        DM -> QAbituraNAME_EDU_SPEC  -> Value,
                        DM -> QAbituraWHERE_EDU_SPEC -> Value,
                        AnsiString (
                            DM -> QAbituraWHEN_EDU_SPEC -> Value
                        )
                    );

            if (DM -> QAbituraNOM_DIPLOM -> IsNull)
                ListBox2 -> Items -> Strings[j] =
                        list_stroka                                 +
                    " "                                             +
                        getInfoAboutDocumentOnEducation (
                            DM -> QAbituraNOM_ATTEST      -> Value,
                            DM -> QAbituraNAME_EDU_MIDDLE -> Value,
                            DM -> QAbituraWHERE_EDU_SPEC  -> Value,
                            AnsiString (
                                DM -> QAbituraWHEN_EDU_MIDDLE -> Value
                            )
                        );
        }


        if (list_stroka == text_dip_sred)
        {
            ListBox2 -> Items -> Strings[j] =
                    list_stroka                                     +
                " "                                                 +
                    getInfoAboutDocumentOnEducation (
                        DM -> QAbituraNOM_ATTEST       -> Value,
                        DM -> QAbituraNAME_EDU_MIDDLE  -> Value,
                        DM -> QAbituraWHERE_EDU_MIDDLE -> Value,
                        AnsiString (
                            DM -> QAbituraWHEN_EDU_MIDDLE -> Value
                        )
                    );

            if (    ! DM -> QAbituraNOM_DIPLOM -> IsNull
                 ||   DM -> QAbituraNOM_DIPLOM -> Value  != ""
               )
                ListBox2 -> Items -> Strings[j] =
                        list_stroka                                 +
                    " "                                             +
                        getInfoAboutDocumentOnEducation (
                            DM -> QAbituraNOM_DIPLOM     -> Value,
                            DM -> QAbituraNAME_EDU_SPEC  -> Value,
                            DM -> QAbituraWHERE_EDU_SPEC -> Value,
                            AnsiString (
                                DM -> QAbituraWHEN_EDU_SPEC -> Value
                            )
                        );
        }


        if (list_stroka == text_dip_vys)
            ListBox2 -> Items -> Strings[j] =
                    list_stroka                                     +
                " "                                                 +
                    getInfoAboutDocumentOnEducation (
                        DM -> QAbituraNOM_DIPLOM     -> Value,
                        DM -> QAbituraNAME_EDU_SPEC  -> Value,
                        DM -> QAbituraWHERE_EDU_SPEC -> Value,
                        AnsiString (
                            DM -> QAbituraWHEN_EDU_SPEC -> Value
                        )
                    );


        if (DM -> QSertificat -> RecordCount && !R)
        {
            for ( int k = 0;                                                    // поиск записей с ЦТ
                      k < DM -> QSertificat -> RecordCount;
                      ++k
                )
            {
                AnsiString pr = "";

                switch (DM -> QSertificatRUS_BEL -> Value)                      // предмет
                {
                    case 0:
                            pr = "Русский язык";
                        break;
                    case 1:
                            pr = "Белорусский язык";
                        break;
                    case 2:
                            pr = "Биология";
                        break;
                    case 3:
                            pr = "Математика";
                        break;
                    case 4:
                            pr = "География";
                        break;
                }

                ListBox2 -> Items ->
                    Add (
                        "Сертификат централизованного экзамена "    \
                        "(тестирования) по предмету: "              +
                            pr                                      +
                        " серия "                                   +
                            DM -> QSertificatSERIA_S -> Value       +
                        " № "                                       +
                            DM -> QSertificatNOMER_S -> Value
                    );

                DM -> QSertificat -> Next ();
            }

            R = true;
        }
    }


    TfrxMemoView * Memo38 =
        dynamic_cast <TfrxMemoView *>
        (
            Print_OpisForm -> frxRepOpis ->
                FindObject (
                    "Memo38"
                )
        );

    String s_tmp = "";

    for ( i = 0;
          i < col;
          ++i
        )
        s_tmp +=
            "\n"                                +
                IntToStr (i + 1)                +
            ". "                                +
                ListBox2 -> Items -> Strings[i];


    Memo38 -> Text = s_tmp;



    AnsiString
        cod_specializ,
        description,
        sp_full;

	if (    DM -> QAbituraTERM_EDU -> Value != StudyPeriodCode::HIGH_THIRD_COURSE
         //   DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::FULL
         //|| DM -> QAbituraTERM_EDU -> Value == StudyPeriodCode::HIGH_FIRST_COURSE
       )
    {
        sp_full     =
            DeleteAfterDatabaseChange::getNcrb2022CodeNameSportStrByNSpecializ (
                DM -> QReport_RaspN_SPECIALIZ -> Value
            );
        description =
            "Специальность (профилизация)";
    }
    else
    {
        description   =
            "Специальность (направление специальности, специализация)";
        cod_specializ =
            "1-88 02 01-01 ";

        switch (DM -> QReport_RaspN_SPECIALIZ -> Value)                         // специализация
        {
            case 4:
                    cod_specializ = "1-88 01 01-01 ";
                break;
            case 57:
                    cod_specializ = "1-88 01 01-02 ";
                break;
            case 38:
                    cod_specializ = "1-88 01 02-01 ";
                break;
            case 39:
                    cod_specializ = "1-88 01 02-02 ";
                break;
            case 3:
                    cod_specializ = "1-88 01 03-01 ";
                break;
            case 47:
                    cod_specializ = "1-88 01 03-02 ";
                break;
            case 48:
                    cod_specializ = "1-88 02 01-02 ";
                break;
            case 52:
                    cod_specializ = "1-88 02 01-03 ";
                break;
            case 56:
                    cod_specializ = "1-88 02 01-04 ";
                break;
            case 61:
                    cod_specializ = "1-89 01 01 ";
                break;
            case 100:
                    cod_specializ = "1-89 02 01-01 ";
                break;
            case 51:
                    cod_specializ = "1-89 02 01-02 ";
                break;
        }

        sp_full =
                cod_specializ                               +
            "«"                                             +
                DM -> vozvrat_spec (
                    DM -> QReport_RaspN_SPECIALIZ -> Value
                )                                           +
            "»";
    }

    TfrxMemoView * Memo35 =                                                     // <- THIS IS THE DIFFERENCE FROM SpeedButton3Click
        dynamic_cast <TfrxMemoView *>
        (
            Print_OpisForm -> frxRepOpis ->
                FindObject (
                    "Memo35"
                )
        );
    Memo35 -> Text = description;                                               // <- THIS IS THE DIFFERENCE FROM SpeedButton4Click

    TfrxMemoView * Memo37 =                                                     // <- THIS IS THE DIFFERENCE FROM SpeedButton3Click
        dynamic_cast <TfrxMemoView *>
        (
            Print_OpisForm -> frxRepOpis ->
                FindObject (
                    "Memo37"
                )
        );

    if (sp_full.Length () < 35)                                                 // <- THIS IS THE DIFFERENCE FROM SpeedButton3Click
        Memo37 -> Text = "";

    if (sp_full.Length () > 80)                                                 // <- THIS IS THE DIFFERENCE FROM SpeedButton3Click
        Memo37 -> Font -> Size = 10;

    Memo37 -> Text = sp_full;                                                   // <- THIS IS THE DIFFERENCE FROM SpeedButton3Click


    TfrxMemoView * Memo10 =                                                     // <- THIS IS THE DIFFERENCE FROM SpeedButton3Click
        dynamic_cast <TfrxMemoView *>
        (
            Print_OpisForm -> frxRepOpis ->
                FindObject (
                    "Memo10"
                )
        );

    Memo10 -> Text = Admissions::INVENTORY::DATE;

    Print_OpisForm -> frxRepOpis -> ShowReport ();                              // <- THIS IS THE DIFFERENCE FROM SpeedButton3Click


    if (Print_OpisForm)                                                         // <- THIS IS THE DIFFERENCE FROM SpeedButton3Click
        delete
            Print_OpisForm;


    for ( int j = col;
              j >= col - DM -> QSertificat -> RecordCount;
              --j
        )
        ListBox2 -> Items -> Delete (j);
}
void __fastcall TListDlgForm::StringSertificat ()
{
    Memo_number -> Visible = true;

    Memo_text_predm -> Text =
        getSubjectNameFromCode (
            DM -> QSertificat_ex_listRUS_BEL -> Value
        );

    MemoDATE_PRIEM -> Text =
        DateTimeToStr (
            SQLTimeStampToDateTime (
                DM -> QSertificat_ex_listDATE_PRIEM -> Value
            )
        );


    if (nom_fac != 4)
        MemoBALL -> Text =
            FloatToStrF (
                DM -> QSertificat_ex_listBALL -> Value,
                ffFixed,
                4,
                1
            );
    else
        if (DM -> QAbituraKONKURS -> Value == 3)
            MemoBALL -> Text =
                FloatToStrF (
                    DM -> QSertificat_ex_listBALL -> Value,
                    ffFixed,
                    4,
                    1
                );
        else
            MemoBALL -> Text =
                FloatToStrF (
                    DM -> QSertificat_ex_listBALL -> Value,
                    ffFixed,
                    3,
                    0
                );


    Memo_text_ball -> Text =
        scoresToWords (
            DM -> QSertificat_ex_listBALL -> Value,
            DM -> QAbituraKONKURS -> Value != 30                                // difference for Institute of Tourism and Hospitality (ITaH)
        );

    MemoFIO   -> Text    = FIO;
    PictureOb -> Visible = true;
}
