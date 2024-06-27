# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QShkala*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    s.ball,
    s.inc_shkala,
    s.rus_bel
FROM
    shkala AS s
WHERE
        s.n_predmet =  :n_pr
    AND
        s.max_ball  >= :n_ball
    AND
        s.min_ball  <= :n_balls
```