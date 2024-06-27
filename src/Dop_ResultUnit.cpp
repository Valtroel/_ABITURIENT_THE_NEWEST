//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dop_ResultUnit.h"
#include "DMUnit.h"
#include "SertificatUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDop_ResultForm *Dop_ResultForm;
//---------------------------------------------------------------------------
__fastcall TDop_ResultForm::TDop_ResultForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDop_ResultForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this -> Close ();
}
//---------------------------------------------------------------------------
void __fastcall TDop_ResultForm::BitBtn1Click(TObject *Sender)
{
if (LookFIO->Text!="" && (LookPred->KeyValue==1 || LookPred->KeyValue==4 || LookPred->KeyValue==9 || LookPred->KeyValue==10))
{
TLocateOptions flag;
if (!DM->QResult_Exam->Active) DM->QResult_Exam->Open();

if (DM->QResult_Exam->Locate("NOMER_AB;N_PREDMET",VarArrayOf(OPENARRAY(Variant,(LookFIO->KeyValue,LookPred->KeyValue))),flag))
        {
        ShowMessage("���� ���������� ��� ��� ������� � ��������� �� ������� �� ������� ��������");

        }
else
        {
        DM->QResult_Exam->Insert();
        DM->QResult_ExamNOMER_AB->Value=LookFIO->KeyValue;
        DM->QResult_ExamN_PREDMET->Value=LookPred->KeyValue;
        if (nom_fac!=4)
        {
           DM->QResult_ExamNOM_BALL->Value=11; //��������� 10 ������
           DM->QResult_ExamBALL->Value=10; //10 ������
        }
        else
        {
          if (DM->QAbituraKONKURS->Value==3)
            {
            DM->QResult_ExamNOM_BALL->Value=11; //��������� 10 ������
            DM->QResult_ExamBALL->Value=10; //10 ������
            }
          else
           {
           DM->QResult_ExamNOM_BALL->Value=13; //��������� ��������
           DM->QResult_ExamBALL->Value=100; //10 ������
           }
        }
        DM->QResult_ExamSTATUS_BALL->Value=2; // 2 - ������ ���������� ������ (�� ���������)
        try
                {
                DM->QResult_Exam->ApplyUpdates();
                DM->QResult_Exam->CommitUpdates();

                ShowMessage("���������� ����������� ������ �������!");

                if (!SertificatForm->summa_b(LookFIO->KeyValue)) ShowMessage("�� ������� �������������� ��� ������");

                LookPred->KeyValue=-1;
                LookFIO->KeyValue=-1;
                }
        catch(...)
                {
                DM->QResult_Exam->CancelUpdates();
                ShowMessage("��������� ���� ��� ����������, ���������� ��� ���!");
                }
        DM->QResult_Exam->Close();
        }
}
else ShowMessage("������� ��� ������");
}
//---------------------------------------------------------------------------
void __fastcall TDop_ResultForm::FormCreate(TObject *Sender)
{ //�������� �����
LookFIO->KeyValue=-1; //���
LookPred->KeyValue=-1;//�����
}
//---------------------------------------------------------------------------

