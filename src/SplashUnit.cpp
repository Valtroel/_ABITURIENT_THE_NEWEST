#include <vcl.h>
#pragma hdrstop


#include "DMStatUnit.h"
#include "DMUnit.h"
#include "DMVedUnit.h"
#include "LoginPassUnit.h"
#include "MainUnit.h"
#include "SplashUnit.h"
#include <winsock2.h>


#pragma package (smart_init)


// #pragma link "RXCtrls"
// #pragma link "RXPlacemnt"


#pragma resource "*.dfm"


TSplashForm * SplashForm;


AnsiString user_name;                                                           // текущее имя пользователя, под которым зашли на комп
String     loginUser,
           pswdUser;





__fastcall TSplashForm::TSplashForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall DB_Params (                                                     // добавление параметров в Database1
        AnsiString Login,                                                       // передаем имя пользователя
        AnsiString Pass                                                         // передаем пароль
    )
{
    DM -> FDConnection1 -> Connected = false;                                   // reset DB_Dekanat params
    DM -> FDConnection1 -> Params -> Clear ();

    DM -> FDConnection2 -> Connected = false;                                   // reset DB_Abitura params
    DM -> FDConnection2 -> Params -> Clear ();

    if (    Login == "1231"                                                     // get defauld DB params for test environment
         || Login == "1232"
         || Login == "1233"
         || Login == "1234"
         || Login == "SYSDBA"
       )
    {                                                                           // Test environment
        Login = "DEVELOPER";

        DM -> FDConnection1 -> Params -> Clear ();
        DM -> FDConnection1 -> Params -> Add ("Database=dekanat");
        DM -> FDConnection1 -> Params -> Add ("Server=172.16.1.30");
        DM -> FDConnection1 -> Params -> Add ("User_Name=" + Login);
        DM -> FDConnection1 -> Params -> Add ("Password="  + Pass);
        DM -> FDConnection1 -> Params -> Add ("DriverID=FB");

        DM -> FDConnection2 -> Params -> Clear ();
        DM -> FDConnection2 -> Params -> Add ("Database=abitur_test");
        DM -> FDConnection2 -> Params -> Add ("Server=172.16.1.30");
        DM -> FDConnection2 -> Params -> Add ("User_Name=" + Login);
        DM -> FDConnection2 -> Params -> Add ("Password="  + Pass);
        DM -> FDConnection2 -> Params -> Add ("DriverID=FB");
    }
    else                                                                        // Product environment
    {
        DM -> FDConnection1 -> Params -> Clear ();
        DM -> FDConnection1 -> Params -> Add ("Database=dekanat");
        DM -> FDConnection1 -> Params -> Add ("Server=172.16.1.30");
        DM -> FDConnection1 -> Params -> Add ("User_Name=" + Login);
        DM -> FDConnection1 -> Params -> Add ("Password="  + Pass);
        DM -> FDConnection1 -> Params -> Add ("DriverID=FB");

        DM -> FDConnection2 -> Params -> Clear ();
        DM -> FDConnection2 -> Params -> Add ("Database=abiturient");
        DM -> FDConnection2 -> Params -> Add ("Server=172.16.1.30");
        DM -> FDConnection2 -> Params -> Add ("User_Name=" + Login);
        DM -> FDConnection2 -> Params -> Add ("Password="  + Pass);
        DM -> FDConnection2 -> Params -> Add ("DriverID=FB");
    }

    #ifdef TEST_ENV
    if (    Login == "1231"                                                     // default DB params
         || Login == "1232"
         || Login == "1233"
         || Login == "1234"
       )
    {
        Login = "DEVELOPER";

        DM -> DB_Dekanat -> AliasName = "Dekanat_local";

        DM -> DB_Dekanat -> Params ->
            Add (
                "SERVER NAME=localhost:D:/Bgufk/Dekanat/IB_DEKANAT.GDB"
            );

        DM -> DB_Abitura -> AliasName = "Abitura_local";
        DM -> DB_Abitura -> Params ->
            Add (
                "SERVER NAME=localhost:D:/Bgufk/Abiturient/IB_ABITURA.GDB"
            );
    }
    else                                                                        // PRODUCTION
    {
        DM -> DB_Dekanat -> AliasName = "Dekanat_vmain1";
        DM -> DB_Dekanat -> Params ->
            Add (
               // "SERVER NAME=vmain1:D:/Bgufk/Dekanat/IB_DEKANAT.GDB"
                "SERVER NAME=172.16.1.10:D:/Bgufk/Dekanat/IB_DEKANAT.GDB"
            );

        DM -> DB_Abitura -> AliasName = "Abitura_vmain1";
        DM -> DB_Abitura -> Params ->
            Add (
                // "SERVER NAME=vmain1:D:/Bgufk/Abiturient/IB_ABITURA.GDB"
                "SERVER NAME=172.16.1.10:D:/Bgufk/Abiturient/IB_ABITURA.GDB"
            );
    }

    // Pass = "abudfv544703";                                                     // for debug
    DM -> DB_Dekanat -> Params -> Add ("USER NAME=" + Login);
    DM -> DB_Dekanat -> Params -> Add ("PASSWORD="  + Pass);

    DM -> DB_Abitura -> Params -> Add ("USER NAME=" + Login);                   // connect to DB_Abitura
    DM -> DB_Abitura -> Params -> Add ("PASSWORD="  + Pass);

    DM -> DB_Dekanat -> Params -> Add ("OPEN MODE=READ/WRITE");                 // DB_Dekanat params
    DM -> DB_Dekanat -> Params -> Add ("SCHEMA CACHE SIZE=8");
    DM -> DB_Dekanat -> Params -> Add ("LANGDRIVER=ancyrr");
    DM -> DB_Dekanat -> Params -> Add ("SQLQRYMODE=");
    DM -> DB_Dekanat -> Params -> Add ("SQLPASSTHRU MODE=SHARED AUTOCOMMIT");
    DM -> DB_Dekanat -> Params -> Add ("SCHEMA CACHE TIME=-1");
    DM -> DB_Dekanat -> Params -> Add ("MAX ROWS=-1");
    DM -> DB_Dekanat -> Params -> Add ("BATCH COUNT=200");
    DM -> DB_Dekanat -> Params -> Add ("ENABLE SCHEMA CACHE=FALSE");
    DM -> DB_Dekanat -> Params -> Add ("SCHEMA CACHE DIR=");
    DM -> DB_Dekanat -> Params -> Add ("ENABLE BCD=FALSE");
    DM -> DB_Dekanat -> Params -> Add ("BLOBS TO CACHE=64");
    DM -> DB_Dekanat -> Params -> Add ("BLOB SIZE=32");
    DM -> DB_Dekanat -> Params -> Add ("WAIT ON LOCKS=FALSE");
    DM -> DB_Dekanat -> Params -> Add ("COMMIT RETAIN=FALSE");
    DM -> DB_Dekanat -> Params -> Add ("ROLE NAME=");

    DM -> DB_Abitura -> Params -> Add ("OPEN MODE=READ/WRITE");                 // DB_Abitura params
    DM -> DB_Abitura -> Params -> Add ("SCHEMA CACHE SIZE=8");
    DM -> DB_Abitura -> Params -> Add ("LANGDRIVER=ancyrr");
    DM -> DB_Abitura -> Params -> Add ("SQLQRYMODE=");
    DM -> DB_Abitura -> Params -> Add ("SQLPASSTHRU MODE=SHARED AUTOCOMMIT");
    DM -> DB_Abitura -> Params -> Add ("SCHEMA CACHE TIME=-1");
    DM -> DB_Abitura -> Params -> Add ("MAX ROWS=-1");
    DM -> DB_Abitura -> Params -> Add ("BATCH COUNT=200");
    DM -> DB_Abitura -> Params -> Add ("ENABLE SCHEMA CACHE=FALSE");
    DM -> DB_Abitura -> Params -> Add ("SCHEMA CACHE DIR=");
    DM -> DB_Abitura -> Params -> Add ("ENABLE BCD=FALSE");
    DM -> DB_Abitura -> Params -> Add ("BLOBS TO CACHE=64");
    DM -> DB_Abitura -> Params -> Add ("BLOB SIZE=32");
    DM -> DB_Abitura -> Params -> Add ("WAIT ON LOCKS=FALSE");
    DM -> DB_Abitura -> Params -> Add ("COMMIT RETAIN=FALSE");
    DM -> DB_Abitura -> Params -> Add ("ROLE NAME=");
    #endif
}



void __fastcall TSplashForm::FormActivate (TObject * Sender)
{
    int fac_nomer;                                                              // faculty number for the developer

    #ifdef TEST_SPLASH_UNIT
    //int
        //nSpecDir   = 1,
    //    nSpecializ = 100;
    //ShowMessage (
    //    DeleteAfterDatabaseChange::getNcrb2022CodeNameSportStrByNSpecializ (
    //        nSpecializ
    //    )
        //DeleteAfterDatabaseChange::getNcrb2022CodeByNSpecDir (
        //    DeleteAfterDatabaseChange::getNSpecDirCodeByNSpecializ (
        //        nSpecializ
        //    )
        //)                                                                       +
        //" "                                                                     +
        //DeleteAfterDatabaseChange::getDirectionName2022ByNSpecDirNSpecializ (
        //    DeleteAfterDatabaseChange::getNSpecDirCodeByNSpecializ (
        //        nSpecializ
        //    ),
        //    nSpecializ
        //)
    //);
    #endif  // TEST_SPLASH_UNIT

    // try {
        if (n_count == 0)
        {
            LoginPass = new TLoginPass (Application);                           // read params from ini file

            TIniFile  * inif =
                new TIniFile (
                    ChangeFileExt (
                        Application -> ExeName,
                        ".INI"
                    )
                );

            LoginPass -> Login -> Text =
                inif -> ReadString (
                    "Edit1",
                    "Text",
                    ""
                );
            LoginPass -> ShowModal ();

            loginUser = LoginPass -> Login    -> Text;

            #ifndef AUTO_SIGN_IN
                pswdUser = LoginPass -> Password -> Text;
            #else
                pswdUser = "dbudfV544703";
            #endif

            if(LoginPass)
                delete LoginPass;

            inif ->
                WriteString (
                    "Edit1",
                    "Text",
                    loginUser
                );

            if (inif)
                delete inif;

            Application ->                                                      // create form TDM for db connection
                CreateForm (
                    __classid (TDM),
                    & DM
                );

            DM -> FDPhysFBDriverLink1 -> VendorLib =
                AnsiString (
                    ExtractFilePath (GetModuleName (0)) +
                    "fbclient.dll"
                );

            st_developer = false;                                               // as a programmer
            st_asu       = false;                                               // as an asu

            if (    loginUser == "1"                                            // пароль для DEVELOPER
                 || loginUser == "2"
                 || loginUser == "3"
                 || loginUser == "4"
                 || loginUser == "5"
               )
            {
                fac_nomer = StrToInt (loginUser);

                loginUser = "DEVELOPER";

                st_developer = true;
            }

            if (    loginUser == "ASU1"                                         // if пароль для DEVELOPER
                 || loginUser == "ASU2"
                 || loginUser == "ASU3"
                 || loginUser == "ASU4"
               )

            {
                fac_nomer    = StrToInt (loginUser);
                loginUser    = "DEVELOPER";

                fac_nomer    = StrToInt (loginUser);
                st_developer = true;
            }


            DB_Params (
                loginUser,
                pswdUser
            );


            if (    loginUser == "1231"                                         // if пароль для DEVELOPER
                 || loginUser == "1232"
                 || loginUser == "1233"
                 || loginUser == "1234"
                 || loginUser == "1235"
               )
            {
                fac_nomer    = StrToInt (loginUser.SubString (4, 1));
                loginUser    = "DEVELOPER";
                st_developer = true;
                TextTest     = "\tТЕСТОВАЯ БАЗА";
            }


            try                                                                 // check login and password
            {
                DM -> FDConnection2 -> Open ();
                DM -> FDConnection1 -> Open ();
            }
            catch (...)                                                         // validation failed
            {
                AnsiString err_access_denied =
                    "Неверное имя пользователя или пароль"          //\
                    //" "                                             +
                    //convertScoresToWords (50.4584)                  +
                    //doubleToStringWithFractionalPart (34.3553)      +           // In this case an example: 34.3553 -> 34,4
                    //" "                                             +
                    //doubleToStringWithoutFractionalPart (34.4553)               // In this case an example: 34.4553 -> 34
                    //getDigitNameOfIntegerPart (28)              +
                    //" "                                         +
                    //ROWING_AND_CANOEING
                    ;
                ShowMessage (
                    //"Неверное имя пользователя " \
                    //"или пароль "
                    err_access_denied
                );

                DM -> FDConnection2 -> Close ();
                DM -> FDConnection1 -> Close ();

                DM -> FDConnection1 -> Connected = false;
                DM -> FDConnection2 -> Connected = false;

                n_count++;

                Application -> Terminate ();
            }

            if (    DM -> FDConnection2 -> Connected                            // check DB connection
                 && DM -> FDConnection1 -> Connected
               )
            {
//                DM -> QIP -> ParamByName ("IP_N") -> AsString = GetMyIP ();     // check IP
//                DM -> QIP -> Open ();
//
//                if (DM -> QIP -> RecordCount)
//                {
                    Application -> CreateForm (__classid (TDMStat), & DMStat);  // create forms with queries
                    Application -> CreateForm (__classid (TDMVed),  & DMVed);

                    DM -> TFaculty             -> Active = true;                // activate Tables from Dekanat DB
                    DM -> TFoundation          -> Active = true;
                    DM -> Increment_GroupTable -> Active = true;
                    DM -> TPass_User           -> Active = true;
                    DM -> TVid_Sport           -> Active = true;

                    DM -> TBall                -> Active = true;                // activate Tables from Abitura DB
                    DM -> TCategory            -> Active = true;
                    DM -> TCk                  -> Active = true;
                    DM -> TDocum               -> Active = true;
                    DM -> TKol_Place           -> Active = true;
                    DM -> TPredmet             -> Active = true;
                    DM -> TRegion              -> Active = true;


                    if (    loginUser == "DEVELOPER"                            // set NOM_FAC value
                         || loginUser == "SYSDBA"
                       )
                        nom_fac = fac_nomer;
                    else
                        nom_fac =
                            DM -> TPass_User ->
                                Lookup (
                                    "USER_NAME",
                                    loginUser,
                                    "N_FAC"
                                );


                    fac1 =                                                      // get full name of the faculty
                        DM -> TFaculty ->
                            Lookup (
                                "N_FAC",
                                nom_fac,
                                "FAC1"
                            );

                    cur_dir = GetCurrentDir () + "\\1\\";                       // get the absolute path to the application

                    if (  ! DirectoryExists (                                   // check if templates folder exists
                                cur_dir.SubString (
                                    1,
                                    cur_dir.Length () - 2
                                )
                            )
                        )
                        ShowMessage (
                            "Отсутствует директория " \
                            "с файлами шаблонов.\n\n"
                            "Генерация договоров, отчетов и т.п. "
                            "не возможна!"
                        );

                    //Application -> HelpFile = cur_dir + "HELP_ABITURA.HLP";


                    if (DirectoryExists (                                       // check if output folder exists
                            PathTo::OUTPUT_DOCUMENTS_SLASH
                        )
                       )
                        out_dir = PathTo::OUTPUT_DOCUMENTS_SLASH;
                    else                                                        // try create an output folder if it's missing
                        if (!CreateDir (
                                PathTo::OUTPUT_DOCUMENTS_SLASH
                              )
                            )
                            ShowMessage (
                                "Не удалось создать каталог на диске\n" +
                                    PathTo::OUTPUT_DOCUMENTS_SLASH
                            );

                    Application ->                                              // create TMainForm
                        CreateForm (
                            __classid (TMainForm),
                            & MainForm
                        );
//                //}
//                else                                                            // IP missed
//                {
//                    ShowMessage (
//                        "Вы не имеете право запускать программу \
//                        Абитуриент."
//                    );
//
//                    Application -> Terminate ();
//                }
            }
            else                                                                // connection faild
            {
                ShowMessage (
                    "Не удалось установить соединение с базой.\n"  \
                    "Проблема с сетью или сервером.\n\n"           \
                    "Необходим перезапуск приложения!"
                );

                DM -> FDConnection2 -> Close ();
                DM -> FDConnection1 -> Close ();

                DM -> FDConnection1 -> Connected = false;
                DM -> FDConnection2 -> Connected = false;
            }
        }
    // }
    // catch (Exception &exception)
    // {
    //     Application -> ShowException (&exception);
    // }
}



void __fastcall TSplashForm::FormCreate (TObject * Sender)
{
    n_count = 0;

    LoadKeyboardLayout (
        "00000409",                                                             // English
        KLF_ACTIVATE
    );

    Label5 -> Caption = DM -> get_version ();                                   // show application version
}



AnsiString GetMyIP ()
{
    struct ipconvert
    {
        unsigned char ip[4];
                 char name[100];
    } * ipname;

    AnsiString   iplong         = "";
    int          version        = 0x101;
    char         Hostname[100];
    HOSTENT    * pHostEnt       = 0;
    WSADATA      WSAData;

    WSAStartup (
        version,
        & WSAData
    );

    gethostname (
        Hostname,
        sizeof (Hostname)
    );

    pHostEnt = gethostbyname (Hostname);

    ipname = (ipconvert *) pHostEnt -> h_addr_list[0];

    for ( int i = 0;                                                            // create a string form ipname[] ({192, 168, 1, 30} -> "192.168.1.30")
              i < 4;
              i++
        )
        iplong += AnsiString (int (ipname -> ip[i])) + ".";

    iplong =
        iplong.SubString (
            1,
            iplong.Length () - 1
        );

    WSACleanup ();

    return
        iplong;
}
