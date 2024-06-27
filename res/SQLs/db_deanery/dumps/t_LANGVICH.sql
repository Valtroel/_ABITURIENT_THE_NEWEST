INSERT INTO OR UPDATE
    LANGVICH
    (
        N_LANGVICH,
        LANGV
    )
VALUES
    (1, 'Английский') MATCHING (N_LANGVICH),
    (2, 'Немецкий') MATCHING (N_LANGVICH),
    (3, 'Французский') MATCHING (N_LANGVICH),
    (4, 'Итальянский') MATCHING (N_LANGVICH),
    (5, 'Испанский') MATCHING (N_LANGVICH),
    (6, 'Китайский') MATCHING (N_LANGVICH);

COMMIT WORK;