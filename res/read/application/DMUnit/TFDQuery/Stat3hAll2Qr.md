# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *Stat3hAll2Qr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.konkurs,
    count
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
        a.term_edu    = 1
    AND
        a.price       = :price
    AND
        a.category_if = 0
GROUP BY
    a.konkurs
```