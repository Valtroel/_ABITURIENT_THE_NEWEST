# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QNoticeSpec*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    d.code_spec_dir,
    s.s_dir
FROM
    special_direction AS d,
    specializ AS s
WHERE
        s.n_specializ = :n_specializ
    AND
        d.n_spec_dir  = s.n_spec_dir
```