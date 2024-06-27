#pragma once
#ifndef MAIN_UNIT_H
#define MAIN_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
//#include "RXCtrls.hpp"
#include <StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>


#include "enums.hpp"
#include "properties.hpp"
#include "Ncrb011TemporaryConverter.h"


#define USE_NEW_HANDLERS
//#define TESTING_MAIN_UNIT


class TMainForm
    : public TForm
{
__published:
    TDBGrid      * DBGrid1;

    TLabel       * Label1;       // ��������� ����� ����:
    TLabel       * Label2;       // �������, ������, ������:
    TLabel       * Label3;       // �������, ������, �� ������:
    TLabel       * Label4;       // �������, �����������, ������:
    TLabel       * Label5;       // �������, �����������, �� ������:
    TLabel       * Label6;       // �������, ������, ������:
    TLabel       * Label7;       // �������, ������, �� ������:
    TLabel       * Label8;       // �������, �����������, ������:
    TLabel       * Label9;       // �������, �����������, �� ������:
    TLabel       * NumDelaLbl1;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl2;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl3;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl4;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl5;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl6;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl7;  // get values from AbiturForm -> max_nom_dela()
    TLabel       * NumDelaLbl8;  // get values from AbiturForm -> max_nom_dela()

    TMainMenu    * MainMenu1;

    TMenuItem    * N1;           // ������ ������ �����: "����������"
    TMenuItem    * N2;           // ������ ������ �����: "������" {N2} (�������� �������)
    TMenuItem    * N3;           // ������ ������ �����: "��������" {N3} (�������� �������)
    TMenuItem    * N4;           // ������ ������ �����: "��������" {N3} -> ��������� �� ������ (�������� �����: ExamenForm)
    TMenuItem    * N5;           // ������ ������ �����: "��������" {N3} -> ���������� (�������� �����: Result_ExamForm)
    TMenuItem    * N6;           // ������ ������ �����: "��������" {N3} -> ��������� (�������� �����: ApellForm)
    TMenuItem    * N7;           // ������ ������ �����: "����������" {N7} (�������� �������)
    TMenuItem    * N8;           // ������ ������ �����: "����������" {N8} (�������� �������)
    TMenuItem    * N9;           // "����������" {N7} -> ����
    TMenuItem    * N10;          // "����������" {N8} -> ������� ��������� ������� (������) [INVISIBLE]
    TMenuItem    * N11;          // "���������" {N11} (�������� �������)
    TMenuItem    * N12;          // ����� �������: "�����"
    TMenuItem    * N13;          // ������ {N2}     -> ������� ������ �����
    TMenuItem    * N14;          // ������ {N2}     -> ������ ������ �����
    TMenuItem    * N15;          // ���������� {N7} -> ���-�� �������� ��������� (����������)
    TMenuItem    * N16;          // �������� {N3}   -> �������������� �� �������
    TMenuItem    * N17;          // �������� {N3}   -> ���������� ����������� ���������
    TMenuItem    * N18;          // �������� {N3}   -> --------------------------------
    TMenuItem    * N19;          // �������� {N3}   -> --------------------------------
    TMenuItem    * N20;          // ���������� {N7} -> ������������ ����������� [INVISIBLE]
    TMenuItem    * N21;          // ���������� {N7} -> ������������ ����������� {N20} [INVISIBLE]     -> ����� 2
    TMenuItem    * N22;          // ���������� {N8} -> ������� ��������� ������� (������) [INVISIBLE]
    TMenuItem    * N23;          // ���������� {N8} -> �������������� ���. ������
    TMenuItem    * N24;          // ���������� {N8} -> --------------------------------
    TMenuItem    * N25;          // ���������� {N8} -> --------------------------------
    TMenuItem    * N26;          // ���������� {N8} -> ������� ��������� �� 2 ���� [INVISIBLE]
    TMenuItem    * N27;          // ���������� {N8} -> ������� ��������� ������� (������) [INVISIBLE]
    TMenuItem    * N28;          // ���������� {N7} -> �������� (����������)
    TMenuItem    * N29;          // ���������� {N7} -> ����� ��� ������
    TMenuItem    * N30;          // ���������� {N7} -> ����� ��� ������ {N29}                         -> �������� � ������ ��������� �� �������� [INVISIBLE]
    TMenuItem    * N31;          // ���������� {N7} -> ������������ ����������� {N20} [INVISIBLE]     -> ����� 3
    TMenuItem    * N32;          // ���������� {N7} -> ����� ��� ������ {N29}                         -> ������ ��������� (��������)
    TMenuItem    * N33;          // �������� {N3}   -> ��������� �� �����������
    TMenuItem    * N34;          // ���������� {N8} -> -------------------------------- [INVISIBLE]
    TMenuItem    * N35;          // ���������� {N8} -> ������ �� ����������
    TMenuItem    * N36;          // ���������� {N7} -> ���������� ������������� ���������
    TMenuItem    * N37;          // ���������� {N7} -> ����� ��� ������ {N29}                         -> ������� ���������� ����������������
    TMenuItem    * N38;          // ���������� {N7} -> ����������� [INVISIBLE]
    TMenuItem    * N39;          // ���������� {N7} -> ����������� {N38} [INVISIBLE]                  -> ���������� � ���� ������
    TMenuItem    * N40;          // ���������� {N7} -> ���������� ��������� [INVISIBLE]
    TMenuItem    * N41;          // ���������� {N8} -> ������� ��������� ������� (������) [INVISIBLE]
    TMenuItem    * N42;          // ������ {N2}     -> ������ �� ������������
    TMenuItem    * N43;          // ���������� {N7} -> ���-�� �������� ��������� �� ������
    TMenuItem    * N44;          // ���������� {N7} -> ����� ��� ������ {N29}                         -> ������ ��������� �� ������������
    TMenuItem    * N45;          // ���������� {N7} -> ���� {N9}                                      -> ����� 1 (�����) {N116}                  -> ������� ����� ��������
    TMenuItem    * N46;          // ���������� {N7} -> ���� {N9}                                      -> ����� 2 (����������) {N210}             -> ������� ����� ��������
    TMenuItem    * N47;          // ���������� {N7} -> ���� {N9}                                      -> ����� 1 (�����) {N116}                  -> ������� ����� ��������
    TMenuItem    * N48;          // ���������� {N7} -> ���� {N9}                                      -> ����� 2 (����������) {N210}             -> ������� ����� ��������
    TMenuItem    * N49;          // �������� {N3}   -> ���������
    TMenuItem    * N52;          // ��������� {N11} -> �����������
    TMenuItem    * N53;          // ��������� {N11} -> ����������� ���� �������
    TMenuItem    * N54;          // �������� {N3}   -> ��������� {N49}                                -> �� �� ���� [INVISIBLE]
    TMenuItem    * N55;          // ���������� {N7} -> ������� [INVISIBLE]
    TMenuItem    * N56;          // ���������� {N8} -> --------------------------------
    TMenuItem    * N57;          // ���������� {N8} -> ������ ��������� � ���������
    TMenuItem    * N58;          // ���������� {N8} -> ������ ��������� � ��������� {N57}             -> ������ {N60}                            -> �������
    TMenuItem    * N59;          // ���������� {N8} -> ������ ��������� � ��������� {N57}             -> ������ {N60}                            -> �������
    TMenuItem    * N60;          // ���������� {N8} -> ������ ��������� � ��������� {N57}             -> ������
    TMenuItem    * N61;          // ���������� {N8} -> ������ ��������� � ��������� {N57}             -> �� ������
    TMenuItem    * N62;          // ���������� {N8} -> ������ ��������� � ��������� {N57}             -> �� ������ {N61}                         -> �������
    TMenuItem    * N63;          // ���������� {N8} -> ������ ��������� � ��������� {N57}             -> �� ������ {N61}                         -> �������
    TMenuItem    * N64;          // ���������� {N7} -> ������ ����������� ����������
    TMenuItem    * N65;          // ���������� {N8} -> ������� ��������� ������ ����
    TMenuItem    * N66;          // ���������� {N8} -> ������� ��������� ������ ���� {N65}            -> ������� ����� ��������
    TMenuItem    * N67;          // ���������� {N8} -> ������� ��������� ������ ���� {N65}            -> ������� ����� ��������
    TMenuItem    * N68;          // ���������� {N8} -> ������� ��������� ������ ���� {N65}            -> ������� ����� �������� {N66}            -> ������
    TMenuItem    * N69;          // ���������� {N8} -> ������� ��������� ������ ���� {N65}            -> ������� ����� �������� {N66}            -> �� ������
    TMenuItem    * N70;          // ���������� {N8} -> ������� ��������� ������ ���� {N65}            -> ������� ����� �������� {N67}            -> ������
    TMenuItem    * N71;          // ���������� {N8} -> ������� ��������� ������ ���� {N65}            -> ������� ����� �������� {N67}            -> �� ������
    TMenuItem    * N72;          // ���������� {N8} -> ������� ��������� ����������� ����
    TMenuItem    * N73;          // ���������� {N8} -> ������� ��������� ����������� ���� {N72}       -> ������� ����� ��������
    TMenuItem    * N74;          // ���������� {N8} -> ������� ��������� ����������� ���� {N72}       -> ������� ����� ��������
    TMenuItem    * N75;          // ���������� {N8} -> ������� ��������� ����������� ���� {N72}       -> ������� ����� �������� {N73}            -> ������
    TMenuItem    * N76;          // ���������� {N8} -> ������� ��������� ����������� ���� {N72}       -> ������� ����� �������� {N73}            -> �� ������
    TMenuItem    * N77;          // ���������� {N8} -> ������� ��������� ����������� ���� {N72}       -> ������� ����� �������� {N74}            -> ������
    TMenuItem    * N78;          // ���������� {N8} -> ������� ��������� ����������� ���� {N72}       -> ������� ����� �������� {N74}            -> �� ������
    TMenuItem    * N79;          // ���������� {N8} -> ������� ��������� 2 �� 2 ���� {N221}           -> ������� ����� ��������
    TMenuItem    * N80;          // ���������� {N8} -> ������� ��������� 2 �� 2 ���� {N221}           -> ������� ����� ��������
    TMenuItem    * N81;          // ���������� {N8} -> ������� ��������� 2 �� 2 ���� {N221}           -> ������� ����� �������� {N79}            -> ������
    TMenuItem    * N82;          // ���������� {N8} -> ������� ��������� 2 �� 2 ���� {N221}           -> ������� ����� �������� {N80}            -> ������
    TMenuItem    * N83;          // ���������� {N8} -> ������� ��������� 2 �� 2 ���� {N221}           -> ������� ����� �������� {N79}            -> �� ������
    TMenuItem    * N84;          // ���������� {N8} -> ������� ��������� 2 �� 2 ���� {N221}           -> ������� ����� �������� {N80}            -> �� ������
    TMenuItem    * N85;          // ���������� {N8} -> ��������� ���� ������� ����
    TMenuItem    * N86;          // ������ {N2}     -> ������ ����� �� ����
    TMenuItem    * N110;         // ���������� {N7} -> ������������ ����������� {N20} [INVISIBLE]     -> ����� 1-� (� ���-�� �������� ���������)
    TMenuItem    * N111;         // ���������� {N7} -> ������������ ����������� {N20} [INVISIBLE]     -> ����� 1-�� (������� � ��������� ����)
    TMenuItem    * N112;         // ���������� {N7} -> ������������ ����������� {N20} [INVISIBLE]     -> ����� 1
    TMenuItem    * N113;         // ���������� {N7} -> ������������ ����������� {N20} [INVISIBLE]     -> ����� 1� (����������� ����������)
    TMenuItem    * N114;         // ���������� {N7} -> ������������ ����������� {N20} [INVISIBLE]     -> ����� 1� (����� �� �������� ���������)
    TMenuItem    * N115;         // ���������� {N7} -> ������������ ����������� {N20} [INVISIBLE]     -> ����� 1�� (����������� ������������� ���������)
    TMenuItem    * N116;         // ���������� {N7} -> ���� {N9}                                      -> ����� 1 (�����)
    TMenuItem    * N210;         // ���������� {N7} -> ���� {N9}                                      -> ����� 2 (����������)
    TMenuItem    * N221;         // ���������� {N8} -> ������� ��������� 2 �� 2 ����
    TMenuItem    * N310;         // ���������� {N7} -> ���� {N9}                                      -> ����� 1-��� ���������� ������� ������ [INVISIBLE]
    TMenuItem    * N311;         // �������� {N3}   -> ��������� {N49}                                -> 4 ����������� ����
    TMenuItem    * N1001;        // �������� {N3}   -> ��������� {N49}                                -> ��� ��� 100         [INVISIBLE]
    TMenuItem    * N150010001;   // �������� {N3}   -> ��������� {N49}                                -> ��� ��� 1500 (1000) [INVISIBLE]

    TShape       * Shape1;

    TSpeedButton * SpeedButton1; // ����� ����������
    TSpeedButton * SpeedButton2; // �������� ��������� ����� ����
    TSpeedButton * SpeedButton3; // ����������� �� ���������
    TSpeedButton * SpeedButton4; // ���������: ����� �� ������ �������� ��������

    void __fastcall FormActivate      (TObject * Sender);
    void __fastcall FormClose         (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCloseQuery    (
            TObject * Sender,
            bool    & CanClose
        );
    void __fastcall FormCreate        (TObject * Sender);
    void __fastcall N1Click           (TObject * Sender);// �������� �����: AbiturForm "����������"
    void __fastcall N4Click           (TObject * Sender);// �������� �����: ExamenForm "������"
    void __fastcall N5Click           (TObject * Sender);// �������� �����: Result_ExamForm "�������� ������ �� ����������� ���������"
    void __fastcall N6Click           (TObject * Sender);// �������� �����: ApellForm "���� - ���������"
    void __fastcall N10Click          (TObject * Sender);// ������� ��������� (������� -> ��������)                                     [INVISIBLE]
    void __fastcall N12Click          (TObject * Sender);// �����
    void __fastcall N13Click          (TObject * Sender);// ���������: ������� ������ ����� �� ����������
    void __fastcall N14Click          (TObject * Sender);// ���������: ������ ������ ����� �� ����������
    void __fastcall N15Click          (TObject * Sender);// ���������: ���������� �� ���-�� �������� ��������� (����������)
    void __fastcall N16Click          (TObject * Sender);// �������� �����: Undo_SpravkaForm
    void __fastcall N17Click          (TObject * Sender);// �������� �����: Dop_ResultForm ���������� ����� ����������� �������� ���
    void __fastcall N21Click          (TObject * Sender);// (CAN'T OPERATE!!!!) ����� 2 (���������� ��������� � ���������� ���������)   [INVISIBLE]
    void __fastcall N22Click          (TObject * Sender);// ������� ��������� (������� -> ������)                                       [INVISIBLE]
    void __fastcall N23Click          (TObject * Sender);// ������������ ����������� ���������
    void __fastcall N26Click          (TObject * Sender);// ���������: ������� ��������� ��� 2 �����                                    [INVISIBLE]
    void __fastcall N27Click          (TObject * Sender);// ���������: ������� ��������� (������ -> ������)                             [INVISIBLE]
    void __fastcall N28Click          (TObject * Sender);// �������� �����: Dlg_ProtokolForm "�������� (����������)"
    void __fastcall N30Click          (TObject * Sender);// ���������: ������ ��������� �� �������� (CAN'T OPERATE!!!!)                 [INVISIBLE]
    void __fastcall N31Click          (TObject * Sender);// ���������: ����� 3 (������� � �������)  (CAN'T OPERATE!!!!)                 [INVISIBLE]
    void __fastcall N32Click          (TObject * Sender);// ���������: ����� ������ ��������� (��������)
    void __fastcall N33Click          (TObject * Sender);// �������� �����: ExamenSpecForm
    void __fastcall N35Click          (TObject * Sender);// �������� �����: Group_FacForm
    void __fastcall N36Click          (TObject * Sender);// �������� �����: Stat_Result_examForm
    void __fastcall N37Click          (TObject * Sender);// ���������: ���������� �� ������ ���������� ����������
    void __fastcall N39Click          (TObject * Sender);// ���������: ���������� � ���� ������ (�����������)                           [INVISIBLE]
    void __fastcall N41Click          (TObject * Sender);// ���������: ������� ��������� ������ ��������                                [INVISIBLE]
    void __fastcall N42Click          (TObject * Sender);// ���������: ������ - �� ������������
    void __fastcall N43Click          (TObject * Sender);// ���������: ����������  ->  ���-�� �������� ��������� �� ������
    void __fastcall N44Click          (TObject * Sender);// ���������: ����� ������ ��������� (��������) �� ������������
    void __fastcall N45Click          (TObject * Sender);// ���������: '����� 1' ������ �� �������
    void __fastcall N46Click          (TObject * Sender);// ���������: '����� 2' ��������� �� �������
    void __fastcall N47Click          (TObject * Sender);// ���������: '����� 1' ������ �� �������
    void __fastcall N48Click          (TObject * Sender);// ���������: '����� 2' ��������� �� �������
    void __fastcall N52Click          (TObject * Sender);// �������� �����: PassDlg
    void __fastcall N53Click          (TObject * Sender);// �������� �����: PassDlg
    void __fastcall N54Click          (TObject * Sender);// �������� �����: ExamenSpecForm "������������ ��������� � �� �� ����"        [INVISIBLE]
    void __fastcall N55Click          (TObject * Sender);// ���������: ���������� - �������
    void __fastcall N58Click          (TObject * Sender);// �������� �����: LetterDualListDlg "������ ��������� � ��������� - ������, �������"
    void __fastcall N59Click          (TObject * Sender);// �������� �����: LetterDualListDlg "������ ��������� � ��������� - ������, �������"
    void __fastcall N62Click          (TObject * Sender);// �������� �����: LetterDualListDlg "������ ��������� � ��������� - ��������, �������"
    void __fastcall N63Click          (TObject * Sender);// �������� �����: LetterDualListDlg "������ ��������� � ��������� - ��������, �������"
    void __fastcall N64Click          (TObject * Sender);// �������� �����: AbiturLogDlg "����� ���� ��� ������������ ������� ����������� ����������"
    void __fastcall N68Click          (TObject * Sender);// ���������: "��������� - ������������� ���������. ������ ����, �������, ������"
    void __fastcall N69Click          (TObject * Sender);// ���������: "��������� - ������������� ���������. ������ ����, �������, ��������"
    void __fastcall N70Click          (TObject * Sender);// ���������: "��������� - ������������� ���������. ������ ����, ������,  ������"
    void __fastcall N71Click          (TObject * Sender);// ���������: "��������� - ������������� ���������. ������ ����, ������,  ��������"
    void __fastcall N75Click          (TObject * Sender);// ���������: "��������� - ������������� ���������. ����������,  �������, ������"
    void __fastcall N76Click          (TObject * Sender);// ���������: "��������� - ������������� ���������. ����������,  �������, ��������"
    void __fastcall N77Click          (TObject * Sender);// ���������: "��������� - ������������� ���������. ����������,  ������,  ������"
    void __fastcall N78Click          (TObject * Sender);// ���������: "��������� - ������������� ���������. ����������,  ������,  ��������"
    void __fastcall N81Click          (TObject * Sender);// ���������: "��������� - ������������� ���������. 2-� ������,  �������, ������"
    void __fastcall N82Click          (TObject * Sender);// ���������: "��������� - ������������� ���������. 2-� ������,  ������,  ������"
    void __fastcall N83Click          (TObject * Sender);// ���������: "��������� - ������������� ���������. 2-� ������,  �������, ��������"
    void __fastcall N84Click          (TObject * Sender);// ���������: "��������� - ������������� ���������. 2-� ������,  ������,  ��������"
    void __fastcall N85Click          (TObject * Sender);// �������� �����: PersonalDocFrm "������ '��������� ������' ������� ����"
    void __fastcall N86Click          (TObject * Sender);// ���������: ������ - ������ �� ����
    void __fastcall N110Click         (TObject * Sender);// ���������: '����� 1-�' ��� ������������ �����������                         [INVISIBLE]
    void __fastcall N112Click         (TObject * Sender);// ���������: ����� - ����� 1                                                  [INVISIBLE]
    void __fastcall N310Click         (TObject * Sender);// ���������: '����� 3' ������� ����� ��������                                 [INVISIBLE]
    void __fastcall N311Click         (TObject * Sender);// ���������: �������� - ��������� (�������)
    void __fastcall SpeedButton1Click (TObject * Sender);// ������: '����� ����������'
    void __fastcall SpeedButton2Click (TObject * Sender);// ������: '�������� ������������ ����� ����
    void __fastcall SpeedButton3Click (TObject * Sender);// ������: '����������� �� ���������'
    void __fastcall SpeedButton4Click (TObject * Sender);// ���������: ����� �� ������ �������� ��������
private:
public:
    __fastcall TMainForm (TComponent * Owner);


    void       __fastcall alignHVCells                       (
            int startColumn,
            int endColumn,
            int row,
            int alignHType,
            int alignVType
        );
    void       __fastcall AllCount_spec                      (                     // ��������� ������ ���������� ������������ �� �������������
            int indexNumber
        );
    void       __fastcall CellValue_Ball                     (                     // ��������� ���� ������ �� �k������� ��� ������ �����������
            int col_pred,
            int nom_stroka
        );
    void       __fastcall Cicle_ball                         (                     // '���� ������' ���������� �� ����� ������
            int edu,
            int konk,
            int price
        );
    void       __fastcall Cicle_ball_konk                    (                     // '���� ������' ���������� �� ��������
            int edu,
            int konk,
            int price
        );
    void       __fastcall Cicle_Report                       (int        edu     );// ��� ������ �� �������� ��������
    void       __fastcall Cicle_Report_special               (int        edu     );// -''- �� ��������������
    void       __fastcall CicleSum                           (                     // ������� ����� �� ������� (�����)
            int n_r,
            int nom_row,
            int st1,
            int st2,
            int index
        );
    bool       __fastcall Clear_mas                          (int        n_ab    );// ����� ������ ����������� � ������� all � ��������� ���� ������
    void       __fastcall Create_mas_all                     (                     // �������� ������� ���� ������������ �� �������
            int n_spec,
            int vid_edu
        );
    void       __fastcall Create_Svod_ved                    (                     // ��������� ������� ��������� ��� ������� �����
            int edu,
            int price
        );
    void       __fastcall Create_Svod_ved_short              (                     // ��������� ������� ��������� ��� ����������� �� ����������� ����
            int edu,
            int price
        );
    void       __fastcall Create_Svod_ved_2VO2K              (                     // ��������� ������� ��������� ��� ����������� �� 2 ���� ��
            int edu,
            int price
        );
    void       __fastcall Data_spisok                        (                     // �������� ������ � ������ ������������
            int col_pred,
            int nom_stroka,
            int j
        );
    void       __fastcall Data_spisok_Pol                    (                     // �������� ������ � ������ ������������ (��������� �� ����)
            int nom_stroka,
            int j
        );
    int        __fastcall Find_nom_spec_str                  (                     // ����� ������� ������ � ������� mas_spec_str �� ������ �������������
            int n_spec,
            int rec_count
        );
    void       __fastcall Forma_Giac                         (                     // ��������� ����
            int form,
            int vid_educ
        );
#ifndef  USE_NEW_HANDLERS
    AnsiString            generateSummaryListByPeriod        (
            const AnsiString & period,
                  int          edu,
                  int          price
        );
    AnsiString            generateSummaryListOfEnrollment (
            const AnsiString & course_number,
            const AnsiString & faculty_name,
                  int          fuculty_number
        );
#else
    AnsiString            getPartOfSheetNameForEducationType (
            const int          eduTypeCode
        );
    AnsiString            getPartOfSheetNameForStudyPeriod   (
            const int          studyPeriod
        );
    AnsiString            getPartOfSheetNameForPayment       (
            const int          payment
        );
    AnsiString            getReportName                      (
            const AnsiString & documentName
        );
    AnsiString            getReportName                      (
            const AnsiString & documentName,
                  bool         isFormatDateUsed
        );
    AnsiString            getReportName                      (
            const AnsiString & facultyName,
            const AnsiString & documentName
        );
    AnsiString            getReportName                      (
            const AnsiString & facultyName,
            const AnsiString & documentName,
            const AnsiString & currentHours
        );
    AnsiString            getReportNameWithCourseNumber      (
            const AnsiString & facultyName,
            const AnsiString & documentName,
            const AnsiString & courseNumber
        );
    AnsiString            getSummaryListNameByPeriod         (
            const AnsiString & period,
                  int          educatinType,
                  int          price
        );
#endif // ! USE_NEW_HANDLERS
    void       __fastcall Itog_podano                     (                     // ������� ������������ �������� �������� �� ���� �������� ��� ���������� ��� ����������  ������ ��������� (��������)
            int edu,
            int n_r,
            int itog
        );
#ifndef USE_NEW_HANDLERS
    void       __fastcall MergeCell                       (
            int col_nom1,
            int col_nom2,
            int row_nom1,
            int row_nom2,
            int align
        );
    void       __fastcall MergeCellCenter                 (
            int col_nom1,
            int col_nom2,
            int row_nom
        );
#else
    void       __fastcall MergeCell                          (
            int startColumn,
            int endColumn,
            int row
        );
    void       __fastcall MergeCell                          (
            int startColumn,
            int endColumn,
            int row,
            int alignHType                                                        // 3 - �� ������
        );
    void       __fastcall MergeCell                          (
            int startColumn,
            int endColumn,
            int startRow,
            int endRow,
            int alignHType                                                        // 3 - �� ������
        );
    void       __fastcall MergeCellCenter                    (
            int startColumn,
            int endColumn,
            int row
        );
    void                  printEnvelope                      (
                  PaymentCode         payment,
                  EducationTypeCode   educationType,
            const AnsiString        & message
        );
#endif // USE_NEW_HANDLERS
    void       __fastcall Priv_Str                           (int        par     );// ������� ������ � ������������
    void       __fastcall Protokol4_J                        (int        pol     );// ���������
    AnsiString            ReturnField                        (AnsiString f       );// ���������� �������� ����
    AnsiString            ReturnField_IT                     (AnsiString f       );// ���������� �������� ����
    void       __fastcall Run_ProcBall                       (                     // ��������� ������� ����� ������
            int fac,
            int ed,
            int konk,
            int price,
            int kolon,
            int stroka_n
        );
    void       __fastcall Shapka_spisok                      (int        col_pred);// ��������� ����� � ������ ������������
    void       __fastcall Shapka_spisok_Pol                  (                     // ��������� ����� ��� ������� ������������
            AnsiString n_gr,
            String     pol
        );
    void       __fastcall Spisok_Pol                         (                     // ������ ������� � ����������� �� ����
            String  pol,
            Variant Workbook
        );
    int        __fastcall Svod_ved                           (                     // ��������� ������� ���������
            int nom_str,
            int konk,
            int vid_edu,
            int rec_pred,
            int price,
            int pr_ved
        );
    void       __fastcall Zachisl_Sertificat                 (                     // ���������: ����� �� ������ �������� ��������
            int  f,
            int  v,
            int  s,
            bool all
        );

    TDateTime AbiturLogDate;                                                       // ������ ���� �������� ������� �����������
};

extern PACKAGE TMainForm * MainForm;

#endif  // MAIN_UNIT_H

