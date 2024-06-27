SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        KOL_SERTIFIKAT
        (
            n_sp      INTEGER,
            n_vid_edu SMALLINT,
            n_fac     SMALLINT,
            predm     SMALLINT,
            st_ball   SMALLINT,
            r_b       SMALLINT
        )
    RETURNS
        (
            n10_9 INTEGER,
            n9_8  INTEGER,
            n8_7  INTEGER,
            n7_6  INTEGER,
            n6_5  INTEGER,
            n5_4  INTEGER,
            n4_3  INTEGER,
            n3_2  INTEGER,
            n2    INTEGER,
            n1    INTEGER,
            n0    INTEGER,
            n_ya  INTEGER
        )
AS
    DECLARE
        VARIABLE n_b INTEGER;
    DECLARE
        VARIABLE b   DOUBLE PRECISION;
    DECLARE
        VARIABLE c   INTEGER;
BEGIN
    n10_9 = 0;    n9_8 = 0;    n8_7 = 0;
    n7_6  = 0;    n6_5 = 0;    n5_4 = 0;
    n4_3  = 0;    n3_2 = 0;    n2   = 0;
    n1    = 0;    n0   = 0;    n_ya = 0;

    IF (:st_ball = 1)
    THEN
        /* for sertificates */
        BEGIN
            FOR
                SELECT
                    examen.BALL,
                    COUNT ( DISTINCT
                                abitura.NOMER_AB
                          )
                FROM
                        ABITURA abitura
                    INNER JOIN
                        EXAMEN  examen
                    ON
                        abitura.NOMER_AB = examen.NOMER_AB
                    INNER JOIN
                        SERTIFICAT sertificat
                    ON
                        abitura.NOMER_AB = sertificat.NOMER_AB
                WHERE
                        abitura.N_SPECIALIZ  =  :n_sp
                    AND abitura.VID_EDU      =  :n_vid_edu
                    AND abitura.N_FAC        =  :n_fac
                    AND examen.N_PREDMET     =  :predm
                    AND examen.STATUS_BALL   =  :st_ball
                    AND sertificat.RUS_BEL   =  :r_b
                    AND sertificat.N_PREDMET =  :predm
                    AND abitura.STATUS       <> 1
                GROUP BY
                    examen.BALL
                INTO
                    :b,
                    :c
            DO
                BEGIN
                    IF (:n_fac <> 4)
                    THEN
                        BEGIN
                            IF (b >  9)               THEN n10_9 = n10_9 + c;
                            IF (b >  8   AND b <= 9)  THEN n9_8  = n9_8  + c;
                            IF (b >  7   AND b <= 8)  THEN n8_7  = n8_7  + c;
                            IF (b >  6   AND b <= 7)  THEN n7_6  = n7_6  + c;
                            IF (b >  5   AND b <= 6)  THEN n6_5  = n6_5  + c;
                            IF (b >  4   AND b <= 5)  THEN n5_4  = n5_4  + c;
                            IF (b >  3   AND b <= 4)  THEN n4_3  = n4_3  + c;
                            IF (b >  2   AND b <= 3)  THEN n3_2  = n3_2  + c;
                        END
                    ELSE
                        BEGIN
                            IF (b >  90)              THEN n10_9 = n10_9 + c;
                            IF (b >  80  AND b <= 90) THEN n9_8  = n9_8  + c;
                            IF (b >  70  AND b <= 80) THEN n8_7  = n8_7  + c;
                            IF (b >  60  AND b <= 70) THEN n7_6  = n7_6  + c;
                            IF (b >  50  AND b <= 60) THEN n6_5  = n6_5  + c;
                            IF (b >  40  AND b <= 50) THEN n5_4  = n5_4  + c;
                            IF (b >  30  AND b <= 40) THEN n4_3  = n4_3  + c;
                            IF (b >  20  AND b <= 30) THEN n3_2  = n3_2  + c;
                            IF (b <= 20)              THEN n2    = n2    + c;
                        END
                END
            SUSPEND;
        END
    ELSE
        /* for exams */
        BEGIN
            FOR
                SELECT
                    examen.BALL,
                    examen.NOM_BALL,
                    COUNT ( DISTINCT
                                abitura.NOMER_AB
                          )
                FROM
                        ABITURA abitura
                    INNER JOIN
                        EXAMEN  examen
                    ON
                        abitura.NOMER_AB = examen.NOMER_AB
                WHERE
                        abitura.N_SPECIALIZ =  :n_sp
                    AND abitura.VID_EDU     =  :n_vid_edu
                    AND abitura.N_FAC       =  :n_fac
                    AND examen.N_PREDMET    =  :predm
                    AND examen.STATUS_BALL  =  :st_ball
                    AND abitura.STATUS      <> 1
                GROUP BY
                    examen.NOM_BALL,
                    examen.BALL
                INTO
                    :b,
                    :n_b,
                    :c
            DO
                BEGIN
                    IF (:n_fac <> 4)
                    THEN
                        BEGIN
                           IF (b = 10) THEN n10_9 = n10_9 + c;
                           IF (b = 9)  THEN n9_8  = n9_8  + c;
                           IF (b = 8)  THEN n8_7  = n8_7  + c;
                           IF (b = 7)  THEN n7_6  = n7_6  + c;
                           IF (b = 6)  THEN n6_5  = n6_5  + c;
                           IF (b = 5)  THEN n5_4  = n5_4  + c;
                           IF (b = 4)  THEN n4_3  = n4_3  + c;
                           IF (b = 3)  THEN n3_2  = n3_2  + c;
                           IF (b = 2)  THEN n2    = n2    + c;
                           IF (b = 1)  THEN n1    = n1    + c;
                           IF (b = 0)
                           THEN
                               /* check zero or absent */
                               BEGIN
                                   IF (n_b = 1)  THEN n0   = n0   + c;
                                   IF (n_b = 12) THEN n_ya = n_ya + c;
                               END
                        END
                    ELSE
                        BEGIN
                            IF (b >  90)              THEN n10_9 = n10_9 + c;
                            IF (b >  80  AND b <= 90) THEN n9_8  = n9_8  + c;
                            IF (b >  70  AND b <= 80) THEN n8_7  = n8_7  + c;
                            IF (b >  60  AND b <= 70) THEN n7_6  = n7_6  + c;
                            IF (b >  50  AND b <= 60) THEN n6_5  = n6_5  + c;
                            IF (b >  40  AND b <= 50) THEN n5_4  = n5_4  + c;
                            IF (b >  30  AND b <= 40) THEN n4_3  = n4_3  + c;
                            IF (b >  20  AND b <= 30) THEN n3_2  = n3_2  + c;
                            IF (b <= 20)              THEN n2    = n2    + c;
                        END
                END
            SUSPEND;
        END
END^

SET TERM ; ^

/* Following GRANT statements are generated automatically */

GRANT
    SELECT
ON
    ABITURA
TO
    PROCEDURE
        KOL_SERTIFIKAT;


GRANT
    SELECT
ON
    EXAMEN
TO
    PROCEDURE
        KOL_SERTIFIKAT;


GRANT
    SELECT
ON
    SERTIFICAT
TO
    PROCEDURE
        KOL_SERTIFIKAT;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO ABITUR1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO ABITUR2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO ABITUR3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO ABITUR4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO ABITURA;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO ALEXANDER_GONCHAROV;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO ASU;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO ASU1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO ASU2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO ASU3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO ASU4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO DEVELOPER;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO DEVELOPER2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO IT1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO IT2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO IT3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO IVANOVA_A;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO MVS1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO MVS2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO MVS3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO MVS4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO OFKIT1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO OFKIT2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO OFKIT3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO OFKIT4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO OKSANA;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_IT;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_IT1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_IT2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_IT3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_IT4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_IT5;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MSTIG1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MSTIG2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MSTIG3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MSTIG4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MSTIGP1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MSTIGP2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MSTIG_1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MSTIG_2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MSTIG_3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MSTIG_4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MSTIG_P1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MSTIG_P2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVS;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVS1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVS2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVS3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVS4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVS5;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVSP1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVSP2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVS_1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVS_2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVS_3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVS_4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVS_P1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_MVS_P2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFKIT;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFKIT1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFKIT2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFKIT3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFKIT4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFKIT5;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFKITP1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFKITP2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFK_1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFK_2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFK_3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFK_4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFK_P1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OFK_P2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OTV1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OTV2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OTV3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_OTV4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIE;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIE1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIE2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIE3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIE4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIE5;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIEP1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIEP2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIEP3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIE_1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIE_2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIE_3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIE_4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIE_P1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO PK_SIIE_P2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO SIIE1;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO SIIE2;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO SIIE3;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO SIIE4;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO SYSDBA;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO UO_LAB;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO UO_N;
GRANT EXECUTE ON PROCEDURE KOL_SERTIFIKAT TO UO_Z;