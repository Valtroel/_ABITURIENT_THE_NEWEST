#pragma once
#ifndef LOGIN_PASS_UNIT_H
#define LOGIN_PASS_UNIT_H


#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>



class TLoginPass
    : public TForm
{
__published:
    TButton * Button1;
    TButton * Button2;

    TEdit   * Login;
    TEdit   * Password;

    TLabel  * Label1;
    TLabel  * Label2;

    void __fastcall Button2Click (TObject * Sender);
    void __fastcall FormActivate (TObject * Sender);
private:
public:
    __fastcall TLoginPass (TComponent * Owner);
};

extern PACKAGE TLoginPass * LoginPass;

#endif  // LOGIN_PASS_UNIT_H