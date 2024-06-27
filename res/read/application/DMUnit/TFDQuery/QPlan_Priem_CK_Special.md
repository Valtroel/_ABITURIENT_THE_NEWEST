# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QPlan_Priem_CK_Special*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    s.n_spec,
    SUM
    (
        k.kol_place
    ) AS sum1,
    k.vid_edu
FROM
    kol_place AS k
        INNER JOIN
            specializ AS s
                ON
                    k.n_specializ = s.n_specializ  
WHERE  
        k.text    = 2
    AND
        k.vid_edu = :vid_edu
GROUP BY
    k.vid_edu,
    s.n_spec
```