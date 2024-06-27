CREATE GENERATOR
    GEN_BLOCK_EDIT_ID;

CREATE TABLE IF NOT EXISTS
    BLOCK_EDIT
    (
        ID_BLOCK          INTEGER,
        N_FAC             SMALLINT,
        ADD_ABITUR        SMALLINT,
        TOOK_DOC1         SMALLINT,
        TOOK_DOC2         SMALLINT,
        RE_INSIDE_FAC     SMALLINT,
        RESTOR_LIST       SMALLINT,
        BLOCK             SMALLINT,
        PEREPODACHA       INTEGER,
        NOTE              VARCHAR(255),
        NOTE_PEREPODACHA  VARCHAR(100) COLLATE PXW_CYRL
    );




/******************************************************************************/
/***                              Primary keys                              ***/
/******************************************************************************/

ALTER TABLE
    BLOCK_EDIT
ADD
    CONSTRAINT
        PK_BLOCK_EDIT
    PRIMARY KEY
        (ID_BLOCK);


/******************************************************************************/
/***                                Triggers                                ***/
/******************************************************************************/



SET TERM ^ ;



/******************************************************************************/
/***                          Triggers for tables                           ***/
/******************************************************************************/



/* Trigger: BLOCK_EDIT_BI */
CREATE OR ALTER TRIGGER BLOCK_EDIT_BI FOR BLOCK_EDIT
ACTIVE BEFORE INSERT POSITION 0
as
begin
  if (new.id_block is null) then
    new.id_block = gen_id(gen_block_edit_id,1);
end
^

SET TERM ; ^



/******************************************************************************/
/***                          Fields descriptions                           ***/
/******************************************************************************/

COMMENT ON COLUMN BLOCK_EDIT.ADD_ABITUR IS 
'Кнопка добавить нового абитуриента (AddBtBtn)
0 - доступна
1- не доступна';

COMMENT ON COLUMN BLOCK_EDIT.TOOK_DOC1 IS 
'Забрал документы до окончания приёма документов (TookDocBtBtn1)
0 - доступна
1- не доступна';

COMMENT ON COLUMN BLOCK_EDIT.TOOK_DOC2 IS 
'Забрал документы во время экзаменов (TookDocBtBtn2)
0 - доступна
1- не доступна';

COMMENT ON COLUMN BLOCK_EDIT.RE_INSIDE_FAC IS 
'Переподача документов внутри факультета (ReInsideFacBtBtn)
0 - доступна
1- не доступна';

COMMENT ON COLUMN BLOCK_EDIT.RESTOR_LIST IS 
'Восстановить в списке (RestorlistBtBtn)
0 - доступна
1- не доступна';

COMMENT ON COLUMN BLOCK_EDIT.BLOCK IS 
'запрет внесения изменений
0 - разрешено
1 - запрещено';

COMMENT ON COLUMN BLOCK_EDIT.PEREPODACHA IS 
'запрет на переподачу документов
0 - разрешено
1 - запрещено';

COMMENT ON COLUMN BLOCK_EDIT.NOTE IS 
'изменение основных данных';



/******************************************************************************/
/***                               Privileges                               ***/
/******************************************************************************/


/* Privileges of users */
GRANT ALL ON BLOCK_EDIT TO ABITUR1;
GRANT ALL ON BLOCK_EDIT TO ABITUR2;
GRANT ALL ON BLOCK_EDIT TO ABITUR3;
GRANT ALL ON BLOCK_EDIT TO ABITUR4;
GRANT ALL ON BLOCK_EDIT TO ABITURA;
GRANT ALL ON BLOCK_EDIT TO ALEXANDER_GONCHAROV;
GRANT ALL ON BLOCK_EDIT TO ASU;
GRANT ALL ON BLOCK_EDIT TO ASU1;
GRANT ALL ON BLOCK_EDIT TO ASU2;
GRANT ALL ON BLOCK_EDIT TO ASU3;
GRANT ALL ON BLOCK_EDIT TO ASU4;
GRANT ALL ON BLOCK_EDIT TO DEVELOPER;
GRANT ALL ON BLOCK_EDIT TO DEVELOPER2;
GRANT ALL ON BLOCK_EDIT TO IVANOVA_A;
GRANT ALL ON BLOCK_EDIT TO OKSANA;
GRANT ALL ON BLOCK_EDIT TO PK;
GRANT ALL ON BLOCK_EDIT TO PK_IT;
GRANT ALL ON BLOCK_EDIT TO PK_IT1;
GRANT ALL ON BLOCK_EDIT TO PK_IT2;
GRANT ALL ON BLOCK_EDIT TO PK_IT3;
GRANT ALL ON BLOCK_EDIT TO PK_IT4;
GRANT ALL ON BLOCK_EDIT TO PK_IT5;
GRANT ALL ON BLOCK_EDIT TO PK_MSTIG1;
GRANT ALL ON BLOCK_EDIT TO PK_MSTIG2;
GRANT ALL ON BLOCK_EDIT TO PK_MSTIG3;
GRANT ALL ON BLOCK_EDIT TO PK_MSTIG4;
GRANT ALL ON BLOCK_EDIT TO PK_MSTIGP1;
GRANT ALL ON BLOCK_EDIT TO PK_MSTIGP2;
GRANT ALL ON BLOCK_EDIT TO PK_MSTIG_1;
GRANT ALL ON BLOCK_EDIT TO PK_MSTIG_2;
GRANT ALL ON BLOCK_EDIT TO PK_MSTIG_3;
GRANT ALL ON BLOCK_EDIT TO PK_MSTIG_4;
GRANT ALL ON BLOCK_EDIT TO PK_MSTIG_P1;
GRANT ALL ON BLOCK_EDIT TO PK_MSTIG_P2;
GRANT ALL ON BLOCK_EDIT TO PK_MVS;
GRANT ALL ON BLOCK_EDIT TO PK_MVS1;
GRANT ALL ON BLOCK_EDIT TO PK_MVS2;
GRANT ALL ON BLOCK_EDIT TO PK_MVS3;
GRANT ALL ON BLOCK_EDIT TO PK_MVS4;
GRANT ALL ON BLOCK_EDIT TO PK_MVS5;
GRANT ALL ON BLOCK_EDIT TO PK_MVSP1;
GRANT ALL ON BLOCK_EDIT TO PK_MVSP2;
GRANT ALL ON BLOCK_EDIT TO PK_MVS_1;
GRANT ALL ON BLOCK_EDIT TO PK_MVS_2;
GRANT ALL ON BLOCK_EDIT TO PK_MVS_3;
GRANT ALL ON BLOCK_EDIT TO PK_MVS_4;
GRANT ALL ON BLOCK_EDIT TO PK_MVS_P1;
GRANT ALL ON BLOCK_EDIT TO PK_MVS_P2;
GRANT ALL ON BLOCK_EDIT TO PK_OFKIT;
GRANT ALL ON BLOCK_EDIT TO PK_OFKIT1;
GRANT ALL ON BLOCK_EDIT TO PK_OFKIT2;
GRANT ALL ON BLOCK_EDIT TO PK_OFKIT3;
GRANT ALL ON BLOCK_EDIT TO PK_OFKIT4;
GRANT ALL ON BLOCK_EDIT TO PK_OFKIT5;
GRANT ALL ON BLOCK_EDIT TO PK_OFKITP1;
GRANT ALL ON BLOCK_EDIT TO PK_OFKITP2;
GRANT ALL ON BLOCK_EDIT TO PK_OFK_1;
GRANT ALL ON BLOCK_EDIT TO PK_OFK_2;
GRANT ALL ON BLOCK_EDIT TO PK_OFK_3;
GRANT ALL ON BLOCK_EDIT TO PK_OFK_4;
GRANT ALL ON BLOCK_EDIT TO PK_OFK_P1;
GRANT ALL ON BLOCK_EDIT TO PK_OFK_P2;
GRANT ALL ON BLOCK_EDIT TO PK_OTV1;
GRANT ALL ON BLOCK_EDIT TO PK_OTV2;
GRANT ALL ON BLOCK_EDIT TO PK_OTV3;
GRANT ALL ON BLOCK_EDIT TO PK_OTV4;
GRANT ALL ON BLOCK_EDIT TO PK_SIIE;
GRANT ALL ON BLOCK_EDIT TO PK_SIIE1;
GRANT ALL ON BLOCK_EDIT TO PK_SIIE2;
GRANT ALL ON BLOCK_EDIT TO PK_SIIE3;
GRANT ALL ON BLOCK_EDIT TO PK_SIIE4;
GRANT ALL ON BLOCK_EDIT TO PK_SIIE5;
GRANT ALL ON BLOCK_EDIT TO PK_SIIEP1;
GRANT ALL ON BLOCK_EDIT TO PK_SIIEP2;
GRANT ALL ON BLOCK_EDIT TO PK_SIIEP3;
GRANT ALL ON BLOCK_EDIT TO PK_SIIE_1;
GRANT ALL ON BLOCK_EDIT TO PK_SIIE_2;
GRANT ALL ON BLOCK_EDIT TO PK_SIIE_3;
GRANT ALL ON BLOCK_EDIT TO PK_SIIE_4;
GRANT ALL ON BLOCK_EDIT TO PK_SIIE_P1;
GRANT ALL ON BLOCK_EDIT TO PK_SIIE_P2;