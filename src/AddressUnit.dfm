object AddressForm: TAddressForm
  Left = 0
  Top = 0
  Caption = #1040#1076#1088#1077#1089' '#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1080
  ClientHeight = 146
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label72: TLabel
    Left = 390
    Top = 92
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
    Left = 408
    Top = 65
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
    Left = 511
    Top = 65
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
    Left = 397
    Top = 39
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
    Left = 372
    Top = 12
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
    Left = 17
    Top = 66
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
    Left = 17
    Top = 39
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
    Left = 17
    Top = 12
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
  object Notice_RequiredTypeStreet: TLabel
    Left = 475
    Top = 40
    Width = 120
    Height = 13
    Caption = '--'#1059#1082#1072#1078#1080#1090#1077' '#1090#1080#1087' '#1091#1083#1080#1094#1099' --'
  end
  object Notice_RequiredDistinct: TLabel
    Left = 220
    Top = 40
    Width = 100
    Height = 13
    Caption = '-- '#1059#1082#1072#1078#1080#1090#1077' '#1056#1072#1081#1086#1085' --'
  end
  object Notice_RequiredTypeLocality: TLabel
    Left = 160
    Top = 65
    Width = 194
    Height = 13
    Caption = '-- '#1059#1082#1072#1078#1080#1090#1077' '#1058#1080#1087' '#1085#1072#1089#1077#1083#1077#1085#1085#1086#1075#1086' '#1087#1091#1085#1082#1090#1072' --'
  end
  object Notice_RequiredLocality: TLabel
    Left = 455
    Top = 12
    Width = 165
    Height = 13
    Caption = '-- '#1059#1082#1072#1078#1080#1090#1077' '#1053#1072#1089#1077#1083#1077#1085#1085#1099#1081' '#1087#1091#1085#1082#1090' --'
  end
  object Type_streetDBLkCmbBx: TDBLookupComboBox
    Left = 445
    Top = 8
    Width = 182
    Height = 25
    Hint = #1042#1099#1073#1086#1088' '#1054#1041#1071#1047#1040#1058#1045#1051#1045#1053'!!!'
    DataField = 'TYPE_STREET'
    DataSource = DM.DSAdress
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    KeyField = 'ID'
    ListField = 'TYPE'
    ListSource = DM.DSType_street
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    OnCloseUp = Type_streetDBLkCmbBxCloseUp
    OnMouseDown = Type_streetDBLkCmbBxMouseDown
  end
  object StreetDBLkCmbBx: TDBLookupComboBox
    Left = 445
    Top = 35
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
    Touch.InteractiveGestureOptions = [igoPanSingleFingerVertical, igoParentPassthrough]
    Touch.ParentTabletOptions = False
    Touch.TabletOptions = [toPressAndHold, toSmoothScrolling]
    Visible = False
    OnClick = Type_streetDBLkCmbBxCloseUp
  end
  object LocalityDBLkCmbBx: TDBLookupComboBox
    Left = 139
    Top = 62
    Width = 227
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
    Visible = False
    OnCloseUp = LocalityDBLkCmbBxCloseUp
    OnExit = LocalityDBLkCmbBxExit
    OnMouseDown = LocalityDBLkCmbBxMouseDown
  end
  object Type_localityDBLkCmbBx: TDBLookupComboBox
    Left = 184
    Top = 35
    Width = 182
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
    Visible = False
    OnCloseUp = Type_localityDBLkCmbBxCloseUp
    OnExit = Type_localityDBLkCmbBxExit
    OnMouseDown = Type_localityDBLkCmbBxMouseDown
    OnMouseEnter = Type_localityDBLkCmbBxMouseEnter
  end
  object DistrictDBLkCmbBx: TDBLookupComboBox
    Left = 64
    Top = 8
    Width = 302
    Height = 25
    DataField = 'N_DISTRICT'
    DataSource = DM.DSAdress
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
    OnMouseDown = DistrictDBLkCmbBxMouseDown
  end
  object DBEditHouse: TDBEdit
    Left = 445
    Top = 62
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
    Left = 578
    Top = 62
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
    Left = 445
    Top = 89
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
    Top = 110
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
end
