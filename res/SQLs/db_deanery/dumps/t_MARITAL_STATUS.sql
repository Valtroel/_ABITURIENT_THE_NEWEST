INSERT INTO OR UPDATE
    MARITAL_STATUS
    (
        MARITAL_ID,
        STATUS,
        GENDER_ID
    )
VALUES
    (1, 'Холост', 1) MATCHING (MARITAL_ID),
    (2, 'Женат', 1) MATCHING (MARITAL_ID),
    (3, 'Разведен', 1) MATCHING (MARITAL_ID),
    (4, 'Вдовец', 1) MATCHING (MARITAL_ID),
    (5, 'Не замужем', 2) MATCHING (MARITAL_ID),
    (6, 'Замужем', 2) MATCHING (MARITAL_ID),
    (7, 'Разведена', 2) MATCHING (MARITAL_ID),
    (8, 'Вдова', 2) MATCHING (MARITAL_ID);

COMMIT WORK;