# [DB_ABITURIENT](../db_abiturient_2022.md) > SEL_EXERCIZE  (**EMPTY TABLE**) *(List of examination exercises)*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **TABLE DESCRIPTION**

| **Field Name** |  Keys   | *Description*                                                                              |
|---------------:|:-------:|:-------------------------------------------------------------------------------------------|
|   ID_SEL_EXERC | PRIMARY | Идентификатор записи упражнения                                                            |
|       NOMER_AB | FOREIGN | `Получает из табл. ABITURA` - идентификатор кандидата                                      |
|  NUM_EXERC_GRP |         | Идентификатор группы контрольных упражнений (КУ)                                           |
|       ID_EXERC | FOREIGN | `Получает из T_EXERCISE.ID_EXERC` - идентификатор названия КУ (контрольного упражнения)    |