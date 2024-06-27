# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *VO2KSpecializQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.nomer_ab
FROM
    abitura AS a
WHERE
        a.status       = 0
    AND
        a.n_specializ  = :sp
    AND
        a.vid_edu      = :v_e
    AND
        (
            a.term_edu = 4
         OR
            a.term_edu = 5
        )
    AND
        a.n_fac        = :n_fac
    AND
        a.price        = :price
```