# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QLocality*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    l.id,
    l.n_district,
    l.name_locality
FROM
    locality AS l
WHERE
        l.n_district    = :district
    AND
        l.type_locality = :n_type
ORDER BY
    l.name_locality
```