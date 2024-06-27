# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QSpisoc_Group_Pol*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.n_specializ,
    a.nom_group,
    a.n_privilege_exam,
    a.n_ck,
    a.nomer_ab,
    a.gragdan,
    a.vid_edu,
    a.konkurs,
    a.n_sport_category,
    a.v_k,
    a.priv,
    a.without,
    a.n_fac,
    a.middle_ball,
    a.price,
    a.sum_ball
FROM
    abitura AS a
WHERE
        a.n_specializ <> 2  
    AND
        a.n_specializ <> 5  
    AND
        a.n_fac       =  :n_fac
    AND
        a.status      =  0
    AND
        a.pol         =  :pol
ORDER BY
    a.nom_group,
    a.n_specializ,
    a.fam,
    a.name,
    otch
```