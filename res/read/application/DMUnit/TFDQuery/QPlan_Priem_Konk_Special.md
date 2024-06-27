# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QPlan_Priem_Konk_Special*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    s.n_spec,
    k.text,
    SUM
    (
        k.kol_place
    ) AS sum1
FROM 
    kol_place AS k
        INNER JOIN
            specializ AS s
                ON
                    k.n_specializ = s.n_specializ  
WHERE
        k.vid_edu = :vid_edu
    AND
        s.n_spec  = :n_sp
GROUP BY
    s.n_spec,
    k.text
```