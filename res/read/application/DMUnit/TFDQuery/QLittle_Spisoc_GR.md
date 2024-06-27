# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QLittle_Spisoc_GR*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.nomer_ab
FROM
    abitura AS a
WHERE
        a.status =    0
    AND
        a.n_fac  =    :fac
    AND
        a.priv   LIKE '10'
ORDER BY
    a.fam,
    a.name,
    a.otch
```