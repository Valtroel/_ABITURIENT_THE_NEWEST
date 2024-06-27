#pragma once
#ifndef FUNC1_H
#define FUNC1_H


extern const AnsiString mas_column[];                                           // = {"A", ..., "AZ"};
extern       Variant    CurCell,                                                // ������� ������
                        CurSheet;                                               // ������� �������


void    __fastcall AutoFillCell    (Variant Range     );                        // ��������������
void    __fastcall AutoFitColumn   (                                            // ���������� ������ �������
        Variant    Sheet,
        int        Col
    );
void    __fastcall AutoFitRow      (                                            // ���������� ������ ������
        Variant    Sheet,
        int        Row
    );
void    __fastcall BorderCell      (                                            // ���������� ������
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
void    __fastcall CellFont        (                                            // ���������� ��������� ������
        AnsiString NameFont,
        int        SizeFont,
        bool       BoldFont,
        bool       ItalicFont,
        int        UnderlineFont,
        Variant    Range
    );
void     _fastcall CellFormula     (                                            // ���� ������� � ������
        AnsiString formula,
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall CellOrient      (                                            // ���������� ������ � ������
        int        col,
        int        row,
        int        grad
    );
void     _fastcall CellValue       (                                            // ���� �������� � ������
        Variant    value,
        int        column = 0,
        int        row = 0,
        Variant    sheet = 0
    );
void    __fastcall CopySheet       (Variant sheet     );                        // ����������� �����
void    __fastcall DeleteSheet     (Variant sheet     );                        // �������� �����
void     _fastcall DisplayAlert    (Variant ole_obj   );                        // ������ ������� Excela �� ������������� ��������
Variant  _fastcall GetCellValue    (                                            // ���������  �������� �� ������
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall HeightRow       (                                            // ��������� ������ ������
        Variant    Range,
        int        height
    );
void    __fastcall HorizontalAlign (                                            // ������������ ����������� ������ �� �����������
        Variant    Range,
        int        nom_align
    );
void    __fastcall M1              (Variant Range     );                        // ����������� �����
void     _fastcall NameSheet1      (                                            // �������������� �����
        Variant    sheet,
        AnsiString name
    );
Variant __fastcall NewBook         (Variant excel_app );                        // ����� �����
Variant  _fastcall NewSheet1       (Variant excel_app );                        // ���������� ������ �����
Variant  _fastcall OpenBook        (                                            // Open WorkBook
        Variant    excel_app,
        AnsiString full_name
    );
void     _fastcall OVisible        (Variant ole_obj   );                        // set Visible to Ole object
void    __fastcall Quit_ex         (Variant excel_app );                        // delete Excel
Variant __fastcall Range           (                                            // ��������� �����
        Variant    excel_book,
        Variant    Cell1,
        Variant    Cell2
    );
Variant  _fastcall SaveBook        (Variant excel_book);                        // ���������� �����
Variant  _fastcall SaveBookAs      (                                            // ���������� ����� c ����� ������
        Variant    excel_book,
        AnsiString name
    );
Variant  _fastcall SelectCell      (                                            // ����� ������ �� ������
        int        column,
        int        row,
        Variant    sheet  = 0
    );
Variant __fastcall SelectColumn    (                                            // ������� �������
        Variant    sheet,
        int        column
    );
Variant __fastcall SelectRow       (                                            // ������� ������
        Variant    sheet,
        int        row
    );
Variant  _fastcall SelectSheet     (                                            // Select WorkSheet by Name
        Variant    excel_book,
        AnsiString name
    );
void    __fastcall SheetFormat     (                                            // ������ ������
        Variant    cell,
        AnsiString Format
    );
void    __fastcall VerticalAlign   (                                            // ������������ ����������� ������ �� ���������
        Variant    Range,
        int        nom_align
    );
void    __fastcall W1              (Variant Range     );                        // ������ �� ������

#endif  // FUNC_H