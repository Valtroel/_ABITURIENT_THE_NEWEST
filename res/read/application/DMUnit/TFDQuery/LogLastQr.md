# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *LogLastQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.id_log,
    a.date_out
FROM
    abitur_logbook AS a
WHERE
    a.nomer_ab = :nomer_ab
ORDER BY
    a.date_in DESC
```