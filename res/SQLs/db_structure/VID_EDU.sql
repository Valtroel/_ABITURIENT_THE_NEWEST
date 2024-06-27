CREATE TABLE IF NOT EXISTS
VID_EDU
(
    ID_VID_EDU  SMALLINT NOT NULL,
    VID_EDU     VARCHAR(10)
);




/******************************************************************************/
/***                              Primary keys                              ***/
/******************************************************************************/

ALTER TABLE
    VID_EDU
ADD
    CONSTRAINT
        PK_VID_EDU
    PRIMARY KEY
        (ID_VID_EDU);


/******************************************************************************/
/***                               Privileges                               ***/
/******************************************************************************/


/* Privileges of users */
GRANT ALL ON VID_EDU TO DEVELOPER;
GRANT ALL ON VID_EDU TO PK_MSTIG_1;
GRANT ALL ON VID_EDU TO PK_MSTIG_2;
GRANT ALL ON VID_EDU TO PK_MSTIG_3;
GRANT ALL ON VID_EDU TO PK_MSTIG_4;
GRANT ALL ON VID_EDU TO PK_MSTIG_P1;
GRANT ALL ON VID_EDU TO PK_MSTIG_P2;
GRANT ALL ON VID_EDU TO PK_MVS_1;
GRANT ALL ON VID_EDU TO PK_MVS_2;
GRANT ALL ON VID_EDU TO PK_MVS_3;
GRANT ALL ON VID_EDU TO PK_MVS_4;
GRANT ALL ON VID_EDU TO PK_MVS_P1;
GRANT ALL ON VID_EDU TO PK_MVS_P2;
GRANT ALL ON VID_EDU TO PK_OFK_1;
GRANT ALL ON VID_EDU TO PK_OFK_2;
GRANT ALL ON VID_EDU TO PK_OFK_3;
GRANT ALL ON VID_EDU TO PK_OFK_4;
GRANT ALL ON VID_EDU TO PK_OFK_P1;
GRANT ALL ON VID_EDU TO PK_OFK_P2;
GRANT ALL ON VID_EDU TO PK_OTV1;
GRANT ALL ON VID_EDU TO PK_OTV2;
GRANT ALL ON VID_EDU TO PK_OTV3;
GRANT ALL ON VID_EDU TO PK_OTV4;
GRANT ALL ON VID_EDU TO PK_SIIE_1;
GRANT ALL ON VID_EDU TO PK_SIIE_2;
GRANT ALL ON VID_EDU TO PK_SIIE_3;
GRANT ALL ON VID_EDU TO PK_SIIE_4;
GRANT ALL ON VID_EDU TO PK_SIIE_P1;
GRANT ALL ON VID_EDU TO PK_SIIE_P2;