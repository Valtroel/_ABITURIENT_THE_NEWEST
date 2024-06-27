SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        predmet_ball
        (
            in_n_ab_ball INTEGER
        )
    RETURNS
        (
            out_n_predmet    SMALLINT,
            out_text_predmet VARCHAR (100),
            out_ball         DOUBLE PRECISION
        )
AS
BEGIN
    FOR
        SELECT
            p.text_predmet,
            e.ball,
            p.n_predmet
        FROM
            examen AS e
                INNER JOIN
                    predmet AS p
                        ON
                            e.n_predmet = p.n_predmet
        WHERE
            e.nomer_ab = :in_n_ab_ball
        ORDER BY
            p.text_predmet
        INTO
            :out_text_predmet,
            :out_ball,
            :out_n_predmet
    DO
    SUSPEND;
END^

SET TERM ; ^

/* Following GRANT statements are generated automatically */

GRANT
    SELECT
ON
    examen
TO
    PROCEDURE
        predmet_ball;

GRANT
    SELECT
ON
    predmet
TO
    PROCEDURE
        predmet_ball;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE predmet_ball TO abitur1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO abitur2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO abitur3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO abitur4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO abitura;
GRANT EXECUTE ON PROCEDURE predmet_ball TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE predmet_ball TO asu;
GRANT EXECUTE ON PROCEDURE predmet_ball TO asu1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO asu2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO asu3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO asu4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO developer;
GRANT EXECUTE ON PROCEDURE predmet_ball TO developer2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO it1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO it2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO it3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO ivanova_a;
GRANT EXECUTE ON PROCEDURE predmet_ball TO mvs1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO mvs2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO mvs3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO mvs4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO ofkit1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO ofkit2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO ofkit3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO ofkit4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO oksana;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_it;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_it1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_it2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_it3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_it4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_it5;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvs;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_otv1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_otv2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_otv3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_otv4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siie;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siie1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siie2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siie3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siie4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siie5;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO siie1;
GRANT EXECUTE ON PROCEDURE predmet_ball TO siie2;
GRANT EXECUTE ON PROCEDURE predmet_ball TO siie3;
GRANT EXECUTE ON PROCEDURE predmet_ball TO siie4;
GRANT EXECUTE ON PROCEDURE predmet_ball TO sysdba;
GRANT EXECUTE ON PROCEDURE predmet_ball TO uo_lab;
GRANT EXECUTE ON PROCEDURE predmet_ball TO uo_n;
GRANT EXECUTE ON PROCEDURE predmet_ball TO uo_z;