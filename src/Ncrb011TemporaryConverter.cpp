#include <vcl.h>
#pragma hdrstop


#include "Ncrb011TemporaryConverter.h"


#pragma package (smart_init)

AnsiString DeleteAfterDatabaseChange::getNcrb2022CodeByNSpecializ (
        int deanerySpesializNSpecializ
    )
{
    return
        getNcrb2022CodeByNSpec (
            getNSpecCodeByNSpesializ (
                deanerySpesializNSpecializ
            )
        );
}
AnsiString DeleteAfterDatabaseChange::getNcrb2022NameSportStrByNSpecializ (
        int deanerySpesializNSpecializ
    )
{
    return
        getDirectionName2022ByNSpecDirNSpecializ (
            getNSpecDirCodeByNSpecializ (
                deanerySpesializNSpecializ
            ),
            deanerySpesializNSpecializ
        );
}
AnsiString DeleteAfterDatabaseChange::getNcrb2022CodeNameSportStrByNSpecializ ( // CHECKED! Works well
        int deanerySpesializNSpecializ
    )
{
    return
        getNcrb2022CodeByNSpec (
            getNSpecCodeByNSpesializ (
                deanerySpesializNSpecializ
            )
        )                                           +
        " «"                                        +
        getDirectionName2022ByNSpecDirNSpecializ (
            getNSpecDirCodeByNSpecializ (
                deanerySpesializNSpecializ
            ),
            deanerySpesializNSpecializ
        )                                           +
        "»";
}
AnsiString DeleteAfterDatabaseChange::getNcrb2022QualificationNameByNSpecializ (
        int deanerySpesializNSpecializ
    )
{
    return
         getNcrb2022QualificationByNSpec (
            getNSpecCodeByNSpesializ (
                deanerySpesializNSpecializ
            )
         );
}
AnsiString DeleteAfterDatabaseChange::getNcrb2022CodeDirectConversionByNSpecializ (
        int deanerySpesializNSpecializ
    )
{
    switch (static_cast <KindOfSportCode> (deanerySpesializNSpecializ))
    {
        case KindOfSportCode::GYMNASTICS:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::MANAGEMENT_SPORTS_TOURISM:                        // OLD! New one is - KindOfSportCode::MANAGEMENT_SPORTS or KindOfSportCode::MANAGEMENT_TOURISM
            return
                NCRB_011::_2022::CODE::MANAGEMENT;
        case KindOfSportCode::PHYSICAL_REHABILITATION:
            return
                NCRB_011::_2022::CODE::REHABILITATION;
        case KindOfSportCode::THERAPEUTIC:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case KindOfSportCode::ORGANIZATION_SPORTS_TOURISM:                      // OLD! New one is - KindOfSportCode::HEALTH_IMPROVING
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION:                     // OLD! New one is - KindOfSportCode::PRESCHOOLERS
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case KindOfSportCode::DANCE_SPORT:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::AEROBICS:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::ROWING_OTHER:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::SWIMMING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::SAILING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::ATHLETICS:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::CROSS_COUNTRY_SKIING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::BULLET_SHOOTING_DEANERY:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::HAND_TO_HAND_COMBAT:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::TAEKWONDO:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::KARATE:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::SKIING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::AUTOMOTIVE_SPORT:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::BASKETBALL:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::BOXING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::GRECO_FREESTYLE_WRESTLING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::CYCLING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::VOLLEYBALL:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::HANDBALL:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::EQUESTRIAN:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::SPEED_SKATING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::TENNIS:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::WEIGHTLIFTING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::FENCING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::FIGURE_SKATING_OLD:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::FOOTBALL:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::HOCKEY:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::SAMBO_JUDO:                                       // OLD! New one is - KindOfSportCode::SAMBO or KindOfSportCode::JUDO
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::WRESTLING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::FOOTBALL_HOCKEY:                                  // OLD! New one is - KindOfSportCode::FOOTBALL or KindOfSportCode::HOCKEY
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::BIATHLON:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::HEALTH_IMPROVING:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case KindOfSportCode::ADAPTIVE:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case KindOfSportCode::FREESTYLE_WRESTLING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::SAMBO:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::JUDO:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::TABLE_TENNIS_ABITURIENT:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::ERGOTHERAPY:
            return
                NCRB_011::_2022::CODE::REHABILITATION;
        case KindOfSportCode::MANAGEMENT_SPORTS:
            return
                NCRB_011::_2022::CODE::MANAGEMENT;
        case KindOfSportCode::SPORTS_DIRECTING_DEANERY:                         // OLD! New one is - KindOfSportCode::SPORTS_DIRECTING
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case KindOfSportCode::MANAGEMENT_TOURISM:
            return
                NCRB_011::_2022::CODE::MANAGEMENT;
        case KindOfSportCode::SPORTS_PSYCHOLOGY:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case KindOfSportCode::BILLIARD_SPORTS:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::ACROBATICS:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::ORIENTEERING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::SPORTS_DIRECTING:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case KindOfSportCode::PRESCHOOLERS:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case KindOfSportCode::MOUNTAINEERING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::SKI_COMBINED:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::TOURISM_HOSPITALITY:
            return
                NCRB_011::_2022::CODE::TOURISM;
        case KindOfSportCode::WATER_TECHNICAL_SPORTS:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::MODEL_TECHNICAL_SPORTS:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::ALPINE_SKIING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::BASEBALL:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::WUSHU:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::CHESS:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::THAI_BOXING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::TOURISM_PROMOTION:                                // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::TOURISM;
        case KindOfSportCode::TOURISM_IT:                                       // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::TOURISM;
        case KindOfSportCode::TOURISM_LOGISTICS:                                // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::TOURISM;
        case KindOfSportCode::TOURISM_SOCIAL:                                   // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::TOURISM;
        case KindOfSportCode::TOURISM_TRANSPORT:                                // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::TOURISM;
        case KindOfSportCode::TOURISM_FOOD:                                     // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::TOURISM;
        case KindOfSportCode::TOURIST_ACCOMMODATION:                            // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::TOURISM;
        case KindOfSportCode::TOURISM_EXCURSION:                                // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::TOURISM;
        case KindOfSportCode::TOURISM_HEALTH:                                   // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::TOURISM;
        case KindOfSportCode::BULLET_SHOOTING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::FIELD_HOCKEY:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::FIGURE_SKATING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::ACADEMIC_ROWING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::HAND_TO_HAND_COMBAT_MS:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::BILLIARDS_RPC:                                    // OLD! New one is - KindOfSportCode::BILLIARDS_SMA
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::MEDICAL:                                          // OLD! New one is - KindOfSportCode::THERAPEUTIC
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM_OLD:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case KindOfSportCode::SCIENCE_HEALTH:                                   // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::THEORY_IMPROVING;
        case KindOfSportCode::PHYSIOLOGY:                                       // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::PHYSIOLOGY;
        case KindOfSportCode::SCIENCE_THEORY:                                   // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::THEORY_IMPROVING;
        case KindOfSportCode::RECEARCH_SPORT:                                   // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::PC_MASTER_DEGREE;
        case KindOfSportCode::INNOVATIVE_TOURISM:                               // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::INNO_TOURISM;
        case KindOfSportCode::INNOVATIVE_HOSPITALITY:                           // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::INNO_HOSPITALITY;
        case KindOfSportCode::INNOVATIVE_TECHNOLOGIES:                          // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::INNO_TECHNOLOGY;
        case KindOfSportCode::INNOVATIVE_MANAGEMENT:                            // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::INNO_MANAGEMENT;
        case KindOfSportCode::BILLIARDS_SMA:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::HAND_TO_HAND_COMBAT_SMA:                          // OLD! New one is - KindOfSportCode::HAND_TO_HAND_COMBAT_MS
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::BADMINTON:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::TABLE_TENNIS_DEANERY:                             // OLD! New one is - KindOfSportCode::TABLE_TENNIS_ABITURIENT
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::PHYSICAL_CULTURE_SPORT:                           // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::INNO_MANAGEMENT;
        case KindOfSportCode::TOURISM_HOSPITALITY_MASTER:                       // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::PC_MASTER_DEGREE;
        case KindOfSportCode::SPORT_CLIMBING:
            return
                NCRB_011::_2022::CODE::COACHING;
        case KindOfSportCode::MASTER_ANTHROPOLOGY:                              // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::TH_MASTER_DEGREE;
        case KindOfSportCode::MASTER_MANAGEMENT:                                // MASTER'S DEGREE
            return
                NCRB_011::_2022::CODE::MNG_MASTER_DEGREE;

        default:
            ShowMessage (
                "ERROR:\n"                                              \
                "The getNcrb2022CodeByNSpecializ "                      \
                "(int deanerySpesializNSpecializ) method returns:\n"    \
                "Value: "                                               +
                    AnsiString (deanerySpesializNSpecializ)             +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deanerySpesializNSpecializ
                );
    }
}

AnsiString DeleteAfterDatabaseChange::getQualification2009 (
        int deaneryQualificationNomerQu
    )
{
    switch (    static_cast <DeaneryQualificationNameByNomerQu>
                (
                    deaneryQualificationNomerQu
                )
           )
    {
        case DeaneryQualificationNameByNomerQu::TEACHER_PHYSICAL_CULTURE_SPORTS:
            return
                DeaneryDB::QUALIFICATION::TEACHER_PHYSICAL_CULTURE_SPORTS;      // "Преподаватель физической культуры и спорта"
        case DeaneryQualificationNameByNomerQu::COACHING_BY_SPORT:
            return
                DeaneryDB::QUALIFICATION::COACHING_BY_SPORT;                    // "Тренер по виду спорта"
        case DeaneryQualificationNameByNomerQu::PHYSICAL_EDUCATION_TEACHER:
            return
                DeaneryDB::QUALIFICATION::PHYSICAL_EDUCATION_TEACHER;           // "Учитель физической культуры"
        case DeaneryQualificationNameByNomerQu::TEACHER_ORGANIZER_HEALTH_TOURISM:
            return
                DeaneryDB::QUALIFICATION::TEACHER_ORGANIZER_HEALTH_TOURISM;     // "Педагог-организатор физкультурно-оздоровительной работы и туризма"
        case DeaneryQualificationNameByNomerQu::TEACHER_ORGANIZER_PRESCHOOLERS:
            return
                DeaneryDB::QUALIFICATION::TEACHER_ORGANIZER_PRESCHOOLERS;       // "Педагог-организатор физического воспитания в дошкольных учреждениях"
        case DeaneryQualificationNameByNomerQu::MANAGER_SPORT_TOURISM:
            return
                DeaneryDB::QUALIFICATION::MANAGER_SPORT_TOURISM;                // "Менеджер спорта и туризма"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_REHABILITATION:
            return
                DeaneryDB::QUALIFICATION::INSTRUCTOR_REHABILITATION;            // "Инструктор-методист физической реабилитации"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_MEDICAL:
            return
                DeaneryDB::QUALIFICATION::INSTRUCTOR_MEDICAL;                   // "Инструктор-методист лечебной физической культуры"
        case DeaneryQualificationNameByNomerQu::TEACHER_PHYSICAL_CULTURE:
            return
                DeaneryDB::QUALIFICATION::TEACHER_PHYSICAL_CULTURE;             // "Преподаватель физической культуры"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_BY_HEALTH:
            return
                DeaneryDB::QUALIFICATION::INSTRUCTOR_BY_HEALTH;                 // "Инструктор-методист по оздоровительной физической культуре"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_BY_ADAPTIVE:
            return
                DeaneryDB::QUALIFICATION::INSTRUCTOR_BY_ADAPTIVE;               // "Инструктор-методист по адаптивной физической культуре"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_PRESCHOOLERS:
            return
                DeaneryDB::QUALIFICATION::INSTRUCTOR_PRESCHOOLERS;              // "Инструктор-методист физического воспитания в дошкольных учреждениях"
        case DeaneryQualificationNameByNomerQu::PSYCHOLOGIST:
            return
                DeaneryDB::QUALIFICATION::PSYCHOLOGIST;                         // "Психолог"
        case DeaneryQualificationNameByNomerQu::MANAGER_SPORT:
            return
                DeaneryDB::QUALIFICATION::MANAGER_SPORT;                        // "Менеджер в спорте"
        case DeaneryQualificationNameByNomerQu::MANAGER_TUORISM:
            return
                DeaneryDB::QUALIFICATION::MANAGER_TUORISM;                      // "Менеджер по туризму"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_RECREATIONAL:
            return
                DeaneryDB::QUALIFICATION::INSTRUCTOR_RECREATIONAL;              // "Инструктор-методист по туризму"
        case DeaneryQualificationNameByNomerQu::MANAGER_DIRECTING:
            return
                DeaneryDB::QUALIFICATION::MANAGER_DIRECTING;                    // "Менеджер-режиссер спортивно-массовых мероприятий"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_BY_MEDICAL:
            return
                DeaneryDB::QUALIFICATION::INSTRUCTOR_BY_MEDICAL;                // "Инструктор-методист по лечебной физической культуре"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_BY_REHABILITATION:
            return
                DeaneryDB::QUALIFICATION::INSTRUCTOR_BY_REHABILITATION;         // "Инструктор-методист по физической реабилитации"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_BY_ERGOTHERAPY:
            return
                DeaneryDB::QUALIFICATION::INSTRUCTOR_BY_ERGOTHERAPY;            // "Инструктор-методист по эрготерапии"
        case DeaneryQualificationNameByNomerQu::SPECIALIST_TOURISM_HOSPITALITY:
            return
                DeaneryDB::QUALIFICATION::SPECIALIST_TOURISM_HOSPITALITY;       // "Специалист в сфере туризма и гостеприимства"

        default:
            ShowMessage (
                "ERROR:\n"                                              \
                "The getPreviousQualification "                         \
                "(int deaneryQualificationNomerQu) method returns:\n"   \
                "Value: "                                               +
                    AnsiString (deaneryQualificationNomerQu)            +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deaneryQualificationNomerQu
                );
    }
}
AnsiString DeleteAfterDatabaseChange::getQualification2022 (
        int deaneryQualificationNomerQu
    )
{
    switch (    static_cast <DeaneryQualificationNameByNomerQu>
                (
                    deaneryQualificationNomerQu
                )
           )
    {
        case DeaneryQualificationNameByNomerQu::TEACHER_PHYSICAL_CULTURE_SPORTS:       // "Преподаватель физической культуры и спорта"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::COACHING_BY_SPORT:                     // "Тренер по виду спорта"
            return
                NCRB_011::_2022::QUALIFICATION::COACHING;                       // "Тренер. Преподаватель"
        case DeaneryQualificationNameByNomerQu::PHYSICAL_EDUCATION_TEACHER:            // "Учитель физической культуры"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::TEACHER_ORGANIZER_HEALTH_TOURISM:      // "Педагог-организатор физкультурно-оздоровительной работы и туризма"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::TEACHER_ORGANIZER_PRESCHOOLERS:        // "Педагог-организатор физического воспитания в дошкольных учреждениях"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::MANAGER_SPORT_TOURISM:                 // "Менеджер спорта и туризма"
            return
                NCRB_011::_2022::QUALIFICATION::MANAGEMENT;                     // "Менеджер. Преподаватель"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_REHABILITATION:             // "Инструктор-методист физической реабилитации"
            return
                NCRB_011::_2022::QUALIFICATION::REHABILITATION;                 // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_MEDICAL:                    // "Инструктор-методист лечебной физической культуры"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::TEACHER_PHYSICAL_CULTURE:              // "Преподаватель физической культуры"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_BY_HEALTH:                  // "Инструктор-методист по оздоровительной физической культуре"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_BY_ADAPTIVE:                // "Инструктор-методист по адаптивной физической культуре"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_PRESCHOOLERS:               // "Инструктор-методист физического воспитания в дошкольных учреждениях"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::PSYCHOLOGIST:                          // "Психолог"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::MANAGER_SPORT:                         // "Менеджер в спорте"
            return
                NCRB_011::_2022::QUALIFICATION::MANAGEMENT;                     // "Менеджер. Преподаватель"
        case DeaneryQualificationNameByNomerQu::MANAGER_TUORISM:                       // "Менеджер по туризму"
            return
                NCRB_011::_2022::QUALIFICATION::MANAGEMENT;                     // "Менеджер. Преподаватель"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_RECREATIONAL:               // "Инструктор-методист по туризму"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::MANAGER_DIRECTING:                     // "Менеджер-режиссер спортивно-массовых мероприятий"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_BY_MEDICAL:                 // "Инструктор-методист по лечебной физической культуре"
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;               // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_BY_REHABILITATION:          // "Инструктор-методист по физической реабилитации"
            return
                NCRB_011::_2022::QUALIFICATION::REHABILITATION;                 // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::INSTRUCTOR_BY_ERGOTHERAPY:             // "Инструктор-методист по эрготерапии"
            return
                NCRB_011::_2022::QUALIFICATION::REHABILITATION;                 // "Инструктор-методист. Преподаватель"
        case DeaneryQualificationNameByNomerQu::SPECIALIST_TOURISM_HOSPITALITY:        // "Специалист в сфере туризма и гостеприимства"
            return
                NCRB_011::_2022::QUALIFICATION::TOURISM;                        // "Специалист"

        default:
            ShowMessage (
                "ERROR:\n"                                              \
                "The get2022Qualification "                             \
                "(int deaneryQualificationNomerQu) method returns:\n"   \
                "Value: "                                               +
                    AnsiString (deaneryQualificationNomerQu)            +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deaneryQualificationNomerQu
                );
    }
}


AnsiString DeleteAfterDatabaseChange::getKindOfSportNameByNSpecializ (
        int deanerySpesializNSpecializ
    )
{
    switch (static_cast <KindOfSportCode> (deanerySpesializNSpecializ))
    {
        case KindOfSportCode::GYMNASTICS:
            return
                KindOfSport::GYMNASTICS;
        case KindOfSportCode::MANAGEMENT_SPORTS_TOURISM:
            return
                KindOfSport::MANAGEMENT_SPORTS_TOURISM;
        case KindOfSportCode::PHYSICAL_REHABILITATION:
            return
                KindOfSport::PHYSICAL_REHABILITATION;
        case KindOfSportCode::THERAPEUTIC:
            return
                KindOfSport::THERAPEUTIC;
        case KindOfSportCode::ORGANIZATION_SPORTS_TOURISM:
            return
                KindOfSport::ORGANIZATION_SPORTS_TOURISM;
        case KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION:
            return
                KindOfSport::PRESCHOOL_PHYSICAL_EDUCATION;
        case KindOfSportCode::DANCE_SPORT:
            return
                KindOfSport::DANCE_SPORT;
        case KindOfSportCode::AEROBICS:
            return
                KindOfSport::AEROBICS;
        case KindOfSportCode::ROWING_OTHER:
            return
                KindOfSport::ROWING_OTHER;
        case KindOfSportCode::SWIMMING:
            return
                KindOfSport::SWIMMING;
        case KindOfSportCode::SAILING:
            return
                KindOfSport::SAILING;
        case KindOfSportCode::ATHLETICS:
            return
                KindOfSport::ATHLETICS;
        case KindOfSportCode::CROSS_COUNTRY_SKIING:
            return
                KindOfSport::CROSS_COUNTRY_SKIING;
        case KindOfSportCode::BULLET_SHOOTING_DEANERY:
            return
                KindOfSport::BULLET_SHOOTING_DEANERY;
        case KindOfSportCode::HAND_TO_HAND_COMBAT:
            return
                KindOfSport::HAND_TO_HAND_COMBAT;
        case KindOfSportCode::TAEKWONDO:
            return
                KindOfSport::TAEKWONDO;
        case KindOfSportCode::KARATE:
            return
                KindOfSport::KARATE;
        case KindOfSportCode::SKIING:
            return
                KindOfSport::SKIING;
        case KindOfSportCode::AUTOMOTIVE_SPORT:
            return
                KindOfSport::AUTOMOTIVE_SPORT;
        case KindOfSportCode::BASKETBALL:
            return
                KindOfSport::BASKETBALL;
        case KindOfSportCode::BOXING:
            return
                KindOfSport::BOXING;
        case KindOfSportCode::GRECO_FREESTYLE_WRESTLING:
            return
                KindOfSport::GRECO_FREESTYLE_WRESTLING;
        case KindOfSportCode::CYCLING:
            return
                KindOfSport::CYCLING;
        case KindOfSportCode::VOLLEYBALL:
            return
                KindOfSport::VOLLEYBALL;
        case KindOfSportCode::HANDBALL:
            return
                KindOfSport::HANDBALL;
        case KindOfSportCode::EQUESTRIAN:
            return
                KindOfSport::EQUESTRIAN;
        case KindOfSportCode::SPEED_SKATING:
            return
                KindOfSport::SPEED_SKATING;
        case KindOfSportCode::TENNIS:
            return
                KindOfSport::TENNIS;
        case KindOfSportCode::WEIGHTLIFTING:
            return
                KindOfSport::WEIGHTLIFTING;
        case KindOfSportCode::FENCING:
            return
                KindOfSport::FENCING;
        case KindOfSportCode::FIGURE_SKATING_OLD:
            return
                KindOfSport::FIGURE_SKATING_OLD;
        case KindOfSportCode::FOOTBALL:
            return
                KindOfSport::FOOTBALL;
        case KindOfSportCode::HOCKEY:
            return
                KindOfSport::HOCKEY;
        case KindOfSportCode::SAMBO_JUDO:
            return
                KindOfSport::SAMBO_JUDO;
        case KindOfSportCode::WRESTLING:
            return
                KindOfSport::WRESTLING;
        case KindOfSportCode::FOOTBALL_HOCKEY:
            return
                KindOfSport::FOOTBALL_HOCKEY;
        case KindOfSportCode::BIATHLON:
            return
                KindOfSport::BIATHLON;
        case KindOfSportCode::HEALTH_IMPROVING:
            return
                KindOfSport::HEALTH_IMPROVING;
        case KindOfSportCode::ADAPTIVE:
            return
                KindOfSport::ADAPTIVE;
        case KindOfSportCode::FREESTYLE_WRESTLING:
            return
                KindOfSport::FREESTYLE_WRESTLING;
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:
            return
                KindOfSport::GRECO_ROMAN_WRESTLING;
        case KindOfSportCode::SAMBO:
            return
                KindOfSport::SAMBO;
        case KindOfSportCode::JUDO:
            return
                KindOfSport::JUDO;
        case KindOfSportCode::TABLE_TENNIS_ABITURIENT:
            return
                KindOfSport::TABLE_TENNIS_ABITURIENT;
        case KindOfSportCode::ERGOTHERAPY:
            return
                KindOfSport::ERGOTHERAPY;
        case KindOfSportCode::MANAGEMENT_SPORTS:
            return
                KindOfSport::MANAGEMENT_SPORTS;
        case KindOfSportCode::SPORTS_DIRECTING_DEANERY:
            return
                KindOfSport::SPORTS_DIRECTING_DEANERY;
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM:
            return
                KindOfSport::SPORTS_RECREATIONAL_TOURISM;
        case KindOfSportCode::MANAGEMENT_TOURISM:
            return
                KindOfSport::MANAGEMENT_TOURISM;
        case KindOfSportCode::SPORTS_PSYCHOLOGY:
            return
                KindOfSport::SPORTS_PSYCHOLOGY;
        case KindOfSportCode::BILLIARD_SPORTS:
            return
                KindOfSport::BILLIARD_SPORTS;
        case KindOfSportCode::ACROBATICS:
            return
                KindOfSport::ACROBATICS;
        case KindOfSportCode::ORIENTEERING:
            return
                KindOfSport::ORIENTEERING;
        case KindOfSportCode::SPORTS_DIRECTING:
            return
                KindOfSport::SPORTS_DIRECTING;
        case KindOfSportCode::PRESCHOOLERS:
            return
                KindOfSport::PRESCHOOLERS;
        case KindOfSportCode::MOUNTAINEERING:
            return
                KindOfSport::MOUNTAINEERING;
        case KindOfSportCode::SKI_COMBINED:
            return
                KindOfSport::SKI_COMBINED;
        case KindOfSportCode::TOURISM_HOSPITALITY:
            return
                KindOfSport::TOURISM_HOSPITALITY;
        case KindOfSportCode::WATER_TECHNICAL_SPORTS:
            return
                KindOfSport::WATER_TECHNICAL_SPORTS;
        case KindOfSportCode::MODEL_TECHNICAL_SPORTS:
            return
                KindOfSport::MODEL_TECHNICAL_SPORTS;
        case KindOfSportCode::ALPINE_SKIING:
            return
                KindOfSport::ALPINE_SKIING;
        case KindOfSportCode::BASEBALL:
            return
                KindOfSport::BASEBALL;
        case KindOfSportCode::WUSHU:
            return
                KindOfSport::WUSHU;
        case KindOfSportCode::CHESS:
            return
                KindOfSport::CHESS;
        case KindOfSportCode::THAI_BOXING:
            return
                KindOfSport::THAI_BOXING;
        case KindOfSportCode::TOURISM_PROMOTION:
            return
                KindOfSport::TOURISM_PROMOTION;
        case KindOfSportCode::TOURISM_IT:
            return
                KindOfSport::TOURISM_IT;
        case KindOfSportCode::TOURISM_LOGISTICS:
            return
                KindOfSport::TOURISM_LOGISTICS;
        case KindOfSportCode::TOURISM_SOCIAL:
            return
                KindOfSport::TOURISM_SOCIAL;
        case KindOfSportCode::TOURISM_TRANSPORT:
            return
                KindOfSport::TOURISM_TRANSPORT;
        case KindOfSportCode::TOURISM_FOOD:
            return
                KindOfSport::TOURISM_FOOD;
        case KindOfSportCode::TOURIST_ACCOMMODATION:
            return
                KindOfSport::TOURIST_ACCOMMODATION;
        case KindOfSportCode::TOURISM_EXCURSION:
            return
                KindOfSport::TOURISM_EXCURSION;
        case KindOfSportCode::TOURISM_HEALTH:
            return
                KindOfSport::TOURISM_HEALTH;
        case KindOfSportCode::BULLET_SHOOTING:
            return
                KindOfSport::BULLET_SHOOTING;
        case KindOfSportCode::FIELD_HOCKEY:
            return
                KindOfSport::FIELD_HOCKEY;
        case KindOfSportCode::FIGURE_SKATING:
            return
                KindOfSport::FIGURE_SKATING;
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                KindOfSport::ROWING_AND_CANOEING;
        case KindOfSportCode::ACADEMIC_ROWING:
            return
                KindOfSport::ACADEMIC_ROWING;
        case KindOfSportCode::HAND_TO_HAND_COMBAT_MS:
            return
                KindOfSport::HAND_TO_HAND_COMBAT_MS;
        case KindOfSportCode::BILLIARDS_RPC:
            return
                KindOfSport::BILLIARDS_RPC;
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                KindOfSport::WITHOUT_SPECIALIZATION;
        case KindOfSportCode::MEDICAL:
            return
                KindOfSport::MEDICAL;
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                KindOfSport::MODERN_PENTATHLON;
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM_OLD:
            return
                KindOfSport::SPORTS_RECREATIONAL_TOURISM;
        case KindOfSportCode::SCIENCE_HEALTH:
            return
                KindOfSport::SCIENCE_HEALTH;
        case KindOfSportCode::PHYSIOLOGY:
            return
                KindOfSport::PHYSIOLOGY;
        case KindOfSportCode::SCIENCE_THEORY:
            return
                KindOfSport::SCIENCE_THEORY;
        case KindOfSportCode::RECEARCH_SPORT:
            return
                KindOfSport::RECEARCH_SPORT;
        case KindOfSportCode::INNOVATIVE_TOURISM:
            return
                KindOfSport::INNOVATIVE_TOURISM;
        case KindOfSportCode::INNOVATIVE_HOSPITALITY:
            return
                KindOfSport::INNOVATIVE_HOSPITALITY;
        case KindOfSportCode::INNOVATIVE_TECHNOLOGIES:
            return
                KindOfSport::INNOVATIVE_TECHNOLOGIES;
        case KindOfSportCode::INNOVATIVE_MANAGEMENT:
            return
                KindOfSport::INNOVATIVE_MANAGEMENT;
        case KindOfSportCode::BILLIARDS_SMA:
            return
                KindOfSport::BILLIARDS_SMA;
        case KindOfSportCode::HAND_TO_HAND_COMBAT_SMA:
            return
                KindOfSport::HAND_TO_HAND_COMBAT_SMA;
        case KindOfSportCode::BADMINTON:
            return
                KindOfSport::BADMINTON;
        case KindOfSportCode::TABLE_TENNIS_DEANERY:
            return
                KindOfSport::TABLE_TENNIS_DEANERY;
        case KindOfSportCode::PHYSICAL_CULTURE_SPORT:
            return
                KindOfSport::PHYSICAL_CULTURE_SPORT;
        case KindOfSportCode::TOURISM_HOSPITALITY_MASTER:
            return
                KindOfSport::TOURISM_HOSPITALITY_MASTER;
        case KindOfSportCode::SPORT_CLIMBING:
            return
                KindOfSport::SPORT_CLIMBING;
        case KindOfSportCode::MASTER_ANTHROPOLOGY:
            return
                KindOfSport::MASTER_ANTHROPOLOGY;
        case KindOfSportCode::MASTER_MANAGEMENT:
            return
                KindOfSport::MASTER_MANAGEMENT;


        default:
            ShowMessage (
                "ERROR:\n"                                              \
                "The getKindOfSportNameByNSpecializ "                   \
                "(int deanerySpesializNSpecializ) method returns:\n"    \
                "Value: "                                               +
                    AnsiString (deanerySpesializNSpecializ)             +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deanerySpesializNSpecializ
                );
    }
}
AnsiString DeleteAfterDatabaseChange::getKindOfSportNameDativeCaseByNSpecializ (
        int deanerySpesializNSpecializ
    )
{
    switch (static_cast <KindOfSportCode> (deanerySpesializNSpecializ))
    {
        case KindOfSportCode::GYMNASTICS:
            return
                KindOfSport::DATIVE_CASE::GYMNASTICS;
        case KindOfSportCode::MANAGEMENT_SPORTS_TOURISM:
            return
                KindOfSport::DATIVE_CASE::MANAGEMENT_SPORTS_TOURISM;
        case KindOfSportCode::PHYSICAL_REHABILITATION:
            return
                KindOfSport::DATIVE_CASE::PHYSICAL_REHABILITATION;
        case KindOfSportCode::THERAPEUTIC:
            return
                KindOfSport::DATIVE_CASE::THERAPEUTIC;
        case KindOfSportCode::ORGANIZATION_SPORTS_TOURISM:
            return
                KindOfSport::DATIVE_CASE::ORGANIZATION_SPORTS_TOURISM;
        case KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION:
            return
                KindOfSport::DATIVE_CASE::PRESCHOOL_PHYSICAL_EDUCATION;
        case KindOfSportCode::DANCE_SPORT:
            return
                KindOfSport::DATIVE_CASE::DANCE_SPORT;
        case KindOfSportCode::AEROBICS:
            return
                KindOfSport::DATIVE_CASE::AEROBICS;
        case KindOfSportCode::ROWING_OTHER:
            return
                KindOfSport::DATIVE_CASE::ROWING_OTHER;
        case KindOfSportCode::SWIMMING:
            return
                KindOfSport::DATIVE_CASE::SWIMMING;
        case KindOfSportCode::SAILING:
            return
                KindOfSport::DATIVE_CASE::SAILING;
        case KindOfSportCode::ATHLETICS:
            return
                KindOfSport::DATIVE_CASE::ATHLETICS;
        case KindOfSportCode::CROSS_COUNTRY_SKIING:
            return
                KindOfSport::DATIVE_CASE::CROSS_COUNTRY_SKIING;
        case KindOfSportCode::BULLET_SHOOTING_DEANERY:
            return
                KindOfSport::DATIVE_CASE::BULLET_SHOOTING_DEANERY;
        case KindOfSportCode::HAND_TO_HAND_COMBAT:
            return
                KindOfSport::DATIVE_CASE::HAND_TO_HAND_COMBAT;
        case KindOfSportCode::TAEKWONDO:
            return
                KindOfSport::DATIVE_CASE::TAEKWONDO;
        case KindOfSportCode::KARATE:
            return
                KindOfSport::DATIVE_CASE::KARATE;
        case KindOfSportCode::SKIING:
            return
                KindOfSport::DATIVE_CASE::SKIING;
        case KindOfSportCode::AUTOMOTIVE_SPORT:
            return
                KindOfSport::DATIVE_CASE::AUTOMOTIVE_SPORT;
        case KindOfSportCode::BASKETBALL:
            return
                KindOfSport::DATIVE_CASE::BASKETBALL;
        case KindOfSportCode::BOXING:
            return
                KindOfSport::DATIVE_CASE::BOXING;
        case KindOfSportCode::GRECO_FREESTYLE_WRESTLING:
            return
                KindOfSport::DATIVE_CASE::GRECO_FREESTYLE_WRESTLING;
        case KindOfSportCode::CYCLING:
            return
                KindOfSport::DATIVE_CASE::CYCLING;
        case KindOfSportCode::VOLLEYBALL:
            return
                KindOfSport::DATIVE_CASE::VOLLEYBALL;
        case KindOfSportCode::HANDBALL:
            return
                KindOfSport::DATIVE_CASE::HANDBALL;
        case KindOfSportCode::EQUESTRIAN:
            return
                KindOfSport::DATIVE_CASE::EQUESTRIAN;
        case KindOfSportCode::SPEED_SKATING:
            return
                KindOfSport::DATIVE_CASE::SPEED_SKATING;
        case KindOfSportCode::TENNIS:
            return
                KindOfSport::DATIVE_CASE::TENNIS;
        case KindOfSportCode::WEIGHTLIFTING:
            return
                KindOfSport::DATIVE_CASE::WEIGHTLIFTING;
        case KindOfSportCode::FENCING:
            return
                KindOfSport::DATIVE_CASE::FENCING;
        case KindOfSportCode::FIGURE_SKATING_OLD:
            return
                KindOfSport::DATIVE_CASE::FIGURE_SKATING_OLD;
        case KindOfSportCode::FOOTBALL:
            return
                KindOfSport::DATIVE_CASE::FOOTBALL;
        case KindOfSportCode::HOCKEY:
            return
                KindOfSport::DATIVE_CASE::HOCKEY;
        case KindOfSportCode::SAMBO_JUDO:
            return
                KindOfSport::DATIVE_CASE::SAMBO_JUDO;
        case KindOfSportCode::WRESTLING:
            return
                KindOfSport::DATIVE_CASE::WRESTLING;
        case KindOfSportCode::FOOTBALL_HOCKEY:
            return
                KindOfSport::DATIVE_CASE::FOOTBALL_HOCKEY;
        case KindOfSportCode::BIATHLON:
            return
                KindOfSport::DATIVE_CASE::BIATHLON;
        case KindOfSportCode::HEALTH_IMPROVING:
            return
                KindOfSport::DATIVE_CASE::HEALTH_IMPROVING;
        case KindOfSportCode::ADAPTIVE:
            return
                KindOfSport::DATIVE_CASE::ADAPTIVE;
        case KindOfSportCode::FREESTYLE_WRESTLING:
            return
                KindOfSport::DATIVE_CASE::FREESTYLE_WRESTLING;
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:
            return
                KindOfSport::DATIVE_CASE::GRECO_ROMAN_WRESTLING;
        case KindOfSportCode::SAMBO:
            return
                KindOfSport::DATIVE_CASE::SAMBO;
        case KindOfSportCode::JUDO:
            return
                KindOfSport::DATIVE_CASE::JUDO;
        case KindOfSportCode::TABLE_TENNIS_ABITURIENT:
            return
                KindOfSport::DATIVE_CASE::TABLE_TENNIS_ABITURIENT;
        case KindOfSportCode::ERGOTHERAPY:
            return
                KindOfSport::DATIVE_CASE::ERGOTHERAPY;
        case KindOfSportCode::MANAGEMENT_SPORTS:
            return
                KindOfSport::DATIVE_CASE::MANAGEMENT_SPORTS;
        case KindOfSportCode::SPORTS_DIRECTING_DEANERY:
            return
                KindOfSport::DATIVE_CASE::SPORTS_DIRECTING_DEANERY;
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM:
            return
                KindOfSport::DATIVE_CASE::SPORTS_RECREATIONAL_TOURISM;
        case KindOfSportCode::MANAGEMENT_TOURISM:
            return
                KindOfSport::DATIVE_CASE::MANAGEMENT_TOURISM;
        case KindOfSportCode::SPORTS_PSYCHOLOGY:
            return
                KindOfSport::DATIVE_CASE::SPORTS_PSYCHOLOGY;
        case KindOfSportCode::BILLIARD_SPORTS:
            return
                KindOfSport::DATIVE_CASE::BILLIARD_SPORTS;
        case KindOfSportCode::ACROBATICS:
            return
                KindOfSport::DATIVE_CASE::ACROBATICS;
        case KindOfSportCode::ORIENTEERING:
            return
                KindOfSport::DATIVE_CASE::ORIENTEERING;
        case KindOfSportCode::SPORTS_DIRECTING:
            return
                KindOfSport::DATIVE_CASE::SPORTS_DIRECTING;
        case KindOfSportCode::PRESCHOOLERS:
            return
                KindOfSport::DATIVE_CASE::PRESCHOOLERS;
        case KindOfSportCode::MOUNTAINEERING:
            return
                KindOfSport::DATIVE_CASE::MOUNTAINEERING;
        case KindOfSportCode::SKI_COMBINED:
            return
                KindOfSport::DATIVE_CASE::SKI_COMBINED;
        case KindOfSportCode::TOURISM_HOSPITALITY:
            return
                KindOfSport::DATIVE_CASE::TOURISM_HOSPITALITY;
        case KindOfSportCode::WATER_TECHNICAL_SPORTS:
            return
                KindOfSport::DATIVE_CASE::WATER_TECHNICAL_SPORTS;
        case KindOfSportCode::MODEL_TECHNICAL_SPORTS:
            return
                KindOfSport::DATIVE_CASE::MODEL_TECHNICAL_SPORTS;
        case KindOfSportCode::ALPINE_SKIING:
            return
                KindOfSport::DATIVE_CASE::ALPINE_SKIING;
        case KindOfSportCode::BASEBALL:
            return
                KindOfSport::DATIVE_CASE::BASEBALL;
        case KindOfSportCode::WUSHU:
            return
                KindOfSport::DATIVE_CASE::WUSHU;
        case KindOfSportCode::CHESS:
            return
                KindOfSport::DATIVE_CASE::CHESS;
        case KindOfSportCode::THAI_BOXING:
            return
                KindOfSport::DATIVE_CASE::THAI_BOXING;
        case KindOfSportCode::TOURISM_PROMOTION:
            return
                KindOfSport::DATIVE_CASE::TOURISM_PROMOTION;
        case KindOfSportCode::TOURISM_IT:
            return
                KindOfSport::DATIVE_CASE::TOURISM_IT;
        case KindOfSportCode::TOURISM_LOGISTICS:
            return
                KindOfSport::DATIVE_CASE::TOURISM_LOGISTICS;
        case KindOfSportCode::TOURISM_SOCIAL:
            return
                KindOfSport::DATIVE_CASE::TOURISM_SOCIAL;
        case KindOfSportCode::TOURISM_TRANSPORT:
            return
                KindOfSport::DATIVE_CASE::TOURISM_TRANSPORT;
        case KindOfSportCode::TOURISM_FOOD:
            return
                KindOfSport::DATIVE_CASE::TOURISM_FOOD;
        case KindOfSportCode::TOURIST_ACCOMMODATION:
            return
                KindOfSport::DATIVE_CASE::TOURIST_ACCOMMODATION;
        case KindOfSportCode::TOURISM_EXCURSION:
            return
                KindOfSport::DATIVE_CASE::TOURISM_EXCURSION;
        case KindOfSportCode::TOURISM_HEALTH:
            return
                KindOfSport::DATIVE_CASE::TOURISM_HEALTH;
        case KindOfSportCode::BULLET_SHOOTING:
            return
                KindOfSport::DATIVE_CASE::BULLET_SHOOTING;
        case KindOfSportCode::FIELD_HOCKEY:
            return
                KindOfSport::DATIVE_CASE::FIELD_HOCKEY;
        case KindOfSportCode::FIGURE_SKATING:
            return
                KindOfSport::DATIVE_CASE::FIGURE_SKATING;
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                KindOfSport::DATIVE_CASE::ROWING_AND_CANOEING;
        case KindOfSportCode::ACADEMIC_ROWING:
            return
                KindOfSport::DATIVE_CASE::ACADEMIC_ROWING;
        case KindOfSportCode::HAND_TO_HAND_COMBAT_MS:
            return
                KindOfSport::DATIVE_CASE::HAND_TO_HAND_COMBAT_MS;
        case KindOfSportCode::BILLIARDS_RPC:
            return
                KindOfSport::DATIVE_CASE::BILLIARDS_RPC;
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                KindOfSport::DATIVE_CASE::WITHOUT_SPECIALIZATION;
        case KindOfSportCode::MEDICAL:
            return
                KindOfSport::DATIVE_CASE::MEDICAL;
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                KindOfSport::DATIVE_CASE::MODERN_PENTATHLON;
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM_OLD:
            return
                KindOfSport::DATIVE_CASE::SPORTS_RECREATIONAL_TOURISM;
        case KindOfSportCode::SCIENCE_HEALTH:
            return
                KindOfSport::DATIVE_CASE::SCIENCE_HEALTH;
        case KindOfSportCode::PHYSIOLOGY:
            return
                KindOfSport::DATIVE_CASE::PHYSIOLOGY;
        case KindOfSportCode::SCIENCE_THEORY:
            return
                KindOfSport::DATIVE_CASE::SCIENCE_THEORY;
        case KindOfSportCode::RECEARCH_SPORT:
            return
                KindOfSport::DATIVE_CASE::RECEARCH_SPORT;
        case KindOfSportCode::INNOVATIVE_TOURISM:
            return
                KindOfSport::DATIVE_CASE::INNOVATIVE_TOURISM;
        case KindOfSportCode::INNOVATIVE_HOSPITALITY:
            return
                KindOfSport::DATIVE_CASE::INNOVATIVE_HOSPITALITY;
        case KindOfSportCode::INNOVATIVE_TECHNOLOGIES:
            return
                KindOfSport::DATIVE_CASE::INNOVATIVE_TECHNOLOGIES;
        case KindOfSportCode::INNOVATIVE_MANAGEMENT:
            return
                KindOfSport::DATIVE_CASE::INNOVATIVE_MANAGEMENT;
        case KindOfSportCode::BILLIARDS_SMA:
            return
                KindOfSport::DATIVE_CASE::BILLIARDS_SMA;
        case KindOfSportCode::HAND_TO_HAND_COMBAT_SMA:
            return
                KindOfSport::DATIVE_CASE::HAND_TO_HAND_COMBAT_SMA;
        case KindOfSportCode::BADMINTON:
            return
                KindOfSport::DATIVE_CASE::BADMINTON;
        case KindOfSportCode::TABLE_TENNIS_DEANERY:
            return
                KindOfSport::DATIVE_CASE::TABLE_TENNIS_DEANERY;
        case KindOfSportCode::PHYSICAL_CULTURE_SPORT:
            return
                KindOfSport::DATIVE_CASE::PHYSICAL_CULTURE_SPORT;
        case KindOfSportCode::TOURISM_HOSPITALITY_MASTER:
            return
                KindOfSport::DATIVE_CASE::TOURISM_HOSPITALITY_MASTER;
        case KindOfSportCode::SPORT_CLIMBING:
            return
                KindOfSport::DATIVE_CASE::SPORT_CLIMBING;
        case KindOfSportCode::MASTER_ANTHROPOLOGY:
            return
                KindOfSport::DATIVE_CASE::MASTER_ANTHROPOLOGY;
        case KindOfSportCode::MASTER_MANAGEMENT:
            return
                KindOfSport::DATIVE_CASE::MASTER_MANAGEMENT;

        default:
            ShowMessage (
                "ERROR:\n"                                              \
                "The getKindOfSportNameDativeCase "                     \
                "(int deanerySpesializNSpecializ) method returns:\n"    \
                "Value: "                                               +
                    AnsiString (deanerySpesializNSpecializ)             +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deanerySpesializNSpecializ
                );
    }
}
int        DeleteAfterDatabaseChange::getFacultyCodeByNSpecializ (
        int deanerySpesializNSpecializ
    )
{
    switch (static_cast <KindOfSportCode> (deanerySpesializNSpecializ))
    {
        case KindOfSportCode::GYMNASTICS:
            return
                FacultyCode::MS;
        case KindOfSportCode::MANAGEMENT_SPORTS_TOURISM:
            return
                FacultyCode::RPC;
        case KindOfSportCode::PHYSICAL_REHABILITATION:
            return
                FacultyCode::RPC;
        case KindOfSportCode::THERAPEUTIC:
            return
                FacultyCode::RPC;
        case KindOfSportCode::ORGANIZATION_SPORTS_TOURISM:
            return
                FacultyCode::RPC;
        case KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION:
            return
                FacultyCode::RPC;
        case KindOfSportCode::DANCE_SPORT:
            return
                FacultyCode::MS;
        case KindOfSportCode::AEROBICS:
            return
                FacultyCode::MS;
        case KindOfSportCode::ROWING_OTHER:
            return
                FacultyCode::MS;
        case KindOfSportCode::SWIMMING:
            return
                FacultyCode::MS;
        case KindOfSportCode::SAILING:
            return
                FacultyCode::MS;
        case KindOfSportCode::ATHLETICS:
            return
                FacultyCode::MS;
        case KindOfSportCode::CROSS_COUNTRY_SKIING:
            return
                FacultyCode::MS;
        case KindOfSportCode::BULLET_SHOOTING_DEANERY:
            return
                FacultyCode::MS;
        case KindOfSportCode::HAND_TO_HAND_COMBAT:
            return
                FacultyCode::MS;
        case KindOfSportCode::TAEKWONDO:
            return
                FacultyCode::MS;
        case KindOfSportCode::KARATE:
            return
                FacultyCode::MS;
        case KindOfSportCode::SKIING:
            return
                FacultyCode::MS;
        case KindOfSportCode::AUTOMOTIVE_SPORT:
            return
                FacultyCode::MS;
        case KindOfSportCode::BASKETBALL:
            return
                FacultyCode::SMA;
        case KindOfSportCode::BOXING:
            return
                FacultyCode::SMA;
        case KindOfSportCode::GRECO_FREESTYLE_WRESTLING:
            return
                FacultyCode::SMA;
        case KindOfSportCode::CYCLING:
            return
                FacultyCode::SMA;
        case KindOfSportCode::VOLLEYBALL:
            return
                FacultyCode::SMA;
        case KindOfSportCode::HANDBALL:
            return
                FacultyCode::SMA;
        case KindOfSportCode::EQUESTRIAN:
            return
                FacultyCode::SMA;
        case KindOfSportCode::SPEED_SKATING:
            return
                FacultyCode::SMA;
        case KindOfSportCode::TENNIS:
            return
                FacultyCode::SMA;
        case KindOfSportCode::WEIGHTLIFTING:
            return
                FacultyCode::SMA;
        case KindOfSportCode::FENCING:
            return
                FacultyCode::SMA;
        case KindOfSportCode::FIGURE_SKATING_OLD:
            return
                FacultyCode::SMA;
        case KindOfSportCode::FOOTBALL:
            return
                FacultyCode::SMA;
        case KindOfSportCode::HOCKEY:
            return
                FacultyCode::SMA;
        case KindOfSportCode::SAMBO_JUDO:
            return
                FacultyCode::SMA;
        case KindOfSportCode::WRESTLING:
            return
                FacultyCode::SMA;
        case KindOfSportCode::FOOTBALL_HOCKEY:
            return
                FacultyCode::SMA;
        case KindOfSportCode::BIATHLON:
            return
                FacultyCode::MS;
        case KindOfSportCode::HEALTH_IMPROVING:
            return
                FacultyCode::RPC;
        case KindOfSportCode::ADAPTIVE:
            return
                FacultyCode::RPC;
        case KindOfSportCode::FREESTYLE_WRESTLING:
            return
                FacultyCode::SMA;
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:
            return
                FacultyCode::SMA;
        case KindOfSportCode::SAMBO:
            return
                FacultyCode::SMA;
        case KindOfSportCode::JUDO:
            return
                FacultyCode::SMA;
        case KindOfSportCode::TABLE_TENNIS_ABITURIENT:
            return
                FacultyCode::SMA;
        case KindOfSportCode::ERGOTHERAPY:
            return
                FacultyCode::RPC;
        case KindOfSportCode::MANAGEMENT_SPORTS:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::SPORTS_DIRECTING_DEANERY:
            return
                FacultyCode::RPC;
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::MANAGEMENT_TOURISM:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::SPORTS_PSYCHOLOGY:
            return
                FacultyCode::MS;
        case KindOfSportCode::BILLIARD_SPORTS:
            return
                FacultyCode::RPC;
        case KindOfSportCode::ACROBATICS:
            return
                FacultyCode::MS;
        case KindOfSportCode::ORIENTEERING:
            return
                FacultyCode::MS;
        case KindOfSportCode::SPORTS_DIRECTING:
            return
                FacultyCode::MS;
        case KindOfSportCode::PRESCHOOLERS:
            return
                FacultyCode::RPC;
        case KindOfSportCode::MOUNTAINEERING:
            return
                FacultyCode::MS;
        case KindOfSportCode::SKI_COMBINED:
            return
                FacultyCode::MS;
        case KindOfSportCode::TOURISM_HOSPITALITY:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::WATER_TECHNICAL_SPORTS:
            return
                FacultyCode::MS;
        case KindOfSportCode::MODEL_TECHNICAL_SPORTS:
            return
                FacultyCode::MS;
        case KindOfSportCode::ALPINE_SKIING:
            return
                FacultyCode::MS;
        case KindOfSportCode::BASEBALL:
            return
                FacultyCode::SMA;
        case KindOfSportCode::WUSHU:
            return
                FacultyCode::MS;
        case KindOfSportCode::CHESS:
            return
                FacultyCode::SMA;
        case KindOfSportCode::THAI_BOXING:
            return
                FacultyCode::MS;
        case KindOfSportCode::TOURISM_PROMOTION:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::TOURISM_IT:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::TOURISM_LOGISTICS:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::TOURISM_SOCIAL:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::TOURISM_TRANSPORT:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::TOURISM_FOOD:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::TOURIST_ACCOMMODATION:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::TOURISM_EXCURSION:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::TOURISM_HEALTH:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::BULLET_SHOOTING:
            return
                FacultyCode::MS;
        case KindOfSportCode::FIELD_HOCKEY:
            return
                FacultyCode::SMA;
        case KindOfSportCode::FIGURE_SKATING:
            return
                FacultyCode::SMA;
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                FacultyCode::MS;
        case KindOfSportCode::ACADEMIC_ROWING:
            return
                FacultyCode::MS;
        case KindOfSportCode::HAND_TO_HAND_COMBAT_MS:
            return
                FacultyCode::MS;
        case KindOfSportCode::BILLIARDS_RPC:
            return
                FacultyCode::RPC;
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                FacultyCode::SMA;
        case KindOfSportCode::MEDICAL:
            return
                FacultyCode::SMA;
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                FacultyCode::MS;
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM_OLD:
            return
                FacultyCode::MSTH;
        case KindOfSportCode::SCIENCE_HEALTH:
            return
                FacultyCode::PGS;
        case KindOfSportCode::PHYSIOLOGY:
            return
                FacultyCode::PGS;
        case KindOfSportCode::SCIENCE_THEORY:
            return
                FacultyCode::DOC;
        case KindOfSportCode::RECEARCH_SPORT:
            return
                FacultyCode::MD;
        case KindOfSportCode::INNOVATIVE_TOURISM:
            return
                FacultyCode::MD;
        case KindOfSportCode::INNOVATIVE_HOSPITALITY:
            return
                FacultyCode::MD;
        case KindOfSportCode::INNOVATIVE_TECHNOLOGIES:
            return
                FacultyCode::MD;
        case KindOfSportCode::INNOVATIVE_MANAGEMENT:
            return
                FacultyCode::MD;
        case KindOfSportCode::BILLIARDS_SMA:
            return
                FacultyCode::SMA;
        case KindOfSportCode::HAND_TO_HAND_COMBAT_SMA:
            return
                FacultyCode::SMA;
        case KindOfSportCode::BADMINTON:
            return
                FacultyCode::SMA;
        case KindOfSportCode::TABLE_TENNIS_DEANERY:
            return
                FacultyCode::SMA;
        case KindOfSportCode::PHYSICAL_CULTURE_SPORT:
            return
                FacultyCode::MD;
        case KindOfSportCode::TOURISM_HOSPITALITY_MASTER:
            return
                FacultyCode::MD;
        case KindOfSportCode::SPORT_CLIMBING:
            return
                FacultyCode::MS;
        case KindOfSportCode::MASTER_ANTHROPOLOGY:
            return
                FacultyCode::PGS;
        case KindOfSportCode::MASTER_MANAGEMENT:
            return
                FacultyCode::MD;

        default:
            ShowMessage (
                "ERROR:\n"                                              \
                "The getFacultyNumberByNSpecializ "                     \
                "(int deanerySpesializNSpecializ) method returns:\n"    \
                "Value: "                                               +
                    AnsiString (deanerySpesializNSpecializ)             +
                "\t - The code does not exist!"
            );
            return
                deanerySpesializNSpecializ;
    }
}
int        DeleteAfterDatabaseChange::getNSpecCodeByNSpesializ (
        int deanerySpesializNSpecializ
    )
{
    switch (static_cast <KindOfSportCode> (deanerySpesializNSpecializ))
    {
        case KindOfSportCode::GYMNASTICS:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::MANAGEMENT_SPORTS_TOURISM:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_SPORT_AUX;
        case KindOfSportCode::PHYSICAL_REHABILITATION:
            return
                DeanerySpecialityNSpecCode::REHABILITATION_ERGOTHERAPY_AUX;
        case KindOfSportCode::THERAPEUTIC:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_AUX;
        case KindOfSportCode::ORGANIZATION_SPORTS_TOURISM:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_SPORT_AUX;
        case KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_SPORT_AUX;
        case KindOfSportCode::DANCE_SPORT:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::AEROBICS:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::ROWING_OTHER:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::SWIMMING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::SAILING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::ATHLETICS:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::CROSS_COUNTRY_SKIING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::BULLET_SHOOTING_DEANERY:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::HAND_TO_HAND_COMBAT:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::TAEKWONDO:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::KARATE:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::SKIING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::AUTOMOTIVE_SPORT:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::BASKETBALL:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::BOXING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::GRECO_FREESTYLE_WRESTLING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::CYCLING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::VOLLEYBALL:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::HANDBALL:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::EQUESTRIAN:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::SPEED_SKATING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::TENNIS:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::WEIGHTLIFTING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::FENCING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::FIGURE_SKATING_OLD:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::FOOTBALL:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::HOCKEY:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::SAMBO_JUDO:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_SPORT_AUX;
        case KindOfSportCode::WRESTLING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::FOOTBALL_HOCKEY:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_SPORT_AUX;
        case KindOfSportCode::BIATHLON:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::HEALTH_IMPROVING:
            return
                DeanerySpecialityNSpecCode::IMPROVING_AND_ADAPTIVE_AUX;
        case KindOfSportCode::ADAPTIVE:
            return
                DeanerySpecialityNSpecCode::IMPROVING_AND_ADAPTIVE_AUX;
        case KindOfSportCode::FREESTYLE_WRESTLING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::SAMBO:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::JUDO:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::TABLE_TENNIS_ABITURIENT:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::ERGOTHERAPY:
            return
                DeanerySpecialityNSpecCode::REHABILITATION_ERGOTHERAPY_AUX;
        case KindOfSportCode::MANAGEMENT_SPORTS:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_TOURISM_AUX;
        case KindOfSportCode::SPORTS_DIRECTING_DEANERY:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_SPORT_AUX;
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_AUX;
        case KindOfSportCode::MANAGEMENT_TOURISM:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_TOURISM_AUX;
        case KindOfSportCode::SPORTS_PSYCHOLOGY:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_AUX;
        case KindOfSportCode::BILLIARD_SPORTS:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::ACROBATICS:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::ORIENTEERING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::SPORTS_DIRECTING:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_AUX;
        case KindOfSportCode::PRESCHOOLERS:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_AUX;
        case KindOfSportCode::MOUNTAINEERING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::SKI_COMBINED:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::TOURISM_HOSPITALITY:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case KindOfSportCode::WATER_TECHNICAL_SPORTS:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::MODEL_TECHNICAL_SPORTS:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::ALPINE_SKIING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::BASEBALL:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::WUSHU:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::CHESS:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::THAI_BOXING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::TOURISM_PROMOTION:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case KindOfSportCode::TOURISM_IT:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case KindOfSportCode::TOURISM_LOGISTICS:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case KindOfSportCode::TOURISM_SOCIAL:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case KindOfSportCode::TOURISM_TRANSPORT:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case KindOfSportCode::TOURISM_FOOD:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case KindOfSportCode::TOURIST_ACCOMMODATION:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case KindOfSportCode::TOURISM_EXCURSION:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case KindOfSportCode::TOURISM_HEALTH:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case KindOfSportCode::BULLET_SHOOTING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::FIELD_HOCKEY:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::FIGURE_SKATING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::ACADEMIC_ROWING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::HAND_TO_HAND_COMBAT_MS:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::BILLIARDS_RPC:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        // case KindOfSportCode::MEDICAL                                    null,   // 95,
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM_OLD:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_TOURISM_AUX;
        case KindOfSportCode::SCIENCE_HEALTH:
            return
                DeanerySpecialityNSpecCode::THEORY_IMPROVING_AUX;
        case KindOfSportCode::PHYSIOLOGY:
            return
                DeanerySpecialityNSpecCode::PHYSIOLOGY_AUX;
        case KindOfSportCode::SCIENCE_THEORY:
            return
                DeanerySpecialityNSpecCode::THEORY_IMPROVING_AUX;
        case KindOfSportCode::RECEARCH_SPORT:
            return
                DeanerySpecialityNSpecCode::THEORY_ADAPTIVE_AUX;
        case KindOfSportCode::INNOVATIVE_TOURISM:
            return
                DeanerySpecialityNSpecCode::INNOVATION_TOURISM_AUX;
        case KindOfSportCode::INNOVATIVE_HOSPITALITY:
            return
                DeanerySpecialityNSpecCode::INNOVATION_HOSPITALITY_AUX;
        case KindOfSportCode::INNOVATIVE_TECHNOLOGIES:
            return
                DeanerySpecialityNSpecCode::INNOVATION_TECHNOLOGY_AUX;
        case KindOfSportCode::INNOVATIVE_MANAGEMENT:
            return
                DeanerySpecialityNSpecCode::INNOVATION_MANAGEMENT_AUX;
        case KindOfSportCode::BILLIARDS_SMA:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::HAND_TO_HAND_COMBAT_SMA:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::BADMINTON:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        //case KindOfSportCode::TABLE_TENNIS_DEANERY                        2,      // 117, n_spec = 2 is absent
        case KindOfSportCode::PHYSICAL_CULTURE_SPORT:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_STUDY_AUX;
        case KindOfSportCode::TOURISM_HOSPITALITY_MASTER:
            return
                DeanerySpecialityNSpecCode::MASTER_PHYSICAL_CULTURE_AUX;
        case KindOfSportCode::SPORT_CLIMBING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case KindOfSportCode::MASTER_ANTHROPOLOGY:
            return
                DeanerySpecialityNSpecCode::THEORY_ADAPTIVE_AUX;
        // case KindOfSportCode::MASTER_MANAGEMENT                          null    // 122,

        default:
            ShowMessage (
                "ERROR:\n"                                              \
                "The getNSpecDirCodeByNSpesializ "                      \
                "(int deanerySpesializNSpecializ) method returns:\n"    \
                "Value: "                                               +
                    AnsiString (deanerySpesializNSpecializ)             +
                "\t - The code does not exist!"
            );
            return
                deanerySpesializNSpecializ;
    }
}
int        DeleteAfterDatabaseChange::getNSpecDirCodeByNSpecializ (
        int deanerySpesializNSpecializ
    )
{
    switch (static_cast <KindOfSportCode> (deanerySpesializNSpecializ))
    {
        case KindOfSportCode::GYMNASTICS:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        // case KindOfSportCode::MANAGEMENT_SPORTS_TOURISM                         // = null,
        case KindOfSportCode::PHYSICAL_REHABILITATION:
            return
                DeanerySpecialDirectionNSpecDirCode::REHABILITATION_REHABILITATION;
        case KindOfSportCode::THERAPEUTIC:
            return
                DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_MEDICAL;
        // case KindOfSportCode::ORGANIZATION_SPORTS_TOURISM                       // = null,
        // case KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION                      // = null,
        case KindOfSportCode::DANCE_SPORT:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::AEROBICS:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::ROWING_OTHER:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::SWIMMING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::SAILING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::ATHLETICS:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::CROSS_COUNTRY_SKIING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::BULLET_SHOOTING_DEANERY:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::HAND_TO_HAND_COMBAT:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::TAEKWONDO:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::KARATE:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::SKIING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::AUTOMOTIVE_SPORT:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::BASKETBALL:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::BOXING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::GRECO_FREESTYLE_WRESTLING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::CYCLING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::VOLLEYBALL:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::HANDBALL:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::EQUESTRIAN:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::SPEED_SKATING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::TENNIS:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::WEIGHTLIFTING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::FENCING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::FIGURE_SKATING_OLD:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::FOOTBALL:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::HOCKEY:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::SAMBO_JUDO:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::WRESTLING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::FOOTBALL_HOCKEY:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::BIATHLON:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::HEALTH_IMPROVING:
            return
                DeanerySpecialDirectionNSpecDirCode::IMPROVING_HEALTH;
        case KindOfSportCode::ADAPTIVE:
            return
                DeanerySpecialDirectionNSpecDirCode::IMPROVING_ADAPTIVE;
        case KindOfSportCode::FREESTYLE_WRESTLING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::SAMBO:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::JUDO:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::TABLE_TENNIS_ABITURIENT:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::ERGOTHERAPY:
            return
                DeanerySpecialDirectionNSpecDirCode::REHABILITATION_ERGOTHERAPY;
        case KindOfSportCode::MANAGEMENT_SPORTS:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_MANAGEMENT;
        // case KindOfSportCode::SPORTS_DIRECTING_DEANERY                          // = null,
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM:
            return
                DeanerySpecialDirectionNSpecDirCode::TOURISM_RECREATIONAL;
        case KindOfSportCode::MANAGEMENT_TOURISM:
            return
                DeanerySpecialDirectionNSpecDirCode::TOURISM_TUORISM_MNG;
        case KindOfSportCode::SPORTS_PSYCHOLOGY:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_PSYCHOLOGY;
        case KindOfSportCode::BILLIARD_SPORTS:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::ACROBATICS:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::ORIENTEERING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::SPORTS_DIRECTING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_DIRECTING;
        case KindOfSportCode::PRESCHOOLERS:
            return
                DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_PRESCHOOLERS;
        case KindOfSportCode::MOUNTAINEERING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::SKI_COMBINED:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::TOURISM_HOSPITALITY:
            return
                DeanerySpecialDirectionNSpecDirCode::SECTION_TOURISM_HOSPITALITY;
        case KindOfSportCode::WATER_TECHNICAL_SPORTS:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::MODEL_TECHNICAL_SPORTS:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::ALPINE_SKIING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::BASEBALL:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::WUSHU:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::CHESS:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::THAI_BOXING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::TOURISM_PROMOTION:
            return
                DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_PROMOTION;
        case KindOfSportCode::TOURISM_IT:
            return
                DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_IT;
        case KindOfSportCode::TOURISM_LOGISTICS:
            return
                DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_LOGISTICS;
        case KindOfSportCode::TOURISM_SOCIAL:
            return
                DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SOCIAL;
        case KindOfSportCode::TOURISM_TRANSPORT:
            return
                DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TRANSPORT;
        case KindOfSportCode::TOURISM_FOOD:
            return
                DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_CATERING;
        case KindOfSportCode::TOURIST_ACCOMMODATION:
            return
                DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_ACCOMMODATION;
        case KindOfSportCode::TOURISM_EXCURSION:
            return
                DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SUPPORTING;
        case KindOfSportCode::TOURISM_HEALTH:
            return
                DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TREATMENT;
        case KindOfSportCode::BULLET_SHOOTING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::FIELD_HOCKEY:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::FIGURE_SKATING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::ACADEMIC_ROWING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::HAND_TO_HAND_COMBAT_MS:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::BILLIARDS_RPC:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        // case KindOfSportCode::MEDICAL                                           // = null, ABSENT
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM_OLD:
            return
                DeanerySpecialDirectionNSpecDirCode::TOURISM_RECREATIONAL;
        case KindOfSportCode::SCIENCE_HEALTH:
            return
                DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_THEORY;
        case KindOfSportCode::PHYSIOLOGY:
            return
                DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_PHYSIOLOGY;
        case KindOfSportCode::SCIENCE_THEORY:
            return
                DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_THEORY;
        case KindOfSportCode::RECEARCH_SPORT:
            return
                DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_SPORT;
        case KindOfSportCode::INNOVATIVE_TOURISM:
            return
                DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TOURISM;
        case KindOfSportCode::INNOVATIVE_HOSPITALITY:
            return
                DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_HOSPITALITY;
        case KindOfSportCode::INNOVATIVE_TECHNOLOGIES:
            return
                DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TECHNOLOGY;
        // case KindOfSportCode::INNOVATIVE_MANAGEMENT                          //= 30, ABSENT
        case KindOfSportCode::BILLIARDS_SMA:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::HAND_TO_HAND_COMBAT_SMA:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::BADMINTON:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::TABLE_TENNIS_DEANERY:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        case KindOfSportCode::PHYSICAL_CULTURE_SPORT:
            return
                DeanerySpecialDirectionNSpecDirCode::MASTER_PHYSICAL_CULTURE_SPORT;
        case KindOfSportCode::TOURISM_HOSPITALITY_MASTER:
            return
                DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_TOURISM;
        case KindOfSportCode::SPORT_CLIMBING:
            return
                DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING;
        // case KindOfSportCode::MASTER_ANTHROPOLOGY                            // = 33, ABSENT
        // case KindOfSportCode::MASTER_MANAGEMENT                                 // = null

        default:
            ShowMessage (
                "ERROR:\n"                                              \
                "The getNSpecDirCodeByNSpecializ "                      \
                "(int deanerySpesializNSpecializ) method returns:\n"    \
                "Value: "                                               +
                    AnsiString (deanerySpesializNSpecializ)             +
                "\t - The code does not exist!"
            );
            return
                deanerySpesializNSpecializ;
    }
}

AnsiString DeleteAfterDatabaseChange::getNcrb2022CodeByNSpec (
        int deanerySpecialityNSpecCode
    )
{
    switch (    static_cast <DeanerySpecialityNSpecCode>
                (
                    deanerySpecialityNSpecCode
                )
           )
    {
        case DeanerySpecialityNSpecCode::IMPROVING_AND_ADAPTIVE_AUX:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX:
            return
                NCRB_011::_2022::CODE::COACHING;
        case DeanerySpecialityNSpecCode::SPORTS_AND_TOURISM_AUX:
            return
                NCRB_011::_2022::CODE::MANAGEMENT;
        case DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_AUX:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case DeanerySpecialityNSpecCode::REHABILITATION_ERGOTHERAPY_AUX:
            return
                NCRB_011::_2022::CODE::REHABILITATION;
        case DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX:
            return
                NCRB_011::_2022::CODE::TOURISM;
        case DeanerySpecialityNSpecCode::THEORY_IMPROVING_AUX:
            return
                NCRB_011::_2022::CODE::THEORY_IMPROVING;
        case DeanerySpecialityNSpecCode::PHYSIOLOGY_AUX:
            return
                NCRB_011::_2022::CODE::PHYSIOLOGY;
        case DeanerySpecialityNSpecCode::THEORY_ADAPTIVE_AUX:
            return
                NCRB_011::_2022::CODE::PC_MASTER_DEGREE;
        case DeanerySpecialityNSpecCode::INNOVATION_TOURISM_AUX:
            return
                NCRB_011::_2022::CODE::INNO_TOURISM;
        case DeanerySpecialityNSpecCode::INNOVATION_HOSPITALITY_AUX:
            return
                NCRB_011::_2022::CODE::INNO_HOSPITALITY;
        case DeanerySpecialityNSpecCode::INNOVATION_TECHNOLOGY_AUX:
            return
                NCRB_011::_2022::CODE::INNO_TECHNOLOGY;
        case DeanerySpecialityNSpecCode::INNOVATION_MANAGEMENT_AUX:
            return
                NCRB_011::_2022::CODE::INNO_MANAGEMENT;
        case DeanerySpecialityNSpecCode::MASTER_PHYSICAL_CULTURE_AUX:
            return
                NCRB_011::_2022::CODE::PC_MASTER_DEGREE;
        case DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_STUDY_AUX:
            return
                NCRB_011::_2022::CODE::TH_MASTER_DEGREE;
        case DeanerySpecialityNSpecCode::TRAINING_MILITARY_PERSONNEL_AUX:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case DeanerySpecialityNSpecCode::SPORTS_CHOREOGRAPHY_AUX:
            return
                NCRB_011::_2022::CODE::CHOREOGRAPHY;
        case DeanerySpecialityNSpecCode::TOURISM_AND_NATURE_MANAGEMENT_AUX:
            return
                NCRB_011::_2022::CODE::NATURE;
        case DeanerySpecialityNSpecCode::HOSPITALITY_TECHNOLOGIES_AUX:
            return
                NCRB_011::_2022::CODE::HOSPITALITY;

        default:
            ShowMessage (
                "ERROR:\n"                                              \
                "The getNcrb2022Code "                                  \
                "(int deanerySpecialityNSpecCode) method returns:\n"    \
                "Value: "                                               +
                    AnsiString (deanerySpecialityNSpecCode)             +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deanerySpecialityNSpecCode
                );
    }
}
AnsiString DeleteAfterDatabaseChange::getSpecialityName2022ByNSpec (
        int deanerySpecialityNSpecCode
    )
{
    switch (    static_cast <DeanerySpecialityNSpecCode>
                (
                    deanerySpecialityNSpecCode
                )
           )
    {
        case DeanerySpecialityNSpecCode::THEORY_IMPROVING_AUX:
            return
                NCRB_011::_2022::NAME::THEORY_IMPROVING;
        case DeanerySpecialityNSpecCode::PHYSIOLOGY_AUX:
            return
                NCRB_011::_2022::NAME::PHYSIOLOGY;
        case DeanerySpecialityNSpecCode::THEORY_ADAPTIVE_AUX:
            return
                NCRB_011::_2022::NAME::PC_MASTER_DEGREE;
        case DeanerySpecialityNSpecCode::INNOVATION_TOURISM_AUX:
            return
                NCRB_011::_2022::NAME::INNO_TOURISM;
        case DeanerySpecialityNSpecCode::INNOVATION_HOSPITALITY_AUX:
            return
                NCRB_011::_2022::NAME::INNO_HOSPITALITY;
        case DeanerySpecialityNSpecCode::INNOVATION_TECHNOLOGY_AUX:
            return
                NCRB_011::_2022::NAME::INNO_TECHNOLOGY;
        case DeanerySpecialityNSpecCode::INNOVATION_MANAGEMENT_AUX:
            return
                NCRB_011::_2022::NAME::INNO_MANAGEMENT;
        case DeanerySpecialityNSpecCode::MASTER_PHYSICAL_CULTURE_AUX:
            return
                NCRB_011::_2022::NAME::PC_MASTER_DEGREE;
        case DeanerySpecialityNSpecCode::IMPROVING_AND_ADAPTIVE_AUX:
            return
                NCRB_011::_2022::NAME::PHYSICAL_CULTURE;
        case DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX:
            return
                    NCRB_011::_2022::NAME::COACHING             +
                " "                                             +
                    NCRB_011::_2022::NAME::COACH::DEFAULT;
        case DeanerySpecialityNSpecCode::SPORTS_AND_TOURISM_AUX:
            return
                NCRB_011::_2022::NAME::MANAGEMENT;
        case DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_AUX:
            return
                NCRB_011::_2022::NAME::PHYSICAL_CULTURE;
        case DeanerySpecialityNSpecCode::REHABILITATION_ERGOTHERAPY_AUX:
            return
                NCRB_011::_2022::NAME::REHABILITATION;
        case DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX:
            return
                    NCRB_011::_2022::NAME::TOURISM;
        case DeanerySpecialityNSpecCode::TRAINING_MILITARY_PERSONNEL_AUX:
            return
                NCRB_011::_2022::NAME::PHYSICAL_CULTURE;
        case DeanerySpecialityNSpecCode::SPORTS_CHOREOGRAPHY_AUX:
            return
                NCRB_011::_2022::NAME::CHOREOGRAPHY;
        case DeanerySpecialityNSpecCode::TOURISM_AND_NATURE_MANAGEMENT_AUX:
            return
                NCRB_011::_2022::NAME::NATURE;
        case DeanerySpecialityNSpecCode::HOSPITALITY_TECHNOLOGIES_AUX:
            return
                NCRB_011::_2022::NAME::HOSPITALITY;
        case DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_STUDY_AUX:
            return
                NCRB_011::_2022::NAME::TH_MASTER_DEGREE;

        default:
            ShowMessage (
                "ERROR:\n"                                              \
                "The getSpecialityName2022ByNSpec "                     \
                "(int deanerySpecialityNSpecCode) method returns:\n"    \
                "Value: "                                               +
                    AnsiString (deanerySpecialityNSpecCode)             +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deanerySpecialityNSpecCode
                );
    }
}
AnsiString DeleteAfterDatabaseChange::getNcrb2022QualificationByNSpec (
        int deanerySpecialityNSpec
    )
{
    switch (static_cast <DeanerySpecialityNSpecCode> (deanerySpecialityNSpec))
    {
        case DeanerySpecialityNSpecCode::IMPROVING_AND_ADAPTIVE_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;
        case DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::COACHING;
        case DeanerySpecialityNSpecCode::SPORTS_AND_TOURISM_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::MANAGEMENT;
        case DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;
        case DeanerySpecialityNSpecCode::REHABILITATION_ERGOTHERAPY_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::REHABILITATION;
        case DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::TOURISM;
        //case DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX:
        //    return
        //        NCRB_011::_2022::QUALIFICATION::TOURISM;
        case DeanerySpecialityNSpecCode::THEORY_IMPROVING_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::THEORY_IMPROVING;
        case DeanerySpecialityNSpecCode::PHYSIOLOGY_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::PHYSIOLOGY;
        case DeanerySpecialityNSpecCode::THEORY_ADAPTIVE_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::PC_MASTER_DEGREE;
        case DeanerySpecialityNSpecCode::INNOVATION_TOURISM_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::INNO_TOURISM;
        case DeanerySpecialityNSpecCode::INNOVATION_HOSPITALITY_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::INNO_HOSPITALITY;
        case DeanerySpecialityNSpecCode::INNOVATION_TECHNOLOGY_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::INNO_TECHNOLOGY;
        case DeanerySpecialityNSpecCode::INNOVATION_MANAGEMENT_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::INNO_MANAGEMENT;
        case DeanerySpecialityNSpecCode::MASTER_PHYSICAL_CULTURE_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::PC_MASTER_DEGREE;
        case DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_STUDY_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::TH_MASTER_DEGREE;
        case DeanerySpecialityNSpecCode::TRAINING_MILITARY_PERSONNEL_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::PHYSICAL_CULTURE;
        case DeanerySpecialityNSpecCode::SPORTS_CHOREOGRAPHY_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::CHOREOGRAPHY;
        case DeanerySpecialityNSpecCode::TOURISM_AND_NATURE_MANAGEMENT_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::NATURE;
        case DeanerySpecialityNSpecCode::HOSPITALITY_TECHNOLOGIES_AUX:
            return
                NCRB_011::_2022::QUALIFICATION::HOSPITALITY;

        default:
            ShowMessage (
                "ERROR:\n"                                      \
                "The getNcrb2022Qualification "                 \
                "(int deanerySpecialityNSpec) method returns:\n"   \
                "Value: "                                       +
                    AnsiString (deanerySpecialityNSpec)            +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deanerySpecialityNSpec
                );
    }
}


AnsiString DeleteAfterDatabaseChange::getNcrb2009CodeByNSpecDir (
        int deanerySpecialDirectionNSpecDirCode
    )
{
    switch (    static_cast <DeanerySpecialDirectionNSpecDirCode>
                (
                    deanerySpecialDirectionNSpecDirCode
                )
           )
    {
        case DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING:
            return
                NCRB_011::_2009::CODE::SPORT::COACHING;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_PSYCHOLOGY:
            return
                NCRB_011::_2009::CODE::SPORT::PSYCHOLOGY;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_DIRECTING:
            return
                NCRB_011::_2009::CODE::SPORT::DIRECTING;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_MANAGEMENT:
            return
                NCRB_011::_2009::CODE::SPORT::MANAGEMENT;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_RECREATIONAL:
            return
                NCRB_011::_2009::CODE::TOURISM::RECREATIONAL;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_TUORISM_MNG:
            return
                NCRB_011::_2009::CODE::TOURISM::TUORISM_MNG;
        case DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_MEDICAL:
            return
                NCRB_011::_2009::CODE::PHYSICAL_CULTURE::MEDICAL;
        case DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_PRESCHOOLERS:
            return
                NCRB_011::_2009::CODE::PHYSICAL_CULTURE::PRESCHOOLERS;
        case DeanerySpecialDirectionNSpecDirCode::IMPROVING_HEALTH:
            return
                NCRB_011::_2009::CODE::IMPROVING::HEALTH;
        case DeanerySpecialDirectionNSpecDirCode::IMPROVING_ADAPTIVE:
            return
                NCRB_011::_2009::CODE::IMPROVING::ADAPTIVE;
        case DeanerySpecialDirectionNSpecDirCode::REHABILITATION_REHABILITATION:
            return
                NCRB_011::_2009::CODE::REHABILITATION::REHABILITATION;
        case DeanerySpecialDirectionNSpecDirCode::REHABILITATION_ERGOTHERAPY:
            return
                NCRB_011::_2009::CODE::REHABILITATION::ERGOTHERAPY;
        case DeanerySpecialDirectionNSpecDirCode::SECTION_TOURISM_HOSPITALITY:
            return
                NCRB_011::_2009::CODE::SECTION::TOURISM_HOSPITALITY;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_PROMOTION:
            return
                NCRB_011::_2009::CODE::TOURISM_HOSPITALITY::PROMOTION;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_IT:
            return
                NCRB_011::_2009::CODE::TOURISM_HOSPITALITY::IT;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_LOGISTICS:
            return
                NCRB_011::_2009::CODE::TOURISM_HOSPITALITY::LOGISTICS;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SOCIAL:
            return
                NCRB_011::_2009::CODE::TOURISM_HOSPITALITY::SOCIAL;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TRANSPORT:
            return
                NCRB_011::_2009::CODE::TOURISM_HOSPITALITY::TRANSPORT;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_CATERING:
            return
                NCRB_011::_2009::CODE::TOURISM_HOSPITALITY::CATERING;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_ACCOMMODATION:
            return
                NCRB_011::_2009::CODE::TOURISM_HOSPITALITY::ACCOMMODATION;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SUPPORTING:
            return
                NCRB_011::_2009::CODE::TOURISM_HOSPITALITY::SUPPORTING;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TREATMENT:
            return
                NCRB_011::_2009::CODE::TOURISM_HOSPITALITY::TREATMENT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_THEORY:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::SCIENCE::THEORY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_PHYSIOLOGY:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::SCIENCE::PHYSIOLOGY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_SPORT:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::RESEARCH::SPORT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TOURISM:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::INNOVATION::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_HOSPITALITY:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::INNOVATION::HOSPITALITY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TECHNOLOGY:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::INNOVATION::TECHNO;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_MANAGEMENT:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::INNOVATION::MANAGEMENT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_PHYSICAL_CULTURE_SPORT:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::RESEARCH::SPORT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_TOURISM:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::RESEARCH::TOURISM;

        default:
            ShowMessage (
                "ERROR:\n"                                                      \
                "The getNcrb2009Code "                                          \
                "(int deanerySpecialDirectionNSpecDirCode) method returns:\n"   \
                "Value: "                                                       +
                    AnsiString (deanerySpecialDirectionNSpecDirCode)            +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deanerySpecialDirectionNSpecDirCode
                );
    };
}
AnsiString DeleteAfterDatabaseChange::getNcrb2022CodeByNSpecDir (               // ERROR With Physical and Coaching
        int deanerySpecialDirectionNSpecDirCode
    )
{
    switch (    static_cast <DeanerySpecialDirectionNSpecDirCode>
                (
                    deanerySpecialDirectionNSpecDirCode
                )
           )
    {
        case DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING:
            return
                NCRB_011::_2022::CODE::MANAGEMENT;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_PSYCHOLOGY:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_DIRECTING:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_MANAGEMENT:
            return
                NCRB_011::_2022::CODE::MANAGEMENT;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_RECREATIONAL:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_TUORISM_MNG:
            return
                NCRB_011::_2022::CODE::MANAGEMENT;
        case DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_MEDICAL:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_PRESCHOOLERS:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case DeanerySpecialDirectionNSpecDirCode::IMPROVING_HEALTH:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case DeanerySpecialDirectionNSpecDirCode::IMPROVING_ADAPTIVE:
            return
                NCRB_011::_2022::CODE::PHYSICAL_CULTURE;
        case DeanerySpecialDirectionNSpecDirCode::REHABILITATION_REHABILITATION:
            return
                NCRB_011::_2022::CODE::REHABILITATION;
        case DeanerySpecialDirectionNSpecDirCode::REHABILITATION_ERGOTHERAPY:
            return
                NCRB_011::_2022::CODE::REHABILITATION;
        case DeanerySpecialDirectionNSpecDirCode::SECTION_TOURISM_HOSPITALITY:
            return
                NCRB_011::_2022::CODE::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_PROMOTION:
            return
                NCRB_011::_2022::CODE::TOURISM;                                     // "1-89 01 01 01",
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_IT:
            return
                NCRB_011::_2022::CODE::TOURISM;                                     // "1-89 01 01 02",
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_LOGISTICS:
            return
                NCRB_011::_2022::CODE::TOURISM;                                     // "1-89 01 01 03",
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SOCIAL:
            return
                NCRB_011::_2022::CODE::TOURISM;                                     // "1-89 01 01 04",
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TRANSPORT:
            return
                NCRB_011::_2022::CODE::TOURISM;                                     // "1-89 01 01 05",
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_CATERING:
            return
                NCRB_011::_2022::CODE::TOURISM;                                     // "1-89 01 01 06",
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_ACCOMMODATION:
            return
                NCRB_011::_2022::CODE::TOURISM;                                     // "1-89 01 01 07",
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SUPPORTING:
            return
                NCRB_011::_2022::CODE::TOURISM;                                     // "1-89 01 01 08",
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TREATMENT:
            return
                NCRB_011::_2022::CODE::TOURISM;                                     // "1-89 01 01 09",
        case DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_THEORY:
            return
                NCRB_011::_2022::CODE::PHYSIOLOGY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_PHYSIOLOGY:
            return
                NCRB_011::_2022::CODE::THEORY_IMPROVING;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_SPORT:
            return
                NCRB_011::_2022::CODE::PC_MASTER_DEGREE;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TOURISM:
            return
                NCRB_011::_2022::CODE::INNO_TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_HOSPITALITY:
            return
                NCRB_011::_2022::CODE::INNO_HOSPITALITY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TECHNOLOGY:
            return
                NCRB_011::_2022::CODE::INNO_TECHNOLOGY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_MANAGEMENT:
            return
                NCRB_011::_2022::CODE::INNO_MANAGEMENT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_PHYSICAL_CULTURE_SPORT:
            return
                NCRB_011::_2022::CODE::PC_MASTER_DEGREE;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_TOURISM:
            return
                NCRB_011::_2022::CODE::TH_MASTER_DEGREE;

        default:
            ShowMessage (
                "ERROR:\n"                                                      \
                "The getNcrb2022CodeByNSpecDir "                                \
                "(int deanerySpecialDirectionNSpecDirCode) method returns:\n"   \
                "Value: "                                                       +
                    AnsiString (deanerySpecialDirectionNSpecDirCode)            +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deanerySpecialDirectionNSpecDirCode
                );
    }
}
AnsiString DeleteAfterDatabaseChange::getDirectionName2022ByNSpecDirNSpecializ (
        int deanerySpecialDirectionNSpecDirCode,
        int deanerySpecializNSpecializ
    )
{
    switch (    static_cast <DeanerySpecialDirectionNSpecDirCode>
                (
                    deanerySpecialDirectionNSpecDirCode
                )
           )
    {
        case DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING:
        {
            AnsiString profile;
            if (deanerySpecializNSpecializ)
                profile =
                    "("                                 +
                        getKindOfSportNameByNSpecializ (
                            deanerySpecializNSpecializ
                        )                               +
                    ")";
            else
                profile = NCRB_011::_2022::NAME::COACH::DEFAULT;
            return
                    NCRB_011::_2022::NAME::COACHING             +
                " "                                             +
                    profile.LowerCase();
        }
        case DeanerySpecialDirectionNSpecDirCode::SPORT_PSYCHOLOGY:
            return
                    NCRB_011::_2022::NAME::PHYSICAL_CULTURE             +
                " "                                                     +
                    NCRB_011::_2022::NAME::PHYSICAL::PSYCHOLOGY;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_DIRECTING:
            return
                    NCRB_011::_2022::NAME::PHYSICAL_CULTURE             +
                " "                                                     +
                    NCRB_011::_2022::NAME::PHYSICAL::DIRECTING;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_MANAGEMENT:
            return
                    NCRB_011::_2022::NAME::MANAGEMENT           +
                " "                                             +
                    NCRB_011::_2022::NAME::MANAGE::SPORT;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_RECREATIONAL:
            return
                    NCRB_011::_2022::NAME::PHYSICAL_CULTURE                 +
                " "                                                         +
                    NCRB_011::_2022::NAME::PHYSICAL::RECREATIONAL;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_TUORISM_MNG:
            return
                    NCRB_011::_2022::NAME::MANAGEMENT           +
                " "                                             +
                    NCRB_011::_2022::NAME::MANAGE::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_MEDICAL:
            return
                    NCRB_011::_2022::NAME::PHYSICAL_CULTURE         +
                " "                                                 +
                    NCRB_011::_2022::NAME::PHYSICAL::HEALTH;
        case DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_PRESCHOOLERS:
            return
                    NCRB_011::_2022::NAME::PHYSICAL_CULTURE                 +
                " "                                                         +
                    NCRB_011::_2022::NAME::PHYSICAL::PRESCHOOLERS;
        case DeanerySpecialDirectionNSpecDirCode::IMPROVING_HEALTH:
            return
                    NCRB_011::_2022::NAME::PHYSICAL_CULTURE             +
                " "                                                     +
                    NCRB_011::_2022::NAME::PHYSICAL::IMPROVING;
        case DeanerySpecialDirectionNSpecDirCode::IMPROVING_ADAPTIVE:
            return
                    NCRB_011::_2022::NAME::PHYSICAL_CULTURE             +
                " "                                                     +
                    NCRB_011::_2022::NAME::PHYSICAL::ADAPTIVE;
        case DeanerySpecialDirectionNSpecDirCode::REHABILITATION_REHABILITATION:
            return
                    NCRB_011::_2022::NAME::REHABILITATION                   +
                " "                                                         +
                    NCRB_011::_2022::NAME::REHABILITATE::REHABILITATION;
        case DeanerySpecialDirectionNSpecDirCode::REHABILITATION_ERGOTHERAPY:
            return
                    NCRB_011::_2022::NAME::REHABILITATION               +
                " "                                                     +
                    NCRB_011::_2022::NAME::REHABILITATE::ERGOTHERAPY;
        case DeanerySpecialDirectionNSpecDirCode::SECTION_TOURISM_HOSPITALITY:
            return
                NCRB_011::_2022::NAME::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_PROMOTION:
            return
                NCRB_011::_2022::NAME::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_IT:
            return
                NCRB_011::_2022::NAME::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_LOGISTICS:
            return
                NCRB_011::_2022::NAME::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SOCIAL:
            return
                NCRB_011::_2022::NAME::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TRANSPORT:
            return
                NCRB_011::_2022::NAME::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_CATERING:
            return
                NCRB_011::_2022::NAME::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_ACCOMMODATION:
            return
                NCRB_011::_2022::NAME::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SUPPORTING:
            return
                NCRB_011::_2022::NAME::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TREATMENT:
            return
                NCRB_011::_2022::NAME::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_THEORY:
            return
                NCRB_011::_2022::NAME::THEORY_IMPROVING;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_PHYSIOLOGY:
            return
                NCRB_011::_2022::NAME::PHYSIOLOGY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_SPORT:
            return
                NCRB_011::_2022::NAME::THEORY_IMPROVING;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TOURISM:
            return
                NCRB_011::_2022::NAME::INNO_TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_HOSPITALITY:
            return
                NCRB_011::_2022::NAME::INNO_HOSPITALITY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TECHNOLOGY:
            return
                NCRB_011::_2022::NAME::INNO_TECHNOLOGY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_MANAGEMENT:
            return
                NCRB_011::_2022::NAME::INNO_MANAGEMENT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_PHYSICAL_CULTURE_SPORT:
            return
                NCRB_011::_2022::NAME::PC_MASTER_DEGREE;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_TOURISM:
            return
                NCRB_011::_2022::NAME::TH_MASTER_DEGREE;

        default:
            ShowMessage (
                "ERROR:\n"                                                      \
                "The getDirectionName2022ByNSpecDirNSpecializ ("                \
                "    int deanerySpecialDirectionNSpecDirCode,"                  \
                "    int deanerySpecializNSpecializmethod returns:\n"   \
                "Value: "                                                       +
                    AnsiString (deanerySpecialDirectionNSpecDirCode)            +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deanerySpecialDirectionNSpecDirCode
                );
    }
}
int        DeleteAfterDatabaseChange::getNSpecCodeByNSpecDir (
        int deanerySpecialDirectionNSpecDirCode
    )
{
    switch (    static_cast <DeanerySpecialDirectionNSpecDirCode>
                (
                    deanerySpecialDirectionNSpecDirCode
                )
           )
    {
        case DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_PSYCHOLOGY:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_DIRECTING:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_MANAGEMENT:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_PEDAGOGY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_RECREATIONAL:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_TOURISM_AUX;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_TUORISM_MNG:
            return
                DeanerySpecialityNSpecCode::SPORTS_AND_TOURISM_AUX;
        case DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_MEDICAL:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_AUX;
        case DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_PRESCHOOLERS:
            return
                DeanerySpecialityNSpecCode::PHYSICAL_CULTURE_AUX;
        case DeanerySpecialDirectionNSpecDirCode::IMPROVING_HEALTH:
            return
                DeanerySpecialityNSpecCode::IMPROVING_AND_ADAPTIVE_AUX;
        case DeanerySpecialDirectionNSpecDirCode::IMPROVING_ADAPTIVE:
            return
                DeanerySpecialityNSpecCode::IMPROVING_AND_ADAPTIVE_AUX;
        case DeanerySpecialDirectionNSpecDirCode::REHABILITATION_REHABILITATION:
            return
                DeanerySpecialityNSpecCode::REHABILITATION_ERGOTHERAPY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::REHABILITATION_ERGOTHERAPY:
            return
                DeanerySpecialityNSpecCode::REHABILITATION_ERGOTHERAPY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::SECTION_TOURISM_HOSPITALITY:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_PROMOTION:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_IT:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_LOGISTICS:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SOCIAL:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TRANSPORT:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_CATERING:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_ACCOMMODATION:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SUPPORTING:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TREATMENT:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_THEORY:
            return
                DeanerySpecialityNSpecCode::THEORY_IMPROVING_AUX;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_PHYSIOLOGY:
            return
                DeanerySpecialityNSpecCode::PHYSIOLOGY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_SPORT:
            return
                DeanerySpecialityNSpecCode::THEORY_ADAPTIVE_AUX;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TOURISM:
            return
                DeanerySpecialityNSpecCode::INNOVATION_TOURISM_AUX;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_HOSPITALITY:
            return
                DeanerySpecialityNSpecCode::INNOVATION_HOSPITALITY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TECHNOLOGY:
            return
                DeanerySpecialityNSpecCode::INNOVATION_TECHNOLOGY_AUX;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_MANAGEMENT:
            return
                DeanerySpecialityNSpecCode::INNOVATION_MANAGEMENT_AUX;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_PHYSICAL_CULTURE_SPORT:
            return
                DeanerySpecialityNSpecCode::MASTER_PHYSICAL_CULTURE_AUX;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_TOURISM:
            return
                DeanerySpecialityNSpecCode::TOURISM_HOSPITALITY_STUDY_AUX;

        default:
            ShowMessage (
                "ERROR:\n"                                                      \
                "The getNSpecCodeByNSpecDir "                                   \
                "(int deanerySpecialDirectionNSpecDirCode) method returns:\n"   \
                "Value: "                                                       +
                    AnsiString (deanerySpecialDirectionNSpecDirCode)            +
                "\t - The code does not exist!"
            );
            return
                deanerySpecialDirectionNSpecDirCode;
    }
}



// EVERYTHING BELOW TO DO A LITTLE LATER
/*
AnsiString ToDoLater::getSpecialityName2009ByNSpecDir (
        int deanerySpecialDirectionNSpecDirCode
    )
{
    switch (    static_cast <DeanerySpecialDirectionNSpecDirCode>
                (
                    deanerySpecialDirectionNSpecDirCode
                )
           )
    {
        case DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING:
            return
                NCRB_011::_2009::NAME::SPORT::COACHING;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_PSYCHOLOGY:
            return
                NCRB_011::_2009::NAME::SPORT::PSYCHOLOGY;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_DIRECTING:
            return
                NCRB_011::_2009::NAME::SPORT::DIRECTING;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_MANAGEMENT:
            return
                NCRB_011::_2009::NAME::SPORT::MANAGEMENT;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_RECREATIONAL:
            return
                NCRB_011::_2009::NAME::TOURISM::RECREATIONAL;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_TUORISM_MNG:
            return
                NCRB_011::_2009::NAME::TOURISM::TUORISM_MNG;
        case DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_MEDICAL:
            return
                NCRB_011::_2009::NAME::PHYSICAL_CULTURE::MEDICAL;
        case DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_PRESCHOOLERS:
            return
                NCRB_011::_2009::NAME::PHYSICAL_CULTURE::PRESCHOOLERS;
        case DeanerySpecialDirectionNSpecDirCode::IMPROVING_HEALTH:
            return
                NCRB_011::_2009::NAME::IMPROVING::HEALTH;
        case DeanerySpecialDirectionNSpecDirCode::IMPROVING_ADAPTIVE:
            return
                NCRB_011::_2009::NAME::IMPROVING::ADAPTIVE;
        case DeanerySpecialDirectionNSpecDirCode::REHABILITATION_REHABILITATION:
            return
                NCRB_011::_2009::NAME::REHABILITATION::REHABILITATION;
        case DeanerySpecialDirectionNSpecDirCode::REHABILITATION_ERGOTHERAPY:
            return
                NCRB_011::_2009::NAME::REHABILITATION::ERGOTHERAPY;
        case DeanerySpecialDirectionNSpecDirCode::SECTION_TOURISM_HOSPITALITY:
            return
                NCRB_011::_2009::NAME::SECTION::TOURISM_HOSPITALITY;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_PROMOTION:
            return
                NCRB_011::_2009::NAME::TOURISM_HOSPITALITY::PROMOTION;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_IT:
            return
                NCRB_011::_2009::NAME::TOURISM_HOSPITALITY::IT;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_LOGISTICS:
            return
                NCRB_011::_2009::NAME::TOURISM_HOSPITALITY::LOGISTICS;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SOCIAL:
            return
                NCRB_011::_2009::NAME::TOURISM_HOSPITALITY::SOCIAL;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TRANSPORT:
            return
                NCRB_011::_2009::NAME::TOURISM_HOSPITALITY::TRANSPORT;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_CATERING:
            return
                NCRB_011::_2009::NAME::TOURISM_HOSPITALITY::CATERING;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_ACCOMMODATION:
            return
                NCRB_011::_2009::NAME::TOURISM_HOSPITALITY::ACCOMMODATION;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SUPPORTING:
            return
                NCRB_011::_2009::NAME::TOURISM_HOSPITALITY::SUPPORTING;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TREATMENT:
            return
                NCRB_011::_2009::NAME::TOURISM_HOSPITALITY::TREATMENT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_THEORY:
            return
                NCRB_011::_2009::NAME::MASTER_DEGREE::SCIENCE::THEORY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_PHYSIOLOGY:
            return
                NCRB_011::_2009::NAME::MASTER_DEGREE::SCIENCE::PHYSIOLOGY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_SPORT:
            return
                NCRB_011::_2009::NAME::MASTER_DEGREE::RESEARCH::SPORT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TOURISM:
            return
                NCRB_011::_2009::NAME::MASTER_DEGREE::INNOVATION::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_HOSPITALITY:
            return
                NCRB_011::_2009::NAME::MASTER_DEGREE::INNOVATION::HOSPITALITY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TECHNOLOGY:
            return
                NCRB_011::_2009::NAME::MASTER_DEGREE::INNOVATION::TECHNO;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_MANAGEMENT:
            return
                NCRB_011::_2009::NAME::MASTER_DEGREE::INNOVATION::MANAGEMENT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_PHYSICAL_CULTURE_SPORT:
            return
                NCRB_011::_2009::NAME::MASTER_DEGREE::RESEARCH::SPORT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_TOURISM:
            return
                NCRB_011::_2009::NAME::MASTER_DEGREE::RESEARCH::TOURISM;

        default:
            ShowMessage (
                "ERROR:\n"                                                      \
                "The getKindOfSportNameDativeCase "                             \
                "(int deanerySpecialDirectionNSpecDirCode) method returns:\n"   \
                "Value: "                                                       +
                    AnsiString (deanerySpecialDirectionNSpecDirCode)            +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deanerySpecialDirectionNSpecDirCode
                );
    }
}
AnsiString ToDoLater::getQualificationName2009 (
        int deanerySpecialDirectionNSpecDirCode
    )
{
    switch (    static_cast <DeanerySpecialDirectionNSpecDirCode>
                (
                    deanerySpecialDirectionNSpecDirCode
                )
           )
    {
        case DeanerySpecialDirectionNSpecDirCode::SPORT_COACHING:
            return
                NCRB_011::_2009::QUALIFICATION::SPORT::COACHING;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_PSYCHOLOGY:
            return
                NCRB_011::_2009::QUALIFICATION::SPORT::PSYCHOLOGY;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_DIRECTING:
            return
                NCRB_011::_2009::QUALIFICATION::SPORT::DIRECTING;
        case DeanerySpecialDirectionNSpecDirCode::SPORT_MANAGEMENT:
            return
                NCRB_011::_2009::QUALIFICATION::SPORT::MANAGEMENT;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_RECREATIONAL:
            return
                NCRB_011::_2009::QUALIFICATION::TOURISM::RECREATIONAL;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_TUORISM_MNG:
            return
                NCRB_011::_2009::QUALIFICATION::TOURISM::TUORISM_MNG;
        case DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_MEDICAL:
            return
                NCRB_011::_2009::QUALIFICATION::PHYSICAL_CULTURE::MEDICAL;
        case DeanerySpecialDirectionNSpecDirCode::PHYSICAL_CULTURE_PRESCHOOLERS:
            return
                NCRB_011::_2009::QUALIFICATION::PHYSICAL_CULTURE::PRESCHOOLERS;
        case DeanerySpecialDirectionNSpecDirCode::IMPROVING_HEALTH:
            return
                NCRB_011::_2009::QUALIFICATION::IMPROVING::HEALTH;
        case DeanerySpecialDirectionNSpecDirCode::IMPROVING_ADAPTIVE:
            return
                NCRB_011::_2009::QUALIFICATION::IMPROVING::ADAPTIVE;
        case DeanerySpecialDirectionNSpecDirCode::REHABILITATION_REHABILITATION:
            return
                NCRB_011::_2009::QUALIFICATION::REHABILITATION::REHABILITATION;
        case DeanerySpecialDirectionNSpecDirCode::REHABILITATION_ERGOTHERAPY:
            return
                NCRB_011::_2009::QUALIFICATION::REHABILITATION::ERGOTHERAPY;
        case DeanerySpecialDirectionNSpecDirCode::SECTION_TOURISM_HOSPITALITY:
            return
                NCRB_011::_2009::QUALIFICATION::SUBSECTION::TRAINING;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_PROMOTION:
            return
                NCRB_011::_2009::QUALIFICATION::TOURISM_HOSPITALITY::PROMOTION;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_IT:
            return
                NCRB_011::_2009::QUALIFICATION::TOURISM_HOSPITALITY::IT;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_LOGISTICS:
            return
                NCRB_011::_2009::QUALIFICATION::TOURISM_HOSPITALITY::LOGISTICS;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SOCIAL:
            return
                NCRB_011::_2009::QUALIFICATION::TOURISM_HOSPITALITY::SOCIAL;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TRANSPORT:
            return
                NCRB_011::_2009::QUALIFICATION::TOURISM_HOSPITALITY::TRANSPORT;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_CATERING:
            return
                NCRB_011::_2009::QUALIFICATION::TOURISM_HOSPITALITY::CATERING;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_ACCOMMODATION:
            return
                NCRB_011::_2009::QUALIFICATION::TOURISM_HOSPITALITY::ACCOMMODATION;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_SUPPORTING:
            return
                NCRB_011::_2009::QUALIFICATION::TOURISM_HOSPITALITY::SUPPORTING;
        case DeanerySpecialDirectionNSpecDirCode::TOURISM_HOSPITALITY_TREATMENT:
            return
                NCRB_011::_2009::QUALIFICATION::TOURISM_HOSPITALITY::TREATMENT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_THEORY:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::SCIENCE::THEORY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_SCIENCE_PHYSIOLOGY:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::SCIENCE::PHYSIOLOGY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_SPORT:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::RESEARCH::SPORT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TOURISM:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::INNOVATION::TOURISM;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_HOSPITALITY:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::INNOVATION::HOSPITALITY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_TECHNOLOGY:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::INNOVATION::TECHNOLOGY;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_INNOVATION_MANAGEMENT:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::INNOVATION::MANAGEMENT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_PHYSICAL_CULTURE_SPORT:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::RESEARCH::SPORT;
        case DeanerySpecialDirectionNSpecDirCode::MASTER_RESEARCH_TOURISM:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::RESEARCH::TOURISM;

        default:
            ShowMessage (
                "ERROR:\n"                                                      \
                "The getQualificationName2009 "                                 \
                "(int deanerySpecialDirectionNSpecDirCode) method returns:\n"   \
                "Value: "                                                       +
                    AnsiString (deanerySpecialDirectionNSpecDirCode)            +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    deanerySpecialDirectionNSpecDirCode
                );
    }
}
AnsiString ToDoLater::getCodeSpecializByNSpesializ (
        int specialityCode
    )
{
    switch (static_cast <KindOfSportCode> (specialityCode))
    {
        case KindOfSportCode::GYMNASTICS:                        return "1";
        case KindOfSportCode::PHYSICAL_REHABILITATION:           return "11";
        case KindOfSportCode::THERAPEUTIC_PHYSICAL_CULTURE:      return "7";
        case KindOfSportCode::DANCE_SPORT:                       return "1";
        case KindOfSportCode::AEROBICS:                          return "1";
        case KindOfSportCode::ROWING_OTHER:                      return "1";
        case KindOfSportCode::SWIMMING:                          return "1";
        case KindOfSportCode::WINDAGE:                           return "1";
        case KindOfSportCode::ATHLETICS:                         return "1";
        case KindOfSportCode::CROSS_COUNTRY_SKIING:              return "1";
        case KindOfSportCode::HAND_TO_HAND_COMBAT:               return "1";
        case KindOfSportCode::TAEKWONDO:                         return "1";
        case KindOfSportCode::KARATE:                            return "1";
        case KindOfSportCode::MOTORSPORT:                        return "1";
        case KindOfSportCode::BASKETBALL:                        return "1";
        case KindOfSportCode::BOXING:                            return "1";
        case KindOfSportCode::BIKE:                              return "1";
        case KindOfSportCode::VOLLEYBALL:                        return "1";
        case KindOfSportCode::HANDBALL:                          return "1";
        case KindOfSportCode::EQUESTRIAN:                        return "1";
        case KindOfSportCode::SPEED_SKATING:                     return "1";
        case KindOfSportCode::TENNIS:                            return "1";
        case KindOfSportCode::WEIGHTLIFTING:                     return "1";
        case KindOfSportCode::FENCE:                             return "1";
        case KindOfSportCode::FIGURE_SKATING_OLD:                return "1";
        case KindOfSportCode::FOOTBALL:                          return "1";
        case KindOfSportCode::HOCKEY:                            return "1";
        case KindOfSportCode::WRESTLING:                         return "1";
        case KindOfSportCode::BIATHLON:                          return "1";
        case KindOfSportCode::HEALTH_IMPROVING_PHYSICAL_CULTURE: return "9";
        case KindOfSportCode::ADAPTIVE_PHYSICAL_EDUCATION:       return "10";
        case KindOfSportCode::FREESTYLE_WRESTLING:               return "1";
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:             return "1";
        case KindOfSportCode::SAMBO:                             return "1";
        case KindOfSportCode::JUDO:                              return "1";
        case KindOfSportCode::TABLE_TENNIS:                      return "П.";
        case KindOfSportCode::OCCUPATIONAL_THERAPY:              return "12";
        case KindOfSportCode::MANAGEMENT_IN_SPORTS:              return "4";
        case KindOfSportCode::SPORTS_AND_HEALTH_TOURISM:         return "5";
        case KindOfSportCode::TOURISM_MANAGEMENT:                return "6";
        case KindOfSportCode::SPORTS_PSYCHOLOGY:                 return "2";
        case KindOfSportCode::BILLIARD_SPORTS:                   return "1";
        case KindOfSportCode::ACROBATICS:                        return "1";
        case KindOfSportCode::ORIENTEERING:                      return "1";
        case KindOfSportCode::SPORTS_DIRECTING:                  return "3";
        case KindOfSportCode::PHYSICAL_CULTURE_OF_PRESCHOOLERS:  return "8";
        case KindOfSportCode::TOURISM_HOSPITALITY:               return "13";
        case KindOfSportCode::WUSHU:                             return "1";
        case KindOfSportCode::CHESS:                             return "1";
        case KindOfSportCode::THAI_BOXING:                       return "1";
        case KindOfSportCode::BULLET_SHOOTING:                   return "1";
        case KindOfSportCode::FIELD_HOCKEY:                      return "1";
        case KindOfSportCode::FIGURE_SKATING:                    return "1";
        case KindOfSportCode::ROWING_AND_CANOEING:               return "1";
        case KindOfSportCode::ROWING:                            return "1";
        case KindOfSportCode::WITHOUT_SPECIALIZATION:            return "1";
        case KindOfSportCode::MODERN_PENTATHLON:                 return "1";
        case KindOfSportCode::BADMINTON:                         return "1";
        case KindOfSportCode::SPORT_CLIMBING:                    return "1";

        default:
            ShowMessage (
                "ERROR:\n"                                  \
                "The getCodeSpecializ "                     \
                "(int specialityCode) method returns:\n"    \
                "Value: "                                   +
                    AnsiString (specialityCode)             +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    specialityCode
                );
    }
}
AnsiString ToDoLater::getDirectionNameByNSpecializ (
        int specialityCode
    )
{
    switch (static_cast <KindOfSportCode> (specialityCode))
    {
        case KindOfSportCode::GYMNASTICS:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по гимнастике)";
        case KindOfSportCode::PHYSICAL_REHABILITATION:
            return
                "Физическая реабилитация и эрготерапия "                    \
                "(физическая реабилитация)";
        case KindOfSportCode::THERAPEUTIC_PHYSICAL_CULTURE:
            return
                "Физическая культура (лечебная)";
        case KindOfSportCode::DANCE_SPORT:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по танцевальному спорту)";
        case KindOfSportCode::AEROBICS:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по аэробике)";
        case KindOfSportCode::ROWING_OTHER:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по гребному спорту)";
        case KindOfSportCode::SWIMMING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по плаванию)";
        case KindOfSportCode::WINDAGE:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по парусному спорту)";
        case KindOfSportCode::ATHLETICS:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по легкой атлетике)";
        case KindOfSportCode::CROSS_COUNTRY_SKIING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по лыжным гонкам)";
        case KindOfSportCode::HAND_TO_HAND_COMBAT:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по рукопашному бою)";
        case KindOfSportCode::TAEKWONDO:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по таэквондо)";
        case KindOfSportCode::KARATE:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по каратэ)";
        case KindOfSportCode::MOTORSPORT:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по автомобильному спорту)";
        case KindOfSportCode::BASKETBALL:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по баскетболу)";
        case KindOfSportCode::BOXING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по боксу)";
        case KindOfSportCode::BIKE:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по велосипедному спорту)";
        case KindOfSportCode::VOLLEYBALL:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по волейболу)";
        case KindOfSportCode::HANDBALL:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по гандболу)";
        case KindOfSportCode::EQUESTRIAN:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по конному спорту)";
        case KindOfSportCode::SPEED_SKATING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по конькобежному спорту)";
        case KindOfSportCode::TENNIS:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по теннису)";
        case KindOfSportCode::WEIGHTLIFTING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по тяжелой атлетике)";
        case KindOfSportCode::FENCE:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по фехтованию)";
        case KindOfSportCode::FIGURE_SKATING_OLD:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по фигурному катанию)";
        case KindOfSportCode::FOOTBALL:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по футболу)";
        case KindOfSportCode::HOCKEY:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по хоккею)";
        case KindOfSportCode::WRESTLING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по спортивной борьбе)";
        case KindOfSportCode::BIATHLON:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по биатлону)";
        case KindOfSportCode::HEALTH_IMPROVING_PHYSICAL_CULTURE:
            return
                "Оздоровительная и адаптивная физическая "                  \
                "культура (оздоровительная)";
        case KindOfSportCode::ADAPTIVE_PHYSICAL_EDUCATION:
            return
                "Оздоровительная и адаптивная физическая "                  \
                "культура (адаптивная)";
        case KindOfSportCode::FREESTYLE_WRESTLING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по вольной борьбе)";
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по греко-римской борьбе)";
        case KindOfSportCode::SAMBO:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по самбо)";
        case KindOfSportCode::JUDO:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по дзюдо)";
        case KindOfSportCode::TABLE_TENNIS:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по теннису настольному)";
        case KindOfSportCode::OCCUPATIONAL_THERAPY:
            return
                "Физическая реабилитация и эрготерапия "                    \
                "(эрготерапия)";
        case KindOfSportCode::MANAGEMENT_IN_SPORTS:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(менеджмент в спорте)";
        case KindOfSportCode::SPORTS_AND_HEALTH_TOURISM:
            return
                "Спортивно-туристская деятельность "                        \
                "(спортивный и рекреационный туризм)";
        case KindOfSportCode::TOURISM_MANAGEMENT:
            return
                "Спортивно-туристская деятельность "                        \
                "(менеджмент в туризме)";
        case KindOfSportCode::SPORTS_PSYCHOLOGY:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(спортивная психология)";
        case KindOfSportCode::BILLIARD_SPORTS:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по бильярдному спорту)";
        case KindOfSportCode::ACROBATICS:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по акробатике)";
        case KindOfSportCode::ORIENTEERING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по спортивному ориентированию)";
        case KindOfSportCode::SPORTS_DIRECTING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(спортивная режиссура)";
        case KindOfSportCode::PHYSICAL_CULTURE_OF_PRESCHOOLERS:
            return
                "Физическая культура (дошкольников)";
        case KindOfSportCode::TOURISM_HOSPITALITY:
            return
                "Туризм и гостеприимство";
        case KindOfSportCode::WUSHU:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по Ушу)";
        case KindOfSportCode::CHESS:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по шахматам)";
        case KindOfSportCode::THAI_BOXING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по таиландскому боксу)";
        case KindOfSportCode::BULLET_SHOOTING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по стрельбе пулевой)";
        case KindOfSportCode::FIELD_HOCKEY:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по хоккею на траве)";
        case KindOfSportCode::FIGURE_SKATING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по фигурному катанию на коньках)";
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по гребле на байдарках и каноэ)";
        case KindOfSportCode::ROWING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по гребле академической)";
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                "Спортивно-педагогическая деятельность";
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по современному пятиборью)";
        case KindOfSportCode::BADMINTON:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по бадминтону)";
        case KindOfSportCode::SPORT_CLIMBING:
            return
                "Спортивно-педагогическая деятельность "                    \
                "(тренерская работа по скалолазанию спортивному)";

        default:
            ShowMessage (
                "ERROR:\n"                                  \
                "The KindOfSportCodeToDirectionName "    \
                "(int specialityCode) method returns:\n"    \
                "Value: "                                   +
                    AnsiString (specialityCode)             +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    specialityCode
                );
    }
}
AnsiString ToDoLater::getDirectionShortName (
        int specialityCode
    )
{
    switch (static_cast <KindOfSportCode> (specialityCode))
    {
        case KindOfSportCode::GYMNASTICS:                        return "Тренерская работа по гимнастике";
        case KindOfSportCode::PHYSICAL_REHABILITATION:           return "Физическая реабилитация";
        case KindOfSportCode::THERAPEUTIC_PHYSICAL_CULTURE:      return "Лечебная физическая культура";
        case KindOfSportCode::DANCE_SPORT:                       return "Тренерская работа по танцевальному спорту";
        case KindOfSportCode::AEROBICS:                          return "Тренерская работа по аэробике";
        case KindOfSportCode::ROWING_OTHER:                      return "Тренерская работа по гребному спорту";
        case KindOfSportCode::SWIMMING:                          return "Тренерская работа по плаванию";
        case KindOfSportCode::WINDAGE:                           return "Тренерская работа по парусному спорту";
        case KindOfSportCode::ATHLETICS:                         return "Тренерская работа по легкой атлетике";
        case KindOfSportCode::CROSS_COUNTRY_SKIING:              return "Тренерская работа по лыжным гонкам";
        case KindOfSportCode::HAND_TO_HAND_COMBAT:               return "Тренерская работа по рукопашному бою";
        case KindOfSportCode::TAEKWONDO:                         return "Тренерская работа по таэквондо";
        case KindOfSportCode::KARATE:                            return "Тренерская работа по каратэ";
        case KindOfSportCode::MOTORSPORT:                        return "Тренерская работа по автомобильному спорту";
        case KindOfSportCode::BASKETBALL:                        return "Тренерская работа по баскетболу";
        case KindOfSportCode::BOXING:                            return "Тренерская работа по боксу";
        case KindOfSportCode::BIKE:                              return "Тренерская работа по велосипедному спорту";
        case KindOfSportCode::VOLLEYBALL:                        return "Тренерская работа по волейболу";
        case KindOfSportCode::HANDBALL:                          return "Тренерская работа по гандболу";
        case KindOfSportCode::EQUESTRIAN:                        return "Тренерская работа по конному спорту";
        case KindOfSportCode::SPEED_SKATING:                     return "Тренерская работа по конькобежному спорту";
        case KindOfSportCode::TENNIS:                            return "Тренерская работа по теннису";
        case KindOfSportCode::WEIGHTLIFTING:                     return "Тренерская работа по тяжелой атлетике";
        case KindOfSportCode::FENCE:                             return "Тренерская работа по фехтованию";
        case KindOfSportCode::FIGURE_SKATING_OLD:                return "Тренерская работа по фигурному катанию на коньках";
        case KindOfSportCode::FOOTBALL:                          return "Тренерская работа по футболу";
        case KindOfSportCode::HOCKEY:                            return "Тренерская работа по хоккею";
        case KindOfSportCode::WRESTLING:                         return "Тренерская работа по спортивной борьбе";
        case KindOfSportCode::BIATHLON:                          return "Тренерская работа по биатлону";
        case KindOfSportCode::HEALTH_IMPROVING_PHYSICAL_CULTURE: return "Оздоровительная физическая культура";
        case KindOfSportCode::ADAPTIVE_PHYSICAL_EDUCATION:       return "Адаптивная физическая культура";
        case KindOfSportCode::FREESTYLE_WRESTLING:               return "Тренерская работа по вольной борьбе";
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:             return "Тренерская работа по греко-римской борьбе";
        case KindOfSportCode::SAMBO:                             return "Тренерская работа по самбо";
        case KindOfSportCode::JUDO:                              return "Тренерская работа по дзюдо";
        case KindOfSportCode::TABLE_TENNIS:                      return "Тренерская работа по теннису настольному";
        case KindOfSportCode::OCCUPATIONAL_THERAPY:              return "Эрготерапия";
        case KindOfSportCode::MANAGEMENT_IN_SPORTS:              return "Менеджмент в спорте";
        case KindOfSportCode::SPORTS_AND_HEALTH_TOURISM:         return "Спортивный и рекреационный туризм";
        case KindOfSportCode::TOURISM_MANAGEMENT:                return "Менеджмент в туризме";
        case KindOfSportCode::SPORTS_PSYCHOLOGY:                 return "Спортивная психология";
        case KindOfSportCode::BILLIARD_SPORTS:                   return "Тренерская работа по бильярдному спорту";
        case KindOfSportCode::ACROBATICS:                        return "Тренерская работа по акробатике";
        case KindOfSportCode::ORIENTEERING:                      return "Тренерская работа по спортивному ориентированию";
        case KindOfSportCode::SPORTS_DIRECTING:                  return "Спортивная режиссура";
        case KindOfSportCode::PHYSICAL_CULTURE_OF_PRESCHOOLERS:  return "Физическая культура дошкольников";
        case KindOfSportCode::TOURISM_HOSPITALITY:               return "Туризм и гостеприимство";
        case KindOfSportCode::WUSHU:                             return "Тренерская работа по Ушу";
        case KindOfSportCode::CHESS:                             return "Тренерская работа по шахматам";
        case KindOfSportCode::THAI_BOXING:                       return "Тренерская работа по таиландскому боксу";
        case KindOfSportCode::BULLET_SHOOTING:                   return "Тренерская работа по стрельбе пулевой";
        case KindOfSportCode::FIELD_HOCKEY:                      return "Тренерская работа по хоккею на траве";
        case KindOfSportCode::FIGURE_SKATING:                    return "Тренерская работа по фигурному катанию на коньках";
        case KindOfSportCode::ROWING_AND_CANOEING:               return "Тренерская работа по гребле на байдарках и каноэ";
        case KindOfSportCode::ROWING:                            return "Тренерская работа по гребле академической";
        case KindOfSportCode::WITHOUT_SPECIALIZATION:            return "-";
        case KindOfSportCode::MODERN_PENTATHLON:                 return "Тренерская работа по современному пятиборью";
        case KindOfSportCode::BADMINTON:                         return "Тренерская работа по бадминтону";
        case KindOfSportCode::SPORT_CLIMBING:                    return "Тренерская работа по скалолазанию спортивному";

        default:
            ShowMessage (
                "ERROR:\n"                                      \
                "The KindOfSportCodeToDirectionShortName "   \
                "(int specialityCode) method returns:\n"        \
                "Value: "                                       +
                    AnsiString (specialityCode)                 +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    specialityCode
                );
    }
}
*/
