# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *RegionUpCKQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
UPDATE
    abitur_logbook AS a
SET
    a.n_ck   = :n_ck
WHERE
    a.id_log = :id_log
```