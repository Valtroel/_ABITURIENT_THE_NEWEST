#pragma once
#ifndef ENUMS_HPP
#define ENUMS_HPP

enum Default
{
    EMPTY                                       = 0,
    START                                       = 0,
    DISABLE                                     = 0,
    STEP                                        = 1,
    ENABLE                                      = 1,
    LOOPS_MAX_ITERATIONS                        = 2,
    SHIFT_FOR_SPREAD_SHORT_SMA_SM               = 2,
    SHIFT_FOR_SPREAD_FULL                       = 4,
    SHIFT_FOR_SPREAD_SHORT_OTHER                = 4,
    SECTIONS_ARRAY_LENGTH                       = 5,
    KINDS_OF_SPORT_LENGTH                       = 57,
    ACCUM_ARRAY_LENGTH                          = 75,
    MAX_NUMBER_OF_ITEMS                         = 83
};
enum ArrayIndexFor
{
    KIND_OF_SPORT_NAMES                         = 0,
    AMOUNT_BY_PLAN                              = 1,
    AMOUNT_TARGETED_TRAINING_BY_PLAN            = 2,
    ROW_NUMBER_FOR_CALC                         = 3,
    AMOUNT_TARGETED_TRAINING                    = 4,
    AMOUNT_WITHOUT_EXAMS                        = 5,
    AMOUNT_OUT_OF_COMPETITION                   = 6,
    AMOUNT_GENERAL_CONTEST                      = 7,
    SCORES_400                                  = 8,
    SCORES_LESS_31                              = 83
};
enum ColumnFor
{
    NAMES                                       = 1,
    TOTAL_BY_PLAN                               = 2,
    TOTAL_TARGETED_TRAINING_BY_PLAN             = 3,
    TOTAL_APPLICANTS                            = 4,
    TOTAL_TARGETED_TRAINING                     = 5,
    TOTAL_WITHOUT_EXAMS                         = 6,
    TOTAL_OUT_OF_COMPETITION                    = 7,
    TOTAL_GENERAL_CONTEST                       = 8,
    START_SCORES                                = 9,
    CURRENT_DATE                                = 25,
    CURRENT_HOURS                               = 33,
    OUTER_BORDER                                = 84
};
enum TypeLineCode
{
    REGULAR_LINE                                = 1,
    SMALL_DOTTED_LINE                           = 2,
    LARGE_DOTTED_LINE                           = 3,
    ONE_LONG_ONE_SHORT                          = 4,
    ONE_LONG_TWO_SHORT                          = 5,
    DOUBLE_LINE                                 = 9
};
enum LineThicknessCode
{
    THIN                                        = 1,
    MEDIUM                                      = 2,
    WIDE                                        = 3,
    EXTRA_WIDE                                  = 4
};
enum RowFor
{
    DATE_AND_HOURS                              = 5,
    FACULTY_NAME                                = 14,
    START_DATA                                  = 15
};
enum ScoresRange
{
    _396_400                                    = 9,
    _391_395                                    = 10,
    _386_390                                    = 11,
    _381_385                                    = 12,
    _376_380                                    = 13,
    _371_375                                    = 14,
    _366_370                                    = 15,
    _361_365                                    = 16,
    _356_360                                    = 17,
    _351_355                                    = 18,
    _346_350                                    = 19,
    _341_345                                    = 20,
    _336_340                                    = 21,
    _331_335                                    = 22,
    _326_330                                    = 23,
    _321_325                                    = 24,
    _316_320                                    = 25,
    _311_315                                    = 26,
    _306_310                                    = 27,
    _301_305                                    = 28,
    _296_300                                    = 29,
    _291_295                                    = 30,
    _286_290                                    = 31,
    _281_285                                    = 32,
    _276_280                                    = 33,
    _271_275                                    = 34,
    _266_270                                    = 35,
    _261_265                                    = 36,
    _256_260                                    = 37,
    _251_255                                    = 38,
    _246_250                                    = 39,
    _241_245                                    = 40,
    _236_240                                    = 41,
    _231_235                                    = 42,
    _226_230                                    = 43,
    _221_225                                    = 44,
    _216_220                                    = 45,
    _211_215                                    = 46,
    _206_210                                    = 47,
    _201_205                                    = 48,
    _196_200                                    = 49,
    _191_195                                    = 50,
    _186_190                                    = 51,
    _181_185                                    = 52,
    _176_180                                    = 53,
    _171_175                                    = 54,
    _166_170                                    = 55,
    _161_165                                    = 56,
    _156_160                                    = 57,
    _151_155                                    = 58,
    _146_150                                    = 59,
    _141_145                                    = 60,
    _136_140                                    = 61,
    _131_135                                    = 62,
    _126_130                                    = 63,
    _121_125                                    = 64,
    _116_120                                    = 65,
    _111_115                                    = 66,
    _106_110                                    = 67,
    _101_105                                    = 68,
    _96_100                                     = 69,
    _91_95                                      = 70,
    _86_90                                      = 71,
    _81_85                                      = 72,
    _76_80                                      = 73,
    _71_75                                      = 74,
    _66_70                                      = 75,
    _61_65                                      = 76,
    _56_60                                      = 77,
    _51_55                                      = 78,
    _46_50                                      = 79,
    _41_45                                      = 80,
    _36_40                                      = 81,
    _31_35                                      = 82,
    _LESS_31                                    = 83
};
enum ContestTypeCode
{
    GENERAL                                     = 0,
    WITHOUT_ENTRANCE_EXAMS                      = 1,
    OUT_OF_COMPETITION                          = 2,
    TARGETED_TRAINING                           = 3
};
enum KindOfSportCode
{
    GYMNASTICS                                  = 1,                            // 1,   -> "Гимнастика",
    MANAGEMENT_SPORTS_TOURISM                   = 2,                            // 2,   -> "Менеджмент спорта и туризма",
    PHYSICAL_REHABILITATION                     = 3,                            // 3,   -> "Физическая реабилитация",
    THERAPEUTIC                                 = 4,                            // 4,   -> "Лечебная физическая культура",
    ORGANIZATION_SPORTS_TOURISM                 = 5,                            // 5,   -> "Организация физкультурно-оздоровительной работы и туризма",
    PRESCHOOL_PHYSICAL_EDUCATION                = 6,                            // 6,   -> "Дошкольное физическое воспитание",
    DANCE_SPORT                                 = 7,                            // 7,   -> "Танцевальный спорт",
    AEROBICS                                    = 8,                            // 8,   -> "Аэробика",
    ROWING_OTHER                                = 9,                            // 9,   -> "Гребной спорт",
    SWIMMING                                    = 10,                           // 10,  -> "Плавание",
    SAILING                                     = 11,                           // 11,  -> "Парусный спорт",
    ATHLETICS                                   = 12,                           // 12,  -> "Легкая атлетика",
    CROSS_COUNTRY_SKIING                        = 13,                           // 13,  -> "Лыжные гонки",
    BULLET_SHOOTING_DEANERY                     = 14,                           // 14,  -> "Пулевая стрельба",
    HAND_TO_HAND_COMBAT                         = 15,                           // 15,  -> "Рукопашный бой",
    TAEKWONDO                                   = 16,                           // 16,  -> "Таэквондо",
    KARATE                                      = 17,                           // 17,  -> "Каратэ",
    SKIING                                      = 18,                           // 18,  -> "Лыжный спорт",
    AUTOMOTIVE_SPORT                            = 19,                           // 19,  -> "Автомобильный спорт",
    BASKETBALL                                  = 20,                           // 20,  -> "Баскетбол",
    BOXING                                      = 21,                           // 21,  -> "Бокс",
    GRECO_FREESTYLE_WRESTLING                   = 22,                           // 22,  -> "Греко-римская и вольная борьба",
    CYCLING                                     = 23,                           // 23,  -> "Велосипедный спорт",
    VOLLEYBALL                                  = 24,                           // 24,  -> "Волейбол",
    HANDBALL                                    = 25,                           // 25,  -> "Гандбол",
    EQUESTRIAN                                  = 26,                           // 26,  -> "Конный спорт",
    SPEED_SKATING                               = 27,                           // 27,  -> "Конькобежный спорт",
    TENNIS                                      = 28,                           // 28,  -> "Теннис",
    WEIGHTLIFTING                               = 29,                           // 29,  -> "Тяжелая атлетика",
    FENCING                                     = 30,                           // 30,  -> "Фехтование",
    FIGURE_SKATING                              = 31,                           // 31,  -> FIGURE_SKATING "Фигурное катание",
    FOOTBALL                                    = 32,                           // 32,  -> "Футбол",
    HOCKEY                                      = 33,                           // 33,  -> "Хоккей",
    WRESTLING                                   = 35,                           // 35,  -> "Спортивная борьба",
    BIATHLON                                    = 37,                           // 37,  -> "Биатлон",
    HEALTH_IMPROVING                            = 38,                           // 38,  -> "Оздоровительная физическая культура",
    ADAPTIVE                                    = 39,                           // 39,  -> "Адаптивная физическая культура",
    FREESTYLE_WRESTLING                         = 42,                           // 42,  -> "Вольная борьба",
    GRECO_ROMAN_WRESTLING                       = 43,                           // 43,  -> "Греко-римская борьба",
    SAMBO                                       = 44,                           // 44,  -> "Самбо",
    JUDO                                        = 45,                           // 45,  -> "Дзюдо",
    TABLE_TENNIS                                = 46,                           // 46,  -> "Теннис настольный",
    ERGOTHERAPY                                 = 47,                           // 47,  -> "Эрготерапия",
    MANAGEMENT_SPORTS                           = 48,                           // 48,  -> "Менеджмент в спорте",
    SPORTS_RECREATIONAL_TOURISM                 = 50,                           // 50,  -> "Спортивный и рекреационный туризм",
    MANAGEMENT_TOURISM                          = 51,                           // 51,  -> "Менеджмент в туризме",
    SPORTS_PSYCHOLOGY                           = 52,                           // 52,  -> "Спортивная психология",
    BILLIARD_SPORTS                             = 53,                           // 53,  -> "Бильярдный спорт",
    ACROBATICS                                  = 54,                           // 54,  -> "Акробатика",
    ORIENTEERING                                = 55,                           // 55,  -> "Спортивное ориентирование",
    SPORTS_DIRECTING                            = 56,                           // 56,  -> "Спортивная режиссура",
    PRESCHOOLERS                                = 57,                           // 57,  -> "Физическая культура дошкольников",
    MOUNTAINEERING                              = 59,                           // 59,  -> "Альпинизм",
    SKI_COMBINED                                = 60,                           // 60,  -> "Лыжное двоеборье",
    TOURISM_HOSPITALITY                         = 61,                           // 61,  -> "Туризм и гостеприимство",
    WATER_TECHNICAL_SPORTS                      = 62,                           // 62,  -> "Водно-технические виды спорта",
    MODEL_TECHNICAL_SPORTS                      = 63,                           // 63,  -> "Модельно-технические виды спорта",
    ALPINE_SKIING                               = 64,                           // 64,  -> "Горнолыжный спорт",
    BASEBALL                                    = 65,                           // 65,  -> "Бейсбол",
    WUSHU                                       = 66,                           // 66,  -> "Ушу",
    CHESS                                       = 68,                           // 68,  -> "Шахматы",
    THAI_BOXING                                 = 69,                           // 69,  -> "Таиландский бокс",
    TOURISM_PROMOTION                           = 70,                           // 70,  -> "Технологии формирования и продвижения туристических услуг",
    TOURISM_IT                                  = 71,                           // 71,  -> "Информационные технологии туристической индустрии",
    TOURISM_LOGISTICS                           = 72,                           // 72,  -> "Логистика в туристической индустрии",
    TOURISM_SOCIAL                              = 73,                           // 73,  -> "Технологии социокультурного сервиса туристов",
    TOURISM_TRANSPORT                           = 74,                           // 74,  -> "Технологии транспортного сервиса туристов",
    TOURISM_FOOD                                = 75,                           // 75,  -> "Технологии сервиса питания туристов",
    TOURIST_ACCOMMODATION                       = 76,                           // 76,  -> "Технологии сервиса размещения туристов",
    TOURISM_EXCURSION                           = 77,                           // 77,  -> "Технологии экскурсионно-сопроводительного сервиса туристов",
    TOURISM_HEALTH                              = 78,                           // 78,  -> "Технологии сервиса оздоровления и лечения туристов",
    BULLET_SHOOTING                             = 79,                           // 79,  -> "Стрельба пулевая",
    FIELD_HOCKEY                                = 80,                           // 80,  -> "Хоккей на траве",
    FIGURE_SKATING_SKATES                       = 84,                           // 84,  -> "Фигурное катание на коньках",
    ROWING_AND_CANOEING                         = 87,                           // 87,  -> "Гребля на байдарках и каноэ",
    ACADEMIC_ROWING                             = 88,                           // 88,  -> "Гребля академическая",
    HAND_TO_HAND_MARTIAL_ARTS                   = 92,                           // 92,  -> "Рукопашный бой (смешанные единоборства)",
    BILLIARDS                                   = 93,                           // 93,  -> "Бильярд",
    WITHOUT_SPECIALIZATION                      = 94,                           // 94,  -> "Без специализации",
    MODERN_PENTATHLON                           = 96,                           // 96,  -> "Современное пятиборье",
    SCIENCE_HEALTH                              = 101,                          // 101, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной",
    PHYSIOLOGY                                  = 102,                          // 102, -> "физиология",
    SCIENCE_THEORY                              = 103,                          // 103, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной",
    RECEARCH_SPORT                              = 104,                          // 104, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной",
    INNOVATIVE_TOURISM                          = 105,                          // 105, -> "инновационный менеджмент в сфере туризма",
    INNOVATIVE_HOSPITALITY                      = 106,                          // 106, -> "инновационный менеджмент в сфере гостеприимства",
    INNOVATIVE_TECHNOLOGIES                     = 107,                          // 107, -> "инновационные технологии в сфере туризма и гостеприимства",
    INNOVATIVE_MANAGEMENT                       = 108,                          // 108, -> "управление инновационными проектами в туристской индустрии",
    BADMINTON                                   = 116,                          // 116, -> "Бадминтон",
    PHYSICAL_CULTURE_SPORT                      = 118,                          // 118, -> "Физическая культура и спорт",
    TOURISM_HOSPITALITY_MASTER                  = 119,                          // 119, -> "Туризм и гостеприимство",
    SPORT_CLIMBING                              = 120,                          // 120, -> "Скалолазание спортивное",
    MASTER_ANTHROPOLOGY                         = 121,                          // 121, -> "антропология",
    MASTER_MANAGEMENT                           = 122                           // 122  -> "Менеджмент",
};
enum SectionCode
{
    NSPEC_HIGH_SCHOOL_IMPROVING                 = 5,                            // 5,  -> "Оздоровительная и адаптивная физическая культура"     (по направлениям)
    NSPEC_HIGH_SCHOOL_COACHING                  = 6,                            // 6,  -> "Спортивно-педагогическая деятельность"                (по направлениям)
    NSPEC_HIGH_SCHOOL_MANAGEMENT                = 7,                            // 7,  -> "Спортивно-туристская деятельность"                    (по направлениям)
    NSPEC_HIGH_SCHOOL_PHYSICAL_CULTURE          = 8,                            // 8,  -> "Физическая культура"                                  (по направлениям)
    NSPEC_HIGH_SCHOOL_REHABILITATION            = 9,                            // 9,  -> "Физическая реабилитация и эрготерапия"                (по направлениям)
    NSPEC_HIGH_SCHOOL_TOURISM                   = 10,                           // 10, -> "Туризм и гостеприимство"
    NSPEC_MASTER_SCIENCE_THEORY                 = 11,                           // 11, -> "Теория и методика физического воспитания, спортивной тренировки, оздоровительной"
    NSPEC_MASTER_SCIENCE_PHYSIOLOGY             = 12,                           // 12, -> "Физиология"
    NSPEC_MASTER_RESEARCH_SPORT                 = 13,                           // 13, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной ФК"
    NSPEC_MASTER_INNOVATION_TOURISM             = 14,                           // 14, -> "инновационный менеджмент в сфере туризма"
    NSPEC_MASTER_INNOVATION_HOSPITALITY         = 15,                           // 15, -> "инновационный менеджмент в сфере гостеприимства"
    NSPEC_MASTER_INNOVATION_TECHNOLOGY          = 16,                           // 16, -> "инновационные технологии в сфере туризма и гостеприимства"
    NSPEC_MASTER_INNOVATION_MANAGEMENT          = 17,                           // 17, -> "управление инновационными проектами в туристской индустрии"
    NSPEC_MASTER_RESEARCH_PHYSICAL_CULTURE      = 18,                           // 18, -> "физическая культура и спорт"
    NSPEC_MASTER_RESEARCH_TOURISM               = 19,                           // 19, -> "туризм и гостеприимство"
    NSPEC_MASTER_RESEARCH_MANAGEMENT            = 20                            // 20  -> "Менеджмент"

    #ifdef ADDITIONAL_SECTION
    NSPEC_SPORTS_CHOREOGRAPHY                   = 21,                           // 21, -> "Спортивная хореография" (code: "1-88 02 74")
    NSPEC_HIGH_SCHOOL_NATURE                    = 22,                           // 22, -> "Туризм и природопользование" (code: "1-89 02 02")
    NSPEC_HOSPITALITY_TECHNOLOGIES              = 23                            // 23  -> "Технология индустрии гостеприимства (по направлениям)" (code: "1-89 03 01")
    #endif
};
enum ProfilingCode                                                              // INSTEAD OF DeanerySpecialDirectionNSpecDirCode
{
    NSPECDIR_SPORT_COACHING                     = 1,                            // 1,  -> "Тренерская работа по",
    NSPECDIR_SPORT_PSYCHOLOGY                   = 2,                            // 2,  -> "Спортивная психология",
    NSPECDIR_SPORT_DIRECTING                    = 3,                            // 3,  -> "Спортивная режиссура",
    NSPECDIR_SPORT_MANAGEMENT                   = 4,                            // 4,  -> "Менеджмент в спорте",
    NSPECDIR_MANAGEMENT_RECREATIONAL            = 5,                            // 5,  -> "Спортивный и рекреационный туризм",
    NSPECDIR_MANAGEMENT_TOURISM_MNG             = 6,                            // 6,  -> "Менеджмент в туризме",
    NSPECDIR_PHYSICAL_CULTURE_MEDICAL           = 7,                            // 7,  -> "Лечебная",
    NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS      = 8,                            // 8,  -> "Дошкольников",
    NSPECDIR_IMPROVING_HEALTH                   = 9,                            // 9,  -> "Оздоровительная",
    NSPECDIR_IMPROVING_ADAPTIVE                 = 10,                           // 10, -> "Адаптивная",
    NSPECDIR_REHABILITATION_REHABILITATION      = 11,                           // 11, -> "Физическая реабилитация",
    NSPECDIR_REHABILITATION_ERGOTHERAPY         = 12,                           // 12, -> "Эрготерапия",
    NSPECDIR_TOURISM_HOSPITALITY                = 13,                           // 13, -> "Туризм и гостеприимство",
    NSPECDIR_TOURISM_PROMOTION                  = 14,                           // 14, -> "Технологии формирования и продвижения туристических услуг",
    NSPECDIR_TOURISM_IT                         = 15,                           // 15, -> "Информационные технологии туристической индустрии",
    NSPECDIR_TOURISM_LOGISTICS                  = 16,                           // 16, -> "Логистика в туристической индустрии",
    NSPECDIR_TOURISM_SOCIAL                     = 17,                           // 17, -> "Технологии социокультурного сервиа туристов",
    NSPECDIR_TOURISM_TRANSPORT                  = 18,                           // 18, -> "Технологии транспортного сервиса туристов",
    NSPECDIR_TOURISM_CATERING                   = 19,                           // 19, -> "Технологии сервиса питания туристов",
    NSPECDIR_TOURISM_ACCOMMODATION              = 20,                           // 20, -> "Технологии сервиса размещения туристов",
    NSPECDIR_TOURISM_SUPPORTING                 = 21,                           // 21, -> "Технологии экскурсионно-сопроводительного сервиса туристов",
    NSPECDIR_TOURISM_TREATMENT                  = 22,                           // 22, -> "Технологии сервиса оздоровления и лечения туристов",
    NSPECDIR_MASTER_SCIENCE_THEORY              = 23,                           // 23, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной физической культуры.",
    NSPECDIR_MASTER_SCIENCE_PHYSIOLOGY          = 24,                           // 24, -> "Физиология",
    NSPECDIR_MASTER_RESEARCH_SPORT              = 25,                           // 25, -> "Теория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной физической культуры.",
    NSPECDIR_MASTER_INNOVATION_TOURISM          = 26,                           // 26, -> "Инновационный менеджмент в сфере туризма",
    NSPECDIR_MASTER_INNOVATION_HOSPITALITY      = 27,                           // 27, -> "Инновационный менеджмент в сфере гостеприимства",
    NSPECDIR_MASTER_INNOVATION_TECHNOLOGY       = 28,                           // 28, -> "Инновационные технологии в сфере туризма и гостеприимства",
    NSPECDIR_MASTER_INNOVATION_MANAGEMENT       = 29,                           // 29, -> "Управление инновационными проектами в туристской индустрии",
    NSPECDIR_MASTER_RESEARCH_MANAGEMENT         = 30,                           // 30, -> "Менеджмент",
    NSPECDIR_MASTER_RESEARCH_PHYSICAL_CULTURE   = 31,                           // 31, -> "Физическая культура и спорт",
    NSPECDIR_MASTER_RESEARCH_TOURISM            = 32                            // 32  -> "Туризм и гостеприимство";
};
enum FacultyCode
{
    SMA                                         = 1,                            // 1, -> Sports and Marital Arts (СИиЕ)
    MS                                          = 2,                            // 2, -> Mass Sports (МВС)
    RPC                                         = 3,                            // 3, -> Recreational Physical Culture (ОФКиТ)
    MSTH                                        = 4,                            // 4, -> Management of Sports, Tourism and Hospitality (МСиТ)
    MD                                          = 5,                            // 5, -> Master's Degree (Магстратура)
    PGS                                         = 6,                            // 6, -> PostGraduate Studies (Аспирантура)
    DOC                                         = 7                             // 7  -> DOCtorate (Докторантура)
};

enum StudyPeriodCode
{
    FULL                                        = 0,                            // 0, -> "Полный срок"
    SHORT_SECOND_COURSE                         = 1,                            // 1, -> "Cокращённый срок (2 курс)"
    SHORT_THIRD_COURSE                          = 2,                            // 2, -> "Cокращённый срок (3 курс)"
    HIGH_FIRST_COURSE                           = 3,                            // 3, -> "Высшее образование (1 курс)"
    HIGH_SECOND_COURSE                          = 4,                            // 4, -> "Высшее образование (2 курс)"
    HIGH_THIRD_COURSE                           = 5                             // 5  -> "Высшее образование (3 курс)"
};
enum EducationTypeCode
{
    INTRAMURAL                                  = 0,
    EXTRAMURAL                                  = 1
};
enum PaymentCode
{
    BUDGET                                      = 0,
    BUYERS                                      = 1
};
enum Section2022Code                                                            // INSTEAD OF DirectionNcrb2022Code
{
    PHYSICAL_CULTURE_2022                       = 0,                            // 1, -> 6-05-1012-01
    COACHING_2022                               = 1,                            // 2, -> 6-05-1012-02
    REHABILITATION_2022                         = 2,                            // 3, -> 6-05-1012-03
    MANAGEMENT_2022                             = 3,                            // 4, -> 6-05-1012-04
    TOURISM_2022                                = 4                             // 5  -> 6-05-1013-01
};
enum Profiling2022Code
{
    IMPROVING_PROF                              = 1,
    HEALTH_PROF                                 = 2,
    PRESCHOOLERS_PROF                           = 3,
    ADIAPTIVE_PROF                              = 4,
    DIRECTING_PROF                              = 5,
    PSYCHOLOGY_PROF                             = 6,
    RECRIATIONAL_PROF                           = 7,
    COACHING_PROF                               = 8,
    REHABILITATION_PROF                         = 9,
    ERGOTHERAPY_PROF                            = 10,
    SPORT_PROF                                  = 11,
    TOURISM_PROF                                = 12,
    HOSPITALITY_PROF                            = 13
};

#endif // ENUMS_HPP
