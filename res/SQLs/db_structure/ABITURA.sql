CREATE GENERATOR
    IBE$LOG_TABLES_GEN;

CREATE TABLE IF NOT EXISTS
ABITURA
(
    /* Personal data */
    NOMER_AB         INTEGER,
    FAM              VARCHAR(30)  COLLATE PXW_CYRL,
    NAME             VARCHAR(30)  COLLATE PXW_CYRL,
    OTCH             VARCHAR(30)  COLLATE PXW_CYRL,
    POL              CHAR(1)      COLLATE PXW_CYRL,
    DATE_R           DATE,
    PLACE_R          VARCHAR(60)  COLLATE PXW_CYRL,
    GRAGDAN          VARCHAR(50)  COLLATE PXW_CYRL,
    NAZ              VARCHAR(15)  COLLATE PXW_CYRL,
    CATEGORY_AB      SMALLINT,
    PHOTO            BLOB         SUB_TYPE 0 SEGMENT SIZE 80,
    DIGIT_SIGN       BLOB         SUB_TYPE 0 SEGMENT SIZE 80,
    PHONE            VARCHAR(30)  COLLATE PXW_CYRL,
    /* Location */
    POSTCODE         INTEGER,
    CITIZENSHIP      SMALLINT,
    N_REGION         SMALLINT,
    N_CENTRE         INTEGER,
    TOWN_VILLAGE     SMALLINT,
    STREET           INTEGER,
    HOUSE            VARCHAR(10),
    FLAT             SMALLINT,
    ADDRESS_BEFORE   VARCHAR(100) COLLATE PXW_CYRL,
    ADDRESS_LIFE     VARCHAR(100) COLLATE PXW_CYRL,
    /* Personal ID data */
    ID_TYPE          SMALLINT,
    PASPORT          VARCHAR(150) COLLATE PXW_CYRL,
    PERSONAL_NOMER   VARCHAR(14)  COLLATE PXW_CYRL,
    ORGAN_V          VARCHAR(255) COLLATE PXW_CYRL,
    DATE_V           DATE,
    DATE_OK          DATE,
    /* Education */
    EDUCATION        SMALLINT,
    /* Secondary education */
    STAT_AB          VARCHAR(8),
    WHERE_EDU_MIDDLE VARCHAR(50)  COLLATE PXW_CYRL,
    NAME_EDU_MIDDLE  VARCHAR(50)  COLLATE PXW_CYRL,
    WHEN_EDU_MIDDLE  SMALLINT,
    NOM_ATTEST       VARCHAR(20)  COLLATE PXW_CYRL,
    /* Vocational education */
    TYPE_SCHOOL      SMALLINT,
    WHERE_EDU_SPEC   VARCHAR(50)  COLLATE PXW_CYRL,
    NAME_EDU_SPEC    VARCHAR(50)  COLLATE PXW_CYRL,
    WHEN_EDU_SPEC    SMALLINT,
    NOM_DIPLOM       VARCHAR(20)  COLLATE PXW_CYRL,
    /* Grade Point Average (GPA) */
    MIDDLE_BALL      DOUBLE PRECISION,
    COPY_AT          SMALLINT     DEFAULT 0,
    /* Privileges */
    CATEGORY_IF      SMALLINT,
    KONKURS          SMALLINT,
    N_PRIVILEGE_EXAM SMALLINT,
    V_K              VARCHAR(5),
    WITHOUT          VARCHAR(5),
    PRIV             VARCHAR(50),
    DISABLED         SMALLINT,
    /* Entrance exams */
    ID_AB_QUEUE      INTEGER      DEFAULT 0,
    DATE_PRIEM       DATE,
    DATE_VOZVRAT     DATE,
    SUM_BALL         DOUBLE PRECISION,
    STATUS           SMALLINT,
    RUS_BEL          SMALLINT,
    N_LANGVICH       SMALLINT,
    LANGV_BALL       SMALLINT,
    /* Enrolled as a student */
    NOM_DELA         SMALLINT,
    NOM_GROUP        VARCHAR(5)   COLLATE PXW_CYRL,
    N_PRIKAZ_INCLUDE SMALLINT,
    D_PRIKAZ_INCLUDE DATE,
    N_FOUND          SMALLINT,
    /* Payment */
    PRICE            SMALLINT,
    N_CK             SMALLINT,
    /* Edu direction */
    VID_EDU          SMALLINT,
    TERM_EDU         SMALLINT,
    N_FAC            SMALLINT,
    N_SPECIALIZ      SMALLINT,
    N_SPEC           SMALLINT,
    N_VID_SPORT      SMALLINT,
    N_SPORT_CATEGORY SMALLINT,
    /* Parents */
    PAPA             VARCHAR(50)  COLLATE PXW_CYRL,
    ADDRESS_PAPA     VARCHAR(100) COLLATE PXW_CYRL,
    WORK_PAPA        VARCHAR(70)  COLLATE PXW_CYRL,
    MAMA             VARCHAR(50)  COLLATE PXW_CYRL,
    ADDRESS_MAMA     VARCHAR(100) COLLATE PXW_CYRL,
    WORK_MAMA        VARCHAR(70)  COLLATE PXW_CYRL,
    /* Job experience */
    WORK_BEFORE      VARCHAR(70)  COLLATE PXW_CYRL,
    STAG             DOUBLE PRECISION,
    STAG_SPEC        DOUBLE PRECISION
);

/******************************************************************************/
/***                              Primary keys                              ***/
/******************************************************************************/

ALTER TABLE
    ABITURA
ADD 
    PRIMARY KEY
        (NOMER_AB);


/******************************************************************************/
/***                                Indices                                 ***/
/******************************************************************************/

CREATE INDEX ABITURA_CENTRE        ON ABITURA (N_CENTRE);
CREATE INDEX ABITURA_DATE_PRIEM    ON ABITURA (DATE_PRIEM);
CREATE INDEX ABITURA_FAC           ON ABITURA (N_FAC);
CREATE INDEX ABITURA_FAC_EDU_GROUP ON ABITURA (N_FAC, VID_EDU, NOM_GROUP);
CREATE INDEX ABITURA_FAC_EDU_SPEC  ON ABITURA (N_FAC, VID_EDU, N_SPECIALIZ);
CREATE INDEX ABITURA_FAM           ON ABITURA (FAM);
CREATE INDEX ABITURA_GRAGDAN       ON ABITURA (GRAGDAN);
CREATE INDEX ABITURA_KONKURS       ON ABITURA (KONKURS);
CREATE INDEX ABITURA_LANGVICH      ON ABITURA (N_LANGVICH);
CREATE INDEX ABITURA_MIDDLE_BALL   ON ABITURA (MIDDLE_BALL);
CREATE INDEX ABITURA_NAME          ON ABITURA (NAME);
CREATE INDEX ABITURA_NOM_DELA      ON ABITURA (NOM_DELA);
CREATE INDEX ABITURA_NOM_GROUP     ON ABITURA (NOM_GROUP);
CREATE INDEX ABITURA_N_CK          ON ABITURA (N_CK);
CREATE INDEX ABITURA_N_FOUND       ON ABITURA (N_FOUND);
CREATE INDEX ABITURA_OTCH          ON ABITURA (OTCH);
CREATE INDEX ABITURA_PRIV          ON ABITURA (PRIV);
CREATE INDEX ABITURA_REGION        ON ABITURA (N_REGION);
CREATE INDEX ABITURA_SPEC          ON ABITURA (N_SPEC);
CREATE INDEX ABITURA_SPECIALIZ     ON ABITURA (N_SPECIALIZ);
CREATE INDEX ABITURA_SPEC_EDU      ON ABITURA (N_SPEC, VID_EDU);
CREATE INDEX ABITURA_STAG          ON ABITURA (STAG);
CREATE INDEX ABITURA_STAG_SPEC     ON ABITURA (STAG_SPEC);
CREATE INDEX ABITURA_STATUS        ON ABITURA (STATUS);
CREATE INDEX ABITURA_STAT_AB       ON ABITURA (STAT_AB);
CREATE INDEX ABITURA_SUM_BALL      ON ABITURA (SUM_BALL);
CREATE INDEX ABITURA_VID_EDU       ON ABITURA (VID_EDU);
CREATE INDEX ABITURA_VK            ON ABITURA (V_K);
CREATE INDEX ABITURA_WHEN_MIDDLE   ON ABITURA (WHEN_EDU_MIDDLE);
CREATE INDEX ABITURA_WHEN_SPEC     ON ABITURA (WHEN_EDU_SPEC);
CREATE INDEX ABITURA_WITHOUT       ON ABITURA (WITHOUT);


/******************************************************************************/
/***                                Triggers                                ***/
/******************************************************************************/



SET TERM ^ ;



/******************************************************************************/
/***                          Triggers for tables                           ***/
/******************************************************************************/

/* Trigger: DEL_ABITURIENT  (Before DELETE)*/
CREATE OR ALTER
    TRIGGER
       DEL_ABITURIENT
FOR
    ABITURA
ACTIVE
    BEFORE DELETE
       POSITION 0
AS
BEGIN
    DELETE FROM
       EXAMEN
    WHERE
       EXAMEN.NOMER_AB = OLD.NOMER_AB;

    DELETE FROM
       SERTIFICAT
    WHERE
       SERTIFICAT.NOMER_AB = OLD.NOMER_AB;

    DELETE FROM
       AB_P
    WHERE
       AB_P.NOMER_AB = OLD.NOMER_AB;
END
^

/* Trigger: IBE$ABITURA_AD  (After DELETE)*/
CREATE OR ALTER
    TRIGGER
       IBE$ABITURA_AD
FOR
    ABITURA
ACTIVE
    AFTER DELETE
       POSITION 32767
AS
	DECLARE VARIABLE
		TID INTEGER;
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
            (:TID, 'ABITURA', 'D', 'NOW', USER);
 
    INSERT INTO
        IBE$LOG_KEYS
        (
            LOG_TABLES_ID,
            KEY_FIELD,
            KEY_VALUE
        )
    VALUES
        (:TID, 'NOMER_AB', OLD.NOMER_AB);
     
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
            (:TID, 'FAM', OLD.FAM, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'NAME', OLD.NAME, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'OTCH', OLD.OTCH, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'POL', OLD.POL, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'PLACE_R', OLD.PLACE_R, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'NAZ', OLD.NAZ, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'ADDRESS_BEFORE', OLD.ADDRESS_BEFORE, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'MIDDLE_BALL', OLD.MIDDLE_BALL, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'NAME_EDU_MIDDLE', OLD.NAME_EDU_MIDDLE, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'NAME_EDU_SPEC', OLD.NAME_EDU_SPEC, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'WHERE_EDU_MIDDLE', OLD.WHERE_EDU_MIDDLE, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'WHERE_EDU_SPEC', OLD.WHERE_EDU_SPEC, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'WHEN_EDU_MIDDLE', OLD.WHEN_EDU_MIDDLE, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'WHEN_EDU_SPEC', OLD.WHEN_EDU_SPEC, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'NOM_DELA', OLD.NOM_DELA, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'VID_EDU', OLD.VID_EDU, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'NOM_GROUP', OLD.NOM_GROUP, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'MAMA', OLD.MAMA, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'PAPA', OLD.PAPA, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'WORK_MAMA', OLD.WORK_MAMA, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'WORK_PAPA', OLD.WORK_PAPA, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'GRAGDAN', OLD.GRAGDAN, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'N_REGION', OLD.N_REGION, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'N_SPECIALIZ', OLD.N_SPECIALIZ, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'STATUS', OLD.STATUS, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'N_FAC', OLD.N_FAC, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'N_VID_SPORT', OLD.N_VID_SPORT, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'N_SPORT_CATEGORY', OLD.N_SPORT_CATEGORY, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'D_PRIKAZ_INCLUDE', OLD.D_PRIKAZ_INCLUDE, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'N_PRIKAZ_INCLUDE', OLD.N_PRIKAZ_INCLUDE, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'PHONE', OLD.PHONE, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'STAG', OLD.STAG, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'DATE_PRIEM', OLD.DATE_PRIEM, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'DATE_VOZVRAT', OLD.DATE_VOZVRAT, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'DATE_R', OLD.DATE_R, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'KONKURS', OLD.KONKURS, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'N_CK', OLD.N_CK, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'N_FOUND', OLD.N_FOUND, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'EDUCATION', OLD.EDUCATION, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'NOM_ATTEST', OLD.NOM_ATTEST, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'NOM_DIPLOM', OLD.NOM_DIPLOM, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'STAG_SPEC', OLD.STAG_SPEC, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'STAT_AB', OLD.STAT_AB, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'WORK_BEFORE', OLD.WORK_BEFORE, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'N_SPEC', OLD.N_SPEC, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'V_K', OLD.V_K, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'PRIV', OLD.PRIV, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'WITHOUT', OLD.WITHOUT, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'N_LANGVICH', OLD.N_LANGVICH, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'LANGV_BALL', OLD.LANGV_BALL, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'N_CENTRE', OLD.N_CENTRE, NULL);
      
    INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID,
                FIELD_NAME,
                OLD_VALUE,
                NEW_VALUE
            )
        VALUES
            (:TID, 'PRICE', OLD.PRICE, NULL);
       
END
^

/* Trigger: IBE$ABITURA_AI (After INSERT) */
CREATE OR ALTER
    TRIGGER
        IBE$ABITURA_AI
FOR
    ABITURA
ACTIVE
    AFTER INSERT
        POSITION 32767
AS
    DECLARE VARIABLE
        TID INTEGER;
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
        (:TID, 'ABITURA', 'I', 'NOW', USER);
 
    INSERT INTO
        IBE$LOG_KEYS
        (
            LOG_TABLES_ID,
            KEY_FIELD,
            KEY_VALUE
        )
    VALUES
        (:TID, 'NOMER_AB', NEW.NOMER_AB);


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
  
    IF (NOT (NEW.FAM IS NULL))
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
            (:TID, 'FAM', NULL, NEW.FAM);
  
    IF (NOT (NEW.NAME IS NULL))
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
            (:TID, 'NAME', NULL, NEW.NAME);
  
    IF (NOT (NEW.OTCH IS NULL))
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
            (:TID, 'OTCH', NULL, NEW.OTCH);
  
    IF (NOT (NEW.POL IS NULL))
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
            (:TID, 'POL', NULL, NEW.POL);
  
    IF (NOT (NEW.PLACE_R IS NULL))
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
            (:TID, 'PLACE_R', NULL, NEW.PLACE_R);
  
    IF (NOT (NEW.NAZ IS NULL))
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
            (:TID, 'NAZ', NULL, NEW.NAZ);
  
    IF (NOT (NEW.ADDRESS_BEFORE IS NULL))
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
            (:TID, 'ADDRESS_BEFORE', NULL, NEW.ADDRESS_BEFORE);
  
    IF (NOT (NEW.MIDDLE_BALL IS NULL))
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
            (:TID, 'MIDDLE_BALL', NULL, NEW.MIDDLE_BALL);
  
    IF (NOT (NEW.NAME_EDU_MIDDLE IS NULL))
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
            (:TID, 'NAME_EDU_MIDDLE', NULL, NEW.NAME_EDU_MIDDLE);
  
    IF (NOT (NEW.NAME_EDU_SPEC IS NULL))
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
            (:TID, 'NAME_EDU_SPEC', NULL, NEW.NAME_EDU_SPEC);
  
    IF (NOT (NEW.WHERE_EDU_MIDDLE IS NULL))
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
            (:TID, 'WHERE_EDU_MIDDLE', NULL, NEW.WHERE_EDU_MIDDLE);
  
    IF (NOT (NEW.WHERE_EDU_SPEC IS NULL))
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
            (:TID, 'WHERE_EDU_SPEC', NULL, NEW.WHERE_EDU_SPEC);
  
    IF (NOT (NEW.WHEN_EDU_MIDDLE IS NULL))
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
            (:TID, 'WHEN_EDU_MIDDLE', NULL, NEW.WHEN_EDU_MIDDLE);
  
    IF (NOT (NEW.WHEN_EDU_SPEC IS NULL))
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
            (:TID, 'WHEN_EDU_SPEC', NULL, NEW.WHEN_EDU_SPEC);
  
    IF (NOT (NEW.NOM_DELA IS NULL))
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
            (:TID, 'NOM_DELA', NULL, NEW.NOM_DELA);
  
    IF (NOT (NEW.VID_EDU IS NULL))
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
            (:TID, 'VID_EDU', NULL, NEW.VID_EDU);
  
    IF (NOT (NEW.NOM_GROUP IS NULL))
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
            (:TID, 'NOM_GROUP', NULL, NEW.NOM_GROUP);
  
    IF (NOT (NEW.MAMA IS NULL))
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
            (:TID, 'MAMA', NULL, NEW.MAMA);
  
    IF (NOT (NEW.PAPA IS NULL))
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
            (:TID, 'PAPA', NULL, NEW.PAPA);
  
    IF (NOT (NEW.WORK_MAMA IS NULL))
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
            (:TID, 'WORK_MAMA', NULL, NEW.WORK_MAMA);
  
    IF (NOT (NEW.WORK_PAPA IS NULL))
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
            (:TID, 'WORK_PAPA', NULL, NEW.WORK_PAPA);
  
    IF (NOT (NEW.GRAGDAN IS NULL))
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
            (:TID, 'GRAGDAN', NULL, NEW.GRAGDAN);
  
    IF (NOT (NEW.N_REGION IS NULL))
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
            (:TID, 'N_REGION', NULL, NEW.N_REGION);
  
    IF (NOT (NEW.N_SPECIALIZ IS NULL))
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
            (:TID, 'N_SPECIALIZ', NULL, NEW.N_SPECIALIZ);
  
    IF (NOT (NEW.STATUS IS NULL))
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
            (:TID, 'STATUS', NULL, NEW.STATUS);
  
    IF (NOT (NEW.N_FAC IS NULL))
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
            (:TID, 'N_FAC', NULL, NEW.N_FAC);
  
    IF (NOT (NEW.N_VID_SPORT IS NULL))
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
            (:TID, 'N_VID_SPORT', NULL, NEW.N_VID_SPORT);
  
    IF (NOT (NEW.N_SPORT_CATEGORY IS NULL))
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
            (:TID, 'N_SPORT_CATEGORY', NULL, NEW.N_SPORT_CATEGORY);
  
    IF (NOT (NEW.D_PRIKAZ_INCLUDE IS NULL))
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
            (:TID, 'D_PRIKAZ_INCLUDE', NULL, NEW.D_PRIKAZ_INCLUDE);
  
    IF (NOT (NEW.N_PRIKAZ_INCLUDE IS NULL))
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
            (:TID, 'N_PRIKAZ_INCLUDE', NULL, NEW.N_PRIKAZ_INCLUDE);
  
    IF (NOT (NEW.PHONE IS NULL))
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
            (:TID, 'PHONE', NULL, NEW.PHONE);
  
    IF (NOT (NEW.STAG IS NULL))
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
            (:TID, 'STAG', NULL, NEW.STAG);
  
    IF (NOT (NEW.DATE_PRIEM IS NULL))
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
            (:TID, 'DATE_PRIEM', NULL, NEW.DATE_PRIEM);
  
    IF (NOT (NEW.DATE_VOZVRAT IS NULL))
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
            (:TID, 'DATE_VOZVRAT', NULL, NEW.DATE_VOZVRAT);
  
    IF (NOT (NEW.DATE_R IS NULL))
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
            (:TID, 'DATE_R', NULL, NEW.DATE_R);
  
    IF (NOT (NEW.KONKURS IS NULL))
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
            (:TID, 'KONKURS', NULL, NEW.KONKURS);
  
    IF (NOT (NEW.N_CK IS NULL))
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
            (:TID, 'N_CK', NULL, NEW.N_CK);
  
    IF (NOT (NEW.N_FOUND IS NULL))
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
            (:TID, 'N_FOUND', NULL, NEW.N_FOUND);
  
    IF (NOT (NEW.EDUCATION IS NULL))
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
            (:TID, 'EDUCATION', NULL, NEW.EDUCATION);
  
    IF (NOT (NEW.NOM_ATTEST IS NULL))
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
            (:TID, 'NOM_ATTEST', NULL, NEW.NOM_ATTEST);
  
    IF (NOT (NEW.NOM_DIPLOM IS NULL))
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
            (:TID, 'NOM_DIPLOM', NULL, NEW.NOM_DIPLOM);
  
    IF (NOT (NEW.STAG_SPEC IS NULL))
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
            (:TID, 'STAG_SPEC', NULL, NEW.STAG_SPEC);
  
    IF (NOT (NEW.STAT_AB IS NULL))
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
            (:TID, 'STAT_AB', NULL, NEW.STAT_AB);
  
    IF (NOT (NEW.WORK_BEFORE IS NULL))
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
            (:TID, 'WORK_BEFORE', NULL, NEW.WORK_BEFORE);
  
    IF (NOT (NEW.N_SPEC IS NULL))
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
            (:TID, 'N_SPEC', NULL, NEW.N_SPEC);
  
    IF (NOT (NEW.V_K IS NULL))
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
            (:TID, 'V_K', NULL, NEW.V_K);
  
    IF (NOT (NEW.PRIV IS NULL))
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
            (:TID, 'PRIV', NULL, NEW.PRIV);
  
    IF (NOT (NEW.WITHOUT IS NULL))
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
            (:TID, 'WITHOUT', NULL, NEW.WITHOUT);
  
    IF (NOT (NEW.N_LANGVICH IS NULL))
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
            (:TID, 'N_LANGVICH', NULL, NEW.N_LANGVICH);
  
    IF (NOT (NEW.LANGV_BALL IS NULL))
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
            (:TID, 'LANGV_BALL', NULL, NEW.LANGV_BALL);
  
    IF (NOT (NEW.N_CENTRE IS NULL))
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
            (:TID, 'N_CENTRE', NULL, NEW.N_CENTRE);
  
    IF (NOT (NEW.PRICE IS NULL))
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
            (:TID, 'PRICE', NULL, NEW.PRICE);
  
END
^


/* Trigger: IBE$ABITURA_AU (After UPDATE)*/
CREATE OR ALTER
	TRIGGER
		IBE$ABITURA_AU
FOR
	ABITURA
ACTIVE
	AFTER UPDATE
		POSITION 32767
AS
	DECLARE VARIABLE
		TID INTEGER;
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
		(:TID, 'ABITURA', 'U', 'NOW', USER);
 
 
    INSERT INTO
        IBE$LOG_KEYS
		(
			LOG_TABLES_ID,
			KEY_FIELD,
			KEY_VALUE
		)
    VALUES
		(:TID, 'NOMER_AB', OLD.NOMER_AB);
 
 
    IF (
            (
                    OLD.NOMER_AB IS NULL
                AND NEW.NOMER_AB IS NOT NULL
            )
        OR
            (
                    NEW.NOMER_AB IS NULL
                AND OLD.NOMER_AB IS NOT NULL
            )
        OR
            (
                    NEW.NOMER_AB IS NOT NULL
                AND OLD.NOMER_AB IS NOT NULL
                AND NEW.NOMER_AB <> OLD.NOMER_AB
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
            (:TID, 'NOMER_AB', OLD.NOMER_AB, NEW.NOMER_AB);
  
    IF (
            (
                    OLD.FAM IS NULL
                AND NEW.FAM IS NOT NULL
            )
        OR
            (
                    NEW.FAM IS NULL
                AND OLD.FAM IS NOT NULL
            )
        OR
            (
                    NEW.FAM IS NOT NULL
                AND OLD.FAM IS NOT NULL
                AND NEW.FAM <> OLD.FAM
            )
        )
    THEN
        INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID, FIELD_NAME, OLD_VALUE, NEW_VALUE
            )
        VALUES
            (:TID, 'FAM', OLD.FAM, NEW.FAM);
  
    IF (
            (
                    OLD.NAME IS NULL
                AND NEW.NAME IS NOT NULL
            )
        OR
            (
                    NEW.NAME IS NULL
                AND OLD.NAME IS NOT NULL
            )
        OR
            (
                    NEW.NAME IS NOT NULL
                AND OLD.NAME IS NOT NULL
                AND NEW.NAME <> OLD.NAME
            )
        )
    THEN
        INSERT INTO
            IBE$LOG_FIELDS
            (
                LOG_TABLES_ID, FIELD_NAME, OLD_VALUE, NEW_VALUE
            )
        VALUES
            (:TID, 'NAME', OLD.NAME, NEW.NAME);
  
    IF (
            (
                    OLD.OTCH IS NULL
                AND NEW.OTCH IS NOT NULL
            )
        OR
            (
                    NEW.OTCH IS NULL
                AND OLD.OTCH IS NOT NULL
            )
        OR
            (
                    NEW.OTCH IS NOT NULL
                AND OLD.OTCH IS NOT NULL
                AND NEW.OTCH <> OLD.OTCH
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
            (:TID, 'OTCH', OLD.OTCH, NEW.OTCH);
  
    IF (
            (
                    OLD.POL IS NULL
                AND NEW.POL IS NOT NULL
            )
        OR
            (
                    NEW.POL IS NULL
                AND OLD.POL IS NOT NULL
            )
        OR
            (
                    NEW.POL IS NOT NULL
                AND OLD.POL IS NOT NULL
                AND NEW.POL <> OLD.POL
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
            (:TID, 'POL', OLD.POL, NEW.POL);
  
    IF (
            (
                    OLD.PLACE_R IS NULL
                AND NEW.PLACE_R IS NOT NULL
            )
        OR
            (
                    NEW.PLACE_R IS NULL
                AND OLD.PLACE_R IS NOT NULL
            )
        OR
            (
                    NEW.PLACE_R IS NOT NULL
                AND OLD.PLACE_R IS NOT NULL
                AND NEW.PLACE_R <> OLD.PLACE_R
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
            (:TID, 'PLACE_R', OLD.PLACE_R, NEW.PLACE_R);
  
    IF (
            (
                    OLD.NAZ IS NULL
                AND NEW.NAZ IS NOT NULL
            )
        OR
            (
                    NEW.NAZ IS NULL
                AND OLD.NAZ IS NOT NULL
            )
        OR
            (
                    NEW.NAZ IS NOT NULL
                AND OLD.NAZ IS NOT NULL
                AND NEW.NAZ <> OLD.NAZ
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
            (:TID, 'NAZ', OLD.NAZ, NEW.NAZ);
  
    IF (
            (
                    OLD.ADDRESS_BEFORE IS NULL
                AND NEW.ADDRESS_BEFORE IS NOT NULL
            )
        OR
            (
                    NEW.ADDRESS_BEFORE IS NULL
                AND OLD.ADDRESS_BEFORE IS NOT NULL
            )
        OR
            (
                    NEW.ADDRESS_BEFORE IS NOT NULL
                AND OLD.ADDRESS_BEFORE IS NOT NULL
                AND NEW.ADDRESS_BEFORE <> OLD.ADDRESS_BEFORE
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
            (:TID, 'ADDRESS_BEFORE', OLD.ADDRESS_BEFORE, NEW.ADDRESS_BEFORE);
  
    IF (
            (
                    OLD.MIDDLE_BALL IS NULL
                AND NEW.MIDDLE_BALL IS NOT NULL
            )
        OR
            (
                    NEW.MIDDLE_BALL IS NULL
                AND OLD.MIDDLE_BALL IS NOT NULL
            )
        OR
            (
                    NEW.MIDDLE_BALL IS NOT NULL
                AND OLD.MIDDLE_BALL IS NOT NULL
                AND NEW.MIDDLE_BALL <> OLD.MIDDLE_BALL
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
            (:TID, 'MIDDLE_BALL', OLD.MIDDLE_BALL, NEW.MIDDLE_BALL);
  
    IF (
            (
                    OLD.NAME_EDU_MIDDLE IS NULL
                AND NEW.NAME_EDU_MIDDLE IS NOT NULL
            )
        OR
            (
                    NEW.NAME_EDU_MIDDLE IS NULL
                AND OLD.NAME_EDU_MIDDLE IS NOT NULL
            )
        OR
            (
                    NEW.NAME_EDU_MIDDLE IS NOT NULL
                AND OLD.NAME_EDU_MIDDLE IS NOT NULL
                AND NEW.NAME_EDU_MIDDLE <> OLD.NAME_EDU_MIDDLE
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
            (:TID, 'NAME_EDU_MIDDLE', OLD.NAME_EDU_MIDDLE, NEW.NAME_EDU_MIDDLE);
  
    IF (
            (
                    OLD.NAME_EDU_SPEC IS NULL
                AND NEW.NAME_EDU_SPEC IS NOT NULL
            )
        OR
            (
                    NEW.NAME_EDU_SPEC IS NULL
                AND OLD.NAME_EDU_SPEC IS NOT NULL
            )
        OR
            (
                    NEW.NAME_EDU_SPEC IS NOT NULL
                AND OLD.NAME_EDU_SPEC IS NOT NULL
                AND NEW.NAME_EDU_SPEC <> OLD.NAME_EDU_SPEC
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
            (:TID, 'NAME_EDU_SPEC', OLD.NAME_EDU_SPEC, NEW.NAME_EDU_SPEC);
  
    IF (
            (
                    OLD.WHERE_EDU_MIDDLE IS NULL
                AND NEW.WHERE_EDU_MIDDLE IS NOT NULL
            )
        OR
            (
                    NEW.WHERE_EDU_MIDDLE IS NULL
                AND OLD.WHERE_EDU_MIDDLE IS NOT NULL
            )
        OR
            (
                    NEW.WHERE_EDU_MIDDLE IS NOT NULL
                AND OLD.WHERE_EDU_MIDDLE IS NOT NULL
                AND NEW.WHERE_EDU_MIDDLE <> OLD.WHERE_EDU_MIDDLE
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
            (:TID, 'WHERE_EDU_MIDDLE', OLD.WHERE_EDU_MIDDLE, NEW.WHERE_EDU_MIDDLE);
  
    IF (
            (
                    OLD.WHERE_EDU_SPEC IS NULL
                AND NEW.WHERE_EDU_SPEC IS NOT NULL
            )
        OR
            (
                    NEW.WHERE_EDU_SPEC IS NULL
                AND OLD.WHERE_EDU_SPEC IS NOT NULL
            )
        OR
            (
                    NEW.WHERE_EDU_SPEC IS NOT NULL
                AND OLD.WHERE_EDU_SPEC IS NOT NULL
                AND NEW.WHERE_EDU_SPEC <> OLD.WHERE_EDU_SPEC
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
            (:TID, 'WHERE_EDU_SPEC', OLD.WHERE_EDU_SPEC, NEW.WHERE_EDU_SPEC);
  
    IF (
            (
                    OLD.WHEN_EDU_MIDDLE IS NULL
                AND NEW.WHEN_EDU_MIDDLE IS NOT NULL
            )
        OR
            (
                    NEW.WHEN_EDU_MIDDLE IS NULL
                AND OLD.WHEN_EDU_MIDDLE IS NOT NULL
            )
        OR
            (
                    NEW.WHEN_EDU_MIDDLE IS NOT NULL
                AND OLD.WHEN_EDU_MIDDLE IS NOT NULL
                AND NEW.WHEN_EDU_MIDDLE <> OLD.WHEN_EDU_MIDDLE
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
            (:TID, 'WHEN_EDU_MIDDLE', OLD.WHEN_EDU_MIDDLE, NEW.WHEN_EDU_MIDDLE);
  
    IF (
            (
                    OLD.WHEN_EDU_SPEC IS NULL
                AND NEW.WHEN_EDU_SPEC IS NOT NULL
            )
        OR
            (
                    NEW.WHEN_EDU_SPEC IS NULL
                AND OLD.WHEN_EDU_SPEC IS NOT NULL
            )
        OR
            (
                    NEW.WHEN_EDU_SPEC IS NOT NULL
                AND OLD.WHEN_EDU_SPEC IS NOT NULL
                AND NEW.WHEN_EDU_SPEC <> OLD.WHEN_EDU_SPEC
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
            (:TID, 'WHEN_EDU_SPEC', OLD.WHEN_EDU_SPEC, NEW.WHEN_EDU_SPEC);
  
    IF (
            (
                    OLD.NOM_DELA IS NULL
                AND NEW.NOM_DELA IS NOT NULL
            )
        OR
            (
                    NEW.NOM_DELA IS NULL
                AND OLD.NOM_DELA IS NOT NULL
            )
        OR
            (
                    NEW.NOM_DELA IS NOT NULL
                AND OLD.NOM_DELA IS NOT NULL
                AND NEW.NOM_DELA <> OLD.NOM_DELA
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
            (:TID, 'NOM_DELA', OLD.NOM_DELA, NEW.NOM_DELA);
  
    IF (
            (
                    OLD.VID_EDU IS NULL
                AND NEW.VID_EDU IS NOT NULL
            )
        OR
            (
                    NEW.VID_EDU IS NULL
                AND OLD.VID_EDU IS NOT NULL
            )
        OR
            (
                    NEW.VID_EDU IS NOT NULL
                AND OLD.VID_EDU IS NOT NULL
                AND NEW.VID_EDU <> OLD.VID_EDU
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
            (:TID, 'VID_EDU', OLD.VID_EDU, NEW.VID_EDU);
  
    IF (
            (
                    OLD.NOM_GROUP IS NULL
                AND NEW.NOM_GROUP IS NOT NULL
            )
        OR
            (
                    NEW.NOM_GROUP IS NULL
                AND OLD.NOM_GROUP IS NOT NULL
            )
        OR
            (
                    NEW.NOM_GROUP IS NOT NULL
                AND OLD.NOM_GROUP IS NOT NULL
                AND NEW.NOM_GROUP <> OLD.NOM_GROUP
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
            (:TID, 'NOM_GROUP', OLD.NOM_GROUP, NEW.NOM_GROUP);
  
    IF (
            (
                    OLD.MAMA IS NULL
                AND NEW.MAMA IS NOT NULL
            )
        OR
            (
                    NEW.MAMA IS NULL
                AND OLD.MAMA IS NOT NULL
            )
        OR
            (
                    NEW.MAMA IS NOT NULL
                AND OLD.MAMA IS NOT NULL
                AND NEW.MAMA <> OLD.MAMA
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
            (:TID, 'MAMA', OLD.MAMA, NEW.MAMA);
  
    IF (
            (
                    OLD.PAPA IS NULL
                AND NEW.PAPA IS NOT NULL
            )
        OR
            (
                    NEW.PAPA IS NULL
                AND OLD.PAPA IS NOT NULL
            )
        OR
            (
                    NEW.PAPA IS NOT NULL
                AND OLD.PAPA IS NOT NULL
                AND NEW.PAPA <> OLD.PAPA
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
            (:TID, 'PAPA', OLD.PAPA, NEW.PAPA);
  
    IF (
            (
                    OLD.WORK_MAMA IS NULL
                AND NEW.WORK_MAMA IS NOT NULL
            )
        OR
            (
                    NEW.WORK_MAMA IS NULL
                AND OLD.WORK_MAMA IS NOT NULL
            )
        OR
            (
                    NEW.WORK_MAMA IS NOT NULL
                AND OLD.WORK_MAMA IS NOT NULL
                AND NEW.WORK_MAMA <> OLD.WORK_MAMA
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
            (:TID, 'WORK_MAMA', OLD.WORK_MAMA, NEW.WORK_MAMA);
  
    IF (
            (
                    OLD.WORK_PAPA IS NULL
                AND NEW.WORK_PAPA IS NOT NULL
            )
        OR
            (
                    NEW.WORK_PAPA IS NULL
                AND OLD.WORK_PAPA IS NOT NULL
            )
        OR
            (
                    NEW.WORK_PAPA IS NOT NULL
                AND OLD.WORK_PAPA IS NOT NULL
                AND NEW.WORK_PAPA <> OLD.WORK_PAPA
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
            (:TID, 'WORK_PAPA', OLD.WORK_PAPA, NEW.WORK_PAPA);
  
    IF (
            (
                    OLD.GRAGDAN IS NULL
                AND NEW.GRAGDAN IS NOT NULL
            )
        OR
            (
                    NEW.GRAGDAN IS NULL
                AND OLD.GRAGDAN IS NOT NULL
            )
        OR
            (
                    NEW.GRAGDAN IS NOT NULL
                AND OLD.GRAGDAN IS NOT NULL
                AND NEW.GRAGDAN <> OLD.GRAGDAN
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
            (:TID, 'GRAGDAN', OLD.GRAGDAN, NEW.GRAGDAN);
  
    IF (
            (
                    OLD.N_REGION IS NULL
                AND NEW.N_REGION IS NOT NULL
            )
        OR
            (
                    NEW.N_REGION IS NULL
                AND OLD.N_REGION IS NOT NULL
            )
        OR
            (
                    NEW.N_REGION IS NOT NULL
                AND OLD.N_REGION IS NOT NULL
                AND NEW.N_REGION <> OLD.N_REGION
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
            (:TID, 'N_REGION', OLD.N_REGION, NEW.N_REGION);
  
    IF (
            (
                    OLD.N_SPECIALIZ IS NULL
                AND NEW.N_SPECIALIZ IS NOT NULL
            )
        OR
            (
                    NEW.N_SPECIALIZ IS NULL
                AND OLD.N_SPECIALIZ IS NOT NULL
            )
        OR
            (
                    NEW.N_SPECIALIZ IS NOT NULL
                AND OLD.N_SPECIALIZ IS NOT NULL
                AND NEW.N_SPECIALIZ <> OLD.N_SPECIALIZ
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
            (:TID, 'N_SPECIALIZ', OLD.N_SPECIALIZ, NEW.N_SPECIALIZ);
  
    IF (
            (
                    OLD.STATUS IS NULL
                AND NEW.STATUS IS NOT NULL
            )
        OR
            (
                    NEW.STATUS IS NULL
                AND OLD.STATUS IS NOT NULL
            )
        OR
            (
                    NEW.STATUS IS NOT NULL
                AND OLD.STATUS IS NOT NULL
                AND NEW.STATUS <> OLD.STATUS
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
            (:TID, 'STATUS', OLD.STATUS, NEW.STATUS);
  
    IF (
            (
                    OLD.N_FAC IS NULL
                AND NEW.N_FAC IS NOT NULL
            )
        OR
            (
                    NEW.N_FAC IS NULL
                AND OLD.N_FAC IS NOT NULL
            )
        OR
            (
                    NEW.N_FAC IS NOT NULL
                AND OLD.N_FAC IS NOT NULL
                AND NEW.N_FAC <> OLD.N_FAC
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
            (:TID, 'N_FAC', OLD.N_FAC, NEW.N_FAC);
  
    IF (
            (
                    OLD.N_VID_SPORT IS NULL
                AND NEW.N_VID_SPORT IS NOT NULL
            )
        OR
            (
                    NEW.N_VID_SPORT IS NULL
                AND OLD.N_VID_SPORT IS NOT NULL
            )
        OR
            (
                    NEW.N_VID_SPORT IS NOT NULL
                AND OLD.N_VID_SPORT IS NOT NULL
                AND NEW.N_VID_SPORT <> OLD.N_VID_SPORT
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
            (:TID, 'N_VID_SPORT', OLD.N_VID_SPORT, NEW.N_VID_SPORT);
  
    IF (
            (
                    OLD.N_SPORT_CATEGORY IS NULL
                AND NEW.N_SPORT_CATEGORY IS NOT NULL
            )
        OR
            (
                    NEW.N_SPORT_CATEGORY IS NULL
                AND OLD.N_SPORT_CATEGORY IS NOT NULL
            )
        OR
            (
                    NEW.N_SPORT_CATEGORY IS NOT NULL
                AND OLD.N_SPORT_CATEGORY IS NOT NULL
                AND NEW.N_SPORT_CATEGORY <> OLD.N_SPORT_CATEGORY
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
            (:TID, 'N_SPORT_CATEGORY', OLD.N_SPORT_CATEGORY, NEW.N_SPORT_CATEGORY);
  
    IF (
            (
                    OLD.D_PRIKAZ_INCLUDE IS NULL
                AND NEW.D_PRIKAZ_INCLUDE IS NOT NULL
            )
        OR
            (
                    NEW.D_PRIKAZ_INCLUDE IS NULL
                AND OLD.D_PRIKAZ_INCLUDE IS NOT NULL
            )
        OR
            (
                    NEW.D_PRIKAZ_INCLUDE IS NOT NULL
                AND OLD.D_PRIKAZ_INCLUDE IS NOT NULL
                AND NEW.D_PRIKAZ_INCLUDE <> OLD.D_PRIKAZ_INCLUDE
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
            (:TID, 'D_PRIKAZ_INCLUDE', OLD.D_PRIKAZ_INCLUDE, NEW.D_PRIKAZ_INCLUDE);
  
    IF (
            (
                    OLD.N_PRIKAZ_INCLUDE IS NULL
                AND NEW.N_PRIKAZ_INCLUDE IS NOT NULL
            )
        OR
            (
                    NEW.N_PRIKAZ_INCLUDE IS NULL
                AND OLD.N_PRIKAZ_INCLUDE IS NOT NULL
            )
        OR
            (
                    NEW.N_PRIKAZ_INCLUDE IS NOT NULL
                AND OLD.N_PRIKAZ_INCLUDE IS NOT NULL
                AND NEW.N_PRIKAZ_INCLUDE <> OLD.N_PRIKAZ_INCLUDE
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
            (:TID, 'N_PRIKAZ_INCLUDE', OLD.N_PRIKAZ_INCLUDE, NEW.N_PRIKAZ_INCLUDE);
  
    IF (
            (
                    OLD.PHONE IS NULL
                AND NEW.PHONE IS NOT NULL
            )
        OR
            (
                    NEW.PHONE IS NULL
                AND OLD.PHONE IS NOT NULL
            )
        OR
            (
                    NEW.PHONE IS NOT NULL
                AND OLD.PHONE IS NOT NULL
                AND NEW.PHONE <> OLD.PHONE
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
            (:TID, 'PHONE', OLD.PHONE, NEW.PHONE);
  
    IF (
            (
                    OLD.STAG IS NULL
                AND NEW.STAG IS NOT NULL
            )
        OR
            (
                    NEW.STAG IS NULL
                AND OLD.STAG IS NOT NULL
            )
        OR
            (
                    NEW.STAG IS NOT NULL
                AND OLD.STAG IS NOT NULL
                AND NEW.STAG <> OLD.STAG
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
            (:TID, 'STAG', OLD.STAG, NEW.STAG);
  
    IF (
            (
                    OLD.DATE_PRIEM IS NULL
                AND NEW.DATE_PRIEM IS NOT NULL
            )
        OR
            (
                    NEW.DATE_PRIEM IS NULL
                AND OLD.DATE_PRIEM IS NOT NULL
            )
        OR
            (
                    NEW.DATE_PRIEM IS NOT NULL
                AND OLD.DATE_PRIEM IS NOT NULL
                AND NEW.DATE_PRIEM <> OLD.DATE_PRIEM
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
            (:TID, 'DATE_PRIEM', OLD.DATE_PRIEM, NEW.DATE_PRIEM);
  
    IF (
            (
                    OLD.DATE_VOZVRAT IS NULL
                AND NEW.DATE_VOZVRAT IS NOT NULL
            )
        OR
            (
                    NEW.DATE_VOZVRAT IS NULL
                AND OLD.DATE_VOZVRAT IS NOT NULL
            )
        OR
            (
                    NEW.DATE_VOZVRAT IS NOT NULL
                AND OLD.DATE_VOZVRAT IS NOT NULL
                AND NEW.DATE_VOZVRAT <> OLD.DATE_VOZVRAT
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
            (:TID, 'DATE_VOZVRAT', OLD.DATE_VOZVRAT, NEW.DATE_VOZVRAT);
  
    IF (
            (
                    OLD.DATE_R IS NULL
                AND NEW.DATE_R IS NOT NULL
            )
        OR
            (
                    NEW.DATE_R IS NULL
                AND OLD.DATE_R IS NOT NULL
            )
        OR
            (
                    NEW.DATE_R IS NOT NULL
                AND OLD.DATE_R IS NOT NULL
                AND NEW.DATE_R <> OLD.DATE_R
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
            (:TID, 'DATE_R', OLD.DATE_R, NEW.DATE_R);
  
    IF (
            (
                    OLD.KONKURS IS NULL
                AND NEW.KONKURS IS NOT NULL
            )
        OR
            (
                    NEW.KONKURS IS NULL
                AND OLD.KONKURS IS NOT NULL
            )
        OR
            (
                    NEW.KONKURS IS NOT NULL
                AND OLD.KONKURS IS NOT NULL
                AND NEW.KONKURS <> OLD.KONKURS
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
            (:TID, 'KONKURS', OLD.KONKURS, NEW.KONKURS);
  
    IF (
            (
                    OLD.N_CK IS NULL
                AND NEW.N_CK IS NOT NULL
            )
        OR
            (
                    NEW.N_CK IS NULL
                AND OLD.N_CK IS NOT NULL
            )
        OR
            (
                    NEW.N_CK IS NOT NULL
                AND OLD.N_CK IS NOT NULL
                AND NEW.N_CK <> OLD.N_CK
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
            (:TID, 'N_CK', OLD.N_CK, NEW.N_CK);
  
    IF (
            (
                    OLD.N_FOUND IS NULL
                AND NEW.N_FOUND IS NOT NULL
            )
        OR
            (
                    NEW.N_FOUND IS NULL
                AND OLD.N_FOUND IS NOT NULL
            )
        OR
            (
                    NEW.N_FOUND IS NOT NULL
                AND OLD.N_FOUND IS NOT NULL
                AND NEW.N_FOUND <> OLD.N_FOUND
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
            (:TID, 'N_FOUND', OLD.N_FOUND, NEW.N_FOUND);
  
    IF (
            (
                    OLD.EDUCATION IS NULL
                AND NEW.EDUCATION IS NOT NULL
            )
        OR
            (
                    NEW.EDUCATION IS NULL
                AND OLD.EDUCATION IS NOT NULL
            )
        OR
            (
                    NEW.EDUCATION IS NOT NULL
                AND OLD.EDUCATION IS NOT NULL
                AND NEW.EDUCATION <> OLD.EDUCATION
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
            (:TID, 'EDUCATION', OLD.EDUCATION, NEW.EDUCATION);
  
    IF (
            (
                    OLD.NOM_ATTEST IS NULL
                AND NEW.NOM_ATTEST IS NOT NULL
            )
        OR
            (
                    NEW.NOM_ATTEST IS NULL
                AND OLD.NOM_ATTEST IS NOT NULL
            )
        OR
            (
                    NEW.NOM_ATTEST IS NOT NULL
                AND OLD.NOM_ATTEST IS NOT NULL
                AND NEW.NOM_ATTEST <> OLD.NOM_ATTEST
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
            (:TID, 'NOM_ATTEST', OLD.NOM_ATTEST, NEW.NOM_ATTEST);
  
    IF (
            (
                    OLD.NOM_DIPLOM IS NULL
                AND NEW.NOM_DIPLOM IS NOT NULL
            )
        OR
            (
                    NEW.NOM_DIPLOM IS NULL
                AND OLD.NOM_DIPLOM IS NOT NULL
            )
        OR
            (
                    NEW.NOM_DIPLOM IS NOT NULL
                AND OLD.NOM_DIPLOM IS NOT NULL
                AND NEW.NOM_DIPLOM <> OLD.NOM_DIPLOM
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
            (:TID, 'NOM_DIPLOM', OLD.NOM_DIPLOM, NEW.NOM_DIPLOM);
  
    IF (
            (
                    OLD.STAG_SPEC IS NULL
                AND NEW.STAG_SPEC IS NOT NULL
            )
        OR
            (
                    NEW.STAG_SPEC IS NULL
                AND OLD.STAG_SPEC IS NOT NULL
            )
        OR
            (
                    NEW.STAG_SPEC IS NOT NULL
                AND OLD.STAG_SPEC IS NOT NULL
                AND NEW.STAG_SPEC <> OLD.STAG_SPEC
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
            (:TID, 'STAG_SPEC', OLD.STAG_SPEC, NEW.STAG_SPEC);
  
    IF (
            (
                    OLD.STAT_AB IS NULL
                AND NEW.STAT_AB IS NOT NULL
            )
        OR
            (
                    NEW.STAT_AB IS NULL
                AND OLD.STAT_AB IS NOT NULL
            )
        OR
            (
                    NEW.STAT_AB IS NOT NULL
                AND OLD.STAT_AB IS NOT NULL
                AND NEW.STAT_AB <> OLD.STAT_AB
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
            (:TID, 'STAT_AB', OLD.STAT_AB, NEW.STAT_AB);
  
    IF (
            (
                    OLD.WORK_BEFORE IS NULL
                AND NEW.WORK_BEFORE IS NOT NULL
            )
        OR
            (
                    NEW.WORK_BEFORE IS NULL
                AND OLD.WORK_BEFORE IS NOT NULL
            )
        OR
            (
                    NEW.WORK_BEFORE IS NOT NULL
                AND OLD.WORK_BEFORE IS NOT NULL
                AND NEW.WORK_BEFORE <> OLD.WORK_BEFORE
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
            (:TID, 'WORK_BEFORE', OLD.WORK_BEFORE, NEW.WORK_BEFORE);
  
    IF (
            (
                    OLD.N_SPEC IS NULL
                AND NEW.N_SPEC IS NOT NULL
            )
        OR
            (
                    NEW.N_SPEC IS NULL
                AND OLD.N_SPEC IS NOT NULL
            )
        OR
            (
                    NEW.N_SPEC IS NOT NULL
                AND OLD.N_SPEC IS NOT NULL
                AND NEW.N_SPEC <> OLD.N_SPEC
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
            (:TID, 'N_SPEC', OLD.N_SPEC, NEW.N_SPEC);
  
    IF (
            (
                    OLD.V_K IS NULL
                AND NEW.V_K IS NOT NULL
            )
        OR
            (
                    NEW.V_K IS NULL
                AND OLD.V_K IS NOT NULL
            )
        OR
            (
                    NEW.V_K IS NOT NULL
                AND OLD.V_K IS NOT NULL
                AND NEW.V_K <> OLD.V_K
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
            (:TID, 'V_K', OLD.V_K, NEW.V_K);
  
    IF (
            (
                    OLD.PRIV IS NULL
                AND NEW.PRIV IS NOT NULL
            )
        OR
            (
                    NEW.PRIV IS NULL
                AND OLD.PRIV IS NOT NULL
            )
        OR
            (
                    NEW.PRIV IS NOT NULL
                AND OLD.PRIV IS NOT NULL
                AND NEW.PRIV <> OLD.PRIV
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
            (:TID, 'PRIV', OLD.PRIV, NEW.PRIV);
  
    IF (
            (
                    OLD.WITHOUT IS NULL
                AND NEW.WITHOUT IS NOT NULL
            )
        OR
            (
                    NEW.WITHOUT IS NULL
                AND OLD.WITHOUT IS NOT NULL
            )
        OR
            (
                    NEW.WITHOUT IS NOT NULL
                AND OLD.WITHOUT IS NOT NULL
                AND NEW.WITHOUT <> OLD.WITHOUT
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
            (:TID, 'WITHOUT', OLD.WITHOUT, NEW.WITHOUT);
  
    IF (
            (
                    OLD.N_LANGVICH IS NULL
                AND NEW.N_LANGVICH IS NOT NULL
            )
        OR
            (
                    NEW.N_LANGVICH IS NULL
                AND OLD.N_LANGVICH IS NOT NULL
            )
        OR
            (
                    NEW.N_LANGVICH IS NOT NULL
                AND OLD.N_LANGVICH IS NOT NULL
                AND NEW.N_LANGVICH <> OLD.N_LANGVICH
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
            (:TID, 'N_LANGVICH', OLD.N_LANGVICH, NEW.N_LANGVICH);
  
    IF (
            (
                    OLD.LANGV_BALL IS NULL
                AND NEW.LANGV_BALL IS NOT NULL
            )
        OR
            (
                    NEW.LANGV_BALL IS NULL
                AND OLD.LANGV_BALL IS NOT NULL
            )
        OR
            (
                    NEW.LANGV_BALL IS NOT NULL
                AND OLD.LANGV_BALL IS NOT NULL
                AND NEW.LANGV_BALL <> OLD.LANGV_BALL
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
            (:TID, 'LANGV_BALL', OLD.LANGV_BALL, NEW.LANGV_BALL);
  
    IF (
            (
                    OLD.N_CENTRE IS NULL
                AND NEW.N_CENTRE IS NOT NULL
            )
        OR
            (
                    NEW.N_CENTRE IS NULL
                AND OLD.N_CENTRE IS NOT NULL
            )
        OR
            (
                    NEW.N_CENTRE IS NOT NULL
                AND OLD.N_CENTRE IS NOT NULL
                AND NEW.N_CENTRE <> OLD.N_CENTRE
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
            (:TID, 'N_CENTRE', OLD.N_CENTRE, NEW.N_CENTRE);
  
    IF (
            (
                    OLD.PRICE IS NULL
                AND NEW.PRICE IS NOT NULL
            )
        OR
            (
                    NEW.PRICE IS NULL
                AND OLD.PRICE IS NOT NULL
            )
        OR
            (
                    NEW.PRICE IS NOT NULL
                AND OLD.PRICE IS NOT NULL
                AND NEW.PRICE <> OLD.PRICE
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
            (:TID, 'PRICE', OLD.PRICE, NEW.PRICE);
 
  
END
^

SET TERM ; ^



/******************************************************************************/
/***                          Fields descriptions                           ***/
/******************************************************************************/

COMMENT ON COLUMN ABITURA.NOMER_AB IS 
'Инкремент';

COMMENT ON COLUMN ABITURA.FAM IS 
'Фамилия';

COMMENT ON COLUMN ABITURA.NAME IS 
'Имя';

COMMENT ON COLUMN ABITURA.OTCH IS 
'Отчество';

COMMENT ON COLUMN ABITURA.POL IS 
'Пол';

COMMENT ON COLUMN ABITURA.PLACE_R IS 
'Место рождения';

COMMENT ON COLUMN ABITURA.NAZ IS 
'Национальность';

COMMENT ON COLUMN ABITURA.ADDRESS_BEFORE IS 
'Адрес регистрации';

COMMENT ON COLUMN ABITURA.ADDRESS_LIFE IS 
'Адрес проживания';

COMMENT ON COLUMN ABITURA.MIDDLE_BALL IS 
'Средний балл аттестата';

COMMENT ON COLUMN ABITURA.NAME_EDU_MIDDLE IS 
'Название учреждения среднего образования (где получил среднее образование)';

COMMENT ON COLUMN ABITURA.NAME_EDU_SPEC IS 
'Название учреждения средне-специального образования (сверх среднего)';

COMMENT ON COLUMN ABITURA.WHERE_EDU_MIDDLE IS 
'Где окончил среднее образование';

COMMENT ON COLUMN ABITURA.WHERE_EDU_SPEC IS 
'Где окончил средне специальное';

COMMENT ON COLUMN ABITURA.WHEN_EDU_MIDDLE IS 
'Когда окончил среднее образование (год)';

COMMENT ON COLUMN ABITURA.WHEN_EDU_SPEC IS 
'Когда окончил средне-специальное обр. (год)';

COMMENT ON COLUMN ABITURA.NOM_DELA IS 
'Номер дела';

COMMENT ON COLUMN ABITURA.VID_EDU IS 
'Вид обучения:
0-дневное
1-заочное';

COMMENT ON COLUMN ABITURA.NOM_GROUP IS 
'Номер группы';

COMMENT ON COLUMN ABITURA.MAMA IS 
'ФИО мама';

COMMENT ON COLUMN ABITURA.PAPA IS 
'ФИО папа';

COMMENT ON COLUMN ABITURA.WORK_MAMA IS 
'Место работы мамы';

COMMENT ON COLUMN ABITURA.WORK_PAPA IS 
'Место работы папы';

COMMENT ON COLUMN ABITURA.GRAGDAN IS 
'Гражданство';

COMMENT ON COLUMN ABITURA.N_REGION IS 
'Связь с табл. Decanat.Region';

COMMENT ON COLUMN ABITURA.N_SPECIALIZ IS 
'Связь с таблицей SPECIALIZ - специализация (из Деканата)';

COMMENT ON COLUMN ABITURA.STATUS IS 
'Статус:
0-действующий
1-забрал документы
2-получил отрицат. оценку
3-неявка на экзамен
4-забрал документы во время экзаменов
5-зачисленный
6-онлайн зарегистрирован';

COMMENT ON COLUMN ABITURA.N_PRIVILEGE_EXAM IS 
'Связь с табл. Privilege_one_exam
1-нет привелегий';

COMMENT ON COLUMN ABITURA.SUM_BALL IS 
'Сумма полученных баллов на экз.';

COMMENT ON COLUMN ABITURA.N_FAC IS 
'Связь с таблицей Faculty (из Деканата)-факультеты
1-СИиЕ
2-МВС
3-ОФКиТ
4-ИТ';

COMMENT ON COLUMN ABITURA.N_VID_SPORT IS 
'Связь с табл. Vid_Sport (из Деканата)';

COMMENT ON COLUMN ABITURA.N_SPORT_CATEGORY IS 
'Связь с табл. Category';

COMMENT ON COLUMN ABITURA.D_PRIKAZ_INCLUDE IS 
'Дата приказа о зачислении';

COMMENT ON COLUMN ABITURA.N_PRIKAZ_INCLUDE IS 
'Номер приказа о зачислении';

COMMENT ON COLUMN ABITURA.PHONE IS 
'Телефон';

COMMENT ON COLUMN ABITURA.PHOTO IS 
'Фотография';

COMMENT ON COLUMN ABITURA.STAG IS 
'Стаж работы';

COMMENT ON COLUMN ABITURA.DATE_PRIEM IS 
'Дата подачи документов';

COMMENT ON COLUMN ABITURA.DATE_VOZVRAT IS 
'Дата возврата документов';

COMMENT ON COLUMN ABITURA.DATE_R IS 
'Дата рождения';

COMMENT ON COLUMN ABITURA.KONKURS IS 
'Конкурс для поступления:
0-общий
1-целевой
2-на 2-3 курс (убран в 2017)
3-вне конкурса3
4-без экзаменов
5-иностранцы (убран в 2017)

Стало:
0 - общий
1 - без вступительных испытаний
2 - вне конкурса
3 - целевой';

COMMENT ON COLUMN ABITURA.N_CK IS 
'Было: Связь с таблицей CK - целевой контракт
Стало: № района откуда ЦК (REGIONAL_CENTRE.N_Centre)';

COMMENT ON COLUMN ABITURA.N_FOUND IS 
'Связь с таблицей Foundatoin - основание зачисления';

COMMENT ON COLUMN ABITURA.EDUCATION IS 
'Образование:
0-Среднее
1-Среднее специальное
2-Незаконченное высшее
3-Высшее
4-Профессионально-техническое';

COMMENT ON COLUMN ABITURA.NOM_ATTEST IS 
'Номер аттестата';

COMMENT ON COLUMN ABITURA.NOM_DIPLOM IS 
'Номер диплома';

COMMENT ON COLUMN ABITURA.STAG_SPEC IS 
'Стаж работы по специальности';

COMMENT ON COLUMN ABITURA.COPY_AT IS 
'Оригинал или копия аттестата
0-оригинал
1-копия';

COMMENT ON COLUMN ABITURA.STAT_AB IS 
'Школы
3-лицей,гимназия
4-село
5-город
6-школа
7-ССУЗ, колледж
8-ВУЗ
9-ПТУ';

COMMENT ON COLUMN ABITURA.WORK_BEFORE IS 
'Работа до поступления';

COMMENT ON COLUMN ABITURA.N_SPEC IS 
'Связь с таблицей SPECIALITY -специальность (из Деканата)';

COMMENT ON COLUMN ABITURA.RUS_BEL IS 
'Русский-белорусский язык
0-русский
1-белорусский';

COMMENT ON COLUMN ABITURA.V_K IS 
'Вне конкурса:
1-Сирота
2-Дети погибших военнослужащих
3-Инвалид 1 или 2 гр.
4-(ЧАЭС ст.18) или (Кубки РБ)
5-(Лица других государств) или (2-ое в/о на 1 курс за оплату)
6- Второе высшее образование на условиях оплаты на 2 и старше курс???';

COMMENT ON COLUMN ABITURA.PRIV IS 
'1 - Выпускники УОР, пед. колледжей
2 - Выпускники профильных учебн. заведений
3 - Стаж практической работы не менее 6 месяцев по специальности
4 - Выпускники ФДП БГУФК
5 - Победители ( I степени ) 3-го этапа респ. олимпиады
6 - Победителя (I ,II, III степени) респ. олимпиады (бел. и русск. яз)
7 - МС РБ, МКМС РБ
8 - Золотая и серебряная медаль
9 - Диплом с отличием проф-тех. образ-я
10 - Диплом с отличием ССУЗ
11 - Свидетельство с отличием о баз. образ-я
12 - Подготов. отд. дневная форма (другое УВО)';

COMMENT ON COLUMN ABITURA.WITHOUT IS 
'Причина по которой без экзаменов
соответствует вкладке ''Без экзаменов'':
1 - Победители (дипломы I, II, III степени) международных олимпиад и республиканской олимпиады по учебным предметам (ТиГ география)
2 - Победители, призеры и участники Олимпийских, Паралимпийских и Дефлимпийских игр, победители и призеры Юношеских Олимпийских игр
3 - Победители и призеры чемпионатов, финалов розыгрышей кубков, первенств мира и Европы, Олимпийских фестивалей молодежи Европы
4 - Победители официальных чемпионатов Республики Беларусь, включенным в программу летних и зимних Олимпийских игр
5 - Победители и призеры чемпионатов, первенств мира и Европы среди инвалидов
6 - Второе в/о на платной основе на 2 и старшие курсы';

COMMENT ON COLUMN ABITURA.N_LANGVICH IS 
'Связь с таблицей LANGVICH
в деканате (иностранный язык)';

COMMENT ON COLUMN ABITURA.LANGV_BALL IS 
'Оценка по иностранному языку';

COMMENT ON COLUMN ABITURA.N_CENTRE IS 
'Связь с таблицей REGIONAL_CENTRE - районного центра (из Деканата)';

COMMENT ON COLUMN ABITURA.PRICE IS 
'Форма обучения:
0-бюджет
1-за оплату';

COMMENT ON COLUMN ABITURA.PASPORT IS 
'Серия и номер паспорта';

COMMENT ON COLUMN ABITURA.PERSONAL_NOMER IS 
'Личный уникальный номер паспорта';

COMMENT ON COLUMN ABITURA.DATE_V IS 
'Дата выдачи документа, удостоверяющего личность';

COMMENT ON COLUMN ABITURA.ORGAN_V IS 
'Кем выдан документ, удостоверяющий личность';

COMMENT ON COLUMN ABITURA.ID_AB_QUEUE IS 
'ID абитуриента из таблици электронной очереди ABITUR_QUEUE';

COMMENT ON COLUMN ABITURA.DIGIT_SIGN IS 
'Подпись';

COMMENT ON COLUMN ABITURA.CATEGORY_AB IS 
'Категория абитуриента:
0 - Беларусь
1 - Иностранцы
2 - СНГ
3 - ДНР/ЛНР';

COMMENT ON COLUMN ABITURA.TERM_EDU IS 
'0 - полный
1 - сокращённый 2 курс
2 - сокращённый 3 курс
3 - 1 курс (ВО)
4 - 2 курс (ВО)
5 - 3 курс (ВО)';

COMMENT ON COLUMN ABITURA.CATEGORY_IF IS 
'Условия поступления для СНГ и ДНР/ЛНР:
0 - РБ
1 - ИГ';

COMMENT ON COLUMN ABITURA.ADDRESS_PAPA IS 
'Адрес проживания отца';

COMMENT ON COLUMN ABITURA.ADDRESS_MAMA IS 
'Адрес проживания матери';

COMMENT ON COLUMN ABITURA.CITIZENSHIP IS 
'Граждпнство - ID страны из таблицы COUNTRIES (деканат)';

COMMENT ON COLUMN ABITURA.TOWN_VILLAGE IS 
'0 - город или посёлок городского типа
1 - сельский населённый пункт';

COMMENT ON COLUMN ABITURA.TYPE_SCHOOL IS 
'0 - УСО
1 - УССО
2 - ПТУ
3 - лицея, гимназии
4 - УВО';

COMMENT ON COLUMN ABITURA.ID_TYPE IS 
'Тип документа, удостоверяющего личность';

COMMENT ON COLUMN ABITURA.DATE_OK IS 
'Дата окончания срока действия документа, удоставеряющего личность';

COMMENT ON COLUMN ABITURA.DISABLED IS 
'Группа инвалидности
1- 1 группа слух
2- 1 группа зрение
3- 1 группа ОДА
4- 2 группа слух
5- 2 группа зрение
6- 2 группа ОДА
7- 3 группа слух
8- 3 группа зрение
9- 3 группа ОДА';

COMMENT ON COLUMN ABITURA.STREET IS 
'ID улицы из таблицы STREET базы Dekanat';

COMMENT ON COLUMN ABITURA.HOUSE IS 
'Дом';

COMMENT ON COLUMN ABITURA.FLAT IS 
'Квартира';

COMMENT ON COLUMN ABITURA.POSTCODE IS 
'Индекс';



/******************************************************************************/
/***                               Privileges                               ***/
/******************************************************************************/


/* Privileges of users */
GRANT ALL ON ABITURA TO ABITUR1;
GRANT ALL ON ABITURA TO ABITUR2;
GRANT ALL ON ABITURA TO ABITUR3;
GRANT ALL ON ABITURA TO ABITUR4;
GRANT ALL ON ABITURA TO ABITURA;
GRANT ALL ON ABITURA TO ALEXANDER_GONCHAROV;
GRANT ALL ON ABITURA TO ASU;
GRANT ALL ON ABITURA TO ASU1;
GRANT ALL ON ABITURA TO ASU2;
GRANT ALL ON ABITURA TO ASU3;
GRANT ALL ON ABITURA TO ASU4;
GRANT ALL ON ABITURA TO DEVELOPER;
GRANT ALL ON ABITURA TO DEVELOPER2;
GRANT ALL ON ABITURA TO IT1;
GRANT ALL ON ABITURA TO IT2;
GRANT ALL ON ABITURA TO IT3;
GRANT ALL ON ABITURA TO IVANOVA_A;
GRANT ALL ON ABITURA TO MVS1;
GRANT ALL ON ABITURA TO MVS2;
GRANT ALL ON ABITURA TO MVS3;
GRANT ALL ON ABITURA TO MVS4;
GRANT ALL ON ABITURA TO OFKIT1;
GRANT ALL ON ABITURA TO OFKIT2;
GRANT ALL ON ABITURA TO OFKIT3;
GRANT ALL ON ABITURA TO OFKIT4;
GRANT ALL ON ABITURA TO OKSANA;
GRANT ALL ON ABITURA TO PK;
GRANT ALL ON ABITURA TO PK_IT;
GRANT ALL ON ABITURA TO PK_IT1;
GRANT ALL ON ABITURA TO PK_IT2;
GRANT ALL ON ABITURA TO PK_IT3;
GRANT ALL ON ABITURA TO PK_IT4;
GRANT ALL ON ABITURA TO PK_IT5;
GRANT ALL ON ABITURA TO PK_MSTIG1;
GRANT ALL ON ABITURA TO PK_MSTIG2;
GRANT ALL ON ABITURA TO PK_MSTIG3;
GRANT ALL ON ABITURA TO PK_MSTIG4;
GRANT ALL ON ABITURA TO PK_MSTIGP1;
GRANT ALL ON ABITURA TO PK_MSTIGP2;
GRANT ALL ON ABITURA TO PK_MSTIG_1;
GRANT ALL ON ABITURA TO PK_MSTIG_2;
GRANT ALL ON ABITURA TO PK_MSTIG_3;
GRANT ALL ON ABITURA TO PK_MSTIG_4;
GRANT ALL ON ABITURA TO PK_MSTIG_P1;
GRANT ALL ON ABITURA TO PK_MSTIG_P2;
GRANT ALL ON ABITURA TO PK_MVS;
GRANT ALL ON ABITURA TO PK_MVS1;
GRANT ALL ON ABITURA TO PK_MVS2;
GRANT ALL ON ABITURA TO PK_MVS3;
GRANT ALL ON ABITURA TO PK_MVS4;
GRANT ALL ON ABITURA TO PK_MVS5;
GRANT ALL ON ABITURA TO PK_MVSP1;
GRANT ALL ON ABITURA TO PK_MVSP2;
GRANT ALL ON ABITURA TO PK_MVS_1;
GRANT ALL ON ABITURA TO PK_MVS_2;
GRANT ALL ON ABITURA TO PK_MVS_3;
GRANT ALL ON ABITURA TO PK_MVS_4;
GRANT ALL ON ABITURA TO PK_MVS_P1;
GRANT ALL ON ABITURA TO PK_MVS_P2;
GRANT ALL ON ABITURA TO PK_OFKIT;
GRANT ALL ON ABITURA TO PK_OFKIT1;
GRANT ALL ON ABITURA TO PK_OFKIT2;
GRANT ALL ON ABITURA TO PK_OFKIT3;
GRANT ALL ON ABITURA TO PK_OFKIT4;
GRANT ALL ON ABITURA TO PK_OFKIT5;
GRANT ALL ON ABITURA TO PK_OFKITP1;
GRANT ALL ON ABITURA TO PK_OFKITP2;
GRANT ALL ON ABITURA TO PK_OFK_1;
GRANT ALL ON ABITURA TO PK_OFK_2;
GRANT ALL ON ABITURA TO PK_OFK_3;
GRANT ALL ON ABITURA TO PK_OFK_4;
GRANT ALL ON ABITURA TO PK_OFK_P1;
GRANT ALL ON ABITURA TO PK_OFK_P2;
GRANT ALL ON ABITURA TO PK_OTV1;
GRANT ALL ON ABITURA TO PK_OTV2;
GRANT ALL ON ABITURA TO PK_OTV3;
GRANT ALL ON ABITURA TO PK_OTV4;
GRANT ALL ON ABITURA TO PK_SIIE;
GRANT ALL ON ABITURA TO PK_SIIE1;
GRANT ALL ON ABITURA TO PK_SIIE2;
GRANT ALL ON ABITURA TO PK_SIIE3;
GRANT ALL ON ABITURA TO PK_SIIE4;
GRANT ALL ON ABITURA TO PK_SIIE5;
GRANT ALL ON ABITURA TO PK_SIIEP1;
GRANT ALL ON ABITURA TO PK_SIIEP2;
GRANT ALL ON ABITURA TO PK_SIIEP3;
GRANT ALL ON ABITURA TO PK_SIIE_1;
GRANT ALL ON ABITURA TO PK_SIIE_2;
GRANT ALL ON ABITURA TO PK_SIIE_3;
GRANT ALL ON ABITURA TO PK_SIIE_4;
GRANT ALL ON ABITURA TO PK_SIIE_P1;
GRANT ALL ON ABITURA TO PK_SIIE_P2;
GRANT ALL ON ABITURA TO SIIE1;
GRANT ALL ON ABITURA TO SIIE2;
GRANT ALL ON ABITURA TO SIIE3;
GRANT ALL ON ABITURA TO SIIE4;
GRANT ALL ON ABITURA TO UO_LAB;
GRANT ALL ON ABITURA TO UO_N;
GRANT ALL ON ABITURA TO UO_Z;

/* Privileges of triggers */
GRANT UPDATE, REFERENCES ON ABITURA             TO TRIGGER IBE$ABITURA_AD;
GRANT UPDATE, REFERENCES ON AB_P                TO TRIGGER IBE$ABITURA_AD;
GRANT INSERT             ON IBE$LOG_BLOB_FIELDS TO TRIGGER IBE$ABITURA_AD;
GRANT INSERT             ON IBE$LOG_FIELDS      TO TRIGGER IBE$ABITURA_AD;
GRANT INSERT             ON IBE$LOG_KEYS        TO TRIGGER IBE$ABITURA_AD;
GRANT INSERT             ON IBE$LOG_TABLES      TO TRIGGER IBE$ABITURA_AD;

GRANT UPDATE, REFERENCES ON ABITURA             TO TRIGGER IBE$ABITURA_AI;
GRANT UPDATE, REFERENCES ON AB_P                TO TRIGGER IBE$ABITURA_AI;
GRANT INSERT             ON IBE$LOG_BLOB_FIELDS TO TRIGGER IBE$ABITURA_AI;
GRANT INSERT             ON IBE$LOG_FIELDS      TO TRIGGER IBE$ABITURA_AI;
GRANT INSERT             ON IBE$LOG_KEYS        TO TRIGGER IBE$ABITURA_AI;
GRANT INSERT             ON IBE$LOG_TABLES      TO TRIGGER IBE$ABITURA_AI;

GRANT UPDATE, REFERENCES ON ABITURA             TO TRIGGER IBE$ABITURA_AU;
GRANT UPDATE, REFERENCES ON AB_P                TO TRIGGER IBE$ABITURA_AU;
GRANT INSERT             ON IBE$LOG_BLOB_FIELDS TO TRIGGER IBE$ABITURA_AU;
GRANT INSERT             ON IBE$LOG_FIELDS      TO TRIGGER IBE$ABITURA_AU;
GRANT INSERT             ON IBE$LOG_KEYS        TO TRIGGER IBE$ABITURA_AU;
GRANT INSERT             ON IBE$LOG_TABLES      TO TRIGGER IBE$ABITURA_AU;