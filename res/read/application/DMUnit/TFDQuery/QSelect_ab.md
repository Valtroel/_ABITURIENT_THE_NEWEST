# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QSelect_ab*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.pol,
    a.place_r,
    a.address_before,
    a.address_life,
    a.middle_ball,
    a.name_edu_middle,
    a.name_edu_spec,
    a.where_edu_middle,
    a.where_edu_spec,
    a.when_edu_middle,
    a.when_edu_spec,
    a.mama,
    a.papa,
    a.address_mama,
    a.address_papa,
    a.work_mama,
    a.work_papa,
    a.n_vid_sport,
    a.n_sport_category,
    a.phone,
    a.date_r,
    a.education,
    a.work_before,
    a.nomer_ab,
    a.status,
    a.d_prikaz_include,
    a.n_prikaz_include,
    a.n_found,
    a.n_region,
    a.citizenship,
    a.n_privilege_exam,
    q.photo,
    q.digit_sign,
    a.n_ck,
    a.v_k,
    a.priv,
    a.without,
    a.n_langvich,
    a.n_centre,
    a.pasport,
    a.personal_nomer,
    a.id_type,
    a.date_v,
    a.date_ok,
    a.organ_v,
    a.street,
    a.house,
    a.flat,
    a.postcode
FROM
    abitura AS a,
    abitur_queue AS q
WHERE
        a.vid_edu     = :edu
    AND
        q.id_ab       = a.id_ab_queue
    AND
        a.n_fac       = :fac  
    AND
        a.status      = 0  
    AND
        a.n_specializ = :n_sp  
    AND
        a.price       = :p
ORDER BY
    a.fam,
    a.name,
    a.otch
```