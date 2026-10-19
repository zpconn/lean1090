// Lean compiler output
// Module: Impl.CPR
// Imports: public import Init public meta import Init public import Model.Types
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(lean_object*);
lean_object* l_Rat_div(lean_object*, lean_object*);
uint8_t l_Rat_blt(lean_object*, lean_object*);
lean_object* l_Rat_neg(lean_object*);
uint8_t l_Rat_instDecidableLe(lean_object*, lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l_Rat_add(lean_object*, lean_object*);
lean_object* l_Rat_mul(lean_object*, lean_object*);
lean_object* l_Rat_floor(lean_object*);
lean_object* l_Rat_ofInt(lean_object*);
lean_object* l_Rat_sub(lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* lean_int_emod(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint8_t l_instDecidableEqRat_decEq(lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* l_Int_toNat(lean_object*);
lean_object* lean_int_add(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_scale;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_parity(uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_parity___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_span___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_span___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_span___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_span___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_span(uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_span___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_absQ___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_absQ___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_absQ(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_modQ(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_normalizeLongitude___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_normalizeLongitude___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_normalizeLongitude(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__4;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__5;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__6;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__7;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__8;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__9;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__10;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__11_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__11;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__12;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__13;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__14;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__15;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__16_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__16;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__17;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__18_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__18;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__19_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__19;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__20_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__20;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__21_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__21;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__22_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__22;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__23_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__23;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__24_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__24;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__25_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__25;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__26_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__26;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__27_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__27;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__28_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__28;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__29_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__29;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__30_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__30;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__31_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__31;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__32_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__32;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__33_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__33;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__34_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__34;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__35_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__35;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__36_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__36;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__37_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__37;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__38_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__38;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__39_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__39;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__40_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__40;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__41_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__41;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__42_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__42;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__43_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__43;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__44_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__44;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__45_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__45;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__46_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__46;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__47_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__47;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__48_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__48;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__49_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__49;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__50_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__50;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__51_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__51;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__52_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__52;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__53_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__53;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__54_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__54;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__55_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__55;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__56_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__56;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_transitions___closed__57_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions___closed__57;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions;
static lean_once_cell_t lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0___closed__0;
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_nlTable___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_nlTable___closed__0;
static const lean_array_object lp_lean1090_Lean1090_Impl_CPR_nlTable___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_lean1090_Lean1090_Impl_CPR_nlTable___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_CPR_nlTable___closed__1_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_nlTable(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_oracleNLTable_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_oracleNLTable_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_oracleNLTable(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_dLat(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_dLat___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_zones(lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_zones___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_dLon(uint8_t, uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_dLon___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_roundedLatitude(uint8_t, uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_encodeCoordinate___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_encodeCoordinate___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_encodeCoordinate(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_encode(uint8_t, uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_encode___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_localCoordinate(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_localLatitude(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_localLatitude___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_decodeLocal___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_decodeLocal___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_decodeLocal(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_decodeLocal___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__4;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__5;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__6;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_globalLatitudes(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_decodeGlobal(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_decodeGlobal___boxed(lean_object*, lean_object*, lean_object*);
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_scale(void){
_start:
{
lean_object* v___x_1_; 
v___x_1_ = lean_unsigned_to_nat(131072u);
return v___x_1_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_parity(uint8_t v_odd_2_){
_start:
{
if (v_odd_2_ == 0)
{
lean_object* v___x_3_; 
v___x_3_ = lean_unsigned_to_nat(0u);
return v___x_3_;
}
else
{
lean_object* v___x_4_; 
v___x_4_ = lean_unsigned_to_nat(1u);
return v___x_4_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_parity___boxed(lean_object* v_odd_5_){
_start:
{
uint8_t v_odd_boxed_6_; lean_object* v_res_7_; 
v_odd_boxed_6_ = lean_unbox(v_odd_5_);
v_res_7_ = lp_lean1090_Lean1090_Impl_CPR_parity(v_odd_boxed_6_);
return v_res_7_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_span___closed__0(void){
_start:
{
lean_object* v___x_8_; lean_object* v___x_9_; 
v___x_8_ = lean_unsigned_to_nat(360u);
v___x_9_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_8_);
return v___x_9_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_span___closed__1(void){
_start:
{
lean_object* v___x_10_; lean_object* v___x_11_; 
v___x_10_ = lean_unsigned_to_nat(90u);
v___x_11_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_10_);
return v___x_11_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_span(uint8_t v_x_12_){
_start:
{
if (v_x_12_ == 0)
{
lean_object* v___x_13_; 
v___x_13_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_span___closed__0, &lp_lean1090_Lean1090_Impl_CPR_span___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_span___closed__0);
return v___x_13_;
}
else
{
lean_object* v___x_14_; 
v___x_14_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_span___closed__1, &lp_lean1090_Lean1090_Impl_CPR_span___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_span___closed__1);
return v___x_14_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_span___boxed(lean_object* v_x_15_){
_start:
{
uint8_t v_x_40__boxed_16_; lean_object* v_res_17_; 
v_x_40__boxed_16_ = lean_unbox(v_x_15_);
v_res_17_ = lp_lean1090_Lean1090_Impl_CPR_span(v_x_40__boxed_16_);
return v_res_17_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_absQ___closed__0(void){
_start:
{
lean_object* v___x_18_; lean_object* v___x_19_; 
v___x_18_ = lean_unsigned_to_nat(0u);
v___x_19_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_18_);
return v___x_19_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_absQ(lean_object* v_x_20_){
_start:
{
lean_object* v___x_21_; uint8_t v___x_22_; 
v___x_21_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_absQ___closed__0, &lp_lean1090_Lean1090_Impl_CPR_absQ___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_absQ___closed__0);
lean_inc_ref(v_x_20_);
v___x_22_ = l_Rat_blt(v_x_20_, v___x_21_);
if (v___x_22_ == 0)
{
return v_x_20_;
}
else
{
lean_object* v___x_23_; 
v___x_23_ = l_Rat_neg(v_x_20_);
return v___x_23_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_modQ(lean_object* v_x_24_, lean_object* v_y_25_){
_start:
{
lean_object* v___x_26_; lean_object* v___x_27_; lean_object* v___x_28_; lean_object* v___x_29_; lean_object* v___x_30_; 
lean_inc_ref(v_y_25_);
v___x_26_ = l_Rat_div(v_x_24_, v_y_25_);
v___x_27_ = l_Rat_floor(v___x_26_);
v___x_28_ = l_Rat_ofInt(v___x_27_);
v___x_29_ = l_Rat_mul(v_y_25_, v___x_28_);
lean_dec_ref(v_y_25_);
v___x_30_ = l_Rat_sub(v_x_24_, v___x_29_);
return v___x_30_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_normalizeLongitude___closed__0(void){
_start:
{
lean_object* v___x_31_; lean_object* v___x_32_; 
v___x_31_ = lean_unsigned_to_nat(180u);
v___x_32_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_31_);
return v___x_32_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_normalizeLongitude(lean_object* v_lon_33_){
_start:
{
lean_object* v___x_34_; lean_object* v___x_35_; lean_object* v___x_36_; lean_object* v___x_37_; lean_object* v___x_38_; 
v___x_34_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_normalizeLongitude___closed__0, &lp_lean1090_Lean1090_Impl_CPR_normalizeLongitude___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_normalizeLongitude___closed__0);
v___x_35_ = l_Rat_add(v_lon_33_, v___x_34_);
v___x_36_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_span___closed__0, &lp_lean1090_Lean1090_Impl_CPR_span___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_span___closed__0);
v___x_37_ = lp_lean1090_Lean1090_Impl_CPR_modQ(v___x_35_, v___x_36_);
v___x_38_ = l_Rat_sub(v___x_37_, v___x_34_);
return v___x_38_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__0(void){
_start:
{
lean_object* v___x_39_; lean_object* v___x_40_; lean_object* v___x_41_; 
v___x_39_ = lean_box(0);
v___x_40_ = lean_cstr_to_nat("8700000000");
v___x_41_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_41_, 0, v___x_40_);
lean_ctor_set(v___x_41_, 1, v___x_39_);
return v___x_41_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__1(void){
_start:
{
lean_object* v___x_42_; lean_object* v___x_43_; lean_object* v___x_44_; 
v___x_42_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__0, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__0);
v___x_43_ = lean_cstr_to_nat("8653536998");
v___x_44_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_44_, 0, v___x_43_);
lean_ctor_set(v___x_44_, 1, v___x_42_);
return v___x_44_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__2(void){
_start:
{
lean_object* v___x_45_; lean_object* v___x_46_; lean_object* v___x_47_; 
v___x_45_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__1, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__1);
v___x_46_ = lean_cstr_to_nat("8575541621");
v___x_47_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_47_, 0, v___x_46_);
lean_ctor_set(v___x_47_, 1, v___x_45_);
return v___x_47_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__3(void){
_start:
{
lean_object* v___x_48_; lean_object* v___x_49_; lean_object* v_y_50_; 
v___x_48_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__2, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__2);
v___x_49_ = lean_cstr_to_nat("8489166191");
v_y_50_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_y_50_, 0, v___x_49_);
lean_ctor_set(v_y_50_, 1, v___x_48_);
return v_y_50_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__4(void){
_start:
{
lean_object* v_y_51_; lean_object* v___x_52_; lean_object* v___x_53_; 
v_y_51_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__3, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__3);
v___x_52_ = lean_cstr_to_nat("8399173563");
v___x_53_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_53_, 0, v___x_52_);
lean_ctor_set(v___x_53_, 1, v_y_51_);
return v___x_53_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__5(void){
_start:
{
lean_object* v___x_54_; lean_object* v___x_55_; lean_object* v___x_56_; 
v___x_54_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__4, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__4_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__4);
v___x_55_ = lean_cstr_to_nat("8307199445");
v___x_56_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_56_, 0, v___x_55_);
lean_ctor_set(v___x_56_, 1, v___x_54_);
return v___x_56_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__6(void){
_start:
{
lean_object* v___x_57_; lean_object* v___x_58_; lean_object* v___x_59_; 
v___x_57_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__5, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__5_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__5);
v___x_58_ = lean_cstr_to_nat("8213956981");
v___x_59_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_59_, 0, v___x_58_);
lean_ctor_set(v___x_59_, 1, v___x_57_);
return v___x_59_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__7(void){
_start:
{
lean_object* v___x_60_; lean_object* v___x_61_; lean_object* v_y_62_; 
v___x_60_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__6, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__6_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__6);
v___x_61_ = lean_cstr_to_nat("8119801349");
v_y_62_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_y_62_, 0, v___x_61_);
lean_ctor_set(v_y_62_, 1, v___x_60_);
return v_y_62_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__8(void){
_start:
{
lean_object* v_y_63_; lean_object* v___x_64_; lean_object* v___x_65_; 
v_y_63_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__7, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__7_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__7);
v___x_64_ = lean_cstr_to_nat("8024923213");
v___x_65_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_65_, 0, v___x_64_);
lean_ctor_set(v___x_65_, 1, v_y_63_);
return v___x_65_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__9(void){
_start:
{
lean_object* v___x_66_; lean_object* v___x_67_; lean_object* v___x_68_; 
v___x_66_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__8, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__8_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__8);
v___x_67_ = lean_cstr_to_nat("7929428225");
v___x_68_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_68_, 0, v___x_67_);
lean_ctor_set(v___x_68_, 1, v___x_66_);
return v___x_68_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__10(void){
_start:
{
lean_object* v___x_69_; lean_object* v___x_70_; lean_object* v___x_71_; 
v___x_69_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__9, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__9_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__9);
v___x_70_ = lean_cstr_to_nat("7833374083");
v___x_71_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_71_, 0, v___x_70_);
lean_ctor_set(v___x_71_, 1, v___x_69_);
return v___x_71_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__11(void){
_start:
{
lean_object* v___x_72_; lean_object* v___x_73_; lean_object* v___x_74_; 
v___x_72_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__10, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__10_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__10);
v___x_73_ = lean_cstr_to_nat("7736789461");
v___x_74_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_74_, 0, v___x_73_);
lean_ctor_set(v___x_74_, 1, v___x_72_);
return v___x_74_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__12(void){
_start:
{
lean_object* v___x_75_; lean_object* v___x_76_; lean_object* v___x_77_; 
v___x_75_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__11, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__11_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__11);
v___x_76_ = lean_cstr_to_nat("7639684391");
v___x_77_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_77_, 0, v___x_76_);
lean_ctor_set(v___x_77_, 1, v___x_75_);
return v___x_77_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__13(void){
_start:
{
lean_object* v___x_78_; lean_object* v___x_79_; lean_object* v___x_80_; 
v___x_78_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__12, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__12_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__12);
v___x_79_ = lean_cstr_to_nat("7542056257");
v___x_80_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_80_, 0, v___x_79_);
lean_ctor_set(v___x_80_, 1, v___x_78_);
return v___x_80_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__14(void){
_start:
{
lean_object* v___x_81_; lean_object* v___x_82_; lean_object* v_y_83_; 
v___x_81_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__13, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__13_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__13);
v___x_82_ = lean_cstr_to_nat("7443893416");
v_y_83_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_y_83_, 0, v___x_82_);
lean_ctor_set(v_y_83_, 1, v___x_81_);
return v_y_83_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__15(void){
_start:
{
lean_object* v_y_84_; lean_object* v___x_85_; lean_object* v___x_86_; 
v_y_84_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__14, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__14_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__14);
v___x_85_ = lean_cstr_to_nat("7345177442");
v___x_86_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_86_, 0, v___x_85_);
lean_ctor_set(v___x_86_, 1, v_y_84_);
return v___x_86_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__16(void){
_start:
{
lean_object* v___x_87_; lean_object* v___x_88_; lean_object* v___x_89_; 
v___x_87_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__15, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__15_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__15);
v___x_88_ = lean_cstr_to_nat("7245884545");
v___x_89_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_89_, 0, v___x_88_);
lean_ctor_set(v___x_89_, 1, v___x_87_);
return v___x_89_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__17(void){
_start:
{
lean_object* v___x_90_; lean_object* v___x_91_; lean_object* v___x_92_; 
v___x_90_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__16, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__16_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__16);
v___x_91_ = lean_cstr_to_nat("7145986473");
v___x_92_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_92_, 0, v___x_91_);
lean_ctor_set(v___x_92_, 1, v___x_90_);
return v___x_92_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__18(void){
_start:
{
lean_object* v___x_93_; lean_object* v___x_94_; lean_object* v___x_95_; 
v___x_93_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__17, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__17_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__17);
v___x_94_ = lean_cstr_to_nat("7045451075");
v___x_95_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_95_, 0, v___x_94_);
lean_ctor_set(v___x_95_, 1, v___x_93_);
return v___x_95_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__19(void){
_start:
{
lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; 
v___x_96_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__18, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__18_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__18);
v___x_97_ = lean_cstr_to_nat("6944242631");
v___x_98_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_98_, 0, v___x_97_);
lean_ctor_set(v___x_98_, 1, v___x_96_);
return v___x_98_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__20(void){
_start:
{
lean_object* v___x_99_; lean_object* v___x_100_; lean_object* v___x_101_; 
v___x_99_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__19, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__19_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__19);
v___x_100_ = lean_cstr_to_nat("6842322022");
v___x_101_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_101_, 0, v___x_100_);
lean_ctor_set(v___x_101_, 1, v___x_99_);
return v___x_101_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__21(void){
_start:
{
lean_object* v___x_102_; lean_object* v___x_103_; lean_object* v_y_104_; 
v___x_102_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__20, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__20_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__20);
v___x_103_ = lean_cstr_to_nat("6739646774");
v_y_104_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_y_104_, 0, v___x_103_);
lean_ctor_set(v_y_104_, 1, v___x_102_);
return v_y_104_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__22(void){
_start:
{
lean_object* v_y_105_; lean_object* v___x_106_; lean_object* v___x_107_; 
v_y_105_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__21, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__21_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__21);
v___x_106_ = lean_cstr_to_nat("6636171008");
v___x_107_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_107_, 0, v___x_106_);
lean_ctor_set(v___x_107_, 1, v_y_105_);
return v___x_107_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__23(void){
_start:
{
lean_object* v___x_108_; lean_object* v___x_109_; lean_object* v___x_110_; 
v___x_108_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__22, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__22_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__22);
v___x_109_ = lean_cstr_to_nat("6531845310");
v___x_110_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_110_, 0, v___x_109_);
lean_ctor_set(v___x_110_, 1, v___x_108_);
return v___x_110_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__24(void){
_start:
{
lean_object* v___x_111_; lean_object* v___x_112_; lean_object* v___x_113_; 
v___x_111_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__23, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__23_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__23);
v___x_112_ = lean_cstr_to_nat("6426616523");
v___x_113_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_113_, 0, v___x_112_);
lean_ctor_set(v___x_113_, 1, v___x_111_);
return v___x_113_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__25(void){
_start:
{
lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v___x_116_; 
v___x_114_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__24, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__24_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__24);
v___x_115_ = lean_cstr_to_nat("6320427479");
v___x_116_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_116_, 0, v___x_115_);
lean_ctor_set(v___x_116_, 1, v___x_114_);
return v___x_116_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__26(void){
_start:
{
lean_object* v___x_117_; lean_object* v___x_118_; lean_object* v___x_119_; 
v___x_117_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__25, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__25_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__25);
v___x_118_ = lean_cstr_to_nat("6213216659");
v___x_119_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_119_, 0, v___x_118_);
lean_ctor_set(v___x_119_, 1, v___x_117_);
return v___x_119_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__27(void){
_start:
{
lean_object* v___x_120_; lean_object* v___x_121_; lean_object* v___x_122_; 
v___x_120_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__26, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__26_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__26);
v___x_121_ = lean_cstr_to_nat("6104917774");
v___x_122_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_122_, 0, v___x_121_);
lean_ctor_set(v___x_122_, 1, v___x_120_);
return v___x_122_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__28(void){
_start:
{
lean_object* v___x_123_; lean_object* v___x_124_; lean_object* v_y_125_; 
v___x_123_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__27, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__27_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__27);
v___x_124_ = lean_cstr_to_nat("5995459277");
v_y_125_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_y_125_, 0, v___x_124_);
lean_ctor_set(v_y_125_, 1, v___x_123_);
return v_y_125_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__29(void){
_start:
{
lean_object* v_y_126_; lean_object* v___x_127_; lean_object* v___x_128_; 
v_y_126_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__28, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__28_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__28);
v___x_127_ = lean_cstr_to_nat("5884763776");
v___x_128_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_128_, 0, v___x_127_);
lean_ctor_set(v___x_128_, 1, v_y_126_);
return v___x_128_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__30(void){
_start:
{
lean_object* v___x_129_; lean_object* v___x_130_; lean_object* v___x_131_; 
v___x_129_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__29, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__29_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__29);
v___x_130_ = lean_cstr_to_nat("5772747354");
v___x_131_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_131_, 0, v___x_130_);
lean_ctor_set(v___x_131_, 1, v___x_129_);
return v___x_131_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__31(void){
_start:
{
lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_134_; 
v___x_132_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__30, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__30_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__30);
v___x_133_ = lean_cstr_to_nat("5659318756");
v___x_134_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_134_, 0, v___x_133_);
lean_ctor_set(v___x_134_, 1, v___x_132_);
return v___x_134_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__32(void){
_start:
{
lean_object* v___x_135_; lean_object* v___x_136_; lean_object* v_y_137_; 
v___x_135_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__31, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__31_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__31);
v___x_136_ = lean_cstr_to_nat("5544378444");
v_y_137_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_y_137_, 0, v___x_136_);
lean_ctor_set(v_y_137_, 1, v___x_135_);
return v_y_137_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__33(void){
_start:
{
lean_object* v_y_138_; lean_object* v___x_139_; lean_object* v___x_140_; 
v_y_138_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__32, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__32_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__32);
v___x_139_ = lean_cstr_to_nat("5427817472");
v___x_140_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_140_, 0, v___x_139_);
lean_ctor_set(v___x_140_, 1, v_y_138_);
return v___x_140_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__34(void){
_start:
{
lean_object* v___x_141_; lean_object* v___x_142_; lean_object* v___x_143_; 
v___x_141_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__33, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__33_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__33);
v___x_142_ = lean_cstr_to_nat("5309516153");
v___x_143_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_143_, 0, v___x_142_);
lean_ctor_set(v___x_143_, 1, v___x_141_);
return v___x_143_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__35(void){
_start:
{
lean_object* v___x_144_; lean_object* v___x_145_; lean_object* v___x_146_; 
v___x_144_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__34, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__34_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__34);
v___x_145_ = lean_cstr_to_nat("5189342469");
v___x_146_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_146_, 0, v___x_145_);
lean_ctor_set(v___x_146_, 1, v___x_144_);
return v___x_146_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__36(void){
_start:
{
lean_object* v___x_147_; lean_object* v___x_148_; lean_object* v_y_149_; 
v___x_147_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__35, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__35_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__35);
v___x_148_ = lean_cstr_to_nat("5067150166");
v_y_149_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_y_149_, 0, v___x_148_);
lean_ctor_set(v_y_149_, 1, v___x_147_);
return v_y_149_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__37(void){
_start:
{
lean_object* v_y_150_; lean_object* v___x_151_; lean_object* v___x_152_; 
v_y_150_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__36, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__36_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__36);
v___x_151_ = lean_cstr_to_nat("4942776439");
v___x_152_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_152_, 0, v___x_151_);
lean_ctor_set(v___x_152_, 1, v_y_150_);
return v___x_152_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__38(void){
_start:
{
lean_object* v___x_153_; lean_object* v___x_154_; lean_object* v___x_155_; 
v___x_153_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__37, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__37_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__37);
v___x_154_ = lean_cstr_to_nat("4816039128");
v___x_155_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_155_, 0, v___x_154_);
lean_ctor_set(v___x_155_, 1, v___x_153_);
return v___x_155_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__39(void){
_start:
{
lean_object* v___x_156_; lean_object* v___x_157_; lean_object* v___x_158_; 
v___x_156_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__38, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__38_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__38);
v___x_157_ = lean_cstr_to_nat("4686733252");
v___x_158_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_158_, 0, v___x_157_);
lean_ctor_set(v___x_158_, 1, v___x_156_);
return v___x_158_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__40(void){
_start:
{
lean_object* v___x_159_; lean_object* v___x_160_; lean_object* v___x_161_; 
v___x_159_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__39, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__39_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__39);
v___x_160_ = lean_cstr_to_nat("4554626723");
v___x_161_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_161_, 0, v___x_160_);
lean_ctor_set(v___x_161_, 1, v___x_159_);
return v___x_161_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__41(void){
_start:
{
lean_object* v___x_162_; lean_object* v___x_163_; lean_object* v___x_164_; 
v___x_162_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__40, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__40_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__40);
v___x_163_ = lean_cstr_to_nat("4419454951");
v___x_164_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_164_, 0, v___x_163_);
lean_ctor_set(v___x_164_, 1, v___x_162_);
return v___x_164_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__42(void){
_start:
{
lean_object* v___x_165_; lean_object* v___x_166_; lean_object* v___x_167_; 
v___x_165_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__41, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__41_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__41);
v___x_166_ = lean_unsigned_to_nat(4280914012u);
v___x_167_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_167_, 0, v___x_166_);
lean_ctor_set(v___x_167_, 1, v___x_165_);
return v___x_167_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__43(void){
_start:
{
lean_object* v___x_168_; lean_object* v___x_169_; lean_object* v_y_170_; 
v___x_168_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__42, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__42_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__42);
v___x_169_ = lean_unsigned_to_nat(4138651832u);
v_y_170_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_y_170_, 0, v___x_169_);
lean_ctor_set(v_y_170_, 1, v___x_168_);
return v_y_170_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__44(void){
_start:
{
lean_object* v_y_171_; lean_object* v___x_172_; lean_object* v___x_173_; 
v_y_171_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__43, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__43_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__43);
v___x_172_ = lean_unsigned_to_nat(3992256684u);
v___x_173_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_173_, 0, v___x_172_);
lean_ctor_set(v___x_173_, 1, v_y_171_);
return v___x_173_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__45(void){
_start:
{
lean_object* v___x_174_; lean_object* v___x_175_; lean_object* v___x_176_; 
v___x_174_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__44, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__44_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__44);
v___x_175_ = lean_unsigned_to_nat(3841241892u);
v___x_176_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_176_, 0, v___x_175_);
lean_ctor_set(v___x_176_, 1, v___x_174_);
return v___x_176_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__46(void){
_start:
{
lean_object* v___x_177_; lean_object* v___x_178_; lean_object* v___x_179_; 
v___x_177_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__45, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__45_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__45);
v___x_178_ = lean_unsigned_to_nat(3685025108u);
v___x_179_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_179_, 0, v___x_178_);
lean_ctor_set(v___x_179_, 1, v___x_177_);
return v___x_179_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__47(void){
_start:
{
lean_object* v___x_180_; lean_object* v___x_181_; lean_object* v___x_182_; 
v___x_180_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__46, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__46_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__46);
v___x_181_ = lean_unsigned_to_nat(3522899598u);
v___x_182_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_182_, 0, v___x_181_);
lean_ctor_set(v___x_182_, 1, v___x_180_);
return v___x_182_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__48(void){
_start:
{
lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_185_; 
v___x_183_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__47, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__47_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__47);
v___x_184_ = lean_unsigned_to_nat(3353993436u);
v___x_185_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_185_, 0, v___x_184_);
lean_ctor_set(v___x_185_, 1, v___x_183_);
return v___x_185_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__49(void){
_start:
{
lean_object* v___x_186_; lean_object* v___x_187_; lean_object* v___x_188_; 
v___x_186_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__48, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__48_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__48);
v___x_187_ = lean_unsigned_to_nat(3177209708u);
v___x_188_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_188_, 0, v___x_187_);
lean_ctor_set(v___x_188_, 1, v___x_186_);
return v___x_188_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__50(void){
_start:
{
lean_object* v___x_189_; lean_object* v___x_190_; lean_object* v_y_191_; 
v___x_189_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__49, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__49_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__49);
v___x_190_ = lean_unsigned_to_nat(2991135686u);
v_y_191_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_y_191_, 0, v___x_190_);
lean_ctor_set(v_y_191_, 1, v___x_189_);
return v_y_191_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__51(void){
_start:
{
lean_object* v_y_192_; lean_object* v___x_193_; lean_object* v___x_194_; 
v_y_192_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__50, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__50_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__50);
v___x_193_ = lean_unsigned_to_nat(2793898710u);
v___x_194_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_194_, 0, v___x_193_);
lean_ctor_set(v___x_194_, 1, v_y_192_);
return v___x_194_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__52(void){
_start:
{
lean_object* v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; 
v___x_195_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__51, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__51_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__51);
v___x_196_ = lean_unsigned_to_nat(2582924707u);
v___x_197_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_197_, 0, v___x_196_);
lean_ctor_set(v___x_197_, 1, v___x_195_);
return v___x_197_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__53(void){
_start:
{
lean_object* v___x_198_; lean_object* v___x_199_; lean_object* v___x_200_; 
v___x_198_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__52, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__52_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__52);
v___x_199_ = lean_unsigned_to_nat(2354504487u);
v___x_200_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_200_, 0, v___x_199_);
lean_ctor_set(v___x_200_, 1, v___x_198_);
return v___x_200_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__54(void){
_start:
{
lean_object* v___x_201_; lean_object* v___x_202_; lean_object* v___x_203_; 
v___x_201_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__53, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__53_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__53);
v___x_202_ = lean_unsigned_to_nat(2102939493u);
v___x_203_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_203_, 0, v___x_202_);
lean_ctor_set(v___x_203_, 1, v___x_201_);
return v___x_203_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__55(void){
_start:
{
lean_object* v___x_204_; lean_object* v___x_205_; lean_object* v___x_206_; 
v___x_204_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__54, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__54_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__54);
v___x_205_ = lean_unsigned_to_nat(1818626357u);
v___x_206_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_206_, 0, v___x_205_);
lean_ctor_set(v___x_206_, 1, v___x_204_);
return v___x_206_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__56(void){
_start:
{
lean_object* v___x_207_; lean_object* v___x_208_; lean_object* v___x_209_; 
v___x_207_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__55, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__55_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__55);
v___x_208_ = lean_unsigned_to_nat(1482817437u);
v___x_209_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_209_, 0, v___x_208_);
lean_ctor_set(v___x_209_, 1, v___x_207_);
return v___x_209_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__57(void){
_start:
{
lean_object* v___x_210_; lean_object* v___x_211_; lean_object* v___x_212_; 
v___x_210_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__56, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__56_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__56);
v___x_211_ = lean_unsigned_to_nat(1047047130u);
v___x_212_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_212_, 0, v___x_211_);
lean_ctor_set(v___x_212_, 1, v___x_210_);
return v___x_212_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_transitions(void){
_start:
{
lean_object* v___x_213_; 
v___x_213_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_transitions___closed__57, &lp_lean1090_Lean1090_Impl_CPR_transitions___closed__57_once, _init_lp_lean1090_Lean1090_Impl_CPR_transitions___closed__57);
return v___x_213_;
}
}
static lean_object* _init_lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0___closed__0(void){
_start:
{
lean_object* v___x_214_; lean_object* v___x_215_; 
v___x_214_ = lean_unsigned_to_nat(100000000u);
v___x_215_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_214_);
return v___x_215_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0(lean_object* v___x_216_, lean_object* v_l_217_, lean_object* v_a_218_, lean_object* v_a_219_){
_start:
{
if (lean_obj_tag(v_a_218_) == 0)
{
lean_dec_ref(v_a_219_);
lean_dec_ref(v___x_216_);
lean_inc(v_l_217_);
return v_l_217_;
}
else
{
lean_object* v_head_220_; lean_object* v_tail_221_; lean_object* v___x_222_; lean_object* v___x_223_; lean_object* v___x_224_; uint8_t v___x_225_; 
v_head_220_ = lean_ctor_get(v_a_218_, 0);
lean_inc_n(v_head_220_, 2);
v_tail_221_ = lean_ctor_get(v_a_218_, 1);
lean_inc(v_tail_221_);
lean_dec_ref_known(v_a_218_, 2);
v___x_222_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_head_220_);
v___x_223_ = lean_obj_once(&lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0___closed__0, &lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0___closed__0_once, _init_lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0___closed__0);
v___x_224_ = l_Rat_div(v___x_222_, v___x_223_);
lean_dec_ref(v___x_222_);
lean_inc_ref(v___x_216_);
v___x_225_ = l_Rat_instDecidableLe(v___x_224_, v___x_216_);
if (v___x_225_ == 0)
{
lean_object* v___x_226_; 
lean_dec(v_tail_221_);
lean_dec(v_head_220_);
lean_dec_ref(v___x_216_);
v___x_226_ = lean_array_to_list(v_a_219_);
return v___x_226_;
}
else
{
lean_object* v___x_227_; 
v___x_227_ = lean_array_push(v_a_219_, v_head_220_);
v_a_218_ = v_tail_221_;
v_a_219_ = v___x_227_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0___boxed(lean_object* v___x_229_, lean_object* v_l_230_, lean_object* v_a_231_, lean_object* v_a_232_){
_start:
{
lean_object* v_res_233_; 
v_res_233_ = lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0(v___x_229_, v_l_230_, v_a_231_, v_a_232_);
lean_dec(v_l_230_);
return v_res_233_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_nlTable___closed__0(void){
_start:
{
lean_object* v___x_234_; lean_object* v___x_235_; 
v___x_234_ = lean_unsigned_to_nat(87u);
v___x_235_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_234_);
return v___x_235_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_nlTable(lean_object* v_lat_238_){
_start:
{
lean_object* v___x_239_; lean_object* v___x_240_; uint8_t v___x_241_; 
v___x_239_ = lp_lean1090_Lean1090_Impl_CPR_absQ(v_lat_238_);
v___x_240_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_nlTable___closed__0, &lp_lean1090_Lean1090_Impl_CPR_nlTable___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_nlTable___closed__0);
v___x_241_ = l_instDecidableEqRat_decEq(v___x_239_, v___x_240_);
if (v___x_241_ == 0)
{
lean_object* v___x_242_; lean_object* v___x_243_; lean_object* v___x_244_; lean_object* v___x_245_; lean_object* v___x_246_; lean_object* v___x_247_; 
v___x_242_ = lean_unsigned_to_nat(59u);
v___x_243_ = lp_lean1090_Lean1090_Impl_CPR_transitions;
v___x_244_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_nlTable___closed__1));
v___x_245_ = lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0(v___x_239_, v___x_243_, v___x_243_, v___x_244_);
v___x_246_ = l_List_lengthTR___redArg(v___x_245_);
lean_dec(v___x_245_);
v___x_247_ = lean_nat_sub(v___x_242_, v___x_246_);
lean_dec(v___x_246_);
return v___x_247_;
}
else
{
lean_object* v___x_248_; 
lean_dec_ref(v___x_239_);
v___x_248_ = lean_unsigned_to_nat(2u);
return v___x_248_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_oracleNLTable_spec__0(lean_object* v_lat_249_, lean_object* v_l_250_, lean_object* v_a_251_, lean_object* v_a_252_){
_start:
{
if (lean_obj_tag(v_a_251_) == 0)
{
lean_dec_ref(v_a_252_);
lean_dec_ref(v_lat_249_);
lean_inc(v_l_250_);
return v_l_250_;
}
else
{
lean_object* v_head_253_; lean_object* v_tail_254_; lean_object* v___x_255_; lean_object* v___x_256_; lean_object* v___x_257_; lean_object* v___x_258_; uint8_t v___x_259_; 
v_head_253_ = lean_ctor_get(v_a_251_, 0);
lean_inc_n(v_head_253_, 2);
v_tail_254_ = lean_ctor_get(v_a_251_, 1);
lean_inc(v_tail_254_);
lean_dec_ref_known(v_a_251_, 2);
v___x_255_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_head_253_);
v___x_256_ = lean_obj_once(&lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0___closed__0, &lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0___closed__0_once, _init_lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_nlTable_spec__0___closed__0);
v___x_257_ = l_Rat_div(v___x_255_, v___x_256_);
lean_dec_ref(v___x_255_);
lean_inc_ref(v_lat_249_);
v___x_258_ = lp_lean1090_Lean1090_Impl_CPR_absQ(v_lat_249_);
v___x_259_ = l_Rat_instDecidableLe(v___x_257_, v___x_258_);
if (v___x_259_ == 0)
{
lean_object* v___x_260_; 
lean_dec(v_tail_254_);
lean_dec(v_head_253_);
lean_dec_ref(v_lat_249_);
v___x_260_ = lean_array_to_list(v_a_252_);
return v___x_260_;
}
else
{
lean_object* v___x_261_; 
v___x_261_ = lean_array_push(v_a_252_, v_head_253_);
v_a_251_ = v_tail_254_;
v_a_252_ = v___x_261_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_oracleNLTable_spec__0___boxed(lean_object* v_lat_263_, lean_object* v_l_264_, lean_object* v_a_265_, lean_object* v_a_266_){
_start:
{
lean_object* v_res_267_; 
v_res_267_ = lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_oracleNLTable_spec__0(v_lat_263_, v_l_264_, v_a_265_, v_a_266_);
lean_dec(v_l_264_);
return v_res_267_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_oracleNLTable(lean_object* v_lat_268_){
_start:
{
lean_object* v___x_269_; lean_object* v___x_270_; lean_object* v___x_271_; lean_object* v___x_272_; lean_object* v___x_273_; lean_object* v___x_274_; 
v___x_269_ = lean_unsigned_to_nat(59u);
v___x_270_ = lp_lean1090_Lean1090_Impl_CPR_transitions;
v___x_271_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_nlTable___closed__1));
v___x_272_ = lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_oracleNLTable_spec__0(v_lat_268_, v___x_270_, v___x_270_, v___x_271_);
v___x_273_ = l_List_lengthTR___redArg(v___x_272_);
lean_dec(v___x_272_);
v___x_274_ = lean_nat_sub(v___x_269_, v___x_273_);
lean_dec(v___x_273_);
return v___x_274_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_dLat(uint8_t v_mode_275_, uint8_t v_odd_276_){
_start:
{
lean_object* v___x_277_; lean_object* v___x_278_; lean_object* v___x_279_; lean_object* v___x_280_; lean_object* v___x_281_; lean_object* v___x_282_; 
v___x_277_ = lp_lean1090_Lean1090_Impl_CPR_span(v_mode_275_);
v___x_278_ = lean_unsigned_to_nat(60u);
v___x_279_ = lp_lean1090_Lean1090_Impl_CPR_parity(v_odd_276_);
v___x_280_ = lean_nat_sub(v___x_278_, v___x_279_);
lean_dec(v___x_279_);
v___x_281_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_280_);
v___x_282_ = l_Rat_div(v___x_277_, v___x_281_);
lean_dec_ref(v___x_277_);
return v___x_282_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_dLat___boxed(lean_object* v_mode_283_, lean_object* v_odd_284_){
_start:
{
uint8_t v_mode_boxed_285_; uint8_t v_odd_boxed_286_; lean_object* v_res_287_; 
v_mode_boxed_285_ = lean_unbox(v_mode_283_);
v_odd_boxed_286_ = lean_unbox(v_odd_284_);
v_res_287_ = lp_lean1090_Lean1090_Impl_CPR_dLat(v_mode_boxed_285_, v_odd_boxed_286_);
return v_res_287_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_zones(lean_object* v_lat_288_, uint8_t v_odd_289_){
_start:
{
lean_object* v___x_290_; lean_object* v___x_291_; lean_object* v___x_292_; lean_object* v___x_293_; uint8_t v___x_294_; 
v___x_290_ = lp_lean1090_Lean1090_Impl_CPR_nlTable(v_lat_288_);
v___x_291_ = lp_lean1090_Lean1090_Impl_CPR_parity(v_odd_289_);
v___x_292_ = lean_nat_sub(v___x_290_, v___x_291_);
lean_dec(v___x_291_);
lean_dec(v___x_290_);
v___x_293_ = lean_unsigned_to_nat(1u);
v___x_294_ = lean_nat_dec_le(v___x_292_, v___x_293_);
if (v___x_294_ == 0)
{
return v___x_292_;
}
else
{
lean_dec(v___x_292_);
return v___x_293_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_zones___boxed(lean_object* v_lat_295_, lean_object* v_odd_296_){
_start:
{
uint8_t v_odd_boxed_297_; lean_object* v_res_298_; 
v_odd_boxed_297_ = lean_unbox(v_odd_296_);
v_res_298_ = lp_lean1090_Lean1090_Impl_CPR_zones(v_lat_295_, v_odd_boxed_297_);
return v_res_298_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_dLon(uint8_t v_mode_299_, uint8_t v_odd_300_, lean_object* v_lat_301_){
_start:
{
lean_object* v___x_302_; lean_object* v___x_303_; lean_object* v___x_304_; lean_object* v___x_305_; 
v___x_302_ = lp_lean1090_Lean1090_Impl_CPR_span(v_mode_299_);
v___x_303_ = lp_lean1090_Lean1090_Impl_CPR_zones(v_lat_301_, v_odd_300_);
v___x_304_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_303_);
v___x_305_ = l_Rat_div(v___x_302_, v___x_304_);
lean_dec_ref(v___x_302_);
return v___x_305_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_dLon___boxed(lean_object* v_mode_306_, lean_object* v_odd_307_, lean_object* v_lat_308_){
_start:
{
uint8_t v_mode_boxed_309_; uint8_t v_odd_boxed_310_; lean_object* v_res_311_; 
v_mode_boxed_309_ = lean_unbox(v_mode_306_);
v_odd_boxed_310_ = lean_unbox(v_odd_307_);
v_res_311_ = lp_lean1090_Lean1090_Impl_CPR_dLon(v_mode_boxed_309_, v_odd_boxed_310_, v_lat_308_);
return v_res_311_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0(void){
_start:
{
lean_object* v___x_312_; lean_object* v___x_313_; 
v___x_312_ = lean_unsigned_to_nat(131072u);
v___x_313_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_312_);
return v___x_313_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__1(void){
_start:
{
lean_object* v___x_314_; lean_object* v___x_315_; 
v___x_314_ = lean_unsigned_to_nat(1u);
v___x_315_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_314_);
return v___x_315_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__2(void){
_start:
{
lean_object* v___x_316_; lean_object* v___x_317_; 
v___x_316_ = lean_unsigned_to_nat(2u);
v___x_317_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_316_);
return v___x_317_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3(void){
_start:
{
lean_object* v___x_318_; lean_object* v___x_319_; lean_object* v___x_320_; 
v___x_318_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__2, &lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__2);
v___x_319_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__1, &lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__1);
v___x_320_ = l_Rat_div(v___x_319_, v___x_318_);
return v___x_320_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_roundedLatitude(uint8_t v_mode_321_, uint8_t v_odd_322_, lean_object* v_lat_323_){
_start:
{
lean_object* v_d_324_; lean_object* v___x_325_; lean_object* v___x_326_; lean_object* v___x_327_; lean_object* v___x_328_; lean_object* v___x_329_; lean_object* v___x_330_; lean_object* v___x_331_; lean_object* v___x_332_; lean_object* v___x_333_; 
v_d_324_ = lp_lean1090_Lean1090_Impl_CPR_dLat(v_mode_321_, v_odd_322_);
v___x_325_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0, &lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0);
v___x_326_ = l_Rat_div(v_d_324_, v___x_325_);
v___x_327_ = l_Rat_div(v_lat_323_, v_d_324_);
v___x_328_ = l_Rat_mul(v___x_327_, v___x_325_);
lean_dec_ref(v___x_327_);
v___x_329_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3, &lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3);
v___x_330_ = l_Rat_add(v___x_328_, v___x_329_);
v___x_331_ = l_Rat_floor(v___x_330_);
v___x_332_ = l_Rat_ofInt(v___x_331_);
v___x_333_ = l_Rat_mul(v___x_326_, v___x_332_);
lean_dec_ref(v___x_326_);
return v___x_333_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___boxed(lean_object* v_mode_334_, lean_object* v_odd_335_, lean_object* v_lat_336_){
_start:
{
uint8_t v_mode_boxed_337_; uint8_t v_odd_boxed_338_; lean_object* v_res_339_; 
v_mode_boxed_337_ = lean_unbox(v_mode_334_);
v_odd_boxed_338_ = lean_unbox(v_odd_335_);
v_res_339_ = lp_lean1090_Lean1090_Impl_CPR_roundedLatitude(v_mode_boxed_337_, v_odd_boxed_338_, v_lat_336_);
lean_dec_ref(v_lat_336_);
return v_res_339_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_encodeCoordinate___closed__0(void){
_start:
{
lean_object* v___x_340_; lean_object* v___x_341_; 
v___x_340_ = lean_unsigned_to_nat(131072u);
v___x_341_ = lean_nat_to_int(v___x_340_);
return v___x_341_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_encodeCoordinate(lean_object* v_width_342_, lean_object* v_coordinate_343_){
_start:
{
lean_object* v___x_344_; lean_object* v___x_345_; lean_object* v___x_346_; lean_object* v___x_347_; lean_object* v___x_348_; lean_object* v___x_349_; lean_object* v___x_350_; lean_object* v___x_351_; lean_object* v___x_352_; lean_object* v___x_353_; 
lean_inc_ref(v_width_342_);
v___x_344_ = lp_lean1090_Lean1090_Impl_CPR_modQ(v_coordinate_343_, v_width_342_);
v___x_345_ = l_Rat_div(v___x_344_, v_width_342_);
lean_dec_ref(v___x_344_);
v___x_346_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0, &lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0);
v___x_347_ = l_Rat_mul(v___x_345_, v___x_346_);
lean_dec_ref(v___x_345_);
v___x_348_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3, &lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3);
v___x_349_ = l_Rat_add(v___x_347_, v___x_348_);
v___x_350_ = l_Rat_floor(v___x_349_);
v___x_351_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_encodeCoordinate___closed__0, &lp_lean1090_Lean1090_Impl_CPR_encodeCoordinate___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_encodeCoordinate___closed__0);
v___x_352_ = lean_int_emod(v___x_350_, v___x_351_);
lean_dec(v___x_350_);
v___x_353_ = l_Int_toNat(v___x_352_);
lean_dec(v___x_352_);
return v___x_353_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_encode(uint8_t v_mode_354_, uint8_t v_odd_355_, lean_object* v_p_356_){
_start:
{
lean_object* v_lat_357_; lean_object* v_lon_358_; lean_object* v_lat_359_; lean_object* v___x_360_; lean_object* v___x_361_; lean_object* v___x_362_; lean_object* v___x_363_; lean_object* v___x_364_; 
v_lat_357_ = lean_ctor_get(v_p_356_, 0);
lean_inc_ref(v_lat_357_);
v_lon_358_ = lean_ctor_get(v_p_356_, 1);
lean_inc_ref(v_lon_358_);
lean_dec_ref(v_p_356_);
v_lat_359_ = lp_lean1090_Lean1090_Impl_CPR_roundedLatitude(v_mode_354_, v_odd_355_, v_lat_357_);
v___x_360_ = lp_lean1090_Lean1090_Impl_CPR_dLat(v_mode_354_, v_odd_355_);
v___x_361_ = lp_lean1090_Lean1090_Impl_CPR_encodeCoordinate(v___x_360_, v_lat_357_);
v___x_362_ = lp_lean1090_Lean1090_Impl_CPR_dLon(v_mode_354_, v_odd_355_, v_lat_359_);
v___x_363_ = lp_lean1090_Lean1090_Impl_CPR_encodeCoordinate(v___x_362_, v_lon_358_);
v___x_364_ = lean_alloc_ctor(0, 2, 1);
lean_ctor_set(v___x_364_, 0, v___x_361_);
lean_ctor_set(v___x_364_, 1, v___x_363_);
lean_ctor_set_uint8(v___x_364_, sizeof(void*)*2, v_odd_355_);
return v___x_364_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_encode___boxed(lean_object* v_mode_365_, lean_object* v_odd_366_, lean_object* v_p_367_){
_start:
{
uint8_t v_mode_boxed_368_; uint8_t v_odd_boxed_369_; lean_object* v_res_370_; 
v_mode_boxed_368_ = lean_unbox(v_mode_365_);
v_odd_boxed_369_ = lean_unbox(v_odd_366_);
v_res_370_ = lp_lean1090_Lean1090_Impl_CPR_encode(v_mode_boxed_368_, v_odd_boxed_369_, v_p_367_);
return v_res_370_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_localCoordinate(lean_object* v_width_371_, lean_object* v_reference_372_, lean_object* v_code_373_){
_start:
{
lean_object* v___x_374_; lean_object* v___x_375_; lean_object* v_fraction_376_; lean_object* v___x_377_; lean_object* v___x_378_; lean_object* v___x_379_; lean_object* v___x_380_; lean_object* v___x_381_; lean_object* v___x_382_; lean_object* v___x_383_; lean_object* v___x_384_; lean_object* v_j_385_; lean_object* v___x_386_; lean_object* v___x_387_; lean_object* v___x_388_; 
v___x_374_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_373_);
v___x_375_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0, &lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0);
v_fraction_376_ = l_Rat_div(v___x_374_, v___x_375_);
lean_dec_ref(v___x_374_);
lean_inc_ref_n(v_width_371_, 3);
v___x_377_ = l_Rat_div(v_reference_372_, v_width_371_);
v___x_378_ = l_Rat_floor(v___x_377_);
v___x_379_ = lp_lean1090_Lean1090_Impl_CPR_modQ(v_reference_372_, v_width_371_);
v___x_380_ = l_Rat_div(v___x_379_, v_width_371_);
lean_dec_ref(v___x_379_);
lean_inc_ref(v_fraction_376_);
v___x_381_ = l_Rat_sub(v___x_380_, v_fraction_376_);
v___x_382_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3, &lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3);
v___x_383_ = l_Rat_add(v___x_381_, v___x_382_);
v___x_384_ = l_Rat_floor(v___x_383_);
v_j_385_ = lean_int_add(v___x_378_, v___x_384_);
lean_dec(v___x_384_);
lean_dec(v___x_378_);
v___x_386_ = l_Rat_ofInt(v_j_385_);
v___x_387_ = l_Rat_add(v___x_386_, v_fraction_376_);
v___x_388_ = l_Rat_mul(v_width_371_, v___x_387_);
lean_dec_ref(v_width_371_);
return v___x_388_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_localLatitude(uint8_t v_mode_389_, lean_object* v_e_390_, lean_object* v_reference_391_){
_start:
{
uint8_t v_odd_392_; lean_object* v_lat_393_; lean_object* v_lat_394_; lean_object* v___x_395_; lean_object* v___x_396_; 
v_odd_392_ = lean_ctor_get_uint8(v_e_390_, sizeof(void*)*2);
v_lat_393_ = lean_ctor_get(v_e_390_, 0);
lean_inc(v_lat_393_);
lean_dec_ref(v_e_390_);
v_lat_394_ = lean_ctor_get(v_reference_391_, 0);
lean_inc_ref(v_lat_394_);
lean_dec_ref(v_reference_391_);
v___x_395_ = lp_lean1090_Lean1090_Impl_CPR_dLat(v_mode_389_, v_odd_392_);
v___x_396_ = lp_lean1090_Lean1090_Impl_CPR_localCoordinate(v___x_395_, v_lat_394_, v_lat_393_);
return v___x_396_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_localLatitude___boxed(lean_object* v_mode_397_, lean_object* v_e_398_, lean_object* v_reference_399_){
_start:
{
uint8_t v_mode_boxed_400_; lean_object* v_res_401_; 
v_mode_boxed_400_ = lean_unbox(v_mode_397_);
v_res_401_ = lp_lean1090_Lean1090_Impl_CPR_localLatitude(v_mode_boxed_400_, v_e_398_, v_reference_399_);
return v_res_401_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_decodeLocal___closed__0(void){
_start:
{
lean_object* v___x_402_; lean_object* v___x_403_; 
v___x_402_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_span___closed__1, &lp_lean1090_Lean1090_Impl_CPR_span___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_span___closed__1);
v___x_403_ = l_Rat_neg(v___x_402_);
return v___x_403_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_decodeLocal(uint8_t v_mode_404_, lean_object* v_e_405_, lean_object* v_reference_406_){
_start:
{
uint8_t v_odd_407_; lean_object* v_lat_408_; lean_object* v_lon_409_; lean_object* v___x_410_; uint8_t v___x_411_; 
v_odd_407_ = lean_ctor_get_uint8(v_e_405_, sizeof(void*)*2);
v_lat_408_ = lean_ctor_get(v_e_405_, 0);
v_lon_409_ = lean_ctor_get(v_e_405_, 1);
lean_inc(v_lon_409_);
v___x_410_ = lean_unsigned_to_nat(131072u);
v___x_411_ = lean_nat_dec_lt(v_lat_408_, v___x_410_);
if (v___x_411_ == 0)
{
lean_object* v___x_412_; 
lean_dec(v_lon_409_);
lean_dec_ref(v_reference_406_);
lean_dec_ref(v_e_405_);
v___x_412_ = lean_box(0);
return v___x_412_;
}
else
{
uint8_t v___x_413_; 
v___x_413_ = lean_nat_dec_lt(v_lon_409_, v___x_410_);
if (v___x_413_ == 0)
{
lean_object* v___x_414_; 
lean_dec(v_lon_409_);
lean_dec_ref(v_reference_406_);
lean_dec_ref(v_e_405_);
v___x_414_ = lean_box(0);
return v___x_414_;
}
else
{
lean_object* v_lat_415_; lean_object* v___x_416_; lean_object* v___x_417_; uint8_t v___x_418_; 
lean_inc_ref(v_reference_406_);
v_lat_415_ = lp_lean1090_Lean1090_Impl_CPR_localLatitude(v_mode_404_, v_e_405_, v_reference_406_);
v___x_416_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_span___closed__1, &lp_lean1090_Lean1090_Impl_CPR_span___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_span___closed__1);
v___x_417_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_decodeLocal___closed__0, &lp_lean1090_Lean1090_Impl_CPR_decodeLocal___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_decodeLocal___closed__0);
lean_inc_ref(v_lat_415_);
v___x_418_ = l_Rat_instDecidableLe(v___x_417_, v_lat_415_);
if (v___x_418_ == 0)
{
lean_object* v___x_419_; 
lean_dec_ref(v_lat_415_);
lean_dec(v_lon_409_);
lean_dec_ref(v_reference_406_);
v___x_419_ = lean_box(0);
return v___x_419_;
}
else
{
uint8_t v___x_420_; 
lean_inc_ref(v_lat_415_);
v___x_420_ = l_Rat_instDecidableLe(v_lat_415_, v___x_416_);
if (v___x_420_ == 0)
{
lean_object* v___x_421_; 
lean_dec_ref(v_lat_415_);
lean_dec(v_lon_409_);
lean_dec_ref(v_reference_406_);
v___x_421_ = lean_box(0);
return v___x_421_;
}
else
{
lean_object* v_lon_422_; lean_object* v___x_424_; uint8_t v_isShared_425_; uint8_t v_isSharedCheck_432_; 
v_lon_422_ = lean_ctor_get(v_reference_406_, 1);
v_isSharedCheck_432_ = !lean_is_exclusive(v_reference_406_);
if (v_isSharedCheck_432_ == 0)
{
lean_object* v_unused_433_; 
v_unused_433_ = lean_ctor_get(v_reference_406_, 0);
lean_dec(v_unused_433_);
v___x_424_ = v_reference_406_;
v_isShared_425_ = v_isSharedCheck_432_;
goto v_resetjp_423_;
}
else
{
lean_inc(v_lon_422_);
lean_dec(v_reference_406_);
v___x_424_ = lean_box(0);
v_isShared_425_ = v_isSharedCheck_432_;
goto v_resetjp_423_;
}
v_resetjp_423_:
{
lean_object* v___x_426_; lean_object* v___x_427_; lean_object* v___x_429_; 
lean_inc_ref(v_lat_415_);
v___x_426_ = lp_lean1090_Lean1090_Impl_CPR_dLon(v_mode_404_, v_odd_407_, v_lat_415_);
v___x_427_ = lp_lean1090_Lean1090_Impl_CPR_localCoordinate(v___x_426_, v_lon_422_, v_lon_409_);
if (v_isShared_425_ == 0)
{
lean_ctor_set(v___x_424_, 1, v___x_427_);
lean_ctor_set(v___x_424_, 0, v_lat_415_);
v___x_429_ = v___x_424_;
goto v_reusejp_428_;
}
else
{
lean_object* v_reuseFailAlloc_431_; 
v_reuseFailAlloc_431_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_431_, 0, v_lat_415_);
lean_ctor_set(v_reuseFailAlloc_431_, 1, v___x_427_);
v___x_429_ = v_reuseFailAlloc_431_;
goto v_reusejp_428_;
}
v_reusejp_428_:
{
lean_object* v___x_430_; 
v___x_430_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_430_, 0, v___x_429_);
return v___x_430_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_decodeLocal___boxed(lean_object* v_mode_434_, lean_object* v_e_435_, lean_object* v_reference_436_){
_start:
{
uint8_t v_mode_boxed_437_; lean_object* v_res_438_; 
v_mode_boxed_437_ = lean_unbox(v_mode_434_);
v_res_438_ = lp_lean1090_Lean1090_Impl_CPR_decodeLocal(v_mode_boxed_437_, v_e_435_, v_reference_436_);
return v_res_438_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__0(void){
_start:
{
lean_object* v___x_439_; lean_object* v___x_440_; 
v___x_439_ = lean_unsigned_to_nat(59u);
v___x_440_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_439_);
return v___x_440_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__1(void){
_start:
{
lean_object* v___x_441_; lean_object* v___x_442_; 
v___x_441_ = lean_unsigned_to_nat(60u);
v___x_442_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_441_);
return v___x_442_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__2(void){
_start:
{
uint8_t v___x_443_; uint8_t v___x_444_; lean_object* v___x_445_; 
v___x_443_ = 0;
v___x_444_ = 0;
v___x_445_ = lp_lean1090_Lean1090_Impl_CPR_dLat(v___x_444_, v___x_443_);
return v___x_445_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__3(void){
_start:
{
lean_object* v___x_446_; lean_object* v___x_447_; 
v___x_446_ = lean_unsigned_to_nat(60u);
v___x_447_ = lean_nat_to_int(v___x_446_);
return v___x_447_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__4(void){
_start:
{
uint8_t v___x_448_; uint8_t v___x_449_; lean_object* v___x_450_; 
v___x_448_ = 1;
v___x_449_ = 0;
v___x_450_ = lp_lean1090_Lean1090_Impl_CPR_dLat(v___x_449_, v___x_448_);
return v___x_450_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__5(void){
_start:
{
lean_object* v___x_451_; lean_object* v___x_452_; 
v___x_451_ = lean_unsigned_to_nat(59u);
v___x_452_ = lean_nat_to_int(v___x_451_);
return v___x_452_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__6(void){
_start:
{
lean_object* v___x_453_; lean_object* v___x_454_; 
v___x_453_ = lean_unsigned_to_nat(270u);
v___x_454_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_453_);
return v___x_454_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_globalLatitudes(lean_object* v_even_455_, lean_object* v_odd_456_){
_start:
{
lean_object* v_lat_457_; lean_object* v_lat_458_; lean_object* v___x_459_; lean_object* v___x_460_; lean_object* v_a_461_; lean_object* v___x_462_; lean_object* v_b_463_; lean_object* v___x_464_; lean_object* v___x_465_; lean_object* v___x_466_; lean_object* v___x_467_; lean_object* v___x_468_; lean_object* v___x_469_; lean_object* v___x_470_; lean_object* v_j_471_; lean_object* v___x_472_; lean_object* v___x_473_; lean_object* v___x_474_; lean_object* v___x_475_; lean_object* v___x_476_; lean_object* v_l0_477_; lean_object* v___x_478_; lean_object* v___x_479_; lean_object* v___x_480_; lean_object* v___x_481_; lean_object* v___x_482_; lean_object* v_l1_483_; lean_object* v___x_484_; lean_object* v___y_486_; uint8_t v___x_492_; 
v_lat_457_ = lean_ctor_get(v_even_455_, 0);
lean_inc(v_lat_457_);
lean_dec_ref(v_even_455_);
v_lat_458_ = lean_ctor_get(v_odd_456_, 0);
lean_inc(v_lat_458_);
lean_dec_ref(v_odd_456_);
v___x_459_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_lat_457_);
v___x_460_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0, &lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0);
v_a_461_ = l_Rat_div(v___x_459_, v___x_460_);
lean_dec_ref(v___x_459_);
v___x_462_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_lat_458_);
v_b_463_ = l_Rat_div(v___x_462_, v___x_460_);
lean_dec_ref(v___x_462_);
v___x_464_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__0, &lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__0);
lean_inc_ref(v_a_461_);
v___x_465_ = l_Rat_mul(v___x_464_, v_a_461_);
v___x_466_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__1, &lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__1);
lean_inc_ref(v_b_463_);
v___x_467_ = l_Rat_mul(v___x_466_, v_b_463_);
v___x_468_ = l_Rat_sub(v___x_465_, v___x_467_);
v___x_469_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3, &lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3);
v___x_470_ = l_Rat_add(v___x_468_, v___x_469_);
v_j_471_ = l_Rat_floor(v___x_470_);
v___x_472_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__2, &lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__2);
v___x_473_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__3, &lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__3);
v___x_474_ = lean_int_emod(v_j_471_, v___x_473_);
v___x_475_ = l_Rat_ofInt(v___x_474_);
v___x_476_ = l_Rat_add(v___x_475_, v_a_461_);
v_l0_477_ = l_Rat_mul(v___x_472_, v___x_476_);
v___x_478_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__4, &lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__4_once, _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__4);
v___x_479_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__5, &lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__5_once, _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__5);
v___x_480_ = lean_int_emod(v_j_471_, v___x_479_);
lean_dec(v_j_471_);
v___x_481_ = l_Rat_ofInt(v___x_480_);
v___x_482_ = l_Rat_add(v___x_481_, v_b_463_);
v_l1_483_ = l_Rat_mul(v___x_478_, v___x_482_);
v___x_484_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__6, &lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__6_once, _init_lp_lean1090_Lean1090_Impl_CPR_globalLatitudes___closed__6);
lean_inc_ref(v_l0_477_);
v___x_492_ = l_Rat_instDecidableLe(v___x_484_, v_l0_477_);
if (v___x_492_ == 0)
{
v___y_486_ = v_l0_477_;
goto v___jp_485_;
}
else
{
lean_object* v___x_493_; lean_object* v___x_494_; 
v___x_493_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_span___closed__0, &lp_lean1090_Lean1090_Impl_CPR_span___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_span___closed__0);
v___x_494_ = l_Rat_sub(v_l0_477_, v___x_493_);
v___y_486_ = v___x_494_;
goto v___jp_485_;
}
v___jp_485_:
{
uint8_t v___x_487_; 
lean_inc_ref(v_l1_483_);
v___x_487_ = l_Rat_instDecidableLe(v___x_484_, v_l1_483_);
if (v___x_487_ == 0)
{
lean_object* v___x_488_; 
v___x_488_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_488_, 0, v___y_486_);
lean_ctor_set(v___x_488_, 1, v_l1_483_);
return v___x_488_;
}
else
{
lean_object* v___x_489_; lean_object* v___x_490_; lean_object* v___x_491_; 
v___x_489_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_span___closed__0, &lp_lean1090_Lean1090_Impl_CPR_span___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_span___closed__0);
v___x_490_ = l_Rat_sub(v_l1_483_, v___x_489_);
v___x_491_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_491_, 0, v___y_486_);
lean_ctor_set(v___x_491_, 1, v___x_490_);
return v___x_491_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_decodeGlobal(lean_object* v_even_495_, lean_object* v_odd_496_, uint8_t v_latestOdd_497_){
_start:
{
lean_object* v___y_499_; lean_object* v___y_500_; lean_object* v___y_501_; lean_object* v___y_502_; lean_object* v___y_509_; lean_object* v___y_510_; lean_object* v___y_511_; lean_object* v___y_512_; lean_object* v___y_513_; lean_object* v___x_520_; uint8_t v_odd_521_; 
lean_inc_ref(v_odd_496_);
lean_inc_ref(v_even_495_);
v___x_520_ = lp_lean1090_Lean1090_Impl_CPR_globalLatitudes(v_even_495_, v_odd_496_);
v_odd_521_ = lean_ctor_get_uint8(v_even_495_, sizeof(void*)*2);
if (v_odd_521_ == 0)
{
lean_object* v_fst_522_; lean_object* v_snd_523_; lean_object* v_lat_524_; lean_object* v_lon_525_; uint8_t v_odd_526_; lean_object* v_lat_527_; lean_object* v_lon_528_; lean_object* v___y_530_; 
v_fst_522_ = lean_ctor_get(v___x_520_, 0);
lean_inc(v_fst_522_);
v_snd_523_ = lean_ctor_get(v___x_520_, 1);
lean_inc(v_snd_523_);
lean_dec_ref(v___x_520_);
v_lat_524_ = lean_ctor_get(v_even_495_, 0);
lean_inc(v_lat_524_);
v_lon_525_ = lean_ctor_get(v_even_495_, 1);
lean_inc(v_lon_525_);
lean_dec_ref(v_even_495_);
v_odd_526_ = lean_ctor_get_uint8(v_odd_496_, sizeof(void*)*2);
v_lat_527_ = lean_ctor_get(v_odd_496_, 0);
lean_inc(v_lat_527_);
v_lon_528_ = lean_ctor_get(v_odd_496_, 1);
lean_inc(v_lon_528_);
lean_dec_ref(v_odd_496_);
if (v_odd_526_ == 0)
{
lean_object* v___x_550_; 
lean_dec(v_lon_528_);
lean_dec(v_lat_527_);
lean_dec(v_lon_525_);
lean_dec(v_lat_524_);
lean_dec(v_snd_523_);
lean_dec(v_fst_522_);
v___x_550_ = lean_box(0);
return v___x_550_;
}
else
{
lean_object* v___x_551_; uint8_t v___x_552_; 
v___x_551_ = lean_unsigned_to_nat(131072u);
v___x_552_ = lean_nat_dec_lt(v_lat_524_, v___x_551_);
lean_dec(v_lat_524_);
if (v___x_552_ == 0)
{
lean_object* v___x_553_; 
lean_dec(v_lon_528_);
lean_dec(v_lat_527_);
lean_dec(v_lon_525_);
lean_dec(v_snd_523_);
lean_dec(v_fst_522_);
v___x_553_ = lean_box(0);
return v___x_553_;
}
else
{
uint8_t v___x_554_; 
v___x_554_ = lean_nat_dec_lt(v_lon_525_, v___x_551_);
if (v___x_554_ == 0)
{
lean_object* v___x_555_; 
lean_dec(v_lon_528_);
lean_dec(v_lat_527_);
lean_dec(v_lon_525_);
lean_dec(v_snd_523_);
lean_dec(v_fst_522_);
v___x_555_ = lean_box(0);
return v___x_555_;
}
else
{
uint8_t v___x_556_; 
v___x_556_ = lean_nat_dec_lt(v_lat_527_, v___x_551_);
lean_dec(v_lat_527_);
if (v___x_556_ == 0)
{
lean_object* v___x_557_; 
lean_dec(v_lon_528_);
lean_dec(v_lon_525_);
lean_dec(v_snd_523_);
lean_dec(v_fst_522_);
v___x_557_ = lean_box(0);
return v___x_557_;
}
else
{
uint8_t v___x_558_; 
v___x_558_ = lean_nat_dec_lt(v_lon_528_, v___x_551_);
if (v___x_558_ == 0)
{
lean_object* v___x_559_; 
lean_dec(v_lon_528_);
lean_dec(v_lon_525_);
lean_dec(v_snd_523_);
lean_dec(v_fst_522_);
v___x_559_ = lean_box(0);
return v___x_559_;
}
else
{
lean_object* v___x_560_; lean_object* v___x_561_; uint8_t v___x_562_; 
v___x_560_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_span___closed__1, &lp_lean1090_Lean1090_Impl_CPR_span___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_span___closed__1);
v___x_561_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_decodeLocal___closed__0, &lp_lean1090_Lean1090_Impl_CPR_decodeLocal___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_decodeLocal___closed__0);
lean_inc(v_fst_522_);
v___x_562_ = l_Rat_instDecidableLe(v___x_561_, v_fst_522_);
if (v___x_562_ == 0)
{
lean_object* v___x_563_; 
lean_dec(v_lon_528_);
lean_dec(v_lon_525_);
lean_dec(v_snd_523_);
lean_dec(v_fst_522_);
v___x_563_ = lean_box(0);
return v___x_563_;
}
else
{
uint8_t v___x_564_; 
lean_inc(v_fst_522_);
v___x_564_ = l_Rat_instDecidableLe(v_fst_522_, v___x_560_);
if (v___x_564_ == 0)
{
lean_object* v___x_565_; 
lean_dec(v_lon_528_);
lean_dec(v_lon_525_);
lean_dec(v_snd_523_);
lean_dec(v_fst_522_);
v___x_565_ = lean_box(0);
return v___x_565_;
}
else
{
uint8_t v___x_566_; 
lean_inc(v_snd_523_);
v___x_566_ = l_Rat_instDecidableLe(v___x_561_, v_snd_523_);
if (v___x_566_ == 0)
{
lean_object* v___x_567_; 
lean_dec(v_lon_528_);
lean_dec(v_lon_525_);
lean_dec(v_snd_523_);
lean_dec(v_fst_522_);
v___x_567_ = lean_box(0);
return v___x_567_;
}
else
{
uint8_t v___x_568_; 
lean_inc(v_snd_523_);
v___x_568_ = l_Rat_instDecidableLe(v_snd_523_, v___x_560_);
if (v___x_568_ == 0)
{
lean_object* v___x_569_; 
lean_dec(v_lon_528_);
lean_dec(v_lon_525_);
lean_dec(v_snd_523_);
lean_dec(v_fst_522_);
v___x_569_ = lean_box(0);
return v___x_569_;
}
else
{
lean_object* v___x_570_; lean_object* v___x_571_; uint8_t v___x_572_; 
lean_inc(v_fst_522_);
v___x_570_ = lp_lean1090_Lean1090_Impl_CPR_nlTable(v_fst_522_);
lean_inc(v_snd_523_);
v___x_571_ = lp_lean1090_Lean1090_Impl_CPR_nlTable(v_snd_523_);
v___x_572_ = lean_nat_dec_eq(v___x_570_, v___x_571_);
lean_dec(v___x_571_);
lean_dec(v___x_570_);
if (v___x_572_ == 0)
{
lean_object* v___x_573_; 
lean_dec(v_lon_528_);
lean_dec(v_lon_525_);
lean_dec(v_snd_523_);
lean_dec(v_fst_522_);
v___x_573_ = lean_box(0);
return v___x_573_;
}
else
{
if (v_latestOdd_497_ == 0)
{
lean_dec(v_snd_523_);
v___y_530_ = v_fst_522_;
goto v___jp_529_;
}
else
{
lean_dec(v_fst_522_);
v___y_530_ = v_snd_523_;
goto v___jp_529_;
}
}
}
}
}
}
}
}
}
}
}
v___jp_529_:
{
lean_object* v_n_531_; lean_object* v___x_532_; lean_object* v___x_533_; lean_object* v_a_534_; lean_object* v___x_535_; lean_object* v_b_536_; lean_object* v___x_537_; lean_object* v___x_538_; lean_object* v___x_539_; lean_object* v___x_540_; lean_object* v___x_541_; lean_object* v___x_542_; lean_object* v___x_543_; lean_object* v___x_544_; lean_object* v___x_545_; lean_object* v_m_546_; lean_object* v___x_547_; lean_object* v___x_548_; uint8_t v___x_549_; 
lean_inc_ref(v___y_530_);
v_n_531_ = lp_lean1090_Lean1090_Impl_CPR_nlTable(v___y_530_);
v___x_532_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_lon_525_);
v___x_533_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0, &lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__0);
v_a_534_ = l_Rat_div(v___x_532_, v___x_533_);
lean_dec_ref(v___x_532_);
v___x_535_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_lon_528_);
v_b_536_ = l_Rat_div(v___x_535_, v___x_533_);
lean_dec_ref(v___x_535_);
v___x_537_ = lean_unsigned_to_nat(1u);
v___x_538_ = lean_nat_sub(v_n_531_, v___x_537_);
v___x_539_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_538_);
v___x_540_ = l_Rat_mul(v_a_534_, v___x_539_);
lean_inc(v_n_531_);
v___x_541_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_n_531_);
v___x_542_ = l_Rat_mul(v_b_536_, v___x_541_);
v___x_543_ = l_Rat_sub(v___x_540_, v___x_542_);
v___x_544_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3, &lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_roundedLatitude___closed__3);
v___x_545_ = l_Rat_add(v___x_543_, v___x_544_);
v_m_546_ = l_Rat_floor(v___x_545_);
v___x_547_ = lp_lean1090_Lean1090_Impl_CPR_parity(v_latestOdd_497_);
v___x_548_ = lean_nat_sub(v_n_531_, v___x_547_);
lean_dec(v___x_547_);
lean_dec(v_n_531_);
v___x_549_ = lean_nat_dec_le(v___x_548_, v___x_537_);
if (v___x_549_ == 0)
{
v___y_509_ = v_m_546_;
v___y_510_ = v___y_530_;
v___y_511_ = v_b_536_;
v___y_512_ = v_a_534_;
v___y_513_ = v___x_548_;
goto v___jp_508_;
}
else
{
lean_dec(v___x_548_);
v___y_509_ = v_m_546_;
v___y_510_ = v___y_530_;
v___y_511_ = v_b_536_;
v___y_512_ = v_a_534_;
v___y_513_ = v___x_537_;
goto v___jp_508_;
}
}
}
else
{
lean_object* v___x_574_; 
lean_dec_ref(v___x_520_);
lean_dec_ref(v_odd_496_);
lean_dec_ref(v_even_495_);
v___x_574_ = lean_box(0);
return v___x_574_;
}
v___jp_498_:
{
lean_object* v___x_503_; lean_object* v_lon_504_; lean_object* v___x_505_; lean_object* v___x_506_; lean_object* v___x_507_; 
v___x_503_ = l_Rat_add(v___y_499_, v___y_502_);
v_lon_504_ = l_Rat_mul(v___y_501_, v___x_503_);
lean_dec_ref(v___y_501_);
v___x_505_ = lp_lean1090_Lean1090_Impl_CPR_normalizeLongitude(v_lon_504_);
v___x_506_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_506_, 0, v___y_500_);
lean_ctor_set(v___x_506_, 1, v___x_505_);
v___x_507_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_507_, 0, v___x_506_);
return v___x_507_;
}
v___jp_508_:
{
lean_object* v___x_514_; lean_object* v___x_515_; lean_object* v___x_516_; lean_object* v___x_517_; lean_object* v___x_518_; lean_object* v___x_519_; 
v___x_514_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_span___closed__0, &lp_lean1090_Lean1090_Impl_CPR_span___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_span___closed__0);
lean_inc(v___y_513_);
v___x_515_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___y_513_);
v___x_516_ = l_Rat_div(v___x_514_, v___x_515_);
v___x_517_ = lean_nat_to_int(v___y_513_);
v___x_518_ = lean_int_emod(v___y_509_, v___x_517_);
lean_dec(v___x_517_);
lean_dec(v___y_509_);
v___x_519_ = l_Rat_ofInt(v___x_518_);
if (v_latestOdd_497_ == 0)
{
lean_dec_ref(v___y_511_);
v___y_499_ = v___x_519_;
v___y_500_ = v___y_510_;
v___y_501_ = v___x_516_;
v___y_502_ = v___y_512_;
goto v___jp_498_;
}
else
{
lean_dec_ref(v___y_512_);
v___y_499_ = v___x_519_;
v___y_500_ = v___y_510_;
v___y_501_ = v___x_516_;
v___y_502_ = v___y_511_;
goto v___jp_498_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_decodeGlobal___boxed(lean_object* v_even_575_, lean_object* v_odd_576_, lean_object* v_latestOdd_577_){
_start:
{
uint8_t v_latestOdd_boxed_578_; lean_object* v_res_579_; 
v_latestOdd_boxed_578_ = lean_unbox(v_latestOdd_577_);
v_res_579_ = lp_lean1090_Lean1090_Impl_CPR_decodeGlobal(v_even_575_, v_odd_576_, v_latestOdd_boxed_578_);
return v_res_579_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Model_Types(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_CPR(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
lean_initialize_runtime_module();
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Model_Types(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_lean1090_Lean1090_Impl_CPR_scale = _init_lp_lean1090_Lean1090_Impl_CPR_scale();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_CPR_scale);
lp_lean1090_Lean1090_Impl_CPR_transitions = _init_lp_lean1090_Lean1090_Impl_CPR_transitions();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_CPR_transitions);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
