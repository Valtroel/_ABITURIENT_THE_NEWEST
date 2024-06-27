# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QControl_Exerc*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    e.name_exerc
FROM
    control_exerc AS c,
    exercise AS e
WHERE
        c.n_specializ   = :n_specializ
    AND
        c.pol           = :pol
    AND
        c.num_exerc_grp = :num_exerc_grp
    AND
        e.id_exerc      = c.id_exerc
```