# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QFindAbiturExerc*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    e.id_sel_exerc,
    e.id_exerc
FROM
    sel_exercize AS e
WHERE
        e.nomer_ab      = :nomer_ab
    AND
        e.num_exerc_grp = :num_exerc_grp
```