SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        GIAZ01
        (
            vid_edu SMALLINT,
            date_in DATE,
            n_spec  SMALLINT
        )
    RETURNS
        (
            s_b_all INTEGER,    /* (Student budget) number of budget students */
            s_b_ck  INTEGER,    /* (Student budget) number of students via supervising organization */
            s_b_2   INTEGER,    /* (Student budget) number of budget students with short-term studies */
            s_p     INTEGER,    /* (study-for-fee) number of paying students */
            s_3s    INTEGER     /* (study-for-fee) number of full-course students in sports and tourism */
        )
AS
    DECLARE
        VARIABLE n_ab     INTEGER;
    DECLARE
        VARIABLE price    SMALLINT;
    DECLARE
        VARIABLE n_fac    SMALLINT;
    DECLARE
        VARIABLE n_ck     SMALLINT;
    DECLARE
        VARIABLE term_edu SMALLINT;
    DECLARE
        VARIABLE n1       INTEGER;
    
BEGIN
    s_b_all = 0;
    s_b_ck  = 0;
    s_b_2   = 0;
    s_p     = 0;
    s_3s    = 0;
    n1      = 0;

    FOR
        SELECT
            abitura.NOMER_AB,   /* abiturient ID */
            abitura.PRICE,      /* payment type: 0 - budget, 1 - study-for-fee */
            abitura.N_FAC,      /* fuculty ID: 1 - СИиЕ, 2 - МВС, 3 - ОФКиТ, 4 - МСиТ */
            abitura.N_CK,       /* supervising organization ID */
            abitura.TERM_EDU    /* Period of study: 0 - полный, 1 - сокращённый 2 курс, 2 - сокращённый 3 курс, 3 - 1 курс (ВО), 4 - 2 курс (ВО), 5 - 3 курс (ВО) */
        FROM
            ABITURA,
            ABITUR_LOGBOOK
        WHERE
                abitura.VID_EDU         =      :vid_edu
            AND abitura.STATUS          IS NOT NULL   /* Статус: 0 - действующий, 1 - забрал документы, 2 - получил отрицат. оценку, 3 - неявка на экзамен, 4 - забрал док-ты во время экз., 5 - зачисленный, 6 - онлайн зарегистрирован */
            AND abitura.N_SPEC          =      :n_spec
            AND abitura.CATEGORY_IF     =      0
            AND abitur_logbook.NOMER_AB =      abitura.NOMER_AB
            AND abitur_logbook.DATE_IN  <      :date_in
            AND (     (abitur_logbook.DATE_OUT >  :date_in)
                  OR  (abitur_logbook.DATE_OUT IS NULL)
                )
            AND (     (abitura.TERM_EDU        != 4)
                  AND (abitura.TERM_EDU        != 5)
                )
        ORDER BY
            abitura.NOMER_AB
        INTO
            :n_ab,
            :price,
            :n_fac,
            :n_ck,
            :term_edu
    DO
        BEGIN
            IF (n_ab <> n1)                             /* find the last of abiturient number */
            THEN
                BEGIN
                    IF (PRICE = 0)                      /* budget */
                    THEN
                        BEGIN
                            s_b_all = s_b_all + 1;

                            IF (N_CK > -1)              /* via supervising organization */
                            THEN
                                s_b_ck = s_b_ck + 1;

                            IF (    (TERM_EDU = 1)      /* short-term studies */
                                 OR (TERM_EDU = 2)
                               )
                            THEN
                                s_b_2 = s_b_2 + 1;
                        END
                    ELSE                                /* study-for-fee */
                        s_p = s_p + 1;

                        IF (    (N_FAC = 4)             /* sports and tourism managment */
                            AND (    (TERM_EDU = 0)     /* full-course */
                                  OR (TERM_EDU = 3)
                                )
                            )
                        THEN
                            s_3s = s_3s + 1;
                END
            n1 = n_ab;
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
        GIAZ01;

GRANT
    SELECT
ON
    ABITUR_LOGBOOK 
TO
    PROCEDURE 
        GIAZ01;

/* Existing privileges on this procedure */

GRANT EXECUTE ON PROCEDURE GIAZ01 TO ABITUR1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO ABITUR2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO ABITUR3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO ABITUR4;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO ABITURA;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO ALEXANDER_GONCHAROV;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO ASU;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO ASU1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO ASU2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO ASU3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO ASU4;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO DEVELOPER;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO IVANOVA_A;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO OKSANA;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_IT;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_IT1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_IT2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_IT3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_IT4;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_IT5;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MSTIG1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MSTIG2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MSTIG3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MSTIG4;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MSTIGP1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MSTIGP2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MSTIG_1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MSTIG_2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MSTIG_3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MSTIG_4;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MSTIG_P1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MSTIG_P2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVS;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVS1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVS2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVS3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVS4;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVS5;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVSP1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVSP2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVS_1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVS_2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVS_3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVS_4;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVS_P1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_MVS_P2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFKIT;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFKIT1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFKIT2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFKIT3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFKIT4;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFKIT5;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFKITP1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFKITP2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFK_1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFK_2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFK_3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFK_4;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFK_P1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OFK_P2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OTV1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OTV2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OTV3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_OTV4;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIE;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIE1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIE2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIE3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIE4;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIE5;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIEP1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIEP2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIEP3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIE_1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIE_2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIE_3;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIE_4;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIE_P1;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO PK_SIIE_P2;
GRANT EXECUTE ON PROCEDURE GIAZ01 TO SYSDBA;