INSERT INTO OR UPDATE
    TYPE_LIKVID
    (
        N_TYPE_LIKVID,
        TEXT_LIKVID
    )
VALUES
    (1, 'Перевод на другой факультет') MATCHING (N_TYPE_LIKVID),
    (2, 'Перевод на другой вид обучения') MATCHING (N_TYPE_LIKVID),
    (3, 'Перевод на другую специализацию') MATCHING (N_TYPE_LIKVID),
    (4, 'Перевод из другого ВУЗа') MATCHING (N_TYPE_LIKVID),
    (5, 'Восстановление') MATCHING (N_TYPE_LIKVID),
    (6, 'Восстановление из другого ВУЗа') MATCHING (N_TYPE_LIKVID),
    (7, 'Повторный курс') MATCHING (N_TYPE_LIKVID),
    (8, 'Выход из академического отпуска') MATCHING (N_TYPE_LIKVID),
    (9, 'После училища олимпийского резерва') MATCHING (N_TYPE_LIKVID),
    (10, 'Получение второго высшего образования') MATCHING (N_TYPE_LIKVID),
    (11, 'После МКП') MATCHING (N_TYPE_LIKVID);

COMMIT WORK;