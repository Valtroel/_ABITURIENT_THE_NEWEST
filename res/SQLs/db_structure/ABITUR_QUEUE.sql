CREATE GENERATOR
    GEN_ABITUR_QUEUE_ID;


CREATE TABLE IF NOT EXISTS
ABITUR_QUEUE
(
    ID_AB         INTEGER,
    FAM           VARCHAR(30)   COLLATE     PXW_CYRL,
    NAME          VARCHAR(30)   COLLATE     PXW_CYRL,
    OTCH          VARCHAR(30)   COLLATE     PXW_CYRL,
    STATUS_QUEUE  SMALLINT      DEFAULT  0,
    PHOTO         BLOB          SUB_TYPE 0  SEGMENT SIZE 80,
    DIGIT_SIGN    BLOB          SUB_TYPE 0  SEGMENT SIZE 80,
    N_FAC         SMALLINT      DEFAULT  0,
    NOMER_QUEUE   SMALLINT      DEFAULT  0,
    TIME_QUEUE    DATE,
    N_SPECIALIZ   SMALLINT      DEFAULT  -1,
    N_SPEC        SMALLINT      DEFAULT  -1,
    VID_EDU       SMALLINT      DEFAULT  -1,
    CATEGORY_AB   SMALLINT      DEFAULT  -1,
    CATEGORY_IF   SMALLINT      DEFAULT  -1,
    CATEGORY_EDU  SMALLINT      DEFAULT  -1,
    TERM_EDU      SMALLINT      DEFAULT  -1,
    PRICE         SMALLINT      DEFAULT  -1,
    KONKURS       SMALLINT      DEFAULT  -1,
    DATE_TIME_ID  SMALLINT
);



/******************************************************************************/
/***                              Primary keys                              ***/
/******************************************************************************/

ALTER TABLE
    ABITUR_QUEUE
ADD
    CONSTRAINT
        PK_ABITUR_QUEUE
    PRIMARY KEY
        (ID_AB);


/******************************************************************************/
/***                                Triggers                                ***/
/******************************************************************************/



SET TERM ^ ;



/******************************************************************************/
/***                          Triggers for tables                           ***/
/******************************************************************************/



/* Trigger: ABITUR_QUEUE_BI (Before INSERT)*/
CREATE OR ALTER
    TRIGGER
        ABITUR_QUEUE_BI
FOR
    ABITUR_QUEUE
ACTIVE
    BEFORE INSERT
        POSITION 0
AS
BEGIN
    IF (NEW.ID_AB IS NULL)
    THEN
        NEW.ID_AB = GEN_ID(GEN_ABITUR_QUEUE_ID, 1);
END
^

SET TERM ; ^



/******************************************************************************/
/***                          Fields descriptions                           ***/
/******************************************************************************/

/* UNCOMMENT QUERIES BELOW FOR MySQL */
/*
ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    STATUS_QUEUE SMALLINT
COMMENT
    'Статус в очереди
    100 - сфотографирован, введены имя, фамилия и отчество
    101 - с фото и подписью в очередь к столу справок
    102 - в очередь на факультеты после стола справок
    103 - вызван
    104 - декан разрешил сохраненить в ABITURA (должен увидеть оператор)
    105 - сохранён в ABITURA
    201 - забирать документы - в очередь после стола справок
    202 - декан разрешил забрать документы (должен увидеть оператор)
    203 - забрал документы - стол справок видит
    299 - прошёл регистрацию online
    300 - прошёл регистрацию online, сфотографирован, введены имя, фамилия и отчество
    301 - прошёл регистрацию online, с фото и подписью в очередь к столу справок
    302 - прошёл регистрацию online, в очередь на факультеты после стола справок
    304 - прошёл регистрацию online, декан разрешил сохраненить в ABITURA (должен увидеть оператор)';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    PHOTO BLOB
COMMENT
    'Фото';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    DIGIT_SIGN BLOB
COMMENT
    'Подпись';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    N_FAC SMALLINT
COMMENT
    'Номер факультета';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    NOMER_QUEUE SMALLINT
COMMENT
    'Номер в очереди';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    TIME_QUEUE DATE
COMMENT
    'Время постановки в очередь';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    N_SPECIALIZ SMALLINT
COMMENT
    'Направление специализации';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    N_SPEC SMALLINT
COMMENT
    'Специальность';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    VID_EDU SMALLINT
COMMENT
    'Форма обучения:
    0 - дневная
    1 - заочная';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    CATEGORY_AB SMALLINT
COMMENT
    'Категория абитуриента:
    0 - Беларусь
    1 - Иностранцы
    2 - СНГ
    3 - ДНР/ЛНР';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    CATEGORY_IF SMALLINT
COMMENT
    'Условия поступления для СНГ и ДНР/ЛНР:
    0 - РБ
    1 - ИГ';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    CATEGORY_EDU SMALLINT
COMMENT
    'Образование:
    0 - среднее
    1 - среднее специальное
    2 - незаконченное высшее
    3 - высшее
    4 - профессионально-техническое';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    TERM_EDU SMALLINT
COMMENT
    '0 - полный
    1 - сокращённый  2 курс (ССО)
    2 - сокращённый  3 курс (ССО)
    3 - 1 курс (ВО)
    4 - 2 курс (ВО)
    5 - 3 курс (ВО)';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    PRICE SMALLINT
COMMENT
    'Форма оплаты:
    0 - бюджет
    1 - за оплату';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    KONKURS SMALLINT
COMMENT
    '0 - общий
    1 - без вступительных испытаний
    2 - вне конкурса
    3 - целевой';

ALTER TABLE
    ABITUR_QUEUE
MODIFY COLUMN
    DATE_TIME_ID SMALLINT
COMMENT
    'Дата и время выбранные онлайн';
*/





/* UNCOMMENT QUERIES BELOW FOR Firebird OR SQL */
/*
COMMENT ON COLUMN
    ABITUR_QUEUE.STATUS_QUEUE
IS 
    'Статус в очереди
    100 - сфотографирован, введены имя, фамилия и отчество
    101 - с фото и подписью в очередь к столу справок
    102 - в очередь на факультеты после стола справок
    103 - вызван
    104 - декан разрешил сохраненить в ABITURA (должен увидеть оператор)
    105 - сохранён в ABITURA
    201 - забирать документы - в очередь после стола справок
    202 - декан разрешил забрать документы (должен увидеть оператор)
    203 - забрал документы - стол справок видит
    299 - прошёл регистрацию online
    300 - прошёл регистрацию online, сфотографирован, введены имя, фамилия и отчество
    301 - прошёл регистрацию online, с фото и подписью в очередь к столу справок
    302 - прошёл регистрацию online, в очередь на факультеты после стола справок
    304 - прошёл регистрацию online, декан разрешил сохраненить в ABITURA (должен увидеть оператор)';

COMMENT ON COLUMN
    ABITUR_QUEUE.PHOTO
IS 
    'Фото';

COMMENT ON COLUMN
    ABITUR_QUEUE.DIGIT_SIGN
IS 
    'Подпись';
    
COMMENT ON COLUMN
    ABITUR_QUEUE.N_FAC
IS 
    'Номер факультета';

COMMENT ON COLUMN
    ABITUR_QUEUE.NOMER_QUEUE
IS
    'Номер в очереди';

COMMENT ON COLUMN
    ABITUR_QUEUE.TIME_QUEUE
IS
    'Время постановки в очередь';

COMMENT ON COLUMN
    ABITUR_QUEUE.N_SPECIALIZ
IS
    'Направление специализации';

COMMENT ON COLUMN
    ABITUR_QUEUE.N_SPEC
IS
    'Специальность';

COMMENT ON COLUMN
    ABITUR_QUEUE.VID_EDU
IS
    'Форма обучения:
    0 - дневная
    1 - заочная';

COMMENT ON COLUMN
    ABITUR_QUEUE.CATEGORY_AB
IS
    'Категория абитуриента:
    0 - Беларусь
    1 - Иностранцы
    2 - СНГ
    3 - ДНР/ЛНР';

COMMENT ON COLUMN
    ABITUR_QUEUE.CATEGORY_IF
IS
    'Условия поступления для СНГ и ДНР/ЛНР:
    0 - РБ
    1 - ИГ';

COMMENT ON COLUMN
    ABITUR_QUEUE.CATEGORY_EDU
IS
    'Образование:
    0 - среднее
    1 - среднее специальное
    2 - незаконченное высшее
    3 - высшее
    4 - профессионально-техническое';

COMMENT ON COLUMN
    ABITUR_QUEUE.TERM_EDU
IS
    '0 - полный
    1 - сокращённый  2 курс (ССО)
    2 - сокращённый  3 курс (ССО)
    3 - 1 курс (ВО)
    4 - 2 курс (ВО)
    5 - 3 курс (ВО)';

COMMENT ON COLUMN
    ABITUR_QUEUE.PRICE
IS 
    'Форма оплаты:
    0 - бюджет
    1 - за оплату';

COMMENT ON COLUMN
    ABITUR_QUEUE.KONKURS
IS 
    '0 - общий
    1 - без вступительных испытаний
    2 - вне конкурса
    3 - целевой';

COMMENT ON COLUMN
    ABITUR_QUEUE.DATE_TIME_ID
IS 
    'Дата и время выбранные онлайн';
*/


/******************************************************************************/
/***                               Privileges                               ***/
/******************************************************************************/


/* Privileges of users */
GRANT ALL ON ABITUR_QUEUE TO ABITUR1;
GRANT ALL ON ABITUR_QUEUE TO ABITUR2;
GRANT ALL ON ABITUR_QUEUE TO ABITUR3;
GRANT ALL ON ABITUR_QUEUE TO ABITUR4;
GRANT ALL ON ABITUR_QUEUE TO ABITURA;
GRANT ALL ON ABITUR_QUEUE TO ALEXANDER_GONCHAROV;
GRANT ALL ON ABITUR_QUEUE TO ASU;
GRANT ALL ON ABITUR_QUEUE TO ASU1;
GRANT ALL ON ABITUR_QUEUE TO ASU2;
GRANT ALL ON ABITUR_QUEUE TO ASU3;
GRANT ALL ON ABITUR_QUEUE TO ASU4;
GRANT ALL ON ABITUR_QUEUE TO DEVELOPER;
GRANT ALL ON ABITUR_QUEUE TO IVANOVA_A;
GRANT ALL ON ABITUR_QUEUE TO OKSANA;
GRANT ALL ON ABITUR_QUEUE TO PK;
GRANT ALL ON ABITUR_QUEUE TO PK_IT;
GRANT ALL ON ABITUR_QUEUE TO PK_IT1;
GRANT ALL ON ABITUR_QUEUE TO PK_IT2;
GRANT ALL ON ABITUR_QUEUE TO PK_IT3;
GRANT ALL ON ABITUR_QUEUE TO PK_IT4;
GRANT ALL ON ABITUR_QUEUE TO PK_IT5;
GRANT ALL ON ABITUR_QUEUE TO PK_MSTIG1;
GRANT ALL ON ABITUR_QUEUE TO PK_MSTIG2;
GRANT ALL ON ABITUR_QUEUE TO PK_MSTIG3;
GRANT ALL ON ABITUR_QUEUE TO PK_MSTIG4;
GRANT ALL ON ABITUR_QUEUE TO PK_MSTIGP1;
GRANT ALL ON ABITUR_QUEUE TO PK_MSTIGP2;
GRANT ALL ON ABITUR_QUEUE TO PK_MSTIG_1;
GRANT ALL ON ABITUR_QUEUE TO PK_MSTIG_2;
GRANT ALL ON ABITUR_QUEUE TO PK_MSTIG_3;
GRANT ALL ON ABITUR_QUEUE TO PK_MSTIG_4;
GRANT ALL ON ABITUR_QUEUE TO PK_MSTIG_P1;
GRANT ALL ON ABITUR_QUEUE TO PK_MSTIG_P2;
GRANT ALL ON ABITUR_QUEUE TO PK_MVS;
GRANT ALL ON ABITUR_QUEUE TO PK_MVS1;
GRANT ALL ON ABITUR_QUEUE TO PK_MVS2;
GRANT ALL ON ABITUR_QUEUE TO PK_MVS3;
GRANT ALL ON ABITUR_QUEUE TO PK_MVS4;
GRANT ALL ON ABITUR_QUEUE TO PK_MVS5;
GRANT ALL ON ABITUR_QUEUE TO PK_MVSP1;
GRANT ALL ON ABITUR_QUEUE TO PK_MVSP2;
GRANT ALL ON ABITUR_QUEUE TO PK_MVS_1;
GRANT ALL ON ABITUR_QUEUE TO PK_MVS_2;
GRANT ALL ON ABITUR_QUEUE TO PK_MVS_3;
GRANT ALL ON ABITUR_QUEUE TO PK_MVS_4;
GRANT ALL ON ABITUR_QUEUE TO PK_MVS_P1;
GRANT ALL ON ABITUR_QUEUE TO PK_MVS_P2;
GRANT ALL ON ABITUR_QUEUE TO PK_OFKIT;
GRANT ALL ON ABITUR_QUEUE TO PK_OFKIT1;
GRANT ALL ON ABITUR_QUEUE TO PK_OFKIT2;
GRANT ALL ON ABITUR_QUEUE TO PK_OFKIT3;
GRANT ALL ON ABITUR_QUEUE TO PK_OFKIT4;
GRANT ALL ON ABITUR_QUEUE TO PK_OFKIT5;
GRANT ALL ON ABITUR_QUEUE TO PK_OFKITP1;
GRANT ALL ON ABITUR_QUEUE TO PK_OFKITP2;
GRANT ALL ON ABITUR_QUEUE TO PK_OFK_1;
GRANT ALL ON ABITUR_QUEUE TO PK_OFK_2;
GRANT ALL ON ABITUR_QUEUE TO PK_OFK_3;
GRANT ALL ON ABITUR_QUEUE TO PK_OFK_4;
GRANT ALL ON ABITUR_QUEUE TO PK_OFK_P1;
GRANT ALL ON ABITUR_QUEUE TO PK_OFK_P2;
GRANT ALL ON ABITUR_QUEUE TO PK_OTV1;
GRANT ALL ON ABITUR_QUEUE TO PK_OTV2;
GRANT ALL ON ABITUR_QUEUE TO PK_OTV3;
GRANT ALL ON ABITUR_QUEUE TO PK_OTV4;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIE;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIE1;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIE2;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIE3;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIE4;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIE5;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIEP1;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIEP2;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIEP3;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIE_1;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIE_2;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIE_3;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIE_4;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIE_P1;
GRANT ALL ON ABITUR_QUEUE TO PK_SIIE_P2;