# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QAbitura*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.address_before,
    a.address_life,
    a.address_mama,
    a.address_papa,
    a.category_ab,
    a.category_if,
    a.citizenship,
    a.d_prikaz_include,
    a.date_priem,
    a.date_r,
    a.date_v,
    a.date_vozvrat,
    a.education,
    a.fam,
    a.gragdan,
    a.konkurs,
    a.langv_ball,
    a.mama,
    a.middle_ball,
    a.n_centre,
    a.n_ck,
    a.n_fac, n_found,
    a.n_langvich,
    a.n_prikaz_include,
    a.n_region,
    a.n_spec,
    a.n_specializ,
    a.n_sport_category,
    a.n_vid_sport,
    a.name,
    a.name_edu_middle,
    a.name_edu_spec,
    a.nom_attest,
    a.nom_dela,
    a.nom_diplom,
    a.nom_group,
    a.nomer_ab,
    a.organ_v,
    a.otch,
    a.papa,
    a.pasport,
    a.personal_nomer,
    a.phone,
    a.place_r,
    a.pol,
    a.price,
    a.rus_bel,
    a.stag,
    a.stag_spec,
    a.status,
    a.sum_ball,
    a.term_edu,
    a.town_village,
    a.type_school,
    a.vid_edu,
    a.when_edu_middle,
    a.when_edu_spec,
    a.where_edu_middle,
    a.where_edu_spec,
    a.work_before,
    a.work_mama,
    a.work_papa,
    a.id_type,
    a.date_ok,
    a.disabled,
    a.street,
    a.house,
    a.flat,
    a.postcode
FROM
    abitura AS a
WHERE
        a.n_fac  = :n_fac
    AND
        a.status = 0
ORDER BY
    a.nom_dela
```