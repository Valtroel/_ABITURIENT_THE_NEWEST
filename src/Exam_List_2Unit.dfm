object Exam_List_2Form: TExam_List_2Form
  Left = 0
  Top = 0
  Caption = 'Exam_List_2Form'
  ClientHeight = 640
  ClientWidth = 1109
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object QuickRep1: TQuickRep
    Left = -8
    Top = -143
    Width = 1123
    Height = 794
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Arial'
    Font.Style = []
    Functions.Strings = (
      'PAGENUMBER'
      'COLUMNNUMBER'
      'REPORTTITLE')
    Functions.DATA = (
      '0'
      '0'
      #39#39)
    Options = [FirstPageHeader, LastPageFooter]
    Page.Columns = 1
    Page.Orientation = poLandscape
    Page.PaperSize = A4
    Page.Continuous = False
    Page.Values = (
      100.000000000000000000
      2100.000000000000000000
      100.000000000000000000
      2970.000000000000000000
      200.000000000000000000
      100.000000000000000000
      0.000000000000000000)
    PrinterSettings.Copies = 1
    PrinterSettings.OutputBin = Auto
    PrinterSettings.Duplex = False
    PrinterSettings.FirstPage = 0
    PrinterSettings.LastPage = 0
    PrinterSettings.UseStandardprinter = False
    PrinterSettings.UseCustomBinCode = False
    PrinterSettings.CustomBinCode = 0
    PrinterSettings.ExtendedDuplex = 0
    PrinterSettings.UseCustomPaperCode = False
    PrinterSettings.CustomPaperCode = 0
    PrinterSettings.PrintMetaFile = False
    PrinterSettings.PrintQuality = 0
    PrinterSettings.Collate = 0
    PrinterSettings.ColorOption = 0
    PrintIfEmpty = True
    SnapToGrid = True
    Units = MM
    Zoom = 100
    PrevFormStyle = fsNormal
    PreviewInitialState = wsNormal
    PrevInitialZoom = qrZoomToFit
    PreviewDefaultSaveType = stQRP
    PreviewLeft = 0
    PreviewTop = 0
    object DetailBand1: TQRBand
      Left = 76
      Top = 39
      Width = 1010
      Height = 715
      AlignToBottom = False
      Color = clWhite
      TransparentBand = False
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        1891.770833333333000000
        2672.291666666667000000)
      PreCaluculateBandHeight = False
      KeepOnOnePage = False
      BandType = rbDetail
      object QRShape1_1: TQRShape
        Left = 518
        Top = 0
        Width = 225
        Height = 77
        Frame.Width = 2
        Size.Values = (
          203.729166666667000000
          1370.541666666670000000
          0.000000000000000000
          595.312500000000000000)
        XLColumn = 0
        Pen.Style = psDash
        Shape = qrsRectangle
        VertAdjust = 0
      end
      object QRLabel1_1: TQRLabel
        Left = 1
        Top = 152
        Width = 76
        Height = 16
        Size.Values = (
          42.333333333333330000
          2.645833333333333000
          402.166666666666700000
          201.083333333333300000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1103':'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel2_1: TQRLabel
        Left = 1
        Top = 177
        Width = 334
        Height = 16
        Size.Values = (
          42.333333333333330000
          2.645833333333333000
          468.312500000000000000
          883.708333333333300000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = '1. '#1069#1082#1079#1072#1084#1077#1085#1072#1094#1080#1086#1085#1085#1099#1081' '#1083#1080#1089#1090' '#1074#1084#1077#1089#1090#1077' '#1089' '#1087#1072#1089#1087#1086#1088#1090#1086#1084' '#1080#1083#1080' '#1076#1088#1091#1075#1080#1084' '
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel3_1: TQRLabel
        Left = 1
        Top = 243
        Width = 384
        Height = 16
        Size.Values = (
          42.333333333333330000
          2.645833333333333000
          642.937500000000000000
          1016.000000000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = '2. '#1055#1086' '#1086#1082#1086#1085#1095#1072#1085#1080#1080' '#1074#1089#1090#1091#1087#1080#1090#1077#1083#1100#1085#1099#1093' '#1080#1089#1087#1099#1090#1072#1085#1080#1081' '#1101#1082#1079#1072#1084#1077#1085#1072#1094#1080#1086#1085#1085#1099#1081' '#1083#1080#1089#1090
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel4_1: TQRLabel
        Left = 14
        Top = 259
        Width = 274
        Height = 16
        Size.Values = (
          42.333333333333330000
          37.041666666666670000
          685.270833333333300000
          724.958333333333300000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1076#1086#1083#1078#1077#1085' '#1073#1099#1090#1100' '#1074#1086#1079#1074#1088#1072#1097#1077#1085' '#1074' '#1087#1088#1080#1077#1084#1085#1091#1102' '#1082#1086#1084#1080#1089#1089#1080#1102'.'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel5_1: TQRLabel
        Left = 1
        Top = 288
        Width = 381
        Height = 18
        Size.Values = (
          47.625000000000000000
          2.645833333333333000
          762.000000000000000000
          1008.062500000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = '3. '#1055#1088#1080' '#1087#1086#1083#1091#1095#1077#1085#1080#1080' '#1085#1077#1091#1076#1086#1074#1083#1077#1090#1074#1086#1088#1080#1090#1077#1083#1100#1085#1086#1081' '#1086#1094#1077#1085#1082#1080' '#1101#1082#1079#1072#1084#1077#1085#1072#1094#1080#1086#1085#1085#1099#1081
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel6_1: TQRLabel
        Left = 14
        Top = 303
        Width = 170
        Height = 16
        Size.Values = (
          42.333333333333330000
          37.041666666666670000
          801.687500000000000000
          449.791666666666700000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1083#1080#1089#1090' '#1086#1089#1090#1072#1077#1090#1089#1103' '#1091' '#1101#1082#1079#1072#1084#1077#1085#1072#1090#1086#1088#1072'.'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel7_1: TQRLabel
        Left = 1
        Top = 330
        Width = 377
        Height = 16
        Size.Values = (
          42.333333333333330000
          2.645833333333333000
          873.125000000000000000
          997.479166666666700000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = '4. '#1053#1077' '#1079#1072#1095#1080#1089#1083#1077#1085#1085#1099#1077' '#1074' '#1091#1095#1077#1073#1085#1086#1077' '#1079#1072#1074#1077#1076#1077#1085#1080#1077' '#1087#1086#1083#1091#1095#1072#1102#1090' '#1089#1074#1086#1080' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel8_1: TQRLabel
        Left = 14
        Top = 349
        Width = 340
        Height = 16
        Size.Values = (
          42.333333333333330000
          37.041666666666670000
          923.395833333333300000
          899.583333333333300000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1074' '#1087#1088#1080#1077#1084#1085#1086#1081' '#1082#1086#1084#1080#1089#1089#1080#1080' '#1087#1086#1089#1083#1077' '#1089#1076#1072#1095#1080' '#1101#1082#1079#1072#1084#1077#1085#1072#1094#1080#1086#1085#1085#1086#1075#1086' '#1083#1080#1089#1090#1072'.'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel10_1: TQRLabel
        Left = 1
        Top = 377
        Width = 307
        Height = 16
        Size.Values = (
          42.333333333333330000
          2.645833333333333000
          997.479166666666700000
          812.270833333333300000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = '5. '#1040#1073#1080#1090#1091#1088#1080#1077#1085#1090#1099', '#1082#1086#1090#1086#1088#1099#1077' '#1086#1087#1086#1079#1076#1072#1083#1080' '#1080#1083#1080'  '#1085#1077' '#1103#1074#1080#1083#1080#1089#1100' '#1085#1072
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel11_1: TQRLabel
        Left = 14
        Top = 436
        Width = 297
        Height = 16
        Size.Values = (
          42.333333333333330000
          37.041666666666670000
          1153.583333333333000000
          785.812500000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1089#1077#1082#1088#1077#1090#1072#1088#1103' '#1087#1088#1080#1077#1084#1085#1086#1081' '#1082#1086#1084#1080#1089#1089#1080#1080', '#1074' '#1087#1077#1088#1080#1086#1076' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1103
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel16_1: TQRLabel
        Left = 536
        Top = 92
        Width = 422
        Height = 21
        Size.Values = (
          55.562500000000000000
          1418.166666666667000000
          243.416666666666700000
          1116.541666666667000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1041#1045#1051#1054#1056#1059#1057#1057#1050#1048#1049' '#1043#1054#1057#1059#1044#1040#1056#1057#1058#1042#1045#1053#1053#1067#1049' '#1059#1053#1048#1042#1045#1056#1057#1048#1058#1045#1058
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold, fsUnderline]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRLabel18_1: TQRLabel
        Left = 571
        Top = 170
        Width = 317
        Height = 23
        Size.Values = (
          60.854166666666670000
          1510.770833333333000000
          449.791666666666700000
          838.729166666666700000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1069#1050#1047#1040#1052#1045#1053#1040#1062#1048#1054#1053#1053#1067#1049' '#1051#1048#1057#1058'     '#8470
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 14
      end
      object QRLabel19_1: TQRLabel
        Left = 519
        Top = 347
        Width = 464
        Height = 20
        Size.Values = (
          52.916666666666670000
          1373.187500000000000000
          918.104166666666700000
          1227.666666666667000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1060#1086#1088#1084#1072' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103' _______________________________'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRLabel20_1: TQRLabel
        Left = 519
        Top = 416
        Width = 465
        Height = 20
        Size.Values = (
          52.916666666666670000
          1373.187500000000000000
          1100.666666666667000000
          1230.312500000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = '__________________________________________________________'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRLabel21_1: TQRLabel
        Left = 519
        Top = 446
        Width = 465
        Height = 20
        Size.Values = (
          52.916666666666670000
          1373.187500000000000000
          1180.041666666667000000
          1230.312500000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1043#1088#1091#1087#1087#1072' '#8470'   ________________________________________________'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRLabel22_1: TQRLabel
        Left = 519
        Top = 215
        Width = 464
        Height = 20
        Size.Values = (
          52.916666666666670000
          1373.187500000000000000
          568.854166666666700000
          1227.666666666667000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1060#1072#1084#1080#1083#1080#1103'  _________________________________________________'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRLabel23_1: TQRLabel
        Left = 519
        Top = 248
        Width = 468
        Height = 20
        Size.Values = (
          52.916666666666670000
          1373.187500000000000000
          656.166666666666700000
          1238.250000000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1057#1086#1073#1089#1090#1074#1077#1085#1085#1086#1077' '#1080#1084#1103'   __________________________________________'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRLabel24_1: TQRLabel
        Left = 519
        Top = 281
        Width = 468
        Height = 20
        Size.Values = (
          52.916666666666670000
          1373.187500000000000000
          743.479166666666700000
          1238.250000000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1054#1090#1095#1077#1089#1090#1074#1086' ('#1077#1089#1083#1080' '#1090#1072#1082#1086#1074#1086#1077' '#1080#1084#1077#1077#1090#1089#1103') ______________________________'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRLabel25_1: TQRLabel
        Left = 522
        Top = 641
        Width = 143
        Height = 16
        Size.Values = (
          42.333333333333330000
          1381.125000000000000000
          1695.979166666667000000
          378.354166666666700000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1054#1090#1074#1077#1090#1089#1090#1074#1077#1085#1085#1099#1081' '#1089#1077#1082#1088#1077#1090#1072#1088#1100
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel26_1: TQRLabel
        Left = 522
        Top = 658
        Width = 464
        Height = 16
        Size.Values = (
          42.333333333333330000
          1381.125000000000000000
          1740.958333333333000000
          1227.666666666667000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = 
          #1087#1088#1080#1077#1084#1085#1086#1081' '#1082#1086#1084#1080#1089#1089#1080#1080'   ______________________                      ' +
          '       ______________'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel27_1: TQRLabel
        Left = 757
        Top = 566
        Width = 74
        Height = 16
        Size.Values = (
          42.333333333333330000
          2002.895833333333000000
          1497.541666666667000000
          195.791666666666700000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080':'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel28_1: TQRLabel
        Left = 792
        Top = 522
        Width = 116
        Height = 16
        Size.Values = (
          42.333333333333330000
          2095.500000000000000000
          1381.125000000000000000
          306.916666666666700000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = '('#1087#1086#1076#1087#1080#1089#1100' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1072')'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 9
      end
      object QRLabel29_1: TQRLabel
        Left = 696
        Top = 675
        Width = 298
        Height = 16
        Size.Values = (
          42.333333333333330000
          1841.500000000000000000
          1785.937500000000000000
          788.458333333333300000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = 
          '('#1087#1086#1076#1087#1080#1089#1100')                                               ('#1080#1085#1080#1094#1080#1072#1083 +
          #1099', '#1092#1072#1084#1080#1083#1080#1103')'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 9
      end
      object QRShape2_1: TQRShape
        Left = 536
        Top = 478
        Width = 100
        Height = 126
        Frame.Style = psDash
        Size.Values = (
          333.375000000000000000
          1418.166666666670000000
          1264.708333333330000000
          264.583333333333000000)
        XLColumn = 0
        Pen.Style = psDot
        Shape = qrsRectangle
        VertAdjust = 0
      end
      object QRDBText1_1: TQRDBText
        Left = 740
        Top = 343
        Width = 79
        Height = 21
        Size.Values = (
          55.562500000000000000
          1957.916666666667000000
          907.520833333333300000
          209.020833333333300000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Color = clWhite
        DataSet = DM.QReport_Rasp
        DataField = 'VID_EDU1'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FullJustify = False
        MaxBreakChars = 0
        FontSize = 12
      end
      object QRDBText3_1: TQRDBText
        Left = 604
        Top = 441
        Width = 105
        Height = 21
        Size.Values = (
          55.562500000000000000
          1598.083333333333000000
          1166.812500000000000000
          277.812500000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Color = clWhite
        DataSet = DM.QReport_Rasp
        DataField = 'NOM_GROUP'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FullJustify = False
        MaxBreakChars = 0
        FontSize = 12
      end
      object QRDBText4_1: TQRDBText
        Left = 652
        Top = 211
        Width = 37
        Height = 21
        Size.Values = (
          55.562500000000000000
          1725.083333333333000000
          558.270833333333300000
          97.895833333333330000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Color = clWhite
        DataSet = DM.QReport_Rasp
        DataField = 'FAM'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FullJustify = False
        MaxBreakChars = 0
        FontSize = 12
      end
      object QRDBText5_1: TQRDBText
        Left = 652
        Top = 244
        Width = 50
        Height = 21
        Size.Values = (
          55.562500000000000000
          1725.083333333333000000
          645.583333333333300000
          132.291666666666700000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Color = clWhite
        DataSet = DM.QReport_Rasp
        DataField = 'NAME'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FullJustify = False
        MaxBreakChars = 0
        FontSize = 12
      end
      object QRDBText6_1: TQRDBText
        Left = 756
        Top = 277
        Width = 46
        Height = 21
        Size.Values = (
          55.562500000000000000
          2000.250000000000000000
          732.895833333333300000
          121.708333333333300000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Color = clWhite
        DataSet = DM.QReport_Rasp
        DataField = 'OTCH'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FullJustify = False
        MaxBreakChars = 0
        FontSize = 12
      end
      object QRDBText7_1: TQRDBText
        Left = 902
        Top = 169
        Width = 110
        Height = 23
        Size.Values = (
          60.854166666666670000
          2386.541666666667000000
          447.145833333333300000
          291.041666666666700000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Color = clWhite
        DataSet = DM.QReport_Rasp
        DataField = 'NOM_DELA'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FullJustify = False
        MaxBreakChars = 0
        FontSize = 14
      end
      object QRDBText8_1: TQRDBText
        Left = 846
        Top = 566
        Width = 83
        Height = 17
        Size.Values = (
          44.979166666666670000
          2238.375000000000000000
          1497.541666666667000000
          219.604166666666700000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Color = clWhite
        DataSet = DM.QReport_Rasp
        DataField = 'DATE_PRIEM'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FullJustify = False
        MaxBreakChars = 0
        FontSize = 10
      end
      object QRLabel30_1: TQRLabel
        Left = 570
        Top = 508
        Width = 27
        Height = 15
        Size.Values = (
          39.687500000000000000
          1508.125000000000000000
          1344.083333333333000000
          71.437500000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1060#1086#1090#1086
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 8
      end
      object QRLabel31_1: TQRLabel
        Left = 539
        Top = 525
        Width = 96
        Height = 16
        Size.Values = (
          42.333333333333330000
          1426.104166666667000000
          1389.062500000000000000
          254.000000000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1080' '#1075#1077#1088#1073#1086#1074#1072#1103' '#1087#1077#1095#1072#1090#1100
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 8
      end
      object QRLabel32_1: TQRLabel
        Left = 568
        Top = 542
        Width = 28
        Height = 16
        Size.Values = (
          42.333333333333330000
          1502.833333333333000000
          1434.041666666667000000
          74.083333333333330000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1042#1059#1047#1072
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 8
      end
      object QRShape3_1: TQRShape
        Left = 750
        Top = 517
        Width = 200
        Height = 1
        Size.Values = (
          2.645833333333330000
          1984.375000000000000000
          1367.895833333330000000
          529.166666666667000000)
        XLColumn = 0
        Brush.Color = clBlack
        Shape = qrsRectangle
        VertAdjust = 0
      end
      object QRLabel34_1: TQRLabel
        Left = 642
        Top = 113
        Width = 214
        Height = 20
        Size.Values = (
          52.916666666666670000
          1698.625000000000000000
          298.979166666666700000
          566.208333333333300000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1060#1048#1047#1048#1063#1045#1057#1050#1054#1049' '#1050#1059#1051#1068#1058#1059#1056#1067
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold, fsUnderline]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRLabel35_1: TQRLabel
        Left = 14
        Top = 211
        Width = 282
        Height = 16
        Size.Values = (
          42.333333333333330000
          37.041666666666670000
          558.270833333333300000
          746.125000000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1089#1083#1091#1078#1080#1090' '#1087#1088#1086#1087#1091#1089#1082#1086#1084' '#1085#1072' '#1074#1089#1090#1091#1087#1080#1090#1077#1083#1100#1085#1099#1077' '#1080#1089#1087#1099#1090#1072#1085#1080#1103'.'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel36_1: TQRLabel
        Left = 14
        Top = 194
        Width = 328
        Height = 16
        Size.Values = (
          42.333333333333330000
          37.041666666666670000
          513.291666666666700000
          867.833333333333300000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1091#1076#1086#1089#1090#1086#1074#1077#1088#1077#1085#1080#1077#1084' '#1083#1080#1095#1085#1086#1089#1090#1080', '#1074#1099#1076#1072#1085#1085#1099#1084' '#1086#1088#1075#1072#1085#1072#1084#1080' '#1052#1042#1044' '#1056#1041','
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel37_1: TQRLabel
        Left = 14
        Top = 397
        Width = 386
        Height = 16
        Size.Values = (
          42.333333333333330000
          37.041666666666670000
          1050.395833333333000000
          1021.291666666667000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1074#1089#1090#1091#1087#1080#1090#1077#1083#1100#1085#1099#1077' '#1080#1089#1087#1099#1090#1072#1085#1080#1103' '#1087#1086' '#1091#1074#1072#1078#1080#1090#1077#1083#1100#1085#1086#1081' '#1087#1088#1080#1095#1080#1085#1077', '#1076#1086#1087#1091#1089#1082#1072#1102#1090#1089#1103
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel38_1: TQRLabel
        Left = 14
        Top = 417
        Width = 325
        Height = 16
        Size.Values = (
          42.333333333333330000
          37.041666666666670000
          1103.312500000000000000
          859.895833333333300000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1082' '#1080#1093' '#1089#1076#1072#1095#1077' '#1087#1086' '#1088#1077#1096#1077#1085#1080#1102' '#1087#1088#1077#1076#1089#1077#1076#1072#1090#1077#1083#1103' '#1080#1083#1080' '#1086#1090#1074#1077#1090#1089#1090#1074#1077#1085#1085#1086#1075#1086
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel39_1: TQRLabel
        Left = 519
        Top = 370
        Width = 426
        Height = 20
        Size.Values = (
          52.916666666666670000
          1373.187500000000000000
          978.958333333333300000
          1127.125000000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1057#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1100' ('#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1080', '#1089#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103')'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRLabel40_1: TQRLabel
        Left = 14
        Top = 456
        Width = 158
        Height = 16
        Size.Values = (
          42.333333333333330000
          37.041666666666670000
          1206.500000000000000000
          418.041666666666700000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1074#1089#1090#1091#1087#1080#1090#1077#1083#1100#1085#1099#1093' '#1080#1089#1087#1099#1090#1072#1085#1080#1081'.'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRImage1_1: TQRImage
        Left = 537
        Top = 480
        Width = 98
        Height = 123
        Frame.Color = clHighlightText
        Frame.Style = psClear
        Size.Values = (
          325.437500000000000000
          1420.812500000000000000
          1270.000000000000000000
          259.291666666667000000)
        XLColumn = 0
        Stretch = True
      end
      object QRLabel9_1: TQRLabel
        Left = 668
        Top = 138
        Width = 172
        Height = 20
        Size.Values = (
          52.916666666666670000
          1767.416666666667000000
          365.125000000000000000
          455.083333333333300000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1048#1053#1057#1058#1048#1058#1059#1058' '#1058#1059#1056#1048#1047#1052#1040
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold, fsUnderline]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRLabel13_1: TQRLabel
        Left = 519
        Top = 314
        Width = 467
        Height = 20
        Size.Values = (
          52.916666666666670000
          1373.187500000000000000
          830.791666666666700000
          1235.604166666667000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1060#1072#1082#1091#1083#1100#1090#1077#1090' _________________________________________________'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRDBText2_1: TQRDBText
        Left = 644
        Top = 310
        Width = 60
        Height = 21
        Size.Values = (
          55.562500000000000000
          1703.916666666667000000
          820.208333333333300000
          158.750000000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Color = clWhite
        DataSet = DM.QReport_Rasp
        DataField = 'N_FAC1'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FullJustify = False
        MaxBreakChars = 0
        FontSize = 12
      end
      object QRLabel14_1: TQRLabel
        Left = 888
        Top = 653
        Width = 84
        Height = 16
        Size.Values = (
          42.333333333333330000
          2349.500000000000000000
          1727.729166666667000000
          222.250000000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1040'.'#1040'. '#1045#1088#1084#1072#1082#1086#1074#1072
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel15_1: TQRLabel
        Left = 607
        Top = 607
        Width = 28
        Height = 16
        Size.Values = (
          42.333333333333330000
          1606.020833333333000000
          1606.020833333333000000
          74.083333333333330000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1052'.'#1055'.'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRRichText1_1: TQRRichText
        Left = 528
        Top = 391
        Width = 449
        Height = 41
        Size.Values = (
          108.479166666667000000
          1397.000000000000000000
          1034.520833333330000000
          1187.979166666670000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AutoStretch = False
        Color = clWindow
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        HiresExport = False
      end
      object QRLabel12_1: TQRLabel
        Left = 14
        Top = 544
        Width = 344
        Height = 20
        Size.Values = (
          52.916666666666670000
          37.041666666666670000
          1439.333333333333000000
          910.166666666666700000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1057' '#1088#1072#1089#1087#1080#1089#1072#1085#1080#1077#1084' '#1082#1086#1085#1089#1091#1083#1100#1090#1072#1094#1080#1081' '#1080' '#1074#1089#1090#1091#1087#1080#1090#1077#1083#1100#1085#1099#1093
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRLabel17_1: TQRLabel
        Left = 14
        Top = 568
        Width = 189
        Height = 20
        Size.Values = (
          52.916666666666670000
          37.041666666666670000
          1502.833333333333000000
          500.062500000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = #1080#1089#1087#1099#1090#1072#1085#1080#1081' '#1086#1079#1085#1072#1082#1086#1084#1083#1077#1085'('#1072')'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 12
      end
      object QRLabel33_1: TQRLabel
        Left = 242
        Top = 602
        Width = 183
        Height = 16
        Size.Values = (
          42.333333333333330000
          640.291666666666700000
          1592.791666666667000000
          484.187500000000000000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = '__________________________'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 10
      end
      object QRLabel41_1: TQRLabel
        Left = 272
        Top = 618
        Width = 116
        Height = 16
        Size.Values = (
          42.333333333333330000
          719.666666666666700000
          1635.125000000000000000
          306.916666666666700000)
        XLColumn = 0
        Alignment = taLeftJustify
        AlignToBand = False
        Caption = '('#1087#1086#1076#1087#1080#1089#1100' '#1072#1073#1080#1090#1091#1088#1080#1077#1085#1090#1072')'
        Color = clWhite
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        Transparent = False
        ExportAs = exptText
        WrapStyle = BreakOnSpaces
        FontSize = 9
      end
    end
  end
end
