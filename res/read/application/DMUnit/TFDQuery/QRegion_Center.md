# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QRegion_Center*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    r.n_centre,
    r.n_region,
    r.centre,
    r.flag
FROM
    regional_centre AS r
WHERE
    r.n_region = :region
ORDER BY
    r.centre
```