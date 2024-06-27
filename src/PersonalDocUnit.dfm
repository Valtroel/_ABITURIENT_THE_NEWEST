object PersonalDocFrm: TPersonalDocFrm
  Left = 0
  Top = 0
  Caption = #1051#1080#1095#1085#1086#1077' '#1076#1077#1083#1086
  ClientHeight = 120
  ClientWidth = 565
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 18
    Width = 117
    Height = 16
    Caption = #1060#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 200
    Top = 18
    Width = 198
    Height = 16
    Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1080':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object VidEduCmbBx: TComboBox
    Left = 16
    Top = 40
    Width = 145
    Height = 21
    TabOrder = 0
    Items.Strings = (
      #1076#1085#1077#1074#1085#1072#1103
      #1079#1072#1086#1095#1085#1072#1103)
  end
  object SpecializCmbBx: TComboBox
    Left = 200
    Top = 40
    Width = 345
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 470
    Top = 80
    Width = 75
    Height = 25
    Caption = #1055#1077#1095#1072#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
  object frxRichObject1: TfrxRichObject
    Left = 88
    Top = 80
  end
end
