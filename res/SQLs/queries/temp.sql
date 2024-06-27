/* abitur decanat*/


BloskUpSQL.sql
/* : TFDUpdateSQL -> INSERT */
INSERT INTO
    block_edit
    (
        block,
        n_fac,
        perepodacha,
        note,
        note_perepodacha
    )
VALUES
    (
        :block,
        :n_fac,
        :perepodacha,
        :note,
        :note_perepodacha
    )

/* : TFDUpdateSQL -> UPDATE (Modify) */
UPDATE
    block_edit AS b
SET
    b.block            = :block,
    b.n_fac            = :n_fac,
    b.perepodacha      = :perepodacha,
    b.note             = :note,
    b.note_perepodacha = :note_perepodacha
WHERE
    b.id_block = :old_id_block

/* : TFDUpdateSQL -> DELETE */
DELETE FROM
    block_edit
WHERE
    id_block = :old_id_block




QSelectUpdateSQL.sql
/* : TFDUpdateSQL -> UPDATE (Modify) */
UPDATE
    abitura AS a
SET
    a.status           = :status,
    a.d_prikaz_include = :d_prikaz_include,
    a.n_prikaz_include = :n_prikaz_include,
    a.n_found          = :n_found
WHERE
    a.nomer_ab = :old_nomer_ab



PasportUp.sql
/* : TFDUpdateSQL -> INSERT */
INSERT INTO
    personal_docum
    (
        nomer,
        id_type,
        series,
        number,
        personal_number,
        date_give,
        date_valid,
        who_give,
        n_region
    )
VALUES
    (
        :nomer,
        :id_type,
        :series,
        :number,
        :personal_number,
        :date_give,
        :date_valid,
        :who_give,
        :n_region
    )  

/* : TFDUpdateSQL -> UPDATE (Modify) */
UPDATE
    personal_docum
SET
    nomer           = :nomer,
    id_type         = :id_type,
    series          = :series,
    number          = :number,
    personal_number = :personal_number,
    date_give       = :date_give,
    date_valid      = :date_valid,
    who_give        = :who_give,
    n_region        = :n_region
WHERE
    nomer           = :old_nomer

/* : TFDUpdateSQL -> DELETE */
DELETE FROM
    personal_docum
WHERE
    nomer = :old_nomer




ListDocFDUp.sql
/* : TFDUpdateSQL -> DELETE */
DELETE FROM
    list_doc
WHERE
        nomer_ab = :old_nomer_ab
    AND
        n_doc    = :old_n_doc

/* : TFDUpdateSQL -> INSERT */
INSERT INTO
    list_doc
    (
        nomer_ab,
        n_doc,
        date_doc,
        doc_index
    )
VALUES
    (
        :nomer_ab,
        :n_doc,
        :date_doc,
        :doc_index
    )




-- : TFDUpdateSQL -> INSERT
-- : TFDUpdateSQL -> UPDATE (Modify)
-- : TFDUpdateSQL -> DELETE
-- : TFDUpdateSQL -> LOCK
-- : TFDUpdateSQL -> UNLOCK
-- : TFDUpdateSQL -> FETCHROW
















/* WithOutTestLogQr.sql
SELECT
    p.short_name,
    d.short_name
FROM
    privilege AS p,
    priveleg_details AS d,
    priveleg_array AS a
WHERE
        p.n_without_tests = :sel_priv
    AND
        d.id_det          = a.id_det
    AND
        a.n_item          = :dat_priv
    AND
        a.id_priv         = p.id_priv */




/* WithoutQr.sql
SELECT
    p.id_priv,
    p.name_priv,
    p.n_without_tests
FROM
    privilege AS p
WHERE
    p.n_without_tests > 0
ORDER BY
    p.n_without_tests */




/* WithoutDetQr.sql
SELECT
    a.n_item,
    a.id_det,
    d.name_detais
FROM
    priveleg_array AS a,
    priveleg_details AS d
WHERE
        a.id_priv = :id_priv
    AND
        d.id_det  = a.id_det */




/* WithoutCntQr.sql
SELECT
    COUNT
    (
        p.id_priv
    )
FROM
    privilege AS p
WHERE
    p.n_without_tests > 0 */




/* VO2KSpecializQr.sql
SELECT
    a.nomer_ab
FROM
    abitura AS a
WHERE
        a.status       = 0
    AND
        a.n_specializ  = :sp
    AND
        a.vid_edu      = :v_e
    AND
        (
            a.term_edu = 4
         OR
            a.term_edu = 5
        )
    AND
        a.n_fac        = :n_fac
    AND
        a.price        = :price */




/* UpDateOutQr.sql
UPDATE
    abitur_logbook AS a
SET
    a.date_out = :date_out
WHERE
    a.id_log   = :id_log */




/* StatusQueueQr.sql
UPDATE
    abitur_queue AS a
SET
    a.fam          = :fam,
    a.name         = :name,
    a.otch         = :otch,
    a.status_queue = :status_queue,
    a.n_specializ  = :specializ,
    a.n_spec       = :n_spec,
    a.vid_edu      = :vid_edu,
    a.category_ab  = :category_ab,
    a.category_if  = :category_if,
    a.category_edu = :category_edu,
    a.term_edu     = :term_edu,
    a.price        = :price,
    a.konkurs      = :konkurs
WHERE
    a.id_ab        = :id_ab */




/* Stat3hAll2Qr.sql
SELECT
    a.konkurs,
    count
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.status      = 0
    AND
        a.n_fac       = :n_fac
    AND
        a.vid_edu     = :vid_edu
    AND
        a.term_edu    = 1
    AND
        a.price       = :price
    AND
        a.category_if = 0
GROUP BY
    a.konkurs */




/* Stat3hAll1Qr.sql
SELECT
    a.konkurs,
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.status  = 0
    AND
        a.n_fac   = :n_fac
    AND
        a.vid_edu = :vid_edu
    AND
            (
                 a.term_edu = 0
              OR
                 a.term_edu = 2
            )
        AND
            a.price       = :price
        AND
            a.n_specializ = :n_specializ
        AND
            (
                 a.category_if = 0
              OR
                 (
                       a.category_if = 1
                   AND
                       a.price       = 0
                 )
            )
GROUP BY
    a.konkurs */




/* SspecQ.sql
SELECT
    a.nomer_ab
FROM
    abitura AS a
WHERE
        a.status      = 0
    AND
        a.n_specializ = :sp
    AND
        a.vid_edu     = :v_e
    AND
        a.term_edu    = 1
    AND
        a.n_fac       = :n_fac
    AND
        a.price       = :price */




/* SportQuery.sql
-- FDConnection1 - Decanat
SELECT
    s.nomer,
    s.sport_category,
    s.sud_category,
    s.who_give,
    s.d_prikaz_sport,
    s.n_prikaz_sport,
    s.n_vid_sport,
    s.who_give_sud,
    s.d_prikaz_sud,
    s.n_prikaz_sud
FROM
    sport AS s
WHERE
    s.nomer = :nomer */




/* SPFDQ1.sql
INSERT INTO
    faculty 
    (
        n_fac,
        fac,
        fac1,
        kod_fac,
        dean,
        fac_rp
    )
VALUES
    (
        :n_fac,
        :fac,
        :fac1,
        :kod_fac,
        :dean,
        :fac_rp
    ) */




/* SPFDQ.sql
-- FDConnection1 - Decanat
SELECT
    *
FROM
    faculty */




/* SpecQr.sql
-- FDConnection1 - Decanat
SELECT
    s.special
FROM
    specializ AS s
WHERE
    s.n_specializ = :n_specializ */




/* SpecializQr.sql
-- FDConnection1 - Decanat
SELECT
    s.n_specializ,
    s.special
FROM
    specializ AS s */



/* SpecializNameQr.sql
-- FDConnection1 - Decanat
SELECT
    s.special,
    s.special_direction
FROM
    specializ AS s
WHERE
    s.n_specializ = :n_specializ */




/* SpecFacQr.sql
-- FDConnection1 - Decanat
SELECT
    s.special,
    s.n_specializ
FROM
    specializ AS s
WHERE
    s.n_fac = :n_fac
ORDER BY
    s.special */




/* SertSelLogQr.sql
SELECT
    p.text_predmet,
    s.seria_s,
    s.nomer_s,
    s.rus_bel,
    s.balls
FROM
    sertificat AS s,
    predmet AS p
WHERE
        p.n_predmet = s.n_predmet
    AND
        s.nomer_ab = :nomer_ab
ORDER BY
    s.rus_bel */




/* SerteficatSelQr.sql
SELECT
    s.n_predmet,
    s.seria_s,
    s.nomer_s,
    s.balls,
    s.describe,
    s.rus_bel
FROM
    sertificat AS s
WHERE
    s.nomer_ab = :nomer_ab */




/* SelPrivLogQr.sql
SELECT
    p.n_priv,
    p.sel_priv,
    p.dat_priv
FROM
    privileg_log AS p
WHERE
    p.id_log = :id_log */




/* SelectLogAbiturQr.sql
SELECT
    l.nom_dela,
    a.nomer_ab,
    a.fam,
    a.name,
    a.otch,
    a.citizenship,
    l.n_specializ,
    l.date_in,
    l.nom_dela,
    l.id_log,
    l.address_before,
    l.n_ck,
    a.d_prikaz_include,
    a.n_prikaz_include,
    l.date_out,
    l.konkurs,
    l.term_edu,
    l.category
FROM
    abitur_logbook AS l,
    abitura AS a
WHERE
        l.nomer_ab =  a.nomer_ab
    AND
        l.n_fac    =  :n_fac
    AND
        l.date_in  >= :date_in1
    AND
        l.date_in  <  :date_in2
    AND
        l.vid_edu  =  :vid_edu 
    AND
        (
             (
                  (
                       l.term_edu = 0
                    OR
                       l.term_edu = 3
                  )
              AND
                  :term_edu = 0
             )
         OR
             (
                  (
                       l.term_edu = 1
                    OR
                       l.term_edu = 2
                    OR
                       l.term_edu = 4
                    OR
                       l.term_edu = 5
                  )
              AND
                  :term_edu = 1
             )
        )
    AND
        l.price = :price
ORDER BY
    l.nom_dela */




/* RegionUpCKQr.sql
UPDATE
    abitur_logbook AS a
SET
    a.n_ck   = :n_ck
WHERE
    a.id_log = :id_log */




/* RegionQr.sql
-- FDConnection1 - Decanat
SELECT
    r.centre
FROM
    regional_centre AS r
WHERE
    r.n_centre = :n_centre */




/* RegionNameQr.sql
-- FDConnection1 - Decanat
SELECT
    r.centre
FROM
    regional_centre AS r
WHERE
    r.n_centre = :n_centre */




/* QUndo_Abit.sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.status,
    a.nomer_ab
FROM
    abitura AS a
WHERE
        a.n_fac  = :n_fac
    AND
        a.status = :st
ORDER BY
    a.fam,
    a.name,
    a.otch */




/* QType_street.sql
-- FDConnection1 - Decanat
SELECT
    t.id,
    t.type,
    t.short_type
FROM
    type_street AS t
ORDER BY
    t.id */



/* QType_locality.sql
-- FDConnection1 - Decanat
SELECT
    l.n_type,
    MIN
    (
        l.name_type
    ) AS name_type,
    l.short_type_name
FROM
    type_locality AS l
GROUP BY
    l.n_type,
    l.short_type_name */



/* QToDekanat.sql
-- FDConnection1 - Decanat
SELECT
    p.nomer,
    p.fam,
    p.name,
    p.otch,
    p.pol,
    p.n_found,
    p.place_r,
    p.papa,
    p.mama,
    p.mariage,
    p.education,
    p.phone,
    p.address_papa,
    p.address_mama,
    p.name_educ,
    p.when_educ,
    p.where_educ,
    p.middle_b,
    p.n_vid_sport,
    p.vid_edu,
    p.n_fac,
    p.kurs,
    p.n_spec,
    p.n_specializ,
    p.n_group,
    p.status_people,
    p.inc_group,
    p.work_before,
    p.address_before,
    p.address,
    p.address_life,
    p.data_r,
    p.n_prikaz_include,
    p.d_prikaz_include,
    p.n_prikaz_kurs,
    p.scholarship,
    p.vid_edu_include,
    p.n_found_include,
    p.n_centre,
    p.gragdan,
    p.address_posle,
    p.phone_posle,
    p.pasport,
    p.personal_nomer,
    CAST
    (
        NULL AS blob
    ) AS photo,
    CAST
    (
        NULL AS blob
    ) AS digit_sign,
    p.date_end,
    p.d_include,
    p.id_street,
    p.house,
    p.flat,
    p.postcode,
    p.number
FROM
    people AS p
ORDER BY
    p.nomer */



/* QSum_Ball.sql
SELECT
    a.nomer_ab,
    SUM
    (
        e.ball
    ),
    a.sum_ball,
    a.middle_ball
FROM
    abitura AS a
        INNER JOIN
            examen AS e
                ON
                    a.nomer_ab = e.nomer_ab  
WHERE
        a.status = 0    
    AND
        a.n_fac  = :n_fac
GROUP BY
    a.nomer_ab,
    a.sum_ball,
    a.middle_ball */




/* QSum_Ball_Nomer.sql
SELECT
    SUM
    (
        e.ball
    ),
    a.sum_ball,
    a.middle_ball,
    a.nomer_ab
FROM
    abitura AS a
        INNER JOIN
            examen AS e
                ON
                    a.nomer_ab = e.nomer_ab  
WHERE
    a.nomer_ab=:nomer
GROUP BY
    a.sum_ball,
    a.middle_ball,
    a.nomer_ab */




/* QStreet.sql
-- FDConnection1 - Decanat
SELECT
    s.id,
    s.name_in_rus
FROM
    street AS s 
WHERE
        s.type_street = :type_street
    AND
        s.id_locality = :id_locality
ORDER BY
    s.name_in_rus */




/* QStatisticEveryDay.sql
SELECT
    k.n_specializ,
    SUM
    (
        k.kol_place
    )
FROM
    k.kol_place AS k
WHERE
        k.n_fac   =  :n_fac
    AND
        k.vid_edu =  :vid_edu
    AND
        k.text    != 1
GROUP BY
    k.n_specializ */




/* QStatistic_Every_Day.sql
SELECT
    a.konkurs,
    a.n_specializ,
    COUNT
    (
        a.nomer_ab
    ),
    a.vid_edu,
    a.price,
    o.order_sp
FROM
    abitura AS a
        LEFT JOIN
            order_specializ AS o
                ON
                    a.n_specializ = o.n_specializ
WHERE
        a.n_specializ <> 2
    AND
        a.n_specializ <> 5
    AND
        a.n_fac       =  :n_fac
    AND
        a.status      =  0
    AND
        a.vid_edu     =  :vid_edu
GROUP BY
    a.vid_edu,
    o.order_sp,
    a.n_specializ,
    a.konkurs,
    a.price */




/* QStatistic_Every_Day_Special.sql
SELECT
    a.konkurs,
    a.n_spec,
    COUNT
    (
        a.nomer_ab
    ),
    a.vid_edu,
    a.price
FROM
    abitura AS a
WHERE
        a.status  = 0 
    AND
        a.vid_edu = :vid_edu
    AND
        a.n_spec  = :n_spec
GROUP BY
    a.vid_edu,
    a.n_spec,
    a.konkurs,
    a.price */




/* QStatistic_Every_Day_Ball.sql
SELECT
    a.konkurs,
    a.price,
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.status      = 0
    AND
        a.n_fac       = :n_fac 
    AND
        a.vid_edu     = :vid_edu
    AND
        a.n_specializ = :n_sp
GROUP BY
    a.konkurs,
    a.price */




/* QStatistic_Every_Day_Ball_Price.sql
SELECT
    a.konkurs,
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.status      = 0
    AND
        a.n_fac       = :n_fac 
    AND
        a.vid_edu     = :vid_edu
    AND
        a.price       = :price
    AND
        a.n_specializ = :n_sp
GROUP BY
    a.konkurs,
    a.price */




/* QSpisok_Spec.sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.fam || ' '|| a.name || ' ' || a.otch AS fio,
    a.n_specializ,
    a.nom_group,
    a.n_privilege_exam,
    a.n_ck,
    a.nomer_ab,
    a.gragdan,
    a.vid_edu,
    a.konkurs,
    a.n_sport_category,
    a.v_k,
    a.priv,
    a.without,
    a.n_fac,
    a.middle_ball,
    a.price
FROM
    abitura AS a
WHERE
        a.n_fac  = :n_fac
    AND
        a.status = 0
ORDER BY
    a.vid_edu,
    a.n_specializ,
    a.fam,
    a.name,
    a.otch */




/* QSpisoc_Group.sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.n_specializ,
    a.nom_group,
    a.n_privilege_exam,
    a.n_ck,
    a.nomer_ab,
    a.gragdan,
    a.vid_edu,
    a.konkurs,
    a.n_sport_category,
    a.v_k,
    a.priv,
    a.without,
    a.n_fac,
    a.middle_ball,
    a.price,
    a.sum_ball
FROM
    abitura AS a
WHERE
        a.n_specializ <> 2  
    AND
        a.n_specializ <> 5  
    AND
        a.n_fac       =  :n_fac
    AND
        a.status      =  0
ORDER BY
    a.nom_group,
    a.n_specializ,
    a.fam,
    a.name,
    a.otch */




/* QSpisoc_Group_Pol.sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.n_specializ,
    a.nom_group,
    a.n_privilege_exam,
    a.n_ck,
    a.nomer_ab,
    a.gragdan,
    a.vid_edu,
    a.konkurs,
    a.n_sport_category,
    a.v_k,
    a.priv,
    a.without,
    a.n_fac,
    a.middle_ball,
    a.price,
    a.sum_ball
FROM
    abitura AS a
WHERE
        a.n_specializ <> 2  
    AND
        a.n_specializ <> 5  
    AND
        a.n_fac       =  :n_fac
    AND
        a.status      =  0
    AND
        a.pol         =  :pol
ORDER BY
    a.nom_group,
    a.n_specializ,
    a.fam,
    a.name,
    otch */




/* QSpecializPlan_Priem.sql
SELECT
    DISTINCT
        s.n_specializ,
        s.special,
        s.n_spec,
        s.n_spec_dir
FROM
    kol_place AS k
        INNER JOIN
            specializ AS s
                ON
                    k.n_specializ = s.n_specializ
WHERE
        k.vid_edu = :vid_edu
    AND
        k.n_fac   = :fac
ORDER BY
    s.special */




/* QSpecializ.sql
SELECT
    s.n_specializ,
    s.code_specializ,
    s.special,
    s.n_fac,
    s.n_spec,
    s.special_direction
FROM
    specializ AS s
WHERE
        s.n_specializ <> 2
    AND
        s.n_specializ <> 5
    AND
        s.n_specializ <> 49
    AND
        s.n_specializ <> 6
    AND
        s.n_fac       =  :n_fac
ORDER BY
    s.special */




/* QShow_Result_Exam.sql
SELECT
    DISTINCT
        a.fam,
        a.name,
        a.otch,
        e.nom_ball,
        a.nomer_ab,
        e.n_predmet,
        e.ball,
        e.status_ball,
        a.nom_dela
FROM
    examen AS e
        RIGHT OUTER JOIN
            abitura AS a
                ON
                    e.nomer_ab = a.nomer_ab  
WHERE
        a.status = 0
    AND
        a.nom_group =:n_gr
    AND
        e.n_predmet=:pr
ORDER BY
    a.fam,
    a.name,
    a.otch */




/* QShkala.sql
-- FDConnection1 - Decanat
SELECT
    s.ball,
    s.inc_shkala,
    s.rus_bel
FROM
    shkala AS s
WHERE
        s.n_predmet =  :n_pr
    AND
        s.max_ball  >= :n_ball
    AND
        s.min_ball  <= :n_balls */




QSertificatToDekanat.sql




/* QSertificat.sql
SELECT
    s.nomer_ab,
    s.n_predmet,
    s.seria_s,
    s.nomer_s,
    s.balls,
    s.describe,
    s.rus_bel,
    s.price,
    s.year_s
FROM
    sertificat AS s
WHERE
    s.nomer_ab = :nomer */



/* QSertificat_Res.sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.vid_edu,
    a.nom_group,
    a.n_fac,
    a.rus_bel,
    s.nomer_ab,
    s.n_predmet,
    s.seria_s,
    s.nomer_s,
    s.balls,
    s.describe
FROM
    abitura AS a
        INNER JOIN
            sertificat AS s
                ON
                    a.nomer_ab = s.nomer_ab  
WHERE
        a.n_fac     = :fac
    AND
        a.nom_group = :gr
    AND
        s.n_predmet = :pr */




/* QSertificat_ex_list.sql
SELECT
    p.text_predmet,
    a.date_priem,
    e.ball,
    s.rus_bel
FROM
    examen AS e
        INNER JOIN
            abitura AS a
                ON
                    e.nomer_ab  = a.nomer_ab
        inner JOIN
            sertificat AS s
                ON
                    a.nomer_ab  = s.nomer_ab
        INNER JOIN
            predmet AS p
                ON
                    e.n_predmet = p.n_predmet
WHERE 
        a.nomer_ab    = :nomer
    AND 
        e.status_ball = 1
    AND
        e.nomer_ab    = s.nomer_ab
    AND
        e.n_predmet   = s.n_predmet */




/* QSelect_ab.sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.pol,
    a.place_r,
    a.address_before,
    a.address_life,
    a.middle_ball,
    a.name_edu_middle,
    a.name_edu_spec,
    a.where_edu_middle,
    a.where_edu_spec,
    a.when_edu_middle,
    a.when_edu_spec,
    a.mama,
    a.papa,
    a.address_mama,
    a.address_papa,
    a.work_mama,
    a.work_papa,
    a.n_vid_sport,
    a.n_sport_category,
    a.phone,
    a.date_r,
    a.education,
    a.work_before,
    a.nomer_ab,
    a.status,
    a.d_prikaz_include,
    a.n_prikaz_include,
    a.n_found,
    a.n_region,
    a.citizenship,
    a.n_privilege_exam,
    q.photo,
    q.digit_sign,
    a.n_ck,
    a.v_k,
    a.priv,
    a.without,
    a.n_langvich,
    a.n_centre,
    a.pasport,
    a.personal_nomer,
    a.id_type,
    a.date_v,
    a.date_ok,
    a.organ_v,
    a.street,
    a.house,
    a.flat,
    a.postcode
FROM
    abitura AS a,
    abitur_queue AS q
WHERE
        a.vid_edu     = :edu
    AND
        q.id_ab       = a.id_ab_queue
    AND
        a.n_fac       = :fac  
    AND
        a.status      = 0  
    AND
        a.n_specializ = :n_sp  
    AND
        a.price       = :p
ORDER BY
    a.fam,
    a.name,
    a.otch */




/* QResult_Exam.sql
SELECT
    e.nomer_ab,
    e.n_predmet,
    e.nom_ball,ball,
    e.status_ball
FROM
    examen AS e */




/* QReport_Rasp.sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.fam || ' ' || a.name || ' ' || a.otch AS fio,
    a.n_specializ,
    a.vid_edu,
    a.n_fac,
    a.nom_attest,
    a.nom_diplom,
    a.name_edu_middle,
    a.name_edu_spec,
    a.where_edu_middle,
    a.where_edu_spec,
    a.when_edu_middle,
    a.when_edu_spec,
    a.nom_dela,
    a.date_priem,
    a.nom_group,
    a.photo
FROM
    abitura AS a
WHERE
    a.nomer_ab = :n_ab */




/* QRep_Sel_Exerc.sql
SELECT
    s.num_exerc_grp,
    e.name_exerc
FROM
    sel_exercize AS s,
    exercise AS e
WHERE
        s.id_exerc = e.id_exerc
    AND
        s.nomer_ab = :nomer_ab
ORDER BY
    s.num_exerc_grp */




/* QRep_Abitura.sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.nom_group
FROM
    abitura AS a
WHERE
    a.nomer_ab = :nomer_ab */




/* QRegion_Center.sql
-- FDConnection1 - Decanat
SELECT
    r.n_centre,
    r.n_region,
    r.centre,
    r.flag
FROM
    regional_centre AS r
WHERE
    r.n_region = :region
ORDER BY
    r.centre */



/* QProverka_sert.sql
SELECT
    a.nomer_ab
FROM
    abitura AS a
WHERE
    (
         a.without IS NULL
      OR
         a.without =  ''
    )
    AND
        a.konkurs <> 4
    AND
        a.rus_bel IS NULL
    AND
        NOT a.nomer_ab =
            SOME
            (
                SELECT
                    s.nomer_ab
                FROM
                    sertificat AS s
                WHERE
                    s.n_predmet = 4
            ) 
    AND
        a.nomer_ab = :nomer */




/* QProverka_RYOR.sql
SELECT
    a.fam,
    a.n_fac,
    a.vid_edu,
    a.name_edu_middle,
    a.priv
FROM
    abitura AS a
WHERE
    (
         a.name_edu_middle LIKE 'УОР'
      OR
         a.name_edu_spec   LIKE 'УОР'
    )
    AND
        a.priv NOT LIKE '13.'
AND
    a.nomer_ab = :nomer */




/* QPrivToDekanat.sql
-- FDConnection1 - Decanat
SELECT
    p.n_priv,
    p.nomer,
    p.vid_priv,
    p.uch_god,
    p.text_priv,
    p.doc_priv,
    p.data_c,
    p.data_po,
    p.describe
FROM
    priv AS p */


/* QPlanPriemPrice.sql
SELECT
    k.n_specializ,
    k.kol_place
FROM
    kol_place AS k
WHERE
        k.n_fac       = :n_fac
    AND
        k.vid_edu     = :vid_edu
    AND
        k.n_specializ = :spec
    AND
        k.text        = 0
    AND
        k.price       = :price */




/* QPlanPriem2Price.sql
SELECT
    k.n_specializ,
    k.kol_place
FROM
    kol_place AS k
WHERE
        k.n_fac       = :n_fac
    AND
        k.vid_edu     = :vid_edu
    AND
        k.n_specializ = :spec
    AND
        k.text        = 1
    AND
        k.price       = :price */




/* QPlan_Priem_Price.sql
SELECT
    k.n_specializ,
    SUM
    (
        k.kol_place
    ),
    k.vid_edu,
    k.text,
    k.price,
    o.order_sp
FROM
    kol_place AS k
        LEFT JOIN
            order_specializ AS o
                ON
                    k.n_specializ = o.n_specializ
WHERE
        k.n_specializ <> 2
    AND
        k.n_specializ <> 5  
    AND
        k.n_fac       =  :n_fac
    AND
        k.vid_edu     =  :vid_edu
    AND
        k.text        =  :text
    AND
        k.price       =  :price
GROUP BY
    k.vid_edu,
    k.text,
    k.price,
    o.order_sp,
    k.n_specializ */




/* QPlan_Priem_Konk.sql
SELECT
    k.n_specializ,
    k.text,
    k.kol_place
FROM
    kol_place AS k
WHERE
        k.n_specializ <> 2
    AND
        k.n_specializ <> 5
    AND
        k.n_fac       =  :n_fac
    AND
        k.vid_edu     =  :vid_edu
    and
        k.n_specializ =  :n_sp
GROUP BY
    k.n_specializ,
    k.text,
    k.kol_place */




/* QPlan_Priem_Konk_Special.sql
SELECT
    s.n_spec,
    k.text,
    SUM
    (
        k.kol_place
    ) AS sum1
FROM 
    kol_place AS k
        INNER JOIN
            specializ AS s
                ON
                    k.n_specializ = s.n_specializ  
WHERE
        k.vid_edu = :vid_edu
    AND
        s.n_spec  = :n_sp
GROUP BY
    s.n_spec,
    k.text */




/* QPlan_Priem_Konk_All_Param.sql
SELECT
    k.n_specializ,
    k.kol_place
FROM
    kol_place AS k
WHERE
        k.n_fac   = :n_fac
    AND
        k.vid_edu = :vid_edu
    AND
        k.text    = :text
    AND
        k.price   = :price */




/* QPlan_Priem_CK.sql
SELECT
    k.n_specializ,
    SUM
    (
        k.kol_place
    ),
    k.vid_edu
FROM
    kol_place AS k
WHERE
        k.n_specializ <> 2  
    AND
        k.n_specializ <> 5  
    AND
        k.text        =  2
    AND
        k.vid_edu     =  :vid_edu 
GROUP BY
    k.vid_edu,
    k.n_specializ */




/* QPlan_Priem_CK_Special.sql
SELECT
    s.n_spec,
    SUM
    (
        k.kol_place
    ) AS sum1,
    k.vid_edu
FROM
    kol_place AS k
        INNER JOIN
            specializ AS s
                ON
                    k.n_specializ = s.n_specializ  
WHERE  
        k.text    = 2
    AND
        k.vid_edu = :vid_edu
GROUP BY
    k.vid_edu,
    s.n_spec */




/* QPlan_Priem_All.sql
SELECT
    k.n_specializ,
    SUM
    (
        k.kol_place
    ),
    k.vid_edu,
    o.order_sp
FROM
    kol_place AS k
        LEFT JOIN
            order_specializ AS o
                ON
                    k.n_specializ = o.n_specializ
WHERE
        k.n_specializ <> 2
    AND
        k.n_specializ <> 5  
    AND
        k.n_fac       =  :n_fac
    AND
        k.vid_edu     =  :vid_edu
GROUP BY
    k.vid_edu,
    o.order_sp,
    k.n_specializ */




/* QPlan_Priem_All_Special.sql
SELECT
    s.n_spec,
    s.code_spec,
    SUM
    (
        k.kol_place
    ) AS sum1,
    k.vid_edu,
    s.spec
FROM
    kol_place AS k
        INNER JOIN
            specializ AS z
                ON
                    k.n_specializ = z.n_specializ
        INNER JOIN
            speciality AS s
                ON
                    z.n_spec      = s.n_spec  
WHERE
    k.vid_edu = :vid_edu
GROUP BY
    k.vid_edu,
    s.code_spec,
    s.n_spec,
    s.spec */




/* QPersonalDocum.sql
-- FDConnection1 - Decanat
SELECT
    p.id_type,
    p.name_type
FROM
    personal_type AS p */




/* QNoticeSpec.sql
-- FDConnection1 - Decanat
SELECT
    d.code_spec_dir,
    s.s_dir
FROM
    special_direction AS d,
    specializ AS s
WHERE
        s.n_specializ = :n_specializ
    AND
        d.n_spec_dir  = s.n_spec_dir */



/* QNoticeFIO.sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.address_before,
    a.n_prikaz_include,
    a.d_prikaz_include,
    a.n_fac,
    a.n_specializ,
    a.term_edu,
    a.vid_edu
FROM
    abitura AS a
WHERE
    a.nomer_ab = :nomer_ab */



/* QNoticeFac.sql
-- FDConnection1 - Decanat
SELECT
    f.fac
FROM
    faculty AS f
WHERE
    f.n_fac = :n_fac */




/* QN_group.sql
SELECT
    n.n_group,
    n.nom_group,
    n.vid_edu,
    n.describe,
    n.n_fac,
    n.n_count
FROM
    n_group AS n
WHERE
        n.n_fac    =    :fac
    AND
        n.vid_edu  =    :edu
    AND
        n.describe LIKE :spec */




/* QMax_Nomer_Ab.sql
SELECT
    MAX
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
    a.n_fac = :n_fac */




/* QMax_Nom_Dela.sql
SELECT
    MAX
    (
        a.nom_dela
    )
FROM
    abitura AS a
WHERE
    a.n_fac = :n_fac */




/* QLocality.sql
-- FDConnection1 - Decanat
SELECT
    l.id,
    l.n_district,
    l.name_locality
FROM
    locality AS l
WHERE
        l.n_district    = :district
    AND
        l.type_locality = :n_type
ORDER BY
    l.name_locality */




/* QLittle_Spisoc_GR.sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.nomer_ab
FROM
    abitura AS a
WHERE
        a.status =    0
    AND
        a.n_fac  =    :fac
    AND
        a.priv   LIKE '10'
ORDER BY
    a.fam,
    a.name,
    a.otch */




/* QListDocToDekanat.sql
-- FDConnection1 - Decanat
SELECT
    l.nomer,
    l.name_doc,
    l.doc_date,
    l.doc_index,
    l.note
FROM
    list_doc AS l */




/* QLetterSourceKol.sql
SELECT
    COUNT
    (
        a.nomer_ab,
    )
FROM
    abitura AS a
WHERE
        a.n_fac  = :n_fac
    AND
        a.status = 0 */




/* QLetterSource.sql
SELECT
    a.nomer_ab,
    a.fam,
    a.name,
    a.otch,
    a.address_before
FROM
    abitura AS a
WHERE
        a.n_fac  = :n_fac
    AND
        a.status = 0
ORDER BY
    a.fam,
    a.name,
    a.otch */




/* QLangvichToDekanat.sql
-- FDConnection1 - Decanat
SELECT
    l.n_langvich,
    l.nomer
FROM
    langvich_ball AS l */



/* QLangvich.sql
-- FDConnection1 - Decanat
SELECT
    l.n_langvich,
    l.langv
FROM
    langvich AS l */




/* QKod_Spec.sql
-- FDConnection1 - Decanat
SELECT
    s.special_direction
FROM
    specializ AS s
WHERE
    s.n_specializ = :n_specializ */




/* QKod_Fac.sql
-- FDConnection1 - Decanat
SELECT
    f.fac
FROM
    faculty AS f
WHERE
    f.n_fac = :n_fac */




/* QIP.sql
-- FDConnection1 - Decanat
SELECT
    i.n_ip,
    i.ip,
    i.ip_name,
    i.gruppa,
    i.program,
    i.flag
FROM
    ip AS i
WHERE
        i.program = 6
    AND
        i.flag    = 1
    AND
        i.ip      = :ip_n */




/* QInc_Gr_Old.sql
-- FDConnection1 - Decanat
SELECT
    i.inc_gr_old,
    i.inc_group,
    i.n_group,
    i.vid_edu,
    i.god,
    i.describe
FROM
    inc_group_old AS i */



/* QGroup_Count.sql
SELECT
    a.nom_group,
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.n_fac  = :n_fac
    AND
        a.status = 0
GROUP BY
    a.nom_group */




/* QGroup_Count_Spec.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.n_fac       = :n_fac
    AND
        a.status      = 0
    AND
        a.nom_group   = :n_gr
    AND
        a.n_specializ = :n_sp */




/* QGIACYearSredVil.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura As a
WHERE
        a.vid_edu         =    :vid_edu
    AND
        a.status          =    0
    AND
        a.education       =    0
    AND
        a.when_edu_middle =    :year
    AND
        a.town_village    LIKE '1'
    AND
        a.konkurs         <>   5 */




/* QGIACYearSredSpec.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu         =  :vid_edu
    AND
        a.status          =  0
    AND
        a.education       =  :education 
    AND
        a.when_edu_middle =  :year
    AND
        a.konkurs         <> 5 */



/* QGIACYearSredCity.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu         =    :vid_edu
    AND
        a.status          =     0
    AND
        a.education       =     0
    AND
        a.when_edu_middle =    :year
    AND
        a.town_village    LIKE '0'
    AND
        a.konkurs         <>    5 */




/* QGIACYearSred.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu         =  :vid_edu
    AND
        a.status          =  0
    AND
        a.education       =  0
    AND
        a.when_edu_middle =  :year
    AND
        a.konkurs         <> 5 */




/* QGIACSirot.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu =    :vid_edu
    AND
        a.status  =     0
    AND
        a.v_k LIKE '1' -- here abitura.v_k contains <null>s */




/* QGIACPtu.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu =    :vid_edu
    AND
        a.status  =     0
    AND
        (
             a.priv LIKE '9.'  -- here abitura.priv contains <null>s
          OR 
             a.priv LIKE '10.' -- here abitura.priv contains <null>s
        ) */




/* QGIACOlimp.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu = :vid_edu
    AND
        a.status  = 0
    AND
        (
             a.without LIKE '2' -- here abitura.without contains <null>s
          OR 
             a.without LIKE '3' -- here abitura.without contains <null>s
        ) */




/* QGIACMil.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu =    :vid_edu
    AND
        a.status  =     0
    AND
        a.v_k LIKE '5' -- here abitura.v_k contains <null>s */




/* QGIACMedal.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu = :vid_edu
    AND
        a.status  = 0
    AND
        a.priv LIKE '8.' -- here abitura.priv contains <null>s */




/* QGIACKursi.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu =    :vid_edu
    AND
        a.status  =    0
    AND
        a.priv    LIKE '12.' -- here abitura.priv contains <null>s */




/* QGIACInCel.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu = :vid_edu
    AND
        a.price   = :price
    AND
        a.status  = 0
    AND
        a.konkurs = 1
    AND
        (
             a.n_specializ = 4
          OR
             a.n_specializ = 57
        ) */




/* QGIACInAll.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu = :vid_edu
    AND
        a.price   = :price
    AND
        a.status  = 0
    AND
        (
             a.n_specializ = 4
          OR
             a.n_specializ = 57
        ) */




/* QGIACForeigner.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu     = :vid_edu
    AND
        a.status      = 0
    AND
        a.category_if = 1 */




/* QGIACEdOSredVil.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu      =    :vid_edu
    AND
        a.status       =     0
    AND
        a.education    =     0
    AND
        a.town_village LIKE '1'
    AND
        a.konkurs      <>    5 */



/* QGIACEdOSredCity.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu      =    :vid_edu
    AND
        a.status       =     0
    AND
        a.education    =     0
    AND
        a.town_village LIKE '0'
    AND
        a.konkurs      <>    5 */




/* QGIACEdOSred.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu   =  :vid_edu
    AND
        a.status    =  0
    AND
        a.education =  :education
    AND
        a.konkurs   <> 5 */




/* QGIACEdLic.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu     =    :vid_edu
    AND
        a.status      =    0
    AND
        a.konkurs     <>   5
    AND
        a.type_school LIKE '3' */




/* QGIACCKSpec.sql
SELECT
    SUM
    (
        c.kol_p
    )
FROM
    ck AS c
WHERE
        c.n_specializ = 4
    OR
        c.n_specializ = 57 */




/* QGIACAllSpec.sql
SELECT
    SUM
    (
        k.kol_place
    )
FROM
    kol_place AS k
WHERE
        k.vid_edu = :vid_edu
    AND
        k.price   = :price
    AND
    (
            k.n_specializ = 4
        OR
            k.n_specializ = 57
    ) */




/* QGIACAllPrivileg1.sql
SELECT
    SUM
    (
        k.kol_place
    )
FROM
    kol_place AS k
WHERE
        k.vid_edu = :vid_edu
    AND
        k.price   = :price
    AND
    (
            k.n_specializ = 4
        OR
            k.n_specializ = 57
    ) */




/* QGIACAllPrivileg.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu = :vid_edu
    AND
        a.status  = 0
    AND
        (
              a.konkurs = 3
          OR
             (
                   a.v_k     <> ""
               AND
                   a.konkurs =  2
             )
        ) */




/* QGIACAll.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu = :vid_edu
    AND
        a.status  = 0 */




/* QGIAC3Sert.sql
SELECT
    COUNT
    (
        a.nomer_ab
    )
FROM
    abitura AS a
WHERE
        a.vid_edu =  :vid_edu
    AND
        a.status  =  0
    AND
        a.n_fac   =  4
    AND
        a.konkurs <> 2
    AND
        a.konkurs <> 4
    AND
        a.konkurs <> 5 */




/* QGIAC2kSpec.sql
SELECT
    SUM
    (
        k.kol_place
    )
FROM
    kol_place AS k
WHERE
        vk.id_edu = :vid_edu
    AND
        k.price   = :price
    AND
        k.text    = 1
    AND
        (
             k.n_specializ = 4  
          OR
             k.n_specializ = 57
        ) */



/* QFotoSign.sql
SELECT
    a.photo,
    a.digit_sign,
    a.nomer_ab
FROM
    abitura AS a
WHERE
        a.n_fac    = :n_fac
    AND
        a.status   = 0
    AND
        a.nomer_ab = :n_ab */




/* QFotoQeue.sql
SELECT
    a.id_ab_queue,
    q.photo,
    q.digit_sign
FROM
    abitur_queue AS q,
    abitura AS a
WHERE
        a.id_ab_queue = q.id_ab
    AND
        a.nomer_ab    = :n_ab */




/* QFindAbiturExerc.sql
SELECT
    e.id_sel_exerc,
    e.id_exerc
FROM
    sel_exercize AS e
WHERE
        e.nomer_ab      = :nomer_ab
    AND
        e.num_exerc_grp = :num_exerc_grp */




/* QExerc_Grp.sql
SELECT
    e.id_exerc,
    e.name_exerc
FROM
    exercise AS e
WHERE
    e.id_exerc
        IN
        (
            SELECT
                c.id_exerc
            FROM
                control_exerc AS c
            WHERE
                    c.n_specializ   = :n_specializ
                AND
                    c.pol           = :pol
                AND
                    c.num_exerc_grp = :num_exerc_grp
        ) */




/* QExamSpec.sql
SELECT
    a.fam,
    e.ball,
    e.status_ball,
    e.n_predmet,
    a.name,
    a.otch,
    a.pol,
    a.konkurs,
    a.nom_dela,
    a.vid_edu,
    a.nomer_ab,
    a.rus_bel,
    e.nom_ball,
    a.without,
    a.term_edu,
    a.education,
    a.category_if,
    a.n_sport_category,
    a.price
FROM
    abitura AS a
        LEFT OUTER JOIN
            examen AS e
                ON
                    a.nomer_ab = e.nomer_ab  
WHERE
        a.status      = 0
    AND
        a.nom_group   = :n_gr
    AND
        a.n_fac       = :n_fac
    AND
        a.n_specializ = :n_sp
ORDER BY
    a.fam,
    a.name,
    a.otch,
    e.n_predmet */




/* QExam.sql
SELECT
    a.fam,
    e.ball,
    e.status_ball,
    e.n_predmet,
    a.name,
    a.otch,
    a.konkurs,
    a.nom_dela,
    a.vid_edu,
    a.nomer_ab,
    a.rus_bel,
    e.nom_ball,
    a.without,
    a.term_edu,
    a.education,
    a.category_if,
    a.n_sport_category,
    a.price
FROM
    abitura AS a
        LEFT OUTER JOIN
            examen AS e
                ON
                    a.nomer_ab = e.nomer_ab  
WHERE
        a.status    = 0
    AND
        a.nom_group = :n_gr
    AND
        a.n_fac     = :n_fac
ORDER BY
    a.fam,
    a.name,
    a.otch,
    e.n_predmet */




/* QEducation.sql
SELECT
    e.id,
    e.nomer_ab,
    e.nom_doc,
    e.n_edu_doc,
    e.name_edu,
    e.where_edu,
    e.when_edu
FROM
    education AS e
WHERE
    e.nomer_ab = :nomer */




/* QDistrict.sql
-- FDConnection1 - Decanat
SELECT
    n_region,
    n_district,
    name_district
FROM
    district
WHERE
    n_region = :region
ORDER BY
    name_district */





/* QDelite.sql
DELETE FROM
    examen
WHERE
    nomer_ab = :nomer */




/* QControl_Exerc.sql
SELECT
    e.name_exerc
FROM
    control_exerc AS c,
    exercise AS e
WHERE
        c.n_specializ   = :n_specializ
    AND
        c.pol           = :pol
    AND
        c.num_exerc_grp = :num_exerc_grp
    AND
        e.id_exerc      = c.id_exerc */




/* QCkToDekanat.sql
-- FDConnection1 - Decanat
SELECT
    c.n_ck,
    c.nomer,
    c.n_region,
    c.n_centre,
    c.customer,
    c.n_specializ,
    c.status_ck
FROM
    ck AS c */




/* QCk.sql
SELECT
    c.n_ck,
    c.n_specializ,
    c.n_region,
    c.text_dep,
    c.kol_p,
    c.customer_place
FROM
    ck AS c
WHERE
        c.n_specializ <> 2
    AND c.n_specializ <> 5
    AND c.n_specializ =  :n_spec */



/* QCK_Kol_Plan.sql
SELECT
    c.kol_place
FROM
    ck_plan AS c
WHERE
    c.n_specializ = :n_specializ */




/* QCenter.sql
-- FDConnection1 - Decanat
SELECT
    r.n_centre,
    r.n_region,
    r.centre,
    r.flag
FROM
    regional_centre AS r
WHERE
    r.n_region = :n_region
ORDER BY
    r.centre */



/* QAdress.sql
-- FDConnection1 - Decanat
SELECT
    ds.name_district,
    tl.name_type,
    lc.name_locality,
    ts.type,
    ds.n_district,
    ds.n_region,
    tl.n_type,
    lc.id AS local_id,
    ts.id AS type_street
FROM
    district AS ds,
    (
        SELECT
            t_l.n_type,
            MIN
            (
                t_l.name_type
            ) AS name_type
        FROM
            type_locality AS t_l
        GROUP BY
            t_l.n_type
    ) AS tl,
    locality AS lc,
    type_street AS ts,
    street AS st
WHERE
        st.type_street   = ts.id
    AND
        st.id_locality   = lc.id
    AND
        lc.type_locality = tl.n_type
    AND
        lc.n_district    = ds.n_district
    AND
        st.id            = :id */
/* select district.name_district, type_local.name_type, locality.name_locality, type_street.type,
  district.n_district, district.n_region, type_local.n_type, locality.id as local_id, type_street.id as type_street
 from district,
 (select type_locality.n_type, min(type_locality.name_type) as name_type
  from type_locality
  group by type_locality.n_type) as type_local,
  locality, type_street, street
where street.type_street = type_street.id
and street.id_locality = locality.id
and locality.type_locality = type_local.n_type
and locality.n_district = district.n_district
and street.id = :id */



/* QAdd_N_Group.sql
SELECT
    n.n_group,
    n.nom_group,
    n.vid_edu,
    n.describe,
    n.n_fac,
    n.n_count
FROM
    n_group AS n
WHERE
    n.n_fac = :fac
ORDER BY
    n.vid_edu,
    n.nom_group */




/* QAbitura.sql
SELECT
    a.address_before,
    a.address_life,
    a.address_mama,
    a.address_papa,
    a.category_ab,
    a.category_if,
    a.citizenship,
    a.d_prikaz_include,
    a.date_priem,
    a.date_r,
    a.date_v,
    a.date_vozvrat,
    a.education,
    a.fam,
    a.gragdan,
    a.konkurs,
    a.langv_ball,
    a.mama,
    a.middle_ball,
    a.n_centre,
    a.n_ck,
    a.n_fac, n_found,
    a.n_langvich,
    a.n_prikaz_include,
    a.n_region,
    a.n_spec,
    a.n_specializ,
    a.n_sport_category,
    a.n_vid_sport,
    a.name,
    a.name_edu_middle,
    a.name_edu_spec,
    a.nom_attest,
    a.nom_dela,
    a.nom_diplom,
    a.nom_group,
    a.nomer_ab,
    a.organ_v,
    a.otch,
    a.papa,
    a.pasport,
    a.personal_nomer,
    a.phone,
    a.place_r,
    a.pol,
    a.price,
    a.rus_bel,
    a.stag,
    a.stag_spec,
    a.status,
    a.sum_ball,
    a.term_edu,
    a.town_village,
    a.type_school,
    a.vid_edu,
    a.when_edu_middle,
    a.when_edu_spec,
    a.where_edu_middle,
    a.where_edu_spec,
    a.work_before,
    a.work_mama,
    a.work_papa,
    a.id_type,
    a.date_ok,
    a.disabled,
    a.street,
    a.house,
    a.flat,
    a.postcode
FROM
    abitura AS a
WHERE
        a.n_fac  = :n_fac
    AND
        a.status = 0
ORDER BY
    a.nom_dela */




/* QAbitur_Priv_Enter.sql
SELECT
    a.nomer_ab,
    a.n_priv
FROM
    abitur_privileg AS a
WHERE
    a.nomer_ab = :n_ab */




/* QAbFIOPol.sql
SELECT
    a.fam,
    a.name,
    a.otch,
    a.pol
FROM
    abitura AS a
WHERE
    a.nomer_ab = :nomer_ab */




/* QAb_Pr_Enter.sql
SELECT
    a.nomer_ab,
    a.n_priv
FROM
    abitur_privileg AS a
ORDER BY
    a.nomer_ab */





/* QAb_P.sql
SELECT
    a.n_ab_p,
    a.nomer_ab,
    a.vid_edu_do,
    a.vid_edu_po,
    a.nom_dela_do,
    a.nom_dela_po,
    a.nom_group_do,
    a.nom_group_po,
    a.n_specializ_do,
    a.n_specializ_po,
    a.n_spec_do,
    a.n_spec_po,
    a.n_ck,
    a.konkurs_do,
    a.konkurs_po,
    a.date_p,
    a.price_do,
    a.price_po
FROM
    ab_p AS a */




/* PrivQr.sql
SELECT
    a.n_priv,
    a.sel_priv,
    a.dat_priv
FROM
    abitur_privileg AS a
WHERE
        a.nomer_ab = :nomer_ab
    AND
        a.n_priv   = :n_priv */




/* PrivilegLogSelQr.sql
SELECT
    a.n_priv,
    a.sel_priv,
    a.dat_priv
FROM
    abitur_privileg AS a
WHERE
    a.nomer_ab = :nomer_ab */




/* PrivCnttQr.sql
SELECT
    COUNT
    (
        a.sel_priv
    )
FROM
    abitur_privileg AS a
WHERE
        a.nomer_ab = :nomer_ab
    AND
        a.n_priv   = :n_priv */




/* PrintDocQr.sql
SELECT
    a.nomer_ab,
    a.fam,
    a.name,
    a.otch
FROM
    abitura AS a
WHERE
        a.n_fac       = :n_fac
    AND
        a.vid_edu     = :vid_edu
    AND
        a.n_specializ = :n_specializ
    AND
        a.status      = 5
ORDER BY
    a.fam,
    a.name,
    a.otch */




/* PasportFDQ.sql
-- FDConnection1 - Decanat
SELECT
    p.nomer,
    p.id_type,
    p.series,
    p.number,
    p.personal_number,
    p.date_give,
    p.date_valid,
    p.who_give,
    p.n_region
FROM
    personal_docum AS p
ORDER BY
    p.nomer */




/* OutTestQr.sql
SELECT
    p.short_name,
    d.short_name
FROM
    privilege AS p,
    priveleg_details AS d,
    priveleg_array AS a
WHERE
        p.n_out_tests = :sel_priv
    AND
        a.n_item      = :dat_priv
    AND
        d.id_det      = a.id_det
    AND
        a.id_priv     = p.id_priv */




/* OutQr.sql
SELECT
    p.id_priv,
    p.name_priv,
    p.n_out_tests
FROM
    privilege AS p
WHERE
    p.n_out_tests > 0
ORDER BY
    p.n_out_tests */




/* OutDetQr.sql
SELECT
    a.n_item,
    a.id_det,
    d.name_detais
FROM
    priveleg_array AS a,
    priveleg_details AS d
WHERE
        a.id_priv = :id_priv
    AND
        d.id_det  = a.id_det */




/* OutCntQr.sql
SELECT
    COUNT
    (
        p.id_priv
    )
FROM
    privilege AS p
WHERE
    p.n_out_tests > 0 */




/* OtherPrivQr.sql
SELECT
    p.short_name
FROM
    privilege AS p
WHERE
    p.n_others = :sel_priv */





/* MaxExrcQr.sql
SELECT
    MAX
    (
        c.id_control_exerc
    )
FROM
    control_exerc AS c */




/* LogLastQr.sql
SELECT
    a.id_log,
    a.date_out
FROM
    abitur_logbook AS a
WHERE
    a.nomer_ab = :nomer_ab
ORDER BY
    a.date_in DESC */




/* LogIDSelQr.sql
SELECT
    a.id_log
FROM
    abitur_logbook AS a
WHERE
    a.nomer_ab = :nomer_ab
ORDER BY
    a.date_in DESC */




/* ListDocFDQ.sql
SELECT
    l.n_doc,
    d.text_doc,
    l.nomer_ab,
    l.date_doc,
    l.doc_index,
    d.date_doc AS date_docum,
    d.index_doc
FROM
    list_doc AS l,
    docum AS d
WHERE
        l.n_doc    = d.n_doc
    AND
        l.nomer_ab = :nomer_ab */




/* LangSelQr.sql
-- FDConnection1 - Decanat
SELECT
    l.langv
FROM
    langvich AS l
WHERE
    l.n_langvich = :n_langvich */




/* KodSpecializQr.sql
-- FDConnection1 - Decanat
SELECT
    d.code_spec_dir
FROM
    special_direction AS d,
    specializ AS s
WHERE
        d.n_spec      = s.n_spec
    AND
        s.n_specializ = :n_specializ
    AND
        d.n_spec_dir  = s.n_spec_dir */





/* InfQr.sql
SELECT
    p.id_priv,
    p.name_priv,
    p.n_others
FROM
    privilege AS p
WHERE
    p.n_others > 0
ORDER BY
    p.n_others */




/* InfCntQr.sql
SELECT
    COUNT
    (
        p.id_priv
    )
FROM
    privilege AS p
WHERE
    p.n_others > 0 */




/* IdAbQueueQr.sql
UPDATE
    abitura AS a
SET
    a.id_ab_queue = :id_ab_queue
WHERE
    a.nomer_ab    = :nomer_ab */




/* GrazdanToDekanatQr.sql
-- FDConnection1 - Decanat
SELECT
    c.short_name
FROM
    countries_ocrb AS c
WHERE
    c.digital_code = :id */




/* FIOSearchQr.sql
SELECT
    q.id_ab,
    q.status_queue,
    q.fam,
    q.name,
    q.otch,
    q.photo,
    q.digit_sign,
    q.n_fac,
    q.n_specializ,
    q.n_spec,
    q.vid_edu,
    q.category_ab,
    q.category_if,
    q.category_edu,
    q.term_edu,
    q.price,
    q.konkurs,
    (
        q.fam  || ' ' ||
        q.name || ' ' ||
        q.otch
    ) AS fio
FROM
    abitur_queue AS q
WHERE
        (
            q.fam  || ' ' ||
            q.name || ' ' ||
            q.otch
        )
            LIKE '%'|| :fio || '%'
    AND
        q.n_fac = :n_fac
    AND
        (
             q.status_queue = 104           -- dean allowed to keep in ABITURA
          OR
             q.status_queue = 304           -- registered online (dean allowed)
        ) 
    AND
        (
            q.id_ab
                NOT IN
                (
                    SELECT
                        a.id_ab_queue
                    FROM
                        abitura AS a        -- here is no documents
                )
        OR
            q.id_ab
                IN
                (
                    SELECT
                        a.id_ab_queue
                    FROM
                        abitura AS a
                    WHERE
                            a.status = 0    -- active student
                        OR
                            a.status = 1    -- took the documents
                        OR
                            a.status = 6    -- registered online
                )
        )
ORDER BY
    q.fam,
    q.name,
    q.otch */




/* DocumInListQ.sql
SELECT
    d.n_doc,
    d.text_doc,
    d.date_doc,
    d.index_doc
FROM
    docum AS d
WHERE
    d.n_doc = :n_doc */




/* DocumFDQ.sql
SELECT
    d.n_doc,
    d.text_doc
FROM
    docum AS d
WHERE
    d.n_doc
        NOT IN
        (
            SELECT
                l.n_doc
            FROM
                list_doc AS l
            WHERE
                l.nomer_ab = :nomer_ab
        )
ORDER BY
    d.n_doc */




/* CountryQr.sql
-- FDConnection1 - Decanat
SELECT
    c.digital_code,
    c.full_name,
    c.short_name
FROM
    countries_ocrb AS c
ORDER BY
    c.short_name */




/* ContrySelQr.sql
SELECT
    c.short_name
FROM
    countries_ocrb AS c
WHERE
    c.digital_code = :id */




/* CntrlExrcQr.sql
SELECT
    e.id_exerc,
    e.name_exerc
FROM
    exercise AS e
ORDER BY
    e.name_exerc */




/* CkRegionQr.sql
-- FDConnection1 - Decanat
SELECT
    r.n_centre,
    r.n_region,
    r.centre
FROM
    regional_centre AS r
WHERE
    r.n_region < 8
ORDER BY
    r.centre */




/* CertificLogInsQr.sql
INSERT INTO
    certificates_logbook
    (
        id_log,
        n_predmet,
        seria_s,
        nomer_s,
        ball,
        describe,
        rus_bel
    )
VALUES
    (
        :id_log,
        :n_predmet,
        :seria_s,
        :nomer_s,
        :ball,
        :describe,
        :rus_bel
    ) */




/* CategUpQr.sql
UPDATE
    abitur_logbook
SET
    category = :category
WHERE
    id_log   = :id_log */




/* BlockQ.sql
SELECT
    *
FROM
    block_edit
WHERE
    n_fac = :fac */




/* BlockBtnQr.sql
SELECT
    b.id_block,
    b.add_abitur,
    b.took_doc1,
    b.took_doc2,
    b.re_inside_fac,
    b.restor_list
FROM
    block_edit AS b
WHERE
    b.n_fac = :n_fac */




/* AdrLogLastQr.sql
SELECT
    a.id_log,
    a.nomer_ab,
    a.date_in
FROM
    abitur_logbook AS a
WHERE
    a.nomer_ab = :nomer_ab
ORDER BY
    a.date_in DESC */




/* AdresOutQr.sql
UPDATE
    abitur_logbook
SET
    address_before = :address_before
WHERE
    id_log         = :id_log */




/* AddrLogUpQr.sql
UPDATE
    abitur_logbook
SET
    address_before = :address
WHERE
    id_log         = :id_log */




/* AbiturSirTmpQr.sql
SELECT
    a.dat_priv
FROM
    abitur_privileg AS a
WHERE
        a.nomer_ab = :nomer_ab
    AND
        a.n_priv   = 1
    AND
        a.sel_priv = 1 */




/* AbiturLogInsQr.sql
INSERT INTO
    abitur_logbook
    (
        nom_dela,
        nomer_ab,
        date_in,
        vid_edu,
        price,
        term_edu,
        address_before,
        n_ck,
        n_specializ,
        n_fac,
        konkurs,
        category
    )
VALUES
    (
        :nom_dela,
        :nomer_ab,
        :date_in,
        :vid_edu,
        :price,
        :term_edu,
        :address_before,
        :n_ck,
        :n_specializ,
        :n_fac,
        :konkurs,
        :category
    ) */




/* AbiturInvTmpQr.sql
SELECT
    a.dat_priv
FROM
    abitur_privileg AS a
WHERE
        a.nomer_ab = :nomer_ab
    AND
        a.n_priv   = 2
    AND
        a.sel_priv = 8 */




/* AbiturCompQr.sql
SELECT
    a.nomer_ab,
    a.n_fac,
    a.n_specializ,
    a.n_spec,
    a.vid_edu,
    a.category_ab,
    a.category_if,
    a.education,
    a.term_edu,
    a.price,
    a.konkurs,
    a.status
FROM
    abitura AS a
WHERE
    a.id_ab_queue = :id_ab_queue */



-- TDataSource
/*
[]: DMUnit/TDataSource/BlockDS.md
[]: DMUnit/TDataSource/CkRegionDS.md
[]: DMUnit/TDataSource/CntrExrcDS.md
[]: DMUnit/TDataSource/CountryDS.md
[]: DMUnit/TDataSource/DSAb_P.md
[]: DMUnit/TDataSource/DSAb_Pr_Enter.md
[]: DMUnit/TDataSource/DSAbitur_Priv_Enter.md
[]: DMUnit/TDataSource/DSAbitura.md
[]: DMUnit/TDataSource/DSAdd_N_Group.md
[]: DMUnit/TDataSource/DSAdress.md
[]: DMUnit/TDataSource/DSBall.md
[]: DMUnit/TDataSource/DSCategory.md
[]: DMUnit/TDataSource/DSCenter.md
[]: DMUnit/TDataSource/DSCk.md
[]: DMUnit/TDataSource/DSCkQ.md
[]: DMUnit/TDataSource/DSCkToDekanat.md
[]: DMUnit/TDataSource/DSDistrict.md
[]: DMUnit/TDataSource/DSDocum.md
[]: DMUnit/TDataSource/DSEducation.md
[]: DMUnit/TDataSource/DSEduDoc.md
[]: DMUnit/TDataSource/DSExam.md
[]: DMUnit/TDataSource/DSExamSpec.md
[]: DMUnit/TDataSource/DSFaculty.md
[]: DMUnit/TDataSource/DSFoundation.md
[]: DMUnit/TDataSource/DSGroup_Count_Spec.md
[]: DMUnit/TDataSource/DSGroup_Count.md
[]: DMUnit/TDataSource/DSInc_Gr_Old.md
[]: DMUnit/TDataSource/DSKol_Place.md
[]: DMUnit/TDataSource/DSLangvich.md
[]: DMUnit/TDataSource/DSLangvichToDekanat.md
[]: DMUnit/TDataSource/DSLittle_Spisoc_GR.md
[]: DMUnit/TDataSource/DSLocality.md
[]: DMUnit/TDataSource/DSMax_Nom_Dela.md
[]: DMUnit/TDataSource/DSMax_Nomer_Ab.md
[]: DMUnit/TDataSource/DSPasport.md
[]: DMUnit/TDataSource/DSPass_User.md
[]: DMUnit/TDataSource/DSPersonalDocum.md
[]: DMUnit/TDataSource/DSPlan_Priem_All.md
[]: DMUnit/TDataSource/DSPlan_Priem_CK.md
[]: DMUnit/TDataSource/DSPredmet.md
[]: DMUnit/TDataSource/DSPrivToDekanat.md
[]: DMUnit/TDataSource/DSQSertificat_Res.md
[]: DMUnit/TDataSource/DSQShkala.md
[]: DMUnit/TDataSource/DSRegion_Center.md
[]: DMUnit/TDataSource/DSRegion.md
[]: DMUnit/TDataSource/DSReport_Rasp.md
[]: DMUnit/TDataSource/DSResult_Exam.md
[]: DMUnit/TDataSource/DSSelect_ab.md
[]: DMUnit/TDataSource/DSSertificat.md
[]: DMUnit/TDataSource/DSShow_Result_Exam.md
[]: DMUnit/TDataSource/DSSpecializ.md
[]: DMUnit/TDataSource/DSSpecializPlan_Priem.md
[]: DMUnit/TDataSource/DSSpisoc_Group_Pol.md
[]: DMUnit/TDataSource/DSSpisoc_Group.md
[]: DMUnit/TDataSource/DSStatistic_Every_Day.md
[]: DMUnit/TDataSource/DSStreet.md
[]: DMUnit/TDataSource/DSSum_Ball_Nomer.md
[]: DMUnit/TDataSource/DSSum_Ball.md
[]: DMUnit/TDataSource/DSToDekanat.md
[]: DMUnit/TDataSource/DSType_locality.md
[]: DMUnit/TDataSource/DSType_street.md
[]: DMUnit/TDataSource/DSUndo_Abit.md
[]: DMUnit/TDataSource/DSVid_Sport.md
[]: DMUnit/TDataSource/ExercDS.md
[]: DMUnit/TDataSource/FIOSearchDS.md
[]: DMUnit/TDataSource/Increment_GroupSource.md
[]: DMUnit/TDataSource/ListDocFDDS.md
[]: DMUnit/TDataSource/Selection_CommitteeDS.md
[]: DMUnit/TDataSource/SpecializDS.md
[]: DMUnit/TDataSource/SPFDDataSource.md
[]: DMUnit/TDataSource/SportQSource.md
*/
-- TFDConnection

[]: DMUnit/TFDConnection/FDConnection1.md
[]: DMUnit/TFDConnection/FDConnection2.md

-- TFDPhysFBDriverLink

[]: DMUnit/TFDPhysFBDriverLink/FDPhysFBDriverLink1.md

-- TFDQueries:
/*
[1]:   DMUnit/TFDQuery/AbiturCompQr.md
[2]:   DMUnit/TFDQuery/AbiturInvTmpQr.md
[3]:   DMUnit/TFDQuery/AbiturLogInsQr.md
[4]:   DMUnit/TFDQuery/AbiturSirTmpQr.md
[5]:   DMUnit/TFDQuery/AddrLogUpQr.md
[6]:   DMUnit/TFDQuery/AdresOutQr.md
[7]:   DMUnit/TFDQuery/AdrLogLastQr.md
[8]:   DMUnit/TFDQuery/BlockBtnQr.md
[9]:   DMUnit/TFDQuery/BlockQ.md
[10]:  DMUnit/TFDQuery/CategUpQr.md
[11]:  DMUnit/TFDQuery/CertificLogInsQr.md
[12]:  DMUnit/TFDQuery/CkRegionQr.md
[13]:  DMUnit/TFDQuery/CntrlExrcQr.md
[14]:  DMUnit/TFDQuery/ContrySelQr.md
[15]:  DMUnit/TFDQuery/CountryQr.md
[16]:  DMUnit/TFDQuery/DocumFDQ.md
[17]:  DMUnit/TFDQuery/DocumInListQ.md
[18]:  DMUnit/TFDQuery/FIOSearchQr.md
[19]:  DMUnit/TFDQuery/GrazdanToDekanatQr.md
[20]:  DMUnit/TFDQuery/IdAbQueueQr.md
[21]:  DMUnit/TFDQuery/InfCntQr.md
[22]:  DMUnit/TFDQuery/InfQr.md
[23]:  DMUnit/TFDQuery/KodSpecializQr.md
[24]:  DMUnit/TFDQuery/LangSelQr.md
[25]:  DMUnit/TFDQuery/ListDocFDQ.md
[26]:  DMUnit/TFDQuery/LogIDSelQr.md
[27]:  DMUnit/TFDQuery/LogLastQr.md
[28]:  DMUnit/TFDQuery/MaxExrcQr.md
[29]:  DMUnit/TFDQuery/OtherPrivQr.md
[30]:  DMUnit/TFDQuery/OutCntQr.md
[31]:  DMUnit/TFDQuery/OutDetQr.md
[32]:  DMUnit/TFDQuery/OutQr.md
[33]:  DMUnit/TFDQuery/OutTestQr.md
[34]:  DMUnit/TFDQuery/PasportFDQ.md
[35]:  DMUnit/TFDQuery/PrintDocQr.md
[36]:  DMUnit/TFDQuery/PrivCnttQr.md
[37]:  DMUnit/TFDQuery/PrivilegLogSelQr.md
[38]:  DMUnit/TFDQuery/PrivQr.md
[39]:  DMUnit/TFDQuery/QAb_P.md
[40]:  DMUnit/TFDQuery/QAb_Pr_Enter.md
[41]:  DMUnit/TFDQuery/QAbFIOPol.md
[42]:  DMUnit/TFDQuery/QAbitur_Priv_Enter.md
[43]:  DMUnit/TFDQuery/QAbitura.md
[44]:  DMUnit/TFDQuery/QAdd_N_Group.md
[45]:  DMUnit/TFDQuery/QAdress.md
[46]:  DMUnit/TFDQuery/QCenter.md
[47]:  DMUnit/TFDQuery/QCK_Kol_Plan.md
[48]:  DMUnit/TFDQuery/QCk.md
[49]:  DMUnit/TFDQuery/QCkToDekanat.md
[50]:  DMUnit/TFDQuery/QControl_Exerc.md
[51]:  DMUnit/TFDQuery/QDelite.md
[52]:  DMUnit/TFDQuery/QDistrict.md
[53]:  DMUnit/TFDQuery/QEducation.md
[54]:  DMUnit/TFDQuery/QExam.md
[55]:  DMUnit/TFDQuery/QExamSpec.md
[56]:  DMUnit/TFDQuery/QExerc_Grp.md
[57]:  DMUnit/TFDQuery/QFindAbiturExerc.md
[58]:  DMUnit/TFDQuery/QFotoQeue.md
[59]:  DMUnit/TFDQuery/QFotoSign.md
[60]:  DMUnit/TFDQuery/QGIAC2kSpec.md
[61]:  DMUnit/TFDQuery/QGIAC3Sert.md
[62]:  DMUnit/TFDQuery/QGIACAll.md
[63]:  DMUnit/TFDQuery/QGIACAllPrivileg.md
[64]:  DMUnit/TFDQuery/QGIACAllPrivileg1.md
[65]:  DMUnit/TFDQuery/QGIACAllSpec.md
[66]:  DMUnit/TFDQuery/QGIACCKSpec.md
[67]:  DMUnit/TFDQuery/QGIACEdLic.md
[68]:  DMUnit/TFDQuery/QGIACEdOSred.md
[69]:  DMUnit/TFDQuery/QGIACEdOSredCity.md
[70]:  DMUnit/TFDQuery/QGIACEdOSredVil.md
[71]:  DMUnit/TFDQuery/QGIACForeigner.md
[72]:  DMUnit/TFDQuery/QGIACInAll.md
[73]:  DMUnit/TFDQuery/QGIACInCel.md
[74]:  DMUnit/TFDQuery/QGIACKursi.md
[75]:  DMUnit/TFDQuery/QGIACMedal.md
[76]:  DMUnit/TFDQuery/QGIACMil.md
[77]:  DMUnit/TFDQuery/QGIACOlimp.md
[78]:  DMUnit/TFDQuery/QGIACPtu.md
[79]:  DMUnit/TFDQuery/QGIACSirot.md
[80]:  DMUnit/TFDQuery/QGIACYearSred.md
[81]:  DMUnit/TFDQuery/QGIACYearSredCity.md
[82]:  DMUnit/TFDQuery/QGIACYearSredSpec.md
[83]:  DMUnit/TFDQuery/QGIACYearSredVil.md
[84]:  DMUnit/TFDQuery/QGroup_Count_Spec.md
[85]:  DMUnit/TFDQuery/QGroup_Count.md
[86]:  DMUnit/TFDQuery/QInc_Gr_Old.md
[87]:  DMUnit/TFDQuery/QIP.md
[88]:  DMUnit/TFDQuery/QKod_Fac.md
[89]:  DMUnit/TFDQuery/QKod_Spec.md
[90]:  DMUnit/TFDQuery/QLangvich.md
[91]:  DMUnit/TFDQuery/QLangvichToDekanat.md
[92]:  DMUnit/TFDQuery/QLetterSource.md
[93]:  DMUnit/TFDQuery/QLetterSourceKol.md
[94]:  DMUnit/TFDQuery/QListDocToDekanat.md
[95]:  DMUnit/TFDQuery/QLittle_Spisoc_GR.md
[96]:  DMUnit/TFDQuery/QLocality.md
[97]:  DMUnit/TFDQuery/QMax_Nom_Dela.md
[98]:  DMUnit/TFDQuery/QMax_Nomer_Ab.md
[99]:  DMUnit/TFDQuery/QN_group.md
[100]: DMUnit/TFDQuery/QNoticeFac.md
[101]: DMUnit/TFDQuery/QNoticeFIO.md
[102]: DMUnit/TFDQuery/QNoticeSpec.md
[103]: DMUnit/TFDQuery/QPersonalDocum.md
[104]: DMUnit/TFDQuery/QPlan_Priem_All_Special.md
[105]: DMUnit/TFDQuery/QPlan_Priem_All.md
[106]: DMUnit/TFDQuery/QPlan_Priem_CK_Special.md
[107]: DMUnit/TFDQuery/QPlan_Priem_CK.md
[108]: DMUnit/TFDQuery/QPlan_Priem_Konk_All_Param.md
[109]: DMUnit/TFDQuery/QPlan_Priem_Konk_Special.md
[110]: DMUnit/TFDQuery/QPlan_Priem_Konk.md
[111]: DMUnit/TFDQuery/QPlan_Priem_Price.md
[112]: DMUnit/TFDQuery/QPlanPriem2Price.md
[113]: DMUnit/TFDQuery/QPlanPriemPrice.md
[114]: DMUnit/TFDQuery/QPrivToDekanat.md
[115]: DMUnit/TFDQuery/QProverka_RYOR.md
[116]: DMUnit/TFDQuery/QProverka_sert.md
[117]: DMUnit/TFDQuery/QRegion_Center.md
[118]: DMUnit/TFDQuery/QRep_Abitura.md
[119]: DMUnit/TFDQuery/QRep_Sel_Exerc.md
[120]: DMUnit/TFDQuery/QReport_Rasp.md
[121]: DMUnit/TFDQuery/QResult_Exam.md
[122]: DMUnit/TFDQuery/QSelect_ab.md
[123]: DMUnit/TFDQuery/QSertificat_ex_list.md
[124]: DMUnit/TFDQuery/QSertificat_Res.md
[125]: DMUnit/TFDQuery/QSertificat.md
[126]: DMUnit/TFDQuery/QSertificatToDekanat.md
[127]: DMUnit/TFDQuery/QShkala.md
[128]: DMUnit/TFDQuery/QShow_Result_Exam.md
[129]: DMUnit/TFDQuery/QSpecializ.md
[130]: DMUnit/TFDQuery/QSpecializPlan_Priem.md
[131]: DMUnit/TFDQuery/QSpisoc_Group_Pol.md
[132]: DMUnit/TFDQuery/QSpisoc_Group.md
[133]: DMUnit/TFDQuery/QSpisok_Spec.md
[134]: DMUnit/TFDQuery/QStatistic_Every_Day_Ball_Price.md
[135]: DMUnit/TFDQuery/QStatistic_Every_Day_Ball.md
[136]: DMUnit/TFDQuery/QStatistic_Every_Day_Special.md
[137]: DMUnit/TFDQuery/QStatistic_Every_Day.md
[138]: DMUnit/TFDQuery/QStatisticEveryDay.md
[139]: DMUnit/TFDQuery/QStreet.md
[140]: DMUnit/TFDQuery/QSum_Ball_Nomer.md
[141]: DMUnit/TFDQuery/QSum_Ball.md
[142]: DMUnit/TFDQuery/QToDekanat.md
[143]: DMUnit/TFDQuery/QType_locality.md
[144]: DMUnit/TFDQuery/QType_street.md
[145]: DMUnit/TFDQuery/QUndo_Abit.md
[146]: DMUnit/TFDQuery/RegionNameQr.md
[147]: DMUnit/TFDQuery/RegionQr.md
[148]: DMUnit/TFDQuery/RegionUpCKQr.md
[149]: DMUnit/TFDQuery/SelectLogAbiturQr.md
[150]: DMUnit/TFDQuery/SelPrivLogQr.md
[151]: DMUnit/TFDQuery/SerteficatSelQr.md
[152]: DMUnit/TFDQuery/SertSelLogQr.md
[153]: DMUnit/TFDQuery/SpecFacQr.md
[154]: DMUnit/TFDQuery/SpecializNameQr.md
[155]: DMUnit/TFDQuery/SpecializQr.md
[156]: DMUnit/TFDQuery/SpecQr.md
[157]: DMUnit/TFDQuery/SPFDQ.md
[158]: DMUnit/TFDQuery/SPFDQ1.md
[159]: DMUnit/TFDQuery/SportQuery.md
[160]: DMUnit/TFDQuery/SspecQ.md
[161]: DMUnit/TFDQuery/Stat3hAll1Qr.md
[162]: DMUnit/TFDQuery/Stat3hAll2Qr.md
[163]: DMUnit/TFDQuery/StatusQueueQr.md
[164]: DMUnit/TFDQuery/UpDateOutQr.md
[165]: DMUnit/TFDQuery/VO2KSpecializQr.md
[166]: DMUnit/TFDQuery/WithoutCntQr.md
[167]: DMUnit/TFDQuery/WithoutDetQr.md
[168]: DMUnit/TFDQuery/WithoutQr.md
[169]: DMUnit/TFDQuery/WithOutTestLogQr.md
*/

-- TFDStoredProc
/*
[]: DMUnit/TFDStoredProc/AbiturLogInsStrdPrc.md
[]: DMUnit/TFDStoredProc/CertificLogDelStrdPrc.md
[]: DMUnit/TFDStoredProc/MaxNumDelaStrdPrc.md
[]: DMUnit/TFDStoredProc/PrivDelStrdPrc.md
[]: DMUnit/TFDStoredProc/PrivilegLogDelStrdPrc.md
[]: DMUnit/TFDStoredProc/PrivilegLogInsStrdPrc.md
[]: DMUnit/TFDStoredProc/PrivInsStrdPrc.md
[]: DMUnit/TFDStoredProc/RaspredBall12StrdPrc.md
[]: DMUnit/TFDStoredProc/RaspredBall34StrdPrc.md
[]: DMUnit/TFDStoredProc/RaspredBallStrdPrc.md
[]: DMUnit/TFDStoredProc/StoredProcBall_Sertifikat.md
[]: DMUnit/TFDStoredProc/StoredProcKolk_Konk.md
[]: DMUnit/TFDStoredProc/StoredProcKolk_Konk1.md
[]: DMUnit/TFDStoredProc/StoredProcN_AB.md
[]: DMUnit/TFDStoredProc/StoredProcN_People.md
[]: DMUnit/TFDStoredProc/StoredProcSelExercIns.md
[]: DMUnit/TFDStoredProc/StoredProcStatistic_Konk.md
[]: DMUnit/TFDStoredProc/StoredProcSumm_Ball_2K.md
[]: DMUnit/TFDStoredProc/StoredProcSumm_Ball.md
[]: DMUnit/TFDStoredProc/StoredProcSumm_Ball100.md
*/
-- TFDTable

/* []: DMUnit/TFDTable/CntrExrcTbl.md
[]: DMUnit/TFDTable/Increment_GroupTable.md
[]: DMUnit/TFDTable/RegCentrTbl.md
[]: DMUnit/TFDTable/Selection_CommitteeFDTable.md
[]: DMUnit/TFDTable/TBall.md
[]: DMUnit/TFDTable/TCategory.md
[]: DMUnit/TFDTable/TCk.md
[]: DMUnit/TFDTable/TDocum.md
[]: DMUnit/TFDTable/TEduDoc.md
[]: DMUnit/TFDTable/TFaculty.md
[]: DMUnit/TFDTable/TFoundation.md
[]: DMUnit/TFDTable/TKol_Place.md
[]: DMUnit/TFDTable/TPass_User.md
[]: DMUnit/TFDTable/TPredmet.md
[]: DMUnit/TFDTable/TRegion.md
[]: DMUnit/TFDTable/TVid_Sport.md */

-- TFDUpdateSQL
/*
[]: DMUnit/TFDUpdateSQL/BloskUpSQL.md
[]: DMUnit/TFDUpdateSQL/ListDocFDUp.md
[]: DMUnit/TFDUpdateSQL/PasportUp.md
[]: DMUnit/TFDUpdateSQL/QSelectUpdateSQL.md
[]: DMUnit/TFDUpdateSQL/SportUpdateSQL.md
[]: DMUnit/TFDUpdateSQL/UpAb_P.md
[]: DMUnit/TFDUpdateSQL/UpAbitur_Priv_Enter.md
[]: DMUnit/TFDUpdateSQL/UpAbitura.md
[]: DMUnit/TFDUpdateSQL/UpAdd_N_Group.md
[]: DMUnit/TFDUpdateSQL/UpCenter.md
[]: DMUnit/TFDUpdateSQL/UpCkToDekanat.md
[]: DMUnit/TFDUpdateSQL/UPFoto.md
[]: DMUnit/TFDUpdateSQL/UpInc_Gr_Old.md
[]: DMUnit/TFDUpdateSQL/UpLangvichToDekanat.md
[]: DMUnit/TFDUpdateSQL/UpListDocToDekanat.md
[]: DMUnit/TFDUpdateSQL/UpPrivToDekanat.md
[]: DMUnit/TFDUpdateSQL/UpResult_Exam.md
[]: DMUnit/TFDUpdateSQL/UpSertificatToDekanat.md
[]: DMUnit/TFDUpdateSQL/UpShow_Result_Exam.md
[]: DMUnit/TFDUpdateSQL/UpSpecializ.md
[]: DMUnit/TFDUpdateSQL/UpSum_Ball_Nomer.md
[]: DMUnit/TFDUpdateSQL/UpSum_Ball.md
[]: DMUnit/TFDUpdateSQL/UpToDekanat.md
[]: DMUnit/TFDUpdateSQL/UpUndo_Abit.md
*/

    DMStatUnit/TDataSource/DSCount_Ball_Examen.md
    DMStatUnit/TDataSource/DSCount_CK.md
    DMStatUnit/TDataSource/DSCount_Diplom.md
    DMStatUnit/TDataSource/DSCount_Gimn.md
    DMStatUnit/TDataSource/DSCount_Gorod.md
    DMStatUnit/TDataSource/DSCount_Medal.md
    DMStatUnit/TDataSource/DSCount_Olimp.md
    DMStatUnit/TDataSource/DSCount_Platn.md
    DMStatUnit/TDataSource/DSCount_PO.md
    DMStatUnit/TDataSource/DSCount_Region.md
    DMStatUnit/TDataSource/DSCount_Selo.md
    DMStatUnit/TDataSource/DSCount_special_ab.md
    DMStatUnit/TDataSource/DSCount_Stag.md
    DMStatUnit/TDataSource/DSCount_Test.md
    DMStatUnit/TDataSource/DSF1kAb.md
    DMStatUnit/TDataSource/DSF1kKol.md
    DMStatUnit/TDataSource/DSProtokol.md
    DMStatUnit/TDataSource/DSQ_GK_All.md
    DMStatUnit/TDataSource/DSQ_GK_Konkurs.md
    DMStatUnit/TDataSource/DSQ_GK_Medal.md
    DMStatUnit/TDataSource/DSQ_GK_Plan_CK.md
    DMStatUnit/TDataSource/DSQ_GK_Plan.md
    DMStatUnit/TDataSource/DSQCount_Ball_Rus_Bel_old.md
    DMStatUnit/TDataSource/DSQCount_Ball_Rus_Bel.md
    DMStatUnit/TDataSource/DSQF2_All_Sdal.md
    DMStatUnit/TDataSource/DSQF2_CK.md
    DMStatUnit/TDataSource/DSQF2_Sdal.md
    DMStatUnit/TDataSource/DSQF2_Zach.md
    DMStatUnit/TDataSource/DSQSpecial.md
    DMStatUnit/TDataSource/DSRegion_Stat.md
    DMStatUnit/TDataSource/DSSpecial.md
    DMStatUnit/TDataSource/DSSport_Categ.md
    DMStatUnit/TDataSource/DSSvod_Ved.md
    DMStatUnit/TDataSource/DSSvod_Ved2.md

    DMStatUnit/TFDQuery/CitizenQr.md
    DMStatUnit/TFDQuery/FullGrpS1Qr.md
    DMStatUnit/TFDQuery/LastLogQr.md
    DMStatUnit/TFDQuery/ProtokolAllQr.md
    DMStatUnit/TFDQuery/ProtokolCkQr.md
    DMStatUnit/TFDQuery/ProtokolQr.md
    DMStatUnit/TFDQuery/Q_GK_All.md
    DMStatUnit/TFDQuery/Q_GK_Konkurs.md
    DMStatUnit/TFDQuery/Q_GK_Medal.md
    DMStatUnit/TFDQuery/Q_GK_Plan_CK.md
    DMStatUnit/TFDQuery/Q_GK_Plan.md
    DMStatUnit/TFDQuery/QBall_prohod.md
    DMStatUnit/TFDQuery/QCount_Ball_Examen.md
    DMStatUnit/TFDQuery/QCount_Ball_Rus_Bel_old.md
    DMStatUnit/TFDQuery/QCount_Ball_Rus_Bel.md
    DMStatUnit/TFDQuery/QCount_Ball.md
    DMStatUnit/TFDQuery/QCount_CK.md
    DMStatUnit/TFDQuery/QCount_Diplom.md
    DMStatUnit/TFDQuery/QCount_Gimn.md
    DMStatUnit/TFDQuery/QCount_Gorod.md
    DMStatUnit/TFDQuery/QCount_High.md
    DMStatUnit/TFDQuery/QCount_Medal.md
    DMStatUnit/TFDQuery/QCount_Olimp.md
    DMStatUnit/TFDQuery/QCount_Platn.md
    DMStatUnit/TFDQuery/QCount_PO.md
    DMStatUnit/TFDQuery/QCount_Region.md
    DMStatUnit/TFDQuery/QCount_RUOR.md
    DMStatUnit/TFDQuery/QCount_Selo.md
    DMStatUnit/TFDQuery/QCount_special_ab.md
    DMStatUnit/TFDQuery/QCount_Stag.md
    DMStatUnit/TFDQuery/QCount_Test.md
    DMStatUnit/TFDQuery/QCount_VK.md
    DMStatUnit/TFDQuery/QCountAll.md
    DMStatUnit/TFDQuery/QCountSpecNapravl.md
    DMStatUnit/TFDQuery/QF1kAb.md
    DMStatUnit/TFDQuery/QF1kKol.md
    DMStatUnit/TFDQuery/QF2_All_Sdal.md
    DMStatUnit/TFDQuery/QF2_CK.md
    DMStatUnit/TFDQuery/QF2_Sdal.md
    DMStatUnit/TFDQuery/QF2_Zach.md
    DMStatUnit/TFDQuery/QProtokol.md
    DMStatUnit/TFDQuery/QRegion_Stat.md
    DMStatUnit/TFDQuery/QSpec_Dir.md
    DMStatUnit/TFDQuery/QSpecial.md
    DMStatUnit/TFDQuery/QSpecializ_for_Spec_Dir.md
    DMStatUnit/TFDQuery/QSpecializ_for_Spec.md
    DMStatUnit/TFDQuery/QSport_Categ.md
    DMStatUnit/TFDQuery/QSvod_Ved.md
    DMStatUnit/TFDQuery/QSvod_Ved2.md
    DMStatUnit/TFDQuery/QZachisl_Sertificat.md

    DMStatUnit/TFDStoredProc/Giaz01SP.md
    DMStatUnit/TFDStoredProc/GIAZ021SP.md
    DMStatUnit/TFDStoredProc/Giaz022SP.md

    DMStatUnit/TFDTable/TSpecial.md