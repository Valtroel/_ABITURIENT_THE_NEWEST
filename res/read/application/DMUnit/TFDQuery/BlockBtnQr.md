# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *BlockBtnQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    b.id_block,
    b.add_abitur,
    b.took_doc1,
    b.took_doc2,
    b.re_inside_fac,
    b.restor_list
FROM
    block_edit AS b
WHERE
    b.n_fac = :n_fac
```