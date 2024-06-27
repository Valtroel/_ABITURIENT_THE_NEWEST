//---------------------------------------------------------------------------

#ifndef MyDListH
#define MyDListH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>

    
//---------------------------------------------------------------------------
class TMyFList : public TForm
{
   friend  class TMyList;
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TLabel *Label1;
        TLabel *Label2;
        TListBox *ListBox1;
        TListBox *ListBox2;
        TBitBtn *OKButton;
        TBitBtn *ExitButton;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn6;
        TBitBtn *BitBtn7;
        TBitBtn *BitBtn5;
        //Процедуры для работы с List
        void __fastcall BitBtn4Click(TObject *Sender);
        //Функция для передачи одной записи
        Integer __fastcall GetFirstSelection(TCustomListBox * List);
        void __fastcall MoveSelected(TCustomListBox * List, TStrings * Items);
        void __fastcall SetItem(TListBox * List, int Index);
        void __fastcall SetButtons();
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall BitBtn7Click(TObject *Sender);
        void __fastcall ListBox1DblClick(TObject *Sender);
        void __fastcall ListBox2DblClick(TObject *Sender);
        void __fastcall ExitButtonClick(TObject *Sender);
        void __fastcall OKButtonClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);

private:	// User declarations
          TMyList* FunRez;
public:		// User declarations
        bool Result;
        __fastcall TMyFList(TComponent* Owner, TMyList* FR);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyFList *MyFList;

//---------------------------------------------------------------------------
#endif
