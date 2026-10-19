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
lean_object* l_Rat_sub(lean_object*, lean_object*);
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
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbQNHValueTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbQNHValueTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbQNHValueTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNHValueTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNHValueTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHValueTable;
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
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenaltyTable;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenalty50(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenalty50___boxed(lean_object*);
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
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_82_; lean_object* v___x_83_; 
v___x_82_ = lean_unsigned_to_nat(1u);
v___x_83_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_82_);
return v___x_83_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1(void){
_start:
{
lean_object* v___x_84_; lean_object* v___x_85_; 
v___x_84_ = lean_unsigned_to_nat(10u);
v___x_85_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_84_);
return v___x_85_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__2(void){
_start:
{
lean_object* v___x_86_; lean_object* v___x_87_; lean_object* v___x_88_; 
v___x_86_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_87_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0);
v___x_88_ = l_Rat_div(v___x_87_, v___x_86_);
return v___x_88_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3(void){
_start:
{
lean_object* v___x_89_; lean_object* v___x_90_; 
v___x_89_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__2);
v___x_90_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_89_);
return v___x_90_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4(void){
_start:
{
lean_object* v___x_91_; lean_object* v___x_92_; 
v___x_91_ = lean_unsigned_to_nat(800u);
v___x_92_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_91_);
return v___x_92_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0(lean_object* v_code_93_){
_start:
{
lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; 
v___x_94_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_93_);
v___x_95_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3);
v___x_96_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_94_, v___x_95_);
lean_dec_ref(v___x_94_);
v___x_97_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4);
v___x_98_ = lp_lean1090_Lean1090_Impl_Binary64_add(v___x_96_, v___x_97_);
return v___x_98_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___closed__1(void){
_start:
{
lean_object* v___f_100_; lean_object* v___x_101_; lean_object* v___x_102_; 
v___f_100_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbQNHValueTable___closed__0));
v___x_101_ = lean_unsigned_to_nat(4096u);
v___x_102_ = l_Array_ofFn___redArg(v___x_101_, v___f_100_);
return v___x_102_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable(void){
_start:
{
lean_object* v___x_103_; 
v___x_103_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___closed__1);
return v___x_103_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNH64(lean_object* v_word_104_){
_start:
{
lean_object* v___x_105_; lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_108_; lean_object* v___x_109_; 
v___x_105_ = lp_lean1090_Lean1090_Impl_cbQNHValueTable;
v___x_106_ = lean_unsigned_to_nat(28u);
v___x_107_ = lean_unsigned_to_nat(12u);
v___x_108_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_104_, v___x_106_, v___x_107_);
v___x_109_ = lean_array_fget_borrowed(v___x_105_, v___x_108_);
lean_dec(v___x_108_);
lean_inc(v___x_109_);
return v___x_109_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNH64___boxed(lean_object* v_word_110_){
_start:
{
lean_object* v_res_111_; 
v_res_111_ = lp_lean1090_Lean1090_Impl_cbQNH64(v_word_110_);
lean_dec(v_word_110_);
return v_res_111_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_112_; lean_object* v___x_113_; 
v___x_112_ = lean_unsigned_to_nat(125u);
v___x_113_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_112_);
return v___x_113_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__1(void){
_start:
{
lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v___x_116_; 
v___x_114_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__0);
v___x_115_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_116_ = l_Rat_div(v___x_115_, v___x_114_);
return v___x_116_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2(void){
_start:
{
lean_object* v___x_117_; lean_object* v___x_118_; 
v___x_117_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__1);
v___x_118_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_117_);
return v___x_118_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3(void){
_start:
{
lean_object* v___x_119_; lean_object* v___x_120_; 
v___x_119_ = lean_unsigned_to_nat(512u);
v___x_120_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_119_);
return v___x_120_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0(lean_object* v_code_121_){
_start:
{
lean_object* v___x_122_; lean_object* v___x_123_; lean_object* v___x_124_; lean_object* v___x_125_; lean_object* v___x_126_; 
v___x_122_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_121_);
v___x_123_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2);
v___x_124_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_122_, v___x_123_);
lean_dec_ref(v___x_122_);
v___x_125_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3);
v___x_126_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_124_, v___x_125_);
lean_dec_ref(v___x_124_);
return v___x_126_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__1(void){
_start:
{
lean_object* v___f_128_; lean_object* v___x_129_; lean_object* v___x_130_; 
v___f_128_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__0));
v___x_129_ = lean_unsigned_to_nat(1024u);
v___x_130_ = l_Array_ofFn___redArg(v___x_129_, v___f_128_);
return v___x_130_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValueTable(void){
_start:
{
lean_object* v___x_131_; 
v___x_131_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__1, &lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___closed__1);
return v___x_131_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMach64(lean_object* v_word_132_){
_start:
{
lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; lean_object* v___x_136_; lean_object* v___x_137_; 
v___x_133_ = lp_lean1090_Lean1090_Impl_cbMachValueTable;
v___x_134_ = lean_unsigned_to_nat(25u);
v___x_135_ = lean_unsigned_to_nat(10u);
v___x_136_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_132_, v___x_134_, v___x_135_);
v___x_137_ = lean_array_fget_borrowed(v___x_133_, v___x_136_);
lean_dec(v___x_136_);
lean_inc(v___x_137_);
return v___x_137_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMach64___boxed(lean_object* v_word_138_){
_start:
{
lean_object* v_res_139_; 
v_res_139_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_138_);
lean_dec(v_word_138_);
return v_res_139_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0(void){
_start:
{
lean_object* v___x_140_; lean_object* v___x_141_; 
v___x_140_ = lean_unsigned_to_nat(360u);
v___x_141_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_140_);
return v___x_141_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWrapAngle(lean_object* v_value_142_){
_start:
{
lean_object* v___x_143_; uint8_t v___x_144_; 
v___x_143_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_value_142_);
v___x_144_ = l_Rat_blt(v_value_142_, v___x_143_);
if (v___x_144_ == 0)
{
return v_value_142_;
}
else
{
lean_object* v___x_145_; lean_object* v___x_146_; 
v___x_145_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0, &lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0);
v___x_146_ = l_Rat_add(v_value_142_, v___x_145_);
return v___x_146_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(lean_object* v_name_147_, lean_object* v_x_148_){
_start:
{
if (lean_obj_tag(v_x_148_) == 0)
{
lean_object* v___x_149_; 
v___x_149_ = lean_box(0);
return v___x_149_;
}
else
{
lean_object* v_head_150_; lean_object* v_tail_151_; lean_object* v_name_152_; uint8_t v___x_153_; 
v_head_150_ = lean_ctor_get(v_x_148_, 0);
v_tail_151_ = lean_ctor_get(v_x_148_, 1);
v_name_152_ = lean_ctor_get(v_head_150_, 0);
v___x_153_ = lean_string_dec_eq(v_name_152_, v_name_147_);
if (v___x_153_ == 0)
{
v_x_148_ = v_tail_151_;
goto _start;
}
else
{
lean_object* v___x_155_; 
lean_inc(v_head_150_);
v___x_155_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_155_, 0, v_head_150_);
return v___x_155_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0___boxed(lean_object* v_name_156_, lean_object* v_x_157_){
_start:
{
lean_object* v_res_158_; 
v_res_158_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(v_name_156_, v_x_157_);
lean_dec(v_x_157_);
lean_dec_ref(v_name_156_);
return v_res_158_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBValue(lean_object* v_register_168_, lean_object* v_word_169_, lean_object* v_name_170_){
_start:
{
lean_object* v___x_171_; 
v___x_171_ = lp_lean1090_Lean1090_Impl_commBLayout(v_register_168_);
if (lean_obj_tag(v___x_171_) == 0)
{
lean_object* v___x_172_; 
v___x_172_ = lean_box(0);
return v___x_172_;
}
else
{
lean_object* v_val_173_; lean_object* v___x_174_; 
v_val_173_ = lean_ctor_get(v___x_171_, 0);
lean_inc(v_val_173_);
lean_dec_ref_known(v___x_171_, 1);
v___x_174_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(v_name_170_, v_val_173_);
lean_dec(v_val_173_);
if (lean_obj_tag(v___x_174_) == 0)
{
lean_object* v___x_175_; 
v___x_175_ = lean_box(0);
return v___x_175_;
}
else
{
lean_object* v_val_176_; lean_object* v___x_178_; uint8_t v_isShared_179_; uint8_t v_isSharedCheck_292_; 
v_val_176_ = lean_ctor_get(v___x_174_, 0);
v_isSharedCheck_292_ = !lean_is_exclusive(v___x_174_);
if (v_isSharedCheck_292_ == 0)
{
v___x_178_ = v___x_174_;
v_isShared_179_ = v_isSharedCheck_292_;
goto v_resetjp_177_;
}
else
{
lean_inc(v_val_176_);
lean_dec(v___x_174_);
v___x_178_ = lean_box(0);
v_isShared_179_ = v_isSharedCheck_292_;
goto v_resetjp_177_;
}
v_resetjp_177_:
{
lean_object* v___x_180_; 
v___x_180_ = lp_lean1090_Lean1090_Impl_payloadValue(v_val_176_, v_word_169_);
if (lean_obj_tag(v___x_180_) == 0)
{
lean_del_object(v___x_178_);
return v___x_180_;
}
else
{
lean_object* v_val_181_; lean_object* v___x_187_; uint8_t v___x_188_; 
v_val_181_ = lean_ctor_get(v___x_180_, 0);
lean_inc(v_val_181_);
v___x_187_ = lean_unsigned_to_nat(16u);
v___x_188_ = lean_nat_dec_eq(v_register_168_, v___x_187_);
if (v___x_188_ == 0)
{
lean_object* v___x_189_; uint8_t v___x_190_; 
v___x_189_ = lean_unsigned_to_nat(64u);
v___x_190_ = lean_nat_dec_eq(v_register_168_, v___x_189_);
if (v___x_190_ == 0)
{
lean_object* v___x_191_; uint8_t v___x_192_; 
v___x_191_ = lean_unsigned_to_nat(68u);
v___x_192_ = lean_nat_dec_eq(v_register_168_, v___x_191_);
if (v___x_192_ == 0)
{
lean_object* v___x_193_; uint8_t v___x_194_; 
v___x_193_ = lean_unsigned_to_nat(80u);
v___x_194_ = lean_nat_dec_eq(v_register_168_, v___x_193_);
if (v___x_194_ == 0)
{
lean_object* v___x_195_; uint8_t v___x_196_; 
v___x_195_ = lean_unsigned_to_nat(96u);
v___x_196_ = lean_nat_dec_eq(v_register_168_, v___x_195_);
if (v___x_196_ == 0)
{
lean_dec(v_val_181_);
lean_del_object(v___x_178_);
return v___x_180_;
}
else
{
lean_object* v___x_197_; uint8_t v___x_198_; 
v___x_197_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__0));
v___x_198_ = lean_string_dec_eq(v_name_170_, v___x_197_);
if (v___x_198_ == 0)
{
lean_object* v___x_199_; uint8_t v___x_200_; 
lean_dec(v_val_181_);
lean_del_object(v___x_178_);
v___x_199_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__1));
v___x_200_ = lean_string_dec_eq(v_name_170_, v___x_199_);
if (v___x_200_ == 0)
{
lean_object* v___x_201_; uint8_t v___x_202_; 
v___x_201_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__2));
v___x_202_ = lean_string_dec_eq(v_name_170_, v___x_201_);
if (v___x_202_ == 0)
{
return v___x_180_;
}
else
{
lean_object* v___x_204_; uint8_t v_isShared_205_; uint8_t v_isSharedCheck_211_; 
v_isSharedCheck_211_ = !lean_is_exclusive(v___x_180_);
if (v_isSharedCheck_211_ == 0)
{
lean_object* v_unused_212_; 
v_unused_212_ = lean_ctor_get(v___x_180_, 0);
lean_dec(v_unused_212_);
v___x_204_ = v___x_180_;
v_isShared_205_ = v_isSharedCheck_211_;
goto v_resetjp_203_;
}
else
{
lean_dec(v___x_180_);
v___x_204_ = lean_box(0);
v_isShared_205_ = v_isSharedCheck_211_;
goto v_resetjp_203_;
}
v_resetjp_203_:
{
lean_object* v___x_206_; lean_object* v___x_207_; lean_object* v___x_209_; 
v___x_206_ = lean_unsigned_to_nat(47u);
v___x_207_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_169_, v___x_206_);
if (v_isShared_205_ == 0)
{
lean_ctor_set(v___x_204_, 0, v___x_207_);
v___x_209_ = v___x_204_;
goto v_reusejp_208_;
}
else
{
lean_object* v_reuseFailAlloc_210_; 
v_reuseFailAlloc_210_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_210_, 0, v___x_207_);
v___x_209_ = v_reuseFailAlloc_210_;
goto v_reusejp_208_;
}
v_reusejp_208_:
{
return v___x_209_;
}
}
}
}
else
{
lean_object* v___x_214_; uint8_t v_isShared_215_; uint8_t v_isSharedCheck_221_; 
v_isSharedCheck_221_ = !lean_is_exclusive(v___x_180_);
if (v_isSharedCheck_221_ == 0)
{
lean_object* v_unused_222_; 
v_unused_222_ = lean_ctor_get(v___x_180_, 0);
lean_dec(v_unused_222_);
v___x_214_ = v___x_180_;
v_isShared_215_ = v_isSharedCheck_221_;
goto v_resetjp_213_;
}
else
{
lean_dec(v___x_180_);
v___x_214_ = lean_box(0);
v_isShared_215_ = v_isSharedCheck_221_;
goto v_resetjp_213_;
}
v_resetjp_213_:
{
lean_object* v___x_216_; lean_object* v___x_217_; lean_object* v___x_219_; 
v___x_216_ = lean_unsigned_to_nat(36u);
v___x_217_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_169_, v___x_216_);
if (v_isShared_215_ == 0)
{
lean_ctor_set(v___x_214_, 0, v___x_217_);
v___x_219_ = v___x_214_;
goto v_reusejp_218_;
}
else
{
lean_object* v_reuseFailAlloc_220_; 
v_reuseFailAlloc_220_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_220_, 0, v___x_217_);
v___x_219_ = v_reuseFailAlloc_220_;
goto v_reusejp_218_;
}
v_reusejp_218_:
{
return v___x_219_;
}
}
}
}
else
{
lean_dec_ref_known(v___x_180_, 1);
goto v___jp_182_;
}
}
}
else
{
lean_object* v___x_223_; uint8_t v___x_224_; 
v___x_223_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__3));
v___x_224_ = lean_string_dec_eq(v_name_170_, v___x_223_);
if (v___x_224_ == 0)
{
lean_object* v___x_225_; uint8_t v___x_226_; 
lean_dec(v_val_181_);
lean_del_object(v___x_178_);
v___x_225_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__4));
v___x_226_ = lean_string_dec_eq(v_name_170_, v___x_225_);
if (v___x_226_ == 0)
{
return v___x_180_;
}
else
{
lean_object* v___x_227_; lean_object* v___x_228_; lean_object* v___x_229_; lean_object* v___x_230_; uint8_t v___x_231_; 
v___x_227_ = lean_unsigned_to_nat(37u);
v___x_228_ = lean_unsigned_to_nat(9u);
v___x_229_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_169_, v___x_227_, v___x_228_);
v___x_230_ = lean_unsigned_to_nat(511u);
v___x_231_ = lean_nat_dec_eq(v___x_229_, v___x_230_);
lean_dec(v___x_229_);
if (v___x_231_ == 0)
{
return v___x_180_;
}
else
{
lean_object* v___x_232_; 
lean_dec_ref_known(v___x_180_, 1);
v___x_232_ = lean_box(0);
return v___x_232_;
}
}
}
else
{
lean_dec_ref_known(v___x_180_, 1);
goto v___jp_182_;
}
}
}
else
{
lean_object* v___x_233_; uint8_t v___x_234_; 
lean_dec(v_val_181_);
lean_del_object(v___x_178_);
v___x_233_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__5));
v___x_234_ = lean_string_dec_eq(v_name_170_, v___x_233_);
if (v___x_234_ == 0)
{
return v___x_180_;
}
else
{
lean_object* v___x_236_; uint8_t v_isShared_237_; uint8_t v_isSharedCheck_242_; 
v_isSharedCheck_242_ = !lean_is_exclusive(v___x_180_);
if (v_isSharedCheck_242_ == 0)
{
lean_object* v_unused_243_; 
v_unused_243_ = lean_ctor_get(v___x_180_, 0);
lean_dec(v_unused_243_);
v___x_236_ = v___x_180_;
v_isShared_237_ = v_isSharedCheck_242_;
goto v_resetjp_235_;
}
else
{
lean_dec(v___x_180_);
v___x_236_ = lean_box(0);
v_isShared_237_ = v_isSharedCheck_242_;
goto v_resetjp_235_;
}
v_resetjp_235_:
{
lean_object* v___x_238_; lean_object* v___x_240_; 
v___x_238_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_169_);
if (v_isShared_237_ == 0)
{
lean_ctor_set(v___x_236_, 0, v___x_238_);
v___x_240_ = v___x_236_;
goto v_reusejp_239_;
}
else
{
lean_object* v_reuseFailAlloc_241_; 
v_reuseFailAlloc_241_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_241_, 0, v___x_238_);
v___x_240_ = v_reuseFailAlloc_241_;
goto v_reusejp_239_;
}
v_reusejp_239_:
{
return v___x_240_;
}
}
}
}
}
else
{
lean_object* v___x_244_; uint8_t v___x_245_; 
lean_dec(v_val_181_);
lean_del_object(v___x_178_);
v___x_244_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__6));
v___x_245_ = lean_string_dec_eq(v_name_170_, v___x_244_);
if (v___x_245_ == 0)
{
lean_object* v___x_246_; uint8_t v___x_247_; 
v___x_246_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__7));
v___x_247_ = lean_string_dec_eq(v_name_170_, v___x_246_);
if (v___x_247_ == 0)
{
return v___x_180_;
}
else
{
lean_object* v___x_249_; uint8_t v_isShared_250_; uint8_t v_isSharedCheck_258_; 
v_isSharedCheck_258_ = !lean_is_exclusive(v___x_180_);
if (v_isSharedCheck_258_ == 0)
{
lean_object* v_unused_259_; 
v_unused_259_ = lean_ctor_get(v___x_180_, 0);
lean_dec(v_unused_259_);
v___x_249_ = v___x_180_;
v_isShared_250_ = v_isSharedCheck_258_;
goto v_resetjp_248_;
}
else
{
lean_dec(v___x_180_);
v___x_249_ = lean_box(0);
v_isShared_250_ = v_isSharedCheck_258_;
goto v_resetjp_248_;
}
v_resetjp_248_:
{
lean_object* v___x_251_; lean_object* v___x_252_; lean_object* v___x_253_; lean_object* v___x_254_; lean_object* v___x_256_; 
v___x_251_ = lean_unsigned_to_nat(15u);
v___x_252_ = lean_unsigned_to_nat(12u);
v___x_253_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_169_, v___x_251_, v___x_252_);
v___x_254_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_253_);
lean_dec(v___x_253_);
if (v_isShared_250_ == 0)
{
lean_ctor_set(v___x_249_, 0, v___x_254_);
v___x_256_ = v___x_249_;
goto v_reusejp_255_;
}
else
{
lean_object* v_reuseFailAlloc_257_; 
v_reuseFailAlloc_257_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_257_, 0, v___x_254_);
v___x_256_ = v_reuseFailAlloc_257_;
goto v_reusejp_255_;
}
v_reusejp_255_:
{
return v___x_256_;
}
}
}
}
else
{
lean_object* v___x_261_; uint8_t v_isShared_262_; uint8_t v_isSharedCheck_270_; 
v_isSharedCheck_270_ = !lean_is_exclusive(v___x_180_);
if (v_isSharedCheck_270_ == 0)
{
lean_object* v_unused_271_; 
v_unused_271_ = lean_ctor_get(v___x_180_, 0);
lean_dec(v_unused_271_);
v___x_261_ = v___x_180_;
v_isShared_262_ = v_isSharedCheck_270_;
goto v_resetjp_260_;
}
else
{
lean_dec(v___x_180_);
v___x_261_ = lean_box(0);
v_isShared_262_ = v_isSharedCheck_270_;
goto v_resetjp_260_;
}
v_resetjp_260_:
{
lean_object* v___x_263_; lean_object* v___x_264_; lean_object* v___x_265_; lean_object* v___x_266_; lean_object* v___x_268_; 
v___x_263_ = lean_unsigned_to_nat(2u);
v___x_264_ = lean_unsigned_to_nat(12u);
v___x_265_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_169_, v___x_263_, v___x_264_);
v___x_266_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_265_);
lean_dec(v___x_265_);
if (v_isShared_262_ == 0)
{
lean_ctor_set(v___x_261_, 0, v___x_266_);
v___x_268_ = v___x_261_;
goto v_reusejp_267_;
}
else
{
lean_object* v_reuseFailAlloc_269_; 
v_reuseFailAlloc_269_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_269_, 0, v___x_266_);
v___x_268_ = v_reuseFailAlloc_269_;
goto v_reusejp_267_;
}
v_reusejp_267_:
{
return v___x_268_;
}
}
}
}
}
else
{
lean_object* v___x_272_; uint8_t v___x_273_; 
lean_dec(v_val_181_);
lean_del_object(v___x_178_);
v___x_272_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__8));
v___x_273_ = lean_string_dec_eq(v_name_170_, v___x_272_);
if (v___x_273_ == 0)
{
return v___x_180_;
}
else
{
lean_object* v___x_275_; uint8_t v_isShared_276_; uint8_t v_isSharedCheck_290_; 
v_isSharedCheck_290_ = !lean_is_exclusive(v___x_180_);
if (v_isSharedCheck_290_ == 0)
{
lean_object* v_unused_291_; 
v_unused_291_ = lean_ctor_get(v___x_180_, 0);
lean_dec(v_unused_291_);
v___x_275_ = v___x_180_;
v_isShared_276_ = v_isSharedCheck_290_;
goto v_resetjp_274_;
}
else
{
lean_dec(v___x_180_);
v___x_275_ = lean_box(0);
v_isShared_276_ = v_isSharedCheck_290_;
goto v_resetjp_274_;
}
v_resetjp_274_:
{
lean_object* v___x_277_; lean_object* v___x_278_; lean_object* v___x_279_; lean_object* v___x_280_; lean_object* v___x_281_; lean_object* v___x_282_; lean_object* v___x_283_; lean_object* v___x_284_; lean_object* v___x_285_; lean_object* v___x_286_; lean_object* v___x_288_; 
v___x_277_ = lean_unsigned_to_nat(41u);
v___x_278_ = lean_unsigned_to_nat(8u);
v___x_279_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_169_, v___x_277_, v___x_278_);
v___x_280_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_279_);
v___x_281_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_282_ = lean_unsigned_to_nat(49u);
v___x_283_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_169_, v___x_282_, v___x_278_);
v___x_284_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_283_);
v___x_285_ = l_Rat_mul(v___x_281_, v___x_284_);
v___x_286_ = l_Rat_add(v___x_280_, v___x_285_);
if (v_isShared_276_ == 0)
{
lean_ctor_set(v___x_275_, 0, v___x_286_);
v___x_288_ = v___x_275_;
goto v_reusejp_287_;
}
else
{
lean_object* v_reuseFailAlloc_289_; 
v_reuseFailAlloc_289_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_289_, 0, v___x_286_);
v___x_288_ = v_reuseFailAlloc_289_;
goto v_reusejp_287_;
}
v_reusejp_287_:
{
return v___x_288_;
}
}
}
}
v___jp_182_:
{
lean_object* v___x_183_; lean_object* v___x_185_; 
v___x_183_ = lp_lean1090_Lean1090_Impl_cbWrapAngle(v_val_181_);
if (v_isShared_179_ == 0)
{
lean_ctor_set(v___x_178_, 0, v___x_183_);
v___x_185_ = v___x_178_;
goto v_reusejp_184_;
}
else
{
lean_object* v_reuseFailAlloc_186_; 
v_reuseFailAlloc_186_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_186_, 0, v___x_183_);
v___x_185_ = v_reuseFailAlloc_186_;
goto v_reusejp_184_;
}
v_reusejp_184_:
{
return v___x_185_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBValue___boxed(lean_object* v_register_293_, lean_object* v_word_294_, lean_object* v_name_295_){
_start:
{
lean_object* v_res_296_; 
v_res_296_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_293_, v_word_294_, v_name_295_);
lean_dec_ref(v_name_295_);
lean_dec(v_word_294_);
lean_dec(v_register_293_);
return v_res_296_;
}
}
LEAN_EXPORT uint32_t lp_lean1090_Lean1090_Impl_cbCharacter(lean_object* v_code_297_){
_start:
{
lean_object* v___x_309_; uint8_t v___x_310_; 
v___x_309_ = lean_unsigned_to_nat(1u);
v___x_310_ = lean_nat_dec_le(v___x_309_, v_code_297_);
if (v___x_310_ == 0)
{
goto v___jp_303_;
}
else
{
lean_object* v___x_311_; uint8_t v___x_312_; 
v___x_311_ = lean_unsigned_to_nat(26u);
v___x_312_ = lean_nat_dec_le(v_code_297_, v___x_311_);
if (v___x_312_ == 0)
{
goto v___jp_303_;
}
else
{
lean_object* v___x_313_; lean_object* v___x_314_; uint32_t v___x_315_; 
v___x_313_ = lean_unsigned_to_nat(64u);
v___x_314_ = lean_nat_add(v___x_313_, v_code_297_);
v___x_315_ = l_Char_ofNat(v___x_314_);
lean_dec(v___x_314_);
return v___x_315_;
}
}
v___jp_298_:
{
lean_object* v___x_299_; uint8_t v___x_300_; 
v___x_299_ = lean_unsigned_to_nat(32u);
v___x_300_ = lean_nat_dec_eq(v_code_297_, v___x_299_);
if (v___x_300_ == 0)
{
uint32_t v___x_301_; 
v___x_301_ = 35;
return v___x_301_;
}
else
{
uint32_t v___x_302_; 
v___x_302_ = 32;
return v___x_302_;
}
}
v___jp_303_:
{
lean_object* v___x_304_; uint8_t v___x_305_; 
v___x_304_ = lean_unsigned_to_nat(48u);
v___x_305_ = lean_nat_dec_le(v___x_304_, v_code_297_);
if (v___x_305_ == 0)
{
goto v___jp_298_;
}
else
{
lean_object* v___x_306_; uint8_t v___x_307_; 
v___x_306_ = lean_unsigned_to_nat(57u);
v___x_307_ = lean_nat_dec_le(v_code_297_, v___x_306_);
if (v___x_307_ == 0)
{
goto v___jp_298_;
}
else
{
uint32_t v___x_308_; 
v___x_308_ = l_Char_ofNat(v_code_297_);
return v___x_308_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCharacter___boxed(lean_object* v_code_316_){
_start:
{
uint32_t v_res_317_; lean_object* v_r_318_; 
v_res_317_ = lp_lean1090_Lean1090_Impl_cbCharacter(v_code_316_);
lean_dec(v_code_316_);
v_r_318_ = lean_box_uint32(v_res_317_);
return v_r_318_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(lean_object* v_a_319_, lean_object* v_a_320_){
_start:
{
if (lean_obj_tag(v_a_319_) == 0)
{
lean_object* v___x_321_; 
v___x_321_ = l_List_reverse___redArg(v_a_320_);
return v___x_321_;
}
else
{
lean_object* v_head_322_; lean_object* v_tail_323_; lean_object* v___x_325_; uint8_t v_isShared_326_; uint8_t v_isSharedCheck_333_; 
v_head_322_ = lean_ctor_get(v_a_319_, 0);
v_tail_323_ = lean_ctor_get(v_a_319_, 1);
v_isSharedCheck_333_ = !lean_is_exclusive(v_a_319_);
if (v_isSharedCheck_333_ == 0)
{
v___x_325_ = v_a_319_;
v_isShared_326_ = v_isSharedCheck_333_;
goto v_resetjp_324_;
}
else
{
lean_inc(v_tail_323_);
lean_inc(v_head_322_);
lean_dec(v_a_319_);
v___x_325_ = lean_box(0);
v_isShared_326_ = v_isSharedCheck_333_;
goto v_resetjp_324_;
}
v_resetjp_324_:
{
uint32_t v___x_327_; lean_object* v___x_328_; lean_object* v___x_330_; 
v___x_327_ = lp_lean1090_Lean1090_Impl_cbCharacter(v_head_322_);
lean_dec(v_head_322_);
v___x_328_ = lean_box_uint32(v___x_327_);
if (v_isShared_326_ == 0)
{
lean_ctor_set(v___x_325_, 1, v_a_320_);
lean_ctor_set(v___x_325_, 0, v___x_328_);
v___x_330_ = v___x_325_;
goto v_reusejp_329_;
}
else
{
lean_object* v_reuseFailAlloc_332_; 
v_reuseFailAlloc_332_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_332_, 0, v___x_328_);
lean_ctor_set(v_reuseFailAlloc_332_, 1, v_a_320_);
v___x_330_ = v_reuseFailAlloc_332_;
goto v_reusejp_329_;
}
v_reusejp_329_:
{
v_a_319_ = v_tail_323_;
v_a_320_ = v___x_330_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbCallsign_spec__0(lean_object* v_a_334_, lean_object* v_a_335_){
_start:
{
if (lean_obj_tag(v_a_334_) == 0)
{
lean_object* v___x_336_; 
v___x_336_ = l_List_reverse___redArg(v_a_335_);
return v___x_336_;
}
else
{
lean_object* v_head_337_; lean_object* v_tail_338_; lean_object* v___x_340_; uint8_t v_isShared_341_; uint8_t v_isSharedCheck_349_; 
v_head_337_ = lean_ctor_get(v_a_334_, 0);
v_tail_338_ = lean_ctor_get(v_a_334_, 1);
v_isSharedCheck_349_ = !lean_is_exclusive(v_a_334_);
if (v_isSharedCheck_349_ == 0)
{
v___x_340_ = v_a_334_;
v_isShared_341_ = v_isSharedCheck_349_;
goto v_resetjp_339_;
}
else
{
lean_inc(v_tail_338_);
lean_inc(v_head_337_);
lean_dec(v_a_334_);
v___x_340_ = lean_box(0);
v_isShared_341_ = v_isSharedCheck_349_;
goto v_resetjp_339_;
}
v_resetjp_339_:
{
lean_object* v___x_342_; uint8_t v___x_343_; 
v___x_342_ = lean_unsigned_to_nat(32u);
v___x_343_ = lean_nat_dec_eq(v_head_337_, v___x_342_);
if (v___x_343_ == 0)
{
lean_object* v___x_345_; 
if (v_isShared_341_ == 0)
{
lean_ctor_set(v___x_340_, 1, v_a_335_);
v___x_345_ = v___x_340_;
goto v_reusejp_344_;
}
else
{
lean_object* v_reuseFailAlloc_347_; 
v_reuseFailAlloc_347_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_347_, 0, v_head_337_);
lean_ctor_set(v_reuseFailAlloc_347_, 1, v_a_335_);
v___x_345_ = v_reuseFailAlloc_347_;
goto v_reusejp_344_;
}
v_reusejp_344_:
{
v_a_334_ = v_tail_338_;
v_a_335_ = v___x_345_;
goto _start;
}
}
else
{
lean_del_object(v___x_340_);
lean_dec(v_head_337_);
v_a_334_ = v_tail_338_;
goto _start;
}
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbCallsign___closed__0(void){
_start:
{
lean_object* v___x_350_; lean_object* v___x_351_; 
v___x_350_ = lean_unsigned_to_nat(8u);
v___x_351_ = l_List_range(v___x_350_);
return v___x_351_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCallsign(lean_object* v_word_352_){
_start:
{
lean_object* v___x_353_; lean_object* v___x_354_; lean_object* v___x_355_; lean_object* v___x_356_; lean_object* v___x_357_; lean_object* v___x_358_; 
v___x_353_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbCallsign___closed__0, &lp_lean1090_Lean1090_Impl_cbCallsign___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbCallsign___closed__0);
v___x_354_ = lean_box(0);
v___x_355_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_adsbCallsign_spec__0(v_word_352_, v___x_353_, v___x_354_);
v___x_356_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbCallsign_spec__0(v___x_355_, v___x_354_);
v___x_357_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(v___x_356_, v___x_354_);
v___x_358_ = lean_string_mk(v___x_357_);
return v___x_358_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCallsign___boxed(lean_object* v_word_359_){
_start:
{
lean_object* v_res_360_; 
v_res_360_ = lp_lean1090_Lean1090_Impl_cbCallsign(v_word_359_);
lean_dec(v_word_359_);
return v_res_360_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbThreat(lean_object* v_word_361_){
_start:
{
lean_object* v___x_362_; lean_object* v___x_363_; lean_object* v___x_364_; lean_object* v___x_365_; uint8_t v___x_366_; 
v___x_362_ = lean_unsigned_to_nat(29u);
v___x_363_ = lean_unsigned_to_nat(2u);
v___x_364_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_361_, v___x_362_, v___x_363_);
v___x_365_ = lean_unsigned_to_nat(0u);
v___x_366_ = lean_nat_dec_eq(v___x_364_, v___x_365_);
if (v___x_366_ == 0)
{
lean_object* v___x_367_; uint8_t v___x_368_; 
v___x_367_ = lean_unsigned_to_nat(1u);
v___x_368_ = lean_nat_dec_eq(v___x_364_, v___x_367_);
if (v___x_368_ == 0)
{
uint8_t v___x_369_; 
v___x_369_ = lean_nat_dec_eq(v___x_364_, v___x_363_);
lean_dec(v___x_364_);
if (v___x_369_ == 0)
{
lean_object* v___x_370_; 
v___x_370_ = lean_box(3);
return v___x_370_;
}
else
{
lean_object* v___x_371_; lean_object* v___x_372_; lean_object* v_range_373_; lean_object* v___x_374_; lean_object* v___x_375_; lean_object* v_bearing_376_; lean_object* v___x_377_; lean_object* v___x_378_; lean_object* v___x_379_; lean_object* v___x_380_; lean_object* v___y_382_; uint8_t v___x_392_; 
v___x_371_ = lean_unsigned_to_nat(44u);
v___x_372_ = lean_unsigned_to_nat(7u);
v_range_373_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_361_, v___x_371_, v___x_372_);
v___x_374_ = lean_unsigned_to_nat(51u);
v___x_375_ = lean_unsigned_to_nat(6u);
v_bearing_376_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_361_, v___x_374_, v___x_375_);
v___x_377_ = lean_unsigned_to_nat(31u);
v___x_378_ = lean_unsigned_to_nat(13u);
v___x_379_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_361_, v___x_377_, v___x_378_);
v___x_380_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v___x_379_);
lean_dec(v___x_379_);
v___x_392_ = lean_nat_dec_eq(v_range_373_, v___x_365_);
if (v___x_392_ == 0)
{
lean_object* v___x_393_; lean_object* v___x_394_; lean_object* v___x_395_; lean_object* v___x_396_; lean_object* v___x_397_; 
v___x_393_ = lean_nat_sub(v_range_373_, v___x_367_);
lean_dec(v_range_373_);
v___x_394_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_393_);
v___x_395_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_396_ = l_Rat_div(v___x_394_, v___x_395_);
lean_dec_ref(v___x_394_);
v___x_397_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_397_, 0, v___x_396_);
v___y_382_ = v___x_397_;
goto v___jp_381_;
}
else
{
lean_object* v___x_398_; 
lean_dec(v_range_373_);
v___x_398_ = lean_box(0);
v___y_382_ = v___x_398_;
goto v___jp_381_;
}
v___jp_381_:
{
uint8_t v___x_383_; 
v___x_383_ = lean_nat_dec_eq(v_bearing_376_, v___x_365_);
if (v___x_383_ == 0)
{
lean_object* v___x_384_; lean_object* v___x_385_; lean_object* v___x_386_; lean_object* v___x_387_; lean_object* v___x_388_; lean_object* v___x_389_; 
v___x_384_ = lean_nat_sub(v_bearing_376_, v___x_367_);
lean_dec(v_bearing_376_);
v___x_385_ = lean_nat_mul(v___x_375_, v___x_384_);
lean_dec(v___x_384_);
v___x_386_ = lean_unsigned_to_nat(3u);
v___x_387_ = lean_nat_add(v___x_385_, v___x_386_);
lean_dec(v___x_385_);
v___x_388_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_388_, 0, v___x_387_);
v___x_389_ = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(v___x_389_, 0, v___x_380_);
lean_ctor_set(v___x_389_, 1, v___y_382_);
lean_ctor_set(v___x_389_, 2, v___x_388_);
return v___x_389_;
}
else
{
lean_object* v___x_390_; lean_object* v___x_391_; 
lean_dec(v_bearing_376_);
v___x_390_ = lean_box(0);
v___x_391_ = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(v___x_391_, 0, v___x_380_);
lean_ctor_set(v___x_391_, 1, v___y_382_);
lean_ctor_set(v___x_391_, 2, v___x_390_);
return v___x_391_;
}
}
}
}
else
{
lean_object* v___x_399_; lean_object* v___x_400_; lean_object* v___x_401_; lean_object* v___x_402_; 
lean_dec(v___x_364_);
v___x_399_ = lean_unsigned_to_nat(31u);
v___x_400_ = lean_unsigned_to_nat(24u);
v___x_401_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_361_, v___x_399_, v___x_400_);
v___x_402_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_402_, 0, v___x_401_);
return v___x_402_;
}
}
else
{
lean_object* v___x_403_; 
lean_dec(v___x_364_);
v___x_403_ = lean_box(0);
return v___x_403_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbThreat___boxed(lean_object* v_word_404_){
_start:
{
lean_object* v_res_405_; 
v_res_405_ = lp_lean1090_Lean1090_Impl_cbThreat(v_word_404_);
lean_dec(v_word_404_);
return v_res_405_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0(void){
_start:
{
lean_object* v___x_406_; lean_object* v___x_407_; 
v___x_406_ = lean_unsigned_to_nat(20u);
v___x_407_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_406_);
return v___x_407_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1(void){
_start:
{
lean_object* v___x_408_; lean_object* v___x_409_; lean_object* v___x_410_; 
v___x_408_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0);
v___x_409_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0);
v___x_410_ = l_Rat_div(v___x_409_, v___x_408_);
return v___x_410_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2(void){
_start:
{
lean_object* v___x_411_; lean_object* v___x_412_; 
v___x_411_ = lean_unsigned_to_nat(251u);
v___x_412_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_411_);
return v___x_412_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3(void){
_start:
{
lean_object* v___x_413_; lean_object* v___x_414_; lean_object* v___x_415_; 
v___x_413_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0);
v___x_414_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2);
v___x_415_ = l_Rat_div(v___x_414_, v___x_413_);
return v___x_415_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4(void){
_start:
{
lean_object* v___x_416_; lean_object* v___x_417_; 
v___x_416_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3);
v___x_417_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_417_, 0, v___x_416_);
return v___x_417_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5(void){
_start:
{
lean_object* v___x_418_; lean_object* v___x_419_; 
v___x_418_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1);
v___x_419_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_419_, 0, v___x_418_);
return v___x_419_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange(lean_object* v_code_420_){
_start:
{
lean_object* v___x_421_; uint8_t v___x_422_; 
v___x_421_ = lean_unsigned_to_nat(0u);
v___x_422_ = lean_nat_dec_eq(v_code_420_, v___x_421_);
if (v___x_422_ == 0)
{
lean_object* v___x_423_; uint8_t v___x_424_; 
v___x_423_ = lean_unsigned_to_nat(1u);
v___x_424_ = lean_nat_dec_eq(v_code_420_, v___x_423_);
if (v___x_424_ == 0)
{
lean_object* v___x_425_; uint8_t v___x_426_; 
v___x_425_ = lean_unsigned_to_nat(127u);
v___x_426_ = lean_nat_dec_eq(v_code_420_, v___x_425_);
if (v___x_426_ == 0)
{
lean_object* v___x_427_; lean_object* v___x_428_; lean_object* v___x_429_; lean_object* v___x_430_; lean_object* v___x_431_; lean_object* v___x_432_; 
v___x_427_ = lean_nat_sub(v_code_420_, v___x_423_);
v___x_428_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_427_);
v___x_429_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_430_ = l_Rat_div(v___x_428_, v___x_429_);
lean_dec_ref(v___x_428_);
v___x_431_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1);
v___x_432_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_432_, 0, v___x_430_);
lean_ctor_set(v___x_432_, 1, v___x_431_);
return v___x_432_;
}
else
{
lean_object* v___x_433_; 
v___x_433_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4);
return v___x_433_;
}
}
else
{
lean_object* v___x_434_; 
v___x_434_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5);
return v___x_434_;
}
}
else
{
lean_object* v___x_435_; 
v___x_435_ = lean_box(0);
return v___x_435_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange___boxed(lean_object* v_code_436_){
_start:
{
lean_object* v_res_437_; 
v_res_437_ = lp_lean1090_Lean1090_Impl_standardThreatRange(v_code_436_);
lean_dec(v_code_436_);
return v_res_437_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatBearing(lean_object* v_code_438_){
_start:
{
lean_object* v___x_439_; uint8_t v___x_440_; 
v___x_439_ = lean_unsigned_to_nat(0u);
v___x_440_ = lean_nat_dec_eq(v_code_438_, v___x_439_);
if (v___x_440_ == 0)
{
lean_object* v___x_441_; uint8_t v___x_442_; 
v___x_441_ = lean_unsigned_to_nat(60u);
v___x_442_ = lean_nat_dec_le(v_code_438_, v___x_441_);
if (v___x_442_ == 0)
{
lean_object* v___x_443_; 
v___x_443_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_443_, 0, v_code_438_);
return v___x_443_;
}
else
{
lean_object* v___x_444_; lean_object* v___x_445_; lean_object* v___x_446_; lean_object* v___x_447_; lean_object* v___x_448_; lean_object* v___x_449_; 
v___x_444_ = lean_unsigned_to_nat(6u);
v___x_445_ = lean_unsigned_to_nat(1u);
v___x_446_ = lean_nat_sub(v_code_438_, v___x_445_);
v___x_447_ = lean_nat_mul(v___x_444_, v___x_446_);
lean_dec(v___x_446_);
v___x_448_ = lean_nat_mul(v___x_444_, v_code_438_);
lean_dec(v_code_438_);
v___x_449_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_449_, 0, v___x_447_);
lean_ctor_set(v___x_449_, 1, v___x_448_);
return v___x_449_;
}
}
else
{
lean_object* v___x_450_; 
lean_dec(v_code_438_);
v___x_450_ = lean_box(0);
return v___x_450_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat(lean_object* v_word_455_){
_start:
{
lean_object* v___x_456_; uint8_t v___x_457_; 
v___x_456_ = lean_cstr_to_nat("72057594037927936");
v___x_457_ = lean_nat_dec_le(v___x_456_, v_word_455_);
if (v___x_457_ == 0)
{
lean_object* v___x_458_; lean_object* v___x_459_; lean_object* v___x_460_; lean_object* v___x_461_; uint8_t v___x_462_; 
v___x_458_ = lean_unsigned_to_nat(2u);
v___x_459_ = lean_unsigned_to_nat(29u);
v___x_460_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_455_, v___x_459_, v___x_458_);
v___x_461_ = lean_unsigned_to_nat(0u);
v___x_462_ = lean_nat_dec_eq(v___x_460_, v___x_461_);
if (v___x_462_ == 0)
{
lean_object* v___x_463_; uint8_t v___x_464_; 
v___x_463_ = lean_unsigned_to_nat(1u);
v___x_464_ = lean_nat_dec_eq(v___x_460_, v___x_463_);
if (v___x_464_ == 0)
{
uint8_t v___x_465_; 
v___x_465_ = lean_nat_dec_eq(v___x_460_, v___x_458_);
lean_dec(v___x_460_);
if (v___x_465_ == 0)
{
lean_object* v___x_466_; 
v___x_466_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__0));
return v___x_466_;
}
else
{
lean_object* v___x_467_; lean_object* v___x_468_; lean_object* v___x_469_; lean_object* v___x_470_; lean_object* v___x_471_; lean_object* v___x_472_; lean_object* v___x_473_; lean_object* v___x_474_; lean_object* v___x_475_; lean_object* v___x_476_; lean_object* v___x_477_; lean_object* v___x_478_; lean_object* v___x_479_; lean_object* v___x_480_; 
v___x_467_ = lean_unsigned_to_nat(31u);
v___x_468_ = lean_unsigned_to_nat(13u);
v___x_469_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_455_, v___x_467_, v___x_468_);
v___x_470_ = lp_lean1090_Lean1090_Impl_Altitude_decodeGillham(v___x_469_);
lean_dec(v___x_469_);
v___x_471_ = lean_unsigned_to_nat(44u);
v___x_472_ = lean_unsigned_to_nat(7u);
v___x_473_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_455_, v___x_471_, v___x_472_);
v___x_474_ = lp_lean1090_Lean1090_Impl_standardThreatRange(v___x_473_);
lean_dec(v___x_473_);
v___x_475_ = lean_unsigned_to_nat(51u);
v___x_476_ = lean_unsigned_to_nat(6u);
v___x_477_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_455_, v___x_475_, v___x_476_);
v___x_478_ = lp_lean1090_Lean1090_Impl_standardThreatBearing(v___x_477_);
v___x_479_ = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(v___x_479_, 0, v___x_470_);
lean_ctor_set(v___x_479_, 1, v___x_474_);
lean_ctor_set(v___x_479_, 2, v___x_478_);
v___x_480_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_480_, 0, v___x_479_);
return v___x_480_;
}
}
else
{
lean_object* v___x_481_; lean_object* v___x_482_; uint8_t v___x_483_; 
lean_dec(v___x_460_);
v___x_481_ = lean_unsigned_to_nat(55u);
v___x_482_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_455_, v___x_481_, v___x_458_);
v___x_483_ = lean_nat_dec_eq(v___x_482_, v___x_461_);
lean_dec(v___x_482_);
if (v___x_483_ == 0)
{
lean_object* v___x_484_; 
v___x_484_ = lean_box(0);
return v___x_484_;
}
else
{
lean_object* v___x_485_; lean_object* v___x_486_; lean_object* v___x_487_; lean_object* v___x_488_; lean_object* v___x_489_; 
v___x_485_ = lean_unsigned_to_nat(31u);
v___x_486_ = lean_unsigned_to_nat(24u);
v___x_487_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_455_, v___x_485_, v___x_486_);
v___x_488_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_488_, 0, v___x_487_);
v___x_489_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_489_, 0, v___x_488_);
return v___x_489_;
}
}
}
else
{
lean_object* v___x_490_; 
lean_dec(v___x_460_);
v___x_490_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__1));
return v___x_490_;
}
}
else
{
lean_object* v___x_491_; 
v___x_491_ = lean_box(0);
return v___x_491_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat___boxed(lean_object* v_word_492_){
_start:
{
lean_object* v_res_493_; 
v_res_493_ = lp_lean1090_Lean1090_Impl_cbStandardThreat(v_word_492_);
lean_dec(v_word_492_);
return v_res_493_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbDashPlaceholder(lean_object* v_code_494_){
_start:
{
lean_object* v___x_495_; uint8_t v___x_496_; 
v___x_495_ = lean_unsigned_to_nat(0u);
v___x_496_ = lean_nat_dec_eq(v_code_494_, v___x_495_);
if (v___x_496_ == 0)
{
lean_object* v___x_497_; uint8_t v___x_498_; 
v___x_497_ = lean_unsigned_to_nat(32u);
v___x_498_ = lean_nat_dec_eq(v_code_494_, v___x_497_);
if (v___x_498_ == 0)
{
lean_object* v___x_499_; uint8_t v___x_500_; 
v___x_499_ = lean_unsigned_to_nat(45u);
v___x_500_ = lean_nat_dec_eq(v_code_494_, v___x_499_);
return v___x_500_;
}
else
{
return v___x_498_;
}
}
else
{
return v___x_496_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDashPlaceholder___boxed(lean_object* v_code_501_){
_start:
{
uint8_t v_res_502_; lean_object* v_r_503_; 
v_res_502_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v_code_501_);
lean_dec(v_code_501_);
v_r_503_ = lean_box(v_res_502_);
return v_r_503_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(lean_object* v_word_504_, lean_object* v_a_505_, lean_object* v_a_506_){
_start:
{
if (lean_obj_tag(v_a_505_) == 0)
{
lean_object* v___x_507_; 
v___x_507_ = l_List_reverse___redArg(v_a_506_);
return v___x_507_;
}
else
{
lean_object* v_head_508_; lean_object* v_tail_509_; lean_object* v___x_511_; uint8_t v_isShared_512_; uint8_t v_isSharedCheck_522_; 
v_head_508_ = lean_ctor_get(v_a_505_, 0);
v_tail_509_ = lean_ctor_get(v_a_505_, 1);
v_isSharedCheck_522_ = !lean_is_exclusive(v_a_505_);
if (v_isSharedCheck_522_ == 0)
{
v___x_511_ = v_a_505_;
v_isShared_512_ = v_isSharedCheck_522_;
goto v_resetjp_510_;
}
else
{
lean_inc(v_tail_509_);
lean_inc(v_head_508_);
lean_dec(v_a_505_);
v___x_511_ = lean_box(0);
v_isShared_512_ = v_isSharedCheck_522_;
goto v_resetjp_510_;
}
v_resetjp_510_:
{
lean_object* v___x_513_; lean_object* v___x_514_; lean_object* v___x_515_; lean_object* v___x_516_; lean_object* v___x_517_; lean_object* v___x_519_; 
v___x_513_ = lean_unsigned_to_nat(2u);
v___x_514_ = lean_unsigned_to_nat(6u);
v___x_515_ = lean_nat_mul(v___x_514_, v_head_508_);
lean_dec(v_head_508_);
v___x_516_ = lean_nat_add(v___x_513_, v___x_515_);
lean_dec(v___x_515_);
v___x_517_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_504_, v___x_516_, v___x_514_);
lean_dec(v___x_516_);
if (v_isShared_512_ == 0)
{
lean_ctor_set(v___x_511_, 1, v_a_506_);
lean_ctor_set(v___x_511_, 0, v___x_517_);
v___x_519_ = v___x_511_;
goto v_reusejp_518_;
}
else
{
lean_object* v_reuseFailAlloc_521_; 
v_reuseFailAlloc_521_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_521_, 0, v___x_517_);
lean_ctor_set(v_reuseFailAlloc_521_, 1, v_a_506_);
v___x_519_ = v_reuseFailAlloc_521_;
goto v_reusejp_518_;
}
v_reusejp_518_:
{
v_a_505_ = v_tail_509_;
v_a_506_ = v___x_519_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0___boxed(lean_object* v_word_523_, lean_object* v_a_524_, lean_object* v_a_525_){
_start:
{
lean_object* v_res_526_; 
v_res_526_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(v_word_523_, v_a_524_, v_a_525_);
lean_dec(v_word_523_);
return v_res_526_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__1(lean_object* v_a_527_, lean_object* v_a_528_){
_start:
{
if (lean_obj_tag(v_a_527_) == 0)
{
lean_object* v___x_529_; 
v___x_529_ = l_List_reverse___redArg(v_a_528_);
return v___x_529_;
}
else
{
lean_object* v_head_530_; lean_object* v_tail_531_; lean_object* v___x_533_; uint8_t v_isShared_534_; uint8_t v_isSharedCheck_541_; 
v_head_530_ = lean_ctor_get(v_a_527_, 0);
v_tail_531_ = lean_ctor_get(v_a_527_, 1);
v_isSharedCheck_541_ = !lean_is_exclusive(v_a_527_);
if (v_isSharedCheck_541_ == 0)
{
v___x_533_ = v_a_527_;
v_isShared_534_ = v_isSharedCheck_541_;
goto v_resetjp_532_;
}
else
{
lean_inc(v_tail_531_);
lean_inc(v_head_530_);
lean_dec(v_a_527_);
v___x_533_ = lean_box(0);
v_isShared_534_ = v_isSharedCheck_541_;
goto v_resetjp_532_;
}
v_resetjp_532_:
{
uint8_t v___x_535_; 
v___x_535_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v_head_530_);
if (v___x_535_ == 0)
{
lean_object* v___x_537_; 
if (v_isShared_534_ == 0)
{
lean_ctor_set(v___x_533_, 1, v_a_528_);
v___x_537_ = v___x_533_;
goto v_reusejp_536_;
}
else
{
lean_object* v_reuseFailAlloc_539_; 
v_reuseFailAlloc_539_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_539_, 0, v_head_530_);
lean_ctor_set(v_reuseFailAlloc_539_, 1, v_a_528_);
v___x_537_ = v_reuseFailAlloc_539_;
goto v_reusejp_536_;
}
v_reusejp_536_:
{
v_a_527_ = v_tail_531_;
v_a_528_ = v___x_537_;
goto _start;
}
}
else
{
lean_del_object(v___x_533_);
lean_dec(v_head_530_);
v_a_527_ = v_tail_531_;
goto _start;
}
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0(void){
_start:
{
lean_object* v___x_542_; lean_object* v___x_543_; 
v___x_542_ = lean_unsigned_to_nat(7u);
v___x_543_ = l_List_range(v___x_542_);
return v___x_543_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistrationCodes(lean_object* v_word_544_){
_start:
{
lean_object* v___x_545_; lean_object* v___x_546_; lean_object* v___x_547_; lean_object* v___x_548_; 
v___x_545_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0, &lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0);
v___x_546_ = lean_box(0);
v___x_547_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(v_word_544_, v___x_545_, v___x_546_);
v___x_548_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__1(v___x_547_, v___x_546_);
return v___x_548_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistrationCodes___boxed(lean_object* v_word_549_){
_start:
{
lean_object* v_res_550_; 
v_res_550_ = lp_lean1090_Lean1090_Impl_cbRegistrationCodes(v_word_549_);
lean_dec(v_word_549_);
return v_res_550_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistration(lean_object* v_word_551_){
_start:
{
lean_object* v___x_552_; lean_object* v___x_553_; lean_object* v___x_554_; uint8_t v___x_555_; 
v___x_552_ = lean_unsigned_to_nat(1u);
v___x_553_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_551_, v___x_552_, v___x_552_);
v___x_554_ = lean_unsigned_to_nat(0u);
v___x_555_ = lean_nat_dec_eq(v___x_553_, v___x_554_);
lean_dec(v___x_553_);
if (v___x_555_ == 0)
{
lean_object* v___x_556_; lean_object* v___x_557_; lean_object* v___x_558_; lean_object* v___x_559_; lean_object* v___x_560_; 
v___x_556_ = lp_lean1090_Lean1090_Impl_cbRegistrationCodes(v_word_551_);
v___x_557_ = lean_box(0);
v___x_558_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(v___x_556_, v___x_557_);
v___x_559_ = lean_string_mk(v___x_558_);
v___x_560_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_560_, 0, v___x_559_);
return v___x_560_;
}
else
{
lean_object* v___x_561_; 
v___x_561_ = lean_box(0);
return v___x_561_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistration___boxed(lean_object* v_word_562_){
_start:
{
lean_object* v_res_563_; 
v_res_563_ = lp_lean1090_Lean1090_Impl_cbRegistration(v_word_562_);
lean_dec(v_word_562_);
return v_res_563_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(lean_object* v_word_564_, lean_object* v_x_565_){
_start:
{
if (lean_obj_tag(v_x_565_) == 0)
{
uint8_t v___x_566_; 
v___x_566_ = 1;
return v___x_566_;
}
else
{
lean_object* v_head_567_; lean_object* v_tail_568_; lean_object* v___x_569_; lean_object* v___x_570_; lean_object* v___x_571_; uint8_t v___x_572_; 
v_head_567_ = lean_ctor_get(v_x_565_, 0);
v_tail_568_ = lean_ctor_get(v_x_565_, 1);
v___x_569_ = lean_unsigned_to_nat(1u);
v___x_570_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_564_, v_head_567_, v___x_569_);
v___x_571_ = lean_unsigned_to_nat(0u);
v___x_572_ = lean_nat_dec_eq(v___x_570_, v___x_571_);
lean_dec(v___x_570_);
if (v___x_572_ == 0)
{
return v___x_572_;
}
else
{
v_x_565_ = v_tail_568_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0___boxed(lean_object* v_word_574_, lean_object* v_x_575_){
_start:
{
uint8_t v_res_576_; lean_object* v_r_577_; 
v_res_576_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(v_word_574_, v_x_575_);
lean_dec(v_x_575_);
lean_dec(v_word_574_);
v_r_577_ = lean_box(v_res_576_);
return v_r_577_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid17(lean_object* v_word_599_){
_start:
{
lean_object* v___x_600_; lean_object* v___x_601_; lean_object* v___x_602_; uint8_t v___x_603_; 
v___x_600_ = lean_unsigned_to_nat(7u);
v___x_601_ = lean_unsigned_to_nat(1u);
v___x_602_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_599_, v___x_600_, v___x_601_);
v___x_603_ = lean_nat_dec_eq(v___x_602_, v___x_601_);
lean_dec(v___x_602_);
if (v___x_603_ == 0)
{
return v___x_603_;
}
else
{
lean_object* v___x_604_; lean_object* v___x_605_; lean_object* v___x_606_; lean_object* v___x_607_; uint8_t v___x_608_; 
v___x_604_ = lean_unsigned_to_nat(30u);
v___x_605_ = lean_unsigned_to_nat(27u);
v___x_606_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_599_, v___x_604_, v___x_605_);
v___x_607_ = lean_unsigned_to_nat(0u);
v___x_608_ = lean_nat_dec_eq(v___x_606_, v___x_607_);
lean_dec(v___x_606_);
if (v___x_608_ == 0)
{
return v___x_608_;
}
else
{
lean_object* v___x_609_; uint8_t v___x_610_; 
v___x_609_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbValid17___closed__6));
v___x_610_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(v_word_599_, v___x_609_);
return v___x_610_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid17___boxed(lean_object* v_word_611_){
_start:
{
uint8_t v_res_612_; lean_object* v_r_613_; 
v_res_612_ = lp_lean1090_Lean1090_Impl_cbValid17(v_word_611_);
lean_dec(v_word_611_);
v_r_613_ = lean_box(v_res_612_);
return v_r_613_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(lean_object* v_word_677_, lean_object* v_x_678_){
_start:
{
if (lean_obj_tag(v_x_678_) == 0)
{
uint8_t v___x_679_; 
v___x_679_ = 1;
return v___x_679_;
}
else
{
lean_object* v_head_680_; lean_object* v_tail_681_; uint8_t v___y_683_; lean_object* v___x_685_; lean_object* v_allowed_686_; lean_object* v___x_687_; uint8_t v___x_688_; 
v_head_680_ = lean_ctor_get(v_x_678_, 0);
v_tail_681_ = lean_ctor_get(v_x_678_, 1);
v___x_685_ = lean_unsigned_to_nat(56u);
v_allowed_686_ = ((lean_object*)(lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__20));
v___x_687_ = lean_nat_sub(v___x_685_, v_head_680_);
v___x_688_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v___x_687_, v_allowed_686_);
lean_dec(v___x_687_);
if (v___x_688_ == 0)
{
lean_object* v___x_689_; lean_object* v___x_690_; lean_object* v___x_691_; lean_object* v___x_692_; uint8_t v___x_693_; 
v___x_689_ = lean_unsigned_to_nat(1u);
v___x_690_ = lean_nat_add(v_head_680_, v___x_689_);
v___x_691_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_677_, v___x_690_, v___x_689_);
lean_dec(v___x_690_);
v___x_692_ = lean_unsigned_to_nat(0u);
v___x_693_ = lean_nat_dec_eq(v___x_691_, v___x_692_);
lean_dec(v___x_691_);
v___y_683_ = v___x_693_;
goto v___jp_682_;
}
else
{
v___y_683_ = v___x_688_;
goto v___jp_682_;
}
v___jp_682_:
{
if (v___y_683_ == 0)
{
return v___y_683_;
}
else
{
v_x_678_ = v_tail_681_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___boxed(lean_object* v_word_694_, lean_object* v_x_695_){
_start:
{
uint8_t v_res_696_; lean_object* v_r_697_; 
v_res_696_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(v_word_694_, v_x_695_);
lean_dec(v_x_695_);
lean_dec(v_word_694_);
v_r_697_ = lean_box(v_res_696_);
return v_r_697_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(lean_object* v_word_698_, lean_object* v_x_699_){
_start:
{
if (lean_obj_tag(v_x_699_) == 0)
{
uint8_t v___x_700_; 
v___x_700_ = 1;
return v___x_700_;
}
else
{
lean_object* v_head_701_; lean_object* v_tail_702_; lean_object* v___x_703_; lean_object* v___x_704_; lean_object* v___x_705_; lean_object* v___x_706_; uint8_t v___x_707_; 
v_head_701_ = lean_ctor_get(v_x_699_, 0);
v_tail_702_ = lean_ctor_get(v_x_699_, 1);
v___x_703_ = lean_unsigned_to_nat(57u);
v___x_704_ = lean_nat_sub(v___x_703_, v_head_701_);
v___x_705_ = lean_unsigned_to_nat(1u);
v___x_706_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_698_, v___x_704_, v___x_705_);
lean_dec(v___x_704_);
v___x_707_ = lean_nat_dec_eq(v___x_706_, v___x_705_);
lean_dec(v___x_706_);
if (v___x_707_ == 0)
{
return v___x_707_;
}
else
{
v_x_699_ = v_tail_702_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1___boxed(lean_object* v_word_709_, lean_object* v_x_710_){
_start:
{
uint8_t v_res_711_; lean_object* v_r_712_; 
v_res_711_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(v_word_709_, v_x_710_);
lean_dec(v_x_710_);
lean_dec(v_word_709_);
v_r_712_ = lean_box(v_res_711_);
return v_r_712_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid18___closed__0(void){
_start:
{
lean_object* v___x_713_; lean_object* v___x_714_; 
v___x_713_ = lean_unsigned_to_nat(56u);
v___x_714_ = l_List_range(v___x_713_);
return v___x_714_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid18(lean_object* v_word_727_){
_start:
{
lean_object* v___x_728_; uint8_t v___x_729_; 
v___x_728_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid18___closed__0, &lp_lean1090_Lean1090_Impl_cbValid18___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid18___closed__0);
v___x_729_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(v_word_727_, v___x_728_);
if (v___x_729_ == 0)
{
return v___x_729_;
}
else
{
lean_object* v___x_730_; uint8_t v___x_731_; 
v___x_730_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbValid18___closed__4));
v___x_731_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(v_word_727_, v___x_730_);
return v___x_731_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid18___boxed(lean_object* v_word_732_){
_start:
{
uint8_t v_res_733_; lean_object* v_r_734_; 
v_res_733_ = lp_lean1090_Lean1090_Impl_cbValid18(v_word_732_);
lean_dec(v_word_732_);
v_r_734_ = lean_box(v_res_733_);
return v_r_734_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(lean_object* v_word_771_, lean_object* v_x_772_){
_start:
{
if (lean_obj_tag(v_x_772_) == 0)
{
uint8_t v___x_773_; 
v___x_773_ = 1;
return v___x_773_;
}
else
{
lean_object* v_head_774_; lean_object* v_tail_775_; uint8_t v___y_777_; lean_object* v_allowed_779_; lean_object* v___x_780_; lean_object* v___x_781_; uint8_t v___x_782_; 
v_head_774_ = lean_ctor_get(v_x_772_, 0);
v_tail_775_ = lean_ctor_get(v_x_772_, 1);
v_allowed_779_ = ((lean_object*)(lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__11));
v___x_780_ = lean_unsigned_to_nat(112u);
v___x_781_ = lean_nat_sub(v___x_780_, v_head_774_);
v___x_782_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v___x_781_, v_allowed_779_);
lean_dec(v___x_781_);
if (v___x_782_ == 0)
{
lean_object* v___x_783_; lean_object* v___x_784_; lean_object* v___x_785_; lean_object* v___x_786_; uint8_t v___x_787_; 
v___x_783_ = lean_unsigned_to_nat(1u);
v___x_784_ = lean_nat_add(v_head_774_, v___x_783_);
v___x_785_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_771_, v___x_784_, v___x_783_);
lean_dec(v___x_784_);
v___x_786_ = lean_unsigned_to_nat(0u);
v___x_787_ = lean_nat_dec_eq(v___x_785_, v___x_786_);
lean_dec(v___x_785_);
v___y_777_ = v___x_787_;
goto v___jp_776_;
}
else
{
v___y_777_ = v___x_782_;
goto v___jp_776_;
}
v___jp_776_:
{
if (v___y_777_ == 0)
{
return v___y_777_;
}
else
{
v_x_772_ = v_tail_775_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___boxed(lean_object* v_word_788_, lean_object* v_x_789_){
_start:
{
uint8_t v_res_790_; lean_object* v_r_791_; 
v_res_790_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(v_word_788_, v_x_789_);
lean_dec(v_x_789_);
lean_dec(v_word_788_);
v_r_791_ = lean_box(v_res_790_);
return v_r_791_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid19(lean_object* v_word_792_){
_start:
{
lean_object* v___x_793_; uint8_t v___x_794_; 
v___x_793_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid18___closed__0, &lp_lean1090_Lean1090_Impl_cbValid18___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid18___closed__0);
v___x_794_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(v_word_792_, v___x_793_);
return v___x_794_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid19___boxed(lean_object* v_word_795_){
_start:
{
uint8_t v_res_796_; lean_object* v_r_797_; 
v_res_796_ = lp_lean1090_Lean1090_Impl_cbValid19(v_word_795_);
lean_dec(v_word_795_);
v_r_797_ = lean_box(v_res_796_);
return v_r_797_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbValid21_spec__0(lean_object* v_a_798_, lean_object* v_a_799_){
_start:
{
if (lean_obj_tag(v_a_798_) == 0)
{
lean_object* v___x_800_; 
v___x_800_ = l_List_reverse___redArg(v_a_799_);
return v___x_800_;
}
else
{
lean_object* v_head_801_; lean_object* v_tail_802_; lean_object* v___x_804_; uint8_t v_isShared_805_; uint8_t v_isSharedCheck_814_; 
v_head_801_ = lean_ctor_get(v_a_798_, 0);
v_tail_802_ = lean_ctor_get(v_a_798_, 1);
v_isSharedCheck_814_ = !lean_is_exclusive(v_a_798_);
if (v_isSharedCheck_814_ == 0)
{
v___x_804_ = v_a_798_;
v_isShared_805_ = v_isSharedCheck_814_;
goto v_resetjp_803_;
}
else
{
lean_inc(v_tail_802_);
lean_inc(v_head_801_);
lean_dec(v_a_798_);
v___x_804_ = lean_box(0);
v_isShared_805_ = v_isSharedCheck_814_;
goto v_resetjp_803_;
}
v_resetjp_803_:
{
uint32_t v___x_806_; uint32_t v___x_807_; uint8_t v___x_808_; 
v___x_806_ = lp_lean1090_Lean1090_Impl_cbCharacter(v_head_801_);
v___x_807_ = 35;
v___x_808_ = lean_uint32_dec_eq(v___x_806_, v___x_807_);
if (v___x_808_ == 0)
{
lean_del_object(v___x_804_);
lean_dec(v_head_801_);
v_a_798_ = v_tail_802_;
goto _start;
}
else
{
lean_object* v___x_811_; 
if (v_isShared_805_ == 0)
{
lean_ctor_set(v___x_804_, 1, v_a_799_);
v___x_811_ = v___x_804_;
goto v_reusejp_810_;
}
else
{
lean_object* v_reuseFailAlloc_813_; 
v_reuseFailAlloc_813_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_813_, 0, v_head_801_);
lean_ctor_set(v_reuseFailAlloc_813_, 1, v_a_799_);
v___x_811_ = v_reuseFailAlloc_813_;
goto v_reusejp_810_;
}
v_reusejp_810_:
{
v_a_798_ = v_tail_802_;
v_a_799_ = v___x_811_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid21(lean_object* v_word_815_){
_start:
{
uint8_t v___y_817_; lean_object* v_codes_830_; lean_object* v___x_831_; lean_object* v___x_832_; lean_object* v___x_833_; uint8_t v___x_834_; 
v_codes_830_ = lp_lean1090_Lean1090_Impl_cbRegistrationCodes(v_word_815_);
v___x_831_ = lean_unsigned_to_nat(1u);
v___x_832_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_815_, v___x_831_, v___x_831_);
v___x_833_ = lean_unsigned_to_nat(0u);
v___x_834_ = lean_nat_dec_eq(v___x_832_, v___x_833_);
lean_dec(v___x_832_);
if (v___x_834_ == 0)
{
lean_object* v___x_835_; lean_object* v___x_836_; lean_object* v___x_837_; lean_object* v___x_838_; uint8_t v___x_839_; 
v___x_835_ = lean_box(0);
v___x_836_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbValid21_spec__0(v_codes_830_, v___x_835_);
v___x_837_ = l_List_lengthTR___redArg(v___x_836_);
lean_dec(v___x_836_);
v___x_838_ = lean_unsigned_to_nat(2u);
v___x_839_ = lean_nat_dec_le(v___x_837_, v___x_838_);
lean_dec(v___x_837_);
v___y_817_ = v___x_839_;
goto v___jp_816_;
}
else
{
uint8_t v___x_840_; 
v___x_840_ = l_List_isEmpty___redArg(v_codes_830_);
lean_dec(v_codes_830_);
v___y_817_ = v___x_840_;
goto v___jp_816_;
}
v___jp_816_:
{
if (v___y_817_ == 0)
{
return v___y_817_;
}
else
{
lean_object* v___x_818_; lean_object* v___x_819_; lean_object* v___x_820_; lean_object* v___x_821_; uint8_t v___x_822_; 
v___x_818_ = lean_unsigned_to_nat(44u);
v___x_819_ = lean_unsigned_to_nat(1u);
v___x_820_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_815_, v___x_818_, v___x_819_);
v___x_821_ = lean_unsigned_to_nat(0u);
v___x_822_ = lean_nat_dec_eq(v___x_820_, v___x_821_);
lean_dec(v___x_820_);
if (v___x_822_ == 0)
{
return v___x_822_;
}
else
{
lean_object* v___x_823_; lean_object* v___x_824_; lean_object* v___x_825_; uint8_t v___x_826_; 
v___x_823_ = lean_unsigned_to_nat(45u);
v___x_824_ = lean_unsigned_to_nat(6u);
v___x_825_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_815_, v___x_823_, v___x_824_);
v___x_826_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v___x_825_);
lean_dec(v___x_825_);
if (v___x_826_ == 0)
{
return v___x_826_;
}
else
{
lean_object* v___x_827_; lean_object* v___x_828_; uint8_t v___x_829_; 
v___x_827_ = lean_unsigned_to_nat(51u);
v___x_828_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_815_, v___x_827_, v___x_824_);
v___x_829_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v___x_828_);
lean_dec(v___x_828_);
return v___x_829_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid21___boxed(lean_object* v_word_841_){
_start:
{
uint8_t v_res_842_; lean_object* v_r_843_; 
v_res_842_ = lp_lean1090_Lean1090_Impl_cbValid21(v_word_841_);
lean_dec(v_word_841_);
v_r_843_ = lean_box(v_res_842_);
return v_r_843_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid40___closed__0(void){
_start:
{
lean_object* v___x_844_; lean_object* v___x_845_; 
v___x_844_ = lean_unsigned_to_nat(50000u);
v___x_845_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_844_);
return v___x_845_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid40___closed__1(void){
_start:
{
lean_object* v___x_846_; lean_object* v___x_847_; 
v___x_846_ = lean_unsigned_to_nat(1200u);
v___x_847_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_846_);
return v___x_847_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid40(lean_object* v_word_848_){
_start:
{
uint8_t v___y_850_; lean_object* v___x_877_; lean_object* v___x_878_; lean_object* v___x_879_; uint8_t v___x_880_; 
v___x_877_ = lean_unsigned_to_nat(1u);
v___x_878_ = lean_unsigned_to_nat(2u);
v___x_879_ = lean_unsigned_to_nat(12u);
v___x_880_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_848_, v___x_877_, v___x_878_, v___x_879_);
if (v___x_880_ == 0)
{
v___y_850_ = v___x_880_;
goto v___jp_849_;
}
else
{
lean_object* v___x_881_; lean_object* v___x_882_; uint8_t v___x_883_; 
v___x_881_ = lean_unsigned_to_nat(14u);
v___x_882_ = lean_unsigned_to_nat(15u);
v___x_883_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_848_, v___x_881_, v___x_882_, v___x_879_);
v___y_850_ = v___x_883_;
goto v___jp_849_;
}
v___jp_849_:
{
if (v___y_850_ == 0)
{
return v___y_850_;
}
else
{
lean_object* v___x_851_; lean_object* v___x_852_; lean_object* v___x_853_; uint8_t v___x_854_; 
v___x_851_ = lean_unsigned_to_nat(27u);
v___x_852_ = lean_unsigned_to_nat(28u);
v___x_853_ = lean_unsigned_to_nat(12u);
v___x_854_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_848_, v___x_851_, v___x_852_, v___x_853_);
if (v___x_854_ == 0)
{
return v___x_854_;
}
else
{
lean_object* v___x_855_; lean_object* v___x_856_; lean_object* v___x_857_; lean_object* v___x_858_; uint8_t v___x_859_; 
v___x_855_ = lean_unsigned_to_nat(40u);
v___x_856_ = lean_unsigned_to_nat(8u);
v___x_857_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_848_, v___x_855_, v___x_856_);
v___x_858_ = lean_unsigned_to_nat(0u);
v___x_859_ = lean_nat_dec_eq(v___x_857_, v___x_858_);
lean_dec(v___x_857_);
if (v___x_859_ == 0)
{
return v___x_859_;
}
else
{
lean_object* v___x_860_; lean_object* v___x_861_; lean_object* v___x_862_; uint8_t v___x_863_; 
v___x_860_ = lean_unsigned_to_nat(52u);
v___x_861_ = lean_unsigned_to_nat(2u);
v___x_862_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_848_, v___x_860_, v___x_861_);
v___x_863_ = lean_nat_dec_eq(v___x_862_, v___x_858_);
lean_dec(v___x_862_);
if (v___x_863_ == 0)
{
return v___x_863_;
}
else
{
lean_object* v___x_864_; lean_object* v___x_865_; lean_object* v___x_866_; uint8_t v___x_867_; 
v___x_864_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_848_, v___x_861_, v___x_853_);
v___x_865_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_864_);
lean_dec(v___x_864_);
v___x_866_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid40___closed__0, &lp_lean1090_Lean1090_Impl_cbValid40___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid40___closed__0);
v___x_867_ = l_Rat_instDecidableLe(v___x_865_, v___x_866_);
if (v___x_867_ == 0)
{
return v___x_867_;
}
else
{
lean_object* v___x_868_; lean_object* v___x_869_; lean_object* v___x_870_; uint8_t v___x_871_; 
v___x_868_ = lean_unsigned_to_nat(15u);
v___x_869_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_848_, v___x_868_, v___x_853_);
v___x_870_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_869_);
lean_dec(v___x_869_);
v___x_871_ = l_Rat_instDecidableLe(v___x_870_, v___x_866_);
if (v___x_871_ == 0)
{
return v___x_871_;
}
else
{
lean_object* v___x_872_; lean_object* v___x_873_; uint8_t v___x_874_; 
v___x_872_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4);
v___x_873_ = lp_lean1090_Lean1090_Impl_cbQNH64(v_word_848_);
lean_inc_ref(v___x_873_);
v___x_874_ = l_Rat_instDecidableLe(v___x_872_, v___x_873_);
if (v___x_874_ == 0)
{
lean_dec_ref(v___x_873_);
return v___x_874_;
}
else
{
lean_object* v___x_875_; uint8_t v___x_876_; 
v___x_875_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid40___closed__1, &lp_lean1090_Lean1090_Impl_cbValid40___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbValid40___closed__1);
v___x_876_ = l_Rat_instDecidableLe(v___x_873_, v___x_875_);
return v___x_876_;
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid40___boxed(lean_object* v_word_884_){
_start:
{
uint8_t v_res_885_; lean_object* v_r_886_; 
v_res_885_ = lp_lean1090_Lean1090_Impl_cbValid40(v_word_884_);
lean_dec(v_word_884_);
v_r_886_ = lean_box(v_res_885_);
return v_r_886_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0(void){
_start:
{
lean_object* v___x_887_; lean_object* v___x_888_; 
v___x_887_ = lean_unsigned_to_nat(60u);
v___x_888_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_887_);
return v___x_888_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid44(lean_object* v_word_889_){
_start:
{
lean_object* v___x_913_; lean_object* v___x_914_; lean_object* v___x_915_; uint8_t v___x_916_; 
v___x_913_ = lean_unsigned_to_nat(1u);
v___x_914_ = lean_unsigned_to_nat(4u);
v___x_915_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_889_, v___x_913_, v___x_914_);
v___x_916_ = lean_nat_dec_eq(v___x_915_, v___x_913_);
if (v___x_916_ == 0)
{
lean_object* v___x_917_; uint8_t v___x_918_; 
v___x_917_ = lean_unsigned_to_nat(2u);
v___x_918_ = lean_nat_dec_eq(v___x_915_, v___x_917_);
lean_dec(v___x_915_);
if (v___x_918_ == 0)
{
return v___x_918_;
}
else
{
goto v___jp_890_;
}
}
else
{
lean_dec(v___x_915_);
goto v___jp_890_;
}
v___jp_890_:
{
lean_object* v___x_891_; lean_object* v___x_892_; lean_object* v___x_893_; uint8_t v___x_894_; 
v___x_891_ = lean_unsigned_to_nat(5u);
v___x_892_ = lean_unsigned_to_nat(6u);
v___x_893_ = lean_unsigned_to_nat(18u);
v___x_894_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_889_, v___x_891_, v___x_892_, v___x_893_);
if (v___x_894_ == 0)
{
return v___x_894_;
}
else
{
lean_object* v___x_895_; lean_object* v___x_896_; lean_object* v___x_897_; uint8_t v___x_898_; 
v___x_895_ = lean_unsigned_to_nat(9u);
v___x_896_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_889_, v___x_892_, v___x_895_);
v___x_897_ = lean_unsigned_to_nat(250u);
v___x_898_ = lean_nat_dec_le(v___x_896_, v___x_897_);
lean_dec(v___x_896_);
if (v___x_898_ == 0)
{
return v___x_898_;
}
else
{
lean_object* v___x_899_; lean_object* v___x_900_; uint8_t v___x_901_; 
v___x_899_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
v___x_900_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_889_);
lean_inc_ref(v___x_900_);
v___x_901_ = l_Rat_instDecidableLe(v___x_899_, v___x_900_);
if (v___x_901_ == 0)
{
lean_dec_ref(v___x_900_);
return v___x_901_;
}
else
{
lean_object* v___x_902_; uint8_t v___x_903_; 
v___x_902_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid44___closed__0, &lp_lean1090_Lean1090_Impl_cbValid44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0);
v___x_903_ = l_Rat_instDecidableLe(v___x_900_, v___x_902_);
if (v___x_903_ == 0)
{
return v___x_903_;
}
else
{
lean_object* v___x_904_; lean_object* v___x_905_; lean_object* v___x_906_; uint8_t v___x_907_; 
v___x_904_ = lean_unsigned_to_nat(35u);
v___x_905_ = lean_unsigned_to_nat(36u);
v___x_906_ = lean_unsigned_to_nat(11u);
v___x_907_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_889_, v___x_904_, v___x_905_, v___x_906_);
if (v___x_907_ == 0)
{
return v___x_907_;
}
else
{
lean_object* v___x_908_; lean_object* v___x_909_; lean_object* v___x_910_; lean_object* v___x_911_; uint8_t v___x_912_; 
v___x_908_ = lean_unsigned_to_nat(47u);
v___x_909_ = lean_unsigned_to_nat(10u);
v___x_910_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_889_, v___x_908_, v___x_909_);
v___x_911_ = lean_unsigned_to_nat(0u);
v___x_912_ = lean_nat_dec_eq(v___x_910_, v___x_911_);
lean_dec(v___x_910_);
return v___x_912_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid44___boxed(lean_object* v_word_919_){
_start:
{
uint8_t v_res_920_; lean_object* v_r_921_; 
v_res_920_ = lp_lean1090_Lean1090_Impl_cbValid44(v_word_919_);
lean_dec(v_word_919_);
v_r_921_ = lean_box(v_res_920_);
return v_r_921_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid45(lean_object* v_word_922_){
_start:
{
uint8_t v___y_924_; lean_object* v___x_933_; lean_object* v___x_934_; lean_object* v___x_935_; lean_object* v___x_936_; uint8_t v___x_937_; 
v___x_933_ = lean_unsigned_to_nat(1u);
v___x_934_ = lean_unsigned_to_nat(15u);
v___x_935_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_922_, v___x_933_, v___x_934_);
v___x_936_ = lean_unsigned_to_nat(0u);
v___x_937_ = lean_nat_dec_eq(v___x_935_, v___x_936_);
lean_dec(v___x_935_);
if (v___x_937_ == 0)
{
return v___x_937_;
}
else
{
lean_object* v___x_938_; lean_object* v___x_939_; lean_object* v___x_940_; uint8_t v___x_941_; 
v___x_938_ = lean_unsigned_to_nat(52u);
v___x_939_ = lean_unsigned_to_nat(5u);
v___x_940_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_922_, v___x_938_, v___x_939_);
v___x_941_ = lean_nat_dec_eq(v___x_940_, v___x_936_);
lean_dec(v___x_940_);
if (v___x_941_ == 0)
{
return v___x_941_;
}
else
{
lean_object* v___x_942_; lean_object* v___x_943_; uint8_t v___x_944_; 
v___x_942_ = lean_unsigned_to_nat(16u);
v___x_943_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_922_, v___x_942_, v___x_933_);
v___x_944_ = lean_nat_dec_eq(v___x_943_, v___x_936_);
lean_dec(v___x_943_);
if (v___x_944_ == 0)
{
lean_object* v___x_945_; lean_object* v___x_946_; lean_object* v___x_947_; lean_object* v___x_948_; lean_object* v___x_949_; lean_object* v___x_950_; uint8_t v___x_951_; 
v___x_945_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
v___x_946_ = lean_unsigned_to_nat(17u);
v___x_947_ = lean_unsigned_to_nat(10u);
v___x_948_ = lp_lean1090_Lean1090_Impl_cbSigned(v_word_922_, v___x_946_, v___x_947_);
v___x_949_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v___x_950_ = l_Rat_div(v___x_948_, v___x_949_);
lean_dec_ref(v___x_948_);
lean_inc_ref(v___x_950_);
v___x_951_ = l_Rat_instDecidableLe(v___x_945_, v___x_950_);
if (v___x_951_ == 0)
{
lean_dec_ref(v___x_950_);
return v___x_951_;
}
else
{
lean_object* v___x_952_; uint8_t v___x_953_; 
v___x_952_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid44___closed__0, &lp_lean1090_Lean1090_Impl_cbValid44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0);
v___x_953_ = l_Rat_instDecidableLe(v___x_950_, v___x_952_);
v___y_924_ = v___x_953_;
goto v___jp_923_;
}
}
else
{
lean_object* v___x_954_; lean_object* v___x_955_; lean_object* v___x_956_; uint8_t v___x_957_; 
v___x_954_ = lean_unsigned_to_nat(18u);
v___x_955_ = lean_unsigned_to_nat(9u);
v___x_956_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_922_, v___x_954_, v___x_955_);
v___x_957_ = lean_nat_dec_eq(v___x_956_, v___x_936_);
lean_dec(v___x_956_);
v___y_924_ = v___x_957_;
goto v___jp_923_;
}
}
}
v___jp_923_:
{
if (v___y_924_ == 0)
{
return v___y_924_;
}
else
{
lean_object* v___x_925_; lean_object* v___x_926_; lean_object* v___x_927_; uint8_t v___x_928_; 
v___x_925_ = lean_unsigned_to_nat(27u);
v___x_926_ = lean_unsigned_to_nat(28u);
v___x_927_ = lean_unsigned_to_nat(11u);
v___x_928_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_922_, v___x_925_, v___x_926_, v___x_927_);
if (v___x_928_ == 0)
{
return v___x_928_;
}
else
{
lean_object* v___x_929_; lean_object* v___x_930_; lean_object* v___x_931_; uint8_t v___x_932_; 
v___x_929_ = lean_unsigned_to_nat(39u);
v___x_930_ = lean_unsigned_to_nat(40u);
v___x_931_ = lean_unsigned_to_nat(12u);
v___x_932_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_922_, v___x_929_, v___x_930_, v___x_931_);
return v___x_932_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid45___boxed(lean_object* v_word_958_){
_start:
{
uint8_t v_res_959_; lean_object* v_r_960_; 
v_res_959_ = lp_lean1090_Lean1090_Impl_cbValid45(v_word_958_);
lean_dec(v_word_958_);
v_r_960_ = lean_box(v_res_959_);
return v_r_960_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid50___closed__0(void){
_start:
{
lean_object* v___x_961_; lean_object* v___x_962_; 
v___x_961_ = lean_unsigned_to_nat(45u);
v___x_962_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_961_);
return v___x_962_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid50(lean_object* v_word_963_){
_start:
{
uint8_t v___y_965_; lean_object* v___x_998_; lean_object* v___x_999_; lean_object* v___x_1000_; uint8_t v___x_1001_; 
v___x_998_ = lean_unsigned_to_nat(1u);
v___x_999_ = lean_unsigned_to_nat(2u);
v___x_1000_ = lean_unsigned_to_nat(10u);
v___x_1001_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_963_, v___x_998_, v___x_999_, v___x_1000_);
if (v___x_1001_ == 0)
{
v___y_965_ = v___x_1001_;
goto v___jp_964_;
}
else
{
lean_object* v___x_1002_; lean_object* v___x_1003_; lean_object* v___x_1004_; uint8_t v___x_1005_; 
v___x_1002_ = lean_unsigned_to_nat(12u);
v___x_1003_ = lean_unsigned_to_nat(13u);
v___x_1004_ = lean_unsigned_to_nat(11u);
v___x_1005_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_963_, v___x_1002_, v___x_1003_, v___x_1004_);
v___y_965_ = v___x_1005_;
goto v___jp_964_;
}
v___jp_964_:
{
if (v___y_965_ == 0)
{
return v___y_965_;
}
else
{
lean_object* v___x_966_; lean_object* v___x_967_; lean_object* v___x_968_; uint8_t v___x_969_; 
v___x_966_ = lean_unsigned_to_nat(24u);
v___x_967_ = lean_unsigned_to_nat(25u);
v___x_968_ = lean_unsigned_to_nat(10u);
v___x_969_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_963_, v___x_966_, v___x_967_, v___x_968_);
if (v___x_969_ == 0)
{
return v___x_969_;
}
else
{
lean_object* v___x_970_; lean_object* v___x_971_; uint8_t v___x_972_; 
v___x_970_ = lean_unsigned_to_nat(35u);
v___x_971_ = lean_unsigned_to_nat(36u);
v___x_972_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_963_, v___x_970_, v___x_971_, v___x_968_);
if (v___x_972_ == 0)
{
return v___x_972_;
}
else
{
lean_object* v___x_973_; lean_object* v___x_974_; uint8_t v___x_975_; 
v___x_973_ = lean_unsigned_to_nat(46u);
v___x_974_ = lean_unsigned_to_nat(47u);
v___x_975_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_963_, v___x_973_, v___x_974_, v___x_968_);
if (v___x_975_ == 0)
{
return v___x_975_;
}
else
{
lean_object* v___x_976_; lean_object* v___x_977_; lean_object* v___x_978_; lean_object* v___x_979_; lean_object* v___x_980_; lean_object* v___x_981_; lean_object* v___x_982_; uint8_t v___x_983_; 
v___x_976_ = lean_unsigned_to_nat(2u);
v___x_977_ = lp_lean1090_Lean1090_Impl_cbSigned(v_word_963_, v___x_976_, v___x_968_);
v___x_978_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid50___closed__0, &lp_lean1090_Lean1090_Impl_cbValid50___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid50___closed__0);
v___x_979_ = l_Rat_mul(v___x_977_, v___x_978_);
lean_dec_ref(v___x_977_);
v___x_980_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_981_ = l_Rat_div(v___x_979_, v___x_980_);
lean_dec_ref(v___x_979_);
v___x_982_ = l_Rat_abs(v___x_981_);
v___x_983_ = l_Rat_instDecidableLe(v___x_982_, v___x_978_);
if (v___x_983_ == 0)
{
return v___x_983_;
}
else
{
lean_object* v___x_984_; lean_object* v___x_985_; lean_object* v___x_986_; uint8_t v___x_987_; 
v___x_984_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_963_, v___x_967_, v___x_968_);
v___x_985_ = lean_nat_mul(v___x_984_, v___x_976_);
lean_dec(v___x_984_);
v___x_986_ = lean_unsigned_to_nat(700u);
v___x_987_ = lean_nat_dec_le(v___x_985_, v___x_986_);
lean_dec(v___x_985_);
if (v___x_987_ == 0)
{
return v___x_987_;
}
else
{
lean_object* v___x_988_; lean_object* v___x_989_; lean_object* v___x_990_; uint8_t v___x_991_; 
v___x_988_ = lean_unsigned_to_nat(1u);
v___x_989_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_963_, v___x_973_, v___x_988_);
v___x_990_ = lean_unsigned_to_nat(0u);
v___x_991_ = lean_nat_dec_eq(v___x_989_, v___x_990_);
lean_dec(v___x_989_);
if (v___x_991_ == 0)
{
lean_object* v___x_992_; lean_object* v___x_993_; lean_object* v___x_994_; uint8_t v___x_995_; 
v___x_992_ = lean_unsigned_to_nat(80u);
v___x_993_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_963_, v___x_974_, v___x_968_);
v___x_994_ = lean_nat_mul(v___x_993_, v___x_976_);
lean_dec(v___x_993_);
v___x_995_ = lean_nat_dec_le(v___x_992_, v___x_994_);
if (v___x_995_ == 0)
{
lean_dec(v___x_994_);
return v___x_995_;
}
else
{
lean_object* v___x_996_; uint8_t v___x_997_; 
v___x_996_ = lean_unsigned_to_nat(600u);
v___x_997_ = lean_nat_dec_le(v___x_994_, v___x_996_);
lean_dec(v___x_994_);
return v___x_997_;
}
}
else
{
return v___x_991_;
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid50___boxed(lean_object* v_word_1006_){
_start:
{
uint8_t v_res_1007_; lean_object* v_r_1008_; 
v_res_1007_ = lp_lean1090_Lean1090_Impl_cbValid50(v_word_1006_);
lean_dec(v_word_1006_);
v_r_1008_ = lean_box(v_res_1007_);
return v_r_1008_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid60___closed__0(void){
_start:
{
lean_object* v___x_1009_; lean_object* v___x_1010_; 
v___x_1009_ = lean_unsigned_to_nat(6000u);
v___x_1010_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1009_);
return v___x_1010_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid60(lean_object* v_word_1011_){
_start:
{
uint8_t v___y_1013_; lean_object* v___x_1035_; lean_object* v___x_1036_; lean_object* v___x_1037_; uint8_t v___x_1038_; 
v___x_1035_ = lean_unsigned_to_nat(1u);
v___x_1036_ = lean_unsigned_to_nat(2u);
v___x_1037_ = lean_unsigned_to_nat(11u);
v___x_1038_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1011_, v___x_1035_, v___x_1036_, v___x_1037_);
if (v___x_1038_ == 0)
{
v___y_1013_ = v___x_1038_;
goto v___jp_1012_;
}
else
{
lean_object* v___x_1039_; lean_object* v___x_1040_; lean_object* v___x_1041_; uint8_t v___x_1042_; 
v___x_1039_ = lean_unsigned_to_nat(13u);
v___x_1040_ = lean_unsigned_to_nat(14u);
v___x_1041_ = lean_unsigned_to_nat(10u);
v___x_1042_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1011_, v___x_1039_, v___x_1040_, v___x_1041_);
v___y_1013_ = v___x_1042_;
goto v___jp_1012_;
}
v___jp_1012_:
{
if (v___y_1013_ == 0)
{
return v___y_1013_;
}
else
{
lean_object* v___x_1014_; lean_object* v___x_1015_; lean_object* v___x_1016_; uint8_t v___x_1017_; 
v___x_1014_ = lean_unsigned_to_nat(24u);
v___x_1015_ = lean_unsigned_to_nat(25u);
v___x_1016_ = lean_unsigned_to_nat(10u);
v___x_1017_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1011_, v___x_1014_, v___x_1015_, v___x_1016_);
if (v___x_1017_ == 0)
{
return v___x_1017_;
}
else
{
lean_object* v___x_1018_; lean_object* v___x_1019_; uint8_t v___x_1020_; 
v___x_1018_ = lean_unsigned_to_nat(35u);
v___x_1019_ = lean_unsigned_to_nat(36u);
v___x_1020_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1011_, v___x_1018_, v___x_1019_, v___x_1016_);
if (v___x_1020_ == 0)
{
return v___x_1020_;
}
else
{
lean_object* v___x_1021_; lean_object* v___x_1022_; uint8_t v___x_1023_; 
v___x_1021_ = lean_unsigned_to_nat(46u);
v___x_1022_ = lean_unsigned_to_nat(47u);
v___x_1023_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1011_, v___x_1021_, v___x_1022_, v___x_1016_);
if (v___x_1023_ == 0)
{
return v___x_1023_;
}
else
{
lean_object* v___x_1024_; lean_object* v___x_1025_; lean_object* v___x_1026_; uint8_t v___x_1027_; 
v___x_1024_ = lean_unsigned_to_nat(14u);
v___x_1025_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1011_, v___x_1024_, v___x_1016_);
v___x_1026_ = lean_unsigned_to_nat(500u);
v___x_1027_ = lean_nat_dec_le(v___x_1025_, v___x_1026_);
lean_dec(v___x_1025_);
if (v___x_1027_ == 0)
{
return v___x_1027_;
}
else
{
lean_object* v___x_1028_; lean_object* v___x_1029_; uint8_t v___x_1030_; 
v___x_1028_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_1011_);
v___x_1029_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0);
v___x_1030_ = l_Rat_instDecidableLe(v___x_1028_, v___x_1029_);
if (v___x_1030_ == 0)
{
return v___x_1030_;
}
else
{
lean_object* v___x_1031_; lean_object* v___x_1032_; lean_object* v___x_1033_; uint8_t v___x_1034_; 
v___x_1031_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_1011_, v___x_1022_);
v___x_1032_ = l_Rat_abs(v___x_1031_);
v___x_1033_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid60___closed__0, &lp_lean1090_Lean1090_Impl_cbValid60___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid60___closed__0);
v___x_1034_ = l_Rat_instDecidableLe(v___x_1032_, v___x_1033_);
return v___x_1034_;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid60___boxed(lean_object* v_word_1043_){
_start:
{
uint8_t v_res_1044_; lean_object* v_r_1045_; 
v_res_1044_ = lp_lean1090_Lean1090_Impl_cbValid60(v_word_1043_);
lean_dec(v_word_1043_);
v_r_1045_ = lean_box(v_res_1044_);
return v_r_1045_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_bdsWireValid(lean_object* v_register_1046_, lean_object* v_word_1047_){
_start:
{
lean_object* v___x_1048_; uint8_t v___x_1049_; 
v___x_1048_ = lean_cstr_to_nat("72057594037927936");
v___x_1049_ = lean_nat_dec_lt(v_word_1047_, v___x_1048_);
if (v___x_1049_ == 0)
{
return v___x_1049_;
}
else
{
lean_object* v___x_1050_; uint8_t v___x_1051_; 
v___x_1050_ = lean_unsigned_to_nat(5u);
v___x_1051_ = lean_nat_dec_eq(v_register_1046_, v___x_1050_);
if (v___x_1051_ == 0)
{
lean_object* v___x_1052_; uint8_t v___x_1053_; 
v___x_1052_ = lean_unsigned_to_nat(101u);
v___x_1053_ = lean_nat_dec_eq(v_register_1046_, v___x_1052_);
if (v___x_1053_ == 0)
{
lean_object* v___x_1054_; uint8_t v___x_1055_; 
v___x_1054_ = lean_unsigned_to_nat(16u);
v___x_1055_ = lean_nat_dec_eq(v_register_1046_, v___x_1054_);
if (v___x_1055_ == 0)
{
lean_object* v___x_1056_; uint8_t v___x_1057_; 
v___x_1056_ = lean_unsigned_to_nat(23u);
v___x_1057_ = lean_nat_dec_eq(v_register_1046_, v___x_1056_);
if (v___x_1057_ == 0)
{
lean_object* v___x_1058_; uint8_t v___x_1059_; 
v___x_1058_ = lean_unsigned_to_nat(24u);
v___x_1059_ = lean_nat_dec_eq(v_register_1046_, v___x_1058_);
if (v___x_1059_ == 0)
{
lean_object* v___x_1060_; uint8_t v___x_1061_; 
v___x_1060_ = lean_unsigned_to_nat(25u);
v___x_1061_ = lean_nat_dec_eq(v_register_1046_, v___x_1060_);
if (v___x_1061_ == 0)
{
lean_object* v___x_1062_; uint8_t v___x_1063_; 
v___x_1062_ = lean_unsigned_to_nat(32u);
v___x_1063_ = lean_nat_dec_eq(v_register_1046_, v___x_1062_);
if (v___x_1063_ == 0)
{
lean_object* v___x_1064_; uint8_t v___x_1065_; 
v___x_1064_ = lean_unsigned_to_nat(33u);
v___x_1065_ = lean_nat_dec_eq(v_register_1046_, v___x_1064_);
if (v___x_1065_ == 0)
{
lean_object* v___x_1066_; uint8_t v___x_1067_; 
v___x_1066_ = lean_unsigned_to_nat(48u);
v___x_1067_ = lean_nat_dec_eq(v_register_1046_, v___x_1066_);
if (v___x_1067_ == 0)
{
lean_object* v___x_1068_; uint8_t v___x_1069_; 
v___x_1068_ = lean_unsigned_to_nat(64u);
v___x_1069_ = lean_nat_dec_eq(v_register_1046_, v___x_1068_);
if (v___x_1069_ == 0)
{
lean_object* v___x_1070_; uint8_t v___x_1071_; 
v___x_1070_ = lean_unsigned_to_nat(68u);
v___x_1071_ = lean_nat_dec_eq(v_register_1046_, v___x_1070_);
if (v___x_1071_ == 0)
{
lean_object* v___x_1072_; uint8_t v___x_1073_; 
v___x_1072_ = lean_unsigned_to_nat(69u);
v___x_1073_ = lean_nat_dec_eq(v_register_1046_, v___x_1072_);
if (v___x_1073_ == 0)
{
lean_object* v___x_1074_; uint8_t v___x_1075_; 
v___x_1074_ = lean_unsigned_to_nat(80u);
v___x_1075_ = lean_nat_dec_eq(v_register_1046_, v___x_1074_);
if (v___x_1075_ == 0)
{
lean_object* v___x_1076_; uint8_t v___x_1077_; 
v___x_1076_ = lean_unsigned_to_nat(96u);
v___x_1077_ = lean_nat_dec_eq(v_register_1046_, v___x_1076_);
if (v___x_1077_ == 0)
{
return v___x_1077_;
}
else
{
uint8_t v___x_1078_; 
v___x_1078_ = lp_lean1090_Lean1090_Impl_cbValid60(v_word_1047_);
return v___x_1078_;
}
}
else
{
uint8_t v___x_1079_; 
v___x_1079_ = lp_lean1090_Lean1090_Impl_cbValid50(v_word_1047_);
return v___x_1079_;
}
}
else
{
uint8_t v___x_1080_; 
v___x_1080_ = lp_lean1090_Lean1090_Impl_cbValid45(v_word_1047_);
return v___x_1080_;
}
}
else
{
uint8_t v___x_1081_; 
v___x_1081_ = lp_lean1090_Lean1090_Impl_cbValid44(v_word_1047_);
return v___x_1081_;
}
}
else
{
uint8_t v___x_1082_; 
v___x_1082_ = lp_lean1090_Lean1090_Impl_cbValid40(v_word_1047_);
return v___x_1082_;
}
}
else
{
lean_object* v___x_1083_; lean_object* v___x_1084_; lean_object* v___x_1085_; uint8_t v___x_1086_; 
v___x_1083_ = lean_unsigned_to_nat(1u);
v___x_1084_ = lean_unsigned_to_nat(8u);
v___x_1085_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1047_, v___x_1083_, v___x_1084_);
v___x_1086_ = lean_nat_dec_eq(v___x_1085_, v___x_1066_);
lean_dec(v___x_1085_);
return v___x_1086_;
}
}
else
{
uint8_t v___x_1087_; 
v___x_1087_ = lp_lean1090_Lean1090_Impl_cbValid21(v_word_1047_);
return v___x_1087_;
}
}
else
{
lean_object* v___x_1088_; lean_object* v___x_1089_; lean_object* v___x_1090_; uint8_t v___x_1091_; 
v___x_1088_ = lean_unsigned_to_nat(1u);
v___x_1089_ = lean_unsigned_to_nat(8u);
v___x_1090_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1047_, v___x_1088_, v___x_1089_);
v___x_1091_ = lean_nat_dec_eq(v___x_1090_, v___x_1062_);
lean_dec(v___x_1090_);
return v___x_1091_;
}
}
else
{
uint8_t v___x_1092_; 
v___x_1092_ = lp_lean1090_Lean1090_Impl_cbValid19(v_word_1047_);
return v___x_1092_;
}
}
else
{
uint8_t v___x_1093_; 
v___x_1093_ = lp_lean1090_Lean1090_Impl_cbValid18(v_word_1047_);
return v___x_1093_;
}
}
else
{
uint8_t v___x_1094_; 
v___x_1094_ = lp_lean1090_Lean1090_Impl_cbValid17(v_word_1047_);
return v___x_1094_;
}
}
else
{
lean_object* v___x_1095_; lean_object* v___x_1096_; lean_object* v___x_1097_; uint8_t v___x_1098_; 
v___x_1095_ = lean_unsigned_to_nat(1u);
v___x_1096_ = lean_unsigned_to_nat(8u);
v___x_1097_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1047_, v___x_1095_, v___x_1096_);
v___x_1098_ = lean_nat_dec_eq(v___x_1097_, v___x_1054_);
lean_dec(v___x_1097_);
if (v___x_1098_ == 0)
{
return v___x_1098_;
}
else
{
lean_object* v___x_1099_; lean_object* v___x_1100_; lean_object* v___x_1101_; uint8_t v___x_1102_; 
v___x_1099_ = lean_unsigned_to_nat(10u);
v___x_1100_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1047_, v___x_1099_, v___x_1050_);
v___x_1101_ = lean_unsigned_to_nat(0u);
v___x_1102_ = lean_nat_dec_eq(v___x_1100_, v___x_1101_);
lean_dec(v___x_1100_);
return v___x_1102_;
}
}
}
else
{
lean_object* v___x_1103_; lean_object* v___x_1104_; lean_object* v___x_1105_; uint8_t v___x_1106_; 
v___x_1103_ = lean_unsigned_to_nat(1u);
v___x_1104_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1047_, v___x_1103_, v___x_1050_);
v___x_1105_ = lean_unsigned_to_nat(31u);
v___x_1106_ = lean_nat_dec_eq(v___x_1104_, v___x_1105_);
lean_dec(v___x_1104_);
if (v___x_1106_ == 0)
{
return v___x_1106_;
}
else
{
lean_object* v___x_1107_; lean_object* v___x_1108_; lean_object* v___x_1109_; lean_object* v___x_1110_; uint8_t v___x_1111_; 
v___x_1107_ = lean_unsigned_to_nat(6u);
v___x_1108_ = lean_unsigned_to_nat(3u);
v___x_1109_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1047_, v___x_1107_, v___x_1108_);
v___x_1110_ = lean_unsigned_to_nat(2u);
v___x_1111_ = lean_nat_dec_lt(v___x_1109_, v___x_1110_);
lean_dec(v___x_1109_);
if (v___x_1111_ == 0)
{
return v___x_1111_;
}
else
{
uint8_t v___x_1112_; 
v___x_1112_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1047_);
return v___x_1112_;
}
}
}
}
else
{
lean_object* v___x_1113_; lean_object* v_tc_1114_; lean_object* v___x_1121_; uint8_t v___x_1122_; 
v___x_1113_ = lean_unsigned_to_nat(1u);
v_tc_1114_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1047_, v___x_1113_, v___x_1050_);
v___x_1121_ = lean_unsigned_to_nat(9u);
v___x_1122_ = lean_nat_dec_le(v___x_1121_, v_tc_1114_);
if (v___x_1122_ == 0)
{
goto v___jp_1115_;
}
else
{
lean_object* v___x_1123_; uint8_t v___x_1124_; 
v___x_1123_ = lean_unsigned_to_nat(18u);
v___x_1124_ = lean_nat_dec_le(v_tc_1114_, v___x_1123_);
if (v___x_1124_ == 0)
{
goto v___jp_1115_;
}
else
{
uint8_t v___x_1125_; 
lean_dec(v_tc_1114_);
v___x_1125_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1047_);
return v___x_1125_;
}
}
v___jp_1115_:
{
lean_object* v___x_1116_; uint8_t v___x_1117_; 
v___x_1116_ = lean_unsigned_to_nat(20u);
v___x_1117_ = lean_nat_dec_le(v___x_1116_, v_tc_1114_);
if (v___x_1117_ == 0)
{
lean_dec(v_tc_1114_);
return v___x_1117_;
}
else
{
lean_object* v___x_1118_; uint8_t v___x_1119_; 
v___x_1118_ = lean_unsigned_to_nat(22u);
v___x_1119_ = lean_nat_dec_le(v_tc_1114_, v___x_1118_);
lean_dec(v_tc_1114_);
if (v___x_1119_ == 0)
{
return v___x_1119_;
}
else
{
uint8_t v___x_1120_; 
v___x_1120_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1047_);
return v___x_1120_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsWireValid___boxed(lean_object* v_register_1126_, lean_object* v_word_1127_){
_start:
{
uint8_t v_res_1128_; lean_object* v_r_1129_; 
v_res_1128_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1126_, v_word_1127_);
lean_dec(v_word_1127_);
lean_dec(v_register_1126_);
v_r_1129_ = lean_box(v_res_1128_);
return v_r_1129_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_bdsLayout___closed__0(void){
_start:
{
lean_object* v___x_1130_; lean_object* v___x_1131_; 
v___x_1130_ = lp_lean1090_Lean1090_Impl_adsbPositionLayout;
v___x_1131_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1131_, 0, v___x_1130_);
return v___x_1131_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsLayout(lean_object* v_register_1132_, lean_object* v_word_1133_){
_start:
{
lean_object* v___x_1134_; uint8_t v___x_1135_; 
v___x_1134_ = lean_unsigned_to_nat(5u);
v___x_1135_ = lean_nat_dec_eq(v_register_1132_, v___x_1134_);
if (v___x_1135_ == 0)
{
lean_object* v___x_1136_; uint8_t v___x_1137_; 
v___x_1136_ = lean_unsigned_to_nat(101u);
v___x_1137_ = lean_nat_dec_eq(v_register_1132_, v___x_1136_);
if (v___x_1137_ == 0)
{
lean_object* v___x_1138_; 
v___x_1138_ = lp_lean1090_Lean1090_Impl_commBLayout(v_register_1132_);
return v___x_1138_;
}
else
{
lean_object* v___x_1139_; 
v___x_1139_ = lp_lean1090_Lean1090_Impl_adsbLayout(v_word_1133_);
return v___x_1139_;
}
}
else
{
lean_object* v___x_1140_; 
v___x_1140_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_bdsLayout___closed__0, &lp_lean1090_Lean1090_Impl_bdsLayout___closed__0_once, _init_lp_lean1090_Lean1090_Impl_bdsLayout___closed__0);
return v___x_1140_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsLayout___boxed(lean_object* v_register_1141_, lean_object* v_word_1142_){
_start:
{
lean_object* v_res_1143_; 
v_res_1143_ = lp_lean1090_Lean1090_Impl_bdsLayout(v_register_1141_, v_word_1142_);
lean_dec(v_word_1142_);
lean_dec(v_register_1141_);
return v_res_1143_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeBDS(lean_object* v_register_1144_, lean_object* v_word_1145_){
_start:
{
lean_object* v___x_1146_; 
v___x_1146_ = lp_lean1090_Lean1090_Impl_bdsLayout(v_register_1144_, v_word_1145_);
if (lean_obj_tag(v___x_1146_) == 0)
{
lean_object* v___x_1147_; 
lean_dec(v_register_1144_);
v___x_1147_ = lean_box(0);
return v___x_1147_;
}
else
{
lean_object* v_val_1148_; lean_object* v___x_1150_; uint8_t v_isShared_1151_; uint8_t v_isSharedCheck_1159_; 
v_val_1148_ = lean_ctor_get(v___x_1146_, 0);
v_isSharedCheck_1159_ = !lean_is_exclusive(v___x_1146_);
if (v_isSharedCheck_1159_ == 0)
{
v___x_1150_ = v___x_1146_;
v_isShared_1151_ = v_isSharedCheck_1159_;
goto v_resetjp_1149_;
}
else
{
lean_inc(v_val_1148_);
lean_dec(v___x_1146_);
v___x_1150_ = lean_box(0);
v_isShared_1151_ = v_isSharedCheck_1159_;
goto v_resetjp_1149_;
}
v_resetjp_1149_:
{
uint8_t v___x_1152_; 
v___x_1152_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1144_, v_word_1145_);
if (v___x_1152_ == 0)
{
lean_object* v___x_1153_; 
lean_del_object(v___x_1150_);
lean_dec(v_val_1148_);
lean_dec(v_register_1144_);
v___x_1153_ = lean_box(0);
return v___x_1153_;
}
else
{
lean_object* v___x_1154_; lean_object* v___x_1155_; lean_object* v___x_1157_; 
v___x_1154_ = lp_lean1090_Lean1090_Impl_decodePayloadFields(v_val_1148_, v_word_1145_);
v___x_1155_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1155_, 0, v_register_1144_);
lean_ctor_set(v___x_1155_, 1, v___x_1154_);
if (v_isShared_1151_ == 0)
{
lean_ctor_set(v___x_1150_, 0, v___x_1155_);
v___x_1157_ = v___x_1150_;
goto v_reusejp_1156_;
}
else
{
lean_object* v_reuseFailAlloc_1158_; 
v_reuseFailAlloc_1158_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1158_, 0, v___x_1155_);
v___x_1157_ = v_reuseFailAlloc_1158_;
goto v_reusejp_1156_;
}
v_reusejp_1156_:
{
return v___x_1157_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeBDS___boxed(lean_object* v_register_1160_, lean_object* v_word_1161_){
_start:
{
lean_object* v_res_1162_; 
v_res_1162_ = lp_lean1090_Lean1090_Impl_decodeBDS(v_register_1160_, v_word_1161_);
lean_dec(v_word_1161_);
return v_res_1162_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__0(void){
_start:
{
lean_object* v___x_1163_; lean_object* v___x_1164_; 
v___x_1163_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0);
v___x_1164_ = l_Rat_neg(v___x_1163_);
return v___x_1164_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1(void){
_start:
{
lean_object* v___x_1165_; lean_object* v___x_1166_; 
v___x_1165_ = lean_unsigned_to_nat(2u);
v___x_1166_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1165_);
return v___x_1166_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__2(void){
_start:
{
lean_object* v___x_1167_; lean_object* v___x_1168_; lean_object* v___x_1169_; 
v___x_1167_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1168_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__0, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__0);
v___x_1169_ = l_Rat_div(v___x_1168_, v___x_1167_);
return v___x_1169_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGaussian(lean_object* v_value_1170_, lean_object* v_mu_1171_, lean_object* v_sigma_1172_){
_start:
{
lean_object* v___x_1173_; lean_object* v___x_1174_; lean_object* v___x_1175_; lean_object* v_z_1176_; lean_object* v___x_1177_; lean_object* v___x_1178_; lean_object* v___x_1179_; 
v___x_1173_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_mu_1171_);
v___x_1174_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_value_1170_, v___x_1173_);
v___x_1175_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_sigma_1172_);
v_z_1176_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1174_, v___x_1175_);
lean_dec_ref(v___x_1174_);
v___x_1177_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__2, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__2);
lean_inc_ref(v_z_1176_);
v___x_1178_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1177_, v_z_1176_);
v___x_1179_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1178_, v_z_1176_);
lean_dec_ref(v___x_1178_);
return v___x_1179_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbLaplace(lean_object* v_value_1180_, lean_object* v_median_1181_, lean_object* v_scale_1182_){
_start:
{
lean_object* v___x_1183_; uint8_t v___x_1184_; 
v___x_1183_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_scale_1182_);
v___x_1184_ = l_Rat_instDecidableLe(v_scale_1182_, v___x_1183_);
if (v___x_1184_ == 0)
{
lean_object* v___x_1185_; lean_object* v___x_1186_; lean_object* v___x_1187_; lean_object* v___x_1188_; lean_object* v___x_1189_; lean_object* v___x_1190_; 
v___x_1185_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_median_1181_);
v___x_1186_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_value_1180_, v___x_1185_);
v___x_1187_ = l_Rat_abs(v___x_1186_);
v___x_1188_ = l_Rat_neg(v___x_1187_);
v___x_1189_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_scale_1182_);
v___x_1190_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1188_, v___x_1189_);
lean_dec_ref(v___x_1188_);
return v___x_1190_;
}
else
{
lean_dec_ref(v_scale_1182_);
lean_dec_ref(v_median_1181_);
lean_dec_ref(v_value_1180_);
return v___x_1183_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScoreField(lean_object* v_value_1191_, lean_object* v_score_1192_){
_start:
{
if (lean_obj_tag(v_value_1191_) == 0)
{
lean_object* v___x_1193_; 
lean_dec_ref(v_score_1192_);
v___x_1193_ = lean_box(0);
return v___x_1193_;
}
else
{
lean_object* v_val_1194_; lean_object* v___x_1195_; lean_object* v___x_1196_; lean_object* v___x_1197_; 
v_val_1194_ = lean_ctor_get(v_value_1191_, 0);
lean_inc(v_val_1194_);
lean_dec_ref_known(v_value_1191_, 1);
v___x_1195_ = lean_apply_1(v_score_1192_, v_val_1194_);
v___x_1196_ = lean_box(0);
v___x_1197_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1197_, 0, v___x_1195_);
lean_ctor_set(v___x_1197_, 1, v___x_1196_);
return v___x_1197_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1198_; lean_object* v___x_1199_; 
v___x_1198_ = lean_unsigned_to_nat(142u);
v___x_1199_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1198_);
return v___x_1199_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1(void){
_start:
{
lean_object* v___x_1200_; lean_object* v___x_1201_; 
v___x_1200_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0);
v___x_1201_ = l_Rat_neg(v___x_1200_);
return v___x_1201_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2(void){
_start:
{
lean_object* v___x_1202_; lean_object* v___x_1203_; lean_object* v___x_1204_; 
v___x_1202_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1203_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1);
v___x_1204_ = l_Rat_div(v___x_1203_, v___x_1202_);
return v___x_1204_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3(void){
_start:
{
lean_object* v___x_1205_; lean_object* v___x_1206_; 
v___x_1205_ = lean_unsigned_to_nat(164u);
v___x_1206_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1205_);
return v___x_1206_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4(void){
_start:
{
lean_object* v___x_1207_; lean_object* v___x_1208_; lean_object* v___x_1209_; 
v___x_1207_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1208_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3);
v___x_1209_ = l_Rat_div(v___x_1208_, v___x_1207_);
return v___x_1209_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0(lean_object* v_x_1210_){
_start:
{
lean_object* v___x_1211_; lean_object* v___x_1212_; lean_object* v___x_1213_; 
v___x_1211_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2);
v___x_1212_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4);
v___x_1213_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1210_, v___x_1211_, v___x_1212_);
return v___x_1213_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0(void){
_start:
{
lean_object* v___x_1214_; lean_object* v___x_1215_; 
v___x_1214_ = lean_unsigned_to_nat(393u);
v___x_1215_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1214_);
return v___x_1215_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1(void){
_start:
{
lean_object* v___x_1216_; lean_object* v___x_1217_; 
v___x_1216_ = lean_unsigned_to_nat(290u);
v___x_1217_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1216_);
return v___x_1217_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1(lean_object* v_x_1218_){
_start:
{
lean_object* v___x_1219_; lean_object* v___x_1220_; lean_object* v___x_1221_; 
v___x_1219_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0);
v___x_1220_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1);
v___x_1221_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1218_, v___x_1219_, v___x_1220_);
return v___x_1221_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0(void){
_start:
{
lean_object* v___x_1222_; lean_object* v___x_1223_; 
v___x_1222_ = lean_unsigned_to_nat(52u);
v___x_1223_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1222_);
return v___x_1223_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1(void){
_start:
{
lean_object* v___x_1224_; lean_object* v___x_1225_; 
v___x_1224_ = lean_unsigned_to_nat(29u);
v___x_1225_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1224_);
return v___x_1225_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2(lean_object* v_x_1226_){
_start:
{
lean_object* v___x_1227_; lean_object* v___x_1228_; lean_object* v___x_1229_; 
v___x_1227_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0);
v___x_1228_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1);
v___x_1229_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1226_, v___x_1227_, v___x_1228_);
return v___x_1229_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0(void){
_start:
{
lean_object* v___x_1230_; lean_object* v___x_1231_; 
v___x_1230_ = lean_unsigned_to_nat(272u);
v___x_1231_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1230_);
return v___x_1231_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1(void){
_start:
{
lean_object* v___x_1232_; lean_object* v___x_1233_; 
v___x_1232_ = lean_unsigned_to_nat(55u);
v___x_1233_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1232_);
return v___x_1233_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4(lean_object* v_x_1234_){
_start:
{
lean_object* v___x_1235_; lean_object* v___x_1236_; lean_object* v___x_1237_; 
v___x_1235_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0);
v___x_1236_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1);
v___x_1237_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1234_, v___x_1235_, v___x_1236_);
return v___x_1237_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0(void){
_start:
{
lean_object* v___x_1238_; lean_object* v___x_1239_; 
v___x_1238_ = lean_unsigned_to_nat(69u);
v___x_1239_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1238_);
return v___x_1239_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1(void){
_start:
{
lean_object* v___x_1240_; lean_object* v___x_1241_; 
v___x_1240_ = lean_unsigned_to_nat(100u);
v___x_1241_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1240_);
return v___x_1241_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2(void){
_start:
{
lean_object* v___x_1242_; lean_object* v___x_1243_; lean_object* v___x_1244_; 
v___x_1242_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1243_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0);
v___x_1244_ = l_Rat_div(v___x_1243_, v___x_1242_);
return v___x_1244_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3(void){
_start:
{
lean_object* v___x_1245_; lean_object* v___x_1246_; 
v___x_1245_ = lean_unsigned_to_nat(21u);
v___x_1246_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1245_);
return v___x_1246_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4(void){
_start:
{
lean_object* v___x_1247_; lean_object* v___x_1248_; lean_object* v___x_1249_; 
v___x_1247_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1248_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3);
v___x_1249_ = l_Rat_div(v___x_1248_, v___x_1247_);
return v___x_1249_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3(lean_object* v_x_1250_){
_start:
{
lean_object* v___x_1251_; lean_object* v___x_1252_; lean_object* v___x_1253_; 
v___x_1251_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2);
v___x_1252_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4);
v___x_1253_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1250_, v___x_1251_, v___x_1252_);
return v___x_1253_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0(void){
_start:
{
lean_object* v___x_1254_; lean_object* v___x_1255_; 
v___x_1254_ = lean_unsigned_to_nat(298u);
v___x_1255_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1254_);
return v___x_1255_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1(void){
_start:
{
lean_object* v___x_1256_; lean_object* v___x_1257_; 
v___x_1256_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0);
v___x_1257_ = l_Rat_neg(v___x_1256_);
return v___x_1257_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2(void){
_start:
{
lean_object* v___x_1258_; lean_object* v___x_1259_; 
v___x_1258_ = lean_unsigned_to_nat(1669u);
v___x_1259_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1258_);
return v___x_1259_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5(lean_object* v_x_1260_){
_start:
{
lean_object* v___x_1261_; lean_object* v___x_1262_; lean_object* v___x_1263_; 
v___x_1261_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1);
v___x_1262_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2);
v___x_1263_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1260_, v___x_1261_, v___x_1262_);
return v___x_1263_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0(void){
_start:
{
lean_object* v___x_1264_; lean_object* v___x_1265_; 
v___x_1264_ = lean_unsigned_to_nat(418u);
v___x_1265_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1264_);
return v___x_1265_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1(void){
_start:
{
lean_object* v___x_1266_; lean_object* v___x_1267_; 
v___x_1266_ = lean_unsigned_to_nat(129u);
v___x_1267_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1266_);
return v___x_1267_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6(lean_object* v_x_1268_){
_start:
{
lean_object* v___x_1269_; lean_object* v___x_1270_; lean_object* v___x_1271_; 
v___x_1269_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0);
v___x_1270_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1);
v___x_1271_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1268_, v___x_1269_, v___x_1270_);
return v___x_1271_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0(void){
_start:
{
lean_object* v___x_1272_; lean_object* v___x_1273_; 
v___x_1272_ = lean_unsigned_to_nat(413u);
v___x_1273_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1272_);
return v___x_1273_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1(void){
_start:
{
lean_object* v___x_1274_; lean_object* v___x_1275_; 
v___x_1274_ = lean_unsigned_to_nat(120u);
v___x_1275_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1274_);
return v___x_1275_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7(lean_object* v_x_1276_){
_start:
{
lean_object* v___x_1277_; lean_object* v___x_1278_; lean_object* v___x_1279_; 
v___x_1277_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0);
v___x_1278_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1);
v___x_1279_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1276_, v___x_1277_, v___x_1278_);
return v___x_1279_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0(void){
_start:
{
lean_object* v___x_1280_; lean_object* v___x_1281_; 
v___x_1280_ = lean_unsigned_to_nat(70u);
v___x_1281_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1280_);
return v___x_1281_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1(void){
_start:
{
lean_object* v___x_1282_; lean_object* v___x_1283_; lean_object* v___x_1284_; 
v___x_1282_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1283_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0);
v___x_1284_ = l_Rat_div(v___x_1283_, v___x_1282_);
return v___x_1284_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8(lean_object* v_x_1285_){
_start:
{
lean_object* v___x_1286_; lean_object* v___x_1287_; lean_object* v___x_1288_; 
v___x_1286_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1287_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1);
v___x_1288_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1285_, v___x_1286_, v___x_1287_);
return v___x_1288_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__9(lean_object* v_x_1289_){
_start:
{
lean_object* v___x_1290_; lean_object* v___x_1291_; lean_object* v___x_1292_; 
v___x_1290_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1291_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1292_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1289_, v___x_1290_, v___x_1291_);
return v___x_1292_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0(void){
_start:
{
lean_object* v___x_1293_; lean_object* v___x_1294_; 
v___x_1293_ = lean_unsigned_to_nat(24688u);
v___x_1294_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1293_);
return v___x_1294_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1(void){
_start:
{
lean_object* v___x_1295_; lean_object* v___x_1296_; 
v___x_1295_ = lean_unsigned_to_nat(10844u);
v___x_1296_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1295_);
return v___x_1296_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10(lean_object* v_x_1297_){
_start:
{
lean_object* v___x_1298_; lean_object* v___x_1299_; lean_object* v___x_1300_; 
v___x_1298_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0);
v___x_1299_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1);
v___x_1300_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1297_, v___x_1298_, v___x_1299_);
return v___x_1300_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0(void){
_start:
{
lean_object* v___x_1301_; lean_object* v___x_1302_; 
v___x_1301_ = lean_unsigned_to_nat(10132u);
v___x_1302_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1301_);
return v___x_1302_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1(void){
_start:
{
lean_object* v___x_1303_; lean_object* v___x_1304_; lean_object* v___x_1305_; 
v___x_1303_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1304_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0);
v___x_1305_ = l_Rat_div(v___x_1304_, v___x_1303_);
return v___x_1305_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2(void){
_start:
{
lean_object* v___x_1306_; lean_object* v___x_1307_; 
v___x_1306_ = lean_unsigned_to_nat(54u);
v___x_1307_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1306_);
return v___x_1307_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3(void){
_start:
{
lean_object* v___x_1308_; lean_object* v___x_1309_; lean_object* v___x_1310_; 
v___x_1308_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1309_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2);
v___x_1310_ = l_Rat_div(v___x_1309_, v___x_1308_);
return v___x_1310_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11(lean_object* v_x_1311_){
_start:
{
lean_object* v___x_1312_; lean_object* v___x_1313_; lean_object* v___x_1314_; 
v___x_1312_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1);
v___x_1313_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3);
v___x_1314_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1311_, v___x_1312_, v___x_1313_);
return v___x_1314_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5(void){
_start:
{
lean_object* v___x_1320_; lean_object* v___x_1321_; 
v___x_1320_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3);
v___x_1321_ = l_Rat_neg(v___x_1320_);
return v___x_1321_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6(void){
_start:
{
lean_object* v___x_1322_; lean_object* v___x_1323_; 
v___x_1322_ = lean_unsigned_to_nat(990u);
v___x_1323_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1322_);
return v___x_1323_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7(void){
_start:
{
lean_object* v___x_1324_; lean_object* v___x_1325_; lean_object* v___x_1326_; 
v___x_1324_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1325_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6);
v___x_1326_ = l_Rat_div(v___x_1325_, v___x_1324_);
return v___x_1326_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms(lean_object* v_register_1344_, lean_object* v_word_1345_){
_start:
{
lean_object* v___x_1346_; uint8_t v___x_1347_; 
v___x_1346_ = lean_unsigned_to_nat(64u);
v___x_1347_ = lean_nat_dec_eq(v_register_1344_, v___x_1346_);
if (v___x_1347_ == 0)
{
lean_object* v___x_1348_; uint8_t v___x_1349_; 
v___x_1348_ = lean_unsigned_to_nat(80u);
v___x_1349_ = lean_nat_dec_eq(v_register_1344_, v___x_1348_);
if (v___x_1349_ == 0)
{
lean_object* v___x_1350_; uint8_t v___x_1351_; 
v___x_1350_ = lean_unsigned_to_nat(96u);
v___x_1351_ = lean_nat_dec_eq(v_register_1344_, v___x_1350_);
if (v___x_1351_ == 0)
{
lean_object* v___x_1352_; uint8_t v___x_1353_; 
v___x_1352_ = lean_unsigned_to_nat(68u);
v___x_1353_ = lean_nat_dec_eq(v_register_1344_, v___x_1352_);
if (v___x_1353_ == 0)
{
lean_object* v___x_1354_; uint8_t v___x_1355_; 
v___x_1354_ = lean_unsigned_to_nat(69u);
v___x_1355_ = lean_nat_dec_eq(v_register_1344_, v___x_1354_);
if (v___x_1355_ == 0)
{
lean_object* v___x_1356_; 
v___x_1356_ = lean_box(0);
return v___x_1356_;
}
else
{
lean_object* v___f_1357_; lean_object* v___f_1358_; lean_object* v___x_1359_; lean_object* v___x_1360_; lean_object* v___x_1361_; lean_object* v___x_1362_; lean_object* v___x_1363_; lean_object* v___x_1364_; lean_object* v___x_1365_; 
v___f_1357_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__0));
v___f_1358_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1));
v___x_1359_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__2));
v___x_1360_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1359_);
v___x_1361_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1360_, v___f_1357_);
v___x_1362_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__3));
v___x_1363_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1362_);
v___x_1364_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1363_, v___f_1358_);
v___x_1365_ = l_List_appendTR___redArg(v___x_1361_, v___x_1364_);
return v___x_1365_;
}
}
else
{
lean_object* v___f_1366_; lean_object* v___f_1367_; lean_object* v___x_1368_; lean_object* v___x_1369_; lean_object* v___x_1370_; lean_object* v___x_1371_; lean_object* v___x_1372_; lean_object* v___x_1373_; lean_object* v___x_1374_; lean_object* v___x_1375_; lean_object* v___x_1376_; lean_object* v___x_1377_; lean_object* v___x_1378_; lean_object* v___x_1379_; lean_object* v___x_1380_; lean_object* v___x_1381_; 
v___f_1366_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__4));
v___f_1367_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1));
v___x_1368_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_1345_);
v___x_1369_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5);
v___x_1370_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7);
v___x_1371_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1368_, v___x_1369_, v___x_1370_);
v___x_1372_ = lean_box(0);
v___x_1373_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1373_, 0, v___x_1371_);
lean_ctor_set(v___x_1373_, 1, v___x_1372_);
v___x_1374_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__8));
v___x_1375_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1374_);
v___x_1376_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1375_, v___f_1366_);
v___x_1377_ = l_List_appendTR___redArg(v___x_1373_, v___x_1376_);
v___x_1378_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__9));
v___x_1379_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1378_);
v___x_1380_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1379_, v___f_1367_);
v___x_1381_ = l_List_appendTR___redArg(v___x_1377_, v___x_1380_);
return v___x_1381_;
}
}
else
{
lean_object* v___f_1382_; lean_object* v___f_1383_; lean_object* v___f_1384_; lean_object* v___x_1385_; lean_object* v___x_1386_; lean_object* v___x_1387_; lean_object* v___y_1389_; lean_object* v___x_1396_; lean_object* v___x_1397_; 
v___f_1382_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__10));
v___f_1383_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__11));
v___f_1384_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__12));
v___x_1385_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13));
v___x_1386_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1385_);
v___x_1387_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1386_, v___f_1382_);
v___x_1396_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14));
v___x_1397_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1396_);
if (lean_obj_tag(v___x_1397_) == 0)
{
v___y_1389_ = v___x_1397_;
goto v___jp_1388_;
}
else
{
lean_object* v___x_1399_; uint8_t v_isShared_1400_; uint8_t v_isSharedCheck_1405_; 
v_isSharedCheck_1405_ = !lean_is_exclusive(v___x_1397_);
if (v_isSharedCheck_1405_ == 0)
{
lean_object* v_unused_1406_; 
v_unused_1406_ = lean_ctor_get(v___x_1397_, 0);
lean_dec(v_unused_1406_);
v___x_1399_ = v___x_1397_;
v_isShared_1400_ = v_isSharedCheck_1405_;
goto v_resetjp_1398_;
}
else
{
lean_dec(v___x_1397_);
v___x_1399_ = lean_box(0);
v_isShared_1400_ = v_isSharedCheck_1405_;
goto v_resetjp_1398_;
}
v_resetjp_1398_:
{
lean_object* v___x_1401_; lean_object* v___x_1403_; 
v___x_1401_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_1345_);
if (v_isShared_1400_ == 0)
{
lean_ctor_set(v___x_1399_, 0, v___x_1401_);
v___x_1403_ = v___x_1399_;
goto v_reusejp_1402_;
}
else
{
lean_object* v_reuseFailAlloc_1404_; 
v_reuseFailAlloc_1404_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1404_, 0, v___x_1401_);
v___x_1403_ = v_reuseFailAlloc_1404_;
goto v_reusejp_1402_;
}
v_reusejp_1402_:
{
v___y_1389_ = v___x_1403_;
goto v___jp_1388_;
}
}
}
v___jp_1388_:
{
lean_object* v___x_1390_; lean_object* v___x_1391_; lean_object* v___x_1392_; lean_object* v___x_1393_; lean_object* v___x_1394_; lean_object* v___x_1395_; 
v___x_1390_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___y_1389_, v___f_1383_);
v___x_1391_ = l_List_appendTR___redArg(v___x_1387_, v___x_1390_);
v___x_1392_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__2));
v___x_1393_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1392_);
v___x_1394_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1393_, v___f_1384_);
v___x_1395_ = l_List_appendTR___redArg(v___x_1391_, v___x_1394_);
return v___x_1395_;
}
}
}
else
{
lean_object* v___f_1407_; lean_object* v___f_1408_; lean_object* v___f_1409_; lean_object* v___f_1410_; lean_object* v___x_1411_; lean_object* v___x_1412_; lean_object* v___x_1413_; lean_object* v___x_1414_; lean_object* v___x_1415_; lean_object* v___x_1416_; lean_object* v___x_1417_; lean_object* v___x_1418_; lean_object* v___x_1419_; lean_object* v___x_1420_; lean_object* v___x_1421_; lean_object* v___x_1422_; lean_object* v___x_1423_; lean_object* v___x_1424_; lean_object* v___x_1425_; 
v___f_1407_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__15));
v___f_1408_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__16));
v___f_1409_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__17));
v___f_1410_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__18));
v___x_1411_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19));
v___x_1412_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1411_);
v___x_1413_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1412_, v___f_1410_);
v___x_1414_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__4));
v___x_1415_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1414_);
v___x_1416_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1415_, v___f_1409_);
v___x_1417_ = l_List_appendTR___redArg(v___x_1413_, v___x_1416_);
v___x_1418_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__20));
v___x_1419_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1418_);
v___x_1420_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1419_, v___f_1408_);
v___x_1421_ = l_List_appendTR___redArg(v___x_1417_, v___x_1420_);
v___x_1422_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__21));
v___x_1423_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1422_);
v___x_1424_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1423_, v___f_1407_);
v___x_1425_ = l_List_appendTR___redArg(v___x_1421_, v___x_1424_);
return v___x_1425_;
}
}
else
{
lean_object* v___f_1426_; lean_object* v___f_1427_; lean_object* v___y_1429_; lean_object* v___x_1439_; lean_object* v___x_1440_; 
v___f_1426_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__22));
v___f_1427_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__23));
v___x_1439_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__24));
v___x_1440_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1439_);
if (lean_obj_tag(v___x_1440_) == 0)
{
v___y_1429_ = v___x_1440_;
goto v___jp_1428_;
}
else
{
lean_object* v___x_1442_; uint8_t v_isShared_1443_; uint8_t v_isSharedCheck_1448_; 
v_isSharedCheck_1448_ = !lean_is_exclusive(v___x_1440_);
if (v_isSharedCheck_1448_ == 0)
{
lean_object* v_unused_1449_; 
v_unused_1449_ = lean_ctor_get(v___x_1440_, 0);
lean_dec(v_unused_1449_);
v___x_1442_ = v___x_1440_;
v_isShared_1443_ = v_isSharedCheck_1448_;
goto v_resetjp_1441_;
}
else
{
lean_dec(v___x_1440_);
v___x_1442_ = lean_box(0);
v_isShared_1443_ = v_isSharedCheck_1448_;
goto v_resetjp_1441_;
}
v_resetjp_1441_:
{
lean_object* v___x_1444_; lean_object* v___x_1446_; 
v___x_1444_ = lp_lean1090_Lean1090_Impl_cbQNH64(v_word_1345_);
if (v_isShared_1443_ == 0)
{
lean_ctor_set(v___x_1442_, 0, v___x_1444_);
v___x_1446_ = v___x_1442_;
goto v_reusejp_1445_;
}
else
{
lean_object* v_reuseFailAlloc_1447_; 
v_reuseFailAlloc_1447_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1447_, 0, v___x_1444_);
v___x_1446_ = v_reuseFailAlloc_1447_;
goto v_reusejp_1445_;
}
v_reusejp_1445_:
{
v___y_1429_ = v___x_1446_;
goto v___jp_1428_;
}
}
}
v___jp_1428_:
{
lean_object* v___x_1430_; lean_object* v___x_1431_; lean_object* v___x_1432_; lean_object* v___x_1433_; lean_object* v___x_1434_; lean_object* v___x_1435_; lean_object* v___x_1436_; lean_object* v___x_1437_; lean_object* v___x_1438_; 
v___x_1430_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___y_1429_, v___f_1427_);
v___x_1431_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__6));
v___x_1432_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1431_);
v___x_1433_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1432_, v___f_1426_);
v___x_1434_ = l_List_appendTR___redArg(v___x_1430_, v___x_1433_);
v___x_1435_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__7));
v___x_1436_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1344_, v_word_1345_, v___x_1435_);
v___x_1437_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1436_, v___f_1426_);
v___x_1438_ = l_List_appendTR___redArg(v___x_1434_, v___x_1437_);
return v___x_1438_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___boxed(lean_object* v_register_1450_, lean_object* v_word_1451_){
_start:
{
lean_object* v_res_1452_; 
v_res_1452_ = lp_lean1090_Lean1090_Impl_cbDensityTerms(v_register_1450_, v_word_1451_);
lean_dec(v_word_1451_);
lean_dec(v_register_1450_);
return v_res_1452_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_cbDensity_spec__0(lean_object* v_x_1453_, lean_object* v_x_1454_){
_start:
{
if (lean_obj_tag(v_x_1454_) == 0)
{
return v_x_1453_;
}
else
{
lean_object* v_head_1455_; lean_object* v_tail_1456_; lean_object* v___x_1457_; 
v_head_1455_ = lean_ctor_get(v_x_1454_, 0);
lean_inc(v_head_1455_);
v_tail_1456_ = lean_ctor_get(v_x_1454_, 1);
lean_inc(v_tail_1456_);
lean_dec_ref_known(v_x_1454_, 2);
v___x_1457_ = lp_lean1090_Lean1090_Impl_Binary64_add(v_x_1453_, v_head_1455_);
v_x_1453_ = v___x_1457_;
v_x_1454_ = v_tail_1456_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensity(lean_object* v_register_1459_, lean_object* v_word_1460_){
_start:
{
lean_object* v_terms_1461_; uint8_t v___x_1462_; 
v_terms_1461_ = lp_lean1090_Lean1090_Impl_cbDensityTerms(v_register_1459_, v_word_1460_);
v___x_1462_ = l_List_isEmpty___redArg(v_terms_1461_);
if (v___x_1462_ == 0)
{
lean_object* v___x_1463_; lean_object* v___x_1464_; lean_object* v___x_1465_; lean_object* v___x_1466_; lean_object* v___x_1467_; 
v___x_1463_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc(v_terms_1461_);
v___x_1464_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_cbDensity_spec__0(v___x_1463_, v_terms_1461_);
v___x_1465_ = l_List_lengthTR___redArg(v_terms_1461_);
lean_dec(v_terms_1461_);
v___x_1466_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1465_);
v___x_1467_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1464_, v___x_1466_);
lean_dec_ref(v___x_1464_);
return v___x_1467_;
}
else
{
lean_object* v___x_1468_; 
lean_dec(v_terms_1461_);
v___x_1468_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1468_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensity___boxed(lean_object* v_register_1469_, lean_object* v_word_1470_){
_start:
{
lean_object* v_res_1471_; 
v_res_1471_ = lp_lean1090_Lean1090_Impl_cbDensity(v_register_1469_, v_word_1470_);
lean_dec(v_word_1470_);
lean_dec(v_register_1469_);
return v_res_1471_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1472_; lean_object* v___x_1473_; 
v___x_1472_ = lean_unsigned_to_nat(1023u);
v___x_1473_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1472_);
return v___x_1473_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0(lean_object* v_code_1474_){
_start:
{
lean_object* v___x_1475_; lean_object* v___x_1476_; lean_object* v___x_1477_; lean_object* v___x_1478_; lean_object* v___x_1479_; lean_object* v___x_1480_; lean_object* v___x_1481_; lean_object* v___x_1482_; lean_object* v___x_1483_; lean_object* v___x_1484_; lean_object* v___x_1485_; 
v___x_1475_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1476_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1477_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1474_);
v___x_1478_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0);
v___x_1479_ = l_Rat_sub(v___x_1477_, v___x_1478_);
v___x_1480_ = l_Rat_mul(v___x_1476_, v___x_1479_);
v___x_1481_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_1480_);
v___x_1482_ = l_Rat_abs(v___x_1481_);
v___x_1483_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1484_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1482_, v___x_1483_);
lean_dec_ref(v___x_1482_);
v___x_1485_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v___x_1475_, v___x_1484_);
return v___x_1485_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1(void){
_start:
{
lean_object* v___f_1487_; lean_object* v___x_1488_; lean_object* v___x_1489_; 
v___f_1487_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__0));
v___x_1488_ = lean_unsigned_to_nat(2047u);
v___x_1489_ = l_Array_ofFn___redArg(v___x_1488_, v___f_1487_);
return v___x_1489_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable(void){
_start:
{
lean_object* v___x_1490_; 
v___x_1490_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1, &lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1);
return v___x_1490_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenalty50(lean_object* v_word_1491_){
_start:
{
lean_object* v___x_1492_; lean_object* v___x_1493_; lean_object* v___x_1494_; lean_object* v___x_1495_; uint8_t v___x_1496_; 
v___x_1492_ = lean_unsigned_to_nat(46u);
v___x_1493_ = lean_unsigned_to_nat(1u);
v___x_1494_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1491_, v___x_1492_, v___x_1493_);
v___x_1495_ = lean_unsigned_to_nat(0u);
v___x_1496_ = lean_nat_dec_eq(v___x_1494_, v___x_1495_);
lean_dec(v___x_1494_);
if (v___x_1496_ == 0)
{
lean_object* v___x_1497_; lean_object* v___x_1498_; uint8_t v___x_1499_; 
v___x_1497_ = lean_unsigned_to_nat(24u);
v___x_1498_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1491_, v___x_1497_, v___x_1493_);
v___x_1499_ = lean_nat_dec_eq(v___x_1498_, v___x_1495_);
lean_dec(v___x_1498_);
if (v___x_1499_ == 0)
{
lean_object* v___x_1500_; lean_object* v___x_1501_; lean_object* v_tas_1502_; lean_object* v___x_1503_; lean_object* v_gs_1504_; lean_object* v___x_1505_; lean_object* v___x_1506_; lean_object* v___x_1507_; lean_object* v___x_1508_; lean_object* v___x_1509_; 
v___x_1500_ = lean_unsigned_to_nat(47u);
v___x_1501_ = lean_unsigned_to_nat(10u);
v_tas_1502_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1491_, v___x_1500_, v___x_1501_);
v___x_1503_ = lean_unsigned_to_nat(25u);
v_gs_1504_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1491_, v___x_1503_, v___x_1501_);
v___x_1505_ = lp_lean1090_Lean1090_Impl_cbWindPenaltyTable;
v___x_1506_ = lean_unsigned_to_nat(1023u);
v___x_1507_ = lean_nat_add(v_tas_1502_, v___x_1506_);
lean_dec(v_tas_1502_);
v___x_1508_ = lean_nat_sub(v___x_1507_, v_gs_1504_);
lean_dec(v_gs_1504_);
lean_dec(v___x_1507_);
v___x_1509_ = lean_array_fget_borrowed(v___x_1505_, v___x_1508_);
lean_dec(v___x_1508_);
lean_inc(v___x_1509_);
return v___x_1509_;
}
else
{
lean_object* v___x_1510_; 
v___x_1510_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1510_;
}
}
else
{
lean_object* v___x_1511_; 
v___x_1511_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1511_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenalty50___boxed(lean_object* v_word_1512_){
_start:
{
lean_object* v_res_1513_; 
v_res_1513_ = lp_lean1090_Lean1090_Impl_cbWindPenalty50(v_word_1512_);
lean_dec(v_word_1512_);
return v_res_1513_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0(void){
_start:
{
lean_object* v___x_1514_; lean_object* v___x_1515_; 
v___x_1514_ = lean_unsigned_to_nat(3u);
v___x_1515_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1514_);
return v___x_1515_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1(void){
_start:
{
lean_object* v___x_1516_; lean_object* v___x_1517_; 
v___x_1516_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__0, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0);
v___x_1517_ = l_Rat_neg(v___x_1516_);
return v___x_1517_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__2(void){
_start:
{
lean_object* v___x_1518_; lean_object* v___x_1519_; 
v___x_1518_ = lean_unsigned_to_nat(250u);
v___x_1519_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1518_);
return v___x_1519_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__3(void){
_start:
{
lean_object* v___x_1520_; lean_object* v___x_1521_; 
v___x_1520_ = lean_unsigned_to_nat(5u);
v___x_1521_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1520_);
return v___x_1521_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__4(void){
_start:
{
lean_object* v___x_1522_; lean_object* v___x_1523_; lean_object* v___x_1524_; 
v___x_1522_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1523_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__0, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0);
v___x_1524_ = l_Rat_div(v___x_1523_, v___x_1522_);
return v___x_1524_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__5(void){
_start:
{
lean_object* v___x_1525_; lean_object* v___x_1526_; 
v___x_1525_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__4, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__4);
v___x_1526_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_1525_);
return v___x_1526_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPenalty(lean_object* v_register_1527_, lean_object* v_word_1528_){
_start:
{
lean_object* v___x_1531_; uint8_t v___x_1532_; 
v___x_1531_ = lean_unsigned_to_nat(80u);
v___x_1532_ = lean_nat_dec_eq(v_register_1527_, v___x_1531_);
if (v___x_1532_ == 0)
{
lean_object* v___x_1533_; uint8_t v___x_1534_; 
v___x_1533_ = lean_unsigned_to_nat(96u);
v___x_1534_ = lean_nat_dec_eq(v_register_1527_, v___x_1533_);
if (v___x_1534_ == 0)
{
lean_object* v___x_1535_; 
v___x_1535_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1535_;
}
else
{
lean_object* v___x_1536_; lean_object* v___x_1537_; 
v___x_1536_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13));
v___x_1537_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1527_, v_word_1528_, v___x_1536_);
if (lean_obj_tag(v___x_1537_) == 1)
{
lean_object* v_val_1538_; lean_object* v___x_1539_; lean_object* v___x_1540_; 
v_val_1538_ = lean_ctor_get(v___x_1537_, 0);
lean_inc(v_val_1538_);
lean_dec_ref_known(v___x_1537_, 1);
v___x_1539_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14));
v___x_1540_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1527_, v_word_1528_, v___x_1539_);
if (lean_obj_tag(v___x_1540_) == 1)
{
lean_object* v_mach_1541_; lean_object* v___x_1542_; uint8_t v___y_1544_; uint8_t v___x_1546_; uint8_t v___y_1548_; 
lean_dec_ref_known(v___x_1540_, 1);
v_mach_1541_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_1528_);
v___x_1542_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_mach_1541_);
v___x_1546_ = l_Rat_blt(v___x_1542_, v_mach_1541_);
if (v___x_1546_ == 0)
{
lean_dec_ref(v_mach_1541_);
lean_dec(v_val_1538_);
return v___x_1542_;
}
else
{
lean_object* v_ratio_1549_; lean_object* v___x_1550_; uint8_t v___x_1551_; 
v_ratio_1549_ = lp_lean1090_Lean1090_Impl_Binary64_div(v_val_1538_, v_mach_1541_);
lean_dec(v_val_1538_);
v___x_1550_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__2, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__2);
lean_inc_ref(v_ratio_1549_);
v___x_1551_ = l_Rat_blt(v_ratio_1549_, v___x_1550_);
if (v___x_1551_ == 0)
{
lean_object* v___x_1552_; uint8_t v___x_1553_; 
v___x_1552_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4);
v___x_1553_ = l_Rat_blt(v___x_1552_, v_ratio_1549_);
v___y_1548_ = v___x_1553_;
goto v___jp_1547_;
}
else
{
lean_dec_ref(v_ratio_1549_);
v___y_1548_ = v___x_1546_;
goto v___jp_1547_;
}
}
v___jp_1543_:
{
if (v___y_1544_ == 0)
{
return v___x_1542_;
}
else
{
lean_object* v___x_1545_; 
v___x_1545_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__1, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1);
return v___x_1545_;
}
}
v___jp_1547_:
{
if (v___x_1546_ == 0)
{
v___y_1544_ = v___x_1546_;
goto v___jp_1543_;
}
else
{
v___y_1544_ = v___y_1548_;
goto v___jp_1543_;
}
}
}
else
{
lean_dec(v___x_1540_);
lean_dec(v_val_1538_);
goto v___jp_1529_;
}
}
else
{
lean_dec(v___x_1537_);
goto v___jp_1529_;
}
}
}
else
{
lean_object* v_p_1554_; uint8_t v___y_1556_; lean_object* v___x_1559_; lean_object* v___x_1560_; 
v_p_1554_ = lp_lean1090_Lean1090_Impl_cbWindPenalty50(v_word_1528_);
v___x_1559_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19));
v___x_1560_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1527_, v_word_1528_, v___x_1559_);
if (lean_obj_tag(v___x_1560_) == 1)
{
lean_object* v_val_1561_; lean_object* v___x_1562_; lean_object* v___x_1563_; 
v_val_1561_ = lean_ctor_get(v___x_1560_, 0);
lean_inc(v_val_1561_);
lean_dec_ref_known(v___x_1560_, 1);
v___x_1562_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__4));
v___x_1563_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1527_, v_word_1528_, v___x_1562_);
if (lean_obj_tag(v___x_1563_) == 1)
{
lean_object* v_val_1564_; uint8_t v___y_1566_; lean_object* v___x_1570_; lean_object* v___x_1571_; uint8_t v___x_1572_; 
v_val_1564_ = lean_ctor_get(v___x_1563_, 0);
lean_inc(v_val_1564_);
lean_dec_ref_known(v___x_1563_, 1);
v___x_1570_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__3, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__3);
lean_inc(v_val_1561_);
v___x_1571_ = l_Rat_abs(v_val_1561_);
v___x_1572_ = l_Rat_blt(v___x_1570_, v___x_1571_);
if (v___x_1572_ == 0)
{
v___y_1566_ = v___x_1572_;
goto v___jp_1565_;
}
else
{
lean_object* v___x_1573_; lean_object* v___x_1574_; uint8_t v___x_1575_; 
v___x_1573_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__5, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__5);
lean_inc(v_val_1564_);
v___x_1574_ = l_Rat_abs(v_val_1564_);
v___x_1575_ = l_Rat_blt(v___x_1573_, v___x_1574_);
v___y_1566_ = v___x_1575_;
goto v___jp_1565_;
}
v___jp_1565_:
{
if (v___y_1566_ == 0)
{
lean_dec(v_val_1564_);
lean_dec(v_val_1561_);
return v_p_1554_;
}
else
{
lean_object* v___x_1567_; uint8_t v___x_1568_; uint8_t v___x_1569_; 
v___x_1567_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1568_ = l_Rat_blt(v___x_1567_, v_val_1561_);
v___x_1569_ = l_Rat_blt(v___x_1567_, v_val_1564_);
if (v___x_1569_ == 0)
{
if (v___x_1568_ == 0)
{
return v_p_1554_;
}
else
{
v___y_1556_ = v___x_1569_;
goto v___jp_1555_;
}
}
else
{
v___y_1556_ = v___x_1568_;
goto v___jp_1555_;
}
}
}
}
else
{
lean_dec(v___x_1563_);
lean_dec(v_val_1561_);
return v_p_1554_;
}
}
else
{
lean_dec(v___x_1560_);
return v_p_1554_;
}
v___jp_1555_:
{
if (v___y_1556_ == 0)
{
lean_object* v___x_1557_; lean_object* v___x_1558_; 
v___x_1557_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1558_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_p_1554_, v___x_1557_);
return v___x_1558_;
}
else
{
return v_p_1554_;
}
}
}
v___jp_1529_:
{
lean_object* v___x_1530_; 
v___x_1530_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1530_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPenalty___boxed(lean_object* v_register_1576_, lean_object* v_word_1577_){
_start:
{
lean_object* v_res_1578_; 
v_res_1578_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_1576_, v_word_1577_);
lean_dec(v_word_1577_);
lean_dec(v_register_1576_);
return v_res_1578_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCombinedScore(lean_object* v_register_1579_, lean_object* v_word_1580_){
_start:
{
lean_object* v___x_1581_; lean_object* v___x_1582_; lean_object* v___x_1583_; 
v___x_1581_ = lp_lean1090_Lean1090_Impl_cbDensity(v_register_1579_, v_word_1580_);
v___x_1582_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_1579_, v_word_1580_);
v___x_1583_ = lp_lean1090_Lean1090_Impl_Binary64_add(v___x_1581_, v___x_1582_);
return v___x_1583_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCombinedScore___boxed(lean_object* v_register_1584_, lean_object* v_word_1585_){
_start:
{
lean_object* v_res_1586_; 
v_res_1586_ = lp_lean1090_Lean1090_Impl_cbCombinedScore(v_register_1584_, v_word_1585_);
lean_dec(v_word_1585_);
lean_dec(v_register_1584_);
return v_res_1586_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHScoreTable___lam__0(lean_object* v_code_1587_){
_start:
{
lean_object* v___x_1588_; lean_object* v___x_1589_; lean_object* v___x_1590_; lean_object* v___x_1591_; lean_object* v___x_1592_; lean_object* v___x_1593_; lean_object* v___x_1594_; lean_object* v___x_1595_; 
v___x_1588_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1587_);
v___x_1589_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3);
v___x_1590_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1588_, v___x_1589_);
lean_dec_ref(v___x_1588_);
v___x_1591_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4);
v___x_1592_ = lp_lean1090_Lean1090_Impl_Binary64_add(v___x_1590_, v___x_1591_);
v___x_1593_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1);
v___x_1594_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3);
v___x_1595_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1592_, v___x_1593_, v___x_1594_);
return v___x_1595_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1597_; lean_object* v___x_1598_; lean_object* v___x_1599_; 
v___f_1597_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__0));
v___x_1598_ = lean_unsigned_to_nat(4096u);
v___x_1599_ = l_Array_ofFn___redArg(v___x_1598_, v___f_1597_);
return v___x_1599_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable(void){
_start:
{
lean_object* v___x_1600_; 
v___x_1600_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1);
return v___x_1600_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0(lean_object* v_code_1601_){
_start:
{
lean_object* v___x_1602_; lean_object* v___x_1603_; lean_object* v___x_1604_; lean_object* v___x_1605_; 
v___x_1602_ = lp_lean1090_Lean1090_Impl_cbSelected(v_code_1601_);
v___x_1603_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0);
v___x_1604_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1);
v___x_1605_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1602_, v___x_1603_, v___x_1604_);
return v___x_1605_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0___boxed(lean_object* v_code_1606_){
_start:
{
lean_object* v_res_1607_; 
v_res_1607_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0(v_code_1606_);
lean_dec(v_code_1606_);
return v_res_1607_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1609_; lean_object* v___x_1610_; lean_object* v___x_1611_; 
v___f_1609_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__0));
v___x_1610_ = lean_unsigned_to_nat(4096u);
v___x_1611_ = l_Array_ofFn___redArg(v___x_1610_, v___f_1609_);
return v___x_1611_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable(void){
_start:
{
lean_object* v___x_1612_; 
v___x_1612_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1);
return v___x_1612_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1613_; lean_object* v___x_1614_; lean_object* v___x_1615_; 
v___x_1613_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1614_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid50___closed__0, &lp_lean1090_Lean1090_Impl_cbValid50___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid50___closed__0);
v___x_1615_ = l_Rat_div(v___x_1614_, v___x_1613_);
return v___x_1615_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0(lean_object* v_code_1616_){
_start:
{
uint8_t v___x_1617_; lean_object* v___x_1618_; lean_object* v___x_1619_; lean_object* v___x_1620_; lean_object* v___x_1621_; lean_object* v___x_1622_; lean_object* v___x_1623_; lean_object* v___x_1624_; lean_object* v___x_1625_; 
v___x_1617_ = 1;
v___x_1618_ = lean_unsigned_to_nat(10u);
v___x_1619_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1617_, v___x_1618_, v_code_1616_);
v___x_1620_ = l_Rat_ofInt(v___x_1619_);
v___x_1621_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0);
v___x_1622_ = l_Rat_mul(v___x_1620_, v___x_1621_);
lean_dec_ref(v___x_1620_);
v___x_1623_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1624_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1625_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1622_, v___x_1623_, v___x_1624_);
return v___x_1625_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1627_; lean_object* v___x_1628_; lean_object* v___x_1629_; 
v___f_1627_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__0));
v___x_1628_ = lean_unsigned_to_nat(1024u);
v___x_1629_ = l_Array_ofFn___redArg(v___x_1628_, v___f_1627_);
return v___x_1629_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable(void){
_start:
{
lean_object* v___x_1630_; 
v___x_1630_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1);
return v___x_1630_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1631_; lean_object* v___x_1632_; 
v___x_1631_ = lean_unsigned_to_nat(8u);
v___x_1632_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1631_);
return v___x_1632_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1(void){
_start:
{
lean_object* v___x_1633_; lean_object* v___x_1634_; lean_object* v___x_1635_; 
v___x_1633_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1634_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0);
v___x_1635_ = l_Rat_div(v___x_1634_, v___x_1633_);
return v___x_1635_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0(lean_object* v_code_1636_){
_start:
{
uint8_t v___x_1637_; lean_object* v___x_1638_; lean_object* v___x_1639_; lean_object* v___x_1640_; lean_object* v___x_1641_; lean_object* v___x_1642_; lean_object* v___x_1643_; lean_object* v___x_1644_; lean_object* v___x_1645_; 
v___x_1637_ = 1;
v___x_1638_ = lean_unsigned_to_nat(10u);
v___x_1639_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1637_, v___x_1638_, v_code_1636_);
v___x_1640_ = l_Rat_ofInt(v___x_1639_);
v___x_1641_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1);
v___x_1642_ = l_Rat_mul(v___x_1640_, v___x_1641_);
lean_dec_ref(v___x_1640_);
v___x_1643_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1644_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1);
v___x_1645_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1642_, v___x_1643_, v___x_1644_);
return v___x_1645_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1647_; lean_object* v___x_1648_; lean_object* v___x_1649_; 
v___f_1647_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__0));
v___x_1648_ = lean_unsigned_to_nat(1024u);
v___x_1649_ = l_Array_ofFn___redArg(v___x_1648_, v___f_1647_);
return v___x_1649_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable(void){
_start:
{
lean_object* v___x_1650_; 
v___x_1650_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1);
return v___x_1650_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTASScoreTable___lam__0(lean_object* v_code_1651_){
_start:
{
lean_object* v___x_1652_; lean_object* v___x_1653_; lean_object* v___x_1654_; lean_object* v___x_1655_; lean_object* v___x_1656_; lean_object* v___x_1657_; 
v___x_1652_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1651_);
v___x_1653_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1654_ = l_Rat_mul(v___x_1652_, v___x_1653_);
lean_dec_ref(v___x_1652_);
v___x_1655_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0);
v___x_1656_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1);
v___x_1657_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1654_, v___x_1655_, v___x_1656_);
return v___x_1657_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1659_; lean_object* v___x_1660_; lean_object* v___x_1661_; 
v___f_1659_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__0));
v___x_1660_ = lean_unsigned_to_nat(1024u);
v___x_1661_ = l_Array_ofFn___redArg(v___x_1660_, v___f_1659_);
return v___x_1661_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable(void){
_start:
{
lean_object* v___x_1662_; 
v___x_1662_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1);
return v___x_1662_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___lam__0(lean_object* v_code_1663_){
_start:
{
lean_object* v___x_1664_; lean_object* v___x_1665_; lean_object* v___x_1666_; lean_object* v___x_1667_; lean_object* v___x_1668_; lean_object* v___x_1669_; 
v___x_1664_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1663_);
v___x_1665_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1666_ = l_Rat_mul(v___x_1664_, v___x_1665_);
lean_dec_ref(v___x_1664_);
v___x_1667_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0);
v___x_1668_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1);
v___x_1669_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1666_, v___x_1667_, v___x_1668_);
return v___x_1669_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1671_; lean_object* v___x_1672_; lean_object* v___x_1673_; 
v___f_1671_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__0));
v___x_1672_ = lean_unsigned_to_nat(1024u);
v___x_1673_ = l_Array_ofFn___redArg(v___x_1672_, v___f_1671_);
return v___x_1673_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable(void){
_start:
{
lean_object* v___x_1674_; 
v___x_1674_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1);
return v___x_1674_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbIASScoreTable___lam__0(lean_object* v_code_1675_){
_start:
{
lean_object* v___x_1676_; lean_object* v___x_1677_; lean_object* v___x_1678_; lean_object* v___x_1679_; 
v___x_1676_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1675_);
v___x_1677_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0);
v___x_1678_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1);
v___x_1679_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1676_, v___x_1677_, v___x_1678_);
return v___x_1679_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1681_; lean_object* v___x_1682_; lean_object* v___x_1683_; 
v___f_1681_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__0));
v___x_1682_ = lean_unsigned_to_nat(1024u);
v___x_1683_ = l_Array_ofFn___redArg(v___x_1682_, v___f_1681_);
return v___x_1683_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable(void){
_start:
{
lean_object* v___x_1684_; 
v___x_1684_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1);
return v___x_1684_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachScoreTable___lam__0(lean_object* v_code_1685_){
_start:
{
lean_object* v___x_1686_; lean_object* v___x_1687_; lean_object* v___x_1688_; lean_object* v___x_1689_; lean_object* v___x_1690_; lean_object* v___x_1691_; lean_object* v___x_1692_; lean_object* v___x_1693_; 
v___x_1686_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1685_);
v___x_1687_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2);
v___x_1688_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1686_, v___x_1687_);
lean_dec_ref(v___x_1686_);
v___x_1689_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3);
v___x_1690_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1688_, v___x_1689_);
lean_dec_ref(v___x_1688_);
v___x_1691_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2);
v___x_1692_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4);
v___x_1693_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1690_, v___x_1691_, v___x_1692_);
return v___x_1693_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1695_; lean_object* v___x_1696_; lean_object* v___x_1697_; 
v___f_1695_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__0));
v___x_1696_ = lean_unsigned_to_nat(1024u);
v___x_1697_ = l_Array_ofFn___redArg(v___x_1696_, v___f_1695_);
return v___x_1697_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable(void){
_start:
{
lean_object* v___x_1698_; 
v___x_1698_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1);
return v___x_1698_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___lam__0(lean_object* v_code_1699_){
_start:
{
lean_object* v___y_1701_; lean_object* v___x_1705_; lean_object* v___x_1706_; lean_object* v___x_1707_; uint8_t v___x_1710_; 
v___x_1705_ = lean_unsigned_to_nat(512u);
v___x_1706_ = lean_nat_mod(v_code_1699_, v___x_1705_);
v___x_1707_ = lean_unsigned_to_nat(0u);
v___x_1710_ = lean_nat_dec_eq(v___x_1706_, v___x_1707_);
if (v___x_1710_ == 0)
{
lean_object* v___x_1711_; uint8_t v___x_1712_; 
v___x_1711_ = lean_unsigned_to_nat(511u);
v___x_1712_ = lean_nat_dec_eq(v___x_1706_, v___x_1711_);
lean_dec(v___x_1706_);
if (v___x_1712_ == 0)
{
uint8_t v___x_1713_; lean_object* v___x_1714_; lean_object* v___x_1715_; lean_object* v___x_1716_; lean_object* v___x_1717_; lean_object* v___x_1718_; 
v___x_1713_ = 1;
v___x_1714_ = lean_unsigned_to_nat(10u);
v___x_1715_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1713_, v___x_1714_, v_code_1699_);
v___x_1716_ = l_Rat_ofInt(v___x_1715_);
v___x_1717_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__0, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__0);
v___x_1718_ = l_Rat_mul(v___x_1716_, v___x_1717_);
lean_dec_ref(v___x_1716_);
v___y_1701_ = v___x_1718_;
goto v___jp_1700_;
}
else
{
lean_dec(v_code_1699_);
goto v___jp_1708_;
}
}
else
{
lean_dec(v___x_1706_);
lean_dec(v_code_1699_);
goto v___jp_1708_;
}
v___jp_1700_:
{
lean_object* v___x_1702_; lean_object* v___x_1703_; lean_object* v___x_1704_; 
v___x_1702_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1);
v___x_1703_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2);
v___x_1704_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___y_1701_, v___x_1702_, v___x_1703_);
return v___x_1704_;
}
v___jp_1708_:
{
lean_object* v___x_1709_; 
v___x_1709_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___y_1701_ = v___x_1709_;
goto v___jp_1700_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1720_; lean_object* v___x_1721_; lean_object* v___x_1722_; 
v___f_1720_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__0));
v___x_1721_ = lean_unsigned_to_nat(1024u);
v___x_1722_ = l_Array_ofFn___redArg(v___x_1721_, v___f_1720_);
return v___x_1722_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable(void){
_start:
{
lean_object* v___x_1723_; 
v___x_1723_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1);
return v___x_1723_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___lam__0(lean_object* v_code_1724_){
_start:
{
lean_object* v___y_1726_; uint8_t v___x_1730_; lean_object* v___x_1731_; lean_object* v___x_1732_; lean_object* v___x_1733_; lean_object* v___x_1734_; lean_object* v_initial_1735_; lean_object* v___x_1736_; uint8_t v___x_1737_; 
v___x_1730_ = 1;
v___x_1731_ = lean_unsigned_to_nat(11u);
v___x_1732_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1730_, v___x_1731_, v_code_1724_);
v___x_1733_ = l_Rat_ofInt(v___x_1732_);
v___x_1734_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v_initial_1735_ = l_Rat_div(v___x_1733_, v___x_1734_);
lean_dec_ref(v___x_1733_);
v___x_1736_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
lean_inc_ref(v_initial_1735_);
v___x_1737_ = l_Rat_blt(v_initial_1735_, v___x_1736_);
if (v___x_1737_ == 0)
{
v___y_1726_ = v_initial_1735_;
goto v___jp_1725_;
}
else
{
lean_object* v___x_1738_; lean_object* v___x_1739_; 
v___x_1738_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1739_ = l_Rat_add(v_initial_1735_, v___x_1738_);
v___y_1726_ = v___x_1739_;
goto v___jp_1725_;
}
v___jp_1725_:
{
lean_object* v___x_1727_; lean_object* v___x_1728_; lean_object* v___x_1729_; 
v___x_1727_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5);
v___x_1728_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7);
v___x_1729_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___y_1726_, v___x_1727_, v___x_1728_);
return v___x_1729_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1741_; lean_object* v___x_1742_; lean_object* v___x_1743_; 
v___f_1741_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__0));
v___x_1742_ = lean_unsigned_to_nat(2048u);
v___x_1743_ = l_Array_ofFn___redArg(v___x_1742_, v___f_1741_);
return v___x_1743_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable(void){
_start:
{
lean_object* v___x_1744_; 
v___x_1744_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1);
return v___x_1744_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindScoreTable___lam__0(lean_object* v_code_1745_){
_start:
{
lean_object* v___x_1746_; lean_object* v___x_1747_; lean_object* v___x_1748_; lean_object* v___x_1749_; 
v___x_1746_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1745_);
v___x_1747_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0);
v___x_1748_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1);
v___x_1749_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1746_, v___x_1747_, v___x_1748_);
return v___x_1749_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1751_; lean_object* v___x_1752_; lean_object* v___x_1753_; 
v___f_1751_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__0));
v___x_1752_ = lean_unsigned_to_nat(512u);
v___x_1753_ = l_Array_ofFn___redArg(v___x_1752_, v___f_1751_);
return v___x_1753_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable(void){
_start:
{
lean_object* v___x_1754_; 
v___x_1754_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1);
return v___x_1754_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPressureScoreTable___lam__0(lean_object* v_code_1755_){
_start:
{
lean_object* v___x_1756_; lean_object* v___x_1757_; lean_object* v___x_1758_; lean_object* v___x_1759_; 
v___x_1756_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1755_);
v___x_1757_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0);
v___x_1758_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1);
v___x_1759_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1756_, v___x_1757_, v___x_1758_);
return v___x_1759_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1761_; lean_object* v___x_1762_; lean_object* v___x_1763_; 
v___f_1761_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__0));
v___x_1762_ = lean_unsigned_to_nat(2048u);
v___x_1763_ = l_Array_ofFn___redArg(v___x_1762_, v___f_1761_);
return v___x_1763_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable(void){
_start:
{
lean_object* v___x_1764_; 
v___x_1764_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1);
return v___x_1764_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1765_; lean_object* v___x_1766_; lean_object* v___x_1767_; 
v___x_1765_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v___x_1766_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0);
v___x_1767_ = l_Rat_div(v___x_1766_, v___x_1765_);
return v___x_1767_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0(lean_object* v_code_1768_){
_start:
{
uint8_t v___x_1769_; lean_object* v___x_1770_; lean_object* v___x_1771_; lean_object* v___x_1772_; lean_object* v___x_1773_; lean_object* v___x_1774_; lean_object* v___x_1775_; lean_object* v___x_1776_; lean_object* v___x_1777_; 
v___x_1769_ = 1;
v___x_1770_ = lean_unsigned_to_nat(10u);
v___x_1771_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1769_, v___x_1770_, v_code_1768_);
v___x_1772_ = l_Rat_ofInt(v___x_1771_);
v___x_1773_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0);
v___x_1774_ = l_Rat_mul(v___x_1772_, v___x_1773_);
lean_dec_ref(v___x_1772_);
v___x_1775_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2);
v___x_1776_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4);
v___x_1777_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1774_, v___x_1775_, v___x_1776_);
return v___x_1777_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1779_; lean_object* v___x_1780_; lean_object* v___x_1781_; 
v___f_1779_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__0));
v___x_1780_ = lean_unsigned_to_nat(1024u);
v___x_1781_ = l_Array_ofFn___redArg(v___x_1780_, v___f_1779_);
return v___x_1781_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable(void){
_start:
{
lean_object* v___x_1782_; 
v___x_1782_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1);
return v___x_1782_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg(lean_object* v_width_1783_, lean_object* v_table_1784_, lean_object* v_word_1785_, lean_object* v_start_1786_){
_start:
{
lean_object* v___x_1787_; lean_object* v___x_1788_; 
v___x_1787_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1785_, v_start_1786_, v_width_1783_);
v___x_1788_ = lean_array_fget_borrowed(v_table_1784_, v___x_1787_);
lean_dec(v___x_1787_);
lean_inc(v___x_1788_);
return v___x_1788_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg___boxed(lean_object* v_width_1789_, lean_object* v_table_1790_, lean_object* v_word_1791_, lean_object* v_start_1792_){
_start:
{
lean_object* v_res_1793_; 
v_res_1793_ = lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg(v_width_1789_, v_table_1790_, v_word_1791_, v_start_1792_);
lean_dec(v_start_1792_);
lean_dec(v_word_1791_);
lean_dec_ref(v_table_1790_);
lean_dec(v_width_1789_);
return v_res_1793_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet(lean_object* v_width_1794_, lean_object* v_table_1795_, lean_object* v_size_1796_, lean_object* v_word_1797_, lean_object* v_start_1798_){
_start:
{
lean_object* v___x_1799_; lean_object* v___x_1800_; 
v___x_1799_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1797_, v_start_1798_, v_width_1794_);
v___x_1800_ = lean_array_fget_borrowed(v_table_1795_, v___x_1799_);
lean_dec(v___x_1799_);
lean_inc(v___x_1800_);
return v___x_1800_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___boxed(lean_object* v_width_1801_, lean_object* v_table_1802_, lean_object* v_size_1803_, lean_object* v_word_1804_, lean_object* v_start_1805_){
_start:
{
lean_object* v_res_1806_; 
v_res_1806_ = lp_lean1090_Lean1090_Impl_cbDensityTableGet(v_width_1801_, v_table_1802_, v_size_1803_, v_word_1804_, v_start_1805_);
lean_dec(v_start_1805_);
lean_dec(v_word_1804_);
lean_dec_ref(v_table_1802_);
lean_dec(v_width_1801_);
return v_res_1806_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTermsFast(lean_object* v_register_1807_, lean_object* v_word_1808_){
_start:
{
lean_object* v___x_1809_; uint8_t v___x_1810_; 
v___x_1809_ = lean_unsigned_to_nat(64u);
v___x_1810_ = lean_nat_dec_eq(v_register_1807_, v___x_1809_);
if (v___x_1810_ == 0)
{
lean_object* v___x_1811_; uint8_t v___x_1812_; 
v___x_1811_ = lean_unsigned_to_nat(80u);
v___x_1812_ = lean_nat_dec_eq(v_register_1807_, v___x_1811_);
if (v___x_1812_ == 0)
{
lean_object* v___x_1813_; uint8_t v___x_1814_; 
v___x_1813_ = lean_unsigned_to_nat(96u);
v___x_1814_ = lean_nat_dec_eq(v_register_1807_, v___x_1813_);
if (v___x_1814_ == 0)
{
lean_object* v___x_1815_; uint8_t v___x_1816_; 
v___x_1815_ = lean_unsigned_to_nat(68u);
v___x_1816_ = lean_nat_dec_eq(v_register_1807_, v___x_1815_);
if (v___x_1816_ == 0)
{
lean_object* v___x_1817_; uint8_t v___x_1818_; 
v___x_1817_ = lean_unsigned_to_nat(69u);
v___x_1818_ = lean_nat_dec_eq(v_register_1807_, v___x_1817_);
if (v___x_1818_ == 0)
{
lean_object* v___x_1819_; 
v___x_1819_ = lean_box(0);
return v___x_1819_;
}
else
{
lean_object* v___x_1820_; lean_object* v___x_1821_; lean_object* v___x_1822_; lean_object* v___x_1823_; lean_object* v___y_1825_; uint8_t v___x_1839_; 
v___x_1820_ = lean_unsigned_to_nat(16u);
v___x_1821_ = lean_unsigned_to_nat(1u);
v___x_1822_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1820_, v___x_1821_);
v___x_1823_ = lean_unsigned_to_nat(0u);
v___x_1839_ = lean_nat_dec_eq(v___x_1822_, v___x_1823_);
lean_dec(v___x_1822_);
if (v___x_1839_ == 0)
{
lean_object* v___x_1840_; lean_object* v___x_1841_; lean_object* v___x_1842_; lean_object* v___x_1843_; lean_object* v___x_1844_; lean_object* v___x_1845_; lean_object* v___x_1846_; 
v___x_1840_ = lean_unsigned_to_nat(10u);
v___x_1841_ = lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable;
v___x_1842_ = lean_unsigned_to_nat(17u);
v___x_1843_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1842_, v___x_1840_);
v___x_1844_ = lean_array_fget_borrowed(v___x_1841_, v___x_1843_);
lean_dec(v___x_1843_);
v___x_1845_ = lean_box(0);
lean_inc(v___x_1844_);
v___x_1846_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1846_, 0, v___x_1844_);
lean_ctor_set(v___x_1846_, 1, v___x_1845_);
v___y_1825_ = v___x_1846_;
goto v___jp_1824_;
}
else
{
lean_object* v___x_1847_; 
v___x_1847_ = lean_box(0);
v___y_1825_ = v___x_1847_;
goto v___jp_1824_;
}
v___jp_1824_:
{
lean_object* v___x_1826_; lean_object* v___x_1827_; uint8_t v___x_1828_; 
v___x_1826_ = lean_unsigned_to_nat(27u);
v___x_1827_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1826_, v___x_1821_);
v___x_1828_ = lean_nat_dec_eq(v___x_1827_, v___x_1823_);
lean_dec(v___x_1827_);
if (v___x_1828_ == 0)
{
lean_object* v___x_1829_; lean_object* v___x_1830_; lean_object* v___x_1831_; lean_object* v___x_1832_; lean_object* v___x_1833_; lean_object* v___x_1834_; lean_object* v___x_1835_; lean_object* v___x_1836_; 
v___x_1829_ = lean_unsigned_to_nat(11u);
v___x_1830_ = lp_lean1090_Lean1090_Impl_cbPressureScoreTable;
v___x_1831_ = lean_unsigned_to_nat(28u);
v___x_1832_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1831_, v___x_1829_);
v___x_1833_ = lean_array_fget_borrowed(v___x_1830_, v___x_1832_);
lean_dec(v___x_1832_);
v___x_1834_ = lean_box(0);
lean_inc(v___x_1833_);
v___x_1835_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1835_, 0, v___x_1833_);
lean_ctor_set(v___x_1835_, 1, v___x_1834_);
v___x_1836_ = l_List_appendTR___redArg(v___y_1825_, v___x_1835_);
return v___x_1836_;
}
else
{
lean_object* v___x_1837_; lean_object* v___x_1838_; 
v___x_1837_ = lean_box(0);
v___x_1838_ = l_List_appendTR___redArg(v___y_1825_, v___x_1837_);
return v___x_1838_;
}
}
}
}
else
{
lean_object* v___x_1848_; lean_object* v___x_1849_; lean_object* v___x_1850_; lean_object* v___x_1851_; lean_object* v___x_1852_; lean_object* v___x_1853_; lean_object* v___x_1854_; lean_object* v___x_1855_; lean_object* v___x_1856_; lean_object* v___x_1857_; lean_object* v___x_1858_; lean_object* v___y_1860_; uint8_t v___x_1872_; 
v___x_1848_ = lean_unsigned_to_nat(11u);
v___x_1849_ = lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable;
v___x_1850_ = lean_unsigned_to_nat(24u);
v___x_1851_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1850_, v___x_1848_);
v___x_1852_ = lean_array_fget_borrowed(v___x_1849_, v___x_1851_);
lean_dec(v___x_1851_);
v___x_1853_ = lean_box(0);
lean_inc(v___x_1852_);
v___x_1854_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1854_, 0, v___x_1852_);
lean_ctor_set(v___x_1854_, 1, v___x_1853_);
v___x_1855_ = lean_unsigned_to_nat(5u);
v___x_1856_ = lean_unsigned_to_nat(1u);
v___x_1857_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1855_, v___x_1856_);
v___x_1858_ = lean_unsigned_to_nat(0u);
v___x_1872_ = lean_nat_dec_eq(v___x_1857_, v___x_1858_);
lean_dec(v___x_1857_);
if (v___x_1872_ == 0)
{
lean_object* v___x_1873_; lean_object* v___x_1874_; lean_object* v___x_1875_; lean_object* v___x_1876_; lean_object* v___x_1877_; lean_object* v___x_1878_; 
v___x_1873_ = lean_unsigned_to_nat(9u);
v___x_1874_ = lp_lean1090_Lean1090_Impl_cbWindScoreTable;
v___x_1875_ = lean_unsigned_to_nat(6u);
v___x_1876_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1875_, v___x_1873_);
v___x_1877_ = lean_array_fget_borrowed(v___x_1874_, v___x_1876_);
lean_dec(v___x_1876_);
lean_inc(v___x_1877_);
v___x_1878_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1878_, 0, v___x_1877_);
lean_ctor_set(v___x_1878_, 1, v___x_1853_);
v___y_1860_ = v___x_1878_;
goto v___jp_1859_;
}
else
{
v___y_1860_ = v___x_1853_;
goto v___jp_1859_;
}
v___jp_1859_:
{
lean_object* v___x_1861_; lean_object* v___x_1862_; lean_object* v___x_1863_; uint8_t v___x_1864_; 
v___x_1861_ = l_List_appendTR___redArg(v___x_1854_, v___y_1860_);
v___x_1862_ = lean_unsigned_to_nat(35u);
v___x_1863_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1862_, v___x_1856_);
v___x_1864_ = lean_nat_dec_eq(v___x_1863_, v___x_1858_);
lean_dec(v___x_1863_);
if (v___x_1864_ == 0)
{
lean_object* v___x_1865_; lean_object* v___x_1866_; lean_object* v___x_1867_; lean_object* v___x_1868_; lean_object* v___x_1869_; lean_object* v___x_1870_; 
v___x_1865_ = lp_lean1090_Lean1090_Impl_cbPressureScoreTable;
v___x_1866_ = lean_unsigned_to_nat(36u);
v___x_1867_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1866_, v___x_1848_);
v___x_1868_ = lean_array_fget_borrowed(v___x_1865_, v___x_1867_);
lean_dec(v___x_1867_);
lean_inc(v___x_1868_);
v___x_1869_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1869_, 0, v___x_1868_);
lean_ctor_set(v___x_1869_, 1, v___x_1853_);
v___x_1870_ = l_List_appendTR___redArg(v___x_1861_, v___x_1869_);
return v___x_1870_;
}
else
{
lean_object* v___x_1871_; 
v___x_1871_ = l_List_appendTR___redArg(v___x_1861_, v___x_1853_);
return v___x_1871_;
}
}
}
}
else
{
lean_object* v___x_1879_; lean_object* v___x_1880_; lean_object* v___x_1881_; lean_object* v___x_1882_; lean_object* v___y_1884_; lean_object* v___y_1885_; lean_object* v___y_1901_; uint8_t v___x_1913_; 
v___x_1879_ = lean_unsigned_to_nat(13u);
v___x_1880_ = lean_unsigned_to_nat(1u);
v___x_1881_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1879_, v___x_1880_);
v___x_1882_ = lean_unsigned_to_nat(0u);
v___x_1913_ = lean_nat_dec_eq(v___x_1881_, v___x_1882_);
lean_dec(v___x_1881_);
if (v___x_1913_ == 0)
{
lean_object* v___x_1914_; lean_object* v___x_1915_; lean_object* v___x_1916_; lean_object* v___x_1917_; lean_object* v___x_1918_; lean_object* v___x_1919_; lean_object* v___x_1920_; 
v___x_1914_ = lean_unsigned_to_nat(10u);
v___x_1915_ = lp_lean1090_Lean1090_Impl_cbIASScoreTable;
v___x_1916_ = lean_unsigned_to_nat(14u);
v___x_1917_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1916_, v___x_1914_);
v___x_1918_ = lean_array_fget_borrowed(v___x_1915_, v___x_1917_);
lean_dec(v___x_1917_);
v___x_1919_ = lean_box(0);
lean_inc(v___x_1918_);
v___x_1920_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1920_, 0, v___x_1918_);
lean_ctor_set(v___x_1920_, 1, v___x_1919_);
v___y_1901_ = v___x_1920_;
goto v___jp_1900_;
}
else
{
lean_object* v___x_1921_; 
v___x_1921_ = lean_box(0);
v___y_1901_ = v___x_1921_;
goto v___jp_1900_;
}
v___jp_1883_:
{
lean_object* v___x_1886_; lean_object* v___x_1887_; lean_object* v___x_1888_; uint8_t v___x_1889_; 
v___x_1886_ = l_List_appendTR___redArg(v___y_1884_, v___y_1885_);
v___x_1887_ = lean_unsigned_to_nat(46u);
v___x_1888_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1887_, v___x_1880_);
v___x_1889_ = lean_nat_dec_eq(v___x_1888_, v___x_1882_);
lean_dec(v___x_1888_);
if (v___x_1889_ == 0)
{
lean_object* v___x_1890_; lean_object* v___x_1891_; lean_object* v___x_1892_; lean_object* v___x_1893_; lean_object* v___x_1894_; lean_object* v___x_1895_; lean_object* v___x_1896_; lean_object* v___x_1897_; 
v___x_1890_ = lean_unsigned_to_nat(10u);
v___x_1891_ = lp_lean1090_Lean1090_Impl_cbVerticalScoreTable;
v___x_1892_ = lean_unsigned_to_nat(47u);
v___x_1893_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1892_, v___x_1890_);
v___x_1894_ = lean_array_fget_borrowed(v___x_1891_, v___x_1893_);
lean_dec(v___x_1893_);
v___x_1895_ = lean_box(0);
lean_inc(v___x_1894_);
v___x_1896_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1896_, 0, v___x_1894_);
lean_ctor_set(v___x_1896_, 1, v___x_1895_);
v___x_1897_ = l_List_appendTR___redArg(v___x_1886_, v___x_1896_);
return v___x_1897_;
}
else
{
lean_object* v___x_1898_; lean_object* v___x_1899_; 
v___x_1898_ = lean_box(0);
v___x_1899_ = l_List_appendTR___redArg(v___x_1886_, v___x_1898_);
return v___x_1899_;
}
}
v___jp_1900_:
{
lean_object* v___x_1902_; lean_object* v___x_1903_; uint8_t v___x_1904_; 
v___x_1902_ = lean_unsigned_to_nat(24u);
v___x_1903_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1902_, v___x_1880_);
v___x_1904_ = lean_nat_dec_eq(v___x_1903_, v___x_1882_);
lean_dec(v___x_1903_);
if (v___x_1904_ == 0)
{
lean_object* v___x_1905_; lean_object* v___x_1906_; lean_object* v___x_1907_; lean_object* v___x_1908_; lean_object* v___x_1909_; lean_object* v___x_1910_; lean_object* v___x_1911_; 
v___x_1905_ = lean_unsigned_to_nat(10u);
v___x_1906_ = lp_lean1090_Lean1090_Impl_cbMachScoreTable;
v___x_1907_ = lean_unsigned_to_nat(25u);
v___x_1908_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1907_, v___x_1905_);
v___x_1909_ = lean_array_fget_borrowed(v___x_1906_, v___x_1908_);
lean_dec(v___x_1908_);
v___x_1910_ = lean_box(0);
lean_inc(v___x_1909_);
v___x_1911_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1911_, 0, v___x_1909_);
lean_ctor_set(v___x_1911_, 1, v___x_1910_);
v___y_1884_ = v___y_1901_;
v___y_1885_ = v___x_1911_;
goto v___jp_1883_;
}
else
{
lean_object* v___x_1912_; 
v___x_1912_ = lean_box(0);
v___y_1884_ = v___y_1901_;
v___y_1885_ = v___x_1912_;
goto v___jp_1883_;
}
}
}
}
else
{
lean_object* v___x_1922_; lean_object* v___x_1923_; lean_object* v___x_1924_; lean_object* v___y_1926_; lean_object* v___y_1927_; lean_object* v___y_1943_; lean_object* v___y_1944_; lean_object* v___y_1958_; lean_object* v___y_1961_; uint8_t v___x_1977_; 
v___x_1922_ = lean_unsigned_to_nat(1u);
v___x_1923_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1922_, v___x_1922_);
v___x_1924_ = lean_unsigned_to_nat(0u);
v___x_1977_ = lean_nat_dec_eq(v___x_1923_, v___x_1924_);
lean_dec(v___x_1923_);
if (v___x_1977_ == 0)
{
lean_object* v___x_1978_; lean_object* v___x_1979_; lean_object* v___x_1980_; lean_object* v___x_1981_; lean_object* v___x_1982_; lean_object* v___x_1983_; lean_object* v___x_1984_; 
v___x_1978_ = lean_unsigned_to_nat(10u);
v___x_1979_ = lp_lean1090_Lean1090_Impl_cbRollScoreTable;
v___x_1980_ = lean_unsigned_to_nat(2u);
v___x_1981_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1980_, v___x_1978_);
v___x_1982_ = lean_array_fget_borrowed(v___x_1979_, v___x_1981_);
lean_dec(v___x_1981_);
v___x_1983_ = lean_box(0);
lean_inc(v___x_1982_);
v___x_1984_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1984_, 0, v___x_1982_);
lean_ctor_set(v___x_1984_, 1, v___x_1983_);
v___y_1961_ = v___x_1984_;
goto v___jp_1960_;
}
else
{
lean_object* v___x_1985_; 
v___x_1985_ = lean_box(0);
v___y_1961_ = v___x_1985_;
goto v___jp_1960_;
}
v___jp_1925_:
{
lean_object* v___x_1928_; lean_object* v___x_1929_; lean_object* v___x_1930_; uint8_t v___x_1931_; 
v___x_1928_ = l_List_appendTR___redArg(v___y_1926_, v___y_1927_);
v___x_1929_ = lean_unsigned_to_nat(24u);
v___x_1930_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1929_, v___x_1922_);
v___x_1931_ = lean_nat_dec_eq(v___x_1930_, v___x_1924_);
lean_dec(v___x_1930_);
if (v___x_1931_ == 0)
{
lean_object* v___x_1932_; lean_object* v___x_1933_; lean_object* v___x_1934_; lean_object* v___x_1935_; lean_object* v___x_1936_; lean_object* v___x_1937_; lean_object* v___x_1938_; lean_object* v___x_1939_; 
v___x_1932_ = lean_unsigned_to_nat(10u);
v___x_1933_ = lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable;
v___x_1934_ = lean_unsigned_to_nat(25u);
v___x_1935_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1934_, v___x_1932_);
v___x_1936_ = lean_array_fget_borrowed(v___x_1933_, v___x_1935_);
lean_dec(v___x_1935_);
v___x_1937_ = lean_box(0);
lean_inc(v___x_1936_);
v___x_1938_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1938_, 0, v___x_1936_);
lean_ctor_set(v___x_1938_, 1, v___x_1937_);
v___x_1939_ = l_List_appendTR___redArg(v___x_1928_, v___x_1938_);
return v___x_1939_;
}
else
{
lean_object* v___x_1940_; lean_object* v___x_1941_; 
v___x_1940_ = lean_box(0);
v___x_1941_ = l_List_appendTR___redArg(v___x_1928_, v___x_1940_);
return v___x_1941_;
}
}
v___jp_1942_:
{
lean_object* v___x_1945_; lean_object* v___x_1946_; lean_object* v___x_1947_; uint8_t v___x_1948_; 
v___x_1945_ = l_List_appendTR___redArg(v___y_1943_, v___y_1944_);
v___x_1946_ = lean_unsigned_to_nat(46u);
v___x_1947_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1946_, v___x_1922_);
v___x_1948_ = lean_nat_dec_eq(v___x_1947_, v___x_1924_);
lean_dec(v___x_1947_);
if (v___x_1948_ == 0)
{
lean_object* v___x_1949_; lean_object* v___x_1950_; lean_object* v___x_1951_; lean_object* v___x_1952_; lean_object* v___x_1953_; lean_object* v___x_1954_; lean_object* v___x_1955_; 
v___x_1949_ = lean_unsigned_to_nat(10u);
v___x_1950_ = lp_lean1090_Lean1090_Impl_cbTASScoreTable;
v___x_1951_ = lean_unsigned_to_nat(47u);
v___x_1952_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1951_, v___x_1949_);
v___x_1953_ = lean_array_fget_borrowed(v___x_1950_, v___x_1952_);
lean_dec(v___x_1952_);
v___x_1954_ = lean_box(0);
lean_inc(v___x_1953_);
v___x_1955_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1955_, 0, v___x_1953_);
lean_ctor_set(v___x_1955_, 1, v___x_1954_);
v___y_1926_ = v___x_1945_;
v___y_1927_ = v___x_1955_;
goto v___jp_1925_;
}
else
{
lean_object* v___x_1956_; 
v___x_1956_ = lean_box(0);
v___y_1926_ = v___x_1945_;
v___y_1927_ = v___x_1956_;
goto v___jp_1925_;
}
}
v___jp_1957_:
{
lean_object* v___x_1959_; 
v___x_1959_ = lean_box(0);
v___y_1943_ = v___y_1958_;
v___y_1944_ = v___x_1959_;
goto v___jp_1942_;
}
v___jp_1960_:
{
lean_object* v___x_1962_; lean_object* v___x_1963_; uint8_t v___x_1964_; 
v___x_1962_ = lean_unsigned_to_nat(35u);
v___x_1963_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1962_, v___x_1922_);
v___x_1964_ = lean_nat_dec_eq(v___x_1963_, v___x_1924_);
lean_dec(v___x_1963_);
if (v___x_1964_ == 0)
{
lean_object* v___x_1965_; lean_object* v___x_1966_; lean_object* v___x_1967_; lean_object* v___x_1968_; uint8_t v___x_1969_; 
v___x_1965_ = lean_unsigned_to_nat(37u);
v___x_1966_ = lean_unsigned_to_nat(9u);
v___x_1967_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1965_, v___x_1966_);
v___x_1968_ = lean_unsigned_to_nat(511u);
v___x_1969_ = lean_nat_dec_eq(v___x_1967_, v___x_1968_);
lean_dec(v___x_1967_);
if (v___x_1969_ == 0)
{
lean_object* v___x_1970_; lean_object* v___x_1971_; lean_object* v___x_1972_; lean_object* v___x_1973_; lean_object* v___x_1974_; lean_object* v___x_1975_; lean_object* v___x_1976_; 
v___x_1970_ = lean_unsigned_to_nat(10u);
v___x_1971_ = lp_lean1090_Lean1090_Impl_cbRateScoreTable;
v___x_1972_ = lean_unsigned_to_nat(36u);
v___x_1973_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1972_, v___x_1970_);
v___x_1974_ = lean_array_fget_borrowed(v___x_1971_, v___x_1973_);
lean_dec(v___x_1973_);
v___x_1975_ = lean_box(0);
lean_inc(v___x_1974_);
v___x_1976_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1976_, 0, v___x_1974_);
lean_ctor_set(v___x_1976_, 1, v___x_1975_);
v___y_1943_ = v___y_1961_;
v___y_1944_ = v___x_1976_;
goto v___jp_1942_;
}
else
{
v___y_1958_ = v___y_1961_;
goto v___jp_1957_;
}
}
else
{
v___y_1958_ = v___y_1961_;
goto v___jp_1957_;
}
}
}
}
else
{
lean_object* v___x_1986_; lean_object* v___x_1987_; lean_object* v___x_1988_; lean_object* v___x_1989_; lean_object* v___y_1991_; lean_object* v___y_1992_; lean_object* v___y_2008_; uint8_t v___x_2019_; 
v___x_1986_ = lean_unsigned_to_nat(27u);
v___x_1987_ = lean_unsigned_to_nat(1u);
v___x_1988_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1986_, v___x_1987_);
v___x_1989_ = lean_unsigned_to_nat(0u);
v___x_2019_ = lean_nat_dec_eq(v___x_1988_, v___x_1989_);
lean_dec(v___x_1988_);
if (v___x_2019_ == 0)
{
lean_object* v___x_2020_; lean_object* v___x_2021_; lean_object* v___x_2022_; lean_object* v___x_2023_; lean_object* v___x_2024_; lean_object* v___x_2025_; lean_object* v___x_2026_; 
v___x_2020_ = lean_unsigned_to_nat(12u);
v___x_2021_ = lp_lean1090_Lean1090_Impl_cbQNHScoreTable;
v___x_2022_ = lean_unsigned_to_nat(28u);
v___x_2023_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_2022_, v___x_2020_);
v___x_2024_ = lean_array_fget_borrowed(v___x_2021_, v___x_2023_);
lean_dec(v___x_2023_);
v___x_2025_ = lean_box(0);
lean_inc(v___x_2024_);
v___x_2026_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2026_, 0, v___x_2024_);
lean_ctor_set(v___x_2026_, 1, v___x_2025_);
v___y_2008_ = v___x_2026_;
goto v___jp_2007_;
}
else
{
lean_object* v___x_2027_; 
v___x_2027_ = lean_box(0);
v___y_2008_ = v___x_2027_;
goto v___jp_2007_;
}
v___jp_1990_:
{
lean_object* v___x_1993_; lean_object* v___x_1994_; lean_object* v___x_1995_; uint8_t v___x_1996_; 
v___x_1993_ = l_List_appendTR___redArg(v___y_1991_, v___y_1992_);
v___x_1994_ = lean_unsigned_to_nat(14u);
v___x_1995_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1994_, v___x_1987_);
v___x_1996_ = lean_nat_dec_eq(v___x_1995_, v___x_1989_);
lean_dec(v___x_1995_);
if (v___x_1996_ == 0)
{
lean_object* v___x_1997_; lean_object* v___x_1998_; lean_object* v___x_1999_; lean_object* v___x_2000_; lean_object* v___x_2001_; lean_object* v___x_2002_; lean_object* v___x_2003_; lean_object* v___x_2004_; 
v___x_1997_ = lean_unsigned_to_nat(12u);
v___x_1998_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable;
v___x_1999_ = lean_unsigned_to_nat(15u);
v___x_2000_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1999_, v___x_1997_);
v___x_2001_ = lean_array_fget_borrowed(v___x_1998_, v___x_2000_);
lean_dec(v___x_2000_);
v___x_2002_ = lean_box(0);
lean_inc(v___x_2001_);
v___x_2003_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2003_, 0, v___x_2001_);
lean_ctor_set(v___x_2003_, 1, v___x_2002_);
v___x_2004_ = l_List_appendTR___redArg(v___x_1993_, v___x_2003_);
return v___x_2004_;
}
else
{
lean_object* v___x_2005_; lean_object* v___x_2006_; 
v___x_2005_ = lean_box(0);
v___x_2006_ = l_List_appendTR___redArg(v___x_1993_, v___x_2005_);
return v___x_2006_;
}
}
v___jp_2007_:
{
lean_object* v___x_2009_; uint8_t v___x_2010_; 
v___x_2009_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_1987_, v___x_1987_);
v___x_2010_ = lean_nat_dec_eq(v___x_2009_, v___x_1989_);
lean_dec(v___x_2009_);
if (v___x_2010_ == 0)
{
lean_object* v___x_2011_; lean_object* v___x_2012_; lean_object* v___x_2013_; lean_object* v___x_2014_; lean_object* v___x_2015_; lean_object* v___x_2016_; lean_object* v___x_2017_; 
v___x_2011_ = lean_unsigned_to_nat(12u);
v___x_2012_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable;
v___x_2013_ = lean_unsigned_to_nat(2u);
v___x_2014_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1808_, v___x_2013_, v___x_2011_);
v___x_2015_ = lean_array_fget_borrowed(v___x_2012_, v___x_2014_);
lean_dec(v___x_2014_);
v___x_2016_ = lean_box(0);
lean_inc(v___x_2015_);
v___x_2017_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2017_, 0, v___x_2015_);
lean_ctor_set(v___x_2017_, 1, v___x_2016_);
v___y_1991_ = v___y_2008_;
v___y_1992_ = v___x_2017_;
goto v___jp_1990_;
}
else
{
lean_object* v___x_2018_; 
v___x_2018_ = lean_box(0);
v___y_1991_ = v___y_2008_;
v___y_1992_ = v___x_2018_;
goto v___jp_1990_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTermsFast___boxed(lean_object* v_register_2028_, lean_object* v_word_2029_){
_start:
{
lean_object* v_res_2030_; 
v_res_2030_ = lp_lean1090_Lean1090_Impl_cbDensityTermsFast(v_register_2028_, v_word_2029_);
lean_dec(v_word_2029_);
lean_dec(v_register_2028_);
return v_res_2030_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0(lean_object* v_register_2031_, lean_object* v_word_2032_, lean_object* v_x_2033_){
_start:
{
lean_object* v___x_2034_; lean_object* v___x_2035_; uint8_t v___x_2036_; 
v___x_2034_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__1, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1);
v___x_2035_ = lp_lean1090_Lean1090_Impl_cbCombinedScore(v_register_2031_, v_word_2032_);
v___x_2036_ = l_Rat_instDecidableLe(v___x_2034_, v___x_2035_);
return v___x_2036_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed(lean_object* v_register_2037_, lean_object* v_word_2038_, lean_object* v_x_2039_){
_start:
{
uint8_t v_res_2040_; lean_object* v_r_2041_; 
v_res_2040_ = lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0(v_register_2037_, v_word_2038_, v_x_2039_);
lean_dec(v_word_2038_);
lean_dec(v_register_2037_);
v_r_2041_ = lean_box(v_res_2040_);
return v_r_2041_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses(lean_object* v_register_2042_, lean_object* v_word_2043_){
_start:
{
lean_object* v___f_2044_; lean_object* v___x_2045_; lean_object* v___x_2046_; uint8_t v___x_2047_; 
lean_inc(v_word_2043_);
lean_inc(v_register_2042_);
v___f_2044_ = lean_alloc_closure((void*)(lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed), 3, 2);
lean_closure_set(v___f_2044_, 0, v_register_2042_);
lean_closure_set(v___f_2044_, 1, v_word_2043_);
v___x_2045_ = lp_lean1090_Lean1090_Impl_cbDensityTermsFast(v_register_2042_, v_word_2043_);
v___x_2046_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_2042_, v_word_2043_);
lean_dec(v_word_2043_);
lean_dec(v_register_2042_);
v___x_2047_ = lp_lean1090_Lean1090_Impl_ScoreGate_choose(v___x_2045_, v___x_2046_, v___f_2044_);
return v___x_2047_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScorePasses___boxed(lean_object* v_register_2048_, lean_object* v_word_2049_){
_start:
{
uint8_t v_res_2050_; lean_object* v_r_2051_; 
v_res_2050_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2048_, v_word_2049_);
v_r_2051_ = lean_box(v_res_2050_);
return v_r_2051_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBCoreEligible(lean_object* v_register_2089_, lean_object* v_word_2090_){
_start:
{
uint8_t v___y_2092_; lean_object* v___x_2096_; uint8_t v___x_2097_; 
v___x_2096_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBCoreRegisters));
v___x_2097_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_2089_, v___x_2096_);
if (v___x_2097_ == 0)
{
v___y_2092_ = v___x_2097_;
goto v___jp_2091_;
}
else
{
uint8_t v___x_2098_; 
v___x_2098_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_2089_, v_word_2090_);
v___y_2092_ = v___x_2098_;
goto v___jp_2091_;
}
v___jp_2091_:
{
if (v___y_2092_ == 0)
{
lean_dec(v_word_2090_);
lean_dec(v_register_2089_);
return v___y_2092_;
}
else
{
lean_object* v___x_2093_; uint8_t v___x_2094_; 
v___x_2093_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__4));
v___x_2094_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_2089_, v___x_2093_);
if (v___x_2094_ == 0)
{
lean_dec(v_word_2090_);
lean_dec(v_register_2089_);
return v___y_2092_;
}
else
{
uint8_t v___x_2095_; 
v___x_2095_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2089_, v_word_2090_);
return v___x_2095_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBCoreEligible___boxed(lean_object* v_register_2099_, lean_object* v_word_2100_){
_start:
{
uint8_t v_res_2101_; lean_object* v_r_2102_; 
v_res_2101_ = lp_lean1090_Lean1090_Impl_commBCoreEligible(v_register_2099_, v_word_2100_);
v_r_2102_ = lean_box(v_res_2101_);
return v_r_2102_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBPositionEligible(lean_object* v_df_2103_, lean_object* v_outerAltitude_2104_, lean_object* v_word_2105_){
_start:
{
lean_object* v___x_2106_; uint8_t v___x_2107_; 
v___x_2106_ = lean_unsigned_to_nat(20u);
v___x_2107_ = lean_nat_dec_eq(v_df_2103_, v___x_2106_);
if (v___x_2107_ == 0)
{
lean_dec(v_outerAltitude_2104_);
return v___x_2107_;
}
else
{
lean_object* v___x_2108_; lean_object* v___x_2109_; lean_object* v_tc_2110_; lean_object* v___x_2111_; uint8_t v___x_2112_; 
v___x_2108_ = lean_unsigned_to_nat(1u);
v___x_2109_ = lean_unsigned_to_nat(5u);
v_tc_2110_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2105_, v___x_2108_, v___x_2109_);
v___x_2111_ = lean_unsigned_to_nat(9u);
v___x_2112_ = lean_nat_dec_le(v___x_2111_, v_tc_2110_);
if (v___x_2112_ == 0)
{
lean_dec(v_tc_2110_);
lean_dec(v_outerAltitude_2104_);
return v___x_2112_;
}
else
{
lean_object* v___x_2113_; uint8_t v___x_2114_; 
v___x_2113_ = lean_unsigned_to_nat(22u);
v___x_2114_ = lean_nat_dec_lt(v_tc_2110_, v___x_2113_);
if (v___x_2114_ == 0)
{
lean_dec(v_tc_2110_);
lean_dec(v_outerAltitude_2104_);
return v___x_2114_;
}
else
{
lean_object* v___x_2115_; uint8_t v___x_2116_; 
v___x_2115_ = lean_unsigned_to_nat(19u);
v___x_2116_ = lean_nat_dec_eq(v_tc_2110_, v___x_2115_);
lean_dec(v_tc_2110_);
if (v___x_2116_ == 0)
{
uint8_t v___x_2117_; 
v___x_2117_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v___x_2109_, v_word_2105_);
if (v___x_2117_ == 0)
{
lean_dec(v_outerAltitude_2104_);
return v___x_2117_;
}
else
{
lean_object* v___x_2118_; lean_object* v___x_2119_; uint8_t v___x_2120_; 
v___x_2118_ = lean_alloc_closure((void*)(l_Int_instDecidableEq___boxed), 2, 0);
v___x_2119_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_word_2105_);
v___x_2120_ = l_Option_instDecidableEq___redArg(v___x_2118_, v___x_2119_, v_outerAltitude_2104_);
return v___x_2120_;
}
}
else
{
uint8_t v___x_2121_; 
lean_dec(v_outerAltitude_2104_);
v___x_2121_ = 0;
return v___x_2121_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBPositionEligible___boxed(lean_object* v_df_2122_, lean_object* v_outerAltitude_2123_, lean_object* v_word_2124_){
_start:
{
uint8_t v_res_2125_; lean_object* v_r_2126_; 
v_res_2125_ = lp_lean1090_Lean1090_Impl_commBPositionEligible(v_df_2122_, v_outerAltitude_2123_, v_word_2124_);
lean_dec(v_word_2124_);
lean_dec(v_df_2122_);
v_r_2126_ = lean_box(v_res_2125_);
return v_r_2126_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg(){
_start:
{
uint8_t v___x_2128_; 
v___x_2128_ = 0;
return v___x_2128_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg___boxed(lean_object* v___dummy_2129_){
_start:
{
uint8_t v_res_2130_; lean_object* v_r_2131_; 
v_res_2130_ = lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg();
v_r_2131_ = lean_box(v_res_2130_);
return v_r_2131_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBOperationEligible(lean_object* v___word_2132_){
_start:
{
uint8_t v___x_2133_; 
v___x_2133_ = 0;
return v___x_2133_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBOperationEligible___boxed(lean_object* v___word_2134_){
_start:
{
uint8_t v_res_2135_; lean_object* v_r_2136_; 
v_res_2135_ = lp_lean1090_Lean1090_Impl_commBOperationEligible(v___word_2134_);
lean_dec(v___word_2134_);
v_r_2136_ = lean_box(v_res_2135_);
return v_r_2136_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBEligible(lean_object* v_df_2137_, lean_object* v_outerAltitude_2138_, lean_object* v_register_2139_, lean_object* v_word_2140_){
_start:
{
lean_object* v___x_2151_; uint8_t v___x_2152_; 
v___x_2151_ = lean_unsigned_to_nat(20u);
v___x_2152_ = lean_nat_dec_eq(v_df_2137_, v___x_2151_);
if (v___x_2152_ == 0)
{
lean_object* v___x_2153_; uint8_t v___x_2154_; 
v___x_2153_ = lean_unsigned_to_nat(21u);
v___x_2154_ = lean_nat_dec_eq(v_df_2137_, v___x_2153_);
if (v___x_2154_ == 0)
{
lean_dec(v_word_2140_);
lean_dec(v_register_2139_);
lean_dec(v_outerAltitude_2138_);
return v___x_2154_;
}
else
{
goto v___jp_2141_;
}
}
else
{
goto v___jp_2141_;
}
v___jp_2141_:
{
lean_object* v___x_2142_; uint8_t v___x_2143_; 
v___x_2142_ = lean_unsigned_to_nat(0u);
v___x_2143_ = lean_nat_dec_eq(v_word_2140_, v___x_2142_);
if (v___x_2143_ == 0)
{
lean_object* v___x_2144_; uint8_t v___x_2145_; 
v___x_2144_ = lean_unsigned_to_nat(5u);
v___x_2145_ = lean_nat_dec_eq(v_register_2139_, v___x_2144_);
if (v___x_2145_ == 0)
{
lean_object* v___x_2146_; uint8_t v___x_2147_; 
lean_dec(v_outerAltitude_2138_);
v___x_2146_ = lean_unsigned_to_nat(101u);
v___x_2147_ = lean_nat_dec_eq(v_register_2139_, v___x_2146_);
if (v___x_2147_ == 0)
{
uint8_t v___x_2148_; 
v___x_2148_ = lp_lean1090_Lean1090_Impl_commBCoreEligible(v_register_2139_, v_word_2140_);
return v___x_2148_;
}
else
{
lean_dec(v_word_2140_);
lean_dec(v_register_2139_);
return v___x_2145_;
}
}
else
{
uint8_t v___x_2149_; 
lean_dec(v_register_2139_);
v___x_2149_ = lp_lean1090_Lean1090_Impl_commBPositionEligible(v_df_2137_, v_outerAltitude_2138_, v_word_2140_);
lean_dec(v_word_2140_);
return v___x_2149_;
}
}
else
{
uint8_t v___x_2150_; 
lean_dec(v_word_2140_);
lean_dec(v_register_2139_);
lean_dec(v_outerAltitude_2138_);
v___x_2150_ = 0;
return v___x_2150_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBEligible___boxed(lean_object* v_df_2155_, lean_object* v_outerAltitude_2156_, lean_object* v_register_2157_, lean_object* v_word_2158_){
_start:
{
uint8_t v_res_2159_; lean_object* v_r_2160_; 
v_res_2159_ = lp_lean1090_Lean1090_Impl_commBEligible(v_df_2155_, v_outerAltitude_2156_, v_register_2157_, v_word_2158_);
lean_dec(v_df_2155_);
v_r_2160_ = lean_box(v_res_2159_);
return v_r_2160_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBRegisters___closed__2(void){
_start:
{
lean_object* v___x_2167_; lean_object* v___x_2168_; lean_object* v___x_2169_; 
v___x_2167_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBRegisters___closed__1));
v___x_2168_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBRegisters___closed__0));
v___x_2169_ = l_List_appendTR___redArg(v___x_2168_, v___x_2167_);
return v___x_2169_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBRegisters(void){
_start:
{
lean_object* v___x_2170_; 
v___x_2170_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_commBRegisters___closed__2, &lp_lean1090_Lean1090_Impl_commBRegisters___closed__2_once, _init_lp_lean1090_Lean1090_Impl_commBRegisters___closed__2);
return v___x_2170_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(lean_object* v_df_2171_, lean_object* v_outerAltitude_2172_, lean_object* v_word_2173_, lean_object* v_a_2174_, lean_object* v_a_2175_){
_start:
{
if (lean_obj_tag(v_a_2174_) == 0)
{
lean_object* v___x_2176_; 
lean_dec(v_word_2173_);
lean_dec(v_outerAltitude_2172_);
v___x_2176_ = lean_array_to_list(v_a_2175_);
return v___x_2176_;
}
else
{
lean_object* v_head_2177_; lean_object* v_tail_2178_; lean_object* v___x_2180_; uint8_t v_isShared_2181_; uint8_t v_isSharedCheck_2192_; 
v_head_2177_ = lean_ctor_get(v_a_2174_, 0);
v_tail_2178_ = lean_ctor_get(v_a_2174_, 1);
v_isSharedCheck_2192_ = !lean_is_exclusive(v_a_2174_);
if (v_isSharedCheck_2192_ == 0)
{
v___x_2180_ = v_a_2174_;
v_isShared_2181_ = v_isSharedCheck_2192_;
goto v_resetjp_2179_;
}
else
{
lean_inc(v_tail_2178_);
lean_inc(v_head_2177_);
lean_dec(v_a_2174_);
v___x_2180_ = lean_box(0);
v_isShared_2181_ = v_isSharedCheck_2192_;
goto v_resetjp_2179_;
}
v_resetjp_2179_:
{
uint8_t v___x_2182_; 
lean_inc(v_word_2173_);
lean_inc(v_head_2177_);
lean_inc(v_outerAltitude_2172_);
v___x_2182_ = lp_lean1090_Lean1090_Impl_commBEligible(v_df_2171_, v_outerAltitude_2172_, v_head_2177_, v_word_2173_);
if (v___x_2182_ == 0)
{
lean_del_object(v___x_2180_);
lean_dec(v_head_2177_);
v_a_2174_ = v_tail_2178_;
goto _start;
}
else
{
lean_object* v___x_2184_; 
lean_inc(v_head_2177_);
v___x_2184_ = lp_lean1090_Lean1090_Impl_decodeBDS(v_head_2177_, v_word_2173_);
if (lean_obj_tag(v___x_2184_) == 0)
{
lean_del_object(v___x_2180_);
lean_dec(v_head_2177_);
v_a_2174_ = v_tail_2178_;
goto _start;
}
else
{
lean_object* v_val_2186_; lean_object* v___x_2188_; 
v_val_2186_ = lean_ctor_get(v___x_2184_, 0);
lean_inc(v_val_2186_);
lean_dec_ref_known(v___x_2184_, 1);
if (v_isShared_2181_ == 0)
{
lean_ctor_set_tag(v___x_2180_, 0);
lean_ctor_set(v___x_2180_, 1, v_val_2186_);
v___x_2188_ = v___x_2180_;
goto v_reusejp_2187_;
}
else
{
lean_object* v_reuseFailAlloc_2191_; 
v_reuseFailAlloc_2191_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2191_, 0, v_head_2177_);
lean_ctor_set(v_reuseFailAlloc_2191_, 1, v_val_2186_);
v___x_2188_ = v_reuseFailAlloc_2191_;
goto v_reusejp_2187_;
}
v_reusejp_2187_:
{
lean_object* v___x_2189_; 
v___x_2189_ = lean_array_push(v_a_2175_, v___x_2188_);
v_a_2174_ = v_tail_2178_;
v_a_2175_ = v___x_2189_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0___boxed(lean_object* v_df_2193_, lean_object* v_outerAltitude_2194_, lean_object* v_word_2195_, lean_object* v_a_2196_, lean_object* v_a_2197_){
_start:
{
lean_object* v_res_2198_; 
v_res_2198_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(v_df_2193_, v_outerAltitude_2194_, v_word_2195_, v_a_2196_, v_a_2197_);
lean_dec(v_df_2193_);
return v_res_2198_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_inferCommB(lean_object* v_df_2201_, lean_object* v_outerAltitude_2202_, lean_object* v_word_2203_){
_start:
{
lean_object* v___x_2204_; lean_object* v___x_2205_; lean_object* v___x_2206_; 
v___x_2204_ = lp_lean1090_Lean1090_Impl_commBRegisters;
v___x_2205_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_inferCommB___closed__0));
v___x_2206_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(v_df_2201_, v_outerAltitude_2202_, v_word_2203_, v___x_2204_, v___x_2205_);
return v___x_2206_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_inferCommB___boxed(lean_object* v_df_2207_, lean_object* v_outerAltitude_2208_, lean_object* v_word_2209_){
_start:
{
lean_object* v_res_2210_; 
v_res_2210_ = lp_lean1090_Lean1090_Impl_inferCommB(v_df_2207_, v_outerAltitude_2208_, v_word_2209_);
lean_dec(v_df_2207_);
return v_res_2210_;
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
lp_lean1090_Lean1090_Impl_cbQNHValueTable = _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbQNHValueTable);
lp_lean1090_Lean1090_Impl_cbMachValueTable = _init_lp_lean1090_Lean1090_Impl_cbMachValueTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbMachValueTable);
lp_lean1090_Lean1090_Impl_cbWindPenaltyTable = _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbWindPenaltyTable);
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
