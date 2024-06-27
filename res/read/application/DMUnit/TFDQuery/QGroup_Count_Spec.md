# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QGroup_Count_Spec*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.n_fac       = :n_fac
    AND
        a.status      = 0
    AND
        a.nom_group   = :n_gr
    AND
        a.n_specializ = :n_sp
```