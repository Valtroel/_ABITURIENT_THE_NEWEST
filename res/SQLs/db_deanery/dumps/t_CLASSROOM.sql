INSERT INTO OR UPDATE
    CLASSROOM
    (
        ID_ROOM,
        ID_BUILD,
        NAME_ROOM
    )
VALUES
    (1, 1, '622') MATCHING (ID_ROOM),
    (2, 2, '�����') MATCHING (ID_ROOM),
    (3, 3, '�������') MATCHING (ID_ROOM),
    (4, 4, '���') MATCHING (ID_ROOM);

COMMIT WORK;
