# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QAdd_N_Group*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    n.n_group,
    n.nom_group,
    n.vid_edu,
    n.describe,
    n.n_fac,
    n.n_count
FROM
    n_group AS n
WHERE
    n.n_fac = :fac
ORDER BY
    n.vid_edu,
    n.nom_group
```