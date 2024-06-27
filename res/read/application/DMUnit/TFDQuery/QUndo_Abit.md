# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QUndo_Abit*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.status,
    a.nomer_ab
FROM
    abitura AS a
WHERE
        a.n_fac  = :n_fac
    AND
        a.status = :st
ORDER BY
    a.fam,
    a.name,
    a.otch
```