#include <vcl.h>
#pragma hdrstop


#include "func.h"


#pragma package (smart_init)


Variant
    CurCell,
    CurSheet;

const AnsiString
    mas_column [] =
    {
        "A",  "B",  "C",  "D",  "E",  "F",  "G",  "H",  "I",
        "J",  "K",  "L",  "M",  "N",  "O",  "P",  "Q",  "R",
        "S",  "T",  "U",  "V",  "W",  "X",  "Y",  "Z",

        "AA", "AB", "AC", "AD", "AE", "AF", "AG", "AH", "AI",
        "AJ", "AK", "AL", "AM", "AN", "AO", "AP", "AQ", "AR",
        "AS", "AT", "AU", "AV", "AW", "AX", "AY", "AZ"
    };



void __fastcall AutoFillCell (Variant Range)                                    // Автозаполнение
{
    /*
    Function FCellAutoFill ("AutoFill");

    FCellAutoFill << Range << 1;

    Range.Exec (FCellAutoFill);
    */
}
void __fastcall AutoFitColumn (                                                 // Автоподбор ширины столбца
        Variant Sheet,
        int     Col
    )
{
    Variant Column =
        SelectColumn (
            Sheet,
            Col
        );

    Function FColumnAutoFit ("AutoFit");

    Column.Exec (FColumnAutoFit);
}
void __fastcall AutoFitRow (                                                    // Автоподбор ширины строки
        Variant Sheet,
        int     Row
    )
{
    Variant Row2 =
        SelectRow (
            Sheet,
            Row
        );

    Function FRowAutoFit ("AutoFit");

    Row2.Exec (FRowAutoFit);
}
void __fastcall BorderCell (                                                    // cell framing
        int col,
        int row,
        int typeline,
        int weightline
    )
{
    Variant Cell =
        SelectCell (
            col,
            row
        );

    Function FBorderCell ("BorderAround");

    // TYPE LINE CODES:
    //     1 - regular line,
    //     2 - small dotted line,
    //     3 - large dotted line,
    //     4 - one long one short,
    //     5 - one long two short,
    //     9 - double line,
    // WEIGHT LINE:
    //     up to 4   line thickness

    FBorderCell << typeline << weightline;

    Cell.Exec (FBorderCell);
}
void __fastcall Borders (
        Variant Range,
        int     typeline,
        int     weightline
    )
{
    Function FBorders ("BorderAround");

    FBorders << typeline << weightline;

    Range.Exec (FBorders);
}
void __fastcall CellFont (                                                      // установить параметры шрифта
        AnsiString NameFont,
        int        SizeFont,
        bool       BoldFont,
        bool       ItalicFont,
        int        UnderlineFont,
        Variant    Range
    )
{
    PropertyGet PGFont ("Font");
    Variant GF = Range.Exec (PGFont);

    PropertySet PSName ("Name");
    PSName << NameFont;
    GF.Exec (PSName);

    PropertySet PSSize ("Size");
    PSSize << SizeFont;
    GF.Exec (PSSize);

    PropertySet PSBold ("Bold");
    PSBold << BoldFont;
    GF.Exec (PSBold);

    PropertySet PSItalic ("Italic");
    PSItalic << ItalicFont;
    GF.Exec (PSItalic);

    // TYPE UNDERLINE CODES:
    //     1 - non,
    //     2 - single line by value,
    //     3 - double line by value,
    //     4 - single line by cell,
    //     5 - double line by cell

    PropertySet PSUnderline ("Underline");
    PSUnderline << UnderlineFont;
    GF.Exec (PSUnderline);
}
void _fastcall  CellFormula (
        AnsiString formula,
        int     column,
        int     row,
        Variant sheet
    )
{
    Variant local_cell =
        SelectCell (
            column,
            row,
            sheet
        );

    PropertySet PSCellsFormula ("FormulaLocal");

    PSCellsFormula << formula;

    local_cell.Exec (
        PSCellsFormula
    );
}
void __fastcall CellOrient (                                                    // Orientation of text in a cell
        int col,
        int row,
        int grad
    )
{
    Variant Cell =
        SelectCell (
            col,
            row
        );

    PropertySet PSOrient ("Orientation");

    PSOrient << grad;

    Cell.Exec (PSOrient);
}
void _fastcall  CellValue (
        Variant value,
        int     column,
        int     row,
        Variant sheet
    )
{
    Variant local_cell =
        SelectCell (
            column,
            row,
            sheet
        );

    PropertySet PSCellsValue ("Value");

    PSCellsValue << value;

    local_cell.Exec (
        PSCellsValue
    );
}
void __fastcall CopySheet (Variant sheet)                                       // sheet copy
{
    Function FCopySheet ("Copy");

    FCopySheet << sheet;

    sheet.Exec (FCopySheet);
}
void __fastcall DeleteSheet (Variant sheet)                                     // Удаление листа
{
    Function FDeleteSheet ("Delete");

    sheet.Exec (FDeleteSheet);
}
void _fastcall DisplayAlert (Variant ole_obj)
{
    PropertySet PSAlert ("DisplayAlerts");

    PSAlert << FALSE;

    ole_obj.Exec (PSAlert);
}
Variant _fastcall  GetCellValue (
        int     column,
        int     row,
        Variant sheet
    )
{
    Variant local_cell =
        SelectCell (
            column,
            row,
            sheet
        );

    PropertyGet PGCellsValue ("Value");

    return
        local_cell.Exec (
            PGCellsValue
        );
}
void __fastcall HeightRow (                                                     // setting line width
        Variant Range,
        int     height
    )
{
    PropertySet PSHeightRow ("RowHeight");

    PSHeightRow << height;

    Range.Exec (PSHeightRow);
}
void __fastcall HorizontalAlign (                                               // Выравнивание содержимого ячейки по горизонтали
        Variant Range,
        int     nom_align
    )
{
    PropertySet PSCenterAlign ("HorizontalAlignment");

    // HORIZONTAL ALIGNMENT TYPE CODES:
    //     1 - by value,
    //     2 - left side,
    //     3 - center,
    //     4 - right side,
    //     5 - padding,
    //     6 - by width

    PSCenterAlign << nom_align;

    Range.Exec (
        PSCenterAlign
    );
}
void __fastcall mergeCell (Variant Range)                                       // Объединение ячеек
{
    Function PGMerge ("Merge");

    Range.Exec (
        PGMerge
    );
}
void _fastcall NameSheet1 (
        Variant    sheet,
        AnsiString name
    )
{
    PropertySet PSWorksheetsName ("Name");

    PSWorksheetsName << name;

    sheet.Exec (
        PSWorksheetsName
    );
}
Variant __fastcall NewBook (Variant excel_app)                                  // Новая книга
{
    PropertyGet PGExcelWorkbooks ("Workbooks");

    Variant Workbooks =
        excel_app.Exec (
            PGExcelWorkbooks
        );

    Function FWorkbooksAdd ("Add");

    return
        Workbooks.Exec (FWorkbooksAdd);
}
Variant _fastcall NewSheet1 (Variant excel_book)
{
    PropertyGet PGExcelWorksheets ("Worksheets");

    Variant Worksheets =
        excel_book.Exec (
            PGExcelWorksheets
        );

    Function FWorksheetsNew ("Add");

    return
        Worksheets.Exec (
            FWorksheetsNew
        );
}
Variant _fastcall OpenBook (
        Variant    excel_app,
        AnsiString full_name
    )
{
    PropertyGet PGExcelWorkbooks ("Workbooks");

    Variant Workbooks =
        excel_app.Exec (
            PGExcelWorkbooks
        );

    Function FWorkbooksOpen ("Open");

    FWorkbooksOpen << full_name;

    return
        Workbooks.Exec (
            FWorkbooksOpen
        );
}
void _fastcall OVisible (Variant ole_obj)
{
    PropertySet PSVisible ("Visible");

    PSVisible << TRUE;

    ole_obj.Exec (PSVisible);
}
void __fastcall Quit_ex (Variant excel_app)                                     // delete Excel
{
    /*
    PropertyGet PGExcelWorkbooks ("Workbooks");

    Variant Workbooks = excel_app.Exec (PGExcelWorkbooks);

    Function FWorkbooksQuit ("Quit");

    excel_app.Exec (FWorkbooksQuit);
    */
}
Variant __fastcall Range (                                                      // Выделение ячеек
        Variant Sheet,
        Variant Cell1,
        Variant Cell2
    )
{
    PropertyGet PGCellRange ("Range");

    PGCellRange << Cell1 << Cell2;

    return
        Sheet.Exec (
            PGCellRange
        );
}
Variant _fastcall SaveBook (Variant excel_book)
{
    Function FWorkbooksSave ("Save");

    return
        excel_book.Exec (
            FWorkbooksSave
        );
}
Variant _fastcall SaveBookAs (
        Variant    excel_book,
        AnsiString name
    )
{
    Function FWorkbooksSaveAs ("SaveAs");

    FWorkbooksSaveAs << name;

    return
        excel_book.Exec (
            FWorkbooksSaveAs
        );
}
Variant _fastcall SelectCell (
        int     column,
        int     row,
        Variant sheet
    )
{
    if (! sheet)
        sheet = CurSheet;

    PropertyGet PGSheetCells ("Cells");

    Variant Cells =
        sheet.Exec (
            PGSheetCells
        );

    PropertyGet PGCellsCells ("Cells");

    if (    row    > 0
         && column > 0
       )
    {
        PGCellsCells << row << column;

        CurCell =
            Cells.Exec (
                PGCellsCells
            );
    }

    return
        CurCell;
}
Variant __fastcall SelectColumn (                                               // выбрать столбец
        Variant sheet,
        int     column
     )
{
    PropertyGet PGColumn ("Columns");

    PGColumn << column;

    return
        sheet.Exec (
            PGColumn
        );
}
Variant __fastcall SelectRow (                                                  // выбрать строку
        Variant sheet,
        int     row
    )
{
    PropertyGet PGRow ("Rows");

    PGRow << row;

    return
        sheet.Exec (
            PGRow
        );
}
Variant _fastcall SelectSheet (
        Variant    excel_book,
        AnsiString name
    )
{
    PropertyGet PGWorkbookSheets ("Worksheets");

    PGWorkbookSheets << name;

    CurSheet =
        excel_book.Exec (
            PGWorkbookSheets
        );

    CurCell  =
        SelectCell (
            1,
            1
        );

    return
        CurSheet;
}
void __fastcall SheetFormat (                                                   // cell format
        Variant    cell,
        AnsiString Format
    )
{
    PropertySet PSFormatCell ("NumberFormat");

    PSFormatCell << Format;

    cell.Exec (PSFormatCell);
}
void __fastcall VerticalAlign (                                                 // Выравнивание содержимого ячейки по вертикали
        Variant Range,
        int     nom_align
    )
{
    PropertySet PSVertAlign ("VerticalAlignment");

    // ALIGNMENT TYPE CODES:
    //     1 - top,
    //     2 - center,
    //     3 - bottom,
    //     4 - height

    PSVertAlign << nom_align;

    Range.Exec (PSVertAlign);
}
void __fastcall wrapWord (
        Variant Range
    )
{
    PropertySet PGWrap ("WrapText");

    PGWrap << true;

    Range.Exec (PGWrap);
}
