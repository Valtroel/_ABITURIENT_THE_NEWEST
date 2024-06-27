# [ABITURIENT (*application*)](../../app_abiturient_2022.md) > [DMUnit](../DMUnit.md) > TFDQuery

> Back to ["ABITURIENT 2022" Project](/README.md)

> Back to [DB_ABITURIENT](../../../db/db_abiturient_2022.md)

> **ABBREVIATIONS IN THE TABLE**:</br>
> ***CN*** - connection to database;</br>
> ***dean*** - connect to "*Deanery*" database, other - to "*Abiturient*"</br>
> ***DS*** - has a *TDataSource*</br>
> ***Up*** - has a *TFDUpdateSQL*  

|                       *Component name* |    *Type*   | *CN* | *DS* | *Up* | *Description*    |
|---------------------------------------:|:-----------:|:----:|:----:|:----:|:-----------------|
|                      [AbiturCompQr][1] | TFDQuery \* |      |      |      |  |
|                    [AbiturInvTmpQr][2] | TFDQuery \* |      |      |      |  |
|                    [AbiturLogInsQr][3] | TFDQuery \* |      |      |      |  |
|                    [AbiturSirTmpQr][4] | TFDQuery \* |      |      |      |  |
|                       [AddrLogUpQr][5] | TFDQuery \* |      |      |      |  |
|                        [AdresOutQr][6] | TFDQuery \* |      |      |      |  |
|                      [AdrLogLastQr][7] | TFDQuery \* |      |      |      |  |
|                        [BlockBtnQr][8] | TFDQuery \* |      |      |      |  |
|                            [BlockQ][9] | TFDQuery \* |      |  DS  |  Up  |  |
|                        [CategUpQr][10] | TFDQuery \* |      |      |      |  |
|                 [CertificLogInsQr][11] | TFDQuery \* |      |      |      |  |
|                       [CkRegionQr][12] | TFDQuery \* | Dean |  DS  |      |  |
|                      [CntrlExrcQr][13] | TFDQuery \* |      |  DS  |      |  |
|                      [ContrySelQr][14] | TFDQuery \* |      |      |      |  |
|                        [CountryQr][15] | TFDQuery \* | Dean |  DS  |      |  |
|                         [DocumFDQ][16] | TFDQuery \* |      |      |      |  |
|                     [DocumInListQ][17] | TFDQuery \* |      |      |      |  |
|                      [FIOSearchQr][18] | TFDQuery \* |      |      |      |  |
|               [GrazdanToDekanatQr][19] | TFDQuery \* | Dean |      |      |  |
|                      [IdAbQueueQr][20] | TFDQuery \* |      |      |      |  |
|                         [InfCntQr][21] | TFDQuery \* |      |      |      |  |
|                            [InfQr][22] | TFDQuery \* |      |      |      |  |
|                   [KodSpecializQr][23] | TFDQuery \* | Dean |      |      |  |
|                        [LangSelQr][24] | TFDQuery \* | Dean |      |      |  |
|                       [ListDocFDQ][25] | TFDQuery \* |      |  DS  |  Up  |  |
|                       [LogIDSelQr][26] | TFDQuery \* |      |      |      |  |
|                        [LogLastQr][27] | TFDQuery \* |      |      |      |  |
|                        [MaxExrcQr][28] | TFDQuery \* |      |      |      |  |
|                      [OtherPrivQr][29] | TFDQuery \* |      |      |      |  |
|                         [OutCntQr][30] | TFDQuery \* |      |      |      |  |
|                         [OutDetQr][31] | TFDQuery \* |      |      |      |  |
|                            [OutQr][32] | TFDQuery \* |      |      |      |  |
|                        [OutTestQr][33] | TFDQuery \* |      |      |      |  |
|                       [PasportFDQ][34] | TFDQuery \* | Dean |  DS  |      |  |
|                       [PrintDocQr][35] | TFDQuery \* |      |      |      |  |
|                       [PrivCnttQr][36] | TFDQuery \* |      |      |      |  |
|                 [PrivilegLogSelQr][37] | TFDQuery \* |      |      |      |  |
|                           [PrivQr][38] | TFDQuery \* |      |      |      |  |
|                            [QAb_P][39] | TFDQuery \* |      |  DS  |  Up  |  |
|                     [QAb_Pr_Enter][40] | TFDQuery \* |      |  DS  |      |  |
|                        [QAbFIOPol][41] | TFDQuery \* |      |      |      |  |
|               [QAbitur_Priv_Enter][42] | TFDQuery \* |      |  DS  |  Up  |  |
|                         [QAbitura][43] | TFDQuery \* |      |  DS  |      |  |
|                     [QAdd_N_Group][44] | TFDQuery \* |      |  DS  |      |  |
|                          [QAdress][45] | TFDQuery \* | Dean |  DS  |      |  |
|                          [QCenter][46] | TFDQuery \* | Dean |  DS  |  Up  |  |
|                     [QCK_Kol_Plan][47] | TFDQuery \* |      |      |      |  |
|                              [QCk][48] | TFDQuery \* |      |  DS  |      |  |
|                     [QCkToDekanat][49] | TFDQuery \* | Dean |  DS  |  Up  |  |
|                   [QControl_Exerc][50] | TFDQuery \* |      |      |      |  |
|                          [QDelite][51] | TFDQuery \* |      |      |      |  |
|                        [QDistrict][52] | TFDQuery \* | Dean |  DS  |      |  |
|                       [QEducation][53] | TFDQuery \* |      |  DS  |      |  |
|                            [QExam][54] | TFDQuery \* |      |  DS  |      |  |
|                        [QExamSpec][55] | TFDQuery \* |      |  DS  |      |  |
|                       [QExerc_Grp][56] | TFDQuery \* |      |      |      |  |
|                 [QFindAbiturExerc][57] | TFDQuery \* |      |      |      |  |
|                        [QFotoQeue][58] | TFDQuery \* |      |      |      |  |
|                        [QFotoSign][59] | TFDQuery \* |      |      |  Up  |  |
|                      [QGIAC2kSpec][60] | TFDQuery \* |      |      |      |  |
|                       [QGIAC3Sert][61] | TFDQuery \* |      |      |      |  |
|                         [QGIACAll][62] | TFDQuery \* |      |      |      |  |
|                 [QGIACAllPrivileg][63] | TFDQuery \* |      |      |      |  |
|                [QGIACAllPrivileg1][64] | TFDQuery \* |      |      |      |  |
|                     [QGIACAllSpec][65] | TFDQuery \* |      |      |      |  |
|                      [QGIACCKSpec][66] | TFDQuery \* |      |      |      |  |
|                       [QGIACEdLic][67] | TFDQuery \* |      |      |      |  |
|                     [QGIACEdOSred][68] | TFDQuery \* |      |      |      |  |
|                 [QGIACEdOSredCity][69] | TFDQuery \* |      |      |      |  |
|                  [QGIACEdOSredVil][70] | TFDQuery \* |      |      |      |  |
|                   [QGIACForeigner][71] | TFDQuery \* |      |      |      |  |
|                       [QGIACInAll][72] | TFDQuery \* |      |      |      |  |
|                       [QGIACInCel][73] | TFDQuery \* |      |      |      |  |
|                       [QGIACKursi][74] | TFDQuery \* |      |      |      |  |
|                       [QGIACMedal][75] | TFDQuery \* |      |      |      |  |
|                         [QGIACMil][76] | TFDQuery \* |      |      |      |  |
|                       [QGIACOlimp][77] | TFDQuery \* |      |      |      |  |
|                         [QGIACPtu][78] | TFDQuery \* |      |      |      |  |
|                       [QGIACSirot][79] | TFDQuery \* |      |      |      |  |
|                    [QGIACYearSred][80] | TFDQuery \* |      |      |      |  |
|                [QGIACYearSredCity][81] | TFDQuery \* |      |      |      |  |
|                [QGIACYearSredSpec][82] | TFDQuery \* |      |      |      |  |
|                 [QGIACYearSredVil][83] | TFDQuery \* |      |      |      |  |
|                [QGroup_Count_Spec][84] | TFDQuery \* |      |  DS  |      |  |
|                     [QGroup_Count][85] | TFDQuery \* |      |  DS  |      |  |
|                      [QInc_Gr_Old][86] | TFDQuery \* | Dean |  DS  |  Up  |  |
|                              [QIP][87] | TFDQuery \* | Dean |      |      |  |
|                         [QKod_Fac][88] | TFDQuery \* | Dean |      |      |  |
|                        [QKod_Spec][89] | TFDQuery \* | Dean |      |      |  |
|                        [QLangvich][90] | TFDQuery \* | Dean |  DS  |      |  |
|               [QLangvichToDekanat][91] | TFDQuery \* | Dean |  DS  |  Up  |  |
|                    [QLetterSource][92] | TFDQuery \* |      |      |      |  |
|                 [QLetterSourceKol][93] | TFDQuery \* |      |      |      |  |
|                [QListDocToDekanat][94] | TFDQuery \* | Dean |      |  Up  |  |
|                [QLittle_Spisoc_GR][95] | TFDQuery \* |      |  DS  |      |  |
|                        [QLocality][96] | TFDQuery \* | Dean |  DS  |      |  |
|                    [QMax_Nom_Dela][97] | TFDQuery \* |      |  DS  |      |  |
|                    [QMax_Nomer_Ab][98] | TFDQuery \* |      |  DS  |      |  |
|                         [QN_group][99] | TFDQuery \* |      |      |      |  |
|                      [QNoticeFac][100] | TFDQuery \* | Dean |      |      |  |
|                      [QNoticeFIO][101] | TFDQuery \* |      |      |      |  |
|                     [QNoticeSpec][102] | TFDQuery \* | Dean |      |      |  |
|                  [QPersonalDocum][103] | TFDQuery \* |      |      |      |  |
|         [QPlan_Priem_All_Special][104] | TFDQuery \* |      |      |      |  |
|                 [QPlan_Priem_All][105] | TFDQuery \* |      |      |      |  |
|          [QPlan_Priem_CK_Special][106] | TFDQuery \* |      |      |      |  |
|                  [QPlan_Priem_CK][107] | TFDQuery \* |      |      |      |  |
|      [QPlan_Priem_Konk_All_Param][108] | TFDQuery \* |      |      |      |  |
|        [QPlan_Priem_Konk_Special][109] | TFDQuery \* |      |      |      |  |
|                [QPlan_Priem_Konk][110] | TFDQuery \* |      |      |      |  |
|               [QPlan_Priem_Price][111] | TFDQuery \* |      |      |      |  |
|                [QPlanPriem2Price][112] | TFDQuery \* |      |      |      |  |
|                 [QPlanPriemPrice][113] | TFDQuery \* |      |      |      |  |
|                  [QPrivToDekanat][114] | TFDQuery \* |      |      |      |  |
|                  [QProverka_RYOR][115] | TFDQuery \* |      |      |      |  |
|                  [QProverka_sert][116] | TFDQuery \* |      |      |      |  |
|                  [QRegion_Center][117] | TFDQuery \* |      |      |      |  |
|                    [QRep_Abitura][118] | TFDQuery \* |      |      |      |  |
|                  [QRep_Sel_Exerc][119] | TFDQuery \* |      |      |      |  |
|                    [QReport_Rasp][120] | TFDQuery \* |      |      |      |  |
|                    [QResult_Exam][121] | TFDQuery \* |      |      |      |  |
|                      [QSelect_ab][122] | TFDQuery \* |      |      |      |  |
|             [QSertificat_ex_list][123] | TFDQuery \* |      |      |      |  |
|                 [QSertificat_Res][124] | TFDQuery \* |      |      |      |  |
|                     [QSertificat][125] | TFDQuery \* |      |      |      |  |
|            [QSertificatToDekanat][126] | TFDQuery \* |      |      |      |  |
|                         [QShkala][127] | TFDQuery \* |      |      |      |  |
|               [QShow_Result_Exam][128] | TFDQuery \* |      |      |      |  |
|                      [QSpecializ][129] | TFDQuery \* |      |      |      |  |
|            [QSpecializPlan_Priem][130] | TFDQuery \* |      |      |      |  |
|               [QSpisoc_Group_Pol][131] | TFDQuery \* |      |      |      |  |
|                   [QSpisoc_Group][132] | TFDQuery \* |      |      |      |  |
|                    [QSpisok_Spec][133] | TFDQuery \* |      |      |      |  |
| [QStatistic_Every_Day_Ball_Price][134] | TFDQuery \* |      |      |      |  |
|       [QStatistic_Every_Day_Ball][135] | TFDQuery \* |      |      |      |  |
|    [QStatistic_Every_Day_Special][136] | TFDQuery \* |      |      |      |  |
|            [QStatistic_Every_Day][137] | TFDQuery \* |      |      |      |  |
|              [QStatisticEveryDay][138] | TFDQuery \* |      |      |      |  |
|                         [QStreet][139] | TFDQuery \* |      |      |      |  |
|                 [QSum_Ball_Nomer][140] | TFDQuery \* |      |      |      |  |
|                       [QSum_Ball][141] | TFDQuery \* |      |      |      |  |
|                      [QToDekanat][142] | TFDQuery \* |      |      |      |  |
|                  [QType_locality][143] | TFDQuery \* |      |      |      |  |
|                    [QType_street][144] | TFDQuery \* |      |      |      |  |
|                      [QUndo_Abit][145] | TFDQuery \* |      |      |      |  |
|                    [RegionNameQr][146] | TFDQuery \* |      |      |      |  |
|                        [RegionQr][147] | TFDQuery \* |      |      |      |  |
|                    [RegionUpCKQr][148] | TFDQuery \* |      |      |      |  |
|               [SelectLogAbiturQr][149] | TFDQuery \* |      |      |      |  |
|                    [SelPrivLogQr][150] | TFDQuery \* |      |      |      |  |
|                 [SerteficatSelQr][151] | TFDQuery \* |      |      |      |  |
|                    [SertSelLogQr][152] | TFDQuery \* |      |      |      |  |
|                       [SpecFacQr][153] | TFDQuery \* |      |      |      |  |
|                 [SpecializNameQr][154] | TFDQuery \* |      |      |      |  |
|                     [SpecializQr][155] | TFDQuery \* |      |      |      |  |
|                          [SpecQr][156] | TFDQuery \* |      |      |      |  |
|                           [SPFDQ][157] | TFDQuery \* |      |      |      |  |
|                          [SPFDQ1][158] | TFDQuery \* |      |      |      |  |
|                      [SportQuery][159] | TFDQuery \* |      |      |      |  |
|                          [SspecQ][160] | TFDQuery \* |      |      |      |  |
|                    [Stat3hAll1Qr][161] | TFDQuery \* |      |      |      |  |
|                    [Stat3hAll2Qr][162] | TFDQuery \* |      |      |      |  |
|                   [StatusQueueQr][163] | TFDQuery \* |      |      |      |  |
|                     [UpDateOutQr][164] | TFDQuery \* |      |      |      |  |
|                 [VO2KSpecializQr][165] | TFDQuery \* |      |      |      |  |
|                    [WithoutCntQr][166] | TFDQuery \* |      |      |      |  |
|                    [WithoutDetQr][167] | TFDQuery \* |      |      |      |  |
|                       [WithoutQr][168] | TFDQuery \* |      |      |      |  |
|                [WithOutTestLogQr][169] | TFDQuery \* |      |      |      |  |

---
<br>

[1]:   AbiturCompQr.md
[2]:   AbiturInvTmpQr.md
[3]:   AbiturLogInsQr.md
[4]:   AbiturSirTmpQr.md
[5]:   AddrLogUpQr.md
[6]:   AdresOutQr.md
[7]:   AdrLogLastQr.md
[8]:   BlockBtnQr.md
[9]:   BlockQ.md
[10]:  CategUpQr.md
[11]:  CertificLogInsQr.md
[12]:  CkRegionQr.md
[13]:  CntrlExrcQr.md
[14]:  ContrySelQr.md
[15]:  CountryQr.md
[16]:  DocumFDQ.md
[17]:  DocumInListQ.md
[18]:  FIOSearchQr.md
[19]:  GrazdanToDekanatQr.md
[20]:  IdAbQueueQr.md
[21]:  InfCntQr.md
[22]:  InfQr.md
[23]:  KodSpecializQr.md
[24]:  LangSelQr.md
[25]:  ListDocFDQ.md
[26]:  LogIDSelQr.md
[27]:  LogLastQr.md
[28]:  MaxExrcQr.md
[29]:  OtherPrivQr.md
[30]:  OutCntQr.md
[31]:  OutDetQr.md
[32]:  OutQr.md
[33]:  OutTestQr.md
[34]:  PasportFDQ.md
[35]:  PrintDocQr.md
[36]:  PrivCnttQr.md
[37]:  PrivilegLogSelQr.md
[38]:  PrivQr.md
[39]:  QAb_P.md
[40]:  QAb_Pr_Enter.md
[41]:  QAbFIOPol.md
[42]:  QAbitur_Priv_Enter.md
[43]:  QAbitura.md
[44]:  QAdd_N_Group.md
[45]:  QAdress.md
[46]:  QCenter.md
[47]:  QCK_Kol_Plan.md
[48]:  QCk.md
[49]:  QCkToDekanat.md
[50]:  QControl_Exerc.md
[51]:  QDelite.md
[52]:  QDistrict.md
[53]:  QEducation.md
[54]:  QExam.md
[55]:  QExamSpec.md
[56]:  QExerc_Grp.md
[57]:  QFindAbiturExerc.md
[58]:  QFotoQeue.md
[59]:  QFotoSign.md
[60]:  QGIAC2kSpec.md
[61]:  QGIAC3Sert.md
[62]:  QGIACAll.md
[63]:  QGIACAllPrivileg.md
[64]:  QGIACAllPrivileg1.md
[65]:  QGIACAllSpec.md
[66]:  QGIACCKSpec.md
[67]:  QGIACEdLic.md
[68]:  QGIACEdOSred.md
[69]:  QGIACEdOSredCity.md
[70]:  QGIACEdOSredVil.md
[71]:  QGIACForeigner.md
[72]:  QGIACInAll.md
[73]:  QGIACInCel.md
[74]:  QGIACKursi.md
[75]:  QGIACMedal.md
[76]:  QGIACMil.md
[77]:  QGIACOlimp.md
[78]:  QGIACPtu.md
[79]:  QGIACSirot.md
[80]:  QGIACYearSred.md
[81]:  QGIACYearSredCity.md
[82]:  QGIACYearSredSpec.md
[83]:  QGIACYearSredVil.md
[84]:  QGroup_Count_Spec.md
[85]:  QGroup_Count.md
[86]:  QInc_Gr_Old.md
[87]:  QIP.md
[88]:  QKod_Fac.md
[89]:  QKod_Spec.md
[90]:  QLangvich.md
[91]:  QLangvichToDekanat.m
[92]:  QLetterSource.md
[93]:  QLetterSourceKol.md
[94]:  QListDocToDekanat.md
[95]:  QLittle_Spisoc_GR.md
[96]:  QLocality.md
[97]:  QMax_Nom_Dela.md
[98]:  QMax_Nomer_Ab.md
[99]:  QN_group.md
[100]: QNoticeFac.md
[101]: QNoticeFIO.md
[102]: QNoticeSpec.md
[103]: QPersonalDocum.md
[104]: QPlan_Priem_All_Spe
[105]: QPlan_Priem_All.md
[106]: QPlan_Priem_CK_Spec
[107]: QPlan_Priem_CK.md
[108]: QPlan_Priem_Konk_Al
[109]: QPlan_Priem_Konk_Sp
[110]: QPlan_Priem_Konk.md
[111]: QPlan_Priem_Price.m
[112]: QPlanPriem2Price.md
[113]: QPlanPriemPrice.md
[114]: QPrivToDekanat.md
[115]: QProverka_RYOR.md
[116]: QProverka_sert.md
[117]: QRegion_Center.md
[118]: QRep_Abitura.md
[119]: QRep_Sel_Exerc.md
[120]: QReport_Rasp.md
[121]: QResult_Exam.md
[122]: QSelect_ab.md
[123]: QSertificat_ex_list
[124]: QSertificat_Res.md
[125]: QSertificat.md
[126]: QSertificatToDekana
[127]: QShkala.md
[128]: QShow_Result_Exam.m
[129]: QSpecializ.md
[130]: QSpecializPlan_Prie
[131]: QSpisoc_Group_Pol.m
[132]: QSpisoc_Group.md
[133]: QSpisok_Spec.md
[134]: QStatistic_Every_Da
[135]: QStatistic_Every_Da
[136]: QStatistic_Every_Da
[137]: QStatistic_Every_Da
[138]: QStatisticEveryDay.
[139]: QStreet.md
[140]: QSum_Ball_Nomer.md
[141]: QSum_Ball.md
[142]: QToDekanat.md
[143]: QType_locality.md
[144]: QType_street.md
[145]: QUndo_Abit.md
[146]: RegionNameQr.md
[147]: RegionQr.md
[148]: RegionUpCKQr.md
[149]: SelectLogAbiturQr.m
[150]: SelPrivLogQr.md
[151]: SerteficatSelQr.md
[152]: SertSelLogQr.md
[153]: SpecFacQr.md
[154]: SpecializNameQr.md
[155]: SpecializQr.md
[156]: SpecQr.md
[157]: SPFDQ.md
[158]: SPFDQ1.md
[159]: SportQuery.md
[160]: SspecQ.md
[161]: Stat3hAll1Qr.md
[162]: Stat3hAll2Qr.md
[163]: StatusQueueQr.md
[164]: UpDateOutQr.md
[165]: VO2KSpecializQr.md
[166]: WithoutCntQr.md
[167]: WithoutDetQr.md
[168]: WithoutQr.md
[169]: WithOutTestLogQr.m