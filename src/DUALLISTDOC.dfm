object DualListDlgDoc: TDualListDlgDoc
  Left = 250
  Top = 108
  BorderStyle = bsDialog
  Caption = 'Choices Dialog'
  ClientHeight = 561
  ClientWidth = 955
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object SrcLabel: TLabel
    Left = 8
    Top = 8
    Width = 145
    Height = 16
    AutoSize = False
    Caption = 'Source List:'
  end
  object DstLabel: TLabel
    Left = 544
    Top = 8
    Width = 145
    Height = 16
    AutoSize = False
    Caption = 'Destination List:'
  end
  object IncludeBtn: TSpeedButton
    Left = 514
    Top = 72
    Width = 24
    Height = 24
    Caption = '>'
    OnClick = IncludeBtnClick
  end
  object IncAllBtn: TSpeedButton
    Left = 514
    Top = 104
    Width = 24
    Height = 24
    Caption = '>>'
    Enabled = False
    Visible = False
    OnClick = IncAllBtnClick
  end
  object ExcludeBtn: TSpeedButton
    Left = 514
    Top = 136
    Width = 24
    Height = 24
    Caption = '<'
    OnClick = ExcludeBtnClick
  end
  object ExAllBtn: TSpeedButton
    Left = 514
    Top = 168
    Width = 24
    Height = 24
    Caption = '<<'
    Enabled = False
    Visible = False
    OnClick = ExcAllBtnClick
  end
  object OKBtn: TButton
    Left = 421
    Top = 508
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 2
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 501
    Top = 508
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object HelpBtn: TButton
    Left = 581
    Top = 508
    Width = 75
    Height = 25
    Caption = 'Help'
    TabOrder = 4
  end
  object SrcList: TListBox
    Left = 8
    Top = 24
    Width = 500
    Height = 478
    ItemHeight = 13
    Items.Strings = (
      '')
    MultiSelect = True
    Sorted = True
    TabOrder = 0
    OnDblClick = SrcListDblClick
  end
  object DstList: TListBox
    Left = 544
    Top = 24
    Width = 393
    Height = 478
    ItemHeight = 13
    MultiSelect = True
    TabOrder = 1
    OnDblClick = DstListDblClick
  end
end
