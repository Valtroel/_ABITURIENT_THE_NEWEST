SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        get_nomer_ab
    RETURNS
        (
            nab INTEGER
        )
AS
BEGIN
    nab = GEN_ID (abitura_nomer_ab, 1);
END^

SET TERM ; ^

/* Following GRANT statements are generated automatically */

GRANT
    USAGE
ON
    SEQUENCE
        abitura_nomer_ab
TO
    PROCEDURE
        get_nomer_ab;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE get_nomer_ab TO abitur1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO abitur2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO abitur3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO abitur4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO abitura;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO asu;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO asu1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO asu2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO asu3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO asu4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO developer;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO developer2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO it1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO it2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO it3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO ivanova_a;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO mvs1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO mvs2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO mvs3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO mvs4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO ofkit1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO ofkit2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO ofkit3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO ofkit4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO oksana;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_it;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_it1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_it2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_it3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_it4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_it5;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvs;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_otv1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_otv2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_otv3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_otv4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siie;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siie1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siie2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siie3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siie4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siie5;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siiep3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO siie1;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO siie2;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO siie3;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO siie4;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO sysdba;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO uo_lab;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO uo_n;
GRANT EXECUTE ON PROCEDURE get_nomer_ab TO uo_z;