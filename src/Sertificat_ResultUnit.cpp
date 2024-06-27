//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sertificat_ResultUnit.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSertificat_ResultForm *Sertificat_ResultForm;
//---------------------------------------------------------------------------
__fastcall TSertificat_ResultForm::TSertificat_ResultForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSertificat_ResultForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
caFree;        
}
//---------------------------------------------------------------------------
void __fastcall TSertificat_ResultForm::Button1Click(TObject *Sender)
{
if (Edit1->Text!="")
{
DM->QSertificat_Res->Close();
DM->QSertificat_Res->ParamByName("FAC")->AsSmallInt=nom_fac;
DM->QSertificat_Res->ParamByName("GR")->AsString=Edit1->Text;
DM->QSertificat_Res->ParamByName("PR")->AsSmallInt=4;
DM->QSertificat_Res->Open();
      if (!DM->QSertificat_Res->RecordCount)
      {
        ShowMessage("В этой группе нет абитуриентов с тестированием!");
        return;
       }
       else
      {
        //----------- Enabled

        LookPred->Enabled=true;
        LookPred->KeyValue=4;
        LookFIO->Enabled=true;
        Button2->Enabled=true;
       }
}
else
{
 ShowMessage("Введите номер группы");
 Edit1->SetFocus();
}
}
//---------------------------------------------------------------------------
void __fastcall TSertificat_ResultForm::FormShow(TObject *Sender)
{
LookPred->KeyValue=4;        
}
//---------------------------------------------------------------------------
void __fastcall TSertificat_ResultForm::Button2Click(TObject *Sender)
{
if (LookFIO->Text!="" && LookPred->KeyValue==4)
{
 /*DM->QShkala->Close();
 DM->QShkala->ParamByName("N_PR")->AsSmallInt=LookPred->KeyValue;
 DM->QShkala->ParamByName("N_BALL")->AsSmallInt=DM->QSertificat_ResBALLS->Value;
 DM->QShkala->ParamByName("N_BALLS")->AsSmallInt=DM->QSertificat_ResBALLS->Value;
 DM->QShkala->Open();

 Label5->Caption=DM->QShkalaBALL->Value;  */

 Label5->Caption=DM->ball_result(DM->QSertificatBALLS->Value, nom_fac);

 Label7->Caption=DM->QSertificat_ResSERIA_S->Value+" № "+DM->QSertificat_ResNOMER_S->Value;
 Label9->Caption=DM->QSertificat_ResBALLS->Value;
 Variant rus=DM->QSertificat_ResRUS_BEL->AsVariant;
  if (!rus.IsNull())
  {
      if (rus)  Label11->Caption="Белорусский язык"; //rus=1 белорусский язык
      else   Label11->Caption="Русский язык";    //rus=0 русский язык
  }
  else  Label11->Caption="";


 //----------Visible

 Label4->Visible=true;
 Label5->Visible=true;
 Label6->Visible=true;
 Label7->Visible=true;
 Label8->Visible=true;
 Label9->Visible=true;
 Label10->Visible=true;
 Label11->Visible=true;
 BitBtn1->Visible=true;
}
else
{
 ShowMessage("Проверьте правильность введенных данных!");
}
}
//---------------------------------------------------------------------------
void __fastcall TSertificat_ResultForm::BitBtn1Click(TObject *Sender)
{
TLocateOptions flag;
if (!DM->QResult_Exam->Active) DM->QResult_Exam->Open();

if (DM->QResult_Exam->Locate("NOMER_AB;N_PREDMET",VarArrayOf(OPENARRAY(Variant,(LookFIO->KeyValue,LookPred->KeyValue))),flag))
        {
             if (DM->QResult_ExamNOM_BALL->Value!=0)
             {
               ShowMessage("У этого абитуриента уже есть оценка по данному предмету");
             }
             else ShowMessage("Этот абитуриент уже был включен в ведомость на экзамен по данному предмету");
        }
else
        {  //else
        DM->QResult_Exam->Insert();
        DM->QResult_ExamNOMER_AB->Value=LookFIO->KeyValue;
        DM->QResult_ExamN_PREDMET->Value=LookPred->KeyValue;

       // DM->QResult_ExamNOM_BALL->Value=DM->QShkalaINC_SHKALA->Value;
       // DM->QResult_ExamBALL->Value=DM->QShkalaBALL->Value;

        if (nom_fac==4) DM->QResult_ExamNOM_BALL->Value=13;//стобалка
        else
          {
            // AnsiString z=FloatToStrF(,ffFixed,5,0);
            // DM->QResult_ExamNOM_BALL->Value=z.ToInt()+1;

          }

//        DM->QResult_ExamBALL->Value=ozenka;



       //статус полученной оценки 0 - для оценки за экзамен
       //                         1 - для централизованного тестирования
        DM->QResult_ExamSTATUS_BALL->Value=1;
        try
                { //try
                DM->QResult_Exam->ApplyUpdates();
                DM->QResult_Exam->CommitUpdates();
                ShowMessage("Сохранение результатов прошло успешно!");

                DM->QResult_Exam->Close();
                DM->QSertificat_Res->Close();

                //----------- Enabled
                 LookPred->KeyValue=-1;
                 LookFIO->KeyValue=-1;
                 LookPred->Enabled=false;
                 LookFIO->Enabled=false;
                 Button2->Enabled=false;
                 //----------Visible
                 Label4->Visible=false;
                 Label5->Visible=false;
                 Label6->Visible=false;
                 Label7->Visible=false;
                 Label8->Visible=false;
                 Label9->Visible=false;
                 Label10->Visible=false;
                 Label11->Visible=false;
                 BitBtn1->Visible=false;


               
                }//end try
        catch(...)
                { //catch
                DM->QResult_Exam->CancelUpdates();
                ShowMessage("Произошел сбой при сохранении, попробуйте еще раз!");
                } //end catch
        DM->QResult_Exam->Close();
        } //end else

}
//---------------------------------------------------------------------------
void __fastcall TSertificat_ResultForm::Edit1Change(TObject *Sender)
{
   DM->QResult_Exam->Close();
   DM->QSertificat_Res->Close();

//----------- Enabled
 LookPred->KeyValue=-1;
 LookFIO->KeyValue=-1;
 LookPred->Enabled=false;
 LookFIO->Enabled=false;
 Button2->Enabled=false;
 //----------Visible
 Label4->Visible=false;
 Label5->Visible=false;
 Label6->Visible=false;
 Label7->Visible=false;
 Label8->Visible=false;
 Label9->Visible=false;
 Label10->Visible=false;
 Label11->Visible=false;
 BitBtn1->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TSertificat_ResultForm::LookFIOCloseUp(TObject *Sender)
{
//----------Visible
 Label4->Visible=false;
 Label5->Visible=false;
 Label6->Visible=false;
 Label7->Visible=false;
 Label8->Visible=false;
 Label9->Visible=false;
 Label10->Visible=false;
 Label11->Visible=false;
 BitBtn1->Visible=false;
}
//---------------------------------------------------------------------------
