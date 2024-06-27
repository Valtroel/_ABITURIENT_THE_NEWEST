#pragma once
#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

#define USE_SYSTEM_DATE
#define ADD_SERTIFICATE_INSTEAD_COUNT_MIDDLE_BALL

//#define AUTO_SIGN_IN
//#define TEST_SRED_BAL_UNIT
//#define NEW_CHECKS
//#define REFACTORING
//#define TEST_EXAMEN_UNIT
//#define TEST_SPLASH_UNIT
//#define TEST_LIST_DLG
//#define TEST_MAIN_UNIT
//#define USE_OLD_IF_DOES_NOT_WORK_SRED_BAL_UNIT
//#define TARGETED_CONTRACT_ENROLLMENT
//#define TESTING_EXAMENN_SPEC_UNIT
//#define ENROLLMENT_PEOPLE_WITHOUT_CERTIFICATES
//#define DATABASE_SUBSTITUTE
//#define SHOW_EXAM_RESULTS_ONLY_FOR_ADMISSIONS_COMMITTEE
//#define SHOW_EXTRA_BUTTONS

#define NEW_EXAM_SUMMARY_LISTS

//#define DEEP_CHECK_PERSONAL_NUMBER                                            // WARNING: BE CAREFUL!!!! Works only for personal numbers until 2012.

//#define CHECK_SPECIALITY_OR_PROFILING

//#define DELETE_PREVIOUS_VERSION_OF_KOS


//#define SET_INVENTORY_DATE_BY_HAND                                              // IT'S FOR CHANGING CURRENT DATE TO OTHER INTO INVENTORY LIST AND (ListDlgUnit.cpp)


#include "enums.hpp"

//#define STATE_FROM_WORK_PC

#ifndef STATE_FROM_WORK_PC
    #ifndef NEW_INTEGRATION         // CHECKED!!!!                              EUGEN PC STATE ON 06.07.2023 21:18:52
        namespace Admissions
        {
            namespace TIME
            {
                const AnsiString
                    YEAR                 =
                        (Now ())
                            .FormatString (
                                "yyyy"
                            );
            }
            namespace INVENTORY
            {
                const AnsiString
                    #ifdef SET_INVENTORY_DATE_BY_HAND                                   // IT'S FOR CHANGING CURRENT DATE TO OTHER INTO INVENTORY LIST (ListDlgUnit.cpp)
                    DATE                 =
                        "18.07.2023";
                    #else
                    DATE                 =
                        (Now ())
                            .FormatString (
                                "dd.mm.yyyy"
                            );
                    #endif  // SET_INVENTORY_DATE_BY_HAND
            }
            namespace DEADLINE
            {
                const AnsiString
                    FOR_RECEIVING_PART_1 =
                        "05.06."                    +
                            Admissions::TIME::YEAR  +
                        " 6:00:00",
                    FOR_RECEIVING_PART_2 =
                        "10.08."                    +
                            Admissions::TIME::YEAR  +
                        " 6:00:00";
            }
            namespace ADDITIONAL
            {
                const AnsiString
                    ORDER_DATE_PART_1    =
                        "04.06."                    +
                            Admissions::TIME::YEAR,
                    ORDER_DATE_PART_2    =
                        "08.08."                    +
                            Admissions::TIME::YEAR;
            }
            namespace DOCUMENTS
            {
                const AnsiString
                    PROVIDE_DATE =
                        "15.06."                    +
                            Admissions::TIME::YEAR;
            }
            namespace ARRIVAL
            {
                namespace TIME
                {
                    const AnsiString
                        EVERYONE = "9:00";
                }
                namespace DATE
                {
                    namespace INTRAMURAL
                    {
                        const AnsiString
                            ALL =
                                "01.09."                                +
                                    Admissions::TIME::YEAR;
                    }
                    namespace EXTRAMURAL
                    {
                        namespace FULL
                        {
                            const AnsiString
                                MSTH_MNG     =
                                    "18.09."                            +
                                        Admissions::TIME::YEAR,
                                MSTH_TOURISM =
                                    "11.09."                            +
                                        Admissions::TIME::YEAR,
                                OTHER        =
                                    "18.09."                            +
                                        Admissions::TIME::YEAR;
                        }
                        namespace SECOND_COURSE
                        {
                            const AnsiString
                                SMA          =
                                    "08.01."                            +
                                        AnsiString (
                                            StrToInt (
                                                Admissions::TIME::YEAR
                                            )
                                            +   Default::STEP
                                        ),
                                MS           =
                                    "08.01."                            +
                                        AnsiString (
                                            StrToInt (
                                                Admissions::TIME::YEAR
                                            )
                                            +   Default::STEP
                                        ),
                                RPC          =
                                    "08.01."                            +
                                        AnsiString (
                                            StrToInt (
                                                Admissions::TIME::YEAR
                                            )
                                            +   Default::STEP
                                        ),
                                MSTH_MNG     =
                                    "08.01."                            +
                                        AnsiString (
                                            StrToInt (
                                                Admissions::TIME::YEAR
                                            )
                                            +   Default::STEP
                                        ),
                                MSTH_TOURISM =
                                    "30.10."                            +
                                        Admissions::TIME::YEAR;

                            namespace SKIING
                            {
                                const AnsiString
                                    SMA =
                                        "02.10."                        +
                                            Admissions::TIME::YEAR,
                                    MS  =
                                        "04.10."                        +
                                            Admissions::TIME::YEAR,
                                    RPC =
                                        "06.10."                        +
                                            Admissions::TIME::YEAR;
                            }
                        }
                        namespace THIRD_COURSE
                        {
                            const AnsiString
                                SMA          =
                                    "16.10."                            +
                                        Admissions::TIME::YEAR,
                                MS           =
                                    "16.10."                            +
                                        Admissions::TIME::YEAR,
                                RPC          =
                                    "16.10."                            +
                                        Admissions::TIME::YEAR,
                                MSTH_MNG     =
                                    "16.10."                            +
                                        Admissions::TIME::YEAR,
                                MSTH_TOURISM =
                                    "04.12."                            +
                                        Admissions::TIME::YEAR;
                        }
                    }
                }
            }
        }
        namespace ContestType
        {
            const AnsiString
                GENERAL                = "общий",
                WITHOUT_ENTRANCE_EXAMS = "без вступительных испытаний",
                OUT_OF_COMPETITION     = "вне конкурса",
                TARGETED_TRAINING      = "целевой";
        }
        namespace Contract
        {
            namespace DOCUMENT_FILE
            {
                const AnsiString
                    BUDGET  = "ДОГОВОР - Бюджет.xls",
                    BUYERS  = "ДОГОВОР - Платники.xls";
            }
            namespace DOCUMENT_NAME
            {
                const AnsiString
                    BUDGET = "ДОГОВОР - Бюджет",
                    BUYERS = "ДОГОВОР - Платники";
            }
            namespace BSUPC
            {
                const AnsiString
					PERSON = "Башлаковой Галины Ивановны";

                namespace BASE_DOCUMENT
                {
                    const AnsiString
                        NAME   = "доверенности",
                        DATE   = "16.11.2021",
                        NUMBER = "13-16-45";
                }
            }
            namespace IMS
            {
                const AnsiString
                    PERSON = "Михайловой Ольги Николаевны";

                namespace BASE_DOCUMENT
                {
                    const AnsiString
                        NAME   = "доверенности",
                        DATE   = "26.10.2021",
                        NUMBER = "13-16-42";
                }
            }
            namespace PAYMENT_TERM
            {
                const AnsiString
                    FIRST_SEMESTER  =
                        "до 01.09."                                 +
                            Admissions::TIME::YEAR                  +
                        " (включительно) – за первый "              \
                        "семестр первого года обучения в размере",
                    SECOND_SEMESTER =
                        "с 01.02."                                  +
                                AnsiString (
                                        StrToInt (
                                            Admissions::TIME::YEAR
                                        )
                                    +   Default::STEP
                                )                                   +
                        " до 01.03."                                +
                                AnsiString (
                                        StrToInt (
                                            Admissions::TIME::YEAR
                                        )
                                    +   Default::STEP
                                )                                   +
                        " – за второй семестр первого года "        \
                        "обучения в размере";
            }
            namespace COST_FOR
            {
                namespace BUDGET
                {
                    namespace INTRAMURAL
                    {
                        const AnsiString
                            FULL_COURSE   =                                             // БЮДЖЕТ, ДНЕВНОЕ, ПОЛНЫЙ СРОК
                                "заключения настоящего договора "               \
                                "составляет 45828,64 ("                         \
                                "сорок пять тысяч восемьсот двадцать восемь "   \
                                "рублей 64 копейки) белорусских рублей.",
                            SECOND_COURSE =                                             // БЮДЖЕТ, ДНЕВНОЕ, СОКРАЩЁННЫЙ СРОК (2 курс)
                                "заключения настоящего договора "               \
                                "составляет 34371,48 ("                         \
                                "тридцать четыре тысячи триста семьдесят один " \
                                "рубль 48 копеек) белорусских рублей.";
                    }
                    namespace EXTRAMURAL
                    {
                        const AnsiString
                            FULL_COURSE   =                                             // БЮДЖЕТ, ЗАОЧНОЕ, ПОЛНЫЙ СРОК
                                "заключения настоящего договора "               \
                                "составляет 22914,30 ("                         \
                                "двадцать две тысячи девятьсот четырнадцать "   \
                                "рублей 30 копеек) белорусских рублей.",
                            SECOND_COURSE =                                             // БЮДЖЕТ, ЗАОЧНОЕ, СОКРАЩЁННЫЙ СРОК (2 курс)
                                "заключения настоящего договора "               \
                                "составляет 18331,44 ("                         \
                                "восемнадцать тысяч триста тридцать один "      \
                                "рубль 44 копейки) белорусских рублей.",
                            THIRD_COURSE  =                                             // БЮДЖЕТ, ЗАОЧНОЕ, СОКРАЩЁННЫЙ СРОК (3 курс)
                                "заключения настоящего договора "               \
                                "составляет 13748,58 ("                         \
                                "тринадцать тысяч семьсот сорок восемь "        \
                                "рублей 58 копеек) белорусских рублей.";
                    }
                }
                namespace BUYERS
                {
                    namespace INTRAMURAL
                    {
                        const AnsiString                                                // ПЛАТНИКИ, ДНЕВНОЕ, ЗА ГОД
                            ANNUAL       =
                                "составляет 3233 ("                             \
                                "три тысячи двести тридцать три рубля"          \
                                ") белорусских рублей "                         \
                                "за первый год обучения.",
                            PER_SEMESTER =                                              // ПЛАТНИКИ, ДНЕВНОЕ, ПО СЕМЕСТРАМ
                                "1616,50 ("                                     \
                                "одна тысяча шестьсот шестнадцать "             \
                                "рублей 50 копеек) белорусских рублей;";
                    }
                    namespace EXTRAMURAL
                    {
                        const AnsiString
                            ANNUAL           =                                          // ПЛАТНИКИ, ЗАОЧНОЕ, ЗА ГОД (СИиЕ, МВС, ОФК)
                                "составляет 1251 ("                             \
                                "одна тысяча двести пятьдесят один"             \
                                ") белорусских рублей "                         \
                                "за первый год обучения.",
                            ANNUAL_IMS       =                                          // ПЛАТНИКИ, ЗАОЧНОЕ, ЗА ГОД (ИМСиТ)
                                "составляет 1335 ("                             \
                                "одна тысяча триста тридцать пять"              \
                                ") белорусских рублей "                         \
                                "за первый год обучения.",
                            PER_SEMESTER     =                                          // ПЛАТНИКИ, ЗАОЧНОЕ, ПО СЕМЕСТРАМ (СИиЕ, МВС, ОФК)
                                "625,50 ("                                      \
                                "шестьсот двадцать пять "                       \
                                "рублей 50 копеек) белорусских рублей;",
                            PER_SEMESTER_IMS =                                          // ПЛАТНИКИ, ЗАОЧНОЕ, ПО СЕМЕСТРАМ (ИМСиТ)
                                "667,50 ("                                      \
                                "шестьсот шестьдесят семь "                     \
                                "рублей 50 копеек) белорусских рублей;";
                    }
                }
            }
        }
        namespace DeaneryDB
        {
            namespace QUALIFICATION
            {
                const AnsiString
                    TEACHER_PHYSICAL_CULTURE_SPORTS  =
                        "Преподаватель физической культуры и спорта",
                    COACHING_BY_SPORT                =
                        "Тренер по виду спорта",
                    PHYSICAL_EDUCATION_TEACHER       =
                        "Учитель физической культуры",
                    TEACHER_ORGANIZER_HEALTH_TOURISM =
                        "Педагог-организатор физкультурно-оздоровительной "     \
                        "работы и туризма",
                    TEACHER_ORGANIZER_PRESCHOOLERS   =
                        "Педагог-организатор физического воспитания в "         \
                        "дошкольных учреждениях",
                    MANAGER_SPORT_TOURISM            =
                        "Менеджер спорта и туризма",
                    INSTRUCTOR_REHABILITATION        =
                        "Инструктор-методист физической реабилитации",
                    INSTRUCTOR_MEDICAL               =
                        "Инструктор-методист лечебной физической культуры",
                    TEACHER_PHYSICAL_CULTURE         =
                        "Преподаватель физической культуры",
                    INSTRUCTOR_BY_HEALTH             =
                        "Инструктор-методист по оздоровительной физической "    \
                        "культуре",
                    INSTRUCTOR_BY_ADAPTIVE           =
                        "Инструктор-методист по адаптивной физической "         \
                        "культуре",
                    INSTRUCTOR_PRESCHOOLERS          =
                        "Инструктор-методист физического воспитания в "         \
                        "дошкольных учреждениях",
                    PSYCHOLOGIST                     =
                        "Психолог",
                    MANAGER_SPORT                    =
                        "Менеджер в спорте",
                    MANAGER_TUORISM                  =
                        "Менеджер по туризму",
                    INSTRUCTOR_RECREATIONAL          =
                        "Инструктор-методист по туризму",
                    MANAGER_DIRECTING                =
                        "Менеджер-режиссер спортивно-массовых мероприятий",
                    INSTRUCTOR_BY_MEDICAL            =
                        "Инструктор-методист по лечебной физической культуре",
                    INSTRUCTOR_BY_REHABILITATION     =
                        "Инструктор-методист по физической реабилитации",
                    INSTRUCTOR_BY_ERGOTHERAPY        =
                        "Инструктор-методист по эрготерапии",
                    SPECIALIST_TOURISM_HOSPITALITY   =
                        "Специалист в сфере туризма и гостеприимства";
            }
        }
        namespace DocumentFile
        {
            namespace APPLICATION_FOR
            {
                const AnsiString
                    PARTICIPATION       = "ЗАЯВЛЕНИЕ - Допуск к участию.xls";
            }
            namespace LIST
            {
                const AnsiString
                    GROUPS              = "СПИСОК - Групп.xls";                         // NEW (СПИСОК.xls -> СПИСОК - групп.xls)
            }
            namespace PROTOCOL
            {
                AnsiString
                    admitted            = "ПРОТОКОЛ - О допуске абитуриентов.doc",      // NEW (OLE Issue) DELETE YEAR
                    daily               = "ПРОТОКОЛ - Ежедневный.xls",
                    exam                = "ПРОТОКОЛ - Экзамен по ФКиС.xls";
                const AnsiString
                    GIRLS_TESTS         = "ПРОТОКОЛ - Испытаний (Девушки).xls";
            }
            namespace REGISTRY
            {
                const AnsiString
                    BOOK                = "ЖУРНАЛ - Регистрация.xls";
            }
            namespace REPORT
            {
                const AnsiString
                    FORM_1              = "ОТЧЕТ - Форма 1.xls",                        // NEW (INDEX Issue MessageBox) DELETE YEAR
                    FORM_2              = "ОТЧЕТ - Форма 2.xls",                        // NEW (INDEX Issue MessageBox, REQUIRE CHECK Section I) DELETE YEAR
                    SUBMITTED           = "ОТЧЕТ - Подано заявлений.xls";
            }
            namespace STATISTIC
            {
                AnsiString
                    cert_result_hundred =
                        "СТАТИСТИКА - Результаты сертификатов (стобалльная).xls",
                    cert_result_ten     =
                        "СТАТИСТИКА - Результаты сертификатов (десятибалльная).xls",    // (REQUIRE CHECK Range)
                    exam_result         =
                        "СТАТИСТИКА - Результаты сдачи экзаменов.xls";
                const AnsiString
                    ADMISSION_PROGRESS  =
                        "СТАТИСТИКА - Ход приема.xls",
                    CONTEST             =
                        "СТАТИСТИКА - Конкурс.xls",                                     // NEW DELETE YEAR
                    DAILY               =
                        "СТАТИСТИКА - Ежедневная.xls",
                    LEVEL_OF_SPORTS     =
                        "СТАТИСТИКА - Уровень спортивной подготовки.xls",
                    SCORES              =
                        "СТАТИСТИКА - Баллы.xls";                                       // NOTE: INSTEAD USEING Abitur_RIO
            }
            namespace SUMMARY_LIST
            {
                const AnsiString
                    ENROLLMENT          = "ВЕДОМОСТЬ - Зачисление.xls",
                    ENTRANCE_EXAMS      = "ВЕДОМОСТЬ - Вступительных экзаменов.xls";    // NEW DELETE YEAR
            }
        }
        namespace DocumentName
        {
            namespace APPLICATION_FOR
            {
                const AnsiString
                    PARTICIPATION      = "ЗАЯВЛЕНИЕ - Допуск к участию";
            }
            namespace LIST
            {
                const AnsiString
                    GROUPS             = "СПИСОК - Групп",                              // NEW (СПИСОК -> СПИСОК - групп)
                    BY_DESTINATIONS    = "СПИСОК - По направлениям",
                    BY_GENDER          = "СПИСОК - По полу";
            }
            namespace PROTOCOL
            {
                AnsiString
                    daily              = "ПРОТОКОЛ - Ежедневный",
                    exam               = "ПРОТОКОЛ - Экзамен по ФКиС";
                const AnsiString
                    GIRLS_TESTS        = "ПРОТОКОЛ - Испытаний (Девушки)";
            }
            namespace REGISTRY
            {
                const AnsiString
                    BOOK               = "ЖУРНАЛ - Регистрация";
            }
            namespace REPORT
            {
                const AnsiString
                    FORM_1             = "ОТЧЕТ - Форма 1",
                    FORM_2             = "ОТЧЕТ - Форма 2",
                    SUBMITTED          = "ОТЧЕТ - Подано заявлений";                    // (REQUIRE CHECK Calcalation)
            }
            namespace STATISTIC
            {
                const AnsiString
                    ADMISSION_PROGRESS =
                        "СТАТИСТИКА - Ход приема",
                    CONTEST            =
                        "СТАТИСТИКА - Конкурс",
                    DAILY              =
                        "СТАТИСТИКА - Ежедневная",
                    LEVEL_OF_SPORTS    =
                        "СТАТИСТИКА - Уровень спортивной подготовки",
                    SCORES             =
                        "СТАТИСТИКА - Баллы";                                           // INSTEAD USEING Abitur_RIO
            }
            namespace SUMMARY_LIST
            {
                const AnsiString
                    ENROLLMENT         = "ВЕДОМОСТЬ - Зачисление",
                    ENTRANCE_EXAMS     = "ВЕДОМОСТЬ - Вступительных экзаменов";
            }
        }
        namespace EducationType
        {
            const AnsiString
                EXTRAMURAL = "заочное",
                INTRAMURAL = "дневное",
                EXTRA_FORM = "заочной",
                INTRA_FORM = "дневной";
        }
        namespace EnvelopeMessage
        {
            namespace BUDGET
            {
                const AnsiString
                    EXTRAMURAL = "бюджет, заочная форма обучения",
                    INTRAMURAL = "бюджет, дневная форма обучения";
            }
            namespace BUYERS
            {
                const AnsiString
                    EXTRAMURAL = "за оплату, заочная форма обучения",
                    INTRAMURAL = "за оплату, дневная форма обучения";
            }
        }
        namespace Faculty
        {
            const AnsiString
                SMA  = "СИиЕ",                                                          // 1, -> Sports and Marital Arts (СИиЕ)
                MS   = "МВС",                                                           // 2, -> Mass Sports (МВС)
                RPC  = "ОФК",                                                           // 3, -> Recreational Physical Culture (ОФКиТ)
                MSTH = "МСТиГ",                                                         // 4, -> Management of Sports, Tourism and Hospitality (МСиТ)
                MD   = "Магстратура",                                                   // 5, -> Master's Degree (Магстратура)
                PGS  = "Аспирантура",                                                   // 6, -> PostGraduate Studies (Аспирантура)
                DOC  = "Докторантура";                                                  // 7  -> DOCtorate (Докторантура)
        }
        namespace LegallyAuthorizedPerson
        {
            AnsiString
                edu_head_desc  = "Ермакову А.А.";
            const AnsiString
                DEAN_FACULTY_1 = "В.И.Новицкая",                                        // СИиЕ  (SMA)  - Sports and Marital Arts
                DEAN_FACULTY_2 = "И.И.Гуслистова",                                      // МВС   (MS)   - Mass Sports
                DEAN_FACULTY_3 = "Н.М.Машарская",                                       // ОФКиТ (RPC)  - Recreational Physical Culture
                DEAN_FACULTY_4 = "О.Н.Михайлова",                                       // МСиТ  (MSTH) - Management of Sports, Tourism and Hospitality
                SECRETARY      = "А.И. Лихач",
                SECRETARY_DESC = "Лихач А.И.",
                VICE_RECTOR    = "Г.И.Башлакова";
        }
        namespace NCRB_011                                                                  // National Classifier of the Republic of Belarus
        {
            namespace _2009
            {
                namespace CODE
                {
                    namespace PART
                    {
                        const AnsiString
                            BIOLOGICAL_SCIENCES            = "03.00.00",                // Master degree
                            PEDAGOGICAL_SCIENCES           = "13.00.00",                // Master degree
                            PEDAGOGY_PROFESSIONAL          = "1-08",                    // Master degree
                            COMMUNICATION_SCIENCES         = "1-26",                    // Master degree
                            PHYSICAL_CULTURE_AND_SPORT     = "1-88",
                            TOURISM_HOSPITALITY            = "1-89";
                    }
                    namespace CHAPTER
                    {
                        const AnsiString
                            PHYSIOLOGY                     = "03.03.01",                // Master degree
                            THEORY_IMPROVING               = "13.00.04",                // Master degree
                            RESEARCH_AND_DEVELOPMENT       = "1-08 80",                 // Master degree
                            MANAGEMENT                     = "1-26 80",                 // Master degree
                            PHYSICAL_CULTURE               = "1-88 01",
                            SPORT                          = "1-88 02",
                            TOURISM_HOSPITALITY            = "1-89 01",
                            TOURISM                        = "1-89 02",
                            HOSPITALITY                    = "1-89 03",
                            RESEARCH_AND_TEACHING          = "1-89 80",                 // Master degree
                            INNOVATION                     = "1-89 81";                 // Master degree
                    }
                    namespace SECTION
                    {
                        const AnsiString
                            RESEARCH_SPORT                 = "1-08 80 04",              // Master degree
                            RESEARCH_MANAGEMENT            = "1-26 80 04",              // Master degree
                            PHYSICAL_CULTURE               = "1-88 01 01",
                            IMPROVING_AND_ADAPTIVE         = "1-88 01 02",
                            REHABILITATION_ERGOTHERAPY     = "1-88 01 03",
                            TRAINING_MILITARY_PERSONNEL    = "1-88 01 04",
                            SPORTS_AND_PEDAGOGY            = "1-88 02 01",
                            SPORTS_CHOREOGRAPHY            = "1-88 02 72",
                            TOURISM_HOSPITALITY            = "1-89 01 01",
                            SPORTS_AND_TOURISM             = "1-89 02 01",
                            TOURISM_AND_NATURE_MANAGEMENT  = "1-89 02 02",
                            HOSPITALITY_TECHNOLOGIES       = "1-89 03 01",
                            RESEARCH_TOURISM_HOSPITALITY   = "1-89 80 01",              // Master degree
                            INNOVATION_MANAGEMENT          = "1-89 81 01",              // Master degree
                            INNOVATION_TOURISM             = "1-89 81 02",              // Master degree
                            INNOVATION_HOSPITALITY         = "1-89 81 03",              // Master degree
                            INNOVATION_TECHNOLOGY          = "1-89 81 04";              // Master degree
                    }
                    namespace SUBSECTION
                    {
                        const AnsiString
                            MEDICAL                       = "1-88 01 01-01",
                            PRESCHOOLERS                  = "1-88 01 01-02",
                            HEALTH                        = "1-88 01 02-01",
                            ADAPTIVE                      = "1-88 01 02-02",
                            REHABILITATION                = "1-88 01 03-01",
                            ERGOTHERAPY                   = "1-88 01 03-02",
                            COACHING                      = "1-88 02 01-01",
                            MANAGEMENT                    = "1-88 02 01-02",
                            PSYCHOLOGY                    = "1-88 02 01-03",
                            DIRECTING                     = "1-88 02 01-04",
                            PROMOTION                     = "1-89 01 01 01",
                            IT                            = "1-89 01 01 02",
                            LOGISTICS                     = "1-89 01 01 03",
                            SOCIAL                        = "1-89 01 01 04",
                            TRANSPORT                     = "1-89 01 01 05",
                            CATERING                      = "1-89 01 01 06",
                            ACCOMMODATION                 = "1-89 01 01 07",
                            SUPPORTING                    = "1-89 01 01 08",
                            TREATMENT                     = "1-89 01 01 09",
                            RECREATIONAL                  = "1-89 02 01-01",
                            TUORISM_MNG                   = "1-89 02 01-02",
                            RESTAURANTS                   = "1-89 03 01-01";
                    }
                    namespace MASTER_DEGREE
                    {
                        namespace SCIENCE
                        {
                            const AnsiString
                                PHYSIOLOGY  = "03.03.01",
                                THEORY      = "13.00.04";
                        }
                        namespace RESEARCH
                        {
                            const AnsiString
                                SPORT       = "1-08 80 04",
                                MANAGEMENT  = "1-26 80 04",
                                TOURISM     = "1-89 80 01";
                        }
                        namespace INNOVATION
                        {
                            const AnsiString
                                MANAGEMENT  = "1-89 81 01",
                                TOURISM     = "1-89 81 02",
                                HOSPITALITY = "1-89 81 03",
                                TECHNO      = "1-89 81 04";
                        }
                    }
                    namespace PHYSICAL_CULTURE
                    {
                        const AnsiString
                            MEDICAL      = "1-88 01 01-01",
                            PRESCHOOLERS = "1-88 01 01-02";
                    }
                    namespace IMPROVING
                    {
                        const AnsiString
                            HEALTH   = "1-88 01 02-01",
                            ADAPTIVE = "1-88 01 02-02";
                    }
                    namespace REHABILITATION
                    {
                        const AnsiString
                            REHABILITATION = "1-88 01 03-01",
                            ERGOTHERAPY    = "1-88 01 03-02";
                    }
                    namespace MILITARY
                    {
                        const AnsiString
                            TRAINING = "1-88 01 04";
                    }
                    namespace SPORT
                    {
                        const AnsiString
                            COACHING   = "1-88 02 01-01",
                            MANAGEMENT = "1-88 02 01-02",
                            PSYCHOLOGY = "1-88 02 01-03",
                            DIRECTING  = "1-88 02 01-04";
                    }
                    namespace TOURISM_HOSPITALITY
                    {
                        const AnsiString
                            PROMOTION     = "1-89 01 01 01",
                            IT            = "1-89 01 01 02",
                            LOGISTICS     = "1-89 01 01 03",
                            SOCIAL        = "1-89 01 01 04",
                            TRANSPORT     = "1-89 01 01 05",
                            CATERING      = "1-89 01 01 06",
                            ACCOMMODATION = "1-89 01 01 07",
                            SUPPORTING    = "1-89 01 01 08",
                            TREATMENT     = "1-89 01 01 09";
                    }
                    namespace TOURISM
                    {
                        const AnsiString
                            RECREATIONAL = "1-89 02 01-01",
                            TUORISM_MNG  = "1-89 02 01-02";
                    }
                    namespace HOSPITALITY
                    {
                        const AnsiString
                            RESTAURANTS = "1-89 03 01-01";
                    }
                }
                namespace NAME
                {
                    namespace PART
                    {
                        const AnsiString
                            BIOLOGICAL_SCIENCES        =                                // Master degree
                                "Биологические науки",
                            PEDAGOGICAL_SCIENCES       =                                // Master degree
                                "Педагогические науки",
                            PEDAGOGY_PROFESSIONAL      =                                // Master degree
                                "Педагогика. Профессиональное образование",
                            COMMUNICATION_SCIENCES     =                                // Master degree
                                "Управление",
                            PHYSICAL_CULTURE_AND_SPORT =
                                "Физическая культура и спорт",
                            TOURISM_HOSPITALITY        =
                                "Туризм. Гостеприимство";
                    }
                    namespace CHAPTER
                    {
                        const AnsiString
                            PHYSIOLOGY               =                                  // Master degree
                                "Физиология",
                            THEORY_IMPROVING         =                                  // Master degree
                                "Теория и методика физического воспитания, "        \
                                "спортивной тренировки, оздоровительной и "         \
                                "адаптивной физической культуры",
                            RESEARCH_AND_DEVELOPMENT =                                  // Master degree
                                "Научные исследования и разработки, преподавание",
                            PHYSICAL_CULTURE         =
                                "Физическая культура",
                            SPORT                    =
                                "Спорт",
                            TOURISM_HOSPITALITY      =
                                "Туризм и гостеприимство",
                            TOURISM                  =
                                "Туризм",
                            HOSPITALITY              =
                                "Гостеприимство",
                            RESEARCH_AND_TEACHING    =                                  // Master degree
                                "Научные исследования и разработки, преподавание",
                            INNOVATION                     =                            // Master degree
                                "Инновационная деятельность (с углубленной "        \
                                "подготовкой специалистов)";
                    }
                    namespace SECTION
                    {
                        const AnsiString
                            RESEARCH_SPORT                 =                            // Master degree
                                "Физическая культура и спорт",
                            PHYSICAL_CULTURE              =
                                "Физическая культура (по направлениям)",
                            IMPROVING_AND_ADAPTIVE        =
                                "Оздоровительная и адаптивная физическая культура " \
                                "(по направлениям)",
                            REHABILITATION_ERGOTHERAPY    =
                                "Физическая реабилитация и эрготерапия "            \
                                "(по направлениям)",
                            TRAINING_MILITARY_PERSONNEL   =
                                "Физическая подготовка военнослужащих",
                            SPORTS_AND_PEDAGOGY           =
                                "Спортивно-педагогическая деятельность",
                            SPORTS_CHOREOGRAPHY           =
                                "Спортивная хореография",
                            TOURISM_HOSPITALITY       =
                                "Туризм и гостеприимство",
                            SPORTS_AND_TOURISM            =
                                "Спортивно-туристская деятельность "                \
                                "(по направлениям)",
                            TOURISM_AND_NATURE_MANAGEMENT =
                                "Туризм и природопользование",
                            HOSPITALITY_TECHNOLOGIES      =
                                "Технология индустрии гостеприимства "              \
                                "(по направлениям)",
                            TOURISM_HOSPITALITY_STUDY =
                                "Туризм и гостеприимство",
                            RESEARCH_TOURISM_HOSPITALITY   =                            // Master degree
                                "Туризм и гостеприимство",
                            INNOVATION_MANAGEMENT          =                            // Master degree
                                "Управление инновационными проектами в "            \
                                "туристской индустрии",
                            INNOVATION_TOURISM             =                            // Master degree
                                "Инновационный менеджмент в сфере туризма",
                            INNOVATION_HOSPITALITY         =                            // Master degree
                                "Инновационный менеджмент в сфере гостеприимства",
                            INNOVATION_TECHNOLOGY          =                            // Master degree
                                "Инновационные технологии в сфере туризма и "       \
                                "гостеприимства";
                    }
                    namespace SUBSECTION
                    {
                        const AnsiString
                            MEDICAL        =
                                "Физическая культура (лечебная)",
                            PRESCHOOLERS   =
                                "Физическая культура (дошкольников)",
                            HEALTH         =
                                "Оздоровительная и адаптивная физическая культура " \
                                "(оздоровительная)",
                            ADAPTIVE       =
                                "Оздоровительная и адаптивная физическая культура " \
                                "(адаптивная)",
                            REHABILITATION =
                                "Физическая реабилитация и эрготерапия "            \
                                "(физическая реабилитация)",
                            ERGOTHERAPY    =
                                "Физическая реабилитация и эрготерапия "            \
                                "(эрготерапия)",
                            COACHING       =
                                "Спортивно-педагогическая деятельность "            \
                                "(тренерская работа с указанием вида спорта)",
                            MANAGEMENT     =
                                "Спортивно-педагогическая деятельность "            \
                                "(менеджмент в спорте)",
                            PSYCHOLOGY     =
                                "Спортивно-педагогическая деятельность "            \
                                "(спортивная психология)",
                            DIRECTING      =
                                "Спортивно-педагогическая деятельность "            \
                                "(спортивная режиссура)",
                            PROMOTION      =
                                "Технологии формирования и продвижения "            \
                                "туристических услуг",
                            IT             =
                                "Информационные технологии туристической "          \
                                "индустрии",
                            LOGISTICS      =
                                "Логистика в туристической индустрии",
                            SOCIAL         =
                                "Технологии социокультурного сервиса туристов",
                            TRANSPORT      =
                                "Технологии транспортного сервиса туристов",
                            CATERING       =
                                "Технологии сервиса питания туристов",
                            ACCOMMODATION  =
                                "Технологии сервиса размещения туристов",
                            SUPPORTING     =
                                "Технологии экскурсионно-сопроводительного "        \
                                "сервиса туристов",
                            TREATMENT      =
                                "Технологии сервиса оздоровления и лечения "        \
                                "туристов",
                            RECREATIONAL   =
                                "Спортивно-туристская деятельность "                \
                                "(спортивный и рекреационный туризм)",
                            TUORISM_MNG    =
                                "Спортивно-туристская деятельность "                \
                                "(менеджмент в туризме)",
                            RESTAURANTS    =
                                "Технология индустрии гостеприимства "              \
                                "(ресторанная деятельность)";
                    }
                    namespace MASTER_DEGREE
                    {
                        namespace SCIENCE
                        {
                            const AnsiString
                                PHYSIOLOGY  =
                                    "Физиология",
                                THEORY      =
                                    "Теория и методика физического воспитания, "    \
                                    "спортивной тренировки, оздоровительной и "     \
                                    "адаптивной физической культуры";
                        }
                        namespace RESEARCH
                        {
                            const AnsiString
                                SPORT       =
                                    "Физическая культура и спорт",
                                MANAGEMENT  =
                                    "Менеджмент",
                                TOURISM     =
                                    "Туризм и гостеприимство";
                        }
                        namespace INNOVATION
                        {
                            const AnsiString
                                MANAGEMENT  =
                                    "Управление инновационными проектами в "        \
                                    "туристской индустрии",
                                TOURISM     =
                                    "Инновационный менеджмент в сфере туризма",
                                HOSPITALITY =
                                    "Инновационный менеджмент в сфере "             \
                                    "гостеприимства",
                                TECHNO  =
                                    "Инновационные технологии в сфере туризма и "   \
                                    "гостеприимства";
                        }
                    }
                    namespace PHYSICAL_CULTURE
                    {
                        const AnsiString
                            MEDICAL        = "Физическая культура (лечебная)",
                            PRESCHOOLERS   = "Физическая культура (дошкольников)";
                    }
                    namespace IMPROVING
                    {
                        const AnsiString
                            HEALTH         =
                                "Оздоровительная и адаптивная физическая культура " \
                                "(оздоровительная)",
                            ADAPTIVE       =
                                "Оздоровительная и адаптивная физическая культура " \
                                "(адаптивная)";
                    }
                    namespace REHABILITATION
                    {
                        const AnsiString
                            REHABILITATION =
                                "Физическая реабилитация и эрготерапия "            \
                                "(физическая реабилитация)",
                            ERGOTHERAPY    =
                                "Физическая реабилитация и эрготерапия "            \
                                "(эрготерапия)";
                    }
                    namespace MILITARY
                    {
                        const AnsiString
                            TRAINING       = "Физическая подготовка военнослужащих";
                    }
                    namespace SPORT
                    {
                        const AnsiString
                            COACHING       =
                                "Спортивно-педагогическая деятельность "            \
                                "(тренерская работа с указанием вида спорта)",
                            MANAGEMENT     =
                                "Спортивно-педагогическая деятельность "            \
                                "(менеджмент в спорте)",
                            PSYCHOLOGY     =
                                "Спортивно-педагогическая деятельность "            \
                                "(спортивная психология)",
                            DIRECTING      =
                                "Спортивно-педагогическая деятельность "            \
                                "(спортивная режиссура)";
                    }
                    namespace TOURISM_HOSPITALITY
                    {
                        const AnsiString
                            PROMOTION      =
                                "Технологии формирования и продвижения "            \
                                "туристических услуг",
                            IT             =
                                "Информационные технологии туристической индустрии",
                            LOGISTICS      =
                                "Логистика в туристической индустрии",
                            SOCIAL         =
                                "Технологии социокультурного сервиса туристов",
                            TRANSPORT      =
                                "Технологии транспортного сервиса туристов",
                            CATERING       =
                                "Технологии сервиса питания туристов",
                            ACCOMMODATION  =
                                "Технологии сервиса размещения туристов",
                            SUPPORTING     =
                                "Технологии экскурсионно-сопроводительного "        \
                                "сервиса туристов",
                            TREATMENT      =
                                "Технологии сервиса оздоровления и лечения "        \
                                "туристов";
                    }
                    namespace TOURISM
                    {
                        const AnsiString
                            RECREATIONAL   =
                                "Спортивно-туристская деятельность "                \
                                "(спортивный и рекреационный туризм)",
                            TUORISM_MNG    =
                                "Спортивно-туристская деятельность "                \
                                "(менеджмент в туризме)";
                    }
                    namespace HOSPITALITY
                    {
                        const AnsiString
                            RESTAURANTS    =
                                "Технология индустрии гостеприимства "              \
                                "(ресторанная деятельность)";
                    }
                }
                namespace QUALIFICATION
                {
                    namespace SUBSECTION
                    {
                        const AnsiString
                            MEDICAL        =
                                "Инструктор-методист по лечебной физической "       \
                                "культуре. Преподаватель физической культуры",
                            PRESCHOOLERS   =
                                "Инструктор-методист физического воспитания в "     \
                                "дошкольных учреждениях. "                          \
                                "Преподаватель физической культуры",
                            HEALTH         =
                                "Инструктор-методист по оздоровительной "           \
                                "физической культуре. "                             \
                                "Преподаватель физической культуры",
                            ADAPTIVE       =
                                "Инструктор-методист по адаптивной "                \
                                "физической культуре. "                             \
                                "Преподаватель физической культуры",
                            REHABILITATION =
                                "Инструктор-методист по физической "                \
                                "реабилитации. "                                    \
                                "Преподаватель физической культуры",
                            ERGOTHERAPY    =
                                "Инструктор-методист по эрготерапии. "              \
                                "Преподаватель физической культуры",
                            TRAINING       =
                                "Специалист по управлению. "                        \
                                "Инструктор-методист по физической "                \
                                "подготовке",
                            COACHING       =
                                "Тренер (по виду спорта). "                         \
                                "Преподаватель физической культуры",
                            MANAGEMENT     =
                                "Менеджер в спорте. "                               \
                                "Преподаватель физической культуры",
                            PSYCHOLOGY     =
                                "Психолог. "                                        \
                                "Преподаватель физической культуры",
                            DIRECTING      =
                                "Менеджер-режиссер спортивно-массовых "             \
                                "мероприятий."                                      \
                                "Преподаватель физической культуры",
                            PROMOTION      =
                                "Специалист в сфере туризма и гостеприимства",
                            IT             =
                                "Специалист в сфере туризма и гостеприимства",
                            LOGISTICS      =
                                "Специалист в сфере туризма и гостеприимства",
                            SOCIAL         =
                                "Специалист в сфере туризма и гостеприимства",
                            TRANSPORT      =
                                "Специалист в сфере туризма и гостеприимства",
                            CATERING       =
                                "Специалист в сфере туризма и гостеприимства",
                            ACCOMMODATION  =
                                "Специалист в сфере туризма и гостеприимства",
                            SUPPORTING     =
                                "Специалист в сфере туризма и гостеприимства",
                            TREATMENT      =
                                "Специалист в сфере туризма и гостеприимства",
                            RECREATIONAL   =
                                "Инструктор-методист по туризму. "                  \
                                "Преподаватель физической культуры",
                            TUORISM_MNG    =
                                "Менеджер по туризму. "                             \
                                "Преподаватель физической культуры",
                            RESTAURANTS    = "Менеджер. Технолог";
                    }
                    namespace MASTER_DEGREE
                    {
                        namespace SCIENCE
                        {
                            const AnsiString
                                PHYSIOLOGY  = "Магистр",
                                THEORY      = "Магистр";
                        }
                        namespace RESEARCH
                        {
                            const AnsiString
                                SPORT       = "Магистр",
                                MANAGEMENT  = "Магистр",
                                TOURISM     = "Магистр";
                        }
                        namespace INNOVATION
                        {
                            const AnsiString
                                MANAGEMENT  = "Магистр",
                                TOURISM     = "Магистр",
                                HOSPITALITY = "Магистр",
                                TECHNO      = "Магистр";
                        }
                    }
                    namespace PHYSICAL_CULTURE
                    {
                        const AnsiString
                            MEDICAL        =
                                "Инструктор-методист по лечебной физической "       \
                                "культуре. Преподаватель физической культуры",
                            PRESCHOOLERS   =
                                "Инструктор-методист физического воспитания в "     \
                                "дошкольных учреждениях. "                          \
                                "Преподаватель физической культуры";
                    }
                    namespace IMPROVING
                    {
                        const AnsiString
                            HEALTH         =
                                "Инструктор-методист по оздоровительной "           \
                                "физической культуре. "                             \
                                "Преподаватель физической культуры",
                            ADAPTIVE       =
                                "Инструктор-методист по адаптивной "                \
                                "физической культуре. "                             \
                                "Преподаватель физической культуры";
                    }
                    namespace REHABILITATION
                    {
                        const AnsiString
                            REHABILITATION =
                                "Инструктор-методист по физической "                \
                                "реабилитации. "                                    \
                                "Преподаватель физической культуры",
                            ERGOTHERAPY    =
                                "Инструктор-методист по эрготерапии. "              \
                                "Преподаватель физической культуры";
                    }
                    namespace MILITARY
                    {
                        const AnsiString
                            TRAINING       =
                                "Специалист по управлению. "                        \
                                "Инструктор-методист по физической "                \
                                "подготовке";
                    }
                    namespace SPORT
                    {
                        const AnsiString
                            COACHING       =
                                "Тренер (по виду спорта). "                         \
                                "Преподаватель физической культуры",
                            MANAGEMENT     =
                                "Менеджер в спорте. "                               \
                                "Преподаватель физической культуры",
                            PSYCHOLOGY     =
                                "Психолог. "                                        \
                                "Преподаватель физической культуры",
                            DIRECTING      =
                                "Менеджер-режиссер спортивно-массовых "             \
                                "мероприятий."                                      \
                                "Преподаватель физической культуры";
                    }
                    namespace TOURISM_HOSPITALITY
                    {
                        const AnsiString
                            PROMOTION      =
                                "Специалист в сфере туризма и гостеприимства",
                            IT             =
                                "Специалист в сфере туризма и гостеприимства",
                            LOGISTICS      =
                                "Специалист в сфере туризма и гостеприимства",
                            SOCIAL         =
                                "Специалист в сфере туризма и гостеприимства",
                            TRANSPORT      =
                                "Специалист в сфере туризма и гостеприимства",
                            CATERING       =
                                "Специалист в сфере туризма и гостеприимства",
                            ACCOMMODATION  =
                                "Специалист в сфере туризма и гостеприимства",
                            SUPPORTING     =
                                "Специалист в сфере туризма и гостеприимства",
                            TREATMENT      =
                                "Специалист в сфере туризма и гостеприимства";
                    }
                    namespace TOURISM
                    {
                        const AnsiString
                            RECREATIONAL   =
                                "Инструктор-методист по туризму. "                  \
                                "Преподаватель физической культуры",
                            TUORISM_MNG    =
                                "Менеджер по туризму. "                             \
                                "Преподаватель физической культуры";
                    }
                    namespace HOSPITALITY
                    {
                        const AnsiString
                            RESTAURANTS    = "Менеджер. Технолог";
                    }
                }
            }
            namespace _2022
            {
                namespace CODE
                {
                    const AnsiString
                        PHYSIOLOGY       = "03.03.01",                                  // Master degree
                        THEORY_IMPROVING = "13.00.04",                                  // Master degree
                        INNO_MANAGEMENT  = "1-89 81 01",                                // Master degree
                        INNO_TOURISM     = "1-89 81 02",                                // Master degree
                        INNO_HOSPITALITY = "1-89 81 03",                                // Master degree
                        INNO_TECHNOLOGY  = "1-89 81 04",                                // Master degree
                        PHYSICAL_CULTURE = "6-05-1012-01",
                        COACHING         = "6-05-1012-02",
                        REHABILITATION   = "6-05-1012-03",
                        MANAGEMENT       = "6-05-1012-04",
                        TOURISM          = "6-05-1013-01",
                        NATURE           = "6-05-1013-03",
                        HOSPITALITY      = "6-05-1013-04",
                        MNG_MASTER_DEGREE = "7-06-0412-01",
                        PC_MASTER_DEGREE = "7-06-1012-01",                              // Master degree
                        TH_MASTER_DEGREE = "7-06-1013-01",                              // Master degree
                        CHOREOGRAPHY     = "9-09-1012-04";                              // Master degree
                }
                namespace NAME
                {
                    const AnsiString
                        PHYSIOLOGY       =                                              // Master degree
                            "Физиология",
                        THEORY_IMPROVING =                                              // Master degree
                            "Теория и методика физического воспитания, "        \
                            "спортивной тренировки, оздоровительной и "         \
                            "адаптивной физической культуры",
                        INNO_MANAGEMENT  =                                              // Master degree
                            "Управление инновационными проектами в "            \
                            "туристской индустрии",
                        INNO_TOURISM     =                                              // Master degree
                            "Инновационный менеджмент в сфере туризма",
                        INNO_HOSPITALITY =                                              // Master degree
                            "Инновационный менеджмент в сфере гостеприимства",
                        INNO_TECHNOLOGY  =                                              // Master degree
                            "Инновационные технологии в сфере туризма и "       \
                            "гостеприимства",
                        PHYSICAL_CULTURE =
                            "Физическая культура",
                        COACHING         =
                            "Тренерская деятельность",
                        REHABILITATION   =
                            "Физическая реабилитация и эрготерапия",
                        MANAGEMENT       =
                            "Организация и управление физической культурой, "   \
                            "спортом и туризмом",
                        TOURISM          =
                            "Туризм и гостеприимство",
                        NATURE           =
                            "Туризм и природопользование",
                        HOSPITALITY      =
                            "Технология индустрии гостеприимства",
                        PC_MASTER_DEGREE =                                              // Master degree
                            "Физическая культура и спорт",
                        TH_MASTER_DEGREE =                                              // Master degree
                            "Туризм и гостеприимство",
                        CHOREOGRAPHY     =
                            "Спортивная хореография";

                    namespace PHYSICAL
                    {
                        const AnsiString
                            IMPROVING      = "(оздоровительная)",                       // "(оздоровительная физическая культура)",
                            HEALTH         = "(лечебная)",                              // "(лечебная физическая культура)",
                            PRESCHOOLERS   = "(дошкольников)",                          // "(физическая культура дошкольников)",
                            ADAPTIVE       = "(адаптивная)",                            // "(адаптивная физическая культура)",
                            DIRECTING      = "(спортивная режиссура)",
                            PSYCHOLOGY     = "(спортивная психология)",
                            RECREATIONAL   = "(спортивный и рекреационный туризм)";
                    }
                    namespace COACH
                    {
                        const AnsiString
                            DEFAULT        = "(с указанием вида спорта)";
                    }
                    namespace REHABILITATE
                    {
                        const AnsiString
                            REHABILITATION = "(физическая реабилитация)",
                            ERGOTHERAPY    = "(эрготерапия)";
                    }
                    namespace MANAGE
                    {
                        const AnsiString
                            SPORT          = "(менеджмент в спорте)",
                            TOURISM        = "(менеджмент в туризме)";
                    }
                }
                namespace QUALIFICATION
                {
                    const AnsiString
                        PHYSIOLOGY       = "Магистр",                                   // Master degree
                        THEORY_IMPROVING = "Магистр",                                   // Master degree
                        INNO_MANAGEMENT  = "Магистр управления",                        // Master degree
                        INNO_TOURISM     = "Магистр туризма",                           // Master degree
                        INNO_HOSPITALITY = "Магистр гостеприимства",                    // Master degree
                        INNO_TECHNOLOGY  = "Магистр инноваций",                         // Master degree
                        PHYSICAL_CULTURE = "Инструктор-методист. Преподаватель",
                        COACHING         = "Тренер. Преподаватель",
                        REHABILITATION   = "Инструктор-методист. Преподаватель",
                        MANAGEMENT       = "Менеджер. Преподаватель",
                        TOURISM          = "Специалист",
                        NATURE           = "Специалист по туризму и природопользованию",
                        HOSPITALITY      = "Менеджер. Технолог",
                        PC_MASTER_DEGREE = "Магистр",                                   // Master degree
                        TH_MASTER_DEGREE = "Магистр",                                   // Master degree
                        CHOREOGRAPHY     = "Инструктор-методист";
                }
            }
        }
        namespace PathTo
        {
            const AnsiString
                OUTPUT_DOCUMENTS       = "D:\\Документы приемной комиссии",
                OUTPUT_DOCUMENTS_SLASH = "D:\\Документы приемной комиссии\\";
        }
        namespace Payment
        {
            const AnsiString
                BUDGET = "бюджет",
                BUYERS = "платное";
        }
        namespace KindOfSport
        {
            const AnsiString
                GYMNASTICS                   =
                    "Гимнастика",
                MANAGEMENT_SPORTS_TOURISM    =
                    "Менеджмент спорта и туризма",
                PHYSICAL_REHABILITATION      =
                    "Физическая реабилитация",
                THERAPEUTIC                  =
                    "Лечебная физическая культура",
                ORGANIZATION_SPORTS_TOURISM  =
                    "Организация физкультурно-оздоровительной "         \
                    "работы и туризма",
                PRESCHOOL_PHYSICAL_EDUCATION =
                    "Дошкольное физическое воспитание",
                DANCE_SPORT                  =
                    "Танцевальный спорт",
                AEROBICS                     =
                    "Аэробика",
                ROWING_OTHER                 =
                    "Гребной спорт",
                SWIMMING                     =
                    "Плавание",
                SAILING                      =
                    "Парусный спорт",
                ATHLETICS                    =
                    "Легкая атлетика",
                CROSS_COUNTRY_SKIING         =
                    "Лыжные гонки",
                BULLET_SHOOTING_DEANERY      =
                    "Пулевая стрельба",
                HAND_TO_HAND_COMBAT          =
                    "Рукопашный бой",
                TAEKWONDO                    =
                    "Таэквондо",
                KARATE                       =
                    "Каратэ",
                SKIING                       =
                    "Лыжный спорт",
                AUTOMOTIVE_SPORT             =
                    "Автомобильный спорт",
                BASKETBALL                   =
                    "Баскетбол",
                BOXING                       =
                    "Бокс",
                GRECO_FREESTYLE_WRESTLING    =
                    "Греко-римская и вольная борьба",
                CYCLING                      =
                    "Велосипедный спорт",
                VOLLEYBALL                   =
                    "Волейбол",
                HANDBALL                     =
                    "Гандбол",
                EQUESTRIAN                   =
                    "Конный спорт",
                SPEED_SKATING                =
                    "Конькобежный спорт",
                TENNIS                       =
                    "Теннис",
                WEIGHTLIFTING                =
                    "Тяжелая атлетика",
                FENCING                      =
                    "Фехтование",
                FIGURE_SKATING_OLD           =
                    "Фигурное катание",
                FOOTBALL                     =
                    "Футбол",
                HOCKEY                       =
                    "Хоккей",
                SAMBO_JUDO                   =
                    "Самбо-дзюдо",
                WRESTLING                    =
                    "Спортивная борьба",
                FOOTBALL_HOCKEY              =
                    "Футбол и хоккей",
                BIATHLON                     =
                    "Биатлон",
                HEALTH_IMPROVING             =
                    "Оздоровительная физическая культура",
                ADAPTIVE                     =
                    "Адаптивная физическая культура",
                FREESTYLE_WRESTLING          =
                    "Вольная борьба",
                GRECO_ROMAN_WRESTLING        =
                    "Греко-римская борьба",
                SAMBO                        =
                    "Самбо",
                JUDO                         =
                    "Дзюдо",
                TABLE_TENNIS_ABITURIENT      =
                    "Теннис настольный",
                ERGOTHERAPY                  =
                    "Эрготерапия",
                MANAGEMENT_SPORTS            =
                    "Менеджмент в спорте",
                SPORTS_DIRECTING_DEANERY     =
                    "Спортивная режиссура",
                SPORTS_RECREATIONAL_TOURISM  =
                    "Спортивный и рекреационный туризм",
                MANAGEMENT_TOURISM           =
                    "Менеджмент в туризме",
                SPORTS_PSYCHOLOGY            =
                    "Спортивная психология",
                BILLIARD_SPORTS              =
                    "Бильярдный спорт",
                ACROBATICS                   =
                    "Акробатика",
                ORIENTEERING                 =
                    "Спортивное ориентирование",
                SPORTS_DIRECTING             =
                    "Спортивная режиссура",
                PRESCHOOLERS                 =
                    "Физическая культура дошкольников",
                MOUNTAINEERING               =
                    "Альпинизм",
                SKI_COMBINED                 =
                    "Лыжное двоеборье",
                TOURISM_HOSPITALITY          =
                    "Туризм и гостеприимство",
                WATER_TECHNICAL_SPORTS       =
                    "Водно-технические виды спорта",
                MODEL_TECHNICAL_SPORTS       =
                    "Модельно-технические виды спорта",
                ALPINE_SKIING                =
                    "Горнолыжный спорт",
                BASEBALL                     =
                    "Бейсбол",
                WUSHU                        =
                    "Ушу",
                CHESS                        =
                    "Шахматы",
                THAI_BOXING                  =
                    "Таиландский бокс",
                TOURISM_PROMOTION            =
                    "Технологии формирования и продвижения "            \
                    "туристических услуг",
                TOURISM_IT                   =
                    "Информационные технологии туристической "          \
                    "индустрии",
                TOURISM_LOGISTICS            =
                    "Логистика в туристической индустрии",
                TOURISM_SOCIAL               =
                    "Технологии социокультурного сервиса "              \
                    "туристов",
                TOURISM_TRANSPORT            =
                    "Технологии транспортного сервиса туристов",
                TOURISM_FOOD                 =
                    "Технологии сервиса питания туристов",
                TOURIST_ACCOMMODATION        =
                    "Технологии сервиса размещения туристов",
                TOURISM_EXCURSION            =
                    "Технологии экскурсионно-сопроводительного "        \
                    "сервиса туристов",
                TOURISM_HEALTH               =
                    "Технологии сервиса оздоровления и лечения "        \
                    "туристов",
                BULLET_SHOOTING              =
                    "Стрельба пулевая",
                FIELD_HOCKEY                 =
                    "Хоккей на траве",
                FIGURE_SKATING               =
                    "Фигурное катание на коньках",
                ROWING_AND_CANOEING          =
                    "Гребля на байдарках и каноэ",
                ACADEMIC_ROWING              =
                    "Гребля академическая",
                HAND_TO_HAND_COMBAT_MS       =
                    "Рукопашный бой (смешанные единоборства)",
                BILLIARDS_RPC                =
                    "Бильярд",
                WITHOUT_SPECIALIZATION       =
                    "Без специализации",
                MEDICAL                      =
                    "Физическая культура(лечебная)",
                MODERN_PENTATHLON            =
                    "Современное пятиборье",
                SCIENCE_HEALTH               =
                    "теория и методика физического воспитания, "        \
                    "спортивной тренировки, оздоровительной",
                PHYSIOLOGY                   =
                    "физиология",
                SCIENCE_THEORY               =
                    "теория и методика физического воспитания, "        \
                    "спортивной тренировки, оздоровительной",
                RECEARCH_SPORT               =
                    "теория и методика физического воспитания, "        \
                    "спортивной тренировки, оздоровительной",
                INNOVATIVE_TOURISM           =
                    "инновационный менеджмент в сфере туризма",
                INNOVATIVE_HOSPITALITY       =
                    "инновационный менеджмент в сфере гостеприимства",
                INNOVATIVE_TECHNOLOGIES      =
                    "инновационные технологии в сфере туризма "         \
                    "и гостеприимства",
                INNOVATIVE_MANAGEMENT        =
                    "управление инновационными проектами в "            \
                    "туристской индустрии",
                BILLIARDS_SMA                =
                    "Бильярд",
                HAND_TO_HAND_COMBAT_SMA      =
                    "Рукопашный бой (смешанные единоборства)",
                BADMINTON                    =
                    "Бадминтон",
                TABLE_TENNIS_DEANERY         =
                    "Настольный теннис",
                PHYSICAL_CULTURE_SPORT       =
                    "Физическая культура и спорт",
                TOURISM_HOSPITALITY_MASTER   =
                    "Туризм и гостеприимство",
                SPORT_CLIMBING               =
                    "Скалолазание спортивное",
                MASTER_ANTHROPOLOGY          =
                    "антропология",
                MASTER_MANAGEMENT            =
                    "Менеджмент",
                MASTER_PHYSICAL_CULTURE      =
                    "Физическая культура и спорт";

            namespace DATIVE_CASE
            {
                const AnsiString
                    GYMNASTICS                   =
                        "гимнастике",
                    MANAGEMENT_SPORTS_TOURISM    =
                        "менеджменту спорта и туризма",
                    PHYSICAL_REHABILITATION      =
                        "физическая реабилитации",
                    THERAPEUTIC                  =
                        "лечебной физическая культура",
                    ORGANIZATION_SPORTS_TOURISM  =
                        "организации физкультурно-оздоровительной "         \
                        "работы и туризма",
                    PRESCHOOL_PHYSICAL_EDUCATION =
                        "дошкольному физическому воспитанию",
                    DANCE_SPORT                  =
                        "танцевальному спорту",
                    AEROBICS                     =
                        "аэробике",
                    ROWING_OTHER                 =
                        "гребному спорту",
                    SWIMMING                     =
                        "плаванию",
                    SAILING                      =
                        "парусному спорту",
                    ATHLETICS                    =
                        "легкой атлетике",
                    CROSS_COUNTRY_SKIING         =
                        "лыжным гонкам",
                    BULLET_SHOOTING_DEANERY      =
                        "пулевой стрельбе",
                    HAND_TO_HAND_COMBAT          =
                        "рукопашному бою",
                    TAEKWONDO                    =
                        "таэквондо",
                    KARATE                       =
                        "каратэ",
                    SKIING                       =
                        "лыжному спорту",
                    AUTOMOTIVE_SPORT             =
                        "автомобильному спорту",
                    BASKETBALL                   =
                        "баскетболу",
                    BOXING                       =
                        "боксу",
                    GRECO_FREESTYLE_WRESTLING    =
                        "греко-римской и вольной борьбе",
                    CYCLING                      =
                        "велосипедному спорту",
                    VOLLEYBALL                   =
                        "волейболу",
                    HANDBALL                     =
                        "гандболу",
                    EQUESTRIAN                   =
                        "конному спорту",
                    SPEED_SKATING                =
                        "конькобежному спорту",
                    TENNIS                       =
                        "теннису",
                    WEIGHTLIFTING                =
                        "тяжелой атлетике",
                    FENCING                      =
                        "фехтованию",
                    FIGURE_SKATING_OLD           =
                        "фигурному катанию",
                    FOOTBALL                     =
                        "футболу",
                    HOCKEY                       =
                        "хоккею",
                    SAMBO_JUDO                   =
                        "самбо-дзюдо",
                    WRESTLING                    =
                        "спортивной борьбе",
                    FOOTBALL_HOCKEY              =
                        "футболу и хоккею",
                    BIATHLON                     =
                        "биатлону",
                    HEALTH_IMPROVING             =
                        "оздоровительной физической культуре",
                    ADAPTIVE                     =
                        "адаптивной физической культуре",
                    FREESTYLE_WRESTLING          =
                        "вольной борьбе",
                    GRECO_ROMAN_WRESTLING        =
                        "греко-римской борьбе",
                    SAMBO                        =
                        "самбо",
                    JUDO                         =
                        "дзюдо",
                    TABLE_TENNIS_ABITURIENT      =
                        "теннису настольному",
                    ERGOTHERAPY                  =
                        "эрготерапии",
                    MANAGEMENT_SPORTS            =
                        "менеджменту в спорте",
                    SPORTS_DIRECTING_DEANERY     =
                        "спортивной режиссуре",
                    SPORTS_RECREATIONAL_TOURISM  =
                        "спортивному и рекреационному туризму",
                    MANAGEMENT_TOURISM           =
                        "менеджменту в туризме",
                    SPORTS_PSYCHOLOGY            =
                        "спортивной психологии",
                    BILLIARD_SPORTS              =
                        "бильярдному спорту",
                    ACROBATICS                   =
                        "акробатике",
                    ORIENTEERING                 =
                        "спортивному ориентированию",
                    SPORTS_DIRECTING             =
                        "спортивной режиссуре",
                    PRESCHOOLERS                 =
                        "физической культуре дошкольников",
                    MOUNTAINEERING               =
                        "альпинизму",
                    SKI_COMBINED                 =
                        "лыжному двоеборью",
                    TOURISM_HOSPITALITY          =
                        "туризму и гостеприимству",
                    WATER_TECHNICAL_SPORTS       =
                        "водно-техническим видам спорта",
                    MODEL_TECHNICAL_SPORTS       =
                        "модельно-техническим видам спорта",
                    ALPINE_SKIING                =
                        "горнолыжному спорту",
                    BASEBALL                     =
                        "бейсболу",
                    WUSHU                        =
                        "ушу",
                    CHESS                        =
                        "шахматам",
                    THAI_BOXING                  =
                        "таиландскому боксу",
                    TOURISM_PROMOTION            =
                        "технологиям формирования и продвижения "            \
                        "туристических услуг",
                    TOURISM_IT                   =
                        "информационным технологиям туристической "          \
                        "индустрии",
                    TOURISM_LOGISTICS            =
                        "логистике в туристической индустрии",
                    TOURISM_SOCIAL               =
                        "технологиям социокультурного сервиса "              \
                        "туристов",
                    TOURISM_TRANSPORT            =
                        "технологиям транспортного сервиса туристов",
                    TOURISM_FOOD                 =
                        "технологиям сервиса питания туристов",
                    TOURIST_ACCOMMODATION        =
                        "технологиям сервиса размещения туристов",
                    TOURISM_EXCURSION            =
                        "технологиям экскурсионно-сопроводительного "        \
                        "сервиса туристов",
                    TOURISM_HEALTH               =
                        "технологиям сервиса оздоровления и лечения "        \
                        "туристов",
                    BULLET_SHOOTING              =
                        "стрельбе пулевой",
                    FIELD_HOCKEY                 =
                        "хоккею на траве",
                    FIGURE_SKATING               =
                        "фигурному катанию на коньках",
                    ROWING_AND_CANOEING          =
                        "гребле на байдарках и каноэ",
                    ACADEMIC_ROWING              =
                        "гребле академической",
                    HAND_TO_HAND_COMBAT_MS       =
                        "рукопашному бою (смешанные единоборства)",
                    BILLIARDS_RPC                =
                        "бильярду",
                    WITHOUT_SPECIALIZATION       =
                        "без специализации",
                    MEDICAL                      =
                        "физической культуре (лечебной)",
                    MODERN_PENTATHLON            =
                        "современному пятиборью",
                    SCIENCE_HEALTH               =
                        "теории и методике физического воспитания, "        \
                        "спортивной тренировки, оздоровительной",
                    PHYSIOLOGY                   =
                        "физиологии",
                    SCIENCE_THEORY               =
                        "теории и методике физического воспитания, "        \
                        "спортивной тренировки, оздоровительной",
                    RECEARCH_SPORT               =
                        "теории и методике физического воспитания, "        \
                        "спортивной тренировки, оздоровительной",
                    INNOVATIVE_TOURISM           =
                        "инновационному менеджменту в сфере туризма",
                    INNOVATIVE_HOSPITALITY       =
                        "инновационному менеджменту в сфере гостеприимства",
                    INNOVATIVE_TECHNOLOGIES      =
                        "инновационным технологиям в сфере туризма "         \
                        "и гостеприимства",
                    INNOVATIVE_MANAGEMENT        =
                        "управлению инновационными проектами в "            \
                        "туристской индустрии",
                    BILLIARDS_SMA                =
                        "бильярду",
                    HAND_TO_HAND_COMBAT_SMA      =
                        "рукопашному бою (смешанные единоборства)",
                    BADMINTON                    =
                        "бадминтону",
                    TABLE_TENNIS_DEANERY         =
                        "настольному теннису",
                    PHYSICAL_CULTURE_SPORT       =
                        "физической культуре и спорту",
                    TOURISM_HOSPITALITY_MASTER   =
                        "туризму и гостеприимству",
                    SPORT_CLIMBING               =
                        "спортивному скалолазанию",
                    MASTER_ANTHROPOLOGY          =
                        "антропологии",
                    MASTER_MANAGEMENT            =
                        "менеджменту",
                    MASTER_PHYSICAL_CULTURE      =
                        "физической культуре и спорту";
            }
        }
        namespace SportsRanks
        {
            const AnsiString
                INTERNATIONAL_MASTER_OF_SPORTS =                                        // (IMS)
                    "Мастер спорта международного класса (МСМК)",
                HONORED_MASTER_OF_SPORTS       = "Заслуженный мастер спорта (ЗМС)",     // (HMS)
                MASTER_OF_SPORT                = "Мастер спорта (МС)",                  // (MS)
                CANDIDATE_IN_MASTERS_OF_SPORT  = "Кандидат в мастера спорта (КМС)",     // (CMS)
                FIRST_SPORT_CATEGORY           = "I спортивный разряд (I разряд)",      // (FSC)
                SECOND_SPORT_CATEGORY          = "II спортивный разряд (II разряд)",    // (SSC)
                THIRD_SPORT_CATEGORY           = "III спортивный разряд (III разряд)",  // (TSC)
                FIRST_YOUTH_CATEGORY           = "I юношеский разряд (I юношеский)",    // (FYC)
                SECOND_YOUTH_CATEGORY          = "II юношеский разряд (II юношеский)",  // (SYC)
                FIRST_APPRENTICESHIP_DEGREE    = "1-я ученическая степень (1 кю)",      // (FAD)
                SECOND_APPRENTICESHIP_DEGREE   = "2-я ученическая степень (2 кю)",      // (SAD)
                THIRD_APPRENTICESHIP_DEGREE    = "3-я ученическая степень (3 кю)",      // (TAD)
                WITHOUT                        = "нет";                                 // (NO)

            namespace ABBR
            {
                const AnsiString
                    INTERNATIONAL_MASTER_OF_SPORTS = "МСМК",
                    HONORED_MASTER_OF_SPORTS       = "ЗМС",
                    MASTER_OF_SPORT                = "МС",
                    CANDIDATE_IN_MASTERS_OF_SPORT  = "КМС",
                    FIRST_SPORT_CATEGORY           = "I разряд",
                    SECOND_SPORT_CATEGORY          = "II разряд",
                    THIRD_SPORT_CATEGORY           = "III разряд",
                    FIRST_YOUTH_CATEGORY           = "I юношеский",
                    SECOND_YOUTH_CATEGORY          = "II юношеский",
                    FIRST_APPRENTICESHIP_DEGREE    = "1 кю",
                    SECOND_APPRENTICESHIP_DEGREE   = "2 кю",
                    THIRD_APPRENTICESHIP_DEGREE    = "3 кю",
                    WITHOUT                        = "нет";
            }
        }
        namespace StudyPeriod
        {
            namespace HIGH
            {
                const AnsiString
                    NAME           = "Высшее образование",
                    FULL           = "Полный срок",                                     // t_abitur_queue.term_edu = 0
                    FIRST_COURSE   = "Высшее образование (1 курс)",                     // t_abitur_queue.term_edu = 3
                    SECOND_COURSE  = "Высшее образование (2 курс)",                     // t_abitur_queue.term_edu = 4
                    THIRD_COURSE   = "Высшее образование (3 курс)";                     // t_abitur_queue.term_edu = 5
            }
            namespace SHORT
            {
                const AnsiString
                    NAME          = "Cокращённый срок",
                    SECOND_COURSE = "Cокращённый срок (2 курс)",                        // t_abitur_queue.term_edu = 1
                    THIRD_COURSE  = "Cокращённый срок (3 курс)";                        // t_abitur_queue.term_edu = 2
            }
        }
    #else
        namespace Admissions
        {
            namespace TIME
            {
                const AnsiString
                    YEAR                 =
                        (Now ())
                            .FormatString (
                                "yyyy"
                            );
            }
            namespace INVENTORY
            {
                const AnsiString
                    #ifdef SET_INVENTORY_DATE_BY_HAND                                   // IT'S FOR CHANGING CURRENT DATE TO OTHER INTO INVENTORY LIST (ListDlgUnit.cpp)
                    DATE                 =
                        "01.06.2023";
                    #else
                    DATE                 =
                        (Now ())
                            .FormatString (
                                "dd.mm.yyyy"
                            );
                    #endif  // SET_INVENTORY_DATE_BY_HAND
            }
            namespace DEADLINE
            {
                const AnsiString
                    FOR_RECEIVING_PART_1 =
                        "05.06."                    +
                            Admissions::TIME::YEAR  +
                        " 6:00:00",
                    FOR_RECEIVING_PART_2 =
                        "10.08."                    +
                            Admissions::TIME::YEAR  +
                        " 6:00:00";
            }
            namespace ADDITIONAL
            {
                const AnsiString
                    ORDER_DATE_PART_1    =
                        "04.06."                    +
                            Admissions::TIME::YEAR,
                    ORDER_DATE_PART_2    =
                        "08.08."                    +
                            Admissions::TIME::YEAR;
            }
            namespace DOCUMENTS
            {
                const AnsiString
                    PROVIDE_DATE =
                        "15.06."                    +
                            Admissions::TIME::YEAR;
            }
            namespace ARRIVAL
            {
                namespace TIME
                {
                    const AnsiString
                        EVERYONE = "9:00";
                }
                namespace DATE
                {
                    namespace INTRAMURAL
                    {
                        const AnsiString
                            ALL =
                                "01.09."                    +
                                    Admissions::TIME::YEAR;
                    }
                    namespace EXTRAMURAL
                    {
                        namespace FULL
                        {
                            const AnsiString
                                MSTH  =
                                    "05.09."                    +
                                        Admissions::TIME::YEAR,
                                OTHER =
                                    "12.09."                    +
                                        Admissions::TIME::YEAR;
                        }
                        namespace SHORT
                        {
                            const AnsiString
                                SMA   =
                                    "03.10."                    +
                                        Admissions::TIME::YEAR,
                                MS    =
                                    "05.10."                    +
                                        Admissions::TIME::YEAR,
                                RPC   =
                                    "07.10."                    +
                                        Admissions::TIME::YEAR,
                                MSTH  =
                                    "24.10."                    +
                                        Admissions::TIME::YEAR;
                        }
                    }
                }
            }
        }
        namespace ContestType
        {
            const AnsiString
                GENERAL                = "общий",
                WITHOUT_ENTRANCE_EXAMS = "без вступительных испытаний",
                OUT_OF_COMPETITION     = "вне конкурса",
                TARGETED_TRAINING      = "целевой";
        }
        namespace Contract
        {
            namespace DOCUMENT_FILE
            {
                const AnsiString
                    BUDGET  = "ДОГОВОР - Бюджет.xls",
                    BUYERS  = "ДОГОВОР - Платники.xls";
            }
            namespace DOCUMENT_NAME
            {
                const AnsiString
                    BUDGET = "ДОГОВОР - Бюджет",
                    BUYERS = "ДОГОВОР - Платники";
            }
            namespace BSUPC
            {
                const AnsiString
					PERSON = "Башлаковой Галины Ивановны";                         // Old name: CONTRACT_SIDE_BSUPC_MAIN

                namespace BASE_DOCUMENT
                {
                    const AnsiString
                        NAME   = "доверенности",                                        // Old name: CONTRACT_TYPE_POWER_DOC_MAIN
                        DATE   = "16.11.2021",                                          // Old name: CONTRACT_POWER_DOC_DATE_MAIN
                        NUMBER = "13-16-45";                                            // Old name: CONTRACT_POWER_DOC_NO_MAIN
                }
            }
            namespace IMS
            {
                const AnsiString
                    PERSON = "Михайловой Ольги Николаевны";                             // Old name: CONTRACT_SIDE_BSUPC_IMST

                namespace BASE_DOCUMENT
                {
                    const AnsiString
                        NAME   = "доверенности",                                        // Old name: CONTRACT_TYPE_POWER_DOC_IMST
                        DATE   = "26.10.2021",                                          // Old name: CONTRACT_POWER_DOC_DATE_IMST
                        NUMBER = "13-16-42";                                            // Old name: CONTRACT_POWER_DOC_NO_IMST
                }
            }
            namespace PAYMENT_TERM
            {
                const AnsiString
                    FIRST_SEMESTER  =
                        "по 31.08."                                 +
                            Admissions::TIME::YEAR                  +
                        " (включительно) – за первый "              \
                        "семестр первого года обучения в размере",
                    SECOND_SEMESTER =
                        "с 01.02."                                  +
                            AnsiString (
                                    StrToInt (
                                        Admissions::TIME::YEAR
                                    )
                                +   Default::STEP
                            )                                       +
                        " до 01.03."                                +
                            AnsiString (
                                    StrToInt (
                                        Admissions::TIME::YEAR
                                    )
                                +   Default::STEP
                            )                                       +
                        " – за второй семестр первого года "        \
                        "обучения в размере";
            }
            namespace COST_FOR
            {
                namespace BUDGET
                {
                    namespace INTRAMURAL
                    {
                        const AnsiString
                            FULL_COURSE   =                                             // БЮДЖЕТ, ДНЕВНОЕ, ПОЛНЫЙ СРОК
                                "заключения настоящего договора "               \
                                "составляет 32830,32 ("                         \
                                "тридцать две тысячи восемьсот тридцать "       \
                                "рублей 32 копейки) белорусских рублей.",
                            SECOND_COURSE =                                             // БЮДЖЕТ, ДНЕВНОЕ, СОКРАЩЁННЫЙ СРОК (2 курс)
                                "заключения настоящего договора "               \
                                "составляет 24622,74 ("                         \
                                "двадцать четыре тысячи шестьсот двадцать два " \
                                "рубля 74 копейки) белорусских рублей.";
                    }
                    namespace EXTRAMURAL
                    {
                        const AnsiString
                            FULL_COURSE   =                                             // БЮДЖЕТ, ЗАОЧНОЕ, ПОЛНЫЙ СРОК
                                "заключения настоящего договора "               \
                                "составляет 16415,15 ("                         \
                                "шестнадцать тысяч четыреста пятнадцать "       \
                                "рублей 15 копеек) белорусских рублей.",
                            SECOND_COURSE =                                             // БЮДЖЕТ, ЗАОЧНОЕ, СОКРАЩЁННЫЙ СРОК (2 курс)
                                "заключения настоящего договора "               \
                                "составляет 13132,12 ("                         \
                                "тринадцать тысяч сто тридцать два "            \
                                "рубля 12 копеек) белорусских рублей.",
                            THIRD_COURSE  =                                             // БЮДЖЕТ, ЗАОЧНОЕ, СОКРАЩЁННЫЙ СРОК (3 курс)
                                "заключения настоящего договора "               \
                                "составляет 9849,09 ("                          \
                                "девять тысяч восемьсот сорок девять "          \
                                "рублей 09 копеек) белорусских рублей.";
                    }
                }
                namespace BUYERS
                {
                    namespace INTRAMURAL
                    {
                        const AnsiString                                                // ПЛАТНИКИ, ДНЕВНОЕ, ЗА ГОД
                            ANNUAL       =
                                "составляет 2748 ("                             \
                                "две тысячи семьсот сорок восемь"               \
                                ") белорусских рублей "                         \
                                "за первый год обучения.",
                            PER_SEMESTER =                                              // ПЛАТНИКИ, ДНЕВНОЕ, ПО СЕМЕСТРАМ
                                "1374 ("                                        \
                                "одна тысяча триста семьдесят четыре"           \
                                ") белорусских рублей;";
                    }
                    namespace EXTRAMURAL
                    {
                        const AnsiString
                            ANNUAL           =                                          // ПЛАТНИКИ, ЗАОЧНОЕ, ЗА ГОД (СИиЕ, МВС, ОФК)
                                "составляет 1065 ("                             \
                                "одна тысяча шестьдесят пять"                   \
                                ") белорусских рублей "                         \
                                "за первый год обучения.",
                            ANNUAL_IMS       =                                          // ПЛАТНИКИ, ЗАОЧНОЕ, ЗА ГОД (ИМСиТ)
                                "составляет 1135 ("                             \
                                "одна тысяча сто тридцать пять"                 \
                                ") белорусских рублей "                         \
                                "за первый год обучения.",
                            PER_SEMESTER     =                                          // ПЛАТНИКИ, ЗАОЧНОЕ, ПО СЕМЕСТРАМ (СИиЕ, МВС, ОФК)
                                "532,50 ("                                      \
                                "пятьсот тридцать два "                         \
                                "рубля 50 копеек) белорусских рублей;",
                            PER_SEMESTER_IMS =                                          // ПЛАТНИКИ, ЗАОЧНОЕ, ПО СЕМЕСТРАМ (ИМСиТ)
                                "567,50 ("                                      \
                                "пятьсот шестьдесят семь "                      \
                                "рублей 50 копеек) белорусских рублей;";
                    }
                }
            }
        }
        #ifndef NEW_DOCUMENTS_NAMESPACES
            namespace DocumentFile
            {
                namespace APPLICATION_FOR
                {
                    const AnsiString
                        PARTICIPATION       = "ЗАЯВЛЕНИЕ - Допуск к участию.xls";
                }
                namespace LIST
                {
                    const AnsiString
                        GROUPS              = "СПИСОК - Групп.xls";                         // NEW (СПИСОК.xls -> СПИСОК - групп.xls)
                }
                namespace PROTOCOL
                {
                    AnsiString
                        admitted            = "ПРОТОКОЛ - О допуске абитуриентов.doc",      // NEW (OLE Issue) DELETE YEAR
                        daily               = "ПРОТОКОЛ - Ежедневный.xls",
                        exam                = "ПРОТОКОЛ - Экзамен по ФКиС.xls";
                    const AnsiString
                        GIRLS_TESTS         = "ПРОТОКОЛ - Испытаний (Девушки).xls";
                }
                namespace REGISTRY
                {
                    const AnsiString
                        BOOK                = "ЖУРНАЛ - Регистрация.xls";
                }
                namespace REPORT
                {
                    const AnsiString
                        FORM_1              = "ОТЧЕТ - Форма 1.xls",                        // NEW (INDEX Issue MessageBox) DELETE YEAR
                        FORM_2              = "ОТЧЕТ - Форма 2.xls",                        // NEW (INDEX Issue MessageBox, REQUIRE CHECK Section I) DELETE YEAR
                        SUBMITTED           = "ОТЧЕТ - Подано заявлений.xls";
                }
                namespace STATISTIC
                {
                    AnsiString
                        cert_result_hundred =
                            "СТАТИСТИКА - Результаты сертификатов (стобалльная).xls",
                        cert_result_ten     =
                            "СТАТИСТИКА - Результаты сертификатов (десятибалльная).xls",    // (REQUIRE CHECK Range)
                        exam_result         =
                            "СТАТИСТИКА - Результаты сдачи экзаменов.xls";
                    const AnsiString
                        ADMISSION_PROGRESS  =
                            "СТАТИСТИКА - Ход приема.xls",
                        CONTEST             =
                            "СТАТИСТИКА - Конкурс.xls",                                     // NEW DELETE YEAR
                        DAILY               =
                            "СТАТИСТИКА - Ежедневная.xls",
                        LEVEL_OF_SPORTS     =
                            "СТАТИСТИКА - Уровень спортивной подготовки.xls",
                        SCORES              =
                            "СТАТИСТИКА - Баллы.xls";                                       // NOTE: INSTEAD USEING Abitur_RIO
                }
                namespace SUMMARY_LIST
                {
                    const AnsiString
                        ENROLLMENT          = "ВЕДОМОСТЬ - Зачисление.xls",
                        ENTRANCE_EXAMS      = "ВЕДОМОСТЬ - Вступительных экзаменов.xls";    // NEW DELETE YEAR
                }
            }
            namespace DocumentName
            {
                namespace APPLICATION_FOR
                {
                    const AnsiString
                        PARTICIPATION      = "ЗАЯВЛЕНИЕ - Допуск к участию";
                }
                namespace LIST
                {
                    const AnsiString
                        GROUPS             = "СПИСОК - Групп",                              // NEW (СПИСОК -> СПИСОК - групп)
                        BY_DESTINATIONS    = "СПИСОК - По направлениям",
                        BY_GENDER          = "СПИСОК - По полу";
                }
                namespace PROTOCOL
                {
                    AnsiString
                        daily              = "ПРОТОКОЛ - Ежедневный",
                        exam               = "ПРОТОКОЛ - Экзамен по ФКиС";
                    const AnsiString
                        GIRLS_TESTS        = "ПРОТОКОЛ - Испытаний (Девушки)";
                }
                namespace REGISTRY
                {
                    const AnsiString
                        BOOK               = "ЖУРНАЛ - Регистрация";
                }
                namespace REPORT
                {
                    const AnsiString
                        FORM_1             = "ОТЧЕТ - Форма 1",
                        FORM_2             = "ОТЧЕТ - Форма 2",
                        SUBMITTED          = "ОТЧЕТ - Подано заявлений";                    // (REQUIRE CHECK Calcalation)
                }
                namespace STATISTIC
                {
                    const AnsiString
                        ADMISSION_PROGRESS =
                            "СТАТИСТИКА - Ход приема",
                        CONTEST            =
                            "СТАТИСТИКА - Конкурс",
                        DAILY              =
                            "СТАТИСТИКА - Ежедневная",
                        LEVEL_OF_SPORTS    =
                            "СТАТИСТИКА - Уровень спортивной подготовки",
                        SCORES             =
                            "СТАТИСТИКА - Баллы";                                           // INSTEAD USEING Abitur_RIO
                }
                namespace SUMMARY_LIST
                {
                    const AnsiString
                        ENROLLMENT         = "ВЕДОМОСТЬ - Зачисление",
                        ENTRANCE_EXAMS     = "ВЕДОМОСТЬ - Вступительных экзаменов";
                }
            }
        #else
            // Document::EXTENSION::EXCEL
            // Document::EXTENSION::WORD

            // Document::NAME::APPLICATION_FOR::PARTICIPATION
            // Document::NAME::LIST::BY_DESTINATIONS
            // Document::NAME::LIST::BY_GENDER
            // Document::NAME::LIST::GROUPS
            // Document::NAME::PROTOCOL::ADMITTED
            // Document::NAME::PROTOCOL::DAILY
            // Document::NAME::PROTOCOL::EXAM
            // Document::NAME::PROTOCOL::GIRLS_TESTS
            // Document::NAME::REGISTRY::BOOK
            // Document::NAME::REPORT::FORM_1
            // Document::NAME::REPORT::FORM_2
            // Document::NAME::REPORT::SUBMITTED
            // Document::NAME::STATISTIC::ADMISSION_PROGRESS
            // Document::NAME::STATISTIC::CERT_RESULT_HUNDRED
            // Document::NAME::STATISTIC::CERT_RESULT_TEN
            // Document::NAME::STATISTIC::CONTEST
            // Document::NAME::STATISTIC::DAILY
            // Document::NAME::STATISTIC::EXAM_RESULT
            // Document::NAME::STATISTIC::LEVEL_OF_SPORTS
            // Document::NAME::STATISTIC::SCORES
            // Document::NAME::SUMMARY_LIST::ENROLLMENT
            // Document::NAME::SUMMARY_LIST::ENTRANCE_EXAMS

            // Document::FILE::APPLICATION_FOR::PARTICIPATION
            // Document::FILE::LIST::BY_DESTINATIONS
            // Document::FILE::LIST::BY_GENDER
            // Document::FILE::LIST::GROUPS
            // Document::FILE::PROTOCOL::ADMITTED
            // Document::FILE::PROTOCOL::DAILY
            // Document::FILE::PROTOCOL::EXAM
            // Document::FILE::PROTOCOL::GIRLS_TESTS
            // Document::FILE::REGISTRY::BOOK
            // Document::FILE::REPORT::FORM_1
            // Document::FILE::REPORT::FORM_2
            // Document::FILE::REPORT::SUBMITTED
            // Document::FILE::STATISTIC::ADMISSION_PROGRESS
            // Document::FILE::STATISTIC::CERT_RESULT_HUNDRED
            // Document::FILE::STATISTIC::CERT_RESULT_TEN
            // Document::FILE::STATISTIC::CONTEST
            // Document::FILE::STATISTIC::DAILY
            // Document::FILE::STATISTIC::EXAM_RESULT
            // Document::FILE::STATISTIC::LEVEL_OF_SPORTS
            // Document::FILE::STATISTIC::SCORES
            // Document::FILE::SUMMARY_LIST::ENROLLMENT
            // Document::FILE::SUMMARY_LIST::ENTRANCE_EXAMS
            namespace Document
            {
                namespace EXTENSION
                {
                    const AnsiString
                        EXCEL = ".xls",
                        WORD  = ".doc";
                }
                namespace NAME
                {
                    namespace APPLICATION_FOR
                    {
                        const AnsiString
                            PARTICIPATION        =
                                "ЗАЯВЛЕНИЕ - Допуск к участию";
                    }
                    namespace LIST
                    {
                        const AnsiString
                            BY_DESTINATIONS      =
                                "СПИСОК - По направлениям",
                            BY_GENDER            =
                                "СПИСОК - По полу",
                            GROUPS               =                                          // NEW (СПИСОК -> СПИСОК - групп)
                                "СПИСОК - Групп";
                    }
                    namespace PROTOCOL
                    {
                        const AnsiString
                            ADMITTED             =
                                "ПРОТОКОЛ - О допуске абитуриентов",                        // NEW (OLE Issue) DELETE YEAR
                            DAILY                =
                                "ПРОТОКОЛ - Ежедневный",
                            EXAM                 =
                                "ПРОТОКОЛ - Экзамен по ФКиС",
                            GIRLS_TESTS          =
                                "ПРОТОКОЛ - Испытаний (Девушки)";
                    }
                    namespace REGISTRY
                    {
                        const AnsiString
                            BOOK                 =
                                "ЖУРНАЛ - Регистрация";
                    }
                    namespace REPORT
                    {
                        const AnsiString
                            FORM_1               =
                                "ОТЧЕТ - Форма 1",
                            FORM_2               =
                                "ОТЧЕТ - Форма 2",
                            SUBMITTED            =
                                "ОТЧЕТ - Подано заявлений";                                 // (REQUIRE CHECK Calcalation)
                    }
                    namespace STATISTIC
                    {
                        const AnsiString
                            ADMISSION_PROGRESS   =
                                "СТАТИСТИКА - Ход приема",
                            CERT_RESULT_HUNDRED  =
                                "СТАТИСТИКА - Результаты сертификатов (стобалльная)",
                            CERT_RESULT_TEN      =
                                "СТАТИСТИКА - Результаты сертификатов (десятибалльная)",    // (REQUIRE CHECK Range)
                            CONTEST              =
                                "СТАТИСТИКА - Конкурс",
                            DAILY                =
                                "СТАТИСТИКА - Ежедневная",
                            EXAM_RESULT          =
                                "СТАТИСТИКА - Результаты сдачи экзаменов",
                            LEVEL_OF_SPORTS      =
                                "СТАТИСТИКА - Уровень спортивной подготовки",
                            SCORES               =
                                "СТАТИСТИКА - Баллы";                                       // INSTEAD USEING Abitur_RIO
                    }
                    namespace SUMMARY_LIST
                    {
                        const AnsiString
                            ENROLLMENT           =
                                "ВЕДОМОСТЬ - Зачисление",
                            ENTRANCE_EXAMS       =
                                "ВЕДОМОСТЬ - Вступительных экзаменов";
                    }
                }
                namespace FILE
                {
                    namespace APPLICATION_FOR
                    {
                        const AnsiString
                            PARTICIPATION       =
                                Document::NAME::APPLICATION_FOR::PARTICIPATION    +
                                Document::EXTENSION::EXCEL;
                    }
                    namespace LIST
                    {
                        const AnsiString
                            BY_DESTINATIONS     =
                                Document::NAME::LIST::BY_DESTINATIONS             +
                                Document::EXTENSION::EXCEL,
                            BY_GENDER           =
                                Document::NAME::LIST::BY_GENDER                   +
                                Document::EXTENSION::EXCEL,
                            GROUPS              =
                                Document::NAME::LIST::GROUPS                      +
                                Document::EXTENSION::EXCEL;
                    }
                    namespace PROTOCOL
                    {
                        const AnsiString
                            ADMITTED            =
                                Document::NAME::PROTOCOL::ADMITTED                +
                                Document::EXTENSION::EXCEL,
                            DAILY               =
                                Document::NAME::PROTOCOL::DAILY                   +
                                Document::EXTENSION::EXCEL,
                            EXAM                =
                                Document::NAME::PROTOCOL::EXAM                    +
                                Document::EXTENSION::EXCEL,
                            GIRLS_TESTS         =
                                Document::NAME::PROTOCOL::GIRLS_TESTS             +
                                Document::EXTENSION::EXCEL;
                    }
                    namespace REGISTRY
                    {
                        const AnsiString
                            BOOK                =
                                Document::NAME::REGISTRY::BOOK                    +
                                Document::EXTENSION::EXCEL;
                    }
                    namespace REPORT
                    {
                        const AnsiString
                            FORM_1              =
                                Document::NAME::REPORT::FORM_1                    +
                                Document::EXTENSION::EXCEL,
                            FORM_2              =
                                Document::NAME::REPORT::FORM_2                    +
                                Document::EXTENSION::EXCEL,
                            SUBMITTED           =
                                Document::NAME::REPORT::SUBMITTED                 +
                                Document::EXTENSION::EXCEL;
                    }
                    namespace STATISTIC
                    {
                        const AnsiString
                            ADMISSION_PROGRESS  =
                                Document::NAME::STATISTIC::ADMISSION_PROGRESS     +
                                Document::EXTENSION::EXCEL,
                            CERT_RESULT_HUNDRED =
                                Document::NAME::STATISTIC::CERT_RESULT_HUNDRED    +
                                Document::EXTENSION::EXCEL,
                            CERT_RESULT_TEN     =
                                Document::NAME::STATISTIC::CERT_RESULT_TEN        +
                                Document::EXTENSION::EXCEL,
                            CONTEST             =
                                Document::NAME::STATISTIC::CONTEST                +
                                Document::EXTENSION::EXCEL,
                            DAILY               =
                                Document::NAME::STATISTIC::DAILY                  +
                                Document::EXTENSION::EXCEL,
                            EXAM_RESULT         =
                                Document::NAME::STATISTIC::EXAM_RESULT            +
                                Document::EXTENSION::EXCEL,
                            LEVEL_OF_SPORTS     =
                                Document::NAME::STATISTIC::LEVEL_OF_SPORTS        +
                                Document::EXTENSION::EXCEL,
                            SCORES              =
                                Document::NAME::STATISTIC::SCORES                 +
                                Document::EXTENSION::EXCEL;
                    }
                    namespace SUMMARY_LIST
                    {
                        const AnsiString
                            ENROLLMENT          =
                                Document::NAME::SUMMARY_LIST::ENROLLMENT          +
                                Document::EXTENSION::EXCEL,
                            ENTRANCE_EXAMS      =
                                Document::NAME::SUMMARY_LIST::ENTRANCE_EXAMS      +
                                Document::EXTENSION::EXCEL;
                    }
                }
            }
        #endif  // ! NEW_DOCUMENTS_NAMESPACES
        namespace EducationType
        {
            const AnsiString
                EXTRAMURAL = "заочное",
                INTRAMURAL = "дневное",
                EXTRA_FORM = "заочной",
                INTRA_FORM = "дневной";
        }
        namespace EnvelopeMessage
        {
            namespace BUDGET
            {
                const AnsiString
                    EXTRAMURAL = "бюджет, заочная форма обучения",
                    INTRAMURAL = "бюджет, дневная форма обучения";
            }
            namespace BUYERS
            {
                const AnsiString
                    EXTRAMURAL = "за оплату, заочная форма обучения",
                    INTRAMURAL = "за оплату, дневная форма обучения";
            }
        }
        namespace Faculty
        {
            namespace SHORT
            {
                const AnsiString
                    SMA  = "СИиЕ",                                                      // 1, -> Sports and Marital Arts (СИиЕ)
                    MS   = "МВС",                                                       // 2, -> Mass Sports (МВС)
                    RPC  = "ОФК",                                                       // 3, -> Recreational Physical Culture (ОФКиТ)
                    MSTH = "МСТиГ",                                                     // 4, -> Management of Sports, Tourism and Hospitality (МСиТ)
                    MD   = "Магстратура",                                               // 5, -> Master's Degree (Магстратура)
                    PGS  = "Аспирантура",                                               // 6, -> PostGraduate Studies (Аспирантура)
                    DOC  = "Докторантура";                                              // 7  -> DOCtorate (Докторантура)
            }
            namespace NAME
            {
                const AnsiString
                    SMA  =                                                              // 1, -> Sports and Marital Arts (СИиЕ)
                        "Спортивно-педагогический факультет "   \
                        "спортивных игр и единоборств",
                    MS   =                                                              // 2, -> Mass Sports (МВС)
                        "Спортивно-педагогический факультет "   \
                        "массовых видов спорта",
                    RPC  =                                                              // 3, -> Recreational Physical Culture (ОФКиТ)
                        "Факультет оздоровительной "            \
                        "физической культуры",
                    MSTH =                                                              // 4, -> Management of Sports, Tourism and Hospitality (МСиТ)
                        "Факультет менеджмента спорта, "        \
                        "туризма и гостеприимства",
                    MD   =                                                              // 5, -> Master's Degree (Магстратура)
                        "Магстратура",
                    PGS  =                                                              // 6, -> PostGraduate Studies (Аспирантура)
                        "Аспирантура",
                    DOC  =                                                              // 7  -> DOCtorate (Докторантура)
                        "Докторантура";
            }
        }
        namespace LegallyAuthorizedPerson
        {
            const AnsiString
                DEAN_FACULTY_1 = "В.И.Новицкая",                                        // СИиЕ  (SMA)  - Sports and Marital Arts
                DEAN_FACULTY_2 = "И.И.Гуслистова",                                      // МВС   (MS)   - Mass Sports
                DEAN_FACULTY_3 = "Н.М.Машарская",                                       // ОФКиТ (RPC)  - Recreational Physical Culture
                DEAN_FACULTY_4 = "О.Н.Михайлова",                                       // МСиТ  (MSTH) - Management of Sports, Tourism and Hospitality
                EDU_HEAD_DESC  = "Ермакову А.А.",
                SECRETARY      = "А.И. Лихач",
                SECRETARY_DESC = "Лихач А.И.",
                VICE_RECTOR    = "Г.И.Башлакова";
        }
        namespace PathTo
        {
            const AnsiString
                OUTPUT_DOCUMENTS       = "D:\\Документы приемной комиссии",
                OUTPUT_DOCUMENTS_SLASH = "D:\\Документы приемной комиссии\\";
        }
        namespace Payment
        {
            const AnsiString
                BUDGET = "бюджет",
                BUYERS = "платное";
        }
        namespace SportsRanks
        {
            namespace ABBR
            {
                const AnsiString
                    INTERNATIONAL_MASTER_OF_SPORTS = "МСМК",
                    HONORED_MASTER_OF_SPORTS       = "ЗМС",
                    MASTER_OF_SPORT                = "МС",
                    CANDIDATE_IN_MASTERS_OF_SPORT  = "КМС",
                    FIRST_SPORT_CATEGORY           = "I разряд",
                    SECOND_SPORT_CATEGORY          = "II разряд",
                    THIRD_SPORT_CATEGORY           = "III разряд",
                    FIRST_YOUTH_CATEGORY           = "I юношеский",
                    SECOND_YOUTH_CATEGORY          = "II юношеский",
                    FIRST_APPRENTICESHIP_DEGREE    = "1 кю",
                    SECOND_APPRENTICESHIP_DEGREE   = "2 кю",
                    THIRD_APPRENTICESHIP_DEGREE    = "3 кю",
                    WITHOUT                        = "нет";
            }
            namespace NAME
            {
                const AnsiString
                    INTERNATIONAL_MASTER_OF_SPORTS =                                    // (IMS)
                        "Мастер спорта международного класса (МСМК)",
                    HONORED_MASTER_OF_SPORTS       =                                    // (HMS)
                        "Заслуженный мастер спорта (ЗМС)",
                    MASTER_OF_SPORT                =                                    // (MS)
                        "Мастер спорта (МС)",
                    CANDIDATE_IN_MASTERS_OF_SPORT  =                                    // (CMS)
                        "Кандидат в мастера спорта (КМС)",
                    FIRST_SPORT_CATEGORY           =                                    // (FSC)
                        "I спортивный разряд (I разряд)",
                    SECOND_SPORT_CATEGORY          =                                    // (SSC)
                        "II спортивный разряд (II разряд)",
                    THIRD_SPORT_CATEGORY           =                                    // (TSC)
                        "III спортивный разряд (III разряд)",
                    FIRST_YOUTH_CATEGORY           =                                    // (FYC)
                        "I юношеский разряд (I юношеский)",
                    SECOND_YOUTH_CATEGORY          =                                    // (SYC)
                        "II юношеский разряд (II юношеский)",
                    FIRST_APPRENTICESHIP_DEGREE    =                                    // (FAD)
                        "1-я ученическая степень (1 кю)",
                    SECOND_APPRENTICESHIP_DEGREE   =                                    // (SAD)
                        "2-я ученическая степень (2 кю)",
                    THIRD_APPRENTICESHIP_DEGREE    =                                    // (TAD)
                        "3-я ученическая степень (3 кю)",
                    WITHOUT                        =                                    // (NO)
                        "нет";
            }
        }
        namespace StudyPeriod
        {
            namespace HIGH
            {
                const AnsiString
                    NAME           = "Высшее образование",
                    FULL           = "Полный срок",                                     // t_abitur_queue.term_edu = 0
                    FIRST_COURSE   = "Высшее образование (1 курс)",                     // t_abitur_queue.term_edu = 3
                    SECOND_COURSE  = "Высшее образование (2 курс)",                     // t_abitur_queue.term_edu = 4
                    THIRD_COURSE   = "Высшее образование (3 курс)";                     // t_abitur_queue.term_edu = 5
            }
            namespace SHORT
            {
                const AnsiString
                    NAME          = "Cокращённый срок",
                    SECOND_COURSE = "Cокращённый срок (2 курс)",                        // t_abitur_queue.term_edu = 1
                    THIRD_COURSE  = "Cокращённый срок (3 курс)";                        // t_abitur_queue.term_edu = 2
            }
        }
        #ifndef DATABASE_SUBSTITUTE
            namespace DeaneryDB
            {
                namespace QUALIFICATION
                {
                    const AnsiString
                        TEACHER_PHYSICAL_CULTURE_SPORTS  =
                            "Преподаватель физической культуры и спорта",
                        COACHING_BY_SPORT                =
                            "Тренер по виду спорта",
                        PHYSICAL_EDUCATION_TEACHER       =
                            "Учитель физической культуры",
                        TEACHER_ORGANIZER_HEALTH_TOURISM =
                            "Педагог-организатор физкультурно-оздоровительной "     \
                            "работы и туризма",
                        TEACHER_ORGANIZER_PRESCHOOLERS   =
                            "Педагог-организатор физического воспитания в "         \
                            "дошкольных учреждениях",
                        MANAGER_SPORT_TOURISM            =
                            "Менеджер спорта и туризма",
                        INSTRUCTOR_REHABILITATION        =
                            "Инструктор-методист физической реабилитации",
                        INSTRUCTOR_MEDICAL               =
                            "Инструктор-методист лечебной физической культуры",
                        TEACHER_PHYSICAL_CULTURE         =
                            "Преподаватель физической культуры",
                        INSTRUCTOR_BY_HEALTH             =
                            "Инструктор-методист по оздоровительной физической "    \
                            "культуре",
                        INSTRUCTOR_BY_ADAPTIVE           =
                            "Инструктор-методист по адаптивной физической "         \
                            "культуре",
                        INSTRUCTOR_PRESCHOOLERS          =
                            "Инструктор-методист физического воспитания в "         \
                            "дошкольных учреждениях",
                        PSYCHOLOGIST                     =
                            "Психолог",
                        MANAGER_SPORT                    =
                            "Менеджер в спорте",
                        MANAGER_TUORISM                  =
                            "Менеджер по туризму",
                        INSTRUCTOR_RECREATIONAL          =
                            "Инструктор-методист по туризму",
                        MANAGER_DIRECTING                =
                            "Менеджер-режиссер спортивно-массовых мероприятий",
                        INSTRUCTOR_BY_MEDICAL            =
                            "Инструктор-методист по лечебной физической культуре",
                        INSTRUCTOR_BY_REHABILITATION     =
                            "Инструктор-методист по физической реабилитации",
                        INSTRUCTOR_BY_ERGOTHERAPY        =
                            "Инструктор-методист по эрготерапии",
                        SPECIALIST_TOURISM_HOSPITALITY   =
                            "Специалист в сфере туризма и гостеприимства";
                }
            }
            namespace NCRB_011                                                                  // National Classifier of the Republic of Belarus
            {
                namespace _2009
                {
                    namespace CODE
                    {
                        namespace PART
                        {
                            const AnsiString
                                BIOLOGICAL_SCIENCES            = "03.00.00",                // Master degree
                                PEDAGOGICAL_SCIENCES           = "13.00.00",                // Master degree
                                PEDAGOGY_PROFESSIONAL          = "1-08",                    // Master degree
                                COMMUNICATION_SCIENCES         = "1-26",                    // Master degree
                                PHYSICAL_CULTURE_AND_SPORT     = "1-88",
                                TOURISM_HOSPITALITY            = "1-89";
                        }
                        namespace CHAPTER
                        {
                            const AnsiString
                                PHYSIOLOGY                     = "03.03.01",                // Master degree
                                THEORY_IMPROVING               = "13.00.04",                // Master degree
                                RESEARCH_AND_DEVELOPMENT       = "1-08 80",                 // Master degree
                                MANAGEMENT                     = "1-26 80",                 // Master degree
                                PHYSICAL_CULTURE               = "1-88 01",
                                SPORT                          = "1-88 02",
                                TOURISM_HOSPITALITY            = "1-89 01",
                                TOURISM                        = "1-89 02",
                                HOSPITALITY                    = "1-89 03",
                                RESEARCH_AND_TEACHING          = "1-89 80",                 // Master degree
                                INNOVATION                     = "1-89 81";                 // Master degree
                        }
                        namespace SECTION
                        {
                            const AnsiString
                                RESEARCH_SPORT                 = "1-08 80 04",              // Master degree
                                RESEARCH_MANAGEMENT            = "1-26 80 04",              // Master degree
                                PHYSICAL_CULTURE               = "1-88 01 01",
                                IMPROVING_AND_ADAPTIVE         = "1-88 01 02",
                                REHABILITATION_ERGOTHERAPY     = "1-88 01 03",
                                TRAINING_MILITARY_PERSONNEL    = "1-88 01 04",
                                SPORTS_AND_PEDAGOGY            = "1-88 02 01",
                                SPORTS_CHOREOGRAPHY            = "1-88 02 72",
                                TOURISM_HOSPITALITY            = "1-89 01 01",
                                SPORTS_AND_TOURISM             = "1-89 02 01",
                                TOURISM_AND_NATURE_MANAGEMENT  = "1-89 02 02",
                                HOSPITALITY_TECHNOLOGIES       = "1-89 03 01",
                                RESEARCH_TOURISM_HOSPITALITY   = "1-89 80 01",              // Master degree
                                INNOVATION_MANAGEMENT          = "1-89 81 01",              // Master degree
                                INNOVATION_TOURISM             = "1-89 81 02",              // Master degree
                                INNOVATION_HOSPITALITY         = "1-89 81 03",              // Master degree
                                INNOVATION_TECHNOLOGY          = "1-89 81 04";              // Master degree
                        }
                        namespace SUBSECTION
                        {
                            const AnsiString
                                MEDICAL                       = "1-88 01 01-01",
                                PRESCHOOLERS                  = "1-88 01 01-02",
                                HEALTH                        = "1-88 01 02-01",
                                ADAPTIVE                      = "1-88 01 02-02",
                                REHABILITATION                = "1-88 01 03-01",
                                ERGOTHERAPY                   = "1-88 01 03-02",
                                COACHING                      = "1-88 02 01-01",
                                MANAGEMENT                    = "1-88 02 01-02",
                                PSYCHOLOGY                    = "1-88 02 01-03",
                                DIRECTING                     = "1-88 02 01-04",
                                PROMOTION                     = "1-89 01 01 01",
                                IT                            = "1-89 01 01 02",
                                LOGISTICS                     = "1-89 01 01 03",
                                SOCIAL                        = "1-89 01 01 04",
                                TRANSPORT                     = "1-89 01 01 05",
                                CATERING                      = "1-89 01 01 06",
                                ACCOMMODATION                 = "1-89 01 01 07",
                                SUPPORTING                    = "1-89 01 01 08",
                                TREATMENT                     = "1-89 01 01 09",
                                RECREATIONAL                  = "1-89 02 01-01",
                                TUORISM_MNG                   = "1-89 02 01-02",
                                RESTAURANTS                   = "1-89 03 01-01";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    PHYSIOLOGY  = "03.03.01",
                                    THEORY      = "13.00.04";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT       = "1-08 80 04",
                                    MANAGEMENT  = "1-26 80 04",
                                    TOURISM     = "1-89 80 01";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    MANAGEMENT  = "1-89 81 01",
                                    TOURISM     = "1-89 81 02",
                                    HOSPITALITY = "1-89 81 03",
                                    TECHNO      = "1-89 81 04";
                            }
                        }
                        namespace PHYSICAL_CULTURE
                        {
                            const AnsiString
                                MEDICAL      = "1-88 01 01-01",
                                PRESCHOOLERS = "1-88 01 01-02";
                        }
                        namespace IMPROVING
                        {
                            const AnsiString
                                HEALTH   = "1-88 01 02-01",
                                ADAPTIVE = "1-88 01 02-02";
                        }
                        namespace REHABILITATION
                        {
                            const AnsiString
                                REHABILITATION = "1-88 01 03-01",
                                ERGOTHERAPY    = "1-88 01 03-02";
                        }
                        namespace MILITARY
                        {
                            const AnsiString
                                TRAINING = "1-88 01 04";
                        }
                        namespace SPORT
                        {
                            const AnsiString
                                COACHING   = "1-88 02 01-01",
                                MANAGEMENT = "1-88 02 01-02",
                                PSYCHOLOGY = "1-88 02 01-03",
                                DIRECTING  = "1-88 02 01-04";
                        }
                        namespace TOURISM_HOSPITALITY
                        {
                            const AnsiString
                                PROMOTION     = "1-89 01 01 01",
                                IT            = "1-89 01 01 02",
                                LOGISTICS     = "1-89 01 01 03",
                                SOCIAL        = "1-89 01 01 04",
                                TRANSPORT     = "1-89 01 01 05",
                                CATERING      = "1-89 01 01 06",
                                ACCOMMODATION = "1-89 01 01 07",
                                SUPPORTING    = "1-89 01 01 08",
                                TREATMENT     = "1-89 01 01 09";
                        }
                        namespace TOURISM
                        {
                            const AnsiString
                                RECREATIONAL = "1-89 02 01-01",
                                TUORISM_MNG  = "1-89 02 01-02";
                        }
                        namespace HOSPITALITY
                        {
                            const AnsiString
                                RESTAURANTS = "1-89 03 01-01";
                        }
                    }
                    namespace NAME
                    {
                        namespace PART
                        {
                            const AnsiString
                                BIOLOGICAL_SCIENCES        =                                // Master degree
                                    "Биологические науки",
                                PEDAGOGICAL_SCIENCES       =                                // Master degree
                                    "Педагогические науки",
                                PEDAGOGY_PROFESSIONAL      =                                // Master degree
                                    "Педагогика. Профессиональное образование",
                                COMMUNICATION_SCIENCES     =                                // Master degree
                                    "Управление",
                                PHYSICAL_CULTURE_AND_SPORT =
                                    "Физическая культура и спорт",
                                TOURISM_HOSPITALITY        =
                                    "Туризм. Гостеприимство";
                        }
                        namespace CHAPTER
                        {
                            const AnsiString
                                PHYSIOLOGY               =                                  // Master degree
                                    "Физиология",
                                THEORY_IMPROVING         =                                  // Master degree
                                    "Теория и методика физического воспитания, "        \
                                    "спортивной тренировки, оздоровительной и "         \
                                    "адаптивной физической культуры",
                                RESEARCH_AND_DEVELOPMENT =                                  // Master degree
                                    "Научные исследования и разработки, преподавание",
                                PHYSICAL_CULTURE         =
                                    "Физическая культура",
                                SPORT                    =
                                    "Спорт",
                                TOURISM_HOSPITALITY      =
                                    "Туризм и гостеприимство",
                                TOURISM                  =
                                    "Туризм",
                                HOSPITALITY              =
                                    "Гостеприимство",
                                RESEARCH_AND_TEACHING    =                                  // Master degree
                                    "Научные исследования и разработки, преподавание",
                                INNOVATION                     =                            // Master degree
                                    "Инновационная деятельность (с углубленной "        \
                                    "подготовкой специалистов)";
                        }
                        namespace SECTION
                        {
                            const AnsiString
                                RESEARCH_SPORT                 =                            // Master degree
                                    "Физическая культура и спорт",
                                PHYSICAL_CULTURE              =
                                    "Физическая культура (по направлениям)",
                                IMPROVING_AND_ADAPTIVE        =
                                    "Оздоровительная и адаптивная физическая культура " \
                                    "(по направлениям)",
                                REHABILITATION_ERGOTHERAPY    =
                                    "Физическая реабилитация и эрготерапия "            \
                                    "(по направлениям)",
                                TRAINING_MILITARY_PERSONNEL   =
                                    "Физическая подготовка военнослужащих",
                                SPORTS_AND_PEDAGOGY           =
                                    "Спортивно-педагогическая деятельность",
                                SPORTS_CHOREOGRAPHY           =
                                    "Спортивная хореография",
                                TOURISM_HOSPITALITY       =
                                    "Туризм и гостеприимство",
                                SPORTS_AND_TOURISM            =
                                    "Спортивно-туристская деятельность "                \
                                    "(по направлениям)",
                                TOURISM_AND_NATURE_MANAGEMENT =
                                    "Туризм и природопользование",
                                HOSPITALITY_TECHNOLOGIES      =
                                    "Технология индустрии гостеприимства "              \
                                    "(по направлениям)",
                                TOURISM_HOSPITALITY_STUDY =
                                    "Туризм и гостеприимство",
                                RESEARCH_TOURISM_HOSPITALITY   =                            // Master degree
                                    "Туризм и гостеприимство",
                                INNOVATION_MANAGEMENT          =                            // Master degree
                                    "Управление инновационными проектами в "            \
                                    "туристской индустрии",
                                INNOVATION_TOURISM             =                            // Master degree
                                    "Инновационный менеджмент в сфере туризма",
                                INNOVATION_HOSPITALITY         =                            // Master degree
                                    "Инновационный менеджмент в сфере гостеприимства",
                                INNOVATION_TECHNOLOGY          =                            // Master degree
                                    "Инновационные технологии в сфере туризма и "       \
                                    "гостеприимства";
                        }
                        namespace SUBSECTION
                        {
                            const AnsiString
                                MEDICAL        =
                                    "Физическая культура (лечебная)",
                                PRESCHOOLERS   =
                                    "Физическая культура (дошкольников)",
                                HEALTH         =
                                    "Оздоровительная и адаптивная физическая культура " \
                                    "(оздоровительная)",
                                ADAPTIVE       =
                                    "Оздоровительная и адаптивная физическая культура " \
                                    "(адаптивная)",
                                REHABILITATION =
                                    "Физическая реабилитация и эрготерапия "            \
                                    "(физическая реабилитация)",
                                ERGOTHERAPY    =
                                    "Физическая реабилитация и эрготерапия "            \
                                    "(эрготерапия)",
                                COACHING       =
                                    "Спортивно-педагогическая деятельность "            \
                                    "(тренерская работа с указанием вида спорта)",
                                MANAGEMENT     =
                                    "Спортивно-педагогическая деятельность "            \
                                    "(менеджмент в спорте)",
                                PSYCHOLOGY     =
                                    "Спортивно-педагогическая деятельность "            \
                                    "(спортивная психология)",
                                DIRECTING      =
                                    "Спортивно-педагогическая деятельность "            \
                                    "(спортивная режиссура)",
                                PROMOTION      =
                                    "Технологии формирования и продвижения "            \
                                    "туристических услуг",
                                IT             =
                                    "Информационные технологии туристической "          \
                                    "индустрии",
                                LOGISTICS      =
                                    "Логистика в туристической индустрии",
                                SOCIAL         =
                                    "Технологии социокультурного сервиса туристов",
                                TRANSPORT      =
                                    "Технологии транспортного сервиса туристов",
                                CATERING       =
                                    "Технологии сервиса питания туристов",
                                ACCOMMODATION  =
                                    "Технологии сервиса размещения туристов",
                                SUPPORTING     =
                                    "Технологии экскурсионно-сопроводительного "        \
                                    "сервиса туристов",
                                TREATMENT      =
                                    "Технологии сервиса оздоровления и лечения "        \
                                    "туристов",
                                RECREATIONAL   =
                                    "Спортивно-туристская деятельность "                \
                                    "(спортивный и рекреационный туризм)",
                                TUORISM_MNG    =
                                    "Спортивно-туристская деятельность "                \
                                    "(менеджмент в туризме)",
                                RESTAURANTS    =
                                    "Технология индустрии гостеприимства "              \
                                    "(ресторанная деятельность)";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    PHYSIOLOGY  =
                                        "Физиология",
                                    THEORY      =
                                        "Теория и методика физического воспитания, "    \
                                        "спортивной тренировки, оздоровительной и "     \
                                        "адаптивной физической культуры";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT       =
                                        "Физическая культура и спорт",
                                    MANAGEMENT  =
                                        "Менеджмент",
                                    TOURISM     =
                                        "Туризм и гостеприимство";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    MANAGEMENT  =
                                        "Управление инновационными проектами в "        \
                                        "туристской индустрии",
                                    TOURISM     =
                                        "Инновационный менеджмент в сфере туризма",
                                    HOSPITALITY =
                                        "Инновационный менеджмент в сфере "             \
                                        "гостеприимства",
                                    TECHNO  =
                                        "Инновационные технологии в сфере туризма и "   \
                                        "гостеприимства";
                            }
                        }
                        namespace PHYSICAL_CULTURE
                        {
                            const AnsiString
                                MEDICAL        = "Физическая культура (лечебная)",
                                PRESCHOOLERS   = "Физическая культура (дошкольников)";
                        }
                        namespace IMPROVING
                        {
                            const AnsiString
                                HEALTH         =
                                    "Оздоровительная и адаптивная физическая культура " \
                                    "(оздоровительная)",
                                ADAPTIVE       =
                                    "Оздоровительная и адаптивная физическая культура " \
                                    "(адаптивная)";
                        }
                        namespace REHABILITATION
                        {
                            const AnsiString
                                REHABILITATION =
                                    "Физическая реабилитация и эрготерапия "            \
                                    "(физическая реабилитация)",
                                ERGOTHERAPY    =
                                    "Физическая реабилитация и эрготерапия "            \
                                    "(эрготерапия)";
                        }
                        namespace MILITARY
                        {
                            const AnsiString
                                TRAINING       = "Физическая подготовка военнослужащих";
                        }
                        namespace SPORT
                        {
                            const AnsiString
                                COACHING       =
                                    "Спортивно-педагогическая деятельность "            \
                                    "(тренерская работа с указанием вида спорта)",
                                MANAGEMENT     =
                                    "Спортивно-педагогическая деятельность "            \
                                    "(менеджмент в спорте)",
                                PSYCHOLOGY     =
                                    "Спортивно-педагогическая деятельность "            \
                                    "(спортивная психология)",
                                DIRECTING      =
                                    "Спортивно-педагогическая деятельность "            \
                                    "(спортивная режиссура)";
                        }
                        namespace TOURISM_HOSPITALITY
                        {
                            const AnsiString
                                PROMOTION      =
                                    "Технологии формирования и продвижения "            \
                                    "туристических услуг",
                                IT             =
                                    "Информационные технологии туристической индустрии",
                                LOGISTICS      =
                                    "Логистика в туристической индустрии",
                                SOCIAL         =
                                    "Технологии социокультурного сервиса туристов",
                                TRANSPORT      =
                                    "Технологии транспортного сервиса туристов",
                                CATERING       =
                                    "Технологии сервиса питания туристов",
                                ACCOMMODATION  =
                                    "Технологии сервиса размещения туристов",
                                SUPPORTING     =
                                    "Технологии экскурсионно-сопроводительного "        \
                                    "сервиса туристов",
                                TREATMENT      =
                                    "Технологии сервиса оздоровления и лечения "        \
                                    "туристов";
                        }
                        namespace TOURISM
                        {
                            const AnsiString
                                RECREATIONAL   =
                                    "Спортивно-туристская деятельность "                \
                                    "(спортивный и рекреационный туризм)",
                                TUORISM_MNG    =
                                    "Спортивно-туристская деятельность "                \
                                    "(менеджмент в туризме)";
                        }
                        namespace HOSPITALITY
                        {
                            const AnsiString
                                RESTAURANTS    =
                                    "Технология индустрии гостеприимства "              \
                                    "(ресторанная деятельность)";
                        }
                    }
                    namespace QUALIFICATION
                    {
                        namespace SUBSECTION
                        {
                            const AnsiString
                                MEDICAL        =
                                    "Инструктор-методист по лечебной физической "       \
                                    "культуре. Преподаватель физической культуры",
                                PRESCHOOLERS   =
                                    "Инструктор-методист физического воспитания в "     \
                                    "дошкольных учреждениях. "                          \
                                    "Преподаватель физической культуры",
                                HEALTH         =
                                    "Инструктор-методист по оздоровительной "           \
                                    "физической культуре. "                             \
                                    "Преподаватель физической культуры",
                                ADAPTIVE       =
                                    "Инструктор-методист по адаптивной "                \
                                    "физической культуре. "                             \
                                    "Преподаватель физической культуры",
                                REHABILITATION =
                                    "Инструктор-методист по физической "                \
                                    "реабилитации. "                                    \
                                    "Преподаватель физической культуры",
                                ERGOTHERAPY    =
                                    "Инструктор-методист по эрготерапии. "              \
                                    "Преподаватель физической культуры",
                                TRAINING       =
                                    "Специалист по управлению. "                        \
                                    "Инструктор-методист по физической "                \
                                    "подготовке",
                                COACHING       =
                                    "Тренер (по виду спорта). "                         \
                                    "Преподаватель физической культуры",
                                MANAGEMENT     =
                                    "Менеджер в спорте. "                               \
                                    "Преподаватель физической культуры",
                                PSYCHOLOGY     =
                                    "Психолог. "                                        \
                                    "Преподаватель физической культуры",
                                DIRECTING      =
                                    "Менеджер-режиссер спортивно-массовых "             \
                                    "мероприятий."                                      \
                                    "Преподаватель физической культуры",
                                PROMOTION      =
                                    "Специалист в сфере туризма и гостеприимства",
                                IT             =
                                    "Специалист в сфере туризма и гостеприимства",
                                LOGISTICS      =
                                    "Специалист в сфере туризма и гостеприимства",
                                SOCIAL         =
                                    "Специалист в сфере туризма и гостеприимства",
                                TRANSPORT      =
                                    "Специалист в сфере туризма и гостеприимства",
                                CATERING       =
                                    "Специалист в сфере туризма и гостеприимства",
                                ACCOMMODATION  =
                                    "Специалист в сфере туризма и гостеприимства",
                                SUPPORTING     =
                                    "Специалист в сфере туризма и гостеприимства",
                                TREATMENT      =
                                    "Специалист в сфере туризма и гостеприимства",
                                RECREATIONAL   =
                                    "Инструктор-методист по туризму. "                  \
                                    "Преподаватель физической культуры",
                                TUORISM_MNG    =
                                    "Менеджер по туризму. "                             \
                                    "Преподаватель физической культуры",
                                RESTAURANTS    = "Менеджер. Технолог";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    PHYSIOLOGY  = "Магистр",
                                    THEORY      = "Магистр";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT       = "Магистр",
                                    MANAGEMENT  = "Магистр",
                                    TOURISM     = "Магистр";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    MANAGEMENT  = "Магистр",
                                    TOURISM     = "Магистр",
                                    HOSPITALITY = "Магистр",
                                    TECHNO      = "Магистр";
                            }
                        }
                        namespace PHYSICAL_CULTURE
                        {
                            const AnsiString
                                MEDICAL        =
                                    "Инструктор-методист по лечебной физической "       \
                                    "культуре. Преподаватель физической культуры",
                                PRESCHOOLERS   =
                                    "Инструктор-методист физического воспитания в "     \
                                    "дошкольных учреждениях. "                          \
                                    "Преподаватель физической культуры";
                        }
                        namespace IMPROVING
                        {
                            const AnsiString
                                HEALTH         =
                                    "Инструктор-методист по оздоровительной "           \
                                    "физической культуре. "                             \
                                    "Преподаватель физической культуры",
                                ADAPTIVE       =
                                    "Инструктор-методист по адаптивной "                \
                                    "физической культуре. "                             \
                                    "Преподаватель физической культуры";
                        }
                        namespace REHABILITATION
                        {
                            const AnsiString
                                REHABILITATION =
                                    "Инструктор-методист по физической "                \
                                    "реабилитации. "                                    \
                                    "Преподаватель физической культуры",
                                ERGOTHERAPY    =
                                    "Инструктор-методист по эрготерапии. "              \
                                    "Преподаватель физической культуры";
                        }
                        namespace MILITARY
                        {
                            const AnsiString
                                TRAINING       =
                                    "Специалист по управлению. "                        \
                                    "Инструктор-методист по физической "                \
                                    "подготовке";
                        }
                        namespace SPORT
                        {
                            const AnsiString
                                COACHING       =
                                    "Тренер (по виду спорта). "                         \
                                    "Преподаватель физической культуры",
                                MANAGEMENT     =
                                    "Менеджер в спорте. "                               \
                                    "Преподаватель физической культуры",
                                PSYCHOLOGY     =
                                    "Психолог. "                                        \
                                    "Преподаватель физической культуры",
                                DIRECTING      =
                                    "Менеджер-режиссер спортивно-массовых "             \
                                    "мероприятий."                                      \
                                    "Преподаватель физической культуры";
                        }
                        namespace TOURISM_HOSPITALITY
                        {
                            const AnsiString
                                PROMOTION      =
                                    "Специалист в сфере туризма и гостеприимства",
                                IT             =
                                    "Специалист в сфере туризма и гостеприимства",
                                LOGISTICS      =
                                    "Специалист в сфере туризма и гостеприимства",
                                SOCIAL         =
                                    "Специалист в сфере туризма и гостеприимства",
                                TRANSPORT      =
                                    "Специалист в сфере туризма и гостеприимства",
                                CATERING       =
                                    "Специалист в сфере туризма и гостеприимства",
                                ACCOMMODATION  =
                                    "Специалист в сфере туризма и гостеприимства",
                                SUPPORTING     =
                                    "Специалист в сфере туризма и гостеприимства",
                                TREATMENT      =
                                    "Специалист в сфере туризма и гостеприимства";
                        }
                        namespace TOURISM
                        {
                            const AnsiString
                                RECREATIONAL   =
                                    "Инструктор-методист по туризму. "                  \
                                    "Преподаватель физической культуры",
                                TUORISM_MNG    =
                                    "Менеджер по туризму. "                             \
                                    "Преподаватель физической культуры";
                        }
                        namespace HOSPITALITY
                        {
                            const AnsiString
                                RESTAURANTS    = "Менеджер. Технолог";
                        }
                    }
                }
                namespace _2022
                {
                    namespace CODE
                    {
                        const AnsiString
                            PHYSIOLOGY       = "03.03.01",                                  // Master degree
                            THEORY_IMPROVING = "13.00.04",                                  // Master degree
                            INNO_MANAGEMENT  = "1-89 81 01",                                // Master degree
                            INNO_TOURISM     = "1-89 81 02",                                // Master degree
                            INNO_HOSPITALITY = "1-89 81 03",                                // Master degree
                            INNO_TECHNOLOGY  = "1-89 81 04",                                // Master degree
                            PHYSICAL_CULTURE = "6-05-1012-01",
                            COACHING         = "6-05-1012-02",
                            REHABILITATION   = "6-05-1012-03",
                            MANAGEMENT       = "6-05-1012-04",
                            TOURISM          = "6-05-1013-01",
                            NATURE           = "6-05-1013-03",
                            HOSPITALITY      = "6-05-1013-04",
                            MNG_MASTER_DEGREE = "7-06-0412-01",
                            PC_MASTER_DEGREE = "7-06-1012-01",                              // Master degree
                            TH_MASTER_DEGREE = "7-06-1013-01",                              // Master degree
                            CHOREOGRAPHY     = "9-09-1012-04";                              // Master degree
                    }
                    namespace NAME
                    {
                        const AnsiString
                            PHYSIOLOGY       =                                              // Master degree
                                "Физиология",
                            THEORY_IMPROVING =                                              // Master degree
                                "Теория и методика физического воспитания, "        \
                                "спортивной тренировки, оздоровительной и "         \
                                "адаптивной физической культуры",
                            INNO_MANAGEMENT  =                                              // Master degree
                                "Управление инновационными проектами в "            \
                                "туристской индустрии",
                            INNO_TOURISM     =                                              // Master degree
                                "Инновационный менеджмент в сфере туризма",
                            INNO_HOSPITALITY =                                              // Master degree
                                "Инновационный менеджмент в сфере гостеприимства",
                            INNO_TECHNOLOGY  =                                              // Master degree
                                "Инновационные технологии в сфере туризма и "       \
                                "гостеприимства",
                            PHYSICAL_CULTURE =
                                "Физическая культура",
                            COACHING         =
                                "Тренерская деятельность",
                            REHABILITATION   =
                                "Физическая реабилитация и эрготерапия",
                            MANAGEMENT       =
                                "Организация и управление физической культурой, "   \
                                "спортом и туризмом",
                            TOURISM          =
                                "Туризм и гостеприимство",
                            NATURE           =
                                "Туризм и природопользование",
                            HOSPITALITY      =
                                "Технология индустрии гостеприимства",
                            PC_MASTER_DEGREE =                                              // Master degree
                                "Физическая культура и спорт",
                            TH_MASTER_DEGREE =                                              // Master degree
                                "Туризм и гостеприимство",
                            CHOREOGRAPHY     =
                                "Спортивная хореография";

                        namespace PHYSICAL
                        {
                            const AnsiString
                                IMPROVING      = "(оздоровительная)",                       // "(оздоровительная физическая культура)",
                                HEALTH         = "(лечебная)",                              // "(лечебная физическая культура)",
                                PRESCHOOLERS   = "(дошкольников)",                          // "(физическая культура дошкольников)",
                                ADAPTIVE       = "(адаптивная)",                            // "(адаптивная физическая культура)",
                                DIRECTING      = "(спортивная режиссура)",
                                PSYCHOLOGY     = "(спортивная психология)",
                                RECREATIONAL   = "(спортивный и рекреационный туризм)";
                        }
                        namespace COACH
                        {
                            const AnsiString
                                DEFAULT        = "(с указанием вида спорта)";
                        }
                        namespace REHABILITATE
                        {
                            const AnsiString
                                REHABILITATION = "(физическая реабилитация)",
                                ERGOTHERAPY    = "(эрготерапия)";
                        }
                        namespace MANAGE
                        {
                            const AnsiString
                                SPORT          = "(менеджмент в спорте)",
                                TOURISM        = "(менеджмент в туризме)";
                        }
                    }
                    namespace QUALIFICATION
                    {
                        const AnsiString
                            PHYSIOLOGY       = "Магистр",                                   // Master degree
                            THEORY_IMPROVING = "Магистр",                                   // Master degree
                            INNO_MANAGEMENT  = "Магистр управления",                        // Master degree
                            INNO_TOURISM     = "Магистр туризма",                           // Master degree
                            INNO_HOSPITALITY = "Магистр гостеприимства",                    // Master degree
                            INNO_TECHNOLOGY  = "Магистр инноваций",                         // Master degree
                            PHYSICAL_CULTURE = "Инструктор-методист. Преподаватель",
                            COACHING         = "Тренер. Преподаватель",
                            REHABILITATION   = "Инструктор-методист. Преподаватель",
                            MANAGEMENT       = "Менеджер. Преподаватель",
                            TOURISM          = "Специалист",
                            NATURE           = "Специалист по туризму и природопользованию",
                            HOSPITALITY      = "Менеджер. Технолог",
                            PC_MASTER_DEGREE = "Магистр",                                   // Master degree
                            TH_MASTER_DEGREE = "Магистр",                                   // Master degree
                            CHOREOGRAPHY     = "Инструктор-методист";
                    }
                }
            }
            namespace KindOfSport
            {
                const AnsiString
                    GYMNASTICS                   =
                        "Гимнастика",
                    MANAGEMENT_SPORTS_TOURISM    =
                        "Менеджмент спорта и туризма",
                    PHYSICAL_REHABILITATION      =
                        "Физическая реабилитация",
                    THERAPEUTIC                  =
                        "Лечебная физическая культура",
                    ORGANIZATION_SPORTS_TOURISM  =
                        "Организация физкультурно-оздоровительной "         \
                        "работы и туризма",
                    PRESCHOOL_PHYSICAL_EDUCATION =
                        "Дошкольное физическое воспитание",
                    DANCE_SPORT                  =
                        "Танцевальный спорт",
                    AEROBICS                     =
                        "Аэробика",
                    ROWING_OTHER                 =
                        "Гребной спорт",
                    SWIMMING                     =
                        "Плавание",
                    SAILING                      =
                        "Парусный спорт",
                    ATHLETICS                    =
                        "Легкая атлетика",
                    CROSS_COUNTRY_SKIING         =
                        "Лыжные гонки",
                    BULLET_SHOOTING_DEANERY      =
                        "Пулевая стрельба",
                    HAND_TO_HAND_COMBAT          =
                        "Рукопашный бой",
                    TAEKWONDO                    =
                        "Таэквондо",
                    KARATE                       =
                        "Каратэ",
                    SKIING                       =
                        "Лыжный спорт",
                    AUTOMOTIVE_SPORT             =
                        "Автомобильный спорт",
                    BASKETBALL                   =
                        "Баскетбол",
                    BOXING                       =
                        "Бокс",
                    GRECO_FREESTYLE_WRESTLING    =
                        "Греко-римская и вольная борьба",
                    CYCLING                      =
                        "Велосипедный спорт",
                    VOLLEYBALL                   =
                        "Волейбол",
                    HANDBALL                     =
                        "Гандбол",
                    EQUESTRIAN                   =
                        "Конный спорт",
                    SPEED_SKATING                =
                        "Конькобежный спорт",
                    TENNIS                       =
                        "Теннис",
                    WEIGHTLIFTING                =
                        "Тяжелая атлетика",
                    FENCING                      =
                        "Фехтование",
                    FIGURE_SKATING_OLD           =
                        "Фигурное катание",
                    FOOTBALL                     =
                        "Футбол",
                    HOCKEY                       =
                        "Хоккей",
                    SAMBO_JUDO                   =
                        "Самбо-дзюдо",
                    WRESTLING                    =
                        "Спортивная борьба",
                    FOOTBALL_HOCKEY              =
                        "Футбол и хоккей",
                    BIATHLON                     =
                        "Биатлон",
                    HEALTH_IMPROVING             =
                        "Оздоровительная физическая культура",
                    ADAPTIVE                     =
                        "Адаптивная физическая культура",
                    FREESTYLE_WRESTLING          =
                        "Вольная борьба",
                    GRECO_ROMAN_WRESTLING        =
                        "Греко-римская борьба",
                    SAMBO                        =
                        "Самбо",
                    JUDO                         =
                        "Дзюдо",
                    TABLE_TENNIS_ABITURIENT      =
                        "Теннис настольный",
                    ERGOTHERAPY                  =
                        "Эрготерапия",
                    MANAGEMENT_SPORTS            =
                        "Менеджмент в спорте",
                    SPORTS_DIRECTING_DEANERY     =
                        "Спортивная режиссура",
                    SPORTS_RECREATIONAL_TOURISM  =
                        "Спортивный и рекреационный туризм",
                    MANAGEMENT_TOURISM           =
                        "Менеджмент в туризме",
                    SPORTS_PSYCHOLOGY            =
                        "Спортивная психология",
                    BILLIARD_SPORTS              =
                        "Бильярдный спорт",
                    ACROBATICS                   =
                        "Акробатика",
                    ORIENTEERING                 =
                        "Спортивное ориентирование",
                    SPORTS_DIRECTING             =
                        "Спортивная режиссура",
                    PRESCHOOLERS                 =
                        "Физическая культура дошкольников",
                    MOUNTAINEERING               =
                        "Альпинизм",
                    SKI_COMBINED                 =
                        "Лыжное двоеборье",
                    TOURISM_HOSPITALITY          =
                        "Туризм и гостеприимство",
                    WATER_TECHNICAL_SPORTS       =
                        "Водно-технические виды спорта",
                    MODEL_TECHNICAL_SPORTS       =
                        "Модельно-технические виды спорта",
                    ALPINE_SKIING                =
                        "Горнолыжный спорт",
                    BASEBALL                     =
                        "Бейсбол",
                    WUSHU                        =
                        "Ушу",
                    CHESS                        =
                        "Шахматы",
                    THAI_BOXING                  =
                        "Таиландский бокс",
                    TOURISM_PROMOTION            =
                        "Технологии формирования и продвижения "            \
                        "туристических услуг",
                    TOURISM_IT                   =
                        "Информационные технологии туристической "          \
                        "индустрии",
                    TOURISM_LOGISTICS            =
                        "Логистика в туристической индустрии",
                    TOURISM_SOCIAL               =
                        "Технологии социокультурного сервиса "              \
                        "туристов",
                    TOURISM_TRANSPORT            =
                        "Технологии транспортного сервиса туристов",
                    TOURISM_FOOD                 =
                        "Технологии сервиса питания туристов",
                    TOURIST_ACCOMMODATION        =
                        "Технологии сервиса размещения туристов",
                    TOURISM_EXCURSION            =
                        "Технологии экскурсионно-сопроводительного "        \
                        "сервиса туристов",
                    TOURISM_HEALTH               =
                        "Технологии сервиса оздоровления и лечения "        \
                        "туристов",
                    BULLET_SHOOTING              =
                        "Стрельба пулевая",
                    FIELD_HOCKEY                 =
                        "Хоккей на траве",
                    FIGURE_SKATING               =
                        "Фигурное катание на коньках",
                    ROWING_AND_CANOEING          =
                        "Гребля на байдарках и каноэ",
                    ACADEMIC_ROWING              =
                        "Гребля академическая",
                    HAND_TO_HAND_COMBAT_MS       =
                        "Рукопашный бой (смешанные единоборства)",
                    BILLIARDS_RPC                =
                        "Бильярд",
                    WITHOUT_SPECIALIZATION       =
                        "Без специализации",
                    MEDICAL                      =
                        "Физическая культура(лечебная)",
                    MODERN_PENTATHLON            =
                        "Современное пятиборье",
                    SCIENCE_HEALTH               =
                        "теория и методика физического воспитания, "        \
                        "спортивной тренировки, оздоровительной",
                    PHYSIOLOGY                   =
                        "физиология",
                    SCIENCE_THEORY               =
                        "теория и методика физического воспитания, "        \
                        "спортивной тренировки, оздоровительной",
                    RECEARCH_SPORT               =
                        "теория и методика физического воспитания, "        \
                        "спортивной тренировки, оздоровительной",
                    INNOVATIVE_TOURISM           =
                        "инновационный менеджмент в сфере туризма",
                    INNOVATIVE_HOSPITALITY       =
                        "инновационный менеджмент в сфере гостеприимства",
                    INNOVATIVE_TECHNOLOGIES      =
                        "инновационные технологии в сфере туризма "         \
                        "и гостеприимства",
                    INNOVATIVE_MANAGEMENT        =
                        "управление инновационными проектами в "            \
                        "туристской индустрии",
                    BILLIARDS_SMA                =
                        "Бильярд",
                    HAND_TO_HAND_COMBAT_SMA      =
                        "Рукопашный бой (смешанные единоборства)",
                    BADMINTON                    =
                        "Бадминтон",
                    TABLE_TENNIS_DEANERY         =
                        "Настольный теннис",
                    PHYSICAL_CULTURE_SPORT       =
                        "Физическая культура и спорт",
                    TOURISM_HOSPITALITY_MASTER   =
                        "Туризм и гостеприимство",
                    SPORT_CLIMBING               =
                        "Скалолазание спортивное",
                    MASTER_ANTHROPOLOGY          =
                        "антропология",
                    MASTER_MANAGEMENT            =
                        "Менеджмент",
                    MASTER_PHYSICAL_CULTURE      =
                        "Физическая культура и спорт";

                namespace DATIVE_CASE
                {
                    const AnsiString
                        GYMNASTICS                   =
                            "гимнастике",
                        MANAGEMENT_SPORTS_TOURISM    =
                            "менеджменту спорта и туризма",
                        PHYSICAL_REHABILITATION      =
                            "физическая реабилитации",
                        THERAPEUTIC                  =
                            "лечебной физическая культура",
                        ORGANIZATION_SPORTS_TOURISM  =
                            "организации физкультурно-оздоровительной "         \
                            "работы и туризма",
                        PRESCHOOL_PHYSICAL_EDUCATION =
                            "дошкольному физическому воспитанию",
                        DANCE_SPORT                  =
                            "танцевальному спорту",
                        AEROBICS                     =
                            "аэробике",
                        ROWING_OTHER                 =
                            "гребному спорту",
                        SWIMMING                     =
                            "плаванию",
                        SAILING                      =
                            "парусному спорту",
                        ATHLETICS                    =
                            "легкой атлетике",
                        CROSS_COUNTRY_SKIING         =
                            "лыжным гонкам",
                        BULLET_SHOOTING_DEANERY      =
                            "пулевой стрельбе",
                        HAND_TO_HAND_COMBAT          =
                            "рукопашному бою",
                        TAEKWONDO                    =
                            "таэквондо",
                        KARATE                       =
                            "каратэ",
                        SKIING                       =
                            "лыжному спорту",
                        AUTOMOTIVE_SPORT             =
                            "автомобильному спорту",
                        BASKETBALL                   =
                            "баскетболу",
                        BOXING                       =
                            "боксу",
                        GRECO_FREESTYLE_WRESTLING    =
                            "греко-римской и вольной борьбе",
                        CYCLING                      =
                            "велосипедному спорту",
                        VOLLEYBALL                   =
                            "волейболу",
                        HANDBALL                     =
                            "гандболу",
                        EQUESTRIAN                   =
                            "конному спорту",
                        SPEED_SKATING                =
                            "конькобежному спорту",
                        TENNIS                       =
                            "теннису",
                        WEIGHTLIFTING                =
                            "тяжелой атлетике",
                        FENCING                      =
                            "фехтованию",
                        FIGURE_SKATING_OLD           =
                            "фигурному катанию",
                        FOOTBALL                     =
                            "футболу",
                        HOCKEY                       =
                            "хоккею",
                        SAMBO_JUDO                   =
                            "самбо-дзюдо",
                        WRESTLING                    =
                            "спортивной борьбе",
                        FOOTBALL_HOCKEY              =
                            "футболу и хоккею",
                        BIATHLON                     =
                            "биатлону",
                        HEALTH_IMPROVING             =
                            "оздоровительной физической культуре",
                        ADAPTIVE                     =
                            "адаптивной физической культуре",
                        FREESTYLE_WRESTLING          =
                            "вольной борьбе",
                        GRECO_ROMAN_WRESTLING        =
                            "греко-римской борьбе",
                        SAMBO                        =
                            "самбо",
                        JUDO                         =
                            "дзюдо",
                        TABLE_TENNIS_ABITURIENT      =
                            "теннису настольному",
                        ERGOTHERAPY                  =
                            "эрготерапии",
                        MANAGEMENT_SPORTS            =
                            "менеджменту в спорте",
                        SPORTS_DIRECTING_DEANERY     =
                            "спортивной режиссуре",
                        SPORTS_RECREATIONAL_TOURISM  =
                            "спортивному и рекреационному туризму",
                        MANAGEMENT_TOURISM           =
                            "менеджменту в туризме",
                        SPORTS_PSYCHOLOGY            =
                            "спортивной психологии",
                        BILLIARD_SPORTS              =
                            "бильярдному спорту",
                        ACROBATICS                   =
                            "акробатике",
                        ORIENTEERING                 =
                            "спортивному ориентированию",
                        SPORTS_DIRECTING             =
                            "спортивной режиссуре",
                        PRESCHOOLERS                 =
                            "физической культуре дошкольников",
                        MOUNTAINEERING               =
                            "альпинизму",
                        SKI_COMBINED                 =
                            "лыжному двоеборью",
                        TOURISM_HOSPITALITY          =
                            "туризму и гостеприимству",
                        WATER_TECHNICAL_SPORTS       =
                            "водно-техническим видам спорта",
                        MODEL_TECHNICAL_SPORTS       =
                            "модельно-техническим видам спорта",
                        ALPINE_SKIING                =
                            "горнолыжному спорту",
                        BASEBALL                     =
                            "бейсболу",
                        WUSHU                        =
                            "ушу",
                        CHESS                        =
                            "шахматам",
                        THAI_BOXING                  =
                            "таиландскому боксу",
                        TOURISM_PROMOTION            =
                            "технологиям формирования и продвижения "            \
                            "туристических услуг",
                        TOURISM_IT                   =
                            "информационным технологиям туристической "          \
                            "индустрии",
                        TOURISM_LOGISTICS            =
                            "логистике в туристической индустрии",
                        TOURISM_SOCIAL               =
                            "технологиям социокультурного сервиса "              \
                            "туристов",
                        TOURISM_TRANSPORT            =
                            "технологиям транспортного сервиса туристов",
                        TOURISM_FOOD                 =
                            "технологиям сервиса питания туристов",
                        TOURIST_ACCOMMODATION        =
                            "технологиям сервиса размещения туристов",
                        TOURISM_EXCURSION            =
                            "технологиям экскурсионно-сопроводительного "        \
                            "сервиса туристов",
                        TOURISM_HEALTH               =
                            "технологиям сервиса оздоровления и лечения "        \
                            "туристов",
                        BULLET_SHOOTING              =
                            "стрельбе пулевой",
                        FIELD_HOCKEY                 =
                            "хоккею на траве",
                        FIGURE_SKATING               =
                            "фигурному катанию на коньках",
                        ROWING_AND_CANOEING          =
                            "гребле на байдарках и каноэ",
                        ACADEMIC_ROWING              =
                            "гребле академической",
                        HAND_TO_HAND_COMBAT_MS       =
                            "рукопашному бою (смешанные единоборства)",
                        BILLIARDS_RPC                =
                            "бильярду",
                        WITHOUT_SPECIALIZATION       =
                            "без специализации",
                        MEDICAL                      =
                            "физической культуре (лечебной)",
                        MODERN_PENTATHLON            =
                            "современному пятиборью",
                        SCIENCE_HEALTH               =
                            "теории и методике физического воспитания, "        \
                            "спортивной тренировки, оздоровительной",
                        PHYSIOLOGY                   =
                            "физиологии",
                        SCIENCE_THEORY               =
                            "теории и методике физического воспитания, "        \
                            "спортивной тренировки, оздоровительной",
                        RECEARCH_SPORT               =
                            "теории и методике физического воспитания, "        \
                            "спортивной тренировки, оздоровительной",
                        INNOVATIVE_TOURISM           =
                            "инновационному менеджменту в сфере туризма",
                        INNOVATIVE_HOSPITALITY       =
                            "инновационному менеджменту в сфере гостеприимства",
                        INNOVATIVE_TECHNOLOGIES      =
                            "инновационным технологиям в сфере туризма "         \
                            "и гостеприимства",
                        INNOVATIVE_MANAGEMENT        =
                            "управлению инновационными проектами в "            \
                            "туристской индустрии",
                        BILLIARDS_SMA                =
                            "бильярду",
                        HAND_TO_HAND_COMBAT_SMA      =
                            "рукопашному бою (смешанные единоборства)",
                        BADMINTON                    =
                            "бадминтону",
                        TABLE_TENNIS_DEANERY         =
                            "настольному теннису",
                        PHYSICAL_CULTURE_SPORT       =
                            "физической культуре и спорту",
                        TOURISM_HOSPITALITY_MASTER   =
                            "туризму и гостеприимству",
                        SPORT_CLIMBING               =
                            "спортивному скалолазанию",
                        MASTER_ANTHROPOLOGY          =
                            "антропологии",
                        MASTER_MANAGEMENT            =
                            "менеджменту",
                        MASTER_PHYSICAL_CULTURE      =
                            "физической культуре и спорту";
                }
            }
        #else
            namespace NCRB_011                                                              // National Classifier of the Republic of Belarus
            {
                namespace _2009
                {
                    namespace CODE
                    {
                        namespace HIGH_SCHOOL
                        {
                            namespace SPORT
                            {
                                const AnsiString
                                    COACHING   = "1-88 02 01-01",
                                    PSYCHOLOGY = "1-88 02 01-03",
                                    DIRECTING  = "1-88 02 01-04",
                                    MANAGEMENT = "1-88 02 01-02";
                            }
                            namespace MANAGEMENT
                            {
                                const AnsiString
                                    RECREATIONAL = "1-89 02 01-01",
                                    TUORISM_MNG  = "1-89 02 01-02";
                            }
                            namespace PHYSICAL_CULTURE
                            {
                                const AnsiString
                                    MEDICAL      = "1-88 01 01-01",
                                    PRESCHOOLERS = "1-88 01 01-02";
                            }
                            namespace IMPROVING
                            {
                                const AnsiString
                                    HEALTH   = "1-88 01 02-01",
                                    ADAPTIVE = "1-88 01 02-02";
                            }
                            namespace REHABILITATION
                            {
                                const AnsiString
                                    REHABILITATION = "1-88 01 03-01",
                                    ERGOTHERAPY    = "1-88 01 03-02";
                            }
                            namespace TOURISM
                            {
                                const AnsiString
                                    HOSPITALITY   = "1-89 01 01",
                                    PROMOTION     = "1-89 01 01 01",
                                    IT            = "1-89 01 01 02",
                                    LOGISTICS     = "1-89 01 01 03",
                                    SOCIAL        = "1-89 01 01 04",
                                    TRANSPORT     = "1-89 01 01 05",
                                    CATERING      = "1-89 01 01 06",
                                    ACCOMMODATION = "1-89 01 01 07",
                                    SUPPORTING    = "1-89 01 01 08",
                                    TREATMENT     = "1-89 01 01 09";
                            }
                        }
                        namespace SERVICE
                        {
                            const AnsiString
                                RESTAURANTS = "1-89 03 01-01";
                        }
                        namespace MILITARY
                        {
                            const AnsiString
                                TRAINING = "1-88 01 04";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           = "13.00.04",
                                    PHYSIOLOGY       = "03.03.01";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM          = "1-89 81 02",
                                    HOSPITALITY      = "1-89 81 03",
                                    TECHNOLOGIES     = "1-89 81 04",
                                    MANAGEMENT       = "1-89 81 01";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            = "1-08 80 04",
                                    PHYSICAL_CULTURE = "1-89 80 01",
                                    MANAGEMENT       = "1-26 80 04",
                                    TOURISM          = "1-89 80 01";
                            }
                        }
                    }
                    namespace SECTION
                    {
                        namespace HIGH_SCHOOL
                        {
                            const AnsiString
                                IMPROVING         =
                                    "Оздоровительная и адаптивная физическая "          \
                                    "культура",                                             // (по направлениям)
                                COACHING          =
                                    "Спортивно-педагогическая деятельность",                // (по направлениям)
                                MANAGEMENT        =
                                    "Спортивно-туристская деятельность",                    // (по направлениям)
                                PHYSICAL_CULTURE  =
                                    "Физическая культура",                                  // (по направлениям)
                                REHABILITATION    =
                                    "Физическая реабилитация и эрготерапия",                // (по направлениям)
                                TOURISM           =
                                    "Туризм и гостеприимство";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           =
                                        "Теория и методика физического воспитания, "    \
                                        "спортивной тренировки, оздоровительной",
                                    PHYSIOLOGY       =
                                        "физиология";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM        =
                                        "Инновационный менеджмент в сфере туризма",
                                    HOSPITALITY    =
                                        "Инновационный менеджмент в сфере "             \
                                        "гостеприимства",
                                    TECHNOLOGIES   =
                                        "Инновационные технологии в сфере туризма "     \
                                        "и гостеприимства",
                                    MANAGEMENT     =
                                        "Управление инновационными проектами в "        \
                                        "туристской индустрии";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            =
                                        "Теория и методика физического "                \
                                        "воспитания, спортивной тренировки, "           \
                                        "оздоровительной и адаптивной ФК",
                                    PHYSICAL_CULTURE =
                                        "Физическая культура и спорт",
                                    TOURISM          =
                                        "Туризм и гостеприимство",
                                    MANAGEMENT       =
                                        "Менеджмент";
                            }
                        }
                    }
                    namespace PROFILING
                    {
                        namespace HIGH_SCHOOL
                        {
                            namespace SPORT
                            {
                                const AnsiString
                                    COACHING       = "Tренерская работа по ",               // + getKindOfSportNameDativeCase (nSpecializ)
                                    PSYCHOLOGY     = "Спортивная психология",               // (AsPostfix)
                                    DIRECTING      = "Сспортивная режиссура",               // (AsPostfix)
                                    MANAGEMENT     = "Менеджмент в спорте";                 // (AsPostfix)
                            }
                            namespace MANAGEMENT
                            {
                                const AnsiString
                                    RECREATIONAL   = "Спортивный и рекреационный туризм",   // (AsPostfix)
                                    TUORISM_MNG    = "Менеджмент в туризме";                // (AsPostfix)
                            }
                            namespace PHYSICAL_CULTURE
                            {
                                const AnsiString
                                    MEDICAL        = "Лечебная",                            // (AsPostfix)
                                    PRESCHOOLERS   = "Дошкольников";                        // (AsPostfix)
                            }
                            namespace IMPROVING
                            {
                                const AnsiString
                                    HEALTH         = "Оздоровительная",                     // (AsPostfix)
                                    ADAPTIVE       = "Адаптивная";                          // (AsPostfix)
                            }
                            namespace REHABILITATION
                            {
                                const AnsiString
                                    REHABILITATION = "Физическая реабилитация",             // (AsPostfix)
                                    ERGOTHERAPY    = "Эрготерапия";                         // (AsPostfix)
                            }
                            namespace TOURISM
                            {
                                const AnsiString
                                    HOSPITALITY    = "Туризм и гостеприимство",
                                    PROMOTION      =
                                        "Технологии формирования и продвижения "        \
                                        "туристических услуг",
                                    IT             =
                                        "Информационные технологии туристической "      \
                                        "индустрии",
                                    LOGISTICS      =
                                        "Логистика в туристической индустрии",
                                    SOCIAL         =
                                        "Технологии социокультурного сервиа туристов",
                                    TRANSPORT      =
                                        "Технологии транспортного сервиса туристов",
                                    CATERING       =
                                        "Технологии сервиса питания туристов",
                                    ACCOMMODATION  =
                                        "Технологии сервиса размещениятуристов ",
                                    SUPPORTING     =
                                        "Технологии экскурсионно-сопроводительного "    \
                                        "сервиса туристов",
                                    TREATMENT      =
                                        "Технологии сервиса оздоровления и лечения "    \
                                        "туристов";
                            }
                        }
                        namespace SERVICE
                        {
                            const AnsiString
                                RESTAURANTS    = "Ресторанная деятельность";
                        }
                        namespace MILITARY
                        {
                            const AnsiString
                                TRAINING       = "Физическая подготовка военнослужащих";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           =
                                        "Теория и методика физического воспитания, "    \
                                        "спортивной тренировки, оздоровительной и "     \
                                        "адаптивной физической культуры.",
                                    PHYSIOLOGY       = "физиология";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM          =
                                        "Инновационный менеджмент в сфере туризма",
                                    HOSPITALITY      =
                                        "Инновационный менеджмент в сфере "             \
                                        "гостеприимства",
                                    TECHNOLOGIES     =
                                        "Инновационные технологии в сфере туризма и "   \
                                        "гостеприимства",
                                    MANAGEMENT       =
                                        "Управление инновационными проектами в "        \
                                        "туристской индустрии";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            =
                                        "теория и методика физического воспитания, "    \
                                        "спортивной тренировки, оздоровительной и "     \
                                        "адаптивной физической культуры.",
                                    PHYSICAL_CULTURE = "Физическая культура и спорт",
                                    MANAGEMENT       = "Менеджмент",
                                    TOURISM          = "Туризм и гостеприимство";
                            }
                        }
                    }
                    namespace QUALIFICATION
                    {
                        namespace HIGH_SCHOOL
                        {
                            namespace SPORT
                            {
                                const AnsiString
                                    COACHING       =
                                        "Тренер (по виду спорта). "                     \
                                        "Преподаватель физической культуры",
                                    PSYCHOLOGY     =
                                        "Психолог. "                                    \
                                        "Преподаватель физической культуры",
                                    DIRECTING      =
                                        "Менеджер-режиссер спортивно-массовых "         \
                                        "мероприятий."                                  \
                                        "Преподаватель физической культуры",
                                    MANAGEMENT     =
                                        "Менеджер в спорте. "                           \
                                        "Преподаватель физической культуры";
                            }
                            namespace MANAGEMENT
                            {
                                const AnsiString
                                    RECREATIONAL   =
                                        "Инструктор-методист по туризму. "              \
                                        "Преподаватель физической культуры",
                                    TUORISM_MNG    =
                                        "Менеджер по туризму. "                         \
                                        "Преподаватель физической культуры";
                            }
                            namespace PHYSICAL_CULTURE
                            {
                                const AnsiString
                                    MEDICAL        =
                                        "Инструктор-методист по лечебной физической "   \
                                        "культуре. Преподаватель физической культуры",
                                    PRESCHOOLERS   =
                                        "Инструктор-методист физического воспитания в " \
                                        "дошкольных учреждениях. "                      \
                                        "Преподаватель физической культуры";
                            }
                            namespace IMPROVING
                            {
                                const AnsiString
                                    HEALTH         =
                                        "Инструктор-методист по оздоровительной "       \
                                        "физической культуре. "                         \
                                        "Преподаватель физической культуры",
                                    ADAPTIVE       =
                                        "Инструктор-методист по адаптивной "            \
                                        "физической культуре. "                         \
                                        "Преподаватель физической культуры";
                            }
                            namespace REHABILITATION
                            {
                                const AnsiString
                                    REHABILITATION =
                                        "Инструктор-методист по физической "            \
                                        "реабилитации. "                                \
                                        "Преподаватель физической культуры",
                                    ERGOTHERAPY    =
                                        "Инструктор-методист по эрготерапии. "          \
                                        "Преподаватель физической культуры";
                            }
                            namespace TOURISM
                            {
                                const AnsiString
                                    HOSPITALITY    =
                                        "Специалист в сфере туризма и гостеприимства",
                                    PROMOTION      =
                                        "Специалист в сфере туризма и гостеприимства",
                                    IT             =
                                        "Специалист в сфере туризма и гостеприимства",
                                    LOGISTICS      =
                                        "Специалист в сфере туризма и гостеприимства",
                                    SOCIAL         =
                                        "Специалист в сфере туризма и гостеприимства",
                                    TRANSPORT      =
                                        "Специалист в сфере туризма и гостеприимства",
                                    CATERING       =
                                        "Специалист в сфере туризма и гостеприимства",
                                    ACCOMMODATION  =
                                        "Специалист в сфере туризма и гостеприимства",
                                    SUPPORTING     =
                                        "Специалист в сфере туризма и гостеприимства",
                                    TREATMENT      =
                                        "Специалист в сфере туризма и гостеприимства";
                            }
                        }
                        namespace SERVICE
                        {
                            const AnsiString
                                RESTAURANTS    = "Менеджер. Технолог";
                        }
                        namespace MILITARY
                        {
                            const AnsiString
                                TRAINING       =
                                    "Специалист по управлению. "                        \
                                    "Инструктор-методист по физической "                \
                                    "подготовке";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           = "Магистр",
                                    PHYSIOLOGY       = "Магистр";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM          = "Магистр туризма",
                                    HOSPITALITY      = "Магистр гостеприимства",
                                    TECHNOLOGIES     = "Магистр инноваций",
                                    MANAGEMENT       = "Магистр управления";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            = "Магистр",
                                    PHYSICAL_CULTURE = "Магистр",
                                    TOURISM          = "Магистр",
                                    MANAGEMENT       = "Магистр";
                            }
                        }
                    }
                }
                namespace _2022
                {
                    namespace CODE
                    {
                        namespace HIGH_SCHOOL
                        {
                            const AnsiString
                                COACHING         = "6-05-1012-02",                          // "6-05-1012-02", old code: "1-88 02 01-01",
                                TOURISM          = "6-05-1013-01",                          // "6-05-1013-01", old code: "1-89 01 01";
                                PHYSICAL_CULTURE = "6-05-1012-01",                          // "6-05-1012-01", old code: "1-88 01 01";
                                REHABILITATION   = "6-05-1012-03",                          // "6-05-1012-03", old code: "1-88 01 03";
                                MANAGEMENT       = "6-05-1012-04";                          // "6-05-1012-04"; old code: "1-88 02 01-02";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           = "13.00.04",                          // "13.00.04",     old code: "13.00.04",
                                    PHYSIOLOGY       = "03.03.01";                          // "03.03.01";     old code: "03.03.01";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM          = "1-89 81 02",                        // "1-89 81 02",   old code: "1-89 81 02",
                                    HOSPITALITY      = "1-89 81 03",                        // "1-89 81 03",   old code: "1-89 81 03",
                                    TECHNOLOGIES     = "1-89 81 04",                        // "1-89 81 04",   old code: "1-89 81 04",
                                    MANAGEMENT       = "1-89 81 01";                        // "1-89 81 01";   old code: "1-89 81 01";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            = "7-06-1012-01",                      // "7-06-1012-01", old code: "1-08 80 04",
                                    PHYSICAL_CULTURE = "7-06-1012-01",                      // "7-06-1012-01", old code: "1-08 80 04",
                                    TOURISM          = "7-06-1013-01",                      // "7-06-1013-01", old code: "1-89 80 01",
                                    MANAGEMENT       = "7-06-0412-01";                      // "7-06-0412-01"; old code: "1-26 80 04",
                            }
                        }
                    }
                    namespace NAME
                    {
                        namespace HIGH_SCHOOL
                        {
                            const AnsiString
                                COACHING         =
                                    "Тренерская деятельность",
                                TOURISM          =
                                    "Туризм и гостеприимство",
                                PHYSICAL_CULTURE =
                                    "Физическая культура",
                                REHABILITATION   =
                                    "Физическая реабилитация и эрготерапия",
                                MANAGEMENT       =
                                    "Организация и управление физической "              \
                                    "культурой, спортом и туризмом";

                            namespace PROFILING
                            {
                                namespace COACH
                                {
                                    const AnsiString
                                        DEFAULT        =
                                            "(с указанием вида спорта)";
                                }
                                namespace PHYSICAL
                                {
                                    const AnsiString
                                        #ifndef USE_SHORT_NCRB011_2022_PROFILING_NAME
                                            IMPROVING      =
                                                "(оздоровительная физическая культура)",
                                            HEALTH         =
                                                "(лечебная физическая культура)",
                                            PRESCHOOLERS   =
                                                "(физическая культура дошкольников)",
                                            ADAPTIVE       =
                                                "(адаптивная физическая культура)",
                                        #else
                                            IMPROVING      =
                                                "(оздоровительная)",
                                            HEALTH         =
                                                "(лечебная)",
                                            PRESCHOOLERS   =
                                                "(дошкольников)",
                                            ADAPTIVE       =
                                                "(адаптивная)",
                                        #endif  // USE_SHORT_NCRB011_2022_PROFILING_NAME
                                        DIRECTING      =
                                            "(спортивная режиссура)",
                                        PSYCHOLOGY     =
                                            "(спортивная психология)",
                                        RECREATIONAL   =
                                            "(спортивный и рекреационный "              \
                                            "туризм)";
                                }
                                namespace REHABILITATE
                                {
                                    const AnsiString
                                        REHABILITATION =
                                            "(физическая реабилитация)",
                                        ERGOTHERAPY    =
                                            "(эрготерапия)";
                                }
                                namespace MANAGE
                                {
                                    const AnsiString
                                        SPORT          =
                                            "(менеджмент в спорте)",
                                        TOURISM        =
                                            "(менеджмент в туризме)";
                                }
                            }
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           =
                                        "Теория и методика физического "                \
                                        "воспитания, спортивной тренировки, "           \
                                        "оздоровительной",
                                    PHYSIOLOGY       =
                                        "Физиология";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM          =
                                        "Инновационный менеджмент в "                   \
                                        "сфере туризма",
                                    HOSPITALITY      =
                                        "Инновационный менеджмент в "                   \
                                        "сфере гостеприимства",
                                    TECHNOLOGIES       =
                                        "Инновационные технологии в "                   \
                                        "сфере туризма и гостеприимства",
                                    MANAGEMENT       =
                                        "Управление инновационными "                    \
                                        "проектами в туристской индустрии";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            =
                                        "Tеория и методика физического "                \
                                        "воспитания, спортивной тренировки, "           \
                                        "оздоровительной и адаптивной "                 \
                                        "физической культуры",
                                    PHYSICAL_CULTURE =
                                        "Физическая культура и спорт",
                                    TOURISM          =
                                        "Туризм и гостеприимство",
                                    MANAGEMENT       =
                                        "Менеджмент";
                            }
                        }
                    }
                    namespace QUALIFICATION
                    {
                        namespace HIGH_SCHOOL
                        {
                            const AnsiString
                                COACHING         = "Тренер. Преподаватель",
                                TOURISM          = "Специалист",
                                PHYSICAL_CULTURE = "Инструктор-методист. Преподаватель",
                                REHABILITATION   = "Инструктор-методист. Преподаватель",
                                MANAGEMENT       = "Менеджер. Преподаватель";
                        }
                        namespace MASTER_DEGREE
                        {
                            namespace SCIENCE
                            {
                                const AnsiString
                                    THEORY           = "Магистр",
                                    PHYSIOLOGY       = "Магистр";
                            }
                            namespace INNOVATION
                            {
                                const AnsiString
                                    TOURISM          = "Магистр туризма",
                                    HOSPITALITY      = "Магистр гостеприимства",
                                    TECHNOLOGIES     = "Магистр инноваций",
                                    MANAGEMENT       = "Магистр управления";
                            }
                            namespace RESEARCH
                            {
                                const AnsiString
                                    SPORT            = "Магистр",
                                    PHYSICAL_CULTURE = "Магистр",
                                    TOURISM          = "Магистр",
                                    MANAGEMENT       = "Магистр";
                            }
                        }
                    }
                }
            }
            namespace KindOfSport
            {
                // KindOfSportCode::GYMNASTICS;                    // 1,   -> "Гимнастика",
                // KindOfSportCode::MANAGEMENT_SPORTS_TOURISM;     // 2,   -> "Менеджмент спорта и туризма",
                // KindOfSportCode::PHYSICAL_REHABILITATION;       // 3,   -> "Физическая реабилитация",
                // KindOfSportCode::THERAPEUTIC;                   // 4,   -> "Лечебная физическая культура",
                // KindOfSportCode::ORGANIZATION_SPORTS_TOURISM;   // 5,   -> "Организация физкультурно-оздоровительной работы и туризма",
                // KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION;  // 6,   -> "Дошкольное физическое воспитание",
                // KindOfSportCode::DANCE_SPORT;                   // 7,   -> "Танцевальный спорт",
                // KindOfSportCode::AEROBICS;                      // 8,   -> "Аэробика",
                // KindOfSportCode::ROWING_OTHER;                  // 9,   -> "Гребной спорт",
                // KindOfSportCode::SWIMMING;                      // 10,  -> "Плавание",
                // KindOfSportCode::SAILING;                       // 11,  -> "Парусный спорт",
                // KindOfSportCode::ATHLETICS;                     // 12,  -> "Легкая атлетика",
                // KindOfSportCode::CROSS_COUNTRY_SKIING;          // 13,  -> "Лыжные гонки",
                // KindOfSportCode::BULLET_SHOOTING_DEANERY;       // 14,  -> "Пулевая стрельба",
                // KindOfSportCode::HAND_TO_HAND_COMBAT;           // 15,  -> "Рукопашный бой",
                // KindOfSportCode::TAEKWONDO;                     // 16,  -> "Таэквондо",
                // KindOfSportCode::KARATE;                        // 17,  -> "Каратэ",
                // KindOfSportCode::SKIING;                        // 18,  -> "Лыжный спорт",
                // KindOfSportCode::AUTOMOTIVE_SPORT;              // 19,  -> "Автомобильный спорт",
                // KindOfSportCode::BASKETBALL;                    // 20,  -> "Баскетбол",
                // KindOfSportCode::BOXING;                        // 21,  -> "Бокс",
                // KindOfSportCode::GRECO_FREESTYLE_WRESTLING;     // 22,  -> "Греко-римская и вольная борьба",
                // KindOfSportCode::CYCLING;                       // 23,  -> "Велосипедный спорт",
                // KindOfSportCode::VOLLEYBALL;                    // 24,  -> "Волейбол",
                // KindOfSportCode::HANDBALL;                      // 25,  -> "Гандбол",
                // KindOfSportCode::EQUESTRIAN;                    // 26,  -> "Конный спорт",
                // KindOfSportCode::SPEED_SKATING;                 // 27,  -> "Конькобежный спорт",
                // KindOfSportCode::TENNIS;                        // 28,  -> "Теннис",
                // KindOfSportCode::WEIGHTLIFTING;                 // 29,  -> "Тяжелая атлетика",
                // KindOfSportCode::FENCING;                       // 30,  -> "Фехтование",
                // KindOfSportCode::FIGURE_SKATING;                // 31,  -> FIGURE_SKATING "Фигурное катание",
                // KindOfSportCode::FOOTBALL;                      // 32,  -> "Футбол",
                // KindOfSportCode::HOCKEY;                        // 33,  -> "Хоккей",
                // KindOfSportCode::WRESTLING;                     // 35,  -> "Спортивная борьба",
                // KindOfSportCode::BIATHLON;                      // 37,  -> "Биатлон",
                // KindOfSportCode::HEALTH_IMPROVING;              // 38,  -> "Оздоровительная физическая культура",
                // KindOfSportCode::ADAPTIVE;                      // 39,  -> "Адаптивная физическая культура",
                // KindOfSportCode::FREESTYLE_WRESTLING;           // 42,  -> "Вольная борьба",
                // KindOfSportCode::GRECO_ROMAN_WRESTLING;         // 43,  -> "Греко-римская борьба",
                // KindOfSportCode::SAMBO;                         // 44,  -> "Самбо",
                // KindOfSportCode::JUDO;                          // 45,  -> "Дзюдо",
                // KindOfSportCode::TABLE_TENNIS;                  // 46,  -> "Теннис настольный",
                // KindOfSportCode::ERGOTHERAPY;                   // 47,  -> "Эрготерапия",
                // KindOfSportCode::MANAGEMENT_SPORTS;             // 48,  -> "Менеджмент в спорте",
                // KindOfSportCode::SPORTS_RECREATIONAL_TOURISM;   // 50,  -> "Спортивный и рекреационный туризм",
                // KindOfSportCode::MANAGEMENT_TOURISM;            // 51,  -> "Менеджмент в туризме",
                // KindOfSportCode::SPORTS_PSYCHOLOGY;             // 52,  -> "Спортивная психология",
                // KindOfSportCode::BILLIARD_SPORTS;               // 53,  -> "Бильярдный спорт",
                // KindOfSportCode::ACROBATICS;                    // 54,  -> "Акробатика",
                // KindOfSportCode::ORIENTEERING;                  // 55,  -> "Спортивное ориентирование",
                // KindOfSportCode::SPORTS_DIRECTING;              // 56,  -> "Спортивная режиссура",
                // KindOfSportCode::PRESCHOOLERS;                  // 57,  -> "Физическая культура дошкольников",
                // KindOfSportCode::MOUNTAINEERING;                // 59,  -> "Альпинизм",
                // KindOfSportCode::SKI_COMBINED;                  // 60,  -> "Лыжное двоеборье",
                // KindOfSportCode::TOURISM_HOSPITALITY;           // 61,  -> "Туризм и гостеприимство",
                // KindOfSportCode::WATER_TECHNICAL_SPORTS;        // 62,  -> "Водно-технические виды спорта",
                // KindOfSportCode::MODEL_TECHNICAL_SPORTS;        // 63,  -> "Модельно-технические виды спорта",
                // KindOfSportCode::ALPINE_SKIING;                 // 64,  -> "Горнолыжный спорт",
                // KindOfSportCode::BASEBALL;                      // 65,  -> "Бейсбол",
                // KindOfSportCode::WUSHU;                         // 66,  -> "Ушу",
                // KindOfSportCode::CHESS;                         // 68,  -> "Шахматы",
                // KindOfSportCode::THAI_BOXING;                   // 69,  -> "Таиландский бокс",
                // KindOfSportCode::TOURISM_PROMOTION;             // 70,  -> "Технологии формирования и продвижения туристических услуг",
                // KindOfSportCode::TOURISM_IT;                    // 71,  -> "Информационные технологии туристической индустрии",
                // KindOfSportCode::TOURISM_LOGISTICS;             // 72,  -> "Логистика в туристической индустрии",
                // KindOfSportCode::TOURISM_SOCIAL;                // 73,  -> "Технологии социокультурного сервиса туристов",
                // KindOfSportCode::TOURISM_TRANSPORT;             // 74,  -> "Технологии транспортного сервиса туристов",
                // KindOfSportCode::TOURISM_FOOD;                  // 75,  -> "Технологии сервиса питания туристов",
                // KindOfSportCode::TOURIST_ACCOMMODATION;         // 76,  -> "Технологии сервиса размещения туристов",
                // KindOfSportCode::TOURISM_EXCURSION;             // 77,  -> "Технологии экскурсионно-сопроводительного сервиса туристов",
                // KindOfSportCode::TOURISM_HEALTH;                // 78,  -> "Технологии сервиса оздоровления и лечения туристов",
                // KindOfSportCode::BULLET_SHOOTING;               // 79,  -> "Стрельба пулевая",
                // KindOfSportCode::FIELD_HOCKEY;                  // 80,  -> "Хоккей на траве",
                // KindOfSportCode::FIGURE_SKATING_SKATES;         // 84,  -> "Фигурное катание на коньках",
                // KindOfSportCode::ROWING_AND_CANOEING;           // 87,  -> "Гребля на байдарках и каноэ",
                // KindOfSportCode::ACADEMIC_ROWING;               // 88,  -> "Гребля академическая",
                // KindOfSportCode::HAND_TO_HAND_MARTIAL_ARTS;     // 92,  -> "Рукопашный бой (смешанные единоборства)",
                // KindOfSportCode::BILLIARDS;                     // 93,  -> "Бильярд",
                // KindOfSportCode::WITHOUT_SPECIALIZATION;        // 94,  -> "Без специализации",
                // KindOfSportCode::MODERN_PENTATHLON;             // 96,  -> "Современное пятиборье",
                // KindOfSportCode::SCIENCE_HEALTH;                // 101, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной",
                // KindOfSportCode::PHYSIOLOGY;                    // 102, -> "физиология",
                // KindOfSportCode::SCIENCE_THEORY;                // 103, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной",
                // KindOfSportCode::RECEARCH_SPORT;                // 104, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной",
                // KindOfSportCode::INNOVATIVE_TOURISM;            // 105, -> "инновационный менеджмент в сфере туризма",
                // KindOfSportCode::INNOVATIVE_HOSPITALITY;        // 106, -> "инновационный менеджмент в сфере гостеприимства",
                // KindOfSportCode::INNOVATIVE_TECHNOLOGIES;       // 107, -> "инновационные технологии в сфере туризма и гостеприимства",
                // KindOfSportCode::INNOVATIVE_MANAGEMENT;         // 108, -> "управление инновационными проектами в туристской индустрии",
                // KindOfSportCode::BADMINTON;                     // 116, -> "Бадминтон",
                // KindOfSportCode::PHYSICAL_CULTURE_SPORT;        // 118, -> "Физическая культура и спорт",
                // KindOfSportCode::TOURISM_HOSPITALITY_MASTER;    // 119, -> "Туризм и гостеприимство",
                // KindOfSportCode::SPORT_CLIMBING;                // 120, -> "Скалолазание спортивное",
                // KindOfSportCode::MASTER_ANTHROPOLOGY;           // 121, -> "антропология",
                // KindOfSportCode::MASTER_MANAGEMENT;             // 122  -> "Менеджмент",
                const AnsiString
                    GYMNASTICS                   =
                        "Гимнастика",
                    MANAGEMENT_SPORTS_TOURISM    =
                        "Менеджмент спорта и туризма",
                    PHYSICAL_REHABILITATION      =
                        "Физическая реабилитация",
                    THERAPEUTIC                  =
                        "Лечебная физическая культура",
                    ORGANIZATION_SPORTS_TOURISM  =
                        "Организация физкультурно-оздоровительной "                     \
                        "работы и туризма",
                    PRESCHOOL_PHYSICAL_EDUCATION =
                        "Дошкольное физическое воспитание",
                    DANCE_SPORT                  =
                        "Танцевальный спорт",
                    AEROBICS                     =
                        "Аэробика",
                    ROWING_OTHER                 =
                        "Гребной спорт",
                    SWIMMING                     =
                        "Плавание",
                    SAILING                      =
                        "Парусный спорт",
                    ATHLETICS                    =
                        "Легкая атлетика",
                    CROSS_COUNTRY_SKIING         =
                        "Лыжные гонки",
                    BULLET_SHOOTING_DEANERY      =
                        "Пулевая стрельба",
                    HAND_TO_HAND_COMBAT          =
                        "Рукопашный бой",
                    TAEKWONDO                    =
                        "Таэквондо",
                    KARATE                       =
                        "Каратэ",
                    SKIING                       =
                        "Лыжный спорт",
                    AUTOMOTIVE_SPORT             =
                        "Автомобильный спорт",
                    BASKETBALL                   =
                        "Баскетбол",
                    BOXING                       =
                        "Бокс",
                    GRECO_FREESTYLE_WRESTLING    =
                        "Греко-римская и вольная борьба",
                    CYCLING                      =
                        "Велосипедный спорт",
                    VOLLEYBALL                   =
                        "Волейбол",
                    HANDBALL                     =
                        "Гандбол",
                    EQUESTRIAN                   =
                        "Конный спорт",
                    SPEED_SKATING                =
                        "Конькобежный спорт",
                    TENNIS                       =
                        "Теннис",
                    WEIGHTLIFTING                =
                        "Тяжелая атлетика",
                    FENCING                      =
                        "Фехтование",
                    FIGURE_SKATING               =
                        "Фигурное катание",
                    FOOTBALL                     =
                        "Футбол",
                    HOCKEY                       =
                        "Хоккей",
                    WRESTLING                    =
                        "Спортивная борьба",
                    BIATHLON                     =
                        "Биатлон",
                    HEALTH_IMPROVING             =
                        "Оздоровительная физическая культура",
                    ADAPTIVE                     =
                        "Адаптивная физическая культура",
                    FREESTYLE_WRESTLING          =
                        "Вольная борьба",
                    GRECO_ROMAN_WRESTLING        =
                        "Греко-римская борьба",
                    SAMBO                        =
                        "Самбо",
                    JUDO                         =
                        "Дзюдо",
                    TABLE_TENNIS                 =
                        "Теннис настольный",
                    ERGOTHERAPY                  =
                        "Эрготерапия",
                    MANAGEMENT_SPORTS            =
                        "Менеджмент в спорте",
                    SPORTS_RECREATIONAL_TOURISM  =
                        "Спортивный и рекреационный туризм",
                    MANAGEMENT_TOURISM           =
                        "Менеджмент в туризме",
                    SPORTS_PSYCHOLOGY            =
                        "Спортивная психология",
                    BILLIARD_SPORTS              =
                        "Бильярдный спорт",
                    ACROBATICS                   =
                        "Акробатика",
                    ORIENTEERING                 =
                        "Спортивное ориентирование",
                    SPORTS_DIRECTING             =
                        "Спортивная режиссура",
                    PRESCHOOLERS                 =
                        "Физическая культура дошкольников",
                    MOUNTAINEERING               =
                        "Альпинизм",
                    SKI_COMBINED                 =
                        "Лыжное двоеборье",
                    TOURISM_HOSPITALITY          =
                        "Туризм и гостеприимство",
                    WATER_TECHNICAL_SPORTS       =
                        "Водно-технические виды спорта",
                    MODEL_TECHNICAL_SPORTS       =
                        "Модельно-технические виды спорта",
                    ALPINE_SKIING                =
                        "Горнолыжный спорт",
                    BASEBALL                     =
                        "Бейсбол",
                    WUSHU                        =
                        "Ушу",
                    CHESS                        =
                        "Шахматы",
                    THAI_BOXING                  =
                        "Таиландский бокс",
                    TOURISM_PROMOTION            =
                        "Технологии формирования и продвижения "                        \
                        "туристических услуг",
                    TOURISM_IT                   =
                        "Информационные технологии туристической "                      \
                        "индустрии",
                    TOURISM_LOGISTICS            =
                        "Логистика в туристической индустрии",
                    TOURISM_SOCIAL               =
                        "Технологии социокультурного сервиса "                          \
                        "туристов",
                    TOURISM_TRANSPORT            =
                        "Технологии транспортного сервиса туристов",
                    TOURISM_FOOD                 =
                        "Технологии сервиса питания туристов",
                    TOURIST_ACCOMMODATION        =
                        "Технологии сервиса размещения туристов",
                    TOURISM_EXCURSION            =
                        "Технологии экскурсионно-сопроводительного "                    \
                        "сервиса туристов",
                    TOURISM_HEALTH               =
                        "Технологии сервиса оздоровления и лечения "                    \
                        "туристов",
                    BULLET_SHOOTING              =
                        "Стрельба пулевая",
                    FIELD_HOCKEY                 =
                        "Хоккей на траве",
                    FIGURE_SKATING_SKATES        =
                        "Фигурное катание на коньках",
                    ROWING_AND_CANOEING          =
                        "Гребля на байдарках и каноэ",
                    ACADEMIC_ROWING              =
                        "Гребля академическая",
                    HAND_TO_HAND_MARTIAL_ARTS    =
                        "Рукопашный бой (смешанные единоборства)",
                    BILLIARDS                    =
                        "Бильярд",
                    WITHOUT_SPECIALIZATION       =
                        "Без специализации",
                    MODERN_PENTATHLON            =
                        "Современное пятиборье",
                    SCIENCE_HEALTH               =
                        "теория и методика физического воспитания, "                    \
                        "спортивной тренировки, оздоровительной",
                    PHYSIOLOGY                   =
                        "физиология",
                    SCIENCE_THEORY               =
                        "теория и методика физического воспитания, "                    \
                        "спортивной тренировки, оздоровительной",
                    RECEARCH_SPORT               =
                        "теория и методика физического воспитания, "                    \
                        "спортивной тренировки, оздоровительной",
                    INNOVATIVE_TOURISM           =
                        "инновационный менеджмент в сфере туризма",
                    INNOVATIVE_HOSPITALITY       =
                        "инновационный менеджмент в сфере гостеприимства",
                    INNOVATIVE_TECHNOLOGIES      =
                        "инновационные технологии в сфере туризма "                     \
                        "и гостеприимства",
                    INNOVATIVE_MANAGEMENT        =
                        "управление инновационными проектами в "                        \
                        "туристской индустрии",
                    BADMINTON                    =
                        "Бадминтон",
                    PHYSICAL_CULTURE_SPORT       =
                        "Физическая культура и спорт",
                    TOURISM_HOSPITALITY_MASTER   =
                        "Туризм и гостеприимство",
                    SPORT_CLIMBING               =
                        "Скалолазание спортивное",
                    MASTER_ANTHROPOLOGY          =
                        "антропология",
                    MASTER_MANAGEMENT            =
                        "Менеджмент";

                // KindOfSport::DATIVE_CASE::GYMNASTICS;                                    // "гимнастике",
                // KindOfSport::DATIVE_CASE::MANAGEMENT_SPORTS_TOURISM;                     // "менеджменту спорта и туризма",
                // KindOfSport::DATIVE_CASE::PHYSICAL_REHABILITATION;                       // "физическая реабилитации",
                // KindOfSport::DATIVE_CASE::THERAPEUTIC;                                   // "лечебной физическая культура",
                // KindOfSport::DATIVE_CASE::ORGANIZATION_SPORTS_TOURISM;                   // "организации физкультурно-оздоровительной работы и туризма",
                // KindOfSport::DATIVE_CASE::PRESCHOOL_PHYSICAL_EDUCATION;                  // "дошкольному физическому воспитанию",
                // KindOfSport::DATIVE_CASE::DANCE_SPORT;                                   // "танцевальному спорту",
                // KindOfSport::DATIVE_CASE::AEROBICS;                                      // "аэробике",
                // KindOfSport::DATIVE_CASE::ROWING_OTHER;                                  // "гребному спорту",
                // KindOfSport::DATIVE_CASE::SWIMMING;                                      // "плаванию",
                // KindOfSport::DATIVE_CASE::SAILING;                                       // "парусному спорту",
                // KindOfSport::DATIVE_CASE::ATHLETICS;                                     // "легкой атлетике",
                // KindOfSport::DATIVE_CASE::CROSS_COUNTRY_SKIING;                          // "лыжным гонкам",
                // KindOfSport::DATIVE_CASE::BULLET_SHOOTING_DEANERY;                       // "пулевой стрельбе",
                // KindOfSport::DATIVE_CASE::HAND_TO_HAND_COMBAT;                           // "рукопашному бою",
                // KindOfSport::DATIVE_CASE::TAEKWONDO;                                     // "таэквондо",
                // KindOfSport::DATIVE_CASE::KARATE;                                        // "каратэ",
                // KindOfSport::DATIVE_CASE::SKIING;                                        // "лыжному спорту",
                // KindOfSport::DATIVE_CASE::AUTOMOTIVE_SPORT;                              // "автомобильному спорту",
                // KindOfSport::DATIVE_CASE::BASKETBALL;                                    // "баскетболу",
                // KindOfSport::DATIVE_CASE::BOXING;                                        // "боксу",
                // KindOfSport::DATIVE_CASE::GRECO_FREESTYLE_WRESTLING;                     // "греко-римской и вольной борьбе",
                // KindOfSport::DATIVE_CASE::CYCLING;                                       // "велосипедному спорту",
                // KindOfSport::DATIVE_CASE::VOLLEYBALL;                                    // "волейболу",
                // KindOfSport::DATIVE_CASE::HANDBALL;                                      // "гандболу",
                // KindOfSport::DATIVE_CASE::EQUESTRIAN;                                    // "конному спорту",
                // KindOfSport::DATIVE_CASE::SPEED_SKATING;                                 // "конькобежному спорту",
                // KindOfSport::DATIVE_CASE::TENNIS;                                        // "теннису",
                // KindOfSport::DATIVE_CASE::WEIGHTLIFTING;                                 // "тяжелой атлетике",
                // KindOfSport::DATIVE_CASE::FENCING;                                       // "фехтованию",
                // KindOfSport::DATIVE_CASE::FIGURE_SKATING;                                // "фигурному катанию",
                // KindOfSport::DATIVE_CASE::FOOTBALL;                                      // "футболу",
                // KindOfSport::DATIVE_CASE::HOCKEY;                                        // "хоккею",
                // KindOfSport::DATIVE_CASE::WRESTLING;                                     // "спортивной борьбе",
                // KindOfSport::DATIVE_CASE::BIATHLON;                                      // "биатлону",
                // KindOfSport::DATIVE_CASE::HEALTH_IMPROVING;                              // "оздоровительной физической культуре",
                // KindOfSport::DATIVE_CASE::ADAPTIVE;                                      // "адаптивной физической культуре",
                // KindOfSport::DATIVE_CASE::FREESTYLE_WRESTLING;                           // "вольной борьбе",
                // KindOfSport::DATIVE_CASE::GRECO_ROMAN_WRESTLING;                         // "греко-римской борьбе",
                // KindOfSport::DATIVE_CASE::SAMBO;                                         // "самбо",
                // KindOfSport::DATIVE_CASE::JUDO;                                          // "дзюдо",
                // KindOfSport::DATIVE_CASE::TABLE_TENNIS;                                  // "теннису настольному",
                // KindOfSport::DATIVE_CASE::ERGOTHERAPY;                                   // "эрготерапии",
                // KindOfSport::DATIVE_CASE::MANAGEMENT_SPORTS;                             // "менеджменту в спорте",
                // KindOfSport::DATIVE_CASE::SPORTS_RECREATIONAL_TOURISM;                   // "спортивному и рекреационному туризму",
                // KindOfSport::DATIVE_CASE::MANAGEMENT_TOURISM;                            // "менеджменту в туризме",
                // KindOfSport::DATIVE_CASE::SPORTS_PSYCHOLOGY;                             // "спортивной психологии",
                // KindOfSport::DATIVE_CASE::BILLIARD_SPORTS;                               // "бильярдному спорту",
                // KindOfSport::DATIVE_CASE::ACROBATICS;                                    // "акробатике",
                // KindOfSport::DATIVE_CASE::ORIENTEERING;                                  // "спортивному ориентированию",
                // KindOfSport::DATIVE_CASE::SPORTS_DIRECTING;                              // "спортивной режиссуре",
                // KindOfSport::DATIVE_CASE::PRESCHOOLERS;                                  // "физической культуре дошкольников",
                // KindOfSport::DATIVE_CASE::MOUNTAINEERING;                                // "альпинизму",
                // KindOfSport::DATIVE_CASE::SKI_COMBINED;                                  // "лыжному двоеборью",
                // KindOfSport::DATIVE_CASE::TOURISM_HOSPITALITY;                           // "туризму и гостеприимству",
                // KindOfSport::DATIVE_CASE::WATER_TECHNICAL_SPORTS;                        // "водно-техническим видам спорта",
                // KindOfSport::DATIVE_CASE::MODEL_TECHNICAL_SPORTS;                        // "модельно-техническим видам спорта",
                // KindOfSport::DATIVE_CASE::ALPINE_SKIING;                                 // "горнолыжному спорту",
                // KindOfSport::DATIVE_CASE::BASEBALL;                                      // "бейсболу",
                // KindOfSport::DATIVE_CASE::WUSHU;                                         // "ушу",
                // KindOfSport::DATIVE_CASE::CHESS;                                         // "шахматам",
                // KindOfSport::DATIVE_CASE::THAI_BOXING;                                   // "таиландскому боксу",
                // KindOfSport::DATIVE_CASE::TOURISM_PROMOTION;                             // "технологиям формирования и продвижения туристических услуг",
                // KindOfSport::DATIVE_CASE::TOURISM_IT;                                    // "информационным технологиям туристической индустрии",
                // KindOfSport::DATIVE_CASE::TOURISM_LOGISTICS;                             // "логистике в туристической индустрии",
                // KindOfSport::DATIVE_CASE::TOURISM_SOCIAL;                                // "технологиям социокультурного сервиса туристов",
                // KindOfSport::DATIVE_CASE::TOURISM_TRANSPORT;                             // "технологиям транспортного сервиса туристов",
                // KindOfSport::DATIVE_CASE::TOURISM_FOOD;                                  // "технологиям сервиса питания туристов",
                // KindOfSport::DATIVE_CASE::TOURIST_ACCOMMODATION;                         // "технологиям сервиса размещения туристов",
                // KindOfSport::DATIVE_CASE::TOURISM_EXCURSION;                             // "технологиям экскурсионно-сопроводительного сервиса туристов",
                // KindOfSport::DATIVE_CASE::TOURISM_HEALTH;                                // "технологиям сервиса оздоровления и лечения туристов",
                // KindOfSport::DATIVE_CASE::BULLET_SHOOTING;                               // "стрельбе пулевой",
                // KindOfSport::DATIVE_CASE::FIELD_HOCKEY;                                  // "хоккею на траве",
                // KindOfSport::DATIVE_CASE::FIGURE_SKATING_SKATES;                         // "фигурному катанию на коньках",
                // KindOfSport::DATIVE_CASE::ROWING_AND_CANOEING;                           // "гребле на байдарках и каноэ",
                // KindOfSport::DATIVE_CASE::ACADEMIC_ROWING;                               // "гребле академической",
                // KindOfSport::DATIVE_CASE::HAND_TO_HAND_MARTIAL_ARTS;                     // "рукопашному бою (смешанные единоборства)",
                // KindOfSport::DATIVE_CASE::BILLIARDS;                                     // "бильярду",
                // KindOfSport::DATIVE_CASE::WITHOUT_SPECIALIZATION;                        // "без специализации",
                // KindOfSport::DATIVE_CASE::MODERN_PENTATHLON;                             // "современному пятиборью",
                // KindOfSport::DATIVE_CASE::SCIENCE_HEALTH;                                // "теории и методике физического воспитания, спортивной тренировки, оздоровительной",
                // KindOfSport::DATIVE_CASE::PHYSIOLOGY;                                    // "физиологии",
                // KindOfSport::DATIVE_CASE::SCIENCE_THEORY;                                // "теории и методике физического воспитания, спортивной тренировки, оздоровительной",
                // KindOfSport::DATIVE_CASE::RECEARCH_SPORT;                                // "теории и методике физического воспитания, спортивной тренировки, оздоровительной",
                // KindOfSport::DATIVE_CASE::INNOVATIVE_TOURISM;                            // "инновационному менеджменту в сфере туризма",
                // KindOfSport::DATIVE_CASE::INNOVATIVE_HOSPITALITY;                        // "инновационному менеджменту в сфере гостеприимства",
                // KindOfSport::DATIVE_CASE::INNOVATIVE_TECHNOLOGIES;                       // "инновационным технологиям в сфере туризма и гостеприимства",
                // KindOfSport::DATIVE_CASE::INNOVATIVE_MANAGEMENT;                         // "управлению инновационными проектами в туристской индустрии",
                // KindOfSport::DATIVE_CASE::BADMINTON;                                     // "бадминтону",
                // KindOfSport::DATIVE_CASE::PHYSICAL_CULTURE_SPORT;                        // "физической культуре и спорту",
                // KindOfSport::DATIVE_CASE::TOURISM_HOSPITALITY_MASTER;                    // "туризму и гостеприимству",
                // KindOfSport::DATIVE_CASE::SPORT_CLIMBING;                                // "спортивному скалолазанию",
                // KindOfSport::DATIVE_CASE::MASTER_ANTHROPOLOGY;                           // "антропологии",
                // KindOfSport::DATIVE_CASE::MASTER_MANAGEMENT;                             // "менеджменту";
                namespace DATIVE_CASE
                {
                    const AnsiString
                        GYMNASTICS                   =
                            "гимнастике",
                        MANAGEMENT_SPORTS_TOURISM    =
                            "менеджменту спорта и туризма",
                        PHYSICAL_REHABILITATION      =
                            "физическаой реабилитации",
                        THERAPEUTIC                  =
                            "лечебной физической культуре",
                        ORGANIZATION_SPORTS_TOURISM  =
                            "организации физкультурно-оздоровительной "                 \
                            "работы и туризма",
                        PRESCHOOL_PHYSICAL_EDUCATION =
                            "дошкольному физическому воспитанию",
                        DANCE_SPORT                  =
                            "танцевальному спорту",
                        AEROBICS                     =
                            "аэробике",
                        ROWING_OTHER                 =
                            "гребному спорту",
                        SWIMMING                     =
                            "плаванию",
                        SAILING                      =
                            "парусному спорту",
                        ATHLETICS                    =
                            "легкой атлетике",
                        CROSS_COUNTRY_SKIING         =
                            "лыжным гонкам",
                        BULLET_SHOOTING_DEANERY      =
                            "пулевой стрельбе",
                        HAND_TO_HAND_COMBAT          =
                            "рукопашному бою",
                        TAEKWONDO                    =
                            "таэквондо",
                        KARATE                       =
                            "каратэ",
                        SKIING                       =
                            "лыжному спорту",
                        AUTOMOTIVE_SPORT             =
                            "автомобильному спорту",
                        BASKETBALL                   =
                            "баскетболу",
                        BOXING                       =
                            "боксу",
                        GRECO_FREESTYLE_WRESTLING    =
                            "греко-римской и вольной борьбе",
                        CYCLING                      =
                            "велосипедному спорту",
                        VOLLEYBALL                   =
                            "волейболу",
                        HANDBALL                     =
                            "гандболу",
                        EQUESTRIAN                   =
                            "конному спорту",
                        SPEED_SKATING                =
                            "конькобежному спорту",
                        TENNIS                       =
                            "теннису",
                        WEIGHTLIFTING                =
                            "тяжелой атлетике",
                        FENCING                      =
                            "фехтованию",
                        FIGURE_SKATING               =
                            "фигурному катанию",
                        FOOTBALL                     =
                            "футболу",
                        HOCKEY                       =
                            "хоккею",
                        WRESTLING                    =
                            "спортивной борьбе",
                        BIATHLON                     =
                            "биатлону",
                        HEALTH_IMPROVING             =
                            "оздоровительной физической культуре",
                        ADAPTIVE                     =
                            "адаптивной физической культуре",
                        FREESTYLE_WRESTLING          =
                            "вольной борьбе",
                        GRECO_ROMAN_WRESTLING        =
                            "греко-римской борьбе",
                        SAMBO                        =
                            "самбо",
                        JUDO                         =
                            "дзюдо",
                        TABLE_TENNIS                 =
                            "теннису настольному",
                        ERGOTHERAPY                  =
                            "эрготерапии",
                        MANAGEMENT_SPORTS            =
                            "менеджменту в спорте",
                        SPORTS_RECREATIONAL_TOURISM  =
                            "спортивному и рекреационному туризму",
                        MANAGEMENT_TOURISM           =
                            "менеджменту в туризме",
                        SPORTS_PSYCHOLOGY            =
                            "спортивной психологии",
                        BILLIARD_SPORTS              =
                            "бильярдному спорту",
                        ACROBATICS                   =
                            "акробатике",
                        ORIENTEERING                 =
                            "спортивному ориентированию",
                        SPORTS_DIRECTING             =
                            "спортивной режиссуре",
                        PRESCHOOLERS                 =
                            "физической культуре дошкольников",
                        MOUNTAINEERING               =
                            "альпинизму",
                        SKI_COMBINED                 =
                            "лыжному двоеборью",
                        TOURISM_HOSPITALITY          =
                            "туризму и гостеприимству",
                        WATER_TECHNICAL_SPORTS       =
                            "водно-техническим видам спорта",
                        MODEL_TECHNICAL_SPORTS       =
                            "модельно-техническим видам спорта",
                        ALPINE_SKIING                =
                            "горнолыжному спорту",
                        BASEBALL                     =
                            "бейсболу",
                        WUSHU                        =
                            "ушу",
                        CHESS                        =
                            "шахматам",
                        THAI_BOXING                  =
                            "таиландскому боксу",
                        TOURISM_PROMOTION            =
                            "технологиям формирования и продвижения "                   \
                            "туристических услуг",
                        TOURISM_IT                   =
                            "информационным технологиям туристической "                 \
                            "индустрии",
                        TOURISM_LOGISTICS            =
                            "логистике в туристической индустрии",
                        TOURISM_SOCIAL               =
                            "технологиям социокультурного сервиса "                     \
                            "туристов",
                        TOURISM_TRANSPORT            =
                            "технологиям транспортного сервиса туристов",
                        TOURISM_FOOD                 =
                            "технологиям сервиса питания туристов",
                        TOURIST_ACCOMMODATION        =
                            "технологиям сервиса размещения туристов",
                        TOURISM_EXCURSION            =
                            "технологиям экскурсионно-сопроводительного "               \
                            "сервиса туристов",
                        TOURISM_HEALTH               =
                            "технологиям сервиса оздоровления и лечения "               \
                            "туристов",
                        BULLET_SHOOTING              =
                            "стрельбе пулевой",
                        FIELD_HOCKEY                 =
                            "хоккею на траве",
                        FIGURE_SKATING_SKATES        =
                            "фигурному катанию на коньках",
                        ROWING_AND_CANOEING          =
                            "гребле на байдарках и каноэ",
                        ACADEMIC_ROWING              =
                            "гребле академической",
                        HAND_TO_HAND_MARTIAL_ARTS    =
                            "рукопашному бою (смешанным единоборствам)",
                        BILLIARDS                    =
                            "бильярду",
                        WITHOUT_SPECIALIZATION       =
                            "без специализации",
                        MODERN_PENTATHLON            =
                            "современному пятиборью",
                        SCIENCE_HEALTH               =
                            "теории и методике физического воспитания, "                \
                            "спортивной тренировки, оздоровительной",
                        PHYSIOLOGY                   =
                            "физиологии",
                        SCIENCE_THEORY               =
                            "теории и методике физического воспитания, "                \
                            "спортивной тренировки, оздоровительной",
                        RECEARCH_SPORT               =
                            "теории и методике физического воспитания, "                \
                            "спортивной тренировки, оздоровительной",
                        INNOVATIVE_TOURISM           =
                            "инновационному менеджменту в сфере туризма",
                        INNOVATIVE_HOSPITALITY       =
                            "инновационному менеджменту в сфере гостеприимства",
                        INNOVATIVE_TECHNOLOGIES      =
                            "инновационным технологиям в сфере туризма "                \
                            "и гостеприимства",
                        INNOVATIVE_MANAGEMENT        =
                            "управлению инновационными проектами в "                    \
                            "туристской индустрии",
                        BADMINTON                    =
                            "бадминтону",
                        PHYSICAL_CULTURE_SPORT       =
                            "физической культуре и спорту",
                        TOURISM_HOSPITALITY_MASTER   =
                            "туризму и гостеприимству",
                        SPORT_CLIMBING               =
                            "спортивному скалолазанию",
                        MASTER_ANTHROPOLOGY          =
                            "антропологии",
                        MASTER_MANAGEMENT            =
                            "менеджменту";
                }
            }
        #endif  // ! DATABASE_SUBSTITUTE
    #endif // ! NEW_INTEGRATION
#else                                       // CHECKED!!!
    namespace Admissions
    {
        namespace TIME
        {
            const AnsiString
                YEAR                 = "2023";
        }
        namespace INVENTORY
        {
            const AnsiString
                #ifdef SET_INVENTORY_DATE_BY_HAND                                   // IT'S FOR CHANGING CURRENT DATE TO OTHER INTO INVENTORY LIST (ListDlgUnit.cpp)
                DATE                 =
                    "01.06.2023";
                #else
                DATE                 =
                    (Now ())
                        .FormatString (
                            "dd.mm.yyyy"
                        );
                #endif  // SET_INVENTORY_DATE_BY_HAND
        }
        namespace DEADLINE
        {
            const AnsiString
                FOR_RECEIVING_PART_1 = "05.06.2023 6:00:00",
                FOR_RECEIVING_PART_2 = "10.08.2023 6:00:00";
        }
        namespace ADDITIONAL
        {
            const AnsiString
                ORDER_DATE_PART_1    = "04.06.2023",
                ORDER_DATE_PART_2    = "08.08.2023";
        }
        namespace DOCUMENTS
        {
            const AnsiString
                PROVIDE_DATE = "15.06.2023";
        }
        namespace ARRIVAL
        {
            namespace TIME
            {
                const AnsiString
                    EVERYONE = "9:00";
            }
            namespace DATE
            {
                namespace INTRAMURAL
                {
                    const AnsiString
                        ALL = "01.09.2023";
                }
                namespace EXTRAMURAL
                {
                    namespace FULL
                    {
                        const AnsiString
                            MSTH  = "05.09.2023.",
                            OTHER = "12.09.2023.";
                    }
                    namespace SHORT
                    {
                        const AnsiString
                            SMA   = "03.10.2023.",
                            MS    = "05.10.2023.",
                            RPC   = "07.10.2023.",
                            MSTH  = "24.10.2023.";
                    }
                }
            }
        }
    }
    namespace ContestType
    {
        const AnsiString
            GENERAL                = "общий",
            WITHOUT_ENTRANCE_EXAMS = "без вступительных испытаний",
            OUT_OF_COMPETITION     = "вне конкурса",
            TARGETED_TRAINING      = "целевой";
    }
    namespace Contract
    {
        namespace DOCUMENT_FILE
        {
            const AnsiString
                BUDGET  = "ДОГОВОР - Бюджет.xls",
                BUYERS  = "ДОГОВОР - Платники.xls";
        }
        namespace DOCUMENT_NAME
        {
            const AnsiString
                BUDGET = "ДОГОВОР - Бюджет",
                BUYERS = "ДОГОВОР - Платники";
        }
        namespace BSUPC
        {
            const AnsiString
                PERSON = "Башлаковой Галины Ивановны";                         // Old name: CONTRACT_SIDE_BSUPC_MAIN

            namespace BASE_DOCUMENT
            {
                const AnsiString
                    NAME   = "доверенности",                                        // Old name: CONTRACT_TYPE_POWER_DOC_MAIN
                    DATE   = "16.11.2021",                                          // Old name: CONTRACT_POWER_DOC_DATE_MAIN
                    NUMBER = "13-16-45";                                            // Old name: CONTRACT_POWER_DOC_NO_MAIN
            }
        }
        namespace IMS
        {
            const AnsiString
                PERSON = "Михайловой Ольги Николаевны";                             // Old name: CONTRACT_SIDE_BSUPC_IMST

            namespace BASE_DOCUMENT
            {
                const AnsiString
                    NAME   = "доверенности",                                        // Old name: CONTRACT_TYPE_POWER_DOC_IMST
                    DATE   = "26.10.2021",                                          // Old name: CONTRACT_POWER_DOC_DATE_IMST
                    NUMBER = "13-16-42";                                            // Old name: CONTRACT_POWER_DOC_NO_IMST
            }
        }
        namespace PAYMENT_TERM
        {
            const AnsiString
                FIRST_SEMESTER  =
                    "по 31.08.2023 (включительно) – за первый "              \
                    "семестр первого года обучения в размере",
                SECOND_SEMESTER =
                    "с 01.02.2024 до 01.03.2024 – за второй "               \
                    "семестр первого года обучения в размере";
        }
        namespace COST_FOR
        {
            namespace BUDGET
            {
                namespace INTRAMURAL
                {
                    const AnsiString
                        FULL_COURSE   =                                             // БЮДЖЕТ, ДНЕВНОЕ, ПОЛНЫЙ СРОК
                            "заключения настоящего договора "               \
                            "составляет 32830,32 ("                         \
                            "тридцать две тысячи восемьсот тридцать "       \
                            "рублей 32 копейки) белорусских рублей.",
                        SECOND_COURSE =                                             // БЮДЖЕТ, ДНЕВНОЕ, СОКРАЩЁННЫЙ СРОК (2 курс)
                            "заключения настоящего договора "               \
                            "составляет 24622,74 ("                         \
                            "двадцать четыре тысячи шестьсот двадцать два " \
                            "рубля 74 копейки) белорусских рублей.";
                }
                namespace EXTRAMURAL
                {
                    const AnsiString
                        FULL_COURSE   =                                             // БЮДЖЕТ, ЗАОЧНОЕ, ПОЛНЫЙ СРОК
                            "заключения настоящего договора "               \
                            "составляет 16415,15 ("                         \
                            "шестнадцать тысяч четыреста пятнадцать "       \
                            "рублей 15 копеек) белорусских рублей.",
                        SECOND_COURSE =                                             // БЮДЖЕТ, ЗАОЧНОЕ, СОКРАЩЁННЫЙ СРОК (2 курс)
                            "заключения настоящего договора "               \
                            "составляет 13132,12 ("                         \
                            "тринадцать тысяч сто тридцать два "            \
                            "рубля 12 копеек) белорусских рублей.",
                        THIRD_COURSE  =                                             // БЮДЖЕТ, ЗАОЧНОЕ, СОКРАЩЁННЫЙ СРОК (3 курс)
                            "заключения настоящего договора "               \
                            "составляет 9849,09 ("                          \
                            "девять тысяч восемьсот сорок девять "          \
                            "рублей 09 копеек) белорусских рублей.";
                }
            }
            namespace BUYERS
            {
                namespace INTRAMURAL
                {
                    const AnsiString                                                // ПЛАТНИКИ, ДНЕВНОЕ, ЗА ГОД
                        ANNUAL       =
                            "составляет 2748 ("                             \
                            "две тысячи семьсот сорок восемь"               \
                            ") белорусских рублей "                         \
                            "за первый год обучения.",
                        PER_SEMESTER =                                              // ПЛАТНИКИ, ДНЕВНОЕ, ПО СЕМЕСТРАМ
                            "1374 ("                                        \
                            "одна тысяча триста семьдесят четыре"           \
                            ") белорусских рублей;";
                }
                namespace EXTRAMURAL
                {
                    const AnsiString
                        ANNUAL           =                                          // ПЛАТНИКИ, ЗАОЧНОЕ, ЗА ГОД (СИиЕ, МВС, ОФК)
                            "составляет 1065 ("                             \
                            "одна тысяча шестьдесят пять"                   \
                            ") белорусских рублей "                         \
                            "за первый год обучения.",
                        ANNUAL_IMS       =                                          // ПЛАТНИКИ, ЗАОЧНОЕ, ЗА ГОД (ИМСиТ)
                            "составляет 1135 ("                             \
                            "одна тысяча сто тридцать пять"                 \
                            ") белорусских рублей "                         \
                            "за первый год обучения.",
                        PER_SEMESTER     =                                          // ПЛАТНИКИ, ЗАОЧНОЕ, ПО СЕМЕСТРАМ (СИиЕ, МВС, ОФК)
                            "532,50 ("                                      \
                            "пятьсот тридцать два "                         \
                            "рубля 50 копеек) белорусских рублей;",
                        PER_SEMESTER_IMS =                                          // ПЛАТНИКИ, ЗАОЧНОЕ, ПО СЕМЕСТРАМ (ИМСиТ)
                            "567,50 ("                                      \
                            "пятьсот шестьдесят семь "                      \
                            "рублей 50 копеек) белорусских рублей;";
                }
            }
        }
    }
    namespace DocumentFile
    {
        namespace APPLICATION_FOR
        {
            const AnsiString
                PARTICIPATION       = "ЗАЯВЛЕНИЕ - Допуск к участию.xls";
        }
        namespace LIST
        {
            const AnsiString
                GROUPS              = "СПИСОК - Групп.xls";                         // NEW (СПИСОК.xls -> СПИСОК - групп.xls)
        }
        namespace PROTOCOL
        {
            AnsiString
                admitted            = "ПРОТОКОЛ - О допуске абитуриентов.doc",      // NEW (OLE Issue) DELETE YEAR
                daily               = "ПРОТОКОЛ - Ежедневный.xls",
                exam                = "ПРОТОКОЛ - Экзамен по ФКиС.xls";
            const AnsiString
                GIRLS_TESTS         = "ПРОТОКОЛ - Испытаний (Девушки).xls";
        }
        namespace REGISTRY
        {
            const AnsiString
                BOOK                = "ЖУРНАЛ - Регистрация.xls";
        }
        namespace REPORT
        {
            const AnsiString
                FORM_1              = "ОТЧЕТ - Форма 1.xls",                        // NEW (INDEX Issue MessageBox) DELETE YEAR
                FORM_2              = "ОТЧЕТ - Форма 2.xls",                        // NEW (INDEX Issue MessageBox, REQUIRE CHECK Section I) DELETE YEAR
                SUBMITTED           = "ОТЧЕТ - Подано заявлений.xls";
        }
        namespace STATISTIC
        {
            AnsiString
                cert_result_hundred =
                    "СТАТИСТИКА - Результаты сертификатов (стобалльная).xls",
                cert_result_ten     =
                    "СТАТИСТИКА - Результаты сертификатов (десятибалльная).xls",    // (REQUIRE CHECK Range)
                exam_result         =
                    "СТАТИСТИКА - Результаты сдачи экзаменов.xls";
            const AnsiString
                ADMISSION_PROGRESS  =
                    "СТАТИСТИКА - Ход приема.xls",                                  // NEW
                CONTEST             =
                    "СТАТИСТИКА - Конкурс.xls",                                     // NEW DELETE YEAR
                DAILY               =
                    "СТАТИСТИКА - Ежедневная.xls",
                LEVEL_OF_SPORTS     =
                    "СТАТИСТИКА - Уровень спортивной подготовки.xls",
                SCORES              =
                    "СТАТИСТИКА - Баллы.xls";                                       // NEW (INSTEAD USEING Abitur_RIO) DELETE YEAR
        }
        namespace SUMMARY_LIST
        {
            const AnsiString
                ENROLLMENT          = "ВЕДОМОСТЬ - Зачисление.xls",                 // NEW
                ENTRANCE_EXAMS      = "ВЕДОМОСТЬ - Вступительных экзаменов.xls";    // NEW DELETE YEAR
        }
    }
    namespace DocumentName
    {
        namespace APPLICATION_FOR
        {
            const AnsiString
                PARTICIPATION      = "ЗАЯВЛЕНИЕ - Допуск к участию";
        }
        namespace LIST
        {
            const AnsiString
                GROUPS             = "СПИСОК - Групп",                              // NEW (СПИСОК -> СПИСОК - групп)
                BY_DESTINATIONS    = "СПИСОК - По направлениям",                    // NEW
                BY_GENDER          = "СПИСОК - По полу";                            // NEW
        }
        namespace PROTOCOL
        {
            AnsiString
                daily              = "ПРОТОКОЛ - Ежедневный",
                exam               = "ПРОТОКОЛ - Экзамен по ФКиС";
            const AnsiString
                GIRLS_TESTS        = "ПРОТОКОЛ - Испытаний (Девушки)";
        }
        namespace REGISTRY
        {
            const AnsiString
                BOOK               = "ЖУРНАЛ - Регистрация";
        }
        namespace REPORT
        {
            const AnsiString
                FORM_1             = "ОТЧЕТ - Форма 1",
                FORM_2             = "ОТЧЕТ - Форма 2",
                SUBMITTED          = "ОТЧЕТ - Подано заявлений";                    // (REQUIRE CHECK Calcalation)
        }
        namespace STATISTIC
        {
            const AnsiString
                ADMISSION_PROGRESS =
                    "СТАТИСТИКА - Ход приема",                                      // NEW
                CONTEST            =
                    "СТАТИСТИКА - Конкурс",
                DAILY              =
                    "СТАТИСТИКА - Ежедневная",
                LEVEL_OF_SPORTS    =
                    "СТАТИСТИКА - Уровень спортивной подготовки",
                SCORES             =
                    "СТАТИСТИКА - Баллы";                                           // INSTEAD USEING Abitur_RIO
        }
        namespace SUMMARY_LIST
        {
            const AnsiString
                ENROLLMENT         = "ВЕДОМОСТЬ - Зачисление",                      // NEW
                ENTRANCE_EXAMS     = "ВЕДОМОСТЬ - Вступительных экзаменов";
        }
    }
    namespace EducationType
    {
        const AnsiString
            EXTRAMURAL = "заочное",
            INTRAMURAL = "дневное",
            EXTRA_FORM = "заочной",
            INTRA_FORM = "дневной";
    }
    namespace EnvelopeMessage
    {
        namespace BUDGET
        {
            const AnsiString
                EXTRAMURAL = "бюджет, заочная форма обучения",
				INTRAMURAL = "бюджет, дневная форма обучения";
        }
        namespace BUYERS
        {
            const AnsiString
                EXTRAMURAL = "за оплату, заочная форма обучения",
                INTRAMURAL = "за оплату, дневная форма обучения";
        }
    }
    namespace Faculty
    {
        const AnsiString
            SMA  = "СИиЕ",                                                          // 1, -> Sports and Marital Arts (СИиЕ)
            MS   = "МВС",                                                           // 2, -> Mass Sports (МВС)
            RPC  = "ОФК",                                                           // 3, -> Recreational Physical Culture (ОФКиТ)
            MSTH = "МСТиГ",                                                         // 4, -> Management of Sports, Tourism and Hospitality (МСиТ)
            MD   = "Магстратура",                                                   // 5, -> Master's Degree (Магстратура)
            PGS  = "Аспирантура",                                                   // 6, -> PostGraduate Studies (Аспирантура)
            DOC  = "Докторантура";                                                  // 7  -> DOCtorate (Докторантура)
    }
    namespace LegallyAuthorizedPerson
    {
        AnsiString
            edu_head_desc  = "Ермакову А.А.";
        const AnsiString
            DEAN_FACULTY_1 = "В.И.Новицкая",                                        // СИиЕ  (SMA)  - Sports and Marital Arts
            DEAN_FACULTY_2 = "И.И.Гуслистова",                                      // МВС   (MS)   - Mass Sports
            DEAN_FACULTY_3 = "Н.М.Машарская",                                       // ОФКиТ (RPC)  - Recreational Physical Culture
            DEAN_FACULTY_4 = "О.Н.Михайлова",                                       // МСиТ  (MSTH) - Management of Sports, Tourism and Hospitality
            SECRETARY      = "А.И. Лихач",
            SECRETARY_DESC = "Лихач А.И.",
			VICE_RECTOR    = "Г.И.Башлакова";
    }

    namespace DeaneryDB
    {
        namespace QUALIFICATION
        {
            const AnsiString
                TEACHER_PHYSICAL_CULTURE_SPORTS  =
                    "Преподаватель физической культуры и спорта",
                COACHING_BY_SPORT                =
                    "Тренер по виду спорта",
                PHYSICAL_EDUCATION_TEACHER       =
                    "Учитель физической культуры",
                TEACHER_ORGANIZER_HEALTH_TOURISM =
                    "Педагог-организатор физкультурно-оздоровительной "     \
                    "работы и туризма",
                TEACHER_ORGANIZER_PRESCHOOLERS   =
                    "Педагог-организатор физического воспитания в "         \
                    "дошкольных учреждениях",
                MANAGER_SPORT_TOURISM            =
                    "Менеджер спорта и туризма",
                INSTRUCTOR_REHABILITATION        =
                    "Инструктор-методист физической реабилитации",
                INSTRUCTOR_MEDICAL               =
                    "Инструктор-методист лечебной физической культуры",
                TEACHER_PHYSICAL_CULTURE         =
                    "Преподаватель физической культуры",
                INSTRUCTOR_BY_HEALTH             =
                    "Инструктор-методист по оздоровительной физической "    \
                    "культуре",
                INSTRUCTOR_BY_ADAPTIVE           =
                    "Инструктор-методист по адаптивной физической "         \
                    "культуре",
                INSTRUCTOR_PRESCHOOLERS          =
                    "Инструктор-методист физического воспитания в "         \
                    "дошкольных учреждениях",
                PSYCHOLOGIST                     =
                    "Психолог",
                MANAGER_SPORT                    =
                    "Менеджер в спорте",
                MANAGER_TUORISM                  =
                    "Менеджер по туризму",
                INSTRUCTOR_RECREATIONAL          =
                    "Инструктор-методист по туризму",
                MANAGER_DIRECTING                =
                    "Менеджер-режиссер спортивно-массовых мероприятий",
                INSTRUCTOR_BY_MEDICAL            =
                    "Инструктор-методист по лечебной физической культуре",
                INSTRUCTOR_BY_REHABILITATION     =
                    "Инструктор-методист по физической реабилитации",
                INSTRUCTOR_BY_ERGOTHERAPY        =
                    "Инструктор-методист по эрготерапии",
                SPECIALIST_TOURISM_HOSPITALITY   =
                    "Специалист в сфере туризма и гостеприимства";
        }
    }
    namespace NCRB_011                                                                  // National Classifier of the Republic of Belarus
    {
        namespace _2009
        {
            namespace CODE
            {
                namespace PART
                {
                    const AnsiString
                        BIOLOGICAL_SCIENCES            = "03.00.00",                // Master degree
                        PEDAGOGICAL_SCIENCES           = "13.00.00",                // Master degree
                        PEDAGOGY_PROFESSIONAL          = "1-08",                    // Master degree
                        COMMUNICATION_SCIENCES         = "1-26",                    // Master degree
                        PHYSICAL_CULTURE_AND_SPORT     = "1-88",
                        TOURISM_HOSPITALITY            = "1-89";
                }
                namespace CHAPTER
                {
                    const AnsiString
                        PHYSIOLOGY                     = "03.03.01",                // Master degree
                        THEORY_IMPROVING               = "13.00.04",                // Master degree
                        RESEARCH_AND_DEVELOPMENT       = "1-08 80",                 // Master degree
                        MANAGEMENT                     = "1-26 80",                 // Master degree
                        PHYSICAL_CULTURE               = "1-88 01",
                        SPORT                          = "1-88 02",
                        TOURISM_HOSPITALITY            = "1-89 01",
                        TOURISM                        = "1-89 02",
                        HOSPITALITY                    = "1-89 03",
                        RESEARCH_AND_TEACHING          = "1-89 80",                 // Master degree
                        INNOVATION                     = "1-89 81";                 // Master degree
                }
                namespace SECTION
                {
                    const AnsiString
                        RESEARCH_SPORT                 = "1-08 80 04",              // Master degree
                        RESEARCH_MANAGEMENT            = "1-26 80 04",              // Master degree
                        PHYSICAL_CULTURE               = "1-88 01 01",
                        IMPROVING_AND_ADAPTIVE         = "1-88 01 02",
                        REHABILITATION_ERGOTHERAPY     = "1-88 01 03",
                        TRAINING_MILITARY_PERSONNEL    = "1-88 01 04",
                        SPORTS_AND_PEDAGOGY            = "1-88 02 01",
                        SPORTS_CHOREOGRAPHY            = "1-88 02 72",
                        TOURISM_HOSPITALITY            = "1-89 01 01",
                        SPORTS_AND_TOURISM             = "1-89 02 01",
                        TOURISM_AND_NATURE_MANAGEMENT  = "1-89 02 02",
                        HOSPITALITY_TECHNOLOGIES       = "1-89 03 01",
                        RESEARCH_TOURISM_HOSPITALITY   = "1-89 80 01",              // Master degree
                        INNOVATION_MANAGEMENT          = "1-89 81 01",              // Master degree
                        INNOVATION_TOURISM             = "1-89 81 02",              // Master degree
                        INNOVATION_HOSPITALITY         = "1-89 81 03",              // Master degree
                        INNOVATION_TECHNOLOGY          = "1-89 81 04";              // Master degree
                }
                namespace SUBSECTION
                {
                    const AnsiString
                        MEDICAL                       = "1-88 01 01-01",
                        PRESCHOOLERS                  = "1-88 01 01-02",
                        HEALTH                        = "1-88 01 02-01",
                        ADAPTIVE                      = "1-88 01 02-02",
                        REHABILITATION                = "1-88 01 03-01",
                        ERGOTHERAPY                   = "1-88 01 03-02",
                        COACHING                      = "1-88 02 01-01",
                        MANAGEMENT                    = "1-88 02 01-02",
                        PSYCHOLOGY                    = "1-88 02 01-03",
                        DIRECTING                     = "1-88 02 01-04",
                        PROMOTION                     = "1-89 01 01 01",
                        IT                            = "1-89 01 01 02",
                        LOGISTICS                     = "1-89 01 01 03",
                        SOCIAL                        = "1-89 01 01 04",
                        TRANSPORT                     = "1-89 01 01 05",
                        CATERING                      = "1-89 01 01 06",
                        ACCOMMODATION                 = "1-89 01 01 07",
                        SUPPORTING                    = "1-89 01 01 08",
                        TREATMENT                     = "1-89 01 01 09",
                        RECREATIONAL                  = "1-89 02 01-01",
                        TUORISM_MNG                   = "1-89 02 01-02",
                        RESTAURANTS                   = "1-89 03 01-01";
                }
                namespace MASTER_DEGREE
                {
                    namespace SCIENCE
                    {
                        const AnsiString
                            PHYSIOLOGY  = "03.03.01",
                            THEORY      = "13.00.04";
                    }
                    namespace RESEARCH
                    {
                        const AnsiString
                            SPORT       = "1-08 80 04",
                            MANAGEMENT  = "1-26 80 04",
                            TOURISM     = "1-89 80 01";
                    }
                    namespace INNOVATION
                    {
                        const AnsiString
                            MANAGEMENT  = "1-89 81 01",
                            TOURISM     = "1-89 81 02",
                            HOSPITALITY = "1-89 81 03",
                            TECHNO      = "1-89 81 04";
                    }
                }
                namespace PHYSICAL_CULTURE
                {
                    const AnsiString
                        MEDICAL      = "1-88 01 01-01",
                        PRESCHOOLERS = "1-88 01 01-02";
                }
                namespace IMPROVING
                {
                    const AnsiString
                        HEALTH   = "1-88 01 02-01",
                        ADAPTIVE = "1-88 01 02-02";
                }
                namespace REHABILITATION
                {
                    const AnsiString
                        REHABILITATION = "1-88 01 03-01",
                        ERGOTHERAPY    = "1-88 01 03-02";
                }
                namespace MILITARY
                {
                    const AnsiString
                        TRAINING = "1-88 01 04";
                }
                namespace SPORT
                {
                    const AnsiString
                        COACHING   = "1-88 02 01-01",
                        MANAGEMENT = "1-88 02 01-02",
                        PSYCHOLOGY = "1-88 02 01-03",
                        DIRECTING  = "1-88 02 01-04";
                }
                namespace TOURISM_HOSPITALITY
                {
                    const AnsiString
                        PROMOTION     = "1-89 01 01 01",
                        IT            = "1-89 01 01 02",
                        LOGISTICS     = "1-89 01 01 03",
                        SOCIAL        = "1-89 01 01 04",
                        TRANSPORT     = "1-89 01 01 05",
                        CATERING      = "1-89 01 01 06",
                        ACCOMMODATION = "1-89 01 01 07",
                        SUPPORTING    = "1-89 01 01 08",
                        TREATMENT     = "1-89 01 01 09";
                }
                namespace TOURISM
                {
                    const AnsiString
                        RECREATIONAL = "1-89 02 01-01",
                        TUORISM_MNG  = "1-89 02 01-02";
                }
                namespace HOSPITALITY
                {
                    const AnsiString
                        RESTAURANTS = "1-89 03 01-01";
                }
            }
            namespace NAME
            {
                namespace PART
                {
                    const AnsiString
                        BIOLOGICAL_SCIENCES        =                                // Master degree
                            "Биологические науки",
                        PEDAGOGICAL_SCIENCES       =                                // Master degree
                            "Педагогические науки",
                        PEDAGOGY_PROFESSIONAL      =                                // Master degree
                            "Педагогика. Профессиональное образование",
                        COMMUNICATION_SCIENCES     =                                // Master degree
                            "Управление",
                        PHYSICAL_CULTURE_AND_SPORT =
                            "Физическая культура и спорт",
                        TOURISM_HOSPITALITY        =
                            "Туризм. Гостеприимство";
                }
                namespace CHAPTER
                {
                    const AnsiString
                        PHYSIOLOGY               =                                  // Master degree
                            "Физиология",
                        THEORY_IMPROVING         =                                  // Master degree
                            "Теория и методика физического воспитания, "        \
                            "спортивной тренировки, оздоровительной и "         \
                            "адаптивной физической культуры",
                        RESEARCH_AND_DEVELOPMENT =                                  // Master degree
                            "Научные исследования и разработки, преподавание",
                        PHYSICAL_CULTURE         =
                            "Физическая культура",
                        SPORT                    =
                            "Спорт",
                        TOURISM_HOSPITALITY      =
                            "Туризм и гостеприимство",
                        TOURISM                  =
                            "Туризм",
                        HOSPITALITY              =
                            "Гостеприимство",
                        RESEARCH_AND_TEACHING    =                                  // Master degree
                            "Научные исследования и разработки, преподавание",
                        INNOVATION                     =                            // Master degree
                            "Инновационная деятельность (с углубленной "        \
                            "подготовкой специалистов)";
                }
                namespace SECTION
                {
                    const AnsiString
                        RESEARCH_SPORT                 =                            // Master degree
                            "Физическая культура и спорт",
                        PHYSICAL_CULTURE              =
                            "Физическая культура (по направлениям)",
                        IMPROVING_AND_ADAPTIVE        =
                            "Оздоровительная и адаптивная физическая культура " \
                            "(по направлениям)",
                        REHABILITATION_ERGOTHERAPY    =
                            "Физическая реабилитация и эрготерапия "            \
                            "(по направлениям)",
                        TRAINING_MILITARY_PERSONNEL   =
                            "Физическая подготовка военнослужащих",
                        SPORTS_AND_PEDAGOGY           =
                            "Спортивно-педагогическая деятельность",
                        SPORTS_CHOREOGRAPHY           =
                            "Спортивная хореография",
                        TOURISM_HOSPITALITY       =
                            "Туризм и гостеприимство",
                        SPORTS_AND_TOURISM            =
                            "Спортивно-туристская деятельность "                \
                            "(по направлениям)",
                        TOURISM_AND_NATURE_MANAGEMENT =
                            "Туризм и природопользование",
                        HOSPITALITY_TECHNOLOGIES      =
                            "Технология индустрии гостеприимства "              \
                            "(по направлениям)",
                        TOURISM_HOSPITALITY_STUDY =
                            "Туризм и гостеприимство",
                        RESEARCH_TOURISM_HOSPITALITY   =                            // Master degree
                            "Туризм и гостеприимство",
                        INNOVATION_MANAGEMENT          =                            // Master degree
                            "Управление инновационными проектами в "            \
                            "туристской индустрии",
                        INNOVATION_TOURISM             =                            // Master degree
                            "Инновационный менеджмент в сфере туризма",
                        INNOVATION_HOSPITALITY         =                            // Master degree
                            "Инновационный менеджмент в сфере гостеприимства",
                        INNOVATION_TECHNOLOGY          =                            // Master degree
                            "Инновационные технологии в сфере туризма и "       \
                            "гостеприимства";
                }
                namespace SUBSECTION
                {
                    const AnsiString
                        MEDICAL        =
                            "Физическая культура (лечебная)",
                        PRESCHOOLERS   =
                            "Физическая культура (дошкольников)",
                        HEALTH         =
                            "Оздоровительная и адаптивная физическая культура " \
                            "(оздоровительная)",
                        ADAPTIVE       =
                            "Оздоровительная и адаптивная физическая культура " \
                            "(адаптивная)",
                        REHABILITATION =
                            "Физическая реабилитация и эрготерапия "            \
                            "(физическая реабилитация)",
                        ERGOTHERAPY    =
                            "Физическая реабилитация и эрготерапия "            \
                            "(эрготерапия)",
                        COACHING       =
                            "Спортивно-педагогическая деятельность "            \
                            "(тренерская работа с указанием вида спорта)",
                        MANAGEMENT     =
                            "Спортивно-педагогическая деятельность "            \
                            "(менеджмент в спорте)",
                        PSYCHOLOGY     =
                            "Спортивно-педагогическая деятельность "            \
                            "(спортивная психология)",
                        DIRECTING      =
                            "Спортивно-педагогическая деятельность "            \
                            "(спортивная режиссура)",
                        PROMOTION      =
                            "Технологии формирования и продвижения "            \
                            "туристических услуг",
                        IT             =
                            "Информационные технологии туристической "          \
                            "индустрии",
                        LOGISTICS      =
                            "Логистика в туристической индустрии",
                        SOCIAL         =
                            "Технологии социокультурного сервиса туристов",
                        TRANSPORT      =
                            "Технологии транспортного сервиса туристов",
                        CATERING       =
                            "Технологии сервиса питания туристов",
                        ACCOMMODATION  =
                            "Технологии сервиса размещения туристов",
                        SUPPORTING     =
                            "Технологии экскурсионно-сопроводительного "        \
                            "сервиса туристов",
                        TREATMENT      =
                            "Технологии сервиса оздоровления и лечения "        \
                            "туристов",
                        RECREATIONAL   =
                            "Спортивно-туристская деятельность "                \
                            "(спортивный и рекреационный туризм)",
                        TUORISM_MNG    =
                            "Спортивно-туристская деятельность "                \
                            "(менеджмент в туризме)",
                        RESTAURANTS    =
                            "Технология индустрии гостеприимства "              \
                            "(ресторанная деятельность)";
                }
                namespace MASTER_DEGREE
                {
                    namespace SCIENCE
                    {
                        const AnsiString
                            PHYSIOLOGY  =
                                "Физиология",
                            THEORY      =
                                "Теория и методика физического воспитания, "    \
                                "спортивной тренировки, оздоровительной и "     \
                                "адаптивной физической культуры";
                    }
                    namespace RESEARCH
                    {
                        const AnsiString
                            SPORT       =
                                "Физическая культура и спорт",
                            MANAGEMENT  =
                                "Менеджмент",
                            TOURISM     =
                                "Туризм и гостеприимство";
                    }
                    namespace INNOVATION
                    {
                        const AnsiString
                            MANAGEMENT  =
                                "Управление инновационными проектами в "        \
                                "туристской индустрии",
                            TOURISM     =
                                "Инновационный менеджмент в сфере туризма",
                            HOSPITALITY =
                                "Инновационный менеджмент в сфере "             \
                                "гостеприимства",
                            TECHNO  =
                                "Инновационные технологии в сфере туризма и "   \
                                "гостеприимства";
                    }
                }
                namespace PHYSICAL_CULTURE
                {
                    const AnsiString
                        MEDICAL        = "Физическая культура (лечебная)",
                        PRESCHOOLERS   = "Физическая культура (дошкольников)";
                }
                namespace IMPROVING
                {
                    const AnsiString
                        HEALTH         =
                            "Оздоровительная и адаптивная физическая культура " \
                            "(оздоровительная)",
                        ADAPTIVE       =
                            "Оздоровительная и адаптивная физическая культура " \
                            "(адаптивная)";
                }
                namespace REHABILITATION
                {
                    const AnsiString
                        REHABILITATION =
                            "Физическая реабилитация и эрготерапия "            \
                            "(физическая реабилитация)",
                        ERGOTHERAPY    =
                            "Физическая реабилитация и эрготерапия "            \
                            "(эрготерапия)";
                }
                namespace MILITARY
                {
                    const AnsiString
                        TRAINING       = "Физическая подготовка военнослужащих";
                }
                namespace SPORT
                {
                    const AnsiString
                        COACHING       =
                            "Спортивно-педагогическая деятельность "            \
                            "(тренерская работа с указанием вида спорта)",
                        MANAGEMENT     =
                            "Спортивно-педагогическая деятельность "            \
                            "(менеджмент в спорте)",
                        PSYCHOLOGY     =
                            "Спортивно-педагогическая деятельность "            \
                            "(спортивная психология)",
                        DIRECTING      =
                            "Спортивно-педагогическая деятельность "            \
                            "(спортивная режиссура)";
                }
                namespace TOURISM_HOSPITALITY
                {
                    const AnsiString
                        PROMOTION      =
                            "Технологии формирования и продвижения "            \
                            "туристических услуг",
                        IT             =
                            "Информационные технологии туристической индустрии",
                        LOGISTICS      =
                            "Логистика в туристической индустрии",
                        SOCIAL         =
                            "Технологии социокультурного сервиса туристов",
                        TRANSPORT      =
                            "Технологии транспортного сервиса туристов",
                        CATERING       =
                            "Технологии сервиса питания туристов",
                        ACCOMMODATION  =
                            "Технологии сервиса размещения туристов",
                        SUPPORTING     =
                            "Технологии экскурсионно-сопроводительного "        \
                            "сервиса туристов",
                        TREATMENT      =
                            "Технологии сервиса оздоровления и лечения "        \
                            "туристов";
                }
                namespace TOURISM
                {
                    const AnsiString
                        RECREATIONAL   =
                            "Спортивно-туристская деятельность "                \
                            "(спортивный и рекреационный туризм)",
                        TUORISM_MNG    =
                            "Спортивно-туристская деятельность "                \
                            "(менеджмент в туризме)";
                }
                namespace HOSPITALITY
                {
                    const AnsiString
                        RESTAURANTS    =
                            "Технология индустрии гостеприимства "              \
                            "(ресторанная деятельность)";
                }
            }
            namespace QUALIFICATION
            {
                namespace SUBSECTION
                {
                    const AnsiString
                        MEDICAL        =
                            "Инструктор-методист по лечебной физической "       \
                            "культуре. Преподаватель физической культуры",
                        PRESCHOOLERS   =
                            "Инструктор-методист физического воспитания в "     \
                            "дошкольных учреждениях. "                          \
                            "Преподаватель физической культуры",
                        HEALTH         =
                            "Инструктор-методист по оздоровительной "           \
                            "физической культуре. "                             \
                            "Преподаватель физической культуры",
                        ADAPTIVE       =
                            "Инструктор-методист по адаптивной "                \
                            "физической культуре. "                             \
                            "Преподаватель физической культуры",
                        REHABILITATION =
                            "Инструктор-методист по физической "                \
                            "реабилитации. "                                    \
                            "Преподаватель физической культуры",
                        ERGOTHERAPY    =
                            "Инструктор-методист по эрготерапии. "              \
                            "Преподаватель физической культуры",
                        TRAINING       =
                            "Специалист по управлению. "                        \
                            "Инструктор-методист по физической "                \
                            "подготовке",
                        COACHING       =
                            "Тренер (по виду спорта). "                         \
                            "Преподаватель физической культуры",
                        MANAGEMENT     =
                            "Менеджер в спорте. "                               \
                            "Преподаватель физической культуры",
                        PSYCHOLOGY     =
                            "Психолог. "                                        \
                            "Преподаватель физической культуры",
                        DIRECTING      =
                            "Менеджер-режиссер спортивно-массовых "             \
                            "мероприятий."                                      \
                            "Преподаватель физической культуры",
                        PROMOTION      =
                            "Специалист в сфере туризма и гостеприимства",
                        IT             =
                            "Специалист в сфере туризма и гостеприимства",
                        LOGISTICS      =
                            "Специалист в сфере туризма и гостеприимства",
                        SOCIAL         =
                            "Специалист в сфере туризма и гостеприимства",
                        TRANSPORT      =
                            "Специалист в сфере туризма и гостеприимства",
                        CATERING       =
                            "Специалист в сфере туризма и гостеприимства",
                        ACCOMMODATION  =
                            "Специалист в сфере туризма и гостеприимства",
                        SUPPORTING     =
                            "Специалист в сфере туризма и гостеприимства",
                        TREATMENT      =
                            "Специалист в сфере туризма и гостеприимства",
                        RECREATIONAL   =
                            "Инструктор-методист по туризму. "                  \
                            "Преподаватель физической культуры",
                        TUORISM_MNG    =
                            "Менеджер по туризму. "                             \
                            "Преподаватель физической культуры",
                        RESTAURANTS    = "Менеджер. Технолог";
                }
                namespace MASTER_DEGREE
                {
                    namespace SCIENCE
                    {
                        const AnsiString
                            PHYSIOLOGY  = "Магистр",
                            THEORY      = "Магистр";
                    }
                    namespace RESEARCH
                    {
                        const AnsiString
                            SPORT       = "Магистр",
                            MANAGEMENT  = "Магистр",
                            TOURISM     = "Магистр";
                    }
                    namespace INNOVATION
                    {
                        const AnsiString
                            MANAGEMENT  = "Магистр",
                            TOURISM     = "Магистр",
                            HOSPITALITY = "Магистр",
                            TECHNO      = "Магистр";
                    }
                }
                namespace PHYSICAL_CULTURE
                {
                    const AnsiString
                        MEDICAL        =
                            "Инструктор-методист по лечебной физической "       \
                            "культуре. Преподаватель физической культуры",
                        PRESCHOOLERS   =
                            "Инструктор-методист физического воспитания в "     \
                            "дошкольных учреждениях. "                          \
                            "Преподаватель физической культуры";
                }
                namespace IMPROVING
                {
                    const AnsiString
                        HEALTH         =
                            "Инструктор-методист по оздоровительной "           \
                            "физической культуре. "                             \
                            "Преподаватель физической культуры",
                        ADAPTIVE       =
                            "Инструктор-методист по адаптивной "                \
                            "физической культуре. "                             \
                            "Преподаватель физической культуры";
                }
                namespace REHABILITATION
                {
                    const AnsiString
                        REHABILITATION =
                            "Инструктор-методист по физической "                \
                            "реабилитации. "                                    \
                            "Преподаватель физической культуры",
                        ERGOTHERAPY    =
                            "Инструктор-методист по эрготерапии. "              \
                            "Преподаватель физической культуры";
                }
                namespace MILITARY
                {
                    const AnsiString
                        TRAINING       =
                            "Специалист по управлению. "                        \
                            "Инструктор-методист по физической "                \
                            "подготовке";
                }
                namespace SPORT
                {
                    const AnsiString
                        COACHING       =
                            "Тренер (по виду спорта). "                         \
                            "Преподаватель физической культуры",
                        MANAGEMENT     =
                            "Менеджер в спорте. "                               \
                            "Преподаватель физической культуры",
                        PSYCHOLOGY     =
                            "Психолог. "                                        \
                            "Преподаватель физической культуры",
                        DIRECTING      =
                            "Менеджер-режиссер спортивно-массовых "             \
                            "мероприятий."                                      \
                            "Преподаватель физической культуры";
                }
                namespace TOURISM_HOSPITALITY
                {
                    const AnsiString
                        PROMOTION      =
                            "Специалист в сфере туризма и гостеприимства",
                        IT             =
                            "Специалист в сфере туризма и гостеприимства",
                        LOGISTICS      =
                            "Специалист в сфере туризма и гостеприимства",
                        SOCIAL         =
                            "Специалист в сфере туризма и гостеприимства",
                        TRANSPORT      =
                            "Специалист в сфере туризма и гостеприимства",
                        CATERING       =
                            "Специалист в сфере туризма и гостеприимства",
                        ACCOMMODATION  =
                            "Специалист в сфере туризма и гостеприимства",
                        SUPPORTING     =
                            "Специалист в сфере туризма и гостеприимства",
                        TREATMENT      =
                            "Специалист в сфере туризма и гостеприимства";
                }
                namespace TOURISM
                {
                    const AnsiString
                        RECREATIONAL   =
                            "Инструктор-методист по туризму. "                  \
                            "Преподаватель физической культуры",
                        TUORISM_MNG    =
                            "Менеджер по туризму. "                             \
                            "Преподаватель физической культуры";
                }
                namespace HOSPITALITY
                {
                    const AnsiString
                        RESTAURANTS    = "Менеджер. Технолог";
                }
            }
        }
        namespace _2022
        {
            namespace CODE
            {
                const AnsiString
                    PHYSIOLOGY       = "03.03.01",                                  // Master degree
                    THEORY_IMPROVING = "13.00.04",                                  // Master degree
                    INNO_MANAGEMENT  = "1-89 81 01",                                // Master degree
                    INNO_TOURISM     = "1-89 81 02",                                // Master degree
                    INNO_HOSPITALITY = "1-89 81 03",                                // Master degree
                    INNO_TECHNOLOGY  = "1-89 81 04",                                // Master degree
                    PHYSICAL_CULTURE = "6-05-1012-01",
                    COACHING         = "6-05-1012-02",
                    REHABILITATION   = "6-05-1012-03",
                    MANAGEMENT       = "6-05-1012-04",
                    TOURISM          = "6-05-1013-01",
                    NATURE           = "6-05-1013-03",
                    HOSPITALITY      = "6-05-1013-04",
                    MNG_MASTER_DEGREE = "7-06-0412-01",
                    PC_MASTER_DEGREE = "7-06-1012-01",                              // Master degree
                    TH_MASTER_DEGREE = "7-06-1013-01",                              // Master degree
                    CHOREOGRAPHY     = "9-09-1012-04";                              // Master degree
            }
            namespace NAME
            {
                const AnsiString
                    PHYSIOLOGY       =                                              // Master degree
                        "Физиология",
                    THEORY_IMPROVING =                                              // Master degree
                        "Теория и методика физического воспитания, "        \
                        "спортивной тренировки, оздоровительной и "         \
                        "адаптивной физической культуры",
                    INNO_MANAGEMENT  =                                              // Master degree
                        "Управление инновационными проектами в "            \
                        "туристской индустрии",
                    INNO_TOURISM     =                                              // Master degree
                        "Инновационный менеджмент в сфере туризма",
                    INNO_HOSPITALITY =                                              // Master degree
                        "Инновационный менеджмент в сфере гостеприимства",
                    INNO_TECHNOLOGY  =                                              // Master degree
                        "Инновационные технологии в сфере туризма и "       \
                        "гостеприимства",
                    PHYSICAL_CULTURE =
                        "Физическая культура",
                    COACHING         =
                        "Тренерская деятельность",
                    REHABILITATION   =
                        "Физическая реабилитация и эрготерапия",
                    MANAGEMENT       =
                        "Организация и управление физической культурой, "   \
                        "спортом и туризмом",
                    TOURISM          =
                        "Туризм и гостеприимство",
                    NATURE           =
                        "Туризм и природопользование",
                    HOSPITALITY      =
                        "Технология индустрии гостеприимства",
                    PC_MASTER_DEGREE =                                              // Master degree
                        "Физическая культура и спорт",
                    TH_MASTER_DEGREE =                                              // Master degree
                        "Туризм и гостеприимство",
                    CHOREOGRAPHY     =
                        "Спортивная хореография";

                namespace PHYSICAL
                {
                    const AnsiString
                        IMPROVING      = "(оздоровительная)",                       // "(оздоровительная физическая культура)",
                        HEALTH         = "(лечебная)",                              // "(лечебная физическая культура)",
                        PRESCHOOLERS   = "(дошкольников)",                          // "(физическая культура дошкольников)",
                        ADAPTIVE       = "(адаптивная)",                            // "(адаптивная физическая культура)",
                        DIRECTING      = "(спортивная режиссура)",
                        PSYCHOLOGY     = "(спортивная психология)",
                        RECREATIONAL   = "(спортивный и рекреационный туризм)";
                }
                namespace COACH
                {
                    const AnsiString
                        DEFAULT        = "(с указанием вида спорта)";
                }
                namespace REHABILITATE
                {
                    const AnsiString
                        REHABILITATION = "(физическая реабилитация)",
                        ERGOTHERAPY    = "(эрготерапия)";
                }
                namespace MANAGE
                {
                    const AnsiString
                        SPORT          = "(менеджмент в спорте)",
                        TOURISM        = "(менеджмент в туризме)";
                }
            }
            namespace QUALIFICATION
            {
                const AnsiString
                    PHYSIOLOGY       = "Магистр",                                   // Master degree
                    THEORY_IMPROVING = "Магистр",                                   // Master degree
                    INNO_MANAGEMENT  = "Магистр управления",                        // Master degree
                    INNO_TOURISM     = "Магистр туризма",                           // Master degree
                    INNO_HOSPITALITY = "Магистр гостеприимства",                    // Master degree
                    INNO_TECHNOLOGY  = "Магистр инноваций",                         // Master degree
                    PHYSICAL_CULTURE = "Инструктор-методист. Преподаватель",
                    COACHING         = "Тренер. Преподаватель",
                    REHABILITATION   = "Инструктор-методист. Преподаватель",
                    MANAGEMENT       = "Менеджер. Преподаватель",
                    TOURISM          = "Специалист",
                    NATURE           = "Специалист по туризму и природопользованию",
                    HOSPITALITY      = "Менеджер. Технолог",
                    PC_MASTER_DEGREE = "Магистр",                                   // Master degree
                    TH_MASTER_DEGREE = "Магистр",                                   // Master degree
                    CHOREOGRAPHY     = "Инструктор-методист";
            }
        }
    }
    namespace KindOfSport
    {
        const AnsiString
            GYMNASTICS                   =
                "Гимнастика",
            MANAGEMENT_SPORTS_TOURISM    =
                "Менеджмент спорта и туризма",
            PHYSICAL_REHABILITATION      =
                "Физическая реабилитация",
            THERAPEUTIC                  =
                "Лечебная физическая культура",
            ORGANIZATION_SPORTS_TOURISM  =
                "Организация физкультурно-оздоровительной "         \
                "работы и туризма",
            PRESCHOOL_PHYSICAL_EDUCATION =
                "Дошкольное физическое воспитание",
            DANCE_SPORT                  =
                "Танцевальный спорт",
            AEROBICS                     =
                "Аэробика",
            ROWING_OTHER                 =
                "Гребной спорт",
            SWIMMING                     =
                "Плавание",
            SAILING                      =
                "Парусный спорт",
            ATHLETICS                    =
                "Легкая атлетика",
            CROSS_COUNTRY_SKIING         =
                "Лыжные гонки",
            BULLET_SHOOTING_DEANERY      =
                "Пулевая стрельба",
            HAND_TO_HAND_COMBAT          =
                "Рукопашный бой",
            TAEKWONDO                    =
                "Таэквондо",
            KARATE                       =
                "Каратэ",
            SKIING                       =
                "Лыжный спорт",
            AUTOMOTIVE_SPORT             =
                "Автомобильный спорт",
            BASKETBALL                   =
                "Баскетбол",
            BOXING                       =
                "Бокс",
            GRECO_FREESTYLE_WRESTLING    =
                "Греко-римская и вольная борьба",
            CYCLING                      =
                "Велосипедный спорт",
            VOLLEYBALL                   =
                "Волейбол",
            HANDBALL                     =
                "Гандбол",
            EQUESTRIAN                   =
                "Конный спорт",
            SPEED_SKATING                =
                "Конькобежный спорт",
            TENNIS                       =
                "Теннис",
            WEIGHTLIFTING                =
                "Тяжелая атлетика",
            FENCING                      =
                "Фехтование",
            FIGURE_SKATING_OLD           =
                "Фигурное катание",
            FOOTBALL                     =
                "Футбол",
            HOCKEY                       =
                "Хоккей",
            SAMBO_JUDO                   =
                "Самбо-дзюдо",
            WRESTLING                    =
                "Спортивная борьба",
            FOOTBALL_HOCKEY              =
                "Футбол и хоккей",
            BIATHLON                     =
                "Биатлон",
            HEALTH_IMPROVING             =
                "Оздоровительная физическая культура",
            ADAPTIVE                     =
                "Адаптивная физическая культура",
            FREESTYLE_WRESTLING          =
                "Вольная борьба",
            GRECO_ROMAN_WRESTLING        =
                "Греко-римская борьба",
            SAMBO                        =
                "Самбо",
            JUDO                         =
                "Дзюдо",
            TABLE_TENNIS_ABITURIENT      =
                "Теннис настольный",
            ERGOTHERAPY                  =
                "Эрготерапия",
            MANAGEMENT_SPORTS            =
                "Менеджмент в спорте",
            SPORTS_DIRECTING_DEANERY     =
                "Спортивная режиссура",
            SPORTS_RECREATIONAL_TOURISM  =
                "Спортивный и рекреационный туризм",
            MANAGEMENT_TOURISM           =
                "Менеджмент в туризме",
            SPORTS_PSYCHOLOGY            =
                "Спортивная психология",
            BILLIARD_SPORTS              =
                "Бильярдный спорт",
            ACROBATICS                   =
                "Акробатика",
            ORIENTEERING                 =
                "Спортивное ориентирование",
            SPORTS_DIRECTING             =
                "Спортивная режиссура",
            PRESCHOOLERS                 =
                "Физическая культура дошкольников",
            MOUNTAINEERING               =
                "Альпинизм",
            SKI_COMBINED                 =
                "Лыжное двоеборье",
            TOURISM_HOSPITALITY          =
                "Туризм и гостеприимство",
            WATER_TECHNICAL_SPORTS       =
                "Водно-технические виды спорта",
            MODEL_TECHNICAL_SPORTS       =
                "Модельно-технические виды спорта",
            ALPINE_SKIING                =
                "Горнолыжный спорт",
            BASEBALL                     =
                "Бейсбол",
            WUSHU                        =
                "Ушу",
            CHESS                        =
                "Шахматы",
            THAI_BOXING                  =
                "Таиландский бокс",
            TOURISM_PROMOTION            =
                "Технологии формирования и продвижения "            \
                "туристических услуг",
            TOURISM_IT                   =
                "Информационные технологии туристической "          \
                "индустрии",
            TOURISM_LOGISTICS            =
                "Логистика в туристической индустрии",
            TOURISM_SOCIAL               =
                "Технологии социокультурного сервиса "              \
                "туристов",
            TOURISM_TRANSPORT            =
                "Технологии транспортного сервиса туристов",
            TOURISM_FOOD                 =
                "Технологии сервиса питания туристов",
            TOURIST_ACCOMMODATION        =
                "Технологии сервиса размещения туристов",
            TOURISM_EXCURSION            =
                "Технологии экскурсионно-сопроводительного "        \
                "сервиса туристов",
            TOURISM_HEALTH               =
                "Технологии сервиса оздоровления и лечения "        \
                "туристов",
            BULLET_SHOOTING              =
                "Стрельба пулевая",
            FIELD_HOCKEY                 =
                "Хоккей на траве",
            FIGURE_SKATING               =
                "Фигурное катание на коньках",
            ROWING_AND_CANOEING          =
                "Гребля на байдарках и каноэ",
            ACADEMIC_ROWING              =
                "Гребля академическая",
            HAND_TO_HAND_COMBAT_MS       =
                "Рукопашный бой (смешанные единоборства)",
            BILLIARDS_RPC                =
                "Бильярд",
            WITHOUT_SPECIALIZATION       =
                "Без специализации",
            MEDICAL                      =
                "Физическая культура(лечебная)",
            MODERN_PENTATHLON            =
                "Современное пятиборье",
            SCIENCE_HEALTH               =
                "теория и методика физического воспитания, "        \
                "спортивной тренировки, оздоровительной",
            PHYSIOLOGY                   =
                "физиология",
            SCIENCE_THEORY               =
                "теория и методика физического воспитания, "        \
                "спортивной тренировки, оздоровительной",
            RECEARCH_SPORT               =
                "теория и методика физического воспитания, "        \
                "спортивной тренировки, оздоровительной",
            INNOVATIVE_TOURISM           =
                "инновационный менеджмент в сфере туризма",
            INNOVATIVE_HOSPITALITY       =
                "инновационный менеджмент в сфере гостеприимства",
            INNOVATIVE_TECHNOLOGIES      =
                "инновационные технологии в сфере туризма "         \
                "и гостеприимства",
            INNOVATIVE_MANAGEMENT        =
                "управление инновационными проектами в "            \
                "туристской индустрии",
            BILLIARDS_SMA                =
                "Бильярд",
            HAND_TO_HAND_COMBAT_SMA      =
                "Рукопашный бой (смешанные единоборства)",
            BADMINTON                    =
                "Бадминтон",
            TABLE_TENNIS_DEANERY         =
                "Настольный теннис",
            PHYSICAL_CULTURE_SPORT       =
                "Физическая культура и спорт",
            TOURISM_HOSPITALITY_MASTER   =
                "Туризм и гостеприимство",
            SPORT_CLIMBING               =
                "Скалолазание спортивное",
            MASTER_ANTHROPOLOGY          =
                "антропология",
            MASTER_MANAGEMENT            =
                "Менеджмент",
            MASTER_PHYSICAL_CULTURE      =
                "Физическая культура и спорт";

        namespace DATIVE_CASE
        {
            const AnsiString
                GYMNASTICS                   =
                    "гимнастике",
                MANAGEMENT_SPORTS_TOURISM    =
                    "менеджменту спорта и туризма",
                PHYSICAL_REHABILITATION      =
                    "физическая реабилитации",
                THERAPEUTIC                  =
                    "лечебной физическая культура",
                ORGANIZATION_SPORTS_TOURISM  =
                    "организации физкультурно-оздоровительной "         \
                    "работы и туризма",
                PRESCHOOL_PHYSICAL_EDUCATION =
                    "дошкольному физическому воспитанию",
                DANCE_SPORT                  =
                    "танцевальному спорту",
                AEROBICS                     =
                    "аэробике",
                ROWING_OTHER                 =
                    "гребному спорту",
                SWIMMING                     =
                    "плаванию",
                SAILING                      =
                    "парусному спорту",
                ATHLETICS                    =
                    "легкой атлетике",
                CROSS_COUNTRY_SKIING         =
                    "лыжным гонкам",
                BULLET_SHOOTING_DEANERY      =
                    "пулевой стрельбе",
                HAND_TO_HAND_COMBAT          =
                    "рукопашному бою",
                TAEKWONDO                    =
                    "таэквондо",
                KARATE                       =
                    "каратэ",
                SKIING                       =
                    "лыжному спорту",
                AUTOMOTIVE_SPORT             =
                    "автомобильному спорту",
                BASKETBALL                   =
                    "баскетболу",
                BOXING                       =
                    "боксу",
                GRECO_FREESTYLE_WRESTLING    =
                    "греко-римской и вольной борьбе",
                CYCLING                      =
                    "велосипедному спорту",
                VOLLEYBALL                   =
                    "волейболу",
                HANDBALL                     =
                    "гандболу",
                EQUESTRIAN                   =
                    "конному спорту",
                SPEED_SKATING                =
                    "конькобежному спорту",
                TENNIS                       =
                    "теннису",
                WEIGHTLIFTING                =
                    "тяжелой атлетике",
                FENCING                      =
                    "фехтованию",
                FIGURE_SKATING_OLD           =
                    "фигурному катанию",
                FOOTBALL                     =
                    "футболу",
                HOCKEY                       =
                    "хоккею",
                SAMBO_JUDO                   =
                    "самбо-дзюдо",
                WRESTLING                    =
                    "спортивной борьбе",
                FOOTBALL_HOCKEY              =
                    "футболу и хоккею",
                BIATHLON                     =
                    "биатлону",
                HEALTH_IMPROVING             =
                    "оздоровительной физической культуре",
                ADAPTIVE                     =
                    "адаптивной физической культуре",
                FREESTYLE_WRESTLING          =
                    "вольной борьбе",
                GRECO_ROMAN_WRESTLING        =
                    "греко-римской борьбе",
                SAMBO                        =
                    "самбо",
                JUDO                         =
                    "дзюдо",
                TABLE_TENNIS_ABITURIENT      =
                    "теннису настольному",
                ERGOTHERAPY                  =
                    "эрготерапии",
                MANAGEMENT_SPORTS            =
                    "менеджменту в спорте",
                SPORTS_DIRECTING_DEANERY     =
                    "спортивной режиссуре",
                SPORTS_RECREATIONAL_TOURISM  =
                    "спортивному и рекреационному туризму",
                MANAGEMENT_TOURISM           =
                    "менеджменту в туризме",
                SPORTS_PSYCHOLOGY            =
                    "спортивной психологии",
                BILLIARD_SPORTS              =
                    "бильярдному спорту",
                ACROBATICS                   =
                    "акробатике",
                ORIENTEERING                 =
                    "спортивному ориентированию",
                SPORTS_DIRECTING             =
                    "спортивной режиссуре",
                PRESCHOOLERS                 =
                    "физической культуре дошкольников",
                MOUNTAINEERING               =
                    "альпинизму",
                SKI_COMBINED                 =
                    "лыжному двоеборью",
                TOURISM_HOSPITALITY          =
                    "туризму и гостеприимству",
                WATER_TECHNICAL_SPORTS       =
                    "водно-техническим видам спорта",
                MODEL_TECHNICAL_SPORTS       =
                    "модельно-техническим видам спорта",
                ALPINE_SKIING                =
                    "горнолыжному спорту",
                BASEBALL                     =
                    "бейсболу",
                WUSHU                        =
                    "ушу",
                CHESS                        =
                    "шахматам",
                THAI_BOXING                  =
                    "таиландскому боксу",
                TOURISM_PROMOTION            =
                    "технологиям формирования и продвижения "            \
                    "туристических услуг",
                TOURISM_IT                   =
                    "информационным технологиям туристической "          \
                    "индустрии",
                TOURISM_LOGISTICS            =
                    "логистике в туристической индустрии",
                TOURISM_SOCIAL               =
                    "технологиям социокультурного сервиса "              \
                    "туристов",
                TOURISM_TRANSPORT            =
                    "технологиям транспортного сервиса туристов",
                TOURISM_FOOD                 =
                    "технологиям сервиса питания туристов",
                TOURIST_ACCOMMODATION        =
                    "технологиям сервиса размещения туристов",
                TOURISM_EXCURSION            =
                    "технологиям экскурсионно-сопроводительного "        \
                    "сервиса туристов",
                TOURISM_HEALTH               =
                    "технологиям сервиса оздоровления и лечения "        \
                    "туристов",
                BULLET_SHOOTING              =
                    "стрельбе пулевой",
                FIELD_HOCKEY                 =
                    "хоккею на траве",
                FIGURE_SKATING               =
                    "фигурному катанию на коньках",
                ROWING_AND_CANOEING          =
                    "гребле на байдарках и каноэ",
                ACADEMIC_ROWING              =
                    "гребле академической",
                HAND_TO_HAND_COMBAT_MS       =
                    "рукопашному бою (смешанные единоборства)",
                BILLIARDS_RPC                =
                    "бильярду",
                WITHOUT_SPECIALIZATION       =
                    "без специализации",
                MEDICAL                      =
                    "физической культуре (лечебной)",
                MODERN_PENTATHLON            =
                    "современному пятиборью",
                SCIENCE_HEALTH               =
                    "теории и методике физического воспитания, "        \
                    "спортивной тренировки, оздоровительной",
                PHYSIOLOGY                   =
                    "физиологии",
                SCIENCE_THEORY               =
                    "теории и методике физического воспитания, "        \
                    "спортивной тренировки, оздоровительной",
                RECEARCH_SPORT               =
                    "теории и методике физического воспитания, "        \
                    "спортивной тренировки, оздоровительной",
                INNOVATIVE_TOURISM           =
                    "инновационному менеджменту в сфере туризма",
                INNOVATIVE_HOSPITALITY       =
                    "инновационному менеджменту в сфере гостеприимства",
                INNOVATIVE_TECHNOLOGIES      =
                    "инновационным технологиям в сфере туризма "         \
                    "и гостеприимства",
                INNOVATIVE_MANAGEMENT        =
                    "управлению инновационными проектами в "            \
                    "туристской индустрии",
                BILLIARDS_SMA                =
                    "бильярду",
                HAND_TO_HAND_COMBAT_SMA      =
                    "рукопашному бою (смешанные единоборства)",
                BADMINTON                    =
                    "бадминтону",
                TABLE_TENNIS_DEANERY         =
                    "настольному теннису",
                PHYSICAL_CULTURE_SPORT       =
                    "физической культуре и спорту",
                TOURISM_HOSPITALITY_MASTER   =
                    "туризму и гостеприимству",
                SPORT_CLIMBING               =
                    "спортивному скалолазанию",
                MASTER_ANTHROPOLOGY          =
                    "антропологии",
                MASTER_MANAGEMENT            =
                    "менеджменту",
                MASTER_PHYSICAL_CULTURE      =
                    "физической культуре и спорту";
        }
    }

    namespace PathTo
    {
        const AnsiString
            OUTPUT_DOCUMENTS       = "D:\\Документы приемной комиссии",
            OUTPUT_DOCUMENTS_SLASH = "D:\\Документы приемной комиссии\\";
    }
    namespace Payment
    {
        const AnsiString
            BUDGET = "бюджет",
            BUYERS = "платное";
    }
    namespace SportsRanks
    {
        const AnsiString
            INTERNATIONAL_MASTER_OF_SPORTS =                                        // (IMS)
                "Мастер спорта международного класса (МСМК)",
            HONORED_MASTER_OF_SPORTS       = "Заслуженный мастер спорта (ЗМС)",     // (HMS)
            MASTER_OF_SPORT                = "Мастер спорта (МС)",                  // (MS)
            CANDIDATE_IN_MASTERS_OF_SPORT  = "Кандидат в мастера спорта (КМС)",     // (CMS)
            FIRST_SPORT_CATEGORY           = "I спортивный разряд (I разряд)",      // (FSC)
            SECOND_SPORT_CATEGORY          = "II спортивный разряд (II разряд)",    // (SSC)
            THIRD_SPORT_CATEGORY           = "III спортивный разряд (III разряд)",  // (TSC)
            FIRST_YOUTH_CATEGORY           = "I юношеский разряд (I юношеский)",    // (FYC)
            SECOND_YOUTH_CATEGORY          = "II юношеский разряд (II юношеский)",  // (SYC)
            FIRST_APPRENTICESHIP_DEGREE    = "1-я ученическая степень (1 кю)",      // (FAD)
            SECOND_APPRENTICESHIP_DEGREE   = "2-я ученическая степень (2 кю)",      // (SAD)
            THIRD_APPRENTICESHIP_DEGREE    = "3-я ученическая степень (3 кю)",      // (TAD)
            WITHOUT                        = "нет";                                 // (NO)

        namespace ABBR
        {
            const AnsiString
                INTERNATIONAL_MASTER_OF_SPORTS = "МСМК",
                HONORED_MASTER_OF_SPORTS       = "ЗМС",
                MASTER_OF_SPORT                = "МС",
                CANDIDATE_IN_MASTERS_OF_SPORT  = "КМС",
                FIRST_SPORT_CATEGORY           = "I разряд",
                SECOND_SPORT_CATEGORY          = "II разряд",
                THIRD_SPORT_CATEGORY           = "III разряд",
                FIRST_YOUTH_CATEGORY           = "I юношеский",
                SECOND_YOUTH_CATEGORY          = "II юношеский",
                FIRST_APPRENTICESHIP_DEGREE    = "1 кю",
                SECOND_APPRENTICESHIP_DEGREE   = "2 кю",
                THIRD_APPRENTICESHIP_DEGREE    = "3 кю",
                WITHOUT                        = "нет";
        }
    }
    namespace StudyPeriod
    {
        namespace HIGH
        {
            const AnsiString
                NAME           = "Высшее образование",
                FULL           = "Полный срок",                                     // t_abitur_queue.term_edu = 0
                FIRST_COURSE   = "Высшее образование (1 курс)",                     // t_abitur_queue.term_edu = 3
                SECOND_COURSE  = "Высшее образование (2 курс)",                     // t_abitur_queue.term_edu = 4
                THIRD_COURSE   = "Высшее образование (3 курс)";                     // t_abitur_queue.term_edu = 5
        }
        namespace SHORT
        {
            const AnsiString
                NAME          = "Cокращённый срок",
                SECOND_COURSE = "Cокращённый срок (2 курс)",                        // t_abitur_queue.term_edu = 1
                THIRD_COURSE  = "Cокращённый срок (3 курс)";                        // t_abitur_queue.term_edu = 2
        }
    }
#endif // ! STATE_FROM_WORK_PC


#endif // PROPERTIES_HPP
