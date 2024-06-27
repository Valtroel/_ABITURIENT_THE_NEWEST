# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QStatistic_Every_Day_Ball_Price*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.konkurs,
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.status      = 0
    AND
        a.n_fac       = :n_fac 
    AND
        a.vid_edu     = :vid_edu
    AND
        a.price       = :price
    AND
        a.n_specializ = :n_sp
GROUP BY
    a.konkurs,
    a.price
```