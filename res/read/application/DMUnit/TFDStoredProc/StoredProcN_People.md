# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > [TFDStoredProc](TFDStoredProc.md) > *StoredProcN_People*

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

---

## StoredProcN_People -> **get_n_people**
 
```json
{
    "Name"           : "StoredProcN_People",
    "Connection"     : "FDConnection1",
    "StoredProcName" : "GET_N_PEOPLE"
}
```
<!--
    <ParamData>

    "DataType"       : "TFDStoredProc",
    "CachedUpdates"  : true,

        <item
            Name      = 'ID_LOG'
            DataType  = 'Integer'
            ParamType = 'Input'
        />
    </ParamData>
</object>
``` -->

### Params > TFDConnectionDefParams

|         *Name* |        *Param*       |
|---------------:|:--------------------:|
| *CharacterSet* |    **csWIN1251**     |
|  *CharLenMode* |       clmChars       |
|     *Database* |     **dekanat**      |
|     *DriverID* |        **FB**        |
|     *PageSize* |       *ps4096*       |
|     *Password* |   **dbudfV544703**   |
|     *Protocol* |       ipTCPIP        |
|       *Server* |    **172.16.1.30**   |
|   *SQLDialect* |        **1**         |
|     *UserName* |     **developer**    |

---
</br>

```sql
-- FDConnection1 - Dekanat
SET TERM ^ ;

CREATE OR ALTER
    PROCEDURE
        get_n_people
        RETURNS
            (
                np INTEGER,
                nd INTEGER
            )
AS
BEGIN
    :np =
        GEN_ID (
            people_nomer,
            1
        );


    :nd =
        (
            SELECT
                IIF (
                        MAX (p.number) IS NULL,
                            0,
                            MAX (p.number)
                    )
            FROM
                people AS p
            WHERE
                    EXTRACT (
                            year
                        FROM
                            p.d_prikaz_include
                    )
                =
                    EXTRACT (
                            year
                        FROM
                            CAST ('now' AS TIMESTAMP)
                    )
        ) + 1;
END^

SET TERM ; ^
```

---
</br>

### Grant statements

```sql
GRANT
    USAGE
ON
    SEQUENCE
        people_nomer
TO
    PROCEDURE
        get_n_people;


GRANT
    SELECT
ON
    people
TO
    PROCEDURE
        get_n_people;
```

---
</br>

### List of users who have privileges

```sql
GRANT EXECUTE ON PROCEDURE get_n_people TO abitur1;
GRANT EXECUTE ON PROCEDURE get_n_people TO abitur2;
GRANT EXECUTE ON PROCEDURE get_n_people TO abitur3;
GRANT EXECUTE ON PROCEDURE get_n_people TO abitur4;
GRANT EXECUTE ON PROCEDURE get_n_people TO alena_2109;
GRANT EXECUTE ON PROCEDURE get_n_people TO alexander_goncharov;
GRANT EXECUTE ON PROCEDURE get_n_people TO alina_e;
GRANT EXECUTE ON PROCEDURE get_n_people TO anna;
GRANT EXECUTE ON PROCEDURE get_n_people TO aspa;
GRANT EXECUTE ON PROCEDURE get_n_people TO aspirantura;
GRANT EXECUTE ON PROCEDURE get_n_people TO asu;
GRANT EXECUTE ON PROCEDURE get_n_people TO asu1;
GRANT EXECUTE ON PROCEDURE get_n_people TO asu2;
GRANT EXECUTE ON PROCEDURE get_n_people TO asu3;
GRANT EXECUTE ON PROCEDURE get_n_people TO asu4;
GRANT EXECUTE ON PROCEDURE get_n_people TO baks16;
GRANT EXECUTE ON PROCEDURE get_n_people TO baks68878;
GRANT EXECUTE ON PROCEDURE get_n_people TO bobrovich_o;
GRANT EXECUTE ON PROCEDURE get_n_people TO developer;
GRANT EXECUTE ON PROCEDURE get_n_people TO developer2;
GRANT EXECUTE ON PROCEDURE get_n_people TO dobrovolskaya;
GRANT EXECUTE ON PROCEDURE get_n_people TO dvoretskaya_k;
GRANT EXECUTE ON PROCEDURE get_n_people TO faculty1;
GRANT EXECUTE ON PROCEDURE get_n_people TO fififi;
GRANT EXECUTE ON PROCEDURE get_n_people TO goncharov434_2;
GRANT EXECUTE ON PROCEDURE get_n_people TO gunich_o;
GRANT EXECUTE ON PROCEDURE get_n_people TO gunich_oksana;
GRANT EXECUTE ON PROCEDURE get_n_people TO hostel_pk1;
GRANT EXECUTE ON PROCEDURE get_n_people TO hostel_pk2;
GRANT EXECUTE ON PROCEDURE get_n_people TO imsit_z;
GRANT EXECUTE ON PROCEDURE get_n_people TO inter_01;
GRANT EXECUTE ON PROCEDURE get_n_people TO inter_02;
GRANT EXECUTE ON PROCEDURE get_n_people TO ip_project;
GRANT EXECUTE ON PROCEDURE get_n_people TO ironskull;
GRANT EXECUTE ON PROCEDURE get_n_people TO it;
GRANT EXECUTE ON PROCEDURE get_n_people TO it2;
GRANT EXECUTE ON PROCEDURE get_n_people TO it5;
GRANT EXECUTE ON PROCEDURE get_n_people TO it6;
GRANT EXECUTE ON PROCEDURE get_n_people TO it7;
GRANT EXECUTE ON PROCEDURE get_n_people TO it8;
GRANT EXECUTE ON PROCEDURE get_n_people TO it_1;
GRANT EXECUTE ON PROCEDURE get_n_people TO it_2;
GRANT EXECUTE ON PROCEDURE get_n_people TO it_3;
GRANT EXECUTE ON PROCEDURE get_n_people TO it_8;
GRANT EXECUTE ON PROCEDURE get_n_people TO it_d;
GRANT EXECUTE ON PROCEDURE get_n_people TO it_l;
GRANT EXECUTE ON PROCEDURE get_n_people TO it_m;
GRANT EXECUTE ON PROCEDURE get_n_people TO it_pk;
GRANT EXECUTE ON PROCEDURE get_n_people TO it_z;
GRANT EXECUTE ON PROCEDURE get_n_people TO ivanova_a;
GRANT EXECUTE ON PROCEDURE get_n_people TO jkmuf2507;
GRANT EXECUTE ON PROCEDURE get_n_people TO kandrukevich_m;
GRANT EXECUTE ON PROCEDURE get_n_people TO kand_m;
GRANT EXECUTE ON PROCEDURE get_n_people TO kosik_n;
GRANT EXECUTE ON PROCEDURE get_n_people TO kristina;
GRANT EXECUTE ON PROCEDURE get_n_people TO lavrenova_v;
GRANT EXECUTE ON PROCEDURE get_n_people TO lenausova;
GRANT EXECUTE ON PROCEDURE get_n_people TO liashkovich_i;
GRANT EXECUTE ON PROCEDURE get_n_people TO ltrfyfn2019;
GRANT EXECUTE ON PROCEDURE get_n_people TO magistr;
GRANT EXECUTE ON PROCEDURE get_n_people TO marina;
GRANT EXECUTE ON PROCEDURE get_n_people TO matusevich;
GRANT EXECUTE ON PROCEDURE get_n_people TO mimi;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_1;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_d;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_d_l;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_etb;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_g;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_l;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_lp;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_n;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_pk;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_v;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_z;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_zam;
GRANT EXECUTE ON PROCEDURE get_n_people TO mvs_z_l;
GRANT EXECUTE ON PROCEDURE get_n_people TO m_2;
GRANT EXECUTE ON PROCEDURE get_n_people TO new78;
GRANT EXECUTE ON PROCEDURE get_n_people TO newlogin;
GRANT EXECUTE ON PROCEDURE get_n_people TO newuser;
GRANT EXECUTE ON PROCEDURE get_n_people TO novik_a;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkit15;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkita;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkit_1;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkit_15;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkit_a;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkit_d;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkit_d_a;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkit_l;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkit_lab;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkit_m;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkit_n;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkit_pk;
GRANT EXECUTE ON PROCEDURE get_n_people TO ofkit_z;
GRANT EXECUTE ON PROCEDURE get_n_people TO ok;
GRANT EXECUTE ON PROCEDURE get_n_people TO ok1;
GRANT EXECUTE ON PROCEDURE get_n_people TO ok2;
GRANT EXECUTE ON PROCEDURE get_n_people TO oksana;
GRANT EXECUTE ON PROCEDURE get_n_people TO ok_st;
GRANT EXECUTE ON PROCEDURE get_n_people TO ok_stud;
GRANT EXECUTE ON PROCEDURE get_n_people TO ok_stud_1;
GRANT EXECUTE ON PROCEDURE get_n_people TO ok_stud_2;
GRANT EXECUTE ON PROCEDURE get_n_people TO ok_stud_n;
GRANT EXECUTE ON PROCEDURE get_n_people TO ok_stud_sl;
GRANT EXECUTE ON PROCEDURE get_n_people TO ok_stud_us;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_it;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_it1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_it2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_it3;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_it4;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_it5;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mstig1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mstig2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mstig3;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mstig4;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mstigp1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mstigp2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mstig_1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mstig_2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mstig_3;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mstig_4;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mstig_p1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mstig_p2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvs;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvs1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvs2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvs3;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvs4;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvs5;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvsp1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvsp2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvs_1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvs_2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvs_3;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvs_4;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvs_p1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_mvs_p2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofkit;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofkit1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofkit2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofkit3;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofkit4;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofkit5;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofkitp1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofkitp2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofk_1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofk_2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofk_3;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofk_4;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofk_p1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_ofk_p2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_otv1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_otv2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_otv3;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_otv4;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siie;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siie1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siie2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siie3;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siie4;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siie5;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siiep1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siiep2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siie_1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siie_2;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siie_3;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siie_4;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siie_p1;
GRANT EXECUTE ON PROCEDURE get_n_people TO pk_siie_p2;
GRANT EXECUTE ON PROCEDURE get_n_people TO planida_e;
GRANT EXECUTE ON PROCEDURE get_n_people TO press_01;
GRANT EXECUTE ON PROCEDURE get_n_people TO priem1;
GRANT EXECUTE ON PROCEDURE get_n_people TO sadik;
GRANT EXECUTE ON PROCEDURE get_n_people TO sel_com;
GRANT EXECUTE ON PROCEDURE get_n_people TO serafimovich_y;
GRANT EXECUTE ON PROCEDURE get_n_people TO setun1998;
GRANT EXECUTE ON PROCEDURE get_n_people TO shmaenkova_m;
GRANT EXECUTE ON PROCEDURE get_n_people TO shpakevich_p;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie1;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie10;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie12;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie123;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie1234;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie2;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie3;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie4;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie6;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_123;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_2;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_5;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_belaya_m;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_d;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_d2;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_lab;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_lab_d;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_lab_z;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_lab_z2;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_lab_z3;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_new;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_o;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_pk;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_z;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_z1;
GRANT EXECUTE ON PROCEDURE get_n_people TO siie_z12;
GRANT EXECUTE ON PROCEDURE get_n_people TO smolenkova_t;
GRANT EXECUTE ON PROCEDURE get_n_people TO stud_kadr1;
GRANT EXECUTE ON PROCEDURE get_n_people TO stud_kadr2;
GRANT EXECUTE ON PROCEDURE get_n_people TO stud_kadr3;
GRANT EXECUTE ON PROCEDURE get_n_people TO stud_kadr4;
GRANT EXECUTE ON PROCEDURE get_n_people TO sveta;
GRANT EXECUTE ON PROCEDURE get_n_people TO sysdba;
GRANT EXECUTE ON PROCEDURE get_n_people TO test_prepod;
GRANT EXECUTE ON PROCEDURE get_n_people TO test_proba;
GRANT EXECUTE ON PROCEDURE get_n_people TO test_stud;
GRANT EXECUTE ON PROCEDURE get_n_people TO uhnovec;
GRANT EXECUTE ON PROCEDURE get_n_people TO uo_lab;
GRANT EXECUTE ON PROCEDURE get_n_people TO uo_m;
GRANT EXECUTE ON PROCEDURE get_n_people TO uo_n;
GRANT EXECUTE ON PROCEDURE get_n_people TO uo_z;
GRANT EXECUTE ON PROCEDURE get_n_people TO user123;
GRANT EXECUTE ON PROCEDURE get_n_people TO user622;
GRANT EXECUTE ON PROCEDURE get_n_people TO viewer_mob;
GRANT EXECUTE ON PROCEDURE get_n_people TO vnuk;
GRANT EXECUTE ON PROCEDURE get_n_people TO vorobei75;
GRANT EXECUTE ON PROCEDURE get_n_people TO ya;
GRANT EXECUTE ON PROCEDURE get_n_people TO yauheni_hatsura;
GRANT EXECUTE ON PROCEDURE get_n_people TO zhanna_73;
```