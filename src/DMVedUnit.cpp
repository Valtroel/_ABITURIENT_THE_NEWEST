#include <vcl.h>
#pragma hdrstop


#include "DMUnit.h"
#include "DMVedUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TDMVed * DMVed;



__fastcall TDMVed::TDMVed (TComponent * Owner)
    : TDataModule(Owner)
{ }
