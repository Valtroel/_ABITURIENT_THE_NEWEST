INSERT INTO OR UPDATE
    TEACHERS
    (
        ID_TEACHER,
        FAM,
        NAME,
        OTCH
    )
VALUES
    (1, '�������������', '', '') MATCHING (ID_TEACHER),
    (2, '�������', '����', '��������') MATCHING (ID_TEACHER),
    (3, '��������', '�����', '������������') MATCHING (ID_TEACHER),
    (4, '��������', '�������', '����������') MATCHING (ID_TEACHER);

COMMIT WORK;