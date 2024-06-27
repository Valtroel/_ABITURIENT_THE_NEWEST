object DualListDlg: TDualListDlg
  Left = 0
  Top = 0
  Caption = 'DualListDlg'
  ClientHeight = 281
  ClientWidth = 375
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object SrcLabel: TLabel
    Left = 8
    Top = 18
    Width = 145
    Height = 16
    AutoSize = False
    Caption = 'Source List:'
  end
  object DstLabel: TLabel
    Left = 222
    Top = 18
    Width = 145
    Height = 16
    AutoSize = False
    Caption = 'Destination List:'
  end
  object IncludeBtn: TSpeedButton
    Left = 176
    Top = 48
    Width = 24
    Height = 24
    Caption = '>'
    OnClick = IncludeBtnClick
  end
  object IncAllBtn: TSpeedButton
    Left = 176
    Top = 78
    Width = 24
    Height = 24
    Caption = '>>'
    OnClick = IncAllBtnClick
  end
  object ExcludeBtn: TSpeedButton
    Left = 176
    Top = 108
    Width = 24
    Height = 24
    Caption = '<'
    Enabled = False
    OnClick = ExcludeBtnClick
  end
  object ExAllBtn: TSpeedButton
    Left = 176
    Top = 138
    Width = 24
    Height = 24
    Caption = '<<'
    Enabled = False
    OnClick = ExAllBtnClick
  end
  object SrcList: TListBox
    Left = 8
    Top = 40
    Width = 144
    Height = 185
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      'Item1'
      'Item2'
      'Item3'
      'Item4'
      'Item5')
    MultiSelect = True
    ParentFont = False
    ScrollWidth = 1
    Sorted = True
    TabOrder = 0
    OnDblClick = SrcListDblClick
  end
  object DstList: TListBox
    Left = 223
    Top = 40
    Width = 144
    Height = 185
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 13
    MultiSelect = True
    ParentFont = False
    TabOrder = 1
    OnDblClick = DstListDblClick
  end
  object OKBtn: TButton
    Left = 92
    Top = 238
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 2
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 176
    Top = 238
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object HelpBtn: TButton
    Left = 268
    Top = 238
    Width = 75
    Height = 25
    Caption = 'Help'
    TabOrder = 4
  end
end
