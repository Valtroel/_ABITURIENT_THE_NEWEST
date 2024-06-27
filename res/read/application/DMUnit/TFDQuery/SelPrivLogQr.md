# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *SelPrivLogQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    p.n_priv,
    p.sel_priv,
    p.dat_priv
FROM
    privileg_log AS p
WHERE
    p.id_log = :id_log
```