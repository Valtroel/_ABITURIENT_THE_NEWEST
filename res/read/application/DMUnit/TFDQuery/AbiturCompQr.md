# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *AbiturCompQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.nomer_ab,
    a.n_fac,
    a.n_specializ,
    a.n_spec,
    a.vid_edu,
    a.category_ab,
    a.category_if,
    a.education,
    a.term_edu,
    a.price,
    a.konkurs,
    a.status
FROM
    abitura AS a
WHERE
    a.id_ab_queue = :id_ab_queue
```