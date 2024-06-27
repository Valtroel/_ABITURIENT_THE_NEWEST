INSERT INTO OR UPDATE
    HOSTEL
    (
        ID_HOSTEL,
        ADRESS_H
    )
VALUES
    (1, 'ул.Игнатьева,13') MATCHING (ID_HOSTEL),
    (2, 'пр.Победителей,107') MATCHING (ID_HOSTEL);

COMMIT WORK;