object DMStat: TDMStat
  OldCreateOrder = False
  Height = 256
  Width = 896
  object DSF1kKol: TDataSource
    DataSet = QF1kKol
    Left = 544
    Top = 160
  end
  object DSF1kAb: TDataSource
    DataSet = QF1kAb
    Left = 512
    Top = 160
  end
  object DSSvod_Ved: TDataSource
    DataSet = QSvod_Ved
    Left = 800
    Top = 160
  end
  object DSSvod_Ved2: TDataSource
    DataSet = QSvod_Ved2
    Left = 832
    Top = 160
  end
  object DSProtokol: TDataSource
    DataSet = QProtokol
    Left = 704
    Top = 160
  end
  object DSCount_special_ab: TDataSource
    DataSet = QCount_special_ab
    Left = 416
    Top = 160
  end
  object DSSpecial: TDataSource
    DataSet = TSpecial
    Left = 32
    Top = 160
  end
  object DSCount_PO: TDataSource
    DataSet = QCount_PO
    Left = 832
    Top = 80
  end
  object DSCount_CK: TDataSource
    DataSet = QCount_CK
    Left = 608
    Top = 80
  end
  object DSCount_Medal: TDataSource
    DataSet = QCount_Medal
    Left = 736
    Top = 80
  end
  object DSCount_Diplom: TDataSource
    DataSet = QCount_Diplom
    Left = 640
    Top = 80
  end
  object DSCount_Olimp: TDataSource
    DataSet = QCount_Olimp
    Left = 768
    Top = 80
  end
  object DSCount_Gimn: TDataSource
    DataSet = QCount_Gimn
    Left = 672
    Top = 80
  end
  object DSCount_Selo: TDataSource
    DataSet = QCount_Selo
    Left = 384
    Top = 160
  end
  object DSCount_Gorod: TDataSource
    DataSet = QCount_Gorod
    Left = 704
    Top = 80
  end
  object DSCount_Stag: TDataSource
    DataSet = QCount_Stag
    Left = 448
    Top = 160
  end
  object DSCount_Region: TDataSource
    DataSet = QCount_Region
    Left = 352
    Top = 160
  end
  object DSRegion_Stat: TDataSource
    DataSet = QRegion_Stat
    Left = 736
    Top = 160
  end
  object DSCount_Platn: TDataSource
    DataSet = QCount_Platn
    Left = 800
    Top = 80
  end
  object DSCount_Ball_Examen: TDataSource
    DataSet = QCount_Ball_Examen
    Left = 512
    Top = 80
  end
  object DSSport_Categ: TDataSource
    DataSet = QSport_Categ
    Left = 768
    Top = 160
  end
  object DSQSpecial: TDataSource
    DataSet = QSpecial
    Left = 32
    Top = 64
  end
  object DSQ_GK_All: TDataSource
    DataSet = Q_GK_All
    Left = 352
    Top = 80
  end
  object DSQ_GK_Konkurs: TDataSource
    DataSet = Q_GK_Konkurs
    Left = 384
    Top = 80
  end
  object DSQ_GK_Medal: TDataSource
    DataSet = Q_GK_Medal
    Left = 416
    Top = 80
  end
  object DSQ_GK_Plan: TDataSource
    DataSet = Q_GK_Plan
    Left = 448
    Top = 80
  end
  object DSQ_GK_Plan_CK: TDataSource
    DataSet = Q_GK_Plan_CK
    Left = 480
    Top = 80
  end
  object DSQF2_All_Sdal: TDataSource
    DataSet = QF2_All_Sdal
    Left = 576
    Top = 160
  end
  object DSQF2_Sdal: TDataSource
    DataSet = QF2_Sdal
    Left = 640
    Top = 160
  end
  object DSQF2_Zach: TDataSource
    DataSet = QF2_Zach
    Left = 672
    Top = 160
  end
  object DSQF2_CK: TDataSource
    DataSet = QF2_CK
    Left = 608
    Top = 160
  end
  object DSCount_Test: TDataSource
    DataSet = QCount_Test
    Left = 480
    Top = 160
  end
  object DSQCount_Ball_Rus_Bel_old: TDataSource
    DataSet = QCount_Ball_Rus_Bel_old
    Left = 576
    Top = 80
  end
  object DSQCount_Ball_Rus_Bel: TDataSource
    DataSet = QCount_Ball_Rus_Bel
    Left = 544
    Top = 80
  end
  object Q_GK_All: TFDQuery
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
      '        status = 0'
      '    AND'
      '        n_fac  = :fac')
    Left = 352
    Top = 112
    ParamData = <
      item
        Name = 'FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object Q_GK_AllCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QF1kAb: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    specializ.special,'
      '    COUNT'
      '    ('
      '        abitura.nomer_ab'
      '    ) AS count_nomer_ab,'
      '    abitura.copy_at,'
      '    faculty.fac1'
      'FROM'
      '    abitura'
      '        INNER JOIN'
      '            specializ'
      '        ON'
      '            abitura.n_specializ = specializ.n_specializ'
      '        INNER JOIN'
      '            faculty'
      '        ON'
      '            abitura.n_fac       = faculty.n_fac'
      'WHERE'
      '        abitura.konkurs NOT IN (3,4)'
      '    AND'
      '        abitura.status  =      :stat'
      '    AND'
      '        abitura.vid_edu =      :vid'
      'GROUP BY'
      '    specializ.special,'
      '    abitura.copy_at,'
      '    faculty.fac1'
      'ORDER BY'
      '    faculty.fac1,'
      '    specializ.special,'
      '    abitura.copy_at')
    Left = 512
    Top = 192
    ParamData = <
      item
        Name = 'STAT'
        DataType = ftSmallint
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'VID'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QF1kAbSPECIAL: TStringField
      FieldName = 'SPECIAL'
      Origin = 'SPECIAL'
      Size = 80
    end
    object QF1kAbCOUNT_NOMER_AB: TIntegerField
      FieldName = 'COUNT_NOMER_AB'
      Origin = 'COUNT_NOMER_AB'
      Required = True
    end
    object QF1kAbCOPY_AT: TSmallintField
      FieldName = 'COPY_AT'
      Origin = 'COPY_AT'
    end
    object QF1kAbFAC1: TStringField
      FieldName = 'FAC1'
      Origin = 'FAC1'
    end
  end
  object QF1kKol: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    specializ.special,'
      '    SUM'
      '    ('
      '        kol_place.kol_place'
      '    ) AS sum_kol_place,'
      '    faculty.fac1'
      'FROM'
      '    kol_place'
      '        INNER JOIN'
      '            specializ'
      '        ON'
      '            kol_place.n_specializ = specializ.n_specializ'
      '        INNER JOIN'
      '            faculty'
      '        ON'
      '            kol_place.n_fac       = faculty.n_fac'
      'WHERE'
      '        kol_place.vid_edu   =  :edu'
      '    AND'
      '        kol_place.kol_place <> -1'
      '    AND'
      '        kol_place.kol_place <> 0'
      'GROUP BY'
      '    specializ.special,'
      '    faculty.fac1'
      'ORDER BY'
      '    faculty.fac1,'
      '    specializ.special')
    Left = 544
    Top = 192
    ParamData = <
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QF1kKolSPECIAL: TStringField
      FieldName = 'SPECIAL'
      Origin = 'SPECIAL'
      Size = 80
    end
    object QF1kKolSUM_KOL_PLACE: TIntegerField
      FieldName = 'SUM_KOL_PLACE'
      Origin = 'SUM_KOL_PLACE'
    end
    object QF1kKolFAC1: TStringField
      FieldName = 'FAC1'
      Origin = 'FAC1'
    end
  end
  object Q_GK_Konkurs: TFDQuery
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
      '        status  = 0'
      '    AND'
      '        n_fac   = :fac'
      '    AND'
      '        konkurs = :kon')
    Left = 384
    Top = 112
    ParamData = <
      item
        Name = 'FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'KON'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object Q_GK_KonkursCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object Q_GK_Medal: TFDQuery
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
      '        status           = 0'
      '    AND'
      '        n_fac            = :fac'
      '    AND'
      '        n_privilege_exam = :priv')
    Left = 416
    Top = 112
    ParamData = <
      item
        Name = 'FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PRIV'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object Q_GK_MedalCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object Q_GK_Plan: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    SUM'
      '    ('
      '        kol_place'
      '    )'
      'FROM'
      '    kol_place'
      'WHERE'
      '    n_fac = :fac')
    Left = 448
    Top = 112
    ParamData = <
      item
        Name = 'FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object Q_GK_PlanSUM: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'SUM'
      Origin = 'SUM'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object Q_GK_Plan_CK: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    SUM'
      '    ('
      '        kol_place'
      '    )'
      'FROM'
      '    kol_place'
      'WHERE'
      '        n_fac = :fac'
      '    AND'
      '        text  = 2')
    Left = 480
    Top = 112
    ParamData = <
      item
        Name = 'FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object Q_GK_Plan_CKSUM: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'SUM'
      Origin = 'SUM'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object TSpecial: TFDTable
    IndexFieldNames = 'N_SPEC'
    Connection = DM.FDConnection1
    UpdateOptions.UpdateTableName = 'SPECIALITY'
    TableName = 'SPECIALITY'
    Left = 32
    Top = 192
    object TSpecialN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object TSpecialSPEC: TStringField
      FieldName = 'SPEC'
      Origin = 'SPEC'
      Size = 255
    end
    object TSpecialOLD_NUM: TSmallintField
      FieldName = 'OLD_NUM'
      Origin = 'OLD_NUM'
    end
    object TSpecialCODE_SPEC: TStringField
      FieldName = 'CODE_SPEC'
      Origin = 'CODE_SPEC'
      Size = 10
    end
  end
  object QSpecial: TFDQuery
    Connection = DM.FDConnection1
    SQL.Strings = (
      'SELECT'
      '    n_spec,'
      '    spec,'
      '    code_spec'
      'FROM'
      '    speciality'
      'WHERE'
      '    old_num = 0 '
      'ORDER BY'
      '    code_spec')
    Left = 32
    Top = 96
    object QSpecialN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object QSpecialSPEC: TStringField
      FieldName = 'SPEC'
      Origin = 'SPEC'
      Size = 255
    end
    object QSpecialCODE_SPEC: TStringField
      FieldName = 'CODE_SPEC'
      Origin = 'CODE_SPEC'
      Size = 10
    end
  end
  object QCount_Gimn: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    ),'
      '    n_spec'
      'FROM'
      '    abitura'
      'WHERE'
      '         stat_ab LIKE "3"'
      '         --stat_ab LIKE '#39'3'#39
      '    AND'
      '         status  =    :st'
      '    AND'
      '         vid_edu =    :edu'
      '    AND'
      '         n_spec  <>   1'
      '    AND'
      '        ('
      '             n_found <> 2'
      '          OR'
      '             n_found IS NULL'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 672
    Top = 112
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_GimnCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_GimnN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QCount_Selo: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        fam'
      '    ),'
      '    n_spec'
      'FROM'
      '    abitura'
      'WHERE'
      '        stat_ab          LIKE "4"'
      '        -- stat_ab LIKE '#39'4'#39
      '    AND'
      '        status           =    :st'
      '    AND'
      '        vid_edu          =    :edu'
      '    AND'
      '        konkurs          <>   3'
      '    AND'
      '        n_spec           <>   1'
      '    AND'
      '        n_privilege_exam <>   8'
      '    AND'
      '        ('
      '            n_found <> 2'
      '         OR'
      '            n_found IS NULL'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 384
    Top = 192
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_SeloCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_SeloN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QF2_All_Sdal: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    n_spec,'
      '    COUNT'
      '    ('
      '         nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status  IN (0,2,4,5)'
      '    AND'
      '        konkurs <> 5'
      '  '
      '    AND'
      '        vid_edu =  :v_e'
      '  '
      '    AND'
      '        n_spec  <> 1'
      '  '
      '    AND'
      '        NOT EXISTS'
      '        ('
      '            SELECT'
      '                nomer_ab'
      '            FROM'
      '                sertificat'
      '            WHERE'
      '                nomer_ab = nomer_ab'
      '            GROUP BY'
      '                nomer_ab'
      '            HAVING'
      '               COUNT'
      '               ('
      '                   n_predmet'
      '               ) = 3'
      '        )'
      '    AND'
      '        EXISTS'
      '        ('
      '            SELECT'
      '                DISTINCT'
      '                    nomer_ab'
      '            FROM'
      '                examen'
      '            WHERE'
      '                    nomer_ab    = nomer_ab'
      '                AND'
      '                    status_ball = 0'
      '            GROUP BY'
      '                nomer_ab'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 576
    Top = 192
    ParamData = <
      item
        Name = 'V_E'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QF2_All_SdalN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
    object QF2_All_SdalCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QF2_Sdal: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    n_spec,'
      '    COUNT'
      '    ('
      '         nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status  IN (0,5)'
      '    AND'
      '        konkurs <> 5'
      '    AND'
      '        vid_edu =  :v_e'
      '    AND'
      '        n_spec  <> 1'
      '    AND'
      '        NOT EXISTS'
      '        ('
      '            SELECT'
      '                nomer_ab'
      '            FROM'
      '                sertificat'
      '            WHERE'
      '                nomer_ab = nomer_ab'
      '            GROUP BY'
      '                nomer_ab'
      '            HAVING'
      '                COUNT'
      '                ('
      '                    n_predmet'
      '                ) = 3'
      '        )'
      '    AND'
      '        EXISTS'
      '        ('
      '            SELECT'
      '                DISTINCT'
      '                    nomer_ab'
      '            FROM'
      '                examen'
      '            WHERE'
      '                    nomer_ab    = nomer_ab'
      '                AND'
      '                    status_ball = 0'
      '            GROUP BY'
      '                nomer_ab'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 640
    Top = 192
    ParamData = <
      item
        Name = 'V_E'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QF2_SdalN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
    object QF2_SdalCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QF2_Zach: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    n_spec,'
      '    COUNT'
      '    ('
      '         nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      'WHERE'
      '        status  =  5'
      '    AND'
      '        vid_edu =  :v_e'
      '    AND'
      '        n_spec  <> 1'
      '    AND'
      '        n_found <> 2'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 672
    Top = 192
    ParamData = <
      item
        Name = 'V_E'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QF2_ZachN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
    object QF2_ZachCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QSvod_Ved: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    abitura.fam,'
      '    abitura.name,'
      '    abitura.otch,'
      '    abitura.nom_dela,'
      '    abitura.date_r,'
      '    abitura.pol,'
      '    abitura.name_edu_middle,'
      '    abitura.when_edu_middle,'
      '    abitura.stag,'
      '    abitura.stag_spec,'
      '    abitura.sport_category,'
      '    abitura.text_predmet,'
      '    abitura.ball,'
      '    abitura.middle_ball,'
      '    abitura.address_before,'
      '    abitura.konkurs,'
      '    abitura.n_ck,'
      '    privilege_one_exam.text_privilege_exam,'
      '    predmet.text_privilege_enter,'
      '    predmet.privilege_level,'
      '    abitura.sum_ball'
      'FROM'
      '    abitura'
      '        LEFT OUTER JOIN'
      '            category'
      '        ON'
      '            abitura.n_sport_category  = category.n_sport_category'
      '        LEFT OUTER JOIN'
      '            examen'
      '        ON'
      '            abitura.nomer_ab          = examen.nomer_ab'
      '        LEFT OUTER JOIN'
      '            privilege_one_exam'
      '        ON'
      '            abitura.n_privilege_exam  = privilege_one_exam.n_privilege_exam'
      '        LEFT OUTER JOIN'
      '            abitura_privilege'
      '        ON'
      '            abitura.nomer_ab          = abitura_privilege.nomer_ab'
      '        LEFT OUTER JOIN'
      '            predmet'
      '        ON'
      '            examen.n_predmet         = predmet.n_predmet'
      '        LEFT OUTER JOIN'
      '            privilege_enter'
      '        ON'
      '            abitura_privilege.n_privilege_enter = predmet.n_privilege_enter'
      'WHERE'
      '        abitura.status  =  0'
      '    AND'
      '        abitura.copy_at =  0'
      '    AND'
      '        abitura.konkurs <> 3')
    Left = 800
    Top = 192
  end
  object QSvod_Ved2: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    abitura.fam,'
      '    abitura.name,'
      '    abitura.otch,'
      '    abitura.nom_dela,'
      '    abitura.date_r,'
      '    abitura.pol,'
      '    abitura.name_edu_middle,'
      '    abitura.when_edu_middle,'
      '    abitura.stag,'
      '    abitura.stag_spec,'
      '    category.sport_category,'
      '    predmet.text_predmet,'
      '    examen.ball,'
      '    abitura.middle_ball,'
      '    abitura.address_before,'
      '    abitura.konkurs,'
      '    abitura.n_ck,'
      '    privilege_one_exam.text_privilege_exam,'
      '    pen.text_privilege_enter,'
      '    pen.privilege_level,'
      '    abitura.sum_ball,'
      '    abitura.n_specializ'
      'FROM'
      '    abitura'
      '        LEFT OUTER JOIN'
      '            category'
      '        ON'
      '            abitura.n_sport_category  = category.n_sport_category'
      '        LEFT OUTER JOIN'
      '            examen'
      '        ON'
      '            abitura.nomer_ab          = examen.nomer_ab'
      '        LEFT OUTER JOIN'
      '            privilege_one_exam'
      '        ON'
      '            abitura.n_privilege_exam  = privilege_one_exam.n_privilege_exam'
      '        LEFT OUTER JOIN'
      '            abitura_privilege'
      '        ON'
      '            abitura.nomer_ab          = abitura_privilege.nomer_ab'
      '        LEFT OUTER JOIN'
      '            predmet'
      '        ON'
      '            examen.n_predmet         = predmet.n_predmet'
      '        LEFT OUTER JOIN'
      '            privilege_enter AS pen'
      '        ON'
      '            abitura_privilege.n_privilege_enter = pen.n_privilege_enter'
      'WHERE'
      '        abitura.status  = 0'
      '    AND'
      '        abitura.copy_at = 0'
      '    AND'
      '        abitura.konkurs = 3'
      'ORDER BY'
      '    abitura.n_specializ,'
      '    abitura.sum_ball       DESC,'
      '    category.sport_category DESC,'
      '    abitura.middle_ball    DESC')
    Left = 832
    Top = 192
  end
  object QCount_special_ab: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    n_spec,'
      '    COUNT'
      '    ('
      '         nomer_ab'
      '    ),'
      '    price'
      'FROM'
      '    abitura'
      'WHERE'
      '        status  =  :st'
      '    AND'
      '        vid_edu =  :edu'
      '    AND'
      '        n_spec  <> 1'
      'GROUP BY'
      '    n_spec,'
      '    price')
    Left = 416
    Top = 192
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_special_abN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
    object QCount_special_abCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_special_abPRICE: TSmallintField
      FieldName = 'PRICE'
      Origin = 'PRICE'
    end
  end
  object QCount_Gorod: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    ),'
      '    n_spec'
      'FROM'
      '    abitura'
      'WHERE'
      '        stat_ab LIKE :n'
      '    AND'
      '        status  =    :st'
      '    AND'
      '        vid_edu =    :edu'
      '    AND'
      '        n_spec  <>   1'
      '    AND'
      '        ('
      '            n_found <> 2'
      '         OR'
      '            n_found IS NULL'
      '        )'
      '    AND'
      '        ('
      '            when_edu_middle LIKE :god'
      '         OR'
      '            when_edu_spec   LIKE :god'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 704
    Top = 112
    ParamData = <
      item
        Name = 'N'
        DataType = ftString
        ParamType = ptInput
        Size = 8
      end
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'GOD'
        DataType = ftString
        ParamType = ptInput
        Size = 30
      end>
    object QCount_GorodCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_GorodN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QCount_Stag: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    ),'
      '    n_spec'
      'FROM'
      '    abitura'
      'WHERE'
      '        status  =  :st'
      '    AND'
      '        vid_edu =  :edu'
      '    AND'
      '        n_spec  <> 1'
      '    AND'
      '        ('
      '            stag      >= 24'
      '         OR'
      '            stag_spec >= 24'
      '        )'
      '    AND'
      '        ('
      '            n_found <> 2'
      '         OR'
      '            n_found IS NULL'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 448
    Top = 192
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_StagCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_StagN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QF2_CK: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        fam'
      '    ),'
      '    n_spec'
      'FROM'
      '    abitura'
      'WHERE'
      '        status  =  5'
      '    AND'
      '        vid_edu =  0'
      '    AND'
      '        konkurs =  2'
      '    AND'
      '        n_spec  <> 1'
      '    AND'
      '        n_found =  1'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 608
    Top = 192
    object QF2_CKCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QF2_CKN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QCount_Test: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        abitura.nomer_ab'
      '    ),'
      '    abitura.n_spec'
      'FROM'
      '    abitura'
      'WHERE'
      '    EXISTS'
      '    ('
      '        SELECT'
      '            sertificat.nomer_ab'
      '        FROM'
      '            sertificat'
      '        WHERE'
      '            sertificat.nomer_ab = abitura.nomer_ab'
      '        GROUP BY'
      '            sertificat.nomer_ab'
      '        HAVING'
      '            COUNT'
      '            ('
      '                sertificat.n_predmet'
      '            ) = 3'
      '    )'
      '    AND'
      '        abitura.status  =  :st'
      '    AND'
      '        abitura.vid_edu =  :edu'
      '    AND'
      '        abitura.n_spec  <> 1'
      '    AND'
      '        ('
      '            abitura.n_found <> 2'
      '         OR'
      '            abitura.n_found IS NULL'
      '        )'
      'GROUP BY'
      '    abitura.n_spec'
      'ORDER BY'
      '    abitura.n_spec')
    Left = 480
    Top = 192
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_TestCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_TestN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QCount_CK: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    ),'
      '    n_spec'
      'FROM'
      '     abitura'
      'WHERE'
      '        status  =  :st'
      '    AND'
      '        vid_edu =  0'
      '    AND'
      '        konkurs =  2'
      '    AND'
      '        n_spec  <> 1'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 608
    Top = 112
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_CKCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_CKN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QCount_Ball_Rus_Bel_old: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    ball.ball,'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            abitura.nomer_ab'
      '    ),'
      '    abitura.n_specializ,'
      '    abitura.vid_edu'
      'FROM'
      '    abitura'
      '        INNER JOIN'
      '            examen'
      '        ON'
      '            abitura.nomer_ab = examen.nomer_ab'
      '        INNER JOIN'
      '            ball'
      '        ON'
      '            examen.nom_ball = ball.nom_ball'
      'WHERE'
      '        abitura.n_specializ <> 2'
      '    AND'
      '        abitura.n_specializ <> 5'
      '    AND'
      '        abitura.vid_edu     =  :v_d'
      '    AND'
      '        abitura.n_fac       =  :n_fac'
      '    AND'
      '        examen.n_predmet   =  :pr'
      '    AND'
      '        abitura.rus_bel     =  :rb'
      '    AND'
      '        examen.status_ball =  :st_ball'
      '    AND'
      '        abitura.status<>1'
      'GROUP BY'
      '    abitura.n_specializ,'
      '    abitura.vid_edu,'
      '    ball.ball')
    Left = 576
    Top = 112
    ParamData = <
      item
        Name = 'V_D'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PR'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'RB'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'ST_BALL'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_Ball_Rus_Bel_oldBALL: TStringField
      FieldName = 'BALL'
      Origin = 'BALL'
      Size = 15
    end
    object QCount_Ball_Rus_Bel_oldCOUNT: TIntegerField
      FieldName = 'COUNT'
      Origin = 'COUNT'
      Required = True
    end
    object QCount_Ball_Rus_Bel_oldN_SPECIALIZ: TSmallintField
      FieldName = 'N_SPECIALIZ'
      Origin = 'N_SPECIALIZ'
    end
    object QCount_Ball_Rus_Bel_oldVID_EDU: TSmallintField
      FieldName = 'VID_EDU'
      Origin = 'VID_EDU'
    end
  end
  object QCount_PO: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    ),'
      '    n_spec'
      'FROM'
      '     abitura'
      'WHERE'
      '        -- priv LIKE '#39'15.'#39
      '        priv    LIKE "15."'
      '    AND'
      '        status  =    :st'
      '    AND'
      '        vid_edu =    0'
      '    AND'
      '        n_spec  <>   1'
      '    AND'
      '        ('
      '            n_found <> 2'
      '         OR'
      '            n_found IS NULL'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 832
    Top = 112
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_POCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_PON_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QCount_Medal: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    ),'
      '    n_spec'
      'FROM'
      '     abitura'
      'WHERE'
      '        status  =    :st'
      '    AND'
      '        vid_edu =    :edu'
      '    AND'
      '        n_spec  <>   1'
      '    AND'
      '        priv    LIKE "12."'
      '    AND'
      '        ('
      '            n_found <> 2'
      '         OR'
      '            n_found IS NULL'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 736
    Top = 112
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_MedalCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_MedalN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QCount_Diplom: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    ),'
      '    n_spec'
      'FROM'
      '     abitura'
      'WHERE'
      '        status  =    :st'
      '    AND'
      '        vid_edu =    :edu'
      '    AND'
      '        n_spec  <>   1'
      '    AND'
      '        priv    LIKE "13."'
      '    AND'
      '        ('
      '            n_found <> 2'
      '         OR'
      '            n_found is null'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 640
    Top = 112
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_DiplomCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_DiplomN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QCount_Olimp: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    ),'
      '    n_spec'
      'FROM'
      '     abitura'
      'WHERE'
      '        without LIKE :n'
      '    AND'
      '        status  =    :st'
      '    AND'
      '        vid_edu =    :edu'
      '    AND'
      '        n_spec  <>   1'
      '    AND'
      '        ('
      '            n_found <> 2'
      '        OR'
      '            n_found IS NULL'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 768
    Top = 112
    ParamData = <
      item
        Name = 'N'
        DataType = ftString
        ParamType = ptInput
        Size = 5
      end
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_OlimpCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_OlimpN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QCount_Region: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    ),'
      '    n_spec'
      'FROM'
      '     abitura'
      'WHERE'
      '        gragdan  <> "#1056#1041"'
      '    AND'
      '        n_centre IN (122,123,124,125)'
      '    AND'
      '        status   =  :st'
      '    AND'
      '        vid_edu  =  :edu'
      '    AND'
      '        n_spec   <> 1'
      '    AND'
      '        ('
      '            n_found <> 2'
      '         OR'
      '            n_found IS NULL'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 352
    Top = 192
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_RegionCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_RegionN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QRegion_Stat: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    ),'
      '    n_specializ,'
      '    konkurs,'
      '    n_region'
      'FROM'
      '    abitura'
      'WHERE'
      '        status      =  0'
      '    AND'
      '        n_specializ <> 2'
      '    AND'
      '        n_specializ <> 5'
      '    AND'
      '        konkurs     <> 3'
      '    AND'
      '        n_fac       =  :n_fac'
      '    AND'
      '        vid_edu     =  :vid_edu'
      'GROUP BY'
      '    n_specializ,'
      '    n_region,'
      '    konkurs'
      'ORDER BY'
      '    n_specializ,'
      '    n_region,'
      '    konkurs')
    Left = 736
    Top = 192
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
      end>
    object QRegion_StatCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QRegion_StatN_SPECIALIZ: TSmallintField
      FieldName = 'N_SPECIALIZ'
      Origin = 'N_SPECIALIZ'
    end
    object QRegion_StatKONKURS: TSmallintField
      FieldName = 'KONKURS'
      Origin = 'KONKURS'
    end
    object QRegion_StatN_REGION: TSmallintField
      FieldName = 'N_REGION'
      Origin = 'N_REGION'
    end
  end
  object QCount_RUOR: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    ),'
      '    n_spec'
      'FROM'
      '    abitura'
      'WHERE'
      '        status  =  :st'
      '    AND'
      '        vid_edu =  :edu'
      '    AND'
      '        konkurs =  3'
      '    AND'
      '        n_spec  <> 1'
      '    AND'
      '        ('
      '            n_found <> 2'
      '        OR'
      '            n_found IS NULL'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 608
    Top = 16
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_RUORCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_RUORN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QCount_High: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        nomer_ab'
      '    ),'
      '    n_spec'
      'FROM'
      '    abitura'
      'WHERE'
      '        status  = :st'
      '    AND'
      '        vid_edu = :edu'
      '    AND'
      '        ('
      '            without LIKE '#39'5'#39
      '         OR'
      '            v_k     LIKE '#39'5'#39
      '         OR'
      '            stat_ab LIKE '#39'8'#39
      '        )'
      '    AND'
      '        n_spec <> 1'
      '    AND'
      '        ('
      '            n_found <> 2'
      '         OR'
      '            n_found IS NULL'
      '        )'
      'GROUP BY'
      '    n_spec'
      'ORDER BY'
      '    n_spec')
    Left = 576
    Top = 16
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_HighCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_HighN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QCount_Platn: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    COUNT'
      '    ('
      '        abitura.nomer_ab'
      '    ),'
      '    abitura.n_spec'
      'FROM'
      '    abitura'
      '        INNER JOIN'
      '            kol_place'
      '        ON'
      '            abitura.n_specializ = kol_place.n_specializ'
      'WHERE'
      '        abitura.konkurs <> 3'
      '    AND'
      '        abitura.status  =  :st'
      '    AND'
      '        abitura.vid_edu =  :v_ed'
      '    AND'
      '        abitura.n_spec  <> 1'
      '    AND'
      '        ('
      '            abitura.konkurs = 4'
      '         OR'
      '            ('
      '                 kol_place.kol_place = 0'
      '             AND'
      '                 kol_place.vid_edu   = :edu'
      '            )'
      '        )'
      'GROUP BY'
      '    abitura.n_spec')
    Left = 800
    Top = 112
    ParamData = <
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'V_ED'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_PlatnCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
    object QCount_PlatnN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QSport_Categ: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    category.sport_category,'
      '    abitura.n_specializ,'
      '    COUNT'
      '    ('
      '        abitura.nomer_ab'
      '    )'
      'FROM'
      '    abitura'
      '        INNER JOIN'
      '            category'
      '        ON'
      '            abitura.n_sport_category = category.n_sport_category'
      'WHERE'
      '        abitura.n_specializ      <> 2'
      '    AND'
      '        abitura.n_specializ      <> 5'
      '    AND'
      '        abitura.status           IN (0, 5)'
      '    AND'
      '        abitura.vid_edu          =  :v_e'
      '    AND'
      '        abitura.n_fac            =  :n_fac'
      '    AND'
      '        abitura.n_sport_category <> 12'
      'GROUP BY'
      '    abitura.n_specializ,'
      '    category.sport_category')
    Left = 768
    Top = 192
    ParamData = <
      item
        Name = 'V_E'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QSport_CategSPORT_CATEGORY: TStringField
      FieldName = 'SPORT_CATEGORY'
      Origin = 'SPORT_CATEGORY'
      Size = 50
    end
    object QSport_CategN_SPECIALIZ: TSmallintField
      FieldName = 'N_SPECIALIZ'
      Origin = 'N_SPECIALIZ'
    end
    object QSport_CategSPEC1: TStringField
      FieldKind = fkLookup
      FieldName = 'SPEC1'
      LookupDataSet = DM.QSpecializ
      LookupKeyFields = 'N_SPECIALIZ'
      LookupResultField = 'SPECIAL'
      KeyFields = 'N_SPECIALIZ'
      Size = 80
      Lookup = True
    end
    object QSport_CategCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ReadOnly = True
    end
  end
  object FullGrpS1Qr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    citizenship,'
      '    price,'
      '    term_edu,'
      '    konkurs,'
      '    n_sport_category,'
      '    category_if'
      'FROM'
      '    abitura'
      'WHERE'
      '    nomer_ab = :nomer_ab')
    Left = 352
    Top = 16
    ParamData = <
      item
        Name = 'NOMER_AB'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object FullGrpS1QrCITIZENSHIP: TSmallintField
      FieldName = 'CITIZENSHIP'
      Origin = 'CITIZENSHIP'
    end
    object FullGrpS1QrPRICE: TSmallintField
      FieldName = 'PRICE'
      Origin = 'PRICE'
    end
    object FullGrpS1QrTERM_EDU: TSmallintField
      FieldName = 'TERM_EDU'
      Origin = 'TERM_EDU'
    end
    object FullGrpS1QrKONKURS: TSmallintField
      FieldName = 'KONKURS'
      Origin = 'KONKURS'
    end
    object FullGrpS1QrN_SPORT_CATEGORY: TSmallintField
      FieldName = 'N_SPORT_CATEGORY'
      Origin = 'N_SPORT_CATEGORY'
    end
    object FullGrpS1QrCATEGORY_IF: TSmallintField
      FieldName = 'CATEGORY_IF'
      Origin = 'CATEGORY_IF'
    end
  end
  object CitizenQr: TFDQuery
    Connection = DM.FDConnection1
    SQL.Strings = (
      'SELECT'
      '    name'
      'FROM'
      '    countries'
      'WHERE'
      '    id = :id')
    Left = 32
    Top = 16
    ParamData = <
      item
        Name = 'ID'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object CitizenQrNAME: TStringField
      FieldName = 'NAME'
      Origin = 'NAME'
      Size = 80
    end
  end
  object LastLogQr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    id_log'
      'FROM'
      '    abitur_logbook'
      'WHERE'
      '        nomer_ab =  :nomer_ab'
      '    AND'
      '        date_out IS NULL'
      'ORDER BY'
      '    date_out DESC')
    Left = 384
    Top = 16
    ParamData = <
      item
        Name = 'NOMER_AB'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object LastLogQrID_LOG: TIntegerField
      FieldName = 'ID_LOG'
      Origin = 'ID_LOG'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
  end
  object QCount_Ball_Examen: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    ball.ball,'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            abitura.nomer_ab'
      '    ),'
      '    abitura.n_specializ,'
      '    abitura.vid_edu'
      'FROM'
      '    abitura'
      '        INNER JOIN'
      '            examen'
      '        ON'
      '            abitura.nomer_ab = examen.nomer_ab'
      '        INNER JOIN'
      '            ball'
      '        ON'
      '            examen.nom_ball = ball.nom_ball'
      'WHERE'
      '        abitura.n_specializ <> 2'
      '    AND'
      '        abitura.n_specializ <> 5'
      '    AND'
      '        abitura.vid_edu     =  :v_d'
      '    AND'
      '        abitura.n_fac       =  :n_fac'
      '    AND'
      '        examen.n_predmet   =  :pr'
      '    AND'
      '        examen.status_ball =  :st_ball'
      '    AND'
      '        abitura.status      <> 1'
      'GROUP BY'
      '    abitura.n_specializ,'
      '    abitura.vid_edu,'
      '    ball.ball')
    Left = 512
    Top = 112
    ParamData = <
      item
        Name = 'V_D'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PR'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'ST_BALL'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_Ball_ExamenBALL: TStringField
      FieldName = 'BALL'
      Origin = 'BALL'
      Size = 15
    end
    object QCount_Ball_ExamenCOUNT: TIntegerField
      FieldName = 'COUNT'
      Origin = 'COUNT'
      Required = True
    end
    object QCount_Ball_ExamenN_SPECIALIZ: TSmallintField
      FieldName = 'N_SPECIALIZ'
      Origin = 'N_SPECIALIZ'
    end
    object QCount_Ball_ExamenVID_EDU: TSmallintField
      FieldName = 'VID_EDU'
      Origin = 'VID_EDU'
    end
  end
  object QCount_Ball_Rus_Bel: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    ball.ball,'
      '    COUNT'
      '    ('
      '        DISTINCT'
      '            abitura.nomer_ab'
      '    ),'
      '    abitura.n_specializ,'
      '    abitura.vid_edu'
      'FROM'
      '    abitura'
      '        INNER JOIN'
      '            examen'
      '        ON'
      '            abitura.nomer_ab = examen.nomer_ab'
      '        INNER JOIN'
      '            sertificat'
      '        ON'
      '            abitura.nomer_ab = sertificat.nomer_ab'
      '        INNER JOIN'
      '            ball'
      '        ON'
      '            examen.nom_ball = ball.nom_ball'
      'WHERE'
      '        abitura.n_specializ <> 2'
      '    AND'
      '        abitura.n_specializ <> 5'
      '    AND'
      '        abitura.vid_edu     =  :v_d'
      '    AND'
      '        abitura.n_fac       =  :n_fac'
      '    AND'
      '        examen.n_predmet   =  :pr'
      '    AND'
      '        examen.status_ball =  :st_ball'
      '    AND'
      '        sertificat.rus_bel     =  :rb'
      '    AND'
      '        sertificat.n_predmet   =  :pr'
      '    AND'
      '        abitura.status      <> 1'
      'GROUP BY'
      '    abitura.n_specializ,'
      '    abitura.vid_edu,'
      '    ball.ball')
    Left = 544
    Top = 112
    ParamData = <
      item
        Name = 'V_D'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PR'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'ST_BALL'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'RB'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_Ball_Rus_BelBALL: TStringField
      FieldName = 'BALL'
      Origin = 'BALL'
      Size = 15
    end
    object QCount_Ball_Rus_BelCOUNT: TIntegerField
      FieldName = 'COUNT'
      Origin = 'COUNT'
      Required = True
    end
    object QCount_Ball_Rus_BelN_SPECIALIZ: TSmallintField
      FieldName = 'N_SPECIALIZ'
      Origin = 'N_SPECIALIZ'
    end
    object QCount_Ball_Rus_BelVID_EDU: TSmallintField
      FieldName = 'VID_EDU'
      Origin = 'VID_EDU'
    end
  end
  object ProtokolAllQr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    DISTINCT'
      '        fam,'
      '        name,'
      '        otch,'
      '        term_edu'
      'FROM'
      '    abitura'
      'WHERE'
      '        status      =  0'
      '    AND n_fac       =  :n_fac'
      '    AND category_if =  0'
      '    AND term_edu    <> 1'
      '    AND term_edu    <> 2'
      '    AND konkurs     =  0'
      '    AND date_priem  =  :dtate_priem'
      '    AND vid_edu     =  :vid_edu'
      '    AND price       =  :price'
      'ORDER BY'
      '    nom_dela')
    Left = 416
    Top = 16
    ParamData = <
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'DTATE_PRIEM'
        DataType = ftTimeStamp
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
      end>
    object ProtokolAllQrFAM: TStringField
      FieldName = 'FAM'
      Origin = 'FAM'
      Size = 30
    end
    object ProtokolAllQrNAME: TStringField
      FieldName = 'NAME'
      Origin = 'NAME'
      Size = 30
    end
    object ProtokolAllQrOTCH: TStringField
      FieldName = 'OTCH'
      Origin = 'OTCH'
      Size = 30
    end
    object ProtokolAllQrTERM_EDU: TSmallintField
      FieldName = 'TERM_EDU'
      Origin = 'TERM_EDU'
    end
  end
  object ProtokolCkQr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    DISTINCT'
      '        nomer_ab,'
      '        fam,'
      '        name,'
      '        otch,'
      '        term_edu'
      'FROM'
      '    abitura'
      'WHERE'
      '        status      = 0'
      '    AND'
      '        n_fac       = :n_fac'
      '    AND'
      '        category_if = 0'
      '    AND'
      '        konkurs     = 3'
      '    AND'
      '        date_priem  = :dtate_priem'
      '    AND'
      '        vid_edu     = :vid_edu'
      'ORDER BY'
      '    nom_dela')
    Left = 448
    Top = 16
    ParamData = <
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'DTATE_PRIEM'
        DataType = ftTimeStamp
        ParamType = ptInput
      end
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object ProtokolCkQrNOMER_AB: TIntegerField
      FieldName = 'NOMER_AB'
      Origin = 'NOMER_AB'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object ProtokolCkQrFAM: TStringField
      FieldName = 'FAM'
      Origin = 'FAM'
      Size = 30
    end
    object ProtokolCkQrNAME: TStringField
      FieldName = 'NAME'
      Origin = 'NAME'
      Size = 30
    end
    object ProtokolCkQrOTCH: TStringField
      FieldName = 'OTCH'
      Origin = 'OTCH'
      Size = 30
    end
    object ProtokolCkQrTERM_EDU: TSmallintField
      FieldName = 'TERM_EDU'
      Origin = 'TERM_EDU'
    end
  end
  object QProtokol: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    *'
      'FROM'
      '    protokol'
      '    ('
      '        :n_fac,'
      '        :data,'
      '        :vid_edu,'
      '        :konk,'
      '        :price'
      '    )')
    Left = 704
    Top = 192
    ParamData = <
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'DATA'
        DataType = ftTimeStamp
        ParamType = ptInput
      end
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'KONK'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PRICE'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QProtokolOUT_FAM: TStringField
      FieldName = 'OUT_FAM'
      Origin = 'OUT_FAM'
      Size = 30
    end
    object QProtokolOUT_NAME: TStringField
      FieldName = 'OUT_NAME'
      Origin = 'OUT_NAME'
      Size = 30
    end
    object QProtokolOUT_OTCH: TStringField
      FieldName = 'OUT_OTCH'
      Origin = 'OUT_OTCH'
      Size = 30
    end
    object QProtokolOUT_N_DEL: TSmallintField
      FieldName = 'OUT_N_DEL'
      Origin = 'OUT_N_DEL'
    end
    object QProtokolOUT_VK: TStringField
      FieldName = 'OUT_VK'
      Origin = 'OUT_VK'
      Size = 5
    end
    object QProtokolOUT_WITHOUT: TStringField
      FieldName = 'OUT_WITHOUT'
      Origin = 'OUT_WITHOUT'
      Size = 5
    end
  end
  object QCount_Ball: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    *'
      'FROM'
      '    kol_sertifikat'
      '    ('
      '        :n_sp,'
      '        :n_vid_edu,'
      '        :n_fac,'
      '        :predm,'
      '        :st_ball,'
      '        :r_b'
      '    )')
    Left = 544
    Top = 16
    ParamData = <
      item
        Name = 'N_SP'
        DataType = ftInteger
        ParamType = ptInput
      end
      item
        Name = 'N_VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'N_FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PREDM'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'ST_BALL'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'R_B'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_BallN10_9: TIntegerField
      FieldName = 'N10_9'
      Origin = 'N10_9'
    end
    object QCount_BallN9_8: TIntegerField
      FieldName = 'N9_8'
      Origin = 'N9_8'
    end
    object QCount_BallN8_7: TIntegerField
      FieldName = 'N8_7'
      Origin = 'N8_7'
    end
    object QCount_BallN7_6: TIntegerField
      FieldName = 'N7_6'
      Origin = 'N7_6'
    end
    object QCount_BallN6_5: TIntegerField
      FieldName = 'N6_5'
      Origin = 'N6_5'
    end
    object QCount_BallN5_4: TIntegerField
      FieldName = 'N5_4'
      Origin = 'N5_4'
    end
    object QCount_BallN4_3: TIntegerField
      FieldName = 'N4_3'
      Origin = 'N4_3'
    end
    object QCount_BallN3_2: TIntegerField
      FieldName = 'N3_2'
      Origin = 'N3_2'
    end
    object QCount_BallN2: TIntegerField
      FieldName = 'N2'
      Origin = 'N2'
    end
    object QCount_BallN1: TIntegerField
      FieldName = 'N1'
      Origin = 'N1'
    end
    object QCount_BallN0: TIntegerField
      FieldName = 'N0'
      Origin = 'N0'
    end
    object QCount_BallN_YA: TIntegerField
      FieldName = 'N_YA'
      Origin = 'N_YA'
    end
  end
  object ProtokolQr: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    abitur_logbook.nomer_ab,'
      '    abitur_logbook.nom_dela,'
      '    abitura.fam,'
      '    abitura.name,'
      '    abitura.otch,'
      '    abitur_logbook.price,'
      '    abitura.category_if,'
      '    abitur_logbook.term_edu,'
      '    abitur_logbook.konkurs'
      'FROM'
      '    abitur_logbook,'
      '    abitura'
      'WHERE'
      '        abitur_logbook.n_fac    =  :n_fac'
      '    AND abitur_logbook.vid_edu  =  :vid_edu'
      '    AND abitur_logbook.date_in  >= :date_in1'
      '    AND abitur_logbook.date_in  <  :date_in2'
      '    AND abitur_logbook.date_out IS NULL'
      '    AND abitura.nomer_ab =  abitur_logbook.nomer_ab'
      '    AND abitura.status   =  0'
      'ORDER BY'
      '    abitur_logbook.nom_dela')
    Left = 480
    Top = 16
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
        Name = 'DATE_IN1'
        DataType = ftTimeStamp
        ParamType = ptInput
      end
      item
        Name = 'DATE_IN2'
        DataType = ftTimeStamp
        ParamType = ptInput
      end>
    object ProtokolQrNOMER_AB: TIntegerField
      FieldName = 'NOMER_AB'
      Origin = 'NOMER_AB'
    end
    object ProtokolQrNOM_DELA: TSmallintField
      FieldName = 'NOM_DELA'
      Origin = 'NOM_DELA'
    end
    object ProtokolQrFAM: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'FAM'
      Origin = 'FAM'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
    object ProtokolQrNAME: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'NAME'
      Origin = 'NAME'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
    object ProtokolQrOTCH: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'OTCH'
      Origin = 'OTCH'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
    object ProtokolQrPRICE: TSmallintField
      FieldName = 'PRICE'
      Origin = 'PRICE'
    end
    object ProtokolQrCATEGORY_IF: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'CATEGORY_IF'
      Origin = 'CATEGORY_IF'
      ProviderFlags = []
      ReadOnly = True
    end
    object ProtokolQrTERM_EDU: TSmallintField
      FieldName = 'TERM_EDU'
      Origin = 'TERM_EDU'
    end
    object ProtokolQrKONKURS: TSmallintField
      FieldName = 'KONKURS'
      Origin = 'KONKURS'
    end
  end
  object QZachisl_Sertificat: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    abitura.nomer_ab,'
      '    abitura.konkurs,'
      '    abitura.fam,'
      '    abitura.name,'
      '    abitura.otch,'
      '    abitura.pasport,'
      '    abitura.n_found,'
      '    sertificat.n_predmet,'
      '    sertificat.rus_bel,'
      '    predmet.text_predmet,'
      '    sertificat.seria_s,'
      '    sertificat.nomer_s,'
      '    sertificat.balls'
      'FROM'
      '    abitura'
      '    LEFT JOIN'
      '        sertificat'
      '    ON'
      '        sertificat.nomer_ab  = abitura.nomer_ab'
      '    LEFT JOIN'
      '        predmet'
      '    ON'
      '        predmet.n_predmet = sertificat.n_predmet'
      'WHERE'
      '        abitura.status  = :s'
      '    AND abitura.vid_edu = :v'
      '    AND abitura.n_fac   = :f'
      'ORDER BY'
      '    abitura.fam,'
      '    abitura.name,'
      '    abitura.otch')
    Left = 768
    Top = 16
    ParamData = <
      item
        Name = 'S'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'V'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'F'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QZachisl_SertificatNOMER_AB: TIntegerField
      FieldName = 'NOMER_AB'
      Origin = 'NOMER_AB'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object QZachisl_SertificatKONKURS: TSmallintField
      FieldName = 'KONKURS'
      Origin = 'KONKURS'
    end
    object QZachisl_SertificatFAM: TStringField
      FieldName = 'FAM'
      Origin = 'FAM'
      Size = 30
    end
    object QZachisl_SertificatNAME: TStringField
      FieldName = 'NAME'
      Origin = 'NAME'
      Size = 30
    end
    object QZachisl_SertificatOTCH: TStringField
      FieldName = 'OTCH'
      Origin = 'OTCH'
      Size = 30
    end
    object QZachisl_SertificatPASPORT: TStringField
      FieldName = 'PASPORT'
      Origin = 'PASPORT'
      Size = 150
    end
    object QZachisl_SertificatN_FOUND: TSmallintField
      FieldName = 'N_FOUND'
      Origin = 'N_FOUND'
    end
    object QZachisl_SertificatN_PREDMET: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'N_PREDMET'
      Origin = 'N_PREDMET'
      ProviderFlags = []
      ReadOnly = True
    end
    object QZachisl_SertificatRUS_BEL: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'RUS_BEL'
      Origin = 'RUS_BEL'
      ProviderFlags = []
      ReadOnly = True
    end
    object QZachisl_SertificatTEXT_PREDMET: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'TEXT_PREDMET'
      Origin = 'TEXT_PREDMET'
      ProviderFlags = []
      ReadOnly = True
      Size = 100
    end
    object QZachisl_SertificatSERIA_S: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'SERIA_S'
      Origin = 'SERIA_S'
      ProviderFlags = []
      ReadOnly = True
      Size = 10
    end
    object QZachisl_SertificatNOMER_S: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'NOMER_S'
      Origin = 'NOMER_S'
      ProviderFlags = []
      ReadOnly = True
      Size = 15
    end
    object QZachisl_SertificatBALLS: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'BALLS'
      Origin = 'BALLS'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QCount_VK: TFDQuery
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
      '        v_k     LIKE :n'
      '    AND'
      '        status  =    :st'
      '    AND'
      '        vid_edu =    :edu'
      '    AND'
      '        n_spec  <>   1')
    Left = 640
    Top = 16
    ParamData = <
      item
        Name = 'N'
        DataType = ftString
        ParamType = ptInput
        Size = 5
      end
      item
        Name = 'ST'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCount_VKCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object Giaz01SP: TFDStoredProc
    CachedUpdates = True
    Connection = DM.FDConnection2
    StoredProcName = 'GIAZ01'
    Left = 208
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
        Name = 'DATE_IN'
        DataType = ftTimeStamp
        ParamType = ptInput
      end
      item
        Position = 3
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Position = 4
        Name = 'S_B_ALL'
        DataType = ftInteger
        ParamType = ptOutput
      end
      item
        Position = 5
        Name = 'S_B_CK'
        DataType = ftInteger
        ParamType = ptOutput
      end
      item
        Position = 6
        Name = 'S_B_2'
        DataType = ftInteger
        ParamType = ptOutput
      end
      item
        Position = 7
        Name = 'S_P'
        DataType = ftInteger
        ParamType = ptOutput
      end
      item
        Position = 8
        Name = 'S_3S'
        DataType = ftInteger
        ParamType = ptOutput
      end>
    object Giaz01SPS_B_ALL: TIntegerField
      FieldName = 'S_B_ALL'
      Origin = 'S_B_ALL'
    end
    object Giaz01SPS_B_CK: TIntegerField
      FieldName = 'S_B_CK'
      Origin = 'S_B_CK'
    end
    object Giaz01SPS_B_2: TIntegerField
      FieldName = 'S_B_2'
      Origin = 'S_B_2'
    end
    object Giaz01SPS_P: TIntegerField
      FieldName = 'S_P'
      Origin = 'S_P'
    end
    object Giaz01SPS_3S: TIntegerField
      FieldName = 'S_3S'
      Origin = 'S_3S'
    end
  end
  object GIAZ021SP: TFDStoredProc
    CachedUpdates = True
    Connection = DM.FDConnection2
    StoredProcName = 'GIAZ021'
    Left = 208
    Top = 64
    ParamData = <
      item
        Position = 1
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Position = 2
        Name = 'DATE_IN'
        DataType = ftTimeStamp
        ParamType = ptInput
      end
      item
        Position = 3
        Name = 'S_ALL'
        DataType = ftInteger
        ParamType = ptOutput
      end
      item
        Position = 4
        Name = 'S_16'
        DataType = ftInteger
        ParamType = ptOutput
      end
      item
        Position = 5
        Name = 'S_17'
        DataType = ftInteger
        ParamType = ptOutput
      end>
    object GIAZ021SPS_ALL: TIntegerField
      FieldName = 'S_ALL'
      Origin = 'S_ALL'
    end
    object GIAZ021SPS_16: TIntegerField
      FieldName = 'S_16'
      Origin = 'S_16'
    end
    object GIAZ021SPS_17: TIntegerField
      FieldName = 'S_17'
      Origin = 'S_17'
    end
  end
  object Giaz022SP: TFDStoredProc
    CachedUpdates = True
    Connection = DM.FDConnection2
    StoredProcName = 'GIAZ022'
    Left = 208
    Top = 112
    ParamData = <
      item
        Position = 1
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Position = 2
        Name = 'DATE_IN'
        DataType = ftTimeStamp
        ParamType = ptInput
      end
      item
        Position = 3
        Name = 'S_ALL'
        DataType = ftInteger
        ParamType = ptOutput
      end
      item
        Position = 4
        Name = 'S_21'
        DataType = ftInteger
        ParamType = ptOutput
      end
      item
        Position = 5
        Name = 'S_27'
        DataType = ftInteger
        ParamType = ptOutput
      end
      item
        Position = 6
        Name = 'S_22_26'
        DataType = ftInteger
        ParamType = ptOutput
      end>
    object Giaz022SPS_ALL: TIntegerField
      FieldName = 'S_ALL'
      Origin = 'S_ALL'
    end
    object Giaz022SPS_21: TIntegerField
      FieldName = 'S_21'
      Origin = 'S_21'
    end
    object Giaz022SPS_27: TIntegerField
      FieldName = 'S_27'
      Origin = 'S_27'
    end
    object Giaz022SPS_22_26: TIntegerField
      FieldName = 'S_22_26'
      Origin = 'S_22_26'
    end
  end
  object QCountAll: TFDQuery
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
      '    vid_edu = :edu')
    Left = 672
    Top = 16
    ParamData = <
      item
        Name = 'EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCountAllCOUNT: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = 'COUNT'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QSpec_Dir: TFDQuery
    Connection = DM.FDConnection1
    SQL.Strings = (
      'SELECT'
      '    n_spec_dir,'
      '    spec_dir,'
      '    spec_dir_full,'
      '    code_spec_dir,'
      '    n_spec'
      'FROM'
      '    special_direction'
      'WHERE'
      '    n_spec = :n_spec'
      'ORDER BY'
      '    code_spec_dir')
    Left = 64
    Top = 16
    ParamData = <
      item
        Name = 'N_SPEC'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object QSpec_DirN_SPEC_DIR: TIntegerField
      FieldName = 'N_SPEC_DIR'
      Origin = 'N_SPEC_DIR'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object QSpec_DirSPEC_DIR: TStringField
      FieldName = 'SPEC_DIR'
      Origin = 'SPEC_DIR'
      Size = 255
    end
    object QSpec_DirSPEC_DIR_FULL: TStringField
      FieldName = 'SPEC_DIR_FULL'
      Origin = 'SPEC_DIR_FULL'
      Size = 255
    end
    object QSpec_DirCODE_SPEC_DIR: TStringField
      FieldName = 'CODE_SPEC_DIR'
      Origin = 'CODE_SPEC_DIR'
      Size = 30
    end
    object QSpec_DirN_SPEC: TIntegerField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
  end
  object QSpecializ_for_Spec_Dir: TFDQuery
    Connection = DM.FDConnection1
    SQL.Strings = (
      'SELECT'
      '    n_specializ,'
      '    code_specializ,'
      '    special,'
      '    n_fac,'
      '    n_spec,'
      '    special_sklon,'
      '    special_direction,'
      '    n_spec_dir'
      'FROM'
      '    specializ'
      'WHERE'
      '    n_spec_dir = :n_spec_dir'
      'ORDER BY'
      '    special')
    Left = 96
    Top = 16
    ParamData = <
      item
        Name = 'N_SPEC_DIR'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object QSpecializ_for_Spec_DirN_SPECIALIZ: TSmallintField
      FieldName = 'N_SPECIALIZ'
      Origin = 'N_SPECIALIZ'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object QSpecializ_for_Spec_DirCODE_SPECIALIZ: TStringField
      FieldName = 'CODE_SPECIALIZ'
      Origin = 'CODE_SPECIALIZ'
      Size = 15
    end
    object QSpecializ_for_Spec_DirSPECIAL: TStringField
      FieldName = 'SPECIAL'
      Origin = 'SPECIAL'
      Size = 80
    end
    object QSpecializ_for_Spec_DirN_FAC: TSmallintField
      FieldName = 'N_FAC'
      Origin = 'N_FAC'
    end
    object QSpecializ_for_Spec_DirN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
    object QSpecializ_for_Spec_DirSPECIAL_SKLON: TStringField
      FieldName = 'SPECIAL_SKLON'
      Origin = 'SPECIAL_SKLON'
      Size = 80
    end
    object QSpecializ_for_Spec_DirSPECIAL_DIRECTION: TStringField
      FieldName = 'SPECIAL_DIRECTION'
      Origin = 'SPECIAL_DIRECTION'
      Size = 255
    end
    object QSpecializ_for_Spec_DirN_SPEC_DIR: TIntegerField
      FieldName = 'N_SPEC_DIR'
      Origin = 'N_SPEC_DIR'
    end
  end
  object QSpecializ_for_Spec: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    n_specializ,'
      '    code_specializ,'
      '    special,'
      '    n_fac,'
      '    n_spec,'
      '    special_sklon,'
      '    special_direction,'
      '    n_spec_dir'
      'FROM'
      '    specializ'
      'WHERE'
      '    n_spec = :n_spec')
    Left = 736
    Top = 16
    ParamData = <
      item
        Name = 'N_SPEC'
        DataType = ftSmallint
        ParamType = ptInput
        Value = Null
      end>
    object QSpecializ_for_SpecN_SPECIALIZ: TSmallintField
      FieldName = 'N_SPECIALIZ'
      Origin = 'N_SPECIALIZ'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
    end
    object QSpecializ_for_SpecCODE_SPECIALIZ: TStringField
      FieldName = 'CODE_SPECIALIZ'
      Origin = 'CODE_SPECIALIZ'
      Size = 15
    end
    object QSpecializ_for_SpecSPECIAL: TStringField
      FieldName = 'SPECIAL'
      Origin = 'SPECIAL'
      Size = 80
    end
    object QSpecializ_for_SpecN_FAC: TSmallintField
      FieldName = 'N_FAC'
      Origin = 'N_FAC'
    end
    object QSpecializ_for_SpecN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
    end
    object QSpecializ_for_SpecSPECIAL_SKLON: TStringField
      FieldName = 'SPECIAL_SKLON'
      Origin = 'SPECIAL_SKLON'
      Size = 80
    end
    object QSpecializ_for_SpecSPECIAL_DIRECTION: TStringField
      FieldName = 'SPECIAL_DIRECTION'
      Origin = 'SPECIAL_DIRECTION'
      Size = 255
    end
    object QSpecializ_for_SpecN_SPEC_DIR: TIntegerField
      FieldName = 'N_SPEC_DIR'
      Origin = 'N_SPEC_DIR'
    end
  end
  object QCountSpecNapravl: TFDQuery
    Connection = DM.FDConnection2
    SQL.Strings = (
      'SELECT'
      '    text,'
      '    SUM'
      '    ('
      '        kol_place'
      '    )'
      'FROM'
      '    kol_place'
      'WHERE'
      '        n_specializ IN (:s)'
      '    AND vid_edu     =  :vid_edu'
      '    AND kol_place   <> -1'
      'GROUP BY'
      '    text')
    Left = 704
    Top = 16
    ParamData = <
      item
        Name = 'S'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'VID_EDU'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QCountSpecNapravlTEXT: TSmallintField
      FieldName = 'TEXT'
      Origin = 'TEXT'
    end
    object QCountSpecNapravlSUM: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'SUM'
      Origin = 'SUM'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object QBall_prohod: TFDQuery
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
      '        status      = 5'
      '    AND'
      '        vid_edu     = :v'
      '    AND'
      '        n_specializ = :sp'
      '    AND'
      '        price       = :pr'
      '    AND'
      '        konkurs     = :k')
    Left = 512
    Top = 16
    ParamData = <
      item
        Name = 'V'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'SP'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'PR'
        DataType = ftSmallint
        ParamType = ptInput
      end
      item
        Name = 'K'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object QBall_prohodMIN: TFloatField
      AutoGenerateValue = arDefault
      FieldName = 'MIN'
      Origin = 'MIN'
      ProviderFlags = []
      ReadOnly = True
    end
  end
end
