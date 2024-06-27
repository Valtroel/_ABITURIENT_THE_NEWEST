# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *FIOSearchQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    q.id_ab,
    q.status_queue,
    q.fam,
    q.name,
    q.otch,
    q.photo,
    q.digit_sign,
    q.n_fac,
    q.n_specializ,
    q.n_spec,
    q.vid_edu,
    q.category_ab,
    q.category_if,
    q.category_edu,
    q.term_edu,
    q.price,
    q.konkurs,
    (
        q.fam  || ' ' ||
        q.name || ' ' ||
        q.otch
    ) AS fio
FROM
    abitur_queue AS q
WHERE
        (
            q.fam  || ' ' ||
            q.name || ' ' ||
            q.otch
        )
            LIKE '%'|| :fio || '%'
    AND
        q.n_fac = :n_fac
    AND
        (
             q.status_queue = 104           -- dean allowed to keep in ABITURA
          OR
             q.status_queue = 304           -- registered online (dean allowed)
        ) 
    AND
        (
            q.id_ab
                NOT IN
                (
                    SELECT
                        a.id_ab_queue
                    FROM
                        abitura AS a        -- here is no documents
                )
        OR
            q.id_ab
                IN
                (
                    SELECT
                        a.id_ab_queue
                    FROM
                        abitura AS a
                    WHERE
                            a.status = 0    -- active student
                        OR
                            a.status = 1    -- took the documents
                        OR
                            a.status = 6    -- registered online
                )
        )
ORDER BY
    q.fam,
    q.name,
    q.otch
```