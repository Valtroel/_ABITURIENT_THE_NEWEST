# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QProverka_sert*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.nomer_ab
FROM
    abitura AS a
WHERE
    (
         a.without IS NULL
      OR
         a.without =  ''
    )
    AND
        a.konkurs <> 4
    AND
        a.rus_bel IS NULL
    AND
        NOT a.nomer_ab =
            SOME
            (
                SELECT
                    s.nomer_ab
                FROM
                    sertificat AS s
                WHERE
                    s.n_predmet = 4
            ) 
    AND
        a.nomer_ab = :nomer
```