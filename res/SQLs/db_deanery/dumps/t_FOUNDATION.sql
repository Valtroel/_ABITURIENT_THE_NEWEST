INSERT INTO OR UPDATE
    FOUNDATION
    (
        N_FOUND,
        VID_FOUND
    )
VALUES
    (1, 'Целевой контракт') MATCHING (N_FOUND),
    (2, 'Договор') MATCHING (N_FOUND),
    (3, 'После РУОР') MATCHING (N_FOUND),
    (4, 'Конкурс') MATCHING (N_FOUND),
    (5, 'ПО') MATCHING (N_FOUND),
    (6, 'Бюджет') MATCHING (N_FOUND),
    (7, 'Вне конкурса') MATCHING (N_FOUND),
    (8, 'Без экзаменов') MATCHING (N_FOUND),
    (9, 'Перевод из др. ВУЗа') MATCHING (N_FOUND),
    (10, 'После Пед.колледжа') MATCHING (N_FOUND),
    (11, 'Восст-ие из др. ВУЗа') MATCHING (N_FOUND),
    (12, 'После РУОР(вне конк)') MATCHING (N_FOUND),
    (13, 'После РУОР (без экз)') MATCHING (N_FOUND),
    (14, 'Договор (после РУОР)') MATCHING (N_FOUND),
    (15, 'Договор(Пед.колледж)') MATCHING (N_FOUND),
    (16, 'п.29 Правил приема') MATCHING (N_FOUND),
    (17, 'После МКП') MATCHING (N_FOUND),
    (18, 'Договор(после МКП,ИПК(вне к))') MATCHING (N_FOUND),
    (19, 'Договор(после МКП,ИПК(без э))') MATCHING (N_FOUND),
    (20, 'Договор (после МКП,ИПК)') MATCHING (N_FOUND),
    (23, 'п.33 Правил приема сверх плана приема') MATCHING (N_FOUND),
    (24, 'Не введено') MATCHING (N_FOUND);

COMMIT WORK;