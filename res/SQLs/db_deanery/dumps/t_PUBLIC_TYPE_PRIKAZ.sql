INSERT INTO OR UPDATE
    PUBLIC_TYPE_PRIKAZ
    (
        N_TYPE,
        TYPE_PRIKAZ
    )
VALUES
    (2, '�� ��������� �������') MATCHING (N_TYPE),
    (4, '������� �� �������������� ������') MATCHING (N_TYPE),
    (5, '��������� ��� ��������') MATCHING (N_TYPE),
    (6, '�������') MATCHING (N_TYPE),
    (7, '������� �� ������� ����') MATCHING (N_TYPE),
    (8, '������ �� ������ � ��� ��������� � ������ �������') MATCHING (N_TYPE),
    (9, '������ �� ��������� ����') MATCHING (N_TYPE),
    (10, '�� ��������� �����') MATCHING (N_TYPE),
    (11, '�� ��������� ��������') MATCHING (N_TYPE),
    (12, '������ �� ������ � ��� ���������') MATCHING (N_TYPE),
    (13, '������ �� ������ � ������ �������') MATCHING (N_TYPE);

COMMIT WORK;