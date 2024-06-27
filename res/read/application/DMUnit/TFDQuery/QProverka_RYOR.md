# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QProverka_RYOR*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.fam,
    a.n_fac,
    a.vid_edu,
    a.name_edu_middle,
    a.priv
FROM
    abitura AS a
WHERE
    (
         a.name_edu_middle LIKE 'УОР'
      OR
         a.name_edu_spec   LIKE 'УОР'
    )
    AND
        a.priv NOT LIKE '13.'
AND
    a.nomer_ab = :nomer
```