# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QType_locality*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    l.n_type,
    MIN
    (
        l.name_type
    ) AS name_type,
    l.short_type_name
FROM
    type_locality AS l
GROUP BY
    l.n_type,
    l.short_type_name
```