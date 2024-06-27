INSERT INTO OR UPDATE
    VID_RESTORE
    (
        N_VID_RESTORE,
        VID_RESTORE
    )
VALUES
    (0, 'Восстановление') MATCHING (N_VID_RESTORE),
    (1, 'Отчисление') MATCHING (N_VID_RESTORE);

COMMIT WORK;