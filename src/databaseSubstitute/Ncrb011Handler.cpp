#include <vcl.h>
#pragma hdrstop


#include "Ncrb011Handler.h"


#pragma package (smart_init)



// get CODE
AnsiString InsteadDb::getNcrb2009CodeByNSpecializ (const int nSpecializ)        // e.g. nSpecializ: 47 -> "1-88 01 03-02"
{
    return
        getNcrb2009CodeByNSpecDir (                                             // e.g. nSpecDir: 12 -> "1-88 01 03-02"
            getProfilingCodeByNSpecializ (                                      // e.g. nSpecializ: 47 -> 12
                nSpecializ
            )
        );
}
AnsiString InsteadDb::getNcrb2022CodeByNSpecializ (const int nSpecializ)        // e.g. nSpecializ: 3 -> "6-05-1012-03"
{
    return
        getNcrb2022CodeByNSpecDir (                                             // e.g. nSpecDir: 11 -> "6-05-1012-03"
            getProfilingCodeByNSpecializ (                                      // e.g. nSpecializ: 3 -> 11
                nSpecializ
            )
        );
}
AnsiString InsteadDb::getNcrb2022CodeByNSpecializFH (const int nSpecializ)
{
    return
        getNcrb2022CodeByNSpecializ1stHand (
            nSpecializ
        );
}
// get NAME
AnsiString InsteadDb::getNcrb2009FullNameByNSpecializ (const int nSpecializ)
{
    return
            getNcrb2009CodeByNSpecializ      (nSpecializ)   +
        " "                                                 +
            getProfiling2009NameByNSpecializ (nSpecializ);
}
AnsiString InsteadDb::getNcrb2022FullNameByNSpecializ (const int nSpecializ)
{
    return
            getNcrb2022CodeByNSpecializ      (nSpecializ)   +
        " "                                                 +
            getProfiling2022NameByNSpecializ (nSpecializ);
}
AnsiString InsteadDb::getProfiling2009NameByNSpecializ (const int nSpecializ)   // e.g. nSpecializ: 69 -> "Спортивно-педагогическая деятельность (тренерская работа по таиландскому боксу)
{
    AnsiString profilingPart;

    int nSpecDir = getProfilingCodeByNSpecializ (nSpecializ);                   // e.g. nSpecializ: 69 -> 1

    if (nSpecDir == ProfilingCode::NSPECDIR_SPORT_COACHING)                     // (1 == 1) -> true
        profilingPart =
                getProfiling2009NameByNSpecDir      (nSpecDir)      +           // e.g. nSpecDir: 1 -> "Тренерская работа по"
            " "                                                     +           // " "
                getKindOfSportDativeCaseForCoaching (nSpecializ);               // e.g. nSpecializ: 69 -> "таиландскому боксу"
    else
        profilingPart =
                getProfiling2009NameByNSpecDir (nSpecDir);

    return
        escapingStringWithDoubleQuotes (
                getSection2009NameByNspecializ (nSpecializ)         +           // e.g. nSpecializ: 42 -> "Спортивно-педагогическая деятельность"
            " "                                                     +           // " "
                profilingToPostfix             (profilingPart)                  // e.g. profilingPart: "Тренерская работа по таиландскому боксу" -> "(тренерская работа по таиландскому боксу)"
        );
}
AnsiString InsteadDb::getProfiling2022NameByNSpecializ (const int nSpecializ)   // e.g. nSpecializ: 42 -> "Тренерская деятельность (вольная борьба)"; 39 -> "Физическая культура (адаптивная физическая культура)"
{
    int nSpecDir = getProfilingCodeByNSpecializ (nSpecializ);                   // e.g. nSpecializ: 42 -> 1; 39 -> 10

    if (nSpecDir == ProfilingCode::NSPECDIR_SPORT_COACHING)                     // (1 == 1) -> true; (1 == 10) -> false
        return
                getProfiling2022NameByNSpecDir (nSpecDir)    +                  // e.g. nSpecDir: 1 -> "Тренерская деятельность"
            " "                                              +                  // " "
                getKindOfSportAsPostfix (nSpecializ);                           // e.g. nSpecializ: 42 -> "(вольная борьба)"
    else
        return
            getProfiling2022NameByNSpecDir (nSpecDir);                          // e.g. nSpecDir: 10 -> "Физическая культура (адаптивная физическая культура)",
}
AnsiString InsteadDb::getSection2009NameByNspecializ (const int nSpecializ)
{
    return
        getSection2009NameByNSpec (
            getSectionCodeByNSpecializ (nSpecializ)
        );
}
AnsiString InsteadDb::getSection2022CodeNameById (const int id)
{
    return
            getNcrb2022CodeById (id)        +
        " "                                 +
            escapingStringWithDoubleQuotes (
                getSection2022NameById (id)
            );
}
// get KIND OF SPORT
AnsiString InsteadDb::getKindOfSportAsPostfix (const int nSpecializ)
{
    return
        escapingStringWithParentheses (
            getKindOfSportNameByNSpecializ (nSpecializ)
                .LowerCase ()
        );
}
AnsiString InsteadDb::getKindOfSportDativeCaseForCoaching (const int nSpecializ)
{
    return
        getKindOfSportNameDativeCaseByNSpecializ (nSpecializ)
            .LowerCase ();
}
// get GRADE
AnsiString InsteadDb::getQualification2009NameByNSpecializ (const int nSpecializ)
{
    return
        getQualification2009NameByNSpecDir (
            getProfilingCodeByNSpecializ (
                nSpecializ
            )
        );
}
AnsiString InsteadDb::getQualification2022NameByNSpecializ (const int nSpecializ)
{
    return
        getQualification2022NameByNSpecDir (
            getProfilingCodeByNSpecializ (
                nSpecializ
            )
        );
}


// AUXILIARY
AnsiString InsteadDb::escapingStringWithDoubleQuotes (const AnsiString wrappingString)
{
    return
        "«"                 +
            wrappingString  +
        "»";
}
AnsiString InsteadDb::escapingStringWithParentheses (const AnsiString wrappingString)
{
    return
        "("                 +
            wrappingString  +
        ")";
}
AnsiString InsteadDb::profilingToPostfix (const AnsiString profiling)
{
    return
        escapingStringWithParentheses (
            profiling.LowerCase ()
        );
}


// CONTROL
int        InsteadDb::getProfilingCodeByNSpecializ (const int nSpecializ)
{
    switch (static_cast <KindOfSportCode> (nSpecializ))
    {
        case KindOfSportCode::GYMNASTICS:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::MANAGEMENT_SPORTS_TOURISM:
            return
                ProfilingCode::NSPECDIR_MANAGEMENT_TOURISM_MNG;                 // 6,
        case KindOfSportCode::PHYSICAL_REHABILITATION:
            return
                ProfilingCode::NSPECDIR_REHABILITATION_REHABILITATION;          // 11,
        case KindOfSportCode::THERAPEUTIC:
            return
                ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_MEDICAL;               // 7,
        case KindOfSportCode::ORGANIZATION_SPORTS_TOURISM:
            return
                ProfilingCode::NSPECDIR_IMPROVING_HEALTH;                       // 9,
        case KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION:
            return
                ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS;          // 8,
        case KindOfSportCode::DANCE_SPORT:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::AEROBICS:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::ROWING_OTHER:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::SWIMMING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::SAILING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::ATHLETICS:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::CROSS_COUNTRY_SKIING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::BULLET_SHOOTING_DEANERY:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::HAND_TO_HAND_COMBAT:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::TAEKWONDO:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::KARATE:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::SKIING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::AUTOMOTIVE_SPORT:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::BASKETBALL:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::BOXING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::GRECO_FREESTYLE_WRESTLING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::CYCLING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::VOLLEYBALL:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::HANDBALL:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::EQUESTRIAN:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::SPEED_SKATING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::TENNIS:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::WEIGHTLIFTING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::FENCING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::FIGURE_SKATING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::FOOTBALL:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::HOCKEY:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::WRESTLING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::BIATHLON:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::HEALTH_IMPROVING:
            return
                ProfilingCode::NSPECDIR_IMPROVING_HEALTH;                       // 9,
        case KindOfSportCode::ADAPTIVE:
            return
                ProfilingCode::NSPECDIR_IMPROVING_ADAPTIVE;                     // 10,
        case KindOfSportCode::FREESTYLE_WRESTLING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::SAMBO:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::JUDO:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::TABLE_TENNIS:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::ERGOTHERAPY:
            return
                ProfilingCode::NSPECDIR_REHABILITATION_ERGOTHERAPY;             // 12,
        case KindOfSportCode::MANAGEMENT_SPORTS:
            return
                ProfilingCode::NSPECDIR_SPORT_MANAGEMENT;                       // 4,
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM:
            return
                ProfilingCode::NSPECDIR_MANAGEMENT_RECREATIONAL;                // 5,
        case KindOfSportCode::MANAGEMENT_TOURISM:
            return
                ProfilingCode::NSPECDIR_MANAGEMENT_TOURISM_MNG;                 // 6,
        case KindOfSportCode::SPORTS_PSYCHOLOGY:
            return
                ProfilingCode::NSPECDIR_SPORT_PSYCHOLOGY;                       // 2,
        case KindOfSportCode::BILLIARD_SPORTS:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::ACROBATICS:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::ORIENTEERING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::SPORTS_DIRECTING:
            return
                ProfilingCode::NSPECDIR_SPORT_DIRECTING;                        // 3,
        case KindOfSportCode::PRESCHOOLERS:
            return
                ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS;          // 8,
        case KindOfSportCode::MOUNTAINEERING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::SKI_COMBINED:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::TOURISM_HOSPITALITY:
            return
                ProfilingCode::NSPECDIR_TOURISM_HOSPITALITY;                    // 13,
        case KindOfSportCode::WATER_TECHNICAL_SPORTS:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::MODEL_TECHNICAL_SPORTS:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::ALPINE_SKIING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::BASEBALL:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::WUSHU:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::CHESS:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::THAI_BOXING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::TOURISM_PROMOTION:
            return
                ProfilingCode::NSPECDIR_TOURISM_PROMOTION;                      // 14,
        case KindOfSportCode::TOURISM_IT:
            return
                ProfilingCode::NSPECDIR_TOURISM_IT;                             // 15,
        case KindOfSportCode::TOURISM_LOGISTICS:
            return
                ProfilingCode::NSPECDIR_TOURISM_LOGISTICS;                      // 16,
        case KindOfSportCode::TOURISM_SOCIAL:
            return
                ProfilingCode::NSPECDIR_TOURISM_SOCIAL;                         // 17,
        case KindOfSportCode::TOURISM_TRANSPORT:
            return
                ProfilingCode::NSPECDIR_TOURISM_TRANSPORT;                      // 18,
        case KindOfSportCode::TOURISM_FOOD:
            return
                ProfilingCode::NSPECDIR_TOURISM_CATERING;                       // 19,
        case KindOfSportCode::TOURIST_ACCOMMODATION:
            return
                ProfilingCode::NSPECDIR_TOURISM_ACCOMMODATION;                  // 20,
        case KindOfSportCode::TOURISM_EXCURSION:
            return
                ProfilingCode::NSPECDIR_TOURISM_SUPPORTING;                     // 21,
        case KindOfSportCode::TOURISM_HEALTH:
            return
                ProfilingCode::NSPECDIR_TOURISM_TREATMENT;                      // 22,
        case KindOfSportCode::BULLET_SHOOTING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::FIELD_HOCKEY:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::FIGURE_SKATING_SKATES:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::ACADEMIC_ROWING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::HAND_TO_HAND_MARTIAL_ARTS:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::BILLIARDS:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::SCIENCE_HEALTH:
            return
                ProfilingCode::NSPECDIR_MASTER_SCIENCE_THEORY;                  // 23,
        case KindOfSportCode::PHYSIOLOGY:
            return
                ProfilingCode::NSPECDIR_MASTER_SCIENCE_PHYSIOLOGY;              // 24,
        case KindOfSportCode::SCIENCE_THEORY:
            return
                ProfilingCode::NSPECDIR_MASTER_SCIENCE_THEORY;                  // 23,
        case KindOfSportCode::RECEARCH_SPORT:
            return
                ProfilingCode::NSPECDIR_MASTER_RESEARCH_SPORT;                  // 25,
        case KindOfSportCode::INNOVATIVE_TOURISM:
            return
                ProfilingCode::NSPECDIR_MASTER_INNOVATION_TOURISM;              // 26,
        case KindOfSportCode::INNOVATIVE_HOSPITALITY:
            return
                ProfilingCode::NSPECDIR_MASTER_INNOVATION_HOSPITALITY;          // 27,
        case KindOfSportCode::INNOVATIVE_TECHNOLOGIES:
            return
                ProfilingCode::NSPECDIR_MASTER_INNOVATION_TECHNOLOGY;           // 28,
        case KindOfSportCode::INNOVATIVE_MANAGEMENT:
            return
                ProfilingCode::NSPECDIR_MASTER_INNOVATION_MANAGEMENT;           // 29,
        case KindOfSportCode::BADMINTON:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::PHYSICAL_CULTURE_SPORT:
            return
                ProfilingCode::NSPECDIR_MASTER_RESEARCH_PHYSICAL_CULTURE;       // 31,
        case KindOfSportCode::TOURISM_HOSPITALITY_MASTER:
            return
                ProfilingCode::NSPECDIR_MASTER_RESEARCH_TOURISM;                // 32
        case KindOfSportCode::SPORT_CLIMBING:
            return
                ProfilingCode::NSPECDIR_SPORT_COACHING;                         // 1,
        case KindOfSportCode::MASTER_ANTHROPOLOGY:
            return
                ProfilingCode::NSPECDIR_MASTER_RESEARCH_SPORT;                  // 25,
        case KindOfSportCode::MASTER_MANAGEMENT:
            return
                ProfilingCode::NSPECDIR_MASTER_RESEARCH_MANAGEMENT;             // 30,

        default:
            ShowMessage (
                "ERROR:\n"                              \
                "The getProfilingCodeByNSpecializ "     \
                "(int nSpecializ) method returns:\n"    \
                "Value: "                               +
                    AnsiString (nSpecializ)             +
                "\t - The code does not exist!"
            );
            return
                nSpecializ;
    }
}
int        InsteadDb::getSectionCodeByNSpecializ (const int nSpecializ)
{
    switch (static_cast <KindOfSportCode> (nSpecializ))
    {
        case KindOfSportCode::GYMNASTICS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::MANAGEMENT_SPORTS_TOURISM:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 7,  -> "Спортивно-туристская деятельность (по направлениям)"
        case KindOfSportCode::PHYSICAL_REHABILITATION:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_REHABILITATION;                  // 9,  -> "Физическая реабилитация и эрготерапия (по направлениям)"
        case KindOfSportCode::THERAPEUTIC:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_PHYSICAL_CULTURE;                // 8,  -> "Физическая культура (по направлениям)"
        case KindOfSportCode::ORGANIZATION_SPORTS_TOURISM:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_IMPROVING;                       // 5,  -> "Оздоровительная и адаптивная физическая культура (по направлениям)"
        case KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_PHYSICAL_CULTURE;                // 8,  -> "Физическая культура (по направлениям)"
        case KindOfSportCode::DANCE_SPORT:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::AEROBICS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::ROWING_OTHER:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::SWIMMING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::SAILING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::ATHLETICS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::CROSS_COUNTRY_SKIING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::BULLET_SHOOTING_DEANERY:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::HAND_TO_HAND_COMBAT:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::TAEKWONDO:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::KARATE:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::SKIING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::AUTOMOTIVE_SPORT:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::BASKETBALL:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::BOXING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::GRECO_FREESTYLE_WRESTLING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::CYCLING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::VOLLEYBALL:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::HANDBALL:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::EQUESTRIAN:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::SPEED_SKATING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::TENNIS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::WEIGHTLIFTING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::FENCING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::FIGURE_SKATING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::FOOTBALL:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::HOCKEY:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::WRESTLING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::BIATHLON:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::HEALTH_IMPROVING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_IMPROVING;                       // 5,  -> "Оздоровительная и адаптивная физическая культура (по направлениям)"
        case KindOfSportCode::ADAPTIVE:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_IMPROVING;                       // 5,  -> "Оздоровительная и адаптивная физическая культура (по направлениям)"
        case KindOfSportCode::FREESTYLE_WRESTLING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::SAMBO:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::JUDO:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::TABLE_TENNIS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::ERGOTHERAPY:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_REHABILITATION;                  // 9,  -> "Физическая реабилитация и эрготерапия (по направлениям)"
        case KindOfSportCode::MANAGEMENT_SPORTS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 7,  -> "Спортивно-туристская деятельность (по направлениям)"
        case KindOfSportCode::MANAGEMENT_TOURISM:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 7,  -> "Спортивно-туристская деятельность (по направлениям)"
        case KindOfSportCode::SPORTS_PSYCHOLOGY:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::BILLIARD_SPORTS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::ACROBATICS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::ORIENTEERING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::SPORTS_DIRECTING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::PRESCHOOLERS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_PHYSICAL_CULTURE;                // 8,  -> "Физическая культура (по направлениям)"
        case KindOfSportCode::MOUNTAINEERING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::SKI_COMBINED:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::TOURISM_HOSPITALITY:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT;                      // 10, -> "Туризм и гостеприимство"
        case KindOfSportCode::WATER_TECHNICAL_SPORTS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::MODEL_TECHNICAL_SPORTS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::ALPINE_SKIING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::BASEBALL:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::WUSHU:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::CHESS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::THAI_BOXING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::TOURISM_PROMOTION:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT;                      // 10, -> "Туризм и гостеприимство"
        case KindOfSportCode::TOURISM_IT:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT;                      // 10, -> "Туризм и гостеприимство"
        case KindOfSportCode::TOURISM_LOGISTICS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT;                      // 10, -> "Туризм и гостеприимство"
        case KindOfSportCode::TOURISM_SOCIAL:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT;                      // 10, -> "Туризм и гостеприимство"
        case KindOfSportCode::TOURISM_TRANSPORT:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT;                      // 10, -> "Туризм и гостеприимство"
        case KindOfSportCode::TOURISM_FOOD:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT;                      // 10, -> "Туризм и гостеприимство"
        case KindOfSportCode::TOURIST_ACCOMMODATION:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT;                      // 10, -> "Туризм и гостеприимство"
        case KindOfSportCode::TOURISM_EXCURSION:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT;                      // 10, -> "Туризм и гостеприимство"
        case KindOfSportCode::TOURISM_HEALTH:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT;                      // 10, -> "Туризм и гостеприимство"
        case KindOfSportCode::BULLET_SHOOTING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::FIELD_HOCKEY:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::FIGURE_SKATING_SKATES:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::ACADEMIC_ROWING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::HAND_TO_HAND_MARTIAL_ARTS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::BILLIARDS:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::SCIENCE_HEALTH:
            return
                SectionCode::NSPEC_MASTER_SCIENCE_THEORY;                       // 11, -> "Теория и методика физического воспитания, спортивной тренировки, оздоровительной"
        case KindOfSportCode::PHYSIOLOGY:
            return
                SectionCode::NSPEC_MASTER_SCIENCE_PHYSIOLOGY;                   // 12, -> "Физиология"
        case KindOfSportCode::SCIENCE_THEORY:
            return
                SectionCode::NSPEC_MASTER_SCIENCE_THEORY;                       // 11, -> "Теория и методика физического воспитания, спортивной тренировки, оздоровительной"
        case KindOfSportCode::RECEARCH_SPORT:
            return
                SectionCode::NSPEC_MASTER_RESEARCH_SPORT;                       // 13, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной ФК"
        case KindOfSportCode::INNOVATIVE_TOURISM:
            return
                SectionCode::NSPEC_MASTER_INNOVATION_TOURISM;                   // 14, -> "инновационный менеджмент в сфере туризма"
        case KindOfSportCode::INNOVATIVE_HOSPITALITY:
            return
                SectionCode::NSPEC_MASTER_INNOVATION_HOSPITALITY;               // 15, -> "инновационный менеджмент в сфере гостеприимства"
        case KindOfSportCode::INNOVATIVE_TECHNOLOGIES:
            return
                SectionCode::NSPEC_MASTER_INNOVATION_TECHNOLOGY;                // 16, -> "инновационные технологии в сфере туризма и гостеприимства"
        case KindOfSportCode::INNOVATIVE_MANAGEMENT:
            return
                SectionCode::NSPEC_MASTER_INNOVATION_MANAGEMENT;                // 17, -> "управление инновационными проектами в туристской индустрии"
        case KindOfSportCode::BADMINTON:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::PHYSICAL_CULTURE_SPORT:
            return
                SectionCode::NSPEC_MASTER_RESEARCH_PHYSICAL_CULTURE;            // 18, -> "физическая культура и спорт"
        case KindOfSportCode::TOURISM_HOSPITALITY_MASTER:
            return
                SectionCode::NSPEC_MASTER_RESEARCH_TOURISM;                     // 19, -> "туризм и гостеприимство"
        case KindOfSportCode::SPORT_CLIMBING:
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность (по направлениям)"
        case KindOfSportCode::MASTER_ANTHROPOLOGY:
            return
                SectionCode::NSPEC_MASTER_RESEARCH_SPORT;                       // 13, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной ФК"
        case KindOfSportCode::MASTER_MANAGEMENT:
            return
                SectionCode::NSPEC_MASTER_RESEARCH_MANAGEMENT;                  // 20  -> "Менеджмент"

        default:
            ShowMessage (
                "ERROR:\n"                              \
                "The getSectionCodeByNSpecializ "       \
                "(int nSpecializ) method returns:\n"    \
                "Value: "                               +
                    AnsiString (nSpecializ)             +
                "\t - The code does not exist!"
            );
            return
                nSpecializ;
    }
}
int        InsteadDb::getSectionCodeByNSpecDir (const int nSpecDir)
{
    switch (static_cast <ProfilingCode> (nSpecDir))
    {
        case ProfilingCode::NSPECDIR_SPORT_COACHING:                            // 1,  -> "Тренерская работа по",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность"                (по направлениям)
        case ProfilingCode::NSPECDIR_SPORT_PSYCHOLOGY:                          // 2,  -> "Спортивная психология",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность"                (по направлениям)
        case ProfilingCode::NSPECDIR_SPORT_DIRECTING:                           // 3,  -> "Спортивная режиссура",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность"                (по направлениям)
        case ProfilingCode::NSPECDIR_SPORT_MANAGEMENT:                          // 4,  -> "Менеджмент в спорте",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность"                (по направлениям)
        case ProfilingCode::NSPECDIR_MANAGEMENT_RECREATIONAL:                   // 5,  -> "Спортивный и рекреационный туризм",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT;                      // 7,  -> "Спортивно-туристская деятельность"                    (по направлениям)
        case ProfilingCode::NSPECDIR_MANAGEMENT_TOURISM_MNG:                    // 6,  -> "Менеджмент в туризме",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT;                      // 7,  -> "Спортивно-туристская деятельность"                    (по направлениям)
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_MEDICAL:                  // 7,  -> "Лечебная",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_PHYSICAL_CULTURE;                // 8,  -> "Физическая культура"                                  (по направлениям)
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS:             // 8,  -> "Дошкольников",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_PHYSICAL_CULTURE;                // 8,  -> "Физическая культура"                                  (по направлениям)
        case ProfilingCode::NSPECDIR_IMPROVING_HEALTH:                          // 9,  -> "Оздоровительная",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_IMPROVING;                       // 5,  -> "Оздоровительная и адаптивная физическая культура"     (по направлениям)
        case ProfilingCode::NSPECDIR_IMPROVING_ADAPTIVE:                        // 10, -> "Адаптивная",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_IMPROVING;                       // 5,  -> "Оздоровительная и адаптивная физическая культура"     (по направлениям)
        case ProfilingCode::NSPECDIR_REHABILITATION_REHABILITATION:             // 11, -> "Физическая реабилитация",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_REHABILITATION;                  // 9,  -> "Физическая реабилитация и эрготерапия"                (по направлениям)
        case ProfilingCode::NSPECDIR_REHABILITATION_ERGOTHERAPY:                // 12, -> "Эрготерапия",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_REHABILITATION;                  // 9,  -> "Физическая реабилитация и эрготерапия"                (по направлениям)
        case ProfilingCode::NSPECDIR_TOURISM_HOSPITALITY:                       // 13, -> "Туризм и гостеприимство",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 10, -> "Туризм и гостеприимство"
        case ProfilingCode::NSPECDIR_TOURISM_PROMOTION:                         // 14, -> "Технологии формирования и продвижения туристических услуг",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 10, -> "Туризм и гостеприимство"
        case ProfilingCode::NSPECDIR_TOURISM_IT:                                // 15, -> "Информационные технологии туристической индустрии",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 10, -> "Туризм и гостеприимство"
        case ProfilingCode::NSPECDIR_TOURISM_LOGISTICS:                         // 16, -> "Логистика в туристической индустрии",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 10, -> "Туризм и гостеприимство"
        case ProfilingCode::NSPECDIR_TOURISM_SOCIAL:                            // 17, -> "Технологии социокультурного сервиа туристов",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 10, -> "Туризм и гостеприимство"
        case ProfilingCode::NSPECDIR_TOURISM_TRANSPORT:                         // 18, -> "Технологии транспортного сервиса туристов",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 10, -> "Туризм и гостеприимство"
        case ProfilingCode::NSPECDIR_TOURISM_CATERING:                          // 19, -> "Технологии сервиса питания туристов",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 10, -> "Туризм и гостеприимство"
        case ProfilingCode::NSPECDIR_TOURISM_ACCOMMODATION:                     // 20, -> "Технологии сервиса размещения туристов",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 10, -> "Туризм и гостеприимство"
        case ProfilingCode::NSPECDIR_TOURISM_SUPPORTING:                        // 21, -> "Технологии экскурсионно-сопроводительного сервиса туристов",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 10, -> "Туризм и гостеприимство"
        case ProfilingCode::NSPECDIR_TOURISM_TREATMENT:                         // 22, -> "Технологии сервиса оздоровления и лечения туристов",
            return
                SectionCode::NSPEC_HIGH_SCHOOL_TOURISM;                         // 10, -> "Туризм и гостеприимство"
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_THEORY:                     // 23, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной физической культуры.",
            return
                SectionCode::NSPEC_MASTER_SCIENCE_THEORY;                       // 11, -> "Теория и методика физического воспитания, спортивной тренировки, оздоровительной"
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_PHYSIOLOGY:                 // 24, -> "Физиология",
            return
                SectionCode::NSPEC_MASTER_SCIENCE_PHYSIOLOGY;                   // 12, -> "Физиология"
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_SPORT:                     // 25, -> "Теория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной физической культуры.",
            return
                SectionCode::NSPEC_MASTER_RESEARCH_SPORT;                       // 13, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной ФК"
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TOURISM:                 // 26, -> "Инновационный менеджмент в сфере туризма",
            return
                SectionCode::NSPEC_MASTER_INNOVATION_TOURISM;                   // 14, -> "инновационный менеджмент в сфере туризма"
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_HOSPITALITY:             // 27, -> "Инновационный менеджмент в сфере гостеприимства",
            return
                SectionCode::NSPEC_MASTER_INNOVATION_HOSPITALITY;               // 15, -> "инновационный менеджмент в сфере гостеприимства"
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TECHNOLOGY:              // 28, -> "Инновационные технологии в сфере туризма и гостеприимства",
            return
                SectionCode::NSPEC_MASTER_INNOVATION_TECHNOLOGY;                // 16, -> "инновационные технологии в сфере туризма и гостеприимства"
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_MANAGEMENT:              // 29, -> "Управление инновационными проектами в туристской индустрии",
            return
                SectionCode::NSPEC_MASTER_INNOVATION_MANAGEMENT;                // 17, -> "управление инновационными проектами в туристской индустрии"
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_MANAGEMENT:                // 30, -> "Менеджмент",
            return
                SectionCode::NSPEC_MASTER_RESEARCH_MANAGEMENT;                  // 20  -> "Менеджмент"
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_PHYSICAL_CULTURE:          // 31, -> "Физическая культура и спорт",
            return
                SectionCode::NSPEC_MASTER_RESEARCH_PHYSICAL_CULTURE;            // 18, -> "физическая культура и спорт"
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_TOURISM:                   // 32  -> "Туризм и гостеприимство";
            return
                SectionCode::NSPEC_MASTER_RESEARCH_TOURISM;                     // 19, -> "туризм и гостеприимство"

        default:
            ShowMessage (
                "ERROR:\n"                          \
                "The getSectionCodeByNSpecDir "     \
                "(int nSpecDir) method returns:\n"  \
                "Value: "                           +
                    AnsiString (nSpecDir)           +
                "\t - The code does not exist!"
            );
            return
                nSpecDir;
    }
}
int        InsteadDb::getFacultyCodeByNSpecializ (const int nSpecializ)
{
    switch (static_cast <KindOfSportCode> (nSpecializ))
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
        case KindOfSportCode::FIGURE_SKATING:
            return
                FacultyCode::SMA;
        case KindOfSportCode::FOOTBALL:
            return
                FacultyCode::SMA;
        case KindOfSportCode::HOCKEY:
            return
                FacultyCode::SMA;
        case KindOfSportCode::WRESTLING:
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
        case KindOfSportCode::TABLE_TENNIS:
            return
                FacultyCode::SMA;
        case KindOfSportCode::ERGOTHERAPY:
            return
                FacultyCode::RPC;
        case KindOfSportCode::MANAGEMENT_SPORTS:
            return
                FacultyCode::MSTH;
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
                FacultyCode::SMA;
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
        case KindOfSportCode::FIGURE_SKATING_SKATES:
            return
                FacultyCode::SMA;
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                FacultyCode::MS;
        case KindOfSportCode::ACADEMIC_ROWING:
            return
                FacultyCode::MS;
        case KindOfSportCode::HAND_TO_HAND_MARTIAL_ARTS:
            return
                FacultyCode::MS;
        case KindOfSportCode::BILLIARDS:
            return
                FacultyCode::SMA;
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                FacultyCode::SMA;
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                FacultyCode::MS;
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
        case KindOfSportCode::BADMINTON:
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
                "ERROR:\n"                              \
                "The getFacultyCodeByNSpecializ "       \
                "(int nSpecializ) method returns:\n"    \
                "Value: "                               +
                    AnsiString (nSpecializ)             +
                "\t - The code does not exist!"
            );
            return
                nSpecializ;
    }
}

// CODE
AnsiString InsteadDb::getNcrb2022CodeById (const int id)
{
    switch (static_cast <Section2022Code> (id))
    {
        case Section2022Code::PHYSICAL_CULTURE_2022:                            // 0
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;           // 0 -> "6-05-1012-01", old code: "1-88 01 01";
        case Section2022Code::COACHING_2022:                                    // 1
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::COACHING;                   // 1 -> "6-05-1012-02", old code: "1-88 02 01-01",
        case Section2022Code::REHABILITATION_2022:                              // 2
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::REHABILITATION;             // 2 -> "6-05-1012-03", old code: "1-88 01 03",
        case Section2022Code::MANAGEMENT_2022:                                  // 3
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::MANAGEMENT;                 // 3 -> "6-05-1012-04"; old code: "1-88 02 01-02",
        case Section2022Code::TOURISM_2022:                                     // 4
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                    // 4 -> ""6-05-1013-01", old code: "1-89 01 01",

        default:
            ShowMessage (
                "ERROR:\n"                          \
                "The getNcrb2022CodeById "          \
                "(const int id) method returns:\n"  \
                "Value: "                           +
                    AnsiString (id)                 +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    id
                );
    }
}
// KIND OF SPORTS
AnsiString InsteadDb::getKindOfSportNameByNSpecializ (const int nSpecializ)
{
    switch (static_cast <KindOfSportCode> (nSpecializ))
    {
        case KindOfSportCode::GYMNASTICS:
            return
                KindOfSport::GYMNASTICS;                                        // "Гимнастика",
        case KindOfSportCode::MANAGEMENT_SPORTS_TOURISM:
            return
                KindOfSport::MANAGEMENT_SPORTS_TOURISM;                         // "Менеджмент спорта и туризма",
        case KindOfSportCode::PHYSICAL_REHABILITATION:
            return
                KindOfSport::PHYSICAL_REHABILITATION;                           // "Физическая реабилитация",
        case KindOfSportCode::THERAPEUTIC:
            return
                KindOfSport::THERAPEUTIC;                                       // "Лечебная физическая культура",
        case KindOfSportCode::ORGANIZATION_SPORTS_TOURISM:
            return
                KindOfSport::ORGANIZATION_SPORTS_TOURISM;                       // "Организация физкультурно-оздоровительной работы и туризма",
        case KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION:
            return
                KindOfSport::PRESCHOOL_PHYSICAL_EDUCATION;                      // "Дошкольное физическое воспитание",
        case KindOfSportCode::DANCE_SPORT:
            return
                KindOfSport::DANCE_SPORT;                                       // "Танцевальный спорт",
        case KindOfSportCode::AEROBICS:
            return
                KindOfSport::AEROBICS;                                          // "Аэробика",
        case KindOfSportCode::ROWING_OTHER:
            return
                KindOfSport::ROWING_OTHER;                                      // "Гребной спорт",
        case KindOfSportCode::SWIMMING:
            return
                KindOfSport::SWIMMING;                                          // "Плавание",
        case KindOfSportCode::SAILING:
            return
                KindOfSport::SAILING;                                           // "Парусный спорт",
        case KindOfSportCode::ATHLETICS:
            return
                KindOfSport::ATHLETICS;                                         // "Легкая атлетика",
        case KindOfSportCode::CROSS_COUNTRY_SKIING:
            return
                KindOfSport::CROSS_COUNTRY_SKIING;                              // "Лыжные гонки",
        case KindOfSportCode::BULLET_SHOOTING_DEANERY:
            return
                KindOfSport::BULLET_SHOOTING_DEANERY;                           // "Пулевая стрельба",
        case KindOfSportCode::HAND_TO_HAND_COMBAT:
            return
                KindOfSport::HAND_TO_HAND_COMBAT;                               // "Рукопашный бой",
        case KindOfSportCode::TAEKWONDO:
            return
                KindOfSport::TAEKWONDO;                                         // "Таэквондо",
        case KindOfSportCode::KARATE:
            return
                KindOfSport::KARATE;                                            // "Каратэ",
        case KindOfSportCode::SKIING:
            return
                KindOfSport::SKIING;                                            // "Лыжный спорт",
        case KindOfSportCode::AUTOMOTIVE_SPORT:
            return
                KindOfSport::AUTOMOTIVE_SPORT;                                  // "Автомобильный спорт",
        case KindOfSportCode::BASKETBALL:
            return
                KindOfSport::BASKETBALL;                                        // "Баскетбол",
        case KindOfSportCode::BOXING:
            return
                KindOfSport::BOXING;                                            // "Бокс",
        case KindOfSportCode::GRECO_FREESTYLE_WRESTLING:
            return
                KindOfSport::GRECO_FREESTYLE_WRESTLING;                         // "Греко-римская и вольная борьба",
        case KindOfSportCode::CYCLING:
            return
                KindOfSport::CYCLING;                                           // "Велосипедный спорт",
        case KindOfSportCode::VOLLEYBALL:
            return
                KindOfSport::VOLLEYBALL;                                        // "Волейбол",
        case KindOfSportCode::HANDBALL:
            return
                KindOfSport::HANDBALL;                                          // "Гандбол",
        case KindOfSportCode::EQUESTRIAN:
            return
                KindOfSport::EQUESTRIAN;                                        // "Конный спорт",
        case KindOfSportCode::SPEED_SKATING:
            return
                KindOfSport::SPEED_SKATING;                                     // "Конькобежный спорт",
        case KindOfSportCode::TENNIS:
            return
                KindOfSport::TENNIS;                                            // "Теннис",
        case KindOfSportCode::WEIGHTLIFTING:
            return
                KindOfSport::WEIGHTLIFTING;                                     // "Тяжелая атлетика",
        case KindOfSportCode::FENCING:
            return
                KindOfSport::FENCING;                                           // "Фехтование",
        case KindOfSportCode::FIGURE_SKATING:
            return
                KindOfSport::FIGURE_SKATING;                                    // "Фигурное катание",
        case KindOfSportCode::FOOTBALL:
            return
                KindOfSport::FOOTBALL;                                          // "Футбол",
        case KindOfSportCode::HOCKEY:
            return
                KindOfSport::HOCKEY;                                            // "Хоккей",
        case KindOfSportCode::WRESTLING:
            return
                KindOfSport::WRESTLING;                                         // "Спортивная борьба",
        case KindOfSportCode::BIATHLON:
            return
                KindOfSport::BIATHLON;                                          // "Биатлон",
        case KindOfSportCode::HEALTH_IMPROVING:
            return
                KindOfSport::HEALTH_IMPROVING;                                  // "Оздоровительная физическая культура",
        case KindOfSportCode::ADAPTIVE:
            return
                KindOfSport::ADAPTIVE;                                          // "Адаптивная физическая культура",
        case KindOfSportCode::FREESTYLE_WRESTLING:
            return
                KindOfSport::FREESTYLE_WRESTLING;                               // "Вольная борьба",
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:
            return
                KindOfSport::GRECO_ROMAN_WRESTLING;                             // "Греко-римская борьба",
        case KindOfSportCode::SAMBO:
            return
                KindOfSport::SAMBO;                                             // "Самбо",
        case KindOfSportCode::JUDO:
            return
                KindOfSport::JUDO;                                              // "Дзюдо",
        case KindOfSportCode::TABLE_TENNIS:
            return
                KindOfSport::TABLE_TENNIS;                                      // "Теннис настольный",
        case KindOfSportCode::ERGOTHERAPY:
            return
                KindOfSport::ERGOTHERAPY;                                       // "Эрготерапия",
        case KindOfSportCode::MANAGEMENT_SPORTS:
            return
                KindOfSport::MANAGEMENT_SPORTS;                                 // "Менеджмент в спорте",
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM:
            return
                KindOfSport::SPORTS_RECREATIONAL_TOURISM;                       // "Спортивный и рекреационный туризм",
        case KindOfSportCode::MANAGEMENT_TOURISM:
            return
                KindOfSport::MANAGEMENT_TOURISM;                                // "Менеджмент в туризме",
        case KindOfSportCode::SPORTS_PSYCHOLOGY:
            return
                KindOfSport::SPORTS_PSYCHOLOGY;                                 // "Спортивная психология",
        case KindOfSportCode::BILLIARD_SPORTS:
            return
                KindOfSport::BILLIARD_SPORTS;                                   // "Бильярдный спорт",
        case KindOfSportCode::ACROBATICS:
            return
                KindOfSport::ACROBATICS;                                        // "Акробатика",
        case KindOfSportCode::ORIENTEERING:
            return
                KindOfSport::ORIENTEERING;                                      // "Спортивное ориентирование",
        case KindOfSportCode::SPORTS_DIRECTING:
            return
                KindOfSport::SPORTS_DIRECTING;                                  // "Спортивная режиссура",
        case KindOfSportCode::PRESCHOOLERS:
            return
                KindOfSport::PRESCHOOLERS;                                      // "Физическая культура дошкольников",
        case KindOfSportCode::MOUNTAINEERING:
            return
                KindOfSport::MOUNTAINEERING;                                    // "Альпинизм",
        case KindOfSportCode::SKI_COMBINED:
            return
                KindOfSport::SKI_COMBINED;                                      // "Лыжное двоеборье",
        case KindOfSportCode::TOURISM_HOSPITALITY:
            return
                KindOfSport::TOURISM_HOSPITALITY;                               // "Туризм и гостеприимство",
        case KindOfSportCode::WATER_TECHNICAL_SPORTS:
            return
                KindOfSport::WATER_TECHNICAL_SPORTS;                            // "Водно-технические виды спорта",
        case KindOfSportCode::MODEL_TECHNICAL_SPORTS:
            return
                KindOfSport::MODEL_TECHNICAL_SPORTS;                            // "Модельно-технические виды спорта",
        case KindOfSportCode::ALPINE_SKIING:
            return
                KindOfSport::ALPINE_SKIING;                                     // "Горнолыжный спорт",
        case KindOfSportCode::BASEBALL:
            return
                KindOfSport::BASEBALL;                                          // "Бейсбол",
        case KindOfSportCode::WUSHU:
            return
                KindOfSport::WUSHU;                                             // "Ушу",
        case KindOfSportCode::CHESS:
            return
                KindOfSport::CHESS;                                             // "Шахматы",
        case KindOfSportCode::THAI_BOXING:
            return
                KindOfSport::THAI_BOXING;                                       // "Таиландский бокс",
        case KindOfSportCode::TOURISM_PROMOTION:
            return
                KindOfSport::TOURISM_PROMOTION;                                 // "Технологии формирования и продвижения туристических услуг",
        case KindOfSportCode::TOURISM_IT:
            return
                KindOfSport::TOURISM_IT;                                        // "Информационные технологии туристической индустрии",
        case KindOfSportCode::TOURISM_LOGISTICS:
            return
                KindOfSport::TOURISM_LOGISTICS;                                 // "Логистика в туристической индустрии",
        case KindOfSportCode::TOURISM_SOCIAL:
            return
                KindOfSport::TOURISM_SOCIAL;                                    // "Технологии социокультурного сервиса туристов",
        case KindOfSportCode::TOURISM_TRANSPORT:
            return
                KindOfSport::TOURISM_TRANSPORT;                                 // "Технологии транспортного сервиса туристов",
        case KindOfSportCode::TOURISM_FOOD:
            return
                KindOfSport::TOURISM_FOOD;                                      // "Технологии сервиса питания туристов",
        case KindOfSportCode::TOURIST_ACCOMMODATION:
            return
                KindOfSport::TOURIST_ACCOMMODATION;                             // "Технологии сервиса размещения туристов",
        case KindOfSportCode::TOURISM_EXCURSION:
            return
                KindOfSport::TOURISM_EXCURSION;                                 // "Технологии экскурсионно-сопроводительного сервиса туристов",
        case KindOfSportCode::TOURISM_HEALTH:
            return
                KindOfSport::TOURISM_HEALTH;                                    // "Технологии сервиса оздоровления и лечения туристов",
        case KindOfSportCode::BULLET_SHOOTING:
            return
                KindOfSport::BULLET_SHOOTING;                                   // "Стрельба пулевая",
        case KindOfSportCode::FIELD_HOCKEY:
            return
                KindOfSport::FIELD_HOCKEY;                                      // "Хоккей на траве",
        case KindOfSportCode::FIGURE_SKATING_SKATES:
            return
                KindOfSport::FIGURE_SKATING_SKATES;                             // "Фигурное катание на коньках",
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                KindOfSport::ROWING_AND_CANOEING;                               // "Гребля на байдарках и каноэ",
        case KindOfSportCode::ACADEMIC_ROWING:
            return
                KindOfSport::ACADEMIC_ROWING;                                   // "Гребля академическая",
        case KindOfSportCode::HAND_TO_HAND_MARTIAL_ARTS:
            return
                KindOfSport::HAND_TO_HAND_MARTIAL_ARTS;                         // "Рукопашный бой (смешанные единоборства)",
        case KindOfSportCode::BILLIARDS:
            return
                KindOfSport::BILLIARDS;                                         // "Бильярд",
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                KindOfSport::WITHOUT_SPECIALIZATION;                            // "Без специализации",
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                KindOfSport::MODERN_PENTATHLON;                                 // "Современное пятиборье",
        case KindOfSportCode::SCIENCE_HEALTH:
            return
                KindOfSport::SCIENCE_HEALTH;                                    // "теория и методика физического воспитания, спортивной тренировки, оздоровительной",
        case KindOfSportCode::PHYSIOLOGY:
            return
                KindOfSport::PHYSIOLOGY;                                        // "физиология",
        case KindOfSportCode::SCIENCE_THEORY:
            return
                KindOfSport::SCIENCE_THEORY;                                    // "теория и методика физического воспитания, спортивной тренировки, оздоровительной",
        case KindOfSportCode::RECEARCH_SPORT:
            return
                KindOfSport::RECEARCH_SPORT;                                    // "теория и методика физического воспитания, спортивной тренировки, оздоровительной",
        case KindOfSportCode::INNOVATIVE_TOURISM:
            return
                KindOfSport::INNOVATIVE_TOURISM;                                // "инновационный менеджмент в сфере туризма",
        case KindOfSportCode::INNOVATIVE_HOSPITALITY:
            return
                KindOfSport::INNOVATIVE_HOSPITALITY;                            // "инновационный менеджмент в сфере гостеприимства",
        case KindOfSportCode::INNOVATIVE_TECHNOLOGIES:
            return
                KindOfSport::INNOVATIVE_TECHNOLOGIES;                           // "инновационные технологии в сфере туризма и гостеприимства",
        case KindOfSportCode::INNOVATIVE_MANAGEMENT:
            return
                KindOfSport::INNOVATIVE_MANAGEMENT;                             // "управление инновационными проектами в туристской индустрии",
        case KindOfSportCode::BADMINTON:
            return
                KindOfSport::BADMINTON;                                         // "Бадминтон",
        case KindOfSportCode::PHYSICAL_CULTURE_SPORT:
            return
                KindOfSport::PHYSICAL_CULTURE_SPORT;                            // "Физическая культура и спорт",
        case KindOfSportCode::TOURISM_HOSPITALITY_MASTER:
            return
                KindOfSport::TOURISM_HOSPITALITY_MASTER;                        // "Туризм и гостеприимство",
        case KindOfSportCode::SPORT_CLIMBING:
            return
                KindOfSport::SPORT_CLIMBING;                                    // "Скалолазание спортивное",
        case KindOfSportCode::MASTER_ANTHROPOLOGY:
            return
                KindOfSport::MASTER_ANTHROPOLOGY;                               // "антропология",
        case KindOfSportCode::MASTER_MANAGEMENT:
            return
                KindOfSport::MASTER_MANAGEMENT;                                 // "Менеджмент";

        default:
            ShowMessage (
                "ERROR:\n"                                              \
                "The getKindOfSportNameByNSpecializ "                   \
                "(int nSpecializ) method returns:\n"    \
                "Value: "                                               +
                    AnsiString (nSpecializ)             +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    nSpecializ
                );
    }
}
AnsiString InsteadDb::getKindOfSportNameDativeCaseByNSpecializ (const int nSpecializ)
{
    switch (static_cast <KindOfSportCode> (nSpecializ))
    {
        case KindOfSportCode::GYMNASTICS:
            return
                KindOfSport::DATIVE_CASE::GYMNASTICS;                           // "гимнастике",
        case KindOfSportCode::MANAGEMENT_SPORTS_TOURISM:
            return
                KindOfSport::DATIVE_CASE::MANAGEMENT_SPORTS_TOURISM;            // "менеджменту спорта и туризма",
        case KindOfSportCode::PHYSICAL_REHABILITATION:
            return
                KindOfSport::DATIVE_CASE::PHYSICAL_REHABILITATION;              // "физической реабилитации",
        case KindOfSportCode::THERAPEUTIC:
            return
                KindOfSport::DATIVE_CASE::THERAPEUTIC;                          // "лечебной физической культуре",
        case KindOfSportCode::ORGANIZATION_SPORTS_TOURISM:
            return
                KindOfSport::DATIVE_CASE::ORGANIZATION_SPORTS_TOURISM;          // "организации физкультурно-оздоровительной работы и туризма",
        case KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION:
            return
                KindOfSport::DATIVE_CASE::PRESCHOOL_PHYSICAL_EDUCATION;         // "дошкольному физическому воспитанию",
        case KindOfSportCode::DANCE_SPORT:
            return
                KindOfSport::DATIVE_CASE::DANCE_SPORT;                          // "танцевальному спорту",
        case KindOfSportCode::AEROBICS:
            return
                KindOfSport::DATIVE_CASE::AEROBICS;                             // "аэробике",
        case KindOfSportCode::ROWING_OTHER:
            return
                KindOfSport::DATIVE_CASE::ROWING_OTHER;                         // "гребному спорту",
        case KindOfSportCode::SWIMMING:
            return
                KindOfSport::DATIVE_CASE::SWIMMING;                             // "плаванию",
        case KindOfSportCode::SAILING:
            return
                KindOfSport::DATIVE_CASE::SAILING;                              // "парусному спорту",
        case KindOfSportCode::ATHLETICS:
            return
                KindOfSport::DATIVE_CASE::ATHLETICS;                            // "легкой атлетике",
        case KindOfSportCode::CROSS_COUNTRY_SKIING:
            return
                KindOfSport::DATIVE_CASE::CROSS_COUNTRY_SKIING;                 // "лыжным гонкам",
        case KindOfSportCode::BULLET_SHOOTING_DEANERY:
            return
                KindOfSport::DATIVE_CASE::BULLET_SHOOTING_DEANERY;              // "пулевой стрельбе",
        case KindOfSportCode::HAND_TO_HAND_COMBAT:
            return
                KindOfSport::DATIVE_CASE::HAND_TO_HAND_COMBAT;                  // "рукопашному бою",
        case KindOfSportCode::TAEKWONDO:
            return
                KindOfSport::DATIVE_CASE::TAEKWONDO;                            // "таэквондо",
        case KindOfSportCode::KARATE:
            return
                KindOfSport::DATIVE_CASE::KARATE;                               // "каратэ",
        case KindOfSportCode::SKIING:
            return
                KindOfSport::DATIVE_CASE::SKIING;                               // "лыжному спорту",
        case KindOfSportCode::AUTOMOTIVE_SPORT:
            return
                KindOfSport::DATIVE_CASE::AUTOMOTIVE_SPORT;                     // "автомобильному спорту",
        case KindOfSportCode::BASKETBALL:
            return
                KindOfSport::DATIVE_CASE::BASKETBALL;                           // "баскетболу",
        case KindOfSportCode::BOXING:
            return
                KindOfSport::DATIVE_CASE::BOXING;                               // "боксу",
        case KindOfSportCode::GRECO_FREESTYLE_WRESTLING:
            return
                KindOfSport::DATIVE_CASE::GRECO_FREESTYLE_WRESTLING;            // "греко-римской и вольной борьбе",
        case KindOfSportCode::CYCLING:
            return
                KindOfSport::DATIVE_CASE::CYCLING;                              // "велосипедному спорту",
        case KindOfSportCode::VOLLEYBALL:
            return
                KindOfSport::DATIVE_CASE::VOLLEYBALL;                           // "волейболу",
        case KindOfSportCode::HANDBALL:
            return
                KindOfSport::DATIVE_CASE::HANDBALL;                             // "гандболу",
        case KindOfSportCode::EQUESTRIAN:
            return
                KindOfSport::DATIVE_CASE::EQUESTRIAN;                           // "конному спорту",
        case KindOfSportCode::SPEED_SKATING:
            return
                KindOfSport::DATIVE_CASE::SPEED_SKATING;                        // "конькобежному спорту",
        case KindOfSportCode::TENNIS:
            return
                KindOfSport::DATIVE_CASE::TENNIS;                               // "теннису",
        case KindOfSportCode::WEIGHTLIFTING:
            return
                KindOfSport::DATIVE_CASE::WEIGHTLIFTING;                        // "тяжелой атлетике",
        case KindOfSportCode::FENCING:
            return
                KindOfSport::DATIVE_CASE::FENCING;                              // "фехтованию",
        case KindOfSportCode::FIGURE_SKATING:
            return
                KindOfSport::DATIVE_CASE::FIGURE_SKATING;                       // "фигурному катанию",
        case KindOfSportCode::FOOTBALL:
            return
                KindOfSport::DATIVE_CASE::FOOTBALL;                             // "футболу",
        case KindOfSportCode::HOCKEY:
            return
                KindOfSport::DATIVE_CASE::HOCKEY;                               // "хоккею",
        case KindOfSportCode::WRESTLING:
            return
                KindOfSport::DATIVE_CASE::WRESTLING;                            // "спортивной борьбе",
        case KindOfSportCode::BIATHLON:
            return
                KindOfSport::DATIVE_CASE::BIATHLON;                             // "биатлону",
        case KindOfSportCode::HEALTH_IMPROVING:
            return
                KindOfSport::DATIVE_CASE::HEALTH_IMPROVING;                     // "оздоровительной физической культуре",
        case KindOfSportCode::ADAPTIVE:
            return
                KindOfSport::DATIVE_CASE::ADAPTIVE;                             // "адаптивной физической культуре",
        case KindOfSportCode::FREESTYLE_WRESTLING:
            return
                KindOfSport::DATIVE_CASE::FREESTYLE_WRESTLING;                  // "вольной борьбе",
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:
            return
                KindOfSport::DATIVE_CASE::GRECO_ROMAN_WRESTLING;                // "греко-римской борьбе",
        case KindOfSportCode::SAMBO:
            return
                KindOfSport::DATIVE_CASE::SAMBO;                                // "самбо",
        case KindOfSportCode::JUDO:
            return
                KindOfSport::DATIVE_CASE::JUDO;                                 // "дзюдо",
        case KindOfSportCode::TABLE_TENNIS:
            return
                KindOfSport::DATIVE_CASE::TABLE_TENNIS;                         // "теннису настольному",
        case KindOfSportCode::ERGOTHERAPY:
            return
                KindOfSport::DATIVE_CASE::ERGOTHERAPY;                          // "эрготерапии",
        case KindOfSportCode::MANAGEMENT_SPORTS:
            return
                KindOfSport::DATIVE_CASE::MANAGEMENT_SPORTS;                    // "менеджменту в спорте",
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM:
            return
                KindOfSport::DATIVE_CASE::SPORTS_RECREATIONAL_TOURISM;          // "спортивному и рекреационному туризму",
        case KindOfSportCode::MANAGEMENT_TOURISM:
            return
                KindOfSport::DATIVE_CASE::MANAGEMENT_TOURISM;                   // "менеджменту в туризме",
        case KindOfSportCode::SPORTS_PSYCHOLOGY:
            return
                KindOfSport::DATIVE_CASE::SPORTS_PSYCHOLOGY;                    // "спортивной психологии",
        case KindOfSportCode::BILLIARD_SPORTS:
            return
                KindOfSport::DATIVE_CASE::BILLIARD_SPORTS;                      // "бильярдному спорту",
        case KindOfSportCode::ACROBATICS:
            return
                KindOfSport::DATIVE_CASE::ACROBATICS;                           // "акробатике",
        case KindOfSportCode::ORIENTEERING:
            return
                KindOfSport::DATIVE_CASE::ORIENTEERING;                         // "спортивному ориентированию",
        case KindOfSportCode::SPORTS_DIRECTING:
            return
                KindOfSport::DATIVE_CASE::SPORTS_DIRECTING;                     // "спортивной режиссуре",
        case KindOfSportCode::PRESCHOOLERS:
            return
                KindOfSport::DATIVE_CASE::PRESCHOOLERS;                         // "физической культуре дошкольников",
        case KindOfSportCode::MOUNTAINEERING:
            return
                KindOfSport::DATIVE_CASE::MOUNTAINEERING;                       // "альпинизму",
        case KindOfSportCode::SKI_COMBINED:
            return
                KindOfSport::DATIVE_CASE::SKI_COMBINED;                         // "лыжному двоеборью",
        case KindOfSportCode::TOURISM_HOSPITALITY:
            return
                KindOfSport::DATIVE_CASE::TOURISM_HOSPITALITY;                  // "туризму и гостеприимству",
        case KindOfSportCode::WATER_TECHNICAL_SPORTS:
            return
                KindOfSport::DATIVE_CASE::WATER_TECHNICAL_SPORTS;               // "водно-техническим видам спорта",
        case KindOfSportCode::MODEL_TECHNICAL_SPORTS:
            return
                KindOfSport::DATIVE_CASE::MODEL_TECHNICAL_SPORTS;               // "модельно-техническим видам спорта",
        case KindOfSportCode::ALPINE_SKIING:
            return
                KindOfSport::DATIVE_CASE::ALPINE_SKIING;                        // "горнолыжному спорту",
        case KindOfSportCode::BASEBALL:
            return
                KindOfSport::DATIVE_CASE::BASEBALL;                             // "бейсболу",
        case KindOfSportCode::WUSHU:
            return
                KindOfSport::DATIVE_CASE::WUSHU;                                // "ушу",
        case KindOfSportCode::CHESS:
            return
                KindOfSport::DATIVE_CASE::CHESS;                                // "шахматам",
        case KindOfSportCode::THAI_BOXING:
            return
                KindOfSport::DATIVE_CASE::THAI_BOXING;                          // "таиландскому боксу",
        case KindOfSportCode::TOURISM_PROMOTION:
            return
                KindOfSport::DATIVE_CASE::TOURISM_PROMOTION;                    // "технологиям формирования и продвижения туристических услуг",
        case KindOfSportCode::TOURISM_IT:
            return
                KindOfSport::DATIVE_CASE::TOURISM_IT;                           // "информационным технологиям туристической индустрии",
        case KindOfSportCode::TOURISM_LOGISTICS:
            return
                KindOfSport::DATIVE_CASE::TOURISM_LOGISTICS;                    // "логистике в туристической индустрии",
        case KindOfSportCode::TOURISM_SOCIAL:
            return
                KindOfSport::DATIVE_CASE::TOURISM_SOCIAL;                       // "технологиям социокультурного сервиса туристов",
        case KindOfSportCode::TOURISM_TRANSPORT:
            return
                KindOfSport::DATIVE_CASE::TOURISM_TRANSPORT;                    // "технологиям транспортного сервиса туристов",
        case KindOfSportCode::TOURISM_FOOD:
            return
                KindOfSport::DATIVE_CASE::TOURISM_FOOD;                         // "технологиям сервиса питания туристов",
        case KindOfSportCode::TOURIST_ACCOMMODATION:
            return
                KindOfSport::DATIVE_CASE::TOURIST_ACCOMMODATION;                // "технологиям сервиса размещения туристов",
        case KindOfSportCode::TOURISM_EXCURSION:
            return
                KindOfSport::DATIVE_CASE::TOURISM_EXCURSION;                    // "технологиям экскурсионно-сопроводительного сервиса туристов",
        case KindOfSportCode::TOURISM_HEALTH:
            return
                KindOfSport::DATIVE_CASE::TOURISM_HEALTH;                       // "технологиям сервиса оздоровления и лечения туристов",
        case KindOfSportCode::BULLET_SHOOTING:
            return
                KindOfSport::DATIVE_CASE::BULLET_SHOOTING;                      // "стрельбе пулевой",
        case KindOfSportCode::FIELD_HOCKEY:
            return
                KindOfSport::DATIVE_CASE::FIELD_HOCKEY;                         // "хоккею на траве",
        case KindOfSportCode::FIGURE_SKATING_SKATES:
            return
                KindOfSport::DATIVE_CASE::FIGURE_SKATING_SKATES;                // "фигурному катанию на коньках",
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                KindOfSport::DATIVE_CASE::ROWING_AND_CANOEING;                  // "гребле на байдарках и каноэ",
        case KindOfSportCode::ACADEMIC_ROWING:
            return
                KindOfSport::DATIVE_CASE::ACADEMIC_ROWING;                      // "гребле академической",
        case KindOfSportCode::HAND_TO_HAND_MARTIAL_ARTS:
            return
                KindOfSport::DATIVE_CASE::HAND_TO_HAND_MARTIAL_ARTS;            // "рукопашному бою (смешанные единоборства)",
        case KindOfSportCode::BILLIARDS:
            return
                KindOfSport::DATIVE_CASE::BILLIARDS;                            // "бильярду",
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                KindOfSport::DATIVE_CASE::WITHOUT_SPECIALIZATION;               // "без специализации",
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                KindOfSport::DATIVE_CASE::MODERN_PENTATHLON;                    // "современному пятиборью",
        case KindOfSportCode::SCIENCE_HEALTH:
            return
                KindOfSport::DATIVE_CASE::SCIENCE_HEALTH;                       // "теории и методике физического воспитания, спортивной тренировки, оздоровительной",
        case KindOfSportCode::PHYSIOLOGY:
            return
                KindOfSport::DATIVE_CASE::PHYSIOLOGY;                           // "физиологии",
        case KindOfSportCode::SCIENCE_THEORY:
            return
                KindOfSport::DATIVE_CASE::SCIENCE_THEORY;                       // "теории и методике физического воспитания, спортивной тренировки, оздоровительной",
        case KindOfSportCode::RECEARCH_SPORT:
            return
                KindOfSport::DATIVE_CASE::RECEARCH_SPORT;                       // "теории и методике физического воспитания, спортивной тренировки, оздоровительной",
        case KindOfSportCode::INNOVATIVE_TOURISM:
            return
                KindOfSport::DATIVE_CASE::INNOVATIVE_TOURISM;                   // "инновационному менеджменту в сфере туризма",
        case KindOfSportCode::INNOVATIVE_HOSPITALITY:
            return
                KindOfSport::DATIVE_CASE::INNOVATIVE_HOSPITALITY;               // "инновационному менеджменту в сфере гостеприимства",
        case KindOfSportCode::INNOVATIVE_TECHNOLOGIES:
            return
                KindOfSport::DATIVE_CASE::INNOVATIVE_TECHNOLOGIES;              // "инновационным технологиям в сфере туризма и гостеприимства",
        case KindOfSportCode::INNOVATIVE_MANAGEMENT:
            return
                KindOfSport::DATIVE_CASE::INNOVATIVE_MANAGEMENT;                // "управлению инновационными проектами в туристской индустрии",
        case KindOfSportCode::BADMINTON:
            return
                KindOfSport::DATIVE_CASE::BADMINTON;                            // "бадминтону",
        case KindOfSportCode::PHYSICAL_CULTURE_SPORT:
            return
                KindOfSport::DATIVE_CASE::PHYSICAL_CULTURE_SPORT;               // "физической культуре и спорту",
        case KindOfSportCode::TOURISM_HOSPITALITY_MASTER:
            return
                KindOfSport::DATIVE_CASE::TOURISM_HOSPITALITY_MASTER;           // "туризму и гостеприимству",
        case KindOfSportCode::SPORT_CLIMBING:
            return
                KindOfSport::DATIVE_CASE::SPORT_CLIMBING;                       // "спортивному скалолазанию",
        case KindOfSportCode::MASTER_ANTHROPOLOGY:
            return
                KindOfSport::DATIVE_CASE::MASTER_ANTHROPOLOGY;                  // "антропологии",
        case KindOfSportCode::MASTER_MANAGEMENT:
            return
                KindOfSport::DATIVE_CASE::MASTER_MANAGEMENT;                    // "менеджменту";

        default:
            ShowMessage (
                "ERROR:\n"                                      \
                "The getKindOfSportNameDativeCaseByNSpecializ " \
                "(int nSpecializ) method returns:\n"            \
                "Value: "                                       +
                    AnsiString (nSpecializ)                     +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    nSpecializ
                );
    }
}
AnsiString InsteadDb::getNcrb2022CodeByNSpecializ1stHand (const int nSpecializ)
{
    switch (static_cast <KindOfSportCode> (nSpecializ))
    {
        case KindOfSportCode::GYMNASTICS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::MANAGEMENT_SPORTS_TOURISM:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::MANAGEMENT;                 // "6-05-1012-04"; old code: "1-88 02 01-02";
        case KindOfSportCode::PHYSICAL_REHABILITATION:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::REHABILITATION;             // "6-05-1012-03", old code: "1-88 01 03-01",
        case KindOfSportCode::THERAPEUTIC:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;           // "6-05-1012-01", old code: "1-88 01 01-01",
        case KindOfSportCode::ORGANIZATION_SPORTS_TOURISM:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;           // "6-05-1012-01", old code: "1-88 01 02-01",
        case KindOfSportCode::PRESCHOOL_PHYSICAL_EDUCATION:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;           // "6-05-1012-01", old code: "1-88 01 01-02";
        case KindOfSportCode::DANCE_SPORT:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::AEROBICS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::ROWING_OTHER:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::SWIMMING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::SAILING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::ATHLETICS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::CROSS_COUNTRY_SKIING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::BULLET_SHOOTING_DEANERY:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::HAND_TO_HAND_COMBAT:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::TAEKWONDO:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::KARATE:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::SKIING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::AUTOMOTIVE_SPORT:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::BASKETBALL:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::BOXING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::GRECO_FREESTYLE_WRESTLING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::CYCLING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::VOLLEYBALL:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::HANDBALL:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::EQUESTRIAN:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::SPEED_SKATING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::TENNIS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::WEIGHTLIFTING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::FENCING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::FIGURE_SKATING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::FOOTBALL:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::HOCKEY:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::WRESTLING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::BIATHLON:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::HEALTH_IMPROVING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;           // "6-05-1012-01", old code: "1-88 01 02-01",
        case KindOfSportCode::ADAPTIVE:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;           // "6-05-1012-01", old code: "1-88 01 02-02";
        case KindOfSportCode::FREESTYLE_WRESTLING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::GRECO_ROMAN_WRESTLING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::SAMBO:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::JUDO:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::TABLE_TENNIS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::ERGOTHERAPY:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::REHABILITATION;             // "6-05-1012-03", old code: "1-88 01 03-02";
        case KindOfSportCode::MANAGEMENT_SPORTS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::MANAGEMENT;                 // "6-05-1012-04"; old code: "1-88 02 01-02";
        case KindOfSportCode::SPORTS_RECREATIONAL_TOURISM:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;           // "6-05-1012-01", old code: "1-89 02 01-01",
        case KindOfSportCode::MANAGEMENT_TOURISM:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::MANAGEMENT;                 // "6-05-1012-04"; old code: "1-88 02 01-02";
        case KindOfSportCode::SPORTS_PSYCHOLOGY:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;           // "6-05-1012-01", old code: "1-88 02 01-03",
        case KindOfSportCode::BILLIARD_SPORTS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::ACROBATICS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::ORIENTEERING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::SPORTS_DIRECTING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;           // "6-05-1012-01", old code: "1-88 02 01-04",
        case KindOfSportCode::PRESCHOOLERS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;           // "6-05-1012-01", old code: "1-88 01 01-02";
        case KindOfSportCode::MOUNTAINEERING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::SKI_COMBINED:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::TOURISM_HOSPITALITY:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                    // "6-05-1013-01", old code: "1-89 01 01",
        case KindOfSportCode::WATER_TECHNICAL_SPORTS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::MODEL_TECHNICAL_SPORTS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::ALPINE_SKIING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::BASEBALL:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::WUSHU:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::CHESS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::THAI_BOXING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::TOURISM_PROMOTION:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                    // "6-05-1013-01", old code: "1-89 01 01 01",
        case KindOfSportCode::TOURISM_IT:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                    // "6-05-1013-01", old code: "1-89 01 01 02",
        case KindOfSportCode::TOURISM_LOGISTICS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                    // "6-05-1013-01", old code: "1-89 01 01 03",
        case KindOfSportCode::TOURISM_SOCIAL:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                    // "6-05-1013-01", old code: "1-89 01 01 04",
        case KindOfSportCode::TOURISM_TRANSPORT:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                    // "6-05-1013-01", old code: "1-89 01 01 05",
        case KindOfSportCode::TOURISM_FOOD:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                    // "6-05-1013-01", old code: "1-89 01 01 06",
        case KindOfSportCode::TOURIST_ACCOMMODATION:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                    // "6-05-1013-01", old code: "1-89 01 01 07",
        case KindOfSportCode::TOURISM_EXCURSION:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                    // "6-05-1013-01", old code: "1-89 01 01 08",
        case KindOfSportCode::TOURISM_HEALTH:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                    // "6-05-1013-01", old code: "1-89 01 01 09";
        case KindOfSportCode::BULLET_SHOOTING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::FIELD_HOCKEY:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::FIGURE_SKATING_SKATES:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::ROWING_AND_CANOEING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::ACADEMIC_ROWING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::HAND_TO_HAND_MARTIAL_ARTS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::BILLIARDS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::WITHOUT_SPECIALIZATION:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::MODERN_PENTATHLON:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::SCIENCE_HEALTH:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::SCIENCE::THEORY;          // "13.00.04",     old code: "13.00.04",
        case KindOfSportCode::PHYSIOLOGY:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::SCIENCE::PHYSIOLOGY;      // "03.03.01";     old code: "03.03.01";
        case KindOfSportCode::SCIENCE_THEORY:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::SCIENCE::THEORY;          // "13.00.04",     old code: "13.00.04",
        case KindOfSportCode::RECEARCH_SPORT:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::RESEARCH::SPORT;          // "13.00.04",     old code: "1-08 80 04",
        case KindOfSportCode::INNOVATIVE_TOURISM:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::INNOVATION::TOURISM;      // "1-89 81 02",   old code: "1-89 81 02",
        case KindOfSportCode::INNOVATIVE_HOSPITALITY:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::INNOVATION::HOSPITALITY;  // "1-89 81 03",   old code: "1-89 81 03",
        case KindOfSportCode::INNOVATIVE_TECHNOLOGIES:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::INNOVATION::TECHNOLOGIES; // "1-89 81 04",   old code: "1-89 81 04",
        case KindOfSportCode::INNOVATIVE_MANAGEMENT:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::INNOVATION::MANAGEMENT;   // "1-89 81 01";   old code: "1-89 81 01";
        case KindOfSportCode::BADMINTON:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::PHYSICAL_CULTURE_SPORT:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::RESEARCH::PHYSICAL_CULTURE;   // "7-06-1012-01", old code: "1-08 80 04",
        case KindOfSportCode::TOURISM_HOSPITALITY_MASTER:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::RESEARCH::TOURISM;        // "7-06-1013-01", old code: "1-89 80 01",
        case KindOfSportCode::SPORT_CLIMBING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                   // "6-05-1012-02", old code: "1-88 02 01-01",
        case KindOfSportCode::MASTER_ANTHROPOLOGY:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::RESEARCH::SPORT;          // "13.00.04",     old code: "1-08 80 04",
        case KindOfSportCode::MASTER_MANAGEMENT:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::RESEARCH::MANAGEMENT;     // "7-06-0412-01"; old code: "1-26 80 04",

        default:
            ShowMessage (
                "ERROR:\n"                              \
                "The getNcrb2022CodeByNSpecializ "      \
                "(int nSpecializ) method returns:\n"    \
                "Value: "                               +
                    AnsiString (nSpecializ)             +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    nSpecializ
                );
    }
}
// PROFILING
AnsiString InsteadDb::getProfiling2009NameByNSpecDir (const int nSpecDir)
{
    switch (static_cast <ProfilingCode> (nSpecDir))
    {
        case ProfilingCode::NSPECDIR_SPORT_COACHING:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::SPORT::COACHING;       // 1,  -> "Тренерская работа по",
        case ProfilingCode::NSPECDIR_SPORT_PSYCHOLOGY:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::SPORT::PSYCHOLOGY;     // 2,  -> "Спортивная психология",
        case ProfilingCode::NSPECDIR_SPORT_DIRECTING:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::SPORT::DIRECTING;      // 3,  -> "Спортивная режиссура",
        case ProfilingCode::NSPECDIR_SPORT_MANAGEMENT:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::SPORT::MANAGEMENT;     // 4,  -> "Менеджмент в спорте",
        case ProfilingCode::NSPECDIR_MANAGEMENT_RECREATIONAL:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::MANAGEMENT::RECREATIONAL;  // 5,  -> "Спортивный и рекреационный туризм",
        case ProfilingCode::NSPECDIR_MANAGEMENT_TOURISM_MNG:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::MANAGEMENT::TUORISM_MNG;   // 6,  -> "Менеджмент в туризме",
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_MEDICAL:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::PHYSICAL_CULTURE::MEDICAL; // 7,  -> "Лечебная",
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::PHYSICAL_CULTURE::PRESCHOOLERS;    // 8,  -> "Дошкольников",
        case ProfilingCode::NSPECDIR_IMPROVING_HEALTH:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::IMPROVING::HEALTH;     // 9,  -> "Оздоровительная",
        case ProfilingCode::NSPECDIR_IMPROVING_ADAPTIVE:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::IMPROVING::ADAPTIVE;   // 10, -> "Адаптивная",
        case ProfilingCode::NSPECDIR_REHABILITATION_REHABILITATION:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::REHABILITATION::REHABILITATION;    // 11, -> "Физическая реабилитация",
        case ProfilingCode::NSPECDIR_REHABILITATION_ERGOTHERAPY:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::REHABILITATION::ERGOTHERAPY;   // 12, -> "Эрготерапия",
        case ProfilingCode::NSPECDIR_TOURISM_HOSPITALITY:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::TOURISM::HOSPITALITY;  // 13, -> "Туризм и гостеприимство",
        case ProfilingCode::NSPECDIR_TOURISM_PROMOTION:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::TOURISM::PROMOTION;    // 14, -> "Технологии формирования и продвижения туристических услуг",
        case ProfilingCode::NSPECDIR_TOURISM_IT:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::TOURISM::IT;           // 15, -> "Информационные технологии туристической индустрии",
        case ProfilingCode::NSPECDIR_TOURISM_LOGISTICS:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::TOURISM::LOGISTICS;    // 16, -> "Логистика в туристической индустрии",
        case ProfilingCode::NSPECDIR_TOURISM_SOCIAL:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::TOURISM::SOCIAL;       // 17, -> "Технологии социокультурного сервиа туристов",
        case ProfilingCode::NSPECDIR_TOURISM_TRANSPORT:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::TOURISM::TRANSPORT;    // 18, -> "Технологии транспортного сервиса туристов",
        case ProfilingCode::NSPECDIR_TOURISM_CATERING:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::TOURISM::CATERING;     // 19, -> "Технологии сервиса питания туристов",
        case ProfilingCode::NSPECDIR_TOURISM_ACCOMMODATION:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::TOURISM::ACCOMMODATION;    // 20, -> "Технологии сервиса размещения туристов",
        case ProfilingCode::NSPECDIR_TOURISM_SUPPORTING:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::TOURISM::SUPPORTING;   // 21, -> "Технологии экскурсионно-сопроводительного сервиса туристов",
        case ProfilingCode::NSPECDIR_TOURISM_TREATMENT:
            return
                NCRB_011::_2009::PROFILING::HIGH_SCHOOL::TOURISM::TREATMENT;    // 22, -> "Технологии сервиса оздоровления и лечения туристов",
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_THEORY:
            return
                NCRB_011::_2009::PROFILING::MASTER_DEGREE::SCIENCE::THEORY;     // 23, -> "теория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной физической культуры.",
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_PHYSIOLOGY:
            return
                NCRB_011::_2009::PROFILING::MASTER_DEGREE::SCIENCE::PHYSIOLOGY; // 24, -> "Физиология",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_SPORT:
            return
                NCRB_011::_2009::PROFILING::MASTER_DEGREE::RESEARCH::SPORT;     // 25, -> "Теория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной физической культуры.",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TOURISM:
            return
                NCRB_011::_2009::PROFILING::MASTER_DEGREE::INNOVATION::TOURISM; // 26, -> "Инновационный менеджмент в сфере туризма",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_HOSPITALITY:
            return
                NCRB_011::_2009::PROFILING::MASTER_DEGREE::INNOVATION::HOSPITALITY; // 27, -> "Инновационный менеджмент в сфере гостеприимства",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TECHNOLOGY:
            return
                NCRB_011::_2009::PROFILING::MASTER_DEGREE::INNOVATION::TECHNOLOGIES;    // 28, -> "Инновационные технологии в сфере туризма и гостеприимства",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_MANAGEMENT:
            return
                NCRB_011::_2009::PROFILING::MASTER_DEGREE::INNOVATION::MANAGEMENT;  // 29, -> "Управление инновационными проектами в туристской индустрии",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_MANAGEMENT:
            return
                NCRB_011::_2009::PROFILING::MASTER_DEGREE::RESEARCH::MANAGEMENT;    // 30, -> "Менеджмент",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_PHYSICAL_CULTURE:
            return
                NCRB_011::_2009::PROFILING::MASTER_DEGREE::RESEARCH::PHYSICAL_CULTURE;  // 31, -> "Физическая культура и спорт",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_TOURISM:
            return
                NCRB_011::_2009::PROFILING::MASTER_DEGREE::RESEARCH::TOURISM;   // 32  -> "Туризм и гостеприимство";

        default:
            ShowMessage (
                "ERROR:\n"                              \
                "The getProfiling2009NameByNSpecDir "   \
                "(int nSpecDir) method returns:\n"      \
                "Value: "                               +
                    AnsiString (nSpecDir)               +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    nSpecDir
                );
    }
}
AnsiString InsteadDb::getProfiling2022NameByNSpecDir (const int nSpecDir)
{
    switch (static_cast <ProfilingCode> (nSpecDir))
    {
        case ProfilingCode::NSPECDIR_SPORT_COACHING:
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::COACHING;                                       // "Тренерская деятельность",
        case ProfilingCode::NSPECDIR_SPORT_PSYCHOLOGY:
            return
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PHYSICAL_CULTURE                        +   // "Физическая культура",
                " "                                                                             +
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PROFILING::PHYSICAL::PSYCHOLOGY;            // "(спортивная психология)",
        case ProfilingCode::NSPECDIR_SPORT_DIRECTING:
            return
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PHYSICAL_CULTURE                        +   // "Физическая культура",
                " "                                                                             +
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PROFILING::PHYSICAL::DIRECTING;             // "(спортивная режиссура)",
        case ProfilingCode::NSPECDIR_SPORT_MANAGEMENT:
            return
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::MANAGEMENT                              +   // "Организация и управление физической культурой, спортом и туризмом";
                " "                                                                             +
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PROFILING::MANAGE::SPORT;                   // "(менеджмент в спорте)",
        case ProfilingCode::NSPECDIR_MANAGEMENT_RECREATIONAL:
            return
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PHYSICAL_CULTURE                        +   // "Физическая культура",
                " "                                                                             +
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PROFILING::PHYSICAL::RECREATIONAL;          // "(спортивный и рекреационный туризм)";
        case ProfilingCode::NSPECDIR_MANAGEMENT_TOURISM_MNG:
            return
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::MANAGEMENT                              +   // "Организация и управление физической культурой, спортом и туризмом";
                " "                                                                             +
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PROFILING::MANAGE::TOURISM;                 // "(менеджмент в туризме)";
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_MEDICAL:
            return
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PHYSICAL_CULTURE                        +   // "Физическая культура",
                " "                                                                             +
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PROFILING::PHYSICAL::HEALTH;                // "(лечебная физическая культура)",
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS:
            return
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PHYSICAL_CULTURE                        +   // "Физическая культура",
                " "                                                                             +
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PROFILING::PHYSICAL::PRESCHOOLERS;          // "(физическая культура дошкольников)",
        case ProfilingCode::NSPECDIR_IMPROVING_HEALTH:
            return
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PHYSICAL_CULTURE                        +   // "Физическая культура",
                " "                                                                             +
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PROFILING::PHYSICAL::IMPROVING;             // "(оздоровительная физическая культура)",
        case ProfilingCode::NSPECDIR_IMPROVING_ADAPTIVE:
            return
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PHYSICAL_CULTURE                        +   // "Физическая культура",
                " "                                                                             +
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PROFILING::PHYSICAL::ADAPTIVE;              // "(адаптивная физическая культура)",
        case ProfilingCode::NSPECDIR_REHABILITATION_REHABILITATION:
            return
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::REHABILITATION                          + // "Физическая реабилитация и эрготерапия",
                " "                                                                             +
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PROFILING::REHABILITATE::REHABILITATION;    // "(физическая реабилитация)",
        case ProfilingCode::NSPECDIR_REHABILITATION_ERGOTHERAPY:
            return
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::REHABILITATION                          + // "Физическая реабилитация и эрготерапия",
                " "                                                                             +
                    NCRB_011::_2022::NAME::HIGH_SCHOOL::PROFILING::REHABILITATE::ERGOTHERAPY;       // "(эрготерапия)";
        case ProfilingCode::NSPECDIR_TOURISM_HOSPITALITY:
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                                    // "Туризм и гостеприимство",
        case ProfilingCode::NSPECDIR_TOURISM_PROMOTION:
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                                    // "Туризм и гостеприимство",
        case ProfilingCode::NSPECDIR_TOURISM_IT:
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                                    // "Туризм и гостеприимство",
        case ProfilingCode::NSPECDIR_TOURISM_LOGISTICS:
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                                    // "Туризм и гостеприимство",
        case ProfilingCode::NSPECDIR_TOURISM_SOCIAL:
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                                    // "Туризм и гостеприимство",
        case ProfilingCode::NSPECDIR_TOURISM_TRANSPORT:
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                                    // "Туризм и гостеприимство",
        case ProfilingCode::NSPECDIR_TOURISM_CATERING:
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                                    // "Туризм и гостеприимство",
        case ProfilingCode::NSPECDIR_TOURISM_ACCOMMODATION:
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                                    // "Туризм и гостеприимство",
        case ProfilingCode::NSPECDIR_TOURISM_SUPPORTING:
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                                    // "Туризм и гостеприимство",
        case ProfilingCode::NSPECDIR_TOURISM_TREATMENT:
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                                    // "Туризм и гостеприимство",
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_THEORY:
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::SCIENCE::THEORY;                          // "Теория и методика физического воспитания, спортивной тренировки, оздоровительной",
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_PHYSIOLOGY:
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::SCIENCE::PHYSIOLOGY;                      // "Физиология";
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_SPORT:
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::RESEARCH::SPORT;                          // "Tеория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной физической культуры",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TOURISM:
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::INNOVATION::TOURISM;                      // "Инновационный менеджмент в сфере туризма",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_HOSPITALITY:
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::INNOVATION::HOSPITALITY;                  // "Инновационный менеджмент в сфере гостеприимства",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TECHNOLOGY:
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::INNOVATION::TECHNOLOGIES;                 // "Инновационные технологии в сфере туризма и гостеприимства",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_MANAGEMENT:
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::INNOVATION::MANAGEMENT;                   // "Управление инновационными проектами в туристской индустрии";
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_MANAGEMENT:
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::RESEARCH::MANAGEMENT;                     // "Менеджмент";
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_PHYSICAL_CULTURE:
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::RESEARCH::PHYSICAL_CULTURE;               // "Физическая культура и спорт",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_TOURISM:
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::RESEARCH::TOURISM;                        // "Туризм и гостеприимство",

        default:
            ShowMessage (
                "ERROR:\n"                              \
                "The getProfiling2022NameByNSpecDir "   \
                "(int nSpecDir) method returns:\n"      \
                "Value: "                               +
                    AnsiString (nSpecDir)               +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    nSpecDir
                );
    }
}
AnsiString InsteadDb::getNcrb2009CodeByNSpecDir (const int nSpecDir)
{
    switch (static_cast <ProfilingCode> (nSpecDir))
    {
        case ProfilingCode::NSPECDIR_SPORT_COACHING:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::SPORT::COACHING;                // "1-88 02 01-01",
        case ProfilingCode::NSPECDIR_SPORT_PSYCHOLOGY:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::SPORT::PSYCHOLOGY;              // "1-88 02 01-03",
        case ProfilingCode::NSPECDIR_SPORT_DIRECTING:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::SPORT::DIRECTING;               // "1-88 02 01-04",
        case ProfilingCode::NSPECDIR_SPORT_MANAGEMENT:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::SPORT::MANAGEMENT;              // "1-88 02 01-02";
        case ProfilingCode::NSPECDIR_MANAGEMENT_RECREATIONAL:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::MANAGEMENT::RECREATIONAL;       // "1-89 02 01-01",
        case ProfilingCode::NSPECDIR_MANAGEMENT_TOURISM_MNG:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::MANAGEMENT::TUORISM_MNG;        // "1-89 02 01-02";
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_MEDICAL:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE::MEDICAL;      // "1-88 01 01-01",
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE::PRESCHOOLERS; // "1-88 01 01-02";
        case ProfilingCode::NSPECDIR_IMPROVING_HEALTH:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::IMPROVING::HEALTH;              // "1-88 01 02-01",
        case ProfilingCode::NSPECDIR_IMPROVING_ADAPTIVE:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::IMPROVING::ADAPTIVE;            // "1-88 01 02-02";
        case ProfilingCode::NSPECDIR_REHABILITATION_REHABILITATION:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::REHABILITATION::REHABILITATION; // "1-88 01 03-01",
        case ProfilingCode::NSPECDIR_REHABILITATION_ERGOTHERAPY:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::REHABILITATION::ERGOTHERAPY;    // "1-88 01 03-02";
        case ProfilingCode::NSPECDIR_TOURISM_HOSPITALITY:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::TOURISM::HOSPITALITY;           // "1-89 01 01",
        case ProfilingCode::NSPECDIR_TOURISM_PROMOTION:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::TOURISM::PROMOTION;             // "1-89 01 01 01",
        case ProfilingCode::NSPECDIR_TOURISM_IT:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::TOURISM::IT;                    // "1-89 01 01 02",
        case ProfilingCode::NSPECDIR_TOURISM_LOGISTICS:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::TOURISM::LOGISTICS;             // "1-89 01 01 03",
        case ProfilingCode::NSPECDIR_TOURISM_SOCIAL:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::TOURISM::SOCIAL;                // "1-89 01 01 04",
        case ProfilingCode::NSPECDIR_TOURISM_TRANSPORT:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::TOURISM::TRANSPORT;             // "1-89 01 01 05",
        case ProfilingCode::NSPECDIR_TOURISM_CATERING:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::TOURISM::CATERING;              // "1-89 01 01 06",
        case ProfilingCode::NSPECDIR_TOURISM_ACCOMMODATION:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::TOURISM::ACCOMMODATION;         // "1-89 01 01 07",
        case ProfilingCode::NSPECDIR_TOURISM_SUPPORTING:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::TOURISM::SUPPORTING;            // "1-89 01 01 08",
        case ProfilingCode::NSPECDIR_TOURISM_TREATMENT:
            return
                NCRB_011::_2009::CODE::HIGH_SCHOOL::TOURISM::TREATMENT;             // "1-89 01 01 09";
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_THEORY:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::SCIENCE::THEORY;              // "13.00.04",
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_PHYSIOLOGY:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::SCIENCE::PHYSIOLOGY;          // "03.03.01";
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_SPORT:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::RESEARCH::SPORT;              // "1-08 80 04",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TOURISM:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::INNOVATION::TOURISM;          // "1-89 81 02",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_HOSPITALITY:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::INNOVATION::HOSPITALITY;      // "1-89 81 03",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TECHNOLOGY:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::INNOVATION::TECHNOLOGIES;     // "1-89 81 04",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_MANAGEMENT:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::INNOVATION::MANAGEMENT;       // "1-89 81 01";
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_MANAGEMENT:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::RESEARCH::MANAGEMENT;         // "1-26 80 04",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_PHYSICAL_CULTURE:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::RESEARCH::PHYSICAL_CULTURE;   // "1-08 80 04",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_TOURISM:
            return
                NCRB_011::_2009::CODE::MASTER_DEGREE::RESEARCH::TOURISM;            // "1-89 80 01";

        default:
            ShowMessage (
                "ERROR:\n"                          \
                "The getNcrb2009CodeByNSpecDir "    \
                "(int nSpecDir) method returns:\n"  \
                "Value: "                           +
                    AnsiString (nSpecDir)           +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    nSpecDir
                );
    }
}
AnsiString InsteadDb::getNcrb2022CodeByNSpecDir (const int nSpecDir)
{
    switch (static_cast <ProfilingCode> (nSpecDir))
    {
        case ProfilingCode::NSPECDIR_SPORT_COACHING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::COACHING;                       // "6-05-1012-02", old code: "1-88 02 01-01",
        case ProfilingCode::NSPECDIR_SPORT_PSYCHOLOGY:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;               // "6-05-1012-01", old code: "1-88 02 01-03",
        case ProfilingCode::NSPECDIR_SPORT_DIRECTING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;               // "6-05-1012-01", old code: "1-88 02 01-04",
        case ProfilingCode::NSPECDIR_SPORT_MANAGEMENT:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::MANAGEMENT;                     // "6-05-1012-04"; old code: "1-88 02 01-02";
        case ProfilingCode::NSPECDIR_MANAGEMENT_RECREATIONAL:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;               // "6-05-1012-01", old code: "1-89 02 01-01",
        case ProfilingCode::NSPECDIR_MANAGEMENT_TOURISM_MNG:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::MANAGEMENT;                     // "6-05-1012-04"; old code: "1-89 02 01-02";
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_MEDICAL:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;               // "6-05-1012-01", old code: "1-88 01 01-01",
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;               // "6-05-1012-01", old code: "1-88 01 01-02";
        case ProfilingCode::NSPECDIR_IMPROVING_HEALTH:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;               // "6-05-1012-01", old code: "1-88 01 02-01",
        case ProfilingCode::NSPECDIR_IMPROVING_ADAPTIVE:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::PHYSICAL_CULTURE;               // "6-05-1012-01", old code: "1-88 01 02-02";
        case ProfilingCode::NSPECDIR_REHABILITATION_REHABILITATION:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::REHABILITATION;                 // "6-05-1012-03", old code: "1-88 01 03-01",
        case ProfilingCode::NSPECDIR_REHABILITATION_ERGOTHERAPY:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::REHABILITATION;                 // "6-05-1012-03", old code: "1-88 01 03-02";
        case ProfilingCode::NSPECDIR_TOURISM_HOSPITALITY:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                        // "6-05-1013-01", old code: "1-89 01 01",
        case ProfilingCode::NSPECDIR_TOURISM_PROMOTION:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                        // "6-05-1013-01", old code: "1-89 01 01 01",
        case ProfilingCode::NSPECDIR_TOURISM_IT:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                        // "6-05-1013-01", old code: "1-89 01 01 02",
        case ProfilingCode::NSPECDIR_TOURISM_LOGISTICS:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                        // "6-05-1013-01", old code: "1-89 01 01 03",
        case ProfilingCode::NSPECDIR_TOURISM_SOCIAL:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                        // "6-05-1013-01", old code: "1-89 01 01 04",
        case ProfilingCode::NSPECDIR_TOURISM_TRANSPORT:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                        // "6-05-1013-01", old code: "1-89 01 01 05",
        case ProfilingCode::NSPECDIR_TOURISM_CATERING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                        // "6-05-1013-01", old code: "1-89 01 01 06",
        case ProfilingCode::NSPECDIR_TOURISM_ACCOMMODATION:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                        // "6-05-1013-01", old code: "1-89 01 01 07",
        case ProfilingCode::NSPECDIR_TOURISM_SUPPORTING:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                        // "6-05-1013-01", old code: "1-89 01 01 08",
        case ProfilingCode::NSPECDIR_TOURISM_TREATMENT:
            return
                NCRB_011::_2022::CODE::HIGH_SCHOOL::TOURISM;                        // "6-05-1013-01", old code: "1-89 01 01 09";
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_THEORY:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::SCIENCE::THEORY;              // "13.00.04",     old code: "13.00.04",
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_PHYSIOLOGY:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::SCIENCE::PHYSIOLOGY;          // "03.03.01";     old code: "03.03.01";
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_SPORT:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::RESEARCH::SPORT;              // "13.00.04",     old code: "1-08 80 04",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TOURISM:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::INNOVATION::TOURISM;          // "1-89 81 02",   old code: "1-89 81 02",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_HOSPITALITY:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::INNOVATION::HOSPITALITY;      // "1-89 81 03",   old code: "1-89 81 03",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TECHNOLOGY:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::INNOVATION::TECHNOLOGIES;     // "1-89 81 04",   old code: "1-89 81 04",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_MANAGEMENT:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::INNOVATION::MANAGEMENT;       // "1-89 81 01";   old code: "1-89 81 01";
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_MANAGEMENT:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::RESEARCH::MANAGEMENT;         // "7-06-0412-01"; old code: "1-26 80 04",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_PHYSICAL_CULTURE:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::RESEARCH::PHYSICAL_CULTURE;   // "7-06-1012-01", old code: "1-08 80 04",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_TOURISM:
            return
                NCRB_011::_2022::CODE::MASTER_DEGREE::RESEARCH::TOURISM;            // "7-06-1013-01", old code: "1-89 80 01",

        default:
            ShowMessage (
                "ERROR:\n"                          \
                "The getNcrb2022CodeByNSpecDir "    \
                "(int nSpecDir) method returns:\n"  \
                "Value: "                           +
                    AnsiString (nSpecDir)           +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    nSpecDir
                );
    }
}
AnsiString InsteadDb::getQualification2009NameByNSpecDir (const int nSpecDir)
{
    switch (static_cast <ProfilingCode> (nSpecDir))
    {
        case ProfilingCode::NSPECDIR_SPORT_COACHING:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::SPORT::COACHING;                   // "Преподаватель физической культуры. Тренер ",        (по виду спорта).
        case ProfilingCode::NSPECDIR_SPORT_PSYCHOLOGY:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::SPORT::PSYCHOLOGY;                 // "Психолог. Преподаватель физической культуры",
        case ProfilingCode::NSPECDIR_SPORT_DIRECTING:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::SPORT::DIRECTING;                  // "Менеджер-режиссер спортивно-массовых мероприятий.Преподаватель физической культуры";
        case ProfilingCode::NSPECDIR_SPORT_MANAGEMENT:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::SPORT::MANAGEMENT;                 // "Менеджер в спорте. Преподаватель физической культуры",
        case ProfilingCode::NSPECDIR_MANAGEMENT_RECREATIONAL:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::MANAGEMENT::RECREATIONAL;          // "Инструктор-методист по туризму. Преподаватель физической культуры",
        case ProfilingCode::NSPECDIR_MANAGEMENT_TOURISM_MNG:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::MANAGEMENT::TUORISM_MNG;           // "Менеджер по туризму. Преподаватель физической культуры";
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_MEDICAL:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::PHYSICAL_CULTURE::MEDICAL;         // "Инструктор-методист по лечебной физической культуре. Преподаватель физической культуры",
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::PHYSICAL_CULTURE::PRESCHOOLERS;    // "Инструктор-методист физического воспитания в дошкольных учреждениях. Преподаватель физической культуры";
        case ProfilingCode::NSPECDIR_IMPROVING_HEALTH:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::IMPROVING::HEALTH;                 // "Инструктор-методист по оздоровительной физической культуре. Преподаватель физической культуры",
        case ProfilingCode::NSPECDIR_IMPROVING_ADAPTIVE:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::IMPROVING::ADAPTIVE;               // "Инструктор-методист по адаптивной физической культуре. Преподаватель физической культуры";
        case ProfilingCode::NSPECDIR_REHABILITATION_REHABILITATION:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::REHABILITATION::REHABILITATION;    // "Инструктор-методист по физической реабилитации. Преподаватель физической культуры",
        case ProfilingCode::NSPECDIR_REHABILITATION_ERGOTHERAPY:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::REHABILITATION::ERGOTHERAPY;       // "Инструктор-методист по эрготерапии. Преподаватель физической культуры";
        case ProfilingCode::NSPECDIR_TOURISM_HOSPITALITY:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::TOURISM::HOSPITALITY;             // "Специалист в сфере туризма и гостеприимства",
        case ProfilingCode::NSPECDIR_TOURISM_PROMOTION:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::TOURISM::PROMOTION;               // "Специалист в сфере туризма и гостеприимства",
        case ProfilingCode::NSPECDIR_TOURISM_IT:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::TOURISM::IT;                      // "Специалист в сфере туризма и гостеприимства",
        case ProfilingCode::NSPECDIR_TOURISM_LOGISTICS:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::TOURISM::LOGISTICS;               // "Специалист в сфере туризма и гостеприимства",
        case ProfilingCode::NSPECDIR_TOURISM_SOCIAL:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::TOURISM::SOCIAL;                  // "Специалист в сфере туризма и гостеприимства",
        case ProfilingCode::NSPECDIR_TOURISM_TRANSPORT:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::TOURISM::TRANSPORT;               // "Специалист в сфере туризма и гостеприимства",
        case ProfilingCode::NSPECDIR_TOURISM_CATERING:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::TOURISM::CATERING;                // "Специалист в сфере туризма и гостеприимства",
        case ProfilingCode::NSPECDIR_TOURISM_ACCOMMODATION:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::TOURISM::ACCOMMODATION;           // "Специалист в сфере туризма и гостеприимства",
        case ProfilingCode::NSPECDIR_TOURISM_SUPPORTING:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::TOURISM::SUPPORTING;              // "Специалист в сфере туризма и гостеприимства",
        case ProfilingCode::NSPECDIR_TOURISM_TREATMENT:
            return
                NCRB_011::_2009::QUALIFICATION::HIGH_SCHOOL::TOURISM::TREATMENT;               // "Специалист в сфере туризма и гостеприимства";
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_THEORY:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::SCIENCE::THEORY;                 // "Магистр",
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_PHYSIOLOGY:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::SCIENCE::PHYSIOLOGY;             // "Магистр",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_SPORT:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::RESEARCH::SPORT;                 // "Магистр",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TOURISM:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::INNOVATION::TOURISM;             // "Магистр туризма",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_HOSPITALITY:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::INNOVATION::HOSPITALITY;         // "Магистр гостеприимства",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TECHNOLOGY:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::INNOVATION::TECHNOLOGIES;        // "Магистр инноваций",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_MANAGEMENT:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::INNOVATION::MANAGEMENT;          // "Магистр управления",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_MANAGEMENT:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::RESEARCH::MANAGEMENT;            // "Магистр",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_PHYSICAL_CULTURE:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::RESEARCH::PHYSICAL_CULTURE;      // "Магистр",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_TOURISM:
            return
                NCRB_011::_2009::QUALIFICATION::MASTER_DEGREE::RESEARCH::TOURISM;               // "Магистр",

        default:
            ShowMessage (
                "ERROR:\n"                                  \
                "The getQualification2009NameByNSpecDir "   \
                "(const int nSpecDir) method returns:\n"    \
                "Value: "                                   +
                    AnsiString (nSpecDir)                   +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    nSpecDir
                );
    }
}
AnsiString InsteadDb::getQualification2022NameByNSpecDir (const int nSpecDir)
{
    switch (static_cast <ProfilingCode> (nSpecDir))
    {
        case ProfilingCode::NSPECDIR_SPORT_COACHING:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::COACHING;                      // "Тренер. Преподаватель",
        case ProfilingCode::NSPECDIR_SPORT_PSYCHOLOGY:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::PHYSICAL_CULTURE;              // "Инструктор-методист. Преподаватель",
        case ProfilingCode::NSPECDIR_SPORT_DIRECTING:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::PHYSICAL_CULTURE;              // "Инструктор-методист. Преподаватель",
        case ProfilingCode::NSPECDIR_SPORT_MANAGEMENT:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::MANAGEMENT;                    // "Менеджер. Преподаватель",
        case ProfilingCode::NSPECDIR_MANAGEMENT_RECREATIONAL:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::PHYSICAL_CULTURE;              // "Инструктор-методист. Преподаватель",
        case ProfilingCode::NSPECDIR_MANAGEMENT_TOURISM_MNG:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::MANAGEMENT;                    // "Менеджер. Преподаватель",
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_MEDICAL:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::PHYSICAL_CULTURE;              // "Инструктор-методист. Преподаватель",
        case ProfilingCode::NSPECDIR_PHYSICAL_CULTURE_PRESCHOOLERS:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::PHYSICAL_CULTURE;              // "Инструктор-методист. Преподаватель",
        case ProfilingCode::NSPECDIR_IMPROVING_HEALTH:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::PHYSICAL_CULTURE;              // "Инструктор-методист. Преподаватель",
        case ProfilingCode::NSPECDIR_IMPROVING_ADAPTIVE:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::PHYSICAL_CULTURE;              // "Инструктор-методист. Преподаватель",
        case ProfilingCode::NSPECDIR_REHABILITATION_REHABILITATION:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::REHABILITATION;                // "Инструктор-методист. Преподаватель",
        case ProfilingCode::NSPECDIR_REHABILITATION_ERGOTHERAPY:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::REHABILITATION;                // "Инструктор-методист. Преподаватель",
        case ProfilingCode::NSPECDIR_TOURISM_HOSPITALITY:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::TOURISM;                       // "Специалист",
        case ProfilingCode::NSPECDIR_TOURISM_PROMOTION:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::TOURISM;                       // "Специалист",
        case ProfilingCode::NSPECDIR_TOURISM_IT:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::TOURISM;                       // "Специалист",
        case ProfilingCode::NSPECDIR_TOURISM_LOGISTICS:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::TOURISM;                       // "Специалист",
        case ProfilingCode::NSPECDIR_TOURISM_SOCIAL:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::TOURISM;                       // "Специалист",
        case ProfilingCode::NSPECDIR_TOURISM_TRANSPORT:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::TOURISM;                       // "Специалист",
        case ProfilingCode::NSPECDIR_TOURISM_CATERING:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::TOURISM;                       // "Специалист",
        case ProfilingCode::NSPECDIR_TOURISM_ACCOMMODATION:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::TOURISM;                       // "Специалист",
        case ProfilingCode::NSPECDIR_TOURISM_SUPPORTING:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::TOURISM;                       // "Специалист",
        case ProfilingCode::NSPECDIR_TOURISM_TREATMENT:
            return
                NCRB_011::_2022::QUALIFICATION::HIGH_SCHOOL::TOURISM;                       // "Специалист",
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_THEORY:
            return
                NCRB_011::_2022::QUALIFICATION::MASTER_DEGREE::SCIENCE::THEORY;             // "Магистр",
        case ProfilingCode::NSPECDIR_MASTER_SCIENCE_PHYSIOLOGY:
            return
                NCRB_011::_2022::QUALIFICATION::MASTER_DEGREE::SCIENCE::PHYSIOLOGY;         // "Магистр",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_SPORT:
            return
                NCRB_011::_2022::QUALIFICATION::MASTER_DEGREE::RESEARCH::SPORT;             // "Магистр",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TOURISM:
            return
                NCRB_011::_2022::QUALIFICATION::MASTER_DEGREE::INNOVATION::TOURISM;         // "Магистр туризма",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_HOSPITALITY:
            return
                NCRB_011::_2022::QUALIFICATION::MASTER_DEGREE::INNOVATION::HOSPITALITY;     // "Магистр гостеприимства",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_TECHNOLOGY:
            return
                NCRB_011::_2022::QUALIFICATION::MASTER_DEGREE::INNOVATION::TECHNOLOGIES;    // "Магистр инноваций",
        case ProfilingCode::NSPECDIR_MASTER_INNOVATION_MANAGEMENT:
            return
                NCRB_011::_2022::QUALIFICATION::MASTER_DEGREE::INNOVATION::MANAGEMENT;      // "Магистр управления",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_MANAGEMENT:
            return
                NCRB_011::_2022::QUALIFICATION::MASTER_DEGREE::RESEARCH::MANAGEMENT;        // "Магистр",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_PHYSICAL_CULTURE:
            return
                NCRB_011::_2022::QUALIFICATION::MASTER_DEGREE::RESEARCH::PHYSICAL_CULTURE;  // "Магистр",
        case ProfilingCode::NSPECDIR_MASTER_RESEARCH_TOURISM:
            return
                NCRB_011::_2022::QUALIFICATION::MASTER_DEGREE::RESEARCH::TOURISM;           // "Магистр",

        default:
            ShowMessage (
                "ERROR:\n"                                  \
                "The getQualification2022NameByNSpecDir "   \
                "(int nSpecDir) method returns:\n"          \
                "Value: "                                   +
                    AnsiString (nSpecDir)                   +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    nSpecDir
                );
    }
}
// SECTION
AnsiString InsteadDb::getSection2009NameByNSpec (const int nSpec)
{
    switch (static_cast <SectionCode> (nSpec))
    {
        case SectionCode::NSPEC_HIGH_SCHOOL_IMPROVING:
            return
                NCRB_011::_2009::SECTION::HIGH_SCHOOL::IMPROVING;                       // 5,  -> "Оздоровительная и адаптивная физическая культура",         // (по направлениям)
        case SectionCode::NSPEC_HIGH_SCHOOL_COACHING:
            return
                NCRB_011::_2009::SECTION::HIGH_SCHOOL::COACHING;                        // 6,  -> "Спортивно-педагогическая деятельность",                    // (по направлениям)
        case SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT:
            return
                NCRB_011::_2009::SECTION::HIGH_SCHOOL::MANAGEMENT;                      // 7,  -> "Спортивно-туристская деятельность",                        // (по направлениям)
        case SectionCode::NSPEC_HIGH_SCHOOL_PHYSICAL_CULTURE:
            return
                NCRB_011::_2009::SECTION::HIGH_SCHOOL::PHYSICAL_CULTURE;                // 8,  -> "Физическая культура",                                      // (по направлениям)
        case SectionCode::NSPEC_HIGH_SCHOOL_REHABILITATION:
            return
                NCRB_011::_2009::SECTION::HIGH_SCHOOL::REHABILITATION;                  // 9,  -> "Физическая реабилитация и эрготерапия",                    // (по направлениям)
        case SectionCode::NSPEC_HIGH_SCHOOL_TOURISM:
            return
                NCRB_011::_2009::SECTION::HIGH_SCHOOL::TOURISM;                         // 10, -> "Туризм и гостеприимство";
        case SectionCode::NSPEC_MASTER_SCIENCE_THEORY:
            return
                NCRB_011::_2009::SECTION::MASTER_DEGREE::SCIENCE::THEORY;               // 11, -> "Теория и методика физического воспитания, спортивной тренировки, оздоровительной",
        case SectionCode::NSPEC_MASTER_SCIENCE_PHYSIOLOGY:
            return
                NCRB_011::_2009::SECTION::MASTER_DEGREE::SCIENCE::PHYSIOLOGY;           // 12, -> "физиология";
        case SectionCode::NSPEC_MASTER_RESEARCH_SPORT:
            return
                NCRB_011::_2009::SECTION::MASTER_DEGREE::RESEARCH::SPORT;               // 13, -> "Теория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной ФК",
        case SectionCode::NSPEC_MASTER_INNOVATION_TOURISM:
            return
                NCRB_011::_2009::SECTION::MASTER_DEGREE::INNOVATION::TOURISM;           // 14, -> "Инновационный менеджмент в сфере туризма",
        case SectionCode::NSPEC_MASTER_INNOVATION_HOSPITALITY:
            return
                NCRB_011::_2009::SECTION::MASTER_DEGREE::INNOVATION::HOSPITALITY;       // 15, -> "Инновационный менеджмент в сфере гостеприимства",
        case SectionCode::NSPEC_MASTER_INNOVATION_TECHNOLOGY:
            return
                NCRB_011::_2009::SECTION::MASTER_DEGREE::INNOVATION::TECHNOLOGIES;      // 16, -> "Инновационные технологии в сфере туризма и гостеприимства",
        case SectionCode::NSPEC_MASTER_INNOVATION_MANAGEMENT:
            return
                NCRB_011::_2009::SECTION::MASTER_DEGREE::INNOVATION::MANAGEMENT;        // 17, -> "Управление инновационными проектами в туристской индустрии";
        case SectionCode::NSPEC_MASTER_RESEARCH_PHYSICAL_CULTURE:
            return
                NCRB_011::_2009::SECTION::MASTER_DEGREE::RESEARCH::PHYSICAL_CULTURE;    // 18, -> "Физическая культура и спорт",
        case SectionCode::NSPEC_MASTER_RESEARCH_TOURISM:
            return
                NCRB_011::_2009::SECTION::MASTER_DEGREE::RESEARCH::TOURISM;             // 19, -> "Туризм и гостеприимство";
        case SectionCode::NSPEC_MASTER_RESEARCH_MANAGEMENT:
            return
                NCRB_011::_2009::SECTION::MASTER_DEGREE::RESEARCH::MANAGEMENT;          // 20  -> "Менеджмент",

        default:
            ShowMessage (
                "ERROR:\n"                          \
                "The getSection2009NameByNSpec "    \
                "(int nSpec) method returns:\n"     \
                "Value: "                           +
                    AnsiString (nSpec)              +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    nSpec
                );
    }
}
AnsiString InsteadDb::getSection2022NameByNSpec (const int nSpec)                  // IMPORTANT!!! DO NOT USE THIS for 2022 Errors Possible. Use getProfiling2022NameByNSpecDir (int nSpecDir) instead.
{
    switch (static_cast <SectionCode> (nSpec))
    {
        case SectionCode::NSPEC_HIGH_SCHOOL_IMPROVING:                              // 5
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::PHYSICAL_CULTURE;               // "Физическая культура",
        case SectionCode::NSPEC_HIGH_SCHOOL_COACHING:                               // 6
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::COACHING;                       // "Тренерская деятельность",
        case SectionCode::NSPEC_HIGH_SCHOOL_MANAGEMENT:                             // 7
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::MANAGEMENT;                     // "Организация и управление физической культурой, спортом и туризмом";
        case SectionCode::NSPEC_HIGH_SCHOOL_PHYSICAL_CULTURE:                       // 8
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::PHYSICAL_CULTURE;               // "Физическая культура",
        case SectionCode::NSPEC_HIGH_SCHOOL_REHABILITATION:                         // 9
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::REHABILITATION;                 // "Физическая реабилитация и эрготерапия",
        case SectionCode::NSPEC_HIGH_SCHOOL_TOURISM:                                // 10
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                        // "Туризм и гостеприимство",
        case SectionCode::NSPEC_MASTER_SCIENCE_THEORY:                              // 11
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::SCIENCE::THEORY;              // "Теория и методика физического воспитания, спортивной тренировки, оздоровительной",
        case SectionCode::NSPEC_MASTER_SCIENCE_PHYSIOLOGY:                          // 12
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::SCIENCE::PHYSIOLOGY;          // "Физиология";
        case SectionCode::NSPEC_MASTER_RESEARCH_SPORT:                              // 13
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::RESEARCH::SPORT;              // "Tеория и методика физического воспитания, спортивной тренировки, оздоровительной и адаптивной физической культуры",
        case SectionCode::NSPEC_MASTER_INNOVATION_TOURISM:                          // 14
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::INNOVATION::TOURISM;          // "Инновационный менеджмент в сфере туризма",
        case SectionCode::NSPEC_MASTER_INNOVATION_HOSPITALITY:                      // 15
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::INNOVATION::HOSPITALITY;      // "Инновационный менеджмент в сфере гостеприимства",
        case SectionCode::NSPEC_MASTER_INNOVATION_TECHNOLOGY:                       // 16
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::INNOVATION::TECHNOLOGIES;     // "Инновационные технологии в сфере туризма и гостеприимства",
        case SectionCode::NSPEC_MASTER_INNOVATION_MANAGEMENT:                       // 17
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::INNOVATION::MANAGEMENT;       // Управление инновационными проектами в туристской индустрии";
        case SectionCode::NSPEC_MASTER_RESEARCH_PHYSICAL_CULTURE:                   // 18
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::RESEARCH::PHYSICAL_CULTURE;   // "Физическая культура и спорт",
        case SectionCode::NSPEC_MASTER_RESEARCH_TOURISM:                            // 19
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::RESEARCH::TOURISM;            // "Туризм и гостеприимство",
        case SectionCode::NSPEC_MASTER_RESEARCH_MANAGEMENT:                         // 20
            return
                NCRB_011::_2022::NAME::MASTER_DEGREE::RESEARCH::MANAGEMENT;         // "Менеджмент";

        default:
            ShowMessage (
                "ERROR:\n"                          \
                "The getSection2022NameByNSpec "    \
                "(int nSpec) method returns:\n"     \
                "Value: "                           +
                    AnsiString (nSpec)              +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    nSpec
                );
    }
}
AnsiString InsteadDb::getSection2022NameById (const int id)
{
    switch (static_cast <Section2022Code> (id))
    {
        case Section2022Code::PHYSICAL_CULTURE_2022:                            // 0 -> 6-05-1012-01
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::PHYSICAL_CULTURE;           // 0 -> "Физическая культура",
        case Section2022Code::COACHING_2022:                                    // 1 -> 6-05-1012-02
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::COACHING;                   // 1 -> "Тренерская деятельность",
        case Section2022Code::REHABILITATION_2022:                              // 2 -> 6-05-1012-03
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::REHABILITATION;             // 2 -> "Физическая реабилитация и эрготерапия",
        case Section2022Code::MANAGEMENT_2022:                                  // 3 -> 6-05-1012-04
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::MANAGEMENT;                 // 3 -> "Организация и управление физической культурой, спортом и туризмом";
        case Section2022Code::TOURISM_2022:                                     // 4 -> 6-05-1013-01
            return
                NCRB_011::_2022::NAME::HIGH_SCHOOL::TOURISM;                    // 4 -> "Туризм и гостеприимство",

        default:
            ShowMessage (
                "ERROR:\n"                          \
                "The getSection2022NameByCode "     \
                "(const int id) method returns:\n"  \
                "Value: "                           +
                    AnsiString (id)                 +
                "\t - The code does not exist!"
            );
            return
                AnsiString (
                    id
                );
    }
}
