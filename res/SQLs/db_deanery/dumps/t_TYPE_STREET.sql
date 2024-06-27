INSERT INTO OR UPDATE
    TYPE_STREET
    (
        ID,
        TYPE,
        SHORT_TYPE
    )
VALUES
    (0, '-', NULL) MATCHING (ID),
    (1, 'улица', 'ул.') MATCHING (ID),
    (2, 'переулок', 'пер.') MATCHING (ID),
    (3, 'проезд', 'пр-д') MATCHING (ID),
    (4, 'проспект', 'пр.') MATCHING (ID),
    (5, 'тракт', 'тр.') MATCHING (ID),
    (6, 'бульвар', 'б-р') MATCHING (ID),
    (7, 'тупик', 'туп.') MATCHING (ID),
    (8, 'площадь', 'пл.') MATCHING (ID),
    (10, 'набережная', 'наб.') MATCHING (ID),
    (11, 'поселок', 'пос.') MATCHING (ID),
    (12, 'шоссе', 'шоссе') MATCHING (ID),
    (13, 'территория', 'тер.') MATCHING (ID),
    (14, 'парк', 'парк') MATCHING (ID),
    (15, 'станция', 'ст.') MATCHING (ID),
    (16, 'микрорайон', 'мкр-н') MATCHING (ID),
    (18, 'квартал', 'квартал') MATCHING (ID),
    (999, 'другое', NULL) MATCHING (ID);

COMMIT WORK;