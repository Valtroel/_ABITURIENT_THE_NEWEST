INSERT INTO OR UPDATE
    REGION
    (
        N_REGION,
        TEXT_REGION
    )
VALUES
    (0, 'нет') MATCHING (N_REGION),
    (1, 'Брестская обл.') MATCHING (N_REGION),
    (2, 'Витебская обл.') MATCHING (N_REGION),
    (3, 'Гомельская обл.') MATCHING (N_REGION),
    (4, 'Гродненская обл.') MATCHING (N_REGION),
    (5, 'г. Минск') MATCHING (N_REGION),
    (6, 'Минская обл.') MATCHING (N_REGION),
    (7, 'Могилевская обл.') MATCHING (N_REGION),
    (8, 'Другие республики') MATCHING (N_REGION);

COMMIT WORK;