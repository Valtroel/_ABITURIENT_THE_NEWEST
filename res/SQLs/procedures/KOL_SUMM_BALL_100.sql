SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        kol_summ_ball_100
        (
            in_sp      INTEGER,
            in_vid_edu SMALLINT,
            konk       SMALLINT,
            price      SMALLINT
        )
    RETURNS
        (
            n100     INTEGER,    n100_110 INTEGER,    n110_120 INTEGER,    n120_130 INTEGER,    n130_140 INTEGER,
            n140_150 INTEGER,    n150_160 INTEGER,    n160_170 INTEGER,    n170_180 INTEGER,    n180_190 INTEGER,
            n190_200 INTEGER,    n200_210 INTEGER,    n210_220 INTEGER,    n220_230 INTEGER,    n230_240 INTEGER,
            n240_250 INTEGER,    n250_260 INTEGER,    n260_270 INTEGER,    n270_280 INTEGER,    n280_290 INTEGER,
            n290_300 INTEGER,    n300_310 INTEGER,    n310_320 INTEGER,    n320_330 INTEGER,    n330_340 INTEGER,
            n340_350 INTEGER,    n350_360 INTEGER,    n360_370 INTEGER,    n370_380 INTEGER,    n380_390 INTEGER,
            n390_400 INTEGER
        )
AS
    DECLARE
        VARIABLE s DOUBLE PRECISION;
BEGIN
    n100     = 0;    n100_110 = 0;    n110_120 = 0;    n120_130 = 0;    n130_140 = 0;
    n140_150 = 0;    n150_160 = 0;    n160_170 = 0;    n170_180 = 0;    n180_190 = 0;
    n190_200 = 0;    n200_210 = 0;    n210_220 = 0;    n220_230 = 0;    n230_240 = 0;
    n240_250 = 0;    n250_260 = 0;    n260_270 = 0;    n270_280 = 0;    n280_290 = 0;
    n290_300 = 0;    n300_310 = 0;    n310_320 = 0;    n320_330 = 0;    n330_340 = 0;
    n340_350 = 0;    n350_360 = 0;    n360_370 = 0;    n370_380 = 0;    n380_390 = 0;
    n390_400 = 0;

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


                WHEN (
                        a.sum_ball > 401
                     )
                THEN
                    a.sum_ball / 10
                ELSE
                    a.sum_ball
            END
                sum_ball
        FROM
            abitura AS a
        WHERE
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
            IF (s <  100 OR   s IS NULL) THEN n100     = n100     + 1;
            IF (s >= 100 AND  s <= 110 ) THEN n100_110 = n100_110 + 1;
            IF (s >  110 AND  s <= 120 ) THEN n110_120 = n110_120 + 1;
            IF (s >  120 AND  s <= 130 ) THEN n120_130 = n120_130 + 1;
            IF (s >  130 AND  s <= 140 ) THEN n130_140 = n130_140 + 1;
            IF (s >  140 AND  s <= 150 ) THEN n140_150 = n140_150 + 1;
            IF (s >  150 AND  s <= 160 ) THEN n150_160 = n150_160 + 1;
            IF (s >  160 AND  s <= 170 ) THEN n160_170 = n160_170 + 1;
            IF (s >  170 AND  s <= 180 ) THEN n170_180 = n170_180 + 1;
            IF (s >  180 AND  s <= 190 ) THEN n180_190 = n180_190 + 1;
            IF (s >  190 AND  s <= 200 ) THEN n190_200 = n190_200 + 1;
            IF (s >  200 AND  s <= 210 ) THEN n200_210 = n200_210 + 1;
            IF (s >  210 AND  s <= 220 ) THEN n210_220 = n210_220 + 1;
            IF (s >  220 AND  s <= 230 ) THEN n220_230 = n220_230 + 1;
            IF (s >  230 AND  s <= 240 ) THEN n230_240 = n230_240 + 1;
            IF (s >  240 AND  s <= 250 ) THEN n240_250 = n240_250 + 1;
            IF (s >  250 AND  s <= 260 ) THEN n250_260 = n250_260 + 1;
            IF (s >  260 AND  s <= 270 ) THEN n260_270 = n260_270 + 1;
            IF (s >  270 AND  s <= 280 ) THEN n270_280 = n270_280 + 1;
            IF (s >  280 AND  s <= 290 ) THEN n280_290 = n280_290 + 1;
            IF (s >  290 AND  s <= 300 ) THEN n290_300 = n290_300 + 1;
            IF (s >  300 AND  s <= 310 ) THEN n300_310 = n300_310 + 1;
            IF (s >  310 AND  s <= 320 ) THEN n310_320 = n310_320 + 1;
            IF (s >  320 AND  s <= 330 ) THEN n320_330 = n320_330 + 1;
            IF (s >  330 AND  s <= 340 ) THEN n330_340 = n330_340 + 1;
            IF (s >  340 AND  s <= 350 ) THEN n340_350 = n340_350 + 1;
            IF (s >  350 AND  s <= 360 ) THEN n350_360 = n350_360 + 1;
            IF (s >  360 AND  s <= 370 ) THEN n360_370 = n360_370 + 1;
            IF (s >  370 AND  s <= 380 ) THEN n370_380 = n370_380 + 1;
            IF (s >  380 AND  s <= 390 ) THEN n380_390 = n380_390 + 1;
            IF (s >  390 AND  s <= 400 ) THEN n390_400 = n390_400 + 1;
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
        kol_summ_ball_100;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO abitur1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO abitur2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO abitur3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO abitur4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO abitura;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO asu;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO asu1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO asu2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO asu3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO asu4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO developer;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO developer2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO it1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO it2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO it3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO ivanova_a;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO mvs1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO mvs2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO mvs3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO mvs4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO ofkit1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO ofkit2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO ofkit3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO ofkit4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO oksana;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_it;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_it1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_it2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_it3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_it4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_it5;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvs;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_otv1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_otv2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_otv3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_otv4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siie;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siie1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siie2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siie3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siie4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siie5;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO siie1;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO siie2;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO siie3;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO siie4;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO sysdba;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO uo_lab;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO uo_n;
GRANT EXECUTE ON PROCEDURE kol_summ_ball_100 TO uo_z;