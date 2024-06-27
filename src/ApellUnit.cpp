//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ApellUnit.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TApellForm *ApellForm;
//---------------------------------------------------------------------------
__fastcall TApellForm::TApellForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TApellForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this -> Close ();
}
//---------------------------------------------------------------------------
void __fastcall TApellForm::BitBtn1Click(TObject *Sender)
{
    if (    (LookB->Text!="2")
         && (LookB->Text!="�������")
         && (LookB->Text!="1")
         && (LookB->Text!="0")
         && (LookB->Text!="")
       )
    {//if �������� �� ��������� ������
        TLocateOptions fl;

        if (!DM->QResult_Exam->Active) DM->QResult_Exam->Open();

          if (  DM -> QResult_Exam ->
                    Locate (
                        "NOMER_AB;N_PREDMET",
                        VarArrayOf (
                            OPENARRAY (
                                Variant,
                                (
                                    LookF -> KeyValue,
                                    LookP -> KeyValue
                                )
                            )
                        ),
                        fl
                    )
             )
           {//if1 ���������� � ��������� ������ ��. � ��������
            if (    DM->QResult_ExamBALL->Value == 2
                 || DM->QResult_ExamBALL->Value == 1
                 || DM->QResult_ExamBALL->Value == 0
                )
            { //if 2 �������� ��������� ������
                DM->QResult_Exam->Edit();
                try
                {
                    DM->QResult_ExamBALL->Value=LookB->Text.ToInt();
                 DM->QResult_ExamNOM_BALL->Value=LookB->KeyValue;
                 DM->QResult_Exam->ApplyUpdates();
                 DM->QResult_Exam->CommitUpdates();

                 DM->QUndo_Abit->Edit();
                 DM->QUndo_AbitSTATUS->Value=0;
                 DM->QUndo_Abit->ApplyUpdates();
                 DM->QUndo_Abit->CommitUpdates();
                 }
                catch (EConvertError&)
                 {
                 ShowMessage("��������� �������� �� �������� ��������!");
                 }
                }
           else if (DM->QResult_ExamBALL->Value==0)
            { //else if if2
              AnsiString str_ball;
             str_ball=AnsiToUtf8(DM->TBall->Lookup("NOM_BALL",DM->QResult_ExamNOM_BALL->Value,"BALL"));
             str_ball.SetLength(2);
             if (str_ball.LowerCase()=="��")
              {
             DM->QResult_Exam->Edit();
             try
             {
             LookB->Text.ToDouble();
             ShowMessage("��������� �������� �� �������� ���������!");
             }
            catch (EConvertError&)
             {
             DM->QResult_ExamNOM_BALL->Value=LookB->KeyValue;
             DM->QResult_Exam->ApplyUpdates();
             DM->QResult_Exam->CommitUpdates();

             DM->QUndo_Abit->Edit();
             DM->QUndo_AbitSTATUS->Value=0;
             DM->QUndo_Abit->ApplyUpdates();
             DM->QUndo_Abit->CommitUpdates();
             }
              }
             else
              {
              ShowMessage("������������� ������ ���������� � ����������� ���������!");
              }
            }
           else
            {//else if2
            ShowMessage("������������� ������ ���������� � ����������� ���������!");
            }
           } //if1
          else
           {//else if1
           ShowMessage("������ ���������� �� ������ ������� �� ����� ��������. ��������� ������������ ��������� ������!");
           }
 }//if
else
 {
  ShowMessage("�� ��������� ������ ������ ���� �������������!");
 }
DM->QGroup_Count->Close();
DM->QGroup_Count->ParamByName("N_FAC")->AsInteger=nom_fac;
DM->QGroup_Count->Open();

Close();
}
//---------------------------------------------------------------------------

