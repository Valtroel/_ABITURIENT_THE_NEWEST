 // INCLUDES
AbiturUnit.cpp |       AbiturUnt.h
AbiturUnit.cpp | AddressLifeUnit.h
AbiturUnit.cpp |     AddressUnit.h
AbiturUnit.cpp |         Classes.hpp
AbiturUnit.cpp |      DMStatUnit.h
AbiturUnit.cpp |          DMUnit.h
AbiturUnit.cpp |       DMVedUnit.h
AbiturUnit.cpp |     DUALLISTDOC.h
AbiturUnit.cpp |        graphics.hpp
AbiturUnit.cpp |            jpeg.hpp
AbiturUnit.cpp |     ListDlgUnit.h
AbiturUnit.cpp |        MainUnit.h
AbiturUnit.cpp |  Priv_EnterUnit.h
AbiturUnit.cpp |   Rep_Sel_Exerc.h
AbiturUnit.cpp |  SertificatUnit.h
AbiturUnit.cpp |     SredBalUnit.h
AbiturUnit.cpp |    Undo_Ab_Unit.h
AbiturUnit.cpp |   Undo_Ab_1Unit.h



// LIST FORM
Abiturient.cpp |        AbituraLogDlg.cpp AbiturLogDlg
Abiturient.cpp |           AbiturUnit.cpp AbiturForm
Abiturient.cpp |      AddressLifeUnit.cpp AddressLifeForm
Abiturient.cpp |          AddressUnit.cpp AddressForm
Abiturient.cpp |            ApellUnit.cpp ApellForm
Abiturient.cpp |            Ball_Unit.cpp Ball_Form
Abiturient.cpp |            BlockUnit.cpp BlockForm
Abiturient.cpp |     Dlg_ProtokolUnit.cpp Dlg_ProtokolForm
Abiturient.cpp |               DMUnit.cpp DM                /* TDataModule: File Type */
Abiturient.cpp |           DMStatUnit.cpp DMStat            /* TDataModule: File Type */
Abiturient.cpp |            DMVedUnit.cpp DMVed             /* TDataModule: File Type */
Abiturient.cpp |       Dop_ResultUnit.cpp Dop_ResultForm
Abiturient.cpp |             DUALLIST.cpp DualListDlg
Abiturient.cpp |          DUALLISTDOC.cpp DualListDlgDoc
Abiturient.cpp |     Exam_List_obUnit.cpp Exam_List_obForm
Abiturient.cpp |        Exam_ListUnit.cpp Exam_ListForm
Abiturient.cpp |       ExamenSpecUnit.cpp ExamenSpecForm
Abiturient.cpp |           ExamenUnit.cpp ExamenForm
Abiturient.cpp |        Group_FacUnit.cpp Group_FacForm
Abiturient.cpp |       LETTERDUALLIST.cpp LetterDualListDlg
Abiturient.cpp |           LetterUnit.cpp LetterForm
Abiturient.cpp |          ListDlgUnit.cpp ListDlgForm
Abiturient.cpp |     ListDocIndexUnit.cpp ListDocIndexForm
Abiturient.cpp |        LoginPassUnit.cpp LoginPass
Abiturient.cpp |             MainUnit.cpp MainForm
Abiturient.cpp |           NoticeUnit.cpp NoticeForm
Abiturient.cpp |          PassDlgUnit.cpp PassDlg
Abiturient.cpp |      PersonalDocUnit.cpp PersonalDocFrm
Abiturient.cpp |      Print_GroupUnit.cpp Print_GroupForm
Abiturient.cpp |       Print_OpisUnit.cpp Print_OpisForm
Abiturient.cpp |   Print_RaspiskaUnit.cpp Print_RaspiskaForm
Abiturient.cpp |       Priv_EnterUnit.cpp Priv_EnterForm
Abiturient.cpp |     PrnPersonDocUnit.cpp PrnPersonDocForm
Abiturient.cpp |        Rep_Sel_Exerc.cpp FormRepSelExerc
Abiturient.cpp |     Resuilt_ExamUnit.cpp Result_ExamForm
Abiturient.cpp |       SertificatUnit.cpp SertificatForm
Abiturient.cpp |     Spisoc_GroupUnit.cpp Spisoc_GroupForm
Abiturient.cpp |           SplashUnit.cpp SplashForm
Abiturient.cpp |            SpravUnit.cpp SpravForm
Abiturient.cpp |          SredBalUnit.cpp SredBalForm
Abiturient.cpp | Stat_Result_examUnit.cpp Stat_Result_examForm
Abiturient.cpp |        Undo_Ab_1Unit.cpp Undo_Ab_1Form
Abiturient.cpp |         Undo_Ab_Unit.cpp Undo_Ab_Form
Abiturient.cpp |     Undo_SpravkaUnit.cpp Undo_SpravkaForm




// FUNCTIONS
// int __fastcall TAbiturForm::langv_ball (
//         int ind,
//         int fl
//     )    //ФУНКЦИЯ ВОЗВРАЩАЕТ ОЦЕНКУ ПО ИНОСТРАННОМУ ЯЗЫКУ
void __fastcall TAbiturForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )   //ЗАКРЫТИЕ ФОРМЫ
void __fastcall TAbiturForm::DBNavigator1Click (
        TObject      * Sender,
        TNavigateBtn   Button
    )   //НАВИГАТОР
void __fastcall TAbiturForm::NameDBEdtKeyDown (
        TObject     * Sender,
        WORD        & Key,
        TShiftState  Shift
    )   //ИМЯ
void __fastcall TAbiturForm::FamDBEdtKeyDown (
        TObject     * Sender,
        WORD        & Key,
        TShiftState   Shift
    )   //ФАМИЛИЯ
void __fastcall TAbiturForm::FormCanResize (
        TObject * Sender,
        int     & NewWidth,
        int     & NewHeight,
        bool    & Resize
    )
void __fastcall TAbiturForm::ApplicationEvents1Message (
        tagMSG & Msg,
        bool &Handled
    )   //ОРГАНИЗАЦИЯ НОРМАЛЬНОЙ РАБОТЫ КОЛЕСИКА МЫШИ В 'DBGrid'
void __fastcall TDM::FIOSearchDSDataChange (
        TObject * Sender,
        TField  * Field
    )
void __fastcall TAbiturForm::DBGrid2DrawColumnCell (
        TObject               * Sender,
        const TRect           & Rect,
        int                     DataCol,
        TColumn               * Column,
        Grids::TGridDrawState   State
    )   //ИЗМЕНЕНИЕ ЦВЕТА СТРОКИ 

// void __fastcall ClearCheck(TRxCheckListBox * cList)  //ФУНКЦИЯ, КОТОРАЯ ОТКЛЮЧАЕТ ВСЕ 'CHECk'

AbiturUnit.cpp | AnsiString __fastcall TAbiturForm::Chek_Vid_Edu ()                      //ВЫБОР АБИТУРИЕНТОВ ТОЛЬКО ОПРЕДЕЛЕННОГО ВИДА ОБУЧЕНИЯ
AbiturUnit.cpp |            __fastcall TAbiturForm::TAbiturForm  (TComponent * Owner)    //ПОКАЗ КОМПОНЕНТОВ ДЛЯ РАЗРАБОТЧИКА (ВСЕГДА)
AbiturUnit.cpp | void       __fastcall TAbiturForm::NewAbitur    (int pr_w)              //НОВЫЙ АБИТУРИЕНТ (value of pr_w: 0 - по кнопке ДОБАВИТЬ, 1 - из закладки ПОДАЧА ДОКУМЕНТОВ)
AbiturUnit.cpp | void       __fastcall TAbiturForm::PressBtn     (int press_btn)         //ФУНКЦИЯ ВЫБОРА

AbiturUnit.cpp | int  __fastcall TAbiturForm::NewWo             ()   //ЗАПИСЬ В БД СПИСКА ПРИВЕЛЕГИЙ
AbiturUnit.cpp | void __fastcall TAbiturForm::VidKonkurs        ()   //ПРОЦЕДУРА УСТАНОВКИ КОНКУРСА АБИТУРИЕНТА (функция вызывается если у платников общий конкурс (т.е. oplata_konkurs == 0))
AbiturUnit.cpp | void __fastcall TAbiturForm::NameBtn           ()   //НАЗНАЧАЕТ КНОПКАМ ИМЕНА ФАКУЛЬТЕТОВ (для Института туризма другие названия)
AbiturUnit.cpp | void __fastcall TAbiturForm::BitBtnShow        ()   //ПОКАЗ КОМПОНЕНТОВ ДЛЯ РАЗРАБОТЧИКА (ВСЕГДА)
AbiturUnit.cpp | void __fastcall TAbiturForm::PoleBlock         ()   //GET VALUE FROM 'BLOCK' FIELD
AbiturUnit.cpp | void __fastcall TAbiturForm::MsgEdit           ()   //PROHIBITION OF DATA MODIFICATION
AbiturUnit.cpp | void __fastcall TAbiturForm::EnabledTrue       ()   //ПОКАЗ КОМПОНЕНТОВ ДЛЯ ИЗМЕНЕНИЯ ДАННЫХ АБИТУРИЕНТА (ЗАВИСИТ ОТ ПОЛЯ В БД)
AbiturUnit.cpp | void __fastcall TAbiturForm::EnableDate        ()   //ПОКАЗ КОМПОНЕНТОВ ДЛЯ РАЗРАБОТЧИКА (ВСЕГДА)
AbiturUnit.cpp | void __fastcall TAbiturForm::max_nom_dela      ()   //ФУНКЦИЯ ВОЗВРАЩАЮЩАЯ МАКСИМАЛЬНЫЙ НОМЕР ДЕЛА
AbiturUnit.cpp | void __fastcall TAbiturForm::UncheckCh         ()   //ФУНКЦИЯ, КОТОРАЯ ОТКЛЮЧАЕТ ВСЕ 'CHECK'
AbiturUnit.cpp | void __fastcall TAbiturForm::RefreshCh         ()   //ФУНКЦИЯ ИНИЦИАЛИЗИРУЕТ 'CHECks' (Считывание дополнительных параметров)
AbiturUnit.cpp | void __fastcall TAbiturForm::RefreshControl    ()   //ФУНКЦИЯ ЧИТЕНИЯ ДАННЫХ ИЗ БАЗЫ И ИНИЦИАЛИЗАЦИИ КОМПОНЕНТОВ
AbiturUnit.cpp | void __fastcall TAbiturForm::ReLoadAbiturPhoto ()   //ВЫВОДИМ НУЖНОЕ ФОТО

AbiturUnit.cpp | void __fastcall TAbiturForm::TabSheet1Enter                  (TObject * Sender)    //ПЕРЕХОД НА ЗАКЛАДКУ 'ПОЛНЫЙ СПИСОК'
AbiturUnit.cpp | void __fastcall TAbiturForm::TabSheet2Enter                  (TObject * Sender)    //ПЕРЕХОД НА ЗАКЛАДКУ 'ЛИЧНОЕ ДЕЛО'
AbiturUnit.cpp | void __fastcall TAbiturForm::TabSheet3Enter                  (TObject * Sender)    //ПЕРЕХОД НА ЗАКЛАДКУ 'ДОПОЛНИТЕЛЬНЫЕ СВЕДЕНИЯ'
AbiturUnit.cpp | void __fastcall TAbiturForm::TabSheet1Show                   (TObject * Sender)    //ПОКАЗ ЗАКЛАДКИ 'ПОЛНЫЙ СПИСОК'
AbiturUnit.cpp | void __fastcall TAbiturForm::TabSheet3Show                   (TObject * Sender)    //ПОКАЗ ЗАКЛАДКИ 'ДОПОЛНИТЕЛЬНЫЕ СВЕДЕНИЯ'
AbiturUnit.cpp | void __fastcall TAbiturForm::ExitBitBtnClick                 (TObject * Sender)    //КНОПКА 'ВЫХОД'
AbiturUnit.cpp | void __fastcall TAbiturForm::SaveBtBtnClick                  (TObject * Sender)    //КНОПКА 'СОХРАНИТЬ'
AbiturUnit.cpp | void __fastcall TAbiturForm::CancelBtBtnClick                (TObject * Sender)    //КНОПКА 'ОТМЕНИТЬ'
AbiturUnit.cpp | void __fastcall TAbiturForm::Edit1Change                     (TObject * Sender)    //'ПОИСК ПО ФАМИЛИИ' - ПОЛЕ ВВОДА
AbiturUnit.cpp | void __fastcall TAbiturForm::RadioGroup1Click                (TObject * Sender)    //ВИД ОБУЧЕНИЯ
AbiturUnit.cpp | void __fastcall TAbiturForm::FormActivate                    (TObject * Sender)    //ПОКАЗ ОСНОВНОЙ ФОРМЫ
AbiturUnit.cpp | void __fastcall TAbiturForm::KonkursRdGrpClick               (TObject * Sender)    //ИЗМЕНЕНИЯ ПО КНОПКЕ 'КОНКУРС'
AbiturUnit.cpp | void __fastcall TAbiturForm::AddBtBtnClick                   (TObject * Sender)    //КНОПКА 'ДОБАВИТЬ'
AbiturUnit.cpp | void __fastcall TAbiturForm::DBGrid1DblClick                 (TObject * Sender)    //GRID  НА ЗАКЛАДКЕ 'ПОЛНЫЙ СПИСОК'
AbiturUnit.cpp | void __fastcall TAbiturForm::PrintBtBtnClick                 (TObject * Sender)    //КНОПКА 'ПЕЧАТЬ'
AbiturUnit.cpp | void __fastcall TAbiturForm::RestorlistBtBtnClick            (TObject * Sender)    //КНОПКА 'ВОССТАНОВИТЬ В СПИСКЕ' (для абитуриентов, которые забирали документы)
AbiturUnit.cpp | void __fastcall TAbiturForm::TookDocBtBtn1Click              (TObject * Sender)    //КНОПКА 'ЗАБРАЛ ДОКУМЕНТЫ' ДО ОКОНЧАНИЯ ПРИЁМА ДОКУМЕНТОВ
AbiturUnit.cpp | void __fastcall TAbiturForm::FormEduCmbBxChange              (TObject * Sender)    //ВИД ОБУЧЕНИЯ
AbiturUnit.cpp | void __fastcall TAbiturForm::EducatCmbBxChange               (TObject * Sender)    //ИЗМЕНЕНИЕ ОБРАЗОВАНИЯ
AbiturUnit.cpp | void __fastcall TAbiturForm::DBGrid1TitleClick               (TColumn * Column)    //ЩЕЛЧЕК НА ТИТУЛЕ GRIDА, ДЛЯ СОРТИРОВКИ
AbiturUnit.cpp | void __fastcall TAbiturForm::TookDocBtBtn2Click              (TObject * Sender)    //КНОПКА ЗАБРАЛ ДОКУМЕНТЫ ВО ВРЕМЯ ЭКЗАМЕНОВ
AbiturUnit.cpp | void __fastcall TAbiturForm::DBGrid3DblClick                 (TObject * Sender)    //ДВОЙНОЙ ЩЕЛЧЕК НА GRID-Е С СЕРТИФИКАТАМИ
AbiturUnit.cpp | void __fastcall TAbiturForm::WhereEduMiddleDBEdtClick        (TObject * Sender)    //ГДЕ ЗАКОНЧИЛ СРЕДНЕЕ ОБРАЗОВАНИЕ (КОДЫ РАЙОНОВ)
AbiturUnit.cpp | void __fastcall TAbiturForm::SpecializDBLookupCmbBxExit      (TObject * Sender)    //ВЫБОР СПЕЦИАЛИЗАЦИИ
AbiturUnit.cpp | void __fastcall TAbiturForm::Image1Click                     (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::FormCreate                      (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::FormEduCmbBxExit                (TObject * Sender)    //ВЫХОД ИЗ ЭЛЕМЕНТА ВЫБОРА ФОРМЫ ОБУЧЕНИЯ
AbiturUnit.cpp | void __fastcall TAbiturForm::SpeedButton1Click               (TObject * Sender)    //ВЫЗОВ ФОРМЫ ПО 'СРЕДНЕМУ БАЛЛУ' АТТЕСТАТА
AbiturUnit.cpp | void __fastcall TAbiturForm::ReInsideFacBtBtnClick           (TObject * Sender)    //ПЕРЕПОДАЧА ДОКУМЕНТОВ (Cмена факультета, специальности и т.д.)
AbiturUnit.cpp | void __fastcall TAbiturForm::Vk1Click                        (TObject * Sender)    //ИЗМЕНЕНИЕ 'ПРЕИМУЩЕСТВ' ПОСЛЕ ДОБАВЛЕНИЯ АБИТУРИЕНТА
AbiturUnit.cpp | void __fastcall TAbiturForm::PersonNumDBEdtExit              (TObject * Sender)    //ПОСЛЕ ВВОДА ЛИЧНОГО НОМЕРА ВВОДИМ 'ПОЛ' И 'ДАТУ' РОЖДЕНИЯ (!!!Проверить, чтобы это был пасспорт СМОТРЕТЬ!!!!)
AbiturUnit.cpp | void __fastcall TAbiturForm::FamDBEdtExit                    (TObject * Sender)    //FAM, NAME, OTCH (в режиме добавления студента) (Обработка ФИО с приведением его в нужный формат)
AbiturUnit.cpp | void __fastcall TAbiturForm::NameDBEdtExit                   (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::OtchDBEdtExit                   (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::PriceRdGrpEnter                 (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::KonkursRdGrpEnter               (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::EducatCmbBxEnter                (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::DBGrid3Enter                    (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::NomGroupCmbBxEnter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::clictNotConcoursEnter           (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::clistAddAwardsEnter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::clistNotExamsEnter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::clistGIACEnter                  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::clistddEnrollingEnter           (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::clictNotConcoursClickCheck      (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::clistNotExamsClickCheck         (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::clistAddAwardsClickCheck        (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::clistddEnrollingClickCheck      (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::clistGIACClickCheck             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::StagDBEdtEhExit                 (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::StagSpecDBEdtEhExit             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::TabSheet4Show                   (TObject * Sender)    //ПРИ ОТОБРАЖЕНИИ ВКЛАДКИ ВЫБОР КУ
AbiturUnit.cpp | void __fastcall TAbiturForm::BitBtn9Click                    (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::TabSheet4Enter                  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::RdGrpSchoolClick                (TObject * Sender)    //ИЗМЕНЕНИЕ ВИДА УЧЕБНОГО ЗАВЕДЕНИЯ
AbiturUnit.cpp | void __fastcall TAbiturForm::RGrpVillageClick                (TObject * Sender)    //ИЗМЕНЕНИЕ ГОРОД / СЕЛО
AbiturUnit.cpp | void __fastcall TAbiturForm::CategoryAbCmbBxChange           (TObject * Sender)    //ИЗМЕНЕНИЕ КАТЕГОРИИ АБИТУРИЕНТА
AbiturUnit.cpp | void __fastcall TAbiturForm::TermEduCmbBxChange              (TObject * Sender)    //ИЗМЕНЕНИЕ СРОКА ПОЛУЧЕНИЯ ОБРАЗОВАНИЯ
AbiturUnit.cpp | void __fastcall TAbiturForm::PriceCmbBxChange                (TObject * Sender)    //ИЗМЕНЕНИЕ ФОРМЫ ОПЛАТЫ
AbiturUnit.cpp | void __fastcall TAbiturForm::TabSheet5Show                   (TObject * Sender)    //ПЕРЕХОД НА ЗАКЛАДКУ 'ПОДАЧА ДОКУМЕНТОВ'
AbiturUnit.cpp | void __fastcall TAbiturForm::FIOSearchEdtChange              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::DBGrid2DblClick                 (TObject * Sender)    //ФУНКЦИЯ ДВОЙНОГО КЛИКА ПО АБИТУРИЕНТУ ИЗ СПИСКА ОТ ДЕКАНА (декан разрешает сохранять данные в ABITURA: переподачи документов, предъявления недостающих документов, создания новой записи о кондидате, сверки параметров)
AbiturUnit.cpp | void __fastcall TAbiturForm::FIOReBitBtnClick                (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::SngFrgCmbBxChange               (TObject * Sender)    //ИЗМЕНЕНИЕ УСЛОВИЙ ПОСТУПЛЕНИЯ
AbiturUnit.cpp | void __fastcall TAbiturForm::KonkursCmbBxChange              (TObject * Sender)    //ИЗМЕНЕНИЕ КОНКУРСА
AbiturUnit.cpp | void __fastcall TAbiturForm::InfChekLstBxClickCheck          (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::SchoolCmbBxChange               (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::TownVillageCmbBxChange          (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::AdressRegEdtChange              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::PlaceRDBEdtChange               (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::NomDelaDBEdtChange              (TObject * Sender)    //ИЗМЕНЕНИЕ НОМЕРА ДЕЛА
AbiturUnit.cpp | void __fastcall TAbiturForm::AdressRegEdtExit                (TObject * Sender)    //ЗАПИСЬ В ЛОГ КОГДА НЕ В РЕЖИМЕ 'ИЗМЕНЕНИЯ КОНКУРСА'
AbiturUnit.cpp | void __fastcall TAbiturForm::SportCategoryDBLookupCmboBxExit (TObject * Sender)    //ЗАПИСЬ В ЛОГ КОГДА НЕ В РЕЖИМЕ 'ИЗМЕНЕНИЯ КОНКУРСА'
AbiturUnit.cpp | void __fastcall TAbiturForm::CkRegionDBLkpCmbBxExit          (TObject * Sender)    //ЗАПИСЬ В ЛОГ КОГДА НЕ В РЕЖИМЕ 'ИЗМЕНЕНИЯ КОНКУРСА'
AbiturUnit.cpp | void __fastcall TAbiturForm::DBDateEdit1Change               (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::DBGrid2CellClick                (TColumn * Column)
AbiturUnit.cpp | void __fastcall TAbiturForm::PersonNumDBEdtChange            (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::BitBtn1Click                    (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::CheckBox1Click                  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::PageControl1Change              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::DistrictDBLkCmbBxExit           (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::TabSheet2Show                   (TObject * Sender)    //ПЕРЕХОД НА ВКЛАДКУ -> 'ЛИЧНОЕ ДЕЛО'
AbiturUnit.cpp | void __fastcall TAbiturForm::RegionDBLookupCmbBxCloseUp      (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::CheckBox2Click                  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::AdressLifeEdtClick              (TObject * Sender)

AbiturUnit.cpp | void __fastcall TAbiturForm::Ch5Enter              (TObject * Sender) //ЗАПРЕТ ИЗМЕНЕНИЯ ДАННЫХ!!! (ПОСЛЕ УСТАНОВКИ В БД BLOCK = 1)
AbiturUnit.cpp | void __fastcall TAbiturForm::Ch6Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Ch3Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Ch7Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Ch8Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Ch9Enter              (TObject * Sender)

AbiturUnit.cpp | void __fastcall TAbiturForm::OutCmboBx1Change      (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::OutCmboBx2Change      (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::OutCmboBx3Change      (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::OutCmboBx4Change      (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::OutCmboBx5Change      (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::OutCmboBx6Change      (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::OutCmboBx7Change      (TObject * Sender)

AbiturUnit.cpp | void __fastcall TAbiturForm::Pr1Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr4Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr21Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr2Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr3Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr5Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr6Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr7Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr19Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr8Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr9Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr10Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr11Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr12Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr13Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr23Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr17Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr14Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr22Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr20Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr18Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr16Enter             (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Pr15Enter             (TObject * Sender)

AbiturUnit.cpp | void __fastcall TAbiturForm::Vk1Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Vk4Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Vk6Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Vk5Enter              (TObject * Sender)

AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx1Change  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx2Change  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx3Change  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx4Change  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx5Change  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx6Change  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx7Change  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx8Change  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx9Change  (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx10Change (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx11Change (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx12Change (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx13Change (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx14Change (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx15Change (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::WithOutCmboBx16Change (TObject * Sender)

AbiturUnit.cpp | void __fastcall TAbiturForm::Wo1Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Wo2Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Wo3Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Wo4Enter              (TObject * Sender)
AbiturUnit.cpp | void __fastcall TAbiturForm::Wo5Enter              (TObject * Sender)

