//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MyDList.h"
#include "MyList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMyFList *MyFList;
int he;
int he1;
//---------------------------------------------------------------------------
__fastcall TMyFList::TMyFList(TComponent* Owner,TMyList* FR)
        : TForm(Owner)
{
     FunRez=FR;

}
//---------------------------------------------------------------------------
void __fastcall TMyFList::BitBtn4Click(TObject *Sender)
{
    he=0;
    he1=0;
    int Index;
    Index = GetFirstSelection(ListBox1);
     if (ListBox1->Items->Strings[Index].Length()>he)
    {
       he+=ListBox1->Items->Strings[Index].Length()*5;
    }
    MoveSelected(ListBox1, ListBox2->Items);
    SetItem(ListBox1, Index);
    //ƒобавление горизонтальной полосы прокрутки
   
    for (int i=0;i<=ListBox1->Items->Count-1;i++)
   {
       if (ListBox1->Items->Strings[i].Length()>he1)
         he1+=ListBox1->Items->Strings[i].Length()*5;
   }
   // ListBox1->Sorted= true;
   // ListBox2->Sorted= true;
    //полоса прокрутки в List2
    ListBox2->Perform(LB_SETHORIZONTALEXTENT,ListBox2->Width+he+18,0);
    //полоса прокрутки в List1
    ListBox1->Perform(LB_SETHORIZONTALEXTENT,ListBox1->Width+he1+18,0);
    if (ListBox1->Items->Count==0)
        ListBox1->Perform(LB_SETHORIZONTALEXTENT,0,0);


}
//---------------------------------------------------------------------------


Integer __fastcall TMyFList::GetFirstSelection(TCustomListBox *List)
{
     for (int i=0; i < List->Items->Count; i++)
      {
      	 if (List->Selected[i])
	 return i;
	}

	return LB_ERR;

}

void __fastcall TMyFList::MoveSelected(TCustomListBox *List, TStrings *Items)
{
     int i;
     for (i=List->Items->Count-1; i >= 0; i--)
	{   if (List->Selected[i])
	    {	Items->AddObject(List->Items->Strings[i], List->Items->Objects[i]);
	     	List->Items->Delete(i);
	    }
	}

}

void __fastcall TMyFList::SetItem(TListBox *List, int Index)
{
      int MaxIndex;
      List->SetFocus();
      MaxIndex = List->Items->Count;
      if (Index == LB_ERR)
       	Index = 0;
      else {if (Index > MaxIndex)
		Index = MaxIndex;}
      if (MaxIndex!=0)
          List->ExtendedSelect;//    ->Selected[Index] = true;
      SetButtons();

}

void __fastcall TMyFList::SetButtons()
{
       bool List1Empty, List2Empty;

	List1Empty = (ListBox1->Items->Count == 0);
	List2Empty = (ListBox2->Items->Count == 0);
	BitBtn4->Enabled = (!List1Empty);
	BitBtn5->Enabled = (!List1Empty);
	BitBtn6->Enabled = (!List2Empty);
	BitBtn7->Enabled = (!List2Empty);

}
void __fastcall TMyFList::BitBtn5Click(TObject *Sender)
{
    int i;
    he=0;
    for (i=0; i < ListBox1->Items->Count; i++)
    {
       	ListBox2->Items->AddObject(ListBox1->Items->Strings[i], ListBox1->Items->Objects[i]);
        if (ListBox1->Items->Strings[i].Length()>he)
        he+=ListBox1->Items->Strings[i].Length()*5;

     }

    ListBox1->Items->Clear();
    SetItem(ListBox1, 0);
    //ƒл€ сортировки
   // ListBox1->Sorted= true;
   // ListBox2->Sorted= true;
    //полоса прокрутки в List2
    ListBox2->Perform(LB_SETHORIZONTALEXTENT,ListBox2->Width+he+18,0);
    //полоса прокрутки в List1 не нужна



}
//---------------------------------------------------------------------------

void __fastcall TMyFList::BitBtn6Click(TObject *Sender)
{
   int Index;
   Index = GetFirstSelection(ListBox2);
   MoveSelected(ListBox2, ListBox1->Items);
   SetItem(ListBox2, Index);
    //ƒл€ сортировки
  //  ListBox1->Sorted= true;
  //  ListBox2->Sorted= true;
    //≈сли нет элементов то полосы прокрутки нет
    if (ListBox2->Items->Count==0)
        ListBox2->Perform(LB_SETHORIZONTALEXTENT,0,0);

}
//---------------------------------------------------------------------------

void __fastcall TMyFList::BitBtn7Click(TObject *Sender)
{
    int i;
    for (i=0; i < ListBox2->Items->Count; i++)
    	ListBox1->Items->AddObject(ListBox2->Items->Strings[i], ListBox2->Items->Objects[i]);
    ListBox2->Items->Clear();
    SetItem(ListBox2, 0);
     //ƒл€ сортировки
  //  ListBox1->Sorted= true;
  //  ListBox2->Sorted= true;
    ListBox2->Perform(LB_SETHORIZONTALEXTENT,0,0);

}
//---------------------------------------------------------------------------


void __fastcall TMyFList::ListBox1DblClick(TObject *Sender)
{
    TMyFList::BitBtn4Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMyFList::ListBox2DblClick(TObject *Sender)
{
    TMyFList::BitBtn6Click(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TMyFList::ExitButtonClick(TObject *Sender)
{
   MyFList->Close();
   Result=false;
}
//---------------------------------------------------------------------------

void __fastcall TMyFList::OKButtonClick(TObject *Sender)
{
    FunRez->RezSourceBox();
    MyFList->Close();
    Result=true;
}
//---------------------------------------------------------------------------

void __fastcall TMyFList::FormClose(TObject *Sender, TCloseAction &Action)
{
   Action=caFree;     
}
//---------------------------------------------------------------------------

void __fastcall TMyFList::FormShow(TObject *Sender)
{
    //    
}
//---------------------------------------------------------------------------



