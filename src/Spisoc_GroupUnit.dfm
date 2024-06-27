object Spisoc_GroupForm: TSpisoc_GroupForm
  Left = 66
  Top = 131
  Caption = #1057#1087#1080#1089#1082#1080' '#1075#1088#1091#1087#1087
  ClientHeight = 501
  ClientWidth = 767
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
  object Button1: TButton
    Left = 410
    Top = 33
    Width = 60
    Height = 20
    Caption = #1044#1085#1077#1074#1085#1086#1077
    TabOrder = 0
    OnClick = Button1Click
  end
  object R1: TRichEdit
    Left = 39
    Top = 72
    Width = 547
    Height = 312
    ParentFont = False
    TabOrder = 1
    Zoom = 100
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 143
    Top = 26
    Width = 118
    Height = 21
    KeyField = 'N_PRIVILEGE_EXAM'
    ListField = 'TEXT_PRIVILEGE_EXAM'
    TabOrder = 2
  end
end
