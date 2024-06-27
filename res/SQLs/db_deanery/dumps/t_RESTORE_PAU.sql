INSERT INTO OR UPDATE
    RESTORE_PAU
    (
        NOMER,
        N_CAUSE_RESTORE,
        VID_RESTORE,
        N_PRIKAZ_RES,
        D_PRIKAZ_RES,
        DESCRIBE
    )
VALUES  
    (112, 1, 1, 212, '2019-12-12 00:00:00', 'отчислен потому что тупой'),
    (112, 1, 0, 213, '2020-12-12 00:00:00', 'поверили что не тупой');

COMMIT WORK;