# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QNoticeFIO*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.address_before,
    a.n_prikaz_include,
    a.d_prikaz_include,
    a.n_fac,
    a.n_specializ,
    a.term_edu,
    a.vid_edu
FROM
    abitura AS a
WHERE
    a.nomer_ab = :nomer_ab
```