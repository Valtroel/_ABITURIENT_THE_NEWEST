# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *CertificLogInsQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
INSERT INTO
    certificates_logbook
    (
        id_log,
        n_predmet,
        seria_s,
        nomer_s,
        ball,
        describe,
        rus_bel
    )
VALUES
    (
        :id_log,
        :n_predmet,
        :seria_s,
        :nomer_s,
        :ball,
        :describe,
        :rus_bel
    )
```