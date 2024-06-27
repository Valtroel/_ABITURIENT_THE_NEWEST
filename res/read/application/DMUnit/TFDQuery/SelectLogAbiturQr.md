# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *SelectLogAbiturQr*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    l.nom_dela,
    a.nomer_ab,
    a.fam,
    a.name,
    a.otch,
    a.citizenship,
    l.n_specializ,
    l.date_in,
    l.nom_dela,
    l.id_log,
    l.address_before,
    l.n_ck,
    a.d_prikaz_include,
    a.n_prikaz_include,
    l.date_out,
    l.konkurs,
    l.term_edu,
    l.category
FROM
    abitur_logbook AS l,
    abitura AS a
WHERE
        l.nomer_ab =  a.nomer_ab
    AND
        l.n_fac    =  :n_fac
    AND
        l.date_in  >= :date_in1
    AND
        l.date_in  <  :date_in2
    AND
        l.vid_edu  =  :vid_edu 
    AND
        (
             (
                  (
                       l.term_edu = 0
                    OR
                       l.term_edu = 3
                  )
              AND
                  :term_edu = 0
             )
         OR
             (
                  (
                       l.term_edu = 1
                    OR
                       l.term_edu = 2
                    OR
                       l.term_edu = 4
                    OR
                       l.term_edu = 5
                  )
              AND
                  :term_edu = 1
             )
        )
    AND
        l.price = :price
ORDER BY
    l.nom_dela
```