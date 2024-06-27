# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QIP*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    i.n_ip,
    i.ip,
    i.ip_name,
    i.gruppa,
    i.program,
    i.flag
FROM
    ip AS i
WHERE
        i.program = 6
    AND
        i.flag    = 1
    AND
        i.ip      = :ip_n
```