/******************************************************************************/

/******************************************************************************/
/***      Following SET SQL DIALECT is just for the Database Comparer       ***/
/******************************************************************************/


/******************************************************************************/
/***                                 Views                                  ***/
/******************************************************************************/


/* View: PEOPLE_NUMBER */
CREATE OR ALTER VIEW PEOPLE_NUMBER(
    NOMER,
    D_PRIKAZ,
    NUMBER)
AS
select people.nomer,  people.d_prikaz_include, people.number from people
where people.d_prikaz_include >= "01.01.2020"
order by people.d_prikaz_include, people.nomer
;




/******************************************************************************/
/***                               Privileges                               ***/
/******************************************************************************/


/* Privileges of users */
GRANT ALL ON PEOPLE_NUMBER TO ALENA_2109;
GRANT ALL ON PEOPLE_NUMBER TO ALINA_E;
GRANT ALL ON PEOPLE_NUMBER TO GUNICH_O;
GRANT ALL ON PEOPLE_NUMBER TO KANDRUKEVICH_M;
GRANT ALL ON PEOPLE_NUMBER TO KOSIK_N;
GRANT ALL ON PEOPLE_NUMBER TO LIASHKOVICH_I;
GRANT ALL ON PEOPLE_NUMBER TO OK_STUD_2;
GRANT ALL ON PEOPLE_NUMBER TO PK_OTV1;
GRANT ALL ON PEOPLE_NUMBER TO PK_OTV2;
GRANT ALL ON PEOPLE_NUMBER TO PK_OTV3;
GRANT ALL ON PEOPLE_NUMBER TO PK_OTV4;
GRANT ALL ON PEOPLE_NUMBER TO SADIK;
GRANT ALL ON PEOPLE_NUMBER TO SETUN1998;
GRANT ALL ON PEOPLE_NUMBER TO SMOLENKOVA_T;
GRANT ALL ON PEOPLE_NUMBER TO ZHANNA_73;