//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Func1.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
Variant CurSheet,CurCell;
const AnsiString mas_column[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","AA","AB","AC","AD","AE","AF","AG","AH","AI","AJ","AK","AL","AM","AN","AO","AP","AQ","AR","AS","AT","AU","AV","AW","AX","AY","AZ"};

void _fastcall OVisible(Variant ole_obj)
{
  PropertySet PSVisible("Visible");
  PSVisible << TRUE;
  ole_obj.Exec(PSVisible);
}

void _fastcall DisplayAlert(Variant ole_obj)
{
  PropertySet PSAlert("DisplayAlerts");
  PSAlert << FALSE;
  ole_obj.Exec(PSAlert);
}

//delete Excel
void __fastcall Quit_ex(Variant excel_app)
{                                               
 /*PropertyGet PGExcelWorkbooks("Workbooks");
  Variant Workbooks=excel_app.Exec(PGExcelWorkbooks);
  Function FWorkbooksQuit("Quit");
  excel_app.Exec(FWorkbooksQuit);  */
}

Variant _fastcall OpenBook(Variant excel_app, AnsiString full_name)
{
  PropertyGet PGExcelWorkbooks("Workbooks");
  Variant Workbooks=excel_app.Exec(PGExcelWorkbooks);
  Function FWorkbooksOpen("Open");
  FWorkbooksOpen << full_name;
  return Workbooks.Exec(FWorkbooksOpen);
}

//Ќова€ книга
Variant __fastcall NewBook(Variant excel_app)
{
 PropertyGet PGExcelWorkbooks("Workbooks");
  Variant Workbooks=excel_app.Exec(PGExcelWorkbooks);
  Function FWorkbooksAdd("Add");
  return Workbooks.Exec(FWorkbooksAdd);
}

Variant _fastcall SelectSheet(Variant excel_book, AnsiString name)
{
  PropertyGet PGWorkbookSheets("Worksheets");
  PGWorkbookSheets << name;
  CurSheet=excel_book.Exec(PGWorkbookSheets);
  CurCell=SelectCell(1,1);
  return CurSheet;
}

//выбрать столбец
Variant __fastcall SelectColumn(Variant sheet, int column)
{
 PropertyGet PGColumn("Columns");
 PGColumn << column;
 return sheet.Exec(PGColumn);
}

//выбрать строку
Variant __fastcall SelectRow(Variant sheet, int row)
{
 PropertyGet PGRow("Rows");
 PGRow << row;
 return sheet.Exec(PGRow);
}


Variant _fastcall SelectCell(int column, int row, Variant sheet)
{
  if (!sheet)sheet=CurSheet;
  PropertyGet PGSheetCells("Cells");
  Variant Cells=sheet.Exec(PGSheetCells);
  PropertyGet PGCellsCells("Cells");
  if ((row>0)&&(column>0))
    {PGCellsCells << row << column;
     CurCell=Cells.Exec(PGCellsCells);}
  return CurCell;
}

void _fastcall  CellValue(Variant value, int column, int row, Variant sheet)
{
  Variant local_cell=SelectCell(column, row, sheet);
  PropertySet PSCellsValue("Value");
  PSCellsValue << value;
  local_cell.Exec(PSCellsValue);
}

Variant _fastcall  GetCellValue(int column, int row, Variant sheet)
{
  Variant local_cell=SelectCell(column, row, sheet);
  PropertyGet PGCellsValue("Value");
  return local_cell.Exec(PGCellsValue);
}

void _fastcall  CellFormula(AnsiString formula,  int column, int row, Variant sheet)
{
  Variant local_cell=SelectCell(column, row, sheet);
  PropertySet PSCellsFormula("FormulaLocal");
  PSCellsFormula << formula;
  local_cell.Exec(PSCellsFormula);
}

Variant _fastcall SaveBookAs(Variant excel_book, AnsiString name)
{
 Function FWorkbooksSaveAs("SaveAs");
  FWorkbooksSaveAs << name;
  return excel_book.Exec(FWorkbooksSaveAs);
}

Variant _fastcall SaveBook(Variant excel_book)
{
  Function FWorkbooksSave("Save");
  return excel_book.Exec(FWorkbooksSave);
}

Variant _fastcall NewSheet1(Variant excel_book)
{
  PropertyGet PGExcelWorksheets("Worksheets");
  Variant Worksheets=excel_book.Exec(PGExcelWorksheets);
  Function FWorksheetsNew("Add");
  return Worksheets.Exec(FWorksheetsNew);
}

void _fastcall NameSheet1(Variant sheet, AnsiString name)
{
  PropertySet PSWorksheetsName("Name");
  PSWorksheetsName << name;
  sheet.Exec(PSWorksheetsName);
}

//¬ыделение €чеек
Variant __fastcall Range(Variant Sheet, Variant Cell1, Variant Cell2)
{
 PropertyGet PGCellRange("Range");
 PGCellRange << Cell1 << Cell2;
 return Sheet.Exec(PGCellRange);
}

//ќбъединение €чеек
void __fastcall M1(Variant Range)
{
 Function PGMerge("Merge");
 Range.Exec(PGMerge);
}

//¬ыравнивание содержимого €чейки по горизонтали
// 1-по значению, 2-по левому краю, 3-по центру, 4-по правому краю, 5-с заполнением, 6-по ширине
void __fastcall HorizontalAlign(Variant Range, int nom_align)
{
 PropertySet PSCenterAlign("HorizontalAlignment");
 PSCenterAlign << nom_align;
 Range.Exec(PSCenterAlign);
}

//¬ыравнивание содержимого €чейки по вертикали
// 1-по верхнему краю, 2-по центру, 3-по нижнему краю, 4-по высоте
void __fastcall VerticalAlign(Variant Range, int nom_align)
{
 PropertySet PSVertAlign("VerticalAlignment");
 PSVertAlign << nom_align;
 Range.Exec(PSVertAlign);
}

//установить параметры шрифта
//Underline: 1-нет, 2-одинарное по значению, 3-двойное по значению, 4-одинарное по €чейке, 5-двойное по €чейке
void __fastcall CellFont(AnsiString NameFont, int SizeFont, bool BoldFont, bool ItalicFont, int UnderlineFont, Variant Range)
{
 PropertyGet PGFont("Font");
 Variant GF=Range.Exec(PGFont);

 PropertySet PSName("Name");
 PSName << NameFont;
 GF.Exec(PSName);

 PropertySet PSSize("Size");
 PSSize << SizeFont;
 GF.Exec(PSSize);

 PropertySet PSBold("Bold");
 PSBold << BoldFont;
 GF.Exec(PSBold);

 PropertySet PSItalic("Italic");
 PSItalic << ItalicFont;
 GF.Exec(PSItalic);

 PropertySet PSUnderline("Underline");
 PSUnderline << UnderlineFont;
 GF.Exec(PSUnderline);
}

//јвтоподбор ширины столбца
void __fastcall AutoFitColumn(Variant Sheet, int Col)
{
Variant Column=SelectColumn(Sheet, Col);
 Function FColumnAutoFit("AutoFit");
 Column.Exec(FColumnAutoFit);
}

//јвтоподбор ширины строки
void __fastcall AutoFitRow(Variant Sheet, int Row)
{
Variant Row2=SelectRow(Sheet, Row);
 Function FRowAutoFit("AutoFit");
 Row2.Exec(FRowAutoFit);/**/
}

//јвтозаполнение
void __fastcall AutoFillCell(Variant Range)
{
/* Function FCellAutoFill("AutoFill");
 FCellAutoFill << Range << 1;
 Range.Exec(FCellAutoFill);  */
}

//”даление листа
void __fastcall DeleteSheet(Variant sheet)
{
Function FDeleteSheet("Delete");
sheet.Exec(FDeleteSheet);
}

// опирование листа
void __fastcall CopySheet(Variant sheet)
{
Function FCopySheet("Copy");
FCopySheet << sheet;
sheet.Exec(FCopySheet);
}

//‘ормат €чейки
void __fastcall SheetFormat(Variant cell, AnsiString Format)
{
 PropertySet PSFormatCell("NumberFormat");
 PSFormatCell << Format;
 cell.Exec(PSFormatCell);
}

//установка ширины строки
void __fastcall HeightRow (Variant Range, int height)
{
 PropertySet PSHeightRow("RowHeight");
 PSHeightRow << height;
 Range.Exec(PSHeightRow);
}

//обрамление €чейки
//1-обычна€ лини€, 2-мелкий пунктир, 3-крупный пунктир,4-одна длинна€ одна коротка€, 5-одна длинна€ две короткие, 9-двойна€ лини€,
//до 4 толщина линии
void __fastcall BorderCell (int col, int row, int typeline, int weightline)
{
 Variant Cell=SelectCell(col,row);
 Function FBorderCell("BorderAround");
 FBorderCell << typeline << weightline;
 Cell.Exec(FBorderCell);
}

void __fastcall Borders (Variant Range, int typeline, int weightline)
{
  Function FBorders("BorderAround");
 FBorders << typeline << weightline;
 Range.Exec(FBorders);
}

//ќриентаци€ текста в €чейке
void __fastcall CellOrient(int col, int row, int grad)
{
Variant Cell=SelectCell(col,row);
PropertySet PSOrient("Orientation");
PSOrient << grad;
Cell.Exec(PSOrient);
}

//ѕернос по словам
void __fastcall W1(Variant Range)
{
 PropertySet PGWrap("WrapText");
 PGWrap << true;
 Range.Exec(PGWrap);
}
