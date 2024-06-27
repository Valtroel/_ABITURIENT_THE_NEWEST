# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *PrintDocQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.nomer_ab,
    a.fam,
    a.name,
    a.otch
FROM
    abitura AS a
WHERE
        a.n_fac       = :n_fac
    AND
        a.vid_edu     = :vid_edu
    AND
        a.n_specializ = :n_specializ
    AND
        a.status      = 5
ORDER BY
    a.fam,
    a.name,
    a.otch
```