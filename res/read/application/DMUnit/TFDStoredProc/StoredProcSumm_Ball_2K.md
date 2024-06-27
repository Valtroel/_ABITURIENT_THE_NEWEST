# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDStoredProc](TFDStoredProc.md) > *StoredProcSumm_Ball_2K*

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
        koll_summ_ball2k
        (
            in_fac     INTEGER,
            in_vid_edu INTEGER,
            konk       SMALLINT,
            price      SMALLINT
        )
    RETURNS
        (
            n2_3   INTEGER,    n3_4   INTEGER,    n4_5   INTEGER,    n5_6   INTEGER,    n6_7   INTEGER,
            n7_8   INTEGER,    n8_9   INTEGER,    n9_10  INTEGER,    n10_11 INTEGER,    n11_12 INTEGER,
            n12_13 INTEGER,    n13_14 INTEGER,    n14_15 INTEGER,    n15_16 INTEGER,    n16_17 INTEGER,
            n17_18 INTEGER,    n18_19 INTEGER,    n19_20 INTEGER,    n20_21 INTEGER,    n21_22 INTEGER,
            n22_23 INTEGER,    n23_24 INTEGER,    n24_25 INTEGER,    n25_26 INTEGER,    n26_27 INTEGER,
            n27_28 INTEGER,    n28_29 INTEGER,    n29_30 INTEGER,    n30_31 INTEGER,    n31_32 INTEGER,
            n32_33 INTEGER,    n33_34 INTEGER,    n34_35 INTEGER,    n35_36 INTEGER,    n36_37 INTEGER,
            n37_38 INTEGER,    n38_39 INTEGER,    n39_40 INTEGER
        )
AS
    DECLARE
        VARIABLE s double precision;
BEGIN
    n2_3   = 0;    n3_4   = 0;    n4_5   = 0;    n5_6   = 0;    n6_7   = 0;
    n7_8   = 0;    n8_9   = 0;    n9_10  = 0;    n10_11 = 0;    n11_12 = 0;
    n12_13 = 0;    n13_14 = 0;    n14_15 = 0;    n15_16 = 0;    n16_17 = 0;
    n17_18 = 0;    n18_19 = 0;    n19_20 = 0;    n20_21 = 0;    n21_22 = 0;
    n22_23 = 0;    n23_24 = 0;    n24_25 = 0;    n25_26 = 0;    n26_27 = 0;
    n27_28 = 0;    n28_29 = 0;    n29_30 = 0;    n30_31 = 0;    n31_32 = 0;
    n32_33 = 0;    n33_34 = 0;    n34_35 = 0;    n35_36 = 0;    n36_37 = 0;
    n37_38 = 0;    n38_39 = 0;    n39_40 = 0;

    FOR
        SELECT
            CASE
                WHEN (
                          a.sum_ball IS NULL
                       OR
                          a.sum_ball =  0
                     )
                THEN
                    a.middle_ball
                ELSE
                    a.sum_ball
            END
                sum_ball
        FROM
            abitura AS a
        WHERE
                a.n_fac   =  :in_fac
            AND
                a.vid_edu =  :in_vid_edu
            AND
                a.price   =  :price
            AND
                a.status  IN (0)
            AND
                a.konkurs =  :konk
            AND
                a.v_k     IN ("") and abitura.without in ("")
        INTO
            :s
    DO
        BEGIN
            IF (s <= 30)               THEN n2_3   = n2_3   + 1;
            IF (s >  30  AND s <= 40)  THEN n3_4   = n3_4   + 1;
            IF (s >  40  AND s <= 50)  THEN n4_5   = n4_5   + 1;
            IF (s >  50  AND s <= 60)  THEN n5_6   = n5_6   + 1;
            IF (s >  60  AND s <= 70)  THEN n6_7   = n6_7   + 1;
            IF (s >  70  AND s <= 80)  THEN n7_8   = n7_8   + 1;
            IF (s >  80  AND s <= 90)  THEN n8_9   = n8_9   + 1;
            IF (s >  90  AND s <= 100) THEN n9_10  = n9_10  + 1;
            IF (s >  100 AND s <= 110) THEN n10_11 = n10_11 + 1;
            IF (s >  110 AND s <= 120) THEN n11_12 = n11_12 + 1;
            IF (s >  120 AND s <= 130) THEN n12_13 = n12_13 + 1;
            IF (s >  130 AND s <= 140) THEN n13_14 = n13_14 + 1;
            IF (s >  140 AND s <= 150) THEN n14_15 = n14_15 + 1;
            IF (s >  150 AND s <= 160) THEN n15_16 = n15_16 + 1;
            IF (s >  160 AND s <= 170) THEN n16_17 = n16_17 + 1;
            IF (s >  170 AND s <= 180) THEN n17_18 = n17_18 + 1;
            IF (s >  180 AND s <= 190) THEN n18_19 = n18_19 + 1;
            IF (s >  190 AND s <= 200) THEN n19_20 = n19_20 + 1;
            IF (s >  200 AND s <= 210) THEN n20_21 = n20_21 + 1;
            IF (s >  210 AND s <= 220) THEN n21_22 = n21_22 + 1;
            IF (s >  220 AND s <= 230) THEN n22_23 = n22_23 + 1;
            IF (s >  230 AND s <= 240) THEN n23_24 = n23_24 + 1;
            IF (s >  240 AND s <= 250) THEN n24_25 = n24_25 + 1;
            IF (s >  250 AND s <= 260) THEN n25_26 = n25_26 + 1;
            IF (s >  260 AND s <= 270) THEN n26_27 = n26_27 + 1;
            IF (s >  270 AND s <= 280) THEN n27_28 = n27_28 + 1;
            IF (s >  280 AND s <= 290) THEN n28_29 = n28_29 + 1;
            IF (s >  290 AND s <= 300) THEN n29_30 = n29_30 + 1;
            IF (s >  300 AND s <= 310) THEN n30_31 = n30_31 + 1;
            IF (s >  310 AND s <= 320) THEN n31_32 = n31_32 + 1;
            IF (s >  320 AND s <= 330) THEN n32_33 = n32_33 + 1;
            IF (s >  330 AND s <= 340) THEN n33_34 = n33_34 + 1;
            IF (s >  340 AND s <= 350) THEN n34_35 = n34_35 + 1;
            IF (s >  350 AND s <= 360) THEN n35_36 = n35_36 + 1;
            IF (s >  360 AND s <= 370) THEN n36_37 = n36_37 + 1;
            IF (s >  370 AND s <= 380) THEN n37_38 = n37_38 + 1;
            IF (s >  380 AND s <= 390) THEN n38_39 = n38_39 + 1;
            IF (s >  390 AND s <= 400) THEN n39_40 = n39_40 + 1;
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
        koll_summ_ball2k;
```

---
</br>

### List of users who have privileges

```sql
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO abitur1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO abitur2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO abitur3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO abitur4;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO abitura;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO asu;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO asu1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO asu2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO asu3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO asu4;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO developer;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO developer2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO ivanova_a;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO oksana;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_it;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_it1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_it2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_it3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_it4;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_it5;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvs;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_otv1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_otv2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_otv3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_otv4;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siie;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siie1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siie2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siie3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siie4;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siie5;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE koll_summ_ball2k TO sysdba;
```