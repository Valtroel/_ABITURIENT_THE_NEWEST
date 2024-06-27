object Dop_ResultForm: TDop_ResultForm
  Left = 275
  Top = 182
  Caption = #1055#1086#1073#1077#1076#1080#1090#1077#1083#1080' '#1088#1077#1089#1087#1091#1073#1083#1080#1082#1072#1085#1089#1082#1086#1081' '#1086#1083#1080#1084#1087#1080#1072#1076#1099
  ClientHeight = 127
  ClientWidth = 508
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 508
    Height = 127
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    ExplicitWidth = 516
    ExplicitHeight = 138
    object Label1: TLabel
      Left = 26
      Top = 16
      Width = 63
      Height = 13
      Caption = #8470' '#1075#1088#1091#1087#1087#1099':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label2: TLabel
      Left = 26
      Top = 46
      Width = 35
      Height = 13
      Caption = #1060#1048#1054':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 26
      Top = 77
      Width = 57
      Height = 13
      Caption = #1055#1088#1077#1076#1084#1077#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 26
      Top = 106
      Width = 49
      Height = 13
      Caption = #1054#1094#1077#1085#1082#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 98
      Top = 106
      Width = 61
      Height = 13
      Caption = '10 '#1073#1072#1083#1083#1086#1074
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 98
      Top = 13
      Width = 52
      Height = 21
      Color = 14936298
      TabOrder = 0
      Visible = False
    end
    object LookFIO: TDBLookupComboBox
      Left = 98
      Top = 42
      Width = 247
      Height = 21
      Color = 14936298
      KeyField = 'NOMER_AB'
      ListField = 'FIO'
      ListSource = DM.DSLittle_Spisoc_GR
      TabOrder = 1
    end
    object LookPred: TDBLookupComboBox
      Left = 98
      Top = 73
      Width = 247
      Height = 21
      Color = 14936298
      KeyField = 'N_PREDMET'
      ListField = 'TEXT_PREDMET'
      ListSource = DM.DSPredmet
      TabOrder = 2
    end
    object Button1: TButton
      Left = 362
      Top = 10
      Width = 146
      Height = 27
      Cursor = crHandPoint
      Caption = #1057#1087#1080#1089#1086#1082' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1086#1074
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Visible = False
    end
    object BitBtn1: TBitBtn
      Left = 362
      Top = 68
      Width = 146
      Height = 27
      Cursor = crHandPoint
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1088#1077#1079#1091#1083#1100#1090#1072#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Spacing = 10
      TabOrder = 4
      OnClick = BitBtn1Click
    end
    object RadioGroup1: TRadioGroup
      Left = 98
      Top = 141
      Width = 247
      Height = 105
      Columns = 3
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1079#1072#1095#1077#1090
        '3'
        '4'
        '5'
        '6'
        '7'
        '8'
        '9'
        '10')
      ParentFont = False
      TabOrder = 5
      Visible = False
    end
  end
end
