# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QStreet*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    s.id,
    s.name_in_rus
FROM
    street AS s 
WHERE
        s.type_street = :type_street
    AND
        s.id_locality = :id_locality
ORDER BY
    s.name_in_rus
```