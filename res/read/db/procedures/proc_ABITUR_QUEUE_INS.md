# [DB_ABITURIENT](../db_abiturient_2022.md) > *ABITUR_QUEUE_INS*

> Back to ["ABITURIENT 2022" Project](../../../../README.md)

## Create a new candidate record in the [**ABITUR_QUEUE**][4] table

### Procedure requires *INPUT* fields

| *Type*         | *Field name*     | *Description*            |
|:---------------|:-----------------|:-------------------------|
| *varchar (30)* | **FAM**          | *Last name*              |
| *varchar (30)* | **NAME**         | *First name*             |
| *varchar (30)* | **OTCH**         | *Surname*                |
| *smallint*     | **STATUS_QUEUE** | *What data was provided* |

> ***NOTE***:</br>*List of values T_ABITUR_QUEUE.**STATUS_QUEUE***:</br>100 - *сфотографирован, введены имя, фамилия и отчество*</br>101 - *с фото и подписью в очередь к столу справок*</br>102 - *в очередь на факультеты после стола справок*</br>103 - *вызван*</br>104 - *декан разрешил сохраненить в ABITURA (должен увидеть оператор)*</br>105 - *сохранён в ABITURA*</br>201 - *забирать документы - в очередь после стола справок*</br>202 - *декан разрешил забрать документы (должен увидеть оператор)*</br>203 - *забрал документы - стол справок видит*</br>299 - *прошёл регистрацию online*</br>300 - *прошёл регистрацию online, сфотографирован, введены имя, фамилия и отчество*</br>301 - *прошёл регистрацию online, с фото и подписью в очередь к столу справок*</br>302 - *прошёл регистрацию online, в очередь на факультеты после стола справок*</br>304 - *прошёл регистрацию online, декан разрешил сохраненить в ABITURA (должен увидеть оператор)*

### Procedure returns *OUTPUT* field values

> The Procedure returns **None** data

---
</br>

### Dependencies

List of dependent tables from a database:

* [**t_abitur_queue**][4]

List of dependent fields from tables:

* [**t_abitur_queue**][4].*fam*
* [**t_abitur_queue**][4].*name*
* [**t_abitur_queue**][4].*otch*
* [**t_abitur_queue**][4].*status_queue*

---
</br>

### Main logic

```sql
INSERT INTO
    ABITUR_QUEUE
    (
        FAM,
        NAME,
        OTCH,
        STATUS_QUEUE
    )
VALUES
    (
        :fam,
        :name,
        :otch,
        :status_queue
    );
```

[4]: ../t_ABITUR_QUEUE.md