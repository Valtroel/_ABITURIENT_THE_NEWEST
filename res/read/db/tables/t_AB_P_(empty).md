# [DB_ABITURIENT](../db_abiturient_2022.md) > AB_P (**TEMPORARY, EMPTY TABLE**) *(Documents transfer between faculties)*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **TABLE DESCRIPTION**

| **Field Name** |  Keys   | *Description*                                                          |
|---------------:|:-------:|:-----------------------------------------------------------------------|
|         N_AB_P |         | Инкремент таблицы по переподаче документов                             |
|       NOMER_AB | FOREIGN | `Получает из табл. ABITURA` - идентификатор кандидата                  |
|       PRICE_DO |         | Форма оплаты до переподачи                                             |
|       PRICE_PO |         | Форма оплаты после переподачи                                          |
|     VID_EDU_DO |         | Вид обучения до переподачи                                             |
|     VID_EDU_PO |         | Вид обучения после переподачи                                          |
|    NOM_DELA_DO |         | Номер дела до переподачи                                               |
|    NOM_DELA_PO |         | Номер дела после переподачи                                            |
|   NOM_GROUP_DO |         | Номер группы до                                                        |
|   NOM_GROUP_PO |         | Номер группы после...                                                  |
| N_SPECIALIZ_DO |         | Направление специальности (специализация) до...                        |
| N_SPECIALIZ_PO |         | Направление специальности (специализация) после...                     |
|      N_SPEC_DO |         | Специальность до...                                                    |
|      N_SPEC_PO |         | Специальность после...                                                 |
|           N_CK |         | Был ли целевой контракт                                                |
|     KONKURS_DO |         | Конкурс до...                                                          |
|     KONKURS_PO |         | Конкурс после....                                                      |
|         DATE_P | FOREIGN | `Получает из табл. ABITURA.DATE_PRIEM` - дата переподачи документов    |