/******************************************************************************/

/******************************************************************************/
/***      Following SET SQL DIALECT is just for the Database Comparer       ***/
/******************************************************************************/


/******************************************************************************/
/***                                 Views                                  ***/
/******************************************************************************/


/* View: IN_MINTRUD */
CREATE OR ALTER VIEW IN_MINTRUD(
    PERSONAL_NOMER,
    FAM,
    NAME,
    OTCH,
    D_PRIKAZ_INCLUDE,
    D_PRIKAZ_KURS)
AS
select people.personal_nomer, people.fam, people.name, people.otch, people.d_prikaz_include, people.d_prikaz_kurs from people
  where people.vid_edu = 0
    and people.data_r < "01.07.2000"
    and people.d_prikaz_include < "01.07.2018"
    and (people.d_prikaz_kurs >= "01.04.2018" or people.d_prikaz_kurs is null)
    and people.nomer not in (select a.nomer from restore a, student_restore
                             where a.nomer = student_restore.nomer
                               and a.d_prikaz_res = student_restore.d_prikaz_res
                               and a.vid_restore = 1)
union
  select people.personal_nomer, people.fam, people.name, people.otch, people.d_prikaz_include, people.d_prikaz_kurs from people
  where people.vid_edu = 0
    and people.data_r < "01.07.2000"
    and people.d_prikaz_include < "01.07.2018"
    and (people.d_prikaz_kurs >= "01.04.2018" or people.d_prikaz_kurs is null)
    and people.nomer in (select restore.nomer from restore
                         where restore.d_prikaz_res between "01.04.2018" and "30.06.2018")
;




/******************************************************************************/
/***                               Privileges                               ***/
/******************************************************************************/


/* Privileges of users */
GRANT ALL ON IN_MINTRUD TO ALENA_2109;
GRANT ALL ON IN_MINTRUD TO ALEXANDER_GONCHAROV;
GRANT ALL ON IN_MINTRUD TO ALINA_E;
GRANT ALL ON IN_MINTRUD TO ASPIRANTURA;
GRANT ALL ON IN_MINTRUD TO DOBROVOLSKAYA;
GRANT ALL ON IN_MINTRUD TO DVORETSKAYA_K;
GRANT ALL ON IN_MINTRUD TO GONCHAROV434_2;
GRANT ALL ON IN_MINTRUD TO GUNICH_O;
GRANT ALL ON IN_MINTRUD TO HOSTEL_PK1;
GRANT ALL ON IN_MINTRUD TO HOSTEL_PK2;
GRANT ALL ON IN_MINTRUD TO IMSIT_Z;
GRANT ALL ON IN_MINTRUD TO IVANOVA_A;
GRANT ALL ON IN_MINTRUD TO KANDRUKEVICH_M;
GRANT ALL ON IN_MINTRUD TO KAND_M;
GRANT ALL ON IN_MINTRUD TO KOSIK_N;
GRANT ALL ON IN_MINTRUD TO KRISTINA;
GRANT ALL ON IN_MINTRUD TO LIASHKOVICH_I;
GRANT ALL ON IN_MINTRUD TO LTRFYFN2019;
GRANT ALL ON IN_MINTRUD TO MAGISTR;
GRANT ALL ON IN_MINTRUD TO MARINA;
GRANT ALL ON IN_MINTRUD TO MATUSEVICH;
GRANT ALL ON IN_MINTRUD TO OKSANA;
GRANT ALL ON IN_MINTRUD TO OK_STUD_2;
GRANT ALL ON IN_MINTRUD TO PK_MSTIG1;
GRANT ALL ON IN_MINTRUD TO PK_MSTIG_1;
GRANT ALL ON IN_MINTRUD TO PK_MSTIG_2;
GRANT ALL ON IN_MINTRUD TO PK_MSTIG_3;
GRANT ALL ON IN_MINTRUD TO PK_MSTIG_4;
GRANT ALL ON IN_MINTRUD TO PK_MSTIG_P1;
GRANT ALL ON IN_MINTRUD TO PK_MSTIG_P2;
GRANT ALL ON IN_MINTRUD TO PK_MVS1;
GRANT ALL ON IN_MINTRUD TO PK_MVS4;
GRANT ALL ON IN_MINTRUD TO PK_MVS_1;
GRANT ALL ON IN_MINTRUD TO PK_MVS_2;
GRANT ALL ON IN_MINTRUD TO PK_MVS_3;
GRANT ALL ON IN_MINTRUD TO PK_MVS_4;
GRANT ALL ON IN_MINTRUD TO PK_MVS_P1;
GRANT ALL ON IN_MINTRUD TO PK_MVS_P2;
GRANT ALL ON IN_MINTRUD TO PK_OFK_1;
GRANT ALL ON IN_MINTRUD TO PK_OFK_2;
GRANT ALL ON IN_MINTRUD TO PK_OFK_3;
GRANT ALL ON IN_MINTRUD TO PK_OFK_4;
GRANT ALL ON IN_MINTRUD TO PK_OFK_P1;
GRANT ALL ON IN_MINTRUD TO PK_OFK_P2;
GRANT ALL ON IN_MINTRUD TO PK_OTV1;
GRANT ALL ON IN_MINTRUD TO PK_OTV2;
GRANT ALL ON IN_MINTRUD TO PK_OTV3;
GRANT ALL ON IN_MINTRUD TO PK_OTV4;
GRANT ALL ON IN_MINTRUD TO PK_SIIE_1;
GRANT ALL ON IN_MINTRUD TO PK_SIIE_2;
GRANT ALL ON IN_MINTRUD TO PK_SIIE_3;
GRANT ALL ON IN_MINTRUD TO PK_SIIE_4;
GRANT ALL ON IN_MINTRUD TO PK_SIIE_P1;
GRANT ALL ON IN_MINTRUD TO PK_SIIE_P2;
GRANT ALL ON IN_MINTRUD TO SADIK;
GRANT ALL ON IN_MINTRUD TO SEL_COM;
GRANT ALL ON IN_MINTRUD TO SETUN1998;
GRANT ALL ON IN_MINTRUD TO SHPAKEVICH_P;
GRANT ALL ON IN_MINTRUD TO SMOLENKOVA_T;
GRANT ALL ON IN_MINTRUD TO ZHANNA_73;