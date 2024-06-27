object Dlg_ProtokolForm: TDlg_ProtokolForm
  Left = 490
  Top = 330
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #1060#1086#1088#1084#1080#1088#1086#1074#1072#1085#1080#1077' '#1087#1088#1086#1090#1086#1082#1086#1083#1072
  ClientHeight = 128
  ClientWidth = 233
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
    Width = 233
    Height = 128
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    OnDblClick = Panel1DblClick
    object Label1: TLabel
      Left = 26
      Top = 18
      Width = 83
      Height = 13
      Caption = #8470' '#1087#1088#1086#1090#1086#1082#1086#1083#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 26
      Top = 58
      Width = 35
      Height = 13
      Caption = #1044#1072#1090#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 148
      Top = 14
      Width = 40
      Height = 21
      TabOrder = 0
    end
    object BitBtn1: TBitBtn
      Left = 41
      Top = 101
      Width = 154
      Height = 27
      Cursor = crHandPoint
      Hint = #1060#1086#1088#1084#1080#1088#1086#1074#1072#1085#1080#1077' '#1087#1088#1086#1090#1086#1082#1086#1083#1072' '#1074' Excel'
      Caption = #1057#1086#1079#1076#1072#1090#1100' '#1087#1088#1086#1090#1086#1082#1086#1083
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        06020000424D0602000000000000760000002800000028000000140000000100
        0400000000009001000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333FFFFFFFFF333333333300000000033333333333888888
        888F33333333330BFBFBFB03333FFFFFFF8F3FFFFF8F33000000000F88888F03
        33888888888F8888838F307F7F7F7F0BFBFBFB0338F33333338F333FFF8F30F7
        F7F7F70F77888F0338F33333338FFF88838F307F7F7F74444BFBFB0338F33333
        38888F3FFF8F30F7F7F7F7C447888F0338F3333333888F88838F307F7F7F744C
        4BFBFB0338F3333338888F333F8F30F7F7F7444F4FFF880338F33333888F8333
        8883307F7F74440BFBFB803338F33338888FFFFF883330F7F744470000000333
        38F33388838888888333307F7F747F7F0333333338F3333833338F33333330F7
        F7F7F7F70333333338F3333333338F333333307F7F7F7F7F0333333338F33FFF
        FFF38F33333330F7444444F703333333383F888888FF833333333300ECCCC400
        33333333338838888888333333333333ECCCC433333333333333388888333333
        333333333EEEE333333333333333333333333333333333333333333333333333
        33333333333333333333}
      NumGlyphs = 2
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      Spacing = 10
      TabOrder = 1
      OnClick = BitBtn1Click
    end
    object DateTimePicker1: TDateTimePicker
      Left = 67
      Top = 56
      Width = 121
      Height = 21
      Date = 43234.499958217600000000
      Time = 43234.499958217600000000
      TabOrder = 2
      OnChange = DateTimePicker1Change
    end
  end
end
