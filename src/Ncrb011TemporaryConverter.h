#pragma once
#ifndef NCRB_011_TEMPORARY_CONVERTER_H
#define NCRB_011_TEMPORARY_CONVERTER_H


#include "enums.hpp"
#include "properties.hpp"

namespace DeleteAfterDatabaseChange
{
    AnsiString getNcrb2022CodeByNSpecializ                  (
            int deanerySpesializNSpecializ
        );
    AnsiString getNcrb2022NameSportStrByNSpecializ          (
            int deanerySpesializNSpecializ
        );
    AnsiString getNcrb2022CodeNameSportStrByNSpecializ      (
            int deanerySpesializNSpecializ
        );
    AnsiString getNcrb2022QualificationNameByNSpecializ     (
            int deanerySpesializNSpecializ
        );

    AnsiString getNcrb2022CodeDirectConversionByNSpecializ (
            int deanerySpesializNSpecializ
        );


    AnsiString getQualification2009                         (
            int deaneryQualificationNomerQu
        );
    AnsiString getQualification2022                         (
            int deaneryQualificationNomerQu
        );


    AnsiString getKindOfSportNameByNSpecializ               (
            int deanerySpesializNSpecializ
        );
    AnsiString getKindOfSportNameDativeCaseByNSpecializ     (
            int deanerySpesializNSpecializ
        );
    int        getFacultyCodeByNSpecializ                   (
            int deanerySpesializNSpecializ
        );
    int        getNSpecCodeByNSpesializ                     (
            int deanerySpesializNSpecializ
        );
    int        getNSpecDirCodeByNSpecializ                  (
            int deanerySpesializNSpecializ
        );


    AnsiString getNcrb2022CodeByNSpec                       (
            int deanerySpecialityNSpecCode
        );
    AnsiString getSpecialityName2022ByNSpec                 (
            int deanerySpecialityNSpecCode
        );
    AnsiString getNcrb2022QualificationByNSpec              (
            int deanerySpecialityNSpec
        );


    AnsiString getNcrb2009CodeByNSpecDir                    (
            int deanerySpecialDirectionNSpecDirCode
        );
    AnsiString getNcrb2022CodeByNSpecDir                    (
            int deanerySpecialDirectionNSpecDirCode
        );
    AnsiString getDirectionName2022ByNSpecDirNSpecializ     (
            int deanerySpecialDirectionNSpecDirCode,
            int deanerySpecializNSpecializ
        );
    int        getNSpecCodeByNSpecDir                       (
            int deanerySpecialDirectionNSpecDirCode
        );
}


// EVERYTHING BELOW TO DO A LITTLE LATER
/*
namespace ToDoLater
{
    AnsiString getSpecialityName2009ByNSpecDir (
            int deanerySpecialDirectionNSpecDirCode
        );
    AnsiString getQualificationName2009 (
            int deanerySpecialDirectionNSpecDirCode
        );
    AnsiString getCodeSpecializByNSpesializ (
            int specialityCode
        );
    AnsiString getDirectionNameByNSpecializ (
            int specialityCode
        );
    AnsiString getDirectionShortName (
            int specialityCode
        );
}
*/

#endif  // NCRB_011_TEMPORARY_CONVERTER_H

