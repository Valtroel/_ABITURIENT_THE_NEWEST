INSERT INTO OR UPDATE
    PUBLIC_TYPE_PRIKAZ
    (
        N_TYPE,
        TYPE_PRIKAZ
    )
VALUES
    (2, 'На изменение фамилии') MATCHING (N_TYPE),
    (4, 'Перевод на индивидуальный график') MATCHING (N_TYPE),
    (5, 'Повторный год обучения') MATCHING (N_TYPE),
    (6, 'Перевод') MATCHING (N_TYPE),
    (7, 'Перевод из другого ВУЗа') MATCHING (N_TYPE),
    (8, 'Приказ на допуск к ГОС экзаменам и защите диплома') MATCHING (N_TYPE),
    (9, 'Приказ об окончании ВУЗа') MATCHING (N_TYPE),
    (10, 'На изменение имени') MATCHING (N_TYPE),
    (11, 'На изменение отчества') MATCHING (N_TYPE),
    (12, 'Приказ на допуск к ГОС экзаменам') MATCHING (N_TYPE),
    (13, 'Приказ на допуск к защите диплома') MATCHING (N_TYPE);

COMMIT WORK;