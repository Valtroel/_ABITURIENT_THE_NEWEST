object Undo_Ab_1Form: TUndo_Ab_1Form
  Left = 365
  Top = 189
  BorderIcons = []
  Caption = #1042#1086#1089#1089#1090#1072#1085#1086#1074#1083#1077#1085#1080#1077
  ClientHeight = 449
  ClientWidth = 410
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 410
    Height = 59
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object DBText1: TDBText
      Left = 19
      Top = 7
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'FAM'
      DataSource = DM.DSAbitura
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText2: TDBText
      Left = 19
      Top = 24
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'NAME'
      DataSource = DM.DSAbitura
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText3: TDBText
      Left = 19
      Top = 40
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'OTCH'
      DataSource = DM.DSAbitura
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 59
    Width = 410
    Height = 390
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    ExplicitHeight = 375
    object Label5: TLabel
      Left = 10
      Top = 15
      Width = 49
      Height = 13
      Caption = #8470' '#1076#1077#1083#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 10
      Top = 94
      Width = 63
      Height = 13
      Caption = #8470' '#1075#1088#1091#1087#1087#1099':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 10
      Top = 41
      Width = 85
      Height = 13
      Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 10
      Top = 67
      Width = 97
      Height = 13
      Caption = #1057#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Left = 10
      Top = 263
      Width = 72
      Height = 13
      Caption = #1042#1080#1076' '#1089#1087#1086#1088#1090#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 10
      Top = 295
      Width = 48
      Height = 13
      Caption = #1056#1072#1079#1088#1103#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label29: TLabel
      Left = 146
      Top = 197
      Width = 106
      Height = 26
      Caption = #1054#1090#1082#1091#1076#1072#13#10#1094#1077#1083#1077#1074#1086#1081' '#1076#1086#1075#1086#1074#1086#1088':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label3: TLabel
      Left = 110
      Top = 324
      Width = 157
      Height = 13
      Caption = #1044#1072#1090#1072' '#1087#1088#1080#1077#1084#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 282
      Top = 324
      Width = 39
      Height = 13
      Caption = 'Label4'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit2: TEdit
      Left = 110
      Top = 11
      Width = 52
      Height = 21
      Color = 14936298
      TabOrder = 0
    end
    object ComboBox1: TComboBox
      Left = 110
      Top = 37
      Width = 120
      Height = 21
      Color = 14936298
      TabOrder = 1
      OnChange = ComboBox1Change
      Items.Strings = (
        #1044#1085#1077#1074#1085#1086#1077
        #1047#1072#1086#1095#1085#1086#1077)
    end
    object DBLookupComboBox1: TDBLookupComboBox
      Left = 110
      Top = 63
      Width = 300
      Height = 21
      Color = 14936298
      KeyField = 'N_SPECIALIZ'
      ListField = 'SPECIAL'
      ListSource = DM.DSSpecializPlan_Priem
      TabOrder = 2
      OnCloseUp = DBLookupComboBox1CloseUp
    end
    object DBLookupComboBox2: TDBLookupComboBox
      Left = 110
      Top = 259
      Width = 300
      Height = 21
      Color = 14936298
      DataField = 'N_VID_SPORT'
      DataSource = DM.DSAbitura
      KeyField = 'N_VID_SPORT'
      ListField = 'VID_SPORT'
      ListSource = DM.DSVid_Sport
      TabOrder = 4
    end
    object DBLookupComboBox3: TDBLookupComboBox
      Left = 110
      Top = 291
      Width = 120
      Height = 21
      Color = 14936298
      DataField = 'N_SPORT_CATEGORY'
      DataSource = DM.DSAbitura
      KeyField = 'N_SPORT_CATEGORY'
      ListField = 'SPORT_CATEGORY'
      ListSource = DM.DSCategory
      TabOrder = 5
    end
    object DBLookupComboBox4: TDBLookupComboBox
      Left = 144
      Top = 227
      Width = 266
      Height = 21
      Color = 14936298
      DataField = 'N_CK'
      DataSource = DM.DSAbitura
      KeyField = 'N_CK'
      ListField = 'TEXT_DEP'
      ListSource = DM.DSCkQ
      TabOrder = 6
      Visible = False
    end
    object BitBtn1: TBitBtn
      Left = 25
      Top = 349
      Width = 86
      Height = 26
      Cursor = crHandPoint
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = bkOK
      NumGlyphs = 2
      ParentFont = False
      TabOrder = 7
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 305
      Top = 349
      Width = 86
      Height = 26
      Cursor = crHandPoint
      Caption = #1042#1099#1093#1086#1076
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = bkClose
      NumGlyphs = 2
      ParentFont = False
      TabOrder = 8
      OnClick = BitBtn2Click
    end
    object ComboBox2: TComboBox
      Left = 110
      Top = 90
      Width = 120
      Height = 21
      Style = csDropDownList
      Color = 14936298
      TabOrder = 3
    end
    object PriceCmbBx: TComboBox
      Left = 13
      Top = 170
      Width = 94
      Height = 21
      Style = csDropDownList
      Color = 14936298
      TabOrder = 9
      Items.Strings = (
        #1073#1102#1076#1078#1077#1090
        #1079#1072' '#1086#1087#1083#1072#1090#1091)
    end
    object KonkursCmbBx: TComboBox
      Left = 167
      Top = 170
      Width = 203
      Height = 21
      Style = csDropDownList
      Color = 14936298
      TabOrder = 10
      Items.Strings = (
        #1086#1073#1097#1080#1081
        #1073#1077#1079' '#1074#1089#1090#1091#1087#1080#1090#1077#1083#1100#1085#1099#1093' '#1080#1089#1087#1099#1090#1072#1085#1080#1081
        #1074#1085#1077' '#1082#1086#1085#1082#1091#1088#1089#1072
        #1094#1077#1083#1077#1074#1086#1081)
    end
    object SngFrgCmbBx: TComboBox
      Left = 227
      Top = 130
      Width = 135
      Height = 21
      Style = csDropDownList
      Color = 14936298
      TabOrder = 11
      Items.Strings = (
        #1056#1041
        #1048#1085#1086#1089#1090#1088#1072#1085#1077#1094)
    end
    object CategoryAbCmbBx: TComboBox
      Left = 19
      Top = 130
      Width = 145
      Height = 21
      Style = csDropDownList
      Color = 14936298
      TabOrder = 12
      Items.Strings = (
        #1041#1077#1083#1072#1088#1091#1089#1100
        #1048#1085#1086#1089#1090#1088#1072#1085#1094#1099
        #1057#1053#1043
        #1044#1053#1056'/'#1051#1053#1056)
    end
  end
end
