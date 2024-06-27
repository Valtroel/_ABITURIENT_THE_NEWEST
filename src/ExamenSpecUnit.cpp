#include <vcl.h>
#pragma hdrstop


#include "ExamenSpecUnit.h"
#include "DMUnit.h"
#include "Func.h"


#pragma package (smart_init)
// #pragma link "RXToolEdit"
#pragma resource "*.dfm"



TExamenSpecForm * ExamenSpecForm;



AnsiString *
    mas_fio_nomdela2 [3];

AnsiString
    kindOfSportName = "",
    profiling       = "Специальность (профилизация)",
    vid_ed2;                                                                    // хранит вида обучения

int
    col_ab2,
    kindOfSportCode = 0,
    mas_vip         = 0;                                                        // флаг наличия данных в массиве 0 - нет, 1 - есть

Variant
    ExApp;


__fastcall TExamenSpecForm::TExamenSpecForm (TComponent * Owner)
    : TForm (Owner)
{
    DateTimePicker1 -> Date =
        (Now ())
            .FormatString (
                "dd.mm.yyyy"
            );

    TDateTime
        currentDate;

    AnsiString
        currentHours =
            AnsiToUtf8 (
                currentDate.CurrentTime ()
            )
            .SetLength (2);

    if (currentHours.IsDelimiter ("\\:", 2))
        currentHours = currentHours.SetLength (1);

    MaskEdit1       -> EditText =
        currentHours + ".00";

    // AnsiString
    //     n_file =
    //             DocumentName::SUMMARY_LIST::ENTRANCE_EXAMS  +
    //         " "                                             +
    //             Edit1             -> Text                   +
    //         ", по "                                         +
    //             DBLookupComboBox1 -> Text                   +
    //         ", за "                                         +
    //             DateToStr (
    //                 DateTimePicker1 -> Date
    //             )                                           +
    //         ".xls";

    #ifdef TESTING_EXAMENN_SPEC_UNIT
    AnsiString
        err_access_denied =
            "«"                                                                +
                DeleteAfterDatabaseChange::getNcrb2022NameSportStrByNSpecializ (
                    DM -> QExamSpecN_SPECIALIZ -> Value
                )                                                              +
            "»";
            //DateToStr (
            //    DateTimePicker1 -> Date
            //);

    ShowMessage (
        err_access_denied
    );
    #endif
}



void __fastcall TExamenSpecForm::Button1Click (TObject * Sender)
{
    int
        n = DM -> QAbituraN_SPECIALIZ -> Value;
    String
        new_num_dela;

    if (    DBLookupComboBox1 -> Text ==                                        // проверка ведомость должна быть на спец. или СФП или ОФП
                "Основы теории и методики спортивной тренировки"
         || DBLookupComboBox1 -> Text ==
                "Физическая культура и спорт"
         || DBLookupComboBox1 -> Text ==
                "Организация туризма"
         || DBLookupComboBox1 -> Text ==
                "Маркетинг туризма"
         || DBLookupComboBox1 -> Text ==
                "Экскурсоведение"
         || DBLookupComboBox1 -> Text ==
                "Белорусский (русский) язык"
         || DBLookupComboBox1 -> Text ==
                "Теория и методика физического воспитания"
         || DBLookupComboBox1 -> Text ==
                "Основы медицинских знаний"
         || DBLookupComboBox1 -> Text ==
                "Биология"
       )
    {
        AnsiString
            text_test_rus   = "Тест рус.",
            text_test_bel   = "Тест бел.",
            text_test_biol  = "Тест биол.",
            text_test_matem = "Тест матем.",
            text_test_geogr = "Тест геогр.",
            text_soch_rus   = "Изл. рус.",
            text_soch_bel   = "Изл. бел.",
            text_spec       = "Специализ.";

        if (Edit1 -> Text != "")                                                // Если не пустой номер группы
        {
            SG1          -> Visible = true;
            SpeedButton1 -> Visible = true;
            SpeedButton2 -> Visible = true;
            SpeedButton3 -> Visible = true;
            SpeedButton4 -> Visible = true;
            SpeedButton5 -> Visible = true;
            Panel2       -> Visible = true;
            ListBox1     -> Visible = true;

            for (int i = 1;                                                     // очищаем StringGrid
                     i < SG1 -> RowCount;
                     ++i
                )
                for (int j = 0;
                         j < 3;
                         ++j
                    )
                    SG1 -> Cells[j][i] = "";

            ListBox1 -> Clear ();

            AnsiString
                SQL_Text =
                    " SELECT"                                           \
                    "     abitura.fam,"                                 \
                    "     abitura.n_fac,"                               \
                    "     examen.ball,"                                 \
                    "     examen.status_ball,"                          \
                    "     examen.n_predmet,"                            \
                    "     abitura.name,"                                \
                    "     abitura.otch,"                                \
                    "     abitura.pol,"                                 \
                    "     abitura.konkurs,"                             \
                    "     abitura.nom_dela,"                            \
                    "     abitura.vid_edu,"                             \
                    "     abitura.nomer_ab,"                            \
                    "     abitura.rus_bel,"                             \
                    "     examen.nom_ball,"                             \
                    "     abitura.without,"                             \
                    "     abitura.term_edu,"                            \
                    "     abitura.education,"                           \
                    "     abitura.category_if,"                         \
                    "     abitura.n_sport_category,"                    \
                    "     abitura.price,"                               \
                    "     abitura.n_specializ,"                         \
                    "     abitura.disabled"                             \
                    " FROM"                                             \
                    "     abitura"                                      \
                    "         LEFT OUTER JOIN"                          \
                    "             examen"                               \
                    "         ON"                                       \
                    "            abitura.nomer_ab = examen.nomer_ab"    \
                    " WHERE"                                            \
                    "         abitura.status      = 0"                  \
                    "     AND"                                          \
                    "         abitura.nom_group   = :n_gr"              \
                    "     AND"                                          \
                    "         abitura.n_fac       = :n_fac";
            AnsiString
                SQLShort =
                    "     AND"                                          \
                    "         abitura.term_edu IN (1,2)";
            AnsiString
                SQL_End =
                    " ORDER BY"                                         \
                    "     abitura.fam,"                                 \
                    "     abitura.name,"                                \
                    "     abitura.otch,"                                \
                    "     examen.n_predmet";
            AnsiString
                SQL_Text_count =
                    " SELECT"                                           \
                    "     COUNT"                                        \
                    "     ("                                            \
                    "         nomer_ab"                                 \
                    "     )"                                            \
                    " FROM"                                             \
                    "     abitura"                                      \
                    " WHERE"                                            \
                    "         n_fac       = :n_fac"                     \
                    "     AND"                                          \
                    "         status      = 0"                          \
                    "     AND"                                          \
                    "         nom_group   = :n_gr";

            DM -> QExamSpec -> Close ();                                        // Построение списка абитуриентов
            DM -> QExamSpec -> SQL -> Clear ();

            DM -> QGroup_Count_Spec -> Close ();                                // Подсчёт количества абитуриентов в группе
            DM -> QGroup_Count_Spec -> SQL -> Clear ();

            if (    DBLookupComboBox1 -> Text ==
                        "Основы теории и методики спортивной тренировки"
                 || DBLookupComboBox1 -> Text ==
                        "Организация туризма"
                 || DBLookupComboBox1 -> Text ==
                        "Маркетинг туризма"
                 || DBLookupComboBox1 -> Text ==
                        "Экскурсоведение"
                 || DBLookupComboBox1 -> Text ==
                        "Теория и методика физического воспитания"
                 || DBLookupComboBox1 -> Text ==
                        "Основы медицинских знаний"
                 || DBLookupComboBox1 -> Text ==
                        "Биология"
               )
            {                                                                   // только для 2 курса
                DM -> QExamSpec ->
                    SQL -> Add (
                        SQL_Text    +
                        SQLShort    +
                        SQL_End
                    );
                DM -> QGroup_Count_Spec ->
                    SQL -> Add (
                        SQL_Text_count +
                        SQLShort
                    );
            }
            else                                                                // 1 курс
            {
                DM -> QExamSpec ->
                    SQL -> Add (
                        SQL_Text    +
                        SQL_End
                    );
                DM -> QGroup_Count_Spec ->
                    SQL -> Add (
                        SQL_Text_count
                    );
            }

            DM -> QExamSpec ->
                ParamByName ("N_FAC") -> Value    = nom_fac;
            DM -> QExamSpec ->                                                  // Список студентов группы
                ParamByName ("N_GR")  -> AsString = Edit1  -> Text;
            DM -> QExamSpec -> Open ();

            DM -> QGroup_Count_Spec ->                                          // Количество студентов в группе
                ParamByName ("N_FAC") -> Value    = nom_fac;
            DM -> QGroup_Count_Spec ->
                ParamByName ("N_GR")  -> AsString = Edit1  -> Text;
            DM -> QGroup_Count_Spec -> Open ();


            col_ab2         =
                DM -> QGroup_Count_SpecCOUNT -> Value;                          // Количство студентов в группе

            kindOfSportCode =
                DM -> QExamSpecN_SPECIALIZ   -> Value;

            kindOfSportName =
                DeleteAfterDatabaseChange::getNcrb2022NameSportStrByNSpecializ (
                    kindOfSportCode
                );


            if (!col_ab2)
            {
                ShowMessage (
                    "Нет таких абитуриентов!"
                );

                return
                    Edit1Change (this);
            }

            if (mas_vip)
            {
                for (int i = 0;
                         i < 3;
                         ++i
                    )
                    if (mas_fio_nomdela2)
                        delete [] mas_fio_nomdela2[i];

                mas_vip = 0;
            }

            for (int i = 0;
                     i < 3;
                     ++i
                )
                mas_fio_nomdela2[i] =
                    new AnsiString[col_ab2];

            mas_vip = 1;

            SG1 -> RowCount = col_ab2 + 1;

            if (!DM -> QExamSpecVID_EDU -> Value)
                vid_ed2 = "Дневная форма получения образования";
            else
                vid_ed2 = "Заочная форма получения образования";

            AnsiString
                bal,
                fam,
                str        = "";

            int
                n_abit;                                                         // ФИО с номером дела


            for (int i = 1;
                     i <= col_ab2;
                     ++i
                )
            {
                new_num_dela =
                    DM -> NumDelaString (
                        DM -> QExamSpecVID_EDU  -> Value,
                        DM -> QExamSpecTERM_EDU -> Value,
                        DM -> QExamSpecPRICE    -> Value,
                        DM -> QExamSpecNOM_DELA -> Value
                    );

                n_abit =
                    DM -> QExamSpecNOMER_AB -> Value;

                fam =
                    DM -> QExamSpecFAM      -> Value;

                str =
                        fam                     +
                    " "                         +
                        DM -> QExamSpecNAME ->
                            Value.SubString (
                                1,
                                1
                            )                   +
                    ".";

                if (    DM -> QExamSpecOTCH -> Value != ""
                     || DM -> QExamSpecOTCH -> Value != "-"
                   )
                    str +=
                        " "                         +
                            DM -> QExamSpecOTCH ->
                                Value.SubString (
                                    1,
                                    1
                                )                   +
                        ". ["                       +
                            new_num_dela            +
                        "]";

                mas_fio_nomdela2[0][i - 1] = str;
                mas_fio_nomdela2[1][i - 1] = new_num_dela;
                mas_fio_nomdela2[2][i - 1] = DM -> QExamSpecNOMER_AB -> Value;

                SG1 -> Cells[0][i] = str;                                       // StringGrid 1-ая колонка


                switch (DM -> QExamSpecTERM_EDU -> Value)                       // StringGrid 2-ая колонка
                {
                    case 1:
                            SG1 -> Cells[1][i] = "ССО 2к.";
                        break;
                    case 2:
                            SG1 -> Cells[1][i] = "ССО 3к.";
                        break;
                    case 3:
                            SG1 -> Cells[1][i] = "ВО 1к.";
                        break;
                    case 4:
                            SG1 -> Cells[1][i] = "ВО 2к.";
                        break;
                    case 5:
                            SG1 -> Cells[1][i] = "ВО 3к.";
                        break;
                    default:
                        SG1 -> Cells[1][i] = "";
                }

                switch (DM -> QExamSpecKONKURS -> Value)
                {
                    case 1:
                            if (SG1 -> Cells[1][i] == "")
                                SG1 -> Cells[1][i] =
                                    "БВИ";
                            else
                                SG1 -> Cells[1][i] =
                                        SG1 -> Cells[1][i]  +
                                    ", БВИ";
                        break;
                    case 2:
                            if (SG1 -> Cells[1][i] == "")
                                SG1 -> Cells[1][i] =
                                    "ВК";
                            else
                                SG1 -> Cells[1][i] =
                                        SG1 -> Cells[1][i]  +
                                    ", ВК";
                        break;
                    case 3:
                            if (SG1 -> Cells[1][i] == "")
                                SG1 -> Cells[1][i] =
                                    "ЦК";
                            else
                                SG1 -> Cells[1][i] =
                                        SG1 -> Cells[1][i]  +
                                    ", ЦК";
                        break;
                }

                switch (DM -> QExamSpecN_SPORT_CATEGORY -> Value)
                {
                    case 5:
                            if (SG1 -> Cells[1][i] == "")
                                SG1 -> Cells[1][i] =
                                    "МС";
                            else
                                SG1 -> Cells[1][i] =
                                        SG1 -> Cells[1][i]  +
                                    ", МС";
                        break;
                    case 6:
                            if (SG1 -> Cells[1][i] == "")
                                SG1 -> Cells[1][i] =
                                    "МСМК";
                            else
                                SG1 -> Cells[1][i] =
                                        SG1 -> Cells[1][i]  +
                                    ", МСМК";
                        break;
                    case 7:
                            if (SG1 -> Cells[1][i] == "")
                                SG1 -> Cells[1][i] =
                                    "ЗМС";
                            else
                                SG1 -> Cells[1][i] =
                                        SG1 -> Cells[1][i]  +
                                    ", ЗМС";
                        break;
                }

                if (DM -> QExamSpecCATEGORY_IF -> Value)
                {
                    if (SG1 -> Cells[1][i] == "")
                        SG1 -> Cells[1][i] =
                            "Иностранец";
                    else
                        SG1 -> Cells[1][i] =
                                SG1 -> Cells[1][i]  +
                            ", Иностранец";
                }

                if (DM -> QExamSpecN_PREDMET -> Value)
                {
                    AnsiString text_pr =
                        DM -> QExamSpecPREDM -> Value;

                    if (    text_pr == "Белорусский (русский) язык"
                         || text_pr == "Биология"
                         || text_pr == "Математика"
                         || text_pr == "География"
                       )
                    {
                        switch (DM -> QExamSpecSTATUS_BALL -> Value)                        // 0 - экзамен, 1 - тестирование, 2 - Олимпиады БГУ
                        {
                            case 0:                                                         // экзамен
                                    if (DM -> QExamSpecN_PREDMET -> Value == 4)             // языки
                                        if (DM -> QExamSpecRUS_BEL -> Value)
                                            bal =
                                                    text_soch_bel                       +
                                                " - "                                   +
                                                    AnsiString (
                                                        DM -> QExamSpecBALL1 -> Value
                                                    );
                                        else
                                            bal =
                                                    text_soch_rus                       +
                                                " - "                                   +
                                                    AnsiString (
                                                        DM -> QExamSpecBALL1 -> Value
                                                    );

                                    if (    DM -> QExamSpecN_PREDMET -> Value == 1          // биология, математика, география
                                         || DM -> QExamSpecN_PREDMET -> Value == 9
                                         || DM -> QExamSpecN_PREDMET -> Value == 10
                                       )
                                            bal =
                                                    DM -> QExamSpecPREDM -> Value       +
                                                " - "                                   +
                                                    AnsiString (
                                                        DM -> QExamSpecBALL1 -> Value
                                                    );
                                break;
                            case 2:                                                         // Олимпиада
                                    bal =
                                            DM -> QExamSpecPREDM -> Value       +
                                        " (олимп.) - "                          +
                                            AnsiString (
                                                DM -> QExamSpecBALL1 -> Value
                                            );
                                break;
                            case 1:                                                         // тестирование
                                    DM -> QSertificat -> Close ();
                                    DM -> QSertificat ->
                                        ParamByName ("NOMER") -> AsInteger =
                                            DM -> QExamSpecNOMER_AB -> Value;
                                    DM -> QSertificat -> Open ();

                                    int st_test =
                                        DM -> QSertificat ->
                                            Lookup (
                                                "NOMER_AB;N_PREDMET",
                                                VarArrayOf (
                                                    OPENARRAY (
                                                        Variant,
                                                        (
                                                            DM -> QExamSpecNOMER_AB  -> Value,
                                                            DM -> QExamSpecN_PREDMET -> Value
                                                        )
                                                    )
                                                ),
                                                "RUS_BEL"
                                            );

                                    switch (st_test)
                                    {
                                        case 0:                                                 // русский
                                                bal =
                                                        text_test_rus                       +
                                                    " - "                                   +
                                                        AnsiString (
                                                            DM -> QExamSpecBALL1 -> Value
                                                        );
                                            break;
                                        case 1:                                                 // белорусский
                                                bal =
                                                        text_test_bel                       +
                                                    " - "                                   +
                                                        AnsiString (
                                                            DM -> QExamSpecBALL1 -> Value
                                                        );
                                            break;
                                        case 2:                                                 // биология
                                                bal =
                                                        text_test_biol                      +
                                                    " - "                                   +
                                                        AnsiString (
                                                            DM -> QExamSpecBALL1 -> Value
                                                        );
                                            break;
                                        case 3:                                                 // математика
                                                bal =
                                                        text_test_matem                     +
                                                    " - "                                   +
                                                        AnsiString (
                                                            DM -> QExamSpecBALL1 -> Value
                                                        );
                                            break;
                                        case 4:                                                 // география
                                                bal =
                                                        text_test_geogr                     +
                                                    " - "                                   +
                                                        AnsiString (
                                                            DM -> QExamBALL1 -> Value
                                                        );
                                            break;
                                    }
                                break;
                        }
                    }
                    else
                    {
                        bal =
                                DM -> QExamSpecPREDM -> Value       +
                            " - "                                   +
                                AnsiString (
                                    DM -> QExamSpecBALL1 -> Value
                                );
                    }
                    DM -> QExamSpec -> Next ();

                    while (     n_abit == DM -> QExamSpecNOMER_AB -> Value
                            && !DM -> QExamSpec -> Eof
                          )
                    {
                        text_pr = DM -> QExamSpecPREDM -> Value;

                        if (    text_pr == "Белорусский (русский) язык"
                             || text_pr == "Биология"
                             || text_pr == "Математика"
                             || text_pr == "География"
                           )
                        {
                            switch (DM -> QExamSpecSTATUS_BALL -> Value)                // 0 - экзамен, 1 - тестирование, 2 - Олимпиады БГУ
                            {
                                case 0:                                                 // экзамен
                                        if (DM -> QExamSpecN_PREDMET -> Value == 4)     // языки
                                            if (DM -> QExamSpecRUS_BEL -> Value)
                                                bal +=
                                                    "; "                                    +
                                                        text_soch_bel                       +
                                                    " - "                                   +
                                                        AnsiString (
                                                            DM -> QExamSpecBALL1 -> Value
                                                        );
                                            else
                                                bal +=
                                                    "; "                                    +
                                                        text_soch_rus                       +
                                                    " - "                                   +
                                                        AnsiString (
                                                            DM -> QExamSpecBALL1 -> Value
                                                        );

                                        if (    DM -> QExamSpecN_PREDMET -> Value == 1      // биология, математика, география
                                             || DM -> QExamSpecN_PREDMET -> Value == 9
                                             || DM -> QExamSpecN_PREDMET -> Value == 10
                                           )
                                                bal +=
                                                    "; "                                +
                                                        DM -> QExamSpecPREDM -> Value   +
                                                    " - "                               +
                                                        AnsiString (
                                                            DM -> QExamSpecBALL1 -> Value
                                                        );
                                    break;
                                case 2:                                                     // Олимпиада
                                        bal +=
                                            "; "                                    +
                                                DM -> QExamSpecPREDM -> Value       +
                                            " (олимп.) - "                          +
                                                AnsiString (
                                                    DM -> QExamSpecBALL1 -> Value
                                                );
                                    break;
                                case 1:                                                     // тестирование
                                        DM -> QSertificat -> Close ();
                                        DM -> QSertificat ->
                                            ParamByName ("NOMER") -> AsInteger =
                                                DM -> QExamSpecNOMER_AB -> Value;
                                        DM -> QSertificat -> Open ();

                                        int st_test =
                                            DM -> QSertificat ->
                                                Lookup (
                                                    "NOMER_AB;N_PREDMET",
                                                    VarArrayOf (
                                                        OPENARRAY (
                                                            Variant,
                                                            (
                                                                DM -> QExamSpecNOMER_AB  -> Value,
                                                                DM -> QExamSpecN_PREDMET -> Value
                                                            )
                                                        )
                                                    ),
                                                    "RUS_BEL"
                                                );

                                        switch (st_test)
                                        {
                                            case 0:                                         // русский
                                                    bal +=
                                                        "; "                                    +
                                                            text_test_rus                       +
                                                        " - "                                   +
                                                            AnsiString (
                                                                DM -> QExamSpecBALL1 -> Value
                                                            );
                                                break;
                                            case 1:                                         // белорусский
                                                    bal +=
                                                        "; "                                    +
                                                            text_test_bel                       +
                                                        " - "                                   +
                                                            AnsiString (
                                                                DM -> QExamSpecBALL1 -> Value
                                                            );
                                                break;
                                            case 2:                                         // биология
                                                    bal +=
                                                        "; "                                    +
                                                            text_test_biol                      +
                                                        " - "                                   +
                                                            AnsiString (
                                                                DM -> QExamSpecBALL1 -> Value
                                                            );
                                                break;
                                            case 3:                                         // математика
                                                    bal +=
                                                        "; "                                    +
                                                            text_test_matem                     +
                                                        " - "                                   +
                                                            AnsiString (
                                                                DM -> QExamSpecBALL1 -> Value
                                                            );
                                                break;
                                            case 4:                                         // география
                                                    bal +=
                                                        "; "                                    +
                                                            text_test_geogr                     +
                                                        " - "                                   +
                                                            AnsiString (
                                                                DM -> QExamSpecBALL1 -> Value
                                                            );
                                                break;
                                        }
                                    break;
                            }
                        }
                        else
                        {
                            bal +=
                                "; "                                    +
                                    DM -> QExamSpecPREDM -> Value       +
                                " - "                                   +
                                    AnsiString (
                                        DM -> QExamSpecBALL1 -> Value
                                    );
                        }
                        DM -> QExamSpec -> Next ();
                    }
                    SG1 -> Cells[2][i] = bal;
                }
                else
                    DM -> QExamSpec -> Next ();
            }
            ExamenSpecForm -> Height = 704;
        }
        else
        {
            ShowMessage (
                "Не введен номер группы"
            );

            Edit1 -> SetFocus ();
        }
    }
    else
    {
        if (n != 4)
            ShowMessage (
                "Ведомость должна быть по основам теории "          \
                "и методики спортивной тренировки");
        else
            ShowMessage (
                "Ведомость должна быть по организации туризма "     \
                "или маркетингу туризма или экскурсоведению"
            );
    }
}
void __fastcall TExamenSpecForm::Button2Click (TObject * Sender)
{
    if (ListBox1 -> Items -> Count)
    {
        AnsiString
            list_fio   = "";

        int
            list_count = ListBox1 -> Items -> Count;

        if(RG1 -> ItemIndex == 1)
            profiling =
                "Специальность (направление специальности, специализация)";

        for (int i = 0;                                                         // Проверка на наличие повторно включённых в список TODO: deleteDuplicateEntries (int enteryNumber)
                 i < list_count - 1;
                 ++i
            )
        {
            if (    ListBox1 -> Items -> Strings[i]
                 == ListBox1 -> Items -> Strings[i + 1]
               )
            {
                list_fio =
                    "Абитуриент "                           +
                        ListBox1 -> Items -> Strings[i]     +
                    " уже выбран в списке";

                AnsiString
                    ansi_string1 = "Удалить из списка вторую копию?";

                wchar_t * UnicodeString1 =
                    new wchar_t[ansi_string1.WideCharBufSize ()];

                ansi_string1.WideChar (
                    UnicodeString1,
                    ansi_string1.WideCharBufSize ()
                );

                ansi_string1 = list_fio.c_str ();

                wchar_t * UnicodeString2 =
                    new wchar_t[ansi_string1.WideCharBufSize ()];

                ansi_string1.WideChar (
                    UnicodeString2,
                    ansi_string1.WideCharBufSize ()
                );

                if (    Application -> MessageBox (
                            UnicodeString1,
                            UnicodeString2,
                            MB_YESNO
                        ) == IDYES
                    )
                {
                    ListBox1 -> ItemIndex = i;
                    ListBox1 -> Items ->
                        Delete (
                            ListBox1 -> ItemIndex
                        );

                    --list_count;
                    --i;
                }
                if (UnicodeString1)
                    delete [] UnicodeString1;
                if (UnicodeString2)
                    delete [] UnicodeString2;
            }
        }

        if (DBLookupComboBox1 -> Text != "")                                    // если заполнены дисциплина
        {
            int n_pr = DBLookupComboBox1 -> KeyValue;                           // переменная для занесения в EXAMEN номера предмета

            if (!DM -> QResult_Exam -> Active)                                  // Проверка абитуриентов на наличие в таблице результатов экзаменов
                DM -> QResult_Exam -> Open ();

            AnsiString
                sss = "";

            TLocateOptions
                flag;

            for (int i = 0;
                     i < ListBox1 -> Items -> Count;
                     ++i
                )
            {
                if (    DM -> QResult_Exam ->
                            Locate (
                                "NOMER_AB;N_PREDMET",
                                VarArrayOf (
                                    OPENARRAY (
                                        Variant,
                                        (
                                            StrToInt (
                                                search_nomdela2 (
                                                    col_ab2,
                                                    ListBox1 -> Items -> Strings[i],
                                                    2
                                                )
                                            ),
                                            n_pr
                                        )
                                    )
                                ),
                                flag
                            )
                   )
                {
                    sss += ListBox1 -> Items -> Strings[i] + ". ";
                }
            }

            if (sss == "")                                                      // if  проверки на отсутствие в таблице результатов экзаменов
            {
                ExApp =
                    Variant::CreateObject (
                        "Excel.Application"
                    );

                Variant Workbook =
                    OpenBook (
                        ExApp,
                        cur_dir                         +
                        DocumentFile::PROTOCOL::exam
                    );

                Variant Sheet =
                    SelectSheet (
                        Workbook,
                        "Экзаменационная ведомость"
                    );

                // !!!OVisible (ExApp);

                CellValue (                                                     // факультет
                    fac1,
                    3,
                    10
                );
                CellValue (                                                     // вид обучения
                    vid_ed2,
                    1,
                    4
                );
                CellValue (                                                     // "Специальность (профилизация)" / "Специальность (направление специальности, специализация)
                    profiling,
                    1,
                    11
                );
                CellValue (                                                     // дата экз.
                    DateTimePicker1 -> Date,
                    3,
                    12
                );
                CellValue (                                                     // группа
                    "группа № "         +
                        Edit1 -> Text,
                    7,
                    10
                );
                CellValue (                                                     // предмет
                    DBLookupComboBox1 -> Text,
                    4,
                    8
                );
                CellValue (                                                     // начало экз.
                    MaskEdit1 -> EditText,
                    3,
                    13
                );


                if(RG1 -> ItemIndex == 0)
                    CellValue (
                        escapingStringWithDoubleQuotes (
                            kindOfSportName
                        ),
                        3,
                        11
                    );
                else
                    CellValue (
                        DM -> vozvrat_spec (
                            kindOfSportCode
                        ),
                        3,
                        11
                    );


                int
                    n_st = 19;                                                  // первая строка для занесения фамилий

                for (int i = 0;
                         i < ListBox1 -> Items -> Count;
                         ++i
                    )
                {
                    AnsiString
                        List_text = ListBox1 -> Items -> Strings[i];

                    int
                        j         = List_text.Pos ('[');


                    List_text =
                        List_text.SubString (                                   // Урезаем запись до нужной для базы данных
                            1,
                            j - 1
                        );
                    CellValue (                                                 // Вывод фамилии и инициалов
                        List_text,
                        2,
                        n_st
                    );
                    CellValue (                                                 // номер экз. листа
                        search_nomdela2 (
                            col_ab2,
                            ListBox1 -> Items -> Strings[i],
                            1
                        ),
                        3,
                        n_st++
                    );


                    DM -> QResult_Exam -> Insert ();                            // занесение в EXAMEN записей [N_AB,N_PR]

                    DM -> QResult_ExamNOMER_AB -> Value =
                        StrToInt (
                            search_nomdela2 (
                                col_ab2,
                                ListBox1 -> Items -> Strings[i],
                                2
                            )
                        );
                    DM -> QResult_ExamN_PREDMET -> Value = n_pr;

                    DM -> QResult_Exam          -> ApplyUpdates ();
                    DM -> QResult_Exam          -> CommitUpdates ();
                }

                DM -> QResult_Exam -> Close ();


                Variant Sheet2 =
                    SelectSheet (
                        Workbook,
                        "Инструктаж"
                    );
                CellValue (                                                     // факультет
                    fac1,
                    3,
                    10
                );
                CellValue (                                                     // "Специальность (профилизация)" / "Специальность (направление специальности, специализация)
                    profiling,
                    1,
                    11
                );
                CellValue (                                                     // вид обучения
                    vid_ed2,
                    1,
                    4
                );
                CellValue (                                                     // дата экз.
                    DateTimePicker1 -> Date,
                    3,
                    12
                );
                CellValue (                                                     // группа
                    "группа № "         +
                        Edit1 -> Text,
                    7,
                    10
                );

                if(RG1 -> ItemIndex == 0)
                    CellValue (
                        escapingStringWithDoubleQuotes (
                            kindOfSportName
                        ),
                        3,
                        11
                    );
                else
                    CellValue (
                        DM -> vozvrat_spec (
                            kindOfSportCode
                        ),
                        3,
                        11
                    );

                int
                    stroka = 17;                                                // первая строка для занесения фамилий

                for (int i = 0;
                         i < ListBox1 -> Items -> Count;
                         ++i
                    )
                {
                    AnsiString List_text =
                        ListBox1 -> Items -> Strings[i];

                    int j = List_text.Pos ('[');                                // Урезаем запись до нужной для базы данных

                    List_text =
                        List_text.SubString (
                            1,
                            j - 1
                        );
                    CellValue (
                        List_text,
                        2,
                        stroka++
                    );
                }


                AnsiString
                    pol = "М";                                                  // пол абитуриента

                if (DBLookupComboBox1 -> Text == "Физическая культура и спорт") // Построение ПРОТОКОЛА с КУ
                {
                    Variant Sheet3;

                    for (int id_pol = 0;
                             id_pol < 2;
                             ++id_pol
                        )
                    {
                        switch (id_pol)                                         // выбор страницы
                        {
                            case 0:
                                    pol    = "М";
                                    Sheet3 =
                                        SelectSheet (
                                            Workbook,
                                            "КУ М"
                                        );
                                break;
                            case 1:
                                    pol    = "Ж";
                                    Sheet3 =
                                        SelectSheet (
                                            Workbook,
                                            "КУ Ж"
                                        );
                                break;
                        }

                        CellValue (                                             // факультет
                            fac1,
                            3,
                            6
                        );
                        CellValue (                                             // группа
                            Edit1 -> Text,
                            7,
                            6
                        );
                        CellValue (                                             // пол
                            pol,
                            11,
                            6
                        );
                        CellValue (                                             // "Специальность (профилизация)" / "Специальность (направление специальности, специализация)
                            profiling,
                            2,
                            8
                        );
                        CellValue (                                             // дата экз.
                            DateTimePicker1 -> Date,
                            3,
                            11
                        );
                        CellValue (                                             // время
                            MaskEdit1 -> EditText,
                            7,
                            11
                        );

                        if(RG1 -> ItemIndex == 0)
                            CellValue (
                                escapingStringWithDoubleQuotes (
                                    kindOfSportName
                                ),
                                4,
                                8
                            );
                        else
                            CellValue (
                                DM -> vozvrat_spec (
                                    kindOfSportCode
                                ),
                                4,
                                8
                            );

                        int
                            mas_id_exerc[3][2];                                 // массив с номерами КУ

                        for (int j = 0;
                                 j < 6;
                                 ++j
                            )
                        {
                            DM -> QControl_Exerc -> Close ();
                            DM -> QControl_Exerc ->
                                ParamByName ("n_specializ")   -> AsInteger    =
                                    DM -> QExamSpecN_SPECIALIZ -> Value;
                            DM -> QControl_Exerc ->
                                ParamByName ("pol")           -> AsAnsiString =
                                    pol;
                            DM -> QControl_Exerc ->
                                ParamByName ("num_exerc_grp") -> AsInteger    =
                                    j + 1;
                            DM -> QControl_Exerc -> Open ();

                            CellValue (
                                DM -> QControl_ExercNAME_EXERC -> AsString,
                                (5 + j),
                                17
                            );
                        }
                        DM -> QControl_Exerc -> Close ();

                        AnsiString
                            full_name;                                          // полное имя

                        int
                            stroka = 21;                                        // первая строка для занесения фамилий

                        for (int i = 0;                                         // по абитуриентам
                                 i < ListBox1 -> Items -> Count;
                                 ++i
                            )
                        {

                            DM -> QAbFIOPol -> Close ();                        // Вывод ФИО
                            DM -> QAbFIOPol ->
                                ParamByName ("NOMER_AB") -> AsInteger =
                                    StrToInt (
                                        search_nomdela2 (
                                            col_ab2,
                                            ListBox1 -> Items -> Strings[i],
                                            2
                                        )
                                    );
                            DM -> QAbFIOPol -> Open ();

                            if (DM -> QAbFIOPolPOL -> AsString == pol)          // выбор студентов по полу
                            {
                                full_name =
                                        DM -> QAbFIOPolFAM  -> AsString +
                                    " "                                 +
                                        DM -> QAbFIOPolNAME -> AsString +
                                    " "                                 +
                                        DM -> QAbFIOPolOTCH -> AsString;

                                CellValue (                                     // Вывод ФИО
                                    full_name,
                                    2,
                                    stroka
                                );


                                CellValue (                                     // вывод номера экзаменационного листа
                                    (
                                        search_nomdela2 (
                                            col_ab2,
                                            ListBox1 -> Items -> Strings[i],
                                            1
                                        )
                                    ),
                                    4,
                                    stroka
                                );

                                stroka += 2;
                            }
                        }
                    }
                }

                AnsiString
                    n_file =
                        DocumentName::PROTOCOL::exam    +
                    " группы "                          +
                        Edit1             -> Text       +
                    ", специализации "                  +
                        kindOfSportName                 +
                    ", по "                             +
                        DBLookupComboBox1 -> Text       +
                    ".xls";

                Variant WorkSaveAs =
                    SaveBookAs (
                        Workbook,
                        PathTo::OUTPUT_DOCUMENTS_SLASH +
                        n_file
                    );
                OVisible (
                    ExApp
                );

                ExApp.Clear ();

                Edit1Change (
                    ExamenSpecForm
                );

                if (mas_vip)
                {
                    for (int i = 0;
                             i < 3;
                             ++i
                        )
                        if (mas_fio_nomdela2)
                            delete [] mas_fio_nomdela2[i];

                    mas_vip = 0;
                }
            }
            else
                ShowMessage (
                    "Абитуриенты :\n"                                       +
                    sss                                                     +
                    "\nуже были включены в ведомость по этому предмету.\n"  \
                    "Неверный список абитуриентов на экзамен!"
                );
        }
        else
            ShowMessage (
                "Введите все данные"
            );
    }
    else
        ShowMessage (
            "Выберите абитуриентов в список на экзамен"
        );
}
void __fastcall TExamenSpecForm::DateTimePicker1Change (TObject * Sender)
{
    DateTimePicker1 -> Time = StrToTime ("00:00");
}
void __fastcall TExamenSpecForm::Edit1Change (TObject * Sender)
{
    ExamenSpecForm -> Height = 163;

    SG1            -> Visible = false;
    SpeedButton1   -> Visible = false;
    SpeedButton2   -> Visible = false;
    SpeedButton3   -> Visible = false;
    SpeedButton4   -> Visible = false;
    SpeedButton5   -> Visible = false;
    Panel2         -> Visible = false;
    ListBox1       -> Visible = false;
}
AnsiString TExamenSpecForm::escapingStringWithDoubleQuotes (
        const AnsiString wrappingString
    )
{
    return
        "«"                 +
            wrappingString  +
        "»";
}
void __fastcall TExamenSpecForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    if (mas_vip)
    {
        for (int i = 0;
                 i < 3;
                 ++i
            )
            if (mas_fio_nomdela2)
                delete [] mas_fio_nomdela2[i];

        mas_vip = 0;
    }

    this -> Close ();
}
void __fastcall TExamenSpecForm::FormCreate (TObject * Sender)
{
    SG1 -> Font -> Style = TFontStyles () << fsBold;

    SG1 -> Cells[0][0] = "ФИО";
    SG1 -> Cells[1][0] = "Конкурс";
    SG1 -> Cells[2][0] = "Оценки по экз.";
}
AnsiString TExamenSpecForm::removeDots (const AnsiString & groupNumber)
{
    return
        StringReplace (
            groupNumber,
            ".",
            "",
            TReplaceFlags () << rfReplaceAll
        );
}
AnsiString TExamenSpecForm::search_nomdela2 (
        int        col_ab,
        AnsiString fam,
        int        ind
    )
{
    AnsiString
        nomdel;

    for (int i = 0;
             i < col_ab;
             ++i
        )
    {
        if (mas_fio_nomdela2[0][i] == fam)
            switch (ind)
            {
                case 1:
                        nomdel = mas_fio_nomdela2[1][i];                        // возвр. номер дела
                    break;
                case 2:
                        nomdel = mas_fio_nomdela2[2][i];                        // возвр. номер абит.
                    break;
            }
    }

    return
        nomdel;
}
void __fastcall TExamenSpecForm::SG1DblClick (TObject * Sender)
{
    ListBox1 -> Items ->
        Add (
            SG1 -> Cells[0][SG1 -> Row]
        );
}
void __fastcall TExamenSpecForm::SpeedButton2Click (TObject * Sender)
{
    for (int i = 1;
             i < SG1 -> RowCount;
             ++i
        )
        ListBox1 -> Items ->
            Add (
                SG1 -> Cells[0][i]
            );
}
void __fastcall TExamenSpecForm::SpeedButton3Click (TObject * Sender)
{
    ListBox1 -> Items ->
        Delete (
            ListBox1 -> ItemIndex
        );
}
void __fastcall TExamenSpecForm::SpeedButton4Click (TObject * Sender)
{
    ListBox1 -> Clear ();
}
