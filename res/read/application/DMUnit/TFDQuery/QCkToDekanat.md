# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QCkToDekanat*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    c.n_ck,
    c.nomer,
    c.n_region,
    c.n_centre,
    c.customer,
    c.n_specializ,
    c.status_ck
FROM
    ck AS c
```