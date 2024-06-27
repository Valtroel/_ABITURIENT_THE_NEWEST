object LetterDualListDlg: TLetterDualListDlg
  Left = 250
  Top = 108
  BorderStyle = bsDialog
  Caption = #1042#1099#1073#1086#1088' '#1089#1090#1091#1076#1077#1085#1090#1086#1074' '#1076#1083#1103' '#1087#1077#1095#1072#1090#1080' '#1082#1086#1085#1074#1077#1088#1090#1086#1074
  ClientHeight = 511
  ClientWidth = 794
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object SrcLabel: TLabel
    Left = 8
    Top = 8
    Width = 360
    Height = 16
    AutoSize = False
    Caption = 'Source List:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object DstLabel: TLabel
    Left = 426
    Top = 8
    Width = 360
    Height = 16
    AutoSize = False
    Caption = 'Destination List:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object IncludeBtn: TSpeedButton
    Left = 372
    Top = 30
    Width = 50
    Height = 40
    Caption = '>'
    OnClick = IncludeBtnClick
  end
  object IncAllBtn: TSpeedButton
    Left = 372
    Top = 70
    Width = 50
    Height = 40
    Caption = '>>'
    OnClick = IncAllBtnClick
  end
  object ExcludeBtn: TSpeedButton
    Left = 372
    Top = 120
    Width = 50
    Height = 40
    Caption = '<'
    Enabled = False
    OnClick = ExcludeBtnClick
  end
  object ExAllBtn: TSpeedButton
    Left = 372
    Top = 160
    Width = 50
    Height = 40
    Caption = '<<'
    Enabled = False
    OnClick = ExcAllBtnClick
  end
  object DstListI: TListBox
    Left = 458
    Top = 375
    Width = 121
    Height = 40
    ItemHeight = 13
    MultiSelect = True
    TabOrder = 4
  end
  object SrcListI: TListBox
    Left = 56
    Top = 375
    Width = 121
    Height = 40
    ItemHeight = 13
    Items.Strings = (
      'Item1'
      'Item2'
      'Item3'
      'Item4'
      'Item5')
    MultiSelect = True
    TabOrder = 5
  end
  object OKBtn: TButton
    Left = 520
    Top = 465
    Width = 120
    Height = 40
    Caption = #1055#1077#1095#1072#1090#1100
    Default = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = []
    ModalResult = 1
    ParentFont = False
    TabOrder = 2
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 650
    Top = 465
    Width = 120
    Height = 40
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = []
    ModalResult = 2
    ParentFont = False
    TabOrder = 3
  end
  object SrcList: TListBox
    Left = 8
    Top = 24
    Width = 360
    Height = 433
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ItemHeight = 17
    Items.Strings = (
      'Item1'
      'Item2'
      'Item3'
      'Item4'
      'Item5')
    MultiSelect = True
    ParentFont = False
    Sorted = True
    TabOrder = 0
  end
  object DstList: TListBox
    Left = 426
    Top = 24
    Width = 360
    Height = 433
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ItemHeight = 17
    MultiSelect = True
    ParentFont = False
    TabOrder = 1
  end
  object DBImage1: TDBImage
    Left = 374
    Top = 328
    Width = 105
    Height = 105
    DataField = 'SIGNATURE'
    DataSource = DM.Selection_CommitteeDS
    TabOrder = 6
    Visible = False
  end
end
