# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QRep_Sel_Exerc*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    s.num_exerc_grp,
    e.name_exerc
FROM
    sel_exercize AS s,
    exercise AS e
WHERE
        s.id_exerc = e.id_exerc
    AND
        s.nomer_ab = :nomer_ab
ORDER BY
    s.num_exerc_grp
```