INSERT INTO OR UPDATE
    BUILDINGS
    (
        ID_BUILD,
        NAME_BUILD,
        SHORT_NAME
    )
VALUES
    (1, '������� ������� ������', '') MATCHING (ID_BUILD),
    (2, '����������������� �����', '�����') MATCHING (ID_BUILD),
    (3, '������������ �������', '�������') MATCHING (ID_BUILD),
    (4, '������-���������� ������', '���') MATCHING (ID_BUILD);

COMMIT WORK;