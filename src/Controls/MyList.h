//---------------------------------------------------------------------------

#ifndef MyListH
#define MyListH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include "MyDList.h"
#include <DBCtrls.hpp>

//---------------------------------------------------------------------------
class PACKAGE TMyList : public TComponent
{
   typedef void __fastcall(__closure *TNotifyEvent)(System::TObject*Sender);

private:
//Для строк
   //TStringList* SourceList;
//Для вых. строк
   //TStringList* FOutList;
// Для текста
   AnsiString FString;
   bool FSortedList1;
   bool FSortedList2;
//Переменная для Sourse
   TFieldDataLink* FDataLink;
 //Caption кнопок
   TCaption FLabel1Caption;
   TCaption FLabel2Caption;
   TCaption FBitBtn1Caption;
   TCaption FBitBtn2Caption;
   TCaption FFormCaption;


//Для строк
        //AnsiString __fastcall GetString(int Index);
       //     void __fastcall SetString(int Index, AnsiString Value);
//Для Query   для связывания с базой
AnsiString __fastcall GetDataField(void);
       TDataSource* __fastcall GetDataSource(void);
       void __fastcall SetDataSource(TDataSource* pDataSource);

protected:


public:
   //Для строк
   TStringList* SourceList;
  //Для вых. строк
  TStringList* FOutList;
  //Для вых. строк из первого List
  TStringList* FInList;
        __fastcall TMyList(TComponent* Owner);
        __fastcall ~TMyList(void);
        //Выполнить
        virtual bool __fastcall Execute(TMyList* ML);
        //Закрыть

        //Процедура для добавления Items в List
        void __fastcall RefreshSourceBox(TListBox* Box);
        void __fastcall RezSourceBox();

__published:
        __property bool SelectList1={read=FSortedList1, write=FSortedList1};
        __property bool SelectList2={read=FSortedList2, write=FSortedList2};

          //Свойства для надписей компонентов
        __property TCaption Label1Caption  = { read=FLabel1Caption, write=FLabel1Caption };
        __property TCaption Label2Caption  = { read=FLabel2Caption, write=FLabel2Caption };
        __property TCaption BitBtn1Caption  = { read=FBitBtn1Caption, write=FBitBtn1Caption };
        __property TCaption BitBtn2Caption  = { read=FBitBtn2Caption, write=FBitBtn2Caption };
        __property TCaption FormCaption  = { read=FFormCaption, write=FFormCaption };
        //Результат массив строк
     //   __property TStringList* RezString = {read=FOutList, write=FOutList};
        //Входящий массив строк
     //  __property TStringList* InputString = {read=SourceList, write=SourceList};
         //Свойства для базы данных
       __property TDataSource* DataSource  = { read=GetDataSource, write =SetDataSource,nodefault };

       //Свойства компонента

        };
//---------------------------------------------------------------------------

#endif
