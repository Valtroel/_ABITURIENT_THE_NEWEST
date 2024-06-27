object MyFList: TMyFList
  Left = 235
  Top = 130
  Width = 540
  Height = 397
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 532
    Height = 41
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 32
      Top = 16
      Width = 3
      Height = 13
    end
    object Label2: TLabel
      Left = 304
      Top = 16
      Width = 3
      Height = 13
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 315
    Width = 532
    Height = 55
    Align = alBottom
    TabOrder = 1
    object OKButton: TBitBtn
      Left = 56
      Top = 16
      Width = 75
      Height = 25
      Default = True
      TabOrder = 0
      OnClick = OKButtonClick
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333330000333333333333333333333333F33333333333
        00003333344333333333333333388F3333333333000033334224333333333333
        338338F3333333330000333422224333333333333833338F3333333300003342
        222224333333333383333338F3333333000034222A22224333333338F338F333
        8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
        33333338F83338F338F33333000033A33333A222433333338333338F338F3333
        0000333333333A222433333333333338F338F33300003333333333A222433333
        333333338F338F33000033333333333A222433333333333338F338F300003333
        33333333A222433333333333338F338F00003333333333333A22433333333333
        3338F38F000033333333333333A223333333333333338F830000333333333333
        333A333333333333333338330000333333333333333333333333333333333333
        0000}
      NumGlyphs = 2
    end
    object ExitButton: TBitBtn
      Left = 395
      Top = 16
      Width = 77
      Height = 25
      TabOrder = 1
      OnClick = ExitButtonClick
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00388888888877
        F7F787F8888888888333333F00004444400888FFF444448888888888F333FF8F
        000033334D5007FFF4333388888888883338888F0000333345D50FFFF4333333
        338F888F3338F33F000033334D5D0FFFF43333333388788F3338F33F00003333
        45D50FEFE4333333338F878F3338F33F000033334D5D0FFFF43333333388788F
        3338F33F0000333345D50FEFE4333333338F878F3338F33F000033334D5D0FFF
        F43333333388788F3338F33F0000333345D50FEFE4333333338F878F3338F33F
        000033334D5D0EFEF43333333388788F3338F33F0000333345D50FEFE4333333
        338F878F3338F33F000033334D5D0EFEF43333333388788F3338F33F00003333
        4444444444333333338F8F8FFFF8F33F00003333333333333333333333888888
        8888333F00003333330000003333333333333FFFFFF3333F00003333330AAAA0
        333333333333888888F3333F00003333330000003333333333338FFFF8F3333F
        0000}
      NumGlyphs = 2
      Style = bsNew
    end
  end
  object Panel3: TPanel
    Left = 242
    Top = 41
    Width = 49
    Height = 274
    Align = alRight
    TabOrder = 2
    object BitBtn4: TBitBtn
      Left = 11
      Top = 24
      Width = 25
      Height = 25
      Caption = '>'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = BitBtn4Click
    end
    object BitBtn6: TBitBtn
      Left = 11
      Top = 185
      Width = 25
      Height = 25
      Caption = '<'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = BitBtn6Click
    end
    object BitBtn7: TBitBtn
      Left = 11
      Top = 224
      Width = 25
      Height = 25
      Caption = '<<'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = BitBtn7Click
    end
    object BitBtn5: TBitBtn
      Left = 11
      Top = 62
      Width = 25
      Height = 25
      Caption = '>>'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = BitBtn5Click
    end
  end
  object Panel4: TPanel
    Left = 291
    Top = 41
    Width = 241
    Height = 274
    Align = alRight
    TabOrder = 3
    object ListBox2: TListBox
      Left = 1
      Top = 1
      Width = 239
      Height = 272
      Align = alClient
      ItemHeight = 13
      MultiSelect = True
      Sorted = True
      TabOrder = 0
      OnDblClick = ListBox2DblClick
    end
  end
  object Panel5: TPanel
    Left = 0
    Top = 41
    Width = 242
    Height = 274
    Align = alClient
    TabOrder = 4
    object ListBox1: TListBox
      Left = 1
      Top = 1
      Width = 240
      Height = 272
      Align = alClient
      ItemHeight = 13
      MultiSelect = True
      Sorted = True
      TabOrder = 0
      OnDblClick = ListBox1DblClick
    end
  end
end
