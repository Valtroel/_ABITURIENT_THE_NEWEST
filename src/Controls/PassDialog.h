//---------------------------------------------------------------------------

#ifndef PassDialogH
#define PassDialogH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include "MyDialogPass.h"

//---------------------------------------------------------------------------
class TChek_user_login : public TForm
{
  friend  class TMyDialogPass;
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit1;
        TLabel *Label3;
        TEdit *Edit2;
        TLabel *Label4;
        TBitBtn *OKBitBtn;
        TBitBtn *ExitBitBtn;
        void __fastcall ExitBitBtnClick(TObject *Sender);
        void __fastcall OKBitBtnClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormActivate(TObject *Sender);

private:	// User declarations
        TMyDialogPass* FunRezPass;

public:		// User declarations
        __fastcall TChek_user_login(TComponent* Owner,TMyDialogPass* FR);
        bool Result;
};
//---------------------------------------------------------------------------
extern PACKAGE TChek_user_login *Chek_user_login;
//---------------------------------------------------------------------------
#endif
