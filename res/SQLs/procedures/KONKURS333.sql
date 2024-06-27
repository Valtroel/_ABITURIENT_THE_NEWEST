SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        konkurs333
        (
            in_sp      SMALLINT,
            in_vid_edu SMALLINT,
            in_konk    SMALLINT,
            in_price   SMALLINT
        )
    RETURNS
        (
            out_nomer_ab        INTEGER,
            out_n_dela          INTEGER,
            out_date_r          DATE,
            out_pol             CHAR (1),
            out_name_edu_middle VARCHAR (50),
            out_when_edu_middle SMALLINT,
            out_name_edu_spec   VARCHAR (50),
            out_when_edu_spec   SMALLINT,
            out_stag            DOUBLE PRECISION,
            out_stag_spec       DOUBLE PRECISION,
            out_sport_category  VARCHAR (50),
            out_middle_ball     DOUBLE PRECISION,
            out_sum_ball        DOUBLE PRECISION,
            out_address_before  VARCHAR (100),
            out_konkurs         SMALLINT,
            out_n_ck            SMALLINT,
            out_term_edu        SMALLINT,
            out_category_ab     SMALLINT,
            out_fio             VARCHAR (90)
        )
AS
BEGIN
    FOR
        SELECT
            a.nomer_ab,
            a.nom_dela,
            a.date_r,
            a.pol,
            a.name_edu_middle,
            a.when_edu_middle,
            a.name_edu_spec,
            a.when_edu_spec,
            a.stag,
            a.stag_spec,
            c.sport_category,
            a.middle_ball,
            a.sum_ball,
            a.address_before,
            a.konkurs,
            a.n_ck,
            a.term_edu,
            a.category_ab,
            IIF ( a.otch IS NULL,
                    a.fam || ' ' || a.name,
                    a.fam || ' ' || a.name || ' ' || a.otch
                ) fio
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
                a.status      = 5
            AND
                a.category_if = 0
            AND
                (
                    a.term_edu = 0
                 OR
                    a.term_edu = 3
                )
        ORDER BY
            a.sum_ball    DESC,
            a.middle_ball DESC
        INTO
            :out_nomer_ab,
            :out_n_dela,
            :out_date_r,
            :out_pol,
            :out_name_edu_middle,
            :out_when_edu_middle,
            :out_name_edu_spec,
            :out_when_edu_spec,
            :out_stag,
            :out_stag_spec,
            :out_sport_category,
            :out_middle_ball,
            :out_sum_ball,
            :out_address_before,
            :out_konkurs,
            :out_n_ck,
            :out_term_edu,
            :out_category_ab,
            :out_fio
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
        konkurs333;

GRANT
    SELECT
ON
    category
TO
    PROCEDURE
        konkurs333;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE konkurs333 TO abitur1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO abitur2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO abitur3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO abitur4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO abitura;
GRANT EXECUTE ON PROCEDURE konkurs333 TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE konkurs333 TO anna;
GRANT EXECUTE ON PROCEDURE konkurs333 TO aspirantura;
GRANT EXECUTE ON PROCEDURE konkurs333 TO asu;
GRANT EXECUTE ON PROCEDURE konkurs333 TO asu1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO asu2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO asu3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO asu4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO baks68878;
GRANT EXECUTE ON PROCEDURE konkurs333 TO dev;
GRANT EXECUTE ON PROCEDURE konkurs333 TO developer;
GRANT EXECUTE ON PROCEDURE konkurs333 TO developer2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO dobrovolskaya;
GRANT EXECUTE ON PROCEDURE konkurs333 TO dvoretskaya_k;
GRANT EXECUTE ON PROCEDURE konkurs333 TO gunich_oksana;
GRANT EXECUTE ON PROCEDURE konkurs333 TO imsit_z;
GRANT EXECUTE ON PROCEDURE konkurs333 TO it1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO it2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO it3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO it5;
GRANT EXECUTE ON PROCEDURE konkurs333 TO it7;
GRANT EXECUTE ON PROCEDURE konkurs333 TO it_8;
GRANT EXECUTE ON PROCEDURE konkurs333 TO it_z;
GRANT EXECUTE ON PROCEDURE konkurs333 TO ivanova_a;
GRANT EXECUTE ON PROCEDURE konkurs333 TO jkmuf2507;
GRANT EXECUTE ON PROCEDURE konkurs333 TO kand_m;
GRANT EXECUTE ON PROCEDURE konkurs333 TO kristina;
GRANT EXECUTE ON PROCEDURE konkurs333 TO lavrenova_v;
GRANT EXECUTE ON PROCEDURE konkurs333 TO lenausova;
GRANT EXECUTE ON PROCEDURE konkurs333 TO ltrfyfn2019;
GRANT EXECUTE ON PROCEDURE konkurs333 TO magistr;
GRANT EXECUTE ON PROCEDURE konkurs333 TO marina;
GRANT EXECUTE ON PROCEDURE konkurs333 TO matusevich;
GRANT EXECUTE ON PROCEDURE konkurs333 TO mvs1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO mvs2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO mvs3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO mvs4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO mvs_d;
GRANT EXECUTE ON PROCEDURE konkurs333 TO mvs_z;
GRANT EXECUTE ON PROCEDURE konkurs333 TO mvs_z_l;
GRANT EXECUTE ON PROCEDURE konkurs333 TO m_2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO ofkit1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO ofkit2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO ofkit3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO ofkit4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO ofkit_a;
GRANT EXECUTE ON PROCEDURE konkurs333 TO ofkit_d;
GRANT EXECUTE ON PROCEDURE konkurs333 TO ofkit_m;
GRANT EXECUTE ON PROCEDURE konkurs333 TO ofkit_n;
GRANT EXECUTE ON PROCEDURE konkurs333 TO oksana;
GRANT EXECUTE ON PROCEDURE konkurs333 TO ok_stud_1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_it;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_it1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_it2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_it3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_it4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_it5;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvs;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_otv1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_otv2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_otv3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_otv4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siie;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siie1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siie2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siie3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siie4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siie5;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO planida_e;
GRANT EXECUTE ON PROCEDURE konkurs333 TO public;
GRANT EXECUTE ON PROCEDURE konkurs333 TO sel_com;
GRANT EXECUTE ON PROCEDURE konkurs333 TO shmaenkova_m;
GRANT EXECUTE ON PROCEDURE konkurs333 TO shpakevich_p;
GRANT EXECUTE ON PROCEDURE konkurs333 TO siie1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO siie1234;
GRANT EXECUTE ON PROCEDURE konkurs333 TO siie2;
GRANT EXECUTE ON PROCEDURE konkurs333 TO siie3;
GRANT EXECUTE ON PROCEDURE konkurs333 TO siie4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO siie_z1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO stud_kadr1;
GRANT EXECUTE ON PROCEDURE konkurs333 TO stud_kadr4;
GRANT EXECUTE ON PROCEDURE konkurs333 TO sveta;
GRANT EXECUTE ON PROCEDURE konkurs333 TO sysdba;
GRANT EXECUTE ON PROCEDURE konkurs333 TO uo_lab;
GRANT EXECUTE ON PROCEDURE konkurs333 TO uo_n;
GRANT EXECUTE ON PROCEDURE konkurs333 TO uo_z;
GRANT EXECUTE ON PROCEDURE konkurs333 TO viewer_mob;
GRANT EXECUTE ON PROCEDURE konkurs333 TO vnuk;
GRANT EXECUTE ON PROCEDURE konkurs333 TO vorobei75;
GRANT EXECUTE ON PROCEDURE konkurs333 TO yauheni_hatsura;