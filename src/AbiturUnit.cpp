// ---------------------------------------------------------------------------

#include <vcl.h>
#include <systdate.h>
#include <jpeg.hpp>
#include <graphics.hpp>
#include <Classes.hpp>
#pragma hdrstop
#include "AbiturUnit.h"
#include "DMUnit.h"
#include "Priv_EnterUnit.h"
#include "ListDlgUnit.h"
#include "Undo_Ab_Unit.h"
#include "MainUnit.h"
#include "SertificatUnit.h"
#include "EducationUnit.h"
#include "SredBalUnit.h"
#include "Undo_Ab_1Unit.h"
#include "DMStatUnit.h"
#include "DMVedUnit.h"
#include "Rep_Sel_Exerc.h"
#include "DUALLISTDOC.h"
#include "AddressUnit.h"
#include "AddressLifeUnit.h"
#include "SplashUnit.h"
// ---------------------------------------------------------------------------
// #pragma package(smart_init)
#pragma resource "*.dfm"
TAbiturForm *AbiturForm;

// для формирования фотографии на личной карточке

TMemoryStream* pms;
Jpeg::TJPEGImage *jp;
// переменная для определения текущего каталога в OpenDialog
bool ForceCurrentDirectory = true;

bool st_ins = false; // переменная для проверки добавления абитуриента

int mas_sel_exerc[3][2]; // массив выбранных контрольных упражнений

AnsiString SQLText = "SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
            ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
            D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
            EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
            N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
            N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
            NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
            NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
            PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
            STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
            VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
            WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, DISABLED, \
            STREET, HOUSE, FLAT, POSTCODE \
            FROM ABITURA WHERE (N_FAC=:N_FAC) AND (STATUS=0) ";

bool mess; // переменная для определения выдачи сообщения
int ChangLog; // запись изменений условий поступления абитуриента в журнал
// -1 - изменения запрещены
// 0 - изменений от декана нет
// 1 - значительные изменения у существующего абитуриента
// 2 - новый абитуриент

int AddAbiturPerm, TookDoc1Perm, TookDoc2Perm, ReInsideFacPerm, RestorListPerm;
// Кнопки 0 - доступна, 1- не доступна
// Добавить нового абитуриента (AddBtBtn)
// Забрал документы до окончания приёма документов (TookDocBtBtn1)
// Забрал документы во время экзаменов (TookDocBtBtn2)
// Переподача документов внутри факультета (ReInsideFacBtBtn)
// Восстановить в списке (RestorlistBtBtn)

struct OldKonkurs // структура для установленных параметров конкурса абитуриента
{
    int FormEduIndex;
    int SpecializDBLookupIndex;
    int CategoryAbIndex;
    int SngFrgIndex;
    int EducatIndex;
    int TermEduIndex;
    int PriceIndex;
    int KonkursIndex;
};

OldKonkurs OldKonkursVal;

bool pan1,
     pan2,
     pan3,
     pan4,
     pan5,
     pan6,
     pan7;


int  region_id,                                                                 // ВЫСОТА разделов после активации
     panH1     = 220,                                                           // Unrolled 'CONDITIONS' Panel  220px
     panH2     = 80,                                                            // Unrolled 'ADDRESS'    Panel   80px
     panH3     = 80,                                                            // Unrolled 'PASSPORT'   Panel   80px
     panH4     = 245,                                                           // Unrolled 'EDUCATION'  Panel  300px
     panH5     = 55,                                                            // Unrolled 'JOB'        Panel   60px
     panH6     = 130,                                                           // Unrolled 'RELATIVES'  Panel  130px
     panH7     = 477;                                                           // Unrolled 'BENEFITS'   Panel  400px

// ---------------------------------------------------------------------------
__fastcall TAbiturForm::TAbiturForm (TComponent * Owner)
    : TForm (Owner)
{
    DM -> QAbitura -> Open ();
}

// ---------------------------------------------------------------------------
/* void __fastcall TAbiturForm::VidKonkurs()
 {//процедура установки конкурса абитуриента
 //функция вызывается если у платников общий конкурс (т.е. oplata_konkurs==0)

 KonkursRdGrp->Enabled=true;

 price = PriceRdGrp->ItemIndex;    //бюджет/за оплату
 //vid_edu = ComboBox1->ItemIndex;    //дневное/заочное
 vid_edu = FormEduCmbBx->Text; //дневное/заочное

 switch (price)
 {
 case 0: //бюджет
 KonkursRdGrp->Items->Strings[0] = "Городской";
 KonkursRdGrp->Controls[1]->Enabled = true;            //село есть (дн и заоч)

 if (vid_edu=="Дневное" & nom_fac!=4)
 KonkursRdGrp->Controls[2]->Enabled = true;            //ЦК дн есть (кроме ИТ)
 else KonkursRdGrp->Controls[2]->Enabled = false;      //ЦК заоч нет

 if (vid_edu=="Дневное" & (nom_fac==1 || nom_fac==2)) //на 2 курс тольок СИиЕ и МВС
 KonkursRdGrp->Controls[3]->Enabled = true;            //2 курс  дн  есть
 else KonkursRdGrp->Controls[3]->Enabled = false;      //2 курс заоч  нет

 KonkursRdGrp->Controls[6]->Enabled = false;           //иностранцы нет
 break;

 case 1: //за оплату
 KonkursRdGrp->Items->Strings[0] = "Общий";
 KonkursRdGrp->Controls[1]->Enabled = false;  //село нет
 KonkursRdGrp->Controls[2]->Enabled = false;  //ЦК нет
 if (nom_fac==1 || nom_fac==2)               //на 2 курс тольок СИиЕ и МВС
 KonkursRdGrp->Controls[3]->Enabled = true;   //2 курс есть
 KonkursRdGrp->Controls[6]->Enabled = true;   //иностранцы есть
 break;
 }

 }//end процедура установки конкурса абитуриента */
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::NameBtn()
{ // процедура назначения имен некоторым кнопкам в зависимости от факультета
    // для Института туризма другие названия
    if (nom_fac != 4) {
        TookDocBtBtn1->Hint = "До 17.07.2019!";
        RestorlistBtBtn->Hint = "До 17.07.2019!";
        TookDocBtBtn2->Hint = "С 18.07.2019!";
        ReInsideFacBtBtn->Hint = "После зачисления!";
    }
    else {
        TookDocBtBtn1->Hint =
            "На БЮДЖЕТ до 17.07.2019!   За ОПЛАТУ до 04.08.2019!";
        RestorlistBtBtn->Hint =
            "На БЮДЖЕТ до 17.07.2019!   За ОПЛАТУ до 04.08.2019!";
        TookDocBtBtn2->Hint =
            "На БЮДЖЕТ с 18.07.2019!   За ОПЛАТУ c 05.08.2019!!"; /* */
        ReInsideFacBtBtn->Hint = "После зачисления!";
    }
} // end процедура назначения имен некоторым кнопкам в зависимости от факультета

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::PressBtn(int press_btn) { // функция выбора
    switch (press_btn) { // switch
        // case 0:
    case 1:
        // показ компонентов
        /* ExitBitBtn->Enabled = true;
         ExitBitBtn->Visible = true; */
        press = 1;

        break;
    case 2:
        // если нажата кнопка Добавить
        /* ExitBitBtn->Enabled = false; // Выход
		 ExitBitBtn->Visible = false; // Выход */
		KonkursCmbBx->Enabled = false; // Конкурс
        /* HMENU MenuHandle = GetSystemMenu(Handle, false);
         if(MenuHandle)
         DeleteMenu(MenuHandle, SC_CLOSE, MF_BYCOMMAND); */
        press = 2;
        break;
    case 3:
        // если нажата кнопка Восстановть в списке
        press = 3;
        break;
    case 4:
        // если нажата кнопка Переподача документов
        press = 4;
        break;
    } // end switch
}

// ----------------------------------------------------------------------------
void __fastcall TAbiturForm::BitBtnShow() {
    /* PoleBlock(); // получение значений полей BLOCK и PEREPODACHA
     if (!st_developer) { // не разработчик
     if (pole_block == 1) {
     if (nom_fac != 4) {
     TookDocBtBtn1->Enabled = false; // кнопка забрал документы
     RestorlistBtBtn->Enabled = false; // кнопка восстановить в списке
     // Ниже - сделано на время переподачи документов
     // BitBtn5->Enabled = true; // кнопка переподача
     // BitBtn7->Enabled = true; // кнопка забрал документы
     // BitBtn8->Enabled = true; // кнопка восстановить в списке
     // BitBtn10->Enabled = false; // забрал вообще
     // Конец вставки для переподачи
     }
     ReInsideFacBtBtn->Enabled = true; // кнопка переподача документов
     TookDocBtBtn2->Enabled = true; // закомментировано для переподачи
     // if (nom_fac == 4) BitBtn10->Enabled = true;   // для переподачи
     // else BitBtn10->Enabled = false;   // для переподачи
     // кнопка забрал документы после окончания приема
     }
     else {
     TookDocBtBtn1->Enabled = true; // кнопка забрал документы
     RestorlistBtBtn->Enabled = true; // кнопка восстановить в списке
     ReInsideFacBtBtn->Enabled = false; // кнопка переподача документов
     TookDocBtBtn2->Enabled = false;
     // кнопка забрал документы после окончания приема
     }
     } // and не разработчик */

    if (!TookDoc1Perm || st_developer)
        TookDocBtBtn1->Enabled = true;
    else
        TookDocBtBtn1->Enabled = false;

    if (!TookDoc2Perm || st_developer)
        TookDocBtBtn2->Enabled = true;
    else
        TookDocBtBtn2->Enabled = false;

    if (!ReInsideFacPerm || st_developer)
        ReInsideFacBtBtn->Enabled = true;
    else
        ReInsideFacBtBtn->Enabled = false;

    if (!RestorListPerm || st_developer)
        RestorlistBtBtn->Enabled = true;
    else
        RestorlistBtBtn->Enabled = false;
}

// ----------------------------------------------------------------------------
void __fastcall TAbiturForm::PoleBlock()                                        // получение значения поля BLOCK
{
    DM->BlockQ->Close();
    DM->BlockQ->ParamByName("fac")->AsInteger = nom_fac;
    DM->BlockQ->Open();

    pole_block = DM->BlockQBLOCK->Value;
    perepodacha = DM->BlockQPEREPODACHA->Value;
}

// ----------------------------------------------------------------------------
void __fastcall TAbiturForm::MsgEdit() { // процедура запрета изменения данных
    PoleBlock();
    // int pr = DM->QAbituraPRICE->Value;

    if (!st_developer & pole_block == 1) {
        ShowMessage("Изменять данные ЗАПРЕЩЕНО! Обратитесь к программисту!");
        ExitBitBtn->SetFocus();

    }
    // else if (!st_developer & pole_block==1 & nom_fac==4 & pr!=0)
    // {}

} // end процедура запрета изменения данных

// ----------------------------------------------------------------------------
void __fastcall TAbiturForm::EnabledTrue()
{ // показ компонентов для изменения данных (зависит от поля в БД)
    /* PriceRdGrp->Enabled=true; //Выбор формы оплаты
     KonkursRdGrp->Enabled=true; //Конкурс
     BitBtn7->Enabled=true;     //кнопка забрал документы
     BitBtn8->Enabled=true;     //кнопка восстановить в списке
     BitBtn5->Enabled=true;    //кнопка переподача документов
     BitBtn10->Enabled=true;   //кнопка забрал документы после окончания приема

     ComboBox2->Enabled=true;   //образование
     //тип учреждения образования
     Ch4->Enabled=true;
     Ch5->Enabled=true;
     //выпускник
     Ch3->Enabled=true;
     Ch6->Enabled=true;
     Ch7->Enabled=true;
     Ch8->Enabled=true;
     Ch9->Enabled=true;

     DBEdit23->Enabled=true; //средний балл
     SpeedButton1->Enabled=true; //расчет среднего балла
     DBGrid3->Enabled=true;      //сертификаты
     //вне конкурса (закладка дополнительные сведения)
     Vk1->Enabled=true;
     Vk2->Enabled=true;
     Vk3->Enabled=true;
     Vk4->Enabled=true;
     Vk5->Enabled=true;
     Vk6->Enabled=true;
     //без экзаменов(закладка дополнительные сведения)
     Wo1->Enabled=true;
     Wo2->Enabled=true;
     Wo3->Enabled=true;
     Wo4->Enabled=true;
     Wo5->Enabled=true; */
} // end показ компонентов для изменения данных по абитуриенту

// ----------------------------------------------------------------------------
void __fastcall TAbiturForm::EnableDate ()
{ // Показ компонентов для разработчика всегда
    // ----
    // раньше определялось по дате
    // получения текущей даты сервера
    // -----------------------------
    // DMVed->QDate->Close();
    // DMVed->QDate->Open();
    // DateServer=DMVed->QDateCAST->Value.DateTimeString(); //получили дату с сервера
    // dateOkonch = "26.07.2010";
    // ----

    // PoleBlock();
    /* DM->BlockQ->Close();
     DM->BlockQ->ParamByName("fac")->AsInteger=nom_fac;
     DM->BlockQ->Open();

     int pole_block = DM->BlockQBLOCK->Value; */

    /* if (!st_developer | !st_asu &  pole_block==1)
     {//if пользователь не разработчик и поле BLOCK=1 в БД
     //if (DateServer==dateOkonch & mess==false)
     if (mess==false)
     {
     ShowMessage("Внимание! С "+DateServer+" внесение основных изменений недоступно!");
     //ShowMessage("Внимание! С сегодняшнего дня внесение основных изменений недоступно!");
     mess=true;
     }

     //запрет ИЗМЕНЕНИЙ!!!
     PriceRdGrp->Enabled=false; //Выбор формы оплаты
     KonkursRdGrp->Enabled=false; //Конкурс

     if (!st_developer | !st_asu & nom_fac!=4)
     {
     BitBtn7->Enabled=false;     //кнопка забрал документы
     BitBtn8->Enabled=false;     //кнопка восстановить в списке
     }



     //if (nom_fac!=4)
     //{
     if (!st_developer | !st_asu)
     {
     BitBtn5->Enabled=true;      //кнопка переподача документов
     BitBtn10->Enabled=true;   //кнопка забрал документы после окончания приема
     }
     //} */
    // -----------

    // if (/*!st_developer */ !st_asu)
    // {//if пользователь не разработчик
    // BitBtn5->Enabled=false;     //кнопка переподача документов
    // BitBtn10->Enabled=false;   //кнопка забрал документы после окончания приема

    // if (pole_block==1)
    // {//if поле BLOCK=1 в БД
    /* if (mess==false)
     {//if mess==false
     //ShowMessage("Внимание! С "+DateServer+" внесение основных изменений недоступно!");
     //ShowMessage("Внимание! С сегодняшнего дня внесение основных изменений недоступно!");
     ShowMessage("Внимание! Внесение основных изменений недоступно!");
     mess=true;
     }//end if mess==false

     if (nom_fac!=4)
     {
     BitBtn7->Enabled=false;     //кнопка забрал документы
     BitBtn8->Enabled=false;     //кнопка восстановить в списке
     }
     else
     {
     BitBtn7->Enabled=true;     //кнопка забрал документы
     BitBtn8->Enabled=true;     //кнопка восстановить в списке
     } */

    // запрет ИЗМЕНЕНИЙ!!!
    /* PriceRdGrp->Enabled=false; //Выбор формы оплаты
     KonkursRdGrp->Enabled=false; //Конкурс
     ComboBox2->Enabled=false;   //образование
     //тип учреждения образования
     Ch4->Enabled=false;
     Ch5->Enabled=false;
     //выпускник
     Ch3->Enabled=false;
     Ch6->Enabled=false;
     Ch7->Enabled=false;
     Ch8->Enabled=false;
     Ch9->Enabled=false;

     Ch3->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Ch4->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Ch5->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Ch6->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Ch7->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Ch8->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Ch9->Font->Style=TFontStyles()<< fsBold << fsUnderline;

     AveragScoreDBEdt->Enabled=false; //средний балл
     SpeedButton1->Enabled=false; //расчет среднего балла
     DBGrid3->Enabled=false;      //сертификаты
     //вне конкурса (закладка дополнительные сведения)
     Vk1->Enabled=false;
     Vk2->Enabled=false;
     Vk3->Enabled=false;
     Vk4->Enabled=false;
     Vk5->Enabled=false;
     Vk6->Enabled=false;

     Vk1->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Vk2->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Vk3->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Vk4->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Vk5->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     Vk6->Font->Style=TFontStyles()<< fsBold << fsUnderline;
     //без экзаменов(закладка дополнительные сведения)
     Wo1->Enabled=false;
     Wo2->Enabled=false;
     Wo3->Enabled=false;
     Wo4->Enabled=false;
     Wo5->Enabled=false;
     }
     }//end if пользователь не разработчик и block в БД не 1
     else
     {
     EnabledTrue();
     } */
}


AnsiString __fastcall TAbiturForm::Chek_Vid_Edu ()                              // функция для выбора абитуриентов только определенного вида обучения
{
    switch (RadioGroup1->ItemIndex)
    {
        case 2:                                                                 // ВСЕ
            return
                "";

        default:
            return
                " AND (VID_EDU="                    +
                    AnsiString (
                        RadioGroup1 -> ItemIndex
                    )                               +
                ") ";
    }
}
void __fastcall TAbiturForm::max_nom_dela ()                                    // !!! функция, которая возвращает максимальный номер дела
{
    // int temp;                                                                   // хранит максимальный номер дела

    // DM -> QMax_Nom_Dela -> Close ();
    // DM -> QMax_Nom_Dela ->
    //    ParamByName ("N_FAC") -> AsInteger = nom_fac;
    // DM -> QMax_Nom_Dela -> Open ();

    // if (DM -> QMax_Nom_Dela -> RecordCount)                                    // есть ли абитуриенты
    //    temp = DM -> QMax_Nom_DelaMAX -> Value;
    // else                                                                       // нет ни одного
    //    temp = 0;

    // return
    //     temp;                                                                   // возвращаем максимальный номер дела

    int i = 1;

    for ( int v = 0;
              v < 2;
              ++v
        )
    {
        for ( int t = 0;
                  t < 2;
                  ++t
            )
        {
            for (int p = 0;
                     p < 2;
                     ++p
                )
            {
                DM -> MaxNumDelaStrdPrc -> Close ();
                DM -> MaxNumDelaStrdPrc ->
                    ParamByName ("n_fac")    -> AsSmallInt = nom_fac;
                DM -> MaxNumDelaStrdPrc ->
                    ParamByName ("vid_edu")  -> AsSmallInt = v;
                DM -> MaxNumDelaStrdPrc ->
                    ParamByName ("term_edu") -> AsSmallInt = t;
                DM -> MaxNumDelaStrdPrc ->
                    ParamByName ("price")    -> AsSmallInt = p;

                DM -> MaxNumDelaStrdPrc -> Prepare ();
                DM -> MaxNumDelaStrdPrc -> ExecProc ();

                switch (i)
                {
                    case 1:
                            MainForm -> NumDelaLbl1 -> Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 2:
                            MainForm -> NumDelaLbl2 -> Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 3:
                            MainForm -> NumDelaLbl3->Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 4:
                            MainForm -> NumDelaLbl4->Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 5:
                            MainForm -> NumDelaLbl5 -> Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 6:
                            MainForm -> NumDelaLbl6 -> Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 7:
                            MainForm -> NumDelaLbl7 -> Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                    case 8:
                            MainForm -> NumDelaLbl8 -> Caption =
                                DM -> MaxNumDelaStrdPrc ->
                                    ParamByName ("MX_NUM_DELA") -> AsString;
                        break;
                }

                ++i;
            }
        }
    }
}

// ---------------------------------------------------------------------------
/* int __fastcall TAbiturForm::langv_ball(int ind, int fl)
 { // функция, которая возвращает оценку по иностранному языку, в зависимости от  fl
 // ind - передает или балл или ItemIndex
 // fl - 0 возвратит индекс в ComboBox , 1 - возратит балл с учетом оценок в деканате

 int rez; // переменная результата

 if (fl) {
 // if возврат  балла с учетом оценок в деканате (передаем LangRatCmbBx->ItemIndex)
 switch (ind) { // switch  передаем индекс в LangRatCmbBx
 case -1:
 rez = 0; // не выбрали оценку
 break;
 case 10:
 rez = 5; // отл
 break;
 case 11:
 rez = 4; // хор
 break;
 case 12:
 rez = 3; // удовл
 break;
 case 13:
 rez = 7; // не изучал, а в деканате освобожден
 break;
 default:
 rez = 20 - LangRatCmbBx->ItemIndex;
 // возвращает балл для десятибальной системы
 break;
 } // end switch  передаем индекс в LangRatCmbBx
 } // end if возврат  балла с учетом оценок в деканате (передаем LangRatCmbBx->ItemIndex)
 else { // else возврат  индекса в ComboBox (передаем сохраненную оценку)
 switch (ind) { // switch  передаем оценку
 case 0:
 rez = -1; // нет никакой оценки
 break;
 case 5:
 rez = 10; // отл
 break;
 case 4:
 rez = 11; // хор
 break;
 case 3:
 rez = 12; // удовл
 break;
 case 7:
 rez = 13; // не изучал, а в деканате освобожден
 break;
 default:
 rez = 20 - ind; // возвращает индекс для десятибальной системы
 break;
 } // end switch передаем оценку */

// } // end else возврат  индекса в ComboBox (передаем сохраненную оценку)

// return rez;
/* ItemIndex    Ball
 10         0           20
 9          1           19
 8          2           18
 7          3           17
 6          4           16
 5          5           15
 4          6           14
 3          7           13
 2          8           12
 1          9           11
 отл        10          5
 хор        11          4
 удовл      12          3
 не изучал  13          7
 */
// }         */



// void __fastcall ClearCheck (TRxCheckListBox * cList)                            // функция, которая отключает все  Check
// {
//     int i;
//     for (int i =  0;
//              i < cList -> Items -> Count;
//              ++i
//         )
//         cList -> State[i] = cbUnchecked;
// }
void __fastcall TAbiturForm::UncheckCh ()                                       // !!! функция, которая отключает все Check
{
    // Ch3 -> Checked = false;                                                  // школы
    // Ch4 -> Checked = false;
    // Ch5 -> Checked = false;
    // Ch6 -> Checked = false;
    // Ch7 -> Checked = false;
    // Ch8 -> Checked = false;
    // Ch9 -> Checked = false;

    TownVillageCmbBx -> ItemIndex = -1;
    SchoolCmbBx      -> ItemIndex = -1;

    CheckBox1 -> Checked = false;
    Panel5    -> Visible = false;

    ComboBox1        -> ItemIndex = -1;
    ComboBox2        -> ItemIndex = -1;

    DM -> WithoutCntQr -> Close ();                                             // Сброс списка привелегий (БВИ)
    DM -> WithoutCntQr -> Open ();
    int WithoutCnt =
        DM -> WithoutCntQrCOUNT -> Value;
    DM -> WithoutCntQr -> Close ();

    TComboBox * EditlnstanceCB;

    for (int i = 0;
             i < WithoutCnt;
             ++i
        )
    {
        EditlnstanceCB =
            (TComboBox *)
                FindComponent (
                        "WithOutCmboBx"
                    +   IntToStr (
                            i + 1
                        )
                );
        EditlnstanceCB -> ItemIndex = 0;
    }

    DM -> OutCntQr -> Close();                                                  // Сброс списка привелегий (ВК)
    DM -> OutCntQr -> Open();
    int OutCnt =
        DM -> OutCntQrCOUNT -> Value;
    DM -> OutCntQr -> Close ();

    for (int i = 0;
             i < OutCnt;
             ++i
        )
    {
        EditlnstanceCB =
            (TComboBox *)
                FindComponent (
                        "OutCmboBx"
                    +   IntToStr (
                            i + 1
                        )
                );
        EditlnstanceCB->ItemIndex = 0;
    }

    InfChekLstBx ->                                                             // Дополнительная информация
        CheckAll (
            cbUnchecked,
            true,
            true
        );
}
int __fastcall TAbiturForm::NewWo ()                                            // Запись в БД списка привелегий
{
    int ret_val = 0;

    DM -> PrivDelStrdPrc ->                                                     // Удалить все привелегии данного абитуриента
        ParamByName ("NOMER_AB") -> AsInteger =
            DM -> QAbituraNOMER_AB -> AsInteger;

    DM -> PrivDelStrdPrc -> Prepare ();
    DM -> PrivDelStrdPrc -> ExecProc ();

    DM -> WithoutCntQr -> Close ();                                             // Записать новые БВИ через процедуру
    DM -> WithoutCntQr -> Open ();
    int WithoutCnt =
        DM -> WithoutCntQrCOUNT -> Value;
    DM -> WithoutCntQr -> Close ();

    TComboBox * EditlnstanceCB;

    int j = 0;

    for (int i = 1;
             i <= WithoutCnt;
             ++i
        )
    {
        EditlnstanceCB =
            (TComboBox *)
                FindComponent (
                        "WithOutCmboBx"
                    +   IntToStr (i)
                );
        if (EditlnstanceCB -> ItemIndex > 0)
        {
            j = 1;

            DM -> PrivInsStrdPrc ->
                ParamByName ("NOMER_AB") -> AsInteger =
                    DM -> QAbituraNOMER_AB -> AsInteger;
            DM -> PrivInsStrdPrc ->
                ParamByName ("N_PRIV")   -> AsSmallInt = 0;                     // БВИ
            DM -> PrivInsStrdPrc ->
                ParamByName ("SEL_PRIV") -> AsSmallInt = i;
            DM -> PrivInsStrdPrc ->
                ParamByName ("DAT_PRIV") -> AsSmallInt =
                    EditlnstanceCB -> ItemIndex;

            DM -> PrivInsStrdPrc -> Prepare ();
            DM -> PrivInsStrdPrc -> ExecProc ();
        }
    }

    if (    KonkursCmbBx -> ItemIndex == 1
         && j                         == 0
       )
        ret_val = 1;

	if (    (    TermEduCmbBx -> ItemIndex == 1
              || TermEduCmbBx -> ItemIndex == 2
            )
         && (    EducatCmbBx  -> ItemIndex == 2
              || EducatCmbBx  -> ItemIndex == 3
            )
       )
        ret_val = 0;

    if (ret_val)
        return
            1;

    DM -> OutCntQr -> Close ();                                                 // Записать новые ВК через процедуру
    DM -> OutCntQr -> Open ();
    WithoutCnt =
        DM -> OutCntQrCOUNT -> Value;
    DM -> OutCntQr -> Close ();

    j = 0;

    for (int i =  1;
             i <= WithoutCnt;
             ++i
        )
    {
        EditlnstanceCB =
            (TComboBox *)
                FindComponent (
                        "OutCmboBx"
                    +   IntToStr (i)
                );

        if (EditlnstanceCB -> ItemIndex > 0)
        {
            j = 1;

            DM -> PrivInsStrdPrc ->
                ParamByName ("NOMER_AB") -> AsInteger =
                    DM -> QAbituraNOMER_AB -> AsInteger;
            DM -> PrivInsStrdPrc ->
                ParamByName ("N_PRIV")   -> AsSmallInt = 1;                     // ВК
            DM -> PrivInsStrdPrc ->
                ParamByName ("SEL_PRIV") -> AsSmallInt = i;
            DM -> PrivInsStrdPrc ->
                ParamByName ("DAT_PRIV") -> AsSmallInt =
                    EditlnstanceCB -> ItemIndex;

            DM -> PrivInsStrdPrc -> Prepare ();
            DM -> PrivInsStrdPrc -> ExecProc ();
        }
    }
    if (    KonkursCmbBx->ItemIndex == 2
         && j                       == 0
       )
        return
            2;


    DM -> InfCntQr -> Close ();                                                 // Записать новые преимущества через процедуру
    DM -> InfCntQr -> Open ();
    WithoutCnt =
        DM -> InfCntQrCOUNT -> Value;
    DM -> InfCntQr -> Close ();

    for (int i = 0;
             i < WithoutCnt;
             ++i
        )
    {
        if (InfChekLstBx -> Checked[i])
        {
            DM -> PrivInsStrdPrc ->
                ParamByName ("NOMER_AB") -> AsInteger =
                    DM -> QAbituraNOMER_AB -> AsInteger;
            DM -> PrivInsStrdPrc ->
                ParamByName ("N_PRIV")   -> AsSmallInt = 2;                     // другие
            DM -> PrivInsStrdPrc ->
                ParamByName ("SEL_PRIV") -> AsSmallInt = i + 1;
            DM -> PrivInsStrdPrc ->
                ParamByName ("DAT_PRIV") -> AsSmallInt =
                    InfChekLstBx -> Checked[i];

            DM -> PrivInsStrdPrc -> Prepare ();
            DM -> PrivInsStrdPrc -> ExecProc ();
        }
    }

    return
        0;
}
void __fastcall TAbiturForm::RefreshCh ()                                       // функция, которая устанавливает все Check в нужное положение (Считывание дополнительных параметров)
{
    TownVillageCmbBx -> ItemIndex =                                             // Считывание город/село
        DM -> QAbituraTOWN_VILLAGE -> Value;
    // AnsiString Stat_ab = DM -> QAbituraSTAT_AB -> Value;
    SchoolCmbBx      -> ItemIndex =
        DM -> QAbituraTYPE_SCHOOL  -> Value;                                    // Тип школы

    if (DM -> QAbituraDISABLED -> Value > 0)                                    // Инвалидность
    {
        Panel5    -> Visible = true;
        CheckBox1 -> Checked = true;

        if (DM -> QAbituraDISABLED -> Value % 3)
        {
            ComboBox2 -> ItemIndex =
                  DM -> QAbituraDISABLED -> Value
                % 3
                - 1;
            ComboBox1 -> ItemIndex =
                (   DM -> QAbituraDISABLED -> Value
                  - DM -> QAbituraDISABLED -> Value
                  % 3
                ) / 3;
        }
        else
        {
            ComboBox2 -> ItemIndex = 2;
            ComboBox1 -> ItemIndex =
                (   DM -> QAbituraDISABLED -> Value
                  - 3
                ) / 3;
        }
    }
    else
    {
        Panel5    -> Visible = false;
        CheckBox1 -> Checked = false;

        ComboBox1 -> ItemIndex = -1;
        ComboBox2 -> ItemIndex = -1;
    }

    TComboBox * EditlnstanceCB;                                                 // Считывание БВИ

    DM -> PrivQr -> Close ();
    DM -> PrivQr ->
        ParamByName ("nomer_ab") -> AsInteger =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> PrivQr ->
        ParamByName ("n_priv")   -> AsInteger = 0;                              // БВИ
    DM -> PrivQr -> Open ();

    while (!DM -> PrivQr -> Eof)
    {
        EditlnstanceCB =
            (TComboBox *)
                FindComponent (
                        "WithOutCmboBx"
                    +   IntToStr (
                            DM -> PrivQrSEL_PRIV -> Value
                        )
                );
        EditlnstanceCB -> ItemIndex =
            DM -> PrivQrDAT_PRIV -> Value;

        DM -> PrivQr -> Next ();
    }
    DM -> PrivQr -> Close();


    DM -> PrivQr -> Close ();                                                   // Считывание вне конкурса
    DM -> PrivQr ->
        ParamByName ("nomer_ab") -> AsInteger =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> PrivQr ->
        ParamByName ("n_priv")   -> AsInteger = 1;                              // ВК
    DM -> PrivQr -> Open ();

    while (!DM -> PrivQr -> Eof)
    {
        EditlnstanceCB =
            (TComboBox *)
                FindComponent (
                        "OutCmboBx"
                    +   IntToStr (
                            DM -> PrivQrSEL_PRIV -> Value
                        )
                );
        EditlnstanceCB -> ItemIndex =
            DM -> PrivQrDAT_PRIV -> Value;

        DM -> PrivQr->Next();
    }
    DM -> PrivQr -> Close ();


    DM -> PrivQr -> Close();                                                    // преимущества при зачислении
    DM -> PrivQr -> ParamByName ("nomer_ab") -> AsInteger =
        DM -> QAbituraNOMER_AB -> Value;
    DM -> PrivQr -> ParamByName ("n_priv")   -> AsInteger = 2;                  // другие
    DM -> PrivQr -> Open ();

    while (!DM -> PrivQr -> Eof)
    {
        InfChekLstBx -> Checked[DM -> PrivQrSEL_PRIV -> Value - 1] =
            DM -> PrivQrDAT_PRIV -> Value;

        DM -> PrivQr -> Next ();
    }
    DM -> PrivQr -> Close ();
}
void __fastcall TAbiturForm::RefreshControl ()                                  // функция перечитывания данных из базы и установления компонентов в нужное значение
{
    FormEduCmbBx -> Clear ();
    FormEduCmbBx -> Items -> Add ("дневная");
    FormEduCmbBx -> Items -> Add ("заочная");

    // if (!DM -> QAbitura -> RecordCount)                                         // Дмитрий2019
    // {
    //     // FormEduCmbBx -> ItemIndex = -1;

    //     LangRatCmbBx -> ItemIndex = -1;                                         // балл по иностранному языку

    //     return
    //         ShowMessage (
    //             "Для добавления абитуриентов, "        \
    //             "не забудьте нажать кнопку Добавить!"
    //         );
    // }

    UncheckCh ();                                                               // UPDATE (отключение всех Check)
    RefreshCh ();                                                               // UPDATE (перечитывание всех Check)

    FormEduCmbBx -> ItemIndex = DM -> QAbituraVID_EDU -> Value;                 // закрываем изменение значений вида обучения

    if (ChangLog == -1)
        FormEduCmbBx -> Enabled = false;
    else
        FormEduCmbBx -> Enabled = true;

    // OldKonkursVal.FormEduIndex =
    //     FormEduCmbBx -> ItemIndex;

    DM -> QSpecializPlan_Priem -> Close ();                                     // Направление специальности
    DM -> QSpecializPlan_Priem ->
        ParamByName ("VID_EDU") -> AsSmallInt =
            DM -> QAbituraVID_EDU -> Value;
    DM -> QSpecializPlan_Priem ->
        ParamByName ("FAC") -> AsSmallInt = nom_fac;
    DM -> QSpecializPlan_Priem -> Open ();

    if (ChangLog == -1)
        SpecializDBLookupCmbBx->Enabled = false;
    else
        SpecializDBLookupCmbBx->Enabled = true;

    // OldKonkursVal.SpecializDBLookupIndex =
    //     SpecializDBLookupCmbBx -> KeyValue;

    CategoryAbCmbBx -> ItemIndex =                                              // Категория абитуриента
        DM -> QAbituraCATEGORY_AB -> Value;

    if (ChangLog == -1)
        CategoryAbCmbBx -> Enabled = false;
    else
        CategoryAbCmbBx -> Enabled = true;

    // OldKonkursVal.CategoryAbIndex =
    //     SngFrgCmbBx -> ItemIndex;

    SngFrgCmbBx -> ItemIndex =
        DM -> QAbituraCATEGORY_IF -> Value;

    if (ChangLog == -1)
        SngFrgCmbBx -> Enabled = false;
    else
        SngFrgCmbBx -> Enabled = true;

    // OldKonkursVal.SngFrgIndex =
    //     SngFrgCmbBx -> ItemIndex;

    if (CategoryAbCmbBx -> ItemIndex == 0)
    {
        SngFrgLbl   -> Visible = false;
        SngFrgCmbBx -> Visible = false;
    }
    else
    {
        SngFrgLbl   -> Visible = true;
        SngFrgCmbBx -> Visible = true;
    }

    EducatCmbBx -> ItemIndex =                                                  // образование и конкурс
        DM -> QAbituraEDUCATION -> Value;

    if (ChangLog == -1)
        EducatCmbBx -> Enabled = false;
    else
        EducatCmbBx -> Enabled = true;

    OldKonkursVal.EducatIndex =
        EducatCmbBx -> ItemIndex;

	KonkursCmbBx -> ItemIndex =
        DM -> QAbituraKONKURS -> Value;

    if (ChangLog == -1)
		KonkursCmbBx -> Enabled = true;
    else
		KonkursCmbBx -> Enabled = true;

    if (KonkursCmbBx -> ItemIndex == 3)
    {
        CkRegionDBLkpCmbBx -> Visible = true;
        CkRegionDBLkpCmbBx -> Enabled = true;

        Label29 -> Visible = true;
    }

    // OldKonkursVal.KonkursIndex =
    //     KonkursCmbBx -> ItemIndex;

    PriceCmbBx -> ItemIndex =                                                   // Форма оплаты
        DM -> QAbituraPRICE -> Value;

    if (ChangLog == -1)
        PriceCmbBx -> Enabled = false;
    else
        PriceCmbBx -> Enabled = true;

    // OldKonkursVal.PriceIndex =
    //     PriceCmbBx -> ItemIndex;

    if (    DM->QAbituraEDUCATION->Value == 2                                  // срок обучения / курс поступления
         || DM->QAbituraEDUCATION->Value == 3
       )
        TermEduCmbBx -> ItemIndex =
            DM -> QAbituraTERM_EDU -> Value - 3;
    else
        TermEduCmbBx -> ItemIndex =
            DM -> QAbituraTERM_EDU -> Value;

    if (ChangLog == -1)
        TermEduCmbBx -> Enabled = false;
    else
        TermEduCmbBx -> Enabled = true;

    // OldKonkursVal.TermEduIndex =
    //     TermEduCmbBx -> ItemIndex;

    DM -> CountryQr      -> Close ();                                           // Гражданство
    DM -> CountryQr      -> Open ();


    DM -> QPersonalDocum -> Close ();                                           // Документ
    DM -> QPersonalDocum -> Open ();


    NomGroupCmbBx -> Clear ();                                                  // номер группы абитуриента
    NomGroupCmbBx -> Items ->
        Add (
            DM -> QAbituraNOM_GROUP -> Value
        );
    NomGroupCmbBx -> ItemIndex = 0;


    if (KonkursCmbBx -> ItemIndex == 3)                                         // Целевики (читаем QCk)
    {
        Label29            -> Visible = true;
        CkRegionDBLkpCmbBx -> Visible = true;

        DM -> CkRegionQr -> Close ();
        DM -> CkRegionQr -> Open ();
    }
    else
    {
        Label29            -> Visible = false;
        CkRegionDBLkpCmbBx -> Visible = false;
    }


    AdressRegEdt -> Text =                                                      // адрес регистрации
        DM -> QAbituraADDRESS_BEFORE -> Value;
    AdressLifeEdt -> Text =                                                     // адрес проживания
        DM -> QAbituraADDRESS_LIFE -> Value;

    DM -> QAdress -> Close ();
    DM -> QAdress ->
        ParamByName ("ID") -> AsInteger =
            DM -> QAbituraSTREET -> Value;
    DM -> QAdress -> Active = true;


    // if (!DM -> QAbituraSTREET -> IsNull)
    // {
    //     DM -> QDistrict -> Close ();
    //     DM -> QDistrict ->
    //         ParamByName ("REGION") -> AsInteger =
    //             DM -> QAdressN_REGION -> Value;
    //     DM -> QDistrict -> Open ();


    //     DM -> QType_locality -> Close ();
    //     DM -> QType_locality -> Open ();


    //     DM -> QLocality -> Close ();
    //     if (    DistrictDBLkCmbBx      -> KeyValue
    //          && Type_localityDBLkCmbBx -> KeyValue
    //        )
    //     {
    //         DM -> QLocality ->
    //             ParamByName ("DISTRICT") -> AsInteger =
    //                 DM -> QAdressN_DISTRICT ->Value;
    //         DM -> QLocality ->
    //             ParamByName ("N_TYPE")   -> AsInteger =
    //                 DM -> QAdressN_TYPE     -> Value;
    //         DM -> QLocality -> Open ();
    //     }

    //     DM -> QType_street -> Close ();
    //     DM -> QType_street -> Open ();

    //     DM -> QStreet -> Close ();
    //     DM -> QStreet ->
    //         ParamByName ("TYPE_STREET") -> AsInteger =
    //             DM -> QAdressTYPE_STREET -> Value;
    //     DM -> QStreet ->
    //         ParamByName ("ID_LOCALITY") -> AsInteger =
    //             DM -> QAdressLOCAL_ID    ->Value;
    //     DM -> QStreet -> Open ();
    // }

    // DM -> QRegion_Center -> Close();                                         // район
    // DM -> QRegion_Center ->
    //    ParamByName ("REGION") -> AsInteger =
    //        DM -> QAbituraN_REGION -> Value;
    // DM -> QRegion_Center -> Open ();


    // LangRatCmbBx -> ItemIndex =                                              // балл по иностранному языку
    //     langv_ball (
    //         DM -> QAbituraLANGV_BALL -> Value,
    //         0
    //     );


    DM -> QSertificat -> Close ();                                              // сертификаты абитуриента
    DM -> QSertificat ->
        ParamByName ("NOMER") -> AsInteger =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> QSertificat -> Open ();


    DM -> QEducation -> Close ();                                               // образование абитуриента
    DM -> QEducation ->
        ParamByName ("NOMER") -> AsInteger =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> QEducation -> Open ();
    DM -> TEduDoc -> Close ();
    DM -> TEduDoc -> Open ();

    DM -> QFotoSign -> Close ();                                                // фото
    DM -> QFotoSign ->
        ParamByName ("N_AB")  -> AsInteger =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> QFotoSign ->
        ParamByName ("N_FAC") -> AsInteger =
            DM -> QAbituraN_FAC    -> Value;
    DM -> QFotoSign -> Open ();

    Variant photo =
        & (DM -> QFotoSignPHOTO -> Value);

    if (!DM -> QFotoSignPHOTO -> IsNull)
    {
        pms    -> Clear ();

        DM -> QFotoSignPHOTO -> SaveToStream (pms);

        pms    -> Position = 0;
        jp     -> LoadFromStream (pms);
        Image1 -> Picture -> Assign (jp);
    }
    else
    {
        Image1 -> Picture = NULL;

        TMemoryStream    * pms;                                                 // Выводим фото
        Jpeg::TJPEGImage * jp;

        if (!(TBlobField*)DM->FIOSearchQrPHOTO->IsNull)
        {
            pms = new TMemoryStream;
            jp  = new TJPEGImage;

            DM -> FIOSearchQrPHOTO -> SaveToStream (pms);

            pms ->
                Seek (
                    0,
                    0
                );

            Image1 -> Picture -> Graphic = jp;
            Image1 -> Picture -> Graphic -> LoadFromStream (pms);

            Image1 -> Visible = True;

            delete pms;
            delete jp;

            if (    Image1 -> Picture -> Width  == 0
                 || Image1 -> Picture -> Height == 0
               )
                Image1 -> Picture = NULL;
        }
        else
            Image1 -> Picture = NULL;
    }
    // DM -> QAbitura -> Cancel ();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::FormClose(TObject *Sender, TCloseAction &Action)
{ // ЗАКРЫТИЕ ФОРМЫ

    if (DM->QAbitura->State != dsBrowse) { // if  !=dsBrowse
        // int fl=Application->MessageBox("    Сохранить изменения в личной карточке абитуриента?", "", MB_YESNOCANCEL);
        AnsiString ansi_string1 =
            "    Сохранить изменения в личной карточке абитуриента?";
        // наша строка
        wchar_t * UnicodeString1 = new wchar_t[ansi_string1.WideCharBufSize()];
        // массив-получатель
        ansi_string1.WideChar(UnicodeString1, ansi_string1.WideCharBufSize());
        ansi_string1 = ""; // наша строка
        wchar_t * UnicodeString2 = new wchar_t[ansi_string1.WideCharBufSize()];
        // массив-получатель
        ansi_string1.WideChar(UnicodeString2, ansi_string1.WideCharBufSize());
        int fl = Application->MessageBox(UnicodeString1, UnicodeString2,
            MB_YESNOCANCEL);
        delete[]UnicodeString1;
        delete[]UnicodeString2;

        if (fl == 6) { // if fl==6  -yes   Сохраняем данные и закрываем форму
            // добавила Оля проверка если режим добавления нового человека
            // if (st_ins)
            // {
            // BitBtn1Click(this);
            // }//end добавила Оля проверка если режим добавления нового человека *

            SaveBtBtnClick(this); // ???? Протестировать!!!

            DM->QAbitura->ApplyUpdates();
            DM->QAbitura->CommitUpdates();
            delete pms;
            delete jp;
            DM->QLangvich->Close();
            // Action = caFree;
        } // end if fl==6  -yes   Сохраняем данные и закрываем форму
        else if (fl == 7)
        { // if  fl== 7  - no Отменяем изменения и закрываем форму
            DM->QAbitura->CancelUpdates();
            delete pms;
            delete jp;
            DM->QLangvich->Close();
            // Action = caFree;
        } // end if  fl== 7  - no Отменяем изменения и закрываем форму
        else { // else   cancel   - не закрываем форму
            // Action = caNone;
        } // end else   cancel   - не закрываем форму
    } // end if != dsBrowse
    else { // else Browse
        // if(Application->MessageBox("    Закрыть форму по абитуриенту?", "", MB_YESNO) == mrYes)
        AnsiString ansi_string1 = "    Закрыть форму по абитуриенту?";
        // наша строка
        wchar_t * UnicodeString1 = new wchar_t[ansi_string1.WideCharBufSize()];
        // массив-получатель
        ansi_string1.WideChar(UnicodeString1, ansi_string1.WideCharBufSize());
        ansi_string1 = ""; // наша строка
        wchar_t * UnicodeString2 = new wchar_t[ansi_string1.WideCharBufSize()];
        // массив-получатель
        ansi_string1.WideChar(UnicodeString2, ansi_string1.WideCharBufSize());
        /* if (Application->MessageBox(UnicodeString1, UnicodeString2,
         MB_YESNO) == mrYes)
         Action = caFree;
         else
         Action = caNone; */
        delete[]UnicodeString1;
        delete[]UnicodeString2;
    } // end else Browse   */
    // delete pms;
    // delete jp;

    // добавила Оля
    /* if (st_ins)
     {
     Application->MessageBox("Вы находитесь в режиме добавления нового абитуриента! Нажмите кнопку либо Сохранить , либо Отменить ", "", MB_OK);
     Action = caNone;

     } */
}


void __fastcall TAbiturForm::TabSheet1Enter (TObject * Sender)                  // переход на закладку ПОЛНЫЙ СПИСОК
{
    // ExitBitBtn -> Enabled = false;
    // ExitBitBtn -> Visible = false;

    // SaveBtBtn   -> Enabled = false;
    // CancelBtBtn -> Enabled = false;
    // SaveBtBtn   -> Visible = false;
    // CancelBtBtn -> Visible = false;

    AbiturForm->Height = 700;
}

void __fastcall TAbiturForm::TabSheet2Enter (TObject * Sender)                  // переход на закладку  ЛИЧНОЕ ДЕЛО
{
    //ExitBitBtn -> Enabled = true;
    //ExitBitBtn -> Visible = true;

    // SaveBtBtn   -> Enabled = true;
    // CancelBtBtn -> Enabled = true;
    // SaveBtBtn   -> Visible = true;
    // CancelBtBtn -> Visible = true;

    if (DM -> QAbitura -> State != dsInsert)
        RefreshControl ();

    ActionList1 -> State = asNormal;

    if (! st_developer & pole_block == 1)                                       // закрытие конкурсов после приема документов
		KonkursCmbBx -> Enabled = true;

    // EnableDate();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TabSheet3Enter(TObject *Sender)
{ // переход на закладку ДОПОЛНИТЕЛЬНЫЕ СВЕДЕНИЯ
    /* ExitBitBtn->Enabled=true;
     ExitBitBtn->Visible=true; */
    /* SaveBtBtn->Enabled = true;
     CancelBtBtn->Enabled = true;
     SaveBtBtn->Visible = true;
     CancelBtBtn->Visible = true;
     PrintBtBtn->Visible = true; */
    if (DM->QAbitura->State != dsInsert)
        RefreshControl();
    // EnableDate();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TabSheet1Show (TObject * Sender)                   // показ закладки ПОЛНЫЙ СПИСОК
{
    Edit1 -> SetFocus();

    ActionList1 -> State = asSuspended;
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TabSheet3Show (TObject * Sender)                   // показ закладки  ДОПОЛНИТЕЛЬНЫЕ СВЕДЕНИЯ
{
    /* SaveBtBtn->Enabled = true;
     CancelBtBtn->Enabled = true;
     SaveBtBtn->Visible = true;
     CancelBtBtn->Visible = true;
     PrintBtBtn->Visible = true; */
    WorkBeforeDBEdt -> SetFocus();

    ActionList1 -> State = asSuspended;
}


void __fastcall TAbiturForm::ExitBitBtnClick (TObject * Sender)                  // кнопка ВЫХОД
{
    this -> Close ();
}


void __fastcall TAbiturForm::SaveBtBtnClick (TObject * Sender)                  // кнопка   СОХРАНИТЬ
{
    if (DM -> QAbitura -> State != dsBrowse)
    {
        try
        {
            //------------------------------CONDITIONS----------------------------------------//
            #ifdef NEW_CHECKS
            if (    PriceCmbBx   -> ItemIndex == -1                             // Check chapter ENROLLMENT CONDITIONS
                 || KonkursCmbBx -> ItemIndex == -1
               )
            {
                return
                    ShowMessage (
                        "Вы не указали конкурс или форму оплаты!!!"
                    );
            }
            #endif
            if (    PriceCmbBx   -> ItemIndex == -1                             // Check chapter ENROLLMENT CONDITIONS
                 || KonkursCmbBx -> ItemIndex == -1
               )
                return
                    ShowMessage (
                        "Вы не указали конкурс или форму оплаты!!!"
                    );
            //-----------------------------END-CONDITIONS----------------------------------------//


            //-------------------------------ADDRESS----------------------------------------// Check chapter ADDRESS
            //------------------------------END-ADDRESS----------------------------------------//


            //-------------------------------PERSONAL_ID----------------------------------------//
            if (DocumDBLkCmbBx -> Text == "")                                   // Check document type
                return
                    ShowMessage (
                        "Вы не указали документ удостоверяющий личность!!!"
                    );

            AnsiString personal = PersonNumDBEdt -> Text;                       // read PERSONAL NUMBER

            if (    SitizenshipDBLkCmbBx -> KeyValue == 112                     // Check BELARUSSIAN
                 && personal.Length ()               != 14                      // Check length (14 characters)
                 //&& DocumDBLkCmbBx -> Text           != "Биометрический паспорт"
                 && DocumDBLkCmbBx -> KeyValue       != 6                       // Check not a biometric passport
               )
                return
                    ShowMessage (
                        "Личный номер гражданина Республики Беларусь " \
                        "должен содержать 14 символов!"
                    );
            //------------------------------END-PERSONAL_ID----------------------------------------//




           //------------------------------EDUCATION----------------------------------------//
            #ifndef ENROLLMENT_PEOPLE_WITHOUT_CERTIFICATES
            if (    AveragScoreDBEdt -> Text      == ""                         // Проверка средний балл для неиностранцев SngFrgCmbBx
                 && SngFrgCmbBx      -> ItemIndex != 1
               )
                return
                    ShowMessage (
                        "Вы не ввели средний бал аттестата!!!"
                    );
            if (LangvDBLkpCmbBx -> Text == "")                                  // Проверка ИНОСТРАННЫЙ ЯЗЫК
                return
                    ShowMessage (
                        "Добавьте Иностранный язык!"
                    );
            //#else
            //    AveragScoreDBEdt -> Text = "20";
            //    LangvDBLkpCmbBx  -> ItemIndex = 5;    // "Английский"
            #endif
            //-----------------------------END-EDUCATION----------------------------------------//




            //#ifdef NEW_CHECKS
            //if (FormEduCmbBx -> Text == "")                                     // Check EDUCATION TYPE
            //    return
            //        ShowMessage (
            //            "Введите Вид обучения!\n"  \
            //            "Данные не сохранены!"
            //        );
            //#endif
            if (FormEduCmbBx -> Text != "")                                     // Check EDUCATION TYPE (0 - Intramural, 1 - extramural)
            {
                //#ifdef NEW_CHECKS
                //if (SpecializDBLookupCmbBx -> Text == "")                       // Check SPECIALITY
                //    return
                //        ShowMessage (
                //            "Введите Направление специальности!\n"  \
                //            "Данные не сохранены!"
                //        );
                //#endif
                if (SpecializDBLookupCmbBx -> Text != "")                       // направление специальности
                {
                    //#ifdef NEW_CHECKS
                    //if (    CategoryAbCmbBx -> ItemIndex == -1                  // Check GROUP OF NATIONALITY
                    //     && SngFrgCmbBx     -> ItemIndex == -1                  // Check ENROLLMENT TYPE
                    //   )
                    //    return
                    //        ShowMessage (
                    //            "Введите Категорию абитуриента "    \
                    //            "или Условия поступления!\n"        \
                    //            "Данные не сохранены!"
                    //        );
                    //#endif
                    if (    CategoryAbCmbBx -> ItemIndex != -1                  // Check GROUP OF NATIONALITY (0 - RB, 1 - Foreign, 2 - CIS, 3 - LNR)
                         && SngFrgCmbBx     -> ItemIndex != -1                  // Check ENROLLMENT TYPE (0 - as RB, 1 - as Foreign)
                       )
                    {
                        int tmp_s =
                            DM -> QSpecializPlan_PriemN_SPEC_DIR -> Value;
                        //#ifdef NEW_CHECKS
                        //if (    tmp_s                     == 1                                      // Вид спорта и разряд
                        //     && DM -> QAbituraCATEGORY_IF == 0
                        //     || (    tmp_s                                   != 1
                        //          && VidSportDBLookupCmbBx       -> KeyValue == 121
                        //          && VidSportDBLookupCmbBx       -> KeyValue == 33
                        //          && SportCategoryDBLookupCmboBx -> KeyValue == 12
                        //        )
                        //   )
                        //    return
                        //        ShowMessage (
                        //            "Введите Вид спорта и Разряд!\n"    \
                        //            "Данные не сохранены!"
                        //        );
                        //#endif
                        if (    tmp_s                     != 1                        // Вид спорта и разряд
                             && DM -> QAbituraCATEGORY_IF != 0
                             || (    tmp_s                                   == 1
                                  && VidSportDBLookupCmbBx       -> KeyValue != 121
                                  && VidSportDBLookupCmbBx       -> KeyValue != 33
                                  && SportCategoryDBLookupCmboBx -> KeyValue != 12
                                )
                           )
                        {
                            // не тренерская работа или тренерская и разряд
                            //#ifdef NEW_CHECKS
                            //if (SitizenshipDBLkCmbBx -> KeyValue == 0)            // Гражданство
                            //    return
                            //        ShowMessage (
                            //            "Введите Гражданство!\n"    \
                            //            "Данные не сохранены!"
                            //        );
                            //#endif  // NEW_CHECKS
                            if (SitizenshipDBLkCmbBx->KeyValue != 0)            // Гражданство
                            {
                                //#ifdef NEW_CHECKS
                                //if (RegionDBLookupCmbBx -> Text == "")            // Регион
                                //    return
                                //        ShowMessage (
                                //        "Введите Регион!\n" \
                                //        "Данные не сохранены!"
                                //    );
                                //#endif  // NEW_CHECKS
                                if (RegionDBLookupCmbBx -> Text != "")            // Регион
                                {
                                    //#ifdef NEW_CHECKS
                                    //if (NomGroupCmbBx -> Text == "")              // Check GROUP NUMBER
                                    //    return
                                    //        ShowMessage (
                                    //            "Введите Номер группы!\n"   \
                                    //            "Данные не сохранены!"
                                    //        );
                                    //#endif  // NEW_CHECKS
                                    if (NomGroupCmbBx->Text != "")              // номер группы
                                    {
                                        //#ifdef NEW_CHECKS
                                        //if (    FamDBEdt  -> Text == ""           // Check LAST  NAME
                                        //     || NameDBEdt -> Text == ""           // Check FIRST NAME
                                        //   )
                                        //#endif  // NEW_CHECKS
                                        if (    FamDBEdt  -> Text != ""           // Check LAST  NAME
                                             && NameDBEdt -> Text != ""           // Check FIRST NAME
                                           )
                                        {
                                            //#ifdef NEW_CHECKS
                                            //if (PolDBCmbBx -> Text == "")           // Check GENDER
                                            //    return
                                            //        ShowMessage (
                                            //            "Введите Пол или Место рождения!\n"     \
                                            //            "Данные не сохранены!"
                                            //        );
                                            //#endif  // NEW_CHECKS
                                            if (PolDBCmbBx -> Text != "")           // Check GENDER
                                            {
                                                //#ifdef NEW_CHECKS
                                                //if (DM -> QAbituraDATE_R -> IsNull)    // D.O.B not NULL OR more than 01.01.1935 (is: > 12785) AND less than 01.01.1992 (is: < 35065)
                                                //    return
                                                //        ShowMessage (
                                                //            "Введите правильно Дату рождения!\n"    \
                                                //            "Данные не сохранены!"
                                                //        );
                                                //#endif  // NEW_CHECKS
                                                if (!DM -> QAbituraDATE_R -> IsNull)    // D.O.B not NULL OR more than 01.01.1935 (is: > 12785) AND less than 01.01.1992 (is: < 35065)
                                                {
                                                    //#ifdef NEW_CHECKS
                                                    //if (    SngFrgCmbBx -> ItemIndex == -1  // не иностранцы        // if школы
                                                    //     && SchoolCmbBx -> ItemIndex == 1   // и выбрана школа
                                                    //     || SngFrgCmbBx -> ItemIndex != 1   // или иностранцы
                                                    //   )
                                                    //    return
                                                    //       ShowMessage (
                                                    //                "Введите ВЫПУСКНИК!\n"  \
                                                    //                "Данные не сохранены!"
                                                    //            );
                                                    //#endif  // NEW_CHECKS
                                                    if (    SngFrgCmbBx -> ItemIndex != -1  // Check ENROLLMENT TYPE (-1 - enmpty, 0 - as RB, 1 - as Foreign)
                                                         || SngFrgCmbBx -> ItemIndex == 1   // или иностранцы
                                                         && SchoolCmbBx -> ItemIndex != 1   // и выбрана школа
                                                       )
                                                    {
                                                        //#ifdef NEW_CHECKS
                                                        //if (    SngFrgCmbBx      -> ItemIndex == -1 // не иностранцы        // if город/село
                                                        //     && TownVillageCmbBx -> ItemIndex != 0  // и выбран город/село
                                                        //     || SngFrgCmbBx      -> ItemIndex != 1  // или иностранцы
                                                        //   )
                                                        //    return
                                                        //        ShowMessage (
                                                        //            "Введите УЧРЕЖДЕНИЕ ОБРАЗОВАНИЯ!\n" \
                                                        //            "Данные не сохранены!"
                                                        //        );
                                                        //#endif  // NEW_CHECKS
                                                        if (    SngFrgCmbBx      -> ItemIndex != -1 // не иностранцы        // if город/село
                                                             || SngFrgCmbBx      -> ItemIndex == 1  // или иностранцы
                                                             && TownVillageCmbBx -> ItemIndex == 0  // и выбран город/село
                                                           )
                                                        {
                                                            //#ifdef NEW_CHECKS
                                                            //if (EducatCmbBx -> ItemIndex == -1)         // выбрано образование
                                                            //    return
                                                            //        ShowMessage (
                                                            //            "Введите срок получения образования!\n"   \
                                                            //            "Данные не сохранены!"
                                                            //        );
                                                            //#endif  // NEW_CHECKS
                                                            if (EducatCmbBx -> ItemIndex != -1)         // выбрано образование
                                                            {
                                                                //#ifdef NEW_CHECKS
                                                                //if (TermEduCmbBx -> ItemIndex == -1)    // выбран срок получения образования
                                                                //    return
                                                                //        ShowMessage (
                                                                //            "Введите срок получения образования!\n"   \
                                                                //            "Данные не сохранены!"
                                                                //        );
                                                                //#endif  // NEW_CHECKS
                                                                if (TermEduCmbBx -> ItemIndex != -1)    // выбран срок получения образования
                                                                {
                                                                    //#ifdef NEW_CHECKS
                                                                    //if (PriceCmbBx -> ItemIndex == -1)  // выбрана форма оплаты
                                                                    //    ShowMessage (
                                                                    //        "Введите форму оплаты!\n"   \
                                                                    //        "Данные не сохранены!"
                                                                    //    );
                                                                    //#endif  // NEW_CHECKS
                                                                    if (PriceCmbBx -> ItemIndex != -1)  // выбрана форма оплаты
                                                                    {
                                                                        //#ifdef NEW_CHECKS
                                                                        //if (KonkursCmbBx -> ItemIndex == -1)                                        // выбран конкурс
                                                                        //    return
                                                                        //        ShowMessage (
                                                                        //            "Введите конкурс!\n"    \
                                                                        //            "Данные не сохранены!"
                                                                        //        );
                                                                        //#endif  // NEW_CHECKS
                                                                        if (KonkursCmbBx -> ItemIndex != -1)                                        // выбран конкурс
                                                                        {
                                                                            int nom_abit = DM -> QAbituraNOMER_AB -> Value;
                                                                            // if (DM -> QAbitura -> State == dsInsert)
                                                                            if (    ChangLog == 1                                                   // новый абитуриент
                                                                                 || ChangLog == 2                                                   // или изменения конкурса
                                                                               )
                                                                            {
                                                                                DM -> QAbituraSTATUS -> Value = 0;                                  // Номер дела!

                                                                                DM -> MaxNumDelaStrdPrc ->
                                                                                    ParamByName ("n_fac")   -> AsSmallInt =
                                                                                        nom_fac;
                                                                                DM -> MaxNumDelaStrdPrc ->
                                                                                    ParamByName ("vid_edu") -> AsSmallInt =
                                                                                        FormEduCmbBx -> ItemIndex;

                                                                                if (    EducatCmbBx -> ItemIndex == 2
                                                                                     || EducatCmbBx -> ItemIndex == 3
                                                                                   )
                                                                                    DM -> MaxNumDelaStrdPrc ->
                                                                                        ParamByName ("term_edu") -> AsSmallInt =
                                                                                            TermEduCmbBx -> ItemIndex + 3;
                                                                                else
                                                                                    DM -> MaxNumDelaStrdPrc ->
                                                                                        ParamByName ("term_edu") -> AsSmallInt =
                                                                                            TermEduCmbBx -> ItemIndex;

                                                                                DM -> MaxNumDelaStrdPrc ->
                                                                                    ParamByName ("price") -> AsSmallInt =
                                                                                        PriceCmbBx -> ItemIndex;


                                                                                DM -> MaxNumDelaStrdPrc -> Prepare ();
                                                                                DM -> MaxNumDelaStrdPrc -> ExecProc ();


                                                                                if (DM -> MaxNumDelaStrdPrc ->
                                                                                        ParamByName ("MX_NUM_DELA") -> Value > 0
                                                                                   )
                                                                                    DM -> QAbituraNOM_DELA -> Value =
                                                                                        DM -> MaxNumDelaStrdPrc ->
                                                                                            ParamByName ("MX_NUM_DELA") -> Value + 1;
                                                                                else
                                                                                    DM -> QAbituraNOM_DELA -> Value = 1;

                                                                                DM -> QAbituraNOM_GROUP -> Value = NomGroupCmbBx -> Text;
                                                                            }

                                                                            // DM -> QAbituraN_SPEC         -> Value     = DM -> QSpecializN_SPEC                -> Value;
                                                                            DM -> QAbituraN_SPEC         -> Value     = DM -> QSpecializPlan_PriemN_SPEC      -> Value;
                                                                            DM -> QAbituraN_SPECIALIZ    -> Value     = DM -> QSpecializPlan_PriemN_SPECIALIZ -> Value;
                                                                            DM -> QAbituraCITIZENSHIP    -> Value     = DM -> CountryQrDIGITAL_CODE           -> Value;
                                                                            DM -> QAbituraID_TYPE        -> Value     = DM -> QPersonalDocumID_TYPE           -> Value;
                                                                            DM -> QAbituraN_FAC          -> Value     = nom_fac;
                                                                            DM -> QAbituraCATEGORY_AB    -> Value     = CategoryAbCmbBx  -> ItemIndex;
                                                                            DM -> QAbituraCATEGORY_IF    -> Value     = SngFrgCmbBx      -> ItemIndex;
                                                                            DM -> QAbituraVID_EDU        -> Value     = FormEduCmbBx     -> ItemIndex;
                                                                            DM -> QAbituraADDRESS_BEFORE -> Value     = AdressRegEdt     -> Text;       // адрес регистрации
                                                                            DM -> QAbituraADDRESS_LIFE   -> Value     = AdressLifeEdt    -> Text;       // адрес проживания
                                                                            DM -> QAbituraTOWN_VILLAGE   -> AsInteger = TownVillageCmbBx -> ItemIndex;  // город/село
                                                                            DM -> QAbituraTYPE_SCHOOL    -> AsInteger = SchoolCmbBx      -> ItemIndex;  // тип школы
                                                                            DM -> QAbituraEDUCATION      -> Value     = EducatCmbBx      -> ItemIndex;
                                                                            DM -> QAbituraKONKURS        -> Value     = KonkursCmbBx     -> ItemIndex;
                                                                            DM -> QAbituraPRICE          -> Value     = PriceCmbBx->ItemIndex;


                                                                            int disabilityGroup    = ComboBox1 -> ItemIndex + 1;                        // инвалидность
                                                                            int disabilityCategory = ComboBox2 -> ItemIndex + 1;

                                                                            if (    disabilityGroup
                                                                                 || disabilityCategory
                                                                               )
                                                                                DM -> QAbituraDISABLED -> Value =
                                                                                      (disabilityGroup - 1) * 3
                                                                                    + disabilityCategory;
                                                                            else
                                                                                DM -> QAbituraDISABLED -> Value = 0;

                                                                            if (    EducatCmbBx -> ItemIndex == 2
                                                                                 || EducatCmbBx -> ItemIndex == 3
                                                                               )
                                                                                DM -> QAbituraTERM_EDU -> Value = TermEduCmbBx -> ItemIndex + 3;
                                                                            else
                                                                                DM -> QAbituraTERM_EDU -> Value = TermEduCmbBx -> ItemIndex;

                                                                            // #ifndef ENROLLMENT_PEOPLE_WITHOUT_CERTIFICATES
                                                                            // DM -> QAbituraLANGV_BALL -> Value =                                      // сохранение балла по иностранному языку
                                                                            //    langv_ball (
                                                                            //        LangRatCmbBx -> ItemIndex,
                                                                            //        1
                                                                            //    );
                                                                            // #endif


                                                                            if (KonkursCmbBx -> ItemIndex < 3)                  // check none of those who are the TARGETED
                                                                                DM  -> QAbituraN_CK  -> Value = -1;             // set (-1) in N_CK for people who are not a TARGETED

                                                                            int Pr_Priv = NewWo ();

                                                                            if (    Pr_Priv                   == 2              // check the reason for OUT OF CONTEST
                                                                                 && TermEduCmbBx -> ItemIndex != 0
                                                                                 && PriceCmbBx   -> ItemIndex != 1
                                                                                 && (    EducatCmbBx -> ItemIndex == 2
                                                                                      || EducatCmbBx -> ItemIndex == 3
                                                                                    )
                                                                               )
                                                                            {
                                                                                return
                                                                                    ShowMessage (
                                                                                        "Добавьте основание, по "  \
                                                                                        "которому абитуриент "      \
                                                                                        "поступает ВНЕ КОНКУРСА!"   \
                                                                                        "\nДанные не сохранены!"
                                                                                    );
                                                                            }

                                                                            if (Pr_Priv == 1)                                   // check the reason for WITHOUT TEST
                                                                            {
                                                                                return
                                                                                    ShowMessage (
                                                                                        "Добавьте основание, "      \
                                                                                        "по которому абитуриент "   \
                                                                                        "поступает БЕЗ ЭКЗАМЕНОВ!"  \
                                                                                        "\nДанные не сохранены!"
                                                                                    );
                                                                            }


                                                                            try
                                                                            {
                                                                                DM -> QAbitura  -> ApplyUpdates ();
                                                                                DM -> QAbitura  -> CommitUpdates ();

                                                                                DM -> QFotoSign -> Close ();

                                                                                TLocateOptions Flags;

                                                                                DM  -> QAbitura  ->
                                                                                    Locate (
                                                                                        "NOMER_AB",
                                                                                        nom_abit,
                                                                                        Flags
                                                                                    );

                                                                                DM -> QFotoSign -> ParamByName ("N_FAC") -> AsInteger =
                                                                                    DM -> QAbituraN_FAC    -> Value;
                                                                                DM -> QFotoSign -> ParamByName ("N_AB")  -> AsInteger =
                                                                                    DM -> QAbituraNOMER_AB -> Value;
                                                                                DM -> QFotoSign -> Open ();
                                                                                DM -> QFotoSign -> Edit ();

                                                                                pms -> Clear ();

                                                                                jp  -> Assign (Image1 -> Picture);
                                                                                jp  -> SaveToStream (pms);

                                                                                pms -> Position = 0;

                                                                                DM -> QFotoSignPHOTO -> LoadFromStream (pms);

                                                                                DM -> QFotoSign -> ApplyUpdates ();
                                                                                DM -> QFotoSign -> CommitUpdates ();

                                                                                // ChangLog - Запись в журнал.
                                                                                // -1 - изменения запрещены
                                                                                // 0  - изменений от декана нет
                                                                                // 1  - изменения конкурса у существующего абитуриента
                                                                                // 2  - новый абитуриент
                                                                                if (ChangLog < 1)                               // Незначительные изменения
                                                                                {
                                                                                    DM -> LogLastQr -> Close ();                // Адрес вносим в последний лог // Последняя по DATE_IN запись для NOMER_AB

                                                                                    DM -> LogLastQr -> ParamByName ("nomer_ab") -> AsInteger =
                                                                                        DM -> QAbituraNOMER_AB -> AsInteger;
                                                                                    DM -> LogLastQr -> Open ();

                                                                                    if (    !DM -> LogLastQrID_LOG         -> IsNull
                                                                                         || DM  -> FIOSearchQrSTATUS_QUEUE -> Value == 304
                                                                                       )
                                                                                    {
                                                                                        DM -> AdresOutQr -> Close ();
                                                                                        DM -> AdresOutQr -> ParamByName ("id_log")         -> AsInteger =
                                                                                            DM -> LogLastQrID_LOG        -> AsInteger;
                                                                                        DM -> AdresOutQr -> ParamByName ("address_before") -> AsString  =
                                                                                            DM -> QAbituraADDRESS_BEFORE -> Value;
                                                                                        DM -> AdresOutQr -> Prepare ();
                                                                                        DM -> AdresOutQr -> ExecSQL ();
                                                                                        DM -> AdresOutQr -> Close ();
                                                                                    }
                                                                                    else
                                                                                        ShowMessage (
                                                                                            "Записи в журнале для отметки " \
                                                                                            "о возврате документов не "     \
                                                                                            "найдено!"
                                                                                        );

                                                                                    DM -> LogLastQr -> Close ();
                                                                                }

                                                                                if (ChangLog == 1)                                                      // изменения конкурса у существующего абитуриента
                                                                                {
                                                                                    DM -> LogLastQr -> Close ();
                                                                                    DM -> LogLastQr -> ParamByName ("nomer_ab") -> AsInteger =          // get NOMER_AB
                                                                                        DM -> QAbituraNOMER_AB -> AsInteger;
                                                                                    DM -> LogLastQr -> Open ();

                                                                                    if (    !DM -> LogLastQrID_LOG         -> IsNull
                                                                                         || DM  -> FIOSearchQrSTATUS_QUEUE -> Value == 304              // check state
                                                                                       )
                                                                                    {
                                                                                        DM -> UpDateOutQr -> Close ();
                                                                                        DM -> UpDateOutQr -> ParamByName ("id_log")   -> AsInteger  =  // Дата возврата документов DATE_OUT
                                                                                            DM -> LogLastQrID_LOG -> AsInteger;
                                                                                        DM -> UpDateOutQr -> ParamByName ("date_out") -> AsDateTime =  // Последняя по DATE_IN
                                                                                            cur_d.CurrentDateTime ();


                                                                                        DM -> UpDateOutQr -> Prepare ();
                                                                                        DM -> UpDateOutQr -> ExecSQL ();

                                                                                        DM -> UpDateOutQr -> Close ();
                                                                                    }
                                                                                    else
                                                                                        ShowMessage (
                                                                                            "Записи в журнале для отметки "     \
                                                                                            "о возврате документов не найдено!"
                                                                                        );

                                                                                    DM -> LogLastQr -> Close ();
                                                                                }

                                                                                if (    ChangLog == 1                                                   // Изменение конкурса или новый абитуриент
                                                                                     || ChangLog == 2
                                                                                   )
                                                                                {
                                                                                    DM -> AbiturLogInsQr -> Close ();                                                                                  // Вставка новой записи в лог
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("nom_dela")       -> AsSmallInt = DM -> QAbituraNOM_DELA         -> Value;    // Номер личного дела NOM_DELA
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("nomer_ab")       -> AsInteger  = DM -> QAbituraNOMER_AB         -> Value;    // Номер абитуриента NOMER_AB
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("date_in")        -> AsDateTime = cur_d.CurrentDateTime ();                   // Дата приёма - текущая
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("vid_edu")        -> AsSmallInt = DM -> QAbituraVID_EDU          -> Value;    // Форма обучения VID_EDU
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("price")          -> AsSmallInt = DM -> QAbituraPRICE            -> Value;    // Форма оплаты PRICE
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("term_edu")       -> AsSmallInt = DM -> QAbituraTERM_EDU         -> Value;    // Срок обучения TERM_EDU
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("address_before") -> AsString   = DM -> QAbituraADDRESS_BEFORE   -> Value;    // Адрес ADDRESS_BEFORE
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("n_ck")           -> AsSmallInt = DM -> QAbituraN_CK             -> Value;    // Целевая N_CK
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("n_specializ")    -> AsSmallInt = DM -> QAbituraN_SPECIALIZ      -> Value;    // Направление специализации N_SPECIALIZ
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("n_fac")          -> AsSmallInt = nom_fac;
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("konkurs")        -> AsSmallInt = DM -> QAbituraKONKURS          -> Value;
                                                                                    DM -> AbiturLogInsQr -> ParamByName ("category")       -> AsSmallInt = DM -> QAbituraN_SPORT_CATEGORY -> Value;

                                                                                    DM -> AbiturLogInsQr -> Prepare ();
                                                                                    DM -> AbiturLogInsQr -> ExecSQL ();

                                                                                    DM -> AbiturLogInsQr -> Close ();


                                                                                    DM -> StatusQueueQr -> Close ();
                                                                                    DM -> StatusQueueQr -> ParamByName ("fam")          -> AsString   = DM -> QAbituraFAM         -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("name")         -> AsString   = DM -> QAbituraNAME        -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("otch")         -> AsString   = DM -> QAbituraOTCH        -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("status_queue") -> AsSmallInt = 105;                                    // !!!!Статуст в табиле очереди в 105
                                                                                    DM -> StatusQueueQr -> ParamByName ("specializ")    -> AsSmallInt = DM -> QAbituraN_SPECIALIZ -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("n_spec")       -> AsSmallInt = DM -> QAbituraN_SPEC      -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("vid_edu")      -> AsSmallInt = DM -> QAbituraVID_EDU     -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("category_ab")  -> AsSmallInt = DM -> QAbituraCATEGORY_AB -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("category_if")  -> AsSmallInt = DM -> QAbituraCATEGORY_IF -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("category_edu") -> AsSmallInt = DM -> QAbituraEDUCATION   -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("term_edu")     -> AsSmallInt = DM -> QAbituraTERM_EDU    -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("price")        -> AsSmallInt = DM -> QAbituraPRICE       -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("konkurs")      -> AsSmallInt = DM -> QAbituraKONKURS     -> Value;
                                                                                    DM -> StatusQueueQr -> ParamByName ("id_ab")        -> AsInteger  = DM -> ID_from_QUEUE;

                                                                                    DM -> StatusQueueQr -> Prepare ();
                                                                                    DM -> StatusQueueQr -> ExecSQL ();

                                                                                    DM -> StatusQueueQr -> Close ();


                                                                                    DM -> IdAbQueueQr -> Close ();
                                                                                    DM -> IdAbQueueQr -> ParamByName ("id_ab_queue") -> AsInteger = DM -> ID_from_QUEUE;
                                                                                    DM -> IdAbQueueQr -> ParamByName ("nomer_ab")    -> AsInteger = DM -> QAbituraNOMER_AB -> Value;

                                                                                    DM -> IdAbQueueQr -> Prepare ();
                                                                                    DM -> IdAbQueueQr -> ExecSQL ();

                                                                                    DM -> FIOSearchQr -> Close ();

                                                                                    DM -> ID_from_QUEUE = -1;
                                                                                }

                                                                                ChangLog = -1;                          // блокировка переключателей конкурса

                                                                                DM -> LogLastQr -> Close ();
                                                                                DM -> LogLastQr -> ParamByName ("nomer_ab") -> AsInteger =  // Последняя по DATE_IN запись для NOMER_AB
                                                                                    DM -> QAbituraNOMER_AB -> AsInteger;
                                                                                DM -> LogLastQr -> Open ();

                                                                                if (!DM -> LogLastQrID_LOG -> IsNull)                       // в случае наличия записей о льготах удаляем их
                                                                                {
                                                                                    DM -> PrivilegLogDelStrdPrc ->
                                                                                        ParamByName ("id_log") -> AsInteger =
                                                                                            DM -> LogLastQrID_LOG -> AsInteger;

                                                                                    DM -> PrivilegLogDelStrdPrc -> Prepare ();
                                                                                    DM -> PrivilegLogDelStrdPrc -> ExecProc ();
                                                                                }

                                                                                DM -> PrivilegLogSelQr -> Close ();
                                                                                DM -> PrivilegLogSelQr ->                                   // Копируем из ABITUR_PRIVILEG для NOMER_AB
                                                                                    ParamByName ("nomer_ab") -> AsInteger =
                                                                                        DM -> QAbituraNOMER_AB -> AsInteger;
                                                                                DM -> PrivilegLogSelQr -> Open ();


                                                                                while (!DM -> PrivilegLogSelQr -> Eof)
                                                                                {
                                                                                    DM -> PrivilegLogInsStrdPrc -> ParamByName ("id_log")   -> AsInteger  = DM -> LogLastQrID_LOG          -> AsInteger;
                                                                                    DM -> PrivilegLogInsStrdPrc -> ParamByName ("n_priv")   -> AsSmallInt = DM -> PrivilegLogSelQrN_PRIV   -> Value;
                                                                                    DM -> PrivilegLogInsStrdPrc -> ParamByName ("sel_priv") -> AsSmallInt = DM -> PrivilegLogSelQrSEL_PRIV -> Value;
                                                                                    DM -> PrivilegLogInsStrdPrc -> ParamByName ("dat_priv") -> AsSmallInt = DM -> PrivilegLogSelQrDAT_PRIV -> Value;

                                                                                    DM -> PrivilegLogInsStrdPrc -> Prepare ();
                                                                                    DM -> PrivilegLogInsStrdPrc -> ExecProc ();

                                                                                    DM -> PrivilegLogSelQr -> Next ();
                                                                                }

                                                                                DM -> PrivilegLogSelQr -> Close ();
                                                                                DM -> LogLastQr -> Close ();


                                                                                #ifndef ENROLLMENT_PEOPLE_WITHOUT_CERTIFICATES
                                                                                SertificatForm -> summa_b (nom_abit);
                                                                                DM -> SumBallCalculateQr -> Active = true;
                                                                                DM -> SumBallCalculateQr -> Open ();
                                                                                DM -> SumBallCalculateQr -> Active = false;
                                                                                //if (!SertificatForm -> summa_b (nom_abit))      // сохранение оценок  //can't work because SertificatForm was closed and doesn't exists
                                                                                //    ShowMessage (
                                                                                //        "Не удалось просуммировать оценки"
                                                                                //    );
                                                                                #endif  // ! ENROLLMENT_PEOPLE_WITHOUT_CERTIFICATES

                                                                                DM -> QAbitura -> Close ();
                                                                                DM -> QAbitura -> SQL -> Clear ();
                                                                                DM -> QAbitura ->
                                                                                    SQL -> Add (
                                                                                        " SELECT"                   \
                                                                                        "     address_before,"      \
                                                                                        "     address_life,"        \
                                                                                        "     address_mama,"        \
                                                                                        "     address_papa,"        \
                                                                                        "     category_ab,"         \
                                                                                        "     category_if,"         \
                                                                                        "     citizenship,"         \
                                                                                        "     d_prikaz_include,"    \
                                                                                        "     date_priem,"          \
                                                                                        "     date_r,"              \
                                                                                        "     date_v,"              \
                                                                                        "     date_vozvrat,"        \
                                                                                        "     education,"           \
                                                                                        "     fam,"                 \
                                                                                        "     gragdan,"             \
                                                                                        "     konkurs,"             \
                                                                                        "     mama,"                \
                                                                                        "     middle_ball,"         \
                                                                                        "     n_centre,"            \
                                                                                        "     n_ck,"                \
                                                                                        "     n_fac,"               \
                                                                                        "     n_found,"             \
                                                                                        "     n_langvich,"          \
                                                                                        "     n_prikaz_include,"    \
                                                                                        "     n_region,"            \
                                                                                        "     n_spec,"              \
                                                                                        "     n_specializ,"         \
                                                                                        "     n_sport_category,"    \
                                                                                        "     n_vid_sport,"         \
                                                                                        "     name,"                \
                                                                                        "     name_edu_middle,"     \
                                                                                        "     name_edu_spec,"       \
                                                                                        "     nom_attest,"          \
                                                                                        "     nom_dela,"            \
                                                                                        "     nom_diplom,"          \
                                                                                        "     nom_group,"           \
                                                                                        "     nomer_ab,"            \
                                                                                        "     organ_v,"             \
                                                                                        "     otch,"                \
                                                                                        "     papa,"                \
                                                                                        "     pasport,"             \
                                                                                        "     personal_nomer,"      \
                                                                                        "     phone,"               \
                                                                                        "     place_r,"             \
                                                                                        "     pol,"                 \
                                                                                        "     price,"               \
                                                                                        "     rus_bel,"             \
                                                                                        "     stag,"                \
                                                                                        "     stag_spec,"           \
                                                                                        "     status,"              \
                                                                                        "     sum_ball,"            \
                                                                                        "     term_edu,"            \
                                                                                        "     town_village,"        \
                                                                                        "     type_school,"         \
                                                                                        "     vid_edu,"             \
                                                                                        "     when_edu_middle,"     \
                                                                                        "     when_edu_spec,"       \
                                                                                        "     where_edu_middle,"    \
                                                                                        "     where_edu_spec,"      \
                                                                                        "     work_before,"         \
                                                                                        "     work_mama,"           \
                                                                                        "     work_papa,"           \
                                                                                        "     id_type,"             \
                                                                                        "     date_ok,"             \
                                                                                        "     disabled,"            \
                                                                                        "     street,"              \
                                                                                        "     house,"               \
                                                                                        "     flat,"                \
                                                                                        "     postcode"             \
                                                                                        " FROM"                     \
                                                                                        "     abitura"              \
                                                                                        " WHERE"                    \
                                                                                        "     n_fac = :N_FAC"       \
                                                                                        " AND"                      \
                                                                                        "     ("                    \
                                                                                        "         status = 0"       \
                                                                                        "     OR"                   \
                                                                                        "         status = 6"       \
                                                                                        "     )"                    \
                                                                                        " ORDER BY"                 \
                                                                                        "     fam,"                 \
                                                                                        "     name,"                \
                                                                                        "     otch"
                                                                                    // "SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
                                                                                    // ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
                                                                                    // D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
                                                                                    // EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
                                                                                    // N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
                                                                                    // N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
                                                                                    // NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
                                                                                    // NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
                                                                                    // PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
                                                                                    // STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
                                                                                    // VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
                                                                                    // WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, DISABLED, STREET, \
                                                                                    // HOUSE, FLAT, POSTCODE FROM ABITURA WHERE (N_FAC=:N_FAC) AND (STATUS=0 OR STATUS=6)ORDER BY FAM, NAME, OTCH"
                                                                                );

                                                                                DM -> QAbitura -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
                                                                                DM -> QAbitura -> Open ();

                                                                                RadioGroup1 -> ItemIndex = 2;               // на закладке 'Полный список' вид обучения: 'все'

                                                                                // Переход на последнего абитуриента или на текущего после внесения изменений
                                                                                // TLocateOptions Flags;
                                                                                if (st_ins)                                 // режим ВСТАВКИ
                                                                                    max_nom_dela ();                        // !!! Вывод последнего номера дела на основ. форму

                                                                                DM -> FIOSearchQr -> Close ();

                                                                                DM -> QAbitura ->
                                                                                    Locate (
                                                                                        "NOMER_AB",
                                                                                        nom_abit,
                                                                                        Flags
                                                                                    );


                                                                                RefreshControl ();


                                                                                DM -> QGroup_Count -> Close ();
                                                                                DM -> QGroup_Count -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
                                                                                DM -> QGroup_Count -> Open ();

                                                                                DBDateEdit1            -> Enabled    = true;
                                                                                SpecializDBLookupCmbBx -> Enabled    = false;
                                                                                // NomDelaDBEdt           -> Enabled    = false;
                                                                                TabSheet1              -> TabVisible = true;
                                                                                TabSheet5              -> TabVisible = true;
                                                                                TabSheet2              -> TabVisible = true;
                                                                                // TabSheet3              -> TabVisible = true;
                                                                                // DBNavigator1           -> Enabled    = true;
                                                                                // DBNavigator3           -> Enabled    = true;
                                                                                // DBNavigator4           -> Enabled    = true;
                                                                                // PrintBtBtn             -> Visible    = true;

                                                                                // if (    !AddAbiturPerm
                                                                                //      || st_developer
                                                                                //    )
                                                                                //     AddBtBtn -> Enabled = true;
                                                                                // else
                                                                                //     AddBtBtn -> Enabled = false;

                                                                                st_ins = false;
                                                                            }
                                                                            catch (...)
                                                                            {
                                                                                ShowMessage (
                                                                                    "Произошла ошибка!\n"       \
                                                                                    "Данные не сохранены.\n"    \
                                                                                    "Сообщите программисту!"
                                                                                );
                                                                            }
                                                                        }
                                                                        else
                                                                            ShowMessage (
                                                                                "Введите конкурс!\n"    \
                                                                                "Данные не сохранены!"
                                                                            );
                                                                    }
                                                                    else
                                                                        ShowMessage (
                                                                            "Введите форму оплаты!\n"   \
                                                                            "Данные не сохранены!"
                                                                        );
                                                                }
                                                                else
                                                                    ShowMessage (
                                                                        "Введите срок получения образования!\n"   \
                                                                        "Данные не сохранены!"
                                                                    );
                                                            }
                                                            else
                                                                ShowMessage (
                                                                    "Введите Образование!\n"    \
                                                                    "Данные не сохранены!"
                                                                );
                                                        }
                                                        else
                                                            ShowMessage (
                                                                "Введите УЧРЕЖДЕНИЕ ОБРАЗОВАНИЯ!\n" \
                                                                "Данные не сохранены!"
                                                            );
                                                    }
                                                    else
                                                        ShowMessage (
                                                            "Введите ВЫПУСКНИК!\n"  \
                                                            "Данные не сохранены!"
                                                        );
                                                }
                                                else
                                                    ShowMessage (
                                                        "Введите правильно Дату рождения!\n"    \
                                                        "Данные не сохранены!"
                                                    );
                                            }
                                            else
                                                ShowMessage (
                                                    "Введите Пол или Место рождения!\n"     \
                                                    "Данные не сохранены!"
                                                );
                                        }
                                        else
                                            ShowMessage (
                                                "Введите Фамилия, Имя!\n"   \
                                                "Данные не сохранены!"
                                            );
                                    }
                                    else
                                        ShowMessage (
                                            "Введите Номер группы!\n"   \
                                            "Данные не сохранены!"
                                        );
                                }
                                else
                                    ShowMessage (
                                        "Введите Регион!\n" \
                                        "Данные не сохранены!"
                                    );
                            }
                            else
                                ShowMessage (
                                    "Введите Гражданство!\n"    \
                                    "Данные не сохранены!"
                                );
                        }
                        else
                            ShowMessage (
                                "Введите Вид спорта и Разряд!\n"    \
                                "Данные не сохранены!"
                            );
                    }
                    else
                        ShowMessage (
                            "Введите Категорию абитуриента "    \
                            "или Условия поступления!\n"  \
                            "Данные не сохранены!"
                        );
                }
                else
                    ShowMessage (
                        "Введите Направление специальности!\n"  \
                        "Данные не сохранены!"
                    );
            }
            else
                ShowMessage (
                    "Введите Вид обучения!\n"  \
                    "Данные не сохранены!"
                );
        }
        catch (...)
        {
            ShowMessage (
                "Введены не все данные или ошибка выполнения!"
            );
        }
    }
    else
    {
        ShowMessage (
            "Вы ничего не изменяли!"
        );
    }

    // SaveBtBtn   -> Enabled = true;                                           // Activate and Show button 'Save'
    // SaveBtBtn   -> Visible = true;
    // CancelBtBtn -> Enabled = true;                                           // Activate and Show button 'Cancel'
    // CancelBtBtn -> Visible = true;
    // ExitBitBtn  -> Enabled = true;                                           // Activate and Show button 'Exit'
    // ExitBitBtn  -> Visible = true;

    // DBNavigator4 -> Enabled = true;                                          // Activate and Show button 'Navigator'
    // DBNavigator4 -> Visible = true;

    PressBtn (1);                                                               // показ кнопки выход

    // EnableDate ();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::CancelBtBtnClick(TObject * Sender)
{ // кнопка ОТМЕНИТЬ

    PressBtn(1); // показ кнопки выход
    ChangLog = -1;

    if (DM->QAbitura->State == dsInsert) { // if находимся в режиме вставки
        // ---поиск сертификатов этого абитуриента
        DM->QSertificat->Close();
        DM->QSertificat->ParamByName("NOMER")->AsInteger =
            DM->QAbituraNOMER_AB->Value;
        DM->QSertificat->Open();
        int rec_sert = DM->QSertificat->RecordCount;
        // удаление записей из результатов экзаменов
        DM->QDelite->Close();
        DM->QDelite->SQL->Clear();
        DM->QDelite->SQL->Add("Delete from Examen where Nomer_Ab=:NOMER");
        DM->QDelite->ParamByName("NOMER")->AsInteger =
            DM->QAbituraNOMER_AB->Value;
        DM->QDelite->Prepare();
        DM->QDelite->ExecSQL();
        DM->QDelite->Close();

        if (rec_sert) { // if уже занесли сертификаты
            for (int i = 0; i < rec_sert; i++)
            { // for для удаления сертификатов

                DM->QSertificat->Delete();
                DM->QSertificat->Next();
            } // end for для удаления сертификатов

            DM->QSertificat->ApplyUpdates();
            DM->QSertificat->CommitUpdates();
        } // end if уже занесли сертификаты
    } // end if находимся в режиме вставки

    DM->QAbitura->CancelUpdates();
    RefreshControl();

    DBDateEdit1->Enabled = true;
    SpecializDBLookupCmbBx->Enabled = false;
    // NomDelaDBEdt->Enabled = false;
    TabSheet1->TabVisible = true;
    TabSheet5->TabVisible = true;
    TabSheet2->TabVisible = true;
    // TabSheet3->TabVisible = true;

    // DBNavigator1->Enabled = true;
    // DBNavigator3->Enabled = true;
    // DBNavigator4->Enabled = true;
    // PrintBtBtn->Visible = true;
    /* if (!AddAbiturPerm || st_developer)
     AddBtBtn->Enabled = true;
     else
     AddBtBtn->Enabled = false; */

    st_ins = false;
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Edit1Change(TObject * Sender)
{ // ПОИСК ПО ФАМИЛИИ - поле ввода
    Set<TLocateOption, 0, 1>flags;
    flags << loCaseInsensitive << loPartialKey;
    DM->QAbitura->Locate("FAM", Edit1->Text, flags);
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::RadioGroup1Click(TObject * Sender)
{ // Вид обучения
    if (RadioGroup1->ItemIndex != 2) { // if дневное или заочное
        DM->QAbitura->Close();
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + "AND (VID_EDU=" +
            AnsiString(RadioGroup1->ItemIndex) + ") ORDER BY FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QAbitura->Open();
    } // end if дневное или заочное
    else { // else ВСЕ
        DM->QAbitura->Close();
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + "ORDER BY FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QAbitura->Open();
    } // end else ВСЕ
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::FormActivate(TObject * Sender)
{ // показ основной формы

    AbiturForm->Height = 700;
    PageControl1->ActivePage = TabSheet5;
    if (DM->QAbitura->State != dsInsert)
    { // if  показ формы не в режиме добавления новой записи
        DM->QAbitura->Close();
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
            ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
            D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
            EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
            N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
            N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
            NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
            NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
            PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
            STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
            VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
            WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
            DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA \
        WHERE (N_FAC=:N_FAC) AND (STATUS=0)ORDER BY FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QAbitura->Open();
        if (DM->QAbitura->RecordCount != 0)
            RefreshControl();

        if (DateServer >= dateOkonch)
            KonkursCmbBx->Enabled = false;

        DM->QAdress->Close();
        DM->QAdress->ParamByName("ID")->AsInteger = DM->QAbituraSTREET->Value;
        DM->QAdress->Open();
    } // end  if  показ формы не в режиме добавления новой записи

    ActionList1->State = asSuspended;

    DM->QSpecializPlan_Priem->Open();

    // Гражданство
    DM->CountryQr->Close();
    DM->CountryQr->Open();

    // адрес
    if (region_id == 7) {
        AdressRegEdt->ReadOnly = false;
    }
    else
        AdressRegEdt->ReadOnly = true;

    // Установка списка привелегий
    // БВИ
    DM->WithoutQr->Close();
    DM->WithoutCntQr->Close();
    DM->WithoutCntQr->Open();
    int WithoutCnt = DM->WithoutCntQrCOUNT->Value;
    DM->WithoutCntQr->Close();
    DM->WithoutQr->Open();
    TLabel *EditlnstanceL;
    TComboBox *EditlnstanceCB;
    for (int i = 0; i < WithoutCnt; i++) {
        EditlnstanceL = (TLabel*)FindComponent("WithOutLbl" + IntToStr(i + 1));
        EditlnstanceCB = (TComboBox*)FindComponent
            ("WithOutCmboBx" + IntToStr(i + 1));
        EditlnstanceL->Caption = DM->WithoutQrNAME_PRIV->AsString;
        DM->WithoutDetQr->Close();
        DM->WithoutDetQr->ParamByName("id_priv")->AsSmallInt =
            DM->WithoutQrID_PRIV->Value;
        DM->WithoutDetQr->Open();
        EditlnstanceCB->Clear();
        EditlnstanceCB->Items->Add("–");
        while (!DM->WithoutDetQr->Eof) {
            EditlnstanceCB->Items->Add(DM->WithoutDetQrNAME_DETAIS->AsString);
            DM->WithoutDetQr->Next();
        }
        EditlnstanceCB->ItemIndex = 0;
        DM->WithoutDetQr->Close();
        DM->WithoutQr->Next();
    }
    DM->WithoutQr->Close();

    // ВК
    DM->OutQr->Close();
    DM->OutCntQr->Close();
    DM->OutCntQr->Open();
    int OutCnt = DM->OutCntQrCOUNT->Value;
    DM->OutCntQr->Close();
    DM->OutQr->Open();
    for (int i = 0; i < OutCnt; i++) {
        EditlnstanceL = (TLabel*)FindComponent("OutLbl" + IntToStr(i + 1));
        EditlnstanceCB = (TComboBox*)FindComponent
            ("OutCmboBx" + IntToStr(i + 1));
        EditlnstanceL->Caption = DM->OutQrNAME_PRIV->AsString;
        DM->OutDetQr->Close();
        DM->OutDetQr->ParamByName("id_priv")->AsSmallInt =
            DM->OutQrID_PRIV->Value;
        DM->OutDetQr->Open();
        EditlnstanceCB->Clear();
        EditlnstanceCB->Items->Add("–");
        while (!DM->OutDetQr->Eof) {
            EditlnstanceCB->Items->Add(DM->OutDetQrNAME_DETAIS->AsString);
            DM->OutDetQr->Next();
        }
        EditlnstanceCB->ItemIndex = 0;
        DM->OutDetQr->Close();
        DM->OutQr->Next();
    }
    DM->OutQr->Close();

    // Дополнительная информация
    DM->InfCntQr->Close();
    DM->InfCntQr->Open();
    int InfCnt = DM->InfCntQrCOUNT->Value;
    DM->InfCntQr->Close();
    DM->InfQr->Close();
    DM->InfQr->Open();
    InfChekLstBx->Items->Clear();
    for (int i = 0; i < InfCnt; i++) {
        InfChekLstBx->Items->Add(DM->InfQrNAME_PRIV->AsString);
        DM->InfQr->Next();
    }
    DM->InfQr->Close();

    BitBtnShow(); // показ кнопок

    // Считывание разрешений для кнопок
    DM->BlockBtnQr->Close();
    DM->BlockBtnQr->ParamByName("n_fac")->AsSmallInt = nom_fac;
    DM->BlockBtnQr->Open();
    AddAbiturPerm = DM->BlockBtnQrADD_ABITUR->Value;
    TookDoc1Perm = DM->BlockBtnQrTOOK_DOC1->Value;
    TookDoc2Perm = DM->BlockBtnQrTOOK_DOC2->Value;
    ReInsideFacPerm = DM->BlockBtnQrRE_INSIDE_FAC->Value;
    RestorListPerm = DM->BlockBtnQrRESTOR_LIST->Value;
    DM->BlockBtnQr->Close();

    /* if (!AddAbiturPerm || st_developer)
     AddBtBtn->Enabled = true;
     else
     AddBtBtn->Enabled = false; */

    if (!TookDoc1Perm || st_developer)
        TookDocBtBtn1->Enabled = true;
    else
        TookDocBtBtn1->Enabled = false;

    if (!TookDoc2Perm || st_developer)
        TookDocBtBtn2->Enabled = true;
    else
        TookDocBtBtn2->Enabled = false;

    if (!ReInsideFacPerm || st_developer)
        ReInsideFacBtBtn->Enabled = true;
    else
        ReInsideFacBtBtn->Enabled = false;

    if (!RestorListPerm || st_developer)
        RestorlistBtBtn->Enabled = true;
    else
        RestorlistBtBtn->Enabled = false;

    // EnableDate();//Показ компонентов для разработчика после 25.07.2010

    /* DM->QDistrict->Close();
     DM->QDistrict->Open();
     DM->QType_locality->Close();
     DM->QType_locality->Open();
     DM->QLocality->Close();
     DM->QLocality->Open();
     DM->QType_street->Close();
     DM->QType_street->Open();
     DM->QStreet->Close();
     DM->QStreet->Open(); */

    /* if (SplashUnit->loginUser != "DEVELOPER") {
     GroupBox2->Visible = false;
     GroupBox3->Visible = false;
     GroupBox4->Visible = false;
     } */
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::KonkursRdGrpClick(TObject * Sender)
{ // ИЗМЕНЕНИЯ по кнопке КОНКУРС
    if (DM->QAbitura->State == dsBrowse)
        DM->QAbitura->Edit();
    switch (KonkursCmbBx->ItemIndex) { // switch

    case 3: // ЦК
        if (SpecializDBLookupCmbBx->Text != "") { // if выбрали специализацию
            // Считывание кол-во мест по специальностям р-нам и организациям - УБРАТЬ!!!
            DM->QCk->Close();
            DM->QCk->ParamByName("N_SPEC")->AsInteger =
                DM->QAbituraN_SPECIALIZ->Value;
            DM->QCk->Open();
            Label29->Visible = true;
            CkRegionDBLkpCmbBx->Visible = true;
        } // end if выбрали специализацию
        else { // else ошибка
            ShowMessage("Не выбрана специализация!");
            KonkursCmbBx->ItemIndex = -1;
        } // end else ошибка

        break;
    default:
        Label29->Visible = false;
        CkRegionDBLkpCmbBx->Visible = false;
        break;
    } // end switch
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::AddBtBtnClick(TObject * Sender)
{ // кнопка ДОБАВИТЬ
    NewAbitur(0);
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::DBNavigator1Click(TObject * Sender,
    TNavigateBtn Button) { // НАВИГАТОР
    RefreshControl();
    // перечитывание КУ
    TabSheet4Show(Sender);
    // закрытие конкурсов после приема документов
    if (!st_developer & pole_block == 1)
        KonkursCmbBx->Enabled = false;
    // перечитка Helpa
    WhereEduMiddleDBEdtClick(Sender);
    // Изменение номера дела
    NumDelaLbl->Caption = DM->NumDelaString(DM->QAbituraVID_EDU->Value,
        DM->QAbituraTERM_EDU->Value, DM->QAbituraPRICE->Value,
        DM->QAbituraNOM_DELA->Value);
    ChangLog = -1;
}
void __fastcall TAbiturForm::DBGrid1DblClick (TObject * Sender)                 // Grid  на закладке ПОЛНЫЙ СПИСОК
{
    PageControl1 -> ActivePage = TabSheet2;

    ChangLog = -1;

    RefreshControl ();
}
void __fastcall TAbiturForm::PrintBtBtnClick (TObject * Sender)                  // кнопка ПЕЧАТЬ
{
    SaveBtBtnClick (this);

    ListDlgForm = new TListDlgForm (this);

    ListDlgForm -> ListBox1 -> Items -> Clear ();
    ListDlgForm -> ListBox2 -> Items -> Clear ();

    DM -> ListDocFDQ -> Close ();
    DM -> DocumFDQ   -> Close ();
    DM -> ListDocFDQ ->
        ParamByName ("NOMER_AB") -> Value =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> DocumFDQ   ->
        ParamByName ("NOMER_AB") -> Value =
            DM -> QAbituraNOMER_AB -> Value;
    DM -> ListDocFDQ -> Open();
    DM -> DocumFDQ   -> Open();

    for (int i = 0;
             i < DM -> ListDocFDQ -> RecordCount;
             ++i
        )
    {
        ListDlgForm -> ListBox2 -> Items ->
            AddObject (
                DM -> ListDocFDQTEXT_DOC -> Value,
                (TObject *) (
                    DM -> ListDocFDQN_DOC -> Value
                )
            );

        DM -> ListDocFDQ -> Next ();
    }

    for (int i = 0;
             i < DM -> DocumFDQ -> RecordCount;
             ++i
        )
    {
        ListDlgForm -> ListBox1 -> Items ->
            AddObject (
                DM -> DocumFDQTEXT_DOC -> Value,
                (TObject *) (
                    DM -> DocumFDQN_DOC -> Value
                )
            );

        DM -> DocumFDQ -> Next();
    }

    if (!ListDlgForm -> ListBox2 -> Items -> Count)
    {
        ListDlgForm -> ListBox2 -> Items ->
            AddObject (
                ListDlgForm -> ListBox1 -> Items -> Strings[0],
                ListDlgForm -> ListBox1 -> Items -> Objects[0]
            );

        ListDlgForm -> ListBox1 -> Items -> Delete (0);                         // Добавление заявления в список документов
        ListDlgForm -> ListBox2 -> Items ->
            AddObject (
                ListDlgForm -> ListBox1 -> Items -> Strings[0],
                ListDlgForm -> ListBox1 -> Items -> Objects[0]
            );

        ListDlgForm -> ListBox1 -> Items -> Delete (0);                         // Добавление аттеста в список документов
        ListDlgForm -> ListBox2 -> Items ->
            AddObject (
                ListDlgForm -> ListBox1 -> Items -> Strings[6],
                ListDlgForm -> ListBox1 -> Items -> Objects[6]
            );

        ListDlgForm -> ListBox1 -> Items -> Delete (6);                         // Добавление медицинской справки в список документов
    }

    ListDlgForm -> ShowModal ();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::RestorlistBtBtnClick (TObject * Sender)            // кнопка ВОССТАНОВИТЬ В СПИСКЕ (для абитуриентов, которые забирали документы)
{
    PressBtn (3);

    DBGrid1->Visible = false;
    Undo_Ab_Form = new TUndo_Ab_Form(this);

    DM->QAbitura->Close();
    DM->QAbitura->SQL->Clear();
    DM->QAbitura->SQL->Add("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
            ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
            D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
            EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
            N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
            N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
            NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
            NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
            PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
            STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
            VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
            WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
            DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA WHERE (STATUS=1) ORDER BY FAM, NAME, OTCH"
        );
    DM->QAbitura->Open();

    Undo_Ab_Form->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TookDocBtBtn1Click(TObject * Sender)
{ // кнопка ЗАБРАЛ ДОКУМЕНТЫ до окончания приёма документов

    PoleBlock(); // получение значения в переменную pole_block из БД

    AnsiString fio_ab = DM->QAbituraFAM->Value + " " + DM->QAbituraNAME->Value +
        " " + DM->QAbituraOTCH->Value;
    int price = DM->QAbituraPRICE->Value;

    /* if (!st_developer) {
     if (pole_block == 1 & price != 1) // pole_block==1, price=бюджет
     {
     ShowMessage(
     "Абитуриент включен в зачисление и не может забрарть документы! Обратитесь к программисту!");
     return;
     }
     } */

    if (MessageDlg("Абитуриент забирает документы?", mtConfirmation, mbOKCancel,
        0) == 1) {
        DM->QAbitura->Edit();
        DM->QAbituraSTATUS->Value = 1;
        DM->QAbituraDATE_VOZVRAT->Value =
            DateTimeToSQLTimeStamp(StrToDate(cur_d.CurrentDate()));
        DM->QAbituraN_CK->Value = 0;
        // DM->QAbituraN_PRIVILEGE_EXAM->Value = 1;
        // DM->QAbituraKONKURS->Value=0;

        // сохранение изменений
        DM->QAbitura->ApplyUpdates();
        DM->QAbitura->CommitUpdates();

        // перечитка  QAbitura
        DM->QAbitura->Close();
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
            ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
            D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
            EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
            N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
            N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
            NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
            NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
            PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
            STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
            VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
            WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
            DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA WHERE (N_FAC=:N_FAC) AND (STATUS=0)ORDER BY FAM, NAME, OTCH"
            );
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QAbitura->Open();

        if (DM->QAbitura->RecordCount != 0)
            RefreshControl();

        DM->QGroup_Count->Close();
        DM->QGroup_Count->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QGroup_Count->Open();
    } // end MessageDlg=OK

}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::FormEduCmbBxChange(TObject * Sender)
{ // ВИД ОБУЧЕНИЯ
    bool FormEduChange = false;
    if (ChangLog == 0) {
        if (MessageDlg("Изменение данного параметра повлечёт отметку о возврате документов\n \
         и добавлению новой записи в журнале учёта абитуриентов.\nВы хотите продолжить?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            FormEduChange = true;
        }
    }
    else
        FormEduChange = true;
    if (FormEduChange == true) {
        if (DM->QAbitura->State == dsBrowse)
            DM->QAbitura->Edit();
        if (oplata_konkurs == 0 && PriceCmbBx->ItemIndex != -1)
            VidKonkurs(KonkursCmbBx, PriceCmbBx, FormEduCmbBx);
        if (ChangLog != 2)
            ChangLog = 1;
    }

    // перечитываем КУ по выбору
    // Закомментировано в связи с отменой
    // TabSheet4Show(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::EducatCmbBxChange(TObject * Sender) {
    bool EducatChange = false;
    // Изменение образования
    if (ChangLog == 0) {
        if (MessageDlg("Изменение данного параметра повлечёт отметку о возврате документов\n \
         и добавлению новой записи в журнале учёта абитуриентов.\nВы хотите продолжить?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            EducatChange = true;
        }
    }
    else
        EducatChange = true;
    if (EducatChange == true) {
        if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
            DM->QAbitura->Edit();
        } // end if dsBrowse

        TermEduCmbBx->ItemIndex = -1;
        PriceCmbBx->ItemIndex = -1;
        KonkursCmbBx->ItemIndex = -1;
        TermEduCmbBx->Clear();

        int pr_edu; // 0 - СО/ССО, 1 - ВО
        switch (EducatCmbBx->ItemIndex) {
        case 0: // СО
            {
                pr_edu = 0;
                break;
            }
        case 1: // ССО
            {
                pr_edu = 0;
                break;
            }
        case 2: // незаконченное ВО
            {
                pr_edu = 1;
                break;
            }
        case 3: // ВО
            {
                pr_edu = 1;
                break;
            }
        case 4: // ПТУ
            {
                pr_edu = 0;
                break;
            }
        }

        switch (pr_edu) {
        case 0: // СО/ССО
            {
                // Срок получения образования
                Label64->Caption = "Срок получения образования:";
                TermEduCmbBx->Clear();
                TermEduCmbBx->Items->Add("полный");
                if ((pr_KategIf == 0) && (EducatCmbBx->ItemIndex == 1))
                { // только для РБ + ССО м.б. и сокращённый
                    TermEduCmbBx->Items->Add("сокращённый 2 курс");
                    TermEduCmbBx->Items->Add("сокращённый 3 курс");
                    TermEduCmbBx->ItemIndex = -1;
                    if (EducatCmbBx->ItemIndex > -1)
                        TermEduCmbBx->Enabled = true;
                    else
                        TermEduCmbBx->Enabled = false;
                }
                else { // ИГ, СНГ
                    // СО/ССО, для иностранцев и СНГ - только полный
                    TermEduCmbBx->ItemIndex = 0;
                    TermEduCmbBx->Enabled = false;
                }
                break;
            }
        case 1: // ВО
            {
                // Курс поступления
                Label64->Caption = "Курс поступления:";
                TermEduCmbBx->Items->Clear();
                TermEduCmbBx->Items->Add("1 курс");
                if (((pr_KategIf == 0) || (pr_KategIf == 2)) &&
                    (EducatCmbBx->ItemIndex == 3)) {
                    // ВО, не иностранец
                    TermEduCmbBx->Items->Add("2 курс");
                    TermEduCmbBx->Items->Add("3 курс");
                    TermEduCmbBx->ItemIndex = -1;
                    if (EducatCmbBx->ItemIndex > -1)
                        TermEduCmbBx->Enabled = true;
                    else
                        TermEduCmbBx->Enabled = false;
                }
                else {
                    // ВО, иностранцы
                    // Только полный
                    TermEduCmbBx->ItemIndex = 0;
                    TermEduCmbBx->Enabled = false;
                }
                break;
            }
        default:
            TermEduCmbBx->Enabled = false;
        }

        TermEduCmbBxChange(this);
        if (ChangLog != 2)
            ChangLog = 1;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::FamDBEdtKeyDown(TObject * Sender, WORD & Key,
    TShiftState Shift) { // ФАМИЛИЯ
    /* if (Key==32)
     { //if нажат пробел
     DBEdit4->SetFocus();
     }//end if нажат пробел */ }

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::NameDBEdtKeyDown(TObject * Sender, WORD & Key,
    TShiftState Shift) { // ИМЯ
    /* if (Key==32)
     {//if нажат пробел
     DBEdit5->SetFocus();
     }//end if нажат пробел */ }

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::DBGrid1TitleClick(TColumn * Column)
{ // Щелчек на титуле  Gridа, для сортировки

    DM->QAbitura->Close();

    AnsiString sql_temp_1 = Chek_Vid_Edu();
    AnsiString ttl;
    ttl = Column->Title->Caption;
    if (ttl == "Фамилия") {
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + sql_temp_1 +
            " ORDER BY FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    }
    if (ttl == "№ гр.") {
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + sql_temp_1 +
            " ORDER BY NOM_GROUP, FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    }
    if (ttl == "№ дела") {
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + sql_temp_1 + " ORDER BY NOM_DELA");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    }
    if (ttl == "Направл. специальности") {
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + sql_temp_1 +
            " ORDER BY N_SPECIALIZ, FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    }
    if (ttl == "Конкурс") {
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + sql_temp_1 +
            " ORDER BY KONKURS, FAM, NAME, OTCH");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    }
    if (ttl == "Дата приема") {
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add(SQLText + sql_temp_1 +
            " ORDER BY DATE_PRIEM, NOM_DELA");
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    }

    DM->QAbitura->Open();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TookDocBtBtn2Click(TObject * Sender)
{ // кнопка ЗАБРАЛ ДОКУМЕНТЫ ВО ВРЕМЯ ЭКЗАМЕНОВ
    AnsiString fio_ab = DM->QAbituraFAM->Value + " " + DM->QAbituraNAME->Value +
        " " + DM->QAbituraOTCH->Value;

    if (MessageDlg
        ("Абитуриент действительно хочет забрать документы и уйти из нашего ВУЗа?",
        mtConfirmation, mbOKCancel, 0) == 1) {

        DM->QAbitura->Edit();
        // DM->QAbituraSTATUS->Value = 4; // забрал документы во время экзаменов
        DM->QAbituraSTATUS->Value = 1;
        // заменил, что бы можно было восстановить
        DM->QAbituraDATE_VOZVRAT->Value =
            DateTimeToSQLTimeStamp(StrToDate(cur_d.CurrentDate()));

        DM->QAbitura->ApplyUpdates();
        DM->QAbitura->CommitUpdates();

        DM->QAbitura->Close();
        DM->QAbitura->SQL->Clear();
        DM->QAbitura->SQL->Add("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
            ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
            D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
            EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
            N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
            N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
            NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
            NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
            PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
            STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
            VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
            WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
            DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA WHERE (N_FAC=:N_FAC) AND (STATUS=0)ORDER BY FAM, NAME, OTCH"
            );
        DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QAbitura->Open();

        if (DM->QAbitura->RecordCount != 0)
            RefreshControl();

        DM->QGroup_Count->Close();
        DM->QGroup_Count->ParamByName("N_FAC")->AsInteger = nom_fac;
        DM->QGroup_Count->Open();
    } // end if MessageDlg=OK
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::DBGrid3DblClick(TObject * Sender)                  // Двойной щелчек на Grid-е с сертификатами
{
    SertificatForm = new TSertificatForm(this);
    SertificatForm->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::WhereEduMiddleDBEdtClick(TObject * Sender) {

    WhereEduMiddleDBEdt->HelpContext = 10; // сразу первая страница
    // при перемещении по базе из поля где закончил среднее образование - вызываем Help  с районами
    if ((WhereEduMiddleDBEdt->Text.Pos("Брест")) ||
        (WhereEduMiddleDBEdt->Text.Pos("брест")))
        WhereEduMiddleDBEdt->HelpContext = 20;
    if ((WhereEduMiddleDBEdt->Text.Pos("Витебск")) ||
        (WhereEduMiddleDBEdt->Text.Pos("витебск")))
        WhereEduMiddleDBEdt->HelpContext = 40;
    if ((WhereEduMiddleDBEdt->Text.Pos("Гомель")) ||
        (WhereEduMiddleDBEdt->Text.Pos("гомель")))
        WhereEduMiddleDBEdt->HelpContext = 70;
    if ((WhereEduMiddleDBEdt->Text.Pos("Гродн")) ||
        (WhereEduMiddleDBEdt->Text.Pos("гродн")))
        WhereEduMiddleDBEdt->HelpContext = 100;
    if ((WhereEduMiddleDBEdt->Text.Pos("Минск")) ||
        (WhereEduMiddleDBEdt->Text.Pos("минск")))
        WhereEduMiddleDBEdt->HelpContext = 120;
    if ((WhereEduMiddleDBEdt->Text.Pos("Могилев")) ||
        (WhereEduMiddleDBEdt->Text.Pos("могилев")))
        WhereEduMiddleDBEdt->HelpContext = 150;

    switch (WhereEduMiddleDBEdt->HelpContext) {
    case 20: // Брест
        // Брестская область
        if ((WhereEduMiddleDBEdt->Text.Pos("Баранович")) ||
            (WhereEduMiddleDBEdt->Text.Pos("баранович")) ||
            (WhereEduMiddleDBEdt->Text.Pos("Городищ")))
            WhereEduMiddleDBEdt->HelpContext = 21;
        if ((WhereEduMiddleDBEdt->Text.Pos("Ивацевич")) ||
            (WhereEduMiddleDBEdt->Text.Pos("ивацевич")))
            WhereEduMiddleDBEdt->HelpContext = 22;
        if ((WhereEduMiddleDBEdt->Text.Pos("Каменец")) ||
            (WhereEduMiddleDBEdt->Text.Pos("каменец")))
            WhereEduMiddleDBEdt->HelpContext = 23;
        if ((WhereEduMiddleDBEdt->Text.Pos("Березов")) ||
            (WhereEduMiddleDBEdt->Text.Pos("березов")))
            WhereEduMiddleDBEdt->HelpContext = 24;
        if ((WhereEduMiddleDBEdt->Text.Pos("Лунинец")) ||
            (WhereEduMiddleDBEdt->Text.Pos("лунинец")))
            WhereEduMiddleDBEdt->HelpContext = 25;
        if ((WhereEduMiddleDBEdt->Text.Pos("Брестский")) ||
            (WhereEduMiddleDBEdt->Text.Pos("брестский")))
            WhereEduMiddleDBEdt->HelpContext = 26;
        if ((WhereEduMiddleDBEdt->Text.Pos("Ляхович")) ||
            (WhereEduMiddleDBEdt->Text.Pos("ляхович")))
            WhereEduMiddleDBEdt->HelpContext = 27;
        if ((WhereEduMiddleDBEdt->Text.Pos("Ганцев")) ||
            (WhereEduMiddleDBEdt->Text.Pos("ганцев")))
            WhereEduMiddleDBEdt->HelpContext = 28;
        if ((WhereEduMiddleDBEdt->Text.Pos("Малори")) ||
            (WhereEduMiddleDBEdt->Text.Pos("малори")))
            WhereEduMiddleDBEdt->HelpContext = 29;
        if ((WhereEduMiddleDBEdt->Text.Pos("Дрогичин")) ||
            (WhereEduMiddleDBEdt->Text.Pos("дрогичин")))
            WhereEduMiddleDBEdt->HelpContext = 30;
        if ((WhereEduMiddleDBEdt->Text.Pos("Пинск")) ||
            (WhereEduMiddleDBEdt->Text.Pos("пинск")))
            WhereEduMiddleDBEdt->HelpContext = 31;
        if ((WhereEduMiddleDBEdt->Text.Pos("Жабинк")) ||
            (WhereEduMiddleDBEdt->Text.Pos("жабинк")))
            WhereEduMiddleDBEdt->HelpContext = 32;
        if ((WhereEduMiddleDBEdt->Text.Pos("Пружан")) ||
            (WhereEduMiddleDBEdt->Text.Pos("пружан")))
            WhereEduMiddleDBEdt->HelpContext = 33;
        if ((WhereEduMiddleDBEdt->Text.Pos("Иванов")) ||
            (WhereEduMiddleDBEdt->Text.Pos("иванов")))
            WhereEduMiddleDBEdt->HelpContext = 34;
        if ((WhereEduMiddleDBEdt->Text.Pos("Столин")) ||
            (WhereEduMiddleDBEdt->Text.Pos("столин")))
            WhereEduMiddleDBEdt->HelpContext = 35;
        if ((WhereEduMiddleDBEdt->Text.Pos("Кобрин")) ||
            (WhereEduMiddleDBEdt->Text.Pos("кобрин")))
            WhereEduMiddleDBEdt->HelpContext = 35;
        break;

    case 40: // Витебск
        // районы Витебской области
        if ((WhereEduMiddleDBEdt->Text.Pos("Бешенков")) ||
            (WhereEduMiddleDBEdt->Text.Pos("бешенков")))
            WhereEduMiddleDBEdt->HelpContext = 41;
        if ((WhereEduMiddleDBEdt->Text.Pos("Браслав")) ||
            (WhereEduMiddleDBEdt->Text.Pos("браслав")))
            WhereEduMiddleDBEdt->HelpContext = 42;
        if ((WhereEduMiddleDBEdt->Text.Pos("Вернедвинск")) ||
            (WhereEduMiddleDBEdt->Text.Pos("вернедвинск")))
            WhereEduMiddleDBEdt->HelpContext = 43;
        if ((WhereEduMiddleDBEdt->Text.Pos("Витебский")) ||
            (WhereEduMiddleDBEdt->Text.Pos("витебский")))
            WhereEduMiddleDBEdt->HelpContext = 44;
        if ((WhereEduMiddleDBEdt->Text.Pos("Глубок")) ||
            (WhereEduMiddleDBEdt->Text.Pos("глубок")))
            WhereEduMiddleDBEdt->HelpContext = 45;
        if ((WhereEduMiddleDBEdt->Text.Pos("Городок")) ||
            (WhereEduMiddleDBEdt->Text.Pos("городок")))
            WhereEduMiddleDBEdt->HelpContext = 46;
        if ((WhereEduMiddleDBEdt->Text.Pos("Докшиц")) ||
            (WhereEduMiddleDBEdt->Text.Pos("докшиц")))
            WhereEduMiddleDBEdt->HelpContext = 47;
        if ((WhereEduMiddleDBEdt->Text.Pos("Дубров")) ||
            (WhereEduMiddleDBEdt->Text.Pos("дубров")))
            WhereEduMiddleDBEdt->HelpContext = 48;
        if ((WhereEduMiddleDBEdt->Text.Pos("Лепель")) ||
            (WhereEduMiddleDBEdt->Text.Pos("лепель")))
            WhereEduMiddleDBEdt->HelpContext = 49;
        if ((WhereEduMiddleDBEdt->Text.Pos("Лиозн")) ||
            (WhereEduMiddleDBEdt->Text.Pos("лиозн")))
            WhereEduMiddleDBEdt->HelpContext = 50;
        if ((WhereEduMiddleDBEdt->Text.Pos("Миор")) ||
            (WhereEduMiddleDBEdt->Text.Pos("миор")))
            WhereEduMiddleDBEdt->HelpContext = 51;
        if ((WhereEduMiddleDBEdt->Text.Pos("Орша")) ||
            (WhereEduMiddleDBEdt->Text.Pos("орша")))
            WhereEduMiddleDBEdt->HelpContext = 52;
        if ((WhereEduMiddleDBEdt->Text.Pos("Полоцк")) ||
            (WhereEduMiddleDBEdt->Text.Pos("полоц")))
            WhereEduMiddleDBEdt->HelpContext = 53;
        if ((WhereEduMiddleDBEdt->Text.Pos("Постав")) ||
            (WhereEduMiddleDBEdt->Text.Pos("постав")))
            WhereEduMiddleDBEdt->HelpContext = 54;
        if ((WhereEduMiddleDBEdt->Text.Pos("Россон")) ||
            (WhereEduMiddleDBEdt->Text.Pos("россон")))
            WhereEduMiddleDBEdt->HelpContext = 55;
        if ((WhereEduMiddleDBEdt->Text.Pos("Сенн")) ||
            (WhereEduMiddleDBEdt->Text.Pos("сенн")))
            WhereEduMiddleDBEdt->HelpContext = 56;
        if ((WhereEduMiddleDBEdt->Text.Pos("Толочин")) ||
            (WhereEduMiddleDBEdt->Text.Pos("толочин")))
            WhereEduMiddleDBEdt->HelpContext = 57;
        if ((WhereEduMiddleDBEdt->Text.Pos("Ушач")) ||
            (WhereEduMiddleDBEdt->Text.Pos("ушач")))
            WhereEduMiddleDBEdt->HelpContext = 58;
        if ((WhereEduMiddleDBEdt->Text.Pos("Чашник")) ||
            (WhereEduMiddleDBEdt->Text.Pos("чашник")))
            WhereEduMiddleDBEdt->HelpContext = 59;
        if ((WhereEduMiddleDBEdt->Text.Pos("Шарковщин")) ||
            (WhereEduMiddleDBEdt->Text.Pos("шарковщин")))
            WhereEduMiddleDBEdt->HelpContext = 60;
        if ((WhereEduMiddleDBEdt->Text.Pos("Шумилин")) ||
            (WhereEduMiddleDBEdt->Text.Pos("шумилин")))
            WhereEduMiddleDBEdt->HelpContext = 61;
        break;
    case 70: // Гомель
        // Районы Гомельской области
        if ((WhereEduMiddleDBEdt->Text.Pos("Брагин")) ||
            (WhereEduMiddleDBEdt->Text.Pos("брагин")))
            WhereEduMiddleDBEdt->HelpContext = 71;
        if ((WhereEduMiddleDBEdt->Text.Pos("Буда-Кошелев")) ||
            (WhereEduMiddleDBEdt->Text.Pos("буда-кошелев")))
            WhereEduMiddleDBEdt->HelpContext = 72;
        if ((WhereEduMiddleDBEdt->Text.Pos("Ветк")) ||
            (WhereEduMiddleDBEdt->Text.Pos("ветк")))
            WhereEduMiddleDBEdt->HelpContext = 73;
        if ((WhereEduMiddleDBEdt->Text.Pos("Гомельский")) ||
            (WhereEduMiddleDBEdt->Text.Pos("гомельский")))
            WhereEduMiddleDBEdt->HelpContext = 74;
        if ((WhereEduMiddleDBEdt->Text.Pos("Добруш")) ||
            (WhereEduMiddleDBEdt->Text.Pos("добруш")))
            WhereEduMiddleDBEdt->HelpContext = 75;
        if ((WhereEduMiddleDBEdt->Text.Pos("Ельск")) ||
            (WhereEduMiddleDBEdt->Text.Pos("ельск")))
            WhereEduMiddleDBEdt->HelpContext = 76;
        if ((WhereEduMiddleDBEdt->Text.Pos("Житкович")) ||
            (WhereEduMiddleDBEdt->Text.Pos("житкович")))
            WhereEduMiddleDBEdt->HelpContext = 77;
        if ((WhereEduMiddleDBEdt->Text.Pos("Жлобин")) ||
            (WhereEduMiddleDBEdt->Text.Pos("жлобин")))
            WhereEduMiddleDBEdt->HelpContext = 78;
        if ((WhereEduMiddleDBEdt->Text.Pos("Калинкович")) ||
            (WhereEduMiddleDBEdt->Text.Pos("калинкович")))
            WhereEduMiddleDBEdt->HelpContext = 79;
        if ((WhereEduMiddleDBEdt->Text.Pos("Корм")) ||
            (WhereEduMiddleDBEdt->Text.Pos("корм")))
            WhereEduMiddleDBEdt->HelpContext = 80;
        if ((WhereEduMiddleDBEdt->Text.Pos("Лельчиц")) ||
            (WhereEduMiddleDBEdt->Text.Pos("лельчиц")))
            WhereEduMiddleDBEdt->HelpContext = 81;
        if ((WhereEduMiddleDBEdt->Text.Pos("Лоев")) ||
            (WhereEduMiddleDBEdt->Text.Pos("лоев")))
            WhereEduMiddleDBEdt->HelpContext = 82;
        if ((WhereEduMiddleDBEdt->Text.Pos("Мозыр")) ||
            (WhereEduMiddleDBEdt->Text.Pos("мозыр")))
            WhereEduMiddleDBEdt->HelpContext = 83;
        if ((WhereEduMiddleDBEdt->Text.Pos("Наровля")) ||
            (WhereEduMiddleDBEdt->Text.Pos("наровля")))
            WhereEduMiddleDBEdt->HelpContext = 84;
        if ((WhereEduMiddleDBEdt->Text.Pos("Октябр")) ||
            (WhereEduMiddleDBEdt->Text.Pos("октябр")))
            WhereEduMiddleDBEdt->HelpContext = 85;
        if ((WhereEduMiddleDBEdt->Text.Pos("Петриков")) ||
            (WhereEduMiddleDBEdt->Text.Pos("петриков")))
            WhereEduMiddleDBEdt->HelpContext = 86;
        if ((WhereEduMiddleDBEdt->Text.Pos("Речиц")) ||
            (WhereEduMiddleDBEdt->Text.Pos("речиц")))
            WhereEduMiddleDBEdt->HelpContext = 87;
        if ((WhereEduMiddleDBEdt->Text.Pos("Рогачев")) ||
            (WhereEduMiddleDBEdt->Text.Pos("рогачев")))
            WhereEduMiddleDBEdt->HelpContext = 88;
        if ((WhereEduMiddleDBEdt->Text.Pos("Светлогор")) ||
            (WhereEduMiddleDBEdt->Text.Pos("светлогор")))
            WhereEduMiddleDBEdt->HelpContext = 89;
        if ((WhereEduMiddleDBEdt->Text.Pos("Хойник")) ||
            (WhereEduMiddleDBEdt->Text.Pos("хойник")))
            WhereEduMiddleDBEdt->HelpContext = 90;
        if ((WhereEduMiddleDBEdt->Text.Pos("Чечерск")) ||
            (WhereEduMiddleDBEdt->Text.Pos("чечерск")))
            WhereEduMiddleDBEdt->HelpContext = 91;
        break;
    case 100: // Гродн
        // Гродненская область
        if ((WhereEduMiddleDBEdt->Text.Pos("Берестовиц")) ||
            (WhereEduMiddleDBEdt->Text.Pos("берестовиц")) ||
            (WhereEduMiddleDBEdt->Text.Pos("Пограничный")))
            WhereEduMiddleDBEdt->HelpContext = 101;
        if ((WhereEduMiddleDBEdt->Text.Pos("Волковыс")) ||
            (WhereEduMiddleDBEdt->Text.Pos("волковыс")))
            WhereEduMiddleDBEdt->HelpContext = 102;
        if ((WhereEduMiddleDBEdt->Text.Pos("Воронов")) ||
            (WhereEduMiddleDBEdt->Text.Pos("воронов")))
            WhereEduMiddleDBEdt->HelpContext = 103;
        if ((WhereEduMiddleDBEdt->Text.Pos("Гродненский")) ||
            (WhereEduMiddleDBEdt->Text.Pos("гродненский")))
            WhereEduMiddleDBEdt->HelpContext = 104;
        if ((WhereEduMiddleDBEdt->Text.Pos("Дятлов")) ||
            (WhereEduMiddleDBEdt->Text.Pos("дятлов")))
            WhereEduMiddleDBEdt->HelpContext = 105;
        if ((WhereEduMiddleDBEdt->Text.Pos("Зельв")) ||
            (WhereEduMiddleDBEdt->Text.Pos("зельв")))
            WhereEduMiddleDBEdt->HelpContext = 106;
        if ((WhereEduMiddleDBEdt->Text.Pos("Ивье")) ||
            (WhereEduMiddleDBEdt->Text.Pos("ивье")))
            WhereEduMiddleDBEdt->HelpContext = 117;
        if ((WhereEduMiddleDBEdt->Text.Pos("Корелич")) ||
            (WhereEduMiddleDBEdt->Text.Pos("корелич")))
            WhereEduMiddleDBEdt->HelpContext = 107;
        if ((WhereEduMiddleDBEdt->Text.Pos("Лид")) ||
            (WhereEduMiddleDBEdt->Text.Pos("лид")))
            WhereEduMiddleDBEdt->HelpContext = 108;
        if ((WhereEduMiddleDBEdt->Text.Pos("Мост")) ||
            (WhereEduMiddleDBEdt->Text.Pos("мост")))
            WhereEduMiddleDBEdt->HelpContext = 109;
        if ((WhereEduMiddleDBEdt->Text.Pos("Новогруд")) ||
            (WhereEduMiddleDBEdt->Text.Pos("новогруд")))
            WhereEduMiddleDBEdt->HelpContext = 110;
        if ((WhereEduMiddleDBEdt->Text.Pos("Островец")) ||
            (WhereEduMiddleDBEdt->Text.Pos("островец")))
            WhereEduMiddleDBEdt->HelpContext = 111;
        if ((WhereEduMiddleDBEdt->Text.Pos("Ошмян")) ||
            (WhereEduMiddleDBEdt->Text.Pos("ошмян")))
            WhereEduMiddleDBEdt->HelpContext = 112;
        if ((WhereEduMiddleDBEdt->Text.Pos("Свислоч")) ||
            (WhereEduMiddleDBEdt->Text.Pos("свислоч")))
            WhereEduMiddleDBEdt->HelpContext = 113;
        if ((WhereEduMiddleDBEdt->Text.Pos("Слоним")) ||
            (WhereEduMiddleDBEdt->Text.Pos("слоним")))
            WhereEduMiddleDBEdt->HelpContext = 114;
        if ((WhereEduMiddleDBEdt->Text.Pos("Сморгон")) ||
            (WhereEduMiddleDBEdt->Text.Pos("сморгон")))
            WhereEduMiddleDBEdt->HelpContext = 115;
        if ((WhereEduMiddleDBEdt->Text.Pos("Щучин")) ||
            (WhereEduMiddleDBEdt->Text.Pos("щучин")))
            WhereEduMiddleDBEdt->HelpContext = 116;
        break;
    case 120: // Минск
        // Минская область
        if ((WhereEduMiddleDBEdt->Text.Pos("Березин")) ||
            (WhereEduMiddleDBEdt->Text.Pos("березин")))
            WhereEduMiddleDBEdt->HelpContext = 121;
        if ((WhereEduMiddleDBEdt->Text.Pos("Борисов")) ||
            (WhereEduMiddleDBEdt->Text.Pos("борисов")) ||
            (WhereEduMiddleDBEdt->Text.Pos("Жодино")) ||
            (WhereEduMiddleDBEdt->Text.Pos("жодино")))
            WhereEduMiddleDBEdt->HelpContext = 122;
        if ((WhereEduMiddleDBEdt->Text.Pos("Вилей")) ||
            (WhereEduMiddleDBEdt->Text.Pos("вилей")))
            WhereEduMiddleDBEdt->HelpContext = 123;
        if ((WhereEduMiddleDBEdt->Text.Pos("Воложин")) ||
            (WhereEduMiddleDBEdt->Text.Pos("воложин")))
            WhereEduMiddleDBEdt->HelpContext = 104;
        if ((WhereEduMiddleDBEdt->Text.Pos("Дзержинск")) ||
            (WhereEduMiddleDBEdt->Text.Pos("дзержинск")))
            WhereEduMiddleDBEdt->HelpContext = 125;
        if ((WhereEduMiddleDBEdt->Text.Pos("Клецк")) ||
            (WhereEduMiddleDBEdt->Text.Pos("клецк")))
            WhereEduMiddleDBEdt->HelpContext = 126;
        if ((WhereEduMiddleDBEdt->Text.Pos("Копыль")) ||
            (WhereEduMiddleDBEdt->Text.Pos("копыль")))
            WhereEduMiddleDBEdt->HelpContext = 127;
        if ((WhereEduMiddleDBEdt->Text.Pos("Круп")) ||
            (WhereEduMiddleDBEdt->Text.Pos("круп")))
            WhereEduMiddleDBEdt->HelpContext = 128;
        if ((WhereEduMiddleDBEdt->Text.Pos("Логойск")) ||
            (WhereEduMiddleDBEdt->Text.Pos("логойск")))
            WhereEduMiddleDBEdt->HelpContext = 129;
        if ((WhereEduMiddleDBEdt->Text.Pos("Любан")) ||
            (WhereEduMiddleDBEdt->Text.Pos("любан")))
            WhereEduMiddleDBEdt->HelpContext = 130;
        if ((WhereEduMiddleDBEdt->Text.Pos("Минский")) ||
            (WhereEduMiddleDBEdt->Text.Pos("минский")))
            WhereEduMiddleDBEdt->HelpContext = 131;
        if ((WhereEduMiddleDBEdt->Text.Pos("Молодечн")) ||
            (WhereEduMiddleDBEdt->Text.Pos("молодечн")))
            WhereEduMiddleDBEdt->HelpContext = 132;
        if ((WhereEduMiddleDBEdt->Text.Pos("Мядель")) ||
            (WhereEduMiddleDBEdt->Text.Pos("мядель")))
            WhereEduMiddleDBEdt->HelpContext = 133;
        if ((WhereEduMiddleDBEdt->Text.Pos("Несвиж")) ||
            (WhereEduMiddleDBEdt->Text.Pos("несвиж")))
            WhereEduMiddleDBEdt->HelpContext = 134;
        if ((WhereEduMiddleDBEdt->Text.Pos("Пухович")) ||
            (WhereEduMiddleDBEdt->Text.Pos("пухович")))
            WhereEduMiddleDBEdt->HelpContext = 135;
        if ((WhereEduMiddleDBEdt->Text.Pos("Слуцк")) ||
            (WhereEduMiddleDBEdt->Text.Pos("слуцк")))
            WhereEduMiddleDBEdt->HelpContext = 136;
        if ((WhereEduMiddleDBEdt->Text.Pos("Смолевич")) ||
            (WhereEduMiddleDBEdt->Text.Pos("смолевич")))
            WhereEduMiddleDBEdt->HelpContext = 137;
        if ((WhereEduMiddleDBEdt->Text.Pos("Солигорск")) ||
            (WhereEduMiddleDBEdt->Text.Pos("солигорск")))
            WhereEduMiddleDBEdt->HelpContext = 138;
        if ((WhereEduMiddleDBEdt->Text.Pos("Стар")) ||
            (WhereEduMiddleDBEdt->Text.Pos("стар")))
            // стародорожский
                WhereEduMiddleDBEdt->HelpContext = 139;
        if ((WhereEduMiddleDBEdt->Text.Pos("Столбц")) ||
            (WhereEduMiddleDBEdt->Text.Pos("столбц")))
            WhereEduMiddleDBEdt->HelpContext = 140;
        if ((WhereEduMiddleDBEdt->Text.Pos("Узд")) ||
            (WhereEduMiddleDBEdt->Text.Pos("узд")))
            // узденский
                WhereEduMiddleDBEdt->HelpContext = 141;
        if ((WhereEduMiddleDBEdt->Text.Pos("Червен")) ||
            (WhereEduMiddleDBEdt->Text.Pos("червен")))
            WhereEduMiddleDBEdt->HelpContext = 142;
        break;
    case 150: // Могилев
        // Могилевская область
        if ((WhereEduMiddleDBEdt->Text.Pos("Белынич")) ||
            (WhereEduMiddleDBEdt->Text.Pos("белынич")))
            WhereEduMiddleDBEdt->HelpContext = 151;
        if ((WhereEduMiddleDBEdt->Text.Pos("Бобруйск")) ||
            (WhereEduMiddleDBEdt->Text.Pos("бобруйск")))
            WhereEduMiddleDBEdt->HelpContext = 152;
        if ((WhereEduMiddleDBEdt->Text.Pos("Быхов")) ||
            (WhereEduMiddleDBEdt->Text.Pos("быхов")))
            WhereEduMiddleDBEdt->HelpContext = 153;
        if ((WhereEduMiddleDBEdt->Text.Pos("Глус")) ||
            (WhereEduMiddleDBEdt->Text.Pos("глус")))
            // глусский
                WhereEduMiddleDBEdt->HelpContext = 154;
        if ((WhereEduMiddleDBEdt->Text.Pos("Горецкий")) ||
            (WhereEduMiddleDBEdt->Text.Pos("горецкий")) ||
            (WhereEduMiddleDBEdt->Text.Pos("Горки")))
            WhereEduMiddleDBEdt->HelpContext = 155;
        if ((WhereEduMiddleDBEdt->Text.Pos("Дрибин")) ||
            (WhereEduMiddleDBEdt->Text.Pos("дрибин")))
            WhereEduMiddleDBEdt->HelpContext = 156;
        if ((WhereEduMiddleDBEdt->Text.Pos("Кировс")) ||
            (WhereEduMiddleDBEdt->Text.Pos("кировс")))
            WhereEduMiddleDBEdt->HelpContext = 157;
        if ((WhereEduMiddleDBEdt->Text.Pos("Климович")) ||
            (WhereEduMiddleDBEdt->Text.Pos("климович")))
            WhereEduMiddleDBEdt->HelpContext = 158;
        if ((WhereEduMiddleDBEdt->Text.Pos("Кличев")) ||
            (WhereEduMiddleDBEdt->Text.Pos("кличев")))
            WhereEduMiddleDBEdt->HelpContext = 159;
        if ((WhereEduMiddleDBEdt->Text.Pos("Костюкович")) ||
            (WhereEduMiddleDBEdt->Text.Pos("костюкович")))
            WhereEduMiddleDBEdt->HelpContext = 160;
        if ((WhereEduMiddleDBEdt->Text.Pos("Краснополь")) ||
            (WhereEduMiddleDBEdt->Text.Pos("краснополь")))
            WhereEduMiddleDBEdt->HelpContext = 161;
        if ((WhereEduMiddleDBEdt->Text.Pos("Кричев")) ||
            (WhereEduMiddleDBEdt->Text.Pos("кричев")))
            WhereEduMiddleDBEdt->HelpContext = 162;
        if ((WhereEduMiddleDBEdt->Text.Pos("Кругл")) ||
            (WhereEduMiddleDBEdt->Text.Pos("кругл")))
            // круглянский
                WhereEduMiddleDBEdt->HelpContext = 163;
        if ((WhereEduMiddleDBEdt->Text.Pos("Могилевский")) ||
            (WhereEduMiddleDBEdt->Text.Pos("могилевский")))
            WhereEduMiddleDBEdt->HelpContext = 164;
        if ((WhereEduMiddleDBEdt->Text.Pos("Мстислав")) ||
            (WhereEduMiddleDBEdt->Text.Pos("мстислав")))
            WhereEduMiddleDBEdt->HelpContext = 165;
        if ((WhereEduMiddleDBEdt->Text.Pos("Осипович")) ||
            (WhereEduMiddleDBEdt->Text.Pos("осипович")))
            WhereEduMiddleDBEdt->HelpContext = 166;
        if ((WhereEduMiddleDBEdt->Text.Pos("Славгород")) ||
            (WhereEduMiddleDBEdt->Text.Pos("славгород")))
            WhereEduMiddleDBEdt->HelpContext = 167;
        if ((WhereEduMiddleDBEdt->Text.Pos("Хотимск")) ||
            (WhereEduMiddleDBEdt->Text.Pos("хотимск")))
            WhereEduMiddleDBEdt->HelpContext = 168;
        if ((WhereEduMiddleDBEdt->Text.Pos("Чаус")) ||
            (WhereEduMiddleDBEdt->Text.Pos("чаус")))
            // чаусский
                WhereEduMiddleDBEdt->HelpContext = 169;
        if ((WhereEduMiddleDBEdt->Text.Pos("Чериков")) ||
            (WhereEduMiddleDBEdt->Text.Pos("чериков")))
            WhereEduMiddleDBEdt->HelpContext = 170;
        if ((WhereEduMiddleDBEdt->Text.Pos("Шклов")) ||
            (WhereEduMiddleDBEdt->Text.Pos("шклов")))
            WhereEduMiddleDBEdt->HelpContext = 171;
        break;
    default:
        WhereEduMiddleDBEdt->HelpContext = 10;
        break;
    } // end switch

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::SpecializDBLookupCmbBxExit(TObject * Sender) {
    // Выбор специализации
    NomGroupCmbBx->ItemIndex = -1;

    if (FormEduCmbBx->ItemIndex == -1 || FormEduCmbBx->Text == "")
    { // if проверка на вид обучения
        ShowMessage("Введите сначала форму получения образования!!!!");
        return;
    } // end if проверка на вид обучения
    if (SpecializDBLookupCmbBx->Text == "") { // if проверка на специализацию
        ShowMessage("Введите сначала направление специальности!!!!");
        return;
    } // end if проверка на специализацию

    // переменная для ввода параметра только выбранной специализации
    AnsiString sp = "." + SpecializDBLookupCmbBx->KeyValue;
    sp += ".";

    // открытие Query по параметрам вида обучения и специализации - выбираем нужные группы
    DM->QN_group->Close();
    DM->QN_group->ParamByName("FAC")->AsSmallInt = nom_fac;
    DM->QN_group->ParamByName("EDU")->AsSmallInt = FormEduCmbBx->ItemIndex;
    DM->QN_group->ParamByName("SPEC")->AsString = sp;
    DM->QN_group->Open();

    // открытие Query количества человек в каждой группе
    DM->QGroup_Count->Close();
    DM->QGroup_Count->ParamByName("N_FAC")->AsInteger = nom_fac;
    DM->QGroup_Count->Open();

    // очищаем номера групп
    NomGroupCmbBx->Clear();

    for (int i = 0; i < DM->QN_group->RecordCount; i++)
    { // for цикл по группам нужного вида обучения и специализации

        int kol = 0; // количество человек в группе
        Variant nnn = DM->QGroup_Count->Lookup("NOM_GROUP",
            DM->QN_groupNOM_GROUP->Value, "COUNT");
        if (!nnn.IsNull()) { // if нашли эту группу
            kol = nnn;
        } // end if нашли эту группу
        else
            kol = 0;
        if (kol < DM->QN_groupN_COUNT->Value)
        { // if проверяем на количество человек в группе, разрешенное и сравниваем с реальным
            NomGroupCmbBx->Items->Add(DM->QN_groupNOM_GROUP->Value);
        } // end if проверяем на количество человек в группе, разрешенное и сравниваем с реальным
        DM->QN_group->Next();
    } // end for цикл по группам нужного вида обучения и специализации

    if (ChangLog != 2)
        ChangLog = 1;

    // перечитываем КУ по выбору
    // Закомментировано в связи с отменой
    // TabSheet4Show(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Image1Click(TObject * Sender) {
    if (OpenPictureDialog1->Execute()) {
        try {
            DM->QAbitura->Edit();
        }
        catch (...) {
            DM->QAbitura->Insert();
        }

        Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
        pms->Clear();
        jp->Assign(Image1->Picture);
        jp->SaveToStream(pms);
        pms->Position = 0;
        DM->QFotoSignPHOTO->LoadFromStream(pms);

    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::FormCreate(TObject * Sender) {
    pms = new TMemoryStream();
    jp = new Jpeg::TJPEGImage();
    DM->QLangvich->Open();
    DM->QPersonalDocum->Open();
    ChangLog = 0;

    PageControl1->ActivePage = TabSheet5;

    NameBtn(); // вызов процедуры названия кнопок

}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::FormEduCmbBxExit(TObject * Sender) {
    // Выход из элемента выбора формы обучения
    NomGroupCmbBx->ItemIndex = -1;
    if (SpecializDBLookupCmbBx->Text == "" && DM->QAbitura->State == dsInsert &&
        FormEduCmbBx->Text != "") {
        // if поле направления специальности пустое, а формы обучения выбрана
        /// то перечитываем Query для отображения спец. из плана

        DM->QSpecializPlan_Priem->Close();
        DM->QSpecializPlan_Priem->ParamByName("VID_EDU")->AsSmallInt =
            FormEduCmbBx->ItemIndex;
        DM->QSpecializPlan_Priem->ParamByName("FAC")->AsSmallInt = nom_fac;
        DM->QSpecializPlan_Priem->Open();

    }
    if (SpecializDBLookupCmbBx->Text != "" && DM->QAbitura->State == dsInsert &&
        NomGroupCmbBx->Text == "") {
        // if поле направления специальности выбрана
        // и есть номер группы
        SpecializDBLookupCmbBxExit(this);
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::SpeedButton1Click(TObject * Sender)                // Вызов формы по среднему баллу аттестата
{
    if (press != 2)
        MsgEdit ();

    SredBalForm =  new TSredBalForm(this);
    SredBalForm -> ShowModal();

//    DM->QEducation->Close();
//    DM->QEducation->Open();
//    EducationForm = new TEducationForm(this);
//    EducationForm->ShowModal();
//    DM->QEducation->Insert();
    //DM->QEducationNOMER_AB->Value = DM->QAbituraNOMER_AB->Value;
}
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::SpeedButton2Click(TObject * Sender)                // Вызов формы по добавления сертификатов или расчета среднего балла
{
    if (press != 2)
        MsgEdit ();
    #ifndef ADD_SERTIFICATE_INSTEAD_COUNT_MIDDLE_BALL
    SredBalForm    =  new TSredBalForm (this);
    SredBalForm    -> ShowModal ();
    #else
    SertificatForm =  new TSertificatForm (this);
    SertificatForm -> ShowModal ();
    #endif  // ! ADD_SERTIFICATE_INSTEAD_COUNT_MIDDLE_BALL
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::FormCanResize(TObject * Sender, int &NewWidth,
    int &NewHeight, bool &Resize) {

    /* SaveBtBtn->Top = 8;
     CancelBtBtn->Top = 8;
     ExitBitBtn->Top=8;
     PrintBtBtn->Top=8; */
    // DBNavigator4 ->Top=AbiturForm->Height-62;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::ReInsideFacBtBtnClick(TObject * Sender)
{ // переподал документы
    PressBtn(4);

    Undo_Ab_1Form = new TUndo_Ab_1Form(this);
    Undo_Ab_1Form->Caption = "Переподача документов";
    Undo_Ab_1Form->Edit2->Text = DM->QAbituraNOM_DELA->Value; // № дела
    Undo_Ab_1Form->ComboBox1->ItemIndex = DM->QAbituraVID_EDU->Value;
    // вид обучения
    Undo_Ab_1Form->DBLookupComboBox1->KeyValue = DM->QAbituraN_SPECIALIZ->Value;
    // Категория абитуриента
    Undo_Ab_1Form->CategoryAbCmbBx->ItemIndex = DM->QAbituraCATEGORY_AB->Value;
    Undo_Ab_1Form->SngFrgCmbBx->ItemIndex = DM->QAbituraCATEGORY_IF->Value;

    // Специализация
    // Undo_Ab_1Form->ComboBox2->Text=DM->QAbituraNOM_GROUP->Value;  //№ группы
    Undo_Ab_1Form->ComboBox2->Items->Add(DM->QAbituraNOM_GROUP->Value);
    Undo_Ab_1Form->ComboBox2->ItemIndex = 0;
    Undo_Ab_1Form->KonkursCmbBx->ItemIndex = DM->QAbituraKONKURS->Value;
    // Конкурс

    Undo_Ab_1Form->DBLookupComboBox2->KeyValue = DM->QAbituraN_VID_SPORT->Value;
    // Вид спорта
    Undo_Ab_1Form->DBLookupComboBox3->KeyValue =
        DM->QAbituraN_SPORT_CATEGORY->Value; // Разряд

    if (DM->QAbituraN_CK->Value) { // if есть целевой контракт
        Undo_Ab_1Form->Label29->Visible = true;
        Undo_Ab_1Form->DBLookupComboBox4->Visible = true;
        Undo_Ab_1Form->DBLookupComboBox4->KeyValue = DM->QAbituraN_CK->Value;
        // Откуда КЦ
    } // end if есть целевой контракт
    else { // else нет контракта
        Undo_Ab_1Form->Label29->Visible = false;
        Undo_Ab_1Form->DBLookupComboBox4->Visible = false;
        Undo_Ab_1Form->DBLookupComboBox4->KeyValue = -1; // Откуда КЦ
    } // end else нет контракта

    Undo_Ab_1Form->Label4->Caption =
        SQLTimeStampToDateTime(DM->QAbituraDATE_PRIEM->Value);
    // Дата приема документов
    Undo_Ab_1Form->ShowModal();

}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Vk1Click(TObject * Sender)
{ // Изменение преимуществ при зачислении после добавления абитуриента
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::ApplicationEvents1Message(tagMSG & Msg,
    bool &Handled) {
    // организовать нормальную работу мышиного колесика в DBGrid

    if (DBGrid1->Focused() && AbiturForm->Active && TabSheet1->Focused()) {
        if (Msg.message == WM_MOUSEWHEEL) {
            Msg.message = WM_KEYDOWN;
            Msg.lParam = 0;
            short int i = HIWORD(Msg.wParam);
            Msg.wParam = (i > 0) ? VK_UP : VK_DOWN;
            Handled = false;
        }
    }

}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::PersonNumDBEdtExit (TObject * Sender)              // WARNING: BE CAREFUL!!!! Works only for personal numbers until 2012.
{
    #ifdef DEEP_CHECK_PERSONAL_NUMBER
    if (DM -> QAbitura -> State == dsInsert)                                    // режим добавления студента
    {

        AnsiString lich_nomer = PersonNumDBEdt -> Text;

        if (lich_nomer != "")
        {
            AnsiString
                dat  = "",
                temp =
                    lich_nomer.SubString (
                        1,                                                      // start character position (from 1)
                        1                                                       // number of characters starting at position
                    );

            // if (    StrToInt (temp) < 3
            //      || StrToInt (temp) > 7
            //    )
            //     ShowMessage (
            //         "ВНИМАНИЕ!\n\n"                     \
            //         "В личном номере неверно указан "       \
            //         "регион рождения!\n\n"                   \
            //         "Пример: 3------------- (от 3 до 7)"
            //     );

            // if (StrToInt (temp) == 3)
            // {
            //     PolDBCmbBx -> ItemIndex = 0;

            //     DM -> QAbituraPOL -> Value = "М";
            // }
            // if (StrToInt (temp) == 4)
            // {
            //     PolDBCmbBx -> ItemIndex = 1;

            //     DM -> QAbituraPOL -> Value = "Ж";
            // }


            try
            {
                int x = 0;

                if (    lich_nomer.SubString (1, 1) == 3                        // личный номер
                     || lich_nomer.SubString (1, 1) == 4
                   )
                {
                    temp =                                                      // хранит день
                        lich_nomer.SubString (
                            2,
                            2
                        );
                    x    = temp.ToInt ();

                    if (x < 1 || x > 31)
                        return
                            ShowMessage (
                                "ВНИМАНИЕ!\n\n"                         \
                                "В личном номере неверно указан "       \
                                "день рождения!\n\n"                    \
                                "Пример: -25----------- (от 1 до 31)"
                            );
                    else
                        dat += temp + ".";

                    temp = lich_nomer.SubString (4, 2);                         // месяц
                    x = temp.ToInt ();
                    if (x < 1 || x > 12)
                        return
                            ShowMessage (
                                "ВНИМАНИЕ!\n\n"                         \
                                "В личном номере неверно указан "       \
                                "месяц рождения!\n\n"                   \
                                "Пример: ---05--------- (от 1 до 12)"
                            );
                    else
                        dat += temp + ".";

                    temp = lich_nomer.SubString (6, 2);                         // год
                    x = temp.ToInt ();

                    if (x < 35 || x > 99)
                        return
                            ShowMessage (
                                "ВНИМАНИЕ!\n\n"                         \
                                "В личном номере неверно указан "       \
                                "год рождения!\n\n"                   \
                                "Пример: -----06------- (от 1 до 99)"
                            );
                    else
                        dat += "19" + temp;

                    BirthdayDBDateEdit -> Text = StrToDateTime (dat);
                    DM -> QAbituraDATE_R -> Text = BirthdayDBDateEdit -> Text;
                }
            }
            catch (...)
            {
                ShowMessage (
                    "Неверные данные в личном номере!"
                );
            }
        }
    }
    #endif  // DEEP_CHECK_PERSONAL_NUMBER
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::FamDBEdtExit(TObject * Sender) { // FAM
    if (DM->QAbitura->State == dsInsert) { // if в режиме добавления студента
        // Обработка ФИО с приведением его в нужный формат
        // DMStat->FIO(AnsiString text, TQuery* q, AnsiString pole)
        DMStat->FIO(FamDBEdt->Text, DM->QAbitura, "FAM");
        FamDBEdt->Text = DM->QAbituraFAM->Value;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::NameDBEdtExit(TObject * Sender) { // NAME
    if (DM->QAbitura->State == dsInsert) { // if в режиме добавления студента
        // Обработка ФИО с приведением его в нужный формат
        // DMStat->FIO(AnsiString text, TQuery* q, AnsiString pole)
        DMStat->FIO(NameDBEdt->Text, DM->QAbitura, "NAME");
        NameDBEdt->Text = DM->QAbituraNAME->Value;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OtchDBEdtExit(TObject * Sender) { // OTCH
    if (DM->QAbitura->State == dsInsert) { // if в режиме добавления студента
        // Обработка ФИО с приведением его в нужный формат
        // DMStat->FIO(AnsiString text, TQuery* q, AnsiString pole)
        DMStat->FIO(OtchDBEdt->Text, DM->QAbitura, "OTCH");
        OtchDBEdt->Text = DM->QAbituraOTCH->Value;
    }
}
// ---------------------------------------------------------------------------

// ЗАПРЕТ ИЗМЕНЕНИЯ ДАННЫХ!!! ПОСЛЕ УСТАНОВКИ В БД BLOCK=1
// --------------------------------------------------------------------------
void __fastcall TAbiturForm::Ch5Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Ch6Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Ch3Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Ch7Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Ch8Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Ch9Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::PriceRdGrpEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::KonkursRdGrpEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::EducatCmbBxEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::DBGrid3Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::NomGroupCmbBxEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Vk1Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Vk4Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Vk6Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Vk5Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Wo1Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Wo2Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Wo3Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Wo4Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Wo5Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr1Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr4Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr21Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr2Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr3Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr5Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr6Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr7Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr19Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr8Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr9Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr10Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr11Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr12Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr13Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr23Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr17Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr14Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr22Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr20Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr18Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr16Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Pr15Enter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clictNotConcoursEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistAddAwardsEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistNotExamsEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistGIACEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistddEnrollingEnter(TObject * Sender) {
    if (press != 2)
        MsgEdit();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clictNotConcoursClickCheck(TObject * Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistNotExamsClickCheck(TObject * Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistAddAwardsClickCheck(TObject * Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistddEnrollingClickCheck(TObject * Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::clistGIACClickCheck(TObject * Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::StagSpecDBEdtEhExit(TObject * Sender) {
    if (StagSpecDBEdtEh->Text == "   ") {
        StagSpecDBEdtEh->Text = 0;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TabSheet4Show(TObject * Sender) {
    // При отображении вкладки "Выбор КУ"
    if (nom_fac != 4) {

        RdGrpCtrlExerc1->Items->Clear();
        RdGrpCtrlExerc2->Items->Clear();
        RdGrpCtrlExerc3->Items->Clear();

        int KuGrp, KuAb; // переменные для считывания ID КУ


        if (    DBEditSpec -> Text != ""                                        // запрос КУ
             && DBEditPol  -> Text != ""
           )
        {

            for (int j = 0;                                                     // цикл по блокам КУ
                     j < 3;
                     ++j
                )
            {
                DM -> QExerc_Grp -> Close();

                DM -> QExerc_Grp -> ParamByName ("n_specializ") -> AsInteger =
                    StrToInt(DBEditSpec->Text);
                DM->QExerc_Grp->ParamByName("pol")->AsAnsiString = Caption =
                    DBEditPol->Text;
                DM->QExerc_Grp->ParamByName("num_exerc_grp")->AsInteger = j + 1;
                DM->QExerc_Grp->Open();

                int num_rec = DM -> QExerc_Grp -> RecordCount;                  // количество КУ в выбранном блоке КУ

                switch (j)                                                      // выбор по блокам КУ
                {
                    case 0:
                            for (int i = 0;
                                     i < num_rec;
                                     ++i)
                            {
                                RdGrpCtrlExerc1 -> Items ->
                                    Add (
                                        DM -> QExerc_GrpNAME_EXERC -> AsString
                                    );
                                DM -> QFindAbiturExerc -> Close ();

                                DM -> QFindAbiturExerc ->
                                    ParamByName ("NOMER_AB") ->AsString =
                                        DBEditNumAb -> Text;
                                DM -> QFindAbiturExerc ->
                                    ParamByName ("NUM_EXERC_GRP") -> AsInteger =
                                        j + 1;
                                DM -> QFindAbiturExerc -> Open ();

                                KuGrp = DM -> QExerc_GrpID_EXERC -> AsInteger;
                                KuAb  = DM -> QFindAbiturExercID_EXERC -> AsInteger;

                                mas_sel_exerc[j][i] = KuGrp;

                                if (KuGrp == KuAb)
                                    RdGrpCtrlExerc1 -> ItemIndex = i;

                                DM -> QFindAbiturExerc -> Close();
                                DM -> QExerc_Grp -> Next();
                            }
                        break;
                    case 1:
                            for (int i = 0;
                                     i < num_rec;
                                     ++i)
                            {
                                RdGrpCtrlExerc2 -> Items ->
                                    Add (
                                        DM -> QExerc_GrpNAME_EXERC -> AsString
                                    );
                                DM -> QFindAbiturExerc -> Close ();
                                DM -> QFindAbiturExerc ->
                                    ParamByName ("NOMER_AB") -> AsString =
                                        DBEditNumAb -> Text;
                                DM -> QFindAbiturExerc ->
                                    ParamByName ("NUM_EXERC_GRP") -> AsInteger =
                                        j + 1;
                                DM -> QFindAbiturExerc -> Open ();

                                KuGrp = DM -> QExerc_GrpID_EXERC -> AsInteger;
                                KuAb  = DM -> QFindAbiturExercID_EXERC -> AsInteger;

                                mas_sel_exerc[j][i] = KuGrp;

                                if (KuGrp == KuAb)
                                    RdGrpCtrlExerc2 -> ItemIndex = i;

                                DM -> QFindAbiturExerc -> Close ();
                                DM -> QExerc_Grp -> Next ();
                            }
                        break;
                    case 2:
                            for (int i = 0;
                                     i < num_rec;
                                     ++i
                                )
                            {
                                RdGrpCtrlExerc3 -> Items ->
                                    Add (
                                        DM -> QExerc_GrpNAME_EXERC -> AsString
                                    );
                                DM -> QFindAbiturExerc -> Close();
                                DM -> QFindAbiturExerc ->
                                    ParamByName("NOMER_AB") -> AsString =
                                        DBEditNumAb -> Text;
                                DM -> QFindAbiturExerc ->
                                    ParamByName ("NUM_EXERC_GRP") -> AsInteger =
                                    j + 1;
                                DM -> QFindAbiturExerc -> Open ();

                                KuGrp = DM -> QExerc_GrpID_EXERC -> AsInteger;
                                KuAb  = DM -> QFindAbiturExercID_EXERC -> AsInteger;

                                mas_sel_exerc[j][i] = KuGrp;

                                if (KuGrp == KuAb)
                                    RdGrpCtrlExerc3 -> ItemIndex = i;

                                DM -> QFindAbiturExerc -> Close ();
                                DM -> QExerc_Grp -> Next ();
                            }
                        break;

                    default: ;
                }
            }
        }

        DM->QExerc_Grp->Close();
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::BitBtn9Click(TObject *Sender) {
    DM->QRep_Sel_Exerc->Close();
    DM->QRep_Sel_Exerc->ParamByName("NOMER_AB")->AsString = DBEditNumAb->Text;
    DM->QRep_Abitura->Close();
    DM->QRep_Abitura->ParamByName("NOMER_AB")->AsString = DBEditNumAb->Text;
    DM->QRep_Sel_Exerc->Open();
    DM->QRep_Abitura->Open();
    DM->QKod_Spec->Close();
    DM->QKod_Spec->ParamByName("N_SPECIALIZ")->AsInteger =
        StrToInt(DBEditSpec->Text);
    DM->QKod_Spec->Open();
    DM->QKod_Fac->Close();
    DM->QKod_Fac->ParamByName("N_FAC")->AsInteger = nom_fac;
    DM->QKod_Fac->Open();
    FormRepSelExerc->frxRep_Sel_Exerc->ShowReport();
    DM->QRep_Sel_Exerc->Close();
    DM->QRep_Abitura->Close();
    DM->QKod_Spec->Close();
    DM->QKod_Fac->Close();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::TabSheet4Enter(TObject *Sender) {
    /* SaveBtBtn->Enabled = true;
     CancelBtBtn->Enabled = true;
     SaveBtBtn->Visible = true;
     CancelBtBtn->Visible = true; */
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::RdGrpSchoolClick(TObject *Sender) {
    // Изменение вида учебного заведения
    if (DM->QAbitura->State == dsBrowse)
        DM->QAbitura->Edit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::RGrpVillageClick(TObject *Sender) {
    // Изменение город/село
    if (DM->QAbitura->State == dsBrowse)
        DM->QAbitura->Edit();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::CategoryAbCmbBxChange(TObject *Sender) {
    bool CategoryAbChange = false;
    // Изменение категории абитуриента
    if (ChangLog == 0) {
        if (MessageDlg("Изменение данного параметра повлечёт отметку о возврате документов\n \
         и добавлению новой записи в журнале учёта абитуриентов.\nВы хотите продолжить?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            CategoryAbChange = true;
        }
    }
    else
        CategoryAbChange = true;
    if (CategoryAbChange == true) {
        if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
            DM->QAbitura->Edit();
        } // end if dsBrowse

        // Условия поступления
        SngFrgCmbBx->ItemIndex = -1;
        EducatCmbBx->ItemIndex = -1;
        TermEduCmbBx->ItemIndex = -1;
        PriceCmbBx->ItemIndex = -1;
        KonkursCmbBx->ItemIndex = -1;
        SngFrgCmbBx->Enabled = true;
        switch (CategoryAbCmbBx->ItemIndex) {
        case 0: // Беларусь
            {
                pr_KategIf = 0; // Беларусь
                SitizenshipDBLkCmbBx->KeyValue = 22;
                DocumDBLkCmbBx->KeyValue = 1;
                SngFrgCmbBx->ItemIndex = 0;
                SngFrgCmbBx->Visible = false;
                SngFrgCmbBx->ItemIndex = 0;
                SngFrgLbl->Visible = false;
                EducatCmbBx->Enabled = true;
                EducatCmbBxChange(this);
                break;
            }
        case 1: // Иностранцы
            {
                pr_KategIf = 1; // Иностранцы
                SitizenshipDBLkCmbBx->KeyValue = NULL;
                DocumDBLkCmbBx->KeyValue = 2;
                SngFrgCmbBx->Visible = true;
                SngFrgCmbBx->ItemIndex = 1;
                SngFrgLbl->Visible = true;
                SngFrgCmbBxChange(this);
                break;
            }
        case 2: // СНГ
            {
                pr_KategIf = 2; // СНГ
                SitizenshipDBLkCmbBx->KeyValue = NULL;
                DocumDBLkCmbBx->KeyValue = NULL;
                SngFrgCmbBx->Visible = true;
                SngFrgLbl->Visible = true;
                SngFrgCmbBxChange(this);
                break;
            }
        case 3: // ДНР/ЛНР
            {
                pr_KategIf = 2; // СНГ
                SitizenshipDBLkCmbBx->KeyValue = NULL;
                DocumDBLkCmbBx->KeyValue = NULL;
                SngFrgCmbBx->Visible = true;
                SngFrgLbl->Visible = true;
                SngFrgCmbBxChange(this);
                break;
            }
        default:
            SngFrgCmbBx->Enabled = false;
        }
        if (ChangLog != 2)
            ChangLog = 1;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::TermEduCmbBxChange(TObject *Sender) {
    bool TermEduChange = false;
    // Изменение срока получения образования
    if (ChangLog == 0) {
        if (MessageDlg("Изменение данного параметра повлечёт отметку о возврате документов\n \
         и добавлению новой записи в журнале учёта абитуриентов.\nВы хотите продолжить?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            TermEduChange = true;
        }
    }
    else
        TermEduChange = true;
    if (TermEduChange == true) {
        if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
            DM->QAbitura->Edit();
        } // end if dsBrowse

        PriceCmbBx->ItemIndex = -1;
        KonkursCmbBx->ItemIndex = -1;
        PriceCmbBx->Items->Clear();
        PriceCmbBx->Items->Add("бюджет");
        PriceCmbBx->Items->Add("за оплату");

        if ((pr_KategIf == 1) && (EducatCmbBx->ItemIndex == 3)) {
            // ИГ + ВО = только за оплату
            PriceCmbBx->ItemIndex = 1;
            PriceCmbBx->Enabled = false;
        }
        else {
            PriceCmbBx->ItemIndex = -1;
            if (TermEduCmbBx->ItemIndex > -1)
                PriceCmbBx->Enabled = true;
            else
                PriceCmbBx->Enabled = false;
        }

        PriceCmbBxChange(this);
        if (ChangLog != 2)
            ChangLog = 1;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::PriceCmbBxChange(TObject *Sender) {
    bool PriceChange = false;
    // Изменение формы оплвты
    if (ChangLog == 0) {
        if (MessageDlg("Изменение данного параметра повлечёт отметку о возврате документов\n \
         и добавлению новой записи в журнале учёта абитуриентов.\nВы хотите продолжить?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            PriceChange = true;
        }
    }
    else
        PriceChange = true;
    if (PriceChange == true) {
        if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
            DM->QAbitura->Edit();
        } // end if dsBrowse

        // Конкурс
        KonkursCmbBx->ItemIndex = -1;
        KonkursCmbBx->Items->Clear();
        KonkursCmbBx->Items->Add("общий");
        KonkursCmbBx->Items->Add("без вступительных испытаний");
        // KonkursCmbBx->Items->Add("вне конкурса");
        if (PriceCmbBx->ItemIndex > -1)
            KonkursCmbBx->Enabled = true;
        else
            KonkursCmbBx->Enabled = false;

        int pr_edu;
        switch (EducatCmbBx->ItemIndex) {
        case 0: // СО
            {
                pr_edu = 0;
                break;
            }
        case 1: // ССО
            {
                pr_edu = 0;
                break;
            }
        case 2: // незаконченное ВО
            {
                pr_edu = 1;
                break;
            }
        case 3: // ВО
            {
                pr_edu = 1;
                break;
            }
        case 4: // ПТУ
            {
                pr_edu = 0;
                break;
            }
        }
        switch (pr_KategIf) {
            // Условия поступления
        case 0: // РБ
            {
                switch (pr_edu) {
                    // Образование
                case 0: // СО/ССО
                    {
                        switch (TermEduCmbBx->ItemIndex) {
                            // Срок получения образования
                        case 0: // полный
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("вне конкурса");
                                        KonkursCmbBx->Items->Add("целевой");
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("вне конкурса");
                                        break;
                                    }
                                }
                                break;
                            }
                        case 1: // сокращённый 2 курс
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("вне конкурса");
                                        KonkursCmbBx->Items->Add("целевой");
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("вне конкурса");
                                        break;
                                    }
                                }
                                break;
                            }
                        case 2: // сокращённый 3 курс
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("вне конкурса");
                                        KonkursCmbBx->Items->Add("целевой");
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("вне конкурса");
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                case 1: // ВО
                    {
                        switch (TermEduCmbBx->ItemIndex) {
                            // Срок получения образования
                        case 0: // 1-й курс
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("вне конкурса");
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("вне конкурса");
                                        break;
                                    }
                                }
                                break;
                            }
                        case 1: // 2-1 и выше
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        KonkursCmbBx->ItemIndex = 1; // БВИ
                                        KonkursCmbBx->Enabled = false;
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        KonkursCmbBx->ItemIndex = 1; // БВИ
                                        KonkursCmbBx->Enabled = false;
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        case 1: // Иностранцы
            {
                switch (pr_edu) {
                    // Образование
                case 0: // СО/ССО
                    {
                        switch (TermEduCmbBx->ItemIndex) {
                            // Срок получения образования
                        case 0: // полный
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        KonkursCmbBx->ItemIndex = 0; // общий
                                        KonkursCmbBx->Enabled = false;
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        break;
                                    }
                                }
                                break;
                            }
                        case 1: // сокращённый 2 курс
                        case 2: // сокращённый 3 курс
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                case 1: // ВО
                    {
                        switch (TermEduCmbBx->ItemIndex) {
                            // Срок получения образования
                        case 0: // 1-й курс
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        break;
                                    }
                                }
                                break;
                            }
                        case 1: // 2-1 и выше
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        case 2: // СНГ
            {
                switch (pr_edu) {
                    // Образование
                case 0: // СО/ССО
                    {
                        switch (TermEduCmbBx->ItemIndex) {
                            // Срок получения образования
                        case 0: // полный
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("вне конкурса");
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("вне конкурса");
                                        break;
                                    }
                                }
                                break;
                            }
                        case 1: // сокращённый 2 курс
                        case 2: // сокращённый 3 курс
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                case 1: // ВО
                    {
                        switch (TermEduCmbBx->ItemIndex) {
                            // Срок получения образования
                        case 0: // 1-й курс
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("вне конкурса");
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        KonkursCmbBx->Items->Add
                                        ("вне конкурса");
                                        break;
                                    }
                                }
                                break;
                            }
                        case 1: // 2-1 и выше
                            {
                                switch (PriceCmbBx->ItemIndex) {
                                    // Оплата
                                case 0: // бюджет
                                    {
                                        KonkursCmbBx->ItemIndex = 1; // БВИ
                                        KonkursCmbBx->Enabled = false;
                                        break;
                                    }
                                case 1: // за оплату
                                    {
                                        KonkursCmbBx->ItemIndex = 1; // БВИ
                                        KonkursCmbBx->Enabled = false;
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }

        KonkursCmbBxChange(this);
        if (ChangLog != 2)
            ChangLog = 1;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::TabSheet5Show(TObject *Sender) {
    // переход на закладку ПОДАЧА ДОКУМЕНТОВ
    /* ExitBitBtn->Enabled = true;
     ExitBitBtn->Visible = true;
     SaveBtBtn->Enabled = false;
     CancelBtBtn->Enabled = false;
     SaveBtBtn->Visible = false;
     CancelBtBtn->Visible = false; */
    FIOReBitBtn->Caption = "";
    FIOSearchEdtChange(this);
    AbiturForm->Height = 700;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::FIOSearchEdtChange(TObject *Sender) {
    DM->FIOSearchQr->Close();
    // DM->FIOSearchQr->ParamByName("fio")->AsString = FIOSearchEdt->Text;
    DM->FIOSearchQr->ParamByName("n_fac")->AsSmallInt = nom_fac;
    DM->FIOSearchQr->Open();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::ReLoadAbiturPhoto() {
    // Выводим нужное фото
    TMemoryStream* pms;
    Jpeg::TJPEGImage *jp;

    // Вывод фото
    if (!(TBlobField*)DM->FIOSearchQrPHOTO->IsNull) {
        pms = new TMemoryStream;
        jp = new TJPEGImage;
        DM->FIOSearchQrPHOTO->SaveToStream(pms);
        pms->Seek(0, 0);
        FIOSearchPhImg->Picture->Graphic = jp;
        FIOSearchPhImg->Picture->Graphic->LoadFromStream(pms);
        FIOSearchPhImg->Visible = True;
        delete pms;
        delete jp;
        if ((FIOSearchPhImg->Picture->Width == 0) ||
            (FIOSearchPhImg->Picture->Height == 0))
            FIOSearchPhImg->Picture = NULL;
    }
    else
        FIOSearchPhImg->Picture = NULL;
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::DBGrid2DblClick(TObject *Sender) {
    int r;

    DM->QAbitura->Close();
    DM->QAbitura->SQL->Clear();
    DM->QAbitura->SQL->Add("SELECT ADDRESS_BEFORE, ADDRESS_LIFE, ADDRESS_MAMA, \
            ADDRESS_PAPA, CATEGORY_AB, CATEGORY_IF, CITIZENSHIP, \
            D_PRIKAZ_INCLUDE, DATE_PRIEM, DATE_R, DATE_V, DATE_VOZVRAT, \
            EDUCATION, FAM, GRAGDAN, KONKURS, MAMA, MIDDLE_BALL, \
            N_CENTRE, N_CK, N_FAC, N_FOUND, N_LANGVICH, N_PRIKAZ_INCLUDE, \
            N_REGION, N_SPEC, N_SPECIALIZ, N_SPORT_CATEGORY, N_VID_SPORT, \
            NAME, NAME_EDU_MIDDLE, NAME_EDU_SPEC, NOM_ATTEST, NOM_DELA, \
            NOM_DIPLOM, NOM_GROUP, NOMER_AB, ORGAN_V, OTCH, PAPA, PASPORT, \
            PERSONAL_NOMER, PHONE, PLACE_R, POL, PRICE, RUS_BEL, STAG, \
            STAG_SPEC, STATUS, SUM_BALL, TERM_EDU, TOWN_VILLAGE, TYPE_SCHOOL, \
            VID_EDU, WHEN_EDU_MIDDLE, WHEN_EDU_SPEC, WHERE_EDU_MIDDLE, \
            WHERE_EDU_SPEC, WORK_BEFORE, WORK_MAMA, WORK_PAPA, ID_TYPE, DATE_OK, \
            DISABLED, STREET, HOUSE, FLAT, POSTCODE FROM ABITURA \
        WHERE (N_FAC=:N_FAC) AND (STATUS=0 or STATUS=6) ORDER BY FAM, NAME, OTCH"
        );
    DM->QAbitura->ParamByName("N_FAC")->AsInteger = nom_fac;
    DM->QAbitura->Open();

    // двойной клик по абитуриенту из списка от декана
    // декан разрешил сохраненить в ABITURA
    // !!! Переподача? Донёс? Новый?
    // сравнить параметры? какие?

    FIOSearchEdt->Text = DM->FIOSearchQrFIO->AsString;
    DM->ID_from_QUEUE = DM->FIOSearchQrID_AB->Value;
    // DM->FIOSearchQrFAM->AsString + " " +
    // DM->FIOSearchQrNAME->AsString + " " + DM->FIOSearchQrOTCH->AsString;

    DM->AbiturCompQr->Close();
    DM->AbiturCompQr->ParamByName("id_ab_queue")->Value = DM->ID_from_QUEUE;
    DM->AbiturCompQr->Open();
    if (DM->AbiturCompQrNOMER_AB->Value > 0) { // абитуриент уже есть в ABITURA
        Set<TLocateOption, 0, 1>flags;
        // flags << loCaseInsensitive << loPartialKey;
        DM->QAbitura->Locate("NOMER_AB", DM->AbiturCompQrNOMER_AB->Value,
            flags);
        if (DM->QAbituraNOMER_AB->Value != DM->AbiturCompQrNOMER_AB->Value) {
            ShowMessage(
                "Произошла ошибка при выборе абитуриента!\nОБРАТИТЕСЬ К ПРОГРАММИСТУ!");
        }
        else {
            if ((DM->FIOSearchQrN_FAC->Value == DM->AbiturCompQrN_FAC->Value) &&
                (DM->FIOSearchQrVID_EDU->Value ==
                DM->AbiturCompQrVID_EDU->Value) &&
                (DM->FIOSearchQrN_SPECIALIZ->Value ==
                DM->AbiturCompQrN_SPECIALIZ->Value) &&
                (DM->FIOSearchQrN_SPEC->Value == DM->AbiturCompQrN_SPEC->Value)
                && (DM->FIOSearchQrVID_EDU->Value ==
                DM->AbiturCompQrVID_EDU->Value) &&
                (DM->FIOSearchQrCATEGORY_AB->Value ==
                DM->AbiturCompQrCATEGORY_AB->Value) &&
                (DM->FIOSearchQrCATEGORY_IF->Value ==
                DM->AbiturCompQrCATEGORY_IF->Value) &&
                (DM->FIOSearchQrCATEGORY_EDU->Value ==
                DM->AbiturCompQrEDUCATION->Value) &&
                (DM->FIOSearchQrTERM_EDU->Value ==
                DM->AbiturCompQrTERM_EDU->Value) &&
                (DM->FIOSearchQrPRICE->Value == DM->AbiturCompQrPRICE->Value) &&
                (DM->FIOSearchQrKONKURS->Value ==
                DM->AbiturCompQrKONKURS->Value) &&
                (DM->AbiturCompQrSTATUS->Value != 6)) {
                // !!!изменения незначительны - без записи в журнал
                // призанк записи в журнал - в 0
                ChangLog = -1;
            }
            else {
                ChangLog = 1;
            }
            // Set<TLocateOption, 0, 1>flags;

            // ниже - то что вызывается при двойном клике в полном списке

            PageControl1->ActivePage = TabSheet2;
            RefreshControl();

            if (DM->QAbitura->State == dsBrowse)
                DM->QAbitura->Edit();

            // -----------------------------------------
            if (ChangLog == 1) {
                // из закладки ПОДАЧА ДОКУМЕНТОВ
                // Форма получения образования
                FormEduCmbBx->ItemIndex = DM->FIOSearchQrVID_EDU->AsInteger;
                // Направление специальности
                DM->QSpecializPlan_Priem->Close();
                DM->QSpecializPlan_Priem->ParamByName("VID_EDU")->AsSmallInt =
                    FormEduCmbBx->ItemIndex;
                DM->QSpecializPlan_Priem->ParamByName("FAC")->AsSmallInt =
                    nom_fac;
                DM->QSpecializPlan_Priem->Open();
                SpecializDBLookupCmbBx->KeyValue =
                    DM->FIOSearchQrN_SPECIALIZ->AsInteger;
                SpecializDBLookupCmbBx->Enabled = true;
                // Категория абитуриента
                CategoryAbCmbBx->ItemIndex =
                    DM->FIOSearchQrCATEGORY_AB->AsInteger;
                // Категория поступления
                if (DM->FIOSearchQrCATEGORY_IF->Value > -1)
                    SngFrgCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_IF->Value;
                else
                    SngFrgCmbBx->ItemIndex = -1;
                if (SngFrgCmbBx->ItemIndex == 0) {
                    SngFrgCmbBx->Visible = false;
                    SngFrgLbl->Visible = false;
                }
                else {
                    SngFrgCmbBx->Visible = true;
                    SngFrgLbl->Visible = true;
                }

                int CATEGORY_EDU_tmp = DM->FIOSearchQrCATEGORY_EDU->AsInteger;
                int TERM_EDU_tmp = DM->FIOSearchQrTERM_EDU->AsInteger;
                int PRICE_tmp = DM->FIOSearchQrPRICE->AsInteger;
                int KONKURS_tmp = DM->FIOSearchQrKONKURS->AsInteger;

                // EducatCmbBx->OnChange(this);

                // Образование
                EducatCmbBx->ItemIndex = CATEGORY_EDU_tmp;
                EducatCmbBx->Enabled = true;
                // Срок получения образования
                if ((CATEGORY_EDU_tmp == 2) || (CATEGORY_EDU_tmp == 3)) {
                    Label64->Caption = "Курс поступления:";
                    TermEduCmbBx->ItemIndex = TERM_EDU_tmp - 3;
                }
                else {
                    Label64->Caption = "Срок получения образования:";
                    TermEduCmbBx->ItemIndex = TERM_EDU_tmp;
                }
                TermEduCmbBx->Enabled = true;
                // Форма оплаты
                PriceCmbBx->ItemIndex = PRICE_tmp;
                PriceCmbBx->Enabled = true;
                // Конкурс
                KonkursCmbBx->ItemIndex = KONKURS_tmp;
                KonkursCmbBx->Enabled = true;
                // Целевой договор
                if (KonkursCmbBx->ItemIndex == 3) {
                    Label29->Visible = true;
                    CkRegionDBLkpCmbBx->Visible = true;
                }
                else {
                    Label29->Visible = false;
                    CkRegionDBLkpCmbBx->Visible = false;
                }
            }
        }
        // -------------------------
        if (DM->AbiturCompQrSTATUS->Value == 6) {
            /* FormEduCmbBx->Clear();
             FormEduCmbBx->Items->Add("дневная");
             FormEduCmbBx->Items->Add("заочная");

             CategoryAbCmbBx->Clear();
             CategoryAbCmbBx->Items->Add("Беларусь");
             CategoryAbCmbBx->Items->Add("Иностранцы");
             CategoryAbCmbBx->Items->Add("СНГ");
             CategoryAbCmbBx->Items->Add("ДНР/ЛНР");

             SngFrgCmbBx->Clear();
             SngFrgCmbBx->Items->Add("РБ");
             SngFrgCmbBx->Items->Add("ИГ");
             SngFrgCmbBx->Visible = false;
             SngFrgLbl->Visible = false;

             EducatCmbBx->Clear();
             EducatCmbBx->Items->Add("среднее");
             EducatCmbBx->Items->Add("среднее специальное");
             EducatCmbBx->Items->Add("незаконченное высшее");
             EducatCmbBx->Items->Add("высшее");
             EducatCmbBx->Items->Add("профессионально-техническое");

             TermEduCmbBx->Clear();
             TermEduCmbBx->Items->Add("полный");
             TermEduCmbBx->Items->Add("сокращённый 2 курс");
             TermEduCmbBx->Items->Add("сокращённый 3 курс");

             PriceCmbBx->Clear();
             PriceCmbBx->Items->Add("бюджет");
             PriceCmbBx->Items->Add("за оплату");

             KonkursCmbBx->Clear();
             KonkursCmbBx->Items->Add("общий");
             KonkursCmbBx->Items->Add("без вступительных испытаний");
             KonkursCmbBx->Items->Add("вне конкурса");
             KonkursCmbBx->Items->Add("целевой"); */

            // Выводим фото
            TMemoryStream* pms;
            Jpeg::TJPEGImage *jp;
            if (!(TBlobField*)DM->FIOSearchQrPHOTO->IsNull) {
                pms = new TMemoryStream;
                jp = new TJPEGImage;
                DM->FIOSearchQrPHOTO->SaveToStream(pms);
                pms->Seek(0, 0);
                Image1->Picture->Graphic = jp;
                Image1->Picture->Graphic->LoadFromStream(pms);
                Image1->Visible = True;
                delete pms;
                delete jp;
                if ((Image1->Picture->Width == 0) ||
                    (Image1->Picture->Height == 0))
                    Image1->Picture = NULL;
            }
            else
                Image1->Picture = NULL;
            // из закладки ПОДАЧА ДОКУМЕНТОВ
            FamDBEdt->Text = DM->FIOSearchQrFAM->AsString;
            // Фамилия
            NameDBEdt->Text = DM->FIOSearchQrNAME->AsString; // Имя
            OtchDBEdt->Text = DM->FIOSearchQrOTCH->AsString;
            // Отчество
            // Форма получения образования
            FormEduCmbBx->ItemIndex = DM->FIOSearchQrVID_EDU->AsInteger;
            // Направление специальности
            DM->QSpecializPlan_Priem->Close();
            DM->QSpecializPlan_Priem->ParamByName("VID_EDU")->AsSmallInt =
                FormEduCmbBx->ItemIndex;
            DM->QSpecializPlan_Priem->ParamByName("FAC")->AsSmallInt = nom_fac;
            DM->QSpecializPlan_Priem->Open();
            SpecializDBLookupCmbBx->KeyValue =
                DM->FIOSearchQrN_SPECIALIZ->AsInteger;
            SpecializDBLookupCmbBx->Enabled = true;
            // Категория абитуриента
            CategoryAbCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_AB->AsInteger;
            // Категория поступления
            if (DM->FIOSearchQrCATEGORY_IF->Value > -1)
                SngFrgCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_IF->Value;
            else
                SngFrgCmbBx->ItemIndex = -1;
            if (SngFrgCmbBx->ItemIndex == 0) {
                SngFrgCmbBx->Visible = false;
                SngFrgLbl->Visible = false;
            }
            else {
                SngFrgCmbBx->Visible = true;
                SngFrgLbl->Visible = true;
            }
            // Образование
            EducatCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_EDU->AsInteger;
            EducatCmbBx->Enabled = true;
            // Срок получения образования
            if ((DM->FIOSearchQrCATEGORY_EDU->AsInteger == 2) ||
                (DM->FIOSearchQrCATEGORY_EDU->AsInteger == 3)) {
                Label64->Caption = "Курс поступления:";
                TermEduCmbBx->ItemIndex =
                    DM->FIOSearchQrTERM_EDU->AsInteger - 3;
            }
            else {
                Label64->Caption = "Срок получения образования:";
                TermEduCmbBx->ItemIndex = DM->FIOSearchQrTERM_EDU->AsInteger;
            }
            TermEduCmbBx->Enabled = true;
            // Форма оплаты
            PriceCmbBx->ItemIndex = DM->FIOSearchQrPRICE->AsInteger;
            PriceCmbBx->Enabled = true;
            // Конкурс
            KonkursCmbBx->ItemIndex = DM->FIOSearchQrKONKURS->AsInteger;
            KonkursCmbBx->Enabled = true;
            // Целевой договор
            if (KonkursCmbBx->ItemIndex == 3) {
                Label29->Visible = true;
                CkRegionDBLkpCmbBx->Visible = true;
            }
            else {
                Label29->Visible = false;
                CkRegionDBLkpCmbBx->Visible = false;
            }

            // Выставляем по умолчанию текущую дату приема документов
            DM->QAbituraDATE_PRIEM->Value =
                DateTimeToSQLTimeStamp(StrToDate(cur_d.CurrentDate()));
            DBDateEdit1->Enabled = false;
            //

            NomGroupCmbBx->Clear();

            TabSheet1->TabVisible = false;
            TabSheet5->TabVisible = false;
            // DBNavigator1->Enabled = false;
            // DBNavigator3->Enabled = false;
            // DBNavigator4->Enabled = false;
            // PrintBtBtn->Visible = false;
            AddBtBtn->Enabled = false;

            FormEduCmbBx->SetFocus();

        }
    }
    else { // абитуриента нет в ABITURA
        // призанк записи в журнал - в 2
        ChangLog = 2;
        NewAbitur(1);
    }
}

// ---------------------------------------------------------------------------
void __fastcall TDM::FIOSearchDSDataChange(TObject *Sender, TField *Field) {
    AbiturForm->ReLoadAbiturPhoto();
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::NewAbitur(int pr_w) {
    // Новый абитуриент

    // pr_w = 0 - по кнопке ДОБАВИТЬ, 1 - из закладки ПОДАЧА ДОКУМЕНТОВ

    PageControl1->ActivePage = TabSheet2;
    // RefreshControl();  // !!! Ниже - что выполняется в функции
    // if дата на сервере больше dateOkonch - разрешаю только добавлять!    ПЕРЕДЕЛАТЬ!!!
    // if (DateServer>=dateOkonch) EnabledTrue();

    /* if (nom_fac==4)
     {
     try
     {
     DM->BlockQ->Edit();
     DM->BlockQBLOCK->Value=0;
     DM->BlockQNOTE->Value="Добавление абитуриента " + DateServer;
     }
     catch(...)
     {
     ShowMessage("Произошел сбой! Повторите операцию!");
     }
     } */
    // PoleBlock();//получение значения поля BLOCK

    // PressBtn(2); // Убираем кнопку Выход и группу кнопок Конкурс
    st_ins = true; // режим вставки

    DM->QAbitura->Insert();

    FormEduCmbBx->Clear();
    FormEduCmbBx->Items->Add("дневная");
    FormEduCmbBx->Items->Add("заочная");

    CategoryAbCmbBx->Clear();
    CategoryAbCmbBx->Items->Add("Беларусь");
    CategoryAbCmbBx->Items->Add("Иностранцы");
    CategoryAbCmbBx->Items->Add("СНГ");
    CategoryAbCmbBx->Items->Add("ДНР/ЛНР");

    SngFrgCmbBx->Clear();
    SngFrgCmbBx->Items->Add("РБ");
    SngFrgCmbBx->Items->Add("ИГ");
    SngFrgCmbBx->Visible = false;
    SngFrgLbl->Visible = false;

    EducatCmbBx->Clear();
    EducatCmbBx->Items->Add("среднее");
    EducatCmbBx->Items->Add("среднее специальное");
    EducatCmbBx->Items->Add("незаконченное высшее");
    EducatCmbBx->Items->Add("высшее");
    EducatCmbBx->Items->Add("профессионально-техническое");

    TermEduCmbBx->Clear();
    TermEduCmbBx->Items->Add("полный");
    TermEduCmbBx->Items->Add("сокращённый 2 курс");
    TermEduCmbBx->Items->Add("сокращённый 3 курс");

    PriceCmbBx->Clear();
    PriceCmbBx->Items->Add("бюджет");
    PriceCmbBx->Items->Add("за оплату");

    KonkursCmbBx->Clear();
    KonkursCmbBx->Items->Add("общий");
    KonkursCmbBx->Items->Add("без вступительных испытаний");
    KonkursCmbBx->Items->Add("вне конкурса");
    KonkursCmbBx->Items->Add("целевой");

    if (pr_w) {
        // Выводим фото
        TMemoryStream* pms;
        Jpeg::TJPEGImage *jp;
        if (!(TBlobField*)DM->FIOSearchQrPHOTO->IsNull) {
            pms = new TMemoryStream;
            jp = new TJPEGImage;
            DM->FIOSearchQrPHOTO->SaveToStream(pms);
            pms->Seek(0, 0);
            Image1->Picture->Graphic = jp;
            Image1->Picture->Graphic->LoadFromStream(pms);
            Image1->Visible = True;
            delete pms;
            delete jp;
            if ((Image1->Picture->Width == 0) || (Image1->Picture->Height == 0))
                Image1->Picture = NULL;
        }
        else
            Image1->Picture = NULL;
        // из закладки ПОДАЧА ДОКУМЕНТОВ
        FamDBEdt->Text = DM->FIOSearchQrFAM->AsString; // Фамилия
        NameDBEdt->Text = DM->FIOSearchQrNAME->AsString; // Имя
        OtchDBEdt->Text = DM->FIOSearchQrOTCH->AsString; // Отчество
        // Форма получения образования
        FormEduCmbBx->ItemIndex = DM->FIOSearchQrVID_EDU->AsInteger;
        // Направление специальности
        DM->QSpecializPlan_Priem->Close();
        DM->QSpecializPlan_Priem->ParamByName("VID_EDU")->AsSmallInt =
            FormEduCmbBx->ItemIndex;
        DM->QSpecializPlan_Priem->ParamByName("FAC")->AsSmallInt = nom_fac;
        DM->QSpecializPlan_Priem->Open();
        SpecializDBLookupCmbBx->KeyValue =
            DM->FIOSearchQrN_SPECIALIZ->AsInteger;
        SpecializDBLookupCmbBx->Enabled = true;
        // Категория абитуриента
        CategoryAbCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_AB->AsInteger;
        // Категория поступления
        if (DM->FIOSearchQrCATEGORY_IF->Value > -1)
            SngFrgCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_IF->Value;
        else
            SngFrgCmbBx->ItemIndex = -1;
        if (SngFrgCmbBx->ItemIndex == 0) {
            SngFrgCmbBx->Visible = false;
            SngFrgLbl->Visible = false;
        }
        else {
            SngFrgCmbBx->Visible = true;
            SngFrgLbl->Visible = true;
        }
        // Образование
        EducatCmbBx->ItemIndex = DM->FIOSearchQrCATEGORY_EDU->AsInteger;
        EducatCmbBx->Enabled = true;
        // Срок получения образования
        if ((DM->FIOSearchQrCATEGORY_EDU->AsInteger == 2) ||
            (DM->FIOSearchQrCATEGORY_EDU->AsInteger == 3)) {
            Label64->Caption = "Курс поступления:";
            TermEduCmbBx->ItemIndex = DM->FIOSearchQrTERM_EDU->AsInteger - 3;
        }
        else {
            Label64->Caption = "Срок получения образования:";
            TermEduCmbBx->ItemIndex = DM->FIOSearchQrTERM_EDU->AsInteger;
        }
        TermEduCmbBx->Enabled = true;
        // Форма оплаты
        PriceCmbBx->ItemIndex = DM->FIOSearchQrPRICE->AsInteger;
        PriceCmbBx->Enabled = true;
        // Конкурс
        KonkursCmbBx->ItemIndex = DM->FIOSearchQrKONKURS->AsInteger;
        KonkursCmbBx->Enabled = true;
        // Целевой договор
        if (KonkursCmbBx->ItemIndex == 3) {
            Label29->Visible = true;
            CkRegionDBLkpCmbBx->Visible = true;
        }
        else {
            Label29->Visible = false;
            CkRegionDBLkpCmbBx->Visible = false;
        }
    }
    else {
        // по кнопке ДОБАВИТЬ
        // очищение фотографии
        Image1->Picture = NULL;
        FamDBEdt->Text = ""; // Фамилия
        NameDBEdt->Text = ""; // Имя
        OtchDBEdt->Text = ""; // Отчество
        // Форма получения образования
        FormEduCmbBx->ItemIndex = -1;
        FormEduCmbBx->Enabled = true;
        // Категория абитуриента
        CategoryAbCmbBx->ItemIndex = -1;
        CategoryAbCmbBx->Enabled = true;
        // условия поступления
        SngFrgCmbBx->ItemIndex = -1;
        SngFrgCmbBx->Enabled = false;
        // Образование
        EducatCmbBx->ItemIndex = -1;
        EducatCmbBx->Enabled = false;
        // Срок получения образования
        TermEduCmbBx->ItemIndex = -1;
        TermEduCmbBx->Enabled = false;
        // Форма оплаты
        PriceCmbBx->ItemIndex = -1;
        PriceCmbBx->Enabled = false;
        // Конкурс
        KonkursCmbBx->ItemIndex = -1;
        KonkursCmbBx->Enabled = false;
        // Целевой договор
        Label29->Visible = false;
        CkRegionDBLkpCmbBx->Visible = false;
    }

    // при add new record в поле гражданство заносить РБ
    // DM->QAbituraCITIZENSHIP->Value = 22;
    SitizenshipDBLkCmbBx->KeyValue = 22;
    // DM->QAbituraGRAGDAN->Value = "РБ";
    /* // при add new record обнуляем поле отчества.
     DM->QAbituraOTCH->Value = ""; */
    // закрытие набора данных по сертификатам
    DM->QSertificat->Close();
    // при add new record в поле Priv_One_Exam заносить нет
    // DM->QAbituraN_PRIVILEGE_EXAM->Value = 1;
    //
    UncheckCh();
    //
    // Выставляем по умолчанию текущую дату приема документов
    DM->QAbituraDATE_PRIEM->Value =
        DateTimeToSQLTimeStamp(StrToDate(cur_d.CurrentDate()));
    DBDateEdit1->Enabled = false;
    //
    // SpecializDBLookupCmbBx->Enabled = true;
    // DBEdit1->Enabled=true;
    // DBEdit2->SetFocus();

    // очищение поля адреса
    AdressRegEdt->Text = "";
    AdressLifeEdt->Text = "";
    // районы закрываем

    // LangRatCmbBx->ItemIndex = -1;

    /* FormEduCmbBx->Clear();
     FormEduCmbBx->Items->Add("дневная");
     FormEduCmbBx->Items->Add("заочная");
     FormEduCmbBx->ItemIndex = -1;
     ComboBox2->ItemIndex = -1; */
    NomGroupCmbBx->Clear();

    if (!pr_w) { // по кнопке Добавить
        // Оля
        KonkursCmbBx->ItemIndex = -1;
        PriceCmbBx->ItemIndex = -1;
        KonkursCmbBx->Enabled = false;

        Label29->Visible = false; // ЦК
        CkRegionDBLkpCmbBx->Visible = false;
    }
    // BitBtn5->Visible=false;
    if (nom_fac == 4) { // if институт туризма
        // специализация
        if (!pr_w) { // по кнопке Добавить
            SpecializDBLookupCmbBx->KeyValue = 61;
            DM->QAbituraN_SPECIALIZ->Value = 61;
        }
        // вид спорта
        VidSportDBLookupCmbBx->KeyValue = 33; // Не занимается
    } // end if институт туризма

    else
        // else добавила Оля
    {
        if (!pr_w) { // по кнопке Добавить
            // специализация
            SpecializDBLookupCmbBx->Text == "";
        }
    } // end else
    // разряд
    SportCategoryDBLookupCmboBx->KeyValue = 12;
    // DM->QAbituraN_SPORT_CATEGORY->Value = 12;

    TabSheet1->TabVisible = false;
    TabSheet5->TabVisible = false;
    // DBNavigator1->Enabled = false;
    // DBNavigator3->Enabled = false;
    // DBNavigator4->Enabled = false;
    // PrintBtBtn->Visible = false;
    AddBtBtn->Enabled = false;

    FormEduCmbBx->SetFocus();

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::FIOReBitBtnClick(TObject *Sender) {
    FIOSearchEdt->Text = "";
    DM->FIOSearchQr->Close();
    DM->FIOSearchQr->ParamByName("fio")->AsString = "";
    DM->FIOSearchQr->ParamByName("n_fac")->AsSmallInt = nom_fac;
    DM->FIOSearchQr->Open();
    FIOSearchEdt->Focused();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::SngFrgCmbBxChange(TObject *Sender) {
    bool SngFrgChange = false;
    // Изменение условий поступления
    if (ChangLog == 0) {
        if (MessageDlg("Изменение данного параметра повлечёт отметку о возврате документов\n \
         и добавлению новой записи в журнале учёта абитуриентов.\nВы хотите продолжить?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            SngFrgChange = true;
        }
    }
    else
        SngFrgChange = true;
    if (SngFrgChange == true) {
        if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
            DM->QAbitura->Edit();
        } // end if dsBrowse

        switch (SngFrgCmbBx->ItemIndex) {
        case 0: // СНГ
            {
                pr_KategIf = 2;
                break;
            }
        case 1: // Иностранцы
            {
                pr_KategIf = 1;
                break;
            }
        }

        // Образование
        EducatCmbBx->ItemIndex = -1;
		TermEduCmbBx->ItemIndex = -1;
        PriceCmbBx->ItemIndex = -1;
        KonkursCmbBx->ItemIndex = -1;
        if (SngFrgCmbBx->ItemIndex > -1)
            EducatCmbBx->Enabled = true;
        else
            EducatCmbBx->Enabled = false;

        EducatCmbBxChange(this);
        if (ChangLog != 2)
            ChangLog = 1;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::KonkursCmbBxChange(TObject *Sender) {
    bool KonkursChange = false;
    // Изменение конкурса
    if (ChangLog == 0) { // незначительные изменения
        if (MessageDlg("Изменение данного параметра повлечёт отметку о возврате документов\n \
         и добавлению новой записи в журнале учёта абитуриентов.\nВы хотите продолжить?"
            , mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            KonkursChange = true;
        }
    }
    else
        KonkursChange = true;
    if (KonkursChange == true) {
        if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
            DM->QAbitura->Edit();
        } // end if dsBrowse

        if (KonkursCmbBx->ItemIndex == 3) {
            DM->CkRegionQr->Close();
            DM->CkRegionQr->Open();
            Label29->Visible = true;
            CkRegionDBLkpCmbBx->Visible = true;
            CkRegionDBLkpCmbBx->Enabled = true;
        }
        else {
            Label29->Visible = false;
            CkRegionDBLkpCmbBx->Visible = false;
            CkRegionDBLkpCmbBx->Enabled = false;
        }
        if (ChangLog != 2)
            ChangLog = 1;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::DBGrid2DrawColumnCell(TObject *Sender,
    const TRect &Rect, int DataCol, TColumn *Column,
    Grids::TGridDrawState State) {
    // Изменение цвета строки
    if (DM->FIOSearchQrSTATUS_QUEUE->Value == 202) {
        // выделение цветом забиравшего документы
        DBGrid2->Canvas->Brush->Color = clYellow;
        DBGrid2->Canvas->FillRect(Rect);
        if (Column->Alignment == taRightJustify) {
            DBGrid2->Canvas->TextOutA
                (Rect.Right - 2 - DBGrid2->Canvas->TextWidth
                (Column->Field->Text), Rect.Top + 2, Column->Field->Text);
        }
        else {
            DBGrid2->Canvas->TextOutA(Rect.Left + 2, Rect.Top + 2,
                Column->Field->Text);
        }
    }
    // Изменение цвета строки
    if (DM->FIOSearchQrSTATUS_QUEUE->Value == 304) {
        // выделение цветом забиравшего документы
        DBGrid2->Canvas->Brush->Color = clLime;
        DBGrid2->Canvas->FillRect(Rect);
        if (Column->Alignment == taRightJustify) {
            DBGrid2->Canvas->TextOutA
                (Rect.Right - 2 - DBGrid2->Canvas->TextWidth
                (Column->Field->Text), Rect.Top + 2, Column->Field->Text);
        }
        else {
            DBGrid2->Canvas->TextOutA(Rect.Left + 2, Rect.Top + 2,
                Column->Field->Text);
        }
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::WithOutCmboBx1Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx2Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx3Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx4Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx5Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx6Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx7Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx8Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx9Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx10Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx11Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx12Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx13Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx14Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx15Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::WithOutCmboBx16Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::OutCmboBx1Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OutCmboBx2Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OutCmboBx3Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OutCmboBx4Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OutCmboBx5Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OutCmboBx6Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::OutCmboBx7Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::InfChekLstBxClickCheck(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::SchoolCmbBxChange(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::TownVillageCmbBxChange(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::AdressRegEdtChange(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::PlaceRDBEdtChange(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::AdressRegEdtExit(TObject *Sender) {
    if (ChangLog < 1) {
        // Запись в лог когда не в режиме изменения конкурса
        DM->AdrLogLastQr->Close();
        DM->AdrLogLastQr->ParamByName("nomer_ab")->AsInteger =
            DM->QAbituraNOMER_AB->Value;
        DM->AdrLogLastQr->Open();
        DM->AddrLogUpQr->Close();
        DM->AddrLogUpQr->ParamByName("id_log")->AsInteger =
            DM->AdrLogLastQrID_LOG->Value;
        DM->AddrLogUpQr->ParamByName("address")->AsString = AdressRegEdt->Text;
        DM->AddrLogUpQr->Prepare();
        DM->AddrLogUpQr->ExecSQL();
        DM->AddrLogUpQr->Close();
        DM->AdrLogLastQr->Close();
    }
    AdresPapaDBEdt->Text = AdressRegEdt->Text;
    AdresMamaDBEdt->Text = AdressRegEdt->Text;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::NomDelaDBEdtChange(TObject *Sender) {
    // Изменение номера дела
    NumDelaLbl->Caption = DM->NumDelaString(DM->QAbituraVID_EDU->Value,
        DM->QAbituraTERM_EDU->Value, DM->QAbituraPRICE->Value,
        DM->QAbituraNOM_DELA->Value);
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::SportCategoryDBLookupCmboBxExit(TObject *Sender) {
    if (ChangLog < 1) {
        // Запись в лог когда не в режиме изменения конкурса
        DM->AdrLogLastQr->Close();
        DM->AdrLogLastQr->ParamByName("nomer_ab")->AsInteger =
            DM->QAbituraNOMER_AB->Value;
        DM->AdrLogLastQr->Open();
        DM->CategUpQr->Close();
        DM->CategUpQr->ParamByName("id_log")->AsInteger =
            DM->AdrLogLastQrID_LOG->Value;
        DM->CategUpQr->ParamByName("category")->AsString =
            SportCategoryDBLookupCmboBx->KeyValue;
        DM->CategUpQr->Prepare();
        DM->CategUpQr->ExecSQL();
        DM->CategUpQr->Close();
        DM->AdrLogLastQr->Close();
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::CkRegionDBLkpCmbBxExit(TObject *Sender) {
    if (ChangLog < 1) {
        // Запись в лог когда не в режиме изменения конкурса
        DM->AdrLogLastQr->Close();
        DM->AdrLogLastQr->ParamByName("nomer_ab")->AsInteger =
            DM->QAbituraNOMER_AB->Value;
        DM->AdrLogLastQr->Open();
        DM->RegionUpCKQr->Close();
        DM->RegionUpCKQr->ParamByName("id_log")->AsInteger =
            DM->AdrLogLastQrID_LOG->Value;
        DM->RegionUpCKQr->ParamByName("n_ck")->AsString =
            CkRegionDBLkpCmbBx->KeyValue;
        DM->RegionUpCKQr->Prepare();
        DM->RegionUpCKQr->ExecSQL();
        DM->RegionUpCKQr->Close();
        DM->AdrLogLastQr->Close();
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::DBDateEdit1Change(TObject *Sender) {
    // DBDateEdit1->Time = StrToTime("00:00");
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::DBGrid2CellClick(TColumn *Column) {
    DM->FIOSearchQr->ParamByName("fio")->AsString =
		DM->FIOSearchQrFAM->Value + " " + DM->FIOSearchQrNAME->Value
	    + " " + DM -> FIOSearchQrOTCH->Value;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::PersonNumDBEdtChange (TObject * Sender)
{
    AnsiString
        personal =
            PersonNumDBEdt -> Text,
        key      =
            personal.SubString (
                personal.Length (),
                1
            );

    if (    key >= 'А'
         && key <= 'Я'
       )
    {
        personal =
            personal.SubString (
                1,
                personal.Length() - 1
            );

        PersonNumDBEdt -> Text = personal;

        ShowMessage (
            "Личный номер должен содержать только латинские буквы!"
        );
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::BitBtn1Click(TObject *Sender) {
    DualListDlgDoc = new TDualListDlgDoc(this);
    DualListDlgDoc->SrcList->Items->Clear();
    DualListDlgDoc->DstList->Items->Clear();
    DM->ListDocFDQ->Close();
    DM->DocumFDQ->Close();
    DM->ListDocFDQ->ParamByName("NOMER_AB")->Value =
        DM->QAbituraNOMER_AB->Value;
    DM->DocumFDQ->ParamByName("NOMER_AB")->Value = DM->QAbituraNOMER_AB->Value;
    DM->ListDocFDQ->Open();
    DM->DocumFDQ->Open();
    // Мой компонент
    for (int i = 0; i < DM->ListDocFDQ->RecordCount; i++) {
        DualListDlgDoc->DstList->Items->AddObject(DM->ListDocFDQTEXT_DOC->Value,
            (TObject *)(DM->ListDocFDQN_DOC->Value));
        DM->ListDocFDQ->Next();
    } // for
    for (int i = 0; i < DM->DocumFDQ->RecordCount; i++) {
        DualListDlgDoc->SrcList->Items->AddObject(DM->DocumFDQTEXT_DOC->Value,
            (TObject *)(DM->DocumFDQN_DOC->Value));
        DM->DocumFDQ->Next();
    } // for

    DualListDlgDoc->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::CheckBox1Click(TObject *Sender) {
    if (CheckBox1->Checked) {
        Panel5->Visible = true;
        InfChekLstBx->Checked[7] = true;
    }
    else {
        Panel5->Visible = false;
        ComboBox1->ItemIndex = -1;
        ComboBox2->ItemIndex = -1;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::PageControl1Change(TObject *Sender) {
    if (ComboBox1->ItemIndex == 0 || ComboBox1->ItemIndex == 1) {
        InfChekLstBx->Checked[7] = true;
    }
    else
        InfChekLstBx->Checked[7] = false;

}



void __fastcall TAbiturForm::DistrictDBLkCmbBxExit (TObject * Sender)
{
    DM -> QType_locality -> Close();

    DM -> QType_locality -> Open();

    // if (DM -> QAbitura -> State == dsInsert)
    //     LocalityDBLkCmbBx -> KeyValue = -1;
}



void __fastcall TAbiturForm::TabSheet2Show (TObject * Sender)                   // переход на закладку  ЛИЧНОЕ ДЕЛО
{
    /*
    ExitBitBtn->Enabled=true;
    ExitBitBtn->Visible=true;
    */
    /*
    SaveBtBtn->Enabled = true;
    CancelBtBtn->Enabled = true;
    SaveBtBtn->Visible = true;
    CancelBtBtn->Visible = true;
    */
    if (DM->QAbitura->State != dsInsert)
        RefreshControl();
    ActionList1->State = asNormal;
    // закрытие конкурсов после приема документов
    if (!st_developer & pole_block == 1)
        KonkursCmbBx->Enabled = false;
    // EnableDate();

    Image2->Visible = false;
    Image3->Visible = true;
    Panel6->Height = 220;                                                       // was 200 MOD HEIGHT HERE!!!!!!!
    Panel6->Top = 0;
    pan1 = true;

    Image4->Visible = true;
    Image5->Visible = false;
    Panel2->Height = 22;
    Panel2->Top = Panel6->Height;
    pan2 = false;

    Image6->Visible = true;
    Image7->Visible = false;
    Panel1->Height = 22;
    Panel1->Top = Panel2->Height + Panel2->Top;
    pan3 = false;

    Image8->Visible = true;
    Image9->Visible = false;
    Panel4->Height = 22;
    Panel4->Top = Panel1->Height + Panel1->Top;
    pan4 = false;

    Image10->Visible = true;
    Image11->Visible = false;
    Panel7->Height = 22;
    Panel7->Top = Panel4->Height + Panel4->Top;
    pan5 = false;

    Image12->Visible = true;
    Image13->Visible = false;
    Panel3->Height = 22;
    Panel3->Top = Panel7->Height + Panel7->Top;
    pan6 = false;

    Image14->Visible = true;
    Image15->Visible = false;
    Panel18->Height = 22;
    Panel18->Top = Panel3->Height + Panel3->Top;
    pan7 = false;

    AbiturForm->Height = Panel18->Top + Panel18->Height + 110;                  // HEIGHT HERE !!!!!!!!!!!!!!!!!!
}



void __fastcall TAbiturForm::RegionDBLookupCmbBxCloseUp (TObject * Sender)
{
    if (region_id != RegionDBLookupCmbBx -> KeyValue)
    {
        AddressForm -> DistrictDBLkCmbBx      -> KeyValue = 0;
        AddressForm -> Type_localityDBLkCmbBx -> KeyValue = 0;
        AddressForm -> LocalityDBLkCmbBx      -> KeyValue = 0;
        AddressForm -> Type_streetDBLkCmbBx   -> KeyValue = 0;
        AddressForm -> StreetDBLkCmbBx        -> KeyValue = 0;
    }

    if (RegionDBLookupCmbBx -> KeyValue == 8)                                   // Select 'Другие республики'
        AdressRegEdt -> ReadOnly = false;
    else
    {
        AdressRegEdt -> ReadOnly = true;

        AddressForm =
            new TAddressForm(
                this,
                RegionDBLookupCmbBx
            );

        AddressForm -> ShowModal();

        if (AddressForm -> isAddressSaved ())
        {
            AdressRegEdt   -> Text = AddressForm  -> getAddress ();

            AdresPapaDBEdt -> Text = AdressRegEdt -> Text;
            AdresMamaDBEdt -> Text = AdressRegEdt -> Text;
        }
    }
}



void __fastcall TAbiturForm::CheckBox2Click (TObject * Sender)
{
    if (CheckBox2 -> Checked)
        AdressLifeEdt -> Text = AdressRegEdt -> Text;
    else
    {
        if (region_id != RegionDBLookupCmbBx -> KeyValue)
        {
            AddressLifeForm -> DistrictDBLkCmbBx      -> KeyValue = 0;
            AddressLifeForm -> Type_localityDBLkCmbBx -> KeyValue = 0;
            AddressLifeForm -> LocalityDBLkCmbBx      -> KeyValue = 0;
            AddressLifeForm -> Type_streetDBLkCmbBx   -> KeyValue = 0;
            AddressLifeForm -> StreetDBLkCmbBx        -> KeyValue = 0;
        }

        if (RegionDBLookupCmbBx -> KeyValue == 8)
            AdressLifeEdt -> ReadOnly = false;
        else
        {
            AdressLifeEdt -> ReadOnly = true;

            AddressForm =
                new TAddressForm(
                    this,
                    RegionDBLookupCmbBx
                );

//            AddressLifeForm = new TAddressLifeForm(this);
//
//            if (RegionDBLookupCmbBx -> KeyValue == 5)
//            {
//                AddressLifeForm -> Label48                     -> Visible = false;
//                AddressLifeForm -> Notice_RequiredRegion       -> Visible = false;
//
//                AddressLifeForm -> Label51                     -> Visible = false;
//                AddressLifeForm -> Notice_RequiredDistrict     -> Visible = false;
//
//                AddressLifeForm -> Label54                     -> Visible = false;
//                AddressLifeForm -> Notice_RequiredTypeLocality -> Visible = false;
//
//                AddressLifeForm -> Notice_RequiredLocality     -> Visible = false;
//                AddressLifeForm -> Type_streetDBLkCmbBx        -> Visible = true;
//                AddressLifeForm -> Type_streetDBLkCmbBx        -> Enabled = true;
//
//                DM -> QType_street -> Close();
//                DM -> QType_street -> Open();
//
//                AddressLifeForm -> Type_streetDBLkCmbBx -> KeyValue = 1;
//            }
//            else
//            {
//                AddressLifeForm -> Label48                     -> Visible = true;
//                AddressLifeForm -> Notice_RequiredRegion       -> Visible = true;
//
//                AddressLifeForm -> Label51                     -> Visible = true;
//                AddressLifeForm -> Notice_RequiredDistrict     -> Visible = true;
//
//                AddressLifeForm -> Label54                     -> Visible = true;
//                AddressLifeForm -> Notice_RequiredTypeLocality -> Visible = true;
//
//                AddressLifeForm -> Notice_RequiredLocality     -> Visible = true;
//                AddressLifeForm -> Type_streetDBLkCmbBx        -> Visible = false;
//                AddressLifeForm -> Type_streetDBLkCmbBx        -> Enabled = false;
//
//                DM -> QDistrict -> Close();
//                DM -> QDistrict ->
//                    ParamByName ("REGION") -> AsInteger =
//                            RegionDBLookupCmbBx -> KeyValue;
//                DM -> QDistrict -> Open();
//
//                if (DM -> QAbitura -> State == dsInsert)
//                    AddressLifeForm -> DistrictDBLkCmbBx -> KeyValue = -1;
//            }

            AddressLifeForm -> ShowModal();

            if (AddressLifeForm -> isAddressSaved ())
                AdressLifeEdt -> Text = AddressLifeForm -> getAddress ();
        }
    }
}



void __fastcall TAbiturForm::AdressLifeEdtClick (TObject * Sender)
{
    if (CheckBox2 -> Checked)
        AdressLifeEdt -> Text = AdressRegEdt -> Text;
    else
    {
        if (region_id != RegionDBLookupCmbBx -> KeyValue)
        {
            AddressLifeForm -> DistrictDBLkCmbBx      -> KeyValue = 0;
            AddressLifeForm -> Type_localityDBLkCmbBx -> KeyValue = 0;
            AddressLifeForm -> LocalityDBLkCmbBx      -> KeyValue = 0;
            AddressLifeForm -> Type_streetDBLkCmbBx   -> KeyValue = 0;
            AddressLifeForm -> StreetDBLkCmbBx        -> KeyValue = 0;
        }

        AddressLifeForm = new TAddressLifeForm(this);

        if (RegionDBLookupCmbBx -> KeyValue == 5)
        {
            AddressLifeForm -> Label48 -> Visible = false;
            AddressLifeForm -> Label51 -> Visible = false;
            AddressLifeForm -> Label54 -> Visible = false;

            AddressLifeForm -> DistrictDBLkCmbBx      -> Visible = false;
            AddressLifeForm -> Type_localityDBLkCmbBx -> Visible = false;
            AddressLifeForm -> LocalityDBLkCmbBx      -> Visible = false;

            AddressForm -> DistrictDBLkCmbBx      -> Visible = false;
            AddressForm -> Type_localityDBLkCmbBx -> Visible = false;
            AddressForm -> LocalityDBLkCmbBx      -> Visible = false;

            AddressForm -> Type_streetDBLkCmbBx   -> KeyValue = 1;
            AddressForm -> LocalityDBLkCmbBx      -> KeyValue = 1;

            DM -> QType_street -> Close();
            DM -> QType_street -> Open();
        }
        else
        {
            AddressLifeForm -> Label48 -> Visible = true;
            AddressLifeForm -> Label51 -> Visible = true;
            AddressLifeForm -> Label54 -> Visible = true;

            AddressLifeForm -> DistrictDBLkCmbBx      -> Visible = true;
            AddressLifeForm -> Type_localityDBLkCmbBx -> Visible = true;
            AddressLifeForm -> LocalityDBLkCmbBx      -> Visible = true;

            DM -> QDistrict -> Close();
            DM -> QDistrict ->
                ParamByName ("REGION") -> AsInteger =
                        RegionDBLookupCmbBx -> KeyValue;

            DM -> QDistrict -> Open();

            if (DM -> QAbitura -> State == dsInsert)
                AddressLifeForm -> DistrictDBLkCmbBx -> KeyValue = -1;
        }

        AddressLifeForm -> ShowModal();

        if (AddressLifeForm -> isAddressSaved ())
            AdressLifeEdt -> Text = AddressLifeForm -> getAddress ();
    }
}



void __fastcall TAbiturForm::Panel13Click (TObject * Sender)
{
    if (    AbiturForm -> Height + panH1 <= 1000
         || pan1                         == true
       )
    {
        Image2 -> Visible = !Image2 -> Visible;
        Image3 -> Visible = !Image3 -> Visible;

        pan1 = !pan1;

        Timer1 -> Enabled = true;
    }
}



void __fastcall TAbiturForm::Panel14Click (TObject * Sender)
{
    if (    AbiturForm -> Height + panH2 <= 1000
         || pan2                         == true
       )
    {
        Image4 -> Visible = !Image4 -> Visible;
        Image5 -> Visible = !Image5 -> Visible;

        pan2 = !pan2;

        Timer2 -> Enabled = true;
    }
}



void __fastcall TAbiturForm::Panel15Click(TObject *Sender) {
    if (AbiturForm->Height + panH3 <= 1000 || pan3 == true) {
        Image6->Visible = !Image6->Visible;
        Image7->Visible = !Image7->Visible;
        pan3 = !pan3;
        Timer3->Enabled = true;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel17Click(TObject *Sender) {
    if (AbiturForm->Height + panH4 <= 1000 || pan4 == true) {
        Image8->Visible = !Image8->Visible;
        Image9->Visible = !Image9->Visible;
        pan4 = !pan4;
        Timer4->Enabled = true;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel19Click(TObject *Sender) {
    if (AbiturForm->Height + panH5 <= 1000 || pan5 == true) {
        Image10->Visible = !Image10->Visible;
        Image11->Visible = !Image11->Visible;
        pan5 = !pan5;
        Timer5->Enabled = true;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel20Click(TObject *Sender) {
    if (AbiturForm->Height + panH6 <= 1000 || pan6 == true) {
        Image12->Visible = !Image12->Visible;
        Image13->Visible = !Image13->Visible;
        pan6 = !pan6;
        Timer6->Enabled = true;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel21Click(TObject *Sender) {
    if (AbiturForm->Height + panH7 <= 1000 || pan7 == true) {
        Image14->Visible = !Image14->Visible;
        Image15->Visible = !Image15->Visible;
        pan7 = !pan7;
        Timer7->Enabled = true;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Timer1Timer(TObject *Sender) {
    if (pan1 && Panel6->Height < panH1) {
        Panel6->Height += 10;
        Panel2->Top += 10;
        Panel1->Top += 10;
        Panel4->Top += 10;
        Panel7->Top += 10;
        Panel3->Top += 10;
        Panel18->Top += 10;
        AbiturForm->Height += 10;
    }
    if (!pan1 && Panel6->Height > 22) {
        Panel6->Height -= 10;
        Panel2->Top -= 10;
        Panel1->Top -= 10;
        Panel4->Top -= 10;
        Panel7->Top -= 10;
        Panel3->Top -= 10;
        Panel18->Top -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan1 && Panel6->Height < panH1) && !(!pan1 && Panel6->Height > 22)) {
        Timer1->Enabled = false;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Timer2Timer(TObject *Sender) {
    if (pan2 && Panel2->Height < panH2) {
        Panel2->Height += 10;
        Panel1->Top += 10;
        Panel4->Top += 10;
        Panel7->Top += 10;
        Panel3->Top += 10;
        Panel18->Top += 10;
        AbiturForm->Height += 10;
    }
    if (!pan2 && Panel2->Height > 22) {
        Panel2->Height -= 10;
        Panel1->Top -= 10;
        Panel4->Top -= 10;
        Panel7->Top -= 10;
        Panel3->Top -= 10;
        Panel18->Top -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan2 && Panel2->Height < panH2) && !(!pan2 && Panel2->Height > 22)) {
        Timer2->Enabled = false;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Timer3Timer(TObject *Sender) {
    if (pan3 && Panel1->Height < panH3) {
        Panel1->Height += 10;
        Panel4->Top += 10;
        Panel7->Top += 10;
        Panel3->Top += 10;
        Panel18->Top += 10;
        AbiturForm->Height += 10;
    }
    if (!pan3 && Panel1->Height > 22) {
        Panel1->Height -= 10;
        Panel4->Top -= 10;
        Panel7->Top -= 10;
        Panel3->Top -= 10;
        Panel18->Top -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan3 && Panel1->Height < panH3) && !(!pan3 && Panel1->Height > 22)) {
        Timer3->Enabled = false;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Timer4Timer(TObject *Sender) {
    if (pan4 && Panel4->Height < panH4) {
        Panel4->Height += 10;
        Panel7->Top += 10;
        Panel3->Top += 10;
        Panel18->Top += 10;
        AbiturForm->Height += 10;
    }
    if (!pan4 && Panel4->Height > 22) {
        Panel4->Height -= 10;
        Panel7->Top -= 10;
        Panel3->Top -= 10;
        Panel18->Top -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan4 && Panel4->Height < panH4) && !(!pan4 && Panel4->Height > 22)) {
        Timer4->Enabled = false;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Timer5Timer(TObject *Sender) {
    if (pan5 && Panel7->Height < panH5) {
        Panel7->Height += 10;
        Panel3->Top += 10;
        Panel18->Top += 10;
        AbiturForm->Height += 10;
    }
    if (!pan5 && Panel7->Height > 22) {
        Panel7->Height -= 10;
        Panel3->Top -= 10;
        Panel18->Top -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan5 && Panel7->Height < panH5) && !(!pan5 && Panel7->Height > 22)) {
        Timer5->Enabled = false;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Timer6Timer(TObject *Sender) {
    if (pan6 && Panel3->Height < panH6) {
        Panel3->Height += 10;
        Panel18->Top += 10;
        AbiturForm->Height += 10;
    }
    if (!pan6 && Panel3->Height > 22) {
        Panel3->Height -= 10;
        Panel18->Top -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan6 && Panel3->Height < panH6) && !(!pan6 && Panel3->Height > 22)) {
        Timer6->Enabled = false;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Timer7Timer(TObject *Sender) {
    if (pan7 && Panel18->Height < panH7) {
        Panel18->Height += 10;
        AbiturForm->Height += 10;
    }
    if (!pan7 && Panel18->Height > 22) {
        Panel18->Height -= 10;
        AbiturForm->Height -= 10;
    }
    if (!(pan7 && Panel18->Height < panH7) && !(!pan7 && Panel18->Height > 22))
    {
        Timer7->Enabled = false;
    }

}

// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::WithOutCmboBx19Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::WithOutCmboBx20Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::WithOutCmboBx21Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::WithOutCmboBx22Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
void __fastcall TAbiturForm::WithOutCmboBx23Change(TObject *Sender) {
    if (DM->QAbitura->State == dsBrowse) { // if dsBrowse
        DM->QAbitura->Edit();
    } // end if dsBrowse
}
// ---------------------------------------------------------------------------
void __fastcall TAbiturForm::Panel15DblClick(TObject *Sender) {
    Image4->Visible = !Image4->Visible;
    Image5->Visible = !Image5->Visible;
    if (pan2)
        pan2 = !pan2;
    Timer2->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel17DblClick(TObject *Sender) {
    Image6->Visible = !Image6->Visible;
    Image7->Visible = !Image7->Visible;
    if (pan3)
        pan3 = !pan3;
    Timer3->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel19DblClick(TObject *Sender) {
    Image8->Visible = !Image8->Visible;
    Image9->Visible = !Image9->Visible;
    if (pan4)
        pan4 = !pan4;
    Timer4->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel20DblClick(TObject *Sender) {
    Image10->Visible = !Image10->Visible;
    Image11->Visible = !Image11->Visible;
    if (pan5)
        pan5 = !pan5;
    Timer5->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TAbiturForm::Panel21DblClick(TObject *Sender) {
    Image12->Visible = !Image12->Visible;
    Image13->Visible = !Image13->Visible;
    if (pan6)
        pan6 = !pan6;
    Timer6->Enabled = true;
}
