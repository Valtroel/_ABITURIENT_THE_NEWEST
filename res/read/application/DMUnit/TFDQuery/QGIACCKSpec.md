# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QGIACCKSpec*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    SUM
    (
        c.kol_p
    )
FROM
    ck AS c
WHERE
        c.n_specializ = 4
    OR
        c.n_specializ = 57
```