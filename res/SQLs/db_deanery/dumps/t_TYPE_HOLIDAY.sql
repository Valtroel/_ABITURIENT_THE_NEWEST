INSERT INTO OR UPDATE
    TYPE_HOLIDAY
    (
        N_HOLIDAY,
        HOLIDAY
    )
VALUES
    (1, '���� � ������. ������') MATCHING (N_HOLIDAY),
    (2, '������. ������ �������') MATCHING (N_HOLIDAY),
    (3, '������� ����������� �� �/�') MATCHING (N_HOLIDAY),
    (4, '������������� ������') MATCHING (N_HOLIDAY),
    (5, '��������� ������. �������') MATCHING (N_HOLIDAY),
    (6, '����� �� �������') MATCHING (N_HOLIDAY),
    (7, '������ �� ������������ � �����') MATCHING (N_HOLIDAY),
    (8, '������ �� ����� �� �������� �� 3-� ���') MATCHING (N_HOLIDAY),
    (9, '������ �� ����� �� �������� �� 3-� ��� �� ��������� ����������') MATCHING (N_HOLIDAY),
    (10, '������ �� ������������') MATCHING (N_HOLIDAY),
    (11, '������ ��� ����������� ������� ������') MATCHING (N_HOLIDAY);

COMMIT WORK;