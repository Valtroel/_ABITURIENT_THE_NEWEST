INSERT INTO OR UPDATE
    MARITAL_STATUS
    (
        MARITAL_ID,
        STATUS,
        GENDER_ID
    )
VALUES
    (1, '������', 1) MATCHING (MARITAL_ID),
    (2, '�����', 1) MATCHING (MARITAL_ID),
    (3, '��������', 1) MATCHING (MARITAL_ID),
    (4, '������', 1) MATCHING (MARITAL_ID),
    (5, '�� �������', 2) MATCHING (MARITAL_ID),
    (6, '�������', 2) MATCHING (MARITAL_ID),
    (7, '���������', 2) MATCHING (MARITAL_ID),
    (8, '�����', 2) MATCHING (MARITAL_ID);

COMMIT WORK;