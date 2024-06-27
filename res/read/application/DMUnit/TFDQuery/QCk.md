# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QCk*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    c.n_ck,
    c.n_specializ,
    c.n_region,
    c.text_dep,
    c.kol_p,
    c.customer_place
FROM
    ck AS c
WHERE
        c.n_specializ <> 2
    AND c.n_specializ <> 5
    AND c.n_specializ =  :n_spec
```