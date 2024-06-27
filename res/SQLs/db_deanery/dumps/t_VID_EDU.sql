INSERT INTO OR UPDATE
    VID_EDU
    (
        ID_VID_EDU,
        VID_EDU
    )
VALUES
    (0, 'дневная') MATCHING (ID_VID_EDU),
    (1, 'заочная') MATCHING (ID_VID_EDU),
    (2, 'соискательство') MATCHING (ID_VID_EDU);

COMMIT WORK;