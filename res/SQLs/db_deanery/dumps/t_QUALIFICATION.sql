INSERT INTO OR UPDATE
    QUALIFICATION
    (
        NOMER_QU,
        NAME,
        DESCRIBE
    )
VALUES
    (1, 'Преподаватель физической культуры и спорта', NULL) MATCHING (NOMER_QU),
    (2, 'Тренер по виду спорта', NULL) MATCHING (NOMER_QU),
    (3, 'Учитель физической культуры', NULL) MATCHING (NOMER_QU),
    (4, 'Педагог-организатор физкультурно-оздоровительной работы и туризма', NULL) MATCHING (NOMER_QU),
    (5, 'Педагог-организатор физического воспитания в дошкольных учреждениях', NULL) MATCHING (NOMER_QU),
    (6, 'Менеджер спорта и туризма', NULL) MATCHING (NOMER_QU),
    (7, 'Инструктор-методист физической реабилитации', NULL) MATCHING (NOMER_QU),
    (8, 'Инструктор-методист лечебной физической культуры', NULL) MATCHING (NOMER_QU),
    (9, 'Преподаватель физической культуры', NULL) MATCHING (NOMER_QU),
    (10, 'Инструктор-методист по оздоровительной физической культуре', NULL) MATCHING (NOMER_QU),
    (11, 'Инструктор-методист по адаптивной физической культуре', NULL) MATCHING (NOMER_QU),
    (12, 'Инструктор-методист физического воспитания в дошкольных учреждениях', NULL) MATCHING (NOMER_QU),
    (13, 'Психолог', NULL) MATCHING (NOMER_QU),
    (14, 'Менеджер в спорте', NULL) MATCHING (NOMER_QU),
    (15, 'Менеджер по туризму', NULL) MATCHING (NOMER_QU),
    (16, 'Инструктор-методист по туризму', NULL) MATCHING (NOMER_QU),
    (17, 'Менеджер-режиссер спортивно-массовых мероприятий', NULL) MATCHING (NOMER_QU),
    (18, 'Инструктор-методист по лечебной физической культуре', NULL) MATCHING (NOMER_QU),
    (19, 'Инструктор-методист по физической реабилитации', NULL) MATCHING (NOMER_QU),
    (20, 'Инструктор-методист по эрготерапии', NULL) MATCHING (NOMER_QU),
    (21, 'Специалист в сфере туризма и гостеприимства', NULL) MATCHING (NOMER_QU);

COMMIT WORK;