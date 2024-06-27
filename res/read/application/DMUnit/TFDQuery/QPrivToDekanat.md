# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QPrivToDekanat*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    p.n_priv,
    p.nomer,
    p.vid_priv,
    p.uch_god,
    p.text_priv,
    p.doc_priv,
    p.data_c,
    p.data_po,
    p.describe
FROM
    priv AS p
```