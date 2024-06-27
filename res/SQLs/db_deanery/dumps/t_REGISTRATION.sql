INSERT INTO OR UPDATE
    REGISTRATION
    (
        D_REG,
        D_VIS,
        ADRESS,
        N_ROOM,
        NOMER_S,
        EVICTION,
        N_DOGOVOR,
        NOM_ROOM
    )
VALUES
    ('2018-04-18 00:00:00', '2018-04-20 00:00:00', 'пр.Победителей, 107', 1, 5307, 1, '123V3', 1) MATCHING (N_ROOM),
    ('2018-04-18 00:00:00', '2018-08-31 00:00:00', 'пр.Победителей, 107', 2, 6843, 1, '', 1) MATCHING (N_ROOM);

COMMIT WORK;