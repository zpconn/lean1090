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
size_t lean_array_size(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uget(lean_object*, size_t);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
uint8_t l_Rat_instDecidableLe(lean_object*, lean_object*);
size_t lean_usize_add(size_t, size_t);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
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
lean_object* lean_nat_to_int(lean_object*);
lean_object* lean_nat_abs(lean_object*);
lean_object* lean_int_add(lean_object*, lean_object*);
lean_object* lean_int_mul(lean_object*, lean_object*);
uint8_t lean_int_dec_lt(lean_object*, lean_object*);
lean_object* lean_int_sub(lean_object*, lean_object*);
uint8_t lean_int_dec_le(lean_object*, lean_object*);
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
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___closed__0;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___boxed(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedValid40Table;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbSelectedValid40(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedValid40___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___closed__0;
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static size_t lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHValid40Table;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbQNHValid40(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHValid40___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid40(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid40___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbValid44___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbValid44___closed__0;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid44(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid44___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid45(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid45___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___boxed(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollValid50Table;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbRollValid50(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollValid50___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid50(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid50___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbMachValid60Table_spec__0(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbMachValid60Table_spec__0___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static size_t lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachValid60Table;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbMachValid60(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachValid60___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___closed__0;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___boxed(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalValid60Table;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbVerticalValid60(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalValid60___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid60(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid60___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBPayloadLimit;
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
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__4;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__5;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbRatioOutside250800(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRatioOutside250800___boxed(lean_object*);
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
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___closed__0(void){
_start:
{
lean_object* v___x_844_; lean_object* v___x_845_; 
v___x_844_ = lean_unsigned_to_nat(50000u);
v___x_845_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_844_);
return v___x_845_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0(lean_object* v_code_846_){
_start:
{
lean_object* v___x_847_; lean_object* v___x_848_; uint8_t v___x_849_; 
v___x_847_ = lp_lean1090_Lean1090_Impl_cbSelected(v_code_846_);
v___x_848_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___closed__0);
v___x_849_ = l_Rat_instDecidableLe(v___x_847_, v___x_848_);
return v___x_849_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___boxed(lean_object* v_code_850_){
_start:
{
uint8_t v_res_851_; lean_object* v_r_852_; 
v_res_851_ = lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0(v_code_850_);
lean_dec(v_code_850_);
v_r_852_ = lean_box(v_res_851_);
return v_r_852_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__1(void){
_start:
{
lean_object* v___f_854_; lean_object* v___x_855_; lean_object* v___x_856_; 
v___f_854_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__0));
v___x_855_ = lean_unsigned_to_nat(4096u);
v___x_856_ = l_Array_ofFn___redArg(v___x_855_, v___f_854_);
return v___x_856_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedValid40Table(void){
_start:
{
lean_object* v___x_857_; 
v___x_857_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__1, &lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__1);
return v___x_857_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbSelectedValid40(lean_object* v_word_858_, lean_object* v_start_859_){
_start:
{
lean_object* v___x_860_; lean_object* v___x_861_; lean_object* v___x_862_; lean_object* v___x_863_; uint8_t v___x_864_; 
v___x_860_ = lp_lean1090_Lean1090_Impl_cbSelectedValid40Table;
v___x_861_ = lean_unsigned_to_nat(12u);
v___x_862_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_858_, v_start_859_, v___x_861_);
v___x_863_ = lean_array_fget_borrowed(v___x_860_, v___x_862_);
lean_dec(v___x_862_);
v___x_864_ = lean_unbox(v___x_863_);
return v___x_864_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedValid40___boxed(lean_object* v_word_865_, lean_object* v_start_866_){
_start:
{
uint8_t v_res_867_; lean_object* v_r_868_; 
v_res_867_ = lp_lean1090_Lean1090_Impl_cbSelectedValid40(v_word_865_, v_start_866_);
lean_dec(v_start_866_);
lean_dec(v_word_865_);
v_r_868_ = lean_box(v_res_867_);
return v_r_868_;
}
}
static lean_object* _init_lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___closed__0(void){
_start:
{
lean_object* v___x_869_; lean_object* v___x_870_; 
v___x_869_ = lean_unsigned_to_nat(1200u);
v___x_870_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_869_);
return v___x_870_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0(size_t v_sz_871_, size_t v_i_872_, lean_object* v_bs_873_){
_start:
{
uint8_t v___x_874_; 
v___x_874_ = lean_usize_dec_lt(v_i_872_, v_sz_871_);
if (v___x_874_ == 0)
{
return v_bs_873_;
}
else
{
lean_object* v_v_875_; lean_object* v___x_876_; lean_object* v_bs_x27_877_; uint8_t v___y_879_; lean_object* v___x_885_; uint8_t v___x_886_; 
v_v_875_ = lean_array_uget(v_bs_873_, v_i_872_);
v___x_876_ = lean_unsigned_to_nat(0u);
v_bs_x27_877_ = lean_array_uset(v_bs_873_, v_i_872_, v___x_876_);
v___x_885_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4);
lean_inc(v_v_875_);
v___x_886_ = l_Rat_instDecidableLe(v___x_885_, v_v_875_);
if (v___x_886_ == 0)
{
lean_dec(v_v_875_);
v___y_879_ = v___x_886_;
goto v___jp_878_;
}
else
{
lean_object* v___x_887_; uint8_t v___x_888_; 
v___x_887_ = lean_obj_once(&lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___closed__0, &lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___closed__0_once, _init_lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___closed__0);
v___x_888_ = l_Rat_instDecidableLe(v_v_875_, v___x_887_);
v___y_879_ = v___x_888_;
goto v___jp_878_;
}
v___jp_878_:
{
size_t v___x_880_; size_t v___x_881_; lean_object* v___x_882_; lean_object* v___x_883_; 
v___x_880_ = ((size_t)1ULL);
v___x_881_ = lean_usize_add(v_i_872_, v___x_880_);
v___x_882_ = lean_box(v___y_879_);
v___x_883_ = lean_array_uset(v_bs_x27_877_, v_i_872_, v___x_882_);
v_i_872_ = v___x_881_;
v_bs_873_ = v___x_883_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___boxed(lean_object* v_sz_889_, lean_object* v_i_890_, lean_object* v_bs_891_){
_start:
{
size_t v_sz_boxed_892_; size_t v_i_boxed_893_; lean_object* v_res_894_; 
v_sz_boxed_892_ = lean_unbox_usize(v_sz_889_);
lean_dec(v_sz_889_);
v_i_boxed_893_ = lean_unbox_usize(v_i_890_);
lean_dec(v_i_890_);
v_res_894_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0(v_sz_boxed_892_, v_i_boxed_893_, v_bs_891_);
return v_res_894_;
}
}
static size_t _init_lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__0(void){
_start:
{
lean_object* v___x_895_; size_t v_sz_896_; 
v___x_895_ = lp_lean1090_Lean1090_Impl_cbQNHValueTable;
v_sz_896_ = lean_array_size(v___x_895_);
return v_sz_896_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__1(void){
_start:
{
lean_object* v___x_897_; size_t v___x_898_; size_t v_sz_899_; lean_object* v___x_900_; 
v___x_897_ = lp_lean1090_Lean1090_Impl_cbQNHValueTable;
v___x_898_ = ((size_t)0ULL);
v_sz_899_ = lean_usize_once(&lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__0);
v___x_900_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0(v_sz_899_, v___x_898_, v___x_897_);
return v___x_900_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHValid40Table(void){
_start:
{
lean_object* v___x_901_; 
v___x_901_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__1);
return v___x_901_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbQNHValid40(lean_object* v_word_902_){
_start:
{
lean_object* v___x_903_; lean_object* v___x_904_; lean_object* v___x_905_; lean_object* v___x_906_; lean_object* v___x_907_; uint8_t v___x_908_; 
v___x_903_ = lp_lean1090_Lean1090_Impl_cbQNHValid40Table;
v___x_904_ = lean_unsigned_to_nat(28u);
v___x_905_ = lean_unsigned_to_nat(12u);
v___x_906_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_902_, v___x_904_, v___x_905_);
v___x_907_ = lean_array_fget_borrowed(v___x_903_, v___x_906_);
lean_dec(v___x_906_);
v___x_908_ = lean_unbox(v___x_907_);
return v___x_908_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHValid40___boxed(lean_object* v_word_909_){
_start:
{
uint8_t v_res_910_; lean_object* v_r_911_; 
v_res_910_ = lp_lean1090_Lean1090_Impl_cbQNHValid40(v_word_909_);
lean_dec(v_word_909_);
v_r_911_ = lean_box(v_res_910_);
return v_r_911_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid40(lean_object* v_word_912_){
_start:
{
uint8_t v___y_914_; lean_object* v___x_932_; lean_object* v___x_933_; lean_object* v___x_934_; uint8_t v___x_935_; 
v___x_932_ = lean_unsigned_to_nat(1u);
v___x_933_ = lean_unsigned_to_nat(2u);
v___x_934_ = lean_unsigned_to_nat(12u);
v___x_935_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_912_, v___x_932_, v___x_933_, v___x_934_);
if (v___x_935_ == 0)
{
v___y_914_ = v___x_935_;
goto v___jp_913_;
}
else
{
lean_object* v___x_936_; lean_object* v___x_937_; uint8_t v___x_938_; 
v___x_936_ = lean_unsigned_to_nat(14u);
v___x_937_ = lean_unsigned_to_nat(15u);
v___x_938_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_912_, v___x_936_, v___x_937_, v___x_934_);
v___y_914_ = v___x_938_;
goto v___jp_913_;
}
v___jp_913_:
{
if (v___y_914_ == 0)
{
return v___y_914_;
}
else
{
lean_object* v___x_915_; lean_object* v___x_916_; lean_object* v___x_917_; uint8_t v___x_918_; 
v___x_915_ = lean_unsigned_to_nat(27u);
v___x_916_ = lean_unsigned_to_nat(28u);
v___x_917_ = lean_unsigned_to_nat(12u);
v___x_918_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_912_, v___x_915_, v___x_916_, v___x_917_);
if (v___x_918_ == 0)
{
return v___x_918_;
}
else
{
lean_object* v___x_919_; lean_object* v___x_920_; lean_object* v___x_921_; lean_object* v___x_922_; uint8_t v___x_923_; 
v___x_919_ = lean_unsigned_to_nat(40u);
v___x_920_ = lean_unsigned_to_nat(8u);
v___x_921_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_912_, v___x_919_, v___x_920_);
v___x_922_ = lean_unsigned_to_nat(0u);
v___x_923_ = lean_nat_dec_eq(v___x_921_, v___x_922_);
lean_dec(v___x_921_);
if (v___x_923_ == 0)
{
return v___x_923_;
}
else
{
lean_object* v___x_924_; lean_object* v___x_925_; lean_object* v___x_926_; uint8_t v___x_927_; 
v___x_924_ = lean_unsigned_to_nat(52u);
v___x_925_ = lean_unsigned_to_nat(2u);
v___x_926_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_912_, v___x_924_, v___x_925_);
v___x_927_ = lean_nat_dec_eq(v___x_926_, v___x_922_);
lean_dec(v___x_926_);
if (v___x_927_ == 0)
{
return v___x_927_;
}
else
{
uint8_t v___x_928_; 
v___x_928_ = lp_lean1090_Lean1090_Impl_cbSelectedValid40(v_word_912_, v___x_925_);
if (v___x_928_ == 0)
{
return v___x_928_;
}
else
{
lean_object* v___x_929_; uint8_t v___x_930_; 
v___x_929_ = lean_unsigned_to_nat(15u);
v___x_930_ = lp_lean1090_Lean1090_Impl_cbSelectedValid40(v_word_912_, v___x_929_);
if (v___x_930_ == 0)
{
return v___x_930_;
}
else
{
uint8_t v___x_931_; 
v___x_931_ = lp_lean1090_Lean1090_Impl_cbQNHValid40(v_word_912_);
return v___x_931_;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid40___boxed(lean_object* v_word_939_){
_start:
{
uint8_t v_res_940_; lean_object* v_r_941_; 
v_res_940_ = lp_lean1090_Lean1090_Impl_cbValid40(v_word_939_);
lean_dec(v_word_939_);
v_r_941_ = lean_box(v_res_940_);
return v_r_941_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0(void){
_start:
{
lean_object* v___x_942_; lean_object* v___x_943_; 
v___x_942_ = lean_unsigned_to_nat(60u);
v___x_943_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_942_);
return v___x_943_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid44(lean_object* v_word_944_){
_start:
{
lean_object* v___x_968_; lean_object* v___x_969_; lean_object* v___x_970_; uint8_t v___x_971_; 
v___x_968_ = lean_unsigned_to_nat(1u);
v___x_969_ = lean_unsigned_to_nat(4u);
v___x_970_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_944_, v___x_968_, v___x_969_);
v___x_971_ = lean_nat_dec_eq(v___x_970_, v___x_968_);
if (v___x_971_ == 0)
{
lean_object* v___x_972_; uint8_t v___x_973_; 
v___x_972_ = lean_unsigned_to_nat(2u);
v___x_973_ = lean_nat_dec_eq(v___x_970_, v___x_972_);
lean_dec(v___x_970_);
if (v___x_973_ == 0)
{
return v___x_973_;
}
else
{
goto v___jp_945_;
}
}
else
{
lean_dec(v___x_970_);
goto v___jp_945_;
}
v___jp_945_:
{
lean_object* v___x_946_; lean_object* v___x_947_; lean_object* v___x_948_; uint8_t v___x_949_; 
v___x_946_ = lean_unsigned_to_nat(5u);
v___x_947_ = lean_unsigned_to_nat(6u);
v___x_948_ = lean_unsigned_to_nat(18u);
v___x_949_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_944_, v___x_946_, v___x_947_, v___x_948_);
if (v___x_949_ == 0)
{
return v___x_949_;
}
else
{
lean_object* v___x_950_; lean_object* v___x_951_; lean_object* v___x_952_; uint8_t v___x_953_; 
v___x_950_ = lean_unsigned_to_nat(9u);
v___x_951_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_944_, v___x_947_, v___x_950_);
v___x_952_ = lean_unsigned_to_nat(250u);
v___x_953_ = lean_nat_dec_le(v___x_951_, v___x_952_);
lean_dec(v___x_951_);
if (v___x_953_ == 0)
{
return v___x_953_;
}
else
{
lean_object* v___x_954_; lean_object* v___x_955_; uint8_t v___x_956_; 
v___x_954_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
v___x_955_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_944_);
lean_inc_ref(v___x_955_);
v___x_956_ = l_Rat_instDecidableLe(v___x_954_, v___x_955_);
if (v___x_956_ == 0)
{
lean_dec_ref(v___x_955_);
return v___x_956_;
}
else
{
lean_object* v___x_957_; uint8_t v___x_958_; 
v___x_957_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid44___closed__0, &lp_lean1090_Lean1090_Impl_cbValid44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0);
v___x_958_ = l_Rat_instDecidableLe(v___x_955_, v___x_957_);
if (v___x_958_ == 0)
{
return v___x_958_;
}
else
{
lean_object* v___x_959_; lean_object* v___x_960_; lean_object* v___x_961_; uint8_t v___x_962_; 
v___x_959_ = lean_unsigned_to_nat(35u);
v___x_960_ = lean_unsigned_to_nat(36u);
v___x_961_ = lean_unsigned_to_nat(11u);
v___x_962_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_944_, v___x_959_, v___x_960_, v___x_961_);
if (v___x_962_ == 0)
{
return v___x_962_;
}
else
{
lean_object* v___x_963_; lean_object* v___x_964_; lean_object* v___x_965_; lean_object* v___x_966_; uint8_t v___x_967_; 
v___x_963_ = lean_unsigned_to_nat(47u);
v___x_964_ = lean_unsigned_to_nat(10u);
v___x_965_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_944_, v___x_963_, v___x_964_);
v___x_966_ = lean_unsigned_to_nat(0u);
v___x_967_ = lean_nat_dec_eq(v___x_965_, v___x_966_);
lean_dec(v___x_965_);
return v___x_967_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid44___boxed(lean_object* v_word_974_){
_start:
{
uint8_t v_res_975_; lean_object* v_r_976_; 
v_res_975_ = lp_lean1090_Lean1090_Impl_cbValid44(v_word_974_);
lean_dec(v_word_974_);
v_r_976_ = lean_box(v_res_975_);
return v_r_976_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid45(lean_object* v_word_977_){
_start:
{
uint8_t v___y_979_; lean_object* v___x_988_; lean_object* v___x_989_; lean_object* v___x_990_; lean_object* v___x_991_; uint8_t v___x_992_; 
v___x_988_ = lean_unsigned_to_nat(1u);
v___x_989_ = lean_unsigned_to_nat(15u);
v___x_990_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_977_, v___x_988_, v___x_989_);
v___x_991_ = lean_unsigned_to_nat(0u);
v___x_992_ = lean_nat_dec_eq(v___x_990_, v___x_991_);
lean_dec(v___x_990_);
if (v___x_992_ == 0)
{
return v___x_992_;
}
else
{
lean_object* v___x_993_; lean_object* v___x_994_; lean_object* v___x_995_; uint8_t v___x_996_; 
v___x_993_ = lean_unsigned_to_nat(52u);
v___x_994_ = lean_unsigned_to_nat(5u);
v___x_995_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_977_, v___x_993_, v___x_994_);
v___x_996_ = lean_nat_dec_eq(v___x_995_, v___x_991_);
lean_dec(v___x_995_);
if (v___x_996_ == 0)
{
return v___x_996_;
}
else
{
lean_object* v___x_997_; lean_object* v___x_998_; uint8_t v___x_999_; 
v___x_997_ = lean_unsigned_to_nat(16u);
v___x_998_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_977_, v___x_997_, v___x_988_);
v___x_999_ = lean_nat_dec_eq(v___x_998_, v___x_991_);
lean_dec(v___x_998_);
if (v___x_999_ == 0)
{
lean_object* v___x_1000_; lean_object* v___x_1001_; lean_object* v___x_1002_; lean_object* v___x_1003_; lean_object* v___x_1004_; lean_object* v___x_1005_; uint8_t v___x_1006_; 
v___x_1000_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
v___x_1001_ = lean_unsigned_to_nat(17u);
v___x_1002_ = lean_unsigned_to_nat(10u);
v___x_1003_ = lp_lean1090_Lean1090_Impl_cbSigned(v_word_977_, v___x_1001_, v___x_1002_);
v___x_1004_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v___x_1005_ = l_Rat_div(v___x_1003_, v___x_1004_);
lean_dec_ref(v___x_1003_);
lean_inc_ref(v___x_1005_);
v___x_1006_ = l_Rat_instDecidableLe(v___x_1000_, v___x_1005_);
if (v___x_1006_ == 0)
{
lean_dec_ref(v___x_1005_);
return v___x_1006_;
}
else
{
lean_object* v___x_1007_; uint8_t v___x_1008_; 
v___x_1007_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid44___closed__0, &lp_lean1090_Lean1090_Impl_cbValid44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0);
v___x_1008_ = l_Rat_instDecidableLe(v___x_1005_, v___x_1007_);
v___y_979_ = v___x_1008_;
goto v___jp_978_;
}
}
else
{
lean_object* v___x_1009_; lean_object* v___x_1010_; lean_object* v___x_1011_; uint8_t v___x_1012_; 
v___x_1009_ = lean_unsigned_to_nat(18u);
v___x_1010_ = lean_unsigned_to_nat(9u);
v___x_1011_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_977_, v___x_1009_, v___x_1010_);
v___x_1012_ = lean_nat_dec_eq(v___x_1011_, v___x_991_);
lean_dec(v___x_1011_);
v___y_979_ = v___x_1012_;
goto v___jp_978_;
}
}
}
v___jp_978_:
{
if (v___y_979_ == 0)
{
return v___y_979_;
}
else
{
lean_object* v___x_980_; lean_object* v___x_981_; lean_object* v___x_982_; uint8_t v___x_983_; 
v___x_980_ = lean_unsigned_to_nat(27u);
v___x_981_ = lean_unsigned_to_nat(28u);
v___x_982_ = lean_unsigned_to_nat(11u);
v___x_983_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_977_, v___x_980_, v___x_981_, v___x_982_);
if (v___x_983_ == 0)
{
return v___x_983_;
}
else
{
lean_object* v___x_984_; lean_object* v___x_985_; lean_object* v___x_986_; uint8_t v___x_987_; 
v___x_984_ = lean_unsigned_to_nat(39u);
v___x_985_ = lean_unsigned_to_nat(40u);
v___x_986_ = lean_unsigned_to_nat(12u);
v___x_987_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_977_, v___x_984_, v___x_985_, v___x_986_);
return v___x_987_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid45___boxed(lean_object* v_word_1013_){
_start:
{
uint8_t v_res_1014_; lean_object* v_r_1015_; 
v_res_1014_ = lp_lean1090_Lean1090_Impl_cbValid45(v_word_1013_);
lean_dec(v_word_1013_);
v_r_1015_ = lean_box(v_res_1014_);
return v_r_1015_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1016_; lean_object* v___x_1017_; 
v___x_1016_ = lean_unsigned_to_nat(45u);
v___x_1017_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1016_);
return v___x_1017_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0(lean_object* v_code_1018_){
_start:
{
uint8_t v___x_1019_; lean_object* v___x_1020_; lean_object* v___x_1021_; lean_object* v___x_1022_; lean_object* v___x_1023_; lean_object* v___x_1024_; lean_object* v___x_1025_; lean_object* v___x_1026_; lean_object* v___x_1027_; uint8_t v___x_1028_; 
v___x_1019_ = 1;
v___x_1020_ = lean_unsigned_to_nat(10u);
v___x_1021_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1019_, v___x_1020_, v_code_1018_);
v___x_1022_ = l_Rat_ofInt(v___x_1021_);
v___x_1023_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0);
v___x_1024_ = l_Rat_mul(v___x_1022_, v___x_1023_);
lean_dec_ref(v___x_1022_);
v___x_1025_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1026_ = l_Rat_div(v___x_1024_, v___x_1025_);
lean_dec_ref(v___x_1024_);
v___x_1027_ = l_Rat_abs(v___x_1026_);
v___x_1028_ = l_Rat_instDecidableLe(v___x_1027_, v___x_1023_);
return v___x_1028_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___boxed(lean_object* v_code_1029_){
_start:
{
uint8_t v_res_1030_; lean_object* v_r_1031_; 
v_res_1030_ = lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0(v_code_1029_);
v_r_1031_ = lean_box(v_res_1030_);
return v_r_1031_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__1(void){
_start:
{
lean_object* v___f_1033_; lean_object* v___x_1034_; lean_object* v___x_1035_; 
v___f_1033_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__0));
v___x_1034_ = lean_unsigned_to_nat(1024u);
v___x_1035_ = l_Array_ofFn___redArg(v___x_1034_, v___f_1033_);
return v___x_1035_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table(void){
_start:
{
lean_object* v___x_1036_; 
v___x_1036_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__1, &lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__1);
return v___x_1036_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbRollValid50(lean_object* v_word_1037_){
_start:
{
lean_object* v___x_1038_; lean_object* v___x_1039_; lean_object* v___x_1040_; lean_object* v___x_1041_; lean_object* v___x_1042_; uint8_t v___x_1043_; 
v___x_1038_ = lp_lean1090_Lean1090_Impl_cbRollValid50Table;
v___x_1039_ = lean_unsigned_to_nat(2u);
v___x_1040_ = lean_unsigned_to_nat(10u);
v___x_1041_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1037_, v___x_1039_, v___x_1040_);
v___x_1042_ = lean_array_fget_borrowed(v___x_1038_, v___x_1041_);
lean_dec(v___x_1041_);
v___x_1043_ = lean_unbox(v___x_1042_);
return v___x_1043_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollValid50___boxed(lean_object* v_word_1044_){
_start:
{
uint8_t v_res_1045_; lean_object* v_r_1046_; 
v_res_1045_ = lp_lean1090_Lean1090_Impl_cbRollValid50(v_word_1044_);
lean_dec(v_word_1044_);
v_r_1046_ = lean_box(v_res_1045_);
return v_r_1046_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid50(lean_object* v_word_1047_){
_start:
{
uint8_t v___y_1049_; lean_object* v___x_1076_; lean_object* v___x_1077_; lean_object* v___x_1078_; uint8_t v___x_1079_; 
v___x_1076_ = lean_unsigned_to_nat(1u);
v___x_1077_ = lean_unsigned_to_nat(2u);
v___x_1078_ = lean_unsigned_to_nat(10u);
v___x_1079_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1047_, v___x_1076_, v___x_1077_, v___x_1078_);
if (v___x_1079_ == 0)
{
v___y_1049_ = v___x_1079_;
goto v___jp_1048_;
}
else
{
lean_object* v___x_1080_; lean_object* v___x_1081_; lean_object* v___x_1082_; uint8_t v___x_1083_; 
v___x_1080_ = lean_unsigned_to_nat(12u);
v___x_1081_ = lean_unsigned_to_nat(13u);
v___x_1082_ = lean_unsigned_to_nat(11u);
v___x_1083_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1047_, v___x_1080_, v___x_1081_, v___x_1082_);
v___y_1049_ = v___x_1083_;
goto v___jp_1048_;
}
v___jp_1048_:
{
if (v___y_1049_ == 0)
{
return v___y_1049_;
}
else
{
lean_object* v___x_1050_; lean_object* v___x_1051_; lean_object* v___x_1052_; uint8_t v___x_1053_; 
v___x_1050_ = lean_unsigned_to_nat(24u);
v___x_1051_ = lean_unsigned_to_nat(25u);
v___x_1052_ = lean_unsigned_to_nat(10u);
v___x_1053_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1047_, v___x_1050_, v___x_1051_, v___x_1052_);
if (v___x_1053_ == 0)
{
return v___x_1053_;
}
else
{
lean_object* v___x_1054_; lean_object* v___x_1055_; uint8_t v___x_1056_; 
v___x_1054_ = lean_unsigned_to_nat(35u);
v___x_1055_ = lean_unsigned_to_nat(36u);
v___x_1056_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1047_, v___x_1054_, v___x_1055_, v___x_1052_);
if (v___x_1056_ == 0)
{
return v___x_1056_;
}
else
{
lean_object* v___x_1057_; lean_object* v___x_1058_; uint8_t v___x_1059_; 
v___x_1057_ = lean_unsigned_to_nat(46u);
v___x_1058_ = lean_unsigned_to_nat(47u);
v___x_1059_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1047_, v___x_1057_, v___x_1058_, v___x_1052_);
if (v___x_1059_ == 0)
{
return v___x_1059_;
}
else
{
uint8_t v___x_1060_; 
v___x_1060_ = lp_lean1090_Lean1090_Impl_cbRollValid50(v_word_1047_);
if (v___x_1060_ == 0)
{
return v___x_1060_;
}
else
{
lean_object* v___x_1061_; lean_object* v___x_1062_; lean_object* v___x_1063_; lean_object* v___x_1064_; uint8_t v___x_1065_; 
v___x_1061_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1047_, v___x_1051_, v___x_1052_);
v___x_1062_ = lean_unsigned_to_nat(2u);
v___x_1063_ = lean_nat_mul(v___x_1061_, v___x_1062_);
lean_dec(v___x_1061_);
v___x_1064_ = lean_unsigned_to_nat(700u);
v___x_1065_ = lean_nat_dec_le(v___x_1063_, v___x_1064_);
lean_dec(v___x_1063_);
if (v___x_1065_ == 0)
{
return v___x_1065_;
}
else
{
lean_object* v___x_1066_; lean_object* v___x_1067_; lean_object* v___x_1068_; uint8_t v___x_1069_; 
v___x_1066_ = lean_unsigned_to_nat(1u);
v___x_1067_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1047_, v___x_1057_, v___x_1066_);
v___x_1068_ = lean_unsigned_to_nat(0u);
v___x_1069_ = lean_nat_dec_eq(v___x_1067_, v___x_1068_);
lean_dec(v___x_1067_);
if (v___x_1069_ == 0)
{
lean_object* v___x_1070_; lean_object* v___x_1071_; lean_object* v___x_1072_; uint8_t v___x_1073_; 
v___x_1070_ = lean_unsigned_to_nat(80u);
v___x_1071_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1047_, v___x_1058_, v___x_1052_);
v___x_1072_ = lean_nat_mul(v___x_1071_, v___x_1062_);
lean_dec(v___x_1071_);
v___x_1073_ = lean_nat_dec_le(v___x_1070_, v___x_1072_);
if (v___x_1073_ == 0)
{
lean_dec(v___x_1072_);
return v___x_1073_;
}
else
{
lean_object* v___x_1074_; uint8_t v___x_1075_; 
v___x_1074_ = lean_unsigned_to_nat(600u);
v___x_1075_ = lean_nat_dec_le(v___x_1072_, v___x_1074_);
lean_dec(v___x_1072_);
return v___x_1075_;
}
}
else
{
return v___x_1069_;
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid50___boxed(lean_object* v_word_1084_){
_start:
{
uint8_t v_res_1085_; lean_object* v_r_1086_; 
v_res_1085_ = lp_lean1090_Lean1090_Impl_cbValid50(v_word_1084_);
lean_dec(v_word_1084_);
v_r_1086_ = lean_box(v_res_1085_);
return v_r_1086_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbMachValid60Table_spec__0(size_t v_sz_1087_, size_t v_i_1088_, lean_object* v_bs_1089_){
_start:
{
uint8_t v___x_1090_; 
v___x_1090_ = lean_usize_dec_lt(v_i_1088_, v_sz_1087_);
if (v___x_1090_ == 0)
{
return v_bs_1089_;
}
else
{
lean_object* v_v_1091_; lean_object* v___x_1092_; lean_object* v_bs_x27_1093_; lean_object* v___x_1094_; uint8_t v___x_1095_; size_t v___x_1096_; size_t v___x_1097_; lean_object* v___x_1098_; lean_object* v___x_1099_; 
v_v_1091_ = lean_array_uget(v_bs_1089_, v_i_1088_);
v___x_1092_ = lean_unsigned_to_nat(0u);
v_bs_x27_1093_ = lean_array_uset(v_bs_1089_, v_i_1088_, v___x_1092_);
v___x_1094_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0);
v___x_1095_ = l_Rat_instDecidableLe(v_v_1091_, v___x_1094_);
v___x_1096_ = ((size_t)1ULL);
v___x_1097_ = lean_usize_add(v_i_1088_, v___x_1096_);
v___x_1098_ = lean_box(v___x_1095_);
v___x_1099_ = lean_array_uset(v_bs_x27_1093_, v_i_1088_, v___x_1098_);
v_i_1088_ = v___x_1097_;
v_bs_1089_ = v___x_1099_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbMachValid60Table_spec__0___boxed(lean_object* v_sz_1101_, lean_object* v_i_1102_, lean_object* v_bs_1103_){
_start:
{
size_t v_sz_boxed_1104_; size_t v_i_boxed_1105_; lean_object* v_res_1106_; 
v_sz_boxed_1104_ = lean_unbox_usize(v_sz_1101_);
lean_dec(v_sz_1101_);
v_i_boxed_1105_ = lean_unbox_usize(v_i_1102_);
lean_dec(v_i_1102_);
v_res_1106_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbMachValid60Table_spec__0(v_sz_boxed_1104_, v_i_boxed_1105_, v_bs_1103_);
return v_res_1106_;
}
}
static size_t _init_lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__0(void){
_start:
{
lean_object* v___x_1107_; size_t v_sz_1108_; 
v___x_1107_ = lp_lean1090_Lean1090_Impl_cbMachValueTable;
v_sz_1108_ = lean_array_size(v___x_1107_);
return v_sz_1108_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__1(void){
_start:
{
lean_object* v___x_1109_; size_t v___x_1110_; size_t v_sz_1111_; lean_object* v___x_1112_; 
v___x_1109_ = lp_lean1090_Lean1090_Impl_cbMachValueTable;
v___x_1110_ = ((size_t)0ULL);
v_sz_1111_ = lean_usize_once(&lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__0, &lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__0);
v___x_1112_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbMachValid60Table_spec__0(v_sz_1111_, v___x_1110_, v___x_1109_);
return v___x_1112_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValid60Table(void){
_start:
{
lean_object* v___x_1113_; 
v___x_1113_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__1, &lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__1);
return v___x_1113_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbMachValid60(lean_object* v_word_1114_){
_start:
{
lean_object* v___x_1115_; lean_object* v___x_1116_; lean_object* v___x_1117_; lean_object* v___x_1118_; lean_object* v___x_1119_; uint8_t v___x_1120_; 
v___x_1115_ = lp_lean1090_Lean1090_Impl_cbMachValid60Table;
v___x_1116_ = lean_unsigned_to_nat(25u);
v___x_1117_ = lean_unsigned_to_nat(10u);
v___x_1118_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1114_, v___x_1116_, v___x_1117_);
v___x_1119_ = lean_array_fget_borrowed(v___x_1115_, v___x_1118_);
lean_dec(v___x_1118_);
v___x_1120_ = lean_unbox(v___x_1119_);
return v___x_1120_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachValid60___boxed(lean_object* v_word_1121_){
_start:
{
uint8_t v_res_1122_; lean_object* v_r_1123_; 
v_res_1122_ = lp_lean1090_Lean1090_Impl_cbMachValid60(v_word_1121_);
lean_dec(v_word_1121_);
v_r_1123_ = lean_box(v_res_1122_);
return v_r_1123_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1124_; lean_object* v___x_1125_; 
v___x_1124_ = lean_unsigned_to_nat(6000u);
v___x_1125_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1124_);
return v___x_1125_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0(lean_object* v_code_1126_){
_start:
{
lean_object* v___x_1127_; lean_object* v___x_1128_; lean_object* v___x_1129_; lean_object* v___x_1130_; uint8_t v___x_1131_; 
v___x_1127_ = lean_unsigned_to_nat(47u);
v___x_1128_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_code_1126_, v___x_1127_);
v___x_1129_ = l_Rat_abs(v___x_1128_);
v___x_1130_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___closed__0);
v___x_1131_ = l_Rat_instDecidableLe(v___x_1129_, v___x_1130_);
return v___x_1131_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___boxed(lean_object* v_code_1132_){
_start:
{
uint8_t v_res_1133_; lean_object* v_r_1134_; 
v_res_1133_ = lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0(v_code_1132_);
lean_dec(v_code_1132_);
v_r_1134_ = lean_box(v_res_1133_);
return v_r_1134_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__1(void){
_start:
{
lean_object* v___f_1136_; lean_object* v___x_1137_; lean_object* v___x_1138_; 
v___f_1136_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__0));
v___x_1137_ = lean_unsigned_to_nat(1024u);
v___x_1138_ = l_Array_ofFn___redArg(v___x_1137_, v___f_1136_);
return v___x_1138_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalValid60Table(void){
_start:
{
lean_object* v___x_1139_; 
v___x_1139_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__1, &lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__1);
return v___x_1139_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbVerticalValid60(lean_object* v_word_1140_){
_start:
{
lean_object* v___x_1141_; lean_object* v___x_1142_; lean_object* v___x_1143_; lean_object* v___x_1144_; lean_object* v___x_1145_; uint8_t v___x_1146_; 
v___x_1141_ = lp_lean1090_Lean1090_Impl_cbVerticalValid60Table;
v___x_1142_ = lean_unsigned_to_nat(47u);
v___x_1143_ = lean_unsigned_to_nat(10u);
v___x_1144_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1140_, v___x_1142_, v___x_1143_);
v___x_1145_ = lean_array_fget_borrowed(v___x_1141_, v___x_1144_);
lean_dec(v___x_1144_);
v___x_1146_ = lean_unbox(v___x_1145_);
return v___x_1146_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalValid60___boxed(lean_object* v_word_1147_){
_start:
{
uint8_t v_res_1148_; lean_object* v_r_1149_; 
v_res_1148_ = lp_lean1090_Lean1090_Impl_cbVerticalValid60(v_word_1147_);
lean_dec(v_word_1147_);
v_r_1149_ = lean_box(v_res_1148_);
return v_r_1149_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid60(lean_object* v_word_1150_){
_start:
{
uint8_t v___y_1152_; lean_object* v___x_1169_; lean_object* v___x_1170_; lean_object* v___x_1171_; uint8_t v___x_1172_; 
v___x_1169_ = lean_unsigned_to_nat(1u);
v___x_1170_ = lean_unsigned_to_nat(2u);
v___x_1171_ = lean_unsigned_to_nat(11u);
v___x_1172_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1150_, v___x_1169_, v___x_1170_, v___x_1171_);
if (v___x_1172_ == 0)
{
v___y_1152_ = v___x_1172_;
goto v___jp_1151_;
}
else
{
lean_object* v___x_1173_; lean_object* v___x_1174_; lean_object* v___x_1175_; uint8_t v___x_1176_; 
v___x_1173_ = lean_unsigned_to_nat(13u);
v___x_1174_ = lean_unsigned_to_nat(14u);
v___x_1175_ = lean_unsigned_to_nat(10u);
v___x_1176_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1150_, v___x_1173_, v___x_1174_, v___x_1175_);
v___y_1152_ = v___x_1176_;
goto v___jp_1151_;
}
v___jp_1151_:
{
if (v___y_1152_ == 0)
{
return v___y_1152_;
}
else
{
lean_object* v___x_1153_; lean_object* v___x_1154_; lean_object* v___x_1155_; uint8_t v___x_1156_; 
v___x_1153_ = lean_unsigned_to_nat(24u);
v___x_1154_ = lean_unsigned_to_nat(25u);
v___x_1155_ = lean_unsigned_to_nat(10u);
v___x_1156_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1150_, v___x_1153_, v___x_1154_, v___x_1155_);
if (v___x_1156_ == 0)
{
return v___x_1156_;
}
else
{
lean_object* v___x_1157_; lean_object* v___x_1158_; uint8_t v___x_1159_; 
v___x_1157_ = lean_unsigned_to_nat(35u);
v___x_1158_ = lean_unsigned_to_nat(36u);
v___x_1159_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1150_, v___x_1157_, v___x_1158_, v___x_1155_);
if (v___x_1159_ == 0)
{
return v___x_1159_;
}
else
{
lean_object* v___x_1160_; lean_object* v___x_1161_; uint8_t v___x_1162_; 
v___x_1160_ = lean_unsigned_to_nat(46u);
v___x_1161_ = lean_unsigned_to_nat(47u);
v___x_1162_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1150_, v___x_1160_, v___x_1161_, v___x_1155_);
if (v___x_1162_ == 0)
{
return v___x_1162_;
}
else
{
lean_object* v___x_1163_; lean_object* v___x_1164_; lean_object* v___x_1165_; uint8_t v___x_1166_; 
v___x_1163_ = lean_unsigned_to_nat(14u);
v___x_1164_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1150_, v___x_1163_, v___x_1155_);
v___x_1165_ = lean_unsigned_to_nat(500u);
v___x_1166_ = lean_nat_dec_le(v___x_1164_, v___x_1165_);
lean_dec(v___x_1164_);
if (v___x_1166_ == 0)
{
return v___x_1166_;
}
else
{
uint8_t v___x_1167_; 
v___x_1167_ = lp_lean1090_Lean1090_Impl_cbMachValid60(v_word_1150_);
if (v___x_1167_ == 0)
{
return v___x_1167_;
}
else
{
uint8_t v___x_1168_; 
v___x_1168_ = lp_lean1090_Lean1090_Impl_cbVerticalValid60(v_word_1150_);
return v___x_1168_;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid60___boxed(lean_object* v_word_1177_){
_start:
{
uint8_t v_res_1178_; lean_object* v_r_1179_; 
v_res_1178_ = lp_lean1090_Lean1090_Impl_cbValid60(v_word_1177_);
lean_dec(v_word_1177_);
v_r_1179_ = lean_box(v_res_1178_);
return v_r_1179_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBPayloadLimit(void){
_start:
{
lean_object* v___x_1180_; 
v___x_1180_ = lean_cstr_to_nat("72057594037927936");
return v___x_1180_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_bdsWireValid(lean_object* v_register_1181_, lean_object* v_word_1182_){
_start:
{
lean_object* v___x_1183_; uint8_t v___x_1184_; 
v___x_1183_ = lp_lean1090_Lean1090_Impl_commBPayloadLimit;
v___x_1184_ = lean_nat_dec_lt(v_word_1182_, v___x_1183_);
if (v___x_1184_ == 0)
{
return v___x_1184_;
}
else
{
lean_object* v___x_1185_; uint8_t v___x_1186_; 
v___x_1185_ = lean_unsigned_to_nat(5u);
v___x_1186_ = lean_nat_dec_eq(v_register_1181_, v___x_1185_);
if (v___x_1186_ == 0)
{
lean_object* v___x_1187_; uint8_t v___x_1188_; 
v___x_1187_ = lean_unsigned_to_nat(101u);
v___x_1188_ = lean_nat_dec_eq(v_register_1181_, v___x_1187_);
if (v___x_1188_ == 0)
{
lean_object* v___x_1189_; uint8_t v___x_1190_; 
v___x_1189_ = lean_unsigned_to_nat(16u);
v___x_1190_ = lean_nat_dec_eq(v_register_1181_, v___x_1189_);
if (v___x_1190_ == 0)
{
lean_object* v___x_1191_; uint8_t v___x_1192_; 
v___x_1191_ = lean_unsigned_to_nat(23u);
v___x_1192_ = lean_nat_dec_eq(v_register_1181_, v___x_1191_);
if (v___x_1192_ == 0)
{
lean_object* v___x_1193_; uint8_t v___x_1194_; 
v___x_1193_ = lean_unsigned_to_nat(24u);
v___x_1194_ = lean_nat_dec_eq(v_register_1181_, v___x_1193_);
if (v___x_1194_ == 0)
{
lean_object* v___x_1195_; uint8_t v___x_1196_; 
v___x_1195_ = lean_unsigned_to_nat(25u);
v___x_1196_ = lean_nat_dec_eq(v_register_1181_, v___x_1195_);
if (v___x_1196_ == 0)
{
lean_object* v___x_1197_; uint8_t v___x_1198_; 
v___x_1197_ = lean_unsigned_to_nat(32u);
v___x_1198_ = lean_nat_dec_eq(v_register_1181_, v___x_1197_);
if (v___x_1198_ == 0)
{
lean_object* v___x_1199_; uint8_t v___x_1200_; 
v___x_1199_ = lean_unsigned_to_nat(33u);
v___x_1200_ = lean_nat_dec_eq(v_register_1181_, v___x_1199_);
if (v___x_1200_ == 0)
{
lean_object* v___x_1201_; uint8_t v___x_1202_; 
v___x_1201_ = lean_unsigned_to_nat(48u);
v___x_1202_ = lean_nat_dec_eq(v_register_1181_, v___x_1201_);
if (v___x_1202_ == 0)
{
lean_object* v___x_1203_; uint8_t v___x_1204_; 
v___x_1203_ = lean_unsigned_to_nat(64u);
v___x_1204_ = lean_nat_dec_eq(v_register_1181_, v___x_1203_);
if (v___x_1204_ == 0)
{
lean_object* v___x_1205_; uint8_t v___x_1206_; 
v___x_1205_ = lean_unsigned_to_nat(68u);
v___x_1206_ = lean_nat_dec_eq(v_register_1181_, v___x_1205_);
if (v___x_1206_ == 0)
{
lean_object* v___x_1207_; uint8_t v___x_1208_; 
v___x_1207_ = lean_unsigned_to_nat(69u);
v___x_1208_ = lean_nat_dec_eq(v_register_1181_, v___x_1207_);
if (v___x_1208_ == 0)
{
lean_object* v___x_1209_; uint8_t v___x_1210_; 
v___x_1209_ = lean_unsigned_to_nat(80u);
v___x_1210_ = lean_nat_dec_eq(v_register_1181_, v___x_1209_);
if (v___x_1210_ == 0)
{
lean_object* v___x_1211_; uint8_t v___x_1212_; 
v___x_1211_ = lean_unsigned_to_nat(96u);
v___x_1212_ = lean_nat_dec_eq(v_register_1181_, v___x_1211_);
if (v___x_1212_ == 0)
{
return v___x_1212_;
}
else
{
uint8_t v___x_1213_; 
v___x_1213_ = lp_lean1090_Lean1090_Impl_cbValid60(v_word_1182_);
return v___x_1213_;
}
}
else
{
uint8_t v___x_1214_; 
v___x_1214_ = lp_lean1090_Lean1090_Impl_cbValid50(v_word_1182_);
return v___x_1214_;
}
}
else
{
uint8_t v___x_1215_; 
v___x_1215_ = lp_lean1090_Lean1090_Impl_cbValid45(v_word_1182_);
return v___x_1215_;
}
}
else
{
uint8_t v___x_1216_; 
v___x_1216_ = lp_lean1090_Lean1090_Impl_cbValid44(v_word_1182_);
return v___x_1216_;
}
}
else
{
uint8_t v___x_1217_; 
v___x_1217_ = lp_lean1090_Lean1090_Impl_cbValid40(v_word_1182_);
return v___x_1217_;
}
}
else
{
lean_object* v___x_1218_; lean_object* v___x_1219_; lean_object* v___x_1220_; uint8_t v___x_1221_; 
v___x_1218_ = lean_unsigned_to_nat(1u);
v___x_1219_ = lean_unsigned_to_nat(8u);
v___x_1220_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1182_, v___x_1218_, v___x_1219_);
v___x_1221_ = lean_nat_dec_eq(v___x_1220_, v___x_1201_);
lean_dec(v___x_1220_);
return v___x_1221_;
}
}
else
{
uint8_t v___x_1222_; 
v___x_1222_ = lp_lean1090_Lean1090_Impl_cbValid21(v_word_1182_);
return v___x_1222_;
}
}
else
{
lean_object* v___x_1223_; lean_object* v___x_1224_; lean_object* v___x_1225_; uint8_t v___x_1226_; 
v___x_1223_ = lean_unsigned_to_nat(1u);
v___x_1224_ = lean_unsigned_to_nat(8u);
v___x_1225_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1182_, v___x_1223_, v___x_1224_);
v___x_1226_ = lean_nat_dec_eq(v___x_1225_, v___x_1197_);
lean_dec(v___x_1225_);
return v___x_1226_;
}
}
else
{
uint8_t v___x_1227_; 
v___x_1227_ = lp_lean1090_Lean1090_Impl_cbValid19(v_word_1182_);
return v___x_1227_;
}
}
else
{
uint8_t v___x_1228_; 
v___x_1228_ = lp_lean1090_Lean1090_Impl_cbValid18(v_word_1182_);
return v___x_1228_;
}
}
else
{
uint8_t v___x_1229_; 
v___x_1229_ = lp_lean1090_Lean1090_Impl_cbValid17(v_word_1182_);
return v___x_1229_;
}
}
else
{
lean_object* v___x_1230_; lean_object* v___x_1231_; lean_object* v___x_1232_; uint8_t v___x_1233_; 
v___x_1230_ = lean_unsigned_to_nat(1u);
v___x_1231_ = lean_unsigned_to_nat(8u);
v___x_1232_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1182_, v___x_1230_, v___x_1231_);
v___x_1233_ = lean_nat_dec_eq(v___x_1232_, v___x_1189_);
lean_dec(v___x_1232_);
if (v___x_1233_ == 0)
{
return v___x_1233_;
}
else
{
lean_object* v___x_1234_; lean_object* v___x_1235_; lean_object* v___x_1236_; uint8_t v___x_1237_; 
v___x_1234_ = lean_unsigned_to_nat(10u);
v___x_1235_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1182_, v___x_1234_, v___x_1185_);
v___x_1236_ = lean_unsigned_to_nat(0u);
v___x_1237_ = lean_nat_dec_eq(v___x_1235_, v___x_1236_);
lean_dec(v___x_1235_);
return v___x_1237_;
}
}
}
else
{
lean_object* v___x_1238_; lean_object* v___x_1239_; lean_object* v___x_1240_; uint8_t v___x_1241_; 
v___x_1238_ = lean_unsigned_to_nat(1u);
v___x_1239_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1182_, v___x_1238_, v___x_1185_);
v___x_1240_ = lean_unsigned_to_nat(31u);
v___x_1241_ = lean_nat_dec_eq(v___x_1239_, v___x_1240_);
lean_dec(v___x_1239_);
if (v___x_1241_ == 0)
{
return v___x_1241_;
}
else
{
lean_object* v___x_1242_; lean_object* v___x_1243_; lean_object* v___x_1244_; lean_object* v___x_1245_; uint8_t v___x_1246_; 
v___x_1242_ = lean_unsigned_to_nat(6u);
v___x_1243_ = lean_unsigned_to_nat(3u);
v___x_1244_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1182_, v___x_1242_, v___x_1243_);
v___x_1245_ = lean_unsigned_to_nat(2u);
v___x_1246_ = lean_nat_dec_lt(v___x_1244_, v___x_1245_);
lean_dec(v___x_1244_);
if (v___x_1246_ == 0)
{
return v___x_1246_;
}
else
{
uint8_t v___x_1247_; 
v___x_1247_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1182_);
return v___x_1247_;
}
}
}
}
else
{
lean_object* v___x_1248_; lean_object* v_tc_1249_; lean_object* v___x_1256_; uint8_t v___x_1257_; 
v___x_1248_ = lean_unsigned_to_nat(1u);
v_tc_1249_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1182_, v___x_1248_, v___x_1185_);
v___x_1256_ = lean_unsigned_to_nat(9u);
v___x_1257_ = lean_nat_dec_le(v___x_1256_, v_tc_1249_);
if (v___x_1257_ == 0)
{
goto v___jp_1250_;
}
else
{
lean_object* v___x_1258_; uint8_t v___x_1259_; 
v___x_1258_ = lean_unsigned_to_nat(18u);
v___x_1259_ = lean_nat_dec_le(v_tc_1249_, v___x_1258_);
if (v___x_1259_ == 0)
{
goto v___jp_1250_;
}
else
{
uint8_t v___x_1260_; 
lean_dec(v_tc_1249_);
v___x_1260_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1182_);
return v___x_1260_;
}
}
v___jp_1250_:
{
lean_object* v___x_1251_; uint8_t v___x_1252_; 
v___x_1251_ = lean_unsigned_to_nat(20u);
v___x_1252_ = lean_nat_dec_le(v___x_1251_, v_tc_1249_);
if (v___x_1252_ == 0)
{
lean_dec(v_tc_1249_);
return v___x_1252_;
}
else
{
lean_object* v___x_1253_; uint8_t v___x_1254_; 
v___x_1253_ = lean_unsigned_to_nat(22u);
v___x_1254_ = lean_nat_dec_le(v_tc_1249_, v___x_1253_);
lean_dec(v_tc_1249_);
if (v___x_1254_ == 0)
{
return v___x_1254_;
}
else
{
uint8_t v___x_1255_; 
v___x_1255_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1182_);
return v___x_1255_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsWireValid___boxed(lean_object* v_register_1261_, lean_object* v_word_1262_){
_start:
{
uint8_t v_res_1263_; lean_object* v_r_1264_; 
v_res_1263_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1261_, v_word_1262_);
lean_dec(v_word_1262_);
lean_dec(v_register_1261_);
v_r_1264_ = lean_box(v_res_1263_);
return v_r_1264_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_bdsLayout___closed__0(void){
_start:
{
lean_object* v___x_1265_; lean_object* v___x_1266_; 
v___x_1265_ = lp_lean1090_Lean1090_Impl_adsbPositionLayout;
v___x_1266_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1266_, 0, v___x_1265_);
return v___x_1266_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsLayout(lean_object* v_register_1267_, lean_object* v_word_1268_){
_start:
{
lean_object* v___x_1269_; uint8_t v___x_1270_; 
v___x_1269_ = lean_unsigned_to_nat(5u);
v___x_1270_ = lean_nat_dec_eq(v_register_1267_, v___x_1269_);
if (v___x_1270_ == 0)
{
lean_object* v___x_1271_; uint8_t v___x_1272_; 
v___x_1271_ = lean_unsigned_to_nat(101u);
v___x_1272_ = lean_nat_dec_eq(v_register_1267_, v___x_1271_);
if (v___x_1272_ == 0)
{
lean_object* v___x_1273_; 
v___x_1273_ = lp_lean1090_Lean1090_Impl_commBLayout(v_register_1267_);
return v___x_1273_;
}
else
{
lean_object* v___x_1274_; 
v___x_1274_ = lp_lean1090_Lean1090_Impl_adsbLayout(v_word_1268_);
return v___x_1274_;
}
}
else
{
lean_object* v___x_1275_; 
v___x_1275_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_bdsLayout___closed__0, &lp_lean1090_Lean1090_Impl_bdsLayout___closed__0_once, _init_lp_lean1090_Lean1090_Impl_bdsLayout___closed__0);
return v___x_1275_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsLayout___boxed(lean_object* v_register_1276_, lean_object* v_word_1277_){
_start:
{
lean_object* v_res_1278_; 
v_res_1278_ = lp_lean1090_Lean1090_Impl_bdsLayout(v_register_1276_, v_word_1277_);
lean_dec(v_word_1277_);
lean_dec(v_register_1276_);
return v_res_1278_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeBDS(lean_object* v_register_1279_, lean_object* v_word_1280_){
_start:
{
lean_object* v___x_1281_; 
v___x_1281_ = lp_lean1090_Lean1090_Impl_bdsLayout(v_register_1279_, v_word_1280_);
if (lean_obj_tag(v___x_1281_) == 0)
{
lean_object* v___x_1282_; 
lean_dec(v_register_1279_);
v___x_1282_ = lean_box(0);
return v___x_1282_;
}
else
{
lean_object* v_val_1283_; lean_object* v___x_1285_; uint8_t v_isShared_1286_; uint8_t v_isSharedCheck_1294_; 
v_val_1283_ = lean_ctor_get(v___x_1281_, 0);
v_isSharedCheck_1294_ = !lean_is_exclusive(v___x_1281_);
if (v_isSharedCheck_1294_ == 0)
{
v___x_1285_ = v___x_1281_;
v_isShared_1286_ = v_isSharedCheck_1294_;
goto v_resetjp_1284_;
}
else
{
lean_inc(v_val_1283_);
lean_dec(v___x_1281_);
v___x_1285_ = lean_box(0);
v_isShared_1286_ = v_isSharedCheck_1294_;
goto v_resetjp_1284_;
}
v_resetjp_1284_:
{
uint8_t v___x_1287_; 
v___x_1287_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1279_, v_word_1280_);
if (v___x_1287_ == 0)
{
lean_object* v___x_1288_; 
lean_del_object(v___x_1285_);
lean_dec(v_val_1283_);
lean_dec(v_register_1279_);
v___x_1288_ = lean_box(0);
return v___x_1288_;
}
else
{
lean_object* v___x_1289_; lean_object* v___x_1290_; lean_object* v___x_1292_; 
v___x_1289_ = lp_lean1090_Lean1090_Impl_decodePayloadFields(v_val_1283_, v_word_1280_);
v___x_1290_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1290_, 0, v_register_1279_);
lean_ctor_set(v___x_1290_, 1, v___x_1289_);
if (v_isShared_1286_ == 0)
{
lean_ctor_set(v___x_1285_, 0, v___x_1290_);
v___x_1292_ = v___x_1285_;
goto v_reusejp_1291_;
}
else
{
lean_object* v_reuseFailAlloc_1293_; 
v_reuseFailAlloc_1293_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1293_, 0, v___x_1290_);
v___x_1292_ = v_reuseFailAlloc_1293_;
goto v_reusejp_1291_;
}
v_reusejp_1291_:
{
return v___x_1292_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeBDS___boxed(lean_object* v_register_1295_, lean_object* v_word_1296_){
_start:
{
lean_object* v_res_1297_; 
v_res_1297_ = lp_lean1090_Lean1090_Impl_decodeBDS(v_register_1295_, v_word_1296_);
lean_dec(v_word_1296_);
return v_res_1297_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__0(void){
_start:
{
lean_object* v___x_1298_; lean_object* v___x_1299_; 
v___x_1298_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0);
v___x_1299_ = l_Rat_neg(v___x_1298_);
return v___x_1299_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1(void){
_start:
{
lean_object* v___x_1300_; lean_object* v___x_1301_; 
v___x_1300_ = lean_unsigned_to_nat(2u);
v___x_1301_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1300_);
return v___x_1301_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__2(void){
_start:
{
lean_object* v___x_1302_; lean_object* v___x_1303_; lean_object* v___x_1304_; 
v___x_1302_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1303_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__0, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__0);
v___x_1304_ = l_Rat_div(v___x_1303_, v___x_1302_);
return v___x_1304_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGaussian(lean_object* v_value_1305_, lean_object* v_mu_1306_, lean_object* v_sigma_1307_){
_start:
{
lean_object* v___x_1308_; lean_object* v___x_1309_; lean_object* v___x_1310_; lean_object* v_z_1311_; lean_object* v___x_1312_; lean_object* v___x_1313_; lean_object* v___x_1314_; 
v___x_1308_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_mu_1306_);
v___x_1309_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_value_1305_, v___x_1308_);
v___x_1310_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_sigma_1307_);
v_z_1311_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1309_, v___x_1310_);
lean_dec_ref(v___x_1309_);
v___x_1312_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__2, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__2);
lean_inc_ref(v_z_1311_);
v___x_1313_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1312_, v_z_1311_);
v___x_1314_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1313_, v_z_1311_);
lean_dec_ref(v___x_1313_);
return v___x_1314_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbLaplace(lean_object* v_value_1315_, lean_object* v_median_1316_, lean_object* v_scale_1317_){
_start:
{
lean_object* v___x_1318_; uint8_t v___x_1319_; 
v___x_1318_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_scale_1317_);
v___x_1319_ = l_Rat_instDecidableLe(v_scale_1317_, v___x_1318_);
if (v___x_1319_ == 0)
{
lean_object* v___x_1320_; lean_object* v___x_1321_; lean_object* v___x_1322_; lean_object* v___x_1323_; lean_object* v___x_1324_; lean_object* v___x_1325_; 
v___x_1320_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_median_1316_);
v___x_1321_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_value_1315_, v___x_1320_);
v___x_1322_ = l_Rat_abs(v___x_1321_);
v___x_1323_ = l_Rat_neg(v___x_1322_);
v___x_1324_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_scale_1317_);
v___x_1325_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1323_, v___x_1324_);
lean_dec_ref(v___x_1323_);
return v___x_1325_;
}
else
{
lean_dec_ref(v_scale_1317_);
lean_dec_ref(v_median_1316_);
lean_dec_ref(v_value_1315_);
return v___x_1318_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScoreField(lean_object* v_value_1326_, lean_object* v_score_1327_){
_start:
{
if (lean_obj_tag(v_value_1326_) == 0)
{
lean_object* v___x_1328_; 
lean_dec_ref(v_score_1327_);
v___x_1328_ = lean_box(0);
return v___x_1328_;
}
else
{
lean_object* v_val_1329_; lean_object* v___x_1330_; lean_object* v___x_1331_; lean_object* v___x_1332_; 
v_val_1329_ = lean_ctor_get(v_value_1326_, 0);
lean_inc(v_val_1329_);
lean_dec_ref_known(v_value_1326_, 1);
v___x_1330_ = lean_apply_1(v_score_1327_, v_val_1329_);
v___x_1331_ = lean_box(0);
v___x_1332_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1332_, 0, v___x_1330_);
lean_ctor_set(v___x_1332_, 1, v___x_1331_);
return v___x_1332_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1333_; lean_object* v___x_1334_; 
v___x_1333_ = lean_unsigned_to_nat(142u);
v___x_1334_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1333_);
return v___x_1334_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1(void){
_start:
{
lean_object* v___x_1335_; lean_object* v___x_1336_; 
v___x_1335_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0);
v___x_1336_ = l_Rat_neg(v___x_1335_);
return v___x_1336_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2(void){
_start:
{
lean_object* v___x_1337_; lean_object* v___x_1338_; lean_object* v___x_1339_; 
v___x_1337_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1338_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1);
v___x_1339_ = l_Rat_div(v___x_1338_, v___x_1337_);
return v___x_1339_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3(void){
_start:
{
lean_object* v___x_1340_; lean_object* v___x_1341_; 
v___x_1340_ = lean_unsigned_to_nat(164u);
v___x_1341_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1340_);
return v___x_1341_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4(void){
_start:
{
lean_object* v___x_1342_; lean_object* v___x_1343_; lean_object* v___x_1344_; 
v___x_1342_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1343_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3);
v___x_1344_ = l_Rat_div(v___x_1343_, v___x_1342_);
return v___x_1344_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0(lean_object* v_x_1345_){
_start:
{
lean_object* v___x_1346_; lean_object* v___x_1347_; lean_object* v___x_1348_; 
v___x_1346_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2);
v___x_1347_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4);
v___x_1348_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1345_, v___x_1346_, v___x_1347_);
return v___x_1348_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0(void){
_start:
{
lean_object* v___x_1349_; lean_object* v___x_1350_; 
v___x_1349_ = lean_unsigned_to_nat(393u);
v___x_1350_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1349_);
return v___x_1350_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1(void){
_start:
{
lean_object* v___x_1351_; lean_object* v___x_1352_; 
v___x_1351_ = lean_unsigned_to_nat(290u);
v___x_1352_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1351_);
return v___x_1352_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1(lean_object* v_x_1353_){
_start:
{
lean_object* v___x_1354_; lean_object* v___x_1355_; lean_object* v___x_1356_; 
v___x_1354_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0);
v___x_1355_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1);
v___x_1356_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1353_, v___x_1354_, v___x_1355_);
return v___x_1356_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0(void){
_start:
{
lean_object* v___x_1357_; lean_object* v___x_1358_; 
v___x_1357_ = lean_unsigned_to_nat(52u);
v___x_1358_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1357_);
return v___x_1358_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1(void){
_start:
{
lean_object* v___x_1359_; lean_object* v___x_1360_; 
v___x_1359_ = lean_unsigned_to_nat(29u);
v___x_1360_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1359_);
return v___x_1360_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2(lean_object* v_x_1361_){
_start:
{
lean_object* v___x_1362_; lean_object* v___x_1363_; lean_object* v___x_1364_; 
v___x_1362_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0);
v___x_1363_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1);
v___x_1364_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1361_, v___x_1362_, v___x_1363_);
return v___x_1364_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0(void){
_start:
{
lean_object* v___x_1365_; lean_object* v___x_1366_; 
v___x_1365_ = lean_unsigned_to_nat(272u);
v___x_1366_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1365_);
return v___x_1366_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1(void){
_start:
{
lean_object* v___x_1367_; lean_object* v___x_1368_; 
v___x_1367_ = lean_unsigned_to_nat(55u);
v___x_1368_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1367_);
return v___x_1368_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4(lean_object* v_x_1369_){
_start:
{
lean_object* v___x_1370_; lean_object* v___x_1371_; lean_object* v___x_1372_; 
v___x_1370_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0);
v___x_1371_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1);
v___x_1372_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1369_, v___x_1370_, v___x_1371_);
return v___x_1372_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0(void){
_start:
{
lean_object* v___x_1373_; lean_object* v___x_1374_; 
v___x_1373_ = lean_unsigned_to_nat(69u);
v___x_1374_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1373_);
return v___x_1374_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1(void){
_start:
{
lean_object* v___x_1375_; lean_object* v___x_1376_; 
v___x_1375_ = lean_unsigned_to_nat(100u);
v___x_1376_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1375_);
return v___x_1376_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2(void){
_start:
{
lean_object* v___x_1377_; lean_object* v___x_1378_; lean_object* v___x_1379_; 
v___x_1377_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1378_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0);
v___x_1379_ = l_Rat_div(v___x_1378_, v___x_1377_);
return v___x_1379_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3(void){
_start:
{
lean_object* v___x_1380_; lean_object* v___x_1381_; 
v___x_1380_ = lean_unsigned_to_nat(21u);
v___x_1381_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1380_);
return v___x_1381_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4(void){
_start:
{
lean_object* v___x_1382_; lean_object* v___x_1383_; lean_object* v___x_1384_; 
v___x_1382_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1383_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3);
v___x_1384_ = l_Rat_div(v___x_1383_, v___x_1382_);
return v___x_1384_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3(lean_object* v_x_1385_){
_start:
{
lean_object* v___x_1386_; lean_object* v___x_1387_; lean_object* v___x_1388_; 
v___x_1386_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2);
v___x_1387_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4);
v___x_1388_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1385_, v___x_1386_, v___x_1387_);
return v___x_1388_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0(void){
_start:
{
lean_object* v___x_1389_; lean_object* v___x_1390_; 
v___x_1389_ = lean_unsigned_to_nat(298u);
v___x_1390_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1389_);
return v___x_1390_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1(void){
_start:
{
lean_object* v___x_1391_; lean_object* v___x_1392_; 
v___x_1391_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0);
v___x_1392_ = l_Rat_neg(v___x_1391_);
return v___x_1392_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2(void){
_start:
{
lean_object* v___x_1393_; lean_object* v___x_1394_; 
v___x_1393_ = lean_unsigned_to_nat(1669u);
v___x_1394_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1393_);
return v___x_1394_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5(lean_object* v_x_1395_){
_start:
{
lean_object* v___x_1396_; lean_object* v___x_1397_; lean_object* v___x_1398_; 
v___x_1396_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1);
v___x_1397_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2);
v___x_1398_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1395_, v___x_1396_, v___x_1397_);
return v___x_1398_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0(void){
_start:
{
lean_object* v___x_1399_; lean_object* v___x_1400_; 
v___x_1399_ = lean_unsigned_to_nat(418u);
v___x_1400_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1399_);
return v___x_1400_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1(void){
_start:
{
lean_object* v___x_1401_; lean_object* v___x_1402_; 
v___x_1401_ = lean_unsigned_to_nat(129u);
v___x_1402_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1401_);
return v___x_1402_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6(lean_object* v_x_1403_){
_start:
{
lean_object* v___x_1404_; lean_object* v___x_1405_; lean_object* v___x_1406_; 
v___x_1404_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0);
v___x_1405_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1);
v___x_1406_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1403_, v___x_1404_, v___x_1405_);
return v___x_1406_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0(void){
_start:
{
lean_object* v___x_1407_; lean_object* v___x_1408_; 
v___x_1407_ = lean_unsigned_to_nat(413u);
v___x_1408_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1407_);
return v___x_1408_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1(void){
_start:
{
lean_object* v___x_1409_; lean_object* v___x_1410_; 
v___x_1409_ = lean_unsigned_to_nat(120u);
v___x_1410_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1409_);
return v___x_1410_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7(lean_object* v_x_1411_){
_start:
{
lean_object* v___x_1412_; lean_object* v___x_1413_; lean_object* v___x_1414_; 
v___x_1412_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0);
v___x_1413_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1);
v___x_1414_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1411_, v___x_1412_, v___x_1413_);
return v___x_1414_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0(void){
_start:
{
lean_object* v___x_1415_; lean_object* v___x_1416_; 
v___x_1415_ = lean_unsigned_to_nat(70u);
v___x_1416_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1415_);
return v___x_1416_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1(void){
_start:
{
lean_object* v___x_1417_; lean_object* v___x_1418_; lean_object* v___x_1419_; 
v___x_1417_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1418_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0);
v___x_1419_ = l_Rat_div(v___x_1418_, v___x_1417_);
return v___x_1419_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8(lean_object* v_x_1420_){
_start:
{
lean_object* v___x_1421_; lean_object* v___x_1422_; lean_object* v___x_1423_; 
v___x_1421_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1422_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1);
v___x_1423_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1420_, v___x_1421_, v___x_1422_);
return v___x_1423_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__9(lean_object* v_x_1424_){
_start:
{
lean_object* v___x_1425_; lean_object* v___x_1426_; lean_object* v___x_1427_; 
v___x_1425_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1426_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1427_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1424_, v___x_1425_, v___x_1426_);
return v___x_1427_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0(void){
_start:
{
lean_object* v___x_1428_; lean_object* v___x_1429_; 
v___x_1428_ = lean_unsigned_to_nat(24688u);
v___x_1429_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1428_);
return v___x_1429_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1(void){
_start:
{
lean_object* v___x_1430_; lean_object* v___x_1431_; 
v___x_1430_ = lean_unsigned_to_nat(10844u);
v___x_1431_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1430_);
return v___x_1431_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10(lean_object* v_x_1432_){
_start:
{
lean_object* v___x_1433_; lean_object* v___x_1434_; lean_object* v___x_1435_; 
v___x_1433_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0);
v___x_1434_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1);
v___x_1435_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1432_, v___x_1433_, v___x_1434_);
return v___x_1435_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0(void){
_start:
{
lean_object* v___x_1436_; lean_object* v___x_1437_; 
v___x_1436_ = lean_unsigned_to_nat(10132u);
v___x_1437_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1436_);
return v___x_1437_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1(void){
_start:
{
lean_object* v___x_1438_; lean_object* v___x_1439_; lean_object* v___x_1440_; 
v___x_1438_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1439_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0);
v___x_1440_ = l_Rat_div(v___x_1439_, v___x_1438_);
return v___x_1440_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2(void){
_start:
{
lean_object* v___x_1441_; lean_object* v___x_1442_; 
v___x_1441_ = lean_unsigned_to_nat(54u);
v___x_1442_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1441_);
return v___x_1442_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3(void){
_start:
{
lean_object* v___x_1443_; lean_object* v___x_1444_; lean_object* v___x_1445_; 
v___x_1443_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1444_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2);
v___x_1445_ = l_Rat_div(v___x_1444_, v___x_1443_);
return v___x_1445_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11(lean_object* v_x_1446_){
_start:
{
lean_object* v___x_1447_; lean_object* v___x_1448_; lean_object* v___x_1449_; 
v___x_1447_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1);
v___x_1448_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3);
v___x_1449_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1446_, v___x_1447_, v___x_1448_);
return v___x_1449_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5(void){
_start:
{
lean_object* v___x_1455_; lean_object* v___x_1456_; 
v___x_1455_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3);
v___x_1456_ = l_Rat_neg(v___x_1455_);
return v___x_1456_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6(void){
_start:
{
lean_object* v___x_1457_; lean_object* v___x_1458_; 
v___x_1457_ = lean_unsigned_to_nat(990u);
v___x_1458_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1457_);
return v___x_1458_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7(void){
_start:
{
lean_object* v___x_1459_; lean_object* v___x_1460_; lean_object* v___x_1461_; 
v___x_1459_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1460_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6);
v___x_1461_ = l_Rat_div(v___x_1460_, v___x_1459_);
return v___x_1461_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms(lean_object* v_register_1479_, lean_object* v_word_1480_){
_start:
{
lean_object* v___x_1481_; uint8_t v___x_1482_; 
v___x_1481_ = lean_unsigned_to_nat(64u);
v___x_1482_ = lean_nat_dec_eq(v_register_1479_, v___x_1481_);
if (v___x_1482_ == 0)
{
lean_object* v___x_1483_; uint8_t v___x_1484_; 
v___x_1483_ = lean_unsigned_to_nat(80u);
v___x_1484_ = lean_nat_dec_eq(v_register_1479_, v___x_1483_);
if (v___x_1484_ == 0)
{
lean_object* v___x_1485_; uint8_t v___x_1486_; 
v___x_1485_ = lean_unsigned_to_nat(96u);
v___x_1486_ = lean_nat_dec_eq(v_register_1479_, v___x_1485_);
if (v___x_1486_ == 0)
{
lean_object* v___x_1487_; uint8_t v___x_1488_; 
v___x_1487_ = lean_unsigned_to_nat(68u);
v___x_1488_ = lean_nat_dec_eq(v_register_1479_, v___x_1487_);
if (v___x_1488_ == 0)
{
lean_object* v___x_1489_; uint8_t v___x_1490_; 
v___x_1489_ = lean_unsigned_to_nat(69u);
v___x_1490_ = lean_nat_dec_eq(v_register_1479_, v___x_1489_);
if (v___x_1490_ == 0)
{
lean_object* v___x_1491_; 
v___x_1491_ = lean_box(0);
return v___x_1491_;
}
else
{
lean_object* v___f_1492_; lean_object* v___f_1493_; lean_object* v___x_1494_; lean_object* v___x_1495_; lean_object* v___x_1496_; lean_object* v___x_1497_; lean_object* v___x_1498_; lean_object* v___x_1499_; lean_object* v___x_1500_; 
v___f_1492_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__0));
v___f_1493_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1));
v___x_1494_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__2));
v___x_1495_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1494_);
v___x_1496_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1495_, v___f_1492_);
v___x_1497_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__3));
v___x_1498_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1497_);
v___x_1499_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1498_, v___f_1493_);
v___x_1500_ = l_List_appendTR___redArg(v___x_1496_, v___x_1499_);
return v___x_1500_;
}
}
else
{
lean_object* v___f_1501_; lean_object* v___f_1502_; lean_object* v___x_1503_; lean_object* v___x_1504_; lean_object* v___x_1505_; lean_object* v___x_1506_; lean_object* v___x_1507_; lean_object* v___x_1508_; lean_object* v___x_1509_; lean_object* v___x_1510_; lean_object* v___x_1511_; lean_object* v___x_1512_; lean_object* v___x_1513_; lean_object* v___x_1514_; lean_object* v___x_1515_; lean_object* v___x_1516_; 
v___f_1501_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__4));
v___f_1502_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1));
v___x_1503_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_1480_);
v___x_1504_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5);
v___x_1505_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7);
v___x_1506_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1503_, v___x_1504_, v___x_1505_);
v___x_1507_ = lean_box(0);
v___x_1508_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1508_, 0, v___x_1506_);
lean_ctor_set(v___x_1508_, 1, v___x_1507_);
v___x_1509_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__8));
v___x_1510_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1509_);
v___x_1511_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1510_, v___f_1501_);
v___x_1512_ = l_List_appendTR___redArg(v___x_1508_, v___x_1511_);
v___x_1513_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__9));
v___x_1514_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1513_);
v___x_1515_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1514_, v___f_1502_);
v___x_1516_ = l_List_appendTR___redArg(v___x_1512_, v___x_1515_);
return v___x_1516_;
}
}
else
{
lean_object* v___f_1517_; lean_object* v___f_1518_; lean_object* v___f_1519_; lean_object* v___x_1520_; lean_object* v___x_1521_; lean_object* v___x_1522_; lean_object* v___y_1524_; lean_object* v___x_1531_; lean_object* v___x_1532_; 
v___f_1517_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__10));
v___f_1518_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__11));
v___f_1519_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__12));
v___x_1520_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13));
v___x_1521_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1520_);
v___x_1522_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1521_, v___f_1517_);
v___x_1531_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14));
v___x_1532_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1531_);
if (lean_obj_tag(v___x_1532_) == 0)
{
v___y_1524_ = v___x_1532_;
goto v___jp_1523_;
}
else
{
lean_object* v___x_1534_; uint8_t v_isShared_1535_; uint8_t v_isSharedCheck_1540_; 
v_isSharedCheck_1540_ = !lean_is_exclusive(v___x_1532_);
if (v_isSharedCheck_1540_ == 0)
{
lean_object* v_unused_1541_; 
v_unused_1541_ = lean_ctor_get(v___x_1532_, 0);
lean_dec(v_unused_1541_);
v___x_1534_ = v___x_1532_;
v_isShared_1535_ = v_isSharedCheck_1540_;
goto v_resetjp_1533_;
}
else
{
lean_dec(v___x_1532_);
v___x_1534_ = lean_box(0);
v_isShared_1535_ = v_isSharedCheck_1540_;
goto v_resetjp_1533_;
}
v_resetjp_1533_:
{
lean_object* v___x_1536_; lean_object* v___x_1538_; 
v___x_1536_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_1480_);
if (v_isShared_1535_ == 0)
{
lean_ctor_set(v___x_1534_, 0, v___x_1536_);
v___x_1538_ = v___x_1534_;
goto v_reusejp_1537_;
}
else
{
lean_object* v_reuseFailAlloc_1539_; 
v_reuseFailAlloc_1539_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1539_, 0, v___x_1536_);
v___x_1538_ = v_reuseFailAlloc_1539_;
goto v_reusejp_1537_;
}
v_reusejp_1537_:
{
v___y_1524_ = v___x_1538_;
goto v___jp_1523_;
}
}
}
v___jp_1523_:
{
lean_object* v___x_1525_; lean_object* v___x_1526_; lean_object* v___x_1527_; lean_object* v___x_1528_; lean_object* v___x_1529_; lean_object* v___x_1530_; 
v___x_1525_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___y_1524_, v___f_1518_);
v___x_1526_ = l_List_appendTR___redArg(v___x_1522_, v___x_1525_);
v___x_1527_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__2));
v___x_1528_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1527_);
v___x_1529_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1528_, v___f_1519_);
v___x_1530_ = l_List_appendTR___redArg(v___x_1526_, v___x_1529_);
return v___x_1530_;
}
}
}
else
{
lean_object* v___f_1542_; lean_object* v___f_1543_; lean_object* v___f_1544_; lean_object* v___f_1545_; lean_object* v___x_1546_; lean_object* v___x_1547_; lean_object* v___x_1548_; lean_object* v___x_1549_; lean_object* v___x_1550_; lean_object* v___x_1551_; lean_object* v___x_1552_; lean_object* v___x_1553_; lean_object* v___x_1554_; lean_object* v___x_1555_; lean_object* v___x_1556_; lean_object* v___x_1557_; lean_object* v___x_1558_; lean_object* v___x_1559_; lean_object* v___x_1560_; 
v___f_1542_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__15));
v___f_1543_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__16));
v___f_1544_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__17));
v___f_1545_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__18));
v___x_1546_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19));
v___x_1547_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1546_);
v___x_1548_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1547_, v___f_1545_);
v___x_1549_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__4));
v___x_1550_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1549_);
v___x_1551_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1550_, v___f_1544_);
v___x_1552_ = l_List_appendTR___redArg(v___x_1548_, v___x_1551_);
v___x_1553_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__20));
v___x_1554_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1553_);
v___x_1555_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1554_, v___f_1543_);
v___x_1556_ = l_List_appendTR___redArg(v___x_1552_, v___x_1555_);
v___x_1557_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__21));
v___x_1558_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1557_);
v___x_1559_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1558_, v___f_1542_);
v___x_1560_ = l_List_appendTR___redArg(v___x_1556_, v___x_1559_);
return v___x_1560_;
}
}
else
{
lean_object* v___f_1561_; lean_object* v___f_1562_; lean_object* v___y_1564_; lean_object* v___x_1574_; lean_object* v___x_1575_; 
v___f_1561_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__22));
v___f_1562_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__23));
v___x_1574_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__24));
v___x_1575_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1574_);
if (lean_obj_tag(v___x_1575_) == 0)
{
v___y_1564_ = v___x_1575_;
goto v___jp_1563_;
}
else
{
lean_object* v___x_1577_; uint8_t v_isShared_1578_; uint8_t v_isSharedCheck_1583_; 
v_isSharedCheck_1583_ = !lean_is_exclusive(v___x_1575_);
if (v_isSharedCheck_1583_ == 0)
{
lean_object* v_unused_1584_; 
v_unused_1584_ = lean_ctor_get(v___x_1575_, 0);
lean_dec(v_unused_1584_);
v___x_1577_ = v___x_1575_;
v_isShared_1578_ = v_isSharedCheck_1583_;
goto v_resetjp_1576_;
}
else
{
lean_dec(v___x_1575_);
v___x_1577_ = lean_box(0);
v_isShared_1578_ = v_isSharedCheck_1583_;
goto v_resetjp_1576_;
}
v_resetjp_1576_:
{
lean_object* v___x_1579_; lean_object* v___x_1581_; 
v___x_1579_ = lp_lean1090_Lean1090_Impl_cbQNH64(v_word_1480_);
if (v_isShared_1578_ == 0)
{
lean_ctor_set(v___x_1577_, 0, v___x_1579_);
v___x_1581_ = v___x_1577_;
goto v_reusejp_1580_;
}
else
{
lean_object* v_reuseFailAlloc_1582_; 
v_reuseFailAlloc_1582_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1582_, 0, v___x_1579_);
v___x_1581_ = v_reuseFailAlloc_1582_;
goto v_reusejp_1580_;
}
v_reusejp_1580_:
{
v___y_1564_ = v___x_1581_;
goto v___jp_1563_;
}
}
}
v___jp_1563_:
{
lean_object* v___x_1565_; lean_object* v___x_1566_; lean_object* v___x_1567_; lean_object* v___x_1568_; lean_object* v___x_1569_; lean_object* v___x_1570_; lean_object* v___x_1571_; lean_object* v___x_1572_; lean_object* v___x_1573_; 
v___x_1565_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___y_1564_, v___f_1562_);
v___x_1566_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__6));
v___x_1567_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1566_);
v___x_1568_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1567_, v___f_1561_);
v___x_1569_ = l_List_appendTR___redArg(v___x_1565_, v___x_1568_);
v___x_1570_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__7));
v___x_1571_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1479_, v_word_1480_, v___x_1570_);
v___x_1572_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1571_, v___f_1561_);
v___x_1573_ = l_List_appendTR___redArg(v___x_1569_, v___x_1572_);
return v___x_1573_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___boxed(lean_object* v_register_1585_, lean_object* v_word_1586_){
_start:
{
lean_object* v_res_1587_; 
v_res_1587_ = lp_lean1090_Lean1090_Impl_cbDensityTerms(v_register_1585_, v_word_1586_);
lean_dec(v_word_1586_);
lean_dec(v_register_1585_);
return v_res_1587_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_cbDensity_spec__0(lean_object* v_x_1588_, lean_object* v_x_1589_){
_start:
{
if (lean_obj_tag(v_x_1589_) == 0)
{
return v_x_1588_;
}
else
{
lean_object* v_head_1590_; lean_object* v_tail_1591_; lean_object* v___x_1592_; 
v_head_1590_ = lean_ctor_get(v_x_1589_, 0);
lean_inc(v_head_1590_);
v_tail_1591_ = lean_ctor_get(v_x_1589_, 1);
lean_inc(v_tail_1591_);
lean_dec_ref_known(v_x_1589_, 2);
v___x_1592_ = lp_lean1090_Lean1090_Impl_Binary64_add(v_x_1588_, v_head_1590_);
v_x_1588_ = v___x_1592_;
v_x_1589_ = v_tail_1591_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensity(lean_object* v_register_1594_, lean_object* v_word_1595_){
_start:
{
lean_object* v_terms_1596_; uint8_t v___x_1597_; 
v_terms_1596_ = lp_lean1090_Lean1090_Impl_cbDensityTerms(v_register_1594_, v_word_1595_);
v___x_1597_ = l_List_isEmpty___redArg(v_terms_1596_);
if (v___x_1597_ == 0)
{
lean_object* v___x_1598_; lean_object* v___x_1599_; lean_object* v___x_1600_; lean_object* v___x_1601_; lean_object* v___x_1602_; 
v___x_1598_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc(v_terms_1596_);
v___x_1599_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_cbDensity_spec__0(v___x_1598_, v_terms_1596_);
v___x_1600_ = l_List_lengthTR___redArg(v_terms_1596_);
lean_dec(v_terms_1596_);
v___x_1601_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1600_);
v___x_1602_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1599_, v___x_1601_);
lean_dec_ref(v___x_1599_);
return v___x_1602_;
}
else
{
lean_object* v___x_1603_; 
lean_dec(v_terms_1596_);
v___x_1603_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1603_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensity___boxed(lean_object* v_register_1604_, lean_object* v_word_1605_){
_start:
{
lean_object* v_res_1606_; 
v_res_1606_ = lp_lean1090_Lean1090_Impl_cbDensity(v_register_1604_, v_word_1605_);
lean_dec(v_word_1605_);
lean_dec(v_register_1604_);
return v_res_1606_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1607_; lean_object* v___x_1608_; 
v___x_1607_ = lean_unsigned_to_nat(1023u);
v___x_1608_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1607_);
return v___x_1608_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0(lean_object* v_code_1609_){
_start:
{
lean_object* v___x_1610_; lean_object* v___x_1611_; lean_object* v___x_1612_; lean_object* v___x_1613_; lean_object* v___x_1614_; lean_object* v___x_1615_; lean_object* v___x_1616_; lean_object* v___x_1617_; lean_object* v___x_1618_; lean_object* v___x_1619_; lean_object* v___x_1620_; 
v___x_1610_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1611_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1612_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1609_);
v___x_1613_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0);
v___x_1614_ = l_Rat_sub(v___x_1612_, v___x_1613_);
v___x_1615_ = l_Rat_mul(v___x_1611_, v___x_1614_);
v___x_1616_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_1615_);
v___x_1617_ = l_Rat_abs(v___x_1616_);
v___x_1618_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1619_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1617_, v___x_1618_);
lean_dec_ref(v___x_1617_);
v___x_1620_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v___x_1610_, v___x_1619_);
return v___x_1620_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1(void){
_start:
{
lean_object* v___f_1622_; lean_object* v___x_1623_; lean_object* v___x_1624_; 
v___f_1622_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__0));
v___x_1623_ = lean_unsigned_to_nat(2047u);
v___x_1624_ = l_Array_ofFn___redArg(v___x_1623_, v___f_1622_);
return v___x_1624_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable(void){
_start:
{
lean_object* v___x_1625_; 
v___x_1625_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1, &lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1);
return v___x_1625_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenalty50(lean_object* v_word_1626_){
_start:
{
lean_object* v___x_1627_; lean_object* v___x_1628_; lean_object* v___x_1629_; lean_object* v___x_1630_; uint8_t v___x_1631_; 
v___x_1627_ = lean_unsigned_to_nat(46u);
v___x_1628_ = lean_unsigned_to_nat(1u);
v___x_1629_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1626_, v___x_1627_, v___x_1628_);
v___x_1630_ = lean_unsigned_to_nat(0u);
v___x_1631_ = lean_nat_dec_eq(v___x_1629_, v___x_1630_);
lean_dec(v___x_1629_);
if (v___x_1631_ == 0)
{
lean_object* v___x_1632_; lean_object* v___x_1633_; uint8_t v___x_1634_; 
v___x_1632_ = lean_unsigned_to_nat(24u);
v___x_1633_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1626_, v___x_1632_, v___x_1628_);
v___x_1634_ = lean_nat_dec_eq(v___x_1633_, v___x_1630_);
lean_dec(v___x_1633_);
if (v___x_1634_ == 0)
{
lean_object* v___x_1635_; lean_object* v___x_1636_; lean_object* v_tas_1637_; lean_object* v___x_1638_; lean_object* v_gs_1639_; lean_object* v___x_1640_; lean_object* v___x_1641_; lean_object* v___x_1642_; lean_object* v___x_1643_; lean_object* v___x_1644_; 
v___x_1635_ = lean_unsigned_to_nat(47u);
v___x_1636_ = lean_unsigned_to_nat(10u);
v_tas_1637_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1626_, v___x_1635_, v___x_1636_);
v___x_1638_ = lean_unsigned_to_nat(25u);
v_gs_1639_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1626_, v___x_1638_, v___x_1636_);
v___x_1640_ = lp_lean1090_Lean1090_Impl_cbWindPenaltyTable;
v___x_1641_ = lean_unsigned_to_nat(1023u);
v___x_1642_ = lean_nat_add(v_tas_1637_, v___x_1641_);
lean_dec(v_tas_1637_);
v___x_1643_ = lean_nat_sub(v___x_1642_, v_gs_1639_);
lean_dec(v_gs_1639_);
lean_dec(v___x_1642_);
v___x_1644_ = lean_array_fget_borrowed(v___x_1640_, v___x_1643_);
lean_dec(v___x_1643_);
lean_inc(v___x_1644_);
return v___x_1644_;
}
else
{
lean_object* v___x_1645_; 
v___x_1645_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1645_;
}
}
else
{
lean_object* v___x_1646_; 
v___x_1646_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1646_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenalty50___boxed(lean_object* v_word_1647_){
_start:
{
lean_object* v_res_1648_; 
v_res_1648_ = lp_lean1090_Lean1090_Impl_cbWindPenalty50(v_word_1647_);
lean_dec(v_word_1647_);
return v_res_1648_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0(void){
_start:
{
lean_object* v___x_1649_; lean_object* v_k_1650_; 
v___x_1649_ = lean_cstr_to_nat("2251799813685248");
v_k_1650_ = lean_nat_to_int(v___x_1649_);
return v_k_1650_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__1(void){
_start:
{
lean_object* v___x_1651_; lean_object* v___x_1652_; 
v___x_1651_ = lean_unsigned_to_nat(250u);
v___x_1652_ = lean_nat_to_int(v___x_1651_);
return v___x_1652_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__2(void){
_start:
{
lean_object* v_k_1653_; lean_object* v___x_1654_; lean_object* v___x_1655_; 
v_k_1653_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0);
v___x_1654_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__1, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__1);
v___x_1655_ = lean_int_mul(v___x_1654_, v_k_1653_);
return v___x_1655_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__3(void){
_start:
{
lean_object* v___x_1656_; lean_object* v___x_1657_; 
v___x_1656_ = lean_unsigned_to_nat(250u);
v___x_1657_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1656_);
return v___x_1657_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__4(void){
_start:
{
lean_object* v___x_1658_; lean_object* v___x_1659_; 
v___x_1658_ = lean_unsigned_to_nat(800u);
v___x_1659_ = lean_nat_to_int(v___x_1658_);
return v___x_1659_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__5(void){
_start:
{
lean_object* v_k_1660_; lean_object* v___x_1661_; lean_object* v___x_1662_; 
v_k_1660_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0);
v___x_1661_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__4, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__4);
v___x_1662_ = lean_int_mul(v___x_1661_, v_k_1660_);
return v___x_1662_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbRatioOutside250800(lean_object* v_q_1663_){
_start:
{
lean_object* v_num_1664_; lean_object* v_den_1665_; lean_object* v_d_1666_; lean_object* v_k_1667_; lean_object* v___x_1668_; lean_object* v___x_1669_; lean_object* v_e_1670_; lean_object* v_c_1671_; lean_object* v___x_1672_; lean_object* v_lower_1673_; lean_object* v___x_1674_; uint8_t v___x_1675_; 
v_num_1664_ = lean_ctor_get(v_q_1663_, 0);
v_den_1665_ = lean_ctor_get(v_q_1663_, 1);
lean_inc(v_den_1665_);
v_d_1666_ = lean_nat_to_int(v_den_1665_);
v_k_1667_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0);
v___x_1668_ = lean_nat_abs(v_num_1664_);
v___x_1669_ = lean_nat_to_int(v___x_1668_);
v_e_1670_ = lean_int_add(v___x_1669_, v_d_1666_);
lean_dec(v___x_1669_);
v_c_1671_ = lean_int_mul(v_k_1667_, v_num_1664_);
v___x_1672_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__2, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__2);
v_lower_1673_ = lean_int_mul(v___x_1672_, v_d_1666_);
v___x_1674_ = lean_int_add(v_c_1671_, v_e_1670_);
v___x_1675_ = lean_int_dec_lt(v___x_1674_, v_lower_1673_);
if (v___x_1675_ == 0)
{
lean_object* v___x_1682_; lean_object* v_upper_1683_; lean_object* v___x_1684_; uint8_t v___x_1685_; 
v___x_1682_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__5, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__5);
v_upper_1683_ = lean_int_mul(v___x_1682_, v_d_1666_);
lean_dec(v_d_1666_);
v___x_1684_ = lean_int_sub(v_c_1671_, v_e_1670_);
lean_dec(v_e_1670_);
lean_dec(v_c_1671_);
v___x_1685_ = lean_int_dec_lt(v_upper_1683_, v___x_1684_);
if (v___x_1685_ == 0)
{
uint8_t v___x_1686_; 
v___x_1686_ = lean_int_dec_le(v_lower_1673_, v___x_1684_);
lean_dec(v___x_1684_);
lean_dec(v_lower_1673_);
if (v___x_1686_ == 0)
{
lean_dec(v_upper_1683_);
lean_dec(v___x_1674_);
goto v___jp_1676_;
}
else
{
uint8_t v___x_1687_; 
v___x_1687_ = lean_int_dec_le(v___x_1674_, v_upper_1683_);
lean_dec(v_upper_1683_);
lean_dec(v___x_1674_);
if (v___x_1687_ == 0)
{
goto v___jp_1676_;
}
else
{
lean_dec_ref(v_q_1663_);
return v___x_1685_;
}
}
}
else
{
lean_dec(v___x_1684_);
lean_dec(v_upper_1683_);
lean_dec(v___x_1674_);
lean_dec(v_lower_1673_);
lean_dec_ref(v_q_1663_);
return v___x_1685_;
}
v___jp_1676_:
{
lean_object* v_rounded_1677_; lean_object* v___x_1678_; uint8_t v___x_1679_; 
v_rounded_1677_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_q_1663_);
v___x_1678_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__3, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__3);
lean_inc_ref(v_rounded_1677_);
v___x_1679_ = l_Rat_blt(v_rounded_1677_, v___x_1678_);
if (v___x_1679_ == 0)
{
lean_object* v___x_1680_; uint8_t v___x_1681_; 
v___x_1680_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4);
v___x_1681_ = l_Rat_blt(v___x_1680_, v_rounded_1677_);
return v___x_1681_;
}
else
{
lean_dec_ref(v_rounded_1677_);
return v___x_1679_;
}
}
}
else
{
lean_dec(v___x_1674_);
lean_dec(v_lower_1673_);
lean_dec(v_c_1671_);
lean_dec(v_e_1670_);
lean_dec(v_d_1666_);
lean_dec_ref(v_q_1663_);
return v___x_1675_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRatioOutside250800___boxed(lean_object* v_q_1688_){
_start:
{
uint8_t v_res_1689_; lean_object* v_r_1690_; 
v_res_1689_ = lp_lean1090_Lean1090_Impl_cbRatioOutside250800(v_q_1688_);
v_r_1690_ = lean_box(v_res_1689_);
return v_r_1690_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0(void){
_start:
{
lean_object* v___x_1691_; lean_object* v___x_1692_; 
v___x_1691_ = lean_unsigned_to_nat(3u);
v___x_1692_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1691_);
return v___x_1692_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1(void){
_start:
{
lean_object* v___x_1693_; lean_object* v___x_1694_; 
v___x_1693_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__0, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0);
v___x_1694_ = l_Rat_neg(v___x_1693_);
return v___x_1694_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__2(void){
_start:
{
lean_object* v___x_1695_; lean_object* v___x_1696_; 
v___x_1695_ = lean_unsigned_to_nat(5u);
v___x_1696_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1695_);
return v___x_1696_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__3(void){
_start:
{
lean_object* v___x_1697_; lean_object* v___x_1698_; lean_object* v___x_1699_; 
v___x_1697_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1698_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__0, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0);
v___x_1699_ = l_Rat_div(v___x_1698_, v___x_1697_);
return v___x_1699_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__4(void){
_start:
{
lean_object* v___x_1700_; lean_object* v___x_1701_; 
v___x_1700_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__3, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__3);
v___x_1701_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_1700_);
return v___x_1701_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPenalty(lean_object* v_register_1702_, lean_object* v_word_1703_){
_start:
{
lean_object* v___x_1706_; uint8_t v___x_1707_; 
v___x_1706_ = lean_unsigned_to_nat(80u);
v___x_1707_ = lean_nat_dec_eq(v_register_1702_, v___x_1706_);
if (v___x_1707_ == 0)
{
lean_object* v___x_1708_; uint8_t v___x_1709_; 
v___x_1708_ = lean_unsigned_to_nat(96u);
v___x_1709_ = lean_nat_dec_eq(v_register_1702_, v___x_1708_);
if (v___x_1709_ == 0)
{
lean_object* v___x_1710_; 
v___x_1710_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1710_;
}
else
{
lean_object* v___x_1711_; lean_object* v___x_1712_; 
v___x_1711_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13));
v___x_1712_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1702_, v_word_1703_, v___x_1711_);
if (lean_obj_tag(v___x_1712_) == 1)
{
lean_object* v_val_1713_; lean_object* v___x_1714_; lean_object* v___x_1715_; 
v_val_1713_ = lean_ctor_get(v___x_1712_, 0);
lean_inc(v_val_1713_);
lean_dec_ref_known(v___x_1712_, 1);
v___x_1714_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14));
v___x_1715_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1702_, v_word_1703_, v___x_1714_);
if (lean_obj_tag(v___x_1715_) == 1)
{
lean_object* v_mach_1716_; lean_object* v___x_1717_; uint8_t v___y_1719_; uint8_t v___x_1721_; 
lean_dec_ref_known(v___x_1715_, 1);
v_mach_1716_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_1703_);
v___x_1717_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_mach_1716_);
v___x_1721_ = l_Rat_blt(v___x_1717_, v_mach_1716_);
if (v___x_1721_ == 0)
{
lean_dec_ref(v_mach_1716_);
lean_dec(v_val_1713_);
return v___x_1717_;
}
else
{
if (v___x_1721_ == 0)
{
lean_dec_ref(v_mach_1716_);
lean_dec(v_val_1713_);
v___y_1719_ = v___x_1721_;
goto v___jp_1718_;
}
else
{
lean_object* v___x_1722_; uint8_t v___x_1723_; 
v___x_1722_ = l_Rat_div(v_val_1713_, v_mach_1716_);
lean_dec(v_val_1713_);
v___x_1723_ = lp_lean1090_Lean1090_Impl_cbRatioOutside250800(v___x_1722_);
v___y_1719_ = v___x_1723_;
goto v___jp_1718_;
}
}
v___jp_1718_:
{
if (v___y_1719_ == 0)
{
return v___x_1717_;
}
else
{
lean_object* v___x_1720_; 
v___x_1720_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__1, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1);
return v___x_1720_;
}
}
}
else
{
lean_dec(v___x_1715_);
lean_dec(v_val_1713_);
goto v___jp_1704_;
}
}
else
{
lean_dec(v___x_1712_);
goto v___jp_1704_;
}
}
}
else
{
lean_object* v_p_1724_; uint8_t v___y_1726_; lean_object* v___x_1729_; lean_object* v___x_1730_; 
v_p_1724_ = lp_lean1090_Lean1090_Impl_cbWindPenalty50(v_word_1703_);
v___x_1729_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19));
v___x_1730_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1702_, v_word_1703_, v___x_1729_);
if (lean_obj_tag(v___x_1730_) == 1)
{
lean_object* v_val_1731_; lean_object* v___x_1732_; lean_object* v___x_1733_; 
v_val_1731_ = lean_ctor_get(v___x_1730_, 0);
lean_inc(v_val_1731_);
lean_dec_ref_known(v___x_1730_, 1);
v___x_1732_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__4));
v___x_1733_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1702_, v_word_1703_, v___x_1732_);
if (lean_obj_tag(v___x_1733_) == 1)
{
lean_object* v_val_1734_; uint8_t v___y_1736_; lean_object* v___x_1740_; lean_object* v___x_1741_; uint8_t v___x_1742_; 
v_val_1734_ = lean_ctor_get(v___x_1733_, 0);
lean_inc(v_val_1734_);
lean_dec_ref_known(v___x_1733_, 1);
v___x_1740_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__2, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__2);
lean_inc(v_val_1731_);
v___x_1741_ = l_Rat_abs(v_val_1731_);
v___x_1742_ = l_Rat_blt(v___x_1740_, v___x_1741_);
if (v___x_1742_ == 0)
{
v___y_1736_ = v___x_1742_;
goto v___jp_1735_;
}
else
{
lean_object* v___x_1743_; lean_object* v___x_1744_; uint8_t v___x_1745_; 
v___x_1743_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__4, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__4);
lean_inc(v_val_1734_);
v___x_1744_ = l_Rat_abs(v_val_1734_);
v___x_1745_ = l_Rat_blt(v___x_1743_, v___x_1744_);
v___y_1736_ = v___x_1745_;
goto v___jp_1735_;
}
v___jp_1735_:
{
if (v___y_1736_ == 0)
{
lean_dec(v_val_1734_);
lean_dec(v_val_1731_);
return v_p_1724_;
}
else
{
lean_object* v___x_1737_; uint8_t v___x_1738_; uint8_t v___x_1739_; 
v___x_1737_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1738_ = l_Rat_blt(v___x_1737_, v_val_1731_);
v___x_1739_ = l_Rat_blt(v___x_1737_, v_val_1734_);
if (v___x_1739_ == 0)
{
if (v___x_1738_ == 0)
{
return v_p_1724_;
}
else
{
v___y_1726_ = v___x_1739_;
goto v___jp_1725_;
}
}
else
{
v___y_1726_ = v___x_1738_;
goto v___jp_1725_;
}
}
}
}
else
{
lean_dec(v___x_1733_);
lean_dec(v_val_1731_);
return v_p_1724_;
}
}
else
{
lean_dec(v___x_1730_);
return v_p_1724_;
}
v___jp_1725_:
{
if (v___y_1726_ == 0)
{
lean_object* v___x_1727_; lean_object* v___x_1728_; 
v___x_1727_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1728_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_p_1724_, v___x_1727_);
return v___x_1728_;
}
else
{
return v_p_1724_;
}
}
}
v___jp_1704_:
{
lean_object* v___x_1705_; 
v___x_1705_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1705_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPenalty___boxed(lean_object* v_register_1746_, lean_object* v_word_1747_){
_start:
{
lean_object* v_res_1748_; 
v_res_1748_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_1746_, v_word_1747_);
lean_dec(v_word_1747_);
lean_dec(v_register_1746_);
return v_res_1748_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCombinedScore(lean_object* v_register_1749_, lean_object* v_word_1750_){
_start:
{
lean_object* v___x_1751_; lean_object* v___x_1752_; lean_object* v___x_1753_; 
v___x_1751_ = lp_lean1090_Lean1090_Impl_cbDensity(v_register_1749_, v_word_1750_);
v___x_1752_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_1749_, v_word_1750_);
v___x_1753_ = lp_lean1090_Lean1090_Impl_Binary64_add(v___x_1751_, v___x_1752_);
return v___x_1753_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCombinedScore___boxed(lean_object* v_register_1754_, lean_object* v_word_1755_){
_start:
{
lean_object* v_res_1756_; 
v_res_1756_ = lp_lean1090_Lean1090_Impl_cbCombinedScore(v_register_1754_, v_word_1755_);
lean_dec(v_word_1755_);
lean_dec(v_register_1754_);
return v_res_1756_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHScoreTable___lam__0(lean_object* v_code_1757_){
_start:
{
lean_object* v___x_1758_; lean_object* v___x_1759_; lean_object* v___x_1760_; lean_object* v___x_1761_; lean_object* v___x_1762_; lean_object* v___x_1763_; lean_object* v___x_1764_; lean_object* v___x_1765_; 
v___x_1758_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1757_);
v___x_1759_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3);
v___x_1760_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1758_, v___x_1759_);
lean_dec_ref(v___x_1758_);
v___x_1761_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4);
v___x_1762_ = lp_lean1090_Lean1090_Impl_Binary64_add(v___x_1760_, v___x_1761_);
v___x_1763_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1);
v___x_1764_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3);
v___x_1765_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1762_, v___x_1763_, v___x_1764_);
return v___x_1765_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1767_; lean_object* v___x_1768_; lean_object* v___x_1769_; 
v___f_1767_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__0));
v___x_1768_ = lean_unsigned_to_nat(4096u);
v___x_1769_ = l_Array_ofFn___redArg(v___x_1768_, v___f_1767_);
return v___x_1769_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable(void){
_start:
{
lean_object* v___x_1770_; 
v___x_1770_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1);
return v___x_1770_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0(lean_object* v_code_1771_){
_start:
{
lean_object* v___x_1772_; lean_object* v___x_1773_; lean_object* v___x_1774_; lean_object* v___x_1775_; 
v___x_1772_ = lp_lean1090_Lean1090_Impl_cbSelected(v_code_1771_);
v___x_1773_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0);
v___x_1774_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1);
v___x_1775_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1772_, v___x_1773_, v___x_1774_);
return v___x_1775_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0___boxed(lean_object* v_code_1776_){
_start:
{
lean_object* v_res_1777_; 
v_res_1777_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0(v_code_1776_);
lean_dec(v_code_1776_);
return v_res_1777_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1779_; lean_object* v___x_1780_; lean_object* v___x_1781_; 
v___f_1779_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__0));
v___x_1780_ = lean_unsigned_to_nat(4096u);
v___x_1781_ = l_Array_ofFn___redArg(v___x_1780_, v___f_1779_);
return v___x_1781_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable(void){
_start:
{
lean_object* v___x_1782_; 
v___x_1782_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1);
return v___x_1782_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1783_; lean_object* v___x_1784_; lean_object* v___x_1785_; 
v___x_1783_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1784_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0);
v___x_1785_ = l_Rat_div(v___x_1784_, v___x_1783_);
return v___x_1785_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0(lean_object* v_code_1786_){
_start:
{
uint8_t v___x_1787_; lean_object* v___x_1788_; lean_object* v___x_1789_; lean_object* v___x_1790_; lean_object* v___x_1791_; lean_object* v___x_1792_; lean_object* v___x_1793_; lean_object* v___x_1794_; lean_object* v___x_1795_; 
v___x_1787_ = 1;
v___x_1788_ = lean_unsigned_to_nat(10u);
v___x_1789_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1787_, v___x_1788_, v_code_1786_);
v___x_1790_ = l_Rat_ofInt(v___x_1789_);
v___x_1791_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0);
v___x_1792_ = l_Rat_mul(v___x_1790_, v___x_1791_);
lean_dec_ref(v___x_1790_);
v___x_1793_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1794_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1795_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1792_, v___x_1793_, v___x_1794_);
return v___x_1795_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1797_; lean_object* v___x_1798_; lean_object* v___x_1799_; 
v___f_1797_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__0));
v___x_1798_ = lean_unsigned_to_nat(1024u);
v___x_1799_ = l_Array_ofFn___redArg(v___x_1798_, v___f_1797_);
return v___x_1799_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable(void){
_start:
{
lean_object* v___x_1800_; 
v___x_1800_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1);
return v___x_1800_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1801_; lean_object* v___x_1802_; 
v___x_1801_ = lean_unsigned_to_nat(8u);
v___x_1802_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1801_);
return v___x_1802_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1(void){
_start:
{
lean_object* v___x_1803_; lean_object* v___x_1804_; lean_object* v___x_1805_; 
v___x_1803_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1804_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0);
v___x_1805_ = l_Rat_div(v___x_1804_, v___x_1803_);
return v___x_1805_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0(lean_object* v_code_1806_){
_start:
{
uint8_t v___x_1807_; lean_object* v___x_1808_; lean_object* v___x_1809_; lean_object* v___x_1810_; lean_object* v___x_1811_; lean_object* v___x_1812_; lean_object* v___x_1813_; lean_object* v___x_1814_; lean_object* v___x_1815_; 
v___x_1807_ = 1;
v___x_1808_ = lean_unsigned_to_nat(10u);
v___x_1809_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1807_, v___x_1808_, v_code_1806_);
v___x_1810_ = l_Rat_ofInt(v___x_1809_);
v___x_1811_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1);
v___x_1812_ = l_Rat_mul(v___x_1810_, v___x_1811_);
lean_dec_ref(v___x_1810_);
v___x_1813_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1814_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1);
v___x_1815_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1812_, v___x_1813_, v___x_1814_);
return v___x_1815_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1817_; lean_object* v___x_1818_; lean_object* v___x_1819_; 
v___f_1817_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__0));
v___x_1818_ = lean_unsigned_to_nat(1024u);
v___x_1819_ = l_Array_ofFn___redArg(v___x_1818_, v___f_1817_);
return v___x_1819_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable(void){
_start:
{
lean_object* v___x_1820_; 
v___x_1820_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1);
return v___x_1820_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTASScoreTable___lam__0(lean_object* v_code_1821_){
_start:
{
lean_object* v___x_1822_; lean_object* v___x_1823_; lean_object* v___x_1824_; lean_object* v___x_1825_; lean_object* v___x_1826_; lean_object* v___x_1827_; 
v___x_1822_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1821_);
v___x_1823_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1824_ = l_Rat_mul(v___x_1822_, v___x_1823_);
lean_dec_ref(v___x_1822_);
v___x_1825_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0);
v___x_1826_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1);
v___x_1827_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1824_, v___x_1825_, v___x_1826_);
return v___x_1827_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1829_; lean_object* v___x_1830_; lean_object* v___x_1831_; 
v___f_1829_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__0));
v___x_1830_ = lean_unsigned_to_nat(1024u);
v___x_1831_ = l_Array_ofFn___redArg(v___x_1830_, v___f_1829_);
return v___x_1831_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable(void){
_start:
{
lean_object* v___x_1832_; 
v___x_1832_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1);
return v___x_1832_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___lam__0(lean_object* v_code_1833_){
_start:
{
lean_object* v___x_1834_; lean_object* v___x_1835_; lean_object* v___x_1836_; lean_object* v___x_1837_; lean_object* v___x_1838_; lean_object* v___x_1839_; 
v___x_1834_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1833_);
v___x_1835_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1836_ = l_Rat_mul(v___x_1834_, v___x_1835_);
lean_dec_ref(v___x_1834_);
v___x_1837_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0);
v___x_1838_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1);
v___x_1839_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1836_, v___x_1837_, v___x_1838_);
return v___x_1839_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1841_; lean_object* v___x_1842_; lean_object* v___x_1843_; 
v___f_1841_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__0));
v___x_1842_ = lean_unsigned_to_nat(1024u);
v___x_1843_ = l_Array_ofFn___redArg(v___x_1842_, v___f_1841_);
return v___x_1843_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable(void){
_start:
{
lean_object* v___x_1844_; 
v___x_1844_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1);
return v___x_1844_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbIASScoreTable___lam__0(lean_object* v_code_1845_){
_start:
{
lean_object* v___x_1846_; lean_object* v___x_1847_; lean_object* v___x_1848_; lean_object* v___x_1849_; 
v___x_1846_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1845_);
v___x_1847_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0);
v___x_1848_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1);
v___x_1849_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1846_, v___x_1847_, v___x_1848_);
return v___x_1849_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1851_; lean_object* v___x_1852_; lean_object* v___x_1853_; 
v___f_1851_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__0));
v___x_1852_ = lean_unsigned_to_nat(1024u);
v___x_1853_ = l_Array_ofFn___redArg(v___x_1852_, v___f_1851_);
return v___x_1853_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable(void){
_start:
{
lean_object* v___x_1854_; 
v___x_1854_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1);
return v___x_1854_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachScoreTable___lam__0(lean_object* v_code_1855_){
_start:
{
lean_object* v___x_1856_; lean_object* v___x_1857_; lean_object* v___x_1858_; lean_object* v___x_1859_; lean_object* v___x_1860_; lean_object* v___x_1861_; lean_object* v___x_1862_; lean_object* v___x_1863_; 
v___x_1856_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1855_);
v___x_1857_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2);
v___x_1858_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1856_, v___x_1857_);
lean_dec_ref(v___x_1856_);
v___x_1859_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3);
v___x_1860_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1858_, v___x_1859_);
lean_dec_ref(v___x_1858_);
v___x_1861_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2);
v___x_1862_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4);
v___x_1863_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1860_, v___x_1861_, v___x_1862_);
return v___x_1863_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1865_; lean_object* v___x_1866_; lean_object* v___x_1867_; 
v___f_1865_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__0));
v___x_1866_ = lean_unsigned_to_nat(1024u);
v___x_1867_ = l_Array_ofFn___redArg(v___x_1866_, v___f_1865_);
return v___x_1867_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable(void){
_start:
{
lean_object* v___x_1868_; 
v___x_1868_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1);
return v___x_1868_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___lam__0(lean_object* v_code_1869_){
_start:
{
lean_object* v___y_1871_; lean_object* v___x_1875_; lean_object* v___x_1876_; lean_object* v___x_1877_; uint8_t v___x_1880_; 
v___x_1875_ = lean_unsigned_to_nat(512u);
v___x_1876_ = lean_nat_mod(v_code_1869_, v___x_1875_);
v___x_1877_ = lean_unsigned_to_nat(0u);
v___x_1880_ = lean_nat_dec_eq(v___x_1876_, v___x_1877_);
if (v___x_1880_ == 0)
{
lean_object* v___x_1881_; uint8_t v___x_1882_; 
v___x_1881_ = lean_unsigned_to_nat(511u);
v___x_1882_ = lean_nat_dec_eq(v___x_1876_, v___x_1881_);
lean_dec(v___x_1876_);
if (v___x_1882_ == 0)
{
uint8_t v___x_1883_; lean_object* v___x_1884_; lean_object* v___x_1885_; lean_object* v___x_1886_; lean_object* v___x_1887_; lean_object* v___x_1888_; 
v___x_1883_ = 1;
v___x_1884_ = lean_unsigned_to_nat(10u);
v___x_1885_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1883_, v___x_1884_, v_code_1869_);
v___x_1886_ = l_Rat_ofInt(v___x_1885_);
v___x_1887_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__0, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__0);
v___x_1888_ = l_Rat_mul(v___x_1886_, v___x_1887_);
lean_dec_ref(v___x_1886_);
v___y_1871_ = v___x_1888_;
goto v___jp_1870_;
}
else
{
lean_dec(v_code_1869_);
goto v___jp_1878_;
}
}
else
{
lean_dec(v___x_1876_);
lean_dec(v_code_1869_);
goto v___jp_1878_;
}
v___jp_1870_:
{
lean_object* v___x_1872_; lean_object* v___x_1873_; lean_object* v___x_1874_; 
v___x_1872_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1);
v___x_1873_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2);
v___x_1874_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___y_1871_, v___x_1872_, v___x_1873_);
return v___x_1874_;
}
v___jp_1878_:
{
lean_object* v___x_1879_; 
v___x_1879_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___y_1871_ = v___x_1879_;
goto v___jp_1870_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1890_; lean_object* v___x_1891_; lean_object* v___x_1892_; 
v___f_1890_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__0));
v___x_1891_ = lean_unsigned_to_nat(1024u);
v___x_1892_ = l_Array_ofFn___redArg(v___x_1891_, v___f_1890_);
return v___x_1892_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable(void){
_start:
{
lean_object* v___x_1893_; 
v___x_1893_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1);
return v___x_1893_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___lam__0(lean_object* v_code_1894_){
_start:
{
lean_object* v___y_1896_; uint8_t v___x_1900_; lean_object* v___x_1901_; lean_object* v___x_1902_; lean_object* v___x_1903_; lean_object* v___x_1904_; lean_object* v_initial_1905_; lean_object* v___x_1906_; uint8_t v___x_1907_; 
v___x_1900_ = 1;
v___x_1901_ = lean_unsigned_to_nat(11u);
v___x_1902_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1900_, v___x_1901_, v_code_1894_);
v___x_1903_ = l_Rat_ofInt(v___x_1902_);
v___x_1904_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v_initial_1905_ = l_Rat_div(v___x_1903_, v___x_1904_);
lean_dec_ref(v___x_1903_);
v___x_1906_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
lean_inc_ref(v_initial_1905_);
v___x_1907_ = l_Rat_blt(v_initial_1905_, v___x_1906_);
if (v___x_1907_ == 0)
{
v___y_1896_ = v_initial_1905_;
goto v___jp_1895_;
}
else
{
lean_object* v___x_1908_; lean_object* v___x_1909_; 
v___x_1908_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1909_ = l_Rat_add(v_initial_1905_, v___x_1908_);
v___y_1896_ = v___x_1909_;
goto v___jp_1895_;
}
v___jp_1895_:
{
lean_object* v___x_1897_; lean_object* v___x_1898_; lean_object* v___x_1899_; 
v___x_1897_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5);
v___x_1898_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7);
v___x_1899_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___y_1896_, v___x_1897_, v___x_1898_);
return v___x_1899_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1911_; lean_object* v___x_1912_; lean_object* v___x_1913_; 
v___f_1911_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__0));
v___x_1912_ = lean_unsigned_to_nat(2048u);
v___x_1913_ = l_Array_ofFn___redArg(v___x_1912_, v___f_1911_);
return v___x_1913_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable(void){
_start:
{
lean_object* v___x_1914_; 
v___x_1914_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1);
return v___x_1914_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindScoreTable___lam__0(lean_object* v_code_1915_){
_start:
{
lean_object* v___x_1916_; lean_object* v___x_1917_; lean_object* v___x_1918_; lean_object* v___x_1919_; 
v___x_1916_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1915_);
v___x_1917_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0);
v___x_1918_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1);
v___x_1919_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1916_, v___x_1917_, v___x_1918_);
return v___x_1919_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1921_; lean_object* v___x_1922_; lean_object* v___x_1923_; 
v___f_1921_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__0));
v___x_1922_ = lean_unsigned_to_nat(512u);
v___x_1923_ = l_Array_ofFn___redArg(v___x_1922_, v___f_1921_);
return v___x_1923_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable(void){
_start:
{
lean_object* v___x_1924_; 
v___x_1924_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1);
return v___x_1924_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPressureScoreTable___lam__0(lean_object* v_code_1925_){
_start:
{
lean_object* v___x_1926_; lean_object* v___x_1927_; lean_object* v___x_1928_; lean_object* v___x_1929_; 
v___x_1926_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1925_);
v___x_1927_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0);
v___x_1928_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1);
v___x_1929_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1926_, v___x_1927_, v___x_1928_);
return v___x_1929_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1931_; lean_object* v___x_1932_; lean_object* v___x_1933_; 
v___f_1931_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__0));
v___x_1932_ = lean_unsigned_to_nat(2048u);
v___x_1933_ = l_Array_ofFn___redArg(v___x_1932_, v___f_1931_);
return v___x_1933_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable(void){
_start:
{
lean_object* v___x_1934_; 
v___x_1934_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1);
return v___x_1934_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1935_; lean_object* v___x_1936_; lean_object* v___x_1937_; 
v___x_1935_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v___x_1936_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0);
v___x_1937_ = l_Rat_div(v___x_1936_, v___x_1935_);
return v___x_1937_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0(lean_object* v_code_1938_){
_start:
{
uint8_t v___x_1939_; lean_object* v___x_1940_; lean_object* v___x_1941_; lean_object* v___x_1942_; lean_object* v___x_1943_; lean_object* v___x_1944_; lean_object* v___x_1945_; lean_object* v___x_1946_; lean_object* v___x_1947_; 
v___x_1939_ = 1;
v___x_1940_ = lean_unsigned_to_nat(10u);
v___x_1941_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1939_, v___x_1940_, v_code_1938_);
v___x_1942_ = l_Rat_ofInt(v___x_1941_);
v___x_1943_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0);
v___x_1944_ = l_Rat_mul(v___x_1942_, v___x_1943_);
lean_dec_ref(v___x_1942_);
v___x_1945_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2);
v___x_1946_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4);
v___x_1947_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1944_, v___x_1945_, v___x_1946_);
return v___x_1947_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1949_; lean_object* v___x_1950_; lean_object* v___x_1951_; 
v___f_1949_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__0));
v___x_1950_ = lean_unsigned_to_nat(1024u);
v___x_1951_ = l_Array_ofFn___redArg(v___x_1950_, v___f_1949_);
return v___x_1951_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable(void){
_start:
{
lean_object* v___x_1952_; 
v___x_1952_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1);
return v___x_1952_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg(lean_object* v_width_1953_, lean_object* v_table_1954_, lean_object* v_word_1955_, lean_object* v_start_1956_){
_start:
{
lean_object* v___x_1957_; lean_object* v___x_1958_; 
v___x_1957_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1955_, v_start_1956_, v_width_1953_);
v___x_1958_ = lean_array_fget_borrowed(v_table_1954_, v___x_1957_);
lean_dec(v___x_1957_);
lean_inc(v___x_1958_);
return v___x_1958_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg___boxed(lean_object* v_width_1959_, lean_object* v_table_1960_, lean_object* v_word_1961_, lean_object* v_start_1962_){
_start:
{
lean_object* v_res_1963_; 
v_res_1963_ = lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg(v_width_1959_, v_table_1960_, v_word_1961_, v_start_1962_);
lean_dec(v_start_1962_);
lean_dec(v_word_1961_);
lean_dec_ref(v_table_1960_);
lean_dec(v_width_1959_);
return v_res_1963_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet(lean_object* v_width_1964_, lean_object* v_table_1965_, lean_object* v_size_1966_, lean_object* v_word_1967_, lean_object* v_start_1968_){
_start:
{
lean_object* v___x_1969_; lean_object* v___x_1970_; 
v___x_1969_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1967_, v_start_1968_, v_width_1964_);
v___x_1970_ = lean_array_fget_borrowed(v_table_1965_, v___x_1969_);
lean_dec(v___x_1969_);
lean_inc(v___x_1970_);
return v___x_1970_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___boxed(lean_object* v_width_1971_, lean_object* v_table_1972_, lean_object* v_size_1973_, lean_object* v_word_1974_, lean_object* v_start_1975_){
_start:
{
lean_object* v_res_1976_; 
v_res_1976_ = lp_lean1090_Lean1090_Impl_cbDensityTableGet(v_width_1971_, v_table_1972_, v_size_1973_, v_word_1974_, v_start_1975_);
lean_dec(v_start_1975_);
lean_dec(v_word_1974_);
lean_dec_ref(v_table_1972_);
lean_dec(v_width_1971_);
return v_res_1976_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTermsFast(lean_object* v_register_1977_, lean_object* v_word_1978_){
_start:
{
lean_object* v___x_1979_; uint8_t v___x_1980_; 
v___x_1979_ = lean_unsigned_to_nat(64u);
v___x_1980_ = lean_nat_dec_eq(v_register_1977_, v___x_1979_);
if (v___x_1980_ == 0)
{
lean_object* v___x_1981_; uint8_t v___x_1982_; 
v___x_1981_ = lean_unsigned_to_nat(80u);
v___x_1982_ = lean_nat_dec_eq(v_register_1977_, v___x_1981_);
if (v___x_1982_ == 0)
{
lean_object* v___x_1983_; uint8_t v___x_1984_; 
v___x_1983_ = lean_unsigned_to_nat(96u);
v___x_1984_ = lean_nat_dec_eq(v_register_1977_, v___x_1983_);
if (v___x_1984_ == 0)
{
lean_object* v___x_1985_; uint8_t v___x_1986_; 
v___x_1985_ = lean_unsigned_to_nat(68u);
v___x_1986_ = lean_nat_dec_eq(v_register_1977_, v___x_1985_);
if (v___x_1986_ == 0)
{
lean_object* v___x_1987_; uint8_t v___x_1988_; 
v___x_1987_ = lean_unsigned_to_nat(69u);
v___x_1988_ = lean_nat_dec_eq(v_register_1977_, v___x_1987_);
if (v___x_1988_ == 0)
{
lean_object* v___x_1989_; 
v___x_1989_ = lean_box(0);
return v___x_1989_;
}
else
{
lean_object* v___x_1990_; lean_object* v___x_1991_; lean_object* v___x_1992_; lean_object* v___x_1993_; lean_object* v___y_1995_; uint8_t v___x_2009_; 
v___x_1990_ = lean_unsigned_to_nat(16u);
v___x_1991_ = lean_unsigned_to_nat(1u);
v___x_1992_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_1990_, v___x_1991_);
v___x_1993_ = lean_unsigned_to_nat(0u);
v___x_2009_ = lean_nat_dec_eq(v___x_1992_, v___x_1993_);
lean_dec(v___x_1992_);
if (v___x_2009_ == 0)
{
lean_object* v___x_2010_; lean_object* v___x_2011_; lean_object* v___x_2012_; lean_object* v___x_2013_; lean_object* v___x_2014_; lean_object* v___x_2015_; lean_object* v___x_2016_; 
v___x_2010_ = lean_unsigned_to_nat(10u);
v___x_2011_ = lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable;
v___x_2012_ = lean_unsigned_to_nat(17u);
v___x_2013_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2012_, v___x_2010_);
v___x_2014_ = lean_array_fget_borrowed(v___x_2011_, v___x_2013_);
lean_dec(v___x_2013_);
v___x_2015_ = lean_box(0);
lean_inc(v___x_2014_);
v___x_2016_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2016_, 0, v___x_2014_);
lean_ctor_set(v___x_2016_, 1, v___x_2015_);
v___y_1995_ = v___x_2016_;
goto v___jp_1994_;
}
else
{
lean_object* v___x_2017_; 
v___x_2017_ = lean_box(0);
v___y_1995_ = v___x_2017_;
goto v___jp_1994_;
}
v___jp_1994_:
{
lean_object* v___x_1996_; lean_object* v___x_1997_; uint8_t v___x_1998_; 
v___x_1996_ = lean_unsigned_to_nat(27u);
v___x_1997_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_1996_, v___x_1991_);
v___x_1998_ = lean_nat_dec_eq(v___x_1997_, v___x_1993_);
lean_dec(v___x_1997_);
if (v___x_1998_ == 0)
{
lean_object* v___x_1999_; lean_object* v___x_2000_; lean_object* v___x_2001_; lean_object* v___x_2002_; lean_object* v___x_2003_; lean_object* v___x_2004_; lean_object* v___x_2005_; lean_object* v___x_2006_; 
v___x_1999_ = lean_unsigned_to_nat(11u);
v___x_2000_ = lp_lean1090_Lean1090_Impl_cbPressureScoreTable;
v___x_2001_ = lean_unsigned_to_nat(28u);
v___x_2002_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2001_, v___x_1999_);
v___x_2003_ = lean_array_fget_borrowed(v___x_2000_, v___x_2002_);
lean_dec(v___x_2002_);
v___x_2004_ = lean_box(0);
lean_inc(v___x_2003_);
v___x_2005_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2005_, 0, v___x_2003_);
lean_ctor_set(v___x_2005_, 1, v___x_2004_);
v___x_2006_ = l_List_appendTR___redArg(v___y_1995_, v___x_2005_);
return v___x_2006_;
}
else
{
lean_object* v___x_2007_; lean_object* v___x_2008_; 
v___x_2007_ = lean_box(0);
v___x_2008_ = l_List_appendTR___redArg(v___y_1995_, v___x_2007_);
return v___x_2008_;
}
}
}
}
else
{
lean_object* v___x_2018_; lean_object* v___x_2019_; lean_object* v___x_2020_; lean_object* v___x_2021_; lean_object* v___x_2022_; lean_object* v___x_2023_; lean_object* v___x_2024_; lean_object* v___x_2025_; lean_object* v___x_2026_; lean_object* v___x_2027_; lean_object* v___x_2028_; lean_object* v___y_2030_; uint8_t v___x_2042_; 
v___x_2018_ = lean_unsigned_to_nat(11u);
v___x_2019_ = lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable;
v___x_2020_ = lean_unsigned_to_nat(24u);
v___x_2021_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2020_, v___x_2018_);
v___x_2022_ = lean_array_fget_borrowed(v___x_2019_, v___x_2021_);
lean_dec(v___x_2021_);
v___x_2023_ = lean_box(0);
lean_inc(v___x_2022_);
v___x_2024_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2024_, 0, v___x_2022_);
lean_ctor_set(v___x_2024_, 1, v___x_2023_);
v___x_2025_ = lean_unsigned_to_nat(5u);
v___x_2026_ = lean_unsigned_to_nat(1u);
v___x_2027_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2025_, v___x_2026_);
v___x_2028_ = lean_unsigned_to_nat(0u);
v___x_2042_ = lean_nat_dec_eq(v___x_2027_, v___x_2028_);
lean_dec(v___x_2027_);
if (v___x_2042_ == 0)
{
lean_object* v___x_2043_; lean_object* v___x_2044_; lean_object* v___x_2045_; lean_object* v___x_2046_; lean_object* v___x_2047_; lean_object* v___x_2048_; 
v___x_2043_ = lean_unsigned_to_nat(9u);
v___x_2044_ = lp_lean1090_Lean1090_Impl_cbWindScoreTable;
v___x_2045_ = lean_unsigned_to_nat(6u);
v___x_2046_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2045_, v___x_2043_);
v___x_2047_ = lean_array_fget_borrowed(v___x_2044_, v___x_2046_);
lean_dec(v___x_2046_);
lean_inc(v___x_2047_);
v___x_2048_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2048_, 0, v___x_2047_);
lean_ctor_set(v___x_2048_, 1, v___x_2023_);
v___y_2030_ = v___x_2048_;
goto v___jp_2029_;
}
else
{
v___y_2030_ = v___x_2023_;
goto v___jp_2029_;
}
v___jp_2029_:
{
lean_object* v___x_2031_; lean_object* v___x_2032_; lean_object* v___x_2033_; uint8_t v___x_2034_; 
v___x_2031_ = l_List_appendTR___redArg(v___x_2024_, v___y_2030_);
v___x_2032_ = lean_unsigned_to_nat(35u);
v___x_2033_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2032_, v___x_2026_);
v___x_2034_ = lean_nat_dec_eq(v___x_2033_, v___x_2028_);
lean_dec(v___x_2033_);
if (v___x_2034_ == 0)
{
lean_object* v___x_2035_; lean_object* v___x_2036_; lean_object* v___x_2037_; lean_object* v___x_2038_; lean_object* v___x_2039_; lean_object* v___x_2040_; 
v___x_2035_ = lp_lean1090_Lean1090_Impl_cbPressureScoreTable;
v___x_2036_ = lean_unsigned_to_nat(36u);
v___x_2037_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2036_, v___x_2018_);
v___x_2038_ = lean_array_fget_borrowed(v___x_2035_, v___x_2037_);
lean_dec(v___x_2037_);
lean_inc(v___x_2038_);
v___x_2039_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2039_, 0, v___x_2038_);
lean_ctor_set(v___x_2039_, 1, v___x_2023_);
v___x_2040_ = l_List_appendTR___redArg(v___x_2031_, v___x_2039_);
return v___x_2040_;
}
else
{
lean_object* v___x_2041_; 
v___x_2041_ = l_List_appendTR___redArg(v___x_2031_, v___x_2023_);
return v___x_2041_;
}
}
}
}
else
{
lean_object* v___x_2049_; lean_object* v___x_2050_; lean_object* v___x_2051_; lean_object* v___x_2052_; lean_object* v___y_2054_; lean_object* v___y_2055_; lean_object* v___y_2071_; uint8_t v___x_2083_; 
v___x_2049_ = lean_unsigned_to_nat(13u);
v___x_2050_ = lean_unsigned_to_nat(1u);
v___x_2051_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2049_, v___x_2050_);
v___x_2052_ = lean_unsigned_to_nat(0u);
v___x_2083_ = lean_nat_dec_eq(v___x_2051_, v___x_2052_);
lean_dec(v___x_2051_);
if (v___x_2083_ == 0)
{
lean_object* v___x_2084_; lean_object* v___x_2085_; lean_object* v___x_2086_; lean_object* v___x_2087_; lean_object* v___x_2088_; lean_object* v___x_2089_; lean_object* v___x_2090_; 
v___x_2084_ = lean_unsigned_to_nat(10u);
v___x_2085_ = lp_lean1090_Lean1090_Impl_cbIASScoreTable;
v___x_2086_ = lean_unsigned_to_nat(14u);
v___x_2087_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2086_, v___x_2084_);
v___x_2088_ = lean_array_fget_borrowed(v___x_2085_, v___x_2087_);
lean_dec(v___x_2087_);
v___x_2089_ = lean_box(0);
lean_inc(v___x_2088_);
v___x_2090_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2090_, 0, v___x_2088_);
lean_ctor_set(v___x_2090_, 1, v___x_2089_);
v___y_2071_ = v___x_2090_;
goto v___jp_2070_;
}
else
{
lean_object* v___x_2091_; 
v___x_2091_ = lean_box(0);
v___y_2071_ = v___x_2091_;
goto v___jp_2070_;
}
v___jp_2053_:
{
lean_object* v___x_2056_; lean_object* v___x_2057_; lean_object* v___x_2058_; uint8_t v___x_2059_; 
v___x_2056_ = l_List_appendTR___redArg(v___y_2054_, v___y_2055_);
v___x_2057_ = lean_unsigned_to_nat(46u);
v___x_2058_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2057_, v___x_2050_);
v___x_2059_ = lean_nat_dec_eq(v___x_2058_, v___x_2052_);
lean_dec(v___x_2058_);
if (v___x_2059_ == 0)
{
lean_object* v___x_2060_; lean_object* v___x_2061_; lean_object* v___x_2062_; lean_object* v___x_2063_; lean_object* v___x_2064_; lean_object* v___x_2065_; lean_object* v___x_2066_; lean_object* v___x_2067_; 
v___x_2060_ = lean_unsigned_to_nat(10u);
v___x_2061_ = lp_lean1090_Lean1090_Impl_cbVerticalScoreTable;
v___x_2062_ = lean_unsigned_to_nat(47u);
v___x_2063_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2062_, v___x_2060_);
v___x_2064_ = lean_array_fget_borrowed(v___x_2061_, v___x_2063_);
lean_dec(v___x_2063_);
v___x_2065_ = lean_box(0);
lean_inc(v___x_2064_);
v___x_2066_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2066_, 0, v___x_2064_);
lean_ctor_set(v___x_2066_, 1, v___x_2065_);
v___x_2067_ = l_List_appendTR___redArg(v___x_2056_, v___x_2066_);
return v___x_2067_;
}
else
{
lean_object* v___x_2068_; lean_object* v___x_2069_; 
v___x_2068_ = lean_box(0);
v___x_2069_ = l_List_appendTR___redArg(v___x_2056_, v___x_2068_);
return v___x_2069_;
}
}
v___jp_2070_:
{
lean_object* v___x_2072_; lean_object* v___x_2073_; uint8_t v___x_2074_; 
v___x_2072_ = lean_unsigned_to_nat(24u);
v___x_2073_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2072_, v___x_2050_);
v___x_2074_ = lean_nat_dec_eq(v___x_2073_, v___x_2052_);
lean_dec(v___x_2073_);
if (v___x_2074_ == 0)
{
lean_object* v___x_2075_; lean_object* v___x_2076_; lean_object* v___x_2077_; lean_object* v___x_2078_; lean_object* v___x_2079_; lean_object* v___x_2080_; lean_object* v___x_2081_; 
v___x_2075_ = lean_unsigned_to_nat(10u);
v___x_2076_ = lp_lean1090_Lean1090_Impl_cbMachScoreTable;
v___x_2077_ = lean_unsigned_to_nat(25u);
v___x_2078_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2077_, v___x_2075_);
v___x_2079_ = lean_array_fget_borrowed(v___x_2076_, v___x_2078_);
lean_dec(v___x_2078_);
v___x_2080_ = lean_box(0);
lean_inc(v___x_2079_);
v___x_2081_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2081_, 0, v___x_2079_);
lean_ctor_set(v___x_2081_, 1, v___x_2080_);
v___y_2054_ = v___y_2071_;
v___y_2055_ = v___x_2081_;
goto v___jp_2053_;
}
else
{
lean_object* v___x_2082_; 
v___x_2082_ = lean_box(0);
v___y_2054_ = v___y_2071_;
v___y_2055_ = v___x_2082_;
goto v___jp_2053_;
}
}
}
}
else
{
lean_object* v___x_2092_; lean_object* v___x_2093_; lean_object* v___x_2094_; lean_object* v___y_2096_; lean_object* v___y_2097_; lean_object* v___y_2113_; lean_object* v___y_2114_; lean_object* v___y_2128_; lean_object* v___y_2131_; uint8_t v___x_2147_; 
v___x_2092_ = lean_unsigned_to_nat(1u);
v___x_2093_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2092_, v___x_2092_);
v___x_2094_ = lean_unsigned_to_nat(0u);
v___x_2147_ = lean_nat_dec_eq(v___x_2093_, v___x_2094_);
lean_dec(v___x_2093_);
if (v___x_2147_ == 0)
{
lean_object* v___x_2148_; lean_object* v___x_2149_; lean_object* v___x_2150_; lean_object* v___x_2151_; lean_object* v___x_2152_; lean_object* v___x_2153_; lean_object* v___x_2154_; 
v___x_2148_ = lean_unsigned_to_nat(10u);
v___x_2149_ = lp_lean1090_Lean1090_Impl_cbRollScoreTable;
v___x_2150_ = lean_unsigned_to_nat(2u);
v___x_2151_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2150_, v___x_2148_);
v___x_2152_ = lean_array_fget_borrowed(v___x_2149_, v___x_2151_);
lean_dec(v___x_2151_);
v___x_2153_ = lean_box(0);
lean_inc(v___x_2152_);
v___x_2154_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2154_, 0, v___x_2152_);
lean_ctor_set(v___x_2154_, 1, v___x_2153_);
v___y_2131_ = v___x_2154_;
goto v___jp_2130_;
}
else
{
lean_object* v___x_2155_; 
v___x_2155_ = lean_box(0);
v___y_2131_ = v___x_2155_;
goto v___jp_2130_;
}
v___jp_2095_:
{
lean_object* v___x_2098_; lean_object* v___x_2099_; lean_object* v___x_2100_; uint8_t v___x_2101_; 
v___x_2098_ = l_List_appendTR___redArg(v___y_2096_, v___y_2097_);
v___x_2099_ = lean_unsigned_to_nat(24u);
v___x_2100_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2099_, v___x_2092_);
v___x_2101_ = lean_nat_dec_eq(v___x_2100_, v___x_2094_);
lean_dec(v___x_2100_);
if (v___x_2101_ == 0)
{
lean_object* v___x_2102_; lean_object* v___x_2103_; lean_object* v___x_2104_; lean_object* v___x_2105_; lean_object* v___x_2106_; lean_object* v___x_2107_; lean_object* v___x_2108_; lean_object* v___x_2109_; 
v___x_2102_ = lean_unsigned_to_nat(10u);
v___x_2103_ = lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable;
v___x_2104_ = lean_unsigned_to_nat(25u);
v___x_2105_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2104_, v___x_2102_);
v___x_2106_ = lean_array_fget_borrowed(v___x_2103_, v___x_2105_);
lean_dec(v___x_2105_);
v___x_2107_ = lean_box(0);
lean_inc(v___x_2106_);
v___x_2108_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2108_, 0, v___x_2106_);
lean_ctor_set(v___x_2108_, 1, v___x_2107_);
v___x_2109_ = l_List_appendTR___redArg(v___x_2098_, v___x_2108_);
return v___x_2109_;
}
else
{
lean_object* v___x_2110_; lean_object* v___x_2111_; 
v___x_2110_ = lean_box(0);
v___x_2111_ = l_List_appendTR___redArg(v___x_2098_, v___x_2110_);
return v___x_2111_;
}
}
v___jp_2112_:
{
lean_object* v___x_2115_; lean_object* v___x_2116_; lean_object* v___x_2117_; uint8_t v___x_2118_; 
v___x_2115_ = l_List_appendTR___redArg(v___y_2113_, v___y_2114_);
v___x_2116_ = lean_unsigned_to_nat(46u);
v___x_2117_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2116_, v___x_2092_);
v___x_2118_ = lean_nat_dec_eq(v___x_2117_, v___x_2094_);
lean_dec(v___x_2117_);
if (v___x_2118_ == 0)
{
lean_object* v___x_2119_; lean_object* v___x_2120_; lean_object* v___x_2121_; lean_object* v___x_2122_; lean_object* v___x_2123_; lean_object* v___x_2124_; lean_object* v___x_2125_; 
v___x_2119_ = lean_unsigned_to_nat(10u);
v___x_2120_ = lp_lean1090_Lean1090_Impl_cbTASScoreTable;
v___x_2121_ = lean_unsigned_to_nat(47u);
v___x_2122_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2121_, v___x_2119_);
v___x_2123_ = lean_array_fget_borrowed(v___x_2120_, v___x_2122_);
lean_dec(v___x_2122_);
v___x_2124_ = lean_box(0);
lean_inc(v___x_2123_);
v___x_2125_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2125_, 0, v___x_2123_);
lean_ctor_set(v___x_2125_, 1, v___x_2124_);
v___y_2096_ = v___x_2115_;
v___y_2097_ = v___x_2125_;
goto v___jp_2095_;
}
else
{
lean_object* v___x_2126_; 
v___x_2126_ = lean_box(0);
v___y_2096_ = v___x_2115_;
v___y_2097_ = v___x_2126_;
goto v___jp_2095_;
}
}
v___jp_2127_:
{
lean_object* v___x_2129_; 
v___x_2129_ = lean_box(0);
v___y_2113_ = v___y_2128_;
v___y_2114_ = v___x_2129_;
goto v___jp_2112_;
}
v___jp_2130_:
{
lean_object* v___x_2132_; lean_object* v___x_2133_; uint8_t v___x_2134_; 
v___x_2132_ = lean_unsigned_to_nat(35u);
v___x_2133_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2132_, v___x_2092_);
v___x_2134_ = lean_nat_dec_eq(v___x_2133_, v___x_2094_);
lean_dec(v___x_2133_);
if (v___x_2134_ == 0)
{
lean_object* v___x_2135_; lean_object* v___x_2136_; lean_object* v___x_2137_; lean_object* v___x_2138_; uint8_t v___x_2139_; 
v___x_2135_ = lean_unsigned_to_nat(37u);
v___x_2136_ = lean_unsigned_to_nat(9u);
v___x_2137_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2135_, v___x_2136_);
v___x_2138_ = lean_unsigned_to_nat(511u);
v___x_2139_ = lean_nat_dec_eq(v___x_2137_, v___x_2138_);
lean_dec(v___x_2137_);
if (v___x_2139_ == 0)
{
lean_object* v___x_2140_; lean_object* v___x_2141_; lean_object* v___x_2142_; lean_object* v___x_2143_; lean_object* v___x_2144_; lean_object* v___x_2145_; lean_object* v___x_2146_; 
v___x_2140_ = lean_unsigned_to_nat(10u);
v___x_2141_ = lp_lean1090_Lean1090_Impl_cbRateScoreTable;
v___x_2142_ = lean_unsigned_to_nat(36u);
v___x_2143_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2142_, v___x_2140_);
v___x_2144_ = lean_array_fget_borrowed(v___x_2141_, v___x_2143_);
lean_dec(v___x_2143_);
v___x_2145_ = lean_box(0);
lean_inc(v___x_2144_);
v___x_2146_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2146_, 0, v___x_2144_);
lean_ctor_set(v___x_2146_, 1, v___x_2145_);
v___y_2113_ = v___y_2131_;
v___y_2114_ = v___x_2146_;
goto v___jp_2112_;
}
else
{
v___y_2128_ = v___y_2131_;
goto v___jp_2127_;
}
}
else
{
v___y_2128_ = v___y_2131_;
goto v___jp_2127_;
}
}
}
}
else
{
lean_object* v___x_2156_; lean_object* v___x_2157_; lean_object* v___x_2158_; lean_object* v___x_2159_; lean_object* v___y_2161_; lean_object* v___y_2162_; lean_object* v___y_2178_; uint8_t v___x_2189_; 
v___x_2156_ = lean_unsigned_to_nat(27u);
v___x_2157_ = lean_unsigned_to_nat(1u);
v___x_2158_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2156_, v___x_2157_);
v___x_2159_ = lean_unsigned_to_nat(0u);
v___x_2189_ = lean_nat_dec_eq(v___x_2158_, v___x_2159_);
lean_dec(v___x_2158_);
if (v___x_2189_ == 0)
{
lean_object* v___x_2190_; lean_object* v___x_2191_; lean_object* v___x_2192_; lean_object* v___x_2193_; lean_object* v___x_2194_; lean_object* v___x_2195_; lean_object* v___x_2196_; 
v___x_2190_ = lean_unsigned_to_nat(12u);
v___x_2191_ = lp_lean1090_Lean1090_Impl_cbQNHScoreTable;
v___x_2192_ = lean_unsigned_to_nat(28u);
v___x_2193_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2192_, v___x_2190_);
v___x_2194_ = lean_array_fget_borrowed(v___x_2191_, v___x_2193_);
lean_dec(v___x_2193_);
v___x_2195_ = lean_box(0);
lean_inc(v___x_2194_);
v___x_2196_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2196_, 0, v___x_2194_);
lean_ctor_set(v___x_2196_, 1, v___x_2195_);
v___y_2178_ = v___x_2196_;
goto v___jp_2177_;
}
else
{
lean_object* v___x_2197_; 
v___x_2197_ = lean_box(0);
v___y_2178_ = v___x_2197_;
goto v___jp_2177_;
}
v___jp_2160_:
{
lean_object* v___x_2163_; lean_object* v___x_2164_; lean_object* v___x_2165_; uint8_t v___x_2166_; 
v___x_2163_ = l_List_appendTR___redArg(v___y_2161_, v___y_2162_);
v___x_2164_ = lean_unsigned_to_nat(14u);
v___x_2165_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2164_, v___x_2157_);
v___x_2166_ = lean_nat_dec_eq(v___x_2165_, v___x_2159_);
lean_dec(v___x_2165_);
if (v___x_2166_ == 0)
{
lean_object* v___x_2167_; lean_object* v___x_2168_; lean_object* v___x_2169_; lean_object* v___x_2170_; lean_object* v___x_2171_; lean_object* v___x_2172_; lean_object* v___x_2173_; lean_object* v___x_2174_; 
v___x_2167_ = lean_unsigned_to_nat(12u);
v___x_2168_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable;
v___x_2169_ = lean_unsigned_to_nat(15u);
v___x_2170_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2169_, v___x_2167_);
v___x_2171_ = lean_array_fget_borrowed(v___x_2168_, v___x_2170_);
lean_dec(v___x_2170_);
v___x_2172_ = lean_box(0);
lean_inc(v___x_2171_);
v___x_2173_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2173_, 0, v___x_2171_);
lean_ctor_set(v___x_2173_, 1, v___x_2172_);
v___x_2174_ = l_List_appendTR___redArg(v___x_2163_, v___x_2173_);
return v___x_2174_;
}
else
{
lean_object* v___x_2175_; lean_object* v___x_2176_; 
v___x_2175_ = lean_box(0);
v___x_2176_ = l_List_appendTR___redArg(v___x_2163_, v___x_2175_);
return v___x_2176_;
}
}
v___jp_2177_:
{
lean_object* v___x_2179_; uint8_t v___x_2180_; 
v___x_2179_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2157_, v___x_2157_);
v___x_2180_ = lean_nat_dec_eq(v___x_2179_, v___x_2159_);
lean_dec(v___x_2179_);
if (v___x_2180_ == 0)
{
lean_object* v___x_2181_; lean_object* v___x_2182_; lean_object* v___x_2183_; lean_object* v___x_2184_; lean_object* v___x_2185_; lean_object* v___x_2186_; lean_object* v___x_2187_; 
v___x_2181_ = lean_unsigned_to_nat(12u);
v___x_2182_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable;
v___x_2183_ = lean_unsigned_to_nat(2u);
v___x_2184_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1978_, v___x_2183_, v___x_2181_);
v___x_2185_ = lean_array_fget_borrowed(v___x_2182_, v___x_2184_);
lean_dec(v___x_2184_);
v___x_2186_ = lean_box(0);
lean_inc(v___x_2185_);
v___x_2187_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2187_, 0, v___x_2185_);
lean_ctor_set(v___x_2187_, 1, v___x_2186_);
v___y_2161_ = v___y_2178_;
v___y_2162_ = v___x_2187_;
goto v___jp_2160_;
}
else
{
lean_object* v___x_2188_; 
v___x_2188_ = lean_box(0);
v___y_2161_ = v___y_2178_;
v___y_2162_ = v___x_2188_;
goto v___jp_2160_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTermsFast___boxed(lean_object* v_register_2198_, lean_object* v_word_2199_){
_start:
{
lean_object* v_res_2200_; 
v_res_2200_ = lp_lean1090_Lean1090_Impl_cbDensityTermsFast(v_register_2198_, v_word_2199_);
lean_dec(v_word_2199_);
lean_dec(v_register_2198_);
return v_res_2200_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0(lean_object* v_register_2201_, lean_object* v_word_2202_, lean_object* v_x_2203_){
_start:
{
lean_object* v___x_2204_; lean_object* v___x_2205_; uint8_t v___x_2206_; 
v___x_2204_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__1, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1);
v___x_2205_ = lp_lean1090_Lean1090_Impl_cbCombinedScore(v_register_2201_, v_word_2202_);
v___x_2206_ = l_Rat_instDecidableLe(v___x_2204_, v___x_2205_);
return v___x_2206_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed(lean_object* v_register_2207_, lean_object* v_word_2208_, lean_object* v_x_2209_){
_start:
{
uint8_t v_res_2210_; lean_object* v_r_2211_; 
v_res_2210_ = lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0(v_register_2207_, v_word_2208_, v_x_2209_);
lean_dec(v_word_2208_);
lean_dec(v_register_2207_);
v_r_2211_ = lean_box(v_res_2210_);
return v_r_2211_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses(lean_object* v_register_2212_, lean_object* v_word_2213_){
_start:
{
lean_object* v___f_2214_; lean_object* v___x_2215_; lean_object* v___x_2216_; uint8_t v___x_2217_; 
lean_inc(v_word_2213_);
lean_inc(v_register_2212_);
v___f_2214_ = lean_alloc_closure((void*)(lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed), 3, 2);
lean_closure_set(v___f_2214_, 0, v_register_2212_);
lean_closure_set(v___f_2214_, 1, v_word_2213_);
v___x_2215_ = lp_lean1090_Lean1090_Impl_cbDensityTermsFast(v_register_2212_, v_word_2213_);
v___x_2216_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_2212_, v_word_2213_);
lean_dec(v_word_2213_);
lean_dec(v_register_2212_);
v___x_2217_ = lp_lean1090_Lean1090_Impl_ScoreGate_choose(v___x_2215_, v___x_2216_, v___f_2214_);
return v___x_2217_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScorePasses___boxed(lean_object* v_register_2218_, lean_object* v_word_2219_){
_start:
{
uint8_t v_res_2220_; lean_object* v_r_2221_; 
v_res_2220_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2218_, v_word_2219_);
v_r_2221_ = lean_box(v_res_2220_);
return v_r_2221_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBCoreEligible(lean_object* v_register_2259_, lean_object* v_word_2260_){
_start:
{
uint8_t v___y_2262_; lean_object* v___x_2266_; uint8_t v___x_2267_; 
v___x_2266_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBCoreRegisters));
v___x_2267_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_2259_, v___x_2266_);
if (v___x_2267_ == 0)
{
v___y_2262_ = v___x_2267_;
goto v___jp_2261_;
}
else
{
uint8_t v___x_2268_; 
v___x_2268_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_2259_, v_word_2260_);
v___y_2262_ = v___x_2268_;
goto v___jp_2261_;
}
v___jp_2261_:
{
if (v___y_2262_ == 0)
{
lean_dec(v_word_2260_);
lean_dec(v_register_2259_);
return v___y_2262_;
}
else
{
lean_object* v___x_2263_; uint8_t v___x_2264_; 
v___x_2263_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__4));
v___x_2264_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_2259_, v___x_2263_);
if (v___x_2264_ == 0)
{
lean_dec(v_word_2260_);
lean_dec(v_register_2259_);
return v___y_2262_;
}
else
{
uint8_t v___x_2265_; 
v___x_2265_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2259_, v_word_2260_);
return v___x_2265_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBCoreEligible___boxed(lean_object* v_register_2269_, lean_object* v_word_2270_){
_start:
{
uint8_t v_res_2271_; lean_object* v_r_2272_; 
v_res_2271_ = lp_lean1090_Lean1090_Impl_commBCoreEligible(v_register_2269_, v_word_2270_);
v_r_2272_ = lean_box(v_res_2271_);
return v_r_2272_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBPositionEligible(lean_object* v_df_2273_, lean_object* v_outerAltitude_2274_, lean_object* v_word_2275_){
_start:
{
lean_object* v___x_2276_; uint8_t v___x_2277_; 
v___x_2276_ = lean_unsigned_to_nat(20u);
v___x_2277_ = lean_nat_dec_eq(v_df_2273_, v___x_2276_);
if (v___x_2277_ == 0)
{
lean_dec(v_outerAltitude_2274_);
return v___x_2277_;
}
else
{
lean_object* v___x_2278_; lean_object* v___x_2279_; lean_object* v_tc_2280_; lean_object* v___x_2281_; uint8_t v___x_2282_; 
v___x_2278_ = lean_unsigned_to_nat(1u);
v___x_2279_ = lean_unsigned_to_nat(5u);
v_tc_2280_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2275_, v___x_2278_, v___x_2279_);
v___x_2281_ = lean_unsigned_to_nat(9u);
v___x_2282_ = lean_nat_dec_le(v___x_2281_, v_tc_2280_);
if (v___x_2282_ == 0)
{
lean_dec(v_tc_2280_);
lean_dec(v_outerAltitude_2274_);
return v___x_2282_;
}
else
{
lean_object* v___x_2283_; uint8_t v___x_2284_; 
v___x_2283_ = lean_unsigned_to_nat(22u);
v___x_2284_ = lean_nat_dec_lt(v_tc_2280_, v___x_2283_);
if (v___x_2284_ == 0)
{
lean_dec(v_tc_2280_);
lean_dec(v_outerAltitude_2274_);
return v___x_2284_;
}
else
{
lean_object* v___x_2285_; uint8_t v___x_2286_; 
v___x_2285_ = lean_unsigned_to_nat(19u);
v___x_2286_ = lean_nat_dec_eq(v_tc_2280_, v___x_2285_);
lean_dec(v_tc_2280_);
if (v___x_2286_ == 0)
{
uint8_t v___x_2287_; 
v___x_2287_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v___x_2279_, v_word_2275_);
if (v___x_2287_ == 0)
{
lean_dec(v_outerAltitude_2274_);
return v___x_2287_;
}
else
{
lean_object* v___x_2288_; lean_object* v___x_2289_; uint8_t v___x_2290_; 
v___x_2288_ = lean_alloc_closure((void*)(l_Int_instDecidableEq___boxed), 2, 0);
v___x_2289_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_word_2275_);
v___x_2290_ = l_Option_instDecidableEq___redArg(v___x_2288_, v___x_2289_, v_outerAltitude_2274_);
return v___x_2290_;
}
}
else
{
uint8_t v___x_2291_; 
lean_dec(v_outerAltitude_2274_);
v___x_2291_ = 0;
return v___x_2291_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBPositionEligible___boxed(lean_object* v_df_2292_, lean_object* v_outerAltitude_2293_, lean_object* v_word_2294_){
_start:
{
uint8_t v_res_2295_; lean_object* v_r_2296_; 
v_res_2295_ = lp_lean1090_Lean1090_Impl_commBPositionEligible(v_df_2292_, v_outerAltitude_2293_, v_word_2294_);
lean_dec(v_word_2294_);
lean_dec(v_df_2292_);
v_r_2296_ = lean_box(v_res_2295_);
return v_r_2296_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg(){
_start:
{
uint8_t v___x_2298_; 
v___x_2298_ = 0;
return v___x_2298_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg___boxed(lean_object* v___dummy_2299_){
_start:
{
uint8_t v_res_2300_; lean_object* v_r_2301_; 
v_res_2300_ = lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg();
v_r_2301_ = lean_box(v_res_2300_);
return v_r_2301_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBOperationEligible(lean_object* v___word_2302_){
_start:
{
uint8_t v___x_2303_; 
v___x_2303_ = 0;
return v___x_2303_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBOperationEligible___boxed(lean_object* v___word_2304_){
_start:
{
uint8_t v_res_2305_; lean_object* v_r_2306_; 
v_res_2305_ = lp_lean1090_Lean1090_Impl_commBOperationEligible(v___word_2304_);
lean_dec(v___word_2304_);
v_r_2306_ = lean_box(v_res_2305_);
return v_r_2306_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBEligible(lean_object* v_df_2307_, lean_object* v_outerAltitude_2308_, lean_object* v_register_2309_, lean_object* v_word_2310_){
_start:
{
lean_object* v___x_2321_; uint8_t v___x_2322_; 
v___x_2321_ = lean_unsigned_to_nat(20u);
v___x_2322_ = lean_nat_dec_eq(v_df_2307_, v___x_2321_);
if (v___x_2322_ == 0)
{
lean_object* v___x_2323_; uint8_t v___x_2324_; 
v___x_2323_ = lean_unsigned_to_nat(21u);
v___x_2324_ = lean_nat_dec_eq(v_df_2307_, v___x_2323_);
if (v___x_2324_ == 0)
{
lean_dec(v_word_2310_);
lean_dec(v_register_2309_);
lean_dec(v_outerAltitude_2308_);
return v___x_2324_;
}
else
{
goto v___jp_2311_;
}
}
else
{
goto v___jp_2311_;
}
v___jp_2311_:
{
lean_object* v___x_2312_; uint8_t v___x_2313_; 
v___x_2312_ = lean_unsigned_to_nat(0u);
v___x_2313_ = lean_nat_dec_eq(v_word_2310_, v___x_2312_);
if (v___x_2313_ == 0)
{
lean_object* v___x_2314_; uint8_t v___x_2315_; 
v___x_2314_ = lean_unsigned_to_nat(5u);
v___x_2315_ = lean_nat_dec_eq(v_register_2309_, v___x_2314_);
if (v___x_2315_ == 0)
{
lean_object* v___x_2316_; uint8_t v___x_2317_; 
lean_dec(v_outerAltitude_2308_);
v___x_2316_ = lean_unsigned_to_nat(101u);
v___x_2317_ = lean_nat_dec_eq(v_register_2309_, v___x_2316_);
if (v___x_2317_ == 0)
{
uint8_t v___x_2318_; 
v___x_2318_ = lp_lean1090_Lean1090_Impl_commBCoreEligible(v_register_2309_, v_word_2310_);
return v___x_2318_;
}
else
{
lean_dec(v_word_2310_);
lean_dec(v_register_2309_);
return v___x_2315_;
}
}
else
{
uint8_t v___x_2319_; 
lean_dec(v_register_2309_);
v___x_2319_ = lp_lean1090_Lean1090_Impl_commBPositionEligible(v_df_2307_, v_outerAltitude_2308_, v_word_2310_);
lean_dec(v_word_2310_);
return v___x_2319_;
}
}
else
{
uint8_t v___x_2320_; 
lean_dec(v_word_2310_);
lean_dec(v_register_2309_);
lean_dec(v_outerAltitude_2308_);
v___x_2320_ = 0;
return v___x_2320_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBEligible___boxed(lean_object* v_df_2325_, lean_object* v_outerAltitude_2326_, lean_object* v_register_2327_, lean_object* v_word_2328_){
_start:
{
uint8_t v_res_2329_; lean_object* v_r_2330_; 
v_res_2329_ = lp_lean1090_Lean1090_Impl_commBEligible(v_df_2325_, v_outerAltitude_2326_, v_register_2327_, v_word_2328_);
lean_dec(v_df_2325_);
v_r_2330_ = lean_box(v_res_2329_);
return v_r_2330_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBRegisters___closed__2(void){
_start:
{
lean_object* v___x_2337_; lean_object* v___x_2338_; lean_object* v___x_2339_; 
v___x_2337_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBRegisters___closed__1));
v___x_2338_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBRegisters___closed__0));
v___x_2339_ = l_List_appendTR___redArg(v___x_2338_, v___x_2337_);
return v___x_2339_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBRegisters(void){
_start:
{
lean_object* v___x_2340_; 
v___x_2340_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_commBRegisters___closed__2, &lp_lean1090_Lean1090_Impl_commBRegisters___closed__2_once, _init_lp_lean1090_Lean1090_Impl_commBRegisters___closed__2);
return v___x_2340_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(lean_object* v_df_2341_, lean_object* v_outerAltitude_2342_, lean_object* v_word_2343_, lean_object* v_a_2344_, lean_object* v_a_2345_){
_start:
{
if (lean_obj_tag(v_a_2344_) == 0)
{
lean_object* v___x_2346_; 
lean_dec(v_word_2343_);
lean_dec(v_outerAltitude_2342_);
v___x_2346_ = lean_array_to_list(v_a_2345_);
return v___x_2346_;
}
else
{
lean_object* v_head_2347_; lean_object* v_tail_2348_; lean_object* v___x_2350_; uint8_t v_isShared_2351_; uint8_t v_isSharedCheck_2362_; 
v_head_2347_ = lean_ctor_get(v_a_2344_, 0);
v_tail_2348_ = lean_ctor_get(v_a_2344_, 1);
v_isSharedCheck_2362_ = !lean_is_exclusive(v_a_2344_);
if (v_isSharedCheck_2362_ == 0)
{
v___x_2350_ = v_a_2344_;
v_isShared_2351_ = v_isSharedCheck_2362_;
goto v_resetjp_2349_;
}
else
{
lean_inc(v_tail_2348_);
lean_inc(v_head_2347_);
lean_dec(v_a_2344_);
v___x_2350_ = lean_box(0);
v_isShared_2351_ = v_isSharedCheck_2362_;
goto v_resetjp_2349_;
}
v_resetjp_2349_:
{
uint8_t v___x_2352_; 
lean_inc(v_word_2343_);
lean_inc(v_head_2347_);
lean_inc(v_outerAltitude_2342_);
v___x_2352_ = lp_lean1090_Lean1090_Impl_commBEligible(v_df_2341_, v_outerAltitude_2342_, v_head_2347_, v_word_2343_);
if (v___x_2352_ == 0)
{
lean_del_object(v___x_2350_);
lean_dec(v_head_2347_);
v_a_2344_ = v_tail_2348_;
goto _start;
}
else
{
lean_object* v___x_2354_; 
lean_inc(v_head_2347_);
v___x_2354_ = lp_lean1090_Lean1090_Impl_decodeBDS(v_head_2347_, v_word_2343_);
if (lean_obj_tag(v___x_2354_) == 0)
{
lean_del_object(v___x_2350_);
lean_dec(v_head_2347_);
v_a_2344_ = v_tail_2348_;
goto _start;
}
else
{
lean_object* v_val_2356_; lean_object* v___x_2358_; 
v_val_2356_ = lean_ctor_get(v___x_2354_, 0);
lean_inc(v_val_2356_);
lean_dec_ref_known(v___x_2354_, 1);
if (v_isShared_2351_ == 0)
{
lean_ctor_set_tag(v___x_2350_, 0);
lean_ctor_set(v___x_2350_, 1, v_val_2356_);
v___x_2358_ = v___x_2350_;
goto v_reusejp_2357_;
}
else
{
lean_object* v_reuseFailAlloc_2361_; 
v_reuseFailAlloc_2361_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2361_, 0, v_head_2347_);
lean_ctor_set(v_reuseFailAlloc_2361_, 1, v_val_2356_);
v___x_2358_ = v_reuseFailAlloc_2361_;
goto v_reusejp_2357_;
}
v_reusejp_2357_:
{
lean_object* v___x_2359_; 
v___x_2359_ = lean_array_push(v_a_2345_, v___x_2358_);
v_a_2344_ = v_tail_2348_;
v_a_2345_ = v___x_2359_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0___boxed(lean_object* v_df_2363_, lean_object* v_outerAltitude_2364_, lean_object* v_word_2365_, lean_object* v_a_2366_, lean_object* v_a_2367_){
_start:
{
lean_object* v_res_2368_; 
v_res_2368_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(v_df_2363_, v_outerAltitude_2364_, v_word_2365_, v_a_2366_, v_a_2367_);
lean_dec(v_df_2363_);
return v_res_2368_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_inferCommB(lean_object* v_df_2371_, lean_object* v_outerAltitude_2372_, lean_object* v_word_2373_){
_start:
{
lean_object* v___x_2374_; lean_object* v___x_2375_; lean_object* v___x_2376_; 
v___x_2374_ = lp_lean1090_Lean1090_Impl_commBRegisters;
v___x_2375_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_inferCommB___closed__0));
v___x_2376_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(v_df_2371_, v_outerAltitude_2372_, v_word_2373_, v___x_2374_, v___x_2375_);
return v___x_2376_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_inferCommB___boxed(lean_object* v_df_2377_, lean_object* v_outerAltitude_2378_, lean_object* v_word_2379_){
_start:
{
lean_object* v_res_2380_; 
v_res_2380_ = lp_lean1090_Lean1090_Impl_inferCommB(v_df_2377_, v_outerAltitude_2378_, v_word_2379_);
lean_dec(v_df_2377_);
return v_res_2380_;
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
lp_lean1090_Lean1090_Impl_cbSelectedValid40Table = _init_lp_lean1090_Lean1090_Impl_cbSelectedValid40Table();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbSelectedValid40Table);
lp_lean1090_Lean1090_Impl_cbQNHValid40Table = _init_lp_lean1090_Lean1090_Impl_cbQNHValid40Table();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbQNHValid40Table);
lp_lean1090_Lean1090_Impl_cbRollValid50Table = _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbRollValid50Table);
lp_lean1090_Lean1090_Impl_cbMachValid60Table = _init_lp_lean1090_Lean1090_Impl_cbMachValid60Table();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbMachValid60Table);
lp_lean1090_Lean1090_Impl_cbVerticalValid60Table = _init_lp_lean1090_Lean1090_Impl_cbVerticalValid60Table();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_cbVerticalValid60Table);
lp_lean1090_Lean1090_Impl_commBPayloadLimit = _init_lp_lean1090_Lean1090_Impl_commBPayloadLimit();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_commBPayloadLimit);
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
