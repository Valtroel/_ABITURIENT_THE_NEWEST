INSERT INTO OR UPDATE
    PERSONAL_TYPE
    (
        ID_TYPE,
        NAME_TYPE
    )
VALUES
    (1, 'Паспорт гражданина РБ') MATCHING (ID_TYPE),
    (2, 'Паспорт иностранного гражданина') MATCHING (ID_TYPE),
    (3, 'Вид на жительство в РБ') MATCHING (ID_TYPE),
    (4, 'Справка') MATCHING (ID_TYPE),
    (5, 'Удостоверение беженца') MATCHING (ID_TYPE);

COMMIT WORK;