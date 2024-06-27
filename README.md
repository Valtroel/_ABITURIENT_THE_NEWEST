# ABITURIENT 2022 project (*candidates*)

## CONTENT

1. [Abiturient 2022][app] (*application*)
   * Model
      * Connection
      * Data source
      * [SQL queries][sql]
   * View
      * Forms <!-- [Forms][dfm] -->
   * Controller
2. Configuration
      1. *Installation*
      2. *Dependencies*
      3. *Settings*
         1. Interface
         2. Database
         3. Reports
3. [Database Abiturient][dba]
   * [Generators][gen]
   * Metadata
   * [Procedures][pro]
   * Structure
   * [Tables][tbl]
   * [Triggers][tri]
   * Views

### List of documents

| No | **Old name**                                        | **New name**                                               |
|:--:|:----------------------------------------------------|:-----------------------------------------------------------|
| 1  | Cтатистика по баллам 2021.xls                       | СТАТИСТИКА - Баллы (2022).xls                              |
| 2  | Договор 2021 бюджет.xls                             | ДОГОВОР - Бюджет (2022).xls                                |
| 3  | Договор 2021 платное.xls                            | ДОГОВОР - Платники (2022).xls                              |
| 4  | Ежедневная статистика 2021.xls                      | СТАТИСТИКА - Ежедневная.xls                                |
| 5  | Ежедневный протокол 2021.xls                        | ПРОТОКОЛ - Ежедневный.xls                                  |
| 6  | Журнал регистрации_.xls                             | ЖУРНАЛ - Регистрация.xls                                   |
| 7  | Заявление.xls                                       | ЗАЯВЛЕНИЕ - Допуск к участию.xls                           |
| 8  | Количество бюджетных мест.xls                       | СТАТИСТИКА - Кол-во бюджетных мест.xls                     |
| 9  | Конкурс 2021.xls                                    | СТАТИСТИКА - Конкурс (2022).xls                            |
| 10 | Конкурс цифры по факультету.xls                     | СТАТИСТИКА - Конкурс по факультетам.xls                    |
| 11 | Отчет (подано заявлений итоговая).xls               | ОТЧЕТ - Подано заявлений.xls                               |
| 12 | Полный список.xls                                   | СПИСОК.xls                                                 |
| 13 | Протокол для Грасс 2019.doc                         | ПРОТОКОЛ - О допуске абитуриентов (2022).doc               |
| 14 | Протокол_Ж(4 вида).xls                              | ПРОТОКОЛ - Испытаний (Девушки).xls                         |
| 15 | Результаты поданных сертификатов ИТ.xls             | СТАТИСТИКА - Результаты сертификатов (стобалльная).xls     |
| 16 | Результаты поданных сертификатов.xls                | СТАТИСТИКА - Результаты сертификатов (десятибалльная).xls  |
| 17 | Результаты сдачи вступительных экзаменов.xls        | СТАТИСТИКА - Результаты сдачи экзаменов.xls                |
| 18 | Сводная ведомость вступительных экзаменов 2021.xls  | ВЕДОМОСТЬ - Вступительных экзаменов (2022).xls             |
| 19 | Сводная ведомость вступительных экзаменов.xls       | ВЕДОМОСТЬ - Вступительных экзаменов (В.В. Коваленя).xls    |
| 20 | Сводная ведомость вступительных экзаменов_ИТ.xls    | ВЕДОМОСТЬ - Вступительных экзаменов (А.А. Ермакова).xls    |
| 21 | Уровень спортивной подготовленности.xls             | СТАТИСТИКА - Уровень спортивной подготовки.xls             |
| 22 | Форма 1_2021.xls                                    | ОТЧЕТ - Форма 1 (2022).xls                                 |
| 23 | Форма 2_2021.xls                                    | ОТЧЕТ - Форма 2 (2022).xls                                 |
| 24 | Экзаменационная ведомость.xls                       | ПРОТОКОЛ – Экзамен по ФКиС.xls                             |
| 25 | Экзаменационная ведомость_ИТ.xls                    | ИНСТРУКТАЖ - Экзаменационная.xls                           |

[app]: res/read/application/app_abiturient_2022.md
[sql]: res/read/application/queries_abiturient.md
[dfm]: res/read/application/dfm
[dba]: res/read/db/db_abiturient_2022.md
[gen]: res/read/db/generators/DB_ABITURIENT_GENERATORS.md
[pro]: res/read/db/procedures/DB_ABITURIENT_PROCEDURES.md
[tbl]: res/read/db/db_abiturient_2022.md
[tri]: res/read/db/triggers/DB_ABITURIENT_TRIGGERS.md


| No | **New name**                                               | *constexpr auto*              | **Old name**                                        |
|:--:|:-----------------------------------------------------------|:------------------------------|:----------------------------------------------------|
| 1  | ВЕДОМОСТЬ - Вступительных экзаменов (2022).xls             | SUMMARY_LIST_ENTR_EXAM        | Сводная ведомость вступительных экзаменов 2021.xls  |
| 2  | ВЕДОМОСТЬ - Вступительных экзаменов (А.А. Ермакова).xls    | SUMMARY_LIST_ENTR_EXAM_ERM    | Сводная ведомость вступительных экзаменов_ИТ.xls    |
| 3  | ВЕДОМОСТЬ - Вступительных экзаменов (В.В. Коваленя).xls    | SUMMARY_LIST_ENTR_EXAM_KOVAL  | Сводная ведомость вступительных экзаменов.xls       |
| 4  | ДОГОВОР - Бюджет (2022).xls                                | CONTRACT_BUDGET               | Договор 2021 бюджет.xls                             |
| 5  | ДОГОВОР - Платники (2022).xls                              | CONTRACT_PAYERS               | Договор 2021 платное.xls                            |
| 6  | ЖУРНАЛ - Регистрация.xls                                   | REGISTRY_BOOK                 | Журнал регистрации_.xls                             |
| 7  | ЗАЯВЛЕНИЕ - Допуск к участию.xls                           | APPLICATION_FOR_ADMITION      | Заявление.xls                                       |
| 8  | ИНСТРУКТАЖ - Экзаменационная.xls                           | BRIEFING_BEFORE_EXAM          | Экзаменационная ведомость_ИТ.xls                    |
| 9  | ОТЧЕТ - Подано заявлений.xls                               | REPORT_SUBMITTED              | Отчет (подано заявлений итоговая).xls               |
| 10 | ОТЧЕТ - Форма 1 (2022).xls                                 | REPORT_FORM_1                 | Форма 1_2021.xls                                    |
| 11 | ОТЧЕТ - Форма 2 (2022).xls                                 | REPORT_FORM_2                 | Форма 2_2021.xls                                    |
| 12 | ПРОТОКОЛ - Ежедневный.xls                                  | PROTOCOL_DAILY                | Ежедневный протокол 2021.xls                        |
| 13 | ПРОТОКОЛ - Испытаний (Девушки).xls                         | PROTOCOL_GIRLS_TESTS          | Протокол_Ж(4 вида).xls                              |
| 14 | ПРОТОКОЛ - О допуске абитуриентов (2022).doc               | PROTOCOL_ADMITTED             | Протокол для Грасс 2019.doc                         |
| 15 | ПРОТОКОЛ – Экзамен по ФКиС.xls                             | PROTOCOL_EXAM                 | Экзаменационная ведомость.xls                       |
| 16 | СПИСОК.xls                                                 | LIST_                         | Полный список.xls                                   |
| 17 | СТАТИСТИКА - Баллы (2022).xls                              | STATISTIC_SCORES              | Cтатистика по баллам 2021.xls                       |
| 18 | СТАТИСТИКА - Ежедневная.xls                                | STATISTIC_DAILY               | Ежедневная статистика 2021.xls                      |
| 19 | СТАТИСТИКА - Кол-во бюджетных мест.xls                     | STATISTIC_BUDGET_SEATS        | Количество бюджетных мест.xls                       |
| 20 | СТАТИСТИКА - Конкурс (2022).xls                            | STATISTIC_CONTEST             | Конкурс 2021.xls                                    |
| 21 | СТАТИСТИКА - Конкурс по факультетам.xls                    | STATISTIC_CONTEST_BY_FACULTY  | Конкурс цифры по факультету.xls                     |
| 22 | СТАТИСТИКА - Результаты сдачи экзаменов.xls                | STATISTIC_EXAM_RESULT         | Результаты сдачи вступительных экзаменов.xls        |
| 23 | СТАТИСТИКА - Результаты сертификатов (десятибалльная).xls  | STATISTIC_CERT_RESULT_TEN     | Результаты поданных сертификатов.xls                |
| 24 | СТАТИСТИКА - Результаты сертификатов (стобалльная).xls     | STATISTIC_CERT_RESULT_HUNDRED | Результаты поданных сертификатов ИТ.xls             |
| 25 | СТАТИСТИКА - Уровень спортивной подготовки.xls             | STATISTIC_LEVEL_OF_SPORTS     | Уровень спортивной подготовленности.xls             |

<!--
constexpr auto SUMMARY_LIST_ENTR_EXAM        = "ВЕДОМОСТЬ - Вступительных экзаменов (2022).xls";              // |Сводная ведомость вступительных экзаменов 2021.xls|
constexpr auto SUMMARY_LIST_ENTR_EXAM_ERM    = "ВЕДОМОСТЬ - Вступительных экзаменов (А.А. Ермакова).xls";     // |Сводная ведомость вступительных экзаменов_ИТ.xls|
constexpr auto SUMMARY_LIST_ENTR_EXAM_KOVAL  = "ВЕДОМОСТЬ - Вступительных экзаменов (В.В. Коваленя).xls";     // |Сводная ведомость вступительных экзаменов.xls|
constexpr auto CONTRACT_BUDGET               = "ДОГОВОР - Бюджет (2022).xls";                                 // |Договор 2021 бюджет.xls|
constexpr auto CONTRACT_PAYERS               = "ДОГОВОР - Платники (2022).xls";                               // |Договор 2021 платное.xls|
constexpr auto REGISTRY_BOOK                 = "ЖУРНАЛ - Регистрация.xls";                                    // |Журнал регистрации_.xls|
constexpr auto APPLICATION_FOR_ADMITION      = "ЗАЯВЛЕНИЕ - Допуск к участию.xls";                            // |Заявление.xls|
constexpr auto BRIEFING_BEFORE_EXAM          = "ИНСТРУКТАЖ - Экзаменационная.xls";                            // |Экзаменационная ведомость_ИТ.xls|
constexpr auto REPORT_SUBMITTED              = "ОТЧЕТ - Подано заявлений.xls";                                // |Отчет (подано заявлений итоговая).xls|
constexpr auto REPORT_FORM_1                 = "ОТЧЕТ - Форма 1 (2022).xls";                                  // |Форма 1_2021.xls|
constexpr auto REPORT_FORM_2                 = "ОТЧЕТ - Форма 2 (2022).xls";                                  // |Форма 2_2021.xls|
constexpr auto PROTOCOL_DAILY                = "ПРОТОКОЛ - Ежедневный.xls";                                   // |Ежедневный протокол 2021.xls|
constexpr auto PROTOCOL_GIRLS_TESTS          = "ПРОТОКОЛ - Испытаний (Девушки).xls";                          // |Протокол_Ж(4 вида).xls|
constexpr auto PROTOCOL_ADMITTED             = "ПРОТОКОЛ - О допуске абитуриентов (2022).doc";                // |Протокол для Грасс 2019.doc|
constexpr auto PROTOCOL_EXAM                 = "ПРОТОКОЛ – Экзамен по ФКиС.xls";                              // |Экзаменационная ведомость.xls|
constexpr auto LIST_                         = "СПИСОК.xls";                                                  // |Полный список.xls|
constexpr auto STATISTIC_SCORES              = "СТАТИСТИКА - Баллы (2022).xls";                               // |Cтатистика по баллам 2021.xls|
constexpr auto STATISTIC_DAILY               = "СТАТИСТИКА - Ежедневная.xls";                                 // |Ежедневная статистика 2021.xls|
constexpr auto STATISTIC_BUDGET_SEATS        = "СТАТИСТИКА - Кол-во бюджетных мест.xls";                      // |Количество бюджетных мест.xls|
constexpr auto STATISTIC_CONTEST             = "СТАТИСТИКА - Конкурс (2022).xls";                             // |Конкурс 2021.xls|
constexpr auto STATISTIC_CONTEST_BY_FACULTY  = "СТАТИСТИКА - Конкурс по факультетам.xls";                     // |Конкурс цифры по факультету.xls|
constexpr auto STATISTIC_EXAM_RESULT         = "СТАТИСТИКА - Результаты сдачи экзаменов.xls";                 // |Результаты сдачи вступительных экзаменов.xls|
constexpr auto STATISTIC_CERT_RESULT_TEN     = "СТАТИСТИКА - Результаты сертификатов (десятибалльная).xls";   // |Результаты поданных сертификатов.xls|
constexpr auto STATISTIC_CERT_RESULT_HUNDRED = "СТАТИСТИКА - Результаты сертификатов (стобалльная).xls";      // |Результаты поданных сертификатов ИТ.xls|
constexpr auto STATISTIC_LEVEL_OF_SPORTS     = "СТАТИСТИКА - Уровень спортивной подготовки.xls";              // |Уровень спортивной подготовленности.xls|
-->