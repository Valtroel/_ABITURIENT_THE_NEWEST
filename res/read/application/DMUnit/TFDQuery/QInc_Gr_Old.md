# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QInc_Gr_Old*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
-- FDConnection1 - Decanat
SELECT
    i.inc_gr_old,
    i.inc_group,
    i.n_group,
    i.vid_edu,
    i.god,
    i.describe
FROM
    inc_group_old AS i
```