INSERT INTO OR UPDATE
    TYPE_ENCOURAGE
    (
        N_TYPE_EN,
        VID_EN,
        TYPE_EN
    )
VALUES
    (1, 'Благодарность', 0) MATCHING (N_TYPE_EN),
    (2, 'Замечание', 1) MATCHING (N_TYPE_EN),
    (3, 'Надбавка к учебной стипендии', 0) MATCHING (N_TYPE_EN),
    (4, 'Выговор', 1) MATCHING (N_TYPE_EN),
    (5, 'Строгий выговор', 1) MATCHING (N_TYPE_EN),
    (6, 'Выговор с предупреждением', 1) MATCHING (N_TYPE_EN),
    (7, 'Дополнительный отпуск', 0) MATCHING (N_TYPE_EN),
    (8, 'Строгий выговор с предупреждением', 1) MATCHING (N_TYPE_EN),
    (9, 'Материальная помощь', 0) MATCHING (N_TYPE_EN),
    (10, 'Премирование', 0) MATCHING (N_TYPE_EN),
    (11, 'Грамота', 0) MATCHING (N_TYPE_EN),
    (12, 'Наградной знак', 0) MATCHING (N_TYPE_EN);

COMMIT WORK;