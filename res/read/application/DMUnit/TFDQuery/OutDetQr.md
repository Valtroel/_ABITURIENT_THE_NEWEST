# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *OutDetQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.n_item,
    a.id_det,
    d.name_detais
FROM
    priveleg_array   AS a,
    priveleg_details AS d
WHERE
        a.id_priv  = :id_priv
    AND
        d.id_det   = a.id_det
```