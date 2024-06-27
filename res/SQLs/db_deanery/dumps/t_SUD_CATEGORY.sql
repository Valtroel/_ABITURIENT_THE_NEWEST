INSERT INTO OR UPDATE
    SUD_CATEGORY
    (
        ID,
        NAME
    )
VALUES
    (0, 'нет') MATCHING (ID),
    (1, 'Судья по спорту') MATCHING (ID),
    (2, 'Судья 1 категории') MATCHING (ID),
    (3, 'Судья национальной категории') MATCHING (ID),
    (4, 'Судья высшей национальной категории') MATCHING (ID),
    (5, 'Судья международной категории') MATCHING (ID);

COMMIT WORK;