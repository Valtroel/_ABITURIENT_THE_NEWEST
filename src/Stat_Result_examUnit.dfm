object Stat_Result_examForm: TStat_Result_examForm
  Left = 214
  Top = 160
  Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1074#1089#1090#1091#1087#1080#1090#1077#1083#1100#1085#1099#1093' '#1080#1089#1087#1099#1090#1072#1085#1080#1081
  ClientHeight = 499
  ClientWidth = 725
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 0
    Top = 105
    Width = 725
    Height = 394
    Align = alClient
    Color = 14936298
    DataSource = DMStat.DSCount_Ball_Examen
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -10
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Visible = False
    Columns = <
      item
        Expanded = False
        FieldName = 'SPEC1'
        Title.Alignment = taCenter
        Title.Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1080
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = [fsBold]
        Width = 498
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'BALL'
        Title.Alignment = taCenter
        Title.Caption = #1054#1094#1077#1085#1082#1072
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = [fsBold]
        Width = 88
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'COUNT'
        Title.Alignment = taCenter
        Title.Caption = #1050#1086#1083'-'#1074#1086' '#1072#1073'.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = [fsBold]
        Width = 98
        Visible = True
      end>
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 725
    Height = 105
    Align = alTop
    BevelOuter = bvLowered
    TabOrder = 1
    object Label1: TLabel
      Left = 212
      Top = 17
      Width = 81
      Height = 20
      Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 212
      Top = 45
      Width = 53
      Height = 20
      Caption = #1055#1088#1077#1076#1084#1077#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 212
      Top = 73
      Width = 32
      Height = 20
      Caption = #1071#1079#1099#1082':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object BitBtn1: TBitBtn
      Left = 585
      Top = 15
      Width = 130
      Height = 32
      Cursor = crHandPoint
      Caption = #1055#1086#1082#1072#1079#1072#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
      Glyph.Data = {
        42010000424D4201000000000000760000002800000011000000110000000100
        040000000000CC00000000000000000000001000000010000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00DDDDDDDDDDDD
        DDDDD0000000DDDDDDDDDDDDDDDDD0000000D444444444444444D0000000D4FF
        FFFFFFFFFFF4D0000000D4F000F000F000F4D0000000D4FFFFFFFFFFFFF4D000
        0000D4F000F000F000F4D0000000D4FFFFFFFFFFFFF4D0000000D4F000F000F0
        00F4D0000000D4FFFFFFFFFFFFF4D0000000D4F000F000F000F4D0000000D4FF
        FFFFFFFFFFF4D0000000D444444444444444D0000000D4F444F444F444F4D000
        0000D444444444444444D0000000DDDDDDDDDDDDDDDDD0000000DDDDDDDDDDDD
        DDDDD0000000}
      ParentFont = False
      Spacing = 10
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object Vid_edu: TComboBox
      Left = 300
      Top = 16
      Width = 280
      Height = 25
      Style = csDropDownList
      Color = 15856113
      DropDownCount = 3
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnChange = Vid_eduChange
      Items.Strings = (
        #1044#1085#1077#1074#1085#1086#1077
        #1047#1072#1086#1095#1085#1086#1077)
    end
    object LookPredm: TDBLookupComboBox
      Left = 300
      Top = 44
      Width = 280
      Height = 25
      Color = 15856113
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      KeyField = 'N_PREDMET'
      ListField = 'TEXT_PREDMET'
      ListSource = DM.DSPredmet
      ParentFont = False
      TabOrder = 2
      OnCloseUp = LookPredmCloseUp
    end
    object RadioGroup1: TRadioGroup
      Left = 16
      Top = 8
      Width = 177
      Height = 89
      Caption = #1042#1080#1076' '#1080#1089#1087#1099#1090#1072#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      Items.Strings = (
        #1069#1082#1079#1072#1084#1077#1085#1099
        #1057#1077#1088#1090#1080#1092#1080#1082#1072#1090#1099
        #1054#1083#1080#1084#1087#1080#1072#1076#1099
        #1069#1082#1079#1072#1084#1077#1085#1099' '#1074' '#1076#1088'.'#1042#1059#1047#1072#1093)
      ParentFont = False
      TabOrder = 3
      OnClick = Vid_eduChange
    end
    object ComboBox1: TComboBox
      Left = 300
      Top = 72
      Width = 280
      Height = 25
      Style = csDropDownList
      Color = 15856113
      DropDownCount = 3
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      Visible = False
      OnChange = Vid_eduChange
      Items.Strings = (
        #1056#1091#1089#1089#1082#1080#1081
        #1041#1077#1083#1086#1088#1091#1089#1089#1082#1080#1081)
    end
    object BitBtn2: TBitBtn
      Left = 585
      Top = 66
      Width = 130
      Height = 32
      Cursor = crHandPoint
      Caption = #1042' Excel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
      Glyph.Data = {
        4E010000424D4E01000000000000760000002800000012000000120000000100
        040000000000D800000000000000000000001000000010000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777770000007777777777777777770000007777777777770007770000007444
        4400000006007700000074FFFF08880600080700000074F008000060EE070700
        000074FFFFF8060EE0047700000074F0088060EE00F47700000074FFFF060EE0
        00747700000074F00800EE0EE0047700000074FFFF0EE0F0EE047700000074F0
        080000F000047700000074FFFFFFFFFFFFF47700000074444444444444447700
        000074F444F444F444F477000000744444444444444477000000777777777777
        777777000000777777777777777777000000}
      ParentFont = False
      Spacing = 22
      TabOrder = 5
      Visible = False
      OnClick = BitBtn2Click
    end
  end
end
