INSERT INTO OR UPDATE
    TYPE_ENCOURAGE
    (
        N_TYPE_EN,
        VID_EN,
        TYPE_EN
    )
VALUES
    (1, '�������������', 0) MATCHING (N_TYPE_EN),
    (2, '���������', 1) MATCHING (N_TYPE_EN),
    (3, '�������� � ������� ���������', 0) MATCHING (N_TYPE_EN),
    (4, '�������', 1) MATCHING (N_TYPE_EN),
    (5, '������� �������', 1) MATCHING (N_TYPE_EN),
    (6, '������� � ���������������', 1) MATCHING (N_TYPE_EN),
    (7, '�������������� ������', 0) MATCHING (N_TYPE_EN),
    (8, '������� ������� � ���������������', 1) MATCHING (N_TYPE_EN),
    (9, '������������ ������', 0) MATCHING (N_TYPE_EN),
    (10, '������������', 0) MATCHING (N_TYPE_EN),
    (11, '�������', 0) MATCHING (N_TYPE_EN),
    (12, '��������� ����', 0) MATCHING (N_TYPE_EN);

COMMIT WORK;