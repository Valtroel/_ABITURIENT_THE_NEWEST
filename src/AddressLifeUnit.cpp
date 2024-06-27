#include <vcl.h>
#pragma hdrstop


#include "AddressLifeUnit.h"
#include "DMUnit.h"


#pragma package(smart_init)
#pragma resource "*.dfm"


TAddressLifeForm * AddressLifeForm;


//int
    //district_id,
    //local_id,
    //type_local_id,
    //type_street_id;



__fastcall TAddressLifeForm::TAddressLifeForm (TComponent * Owner)
    : TForm (Owner)
{ }


// GETTERS
AnsiString __fastcall TAddressLifeForm::getAddress       () const
{
    return
        this -> _address;
}
bool       __fastcall TAddressLifeForm::isAddressSaved   () const
{
    return
        this -> _isAddressSaved;
}
int        __fastcall TAddressLifeForm::getRegionId      () const
{
    return
        this -> _regionId;
}
int        __fastcall TAddressLifeForm::getTerrainId     () const
{
    return
        this -> _terrainId;
}
int        __fastcall TAddressLifeForm::getTerrainTypeId () const
{
    return
        this -> _terrainTypeId;
}
int  __fastcall TAddressLifeForm::getStreetTypeId  () const
{
    return
        this -> _streetTypeId;
}
// SETTERS
void __fastcall TAddressLifeForm::setAddress        (const AnsiString & address)
{
    this -> _address = address;
}
void __fastcall TAddressLifeForm::setIsAddressSaved (const bool isSaved)
{
    this -> _isAddressSaved = isSaved;
}
void __fastcall TAddressLifeForm::setRegionId       (const int regionId)
{
    this -> _regionId = regionId;
}
void __fastcall TAddressLifeForm::setTerrainId      (const int terrainId)
{
    this -> _terrainId = terrainId;
}
void __fastcall TAddressLifeForm::setTerrainTypeId  (const int terrainTypeId)
{
    this -> _terrainTypeId = terrainTypeId;
}
void __fastcall TAddressLifeForm::setStreetTypeId   (const int streetTypeId)
{
    this -> _streetTypeId = streetTypeId;
}

void __fastcall TAddressLifeForm::addToAddress (const AnsiString & addition)
{
    this -> _address += addition;
}



void __fastcall TAddressLifeForm::BitBtn1Click (TObject * Sender)
{
    if (DM -> TRegionN_REGION -> Value != 5)
        setAddress (
                DM -> TRegionTEXT_REGION     -> Value           +
            ", "                                                +
                DM -> QDistrictNAME_DISTRICT -> Value           +
            " р-н, "                                            +
                DM -> QType_localitySHORT_TYPE_NAME -> Value    +
            " " +
                DM -> QLocalityNAME_LOCALITY        -> Value
        );
    else
        setAddress (
            DM -> TRegionTEXT_REGION -> Value
        );

    if (DM -> QType_streetSHORT_TYPE -> Value != "-")
        addToAddress (
            ", "                                                +
                DM -> QType_streetSHORT_TYPE -> Value           +
            " "                                                 +
                DM -> QStreetNAME_IN_RUS     -> Value
        );

    if (DBEditHouse -> Text != "")
        addToAddress (
            ", д. "                                             +
                DM -> QAbituraHOUSE -> Value
        );

    if (DBEditFlat -> Text != "")
        addToAddress (
            ", кв. "                                            +
                IntToStr (
                    DM -> QAbituraFLAT -> Value
                )
        );

    if (DBEditPostcode -> Text != "")
        addToAddress (
            ", "                                                +
                IntToStr (
                    DM -> QAbituraPOSTCODE -> Value
                )
        );

    setIsAddressSaved (
        true
    );

    Close ();
}
void __fastcall TAddressLifeForm::DistrictDBLkCmbBxCloseUp (TObject * Sender)
{
    DM -> QType_locality -> Close ();
    DM -> QType_locality -> Open ();

    setTerrainTypeId (
        Type_localityDBLkCmbBx -> KeyValue
    );

    if (getTerrainTypeId () != Type_localityDBLkCmbBx -> KeyValue)
    {
        LocalityDBLkCmbBx    -> KeyValue = 0;
        Type_streetDBLkCmbBx -> KeyValue = 0;
        StreetDBLkCmbBx      -> KeyValue = 0;
    }

    Type_localityDBLkCmbBx -> Enabled = true;
    LocalityDBLkCmbBx      -> Enabled = false;
    Type_streetDBLkCmbBx   -> Enabled = false;
    StreetDBLkCmbBx        -> Enabled = false;

    DM -> QLocality -> Close ();
    DM -> QLocality ->
        ParamByName ("DISTRICT") -> AsInteger =
            DistrictDBLkCmbBx -> KeyValue;
    DM -> QLocality ->
        ParamByName ("N_TYPE")   -> AsInteger =
            Type_localityDBLkCmbBx -> KeyValue;
    DM -> QLocality -> Open ();

    if (DM -> QAbitura -> State == dsInsert)
        LocalityDBLkCmbBx -> KeyValue = -1;
}
void __fastcall TAddressLifeForm::DistrictDBLkCmbBxExit (TObject * Sender)
{
    //DM -> QLocality -> Close ();
    //DM -> QLocality ->
    //    ParamByName ("DISTRICT") -> AsInteger =
    //        DistrictDBLkCmbBx -> KeyValue;
    //DM -> QLocality ->
    //    ParamByName ("N_TYPE")   -> AsInteger =
    //        Type_localityDBLkCmbBx -> KeyValue;
    //DM -> QLocality -> Open ();

    //if (DM -> QAbitura -> State == dsInsert)
    //    LocalityDBLkCmbBx -> KeyValue = -1;
}
void __fastcall TAddressLifeForm::DistrictDBLkCmbBxMouseDown (
        TObject      * Sender,
        TMouseButton   Button,
        TShiftState    Shift,
        int            X,
        int            Y
    )
{
    //setTerrainTypeId (
    //    Type_localityDBLkCmbBx -> KeyValue
    //);
}
void __fastcall TAddressLifeForm::DistrictDBLkCmbBxMouseEnter (TObject * Sender)
{
    //DM -> QType_locality -> Close ();
    //DM -> QType_locality -> Open ();
}
void __fastcall TAddressLifeForm::LocalityDBLkCmbBxCloseUp (TObject * Sender)
{
    setTerrainId (
        LocalityDBLkCmbBx -> KeyValue
    );

    if (getTerrainId () != LocalityDBLkCmbBx -> KeyValue)
    {
        Type_streetDBLkCmbBx -> KeyValue = 0;
        StreetDBLkCmbBx      -> KeyValue = 0;
    }

    Type_streetDBLkCmbBx -> Enabled = true;
    StreetDBLkCmbBx      -> Enabled = false;

    DM -> QType_street -> Close ();
    DM -> QType_street -> Open ();
}
void __fastcall TAddressLifeForm::LocalityDBLkCmbBxExit (TObject * Sender)
{
    //DM -> QType_street -> Close ();
    //DM -> QType_street -> Open ();

    //Type_streetDBLkCmbBx -> KeyValue = 1;
}
void __fastcall TAddressLifeForm::LocalityDBLkCmbBxMouseDown (
        TObject      * Sender,
        TMouseButton   Button,
        TShiftState    Shift,
        int            X,
        int            Y
    )
{
    //setTerrainId (
    //    LocalityDBLkCmbBx -> KeyValue
    //);
}
void __fastcall TAddressLifeForm::RegionDBLookupCmbBxCloseUp (TObject * Sender)
{
    DistrictDBLkCmbBx      -> KeyValue = 0;
    Type_localityDBLkCmbBx -> KeyValue = 0;
    LocalityDBLkCmbBx      -> KeyValue = 0;
    Type_streetDBLkCmbBx   -> KeyValue = 0;
    StreetDBLkCmbBx        -> KeyValue = 0;

    if (RegionDBLookupCmbBx -> KeyValue == 5)
    {
        Label48                -> Visible = false;
        Label51                -> Visible = false;
        Label54                -> Visible = false;
        DistrictDBLkCmbBx      -> Visible = false;
        Type_localityDBLkCmbBx -> Visible = false;
        LocalityDBLkCmbBx      -> Visible = false;

        DM -> QType_street -> Close ();
        DM -> QType_street -> Open ();

        Type_streetDBLkCmbBx -> KeyValue = 1;
        LocalityDBLkCmbBx    -> KeyValue = 1;

        Type_streetDBLkCmbBx -> Enabled = true;
        StreetDBLkCmbBx      -> Enabled = false;
    }
    else
    {
        Label48                -> Visible = true;
        Label51                -> Visible = true;
        Label54                -> Visible = true;
        DistrictDBLkCmbBx      -> Visible = true;
        Type_localityDBLkCmbBx -> Visible = true;
        LocalityDBLkCmbBx      -> Visible = true;

        DM -> QDistrict -> Close ();
        DM -> QDistrict ->
            ParamByName ("REGION") -> AsInteger =
                RegionDBLookupCmbBx -> KeyValue;
        DM -> QDistrict -> Open ();

        if (DM -> QAbitura -> State == dsInsert)
            DistrictDBLkCmbBx -> KeyValue = -1;

        DistrictDBLkCmbBx      -> Enabled = true;
        Type_localityDBLkCmbBx -> Enabled = false;
        LocalityDBLkCmbBx      -> Enabled = false;
        Type_streetDBLkCmbBx   -> Enabled = false;
        StreetDBLkCmbBx        -> Enabled = false;
    }
}
void __fastcall TAddressLifeForm::Type_localityDBLkCmbBxCloseUp (TObject * Sender)
{
    setTerrainId (
        LocalityDBLkCmbBx -> KeyValue
    );

    if (getTerrainTypeId () != Type_localityDBLkCmbBx -> KeyValue)
    {
        LocalityDBLkCmbBx    -> KeyValue = 0;
        Type_streetDBLkCmbBx -> KeyValue = 0;
        StreetDBLkCmbBx      -> KeyValue = 0;
    }

    LocalityDBLkCmbBx    -> Enabled = true;
    Type_streetDBLkCmbBx -> Enabled = false;
    StreetDBLkCmbBx      -> Enabled = false;

    DM -> QLocality -> Close ();
    DM -> QLocality ->
        ParamByName ("DISTRICT") -> AsInteger =
            DistrictDBLkCmbBx -> KeyValue;
    DM -> QLocality ->
        ParamByName ("N_TYPE")   -> AsInteger =
            Type_localityDBLkCmbBx -> KeyValue;
    DM -> QLocality -> Open ();

    if (DM -> QAbitura -> State == dsInsert)
        LocalityDBLkCmbBx -> KeyValue = -1;
}
void __fastcall TAddressLifeForm::Type_localityDBLkCmbBxExit (TObject * Sender)
{
    //DM -> QLocality -> Close ();
    //DM -> QLocality ->
    //    ParamByName ("DISTRICT") -> AsInteger =
    //        DistrictDBLkCmbBx      -> KeyValue;
    //DM -> QLocality ->
    //    ParamByName ("N_TYPE")   -> AsInteger =
    //        Type_localityDBLkCmbBx -> KeyValue;
    //DM -> QLocality -> Open ();

    //if (DM -> QAbitura -> State == dsInsert)
    //    LocalityDBLkCmbBx -> KeyValue = -1;
}
void __fastcall TAddressLifeForm::Type_localityDBLkCmbBxMouseDown (
        TObject      * Sender,
        TMouseButton   Button,
        TShiftState    Shift,
        int            X,
        int            Y
    )
{
    //setTerrainId (
    //    LocalityDBLkCmbBx -> KeyValue
    //);
}
void __fastcall TAddressLifeForm::Type_streetDBLkCmbBxCloseUp (TObject * Sender)
{
    setStreetTypeId (
        Type_streetDBLkCmbBx -> KeyValue
    );

    DM -> QStreet -> Close ();
    DM -> QStreet ->
        ParamByName ("TYPE_STREET") -> AsInteger =
            Type_streetDBLkCmbBx -> KeyValue;
    DM -> QStreet ->
        ParamByName ("ID_LOCALITY") -> AsInteger =
            LocalityDBLkCmbBx    -> KeyValue;
    DM -> QStreet -> Open ();

    if (DM -> QAbitura -> State == dsInsert)
        StreetDBLkCmbBx -> KeyValue = -1;


    if (getStreetTypeId () != Type_streetDBLkCmbBx -> KeyValue)
        StreetDBLkCmbBx -> KeyValue = 0;

    StreetDBLkCmbBx -> Enabled = true;
}
void __fastcall TAddressLifeForm::Type_streetDBLkCmbBxMouseDown (
        TObject      * Sender,
        TMouseButton   Button,
        TShiftState    Shift,
        int            X,
        int            Y
    )
{
    //setStreetTypeId (
    //    Type_streetDBLkCmbBx -> KeyValue
    //);

    //DM -> QStreet -> Close ();
    //DM -> QStreet ->
    //    ParamByName ("TYPE_STREET") -> AsInteger =
    //        Type_streetDBLkCmbBx -> KeyValue;
    //DM -> QStreet ->
    //    ParamByName ("ID_LOCALITY") -> AsInteger =
    //        LocalityDBLkCmbBx -> KeyValue;
    //DM -> QStreet -> Open ();
    //if (DM -> QAbitura -> State == dsInsert)
    //    StreetDBLkCmbBx -> KeyValue = -1;
}
