# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QGroup_Count*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.nom_group,
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.n_fac  = :n_fac
    AND
        a.status = 0
GROUP BY
    a.nom_group
```