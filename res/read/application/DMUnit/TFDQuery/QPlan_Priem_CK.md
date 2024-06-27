# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QPlan_Priem_CK*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    k.n_specializ,
    SUM
    (
        k.kol_place
    ),
    k.vid_edu
FROM
    kol_place AS k
WHERE
        k.n_specializ <> 2  
    AND
        k.n_specializ <> 5  
    AND
        k.text        =  2
    AND
        k.vid_edu     =  :vid_edu 
GROUP BY
    k.vid_edu,
    k.n_specializ
```