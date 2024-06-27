# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QListDocToDekanat*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    l.nomer,
    l.name_doc,
    l.doc_date,
    l.doc_index,
    l.note
FROM
    list_doc AS l
```