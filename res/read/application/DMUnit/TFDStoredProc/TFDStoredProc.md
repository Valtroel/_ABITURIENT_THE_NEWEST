# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > TFDStoredProc

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

> **ABBREVIATIONS IN THE TABLE**:</br>
> ***CN*** - connection to database;</br>
> ***dean*** - connect to "*Deanery*" database, other - to "*Abiturient*"</br>
> ***DS*** - has a *TDataSource*</br>
> ***Up*** - has a *TFDUpdateSQL*  

|                *Component name* |      *Type*      | *CN* | *Procedure name*         |
|--------------------------------:|:----------------:|:----:|:-------------------------|
|       [AbiturLogInsStrdPrc][p1] | TFDStoredProc \* |      | abitur_logbook_ins       |
|     [CertificLogDelStrdPrc][p2] | TFDStoredProc \* |      | certificates_logbook_del |
|         [MaxNumDelaStrdPrc][p3] | TFDStoredProc \* |      | max_num_dela             |
|            [PrivDelStrdPrc][p4] | TFDStoredProc \* |      | abitur_privileg_del      |
|     [PrivilegLogDelStrdPrc][p5] | TFDStoredProc \* |      | privileg_log_del         |
|     [PrivilegLogInsStrdPrc][p6] | TFDStoredProc \* |      | privileg_log_ins         |
|            [PrivInsStrdPrc][p7] | TFDStoredProc \* |      | abitur_privileg_ins      |
|      [RaspredBall12StrdPrc][p8] | TFDStoredProc \* |      | kol_summ_ball12          |
|      [RaspredBall34StrdPrc][p9] | TFDStoredProc \* |      | kol_summ_ball4           |
|       [RaspredBallStrdPrc][p10] | TFDStoredProc \* |      | kol_summ_ball3           |
|[StoredProcBall_Sertifikat][p11] | TFDStoredProc \* |      | ball_sertifikat          |
|      [StoredProcKolk_Konk][p12] | TFDStoredProc \* |      | kol_konk                 |
|     [StoredProcKolk_Konk1][p13] | TFDStoredProc \* |      | kol_konk1                |
|           [StoredProcN_AB][p14] | TFDStoredProc \* |      | get_nomer_ab             |
|       [StoredProcN_People][p15] | TFDStoredProc \* | dean | GET_N_PEOPLE             |
|    [StoredProcSelExercIns][p16] | TFDStoredProc \* |      | proc_sel_exerc_ins       |
| [StoredProcStatistic_Konk][p17] | TFDStoredProc \* |      | kol_priv                 |
|   [StoredProcSumm_Ball_2K][p18] | TFDStoredProc \* |      | koll_summ_ball2k         |
|      [StoredProcSumm_Ball][p19] | TFDStoredProc \* |      | kol_summ_ball2           |
|   [StoredProcSumm_Ball100][p20] | TFDStoredProc \* |      | kol_summ_ball_100        |

[p1]:  AbiturLogInsStrdPrc.md
[p2]:  CertificLogDelStrdPrc.md
[p3]:  MaxNumDelaStrdPrc.md
[p4]:  PrivDelStrdPrc.md
[p5]:  PrivilegLogDelStrdPrc.md
[p6]:  PrivilegLogInsStrdPrc.md
[p7]:  PrivInsStrdPrc.md
[p8]:  RaspredBall12StrdPrc.md
[p9]:  RaspredBall34StrdPrc.md
[p10]: RaspredBallStrdPrc.md
[p11]: StoredProcBall_Sertifikat.md
[p12]: StoredProcKolk_Konk.md
[p13]: StoredProcKolk_Konk1.md
[p14]: StoredProcN_AB.md
[p15]: StoredProcN_People.md
[p16]: StoredProcSelExercIns.md
[p17]: StoredProcStatistic_Konk.md
[p18]: StoredProcSumm_Ball_2K.md
[p19]: StoredProcSumm_Ball.md
[p20]: StoredProcSumm_Ball100.md