#include <vcl.h>
#pragma hdrstop


#include "PassDlgUnit.h"
#include "SpravUnit.h"
#include "BlockUnit.h"
#include "DMUnit.h"


#pragma resource "*.dfm"


TPassDlg *PassDlg;


__fastcall TPassDlg::TPassDlg (TComponent * AOwner)
    : TForm(AOwner)
{ }

void __fastcall TPassDlg::BitBtn1Click (TObject * Sender)
{
    AnsiString
        UsN  = "ADMIN",
        Pass = "abitura" + Admissions::TIME::YEAR;

   if (    User -> Text.UpperCase () == UsN
        && Password -> Text          == Pass
      )
   {
        switch (n_menu)                                                         // открываем форму в зависимости от выбранного в меню Настройки
        {
            case 52:                                                            // Справочники
                    SpravForm =  new TSpravForm (this);
                    SpravForm -> ShowModal ();
                break;
            case 53:                                                            // Ограничение доступа
                    BlockForm =  new TBlockForm (this);
                    BlockForm -> ShowModal();
                break;
        }
   }
   else
        ShowMessage (
            "Неверное имя пользователя или пароль"
        );
}
void __fastcall TPassDlg::BitBtn2Click (TObject * Sender)
{
    this -> Close ();
}
void __fastcall TPassDlg::FormActivate (TObject * Sender)
{
    User     -> Text = "";
    Password -> Text = "";
}
void __fastcall TPassDlg::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}
