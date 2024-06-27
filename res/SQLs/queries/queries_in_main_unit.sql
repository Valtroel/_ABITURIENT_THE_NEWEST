-- const AnsiString PATH_TO_ADMISSION_COMMITTEE_DOCUMENTS = "D:\\Документы приемной комиссии\\";
-- 
-- const AnsiString SUMMARY_LIST_ENTR_EXAM        = "ВЕДОМОСТЬ - Вступительных экзаменов (2022).xls";              // |Сводная ведомость вступительных экзаменов 2021.xls|
-- const AnsiString SUMMARY_LIST_ENTR_EXAM_ERM    = "ВЕДОМОСТЬ - Вступительных экзаменов (А.А. Ермакова).xls";     // |Сводная ведомость вступительных экзаменов_ИТ.xls|
-- const AnsiString SUMMARY_LIST_ENTR_EXAM_KOVAL  = "ВЕДОМОСТЬ - Вступительных экзаменов (В.В. Коваленя).xls";     // |Сводная ведомость вступительных экзаменов.xls|
-- const AnsiString CONTRACT_BUDGET               = "ДОГОВОР - Бюджет (2022).xls";                                 // |Договор 2021 бюджет.xls|
-- const AnsiString CONTRACT_PAYERS               = "ДОГОВОР - Платники (2022).xls";                               // |Договор 2021 платное.xls|
-- const AnsiString REGISTRY_BOOK                 = "ЖУРНАЛ - Регистрация.xls";                                    // |Журнал регистрации_.xls|
-- const AnsiString APPLICATION_FOR_ADMITION      = "ЗАЯВЛЕНИЕ - Допуск к участию.xls";                            // |Заявление.xls|
-- const AnsiString BRIEFING_BEFORE_EXAM          = "ИНСТРУКТАЖ - Экзаменационная.xls";                            // |Экзаменационная ведомость_ИТ.xls|
-- const AnsiString REPORT_SUBMITTED              = "ОТЧЕТ - Подано заявлений.xls";                                // |Отчет (подано заявлений итоговая).xls|
-- const AnsiString REPORT_FORM_1                 = "ОТЧЕТ - Форма 1 (2022).xls";                                  // |Форма 1_2021.xls|
-- const AnsiString REPORT_FORM_2                 = "ОТЧЕТ - Форма 2 (2022).xls";                                  // |Форма 2_2021.xls|
-- const AnsiString PROTOCOL_DAILY                = "ПРОТОКОЛ - Ежедневный.xls";                                   // |Ежедневный протокол 2021.xls|
-- const AnsiString PROTOCOL_GIRLS_TESTS          = "ПРОТОКОЛ - Испытаний (Девушки).xls";                          // |Протокол_Ж(4 вида).xls|
-- const AnsiString PROTOCOL_ADMITTED             = "ПРОТОКОЛ - О допуске абитуриентов (2022).doc";                // |Протокол для Грасс 2019.doc|
-- const AnsiString PROTOCOL_EXAM                 = "ПРОТОКОЛ – Экзамен по ФКиС.xls";                              // |Экзаменационная ведомость.xls|
-- const AnsiString LIST_                         = "СПИСОК.xls";                                                  // |Полный список.xls|
-- const AnsiString STATISTIC_SCORES              = "СТАТИСТИКА - Баллы (2022).xls";                               // |Cтатистика по баллам 2021.xls|
-- const AnsiString STATISTIC_DAILY               = "СТАТИСТИКА - Ежедневная.xls";                                 // |Ежедневная статистика 2021.xls|
-- const AnsiString STATISTIC_BUDGET_SEATS        = "СТАТИСТИКА - Кол-во бюджетных мест.xls";                      // |Количество бюджетных мест.xls|
-- const AnsiString STATISTIC_CONTEST             = "СТАТИСТИКА - Конкурс (2022).xls";                             // |Конкурс 2021.xls|
-- const AnsiString STATISTIC_CONTEST_BY_FACULTY  = "СТАТИСТИКА - Конкурс по факультетам.xls";                     // |Конкурс цифры по факультету.xls|
-- const AnsiString STATISTIC_EXAM_RESULT         = "СТАТИСТИКА - Результаты сдачи экзаменов.xls";                 // |Результаты сдачи вступительных экзаменов.xls|
-- const AnsiString STATISTIC_CERT_RESULT_TEN     = "СТАТИСТИКА - Результаты сертификатов (десятибалльная).xls";   // |Результаты поданных сертификатов.xls|
-- const AnsiString STATISTIC_CERT_RESULT_HUNDRED = "СТАТИСТИКА - Результаты сертификатов (стобалльная).xls";      // |Результаты поданных сертификатов ИТ.xls|
-- const AnsiString STATISTIC_LEVEL_OF_SPORTS     = "СТАТИСТИКА - Уровень спортивной подготовки.xls";              // |Уровень спортивной подготовленности.xls|
-- const AnsiString STATISTIC_RECEPTION_PROGRESS  = "СТАТИСТИКА - Ход приема.xls";                                 // |Информация о ходе приема (госконтроль).xls|


/*
const AnsiString SUMMARY_LIST_ENTR_EXAM        = "ВЕДОМОСТЬ - Вступительных экзаменов (2022).xls";              // |Сводная ведомость вступительных экзаменов 2021.xls|
// in ListDlgUnit const AnsiString CONTRACT_BUDGET               = "ДОГОВОР - Бюджет (2022).xls";                                 // |Договор 2021 бюджет.xls|
// in ListDlgUnit const AnsiString CONTRACT_PAYERS               = "ДОГОВОР - Платники (2022).xls";                               // |Договор 2021 платное.xls|
const AnsiString REGISTRY_BOOK                 = "ЖУРНАЛ - Регистрация.xls";                                    // |Журнал регистрации_.xls|
const AnsiString APPLICATION_FOR_ADMITION      = "ЗАЯВЛЕНИЕ - Допуск к участию.xls";                            // |Заявление.xls|
const AnsiString BRIEFING_BEFORE_EXAM          = "ИНСТРУКТАЖ - Экзаменационная.xls";                            // |Экзаменационная ведомость_ИТ.xls|
const AnsiString REPORT_SUBMITTED              = "ОТЧЕТ - Подано заявлений.xls";                                // |Отчет (подано заявлений итоговая).xls|
const AnsiString REPORT_FORM_1                 = "ОТЧЕТ - Форма 1 (2022).xls";                                  // |Форма 1_2021.xls|
const AnsiString REPORT_FORM_2                 = "ОТЧЕТ - Форма 2 (2022).xls";                                  // |Форма 2_2021.xls|
// in Dlg_ProtokolUnit const AnsiString PROTOCOL_DAILY                = "ПРОТОКОЛ - Ежедневный.xls";                                   // |Ежедневный протокол 2021.xls|
const AnsiString PROTOCOL_GIRLS_TESTS          = "ПРОТОКОЛ - Испытаний (Девушки).xls";                          // |Протокол_Ж(4 вида).xls|
// in Dlg_ProtokolUnit const AnsiString PROTOCOL_ADMITTED             = "ПРОТОКОЛ - О допуске абитуриентов (2022).doc";                // |Протокол для Грасс 2019.doc|
// in ЕxamenUnit const AnsiString PROTOCOL_EXAM                 = "ПРОТОКОЛ – Экзамен по ФКиС.xls";                              // |Экзаменационная ведомость.xls|
const AnsiString LIST_                         = "СПИСОК.xls";                                                  // |Полный список.xls|
const AnsiString STATISTIC_SCORES              = "СТАТИСТИКА - Баллы (2022).xls";                               // |Cтатистика по баллам 2021.xls|
const AnsiString STATISTIC_DAILY               = "СТАТИСТИКА - Ежедневная.xls";                                 // |Ежедневная статистика 2021.xls|
const AnsiString STATISTIC_BUDGET_SEATS        = "СТАТИСТИКА - Кол-во бюджетных мест.xls";                      // |Количество бюджетных мест.xls|
const AnsiString STATISTIC_CONTEST             = "СТАТИСТИКА - Конкурс (2022).xls";                             // |Конкурс 2021.xls|
const AnsiString STATISTIC_CONTEST_BY_FACULTY  = "СТАТИСТИКА - Конкурс по факультетам.xls";                     // |Конкурс цифры по факультету.xls|
// in Stat_Result_examUnit const AnsiString STATISTIC_EXAM_RESULT         = "СТАТИСТИКА - Результаты сдачи экзаменов.xls";                 // |Результаты сдачи вступительных экзаменов.xls|
// in Stat_Result_examUnit const AnsiString STATISTIC_CERT_RESULT_TEN     = "СТАТИСТИКА - Результаты сертификатов (десятибалльная).xls";   // |Результаты поданных сертификатов.xls|
// in Stat_Result_examUnit const AnsiString STATISTIC_CERT_RESULT_HUNDRED = "СТАТИСТИКА - Результаты сертификатов (стобалльная).xls";      // |Результаты поданных сертификатов ИТ.xls|
const AnsiString STATISTIC_LEVEL_OF_SPORTS     = "СТАТИСТИКА - Уровень спортивной подготовки.xls";              // |Уровень спортивной подготовленности.xls|


const AnsiString DEAN_FACULTY_1                = "В.И.Новицкая";                                                // СИиЕ
const AnsiString DEAN_FACULTY_2                = "И.И.Гуслистова";                                              // МВС
const AnsiString DEAN_FACULTY_3                = "Н.М.Машарская";                                               // ОФКиТ
const AnsiString DEAN_FACULTY_4                = "Л.И.Сакун";                                                   // МСиТ
const AnsiString YEAR_OF_ADMISSION             = "2022";
*/



-- BEGIH > TMainForm::Forma_Giac
-- DM -> QGIACAllSpec -> SQL -> Add ("     \
    SELECT                      \
        SUM                     \
        (                       \
            k.kol_place         \
        )                       \
    FROM                        \
        kol_place AS k          \
    WHERE                       \
        k.vid_edu = :vid_edu    \
    AND                         \
        k.price   = :price      \
    AND                         \
        (                       \
            k.n_specializ = 4   \
         OR                     \
            k.n_specializ = 57  \
        )                       \
-- ");

-- DM -> QGIACAllSpec -> SQL -> Add ("     \
    SELECT                          \
        SUM                         \
        (                           \
            k.kol_place             \
        )                           \
    FROM                            \
        kol_place AS k              \
    WHERE                           \
            k.vid_edu = :vid_edu    \
        AND                         \
            k.price   = :price      \
        AND                         \
            (                       \
                k.n_specializ = 38  \
             OR                     \
                k.n_specializ = 39  \
            )                       \
-- ");
-- DM -> QGIACAllSpec -> SQL -> Add (" \
    SELECT                          \
        SUM                         \
        (                           \
            k.kol_place             \
        )                           \
    FROM                            \
        kol_place AS k              \
    WHERE                           \
            k.vid_edu = :vid_edu    \
        AND                         \
            k.price   = :price      \
        AND                         \
            (                       \
                k.n_specializ = 3   \
             OR                     \
                k.n_specializ = 47  \
            )                       \
-- ");
-- DM -> QGIACAllSpec -> SQL -> Add (" \
    SELECT                          \
        SUM                         \
        (                           \
            k.kol_place             \
        )                           \
    FROM                            \
        kol_place AS k              \
    WHERE                           \
            k.vid_edu = :vid_edu    \
        AND                         \
            k.price   = :price      \
        AND                         \
            (                       \
                k.n_specializ = 1   \
             OR                     \
                k.n_specializ = 7   \
             OR                     \
                k.n_specializ = 8   \
             OR                     \
                k.n_specializ = 9   \
             OR                     \
                k.n_specializ = 10  \
             OR                     \
                k.n_specializ = 12  \
             OR                     \
                k.n_specializ = 13  \
             OR                     \
                k.n_specializ = 15  \
             OR                     \
                k.n_specializ = 16  \
             OR                     \
                k.n_specializ = 17  \
             OR                     \
                k.n_specializ = 20  \
             OR                     \
                k.n_specializ = 21  \
             OR                     \
                k.n_specializ = 23  \
             OR                     \
                k.n_specializ = 24  \
             OR                     \
                k.n_specializ = 25  \
             OR                     \
                k.n_specializ = 26  \
             OR                     \
                k.n_specializ = 27  \
             OR                     \
                k.n_specializ = 28  \
             OR                     \
                k.n_specializ = 29  \
             OR                     \
                k.n_specializ = 30  \
             OR                     \
                k.n_specializ = 32  \
             OR                     \
                k.n_specializ = 33  \
             OR                     \
                k.n_specializ = 35  \
             OR                     \
                k.n_specializ = 37  \
             OR                     \
                k.n_specializ = 42  \
             OR                     \
                k.n_specializ = 43  \
             OR                     \
                k.n_specializ = 44  \
             OR                     \
                k.n_specializ = 45  \
             OR                     \
                k.n_specializ = 48  \
             OR                     \
                k.n_specializ = 52  \
             OR                     \
                k.n_specializ = 53  \
             OR                     \
                k.n_specializ = 54  \
             OR                     \
                k.n_specializ = 55  \
             OR                     \
                k.n_specializ = 66  \
             OR                     \
                k.n_specializ = 68  \
             OR                     \
                k.n_specializ = 69  \
             OR                     \
                k.n_specializ = 79  \
             OR                     \
                k.n_specializ = 80  \
             OR                     \
                k.n_specializ = 84  \
             OR                     \
                k.n_specializ = 87  \
             OR                     \
                k.n_specializ = 88  \
             OR                     \
                k.n_specializ = 94  \
             OR                     \
                k.n_specializ = 96  \
             OR                     \
                k.n_specializ = 115 \
             OR                     \
                k.n_specializ = 120 \
            )                       \
-- ");
-- DM -> QGIACAllSpec -> SQL -> Add ("     \
    SELECT                              \
        SUM                             \
        (                               \
            k.kol_place                 \
        )                               \
    FROM                                \
        kol_place AS k                  \
    WHERE                               \
            k.vid_edu     = :vid_edu    \
        AND                             \
            k.price       = :price      \
        AND                             \
            k.n_specializ = 61          \
-- ");
-- DM -> QGIACAllSpec -> SQL -> Add (" \
    SELECT                          \
        SUM                         \
        (                           \
            k.kol_place             \
        )                           \
    FROM                            \
        kol_place AS k              \
    WHERE                           \
            k.vid_edu = :vid_edu    \
        AND                         \
            k.price   = :price      \
        AND                         \
            (                       \
                k.n_specializ = 51  \
             OR                     \
                k.n_specializ = 100 \
            )                       \
-- ");
-- DM -> QGIACCKSpec -> SQL -> Add ("  \
    SELECT                          \
        SUM                         \
        (                           \
    --        c.kol_p                 \
            c.kol_place             \
        )                           \
    FROM                            \
    --    ck AS c                     \
        ck_plan AS c                \
    WHERE                           \
            c.n_specializ = 4       \
         OR                         \
            c.n_specializ = 57      \
-- ");
-- DM -> QGIACCKSpec -> SQL -> Add ("  \
    SELECT                          \
        SUM                         \
        (                           \
            c.kol_place             \
        )                           \
    FROM                            \
        ck_plan AS c                \
    WHERE                           \
            c.n_specializ = 38      \
         OR                         \
            c.n_specializ = 39      \
-- ");
-- DM -> QGIACCKSpec -> SQL -> Add ("  \
    SELECT                          \
        SUM                         \
        (                           \
            c.kol_place             \
        )                           \
    FROM                            \
        ck_plan AS c                \
    WHERE                           \
        c.n_specializ = 3           \
-- ");
-- DM -> QGIACCKSpec -> SQL -> Add ("  \
    SELECT                          \
        SUM                         \
        (                           \
            c.kol_place             \
        )                           \
    FROM                            \
        ck_plan AS c                \
    WHERE                           \
            c.n_specializ = 1       \
        OR                          \
            c.n_specializ = 7       \
        OR                          \
            c.n_specializ = 9       \
        OR                          \
            c.n_specializ = 10      \
        OR                          \
            c.n_specializ = 11      \
        OR                          \
            c.n_specializ = 12      \
        OR                          \
            c.n_specializ = 13      \
        OR                          \
            c.n_specializ = 15      \
        OR                          \
            c.n_specializ = 16      \
        OR                          \
            c.n_specializ = 17      \
        OR                          \
            c.n_specializ = 19      \
        OR                          \
            c.n_specializ = 20      \
        OR                          \
            c.n_specializ = 21      \
        OR                          \
            c.n_specializ = 23      \
        OR                          \
            c.n_specializ = 24      \
        OR                          \
            c.n_specializ = 25      \
        OR                          \
            c.n_specializ = 26      \
        OR                          \
            c.n_specializ = 27      \
        OR                          \
            c.n_specializ = 28      \
        OR                          \
            c.n_specializ = 29      \
        OR                          \
            c.n_specializ = 30      \
        OR                          \
            c.n_specializ = 32      \
        OR                          \
            c.n_specializ = 33      \
        OR                          \
            c.n_specializ = 35      \
        OR                          \
            c.n_specializ = 37      \
        OR                          \
            c.n_specializ = 42      \
        OR                          \
            c.n_specializ = 43      \
        OR                          \
            c.n_specializ = 44      \
        OR                          \
            c.n_specializ = 45      \
        OR                          \
            c.n_specializ = 48      \
        OR                          \
            c.n_specializ = 52      \
        OR                          \
            c.n_specializ = 54      \
        OR                          \
            c.n_specializ = 55      \
        OR                          \
            c.n_specializ = 66      \
        OR                          \
            c.n_specializ = 68      \
        OR                          \
            c.n_specializ = 69      \
        OR                          \
            c.n_specializ = 79      \
        OR                          \
            c.n_specializ = 80      \
        OR                          \
            c.n_specializ = 84      \
        OR                          \
            c.n_specializ = 87      \
        OR                          \
            c.n_specializ = 88      \
        OR                          \
            c.n_specializ = 94      \
        OR                          \
            c.n_specializ = 96      \
        OR                          \
            c.n_specializ = 115     \
        OR                          \
            c.n_specializ = 120     \
-- ");
-- DM -> QGIACCKSpec -> SQL -> Add ("  \
    SELECT                          \
        SUM                         \
        (                           \
            c.kol_place             \
        )                           \
    FROM                            \
        ck_plan AS c                \
    WHERE                           \
        c.n_specializ = 61          \
-- ");
-- DM -> QGIACCKSpec -> SQL -> Add ("  \
    SELECT                          \
        SUM                         \
        (                           \
            c.kol_place             \
        )                           \
    FROM                            \
        ck_plan AS c                \
    WHERE                           \
            c.n_specializ = 51      \
        OR                          \
            c.n_specializ = 100     \
-- ");
-- DM -> QGIAC2kSpec -> SQL -> Add ("  \
    SELECT                          \
        SUM                         \
        (                           \
            k.kol_place             \
        )                           \
    FROM                            \
        kol_place AS k              \
    WHERE                           \
            k.vid_edu = :vid_edu    \
        AND                         \
            k.price   = :price      \
        AND                         \
            (                       \
                k.text        = 1   \
             OR                     \
                k.text        = 2   \
            )                       \
        AND                         \
            (                       \
                k.n_specializ = 4   \
             OR                     \
                k.n_specializ = 57  \
            )                       \
-- ");
-- DM -> QGIAC2kSpec -> SQL -> Add ("  \
    SELECT                          \
        SUM                         \
        (                           \
            k.kol_place             \
        )                           \
    FROM                            \
        kol_place AS k              \
    WHERE                           \
            k.vid_edu = :vid_edu    \
        AND                         \
            k.price   = :price      \
        AND                         \
            (                       \
                k.text        = 1   \
             OR                     \
                k.text        = 2   \
            )                       \
        AND                         \
            (                       \
                k.n_specializ = 38  \
             OR                     \
                k.n_specializ = 39  \
            )                       \
-- ");
-- DM -> QGIAC2kSpec -> SQL -> Add ("      \
    SELECT                              \
        SUM                             \
        (                               \
            k.kol_place                 \
        )                               \
    FROM                                \
        kol_place AS k                  \
    WHERE                               \
            k.vid_edu     = :vid_edu    \
        AND                             \
            k.price       = :price      \
        AND                             \
            k.text        = 1           \
        AND                             \
            k.n_specializ = 3           \
-- ");
-- DM -> QGIAC2kSpec -> SQL -> Add ("  \
    SELECT                          \
        SUM                         \
        (                           \
            k.kol_place             \
        )                           \
    FROM                            \
        kol_place AS k              \
    WHERE                           \
            k.vid_edu = :vid_edu    \
        AND                         \
            k.price   = :price      \
        AND                         \
            k.text    = 1           \
        AND                         \
            (                       \
                k.n_specializ = 1   \
             OR                     \
                k.n_specializ = 7   \
             OR                     \
                k.n_specializ = 9   \
             OR                     \
                k.n_specializ = 10  \
             OR                     \
                k.n_specializ = 11  \
             OR                     \
                k.n_specializ = 12  \
             OR                     \
                k.n_specializ = 13  \
             OR                     \
                k.n_specializ = 15  \
             OR                     \
                k.n_specializ = 16  \
             OR                     \
                k.n_specializ = 17  \
             OR                     \
                k.n_specializ = 19  \
             OR                     \
                k.n_specializ = 20  \
             OR                     \
                k.n_specializ = 21  \
             OR                     \
                k.n_specializ = 23  \
             OR                     \
                k.n_specializ = 24  \
             OR                     \
                k.n_specializ = 25  \
             OR                     \
                k.n_specializ = 26  \
             OR                     \
                k.n_specializ = 27  \
             OR                     \
                k.n_specializ = 28  \
             OR                     \
                k.n_specializ = 29  \
             OR                     \
                k.n_specializ = 30  \
             OR                     \
                k.n_specializ = 32  \
             OR                     \
                k.n_specializ = 33  \
             OR                     \
                k.n_specializ = 35  \
             OR                     \
                k.n_specializ = 37  \
             OR                     \
                k.n_specializ = 42  \
             OR                     \
                k.n_specializ = 43  \
             OR                     \
                k.n_specializ = 44  \
             OR                     \
                k.n_specializ = 45  \
             OR                     \
                k.n_specializ = 48  \
             OR                     \
                k.n_specializ = 52  \
             OR                     \
                k.n_specializ = 54  \
             OR                     \
                k.n_specializ = 55  \
             OR                     \
                k.n_specializ = 66  \
             OR                     \
                k.n_specializ = 68  \
             OR                     \
                k.n_specializ = 69  \
             OR                     \
                k.n_specializ = 79  \
             OR                     \
                k.n_specializ = 80  \
             OR                     \
                k.n_specializ = 84  \
             OR                     \
                k.n_specializ = 87  \
             OR                     \
                k.n_specializ = 88  \
             OR                     \
                k.n_specializ = 94  \
             OR                     \
                k.n_specializ = 96  \
             OR                     \
                k.n_specializ = 115 \
             OR                     \
                k.n_specializ = 120 \
            )                       \
-- ");
-- DM -> QGIAC2kSpec -> SQL -> Add ("      \
    SELECT                              \
        SUM                             \
        (                               \
            k.kol_place                 \
        )                               \
    FROM                                \
        kol_place AS k                  \
    WHERE                               \
            k.vid_edu     = :vid_edu    \
        AND                             \
            k.price       = :price      \
        AND                             \
            k.text        = 1           \
        AND                             \
            k.n_specializ = 61          \
-- ");
-- DM -> QGIAC2kSpec -> SQL -> Add ("  \
    SELECT                          \
        SUM                         \
        (                           \
            k.kol_place             \
        )                           \
    FROM                            \
        kol_place AS k              \
    WHERE                           \
            k.vid_edu = :vid_edu    \
        AND                         \
            k.price   = :price      \
        AND                         \
            k.text    = 1           \
        AND                         \
            (                       \
                k.n_specializ = 100 \
             OR                     \
                k.n_specializ = 51  \
            )                       \
-- ");
-- DMVed -> GIAZ2_4_1Qr -> SQL -> Add ("   \
    SELECT                              \
        COUNT                           \
        (                               \
            a.nomer_ab                  \
        )                               \
    FROM                                \
        abitura AS a                    \
-- ");
-- DMVed -> GIAZ2_4_1Qr -> SQL -> Add ("   \
    WHERE                               \
            a.status          = 5       \
-- ");
-- DMVed -> GIAZ2_4_1Qr -> SQL -> Add ("   \
        AND                             \
            a.vid_edu         = :vid_edu\
-- ");
-- DMVed -> GIAZ2_4_1Qr -> SQL -> Add ("   \
        AND                             \
            a.category_if     = 0       \
-- ");
-- DMVed -> GIAZ2_4_1Qr -> SQL -> Add ("   \
        AND                             \
            a.term_edu        < 5       \
-- ");
-- DMVed -> GIAZ2_4_1Qr -> SQL -> Add ("   \
        AND                             \
            a.town_village    = 0       \
-- ");
-- DMVed -> GIAZ2_4_1Qr -> SQL -> Add ("   \
        AND                             \
            (                           \
                a.type_school = 0       \
             OR                         \
                a.type_school = 3       \
            )                           \
-- ");
-- DMVed -> GIAZ2_4_1Qr -> SQL -> Add ("   \
        AND                             \
            a.when_edu_middle = 2022    \
-- ");
-- DMVed -> GIAZ2_4_3Qr -> SQL -> dd ("    \
    SELECT                              \
        COUNT                           \
        (                               \
            a.nomer_ab                  \
        )                               \
    FROM                                \
        abitura AS a                    \
-- ");
-- DMVed -> GIAZ2_4_3Qr -> SQL -> Add ("   \
    WHERE                               \
            a.status       = 5          \
-- ");
-- DMVed -> GIAZ2_4_3Qr -> SQL -> Add ("   \
        AND                             \
            a.vid_edu      = :vid_edu   \
-- ");
-- DMVed -> GIAZ2_4_3Qr -> SQL -> Add ("   \
        AND                             \
            a.category_if  = 0          \
-- ");
-- DMVed -> GIAZ2_4_3Qr -> SQL -> Add ("   \
        AND                             \
            a.term_edu     < 5          \
-- ");
-- DMVed -> GIAZ2_4_3Qr -> SQL -> Add ("   \
        AND                             \
            a.town_village = 1          \
-- ");
-- DMVed -> GIAZ2_4_3Qr -> SQL -> Add ("   \
        AND                             \
            (                           \
                a.type_school = 0       \
             OR                         \
                a.type_school = 3       \
            )                           \
-- ");
-- DMVed -> GIAZ2_4_3Qr -> SQL -> Add ("   \
        AND                             \
            a.when_edu_middle = 2022    \
-- ");
-- DMVed -> GIAZ2_4_6Qr -> SQL -> Add ("   \
    SELECT                              \
        COUNT                           \
        (                               \
            a.nomer_ab                  \
        )                               \
    FROM                                \
        abitura AS a                    \
-- ");
-- DMVed -> GIAZ2_4_6Qr -> SQL -> Add ("   \
    WHERE                               \
            a.status        = 5         \
-- ");
-- DMVed -> GIAZ2_4_6Qr -> SQL -> Add ("   \
        AND                             \
            a.vid_edu       = :vid_edu  \
-- ");
-- DMVed -> GIAZ2_4_6Qr -> SQL -> Add ("   \
        AND                             \
            a.category_if   = 0         \
-- ");
-- DMVed -> GIAZ2_4_6Qr -> QL -> Add ("    \
        AND                             \
            a.term_edu      < 5         \
-- ");
-- DMVed -> GIAZ2_4_6Qr -> SQL -> Add ("   \
        AND                             \
            a.type_school   = 1         \
-- ");
-- DMVed -> GIAZ2_4_6Qr -> SQL -> Add ("   \
        AND                             \
            a.when_edu_spec = 2022      \
-- ");
-- DMVed -> GIAZ2_4_8Qr -> SQL -> Add ("   \
    SELECT                              \
        COUNT                           \
        (                               \
            a.nomer_ab                  \
        )                               \
    FROM                                \
        abitura AS a                    \
-- ");
-- DMVed -> GIAZ2_4_8Qr -> SQL -> Add ("   \
    WHERE                               \
            a.status        = 5         \
-- ");
-- DMVed -> GIAZ2_4_8Qr -> SQL -> Add ("   \
        AND                             \
            a.vid_edu       = :vid_edu  \
-- ");
-- DMVed -> GIAZ2_4_8Qr -> SQL -> Add ("   \
        AND                             \
            a.category_if   = 0         \
-- ");
-- DMVed -> GIAZ2_4_8Qr -> SQL -> Add ("   \
        AND                             \
            a.term_edu      < 5         \
-- ");
-- DMVed -> GIAZ2_4_8Qr -> SQL -> Add ("   \
        AND                             \
            a.type_school   = 2         \
-- ");
-- DMVed -> GIAZ2_4_8Qr -> SQL -> Add ("   \
        AND                             \
            a.when_edu_spec = 2022      \
-- ");
-- END   > TMainForm::Forma_Giac





-- BEGIN > TMainForm::N21Click
-- AnsiString SQL1 =                                                           // РАСЧЕТ ПОСТУПАЮЩИХ БЕЗ ЭКЗАМЕНОВ (П.21 ПРАВИЛ ПРИЕМА)
--     "                               \
    SELECT                          \
        COUNT                       \
        (                           \
            a.fam                   \
        ),                          \
        a.n_spec                    \
    FROM                            \
        abitura AS a                \
    WHERE                           \
--     ";
-- AnsiString SQL2 = "";
-- AnsiString SQL3 =
--     "                               \
        AND                         \
            a.status  =      :ST    \
        AND                         \
            a.vid_edu =      :EDU   \
        AND                         \
            a.konkurs NOT IN (4)    \
        AND                         \
            a.n_spec  <>     1      \
        AND                         \
            (                       \
                a.n_found <> 2      \
             OR                     \
                a.n_found IS NULL   \
            )                       \
    GROUP BY                        \
        a.n_spec                    \
--     ";
-- SQL2 =                                                                      // Победители и призеры чемп. мира и Европы, участники Олимпийских игр (Wo = 1 или 2)
--     "                           \
        (                       \
            a.without LIKE '1'  \
         OR                     \
            a.without LIKE '2'  \
        )                       \
-- ";
-- SQL2 =                                                                      // Лауреаты фондов Президента РБ (Wo = 3)
--     "                   \
    a.without LIKE '3'  \
--     ";
-- DMStat -> QF2_Sdal -> SQL -> Add ("                 \
    SELECT                                          \
        a.n_spec,                                   \
        COUNT                                       \
        (                                           \
            a.nomer_ab                              \
        )                                           \
    FROM                                            \
        abitura AS a                                \
    WHERE                                           \
            a.status  IN (5)                        \
        AND                                         \
            a.konkurs <> 5                          \
        AND                                         \
            a.vid_edu =  :V_E                       \
        AND                                         \
            a.n_spec  <> 1                          \
        AND                                         \
            (                                       \
                a.n_found <> 2                      \
             OR                                     \
                a.n_found IS NULL                   \
            )                                       \
        AND                                         \
            NOT EXISTS                              \
            (                                       \
                SELECT                              \
                    s.nomer_ab                      \
                FROM                                \
                    sertificat AS s                 \
                WHERE                               \
                    s.nomer_ab = a.nomer_ab         \
                GROUP BY                            \
                    s.nomer_ab                      \
                HAVING COUNT                        \
                (                                   \
                    s.n_predmet                     \
                ) = 3                               \
            )                                       \
        AND                                         \
            EXISTS                                  \
            (                                       \
                SELECT                              \
                    distinct                        \
                        e.nomer_ab                  \
                FROM                                \
                    examen AS e                     \
                WHERE                               \
                        e.nomer_ab    = a.nomer_ab  \
                    AND                             \
                        e.status_ball = 0           \
                GROUP BY                            \
                    e.nomer_ab                      \
            )                                       \
    GROUP BY                                        \
        a.n_spec                                    \
-- ");
-- END   > TMainForm::N21Click




-- BEGIN > TMainForm::N23Click
-- DM -> QSum_Ball -> SQL -> Add ("                \
    SELECT                                      \
        a.nomer_ab,                             \
        SUM                                     \
        (                                       \
            e.ball                              \
        ),                                      \
        a.sum_ball,                             \
        a.middle_ball                           \
    FROM                                        \
        abitura AS a                            \
            INNER JOIN                          \
                examen AS e                     \
                    ON                          \
                        a.nomer_ab = e.nomer_ab \
    WHERE                                       \
            a.status = 0                        \
        AND                                     \
            a.n_fac  = :n_fac                   \
    GROUP BY                                    \
        a.nomer_ab,                             \
        a.sum_ball,                             \
        a.middle_ball                           \
-- ");
-- END   > TMainForm::N23Click




-- BEGIN > TMainForm::N31Click
-- DMStat -> QF2_Zach -> SQL -> Add (" \
    SELECT                          \
        a.n_spec,                   \
        COUNT                       \
        (                           \
            a.nomer_ab              \
        )                           \
    FROM                            \
        abitura AS a                \
    WHERE                           \
            a.status  =  5          \
        AND                         \
            a.vid_edu =  :v_e       \
        AND                         \
            a.n_spec  <> 1          \
    GROUP BY                        \
        a.n_spec                    \
-- ");
-- DMStat -> QF2_Zach -> SQL -> Add (" \
    SELECT                          \
        a.n_spec,                   \
        COUNT                       \
        (                           \
            a.nomer_ab              \
        )                           \
    FROM                            \
        abitura AS a                \
    WHERE                           \
            a.status  =  5          \
        AND                         \
            a.konkurs <> 4          \
        AND                         \
            a.vid_edu =  :v_e       \
        AND                         \
            a.n_spec  <> 1          \
        AND                         \
            a.n_found <> 2          \
    GROUP BY                        \
        a.n_spec                    \
-- ");
-- DMStat -> QF2_Zach -> SQL -> Add (" \
    SELECT                          \
        a.n_spec,                   \
        COUNT                       \
        (                           \
            a.nomer_ab              \
        )                           \
    FROM                            \
        abitura AS a                \
    WHERE                           \
            a.status  =  5          \
        AND                         \
            a.vid_edu =  :v_e       \
        AND                         \
            a.n_spec  <> 1          \
        AND                         \
            a.n_found =  2          \
    GROUP BY                        \
        a.n_spec                    \
-- ");
-- DMStat -> QCount_PO -> SQL -> Add ("    \
    SELECT                              \
        COUNT                           \
        (                               \
            a.fam                       \
        ),                              \
        a.n_spec                        \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.priv    LIKE '15.'        \
        AND                             \
            a.status  =    :st          \
        AND                             \
            a.vid_edu =    0            \
        AND                             \
            a.n_spec  <>   1            \
    GROUP BY                            \
        a.n_spec                        \
-- ");
-- DMStat -> QCount_Medal -> SQL -> Add (" \
    SELECT                              \
        COUNT                           \
        (                               \
            a.fam                       \
        ),                              \
        a.n_spec                        \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.status  =    :st          \
        AND                             \
            a.vid_edu =    :edu         \
        AND                             \
            a.n_spec  <>   1            \
        AND                             \
            a.priv    LIKE '12.'        \
    GROUP BY                            \
        a.n_spec                        \
-- ");
-- DMStat -> QCount_Diplom -> SQL -> Add ("\
    SELECT                              \
        COUNT                           \
        (                               \
            a.fam                       \
        ),                              \
        a.n_spec                        \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.status  =    :st          \
        AND                             \
            a.vid_edu =    :edu         \
        AND                             \
            a.n_spec  <>   1            \
        AND                             \
            a.priv    LIKE '13.'        \
    GROUP BY                            \
        a.n_spec                        \
-- ");
-- DMStat -> QCount_Gimn -> SQL -> Add ("  \
    SELECT                              \
        COUNT                           \
        (                               \
            a.fam                       \
        ),                              \
        a.n_spec                        \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
        a.stat_ab LIKE '3'              \
    AND                                 \
        a.status  =    :st              \
    AND                                 \
        a.vid_edu =    :edu             \
    AND                                 \
        a.n_spec  <>   1                \
    GROUP BY                            \
        a.n_spec                        \
-- ");
-- DMStat -> QCount_Olimp -> SQL -> Add (" \
    SELECT                              \
        COUNT                           \
        (                               \
            a.fam                       \
        ),                              \
        a.n_spec                        \
    FROM                                \
        abitura As a                    \
    WHERE                               \
            (                           \
                a.without LIKE '1'      \
             OR                         \
                a.without LIKE '2'      \
             OR                         \
                a.without LIKE '3'      \
             OR                         \
                a.without LIKE '4'      \
            )                           \
        AND                             \
            a.status  =  :st            \
        AND                             \
            a.vid_edu =  :edu           \
        AND                             \
            a.n_spec  <> 1              \
    GROUP BY                            \
        a.n_spec                        \
-- ");
--AnsiString SQL_Gorod =                                                  // ВЫПУСКНИКИ СЕЛЬСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ - ВСЕХ
--    "                                       \
    SELECT                                  \
        COUNT                               \
        (                                   \
            a.fam                           \
        ),                                  \
        a.n_spec                            \
    FROM                                    \
        abitura AS a                        \
    WHERE                                   \
            a.stat_ab LIKE :n               \
        AND                                 \
            a.status  =    :st              \
        AND                                 \
            a.vid_edu =    :edu             \
        AND                                 \
            a.n_spec  <>   1                \
        AND                                 \
            (                               \
                a.when_edu_middle LIKE :god \
             OR                             \
                a.when_edu_spec   LIKE :god \
            )                               \
    GROUP BY                                \
        a.n_spec                            \
--    ";
-- DMStat -> QCount_Stag -> SQL -> Add ("  \
    SELECT                              \
        COUNT                           \
        (                               \
            a.fam                       \
        ),                              \
        a.n_spec                        \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            (                           \
                a.stag      >= 24       \
             OR                         \
                a.stag_spec >= 24       \
            )                           \
        AND                             \
            a.status  =  :st            \
        AND                             \
            a.vid_edu =  :edu           \
        AND                             \
            a.n_spec  <> 1              \
    GROUP BY                            \
        a.n_spec                        \
-- ");
-- DMStat -> QCount_Region -> SQL -> Add ("    \
    SELECT                                  \
        COUNT                               \
        (                                   \
            --   a.fam                      \
            a.nomer_ab                      \
        ),                                  \
        a.n_spec                            \
    FROM                                    \
        abitura AS a                        \
    WHERE                                   \
            a.gragdan  <> 'РБ'              \
        AND                                 \
            a.status   =  :st               \
        AND                                 \
            a.vid_edu  =  :edu              \
        AND                                 \
            a.n_spec   <> 1                 \
        AND                                 \
            a.n_centre in (122,123,124,125) \
    GROUP BY                                \
        a.n_spec                            \
    ORDER BY                                \
        a.n_spec                            \
-- ");
-- DMStat -> QCount_High -> SQL -> Add ("  \
    SELECT                              \
        COUNT                           \
        (                               \
            a.fam                       \
        ),                              \
        a.n_spec                        \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.status  = :st             \
        AND                             \
            a.vid_edu = :edu            \
        AND                             \
            (                           \
                a.without LIKE '5'      \
             OR                         \
                a.v_k     LIKE '5'      \
             OR                         \
                a.stat_ab LIKE '8'      \
            )                           \
        AND                             \
            a.n_spec <> 1               \
    GROUP BY                            \
        a.n_spec                        \
-- ");
-- DMStat -> QCount_Test -> SQL -> Add ("          \
    SELECT                                      \
        COUNT                                   \
        (                                       \
            a.nomer_ab                          \
        ),                                      \
        a.n_spec                                \
    FROM                                        \
        abitura AS a                            \
    WHERE                                       \
            EXISTS                              \
            (                                   \
                SELECT                          \
                    s.nomer_ab                  \
                FROM                            \
                    sertificat AS s             \
                WHERE                           \
                    s.nomer_ab =  a.nomer_ab    \
                GROUP BY                        \
                    s.nomer_ab                  \
                HAVING COUNT                    \
                (                               \
                    s.n_predmet                 \
                ) = 3                           \
            )                                   \
        AND                                     \
            a.status  =  :st                    \
        AND                                     \
            a.vid_edu =  :edu                   \
        AND                                     \
            a.n_spec  <> 1                      \
    GROUP BY                                    \
        a.n_spec                                \
-- ");
-- DMStat -> QF2_Sdal -> SQL -> Add ("                 \
    SELECT                                          \
        a.n_spec,                                   \
        COUNT                                       \
        (                                           \
            a.nomer_ab                              \
        )                                           \
    FROM                                            \
        abitura AS a                                \
    WHERE                                           \
            a.status  IN (5)                        \
        AND                                         \
            a.konkurs <> 5                          \
        AND                                         \
            a.vid_edu =  :v_e                       \
        AND                                         \
            a.n_spec  <> 1                          \
        AND                                         \
            NOT EXISTS                              \
            (                                       \
                SELECT                              \
                    s.nomer_ab                      \
                FROM                                \
                    sertificat AS s                 \
                WHERE                               \
                    s.nomer_ab =  a.nomer_ab        \
                GROUP BY                            \
                    s.nomer_ab                      \
                HAVING COUNT                        \
                (                                   \
                    s.n_predmet                     \
                ) = 3                               \
            )                                       \
        AND                                         \
            EXISTS                                  \
            (                                       \
                SELECT                              \
                    DISTINCT                        \
                        e.nomer_ab                  \
                FROM                                \
                    examen AS e                     \
                WHERE                               \
                        e.nomer_ab    = a.nomer_ab  \
                    AND                             \
                        e.status_ball = 0           \
                GROUP BY                            \
                    e.nomer_ab                      \
            )                                       \
    GROUP BY                                        \
        a.n_spec                                    \
-- ");
-- DMStat -> QF2_Sdal -> SQL -> Add ("                 \
    SELECT                                          \
        a.n_spec,                                   \
        COUNT                                       \
        (                                           \
            a.nomer_ab                              \
        )                                           \
    FROM                                            \
        abitura AS a                                \
    WHERE                                           \
            a.status  IN (5)                        \
        AND                                         \
            a.konkurs <> 5                          \
        AND                                         \
            a.vid_edu =  :v_e                       \
        AND                                         \
            a.n_spec  <> 1                          \
        AND                                         \
            NOT EXISTS                              \
            (                                       \
                SELECT                              \
                    s.nomer_ab                      \
                FROM                                \
                    sertificat AS s                 \
                WHERE                               \
                    s.nomer_ab =  a.nomer_ab        \
                GROUP BY                            \
                    s.nomer_ab                      \
                HAVING COUNT                        \
                (                                   \
                    s.n_predmet                     \
                ) = 3                               \
            )                                       \
        AND                                         \
            EXISTS                                  \
            (                                       \
                SELECT                              \
                    DISTINCT                        \
                        e.nomer_ab                  \
                FROM                                \
                    examen AS e                     \
                WHERE                               \
                        e.nomer_ab    = a.nomer_ab  \
                    AND                             \
                        e.status_ball = 3           \
                GROUP BY                            \
                    e.nomer_ab                      \
            )                                       \
    GROUP BY                                        \
        a.n_spec                                    \
-- ");
-- DMStat -> QCount_RUOR -> SQL -> Add ("  \
    SELECT                              \
        COUNT                           \
        (                               \
            a.fam                       \
        ),                              \
        a.n_spec                        \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.status  =  :st            \
        AND                             \
            a.vid_edu =  :edu           \
        AND                             \
            a.konkurs =  3              \
        AND                             \
            a.n_spec  <> 1              \
    GROUP BY                            \
        a.n_spec                        \
-- ");
-- END   > TMainForm::N31Click




-- BEGIN > TMainForm::N42Click
-- DM -> QSpisoc_Group -> SQL -> Add ("    \
    SELECT                              \
        a.fam,                          \
        a.name,                         \
        a.otch,                         \
        a.n_specializ,                  \
        a.nom_group,                    \
        a.n_privilege_exam,             \
        a.n_ck,                         \
        a.nomer_ab,                     \
        a.gragdan,                      \
        a.vid_edu,                      \
        a.konkurs,                      \
        a.n_sport_category,             \
        a.v_k,                          \
        a.priv,                         \
        a.without,                      \
        a.n_fac,                        \
        a.middle_ball,                  \
        a.price,                        \
        a.sum_ball                      \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.n_fac  = :n_fac           \
        AND                             \
            a.status = 0                \
    ORDER BY                            \
        a.vid_edu,                      \
        a.n_specializ,                  \
        a.fam,                          \
        a.name,                         \
        a.otch                          \
-- ");
-- END   > TMainForm::N42Click


-- BEGIN > TMainForm::N58Click
-- DM -> QLetterSource -> SQL -> Add ("    \
    SELECT                              \
        a.nomer_ab,                     \
        a.fam,                          \
        a.name,                         \
        a.otch,                         \
        a.address_before                \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.n_fac   = :n_fac          \
        AND                             \
            a.price   = 0               \
        AND                             \
            a.vid_edu = 0               \
        AND                             \
            a.status  = 5               \
    ORDER BY                            \
        a.fam,                          \
        a.name,                         \
        a.otch                          \
-- ");
-- DM -> QLetterSourceKol -> SQL -> Add (" \
    SELECT                              \
        COUNT                           \
        (                               \
            a.nomer_ab                  \
        )                               \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.n_fac   = :n_fac          \
        AND                             \
            a.price   = 0               \
        AND                             \
            a.vid_edu = 0               \
        AND                             \
            a.status  = 5              \
-- ");
-- END   > TMainForm::N58Click




-- BEGIN > TMainForm::N59Click
DM -> QLetterSource ->
        SQL ->
            Add ("                          \
                SELECT                      \
                    a.nomer_ab,             \
                    a.fam,                  \
                    a.name,                 \
                    a.otch,                 \
                    a.address_before        \
                FROM                        \
                    abitura AS a            \
                WHERE                       \
                        a.n_fac   = :n_fac  \
                    AND                     \
                        a.price   = 0       \
                    AND                     \
                        a.vid_edu = 1       \
                    AND                     \
                        a.status  = 5       \
                ORDER BY                    \
                    a.fam,                  \
                    a.name,                 \
                    a.otch                  \
            ");


    DM -> QLetterSourceKol -> Close ();
    DM -> QLetterSourceKol -> SQL -> Clear ();
    DM -> QLetterSourceKol ->
        SQL ->
            Add ("                          \
                SELECT                      \
                    COUNT                   \
                    (                       \
                        a.nomer_ab          \
                    )                       \
                FROM                        \
                    abitura AS a            \
                WHERE                       \
                        a.n_fac   = :n_fac  \
                    AND                     \
                        a.price   = 0       \
                    AND                     \
                        a.vid_edu = 1       \
                    AND                     \
                        a.status  = 5       \
            ");
-- END   > TMainForm::N59Click




-- BEGIN > TMainForm::N62Click
-- DM -> QLetterSource -> SQL -> Add ("    \
    SELECT                              \
        a.nomer_ab,                     \
        a.fam,                          \
        a.name,                         \
        a.otch,                         \
        a.address_before                \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.n_fac   = :n_fac          \
        AND                             \
            a.price   = 1               \
        AND                             \
            a.vid_edu = 0               \
        AND                             \
            a.status  = 5               \
    ORDER BY                            \
        a.fam,                          \
        a.name,                         \
        a.otch                          \
-- ");
-- DM -> QLetterSourceKol -> SQL -> Add (" \
    SELECT                              \
        COUNT                           \
        (                               \
            a.nomer_ab                  \
        )                               \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.n_fac   = :n_fac          \
        AND                             \
            a.price   = 1               \
        AND                             \
            a.vid_edu = 0               \
        AND                             \
            a.status  = 5               \
-- ");
-- END   > TMainForm::N62Click



-- BEGIN > TMainForm::N63Click
-- DM -> QLetterSource -> SQL -> Add ("    \
    SELECT                              \
        a.nomer_ab,                     \
        a.fam,                          \
        a.name,                         \
        a.otch,                         \
        a.address_before                \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.n_fac   = :n_fac          \
        AND                             \
            a.price   = 1               \
        AND                             \
            a.vid_edu = 1               \
        AND                             \
            a.status  = 5               \
    ORDER BY                            \
        a.fam,                          \
        a.name,                         \
        a.otch                          \
-- ");
-- DM -> QLetterSourceKol -> SQL -> Add (" \
    SELECT                              \
        count                           \
        (                               \
            a.nomer_ab                  \
        )                               \
    FROM                                \
        abitura As a                    \
    WHERE                               \
            a.n_fac   = :n_fac          \
        AND                             \
            a.price   = 1               \
        AND                             \
            a.vid_edu = 1               \
        AND                             \
            a.status  = 5               \
-- ");
-- END   > TMainForm::N63Click





-- BEGIN > TMainForm::N112Click
-- DMStat -> QCount_special_ab -> SQL -> Add ("    \
    SELECT                                      \
        a.n_spec,                               \
        COUNT                                   \
        (                                       \
            a.nomer_ab                          \
        )                                       \
    FROM                                        \
        abitura AS a                            \
    WHERE                                       \
            a.status  in (0,2,3,4,5)            \
        AND                                     \
            a.vid_edu =  :edu                   \
        AND                                     \
            a.n_spec  <> 1                      \
    GROUP BY                                    \
        a.n_spec                                \
-- ");
-- DMStat -> QCount_PO -> SQL -> Add ("        \
    SELECT                                  \
        COUNT                               \
        (                                   \
            a.fam                           \
        ),                                  \
        a.n_spec                            \
    FROM                                    \
        abitura AS a                        \
    WHERE                                   \
            a.priv    LIKE '15.'            \
        AND                                 \
            a.status  IN   (0,2,3,4,5)      \
        AND                                 \
            a.vid_edu =    0                \
        AND                                 \
            a.n_spec  <>   1                \
        GROUP BY                            \
            a.n_spec                        \
-- ");
-- DMStat -> QCount_CK -> SQL -> Add ("        \
    SELECT                                  \
        COUNT                               \
        (                                   \
            a.fam                           \
        ),                                  \
        a.n_spec                            \
    FROM                                    \
        abitura AS a                        \
    WHERE                                   \
            a.status  IN (0,2,3,4,5)        \
        AND                                 \
            a.vid_edu =  0                  \
        AND                                 \
            a.konkurs =  2                  \
        AND                                 \
            a.n_spec  <> 1                  \
    GROUP BY                                \
        a.n_spec                            \
-- ");
-- DMStat -> QCount_Medal -> SQL -> Add ("     \
    SELECT                                  \
        COUNT                               \
        (                                   \
            a.fam                           \
        ),                                  \
        a.n_spec                            \
    FROM                                    \
        abitura AS a                        \
    WHERE                                   \
            a.status  IN   (0,2,3,4,5)      \
        AND                                 \
            a.vid_edu =    :edu             \
        AND                                 \
            a.n_spec  <>   1                \
        AND                                 \
            a.priv    LIKE '12.'            \
    GROUP BY                                \
        a.n_spec                            \
-- ");
-- DMStat -> QCount_Diplom -> SQL -> Add ("    \
    SELECT                                  \
        COUNT                               \
        (                                   \
            a.fam                           \
        ),                                  \
        a.n_spec                            \
    FROM                                    \
        abitura AS a                        \
    WHERE                                   \
            a.status  IN   (0,2,3,4,5)      \
        AND                                 \
            a.vid_edu =    :edu             \
        AND                                 \
            a.n_spec  <>   1                \
        AND                                 \
            a.priv    LIKE '13.'            \
    GROUP BY                                \
        a.n_spec                            \
-- ");
-- AnsiString SQL1 =                                                       // ПОДСЧЕТ ВСЕХ 'БЕЗ ЭКЗАМЕНОВ' (П.21 ПРАВИЛ ПРИЕМА)
--     "                               \
    SELECT                          \
        COUNT                       \
        (                           \
            a.fam                   \
        ),                          \
        a.n_spec                    \
    FROM                            \
        abitura AS a                \
    WHERE                           \
--     ";
-- AnsiString SQL2 = "";
-- SQL2 =                                                              // Победители и призеры чемпионатов Мира и Европы, участники Олимпийских игр ( WO = 1 или 2)
--             "                       \
            (                       \
                a.without LIKE '1'  \
             OR                     \
                a.without LIKE '2'  \
            )                       \
--             ";
-- SQL2 =                                                              // Лауреаты фондов Президента РБ (WO = 3)
--             "                   \
            a.without LIKE '3'  \
--             ";
-- SQL2 =
--             "                       \
            (                       \
                a.without LIKE '1'  \
             OR                     \
                a.without LIKE '2'  \
             OR                     \
                a.without LIKE '3'  \
             OR                     \
                a.without LIKE '4'  \
            )                       \
--             ";
-- AnsiString SQL3 =
--     "                               \
        AND                         \
            a.status IN (0,2,3,4,5) \
        AND                         \
            a.vid_edu = :edu        \
        AND                         \
            a.n_spec <> 1           \
        AND                         \
            (                       \
                a.n_found <> 2      \
             OR                     \
                a.n_found IS NULL   \
            )                       \
    GROUP BY                        \
        a.n_spec                    \
--     ";
-- DMStat -> QCount_Gimn -> SQL -> Add ("  \
    SELECT                              \
        COUNT                           \
        (                               \
            a.fam                       \
        ),                              \
        a.n_spec                        \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.stat_ab LIKE '3'          \
        AND                             \
            a.status  IN   (0,2,3,4,5)  \
        AND                             \
            a.vid_edu =    :edu         \
        AND                             \
            a.n_spec  <>   1            \
    GROUP BY                            \
        a.n_spec                        \
-- ");
-- AnsiString SQL_Gorod =                                                  // ВЫПУСКНИКИ ВСЕХ СЕЛЬСКИХ УЧРЕЖДЕНИЙ ОБРАЗОВАНИЯ
--     "                                       \
    SELECT                                  \
        COUNT                               \
        (                                   \
            a.fam                           \
        ),                                  \
        a.n_spec                            \
    FROM                                    \
        abitura AS a                        \
    WHERE                                   \
            a.stat_ab LIKE :n               \
        AND                                 \
            a.status  IN   (0,2,3,4,5)      \
        AND                                 \
            a.vid_edu =    :edu             \
        AND                                 \
            a.n_spec  <>   1                \
        AND                                 \
            (                               \
                a.when_edu_middle LIKE :god \
             OR                             \
                a.when_edu_spec   LIKE :god \
            )                               \
    GROUP BY                                \
        a.n_spec                            \
--     ";
-- DMStat -> QCount_Stag -> SQL -> Add ("      \
    SELECT                                  \
        COUNT                               \
        (                                   \
            a.fam                           \
        ),                                  \
        a.n_spec                            \
    FROM                                    \
        abitura AS a                        \
    WHERE                                   \
            (                               \
                a.stag      >= 24           \
             OR                             \
                a.stag_spec >= 24           \
            )                               \
        AND                                 \
            a.status  IN (0,2,3,4,5)        \
        AND                                 \
            a.vid_edu =  :edu               \
        AND                                 \
            a.n_spec  <> 1                  \
    GROUP BY                                \
        a.n_spec                            \
-- ");
-- DMStat -> QCount_Test -> SQL -> Add ("          \
    SELECT                                      \
        COUNT                                   \
        (                                       \
            a.nomer_ab                          \
        ),                                      \
        a.n_spec                                \
    FROM                                        \
        abitura AS a                            \
    WHERE                                       \
            EXISTS (                            \
                SELECT                          \
                    s.nomer_ab                  \
                FROM                            \
                    sertificat AS s             \
                WHERE                           \
                    s.nomer_ab =  a.nomer_ab    \
                GROUP BY                        \
                    s.nomer_ab                  \
                HAVING                          \
                    COUNT                       \
                    (                           \
                        s.n_predmet             \
                    ) = 3                       \
                )                               \
        AND                                     \
            a.status  IN (0,2,3,4,5)            \
        AND                                     \
            a.vid_edu =  :edu                   \
        AND                                     \
            a.n_spec  <> 1                      \
    GROUP BY                                    \
        a.n_spec                                \
-- ");
-- DMStat -> QCount_RUOR -> SQL -> Add ("          \
    SELECT                                      \
        COUNT                                   \
        (                                       \
            a.fam                               \
        ),                                      \
        a.n_spec                                \
    FROM                                        \
        abitura AS a                            \
    WHERE                                       \
            a.status  IN (0,2,3,4,5)            \
        AND                                     \
            a.vid_edu =  :edu                   \
        AND                                     \
            a.konkurs =  3                      \
        AND                                     \
            a.n_spec  <> 1                      \
    GROUP BY                                    \
        a.n_spec                                \
-- ");
-- DMStat -> QCount_Region -> SQL -> Add ("        \
    SELECT                                      \
        COUNT                                   \
        (                                       \
            a.nomer_ab                          \
        ),                                      \
        a.n_spec                                \
    FROM                                        \
        abitura AS a                            \
    WHERE                                       \
            a.gragdan  <> 'РБ'                  \
        AND                                     \
            a.n_centre IN (122,123,124,125)     \
        AND                                     \
            a.status   IN (0,2,3,4,5)           \
        AND                                     \
            a.vid_edu  =  :edu                  \
        AND                                     \
            a.n_spec   <> 1                     \
    GROUP BY                                    \
        a.n_spec                                \
-- ");
-- DMStat -> QCount_High -> SQL -> Add ("  \
    SELECT                              \
        COUNT                           \
        (                               \
            a.fam                       \
        ),                              \
        a.n_spec                        \
    FROM                                \
        abitura AS a                    \
    WHERE                               \
            a.status  in (0,2,3,4,5)    \
        AND                             \
            a.vid_edu =  :edu           \
        AND                             \
            a.n_spec  <> 1              \
        AND                             \
            (                           \
                a.without LIKE '5'      \
             OR                         \
                a.v_k     LIKE '5'      \
             OR                         \
                a.stat_ab LIKE '8'      \
            )                           \
    GROUP BY                            \
        a.n_spec                        \
-- ");
-- END   > TMainForm::N112Click




-- BEGIN > TMainForm::Zachisl_Sertificat
-- DMStat -> QZachisl_Sertificat -> SQL ->  Add ("     \
    SELECT                                          \
        a.nomer_ab,                                 \
        a.konkurs,                                  \
        a.fam,                                      \
        a.name,                                     \
        a.otch,                                     \
        a.pasport,                                  \
        a.n_found,                                  \
        s.n_predmet,                                \
        s.rus_bel,                                  \
        p.text_predmet,                             \
        s.seria_s,                                  \
        s.nomer_s,                                  \
        s.balls                                     \
    FROM                                            \
        abitura AS a                                \
            LEFT JOIN                               \
                sertificat AS s                     \
                    ON                              \
                        s.nomer_ab  = a.nomer_ab    \
            LEFT JOIN                               \
                predmet AS p                        \
                    ON                              \
                        p.n_predmet = s.n_predmet   \
    WHERE                                           \
            a.status  =  5                          \
        AND                                         \
            a.vid_edu IN (0, 1)                     \
        AND                                         \
            a.n_fac   IN (1, 2, 3, 4)               \
    ORDER BY                                        \
        a.fam,                                      \
        a.name,                                     \
        a.otch                                      \
-- ");
-- END   > TMainForm::Zachisl_Sertificat