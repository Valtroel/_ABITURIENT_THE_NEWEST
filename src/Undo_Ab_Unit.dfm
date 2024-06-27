object Undo_Ab_Form: TUndo_Ab_Form
  Left = 191
  Top = 187
  Caption = #1042#1086#1089#1089#1090#1072#1085#1086#1074#1083#1077#1085#1080#1077' '#1074' '#1089#1087#1080#1089#1086#1082' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1072
  ClientHeight = 387
  ClientWidth = 642
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 332
    Width = 642
    Height = 55
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object BitBtn2: TBitBtn
      Left = 17
      Top = 15
      Width = 133
      Height = 34
      Cursor = crHandPoint
      Caption = #1042#1086#1089#1089#1090#1072#1085#1086#1074#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        96010000424D9601000000000000760000002800000018000000180000000100
        0400000000002001000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333888888888888888333333330000000000000008833333
        30BBBBBBBBBBBBBBB083333330B8000000000008B083333330B0FFFFFFFFFFF0
        B08333334FB0F777777777F0B083333344F0FFFFFFFFFFF0B0833333444F7FFF
        FFFFFFF0B08334444444F7FF777777F0B083344444444F7FFFFFFFF0B0833444
        444444F7FFFFFFF0B083344444444F7FF77777F0B08334444444F7FFFFFFFFF0
        B0833333444F7FFFFFFFFFF0B083333344F0FF77777777F0B08333334FB0FFFF
        FFFFFFF0B083333330B0FFFFFFFFFFF0B083333330B0FF0000000FF0B0833333
        30B80007F7770008B083333330BBBBB07F70BBBBB03333333300000007000000
        0333333333333330F77033333333333333333330000033333333}
      ParentFont = False
      TabOrder = 0
      OnClick = BitBtn2Click
    end
    object BitBtn3: TBitBtn
      Left = 506
      Top = 15
      Width = 133
      Height = 34
      Cursor = crHandPoint
      Caption = #1042#1099#1093#1086#1076
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = bkClose
      NumGlyphs = 2
      ParentFont = False
      TabOrder = 1
      OnClick = BitBtn3Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 642
    Height = 81
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object Label1: TLabel
      Left = 13
      Top = 13
      Width = 238
      Height = 26
      Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1072','#13#10#1082#1086#1090#1086#1088#1086#1075#1086' '#1085#1091#1078#1085#1086' '#1074#1086#1089#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1074' '#1089#1087#1080#1089#1082#1077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label35: TLabel
      Left = 13
      Top = 48
      Width = 117
      Height = 13
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1092#1072#1084#1080#1083#1080#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 143
      Top = 45
      Width = 215
      Height = 21
      Color = 14936298
      TabOrder = 0
      OnChange = Edit1Change
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 81
    Width = 642
    Height = 251
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    object DBGrid1: TDBGrid
      Left = 2
      Top = 2
      Width = 638
      Height = 247
      Align = alClient
      Color = clMenu
      DataSource = DM.DSAbitura
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -10
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      OnDblClick = BitBtn2Click
      Columns = <
        item
          Expanded = False
          FieldName = 'NOM_DELA'
          Title.Alignment = taCenter
          Title.Caption = #8470' '#1076#1077#1083#1072
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -13
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 60
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NOM_GROUP'
          Title.Alignment = taCenter
          Title.Caption = #8470' '#1075#1088'.'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -13
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'FAM'
          Title.Alignment = taCenter
          Title.Caption = #1060#1072#1084#1080#1083#1080#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -13
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 122
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAME'
          Title.Alignment = taCenter
          Title.Caption = #1048#1084#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -13
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 70
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'OTCH'
          Title.Alignment = taCenter
          Title.Caption = #1054#1090#1095#1077#1089#1090#1074#1086
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -13
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 100
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'N_FAC1'
          Title.Alignment = taCenter
          Title.Caption = #1060#1072#1082#1091#1083#1100#1090#1077#1090
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -13
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 88
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'SPECIALIZ1'
          Title.Alignment = taCenter
          Title.Caption = #1053#1072#1087#1088#1072#1074#1083'. '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1080
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -13
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 206
          Visible = True
        end>
    end
  end
end
