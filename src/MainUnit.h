#pragma once
#ifndef MAIN_UNIT_H
#define MAIN_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
//#include "RXCtrls.hpp"
#include <StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>


#include "enums.hpp"
#include "properties.hpp"
#include "Ncrb011TemporaryConverter.h"


#define USE_NEW_HANDLERS
//#define TESTING_MAIN_UNIT


class TMainForm
    : public TForm
{
__published:
    TDBGrid      * DBGrid1;

    TLabel       * Label1;       // Последний номер дела:
    TLabel       * Label2;       // Дневная, полный, бюджет:
    TLabel       * Label3;       // Дневная, полный, за оплату:
    TLabel       * Label4;       // Дневная, сокращённый, бюджет:
    TLabel       * Label5;       // Дневная, сокращённый, за оплату:
    TLabel       * Label6;       // Заочная, полный, бюджет:
    TLabel       * Label7;       // Заочная, полный, за оплату:
    TLabel       * Label8;       // Заочная, сокращённый, бюджет:
    TLabel       * Label9;       // Заочная, сокращённый, за оплату:
    TLabel       * NumDelaLbl1;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl2;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl3;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl4;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl5;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl6;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl7;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl8;  // get values from AbiturForm -> max_nom_dela()

    TMainMenu    * MainMenu1;

    TMenuItem    * N1;           // Кнопка вызова формы: "АБИТУРИЕНТ"
    TMenuItem    * N2;           // Кнопка вызова формы: "ГРУППЫ" {N2} (содержит подменю)
    TMenuItem    * N3;           // Кнопка вызова формы: "ЭКЗАМЕНЫ" {N3} (содержит подменю)
    TMenuItem    * N4;           // Кнопка вызова формы: "ЭКЗАМЕНЫ" {N3} -> Ведомости на группу (Вызывает форму: ExamenForm)
    TMenuItem    * N5;           // Кнопка вызова формы: "ЭКЗАМЕНЫ" {N3} -> Результаты (Вызывает форму: Result_ExamForm)
    TMenuItem    * N6;           // Кнопка вызова формы: "ЭКЗАМЕНЫ" {N3} -> Аппеляции (Вызывает форму: ApellForm)
    TMenuItem    * N7;           // Кнопка вызова формы: "СТАТИСТИКА" {N7} (содержит подменю)
    TMenuItem    * N8;           // Кнопка вызова формы: "ЗАЧИСЛЕНИЕ" {N8} (содержит подменю)
    TMenuItem    * N9;           // "СТАТИСТИКА" {N7} -> ГИАЦ
    TMenuItem    * N10;          // "ЗАЧИСЛЕНИЕ" {N8} -> Сводная ведомость дневная (оплата) [INVISIBLE]
    TMenuItem    * N11;          // "НАСТРОЙКИ" {N11} (содержит подменю)
    TMenuItem    * N12;          // Вызов функции: "ВЫХОД"
    TMenuItem    * N13;          // ГРУППЫ {N2}     -> Краткий список групп
    TMenuItem    * N14;          // ГРУППЫ {N2}     -> Полный список групп
    TMenuItem    * N15;          // СТАТИСТИКА {N7} -> Кол-во поданных заявлений (ежедневная)
    TMenuItem    * N16;          // ЭКЗАМЕНЫ {N3}   -> Восстановление по справке
    TMenuItem    * N17;          // ЭКЗАМЕНЫ {N3}   -> Результаты победителей олимпиады
    TMenuItem    * N18;          // ЭКЗАМЕНЫ {N3}   -> --------------------------------
    TMenuItem    * N19;          // ЭКЗАМЕНЫ {N3}   -> --------------------------------
    TMenuItem    * N20;          // СТАТИСТИКА {N7} -> Министерство образования [INVISIBLE]
    TMenuItem    * N21;          // СТАТИСТИКА {N7} -> Министерство образования {N20} [INVISIBLE]     -> Форма 2
    TMenuItem    * N22;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость дневная (бюджет) [INVISIBLE]
    TMenuItem    * N23;          // ЗАЧИСЛЕНИЕ {N8} -> Просуммировать экз. оценки
    TMenuItem    * N24;          // ЗАЧИСЛЕНИЕ {N8} -> --------------------------------
    TMenuItem    * N25;          // ЗАЧИСЛЕНИЕ {N8} -> --------------------------------
    TMenuItem    * N26;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость на 2 курс [INVISIBLE]
    TMenuItem    * N27;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость заочная (бюджет) [INVISIBLE]
    TMenuItem    * N28;          // СТАТИСТИКА {N7} -> Протокол (ежедневный)
    TMenuItem    * N29;          // СТАТИСТИКА {N7} -> Формы для отчета
    TMenuItem    * N30;          // СТАТИСТИКА {N7} -> Формы для отчета {N29}                         -> Сведения о приеме заявлений по регионам [INVISIBLE]
    TMenuItem    * N31;          // СТАТИСТИКА {N7} -> Министерство образования {N20} [INVISIBLE]     -> Форма 3
    TMenuItem    * N32;          // СТАТИСТИКА {N7} -> Формы для отчета {N29}                         -> Подано заявлений (итоговая)
    TMenuItem    * N33;          // ЭКЗАМЕНЫ {N3}   -> Ведомости по напралениям
    TMenuItem    * N34;          // ЗАЧИСЛЕНИЕ {N8} -> -------------------------------- [INVISIBLE]
    TMenuItem    * N35;          // ЗАЧИСЛЕНИЕ {N8} -> Приказ на зачисление
    TMenuItem    * N36;          // СТАТИСТИКА {N7} -> Результаты вступительных испытаний
    TMenuItem    * N37;          // СТАТИСТИКА {N7} -> Формы для отчета {N29}                         -> Уровень спортивной подготовленности
    TMenuItem    * N38;          // СТАТИСТИКА {N7} -> Госконтроль [INVISIBLE]
    TMenuItem    * N39;          // СТАТИСТИКА {N7} -> Госконтроль {N38} [INVISIBLE]                  -> Информация о ходе приема
    TMenuItem    * N40;          // СТАТИСТИКА {N7} -> Результаты изложения [INVISIBLE]
    TMenuItem    * N41;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость заочная (оплата) [INVISIBLE]
    TMenuItem    * N42;          // ГРУППЫ {N2}     -> Список по направлениям
    TMenuItem    * N43;          // СТАТИСТИКА {N7} -> Кол-во поданных заявлений по баллам
    TMenuItem    * N44;          // СТАТИСТИКА {N7} -> Формы для отчета {N29}                         -> Подано заявлений по направлениям
    TMenuItem    * N45;          // СТАТИСТИКА {N7} -> ГИАЦ {N9}                                      -> Форма 1 (прием) {N116}                  -> Дневная форма обучения
    TMenuItem    * N46;          // СТАТИСТИКА {N7} -> ГИАЦ {N9}                                      -> Форма 2 (зачисление) {N210}             -> Дневная форма обучения
    TMenuItem    * N47;          // СТАТИСТИКА {N7} -> ГИАЦ {N9}                                      -> Форма 1 (прием) {N116}                  -> Заочная форма обучения
    TMenuItem    * N48;          // СТАТИСТИКА {N7} -> ГИАЦ {N9}                                      -> Форма 2 (зачисление) {N210}             -> Заочная форма обучения
    TMenuItem    * N49;          // ЭКЗАМЕНЫ {N3}   -> Протоколы
    TMenuItem    * N52;          // НАСТРОЙКИ {N11} -> Справочники
    TMenuItem    * N53;          // НАСТРОЙКИ {N11} -> Ограничение прав доступа
    TMenuItem    * N54;          // ЭКЗАМЕНЫ {N3}   -> Протоколы {N49}                                -> КУ по ФКиС [INVISIBLE]
    TMenuItem    * N55;          // СТАТИСТИКА {N7} -> Конкурс [INVISIBLE]
    TMenuItem    * N56;          // ЗАЧИСЛЕНИЕ {N8} -> --------------------------------
    TMenuItem    * N57;          // ЗАЧИСЛЕНИЕ {N8} -> Печать извещений и конвертов
    TMenuItem    * N58;          // ЗАЧИСЛЕНИЕ {N8} -> Печать извещений и конвертов {N57}             -> бюджет {N60}                            -> дневная
    TMenuItem    * N59;          // ЗАЧИСЛЕНИЕ {N8} -> Печать извещений и конвертов {N57}             -> бюджет {N60}                            -> заочная
    TMenuItem    * N60;          // ЗАЧИСЛЕНИЕ {N8} -> Печать извещений и конвертов {N57}             -> бюджет
    TMenuItem    * N61;          // ЗАЧИСЛЕНИЕ {N8} -> Печать извещений и конвертов {N57}             -> за оплату
    TMenuItem    * N62;          // ЗАЧИСЛЕНИЕ {N8} -> Печать извещений и конвертов {N57}             -> за оплату {N61}                         -> дневная
    TMenuItem    * N63;          // ЗАЧИСЛЕНИЕ {N8} -> Печать извещений и конвертов {N57}             -> за оплату {N61}                         -> заочная
    TMenuItem    * N64;          // СТАТИСТИКА {N7} -> Журнал регистрации документов
    TMenuItem    * N65;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость полный срок
    TMenuItem    * N66;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость полный срок {N65}            -> Дневная форма обучения
    TMenuItem    * N67;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость полный срок {N65}            -> Заочная форма обучения
    TMenuItem    * N68;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость полный срок {N65}            -> Дневная форма обучения {N66}            -> Бюджет
    TMenuItem    * N69;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость полный срок {N65}            -> Дневная форма обучения {N66}            -> За оплату
    TMenuItem    * N70;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость полный срок {N65}            -> Заочная форма обучения {N67}            -> Бюджет
    TMenuItem    * N71;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость полный срок {N65}            -> Заочная форма обучения {N67}            -> За оплату
    TMenuItem    * N72;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость сокращённый срок
    TMenuItem    * N73;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость сокращённый срок {N72}       -> Дневная форма обучения
    TMenuItem    * N74;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость сокращённый срок {N72}       -> Заочная форма обучения
    TMenuItem    * N75;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость сокращённый срок {N72}       -> Дневная форма обучения {N73}            -> Бюджет
    TMenuItem    * N76;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость сокращённый срок {N72}       -> Дневная форма обучения {N73}            -> За оплату
    TMenuItem    * N77;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость сокращённый срок {N72}       -> Заочная форма обучения {N74}            -> Бюджет
    TMenuItem    * N78;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость сокращённый срок {N72}       -> Заочная форма обучения {N74}            -> За оплату
    TMenuItem    * N79;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость 2 ВО 2 курс {N221}           -> Дневная форма обучения
    TMenuItem    * N80;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость 2 ВО 2 курс {N221}           -> Заочная форма обучения
    TMenuItem    * N81;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость 2 ВО 2 курс {N221}           -> Дневная форма обучения {N79}            -> Бюджет
    TMenuItem    * N82;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость 2 ВО 2 курс {N221}           -> Заочная форма обучения {N80}            -> Бюджет
    TMenuItem    * N83;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость 2 ВО 2 курс {N221}           -> Дневная форма обучения {N79}            -> За оплату
    TMenuItem    * N84;          // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость 2 ВО 2 курс {N221}           -> Заочная форма обучения {N80}            -> За оплату
    TMenuItem    * N85;          // ЗАЧИСЛЕНИЕ {N8} -> Титульный лист личного дела
    TMenuItem    * N86;          // ГРУППЫ {N2}     -> Список групп по полу
    TMenuItem    * N110;         // СТАТИСТИКА {N7} -> Министерство образования {N20} [INVISIBLE]     -> Форма 1-К (о кол-ве поданных заявлений)
    TMenuItem    * N111;         // СТАТИСТИКА {N7} -> Министерство образования {N20} [INVISIBLE]     -> Форма 1-ПБ (конкурс и проходной балл)
    TMenuItem    * N112;         // СТАТИСТИКА {N7} -> Министерство образования {N20} [INVISIBLE]     -> Форма 1
    TMenuItem    * N113;         // СТАТИСТИКА {N7} -> Министерство образования {N20} [INVISIBLE]     -> Форма 1М (поступление медалистов)
    TMenuItem    * N114;         // СТАТИСТИКА {N7} -> Министерство образования {N20} [INVISIBLE]     -> Форма 1Ц (прием по целевому контракту)
    TMenuItem    * N115;         // СТАТИСТИКА {N7} -> Министерство образования {N20} [INVISIBLE]     -> Форма 1уи (прохождение вступительных экзаменов)
    TMenuItem    * N116;         // СТАТИСТИКА {N7} -> ГИАЦ {N9}                                      -> Форма 1 (прием)
    TMenuItem    * N210;         // СТАТИСТИКА {N7} -> ГИАЦ {N9}                                      -> Форма 2 (зачисление)
    TMenuItem    * N221;         // ЗАЧИСЛЕНИЕ {N8} -> Сводная ведомость 2 ВО 2 курс
    TMenuItem    * N310;         // СТАТИСТИКА {N7} -> ГИАЦ {N9}                                      -> Форма 1-ВУЗ зачисление дневная бюджет [INVISIBLE]
    TMenuItem    * N311;         // ЭКЗАМЕНЫ {N3}   -> Протоколы {N49}                                -> 4 стандартных вида
    TMenuItem    * N1001;        // ЭКЗАМЕНЫ {N3}   -> Протоколы {N49}                                -> ОФП Бег 100         [INVISIBLE]
    TMenuItem    * N150010001;   // ЭКЗАМЕНЫ {N3}   -> Протоколы {N49}                                -> ОФП Бег 1500 (1000) [INVISIBLE]

    TShape       * Shape1;

    TSpeedButton * SpeedButton1; // Смена факультета
    TSpeedButton * SpeedButton2; // Обновить последний номер дела
    TSpeedButton * SpeedButton3; // Сертификаты по критериям
    TSpeedButton * SpeedButton4; // Формирует: Отчет об итогах приемной компании

    void __fastcall FormActivate      (TObject * Sender);
    void __fastcall FormClose         (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCloseQuery    (
            TObject * Sender,
            bool    & CanClose
        );
    void __fastcall FormCreate        (TObject * Sender);
    void __fastcall N1Click           (TObject * Sender);// Вызывает форму: AbiturForm "АБИТУРИЕНТ"
    void __fastcall N4Click           (TObject * Sender);// Вызывает форму: ExamenForm "ГРУППЫ"
    void __fastcall N5Click           (TObject * Sender);// Вызывает форму: Result_ExamForm "Настроек отчета по результатом экзаменов"
    void __fastcall N6Click           (TObject * Sender);// Вызывает форму: ApellForm "Меню - НАСТРОЙКИ"
    void __fastcall N10Click          (TObject * Sender);// Сводная ведомость (Дневное -> Платники)                                     [INVISIBLE]
    void __fastcall N12Click          (TObject * Sender);// ВЫХОД
    void __fastcall N13Click          (TObject * Sender);// Формирует: Краткий список групп на факультете
    void __fastcall N14Click          (TObject * Sender);// Формирует: Полный список групп на факультете
    void __fastcall N15Click          (TObject * Sender);// Формирует: Статистику по кол-ву поданных заявлений (ежедневная)
    void __fastcall N16Click          (TObject * Sender);// Вызывает форму: Undo_SpravkaForm
    void __fastcall N17Click          (TObject * Sender);// Вызывает форму: Dop_ResultForm добавления языка победителей олимпиад БГУ
    void __fastcall N21Click          (TObject * Sender);// (CAN'T OPERATE!!!!) Форма 2 (результаты экзаменов и зачисление студентов)   [INVISIBLE]
    void __fastcall N22Click          (TObject * Sender);// Сводная ведомость (Дневное -> Бюджет)                                       [INVISIBLE]
    void __fastcall N23Click          (TObject * Sender);// СУММИРОВАНИЕ РЕЗУЛЬТАТОВ ЭКЗАМЕНОВ
    void __fastcall N26Click          (TObject * Sender);// Формирует: Сводная ведомость для 2 курса                                    [INVISIBLE]
    void __fastcall N27Click          (TObject * Sender);// Формирует: Сводная ведомость (Заочка -> Бюджет)                             [INVISIBLE]
    void __fastcall N28Click          (TObject * Sender);// Вызывает форму: Dlg_ProtokolForm "Протокол (ежедневный)"
    void __fastcall N30Click          (TObject * Sender);// Формирует: Подача заявлений по регионам (CAN'T OPERATE!!!!)                 [INVISIBLE]
    void __fastcall N31Click          (TObject * Sender);// Формирует: Форма 3 (дневная и заочная)  (CAN'T OPERATE!!!!)                 [INVISIBLE]
    void __fastcall N32Click          (TObject * Sender);// Формирует: Отчет Подано заявлений (итоговая)
    void __fastcall N33Click          (TObject * Sender);// Вызывает форму: ExamenSpecForm
    void __fastcall N35Click          (TObject * Sender);// Вызывает форму: Group_FacForm
    void __fastcall N36Click          (TObject * Sender);// Вызывает форму: Stat_Result_examForm
    void __fastcall N37Click          (TObject * Sender);// Формирует: Статистики по уровню спортивной подготовки
    void __fastcall N39Click          (TObject * Sender);// Формирует: Информация о ходе приема (госконтроль)                           [INVISIBLE]
    void __fastcall N41Click          (TObject * Sender);// Формирует: Сводная ведомость Заочка Платники                                [INVISIBLE]
    void __fastcall N42Click          (TObject * Sender);// Формирует: СПИСОК - По направлениям
    void __fastcall N43Click          (TObject * Sender);// Формирует: Статистика  ->  Кол-во поданных заявлений по баллам
    void __fastcall N44Click          (TObject * Sender);// Формирует: Отчет Подано заявлений (итоговая) по направлениям
    void __fastcall N45Click          (TObject * Sender);// Формирует: 'Форма 1' Подали на Дневное
    void __fastcall N46Click          (TObject * Sender);// Формирует: 'Форма 2' Зачислены на Дневное
    void __fastcall N47Click          (TObject * Sender);// Формирует: 'Форма 1' Подали на Заочное
    void __fastcall N48Click          (TObject * Sender);// Формирует: 'Форма 2' Зачислены на Заочное
    void __fastcall N52Click          (TObject * Sender);// Вызывает форму: PassDlg
    void __fastcall N53Click          (TObject * Sender);// Вызывает форму: PassDlg
    void __fastcall N54Click          (TObject * Sender);// Вызывает форму: ExamenSpecForm "Формирование протокола с КУ по ФКиС"        [INVISIBLE]
    void __fastcall N55Click          (TObject * Sender);// Формирует: СТАТИСТИКА - Конкурс
    void __fastcall N58Click          (TObject * Sender);// Вызывает форму: LetterDualListDlg "Печать извещений и конвертов - бюджет, дневная"
    void __fastcall N59Click          (TObject * Sender);// Вызывает форму: LetterDualListDlg "Печать извещений и конвертов - бюджет, заочное"
    void __fastcall N62Click          (TObject * Sender);// Вызывает форму: LetterDualListDlg "Печать извещений и конвертов - платники, дневная"
    void __fastcall N63Click          (TObject * Sender);// Вызывает форму: LetterDualListDlg "Печать извещений и конвертов - платники, заочное"
    void __fastcall N64Click          (TObject * Sender);// Вызывает форму: AbiturLogDlg "Выбор даты для формирования Журнала регистрации документов"
    void __fastcall N68Click          (TObject * Sender);// Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Полный срок, Дневное, Бюджет"
    void __fastcall N69Click          (TObject * Sender);// Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Полный срок, Дневное, Платники"
    void __fastcall N70Click          (TObject * Sender);// Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Полный срок, Заочка,  Бюджет"
    void __fastcall N71Click          (TObject * Sender);// Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Полный срок, Заочка,  Платники"
    void __fastcall N75Click          (TObject * Sender);// Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Сокращенка,  Дневное, Бюджет"
    void __fastcall N76Click          (TObject * Sender);// Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Сокращенка,  Дневное, Платники"
    void __fastcall N77Click          (TObject * Sender);// Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Сокращенка,  Заочка,  Бюджет"
    void __fastcall N78Click          (TObject * Sender);// Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. Сокращенка,  Заочка,  Платники"
    void __fastcall N81Click          (TObject * Sender);// Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. 2-е высшее,  Дневное, Бюджет"
    void __fastcall N82Click          (TObject * Sender);// Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. 2-е высшее,  Заочка,  Бюджет"
    void __fastcall N83Click          (TObject * Sender);// Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. 2-е высшее,  Дневное, Платники"
    void __fastcall N84Click          (TObject * Sender);// Формирует: "ВЕДОМОСТЬ - Вступительных экзаменов. 2-е высшее,  Заочка,  Платники"
    void __fastcall N85Click          (TObject * Sender);// Вызывает форму: PersonalDocFrm "Печать 'титульных листов' личного дела"
    void __fastcall N86Click          (TObject * Sender);// Формирует: СПИСОК - Группы по полу
    void __fastcall N110Click         (TObject * Sender);// Формирует: 'Формы 1-К' для Министерства образования                         [INVISIBLE]
    void __fastcall N112Click         (TObject * Sender);// Формирует: ОТЧЕТ - Форма 1                                                  [INVISIBLE]
    void __fastcall N310Click         (TObject * Sender);// Формирует: 'Форма 3' Дневная форма обучения                                 [INVISIBLE]
    void __fastcall N311Click         (TObject * Sender);// Формирует: ПРОТОКОЛ - Испытаний (Девушки)
    void __fastcall SpeedButton1Click (TObject * Sender);// Кнопка: 'Смена факультета'
    void __fastcall SpeedButton2Click (TObject * Sender);// Кнопка: 'Обновить максимальный номер дела
    void __fastcall SpeedButton3Click (TObject * Sender);// Кнопка: 'Сертификаты по критериям'
    void __fastcall SpeedButton4Click (TObject * Sender);// Формирует: Отчет об итогах приемной компании
private:
public:
    __fastcall TMainForm (TComponent * Owner);


    void       __fastcall alignHVCells                       (
            int startColumn,
            int endColumn,
            int row,
            int alignHType,
            int alignVType
        );
    void       __fastcall AllCount_spec                      (                     // получение общего количества абитуриентов по специализации
            int indexNumber
        );
    void       __fastcall CellValue_Ball                     (                     // получение всех оценок по эkзаменам для одного абитуриента
            int col_pred,
            int nom_stroka
        );
    void       __fastcall Cicle_ball                         (                     // 'ПЛАН ПРИЕМА' статистика по сумме баллов
            int edu,
            int konk,
            int price
        );
    void       __fastcall Cicle_ball_konk                    (                     // 'ПЛАН ПРИЕМА' статистика по конкурсу
            int edu,
            int konk,
            int price
        );
    void       __fastcall Cicle_Report                       (int        edu     );// для отчета по приемной комиссии
    void       __fastcall Cicle_Report_special               (int        edu     );// -''- по специальностям
    void       __fastcall CicleSum                           (                     // Подсчет суммы по ячейкам (ИТОГО)
            int n_r,
            int nom_row,
            int st1,
            int st2,
            int index
        );
    bool       __fastcall Clear_mas                          (int        n_ab    );// Поиск номера абитуриента в массиве all и обнуление этой записи
    void       __fastcall Create_mas_all                     (                     // Создание массива всех абитуриентов на конкурс
            int n_spec,
            int vid_edu
        );
    void       __fastcall Create_Svod_ved                    (                     // формирует сводную ведомость для полного срока
            int edu,
            int price
        );
    void       __fastcall Create_Svod_ved_short              (                     // формирует сводную ведомость для поступающих на сокращённый срок
            int edu,
            int price
        );
    void       __fastcall Create_Svod_ved_2VO2K              (                     // формирует сводную ведомость для поступающих на 2 курс ВО
            int edu,
            int price
        );
    void       __fastcall Data_spisok                        (                     // передает данные в список абитуриентов
            int col_pred,
            int nom_stroka,
            int j
        );
    void       __fastcall Data_spisok_Pol                    (                     // передает данные в список абитуриентов (сортирует по полу)
            int nom_stroka,
            int j
        );
    int        __fastcall Find_nom_spec_str                  (                     // Поиск индекса записи в массиве mas_spec_str по номеру специальности
            int n_spec,
            int rec_count
        );
    void       __fastcall Forma_Giac                         (                     // формирует ГИАЦ
            int form,
            int vid_educ
        );
#ifndef  USE_NEW_HANDLERS
    AnsiString            generateSummaryListByPeriod        (
            const AnsiString & period,
                  int          edu,
                  int          price
        );
    AnsiString            generateSummaryListOfEnrollment (
            const AnsiString & course_number,
            const AnsiString & faculty_name,
                  int          fuculty_number
        );
#else
    AnsiString            getPartOfSheetNameForEducationType (
            const int          eduTypeCode
        );
    AnsiString            getPartOfSheetNameForStudyPeriod   (
            const int          studyPeriod
        );
    AnsiString            getPartOfSheetNameForPayment       (
            const int          payment
        );
    AnsiString            getReportName                      (
            const AnsiString & documentName
        );
    AnsiString            getReportName                      (
            const AnsiString & documentName,
                  bool         isFormatDateUsed
        );
    AnsiString            getReportName                      (
            const AnsiString & facultyName,
            const AnsiString & documentName
        );
    AnsiString            getReportName                      (
            const AnsiString & facultyName,
            const AnsiString & documentName,
            const AnsiString & currentHours
        );
    AnsiString            getReportNameWithCourseNumber      (
            const AnsiString & facultyName,
            const AnsiString & documentName,
            const AnsiString & courseNumber
        );
    AnsiString            getSummaryListNameByPeriod         (
            const AnsiString & period,
                  int          educatinType,
                  int          price
        );
#endif // ! USE_NEW_HANDLERS
    void       __fastcall Itog_podano                     (                     // функция суммирования итоговых значений по виду обучения или факультету для статистики  Подано заявлений (итоговая)
            int edu,
            int n_r,
            int itog
        );
#ifndef USE_NEW_HANDLERS
    void       __fastcall MergeCell                       (
            int col_nom1,
            int col_nom2,
            int row_nom1,
            int row_nom2,
            int align
        );
    void       __fastcall MergeCellCenter                 (
            int col_nom1,
            int col_nom2,
            int row_nom
        );
#else
    void       __fastcall MergeCell                          (
            int startColumn,
            int endColumn,
            int row
        );
    void       __fastcall MergeCell                          (
            int startColumn,
            int endColumn,
            int row,
            int alignHType                                                        // 3 - по центру
        );
    void       __fastcall MergeCell                          (
            int startColumn,
            int endColumn,
            int startRow,
            int endRow,
            int alignHType                                                        // 3 - по центру
        );
    void       __fastcall MergeCellCenter                    (
            int startColumn,
            int endColumn,
            int row
        );
    void                  printEnvelope                      (
                  PaymentCode         payment,
                  EducationTypeCode   educationType,
            const AnsiString        & message
        );
#endif // USE_NEW_HANDLERS
    void       __fastcall Priv_Str                           (int        par     );// возврат строки с привилегиями
    void       __fastcall Protokol4_J                        (int        pol     );// Протоколы
    AnsiString            ReturnField                        (AnsiString f       );// возвращает значение поля
    AnsiString            ReturnField_IT                     (AnsiString f       );// возвращает значение поля
    void       __fastcall Run_ProcBall                       (                     // процедура расчета суммы баллов
            int fac,
            int ed,
            int konk,
            int price,
            int kolon,
            int stroka_n
        );
    void       __fastcall Shapka_spisok                      (int        col_pred);// добавляет шапку в список абитуриентов
    void       __fastcall Shapka_spisok_Pol                  (                     // формирует шапку для списока абитуриентов
            AnsiString n_gr,
            String     pol
        );
    void       __fastcall Spisok_Pol                         (                     // вывода таблицы с сортировкой по полу
            String  pol,
            Variant Workbook
        );
    int        __fastcall Svod_ved                           (                     // формирует сводную ведомость
            int nom_str,
            int konk,
            int vid_edu,
            int rec_pred,
            int price,
            int pr_ved
        );
    void       __fastcall Zachisl_Sertificat                 (                     // Формирует: Отчет об итогах приемной компании
            int  f,
            int  v,
            int  s,
            bool all
        );

    TDateTime AbiturLogDate;                                                       // хранит дату создания журнала регистрации
};

extern PACKAGE TMainForm * MainForm;

#endif  // MAIN_UNIT_H

