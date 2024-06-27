INSERT INTO OR UPDATE
    CAUSE_PASS
    (
        N_CAUSE,
        CAUSE
    )
VALUES
    (1, 'По болезни') MATCHING (N_CAUSE),
    (2, 'По письмам Мин-ва') MATCHING (N_CAUSE),
    (4, 'По Университету') MATCHING (N_CAUSE),
    (3, 'По личным заявлениям') MATCHING (N_CAUSE),
    (5, 'По неуважительной') MATCHING (N_CAUSE),
    (6, 'По письмам ДСО') MATCHING (N_CAUSE);

COMMIT WORK;
