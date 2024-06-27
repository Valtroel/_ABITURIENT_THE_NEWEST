CREATE GENERATOR
    IBE$LOG_TABLES_GEN;

CREATE TABLE IF NOT EXISTS
EXAMEN
(
    NOMER_AB     INTEGER,
    N_PREDMET    SMALLINT,
    NOM_BALL     SMALLINT,
    BALL         DOUBLE PRECISION,
    STATUS_BALL  SMALLINT
);




/******************************************************************************/
/***                                Indices                                 ***/
/******************************************************************************/

CREATE INDEX EXAMEN_BALL             ON EXAMEN (BALL);
CREATE INDEX EXAMEN_NOMER_AB         ON EXAMEN (NOMER_AB);
CREATE INDEX EXAMEN_NOMER_AB_PREDMET ON EXAMEN (NOMER_AB, N_PREDMET);
CREATE INDEX EXAMEN_NOM_BALL         ON EXAMEN (NOM_BALL);
CREATE INDEX EXAMEN_PREDMET          ON EXAMEN (N_PREDMET);
CREATE INDEX EXAMEN_STATUS_BALL      ON EXAMEN (STATUS_BALL);


/******************************************************************************/
/***                                Triggers                                ***/
/******************************************************************************/



SET TERM ^ ;



/******************************************************************************/
/***                          Triggers for tables                           ***/
/******************************************************************************/



/* Trigger: IBE$EXAMEN_AD */
CREATE OR ALTER
    TRIGGER
        IBE$EXAMEN_AD
FOR
    EXAMEN
ACTIVE
    AFTER DELETE
        POSITION 32767
AS
    DECLARE 
        VARIABLE TID INTEGER;
BEGIN
  TID = GEN_ID(IBE$LOG_TABLES_GEN, 1);

    INSERT INTO
        IBE$LOG_TABLES
        (
            ID,
            TABLE_NAME,
            OPERATION,
            DATE_TIME,
            USER_NAME
        )
        VALUES
            (:TID, 'EXAMEN', 'D', 'NOW', USER);

    INSERT INTO
        IBE$LOG_FIELDS
        (
            LOG_TABLES_ID,
            FIELD_NAME,
            OLD_VALUE,
            NEW_VALUE
        )
        VALUES
            (:TID, 'NOMER_AB', OLD.NOMER_AB, NULL);

    INSERT INTO
        IBE$LOG_FIELDS
        (
            LOG_TABLES_ID,
            FIELD_NAME,
            OLD_VALUE,
            NEW_VALUE
        )
        VALUES
            (:TID, 'N_PREDMET', OLD.N_PREDMET, NULL);

    INSERT INTO
        IBE$LOG_FIELDS
        (
            LOG_TABLES_ID,
            FIELD_NAME,
            OLD_VALUE,
            NEW_VALUE
        )
        VALUES
            (:TID, 'NOM_BALL', OLD.NOM_BALL, NULL);

    INSERT INTO
        IBE$LOG_FIELDS
        (
            LOG_TABLES_ID,
            FIELD_NAME,
            OLD_VALUE,
            NEW_VALUE
        )
        VALUES
            (:TID, 'BALL', OLD.BALL, NULL);

    INSERT INTO
        IBE$LOG_FIELDS
        (
            LOG_TABLES_ID,
            FIELD_NAME,
            OLD_VALUE,
            NEW_VALUE
        )
        VALUES
            (:TID, 'STATUS_BALL', OLD.STATUS_BALL, NULL);
END
^


/* Trigger: IBE$EXAMEN_AI */
CREATE OR ALTER
    TRIGGER
        IBE$EXAMEN_AI
FOR
    EXAMEN
ACTIVE
    AFTER INSERT
        POSITION 32767
AS
    DECLARE
        VARIABLE TID INTEGER;
BEGIN
    TID = GEN_ID(IBE$LOG_TABLES_GEN, 1);

    INSERT INTO
        IBE$LOG_TABLES
        (
            ID,
            TABLE_NAME,
            OPERATION,
            DATE_TIME,
            USER_NAME
        )
        VALUES
            (:TID, 'EXAMEN', 'I', 'NOW', USER);


    IF (NOT (NEW.NOMER_AB IS NULL))
    THEN
        INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
            VALUES
                (:TID, 'NOMER_AB', NULL, NEW.NOMER_AB);

    IF (NOT (NEW.N_PREDMET IS NULL))
    THEN
        INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
            VALUES
                (:TID, 'N_PREDMET', NULL, NEW.N_PREDMET);

    IF (NOT (NEW.NOM_BALL IS NULL))
    THEN
        INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
            VALUES
                (:TID, 'NOM_BALL', NULL, NEW.NOM_BALL);

    IF (NOT (NEW.BALL IS NULL))
    THEN
        INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
            VALUES
                (:TID, 'BALL', NULL, NEW.BALL);

    IF (NOT (NEW.STATUS_BALL IS NULL))
    THEN
        INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
            VALUES
                (:TID, 'STATUS_BALL', NULL, NEW.STATUS_BALL);

END
^


/* Trigger: IBE$EXAMEN_AU */
CREATE OR ALTER
    TRIGGER
        IBE$EXAMEN_AU
FOR
    EXAMEN
ACTIVE
    AFTER UPDATE
        POSITION 32767
AS
    DECLARE
        VARIABLE TID INTEGER;
BEGIN
    TID = GEN_ID(IBE$LOG_TABLES_GEN, 1);

    INSERT INTO
        IBE$LOG_TABLES
        (
            ID,
            TABLE_NAME,
            OPERATION,
            DATE_TIME,
            USER_NAME
        )
        VALUES
            (:TID, 'EXAMEN', 'U', 'NOW', USER);


    IF (
            (       OLD.NOMER_AB IS NULL
                AND NEW.NOMER_AB IS NOT NULL
            )
        OR
            (       NEW.NOMER_AB IS NULL
                AND OLD.NOMER_AB IS NOT NULL
            )
        OR
            (       NEW.NOMER_AB IS NOT NULL
                AND OLD.NOMER_AB IS NOT NULL
                AND NEW.NOMER_AB <> OLD.NOMER_AB
            )
        )
    THEN
        INSERT INTO
            IBE$LOG_FIELDS
            (LOG_TABLES_ID, FIELD_NAME, OLD_VALUE, NEW_VALUE
            )
            VALUES
                (:TID, 'NOMER_AB', OLD.NOMER_AB, NEW.NOMER_AB);

    IF (
            (
                    OLD.N_PREDMET IS NULL
                AND NEW.N_PREDMET IS NOT NULL
            )
        OR
            (
                    NEW.N_PREDMET IS NULL
                AND OLD.N_PREDMET IS NOT NULL
            )
        OR
            (
                    NEW.N_PREDMET IS NOT NULL
                AND OLD.N_PREDMET IS NOT NULL
                AND NEW.N_PREDMET <> OLD.N_PREDMET
            )
        )
    THEN
        INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
            VALUES
                (:TID, 'N_PREDMET', OLD.N_PREDMET, NEW.N_PREDMET);

    IF (
            (
                    OLD.NOM_BALL IS NULL
                AND NEW.NOM_BALL IS NOT NULL
            )
        OR
            (
                    NEW.NOM_BALL IS NULL
                AND OLD.NOM_BALL IS NOT NULL
            )
        OR
            (
                    NEW.NOM_BALL IS NOT NULL
                AND OLD.NOM_BALL IS NOT NULL
                AND NEW.NOM_BALL <> OLD.NOM_BALL
            )
        )
    THEN
        INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
            VALUES
                (:TID, 'NOM_BALL', OLD.NOM_BALL, NEW.NOM_BALL);

    IF (
            (
                    OLD.BALL IS NULL
                AND NEW.BALL IS NOT NULL
            )
        OR
            (
                    NEW.BALL IS NULL
                AND OLD.BALL IS NOT NULL
            )
        OR
            (
                    NEW.BALL IS NOT NULL
                AND OLD.BALL IS NOT NULL
                AND NEW.BALL <> OLD.BALL
            )
        )
    THEN
        INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
            VALUES
                (:TID, 'BALL', OLD.BALL, NEW.BALL);

    IF (
            (
                    OLD.STATUS_BALL IS NULL
                AND NEW.STATUS_BALL IS NOT NULL
            )
        OR
            (
                    NEW.STATUS_BALL IS NULL
                AND OLD.STATUS_BALL IS NOT NULL
            )
        OR
            (
                    NEW.STATUS_BALL IS NOT NULL
                AND OLD.STATUS_BALL IS NOT NULL
                AND NEW.STATUS_BALL <> OLD.STATUS_BALL
            )
        )
    THEN
        INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
            VALUES
                (:TID, 'STATUS_BALL', OLD.STATUS_BALL, NEW.STATUS_BALL);

END
^

SET TERM ; ^



/******************************************************************************/
/***                          Fields descriptions                           ***/
/******************************************************************************/

COMMENT ON COLUMN EXAMEN.NOM_BALL IS 
'выбранная радиокнопка балла - на 1 больше балла???
12 - не явился';

COMMENT ON COLUMN EXAMEN.BALL IS 
'балл';

COMMENT ON COLUMN EXAMEN.STATUS_BALL IS 
'статус полученной оценки:
0 - для оценки за экзамен
1 - для централизованного тестирования';



/******************************************************************************/
/***                               Privileges                               ***/
/******************************************************************************/


/* Privileges of users */
GRANT ALL ON EXAMEN TO ABITUR1;
GRANT ALL ON EXAMEN TO ABITUR2;
GRANT ALL ON EXAMEN TO ABITUR3;
GRANT ALL ON EXAMEN TO ABITUR4;
GRANT ALL ON EXAMEN TO ABITURA;
GRANT ALL ON EXAMEN TO ALEXANDER_GONCHAROV;
GRANT ALL ON EXAMEN TO ASU;
GRANT ALL ON EXAMEN TO ASU1;
GRANT ALL ON EXAMEN TO ASU2;
GRANT ALL ON EXAMEN TO ASU3;
GRANT ALL ON EXAMEN TO ASU4;
GRANT ALL ON EXAMEN TO DEVELOPER;
GRANT ALL ON EXAMEN TO DEVELOPER2;
GRANT ALL ON EXAMEN TO IT1;
GRANT ALL ON EXAMEN TO IT2;
GRANT ALL ON EXAMEN TO IT3;
GRANT ALL ON EXAMEN TO IVANOVA_A;
GRANT ALL ON EXAMEN TO MVS1;
GRANT ALL ON EXAMEN TO MVS2;
GRANT ALL ON EXAMEN TO MVS3;
GRANT ALL ON EXAMEN TO MVS4;
GRANT ALL ON EXAMEN TO OFKIT1;
GRANT ALL ON EXAMEN TO OFKIT2;
GRANT ALL ON EXAMEN TO OFKIT3;
GRANT ALL ON EXAMEN TO OFKIT4;
GRANT ALL ON EXAMEN TO OKSANA;
GRANT ALL ON EXAMEN TO PK;
GRANT ALL ON EXAMEN TO PK_IT;
GRANT ALL ON EXAMEN TO PK_IT1;
GRANT ALL ON EXAMEN TO PK_IT2;
GRANT ALL ON EXAMEN TO PK_IT3;
GRANT ALL ON EXAMEN TO PK_IT4;
GRANT ALL ON EXAMEN TO PK_IT5;
GRANT ALL ON EXAMEN TO PK_MSTIG1;
GRANT ALL ON EXAMEN TO PK_MSTIG2;
GRANT ALL ON EXAMEN TO PK_MSTIG3;
GRANT ALL ON EXAMEN TO PK_MSTIG4;
GRANT ALL ON EXAMEN TO PK_MSTIGP1;
GRANT ALL ON EXAMEN TO PK_MSTIGP2;
GRANT ALL ON EXAMEN TO PK_MSTIG_1;
GRANT ALL ON EXAMEN TO PK_MSTIG_2;
GRANT ALL ON EXAMEN TO PK_MSTIG_3;
GRANT ALL ON EXAMEN TO PK_MSTIG_4;
GRANT ALL ON EXAMEN TO PK_MSTIG_P1;
GRANT ALL ON EXAMEN TO PK_MSTIG_P2;
GRANT ALL ON EXAMEN TO PK_MVS;
GRANT ALL ON EXAMEN TO PK_MVS1;
GRANT ALL ON EXAMEN TO PK_MVS2;
GRANT ALL ON EXAMEN TO PK_MVS3;
GRANT ALL ON EXAMEN TO PK_MVS4;
GRANT ALL ON EXAMEN TO PK_MVS5;
GRANT ALL ON EXAMEN TO PK_MVSP1;
GRANT ALL ON EXAMEN TO PK_MVSP2;
GRANT ALL ON EXAMEN TO PK_MVS_1;
GRANT ALL ON EXAMEN TO PK_MVS_2;
GRANT ALL ON EXAMEN TO PK_MVS_3;
GRANT ALL ON EXAMEN TO PK_MVS_4;
GRANT ALL ON EXAMEN TO PK_MVS_P1;
GRANT ALL ON EXAMEN TO PK_MVS_P2;
GRANT ALL ON EXAMEN TO PK_OFKIT;
GRANT ALL ON EXAMEN TO PK_OFKIT1;
GRANT ALL ON EXAMEN TO PK_OFKIT2;
GRANT ALL ON EXAMEN TO PK_OFKIT3;
GRANT ALL ON EXAMEN TO PK_OFKIT4;
GRANT ALL ON EXAMEN TO PK_OFKIT5;
GRANT ALL ON EXAMEN TO PK_OFKITP1;
GRANT ALL ON EXAMEN TO PK_OFKITP2;
GRANT ALL ON EXAMEN TO PK_OFK_1;
GRANT ALL ON EXAMEN TO PK_OFK_2;
GRANT ALL ON EXAMEN TO PK_OFK_3;
GRANT ALL ON EXAMEN TO PK_OFK_4;
GRANT ALL ON EXAMEN TO PK_OFK_P1;
GRANT ALL ON EXAMEN TO PK_OFK_P2;
GRANT ALL ON EXAMEN TO PK_OTV1;
GRANT ALL ON EXAMEN TO PK_OTV2;
GRANT ALL ON EXAMEN TO PK_OTV3;
GRANT ALL ON EXAMEN TO PK_OTV4;
GRANT ALL ON EXAMEN TO PK_SIIE;
GRANT ALL ON EXAMEN TO PK_SIIE1;
GRANT ALL ON EXAMEN TO PK_SIIE2;
GRANT ALL ON EXAMEN TO PK_SIIE3;
GRANT ALL ON EXAMEN TO PK_SIIE4;
GRANT ALL ON EXAMEN TO PK_SIIE5;
GRANT ALL ON EXAMEN TO PK_SIIEP1;
GRANT ALL ON EXAMEN TO PK_SIIEP2;
GRANT ALL ON EXAMEN TO PK_SIIEP3;
GRANT ALL ON EXAMEN TO PK_SIIE_1;
GRANT ALL ON EXAMEN TO PK_SIIE_2;
GRANT ALL ON EXAMEN TO PK_SIIE_3;
GRANT ALL ON EXAMEN TO PK_SIIE_4;
GRANT ALL ON EXAMEN TO PK_SIIE_P1;
GRANT ALL ON EXAMEN TO PK_SIIE_P2;
GRANT ALL ON EXAMEN TO SIIE1;
GRANT ALL ON EXAMEN TO SIIE2;
GRANT ALL ON EXAMEN TO SIIE3;
GRANT ALL ON EXAMEN TO SIIE4;
GRANT ALL ON EXAMEN TO UO_LAB;
GRANT ALL ON EXAMEN TO UO_N;
GRANT ALL ON EXAMEN TO UO_Z;

/* Privileges of triggers */
GRANT INSERT ON IBE$LOG_FIELDS TO TRIGGER IBE$EXAMEN_AD;
GRANT INSERT ON IBE$LOG_TABLES TO TRIGGER IBE$EXAMEN_AD;
GRANT INSERT ON IBE$LOG_FIELDS TO TRIGGER IBE$EXAMEN_AI;
GRANT INSERT ON IBE$LOG_TABLES TO TRIGGER IBE$EXAMEN_AI;
GRANT INSERT ON IBE$LOG_FIELDS TO TRIGGER IBE$EXAMEN_AU;
GRANT INSERT ON IBE$LOG_TABLES TO TRIGGER IBE$EXAMEN_AU;