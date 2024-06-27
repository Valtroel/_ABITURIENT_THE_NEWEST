# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QShow_Result_Exam*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    DISTINCT
        a.fam,
        a.name,
        a.otch,
        e.nom_ball,
        a.nomer_ab,
        e.n_predmet,
        e.ball,
        e.status_ball,
        a.nom_dela
FROM
    examen AS e
        RIGHT OUTER JOIN
            abitura AS a
                ON
                    e.nomer_ab = a.nomer_ab
WHERE
        a.status = 0
    AND
        a.nom_group =:n_gr
    AND
        e.n_predmet=:pr
ORDER BY
    a.fam,
    a.name,
    a.otch
```