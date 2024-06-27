//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Inifiles.hpp>

#include "PassDialog.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma resource "*.dfm"
TChek_user_login *Chek_user_login;
//---------------------------------------------------------------------------
__fastcall TChek_user_login::TChek_user_login(TComponent* Owner,TMyDialogPass* FR)
        : TForm(Owner)
{
      FunRezPass=FR;
}
//---------------------------------------------------------------------------
void __fastcall TChek_user_login::ExitBitBtnClick(TObject *Sender)
{
   Chek_user_login->Close();
   Result=false;
}
//---------------------------------------------------------------------------
void __fastcall TChek_user_login::OKBitBtnClick(TObject *Sender)
{
    FunRezPass->RezSource();
    Chek_user_login->Close();
    Result=true;
}
//---------------------------------------------------------------------------
void __fastcall TChek_user_login::FormCreate(TObject *Sender)
{
   //ChangeFileExt
   TIniFile* ini = new TIniFile(ChangeFileExt(Application->ExeName, ".INI") );
   Edit1->Text =  ini->ReadString( "Edit1", "Text",Edit1->Text);
   delete ini;
   

}
//---------------------------------------------------------------------------

void __fastcall TChek_user_login::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   TIniFile *ini;
   ini = new TIniFile(ChangeFileExt (Application->ExeName, ".INI") ) ;
   ini->WriteString ( "Edit1", "Text",Edit1->Text );
   delete ini;

}
//---------------------------------------------------------------------------

void __fastcall TChek_user_login::FormActivate(TObject *Sender)
{
     Edit2->SetFocus();   
}
//---------------------------------------------------------------------------

