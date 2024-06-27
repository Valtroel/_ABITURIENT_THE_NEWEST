# [DB_ABITURIENT](../db_abiturient_2022.md) > SPECIALIZ *(List of areas of specialization)*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **TABLE DESCRIPTION**

|         **Field Name** |  Keys   | *Description*                                                                                          |
|-----------------------:|:-------:|:-------------------------------------------------------------------------------------------------------|
|            N_SPECIALIZ | PRIMARY | Идентификационный номер специализации - `Передает в T_CK, T_CK_PLAN`                                   |
|         CODE_SPECIALIZ |         | Код специализации (не уникален!!!)                                                                     |
|                SPECIAL |         | Название специализации                                                                                 |
|                  N_FAC | FOREIGN | `Получает из T_FACULTY` - код факультета:</br>1 - *СИиЕ*</br>2 - *МВС*</br>3 - *ОФКиТ*</br>4 - *МСиТ*    |
|                 N_SPEC | FOREIGN | `Получает из T_SPECIALITY` - идентификационный номер специализации                                     |
|          SPECIAL_SKLON |         | Название специализации для печати в документах                                                         |
|      SPECIAL_DIRECTION |         | Полное наименование направления специальности                                                          |
|             N_SPEC_DIR |         | `Связь с таблицей DECANAT.SPECIALITY` - код направления специальности                                  |
| SPECIAL_DIRECTION_SOKR |         | Сокращенное наименование направления специальности                                                     |