SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        kol_priv
        (
            in_fac     INTEGER,
            in_vid_edu INTEGER,
            in_konkurs INTEGER,
            in_price   INTEGER
        )
    RETURNS
        (
            sum_without INTEGER,
            sum_v_k     INTEGER
        )
AS
    DECLARE 
        VARIABLE s_without VARCHAR (10);
    DECLARE 
        VARIABLE s_v_k     VARCHAR (10);
BEGIN
    sum_without = 0;
    sum_v_k     = 0;

    FOR
        SELECT
            a.without,
            a.v_k
        FROM
            abitura AS a
        WHERE
                a.n_fac   =  :in_fac
            AND
                a.vid_edu =  :in_vid_edu
            AND
                a.konkurs =  :in_konkurs
            AND
                a.price   =  :in_price
            AND
                a.status  IN (0)
        INTO
            :s_without,
            :s_v_k
    DO
        BEGIN
            IF (s_without != "")
            THEN
                sum_without = sum_without + 1;
            ELSE
                IF (s_v_k != "")
                THEN
                    sum_v_k = sum_v_k + 1;
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
        kol_priv;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE kol_priv TO abitur1;
GRANT EXECUTE ON PROCEDURE kol_priv TO abitur2;
GRANT EXECUTE ON PROCEDURE kol_priv TO abitur3;
GRANT EXECUTE ON PROCEDURE kol_priv TO abitur4;
GRANT EXECUTE ON PROCEDURE kol_priv TO abitura;
GRANT EXECUTE ON PROCEDURE kol_priv TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE kol_priv TO asu;
GRANT EXECUTE ON PROCEDURE kol_priv TO asu1;
GRANT EXECUTE ON PROCEDURE kol_priv TO asu2;
GRANT EXECUTE ON PROCEDURE kol_priv TO asu3;
GRANT EXECUTE ON PROCEDURE kol_priv TO asu4;
GRANT EXECUTE ON PROCEDURE kol_priv TO developer;
GRANT EXECUTE ON PROCEDURE kol_priv TO developer2;
GRANT EXECUTE ON PROCEDURE kol_priv TO ivanova_a;
GRANT EXECUTE ON PROCEDURE kol_priv TO oksana;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_it;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_it1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_it2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_it3;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_it4;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_it5;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvs;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_otv1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_otv2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_otv3;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_otv4;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siie;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siie1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siie2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siie3;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siie4;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siie5;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE kol_priv TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE kol_priv TO sysdba;