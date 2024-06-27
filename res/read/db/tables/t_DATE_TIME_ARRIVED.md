# [DB_ABITURIENT](../db_abiturient_2022.md) > DATE_TIME_ARRIVED *(Inermediate Candidate arrial date table)*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **TABLE DESCRIPTION**

| **Field Name** |  Keys   | *Description*                                                                                          |
|---------------:|:-------:|:-------------------------------------------------------------------------------------------------------|
|   ID_DATE_TIME |         | Номер записи                                                                                           |
|        DATE_ID |         | Внешний ключ даты (Значения от 1 до 5)                                                                 |
|        TIME_ID |         | Внешний ключ времени (Значения от 1 до 3)                                                              |
|          N_FAC | FOREIGN | `Получает из T_FACULTY` - код факультета:</br>1 - *СИиЕ*</br>2 - *МВС*</br>3 - *ОФКиТ*</br>4 - *МСиТ*    |