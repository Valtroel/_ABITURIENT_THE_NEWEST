# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QAbitur_Priv_Enter*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.nomer_ab,
    a.n_priv
FROM
    abitur_privileg AS a
WHERE
    a.nomer_ab = :n_ab
```