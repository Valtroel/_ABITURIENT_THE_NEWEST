# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QFotoQeue*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.id_ab_queue,
    q.photo,
    q.digit_sign
FROM
    abitur_queue AS q,
    abitura AS a
WHERE
        a.id_ab_queue = q.id_ab
    AND
        a.nomer_ab    = :n_ab
```