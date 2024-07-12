//---------------------------------------------------------------------------

#ifndef PrnPersonDocUnitH
#define PrnPersonDocUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "frxClass.hpp"
#include "frxPreview.hpp"
//---------------------------------------------------------------------------
class TPrnPersonDocForm : public TForm
{
__published:	// IDE-managed Components
	TfrxPreview *frxPreview1;
	TfrxReport *frxReport1;
	void __fastcall frxReport1AfterPrintReport(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPrnPersonDocForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrnPersonDocForm *PrnPersonDocForm;
//---------------------------------------------------------------------------
#endif
