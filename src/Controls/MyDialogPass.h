//---------------------------------------------------------------------------

#ifndef MyDialogPassH
#define MyDialogPassH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>


//---------------------------------------------------------------------------
class PACKAGE TMyDialogPass : public TComponent
{
 typedef void __fastcall(__closure *TNotifyEvent)(System::TObject*Sender);
private:
     TCaption FFormCaption;
     TCaption FLabel1Caption;
     TCaption FLabel2Caption;
     TCaption FLabel3Caption;
     TCaption FLabel4Caption;
     TCaption FBitBtn1Caption;
     TCaption FBitBtn2Caption;
     String FLogin;
     String FPass;


protected:
public:
        __fastcall TMyDialogPass(TComponent* Owner);
        
        //Выполнить
        virtual bool __fastcall Execute(TMyDialogPass* MD);
        void __fastcall RezSource();

__published:

       __property String Login  = { read=FLogin, write=FLogin };
       __property String Pass  = { read=FPass, write=FPass };
        //Свойство для Caption формы
       __property TCaption FormCaption  = { read=FFormCaption, write=FFormCaption };
      //Свойство для надписей на Label
      __property TCaption Label1Caption  = { read=FLabel1Caption, write=FLabel1Caption };
      __property TCaption Label2Caption  = { read=FLabel2Caption, write=FLabel2Caption };
      __property TCaption Label3Caption  = { read=FLabel3Caption, write=FLabel3Caption };
      __property TCaption Label4Caption  = { read=FLabel4Caption, write=FLabel4Caption };
      __property TCaption BitBtn1Caption  = { read=FBitBtn1Caption, write=FBitBtn1Caption };
      __property TCaption BitBtn2Caption  = { read=FBitBtn2Caption, write=FBitBtn2Caption };

};
//---------------------------------------------------------------------------
#endif
 