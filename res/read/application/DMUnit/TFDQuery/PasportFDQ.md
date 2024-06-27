# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *PasportFDQ*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    p.nomer,
    p.id_type,
    p.series,
    p.number,
    p.personal_number,
    p.date_give,
    p.date_valid,
    p.who_give,
    p.n_region
FROM
    personal_docum AS p
ORDER BY
    p.nomer
```