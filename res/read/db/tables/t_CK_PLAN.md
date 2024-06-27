# [DB_ABITURIENT](../db_abiturient_2022.md) > CK_PLAN *(Planes fot training of athletes)*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **TABLE DESCRIPTION**

| **Field Name** |  Keys   | *Description*                                                                          |
|---------------:|:-------:|:---------------------------------------------------------------------------------------|
|     ID_CK_PLAN |         | Номер записи                                                                           |
|    N_SPECIALIZ | FOREIGN | `Получает из T_SPECIALIZ` - код специализации                                          |
|      KOL_PLACE |         | Количество мест зарезервированых под целевую подготовку                                |
|      TERM_EDUC |         | **Период обучения**</br>00 - *полный срок*</br>1 - *сокращённый* - `Передает в T_CK`   |