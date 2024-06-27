# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *DocumInListQ*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    d.n_doc,
    d.text_doc,
    d.date_doc,
    d.index_doc
FROM
    docum AS d
WHERE
    d.n_doc = :n_doc
```