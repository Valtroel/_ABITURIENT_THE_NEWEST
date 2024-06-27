SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        konkurs2
        (
            in_sp      SMALLINT,
            in_vid_edu SMALLINT,
            in_konk    SMALLINT,
            in_price   SMALLINT
        )
    RETURNS
        (
            out_nomer_ab INTEGER,
            out_sum_ball DOUBLE PRECISION,
            out_f        VARCHAR (30),
            out_n        VARCHAR (30),
            out_o        VARCHAR (30),
            out_n_delo   SMALLINT,
            out_date_r   DATE,
            out_pol      CHAR (1),
            out_name_e_m VARCHAR (50),
            out_name_e_s VARCHAR (50),
            out_when_e_m SMALLINT,
            out_when_e_s SMALLINT,
            out_stag     DOUBLE PRECISION,
            out_stag_sp  DOUBLE PRECISION,
            out_sport    VARCHAR (50),
            out_mid_b    DOUBLE PRECISION,
            out_address  VARCHAR (100),
            out_copy_at  SMALLINT,
            out_v_k      VARCHAR (5),
            out_priv     VARCHAR (50),
            out_without  VARCHAR (5),
            out_region   INTEGER,
            out_centre   INTEGER,
            out_fio      VARCHAR (90),
            out_n_ck     SMALLINT
        )
AS
BEGIN
    FOR
        SELECT
            a.nomer_ab,
            a.sum_ball,
            a.fam,
            a.name,
            a.otch,
            a.nom_dela,
            a.date_r,
            a.pol,
            a.name_edu_middle,
            a.name_edu_spec,
            a.when_edu_middle,
            a.when_edu_spec,
            a.stag,
            a.stag_spec,
            c.sport_category,
            a.middle_ball,
            a.address_before,
            a.copy_at,
            a.v_k,
            a.priv,
            a.without,
            a.n_region,
            a.n_centre,
            IIF ( a.otch IS NULL,
                    a.fam || ' ' || a.name,
                    a.fam || ' ' || a.name || ' ' || a.otch
                ) fio,
            a.n_ck
        FROM
            abitura AS a
                LEFT JOIN
                    category AS c
                        ON
                            a.n_sport_category = c.n_sport_category
        WHERE
                a.n_specializ = :in_sp
            AND
                a.vid_edu     = :in_vid_edu
            AND
                a.konkurs     = :in_konk
            AND
                a.price       = :in_price
            AND
                a.status      = 0
        ORDER BY
            a.sum_ball    DESC,
            a.without,
            a.v_k,
            a.priv,
            a.middle_ball DESC
        INTO
            :out_nomer_ab,
            :out_sum_ball,
            :out_f,
            :out_n,
            :out_o,
            :out_n_delo,
            :out_date_r,
            :out_pol,
            :out_name_e_m,
            :out_name_e_s,
            :out_when_e_m,
            :out_when_e_s,
            :out_stag,
            :out_stag_sp,
            :out_sport,
            :out_mid_b,
            :out_address,
            :out_copy_at,
            :out_v_k,
            :out_priv,
            :out_without,
            :out_region,
            :out_centre,
            :out_fio,
            :out_n_ck
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
        konkurs2;


GRANT
    SELECT
ON
    category
TO
    PROCEDURE
        konkurs2;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE konkurs2 TO abitur1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO abitur2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO abitur3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO abitur4;
GRANT EXECUTE ON PROCEDURE konkurs2 TO abitura;
GRANT EXECUTE ON PROCEDURE konkurs2 TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE konkurs2 TO asu;
GRANT EXECUTE ON PROCEDURE konkurs2 TO asu1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO asu2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO asu3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO asu4;
GRANT EXECUTE ON PROCEDURE konkurs2 TO developer;
GRANT EXECUTE ON PROCEDURE konkurs2 TO developer2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO ivanova_a;
GRANT EXECUTE ON PROCEDURE konkurs2 TO oksana;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_it;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_it1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_it2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_it3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_it4;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_it5;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvs;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_otv1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_otv2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_otv3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_otv4;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siie;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siie1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siie2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siie3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siie4;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siie5;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE konkurs2 TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE konkurs2 TO sysdba;