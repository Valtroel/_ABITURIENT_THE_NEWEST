# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *WithOutTestLogQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    p.short_name,
    d.short_name
FROM
    privilege AS p,
    priveleg_details AS d,
    priveleg_array AS a
WHERE
        p.n_without_tests = :sel_priv
    AND
        d.id_det          = a.id_det
    AND
        a.n_item          = :dat_priv
    AND
        a.id_priv         = p.id_priv
```