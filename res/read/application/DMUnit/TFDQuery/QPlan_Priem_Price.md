# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QPlan_Priem_Price*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    k.n_specializ,
    SUM
    (
        k.kol_place
    ),
    k.vid_edu,
    k.text,
    k.price,
    o.order_sp
FROM
    kol_place AS k
        LEFT JOIN
            order_specializ AS o
                ON
                    k.n_specializ = o.n_specializ
WHERE
        k.n_specializ <> 2
    AND
        k.n_specializ <> 5  
    AND
        k.n_fac       =  :n_fac
    AND
        k.vid_edu     =  :vid_edu
    AND
        k.text        =  :text
    AND
        k.price       =  :price
GROUP BY
    k.vid_edu,
    k.text,
    k.price,
    o.order_sp,
    k.n_specializ
```