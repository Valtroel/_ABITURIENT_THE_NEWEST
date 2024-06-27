object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 319
  ClientWidth = 593
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object FDConnection1: TFDConnection
    Params.Strings = (
      'Database=dekanat'
      'Protocol=TCPIP'
      'User_Name=SYSDBA'
      'Password=dbudfV544703'
      'Server=172.16.1.30'
      'DriverID=FB')
    FetchOptions.AssignedValues = [evMode]
    FetchOptions.Mode = fmAll
    LoginPrompt = False
    Left = 112
    Top = 64
  end
  object TFaculty: TFDTable
    CachedUpdates = True
    IndexFieldNames = 'N_FAC'
    Connection = FDConnection1
    FetchOptions.AssignedValues = [evMode]
    FetchOptions.Mode = fmAll
    UpdateOptions.UpdateTableName = 'FACULTY'
    TableName = 'FACULTY'
    Left = 24
    Top = 64
    object TFacultyN_FAC: TSmallintField
      FieldName = 'N_FAC'
      Origin = 'N_FAC'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object TFacultyFAC: TStringField
      FieldName = 'FAC'
      Origin = 'FAC'
      Size = 70
    end
    object TFacultyFAC1: TStringField
      FieldName = 'FAC1'
      Origin = 'FAC1'
    end
    object TFacultyKOD_FAC: TSmallintField
      FieldName = 'KOD_FAC'
      Origin = 'KOD_FAC'
    end
    object TFacultyDEAN: TStringField
      FieldName = 'DEAN'
      Origin = 'DEAN'
      Size = 30
    end
    object TFacultyFAC_RP: TStringField
      FieldName = 'FAC_RP'
      Origin = 'FAC_RP'
      Size = 70
    end
  end
  object FDConnection2: TFDConnection
    Params.Strings = (
      'Database=abiturient'
      'User_Name=SYSDBA'
      'Password=dbudfV544703'
      'Protocol=TCPIP'
      'Server=172.16.1.30'
      'CharacterSet=WIN1251'
      'DriverID=FB')
    FetchOptions.AssignedValues = [evMode]
    FetchOptions.Mode = fmAll
    LoginPrompt = False
    Left = 208
    Top = 64
  end
  object QPlan_Priem_Konk_All_Param: TFDQuery
    CachedUpdates = True
    Connection = FDConnection2
    SQL.Strings = (
      'SELECT'
      '    kol_place.n_specializ,'
      '    kol_place.kol_place'
      'FROM'
      '    kol_place'
      'WHERE'
      '        kol_place.n_fac   = :N_FAC'
      '    AND'
      '        kol_place.vid_edu = :VID_EDU'
      '    AND'
      '        kol_place.text    = :TEXT'
      '    AND'
      '        kol_place.price   = :PRICE'
      '    AND'
      '        kol_place.recruit = 1')
    Left = 336
    Top = 112
    ParamData = <
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'TEXT'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QPlan_Priem_Konk_All_ParamN_SPECIALIZ: TSmallintField
      FieldName = 'N_SPECIALIZ'
      Origin = 'N_SPECIALIZ'
    end
    object QPlan_Priem_Konk_All_ParamKOL_PLACE: TSmallintField
      FieldName = 'KOL_PLACE'
      Origin = 'KOL_PLACE'
    end
    object QPlan_Priem_Konk_All_ParamSPECIALIZ2: TStringField
      FieldKind = fkLookup
      FieldName = 'SPECIALIZ2'
      LookupDataSet = QSpecializ
      LookupKeyFields = 'N_SPECIALIZ'
      LookupResultField = 'SPECIAL'
      KeyFields = 'N_SPECIALIZ'
      Size = 225
      Lookup = True
    end
  end
  object Stat3hAll1Qr: TFDQuery
    Connection = FDConnection2
    SQL.Strings = (
      'SELECT'
      '    abitura.konkurs,'
      '    COUNT'
      '    ('
      '        abitura.nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        abitura.status  = 0'
      '    AND'
      '        abitura.n_fac   = :n_fac'
      '    AND'
      '        abitura.vid_edu = :vid_edu'
      '    AND'
      '        ('
      '            abitura.term_edu = 0'
      '         OR'
      '            abitura.term_edu = 3'
      '        )'
      '    AND'
      '        abitura.price       = :price'
      '    AND'
      '        abitura.n_specializ = :n_specializ'
      '    AND'
      '        (   abitura.category_if = 0'
      '         OR'
      '            abitura.category_if = 1'
      '         AND'
      '            abitura.price       = 0'
      '        )'
      'GROUP BY'
      '    abitura.konkurs')
    Left = 336
    Top = 160
    ParamData = <
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_SPECIALIZ'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object Stat3hAll1QrKONKURS: TSmallintField
      FieldName = 'KONKURS'
      Origin = 'KONKURS'
    end
    object Stat3hAll1QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = '"COUNT"'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object Stat3hAll2Qr: TFDQuery
    Connection = FDConnection2
    SQL.Strings = (
      'SELECT'
      '    abitura.konkurs,'
      '    COUNT'
      '    ('
      '        abitura.nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        abitura.status = 0'
      '    AND'
      '        abitura.n_fac   = :n_fac'
      '    AND'
      '        abitura.vid_edu = :vid_edu'
      '    AND'
      '        ('
      '            abitura.term_edu = 1'
      '         OR'
      '            abitura.term_edu = 2'
      '        )'
      '    AND'
      '        abitura.price       = :price'
      '    AND'
      '        abitura.n_specializ = :n_specializ'
      '    AND'
      '        abitura.category_if = 0'
      'GROUP BY'
      '    abitura.konkurs')
    Left = 336
    Top = 208
    ParamData = <
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_SPECIALIZ'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object Stat3hAll2QrKONKURS: TSmallintField
      FieldName = 'KONKURS'
      Origin = 'KONKURS'
    end
    object Stat3hAll2QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = '"COUNT"'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QCK_Kol_Plan: TFDQuery
    Connection = FDConnection2
    SQL.Strings = (
      'SELECT'
      '    ck_plan.kol_place'
      'FROM'
      '    ck_plan'
      'WHERE'
      '        ck_plan.n_specializ =  :N_SPECIALIZ'
      '    AND'
      '        ck_plan.term_educ   IN ('
      '            :TERM_EDUC - 1,'
      '            :TERM_EDUC'
      '        )')
    Left = 336
    Top = 16
    ParamData = <
      item
        Name = 'N_SPECIALIZ'
        DataType = ftSmallint
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'TERM_EDUC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCK_Kol_PlanKOL_PLACE: TSmallintField
      FieldName = 'KOL_PLACE'
      Origin = 'KOL_PLACE'
    end
  end
  object QStatistic_Every_Day_Ball_Price: TFDQuery
    Connection = FDConnection2
    SQL.Strings = (
      'SELECT'
      '    konkurs,'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status      = 0'
      '    AND'
      '        n_fac       = :N_FAC'
      '    AND'
      '        vid_edu     = :VID_EDU'
      '    AND'
      '        price       = :PRICE'
      '    AND'
      '        n_specializ = :N_SP'
      'GROUP BY'
      '    konkurs,'
      '    price')
    Left = 336
    Top = 64
    ParamData = <
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_SP'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QStatistic_Every_Day_Ball_PriceKONKURS: TSmallintField
      FieldName = 'KONKURS'
      Origin = 'KONKURS'
    end
    object QStatistic_Every_Day_Ball_PriceCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = '"COUNT"'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QSpecializ: TFDQuery
    CachedUpdates = True
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT'
      '    n_specializ,'
      '    code_specializ,'
      '    special,'
      '    n_fac,'
      '    n_spec,'
      '    special_direction'
      'FROM'
      '    specializ'
      'WHERE'
      '        n_specializ <> 2 -- MANAGEMENT'
      '    AND'
      '        n_specializ <> 5 -- HEALTH IMPROVEMENT'
      '    AND'
      '        n_specializ <> 6 -- PRESCHOOLERS'
      '    AND'
      '        n_fac       =  :N_FAC'
      'ORDER BY'
      '    special')
    Left = 24
    Top = 16
    ParamData = <
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QSpecializN_SPECIALIZ: TSmallintField
      FieldName = 'N_SPECIALIZ'
      Origin = 'N_SPECIALIZ'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object QSpecializCODE_SPECIALIZ: TStringField
      FieldName = 'CODE_SPECIALIZ'
      Origin = 'CODE_SPECIALIZ'
      Size = 15
    end
    object QSpecializSPECIAL: TStringField
      FieldName = 'SPECIAL'
      Origin = 'SPECIAL'
      Size = 80
    end
    object QSpecializN_FAC: TSmallintField
      FieldName = 'N_FAC'
      Origin = 'N_FAC'
    end
    object QSpecializN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
    object QSpecializSPECIAL_DIRECTION: TStringField
      FieldName = 'SPECIAL_DIRECTION'
      Origin = 'SPECIAL_DIRECTION'
      Size = 255
    end
  end
  object RaspredBallStrdPrc: TFDStoredProc
    Connection = FDConnection2
    StoredProcName = 'KOL_SUMM_BALL3'
    Left = 512
    Top = 112
    ParamData = <
      item
        Position = 1
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Position = 2
        Name = 'N_SP'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Position = 3
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Position = 4
        Name = 'PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Position = 5
        Name = 'N1_2'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 6
        Name = 'N2_3'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 7
        Name = 'N3_4'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 8
        Name = 'N4_5'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 9
        Name = 'N5_6'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 10
        Name = 'N6_7'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 11
        Name = 'N7_8'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 12
        Name = 'N8_9'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 13
        Name = 'N9_10'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 14
        Name = 'N10_11'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 15
        Name = 'N11_12'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 16
        Name = 'N12_13'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 17
        Name = 'N13_14'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 18
        Name = 'N14_15'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 19
        Name = 'N15_16'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 20
        Name = 'N16_17'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 21
        Name = 'N17_18'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 22
        Name = 'N18_19'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 23
        Name = 'N19_20'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 24
        Name = 'N20_21'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 25
        Name = 'N21_22'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 26
        Name = 'N22_23'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 27
        Name = 'N23_24'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 28
        Name = 'N24_25'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 29
        Name = 'N25_26'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 30
        Name = 'N26_27'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 31
        Name = 'N27_28'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 32
        Name = 'N28_29'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 33
        Name = 'N29_30'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 34
        Name = 'N30_31'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 35
        Name = 'N31_32'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 36
        Name = 'N32_33'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 37
        Name = 'N33_34'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 38
        Name = 'N34_35'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 39
        Name = 'N35_36'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 40
        Name = 'N36_37'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 41
        Name = 'N37_38'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 42
        Name = 'N38_39'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 43
        Name = 'N39_40'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 44
        Name = 'N40_41'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 45
        Name = 'N41_42'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 46
        Name = 'N42_43'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 47
        Name = 'N43_44'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 48
        Name = 'N44_45'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 49
        Name = 'N45_46'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 50
        Name = 'N46_47'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 51
        Name = 'N47_48'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 52
        Name = 'N48_49'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 53
        Name = 'N49_50'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 54
        Name = 'N50_51'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 55
        Name = 'N51_52'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 56
        Name = 'N52_53'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 57
        Name = 'N53_54'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 58
        Name = 'N54_55'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 59
        Name = 'N55_56'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 60
        Name = 'N56_57'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 61
        Name = 'N57_58'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 62
        Name = 'N58_59'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 63
        Name = 'N59_60'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 64
        Name = 'N60_61'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 65
        Name = 'N61_62'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 66
        Name = 'N62_63'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 67
        Name = 'N63_64'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 68
        Name = 'N64_65'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 69
        Name = 'N65_66'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 70
        Name = 'N66_67'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 71
        Name = 'N67_68'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 72
        Name = 'N68_69'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 73
        Name = 'N69_70'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 74
        Name = 'N70_71'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 75
        Name = 'N71_72'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 76
        Name = 'N72_73'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 77
        Name = 'N73_74'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 78
        Name = 'N74_75'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 79
        Name = 'N75_76'
        DataType = ftSmallint
        ParamType = ptOutput
      end>
  end
  object RaspredBall12StrdPrc: TFDStoredProc
    Connection = FDConnection2
    StoredProcName = 'KOL_SUMM_BALL12'
    Left = 512
    Top = 16
    ParamData = <
      item
        Position = 1
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Position = 2
        Name = 'PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Position = 3
        Name = 'N1_2'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 4
        Name = 'N2_3'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 5
        Name = 'N3_4'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 6
        Name = 'N4_5'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 7
        Name = 'N5_6'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 8
        Name = 'N6_7'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 9
        Name = 'N7_8'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 10
        Name = 'N8_9'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 11
        Name = 'N9_10'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 12
        Name = 'N10_11'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 13
        Name = 'N11_12'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 14
        Name = 'N12_13'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 15
        Name = 'N13_14'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 16
        Name = 'N14_15'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 17
        Name = 'N15_16'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 18
        Name = 'N16_17'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 19
        Name = 'N17_18'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 20
        Name = 'N18_19'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 21
        Name = 'N19_20'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 22
        Name = 'N20_21'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 23
        Name = 'N21_22'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 24
        Name = 'N22_23'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 25
        Name = 'N23_24'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 26
        Name = 'N24_25'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 27
        Name = 'N25_26'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 28
        Name = 'N26_27'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 29
        Name = 'N27_28'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 30
        Name = 'N28_29'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 31
        Name = 'N29_30'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 32
        Name = 'N30_31'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 33
        Name = 'N31_32'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 34
        Name = 'N32_33'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 35
        Name = 'N33_34'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 36
        Name = 'N34_35'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 37
        Name = 'N35_36'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 38
        Name = 'N36_37'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 39
        Name = 'N37_38'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 40
        Name = 'N38_39'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 41
        Name = 'N39_40'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 42
        Name = 'N40_41'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 43
        Name = 'N41_42'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 44
        Name = 'N42_43'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 45
        Name = 'N43_44'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 46
        Name = 'N44_45'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 47
        Name = 'N45_46'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 48
        Name = 'N46_47'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 49
        Name = 'N47_48'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 50
        Name = 'N48_49'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 51
        Name = 'N49_50'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 52
        Name = 'N50_51'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 53
        Name = 'N51_52'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 54
        Name = 'N52_53'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 55
        Name = 'N53_54'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 56
        Name = 'N54_55'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 57
        Name = 'N55_56'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 58
        Name = 'N56_57'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 59
        Name = 'N57_58'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 60
        Name = 'N58_59'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 61
        Name = 'N59_60'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 62
        Name = 'N60_61'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 63
        Name = 'N61_62'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 64
        Name = 'N62_63'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 65
        Name = 'N63_64'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 66
        Name = 'N64_65'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 67
        Name = 'N65_66'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 68
        Name = 'N66_67'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 69
        Name = 'N67_68'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 70
        Name = 'N68_69'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 71
        Name = 'N69_70'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 72
        Name = 'N70_71'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 73
        Name = 'N71_72'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 74
        Name = 'N72_73'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 75
        Name = 'N73_74'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 76
        Name = 'N74_75'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 77
        Name = 'N75_76'
        DataType = ftSmallint
        ParamType = ptOutput
      end>
  end
  object RaspredBall34StrdPrc: TFDStoredProc
    Connection = FDConnection2
    StoredProcName = 'KOL_SUMM_BALL4'
    Left = 512
    Top = 64
    ParamData = <
      item
        Position = 1
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Position = 2
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Position = 3
        Name = 'PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Position = 4
        Name = 'N_SP'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 5
        Name = 'N1_2'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 6
        Name = 'N2_3'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 7
        Name = 'N3_4'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 8
        Name = 'N4_5'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 9
        Name = 'N5_6'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 10
        Name = 'N6_7'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 11
        Name = 'N7_8'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 12
        Name = 'N8_9'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 13
        Name = 'N9_10'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 14
        Name = 'N10_11'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 15
        Name = 'N11_12'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 16
        Name = 'N12_13'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 17
        Name = 'N13_14'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 18
        Name = 'N14_15'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 19
        Name = 'N15_16'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 20
        Name = 'N16_17'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 21
        Name = 'N17_18'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 22
        Name = 'N18_19'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 23
        Name = 'N19_20'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 24
        Name = 'N20_21'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 25
        Name = 'N21_22'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 26
        Name = 'N22_23'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 27
        Name = 'N23_24'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 28
        Name = 'N24_25'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 29
        Name = 'N25_26'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 30
        Name = 'N26_27'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 31
        Name = 'N27_28'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 32
        Name = 'N28_29'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 33
        Name = 'N29_30'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 34
        Name = 'N30_31'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 35
        Name = 'N31_32'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 36
        Name = 'N32_33'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 37
        Name = 'N33_34'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 38
        Name = 'N34_35'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 39
        Name = 'N35_36'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 40
        Name = 'N36_37'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 41
        Name = 'N37_38'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 42
        Name = 'N38_39'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 43
        Name = 'N39_40'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 44
        Name = 'N40_41'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 45
        Name = 'N41_42'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 46
        Name = 'N42_43'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 47
        Name = 'N43_44'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 48
        Name = 'N44_45'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 49
        Name = 'N45_46'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 50
        Name = 'N46_47'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 51
        Name = 'N47_48'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 52
        Name = 'N48_49'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 53
        Name = 'N49_50'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 54
        Name = 'N50_51'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 55
        Name = 'N51_52'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 56
        Name = 'N52_53'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 57
        Name = 'N53_54'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 58
        Name = 'N54_55'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 59
        Name = 'N55_56'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 60
        Name = 'N56_57'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 61
        Name = 'N57_58'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 62
        Name = 'N58_59'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 63
        Name = 'N59_60'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 64
        Name = 'N60_61'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 65
        Name = 'N61_62'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 66
        Name = 'N62_63'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 67
        Name = 'N63_64'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 68
        Name = 'N64_65'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 69
        Name = 'N65_66'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 70
        Name = 'N66_67'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 71
        Name = 'N67_68'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 72
        Name = 'N68_69'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 73
        Name = 'N69_70'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 74
        Name = 'N70_71'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 75
        Name = 'N71_72'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 76
        Name = 'N72_73'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 77
        Name = 'N73_74'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 78
        Name = 'N74_75'
        DataType = ftSmallint
        ParamType = ptOutput
      end
      item
        Position = 79
        Name = 'N75_76'
        DataType = ftSmallint
        ParamType = ptOutput
      end>
  end
  object Stat3hAll2Qr2: TFDQuery
    Connection = FDConnection2
    SQL.Strings = (
      'SELECT'
      '    konkurs,'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status = 0'
      '    AND'
      '        ('
      '            n_fac = 1'
      '         OR'
      '            n_fac = 2'
      '        )'
      '    AND'
      '        vid_edu = :vid_edu'
      '    AND'
      '        ('
      '            term_edu = 1'
      '         OR'
      '            term_edu = 2'
      '        )'
      '    AND'
      '        price       = :price'
      '    AND'
      '        category_if = 0'
      'GROUP BY'
      '    konkurs')
    Left = 336
    Top = 256
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object Stat3hAll2Qr2KONKURS: TSmallintField
      FieldName = 'KONKURS'
      Origin = 'KONKURS'
    end
    object Stat3hAll2Qr2COUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = '"COUNT"'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object FDPhysFBDriverLink1: TFDPhysFBDriverLink
    VendorLib = 'D:\Abitur_RIO\fbclient\fbclient.dll'
    Left = 160
    Top = 16
  end
end
