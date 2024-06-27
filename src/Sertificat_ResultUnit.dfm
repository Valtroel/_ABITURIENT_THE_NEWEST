object Sertificat_ResultForm: TSertificat_ResultForm
  Left = 246
  Top = 74
  Width = 543
  Height = 250
  BorderIcons = [biSystemMenu]
  Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1094#1077#1085#1090#1088#1072#1083#1080#1079#1086#1074#1072#1085#1085#1086#1075#1086' '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 535
    Height = 223
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
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
    end
    object Label2: TLabel
      Left = 26
      Top = 45
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
      Top = 74
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
      Top = 191
      Width = 49
      Height = 13
      Caption = #1054#1094#1077#1085#1082#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label5: TLabel
      Left = 98
      Top = 191
      Width = 39
      Height = 13
      Caption = 'Label5'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label6: TLabel
      Left = 26
      Top = 104
      Width = 76
      Height = 13
      Caption = #1057#1077#1088#1090#1080#1092#1080#1082#1072#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label7: TLabel
      Left = 161
      Top = 104
      Width = 39
      Height = 13
      Caption = 'Label7'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label8: TLabel
      Left = 26
      Top = 162
      Width = 124
      Height = 13
      Caption = #1041#1072#1083#1083#1099' '#1089#1077#1088#1090#1080#1092#1080#1082#1072#1090#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label9: TLabel
      Left = 161
      Top = 162
      Width = 39
      Height = 13
      Caption = 'Label9'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label10: TLabel
      Left = 26
      Top = 133
      Width = 57
      Height = 13
      Caption = #1055#1088#1077#1076#1084#1077#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label11: TLabel
      Left = 161
      Top = 133
      Width = 46
      Height = 13
      Caption = 'Label11'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Edit1: TEdit
      Left = 98
      Top = 12
      Width = 52
      Height = 21
      Color = 14936298
      TabOrder = 0
      OnChange = Edit1Change
    end
    object LookFIO: TDBLookupComboBox
      Left = 98
      Top = 41
      Width = 247
      Height = 21
      Color = 14936298
      Enabled = False
      KeyField = 'NOMER_AB'
      ListField = 'FIO'
      ListSource = DM.DSQSertificat_Res
      TabOrder = 1
      OnCloseUp = LookFIOCloseUp
    end
    object LookPred: TDBLookupComboBox
      Left = 98
      Top = 70
      Width = 247
      Height = 21
      Color = 14936298
      Enabled = False
      KeyField = 'N_PREDMET'
      ListField = 'TEXT_PREDMET'
      ListSource = DM.DSPredmet
      TabOrder = 2
      OnCloseUp = LookFIOCloseUp
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
      OnClick = Button1Click
    end
    object BitBtn1: TBitBtn
      Left = 362
      Top = 154
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
      TabOrder = 4
      Visible = False
      OnClick = BitBtn1Click
      Spacing = 10
    end
    object Button2: TButton
      Left = 362
      Top = 68
      Width = 146
      Height = 27
      Caption = #1053#1072#1081#1090#1080' '#1089#1077#1088#1090#1080#1092#1080#1082#1072#1090
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = Button2Click
    end
  end
end
