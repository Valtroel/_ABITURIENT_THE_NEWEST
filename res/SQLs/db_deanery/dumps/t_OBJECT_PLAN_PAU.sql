INSERT INTO OR UPDATE
    OBJECT_PLAN_PAU
    (
        N_OBJECT,
        ALL_CLOCK_PLAN,
        NAME_OBJECT,
        INTEGR_MODUL,
        SHORT_NAME
    )
VALUES
    (1, 108, 'Педагогика и психология высшего образования', NULL, NULL) MATCHING (N_OBJECT),
    (2, 90, 'Социально-коммуникативные технологии в профессиональной деятельности', NULL, NULL) MATCHING (N_OBJECT),
    (3, 90, 'Информационные технологии и математическая статистика в физической культуре и спорте', NULL, NULL) MATCHING (N_OBJECT),
    (4, 216, 'Научно-педагогическая практика', NULL, NULL) MATCHING (N_OBJECT),
    (5, 90, 'Современные проблемы развития индустрии туризма и гостеприимства', NULL, NULL) MATCHING (N_OBJECT),
    (6, 90, 'Информационные технологии и математическая статистика в туристической индустрии', NULL, NULL) MATCHING (N_OBJECT),
    (7, 198, 'Информационные технологии и математическая статистика в туристической индустрии', NULL, NULL) MATCHING (N_OBJECT),
    (8, 216, 'Научно-педагогическая практика', NULL, NULL) MATCHING (N_OBJECT),
    (9, 240, 'Философия и методология науки', NULL, NULL) MATCHING (N_OBJECT),
    (10, 220, 'Иностранный язык', NULL, NULL) MATCHING (N_OBJECT),
    (11, 90, 'Спорт высших достижений и система подготовки спортсмена', NULL, NULL) MATCHING (N_OBJECT),
    (12, 90, 'Психология тренерской деятельности', NULL, NULL) MATCHING (N_OBJECT),
    (13, 54, 'Факультативная дисциплина: Микро- и макроэкономика', NULL, NULL) MATCHING (N_OBJECT),
    (14, 108, 'Основы информационных технологий', NULL, NULL) MATCHING (N_OBJECT),
    (15, 54, 'Факультативная дисциплина: Финансовый менеджмент в индустрии туризма и гостеприимства', NULL, NULL) MATCHING (N_OBJECT);

COMMIT WORK;