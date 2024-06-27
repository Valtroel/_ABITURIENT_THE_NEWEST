/* View: COMP_NOM */
CREATE OR ALTER
    VIEW
        COMP_NOM
        (
            NOMER_AB
        )
AS
    SELECT
        a.nomer_ab
    FROM
        abitura a,
        abitura b
    WHERE
            a.n_fac = b.n_fac
        AND 
            a.vid_edu = b.vid_edu
        AND 
            a.price = b.price
        AND 
            a.term_edu = b.term_edu
        AND 
            a.nom_dela = b.nom_dela
        AND 
            a.nomer_ab <> b.nomer_ab
        AND 
            a.status = 0
        AND 
            b.status = 0
;




/******************************************************************************/
/***                               Privileges                               ***/
/******************************************************************************/


/* Privileges of users */
GRANT ALL ON COMP_NOM TO ABITURA;
GRANT ALL ON COMP_NOM TO ALEXANDER_GONCHAROV;
GRANT ALL ON COMP_NOM TO IVANOVA_A;
GRANT ALL ON COMP_NOM TO OKSANA;
GRANT ALL ON COMP_NOM TO PK_MSTIG_1;
GRANT ALL ON COMP_NOM TO PK_MSTIG_2;
GRANT ALL ON COMP_NOM TO PK_MSTIG_3;
GRANT ALL ON COMP_NOM TO PK_MSTIG_4;
GRANT ALL ON COMP_NOM TO PK_MSTIG_P1;
GRANT ALL ON COMP_NOM TO PK_MSTIG_P2;
GRANT ALL ON COMP_NOM TO PK_MVS_1;
GRANT ALL ON COMP_NOM TO PK_MVS_2;
GRANT ALL ON COMP_NOM TO PK_MVS_3;
GRANT ALL ON COMP_NOM TO PK_MVS_4;
GRANT ALL ON COMP_NOM TO PK_MVS_P1;
GRANT ALL ON COMP_NOM TO PK_MVS_P2;
GRANT ALL ON COMP_NOM TO PK_OFK_1;
GRANT ALL ON COMP_NOM TO PK_OFK_2;
GRANT ALL ON COMP_NOM TO PK_OFK_3;
GRANT ALL ON COMP_NOM TO PK_OFK_4;
GRANT ALL ON COMP_NOM TO PK_OFK_P1;
GRANT ALL ON COMP_NOM TO PK_OFK_P2;
GRANT ALL ON COMP_NOM TO PK_OTV1;
GRANT ALL ON COMP_NOM TO PK_OTV2;
GRANT ALL ON COMP_NOM TO PK_OTV3;
GRANT ALL ON COMP_NOM TO PK_OTV4;
GRANT ALL ON COMP_NOM TO PK_SIIEP2;
GRANT ALL ON COMP_NOM TO PK_SIIE_1;
GRANT ALL ON COMP_NOM TO PK_SIIE_2;
GRANT ALL ON COMP_NOM TO PK_SIIE_3;
GRANT ALL ON COMP_NOM TO PK_SIIE_4;
GRANT ALL ON COMP_NOM TO PK_SIIE_P1;
GRANT ALL ON COMP_NOM TO PK_SIIE_P2;