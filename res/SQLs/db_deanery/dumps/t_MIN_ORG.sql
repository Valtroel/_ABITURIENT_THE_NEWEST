INSERT INTO OR UPDATE
	MIN_ORG
	(
		ID,
		NAME_MIN_ORG,
		DESCRIBE
	)
VALUES
	(1, '������������ ������ � �������', NULL) MATCHING (ID),
    (2, '������������ ���������������', NULL) MATCHING (ID),
    (3, '������������ �����������', NULL) MATCHING (ID),
    (4, '������ �����������', NULL) MATCHING (ID),
    (5, '�����, ����� ������������ ������ � �������', NULL) MATCHING (ID),
    (6, '�����, ����� ������������ ���������������', NULL) MATCHING (ID),
    (7, '�����, ����� ������������ �����������', NULL) MATCHING (ID),
    (8, '�����, ����� ������ �����������', NULL) MATCHING (ID),
    (9, '������', NULL) MATCHING (ID),
    (10, '�����', NULL) MATCHING (ID),
    (11, '��������� ���������� ��������', NULL) MATCHING (ID);

COMMIT WORK;