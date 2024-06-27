# [DB_ABITURIENT](../db_abiturient_2022.md) > PRIVILEG_LOG *(Intermediate table contains privilege entries)*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **TABLE DESCRIPTION**

| **Field Name** |  Keys   | *Description*                                                                                |
|---------------:|:-------:|:---------------------------------------------------------------------------------------------|
|         ID_LOG |         | `Связь с табл. ABITUR_LOGBOOK` - (foreign key)                                               |
|         N_PRIV |         | **Тип поощрения:**</br>0 - *без экзаменов* (поле PRIVELEGE.N_WITHOUT_TESTS),</br>1 - *вне конкурса* (поле PRIVELEGE.N_OUT_TESTS),</br>3 - *другое* (поле PRIVELEGE.N_OTHER) |
|       SEL_PRIV |         | Переключатель привелегий (значения от 1 до 19) (возможно, данные из PRIVILEG.N_WITHOUT_TESTS)|
|       DAT_PRIV |         | Значение переключателя привилегии                                                            |