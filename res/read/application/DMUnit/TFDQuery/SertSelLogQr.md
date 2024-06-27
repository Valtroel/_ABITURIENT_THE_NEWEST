# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *SertSelLogQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    p.text_predmet,
    s.seria_s,
    s.nomer_s,
    s.rus_bel,
    s.balls
FROM
    sertificat AS s,
    predmet AS p
WHERE
        p.n_predmet = s.n_predmet
    AND
        s.nomer_ab = :nomer_ab
ORDER BY
    s.rus_bel
```