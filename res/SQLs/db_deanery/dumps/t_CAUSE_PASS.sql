INSERT INTO OR UPDATE
    CAUSE_PASS
    (
        N_CAUSE,
        CAUSE
    )
VALUES
    (1, '�� �������') MATCHING (N_CAUSE),
    (2, '�� ������� ���-��') MATCHING (N_CAUSE),
    (4, '�� ������������') MATCHING (N_CAUSE),
    (3, '�� ������ ����������') MATCHING (N_CAUSE),
    (5, '�� ��������������') MATCHING (N_CAUSE),
    (6, '�� ������� ���') MATCHING (N_CAUSE);

COMMIT WORK;
