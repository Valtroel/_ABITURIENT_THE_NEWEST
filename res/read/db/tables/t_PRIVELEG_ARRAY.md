# [DB_ABITURIENT](../db_abiturient_2022.md) > PRIVELEG_ARRAY *(Intermediate table of PRIVILEGE and PRIVELEG_DELAILS links)*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **TABLE DESCRIPTION**

| **Field Name** |  Keys   | *Description*                                                                                |
|---------------:|:-------:|:---------------------------------------------------------------------------------------------|
|        ID_PRIV |         | `Связь с табл. PRIVELEGE` - *ID привелегии (foreign key)*                                    |
|         N_ITEM |         | `Связь с табл. PRIVELEGE` - *тип поощрения*</br>1 - *вне конкурса* (поле PRIVELEGE.N_WITHOUT_TESTS)</br>2 - *без экзаменов* (поле PRIVELEGE.N_OUT_TESTS)</br>3 - *другое* (поле PRIVELEGE.N_OTHER) |
|         ID_DET |         | `Связь с табл. PRIVELEG_DELAILS` - *ID основания получения привелегии (foreign key)*         |