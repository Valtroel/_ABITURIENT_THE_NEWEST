# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QExerc_Grp*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    e.id_exerc,
    e.name_exerc
FROM
    exercise AS e
WHERE
    e.id_exerc
        IN
        (
            SELECT
                c.id_exerc
            FROM
                control_exerc AS c
            WHERE
                    c.n_specializ   = :n_specializ
                AND
                    c.pol           = :pol
                AND
                    c.num_exerc_grp = :num_exerc_grp
        )
```