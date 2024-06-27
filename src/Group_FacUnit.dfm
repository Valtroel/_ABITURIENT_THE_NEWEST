object Group_FacForm: TGroup_FacForm
  Left = 210
  Top = 119
  Caption = #1055#1077#1088#1077#1074#1086#1076' '#1079#1072#1095#1080#1089#1083#1077#1085#1085#1099#1093' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1086#1074' '#1074' '#1089#1090#1091#1076#1077#1085#1090#1099
  ClientHeight = 572
  ClientWidth = 643
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 643
    Height = 73
    Align = alTop
    BevelInner = bvLowered
    TabOrder = 0
    object Label1: TLabel
      Left = 15
      Top = 39
      Width = 95
      Height = 26
      Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077#13#10#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 15
      Top = 21
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
    object LookSp: TDBLookupComboBox
      Left = 124
      Top = 43
      Width = 269
      Height = 21
      KeyField = 'N_SPECIALIZ'
      ListField = 'SPECIAL'
      ListSource = DM.DSSpecializ
      TabOrder = 1
      Touch.ParentTabletOptions = False
      Touch.TabletOptions = [toPressAndHold]
      OnCloseUp = LookSpCloseUp
    end
    object Button1: TButton
      Left = 480
      Top = 20
      Width = 148
      Height = 37
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1086#1074
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = Button1Click
    end
    object ComboBox1: TComboBox
      Left = 124
      Top = 16
      Width = 269
      Height = 21
      TabOrder = 0
      Items.Strings = (
        #1044#1085#1077#1074#1085#1086#1077
        #1047#1072#1086#1095#1085#1086#1077)
    end
    object RadioGroup1: TRadioGroup
      Left = 400
      Top = 11
      Width = 73
      Height = 52
      ItemIndex = 0
      Items.Strings = (
        #1041#1102#1076#1078#1077#1090
        #1054#1087#1083#1072#1090#1072)
      TabOrder = 3
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 73
    Width = 643
    Height = 343
    Align = alClient
    BevelInner = bvLowered
    TabOrder = 1
    object Bevel1: TBevel
      Left = 2
      Top = 2
      Width = 639
      Height = 31
      Align = alTop
      Style = bsRaised
      ExplicitWidth = 647
    end
    object Label6: TLabel
      Left = 7
      Top = 10
      Width = 297
      Height = 13
      Caption = #1057#1087#1080#1089#1086#1082' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1086#1074' '#1074#1099#1073#1088#1072#1085#1085#1086#1081' '#1089#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Left = 415
      Top = 10
      Width = 199
      Height = 13
      Caption = #1057#1087#1080#1089#1086#1082' '#1079#1072#1095#1080#1089#1083#1077#1085#1085#1099#1093' '#1074' '#1089#1090#1091#1076#1077#1085#1090#1099':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Bevel2: TBevel
      Left = 329
      Top = 33
      Width = 69
      Height = 308
      Align = alClient
      Style = bsRaised
      ExplicitWidth = 77
      ExplicitHeight = 319
    end
    object SpeedButton1: TSpeedButton
      Left = 352
      Top = 56
      Width = 30
      Height = 30
      Hint = #1055#1077#1088#1077#1084#1077#1089#1090#1080#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1086#1075#1086' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1072' '#1074' '#1089#1087#1080#1089#1086#1082' '#1079#1072#1095#1080#1089#1083#1077#1085#1085#1099#1093
      Glyph.Data = {
        16020000424D160200000000000076000000280000001B0000001A0000000100
        040000000000A001000074120000741200001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000777777777707
        7777777777777770000077777777770077777777777777700000777777777700
        0777777777777770000077777777770000777777777777700000777777777700
        0007777777777770000077777777770000007777777777700000777777777700
        0000077777777770000077777777770000000077777777700000777777777700
        0000077777777770000077777777770000007777777777700000777777777700
        0007777777777770000077777777770000777777777777700000777777777700
        0777777777777770000077777777770077777777777777700000777777777707
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000}
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton1Click
    end
    object SpeedButton2: TSpeedButton
      Left = 352
      Top = 104
      Width = 30
      Height = 30
      Hint = #1055#1077#1088#1077#1084#1077#1089#1090#1080#1090#1100' '#1074#1089#1077#1093' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1086#1074' '#1074' '#1089#1087#1080#1089#1086#1082' '#1079#1072#1095#1080#1089#1083#1077#1085#1085#1099#1093
      Glyph.Data = {
        16020000424D160200000000000076000000280000001B0000001A0000000100
        040000000000A001000074120000741200001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000777770777777
        7707777777777770000077777007777777007777777777700000777770007777
        7700077777777770000077777000077777000077777777700000777770000077
        7700000777777770000077777000000777000000777777700000777770000000
        7700000007777770000077777000000007000000007777700000777770000000
        7700000007777770000077777000000777000000777777700000777770000077
        7700000777777770000077777000077777000077777777700000777770007777
        7700077777777770000077777007777777007777777777700000777770777777
        7707777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000}
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton2Click
    end
    object SpeedButton3: TSpeedButton
      Left = 352
      Top = 152
      Width = 30
      Height = 30
      Hint = #1059#1076#1072#1083#1080#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1086#1075#1086' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1072' '#1080#1079' '#1089#1087#1080#1089#1082#1072' '#1079#1072#1095#1080#1089#1083#1077#1085#1085#1099#1093
      Glyph.Data = {
        16020000424D160200000000000076000000280000001B0000001A0000000100
        040000000000A001000074120000741200001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7707777777777770000077777777777770077777777777700000777777777777
        0007777777777770000077777777777000077777777777700000777777777700
        0007777777777770000077777777700000077777777777700000777777770000
        0007777777777770000077777770000000077777777777700000777777770000
        0007777777777770000077777777700000077777777777700000777777777700
        0007777777777770000077777777777000077777777777700000777777777777
        0007777777777770000077777777777770077777777777700000777777777777
        7707777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000}
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton3Click
    end
    object SpeedButton4: TSpeedButton
      Left = 352
      Top = 200
      Width = 30
      Height = 30
      Hint = #1059#1076#1072#1083#1080#1090#1100' '#1074#1089#1077#1093' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1086#1074' '#1080#1079' '#1089#1087#1080#1089#1082#1072' '#1079#1072#1095#1080#1089#1083#1077#1085#1085#1099#1093
      Glyph.Data = {
        16020000424D160200000000000076000000280000001B0000001A0000000100
        040000000000A001000074120000741200001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000777777777770
        7777777707777770000077777777770077777770077777700000777777777000
        7777770007777770000077777777000077777000077777700000777777700000
        7777000007777770000077777700000077700000077777700000777770000000
        7700000007777770000077770000000070000000077777700000777770000000
        7700000007777770000077777700000077700000077777700000777777700000
        7777000007777770000077777777000077777000077777700000777777777000
        7777770007777770000077777777770077777770077777700000777777777770
        7777777707777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000777777777777
        7777777777777770000077777777777777777777777777700000}
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton4Click
    end
    object List1: TListBox
      Left = 398
      Top = 33
      Width = 243
      Height = 308
      Align = alRight
      ItemHeight = 13
      TabOrder = 0
    end
    object DBGrid1: TDBGrid
      Left = 2
      Top = 33
      Width = 327
      Height = 308
      Align = alLeft
      DataSource = DM.DSSelect_ab
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
      TabOrder = 1
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -10
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      OnDblClick = DBGrid1DblClick
      Columns = <
        item
          Expanded = False
          FieldName = 'FAM'
          Title.Alignment = taCenter
          Title.Caption = #1060#1072#1084#1080#1083#1080#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 124
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAME'
          Title.Alignment = taCenter
          Title.Caption = #1048#1084#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 82
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'OTCH'
          Title.Alignment = taCenter
          Title.Caption = #1054#1090#1095#1077#1089#1090#1074#1086
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end>
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 416
    Width = 643
    Height = 156
    Align = alBottom
    BevelInner = bvLowered
    TabOrder = 2
    object Label2: TLabel
      Left = 17
      Top = 56
      Width = 95
      Height = 26
      Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077#13#10#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 17
      Top = 89
      Width = 90
      Height = 13
      Caption = #1053#1086#1084#1077#1088' '#1075#1088#1091#1087#1087#1099':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 17
      Top = 116
      Width = 143
      Height = 13
      Caption = #1054#1089#1085#1086#1074#1072#1085#1080#1077' '#1079#1072#1095#1080#1089#1083#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 17
      Top = 8
      Width = 400
      Height = 13
      Caption = 
        #1042#1099#1073#1077#1088#1080#1090#1077' '#8470' '#1075#1088#1091#1087#1087#1099', '#1089#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1102' '#1080' '#1086#1089#1085#1086#1074#1072#1085#1080#1103' '#1076#1083#1077' '#1079#1072#1095#1080#1089#1083#1077#1085#1080#1103' '#1074' '#1089#1090 +
        #1091#1076#1077#1085#1090#1099':'
    end
    object Label9: TLabel
      Left = 243
      Top = 89
      Width = 33
      Height = 13
      Caption = #1050#1091#1088#1089':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label10: TLabel
      Left = 16
      Top = 36
      Width = 97
      Height = 13
      Caption = #1053#1086#1084#1077#1088' '#1087#1088#1080#1082#1072#1079#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label11: TLabel
      Left = 232
      Top = 36
      Width = 88
      Height = 13
      Caption = #1044#1072#1090#1072' '#1087#1088#1080#1082#1072#1079#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LookNewSp: TDBLookupComboBox
      Left = 168
      Top = 60
      Width = 273
      Height = 21
      KeyField = 'N_SPECIALIZ'
      ListField = 'SPECIAL'
      ListSource = DM.DSSpecializ
      TabOrder = 0
    end
    object Edit1: TEdit
      Left = 168
      Top = 85
      Width = 53
      Height = 21
      TabOrder = 1
    end
    object LookFound: TDBLookupComboBox
      Left = 168
      Top = 113
      Width = 233
      Height = 21
      KeyField = 'N_FOUND'
      ListField = 'VID_FOUND'
      ListSource = DM.DSFoundation
      TabOrder = 3
      OnCloseUp = LookFoundCloseUp
    end
    object Button2: TButton
      Left = 446
      Top = 103
      Width = 182
      Height = 37
      Caption = #1047#1072#1095#1080#1089#1083#1080#1090#1100' '#1074' '#1089#1090#1091#1076#1077#1085#1090#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnClick = Button2Click
    end
    object Edit2: TEdit
      Left = 329
      Top = 85
      Width = 70
      Height = 21
      TabOrder = 2
      Text = '1'
    end
    object Edit3: TEdit
      Left = 168
      Top = 32
      Width = 53
      Height = 21
      TabOrder = 5
    end
    object CheckBox1: TCheckBox
      Left = 168
      Top = 136
      Width = 97
      Height = 17
      Caption = #1047#1072' '#1086#1087#1083#1072#1090#1091
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
    end
    object DateTimePicker1: TDateTimePicker
      Left = 326
      Top = 33
      Width = 115
      Height = 21
      Date = 44778.000000000000000000
      Time = 44778.000000000000000000
      TabOrder = 7
      OnChange = DateTimePicker1Change
    end
  end
end
