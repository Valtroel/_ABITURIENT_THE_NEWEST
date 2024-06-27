# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDQuery](TDFQuery.md) > *QGIACYearSredSpec*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

```sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu         =  :vid_edu
    AND
        a.status          =  0
    AND
        a.education       =  :education 
    AND
        a.when_edu_middle =  :year
    AND
        a.konkurs         <> 5
```