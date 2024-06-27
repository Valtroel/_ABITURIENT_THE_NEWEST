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
        GENERAL                = "�����",
        OUT_OF_COMPETITION     = "��� ��������",
        WITHOUT_ENTRANCE_EXAMS = "��� ������������� ���������",
        TARGETED_TRAINING      = "�������";
}
namespace Document
{
    namespace STATISTIC
    {
        namespace FILE
        {
            const AnsiString
                SCORES = "���������� - �����.xls";
        }
        namespace NAME
        {
            const AnsiString
                SCORES = "���������� �� ������";
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
            "\\����������\\",
        #else
        OUTPUT_DOCUMENTS =
            "D:\\Priem"                 +
                Admissions::TIME::YEAR  +
            "\\����������\\",
        #endif
        TEMPLATES        =
                GetCurrentDir ()        +
            "\\1\\";
}
namespace Payment
{
    const AnsiString
        BUDGET = "������",
        BUYERS = "�������";
}
namespace Faculty
{
    namespace SHORT
    {
        const AnsiString
            SMA  = "����",                                                      // 1, -> Sports and Marital Arts (����)
            MS   = "���",                                                       // 2, -> Mass Sports (���)
            RPC  = "���",                                                       // 3, -> Recreational Physical Culture (�����)
            MSTH = "�����",                                                     // 4, -> Management of Sports, Tourism and Hospitality (����)
            MD   = "�����������",                                               // 5, -> Master's Degree (�����������)
            PGS  = "�����������",                                               // 6, -> PostGraduate Studies (�����������)
            DOC  = "������������";                                              // 7  -> DOCtorate (������������)
    }
    namespace NAME
    {
        const AnsiString
            SMA  =                                                              // 1, -> Sports and Marital Arts (����)
                "���������-�������������� ��������� "   \
                "���������� ��� � �����������",
            MS   =                                                              // 2, -> Mass Sports (���)
                "���������-�������������� ��������� "   \
                "�������� ����� ������",
            RPC  =                                                              // 3, -> Recreational Physical Culture (�����)
                "��������� ��������������� "            \
                "���������� ��������",
            MSTH =                                                              // 4, -> Management of Sports, Tourism and Hospitality (����)
                "��������� ����������� ������, "        \
                "������� � ��������������",
            MD   =                                                              // 5, -> Master's Degree (�����������)
                "�����������",
            PGS  =                                                              // 6, -> PostGraduate Studies (�����������)
                "�����������",
            DOC  =                                                              // 7  -> DOCtorate (������������)
                "������������";
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
                        "��������������� � ���������� ���������� "          \
                        "��������",                                             // (�� ������������)
                    COACHING          =
                        "���������-�������������� ������������",                // (�� ������������)
                    MANAGEMENT        =
                        "���������-���������� ������������",                    // (�� ������������)
                    PHYSICAL_CULTURE  =
                        "���������� ��������",                                  // (�� ������������)
                    REHABILITATION    =
                        "���������� ������������ � �����������",                // (�� ������������)
                    TOURISM           =
                        "������ � ��������������";
            }
            namespace MASTER_DEGREE
            {
                namespace SCIENCE
                {
                    const AnsiString
                        THEORY           =
                            "������ � �������� ����������� ����������, "    \
                            "���������� ����������, ���������������",
                        PHYSIOLOGY       =
                            "����������";
                }
                namespace INNOVATION
                {
                    const AnsiString
                        TOURISM        =
                            "������������� ���������� � ����� �������",
                        HOSPITALITY    =
                            "������������� ���������� � ����� "             \
                            "��������������",
                        TECHNOLOGIES   =
                            "������������� ���������� � ����� ������� "     \
                            "� ��������������",
                        MANAGEMENT     =
                            "���������� �������������� ��������� � "        \
                            "���������� ���������";
                }
                namespace RESEARCH
                {
                    const AnsiString
                        SPORT            =
                            "������ � �������� ����������� "                \
                            "����������, ���������� ����������, "           \
                            "��������������� � ���������� ��",
                        PHYSICAL_CULTURE =
                            "���������� �������� � �����",
                        TOURISM          =
                            "������ � ��������������",
                        MANAGEMENT       =
                            "����������";
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
                        COACHING       = "T��������� ������ �� ",               // + getKindOfSportNameDativeCase (nSpecializ)
                        PSYCHOLOGY     = "���������� ����������",               // (AsPostfix)
                        DIRECTING      = "����������� ���������",               // (AsPostfix)
                        MANAGEMENT     = "���������� � ������";                 // (AsPostfix)
                }
                namespace MANAGEMENT
                {
                    const AnsiString
                        RECREATIONAL   = "���������� � ������������� ������",   // (AsPostfix)
                        TUORISM_MNG    = "���������� � �������";                // (AsPostfix)
                }
                namespace PHYSICAL_CULTURE
                {
                    const AnsiString
                        MEDICAL        = "��������",                            // (AsPostfix)
                        PRESCHOOLERS   = "������������";                        // (AsPostfix)
                }
                namespace IMPROVING
                {
                    const AnsiString
                        HEALTH         = "���������������",                     // (AsPostfix)
                        ADAPTIVE       = "����������";                          // (AsPostfix)
                }
                namespace REHABILITATION
                {
                    const AnsiString
                        REHABILITATION = "���������� ������������",             // (AsPostfix)
                        ERGOTHERAPY    = "�����������";                         // (AsPostfix)
                }
                namespace TOURISM
                {
                    const AnsiString
                        HOSPITALITY    = "������ � ��������������",
                        PROMOTION      =
                            "���������� ������������ � ����������� "        \
                            "������������� �����",
                        IT             =
                            "�������������� ���������� ������������� "      \
                            "���������",
                        LOGISTICS      =
                            "��������� � ������������� ���������",
                        SOCIAL         =
                            "���������� ���������������� ������ ��������",
                        TRANSPORT      =
                            "���������� ������������� ������� ��������",
                        CATERING       =
                            "���������� ������� ������� ��������",
                        ACCOMMODATION  =
                            "���������� ������� ������������������ ",
                        SUPPORTING     =
                            "���������� ������������-����������������� "    \
                            "������� ��������",
                        TREATMENT      =
                            "���������� ������� ������������ � ������� "    \
                            "��������";
                }
            }
            namespace SERVICE
            {
                const AnsiString
                    RESTAURANTS    = "����������� ������������";
            }
            namespace MILITARY
            {
                const AnsiString
                    TRAINING       = "���������� ���������� ��������������";
            }
            namespace MASTER_DEGREE
            {
                namespace SCIENCE
                {
                    const AnsiString
                        THEORY           =
                            "������ � �������� ����������� ����������, "    \
                            "���������� ����������, ��������������� � "     \
                            "���������� ���������� ��������.",
                        PHYSIOLOGY       = "����������";
                }
                namespace INNOVATION
                {
                    const AnsiString
                        TOURISM          =
                            "������������� ���������� � ����� �������",
                        HOSPITALITY      =
                            "������������� ���������� � ����� "             \
                            "��������������",
                        TECHNOLOGIES     =
                            "������������� ���������� � ����� ������� � "   \
                            "��������������",
                        MANAGEMENT       =
                            "���������� �������������� ��������� � "        \
                            "���������� ���������";
                }
                namespace RESEARCH
                {
                    const AnsiString
                        SPORT            =
                            "������ � �������� ����������� ����������, "    \
                            "���������� ����������, ��������������� � "     \
                            "���������� ���������� ��������.",
                        PHYSICAL_CULTURE = "���������� �������� � �����",
                        MANAGEMENT       = "����������",
                        TOURISM          = "������ � ��������������";
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
                            "������ (�� ���� ������). "                     \
                            "������������� ���������� ��������",
                        PSYCHOLOGY     =
                            "��������. "                                    \
                            "������������� ���������� ��������",
                        DIRECTING      =
                            "��������-�������� ���������-�������� "         \
                            "�����������."                                  \
                            "������������� ���������� ��������",
                        MANAGEMENT     =
                            "�������� � ������. "                           \
                            "������������� ���������� ��������";
                }
                namespace MANAGEMENT
                {
                    const AnsiString
                        RECREATIONAL   =
                            "����������-�������� �� �������. "              \
                            "������������� ���������� ��������",
                        TUORISM_MNG    =
                            "�������� �� �������. "                         \
                            "������������� ���������� ��������";
                }
                namespace PHYSICAL_CULTURE
                {
                    const AnsiString
                        MEDICAL        =
                            "����������-�������� �� �������� ���������� "   \
                            "��������. ������������� ���������� ��������",
                        PRESCHOOLERS   =
                            "����������-�������� ����������� ���������� � " \
                            "���������� �����������. "                      \
                            "������������� ���������� ��������";
                }
                namespace IMPROVING
                {
                    const AnsiString
                        HEALTH         =
                            "����������-�������� �� ��������������� "       \
                            "���������� ��������. "                         \
                            "������������� ���������� ��������",
                        ADAPTIVE       =
                            "����������-�������� �� ���������� "            \
                            "���������� ��������. "                         \
                            "������������� ���������� ��������";
                }
                namespace REHABILITATION
                {
                    const AnsiString
                        REHABILITATION =
                            "����������-�������� �� ���������� "            \
                            "������������. "                                \
                            "������������� ���������� ��������",
                        ERGOTHERAPY    =
                            "����������-�������� �� �����������. "          \
                            "������������� ���������� ��������";
                }
                namespace TOURISM
                {
                    const AnsiString
                        HOSPITALITY    =
                            "���������� � ����� ������� � ��������������",
                        PROMOTION      =
                            "���������� � ����� ������� � ��������������",
                        IT             =
                            "���������� � ����� ������� � ��������������",
                        LOGISTICS      =
                            "���������� � ����� ������� � ��������������",
                        SOCIAL         =
                            "���������� � ����� ������� � ��������������",
                        TRANSPORT      =
                            "���������� � ����� ������� � ��������������",
                        CATERING       =
                            "���������� � ����� ������� � ��������������",
                        ACCOMMODATION  =
                            "���������� � ����� ������� � ��������������",
                        SUPPORTING     =
                            "���������� � ����� ������� � ��������������",
                        TREATMENT      =
                            "���������� � ����� ������� � ��������������";
                }
            }
            namespace SERVICE
            {
                const AnsiString
                    RESTAURANTS    = "��������. ��������";
            }
            namespace MILITARY
            {
                const AnsiString
                    TRAINING       =
                        "���������� �� ����������. "                        \
                        "����������-�������� �� ���������� "                \
                        "����������";
            }
            namespace MASTER_DEGREE
            {
                namespace SCIENCE
                {
                    const AnsiString
                        THEORY           = "�������",
                        PHYSIOLOGY       = "�������";
                }
                namespace INNOVATION
                {
                    const AnsiString
                        TOURISM          = "������� �������",
                        HOSPITALITY      = "������� ��������������",
                        TECHNOLOGIES     = "������� ���������",
                        MANAGEMENT       = "������� ����������";
                }
                namespace RESEARCH
                {
                    const AnsiString
                        SPORT            = "�������",
                        PHYSICAL_CULTURE = "�������",
                        TOURISM          = "�������",
                        MANAGEMENT       = "�������";
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
                        "���������� ������������",
                    TOURISM          =
                        "������ � ��������������",
                    PHYSICAL_CULTURE =
                        "���������� ��������",
                    REHABILITATION   =
                        "���������� ������������ � �����������",
                    MANAGEMENT       =
                        "����������� � ���������� ���������� "              \
                        "���������, ������� � ��������";

                namespace PROFILING
                {
                    namespace COACH
                    {
                        const AnsiString
                            DEFAULT        =
                                "(� ��������� ���� ������)";
                    }
                    namespace PHYSICAL
                    {
                        const AnsiString
                            #ifndef USE_SHORT_NCRB011_2022_PROFILING_NAME
                                IMPROVING      =
                                    "(��������������� ���������� ��������)",
                                HEALTH         =
                                    "(�������� ���������� ��������)",
                                PRESCHOOLERS   =
                                    "(���������� �������� ������������)",
                                ADAPTIVE       =
                                    "(���������� ���������� ��������)",
                            #else
                                IMPROVING      =
                                    "(���������������)",
                                HEALTH         =
                                    "(��������)",
                                PRESCHOOLERS   =
                                    "(������������)",
                                ADAPTIVE       =
                                    "(����������)",
                            #endif  // USE_SHORT_NCRB011_2022_PROFILING_NAME
                            DIRECTING      =
                                "(���������� ���������)",
                            PSYCHOLOGY     =
                                "(���������� ����������)",
                            RECREATIONAL   =
                                "(���������� � ������������� "              \
                                "������)";
                    }
                    namespace REHABILITATE
                    {
                        const AnsiString
                            REHABILITATION =
                                "(���������� ������������)",
                            ERGOTHERAPY    =
                                "(�����������)";
                    }
                    namespace MANAGE
                    {
                        const AnsiString
                            SPORT          =
                                "(���������� � ������)",
                            TOURISM        =
                                "(���������� � �������)";
                    }
                }
            }
            namespace MASTER_DEGREE
            {
                namespace SCIENCE
                {
                    const AnsiString
                        THEORY           =
                            "������ � �������� ����������� "                \
                            "����������, ���������� ����������, "           \
                            "���������������",
                        PHYSIOLOGY       =
                            "����������";
                }
                namespace INNOVATION
                {
                    const AnsiString
                        TOURISM          =
                            "������������� ���������� � "                   \
                            "����� �������",
                        HOSPITALITY      =
                            "������������� ���������� � "                   \
                            "����� ��������������",
                        TECHNOLOGIES       =
                            "������������� ���������� � "                   \
                            "����� ������� � ��������������",
                        MANAGEMENT       =
                            "���������� �������������� "                    \
                            "��������� � ���������� ���������";
                }
                namespace RESEARCH
                {
                    const AnsiString
                        SPORT            =
                            "T����� � �������� ����������� "                \
                            "����������, ���������� ����������, "           \
                            "��������������� � ���������� "                 \
                            "���������� ��������",
                        PHYSICAL_CULTURE =
                            "���������� �������� � �����",
                        TOURISM          =
                            "������ � ��������������",
                        MANAGEMENT       =
                            "����������";
                }
            }
        }
        namespace QUALIFICATION
        {
            namespace HIGH_SCHOOL
            {
                const AnsiString
                    COACHING         = "������. �������������",
                    TOURISM          = "����������",
                    PHYSICAL_CULTURE = "����������-��������. �������������",
                    REHABILITATION   = "����������-��������. �������������",
                    MANAGEMENT       = "��������. �������������";
            }
            namespace MASTER_DEGREE
            {
                namespace SCIENCE
                {
                    const AnsiString
                        THEORY           = "�������",
                        PHYSIOLOGY       = "�������";
                }
                namespace INNOVATION
                {
                    const AnsiString
                        TOURISM          = "������� �������",
                        HOSPITALITY      = "������� ��������������",
                        TECHNOLOGIES     = "������� ���������",
                        MANAGEMENT       = "������� ����������";
                }
                namespace RESEARCH
                {
                    const AnsiString
                        SPORT            = "�������",
                        PHYSICAL_CULTURE = "�������",
                        TOURISM          = "�������",
                        MANAGEMENT       = "�������";
                }
            }
        }
    }
}
namespace KindOfSport
{
    const AnsiString
        GYMNASTICS                   =
            "����������",
        MANAGEMENT_SPORTS_TOURISM    =
            "���������� ������ � �������",
        PHYSICAL_REHABILITATION      =
            "���������� ������������",
        THERAPEUTIC                  =
            "�������� ���������� ��������",
        ORGANIZATION_SPORTS_TOURISM  =
            "����������� ������������-��������������� "                     \
            "������ � �������",
        PRESCHOOL_PHYSICAL_EDUCATION =
            "���������� ���������� ����������",
        DANCE_SPORT                  =
            "������������ �����",
        AEROBICS                     =
            "��������",
        ROWING_OTHER                 =
            "������� �����",
        SWIMMING                     =
            "��������",
        SAILING                      =
            "�������� �����",
        ATHLETICS                    =
            "������ ��������",
        CROSS_COUNTRY_SKIING         =
            "������ �����",
        BULLET_SHOOTING_DEANERY      =
            "������� ��������",
        HAND_TO_HAND_COMBAT          =
            "���������� ���",
        TAEKWONDO                    =
            "���������",
        KARATE                       =
            "������",
        SKIING                       =
            "������ �����",
        AUTOMOTIVE_SPORT             =
            "������������� �����",
        BASKETBALL                   =
            "���������",
        BOXING                       =
            "����",
        GRECO_FREESTYLE_WRESTLING    =
            "�����-������� � ������� ������",
        CYCLING                      =
            "������������ �����",
        VOLLEYBALL                   =
            "��������",
        HANDBALL                     =
            "�������",
        EQUESTRIAN                   =
            "������ �����",
        SPEED_SKATING                =
            "������������ �����",
        TENNIS                       =
            "������",
        WEIGHTLIFTING                =
            "������� ��������",
        FENCING                      =
            "����������",
        FIGURE_SKATING               =
            "�������� �������",
        FOOTBALL                     =
            "������",
        HOCKEY                       =
            "������",
        WRESTLING                    =
            "���������� ������",
        BIATHLON                     =
            "�������",
        HEALTH_IMPROVING             =
            "��������������� ���������� ��������",
        ADAPTIVE                     =
            "���������� ���������� ��������",
        FREESTYLE_WRESTLING          =
            "������� ������",
        GRECO_ROMAN_WRESTLING        =
            "�����-������� ������",
        SAMBO                        =
            "�����",
        JUDO                         =
            "�����",
        TABLE_TENNIS                 =
            "������ ����������",
        ERGOTHERAPY                  =
            "�����������",
        MANAGEMENT_SPORTS            =
            "���������� � ������",
        SPORTS_RECREATIONAL_TOURISM  =
            "���������� � ������������� ������",
        MANAGEMENT_TOURISM           =
            "���������� � �������",
        SPORTS_PSYCHOLOGY            =
            "���������� ����������",
        BILLIARD_SPORTS              =
            "���������� �����",
        ACROBATICS                   =
            "����������",
        ORIENTEERING                 =
            "���������� ��������������",
        SPORTS_DIRECTING             =
            "���������� ���������",
        PRESCHOOLERS                 =
            "���������� �������� ������������",
        MOUNTAINEERING               =
            "���������",
        SKI_COMBINED                 =
            "������ ���������",
        TOURISM_HOSPITALITY          =
            "������ � ��������������",
        WATER_TECHNICAL_SPORTS       =
            "�����-����������� ���� ������",
        MODEL_TECHNICAL_SPORTS       =
            "��������-����������� ���� ������",
        ALPINE_SKIING                =
            "����������� �����",
        BASEBALL                     =
            "�������",
        WUSHU                        =
            "���",
        CHESS                        =
            "�������",
        THAI_BOXING                  =
            "����������� ����",
        TOURISM_PROMOTION            =
            "���������� ������������ � ����������� "                        \
            "������������� �����",
        TOURISM_IT                   =
            "�������������� ���������� ������������� "                      \
            "���������",
        TOURISM_LOGISTICS            =
            "��������� � ������������� ���������",
        TOURISM_SOCIAL               =
            "���������� ���������������� ������� "                          \
            "��������",
        TOURISM_TRANSPORT            =
            "���������� ������������� ������� ��������",
        TOURISM_FOOD                 =
            "���������� ������� ������� ��������",
        TOURIST_ACCOMMODATION        =
            "���������� ������� ���������� ��������",
        TOURISM_EXCURSION            =
            "���������� ������������-����������������� "                    \
            "������� ��������",
        TOURISM_HEALTH               =
            "���������� ������� ������������ � ������� "                    \
            "��������",
        BULLET_SHOOTING              =
            "�������� �������",
        FIELD_HOCKEY                 =
            "������ �� �����",
        FIGURE_SKATING_SKATES        =
            "�������� ������� �� �������",
        ROWING_AND_CANOEING          =
            "������ �� ��������� � �����",
        ACADEMIC_ROWING              =
            "������ �������������",
        HAND_TO_HAND_MARTIAL_ARTS    =
            "���������� ��� (��������� ������������)",
        BILLIARDS                    =
            "�������",
        WITHOUT_SPECIALIZATION       =
            "��� �������������",
        MODERN_PENTATHLON            =
            "����������� ���������",
        SCIENCE_HEALTH               =
            "������ � �������� ����������� ����������, "                    \
            "���������� ����������, ���������������",
        PHYSIOLOGY                   =
            "����������",
        SCIENCE_THEORY               =
            "������ � �������� ����������� ����������, "                    \
            "���������� ����������, ���������������",
        RECEARCH_SPORT               =
            "������ � �������� ����������� ����������, "                    \
            "���������� ����������, ���������������",
        INNOVATIVE_TOURISM           =
            "������������� ���������� � ����� �������",
        INNOVATIVE_HOSPITALITY       =
            "������������� ���������� � ����� ��������������",
        INNOVATIVE_TECHNOLOGIES      =
            "������������� ���������� � ����� ������� "                     \
            "� ��������������",
        INNOVATIVE_MANAGEMENT        =
            "���������� �������������� ��������� � "                        \
            "���������� ���������",
        BADMINTON                    =
            "���������",
        PHYSICAL_CULTURE_SPORT       =
            "���������� �������� � �����",
        TOURISM_HOSPITALITY_MASTER   =
            "������ � ��������������",
        SPORT_CLIMBING               =
            "������������ ����������",
        MASTER_ANTHROPOLOGY          =
            "������������",
        MASTER_MANAGEMENT            =
            "����������";

    namespace DATIVE_CASE
    {
        const AnsiString
            GYMNASTICS                   =
                "����������",
            MANAGEMENT_SPORTS_TOURISM    =
                "����������� ������ � �������",
            PHYSICAL_REHABILITATION      =
                "����������� ������������",
            THERAPEUTIC                  =
                "�������� ���������� ��������",
            ORGANIZATION_SPORTS_TOURISM  =
                "����������� ������������-��������������� "                 \
                "������ � �������",
            PRESCHOOL_PHYSICAL_EDUCATION =
                "����������� ����������� ����������",
            DANCE_SPORT                  =
                "������������� ������",
            AEROBICS                     =
                "��������",
            ROWING_OTHER                 =
                "�������� ������",
            SWIMMING                     =
                "��������",
            SAILING                      =
                "��������� ������",
            ATHLETICS                    =
                "������ ��������",
            CROSS_COUNTRY_SKIING         =
                "������ ������",
            BULLET_SHOOTING_DEANERY      =
                "������� ��������",
            HAND_TO_HAND_COMBAT          =
                "����������� ���",
            TAEKWONDO                    =
                "���������",
            KARATE                       =
                "������",
            SKIING                       =
                "������� ������",
            AUTOMOTIVE_SPORT             =
                "�������������� ������",
            BASKETBALL                   =
                "����������",
            BOXING                       =
                "�����",
            GRECO_FREESTYLE_WRESTLING    =
                "�����-������� � ������� ������",
            CYCLING                      =
                "������������� ������",
            VOLLEYBALL                   =
                "���������",
            HANDBALL                     =
                "��������",
            EQUESTRIAN                   =
                "������� ������",
            SPEED_SKATING                =
                "������������� ������",
            TENNIS                       =
                "�������",
            WEIGHTLIFTING                =
                "������� ��������",
            FENCING                      =
                "����������",
            FIGURE_SKATING               =
                "��������� �������",
            FOOTBALL                     =
                "�������",
            HOCKEY                       =
                "������",
            WRESTLING                    =
                "���������� ������",
            BIATHLON                     =
                "��������",
            HEALTH_IMPROVING             =
                "��������������� ���������� ��������",
            ADAPTIVE                     =
                "���������� ���������� ��������",
            FREESTYLE_WRESTLING          =
                "������� ������",
            GRECO_ROMAN_WRESTLING        =
                "�����-������� ������",
            SAMBO                        =
                "�����",
            JUDO                         =
                "�����",
            TABLE_TENNIS                 =
                "������� �����������",
            ERGOTHERAPY                  =
                "�����������",
            MANAGEMENT_SPORTS            =
                "����������� � ������",
            SPORTS_RECREATIONAL_TOURISM  =
                "����������� � �������������� �������",
            MANAGEMENT_TOURISM           =
                "����������� � �������",
            SPORTS_PSYCHOLOGY            =
                "���������� ����������",
            BILLIARD_SPORTS              =
                "����������� ������",
            ACROBATICS                   =
                "����������",
            ORIENTEERING                 =
                "����������� ��������������",
            SPORTS_DIRECTING             =
                "���������� ���������",
            PRESCHOOLERS                 =
                "���������� �������� ������������",
            MOUNTAINEERING               =
                "����������",
            SKI_COMBINED                 =
                "������� ���������",
            TOURISM_HOSPITALITY          =
                "������� � ��������������",
            WATER_TECHNICAL_SPORTS       =
                "�����-����������� ����� ������",
            MODEL_TECHNICAL_SPORTS       =
                "��������-����������� ����� ������",
            ALPINE_SKIING                =
                "������������ ������",
            BASEBALL                     =
                "��������",
            WUSHU                        =
                "���",
            CHESS                        =
                "��������",
            THAI_BOXING                  =
                "������������ �����",
            TOURISM_PROMOTION            =
                "����������� ������������ � ����������� "                   \
                "������������� �����",
            TOURISM_IT                   =
                "�������������� ����������� ������������� "                 \
                "���������",
            TOURISM_LOGISTICS            =
                "��������� � ������������� ���������",
            TOURISM_SOCIAL               =
                "����������� ���������������� ������� "                     \
                "��������",
            TOURISM_TRANSPORT            =
                "����������� ������������� ������� ��������",
            TOURISM_FOOD                 =
                "����������� ������� ������� ��������",
            TOURIST_ACCOMMODATION        =
                "����������� ������� ���������� ��������",
            TOURISM_EXCURSION            =
                "����������� ������������-����������������� "               \
                "������� ��������",
            TOURISM_HEALTH               =
                "����������� ������� ������������ � ������� "               \
                "��������",
            BULLET_SHOOTING              =
                "�������� �������",
            FIELD_HOCKEY                 =
                "������ �� �����",
            FIGURE_SKATING_SKATES        =
                "��������� ������� �� �������",
            ROWING_AND_CANOEING          =
                "������ �� ��������� � �����",
            ACADEMIC_ROWING              =
                "������ �������������",
            HAND_TO_HAND_MARTIAL_ARTS    =
                "����������� ��� (��������� �������������)",
            BILLIARDS                    =
                "��������",
            WITHOUT_SPECIALIZATION       =
                "��� �������������",
            MODERN_PENTATHLON            =
                "������������ ���������",
            SCIENCE_HEALTH               =
                "������ � �������� ����������� ����������, "                \
                "���������� ����������, ���������������",
            PHYSIOLOGY                   =
                "����������",
            SCIENCE_THEORY               =
                "������ � �������� ����������� ����������, "                \
                "���������� ����������, ���������������",
            RECEARCH_SPORT               =
                "������ � �������� ����������� ����������, "                \
                "���������� ����������, ���������������",
            INNOVATIVE_TOURISM           =
                "�������������� ����������� � ����� �������",
            INNOVATIVE_HOSPITALITY       =
                "�������������� ����������� � ����� ��������������",
            INNOVATIVE_TECHNOLOGIES      =
                "������������� ����������� � ����� ������� "                \
                "� ��������������",
            INNOVATIVE_MANAGEMENT        =
                "���������� �������������� ��������� � "                    \
                "���������� ���������",
            BADMINTON                    =
                "����������",
            PHYSICAL_CULTURE_SPORT       =
                "���������� �������� � ������",
            TOURISM_HOSPITALITY_MASTER   =
                "������� � ��������������",
            SPORT_CLIMBING               =
                "����������� ������������",
            MASTER_ANTHROPOLOGY          =
                "������������",
            MASTER_MANAGEMENT            =
                "�����������";
    }
}

#endif // PROPERTIES_HPP