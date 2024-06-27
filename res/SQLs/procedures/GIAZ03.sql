SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        GIAZ03
        (
            vid_edu SMALLINT
            date_in DATE,
        )
    RETURNS
        (
            s_so_t   INTEGER,
            s_so_t_e INTEGER,
            s_so_w   INTEGER,
            s_so_w_e INTEGER,
            s_l      INTEGER,
            s_sso    INTEGER,
            s_sso_e  INTEGER,
            s_ptu    INTEGER,
            s_ptu_e  INTEGER,
            s_vuz    INTEGER
        )
AS
    DECLARE
        VARIABLE n_a1      INTEGER;
    DECLARE
        VARIABLE n_ab      INTEGER;
    DECLARE
        VARIABLE typ_scl   INTEGER;
    DECLARE
        VARIABLE tw        INTEGER;
    DECLARE
        VARIABLE mdl_whn   INTEGER;
    DECLARE
        VARIABLE spec_when INTEGER;
    DECLARE
        VARIABLE educ      INTEGER;
    DECLARE
        VARIABLE te        INTEGER;
BEGIN
    s_so_t   = 0;    s_so_t_e = 0;    s_so_w   = 0;
    s_so_w_e = 0;    s_l      = 0;    s_sso    = 0;
    s_sso_e  = 0;    s_ptu    = 0;    s_ptu_e  = 0;
    s_vuz    = 0;    n_a1     = 0;

    FOR
        SELECT
            abitura.NOMER_AB,
            abitura.TYPE_SCHOOL,
            abitura.TOWN_VILLAGE,
            abitura.WHEN_EDU_MIDDLE,
            abitura.WHEN_EDU_SPEC,
            abitura.EDUCATION,
            abitura.TERM_EDU
        FROM
            ABITURA,
            ABITUR_LOGBOOK
        WHERE
                abitura.VID_EDU         =      :vid_edu
            AND abitura.STATUS          IS NOT NULL
            AND abitura.CATEGORY_IF     =      0
            AND abitur_logbook.NOMER_AB =      abitura.NOMER_AB
            AND abitur_logbook.DATE_IN  <      :date_in
            AND (     (abitura.TERM_EDU != 4)
                  AND (abitura.TERM_EDU != 5)
                )
        ORDER BY
            abitura.NOMER_AB
        INTO
            :n_ab,      /* NOMER_AB */
            :typ_scl,   /* TYPE_SCHOOL */
            :tw,        /* TOWN_VILLAGE */
            :mdl_whn,   /* WHEN_EDU_MIDDLE */
            :spec_when, /* WHEN_EDU_SPEC */
            :educ,      /* EDUCATION */
            :te         /* TERM_EDU */
    DO
        BEGIN
            IF (n_a1 <> n_ab)
            THEN
                BEGIN
                    IF (te = 3)             /* 1 course (HS) */
                    THEN
                        BEGIN
                            s_vuz = s_vuz + 1;
                        END
                    ELSE
                        BEGIN
                            IF (typ_scl = 3)                                    /* Lyceum, Gymnasium */
                            THEN
                                BEGIN
                                    s_l = s_l + 1;
                                END
                            ELSE
                                BEGIN
                                    IF (typ_scl = 0)                            /* Secondary education institution */
                                    THEN
                                        BEGIN
                                            IF (tw = 0)                         /* City or Urban-type settlement */
                                            THEN
                                                BEGIN
                                                    s_so_t = s_so_t + 1;

                                                    IF (mdl_whn = 2020)         /* Graduated from secondary in 2020.*/
                                                    THEN
                                                        s_so_t_e = s_so_t_e + 1;
                                                END
                                            ELSE                                /* other settlement */
                                                BEGIN
                                                    s_so_w = s_so_w + 1;

                                                    IF (mdl_whn = 2020)
                                                    THEN
                                                        s_so_w_e = s_so_w_e + 1;
                                                END
                                        END
                                    ELSE
                                        BEGIN
                                            IF (typ_scl = 1)                    /* Vocational education */
                                            THEN
                                                BEGIN
                                                    s_sso = s_sso + 1;

                                                    IF (spec_when = 2020)       /* Graduated from vocational education in 2020.*/
                                                    THEN
                                                        s_sso_e = s_sso_e + 1;
                                                END
                                            ELSE
                                                BEGIN
                                                    s_ptu = s_ptu + 1;          /* technical school */

                                                    IF (spec_when = 2020)
                                                    THEN
                                                        s_ptu_e = s_ptu_e + 1;
                                                END
                                        END
                                END
                        END
                END
            n_a1 = n_ab;
        END
    SUSPEND;
END^

SET TERM ; ^

/* Following GRANT statements are generated automatically */

GRANT
    SELECT
ON
    ABITURA
TO
    PROCEDURE
        GIAZ03;


GRANT
    SELECT
ON
    ABITUR_LOGBOOK
TO
    PROCEDURE
        GIAZ03;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE GIAZ03 TO ABITUR1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO ABITUR2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO ABITUR3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO ABITUR4;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO ABITURA;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO ALEXANDER_GONCHAROV;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO ASU;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO ASU1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO ASU2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO ASU3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO ASU4;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO DEVELOPER;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO IVANOVA_A;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO OKSANA;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_IT;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_IT1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_IT2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_IT3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_IT4;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_IT5;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MSTIG1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MSTIG2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MSTIG3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MSTIG4;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MSTIGP1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MSTIGP2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MSTIG_1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MSTIG_2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MSTIG_3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MSTIG_4;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MSTIG_P1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MSTIG_P2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVS;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVS1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVS2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVS3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVS4;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVS5;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVSP1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVSP2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVS_1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVS_2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVS_3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVS_4;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVS_P1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_MVS_P2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFKIT;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFKIT1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFKIT2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFKIT3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFKIT4;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFKIT5;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFKITP1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFKITP2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFK_1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFK_2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFK_3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFK_4;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFK_P1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OFK_P2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OTV1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OTV2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OTV3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_OTV4;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIE;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIE1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIE2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIE3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIE4;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIE5;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIEP1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIEP2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIEP3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIE_1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIE_2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIE_3;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIE_4;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIE_P1;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO PK_SIIE_P2;
GRANT EXECUTE ON PROCEDURE GIAZ03 TO SYSDBA;