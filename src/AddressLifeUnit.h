#pragma once
#ifndef ADDRESS_LIFE_UNIT_H
#define ADDRESS_LIFE_UNIT_H


#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.StdCtrls.hpp>



class TAddressLifeForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;

    TDBEdit           * DBEditFlat;
    TDBEdit           * DBEditHouse;
    TDBEdit           * DBEditPostcode;

    TDBLookupComboBox * DistrictDBLkCmbBx;
    TDBLookupComboBox * LocalityDBLkCmbBx;
    TDBLookupComboBox * RegionDBLookupCmbBx;
    TDBLookupComboBox * StreetDBLkCmbBx;
    TDBLookupComboBox * Type_localityDBLkCmbBx;
    TDBLookupComboBox * Type_streetDBLkCmbBx;

    TLabel            * Label28;
    TLabel            * Label48;
    TLabel            * Label51;
    TLabel            * Label54;
    TLabel            * Label68;
    TLabel            * Label69;
    TLabel            * Label70;
    TLabel            * Label71;
    TLabel            * Label72;
    //TLabel            * Notice_RequiredDistrict;
    //TLabel            * Notice_RequiredLocality;
    //TLabel            * Notice_RequiredRegion;
    //TLabel            * Notice_RequiredTypeLocality;
    //TLabel            * Notice_RequiredTypeStreet;


    void __fastcall BitBtn1Click                    (TObject * Sender);
    void __fastcall DistrictDBLkCmbBxCloseUp        (TObject * Sender);
    void __fastcall DistrictDBLkCmbBxExit           (TObject * Sender);
    void __fastcall DistrictDBLkCmbBxMouseDown      (
            TObject      * Sender,
            TMouseButton   Button,
            TShiftState    Shift,
            int            X,
            int            Y
        );
    void __fastcall DistrictDBLkCmbBxMouseEnter     (TObject * Sender);
    void __fastcall LocalityDBLkCmbBxCloseUp        (TObject * Sender);
    void __fastcall LocalityDBLkCmbBxExit           (TObject * Sender);
    void __fastcall LocalityDBLkCmbBxMouseDown      (
            TObject      * Sender,
            TMouseButton   Button,
            TShiftState    Shift,
            int            X,
            int            Y
        );
    void __fastcall RegionDBLookupCmbBxCloseUp      (TObject * Sender);
    void __fastcall Type_localityDBLkCmbBxCloseUp   (TObject * Sender);
    void __fastcall Type_localityDBLkCmbBxExit      (TObject * Sender);
    void __fastcall Type_localityDBLkCmbBxMouseDown (
            TObject      * Sender,
            TMouseButton   Button,
            TShiftState    Shift,
            int            X,
            int            Y
        );
    void __fastcall Type_streetDBLkCmbBxCloseUp     (TObject * Sender);
    void __fastcall Type_streetDBLkCmbBxMouseDown   (
            TObject      * Sender,
            TMouseButton   Button,
            TShiftState    Shift,
            int            X,
            int            Y
        );
private:
    AnsiString
        _address;
    bool
        _isAddressSaved;
    int
        _regionId,
        _terrainId,
        _terrainTypeId,
        _streetTypeId;
public:
    __fastcall TAddressLifeForm (TComponent * Owner);
    __fastcall TAddressLifeForm (
            TComponent        * Owner,
            TDBLookupComboBox * RegionDBLookupCmbBx
        );


    // GETTERS
    AnsiString __fastcall getAddress       () const;
    bool       __fastcall isAddressSaved   () const;
    int        __fastcall getRegionId      () const;
    int        __fastcall getTerrainId     () const;
    int        __fastcall getTerrainTypeId () const;
    int        __fastcall getStreetTypeId  () const;
    // SETTERS
    void __fastcall setAddress        (const AnsiString & address);
    void __fastcall setIsAddressSaved (const bool isSaved);
    void __fastcall setRegionId       (const int regionId);
    void __fastcall setTerrainId      (const int terrainId);
    void __fastcall setTerrainTypeId  (const int terrainTypeId);
    void __fastcall setStreetTypeId   (const int streetTypeId);

    void __fastcall addToAddress (const AnsiString & addToAddress);
};

extern PACKAGE TAddressLifeForm * AddressLifeForm;

#endif  // ADDRESS_LIFE_UNIT_H