#pragma once
#ifndef FUNC1_H
#define FUNC1_H


extern const AnsiString mas_column[];                                           // = {"A", ..., "AZ"};
extern       Variant    CurCell,                                                // текуща€ €чейка
                        CurSheet;                                               // текуща€ таблица


void    __fastcall AutoFillCell    (Variant Range     );                        // јвтозаполнение
void    __fastcall AutoFitColumn   (                                            // јвтоподбор ширины столбца
        Variant    Sheet,
        int        Col
    );
void    __fastcall AutoFitRow      (                                            // јвтоподбор ширины строки
        Variant    Sheet,
        int        Row
    );
void    __fastcall BorderCell      (                                            // обрамление €чейки
        int        col,
        int        row,
        int        typeline,
        int        weightline
    );
void    __fastcall Borders         (
        Variant    Range,
        int        LineStyle,
        int        weightline
    );
void    __fastcall CellFont        (                                            // установить параметры шрифта
        AnsiString NameFont,
        int        SizeFont,
        bool       BoldFont,
        bool       ItalicFont,
        int        UnderlineFont,
        Variant    Range
    );
void     _fastcall CellFormula     (                                            // ввод формулы в €чейку
        AnsiString formula,
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall CellOrient      (                                            // ќриентаци€ текста в €чейке
        int        col,
        int        row,
        int        grad
    );
void     _fastcall CellValue       (                                            // ввод значени€ в €чейку
        Variant    value,
        int        column = 0,
        int        row = 0,
        Variant    sheet = 0
    );
void    __fastcall CopySheet       (Variant sheet     );                        //  опирование листа
void    __fastcall DeleteSheet     (Variant sheet     );                        // ”даление листа
void     _fastcall DisplayAlert    (Variant ole_obj   );                        // убрать запросы Excela на подтверждени€ действи€
Variant  _fastcall GetCellValue    (                                            // получение  значени€ из €чейки
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall HeightRow       (                                            // установка ширины строки
        Variant    Range,
        int        height
    );
void    __fastcall HorizontalAlign (                                            // ¬ыравнивание содержимого €чейки по горизонтали
        Variant    Range,
        int        nom_align
    );
void    __fastcall M1              (Variant Range     );                        // ќбъединение €чеек
void     _fastcall NameSheet1      (                                            // переименование листа
        Variant    sheet,
        AnsiString name
    );
Variant __fastcall NewBook         (Variant excel_app );                        // Ќова€ книга
Variant  _fastcall NewSheet1       (Variant excel_app );                        // ƒобавление нового листа
Variant  _fastcall OpenBook        (                                            // Open WorkBook
        Variant    excel_app,
        AnsiString full_name
    );
void     _fastcall OVisible        (Variant ole_obj   );                        // set Visible to Ole object
void    __fastcall Quit_ex         (Variant excel_app );                        // delete Excel
Variant __fastcall Range           (                                            // ¬ыделение €чеек
        Variant    excel_book,
        Variant    Cell1,
        Variant    Cell2
    );
Variant  _fastcall SaveBook        (Variant excel_book);                        // —охранение книги
Variant  _fastcall SaveBookAs      (                                            // —охранение книги c новым именем
        Variant    excel_book,
        AnsiString name
    );
Variant  _fastcall SelectCell      (                                            // ¬ыбор €чейки по адресу
        int        column,
        int        row,
        Variant    sheet  = 0
    );
Variant __fastcall SelectColumn    (                                            // выбрать столбец
        Variant    sheet,
        int        column
    );
Variant __fastcall SelectRow       (                                            // выбрать строку
        Variant    sheet,
        int        row
    );
Variant  _fastcall SelectSheet     (                                            // Select WorkSheet by Name
        Variant    excel_book,
        AnsiString name
    );
void    __fastcall SheetFormat     (                                            // ‘ормат €чейки
        Variant    cell,
        AnsiString Format
    );
void    __fastcall VerticalAlign   (                                            // ¬ыравнивание содержимого €чейки по вертикали
        Variant    Range,
        int        nom_align
    );
void    __fastcall W1              (Variant Range     );                        // ѕернос по словам

#endif  // FUNC_H