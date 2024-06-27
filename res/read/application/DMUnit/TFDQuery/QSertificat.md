# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QSertificat*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    s.nomer_ab,
    s.n_predmet,
    s.seria_s,
    s.nomer_s,
    s.balls,
    s.describe,
    s.rus_bel,
    s.price,
    s.year_s
FROM
    sertificat AS s
WHERE
    s.nomer_ab = :nomer
```