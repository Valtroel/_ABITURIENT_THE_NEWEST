# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QPlan_Priem_All_Special*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    s.n_spec,
    s.code_spec,
    SUM
    (
        k.kol_place
    ) AS sum1,
    k.vid_edu,
    s.spec
FROM
    kol_place AS k
        INNER JOIN
            specializ AS z
                ON
                    k.n_specializ = z.n_specializ
        INNER JOIN
            speciality AS s
                ON
                    z.n_spec      = s.n_spec  
WHERE
    k.vid_edu = :vid_edu
GROUP BY
    k.vid_edu,
    s.code_spec,
    s.n_spec,
    s.spec
```