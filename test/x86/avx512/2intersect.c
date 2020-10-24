/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN 2intersect

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/2intersect.h>

static int
test_simde_mm_2intersect_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const simde__mmask8 k1;
    const simde__mmask8 k2;
  } test_vec[] = {
    { {  INT32_C(  1933024678),  INT32_C(  1654182574),  INT32_C(  2112578681),  INT32_C(  1940886531) },
      { -INT32_C(  1741466723),  INT32_C(  1850577758),  INT32_C(  1878396937),  INT32_C(  1834180551) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { { -INT32_C(  1411347460), -INT32_C(   686982819), -INT32_C(   531302179),  INT32_C(  1411347460) },
      { -INT32_C(  1245608361),  INT32_C(  1411347460), -INT32_C(   426632674),  INT32_C(  1968432505) },
      UINT8_C(  8),
      UINT8_C(  2) },
    { {  INT32_C(  1560976195),  INT32_C(  1560976195),  INT32_C(  1560976195),  INT32_C(  1560976195) },
      {  INT32_C(  1560976195), -INT32_C(   931123542), -INT32_C(  1045556664),  INT32_C(  1748370168) },
      UINT8_C( 15),
      UINT8_C(  1) },
    { { -INT32_C(   482977994), -INT32_C(  1435640956), -INT32_C(   765732907), -INT32_C(   685295980) },
      {  INT32_C(  2067083985), -INT32_C(   482977994), -INT32_C(   482977994),  INT32_C(   707305460) },
      UINT8_C(  1),
      UINT8_C(  6) },
    { {  INT32_C(  2064474102),  INT32_C(   254114362), -INT32_C(   438140847), -INT32_C(  2000877130) },
      { -INT32_C(  1694240197),  INT32_C(  2064474102),  INT32_C(  2064474102),  INT32_C(  1113151564) },
      UINT8_C(  1),
      UINT8_C(  6) },
    { { -INT32_C(    11203149),  INT32_C(   838984417),  INT32_C(   421061475), -INT32_C(    11203149) },
      {  INT32_C(  1858315719),  INT32_C(   652085228), -INT32_C(    11203149),  INT32_C(   474132069) },
      UINT8_C(  9),
      UINT8_C(  4) },
    { { -INT32_C(   183566572),  INT32_C(  1160253410), -INT32_C(  1857369435), -INT32_C(   603586539) },
      { -INT32_C(  1857369435), -INT32_C(  1857369435), -INT32_C(  1685844682), -INT32_C(  1857369435) },
      UINT8_C(  4),
      UINT8_C( 11) },
    { { -INT32_C(  1480210747), -INT32_C(   940773931),  INT32_C(  1118128941), -INT32_C(   266425269) },
      {  INT32_C(  1199663222), -INT32_C(   266425269), -INT32_C(   266425269), -INT32_C(  1480210747) },
      UINT8_C(  9),
      UINT8_C( 14) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 k1, k2;
    simde_mm_2intersect_epi32(a, b, &k1, &k2);

    simde_assert_equal_u8(k1, test_vec[i].k1);
    simde_assert_equal_u8(k2, test_vec[i].k2);
  }

  return 0;
}

static int
test_simde_mm_2intersect_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const simde__mmask8 k1;
    const simde__mmask8 k2;
  } test_vec[] = {
    { { -INT64_C( 4776335177296002651),  INT64_C( 8875469304536200269) },
      {  INT64_C(  862643719312783235),  INT64_C( 2147708466904836265) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { {  INT64_C( 4045976202395705330),  INT64_C( 4045976202395705330) },
      {  INT64_C( 4045976202395705330),  INT64_C( 4045976202395705330) },
      UINT8_C(  3),
      UINT8_C(  3) },
    { { -INT64_C( 2397572822580459626), -INT64_C( 6170985749621319162) },
      { -INT64_C( 2397572822580459626), -INT64_C(  785892022578403345) },
      UINT8_C(  1),
      UINT8_C(  1) },
    { {  INT64_C( 3391546047396777466),  INT64_C( 3593163477413257996) },
      {  INT64_C( 3593163477413257996), -INT64_C(  541550164919252183) },
      UINT8_C(  2),
      UINT8_C(  1) },
    { {  INT64_C( 3561287535980966675), -INT64_C( 5515149198495544545) },
      {  INT64_C( 1587772868994464785),  INT64_C( 1587772868994464785) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { {  INT64_C( 8128785740146199590),  INT64_C( 8128785740146199590) },
      {  INT64_C( 9088189746117568130),  INT64_C( 8128785740146199590) },
      UINT8_C(  3),
      UINT8_C(  2) },
    { {  INT64_C( 3587253327639487946),  INT64_C( 7488792276366498831) },
      {  INT64_C( 3587253327639487946), -INT64_C( 4033080124360595636) },
      UINT8_C(  1),
      UINT8_C(  1) },
    { { -INT64_C( 2532488855789940029), -INT64_C( 3119956717484221082) },
      {  INT64_C( 7328211024378615371), -INT64_C( 3119956717484221082) },
      UINT8_C(  2),
      UINT8_C(  2) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 k1, k2;
    simde_mm_2intersect_epi64(a, b, &k1, &k2);

    simde_assert_equal_u8(k1, test_vec[i].k1);
    simde_assert_equal_u8(k2, test_vec[i].k2);
  }

  return 0;
}

static int
test_simde_mm256_2intersect_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t a[8];
    const int32_t b[8];
    const simde__mmask8 k1;
    const simde__mmask8 k2;
  } test_vec[] = {
    { {  INT32_C(  1217017979),  INT32_C(  1747215362), -INT32_C(  1498093887), -INT32_C(   528783467), -INT32_C(   696013891),  INT32_C(   624637876), -INT32_C(   728474186),  INT32_C(    28691334) },
      {  INT32_C(   105463556),  INT32_C(  1685024163), -INT32_C(   385211564),  INT32_C(  1204454794), -INT32_C(   450998992),  INT32_C(   990534020),  INT32_C(  1007656886),  INT32_C(  1849541738) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { { -INT32_C(  1502247421),  INT32_C(  1208673524), -INT32_C(  1859054585), -INT32_C(   891749478), -INT32_C(   844106167),  INT32_C(   101235280), -INT32_C(  1019013287), -INT32_C(   567115557) },
      { -INT32_C(    75192569), -INT32_C(  1502247421),  INT32_C(  1025733795), -INT32_C(  1502247421),  INT32_C(  1116125170), -INT32_C(   901214351), -INT32_C(  2104652890),  INT32_C(   325107468) },
      UINT8_C(  1),
      UINT8_C( 10) },
    { { -INT32_C(   250682010),  INT32_C(   377704819),  INT32_C(   894674629), -INT32_C(  1796318302), -INT32_C(  2083097326), -INT32_C(  1437786620), -INT32_C(  1238574422),  INT32_C(    13208986) },
      { -INT32_C(   437069966), -INT32_C(   894674629), -INT32_C(  1104982244), -INT32_C(  1135472214), -INT32_C(  1975572346), -INT32_C(   264926138),  INT32_C(   894674629),  INT32_C(  1610706926) },
      UINT8_C(  4),
      UINT8_C( 64) },
    { {  INT32_C(  1850143558), -INT32_C(  2057551255),  INT32_C(  1967141599),  INT32_C(   402167184),  INT32_C(    60897469),  INT32_C(  1967141599),  INT32_C(   640457272),  INT32_C(  1351036426) },
      { -INT32_C(  1967141599), -INT32_C(  1609622769),  INT32_C(   719082138),  INT32_C(  1967141599), -INT32_C(   777460979), -INT32_C(   235037511),  INT32_C(  1075325238),  INT32_C(  2039586647) },
      UINT8_C( 36),
      UINT8_C(  8) },
    { {  INT32_C(  2063814764),  INT32_C(    85660523),  INT32_C(  1294989413), -INT32_C(   621710899),  INT32_C(   229349716),  INT32_C(  1828694069),  INT32_C(  2104176048),  INT32_C(   581057974) },
      {  INT32_C(  2104176048),  INT32_C(   519944377),  INT32_C(  2104176048), -INT32_C(   229155426),  INT32_C(   754910198),  INT32_C(  2107178667), -INT32_C(   878230507),  INT32_C(   267209090) },
      UINT8_C( 64),
      UINT8_C(  5) },
    { { -INT32_C(  1475835153), -INT32_C(   205060797), -INT32_C(   797887950), -INT32_C(  1976319669),  INT32_C(  2008203979), -INT32_C(   688633152),  INT32_C(   279026574),  INT32_C(  1976319669) },
      {  INT32_C(  1551706137),  INT32_C(  1615873069),  INT32_C(  1976319669),  INT32_C(  1435300745),  INT32_C(  1976319669),  INT32_C(   374063240),  INT32_C(  1093135708), -INT32_C(  1793767556) },
      UINT8_C(128),
      UINT8_C( 20) },
    { { -INT32_C(  1992980813),  INT32_C(  1308377814), -INT32_C(  1992980813), -INT32_C(   706617568), -INT32_C(  1992980813), -INT32_C(  1992980813), -INT32_C(    15998333), -INT32_C(  1992980813) },
      { -INT32_C(  1992980813), -INT32_C(   875155000),  INT32_C(  2119706974),  INT32_C(   626211080),  INT32_C(  1439342311), -INT32_C(  1992980813), -INT32_C(  1833555352), -INT32_C(  1992980813) },
      UINT8_C(181),
      UINT8_C(161) },
    { { -INT32_C(  1719181359), -INT32_C(   278569583), -INT32_C(  1888567929),  INT32_C(   464865930), -INT32_C(  1825407137),  INT32_C(  1850364165), -INT32_C(   973078405),  INT32_C(   482552395) },
      {  INT32_C(   464865930),  INT32_C(   464865930),  INT32_C(   464865930), -INT32_C(  1716817094), -INT32_C(   131211533), -INT32_C(  1419348177), -INT32_C(  1015978376),  INT32_C(   467612817) },
      UINT8_C(  8),
      UINT8_C(  7) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 k1, k2;
    simde_mm256_2intersect_epi32(a, b, &k1, &k2);

    simde_assert_equal_u8(k1, test_vec[i].k1);
    simde_assert_equal_u8(k2, test_vec[i].k2);
  }

  return 0;
}

static int
test_simde_mm256_2intersect_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t a[4];
    const int64_t b[4];
    const simde__mmask8 k1;
    const simde__mmask8 k2;
  } test_vec[] = {
    { { -INT64_C( 8766748503608748929),  INT64_C( 8902491151602554041), -INT64_C( 6216979381371029026), -INT64_C( 2455504826211227328) },
      {  INT64_C( 2023622991203803871),  INT64_C( 5148066728463264110), -INT64_C(   58813153888836267), -INT64_C( 4219101102839063753) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { {  INT64_C( 4494427296342767328),  INT64_C( 4494427296342767328),  INT64_C( 2110521255196416139), -INT64_C( 5162773510200616018) },
      { -INT64_C( 1609937810159325542),  INT64_C( 4494427296342767328), -INT64_C( 2917026165189634687), -INT64_C(  841956137440168257) },
      UINT8_C(  3),
      UINT8_C(  2) },
    { {  INT64_C( 7958994853337910131), -INT64_C( 4289554115039553052),  INT64_C( 3856682679687434886),  INT64_C( 3041368692472213990) },
      {  INT64_C( 9186261986360726632), -INT64_C( 5419976400773268030),  INT64_C( 3856682679687434886),  INT64_C( 3366724148763797977) },
      UINT8_C(  4),
      UINT8_C(  4) },
    { {  INT64_C( 4809367613008675296),  INT64_C( 2978891424056842101),  INT64_C( 8883542278980876825), -INT64_C( 6247402992387353768) },
      { -INT64_C( 5322822373234603982), -INT64_C( 4809367613008675296),  INT64_C( 4809367613008675296), -INT64_C( 8605108578678238506) },
      UINT8_C(  1),
      UINT8_C(  4) },
    { {  INT64_C( 1658014014993689867),  INT64_C( 8597494887961549808),  INT64_C( 3557126004884492111),  INT64_C( 2701845427586504351) },
      {  INT64_C( 3557126004884492111),  INT64_C( 3557126004884492111),  INT64_C( 3557126004884492111),  INT64_C( 5834683804961742777) },
      UINT8_C(  4),
      UINT8_C(  7) },
    { {  INT64_C( 6181203837213840955),  INT64_C( 6181203837213840955), -INT64_C( 7055680582451281489),  INT64_C( 5233017304722279758) },
      { -INT64_C( 6244094469284677934),  INT64_C( 7314164337829338752),  INT64_C( 6181203837213840955),  INT64_C( 1181151732418991513) },
      UINT8_C(  3),
      UINT8_C(  4) },
    { { -INT64_C( 5164758819808562559),  INT64_C( 8867810427645032693), -INT64_C( 5974686722716203094), -INT64_C( 8301490860214009732) },
      { -INT64_C( 7651463346696779295), -INT64_C( 7651463346696779295),  INT64_C( 8942278592495508056), -INT64_C(  886080949694504164) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { {  INT64_C( 8701478350864771979), -INT64_C( 6167911330808003851),  INT64_C( 8701478350864771979), -INT64_C( 4028468504552457453) },
      { -INT64_C(  731071876734638868), -INT64_C( 6650349780674285640),  INT64_C( 8701478350864771979),  INT64_C( 5579763545130950761) },
      UINT8_C(  5),
      UINT8_C(  4) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 k1, k2;
    simde_mm256_2intersect_epi64(a, b, &k1, &k2);

    simde_assert_equal_u8(k1, test_vec[i].k1);
    simde_assert_equal_u8(k2, test_vec[i].k2);
  }

  return 0;
}

static int
test_simde_mm512_2intersect_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t a[16];
    const int32_t b[16];
    const simde__mmask16 k1;
    const simde__mmask16 k2;
  } test_vec[] = {
    { {  INT32_C(  1907319665), -INT32_C(   781809383), -INT32_C(  1797507720),  INT32_C(  1345818988),  INT32_C(  1480483164), -INT32_C(   110669168),  INT32_C(   346069938),  INT32_C(  1499533288),
        -INT32_C(  1932914574),  INT32_C(   291320217), -INT32_C(   760923802),  INT32_C(   656661706), -INT32_C(   830512834),  INT32_C(  1724376755),  INT32_C(  1786406785), -INT32_C(   373040266) },
      { -INT32_C(  2055893268),  INT32_C(   630706879), -INT32_C(   688374772),  INT32_C(  1476205337),  INT32_C(   807763068), -INT32_C(   459871134), -INT32_C(   900853676), -INT32_C(   676130325),
         INT32_C(  1583163551),  INT32_C(   126153979),  INT32_C(  1239252016),  INT32_C(   329309079), -INT32_C(  1169963689),  INT32_C(   111073714), -INT32_C(   707728151), -INT32_C(  1649638147) },
      UINT16_C(    0),
      UINT16_C(    0) },
    { { -INT32_C(  1476720212),  INT32_C(   783187965), -INT32_C(  1837658885), -INT32_C(  1096411033), -INT32_C(  1887901219), -INT32_C(  1399515453),  INT32_C(     8480258), -INT32_C(  1768083734),
         INT32_C(   893294647),  INT32_C(   325315608), -INT32_C(   542713224), -INT32_C(   794931982), -INT32_C(   127986123),  INT32_C(   799405357),  INT32_C(  1160717915), -INT32_C(  1931752364) },
      {  INT32_C(  2109806949),  INT32_C(  2123375622), -INT32_C(   245483778), -INT32_C(  1195246462),  INT32_C(  1068507154),  INT32_C(  1886344469), -INT32_C(   793403780), -INT32_C(   799239829),
        -INT32_C(  1476720212),  INT32_C(  1076878657), -INT32_C(  1476720212), -INT32_C(  1476720212),  INT32_C(   685506322), -INT32_C(   795325868),  INT32_C(  1403080424), -INT32_C(  1994129953) },
      UINT16_C(    1),
      UINT16_C( 3328) },
    { {  INT32_C(  1547333659),  INT32_C(  1654417742),  INT32_C(  2147012086), -INT32_C(   770029633), -INT32_C(  1694829242),  INT32_C(   678138431),  INT32_C(  1547333659),  INT32_C(   608804617),
         INT32_C(  1547333659), -INT32_C(   490791444), -INT32_C(  1436436245),  INT32_C(  1165786111), -INT32_C(  1327532431), -INT32_C(   371701239),  INT32_C(  1621709910),  INT32_C(    42267379) },
      {  INT32_C(  1547333659),  INT32_C(   239279907),  INT32_C(  1547333659), -INT32_C(  1877265121), -INT32_C(  1270744149),  INT32_C(  1547333659),  INT32_C(  1627146093), -INT32_C(  1369210823),
        -INT32_C(  1458584698), -INT32_C(  1162390814),  INT32_C(   361787382),  INT32_C(  1353100452), -INT32_C(   335222873),  INT32_C(  1854448128),  INT32_C(   583959785), -INT32_C(  1949290235) },
      UINT16_C(  321),
      UINT16_C(   37) },
    { { -INT32_C(   684400652),  INT32_C(   663874353), -INT32_C(    12770982),  INT32_C(  1951392717), -INT32_C(   899591222), -INT32_C(   549918218),  INT32_C(  1929512814),  INT32_C(   771674680),
        -INT32_C(   486264142),  INT32_C(  1997247773), -INT32_C(  2072622922), -INT32_C(   684400652),  INT32_C(   264198425), -INT32_C(  1309738941),  INT32_C(   925167871),  INT32_C(  1969496771) },
      {  INT32_C(  1901619284), -INT32_C(   684400652), -INT32_C(   700948565),  INT32_C(  1036726308), -INT32_C(   850621558), -INT32_C(   684400652), -INT32_C(   289824213),  INT32_C(   409149124),
        -INT32_C(  2071348090), -INT32_C(   684400652), -INT32_C(   173969200),  INT32_C(   707947936),  INT32_C(  2079817720), -INT32_C(   436374086), -INT32_C(   684400652),  INT32_C(  1542666196) },
      UINT16_C( 2049),
      UINT16_C(16930) },
    { {  INT32_C(   333413619), -INT32_C(  1092741138),  INT32_C(   666075015), -INT32_C(   464328980),  INT32_C(   526338405), -INT32_C(   704357185), -INT32_C(   407709677),  INT32_C(    54699280),
         INT32_C(   269885730), -INT32_C(  1076956104),  INT32_C(  1625784948), -INT32_C(   851101336),  INT32_C(  1106027650),  INT32_C(   337178625), -INT32_C(   637809975), -INT32_C(  1847837073) },
      { -INT32_C(  1734216865),  INT32_C(  1532457191),  INT32_C(  1522286322), -INT32_C(    98107017), -INT32_C(  1506077787), -INT32_C(   860204285), -INT32_C(  1918519779),  INT32_C(  1394508532),
         INT32_C(  1558954101),  INT32_C(   582501168), -INT32_C(   109284223),  INT32_C(   452174709), -INT32_C(  1178521930), -INT32_C(  1618576510),  INT32_C(   623651633),  INT32_C(   578374573) },
      UINT16_C(    0),
      UINT16_C(    0) },
    { {  INT32_C(   998204427),  INT32_C(   693974951),  INT32_C(   539154859),  INT32_C(   842667388), -INT32_C(   974390461), -INT32_C(  1469746825),  INT32_C(  1255051677), -INT32_C(   412268580),
         INT32_C(  1394797739), -INT32_C(   830701789), -INT32_C(   722559400), -INT32_C(   167368525),  INT32_C(  1394797739),  INT32_C(     4399459), -INT32_C(  1890905678),  INT32_C(    74889304) },
      { -INT32_C(   950560348),  INT32_C(  1394797739),  INT32_C(  1394797739), -INT32_C(   820360021), -INT32_C(  1586833858), -INT32_C(  1432178953),  INT32_C(  1394797739),  INT32_C(  1226616741),
         INT32_C(  1628468040), -INT32_C(  1210931898), -INT32_C(   740616408), -INT32_C(  1583090333), -INT32_C(  1019015732),  INT32_C(  1394797739),  INT32_C(  2006165202), -INT32_C(  1631539370) },
      UINT16_C( 4352),
      UINT16_C( 8262) },
    { {  INT32_C(  1761595426), -INT32_C(  1658859147),  INT32_C(  1282472681), -INT32_C(  1142025233),  INT32_C(   914111965), -INT32_C(   396891114),  INT32_C(   914111965),  INT32_C(   914111965),
         INT32_C(  1680050159),  INT32_C(  1090601560),  INT32_C(   747532604), -INT32_C(  1494778747), -INT32_C(  1014864211),  INT32_C(   914111965),  INT32_C(  1590627012),  INT32_C(   404313641) },
      {  INT32_C(   914111965), -INT32_C(  1133019777),  INT32_C(   914111965),  INT32_C(   914111965), -INT32_C(  1980654538),  INT32_C(   980393078), -INT32_C(   812106074),  INT32_C(  1927787156),
         INT32_C(  1856529391), -INT32_C(   819322912), -INT32_C(  1505619419),  INT32_C(   416636130),  INT32_C(  1856095992),  INT32_C(   162009187), -INT32_C(   489078450), -INT32_C(   497762061) },
      UINT16_C( 8400),
      UINT16_C(   13) },
    { {  INT32_C(    72416292),  INT32_C(  1104378652),  INT32_C(  1877415565),  INT32_C(  1787280498), -INT32_C(   422041469), -INT32_C(  2031124424), -INT32_C(  1268135743), -INT32_C(  1382630007),
        -INT32_C(   692983878), -INT32_C(   283671198),  INT32_C(   224394907),  INT32_C(  1048045243),  INT32_C(   224394907), -INT32_C(  1848765489),  INT32_C(  1699035100),  INT32_C(   224394907) },
      {  INT32_C(   629457859), -INT32_C(   485188792),  INT32_C(  1441821594),  INT32_C(  1771267930), -INT32_C(  2035238986), -INT32_C(  1508409654), -INT32_C(  1442095947), -INT32_C(    78111432),
         INT32_C(   690019809),  INT32_C(   224394907),  INT32_C(    40369576),  INT32_C(   224394907),  INT32_C(  2090933425),  INT32_C(  1344452762),  INT32_C(   224394907),  INT32_C(   224394907) },
      UINT16_C(37888),
      UINT16_C(51712) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__mmask16 k1, k2;
    simde_mm512_2intersect_epi32(a, b, &k1, &k2);

    simde_assert_equal_u16(k1, test_vec[i].k1);
    simde_assert_equal_u16(k2, test_vec[i].k2);
  }

  return 0;
}

static int
test_simde_mm512_2intersect_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const simde__mmask8 k1;
    const simde__mmask8 k2;
  } test_vec[] = {
    { {  INT64_C( 5168553055441283375), -INT64_C( 3539348696962882976),  INT64_C( 5817362346138043089),  INT64_C( 3968487147570050458),
         INT64_C( 3185622512111151184),  INT64_C(  407243940743446460), -INT64_C(  585419171191263147), -INT64_C( 5466824156440068639) },
      {  INT64_C( 6219709241949814872),  INT64_C( 7606814054839959895),  INT64_C( 1016363449530777798),  INT64_C( 4642675653713852502),
         INT64_C( 4614699684024553753), -INT64_C( 3138064399478343178), -INT64_C( 7235575661464163237), -INT64_C( 4669453642320409334) },
      UINT8_C(  0),
      UINT8_C(  0) },
    { {  INT64_C( 4755374921309394901), -INT64_C( 9180378775273354827), -INT64_C( 6049567253957406678), -INT64_C(  319526712694120149),
         INT64_C( 3887935236943184743),  INT64_C( 4755374921309394901), -INT64_C(  617094524076282335),  INT64_C( 4982487373490752772) },
      {  INT64_C( 1734428563722526300), -INT64_C( 4803963547392538067), -INT64_C( 7649943887019971310),  INT64_C( 4755374921309394901),
         INT64_C( 3706815463824562626),  INT64_C( 2712489773651406667),  INT64_C( 4755374921309394901),  INT64_C( 3153380010101671287) },
      UINT8_C( 33),
      UINT8_C( 72) },
    { { -INT64_C( 9123460286336666584),  INT64_C( 1539118865939218724), -INT64_C( 9123460286336666584),  INT64_C( 8873746391598253201),
        -INT64_C( 4284036367812810027), -INT64_C( 9123460286336666584),  INT64_C( 4151980932426210487),  INT64_C( 8349489671477378065) },
      {  INT64_C( 6946251108763207682),  INT64_C( 8156009828404257278), -INT64_C( 9046324889687907181),  INT64_C(  202034163600500667),
        -INT64_C( 9123460286336666584),  INT64_C( 7968700468414374764), -INT64_C( 5685479010123188442),  INT64_C( 1353570027672698822) },
      UINT8_C( 37),
      UINT8_C( 16) },
    { { -INT64_C( 2031627594634138333), -INT64_C( 3216355587245227491), -INT64_C( 3216355587245227491),  INT64_C( 4922574173478799738),
        -INT64_C( 3216355587245227491), -INT64_C( 8783732379857039187),  INT64_C( 8003268126061066997),  INT64_C( 3819050597373298842) },
      { -INT64_C( 3216355587245227491), -INT64_C( 5501322054403173328), -INT64_C( 3216355587245227491),  INT64_C( 3182461549434432685),
        -INT64_C( 3216355587245227491), -INT64_C( 2415448909100637430), -INT64_C( 2304457403914170796), -INT64_C( 2166793525636209448) },
      UINT8_C( 22),
      UINT8_C( 21) },
    { {  INT64_C( 1529152442343085506),  INT64_C( 1885134428219124552), -INT64_C( 7225886222500309083), -INT64_C( 4881639813352599776),
        -INT64_C( 4881639813352599776),  INT64_C( 1871862973153615129), -INT64_C( 4881639813352599776),  INT64_C( 3321127711715148600) },
      { -INT64_C( 4881639813352599776),  INT64_C( 4919248266449914807),  INT64_C( 1723319408414111010),  INT64_C( 4572830837763827512),
         INT64_C( 2401416311529263042), -INT64_C( 4881639813352599776), -INT64_C( 3045321076404049978),  INT64_C( 5902690307842808383) },
      UINT8_C( 88),
      UINT8_C( 33) },
    { { -INT64_C( 7716316538138037920), -INT64_C( 8162633823873976534), -INT64_C( 4820557501022558553), -INT64_C( 4820557501022558553),
        -INT64_C( 8695084884341802301), -INT64_C( 7716316538138037920),  INT64_C( 1657394534526917829),  INT64_C( 8962897428284991605) },
      {  INT64_C( 4520083695532266198),  INT64_C(  462040351903261004),  INT64_C( 4881702772540018459),  INT64_C( 7055136805196132274),
         INT64_C(  116335706281092147),  INT64_C( 5815819702404429167), -INT64_C( 4820557501022558553),  INT64_C( 2707313128120914342) },
      UINT8_C( 12),
      UINT8_C( 64) },
    { { -INT64_C( 2078091870763473293),  INT64_C( 2475652280986350039), -INT64_C( 5653422662837316793), -INT64_C( 6272664560019460197),
        -INT64_C( 6272664560019460197),  INT64_C( 1619342924220434101), -INT64_C( 6272664560019460197),  INT64_C( 1231787778849964068) },
      { -INT64_C( 5883929854820092705),  INT64_C( 9043367803184548763),  INT64_C( 9103191405880813417),  INT64_C( 7678633565749467912),
         INT64_C( 6887818870142972144), -INT64_C( 6272664560019460197),  INT64_C( 1101744769376845681),  INT64_C( 1837218135771262346) },
      UINT8_C( 88),
      UINT8_C( 32) },
    { { -INT64_C( 8579190114695865908),  INT64_C( 8490188015147203124),  INT64_C( 6428511732540512726),  INT64_C( 6428511732540512726),
        -INT64_C( 3880339714752709229), -INT64_C( 5659074764894222339), -INT64_C(  298302716710701158), -INT64_C( 1961642745170929904) },
      {  INT64_C( 6428511732540512726), -INT64_C( 2873912020668100368),  INT64_C( 5892163249051208328),  INT64_C( 5888770405444264579),
        -INT64_C( 3104119355101856970), -INT64_C( 7108265615378266812),  INT64_C( 6428511732540512726), -INT64_C( 6513078694919253296) },
      UINT8_C( 12),
      UINT8_C( 65) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__mmask8 k1, k2;
    simde_mm512_2intersect_epi64(a, b, &k1, &k2);

    simde_assert_equal_u8(k1, test_vec[i].k1);
    simde_assert_equal_u8(k2, test_vec[i].k2);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_2intersect_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_2intersect_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_2intersect_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_2intersect_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_2intersect_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_2intersect_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>