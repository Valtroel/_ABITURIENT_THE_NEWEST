INSERT INTO OR UPDATE
    BUILDINGS
    (
        ID_BUILD,
        NAME_BUILD,
        SHORT_NAME
    )
VALUES
    (1, 'Главный учебный корпус', '') MATCHING (ID_BUILD),
    (2, 'Легкоатлетический манеж', 'Манеж') MATCHING (ID_BUILD),
    (3, 'Плавательный бассейн', 'Бассейн') MATCHING (ID_BUILD),
    (4, 'Учебно-спортивный корпус', 'УСК') MATCHING (ID_BUILD);

COMMIT WORK;