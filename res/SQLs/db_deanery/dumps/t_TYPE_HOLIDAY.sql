INSERT INTO OR UPDATE
    TYPE_HOLIDAY
    (
        N_HOLIDAY,
        HOLIDAY
    )
VALUES
    (1, 'Уход в академ. отпуск') MATCHING (N_HOLIDAY),
    (2, 'Академ. отпуск продлен') MATCHING (N_HOLIDAY),
    (3, 'Считать вернувшимся из а/о') MATCHING (N_HOLIDAY),
    (4, 'Академический отпуск') MATCHING (N_HOLIDAY),
    (5, 'Продление академ. отпуска') MATCHING (N_HOLIDAY),
    (6, 'Выход из отпуска') MATCHING (N_HOLIDAY),
    (7, 'Отпуск по беременности и родам') MATCHING (N_HOLIDAY),
    (8, 'Отпуск по уходу за ребенком до 3-х лет') MATCHING (N_HOLIDAY),
    (9, 'Отпуск по уходу за ребенком до 3-х лет со свободным посещением') MATCHING (N_HOLIDAY),
    (10, 'Отпуск по беременности') MATCHING (N_HOLIDAY),
    (11, 'Отпуск для прохождения военной службы') MATCHING (N_HOLIDAY);

COMMIT WORK;