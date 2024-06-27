object SertificatForm: TSertificatForm
  Left = 355
  Top = 249
  BorderIcons = []
  Caption = #1057#1077#1088#1090#1080#1092#1080#1082#1072#1090' '#1094#1077#1085#1090#1088#1072#1083#1080#1079#1086#1074#1072#1085#1085#1086#1075#1086' '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1103
  ClientHeight = 275
  ClientWidth = 550
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 221
    Width = 550
    Height = 54
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object BitBtn1: TBitBtn
      Left = 292
      Top = 9
      Width = 125
      Height = 35
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1089#1077#1088#1090#1080#1092#1080#1082#1072#1090
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
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
      Left = 420
      Top = 9
      Width = 125
      Height = 35
      Hint = #1047#1072#1082#1088#1099#1090#1100' '#1092#1086#1088#1084#1091
      Caption = #1042#1099#1093#1086#1076
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
      Kind = bkClose
      NumGlyphs = 2
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      Spacing = 10
      TabOrder = 2
      OnClick = BitBtn2Click
    end
    object DBNavigator1: TDBNavigator
      Left = 4
      Top = 15
      Width = 156
      Height = 25
      DataSource = DM.DSSertificat
      VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbCancel]
      Hints.Strings = (
        #1055#1077#1088#1074#1072#1103' '#1079#1072#1087#1080#1089#1100
        #1055#1088#1077#1076#1099#1076#1091#1097#1072#1103' '#1079#1072#1087#1080#1089#1100
        #1057#1083#1077#1076#1091#1102#1097#1072#1102' '#1079#1072#1087#1080#1089#1100
        #1055#1086#1089#1083#1077#1076#1085#1103#1103' '#1079#1072#1087#1080#1089#1100
        #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1077#1088#1090#1080#1092#1080#1082#1072#1090
        ''
        ''
        ''
        #1054#1090#1084#1077#1085#1080#1090#1100' '#1076#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1089#1077#1088#1090#1080#1092#1080#1082#1072#1090#1072)
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = DBNavigator1Click
    end
    object BitBtn3: TBitBtn
      Left = 164
      Top = 9
      Width = 125
      Height = 35
      Hint = #1059#1076#1072#1083#1080#1090#1100' '#1089#1077#1088#1090#1080#1092#1080#1082#1072#1090
      Caption = #1059#1076#1072#1083#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
      Kind = bkAbort
      NumGlyphs = 2
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      Spacing = 10
      TabOrder = 3
      OnClick = BitBtn3Click
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 550
    Height = 221
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 20
      Top = 112
      Width = 59
      Height = 20
      Caption = #1087#1088#1077#1076#1084#1077#1090#1091' :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 192
      Top = 12
      Width = 43
      Height = 20
      Caption = #1057#1077#1088#1080#1103' :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 345
      Top = 12
      Width = 19
      Height = 20
      Caption = #8470' :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 33
      Top = 138
      Width = 123
      Height = 20
      Caption = #1080' '#1085#1072#1073#1088#1072#1083' ('#1083#1072') '#1073#1072#1083#1083#1099' :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 25
      Top = 165
      Width = 131
      Height = 20
      Caption = #1087#1088#1077#1076#1098#1103#1074#1083#1077#1085' '#1076#1086#1082#1091#1084#1077#1085#1090' :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 20
      Top = 12
      Width = 143
      Height = 24
      Caption = #1057#1045#1056#1058#1048#1060#1048#1050#1040#1058
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 20
      Top = 32
      Width = 105
      Height = 20
      Caption = #1091#1076#1086#1089#1090#1086#1074#1077#1088#1103#1077#1090', '#1095#1090#1086' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 220
      Top = 43
      Width = 70
      Height = 18
      Caption = #1060#1072#1084#1080#1083#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = False
    end
    object Label10: TLabel
      Left = 220
      Top = 64
      Width = 31
      Height = 18
      Caption = #1048#1084#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label11: TLabel
      Left = 220
      Top = 85
      Width = 68
      Height = 18
      Caption = #1054#1090#1095#1077#1089#1090#1074#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label12: TLabel
      Left = 20
      Top = 85
      Width = 169
      Height = 20
      Caption = #1087#1088#1086#1096#1077#1083' ('#1083#1072') '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1087#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 380
      Top = 112
      Width = 33
      Height = 20
      Caption = #1103#1079#1099#1082' :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object Label13: TLabel
      Left = 200
      Top = 138
      Width = 116
      Height = 20
      Caption = #1087#1086#1083#1091#1095#1077#1085#1085#1072#1103' '#1086#1094#1077#1085#1082#1072' :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object Label14: TLabel
      Left = 320
      Top = 140
      Width = 52
      Height = 18
      Caption = #1086#1094#1077#1085#1082#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'Segoe UI Variable Text Semiligh'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SpeedButton1: TSpeedButton
      Left = 464
      Top = 48
      Width = 23
      Height = 22
      Visible = False
      OnClick = SpeedButton1Click
    end
    object Label15: TLabel
      Left = 71
      Top = 191
      Width = 85
      Height = 20
      Caption = #1043#1086#1076' '#1089#1076#1072#1095#1080' '#1062#1058' :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object DBLookupComboBox1: TDBLookupComboBox
      Left = 85
      Top = 111
      Width = 272
      Height = 25
      KeyField = 'N_PREDMET'
      ListField = 'TEXT_PREDMET'
      ListSource = DM.DSPredmet
      TabOrder = 2
      OnCloseUp = DBLookupComboBox1CloseUp
      OnExit = DBLookupComboBox1CloseUp
    end
    object Edit1: TEdit
      Left = 240
      Top = 10
      Width = 90
      Height = 25
      TabOrder = 0
      OnExit = Edit1Exit
    end
    object Edit2: TEdit
      Left = 369
      Top = 10
      Width = 121
      Height = 25
      TabOrder = 1
    end
    object MaskEdit1: TMaskEdit
      Left = 160
      Top = 137
      Width = 32
      Height = 25
      EditMask = '!999;1;_'
      MaxLength = 3
      TabOrder = 4
      Text = '   '
      OnExit = MaskEdit1Exit
    end
    object Edit3: TEdit
      Left = 160
      Top = 164
      Width = 385
      Height = 25
      TabOrder = 5
    end
    object ComboBox1: TComboBox
      Left = 424
      Top = 111
      Width = 121
      Height = 25
      Style = csDropDownList
      TabOrder = 3
      Visible = False
      Items.Strings = (
        #1056#1091#1089#1089#1082#1080#1081
        #1041#1077#1083#1086#1088#1091#1089#1089#1082#1080#1081)
    end
    object Edit4: TEdit
      Left = 160
      Top = 191
      Width = 81
      Height = 25
      ParentShowHint = False
      ShowHint = False
      TabOrder = 6
      Text = '2022'
    end
    object UpDown1: TUpDown
      Left = 241
      Top = 191
      Width = 17
      Height = 25
      Associate = Edit4
      Min = 2021
      Max = 2022
      Position = 2022
      TabOrder = 7
      Thousands = False
    end
  end
  object ActionList1: TActionList
    Left = 496
    Top = 48
    object Action1: TAction
      Caption = 'Action1'
      ShortCut = 45
      OnExecute = SpeedButton1Click
    end
  end
end
