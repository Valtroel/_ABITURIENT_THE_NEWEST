#pragma once
#ifndef ENUMS_HPP
#define ENUMS_HPP


#ifndef STATE_FROM_WORK_PC
    #ifndef NEW_INTEGRATION
        enum ContestTypeCode
        {
            GENERAL                             = 0,
            OUT_OF_COMPETITION                  = 1,
            WITHOUT_ENTRANCE_EXAMS              = 2,
            TARGETED_TRAINING                   = 3
        };
        enum Default
        {
            EMPTY                               = 0,
            START                               = 0,
            DISABLE                             = 0,
            STEP                                = 1,
            ENABLE                              = 1,
            LOOPS_MAX_ITERATIONS                = 2
        };
        enum EducationTypeCode
        {
            INTRAMURAL                          = 0,
            EXTRAMURAL                          = 1
        };
        enum FacultyCode
        {
            SMA                                 = 1,                                    // Sports and Marital Arts (СИиЕ)
            MS                                  = 2,                                    // Mass Sports (МВС)
            RPC                                 = 3,                                    // Recreational Physical Culture (ОФКиТ)
            MSTH                                = 4,                                    // Management of Sports, Tourism and Hospitality (МСиТ)
            MD                                  = 5,                                    // Master's Degree (Магстратура)
            PGS                                 = 6,                                    // PostGraduate Studies (Аспирантура)
            DOC                                 = 7                                     // DOCtorate (Докторантура)
        };
        enum FormTypeCode
        {
            REGISTRATION                        = 1,
            ENROLLMENT                          = 2
        };
        enum PaymentCode
        {
            BUDGET                              = 0,
            BUYERS                              = 1
        };
        enum SportsRanksCode
        {
            THIRD_SPORT_CATEGORY                = 1,                                    // 1  -> 3 разряд
            SECOND_SPORT_CATEGORY               = 2,                                    // 2  -> 2 разряд
            FIRST_SPORT_CATEGORY                = 3,                                    // 3  -> 1 разряд
            CANDIDATE_IN_MASTERS_OF_SPORT       = 4,                                    // 4  -> КМС
            MASTER_OF_SPORT                     = 5,                                    // 5  -> МС
            INTERNATIONAL_MASTER_OF_SPORTS      = 6,                                    // 6  -> МСМК
            HONORED_MASTER_OF_SPORTS            = 7,                                    // 7  -> ЗМС
            THIRD_APPRENTICESHIP_DEGREE         = 8,                                    // 8  -> 3 кю
            SECOND_APPRENTICESHIP_DEGREE        = 9,                                    // 9  -> 2 кю
            FIRST_APPRENTICESHIP_DEGREE         = 10,                                   // 10 -> 1 кю
            FIRST_YOUTH_CATEGORY                = 11,                                   // 11 -> 1 юношеский разряд
            WITHOUT                             = 12,                                   // 12 -> нет
            SECOND_YOUTH_CATEGORY               = 13
        };
        enum StudyPeriodCode
        {
            FULL                                = 0,                                    // "Полный срок"
            SHORT_SECOND_COURSE                 = 1,                                    // "Cокращённый срок (2 курс)"
            SHORT_THIRD_COURSE                  = 2,                                    // "Cокращённый срок (3 курс)"
            HIGH_FIRST_COURSE                   = 3,                                    // "Высшее образование (1 курс)"
            HIGH_SECOND_COURSE                  = 4,                                    // "Высшее образование (2 курс)"
            HIGH_THIRD_COURSE                   = 5                                     // "Высшее образование (3 курс)"
        };
        enum SubjectCode
        {
            RUS                                 = 0,
            BEL                                 = 1
        };

        enum DeaneryQualificationNameByNomerQu
        {
            TEACHER_PHYSICAL_CULTURE_SPORTS     = 1,
            COACHING_BY_SPORT                   = 2,
            PHYSICAL_EDUCATION_TEACHER          = 3,
            TEACHER_ORGANIZER_HEALTH_TOURISM    = 4,
            TEACHER_ORGANIZER_PRESCHOOLERS      = 5,
            MANAGER_SPORT_TOURISM               = 6,
            INSTRUCTOR_REHABILITATION           = 7,
            INSTRUCTOR_MEDICAL                  = 8,
            TEACHER_PHYSICAL_CULTURE            = 9,
            INSTRUCTOR_BY_HEALTH                = 10,
            INSTRUCTOR_BY_ADAPTIVE              = 11,
            INSTRUCTOR_PRESCHOOLERS             = 12,
            PSYCHOLOGIST                        = 13,
            MANAGER_SPORT                       = 14,
            MANAGER_TUORISM                     = 15,
            INSTRUCTOR_RECREATIONAL             = 16,
            MANAGER_DIRECTING                   = 17,
            INSTRUCTOR_BY_MEDICAL               = 18,
            INSTRUCTOR_BY_REHABILITATION        = 19,
            INSTRUCTOR_BY_ERGOTHERAPY           = 20,
            SPECIALIST_TOURISM_HOSPITALITY      = 21
        };
        enum DeanerySpecialDirectionNSpecDirCode
        {
            SPORT_COACHING                      = 1,                                    // old code: "1-88 02 01-01",
            SPORT_PSYCHOLOGY                    = 2,                                    // old code: "1-88 02 01-03",
            SPORT_DIRECTING                     = 3,                                    // old code: "1-88 02 01-04",
            SPORT_MANAGEMENT                    = 4,                                    // old code: "1-88 02 01-02",
            TOURISM_RECREATIONAL                = 5,                                    // old code: "1-89 02 01-01",
            TOURISM_TUORISM_MNG                 = 6,                                    // old code: "1-89 02 01-02",
            PHYSICAL_CULTURE_MEDICAL            = 7,                                    // old code: "1-88 01 01-01",
            PHYSICAL_CULTURE_PRESCHOOLERS       = 8,                                    // old code: "1-88 01 01-02",
            IMPROVING_HEALTH                    = 9,                                    // old code: "1-88 01 02-01",
            IMPROVING_ADAPTIVE                  = 10,                                   // old code: "1-88 01 02-02",
            REHABILITATION_REHABILITATION       = 11,                                   // old code: "1-88 01 03-01",
            REHABILITATION_ERGOTHERAPY          = 12,                                   // old code: "1-88 01 03-02",
            SECTION_TOURISM_HOSPITALITY         = 13,                                   // old code: "1-89 01 01",
            TOURISM_HOSPITALITY_PROMOTION       = 14,                                   // old code: "1-89 01 01 01",
            TOURISM_HOSPITALITY_IT              = 15,                                   // old code: "1-89 01 01 02",
            TOURISM_HOSPITALITY_LOGISTICS       = 16,                                   // old code: "1-89 01 01 03",
            TOURISM_HOSPITALITY_SOCIAL          = 17,                                   // old code: "1-89 01 01 04",
            TOURISM_HOSPITALITY_TRANSPORT       = 18,                                   // old code: "1-89 01 01 05",
            TOURISM_HOSPITALITY_CATERING        = 19,                                   // old code: "1-89 01 01 06",
            TOURISM_HOSPITALITY_ACCOMMODATION   = 20,                                   // old code: "1-89 01 01 07",
            TOURISM_HOSPITALITY_SUPPORTING      = 21,                                   // old code: "1-89 01 01 08",
            TOURISM_HOSPITALITY_TREATMENT       = 22,                                   // old code: "1-89 01 01 09",
            MASTER_SCIENCE_THEORY               = 23,                                   // old code: "13.00.04",
            MASTER_SCIENCE_PHYSIOLOGY           = 24,                                   // old code: "03.03.01",
            MASTER_RESEARCH_SPORT               = 25,                                   // old code: "1-08 80 04",
            MASTER_INNOVATION_TOURISM           = 26,                                   // old code: "1-89 81 02",
            MASTER_INNOVATION_HOSPITALITY       = 27,                                   // old code: "1-89 81 03",
            MASTER_INNOVATION_TECHNOLOGY        = 28,                                   // old code: "1-89 81 04",
            MASTER_INNOVATION_MANAGEMENT        = 29,                                   // old code: "1-89 81 01",      // NOT USE
            MASTER_PHYSICAL_CULTURE_SPORT       = 31,                                   // old code: "1-08 80 04",
            MASTER_RESEARCH_TOURISM             = 32                                    // old code: "1-89 80 01",
        };
        enum DeanerySpecialityNSpecCode
        {
            PHYSICAL_CULTURE_SPORT_AUX          = 1,                                    // old code: "П 02.02.00"
            IMPROVING_AND_ADAPTIVE_AUX          = 5,                                    // old code: "1-88 01 02"
            SPORTS_AND_PEDAGOGY_AUX             = 6,                                    // old code: "1-88 02 01"
            SPORTS_AND_TOURISM_AUX              = 7,                                    // old code: "1-89 02 01"
            PHYSICAL_CULTURE_AUX                = 8,                                    // old code: "1-88 01 01"
            REHABILITATION_ERGOTHERAPY_AUX      = 9,                                    // old code: "1-88 01 03"
            TOURISM_HOSPITALITY_AUX             = 10,                                   // old code: "1-89 01 01"
            THEORY_IMPROVING_AUX                = 11,                                   // old code: "13.00.04"
            PHYSIOLOGY_AUX                      = 12,                                   // old code: "03.03.01"
            THEORY_ADAPTIVE_AUX                 = 13,                                   // old code: "1-08 80 04"
            INNOVATION_TOURISM_AUX              = 14,                                   // old code: "1-89 81 02"
            INNOVATION_HOSPITALITY_AUX          = 15,                                   // old code: "1-89 81 03"
            INNOVATION_TECHNOLOGY_AUX           = 16,                                   // old code: "1-89 81 04"
            INNOVATION_MANAGEMENT_AUX           = 17,                                   // old code: "1-89 81 01"
            MASTER_PHYSICAL_CULTURE_AUX         = 18,                                   // old code: "1-08 80 04"
            TOURISM_HOSPITALITY_STUDY_AUX       = 19,                                   // old code: "1-89 80 01"

            TRAINING_MILITARY_PERSONNEL_AUX     = 20,                                   // old code: "1-88 01 04"
            SPORTS_CHOREOGRAPHY_AUX             = 21,                                   // old code: "1-88 02 74"
            TOURISM_AND_NATURE_MANAGEMENT_AUX   = 22,                                   // old code: "1-89 02 02"
            HOSPITALITY_TECHNOLOGIES_AUX        = 23                                    // old code: "1-89 03 01"
        };
        enum DirectionNcrb2022Code
        {
            PHYSICAL_CULTURE_2022               = 1,                                    // 6-05-1012-01
            COACHING_2022                       = 2,                                    // 6-05-1012-02
            REHABILITATION_2022                 = 3,                                    // 6-05-1012-03
            MANAGEMENT_2022                     = 4,                                    // 6-05-1012-04
            TOURISM_2022                        = 5                                     // 6-05-1013-01
        };
        enum KindOfSportCode
        {
            GYMNASTICS                          = 1,                                    // "Гимнастика",
            MANAGEMENT_SPORTS_TOURISM           = 2,                                    // "Менеджмент спорта и туризма",
            PHYSICAL_REHABILITATION             = 3,                                    // "Физическая реабилитация",
            THERAPEUTIC                         = 4,                                    // "Лечебная физическая культура",
            ORGANIZATION_SPORTS_TOURISM         = 5,                                    // "Организация физкультурно-оздоровительной работы и туризма",
            PRESCHOOL_PHYSICAL_EDUCATION        = 6,                                    // "Дошкольное физическое воспитание",
            DANCE_SPORT                         = 7,                                    // "Танцевальный спорт",
            AEROBICS                            = 8,                                    // "Аэробика",
            ROWING_OTHER                        = 9,                                    // "Гребной спорт",
            SWIMMING                            = 10,                                   // "Плавание",
            SAILING                             = 11,                                   // "Парусный спорт",
            ATHLETICS                           = 12,                                   // "Легкая атлетика",
            CROSS_COUNTRY_SKIING                = 13,                                   // "Лыжные гонки",
            BULLET_SHOOTING_DEANERY             = 14,                                   // "Пулевая стрельба",
            HAND_TO_HAND_COMBAT                 = 15,                                   // "Рукопашный бой",
            TAEKWONDO                           = 16,                                   // "Таэквондо",
            KARATE                              = 17,                                   // "Каратэ",
            SKIING                              = 18,                                   // "Лыжный спорт",
            AUTOMOTIVE_SPORT                    = 19,                                   // "Автомобильный спорт",
            BASKETBALL                          = 20,                                   // "Баскетбол",
            BOXING                              = 21,                                   // "Бокс",
            GRECO_FREESTYLE_WRESTLING           = 22,                                   // "Греко-римская и вольная борьба",
            CYCLING                             = 23,                                   // "Велосипедный спорт",
            VOLLEYBALL                          = 24,                                   // "Волейбол",
            HANDBALL                            = 25,                                   // "Гандбол",
            EQUESTRIAN                          = 26,                                   // "Конный спорт",
            SPEED_SKATING                       = 27,                                   // "Конькобежный спорт",
            TENNIS                              = 28,                                   // "Теннис",
            WEIGHTLIFTING                       = 29,                                   // "Тяжелая атлетика",
            FENCING                             = 30,                                   // "Фехтование",
            FIGURE_SKATING_OLD                  = 31,                                   // FIGURE_SKATING "Фигурное катание",
            FOOTBALL                            = 32,                                   // "Футбол",
            HOCKEY                              = 33,                                   // "Хоккей",
            SAMBO_JUDO                          = 34,                                   // "Самбо-дзюдо",
            WRESTLING                           = 35,                                   // "Спортивная борьба",
            FOOTBALL_HOCKEY                     = 36,                                   // "Футбол и хоккей",
            BIATHLON                            = 37,                                   // "Биатлон",
            HEALTH_IMPROVING                    = 38,                                   // "Оздоровительная физическая культура",
            ADAPTIVE                            = 39,                                   // "Адаптивная физическая культура",
            FREESTYLE_WRESTLING                 = 42,                                   // "Вольная борьба",
            GRECO_ROMAN_WRESTLING               = 43,                                   // "Греко-римская борьба",
            SAMBO                               = 44,                                   // "Самбо",
            JUDO                                = 45,                                   // "Дзюдо",
            TABLE_TENNIS_ABITURIENT             = 46,                                   // "Теннис настольный",
            ERGOTHERAPY                         = 47,                                   // "Эрготерапия",
            MANAGEMENT_SPORTS                   = 48,                                   // "Менеджмент в спорте",
            SPORTS_DIRECTING_DEANERY            = 49,                                   // "Спортивная режиссура",
            SPORTS_RECREATIONAL_TOURISM         = 50,                                   // "Спортивный и рекреационный туризм",
            MANAGEMENT_TOURISM                  = 51,                                   // "Менеджмент в туризме",
            SPORTS_PSYCHOLOGY                   = 52,                                   // "Спортивная психология",
            BILLIARD_SPORTS                     = 53,                                   // "Бильярдный спорт",
            ACROBATICS                          = 54,                                   // "Акробатика",
            ORIENTEERING                        = 55,                                   // "Спортивное ориентирование",
            SPORTS_DIRECTING                    = 56,                                   // "Спортивная режиссура",
            PRESCHOOLERS                        = 57,                                   // "Физическая культура дошкольников",
            MOUNTAINEERING                      = 59,                                   // "Альпинизм",
            SKI_COMBINED                        = 60,                                   // "Лыжное двоеборье",
            TOURISM_HOSPITALITY                 = 61,                                   // "Туризм и гостеприимство",
            WATER_TECHNICAL_SPORTS              = 62,                                   // "Водно-технические виды спорта",
            MODEL_TECHNICAL_SPORTS              = 63,                                   // "Модельно-технические виды спорта",
            ALPINE_SKIING                       = 64,                                   // "Горнолыжный спорт",
            BASEBALL                            = 65,                                   // "Бейсбол",
            WUSHU                               = 66,                                   // "Ушу",
            CHESS                               = 68,                                   // "Шахматы",
            THAI_BOXING                         = 69,                                   // "Таиландский бокс",
            TOURISM_PROMOTION                   = 70,                                   // "Технологии формирования и продвижения туристических услуг",
            TOURISM_IT                          = 71,                                   // "Информационные технологии туристической индустрии",
            TOURISM_LOGISTICS                   = 72,                                   // "Логистика в туристической индустрии",
            TOURISM_SOCIAL                      = 73,                                   // "Технологии социокультурного сервиса туристов",
            TOURISM_TRANSPORT                   = 74,                                   // "Технологии транспортного сервиса туристов",
            TOURISM_FOOD                        = 75,                                   // "Технологии сервиса питания туристов",
            TOURIST_ACCOMMODATION               = 76,                                   // "Технологии сервиса размещения туристов",
            TOURISM_EXCURSION                   = 77,                                   // "Технологии экскурсионно-сопроводительного сервиса туристов",
            TOURISM_HEALTH                      = 78,                                   // "Технологии сервиса оздоровления и лечения туристов",
            BULLET_SHOOTING                     = 79,                                   // "Стрельба пулевая",
            FIELD_HOCKEY                        = 80,                                   // "Хоккей на траве",
            FIGURE_SKATING                      = 84,                                   // "Фигурное катание на коньках",
            ROWING_AND_CANOEING                 = 87,                                   // "Гребля на байдарках и каноэ",
            ACADEMIC_ROWING                     = 88,                                   // "Гребля академическая",
            HAND_TO_HAND_COMBAT_MS              = 92,                                   // "Рукопашный бой (смешанные единоборства)",
            BILLIARDS_RPC                       = 93,                                   // "Бильярд",
            WITHOUT_SPECIALIZATION              = 94,                                   // "Без специализации",
            MEDICAL                             = 95,                                   // "Физическая культура(лечебная)",
            MODERN_PENTATHLON                   = 96,                                   // "Современное пятиборье",
            SPORTS_RECREATIONAL_TOURISM_OLD     = 100,                                  // "Спортивный и рекреационный туризм"
            SCIENCE_HEALTH                      = 101,                                  // "теория и методика физического воспитания, спортивной тренировки, оздоровительной",
            PHYSIOLOGY                          = 102,                                  // "физиология",
            SCIENCE_THEORY                      = 103,                                  // "теория и методика физического воспитания, спортивной тренировки, оздоровительной",
            RECEARCH_SPORT                      = 104,                                  // "теория и методика физического воспитания, спортивной тренировки, оздоровительной",
            INNOVATIVE_TOURISM                  = 105,                                  // "инновационный менеджмент в сфере туризма",
            INNOVATIVE_HOSPITALITY              = 106,                                  // "инновационный менеджмент в сфере гостеприимства",
            INNOVATIVE_TECHNOLOGIES             = 107,                                  // "инновационные технологии в сфере туризма и гостеприимства",
            INNOVATIVE_MANAGEMENT               = 108,                                  // "управление инновационными проектами в туристской индустрии",
            BILLIARDS_SMA                       = 109,                                  // "Бильярд",
            HAND_TO_HAND_COMBAT_SMA             = 110,                                  // "Рукопашный бой (смешанные единоборства)",
            BADMINTON                           = 116,                                  // "Бадминтон",
            TABLE_TENNIS_DEANERY                = 117,                                  // "Настольный теннис",
            PHYSICAL_CULTURE_SPORT              = 118,                                  // "Физическая культура и спорт",
            TOURISM_HOSPITALITY_MASTER          = 119,                                  // "Туризм и гостеприимство",
            SPORT_CLIMBING                      = 120,                                  // "Скалолазание спортивное",
            MASTER_ANTHROPOLOGY                 = 121,                                  // "антропология",
            MASTER_MANAGEMENT                   = 122                                   // "Менеджмент",
        };
        enum ProfilingNcrb2022
        {
            IMPROVING_PROF                      = 1,
            HEALTH_PROF                         = 2,
            PRESCHOOLERS_PROF                   = 3,
            ADIAPTIVE_PROF                      = 4,
            DIRECTING_PROF                      = 5,
            PSYCHOLOGY_PROF                     = 6,
            RECRIATIONAL_PROF                   = 7,
            COACHING_PROF                       = 8,
            REHABILITATION_PROF                 = 9,
            ERGOTHERAPY_PROF                    = 10,
            SPORT_PROF                          = 11,
            TOURISM_PROF                        = 12,
            HOSPITALITY_PROF                    = 13
        };
    #else
        enum ContestTypeCode
        {
            GENERAL                                     = 0,
            WITHOUT_ENTRANCE_EXAMS                      = 1,
            OUT_OF_COMPETITION                          = 2,
            TARGETED_TRAINING                           = 3
        };
        enum Default
        {
            EMPTY                                       = 0,
            START                                       = 0,
            DISABLE                                     = 0,
            STEP                                        = 1,
            ENABLE                                      = 1,
            LOOPS_MAX_ITERATIONS                        = 2
        };
        enum EducationTypeCode
        {
            INTRAMURAL                                  = 0,
            EXTRAMURAL                                  = 1
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
        enum FormTypeCode
        {
            REGISTRATION                                = 1,
            ENROLLMENT                                  = 2
        };
        enum LineThicknessCode
        {
            THIN                                        = 1,
            MEDIUM                                      = 2,
            WIDE                                        = 3,
            EXTRA_WIDE                                  = 4
        };
        enum PaymentCode
        {
            BUDGET                                      = 0,
            BUYERS                                      = 1
        };
        enum SportsRanksCode
        {
            THIRD_SPORT_CATEGORY                        = 1,                            // 1  -> 3 разряд
            SECOND_SPORT_CATEGORY                       = 2,                            // 2  -> 2 разряд
            FIRST_SPORT_CATEGORY                        = 3,                            // 3  -> 1 разряд
            CANDIDATE_IN_MASTERS_OF_SPORT               = 4,                            // 4  -> КМС
            MASTER_OF_SPORT                             = 5,                            // 5  -> МС
            INTERNATIONAL_MASTER_OF_SPORTS              = 6,                            // 6  -> МСМК
            HONORED_MASTER_OF_SPORTS                    = 7,                            // 7  -> ЗМС
            THIRD_APPRENTICESHIP_DEGREE                 = 8,                            // 8  -> 3 кю
            SECOND_APPRENTICESHIP_DEGREE                = 9,                            // 9  -> 2 кю
            FIRST_APPRENTICESHIP_DEGREE                 = 10,                           // 10 -> 1 кю
            FIRST_YOUTH_CATEGORY                        = 11,                           // 11 -> 1 юношеский разряд
            WITHOUT                                     = 12,                           // 12 -> нет
            SECOND_YOUTH_CATEGORY                       = 13                            // 13 -> 2 юношеский разряд
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
        enum SubjectCode
        {
            RUS                                         = 0,
            BEL                                         = 1
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
        enum Section2022Code                                                            // INSTEAD OF DirectionNcrb2022Code
        {
            PHYSICAL_CULTURE_2022                       = 0,                            // 1, -> 6-05-1012-01
            COACHING_2022                               = 1,                            // 2, -> 6-05-1012-02
            REHABILITATION_2022                         = 2,                            // 3, -> 6-05-1012-03
            MANAGEMENT_2022                             = 3,                            // 4, -> 6-05-1012-04
            TOURISM_2022                                = 4                             // 5  -> 6-05-1013-01
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
            #endif  // ADDITIONAL_SECTION
        };
    #endif // ! NEW_INTEGRATION
#else
    enum ContestTypeCode
    {
        GENERAL                                     = 0,
        WITHOUT_ENTRANCE_EXAMS                      = 1,
        OUT_OF_COMPETITION                          = 2,
        TARGETED_TRAINING                           = 3
    };
    enum Default
    {
        EMPTY                                       = 0,
        START                                       = 0,
        DISABLE                                     = 0,
        STEP                                        = 1,
        ENABLE                                      = 1,
        LOOPS_MAX_ITERATIONS                        = 2
    };
    enum EducationTypeCode
    {
        INTRAMURAL                                  = 0,
        EXTRAMURAL                                  = 1
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
    enum FormTypeCode
    {
        REGISTRATION                                = 1,
        ENROLLMENT                                  = 2
    };
    enum LineThicknessCode
    {
        THIN                                        = 1,
        MEDIUM                                      = 2,
        WIDE                                        = 3,
        EXTRA_WIDE                                  = 4
    };
    enum PaymentCode
    {
        BUDGET                                      = 0,
        BUYERS                                      = 1
    };
    enum SportsRanksCode
    {
        THIRD_SPORT_CATEGORY                        = 1,                            // 1  -> 3 разряд
        SECOND_SPORT_CATEGORY                       = 2,                            // 2  -> 2 разряд
        FIRST_SPORT_CATEGORY                        = 3,                            // 3  -> 1 разряд
        CANDIDATE_IN_MASTERS_OF_SPORT               = 4,                            // 4  -> КМС
        MASTER_OF_SPORT                             = 5,                            // 5  -> МС
        INTERNATIONAL_MASTER_OF_SPORTS              = 6,                            // 6  -> МСМК
        HONORED_MASTER_OF_SPORTS                    = 7,                            // 7  -> ЗМС
        THIRD_APPRENTICESHIP_DEGREE                 = 8,                            // 8  -> 3 кю
        SECOND_APPRENTICESHIP_DEGREE                = 9,                            // 9  -> 2 кю
        FIRST_APPRENTICESHIP_DEGREE                 = 10,                           // 10 -> 1 кю
        FIRST_YOUTH_CATEGORY                        = 11,                           // 11 -> 1 юношеский разряд
        WITHOUT                                     = 12,                           // 12 -> нет
        SECOND_YOUTH_CATEGORY                       = 13                            // 13 -> 2 юношеский разряд
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
    enum SubjectCode
    {
        RUS                                         = 0,
        BEL                                         = 1
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

    enum DeaneryQualificationNameByNomerQu
    {
        TEACHER_PHYSICAL_CULTURE_SPORTS     = 1,
        COACHING_BY_SPORT                   = 2,
        PHYSICAL_EDUCATION_TEACHER          = 3,
        TEACHER_ORGANIZER_HEALTH_TOURISM    = 4,
        TEACHER_ORGANIZER_PRESCHOOLERS      = 5,
        MANAGER_SPORT_TOURISM               = 6,
        INSTRUCTOR_REHABILITATION           = 7,
        INSTRUCTOR_MEDICAL                  = 8,
        TEACHER_PHYSICAL_CULTURE            = 9,
        INSTRUCTOR_BY_HEALTH                = 10,
        INSTRUCTOR_BY_ADAPTIVE              = 11,
        INSTRUCTOR_PRESCHOOLERS             = 12,
        PSYCHOLOGIST                        = 13,
        MANAGER_SPORT                       = 14,
        MANAGER_TUORISM                     = 15,
        INSTRUCTOR_RECREATIONAL             = 16,
        MANAGER_DIRECTING                   = 17,
        INSTRUCTOR_BY_MEDICAL               = 18,
        INSTRUCTOR_BY_REHABILITATION        = 19,
        INSTRUCTOR_BY_ERGOTHERAPY           = 20,
        SPECIALIST_TOURISM_HOSPITALITY      = 21
    };
    enum DeanerySpecialityNSpecCode
    {
        PHYSICAL_CULTURE_SPORT_AUX          = 1,                                    // old code: "П 02.02.00"
        IMPROVING_AND_ADAPTIVE_AUX          = 5,                                    // old code: "1-88 01 02"
        SPORTS_AND_PEDAGOGY_AUX             = 6,                                    // old code: "1-88 02 01"
        SPORTS_AND_TOURISM_AUX              = 7,                                    // old code: "1-89 02 01"
        PHYSICAL_CULTURE_AUX                = 8,                                    // old code: "1-88 01 01"
        REHABILITATION_ERGOTHERAPY_AUX      = 9,                                    // old code: "1-88 01 03"
        TOURISM_HOSPITALITY_AUX             = 10,                                   // old code: "1-89 01 01"
        THEORY_IMPROVING_AUX                = 11,                                   // old code: "13.00.04"
        PHYSIOLOGY_AUX                      = 12,                                   // old code: "03.03.01"
        THEORY_ADAPTIVE_AUX                 = 13,                                   // old code: "1-08 80 04"
        INNOVATION_TOURISM_AUX              = 14,                                   // old code: "1-89 81 02"
        INNOVATION_HOSPITALITY_AUX          = 15,                                   // old code: "1-89 81 03"
        INNOVATION_TECHNOLOGY_AUX           = 16,                                   // old code: "1-89 81 04"
        INNOVATION_MANAGEMENT_AUX           = 17,                                   // old code: "1-89 81 01"
        MASTER_PHYSICAL_CULTURE_AUX         = 18,                                   // old code: "1-08 80 04"
        TOURISM_HOSPITALITY_STUDY_AUX       = 19,                                   // old code: "1-89 80 01"
        TRAINING_MILITARY_PERSONNEL_AUX     = 20,                                   // old code: "1-88 01 04"
        SPORTS_CHOREOGRAPHY_AUX             = 21,                                   // old code: "1-88 02 74"
        TOURISM_AND_NATURE_MANAGEMENT_AUX   = 22,                                   // old code: "1-89 02 02"
        HOSPITALITY_TECHNOLOGIES_AUX        = 23                                    // old code: "1-89 03 01"
    };
    #ifndef DELETE_PREVIOUS_VERSION_OF_KOS
        enum DeanerySpecialDirectionNSpecDirCode
        {
            SPORT_COACHING                      = 1,                                    // old code: "1-88 02 01-01",
            SPORT_PSYCHOLOGY                    = 2,                                    // old code: "1-88 02 01-03",
            SPORT_DIRECTING                     = 3,                                    // old code: "1-88 02 01-04",
            SPORT_MANAGEMENT                    = 4,                                    // old code: "1-88 02 01-02",
            TOURISM_RECREATIONAL                = 5,                                    // old code: "1-89 02 01-01",
            TOURISM_TUORISM_MNG                 = 6,                                    // old code: "1-89 02 01-02",
            PHYSICAL_CULTURE_MEDICAL            = 7,                                    // old code: "1-88 01 01-01",
            PHYSICAL_CULTURE_PRESCHOOLERS       = 8,                                    // old code: "1-88 01 01-02",
            IMPROVING_HEALTH                    = 9,                                    // old code: "1-88 01 02-01",
            IMPROVING_ADAPTIVE                  = 10,                                   // old code: "1-88 01 02-02",
            REHABILITATION_REHABILITATION       = 11,                                   // old code: "1-88 01 03-01",
            REHABILITATION_ERGOTHERAPY          = 12,                                   // old code: "1-88 01 03-02",
            SECTION_TOURISM_HOSPITALITY         = 13,                                   // old code: "1-89 01 01",
            TOURISM_HOSPITALITY_PROMOTION       = 14,                                   // old code: "1-89 01 01 01",
            TOURISM_HOSPITALITY_IT              = 15,                                   // old code: "1-89 01 01 02",
            TOURISM_HOSPITALITY_LOGISTICS       = 16,                                   // old code: "1-89 01 01 03",
            TOURISM_HOSPITALITY_SOCIAL          = 17,                                   // old code: "1-89 01 01 04",
            TOURISM_HOSPITALITY_TRANSPORT       = 18,                                   // old code: "1-89 01 01 05",
            TOURISM_HOSPITALITY_CATERING        = 19,                                   // old code: "1-89 01 01 06",
            TOURISM_HOSPITALITY_ACCOMMODATION   = 20,                                   // old code: "1-89 01 01 07",
            TOURISM_HOSPITALITY_SUPPORTING      = 21,                                   // old code: "1-89 01 01 08",
            TOURISM_HOSPITALITY_TREATMENT       = 22,                                   // old code: "1-89 01 01 09",
            MASTER_SCIENCE_THEORY               = 23,                                   // old code: "13.00.04",
            MASTER_SCIENCE_PHYSIOLOGY           = 24,                                   // old code: "03.03.01",
            MASTER_RESEARCH_SPORT               = 25,                                   // old code: "1-08 80 04",
            MASTER_INNOVATION_TOURISM           = 26,                                   // old code: "1-89 81 02",
            MASTER_INNOVATION_HOSPITALITY       = 27,                                   // old code: "1-89 81 03",
            MASTER_INNOVATION_TECHNOLOGY        = 28,                                   // old code: "1-89 81 04",
            MASTER_INNOVATION_MANAGEMENT        = 29,                                   // old code: "1-89 81 01",      // NOT USE
            MASTER_PHYSICAL_CULTURE_SPORT       = 31,                                   // old code: "1-08 80 04",
            MASTER_RESEARCH_TOURISM             = 32                                    // old code: "1-89 80 01",
        };
    #endif  // ! DELETE_PREVIOUS_VERSION_OF_KOS
    enum KindOfSportCode                                                            // UPDATED. TODO: Delete previous version
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
        #ifdef DATABASE_SUBSTITUTE
            FIGURE_SKATING                              = 31,                           // 31,  -> "Фигурное катание",
        #endif // DATABASE_SUBSTITUTE
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

        #ifndef DELETE_PREVIOUS_VERSION_OF_KOS
            ,
            FIGURE_SKATING_OLD                  = 31,                                   // NEW -> FIGURE_SKATING "Фигурное катание",
            SAMBO_JUDO                          = 34,                                   // DELETE "Самбо-дзюдо",
            FOOTBALL_HOCKEY                     = 36,                                   // DELETE "Футбол и хоккей",
            TABLE_TENNIS_ABITURIENT             = 46,                                   // NEW -> TABLE_TENNIS "Теннис настольный",
            SPORTS_DIRECTING_DEANERY            = 49,                                   // DELETE "Спортивная режиссура",
            #ifndef DATABASE_SUBSTITUTE
                FIGURE_SKATING                      = 84,                                   // NEW -> FIGURE_SKATING_SKATES "Фигурное катание на коньках",
            #endif  // ! DATABASE_SUBSTITUTE
            HAND_TO_HAND_COMBAT_MS              = 92,                                   // NEW -> HAND_TO_HAND_MARTIAL_ARTS "Рукопашный бой (смешанные единоборства)",
            BILLIARDS_RPC                       = 93,                                   // NEW -> BILLIARDS "Бильярд",
            MEDICAL                             = 95,                                   // DELETE "Физическая культура(лечебная)",
            SPORTS_RECREATIONAL_TOURISM_OLD     = 100,                                  // DELETE "Спортивный и рекреационный туризм"
            BILLIARDS_SMA                       = 109,                                  // DELETE "Бильярд",
            HAND_TO_HAND_COMBAT_SMA             = 110,                                  // DELETE "Рукопашный бой (смешанные единоборства)",
            TABLE_TENNIS_DEANERY                = 117                                   // DELETE "Настольный теннис",
        #endif  // ! DELETE_PREVIOUS_VERSION_OF_KOS
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
    enum ProfilingNcrb2022
    {
        IMPROVING_PROF                      = 1,
        HEALTH_PROF                         = 2,
        PRESCHOOLERS_PROF                   = 3,
        ADIAPTIVE_PROF                      = 4,
        DIRECTING_PROF                      = 5,
        PSYCHOLOGY_PROF                     = 6,
        RECRIATIONAL_PROF                   = 7,
        COACHING_PROF                       = 8,
        REHABILITATION_PROF                 = 9,
        ERGOTHERAPY_PROF                    = 10,
        SPORT_PROF                          = 11,
        TOURISM_PROF                        = 12,
        HOSPITALITY_PROF                    = 13
    };
    enum Section2022Code                                                            // INSTEAD OF DirectionNcrb2022Code
    {
        PHYSICAL_CULTURE_2022                       = 0,                            // 1, -> 6-05-1012-01
        COACHING_2022                               = 1,                            // 2, -> 6-05-1012-02
        REHABILITATION_2022                         = 2,                            // 3, -> 6-05-1012-03
        MANAGEMENT_2022                             = 3,                            // 4, -> 6-05-1012-04
        TOURISM_2022                                = 4                             // 5  -> 6-05-1013-01
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
#endif // ! STATE_FROM_WORK_PC


#endif // ENUMS_HPP