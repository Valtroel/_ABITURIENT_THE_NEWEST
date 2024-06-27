# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *StatusQueueQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
UPDATE
    abitur_queue AS a
SET
    a.fam          = :fam,
    a.name         = :name,
    a.otch         = :otch,
    a.status_queue = :status_queue,
    a.n_specializ  = :specializ,
    a.n_spec       = :n_spec,
    a.vid_edu      = :vid_edu,
    a.category_ab  = :category_ab,
    a.category_if  = :category_if,
    a.category_edu = :category_edu,
    a.term_edu     = :term_edu,
    a.price        = :price,
    a.konkurs      = :konkurs
WHERE
    a.id_ab        = :id_ab
```