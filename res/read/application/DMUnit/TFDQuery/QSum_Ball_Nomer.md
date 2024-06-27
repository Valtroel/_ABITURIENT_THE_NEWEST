# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QSum_Ball_Nomer*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    SUM
    (
        e.ball
    ),
    a.sum_ball,
    a.middle_ball,
    a.nomer_ab
FROM
    abitura AS a
        INNER JOIN
            examen AS e
                ON
                    a.nomer_ab = e.nomer_ab  
WHERE
    a.nomer_ab=:nomer
GROUP BY
    a.sum_ball,
    a.middle_ball,
    a.nomer_ab
```