//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MyDialogPass.h"
#include "PassDialog.h"
#pragma package(smart_init)

//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TMyDialogPass *)
{
        new TMyDialogPass(NULL);
}
//---------------------------------------------------------------------------
__fastcall TMyDialogPass::TMyDialogPass(TComponent* Owner)
        : TComponent(Owner)
{

     // Login=;
      Pass = "";

}
//---------------------------------------------------------------------------
namespace Mydialogpass
{
        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TMyDialogPass)};
                 RegisterComponents("My", classes, 0);
        }
}
//---------------------------------------------------------------------------

bool __fastcall TMyDialogPass::Execute(TMyDialogPass* MD)
{
    Chek_user_login = new TChek_user_login(this,MD);

    //Передаю в форму надписи на компоненты
    if  (Label1Caption  !="")
    {
       Chek_user_login->Label1->Caption = Label1Caption;
    }

    if  (Label2Caption  !="")
    {
       Chek_user_login->Label2->Caption = Label2Caption;
    }
    if  (Label3Caption  !="")
    {
       Chek_user_login->Label3->Caption = Label3Caption;
    }

    if  (Label4Caption  !="")
    {
       Chek_user_login->Label4->Caption = Label4Caption;
    }



    if  (BitBtn1Caption  !="")
    {
       Chek_user_login->OKBitBtn->Caption = BitBtn1Caption;
    }

    if  (BitBtn2Caption  !="")
    {
       Chek_user_login->ExitBitBtn->Caption = BitBtn2Caption;
    }
    if  (FormCaption  !="")
    {
       Chek_user_login->Caption = FormCaption;
    }

    //Форма
    Chek_user_login->ShowModal();
    if (Chek_user_login->Result)
    return true;
    else return false;


}

void __fastcall TMyDialogPass::RezSource()
{
   FLogin=Chek_user_login->Edit1->Text;
   FPass =Chek_user_login->Edit2->Text;
}
