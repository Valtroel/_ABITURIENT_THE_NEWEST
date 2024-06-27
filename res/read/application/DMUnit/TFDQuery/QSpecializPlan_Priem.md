# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QSpecializPlan_Priem*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    DISTINCT
        s.n_specializ,
        s.special,
        s.n_spec,
        s.n_spec_dir
FROM
    kol_place AS k
        INNER JOIN
            specializ AS s
                ON
                    k.n_specializ = s.n_specializ
WHERE
        k.vid_edu = :vid_edu
    AND
        k.n_fac   = :fac
ORDER BY
    s.special
```