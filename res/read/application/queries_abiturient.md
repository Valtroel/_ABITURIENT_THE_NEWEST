# [ABITURIENT (*application*)](app_abiturient_2022.md) > [DMUnit](DMUnit/DMUnit.md) > TFDQuery

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../db/db_abiturient_2022.md)

> **ABBREVIATIONS IN THE TABLE**:</br>
> ***CN*** - connection to database;</br>
> ***dean*** - connect to "*Deanery*" database, other - to "*Abiturient*"</br>
> ***DS*** - has a *TDataSource*</br>
> ***Up*** - has a *TFDUpdateSQL*  

-- TFDConnection

[]: DMUnit/TFDConnection/FDConnection1.md
[]: DMUnit/TFDConnection/FDConnection2.md

-- TFDPhysFBDriverLink

[]: DMUnit/TFDPhysFBDriverLink/FDPhysFBDriverLink1.md

|             *Component name* |     *Type*     | *CN* | *Description*    |
|-----------------------------:|:--------------:|:----:|:-----------------|
|               [BlockDS][ds1] | TDataSource \* |      |                  |
|            [CkRegionDS][ds2] | TDataSource \* | Dean |                  |
|            [CntrExrcDS][ds3] | TDataSource \* |      |                  |
|             [CountryDS][ds4] | TDataSource \* | Dean |                  |
|                [DSAb_P][ds5] | TDataSource \* |      |                  |
|         [DSAb_Pr_Enter][ds6] | TDataSource \* |      |                  |
|   [DSAbitur_Priv_Enter][ds7] | TDataSource \* |      |                  |
|             [DSAbitura][ds8] | TDataSource \* |      |                  |
|         [DSAdd_N_Group][ds9] | TDataSource \* |      |                  |
|             [DSAdress][ds10] | TDataSource \* | Dean |                  |
|               [DSBall][ds11] | TDataSource \* |      |                  |
|           [DSCategory][ds12] | TDataSource \* |      |                  |
|             [DSCenter][ds13] | TDataSource \* | Dean |                  |
|                 [DSCk][ds14] | TDataSource \* |      |                  |
|                [DSCkQ][ds15] | TDataSource \* |      |                  |
|        [DSCkToDekanat][ds16] | TDataSource \* | Dean |                  |
|           [DSDistrict][ds17] | TDataSource \* | Dean |                  |
|              [DSDocum][ds18] | TDataSource \* |      |                  |
|          [DSEducation][ds19] | TDataSource \* |      |                  |
|             [DSEduDoc][ds20] | TDataSource \* |      |                  |
|               [DSExam][ds21] | TDataSource \* |      |                  |
|           [DSExamSpec][ds22] | TDataSource \* |      |                  |
|            [DSFaculty][ds23] | TDataSource \* | Dean |                  |
|         [DSFoundation][ds24] | TDataSource \* | Dean |                  |
|   [DSGroup_Count_Spec][ds25] | TDataSource \* |      |                  |
|        [DSGroup_Count][ds26] | TDataSource \* |      |                  |
|         [DSInc_Gr_Old][ds27] | TDataSource \* | Dean |                  |
|          [DSKol_Place][ds28] | TDataSource \* |      |                  |
|           [DSLangvich][ds29] | TDataSource \* | Dean |                  |
|  [DSLangvichToDekanat][ds30] | TDataSource \* | Dean |                  |
|   [DSLittle_Spisoc_GR][ds31] | TDataSource \* |      |                  |
|           [DSLocality][ds32] | TDataSource \* | Dean |                  |
|       [DSMax_Nom_Dela][ds33] | TDataSource \* |      |                  |
|       [DSMax_Nomer_Ab][ds34] | TDataSource \* |      |                  |
|            [DSPasport][ds35] | TDataSource \* | Dean |                  |
|          [DSPass_User][ds36] | TDataSource \* | Dean |                  |
|      [DSPersonalDocum][ds37] | TDataSource \* | Dean |                  |
|     [DSPlan_Priem_All][ds38] | TDataSource \* |      |                  |
|      [DSPlan_Priem_CK][ds39] | TDataSource \* |      |                  |
|            [DSPredmet][ds40] | TDataSource \* |      |                  |
|      [DSPrivToDekanat][ds41] | TDataSource \* | Dean |                  |
|    [DSQSertificat_Res][ds42] | TDataSource \* |      |                  |
|            [DSQShkala][ds43] | TDataSource \* |      |                  |
|      [DSRegion_Center][ds44] | TDataSource \* | Dean |                  |
|             [DSRegion][ds45] | TDataSource \* |      |                  |
|        [DSReport_Rasp][ds46] | TDataSource \* |      |                  |
|        [DSResult_Exam][ds47] | TDataSource \* |      |                  |
|          [DSSelect_ab][ds48] | TDataSource \* |      |                  |
|         [DSSertificat][ds49] | TDataSource \* |      |                  |
|   [DSShow_Result_Exam][ds50] | TDataSource \* |      |                  |
|          [DSSpecializ][ds51] | TDataSource \* |      |                  |
|[DSSpecializPlan_Priem][ds52] | TDataSource \* |      |                  |
|   [DSSpisoc_Group_Pol][ds53] | TDataSource \* |      |                  |
|       [DSSpisoc_Group][ds54] | TDataSource \* |      |                  |
|[DSStatistic_Every_Day][ds55] | TDataSource \* |      |                  |
|             [DSStreet][ds56] | TDataSource \* | Dean |                  |
|     [DSSum_Ball_Nomer][ds57] | TDataSource \* |      |                  |
|           [DSSum_Ball][ds58] | TDataSource \* |      |                  |
|          [DSToDekanat][ds59] | TDataSource \* | Dean |                  |
|      [DSType_locality][ds60] | TDataSource \* | Dean |                  |
|        [DSType_street][ds61] | TDataSource \* | Dean |                  |
|          [DSUndo_Abit][ds62] | TDataSource \* |      |                  |
|          [DSVid_Sport][ds63] | TDataSource \* | Dean |                  |
|              [ExercDS][ds64] | TDataSource \* |      |                  |
|          [FIOSearchDS][ds65] | TDataSource \* |      |                  |
|[Increment_GroupSource][ds66] | TDataSource \* | Dean |                  |
|          [ListDocFDDS][ds67] | TDataSource \* |      |                  |
|[Selection_CommitteeDS][ds68] | TDataSource \* |      |                  |
|          [SpecializDS][ds69] | TDataSource \* | Dean |                  |
|       [SPFDDataSource][ds70] | TDataSource \* | Dean |                  |
|         [SportQSource][ds71] | TDataSource \* | Dean |                  |

[ds1]:  DMUnit/TDataSource/BlockDS.md
[ds2]:  DMUnit/TDataSource/CkRegionDS.md
[ds3]:  DMUnit/TDataSource/CntrExrcDS.md
[ds4]:  DMUnit/TDataSource/CountryDS.md
[ds5]:  DMUnit/TDataSource/DSAb_P.md
[ds6]:  DMUnit/TDataSource/DSAb_Pr_Enter.md
[ds7]:  DMUnit/TDataSource/DSAbitur_Priv_Enter.md
[ds8]:  DMUnit/TDataSource/DSAbitura.md
[ds9]:  DMUnit/TDataSource/DSAdd_N_Group.md
[ds10]: DMUnit/TDataSource/DSAdress.md
[ds11]: DMUnit/TDataSource/DSBall.md
[ds12]: DMUnit/TDataSource/DSCategory.md
[ds13]: DMUnit/TDataSource/DSCenter.md
[ds14]: DMUnit/TDataSource/DSCk.md
[ds15]: DMUnit/TDataSource/DSCkQ.md
[ds16]: DMUnit/TDataSource/DSCkToDekanat.md
[ds17]: DMUnit/TDataSource/DSDistrict.md
[ds18]: DMUnit/TDataSource/DSDocum.md
[ds19]: DMUnit/TDataSource/DSEducation.md
[ds20]: DMUnit/TDataSource/DSEduDoc.md
[ds21]: DMUnit/TDataSource/DSExam.md
[ds22]: DMUnit/TDataSource/DSExamSpec.md
[ds23]: DMUnit/TDataSource/DSFaculty.md
[ds24]: DMUnit/TDataSource/DSFoundation.md
[ds25]: DMUnit/TDataSource/DSGroup_Count_Spec.md
[ds26]: DMUnit/TDataSource/DSGroup_Count.md
[ds27]: DMUnit/TDataSource/DSInc_Gr_Old.md
[ds28]: DMUnit/TDataSource/DSKol_Place.md
[ds29]: DMUnit/TDataSource/DSLangvich.md
[ds30]: DMUnit/TDataSource/DSLangvichToDekanat.md
[ds31]: DMUnit/TDataSource/DSLittle_Spisoc_GR.md
[ds32]: DMUnit/TDataSource/DSLocality.md
[ds33]: DMUnit/TDataSource/DSMax_Nom_Dela.md
[ds34]: DMUnit/TDataSource/DSMax_Nomer_Ab.md
[ds35]: DMUnit/TDataSource/DSPasport.md
[ds36]: DMUnit/TDataSource/DSPass_User.md
[ds37]: DMUnit/TDataSource/DSPersonalDocum.md
[ds38]: DMUnit/TDataSource/DSPlan_Priem_All.md
[ds39]: DMUnit/TDataSource/DSPlan_Priem_CK.md
[ds40]: DMUnit/TDataSource/DSPredmet.md
[ds41]: DMUnit/TDataSource/DSPrivToDekanat.md
[ds42]: DMUnit/TDataSource/DSQSertificat_Res.md
[ds43]: DMUnit/TDataSource/DSQShkala.md
[ds44]: DMUnit/TDataSource/DSRegion_Center.md
[ds45]: DMUnit/TDataSource/DSRegion.md
[ds46]: DMUnit/TDataSource/DSReport_Rasp.md
[ds47]: DMUnit/TDataSource/DSResult_Exam.md
[ds48]: DMUnit/TDataSource/DSSelect_ab.md
[ds49]: DMUnit/TDataSource/DSSertificat.md
[ds50]: DMUnit/TDataSource/DSShow_Result_Exam.md
[ds51]: DMUnit/TDataSource/DSSpecializ.md
[ds52]: DMUnit/TDataSource/DSSpecializPlan_Priem.md
[ds53]: DMUnit/TDataSource/DSSpisoc_Group_Pol.md
[ds54]: DMUnit/TDataSource/DSSpisoc_Group.md
[ds55]: DMUnit/TDataSource/DSStatistic_Every_Day.md
[ds56]: DMUnit/TDataSource/DSStreet.md
[ds57]: DMUnit/TDataSource/DSSum_Ball_Nomer.md
[ds58]: DMUnit/TDataSource/DSSum_Ball.md
[ds59]: DMUnit/TDataSource/DSToDekanat.md
[ds60]: DMUnit/TDataSource/DSType_locality.md
[ds61]: DMUnit/TDataSource/DSType_street.md
[ds62]: DMUnit/TDataSource/DSUndo_Abit.md
[ds63]: DMUnit/TDataSource/DSVid_Sport.md
[ds64]: DMUnit/TDataSource/ExercDS.md
[ds65]: DMUnit/TDataSource/FIOSearchDS.md
[ds66]: DMUnit/TDataSource/Increment_GroupSource.md
[ds67]: DMUnit/TDataSource/ListDocFDDS.md
[ds68]: DMUnit/TDataSource/Selection_CommitteeDS.md
[ds69]: DMUnit/TDataSource/SpecializDS.md
[ds70]: DMUnit/TDataSource/SPFDDataSource.md
[ds71]: DMUnit/TDataSource/SportQSource.md

---
</br>

|                        *Component name* |    *Type*   | *CN* | *DS* | *Up* | *Description*    |
|----------------------------------------:|:-----------:|:----:|:----:|:----:|:-----------------|
|                      [AbiturCompQr][q1] | TFDQuery \* |      |      |      |  |
|                    [AbiturInvTmpQr][q2] | TFDQuery \* |      |      |      |  |
|                    [AbiturLogInsQr][q3] | TFDQuery \* |      |      |      |  |
|                    [AbiturSirTmpQr][q4] | TFDQuery \* |      |      |      |  |
|                       [AddrLogUpQr][q5] | TFDQuery \* |      |      |      |  |
|                        [AdresOutQr][q6] | TFDQuery \* |      |      |      |  |
|                      [AdrLogLastQr][q7] | TFDQuery \* |      |      |      |  |
|                        [BlockBtnQr][q8] | TFDQuery \* |      |      |      |  |
|                            [BlockQ][q9] | TFDQuery \* |      |  DS  |  Up  |  |
|                        [CategUpQr][q10] | TFDQuery \* |      |      |      |  |
|                 [CertificLogInsQr][q11] | TFDQuery \* |      |      |      |  |
|                       [CkRegionQr][q12] | TFDQuery \* | Dean |  DS  |      |  |
|                      [CntrlExrcQr][q13] | TFDQuery \* |      |  DS  |      |  |
|                      [ContrySelQr][q14] | TFDQuery \* |      |      |      |  |
|                        [CountryQr][q15] | TFDQuery \* | Dean |  DS  |      |  |
|                         [DocumFDQ][q16] | TFDQuery \* |      |      |      |  |
|                     [DocumInListQ][q17] | TFDQuery \* |      |      |      |  |
|                      [FIOSearchQr][q18] | TFDQuery \* |      |      |      |  |
|               [GrazdanToDekanatQr][q19] | TFDQuery \* | Dean |      |      |  |
|                      [IdAbQueueQr][q20] | TFDQuery \* |      |      |      |  |
|                         [InfCntQr][q21] | TFDQuery \* |      |      |      |  |
|                            [InfQr][q22] | TFDQuery \* |      |      |      |  |
|                   [KodSpecializQr][q23] | TFDQuery \* | Dean |      |      |  |
|                        [LangSelQr][q24] | TFDQuery \* | Dean |      |      |  |
|                       [ListDocFDQ][q25] | TFDQuery \* |      |  DS  |  Up  |  |
|                       [LogIDSelQr][q26] | TFDQuery \* |      |      |      |  |
|                        [LogLastQr][q27] | TFDQuery \* |      |      |      |  |
|                        [MaxExrcQr][q28] | TFDQuery \* |      |      |      |  |
|                      [OtherPrivQr][q29] | TFDQuery \* |      |      |      |  |
|                         [OutCntQr][q30] | TFDQuery \* |      |      |      |  |
|                         [OutDetQr][q31] | TFDQuery \* |      |      |      |  |
|                            [OutQr][q32] | TFDQuery \* |      |      |      |  |
|                        [OutTestQr][q33] | TFDQuery \* |      |      |      |  |
|                       [PasportFDQ][q34] | TFDQuery \* | Dean |  DS  |      |  |
|                       [PrintDocQr][q35] | TFDQuery \* |      |      |      |  |
|                       [PrivCnttQr][q36] | TFDQuery \* |      |      |      |  |
|                 [PrivilegLogSelQr][q37] | TFDQuery \* |      |      |      |  |
|                           [PrivQr][q38] | TFDQuery \* |      |      |      |  |
|                            [QAb_P][q39] | TFDQuery \* |      |  DS  |  Up  |  |
|                     [QAb_Pr_Enter][q40] | TFDQuery \* |      |  DS  |      |  |
|                        [QAbFIOPol][q41] | TFDQuery \* |      |      |      |  |
|               [QAbitur_Priv_Enter][q42] | TFDQuery \* |      |  DS  |  Up  |  |
|                         [QAbitura][q43] | TFDQuery \* |      |  DS  |      |  |
|                     [QAdd_N_Group][q44] | TFDQuery \* |      |  DS  |      |  |
|                          [QAdress][q45] | TFDQuery \* | Dean |  DS  |      |  |
|                          [QCenter][q46] | TFDQuery \* | Dean |  DS  |  Up  |  |
|                     [QCK_Kol_Plan][q47] | TFDQuery \* |      |      |      |  |
|                              [QCk][q48] | TFDQuery \* |      |  DS  |      |  |
|                     [QCkToDekanat][q49] | TFDQuery \* | Dean |  DS  |  Up  |  |
|                   [QControl_Exerc][q50] | TFDQuery \* |      |      |      |  |
|                          [QDelite][q51] | TFDQuery \* |      |      |      |  |
|                        [QDistrict][q52] | TFDQuery \* | Dean |  DS  |      |  |
|                       [QEducation][q53] | TFDQuery \* |      |  DS  |      |  |
|                            [QExam][q54] | TFDQuery \* |      |  DS  |      |  |
|                        [QExamSpec][q55] | TFDQuery \* |      |  DS  |      |  |
|                       [QExerc_Grp][q56] | TFDQuery \* |      |      |      |  |
|                 [QFindAbiturExerc][q57] | TFDQuery \* |      |      |      |  |
|                        [QFotoQeue][q58] | TFDQuery \* |      |      |      |  |
|                        [QFotoSign][q59] | TFDQuery \* |      |      |  Up  |  |
|                      [QGIAC2kSpec][q60] | TFDQuery \* |      |      |      |  |
|                       [QGIAC3Sert][q61] | TFDQuery \* |      |      |      |  |
|                         [QGIACAll][q62] | TFDQuery \* |      |      |      |  |
|                 [QGIACAllPrivileg][q63] | TFDQuery \* |      |      |      |  |
|                [QGIACAllPrivileg1][q64] | TFDQuery \* |      |      |      |  |
|                     [QGIACAllSpec][q65] | TFDQuery \* |      |      |      |  |
|                      [QGIACCKSpec][q66] | TFDQuery \* |      |      |      |  |
|                       [QGIACEdLic][q67] | TFDQuery \* |      |      |      |  |
|                     [QGIACEdOSred][q68] | TFDQuery \* |      |      |      |  |
|                 [QGIACEdOSredCity][q69] | TFDQuery \* |      |      |      |  |
|                  [QGIACEdOSredVil][q70] | TFDQuery \* |      |      |      |  |
|                   [QGIACForeigner][q71] | TFDQuery \* |      |      |      |  |
|                       [QGIACInAll][q72] | TFDQuery \* |      |      |      |  |
|                       [QGIACInCel][q73] | TFDQuery \* |      |      |      |  |
|                       [QGIACKursi][q74] | TFDQuery \* |      |      |      |  |
|                       [QGIACMedal][q75] | TFDQuery \* |      |      |      |  |
|                         [QGIACMil][q76] | TFDQuery \* |      |      |      |  |
|                       [QGIACOlimp][q77] | TFDQuery \* |      |      |      |  |
|                         [QGIACPtu][q78] | TFDQuery \* |      |      |      |  |
|                       [QGIACSirot][q79] | TFDQuery \* |      |      |      |  |
|                    [QGIACYearSred][q80] | TFDQuery \* |      |      |      |  |
|                [QGIACYearSredCity][q81] | TFDQuery \* |      |      |      |  |
|                [QGIACYearSredSpec][q82] | TFDQuery \* |      |      |      |  |
|                 [QGIACYearSredVil][q83] | TFDQuery \* |      |      |      |  |
|                [QGroup_Count_Spec][q84] | TFDQuery \* |      |  DS  |      |  |
|                     [QGroup_Count][q85] | TFDQuery \* |      |  DS  |      |  |
|                      [QInc_Gr_Old][q86] | TFDQuery \* | Dean |  DS  |  Up  |  |
|                              [QIP][q87] | TFDQuery \* | Dean |      |      |  |
|                         [QKod_Fac][q88] | TFDQuery \* | Dean |      |      |  |
|                        [QKod_Spec][q89] | TFDQuery \* | Dean |      |      |  |
|                        [QLangvich][q90] | TFDQuery \* | Dean |  DS  |      |  |
|               [QLangvichToDekanat][q91] | TFDQuery \* | Dean |  DS  |  Up  |  |
|                    [QLetterSource][q92] | TFDQuery \* |      |      |      |  |
|                 [QLetterSourceKol][q93] | TFDQuery \* |      |      |      |  |
|                [QListDocToDekanat][q94] | TFDQuery \* | Dean |      |  Up  |  |
|                [QLittle_Spisoc_GR][q95] | TFDQuery \* |      |  DS  |      |  |
|                        [QLocality][q96] | TFDQuery \* | Dean |  DS  |      |  |
|                    [QMax_Nom_Dela][q97] | TFDQuery \* |      |  DS  |      |  |
|                    [QMax_Nomer_Ab][q98] | TFDQuery \* |      |  DS  |      |  |
|                         [QN_group][q99] | TFDQuery \* |      |      |      |  |
|                      [QNoticeFac][q100] | TFDQuery \* | Dean |      |      |  |
|                      [QNoticeFIO][q101] | TFDQuery \* |      |      |      |  |
|                     [QNoticeSpec][q102] | TFDQuery \* | Dean |      |      |  |
|                  [QPersonalDocum][q103] | TFDQuery \* | Dean |      |      |  |
|         [QPlan_Priem_All_Special][q104] | TFDQuery \* |      |      |      |  |
|                 [QPlan_Priem_All][q105] | TFDQuery \* |      |      |      |  |
|          [QPlan_Priem_CK_Special][q106] | TFDQuery \* |      |      |      |  |
|                  [QPlan_Priem_CK][q107] | TFDQuery \* |      |      |      |  |
|      [QPlan_Priem_Konk_All_Param][q108] | TFDQuery \* |      |      |      |  |
|        [QPlan_Priem_Konk_Special][q109] | TFDQuery \* |      |      |      |  |
|                [QPlan_Priem_Konk][q110] | TFDQuery \* |      |      |      |  |
|               [QPlan_Priem_Price][q111] | TFDQuery \* |      |      |      |  |
|                [QPlanPriem2Price][q112] | TFDQuery \* |      |      |      |  |
|                 [QPlanPriemPrice][q113] | TFDQuery \* |      |      |      |  |
|                  [QPrivToDekanat][q114] | TFDQuery \* | Dean |      |      |  |
|                  [QProverka_RYOR][q115] | TFDQuery \* |      |      |      |  |
|                  [QProverka_sert][q116] | TFDQuery \* |      |      |      |  |
|                  [QRegion_Center][q117] | TFDQuery \* | Dean |      |      |  |
|                    [QRep_Abitura][q118] | TFDQuery \* |      |      |      |  |
|                  [QRep_Sel_Exerc][q119] | TFDQuery \* |      |      |      |  |
|                    [QReport_Rasp][q120] | TFDQuery \* |      |      |      |  |
|                    [QResult_Exam][q121] | TFDQuery \* |      |      |      |  |
|                      [QSelect_ab][q122] | TFDQuery \* |      |      |      |  |
|             [QSertificat_ex_list][q123] | TFDQuery \* |      |      |      |  |
|                 [QSertificat_Res][q124] | TFDQuery \* |      |      |      |  |
|                     [QSertificat][q125] | TFDQuery \* |      |      |      |  |
|            [QSertificatToDekanat][q126] | TFDQuery \* | Dean |      |      |  |
|                         [QShkala][q127] | TFDQuery \* |      |      |      |  |
|               [QShow_Result_Exam][q128] | TFDQuery \* |      |      |      |  |
|                      [QSpecializ][q129] | TFDQuery \* |      |      |      |  |
|            [QSpecializPlan_Priem][q130] | TFDQuery \* |      |      |      |  |
|               [QSpisoc_Group_Pol][q131] | TFDQuery \* |      |      |      |  |
|                   [QSpisoc_Group][q132] | TFDQuery \* |      |      |      |  |
|                    [QSpisok_Spec][q133] | TFDQuery \* |      |      |      |  |
| [QStatistic_Every_Day_Ball_Price][q134] | TFDQuery \* |      |      |      |  |
|       [QStatistic_Every_Day_Ball][q135] | TFDQuery \* |      |      |      |  |
|    [QStatistic_Every_Day_Special][q136] | TFDQuery \* |      |      |      |  |
|            [QStatistic_Every_Day][q137] | TFDQuery \* |      |      |      |  |
|              [QStatisticEveryDay][q138] | TFDQuery \* |      |      |      |  |
|                         [QStreet][q139] | TFDQuery \* | Dean |      |      |  |
|                 [QSum_Ball_Nomer][q140] | TFDQuery \* |      |      |      |  |
|                       [QSum_Ball][q141] | TFDQuery \* |      |      |      |  |
|                      [QToDekanat][q142] | TFDQuery \* | Dean |      |      |  |
|                  [QType_locality][q143] | TFDQuery \* | Dean |      |      |  |
|                    [QType_street][q144] | TFDQuery \* | Dean |      |      |  |
|                      [QUndo_Abit][q145] | TFDQuery \* |      |      |      |  |
|                    [RegionNameQr][q146] | TFDQuery \* | Dean |      |      |  |
|                        [RegionQr][q147] | TFDQuery \* | Dean |      |      |  |
|                    [RegionUpCKQr][q148] | TFDQuery \* |      |      |      |  |
|               [SelectLogAbiturQr][q149] | TFDQuery \* |      |      |      |  |
|                    [SelPrivLogQr][q150] | TFDQuery \* |      |      |      |  |
|                 [SerteficatSelQr][q151] | TFDQuery \* |      |      |      |  |
|                    [SertSelLogQr][q152] | TFDQuery \* |      |      |      |  |
|                       [SpecFacQr][q153] | TFDQuery \* | Dean |      |      |  |
|                 [SpecializNameQr][q154] | TFDQuery \* | Dean |      |      |  |
|                     [SpecializQr][q155] | TFDQuery \* | Dean |      |      |  |
|                          [SpecQr][q156] | TFDQuery \* | Dean |      |      |  |
|                           [SPFDQ][q157] | TFDQuery \* | Dean |      |      |  |
|                          [SPFDQ1][q158] | TFDQuery \* |      |      |      |  |
|                      [SportQuery][q159] | TFDQuery \* |      |      |      |  |
|                          [SspecQ][q160] | TFDQuery \* |      |      |      |  |
|                    [Stat3hAll1Qr][q161] | TFDQuery \* |      |      |      |  |
|                    [Stat3hAll2Qr][q162] | TFDQuery \* |      |      |      |  |
|                   [StatusQueueQr][q163] | TFDQuery \* |      |      |      |  |
|                     [UpDateOutQr][q164] | TFDQuery \* |      |      |      |  |
|                 [VO2KSpecializQr][q165] | TFDQuery \* |      |      |      |  |
|                    [WithoutCntQr][q166] | TFDQuery \* |      |      |      |  |
|                    [WithoutDetQr][q167] | TFDQuery \* |      |      |      |  |
|                       [WithoutQr][q168] | TFDQuery \* |      |      |      |  |
|                [WithOutTestLogQr][q169] | TFDQuery \* |      |      |      |  |

[q1]:   DMUnit/TFDQuery/AbiturCompQr.md
[q2]:   DMUnit/TFDQuery/AbiturInvTmpQr.md
[q3]:   DMUnit/TFDQuery/AbiturLogInsQr.md
[q4]:   DMUnit/TFDQuery/AbiturSirTmpQr.md
[q5]:   DMUnit/TFDQuery/AddrLogUpQr.md
[q6]:   DMUnit/TFDQuery/AdresOutQr.md
[q7]:   DMUnit/TFDQuery/AdrLogLastQr.md
[q8]:   DMUnit/TFDQuery/BlockBtnQr.md
[q9]:   DMUnit/TFDQuery/BlockQ.md
[q10]:  DMUnit/TFDQuery/CategUpQr.md
[q11]:  DMUnit/TFDQuery/CertificLogInsQr.md
[q12]:  DMUnit/TFDQuery/CkRegionQr.md
[q13]:  DMUnit/TFDQuery/CntrlExrcQr.md
[q14]:  DMUnit/TFDQuery/ContrySelQr.md
[q15]:  DMUnit/TFDQuery/CountryQr.md
[q16]:  DMUnit/TFDQuery/DocumFDQ.md
[q17]:  DMUnit/TFDQuery/DocumInListQ.md
[q18]:  DMUnit/TFDQuery/FIOSearchQr.md
[q19]:  DMUnit/TFDQuery/GrazdanToDekanatQr.md
[q20]:  DMUnit/TFDQuery/IdAbQueueQr.md
[q21]:  DMUnit/TFDQuery/InfCntQr.md
[q22]:  DMUnit/TFDQuery/InfQr.md
[q23]:  DMUnit/TFDQuery/KodSpecializQr.md
[q24]:  DMUnit/TFDQuery/LangSelQr.md
[q25]:  DMUnit/TFDQuery/ListDocFDQ.md
[q26]:  DMUnit/TFDQuery/LogIDSelQr.md
[q27]:  DMUnit/TFDQuery/LogLastQr.md
[q28]:  DMUnit/TFDQuery/MaxExrcQr.md
[q29]:  DMUnit/TFDQuery/OtherPrivQr.md
[q30]:  DMUnit/TFDQuery/OutCntQr.md
[q31]:  DMUnit/TFDQuery/OutDetQr.md
[q32]:  DMUnit/TFDQuery/OutQr.md
[q33]:  DMUnit/TFDQuery/OutTestQr.md
[q34]:  DMUnit/TFDQuery/PasportFDQ.md
[q35]:  DMUnit/TFDQuery/PrintDocQr.md
[q36]:  DMUnit/TFDQuery/PrivCnttQr.md
[q37]:  DMUnit/TFDQuery/PrivilegLogSelQr.md
[q38]:  DMUnit/TFDQuery/PrivQr.md
[q39]:  DMUnit/TFDQuery/QAb_P.md
[q40]:  DMUnit/TFDQuery/QAb_Pr_Enter.md
[q41]:  DMUnit/TFDQuery/QAbFIOPol.md
[q42]:  DMUnit/TFDQuery/QAbitur_Priv_Enter.md
[q43]:  DMUnit/TFDQuery/QAbitura.md
[q44]:  DMUnit/TFDQuery/QAdd_N_Group.md
[q45]:  DMUnit/TFDQuery/QAdress.md
[q46]:  DMUnit/TFDQuery/QCenter.md
[q47]:  DMUnit/TFDQuery/QCK_Kol_Plan.md
[q48]:  DMUnit/TFDQuery/QCk.md
[q49]:  DMUnit/TFDQuery/QCkToDekanat.md
[q50]:  DMUnit/TFDQuery/QControl_Exerc.md
[q51]:  DMUnit/TFDQuery/QDelite.md
[q52]:  DMUnit/TFDQuery/QDistrict.md
[q53]:  DMUnit/TFDQuery/QEducation.md
[q54]:  DMUnit/TFDQuery/QExam.md
[q55]:  DMUnit/TFDQuery/QExamSpec.md
[q56]:  DMUnit/TFDQuery/QExerc_Grp.md
[q57]:  DMUnit/TFDQuery/QFindAbiturExerc.md
[q58]:  DMUnit/TFDQuery/QFotoQeue.md
[q59]:  DMUnit/TFDQuery/QFotoSign.md
[q60]:  DMUnit/TFDQuery/QGIAC2kSpec.md
[q61]:  DMUnit/TFDQuery/QGIAC3Sert.md
[q62]:  DMUnit/TFDQuery/QGIACAll.md
[q63]:  DMUnit/TFDQuery/QGIACAllPrivileg.md
[q64]:  DMUnit/TFDQuery/QGIACAllPrivileg1.md
[q65]:  DMUnit/TFDQuery/QGIACAllSpec.md
[q66]:  DMUnit/TFDQuery/QGIACCKSpec.md
[q67]:  DMUnit/TFDQuery/QGIACEdLic.md
[q68]:  DMUnit/TFDQuery/QGIACEdOSred.md
[q69]:  DMUnit/TFDQuery/QGIACEdOSredCity.md
[q70]:  DMUnit/TFDQuery/QGIACEdOSredVil.md
[q71]:  DMUnit/TFDQuery/QGIACForeigner.md
[q72]:  DMUnit/TFDQuery/QGIACInAll.md
[q73]:  DMUnit/TFDQuery/QGIACInCel.md
[q74]:  DMUnit/TFDQuery/QGIACKursi.md
[q75]:  DMUnit/TFDQuery/QGIACMedal.md
[q76]:  DMUnit/TFDQuery/QGIACMil.md
[q77]:  DMUnit/TFDQuery/QGIACOlimp.md
[q78]:  DMUnit/TFDQuery/QGIACPtu.md
[q79]:  DMUnit/TFDQuery/QGIACSirot.md
[q80]:  DMUnit/TFDQuery/QGIACYearSred.md
[q81]:  DMUnit/TFDQuery/QGIACYearSredCity.md
[q82]:  DMUnit/TFDQuery/QGIACYearSredSpec.md
[q83]:  DMUnit/TFDQuery/QGIACYearSredVil.md
[q84]:  DMUnit/TFDQuery/QGroup_Count_Spec.md
[q85]:  DMUnit/TFDQuery/QGroup_Count.md
[q86]:  DMUnit/TFDQuery/QInc_Gr_Old.md
[q87]:  DMUnit/TFDQuery/QIP.md
[q88]:  DMUnit/TFDQuery/QKod_Fac.md
[q89]:  DMUnit/TFDQuery/QKod_Spec.md
[q90]:  DMUnit/TFDQuery/QLangvich.md
[q91]:  DMUnit/TFDQuery/QLangvichToDekanat.m
[q92]:  DMUnit/TFDQuery/QLetterSource.md
[q93]:  DMUnit/TFDQuery/QLetterSourceKol.md
[q94]:  DMUnit/TFDQuery/QListDocToDekanat.md
[q95]:  DMUnit/TFDQuery/QLittle_Spisoc_GR.md
[q96]:  DMUnit/TFDQuery/QLocality.md
[q97]:  DMUnit/TFDQuery/QMax_Nom_Dela.md
[q98]:  DMUnit/TFDQuery/QMax_Nomer_Ab.md
[q99]:  DMUnit/TFDQuery/QN_group.md
[q100]: DMUnit/TFDQuery/QNoticeFac.md
[q101]: DMUnit/TFDQuery/QNoticeFIO.md
[q102]: DMUnit/TFDQuery/QNoticeSpec.md
[q103]: DMUnit/TFDQuery/QPersonalDocum.md
[q104]: DMUnit/TFDQuery/QPlan_Priem_All_Spe
[q105]: DMUnit/TFDQuery/QPlan_Priem_All.md
[q106]: DMUnit/TFDQuery/QPlan_Priem_CK_Spec
[q107]: DMUnit/TFDQuery/QPlan_Priem_CK.md
[q108]: DMUnit/TFDQuery/QPlan_Priem_Konk_Al
[q109]: DMUnit/TFDQuery/QPlan_Priem_Konk_Sp
[q110]: DMUnit/TFDQuery/QPlan_Priem_Konk.md
[q111]: DMUnit/TFDQuery/QPlan_Priem_Price.m
[q112]: DMUnit/TFDQuery/QPlanPriem2Price.md
[q113]: DMUnit/TFDQuery/QPlanPriemPrice.md
[q114]: DMUnit/TFDQuery/QPrivToDekanat.md
[q115]: DMUnit/TFDQuery/QProverka_RYOR.md
[q116]: DMUnit/TFDQuery/QProverka_sert.md
[q117]: DMUnit/TFDQuery/QRegion_Center.md
[q118]: DMUnit/TFDQuery/QRep_Abitura.md
[q119]: DMUnit/TFDQuery/QRep_Sel_Exerc.md
[q120]: DMUnit/TFDQuery/QReport_Rasp.md
[q121]: DMUnit/TFDQuery/QResult_Exam.md
[q122]: DMUnit/TFDQuery/QSelect_ab.md
[q123]: DMUnit/TFDQuery/QSertificat_ex_list
[q124]: DMUnit/TFDQuery/QSertificat_Res.md
[q125]: DMUnit/TFDQuery/QSertificat.md
[q126]: DMUnit/TFDQuery/QSertificatToDekana
[q127]: DMUnit/TFDQuery/QShkala.md
[q128]: DMUnit/TFDQuery/QShow_Result_Exam.m
[q129]: DMUnit/TFDQuery/QSpecializ.md
[q130]: DMUnit/TFDQuery/QSpecializPlan_Prie
[q131]: DMUnit/TFDQuery/QSpisoc_Group_Pol.m
[q132]: DMUnit/TFDQuery/QSpisoc_Group.md
[q133]: DMUnit/TFDQuery/QSpisok_Spec.md
[q134]: DMUnit/TFDQuery/QStatistic_Every_Da
[q135]: DMUnit/TFDQuery/QStatistic_Every_Da
[q136]: DMUnit/TFDQuery/QStatistic_Every_Da
[q137]: DMUnit/TFDQuery/QStatistic_Every_Da
[q138]: DMUnit/TFDQuery/QStatisticEveryDay.
[q139]: DMUnit/TFDQuery/QStreet.md
[q140]: DMUnit/TFDQuery/QSum_Ball_Nomer.md
[q141]: DMUnit/TFDQuery/QSum_Ball.md
[q142]: DMUnit/TFDQuery/QToDekanat.md
[q143]: DMUnit/TFDQuery/QType_locality.md
[q144]: DMUnit/TFDQuery/QType_street.md
[q145]: DMUnit/TFDQuery/QUndo_Abit.md
[q146]: DMUnit/TFDQuery/RegionNameQr.md
[q147]: DMUnit/TFDQuery/RegionQr.md
[q148]: DMUnit/TFDQuery/RegionUpCKQr.md
[q149]: DMUnit/TFDQuery/SelectLogAbiturQr.m
[q150]: DMUnit/TFDQuery/SelPrivLogQr.md
[q151]: DMUnit/TFDQuery/SerteficatSelQr.md
[q152]: DMUnit/TFDQuery/SertSelLogQr.md
[q153]: DMUnit/TFDQuery/SpecFacQr.md
[q154]: DMUnit/TFDQuery/SpecializNameQr.md
[q155]: DMUnit/TFDQuery/SpecializQr.md
[q156]: DMUnit/TFDQuery/SpecQr.md
[q157]: DMUnit/TFDQuery/SPFDQ.md
[q158]: DMUnit/TFDQuery/SPFDQ1.md
[q159]: DMUnit/TFDQuery/SportQuery.md
[q160]: DMUnit/TFDQuery/SspecQ.md
[q161]: DMUnit/TFDQuery/Stat3hAll1Qr.md
[q162]: DMUnit/TFDQuery/Stat3hAll2Qr.md
[q163]: DMUnit/TFDQuery/StatusQueueQr.md
[q164]: DMUnit/TFDQuery/UpDateOutQr.md
[q165]: DMUnit/TFDQuery/VO2KSpecializQr.md
[q166]: DMUnit/TFDQuery/WithoutCntQr.md
[q167]: DMUnit/TFDQuery/WithoutDetQr.md
[q168]: DMUnit/TFDQuery/WithoutQr.md
[q169]: DMUnit/TFDQuery/WithOutTestLogQr.md

---
<br>

|                *Component name* |      *Type*      | *CN* | *Procedure name*         |
|--------------------------------:|:----------------:|:----:|:-------------------------|
<!-- |       [AbiturLogInsStrdPrc][p1] | TFDStoredProc \* |      | abitur_logbook_ins       | -->
<!-- |     [CertificLogDelStrdPrc][p2] | TFDStoredProc \* |      | certificates_logbook_del | -->
<!-- |         [MaxNumDelaStrdPrc][p3] | TFDStoredProc \* |      | max_num_dela             | -->
<!-- |            [PrivDelStrdPrc][p4] | TFDStoredProc \* |      | abitur_privileg_del      | -->
<!-- |     [PrivilegLogDelStrdPrc][p5] | TFDStoredProc \* |      | privileg_log_del         | -->
<!-- |     [PrivilegLogInsStrdPrc][p6] | TFDStoredProc \* |      | privileg_log_ins         | -->
<!-- |            [PrivInsStrdPrc][p7] | TFDStoredProc \* |      | abitur_privileg_ins      | -->
<!-- |      [RaspredBall12StrdPrc][p8] | TFDStoredProc \* |      | kol_summ_ball12          | -->
<!-- |      [RaspredBall34StrdPrc][p9] | TFDStoredProc \* |      | kol_summ_ball4           | -->
<!-- |       [RaspredBallStrdPrc][p10] | TFDStoredProc \* |      | kol_summ_ball3           | -->
<!-- |[StoredProcBall_Sertifikat][p11] | TFDStoredProc \* |      | ball_sertifikat          | -->
<!-- |      [StoredProcKolk_Konk][p12] | TFDStoredProc \* |      | kol_konk                 | -->
<!-- |     [StoredProcKolk_Konk1][p13] | TFDStoredProc \* |      | kol_konk1                | -->
<!-- |           [StoredProcN_AB][p14] | TFDStoredProc \* |      | get_nomer_ab             | -->
|       [StoredProcN_People][p15] | TFDStoredProc \* | dean | GET_N_PEOPLE             |
<!-- |    [StoredProcSelExercIns][p16] | TFDStoredProc \* |      | proc_sel_exerc_ins       | -->
<!-- | [StoredProcStatistic_Konk][p17] | TFDStoredProc \* |      | kol_priv                 | -->
<!-- |   [StoredProcSumm_Ball_2K][p18] | TFDStoredProc \* |      | koll_summ_ball2k         | -->
<!-- |      [StoredProcSumm_Ball][p19] | TFDStoredProc \* |      | kol_summ_ball2           | -->
<!-- |   [StoredProcSumm_Ball100][p20] | TFDStoredProc \* |      | kol_summ_ball_100        | -->

[p1]:  DMUnit/TFDStoredProc/AbiturLogInsStrdPrc.md
[p2]:  DMUnit/TFDStoredProc/CertificLogDelStrdPrc.md
[p3]:  DMUnit/TFDStoredProc/MaxNumDelaStrdPrc.md
[p4]:  DMUnit/TFDStoredProc/PrivDelStrdPrc.md
[p5]:  DMUnit/TFDStoredProc/PrivilegLogDelStrdPrc.md
[p6]:  DMUnit/TFDStoredProc/PrivilegLogInsStrdPrc.md
[p7]:  DMUnit/TFDStoredProc/PrivInsStrdPrc.md
[p8]:  DMUnit/TFDStoredProc/RaspredBall12StrdPrc.md
[p9]:  DMUnit/TFDStoredProc/RaspredBall34StrdPrc.md
[p10]: DMUnit/TFDStoredProc/RaspredBallStrdPrc.md
[p11]: DMUnit/TFDStoredProc/StoredProcBall_Sertifikat.md
[p12]: DMUnit/TFDStoredProc/StoredProcKolk_Konk.md
[p13]: DMUnit/TFDStoredProc/StoredProcKolk_Konk1.md
[p14]: DMUnit/TFDStoredProc/StoredProcN_AB.md
[p15]: DMUnit/TFDStoredProc/StoredProcN_People.md
[p16]: DMUnit/TFDStoredProc/StoredProcSelExercIns.md
[p17]: DMUnit/TFDStoredProc/StoredProcStatistic_Konk.md
[p18]: DMUnit/TFDStoredProc/StoredProcSumm_Ball_2K.md
[p19]: DMUnit/TFDStoredProc/StoredProcSumm_Ball.md
[p20]: DMUnit/TFDStoredProc/StoredProcSumm_Ball100.md

---
</br>

|                *Component name* |    *Type*   | *CN* | *DS* | *Description*    |
|--------------------------------:|:-----------:|:----:|:----:|:-----------------|
|               [CntrExrcTbl][t1] | TFDTable \* |      |  DS  |                  |
|      [Increment_GroupTable][t2] | TFDTable \* | dean |  DS  |                  |
|               [RegCentrTbl][t3] | TFDTable \* | dean |      |                  |
|[Selection_CommitteeFDTable][t4] | TFDTable \* |      |  DS  |                  |
|                     [TBall][t5] | TFDTable \* |      |  DS  |                  |
|                 [TCategory][t6] | TFDTable \* |      |  DS  |                  |
|                       [TCk][t7] | TFDTable \* |      |  DS  |                  |
|                    [TDocum][t8] | TFDTable \* |      |  DS  |                  |
|                   [TEduDoc][t9] | TFDTable \* |      |  DS  |                  |
|                 [TFaculty][t10] | TFDTable \* | dean |  DS  |                  |
|              [TFoundation][t11] | TFDTable \* | dean |  DS  |                  |
|               [TKol_Place][t12] | TFDTable \* |      |  DS  |                  |
|               [TPass_User][t13] | TFDTable \* | dean |  DS  |                  |
|                 [TPredmet][t14] | TFDTable \* |      |  DS  |                  |
|                  [TRegion][t15] | TFDTable \* |      |  DS  |                  |
|               [TVid_Sport][t16] | TFDTable \* | dean |  DS  |                  |

[t1]:  DMUnit/TFDTable/CntrExrcTbl.md
[t2]:  DMUnit/TFDTable/Increment_GroupTable.md
[t3]:  DMUnit/TFDTable/RegCentrTbl.md
[t4]:  DMUnit/TFDTable/Selection_CommitteeFDTable.md
[t5]:  DMUnit/TFDTable/TBall.md
[t6]:  DMUnit/TFDTable/TCategory.md
[t7]:  DMUnit/TFDTable/TCk.md
[t8]:  DMUnit/TFDTable/TDocum.md
[t9]:  DMUnit/TFDTable/TEduDoc.md
[t10]: DMUnit/TFDTable/TFaculty.md
[t11]: DMUnit/TFDTable/TFoundation.md
[t12]: DMUnit/TFDTable/TKol_Place.md
[t13]: DMUnit/TFDTable/TPass_User.md
[t14]: DMUnit/TFDTable/TPredmet.md
[t15]: DMUnit/TFDTable/TRegion.md
[t16]: DMUnit/TFDTable/TVid_Sport.md

--
</br>

|             *Component name* |      *Type*     | *CN* | *DS* | *Up* | *Description*    |
|-----------------------------:|:---------------:|:----:|:----:|:----:|:-----------------|
|            [BloskUpSQL][up1] | TFDUpdateSQL \* |      |  DS  |  Up  |                  |
|           [ListDocFDUp][up2] | TFDUpdateSQL \* |      |  DS  |  Up  |                  |
|             [PasportUp][up3] | TFDUpdateSQL \* | Dean |      |      |                  |
|      [QSelectUpdateSQL][up4] | TFDUpdateSQL \* |      |  DS  |      |                  |
|        [SportUpdateSQL][up5] | TFDUpdateSQL \* | Dean |      |      |                  |
|                [UpAb_P][up6] | TFDUpdateSQL \* |      |  DS  |  Up  |                  |
|   [UpAbitur_Priv_Enter][up7] | TFDUpdateSQL \* |      |  DS  |  Up  |                  |
|             [UpAbitura][up8] | TFDUpdateSQL \* |      |  DS  |  Up  |                  |
|         [UpAdd_N_Group][up9] | TFDUpdateSQL \* |      |      |      |                  |
|             [UpCenter][up10] | TFDUpdateSQL \* | Dean |  DS  |  Up  |                  |
|        [UpCkToDekanat][up11] | TFDUpdateSQL \* | Dean |  DS  |  Up  |                  |
|               [UPFoto][up12] | TFDUpdateSQL \* |      |      |  Up  |                  |
|         [UpInc_Gr_Old][up13] | TFDUpdateSQL \* | Dean |  DS  |  Up  |                  |
|  [UpLangvichToDekanat][up14] | TFDUpdateSQL \* | Dean |  DS  |  Up  |                  |
|   [UpListDocToDekanat][up15] | TFDUpdateSQL \* | Dean |      |  Up  |                  |
|      [UpPrivToDekanat][up16] | TFDUpdateSQL \* | Dean |  DS  |  Up  |                  |
|        [UpResult_Exam][up17] | TFDUpdateSQL \* |      |  DS  |  Up  |                  |
|[UpSertificatToDekanat][up18] | TFDUpdateSQL \* | Dean |      |  Up  |                  |
|   [UpShow_Result_Exam][up19] | TFDUpdateSQL \* |      |  DS  |  Up  |                  |
|          [UpSpecializ][up20] | TFDUpdateSQL \* |      |  DS  |  Up  |                  |
|     [UpSum_Ball_Nomer][up21] | TFDUpdateSQL \* |      |  DS  |  Up  |                  |
|           [UpSum_Ball][up22] | TFDUpdateSQL \* |      |  DS  |  Up  |                  |
|          [UpToDekanat][up23] | TFDUpdateSQL \* | Dean |  DS  |  Up  |                  |
|          [UpUndo_Abit][up24] | TFDUpdateSQL \* |      |      |      |                  |

[up1]:  DMUnit/TFDUpdateSQL/BloskUpSQL.md
[up2]:  DMUnit/TFDUpdateSQL/ListDocFDUp.md
[up3]:  DMUnit/TFDUpdateSQL/PasportUp.md
[up4]:  DMUnit/TFDUpdateSQL/QSelectUpdateSQL.md
[up5]:  DMUnit/TFDUpdateSQL/SportUpdateSQL.md
[up6]:  DMUnit/TFDUpdateSQL/UpAb_P.md
[up7]:  DMUnit/TFDUpdateSQL/UpAbitur_Priv_Enter.md
[up8]:  DMUnit/TFDUpdateSQL/UpAbitura.md
[up9]:  DMUnit/TFDUpdateSQL/UpAdd_N_Group.md
[up10]: DMUnit/TFDUpdateSQL/UpCenter.md
[up11]: DMUnit/TFDUpdateSQL/UpCkToDekanat.md
[up12]: DMUnit/TFDUpdateSQL/UPFoto.md
[up13]: DMUnit/TFDUpdateSQL/UpInc_Gr_Old.md
[up14]: DMUnit/TFDUpdateSQL/UpLangvichToDekanat.md
[up15]: DMUnit/TFDUpdateSQL/UpListDocToDekanat.md
[up16]: DMUnit/TFDUpdateSQL/UpPrivToDekanat.md
[up17]: DMUnit/TFDUpdateSQL/UpResult_Exam.md
[up18]: DMUnit/TFDUpdateSQL/UpSertificatToDekanat.md
[up19]: DMUnit/TFDUpdateSQL/UpShow_Result_Exam.md
[up20]: DMUnit/TFDUpdateSQL/UpSpecializ.md
[up21]: DMUnit/TFDUpdateSQL/UpSum_Ball_Nomer.md
[up22]: DMUnit/TFDUpdateSQL/UpSum_Ball.md
[up23]: DMUnit/TFDUpdateSQL/UpToDekanat.md
[up24]: DMUnit/TFDUpdateSQL/UpUndo_Abit.md

---
</br>

BloskUpSQL

```sql
/* : TFDUpdateSQL -> INSERT */
INSERT INTO
    block_edit
    (
        block,
        n_fac,
        perepodacha,
        note,
        note_perepodacha
    )
VALUES
    (
        :block,
        :n_fac,
        :perepodacha,
        :note,
        :note_perepodacha
    )

/* : TFDUpdateSQL -> UPDATE (Modify) */
UPDATE
    block_edit
SET
    block            = :block,
    n_fac            = :n_fac,
    perepodacha      = :perepodacha,
    note             = :note,
    note_perepodacha = :note_perepodacha
WHERE
    id_block = :old_id_block

/* : TFDUpdateSQL -> DELETE */
DELETE FROM
    block_edit
WHERE
    id_block = :old_id_block
```

QSelectUpdateSQL

```sql
/* : TFDUpdateSQL -> UPDATE (Modify) */
UPDATE
    abitura
SET
    status           = :status,
    d_prikaz_include = :d_prikaz_include,
    n_prikaz_include = :n_prikaz_include,
    n_found          = :n_found
WHERE
    nomer_ab         = :old_nomer_ab
```

WithOutTestLogQr

```sql
SELECT
    prvlg.short_name,
    p_det.short_name
FROM
    privilege        AS prvlg,
    priveleg_details AS p_det,
    priveleg_array   AS p_arr
WHERE
        prvlg.n_without_tests = :sel_priv
    AND
        p_det.id_det          = p_arr.id_det
    AND
        p_arr.n_item          = :dat_priv
    AND
        p_arr.id_priv         = prvlg.id_priv
```

WithoutQr

```sql
SELECT
    p.id_priv,
    p.name_priv,
    p.n_without_tests
FROM
    privilege AS p
WHERE
    p.n_without_tests > 0
ORDER BY
    p.n_without_tests
```

WithoutCntQr

```sql
SELECT
    COUNT
    (
        p.id_priv
    )
FROM
    privilege AS p
WHERE
    p.n_without_tests > 0
```

VO2KSpecializQr

```sql
SELECT
    a.nomer_ab
FROM
    abitura AS a
WHERE
        a.status       = 0
    AND
        a.n_specializ  = :sp
    AND
        a.vid_edu      = :v_e
    AND
        (
            a.term_edu = 4
         OR
            a.term_edu = 5
        )
    AND
        a.n_fac        = :n_fac
    AND
        a.price        = :price
```

UpDateOutQr

```sql
UPDATE
    abitur_logbook AS a
SET
    a.date_out = :date_out
WHERE
    a.id_log   = :id_log
```

WithoutDetQr

```sql
SELECT
    p_arr.n_item,
    p_arr.id_det,
    p_det.name_detais
FROM
    priveleg_array   AS p_arr,
    priveleg_details AS p_det
WHERE
        p_arr.id_priv = :id_priv
    AND
        p_det.id_det  = p_arr.id_det
```

StatusQueueQr

```sql
UPDATE
    abitur_queue AS a
SET
    a.fam          = :fam,
    a.name         = :name,
    a.otch         = :otch,
    a.status_queue = :status_queue,
    a.n_specializ  = :specializ,
    a.n_spec       = :n_spec,
    a.vid_edu      = :vid_edu,
    a.category_ab  = :category_ab,
    a.category_if  = :category_if,
    a.category_edu = :category_edu,
    a.term_edu     = :term_edu,
    a.price        = :price,
    a.konkurs      = :konkurs
WHERE
    a.id_ab        = :id_ab
```

Stat3hAll2Qr

```sql
SELECT
    a.konkurs,
    count
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.status      = 0
    AND
        a.n_fac       = :n_fac
    AND
        a.vid_edu     = :vid_edu
    AND
        a.term_edu    = 1
    AND
        a.price       = :price
    AND
        a.category_if = 0
GROUP BY
    a.konkurs
```

Stat3hAll1Qr

```sql
SELECT
    a.konkurs,
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.status  = 0
    AND
        a.n_fac   = :n_fac
    AND
        a.vid_edu = :vid_edu
    AND
            (
                 a.term_edu = 0
              OR
                 a.term_edu = 2
            )
        AND
            a.price       = :price
        AND
            a.n_specializ = :n_specializ
        AND
            (
                 a.category_if = 0
              OR
                 (
                       a.category_if = 1
                   AND
                       a.price       = 0
                 )
            )
GROUP BY
    a.konkurs
```

SspecQ

```sql
SELECT
    a.nomer_ab
FROM
    abitura AS a
WHERE
        a.status      = 0
    AND
        a.n_specializ = :sp
    AND
        a.vid_edu     = :v_e
    AND
        a.term_edu    = 1
    AND
        a.n_fac       = :n_fac
    AND
        a.price       = :price
```

SPFDQ1

```sql
INSERT INTO
    faculty 
    (
        n_fac,
        fac,
        fac1,
        kod_fac,
        dean,
        fac_rp
    )
VALUES
    (
        :n_fac,
        :fac,
        :fac1,
        :kod_fac,
        :dean,
        :fac_rp
    )
```

SpecQr

```sql
SELECT
    s.special
FROM
    specializ AS s
WHERE
    s.n_specializ = :n_specializ
```

SpecializNameQr

```sql
SELECT
    s.special,
    s.special_direction
FROM
    specializ AS s
WHERE
    s.n_specializ = :n_specializ
```

SpecFacQr

```sql
SELECT
    s.special,
    s.n_specializ
FROM
    specializ AS s
WHERE
    s.n_fac = :n_fac
ORDER BY
    s.special
```

SertSelLogQr

```sql
SELECT
    p.text_predmet,
    s.seria_s,
    s.nomer_s,
    s.rus_bel,
    s.balls
FROM
    sertificat AS s,
    predmet    AS p
WHERE
        p.n_predmet = s.n_predmet
    AND
        s.nomer_ab = :nomer_ab
ORDER BY
    s.rus_bel
```

SerteficatSelQr

```sql
SELECT
    s.n_predmet,
    s.seria_s,
    s.nomer_s,
    s.balls,
    s.describe,
    s.rus_bel
FROM
    sertificat AS s
WHERE
    s.nomer_ab = :nomer_ab
```

SelPrivLogQr

```sql
SELECT
    p_log.n_priv,
    p_log.sel_priv,
    p_log.dat_priv
FROM
    privileg_log AS p_log
WHERE
    p_log.id_log = :id_log
```

SelectLogAbiturQr

```sql
SELECT
    a_log.nom_dela,
    ab.nomer_ab,
    ab.fam,
    ab.name,
    ab.otch,
    ab.citizenship,
    a_log.n_specializ,
    a_log.date_in,
    a_log.nom_dela,
    a_log.id_log,
    a_log.address_before,
    a_log.n_ck,
    ab.d_prikaz_include,
    ab.n_prikaz_include,
    a_log.date_out,
    a_log.konkurs,
    a_log.term_edu,
    a_log.category
FROM
    abitur_logbook AS a_log,
    abitura        AS ab
WHERE
        a_log.nomer_ab = ab.nomer_ab
    AND
        a_log.n_fac = :n_fac
    AND
        a_log.date_in >= :date_in1
    AND
        a_log.date_in < :date_in2
    AND
        a_log.vid_edu = :vid_edu 
    AND
        (
             (
                  (
                       a_log.term_edu = 0
                    OR
                       a_log.term_edu = 3
                  )
              AND
                  :term_edu = 0
             )
         OR
             (
                  (
                       a_log.term_edu = 1
                    OR
                       a_log.term_edu = 2
                    OR
                       a_log.term_edu = 4
                    OR
                       a_log.term_edu = 5
                  )
              AND
                  :term_edu = 1
             )
        )
    AND
        a_log.price = :price
ORDER BY
    a_log.nom_dela
```

RegionUpCKQr

```sql
UPDATE
    abitur_logbook
SET
    n_ck   = :n_ck
WHERE
    id_log = :id_log
```

RegionQr

```sql
SELECT
    centre
FROM
    regional_centre
WHERE
    n_centre = :n_centre
```

RegionNameQr

```sql
SELECT
    centre
FROM
    regional_centre
WHERE
    n_centre = :n_centre
```

QStatisticEveryDay

```sql
SELECT
    n_specializ,
    SUM
    (
        kol_place
    )
FROM
    kol_place
WHERE
        n_fac   =  :n_fac
    AND
        vid_edu =  :vid_edu
    AND
        text    != 1
GROUP BY
    n_specializ
```

QStatistic_Every_Day_Special

```sql
SELECT
    konkurs,
    n_spec,
    COUNT
    (
        nomer_ab
    ),
    vid_edu,
    price
FROM
    abitura
WHERE
        status  = 0 
    AND
        vid_edu = :vid_edu
    AND
        n_spec  = :n_spec
GROUP BY
    vid_edu,
    n_spec,
    konkurs,
    price
```

QStatistic_Every_Day_Ball_Price

```sql
SELECT
    konkurs,
    COUNT
    (
        nomer_ab
    )
FROM
    abitura
WHERE
        status      = 0
    AND
        n_fac       = :n_fac 
    AND
        vid_edu     = :vid_edu
    AND
        price       = :price
    AND
        n_specializ = :n_sp
GROUP BY
    konkurs,
    price
```

QStatistic_Every_Day_Ball

```sql
SELECT
    konkurs,
    price,
    COUNT
    (
        nomer_ab
    )
FROM
    abitura
WHERE
        status      = 0
    AND
        n_fac       = :n_fac 
    AND
        vid_edu     = :vid_edu
    AND
        n_specializ = :n_sp
GROUP BY
    konkurs,
    price
```

QSpisok_Spec

```sql
SELECT
    fam,
    name,
    otch,
    fam || ' '|| name || ' ' || otch AS fio,
    n_specializ,
    nom_group,
    n_privilege_exam,
    n_ck,
    nomer_ab,
    gragdan,
    vid_edu,
    konkurs,
    n_sport_category,
    v_k,
    priv,
    without,
    n_fac,
    middle_ball,
    price
FROM
    abitura
WHERE
        n_fac  = :n_fac
    AND
        status = 0
ORDER BY
    vid_edu,
    n_specializ,
    fam,
    name,
    otch
```

QSertificat_ex_list

```sql
SELECT
    p.text_predmet,
    a.date_priem,
    e.ball,
    s.rus_bel
FROM
    examen AS e
        INNER JOIN
            abitura    AS a
                ON
                    e.nomer_ab  = a.nomer_ab
        inner JOIN
            sertificat AS s
                ON
                    a.nomer_ab  = s.nomer_ab
        INNER JOIN
            predmet    AS p
                ON
                    e.n_predmet = p.n_predmet
WHERE 
        a.nomer_ab    = :nomer
    AND 
        e.status_ball = 1
    AND
        e.nomer_ab    = s.nomer_ab
    AND
        e.n_predmet   = s.n_predmet
```

QRep_Sel_Exerc

```sql
SELECT
    s_exr.num_exerc_grp,
    exerc.name_exerc
FROM
    sel_exercize AS s_exr,
    exercise     AS exerc
WHERE
        s_exr.id_exerc = exerc.id_exerc
    AND
        s_exr.nomer_ab = :nomer_ab
ORDER BY
    s_exr.num_exerc_grp
```

QRep_Abitura

```sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.nom_group
FROM
    abitura AS a
WHERE
    a.nomer_ab = :nomer_ab
```

QProverka_sert

```sql
SELECT
    a.nomer_ab
FROM
    abitura AS a
WHERE
    (
         a.without IS NULL
      OR
         a.without =  ''
    )
    AND
        a.konkurs  <> 4
    AND
        rus_bel    IS NULL
    AND
        NOT a.nomer_ab =
            SOME
            (
                SELECT
                    s.nomer_ab
                FROM
                    sertificat AS s
                WHERE
                    s.n_predmet = 4
            ) 
    AND
        a.nomer_ab =  :nomer
```

QProverka_RYOR

```sql
SELECT
    a.fam,
    a.n_fac,
    a.vid_edu,
    a.name_edu_middle,
    a.priv
FROM
    abitura AS a
WHERE
    (
         a.name_edu_middle LIKE 'УОР'
      OR
         a.name_edu_spec   LIKE 'УОР'
    )
    AND
        a.priv NOT LIKE '13.'
AND
    a.nomer_ab = :NOMER
```

QPlanPriemPrice

```sql
SELECT
    k.n_specializ,
    k.kol_place
FROM
    kol_place AS k
WHERE
        k.n_fac       = :n_fac
    AND
        k.vid_edu     = :vid_edu
    AND
        k.n_specializ = :spec
    AND
        k.text        = 0
    AND
        k.price       = :price
```

QPlanPriem2Price

```sql
SELECT
    n_specializ,
    kol_place
FROM
    kol_place
WHERE
        n_fac       = :n_fac
    AND
        vid_edu     = :vid_edu
    AND
        n_specializ = :spec
    AND
        text        = 1
    AND
        price       = :price
```

QPlan_Priem_Price

```sql
SELECT
    k_plc.n_specializ,
    SUM
    (
        k_plc.kol_place
    ),
    k_plc.vid_edu,
    k_plc.text,
    k_plc.price,
    o_spc.order_sp
FROM
    kol_place AS k_plc
        LEFT JOIN
            order_specializ AS o_spc
                ON
                    k_plc.n_specializ = o_spc.n_specializ
WHERE
        k_plc.n_specializ <> 2
    AND
        k_plc.n_specializ <> 5  
    AND
        k_plc.n_fac       =  :n_fac
    AND
        k_plc.vid_edu     =  :vid_edu
    AND
        k_plc.text        =  :text
    AND
        k_plc.price       =  :price
GROUP BY
    k_plc.vid_edu,
    k_plc.text,
    k_plc.price,
    o_spc.order_sp,
    k_plc.n_specializ
```

QPlan_Priem_Konk_Special

```sql
SELECT
    specz.n_spec,
    text,
    SUM
    (
        k_plc.kol_place
    ) AS sum1
FROM 
    kol_place AS k_plc
        INNER JOIN
            specializ AS specz
                ON
                    k_plc.n_specializ = specz.n_specializ  
WHERE
        k_plc.vid_edu = :vid_edu
    and
        specz.n_spec  = :n_sp
GROUP BY
    specz.n_spec,
    k_plc.text
```

QPlan_Priem_Konk_All_Param

```sql
SELECT
    n_specializ,
    kol_place
FROM
    kol_place
WHERE
        n_fac   = :n_fac
    AND
        vid_edu = :vid_edu
    AND
        text    = :text
    AND
        price   = :price
```

QPlan_Priem_Konk

```sql
SELECT
    k.n_specializ,
    k.text,
    k.kol_place
FROM
    kol_place AS k
WHERE
        k.n_specializ <> 2
    AND
        k.n_specializ <> 5
    AND
        k.n_fac       =  :n_fac
    AND
        k.vid_edu     =  :vid_edu
    and
        k.n_specializ =  :n_sp
GROUP BY
    k.n_specializ,
    k.text,
    k.kol_place
```

QPlan_Priem_CK_Special

```sql
SELECT
    specz.n_spec,
    SUM
    (
        k_plc.kol_place
    ) AS sum1,
    k_plc.vid_edu
FROM
    kol_place AS k_plc
        INNER JOIN
            specializ AS specz
                ON
                    k_plc.n_specializ = specz.n_specializ  
WHERE  
        k_plc.text    = 2
    AND
        k_plc.vid_edu = :vid_edu
GROUP BY
    k_plc.vid_edu,
    specz.n_spec
```

QPlan_Priem_CK

```sql
SELECT
    k.n_specializ,
    SUM
    (
        k.kol_place
    ),
    k.vid_edu
FROM
    kol_place AS k
WHERE
        k.n_specializ <> 2  
    AND
        k.n_specializ <> 5  
    AND
        k.text        =  2
    AND
        k.vid_edu     =  :vid_edu 
GROUP BY
    k.vid_edu,
    k.n_specializ
```

QPlan_Priem_All_Special

```sql
SELECT
    specy.n_spec,
    specy.code_spec,
    SUM
    (
        k_plc.kol_place
    ) AS sum1,
    k_plc.vid_edu,
    specy.spec
FROM
    kol_place AS k_plc
        INNER JOIN
            specializ AS specz
                ON
                    k_plc.n_specializ = specz.n_specializ
        INNER JOIN
            speciality AS specy
                ON
                    specz.n_spec = specy.n_spec  
WHERE
    k_plc.vid_edu = :vid_edu
GROUP BY
    k_plc.vid_edu,
    specy.code_spec,
    specy.n_spec,
    specy.spec
```

QPlan_Priem_All

```sql
SELECT
    k.n_specializ,
    SUM
    (
        k.kol_place
    ),
    k.vid_edu,
    o.order_sp
FROM
    kol_place AS k
        LEFT JOIN
            order_specializ AS o
                ON
                    k.n_specializ = o.n_specializ
WHERE
        k.n_specializ <> 2
    AND
        k.n_specializ <> 5  
    AND
        k.n_fac       =  :n_fac
    AND
        k.vid_edu     =  :vid_edu
GROUP BY
    k.vid_edu,
    o.order_sp,
    k.n_specializ
```

QPersonalDocum

```sql
/* FDConnection1 - Decanat */
SELECT
    id_type,
    name_type
FROM
    personal_type
```

```sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.address_before,
    a.n_prikaz_include,
    a.d_prikaz_include,
    a.n_fac,
    a.n_specializ,
    a.term_edu,
    a.vid_edu
FROM
    abitura AS a
WHERE
    a.nomer_ab = :nomer_ab
```

```sql
SELECT
    f.fac
FROM
    faculty AS f
WHERE
    f.n_fac = :n_fac
```

```sql
SELECT
    n_group,
    nom_group,
    vid_edu,
    describe,
    n_fac,
    n_count
FROM
    n_group
WHERE
        n_fac   = :fac
    AND
        vid_edu = :edu
    AND
        describe LIKE :spec
```

```sql
SELECT
    COUNT
    (
        a.nomer_ab,
    )
FROM
    abitura AS a
WHERE
        a.n_fac  = :n_fac
    AND
        a.status = 0
```

```sql
SELECT
    s.special_direction
FROM
    specializ AS s
WHERE
    s.n_specializ = :n_specializ
```

```sql
SELECT
    COUNT
    (
        nomer_ab
    )
FROM
    abitura
WHERE
        vid_edu         =    :vid_edu
    AND
        status          =     0
    AND
        education       =     0
    AND
        when_edu_middle =    :year
    AND
        town_village    LIKE '1'
    AND
        konkurs         <>    5
```

QGIACSirot

```sql
/*  something went wrong here cos abitura.v_k contains <null>s
    AND
        v_k LIKE '1'
*/
```

QGIACPtu

```sql
/*  something went wrong here cos abitura.priv contains <null>s
    AND
        (
             priv LIKE '9.'
          OR 
             priv LIKE '10.'
        )
*/
```

QGIACOlimp

```sql
/*  something went wrong here cos abitura.without contains <null>s
    AND
        (
             without LIKE '2'
          OR 
             without LIKE '3'
        )
*/
```

QGIACMil

```sql
/*  something went wrong here cos abitura.v_k contains <null>s
    AND
        v_k LIKE '5'
*/
```

QGIACMedal

```sql
/*  something went wrong here cos abitura.priv contains <null>s
    AND
        priv LIKE '8.'
*/
```

QGIACKursi

```sql
/*  something went wrong here cos abitura.priv contains <null>s
    AND
        priv LIKE '12.'
*/
```

-- : TFDUpdateSQL -> INSERT
-- : TFDUpdateSQL -> UPDATE (Modify)
-- : TFDUpdateSQL -> DELETE
-- : TFDUpdateSQL -> LOCK
-- : TFDUpdateSQL -> UNLOCK
-- : TFDUpdateSQL -> FETCHROW

QExerc_Grp

```sql
SELECT
    e.id_exerc,
    e.name_exerc
FROM
    exercise AS e
WHERE
    e.id_exerc
        IN
        (
            SELECT
                c.id_exerc
            FROM
                control_exerc AS c
            WHERE
                    c.n_specializ   = :n_specializ
                AND
                    c.pol           = :pol
                AND
                    c.num_exerc_grp = :num_exerc_grp
        )
```

QDelite

```sql
DELETE FROM
    examen
WHERE
    nomer_ab = :nomer
```

QControl_Exerc

```sql
SELECT
    e.name_exerc
FROM
    control_exerc AS c,
    exercise      AS e
WHERE
        c.n_specializ   = :n_specializ
    AND
        c.pol           = :pol
    AND
        c.num_exerc_grp = :num_exerc_grp
    AND
        e.id_exerc      = c.id_exerc
```

QCK_Kol_Plan

```sql
SELECT
    c.kol_place
FROM
    ck_plan AS c
WHERE
    c.n_specializ = :n_specializ
```

QAbitur_Priv_Enter

```sql
SELECT
    a.nomer_ab,
    a.n_priv
FROM
    abitur_privileg AS a
WHERE
    a.nomer_ab = :n_ab
```

QAbFIOPol

```sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.pol
FROM
    abitura AS a
WHERE
    a.nomer_ab = :nomer_ab
```

QAb_Pr_Enter

```sql
SELECT
    a.nomer_ab,
    a.n_priv
FROM
    abitur_privileg AS a
ORDER BY
    a.nomer_ab
```

QAb_P

```sql
SELECT
    a.n_ab_p,
    a.nomer_ab,
    a.vid_edu_do,
    a.vid_edu_po,
    a.nom_dela_do,
    a.nom_dela_po,
    a.nom_group_do,
    a.nom_group_po,
    a.n_specializ_do,
    a.n_specializ_po,
    a.n_spec_do,
    a.n_spec_po,
    a.n_ck,
    a.konkurs_do,
    a.konkurs_po,
    a.date_p,
    a.price_do,
    a.price_po
FROM
    ab_p AS a
```

PrivQr

```sql
SELECT
    a.n_priv,
    a.sel_priv,
    a.dat_priv
FROM
    abitur_privileg AS a
WHERE
        a.nomer_ab = :nomer_ab
    AND
        a.n_priv   = :n_priv
```

PrivilegLogSelQr

```sql
SELECT
    a.n_priv,
    a.sel_priv,
    a.dat_priv
FROM
    abitur_privileg AS a
WHERE
    a.nomer_ab = :nomer_ab
```

PrivCnttQr

```sql
SELECT
    COUNT
    (
        a.sel_priv
    )
FROM
    abitur_privileg AS a
WHERE
        a.nomer_ab = :nomer_ab
    AND
        a.n_priv   = :n_priv
```

PrintDocQr

```sql
SELECT
    a.nomer_ab,
    a.fam,
    a.name,
    a.otch
FROM
    abitura AS a
WHERE
        a.n_fac       = :n_fac
    AND
        a.vid_edu     = :vid_edu
    AND
        a.n_specializ = :n_specializ
    AND
        a.status      = 5
ORDER BY
    a.fam,
    a.name,
    a.otch
```

PasportUp

```sql
-- : TFDUpdateSQL -> INSERT
INSERT INTO
    personal_docum
    (
        nomer,
        id_type,
        series,
        number,
        personal_number,
        date_give,
        date_valid,
        who_give,
        n_region
    )
VALUES
    (
        :nomer,
        :id_type,
        :series,
        :number,
        :personal_number,
        :date_give,
        :date_valid,
        :who_give,
        :n_region
    )  

-- : TFDUpdateSQL -> UPDATE (Modify)
UPDATE
    personal_docum
SET
    nomer           = :nomer,
    id_type         = :id_type,
    series          = :series,
    number          = :number,
    personal_number = :personal_number,
    date_give       = :date_give,
    date_valid      = :date_valid,
    who_give        = :who_give,
    n_region        = :n_region
WHERE
    nomer           = :old_nomer

-- : TFDUpdateSQL -> DELETE
DELETE FROM
    personal_docum
WHERE
    nomer = :old_nomer
```

PasportFDQ

```sql
/* FDConnection1 - Decanat */
SELECT
    p.nomer,
    p.id_type,
    p.series,
    p.number,
    p.personal_number,
    p.date_give,
    p.date_valid,
    p.who_give,
    p.n_region
FROM
    personal_docum AS p
ORDER BY
    p.nomer
```

OutTestQr

```sql
SELECT
    privl.short_name,
    p_det.short_name
FROM
    privilege        AS privl,
    priveleg_details AS p_det,
    priveleg_array   AS p_arr
WHERE
        privl.n_out_tests = :sel_priv
    AND
        p_arr.n_item      = :dat_priv
    AND
        p_det.id_det      = p_arr.id_det
    AND
        p_arr.id_priv     = privl.id_priv
```

OutQr

```sql
SELECT
    p.id_priv,
    p.name_priv,
    p.n_out_tests
FROM
    privilege AS p
WHERE
    p.n_out_tests > 0
ORDER BY
    p.n_out_tests
```

OutDetQr

```sql
SELECT
    p_arr.n_item,
    p_arr.id_det,
    p_det.name_detais
FROM
    priveleg_array   AS p_arr,
    priveleg_details AS p_det
WHERE
        p_arr.id_priv  = :id_priv
    AND
        p_det.id_det   = p_arr.id_det
```

OutCntQr

```sql
SELECT
    COUNT
    (
        p.id_priv
    )
FROM
    privilege AS p
WHERE
    p.n_out_tests > 0
```

OtherPrivQr

```sql
SELECT
    p.short_name
FROM
    privilege AS p
WHERE
    p.n_others = :sel_priv
```

MaxExrcQr

```sql
SELECT
    MAX
    (
        c.id_control_exerc
    )
FROM
    control_exerc AS c
```

LogLastQr

```sql
SELECT
    a.id_log,
    a.date_out
FROM
    abitur_logbook AS a
WHERE
    a.nomer_ab = :nomer_ab
ORDER BY
    a.date_in DESC
```

LogIDSelQr

```sql
SELECT
    a.id_log
FROM
    abitur_logbook AS a
WHERE
    a.nomer_ab = :nomer_ab
ORDER BY
    a.date_in DESC
```

ListDocFDUp

```sql
/* : TFDUpdateSQL -> DELETE */
DELETE FROM
    list_doc
WHERE
        nomer_ab = :old_nomer_ab
    AND
        n_doc    = :old_n_doc

/* : TFDUpdateSQL -> INSERT */
INSERT INTO
    list_doc
    (
        nomer_ab,
        n_doc,
        date_doc,
        doc_index
    )
VALUES
    (
        :nomer_ab,
        :n_doc,
        :date_doc,
        :doc_index
    )
```

ListDocFDQ

```sql
SELECT
    l.n_doc,
    d.text_doc,
    l.nomer_ab,
    l.date_doc,
    l.doc_index,
    d.date_doc AS date_docum,
    d.index_doc
FROM
    list_doc AS l,
    docum    AS d
WHERE
        l.n_doc    = d.n_doc
    AND
        l.nomer_ab = :nomer_ab
```

LangSelQr

```sql
/* FDConnection1 - Decanat */
SELECT
    l.langv
FROM
    langvich AS l
WHERE
    l.n_langvich = :n_langvich
```

KodSpecializQr

```sql
/* FDConnection1 - Decanat */
SELECT
    s_dir.code_spec_dir
FROM
    special_direction AS s_dir,
    specializ         AS specz
WHERE
        s_dir.n_spec      = specz.n_spec
    AND
        specz.n_specializ = :n_specializ
    AND
        s_dir.n_spec_dir  = specz.n_spec_dir
```

InfQr

```sql
SELECT
    p.id_priv,
    p.name_priv,
    p.n_others
FROM
    privilege AS p
WHERE
    p.n_others > 0
ORDER BY
    p.n_others
```

InfCntQr

```sql
SELECT
    COUNT
    (
        p.id_priv
    )
FROM
    privilege AS p
WHERE
    p.n_others > 0
```

IdAbQueueQr

```sql
UPDATE
    abitura
SET
    id_ab_queue = :id_ab_queue
WHERE
    nomer_ab    = :nomer_ab
```

GrazdanToDekanatQr

```sql
-- FDConnection1 - Decanat
SELECT
    c.short_name
FROM
    countries_ocrb AS c
WHERE
    c.digital_code = :id
```

FIOSearchQr

```sql
SELECT
    q.id_ab,
    q.status_queue,
    q.fam,
    q.name,
    q.otch,
    q.photo,
    q.digit_sign,
    q.n_fac,
    q.n_specializ,
    q.n_spec,
    q.vid_edu,
    q.category_ab,
    q.category_if,
    q.category_edu,
    q.term_edu,
    q.price,
    q.konkurs,
    (
        q.fam  || ' ' ||
        q.name || ' ' ||
        q.otch
    ) AS fio
FROM
    abitur_queue AS q
WHERE
        (
            q.fam  || ' ' ||
            q.name || ' ' ||
            q.otch
        )
            LIKE '%'|| :fio || '%'
    AND
        q.n_fac = :n_fac
    AND
        (
             q.status_queue = 104           -- dean allowed to keep in ABITURA
          OR
             q.status_queue = 304           -- registered online (dean allowed)
        ) 
    AND
        (
            q.id_ab
                NOT IN
                (
                    SELECT
                        a.id_ab_queue
                    FROM
                        abitura AS a        -- here is no documents
                )
        OR
            q.id_ab
                IN
                (
                    SELECT
                        a.id_ab_queue
                    FROM
                        abitura AS a
                    WHERE
                            a.status = 0    -- active student
                        OR
                            a.status = 1    -- took the documents
                        OR
                            a.status = 6    -- registered online
                )
        )
ORDER BY
    q.fam,
    q.name,
    q.otch
```

DocumInListQ

```sql
SELECT
    d.n_doc,
    d.text_doc,
    d.date_doc,
    d.index_doc
FROM
    docum AS d
WHERE
    d.n_doc = :n_doc
```

DocumFDQ

```sql
SELECT
    d.n_doc,
    d.text_doc
FROM
    docum AS d
WHERE
    d.n_doc
        NOT IN
        (
            SELECT
                l.n_doc
            FROM
                list_doc AS l
            WHERE
                l.nomer_ab = :nomer_ab
        )
ORDER BY
    d.n_doc
```

CountryQr

```sql
-- FDConnection1 - Decanat
SELECT
    c.digital_code,
    c.full_name,
    c.short_name
FROM
    countries_ocrb AS c
ORDER BY
    c.short_name
```

ContrySelQr

```sql
SELECT
    c.short_name
FROM
    countries_ocrb AS c
WHERE
    c.digital_code = :id
```

CntrlExrcQr

```sql
SELECT
    e.id_exerc,
    e.name_exerc
FROM
    exercise AS e
ORDER BY
    e.name_exerc
```

CkRegionQr

```sql
-- FDConnection1 - Decanat
SELECT
    r.n_centre,
    r.n_region,
    r.centre
FROM
    regional_centre AS r
WHERE
    r.n_region < 8
ORDER BY
    r.centre
```

CertificLogInsQr

```sql
INSERT INTO
    certificates_logbook
    (
        id_log,
        n_predmet,
        seria_s,
        nomer_s,
        ball,
        describe,
        rus_bel
    )
VALUES
    (
        :id_log,
        :n_predmet,
        :seria_s,
        :nomer_s,
        :ball,
        :describe,
        :rus_bel
    )
```

CategUpQr

```sql
UPDATE
    abitur_logbook
SET
    category = :category
WHERE
    id_log   = :id_log
```

BlockQ

```sql
SELECT
    *
FROM
    block_edit
WHERE
    n_fac = :fac
```

BlockBtnQr

```sql
SELECT
    b.id_block,
    b.add_abitur,
    b.took_doc1,
    b.took_doc2,
    b.re_inside_fac,
    b.restor_list
FROM
    block_edit AS b
WHERE
    b.n_fac = :n_fac
```

AdrLogLastQr

```sql
SELECT
    a.id_log,
    a.nomer_ab,
    a.date_in
FROM
    abitur_logbook AS a
WHERE
    a.nomer_ab = :nomer_ab
ORDER BY
    a.date_in DESC
```

AdresOutQr

```sql
UPDATE
    abitur_logbook
SET
    address_before = :address_before
WHERE
    id_log         = :id_log
```

AddrLogUpQr

```sql
UPDATE
    abitur_logbook
SET
    address_before = :address
WHERE
    id_log         = :id_log
```

AbiturSirTmpQr

```sql
SELECT
    a.dat_priv
FROM
    abitur_privileg AS a
WHERE
        a.nomer_ab = :nomer_ab
    AND
        a.n_priv   = 1
    AND
        a.sel_priv = 1
```

AbiturLogInsQr

```sql
INSERT INTO
    abitur_logbook
    (
        nom_dela,
        nomer_ab,
        date_in,
        vid_edu,
        price,
        term_edu,
        address_before,
        n_ck,
        n_specializ,
        n_fac,
        konkurs,
        category
    )
VALUES
    (
        :nom_dela,
        :nomer_ab,
        :date_in,
        :vid_edu,
        :price,
        :term_edu,
        :address_before,
        :n_ck,
        :n_specializ,
        :n_fac,
        :konkurs,
        :category
    )
```

AbiturInvTmpQr

```sql
SELECT
    a.dat_priv
FROM
    abitur_privileg AS a
WHERE
        a.nomer_ab = :nomer_ab
    AND
        a.n_priv   = 2
    AND
        a.sel_priv = 8
```

AbiturCompQr

```sql
SELECT
    a.nomer_ab,
    a.n_fac,
    a.n_specializ,
    a.n_spec,
    a.vid_edu,
    a.category_ab,
    a.category_if,
    a.education,
    a.term_edu,
    a.price,
    a.konkurs,
    a.status
FROM
    abitura AS a
WHERE
    a.id_ab_queue = :id_ab_queue
```
