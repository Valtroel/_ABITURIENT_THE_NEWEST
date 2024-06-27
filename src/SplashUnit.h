#pragma once
#ifndef SPLASH_UNIT_H
#define SPLASH_UNIT_H


#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//#include "RXCtrls.hpp"
//#include "RxPlacemnt.hpp"
#include <StdCtrls.hpp>


#include "properties.hpp"



//#define TEST_ENV



void __fastcall DB_Params (                                                     // добавление параметров в Database1
        AnsiString Login,                                                       // передаем имя пользователя
        AnsiString Pass                                                         // передаем пароль
    );



class TSplashForm
    : public TForm
{
__published:
    TImage       * Image1;

    TLabel       * Label1;
    TLabel       * Label2;
    TLabel       * Label3;
    TLabel       * Label4;
    TLabel       * Label5;

    TProgressBar * ProgressBar1;

    void __fastcall FormActivate (TObject * Sender);
    void __fastcall FormCreate   (TObject * Sender);
private:
    int n_count;
public:
    __fastcall TSplashForm (TComponent * Owner);
};

extern PACKAGE TSplashForm * SplashForm;

#endif  // SPLASH_UNIT_H
