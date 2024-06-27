# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *OutQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    p.id_priv,
    p.name_priv,
    p.n_out_tests
FROM
    privilege AS p
WHERE
    p.n_out_tests > 0
ORDER BY
    p.n_out_tests
```