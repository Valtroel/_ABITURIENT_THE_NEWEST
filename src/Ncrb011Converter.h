#pragma once
#ifndef NCRB_011_CONVERTER_H
#define NCRB_011_CONVERTER_H

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#ifdef DATABASE_SUBSTITUTE
#include "enums.hpp"
#include "properties.hpp"

namespace Substitute
{
    class TForm1
        : public TForm
    {
    __published:

    private:

    public:
        __fastcall TForm1 (TComponent * Owner);

        // get CODE
        AnsiString getNcrb2009CodeByNSpecializ              (const int nSpecializ);
        AnsiString getNcrb2022CodeByNSpecializ              (const int nSpecializ);
        AnsiString getNcrb2022CodeByNSpecializFH            (const int nSpecializ);
        // get NAME
        AnsiString getNcrb2009FullNameByNSpecializ          (const int nSpecializ);
        AnsiString getNcrb2022FullNameByNSpecializ          (const int nSpecializ);
        AnsiString getProfiling2009NameByNSpecializ         (const int nSpecializ);
        AnsiString getProfiling2022NameByNSpecializ         (const int nSpecializ);
        AnsiString getSection2009NameByNspecializ           (const int nSpecializ);
        AnsiString getSection2022CodeNameById               (const int id);
        // get KIND OF SPORT
        AnsiString getKindOfSportAsPostfix                  (const int nSpecializ);
        AnsiString getKindOfSportDativeCaseForCoaching      (const int nSpecializ);
        // get GRADE
        AnsiString getQualification2009NameByNSpecializ     (const int nSpecializ);
        AnsiString getQualification2022NameByNSpecializ     (const int nSpecializ);


        // AUXILIARY
        AnsiString escapingStringWithDoubleQuotes           (
                const AnsiString wrappingString
            );
        AnsiString escapingStringWithParentheses            (
                const AnsiString wrappingString
            );
        AnsiString profilingToPostfix                       (
                const AnsiString profiling
            );


        // CONTROL        (Require: enums.hpp)
        int        getProfilingCodeByNSpecializ             (const int nSpecializ);
        int        getSectionCodeByNSpecializ               (const int nSpecializ);
        int        getSectionCodeByNSpecDir                 (const int nSpecDir);
        int        getFacultyCodeByNSpecializ               (const int nSpecializ);


        // CODE           (Require: enums.hpp and properties.hpp)
        AnsiString getNcrb2022CodeById                      (const int id);
        // KIND OF SPORTS (Require: enums.hpp and properties.hpp)
        AnsiString getKindOfSportNameByNSpecializ           (const int nSpecializ);
        AnsiString getKindOfSportNameDativeCaseByNSpecializ (const int nSpecializ);
        AnsiString getNcrb2022CodeByNSpecializ1stHand       (const int nSpecializ);
        // PROFILING      (Require: enums.hpp and properties.hpp)
        AnsiString getProfiling2009NameByNSpecDir           (const int nSpecDir);
        AnsiString getProfiling2022NameByNSpecDir           (const int nSpecDir);
        AnsiString getNcrb2009CodeByNSpecDir                (const int nSpecDir);
        AnsiString getNcrb2022CodeByNSpecDir                (const int nSpecDir);
        AnsiString getQualification2009NameByNSpecDir       (const int nSpecDir);
        AnsiString getQualification2022NameByNSpecDir       (const int nSpecDir);
        // SECTION        (Require: enums.hpp and properties.hpp)
        AnsiString getSection2009NameByNSpec                (const int nSpec);
        AnsiString getSection2022NameByNSpec                (const int nSpec);      // IMPORTANT!!! DO NOT USE THIS for 2022 Errors Possible. Use getProfiling2022NameByNSpecDir (int nSpecDir) instead.
        AnsiString getSection2022NameById                   (const int id);
    };
}
extern PACKAGE Substitute::TForm1 * Form1;
#endif  // DATABASE_SUBSTITUTE

#endif  // NCRB_011_CONVERTER_H
