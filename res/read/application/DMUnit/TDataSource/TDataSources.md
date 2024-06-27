# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > TDataSource

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

> **ABBREVIATIONS IN THE TABLE**:</br>
> ***CN*** - connection to database;</br>
> ***dean*** - connect to "*Deanery*" database, other - to "*Abiturient*"</br>
> ***DS*** - has a *TDataSource*</br>
> ***Up*** - has a *TFDUpdateSQL*  

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

[ds1]:  BlockDS.md
[ds2]:  CkRegionDS.md
[ds3]:  CntrExrcDS.md
[ds4]:  CountryDS.md
[ds5]:  DSAb_P.md
[ds6]:  DSAb_Pr_Enter.md
[ds7]:  DSAbitur_Priv_Enter.md
[ds8]:  DSAbitura.md
[ds9]:  DSAdd_N_Group.md
[ds10]: DSAdress.md
[ds11]: DSBall.md
[ds12]: DSCategory.md
[ds13]: DSCenter.md
[ds14]: DSCk.md
[ds15]: DSCkQ.md
[ds16]: DSCkToDekanat.md
[ds17]: DSDistrict.md
[ds18]: DSDocum.md
[ds19]: DSEducation.md
[ds20]: DSEduDoc.md
[ds21]: DSExam.md
[ds22]: DSExamSpec.md
[ds23]: DSFaculty.md
[ds24]: DSFoundation.md
[ds25]: DSGroup_Count_Spec.md
[ds26]: DSGroup_Count.md
[ds27]: DSInc_Gr_Old.md
[ds28]: DSKol_Place.md
[ds29]: DSLangvich.md
[ds30]: DSLangvichToDekanat.md
[ds31]: DSLittle_Spisoc_GR.md
[ds32]: DSLocality.md
[ds33]: DSMax_Nom_Dela.md
[ds34]: DSMax_Nomer_Ab.md
[ds35]: DSPasport.md
[ds36]: DSPass_User.md
[ds37]: DSPersonalDocum.md
[ds38]: DSPlan_Priem_All.md
[ds39]: DSPlan_Priem_CK.md
[ds40]: DSPredmet.md
[ds41]: DSPrivToDekanat.md
[ds42]: DSQSertificat_Res.md
[ds43]: DSQShkala.md
[ds44]: DSRegion_Center.md
[ds45]: DSRegion.md
[ds46]: DSReport_Rasp.md
[ds47]: DSResult_Exam.md
[ds48]: DSSelect_ab.md
[ds49]: DSSertificat.md
[ds50]: DSShow_Result_Exam.md
[ds51]: DSSpecializ.md
[ds52]: DSSpecializPlan_Priem.md
[ds53]: DSSpisoc_Group_Pol.md
[ds54]: DSSpisoc_Group.md
[ds55]: DSStatistic_Every_Day.md
[ds56]: DSStreet.md
[ds57]: DSSum_Ball_Nomer.md
[ds58]: DSSum_Ball.md
[ds59]: DSToDekanat.md
[ds60]: DSType_locality.md
[ds61]: DSType_street.md
[ds62]: DSUndo_Abit.md
[ds63]: DSVid_Sport.md
[ds64]: ExercDS.md
[ds65]: FIOSearchDS.md
[ds66]: Increment_GroupSource.md
[ds67]: ListDocFDDS.md
[ds68]: Selection_CommitteeDS.md
[ds69]: SpecializDS.md
[ds70]: SPFDDataSource.md
[ds71]: SportQSource.md