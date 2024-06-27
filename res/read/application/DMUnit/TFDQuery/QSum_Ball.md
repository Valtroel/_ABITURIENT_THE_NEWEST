# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QSum_Ball*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.nomer_ab,
    SUM
    (
        e.ball
    ),
    a.sum_ball,
    a.middle_ball
FROM
    abitura AS a
        INNER JOIN
            examen AS e
                ON
                    a.nomer_ab = e.nomer_ab  
WHERE
        a.status = 0    
    AND
        a.n_fac  = :n_fac
GROUP BY
    a.nomer_ab,
    a.sum_ball,
    a.middle_ball
```