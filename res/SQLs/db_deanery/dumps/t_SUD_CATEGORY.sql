INSERT INTO OR UPDATE
    SUD_CATEGORY
    (
        ID,
        NAME
    )
VALUES
    (0, '���') MATCHING (ID),
    (1, '����� �� ������') MATCHING (ID),
    (2, '����� 1 ���������') MATCHING (ID),
    (3, '����� ������������ ���������') MATCHING (ID),
    (4, '����� ������ ������������ ���������') MATCHING (ID),
    (5, '����� ������������� ���������') MATCHING (ID);

COMMIT WORK;