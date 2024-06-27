# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *PrivQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.n_priv,
    a.sel_priv,
    a.dat_priv
FROM
    abitur_privileg AS a
WHERE
        a.nomer_ab = :nomer_ab
    AND
        a.n_priv   = :n_priv
```