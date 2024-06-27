object Print_OpisForm: TPrint_OpisForm
  Left = 321
  Top = 48
  Caption = 'Print_OpisForm'
  ClientHeight = 186
  ClientWidth = 470
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object frxRepOpis: TfrxReport
    Version = '5.6.1'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 43747.588594108800000000
    ReportOptions.LastChange = 44729.419864293980000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 80
    Top = 32
    Datasets = <
      item
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      HGuides.Strings = (
        '53'
        '55')
      VGuides.Strings = (
        '200,31509'
        '200,31509'
        '211,65368'
        '211,65368')
      object Memo1: TfrxMemoView
        Left = 319.370122680000000000
        Top = 1.133858270000000000
        Width = 66.897650000000000000
        Height = 18.897640240000000000
        ShowHint = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -17
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          #1054#1055#1048#1057#1068)
        ParentFont = False
      end
      object Memo2: TfrxMemoView
        Left = 74.834650550000000000
        Top = 26.456692913385800000
        Width = 239.999843780000000000
        Height = 18.897640240000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          
            #1083#1080#1095#1085#1086#1075#1086' '#1076#1077#1083#1072' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1072' '#8470'   ___________________________________' +
            '_______')
        ParentFont = False
      end
      object Memo3: TfrxMemoView
        Left = 319.370117800000000000
        Top = 21.031496060000000000
        Width = 375.858228660000000000
        Height = 19.118110240000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Memo4: TfrxMemoView
        Left = 404.409502520000000000
        Top = 41.952755905511800000
        Width = 522.330708660000000000
        Height = 13.228346460000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        Memo.UTF8W = (
          '('#1087#1086' '#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1086#1085#1085#1086#1084#1091' '#1078#1091#1088#1085#1072#1083#1091')')
        ParentFont = False
      end
      object Memo5: TfrxMemoView
        Left = 34.015750470000000000
        Top = 63.118117560000000000
        Width = 61.228048660000000000
        Height = 17.007876460000000000
        Memo.UTF8W = (
          #1060#1072#1084#1080#1083#1080#1103)
      end
      object Memo6: TfrxMemoView
        Left = 266.456744170000000000
        Top = 57.448826220000000000
        Width = 134.929192440000000000
        Height = 18.141734720000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          '[frxDBDataset1."FAM"]')
        ParentFont = False
      end
      object Memo7: TfrxMemoView
        Left = 34.015750470000000000
        Top = 102.047258740000000000
        Width = 112.251702440000000000
        Height = 17.007876460000000000
        Memo.UTF8W = (
          #1057#1086#1073#1089#1090#1074#1077#1085#1085#1086#1077' '#1080#1084#1103)
      end
      object Memo8: TfrxMemoView
        Left = 266.456744170000000000
        Top = 89.952765670000000000
        Width = 136.062992130000000000
        Height = 21.921264720000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          '[frxDBDataset1."NAME"]')
        ParentFont = False
      end
      object Memo9: TfrxMemoView
        Left = 34.015750470000000000
        Top = 138.708680940000000000
        Width = 211.653445670000000000
        Height = 17.007876460000000000
        Memo.UTF8W = (
          #1054#1090#1095#1077#1089#1090#1074#1086' ('#1077#1089#1083#1080' '#1090#1072#1082#1086#1074#1086#1077' '#1080#1084#1077#1077#1090#1089#1103')')
      end
      object Memo30: TfrxMemoView
        Left = 266.456744170000000000
        Top = 129.259859610000000000
        Width = 137.952826690000000000
        Height = 21.921264720000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          '[frxDBDataset1."OTCH"]')
        ParentFont = False
      end
      object Memo31: TfrxMemoView
        Left = 34.015750470000000000
        Top = 177.637822130000000000
        Width = 68.787108660000000000
        Height = 17.007876460000000000
        Memo.UTF8W = (
          #1060#1072#1082#1091#1083#1100#1090#1077#1090)
      end
      object Memo32: TfrxMemoView
        Left = 266.456744170000000000
        Top = 165.543329060000000000
        Width = 137.952819370000000000
        Height = 21.921264720000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          '[frxDBDataset1."N_FAC1"]')
        ParentFont = False
      end
      object Memo33: TfrxMemoView
        Left = 34.015750470000000000
        Top = 214.299244330000000000
        Width = 196.535223150000000000
        Height = 17.007876460000000000
        Memo.UTF8W = (
          #1060#1086#1088#1084#1072' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103)
      end
      object Memo34: TfrxMemoView
        Left = 266.456744170000000000
        Top = 204.850422990000000000
        Width = 137.952533780000000000
        Height = 21.921264720000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          '[frxDBDataset1."VID_EDU1"]')
        ParentFont = False
      end
      object Memo35: TfrxMemoView
        Left = 34.015750470000000000
        Top = 250.582716220000000000
        Width = 204.094537010000000000
        Height = 32.125996460000000000
        Memo.UTF8W = (
          #1057#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1100' ('#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1080', '#1089#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103')')
      end
      object Memo37: TfrxMemoView
        Left = 246.425240790000000000
        Top = 241.133894880000000000
        Width = 430.866185670000000000
        Height = 39.685046690000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          '[frxDBDataset1."SPECIAL1"]')
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo38: TfrxMemoView
        Left = 32.125984250000000000
        Top = 382.488250000000000000
        Width = 665.196943150000000000
        Height = 417.637853860000000000
      end
      object Memo39: TfrxMemoView
        Left = 34.015750470000000000
        Top = 294.803149610000000000
        Width = 56.692913390000000000
        Height = 49.133858270000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #8470' '#1087'/'#1087)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo40: TfrxMemoView
        Left = 90.708663860000000000
        Top = 294.803149610000000000
        Width = 245.669291340000000000
        Height = 49.133858270000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1053#1072#1079#1074#1072#1085#1080#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo41: TfrxMemoView
        Left = 336.377955200000000000
        Top = 294.803149610000000000
        Width = 185.196850390000000000
        Height = 49.133858270000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1044#1072#1090#1072' '#1074#1099#1077#1084#1082#1080' '#1080' '#1084#1077#1089#1090#1086' '#1085#1072#1093#1086#1078#1076#1077#1085#1080#1103' '#1076#1086#1082#1091#1084#1077#1085#1090#1072)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo63: TfrxMemoView
        Left = 521.574805590000000000
        Top = 294.803149610000000000
        Width = 177.637795280000000000
        Height = 49.133858270000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1044#1072#1090#1072' '#1074#1086#1079#1074#1088#1072#1090#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1072' '#1074' '#1083#1080#1095#1085#1086#1077' '#1076#1077#1083#1086)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo65: TfrxMemoView
        Left = 1.889763780000000000
        Top = 822.047361260000000000
        Width = 179.527615200000000000
        Height = 47.244094488189000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1044#1086#1082#1091#1084#1077#1085#1090#1099' '#1087#1088#1080#1085#1103#1090#1099)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo66: TfrxMemoView
        Left = 181.417322830000000000
        Top = 822.047244090000000000
        Width = 181.417366770000000000
        Height = 47.244094490000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1044#1086#1082#1091#1084#1077#1085#1090#1099' '#1074#1086#1079#1074#1088#1072#1097#1077#1085#1099
          ' '#1074' '#1089#1074#1103#1079#1080' '#1089' '#1074#1099#1073#1099#1090#1080#1077#1084)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo11: TfrxMemoView
        Left = 362.834645670000000000
        Top = 822.047244090000000000
        Width = 177.637795280000000000
        Height = 47.244094490000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1044#1086#1082#1091#1084#1077#1085#1090#1099' '#1087#1077#1088#1077#1074#1077#1076#1077#1085#1099
          ' '#1085#1072' _______________')
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo13: TfrxMemoView
        Left = 540.472440940000000000
        Top = 822.047244090000000000
        Width = 173.858304330000000000
        Height = 47.244094490000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1059#1082#1086#1084#1087#1083#1077#1082#1090#1086#1074#1072#1085#1086)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo14: TfrxMemoView
        Left = 1.889749130000000000
        Top = 869.291338580000000000
        Width = 88.818897640000000000
        Height = 28.346456690000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1044#1072#1090#1072)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo15: TfrxMemoView
        Left = 90.708661420000000000
        Top = 869.291338580000000000
        Width = 90.708661420000000000
        Height = 28.346456690000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1087#1086#1076#1087#1080#1089#1100)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo16: TfrxMemoView
        Left = 181.417335040000000000
        Top = 869.291338580000000000
        Width = 90.708661420000000000
        Height = 28.346456690000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1044#1072#1090#1072)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo17: TfrxMemoView
        Left = 272.125984250000000000
        Top = 869.291338580000000000
        Width = 90.708661420000000000
        Height = 28.346456690000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1087#1086#1076#1087#1080#1089#1100)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo18: TfrxMemoView
        Left = 362.834687170000000000
        Top = 869.291338580000000000
        Width = 88.818897640000000000
        Height = 28.346456690000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1044#1072#1090#1072)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo19: TfrxMemoView
        Left = 451.653543310000000000
        Top = 869.291338580000000000
        Width = 88.818897640000000000
        Height = 28.346456690000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1087#1086#1076#1087#1080#1089#1100)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo20: TfrxMemoView
        Left = 540.472440940000000000
        Top = 869.291338580000000000
        Width = 86.929133858267700000
        Height = 28.346456690000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1044#1072#1090#1072)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo21: TfrxMemoView
        Left = 627.401574803150000000
        Top = 869.291338580000000000
        Width = 86.929133860000000000
        Height = 28.346456690000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        Memo.UTF8W = (
          #1087#1086#1076#1087#1080#1089#1100)
        ParentFont = False
        VAlign = vaCenter
      end
      object Shape5: TfrxShapeView
        Left = 34.015770000000000000
        Top = 343.937061570000000000
        Width = 56.692950000000000000
        Height = 26.456690470000000000
        Frame.Width = 2.000000000000000000
      end
      object Shape6: TfrxShapeView
        Left = 90.708720000000000000
        Top = 343.937061570000000000
        Width = 245.669450000000000000
        Height = 26.456690470000000000
        Frame.Width = 2.000000000000000000
      end
      object Shape7: TfrxShapeView
        Left = 336.378170000000000000
        Top = 343.937061570000000000
        Width = 185.196970000000000000
        Height = 26.456690470000000000
        Frame.Width = 2.000000000000000000
      end
      object Shape8: TfrxShapeView
        Left = 521.575140000000000000
        Top = 343.937061570000000000
        Width = 177.637910000000000000
        Height = 26.456690470000000000
        Frame.Width = 2.000000000000000000
      end
      object Line1: TfrxLineView
        Left = 98.267780000000000000
        Top = 79.370130000000000000
        Width = 582.047620000000000000
        Color = clBlack
        ArrowWidth = 77
        Frame.Typ = [ftTop]
        Frame.Width = 2.000000000000000000
      end
      object Line2: TfrxLineView
        Left = 151.181200000000000000
        Top = 117.165430000000000000
        Width = 529.134200000000000000
        Color = clBlack
        ArrowWidth = 77
        Frame.Typ = [ftTop]
        Frame.Width = 2.000000000000000000
      end
      object Line3: TfrxLineView
        Left = 249.448980000000000000
        Top = 154.960730000000000000
        Width = 430.866420000000000000
        Color = clBlack
        ArrowWidth = 77
        Frame.Typ = [ftTop]
        Frame.Width = 2.000000000000000000
      end
      object Line4: TfrxLineView
        Left = 105.826840000000000000
        Top = 192.756030000000000000
        Width = 574.488560000000000000
        Color = clBlack
        ArrowWidth = 77
        Frame.Typ = [ftTop]
        Frame.Width = 2.000000000000000000
      end
      object Line5: TfrxLineView
        Left = 234.330860000000000000
        Top = 230.551330000000000000
        Width = 445.984540000000000000
        Color = clBlack
        ArrowWidth = 77
        Frame.Typ = [ftTop]
        Frame.Width = 2.000000000000000000
      end
      object Line6: TfrxLineView
        Left = 241.889920000000000000
        Top = 283.464750000000000000
        Width = 438.425480000000000000
        Color = clBlack
        ArrowWidth = 77
        Frame.Typ = [ftTop]
        Frame.Width = 2.000000000000000000
      end
      object Line7: TfrxLineView
        Left = 313.700990000000000000
        Top = 43.464566930000000000
        Width = 336.378170000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
        Frame.Width = 2.000000000000000000
      end
      object Memo10: TfrxMemoView
        Left = 1.889763780000000000
        Top = 897.637795280000000000
        Width = 88.818897640000000000
        Height = 28.346456690000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Width = 2.000000000000000000
        HAlign = haCenter
        ParentFont = False
        VAlign = vaCenter
      end
    end
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSet = DM.QReport_Rasp
    BCDToCurrency = False
    Left = 80
    Top = 112
  end
end
