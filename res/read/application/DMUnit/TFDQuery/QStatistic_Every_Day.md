# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QStatistic_Every_Day*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.konkurs,
    a.n_specializ,
    COUNT
    (
        a.nomer_ab
    ),
    a.vid_edu,
    a.price,
    o.order_sp
FROM
    abitura AS a
        LEFT JOIN
            order_specializ AS o
                ON
                    a.n_specializ = o.n_specializ
WHERE
        a.n_specializ <> 2
    AND
        a.n_specializ <> 5
    AND
        a.n_fac       =  :n_fac
    AND
        a.status      =  0
    AND
        a.vid_edu     =  :vid_edu
GROUP BY
    a.vid_edu,
    o.order_sp,
    a.n_specializ,
    a.konkurs,
    a.price
```