INSERT INTO OR UPDATE
    TYPE_OF_CONTROL
    (
        TYPE_ID,
        TYPE_NAME
    )
VALUES
    (0, 'Нет вида контроля') MATCHING (TYPE_ID),
    (1, 'Зачет') MATCHING (TYPE_ID),
    (2, 'Экзамен') MATCHING (TYPE_ID),
    (3, 'Диф. зачет') MATCHING (TYPE_ID),
    (4, 'ГЭК') MATCHING (TYPE_ID),
    (5, 'Канд. экз.') MATCHING (TYPE_ID),
    (6, 'Канд. диф. зач.') MATCHING (TYPE_ID);

COMMIT WORK;