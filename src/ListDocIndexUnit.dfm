object ListDocIndexForm: TListDocIndexForm
  Left = 0
  Top = 0
  ClientHeight = 148
  ClientWidth = 336
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 53
    Width = 88
    Height = 13
    Caption = #1044#1072#1090#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1072':'
  end
  object Label2: TLabel
    Left = 176
    Top = 53
    Width = 93
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1076#1086#1082#1091#1084#1077#1085#1090#1072':'
  end
  object Text_doc: TLabel
    Left = 32
    Top = 8
    Width = 265
    Height = 13
    Caption = 'Text_doc'
  end
  object IndexEdit: TEdit
    Left = 176
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 232
    Top = 115
    Width = 75
    Height = 25
    Kind = bkOK
    NumGlyphs = 2
    TabOrder = 1
    OnClick = BitBtn1Click
  end
  object DateEdit: TMaskEdit
    Left = 32
    Top = 72
    Width = 120
    Height = 21
    EditMask = '!99/99/0000;1;_'
    MaxLength = 10
    TabOrder = 2
    Text = '  .  .    '
    OnClick = DateEditClick
  end
end
