#include <vcl.h>
#pragma hdrstop


#include "func.h"


#pragma package (smart_init)



const AnsiString
    mas_column[] =
    {
        "A" , "B" , "C" , "D" , "E" ,
        "F" , "G" , "H" , "I" , "J" ,
        "K" , "L" , "M" , "N" , "O" ,
        "P" , "Q" , "R" , "S" , "T" ,
        "U" , "V" , "W" , "X" , "Y" ,
        "Z" ,
        "AA", "AB", "AC", "AD", "AE",
        "AF", "AG", "AH", "AI", "AJ",
        "AK", "AL", "AM", "AN", "AO",
        "AP", "AQ", "AR", "AS", "AT",
        "AU", "AV", "AW", "AX", "AY",
        "AZ",
        "BA", "BB", "BC", "BD", "BE",
        "BF", "BG", "BH", "BI", "BJ",
        "BK", "BL", "BM", "BN", "BO",
        "BP", "BQ", "BR", "BS", "BT",
        "BU", "BV", "BW", "BX", "BY",
        "BZ",
        "CA", "CB", "CC", "CD", "CE",
        "CF", "CG", "CH", "CI", "CJ",
        "CK", "CL", "CM", "CN", "CO",
        "CP", "CQ", "CR", "CS", "CT",
        "CU", "CV", "CW", "CX", "CY",
        "CZ"
    };


Variant
    currentCell,
    currentSheet;



void    __fastcall AutoFitColumn        (                                       // Auto fit column width
        Variant    Sheet,
        int        Col
    )
{
    Variant Column =
        SelectColumn (
            Sheet,
            Col
        );
    Function
        FColumnAutoFit (
            "AutoFit"
        );
    Column.Exec (
        FColumnAutoFit
    );
}
void    __fastcall BorderCell           (                                       // cell framing (bordering)
        int        col,
        int        row,
        int        typeline,                                                    // 1 - regular, 2 - dotted, 3 - large dotted, 4 - a long & a short, 5 - a long & two short, 9 - double line
        int        weightline                                                   // up to 4 line thickness
    )
{
    Variant Cell =
        SelectCell (
            col,
            row
        );

    // TYPE LINE CODES:
    //     1 - regular line,
    //     2 - small dotted line,
    //     3 - large dotted line,
    //     4 - one long one short,
    //     5 - one long two short,
    //     9 - double line,
    // WEIGHT LINE:
    //     up to 4   line thickness
    Function
        FBorderCell (
            "BorderAround"
        );
    FBorderCell << typeline << weightline;
    Cell.Exec (
        FBorderCell
    );
}
void    __fastcall CellFont             (                                       // set font options
        AnsiString NameFont,
        int        SizeFont,
        bool       BoldFont,
        bool       ItalicFont,
        int        UnderlineFont,                                               // 1 - none, 2 - single value, 3 - double in value, 4 - single per cell, 5 - double by cell
        int        ColorIndexFont,
        Variant    Range
    )
{
    PropertyGet
        PGFont (
            "Font"
        );
    Variant GF =
        Range.Exec (
            PGFont
        );


    PropertySet
        PSName (
            "Name"
        );
    PSName << NameFont;
    GF.Exec (
        PSName
    );


    PropertySet
        PSSize (
            "Size"
        );
    PSSize << SizeFont;
    GF.Exec (
        PSSize
    );


    PropertySet
        PSBold (
            "Bold"
        );
    PSBold << BoldFont;
    GF.Exec (
        PSBold
    );


    PropertySet
        PSItalic (
            "Italic"
        );
    PSItalic << ItalicFont;
    GF.Exec (
        PSItalic
    );


    // TYPE UNDERLINE CODES:
    //     1 - non,
    //     2 - single line by value,
    //     3 - double line by value,
    //     4 - single line by cell,
    //     5 - double line by cell
    PropertySet
        PSUnderline (
            "Underline"
        );
    PSUnderline << UnderlineFont;
    GF.Exec (
        PSUnderline
    );


    PropertySet
        PSColorIndex (
            "ColorIndex"
        );
    PSColorIndex << ColorIndexFont;
    GF.Exec (
        PSColorIndex
    );
}
void     _fastcall CellFormula          (                                       // set formula into a cell
        AnsiString formula,
        int        column,
        int        row,
        Variant    sheet
    )
{
    Variant local_cell =
        SelectCell (
            column,
            row,
            sheet
        );
    PropertySet
        PSCellsFormula (
            "FormulaLocal"
        );
    PSCellsFormula << formula;
    local_cell.Exec (
        PSCellsFormula
    );
}
void    __fastcall CellOrient           (                                       // cell Text Orientation
        int        col,
        int        row,
        int        grad
    )
{
    Variant Cell =
        SelectCell (
            col,
            row
        );
    PropertySet
        PSOrient (
            "Orientation"
        );
    PSOrient << grad;
    Cell.Exec (
        PSOrient
    );
}
void     _fastcall CellValue            (                                       // entering a value into a cell
        Variant    value,
        int        column,
        int        row,
        Variant    sheet
    )
{
    Variant local_cell =
        SelectCell (
            column,
            row,
            sheet
        );
    PropertySet
        PSCellsValue (
            "Value"
        );
    PSCellsValue << value;
    local_cell.Exec (
        PSCellsValue
    );
}
void    __fastcall ColumnWidth          (                                       // set column width
        Variant    Range,
        int        Width
    )
{
    PropertySet
        PSColumnWidth (
            "ColumnWidth"
        );
    PSColumnWidth << Width;
    Range.Exec (
        PSColumnWidth
    );
}
void    __fastcall ColWorkSheet         (                                       // set the number of sheets in a book
        Variant    excel_app,
        Variant    colSh
    )
{
    PropertySet
        PSColSheet (
            "SheetsInNewWorkbook"
        );
    PSColSheet << colSh;
    excel_app.Exec (
        PSColSheet
    );
}
void    __fastcall DeleteSheet          (Variant sheet     )
{
    Function
        FDeleteSheet (
            "Delete"
        );
    sheet.Exec (
        FDeleteSheet
    );
}
void     _fastcall DisplayAlert         (Variant ole_obj   )                    // remove Excel prompts for action confirmation
{
    PropertySet
        PSAlert (
            "DisplayAlerts"
        );
    PSAlert << FALSE;
    ole_obj.Exec (
        PSAlert
    );
}
Variant  _fastcall GetCellValue         (
        int        column,
        int        row,
        Variant    sheet
    )
{
    Variant local_cell =
        SelectCell (
            column,
            row,
            sheet
        );
    PropertyGet
        PGCellsValue (
            "Value"
        );

    return
        local_cell.Exec (
            PGCellsValue
        );
}
void    __fastcall HeightRow            (                                       // set row height
        Variant    Range,
        int        height
    )
{
    PropertySet
        PSHeightRow (
            "RowHeight"
        );
    PSHeightRow << height;
    Range.Exec (
        PSHeightRow
    );
}
void    __fastcall HorizontalAlign      (                                       // horizontal content alignment
        Variant    Range,
        int        nom_align                                                    // 1 - by value, 2 - left, 3 - center, 4 - right, 5 - with filling, 6 - in width
    )
{
    PropertySet
        PSCenterAlign (
            "HorizontalAlignment"
        );
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
void    __fastcall mergeCell            (Variant Range     )                    // merging cells
{
    Function
        PGMerge (
            "Merge"
        );
    Range.Exec (
        PGMerge
    );
}
void     _fastcall NameSheet1           (                                       // rename the sheet
        Variant    sheet,
        AnsiString name
    )
{
    PropertySet
        PSWorksheetsName (
            "Name"
        );
    PSWorksheetsName << name;
    sheet.Exec (
        PSWorksheetsName
    );
}
Variant __fastcall NewBook              (Variant excel_app )                    // add a new book
{
    PropertyGet
        PGExcelWorkbooks (
            "Workbooks"
        );
    Variant Workbooks =
        excel_app.Exec (
            PGExcelWorkbooks
        );
    Function
        FWorkbooksAdd (
            "Add"
        );

    return
        Workbooks.Exec (
            FWorkbooksAdd
        );
}
Variant  _fastcall NewSheet1            (Variant excel_book)                    // add a new sheet
{
    PropertyGet
        PGExcelWorksheets (
            "Worksheets"
        );
    Variant Worksheets =
        excel_book.Exec (
            PGExcelWorksheets
        );
    Function
        FWorksheetsNew (
            "Add"
        );

    return
        Worksheets.Exec (
            FWorksheetsNew
        );
}
Variant  _fastcall OpenBook             (                                       // open WorkBook
        Variant    excel_app,
        AnsiString full_name
    )
{
    PropertyGet
        PGExcelWorkbooks (
            "Workbooks"
        );
    Variant Workbooks =
        excel_app.Exec (
            PGExcelWorkbooks
        );
    Function
        FWorkbooksOpen (
            "Open"
        );
    FWorkbooksOpen << full_name;

    return
        Workbooks.Exec (
            FWorkbooksOpen
        );
}
void     _fastcall OVisible             (Variant ole_obj   )                    // make the Ole object visible
{
    PropertySet
        PSVisible (
            "Visible"
        );
    PSVisible << TRUE;
    ole_obj.Exec (
        PSVisible
    );
}
void    __fastcall Quit_ex              (Variant excel_app )                    // delete Excel
{                                               
    PropertyGet
        PGExcelWorkbooks (
            "Workbooks"
        );
    Variant Workbooks =
        excel_app.Exec (
            PGExcelWorkbooks
        );
    Function
        FWorkbooksQuit (
            "Quit"
        );
    excel_app.Exec (
        FWorkbooksQuit
    );
    // excel_app.OleFunction ("Quit");
}
Variant __fastcall Range_Range          (                                       // select a range of cells using start and end values
        Variant    Sheet,
        Variant    Cell1,
        Variant    Cell2
    )
{
    PropertyGet
        PGCellRange (
            "Range"
        );
    PGCellRange << Cell1 << Cell2;

    return
        Sheet.Exec (
            PGCellRange
        );
}
Variant __fastcall Range2               (                                       // select a range of cells using range value
        Variant    Sheet,
        AnsiString Ran
    )
{
    PropertyGet
        PGCellRange (
            "Range"
        );
    PGCellRange << Ran;

    return
        Sheet.Exec (
            PGCellRange
        );
}
Variant  _fastcall SaveBook             (Variant excel_book)
{
    Function
        FWorkbooksSave (
            "Save"
        );

    return
        excel_book.Exec (
            FWorkbooksSave
        );
}
Variant  _fastcall SaveBookAs           (
        Variant    excel_book,
        AnsiString name
    )
{
    Function
        FWorkbooksSaveAs (
            "SaveAs"
        );
    FWorkbooksSaveAs << name;

    return
        excel_book.Exec (
            FWorkbooksSaveAs
        );
}
Variant  _fastcall SelectCell           (
        int        column,
        int        row,
        Variant    sheet
    )
{
    if (! sheet)
        sheet = currentSheet;

    PropertyGet
        PGSheetCells (
            "Cells"
        );
    Variant Cells =
        sheet.Exec (
            PGSheetCells
        );
    PropertyGet
        PGCellsCells (
            "Cells"
        );

    if (    row    > 0
         && column > 0
       )
    {
        PGCellsCells << row << column;

        currentCell =
            Cells.Exec (
                PGCellsCells
            );
    }

    return
        currentCell;
}
Variant __fastcall SelectColumn         (
        Variant    sheet,
        int        column
    )
{
    PropertyGet
        PGColumn (
            "Columns"
        );
    PGColumn << column;

    return
        sheet.Exec (
            PGColumn
        );
}
Variant  _fastcall SelectSheet          (
        Variant    excel_book,
        AnsiString name
    )
{
    PropertyGet
        PGWorkbookSheets (
            "Worksheets"
        );
    PGWorkbookSheets << name;
    currentSheet =
        excel_book.Exec (
            PGWorkbookSheets
        );
    currentCell =
        SelectCell (
            1,
            1
        );

    return
        currentSheet;
}
void    __fastcall SetOrientatSheet     (                                       // sheet orientation
        Variant    sheet,
        int        grad                                                         // 1 - portrait, 2 - landscape
    )
{
    PropertyGet
        PGPageSetup (
            "PageSetup"
        );
    Variant PS =
        sheet.Exec (
            PGPageSetup
        );
    PropertySet
        PSName (
            "Orientation"
        );
    PSName << grad;
    PS.Exec (
        PSName
    );
}
void    __fastcall SheetFormat          (                                       // cell format
        Variant    cell,
        AnsiString Format
    )
{
    PropertySet
        PSFormatCell (
            "NumberFormat"
        );
    PSFormatCell << Format;
    cell.Exec (
        PSFormatCell
    );
}
void    __fastcall VerticalAlign        (
        Variant    Range,
        int        nom_align                                                    // 1 - top, 2 - center, 3 - bottom, 4 - height
    )
{
    PropertySet
        PSVertAlign (
            "VerticalAlignment"
        );
    // ALIGNMENT TYPE CODES:
    //     1 - top,
    //     2 - center,
    //     3 - bottom,
    //     4 - height
    PSVertAlign << nom_align;
    Range.Exec (
        PSVertAlign
    );
}
void    __fastcall wrapWord             (Variant Range     )                    // wrap word
{
    PropertySet
        PGWrap (
            "WrapText"
        );
    PGWrap << true;
    Range.Exec (
        PGWrap
    );
}
