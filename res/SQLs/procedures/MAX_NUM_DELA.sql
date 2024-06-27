SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        max_num_dela
        (
            n_fac    SMALLINT,
            vid_edu  SMALLINT,
            term_edu SMALLINT,
            price    SMALLINT
        )
    RETURNS
        (
            mx_num_dela INTEGER
        )
AS
BEGIN
    IF  (
             :term_edu = 1
          OR
             :term_edu = 2
          OR
             :term_edu = 4
          OR
             :term_edu = 5
        )
    THEN
        BEGIN
            SELECT
                MAX
                (
                    a.nom_dela
                )
            FROM
                abitur_logbook AS a
            WHERE
                    a.n_fac   = :n_fac
                AND
                    a.vid_edu = :vid_edu
                AND
                    a.price   = :price
                AND
                    (
                          a.term_edu = 1
                      OR
                          a.term_edu = 2
                      OR
                          a.term_edu = 4
                      OR
                          a.term_edu = 5
                    )
            INTO
                :mx_num_dela;
        END
    ELSE
        BEGIN
            SELECT
                MAX
                (
                    a.nom_dela
                )
            FROM
                abitur_logbook AS a
            WHERE
                    a.n_fac   = :n_fac
                AND
                    a.vid_edu = :vid_edu
                AND
                    a.price   = :price
                AND
                    (   
                         a.term_edu = 0
                      OR
                         a.term_edu = 3
                    )
            INTO
                :mx_num_dela;
        END
    SUSPEND;
END^

SET TERM ; ^

/* Following GRANT statements are generated automatically */

GRANT
    SELECT
ON
    abitur_logbook
TO
    PROCEDURE
        max_num_dela;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE max_num_dela TO abitur1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO abitur2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO abitur3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO abitur4;
GRANT EXECUTE ON PROCEDURE max_num_dela TO abitura;
GRANT EXECUTE ON PROCEDURE max_num_dela TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE max_num_dela TO asu;
GRANT EXECUTE ON PROCEDURE max_num_dela TO asu1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO asu2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO asu3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO asu4;
GRANT EXECUTE ON PROCEDURE max_num_dela TO developer;
GRANT EXECUTE ON PROCEDURE max_num_dela TO ivanova_a;
GRANT EXECUTE ON PROCEDURE max_num_dela TO oksana;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_it;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_it1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_it2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_it3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_it4;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_it5;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvs;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_otv1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_otv2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_otv3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_otv4;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siie;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siie1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siie2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siie3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siie4;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siie5;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE max_num_dela TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE max_num_dela TO sysdba;