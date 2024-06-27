object ListDlgForm: TListDlgForm
  Left = 304
  Top = 182
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = #1060#1086#1088#1084#1080#1088#1086#1074#1072#1085#1080#1077' '#1088#1072#1089#1087#1080#1089#1082#1080' '#1080' '#1101#1082#1079#1072#1084#1077#1085#1072#1094#1080#1086#1085#1085#1086#1075#1086' '#1083#1080#1089#1090#1072
  ClientHeight = 459
  ClientWidth = 920
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
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 9
    Top = 37
    Width = 337
    Height = 14
    AutoSize = False
    Caption = #1057#1087#1080#1089#1086#1082' '#1074#1086#1079#1084#1086#1078#1085#1099#1093' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 623
    Top = 35
    Width = 240
    Height = 16
    Caption = #1057#1087#1080#1089#1086#1082' '#1087#1086#1083#1091#1095#1077#1085#1085#1099#1093' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object SpeedButton1: TSpeedButton
    Left = 593
    Top = 76
    Width = 19
    Height = 18
    Cursor = crHandPoint
    Glyph.Data = {
      DE000000424DDE0000000000000076000000280000000D0000000D0000000100
      0400000000006800000000000000000000001000000010000000000000000000
      BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
      7000777777077777700077777700777770007777770607777000770000066077
      7000770666666607700077066666666070007706666666077000770000066077
      7000777777060777700077777700777770007777770777777000777777777777
      7000}
    OnClick = SpeedButton1Click
  end
  object SpeedButton2: TSpeedButton
    Left = 593
    Top = 115
    Width = 19
    Height = 18
    Cursor = crHandPoint
    Glyph.Data = {
      DE000000424DDE0000000000000076000000280000000D0000000D0000000100
      0400000000006800000000000000000000001000000010000000000000000000
      BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
      7000777777077777700077777007777770007777060777777000777066000007
      7000770666666607700070666666660770007706666666077000777066000007
      7000777706077777700077777007777770007777770777777000777777777777
      7000}
    OnClick = SpeedButton2Click
  end
  object SpeedButton4: TSpeedButton
    Left = 402
    Top = 416
    Width = 150
    Height = 34
    Hint = #1055#1077#1095#1072#1090#1100' '#1086#1087#1080#1089#1080' '#1076#1077#1083#1072
    Caption = #1054#1087#1080#1089#1100' '#1076#1077#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    NumGlyphs = 2
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    OnClick = SpeedButton4Click
  end
  object SpeedButton3: TSpeedButton
    Left = 402
    Top = 367
    Width = 150
    Height = 34
    Hint = #1055#1077#1095#1072#1090#1100' '#1088#1072#1089#1087#1080#1089#1082#1080
    Caption = #1056#1072#1089#1087#1080#1089#1082#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    OnClick = SpeedButton3Click
  end
  object Label4: TLabel
    Left = 647
    Top = 362
    Width = 90
    Height = 16
    Caption = #1069#1082#1079#1072#1084'. '#1083#1080#1089#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object PleaSpdBtn: TSpeedButton
    Left = 176
    Top = 367
    Width = 150
    Height = 34
    Hint = #1055#1077#1095#1072#1090#1100' '#1079#1072#1103#1074#1083#1077#1085#1080#1103
    Caption = #1047#1072#1103#1074#1083#1077#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    OnClick = PleaSpdBtnClick
  end
  object FIOLbl: TLabel
    Left = 8
    Top = 8
    Width = 46
    Height = 16
    Caption = 'FIOLbl'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object BitBtn2: TBitBtn
    Left = 7
    Top = 367
    Width = 151
    Height = 34
    Cursor = crHandPoint
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1089#1087#1080#1089#1086#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Glyph.Data = {
      66010000424D6601000000000000760000002800000014000000140000000100
      040000000000F000000000000000000000001000000010000000000000000000
      8000008000000080800080000000800080008080000080808000C0C0C0000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
      8888888800008888888888888888888800008888777777778888888800008800
      00000000788888880000880BFFFBFFF0777777880000880F444444F000000078
      0000880FFBFFFBF0FBFFF0780000880F444444F04444F0780000880BFFFBFFF0
      FFFBF0780000880F444444F04444F0780000880FFBFFFBF0FBFFF0780000880F
      44F000004477F0780000880BFFF0FFF0FF0007780000880F44F0FB00F70A0778
      0000880FFBF0F0FF000A00080000880000000F470AAAAA080000888888880FFB
      000A00080000888888880000770A088800008888888888888800088800008888
      88888888888888880000}
    ParentFont = False
    TabOrder = 0
    Visible = False
    OnClick = BitBtn2Click
  end
  object ListBox2: TListBox
    Left = 623
    Top = 57
    Width = 289
    Height = 293
    Color = 14936298
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemHeight = 13
    Items.Strings = (
      #1052#1077#1076#1080#1094#1080#1085#1089#1082#1072#1103' '#1089#1087#1088#1072#1074#1082#1072
      #1040#1090#1090#1077#1089#1090#1072#1090' ('#1076#1080#1087#1083#1086#1084') '#1086' '#1089#1088#1077#1076#1085#1077#1084' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1080)
    ParentFont = False
    TabOrder = 1
    OnDblClick = ListBox2DblClick
  end
  object BitBtn3: TBitBtn
    Left = 802
    Top = 416
    Width = 106
    Height = 34
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
    TabOrder = 2
    OnClick = BitBtn3Click
  end
  object ExamSht1BtBtn: TBitBtn
    Left = 647
    Top = 384
    Width = 49
    Height = 34
    Cursor = crHandPoint
    Hint = #1055#1077#1095#1072#1090#1100' '#1087#1077#1088#1074#1086#1081' '#1089#1090#1086#1088#1086#1085#1099#13#10#1101#1082#1079#1072#1084#1077#1085#1072#1094#1080#1086#1085#1085#1086#1075#1086' '#1083#1080#1089#1090#1072' '
    Caption = '1 '#1089#1090#1088
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    Spacing = 8
    TabOrder = 3
    OnClick = ExamSht1BtBtnClick
  end
  object ExamSht2BtBtn: TBitBtn
    Left = 702
    Top = 384
    Width = 42
    Height = 32
    Cursor = crHandPoint
    Hint = #1055#1077#1095#1072#1090#1100' '#1074#1090#1086#1088#1086#1081' '#1089#1090#1086#1088#1086#1085#1099#13#10#1101#1082#1079#1072#1084#1077#1085#1072#1094#1080#1086#1085#1085#1086#1075#1086' '#1083#1080#1089#1090#1072' '
    Caption = '2 '#1089#1090#1088'.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    Spacing = 8
    TabOrder = 4
    OnClick = ExamSht2BtBtnClick
  end
  object BitBtn5: TBitBtn
    Left = 8
    Top = 417
    Width = 151
    Height = 34
    Cursor = crHandPoint
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1089#1087#1080#1089#1086#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Glyph.Data = {
      42010000424D4201000000000000760000002800000011000000110000000100
      040000000000CC00000000000000000000001000000010000000000000000000
      BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
      7777700000007777777777777777700000007777777774F77777700000007777
      7777444F77777000000077777774444F777770000000700000444F44F7777000
      000070FFF444F0744F777000000070F8884FF0774F777000000070FFFFFFF077
      74F77000000070F88888F077774F7000000070FFFFFFF0777774F000000070F8
      8777F07777774000000070FFFF00007777777000000070F88707077777777000
      000070FFFF007777777770000000700000077777777770000000777777777777
      777770000000}
    ParentFont = False
    TabOrder = 5
    Visible = False
    OnClick = BitBtn5Click
  end
  object ContractBtBtn: TBitBtn
    Left = 176
    Top = 417
    Width = 150
    Height = 34
    Caption = #1044#1086#1075#1086#1074#1086#1088' 3 '#1101#1082#1079'.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -10
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = ContractBtBtnClick
  end
  object ExamShtAllBtBtn: TBitBtn
    Left = 647
    Top = 424
    Width = 97
    Height = 26
    Cursor = crHandPoint
    Hint = #1055#1077#1095#1072#1090#1100' '#1087#1077#1088#1074#1086#1081' '#1089#1090#1086#1088#1086#1085#1099#13#10#1101#1082#1079#1072#1084#1077#1085#1072#1094#1080#1086#1085#1085#1086#1075#1086' '#1083#1080#1089#1090#1072' '
    Caption = #1044#1074#1091#1089#1090#1086#1088#1086#1085#1085#1103#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    Spacing = 8
    TabOrder = 7
    OnClick = ExamShtAllBtBtnClick
  end
  object ListBox1: TListBox
    Left = 8
    Top = 57
    Width = 569
    Height = 294
    Color = 14936298
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemHeight = 13
    ParentFont = False
    TabOrder = 8
    OnDblClick = ListBox1DblClick
  end
end
