# [DB_ABITURIENT](../db_abiturient_2022.md) > CONTROL_EXERC *(Intermediate table of results of the physical tests)*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **TABLE DESCRIPTION**

|   **Field Name** |  Keys   | *Description*                                                                                            |
|-----------------:|:-------:|:---------------------------------------------------------------------------------------------------------|
| ID_CONTROL_EXERC |         | Номер записи сдачи нормативов                                                                            |
|            N_FAC |         | `Получает из T_FACULTY` - код факультета:</br>1 - *СИиЕ*</br>2 - *МВС*</br>3 - *ОФКиТ*</br>4 - *МСиТ*      |
|      N_SPECIALIZ |         | `Связь с табл. SPECIALIZ (из Деканата)` - код специализации                                              |
|              POL | FOREIGN | `Связь с полем ABITURA.POL` - пол                                                                        |
|    NUM_EXERC_GRP |         | `Связь с табл. SEL_EXERCIZE ` - номер группы                                                             |
|         ID_EXERC | FOREIGN | `Получает из T_EXERCISE.ID_EXERC` - идентификатор названия КУ (контрольного упражнения)                  |