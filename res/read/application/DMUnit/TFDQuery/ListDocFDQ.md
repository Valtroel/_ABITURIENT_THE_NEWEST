# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *ListDocFDQ*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    l.n_doc,
    d.text_doc,
    l.nomer_ab,
    l.date_doc,
    l.doc_index,
    d.date_doc AS date_docum,
    d.index_doc
FROM
    list_doc AS l,
    docum    AS d
WHERE
        l.n_doc    = d.n_doc
    AND
        l.nomer_ab = :nomer_ab
```