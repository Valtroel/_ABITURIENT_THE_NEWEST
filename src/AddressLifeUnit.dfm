object AddressLifeForm: TAddressLifeForm
  Left = 0
  Top = 0
  Caption = #1040#1076#1088#1077#1089' '#1087#1088#1086#1078#1080#1074#1072#1085#1080#1103
  ClientHeight = 177
  ClientWidth = 646
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 14
  object Label72: TLabel
    Left = 395
    Top = 124
    Width = 45
    Height = 20
    Caption = #1048#1085#1076#1077#1082#1089':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
  end
  object Label70: TLabel
    Left = 413
    Top = 97
    Width = 26
    Height = 20
    Caption = #1044#1086#1084':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
  end
  object Label71: TLabel
    Left = 519
    Top = 97
    Width = 57
    Height = 20
    Caption = #1050#1074#1072#1088#1090#1080#1088#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
  end
  object Label69: TLabel
    Left = 400
    Top = 71
    Width = 39
    Height = 20
    Caption = #1059#1083#1080#1094#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
  end
  object Label68: TLabel
    Left = 375
    Top = 44
    Width = 64
    Height = 20
    Caption = #1058#1080#1087' '#1091#1083#1080#1094#1099':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
  end
  object Label54: TLabel
    Left = 20
    Top = 89
    Width = 109
    Height = 20
    Caption = #1053#1072#1089#1077#1083#1105#1085#1085#1099#1081' '#1087#1091#1085#1082#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
  end
  object Label51: TLabel
    Left = 20
    Top = 62
    Width = 142
    Height = 20
    Caption = #1058#1080#1087' '#1085#1072#1089#1077#1083#1105#1085#1085#1086#1075#1086' '#1087#1091#1085#1082#1090#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
  end
  object Label48: TLabel
    Left = 20
    Top = 35
    Width = 39
    Height = 20
    Caption = #1056#1072#1081#1086#1085':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
  end
  object Label28: TLabel
    Left = 20
    Top = 8
    Width = 43
    Height = 20
    Caption = #1056#1077#1075#1080#1086#1085':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
  end
  object Type_streetDBLkCmbBx: TDBLookupComboBox
    Left = 453
    Top = 40
    Width = 182
    Height = 25
    DataField = 'TYPE_STREET'
    DataSource = DM.DSAdress
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    KeyField = 'ID'
    ListField = 'TYPE'
    ListSource = DM.DSType_street
    ParentFont = False
    TabOrder = 0
    OnCloseUp = Type_streetDBLkCmbBxCloseUp
    OnMouseDown = Type_streetDBLkCmbBxMouseDown
  end
  object StreetDBLkCmbBx: TDBLookupComboBox
    Left = 453
    Top = 67
    Width = 182
    Height = 25
    DataField = 'STREET'
    DataSource = DM.DSAbitura
    DropDownRows = 30
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    KeyField = 'ID'
    ListField = 'NAME_IN_RUS'
    ListSource = DM.DSStreet
    ParentFont = False
    TabOrder = 1
  end
  object LocalityDBLkCmbBx: TDBLookupComboBox
    Left = 145
    Top = 88
    Width = 210
    Height = 25
    DataField = 'LOCAL_ID'
    DataSource = DM.DSAdress
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    KeyField = 'ID'
    ListField = 'NAME_LOCALITY'
    ListSource = DM.DSLocality
    ParentFont = False
    TabOrder = 2
    OnCloseUp = LocalityDBLkCmbBxCloseUp
    OnExit = LocalityDBLkCmbBxExit
    OnMouseDown = LocalityDBLkCmbBxMouseDown
  end
  object Type_localityDBLkCmbBx: TDBLookupComboBox
    Left = 175
    Top = 61
    Width = 180
    Height = 25
    DataField = 'N_TYPE'
    DataSource = DM.DSAdress
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    KeyField = 'N_TYPE'
    ListField = 'NAME_TYPE'
    ListSource = DM.DSType_locality
    ParentFont = False
    TabOrder = 3
    OnCloseUp = Type_localityDBLkCmbBxCloseUp
    OnExit = Type_localityDBLkCmbBxExit
    OnMouseDown = Type_localityDBLkCmbBxMouseDown
  end
  object DistrictDBLkCmbBx: TDBLookupComboBox
    Left = 75
    Top = 34
    Width = 280
    Height = 25
    DataField = 'N_DISTRICT'
    DataSource = DM.DSAdress
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    KeyField = 'N_DISTRICT'
    ListField = 'NAME_DISTRICT'
    ListSource = DM.DSDistrict
    ParentFont = False
    TabOrder = 4
    OnCloseUp = DistrictDBLkCmbBxCloseUp
    OnExit = DistrictDBLkCmbBxExit
    OnMouseDown = DistrictDBLkCmbBxMouseDown
    OnMouseEnter = DistrictDBLkCmbBxMouseEnter
  end
  object DBEditHouse: TDBEdit
    Left = 453
    Top = 94
    Width = 45
    Height = 25
    DataField = 'HOUSE'
    DataSource = DM.DSAbitura
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object DBEditFlat: TDBEdit
    Left = 586
    Top = 94
    Width = 49
    Height = 25
    DataField = 'FLAT'
    DataSource = DM.DSAbitura
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object DBEditPostcode: TDBEdit
    Left = 453
    Top = 121
    Width = 65
    Height = 25
    DataField = 'POSTCODE'
    DataSource = DM.DSAbitura
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
  end
  object BitBtn1: TBitBtn
    Left = 540
    Top = 140
    Width = 90
    Height = 30
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = []
    Kind = bkOK
    NumGlyphs = 2
    ParentFont = False
    TabOrder = 8
    OnClick = BitBtn1Click
  end
  object RegionDBLookupCmbBx: TDBLookupComboBox
    Left = 75
    Top = 7
    Width = 280
    Height = 25
    Color = 14936298
    DataField = 'N_REGION'
    DataSource = DM.DSAbitura
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    KeyField = 'N_REGION'
    ListField = 'TEXT_REGION'
    ListSource = DM.DSRegion
    ParentFont = False
    TabOrder = 9
    OnCloseUp = RegionDBLookupCmbBxCloseUp
  end
end
