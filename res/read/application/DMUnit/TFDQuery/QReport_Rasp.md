# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QReport_Rasp*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.fam || ' ' || a.name || ' ' || a.otch AS fio,
    a.n_specializ,
    a.vid_edu,
    a.n_fac,
    a.nom_attest,
    a.nom_diplom,
    a.name_edu_middle,
    a.name_edu_spec,
    a.where_edu_middle,
    a.where_edu_spec,
    a.when_edu_middle,
    a.when_edu_spec,
    a.nom_dela,
    a.date_priem,
    a.nom_group,
    a.photo
FROM
    abitura AS a
WHERE
    a.nomer_ab = :n_ab
```