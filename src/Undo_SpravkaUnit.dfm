object Undo_SpravkaForm: TUndo_SpravkaForm
  Left = 309
  Top = 155
  Caption = ' '
  ClientHeight = 325
  ClientWidth = 484
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 268
    Width = 484
    Height = 57
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object BitBtn1: TBitBtn
      Left = 183
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
      Spacing = 10
      TabOrder = 0
      OnClick = BitBtn1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 484
    Height = 268
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object DBGrid1: TDBGrid
      Left = 2
      Top = 2
      Width = 480
      Height = 264
      Align = alClient
      Color = 15856113
      DataSource = DM.DSUndo_Abit
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -10
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      Columns = <
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
          Width = 165
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
          Width = 136
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
          Width = 177
          Visible = True
        end>
    end
  end
end
