#pragma once
#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

namespace DEFAULT
{
    const AnsiString
        COLUMN_START_SCORES = "";
}
namespace Admissions
{
    namespace TIME
    {
        const AnsiString
            YEAR =(Now ()).FormatString ("yyyy");
    }
}
namespace ContestType
{
    const AnsiString
        GENERAL                = "общий",
        OUT_OF_COMPETITION     = "вне конкурса",
        WITHOUT_ENTRANCE_EXAMS = "без вступительных испытаний",
        TARGETED_TRAINING      = "целевой";
}
namespace Document
{
    namespace STATISTIC
    {
        namespace FILE
        {
            const AnsiString
                SCORES = "СТАТИСТИКА - Баллы.xls";
        }
        namespace NAME
        {
            const AnsiString
                SCORES = "СТАТИСТИКА по баллам";
        }
    }
}
namespace PathTo
{
    const AnsiString
        #ifdef DEBUG
        OUTPUT_DOCUMENTS =
            "D:\\Priem"                 +
                Admissions::TIME::YEAR  +
            "\\Статистика\\",
        #else
        OUTPUT_DOCUMENTS =
            "D:\\Priem"                 +
                Admissions::TIME::YEAR  +
            "\\Статистика\\",
        #endif
        TEMPLATES        =
                GetCurrentDir ()        +
            "\\1\\";
}
namespace Payment
{
    const AnsiString
        BUDGET = "бюджет",
        BUYERS = "платное";
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

#endif // PROPERTIES_HPP