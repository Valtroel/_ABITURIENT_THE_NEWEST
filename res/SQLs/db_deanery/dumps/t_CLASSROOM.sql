INSERT INTO OR UPDATE
    CLASSROOM
    (
        ID_ROOM,
        ID_BUILD,
        NAME_ROOM
    )
VALUES
    (1, 1, '622') MATCHING (ID_ROOM),
    (2, 2, 'Манеж') MATCHING (ID_ROOM),
    (3, 3, 'Бассейн') MATCHING (ID_ROOM),
    (4, 4, 'УСК') MATCHING (ID_ROOM);

COMMIT WORK;
