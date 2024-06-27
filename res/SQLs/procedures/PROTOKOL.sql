
SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE 
        protokol
        (
            in_n_fac    SMALLINT,
            in_data     DATE,
            in_vid_edu  SMALLINT,
            in_konk     SMALLINT,
            in_price    SMALLINT
        )
    RETURNS
        (
            out_fam     VARCHAR (30),
            out_name    VARCHAR (30),
            out_otch    VARCHAR (30),
            out_n_del   SMALLINT,
            out_vk      VARCHAR (5),
            out_without VARCHAR (5)
        )
AS
BEGIN
    FOR
        SELECT
            DISTINCT
                a.fam,
                a.name,
                a.otch,
                a.nom_dela,
                a.v_k,
                a.without
        FROM
            abitura AS a
        WHERE
                a.n_fac      = :in_n_fac
            AND
                a.status     = 0
            AND
                a.konkurs    = :in_konk
            AND
                a.vid_edu    = :in_vid_edu
            AND
                a.date_priem = :in_data
            AND
                a.price      = :in_price
        ORDER BY
            a.nom_dela
        INTO
            :out_fam,
            :out_name,
            :out_otch,
            :out_n_del,
            :out_vk,
            :out_without
    DO
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
        protokol;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE protokol TO abitur1;
GRANT EXECUTE ON PROCEDURE protokol TO abitur2;
GRANT EXECUTE ON PROCEDURE protokol TO abitur3;
GRANT EXECUTE ON PROCEDURE protokol TO abitur4;
GRANT EXECUTE ON PROCEDURE protokol TO abitura;
GRANT EXECUTE ON PROCEDURE protokol TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE protokol TO asu;
GRANT EXECUTE ON PROCEDURE protokol TO asu1;
GRANT EXECUTE ON PROCEDURE protokol TO asu2;
GRANT EXECUTE ON PROCEDURE protokol TO asu3;
GRANT EXECUTE ON PROCEDURE protokol TO asu4;
GRANT EXECUTE ON PROCEDURE protokol TO developer;
GRANT EXECUTE ON PROCEDURE protokol TO developer2;
GRANT EXECUTE ON PROCEDURE protokol TO it1;
GRANT EXECUTE ON PROCEDURE protokol TO it2;
GRANT EXECUTE ON PROCEDURE protokol TO it3;
GRANT EXECUTE ON PROCEDURE protokol TO ivanova_a;
GRANT EXECUTE ON PROCEDURE protokol TO mvs1;
GRANT EXECUTE ON PROCEDURE protokol TO mvs2;
GRANT EXECUTE ON PROCEDURE protokol TO mvs3;
GRANT EXECUTE ON PROCEDURE protokol TO mvs4;
GRANT EXECUTE ON PROCEDURE protokol TO ofkit1;
GRANT EXECUTE ON PROCEDURE protokol TO ofkit2;
GRANT EXECUTE ON PROCEDURE protokol TO ofkit3;
GRANT EXECUTE ON PROCEDURE protokol TO ofkit4;
GRANT EXECUTE ON PROCEDURE protokol TO oksana;
GRANT EXECUTE ON PROCEDURE protokol TO pk;
GRANT EXECUTE ON PROCEDURE protokol TO pk_it;
GRANT EXECUTE ON PROCEDURE protokol TO pk_it1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_it2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_it3;
GRANT EXECUTE ON PROCEDURE protokol TO pk_it4;
GRANT EXECUTE ON PROCEDURE protokol TO pk_it5;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvs;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_otv1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_otv2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_otv3;
GRANT EXECUTE ON PROCEDURE protokol TO pk_otv4;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siie;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siie1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siie2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siie3;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siie4;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siie5;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE protokol TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE protokol TO siie1;
GRANT EXECUTE ON PROCEDURE protokol TO siie2;
GRANT EXECUTE ON PROCEDURE protokol TO siie3;
GRANT EXECUTE ON PROCEDURE protokol TO siie4;
GRANT EXECUTE ON PROCEDURE protokol TO sysdba;
GRANT EXECUTE ON PROCEDURE protokol TO uo_lab;
GRANT EXECUTE ON PROCEDURE protokol TO uo_n;
GRANT EXECUTE ON PROCEDURE protokol TO uo_z;