# [DB_ABITURIENT](../db_abiturient_2022.md) > SHKALA *(Conversation from a hundred- to a ten-point system)*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## **TABLE DESCRIPTION**

|    **Field Name**|  Keys   | *Description*                                                                  |
|-----------------:|:-------:|:-------------------------------------------------------------------------------|
|       INC_SHKALA |         | Идентификационный номер записи                                                 |
|        N_PREDMET |         | `Связь с табл. PREDMET` - идентификатор дисциплины</br>1 - *Биология*</br>4 - *Белорусский (русский) язык*</br>9 - *Математика*</br>10 - *География* |
|  BALL_SERTIFIKAT |         | Количество баллов по ЦТ (стобалльная шкала)                                    |
|             BALL |         | Средний балл по десятибалльной шкале</br>Тип: **FLOAT**                        |
|          RUS_BEL |         | ???? (Значения от 0 до 2)                                                      |