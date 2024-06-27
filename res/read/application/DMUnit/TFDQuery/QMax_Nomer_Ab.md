# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QMax_Nomer_Ab*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    MAX
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
    a.n_fac = :n_fac
```