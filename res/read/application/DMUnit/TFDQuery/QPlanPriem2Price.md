# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QPlanPriem2Price*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    k.n_specializ,
    k.kol_place
FROM
    kol_place AS k
WHERE
        k.n_fac       = :n_fac
    AND
        k.vid_edu     = :vid_edu
    AND
        k.n_specializ = :spec
    AND
        k.text        = 1
    AND
        k.price       = :price
```