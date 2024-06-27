SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        kol_summ_ball
        (
            in_fac     INTEGER,
            in_sp      INTEGER,
            in_vid_edu SMALLINT,
            konk       SMALLINT,
            price      SMALLINT
        )
    RETURNS
        (
            n9     INTEGER,    n9_10  INTEGER,    n10_11 INTEGER,    n11_12 INTEGER,    n12_13 INTEGER,
            n13_14 INTEGER,    n14_15 INTEGER,    n15_16 INTEGER,    n16_17 INTEGER,    n17_18 INTEGER,
            n18_19 INTEGER,    n19_20 INTEGER,    n20_21 INTEGER,    n21_22 INTEGER,    n22_23 INTEGER,
            n23_24 INTEGER,    n24_25 INTEGER,    n25_26 INTEGER,    n26_27 INTEGER,    n27_28 INTEGER,
            n28_29 INTEGER,    n29_30 INTEGER,    n30_31 INTEGER,    n31_32 INTEGER,    n32_33 INTEGER,
            n33_34 INTEGER,    n34_35 INTEGER,    n35_36 INTEGER,    n36_37 INTEGER,    n37_38 INTEGER,
            n38_39 INTEGER,    n39_40 INTEGER
        )
AS
    DECLARE
        VARIABLE s DOUBLE PRECISION;
BEGIN
    n9     = 0;    n9_10  = 0;    n10_11 = 0;    n11_12 = 0;    n12_13 = 0;
    n13_14 = 0;    n14_15 = 0;    n15_16 = 0;    n16_17 = 0;    n17_18 = 0;
    n18_19 = 0;    n19_20 = 0;    n20_21 = 0;    n21_22 = 0;    n22_23 = 0;
    n23_24 = 0;    n24_25 = 0;    n25_26 = 0;    n26_27 = 0;    n27_28 = 0;
    n28_29 = 0;    n29_30 = 0;    n30_31 = 0;    n31_32 = 0;    n32_33 = 0;
    n33_34 = 0;    n34_35 = 0;    n35_36 = 0;    n36_37 = 0;    n37_38 = 0;
    n38_39 = 0;    n39_40 = 0;

    FOR 
        SELECT
            a.sum_ball
        FROM
            abitura AS a
        WHERE
                a.n_fac       =  :in_fac
            AND
                a.n_specializ =  :in_sp
            AND
                a.vid_edu     =  :in_vid_edu 
            AND
                a.price       =  :price
            AND
                a.status      IN (0)
            AND
                a.konkurs     =  :konk
        INTO
            :s
    DO
        BEGIN 
              IF (s <  9  OR   s is NULL) THEN n9     = n9     + 1;
              IF (s >= 9  AND  s <= 10  ) THEN n9_10  = n9_10  + 1;
              IF (s >  10 AND  s <= 11  ) THEN n10_11 = n10_11 + 1;
              IF (s >  11 AND  s <= 12  ) THEN n11_12 = n11_12 + 1;
              IF (s >  12 AND  s <= 13  ) THEN n12_13 = n12_13 + 1;
              IF (s >  13 AND  s <= 14  ) THEN n13_14 = n13_14 + 1;
              IF (s >  14 AND  s <= 15  ) THEN n14_15 = n14_15 + 1;
              IF (s >  15 AND  s <= 16  ) THEN n15_16 = n15_16 + 1;
              IF (s >  16 AND  s <= 17  ) THEN n16_17 = n16_17 + 1;
              IF (s >  17 AND  s <= 18  ) THEN n17_18 = n17_18 + 1;
              IF (s >  18 AND  s <= 19  ) THEN n18_19 = n18_19 + 1;
              IF (s >  19 AND  s <= 20  ) THEN n19_20 = n19_20 + 1;
              IF (s >  20 AND  s <= 21  ) THEN n20_21 = n20_21 + 1;
              IF (s >  21 AND  s <= 22  ) THEN n21_22 = n21_22 + 1;
              IF (s >  22 AND  s <= 23  ) THEN n22_23 = n22_23 + 1;
              IF (s >  23 AND  s <= 24  ) THEN n23_24 = n23_24 + 1;
              IF (s >  24 AND  s <= 25  ) THEN n24_25 = n24_25 + 1;
              IF (s >  25 AND  s <= 26  ) THEN n25_26 = n25_26 + 1;
              IF (s >  26 AND  s <= 27  ) THEN n26_27 = n26_27 + 1;
              IF (s >  27 AND  s <= 28  ) THEN n27_28 = n27_28 + 1;
              IF (s >  28 AND  s <= 29  ) THEN n28_29 = n28_29 + 1;
              IF (s >  29 AND  s <= 30  ) THEN n29_30 = n29_30 + 1;
              IF (s >  30 AND  s <= 31  ) THEN n30_31 = n30_31 + 1;
              IF (s >  31 AND  s <= 32  ) THEN n31_32 = n31_32 + 1;
              IF (s >  32 AND  s <= 33  ) THEN n32_33 = n32_33 + 1;
              IF (s >  33 AND  s <= 34  ) THEN n33_34 = n33_34 + 1;
              IF (s >  34 AND  s <= 35  ) THEN n34_35 = n34_35 + 1;
              IF (s >  35 AND  s <= 36  ) THEN n35_36 = n35_36 + 1;
              IF (s >  36 AND  s <= 37  ) THEN n36_37 = n36_37 + 1;
              IF (s >  37 AND  s <= 38  ) THEN n37_38 = n37_38 + 1;
              IF (s >  38 AND  s <= 39  ) THEN n38_39 = n38_39 + 1;
              IF (s >  39 AND  s <= 40  ) THEN n39_40 = n39_40 + 1;
        END
    SUSPEND;
END^

SET TERM ; ^

/* Following GRANT statements are generated automatically */

GRANT
    SELECT
ON
    abitura
TO
    PROCEDURE
        kol_summ_ball;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE kol_summ_ball TO abitur1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO abitur2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO abitur3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO abitur4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO abitura;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO asu;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO asu1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO asu2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO asu3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO asu4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO developer;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO developer2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO it1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO it2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO it3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO ivanova_a;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO mvs1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO mvs2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO mvs3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO mvs4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO ofkit1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO ofkit2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO ofkit3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO ofkit4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO oksana;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_it;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_it1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_it2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_it3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_it4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_it5;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvs;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_otv1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_otv2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_otv3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_otv4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siie;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siie1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siie2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siie3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siie4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siie5;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO siie1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO siie2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO siie3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO siie4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO sysdba;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO uo_lab;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO uo_n;
GRANT EXECUTE ON PROCEDURE kol_summ_ball TO uo_z;