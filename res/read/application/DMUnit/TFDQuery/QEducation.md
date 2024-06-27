# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QEducation*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    e.id,
    e.nomer_ab,
    e.nom_doc,
    e.n_edu_doc,
    e.name_edu,
    e.where_edu,
    e.when_edu
FROM
    education AS e
WHERE
    e.nomer_ab = :nomer
```