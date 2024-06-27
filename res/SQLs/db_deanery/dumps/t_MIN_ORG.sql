INSERT INTO OR UPDATE
	MIN_ORG
	(
		ID,
		NAME_MIN_ORG,
		DESCRIBE
	)
VALUES
	(1, 'Министерство спорта и туризма', NULL) MATCHING (ID),
    (2, 'Министерство здравоохранения', NULL) MATCHING (ID),
    (3, 'Министерство образования', NULL) MATCHING (ID),
    (4, 'Другие организации', NULL) MATCHING (ID),
    (5, 'ССУЗы, ВВУЗы Министерства спорта и туризма', NULL) MATCHING (ID),
    (6, 'ССУЗы, ВВУЗы Министерства здравоохранения', NULL) MATCHING (ID),
    (7, 'ССУЗы, ВВУЗы Министерства образования', NULL) MATCHING (ID),
    (8, 'ССУЗы, ВВУЗы других организаций', NULL) MATCHING (ID),
    (9, 'Заявка', NULL) MATCHING (ID),
    (10, 'Заказ', NULL) MATCHING (ID),
    (11, 'Федерация профсоюзов Беларуси', NULL) MATCHING (ID);

COMMIT WORK;