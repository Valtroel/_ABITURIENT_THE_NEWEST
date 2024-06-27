object EducationForm: TEducationForm
  Left = 0
  Top = 0
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1086#1073' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1080
  ClientHeight = 149
  ClientWidth = 523
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
    Left = 8
    Top = 8
    Width = 133
    Height = 13
    Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1086#1073' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1080
  end
  object Label14: TLabel
    Left = 59
    Top = 65
    Width = 71
    Height = 13
    Caption = #1043#1076#1077' '#1079#1072#1082#1086#1085#1095#1080#1083':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label25: TLabel
    Left = 441
    Top = 8
    Width = 77
    Height = 13
    Caption = #1043#1086#1076' '#1086#1082#1086#1085#1095#1072#1085#1080#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label23: TLabel
    Left = 315
    Top = 8
    Width = 120
    Height = 13
    Caption = #8470' '#1072#1090#1090#1077#1089#1090#1072#1090#1072' ('#1076#1080#1087#1083#1086#1084#1072'):'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label21: TLabel
    Left = 159
    Top = 8
    Width = 118
    Height = 13
    Caption = #1059#1095#1077#1073#1085#1086#1077' '#1079#1072#1074#1077#1076#1077#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 8
    Top = 27
    Width = 145
    Height = 21
    KeyField = 'N_EDU_DOC'
    ListField = 'EDU_DOC'
    TabOrder = 0
  end
  object WhereEduMiddleDBEdt: TDBEdit
    Left = 136
    Top = 62
    Width = 362
    Height = 21
    HelpContext = 10
    Color = 14936298
    DataField = 'WHERE_EDU'
    TabOrder = 1
  end
  object WhenEduMiddleDBEdt: TDBEdit
    Left = 441
    Top = 27
    Width = 57
    Height = 21
    Color = 14936298
    DataField = 'WHEN_EDU'
    TabOrder = 2
  end
  object NomAttestDBEdt: TDBEdit
    Left = 315
    Top = 27
    Width = 110
    Height = 21
    Color = 14936298
    DataField = 'NOM_DOC'
    TabOrder = 3
  end
  object NameEduMiddleDBEdt: TDBEdit
    Left = 159
    Top = 27
    Width = 150
    Height = 21
    Color = 14936298
    DataField = 'NAME_EDU'
    TabOrder = 4
  end
  object Panel2: TPanel
    Left = 0
    Top = 95
    Width = 523
    Height = 54
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 5
    object BitBtn1: TBitBtn
      Left = 284
      Top = 6
      Width = 114
      Height = 35
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1089#1077#1088#1090#1080#1092#1080#1082#1072#1090
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        66010000424D6601000000000000760000002800000014000000140000000100
        040000000000F000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
        5555555500005555555555555555555500005555000000000000005500005550
        CCC8CC8888CCC05500005550CCC8CC8888CCC05500005550CCC8CC8888CCC055
        00005550CCC8888888CCC05500005550CCCCCCCCCCCCC05500005550CC444444
        444CC05500005550C4FFFFFFFFF4C05500005550C4FFFFFFFFF4C05500005550
        C4FFFFFFFFF4C05500005550C4FFFFFFFFF4C05500005550C4FFFFFFFFF4C055
        0000555084FFFFFFFFF4005500005550C4FFFFFFFFF4C0550000555000000000
        0000005500005555555555555555555500005555555555555555555500005555
        55555555555555550000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      Spacing = 10
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 404
      Top = 6
      Width = 114
      Height = 35
      Hint = #1047#1072#1082#1088#1099#1090#1100' '#1092#1086#1088#1084#1091
      Caption = #1042#1099#1093#1086#1076
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = bkClose
      NumGlyphs = 2
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      Spacing = 10
      TabOrder = 1
    end
    object BitBtn3: TBitBtn
      Left = 166
      Top = 6
      Width = 112
      Height = 35
      Hint = #1059#1076#1072#1083#1080#1090#1100' '#1089#1077#1088#1090#1080#1092#1080#1082#1072#1090
      Caption = #1059#1076#1072#1083#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = bkAbort
      NumGlyphs = 2
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      Spacing = 10
      TabOrder = 2
      OnClick = BitBtn3Click
    end
  end
end
