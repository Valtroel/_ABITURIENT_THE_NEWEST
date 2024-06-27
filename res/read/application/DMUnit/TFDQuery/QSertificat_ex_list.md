# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QSertificat_ex_list*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    p.text_predmet,
    a.date_priem,
    e.ball,
    s.rus_bel
FROM
    examen AS e
        INNER JOIN
            abitura AS a
                ON
                    e.nomer_ab  = a.nomer_ab
        inner JOIN
            sertificat AS s
                ON
                    a.nomer_ab  = s.nomer_ab
        INNER JOIN
            predmet AS p
                ON
                    e.n_predmet = p.n_predmet
WHERE 
        a.nomer_ab    = :nomer
    AND 
        e.status_ball = 1
    AND
        e.nomer_ab    = s.nomer_ab
    AND
        e.n_predmet   = s.n_predmet
```