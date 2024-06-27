INSERT INTO OR UPDATE
    EDUCATION
    (
        EDUCATION_ID,
        EDUCATION
    )
VALUES
    (1, 'Среднее') MATCHING (EDUCATION_ID),
    (2, 'Среднее специальное') MATCHING (EDUCATION_ID),
    (3, 'Незаконченное высшее') MATCHING (EDUCATION_ID),
    (4, 'Высшее') MATCHING (EDUCATION_ID),
    (5, 'Профессионально-техническое') MATCHING (EDUCATION_ID);

COMMIT WORK;