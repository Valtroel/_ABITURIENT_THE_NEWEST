# [DB_ABITURIENT](../db_abiturient_2022.md) > ABITUR_PRIVILEG *(The privileges)*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **TABLE DESCRIPTION**

| **Field Name** |   Keys   | *Description*                                                     |
|---------------:|:--------:|:------------------------------------------------------------------|
|       NOMER_AB | FOREIGN  | `Получает из табл. T_ABITURA` - идентификатор кандидата             |
|         N_PRIV |          | 0 - *БВИ*</br>1 - *ВК*</br>2 - *другие*                           |
|       SEL_PRIV |          | **КОД ОСНОВАНИЯ получения привелегии**</br>*(Жестко зависит от значения поля `T_ABITUR_PRIVILEG.DAT_PRIV`)*           |
|       DAT_PRIV |          | *Хранит номер колонки из которой нужно читать*</br>*"**КОД ОСНОВАНИЯ** привелегии*"</br>1 - *Работать с `T_PRIVILEGE.N_WITHOUT_TESTS` - без втупительных экзаменов*</br>2 - *Работать с `T_PRIVILEGE.N_OUT_TESTS` - вне конкурса*</br>3 - *Работать с `T_PRIVILEGE.N_OTHERS` - другое* |

---

## **GRANTS**

* *ALL*
  * ABITUR1
  * ABITUR2
  * ABITUR3
  * ABITUR4
  * ABITURA
  * ALEXANDER_GONCHAROV
  * ASU
  * ASU1
  * ASU2
  * ASU3
  * ASU4
  * DEVELOPER
  * IVANOVA_A
  * OKSANA
  * PK
  * PK_IT
  * PK_IT1
  * PK_IT2
  * PK_IT3
  * PK_IT4
  * PK_IT5
  * PK_MSTIG1
  * PK_MSTIG2
  * PK_MSTIG3
  * PK_MSTIG4
  * PK_MSTIGP1
  * PK_MSTIGP2
  * PK_MSTIG_1
  * PK_MSTIG_2
  * PK_MSTIG_3
  * PK_MSTIG_4
  * PK_MSTIG_P1
  * PK_MSTIG_P2
  * PK_MVS
  * PK_MVS1
  * PK_MVS2
  * PK_MVS3
  * PK_MVS4
  * PK_MVS5
  * PK_MVSP1
  * PK_MVSP2
  * PK_MVS_1
  * PK_MVS_2
  * PK_MVS_3
  * PK_MVS_4
  * PK_MVS_P1
  * PK_MVS_P2
  * PK_OFKIT
  * PK_OFKIT1
  * PK_OFKIT2
  * PK_OFKIT3
  * PK_OFKIT4
  * PK_OFKIT5
  * PK_OFKITP1
  * PK_OFKITP2
  * PK_OFK_1
  * PK_OFK_2
  * PK_OFK_3
  * PK_OFK_4
  * PK_OFK_P1
  * PK_OFK_P2
  * PK_OTV1
  * PK_OTV2
  * PK_OTV3
  * PK_OTV4
  * PK_SIIE
  * PK_SIIE1
  * PK_SIIE2
  * PK_SIIE3
  * PK_SIIE4
  * PK_SIIE5
  * PK_SIIEP1
  * PK_SIIEP2
  * PK_SIIEP3
  * PK_SIIE_1
  * PK_SIIE_2
  * PK_SIIE_3
  * PK_SIIE_4
  * PK_SIIE_P1
  * PK_SIIE_P2