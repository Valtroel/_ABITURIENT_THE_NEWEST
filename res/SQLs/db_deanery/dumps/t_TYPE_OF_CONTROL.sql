INSERT INTO OR UPDATE
    TYPE_OF_CONTROL
    (
        TYPE_ID,
        TYPE_NAME
    )
VALUES
    (0, '��� ���� ��������') MATCHING (TYPE_ID),
    (1, '�����') MATCHING (TYPE_ID),
    (2, '�������') MATCHING (TYPE_ID),
    (3, '���. �����') MATCHING (TYPE_ID),
    (4, '���') MATCHING (TYPE_ID),
    (5, '����. ���.') MATCHING (TYPE_ID),
    (6, '����. ���. ���.') MATCHING (TYPE_ID);

COMMIT WORK;