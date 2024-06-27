object AbiturLogDlg: TAbiturLogDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #1057#1086#1079#1076#1072#1085#1080#1077' '#1078#1091#1088#1085#1072#1083#1072' '#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1080
  ClientHeight = 208
  ClientWidth = 249
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 233
    Height = 161
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 32
    Top = 24
    Width = 118
    Height = 16
    Caption = #1044#1072#1090#1072' '#1076#1083#1103' '#1086#1090#1095#1105#1090#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 32
    Top = 73
    Width = 186
    Height = 56
    AutoSize = False
    Caption = #1042#1053#1048#1052#1040#1053#1048#1045'! '#1057#1090#1072#1088#1099#1081' '#1086#1090#1095#1105#1090'  '#1079#1072' '#1074#1099#1073#1088#1072#1085#1085#1099#1081' '#1076#1077#1085#1100' '#1073#1091#1076#1077#1090' '#1087#1077#1088#1077#1087#1080#1089#1072#1085'!'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    WordWrap = True
  end
  object OKBtn: TButton
    Left = 166
    Top = 175
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 75
    Top = 175
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
    OnClick = CancelBtnClick
  end
  object DateTimePicker1: TDateTimePicker
    Left = 32
    Top = 46
    Width = 186
    Height = 21
    Date = 44736.652163634260000000
    Time = 44736.652163634260000000
    TabOrder = 2
  end
end
