# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDStoredProc](TFDStoredProc.md) > *RaspredBall34StrdPrc*

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
        kol_summ_ball4
        (
            n_fac   SMALLINT,
            vid_edu SMALLINT,
            price   SMALLINT,
            n_sp    SMALLINT
        )
    RETURNS
        (
            n1_2   SMALLINT,    n2_3   SMALLINT,    n3_4   SMALLINT,    n4_5   SMALLINT,    n5_6   SMALLINT,
            n6_7   SMALLINT,    n7_8   SMALLINT,    n8_9   SMALLINT,    n9_10  SMALLINT,    n10_11 SMALLINT,
            n11_12 SMALLINT,    n12_13 SMALLINT,    n13_14 SMALLINT,    n14_15 SMALLINT,    n15_16 SMALLINT,
            n16_17 SMALLINT,    n17_18 SMALLINT,    n18_19 SMALLINT,    n19_20 SMALLINT,    n20_21 SMALLINT,
            n21_22 SMALLINT,    n22_23 SMALLINT,    n23_24 SMALLINT,    n24_25 SMALLINT,    n25_26 SMALLINT,
            n26_27 SMALLINT,    n27_28 SMALLINT,    n28_29 SMALLINT,    n29_30 SMALLINT,    n30_31 SMALLINT,
            n31_32 SMALLINT,    n32_33 SMALLINT,    n33_34 SMALLINT,    n34_35 SMALLINT,    n35_36 SMALLINT,
            n36_37 SMALLINT,    n37_38 SMALLINT,    n38_39 SMALLINT,    n39_40 SMALLINT,    n40_41 SMALLINT,
            n41_42 SMALLINT,    n42_43 SMALLINT,    n43_44 SMALLINT,    n44_45 SMALLINT,    n45_46 SMALLINT,
            n46_47 SMALLINT,    n47_48 SMALLINT,    n48_49 SMALLINT,    n49_50 SMALLINT,    n50_51 SMALLINT,
            n51_52 SMALLINT,    n52_53 SMALLINT,    n53_54 SMALLINT,    n54_55 SMALLINT,    n55_56 SMALLINT,
            n56_57 SMALLINT,    n57_58 SMALLINT,    n58_59 SMALLINT,    n59_60 SMALLINT,    n60_61 SMALLINT,
            n61_62 SMALLINT,    n62_63 SMALLINT,    n63_64 SMALLINT,    n64_65 SMALLINT,    n65_66 SMALLINT,
            n66_67 SMALLINT,    n67_68 SMALLINT,    n68_69 SMALLINT,    n69_70 SMALLINT,    n70_71 SMALLINT,
            n71_72 SMALLINT,    n72_73 SMALLINT,    n73_74 SMALLINT,    n74_75 SMALLINT,    n75_76 SMALLINT
        )
AS
    DECLARE
        VARIABLE s INTEGER;
BEGIN
    n1_2   = 0;    n2_3   = 0;    n3_4   = 0;    n4_5   = 0;    n5_6   = 0;
    n6_7   = 0;    n7_8   = 0;    n8_9   = 0;    n9_10  = 0;    n10_11 = 0;
    n11_12 = 0;    n12_13 = 0;    n13_14 = 0;    n14_15 = 0;    n15_16 = 0;
    n16_17 = 0;    n17_18 = 0;    n18_19 = 0;    n19_20 = 0;    n20_21 = 0;
    n21_22 = 0;    n22_23 = 0;    n23_24 = 0;    n24_25 = 0;    n25_26 = 0;
    n26_27 = 0;    n27_28 = 0;    n28_29 = 0;    n29_30 = 0;    n30_31 = 0;
    n31_32 = 0;    n32_33 = 0;    n33_34 = 0;    n34_35 = 0;    n35_36 = 0;
    n36_37 = 0;    n37_38 = 0;    n38_39 = 0;    n39_40 = 0;    n40_41 = 0;
    n41_42 = 0;    n42_43 = 0;    n43_44 = 0;    n44_45 = 0;    n45_46 = 0;
    n46_47 = 0;    n47_48 = 0;    n48_49 = 0;    n49_50 = 0;    n50_51 = 0;
    n51_52 = 0;    n52_53 = 0;    n53_54 = 0;    n54_55 = 0;    n55_56 = 0;
    n56_57 = 0;    n57_58 = 0;    n58_59 = 0;    n59_60 = 0;    n60_61 = 0;
    n61_62 = 0;    n62_63 = 0;    n63_64 = 0;    n64_65 = 0;    n65_66 = 0;
    n66_67 = 0;    n67_68 = 0;    n68_69 = 0;    n69_70 = 0;    n70_71 = 0;
    n71_72 = 0;    n72_73 = 0;    n73_74 = 0;    n74_75 = 0;    n75_76 = 0;  

    FOR
        SELECT
            CASE 
                WHEN (
                          a.sum_ball IS NULL
                       OR
                          a.sum_ball IN (0)
                     )
                THEN
                    a.middle_ball
                ELSE
                    a.sum_ball
            END
                SUM_BALL
        FROM
            abitura AS a
        WHERE
                a.n_fac       =  :n_fac
            AND a.vid_edu     =  :vid_edu
            AND a.status      IN (0)
            AND a.term_edu    IN (1, 2)
            AND a.price       =  :price
            AND a.n_specializ =  :n_sp
            AND a.category_if IN (0)
            AND a.konkurs     =  0
        INTO
            :s
    DO
        BEGIN
            IF (s <= 30)               THEN n1_2   = n1_2   + 1;
            IF (s >  30  AND s <= 35)  THEN n2_3   = n2_3   + 1;
            IF (s >  35  AND s <= 40)  THEN n3_4   = n3_4   + 1;
            IF (s >  40  AND s <= 45)  THEN n4_5   = n4_5   + 1;
            IF (s >  45  AND s <= 50)  THEN n5_6   = n5_6   + 1;
            IF (s >  50  AND s <= 55)  THEN n6_7   = n6_7   + 1;
            IF (s >  55  AND s <= 60)  THEN n7_8   = n7_8   + 1;
            IF (s >  60  AND s <= 65)  THEN n8_9   = n8_9   + 1;
            IF (s >  65  AND s <= 70)  THEN n9_10  = n9_10  + 1;
            IF (s >  70  AND s <= 75)  THEN n10_11 = n10_11 + 1;
            IF (s >  75  AND s <= 80)  THEN n11_12 = n11_12 + 1;
            IF (s >  80  AND s <= 85)  THEN n12_13 = n12_13 + 1;
            IF (s >  85  AND s <= 90)  THEN n13_14 = n13_14 + 1;
            IF (s >  90  AND s <= 95)  THEN n14_15 = n14_15 + 1;
            IF (s >  95  AND s <= 100) THEN n15_16 = n15_16 + 1;
            IF (s >  100 AND s <= 105) THEN n16_17 = n16_17 + 1;
            IF (s >  105 AND s <= 110) THEN n17_18 = n17_18 + 1;
            IF (s >  110 AND s <= 115) THEN n18_19 = n18_19 + 1;
            IF (s >  115 AND s <= 120) THEN n19_20 = n19_20 + 1;
            IF (s >  120 AND s <= 125) THEN n20_21 = n20_21 + 1;
            IF (s >  125 AND s <= 130) THEN n21_22 = n21_22 + 1;
            IF (s >  130 AND s <= 135) THEN n22_23 = n22_23 + 1;
            IF (s >  135 AND s <= 140) THEN n23_24 = n23_24 + 1;
            IF (s >  140 AND s <= 145) THEN n24_25 = n24_25 + 1;
            IF (s >  145 AND s <= 150) THEN n25_26 = n25_26 + 1;
            IF (s >  150 AND s <= 155) THEN n26_27 = n26_27 + 1;
            IF (s >  155 AND s <= 160) THEN n27_28 = n27_28 + 1;
            IF (s >  160 AND s <= 165) THEN n28_29 = n28_29 + 1;
            IF (s >  165 AND s <= 170) THEN n29_30 = n29_30 + 1;
            IF (s >  170 AND s <= 175) THEN n30_31 = n30_31 + 1;
            IF (s >  175 AND s <= 180) THEN n31_32 = n31_32 + 1;
            IF (s >  180 AND s <= 185) THEN n32_33 = n32_33 + 1;
            IF (s >  185 AND s <= 190) THEN n33_34 = n33_34 + 1;
            IF (s >  190 AND s <= 195) THEN n34_35 = n34_35 + 1;
            IF (s >  195 AND s <= 200) THEN n35_36 = n35_36 + 1;
            IF (s >  200 AND s <= 205) THEN n36_37 = n36_37 + 1;
            IF (s >  205 AND s <= 210) THEN n37_38 = n37_38 + 1;
            IF (s >  210 AND s <= 215) THEN n38_39 = n38_39 + 1;
            IF (s >  215 AND s <= 220) THEN n39_40 = n39_40 + 1;
            IF (s >  220 AND s <= 225) THEN n40_41 = n40_41 + 1;
            IF (s >  225 AND s <= 230) THEN n41_42 = n41_42 + 1;
            IF (s >  230 AND s <= 235) THEN n42_43 = n42_43 + 1;
            IF (s >  235 AND s <= 240) THEN n43_44 = n43_44 + 1;
            IF (s >  240 AND s <= 245) THEN n44_45 = n44_45 + 1;
            IF (s >  245 AND s <= 250) THEN n45_46 = n45_46 + 1;
            IF (s >  250 AND s <= 255) THEN n46_47 = n46_47 + 1;
            IF (s >  255 AND s <= 260) THEN n47_48 = n47_48 + 1;
            IF (s >  260 AND s <= 265) THEN n48_49 = n48_49 + 1;
            IF (s >  265 AND s <= 270) THEN n49_50 = n49_50 + 1;
            IF (s >  270 AND s <= 275) THEN n50_51 = n50_51 + 1;
            IF (s >  275 AND s <= 280) THEN n51_52 = n51_52 + 1;
            IF (s >  280 AND s <= 285) THEN n52_53 = n52_53 + 1;
            IF (s >  285 AND s <= 290) THEN n53_54 = n53_54 + 1;
            IF (s >  290 AND s <= 295) THEN n54_55 = n54_55 + 1;
            IF (s >  295 AND s <= 300) THEN n55_56 = n55_56 + 1;
            IF (s >  300 AND s <= 305) THEN n56_57 = n56_57 + 1;
            IF (s >  305 AND s <= 310) THEN n57_58 = n57_58 + 1;
            IF (s >  310 AND s <= 315) THEN n58_59 = n58_59 + 1;
            IF (s >  315 AND s <= 320) THEN n59_60 = n59_60 + 1;
            IF (s >  320 AND s <= 325) THEN n60_61 = n60_61 + 1;
            IF (s >  325 AND s <= 330) THEN n61_62 = n61_62 + 1;
            IF (s >  330 AND s <= 335) THEN n62_63 = n62_63 + 1;
            IF (s >  335 AND s <= 340) THEN n63_64 = n63_64 + 1;
            IF (s >  340 AND s <= 345) THEN n64_65 = n64_65 + 1;
            IF (s >  345 AND s <= 350) THEN n65_66 = n65_66 + 1;
            IF (s >  350 AND s <= 355) THEN n66_67 = n66_67 + 1;
            IF (s >  355 AND s <= 360) THEN n67_68 = n67_68 + 1;
            IF (s >  360 AND s <= 365) THEN n68_69 = n68_69 + 1;
            IF (s >  365 AND s <= 370) THEN n69_70 = n69_70 + 1;
            IF (s >  370 AND s <= 375) THEN n70_71 = n70_71 + 1;
            IF (s >  375 AND s <= 380) THEN n71_72 = n71_72 + 1;
            IF (s >  380 AND s <= 385) THEN n72_73 = n72_73 + 1;
            IF (s >  385 AND s <= 390) THEN n73_74 = n73_74 + 1;
            IF (s >  390 AND s <= 395) THEN n74_75 = n74_75 + 1;
            IF (s >  395)              THEN n75_76 = n75_76 + 1;
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
        kol_summ_ball4;
```

---
</br>

### List of users who have privileges

```sql
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO abitur1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO abitur2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO abitur3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO abitur4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO abitura;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO asu;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO asu1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO asu2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO asu3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO asu4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO developer;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO ivanova_a;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO oksana;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_it;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_it1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_it2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_it3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_it4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_it5;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvs;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_otv1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_otv2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_otv3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_otv4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siie;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siie1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siie2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siie3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siie4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siie5;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball4 TO sysdba;
```