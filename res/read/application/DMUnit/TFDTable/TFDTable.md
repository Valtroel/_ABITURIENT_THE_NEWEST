# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > TFDTable

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

> **ABBREVIATIONS IN THE TABLE**:</br>
> ***CN*** - connection to database;</br>
> ***dean*** - connect to "*Deanery*" database, other - to "*Abiturient*"</br>
> ***DS*** - has a *TDataSource*</br>
> ***Up*** - has a *TFDUpdateSQL*  

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

[t1]:  CntrExrcTbl.md
[t2]:  Increment_GroupTable.md
[t3]:  RegCentrTbl.md
[t4]:  Selection_CommitteeFDTable.md
[t5]:  TBall.md
[t6]:  TCategory.md
[t7]:  TCk.md
[t8]:  TDocum.md
[t9]:  TEduDoc.md
[t10]: TFaculty.md
[t11]: TFoundation.md
[t12]: TKol_Place.md
[t13]: TPass_User.md
[t14]: TPredmet.md
[t15]: TRegion.md
[t16]: TVid_Sport.md