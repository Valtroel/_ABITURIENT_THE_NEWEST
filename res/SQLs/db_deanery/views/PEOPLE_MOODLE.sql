/******************************************************************************/

/******************************************************************************/
/***      Following SET SQL DIALECT is just for the Database Comparer       ***/
/******************************************************************************/


/******************************************************************************/
/***                                 Views                                  ***/
/******************************************************************************/


/* View: PEOPLE_MOODLE */
CREATE OR ALTER VIEW PEOPLE_MOODLE(
    USERNAME,
    USERPASSWORD,
    LASTNAME,
    FIRSTNAME,
    MIDDLENAME,
    EMAIL,
    STUDYFACULTY,
    STUDYGROUP)
AS
select people.n_zachet, people.nomer, people.fam, people.name, people.otch, cast( people.n_zachet as varchar(30))||"@sportedu.by", faculty.fac1,
    case
        when (people.vid_edu = 0 and people.status_people = 1 and ((people.status_kurs = 0) or (people.status_kurs is null))) then (cast(people.n_group as char(3))||(cast("д действующий" as char(13))))
        when (people.vid_edu = 0 and people.status_people = 1 and people.status_kurs = 1) then (cast(people.n_group as char(3))||(cast("д условно переведён" as char(19))))
        when (people.vid_edu = 0 and people.status_people = 2) then (cast(people.n_group as char(3))||(cast("д отчислен" as char(10))))
        when (people.vid_edu = 0 and people.status_people = 3) then (cast(people.n_group as char(3))||(cast("д академический отпуск" as char(22))))
        when (people.vid_edu = 0 and people.status_people = 6) then (cast(people.n_group as char(3))||(cast("д выпускник" as char(11)))||EXTRACT(YEAR FROM people.date_end))
        when (people.vid_edu = 0 and people.status_people = 7) then (cast(people.n_group as char(3))||(cast("д восстанавливающийся" as char(21))))
        when (people.vid_edu = 1 and people.status_people = 1 and ((people.status_kurs = 0) or (people.status_kurs is null))) then (cast(people.n_group as char(3))||(cast("з действующий" as char(13))))
        when (people.vid_edu = 1 and people.status_people = 1 and people.status_kurs = 1) then (cast(people.n_group as char(3))||(cast("з условно переведён" as char(19))))
        when (people.vid_edu = 1 and people.status_people = 2) then (cast(people.n_group as char(3))||(cast("з отчислен" as char(10))))
        when (people.vid_edu = 1 and people.status_people = 3) then (cast(people.n_group as char(3))||(cast("з академический отпуск" as char(22))))
        when (people.vid_edu = 1 and people.status_people = 6) then (cast(people.n_group as char(3))||(cast("з выпускник" as char(11)))||EXTRACT(YEAR FROM people.date_end))
        when (people.vid_edu = 1 and people.status_people = 7) then (cast(people.n_group as char(3))||(cast("з восстанавливающийся" as char(21))))
    end
from people, faculty
where faculty.n_fac = people.n_fac
and people.n_fac between 1 and 4
union
select student_tr.n_zachet, student_tr.nomer, student_tr.fam, student_tr.name, student_tr.otch, cast( student_tr.n_zachet as varchar(30))||"@sportedu.by", faculty.fac1,
  case
        when (student_tr.id_vid_edu = 0 and student_tr.active_student = 1) then (cast(student_tr.n_group as char(3))||(cast("д магистрант" as char(12))))
        when (student_tr.id_vid_edu = 1 and student_tr.active_student = 1) then (cast(student_tr.n_group as char(3))||(cast("з магистрант" as char(12))))
        when (student_tr.active_student <> 1) then (cast(student_tr.n_group as char(3))||(cast("магистрант выпускник" as char(20))))
  end
from student_tr, faculty
where faculty.n_fac = student_tr.id_fac
;




/******************************************************************************/
/***                               Privileges                               ***/
/******************************************************************************/


/* Privileges of users */
GRANT ALL ON PEOPLE_MOODLE TO ABITUR1;
GRANT ALL ON PEOPLE_MOODLE TO ABITUR2;
GRANT ALL ON PEOPLE_MOODLE TO ABITUR3;
GRANT ALL ON PEOPLE_MOODLE TO ABITUR4;
GRANT ALL ON PEOPLE_MOODLE TO ALENA_2109;
GRANT ALL ON PEOPLE_MOODLE TO ALEXANDER_GONCHAROV;
GRANT ALL ON PEOPLE_MOODLE TO ALINA_E;
GRANT ALL ON PEOPLE_MOODLE TO ANNA;
GRANT ALL ON PEOPLE_MOODLE TO ASPA;
GRANT ALL ON PEOPLE_MOODLE TO ASPIRANTURA;
GRANT ALL ON PEOPLE_MOODLE TO ASU;
GRANT ALL ON PEOPLE_MOODLE TO BAKS16;
GRANT ALL ON PEOPLE_MOODLE TO BAKS68878;
GRANT ALL ON PEOPLE_MOODLE TO BOBROVICH_O;
GRANT ALL ON PEOPLE_MOODLE TO DEVELOPER WITH GRANT OPTION;
GRANT ALL ON PEOPLE_MOODLE TO DOBROVOLSKAYA;
GRANT ALL ON PEOPLE_MOODLE TO DVORETSKAYA_K;
GRANT ALL ON PEOPLE_MOODLE TO FACULTY1;
GRANT ALL ON PEOPLE_MOODLE TO FIFIFI;
GRANT ALL ON PEOPLE_MOODLE TO GONCHAROV434_2;
GRANT ALL ON PEOPLE_MOODLE TO GUNICH_O;
GRANT ALL ON PEOPLE_MOODLE TO GUNICH_OKSANA;
GRANT ALL ON PEOPLE_MOODLE TO HOSTEL_PK1;
GRANT ALL ON PEOPLE_MOODLE TO HOSTEL_PK2;
GRANT ALL ON PEOPLE_MOODLE TO IMSIT_Z;
GRANT SELECT ON PEOPLE_MOODLE TO INTER_01;
GRANT SELECT ON PEOPLE_MOODLE TO INTER_02;
GRANT ALL ON PEOPLE_MOODLE TO IP_PROJECT;
GRANT ALL ON PEOPLE_MOODLE TO IRONSKULL;
GRANT ALL ON PEOPLE_MOODLE TO IT;
GRANT ALL ON PEOPLE_MOODLE TO IT1;
GRANT ALL ON PEOPLE_MOODLE TO IT2;
GRANT ALL ON PEOPLE_MOODLE TO IT3;
GRANT ALL ON PEOPLE_MOODLE TO IT4;
GRANT ALL ON PEOPLE_MOODLE TO IT5;
GRANT ALL ON PEOPLE_MOODLE TO IT6;
GRANT ALL ON PEOPLE_MOODLE TO IT7;
GRANT ALL ON PEOPLE_MOODLE TO IT8;
GRANT ALL ON PEOPLE_MOODLE TO IT_8;
GRANT ALL ON PEOPLE_MOODLE TO IT_M;
GRANT ALL ON PEOPLE_MOODLE TO IVANOVA_A;
GRANT ALL ON PEOPLE_MOODLE TO JKMUF2507;
GRANT ALL ON PEOPLE_MOODLE TO KANDRUKEVICH_M;
GRANT ALL ON PEOPLE_MOODLE TO KAND_M;
GRANT ALL ON PEOPLE_MOODLE TO KOSIK_N;
GRANT ALL ON PEOPLE_MOODLE TO KRISTINA;
GRANT ALL ON PEOPLE_MOODLE TO LAVRENOVA_V;
GRANT ALL ON PEOPLE_MOODLE TO LENAUSOVA;
GRANT ALL ON PEOPLE_MOODLE TO LIASHKOVICH_I;
GRANT ALL ON PEOPLE_MOODLE TO LTRFYFN2019;
GRANT ALL ON PEOPLE_MOODLE TO MAGISTR;
GRANT ALL ON PEOPLE_MOODLE TO MARINA;
GRANT ALL ON PEOPLE_MOODLE TO MATUSEVICH;
GRANT ALL ON PEOPLE_MOODLE TO MIMI;
GRANT ALL ON PEOPLE_MOODLE TO MSIT;
GRANT ALL ON PEOPLE_MOODLE TO MVS1;
GRANT ALL ON PEOPLE_MOODLE TO MVS2;
GRANT ALL ON PEOPLE_MOODLE TO MVS3;
GRANT ALL ON PEOPLE_MOODLE TO MVS4;
GRANT ALL ON PEOPLE_MOODLE TO MVS_G;
GRANT ALL ON PEOPLE_MOODLE TO MVS_N;
GRANT ALL ON PEOPLE_MOODLE TO MVS_ZAM;
GRANT ALL ON PEOPLE_MOODLE TO M_2;
GRANT ALL ON PEOPLE_MOODLE TO NEWLOGIN;
GRANT ALL ON PEOPLE_MOODLE TO NOVIK_A;
GRANT ALL ON PEOPLE_MOODLE TO OFKIT1;
GRANT ALL ON PEOPLE_MOODLE TO OFKIT2;
GRANT ALL ON PEOPLE_MOODLE TO OFKIT3;
GRANT ALL ON PEOPLE_MOODLE TO OFKIT4;
GRANT ALL ON PEOPLE_MOODLE TO OFKIT_D_A;
GRANT ALL ON PEOPLE_MOODLE TO OFKIT_LAB;
GRANT ALL ON PEOPLE_MOODLE TO OKSANA;
GRANT ALL ON PEOPLE_MOODLE TO OK_STUD_2;
GRANT ALL ON PEOPLE_MOODLE TO OK_STUD_N;
GRANT ALL ON PEOPLE_MOODLE TO OK_STUD_SL;
GRANT ALL ON PEOPLE_MOODLE TO PK1;
GRANT ALL ON PEOPLE_MOODLE TO PK2;
GRANT ALL ON PEOPLE_MOODLE TO PK3;
GRANT ALL ON PEOPLE_MOODLE TO PK4;
GRANT ALL ON PEOPLE_MOODLE TO PK_MSTIG1;
GRANT ALL ON PEOPLE_MOODLE TO PK_MSTIG2;
GRANT ALL ON PEOPLE_MOODLE TO PK_MSTIG3;
GRANT ALL ON PEOPLE_MOODLE TO PK_MSTIG4;
GRANT ALL ON PEOPLE_MOODLE TO PK_MSTIGP1;
GRANT ALL ON PEOPLE_MOODLE TO PK_MSTIGP2;
GRANT ALL ON PEOPLE_MOODLE TO PK_MSTIG_1;
GRANT ALL ON PEOPLE_MOODLE TO PK_MSTIG_2;
GRANT ALL ON PEOPLE_MOODLE TO PK_MSTIG_3;
GRANT ALL ON PEOPLE_MOODLE TO PK_MSTIG_4;
GRANT ALL ON PEOPLE_MOODLE TO PK_MSTIG_P1;
GRANT ALL ON PEOPLE_MOODLE TO PK_MSTIG_P2;
GRANT ALL ON PEOPLE_MOODLE TO PK_MVS1;
GRANT ALL ON PEOPLE_MOODLE TO PK_MVS4;
GRANT ALL ON PEOPLE_MOODLE TO PK_MVSP1;
GRANT ALL ON PEOPLE_MOODLE TO PK_MVSP2;
GRANT ALL ON PEOPLE_MOODLE TO PK_MVS_1;
GRANT ALL ON PEOPLE_MOODLE TO PK_MVS_2;
GRANT ALL ON PEOPLE_MOODLE TO PK_MVS_3;
GRANT ALL ON PEOPLE_MOODLE TO PK_MVS_4;
GRANT ALL ON PEOPLE_MOODLE TO PK_MVS_P1;
GRANT ALL ON PEOPLE_MOODLE TO PK_MVS_P2;
GRANT ALL ON PEOPLE_MOODLE TO PK_OFKITP1;
GRANT ALL ON PEOPLE_MOODLE TO PK_OFKITP2;
GRANT ALL ON PEOPLE_MOODLE TO PK_OFK_1;
GRANT ALL ON PEOPLE_MOODLE TO PK_OFK_2;
GRANT ALL ON PEOPLE_MOODLE TO PK_OFK_3;
GRANT ALL ON PEOPLE_MOODLE TO PK_OFK_4;
GRANT ALL ON PEOPLE_MOODLE TO PK_OFK_P1;
GRANT ALL ON PEOPLE_MOODLE TO PK_OFK_P2;
GRANT ALL ON PEOPLE_MOODLE TO PK_OTV1;
GRANT ALL ON PEOPLE_MOODLE TO PK_OTV2;
GRANT ALL ON PEOPLE_MOODLE TO PK_OTV3;
GRANT ALL ON PEOPLE_MOODLE TO PK_OTV4;
GRANT ALL ON PEOPLE_MOODLE TO PK_SIIEP1;
GRANT ALL ON PEOPLE_MOODLE TO PK_SIIEP2;
GRANT ALL ON PEOPLE_MOODLE TO PK_SIIE_1;
GRANT ALL ON PEOPLE_MOODLE TO PK_SIIE_2;
GRANT ALL ON PEOPLE_MOODLE TO PK_SIIE_3;
GRANT ALL ON PEOPLE_MOODLE TO PK_SIIE_4;
GRANT ALL ON PEOPLE_MOODLE TO PK_SIIE_P1;
GRANT ALL ON PEOPLE_MOODLE TO PK_SIIE_P2;
GRANT ALL ON PEOPLE_MOODLE TO PLANIDA_E;
GRANT SELECT ON PEOPLE_MOODLE TO PRESS_01;
GRANT ALL ON PEOPLE_MOODLE TO SADIK;
GRANT ALL ON PEOPLE_MOODLE TO SEL_COM;
GRANT ALL ON PEOPLE_MOODLE TO SERAFIMOVICH_Y;
GRANT ALL ON PEOPLE_MOODLE TO SETUN1998;
GRANT ALL ON PEOPLE_MOODLE TO SHMAENKOVA_M;
GRANT ALL ON PEOPLE_MOODLE TO SHPAKEVICH_P;
GRANT ALL ON PEOPLE_MOODLE TO SIIE5;
GRANT ALL ON PEOPLE_MOODLE TO SIIE_BELAYA_M;
GRANT ALL ON PEOPLE_MOODLE TO SIIE_Z;
GRANT ALL ON PEOPLE_MOODLE TO SMOLENKOVA_T;
GRANT ALL ON PEOPLE_MOODLE TO STUDENT;
GRANT ALL ON PEOPLE_MOODLE TO SVETA;
GRANT ALL ON PEOPLE_MOODLE TO TEST_PREPOD;
GRANT ALL ON PEOPLE_MOODLE TO TEST_PROBA;
GRANT ALL ON PEOPLE_MOODLE TO TEST_STUD;
GRANT ALL ON PEOPLE_MOODLE TO UHNOVEC;
GRANT ALL ON PEOPLE_MOODLE TO UO_N;
GRANT SELECT ON PEOPLE_MOODLE TO VIEWER1;
GRANT ALL ON PEOPLE_MOODLE TO VIEWER_MOB;
GRANT ALL ON PEOPLE_MOODLE TO VNUK;
GRANT ALL ON PEOPLE_MOODLE TO VOROBEI75;
GRANT ALL ON PEOPLE_MOODLE TO YA;
GRANT ALL ON PEOPLE_MOODLE TO YAUHENI_HATSURA;
GRANT ALL ON PEOPLE_MOODLE TO ZHANNA_73;