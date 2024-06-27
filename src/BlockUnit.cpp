//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "BlockUnit.h"
#include "DMUnit.h"
#include "DMVedUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBlockForm *BlockForm;
int pressBtn=0;
//1-���������
//0-���������
  TDateTime w;
AnsiString mes = ""; //���������� ��� ���������
//---------------------------------------------------------------------------
__fastcall TBlockForm::TBlockForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBlockForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this -> Close ();
}
//---------------------------------------------------------------------------
void __fastcall TBlockForm::BitBtn2Click(TObject *Sender)
{
PressBtn(1);
}
//---------------------------------------------------------------------------
void __fastcall TBlockForm::BitBtn1Click(TObject *Sender)
{
PressBtn(0);
}
//---------------------------------------------------------------------------
void __fastcall TBlockForm::PressBtn(int pressBtn)
{//������� ����������� ����� ������ ������ (0-���������, 1-���������)
int block=0, per=0, rg=0;
bool tab_sheet; //true-���������, false=����������
//---��������� �������� ������
if (PageControl1->ActivePageIndex==0)
{
   if (RadioGroup1->ItemIndex==-1)
   {
      mes="�������� ���������!";
      ShowMessage(mes);
   }
   else
   {//��������� Q
      DM->BlockQ->Close();
      DM->BlockQ->ParamByName("fac")->AsInteger=RadioGroup1->ItemIndex+1;
      DM->BlockQ->Open();

      block=DM->BlockQBLOCK->Value;     //���������� ���� BLOCK
      rg = RadioGroup1->ItemIndex+1;    //����������� ItemIndex
      tab_sheet=true;
   }
}
else
{//---���������� ����������
   if (RadioGroup2->ItemIndex==-1)
   {
       mes="�������� ���������!";
       ShowMessage(mes);
   }
   else
   {
       DM->BlockQ->Close();
       DM->BlockQ->ParamByName("fac")->AsInteger=RadioGroup2->ItemIndex+1;
       DM->BlockQ->Open();

       per=DM->BlockQPEREPODACHA->Value; //���������� ���� PEREPODACHA
       rg = RadioGroup2->ItemIndex+1;    //����������� ItemIndex
       tab_sheet=false;
   }
}
//��������� ���� �������
DMVed->QDate->Close();
DMVed->QDate->Open();
//DateServer=DateTimeToStr(SQLTimeStampToDateTime(DMVed->QDateCAST->Value));
 //w = SQLTimeStampToDateTime(DMVed->QDateCAST->Value);
DateServer=DateToStr(DMVed->QDateCAST->Value);



switch (pressBtn)
{
	case 0://0-������ ������
                if (tab_sheet==true)
                {//if tab_sheet1
                   if (block==0)
                   {//if � �� ���� ����������
                        mes="���������� " + IntToStr(rg) + " �������� ���������� ��� ���������!";
                        ShowMessage(mes);
                        RadioGroup1->ItemIndex=-1;
                   }//end � �� ���� ����������
                   else
                   {//else ���� ����������
                         DM->BlockQ->Edit();
                         DM->BlockQBLOCK->Value=0;
                         DM->BlockQNOTE->Value="��������� �������� ������ � "+ DateServer;
                   }//and else ���� ����������
                }//and if tab_sheet1
                else
                {//else tab_sheet2
                   if (per==0)
                   {//if � �� ���� ����������
                        mes="���������� " + IntToStr(rg) + " ���������� ���������� ��� ���������!";
                        ShowMessage(mes);
                        RadioGroup1->ItemIndex=-1;
                   }//end � �� ���� ����������
                   else
                   {//else ���� ����������
                         DM->BlockQ->Edit();
                         DM->BlockQPEREPODACHA->Value=0;
                         DM->BlockQNOTE_PEREPODACHA->Value="��������� ���������� ���������� � "+ DateServer;
                   }//and else ���� ����������
                }//and if tab_sheet2
	        break;

	case 1://1-����������� �������
	        if (tab_sheet==true)
                {//if tab_sheet1
                   if (block==1)
                   {//if � �� ���� ������
                        mes="���������� " + IntToStr(rg) + " �������� ���������� ��� ���������!";
                        ShowMessage(mes);
                        RadioGroup1->ItemIndex=-1;
                   }//end � �� ���� ������
                   else
                   {//else ���� ������
                         DM->BlockQ->Edit();
                         DM->BlockQBLOCK->Value=1;
                         DM->BlockQNOTE->Value="��������� �������� ������ � "+ DateServer;
                   }//and else ���� ������
                }//and if tab_sheet1
                else
                {//else tab_sheet2
                    if (per==1)
                    {//if � �� ���� ����������
                        mes="���������� " + IntToStr(rg) + " ���������� ���������� ��� ���������!";
                        ShowMessage(mes);
                        RadioGroup1->ItemIndex=-1;
                    }//end � �� ���� ����������
                    else
                    {//else ���� ����������
                         DM->BlockQ->Edit();
                         DM->BlockQPEREPODACHA->Value=1;
                         DM->BlockQNOTE_PEREPODACHA->Value="��������� ���������� ���������� � "+ DateServer;
                    }//and else ���� ����������
                }//else tab_sheet2
        	break;
}
if (DM->BlockQ->State==dsEdit)
{
     try
     {
        DM->BlockQ->ApplyUpdates();
        DM->BlockQ->CommitUpdates();
        DM->BlockQ->Close();
        mes="���������� ������ �������!";
        ShowMessage(mes);
     }
     catch(...)
     {
        mes="��������� ����! ��������� ��������!";
        ShowMessage(mes);
     }
}
}//end ������� ����������� ����� ������ ������ (0-���������, 1-���������)
//---------------------------------------------------------------------------

