SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        abitur_logbook_ins
        (
            nom_dela        SMALLINT,
            nomer_ab        INTEGER,
            date_in         DATE,
            vid_edu         SMALLINT,
            price           SMALLINT,
            term_edu        SMALLINT,
            address_before  VARCHAR (100),
            n_ck            SMALLINT,
            n_specializ     SMALLINT,
            n_fac           SMALLINT,
            konkurs         SMALLINT,
            category        SMALLINT
        )
AS
BEGIN
    INSERT INTO
        abitur_logbook
        (
            nom_dela,
            nomer_ab,
            date_in,
            vid_edu,
            price,
            term_edu,
            address_before,
            n_ck,
            n_specializ,
            n_fac,
            konkurs,
            category
        )
    VALUES
        (
            :nom_dela,
            :nomer_ab,
            :date_in,
            :vid_edu,
            :price,
            :term_edu,
            :address_before,
            :n_ck,
            :n_specializ,
            :n_fac,
            :konkurs,
            :category
        );
END^

SET TERM ; ^

/* Following GRANT statements are generated automatically */

GRANT
    INSERT
ON
    abitur_logbook
TO
    PROCEDURE
        abitur_logbook_ins;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO abitur1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO abitur2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO abitur3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO abitur4;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO abitura;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO asu;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO asu1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO asu2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO asu3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO asu4;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO developer;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO ivanova_a;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO oksana;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_it;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_it1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_it2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_it3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_it4;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_it5;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvs;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_otv1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_otv2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_otv3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_otv4;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siie;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siie1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siie2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siie3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siie4;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siie5;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO public;
GRANT EXECUTE ON PROCEDURE abitur_logbook_ins TO sysdba;