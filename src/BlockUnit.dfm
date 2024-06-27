object BlockForm: TBlockForm
  Left = 348
  Top = 344
  Caption = #1054#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1087#1088#1072#1074' '#1076#1086#1089#1090#1091#1087#1072' '#1082' '#1076#1072#1085#1085#1099#1084
  ClientHeight = 209
  ClientWidth = 362
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 362
    Height = 154
    Align = alClient
    BevelInner = bvSpace
    BevelOuter = bvLowered
    TabOrder = 0
    object PageControl1: TPageControl
      Left = 2
      Top = 2
      Width = 358
      Height = 150
      ActivePage = TabSheet1
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MultiLine = True
      ParentFont = False
      Style = tsFlatButtons
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = #1048#1079#1084#1077#1085#1077#1085#1080#1077' '#1086#1089#1085#1086#1074#1085#1099#1093' '#1076#1072#1085#1085#1099#1093
        object RadioGroup1: TRadioGroup
          Left = 0
          Top = 0
          Width = 350
          Height = 119
          Align = alClient
          Caption = #1048#1079#1084#1077#1085#1077#1085#1080#1077' '#1086#1089#1085#1086#1074#1085#1099#1093' '#1076#1072#1085#1085#1099#1093
          Columns = 2
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          Items.Strings = (
            #1057#1055#1060' '#1057#1048#1080#1045
            #1057#1055#1060' '#1052#1042#1057
            #1060#1072#1082#1091#1083#1100#1090#1077#1090' '#1054#1060#1050#1080#1058
            #1048#1085#1089#1090#1080#1090#1091#1090' '#1090#1091#1088#1080#1079#1084#1072)
          ParentFont = False
          TabOrder = 0
        end
      end
      object TabSheet2: TTabSheet
        Caption = #1055#1077#1088#1077#1087#1086#1076#1072#1095#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
        ImageIndex = 1
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object RadioGroup2: TRadioGroup
          Left = 0
          Top = 0
          Width = 350
          Height = 119
          Align = alClient
          Caption = #1055#1077#1088#1077#1087#1086#1076#1072#1095#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
          Columns = 2
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          Items.Strings = (
            #1057#1055#1060' '#1057#1048#1080#1045
            #1057#1055#1060' '#1052#1042#1057
            #1060#1072#1082#1091#1083#1100#1090#1077#1090' '#1054#1060#1050#1080#1058
            #1048#1085#1089#1090#1080#1090#1091#1090' '#1090#1091#1088#1080#1079#1084#1072)
          ParentFont = False
          TabOrder = 0
        end
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 154
    Width = 362
    Height = 55
    Align = alBottom
    BevelInner = bvSpace
    BevelOuter = bvLowered
    TabOrder = 1
    object BitBtn1: TBitBtn
      Left = 40
      Top = 16
      Width = 95
      Height = 25
      Caption = #1056#1072#1079#1088#1077#1096#1080#1090#1100
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
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 240
      Top = 16
      Width = 95
      Height = 25
      Caption = #1047#1072#1087#1088#1077#1090#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        42010000424D4201000000000000760000002800000011000000110000000100
        040000000000CC00000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777700000007777777777777777700000007799777774F77997700000007779
        9777444F997770000000777799744449977770000000700009944F99F7777000
        000070FFF499F9944F777000000070F8884999774F777000000070FFFFFF9077
        74F77000000070F888899977774F7000000070FFFF99F9977774F000000070F8
        8997F09977774000000070FF9900007997777000000070F99707077799777000
        00007099FF007777799770000000700000077777777770000000777777777777
        777770000000}
      ParentFont = False
      TabOrder = 1
      OnClick = BitBtn2Click
    end
  end
end
