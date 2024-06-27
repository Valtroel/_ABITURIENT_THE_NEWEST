//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USEFORM("MyDList.cpp", MyFList);
USEFORM("PassDialog.cpp", Chek_user_login);
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Package source.
//---------------------------------------------------------------------------

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
        return 1;
}
//---------------------------------------------------------------------------
