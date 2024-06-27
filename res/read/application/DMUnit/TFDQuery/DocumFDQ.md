# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *DocumFDQ*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    d.n_doc,
    d.text_doc
FROM
    docum AS d
WHERE
    d.n_doc
        NOT IN
        (
            SELECT
                l.n_doc
            FROM
                list_doc AS l
            WHERE
                l.nomer_ab = :nomer_ab
        )
ORDER BY
    d.n_doc
```