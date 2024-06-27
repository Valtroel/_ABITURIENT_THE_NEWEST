# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QExam*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.fam,
    e.ball,
    e.status_ball,
    e.n_predmet,
    a.name,
    a.otch,
    a.konkurs,
    a.nom_dela,
    a.vid_edu,
    a.nomer_ab,
    a.rus_bel,
    e.nom_ball,
    a.without,
    a.term_edu,
    a.education,
    a.category_if,
    a.n_sport_category,
    a.price
FROM
    abitura AS a
        LEFT OUTER JOIN
            examen AS e
                ON
                    a.nomer_ab = e.nomer_ab
WHERE
        a.status    = 0
    AND
        a.nom_group = :n_gr
    AND
        a.n_fac     = :n_fac
ORDER BY
    a.fam,
    a.name,
    a.otch,
    e.n_predmet
```