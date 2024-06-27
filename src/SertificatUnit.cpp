#include <vcl.h>
#pragma hdrstop


#include "AbiturUnit.h"
#include "DMUnit.h"
#include "SertificatUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TSertificatForm * SertificatForm;


bool state_sertificat = false;                                                  // если сертификата еще не было, то false
int  nom;                                                                       // номер абитуриента



__fastcall TSertificatForm::TSertificatForm (TComponent * Owner)
    : TForm (Owner)
{ }


void __fastcall TSertificatForm::BitBtn1Click (TObject * Sender)                // кнопка СОХРАНИТЬ
{
    int n_specializ =
        DM -> QSpecializPlan_PriemN_SPECIALIZ -> Value;

    if (    Edit1 -> Text == ""                                                 // серия
         || Edit2 -> Text == ""                                                 // номер
         || Edit3 -> Text == ""                                                 // документ
       )
        return
            ShowMessage (
                "Проверьте, корректность введенных данных!\n"       \
                "\t1. Cерию сертификата,\n"                         \
                "\t2. Номер сертификата,\n"                         \
                "\t3. Данные документа удостоверяющего личность"
            );

    if (DBLookupComboBox1 -> Text == "")
        return
            ShowMessage (
                "Не указан предмет централизованного тестирования!"
            );

    if (    DBLookupComboBox1 -> KeyValue != 1
         && DBLookupComboBox1 -> KeyValue != 4
         && DBLookupComboBox1 -> KeyValue != 2
         && n_specializ                   != 61
       )
        return
            ShowMessage (
                "Предмет централизованного тестирования должен "            \
                "быть:\n\t1. Биология\n\t2. Белорусский (русский) язык!"
            );

    if (    DBLookupComboBox1 -> KeyValue != 9
         && DBLookupComboBox1 -> KeyValue != 10
         && DBLookupComboBox1 -> KeyValue != 4
         && nom_fac                       == 4
         && n_specializ                   != 48
         && n_specializ                   != 51
         && n_specializ                   != 50
       )
        return
            ShowMessage (
                "Предмет централизованного тестирования должен быть "       \
                "Математика, География или Белорусский (русский) язык!"
            );

    if (    DBLookupComboBox1 -> KeyValue  == 4
         && ComboBox1         -> ItemIndex == -1                                // нужный предмет не выбран
       )
        return
            ShowMessage (
                "Для тестирования по предмету: Белорусский (русский) "      \
                "язык, надо обязательно выбрать язык!"
            );

    if (MaskEdit1 -> Text ==  "   ")                                            // обязательно выставить баллы по тестированию
        return
            ShowMessage (
                "Введите набранные на тестировании баллы!"
            );

    double ozenka = StrToFloat (Label14 -> Caption);

    if (    ozenka  <  2.1                                                      // обязательно выставить баллы по тестированию
         && nom_fac != 4
       )
        return
            ShowMessage (
                "Баллы, полученные на тестировании не являются "            \
                "положительной оценкой!!"
            );

    int b_t = StrToInt (MaskEdit1 -> Text.Trim ());


    //if (    b_t < 10                                                            // в 2014 году 10 - минимальный балл для постепления в ВУЗ по языку
    //     && DBLookupComboBox1 -> KeyValue == 4
    //   )
    //    return
    //        ShowMessage (
    //            "Баллы, полученные на тестировании, не должны быть "        \
    //            "меньше 10!"
    //        );

    //if (    b_t < 15                                                            // в 2014 году 15 - математика и биология
    //     && (   DBLookupComboBox1 -> KeyValue == 9
    //         || DBLookupComboBox1 -> KeyValue == 1
    //        )
    //   )
    //    return
    //        ShowMessage (
    //            "Баллы, полученные на тестировании, не должны быть "        \
    //            "меньше 15!"
    //        );

    //if (    b_t < 20                                                            // в 2014 году 20 - география
    //     && DBLookupComboBox1 -> KeyValue == 10
    //   )
    //    return
    //        ShowMessage (
    //            "Баллы, полученные на тестировании, не должны быть "        \
    //            "меньше 20!"
    //        );


    if (b_t > 100)                                                              // проверка на ввод баллов не более 100
        return
            ShowMessage (
                "Баллы, полученные на тестировании, не должны быть "    \
                "больше 100!"
            );

    // if (DM -> QSertificat -> State == dsInactive)
    //    DM -> QSertificat -> Open ();

    TLocateOptions sss;

    if (    DM -> QSertificat -> Locate (                                       // if нашли сертификат по данному предмету
                "NOMER_AB;N_PREDMET",
                VarArrayOf (
                    OPENARRAY (
                        Variant,
                        (
                            nom,
                            DBLookupComboBox1 -> KeyValue
                        )
                    )
                ),
                sss
            )
       )
        ShowMessage (
            "У абитуриента уже есть сертификат по этому предмету, " \
            "проверьте пожалуйста!"
        );


    try
    {
        if (! state_sertificat)                                                 // false - нет сертификата, true - есть
        {
            DM -> QSertificat -> Insert ();                                     // добавляем
            DM -> QSertificatNOMER_AB  -> Value = nom;                          // номер абитуриента
            DM -> QSertificatN_PREDMET -> Value =                               // предмет
                DBLookupComboBox1 -> KeyValue;
        }
        else
            DM -> QSertificat -> Edit ();

        DM -> QSertificatSERIA_S -> Value = Edit1 -> Text;                      // серия сертификата
        DM -> QSertificatNOMER_S -> Value = Edit2 -> Text;                      // номер сертификата
        DM -> QSertificatBALLS   -> Value = b_t;                                // баллы на тестировании
        DM -> QSertificatYEAR_S  -> Value = StrToInt (Edit4 -> Text);
        DM -> QSertificatPRICE   -> Value = 0;                                  // 0-обязательное, 1-платное тестирование

        int c = DBLookupComboBox1 -> KeyValue,
            r;                                                                  // для сохранения статуса

        switch (c)
        {
            case 1:  r = 2;                      break;                         // биология
            case 2:  r = 5;                      break;                         // география
            case 4:  r = ComboBox1 -> ItemIndex; break;                         // язык
            case 9:  r = 3;                      break;                         // математика
            case 10: r = 4;                      break;                         // география
        }

        DM -> QSertificatRUS_BEL  -> Value = r;
        DM -> QSertificatDESCRIBE -> Value = Edit3 -> Text;                     // документ удостоверяющий личность

        DM -> QSertificat -> ApplyUpdates ();
        DM -> QSertificat -> CommitUpdates ();

        state_sertificat = true;


        TLocateOptions flag;                                                    // поиск оценки и сохранение результатов по результату тестирования

        if (! DM -> QResult_Exam -> Active)
            DM -> QResult_Exam -> Open ();

        if (    DM -> QResult_Exam ->
                    Locate (
                        "NOMER_AB;N_PREDMET",
                        VarArrayOf (
                            OPENARRAY (
                                Variant,
                                (
                                    nom,
                                    DBLookupComboBox1 -> KeyValue
                                )
                            )
                        ),
                        flag
                    )
           )
        {
            if (DM -> QResult_ExamNOM_BALL -> Value !=  0)                      // if нашли запись по данному предмету, отличную от 0
            {
                if (DM -> QResult_ExamBALL -> Value != ozenka)                  // if поменяли баллы в сертификате и надо изменить оценку по предмету
                {
                    // if (    Application -> MessageBox (
                    //             "У этого абитуриента уже есть оценка по "   \
                    //             "данному предмету! Изменить ее!",
                    //             "",
                    //             MB_YESNO
                    //         ) == mrYes
                    //    )

                    AnsiString ansi_string1 =
                        "У этого абитуриента уже есть оценка по данному "   \
                        "предмету!\nЖелаете продолжить?";

                    wchar_t * UnicodeString1 =
                        new wchar_t[ansi_string1.WideCharBufSize ()];

                    ansi_string1.WideChar (
                        UnicodeString1,
                        ansi_string1.WideCharBufSize ()
                    );


                    ansi_string1 = "";

                    wchar_t * UnicodeString2 =
                        new wchar_t[ansi_string1.WideCharBufSize ()];

                    ansi_string1.WideChar (
                        UnicodeString2,
                        ansi_string1.WideCharBufSize ()
                    );

                    if (    Application -> MessageBox (                         // меняем оценку по сертификату
                                UnicodeString1,
                                UnicodeString2,
                                MB_YESNO
                            ) ==  mrYes
                       )
                    {
                        DM -> QResult_Exam -> Edit ();

                        if (    nom_fac                                 == 4
                             && AbiturForm -> TermEduCmbBx -> ItemIndex != 1
                             && AbiturForm -> TermEduCmbBx -> ItemIndex != 2
                           )
                            DM -> QResult_ExamNOM_BALL -> Value = 13;           // стобалка
                        else
                        {
                            AnsiString z =
                                FloatToStrF (
                                    ozenka,
                                    ffFixed,
                                    5,
                                    0
                                );

                            DM -> QResult_ExamNOM_BALL -> Value =
                                z.ToInt () + 1;
                        }

                        DM -> QResult_ExamBALL        -> Value = ozenka;
                        DM -> QResult_ExamSTATUS_BALL -> Value = 1;

                        try
                        {
                            DM -> QResult_Exam -> ApplyUpdates ();
                            DM -> QResult_Exam -> CommitUpdates ();

                            ShowMessage (
                                "Сохранение результатов прошло успешно!"
                            );

                            DM -> QResult_Exam -> Close ();
                        }
                        catch (...)
                        {
                            DM -> QResult_Exam -> CancelUpdates ();

                            ShowMessage (
                                "Произошел сбой при сохранении, "       \
                                "попробуйте еще раз!"
                            );
                        }
                    }
                    else
                        ShowMessage (
                            "Измените баллы в сертификате, они не "     \
                            "соответствуют оценке по экзамену!"
                        );

                    if (UnicodeString1)
                        delete [] UnicodeString1;

                    if (UnicodeString2)
                        delete [] UnicodeString2;
                }
            }
            else
                ShowMessage (
                    "Этот абитуриент уже был включен в ведомость на "   \
                    "экзамен по данному предмету"
                );
        }
        else
        {
            DM -> QResult_Exam -> Insert ();

            DM -> QResult_ExamNOMER_AB  -> Value = nom;
            DM -> QResult_ExamN_PREDMET -> Value =
                DBLookupComboBox1 -> KeyValue;

            if (    nom_fac                                 == 4
                 && AbiturForm -> TermEduCmbBx -> ItemIndex != 1
                 && AbiturForm -> TermEduCmbBx -> ItemIndex != 2
               )
                DM -> QResult_ExamNOM_BALL -> Value = 13;                       // стобалка
            else
            {
                AnsiString z =
                    FloatToStrF (
                        ozenka,
                        ffFixed,
                        5,
                        0
                    );

                DM -> QResult_ExamNOM_BALL -> Value =
                    z.ToInt () + 1;
            }

            DM -> QResult_ExamBALL -> Value = ozenka;


            DM -> QResult_ExamSTATUS_BALL -> Value = 1;                         // статус полученной оценки (0 - оценка экзамена, 1 - оценка по ЦТ)

            try
            {
                DM -> QResult_Exam -> ApplyUpdates ();
                DM -> QResult_Exam -> CommitUpdates ();

                ShowMessage (
                    "Сохранение результатов прошло успешно!"
                );

                DM -> QResult_Exam -> Close ();
            }
            catch (...)
            {
                DM -> QResult_Exam -> CancelUpdates ();

                ShowMessage (
                    "Произошел сбой при сохранении, попробуйте еще раз!"
                );
            }
            DM -> QResult_Exam -> Close ();
        }

        if (DM -> QAbitura -> State != dsInsert)
            if (!summa_b (nom))
                ShowMessage (
                    "Не удалось просуммировать оценки"
                );

        // TLocateOptions Op;

        // DM -> QSertificat ->
        //     Locate (
        //         "NOMER_AB",
        //         nom,
        //         Op
        //     );

        // TLocateOptions Flags;

        // DM -> QAbitura ->
        //     Locate (
        //         "NOMER_AB",
        //         nom,
        //         Flags
        //     );

        // this -> Close ();
    }
    catch (...)
    {
        DM -> QSertificat -> CancelUpdates ();

        ShowMessage (
            "Произошел сбой при сохранении, попробуйте еще раз!"
        );
    }

    DBLookupComboBox1 -> Enabled = false;                                       // делаем недоступным изменение предмета
}
void __fastcall TSertificatForm::BitBtn2Click (TObject * Sender)
{
    if (DM -> QSertificat -> State == dsInsert)
        DM -> QSertificat -> CancelUpdates ();

    this -> Close ();
}
void __fastcall TSertificatForm::BitBtn3Click (TObject * Sender)                // Кнопка удалить сертификат
{
    TLocateOptions Opts;

    Opts.Clear ();

    Variant locvalues[3];

    locvalues[0] = Variant (nom);                                               // номер абитуриента
    locvalues[1] = Variant (DBLookupComboBox1 -> KeyValue);                     // предмет
    locvalues[2] = Variant (1);                                                 // статус (1 - оценка по ЦТ)


    AnsiString ansi_string1 =                                                   // искомая строка
        "\tВы действительно хотите удалить этот сертификат?";

    wchar_t * UnicodeString1 = new wchar_t[ansi_string1.WideCharBufSize ()];    // массив-получатель

    ansi_string1.WideChar (                                                     // передача
        UnicodeString1,
        ansi_string1.WideCharBufSize ()
    );

    ansi_string1 = "";                                                          // очищаем искомую строку

    wchar_t * UnicodeString2 = new wchar_t[ansi_string1.WideCharBufSize ()];    // массив-получатель

    ansi_string1.WideChar (
        UnicodeString2,
        ansi_string1.WideCharBufSize ()
    );


    if (    Application -> MessageBox (                                         // MessageBox == Yes
                UnicodeString1,
                UnicodeString2,
                MB_YESNO
            ) == mrYes
       )
    {

        if (DM -> QResult_Exam -> State == dsInactive)
            DM -> QResult_Exam -> Open ();


        if (    DM -> QResult_Exam -> Locate (                                  // поиск в результатах экзаменов записи по сертификату
                    "NOMER_AB;N_PREDMET;STATUS_BALL",
                    VarArrayOf (
                        locvalues,
                        2
                    ),
                    Opts
                )
           )
        {
            DM -> QResult_Exam -> Delete ();                                    // нашли QResult_Exam запись - удаляем
            DM -> QResult_Exam -> ApplyUpdates ();
            DM -> QResult_Exam -> CommitUpdates ();
        }


        if (    DM -> QSertificat -> Locate (                                   // удаление записей в сертификате
                    "NOMER_AB;N_PREDMET",
                    VarArrayOf (
                        locvalues,
                        1
                    ),
                    Opts
                )
           )
        {
            DM -> QSertificat -> Delete ();                                     // нашли QSertificat запись - удаляем
            DM -> QSertificat -> ApplyUpdates ();
            DM -> QSertificat -> CommitUpdates ();
        }
    }

    if (UnicodeString1)
        delete [] UnicodeString1;

    if (UnicodeString2)
        delete [] UnicodeString2;
}
void __fastcall TSertificatForm::DBLookupComboBox1CloseUp (TObject * Sender)
{
    if (DBLookupComboBox1 -> KeyValue == 4)                                     // Белорусский (русский язык)
    {
        Label5    -> Visible = true;
        ComboBox1 -> Visible = true;

        ComboBox1 -> SetFocus ();
    }
    else                                                                        // биология, математика, география
    {
        Label5    -> Visible = false;
        ComboBox1 -> Visible = false;

        MaskEdit1 -> SetFocus ();
    }
}
void __fastcall TSertificatForm::DBNavigator1Click (
        TObject      * Sender,
        TNavigateBtn   Button
    )
{
    switch (Button)
    {
        case nbFirst:   refrech_sertificat (); break;
        case nbPrior:   refrech_sertificat (); break;
        case nbNext:    refrech_sertificat (); break;
        case nbLast:    refrech_sertificat (); break;
        case nbInsert:
                Edit1             -> Text      = "";                            // серия сертификата
                Edit2             -> Text      = "";                            // номер сертификата
                // Edit3             -> Text      = "";                            // документ удостоверяющий личность
                MaskEdit1         -> Text      = "";                            // баллы на тестировании
                DBLookupComboBox1 -> KeyValue  = -1;                            // предмет
                DBLookupComboBox1 -> Enabled   = true;                          // делаем доступным изменение предмета
                Label14           -> Caption   = "";                            // очищение оценки
                Label5            -> Visible   = false;                         // скрываем выбор языка
                ComboBox1         -> Visible   = false;
                ComboBox1         -> Text      = "";
                ComboBox1         -> ItemIndex = -1;

                state_sertificat = false;                                       // общий флаг когда нет сертификата

                Edit1 -> SetFocus ();
            break;
        case nbDelete:                         break;
        case nbEdit:                           break;
        case nbCancel:  refrech_sertificat (); break;
        case nbRefresh:                        break;
    }
}
void __fastcall TSertificatForm::Edit1Exit (TObject * Sender)
{
    // if (DM -> QSertificat -> State == dsInsert)
    if (! state_sertificat)
        seria_sertificat (
            Edit1 -> Text
        );
}
void __fastcall TSertificatForm::FormActivate (TObject * Sender)
{
    if (DM -> QSertificat -> State == dsInactive)                               // открываем сертификаты
    {
        DM -> QSertificat ->
            ParamByName ("NOMER") -> AsInteger =
                    DM -> QAbituraNOMER_AB -> Value;

        DM -> QSertificat -> Open ();
    }

    refrech_sertificat ();

    Label9  -> Caption = DM -> QAbituraFAM  -> Value;                           // Фамилия
    Label10 -> Caption = DM -> QAbituraNAME -> Value;                           // Имя
    Label11 -> Caption = DM -> QAbituraOTCH -> Value;                           // Отчество

    Label14 -> Caption = MaskEdit1 -> Text;

    UpDown1 -> Max = StrToInt (Admissions::TIME::YEAR);
    UpDown1 -> Min = StrToInt (Admissions::TIME::YEAR) - 1;
}
void __fastcall TSertificatForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}
void __fastcall TSertificatForm::MaskEdit1Exit (TObject * Sender)               // уход с поля с баллами по тестированию
{
    if (MaskEdit1 -> Text != "   ")
    {
        int bal_t = 0;

        try                                                                     // проверка корректности ввода оценки
        {
            bal_t =
                StrToInt (
                    MaskEdit1 -> Text.Trim ()
                );
        }
        catch (...)
        {
            ShowMessage (
                "Проверьте, корректность введенной оценки " \
                "по тестированию!"
            );
            bal_t =
                StrToInt (
                    MaskEdit1 -> Text.Trim ()
                );
        }


        // DM -> QShkala -> Close ();                                              // проверка по шкале на полученный балл
        // DM -> QShkala ->
        //     ParamByName ("N_PR")    -> AsSmallInt =
        //             DBLookupComboBox1 -> KeyValue;
        // DM -> QShkala ->
        //     ParamByName ("N_BALL")  -> AsSmallInt =
        //             bal_t;
        // DM -> QShkala ->
        //     ParamByName ("N_BALLS") -> AsSmallInt =
        //             bal_t;
        // DM -> QShkala -> Open ();

        // if (DBLookupComboBox1 -> KeyValue == 4)                                 // отдельная шкала для белорусского и русского TLocateOptions fl1;
        //     DM -> QShkala ->
        //         Locate (
        //             "RUS_BEL",
        //             ComboBox1 -> ItemIndex,
        //             fl1
        //         );

        // if (nom_fac == 4)
        //     Label14 -> Caption =
        //         IntToStr (
        //             bal_t
        //         );
        // else
        //     Label14 -> Caption =
        //         IntToStr (
        //             DM -> QShkalaBALL -> Value
        //         );

        // Label14 -> Caption =
        //     DM -> ball_result (                                                 // функция возвращает результат сертификата
        //         bal_t,
        //         nom_fac
        //     );
        // if (nom_fac != 4)
        //     Label14 -> Caption =
        //         FloatToStrF (
        //             DM -> ball_result_float (
        //                 bal_t,
        //                 nom_fac
        //             ),
        //             ffFixed,
        //             4,
        //             1
        //         );
        // else
        //     Label14 -> Caption =
        //         FloatToStrF (
        //             DM -> ball_result_float (
        //                 bal_t,
        //                 nom_fac
        //             ),
        //             ffFixed,
        //             3,
        //             0
        //         );

        int rus_b;

        if (DBLookupComboBox1 -> KeyValue == 4)                                 // предмет русский или белорусский язык
            rus_b = ComboBox1 -> ItemIndex;
        else
            rus_b = 2;

        if (nom_fac != 4)
            Label14 -> Caption =
                FloatToStrF (
                    bal_t,
                    ffFixed,
                    4,
                    1
                );
        else
            if (    AbiturForm -> TermEduCmbBx -> ItemIndex == 1
                 || AbiturForm -> TermEduCmbBx -> ItemIndex == 2
               )
                Label14 -> Caption =
                    FloatToStrF (
                        bal_t,
                        ffFixed,
                        4,
                        1
                    );
        else
            Label14 -> Caption =
                FloatToStrF (
                    bal_t,
                    ffFixed,
                    3,
                    0
                );

        if (    DBLookupComboBox1 -> KeyValue == 2
             && bal_t                         <  101
           )
            Label14 -> Caption =
                FloatToStrF (
                    bal_t,
                    ffFixed,
                    3,
                    0
                );
    }
    else
    {
        Label14 -> Caption = "";
        // MaskEdit1 -> SetFocus ();
    }
}
void __fastcall TSertificatForm::refrech_sertificat ()                          // проверка наличия сертификата
{
    nom = DM -> QAbituraNOMER_AB -> Value;

    if (DM -> QSertificat -> RecordCount)                                       // отозражаем данные сертификата выделенного в Gride
    {

        Edit1             -> Text     = DM -> QSertificatSERIA_S   -> Value;    // серия сертификата
        Edit2             -> Text     = DM -> QSertificatNOMER_S   -> Value;    // номер сертификата
        Edit3             -> Text     = DM -> QSertificatDESCRIBE  -> Value;    // документ удостоверяющий личность
        Edit4             -> Text     = DM -> QSertificatYEAR_S    -> Value;    // год выдачи
        DBLookupComboBox1 -> KeyValue = DM -> QSertificatN_PREDMET -> Value;    // предмет

        if (DM -> QSertificatN_PREDMET -> Value == 4)                           // предмет русский или белорусский
        {
            Label5    -> Visible = true;
            ComboBox1 -> Visible = true;

            Variant v =
                DM -> QSertificatRUS_BEL -> AsVariant;

            if (! v.IsNull ())
                ComboBox1 -> ItemIndex =
                    DM -> QSertificatRUS_BEL -> Value;
            else
                ComboBox1 -> ItemIndex = -1;
        }
        else
        {
            Label5    -> Visible = false;
            ComboBox1 -> Visible = false;

            ComboBox1 -> Text = "";
        }

        MaskEdit1 -> Text =                                                     // баллы на тестировании
            DM -> QSertificatBALLS -> Value;
        /*
         if (nom_fac!= 4)
         {
         //проверка по шкале на полученный балл
         DM -> QShkala -> Close ();
         DM -> QShkala -> ParamByName ("N_PR") -> AsSmallInt = DBLookupComboBox1 -> KeyValue;
         DM -> QShkala -> ParamByName ("N_BALL") -> AsSmallInt = DM -> QSertificatBALLS -> Value;
         DM -> QShkala -> ParamByName ("N_BALLS") -> AsSmallInt = DM -> QSertificatBALLS -> Value;
         DM -> QShkala -> Open ();

         Label14 -> Caption = IntToStr (DM -> QShkalaBALL -> Value);
         }
         else Label14 -> Caption = DM -> QSertificatBALLS -> Value;

         //функция, которая возвращает результат сертификата
         //Label14 -> Caption = DM -> ball_result (DM -> QSertificatBALLS -> Value,
         nom_fac);
         */

        int rus_b;

        if (DM -> QSertificatN_PREDMET -> Value == 4)                           // белорусский или русский
            rus_b = DM -> QSertificatRUS_BEL -> Value;
        else
            rus_b = 2;


        // DM -> ball_result_float (                                               // функция, которая возвращает результат сертификата
        //     int b,                                                              // Стобальная оценка
        //     int predmet,                                                        // предмет
        //     int rus_bel                                                         // флаг (0 - рус, 1- бел, 2 - остальные)
        // )


        if (nom_fac != 4)
            Label14 -> Caption =
                FloatToStrF (
                    DM -> ball_result_float (
                        DM -> QSertificatBALLS     -> Value,
                        DM -> QSertificatN_PREDMET -> Value,
                        rus_b,
                        AbiturForm -> KonkursCmbBx -> ItemIndex
                    ),
                    ffFixed,
                    4,
                    1
                );
        else
            if (    AbiturForm -> TermEduCmbBx -> ItemIndex == 1
                 || AbiturForm -> TermEduCmbBx -> ItemIndex == 2
               )
                Label14 -> Caption =
                    FloatToStrF (
                        DM -> ball_result_float (
                            DM -> QSertificatBALLS     -> Value,
                            DM -> QSertificatN_PREDMET -> Value,
                            rus_b,
                            AbiturForm -> KonkursCmbBx -> ItemIndex
                        ),
                        ffFixed,
                        4,
                        1
                    );
        else
            Label14 -> Caption =
                FloatToStrF (
                    DM -> ball_result_float (
                        DM -> QSertificatBALLS     -> Value,
                        DM -> QSertificatN_PREDMET -> Value,
                        rus_b,
                        AbiturForm -> KonkursCmbBx -> ItemIndex
                    ),
                    ffFixed,
                    3,
                    0
                );

        DBLookupComboBox1 -> Enabled = false;                                   // делаем недоступным изменение предмета
        state_sertificat             = true;                                    // общая переменная когда есть уже сертификат
    }
    else
    {
        Edit1 -> Text = "";                                                     // серия сертификата
        Edit2 -> Text = "";                                                     // номер сертификата

        if (AbiturForm -> PasportDBEdt -> Text != "")                          // документ удостоверяющий личности
            Edit3 -> Text =
                "паспорт "                              +
                    AbiturForm -> PasportDBEdt -> Text;
        else
            Edit3 -> Text = "";

        DBLookupComboBox1 -> KeyValue = -1;                                     // предмет
        DBLookupComboBox1 -> Enabled  = true;                                   // делаем доступным изменение предмета
        Label5            -> Visible  = false;                                  // язык
        ComboBox1         -> Visible  = false;
        MaskEdit1         -> Text     = "";                                     // баллы на тестировании
        ComboBox1         -> Text     = "";

        state_sertificat = false;                                               // общая переменная когда нет сертификата
    }
}
void __fastcall TSertificatForm::seria_sertificat (AnsiString seria)            // функция возвращает по серии сертификата предмет
{
    seria =
        seria.SubString (
            1,
            2
        );

    DBLookupComboBox1 -> KeyValue = -1;

    if (    seria == "01"                                                       // "01" - русский
         || seria == "02"                                                       // "02" - белорусский
       )
    {
        DBLookupComboBox1 -> KeyValue = 4;

        Label5    -> Visible = true;
        ComboBox1 -> Visible = true;

        if (seria == "01")
            ComboBox1 -> ItemIndex = 0;
        else
            ComboBox1 -> ItemIndex = 1;
    }
    else
    {
        Label5    -> Visible = false;
        ComboBox1 -> Visible = false;

        ComboBox1 -> Text = "";

        if (seria == "04")                                                      // "04" - математика
            DBLookupComboBox1 -> KeyValue = 9;
        if (seria == "06")                                                      // "06" - биология
            DBLookupComboBox1 -> KeyValue = 1;
        if (seria == "13")                                                      // "13" - география
            DBLookupComboBox1 -> KeyValue = 10;
    }
}
void __fastcall TSertificatForm::SpeedButton1Click (TObject * Sender)
{
    DBNavigator1 -> BtnClick (nbInsert);
}
bool __fastcall TSertificatForm::summa_b (int n)                                // СУММИРОВАНИЕ РЕЗУЛЬТАТОВ ЭКЗАМЕНОВ (с учетом сертификата) (n - номер абитуриента)
{
    try
    {
        DM -> QSum_Ball_Nomer -> Close ();
        DM -> QSum_Ball_Nomer ->
            ParamByName ("NOMER") -> AsInteger = n;
        DM -> QSum_Ball_Nomer -> Open ();

        if (!DM -> QSum_Ball_Nomer -> RecordCount)
            return
                false;

        DM -> QSum_Ball_Nomer -> Edit ();                                       // редактируем

        DM -> QSum_Ball_NomerSUM_BALL -> Value =
              DM -> QSum_Ball_NomerSUM         -> Value
            + DM -> QSum_Ball_NomerMIDDLE_BALL -> Value;

        DM -> QSum_Ball_Nomer -> ApplyUpdates ();                               // сохраняем
        DM -> QSum_Ball_Nomer -> CommitUpdates ();

        return
            true;
    }
    catch (...)
    {
        return
            false;
    }
}

