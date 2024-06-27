# [DB_ABITURIENT](../db_abiturient_2022.md) > TRIGGERS

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **B**efore **I**nsert - *Increment generators*

| *No* | *Trigger name*     |*Table name*         | *Field name*        |
|:----:|:-------------------|:--------------------|:--------------------|
|   1  | AB_P_BI            | **AB_P**            | *N_AB_P*            |
|   2  | ABITUR_LOGBOOK_BI  | **ABITUR_LOGBOOK**  | *ID_LOG*            |
|   3  | ABITUR_QUEUE_BI    | **ABITUR_QUEUE**    | *ID_AB*             |
|   4  | BLOCK_EDIT_BI      | **BLOCK_EDIT**      | *ID_BLOCK*          |
|   5  | CALL_ABITURIENT_BI | **CALL_ABITURIENT** | *ID_CALL*           |
|   6  | CONTROL_EXERC_BI   | **CONTROL_EXERC**   | *ID_CONTROL_EXERC*  |
|   7  | EDU_PERIOD_BI      | **EDU_PERIOD**      | *ID*                |
|   8  | EXERCISE_BI        | **EXERCISE**        | *ID_EXERC*          |
|   9  | INS_N_GROUP        | **N_GROUP**         | *N_GROUP*           |
|  10  | ORDER_SPECIALIZ_BI | **ORDER_SPECIALIZ** | *N_OR_SPEC*         |
|  11  | SEL_EXERCIZE_BI    | **SEL_EXERCIZE**    | *ID_SEL_EXERC*      |
|  12  | SHKALA_BI          | **SHKALA**          | *INC_SHKALA*        |
|  13  | TI_BALL            | **BALL**            | *NOM_BALL*          |
|  14  | TI_CATEGORY        | **CATEGORY**        | *N_SPORT_CATEGORY*  |
|  15  | TI_CK              | **CK**              | *N_CK*              |
|  16  | TI_DOCUM           | **DOCUM**           | *N_DOC*             |
|  17  | TI_KOL_PLACE       | **KOL_PLACE**       | *N_KOL_PLACE*       |
|  18  | TI_PREDMET         | **PREDMET**         | *N_PREDMET*         |
|  19  | TI_REGION          | **REGION**          | *N_REGION*          |

## **B**efore **D**elete - *Removers*

| *No* | *Trigger name*     | *Table name*</br>(*number is direction*)      | *Search Key*  |
|:----:|:-------------------|-----------------------------------------------|:--------------|
|   1  | DEL_ABITURIENT     | 1 - EXAMEN</br> 2 - SERTIFICAT</br>3 - AB_P   | NOMER_AB      |