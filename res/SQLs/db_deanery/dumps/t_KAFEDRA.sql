INSERT INTO OR UPDATE
    KAFEDRA
    (
        N_KAFEDRA,
        NAME_KAFEDRA,
        N_FAC,
        VIPUSK,
        NOTE,
        STATUS
    )
VALUES
    (10, '������� �������������, ������������� � ������� ������', 1, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (11, '������� ���������� ������', 1, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (12, '������� ���������� ���', 1, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (13, '������� ����������, ����� � ������� ��������', 1, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (14, '������� ������� � ������', 1, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (15, '������� ������ � �������� ����������� ���������� � ������', 1, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (16, '������� �����������', 1, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (17, '������� ��������� � �������', 1, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (18, '������� �����-����������� ����� ������', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (19, '������� ����������', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (20, '������� ������ ��������', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (21, '������� ������� � ����������� ������', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (22, '������� ���������� � ����������', 2, 1, '� 2006 ���� ������� ����������� �� 2: ���������� � ����������', 0) MATCHING (N_KAFEDRA),
    (23, '������� ��������', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (24, '������� ���������-������ ����������� � ��������������', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (25, '������� ���������� ��������', 2, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (26, '������� ��������������� ���������� ��������', 3, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (27, '������� �������� ���������� ��������', 3, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (28, '������� ���������� ������������', 3, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (29, '������� ����������� ���������� ������������', 3, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (30, '������� ����������� ������ � �������', 3, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (31, '������� ����������� ������', 3, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (32, '������� ������������ � �������� ������', 3, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (33, '������� ��������', 3, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (34, '������� ���������� � ��������', 3, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (35, '������� ������� � ��������������', 4, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (36, '������� ����������', 2, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (37, '������� ����������', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (38, '������� ���������-������������ � ������������� ����� � �������', 4, 0, NULL, 1) MATCHING (N_KAFEDRA);

COMMIT WORK;