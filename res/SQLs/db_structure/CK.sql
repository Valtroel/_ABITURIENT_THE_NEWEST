CREATE TABLE IF NOT EXISTS
    CK
    (
        N_CK            SMALLINT,
        N_SPECIALIZ     SMALLINT,
        N_REGION        SMALLINT,
        TEXT_DEP        VARCHAR(30) COLLATE PXW_CYRL,
        KOL_P           SMALLINT,
        CUSTOMER_PLACE  VARCHAR(50) COLLATE PXW_CYRL,
        N_FAC           SMALLINT,
        N_CENTRE        INTEGER,
        CUSTOMER        SMALLINT,
        TERM_EDUC       SMALLINT
    );




/******************************************************************************/
/***                              Primary keys                              ***/
/******************************************************************************/

ALTER TABLE
    CK
ADD
    PRIMARY KEY
        (N_CK);


/******************************************************************************/
/***                                Indices                                 ***/
/******************************************************************************/

CREATE INDEX
    CK_CENTRE
ON
    CK
    (
        N_CENTRE
    );

CREATE INDEX
    CK_FAC
ON
    CK
    (
        N_FAC
    );

CREATE INDEX
    CK_FAC_SPECIALIZ
ON
    CK
    (
        N_FAC,
        N_SPECIALIZ
    );

CREATE INDEX
    CK_REGION
ON
    CK
    (
        N_REGION
    );

CREATE INDEX
    CK_SPECIALIZ
ON
    CK
    (
        N_SPECIALIZ
    );

CREATE INDEX
    CK_TEXT_DEP
ON 
    CK
    (
        TEXT_DEP
    );


/******************************************************************************/
/***                                Triggers                                ***/
/******************************************************************************/



SET TERM ^ ;



/******************************************************************************/
/***                          Triggers for tables                           ***/
/******************************************************************************/



/* Trigger: TI_CK */
CREATE OR ALTER TRIGGER TI_CK FOR CK
ACTIVE BEFORE INSERT POSITION 0
AS
BEGIN
NEW.N_CK=GEN_ID(CK_N_CK,1);
END
^

SET TERM ; ^



/******************************************************************************/
/***                          Fields descriptions                           ***/
/******************************************************************************/

COMMENT ON COLUMN CK.N_CENTRE IS 
'Инкремент района';

COMMENT ON COLUMN CK.CUSTOMER IS 
'0 - ОФК
1 - МО';

COMMENT ON COLUMN CK.TERM_EDUC IS 
'0 - полный срок
1 - сокращённый';



/******************************************************************************/
/***                               Privileges                               ***/
/******************************************************************************/


/* Privileges of users */
GRANT ALL ON CK TO ABITUR1;
GRANT ALL ON CK TO ABITUR2;
GRANT ALL ON CK TO ABITUR3;
GRANT ALL ON CK TO ABITUR4;
GRANT ALL ON CK TO ABITURA;
GRANT ALL ON CK TO ALEXANDER_GONCHAROV;
GRANT ALL ON CK TO ASU;
GRANT ALL ON CK TO ASU1;
GRANT ALL ON CK TO ASU2;
GRANT ALL ON CK TO ASU3;
GRANT ALL ON CK TO ASU4;
GRANT ALL ON CK TO DEVELOPER;
GRANT ALL ON CK TO DEVELOPER2;
GRANT ALL ON CK TO IT1;
GRANT ALL ON CK TO IT2;
GRANT ALL ON CK TO IT3;
GRANT ALL ON CK TO IVANOVA_A;
GRANT ALL ON CK TO MVS1;
GRANT ALL ON CK TO MVS2;
GRANT ALL ON CK TO MVS3;
GRANT ALL ON CK TO MVS4;
GRANT ALL ON CK TO OFKIT1;
GRANT ALL ON CK TO OFKIT2;
GRANT ALL ON CK TO OFKIT3;
GRANT ALL ON CK TO OFKIT4;
GRANT ALL ON CK TO OKSANA;
GRANT ALL ON CK TO PK;
GRANT ALL ON CK TO PK_IT;
GRANT ALL ON CK TO PK_IT1;
GRANT ALL ON CK TO PK_IT2;
GRANT ALL ON CK TO PK_IT3;
GRANT ALL ON CK TO PK_IT4;
GRANT ALL ON CK TO PK_IT5;
GRANT ALL ON CK TO PK_MSTIG1;
GRANT ALL ON CK TO PK_MSTIG2;
GRANT ALL ON CK TO PK_MSTIG3;
GRANT ALL ON CK TO PK_MSTIG4;
GRANT ALL ON CK TO PK_MSTIGP1;
GRANT ALL ON CK TO PK_MSTIGP2;
GRANT ALL ON CK TO PK_MSTIG_1;
GRANT ALL ON CK TO PK_MSTIG_2;
GRANT ALL ON CK TO PK_MSTIG_3;
GRANT ALL ON CK TO PK_MSTIG_4;
GRANT ALL ON CK TO PK_MSTIG_P1;
GRANT ALL ON CK TO PK_MSTIG_P2;
GRANT ALL ON CK TO PK_MVS;
GRANT ALL ON CK TO PK_MVS1;
GRANT ALL ON CK TO PK_MVS2;
GRANT ALL ON CK TO PK_MVS3;
GRANT ALL ON CK TO PK_MVS4;
GRANT ALL ON CK TO PK_MVS5;
GRANT ALL ON CK TO PK_MVSP1;
GRANT ALL ON CK TO PK_MVSP2;
GRANT ALL ON CK TO PK_MVS_1;
GRANT ALL ON CK TO PK_MVS_2;
GRANT ALL ON CK TO PK_MVS_3;
GRANT ALL ON CK TO PK_MVS_4;
GRANT ALL ON CK TO PK_MVS_P1;
GRANT ALL ON CK TO PK_MVS_P2;
GRANT ALL ON CK TO PK_OFKIT;
GRANT ALL ON CK TO PK_OFKIT1;
GRANT ALL ON CK TO PK_OFKIT2;
GRANT ALL ON CK TO PK_OFKIT3;
GRANT ALL ON CK TO PK_OFKIT4;
GRANT ALL ON CK TO PK_OFKIT5;
GRANT ALL ON CK TO PK_OFKITP1;
GRANT ALL ON CK TO PK_OFKITP2;
GRANT ALL ON CK TO PK_OFK_1;
GRANT ALL ON CK TO PK_OFK_2;
GRANT ALL ON CK TO PK_OFK_3;
GRANT ALL ON CK TO PK_OFK_4;
GRANT ALL ON CK TO PK_OFK_P1;
GRANT ALL ON CK TO PK_OFK_P2;
GRANT ALL ON CK TO PK_OTV1;
GRANT ALL ON CK TO PK_OTV2;
GRANT ALL ON CK TO PK_OTV3;
GRANT ALL ON CK TO PK_OTV4;
GRANT ALL ON CK TO PK_SIIE;
GRANT ALL ON CK TO PK_SIIE1;
GRANT ALL ON CK TO PK_SIIE2;
GRANT ALL ON CK TO PK_SIIE3;
GRANT ALL ON CK TO PK_SIIE4;
GRANT ALL ON CK TO PK_SIIE5;
GRANT ALL ON CK TO PK_SIIEP1;
GRANT ALL ON CK TO PK_SIIEP2;
GRANT ALL ON CK TO PK_SIIEP3;
GRANT ALL ON CK TO PK_SIIE_1;
GRANT ALL ON CK TO PK_SIIE_2;
GRANT ALL ON CK TO PK_SIIE_3;
GRANT ALL ON CK TO PK_SIIE_4;
GRANT ALL ON CK TO PK_SIIE_P1;
GRANT ALL ON CK TO PK_SIIE_P2;
GRANT ALL ON CK TO SIIE1;
GRANT ALL ON CK TO SIIE2;
GRANT ALL ON CK TO SIIE3;
GRANT ALL ON CK TO SIIE4;
GRANT ALL ON CK TO UO_LAB;
GRANT ALL ON CK TO UO_N;
GRANT ALL ON CK TO UO_Z;