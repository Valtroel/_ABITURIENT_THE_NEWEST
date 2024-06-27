# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QToDekanat*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    p.nomer,
    p.fam,
    p.name,
    p.otch,
    p.pol,
    p.n_found,
    p.place_r,
    p.papa,
    p.mama,
    p.mariage,
    p.education,
    p.phone,
    p.address_papa,
    p.address_mama,
    p.name_educ,
    p.when_educ,
    p.where_educ,
    p.middle_b,
    p.n_vid_sport,
    p.vid_edu,
    p.n_fac,
    p.kurs,
    p.n_spec,
    p.n_specializ,
    p.n_group,
    p.status_people,
    p.inc_group,
    p.work_before,
    p.address_before,
    p.address,
    p.address_life,
    p.data_r,
    p.n_prikaz_include,
    p.d_prikaz_include,
    p.n_prikaz_kurs,
    p.scholarship,
    p.vid_edu_include,
    p.n_found_include,
    p.n_centre,
    p.gragdan,
    p.address_posle,
    p.phone_posle,
    p.pasport,
    p.personal_nomer,
    CAST
    (
        NULL AS blob
    ) AS photo,
    CAST
    (
        NULL AS blob
    ) AS digit_sign,
    p.date_end,
    p.d_include,
    p.id_street,
    p.house,
    p.flat,
    p.postcode,
    p.number
FROM
    people AS p
ORDER BY
    p.nomer
```