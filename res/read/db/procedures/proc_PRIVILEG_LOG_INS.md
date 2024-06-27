# [DB_ABITURIENT](../db_abiturient_2022.md) > *PRIVILEG_LOG_INS*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

<!-- ## Create a new log entry in the [**ABITUR_LOGBOOK**][2] table

### Procedure requires *INPUT* fields

| *Type*          | *Field name*       | *Description*                                      |
|:----------------|:-------------------|:---------------------------------------------------|
| *smallint*      | **NOM_DELA**       | *File number*                                      |
| *integer*       | **NOMER_AB**       | *Candidate number*                                 |
| *date*          | **DATE_IN**        | *Date of submission of documents*                  |
| *smallint*      | **VID_EDU**        | *Form of study*                                    |
| *smallint*      | **PRICE**          | *Payment form*                                     |
| *smallint*      | **TERM_EDU**       | *Full or reduced term of study*                    |
| *varchar (100)* | **ADDRESS_BEFORE** | *Registration address*                             |
| *smallint*      | **N_CK**           | *Region number of the Supervising Organization*    |
| *smallint*      | **N_SPECIALIZ**    | *Specialization ID number*                         |
| *smallint*      | **N_FAC**          | *Faculty ID number*                                |
| *smallint*      | **KONKURS**        | *Terms of the competition for admission*           |
| *smallint*      | **CATEGORY**       | *Sports title code*                                |

> ***NOTE***:</br>*List of values T_ABITUR_LOGBOOK.**VID_EDU***:</br>

> ***NOTE***:</br>*List of values T_ABITUR_LOGBOOK.**PRICE***:</br>

> ***NOTE***:</br>*List of values T_ABITUR_LOGBOOK.**TERM_EDU***:</br>

> ***NOTE***:</br>*List of values T_ABITUR_LOGBOOK.**N_CK***:</br>

> ***NOTE***:</br>*List of values T_ABITUR_LOGBOOK.**N_SPECIALIZ***:</br>

> ***NOTE***:</br>*List of values T_ABITUR_LOGBOOK.**N_FAC***:</br>1 - *СИиЕ*</br>2 - *МВС*</br>3 - *ОФКиТ*</br>4 - *МСиТ*

> ***NOTE***:</br>*List of values T_ABITUR_LOGBOOK.**KONKURS***:</br>0 - *общий*</br>1 - *без вступительных экзаменов*</br>2 - *вне конкурса*</br>3 - *целевой контракт*

> ***NOTE***:</br>*List of values T_ABITUR_LOGBOOK.**CATEGORY***:</br>1 - *3 спортивный разряд*</br>2 - *2 спортивный разряд*</br>3 - *1 спортивный разряд*</br>4 - *Кандидат в Мастера Спорта (КМС)*</br>5 - *Мастер Спорта (МС)*</br>6 - *Мастер Спорта Международного Класса (МСМК)*</br>7 - *Заслуженный Мастер Спорта (ЗМС)*</br>8 - *3 кубок среди юниоров (кю)*</br>9 - *2 кубок среди юниоров (кю)*</br>10 - *1 кубок среди юниоров (кю)*</br>11 - *1 юношеский разряд*</br>12 - *нет*

### Procedure returns *OUTPUT* field values

> The Procedure returns **None** data

---
</br>

### Dependencies

List of dependent tables from a database:

* [**t_abitur_logbook**][2]

List of dependent fields from tables:

* [**t_abitur_logbook**][2].*nom_dela*
* [**t_abitur_logbook**][2].*nomer_ab*
* [**t_abitur_logbook**][2].*date_in*
* [**t_abitur_logbook**][2].*vid_edu*
* [**t_abitur_logbook**][2].*price*
* [**t_abitur_logbook**][2].*term_edu*
* [**t_abitur_logbook**][2].*address_before*
* [**t_abitur_logbook**][2].*n_ck*
* [**t_abitur_logbook**][2].*n_specializ*
* [**t_abitur_logbook**][2].*n_fac*
* [**t_abitur_logbook**][2].*konkurs*
* [**t_abitur_logbook**][2].*category*

---
</br>

### Main logic

```sql
INSERT INTO
    ABITUR_LOGBOOK
    (
        NOM_DELA,
        NOMER_AB,
        DATE_IN,
        VID_EDU,
        PRICE,
        TERM_EDU,
        ADDRESS_BEFORE,
        N_CK,
        N_SPECIALIZ,
        N_FAC,
        KONKURS,
        CATEGORY
    )
VALUES
    (
        :nom_dela,
        :nomer_ab,
        :date_in,
        :vid_edu,
        :price,
        :term_edu,
        :address_before,
        :n_ck,
        :n_specializ,
        :n_fac,
        :konkurs,
        :category
    );
```

[2]:  ../t_ABITUR_LOGBOOK.md -->
