INSERT INTO OR UPDATE
    EDUCATION
    (
        EDUCATION_ID,
        EDUCATION
    )
VALUES
    (1, '�������') MATCHING (EDUCATION_ID),
    (2, '������� �����������') MATCHING (EDUCATION_ID),
    (3, '������������� ������') MATCHING (EDUCATION_ID),
    (4, '������') MATCHING (EDUCATION_ID),
    (5, '���������������-�����������') MATCHING (EDUCATION_ID);

COMMIT WORK;