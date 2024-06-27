# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QStatistic_Every_Day_Special*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.konkurs,
    a.n_spec,
    COUNT
    (
        a.nomer_ab
    ),
    a.vid_edu,
    a.price
FROM
    abitura AS a
WHERE
        a.status  = 0 
    AND
        a.vid_edu = :vid_edu
    AND
        a.n_spec  = :n_spec
GROUP BY
    a.vid_edu,
    a.n_spec,
    a.konkurs,
    a.price
```