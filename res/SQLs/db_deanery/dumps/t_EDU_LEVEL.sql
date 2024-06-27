INSERT INTO OR UPDATE
    EDU_LEVEL
    (
        ID,
        NAME
    )
VALUES
    (1, 'Магистратура') MATCHING (ID),
    (2, 'Аспирантура') MATCHING (ID),
    (3, 'Докторантура') MATCHING (ID);

COMMIT WORK;