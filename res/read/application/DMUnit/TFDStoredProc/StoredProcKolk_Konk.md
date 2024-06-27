# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDStoredProc](TFDStoredProc.md) > *StoredProcKolk_Konk*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

## CertificLogDelStrdPrc -> **certificates_logbook_del**

```xml
<object
    Name           = 'CertificLogDelStrdPrc'
    DataType       = 'TFDStoredProc'
    CachedUpdates  = true
    Connection     = 'FDConnection2'
    StoredProcName = 'CERTIFICATES_LOGBOOK_DEL'
>
    <ParamData>
        <item
            Name      = 'ID_LOG'
            DataType  = 'Integer'
            ParamType = 'Input'
        />
    </ParamData>
</object>
```

### Params > TFDConnectionDefParams

|         *Name* |        *Param*       |
|---------------:|:--------------------:|
| *CharacterSet* |    **csWIN1251**     |
|  *CharLenMode* |       clmChars       |
|     *Database* |    **abiturient**    |
|     *DriverID* |        **FB**        |
|     *PageSize* |       *ps4096*       |
|     *Password* |   **dbudfV544703**   |
|     *Protocol* |       ipTCPIP        |
|       *Server* |    **172.16.1.30**   |
|   *SQLDialect* |        **1**         |
|     *UserName* |     **developer**    |

---
</br>

```sql
SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        kol_konk
        (
            in_fac     SMALLINT,
            in_vid_edu SMALLINT,
            in_spec    SMALLINT
        )
    RETURNS
        (
            s_all_0 INTEGER,
            s_all_1 INTEGER,
            s_cel   INTEGER,
            s_2_0   INTEGER,
            s_2_1   INTEGER,
            s_vk_0  INTEGER,
            s_vk_1  INTEGER,
            s_wo_0  INTEGER,
            s_wo_1  INTEGER,
            s_ing   INTEGER
        )
AS
    DECLARE
        VARIABLE s  SMALLINT;
    DECLARE
        VARIABLE pr SMALLINT;
BEGIN
    s_all_0 = 0;    s_all_1 = 0;
    s_cel   = 0;    s_2_0   = 0;
    s_2_1   = 0;    s_vk_0  = 0;
    s_vk_1  = 0;    s_wo_0  = 0;
    s_wo_1  = 0;    s_ing   = 0;
  
    FOR
        SELECT
            a.konkurs,
            a.price
        FROM 
            abitura AS a
        WHERE
                a.vid_edu     = :in_vid_edu
            AND
                a.status      = 0
            AND
                a.n_fac       = :in_fac
            AND
                a.n_specializ = :in_spec
        INTO
            :s,
            :pr
    DO
        BEGIN
            IF (pr = 0) /* бюджет */
            THEN
                BEGIN 
                    IF (s = 0) THEN s_all_0 = s_all_0 + 1;  /* общий */
                    IF (s = 1) THEN s_cel   = s_cel   + 1;  /* целевой */
                    IF (s = 2) THEN s_2_0   = s_2_0   + 1;  /* на 2-3 курс (убран в 2017) */
                    IF (s = 3) THEN s_vk_0  = s_vk_0  + 1;  /* вне конкурса */
                    IF (s = 4) THEN s_wo_0  = s_wo_0  + 1;  /* без экзаменов */
                END
            ELSE        /* платники */
                BEGIN 
                    IF (s = 0) THEN s_all_1 = s_all_1 + 1;  /* общий */
                    IF (s = 2) THEN s_2_1   = s_2_1   + 1;  /* на 2-3 курс (убран в 2017) */
                    IF (s = 3) THEN s_vk_1  = s_vk_1  + 1;  /* вне конкурса  */
                    IF (s = 4) THEN s_wo_1  = s_wo_1  + 1;  /* без экзаменов */
                    IF (s = 5) THEN s_ing   = s_ing   + 1;  /* иностранцы (убран в 2017) */
                END
        END 
    SUSPEND;
END^

SET TERM ; ^
```

---
</br>

### Grant statements

```sql
GRANT
    SELECT
ON
    abitura
TO
    PROCEDURE
        kol_konk;
```

---
</br>

### List of users who have privileges

```sql
GRANT EXECUTE ON PROCEDURE kol_konk TO abitur1;
GRANT EXECUTE ON PROCEDURE kol_konk TO abitur2;
GRANT EXECUTE ON PROCEDURE kol_konk TO abitur3;
GRANT EXECUTE ON PROCEDURE kol_konk TO abitur4;
GRANT EXECUTE ON PROCEDURE kol_konk TO abitura;
GRANT EXECUTE ON PROCEDURE kol_konk TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE kol_konk TO asu;
GRANT EXECUTE ON PROCEDURE kol_konk TO asu1;
GRANT EXECUTE ON PROCEDURE kol_konk TO asu2;
GRANT EXECUTE ON PROCEDURE kol_konk TO asu3;
GRANT EXECUTE ON PROCEDURE kol_konk TO asu4;
GRANT EXECUTE ON PROCEDURE kol_konk TO developer;
GRANT EXECUTE ON PROCEDURE kol_konk TO developer2;
GRANT EXECUTE ON PROCEDURE kol_konk TO ivanova_a;
GRANT EXECUTE ON PROCEDURE kol_konk TO oksana;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_it;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_it1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_it2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_it3;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_it4;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_it5;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvs;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_otv1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_otv2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_otv3;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_otv4;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siie;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siie1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siie2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siie3;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siie4;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siie5;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE kol_konk TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE kol_konk TO sysdba;
```