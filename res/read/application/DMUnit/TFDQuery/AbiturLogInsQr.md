# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *AbiturLogInsQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
INSERT INTO
    abitur_logbook
    (
        nom_dela,
        nomer_ab,
        date_in,
        vid_edu,
        price,
        term_edu,
        address_before,
        n_ck,
        n_specializ,
        n_fac,
        konkurs,
        category
    )
VALUES
    (
        :nom_dela,
        :nomer_ab,
        :date_in,
        :vid_edu,
        :price,
        :term_edu,
        :address_before,
        :n_ck,
        :n_specializ,
        :n_fac,
        :konkurs,
        :category
    )
```