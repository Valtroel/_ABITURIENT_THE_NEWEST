INSERT INTO OR UPDATE
    EDU_LEVEL
    (
        ID,
        NAME
    )
VALUES
    (1, '������������') MATCHING (ID),
    (2, '�����������') MATCHING (ID),
    (3, '������������') MATCHING (ID);

COMMIT WORK;