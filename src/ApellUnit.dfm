object ApellForm: TApellForm
  Left = 321
  Top = 265
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #1040#1087#1077#1083#1083#1103#1094#1080#1103
  ClientHeight = 107
  ClientWidth = 450
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 450
    Height = 107
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object Label1: TLabel
      Left = 32
      Top = 10
      Width = 39
      Height = 18
      Caption = #1060#1048#1054':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 5
      Top = 41
      Width = 68
      Height = 18
      Caption = #1055#1088#1077#1076#1084#1077#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 15
      Top = 78
      Width = 58
      Height = 18
      Caption = #1054#1094#1077#1085#1082#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object LookF: TDBLookupComboBox
      Left = 78
      Top = 7
      Width = 364
      Height = 21
      KeyField = 'NOMER_AB'
      ListField = 'FAM;NAME;OTCH'
      ListSource = DM.DSUndo_Abit
      TabOrder = 0
    end
    object LookP: TDBLookupComboBox
      Left = 78
      Top = 42
      Width = 363
      Height = 21
      KeyField = 'N_PREDMET'
      ListField = 'TEXT_PREDMET'
      ListSource = DM.DSPredmet
      TabOrder = 1
    end
    object LookB: TDBLookupComboBox
      Left = 78
      Top = 78
      Width = 137
      Height = 21
      KeyField = 'NOM_BALL'
      ListField = 'BALL'
      ListSource = DM.DSBall
      TabOrder = 2
    end
    object BitBtn1: TBitBtn
      Left = 300
      Top = 69
      Width = 142
      Height = 27
      Cursor = crHandPoint
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1086#1094#1077#1085#1082#1091
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        66010000424D6601000000000000760000002800000014000000140000000100
        040000000000F000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0050FFFFFFFFFF
        FFFFFFFF000050F000FFF00000FFF0FF000050FFFFFFFFFFFFFF000F0000500F
        00000FFFFFF2200F000050FFFFFFFFFFFF2222FF000050FFF000000FF2222FFF
        000050FF000000000222FFFF000050F00EEEEEE0022FFFFF00005500EEEEEEEE
        00FF00FF0000500E0E0E000EE00FFFFF0000500E000E000EE00FFFFF0000500E
        0E0E00EEE00FFFFF0000500EE0EE000EE00FFFFF0000500EEEEEEEEEE00FFFFF
        00005500EEEEEEEE00000000000055500EEEEEE0055555550000555500000000
        5555555500005555500000055555555500005555555555555555555500005555
        55555555555555550000}
      ParentFont = False
      Spacing = 10
      TabOrder = 3
      OnClick = BitBtn1Click
    end
  end
end
