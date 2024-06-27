# [DB_ABITURIENT](../db_abiturient_2022.md) > ABITUR_QUEUE *(Digital queue for candidates)*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **TABLE DESCRIPTION**

| **Field Name** |  Keys   | *Description*                                                                                        |
|---------------:|:-------:|:-----------------------------------------------------------------------------------------------------|
|          ID_AB | PRIMARY | Идентификатор записи - `Передает в T_ABITURA.ID_AB_QUEUE`                                            |
|            FAM |         | Фамилия                                                                                              |
|           NAME |         | Имя                                                                                                  |
|           OTCH |         | Отчество                                                                                             |
|   STATUS_QUEUE |         | **Статус в очереди**</br>100 - *сфотографирован, введены имя, фамилия и отчество*</br>101 - *с фото и подписью в очередь к столу справок*</br>102 - *в очередь на факультеты после стола справок*</br>103 - *вызван*</br>104 - *декан разрешил сохраненить в ABITURA (должен увидеть оператор)*</br>105 - *сохранён в ABITURA*</br>201 - *забирать документы - в очередь после стола справок*</br>202 - *декан разрешил забрать документы (должен увидеть оператор)*</br>203 - *забрал документы - стол справок видит*</br>299 - *прошёл регистрацию online*</br>300 - *прошёл регистрацию online, сфотографирован, введены имя, фамилия и отчество*</br>301 - *прошёл регистрацию online, с фото и подписью в очередь к столу справок*</br>302 - *прошёл регистрацию online, в очередь на факультеты после стола справок*</br>304 - *прошёл регистрацию online, декан разрешил сохраненить в ABITURA (должен увидеть оператор)* |
|          PHOTO |         | Фото                                                                                                 |
|     DIGIT_SIGN | FOREIGN | `Получает из табл. ABITURA` - подпись                                                                |
|          N_FAC | FOREIGN | `Получает из T_FACULTY` - код факультета:</br>1 - *СИиЕ*</br>2 - *МВС*</br>3 - *ОФКиТ*</br>4 - *МСиТ*  |
|    NOMER_QUEUE |         | Номер в очереди                                                                                      |
|     TIME_QUEUE |         | Время постановки в очередь                                                                           |
|    N_SPECIALIZ |         | Направление специализации                                                                            |
|         N_SPEC | FOREIGN | `Получает из T_SPECIALITY` - идентификационный номер специализации                                   |
|        VID_EDU |         | **Форма обучения:**</br>0 - *дневная*</br>1 - *заочная*                                              |
|    CATEGORY_AB | FOREIGN | `Получает из табл. ABITURA`</br>**Категория абитуриента:**</br>0 - *Беларусь*</br>1 - *Иностранцы*</br>2 - *СНГ*</br>3 - *ДНР/ЛНР* |
|    CATEGORY_IF |         | **Условия поступления для СНГ и ДНР/ЛНР:**</br>0 - *Граждане РБ*</br>1 - *Иностранцы* - `Передает в T_ABITURA`                     |
|   CATEGORY_EDU | FOREIGN | `Получает из табл. ABITURA` - **Образование:**</br>0 - *среднее*</br>1 - *среднее специальное*</br>2 - *незаконченное высшее*</br>3 - *высшее*</br>4 - *профессионально-техническое* |
|       TERM_EDU |         | 0 - *полный*</br>1 - *сокращённый  2 курс (ССО)*</br>2 - *сокращённый  3 курс (ССО)*</br>3 - *1 курс (ВО)*</br>4 - *2 курс (ВО)*</br>5 - *3 курс (ВО)* |
|          PRICE |         | **Форма оплаты:**</br>0 - *бюджет*</br>1 - *за оплату*                                               |
|        KONKURS |         | 0 - *общий*</br>1 - *без вступительных испытаний*</br>2 - *вне конкурса*</br>3 - *целевой*           |
|   DATE_TIME_ID |         | Дата и время выбранные онлайн                                                                        |

---

## **TRIGGERS, PROCEDURES AND OTHER**

### *Before INSERT*

|      TRIGGER    |       Type       | Field Name |    Expression    | Action |
|:---------------:|:----------------:|:----------:|:----------------:|:------:|
| ABITUR_QUEUE_BI | *Auto increment* |   `ID_AB`  | IF *new* IS NULL |  ADD 1 |

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