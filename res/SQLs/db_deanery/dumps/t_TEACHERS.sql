INSERT INTO OR UPDATE
    TEACHERS
    (
        ID_TEACHER,
        FAM,
        NAME,
        OTCH
    )
VALUES
    (1, 'Преподаватель', '', '') MATCHING (ID_TEACHER),
    (2, 'Сорокин', 'Юрий', 'Адамович') MATCHING (ID_TEACHER),
    (3, 'Левадный', 'Денис', 'Валентинович') MATCHING (ID_TEACHER),
    (4, 'Колодник', 'Татьяна', 'Дмитриевна') MATCHING (ID_TEACHER);

COMMIT WORK;