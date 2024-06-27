INSERT INTO OR UPDATE
    VID_ENCOURAGE
    (
        N_TYPE_EN,
        TYPE_EN
    )
VALUES
    (0, 'Поощрение') MATCHING (N_TYPE_EN),
    (1, 'Взыскание') MATCHING (N_TYPE_EN);

COMMIT WORK;