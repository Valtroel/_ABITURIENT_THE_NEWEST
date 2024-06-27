//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MyList.h"

#pragma package(smart_init)
extern TStringList* Global_List;
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TMyList *)
{
      new TMyList(NULL);
}
//-------ITS MY
/*AnsiString __fastcall TMyList::GetString(int Index)
{
if (Index > (SourceList->Count-1))
      return "";
return SourceList->Strings[Index];
}

void __fastcall TMyList::SetString(int Index, AnsiString Value)
{
 if ((SourceList->Count-1) < Index)
     SourceList->Add(Value);
 SourceList->Insert(Index, Value);
} */
//---------------------------------------------------------------------------
__fastcall TMyList::TMyList(TComponent* Owner)
        : TComponent(Owner)
{
     //Создается объкт StringList
     SourceList=new TStringList;
     FOutList = new TStringList;
     FInList = new TStringList;
     //Для Связи с Query
     FDataLink = new TFieldDataLink();
     FDataLink->Control=this;
    

}
//---------------------------------------------------------------------------
namespace Mylist
{
        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TMyList)};
                 RegisterComponents("My", classes, 0);
        }
}
//---------------------------------------------------------------------------

bool __fastcall TMyList::Execute(TMyList* ML)
{
    MyFList = new TMyFList(this,ML);
   // SourceList->Clear();
   //Постановка сортировки
   if (SelectList1==true)
   {
       MyFList->ListBox1->Sorted=true;
   }
   else
   {
       MyFList->ListBox1->Sorted=false;
   }
   if (SelectList2==true)
   {
       MyFList->ListBox2->Sorted=true;
   }
   else
   {
       MyFList->ListBox2->Sorted=false;
   }


    //Передаю в форму надписи на компоненты
    if  (Label1Caption  !="")
    {
       MyFList->Label1->Caption = Label1Caption;
    }

    if  (Label2Caption  !="")
    {
       MyFList->Label2->Caption = Label2Caption;
    }
    if  (BitBtn1Caption  !="")
    {
       MyFList->OKButton->Caption = BitBtn1Caption;
    }

    if  (BitBtn2Caption  !="")
    {
       MyFList->ExitButton->Caption = BitBtn2Caption;
    }
    if  (FormCaption  !="")
    {
       MyFList->Caption = FormCaption;
    }
    //Добавление String в List1
    if (FDataLink->DataSource!=NULL)//&&(String==""))
    {
       FDataLink->DataSet->First();
       int i=1;
       AnsiString Str;
       while (i<FDataLink->DataSet->RecordCount)
       {
           int j=0;
           Str="";
            while (j<FDataLink->DataSet->FieldCount)
            {
                if ((FDataLink->DataSet->Fields->Fields[j]->DataType==ftSmallint)||(FDataLink->DataSet->Fields->Fields[j]->DataType==ftInteger))
                {
                    if (!FDataLink->DataSet->Fields->Fields[j]->Value.IsNull())
                    {
                       AnsiString St1=FDataLink->DataSet->Fields->Fields[j]->Value.AsType(8);
                       Str=Str+St1+" ";
                     }//if
                     else
                     {
                       Str=Str+" ";
                     }
                }
                else
                {
                   if (!FDataLink->DataSet->Fields->Fields[j]->Value.IsNull())
                  {
                     Str=Str+FDataLink->DataSet->Fields->Fields[j]->Value + " ";
                   }//if
                   else
                   {
                     Str=Str+" ";
                   }
                }
                j++;
            } //while
            SourceList->Add(Str);
            i++;
            FDataLink->DataSet->Next();
       }
     }
    // if ((FDataLink->DataSource!=NULL)&&(String!=""))
   //  {
     //      SourceList=InputString;
    // } //if

    //Процедура добавления строк в ListBox1
    RefreshSourceBox(MyFList->ListBox1);
    ///  Сортировка в List
   // MyFList->ListBox1->Sorted;
   // MyFList->ListBox2->Sorted;
    //
    MyFList->ShowModal();
    if (MyFList->Result)
    return true;
    else return false;
}

//////////////////////////////////////////////////////////////
//Процедура связывания строк в List
void __fastcall TMyList::RefreshSourceBox(TListBox* Box)
{
   int he=0;
   Box->Clear();
   for (int i=0;i<=SourceList->Count-1;i++)
   {
      Box->Items->Add(SourceList->Strings[i]);
      if (Box->Items->Strings[i].Length()>he)
         he+=Box->Items->Strings[i].Length()*5;
   }
   //Добавление горизонтальной полосы прокрутки
   Box->Perform(LB_SETHORIZONTALEXTENT,Box->Width+he+18,0);

}
//Процедура возврата строк
void __fastcall TMyList::RezSourceBox()
{
   for (int i=0;i<MyFList->ListBox2->Items->Count;i++)
   {
     //Формирование List2
     FOutList->Add(MyFList->ListBox2->Items->Strings[i]);
   }
   FInList->Clear();
   for (int i=0;i<MyFList->ListBox1->Items->Count;i++)
   {
     //Формирование List1
     FInList->Add(MyFList->ListBox1->Items->Strings[i]);
   }

}

//Процедуры для Query для связывания Source и Field


 TDataSource* __fastcall TMyList::GetDataSource(void)
{
   return(FDataLink->DataSource);
}


void __fastcall TMyList::SetDataSource(TDataSource* pDataSource)
{
   if(pDataSource !=NULL)
      pDataSource->FreeNotification(this);
   FDataLink->DataSource=pDataSource;

}

//Деструктор

__fastcall TMyList::~TMyList(void)
{
    if(FDataLink)
    {
      FDataLink->Control=0;
      FDataLink->OnUpdateData=0;
      delete FDataLink;
    }
    delete SourceList;
    
}


