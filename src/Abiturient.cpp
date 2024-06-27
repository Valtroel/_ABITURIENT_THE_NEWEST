#include <vcl.h>
#pragma hdrstop

#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>


#include "properties.hpp"
#include "SplashUnit.h"


USEFORM("Print_GroupUnit.cpp", Print_GroupForm);
USEFORM("PersonalDocUnit.cpp", PersonalDocFrm);
USEFORM("PassDlgUnit.cpp", PassDlg);
USEFORM("Priv_EnterUnit.cpp", Priv_EnterForm);
USEFORM("Print_RaspiskaUnit.cpp", Print_RaspiskaForm);
USEFORM("Print_OpisUnit.cpp", Print_OpisForm);
USEFORM("NoticeUnit.cpp", NoticeForm);
USEFORM("ListDocIndexUnit.cpp", ListDocIndexForm);
USEFORM("ListDlgUnit.cpp", ListDlgForm);
USEFORM("LetterUnit.cpp", LetterForm);
USEFORM("MainUnit.cpp", MainForm);
USEFORM("LoginPassUnit.cpp", LoginPass);
USEFORM("Stat_Result_examUnit.cpp", Stat_Result_examForm);
USEFORM("SredBalUnit.cpp", SredBalForm);
USEFORM("SpravUnit.cpp", SpravForm);
USEFORM("Undo_SpravkaUnit.cpp", Undo_SpravkaForm);
USEFORM("Undo_Ab_Unit.cpp", Undo_Ab_Form);
USEFORM("Undo_Ab_1Unit.cpp", Undo_Ab_1Form);
USEFORM("SplashUnit.cpp", SplashForm);
USEFORM("Rep_Sel_Exerc.cpp", FormRepSelExerc);
USEFORM("PrnPersonDocUnit.cpp", PrnPersonDocForm);
USEFORM("Spisoc_GroupUnit.cpp", Spisoc_GroupForm);
USEFORM("SertificatUnit.cpp", SertificatForm);
USEFORM("Resuilt_ExamUnit.cpp", Result_ExamForm);
USEFORM("Dlg_ProtokolUnit.cpp", Dlg_ProtokolForm);
USEFORM("BlockUnit.cpp", BlockForm);
USEFORM("Ball_Unit.cpp", Ball_Form);
USEFORM("DMVedUnit.cpp", DMVed); /* TDataModule: File Type */
USEFORM("DMUnit.cpp", DM); /* TDataModule: File Type */
USEFORM("DMStatUnit.cpp", DMStat); /* TDataModule: File Type */
USEFORM("ApellUnit.cpp", ApellForm);
USEFORM("AbituraLogDlg.cpp", AbiturLogDlg);
USEFORM("AddressUnit.cpp", AddressForm);
USEFORM("AddressLifeUnit.cpp", AddressLifeForm);
USEFORM("AbiturUnit.cpp", AbiturForm);
USEFORM("Exam_List_obUnit.cpp", Exam_List_obForm);
USEFORM("Exam_ListUnit.cpp", Exam_ListForm);
USEFORM("LETTERDUALLIST.cpp", LetterDualListDlg);
USEFORM("Group_FacUnit.cpp", Group_FacForm);
USEFORM("ExamenUnit.cpp", ExamenForm);
USEFORM("DUALLISTDOC.cpp", DualListDlgDoc);
USEFORM("DUALLIST.cpp", DualListDlg);
USEFORM("Dop_ResultUnit.cpp", Dop_ResultForm);
USEFORM("ExamenSpecUnit.cpp", ExamenSpecForm);
USEFORM("EducationUnit.cpp", EducationForm);
//---------------------------------------------------------------------------
WINAPI WinMain (
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR     lpCmdLine,
        int       nCmdShow
    )
{
    try
    {
        SplashForm = new TSplashForm (Application);

        SplashForm -> Show ();
        SplashForm -> Update ();


        Application -> Initialize ();

        TStyleManager::TrySetStyle (
            "Lavender Classico"
        );

        Application -> Title =
            "ÀÑÓ ÀÁÈÒÓÐÈÅÍÒ "           +
                Admissions::TIME::YEAR;

        Application -> HelpFile = "HELP_ABITURA.HLP";

        if (SplashForm)
            delete SplashForm;


        Application->CreateForm(__classid(TLoginPass), &LoginPass);
         Application->CreateForm(__classid(TDualListDlg), &DualListDlg);
         Application->CreateForm(__classid(TDualListDlgDoc), &DualListDlgDoc);
         Application->CreateForm(__classid(TAddressForm), &AddressForm);
         Application->CreateForm(__classid(TListDocIndexForm), &ListDocIndexForm);
         Application->CreateForm(__classid(TAddressLifeForm), &AddressLifeForm);
         Application->CreateForm(__classid(TEducationForm), &EducationForm);
         Application -> Run ();
    }
    catch (Exception & exception)
    {
        Application -> ShowException (& exception);
    }
    return
        0;
}
