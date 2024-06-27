object FormRepSelExerc: TFormRepSelExerc
  Left = 0
  Top = 0
  Caption = #1042#1099#1073#1088#1072#1085#1085#1099#1077' '#1082#1086#1085#1090#1088#1086#1083#1100#1085#1099#1077' '#1091#1087#1088#1072#1078#1085#1077#1085#1080#1103
  ClientHeight = 681
  ClientWidth = 1016
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object frxPreview1: TfrxPreview
    Left = 0
    Top = 0
    Width = 1016
    Height = 681
    Align = alClient
    OutlineVisible = True
    OutlineWidth = 121
    ThumbnailVisible = False
    UseReportHints = True
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    FieldAliases.Strings = (
      'NAME_EXERC=NAME_EXERC'
      'NUM_EXERC_GRP=NUM_EXERC_GRP')
    DataSet = DM.QRep_Sel_Exerc
    BCDToCurrency = False
    Left = 40
    Top = 280
  end
  object frxRep_Sel_Exerc: TfrxReport
    Version = '5.6.1'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 42183.633093750000000000
    ReportOptions.LastChange = 44729.435993344910000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 48
    Top = 168
    Datasets = <
      item
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
      end
      item
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
      end
      item
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset3'
      end
      item
        DataSet = frxDBDataset4
        DataSetName = 'frxDBDataset4'
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
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        Height = 22.677180000000000000
        ParentFont = False
        Top = 16.000000000000000000
        Width = 718.110700000000000000
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        Height = 49.133890000000000000
        Top = 352.000000000000000000
        Width = 718.110700000000000000
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
        RowCount = 0
        object frxDBDataset1NUM_EXERC_GRP1: TfrxMemoView
          Width = 37.795300000000000000
          Height = 49.133890000000000000
          DataField = 'NUM_EXERC_GRP'
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."NUM_EXERC_GRP"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object frxDBDataset1NAME_EXERC: TfrxMemoView
          Left = 37.795300000000000000
          Width = 680.315400000000000000
          Height = 49.133890000000000000
          DataField = 'NAME_EXERC'
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            '[frxDBDataset1."NAME_EXERC"]')
          ParentFont = False
          VAlign = vaCenter
        end
      end
      object PageFooter1: TfrxPageFooter
        FillType = ftBrush
        Height = 22.677180000000000000
        Top = 652.000000000000000000
        Width = 718.110700000000000000
      end
      object Header1: TfrxHeader
        FillType = ftBrush
        Height = 230.551330000000000000
        Top = 100.000000000000000000
        Width = 718.110700000000000000
        object Memo4: TfrxMemoView
          Top = 86.929190000000000000
          Width = 721.890230000000000000
          Height = 30.236240000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            
              '[frxDBDataset2."FAM"] [frxDBDataset2."NAME"] [frxDBDataset2."OTC' +
              'H"]')
          ParentFont = False
        end
        object Memo1: TfrxMemoView
          Top = 11.338590000000000000
          Width = 718.110700000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          HAlign = haCenter
          Memo.UTF8W = (
            #1042#1099#1073#1086#1088' '#1082#1086#1085#1090#1088#1086#1083#1100#1085#1099#1093' '#1091#1087#1088#1072#1078#1085#1077#1085#1080#1081)
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          Top = 181.417440000000000000
          Width = 71.811070000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1043#1088#1091#1087#1087#1072':')
          ParentFont = False
        end
        object frxDBDataset2NOM_GROUP: TfrxMemoView
          Left = 71.811070000000000000
          Top = 181.417440000000000000
          Width = 41.574830000000000000
          Height = 22.677180000000000000
          DataField = 'NOM_GROUP'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset2."NOM_GROUP"]')
          ParentFont = False
        end
        object frxDBDataset3SPECIAL_DIRECTION: TfrxMemoView
          Left = 260.787570000000000000
          Top = 124.724490000000000000
          Width = 457.323130000000000000
          Height = 56.692950000000000000
          DataField = 'SPECIAL_DIRECTION'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset3."SPECIAL_DIRECTION"]')
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          Top = 124.724490000000000000
          Width = 249.448980000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1089#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1080':')
          ParentFont = False
        end
        object frxDBDataset4FAC: TfrxMemoView
          Top = 49.133890000000000000
          Width = 718.110700000000000000
          Height = 37.795300000000000000
          DataField = 'FAC'
          DataSet = frxDBDataset4
          DataSetName = 'frxDBDataset4'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset4."FAC"]')
          ParentFont = False
        end
      end
      object Footer1: TfrxFooter
        FillType = ftBrush
        Height = 113.385900000000000000
        Top = 420.000000000000000000
        Width = 718.110700000000000000
        object Memo2: TfrxMemoView
          Left = 181.417440000000000000
          Top = 94.488250000000000000
          Width = 347.716760000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftBottom]
          ParentFont = False
        end
        object Time: TfrxMemoView
          Left = 94.488250000000000000
          Top = 94.488250000000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          DisplayFormat.FormatStr = 'hh:mm'
          DisplayFormat.Kind = fkDateTime
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[Time]')
          ParentFont = False
        end
        object Date: TfrxMemoView
          Top = 94.488250000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[Date]')
          ParentFont = False
        end
      end
      object frxDBDataset1NUM_EXERC_GRP: TfrxMemoView
        Left = 1421.103280000000000000
        Top = 49.133890000000000000
        Width = 79.370130000000000000
        Height = 34.015770000000000000
        DataField = 'NUM_EXERC_GRP'
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '[frxDBDataset1."NUM_EXERC_GRP"]')
        ParentFont = False
      end
      object MasterData2: TfrxMasterData
        FillType = ftBrush
        Height = 41.574830000000000000
        Top = 552.000000000000000000
        Width = 718.110700000000000000
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
        RowCount = 0
      end
    end
  end
  object frxDBDataset2: TfrxDBDataset
    UserName = 'frxDBDataset2'
    CloseDataSource = False
    DataSet = DM.QRep_Abitura
    BCDToCurrency = False
    Left = 40
    Top = 352
  end
  object frxDBDataset3: TfrxDBDataset
    UserName = 'frxDBDataset3'
    CloseDataSource = False
    DataSet = DM.QKod_Spec
    BCDToCurrency = False
    Left = 40
    Top = 432
  end
  object frxDBDataset4: TfrxDBDataset
    UserName = 'frxDBDataset4'
    CloseDataSource = False
    DataSet = DM.QKod_Fac
    BCDToCurrency = False
    Left = 40
    Top = 496
  end
end
