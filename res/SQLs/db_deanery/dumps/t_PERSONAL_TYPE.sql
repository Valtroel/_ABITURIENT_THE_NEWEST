INSERT INTO OR UPDATE
    PERSONAL_TYPE
    (
        ID_TYPE,
        NAME_TYPE
    )
VALUES
    (1, '������� ���������� ��') MATCHING (ID_TYPE),
    (2, '������� ������������ ����������') MATCHING (ID_TYPE),
    (3, '��� �� ���������� � ��') MATCHING (ID_TYPE),
    (4, '�������') MATCHING (ID_TYPE),
    (5, '������������� �������') MATCHING (ID_TYPE);

COMMIT WORK;