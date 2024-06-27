# ["ABITURIENT 2022" Project](../../../README.md) > DB_ABITURIENT (*candidates*)

> Back to [ABITURIENT (*application*)](../application/app_abiturient_2022.md)

> Back to [SQL queries](../application/queries_abiturient.md)

|               *Table name* | *Description*                                                |
|---------------------------:|:-------------------------------------------------------------|
|               [ABITURA][1] | Candidate's data                                             |
|        [ABITUR_LOGBOOK][2] | Candidate's documents                                        |
|       [ABITUR_PRIVILEG][3] | Candidate privileges                                         |
|          [ABITUR_QUEUE][4] | Digital queue for candidates                                 |
|                  [AB_P][5] | Documents transfer between faculties (*temporary, empty!*)   |
|                  [BALL][6] | Grade Codes                                                  |
|            [BLOCK_EDIT][7] | Prohibition of changes                                       |
|       [CALL_ABITURIENT][8] | Digital queue. Voice assistant                               |
|              [CATEGORY][9] | Sports categories                                            |
| [CERTIFICATES_LOGBOOK][10] | The centralizing testing data (*empty!*)                     |
|                   [CK][11] | The supervising organization data                            |
|              [CK_PLAN][12] | Planes fot training of athletes                              |
|        [CONTROL_EXERC][13] | Intermediate table of results of the physical tests          |
|         [DATE_ARRIVED][14] | Candidate arrial date                                        |
|    [DATE_TIME_ARRIVED][15] | Inermediate Candidate arrial date table                      |
|                [DOCUM][16] | Document classifier                                          |
|            [EDUCATION][17] | List of education documents (*garbage*)                      |
|         [EDU_DOCUMENT][18] | Documents classifier                                         |
|           [EDU_PERIOD][19] | List of study periods (*Lookup table*)                       |
|               [EXAMEN][20] | Entrance exam results                                        |
|             [EXERCISE][21] | List of exercises                                            |
|              [FACULTY][22] | Department descriptions list                                 |
|  [INTERMEDIATE_ABITUR][23] | The candidate's data (*empty!*)                              |
|            [KOL_PLACE][24] | Number of available seats                                    |
|             [LANGUAGE][25] | List of Languages                                            |
|             [LIST_DOC][26] | List of student documents                                    |
|             [LOCALITY][27] | Directory of administrative-territorial units                |
|              [N_GROUP][28] | Generate Group ID                                            |
|      [ORDER_SPECIALIZ][29] | To display a list of specializations                         |
|        [PERSONAL_TYPE][30] | List of types of identification card                         |
|              [PREDMET][31] | List of subjects                                             |
|       [PRIVELEG_ARRAY][32] | Intermediate table of PRIVILEGE and PRIVELEG_DELAILS links   |
|     [PRIVELEG_DETAILS][33] | List of achievements                                         |
|            [PRIVELEGE][34] | List of PRIVILEGES                                           |
|         [PRIVELEG_LOG][35] | Intermediate table contains privilege entries                |
|                [QUEUE][36] | Digital queue data                                           |
|               [REGION][37] | List of the regions                                          |
|                [SCANS][38] | List of scanned documents                                    |
|  [SELECTION_COMMITTEE][39] | List of members of the election commission                   |
|         [SEL_EXERCIZE][40] | List of examination exercises (*empty!*)                     |
|           [SERTIFICAT][41] | About Centralized Testing Certificates                       |
|               [SHKALA][42] | Conversation from a hundred- to a ten-point system           |
|           [SPECIALITY][43] | List of specializations                                      |
|            [SPECIALIZ][44] | List of areas of specialization                              |
|               [STREET][45] | Directory of Minsk streets                                   |
|         [TIME_ARRIVED][46] | List of time periods                                         |
|              [VID_EDU][47] | List of forms of study                                       |

---
<br>

# DB_ABITURIENT TRIGGERS

## **B**efore **I**nsert - *Increment generators*

| *No* | *Trigger name*     | *Table name*          | *Field name*        |
|:----:|:-------------------|:----------------------|:--------------------|
|   1  | AB_P_BI            | [AB_P][5]             | *N_AB_P*            |
|   2  | ABITUR_LOGBOOK_BI  | [ABITUR_LOGBOOK][2]   | *ID_LOG*            |
|   3  | ABITUR_QUEUE_BI    | [ABITUR_QUEUE][4]     | *ID_AB*             |
|   4  | BLOCK_EDIT_BI      | [BLOCK_EDIT][7]       | *ID_BLOCK*          |
|   5  | CALL_ABITURIENT_BI | [CALL_ABITURIENT][8]  | *ID_CALL*           |
|   6  | CONTROL_EXERC_BI   | [CONTROL_EXERC][13]   | *ID_CONTROL_EXERC*  |
|   7  | EDU_PERIOD_BI      | [EDU_PERIOD][19]      | *ID*                |
|   8  | EXERCISE_BI        | [EXERCISE][21]        | *ID_EXERC*          |
|   9  | INS_N_GROUP        | [N_GROUP][28]         | *N_GROUP*           |
|  10  | ORDER_SPECIALIZ_BI | [ORDER_SPECIALIZ][29] | *N_OR_SPEC*         |
|  11  | SEL_EXERCIZE_BI    | [SEL_EXERCIZE][40]    | *ID_SEL_EXERC*      |
|  12  | SHKALA_BI          | [SHKALA][42]          | *INC_SHKALA*        |
|  13  | TI_BALL            | [BALL][6]             | *NOM_BALL*          |
|  14  | TI_CATEGORY        | [CATEGORY][9]         | *N_SPORT_CATEGORY*  |
|  15  | TI_CK              | [CK][11]              | *N_CK*              |
|  16  | TI_DOCUM           | [DOCUM][16]           | *N_DOC*             |
|  17  | TI_KOL_PLACE       | [KOL_PLACE][24]       | *N_KOL_PLACE*       |
|  18  | TI_PREDMET         | [PREDMET][31]         | *N_PREDMET*         |
|  19  | TI_REGION          | [REGION][37]          | *N_REGION*          |

## **B**efore **D**elete - *Removers*

| *No* | *Trigger name*     | *Table name*</br>(*number is direction*)                      | *Search Key*  |
|:----:|:-------------------|---------------------------------------------------------------|:--------------|
|   1  | DEL_ABITURIENT     | 1 - [EXAMEN][20]</br> 2 - [SERTIFICAT][41]</br>3 - [AB_P][5]  | NOMER_AB      |

---
<br>

# DB_ABITURIENT GENERATORS (*increase the last value by one*)

| *No* | *Generator name*               | *Use in trigger*   | *Affect the Table*       | *Affect the Field*    |
|:----:|:-------------------------------|:-------------------|:-------------------------|:----------------------|
|   1  | *ABITURA_NOMER_AB*             | ---                | [ABITURA][1]             | *NOMER_AB*            |
|   2  | *BALL_NOM_BALL*                | TI_BALL            | [BALL][6]                | *NOM_BALL*            |
|   3  | *CATEGORY_N_SPORT_CATEGORY*    | TI_CATEGORY        | [CATEGORY][9]            | *N_SPORT_CATEGORY*    |
|   4  | *CK_N_CK*                      | TI_CK              | [CK][11]                 | *N_CK*                |
|   5  | *DOCUM_N_DOC*                  | TI_DOCUM           | [DOCUM][16]              | *N_DOC*               |
|   6  | *GEN_AB_P_ID*                  | AB_P_BI            | [AB_P][5]                | *N_AB_P*              |
|   7  | *GEN_ABITUR_LOGBOOK_ID*        | ABITUR_LOGBOOK_BI  | [ABITUR_LOGBOOK][2]      | *ID_LOG*              |
|   8  | *GEN_ABITUR_QUEUE_ID*          | ABITUR_QUEUE_BI    | [ABITUR_QUEUE][4]        | *ID_AB*               |
|   9  | *GEN_BLOCK_EDIT_ID*            | BLOCK_EDIT_BI      | [BLOCK_EDIT][7]          | *ID_BLOCK*            |
|  10  | *GEN_CALL_ABITURIENT_ID*       | CALL_ABITURIENT_BI | [CALL_ABITURIENT][8]     | *ID_CALL*             |
|  11  | *GEN_CONTROL_EXERC_ID*         | CONTROL_EXERC_BI   | [CONTROL_EXERC][13]      | *ID_CONTROL_EXERC*    |
|  12  | *GEN_EDU_PERIOD_ID*            | EDU_PERIOD_BI      | [EDU_PERIOD][19]         | *ID*                  |
|  13  | *GEN_EXERCISE_ID*              | EXERCISE_BI        | [EXERCISE][21]           | *ID_EXERC*            |
|  14  | *GEN_ORDER_SPECIALIZ_ID*       | ORDER_SPECIALIZ_BI | [ORDER_SPECIALIZ][29]    | *N_OR_SPEC*           |
|  15  | *GEN_SEL_EXERCIZE_ID*          | SEL_EXERCIZE_BI    | [SEL_EXERCIZE][40]       | *ID_SEL_EXERC*        |
|  16  | *GEN_SHKALA_ID*                | SHKALA_BI          | [SHKALA][42]             | *INC_SHKALA*          |
|  17  | *IBE$LOG_TABLES_GEN*           | ---                | ---                      | ---                   |
|  18  | *KOL_PLACE_N_KOL_PLACE*        | TI_KOL_PLACE       | [KOL_PLACE][24]          | *N_KOL_PLACE*         |
|  19  | *NOMER_GROUP*                  | INS_N_GROUP        | [N_GROUP][28]            | *N_GROUP*             |
|  20  | *PREDMET_N_PREDMET*            | TI_PREDMET         | [PREDMET][31]            | *N_PREDMET*           |
|  21  | *REGION_N_REGION*              | TI_REGION          | [REGION][37]             | *N_REGION*            |

<br>

# DB_ABITURIENT [PROCEDURES](DB_ABITURIENT_PROCEDURES.md)

## **CREATE** *Procedures*

| *No* | *Procedure name*                   | *Description*                  |
|:----:|:-----------------------------------|:-------------------------------|
|   1  | [ABITUR_LOGBOOK_INS][proc-1]       | Create a new log entry         |
|   2  | [ABITUR_PRIVILEG_INS][proc-2]      |  |
|   3  | [ABITUR_QUEUE_INS][proc-3]         | Create a new candidate record  |
|   4  | [CERTIFICATES_LOGBOOK_INS][proc-4] |  |
|   5  | [CONTROL_EXERC_IU][proc-5]         |  |
|   6  | [PRIVILEG_LOG_INS][proc-6]         |  |

[proc-1]: procedures/proc_ABITUR_LOGBOOK_INS.md
[proc-2]: procedures/proc_ABITUR_PRIVILEG_INS.md
[proc-3]: procedures/proc_ABITUR_QUEUE_INS.md
[proc-4]: procedures/proc_CERTIFICATES_LOGBOOK_INS.md
[proc-5]: procedures/proc_CONTROL_EXERC_IU.md
[proc-6]: procedures/proc_PRIVILEG_LOG_INS.md

## **READ** *Procedures*

| *No* | *Procedure name*                   | *Description*                  |
|:----:|:-----------------------------------|:-------------------------------|
|   1  | [ALL_MAS_KONKURS][proc-7]          |  |
|   2  | [BALL_SERTIFIKAT][proc-8]          |  |
|   3  | [CONTROL_EXERC_SEL][proc-9]        |  |
|   4  | [EXAM_CNT][proc-10]                |  |
|   5  | [GET_NOMER_AB][proc-11]            |  |
|   6  | [GIAZ01][proc-12]                  |  |
|   7  | [GIAZ03][proc-13]                  |  |
|   8  | [GIAZ021][proc-14]                 |  |
|   9  | [GIAZ022][proc-15]                 |  |
|  10  | [GIAZ0221][proc-16]                |  |
|  11  | [KOL_KONK][proc-17]                |  |
|  12  | [KOL_KONK1][proc-18]               |  |
|  13  | [KOL_PRIV][proc-19]                |  |
|  14  | [KOL_SERTIFIKAT][proc-20]          |  |
|  15  | [KOL_SUMM_BALL_100][proc-21]       |  |
|  16  | [KOL_SUMM_BALL][proc-22]           |  |
|  17  | [KOL_SUMM_BALL2][proc-23]          |  |
|  18  | [KOL_SUMM_BALL3][proc-24]          |  |
|  19  | [KOL_SUMM_BALL4][proc-25]          |  |
|  20  | [KOL_SUMM_BALL12][proc-26]         |  |
|  21  | [KOLL_SUMM_BALL2K][proc-27]        |  |
|  22  | [KONKURS][proc-28]                 |  |
|  23  | [KONKURS2][proc-29]                |  |
|  24  | [KONKURS2V][proc-30]               |  |
|  25  | [KONKURS3][proc-31]                |  |
|  26  | [KONKURS12][proc-32]               |  |
|  27  | [KONKURS34][proc-33]               |  |
|  28  | [KONKURS333][proc-34]              |  |
|  29  | [MAX_NUM_DELA][proc-35]            |  |
|  30  | [PREDMET_BALL][proc-36]            |  |
|  31  | [PROTOKOL][proc-37]                |  |

[proc-7]:  procedures/proc_ALL_MAS_KONKURS.md
[proc-8]:  procedures/proc_BALL_SERTIFIKAT.md
[proc-9]:  procedures/proc_CONTROL_EXERC_SEL.md
[proc-10]: procedures/proc_EXAM_CNT.md
[proc-11]: procedures/proc_GET_NOMER_AB.md
[proc-12]: procedures/proc_GIAZ01.md
[proc-13]: procedures/proc_GIAZ03.md
[proc-14]: procedures/proc_GIAZ021.md
[proc-15]: procedures/proc_GIAZ022.md
[proc-16]: procedures/proc_GIAZ0221.md
[proc-17]: procedures/proc_KOL_KONK.md
[proc-18]: procedures/proc_KOL_KONK1.md
[proc-19]: procedures/proc_KOL_PRIV.md
[proc-20]: procedures/proc_KOL_SERTIFIKAT.md
[proc-21]: procedures/proc_KOL_SUMM_BALL_100.md
[proc-22]: procedures/proc_KOL_SUMM_BALL.md
[proc-23]: procedures/proc_KOL_SUMM_BALL2.md
[proc-24]: procedures/proc_KOL_SUMM_BALL3.md
[proc-25]: procedures/proc_KOL_SUMM_BALL4.md
[proc-26]: procedures/proc_KOL_SUMM_BALL12.md
[proc-27]: procedures/proc_KOLL_SUMM_BALL2K.md
[proc-28]: procedures/proc_KONKURS.md
[proc-29]: procedures/proc_KONKURS2.md
[proc-30]: procedures/proc_KONKURS2V.md
[proc-31]: procedures/proc_KONKURS3.md
[proc-32]: procedures/proc_KONKURS12.md
[proc-33]: procedures/proc_KONKURS34.md
[proc-34]: procedures/proc_KONKURS333.md
[proc-35]: procedures/proc_MAX_NUM_DELA.md
[proc-36]: procedures/proc_PREDMET_BALL.md
[proc-37]: procedures/proc_PROTOKOL.md

## **UPDATE** *Procedures*

| *No* | *Procedure name*                    | *Description*                  |
|:----:|:------------------------------------|:-------------------------------|
|   1  | [ABITUR_FROM_QUEUE][proc-38]        |  |
|   2  | [ABITUR_QUEUE_UPD_NO_SIGN][proc-39] |  |
|   3  | [ABITUR_QUEUE_UPD][proc-40]         |  |
|   4  | [ABITURA_STATUS_UP][proc-41]        |  |
|   5  | [PROC_SEL_EXERC_INS][proc-42]       |  |

[proc-38]: procedures/proc_ABITUR_FROM_QUEUE.md
[proc-39]: procedures/proc_ABITUR_QUEUE_UPD_NO_SIGN.md
[proc-40]: procedures/proc_ABITUR_QUEUE_UPD.md
[proc-41]: procedures/proc_ABITURA_STATUS_UP.md
[proc-42]: procedures/proc_PROC_SEL_EXERC_INS.md

## **DELETE** *Procedures*

| *No* | *Procedure name*                    | *Description*                  |
|:----:|:------------------------------------|:-------------------------------|
|   1  | [ABITUR_PRIVILEG_DEL][proc-43]      |  |
|   2  | [ABITUR_QUEUE_DEL][proc-44]         |  |
|   3  | [CERTIFICATES_LOGBOOK_DEL][proc-45] |  |
|   4  | [CONTROL_EXERC_DEL][proc-46]        |  |
|   5  | [PRIVILEG_LOG_DEL][proc-47]         |  |

[proc-43]: procedures/proc_ABITUR_PRIVILEG_DEL.md
[proc-44]: procedures/proc_ABITUR_QUEUE_DEL.md
[proc-45]: procedures/proc_CERTIFICATES_LOGBOOK_DEL.md
[proc-46]: procedures/proc_CONTROL_EXERC_DEL.md
[proc-47]: procedures/proc_PRIVILEG_LOG_DEL.md


[1]:  tables/t_ABITURA.md
[2]:  tables/t_ABITUR_LOGBOOK.md
[3]:  tables/t_ABITUR_PRIVILEG.md
[4]:  tables/t_ABITUR_QUEUE.md
[5]:  tables/t_AB_P_(empty).md
[6]:  tables/t_BALL.md
[7]:  tables/t_BLOCK_EDIT.md
[8]:  tables/t_CALL_ABITURIENT.md
[9]:  tables/t_CATEGORY.md
[10]: tables/t_CERTIFICATES_LOGBOOK_(empty).md
[11]: tables/t_CK.md
[12]: tables/t_CK_PLAN.md
[13]: tables/t_CONTROL_EXERC.md
[14]: tables/t_DATE_ARRIVED.md
[15]: tables/t_DATE_TIME_ARRIVED.md
[16]: tables/t_DOCUM.md
[17]: tables/t_EDUCATION_(garbage).md
[18]: tables/t_EDU_DOCUMENT.md
[19]: tables/t_EDU_PERIOD.md
[20]: tables/t_EXAMEN.md
[21]: tables/t_EXERCISE.md
[22]: tables/t_FACULTY.md
[23]: tables/t_INTERMEDIATE_ABITUR_(empty).md
[24]: tables/t_KOL_PLACE.md
[25]: tables/t_LANGUAGE.md
[26]: tables/t_LIST_DOC.md
[27]: tables/t_LOCALITY.md
[28]: tables/t_N_GROUP.md
[29]: tables/t_ORDER_SPECIALIZ.md
[30]: tables/t_PERSONAL_TYPE.md
[31]: tables/t_PREDMET.md
[32]: tables/t_PRIVELEG_ARRAY.md
[33]: tables/t_PRIVELEG_DETAILS.md
[34]: tables/t_PRIVILEGE.md
[35]: tables/t_PRIVILEG_LOG.md
[36]: tables/t_QUEUE.md
[37]: tables/t_REGION.md
[38]: tables/t_SCANS_(empty).md
[39]: tables/t_SELECTION_COMMITTEE.md
[40]: tables/t_SEL_EXERCIZE_(empty).md
[41]: tables/t_SERTIFICAT.md
[42]: tables/t_SHKALA.md
[43]: tables/t_SPECIALITY.md
[44]: tables/t_SPECIALIZ.md
[45]: tables/t_STREET.md
[46]: tables/t_TIME_ARRIVED.md
[47]: tables/t_VID_EDU.md
