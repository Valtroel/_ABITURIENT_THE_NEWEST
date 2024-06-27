# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QSertificat_Res*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.vid_edu,
    a.nom_group,
    a.n_fac,
    a.rus_bel,
    s.nomer_ab,
    s.n_predmet,
    s.seria_s,
    s.nomer_s,
    s.balls,
    s.describe
FROM
    abitura AS a
        INNER JOIN
            sertificat AS s
                ON
                    a.nomer_ab = s.nomer_ab
WHERE
        a.n_fac     = :fac
    AND
        a.nom_group = :gr
    AND
        s.n_predmet = :pr
```