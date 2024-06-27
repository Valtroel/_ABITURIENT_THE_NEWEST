object DMVed: TDMVed
  OldCreateOrder = False
  Height = 240
  Width = 720
  object DSQKol_Place: TDataSource
    DataSet = QKol_Place
    Left = 96
    Top = 128
  end
  object DSQ_All_Mas: TDataSource
    DataSet = QAll_Mas
    Left = 32
    Top = 128
  end
  object DSGorod: TDataSource
    DataSet = QGorod
    Left = 64
    Top = 128
  end
  object DSPredm: TDataSource
    DataSet = QPredm
    Left = 128
    Top = 128
  end
  object DSPredmet_Ball: TDataSource
    DataSet = QPredmet_Ball
    Left = 160
    Top = 128
  end
  object QGorod: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    abitura.nomer_ab AS out_nomer_ab,'
      '    abitura.sum_ball AS out_sum_ball,'
      '    abitura.fam AS out_f,'
      '    abitura.name AS out_n,'
      '    abitura.otch AS out_o,'
      '    abitura.nom_dela AS out_n_delo,'
      '    abitura.date_r AS out_date_r,'
      '    abitura.pol AS out_pol,'
      '    abitura.name_edu_middle AS out_name_e_m,'
      '    abitura.name_edu_spec AS out_name_e_s,'
      '    abitura.when_edu_middle AS out_when_e_m,'
      '    abitura.when_edu_spec AS out_when_e_s,'
      '    abitura.stag AS out_stag,'
      '    abitura.stag_spec AS out_stag_sp,'
      '    category.sport_category AS out_sport,'
      '    abitura.middle_ball AS out_mid_b,'
      '    abitura.address_before AS out_address,'
      '    abitura.copy_at AS out_copy_at,'
      '    abitura.v_k AS out_v_k,'
      '    abitura.priv AS out_priv,'
      '    abitura.without AS out_without,'
      '    abitura.n_region AS out_region,'
      '    abitura.n_centre AS out_centre,'
      '    abitura.fam || #39 #39|| abitura.name || #39 #39 || abitura.otch  AS out_fio,'
      '    abitura.n_ck AS out_n_ck'
      'FROM'
      '    abitura'
      '        LEFT JOIN'
      '            category'
      '        ON'
      '            abitura.n_sport_category = category.n_sport_category'
      'WHERE'
      '        abitura.nomer_ab IN (:in_mas_n_ab)'
      '    AND'
      '        abitura.price    =  :in_price'
      'ORDER BY'
      '    abitura.sum_ball DESC,'
      '    abitura.priv,'
      '    abitura.middle_ball DESC')
    Left = 64
    Top = 176
    ParamData = <
      item
        Name = 'IN_MAS_N_AB'
        DataType = ftInteger
        ParamType = ptInput
      end
      item
        Name = 'IN_PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QGorodOUT_NOMER_AB: TIntegerField
      FieldName = 'OUT_NOMER_AB'
      Origin = 'NOMER_AB'
    end
    object QGorodOUT_SUM_BALL: TFloatField
      FieldName = 'OUT_SUM_BALL'
      Origin = 'SUM_BALL'
    end
    object QGorodOUT_F: TStringField
      FieldName = 'OUT_F'
      Origin = 'FAM'
      Size = 30
    end
    object QGorodOUT_N: TStringField
      FieldName = 'OUT_N'
      Origin = 'NAME'
      Size = 30
    end
    object QGorodOUT_O: TStringField
      FieldName = 'OUT_O'
      Origin = 'OTCH'
      Size = 30
    end
    object QGorodOUT_N_DELO: TSmallintField
      FieldName = 'OUT_N_DELO'
      Origin = 'NOM_DELA'
    end
    object QGorodOUT_DATE_R: TSQLTimeStampField
      FieldName = 'OUT_DATE_R'
      Origin = 'DATE_R'
    end
    object QGorodOUT_POL: TStringField
      FieldName = 'OUT_POL'
      Origin = 'POL'
      FixedChar = True
      Size = 1
    end
    object QGorodOUT_NAME_E_M: TStringField
      FieldName = 'OUT_NAME_E_M'
      Origin = 'NAME_EDU_MIDDLE'
      Size = 50
    end
    object QGorodOUT_NAME_E_S: TStringField
      FieldName = 'OUT_NAME_E_S'
      Origin = 'NAME_EDU_SPEC'
      Size = 50
    end
    object QGorodOUT_WHEN_E_M: TSmallintField
      FieldName = 'OUT_WHEN_E_M'
      Origin = 'WHEN_EDU_MIDDLE'
    end
    object QGorodOUT_WHEN_E_S: TSmallintField
      FieldName = 'OUT_WHEN_E_S'
      Origin = 'WHEN_EDU_SPEC'
    end
    object QGorodOUT_STAG: TFloatField
      FieldName = 'OUT_STAG'
      Origin = 'STAG'
    end
    object QGorodOUT_STAG_SP: TFloatField
      FieldName = 'OUT_STAG_SP'
      Origin = 'STAG_SPEC'
    end
    object QGorodOUT_SPORT: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'OUT_SPORT'
      Origin = 'SPORT_CATEGORY'
      ProviderFlags = []
      ReadOnly = True
      Size = 50
    end
    object QGorodOUT_MID_B: TFloatField
      FieldName = 'OUT_MID_B'
      Origin = 'MIDDLE_BALL'
    end
    object QGorodOUT_ADDRESS: TStringField
      FieldName = 'OUT_ADDRESS'
      Origin = 'ADDRESS_BEFORE'
      Size = 100
    end
    object QGorodOUT_COPY_AT: TSmallintField
      FieldName = 'OUT_COPY_AT'
      Origin = 'COPY_AT'
    end
    object QGorodOUT_V_K: TStringField
      FieldName = 'OUT_V_K'
      Origin = 'V_K'
      Size = 5
    end
    object QGorodOUT_PRIV: TStringField
      FieldName = 'OUT_PRIV'
      Origin = 'PRIV'
      Size = 50
    end
    object QGorodOUT_WITHOUT: TStringField
      FieldName = 'OUT_WITHOUT'
      Origin = 'WITHOUT'
      Size = 5
    end
    object QGorodOUT_REGION: TSmallintField
      FieldName = 'OUT_REGION'
      Origin = 'N_REGION'
    end
    object QGorodOUT_CENTRE: TIntegerField
      FieldName = 'OUT_CENTRE'
      Origin = 'N_CENTRE'
    end
    object QGorodOUT_FIO: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'OUT_FIO'
      Origin = 'OUT_FIO'
      ProviderFlags = []
      ReadOnly = True
      Size = 92
    end
    object QGorodOUT_N_CK: TSmallintField
      FieldName = 'OUT_N_CK'
      Origin = 'N_CK'
    end
  end
  object QDate: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    CAST'
      '    ('
      '        #39Today#39 AS date'
      '    )'
      'FROM'
      '    rdb$database')
    Left = 528
    Top = 128
    object QDateCAST: TDateField
      FieldName = 'CAST'
    end
  end
  object QKol_Place: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    text,'
      '    kol_place'
      'FROM'
      '    kol_place'
      'WHERE'
      '        n_specializ = :sp'
      '    AND'
      '        vid_edu     = :v_e'
      'ORDER BY'
      '    text')
    Left = 96
    Top = 176
    ParamData = <
      item
        Name = 'SP'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'V_E'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QKol_PlaceTEXT: TSmallintField
      FieldName = 'TEXT'
      Origin = 'TEXT'
    end
    object QKol_PlaceKOL_PLACE: TSmallintField
      FieldName = 'KOL_PLACE'
      Origin = 'KOL_PLACE'
    end
  end
  object QAll_Mas: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    *'
      'FROM'
      '    all_mas_konkurs'
      '    ('
      '        :n_sp,'
      '        :v_ed'
      '    )')
    Left = 32
    Top = 176
    ParamData = <
      item
        Name = 'N_SP'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'V_ED'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QAll_MasOUT_N_AB_ALL_M: TIntegerField
      FieldName = 'OUT_N_AB_ALL_M'
      Origin = 'OUT_N_AB_ALL_M'
    end
  end
  object QKonkPlus: TFDQuery
    CachedUpdates = True
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     =  :vid_edu'
      '    AND'
      '        price       =  :price'
      '    AND'
      '        konkurs     <> 2'
      '    AND'
      '        konkurs     <> 5'
      '    AND'
      '        n_specializ =  :n_spec'
      '    AND'
      '        NOT'
      '        ('
      '            status = 1'
      '         OR'
      '            status = 2'
      '         OR'
      '            status = 3'
      '         OR'
      '            status = 4'
      '        )')
    Left = 432
    Top = 176
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
      end
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QKonkPlusCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object QKonkPlus2: TFDQuery
    CachedUpdates = True
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu = :vid_edu'
      '    AND'
      '        price   = :price'
      '    AND'
      '        konkurs = 2'
      '    AND'
      '        n_fac   = :n_fac'
      '    AND'
      '        NOT'
      '        ('
      '            status = 1'
      '         OR'
      '            status = 2'
      '         OR'
      '            status = 3'
      '         OR'
      '            status = 4'
      '        )')
    Left = 464
    Top = 176
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
      end
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QKonkPlus2COUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object QPredm: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    text_predmet'
      'FROM'
      '    predmet'
      'ORDER BY'
      '    text_predmet')
    Left = 128
    Top = 176
    object QPredmTEXT_PREDMET: TStringField
      FieldName = 'TEXT_PREDMET'
      Origin = 'TEXT_PREDMET'
      Size = 100
    end
  end
  object QPredmet_Ball: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    *'
      'FROM'
      '    predmet_ball'
      '    ('
      '        :nom_ab'
      '    )')
    Left = 160
    Top = 176
    ParamData = <
      item
        Name = 'NOM_AB'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object QPredmet_BallOUT_N_PREDMET: TSmallintField
      FieldName = 'OUT_N_PREDMET'
      Origin = 'OUT_N_PREDMET'
    end
    object QPredmet_BallOUT_TEXT_PREDMET: TStringField
      FieldName = 'OUT_TEXT_PREDMET'
      Origin = 'OUT_TEXT_PREDMET'
      Size = 100
    end
    object QPredmet_BallOUT_BALL: TFloatField
      FieldName = 'OUT_BALL'
      Origin = 'OUT_BALL'
    end
  end
  object QGroupProtokol: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    n_group,'
      '    nom_group,'
      '    n_specializ,'
      '    vid_edu,'
      '    describe,'
      '    n_fac,'
      '    n_count'
      'FROM'
      '    n_group'
      'WHERE'
      '    n_fac = :fac')
    Left = 368
    Top = 176
    ParamData = <
      item
        Name = 'FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QGroupProtokolN_GROUP: TSmallintField
      FieldName = 'N_GROUP'
      Origin = 'N_GROUP'
    end
    object QGroupProtokolNOM_GROUP: TStringField
      FieldName = 'NOM_GROUP'
      Origin = 'NOM_GROUP'
      Size = 5
    end
    object QGroupProtokolN_SPECIALIZ: TSmallintField
      FieldName = 'N_SPECIALIZ'
      Origin = 'N_SPECIALIZ'
    end
    object QGroupProtokolVID_EDU: TSmallintField
      FieldName = 'VID_EDU'
      Origin = 'VID_EDU'
    end
    object QGroupProtokolDESCRIBE: TStringField
      FieldName = 'DESCRIBE'
      Origin = 'DESCRIBE'
      Size = 150
    end
    object QGroupProtokolN_FAC: TSmallintField
      FieldName = 'N_FAC'
      Origin = 'N_FAC'
    end
    object QGroupProtokolN_COUNT: TSmallintField
      FieldName = 'N_COUNT'
      Origin = 'N_COUNT'
    end
  end
  object QPeopleProtocol: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    nom_group,'
      '    fam  || '#39' '#39' ||'
      '    name || '#39' '#39' ||'
      '    otch AS fio,'
      '    pol,'
      '    date_r'
      'FROM'
      '    abitura'
      'where'
      '        n_fac     =  :fac'
      '    AND'
      '        status    =  0'
      '    AND'
      '        nom_group =  :n_gr'
      '    AND'
      '        pol       =  :pol'
      '    AND'
      '        konkurs   <> 5'
      'ORDER BY'
      '    nom_group,'
      '    pol,'
      '    fam,'
      '    name,'
      '    otch')
    Left = 624
    Top = 176
    ParamData = <
      item
        Name = 'FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_GR'
        DataType = ftString
        ParamType = ptInput
        Size = 5
      end
      item
        Name = 'POL'
        DataType = ftFixedChar
        ParamType = ptInput
        Size = 1
      end>
    object QPeopleProtocolNOM_GROUP: TStringField
      FieldName = 'NOM_GROUP'
      Origin = 'NOM_GROUP'
      Size = 5
    end
    object QPeopleProtocolFIO: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'FIO'
      Origin = 'FIO'
      ProviderFlags = []
      ReadOnly = True
      Size = 92
    end
    object QPeopleProtocolPOL: TStringField
      FieldName = 'POL'
      Origin = 'POL'
      FixedChar = True
      Size = 1
    end
    object QPeopleProtocolDATE_R: TSQLTimeStampField
      FieldName = 'DATE_R'
      Origin = 'DATE_R'
    end
  end
  object QKol_Place15: TFDQuery
    CachedUpdates = True
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '   kol_place'
      'FROM'
      '    kol_place'
      'WHERE'
      '       n_specializ = :sp'
      '    AND'
      '       text        = :kurs'
      '    AND'
      '       vid_edu     = :v_e'
      '    AND'
      '       price       = :price')
    Left = 400
    Top = 176
    ParamData = <
      item
        Name = 'SP'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'KURS'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'V_E'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QKol_Place15KOL_PLACE: TSmallintField
      FieldName = 'KOL_PLACE'
      Origin = 'KOL_PLACE'
    end
  end
  object QGIACMinBall: TFDQuery
    CachedUpdates = True
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    MIN'
      '    ('
      '        sum_ball'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status           = 5'
      '    AND'
      '        vid_edu          = :vid_edu'
      '    AND'
      '        konkurs          = 0'
      '    AND'
      '        price            = 0'
      '    AND'
      '        d_prikaz_include < "29.07.2015"'
      '    AND'
      '        ('
      '            n_specializ = 4'
      '         OR'
      '            n_specializ = 57'
      '        )')
    Left = 272
    Top = 176
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QGIACMinBallMIN: TFloatField
      AutoGenerateValue = arDefault
      FieldName = 'MIN'
      Origin = 'MIN'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QKonkurs: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    *'
      'FROM'
      '    konkurs3'
      '    ('
      '        :in_sp,'
      '        :in_vid_edu,'
      '        :in_konk,'
      '        :in_price'
      '    )'
      'ORDER BY'
      '    out_sum_ball DESC,'
      '    out_middle_ball DESC')
    Left = 496
    Top = 176
    ParamData = <
      item
        Name = 'IN_SP'
        DataType = ftSmallint
        ParamType = ptInput
        Value = 1
      end
      item
        Name = 'IN_VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
        Value = 0
      end
      item
        Name = 'IN_KONK'
        DataType = ftSmallint
        ParamType = ptInput
        Value = 0
      end
      item
        Name = 'IN_PRICE'
        DataType = ftSmallint
        ParamType = ptInput
        Value = 0
      end>
    object QKonkursOUT_NOMER_AB: TIntegerField
      FieldName = 'OUT_NOMER_AB'
      Origin = 'OUT_NOMER_AB'
    end
    object QKonkursOUT_N_DELA: TIntegerField
      FieldName = 'OUT_N_DELA'
      Origin = 'OUT_N_DELA'
    end
    object QKonkursOUT_DATE_R: TSQLTimeStampField
      FieldName = 'OUT_DATE_R'
      Origin = 'OUT_DATE_R'
    end
    object QKonkursOUT_POL: TStringField
      FieldName = 'OUT_POL'
      Origin = 'OUT_POL'
      FixedChar = True
      Size = 1
    end
    object QKonkursOUT_NAME_EDU_MIDDLE: TStringField
      FieldName = 'OUT_NAME_EDU_MIDDLE'
      Origin = 'OUT_NAME_EDU_MIDDLE'
      Size = 50
    end
    object QKonkursOUT_WHEN_EDU_MIDDLE: TSmallintField
      FieldName = 'OUT_WHEN_EDU_MIDDLE'
      Origin = 'OUT_WHEN_EDU_MIDDLE'
    end
    object QKonkursOUT_NAME_EDU_SPEC: TStringField
      FieldName = 'OUT_NAME_EDU_SPEC'
      Origin = 'OUT_NAME_EDU_SPEC'
      Size = 50
    end
    object QKonkursOUT_WHEN_EDU_SPEC: TSmallintField
      FieldName = 'OUT_WHEN_EDU_SPEC'
      Origin = 'OUT_WHEN_EDU_SPEC'
    end
    object QKonkursOUT_STAG: TFloatField
      FieldName = 'OUT_STAG'
      Origin = 'OUT_STAG'
    end
    object QKonkursOUT_STAG_SPEC: TFloatField
      FieldName = 'OUT_STAG_SPEC'
      Origin = 'OUT_STAG_SPEC'
    end
    object QKonkursOUT_SPORT_CATEGORY: TStringField
      FieldName = 'OUT_SPORT_CATEGORY'
      Origin = 'OUT_SPORT_CATEGORY'
      Size = 50
    end
    object QKonkursOUT_MIDDLE_BALL: TFloatField
      FieldName = 'OUT_MIDDLE_BALL'
      Origin = 'OUT_MIDDLE_BALL'
    end
    object QKonkursOUT_SUM_BALL: TFloatField
      FieldName = 'OUT_SUM_BALL'
      Origin = 'OUT_SUM_BALL'
    end
    object QKonkursOUT_ADDRESS_BEFORE: TStringField
      FieldName = 'OUT_ADDRESS_BEFORE'
      Origin = 'OUT_ADDRESS_BEFORE'
      Size = 100
    end
    object QKonkursOUT_KONKURS: TSmallintField
      FieldName = 'OUT_KONKURS'
      Origin = 'OUT_KONKURS'
    end
    object QKonkursOUT_N_CK: TSmallintField
      FieldName = 'OUT_N_CK'
      Origin = 'OUT_N_CK'
    end
    object QKonkursOUT_TERM_EDU: TSmallintField
      FieldName = 'OUT_TERM_EDU'
      Origin = 'OUT_TERM_EDU'
    end
    object QKonkursOUT_CATEGORY_AB: TSmallintField
      FieldName = 'OUT_CATEGORY_AB'
      Origin = 'OUT_CATEGORY_AB'
    end
    object QKonkursOUT_FIO: TStringField
      FieldName = 'OUT_FIO'
      Origin = 'OUT_FIO'
      Size = 90
    end
  end
  object QKonkurs2V: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    *'
      'FROM'
      '    konkurs2v'
      '    ('
      '        :in_sp,'
      '        :in_vid_edu,'
      '        :in_konk,'
      '        :in_price'
      '    )'
      'ORDER BY'
      '    out_sum_ball DESC,'
      '    out_middle_ball DESC')
    Left = 560
    Top = 176
    ParamData = <
      item
        Name = 'IN_SP'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'IN_VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'IN_KONK'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'IN_PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QKonkurs2VOUT_NOMER_AB: TIntegerField
      FieldName = 'OUT_NOMER_AB'
      Origin = 'OUT_NOMER_AB'
    end
    object QKonkurs2VOUT_N_DELA: TIntegerField
      FieldName = 'OUT_N_DELA'
      Origin = 'OUT_N_DELA'
    end
    object QKonkurs2VOUT_DATE_R: TSQLTimeStampField
      FieldName = 'OUT_DATE_R'
      Origin = 'OUT_DATE_R'
    end
    object QKonkurs2VOUT_POL: TStringField
      FieldName = 'OUT_POL'
      Origin = 'OUT_POL'
      FixedChar = True
      Size = 1
    end
    object QKonkurs2VOUT_NAME_EDU_MIDDLE: TStringField
      FieldName = 'OUT_NAME_EDU_MIDDLE'
      Origin = 'OUT_NAME_EDU_MIDDLE'
      Size = 50
    end
    object QKonkurs2VOUT_WHEN_EDU_MIDDLE: TSmallintField
      FieldName = 'OUT_WHEN_EDU_MIDDLE'
      Origin = 'OUT_WHEN_EDU_MIDDLE'
    end
    object QKonkurs2VOUT_NAME_EDU_SPEC: TStringField
      FieldName = 'OUT_NAME_EDU_SPEC'
      Origin = 'OUT_NAME_EDU_SPEC'
      Size = 50
    end
    object QKonkurs2VOUT_WHEN_EDU_SPEC: TSmallintField
      FieldName = 'OUT_WHEN_EDU_SPEC'
      Origin = 'OUT_WHEN_EDU_SPEC'
    end
    object QKonkurs2VOUT_STAG: TFloatField
      FieldName = 'OUT_STAG'
      Origin = 'OUT_STAG'
    end
    object QKonkurs2VOUT_STAG_SPEC: TFloatField
      FieldName = 'OUT_STAG_SPEC'
      Origin = 'OUT_STAG_SPEC'
    end
    object QKonkurs2VOUT_SPORT_CATEGORY: TStringField
      FieldName = 'OUT_SPORT_CATEGORY'
      Origin = 'OUT_SPORT_CATEGORY'
      Size = 50
    end
    object QKonkurs2VOUT_MIDDLE_BALL: TFloatField
      FieldName = 'OUT_MIDDLE_BALL'
      Origin = 'OUT_MIDDLE_BALL'
    end
    object QKonkurs2VOUT_SUM_BALL: TFloatField
      FieldName = 'OUT_SUM_BALL'
      Origin = 'OUT_SUM_BALL'
    end
    object QKonkurs2VOUT_ADDRESS_BEFORE: TStringField
      FieldName = 'OUT_ADDRESS_BEFORE'
      Origin = 'OUT_ADDRESS_BEFORE'
      Size = 100
    end
    object QKonkurs2VOUT_KONKURS: TSmallintField
      FieldName = 'OUT_KONKURS'
      Origin = 'OUT_KONKURS'
    end
    object QKonkurs2VOUT_N_CK: TSmallintField
      FieldName = 'OUT_N_CK'
      Origin = 'OUT_N_CK'
    end
    object QKonkurs2VOUT_TERM_EDU: TSmallintField
      FieldName = 'OUT_TERM_EDU'
      Origin = 'OUT_TERM_EDU'
    end
    object QKonkurs2VOUT_CATEGORY_AB: TSmallintField
      FieldName = 'OUT_CATEGORY_AB'
      Origin = 'OUT_CATEGORY_AB'
    end
    object QKonkurs2VOUT_FIO: TStringField
      FieldName = 'OUT_FIO'
      Origin = 'OUT_FIO'
      Size = 90
    end
  end
  object QKonkurs34: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    *'
      'FROM'
      '    konkurs34'
      '    ('
      '        :n_fac,'
      '        :in_vid_edu,'
      '        :in_konk,'
      '        :in_price'
      '    )'
      'ORDER BY'
      '    out_sum_ball DESC,'
      '    out_middle_ball DESC')
    Left = 592
    Top = 176
    ParamData = <
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'IN_VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'IN_KONK'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'IN_PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QKonkurs34OUT_NOMER_AB: TIntegerField
      FieldName = 'OUT_NOMER_AB'
      Origin = 'OUT_NOMER_AB'
    end
    object QKonkurs34OUT_N_DELA: TIntegerField
      FieldName = 'OUT_N_DELA'
      Origin = 'OUT_N_DELA'
    end
    object QKonkurs34OUT_DATE_R: TSQLTimeStampField
      FieldName = 'OUT_DATE_R'
      Origin = 'OUT_DATE_R'
    end
    object QKonkurs34OUT_POL: TStringField
      FieldName = 'OUT_POL'
      Origin = 'OUT_POL'
      FixedChar = True
      Size = 1
    end
    object QKonkurs34OUT_NAME_EDU_MIDDLE: TStringField
      FieldName = 'OUT_NAME_EDU_MIDDLE'
      Origin = 'OUT_NAME_EDU_MIDDLE'
      Size = 50
    end
    object QKonkurs34OUT_WHEN_EDU_MIDDLE: TSmallintField
      FieldName = 'OUT_WHEN_EDU_MIDDLE'
      Origin = 'OUT_WHEN_EDU_MIDDLE'
    end
    object QKonkurs34OUT_NAME_EDU_SPEC: TStringField
      FieldName = 'OUT_NAME_EDU_SPEC'
      Origin = 'OUT_NAME_EDU_SPEC'
      Size = 50
    end
    object QKonkurs34OUT_WHEN_EDU_SPEC: TSmallintField
      FieldName = 'OUT_WHEN_EDU_SPEC'
      Origin = 'OUT_WHEN_EDU_SPEC'
    end
    object QKonkurs34OUT_STAG: TFloatField
      FieldName = 'OUT_STAG'
      Origin = 'OUT_STAG'
    end
    object QKonkurs34OUT_STAG_SPEC: TFloatField
      FieldName = 'OUT_STAG_SPEC'
      Origin = 'OUT_STAG_SPEC'
    end
    object QKonkurs34OUT_SPORT_CATEGORY: TStringField
      FieldName = 'OUT_SPORT_CATEGORY'
      Origin = 'OUT_SPORT_CATEGORY'
      Size = 50
    end
    object QKonkurs34OUT_MIDDLE_BALL: TFloatField
      FieldName = 'OUT_MIDDLE_BALL'
      Origin = 'OUT_MIDDLE_BALL'
    end
    object QKonkurs34OUT_SUM_BALL: TFloatField
      FieldName = 'OUT_SUM_BALL'
      Origin = 'OUT_SUM_BALL'
    end
    object QKonkurs34OUT_ADDRESS_BEFORE: TStringField
      FieldName = 'OUT_ADDRESS_BEFORE'
      Origin = 'OUT_ADDRESS_BEFORE'
      Size = 100
    end
    object QKonkurs34OUT_KONKURS: TSmallintField
      FieldName = 'OUT_KONKURS'
      Origin = 'OUT_KONKURS'
    end
    object QKonkurs34OUT_N_CK: TSmallintField
      FieldName = 'OUT_N_CK'
      Origin = 'OUT_N_CK'
    end
    object QKonkurs34OUT_TERM_EDU: TSmallintField
      FieldName = 'OUT_TERM_EDU'
      Origin = 'OUT_TERM_EDU'
    end
    object QKonkurs34OUT_CATEGORY_AB: TSmallintField
      FieldName = 'OUT_CATEGORY_AB'
      Origin = 'OUT_CATEGORY_AB'
    end
    object QKonkurs34OUT_N_SPECIALIZ: TSmallintField
      FieldName = 'OUT_N_SPECIALIZ'
      Origin = 'OUT_N_SPECIALIZ'
    end
    object QKonkurs34OUT_FIO: TStringField
      FieldName = 'OUT_FIO'
      Origin = 'OUT_FIO'
      Size = 90
    end
  end
  object QKonkurs12: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '* FROM KONKURS12(:IN_VID_EDU,:IN_KONK,:IN_PRICE)'
      'ORDER BY'
      'out_sum_ball desc, out_middle_ball desc')
    Left = 528
    Top = 176
    ParamData = <
      item
        Name = 'IN_VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'IN_KONK'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'IN_PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QKonkurs12OUT_NOMER_AB: TIntegerField
      FieldName = 'OUT_NOMER_AB'
      Origin = 'OUT_NOMER_AB'
    end
    object QKonkurs12OUT_N_DELA: TIntegerField
      FieldName = 'OUT_N_DELA'
      Origin = 'OUT_N_DELA'
    end
    object QKonkurs12OUT_DATE_R: TSQLTimeStampField
      FieldName = 'OUT_DATE_R'
      Origin = 'OUT_DATE_R'
    end
    object QKonkurs12OUT_POL: TStringField
      FieldName = 'OUT_POL'
      Origin = 'OUT_POL'
      FixedChar = True
      Size = 1
    end
    object QKonkurs12OUT_NAME_EDU_MIDDLE: TStringField
      FieldName = 'OUT_NAME_EDU_MIDDLE'
      Origin = 'OUT_NAME_EDU_MIDDLE'
      Size = 50
    end
    object QKonkurs12OUT_WHEN_EDU_MIDDLE: TSmallintField
      FieldName = 'OUT_WHEN_EDU_MIDDLE'
      Origin = 'OUT_WHEN_EDU_MIDDLE'
    end
    object QKonkurs12OUT_NAME_EDU_SPEC: TStringField
      FieldName = 'OUT_NAME_EDU_SPEC'
      Origin = 'OUT_NAME_EDU_SPEC'
      Size = 50
    end
    object QKonkurs12OUT_WHEN_EDU_SPEC: TSmallintField
      FieldName = 'OUT_WHEN_EDU_SPEC'
      Origin = 'OUT_WHEN_EDU_SPEC'
    end
    object QKonkurs12OUT_STAG: TFloatField
      FieldName = 'OUT_STAG'
      Origin = 'OUT_STAG'
    end
    object QKonkurs12OUT_STAG_SPEC: TFloatField
      FieldName = 'OUT_STAG_SPEC'
      Origin = 'OUT_STAG_SPEC'
    end
    object QKonkurs12OUT_SPORT_CATEGORY: TStringField
      FieldName = 'OUT_SPORT_CATEGORY'
      Origin = 'OUT_SPORT_CATEGORY'
      Size = 50
    end
    object QKonkurs12OUT_MIDDLE_BALL: TFloatField
      FieldName = 'OUT_MIDDLE_BALL'
      Origin = 'OUT_MIDDLE_BALL'
    end
    object QKonkurs12OUT_SUM_BALL: TFloatField
      FieldName = 'OUT_SUM_BALL'
      Origin = 'OUT_SUM_BALL'
    end
    object QKonkurs12OUT_ADDRESS_BEFORE: TStringField
      FieldName = 'OUT_ADDRESS_BEFORE'
      Origin = 'OUT_ADDRESS_BEFORE'
      Size = 100
    end
    object QKonkurs12OUT_KONKURS: TSmallintField
      FieldName = 'OUT_KONKURS'
      Origin = 'OUT_KONKURS'
    end
    object QKonkurs12OUT_N_CK: TSmallintField
      FieldName = 'OUT_N_CK'
      Origin = 'OUT_N_CK'
    end
    object QKonkurs12OUT_TERM_EDU: TSmallintField
      FieldName = 'OUT_TERM_EDU'
      Origin = 'OUT_TERM_EDU'
    end
    object QKonkurs12OUT_CATEGORY_AB: TSmallintField
      FieldName = 'OUT_CATEGORY_AB'
      Origin = 'OUT_CATEGORY_AB'
    end
    object QKonkurs12OUT_N_SPECIALIZ: TSmallintField
      FieldName = 'OUT_N_SPECIALIZ'
      Origin = 'OUT_N_SPECIALIZ'
    end
    object QKonkurs12OUT_FIO: TStringField
      FieldName = 'OUT_FIO'
      Origin = 'OUT_FIO'
      Size = 90
    end
  end
  object QGIACInDate: TFDQuery
    CachedUpdates = True
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status           = 5'
      '    AND'
      '        vid_edu          = :vid_edu'
      '    AND'
      '        price            = 0'
      '    AND'
      '        d_prikaz_include = :d_prikaz_include'
      '    AND'
      '        ('
      '            n_specializ = 4'
      '         OR'
      '            n_specializ = 57'
      '        )')
    Left = 656
    Top = 128
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'D_PRIKAZ_INCLUDE'
        DataType = ftTimeStamp
        ParamType = ptInput
      end>
    object QGIACInDateCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QGIACInAll: TFDQuery
    CachedUpdates = True
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status  = 5'
      '    AND'
      '        vid_edu = :vid_edu'
      '    AND'
      '        price   = 0'
      '    AND'
      '        ('
      '            n_specializ = 4'
      '         OR'
      '            n_specializ = 57'
      '        )')
    Left = 624
    Top = 128
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QGIACInAllCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QGIACBvi: TFDQuery
    CachedUpdates = True
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '       nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '       vid_edu = :vid_edu'
      '    AND'
      '       status  = 5'
      '    AND'
      '       konkurs = 4'
      '    AND'
      '        ('
      '           n_specializ = 4'
      '         OR'
      '           n_specializ = 57'
      '        )')
    Left = 592
    Top = 128
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QGIACBviCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QGIAC3Sert: TFDQuery
    CachedUpdates = True
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    count'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     =  :vid_edu'
      '    AND'
      '        status      =  5'
      '    AND'
      '        konkurs     <> 2'
      '    AND'
      '        n_specializ =  61')
    Left = 560
    Top = 128
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QGIAC3SertCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QGIACViPlus: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            nomer_ab'
      '    )'
      'FROM'
      '    examen'
      'WHERE'
      '    nomer_ab IN'
      '    ('
      '        SELECT'
      '           nomer_ab'
      '        FROM'
      '            abitura'
      '        WHERE'
      '               vid_edu = :vid_edu'
      '            AND'
      '                NOT'
      '                ('
      '                   status = 2'
      '                 OR'
      '                   status = 3'
      '                 OR'
      '                   status = 4'
      '                )'
      '            AND'
      '                ('
      '                   n_specializ = 4'
      '                 OR'
      '                   n_specializ = 57'
      '                )'
      '    )')
    Left = 336
    Top = 176
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QGIACViPlusCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QGIACViIn: TFDQuery
    CachedUpdates = True
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            nomer_ab'
      '    )'
      'FROM'
      '    examen'
      'WHERE'
      '    nomer_ab IN'
      '    ('
      '        SELECT'
      '            nomer_ab'
      '        FROM'
      '            abitura'
      '        WHERE'
      '                vid_edu = :vid_edu'
      '            AND'
      '                ('
      '                    n_specializ = 4'
      '                 OR'
      '                    n_specializ = 57'
      '                )'
      '    )')
    Left = 304
    Top = 176
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QGIACViInCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object GIAZ2_1_1StrdPrc: TFDStoredProc
    Connection = DM.FDConnection2
    StoredProcName = 'EXAM_CNT'
    Left = 96
    Top = 48
    ParamData = <
      item
        Position = 1
        Name = 'N_SPEC'
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
        Name = 'SUM1'
        DataType = ftInteger
        ParamType = ptOutput
      end>
    object GIAZ2_1_1StrdPrcSUM1: TIntegerField
      FieldName = 'SUM1'
      Origin = 'SUM1'
    end
  end
  object GIAZ2_1_3Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        status      = 5'
      '    AND'
      '        n_specializ = 61'
      '    AND'
      '        ('
      '            term_edu = 0'
      '         OR'
      '            term_edu = 3'
      '        )')
    Left = 432
    Top = 32
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_1_3QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_1_4Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '           nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        term_edu    < 4'
      '    AND'
      '        n_spec      = :n_spec'
      '    AND'
      '        konkurs     = 1'
      '    AND'
      '        status      = 5')
    Left = 496
    Top = 32
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_1_4QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_1_4_ckQr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        abitura.konkurs     =  3'
      '    AND'
      '        privileg_log.n_priv      =  0'
      '    AND'
      '        abitura.n_spec      =  :n_spec'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 464
    Top = 32
    ParamData = <
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_1_4_ckQrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_1_5Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        term_edu    < 4'
      '    AND'
      '        n_spec      = :n_spec'
      '    AND'
      '        konkurs     = 2'
      '    AND'
      '        status      = 5')
    Left = 560
    Top = 32
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_1_5QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
    end
  end
  object GIAZ2_1_5_ckQr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        abitura.konkurs     =  3'
      '    AND'
      '        privileg_log.n_priv      =  1'
      '    AND'
      '        abitura.n_spec      =  :n_spec'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 528
    Top = 32
    ParamData = <
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_1_5_ckQrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_1_6Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status      = 5'
      '    AND'
      '        n_spec      = :n_spec'
      '    AND'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        price       = 0'
      '    AND'
      '        term_edu    < 4')
    Left = 592
    Top = 32
    ParamData = <
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_1_6QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_1_7Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '       nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '       status           = 5'
      '    AND'
      '       n_spec           = :n_spec'
      '    AND'
      '       vid_edu          = :vid_edu'
      '    AND'
      '       category_if      = 0'
      '    AND'
      '       term_edu         < 4'
      '    AND'
      '       price            = 0'
      '    AND'
      '       d_prikaz_include = :d_prikaz_include')
    Left = 624
    Top = 32
    ParamData = <
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'D_PRIKAZ_INCLUDE'
        DataType = ftTimeStamp
        ParamType = ptInput
      end>
    object GIAZ2_1_7QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_1_9Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        term_edu    < 4'
      '    AND'
      '        n_spec      = :n_spec'
      '    AND'
      '        konkurs     = 3'
      '    AND'
      '        price       = 0'
      '    AND'
      '        status      = 5')
    Left = 656
    Top = 32
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_1_9QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_1_10Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        n_spec      = :n_spec'
      '    AND'
      '        price       = 0'
      '    AND'
      '        status      = 5'
      '    AND'
      '        ('
      '            term_edu = 1'
      '         OR'
      '            term_edu = 2'
      '        )')
    Left = 272
    Top = 32
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_1_10QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_1_11Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        n_spec      = :n_spec'
      '    AND'
      '        price       = 0'
      '    AND'
      '        status      = 5'
      '    AND'
      '        ('
      '            term_edu = 3'
      '         OR'
      '            term_edu = 4'
      '         OR'
      '            term_edu = 5'
      '        )')
    Left = 304
    Top = 32
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_1_11QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_1_12Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status      = 5'
      '    AND'
      '        n_spec      = :n_spec'
      '    AND'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        price       = 1'
      '    AND'
      '        term_edu    < 4')
    Left = 336
    Top = 32
    ParamData = <
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_1_12QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_1_13Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        n_spec      = :n_spec'
      '    AND'
      '        price       = 1'
      '    AND'
      '        status      = 5'
      '    AND'
      '        ('
      '            term_edu = 1'
      '         OR'
      '            term_edu = 2'
      '        )')
    Left = 368
    Top = 32
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_1_13QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_1_14Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        n_spec      = :n_spec'
      '    AND'
      '        price       = 1'
      '    AND'
      '        status      = 5'
      '    AND'
      '        ('
      '            term_edu = 3'
      '         OR'
      '            term_edu = 4'
      '         OR'
      '            term_edu = 5'
      '        )')
    Left = 400
    Top = 32
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_1_14QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_2_1Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        term_edu    < 4'
      '    AND'
      '        konkurs     = 1'
      '    AND'
      '        status      = 5')
    Left = 304
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_2_1QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_2_1ckQr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        abitura.konkurs     =  3'
      '    AND'
      '        privileg_log.n_priv      =  0'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 272
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_2_1ckQrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_3_1Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        term_edu    < 4'
      '    AND'
      '        konkurs     = 2'
      '    AND'
      '        status      = 5')
    Left = 464
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_3_1QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_3_1ckQr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        abitura.konkurs     =  3'
      '    AND'
      '        privileg_log.n_priv      =  1'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 432
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_3_1ckQrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_2_2Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        privileg_log.n_priv      =  0'
      '    AND'
      '        privileg_log.sel_priv    =  16'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 336
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_2_2QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_3_2Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        privileg_log.n_priv      =  1'
      '    AND'
      '        privileg_log.sel_priv    =  0'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 496
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_3_2QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_2_4Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        privileg_log.n_priv      =  0'
      '    AND'
      '        privileg_log.sel_priv    =  15'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 368
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_2_4QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_3_3Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        privileg_log.n_priv      =  1'
      '    AND'
      '        privileg_log.sel_priv    =  6'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 528
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_3_3QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_2_6Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        privileg_log.n_priv      =  0'
      '    AND'
      '        privileg_log.sel_priv    <  15'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 400
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_2_6QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_3_4Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        privileg_log.n_priv      =  1'
      '    AND'
      '        privileg_log.sel_priv    <  6'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        ('
      '            abitur_logbook.konkurs = 2'
      '         OR'
      '            abitur_logbook.konkurs = 3'
      '        )'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 560
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_3_4QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_3_6Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        privileg_log.n_priv      =  2'
      '    AND'
      '        privileg_log.sel_priv    =  7'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 592
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_3_6QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_3_7Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        privileg_log.n_priv      =  2'
      '    AND'
      '        privileg_log.sel_priv    =  4'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 624
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_3_7QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_3_8Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        privileg_log.n_priv      =  2'
      '    AND'
      '        privileg_log.sel_priv    =  6'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 656
    Top = 80
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_3_8QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_3_9Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            privileg_log.id_log'
      '    )'
      'FROM'
      '    privileg_log,'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitura.status      =  5'
      '    AND'
      '        abitur_logbook.nomer_ab    =  abitura.nomer_ab'
      '    AND'
      '        privileg_log.id_log      =  abitur_logbook.id_log'
      '    AND'
      '        abitur_logbook.date_out    IS NULL'
      '    AND'
      '        privileg_log.n_priv      =  2'
      '    AND'
      '        privileg_log.sel_priv    =  5'
      '    AND'
      '        abitura.vid_edu     =  :vid_edu'
      '    AND'
      '        abitura.category_if =  0'
      '    AND'
      '        abitura.term_edu    <  4'
      '    AND'
      '        NOT'
      '        ('
      '            abitur_logbook.date_in IS NULL'
      '        )')
    Left = 272
    Top = 128
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_3_9QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_4_10Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status      = 5'
      '    AND'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        term_edu    < 4'
      '    AND'
      '        type_school = 4')
    Left = 304
    Top = 128
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_4_10QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_4_8Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status      = 5'
      '    AND'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        term_edu    < 4'
      '    AND'
      '        type_school = 2')
    Left = 464
    Top = 128
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_4_8QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_4_6Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status      = 5'
      '    AND'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        term_edu    < 4'
      '    AND'
      '        type_school = 1')
    Left = 432
    Top = 128
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_4_6QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_4_5Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status      = 5'
      '    AND'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        term_edu    < 4'
      '    AND'
      '        type_school = 3')
    Left = 400
    Top = 128
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_4_5QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_4_3Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status       = 5'
      '    AND'
      '        vid_edu      = :vid_edu'
      '    AND'
      '        category_if  = 0'
      '    AND'
      '        term_edu     < 4'
      '    AND'
      '        town_village = 1'
      '    AND'
      '        ('
      '            type_school = 0'
      '         OR'
      '            type_school = 3'
      '        )')
    Left = 368
    Top = 128
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_4_3QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object GIAZ2_4_1Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status       = 5'
      '    AND'
      '        vid_edu      = :vid_edu'
      '    AND'
      '        category_if  = 0'
      '    AND'
      '        term_edu     < 4'
      '    AND'
      '        town_village = 0'
      '    AND'
      '        ('
      '            type_school = 0'
      '         OR'
      '            type_school = 3'
      '        )')
    Left = 336
    Top = 128
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZ2_4_1QrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object QSpec1: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    n_specializ'
      'FROM'
      '    specializ'
      'WHERE'
      '    n_fac = :n_fac')
    Left = 656
    Top = 176
    ParamData = <
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QSpec1N_SPECIALIZ: TSmallintField
      FieldName = 'N_SPECIALIZ'
      Origin = 'N_SPECIALIZ'
    end
  end
  object GIAZInQr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        vid_edu     = :vid_edu'
      '    AND'
      '        status      = 5'
      '    AND'
      '        category_if = 1')
    Left = 496
    Top = 128
    ParamData = <
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object GIAZInQrCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
end
