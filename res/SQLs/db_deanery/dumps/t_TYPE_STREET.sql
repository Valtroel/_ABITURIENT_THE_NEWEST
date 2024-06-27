INSERT INTO OR UPDATE
    TYPE_STREET
    (
        ID,
        TYPE,
        SHORT_TYPE
    )
VALUES
    (0, '-', NULL) MATCHING (ID),
    (1, '�����', '��.') MATCHING (ID),
    (2, '��������', '���.') MATCHING (ID),
    (3, '������', '��-�') MATCHING (ID),
    (4, '��������', '��.') MATCHING (ID),
    (5, '�����', '��.') MATCHING (ID),
    (6, '�������', '�-�') MATCHING (ID),
    (7, '�����', '���.') MATCHING (ID),
    (8, '�������', '��.') MATCHING (ID),
    (10, '����������', '���.') MATCHING (ID),
    (11, '�������', '���.') MATCHING (ID),
    (12, '�����', '�����') MATCHING (ID),
    (13, '����������', '���.') MATCHING (ID),
    (14, '����', '����') MATCHING (ID),
    (15, '�������', '��.') MATCHING (ID),
    (16, '����������', '���-�') MATCHING (ID),
    (18, '�������', '�������') MATCHING (ID),
    (999, '������', NULL) MATCHING (ID);

COMMIT WORK;