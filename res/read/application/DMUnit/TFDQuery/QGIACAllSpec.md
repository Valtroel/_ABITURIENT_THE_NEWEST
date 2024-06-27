# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QGIACAllSpec*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    SUM
    (
        k.kol_place
    )
FROM
    kol_place AS k
WHERE
        k.vid_edu = :vid_edu
    AND
        k.price   = :price
    AND
    (
            k.n_specializ = 4
        OR
            k.n_specializ = 57
    )
```