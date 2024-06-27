# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QSpecializ*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    s.n_specializ,
    s.code_specializ,
    s.special,
    s.n_fac,
    s.n_spec,
    s.special_direction
FROM
    specializ AS s
WHERE
        s.n_specializ <> 2
    AND
        s.n_specializ <> 5
    AND
        s.n_specializ <> 49
    AND
        s.n_specializ <> 6
    AND
        s.n_fac       =  :n_fac
ORDER BY
    s.special
```