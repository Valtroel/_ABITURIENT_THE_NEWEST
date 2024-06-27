#include <vcl.h>
#pragma hdrstop


#include "AbiturUnit.h"
#include "AddressUnit.h"
#include "DMUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TAddressForm * AddressForm;



__fastcall TAddressForm::TAddressForm (TComponent * Owner)
    : TForm (Owner)
{ }
__fastcall TAddressForm::TAddressForm (
        TComponent        * Owner,
        TDBLookupComboBox * RegionDBLookupCmbBx
    ) : TForm (Owner)
{
    setRegionId (
        RegionDBLookupCmbBx -> KeyValue
    );

    if (getRegionId () == 5)                                                    // Select 'г. Минск'
    {
        this -> Label48                     -> Visible = false;                 // "Район:"
        this -> DistrictDBLkCmbBx           -> Visible = false;
        this -> DistrictDBLkCmbBx           -> Enabled = false;

        this -> Label51                     -> Visible = false;                 // "Тип населённого пункта:"
        this -> Notice_RequiredDistinct     -> Visible = false;                 // "-- Укажите Район --"

        this -> Label54                     -> Visible = false;                 // "Населённый пункт:"
        this -> Notice_RequiredTypeLocality -> Visible = false;                 // "-- Укажите Тип населенного пункта --"

        this -> Notice_RequiredLocality     -> Visible = false;                 // "-- Укажите Населенный пункт --"
        this -> Type_streetDBLkCmbBx        -> Visible = true;
        this -> Type_streetDBLkCmbBx        -> Enabled = true;

        this -> DistrictDBLkCmbBx      -> KeyValue = 0;
        this -> Type_localityDBLkCmbBx -> KeyValue = 1;
        this -> LocalityDBLkCmbBx      -> KeyValue = 1;

        DM -> QType_street -> Close ();
        DM -> QType_street -> Open ();
    }
    else                                                                        // Select some district: '... обл.'
    {
        this -> Label48                     -> Visible = true;                  // "Район:"
        this -> DistrictDBLkCmbBx           -> Visible = true;
        this -> DistrictDBLkCmbBx           -> Enabled = true;

        this -> Label51                     -> Visible = true;                  // "Тип населённого пункта:"
        this -> Notice_RequiredDistinct     -> Visible = true;                  // "-- Укажите Район --"

        this -> Label54                     -> Visible = true;                  // "Населённый пункт:"
        this -> Notice_RequiredTypeLocality -> Visible = true;                  // "-- Укажите Тип населенного пункта --"

        this -> Notice_RequiredLocality     -> Visible = true;                  // "-- Укажите Населенный пункт --"
        this -> Type_streetDBLkCmbBx        -> Visible = false;
        this -> Type_streetDBLkCmbBx        -> Enabled = false;

        DM -> QDistrict -> Close();
        DM -> QDistrict ->
            ParamByName("REGION") -> AsInteger =
                    getRegionId ();
        DM -> QDistrict -> Open();

        if (DM -> QAbitura -> State == dsInsert)
            this -> DistrictDBLkCmbBx -> KeyValue = -1;
    }
}


// GETTERS
AnsiString __fastcall TAddressForm::getAddress       () const
{
    return
        this -> _address;
}
bool       __fastcall TAddressForm::isAddressSaved   () const
{
    return
        this -> _isAddressSaved;
}
int        __fastcall TAddressForm::getDistrictId    () const
{
    return
        this -> _districtId;
}
int        __fastcall TAddressForm::getRegionId      () const
{
    return
        this -> _regionId;
}
int        __fastcall TAddressForm::getTerrainId     () const
{
    return
        this -> _terrainId;
}
int        __fastcall TAddressForm::getTerrainTypeId () const
{
    return
        this -> _terrainTypeId;
}
int  __fastcall TAddressForm::getStreetTypeId  () const
{
    return
        this -> _streetTypeId;
}
// SETTERS
void __fastcall TAddressForm::setAddress        (const AnsiString & address)
{
    this -> _address = address;
}
void __fastcall TAddressForm::setIsAddressSaved (const bool isSaved)
{
    this -> _isAddressSaved = isSaved;
}
void __fastcall TAddressForm::setDistrictId     (const int districtId)
{
    this -> _districtId = districtId;
}
void __fastcall TAddressForm::setRegionId       (const int regionId)
{
    this -> _regionId = regionId;
}
void __fastcall TAddressForm::setTerrainId      (const int terrainId)
{
    this -> _terrainId = terrainId;
}
void __fastcall TAddressForm::setTerrainTypeId  (const int terrainTypeId)
{
    this -> _terrainTypeId = terrainTypeId;
}
void __fastcall TAddressForm::setStreetTypeId   (const int streetTypeId)
{
    this -> _streetTypeId = streetTypeId;
}

void __fastcall TAddressForm::addToAddress (const AnsiString & addition)
{
    this -> _address += addition;
}


void __fastcall TAddressForm::BitBtn1Click (TObject * Sender)
{
    if (DM -> TRegionN_REGION -> Value == 5)                                    // The region is 'г. Минск'
        setAddress (
            DM -> TRegionTEXT_REGION -> Value
        );
    else
        setAddress (
                DM -> TRegionTEXT_REGION            -> Value    +               // e.g.: "Витебская обл."
            ", "                                                +
                DM -> QDistrictNAME_DISTRICT        -> Value    +               // e.g.: "Ветковский"
            " р-н, "                                            +
                DM -> QType_localitySHORT_TYPE_NAME -> Value    +               // e.g.: "г."
            " "                                                 +
                DM -> QLocalityNAME_LOCALITY        -> Value                    // e.g.: "Вятка"
        );


    if (DM -> QType_streetSHORT_TYPE -> Value != "-")
        addToAddress (
            ", "                                        +
                DM -> QType_streetSHORT_TYPE -> Value   +
            " "                                         +
                DM -> QStreetNAME_IN_RUS     -> Value
        );


    if (DBEditHouse -> Text != "")
        addToAddress (
            ", д. "                                 +
                DM -> QAbituraHOUSE -> Value
        );


    if (DBEditFlat -> Text != "")
        addToAddress (
            ", кв. "                                +
                IntToStr (
                    DM -> QAbituraFLAT -> Value
                )
        );


    if (DBEditPostcode -> Text != "")
        addToAddress (
            ", "                                    +
                IntToStr (
                    DM -> QAbituraPOSTCODE -> Value
                )
        );

    setIsAddressSaved (
        true
    );

    this -> Close ();
}
void __fastcall TAddressForm::DistrictDBLkCmbBxCloseUp (TObject * Sender)
{
    if (getDistrictId () != DistrictDBLkCmbBx -> KeyValue)
    {
        Type_localityDBLkCmbBx -> KeyValue = 0;
        LocalityDBLkCmbBx      -> KeyValue = 0;
        Type_streetDBLkCmbBx   -> KeyValue = 0;
        StreetDBLkCmbBx        -> KeyValue = 0;
    }

    Notice_RequiredDistinct -> Visible = false;
    Notice_RequiredDistinct -> Enabled = false;

    Type_localityDBLkCmbBx  -> Visible = true;
    Type_localityDBLkCmbBx  -> Enabled = true;
}
void __fastcall TAddressForm::DistrictDBLkCmbBxMouseDown (
        TObject      * Sender,
        TMouseButton   Button,
        TShiftState    Shift,
        int            X,
        int            Y
    )
{
    if ( ! DistrictDBLkCmbBx -> KeyValue == NULL)
        setDistrictId (
            DistrictDBLkCmbBx -> KeyValue
        );
}
void __fastcall TAddressForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    DistrictDBLkCmbBx      -> KeyValue = 0;
    Type_localityDBLkCmbBx -> KeyValue = 0;
    LocalityDBLkCmbBx      -> KeyValue = 0;
    Type_streetDBLkCmbBx   -> KeyValue = 0;
    StreetDBLkCmbBx        -> KeyValue = 0;
}
void __fastcall TAddressForm::LocalityDBLkCmbBxCloseUp (TObject * Sender)
{
    DM -> QType_street -> Close ();
    DM -> QType_street -> Open ();

    setTerrainId (
        LocalityDBLkCmbBx -> KeyValue
    );

    if (getTerrainId () != LocalityDBLkCmbBx -> KeyValue)
    {
        Type_streetDBLkCmbBx -> KeyValue = 0;
        StreetDBLkCmbBx      -> KeyValue = 0;
    }

    Notice_RequiredLocality -> Visible = false;
    Notice_RequiredLocality -> Enabled = false;

    Type_streetDBLkCmbBx    -> Visible = true;
    Type_streetDBLkCmbBx    -> Enabled = true;
}



void __fastcall TAddressForm::LocalityDBLkCmbBxExit (TObject * Sender)
{
    // DM -> QType_street -> Close ();
    // DM -> QType_street -> Open ();

    // Type_streetDBLkCmbBx -> KeyValue = 1;
}



void __fastcall TAddressForm::LocalityDBLkCmbBxMouseDown (
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



void __fastcall TAddressForm::Type_localityDBLkCmbBxCloseUp (TObject * Sender)
{
    DM -> QLocality -> Close ();
    DM -> QLocality ->
        ParamByName ("DISTRICT") -> AsInteger =
                DistrictDBLkCmbBx      -> KeyValue;
    DM -> QLocality ->
        ParamByName ("N_TYPE")   -> AsInteger =
                Type_localityDBLkCmbBx -> KeyValue;
    DM -> QLocality -> Open ();

    if (DM -> QAbitura -> State == dsInsert)
        LocalityDBLkCmbBx -> KeyValue = -1;

    if (getTerrainTypeId () != Type_localityDBLkCmbBx -> KeyValue)
    {
        LocalityDBLkCmbBx    -> KeyValue = 0;
        Type_streetDBLkCmbBx -> KeyValue = 0;
        StreetDBLkCmbBx      -> KeyValue = 0;
    }

    Notice_RequiredTypeLocality -> Visible = false;
    Notice_RequiredTypeLocality -> Enabled = false;

    LocalityDBLkCmbBx           -> Visible = true;
    LocalityDBLkCmbBx           -> Enabled = true;

    setTerrainTypeId (
        Type_localityDBLkCmbBx -> KeyValue
    );
}



void __fastcall TAddressForm::Type_localityDBLkCmbBxExit (TObject * Sender)
{
    // DM -> QLocality -> Close ();
    // DM -> QLocality ->
    //     ParamByName ("DISTRICT") -> AsInteger =
    //             DistrictDBLkCmbBx      -> KeyValue;
    // DM -> QLocality ->
    //     ParamByName ("N_TYPE")   -> AsInteger =
    //             Type_localityDBLkCmbBx -> KeyValue;
    // DM -> QLocality -> Open ();

    // if (DM -> QAbitura -> State == dsInsert)
    //     LocalityDBLkCmbBx -> KeyValue = -1;
}



void __fastcall TAddressForm::Type_localityDBLkCmbBxMouseDown (
        TObject      * Sender,
        TMouseButton   Button,
        TShiftState    Shift,
        int            X,
        int            Y
    )
{
    // getTerrainTypeId (
    //    Type_localityDBLkCmbBx -> KeyValue
    //);
}



void __fastcall TAddressForm::Type_localityDBLkCmbBxMouseEnter (TObject * Sender)
{
    DM -> QType_locality -> Close ();
    DM -> QType_locality -> Open ();
}



void __fastcall TAddressForm::Type_streetDBLkCmbBxCloseUp (TObject * Sender)
{
    if (getStreetTypeId () != Type_streetDBLkCmbBx -> KeyValue)
        StreetDBLkCmbBx -> KeyValue = 0;

    Notice_RequiredTypeStreet -> Visible = false;
    Notice_RequiredTypeStreet -> Enabled = false;

    StreetDBLkCmbBx           -> Visible = true;
    StreetDBLkCmbBx           -> Enabled = true;

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
}



void __fastcall TAddressForm::Type_streetDBLkCmbBxMouseDown (
        TObject      * Sender,
        TMouseButton   Button,
        TShiftState    Shift,
        int            X,
        int            Y
    )
{
    // setStreetTypeId (
    //    Type_streetDBLkCmbBx -> KeyValue
    //);

    // DM -> QStreet -> Close ();
    // DM -> QStreet -> 
    //     ParamByName ("TYPE_STREET") -> AsInteger =
    //             Type_streetDBLkCmbBx -> KeyValue;
    // DM -> QStreet -> 
    //     ParamByName ("ID_LOCALITY") -> AsInteger =
    //             LocalityDBLkCmbBx    -> KeyValue;
    // DM -> QStreet -> Open ();

    // if (DM -> QAbitura -> State == dsInsert)
    //     StreetDBLkCmbBx -> KeyValue = -1;
}
