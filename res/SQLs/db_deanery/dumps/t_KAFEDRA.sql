INSERT INTO OR UPDATE
    KAFEDRA
    (
        N_KAFEDRA,
        NAME_KAFEDRA,
        N_FAC,
        VIPUSK,
        NOTE,
        STATUS
    )
VALUES
    (10, 'Кафедра велосипедного, конькобежного и конного спорта', 1, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (11, 'Кафедра спортивной борьбы', 1, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (12, 'Кафедра спортивных игр', 1, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (13, 'Кафедра фехтования, бокса и тяжелой атлетики', 1, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (14, 'Кафедра футбола и хоккея', 1, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (15, 'Кафедра теории и методики физического воспитания и спорта', 1, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (16, 'Кафедра биомеханики', 1, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (17, 'Кафедра философии и истории', 1, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (18, 'Кафедра водно-технических видов спорта', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (19, 'Кафедра гимнастики', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (20, 'Кафедра легкой атлетики', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (21, 'Кафедра лыжного и стрелкового спорта', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (22, 'Кафедра педагогики и психологии', 2, 1, 'В 2006 году кафедра разделилась на 2: педагогики и психологии', 0) MATCHING (N_KAFEDRA),
    (23, 'Кафедра плавания', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (24, 'Кафедра спортивно-боевых единоборств и спецподготовки', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (25, 'Кафедра спортивной медицины', 2, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (26, 'Кафедра оздоровительной физической культуры', 3, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (27, 'Кафедра лечебной физической культуры', 3, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (28, 'Кафедра физической реабилитации', 3, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (29, 'Кафедра физического воспитания дошкольников', 3, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (30, 'Кафедра менеджмента спорта и туризма', 3, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (31, 'Кафедра иностранных языков', 3, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (32, 'Кафедра белорусского и русского языков', 3, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (33, 'Кафедра анатомии', 3, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (34, 'Кафедра физиологии и биохимии', 3, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (35, 'Кафедра туризма и гостеприимства', 4, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (36, 'Кафедра педагогики', 2, 0, NULL, 1) MATCHING (N_KAFEDRA),
    (37, 'Кафедра психологии', 2, 1, NULL, 1) MATCHING (N_KAFEDRA),
    (38, 'Кафедра социально-гуманитарных и экономических основ в туризме', 4, 0, NULL, 1) MATCHING (N_KAFEDRA);

COMMIT WORK;