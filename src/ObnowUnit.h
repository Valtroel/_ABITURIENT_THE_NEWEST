#pragma once
#ifndef OBNOW_UNIT_H
#define OBNOW_UNIT_H


#include <Data.DB.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.StdCtrls.hpp>



class TForm1
    : public TForm
{
__published:
    TDBGrid * DBGrid1;

    TButton * Обновить;
private:
public:
    __fastcall TForm1 (TComponent * Owner);
};

extern PACKAGE TForm1 * Form1;

#endif  // OBNOW_UNIT_H