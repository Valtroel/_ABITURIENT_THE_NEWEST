#pragma once
#ifndef FUNC_H
#define FUNC_H


void    __fastcall AutoFitColumn        (                                       // Auto fit column width
        Variant    Sheet,
        int        Col
    );
void    __fastcall BorderCell           (                                       // cell framing (bordering)
        int        col,
        int        row,
        int        typeline,
        int        weightline
    );
void    __fastcall CellFont             (                                       // set font options
        AnsiString NameFont,
        int        SizeFont,
        bool       BoldFont,
        bool       ItalicFont,
        int        UnderlineFont,
        int        ColorIndexFont,
        Variant    Range
    );
void     _fastcall CellFormula          (                                       // set formula into a cell
        AnsiString formula,
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall CellOrient           (                                       // cell Text Orientation
        int        col,
        int        row,
        int        grad
    );
void     _fastcall CellValue            (                                       // entering a value into a cell
        Variant    value,
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall ColumnWidth          (                                       // set column width
        Variant    Range,
        int        Width
    );
void    __fastcall ColWorkSheet         (                                       // set the number of sheets in a book
        Variant    excel_app,
        Variant    colSh
    );
void    __fastcall DeleteSheet          (Variant sheet     );
void     _fastcall DisplayAlert         (Variant ole_obj   );                   // remove Excel prompts for action confirmation
Variant  _fastcall GetCellValue         (
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall HeightRow            (                                       // set row height
        Variant    Range,
        int        height
    );
void    __fastcall HorizontalAlign      (                                       // horizontal content alignment
        Variant    Range,
        int        nom_align
    );
void    __fastcall mergeCell            (Variant Range     );                   // merging cells
void     _fastcall NameSheet1           (                                       // rename the sheet
        Variant    sheet,
        AnsiString name
    );
Variant __fastcall NewBook              (Variant excel_app );                   // add a new book
Variant  _fastcall NewSheet1            (Variant excel_book);                   // add a new sheet
Variant  _fastcall OpenBook             (                                       // open WorkBook
        Variant    excel_app,
        AnsiString full_name
    );
void     _fastcall OVisible             (Variant ole_obj   );                   // make the Ole object visible
void    __fastcall Quit_ex              (Variant excel_app );                   // delete Excel
Variant __fastcall Range_Range          (                                       // select a range of cells using start and end values
        Variant    Sheet,
        Variant    Cell1,
        Variant    Cell2
    );
Variant __fastcall Range2               (                                       // select a range of cells using range value
        Variant    Sheet,
        AnsiString Ran
    );
Variant  _fastcall SaveBook             (Variant excel_book);
Variant  _fastcall SaveBookAs           (
        Variant    excel_book,
        AnsiString name
    );
Variant  _fastcall SelectCell           (
        int        column,
        int        row,
        Variant    sheet  = 0
    );
Variant __fastcall SelectColumn         (
        Variant    sheet,
        int        column
    );
Variant  _fastcall SelectSheet          (
        Variant    excel_book,
        AnsiString name
    );
void    __fastcall SetOrientatSheet     (                                       // sheet orientation
        Variant    sheet,
        int        grad                                                         // 1 - portrait, 2 - landscape
    );
void    __fastcall SheetFormat          (                                       // cell format
        Variant    cell,
        AnsiString Format
    );
void    __fastcall VerticalAlign        (
        Variant    Range,
        int        nom_align
    );
void    __fastcall wrapWord             (Variant Range     );                   // wrap word

#endif  // FUNC_H
