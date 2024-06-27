object MainForm: TMainForm
  Left = 221
  Top = 195
  Hint = #1057#1077#1088#1090#1080#1092#1080#1082#1072#1090#1099' '#1079#1072#1095#1080#1089#1083#1077#1085#1085#1099#1093
  BorderIcons = [biMinimize, biMaximize]
  Caption = ' '#1040#1057#1059' "'#1040#1073#1080#1090#1091#1088#1080#1077#1085#1090'"'
  ClientHeight = 498
  ClientWidth = 723
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Arial'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  ShowHint = True
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 18
  object Shape1: TShape
    Left = 0
    Top = 0
    Width = 723
    Height = 1
    Align = alTop
    ExplicitWidth = 679
  end
  object Label1: TLabel
    Left = 160
    Top = 12
    Width = 180
    Height = 18
    Caption = #1055#1086#1089#1083#1077#1076#1085#1080#1081' '#1085#1086#1084#1077#1088' '#1076#1077#1083#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object NumDelaLbl1: TLabel
    Left = 405
    Top = 30
    Width = 90
    Height = 20
    Caption = #1085#1086#1084#1077#1088' '#1076#1077#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI Semilight'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object SpeedButton1: TSpeedButton
    Left = 144
    Top = 392
    Width = 23
    Height = 22
    Hint = #1057#1084#1077#1085#1072' '#1092#1072#1082#1091#1083#1100#1090#1077#1090#1072
    ParentShowHint = False
    ShowHint = True
    Visible = False
    OnClick = SpeedButton1Click
  end
  object SpeedButton2: TSpeedButton
    Left = 127
    Top = 8
    Width = 25
    Height = 25
    Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1087#1086#1089#1083#1077#1076#1085#1080#1081' '#1085#1086#1084#1077#1088' '#1076#1077#1083#1072
    Glyph.Data = {
      66010000424D6601000000000000760000002800000014000000140000000100
      040000000000F000000000000000000000001000000010000000000000000000
      BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
      7777777700007777777778888887777700007777777000003888777700007777
      770BBBB03088877700007777770BBBB0308887770000777770BBBB0333088777
      0000777770BBBB03330887770000777770000003330887770000777777778033
      3308877700007777777000333308877700007777770BB0333308877700007777
      70BBBB0333088777000077770BBBBBB03308877700007770BBBBBBBB03088777
      0000777000BBBB00030887770000777770BBBB033308777700007777770BBBB0
      3087777700007777770BBBB03077777700007777777000003777777700007777
      77777777777777770000}
    ParentShowHint = False
    ShowHint = True
    OnClick = SpeedButton2Click
  end
  object SpeedButton3: TSpeedButton
    Left = 196
    Top = 392
    Width = 23
    Height = 22
    Hint = #1057#1077#1088#1090#1080#1092#1080#1082#1072#1090#1099' '#1087#1086' '#1082#1088#1080#1090#1077#1088#1080#1103#1084
    ParentShowHint = False
    ShowHint = True
    Visible = False
    OnClick = SpeedButton3Click
  end
  object SpeedButton4: TSpeedButton
    Left = 248
    Top = 392
    Width = 23
    Height = 22
    OnClick = SpeedButton4Click
  end
  object Label2: TLabel
    Left = 160
    Top = 32
    Width = 182
    Height = 17
    Caption = #1044#1085#1077#1074#1085#1072#1103', '#1087#1086#1083#1085#1099#1081', '#1073#1102#1076#1078#1077#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 160
    Top = 52
    Width = 194
    Height = 17
    Caption = #1044#1085#1077#1074#1085#1072#1103', '#1087#1086#1083#1085#1099#1081', '#1079#1072' '#1086#1087#1083#1072#1090#1091':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 160
    Top = 72
    Width = 224
    Height = 17
    Caption = #1044#1085#1077#1074#1085#1072#1103', '#1089#1086#1082#1088#1072#1097#1105#1085#1085#1099#1081', '#1073#1102#1076#1078#1077#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 160
    Top = 92
    Width = 236
    Height = 17
    Caption = #1044#1085#1077#1074#1085#1072#1103', '#1089#1086#1082#1088#1072#1097#1105#1085#1085#1099#1081', '#1079#1072' '#1086#1087#1083#1072#1090#1091':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 160
    Top = 112
    Width = 181
    Height = 17
    Caption = #1047#1072#1086#1095#1085#1072#1103', '#1087#1086#1083#1085#1099#1081', '#1073#1102#1076#1078#1077#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 160
    Top = 132
    Width = 193
    Height = 17
    Caption = #1047#1072#1086#1095#1085#1072#1103', '#1087#1086#1083#1085#1099#1081', '#1079#1072' '#1086#1087#1083#1072#1090#1091':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Label8: TLabel
    Left = 160
    Top = 152
    Width = 223
    Height = 17
    Caption = #1047#1072#1086#1095#1085#1072#1103', '#1089#1086#1082#1088#1072#1097#1105#1085#1085#1099#1081', '#1073#1102#1076#1078#1077#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Label9: TLabel
    Left = 160
    Top = 172
    Width = 235
    Height = 17
    Caption = #1047#1072#1086#1095#1085#1072#1103', '#1089#1086#1082#1088#1072#1097#1105#1085#1085#1099#1081', '#1079#1072' '#1086#1087#1083#1072#1090#1091':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object NumDelaLbl2: TLabel
    Left = 405
    Top = 50
    Width = 90
    Height = 20
    Caption = #1085#1086#1084#1077#1088' '#1076#1077#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI Semilight'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object NumDelaLbl3: TLabel
    Left = 405
    Top = 70
    Width = 90
    Height = 20
    Caption = #1085#1086#1084#1077#1088' '#1076#1077#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI Semilight'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object NumDelaLbl4: TLabel
    Left = 405
    Top = 90
    Width = 90
    Height = 20
    Caption = #1085#1086#1084#1077#1088' '#1076#1077#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI Semilight'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object NumDelaLbl5: TLabel
    Left = 405
    Top = 110
    Width = 90
    Height = 20
    Caption = #1085#1086#1084#1077#1088' '#1076#1077#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI Semilight'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object NumDelaLbl6: TLabel
    Left = 405
    Top = 130
    Width = 90
    Height = 20
    Caption = #1085#1086#1084#1077#1088' '#1076#1077#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI Semilight'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object NumDelaLbl7: TLabel
    Left = 405
    Top = 150
    Width = 90
    Height = 20
    Caption = #1085#1086#1084#1077#1088' '#1076#1077#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI Semilight'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object NumDelaLbl8: TLabel
    Left = 405
    Top = 170
    Width = 90
    Height = 20
    Caption = #1085#1086#1084#1077#1088' '#1076#1077#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI Semilight'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 1
    Width = 121
    Height = 497
    Align = alLeft
    BorderStyle = bsNone
    Color = clMenu
    DataSource = DM.DSGroup_Count
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI Semilight'
    Font.Style = []
    Options = [dgTitles, dgRowLines]
    ParentFont = False
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Segoe UI Semilight'
    TitleFont.Style = []
    Columns = <
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'NOM_GROUP'
        Title.Alignment = taCenter
        Title.Caption = #8470' '#1075#1088'.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'Segoe UI Semilight'
        Title.Font.Style = [fsBold]
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'COUNT'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Segoe UI Semilight'
        Font.Style = [fsBold]
        Title.Alignment = taCenter
        Title.Caption = #1050#1086#1083'-'#1074#1086' '
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'Segoe UI Semilight'
        Title.Font.Style = [fsBold]
        Width = 56
        Visible = True
      end>
  end
  object MainMenu1: TMainMenu
    Left = 664
    Top = 16
    object N1: TMenuItem
      Caption = #1040#1073#1080#1090#1091#1088#1080#1077#1085#1090
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1043#1088#1091#1087#1087#1099
      object N13: TMenuItem
        Caption = #1050#1088#1072#1090#1082#1080#1081' '#1089#1087#1080#1089#1086#1082' '#1075#1088#1091#1087#1087
        OnClick = N13Click
      end
      object N14: TMenuItem
        Caption = #1055#1086#1083#1085#1099#1081' '#1089#1087#1080#1089#1086#1082' '#1075#1088#1091#1087#1087
        OnClick = N14Click
      end
      object N42: TMenuItem
        Caption = #1057#1087#1080#1089#1086#1082' '#1087#1086' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1103#1084
        OnClick = N42Click
      end
      object N86: TMenuItem
        Caption = #1057#1087#1080#1089#1086#1082' '#1075#1088#1091#1087#1087' '#1087#1086' '#1087#1086#1083#1091
        OnClick = N86Click
      end
    end
    object N3: TMenuItem
      Caption = #1069#1082#1079#1072#1084#1077#1085#1099
      object N33: TMenuItem
        Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1080' '#1087#1086' '#1085#1072#1087#1088#1072#1083#1077#1085#1080#1103#1084
        OnClick = N33Click
      end
      object N4: TMenuItem
        Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1080' '#1085#1072' '#1075#1088#1091#1087#1087#1091
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099
        OnClick = N5Click
      end
      object N18: TMenuItem
        Caption = '-'
      end
      object N49: TMenuItem
        Caption = #1055#1088#1086#1090#1086#1082#1086#1083#1099
        object N311: TMenuItem
          Caption = '4 '#1089#1090#1072#1085#1076#1072#1088#1090#1085#1099#1093' '#1074#1080#1076#1072
          OnClick = N311Click
        end
        object N1001: TMenuItem
          Caption = #1054#1060#1055' '#1041#1077#1075' 100'
          Visible = False
        end
        object N150010001: TMenuItem
          Caption = #1054#1060#1055' '#1041#1077#1075' 1500 (1000)'
          Visible = False
        end
        object N54: TMenuItem
          Caption = #1050#1059' '#1087#1086' '#1060#1050#1080#1057
          Visible = False
          OnClick = N54Click
        end
      end
      object N17: TMenuItem
        Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1087#1086#1073#1077#1076#1080#1090#1077#1083#1077#1081' '#1086#1083#1080#1084#1087#1080#1072#1076#1099
        OnClick = N17Click
      end
      object N19: TMenuItem
        Caption = '-'
      end
      object N6: TMenuItem
        Caption = #1040#1087#1087#1077#1083#1103#1094#1080#1080
        Visible = False
        OnClick = N6Click
      end
      object N16: TMenuItem
        Caption = #1042#1086#1089#1089#1090#1072#1085#1086#1074#1083#1077#1085#1080#1077' '#1087#1086' '#1089#1087#1088#1072#1074#1082#1077
        OnClick = N16Click
      end
    end
    object N7: TMenuItem
      Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072
      object N43: TMenuItem
        Caption = #1050#1086#1083'-'#1074#1086' '#1087#1086#1076#1072#1085#1085#1099#1093' '#1079#1072#1103#1074#1083#1077#1085#1080#1081' '#1087#1086' '#1073#1072#1083#1083#1072#1084
        Visible = False
        OnClick = N43Click
      end
      object N15: TMenuItem
        Caption = #1050#1086#1083'-'#1074#1086' '#1087#1086#1076#1072#1085#1085#1099#1093' '#1079#1072#1103#1074#1083#1077#1085#1080#1081' ('#1077#1078#1077#1076#1085#1077#1074#1085#1072#1103')'
        OnClick = N15Click
      end
      object N28: TMenuItem
        Caption = #1055#1088#1086#1090#1086#1082#1086#1083' ('#1077#1078#1077#1076#1085#1077#1074#1085#1099#1081')'
        OnClick = N28Click
      end
      object N64: TMenuItem
        Caption = #1046#1091#1088#1085#1072#1083' '#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1080' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
        OnClick = N64Click
      end
      object N20: TMenuItem
        Caption = #1052#1080#1085#1080#1089#1090#1077#1088#1089#1090#1074#1086' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103
        Visible = False
        object N110: TMenuItem
          Caption = #1060#1086#1088#1084#1072' 1-'#1050' ('#1086' '#1082#1086#1083'-'#1074#1077' '#1087#1086#1076#1072#1085#1085#1099#1093' '#1079#1072#1103#1074#1083#1077#1085#1080#1081')'
          OnClick = N110Click
        end
        object N111: TMenuItem
          Caption = #1060#1086#1088#1084#1072' 1-'#1055#1041' ('#1082#1086#1085#1082#1091#1088#1089' '#1080' '#1087#1088#1086#1093#1086#1076#1085#1086#1081' '#1073#1072#1083#1083')'
        end
        object N112: TMenuItem
          Caption = #1060#1086#1088#1084#1072' 1'
          OnClick = N112Click
        end
        object N21: TMenuItem
          Caption = #1060#1086#1088#1084#1072' 2'
          OnClick = N21Click
        end
        object N31: TMenuItem
          Caption = #1060#1086#1088#1084#1072' 3'
          OnClick = N31Click
        end
        object N113: TMenuItem
          Caption = #1060#1086#1088#1084#1072' 1'#1052' ('#1087#1086#1089#1090#1091#1087#1083#1077#1085#1080#1077' '#1084#1077#1076#1072#1083#1080#1089#1090#1086#1074')'
        end
        object N114: TMenuItem
          Caption = #1060#1086#1088#1084#1072' 1'#1062' ('#1087#1088#1080#1077#1084' '#1087#1086' '#1094#1077#1083#1077#1074#1086#1084#1091' '#1082#1086#1085#1090#1088#1072#1082#1090#1091')'
        end
        object N115: TMenuItem
          Caption = #1060#1086#1088#1084#1072' 1'#1091#1080' ('#1087#1088#1086#1093#1086#1078#1076#1077#1085#1080#1077' '#1074#1089#1090#1091#1087#1080#1090#1077#1083#1100#1085#1099#1093' '#1101#1082#1079#1072#1084#1077#1085#1086#1074')'
        end
      end
      object N29: TMenuItem
        Caption = #1060#1086#1088#1084#1099' '#1076#1083#1103' '#1086#1090#1095#1077#1090#1072
        object N32: TMenuItem
          Caption = #1055#1086#1076#1072#1085#1086' '#1079#1072#1103#1074#1083#1077#1085#1080#1081' ('#1080#1090#1086#1075#1086#1074#1072#1103')'
          OnClick = N32Click
        end
        object N44: TMenuItem
          Caption = #1055#1086#1076#1072#1085#1086' '#1079#1072#1103#1074#1083#1077#1085#1080#1081' '#1087#1086' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1103#1084
          OnClick = N44Click
        end
        object N30: TMenuItem
          Caption = #1057#1074#1077#1076#1077#1085#1080#1103' '#1086' '#1087#1088#1080#1077#1084#1077' '#1079#1072#1103#1074#1083#1077#1085#1080#1081' '#1087#1086' '#1088#1077#1075#1080#1086#1085#1072#1084
          Visible = False
          OnClick = N30Click
        end
        object N37: TMenuItem
          Caption = #1059#1088#1086#1074#1077#1085#1100' '#1089#1087#1086#1088#1090#1080#1074#1085#1086#1081' '#1087#1086#1076#1075#1086#1090#1086#1074#1083#1077#1085#1085#1086#1089#1090#1080
          OnClick = N37Click
        end
      end
      object N36: TMenuItem
        Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1074#1089#1090#1091#1087#1080#1090#1077#1083#1100#1085#1099#1093' '#1080#1089#1087#1099#1090#1072#1085#1080#1081
        OnClick = N36Click
      end
      object N40: TMenuItem
        Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1080#1079#1083#1086#1078#1077#1085#1080#1103
        Visible = False
      end
      object N38: TMenuItem
        Caption = #1043#1086#1089#1082#1086#1085#1090#1088#1086#1083#1100
        Visible = False
        object N39: TMenuItem
          Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1093#1086#1076#1077' '#1087#1088#1080#1077#1084#1072
          OnClick = N39Click
        end
      end
      object N9: TMenuItem
        Caption = #1043#1048#1040#1062
        Visible = False
        object N116: TMenuItem
          Caption = #1060#1086#1088#1084#1072' 1 ('#1087#1088#1080#1077#1084')'
          object N45: TMenuItem
            Caption = #1044#1085#1077#1074#1085#1072#1103' '#1092#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
            OnClick = N45Click
          end
          object N47: TMenuItem
            Caption = #1047#1072#1086#1095#1085#1072#1103' '#1092#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
            OnClick = N47Click
          end
        end
        object N310: TMenuItem
          Caption = #1060#1086#1088#1084#1072' 1-'#1042#1059#1047' '#1079#1072#1095#1080#1089#1083#1077#1085#1080#1077' '#1076#1085#1077#1074#1085#1072#1103' '#1073#1102#1076#1078#1077#1090
          Visible = False
          OnClick = N310Click
        end
        object N210: TMenuItem
          Caption = #1060#1086#1088#1084#1072' 2 ('#1079#1072#1095#1080#1089#1083#1077#1085#1080#1077')'
          object N46: TMenuItem
            Caption = #1044#1085#1077#1074#1085#1072#1103' '#1092#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
            OnClick = N46Click
          end
          object N48: TMenuItem
            Caption = #1047#1072#1086#1095#1085#1072#1103' '#1092#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
            OnClick = N48Click
          end
        end
      end
      object N55: TMenuItem
        Caption = #1050#1086#1085#1082#1091#1088#1089
        OnClick = N55Click
      end
    end
    object N8: TMenuItem
      Caption = #1047#1072#1095#1080#1089#1083#1077#1085#1080#1077
      object N23: TMenuItem
        Caption = #1055#1088#1086#1089#1091#1084#1084#1080#1088#1086#1074#1072#1090#1100' '#1101#1082#1079'. '#1086#1094#1077#1085#1082#1080
        OnClick = N23Click
      end
      object N24: TMenuItem
        Caption = '-'
      end
      object N26: TMenuItem
        Caption = #1057#1074#1086#1076#1085#1072#1103' '#1074#1077#1076#1086#1084#1086#1089#1090#1100' '#1085#1072' 2 '#1082#1091#1088#1089
        Enabled = False
        Visible = False
        OnClick = N26Click
      end
      object N34: TMenuItem
        Caption = '-'
        Visible = False
      end
      object N65: TMenuItem
        Caption = #1057#1074#1086#1076#1085#1072#1103' '#1074#1077#1076#1086#1084#1086#1089#1090#1100' '#1087#1086#1083#1085#1099#1081' '#1089#1088#1086#1082
        object N66: TMenuItem
          Caption = #1044#1085#1077#1074#1085#1072#1103' '#1092#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
          object N68: TMenuItem
            Caption = #1041#1102#1076#1078#1077#1090
            OnClick = N68Click
          end
          object N69: TMenuItem
            Caption = #1047#1072' '#1086#1087#1083#1072#1090#1091
            OnClick = N69Click
          end
        end
        object N67: TMenuItem
          Caption = #1047#1072#1086#1095#1085#1072#1103' '#1092#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
          object N70: TMenuItem
            Caption = #1041#1102#1076#1078#1077#1090
            OnClick = N70Click
          end
          object N71: TMenuItem
            Caption = #1047#1072' '#1086#1087#1083#1072#1090#1091
            OnClick = N71Click
          end
        end
      end
      object N72: TMenuItem
        Caption = #1057#1074#1086#1076#1085#1072#1103' '#1074#1077#1076#1086#1084#1086#1089#1090#1100' '#1089#1086#1082#1088#1072#1097#1105#1085#1085#1099#1081' '#1089#1088#1086#1082
        object N73: TMenuItem
          Caption = #1044#1085#1077#1074#1085#1072#1103' '#1092#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
          object N75: TMenuItem
            Caption = #1041#1102#1076#1078#1077#1090
            OnClick = N75Click
          end
          object N76: TMenuItem
            Caption = #1047#1072' '#1086#1087#1083#1072#1090#1091
            OnClick = N76Click
          end
        end
        object N74: TMenuItem
          Caption = #1047#1072#1086#1095#1085#1072#1103' '#1092#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
          object N77: TMenuItem
            Caption = #1041#1102#1076#1078#1077#1090
            OnClick = N77Click
          end
          object N78: TMenuItem
            Caption = #1047#1072' '#1086#1087#1083#1072#1090#1091
            OnClick = N78Click
          end
        end
      end
      object N221: TMenuItem
        Caption = #1057#1074#1086#1076#1085#1072#1103' '#1074#1077#1076#1086#1084#1086#1089#1090#1100' 2 '#1042#1054' 2 '#1082#1091#1088#1089
        object N79: TMenuItem
          Caption = #1044#1085#1077#1074#1085#1072#1103' '#1092#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
          object N81: TMenuItem
            Caption = #1041#1102#1076#1078#1077#1090
            OnClick = N81Click
          end
          object N83: TMenuItem
            Caption = #1047#1072' '#1086#1087#1083#1072#1090#1091
            OnClick = N83Click
          end
        end
        object N80: TMenuItem
          Caption = #1047#1072#1086#1095#1085#1072#1103' '#1092#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
          object N82: TMenuItem
            Caption = #1041#1102#1076#1078#1077#1090
            OnClick = N82Click
          end
          object N84: TMenuItem
            Caption = #1047#1072' '#1086#1087#1083#1072#1090#1091
            OnClick = N84Click
          end
        end
      end
      object N22: TMenuItem
        Caption = #1057#1074#1086#1076#1085#1072#1103' '#1074#1077#1076#1086#1084#1086#1089#1090#1100' '#1076#1085#1077#1074#1085#1072#1103' ('#1073#1102#1076#1078#1077#1090')'
        Visible = False
        OnClick = N22Click
      end
      object N27: TMenuItem
        Caption = #1057#1074#1086#1076#1085#1072#1103' '#1074#1077#1076#1086#1084#1086#1089#1090#1100' '#1079#1072#1086#1095#1085#1072#1103' ('#1073#1102#1076#1078#1077#1090')'
        Visible = False
        OnClick = N27Click
      end
      object N10: TMenuItem
        Caption = #1057#1074#1086#1076#1085#1072#1103' '#1074#1077#1076#1086#1084#1086#1089#1090#1100' '#1076#1085#1077#1074#1085#1072#1103' ('#1086#1087#1083#1072#1090#1072')'
        Visible = False
        OnClick = N10Click
      end
      object N41: TMenuItem
        Caption = #1057#1074#1086#1076#1085#1072#1103' '#1074#1077#1076#1086#1084#1086#1089#1090#1100' '#1079#1072#1086#1095#1085#1072#1103' ('#1086#1087#1083#1072#1090#1072')'
        Visible = False
        OnClick = N41Click
      end
      object N25: TMenuItem
        Caption = '-'
      end
      object N35: TMenuItem
        Caption = #1055#1088#1080#1082#1072#1079' '#1085#1072' '#1079#1072#1095#1080#1089#1083#1077#1085#1080#1077
        OnClick = N35Click
      end
      object N56: TMenuItem
        Caption = '-'
      end
      object N57: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100' '#1080#1079#1074#1077#1097#1077#1085#1080#1081' '#1080' '#1082#1086#1085#1074#1077#1088#1090#1086#1074
        object N60: TMenuItem
          Caption = #1073#1102#1076#1078#1077#1090
          object N58: TMenuItem
            Caption = #1076#1085#1077#1074#1085#1072#1103
            OnClick = N58Click
          end
          object N59: TMenuItem
            Caption = #1079#1072#1086#1095#1085#1072#1103
            OnClick = N59Click
          end
        end
        object N61: TMenuItem
          Caption = #1079#1072' '#1086#1087#1083#1072#1090#1091
          object N62: TMenuItem
            Caption = #1076#1085#1077#1074#1085#1072#1103
            OnClick = N62Click
          end
          object N63: TMenuItem
            Caption = #1079#1072#1086#1095#1085#1072#1103
            OnClick = N63Click
          end
        end
      end
      object N85: TMenuItem
        Caption = #1058#1080#1090#1091#1083#1100#1085#1099#1081' '#1083#1080#1089#1090' '#1083#1080#1095#1085#1086#1075#1086' '#1076#1077#1083#1072
        OnClick = N85Click
      end
    end
    object N11: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      object N52: TMenuItem
        Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082#1080
        OnClick = N52Click
      end
      object N53: TMenuItem
        Caption = #1054#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1087#1088#1072#1074' '#1076#1086#1089#1090#1091#1087#1072
        OnClick = N53Click
      end
    end
    object N12: TMenuItem
      Caption = #1042#1099#1093#1086#1076
      OnClick = N12Click
    end
  end
end
