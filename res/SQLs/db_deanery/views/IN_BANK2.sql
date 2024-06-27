/******************************************************************************/

/******************************************************************************/
/***      Following SET SQL DIALECT is just for the Database Comparer       ***/
/******************************************************************************/


/******************************************************************************/
/***                                 Views                                  ***/
/******************************************************************************/


/* View: IN_BANK2 */
CREATE OR ALTER VIEW IN_BANK2(
    FAM1,
    NAME1,
    OTCH1,
    POL1,
    ID_TYPE1,
    FAM_ENG1,
    NAME_ENG1,
    DATA_R1,
    PLACE_R1,
    GRAGDAN1,
    CITIZENSHIP1,
    PERSONAL_NUMBER1,
    SERIESNUMBER1,
    WHO_GIVE1,
    DATE_GIVE1,
    DATE_VALID1,
    DIGITAL_CODE1,
    POSTCODE1,
    SOATO1,
    TEXT_REGION1,
    NAME_DISTRICT1,
    N_TYPE1,
    NAME_LOCALITY1,
    ID1,
    NAME_IN_RUS1,
    HOUSE1,
    FLAT1,
    CITIZENSHIP2,
    POSTCODE2,
    N_ZACHET1,
    NOMER1,
    FAC1,
    VID_EDU1,
    D_PRIKAZ_INCLUDE1,
    D_INCLUDE1,
    DATE_END1,
    OBLAST)
AS
select people.fam, people.name, people.otch, people.pol, personal_docum.id_type,
 upper(people.fam_eng), upper(people.name_eng), people.data_r, people.place_r, people.gragdan,
 people.citizenship, personal_docum.personal_number, personal_docum.series||personal_docum.number,
 personal_docum.who_give, personal_docum.date_give, personal_docum.date_valid, personal_docum.digital_code,
 people.postcode, street.soato,
 region.text_region,
  district.name_district,
 type_locality.n_type, locality.name_locality,
 type_street.id, street.name_in_rus, people.house, people.flat,
 people.citizenship, people.postcode, people.n_zachet, people.nomer, faculty.fac,
 vid_edu.vid_edu, people.d_prikaz_include, people.d_include, people.date_end, people.scholarship
from people, personal_docum,
region, district,
type_locality, locality,
 type_street, street, faculty, vid_edu
where status_people = 1
and people.nomer > 25619
and people.n_fac in (1,2,3,4)
and (people.kurs = 2 or people.kurs = 3)
and people.nomer = personal_docum.nomer
and people.id_street = street.id
and street.type_street = type_street.id
and street.id_locality = locality.id
and locality.n_district = district.n_district
and locality.type_locality = type_locality.n_type
and faculty.n_fac = people.n_fac
and vid_edu.id_vid_edu = people.vid_edu
and region.n_region = people.scholarship
and people.address_before = people.address_life
group by people.fam, people.name, people.otch, people.pol, personal_docum.id_type,
 upper(people.fam_eng), upper(people.name_eng), people.data_r, people.place_r, people.gragdan,
 people.citizenship, personal_docum.personal_number, personal_docum.series||personal_docum.number,
 personal_docum.who_give, personal_docum.date_give, personal_docum.date_valid, personal_docum.digital_code,
 people.postcode, street.soato,
 region.text_region,
 district.name_district,
  type_locality.n_type, locality.name_locality,
 type_street.id, street.name_in_rus, people.house, people.flat,
 people.citizenship, people.postcode, people.n_zachet, people.nomer, faculty.fac,
 vid_edu.vid_edu, people.d_prikaz_include, people.d_include, people.date_end, people.scholarship
order by people.fam, people.name, people.otch
;




/******************************************************************************/
/***                               Privileges                               ***/
/******************************************************************************/


/* Privileges of users */
GRANT ALL ON IN_BANK2 TO ALENA_2109;
GRANT ALL ON IN_BANK2 TO ALINA_E;
GRANT ALL ON IN_BANK2 TO GUNICH_O;
GRANT ALL ON IN_BANK2 TO KANDRUKEVICH_M;
GRANT ALL ON IN_BANK2 TO KOSIK_N;
GRANT ALL ON IN_BANK2 TO LIASHKOVICH_I;
GRANT ALL ON IN_BANK2 TO OK_STUD_2;
GRANT ALL ON IN_BANK2 TO PK_OTV1;
GRANT ALL ON IN_BANK2 TO PK_OTV2;
GRANT ALL ON IN_BANK2 TO PK_OTV3;
GRANT ALL ON IN_BANK2 TO PK_OTV4;
GRANT ALL ON IN_BANK2 TO SADIK;
GRANT ALL ON IN_BANK2 TO SETUN1998;
GRANT ALL ON IN_BANK2 TO SMOLENKOVA_T;
GRANT ALL ON IN_BANK2 TO ZHANNA_73;