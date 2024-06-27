# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *SportQuery*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    s.nomer,
    s.sport_category,
    s.sud_category,
    s.who_give,
    s.d_prikaz_sport,
    s.n_prikaz_sport,
    s.n_vid_sport,
    s.who_give_sud,
    s.d_prikaz_sud,
    s.n_prikaz_sud
FROM
    sport AS s
WHERE
    s.nomer = :nomer
```