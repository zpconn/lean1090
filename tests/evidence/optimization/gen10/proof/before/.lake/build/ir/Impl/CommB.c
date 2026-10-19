// Lean compiler output
// Module: Impl.CommB
// Imports: public import Init public meta import Init public import Impl.CommBLayouts public import Impl.ADSB public import Impl.Binary64 public import Impl.ScoreGate
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
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_payloadBits(lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(lean_object*);
lean_object* l_Rat_div(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_round(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_mul(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_div(lean_object*, lean_object*);
lean_object* l_Array_ofFn___redArg(lean_object*, lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
uint8_t l_Rat_instDecidableLe(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_payloadInteger(uint8_t, lean_object*, lean_object*);
lean_object* l_Rat_ofInt(lean_object*);
lean_object* l_Rat_mul(lean_object*, lean_object*);
lean_object* l_Rat_abs(lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* l_Rat_neg(lean_object*);
uint8_t l_Rat_blt(lean_object*, lean_object*);
lean_object* l_Rat_add(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_add(lean_object*, lean_object*);
lean_object* l_List_range(lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
uint32_t l_Char_ofNat(lean_object*);
uint8_t lean_uint32_dec_eq(uint32_t, uint32_t);
lean_object* l_List_lengthTR___redArg(lean_object*);
uint8_t l_List_isEmpty___redArg(lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint8_t l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(lean_object*, lean_object*);
uint8_t lp_lean1090_Lean1090_Impl_adsbHardValid(lean_object*);
lean_object* l_Int_instDecidableEq___boxed(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbAltitude(lean_object*);
uint8_t l_Option_instDecidableEq___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_sub(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_commBLayout(lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_payloadValue(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbLayout(lean_object*);
extern lean_object* lp_lean1090_Lean1090_Impl_adsbPositionLayout;
lean_object* lp_lean1090_Lean1090_Impl_decodePayloadFields(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
uint8_t lp_lean1090_Lean1090_Impl_ScoreGate_choose(lean_object*, lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGillham(lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_adsbCallsign_spec__0(lean_object*, lean_object*, lean_object*);
lean_object* lean_string_mk(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbStatus(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbStatus___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSigned(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSigned___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelected(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelected___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbTemperature44___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbVertical60___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbVertical60___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbVertical60___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVertical60(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVertical60___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNH64___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNH64___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNH64___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNH64___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNH64___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNH64___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNH64___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNH64___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNH64___closed__4;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNH64(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNH64___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachValueTable;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMach64(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMach64___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWrapAngle(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_commBValue___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "heading"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBValue___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBValue___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBValue___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "vrate_barometric"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBValue___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBValue___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBValue___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "vrate_inertial"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBValue___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBValue___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBValue___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "track"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBValue___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBValue___closed__3_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBValue___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "track_rate"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBValue___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBValue___closed__4_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBValue___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "temperature"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBValue___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBValue___closed__5_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBValue___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "selected_mcp"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBValue___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBValue___closed__6_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBValue___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "selected_fms"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBValue___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBValue___closed__7_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBValue___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "dte"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBValue___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBValue___closed__8_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBValue(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBValue___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint32_t lp_lean1090_Lean1090_Impl_cbCharacter(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCharacter___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbCallsign_spec__0(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbCallsign___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbCallsign___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCallsign(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCallsign___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbThreat(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbThreat___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatBearing(lean_object*);
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(3) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__0_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__1_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbDashPlaceholder(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDashPlaceholder___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__1(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistrationCodes(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistrationCodes___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistration(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistration___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0___boxed(lean_object*, lean_object*);
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbValid17___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(22) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbValid17___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__0_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbValid17___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(21) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__0_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbValid17___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__1_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbValid17___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(20) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__1_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbValid17___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__2_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbValid17___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(15) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__2_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbValid17___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__3_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbValid17___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(12) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__3_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbValid17___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__4_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbValid17___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(11) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__4_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbValid17___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__5_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbValid17___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(10) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__5_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbValid17___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbValid17___closed__6_value;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid17(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid17___boxed(lean_object*);
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__0 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__0_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(6) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__0_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__1 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__1_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(7) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__1_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__2 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__2_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(8) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__2_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__3 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__3_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(9) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__3_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__4 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__4_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(10) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__4_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__5 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__5_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(11) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__5_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__6 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__6_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(15) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__6_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__7 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__7_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(16) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__7_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__8 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__8_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(23) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__8_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__9 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__9_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(24) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__9_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__10 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__10_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(25) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__10_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__11 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__11_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(26) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__11_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__12 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__12_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(27) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__12_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__13 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__13_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(28) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__13_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__14 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__14_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(29) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__14_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__15 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__15_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(30) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__15_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__16 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__16_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(31) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__16_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__17 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__17_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(32) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__17_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__18 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__18_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(33) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__18_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__19 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__19_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(48) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__19_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__20 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__20_value;
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbValid18___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbValid18___closed__0;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbValid18___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(23) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbValid18___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbValid18___closed__1_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbValid18___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(24) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_cbValid18___closed__1_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbValid18___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbValid18___closed__2_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbValid18___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(25) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_cbValid18___closed__2_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbValid18___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbValid18___closed__3_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_cbValid18___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(32) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_cbValid18___closed__3_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_cbValid18___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbValid18___closed__4_value;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid18(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid18___boxed(lean_object*);
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(64) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__0 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__0_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(68) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__0_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__1 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__1_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(69) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__1_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__2 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__2_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(80) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__2_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__3 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__3_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(81) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__3_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__4 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__4_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(82) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__4_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__5 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__5_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(83) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__5_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__6 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__6_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(95) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__6_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__7 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__7_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(96) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__7_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__8 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__8_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(97) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__8_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__9 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__9_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(98) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__9_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__10 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__10_value;
static const lean_ctor_object lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(101) << 1) | 1)),((lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__10_value)}};
static const lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__11 = (const lean_object*)&lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__11_value;
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid19(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid19___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbValid21_spec__0(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid21(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid21___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbValid40___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbValid40___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbValid40___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbValid40___closed__1;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid40(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid40___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbValid44___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbValid44___closed__0;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid44(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid44___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid45(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid45___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbValid50___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbValid50___closed__0;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid50(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid50___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbValid60___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbValid60___closed__0;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid60(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid60___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_bdsWireValid(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsWireValid___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_bdsLayout___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_bdsLayout___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsLayout(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsLayout___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeBDS(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeBDS___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbGaussian___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbGaussian___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbGaussian___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbGaussian___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbGaussian___closed__2;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGaussian(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbLaplace(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScoreField(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__9(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__0_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "static_temperature"};
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "static_pressure"};
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__3_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__4_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7;
static const lean_string_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "wind_speed"};
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__8_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "pressure"};
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__9 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__9_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__10 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__10_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__11 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__11_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__12 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__12_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "IAS"};
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Mach"};
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__15 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__15_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__16 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__16_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__17 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__17_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__9, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__18 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__18_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "roll"};
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "TAS"};
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__20 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__20_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "groundspeed"};
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__21 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__21_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__22 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__22_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__23 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__23_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "barometric_setting"};
static const lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__24 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__24_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_cbDensity_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensity(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensity___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbPenalty___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbPenalty___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbPenalty___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbPenalty___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbPenalty___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbPenalty___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbPenalty___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbPenalty___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbPenalty___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbPenalty___closed__4;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbPenalty___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbPenalty___closed__5;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPenalty(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPenalty___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCombinedScore(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCombinedScore___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHScoreTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbQNHScoreTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHScoreTable;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0___boxed(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollScoreTable;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRateScoreTable;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTASScoreTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbTASScoreTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTASScoreTable;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbIASScoreTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbIASScoreTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbIASScoreTable;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachScoreTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbMachScoreTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachScoreTable;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalScoreTable;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindScoreTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbWindScoreTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindScoreTable;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPressureScoreTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbPressureScoreTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPressureScoreTable;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTermsFast(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTermsFast___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScorePasses___boxed(lean_object*, lean_object*);
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(96) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__0_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(80) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__0_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__1_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(69) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__1_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__2_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(68) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__2_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__3_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(64) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__3_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__4_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(48) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__4_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__5_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(33) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__5_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__6_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(32) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__6_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__7_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(25) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__7_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__8_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(24) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__8_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__9 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__9_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(23) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__9_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__10 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__10_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(16) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__10_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__11 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__11_value;
LEAN_EXPORT const lean_object* lp_lean1090_Lean1090_Impl_commBCoreRegisters = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__11_value;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBCoreEligible(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBCoreEligible___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBPositionEligible(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBPositionEligible___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg();
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBOperationEligible(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBOperationEligible___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBEligible(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBEligible___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBRegisters___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__11_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBRegisters___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBRegisters___closed__0_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_commBRegisters___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(101) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_commBRegisters___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBRegisters___closed__1_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_commBRegisters___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_commBRegisters___closed__2;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBRegisters;
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_lean1090_Lean1090_Impl_inferCommB___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_lean1090_Lean1090_Impl_inferCommB___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_inferCommB___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_inferCommB(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_inferCommB___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbStatus(lean_object* v_word_1_, lean_object* v_status_2_, lean_object* v_start_3_, lean_object* v_width_4_){
_start:
{
lean_object* v___x_5_; lean_object* v___x_6_; uint8_t v___x_7_; 
v___x_5_ = lean_unsigned_to_nat(1u);
v___x_6_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1_, v_status_2_, v___x_5_);
v___x_7_ = lean_nat_dec_eq(v___x_6_, v___x_5_);
lean_dec(v___x_6_);
if (v___x_7_ == 0)
{
lean_object* v___x_8_; lean_object* v___x_9_; uint8_t v___x_10_; 
v___x_8_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1_, v_start_3_, v_width_4_);
v___x_9_ = lean_unsigned_to_nat(0u);
v___x_10_ = lean_nat_dec_eq(v___x_8_, v___x_9_);
lean_dec(v___x_8_);
return v___x_10_;
}
else
{
return v___x_7_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbStatus___boxed(lean_object* v_word_11_, lean_object* v_status_12_, lean_object* v_start_13_, lean_object* v_width_14_){
_start:
{
uint8_t v_res_15_; lean_object* v_r_16_; 
v_res_15_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_11_, v_status_12_, v_start_13_, v_width_14_);
lean_dec(v_width_14_);
lean_dec(v_start_13_);
lean_dec(v_status_12_);
lean_dec(v_word_11_);
v_r_16_ = lean_box(v_res_15_);
return v_r_16_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSigned(lean_object* v_word_17_, lean_object* v_start_18_, lean_object* v_width_19_){
_start:
{
uint8_t v___x_20_; lean_object* v___x_21_; lean_object* v___x_22_; lean_object* v___x_23_; 
v___x_20_ = 1;
v___x_21_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_17_, v_start_18_, v_width_19_);
v___x_22_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_20_, v_width_19_, v___x_21_);
v___x_23_ = l_Rat_ofInt(v___x_22_);
return v___x_23_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSigned___boxed(lean_object* v_word_24_, lean_object* v_start_25_, lean_object* v_width_26_){
_start:
{
lean_object* v_res_27_; 
v_res_27_ = lp_lean1090_Lean1090_Impl_cbSigned(v_word_24_, v_start_25_, v_width_26_);
lean_dec(v_width_26_);
lean_dec(v_start_25_);
lean_dec(v_word_24_);
return v_res_27_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelected(lean_object* v_code_28_){
_start:
{
lean_object* v___x_29_; lean_object* v___x_30_; lean_object* v___x_31_; lean_object* v___x_32_; lean_object* v___x_33_; lean_object* v___x_34_; lean_object* v___x_35_; lean_object* v___x_36_; 
v___x_29_ = lean_unsigned_to_nat(16u);
v___x_30_ = lean_nat_mul(v_code_28_, v___x_29_);
v___x_31_ = lean_unsigned_to_nat(8u);
v___x_32_ = lean_nat_add(v___x_30_, v___x_31_);
lean_dec(v___x_30_);
v___x_33_ = lean_unsigned_to_nat(100u);
v___x_34_ = lean_nat_div(v___x_32_, v___x_33_);
lean_dec(v___x_32_);
v___x_35_ = lean_nat_mul(v___x_34_, v___x_33_);
lean_dec(v___x_34_);
v___x_36_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_35_);
return v___x_36_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelected___boxed(lean_object* v_code_37_){
_start:
{
lean_object* v_res_38_; 
v_res_38_ = lp_lean1090_Lean1090_Impl_cbSelected(v_code_37_);
lean_dec(v_code_37_);
return v_res_38_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0(void){
_start:
{
lean_object* v___x_39_; lean_object* v___x_40_; 
v___x_39_ = lean_unsigned_to_nat(4u);
v___x_40_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_39_);
return v___x_40_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__1(void){
_start:
{
lean_object* v___x_41_; lean_object* v___x_42_; 
v___x_41_ = lean_unsigned_to_nat(80u);
v___x_42_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_41_);
return v___x_42_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2(void){
_start:
{
lean_object* v___x_43_; lean_object* v___x_44_; 
v___x_43_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__1, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__1);
v___x_44_ = l_Rat_neg(v___x_43_);
return v___x_44_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3(void){
_start:
{
lean_object* v___x_45_; lean_object* v___x_46_; 
v___x_45_ = lean_unsigned_to_nat(256u);
v___x_46_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_45_);
return v___x_46_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44(lean_object* v_word_47_){
_start:
{
lean_object* v___x_48_; lean_object* v___x_49_; lean_object* v___x_50_; lean_object* v___x_51_; lean_object* v_initial_52_; lean_object* v___x_53_; uint8_t v___x_54_; 
v___x_48_ = lean_unsigned_to_nat(24u);
v___x_49_ = lean_unsigned_to_nat(11u);
v___x_50_ = lp_lean1090_Lean1090_Impl_cbSigned(v_word_47_, v___x_48_, v___x_49_);
v___x_51_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v_initial_52_ = l_Rat_div(v___x_50_, v___x_51_);
lean_dec_ref(v___x_50_);
v___x_53_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
lean_inc_ref(v_initial_52_);
v___x_54_ = l_Rat_blt(v_initial_52_, v___x_53_);
if (v___x_54_ == 0)
{
return v_initial_52_;
}
else
{
lean_object* v___x_55_; lean_object* v___x_56_; 
v___x_55_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_56_ = l_Rat_add(v_initial_52_, v___x_55_);
return v___x_56_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44___boxed(lean_object* v_word_57_){
_start:
{
lean_object* v_res_58_; 
v_res_58_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_57_);
lean_dec(v_word_57_);
return v_res_58_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__0(void){
_start:
{
lean_object* v___x_59_; lean_object* v___x_60_; 
v___x_59_ = lean_unsigned_to_nat(32u);
v___x_60_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_59_);
return v___x_60_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1(void){
_start:
{
lean_object* v___x_61_; lean_object* v___x_62_; 
v___x_61_ = lean_unsigned_to_nat(0u);
v___x_62_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_61_);
return v___x_62_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVertical60(lean_object* v_word_63_, lean_object* v_start_64_){
_start:
{
lean_object* v___x_65_; lean_object* v___x_66_; lean_object* v___x_67_; lean_object* v_magnitude_68_; lean_object* v___x_69_; uint8_t v___x_70_; 
v___x_65_ = lean_unsigned_to_nat(1u);
v___x_66_ = lean_nat_add(v_start_64_, v___x_65_);
v___x_67_ = lean_unsigned_to_nat(9u);
v_magnitude_68_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_63_, v___x_66_, v___x_67_);
lean_dec(v___x_66_);
v___x_69_ = lean_unsigned_to_nat(0u);
v___x_70_ = lean_nat_dec_eq(v_magnitude_68_, v___x_69_);
if (v___x_70_ == 0)
{
lean_object* v___x_71_; uint8_t v___x_72_; 
v___x_71_ = lean_unsigned_to_nat(511u);
v___x_72_ = lean_nat_dec_eq(v_magnitude_68_, v___x_71_);
lean_dec(v_magnitude_68_);
if (v___x_72_ == 0)
{
lean_object* v___x_73_; lean_object* v___x_74_; lean_object* v___x_75_; lean_object* v___x_76_; 
v___x_73_ = lean_unsigned_to_nat(10u);
v___x_74_ = lp_lean1090_Lean1090_Impl_cbSigned(v_word_63_, v_start_64_, v___x_73_);
v___x_75_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__0, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__0);
v___x_76_ = l_Rat_mul(v___x_74_, v___x_75_);
lean_dec_ref(v___x_74_);
return v___x_76_;
}
else
{
lean_object* v___x_77_; 
v___x_77_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_77_;
}
}
else
{
lean_object* v___x_78_; 
lean_dec(v_magnitude_68_);
v___x_78_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_78_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVertical60___boxed(lean_object* v_word_79_, lean_object* v_start_80_){
_start:
{
lean_object* v_res_81_; 
v_res_81_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_79_, v_start_80_);
lean_dec(v_start_80_);
lean_dec(v_word_79_);
return v_res_81_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__0(void){
_start:
{
lean_object* v___x_82_; lean_object* v___x_83_; 
v___x_82_ = lean_unsigned_to_nat(1u);
v___x_83_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_82_);
return v___x_83_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1(void){
_start:
{
lean_object* v___x_84_; lean_object* v___x_85_; 
v___x_84_ = lean_unsigned_to_nat(10u);
v___x_85_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_84_);
return v___x_85_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__2(void){
_start:
{
lean_object* v___x_86_; lean_object* v___x_87_; lean_object* v___x_88_; 
v___x_86_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_87_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__0, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__0);
v___x_88_ = l_Rat_div(v___x_87_, v___x_86_);
return v___x_88_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__3(void){
_start:
{
lean_object* v___x_89_; lean_object* v___x_90_; 
v___x_89_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__2, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__2);
v___x_90_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_89_);
return v___x_90_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__4(void){
_start:
{
lean_object* v___x_91_; lean_object* v___x_92_; 
v___x_91_ = lean_unsigned_to_nat(800u);
v___x_92_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_91_);
return v___x_92_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNH64(lean_object* v_word_93_){
_start:
{
lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; lean_object* v___x_99_; lean_object* v___x_100_; lean_object* v___x_101_; 
v___x_94_ = lean_unsigned_to_nat(28u);
v___x_95_ = lean_unsigned_to_nat(12u);
v___x_96_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_93_, v___x_94_, v___x_95_);
v___x_97_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_96_);
v___x_98_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__3, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__3);
v___x_99_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_97_, v___x_98_);
lean_dec_ref(v___x_97_);
v___x_100_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__4, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__4);
v___x_101_ = lp_lean1090_Lean1090_Impl_Binary64_add(v___x_99_, v___x_100_);
return v___x_101_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNH64___boxed(lean_object* v_word_102_){
_start:
{
lean_object* v_res_103_; 
v_res_103_ = lp_lean1090_Lean1090_Impl_cbQNH64(v_word_102_);
lean_dec(v_word_102_);
return v_res_103_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_104_; lean_object* v___x_105_; 
v___x_104_ = lean_unsigned_to_nat(125u);
v___x_105_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_104_);
return v___x_105_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__1(void){
_start:
{
lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_108_; 
v___x_106_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__0);
v___x_107_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_108_ = l_Rat_div(v___x_107_, v___x_106_);
return v___x_108_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2(void){
_start:
{
lean_object* v___x_109_; lean_object* v___x_110_; 
v___x_109_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__1);
v___x_110_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_109_);
return v___x_110_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3(void){
_start:
{
lean_object* v___x_111_; lean_object* v___x_112_; 
v___x_111_ = lean_unsigned_to_nat(512u);
v___x_112_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_111_);
return v___x_112_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0(lean_object* v_code_113_){
_start:
{
lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v___x_116_; lean_object* v___x_117_; lean_object* v___x_118_; 
v___x_114_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_113_);
v___x_115_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2);
v___x_116_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_114_, v___x_115_);
lean_dec_ref(v___x_114_);
v___x_117_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3);
v___x_118_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_116_, v___x_117_);
lean_dec_ref(v___x_116_);
return v___x_118_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__1(void){
_start:
{
lean_object* v___f_120_; lean_object* v___x_121_; lean_object* v___x_122_; 
v___f_120_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__0));
v___x_121_ = lean_unsigned_to_nat(1024u);
v___x_122_ = l_Array_ofFn___redArg(v___x_121_, v___f_120_);
return v___x_122_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValueTable(void){
_start:
{
lean_object* v___x_123_; 
v___x_123_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__1, &lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__1);
return v___x_123_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMach64(lean_object* v_word_124_){
_start:
{
lean_object* v___x_125_; lean_object* v___x_126_; lean_object* v___x_127_; lean_object* v___x_128_; lean_object* v___x_129_; 
v___x_125_ = lp_lean1090_Lean1090_Impl_cbMachValueTable;
v___x_126_ = lean_unsigned_to_nat(25u);
v___x_127_ = lean_unsigned_to_nat(10u);
v___x_128_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_124_, v___x_126_, v___x_127_);
v___x_129_ = lean_array_fget_borrowed(v___x_125_, v___x_128_);
lean_dec(v___x_128_);
lean_inc(v___x_129_);
return v___x_129_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMach64___boxed(lean_object* v_word_130_){
_start:
{
lean_object* v_res_131_; 
v_res_131_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_130_);
lean_dec(v_word_130_);
return v_res_131_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0(void){
_start:
{
lean_object* v___x_132_; lean_object* v___x_133_; 
v___x_132_ = lean_unsigned_to_nat(360u);
v___x_133_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_132_);
return v___x_133_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWrapAngle(lean_object* v_value_134_){
_start:
{
lean_object* v___x_135_; uint8_t v___x_136_; 
v___x_135_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_value_134_);
v___x_136_ = l_Rat_blt(v_value_134_, v___x_135_);
if (v___x_136_ == 0)
{
return v_value_134_;
}
else
{
lean_object* v___x_137_; lean_object* v___x_138_; 
v___x_137_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0, &lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0);
v___x_138_ = l_Rat_add(v_value_134_, v___x_137_);
return v___x_138_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(lean_object* v_name_139_, lean_object* v_x_140_){
_start:
{
if (lean_obj_tag(v_x_140_) == 0)
{
lean_object* v___x_141_; 
v___x_141_ = lean_box(0);
return v___x_141_;
}
else
{
lean_object* v_head_142_; lean_object* v_tail_143_; lean_object* v_name_144_; uint8_t v___x_145_; 
v_head_142_ = lean_ctor_get(v_x_140_, 0);
v_tail_143_ = lean_ctor_get(v_x_140_, 1);
v_name_144_ = lean_ctor_get(v_head_142_, 0);
v___x_145_ = lean_string_dec_eq(v_name_144_, v_name_139_);
if (v___x_145_ == 0)
{
v_x_140_ = v_tail_143_;
goto _start;
}
else
{
lean_object* v___x_147_; 
lean_inc(v_head_142_);
v___x_147_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_147_, 0, v_head_142_);
return v___x_147_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0___boxed(lean_object* v_name_148_, lean_object* v_x_149_){
_start:
{
lean_object* v_res_150_; 
v_res_150_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(v_name_148_, v_x_149_);
lean_dec(v_x_149_);
lean_dec_ref(v_name_148_);
return v_res_150_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBValue(lean_object* v_register_160_, lean_object* v_word_161_, lean_object* v_name_162_){
_start:
{
lean_object* v___x_163_; 
v___x_163_ = lp_lean1090_Lean1090_Impl_commBLayout(v_register_160_);
if (lean_obj_tag(v___x_163_) == 0)
{
lean_object* v___x_164_; 
v___x_164_ = lean_box(0);
return v___x_164_;
}
else
{
lean_object* v_val_165_; lean_object* v___x_166_; 
v_val_165_ = lean_ctor_get(v___x_163_, 0);
lean_inc(v_val_165_);
lean_dec_ref_known(v___x_163_, 1);
v___x_166_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(v_name_162_, v_val_165_);
lean_dec(v_val_165_);
if (lean_obj_tag(v___x_166_) == 0)
{
lean_object* v___x_167_; 
v___x_167_ = lean_box(0);
return v___x_167_;
}
else
{
lean_object* v_val_168_; lean_object* v___x_170_; uint8_t v_isShared_171_; uint8_t v_isSharedCheck_284_; 
v_val_168_ = lean_ctor_get(v___x_166_, 0);
v_isSharedCheck_284_ = !lean_is_exclusive(v___x_166_);
if (v_isSharedCheck_284_ == 0)
{
v___x_170_ = v___x_166_;
v_isShared_171_ = v_isSharedCheck_284_;
goto v_resetjp_169_;
}
else
{
lean_inc(v_val_168_);
lean_dec(v___x_166_);
v___x_170_ = lean_box(0);
v_isShared_171_ = v_isSharedCheck_284_;
goto v_resetjp_169_;
}
v_resetjp_169_:
{
lean_object* v___x_172_; 
v___x_172_ = lp_lean1090_Lean1090_Impl_payloadValue(v_val_168_, v_word_161_);
if (lean_obj_tag(v___x_172_) == 0)
{
lean_del_object(v___x_170_);
return v___x_172_;
}
else
{
lean_object* v_val_173_; lean_object* v___x_179_; uint8_t v___x_180_; 
v_val_173_ = lean_ctor_get(v___x_172_, 0);
lean_inc(v_val_173_);
v___x_179_ = lean_unsigned_to_nat(16u);
v___x_180_ = lean_nat_dec_eq(v_register_160_, v___x_179_);
if (v___x_180_ == 0)
{
lean_object* v___x_181_; uint8_t v___x_182_; 
v___x_181_ = lean_unsigned_to_nat(64u);
v___x_182_ = lean_nat_dec_eq(v_register_160_, v___x_181_);
if (v___x_182_ == 0)
{
lean_object* v___x_183_; uint8_t v___x_184_; 
v___x_183_ = lean_unsigned_to_nat(68u);
v___x_184_ = lean_nat_dec_eq(v_register_160_, v___x_183_);
if (v___x_184_ == 0)
{
lean_object* v___x_185_; uint8_t v___x_186_; 
v___x_185_ = lean_unsigned_to_nat(80u);
v___x_186_ = lean_nat_dec_eq(v_register_160_, v___x_185_);
if (v___x_186_ == 0)
{
lean_object* v___x_187_; uint8_t v___x_188_; 
v___x_187_ = lean_unsigned_to_nat(96u);
v___x_188_ = lean_nat_dec_eq(v_register_160_, v___x_187_);
if (v___x_188_ == 0)
{
lean_dec(v_val_173_);
lean_del_object(v___x_170_);
return v___x_172_;
}
else
{
lean_object* v___x_189_; uint8_t v___x_190_; 
v___x_189_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__0));
v___x_190_ = lean_string_dec_eq(v_name_162_, v___x_189_);
if (v___x_190_ == 0)
{
lean_object* v___x_191_; uint8_t v___x_192_; 
lean_dec(v_val_173_);
lean_del_object(v___x_170_);
v___x_191_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__1));
v___x_192_ = lean_string_dec_eq(v_name_162_, v___x_191_);
if (v___x_192_ == 0)
{
lean_object* v___x_193_; uint8_t v___x_194_; 
v___x_193_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__2));
v___x_194_ = lean_string_dec_eq(v_name_162_, v___x_193_);
if (v___x_194_ == 0)
{
return v___x_172_;
}
else
{
lean_object* v___x_196_; uint8_t v_isShared_197_; uint8_t v_isSharedCheck_203_; 
v_isSharedCheck_203_ = !lean_is_exclusive(v___x_172_);
if (v_isSharedCheck_203_ == 0)
{
lean_object* v_unused_204_; 
v_unused_204_ = lean_ctor_get(v___x_172_, 0);
lean_dec(v_unused_204_);
v___x_196_ = v___x_172_;
v_isShared_197_ = v_isSharedCheck_203_;
goto v_resetjp_195_;
}
else
{
lean_dec(v___x_172_);
v___x_196_ = lean_box(0);
v_isShared_197_ = v_isSharedCheck_203_;
goto v_resetjp_195_;
}
v_resetjp_195_:
{
lean_object* v___x_198_; lean_object* v___x_199_; lean_object* v___x_201_; 
v___x_198_ = lean_unsigned_to_nat(47u);
v___x_199_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_161_, v___x_198_);
if (v_isShared_197_ == 0)
{
lean_ctor_set(v___x_196_, 0, v___x_199_);
v___x_201_ = v___x_196_;
goto v_reusejp_200_;
}
else
{
lean_object* v_reuseFailAlloc_202_; 
v_reuseFailAlloc_202_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_202_, 0, v___x_199_);
v___x_201_ = v_reuseFailAlloc_202_;
goto v_reusejp_200_;
}
v_reusejp_200_:
{
return v___x_201_;
}
}
}
}
else
{
lean_object* v___x_206_; uint8_t v_isShared_207_; uint8_t v_isSharedCheck_213_; 
v_isSharedCheck_213_ = !lean_is_exclusive(v___x_172_);
if (v_isSharedCheck_213_ == 0)
{
lean_object* v_unused_214_; 
v_unused_214_ = lean_ctor_get(v___x_172_, 0);
lean_dec(v_unused_214_);
v___x_206_ = v___x_172_;
v_isShared_207_ = v_isSharedCheck_213_;
goto v_resetjp_205_;
}
else
{
lean_dec(v___x_172_);
v___x_206_ = lean_box(0);
v_isShared_207_ = v_isSharedCheck_213_;
goto v_resetjp_205_;
}
v_resetjp_205_:
{
lean_object* v___x_208_; lean_object* v___x_209_; lean_object* v___x_211_; 
v___x_208_ = lean_unsigned_to_nat(36u);
v___x_209_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_161_, v___x_208_);
if (v_isShared_207_ == 0)
{
lean_ctor_set(v___x_206_, 0, v___x_209_);
v___x_211_ = v___x_206_;
goto v_reusejp_210_;
}
else
{
lean_object* v_reuseFailAlloc_212_; 
v_reuseFailAlloc_212_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_212_, 0, v___x_209_);
v___x_211_ = v_reuseFailAlloc_212_;
goto v_reusejp_210_;
}
v_reusejp_210_:
{
return v___x_211_;
}
}
}
}
else
{
lean_dec_ref_known(v___x_172_, 1);
goto v___jp_174_;
}
}
}
else
{
lean_object* v___x_215_; uint8_t v___x_216_; 
v___x_215_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__3));
v___x_216_ = lean_string_dec_eq(v_name_162_, v___x_215_);
if (v___x_216_ == 0)
{
lean_object* v___x_217_; uint8_t v___x_218_; 
lean_dec(v_val_173_);
lean_del_object(v___x_170_);
v___x_217_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__4));
v___x_218_ = lean_string_dec_eq(v_name_162_, v___x_217_);
if (v___x_218_ == 0)
{
return v___x_172_;
}
else
{
lean_object* v___x_219_; lean_object* v___x_220_; lean_object* v___x_221_; lean_object* v___x_222_; uint8_t v___x_223_; 
v___x_219_ = lean_unsigned_to_nat(37u);
v___x_220_ = lean_unsigned_to_nat(9u);
v___x_221_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_161_, v___x_219_, v___x_220_);
v___x_222_ = lean_unsigned_to_nat(511u);
v___x_223_ = lean_nat_dec_eq(v___x_221_, v___x_222_);
lean_dec(v___x_221_);
if (v___x_223_ == 0)
{
return v___x_172_;
}
else
{
lean_object* v___x_224_; 
lean_dec_ref_known(v___x_172_, 1);
v___x_224_ = lean_box(0);
return v___x_224_;
}
}
}
else
{
lean_dec_ref_known(v___x_172_, 1);
goto v___jp_174_;
}
}
}
else
{
lean_object* v___x_225_; uint8_t v___x_226_; 
lean_dec(v_val_173_);
lean_del_object(v___x_170_);
v___x_225_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__5));
v___x_226_ = lean_string_dec_eq(v_name_162_, v___x_225_);
if (v___x_226_ == 0)
{
return v___x_172_;
}
else
{
lean_object* v___x_228_; uint8_t v_isShared_229_; uint8_t v_isSharedCheck_234_; 
v_isSharedCheck_234_ = !lean_is_exclusive(v___x_172_);
if (v_isSharedCheck_234_ == 0)
{
lean_object* v_unused_235_; 
v_unused_235_ = lean_ctor_get(v___x_172_, 0);
lean_dec(v_unused_235_);
v___x_228_ = v___x_172_;
v_isShared_229_ = v_isSharedCheck_234_;
goto v_resetjp_227_;
}
else
{
lean_dec(v___x_172_);
v___x_228_ = lean_box(0);
v_isShared_229_ = v_isSharedCheck_234_;
goto v_resetjp_227_;
}
v_resetjp_227_:
{
lean_object* v___x_230_; lean_object* v___x_232_; 
v___x_230_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_161_);
if (v_isShared_229_ == 0)
{
lean_ctor_set(v___x_228_, 0, v___x_230_);
v___x_232_ = v___x_228_;
goto v_reusejp_231_;
}
else
{
lean_object* v_reuseFailAlloc_233_; 
v_reuseFailAlloc_233_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_233_, 0, v___x_230_);
v___x_232_ = v_reuseFailAlloc_233_;
goto v_reusejp_231_;
}
v_reusejp_231_:
{
return v___x_232_;
}
}
}
}
}
else
{
lean_object* v___x_236_; uint8_t v___x_237_; 
lean_dec(v_val_173_);
lean_del_object(v___x_170_);
v___x_236_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__6));
v___x_237_ = lean_string_dec_eq(v_name_162_, v___x_236_);
if (v___x_237_ == 0)
{
lean_object* v___x_238_; uint8_t v___x_239_; 
v___x_238_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__7));
v___x_239_ = lean_string_dec_eq(v_name_162_, v___x_238_);
if (v___x_239_ == 0)
{
return v___x_172_;
}
else
{
lean_object* v___x_241_; uint8_t v_isShared_242_; uint8_t v_isSharedCheck_250_; 
v_isSharedCheck_250_ = !lean_is_exclusive(v___x_172_);
if (v_isSharedCheck_250_ == 0)
{
lean_object* v_unused_251_; 
v_unused_251_ = lean_ctor_get(v___x_172_, 0);
lean_dec(v_unused_251_);
v___x_241_ = v___x_172_;
v_isShared_242_ = v_isSharedCheck_250_;
goto v_resetjp_240_;
}
else
{
lean_dec(v___x_172_);
v___x_241_ = lean_box(0);
v_isShared_242_ = v_isSharedCheck_250_;
goto v_resetjp_240_;
}
v_resetjp_240_:
{
lean_object* v___x_243_; lean_object* v___x_244_; lean_object* v___x_245_; lean_object* v___x_246_; lean_object* v___x_248_; 
v___x_243_ = lean_unsigned_to_nat(15u);
v___x_244_ = lean_unsigned_to_nat(12u);
v___x_245_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_161_, v___x_243_, v___x_244_);
v___x_246_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_245_);
lean_dec(v___x_245_);
if (v_isShared_242_ == 0)
{
lean_ctor_set(v___x_241_, 0, v___x_246_);
v___x_248_ = v___x_241_;
goto v_reusejp_247_;
}
else
{
lean_object* v_reuseFailAlloc_249_; 
v_reuseFailAlloc_249_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_249_, 0, v___x_246_);
v___x_248_ = v_reuseFailAlloc_249_;
goto v_reusejp_247_;
}
v_reusejp_247_:
{
return v___x_248_;
}
}
}
}
else
{
lean_object* v___x_253_; uint8_t v_isShared_254_; uint8_t v_isSharedCheck_262_; 
v_isSharedCheck_262_ = !lean_is_exclusive(v___x_172_);
if (v_isSharedCheck_262_ == 0)
{
lean_object* v_unused_263_; 
v_unused_263_ = lean_ctor_get(v___x_172_, 0);
lean_dec(v_unused_263_);
v___x_253_ = v___x_172_;
v_isShared_254_ = v_isSharedCheck_262_;
goto v_resetjp_252_;
}
else
{
lean_dec(v___x_172_);
v___x_253_ = lean_box(0);
v_isShared_254_ = v_isSharedCheck_262_;
goto v_resetjp_252_;
}
v_resetjp_252_:
{
lean_object* v___x_255_; lean_object* v___x_256_; lean_object* v___x_257_; lean_object* v___x_258_; lean_object* v___x_260_; 
v___x_255_ = lean_unsigned_to_nat(2u);
v___x_256_ = lean_unsigned_to_nat(12u);
v___x_257_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_161_, v___x_255_, v___x_256_);
v___x_258_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_257_);
lean_dec(v___x_257_);
if (v_isShared_254_ == 0)
{
lean_ctor_set(v___x_253_, 0, v___x_258_);
v___x_260_ = v___x_253_;
goto v_reusejp_259_;
}
else
{
lean_object* v_reuseFailAlloc_261_; 
v_reuseFailAlloc_261_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_261_, 0, v___x_258_);
v___x_260_ = v_reuseFailAlloc_261_;
goto v_reusejp_259_;
}
v_reusejp_259_:
{
return v___x_260_;
}
}
}
}
}
else
{
lean_object* v___x_264_; uint8_t v___x_265_; 
lean_dec(v_val_173_);
lean_del_object(v___x_170_);
v___x_264_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__8));
v___x_265_ = lean_string_dec_eq(v_name_162_, v___x_264_);
if (v___x_265_ == 0)
{
return v___x_172_;
}
else
{
lean_object* v___x_267_; uint8_t v_isShared_268_; uint8_t v_isSharedCheck_282_; 
v_isSharedCheck_282_ = !lean_is_exclusive(v___x_172_);
if (v_isSharedCheck_282_ == 0)
{
lean_object* v_unused_283_; 
v_unused_283_ = lean_ctor_get(v___x_172_, 0);
lean_dec(v_unused_283_);
v___x_267_ = v___x_172_;
v_isShared_268_ = v_isSharedCheck_282_;
goto v_resetjp_266_;
}
else
{
lean_dec(v___x_172_);
v___x_267_ = lean_box(0);
v_isShared_268_ = v_isSharedCheck_282_;
goto v_resetjp_266_;
}
v_resetjp_266_:
{
lean_object* v___x_269_; lean_object* v___x_270_; lean_object* v___x_271_; lean_object* v___x_272_; lean_object* v___x_273_; lean_object* v___x_274_; lean_object* v___x_275_; lean_object* v___x_276_; lean_object* v___x_277_; lean_object* v___x_278_; lean_object* v___x_280_; 
v___x_269_ = lean_unsigned_to_nat(41u);
v___x_270_ = lean_unsigned_to_nat(8u);
v___x_271_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_161_, v___x_269_, v___x_270_);
v___x_272_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_271_);
v___x_273_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_274_ = lean_unsigned_to_nat(49u);
v___x_275_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_161_, v___x_274_, v___x_270_);
v___x_276_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_275_);
v___x_277_ = l_Rat_mul(v___x_273_, v___x_276_);
v___x_278_ = l_Rat_add(v___x_272_, v___x_277_);
if (v_isShared_268_ == 0)
{
lean_ctor_set(v___x_267_, 0, v___x_278_);
v___x_280_ = v___x_267_;
goto v_reusejp_279_;
}
else
{
lean_object* v_reuseFailAlloc_281_; 
v_reuseFailAlloc_281_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_281_, 0, v___x_278_);
v___x_280_ = v_reuseFailAlloc_281_;
goto v_reusejp_279_;
}
v_reusejp_279_:
{
return v___x_280_;
}
}
}
}
v___jp_174_:
{
lean_object* v___x_175_; lean_object* v___x_177_; 
v___x_175_ = lp_lean1090_Lean1090_Impl_cbWrapAngle(v_val_173_);
if (v_isShared_171_ == 0)
{
lean_ctor_set(v___x_170_, 0, v___x_175_);
v___x_177_ = v___x_170_;
goto v_reusejp_176_;
}
else
{
lean_object* v_reuseFailAlloc_178_; 
v_reuseFailAlloc_178_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_178_, 0, v___x_175_);
v___x_177_ = v_reuseFailAlloc_178_;
goto v_reusejp_176_;
}
v_reusejp_176_:
{
return v___x_177_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBValue___boxed(lean_object* v_register_285_, lean_object* v_word_286_, lean_object* v_name_287_){
_start:
{
lean_object* v_res_288_; 
v_res_288_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_285_, v_word_286_, v_name_287_);
lean_dec_ref(v_name_287_);
lean_dec(v_word_286_);
lean_dec(v_register_285_);
return v_res_288_;
}
}
LEAN_EXPORT uint32_t lp_lean1090_Lean1090_Impl_cbCharacter(lean_object* v_code_289_){
_start:
{
lean_object* v___x_301_; uint8_t v___x_302_; 
v___x_301_ = lean_unsigned_to_nat(1u);
v___x_302_ = lean_nat_dec_le(v___x_301_, v_code_289_);
if (v___x_302_ == 0)
{
goto v___jp_295_;
}
else
{
lean_object* v___x_303_; uint8_t v___x_304_; 
v___x_303_ = lean_unsigned_to_nat(26u);
v___x_304_ = lean_nat_dec_le(v_code_289_, v___x_303_);
if (v___x_304_ == 0)
{
goto v___jp_295_;
}
else
{
lean_object* v___x_305_; lean_object* v___x_306_; uint32_t v___x_307_; 
v___x_305_ = lean_unsigned_to_nat(64u);
v___x_306_ = lean_nat_add(v___x_305_, v_code_289_);
v___x_307_ = l_Char_ofNat(v___x_306_);
lean_dec(v___x_306_);
return v___x_307_;
}
}
v___jp_290_:
{
lean_object* v___x_291_; uint8_t v___x_292_; 
v___x_291_ = lean_unsigned_to_nat(32u);
v___x_292_ = lean_nat_dec_eq(v_code_289_, v___x_291_);
if (v___x_292_ == 0)
{
uint32_t v___x_293_; 
v___x_293_ = 35;
return v___x_293_;
}
else
{
uint32_t v___x_294_; 
v___x_294_ = 32;
return v___x_294_;
}
}
v___jp_295_:
{
lean_object* v___x_296_; uint8_t v___x_297_; 
v___x_296_ = lean_unsigned_to_nat(48u);
v___x_297_ = lean_nat_dec_le(v___x_296_, v_code_289_);
if (v___x_297_ == 0)
{
goto v___jp_290_;
}
else
{
lean_object* v___x_298_; uint8_t v___x_299_; 
v___x_298_ = lean_unsigned_to_nat(57u);
v___x_299_ = lean_nat_dec_le(v_code_289_, v___x_298_);
if (v___x_299_ == 0)
{
goto v___jp_290_;
}
else
{
uint32_t v___x_300_; 
v___x_300_ = l_Char_ofNat(v_code_289_);
return v___x_300_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCharacter___boxed(lean_object* v_code_308_){
_start:
{
uint32_t v_res_309_; lean_object* v_r_310_; 
v_res_309_ = lp_lean1090_Lean1090_Impl_cbCharacter(v_code_308_);
lean_dec(v_code_308_);
v_r_310_ = lean_box_uint32(v_res_309_);
return v_r_310_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(lean_object* v_a_311_, lean_object* v_a_312_){
_start:
{
if (lean_obj_tag(v_a_311_) == 0)
{
lean_object* v___x_313_; 
v___x_313_ = l_List_reverse___redArg(v_a_312_);
return v___x_313_;
}
else
{
lean_object* v_head_314_; lean_object* v_tail_315_; lean_object* v___x_317_; uint8_t v_isShared_318_; uint8_t v_isSharedCheck_325_; 
v_head_314_ = lean_ctor_get(v_a_311_, 0);
v_tail_315_ = lean_ctor_get(v_a_311_, 1);
v_isSharedCheck_325_ = !lean_is_exclusive(v_a_311_);
if (v_isSharedCheck_325_ == 0)
{
v___x_317_ = v_a_311_;
v_isShared_318_ = v_isSharedCheck_325_;
goto v_resetjp_316_;
}
else
{
lean_inc(v_tail_315_);
lean_inc(v_head_314_);
lean_dec(v_a_311_);
v___x_317_ = lean_box(0);
v_isShared_318_ = v_isSharedCheck_325_;
goto v_resetjp_316_;
}
v_resetjp_316_:
{
uint32_t v___x_319_; lean_object* v___x_320_; lean_object* v___x_322_; 
v___x_319_ = lp_lean1090_Lean1090_Impl_cbCharacter(v_head_314_);
lean_dec(v_head_314_);
v___x_320_ = lean_box_uint32(v___x_319_);
if (v_isShared_318_ == 0)
{
lean_ctor_set(v___x_317_, 1, v_a_312_);
lean_ctor_set(v___x_317_, 0, v___x_320_);
v___x_322_ = v___x_317_;
goto v_reusejp_321_;
}
else
{
lean_object* v_reuseFailAlloc_324_; 
v_reuseFailAlloc_324_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_324_, 0, v___x_320_);
lean_ctor_set(v_reuseFailAlloc_324_, 1, v_a_312_);
v___x_322_ = v_reuseFailAlloc_324_;
goto v_reusejp_321_;
}
v_reusejp_321_:
{
v_a_311_ = v_tail_315_;
v_a_312_ = v___x_322_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbCallsign_spec__0(lean_object* v_a_326_, lean_object* v_a_327_){
_start:
{
if (lean_obj_tag(v_a_326_) == 0)
{
lean_object* v___x_328_; 
v___x_328_ = l_List_reverse___redArg(v_a_327_);
return v___x_328_;
}
else
{
lean_object* v_head_329_; lean_object* v_tail_330_; lean_object* v___x_332_; uint8_t v_isShared_333_; uint8_t v_isSharedCheck_341_; 
v_head_329_ = lean_ctor_get(v_a_326_, 0);
v_tail_330_ = lean_ctor_get(v_a_326_, 1);
v_isSharedCheck_341_ = !lean_is_exclusive(v_a_326_);
if (v_isSharedCheck_341_ == 0)
{
v___x_332_ = v_a_326_;
v_isShared_333_ = v_isSharedCheck_341_;
goto v_resetjp_331_;
}
else
{
lean_inc(v_tail_330_);
lean_inc(v_head_329_);
lean_dec(v_a_326_);
v___x_332_ = lean_box(0);
v_isShared_333_ = v_isSharedCheck_341_;
goto v_resetjp_331_;
}
v_resetjp_331_:
{
lean_object* v___x_334_; uint8_t v___x_335_; 
v___x_334_ = lean_unsigned_to_nat(32u);
v___x_335_ = lean_nat_dec_eq(v_head_329_, v___x_334_);
if (v___x_335_ == 0)
{
lean_object* v___x_337_; 
if (v_isShared_333_ == 0)
{
lean_ctor_set(v___x_332_, 1, v_a_327_);
v___x_337_ = v___x_332_;
goto v_reusejp_336_;
}
else
{
lean_object* v_reuseFailAlloc_339_; 
v_reuseFailAlloc_339_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_339_, 0, v_head_329_);
lean_ctor_set(v_reuseFailAlloc_339_, 1, v_a_327_);
v___x_337_ = v_reuseFailAlloc_339_;
goto v_reusejp_336_;
}
v_reusejp_336_:
{
v_a_326_ = v_tail_330_;
v_a_327_ = v___x_337_;
goto _start;
}
}
else
{
lean_del_object(v___x_332_);
lean_dec(v_head_329_);
v_a_326_ = v_tail_330_;
goto _start;
}
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbCallsign___closed__0(void){
_start:
{
lean_object* v___x_342_; lean_object* v___x_343_; 
v___x_342_ = lean_unsigned_to_nat(8u);
v___x_343_ = l_List_range(v___x_342_);
return v___x_343_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCallsign(lean_object* v_word_344_){
_start:
{
lean_object* v___x_345_; lean_object* v___x_346_; lean_object* v___x_347_; lean_object* v___x_348_; lean_object* v___x_349_; lean_object* v___x_350_; 
v___x_345_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbCallsign___closed__0, &lp_lean1090_Lean1090_Impl_cbCallsign___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbCallsign___closed__0);
v___x_346_ = lean_box(0);
v___x_347_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_adsbCallsign_spec__0(v_word_344_, v___x_345_, v___x_346_);
v___x_348_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbCallsign_spec__0(v___x_347_, v___x_346_);
v___x_349_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(v___x_348_, v___x_346_);
v___x_350_ = lean_string_mk(v___x_349_);
return v___x_350_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCallsign___boxed(lean_object* v_word_351_){
_start:
{
lean_object* v_res_352_; 
v_res_352_ = lp_lean1090_Lean1090_Impl_cbCallsign(v_word_351_);
lean_dec(v_word_351_);
return v_res_352_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbThreat(lean_object* v_word_353_){
_start:
{
lean_object* v___x_354_; lean_object* v___x_355_; lean_object* v___x_356_; lean_object* v___x_357_; uint8_t v___x_358_; 
v___x_354_ = lean_unsigned_to_nat(29u);
v___x_355_ = lean_unsigned_to_nat(2u);
v___x_356_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_353_, v___x_354_, v___x_355_);
v___x_357_ = lean_unsigned_to_nat(0u);
v___x_358_ = lean_nat_dec_eq(v___x_356_, v___x_357_);
if (v___x_358_ == 0)
{
lean_object* v___x_359_; uint8_t v___x_360_; 
v___x_359_ = lean_unsigned_to_nat(1u);
v___x_360_ = lean_nat_dec_eq(v___x_356_, v___x_359_);
if (v___x_360_ == 0)
{
uint8_t v___x_361_; 
v___x_361_ = lean_nat_dec_eq(v___x_356_, v___x_355_);
lean_dec(v___x_356_);
if (v___x_361_ == 0)
{
lean_object* v___x_362_; 
v___x_362_ = lean_box(3);
return v___x_362_;
}
else
{
lean_object* v___x_363_; lean_object* v___x_364_; lean_object* v_range_365_; lean_object* v___x_366_; lean_object* v___x_367_; lean_object* v_bearing_368_; lean_object* v___x_369_; lean_object* v___x_370_; lean_object* v___x_371_; lean_object* v___x_372_; lean_object* v___y_374_; uint8_t v___x_384_; 
v___x_363_ = lean_unsigned_to_nat(44u);
v___x_364_ = lean_unsigned_to_nat(7u);
v_range_365_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_353_, v___x_363_, v___x_364_);
v___x_366_ = lean_unsigned_to_nat(51u);
v___x_367_ = lean_unsigned_to_nat(6u);
v_bearing_368_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_353_, v___x_366_, v___x_367_);
v___x_369_ = lean_unsigned_to_nat(31u);
v___x_370_ = lean_unsigned_to_nat(13u);
v___x_371_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_353_, v___x_369_, v___x_370_);
v___x_372_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v___x_371_);
lean_dec(v___x_371_);
v___x_384_ = lean_nat_dec_eq(v_range_365_, v___x_357_);
if (v___x_384_ == 0)
{
lean_object* v___x_385_; lean_object* v___x_386_; lean_object* v___x_387_; lean_object* v___x_388_; lean_object* v___x_389_; 
v___x_385_ = lean_nat_sub(v_range_365_, v___x_359_);
lean_dec(v_range_365_);
v___x_386_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_385_);
v___x_387_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_388_ = l_Rat_div(v___x_386_, v___x_387_);
lean_dec_ref(v___x_386_);
v___x_389_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_389_, 0, v___x_388_);
v___y_374_ = v___x_389_;
goto v___jp_373_;
}
else
{
lean_object* v___x_390_; 
lean_dec(v_range_365_);
v___x_390_ = lean_box(0);
v___y_374_ = v___x_390_;
goto v___jp_373_;
}
v___jp_373_:
{
uint8_t v___x_375_; 
v___x_375_ = lean_nat_dec_eq(v_bearing_368_, v___x_357_);
if (v___x_375_ == 0)
{
lean_object* v___x_376_; lean_object* v___x_377_; lean_object* v___x_378_; lean_object* v___x_379_; lean_object* v___x_380_; lean_object* v___x_381_; 
v___x_376_ = lean_nat_sub(v_bearing_368_, v___x_359_);
lean_dec(v_bearing_368_);
v___x_377_ = lean_nat_mul(v___x_367_, v___x_376_);
lean_dec(v___x_376_);
v___x_378_ = lean_unsigned_to_nat(3u);
v___x_379_ = lean_nat_add(v___x_377_, v___x_378_);
lean_dec(v___x_377_);
v___x_380_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_380_, 0, v___x_379_);
v___x_381_ = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(v___x_381_, 0, v___x_372_);
lean_ctor_set(v___x_381_, 1, v___y_374_);
lean_ctor_set(v___x_381_, 2, v___x_380_);
return v___x_381_;
}
else
{
lean_object* v___x_382_; lean_object* v___x_383_; 
lean_dec(v_bearing_368_);
v___x_382_ = lean_box(0);
v___x_383_ = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(v___x_383_, 0, v___x_372_);
lean_ctor_set(v___x_383_, 1, v___y_374_);
lean_ctor_set(v___x_383_, 2, v___x_382_);
return v___x_383_;
}
}
}
}
else
{
lean_object* v___x_391_; lean_object* v___x_392_; lean_object* v___x_393_; lean_object* v___x_394_; 
lean_dec(v___x_356_);
v___x_391_ = lean_unsigned_to_nat(31u);
v___x_392_ = lean_unsigned_to_nat(24u);
v___x_393_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_353_, v___x_391_, v___x_392_);
v___x_394_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_394_, 0, v___x_393_);
return v___x_394_;
}
}
else
{
lean_object* v___x_395_; 
lean_dec(v___x_356_);
v___x_395_ = lean_box(0);
return v___x_395_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbThreat___boxed(lean_object* v_word_396_){
_start:
{
lean_object* v_res_397_; 
v_res_397_ = lp_lean1090_Lean1090_Impl_cbThreat(v_word_396_);
lean_dec(v_word_396_);
return v_res_397_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0(void){
_start:
{
lean_object* v___x_398_; lean_object* v___x_399_; 
v___x_398_ = lean_unsigned_to_nat(20u);
v___x_399_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_398_);
return v___x_399_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1(void){
_start:
{
lean_object* v___x_400_; lean_object* v___x_401_; lean_object* v___x_402_; 
v___x_400_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0);
v___x_401_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__0, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__0);
v___x_402_ = l_Rat_div(v___x_401_, v___x_400_);
return v___x_402_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2(void){
_start:
{
lean_object* v___x_403_; lean_object* v___x_404_; 
v___x_403_ = lean_unsigned_to_nat(251u);
v___x_404_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_403_);
return v___x_404_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3(void){
_start:
{
lean_object* v___x_405_; lean_object* v___x_406_; lean_object* v___x_407_; 
v___x_405_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0);
v___x_406_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2);
v___x_407_ = l_Rat_div(v___x_406_, v___x_405_);
return v___x_407_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4(void){
_start:
{
lean_object* v___x_408_; lean_object* v___x_409_; 
v___x_408_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3);
v___x_409_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_409_, 0, v___x_408_);
return v___x_409_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5(void){
_start:
{
lean_object* v___x_410_; lean_object* v___x_411_; 
v___x_410_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1);
v___x_411_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_411_, 0, v___x_410_);
return v___x_411_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange(lean_object* v_code_412_){
_start:
{
lean_object* v___x_413_; uint8_t v___x_414_; 
v___x_413_ = lean_unsigned_to_nat(0u);
v___x_414_ = lean_nat_dec_eq(v_code_412_, v___x_413_);
if (v___x_414_ == 0)
{
lean_object* v___x_415_; uint8_t v___x_416_; 
v___x_415_ = lean_unsigned_to_nat(1u);
v___x_416_ = lean_nat_dec_eq(v_code_412_, v___x_415_);
if (v___x_416_ == 0)
{
lean_object* v___x_417_; uint8_t v___x_418_; 
v___x_417_ = lean_unsigned_to_nat(127u);
v___x_418_ = lean_nat_dec_eq(v_code_412_, v___x_417_);
if (v___x_418_ == 0)
{
lean_object* v___x_419_; lean_object* v___x_420_; lean_object* v___x_421_; lean_object* v___x_422_; lean_object* v___x_423_; lean_object* v___x_424_; 
v___x_419_ = lean_nat_sub(v_code_412_, v___x_415_);
v___x_420_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_419_);
v___x_421_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_422_ = l_Rat_div(v___x_420_, v___x_421_);
lean_dec_ref(v___x_420_);
v___x_423_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1);
v___x_424_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_424_, 0, v___x_422_);
lean_ctor_set(v___x_424_, 1, v___x_423_);
return v___x_424_;
}
else
{
lean_object* v___x_425_; 
v___x_425_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4);
return v___x_425_;
}
}
else
{
lean_object* v___x_426_; 
v___x_426_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5);
return v___x_426_;
}
}
else
{
lean_object* v___x_427_; 
v___x_427_ = lean_box(0);
return v___x_427_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange___boxed(lean_object* v_code_428_){
_start:
{
lean_object* v_res_429_; 
v_res_429_ = lp_lean1090_Lean1090_Impl_standardThreatRange(v_code_428_);
lean_dec(v_code_428_);
return v_res_429_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatBearing(lean_object* v_code_430_){
_start:
{
lean_object* v___x_431_; uint8_t v___x_432_; 
v___x_431_ = lean_unsigned_to_nat(0u);
v___x_432_ = lean_nat_dec_eq(v_code_430_, v___x_431_);
if (v___x_432_ == 0)
{
lean_object* v___x_433_; uint8_t v___x_434_; 
v___x_433_ = lean_unsigned_to_nat(60u);
v___x_434_ = lean_nat_dec_le(v_code_430_, v___x_433_);
if (v___x_434_ == 0)
{
lean_object* v___x_435_; 
v___x_435_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_435_, 0, v_code_430_);
return v___x_435_;
}
else
{
lean_object* v___x_436_; lean_object* v___x_437_; lean_object* v___x_438_; lean_object* v___x_439_; lean_object* v___x_440_; lean_object* v___x_441_; 
v___x_436_ = lean_unsigned_to_nat(6u);
v___x_437_ = lean_unsigned_to_nat(1u);
v___x_438_ = lean_nat_sub(v_code_430_, v___x_437_);
v___x_439_ = lean_nat_mul(v___x_436_, v___x_438_);
lean_dec(v___x_438_);
v___x_440_ = lean_nat_mul(v___x_436_, v_code_430_);
lean_dec(v_code_430_);
v___x_441_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_441_, 0, v___x_439_);
lean_ctor_set(v___x_441_, 1, v___x_440_);
return v___x_441_;
}
}
else
{
lean_object* v___x_442_; 
lean_dec(v_code_430_);
v___x_442_ = lean_box(0);
return v___x_442_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat(lean_object* v_word_447_){
_start:
{
lean_object* v___x_448_; uint8_t v___x_449_; 
v___x_448_ = lean_cstr_to_nat("72057594037927936");
v___x_449_ = lean_nat_dec_le(v___x_448_, v_word_447_);
if (v___x_449_ == 0)
{
lean_object* v___x_450_; lean_object* v___x_451_; lean_object* v___x_452_; lean_object* v___x_453_; uint8_t v___x_454_; 
v___x_450_ = lean_unsigned_to_nat(2u);
v___x_451_ = lean_unsigned_to_nat(29u);
v___x_452_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_447_, v___x_451_, v___x_450_);
v___x_453_ = lean_unsigned_to_nat(0u);
v___x_454_ = lean_nat_dec_eq(v___x_452_, v___x_453_);
if (v___x_454_ == 0)
{
lean_object* v___x_455_; uint8_t v___x_456_; 
v___x_455_ = lean_unsigned_to_nat(1u);
v___x_456_ = lean_nat_dec_eq(v___x_452_, v___x_455_);
if (v___x_456_ == 0)
{
uint8_t v___x_457_; 
v___x_457_ = lean_nat_dec_eq(v___x_452_, v___x_450_);
lean_dec(v___x_452_);
if (v___x_457_ == 0)
{
lean_object* v___x_458_; 
v___x_458_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__0));
return v___x_458_;
}
else
{
lean_object* v___x_459_; lean_object* v___x_460_; lean_object* v___x_461_; lean_object* v___x_462_; lean_object* v___x_463_; lean_object* v___x_464_; lean_object* v___x_465_; lean_object* v___x_466_; lean_object* v___x_467_; lean_object* v___x_468_; lean_object* v___x_469_; lean_object* v___x_470_; lean_object* v___x_471_; lean_object* v___x_472_; 
v___x_459_ = lean_unsigned_to_nat(31u);
v___x_460_ = lean_unsigned_to_nat(13u);
v___x_461_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_447_, v___x_459_, v___x_460_);
v___x_462_ = lp_lean1090_Lean1090_Impl_Altitude_decodeGillham(v___x_461_);
lean_dec(v___x_461_);
v___x_463_ = lean_unsigned_to_nat(44u);
v___x_464_ = lean_unsigned_to_nat(7u);
v___x_465_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_447_, v___x_463_, v___x_464_);
v___x_466_ = lp_lean1090_Lean1090_Impl_standardThreatRange(v___x_465_);
lean_dec(v___x_465_);
v___x_467_ = lean_unsigned_to_nat(51u);
v___x_468_ = lean_unsigned_to_nat(6u);
v___x_469_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_447_, v___x_467_, v___x_468_);
v___x_470_ = lp_lean1090_Lean1090_Impl_standardThreatBearing(v___x_469_);
v___x_471_ = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(v___x_471_, 0, v___x_462_);
lean_ctor_set(v___x_471_, 1, v___x_466_);
lean_ctor_set(v___x_471_, 2, v___x_470_);
v___x_472_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_472_, 0, v___x_471_);
return v___x_472_;
}
}
else
{
lean_object* v___x_473_; lean_object* v___x_474_; uint8_t v___x_475_; 
lean_dec(v___x_452_);
v___x_473_ = lean_unsigned_to_nat(55u);
v___x_474_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_447_, v___x_473_, v___x_450_);
v___x_475_ = lean_nat_dec_eq(v___x_474_, v___x_453_);
lean_dec(v___x_474_);
if (v___x_475_ == 0)
{
lean_object* v___x_476_; 
v___x_476_ = lean_box(0);
return v___x_476_;
}
else
{
lean_object* v___x_477_; lean_object* v___x_478_; lean_object* v___x_479_; lean_object* v___x_480_; lean_object* v___x_481_; 
v___x_477_ = lean_unsigned_to_nat(31u);
v___x_478_ = lean_unsigned_to_nat(24u);
v___x_479_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_447_, v___x_477_, v___x_478_);
v___x_480_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_480_, 0, v___x_479_);
v___x_481_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_481_, 0, v___x_480_);
return v___x_481_;
}
}
}
else
{
lean_object* v___x_482_; 
lean_dec(v___x_452_);
v___x_482_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__1));
return v___x_482_;
}
}
else
{
lean_object* v___x_483_; 
v___x_483_ = lean_box(0);
return v___x_483_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat___boxed(lean_object* v_word_484_){
_start:
{
lean_object* v_res_485_; 
v_res_485_ = lp_lean1090_Lean1090_Impl_cbStandardThreat(v_word_484_);
lean_dec(v_word_484_);
return v_res_485_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbDashPlaceholder(lean_object* v_code_486_){
_start:
{
lean_object* v___x_487_; uint8_t v___x_488_; 
v___x_487_ = lean_unsigned_to_nat(0u);
v___x_488_ = lean_nat_dec_eq(v_code_486_, v___x_487_);
if (v___x_488_ == 0)
{
lean_object* v___x_489_; uint8_t v___x_490_; 
v___x_489_ = lean_unsigned_to_nat(32u);
v___x_490_ = lean_nat_dec_eq(v_code_486_, v___x_489_);
if (v___x_490_ == 0)
{
lean_object* v___x_491_; uint8_t v___x_492_; 
v___x_491_ = lean_unsigned_to_nat(45u);
v___x_492_ = lean_nat_dec_eq(v_code_486_, v___x_491_);
return v___x_492_;
}
else
{
return v___x_490_;
}
}
else
{
return v___x_488_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDashPlaceholder___boxed(lean_object* v_code_493_){
_start:
{
uint8_t v_res_494_; lean_object* v_r_495_; 
v_res_494_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v_code_493_);
lean_dec(v_code_493_);
v_r_495_ = lean_box(v_res_494_);
return v_r_495_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(lean_object* v_word_496_, lean_object* v_a_497_, lean_object* v_a_498_){
_start:
{
if (lean_obj_tag(v_a_497_) == 0)
{
lean_object* v___x_499_; 
v___x_499_ = l_List_reverse___redArg(v_a_498_);
return v___x_499_;
}
else
{
lean_object* v_head_500_; lean_object* v_tail_501_; lean_object* v___x_503_; uint8_t v_isShared_504_; uint8_t v_isSharedCheck_514_; 
v_head_500_ = lean_ctor_get(v_a_497_, 0);
v_tail_501_ = lean_ctor_get(v_a_497_, 1);
v_isSharedCheck_514_ = !lean_is_exclusive(v_a_497_);
if (v_isSharedCheck_514_ == 0)
{
v___x_503_ = v_a_497_;
v_isShared_504_ = v_isSharedCheck_514_;
goto v_resetjp_502_;
}
else
{
lean_inc(v_tail_501_);
lean_inc(v_head_500_);
lean_dec(v_a_497_);
v___x_503_ = lean_box(0);
v_isShared_504_ = v_isSharedCheck_514_;
goto v_resetjp_502_;
}
v_resetjp_502_:
{
lean_object* v___x_505_; lean_object* v___x_506_; lean_object* v___x_507_; lean_object* v___x_508_; lean_object* v___x_509_; lean_object* v___x_511_; 
v___x_505_ = lean_unsigned_to_nat(2u);
v___x_506_ = lean_unsigned_to_nat(6u);
v___x_507_ = lean_nat_mul(v___x_506_, v_head_500_);
lean_dec(v_head_500_);
v___x_508_ = lean_nat_add(v___x_505_, v___x_507_);
lean_dec(v___x_507_);
v___x_509_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_496_, v___x_508_, v___x_506_);
lean_dec(v___x_508_);
if (v_isShared_504_ == 0)
{
lean_ctor_set(v___x_503_, 1, v_a_498_);
lean_ctor_set(v___x_503_, 0, v___x_509_);
v___x_511_ = v___x_503_;
goto v_reusejp_510_;
}
else
{
lean_object* v_reuseFailAlloc_513_; 
v_reuseFailAlloc_513_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_513_, 0, v___x_509_);
lean_ctor_set(v_reuseFailAlloc_513_, 1, v_a_498_);
v___x_511_ = v_reuseFailAlloc_513_;
goto v_reusejp_510_;
}
v_reusejp_510_:
{
v_a_497_ = v_tail_501_;
v_a_498_ = v___x_511_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0___boxed(lean_object* v_word_515_, lean_object* v_a_516_, lean_object* v_a_517_){
_start:
{
lean_object* v_res_518_; 
v_res_518_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(v_word_515_, v_a_516_, v_a_517_);
lean_dec(v_word_515_);
return v_res_518_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__1(lean_object* v_a_519_, lean_object* v_a_520_){
_start:
{
if (lean_obj_tag(v_a_519_) == 0)
{
lean_object* v___x_521_; 
v___x_521_ = l_List_reverse___redArg(v_a_520_);
return v___x_521_;
}
else
{
lean_object* v_head_522_; lean_object* v_tail_523_; lean_object* v___x_525_; uint8_t v_isShared_526_; uint8_t v_isSharedCheck_533_; 
v_head_522_ = lean_ctor_get(v_a_519_, 0);
v_tail_523_ = lean_ctor_get(v_a_519_, 1);
v_isSharedCheck_533_ = !lean_is_exclusive(v_a_519_);
if (v_isSharedCheck_533_ == 0)
{
v___x_525_ = v_a_519_;
v_isShared_526_ = v_isSharedCheck_533_;
goto v_resetjp_524_;
}
else
{
lean_inc(v_tail_523_);
lean_inc(v_head_522_);
lean_dec(v_a_519_);
v___x_525_ = lean_box(0);
v_isShared_526_ = v_isSharedCheck_533_;
goto v_resetjp_524_;
}
v_resetjp_524_:
{
uint8_t v___x_527_; 
v___x_527_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v_head_522_);
if (v___x_527_ == 0)
{
lean_object* v___x_529_; 
if (v_isShared_526_ == 0)
{
lean_ctor_set(v___x_525_, 1, v_a_520_);
v___x_529_ = v___x_525_;
goto v_reusejp_528_;
}
else
{
lean_object* v_reuseFailAlloc_531_; 
v_reuseFailAlloc_531_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_531_, 0, v_head_522_);
lean_ctor_set(v_reuseFailAlloc_531_, 1, v_a_520_);
v___x_529_ = v_reuseFailAlloc_531_;
goto v_reusejp_528_;
}
v_reusejp_528_:
{
v_a_519_ = v_tail_523_;
v_a_520_ = v___x_529_;
goto _start;
}
}
else
{
lean_del_object(v___x_525_);
lean_dec(v_head_522_);
v_a_519_ = v_tail_523_;
goto _start;
}
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0(void){
_start:
{
lean_object* v___x_534_; lean_object* v___x_535_; 
v___x_534_ = lean_unsigned_to_nat(7u);
v___x_535_ = l_List_range(v___x_534_);
return v___x_535_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistrationCodes(lean_object* v_word_536_){
_start:
{
lean_object* v___x_537_; lean_object* v___x_538_; lean_object* v___x_539_; lean_object* v___x_540_; 
v___x_537_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0, &lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0);
v___x_538_ = lean_box(0);
v___x_539_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(v_word_536_, v___x_537_, v___x_538_);
v___x_540_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__1(v___x_539_, v___x_538_);
return v___x_540_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistrationCodes___boxed(lean_object* v_word_541_){
_start:
{
lean_object* v_res_542_; 
v_res_542_ = lp_lean1090_Lean1090_Impl_cbRegistrationCodes(v_word_541_);
lean_dec(v_word_541_);
return v_res_542_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistration(lean_object* v_word_543_){
_start:
{
lean_object* v___x_544_; lean_object* v___x_545_; lean_object* v___x_546_; uint8_t v___x_547_; 
v___x_544_ = lean_unsigned_to_nat(1u);
v___x_545_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_543_, v___x_544_, v___x_544_);
v___x_546_ = lean_unsigned_to_nat(0u);
v___x_547_ = lean_nat_dec_eq(v___x_545_, v___x_546_);
lean_dec(v___x_545_);
if (v___x_547_ == 0)
{
lean_object* v___x_548_; lean_object* v___x_549_; lean_object* v___x_550_; lean_object* v___x_551_; lean_object* v___x_552_; 
v___x_548_ = lp_lean1090_Lean1090_Impl_cbRegistrationCodes(v_word_543_);
v___x_549_ = lean_box(0);
v___x_550_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(v___x_548_, v___x_549_);
v___x_551_ = lean_string_mk(v___x_550_);
v___x_552_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_552_, 0, v___x_551_);
return v___x_552_;
}
else
{
lean_object* v___x_553_; 
v___x_553_ = lean_box(0);
return v___x_553_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistration___boxed(lean_object* v_word_554_){
_start:
{
lean_object* v_res_555_; 
v_res_555_ = lp_lean1090_Lean1090_Impl_cbRegistration(v_word_554_);
lean_dec(v_word_554_);
return v_res_555_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(lean_object* v_word_556_, lean_object* v_x_557_){
_start:
{
if (lean_obj_tag(v_x_557_) == 0)
{
uint8_t v___x_558_; 
v___x_558_ = 1;
return v___x_558_;
}
else
{
lean_object* v_head_559_; lean_object* v_tail_560_; lean_object* v___x_561_; lean_object* v___x_562_; lean_object* v___x_563_; uint8_t v___x_564_; 
v_head_559_ = lean_ctor_get(v_x_557_, 0);
v_tail_560_ = lean_ctor_get(v_x_557_, 1);
v___x_561_ = lean_unsigned_to_nat(1u);
v___x_562_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_556_, v_head_559_, v___x_561_);
v___x_563_ = lean_unsigned_to_nat(0u);
v___x_564_ = lean_nat_dec_eq(v___x_562_, v___x_563_);
lean_dec(v___x_562_);
if (v___x_564_ == 0)
{
return v___x_564_;
}
else
{
v_x_557_ = v_tail_560_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0___boxed(lean_object* v_word_566_, lean_object* v_x_567_){
_start:
{
uint8_t v_res_568_; lean_object* v_r_569_; 
v_res_568_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(v_word_566_, v_x_567_);
lean_dec(v_x_567_);
lean_dec(v_word_566_);
v_r_569_ = lean_box(v_res_568_);
return v_r_569_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid17(lean_object* v_word_591_){
_start:
{
lean_object* v___x_592_; lean_object* v___x_593_; lean_object* v___x_594_; uint8_t v___x_595_; 
v___x_592_ = lean_unsigned_to_nat(7u);
v___x_593_ = lean_unsigned_to_nat(1u);
v___x_594_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_591_, v___x_592_, v___x_593_);
v___x_595_ = lean_nat_dec_eq(v___x_594_, v___x_593_);
lean_dec(v___x_594_);
if (v___x_595_ == 0)
{
return v___x_595_;
}
else
{
lean_object* v___x_596_; lean_object* v___x_597_; lean_object* v___x_598_; lean_object* v___x_599_; uint8_t v___x_600_; 
v___x_596_ = lean_unsigned_to_nat(30u);
v___x_597_ = lean_unsigned_to_nat(27u);
v___x_598_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_591_, v___x_596_, v___x_597_);
v___x_599_ = lean_unsigned_to_nat(0u);
v___x_600_ = lean_nat_dec_eq(v___x_598_, v___x_599_);
lean_dec(v___x_598_);
if (v___x_600_ == 0)
{
return v___x_600_;
}
else
{
lean_object* v___x_601_; uint8_t v___x_602_; 
v___x_601_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbValid17___closed__6));
v___x_602_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(v_word_591_, v___x_601_);
return v___x_602_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid17___boxed(lean_object* v_word_603_){
_start:
{
uint8_t v_res_604_; lean_object* v_r_605_; 
v_res_604_ = lp_lean1090_Lean1090_Impl_cbValid17(v_word_603_);
lean_dec(v_word_603_);
v_r_605_ = lean_box(v_res_604_);
return v_r_605_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(lean_object* v_word_669_, lean_object* v_x_670_){
_start:
{
if (lean_obj_tag(v_x_670_) == 0)
{
uint8_t v___x_671_; 
v___x_671_ = 1;
return v___x_671_;
}
else
{
lean_object* v_head_672_; lean_object* v_tail_673_; uint8_t v___y_675_; lean_object* v___x_677_; lean_object* v_allowed_678_; lean_object* v___x_679_; uint8_t v___x_680_; 
v_head_672_ = lean_ctor_get(v_x_670_, 0);
v_tail_673_ = lean_ctor_get(v_x_670_, 1);
v___x_677_ = lean_unsigned_to_nat(56u);
v_allowed_678_ = ((lean_object*)(lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__20));
v___x_679_ = lean_nat_sub(v___x_677_, v_head_672_);
v___x_680_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v___x_679_, v_allowed_678_);
lean_dec(v___x_679_);
if (v___x_680_ == 0)
{
lean_object* v___x_681_; lean_object* v___x_682_; lean_object* v___x_683_; lean_object* v___x_684_; uint8_t v___x_685_; 
v___x_681_ = lean_unsigned_to_nat(1u);
v___x_682_ = lean_nat_add(v_head_672_, v___x_681_);
v___x_683_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_669_, v___x_682_, v___x_681_);
lean_dec(v___x_682_);
v___x_684_ = lean_unsigned_to_nat(0u);
v___x_685_ = lean_nat_dec_eq(v___x_683_, v___x_684_);
lean_dec(v___x_683_);
v___y_675_ = v___x_685_;
goto v___jp_674_;
}
else
{
v___y_675_ = v___x_680_;
goto v___jp_674_;
}
v___jp_674_:
{
if (v___y_675_ == 0)
{
return v___y_675_;
}
else
{
v_x_670_ = v_tail_673_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___boxed(lean_object* v_word_686_, lean_object* v_x_687_){
_start:
{
uint8_t v_res_688_; lean_object* v_r_689_; 
v_res_688_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(v_word_686_, v_x_687_);
lean_dec(v_x_687_);
lean_dec(v_word_686_);
v_r_689_ = lean_box(v_res_688_);
return v_r_689_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(lean_object* v_word_690_, lean_object* v_x_691_){
_start:
{
if (lean_obj_tag(v_x_691_) == 0)
{
uint8_t v___x_692_; 
v___x_692_ = 1;
return v___x_692_;
}
else
{
lean_object* v_head_693_; lean_object* v_tail_694_; lean_object* v___x_695_; lean_object* v___x_696_; lean_object* v___x_697_; lean_object* v___x_698_; uint8_t v___x_699_; 
v_head_693_ = lean_ctor_get(v_x_691_, 0);
v_tail_694_ = lean_ctor_get(v_x_691_, 1);
v___x_695_ = lean_unsigned_to_nat(57u);
v___x_696_ = lean_nat_sub(v___x_695_, v_head_693_);
v___x_697_ = lean_unsigned_to_nat(1u);
v___x_698_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_690_, v___x_696_, v___x_697_);
lean_dec(v___x_696_);
v___x_699_ = lean_nat_dec_eq(v___x_698_, v___x_697_);
lean_dec(v___x_698_);
if (v___x_699_ == 0)
{
return v___x_699_;
}
else
{
v_x_691_ = v_tail_694_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1___boxed(lean_object* v_word_701_, lean_object* v_x_702_){
_start:
{
uint8_t v_res_703_; lean_object* v_r_704_; 
v_res_703_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(v_word_701_, v_x_702_);
lean_dec(v_x_702_);
lean_dec(v_word_701_);
v_r_704_ = lean_box(v_res_703_);
return v_r_704_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid18___closed__0(void){
_start:
{
lean_object* v___x_705_; lean_object* v___x_706_; 
v___x_705_ = lean_unsigned_to_nat(56u);
v___x_706_ = l_List_range(v___x_705_);
return v___x_706_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid18(lean_object* v_word_719_){
_start:
{
lean_object* v___x_720_; uint8_t v___x_721_; 
v___x_720_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid18___closed__0, &lp_lean1090_Lean1090_Impl_cbValid18___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid18___closed__0);
v___x_721_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(v_word_719_, v___x_720_);
if (v___x_721_ == 0)
{
return v___x_721_;
}
else
{
lean_object* v___x_722_; uint8_t v___x_723_; 
v___x_722_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbValid18___closed__4));
v___x_723_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(v_word_719_, v___x_722_);
return v___x_723_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid18___boxed(lean_object* v_word_724_){
_start:
{
uint8_t v_res_725_; lean_object* v_r_726_; 
v_res_725_ = lp_lean1090_Lean1090_Impl_cbValid18(v_word_724_);
lean_dec(v_word_724_);
v_r_726_ = lean_box(v_res_725_);
return v_r_726_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(lean_object* v_word_763_, lean_object* v_x_764_){
_start:
{
if (lean_obj_tag(v_x_764_) == 0)
{
uint8_t v___x_765_; 
v___x_765_ = 1;
return v___x_765_;
}
else
{
lean_object* v_head_766_; lean_object* v_tail_767_; uint8_t v___y_769_; lean_object* v_allowed_771_; lean_object* v___x_772_; lean_object* v___x_773_; uint8_t v___x_774_; 
v_head_766_ = lean_ctor_get(v_x_764_, 0);
v_tail_767_ = lean_ctor_get(v_x_764_, 1);
v_allowed_771_ = ((lean_object*)(lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__11));
v___x_772_ = lean_unsigned_to_nat(112u);
v___x_773_ = lean_nat_sub(v___x_772_, v_head_766_);
v___x_774_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v___x_773_, v_allowed_771_);
lean_dec(v___x_773_);
if (v___x_774_ == 0)
{
lean_object* v___x_775_; lean_object* v___x_776_; lean_object* v___x_777_; lean_object* v___x_778_; uint8_t v___x_779_; 
v___x_775_ = lean_unsigned_to_nat(1u);
v___x_776_ = lean_nat_add(v_head_766_, v___x_775_);
v___x_777_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_763_, v___x_776_, v___x_775_);
lean_dec(v___x_776_);
v___x_778_ = lean_unsigned_to_nat(0u);
v___x_779_ = lean_nat_dec_eq(v___x_777_, v___x_778_);
lean_dec(v___x_777_);
v___y_769_ = v___x_779_;
goto v___jp_768_;
}
else
{
v___y_769_ = v___x_774_;
goto v___jp_768_;
}
v___jp_768_:
{
if (v___y_769_ == 0)
{
return v___y_769_;
}
else
{
v_x_764_ = v_tail_767_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___boxed(lean_object* v_word_780_, lean_object* v_x_781_){
_start:
{
uint8_t v_res_782_; lean_object* v_r_783_; 
v_res_782_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(v_word_780_, v_x_781_);
lean_dec(v_x_781_);
lean_dec(v_word_780_);
v_r_783_ = lean_box(v_res_782_);
return v_r_783_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid19(lean_object* v_word_784_){
_start:
{
lean_object* v___x_785_; uint8_t v___x_786_; 
v___x_785_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid18___closed__0, &lp_lean1090_Lean1090_Impl_cbValid18___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid18___closed__0);
v___x_786_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(v_word_784_, v___x_785_);
return v___x_786_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid19___boxed(lean_object* v_word_787_){
_start:
{
uint8_t v_res_788_; lean_object* v_r_789_; 
v_res_788_ = lp_lean1090_Lean1090_Impl_cbValid19(v_word_787_);
lean_dec(v_word_787_);
v_r_789_ = lean_box(v_res_788_);
return v_r_789_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbValid21_spec__0(lean_object* v_a_790_, lean_object* v_a_791_){
_start:
{
if (lean_obj_tag(v_a_790_) == 0)
{
lean_object* v___x_792_; 
v___x_792_ = l_List_reverse___redArg(v_a_791_);
return v___x_792_;
}
else
{
lean_object* v_head_793_; lean_object* v_tail_794_; lean_object* v___x_796_; uint8_t v_isShared_797_; uint8_t v_isSharedCheck_806_; 
v_head_793_ = lean_ctor_get(v_a_790_, 0);
v_tail_794_ = lean_ctor_get(v_a_790_, 1);
v_isSharedCheck_806_ = !lean_is_exclusive(v_a_790_);
if (v_isSharedCheck_806_ == 0)
{
v___x_796_ = v_a_790_;
v_isShared_797_ = v_isSharedCheck_806_;
goto v_resetjp_795_;
}
else
{
lean_inc(v_tail_794_);
lean_inc(v_head_793_);
lean_dec(v_a_790_);
v___x_796_ = lean_box(0);
v_isShared_797_ = v_isSharedCheck_806_;
goto v_resetjp_795_;
}
v_resetjp_795_:
{
uint32_t v___x_798_; uint32_t v___x_799_; uint8_t v___x_800_; 
v___x_798_ = lp_lean1090_Lean1090_Impl_cbCharacter(v_head_793_);
v___x_799_ = 35;
v___x_800_ = lean_uint32_dec_eq(v___x_798_, v___x_799_);
if (v___x_800_ == 0)
{
lean_del_object(v___x_796_);
lean_dec(v_head_793_);
v_a_790_ = v_tail_794_;
goto _start;
}
else
{
lean_object* v___x_803_; 
if (v_isShared_797_ == 0)
{
lean_ctor_set(v___x_796_, 1, v_a_791_);
v___x_803_ = v___x_796_;
goto v_reusejp_802_;
}
else
{
lean_object* v_reuseFailAlloc_805_; 
v_reuseFailAlloc_805_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_805_, 0, v_head_793_);
lean_ctor_set(v_reuseFailAlloc_805_, 1, v_a_791_);
v___x_803_ = v_reuseFailAlloc_805_;
goto v_reusejp_802_;
}
v_reusejp_802_:
{
v_a_790_ = v_tail_794_;
v_a_791_ = v___x_803_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid21(lean_object* v_word_807_){
_start:
{
uint8_t v___y_809_; lean_object* v_codes_822_; lean_object* v___x_823_; lean_object* v___x_824_; lean_object* v___x_825_; uint8_t v___x_826_; 
v_codes_822_ = lp_lean1090_Lean1090_Impl_cbRegistrationCodes(v_word_807_);
v___x_823_ = lean_unsigned_to_nat(1u);
v___x_824_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_807_, v___x_823_, v___x_823_);
v___x_825_ = lean_unsigned_to_nat(0u);
v___x_826_ = lean_nat_dec_eq(v___x_824_, v___x_825_);
lean_dec(v___x_824_);
if (v___x_826_ == 0)
{
lean_object* v___x_827_; lean_object* v___x_828_; lean_object* v___x_829_; lean_object* v___x_830_; uint8_t v___x_831_; 
v___x_827_ = lean_box(0);
v___x_828_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbValid21_spec__0(v_codes_822_, v___x_827_);
v___x_829_ = l_List_lengthTR___redArg(v___x_828_);
lean_dec(v___x_828_);
v___x_830_ = lean_unsigned_to_nat(2u);
v___x_831_ = lean_nat_dec_le(v___x_829_, v___x_830_);
lean_dec(v___x_829_);
v___y_809_ = v___x_831_;
goto v___jp_808_;
}
else
{
uint8_t v___x_832_; 
v___x_832_ = l_List_isEmpty___redArg(v_codes_822_);
lean_dec(v_codes_822_);
v___y_809_ = v___x_832_;
goto v___jp_808_;
}
v___jp_808_:
{
if (v___y_809_ == 0)
{
return v___y_809_;
}
else
{
lean_object* v___x_810_; lean_object* v___x_811_; lean_object* v___x_812_; lean_object* v___x_813_; uint8_t v___x_814_; 
v___x_810_ = lean_unsigned_to_nat(44u);
v___x_811_ = lean_unsigned_to_nat(1u);
v___x_812_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_807_, v___x_810_, v___x_811_);
v___x_813_ = lean_unsigned_to_nat(0u);
v___x_814_ = lean_nat_dec_eq(v___x_812_, v___x_813_);
lean_dec(v___x_812_);
if (v___x_814_ == 0)
{
return v___x_814_;
}
else
{
lean_object* v___x_815_; lean_object* v___x_816_; lean_object* v___x_817_; uint8_t v___x_818_; 
v___x_815_ = lean_unsigned_to_nat(45u);
v___x_816_ = lean_unsigned_to_nat(6u);
v___x_817_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_807_, v___x_815_, v___x_816_);
v___x_818_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v___x_817_);
lean_dec(v___x_817_);
if (v___x_818_ == 0)
{
return v___x_818_;
}
else
{
lean_object* v___x_819_; lean_object* v___x_820_; uint8_t v___x_821_; 
v___x_819_ = lean_unsigned_to_nat(51u);
v___x_820_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_807_, v___x_819_, v___x_816_);
v___x_821_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v___x_820_);
lean_dec(v___x_820_);
return v___x_821_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid21___boxed(lean_object* v_word_833_){
_start:
{
uint8_t v_res_834_; lean_object* v_r_835_; 
v_res_834_ = lp_lean1090_Lean1090_Impl_cbValid21(v_word_833_);
lean_dec(v_word_833_);
v_r_835_ = lean_box(v_res_834_);
return v_r_835_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid40___closed__0(void){
_start:
{
lean_object* v___x_836_; lean_object* v___x_837_; 
v___x_836_ = lean_unsigned_to_nat(50000u);
v___x_837_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_836_);
return v___x_837_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid40___closed__1(void){
_start:
{
lean_object* v___x_838_; lean_object* v___x_839_; 
v___x_838_ = lean_unsigned_to_nat(1200u);
v___x_839_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_838_);
return v___x_839_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid40(lean_object* v_word_840_){
_start:
{
uint8_t v___y_842_; lean_object* v___x_869_; lean_object* v___x_870_; lean_object* v___x_871_; uint8_t v___x_872_; 
v___x_869_ = lean_unsigned_to_nat(1u);
v___x_870_ = lean_unsigned_to_nat(2u);
v___x_871_ = lean_unsigned_to_nat(12u);
v___x_872_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_840_, v___x_869_, v___x_870_, v___x_871_);
if (v___x_872_ == 0)
{
v___y_842_ = v___x_872_;
goto v___jp_841_;
}
else
{
lean_object* v___x_873_; lean_object* v___x_874_; uint8_t v___x_875_; 
v___x_873_ = lean_unsigned_to_nat(14u);
v___x_874_ = lean_unsigned_to_nat(15u);
v___x_875_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_840_, v___x_873_, v___x_874_, v___x_871_);
v___y_842_ = v___x_875_;
goto v___jp_841_;
}
v___jp_841_:
{
if (v___y_842_ == 0)
{
return v___y_842_;
}
else
{
lean_object* v___x_843_; lean_object* v___x_844_; lean_object* v___x_845_; uint8_t v___x_846_; 
v___x_843_ = lean_unsigned_to_nat(27u);
v___x_844_ = lean_unsigned_to_nat(28u);
v___x_845_ = lean_unsigned_to_nat(12u);
v___x_846_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_840_, v___x_843_, v___x_844_, v___x_845_);
if (v___x_846_ == 0)
{
return v___x_846_;
}
else
{
lean_object* v___x_847_; lean_object* v___x_848_; lean_object* v___x_849_; lean_object* v___x_850_; uint8_t v___x_851_; 
v___x_847_ = lean_unsigned_to_nat(40u);
v___x_848_ = lean_unsigned_to_nat(8u);
v___x_849_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_840_, v___x_847_, v___x_848_);
v___x_850_ = lean_unsigned_to_nat(0u);
v___x_851_ = lean_nat_dec_eq(v___x_849_, v___x_850_);
lean_dec(v___x_849_);
if (v___x_851_ == 0)
{
return v___x_851_;
}
else
{
lean_object* v___x_852_; lean_object* v___x_853_; lean_object* v___x_854_; uint8_t v___x_855_; 
v___x_852_ = lean_unsigned_to_nat(52u);
v___x_853_ = lean_unsigned_to_nat(2u);
v___x_854_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_840_, v___x_852_, v___x_853_);
v___x_855_ = lean_nat_dec_eq(v___x_854_, v___x_850_);
lean_dec(v___x_854_);
if (v___x_855_ == 0)
{
return v___x_855_;
}
else
{
lean_object* v___x_856_; lean_object* v___x_857_; lean_object* v___x_858_; uint8_t v___x_859_; 
v___x_856_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_840_, v___x_853_, v___x_845_);
v___x_857_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_856_);
lean_dec(v___x_856_);
v___x_858_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid40___closed__0, &lp_lean1090_Lean1090_Impl_cbValid40___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid40___closed__0);
v___x_859_ = l_Rat_instDecidableLe(v___x_857_, v___x_858_);
if (v___x_859_ == 0)
{
return v___x_859_;
}
else
{
lean_object* v___x_860_; lean_object* v___x_861_; lean_object* v___x_862_; uint8_t v___x_863_; 
v___x_860_ = lean_unsigned_to_nat(15u);
v___x_861_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_840_, v___x_860_, v___x_845_);
v___x_862_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_861_);
lean_dec(v___x_861_);
v___x_863_ = l_Rat_instDecidableLe(v___x_862_, v___x_858_);
if (v___x_863_ == 0)
{
return v___x_863_;
}
else
{
lean_object* v___x_864_; lean_object* v___x_865_; uint8_t v___x_866_; 
v___x_864_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__4, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__4);
v___x_865_ = lp_lean1090_Lean1090_Impl_cbQNH64(v_word_840_);
lean_inc_ref(v___x_865_);
v___x_866_ = l_Rat_instDecidableLe(v___x_864_, v___x_865_);
if (v___x_866_ == 0)
{
lean_dec_ref(v___x_865_);
return v___x_866_;
}
else
{
lean_object* v___x_867_; uint8_t v___x_868_; 
v___x_867_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid40___closed__1, &lp_lean1090_Lean1090_Impl_cbValid40___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbValid40___closed__1);
v___x_868_ = l_Rat_instDecidableLe(v___x_865_, v___x_867_);
return v___x_868_;
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid40___boxed(lean_object* v_word_876_){
_start:
{
uint8_t v_res_877_; lean_object* v_r_878_; 
v_res_877_ = lp_lean1090_Lean1090_Impl_cbValid40(v_word_876_);
lean_dec(v_word_876_);
v_r_878_ = lean_box(v_res_877_);
return v_r_878_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0(void){
_start:
{
lean_object* v___x_879_; lean_object* v___x_880_; 
v___x_879_ = lean_unsigned_to_nat(60u);
v___x_880_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_879_);
return v___x_880_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid44(lean_object* v_word_881_){
_start:
{
lean_object* v___x_905_; lean_object* v___x_906_; lean_object* v___x_907_; uint8_t v___x_908_; 
v___x_905_ = lean_unsigned_to_nat(1u);
v___x_906_ = lean_unsigned_to_nat(4u);
v___x_907_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_881_, v___x_905_, v___x_906_);
v___x_908_ = lean_nat_dec_eq(v___x_907_, v___x_905_);
if (v___x_908_ == 0)
{
lean_object* v___x_909_; uint8_t v___x_910_; 
v___x_909_ = lean_unsigned_to_nat(2u);
v___x_910_ = lean_nat_dec_eq(v___x_907_, v___x_909_);
lean_dec(v___x_907_);
if (v___x_910_ == 0)
{
return v___x_910_;
}
else
{
goto v___jp_882_;
}
}
else
{
lean_dec(v___x_907_);
goto v___jp_882_;
}
v___jp_882_:
{
lean_object* v___x_883_; lean_object* v___x_884_; lean_object* v___x_885_; uint8_t v___x_886_; 
v___x_883_ = lean_unsigned_to_nat(5u);
v___x_884_ = lean_unsigned_to_nat(6u);
v___x_885_ = lean_unsigned_to_nat(18u);
v___x_886_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_881_, v___x_883_, v___x_884_, v___x_885_);
if (v___x_886_ == 0)
{
return v___x_886_;
}
else
{
lean_object* v___x_887_; lean_object* v___x_888_; lean_object* v___x_889_; uint8_t v___x_890_; 
v___x_887_ = lean_unsigned_to_nat(9u);
v___x_888_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_881_, v___x_884_, v___x_887_);
v___x_889_ = lean_unsigned_to_nat(250u);
v___x_890_ = lean_nat_dec_le(v___x_888_, v___x_889_);
lean_dec(v___x_888_);
if (v___x_890_ == 0)
{
return v___x_890_;
}
else
{
lean_object* v___x_891_; lean_object* v___x_892_; uint8_t v___x_893_; 
v___x_891_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
v___x_892_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_881_);
lean_inc_ref(v___x_892_);
v___x_893_ = l_Rat_instDecidableLe(v___x_891_, v___x_892_);
if (v___x_893_ == 0)
{
lean_dec_ref(v___x_892_);
return v___x_893_;
}
else
{
lean_object* v___x_894_; uint8_t v___x_895_; 
v___x_894_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid44___closed__0, &lp_lean1090_Lean1090_Impl_cbValid44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0);
v___x_895_ = l_Rat_instDecidableLe(v___x_892_, v___x_894_);
if (v___x_895_ == 0)
{
return v___x_895_;
}
else
{
lean_object* v___x_896_; lean_object* v___x_897_; lean_object* v___x_898_; uint8_t v___x_899_; 
v___x_896_ = lean_unsigned_to_nat(35u);
v___x_897_ = lean_unsigned_to_nat(36u);
v___x_898_ = lean_unsigned_to_nat(11u);
v___x_899_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_881_, v___x_896_, v___x_897_, v___x_898_);
if (v___x_899_ == 0)
{
return v___x_899_;
}
else
{
lean_object* v___x_900_; lean_object* v___x_901_; lean_object* v___x_902_; lean_object* v___x_903_; uint8_t v___x_904_; 
v___x_900_ = lean_unsigned_to_nat(47u);
v___x_901_ = lean_unsigned_to_nat(10u);
v___x_902_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_881_, v___x_900_, v___x_901_);
v___x_903_ = lean_unsigned_to_nat(0u);
v___x_904_ = lean_nat_dec_eq(v___x_902_, v___x_903_);
lean_dec(v___x_902_);
return v___x_904_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid44___boxed(lean_object* v_word_911_){
_start:
{
uint8_t v_res_912_; lean_object* v_r_913_; 
v_res_912_ = lp_lean1090_Lean1090_Impl_cbValid44(v_word_911_);
lean_dec(v_word_911_);
v_r_913_ = lean_box(v_res_912_);
return v_r_913_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid45(lean_object* v_word_914_){
_start:
{
uint8_t v___y_916_; lean_object* v___x_925_; lean_object* v___x_926_; lean_object* v___x_927_; lean_object* v___x_928_; uint8_t v___x_929_; 
v___x_925_ = lean_unsigned_to_nat(1u);
v___x_926_ = lean_unsigned_to_nat(15u);
v___x_927_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_914_, v___x_925_, v___x_926_);
v___x_928_ = lean_unsigned_to_nat(0u);
v___x_929_ = lean_nat_dec_eq(v___x_927_, v___x_928_);
lean_dec(v___x_927_);
if (v___x_929_ == 0)
{
return v___x_929_;
}
else
{
lean_object* v___x_930_; lean_object* v___x_931_; lean_object* v___x_932_; uint8_t v___x_933_; 
v___x_930_ = lean_unsigned_to_nat(52u);
v___x_931_ = lean_unsigned_to_nat(5u);
v___x_932_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_914_, v___x_930_, v___x_931_);
v___x_933_ = lean_nat_dec_eq(v___x_932_, v___x_928_);
lean_dec(v___x_932_);
if (v___x_933_ == 0)
{
return v___x_933_;
}
else
{
lean_object* v___x_934_; lean_object* v___x_935_; uint8_t v___x_936_; 
v___x_934_ = lean_unsigned_to_nat(16u);
v___x_935_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_914_, v___x_934_, v___x_925_);
v___x_936_ = lean_nat_dec_eq(v___x_935_, v___x_928_);
lean_dec(v___x_935_);
if (v___x_936_ == 0)
{
lean_object* v___x_937_; lean_object* v___x_938_; lean_object* v___x_939_; lean_object* v___x_940_; lean_object* v___x_941_; lean_object* v___x_942_; uint8_t v___x_943_; 
v___x_937_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
v___x_938_ = lean_unsigned_to_nat(17u);
v___x_939_ = lean_unsigned_to_nat(10u);
v___x_940_ = lp_lean1090_Lean1090_Impl_cbSigned(v_word_914_, v___x_938_, v___x_939_);
v___x_941_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v___x_942_ = l_Rat_div(v___x_940_, v___x_941_);
lean_dec_ref(v___x_940_);
lean_inc_ref(v___x_942_);
v___x_943_ = l_Rat_instDecidableLe(v___x_937_, v___x_942_);
if (v___x_943_ == 0)
{
lean_dec_ref(v___x_942_);
return v___x_943_;
}
else
{
lean_object* v___x_944_; uint8_t v___x_945_; 
v___x_944_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid44___closed__0, &lp_lean1090_Lean1090_Impl_cbValid44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0);
v___x_945_ = l_Rat_instDecidableLe(v___x_942_, v___x_944_);
v___y_916_ = v___x_945_;
goto v___jp_915_;
}
}
else
{
lean_object* v___x_946_; lean_object* v___x_947_; lean_object* v___x_948_; uint8_t v___x_949_; 
v___x_946_ = lean_unsigned_to_nat(18u);
v___x_947_ = lean_unsigned_to_nat(9u);
v___x_948_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_914_, v___x_946_, v___x_947_);
v___x_949_ = lean_nat_dec_eq(v___x_948_, v___x_928_);
lean_dec(v___x_948_);
v___y_916_ = v___x_949_;
goto v___jp_915_;
}
}
}
v___jp_915_:
{
if (v___y_916_ == 0)
{
return v___y_916_;
}
else
{
lean_object* v___x_917_; lean_object* v___x_918_; lean_object* v___x_919_; uint8_t v___x_920_; 
v___x_917_ = lean_unsigned_to_nat(27u);
v___x_918_ = lean_unsigned_to_nat(28u);
v___x_919_ = lean_unsigned_to_nat(11u);
v___x_920_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_914_, v___x_917_, v___x_918_, v___x_919_);
if (v___x_920_ == 0)
{
return v___x_920_;
}
else
{
lean_object* v___x_921_; lean_object* v___x_922_; lean_object* v___x_923_; uint8_t v___x_924_; 
v___x_921_ = lean_unsigned_to_nat(39u);
v___x_922_ = lean_unsigned_to_nat(40u);
v___x_923_ = lean_unsigned_to_nat(12u);
v___x_924_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_914_, v___x_921_, v___x_922_, v___x_923_);
return v___x_924_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid45___boxed(lean_object* v_word_950_){
_start:
{
uint8_t v_res_951_; lean_object* v_r_952_; 
v_res_951_ = lp_lean1090_Lean1090_Impl_cbValid45(v_word_950_);
lean_dec(v_word_950_);
v_r_952_ = lean_box(v_res_951_);
return v_r_952_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid50___closed__0(void){
_start:
{
lean_object* v___x_953_; lean_object* v___x_954_; 
v___x_953_ = lean_unsigned_to_nat(45u);
v___x_954_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_953_);
return v___x_954_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid50(lean_object* v_word_955_){
_start:
{
uint8_t v___y_957_; lean_object* v___x_990_; lean_object* v___x_991_; lean_object* v___x_992_; uint8_t v___x_993_; 
v___x_990_ = lean_unsigned_to_nat(1u);
v___x_991_ = lean_unsigned_to_nat(2u);
v___x_992_ = lean_unsigned_to_nat(10u);
v___x_993_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_955_, v___x_990_, v___x_991_, v___x_992_);
if (v___x_993_ == 0)
{
v___y_957_ = v___x_993_;
goto v___jp_956_;
}
else
{
lean_object* v___x_994_; lean_object* v___x_995_; lean_object* v___x_996_; uint8_t v___x_997_; 
v___x_994_ = lean_unsigned_to_nat(12u);
v___x_995_ = lean_unsigned_to_nat(13u);
v___x_996_ = lean_unsigned_to_nat(11u);
v___x_997_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_955_, v___x_994_, v___x_995_, v___x_996_);
v___y_957_ = v___x_997_;
goto v___jp_956_;
}
v___jp_956_:
{
if (v___y_957_ == 0)
{
return v___y_957_;
}
else
{
lean_object* v___x_958_; lean_object* v___x_959_; lean_object* v___x_960_; uint8_t v___x_961_; 
v___x_958_ = lean_unsigned_to_nat(24u);
v___x_959_ = lean_unsigned_to_nat(25u);
v___x_960_ = lean_unsigned_to_nat(10u);
v___x_961_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_955_, v___x_958_, v___x_959_, v___x_960_);
if (v___x_961_ == 0)
{
return v___x_961_;
}
else
{
lean_object* v___x_962_; lean_object* v___x_963_; uint8_t v___x_964_; 
v___x_962_ = lean_unsigned_to_nat(35u);
v___x_963_ = lean_unsigned_to_nat(36u);
v___x_964_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_955_, v___x_962_, v___x_963_, v___x_960_);
if (v___x_964_ == 0)
{
return v___x_964_;
}
else
{
lean_object* v___x_965_; lean_object* v___x_966_; uint8_t v___x_967_; 
v___x_965_ = lean_unsigned_to_nat(46u);
v___x_966_ = lean_unsigned_to_nat(47u);
v___x_967_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_955_, v___x_965_, v___x_966_, v___x_960_);
if (v___x_967_ == 0)
{
return v___x_967_;
}
else
{
lean_object* v___x_968_; lean_object* v___x_969_; lean_object* v___x_970_; lean_object* v___x_971_; lean_object* v___x_972_; lean_object* v___x_973_; lean_object* v___x_974_; uint8_t v___x_975_; 
v___x_968_ = lean_unsigned_to_nat(2u);
v___x_969_ = lp_lean1090_Lean1090_Impl_cbSigned(v_word_955_, v___x_968_, v___x_960_);
v___x_970_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid50___closed__0, &lp_lean1090_Lean1090_Impl_cbValid50___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid50___closed__0);
v___x_971_ = l_Rat_mul(v___x_969_, v___x_970_);
lean_dec_ref(v___x_969_);
v___x_972_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_973_ = l_Rat_div(v___x_971_, v___x_972_);
lean_dec_ref(v___x_971_);
v___x_974_ = l_Rat_abs(v___x_973_);
v___x_975_ = l_Rat_instDecidableLe(v___x_974_, v___x_970_);
if (v___x_975_ == 0)
{
return v___x_975_;
}
else
{
lean_object* v___x_976_; lean_object* v___x_977_; lean_object* v___x_978_; uint8_t v___x_979_; 
v___x_976_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_955_, v___x_959_, v___x_960_);
v___x_977_ = lean_nat_mul(v___x_976_, v___x_968_);
lean_dec(v___x_976_);
v___x_978_ = lean_unsigned_to_nat(700u);
v___x_979_ = lean_nat_dec_le(v___x_977_, v___x_978_);
lean_dec(v___x_977_);
if (v___x_979_ == 0)
{
return v___x_979_;
}
else
{
lean_object* v___x_980_; lean_object* v___x_981_; lean_object* v___x_982_; uint8_t v___x_983_; 
v___x_980_ = lean_unsigned_to_nat(1u);
v___x_981_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_955_, v___x_965_, v___x_980_);
v___x_982_ = lean_unsigned_to_nat(0u);
v___x_983_ = lean_nat_dec_eq(v___x_981_, v___x_982_);
lean_dec(v___x_981_);
if (v___x_983_ == 0)
{
lean_object* v___x_984_; lean_object* v___x_985_; lean_object* v___x_986_; uint8_t v___x_987_; 
v___x_984_ = lean_unsigned_to_nat(80u);
v___x_985_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_955_, v___x_966_, v___x_960_);
v___x_986_ = lean_nat_mul(v___x_985_, v___x_968_);
lean_dec(v___x_985_);
v___x_987_ = lean_nat_dec_le(v___x_984_, v___x_986_);
if (v___x_987_ == 0)
{
lean_dec(v___x_986_);
return v___x_987_;
}
else
{
lean_object* v___x_988_; uint8_t v___x_989_; 
v___x_988_ = lean_unsigned_to_nat(600u);
v___x_989_ = lean_nat_dec_le(v___x_986_, v___x_988_);
lean_dec(v___x_986_);
return v___x_989_;
}
}
else
{
return v___x_983_;
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid50___boxed(lean_object* v_word_998_){
_start:
{
uint8_t v_res_999_; lean_object* v_r_1000_; 
v_res_999_ = lp_lean1090_Lean1090_Impl_cbValid50(v_word_998_);
lean_dec(v_word_998_);
v_r_1000_ = lean_box(v_res_999_);
return v_r_1000_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid60___closed__0(void){
_start:
{
lean_object* v___x_1001_; lean_object* v___x_1002_; 
v___x_1001_ = lean_unsigned_to_nat(6000u);
v___x_1002_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1001_);
return v___x_1002_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid60(lean_object* v_word_1003_){
_start:
{
uint8_t v___y_1005_; lean_object* v___x_1027_; lean_object* v___x_1028_; lean_object* v___x_1029_; uint8_t v___x_1030_; 
v___x_1027_ = lean_unsigned_to_nat(1u);
v___x_1028_ = lean_unsigned_to_nat(2u);
v___x_1029_ = lean_unsigned_to_nat(11u);
v___x_1030_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1003_, v___x_1027_, v___x_1028_, v___x_1029_);
if (v___x_1030_ == 0)
{
v___y_1005_ = v___x_1030_;
goto v___jp_1004_;
}
else
{
lean_object* v___x_1031_; lean_object* v___x_1032_; lean_object* v___x_1033_; uint8_t v___x_1034_; 
v___x_1031_ = lean_unsigned_to_nat(13u);
v___x_1032_ = lean_unsigned_to_nat(14u);
v___x_1033_ = lean_unsigned_to_nat(10u);
v___x_1034_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1003_, v___x_1031_, v___x_1032_, v___x_1033_);
v___y_1005_ = v___x_1034_;
goto v___jp_1004_;
}
v___jp_1004_:
{
if (v___y_1005_ == 0)
{
return v___y_1005_;
}
else
{
lean_object* v___x_1006_; lean_object* v___x_1007_; lean_object* v___x_1008_; uint8_t v___x_1009_; 
v___x_1006_ = lean_unsigned_to_nat(24u);
v___x_1007_ = lean_unsigned_to_nat(25u);
v___x_1008_ = lean_unsigned_to_nat(10u);
v___x_1009_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1003_, v___x_1006_, v___x_1007_, v___x_1008_);
if (v___x_1009_ == 0)
{
return v___x_1009_;
}
else
{
lean_object* v___x_1010_; lean_object* v___x_1011_; uint8_t v___x_1012_; 
v___x_1010_ = lean_unsigned_to_nat(35u);
v___x_1011_ = lean_unsigned_to_nat(36u);
v___x_1012_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1003_, v___x_1010_, v___x_1011_, v___x_1008_);
if (v___x_1012_ == 0)
{
return v___x_1012_;
}
else
{
lean_object* v___x_1013_; lean_object* v___x_1014_; uint8_t v___x_1015_; 
v___x_1013_ = lean_unsigned_to_nat(46u);
v___x_1014_ = lean_unsigned_to_nat(47u);
v___x_1015_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1003_, v___x_1013_, v___x_1014_, v___x_1008_);
if (v___x_1015_ == 0)
{
return v___x_1015_;
}
else
{
lean_object* v___x_1016_; lean_object* v___x_1017_; lean_object* v___x_1018_; uint8_t v___x_1019_; 
v___x_1016_ = lean_unsigned_to_nat(14u);
v___x_1017_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1003_, v___x_1016_, v___x_1008_);
v___x_1018_ = lean_unsigned_to_nat(500u);
v___x_1019_ = lean_nat_dec_le(v___x_1017_, v___x_1018_);
lean_dec(v___x_1017_);
if (v___x_1019_ == 0)
{
return v___x_1019_;
}
else
{
lean_object* v___x_1020_; lean_object* v___x_1021_; uint8_t v___x_1022_; 
v___x_1020_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_1003_);
v___x_1021_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__0, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__0);
v___x_1022_ = l_Rat_instDecidableLe(v___x_1020_, v___x_1021_);
if (v___x_1022_ == 0)
{
return v___x_1022_;
}
else
{
lean_object* v___x_1023_; lean_object* v___x_1024_; lean_object* v___x_1025_; uint8_t v___x_1026_; 
v___x_1023_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_1003_, v___x_1014_);
v___x_1024_ = l_Rat_abs(v___x_1023_);
v___x_1025_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid60___closed__0, &lp_lean1090_Lean1090_Impl_cbValid60___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid60___closed__0);
v___x_1026_ = l_Rat_instDecidableLe(v___x_1024_, v___x_1025_);
return v___x_1026_;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid60___boxed(lean_object* v_word_1035_){
_start:
{
uint8_t v_res_1036_; lean_object* v_r_1037_; 
v_res_1036_ = lp_lean1090_Lean1090_Impl_cbValid60(v_word_1035_);
lean_dec(v_word_1035_);
v_r_1037_ = lean_box(v_res_1036_);
return v_r_1037_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_bdsWireValid(lean_object* v_register_1038_, lean_object* v_word_1039_){
_start:
{
lean_object* v___x_1040_; uint8_t v___x_1041_; 
v___x_1040_ = lean_cstr_to_nat("72057594037927936");
v___x_1041_ = lean_nat_dec_lt(v_word_1039_, v___x_1040_);
if (v___x_1041_ == 0)
{
return v___x_1041_;
}
else
{
lean_object* v___x_1042_; uint8_t v___x_1043_; 
v___x_1042_ = lean_unsigned_to_nat(5u);
v___x_1043_ = lean_nat_dec_eq(v_register_1038_, v___x_1042_);
if (v___x_1043_ == 0)
{
lean_object* v___x_1044_; uint8_t v___x_1045_; 
v___x_1044_ = lean_unsigned_to_nat(101u);
v___x_1045_ = lean_nat_dec_eq(v_register_1038_, v___x_1044_);
if (v___x_1045_ == 0)
{
lean_object* v___x_1046_; uint8_t v___x_1047_; 
v___x_1046_ = lean_unsigned_to_nat(16u);
v___x_1047_ = lean_nat_dec_eq(v_register_1038_, v___x_1046_);
if (v___x_1047_ == 0)
{
lean_object* v___x_1048_; uint8_t v___x_1049_; 
v___x_1048_ = lean_unsigned_to_nat(23u);
v___x_1049_ = lean_nat_dec_eq(v_register_1038_, v___x_1048_);
if (v___x_1049_ == 0)
{
lean_object* v___x_1050_; uint8_t v___x_1051_; 
v___x_1050_ = lean_unsigned_to_nat(24u);
v___x_1051_ = lean_nat_dec_eq(v_register_1038_, v___x_1050_);
if (v___x_1051_ == 0)
{
lean_object* v___x_1052_; uint8_t v___x_1053_; 
v___x_1052_ = lean_unsigned_to_nat(25u);
v___x_1053_ = lean_nat_dec_eq(v_register_1038_, v___x_1052_);
if (v___x_1053_ == 0)
{
lean_object* v___x_1054_; uint8_t v___x_1055_; 
v___x_1054_ = lean_unsigned_to_nat(32u);
v___x_1055_ = lean_nat_dec_eq(v_register_1038_, v___x_1054_);
if (v___x_1055_ == 0)
{
lean_object* v___x_1056_; uint8_t v___x_1057_; 
v___x_1056_ = lean_unsigned_to_nat(33u);
v___x_1057_ = lean_nat_dec_eq(v_register_1038_, v___x_1056_);
if (v___x_1057_ == 0)
{
lean_object* v___x_1058_; uint8_t v___x_1059_; 
v___x_1058_ = lean_unsigned_to_nat(48u);
v___x_1059_ = lean_nat_dec_eq(v_register_1038_, v___x_1058_);
if (v___x_1059_ == 0)
{
lean_object* v___x_1060_; uint8_t v___x_1061_; 
v___x_1060_ = lean_unsigned_to_nat(64u);
v___x_1061_ = lean_nat_dec_eq(v_register_1038_, v___x_1060_);
if (v___x_1061_ == 0)
{
lean_object* v___x_1062_; uint8_t v___x_1063_; 
v___x_1062_ = lean_unsigned_to_nat(68u);
v___x_1063_ = lean_nat_dec_eq(v_register_1038_, v___x_1062_);
if (v___x_1063_ == 0)
{
lean_object* v___x_1064_; uint8_t v___x_1065_; 
v___x_1064_ = lean_unsigned_to_nat(69u);
v___x_1065_ = lean_nat_dec_eq(v_register_1038_, v___x_1064_);
if (v___x_1065_ == 0)
{
lean_object* v___x_1066_; uint8_t v___x_1067_; 
v___x_1066_ = lean_unsigned_to_nat(80u);
v___x_1067_ = lean_nat_dec_eq(v_register_1038_, v___x_1066_);
if (v___x_1067_ == 0)
{
lean_object* v___x_1068_; uint8_t v___x_1069_; 
v___x_1068_ = lean_unsigned_to_nat(96u);
v___x_1069_ = lean_nat_dec_eq(v_register_1038_, v___x_1068_);
if (v___x_1069_ == 0)
{
return v___x_1069_;
}
else
{
uint8_t v___x_1070_; 
v___x_1070_ = lp_lean1090_Lean1090_Impl_cbValid60(v_word_1039_);
return v___x_1070_;
}
}
else
{
uint8_t v___x_1071_; 
v___x_1071_ = lp_lean1090_Lean1090_Impl_cbValid50(v_word_1039_);
return v___x_1071_;
}
}
else
{
uint8_t v___x_1072_; 
v___x_1072_ = lp_lean1090_Lean1090_Impl_cbValid45(v_word_1039_);
return v___x_1072_;
}
}
else
{
uint8_t v___x_1073_; 
v___x_1073_ = lp_lean1090_Lean1090_Impl_cbValid44(v_word_1039_);
return v___x_1073_;
}
}
else
{
uint8_t v___x_1074_; 
v___x_1074_ = lp_lean1090_Lean1090_Impl_cbValid40(v_word_1039_);
return v___x_1074_;
}
}
else
{
lean_object* v___x_1075_; lean_object* v___x_1076_; lean_object* v___x_1077_; uint8_t v___x_1078_; 
v___x_1075_ = lean_unsigned_to_nat(1u);
v___x_1076_ = lean_unsigned_to_nat(8u);
v___x_1077_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1039_, v___x_1075_, v___x_1076_);
v___x_1078_ = lean_nat_dec_eq(v___x_1077_, v___x_1058_);
lean_dec(v___x_1077_);
return v___x_1078_;
}
}
else
{
uint8_t v___x_1079_; 
v___x_1079_ = lp_lean1090_Lean1090_Impl_cbValid21(v_word_1039_);
return v___x_1079_;
}
}
else
{
lean_object* v___x_1080_; lean_object* v___x_1081_; lean_object* v___x_1082_; uint8_t v___x_1083_; 
v___x_1080_ = lean_unsigned_to_nat(1u);
v___x_1081_ = lean_unsigned_to_nat(8u);
v___x_1082_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1039_, v___x_1080_, v___x_1081_);
v___x_1083_ = lean_nat_dec_eq(v___x_1082_, v___x_1054_);
lean_dec(v___x_1082_);
return v___x_1083_;
}
}
else
{
uint8_t v___x_1084_; 
v___x_1084_ = lp_lean1090_Lean1090_Impl_cbValid19(v_word_1039_);
return v___x_1084_;
}
}
else
{
uint8_t v___x_1085_; 
v___x_1085_ = lp_lean1090_Lean1090_Impl_cbValid18(v_word_1039_);
return v___x_1085_;
}
}
else
{
uint8_t v___x_1086_; 
v___x_1086_ = lp_lean1090_Lean1090_Impl_cbValid17(v_word_1039_);
return v___x_1086_;
}
}
else
{
lean_object* v___x_1087_; lean_object* v___x_1088_; lean_object* v___x_1089_; uint8_t v___x_1090_; 
v___x_1087_ = lean_unsigned_to_nat(1u);
v___x_1088_ = lean_unsigned_to_nat(8u);
v___x_1089_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1039_, v___x_1087_, v___x_1088_);
v___x_1090_ = lean_nat_dec_eq(v___x_1089_, v___x_1046_);
lean_dec(v___x_1089_);
if (v___x_1090_ == 0)
{
return v___x_1090_;
}
else
{
lean_object* v___x_1091_; lean_object* v___x_1092_; lean_object* v___x_1093_; uint8_t v___x_1094_; 
v___x_1091_ = lean_unsigned_to_nat(10u);
v___x_1092_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1039_, v___x_1091_, v___x_1042_);
v___x_1093_ = lean_unsigned_to_nat(0u);
v___x_1094_ = lean_nat_dec_eq(v___x_1092_, v___x_1093_);
lean_dec(v___x_1092_);
return v___x_1094_;
}
}
}
else
{
lean_object* v___x_1095_; lean_object* v___x_1096_; lean_object* v___x_1097_; uint8_t v___x_1098_; 
v___x_1095_ = lean_unsigned_to_nat(1u);
v___x_1096_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1039_, v___x_1095_, v___x_1042_);
v___x_1097_ = lean_unsigned_to_nat(31u);
v___x_1098_ = lean_nat_dec_eq(v___x_1096_, v___x_1097_);
lean_dec(v___x_1096_);
if (v___x_1098_ == 0)
{
return v___x_1098_;
}
else
{
lean_object* v___x_1099_; lean_object* v___x_1100_; lean_object* v___x_1101_; lean_object* v___x_1102_; uint8_t v___x_1103_; 
v___x_1099_ = lean_unsigned_to_nat(6u);
v___x_1100_ = lean_unsigned_to_nat(3u);
v___x_1101_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1039_, v___x_1099_, v___x_1100_);
v___x_1102_ = lean_unsigned_to_nat(2u);
v___x_1103_ = lean_nat_dec_lt(v___x_1101_, v___x_1102_);
lean_dec(v___x_1101_);
if (v___x_1103_ == 0)
{
return v___x_1103_;
}
else
{
uint8_t v___x_1104_; 
v___x_1104_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1039_);
return v___x_1104_;
}
}
}
}
else
{
lean_object* v___x_1105_; lean_object* v_tc_1106_; lean_object* v___x_1113_; uint8_t v___x_1114_; 
v___x_1105_ = lean_unsigned_to_nat(1u);
v_tc_1106_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1039_, v___x_1105_, v___x_1042_);
v___x_1113_ = lean_unsigned_to_nat(9u);
v___x_1114_ = lean_nat_dec_le(v___x_1113_, v_tc_1106_);
if (v___x_1114_ == 0)
{
goto v___jp_1107_;
}
else
{
lean_object* v___x_1115_; uint8_t v___x_1116_; 
v___x_1115_ = lean_unsigned_to_nat(18u);
v___x_1116_ = lean_nat_dec_le(v_tc_1106_, v___x_1115_);
if (v___x_1116_ == 0)
{
goto v___jp_1107_;
}
else
{
uint8_t v___x_1117_; 
lean_dec(v_tc_1106_);
v___x_1117_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1039_);
return v___x_1117_;
}
}
v___jp_1107_:
{
lean_object* v___x_1108_; uint8_t v___x_1109_; 
v___x_1108_ = lean_unsigned_to_nat(20u);
v___x_1109_ = lean_nat_dec_le(v___x_1108_, v_tc_1106_);
if (v___x_1109_ == 0)
{
lean_dec(v_tc_1106_);
return v___x_1109_;
}
else
{
lean_object* v___x_1110_; uint8_t v___x_1111_; 
v___x_1110_ = lean_unsigned_to_nat(22u);
v___x_1111_ = lean_nat_dec_le(v_tc_1106_, v___x_1110_);
lean_dec(v_tc_1106_);
if (v___x_1111_ == 0)
{
return v___x_1111_;
}
else
{
uint8_t v___x_1112_; 
v___x_1112_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1039_);
return v___x_1112_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsWireValid___boxed(lean_object* v_register_1118_, lean_object* v_word_1119_){
_start:
{
uint8_t v_res_1120_; lean_object* v_r_1121_; 
v_res_1120_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1118_, v_word_1119_);
lean_dec(v_word_1119_);
lean_dec(v_register_1118_);
v_r_1121_ = lean_box(v_res_1120_);
return v_r_1121_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_bdsLayout___closed__0(void){
_start:
{
lean_object* v___x_1122_; lean_object* v___x_1123_; 
v___x_1122_ = lp_lean1090_Lean1090_Impl_adsbPositionLayout;
v___x_1123_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1123_, 0, v___x_1122_);
return v___x_1123_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsLayout(lean_object* v_register_1124_, lean_object* v_word_1125_){
_start:
{
lean_object* v___x_1126_; uint8_t v___x_1127_; 
v___x_1126_ = lean_unsigned_to_nat(5u);
v___x_1127_ = lean_nat_dec_eq(v_register_1124_, v___x_1126_);
if (v___x_1127_ == 0)
{
lean_object* v___x_1128_; uint8_t v___x_1129_; 
v___x_1128_ = lean_unsigned_to_nat(101u);
v___x_1129_ = lean_nat_dec_eq(v_register_1124_, v___x_1128_);
if (v___x_1129_ == 0)
{
lean_object* v___x_1130_; 
v___x_1130_ = lp_lean1090_Lean1090_Impl_commBLayout(v_register_1124_);
return v___x_1130_;
}
else
{
lean_object* v___x_1131_; 
v___x_1131_ = lp_lean1090_Lean1090_Impl_adsbLayout(v_word_1125_);
return v___x_1131_;
}
}
else
{
lean_object* v___x_1132_; 
v___x_1132_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_bdsLayout___closed__0, &lp_lean1090_Lean1090_Impl_bdsLayout___closed__0_once, _init_lp_lean1090_Lean1090_Impl_bdsLayout___closed__0);
return v___x_1132_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsLayout___boxed(lean_object* v_register_1133_, lean_object* v_word_1134_){
_start:
{
lean_object* v_res_1135_; 
v_res_1135_ = lp_lean1090_Lean1090_Impl_bdsLayout(v_register_1133_, v_word_1134_);
lean_dec(v_word_1134_);
lean_dec(v_register_1133_);
return v_res_1135_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeBDS(lean_object* v_register_1136_, lean_object* v_word_1137_){
_start:
{
lean_object* v___x_1138_; 
v___x_1138_ = lp_lean1090_Lean1090_Impl_bdsLayout(v_register_1136_, v_word_1137_);
if (lean_obj_tag(v___x_1138_) == 0)
{
lean_object* v___x_1139_; 
lean_dec(v_register_1136_);
v___x_1139_ = lean_box(0);
return v___x_1139_;
}
else
{
lean_object* v_val_1140_; lean_object* v___x_1142_; uint8_t v_isShared_1143_; uint8_t v_isSharedCheck_1151_; 
v_val_1140_ = lean_ctor_get(v___x_1138_, 0);
v_isSharedCheck_1151_ = !lean_is_exclusive(v___x_1138_);
if (v_isSharedCheck_1151_ == 0)
{
v___x_1142_ = v___x_1138_;
v_isShared_1143_ = v_isSharedCheck_1151_;
goto v_resetjp_1141_;
}
else
{
lean_inc(v_val_1140_);
lean_dec(v___x_1138_);
v___x_1142_ = lean_box(0);
v_isShared_1143_ = v_isSharedCheck_1151_;
goto v_resetjp_1141_;
}
v_resetjp_1141_:
{
uint8_t v___x_1144_; 
v___x_1144_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1136_, v_word_1137_);
if (v___x_1144_ == 0)
{
lean_object* v___x_1145_; 
lean_del_object(v___x_1142_);
lean_dec(v_val_1140_);
lean_dec(v_register_1136_);
v___x_1145_ = lean_box(0);
return v___x_1145_;
}
else
{
lean_object* v___x_1146_; lean_object* v___x_1147_; lean_object* v___x_1149_; 
v___x_1146_ = lp_lean1090_Lean1090_Impl_decodePayloadFields(v_val_1140_, v_word_1137_);
v___x_1147_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1147_, 0, v_register_1136_);
lean_ctor_set(v___x_1147_, 1, v___x_1146_);
if (v_isShared_1143_ == 0)
{
lean_ctor_set(v___x_1142_, 0, v___x_1147_);
v___x_1149_ = v___x_1142_;
goto v_reusejp_1148_;
}
else
{
lean_object* v_reuseFailAlloc_1150_; 
v_reuseFailAlloc_1150_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1150_, 0, v___x_1147_);
v___x_1149_ = v_reuseFailAlloc_1150_;
goto v_reusejp_1148_;
}
v_reusejp_1148_:
{
return v___x_1149_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeBDS___boxed(lean_object* v_register_1152_, lean_object* v_word_1153_){
_start:
{
lean_object* v_res_1154_; 
v_res_1154_ = lp_lean1090_Lean1090_Impl_decodeBDS(v_register_1152_, v_word_1153_);
lean_dec(v_word_1153_);
return v_res_1154_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__0(void){
_start:
{
lean_object* v___x_1155_; lean_object* v___x_1156_; 
v___x_1155_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__0, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__0);
v___x_1156_ = l_Rat_neg(v___x_1155_);
return v___x_1156_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1(void){
_start:
{
lean_object* v___x_1157_; lean_object* v___x_1158_; 
v___x_1157_ = lean_unsigned_to_nat(2u);
v___x_1158_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1157_);
return v___x_1158_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__2(void){
_start:
{
lean_object* v___x_1159_; lean_object* v___x_1160_; lean_object* v___x_1161_; 
v___x_1159_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1160_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__0, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__0);
v___x_1161_ = l_Rat_div(v___x_1160_, v___x_1159_);
return v___x_1161_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGaussian(lean_object* v_value_1162_, lean_object* v_mu_1163_, lean_object* v_sigma_1164_){
_start:
{
lean_object* v___x_1165_; lean_object* v___x_1166_; lean_object* v___x_1167_; lean_object* v_z_1168_; lean_object* v___x_1169_; lean_object* v___x_1170_; lean_object* v___x_1171_; 
v___x_1165_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_mu_1163_);
v___x_1166_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_value_1162_, v___x_1165_);
v___x_1167_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_sigma_1164_);
v_z_1168_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1166_, v___x_1167_);
lean_dec_ref(v___x_1166_);
v___x_1169_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__2, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__2);
lean_inc_ref(v_z_1168_);
v___x_1170_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1169_, v_z_1168_);
v___x_1171_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1170_, v_z_1168_);
lean_dec_ref(v___x_1170_);
return v___x_1171_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbLaplace(lean_object* v_value_1172_, lean_object* v_median_1173_, lean_object* v_scale_1174_){
_start:
{
lean_object* v___x_1175_; uint8_t v___x_1176_; 
v___x_1175_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_scale_1174_);
v___x_1176_ = l_Rat_instDecidableLe(v_scale_1174_, v___x_1175_);
if (v___x_1176_ == 0)
{
lean_object* v___x_1177_; lean_object* v___x_1178_; lean_object* v___x_1179_; lean_object* v___x_1180_; lean_object* v___x_1181_; lean_object* v___x_1182_; 
v___x_1177_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_median_1173_);
v___x_1178_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_value_1172_, v___x_1177_);
v___x_1179_ = l_Rat_abs(v___x_1178_);
v___x_1180_ = l_Rat_neg(v___x_1179_);
v___x_1181_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_scale_1174_);
v___x_1182_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1180_, v___x_1181_);
lean_dec_ref(v___x_1180_);
return v___x_1182_;
}
else
{
lean_dec_ref(v_scale_1174_);
lean_dec_ref(v_median_1173_);
lean_dec_ref(v_value_1172_);
return v___x_1175_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScoreField(lean_object* v_value_1183_, lean_object* v_score_1184_){
_start:
{
if (lean_obj_tag(v_value_1183_) == 0)
{
lean_object* v___x_1185_; 
lean_dec_ref(v_score_1184_);
v___x_1185_ = lean_box(0);
return v___x_1185_;
}
else
{
lean_object* v_val_1186_; lean_object* v___x_1187_; lean_object* v___x_1188_; lean_object* v___x_1189_; 
v_val_1186_ = lean_ctor_get(v_value_1183_, 0);
lean_inc(v_val_1186_);
lean_dec_ref_known(v_value_1183_, 1);
v___x_1187_ = lean_apply_1(v_score_1184_, v_val_1186_);
v___x_1188_ = lean_box(0);
v___x_1189_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1189_, 0, v___x_1187_);
lean_ctor_set(v___x_1189_, 1, v___x_1188_);
return v___x_1189_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1190_; lean_object* v___x_1191_; 
v___x_1190_ = lean_unsigned_to_nat(142u);
v___x_1191_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1190_);
return v___x_1191_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1(void){
_start:
{
lean_object* v___x_1192_; lean_object* v___x_1193_; 
v___x_1192_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0);
v___x_1193_ = l_Rat_neg(v___x_1192_);
return v___x_1193_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2(void){
_start:
{
lean_object* v___x_1194_; lean_object* v___x_1195_; lean_object* v___x_1196_; 
v___x_1194_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1195_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1);
v___x_1196_ = l_Rat_div(v___x_1195_, v___x_1194_);
return v___x_1196_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3(void){
_start:
{
lean_object* v___x_1197_; lean_object* v___x_1198_; 
v___x_1197_ = lean_unsigned_to_nat(164u);
v___x_1198_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1197_);
return v___x_1198_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4(void){
_start:
{
lean_object* v___x_1199_; lean_object* v___x_1200_; lean_object* v___x_1201_; 
v___x_1199_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1200_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3);
v___x_1201_ = l_Rat_div(v___x_1200_, v___x_1199_);
return v___x_1201_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0(lean_object* v_x_1202_){
_start:
{
lean_object* v___x_1203_; lean_object* v___x_1204_; lean_object* v___x_1205_; 
v___x_1203_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2);
v___x_1204_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4);
v___x_1205_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1202_, v___x_1203_, v___x_1204_);
return v___x_1205_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0(void){
_start:
{
lean_object* v___x_1206_; lean_object* v___x_1207_; 
v___x_1206_ = lean_unsigned_to_nat(393u);
v___x_1207_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1206_);
return v___x_1207_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1(void){
_start:
{
lean_object* v___x_1208_; lean_object* v___x_1209_; 
v___x_1208_ = lean_unsigned_to_nat(290u);
v___x_1209_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1208_);
return v___x_1209_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1(lean_object* v_x_1210_){
_start:
{
lean_object* v___x_1211_; lean_object* v___x_1212_; lean_object* v___x_1213_; 
v___x_1211_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0);
v___x_1212_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1);
v___x_1213_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1210_, v___x_1211_, v___x_1212_);
return v___x_1213_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0(void){
_start:
{
lean_object* v___x_1214_; lean_object* v___x_1215_; 
v___x_1214_ = lean_unsigned_to_nat(52u);
v___x_1215_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1214_);
return v___x_1215_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1(void){
_start:
{
lean_object* v___x_1216_; lean_object* v___x_1217_; 
v___x_1216_ = lean_unsigned_to_nat(29u);
v___x_1217_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1216_);
return v___x_1217_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2(lean_object* v_x_1218_){
_start:
{
lean_object* v___x_1219_; lean_object* v___x_1220_; lean_object* v___x_1221_; 
v___x_1219_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0);
v___x_1220_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1);
v___x_1221_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1218_, v___x_1219_, v___x_1220_);
return v___x_1221_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0(void){
_start:
{
lean_object* v___x_1222_; lean_object* v___x_1223_; 
v___x_1222_ = lean_unsigned_to_nat(272u);
v___x_1223_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1222_);
return v___x_1223_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1(void){
_start:
{
lean_object* v___x_1224_; lean_object* v___x_1225_; 
v___x_1224_ = lean_unsigned_to_nat(55u);
v___x_1225_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1224_);
return v___x_1225_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4(lean_object* v_x_1226_){
_start:
{
lean_object* v___x_1227_; lean_object* v___x_1228_; lean_object* v___x_1229_; 
v___x_1227_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0);
v___x_1228_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1);
v___x_1229_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1226_, v___x_1227_, v___x_1228_);
return v___x_1229_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0(void){
_start:
{
lean_object* v___x_1230_; lean_object* v___x_1231_; 
v___x_1230_ = lean_unsigned_to_nat(69u);
v___x_1231_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1230_);
return v___x_1231_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1(void){
_start:
{
lean_object* v___x_1232_; lean_object* v___x_1233_; 
v___x_1232_ = lean_unsigned_to_nat(100u);
v___x_1233_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1232_);
return v___x_1233_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2(void){
_start:
{
lean_object* v___x_1234_; lean_object* v___x_1235_; lean_object* v___x_1236_; 
v___x_1234_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1235_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0);
v___x_1236_ = l_Rat_div(v___x_1235_, v___x_1234_);
return v___x_1236_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3(void){
_start:
{
lean_object* v___x_1237_; lean_object* v___x_1238_; 
v___x_1237_ = lean_unsigned_to_nat(21u);
v___x_1238_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1237_);
return v___x_1238_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4(void){
_start:
{
lean_object* v___x_1239_; lean_object* v___x_1240_; lean_object* v___x_1241_; 
v___x_1239_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1240_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3);
v___x_1241_ = l_Rat_div(v___x_1240_, v___x_1239_);
return v___x_1241_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3(lean_object* v_x_1242_){
_start:
{
lean_object* v___x_1243_; lean_object* v___x_1244_; lean_object* v___x_1245_; 
v___x_1243_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2);
v___x_1244_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4);
v___x_1245_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1242_, v___x_1243_, v___x_1244_);
return v___x_1245_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0(void){
_start:
{
lean_object* v___x_1246_; lean_object* v___x_1247_; 
v___x_1246_ = lean_unsigned_to_nat(298u);
v___x_1247_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1246_);
return v___x_1247_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1(void){
_start:
{
lean_object* v___x_1248_; lean_object* v___x_1249_; 
v___x_1248_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0);
v___x_1249_ = l_Rat_neg(v___x_1248_);
return v___x_1249_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2(void){
_start:
{
lean_object* v___x_1250_; lean_object* v___x_1251_; 
v___x_1250_ = lean_unsigned_to_nat(1669u);
v___x_1251_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1250_);
return v___x_1251_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5(lean_object* v_x_1252_){
_start:
{
lean_object* v___x_1253_; lean_object* v___x_1254_; lean_object* v___x_1255_; 
v___x_1253_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1);
v___x_1254_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2);
v___x_1255_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1252_, v___x_1253_, v___x_1254_);
return v___x_1255_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0(void){
_start:
{
lean_object* v___x_1256_; lean_object* v___x_1257_; 
v___x_1256_ = lean_unsigned_to_nat(418u);
v___x_1257_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1256_);
return v___x_1257_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1(void){
_start:
{
lean_object* v___x_1258_; lean_object* v___x_1259_; 
v___x_1258_ = lean_unsigned_to_nat(129u);
v___x_1259_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1258_);
return v___x_1259_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6(lean_object* v_x_1260_){
_start:
{
lean_object* v___x_1261_; lean_object* v___x_1262_; lean_object* v___x_1263_; 
v___x_1261_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0);
v___x_1262_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1);
v___x_1263_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1260_, v___x_1261_, v___x_1262_);
return v___x_1263_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0(void){
_start:
{
lean_object* v___x_1264_; lean_object* v___x_1265_; 
v___x_1264_ = lean_unsigned_to_nat(413u);
v___x_1265_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1264_);
return v___x_1265_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1(void){
_start:
{
lean_object* v___x_1266_; lean_object* v___x_1267_; 
v___x_1266_ = lean_unsigned_to_nat(120u);
v___x_1267_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1266_);
return v___x_1267_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7(lean_object* v_x_1268_){
_start:
{
lean_object* v___x_1269_; lean_object* v___x_1270_; lean_object* v___x_1271_; 
v___x_1269_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0);
v___x_1270_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1);
v___x_1271_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1268_, v___x_1269_, v___x_1270_);
return v___x_1271_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0(void){
_start:
{
lean_object* v___x_1272_; lean_object* v___x_1273_; 
v___x_1272_ = lean_unsigned_to_nat(70u);
v___x_1273_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1272_);
return v___x_1273_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1(void){
_start:
{
lean_object* v___x_1274_; lean_object* v___x_1275_; lean_object* v___x_1276_; 
v___x_1274_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1275_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0);
v___x_1276_ = l_Rat_div(v___x_1275_, v___x_1274_);
return v___x_1276_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8(lean_object* v_x_1277_){
_start:
{
lean_object* v___x_1278_; lean_object* v___x_1279_; lean_object* v___x_1280_; 
v___x_1278_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1279_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1);
v___x_1280_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1277_, v___x_1278_, v___x_1279_);
return v___x_1280_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__9(lean_object* v_x_1281_){
_start:
{
lean_object* v___x_1282_; lean_object* v___x_1283_; lean_object* v___x_1284_; 
v___x_1282_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1283_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1284_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1281_, v___x_1282_, v___x_1283_);
return v___x_1284_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0(void){
_start:
{
lean_object* v___x_1285_; lean_object* v___x_1286_; 
v___x_1285_ = lean_unsigned_to_nat(24688u);
v___x_1286_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1285_);
return v___x_1286_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1(void){
_start:
{
lean_object* v___x_1287_; lean_object* v___x_1288_; 
v___x_1287_ = lean_unsigned_to_nat(10844u);
v___x_1288_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1287_);
return v___x_1288_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10(lean_object* v_x_1289_){
_start:
{
lean_object* v___x_1290_; lean_object* v___x_1291_; lean_object* v___x_1292_; 
v___x_1290_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0);
v___x_1291_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1);
v___x_1292_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1289_, v___x_1290_, v___x_1291_);
return v___x_1292_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0(void){
_start:
{
lean_object* v___x_1293_; lean_object* v___x_1294_; 
v___x_1293_ = lean_unsigned_to_nat(10132u);
v___x_1294_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1293_);
return v___x_1294_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1(void){
_start:
{
lean_object* v___x_1295_; lean_object* v___x_1296_; lean_object* v___x_1297_; 
v___x_1295_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1296_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0);
v___x_1297_ = l_Rat_div(v___x_1296_, v___x_1295_);
return v___x_1297_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2(void){
_start:
{
lean_object* v___x_1298_; lean_object* v___x_1299_; 
v___x_1298_ = lean_unsigned_to_nat(54u);
v___x_1299_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1298_);
return v___x_1299_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3(void){
_start:
{
lean_object* v___x_1300_; lean_object* v___x_1301_; lean_object* v___x_1302_; 
v___x_1300_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1301_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2);
v___x_1302_ = l_Rat_div(v___x_1301_, v___x_1300_);
return v___x_1302_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11(lean_object* v_x_1303_){
_start:
{
lean_object* v___x_1304_; lean_object* v___x_1305_; lean_object* v___x_1306_; 
v___x_1304_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1);
v___x_1305_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3);
v___x_1306_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1303_, v___x_1304_, v___x_1305_);
return v___x_1306_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5(void){
_start:
{
lean_object* v___x_1312_; lean_object* v___x_1313_; 
v___x_1312_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3);
v___x_1313_ = l_Rat_neg(v___x_1312_);
return v___x_1313_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6(void){
_start:
{
lean_object* v___x_1314_; lean_object* v___x_1315_; 
v___x_1314_ = lean_unsigned_to_nat(990u);
v___x_1315_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1314_);
return v___x_1315_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7(void){
_start:
{
lean_object* v___x_1316_; lean_object* v___x_1317_; lean_object* v___x_1318_; 
v___x_1316_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1317_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6);
v___x_1318_ = l_Rat_div(v___x_1317_, v___x_1316_);
return v___x_1318_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms(lean_object* v_register_1336_, lean_object* v_word_1337_){
_start:
{
lean_object* v___x_1338_; uint8_t v___x_1339_; 
v___x_1338_ = lean_unsigned_to_nat(64u);
v___x_1339_ = lean_nat_dec_eq(v_register_1336_, v___x_1338_);
if (v___x_1339_ == 0)
{
lean_object* v___x_1340_; uint8_t v___x_1341_; 
v___x_1340_ = lean_unsigned_to_nat(80u);
v___x_1341_ = lean_nat_dec_eq(v_register_1336_, v___x_1340_);
if (v___x_1341_ == 0)
{
lean_object* v___x_1342_; uint8_t v___x_1343_; 
v___x_1342_ = lean_unsigned_to_nat(96u);
v___x_1343_ = lean_nat_dec_eq(v_register_1336_, v___x_1342_);
if (v___x_1343_ == 0)
{
lean_object* v___x_1344_; uint8_t v___x_1345_; 
v___x_1344_ = lean_unsigned_to_nat(68u);
v___x_1345_ = lean_nat_dec_eq(v_register_1336_, v___x_1344_);
if (v___x_1345_ == 0)
{
lean_object* v___x_1346_; uint8_t v___x_1347_; 
v___x_1346_ = lean_unsigned_to_nat(69u);
v___x_1347_ = lean_nat_dec_eq(v_register_1336_, v___x_1346_);
if (v___x_1347_ == 0)
{
lean_object* v___x_1348_; 
v___x_1348_ = lean_box(0);
return v___x_1348_;
}
else
{
lean_object* v___f_1349_; lean_object* v___f_1350_; lean_object* v___x_1351_; lean_object* v___x_1352_; lean_object* v___x_1353_; lean_object* v___x_1354_; lean_object* v___x_1355_; lean_object* v___x_1356_; lean_object* v___x_1357_; 
v___f_1349_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__0));
v___f_1350_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1));
v___x_1351_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__2));
v___x_1352_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1351_);
v___x_1353_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1352_, v___f_1349_);
v___x_1354_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__3));
v___x_1355_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1354_);
v___x_1356_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1355_, v___f_1350_);
v___x_1357_ = l_List_appendTR___redArg(v___x_1353_, v___x_1356_);
return v___x_1357_;
}
}
else
{
lean_object* v___f_1358_; lean_object* v___f_1359_; lean_object* v___x_1360_; lean_object* v___x_1361_; lean_object* v___x_1362_; lean_object* v___x_1363_; lean_object* v___x_1364_; lean_object* v___x_1365_; lean_object* v___x_1366_; lean_object* v___x_1367_; lean_object* v___x_1368_; lean_object* v___x_1369_; lean_object* v___x_1370_; lean_object* v___x_1371_; lean_object* v___x_1372_; lean_object* v___x_1373_; 
v___f_1358_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__4));
v___f_1359_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1));
v___x_1360_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_1337_);
v___x_1361_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5);
v___x_1362_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7);
v___x_1363_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1360_, v___x_1361_, v___x_1362_);
v___x_1364_ = lean_box(0);
v___x_1365_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1365_, 0, v___x_1363_);
lean_ctor_set(v___x_1365_, 1, v___x_1364_);
v___x_1366_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__8));
v___x_1367_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1366_);
v___x_1368_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1367_, v___f_1358_);
v___x_1369_ = l_List_appendTR___redArg(v___x_1365_, v___x_1368_);
v___x_1370_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__9));
v___x_1371_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1370_);
v___x_1372_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1371_, v___f_1359_);
v___x_1373_ = l_List_appendTR___redArg(v___x_1369_, v___x_1372_);
return v___x_1373_;
}
}
else
{
lean_object* v___f_1374_; lean_object* v___f_1375_; lean_object* v___f_1376_; lean_object* v___x_1377_; lean_object* v___x_1378_; lean_object* v___x_1379_; lean_object* v___y_1381_; lean_object* v___x_1388_; lean_object* v___x_1389_; 
v___f_1374_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__10));
v___f_1375_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__11));
v___f_1376_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__12));
v___x_1377_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13));
v___x_1378_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1377_);
v___x_1379_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1378_, v___f_1374_);
v___x_1388_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14));
v___x_1389_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1388_);
if (lean_obj_tag(v___x_1389_) == 0)
{
v___y_1381_ = v___x_1389_;
goto v___jp_1380_;
}
else
{
lean_object* v___x_1391_; uint8_t v_isShared_1392_; uint8_t v_isSharedCheck_1397_; 
v_isSharedCheck_1397_ = !lean_is_exclusive(v___x_1389_);
if (v_isSharedCheck_1397_ == 0)
{
lean_object* v_unused_1398_; 
v_unused_1398_ = lean_ctor_get(v___x_1389_, 0);
lean_dec(v_unused_1398_);
v___x_1391_ = v___x_1389_;
v_isShared_1392_ = v_isSharedCheck_1397_;
goto v_resetjp_1390_;
}
else
{
lean_dec(v___x_1389_);
v___x_1391_ = lean_box(0);
v_isShared_1392_ = v_isSharedCheck_1397_;
goto v_resetjp_1390_;
}
v_resetjp_1390_:
{
lean_object* v___x_1393_; lean_object* v___x_1395_; 
v___x_1393_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_1337_);
if (v_isShared_1392_ == 0)
{
lean_ctor_set(v___x_1391_, 0, v___x_1393_);
v___x_1395_ = v___x_1391_;
goto v_reusejp_1394_;
}
else
{
lean_object* v_reuseFailAlloc_1396_; 
v_reuseFailAlloc_1396_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1396_, 0, v___x_1393_);
v___x_1395_ = v_reuseFailAlloc_1396_;
goto v_reusejp_1394_;
}
v_reusejp_1394_:
{
v___y_1381_ = v___x_1395_;
goto v___jp_1380_;
}
}
}
v___jp_1380_:
{
lean_object* v___x_1382_; lean_object* v___x_1383_; lean_object* v___x_1384_; lean_object* v___x_1385_; lean_object* v___x_1386_; lean_object* v___x_1387_; 
v___x_1382_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___y_1381_, v___f_1375_);
v___x_1383_ = l_List_appendTR___redArg(v___x_1379_, v___x_1382_);
v___x_1384_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__2));
v___x_1385_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1384_);
v___x_1386_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1385_, v___f_1376_);
v___x_1387_ = l_List_appendTR___redArg(v___x_1383_, v___x_1386_);
return v___x_1387_;
}
}
}
else
{
lean_object* v___f_1399_; lean_object* v___f_1400_; lean_object* v___f_1401_; lean_object* v___f_1402_; lean_object* v___x_1403_; lean_object* v___x_1404_; lean_object* v___x_1405_; lean_object* v___x_1406_; lean_object* v___x_1407_; lean_object* v___x_1408_; lean_object* v___x_1409_; lean_object* v___x_1410_; lean_object* v___x_1411_; lean_object* v___x_1412_; lean_object* v___x_1413_; lean_object* v___x_1414_; lean_object* v___x_1415_; lean_object* v___x_1416_; lean_object* v___x_1417_; 
v___f_1399_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__15));
v___f_1400_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__16));
v___f_1401_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__17));
v___f_1402_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__18));
v___x_1403_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19));
v___x_1404_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1403_);
v___x_1405_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1404_, v___f_1402_);
v___x_1406_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__4));
v___x_1407_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1406_);
v___x_1408_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1407_, v___f_1401_);
v___x_1409_ = l_List_appendTR___redArg(v___x_1405_, v___x_1408_);
v___x_1410_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__20));
v___x_1411_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1410_);
v___x_1412_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1411_, v___f_1400_);
v___x_1413_ = l_List_appendTR___redArg(v___x_1409_, v___x_1412_);
v___x_1414_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__21));
v___x_1415_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1414_);
v___x_1416_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1415_, v___f_1399_);
v___x_1417_ = l_List_appendTR___redArg(v___x_1413_, v___x_1416_);
return v___x_1417_;
}
}
else
{
lean_object* v___f_1418_; lean_object* v___f_1419_; lean_object* v___y_1421_; lean_object* v___x_1431_; lean_object* v___x_1432_; 
v___f_1418_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__22));
v___f_1419_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__23));
v___x_1431_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__24));
v___x_1432_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1431_);
if (lean_obj_tag(v___x_1432_) == 0)
{
v___y_1421_ = v___x_1432_;
goto v___jp_1420_;
}
else
{
lean_object* v___x_1434_; uint8_t v_isShared_1435_; uint8_t v_isSharedCheck_1440_; 
v_isSharedCheck_1440_ = !lean_is_exclusive(v___x_1432_);
if (v_isSharedCheck_1440_ == 0)
{
lean_object* v_unused_1441_; 
v_unused_1441_ = lean_ctor_get(v___x_1432_, 0);
lean_dec(v_unused_1441_);
v___x_1434_ = v___x_1432_;
v_isShared_1435_ = v_isSharedCheck_1440_;
goto v_resetjp_1433_;
}
else
{
lean_dec(v___x_1432_);
v___x_1434_ = lean_box(0);
v_isShared_1435_ = v_isSharedCheck_1440_;
goto v_resetjp_1433_;
}
v_resetjp_1433_:
{
lean_object* v___x_1436_; lean_object* v___x_1438_; 
v___x_1436_ = lp_lean1090_Lean1090_Impl_cbQNH64(v_word_1337_);
if (v_isShared_1435_ == 0)
{
lean_ctor_set(v___x_1434_, 0, v___x_1436_);
v___x_1438_ = v___x_1434_;
goto v_reusejp_1437_;
}
else
{
lean_object* v_reuseFailAlloc_1439_; 
v_reuseFailAlloc_1439_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1439_, 0, v___x_1436_);
v___x_1438_ = v_reuseFailAlloc_1439_;
goto v_reusejp_1437_;
}
v_reusejp_1437_:
{
v___y_1421_ = v___x_1438_;
goto v___jp_1420_;
}
}
}
v___jp_1420_:
{
lean_object* v___x_1422_; lean_object* v___x_1423_; lean_object* v___x_1424_; lean_object* v___x_1425_; lean_object* v___x_1426_; lean_object* v___x_1427_; lean_object* v___x_1428_; lean_object* v___x_1429_; lean_object* v___x_1430_; 
v___x_1422_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___y_1421_, v___f_1419_);
v___x_1423_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__6));
v___x_1424_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1423_);
v___x_1425_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1424_, v___f_1418_);
v___x_1426_ = l_List_appendTR___redArg(v___x_1422_, v___x_1425_);
v___x_1427_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__7));
v___x_1428_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1336_, v_word_1337_, v___x_1427_);
v___x_1429_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1428_, v___f_1418_);
v___x_1430_ = l_List_appendTR___redArg(v___x_1426_, v___x_1429_);
return v___x_1430_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___boxed(lean_object* v_register_1442_, lean_object* v_word_1443_){
_start:
{
lean_object* v_res_1444_; 
v_res_1444_ = lp_lean1090_Lean1090_Impl_cbDensityTerms(v_register_1442_, v_word_1443_);
lean_dec(v_word_1443_);
lean_dec(v_register_1442_);
return v_res_1444_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_cbDensity_spec__0(lean_object* v_x_1445_, lean_object* v_x_1446_){
_start:
{
if (lean_obj_tag(v_x_1446_) == 0)
{
return v_x_1445_;
}
else
{
lean_object* v_head_1447_; lean_object* v_tail_1448_; lean_object* v___x_1449_; 
v_head_1447_ = lean_ctor_get(v_x_1446_, 0);
lean_inc(v_head_1447_);
v_tail_1448_ = lean_ctor_get(v_x_1446_, 1);
lean_inc(v_tail_1448_);
lean_dec_ref_known(v_x_1446_, 2);
v___x_1449_ = lp_lean1090_Lean1090_Impl_Binary64_add(v_x_1445_, v_head_1447_);
v_x_1445_ = v___x_1449_;
v_x_1446_ = v_tail_1448_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensity(lean_object* v_register_1451_, lean_object* v_word_1452_){
_start:
{
lean_object* v_terms_1453_; uint8_t v___x_1454_; 
v_terms_1453_ = lp_lean1090_Lean1090_Impl_cbDensityTerms(v_register_1451_, v_word_1452_);
v___x_1454_ = l_List_isEmpty___redArg(v_terms_1453_);
if (v___x_1454_ == 0)
{
lean_object* v___x_1455_; lean_object* v___x_1456_; lean_object* v___x_1457_; lean_object* v___x_1458_; lean_object* v___x_1459_; 
v___x_1455_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc(v_terms_1453_);
v___x_1456_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_cbDensity_spec__0(v___x_1455_, v_terms_1453_);
v___x_1457_ = l_List_lengthTR___redArg(v_terms_1453_);
lean_dec(v_terms_1453_);
v___x_1458_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1457_);
v___x_1459_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1456_, v___x_1458_);
lean_dec_ref(v___x_1456_);
return v___x_1459_;
}
else
{
lean_object* v___x_1460_; 
lean_dec(v_terms_1453_);
v___x_1460_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1460_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensity___boxed(lean_object* v_register_1461_, lean_object* v_word_1462_){
_start:
{
lean_object* v_res_1463_; 
v_res_1463_ = lp_lean1090_Lean1090_Impl_cbDensity(v_register_1461_, v_word_1462_);
lean_dec(v_word_1462_);
lean_dec(v_register_1461_);
return v_res_1463_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0(void){
_start:
{
lean_object* v___x_1464_; lean_object* v___x_1465_; 
v___x_1464_ = lean_unsigned_to_nat(5u);
v___x_1465_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1464_);
return v___x_1465_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1(void){
_start:
{
lean_object* v___x_1466_; lean_object* v___x_1467_; 
v___x_1466_ = lean_unsigned_to_nat(3u);
v___x_1467_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1466_);
return v___x_1467_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__2(void){
_start:
{
lean_object* v___x_1468_; lean_object* v___x_1469_; lean_object* v___x_1470_; 
v___x_1468_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1469_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__1, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1);
v___x_1470_ = l_Rat_div(v___x_1469_, v___x_1468_);
return v___x_1470_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__3(void){
_start:
{
lean_object* v___x_1471_; lean_object* v___x_1472_; 
v___x_1471_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__2, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__2);
v___x_1472_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_1471_);
return v___x_1472_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__4(void){
_start:
{
lean_object* v___x_1473_; lean_object* v___x_1474_; 
v___x_1473_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__1, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1);
v___x_1474_ = l_Rat_neg(v___x_1473_);
return v___x_1474_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__5(void){
_start:
{
lean_object* v___x_1475_; lean_object* v___x_1476_; 
v___x_1475_ = lean_unsigned_to_nat(250u);
v___x_1476_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1475_);
return v___x_1476_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPenalty(lean_object* v_register_1477_, lean_object* v_word_1478_){
_start:
{
lean_object* v___y_1482_; uint8_t v___y_1483_; lean_object* v___y_1487_; lean_object* v___y_1488_; lean_object* v___y_1489_; uint8_t v___y_1490_; lean_object* v___y_1495_; lean_object* v___x_1510_; uint8_t v___x_1511_; 
v___x_1510_ = lean_unsigned_to_nat(80u);
v___x_1511_ = lean_nat_dec_eq(v_register_1477_, v___x_1510_);
if (v___x_1511_ == 0)
{
lean_object* v___x_1512_; uint8_t v___x_1513_; 
v___x_1512_ = lean_unsigned_to_nat(96u);
v___x_1513_ = lean_nat_dec_eq(v_register_1477_, v___x_1512_);
if (v___x_1513_ == 0)
{
lean_object* v___x_1514_; 
v___x_1514_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1514_;
}
else
{
lean_object* v___x_1515_; lean_object* v___x_1516_; 
v___x_1515_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13));
v___x_1516_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1477_, v_word_1478_, v___x_1515_);
if (lean_obj_tag(v___x_1516_) == 1)
{
lean_object* v_val_1517_; lean_object* v___x_1518_; lean_object* v___x_1519_; 
v_val_1517_ = lean_ctor_get(v___x_1516_, 0);
lean_inc(v_val_1517_);
lean_dec_ref_known(v___x_1516_, 1);
v___x_1518_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14));
v___x_1519_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1477_, v_word_1478_, v___x_1518_);
if (lean_obj_tag(v___x_1519_) == 1)
{
lean_object* v_mach_1520_; lean_object* v___x_1521_; uint8_t v___y_1523_; uint8_t v___x_1525_; uint8_t v___y_1527_; 
lean_dec_ref_known(v___x_1519_, 1);
v_mach_1520_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_1478_);
v___x_1521_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_mach_1520_);
v___x_1525_ = l_Rat_blt(v___x_1521_, v_mach_1520_);
if (v___x_1525_ == 0)
{
lean_dec_ref(v_mach_1520_);
lean_dec(v_val_1517_);
return v___x_1521_;
}
else
{
lean_object* v_ratio_1528_; lean_object* v___x_1529_; uint8_t v___x_1530_; 
v_ratio_1528_ = lp_lean1090_Lean1090_Impl_Binary64_div(v_val_1517_, v_mach_1520_);
lean_dec(v_val_1517_);
v___x_1529_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__5, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__5);
lean_inc_ref(v_ratio_1528_);
v___x_1530_ = l_Rat_blt(v_ratio_1528_, v___x_1529_);
if (v___x_1530_ == 0)
{
lean_object* v___x_1531_; uint8_t v___x_1532_; 
v___x_1531_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__4, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__4);
v___x_1532_ = l_Rat_blt(v___x_1531_, v_ratio_1528_);
v___y_1527_ = v___x_1532_;
goto v___jp_1526_;
}
else
{
lean_dec_ref(v_ratio_1528_);
v___y_1527_ = v___x_1525_;
goto v___jp_1526_;
}
}
v___jp_1522_:
{
if (v___y_1523_ == 0)
{
return v___x_1521_;
}
else
{
lean_object* v___x_1524_; 
v___x_1524_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__4, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__4);
return v___x_1524_;
}
}
v___jp_1526_:
{
if (v___x_1525_ == 0)
{
v___y_1523_ = v___x_1525_;
goto v___jp_1522_;
}
else
{
v___y_1523_ = v___y_1527_;
goto v___jp_1522_;
}
}
}
else
{
lean_dec(v___x_1519_);
lean_dec(v_val_1517_);
goto v___jp_1479_;
}
}
else
{
lean_dec(v___x_1516_);
goto v___jp_1479_;
}
}
}
else
{
lean_object* v___x_1533_; lean_object* v___x_1534_; 
v___x_1533_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__20));
v___x_1534_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1477_, v_word_1478_, v___x_1533_);
if (lean_obj_tag(v___x_1534_) == 1)
{
lean_object* v_val_1535_; lean_object* v___x_1536_; lean_object* v___x_1537_; 
v_val_1535_ = lean_ctor_get(v___x_1534_, 0);
lean_inc(v_val_1535_);
lean_dec_ref_known(v___x_1534_, 1);
v___x_1536_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__21));
v___x_1537_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1477_, v_word_1478_, v___x_1536_);
if (lean_obj_tag(v___x_1537_) == 1)
{
lean_object* v_val_1538_; lean_object* v___x_1539_; lean_object* v___x_1540_; lean_object* v___x_1541_; lean_object* v___x_1542_; lean_object* v___x_1543_; lean_object* v___x_1544_; 
v_val_1538_ = lean_ctor_get(v___x_1537_, 0);
lean_inc(v_val_1538_);
lean_dec_ref_known(v___x_1537_, 1);
v___x_1539_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1540_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_val_1535_, v_val_1538_);
v___x_1541_ = l_Rat_abs(v___x_1540_);
v___x_1542_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1543_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1541_, v___x_1542_);
lean_dec_ref(v___x_1541_);
v___x_1544_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v___x_1539_, v___x_1543_);
v___y_1495_ = v___x_1544_;
goto v___jp_1494_;
}
else
{
lean_dec(v___x_1537_);
lean_dec(v_val_1535_);
goto v___jp_1508_;
}
}
else
{
lean_dec(v___x_1534_);
goto v___jp_1508_;
}
}
v___jp_1479_:
{
lean_object* v___x_1480_; 
v___x_1480_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1480_;
}
v___jp_1481_:
{
if (v___y_1483_ == 0)
{
lean_object* v___x_1484_; lean_object* v___x_1485_; 
v___x_1484_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1485_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v___y_1482_, v___x_1484_);
return v___x_1485_;
}
else
{
return v___y_1482_;
}
}
v___jp_1486_:
{
if (v___y_1490_ == 0)
{
lean_dec_ref(v___y_1489_);
lean_dec_ref(v___y_1487_);
return v___y_1488_;
}
else
{
lean_object* v___x_1491_; uint8_t v___x_1492_; uint8_t v___x_1493_; 
v___x_1491_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1492_ = l_Rat_blt(v___x_1491_, v___y_1487_);
v___x_1493_ = l_Rat_blt(v___x_1491_, v___y_1489_);
if (v___x_1493_ == 0)
{
if (v___x_1492_ == 0)
{
return v___y_1488_;
}
else
{
v___y_1482_ = v___y_1488_;
v___y_1483_ = v___x_1493_;
goto v___jp_1481_;
}
}
else
{
v___y_1482_ = v___y_1488_;
v___y_1483_ = v___x_1492_;
goto v___jp_1481_;
}
}
}
v___jp_1494_:
{
lean_object* v___x_1496_; lean_object* v___x_1497_; 
v___x_1496_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19));
v___x_1497_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1477_, v_word_1478_, v___x_1496_);
if (lean_obj_tag(v___x_1497_) == 1)
{
lean_object* v_val_1498_; lean_object* v___x_1499_; lean_object* v___x_1500_; 
v_val_1498_ = lean_ctor_get(v___x_1497_, 0);
lean_inc(v_val_1498_);
lean_dec_ref_known(v___x_1497_, 1);
v___x_1499_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__4));
v___x_1500_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1477_, v_word_1478_, v___x_1499_);
if (lean_obj_tag(v___x_1500_) == 1)
{
lean_object* v_val_1501_; lean_object* v___x_1502_; lean_object* v___x_1503_; uint8_t v___x_1504_; 
v_val_1501_ = lean_ctor_get(v___x_1500_, 0);
lean_inc(v_val_1501_);
lean_dec_ref_known(v___x_1500_, 1);
v___x_1502_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__0, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0);
lean_inc(v_val_1498_);
v___x_1503_ = l_Rat_abs(v_val_1498_);
v___x_1504_ = l_Rat_blt(v___x_1502_, v___x_1503_);
if (v___x_1504_ == 0)
{
v___y_1487_ = v_val_1498_;
v___y_1488_ = v___y_1495_;
v___y_1489_ = v_val_1501_;
v___y_1490_ = v___x_1504_;
goto v___jp_1486_;
}
else
{
lean_object* v___x_1505_; lean_object* v___x_1506_; uint8_t v___x_1507_; 
v___x_1505_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__3, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__3);
lean_inc(v_val_1501_);
v___x_1506_ = l_Rat_abs(v_val_1501_);
v___x_1507_ = l_Rat_blt(v___x_1505_, v___x_1506_);
v___y_1487_ = v_val_1498_;
v___y_1488_ = v___y_1495_;
v___y_1489_ = v_val_1501_;
v___y_1490_ = v___x_1507_;
goto v___jp_1486_;
}
}
else
{
lean_dec(v___x_1500_);
lean_dec(v_val_1498_);
return v___y_1495_;
}
}
else
{
lean_dec(v___x_1497_);
return v___y_1495_;
}
}
v___jp_1508_:
{
lean_object* v___x_1509_; 
v___x_1509_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___y_1495_ = v___x_1509_;
goto v___jp_1494_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPenalty___boxed(lean_object* v_register_1545_, lean_object* v_word_1546_){
_start:
{
lean_object* v_res_1547_; 
v_res_1547_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_1545_, v_word_1546_);
lean_dec(v_word_1546_);
lean_dec(v_register_1545_);
return v_res_1547_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCombinedScore(lean_object* v_register_1548_, lean_object* v_word_1549_){
_start:
{
lean_object* v___x_1550_; lean_object* v___x_1551_; lean_object* v___x_1552_; 
v___x_1550_ = lp_lean1090_Lean1090_Impl_cbDensity(v_register_1548_, v_word_1549_);
v___x_1551_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_1548_, v_word_1549_);
v___x_1552_ = lp_lean1090_Lean1090_Impl_Binary64_add(v___x_1550_, v___x_1551_);
return v___x_1552_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCombinedScore___boxed(lean_object* v_register_1553_, lean_object* v_word_1554_){
_start:
{
lean_object* v_res_1555_; 
v_res_1555_ = lp_lean1090_Lean1090_Impl_cbCombinedScore(v_register_1553_, v_word_1554_);
lean_dec(v_word_1554_);
lean_dec(v_register_1553_);
return v_res_1555_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHScoreTable___lam__0(lean_object* v_code_1556_){
_start:
{
lean_object* v___x_1557_; lean_object* v___x_1558_; lean_object* v___x_1559_; lean_object* v___x_1560_; lean_object* v___x_1561_; lean_object* v___x_1562_; lean_object* v___x_1563_; lean_object* v___x_1564_; 
v___x_1557_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1556_);
v___x_1558_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__3, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__3);
v___x_1559_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1557_, v___x_1558_);
lean_dec_ref(v___x_1557_);
v___x_1560_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__4, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__4);
v___x_1561_ = lp_lean1090_Lean1090_Impl_Binary64_add(v___x_1559_, v___x_1560_);
v___x_1562_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1);
v___x_1563_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3);
v___x_1564_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1561_, v___x_1562_, v___x_1563_);
return v___x_1564_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1566_; lean_object* v___x_1567_; lean_object* v___x_1568_; 
v___f_1566_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__0));
v___x_1567_ = lean_unsigned_to_nat(4096u);
v___x_1568_ = l_Array_ofFn___redArg(v___x_1567_, v___f_1566_);
return v___x_1568_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable(void){
_start:
{
lean_object* v___x_1569_; 
v___x_1569_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1);
return v___x_1569_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0(lean_object* v_code_1570_){
_start:
{
lean_object* v___x_1571_; lean_object* v___x_1572_; lean_object* v___x_1573_; lean_object* v___x_1574_; 
v___x_1571_ = lp_lean1090_Lean1090_Impl_cbSelected(v_code_1570_);
v___x_1572_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0);
v___x_1573_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1);
v___x_1574_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1571_, v___x_1572_, v___x_1573_);
return v___x_1574_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0___boxed(lean_object* v_code_1575_){
_start:
{
lean_object* v_res_1576_; 
v_res_1576_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0(v_code_1575_);
lean_dec(v_code_1575_);
return v_res_1576_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1578_; lean_object* v___x_1579_; lean_object* v___x_1580_; 
v___f_1578_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__0));
v___x_1579_ = lean_unsigned_to_nat(4096u);
v___x_1580_ = l_Array_ofFn___redArg(v___x_1579_, v___f_1578_);
return v___x_1580_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable(void){
_start:
{
lean_object* v___x_1581_; 
v___x_1581_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1);
return v___x_1581_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1582_; lean_object* v___x_1583_; lean_object* v___x_1584_; 
v___x_1582_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1583_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid50___closed__0, &lp_lean1090_Lean1090_Impl_cbValid50___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid50___closed__0);
v___x_1584_ = l_Rat_div(v___x_1583_, v___x_1582_);
return v___x_1584_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0(lean_object* v_code_1585_){
_start:
{
uint8_t v___x_1586_; lean_object* v___x_1587_; lean_object* v___x_1588_; lean_object* v___x_1589_; lean_object* v___x_1590_; lean_object* v___x_1591_; lean_object* v___x_1592_; lean_object* v___x_1593_; lean_object* v___x_1594_; 
v___x_1586_ = 1;
v___x_1587_ = lean_unsigned_to_nat(10u);
v___x_1588_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1586_, v___x_1587_, v_code_1585_);
v___x_1589_ = l_Rat_ofInt(v___x_1588_);
v___x_1590_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0);
v___x_1591_ = l_Rat_mul(v___x_1589_, v___x_1590_);
lean_dec_ref(v___x_1589_);
v___x_1592_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1593_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1594_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1591_, v___x_1592_, v___x_1593_);
return v___x_1594_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1596_; lean_object* v___x_1597_; lean_object* v___x_1598_; 
v___f_1596_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__0));
v___x_1597_ = lean_unsigned_to_nat(1024u);
v___x_1598_ = l_Array_ofFn___redArg(v___x_1597_, v___f_1596_);
return v___x_1598_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable(void){
_start:
{
lean_object* v___x_1599_; 
v___x_1599_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1);
return v___x_1599_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1600_; lean_object* v___x_1601_; 
v___x_1600_ = lean_unsigned_to_nat(8u);
v___x_1601_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1600_);
return v___x_1601_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1(void){
_start:
{
lean_object* v___x_1602_; lean_object* v___x_1603_; lean_object* v___x_1604_; 
v___x_1602_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1603_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0);
v___x_1604_ = l_Rat_div(v___x_1603_, v___x_1602_);
return v___x_1604_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0(lean_object* v_code_1605_){
_start:
{
uint8_t v___x_1606_; lean_object* v___x_1607_; lean_object* v___x_1608_; lean_object* v___x_1609_; lean_object* v___x_1610_; lean_object* v___x_1611_; lean_object* v___x_1612_; lean_object* v___x_1613_; lean_object* v___x_1614_; 
v___x_1606_ = 1;
v___x_1607_ = lean_unsigned_to_nat(10u);
v___x_1608_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1606_, v___x_1607_, v_code_1605_);
v___x_1609_ = l_Rat_ofInt(v___x_1608_);
v___x_1610_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1);
v___x_1611_ = l_Rat_mul(v___x_1609_, v___x_1610_);
lean_dec_ref(v___x_1609_);
v___x_1612_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1613_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1);
v___x_1614_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1611_, v___x_1612_, v___x_1613_);
return v___x_1614_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1616_; lean_object* v___x_1617_; lean_object* v___x_1618_; 
v___f_1616_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__0));
v___x_1617_ = lean_unsigned_to_nat(1024u);
v___x_1618_ = l_Array_ofFn___redArg(v___x_1617_, v___f_1616_);
return v___x_1618_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable(void){
_start:
{
lean_object* v___x_1619_; 
v___x_1619_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1);
return v___x_1619_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTASScoreTable___lam__0(lean_object* v_code_1620_){
_start:
{
lean_object* v___x_1621_; lean_object* v___x_1622_; lean_object* v___x_1623_; lean_object* v___x_1624_; lean_object* v___x_1625_; lean_object* v___x_1626_; 
v___x_1621_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1620_);
v___x_1622_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1623_ = l_Rat_mul(v___x_1621_, v___x_1622_);
lean_dec_ref(v___x_1621_);
v___x_1624_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0);
v___x_1625_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1);
v___x_1626_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1623_, v___x_1624_, v___x_1625_);
return v___x_1626_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1628_; lean_object* v___x_1629_; lean_object* v___x_1630_; 
v___f_1628_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__0));
v___x_1629_ = lean_unsigned_to_nat(1024u);
v___x_1630_ = l_Array_ofFn___redArg(v___x_1629_, v___f_1628_);
return v___x_1630_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable(void){
_start:
{
lean_object* v___x_1631_; 
v___x_1631_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1);
return v___x_1631_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___lam__0(lean_object* v_code_1632_){
_start:
{
lean_object* v___x_1633_; lean_object* v___x_1634_; lean_object* v___x_1635_; lean_object* v___x_1636_; lean_object* v___x_1637_; lean_object* v___x_1638_; 
v___x_1633_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1632_);
v___x_1634_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1635_ = l_Rat_mul(v___x_1633_, v___x_1634_);
lean_dec_ref(v___x_1633_);
v___x_1636_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0);
v___x_1637_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1);
v___x_1638_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1635_, v___x_1636_, v___x_1637_);
return v___x_1638_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1640_; lean_object* v___x_1641_; lean_object* v___x_1642_; 
v___f_1640_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__0));
v___x_1641_ = lean_unsigned_to_nat(1024u);
v___x_1642_ = l_Array_ofFn___redArg(v___x_1641_, v___f_1640_);
return v___x_1642_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable(void){
_start:
{
lean_object* v___x_1643_; 
v___x_1643_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1);
return v___x_1643_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbIASScoreTable___lam__0(lean_object* v_code_1644_){
_start:
{
lean_object* v___x_1645_; lean_object* v___x_1646_; lean_object* v___x_1647_; lean_object* v___x_1648_; 
v___x_1645_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1644_);
v___x_1646_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0);
v___x_1647_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1);
v___x_1648_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1645_, v___x_1646_, v___x_1647_);
return v___x_1648_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1650_; lean_object* v___x_1651_; lean_object* v___x_1652_; 
v___f_1650_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__0));
v___x_1651_ = lean_unsigned_to_nat(1024u);
v___x_1652_ = l_Array_ofFn___redArg(v___x_1651_, v___f_1650_);
return v___x_1652_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable(void){
_start:
{
lean_object* v___x_1653_; 
v___x_1653_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1);
return v___x_1653_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachScoreTable___lam__0(lean_object* v_code_1654_){
_start:
{
lean_object* v___x_1655_; lean_object* v___x_1656_; lean_object* v___x_1657_; lean_object* v___x_1658_; lean_object* v___x_1659_; lean_object* v___x_1660_; lean_object* v___x_1661_; lean_object* v___x_1662_; 
v___x_1655_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1654_);
v___x_1656_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2);
v___x_1657_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1655_, v___x_1656_);
lean_dec_ref(v___x_1655_);
v___x_1658_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3);
v___x_1659_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1657_, v___x_1658_);
lean_dec_ref(v___x_1657_);
v___x_1660_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2);
v___x_1661_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4);
v___x_1662_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1659_, v___x_1660_, v___x_1661_);
return v___x_1662_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1664_; lean_object* v___x_1665_; lean_object* v___x_1666_; 
v___f_1664_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__0));
v___x_1665_ = lean_unsigned_to_nat(1024u);
v___x_1666_ = l_Array_ofFn___redArg(v___x_1665_, v___f_1664_);
return v___x_1666_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable(void){
_start:
{
lean_object* v___x_1667_; 
v___x_1667_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1);
return v___x_1667_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___lam__0(lean_object* v_code_1668_){
_start:
{
lean_object* v___y_1670_; lean_object* v___x_1674_; lean_object* v___x_1675_; lean_object* v___x_1676_; uint8_t v___x_1679_; 
v___x_1674_ = lean_unsigned_to_nat(512u);
v___x_1675_ = lean_nat_mod(v_code_1668_, v___x_1674_);
v___x_1676_ = lean_unsigned_to_nat(0u);
v___x_1679_ = lean_nat_dec_eq(v___x_1675_, v___x_1676_);
if (v___x_1679_ == 0)
{
lean_object* v___x_1680_; uint8_t v___x_1681_; 
v___x_1680_ = lean_unsigned_to_nat(511u);
v___x_1681_ = lean_nat_dec_eq(v___x_1675_, v___x_1680_);
lean_dec(v___x_1675_);
if (v___x_1681_ == 0)
{
uint8_t v___x_1682_; lean_object* v___x_1683_; lean_object* v___x_1684_; lean_object* v___x_1685_; lean_object* v___x_1686_; lean_object* v___x_1687_; 
v___x_1682_ = 1;
v___x_1683_ = lean_unsigned_to_nat(10u);
v___x_1684_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1682_, v___x_1683_, v_code_1668_);
v___x_1685_ = l_Rat_ofInt(v___x_1684_);
v___x_1686_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__0, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__0);
v___x_1687_ = l_Rat_mul(v___x_1685_, v___x_1686_);
lean_dec_ref(v___x_1685_);
v___y_1670_ = v___x_1687_;
goto v___jp_1669_;
}
else
{
lean_dec(v_code_1668_);
goto v___jp_1677_;
}
}
else
{
lean_dec(v___x_1675_);
lean_dec(v_code_1668_);
goto v___jp_1677_;
}
v___jp_1669_:
{
lean_object* v___x_1671_; lean_object* v___x_1672_; lean_object* v___x_1673_; 
v___x_1671_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1);
v___x_1672_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2);
v___x_1673_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___y_1670_, v___x_1671_, v___x_1672_);
return v___x_1673_;
}
v___jp_1677_:
{
lean_object* v___x_1678_; 
v___x_1678_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___y_1670_ = v___x_1678_;
goto v___jp_1669_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1689_; lean_object* v___x_1690_; lean_object* v___x_1691_; 
v___f_1689_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__0));
v___x_1690_ = lean_unsigned_to_nat(1024u);
v___x_1691_ = l_Array_ofFn___redArg(v___x_1690_, v___f_1689_);
return v___x_1691_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable(void){
_start:
{
lean_object* v___x_1692_; 
v___x_1692_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1);
return v___x_1692_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___lam__0(lean_object* v_code_1693_){
_start:
{
lean_object* v___y_1695_; uint8_t v___x_1699_; lean_object* v___x_1700_; lean_object* v___x_1701_; lean_object* v___x_1702_; lean_object* v___x_1703_; lean_object* v_initial_1704_; lean_object* v___x_1705_; uint8_t v___x_1706_; 
v___x_1699_ = 1;
v___x_1700_ = lean_unsigned_to_nat(11u);
v___x_1701_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1699_, v___x_1700_, v_code_1693_);
v___x_1702_ = l_Rat_ofInt(v___x_1701_);
v___x_1703_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v_initial_1704_ = l_Rat_div(v___x_1702_, v___x_1703_);
lean_dec_ref(v___x_1702_);
v___x_1705_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
lean_inc_ref(v_initial_1704_);
v___x_1706_ = l_Rat_blt(v_initial_1704_, v___x_1705_);
if (v___x_1706_ == 0)
{
v___y_1695_ = v_initial_1704_;
goto v___jp_1694_;
}
else
{
lean_object* v___x_1707_; lean_object* v___x_1708_; 
v___x_1707_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1708_ = l_Rat_add(v_initial_1704_, v___x_1707_);
v___y_1695_ = v___x_1708_;
goto v___jp_1694_;
}
v___jp_1694_:
{
lean_object* v___x_1696_; lean_object* v___x_1697_; lean_object* v___x_1698_; 
v___x_1696_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5);
v___x_1697_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7);
v___x_1698_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___y_1695_, v___x_1696_, v___x_1697_);
return v___x_1698_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1710_; lean_object* v___x_1711_; lean_object* v___x_1712_; 
v___f_1710_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__0));
v___x_1711_ = lean_unsigned_to_nat(2048u);
v___x_1712_ = l_Array_ofFn___redArg(v___x_1711_, v___f_1710_);
return v___x_1712_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable(void){
_start:
{
lean_object* v___x_1713_; 
v___x_1713_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1);
return v___x_1713_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindScoreTable___lam__0(lean_object* v_code_1714_){
_start:
{
lean_object* v___x_1715_; lean_object* v___x_1716_; lean_object* v___x_1717_; lean_object* v___x_1718_; 
v___x_1715_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1714_);
v___x_1716_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0);
v___x_1717_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1);
v___x_1718_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1715_, v___x_1716_, v___x_1717_);
return v___x_1718_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1720_; lean_object* v___x_1721_; lean_object* v___x_1722_; 
v___f_1720_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__0));
v___x_1721_ = lean_unsigned_to_nat(512u);
v___x_1722_ = l_Array_ofFn___redArg(v___x_1721_, v___f_1720_);
return v___x_1722_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable(void){
_start:
{
lean_object* v___x_1723_; 
v___x_1723_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1);
return v___x_1723_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPressureScoreTable___lam__0(lean_object* v_code_1724_){
_start:
{
lean_object* v___x_1725_; lean_object* v___x_1726_; lean_object* v___x_1727_; lean_object* v___x_1728_; 
v___x_1725_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1724_);
v___x_1726_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0);
v___x_1727_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1);
v___x_1728_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1725_, v___x_1726_, v___x_1727_);
return v___x_1728_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1730_; lean_object* v___x_1731_; lean_object* v___x_1732_; 
v___f_1730_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__0));
v___x_1731_ = lean_unsigned_to_nat(2048u);
v___x_1732_ = l_Array_ofFn___redArg(v___x_1731_, v___f_1730_);
return v___x_1732_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable(void){
_start:
{
lean_object* v___x_1733_; 
v___x_1733_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1);
return v___x_1733_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1734_; lean_object* v___x_1735_; lean_object* v___x_1736_; 
v___x_1734_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v___x_1735_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__0, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__0);
v___x_1736_ = l_Rat_div(v___x_1735_, v___x_1734_);
return v___x_1736_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0(lean_object* v_code_1737_){
_start:
{
uint8_t v___x_1738_; lean_object* v___x_1739_; lean_object* v___x_1740_; lean_object* v___x_1741_; lean_object* v___x_1742_; lean_object* v___x_1743_; lean_object* v___x_1744_; lean_object* v___x_1745_; lean_object* v___x_1746_; 
v___x_1738_ = 1;
v___x_1739_ = lean_unsigned_to_nat(10u);
v___x_1740_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1738_, v___x_1739_, v_code_1737_);
v___x_1741_ = l_Rat_ofInt(v___x_1740_);
v___x_1742_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0);
v___x_1743_ = l_Rat_mul(v___x_1741_, v___x_1742_);
lean_dec_ref(v___x_1741_);
v___x_1744_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2);
v___x_1745_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4);
v___x_1746_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1743_, v___x_1744_, v___x_1745_);
return v___x_1746_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1748_; lean_object* v___x_1749_; lean_object* v___x_1750_; 
v___f_1748_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__0));
v___x_1749_ = lean_unsigned_to_nat(1024u);
v___x_1750_ = l_Array_ofFn___redArg(v___x_1749_, v___f_1748_);
return v___x_1750_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable(void){
_start:
{
lean_object* v___x_1751_; 
v___x_1751_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1);
return v___x_1751_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg(lean_object* v_width_1752_, lean_object* v_table_1753_, lean_object* v_word_1754_, lean_object* v_start_1755_){
_start:
{
lean_object* v___x_1756_; lean_object* v___x_1757_; 
v___x_1756_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1754_, v_start_1755_, v_width_1752_);
v___x_1757_ = lean_array_fget_borrowed(v_table_1753_, v___x_1756_);
lean_dec(v___x_1756_);
lean_inc(v___x_1757_);
return v___x_1757_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg___boxed(lean_object* v_width_1758_, lean_object* v_table_1759_, lean_object* v_word_1760_, lean_object* v_start_1761_){
_start:
{
lean_object* v_res_1762_; 
v_res_1762_ = lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg(v_width_1758_, v_table_1759_, v_word_1760_, v_start_1761_);
lean_dec(v_start_1761_);
lean_dec(v_word_1760_);
lean_dec_ref(v_table_1759_);
lean_dec(v_width_1758_);
return v_res_1762_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet(lean_object* v_width_1763_, lean_object* v_table_1764_, lean_object* v_size_1765_, lean_object* v_word_1766_, lean_object* v_start_1767_){
_start:
{
lean_object* v___x_1768_; lean_object* v___x_1769_; 
v___x_1768_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1766_, v_start_1767_, v_width_1763_);
v___x_1769_ = lean_array_fget_borrowed(v_table_1764_, v___x_1768_);
lean_dec(v___x_1768_);
lean_inc(v___x_1769_);
return v___x_1769_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___boxed(lean_object* v_width_1770_, lean_object* v_table_1771_, lean_object* v_size_1772_, lean_object* v_word_1773_, lean_object* v_start_1774_){
_start:
{
lean_object* v_res_1775_; 
v_res_1775_ = lp_lean1090_Lean1090_Impl_cbDensityTableGet(v_width_1770_, v_table_1771_, v_size_1772_, v_word_1773_, v_start_1774_);
lean_dec(v_start_1774_);
lean_dec(v_word_1773_);
lean_dec_ref(v_table_1771_);
lean_dec(v_width_1770_);
return v_res_1775_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTermsFast(lean_object* v_register_1776_, lean_object* v_word_1777_){
_start:
{
lean_object* v___x_1778_; uint8_t v___x_1779_; 
v___x_1778_ = lean_unsigned_to_nat(64u);
v___x_1779_ = lean_nat_dec_eq(v_register_1776_, v___x_1778_);
if (v___x_1779_ == 0)
{
lean_object* v___x_1780_; uint8_t v___x_1781_; 
v___x_1780_ = lean_unsigned_to_nat(80u);
v___x_1781_ = lean_nat_dec_eq(v_register_1776_, v___x_1780_);
if (v___x_1781_ == 0)
{
lean_object* v___x_1782_; uint8_t v___x_1783_; 
v___x_1782_ = lean_unsigned_to_nat(96u);
v___x_1783_ = lean_nat_dec_eq(v_register_1776_, v___x_1782_);
if (v___x_1783_ == 0)
{
lean_object* v___x_1784_; uint8_t v___x_1785_; 
v___x_1784_ = lean_unsigned_to_nat(68u);
v___x_1785_ = lean_nat_dec_eq(v_register_1776_, v___x_1784_);
if (v___x_1785_ == 0)
{
lean_object* v___x_1786_; uint8_t v___x_1787_; 
v___x_1786_ = lean_unsigned_to_nat(69u);
v___x_1787_ = lean_nat_dec_eq(v_register_1776_, v___x_1786_);
if (v___x_1787_ == 0)
{
lean_object* v___x_1788_; 
v___x_1788_ = lean_box(0);
return v___x_1788_;
}
else
{
lean_object* v___x_1789_; lean_object* v___x_1790_; lean_object* v___x_1791_; lean_object* v___x_1792_; lean_object* v___y_1794_; uint8_t v___x_1808_; 
v___x_1789_ = lean_unsigned_to_nat(16u);
v___x_1790_ = lean_unsigned_to_nat(1u);
v___x_1791_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1789_, v___x_1790_);
v___x_1792_ = lean_unsigned_to_nat(0u);
v___x_1808_ = lean_nat_dec_eq(v___x_1791_, v___x_1792_);
lean_dec(v___x_1791_);
if (v___x_1808_ == 0)
{
lean_object* v___x_1809_; lean_object* v___x_1810_; lean_object* v___x_1811_; lean_object* v___x_1812_; lean_object* v___x_1813_; lean_object* v___x_1814_; lean_object* v___x_1815_; 
v___x_1809_ = lean_unsigned_to_nat(10u);
v___x_1810_ = lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable;
v___x_1811_ = lean_unsigned_to_nat(17u);
v___x_1812_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1811_, v___x_1809_);
v___x_1813_ = lean_array_fget_borrowed(v___x_1810_, v___x_1812_);
lean_dec(v___x_1812_);
v___x_1814_ = lean_box(0);
lean_inc(v___x_1813_);
v___x_1815_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1815_, 0, v___x_1813_);
lean_ctor_set(v___x_1815_, 1, v___x_1814_);
v___y_1794_ = v___x_1815_;
goto v___jp_1793_;
}
else
{
lean_object* v___x_1816_; 
v___x_1816_ = lean_box(0);
v___y_1794_ = v___x_1816_;
goto v___jp_1793_;
}
v___jp_1793_:
{
lean_object* v___x_1795_; lean_object* v___x_1796_; uint8_t v___x_1797_; 
v___x_1795_ = lean_unsigned_to_nat(27u);
v___x_1796_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1795_, v___x_1790_);
v___x_1797_ = lean_nat_dec_eq(v___x_1796_, v___x_1792_);
lean_dec(v___x_1796_);
if (v___x_1797_ == 0)
{
lean_object* v___x_1798_; lean_object* v___x_1799_; lean_object* v___x_1800_; lean_object* v___x_1801_; lean_object* v___x_1802_; lean_object* v___x_1803_; lean_object* v___x_1804_; lean_object* v___x_1805_; 
v___x_1798_ = lean_unsigned_to_nat(11u);
v___x_1799_ = lp_lean1090_Lean1090_Impl_cbPressureScoreTable;
v___x_1800_ = lean_unsigned_to_nat(28u);
v___x_1801_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1800_, v___x_1798_);
v___x_1802_ = lean_array_fget_borrowed(v___x_1799_, v___x_1801_);
lean_dec(v___x_1801_);
v___x_1803_ = lean_box(0);
lean_inc(v___x_1802_);
v___x_1804_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1804_, 0, v___x_1802_);
lean_ctor_set(v___x_1804_, 1, v___x_1803_);
v___x_1805_ = l_List_appendTR___redArg(v___y_1794_, v___x_1804_);
return v___x_1805_;
}
else
{
lean_object* v___x_1806_; lean_object* v___x_1807_; 
v___x_1806_ = lean_box(0);
v___x_1807_ = l_List_appendTR___redArg(v___y_1794_, v___x_1806_);
return v___x_1807_;
}
}
}
}
else
{
lean_object* v___x_1817_; lean_object* v___x_1818_; lean_object* v___x_1819_; lean_object* v___x_1820_; lean_object* v___x_1821_; lean_object* v___x_1822_; lean_object* v___x_1823_; lean_object* v___x_1824_; lean_object* v___x_1825_; lean_object* v___x_1826_; lean_object* v___x_1827_; lean_object* v___y_1829_; uint8_t v___x_1841_; 
v___x_1817_ = lean_unsigned_to_nat(11u);
v___x_1818_ = lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable;
v___x_1819_ = lean_unsigned_to_nat(24u);
v___x_1820_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1819_, v___x_1817_);
v___x_1821_ = lean_array_fget_borrowed(v___x_1818_, v___x_1820_);
lean_dec(v___x_1820_);
v___x_1822_ = lean_box(0);
lean_inc(v___x_1821_);
v___x_1823_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1823_, 0, v___x_1821_);
lean_ctor_set(v___x_1823_, 1, v___x_1822_);
v___x_1824_ = lean_unsigned_to_nat(5u);
v___x_1825_ = lean_unsigned_to_nat(1u);
v___x_1826_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1824_, v___x_1825_);
v___x_1827_ = lean_unsigned_to_nat(0u);
v___x_1841_ = lean_nat_dec_eq(v___x_1826_, v___x_1827_);
lean_dec(v___x_1826_);
if (v___x_1841_ == 0)
{
lean_object* v___x_1842_; lean_object* v___x_1843_; lean_object* v___x_1844_; lean_object* v___x_1845_; lean_object* v___x_1846_; lean_object* v___x_1847_; 
v___x_1842_ = lean_unsigned_to_nat(9u);
v___x_1843_ = lp_lean1090_Lean1090_Impl_cbWindScoreTable;
v___x_1844_ = lean_unsigned_to_nat(6u);
v___x_1845_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1844_, v___x_1842_);
v___x_1846_ = lean_array_fget_borrowed(v___x_1843_, v___x_1845_);
lean_dec(v___x_1845_);
lean_inc(v___x_1846_);
v___x_1847_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1847_, 0, v___x_1846_);
lean_ctor_set(v___x_1847_, 1, v___x_1822_);
v___y_1829_ = v___x_1847_;
goto v___jp_1828_;
}
else
{
v___y_1829_ = v___x_1822_;
goto v___jp_1828_;
}
v___jp_1828_:
{
lean_object* v___x_1830_; lean_object* v___x_1831_; lean_object* v___x_1832_; uint8_t v___x_1833_; 
v___x_1830_ = l_List_appendTR___redArg(v___x_1823_, v___y_1829_);
v___x_1831_ = lean_unsigned_to_nat(35u);
v___x_1832_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1831_, v___x_1825_);
v___x_1833_ = lean_nat_dec_eq(v___x_1832_, v___x_1827_);
lean_dec(v___x_1832_);
if (v___x_1833_ == 0)
{
lean_object* v___x_1834_; lean_object* v___x_1835_; lean_object* v___x_1836_; lean_object* v___x_1837_; lean_object* v___x_1838_; lean_object* v___x_1839_; 
v___x_1834_ = lp_lean1090_Lean1090_Impl_cbPressureScoreTable;
v___x_1835_ = lean_unsigned_to_nat(36u);
v___x_1836_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1835_, v___x_1817_);
v___x_1837_ = lean_array_fget_borrowed(v___x_1834_, v___x_1836_);
lean_dec(v___x_1836_);
lean_inc(v___x_1837_);
v___x_1838_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1838_, 0, v___x_1837_);
lean_ctor_set(v___x_1838_, 1, v___x_1822_);
v___x_1839_ = l_List_appendTR___redArg(v___x_1830_, v___x_1838_);
return v___x_1839_;
}
else
{
lean_object* v___x_1840_; 
v___x_1840_ = l_List_appendTR___redArg(v___x_1830_, v___x_1822_);
return v___x_1840_;
}
}
}
}
else
{
lean_object* v___x_1848_; lean_object* v___x_1849_; lean_object* v___x_1850_; lean_object* v___x_1851_; lean_object* v___y_1853_; lean_object* v___y_1854_; lean_object* v___y_1870_; uint8_t v___x_1882_; 
v___x_1848_ = lean_unsigned_to_nat(13u);
v___x_1849_ = lean_unsigned_to_nat(1u);
v___x_1850_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1848_, v___x_1849_);
v___x_1851_ = lean_unsigned_to_nat(0u);
v___x_1882_ = lean_nat_dec_eq(v___x_1850_, v___x_1851_);
lean_dec(v___x_1850_);
if (v___x_1882_ == 0)
{
lean_object* v___x_1883_; lean_object* v___x_1884_; lean_object* v___x_1885_; lean_object* v___x_1886_; lean_object* v___x_1887_; lean_object* v___x_1888_; lean_object* v___x_1889_; 
v___x_1883_ = lean_unsigned_to_nat(10u);
v___x_1884_ = lp_lean1090_Lean1090_Impl_cbIASScoreTable;
v___x_1885_ = lean_unsigned_to_nat(14u);
v___x_1886_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1885_, v___x_1883_);
v___x_1887_ = lean_array_fget_borrowed(v___x_1884_, v___x_1886_);
lean_dec(v___x_1886_);
v___x_1888_ = lean_box(0);
lean_inc(v___x_1887_);
v___x_1889_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1889_, 0, v___x_1887_);
lean_ctor_set(v___x_1889_, 1, v___x_1888_);
v___y_1870_ = v___x_1889_;
goto v___jp_1869_;
}
else
{
lean_object* v___x_1890_; 
v___x_1890_ = lean_box(0);
v___y_1870_ = v___x_1890_;
goto v___jp_1869_;
}
v___jp_1852_:
{
lean_object* v___x_1855_; lean_object* v___x_1856_; lean_object* v___x_1857_; uint8_t v___x_1858_; 
v___x_1855_ = l_List_appendTR___redArg(v___y_1853_, v___y_1854_);
v___x_1856_ = lean_unsigned_to_nat(46u);
v___x_1857_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1856_, v___x_1849_);
v___x_1858_ = lean_nat_dec_eq(v___x_1857_, v___x_1851_);
lean_dec(v___x_1857_);
if (v___x_1858_ == 0)
{
lean_object* v___x_1859_; lean_object* v___x_1860_; lean_object* v___x_1861_; lean_object* v___x_1862_; lean_object* v___x_1863_; lean_object* v___x_1864_; lean_object* v___x_1865_; lean_object* v___x_1866_; 
v___x_1859_ = lean_unsigned_to_nat(10u);
v___x_1860_ = lp_lean1090_Lean1090_Impl_cbVerticalScoreTable;
v___x_1861_ = lean_unsigned_to_nat(47u);
v___x_1862_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1861_, v___x_1859_);
v___x_1863_ = lean_array_fget_borrowed(v___x_1860_, v___x_1862_);
lean_dec(v___x_1862_);
v___x_1864_ = lean_box(0);
lean_inc(v___x_1863_);
v___x_1865_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1865_, 0, v___x_1863_);
lean_ctor_set(v___x_1865_, 1, v___x_1864_);
v___x_1866_ = l_List_appendTR___redArg(v___x_1855_, v___x_1865_);
return v___x_1866_;
}
else
{
lean_object* v___x_1867_; lean_object* v___x_1868_; 
v___x_1867_ = lean_box(0);
v___x_1868_ = l_List_appendTR___redArg(v___x_1855_, v___x_1867_);
return v___x_1868_;
}
}
v___jp_1869_:
{
lean_object* v___x_1871_; lean_object* v___x_1872_; uint8_t v___x_1873_; 
v___x_1871_ = lean_unsigned_to_nat(24u);
v___x_1872_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1871_, v___x_1849_);
v___x_1873_ = lean_nat_dec_eq(v___x_1872_, v___x_1851_);
lean_dec(v___x_1872_);
if (v___x_1873_ == 0)
{
lean_object* v___x_1874_; lean_object* v___x_1875_; lean_object* v___x_1876_; lean_object* v___x_1877_; lean_object* v___x_1878_; lean_object* v___x_1879_; lean_object* v___x_1880_; 
v___x_1874_ = lean_unsigned_to_nat(10u);
v___x_1875_ = lp_lean1090_Lean1090_Impl_cbMachScoreTable;
v___x_1876_ = lean_unsigned_to_nat(25u);
v___x_1877_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1876_, v___x_1874_);
v___x_1878_ = lean_array_fget_borrowed(v___x_1875_, v___x_1877_);
lean_dec(v___x_1877_);
v___x_1879_ = lean_box(0);
lean_inc(v___x_1878_);
v___x_1880_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1880_, 0, v___x_1878_);
lean_ctor_set(v___x_1880_, 1, v___x_1879_);
v___y_1853_ = v___y_1870_;
v___y_1854_ = v___x_1880_;
goto v___jp_1852_;
}
else
{
lean_object* v___x_1881_; 
v___x_1881_ = lean_box(0);
v___y_1853_ = v___y_1870_;
v___y_1854_ = v___x_1881_;
goto v___jp_1852_;
}
}
}
}
else
{
lean_object* v___x_1891_; lean_object* v___x_1892_; lean_object* v___x_1893_; lean_object* v___y_1895_; lean_object* v___y_1896_; lean_object* v___y_1912_; lean_object* v___y_1913_; lean_object* v___y_1927_; lean_object* v___y_1930_; uint8_t v___x_1946_; 
v___x_1891_ = lean_unsigned_to_nat(1u);
v___x_1892_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1891_, v___x_1891_);
v___x_1893_ = lean_unsigned_to_nat(0u);
v___x_1946_ = lean_nat_dec_eq(v___x_1892_, v___x_1893_);
lean_dec(v___x_1892_);
if (v___x_1946_ == 0)
{
lean_object* v___x_1947_; lean_object* v___x_1948_; lean_object* v___x_1949_; lean_object* v___x_1950_; lean_object* v___x_1951_; lean_object* v___x_1952_; lean_object* v___x_1953_; 
v___x_1947_ = lean_unsigned_to_nat(10u);
v___x_1948_ = lp_lean1090_Lean1090_Impl_cbRollScoreTable;
v___x_1949_ = lean_unsigned_to_nat(2u);
v___x_1950_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1949_, v___x_1947_);
v___x_1951_ = lean_array_fget_borrowed(v___x_1948_, v___x_1950_);
lean_dec(v___x_1950_);
v___x_1952_ = lean_box(0);
lean_inc(v___x_1951_);
v___x_1953_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1953_, 0, v___x_1951_);
lean_ctor_set(v___x_1953_, 1, v___x_1952_);
v___y_1930_ = v___x_1953_;
goto v___jp_1929_;
}
else
{
lean_object* v___x_1954_; 
v___x_1954_ = lean_box(0);
v___y_1930_ = v___x_1954_;
goto v___jp_1929_;
}
v___jp_1894_:
{
lean_object* v___x_1897_; lean_object* v___x_1898_; lean_object* v___x_1899_; uint8_t v___x_1900_; 
v___x_1897_ = l_List_appendTR___redArg(v___y_1895_, v___y_1896_);
v___x_1898_ = lean_unsigned_to_nat(24u);
v___x_1899_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1898_, v___x_1891_);
v___x_1900_ = lean_nat_dec_eq(v___x_1899_, v___x_1893_);
lean_dec(v___x_1899_);
if (v___x_1900_ == 0)
{
lean_object* v___x_1901_; lean_object* v___x_1902_; lean_object* v___x_1903_; lean_object* v___x_1904_; lean_object* v___x_1905_; lean_object* v___x_1906_; lean_object* v___x_1907_; lean_object* v___x_1908_; 
v___x_1901_ = lean_unsigned_to_nat(10u);
v___x_1902_ = lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable;
v___x_1903_ = lean_unsigned_to_nat(25u);
v___x_1904_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1903_, v___x_1901_);
v___x_1905_ = lean_array_fget_borrowed(v___x_1902_, v___x_1904_);
lean_dec(v___x_1904_);
v___x_1906_ = lean_box(0);
lean_inc(v___x_1905_);
v___x_1907_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1907_, 0, v___x_1905_);
lean_ctor_set(v___x_1907_, 1, v___x_1906_);
v___x_1908_ = l_List_appendTR___redArg(v___x_1897_, v___x_1907_);
return v___x_1908_;
}
else
{
lean_object* v___x_1909_; lean_object* v___x_1910_; 
v___x_1909_ = lean_box(0);
v___x_1910_ = l_List_appendTR___redArg(v___x_1897_, v___x_1909_);
return v___x_1910_;
}
}
v___jp_1911_:
{
lean_object* v___x_1914_; lean_object* v___x_1915_; lean_object* v___x_1916_; uint8_t v___x_1917_; 
v___x_1914_ = l_List_appendTR___redArg(v___y_1912_, v___y_1913_);
v___x_1915_ = lean_unsigned_to_nat(46u);
v___x_1916_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1915_, v___x_1891_);
v___x_1917_ = lean_nat_dec_eq(v___x_1916_, v___x_1893_);
lean_dec(v___x_1916_);
if (v___x_1917_ == 0)
{
lean_object* v___x_1918_; lean_object* v___x_1919_; lean_object* v___x_1920_; lean_object* v___x_1921_; lean_object* v___x_1922_; lean_object* v___x_1923_; lean_object* v___x_1924_; 
v___x_1918_ = lean_unsigned_to_nat(10u);
v___x_1919_ = lp_lean1090_Lean1090_Impl_cbTASScoreTable;
v___x_1920_ = lean_unsigned_to_nat(47u);
v___x_1921_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1920_, v___x_1918_);
v___x_1922_ = lean_array_fget_borrowed(v___x_1919_, v___x_1921_);
lean_dec(v___x_1921_);
v___x_1923_ = lean_box(0);
lean_inc(v___x_1922_);
v___x_1924_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1924_, 0, v___x_1922_);
lean_ctor_set(v___x_1924_, 1, v___x_1923_);
v___y_1895_ = v___x_1914_;
v___y_1896_ = v___x_1924_;
goto v___jp_1894_;
}
else
{
lean_object* v___x_1925_; 
v___x_1925_ = lean_box(0);
v___y_1895_ = v___x_1914_;
v___y_1896_ = v___x_1925_;
goto v___jp_1894_;
}
}
v___jp_1926_:
{
lean_object* v___x_1928_; 
v___x_1928_ = lean_box(0);
v___y_1912_ = v___y_1927_;
v___y_1913_ = v___x_1928_;
goto v___jp_1911_;
}
v___jp_1929_:
{
lean_object* v___x_1931_; lean_object* v___x_1932_; uint8_t v___x_1933_; 
v___x_1931_ = lean_unsigned_to_nat(35u);
v___x_1932_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1931_, v___x_1891_);
v___x_1933_ = lean_nat_dec_eq(v___x_1932_, v___x_1893_);
lean_dec(v___x_1932_);
if (v___x_1933_ == 0)
{
lean_object* v___x_1934_; lean_object* v___x_1935_; lean_object* v___x_1936_; lean_object* v___x_1937_; uint8_t v___x_1938_; 
v___x_1934_ = lean_unsigned_to_nat(37u);
v___x_1935_ = lean_unsigned_to_nat(9u);
v___x_1936_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1934_, v___x_1935_);
v___x_1937_ = lean_unsigned_to_nat(511u);
v___x_1938_ = lean_nat_dec_eq(v___x_1936_, v___x_1937_);
lean_dec(v___x_1936_);
if (v___x_1938_ == 0)
{
lean_object* v___x_1939_; lean_object* v___x_1940_; lean_object* v___x_1941_; lean_object* v___x_1942_; lean_object* v___x_1943_; lean_object* v___x_1944_; lean_object* v___x_1945_; 
v___x_1939_ = lean_unsigned_to_nat(10u);
v___x_1940_ = lp_lean1090_Lean1090_Impl_cbRateScoreTable;
v___x_1941_ = lean_unsigned_to_nat(36u);
v___x_1942_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1941_, v___x_1939_);
v___x_1943_ = lean_array_fget_borrowed(v___x_1940_, v___x_1942_);
lean_dec(v___x_1942_);
v___x_1944_ = lean_box(0);
lean_inc(v___x_1943_);
v___x_1945_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1945_, 0, v___x_1943_);
lean_ctor_set(v___x_1945_, 1, v___x_1944_);
v___y_1912_ = v___y_1930_;
v___y_1913_ = v___x_1945_;
goto v___jp_1911_;
}
else
{
v___y_1927_ = v___y_1930_;
goto v___jp_1926_;
}
}
else
{
v___y_1927_ = v___y_1930_;
goto v___jp_1926_;
}
}
}
}
else
{
lean_object* v___x_1955_; lean_object* v___x_1956_; lean_object* v___x_1957_; lean_object* v___x_1958_; lean_object* v___y_1960_; lean_object* v___y_1961_; lean_object* v___y_1977_; uint8_t v___x_1988_; 
v___x_1955_ = lean_unsigned_to_nat(27u);
v___x_1956_ = lean_unsigned_to_nat(1u);
v___x_1957_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1955_, v___x_1956_);
v___x_1958_ = lean_unsigned_to_nat(0u);
v___x_1988_ = lean_nat_dec_eq(v___x_1957_, v___x_1958_);
lean_dec(v___x_1957_);
if (v___x_1988_ == 0)
{
lean_object* v___x_1989_; lean_object* v___x_1990_; lean_object* v___x_1991_; lean_object* v___x_1992_; lean_object* v___x_1993_; lean_object* v___x_1994_; lean_object* v___x_1995_; 
v___x_1989_ = lean_unsigned_to_nat(12u);
v___x_1990_ = lp_lean1090_Lean1090_Impl_cbQNHScoreTable;
v___x_1991_ = lean_unsigned_to_nat(28u);
v___x_1992_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1991_, v___x_1989_);
v___x_1993_ = lean_array_fget_borrowed(v___x_1990_, v___x_1992_);
lean_dec(v___x_1992_);
v___x_1994_ = lean_box(0);
lean_inc(v___x_1993_);
v___x_1995_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1995_, 0, v___x_1993_);
lean_ctor_set(v___x_1995_, 1, v___x_1994_);
v___y_1977_ = v___x_1995_;
goto v___jp_1976_;
}
else
{
lean_object* v___x_1996_; 
v___x_1996_ = lean_box(0);
v___y_1977_ = v___x_1996_;
goto v___jp_1976_;
}
v___jp_1959_:
{
lean_object* v___x_1962_; lean_object* v___x_1963_; lean_object* v___x_1964_; uint8_t v___x_1965_; 
v___x_1962_ = l_List_appendTR___redArg(v___y_1960_, v___y_1961_);
v___x_1963_ = lean_unsigned_to_nat(14u);
v___x_1964_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1963_, v___x_1956_);
v___x_1965_ = lean_nat_dec_eq(v___x_1964_, v___x_1958_);
lean_dec(v___x_1964_);
if (v___x_1965_ == 0)
{
lean_object* v___x_1966_; lean_object* v___x_1967_; lean_object* v___x_1968_; lean_object* v___x_1969_; lean_object* v___x_1970_; lean_object* v___x_1971_; lean_object* v___x_1972_; lean_object* v___x_1973_; 
v___x_1966_ = lean_unsigned_to_nat(12u);
v___x_1967_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable;
v___x_1968_ = lean_unsigned_to_nat(15u);
v___x_1969_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1968_, v___x_1966_);
v___x_1970_ = lean_array_fget_borrowed(v___x_1967_, v___x_1969_);
lean_dec(v___x_1969_);
v___x_1971_ = lean_box(0);
lean_inc(v___x_1970_);
v___x_1972_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1972_, 0, v___x_1970_);
lean_ctor_set(v___x_1972_, 1, v___x_1971_);
v___x_1973_ = l_List_appendTR___redArg(v___x_1962_, v___x_1972_);
return v___x_1973_;
}
else
{
lean_object* v___x_1974_; lean_object* v___x_1975_; 
v___x_1974_ = lean_box(0);
v___x_1975_ = l_List_appendTR___redArg(v___x_1962_, v___x_1974_);
return v___x_1975_;
}
}
v___jp_1976_:
{
lean_object* v___x_1978_; uint8_t v___x_1979_; 
v___x_1978_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1956_, v___x_1956_);
v___x_1979_ = lean_nat_dec_eq(v___x_1978_, v___x_1958_);
lean_dec(v___x_1978_);
if (v___x_1979_ == 0)
{
lean_object* v___x_1980_; lean_object* v___x_1981_; lean_object* v___x_1982_; lean_object* v___x_1983_; lean_object* v___x_1984_; lean_object* v___x_1985_; lean_object* v___x_1986_; 
v___x_1980_ = lean_unsigned_to_nat(12u);
v___x_1981_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable;
v___x_1982_ = lean_unsigned_to_nat(2u);
v___x_1983_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1777_, v___x_1982_, v___x_1980_);
v___x_1984_ = lean_array_fget_borrowed(v___x_1981_, v___x_1983_);
lean_dec(v___x_1983_);
v___x_1985_ = lean_box(0);
lean_inc(v___x_1984_);
v___x_1986_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1986_, 0, v___x_1984_);
lean_ctor_set(v___x_1986_, 1, v___x_1985_);
v___y_1960_ = v___y_1977_;
v___y_1961_ = v___x_1986_;
goto v___jp_1959_;
}
else
{
lean_object* v___x_1987_; 
v___x_1987_ = lean_box(0);
v___y_1960_ = v___y_1977_;
v___y_1961_ = v___x_1987_;
goto v___jp_1959_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTermsFast___boxed(lean_object* v_register_1997_, lean_object* v_word_1998_){
_start:
{
lean_object* v_res_1999_; 
v_res_1999_ = lp_lean1090_Lean1090_Impl_cbDensityTermsFast(v_register_1997_, v_word_1998_);
lean_dec(v_word_1998_);
lean_dec(v_register_1997_);
return v_res_1999_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0(lean_object* v_register_2000_, lean_object* v_word_2001_, lean_object* v_x_2002_){
_start:
{
lean_object* v___x_2003_; lean_object* v___x_2004_; uint8_t v___x_2005_; 
v___x_2003_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__4, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__4);
v___x_2004_ = lp_lean1090_Lean1090_Impl_cbCombinedScore(v_register_2000_, v_word_2001_);
v___x_2005_ = l_Rat_instDecidableLe(v___x_2003_, v___x_2004_);
return v___x_2005_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed(lean_object* v_register_2006_, lean_object* v_word_2007_, lean_object* v_x_2008_){
_start:
{
uint8_t v_res_2009_; lean_object* v_r_2010_; 
v_res_2009_ = lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0(v_register_2006_, v_word_2007_, v_x_2008_);
lean_dec(v_word_2007_);
lean_dec(v_register_2006_);
v_r_2010_ = lean_box(v_res_2009_);
return v_r_2010_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses(lean_object* v_register_2011_, lean_object* v_word_2012_){
_start:
{
lean_object* v___f_2013_; lean_object* v___x_2014_; lean_object* v___x_2015_; uint8_t v___x_2016_; 
lean_inc(v_word_2012_);
lean_inc(v_register_2011_);
v___f_2013_ = lean_alloc_closure((void*)(lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed), 3, 2);
lean_closure_set(v___f_2013_, 0, v_register_2011_);
lean_closure_set(v___f_2013_, 1, v_word_2012_);
v___x_2014_ = lp_lean1090_Lean1090_Impl_cbDensityTermsFast(v_register_2011_, v_word_2012_);
v___x_2015_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_2011_, v_word_2012_);
lean_dec(v_word_2012_);
lean_dec(v_register_2011_);
v___x_2016_ = lp_lean1090_Lean1090_Impl_ScoreGate_choose(v___x_2014_, v___x_2015_, v___f_2013_);
return v___x_2016_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScorePasses___boxed(lean_object* v_register_2017_, lean_object* v_word_2018_){
_start:
{
uint8_t v_res_2019_; lean_object* v_r_2020_; 
v_res_2019_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2017_, v_word_2018_);
v_r_2020_ = lean_box(v_res_2019_);
return v_r_2020_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBCoreEligible(lean_object* v_register_2058_, lean_object* v_word_2059_){
_start:
{
uint8_t v___y_2061_; lean_object* v___x_2065_; uint8_t v___x_2066_; 
v___x_2065_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBCoreRegisters));
v___x_2066_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_2058_, v___x_2065_);
if (v___x_2066_ == 0)
{
v___y_2061_ = v___x_2066_;
goto v___jp_2060_;
}
else
{
uint8_t v___x_2067_; 
v___x_2067_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_2058_, v_word_2059_);
v___y_2061_ = v___x_2067_;
goto v___jp_2060_;
}
v___jp_2060_:
{
if (v___y_2061_ == 0)
{
lean_dec(v_word_2059_);
lean_dec(v_register_2058_);
return v___y_2061_;
}
else
{
lean_object* v___x_2062_; uint8_t v___x_2063_; 
v___x_2062_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__4));
v___x_2063_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_2058_, v___x_2062_);
if (v___x_2063_ == 0)
{
lean_dec(v_word_2059_);
lean_dec(v_register_2058_);
return v___y_2061_;
}
else
{
uint8_t v___x_2064_; 
v___x_2064_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2058_, v_word_2059_);
return v___x_2064_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBCoreEligible___boxed(lean_object* v_register_2068_, lean_object* v_word_2069_){
_start:
{
uint8_t v_res_2070_; lean_object* v_r_2071_; 
v_res_2070_ = lp_lean1090_Lean1090_Impl_commBCoreEligible(v_register_2068_, v_word_2069_);
v_r_2071_ = lean_box(v_res_2070_);
return v_r_2071_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBPositionEligible(lean_object* v_df_2072_, lean_object* v_outerAltitude_2073_, lean_object* v_word_2074_){
_start:
{
lean_object* v___x_2075_; uint8_t v___x_2076_; 
v___x_2075_ = lean_unsigned_to_nat(20u);
v___x_2076_ = lean_nat_dec_eq(v_df_2072_, v___x_2075_);
if (v___x_2076_ == 0)
{
lean_dec(v_outerAltitude_2073_);
return v___x_2076_;
}
else
{
lean_object* v___x_2077_; lean_object* v___x_2078_; lean_object* v_tc_2079_; lean_object* v___x_2080_; uint8_t v___x_2081_; 
v___x_2077_ = lean_unsigned_to_nat(1u);
v___x_2078_ = lean_unsigned_to_nat(5u);
v_tc_2079_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2074_, v___x_2077_, v___x_2078_);
v___x_2080_ = lean_unsigned_to_nat(9u);
v___x_2081_ = lean_nat_dec_le(v___x_2080_, v_tc_2079_);
if (v___x_2081_ == 0)
{
lean_dec(v_tc_2079_);
lean_dec(v_outerAltitude_2073_);
return v___x_2081_;
}
else
{
lean_object* v___x_2082_; uint8_t v___x_2083_; 
v___x_2082_ = lean_unsigned_to_nat(22u);
v___x_2083_ = lean_nat_dec_lt(v_tc_2079_, v___x_2082_);
if (v___x_2083_ == 0)
{
lean_dec(v_tc_2079_);
lean_dec(v_outerAltitude_2073_);
return v___x_2083_;
}
else
{
lean_object* v___x_2084_; uint8_t v___x_2085_; 
v___x_2084_ = lean_unsigned_to_nat(19u);
v___x_2085_ = lean_nat_dec_eq(v_tc_2079_, v___x_2084_);
lean_dec(v_tc_2079_);
if (v___x_2085_ == 0)
{
uint8_t v___x_2086_; 
v___x_2086_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v___x_2078_, v_word_2074_);
if (v___x_2086_ == 0)
{
lean_dec(v_outerAltitude_2073_);
return v___x_2086_;
}
else
{
lean_object* v___x_2087_; lean_object* v___x_2088_; uint8_t v___x_2089_; 
v___x_2087_ = lean_alloc_closure((void*)(l_Int_instDecidableEq___boxed), 2, 0);
v___x_2088_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_word_2074_);
v___x_2089_ = l_Option_instDecidableEq___redArg(v___x_2087_, v___x_2088_, v_outerAltitude_2073_);
return v___x_2089_;
}
}
else
{
uint8_t v___x_2090_; 
lean_dec(v_outerAltitude_2073_);
v___x_2090_ = 0;
return v___x_2090_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBPositionEligible___boxed(lean_object* v_df_2091_, lean_object* v_outerAltitude_2092_, lean_object* v_word_2093_){
_start:
{
uint8_t v_res_2094_; lean_object* v_r_2095_; 
v_res_2094_ = lp_lean1090_Lean1090_Impl_commBPositionEligible(v_df_2091_, v_outerAltitude_2092_, v_word_2093_);
lean_dec(v_word_2093_);
lean_dec(v_df_2091_);
v_r_2095_ = lean_box(v_res_2094_);
return v_r_2095_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg(){
_start:
{
uint8_t v___x_2097_; 
v___x_2097_ = 0;
return v___x_2097_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg___boxed(lean_object* v___dummy_2098_){
_start:
{
uint8_t v_res_2099_; lean_object* v_r_2100_; 
v_res_2099_ = lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg();
v_r_2100_ = lean_box(v_res_2099_);
return v_r_2100_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBOperationEligible(lean_object* v___word_2101_){
_start:
{
uint8_t v___x_2102_; 
v___x_2102_ = 0;
return v___x_2102_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBOperationEligible___boxed(lean_object* v___word_2103_){
_start:
{
uint8_t v_res_2104_; lean_object* v_r_2105_; 
v_res_2104_ = lp_lean1090_Lean1090_Impl_commBOperationEligible(v___word_2103_);
lean_dec(v___word_2103_);
v_r_2105_ = lean_box(v_res_2104_);
return v_r_2105_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBEligible(lean_object* v_df_2106_, lean_object* v_outerAltitude_2107_, lean_object* v_register_2108_, lean_object* v_word_2109_){
_start:
{
lean_object* v___x_2120_; uint8_t v___x_2121_; 
v___x_2120_ = lean_unsigned_to_nat(20u);
v___x_2121_ = lean_nat_dec_eq(v_df_2106_, v___x_2120_);
if (v___x_2121_ == 0)
{
lean_object* v___x_2122_; uint8_t v___x_2123_; 
v___x_2122_ = lean_unsigned_to_nat(21u);
v___x_2123_ = lean_nat_dec_eq(v_df_2106_, v___x_2122_);
if (v___x_2123_ == 0)
{
lean_dec(v_word_2109_);
lean_dec(v_register_2108_);
lean_dec(v_outerAltitude_2107_);
return v___x_2123_;
}
else
{
goto v___jp_2110_;
}
}
else
{
goto v___jp_2110_;
}
v___jp_2110_:
{
lean_object* v___x_2111_; uint8_t v___x_2112_; 
v___x_2111_ = lean_unsigned_to_nat(0u);
v___x_2112_ = lean_nat_dec_eq(v_word_2109_, v___x_2111_);
if (v___x_2112_ == 0)
{
lean_object* v___x_2113_; uint8_t v___x_2114_; 
v___x_2113_ = lean_unsigned_to_nat(5u);
v___x_2114_ = lean_nat_dec_eq(v_register_2108_, v___x_2113_);
if (v___x_2114_ == 0)
{
lean_object* v___x_2115_; uint8_t v___x_2116_; 
lean_dec(v_outerAltitude_2107_);
v___x_2115_ = lean_unsigned_to_nat(101u);
v___x_2116_ = lean_nat_dec_eq(v_register_2108_, v___x_2115_);
if (v___x_2116_ == 0)
{
uint8_t v___x_2117_; 
v___x_2117_ = lp_lean1090_Lean1090_Impl_commBCoreEligible(v_register_2108_, v_word_2109_);
return v___x_2117_;
}
else
{
lean_dec(v_word_2109_);
lean_dec(v_register_2108_);
return v___x_2114_;
}
}
else
{
uint8_t v___x_2118_; 
lean_dec(v_register_2108_);
v___x_2118_ = lp_lean1090_Lean1090_Impl_commBPositionEligible(v_df_2106_, v_outerAltitude_2107_, v_word_2109_);
lean_dec(v_word_2109_);
return v___x_2118_;
}
}
else
{
uint8_t v___x_2119_; 
lean_dec(v_word_2109_);
lean_dec(v_register_2108_);
lean_dec(v_outerAltitude_2107_);
v___x_2119_ = 0;
return v___x_2119_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBEligible___boxed(lean_object* v_df_2124_, lean_object* v_outerAltitude_2125_, lean_object* v_register_2126_, lean_object* v_word_2127_){
_start:
{
uint8_t v_res_2128_; lean_object* v_r_2129_; 
v_res_2128_ = lp_lean1090_Lean1090_Impl_commBEligible(v_df_2124_, v_outerAltitude_2125_, v_register_2126_, v_word_2127_);
lean_dec(v_df_2124_);
v_r_2129_ = lean_box(v_res_2128_);
return v_r_2129_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBRegisters___closed__2(void){
_start:
{
lean_object* v___x_2136_; lean_object* v___x_2137_; lean_object* v___x_2138_; 
v___x_2136_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBRegisters___closed__1));
v___x_2137_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBRegisters___closed__0));
v___x_2138_ = l_List_appendTR___redArg(v___x_2137_, v___x_2136_);
return v___x_2138_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBRegisters(void){
_start:
{
lean_object* v___x_2139_; 
v___x_2139_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_commBRegisters___closed__2, &lp_lean1090_Lean1090_Impl_commBRegisters___closed__2_once, _init_lp_lean1090_Lean1090_Impl_commBRegisters___closed__2);
return v___x_2139_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(lean_object* v_df_2140_, lean_object* v_outerAltitude_2141_, lean_object* v_word_2142_, lean_object* v_a_2143_, lean_object* v_a_2144_){
_start:
{
if (lean_obj_tag(v_a_2143_) == 0)
{
lean_object* v___x_2145_; 
lean_dec(v_word_2142_);
lean_dec(v_outerAltitude_2141_);
v___x_2145_ = lean_array_to_list(v_a_2144_);
return v___x_2145_;
}
else
{
lean_object* v_head_2146_; lean_object* v_tail_2147_; lean_object* v___x_2149_; uint8_t v_isShared_2150_; uint8_t v_isSharedCheck_2161_; 
v_head_2146_ = lean_ctor_get(v_a_2143_, 0);
v_tail_2147_ = lean_ctor_get(v_a_2143_, 1);
v_isSharedCheck_2161_ = !lean_is_exclusive(v_a_2143_);
if (v_isSharedCheck_2161_ == 0)
{
v___x_2149_ = v_a_2143_;
v_isShared_2150_ = v_isSharedCheck_2161_;
goto v_resetjp_2148_;
}
else
{
lean_inc(v_tail_2147_);
lean_inc(v_head_2146_);
lean_dec(v_a_2143_);
v___x_2149_ = lean_box(0);
v_isShared_2150_ = v_isSharedCheck_2161_;
goto v_resetjp_2148_;
}
v_resetjp_2148_:
{
uint8_t v___x_2151_; 
lean_inc(v_word_2142_);
lean_inc(v_head_2146_);
lean_inc(v_outerAltitude_2141_);
v___x_2151_ = lp_lean1090_Lean1090_Impl_commBEligible(v_df_2140_, v_outerAltitude_2141_, v_head_2146_, v_word_2142_);
if (v___x_2151_ == 0)
{
lean_del_object(v___x_2149_);
lean_dec(v_head_2146_);
v_a_2143_ = v_tail_2147_;
goto _start;
}
else
{
lean_object* v___x_2153_; 
lean_inc(v_head_2146_);
v___x_2153_ = lp_lean1090_Lean1090_Impl_decodeBDS(v_head_2146_, v_word_2142_);
if (lean_obj_tag(v___x_2153_) == 0)
{
lean_del_object(v___x_2149_);
lean_dec(v_head_2146_);
v_a_2143_ = v_tail_2147_;
goto _start;
}
else
{
lean_object* v_val_2155_; lean_object* v___x_2157_; 
v_val_2155_ = lean_ctor_get(v___x_2153_, 0);
lean_inc(v_val_2155_);
lean_dec_ref_known(v___x_2153_, 1);
if (v_isShared_2150_ == 0)
{
lean_ctor_set_tag(v___x_2149_, 0);
lean_ctor_set(v___x_2149_, 1, v_val_2155_);
v___x_2157_ = v___x_2149_;
goto v_reusejp_2156_;
}
else
{
lean_object* v_reuseFailAlloc_2160_; 
v_reuseFailAlloc_2160_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2160_, 0, v_head_2146_);
lean_ctor_set(v_reuseFailAlloc_2160_, 1, v_val_2155_);
v___x_2157_ = v_reuseFailAlloc_2160_;
goto v_reusejp_2156_;
}
v_reusejp_2156_:
{
lean_object* v___x_2158_; 
v___x_2158_ = lean_array_push(v_a_2144_, v___x_2157_);
v_a_2143_ = v_tail_2147_;
v_a_2144_ = v___x_2158_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0___boxed(lean_object* v_df_2162_, lean_object* v_outerAltitude_2163_, lean_object* v_word_2164_, lean_object* v_a_2165_, lean_object* v_a_2166_){
_start:
{
lean_object* v_res_2167_; 
v_res_2167_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(v_df_2162_, v_outerAltitude_2163_, v_word_2164_, v_a_2165_, v_a_2166_);
lean_dec(v_df_2162_);
return v_res_2167_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_inferCommB(lean_object* v_df_2170_, lean_object* v_outerAltitude_2171_, lean_object* v_word_2172_){
_start:
{
lean_object* v___x_2173_; lean_object* v___x_2174_; lean_object* v___x_2175_; 
v___x_2173_ = lp_lean1090_Lean1090_Impl_commBRegisters;
v___x_2174_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_inferCommB___closed__0));
v___x_2175_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(v_df_2170_, v_outerAltitude_2171_, v_word_2172_, v___x_2173_, v___x_2174_);
return v___x_2175_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_inferCommB___boxed(lean_object* v_df_2176_, lean_object* v_outerAltitude_2177_, lean_object* v_word_2178_){
_start:
{
lean_object* v_res_2179_; 
v_res_2179_ = lp_lean1090_Lean1090_Impl_inferCommB(v_df_2176_, v_outerAltitude_2177_, v_word_2178_);
lean_dec(v_df_2176_);
return v_res_2179_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Impl_CommBLayouts(uint8_t builtin);
lean_object* initialize_lean1090_Impl_ADSB(uint8_t builtin);
lean_object* initialize_lean1090_Impl_Binary64(uint8_t builtin);
lean_object* initialize_lean1090_Impl_ScoreGate(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_CommB(uint8_t builtin) {
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
res = initialize_lean1090_Impl_CommBLayouts(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_ADSB(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_Binary64(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_ScoreGate(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_lean1090_Lean1090_Impl_cbMachValueTable = _init_lp_lean1090_Lean1090_Impl_cbMachValueTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbMachValueTable);
lp_lean1090_Lean1090_Impl_cbQNHScoreTable = _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbQNHScoreTable);
lp_lean1090_Lean1090_Impl_cbSelectedScoreTable = _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbSelectedScoreTable);
lp_lean1090_Lean1090_Impl_cbRollScoreTable = _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbRollScoreTable);
lp_lean1090_Lean1090_Impl_cbRateScoreTable = _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbRateScoreTable);
lp_lean1090_Lean1090_Impl_cbTASScoreTable = _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbTASScoreTable);
lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable = _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable);
lp_lean1090_Lean1090_Impl_cbIASScoreTable = _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbIASScoreTable);
lp_lean1090_Lean1090_Impl_cbMachScoreTable = _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbMachScoreTable);
lp_lean1090_Lean1090_Impl_cbVerticalScoreTable = _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbVerticalScoreTable);
lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable = _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable);
lp_lean1090_Lean1090_Impl_cbWindScoreTable = _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbWindScoreTable);
lp_lean1090_Lean1090_Impl_cbPressureScoreTable = _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbPressureScoreTable);
lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable = _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable);
lp_lean1090_Lean1090_Impl_commBRegisters = _init_lp_lean1090_Lean1090_Impl_commBRegisters();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_commBRegisters);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
