
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
    a.nomer_ab = :nomer_ab



SELECT
    f.fac
FROM
    faculty AS f
WHERE
    f.n_fac = :n_fac


SELECT
    n_group,
    nom_group,
    vid_edu,
    describe,
    n_fac,
    n_count
FROM
    n_group
WHERE
        n_fac   = :fac
    AND
        vid_edu = :edu
    AND
        describe LIKE :spec


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
        a.status = 0


SELECT
    s.special_direction
FROM
    specializ AS s
WHERE
    s.n_specializ = :n_specializ


SELECT
    COUNT
    (
        nomer_ab
    )
FROM
    abitura
WHERE
        vid_edu         =    :vid_edu
    AND
        status          =     0
    AND
        education       =     0
    AND
        when_edu_middle =    :year
    AND
        town_village    LIKE '1'
    AND
        konkurs         <>    5


    AND
        town_village    LIKE '0'

