# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QAdress*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    ds.name_district,
    tl.name_type,
    lc.name_locality,
    ts.type,
    ds.n_district,
    ds.n_region,
    tl.n_type,
    lc.id AS local_id,
    ts.id AS type_street
FROM
    district AS ds,
    (
        SELECT
            t_l.n_type,
            MIN
            (
                t_l.name_type
            ) AS name_type
        FROM
            type_locality AS t_l
        GROUP BY
            t_l.n_type
    ) AS tl,
    locality AS lc,
    type_street AS ts,
    street AS st
WHERE
        st.type_street   = ts.id
    AND
        st.id_locality   = lc.id
    AND
        lc.type_locality = tl.n_type
    AND
        lc.n_district    = ds.n_district
    AND
        st.id            = :id
```