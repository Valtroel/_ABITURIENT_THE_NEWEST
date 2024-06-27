//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "Func.h"
#include "DMStatUnit.h"
#include "DMUnit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDMStat *DMStat;
//---------------------------------------------------------------------------
__fastcall TDMStat::TDMStat(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMStat::SQL_Run(TFDQuery *q, AnsiString sql, int vid_educ, int stb, int str)
{//��������� Query � ������� ������ � Excel
q->Close();
q->SQL->Clear();
q->SQL->Add(sql);
q->ParamByName("EDU")->AsInteger=vid_educ;
q->Open();
if (q->RecordCount) CellValue(q->Fields->FieldByName("COUNT")->Value,stb,str);
}
//---------------------------------------------------------------------------
void __fastcall TDMStat::SQL_RunCycle(TFDQuery *q, AnsiString sql, int vid_educ, int rec_spec, int stb)
{//��������� Query � ������� ������ � Excel
q->Close();
q->SQL->Clear();
q->SQL->Add(sql);
q->ParamByName("EDU")->AsInteger=vid_educ;
q->Open();
for (int j=0;j<q->RecordCount;j++)
  {
     CellValue(q->Fields->FieldByName("COUNT")->Value,stb,MainForm->Find_nom_spec_str(q->Fields->FieldByName("N_SPEC")->Value,rec_spec));
     q->Next();
  }
}
//----------------------------------------------------------------------------
void __fastcall TDMStat::SQL_Build(int form, int vid, int param)
{//������� Query

//��� ����� 1 �� ���� ��������� ��������� ��� ��������� (param=1)
//��� ����� 2 �� ���� ��������� ���������� ����������� (param=0)

if ((form==2 && !param) || (form==1 && param==1))  return;


AnsiString sql_t="SELECT COUNT(distinct(NOMER_AB)) FROM  ABITURA \
   WHERE (VID_EDU = :EDU) AND  (N_SPEC <> 1) AND (STATUS in"; //��� SQL

int stb, str;
AnsiString status="";//������ �����������

if (param<=11)
{
        str=9;
        if (form==3) stb=param+2;
        if (form==2) stb=param+1;
        if (form==1) {if (!param) stb=2; else stb=param+1;}
}
else  { /*str=8;*/ /*��� �������� �� str=9*/   str=9;    stb=param-10;     }

if (form==1) status=" (0,2,3,4,5)) ";  //�������� ���������
else status=" (5)) ";  //�����������

sql_t+=status;

if (form==3) sql_t+="AND (N_FOUND not in (2,14,15)) ";

//��� param=0  �� switch �� �������  QCount_special_ab - ���������� ������������ �������� ��������� � �����������

switch (param)
   {
      case 1: //��������� ��� ���������
              if (form!=1)  sql_t+="AND ((N_FOUND=8) or (N_FOUND=13))";

         break;

      case 2: case 3:  case 4:
      //QCount_Olimp - Wo=1   ����������  ������������� � ��������������� ��������
      //QCount_Olimp - Wo=2   ���������� � ������� ����������� ���� � ������, ��������� ����������� ���
      //QCount_Olimp -  Wo=3  �������� ������ ���������� ��
                sql_t+="AND (WITHOUT containing '"+AnsiString(param-1)+"') ";
                if (form!=1) sql_t+="AND ((N_FOUND=8) or (N_FOUND=13))";
         break;
      case 5:  //�������: ��� ��������
               if (form==1) sql_t+="AND (KONKURS=4 OR (KONKURS=3 and V_K containing '4'))";
               else         sql_t+="AND ((N_FOUND=7) or (N_FOUND=12))";
         break;
      case 6:  /*//��� �������� ������ ��� ���� ������
               if (form==1) sql_t+="AND ((V_K containing '1') or (PRIV CONTAINING '.1.'))";
               else         sql_t+="AND ((N_FOUND=7) or (N_FOUND=12)) AND (V_K containing '1')";
               */
               //������ � 2008 ���� ���������� ������ ��, ��� ���� ��� ��������
               if (form==1) sql_t+="AND (V_K containing '1')";
               else         sql_t+="AND ((N_FOUND=7) or (N_FOUND=12)) AND (V_K containing '1')";
         break;
      case 7: /* //��� �������� ��������    ��� ���� ������
               if (form==1) sql_t+="AND ((V_K containing '2') or (PRIV CONTAINING '.2.'))";
               else         sql_t+="AND ((N_FOUND=7) or (N_FOUND=12)) AND (V_K containing '2')";
               */
               //�������� � 2008 ���� �� ���� ��� ��������
               sql_t+="AND (PRIV CONTAINING '.2.')";
         break;
      case 8:  //����
               sql_t+="AND ((PRIV CONTAINING '.5.') or (PRIV CONTAINING '.7.'))";

         break;
      case 9:  //���������-���������
               sql_t+="AND ((PRIV CONTAINING '.8.') or (PRIV CONTAINING '.11.'))";

         break;
      case 10:  //������� � �������� - ������ ��� ���� � ���
               sql_t+="AND ((PRIV CONTAINING '.9.') or (PRIV CONTAINING '.10.'))";

         break;
      case 11:  //��  (���� ������ 15, ������ ���� ������ ���������������� ��������� ������� ����� ��� 18-��� ����� � 20-��� ��.�����)
               sql_t+="AND (PRIV CONTAINING '.12.')";

         break;

////////////////////////////////////
      case 12:  //���������� ��������� ���������� ����������� - ����
               sql_t+="AND (STAT_AB CONTAINING '5') AND (STAT_AB CONTAINING '3' or STAT_AB CONTAINING '6') \
                       AND (when_edu_middle like '%' or when_edu_spec like '%')";

         break;

      case 13:  //���������� ��������� ���������� ����������� - ������ �������� ����
               sql_t+="AND (STAT_AB CONTAINING '5') AND (STAT_AB CONTAINING '3' or STAT_AB CONTAINING '6') \
					   AND (when_edu_middle like '2022' or when_edu_spec like '2022')";

         break;
      case 14:  //���������� �������� ���������� ����������� - ����
               sql_t+="AND (STAT_AB CONTAINING '4') AND (STAT_AB CONTAINING '3' or STAT_AB CONTAINING '6') \
                       AND (when_edu_middle like '%' or when_edu_spec like '%')";

         break;
      case 15:  //���������� �������� ���������� ����������� - ������ �������� ����
               sql_t+="AND (STAT_AB CONTAINING '4') AND (STAT_AB CONTAINING '3' or STAT_AB CONTAINING '6') \
					   AND (when_edu_middle like '2022' or when_edu_spec like '2022')";

         break;
      case 17:  //���������� ���� - ����
               sql_t+="AND (STAT_AB CONTAINING '7') \
                       AND (when_edu_middle like '%' or when_edu_spec like '%')";

         break;
      case 18:  //���������� ���� - ������ �������� ����
               sql_t+="AND (STAT_AB CONTAINING '7') \
					   AND (when_edu_middle like '2022' or when_edu_spec like '2022')";

         break;
      case 19:  //���������� ��� - ����
               sql_t+="AND (STAT_AB CONTAINING '9') \
                       AND (when_edu_middle like '%' or when_edu_spec like '%')";

         break;
      case 20:  //���������� ��� - ������ �������� ����
               sql_t+="AND (STAT_AB CONTAINING '9') \
					   AND (when_edu_middle like '2022' or when_edu_spec like '2022')";

         break;

      case 21:  //���������� ����� - ����
               sql_t+="AND (STAT_AB CONTAINING '8') \
                       AND (when_edu_middle like '%' or when_edu_spec like '%')";

         break;

      case 16:  // ����������� �����, ��������
               sql_t+="AND (STAT_AB CONTAINING '3') \
                       AND (when_edu_middle like '%' or when_edu_spec like '%')";

         break;

      case 22:  //����������� ��������
               sql_t+="AND (GRAGDAN<>'��') AND (N_REGION=8)";

         break;

      case 23:  //�������� ��, ����������, ����������, ������������
               sql_t+="AND (GRAGDAN<>'��') AND (N_CENTRE in (122,123,124,125,262))";

         break;
   }

SQL_Run(DMStat->QCountAll, sql_t, vid, stb, str);

}
//----------------------------------------------------------------------------
void __fastcall TDMStat::SQL_BuildCycle(int form, int vid, int rec_spec, int param)
{//������� Query
//��� ����� 1 �� ���� ��������� (param=11,12,13)
if (form==1 && param>10) return;

AnsiString sql_t="SELECT a.N_SPEC, COUNT(distinct(a.NOMER_AB)) FROM  ABITURA a \
   WHERE (a.VID_EDU = :EDU) AND  (a.N_SPEC <> 1) AND (a.STATUS in"; //��� SQL

int stb;
AnsiString status="";//������ �����������
if (form==1) status=" (0,2,3,4,5)) ";  //�������� ���������
else status=" (5)) ";  //�����������

sql_t+=status;

//stb=param+2;

switch (param)
   {
      case 1:   //�����2
                if (form==2) {sql_t="SELECT a.N_SPEC, COUNT(distinct(a.NOMER_AB)) FROM  ABITURA a \
                        WHERE (a.VID_EDU = :EDU) AND (a.N_SPEC <> 1)  AND  ((KONKURS <> 5) or (KONKURS=3 and WITHOUT<>'' )) \
                        AND (a.STATUS in (0,2,4,5)) \
                        and  not exists(SELECT  s.nomer_ab  \
                                   FROM  sertificat s   \
                                   where s.nomer_ab=A.NOMER_AB \
                                   group by s.nomer_ab  \
                                   having count(s.n_predmet)=3) \
                        and  exists(SELECT distinct e.nomer_ab  \
                                   FROM  examen e   \
                                   where e.nomer_ab=A.NOMER_AB   \
                                   and (e.status_ball=0)  \
                                   group by e.nomer_ab)";
                        stb=3;}
         break;
      case 2:   //�����2  ����������� ������������� ���������
                if (form==2) {sql_t="SELECT a.N_SPEC, COUNT(distinct(a.NOMER_AB)) FROM  ABITURA a \
                        WHERE (a.VID_EDU = :EDU) AND (a.N_SPEC <> 1)  AND  ((KONKURS <> 5) or (KONKURS=3 and WITHOUT<>'' )) \
                        AND (a.STATUS in (0,5)) \
                           and  not exists(SELECT  s.nomer_ab  \
                                      FROM  sertificat s   \
                                      where s.nomer_ab=A.NOMER_AB   \
                                      group by s.nomer_ab  \
                                      having count(s.n_predmet)=3)  \
                           and  exists(SELECT distinct e.nomer_ab  \
                                      FROM  examen e   \
                                      where e.nomer_ab=A.NOMER_AB  \
                                      and (e.status_ball=0) \
                                      group by e.nomer_ab)";
                           stb=4;}
         break;
      case 3:   //�����2 ��� �����������
                if (form==2) {
                               sql_t+="";
                               stb=5;
                              }
         break;
      case 4:   //�����2 ��������� �� ������������ ����������������� ������������ (3 �����)
                if (form==2) { sql_t+="AND exists(SELECT  s.nomer_ab  \
                        FROM  sertificat s  where s.nomer_ab=a.NOMER_AB  group by s.nomer_ab \
                        having count(s.n_predmet)=3)";
                        stb=6;}
         break;
      case 5:   //�����2  ��������� ��� ���������
                if (form==2) { sql_t+="AND ((a.N_FOUND=8) or (a.N_FOUND=13))";
                               stb=7;}
         break;
      case 6:   //�����1 ������ ��������� ����� �� ������
                if (form==1) { sql_t+="AND (a.PRICE=0 or a.PRICE is null)";
                               stb=9;}
                //�����2  ��������� �� ������ �����
                else         { sql_t+="AND (a.N_FOUND not in (2,14,15) and a.PRICE=0) ";
                               stb=8;}
         break;
      case 7:   //�����1 �������
                if (form==1) { sql_t+="AND (a.KONKURS=2) AND (a.PRICE=0)";
                               stb=10;}
                //�����2  ������� ������������� - ������ ���
                else         { sql_t="";
                               stb=9;}
         break;
      case 8:   //�����1 �� ����������� ���� �������� (2 ���� - ����, 3 ���� - ����������)  �� ���� ������� �������
                if (form==1) { sql_t+="AND (a.KONKURS=3) AND (a.PRICE=0)";
                               stb=11;}
                //�����2  �� ���� ������� ������� �� - ������ ���
                else         { sql_t="";
                               stb=10;}
         break;
      case 9:   //�����1 ������ ��������� ����� �� �������� ������
                if (form==1) { sql_t+="AND (a.PRICE=1)";
                               stb=13;}
                //�����2  ��������� �� �������� ��������
                else         { sql_t+="AND (a.N_FOUND=1)";
                               stb=11;}
         break;
      case 10:  //�����1 ����������� ����������������� ������������ (3 �����)
                if (form==1) { sql_t+="AND exists(SELECT  s.nomer_ab  \
                        FROM  sertificat s  where s.nomer_ab=a.NOMER_AB  group by s.nomer_ab \
                        having count(s.n_predmet)=3)";
                        stb=14;}
                //�����2 ��������� �� ����������� ���� �������� (2 ���� - ����, 3 ���� - ����������)  �� ���� ������� �������
                else    { sql_t+="AND (a.N_FOUND in (3, 10, 12, 13)) AND (a.PRICE=0) ";
                          stb=12;}
         break;
      case 11:  //�����2 ��������� �� �������� ������
                sql_t+="AND (a.N_FOUND in (2, 14,15,7,8,12,13,16,18,19,20)) AND (a.PRICE=1) ";
                stb=14;
         break;
      case 12:  //�����2 ��������� �� ����������� ���� �������� (2 ���� - ����, 3 ���� - ����������)  �� �������� ������
                sql_t+="AND (a.N_FOUND in (12,13,14,15,18,19,20)) AND (a.PRICE=1)";
                stb=15;
         break;
      case 13:   //�����2 ��������� ��� ��������� ������� ������� �����������
                sql_t+="AND ((WITHOUT containing '5') or (V_K containing '5')) AND (a.PRICE=1) ";
                stb=16;
         break;

   }



sql_t+=" GROUP BY a.N_SPEC";

if (sql_t!=" GROUP BY a.N_SPEC") SQL_RunCycle(DMStat->QCountAll, sql_t, vid, rec_spec, stb);

}
//------------------------------------------------------------------------------
float TDMStat::SQL_Min_Ball(int vid_educ, int sp, int price, int konkurs)
{//������ ��������� ����
float ball;

DMStat->QBall_prohod->Close();
DMStat->QBall_prohod->ParamByName("v")->AsSmallInt=vid_educ;
DMStat->QBall_prohod->ParamByName("sp")->AsInteger=sp;

DMStat->QBall_prohod->ParamByName("pr")->AsSmallInt=price;
DMStat->QBall_prohod->ParamByName("k")->AsSmallInt=konkurs;
DMStat->QBall_prohod->Open();

ball=DMStat->QBall_prohodMIN->Value;

//���������� �� n ������ ����� �������
int n=2;
if (ball>0) ball=floor(ball*pow10(n)+0.5)*pow10(-n);

return  ball;

}
//------------------------------------------------------------------------------
void __fastcall TDMStat::Prohod_Ball(float gorod, float selo, int stroka, int price_twokurs)
{//���������� ����� ���� ������� (����� ��� ���������� �������)

//int price_twokurs ��� ������� �������  - 3;  ��� ������ ������� - 5; ��� 2 ����� - 7 (�� ������� ������ ������� � Excel)
if (price_twokurs!=7)
{ //if �� 2 ����
      if (gorod && selo)
        {//if ���� ��� ��������
           if (selo>gorod)
              {//if ���� ����� ����� ������ - ����� �������
                 CellValue(gorod,price_twokurs,stroka);
                 CellValue(gorod,price_twokurs+1,stroka);
              }
           else
              {//else ���� ����� ���� ������ - ���������� �������
                 CellValue(gorod,price_twokurs,stroka);
                 CellValue(selo,price_twokurs+1,stroka);
              }
        }//end if ���� ��� ��������
      else
        {
           if (gorod && !selo) { CellValue(gorod,price_twokurs,stroka);  CellValue("�",price_twokurs+1,stroka);  }

           if (!gorod && selo) { CellValue("�",price_twokurs,stroka);  CellValue(selo,price_twokurs+1,stroka);  }

           if (!gorod && !selo) { CellValue("�",price_twokurs,stroka);  CellValue("�",price_twokurs+1,stroka);  }
        }
} //end if �� 2 ����
else
{//��� 2 �����
    if (gorod) CellValue(gorod,price_twokurs,stroka);
    else       CellValue("�",price_twokurs,stroka);

    if (selo)  CellValue(selo,price_twokurs+1,stroka);
    else       CellValue("�",price_twokurs+1,stroka);
}

}
//------------------------------------------------------------------------------
void __fastcall TDMStat::FIO(AnsiString text, TFDQuery* q, AnsiString pole)
{ //��������� ��� � ����������� ��� � ������ ������
//AnsiString text - ���� �����
//TQuery *q -  Query �� �������� ����� ����������
//AnsiString pole - ���� � Query ������� ���� ���������
text=text.Trim();
AnsiString t1=text.SubString(1,1);
AnsiString t2=text.SubString(2,text.Length()-1);
t1.Trim();
t2.Trim();
t1=t1.UpperCase();
t2=t2.LowerCase();
q->Fields->FieldByName(pole)->Value=t1+t2;
}
//---------------------------------------------------------------------------

