# [DB_ABITURIENT](../db_abiturient_2022.md) > ABITUR_LOGBOOK *(The candidate documents)*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **TABLE DESCRIPTION**

| **Field Name** |   Keys  | *Description*                                                                                             |
|---------------:|:-------:|:----------------------------------------------------------------------------------------------------------|
|         ID_LOG | PRIMARY | Идентификатор записи                                                                                      |
|       NOM_DELA |         | Номер дела                                                                                                |
|       NOMER_AB | FOREIGN | `Получает из табл. ABITURA` - идентификатор кандидата                                                     |
|        DATE_IN | FOREIGN | `Получает из табл. ABITURA.DATE_PRIEM` - дата приёма документов                                           |
|        VID_EDU |         | Форма обучения                                                                                            |
|          PRICE |         | Форма оплаты                                                                                              |
|       TERM_EDU |         | **Полный** (*1 курс*) / **Сокращённый** (*2 и старше*)                                                    |
| ADDRESS_BEFORE | FOREIGN | `Получает из табл. ABITURA` - адрес регистрации                                                           |
|           N_CK |         | № района откуда ЦК (*Целевой Контракт*)</br>`(Связь с полем REGIONAL_CENTRE.N_CENTRE)`</br>`-1` - *нет*   |
|       DATE_OUT | FOREIGN | `Получает из табл. ABITURA.DATE_VOZVRAT` - дата возврата документов                                       |
|    N_SPECIALIZ |         | Направление специализации                                                                                 |
|          N_FAC | FOREIGN | `Получает из T_FACULTY` - код факультета:</br>1 - *СИиЕ*</br>2 - *МВС*</br>3 - *ОФКиТ*</br>4 - *МСиТ*       |
|        KONKURS |         | 0 - *общий*</br>1 - *без вступительных экзаменов*</br>2 - *вне конкурса*</br>3 - *целевой*                |
|       CATEGORY | FOREIGN | `Получает из T_CATEGORY.N_SPORT_CATEGORY` - код спортивного звания:</br>1 - *3 спортивный разряд*</br>2 - *2 спортивный разряд*</br>3 - *1 спортивный разряд*</br>4 - *Кандидат в Мастера Спорта (КМС)*</br>5 - *Мастер Спорта (МС)*</br>6 - *Мастер Спорта Международного Класса (МСМК)*</br>7 - *Заслуженный Мастер Спорта (ЗМС)*</br>8 - *3 кубок среди юниоров (кю)*</br>9 - *2 кубок среди юниоров (кю)*</br>10 - *1 кубок среди юниоров (кю)*</br>11 - *1 юношеский разряд*</br>12 - *нет*|

---

## **TRIGGERS, PROCEDURES AND OTHER**

### *Before INSERT*

|      TRIGGER      |       Type       |  Field Name |    Expression    | Action |
|:-----------------:|:----------------:|:-----------:|:----------------:|:------:|
| ABITUR_LOGBOOK_BI | *Auto increment* |  `ID_LOG`   | IF *new* IS NULL |  ADD 1 |

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