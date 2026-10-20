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
lean_object* l_Rat_instNatCast___lam__0(lean_object*);
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
static const lean_string_object lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "heading"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "vrate_barometric"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "vrate_inertial"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "track"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__3_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "track_rate"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__4_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "temperature"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__5_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "selected_mcp"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__6_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "selected_fms"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__7_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "dte"};
static const lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__8_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__9;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0___boxed(lean_object*, lean_object*);
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
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__9(void){
_start:
{
lean_object* v___x_156_; lean_object* v___x_157_; 
v___x_156_ = lean_unsigned_to_nat(256u);
v___x_157_ = l_Rat_instNatCast___lam__0(v___x_156_);
return v___x_157_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue(lean_object* v_register_158_, lean_object* v_word_159_, lean_object* v_name_160_, lean_object* v_value_161_){
_start:
{
lean_object* v___x_165_; uint8_t v___x_166_; 
v___x_165_ = lean_unsigned_to_nat(16u);
v___x_166_ = lean_nat_dec_eq(v_register_158_, v___x_165_);
if (v___x_166_ == 0)
{
lean_object* v___x_167_; uint8_t v___x_168_; 
v___x_167_ = lean_unsigned_to_nat(64u);
v___x_168_ = lean_nat_dec_eq(v_register_158_, v___x_167_);
if (v___x_168_ == 0)
{
lean_object* v___x_169_; uint8_t v___x_170_; 
v___x_169_ = lean_unsigned_to_nat(68u);
v___x_170_ = lean_nat_dec_eq(v_register_158_, v___x_169_);
if (v___x_170_ == 0)
{
lean_object* v___x_171_; uint8_t v___x_172_; 
v___x_171_ = lean_unsigned_to_nat(80u);
v___x_172_ = lean_nat_dec_eq(v_register_158_, v___x_171_);
if (v___x_172_ == 0)
{
lean_object* v___x_173_; uint8_t v___x_174_; 
v___x_173_ = lean_unsigned_to_nat(96u);
v___x_174_ = lean_nat_dec_eq(v_register_158_, v___x_173_);
if (v___x_174_ == 0)
{
lean_object* v___x_175_; 
v___x_175_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_175_, 0, v_value_161_);
return v___x_175_;
}
else
{
lean_object* v___x_176_; uint8_t v___x_177_; 
v___x_176_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__0));
v___x_177_ = lean_string_dec_eq(v_name_160_, v___x_176_);
if (v___x_177_ == 0)
{
lean_object* v___x_178_; uint8_t v___x_179_; 
v___x_178_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__1));
v___x_179_ = lean_string_dec_eq(v_name_160_, v___x_178_);
if (v___x_179_ == 0)
{
lean_object* v___x_180_; uint8_t v___x_181_; 
v___x_180_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__2));
v___x_181_ = lean_string_dec_eq(v_name_160_, v___x_180_);
if (v___x_181_ == 0)
{
lean_object* v___x_182_; 
v___x_182_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_182_, 0, v_value_161_);
return v___x_182_;
}
else
{
lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_185_; 
lean_dec_ref(v_value_161_);
v___x_183_ = lean_unsigned_to_nat(47u);
v___x_184_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_159_, v___x_183_);
v___x_185_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_185_, 0, v___x_184_);
return v___x_185_;
}
}
else
{
lean_object* v___x_186_; lean_object* v___x_187_; lean_object* v___x_188_; 
lean_dec_ref(v_value_161_);
v___x_186_ = lean_unsigned_to_nat(36u);
v___x_187_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_159_, v___x_186_);
v___x_188_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_188_, 0, v___x_187_);
return v___x_188_;
}
}
else
{
goto v___jp_162_;
}
}
}
else
{
lean_object* v___x_189_; uint8_t v___x_190_; 
v___x_189_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__3));
v___x_190_ = lean_string_dec_eq(v_name_160_, v___x_189_);
if (v___x_190_ == 0)
{
lean_object* v___x_191_; uint8_t v___x_192_; 
v___x_191_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__4));
v___x_192_ = lean_string_dec_eq(v_name_160_, v___x_191_);
if (v___x_192_ == 0)
{
lean_object* v___x_193_; 
v___x_193_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_193_, 0, v_value_161_);
return v___x_193_;
}
else
{
lean_object* v___x_194_; lean_object* v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; uint8_t v___x_198_; 
v___x_194_ = lean_unsigned_to_nat(37u);
v___x_195_ = lean_unsigned_to_nat(9u);
v___x_196_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_159_, v___x_194_, v___x_195_);
v___x_197_ = lean_unsigned_to_nat(511u);
v___x_198_ = lean_nat_dec_eq(v___x_196_, v___x_197_);
lean_dec(v___x_196_);
if (v___x_198_ == 0)
{
lean_object* v___x_199_; 
v___x_199_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_199_, 0, v_value_161_);
return v___x_199_;
}
else
{
lean_object* v___x_200_; 
lean_dec_ref(v_value_161_);
v___x_200_ = lean_box(0);
return v___x_200_;
}
}
}
else
{
goto v___jp_162_;
}
}
}
else
{
lean_object* v___x_201_; uint8_t v___x_202_; 
v___x_201_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__5));
v___x_202_ = lean_string_dec_eq(v_name_160_, v___x_201_);
if (v___x_202_ == 0)
{
lean_object* v___x_203_; 
v___x_203_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_203_, 0, v_value_161_);
return v___x_203_;
}
else
{
lean_object* v___x_204_; lean_object* v___x_205_; 
lean_dec_ref(v_value_161_);
v___x_204_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_159_);
v___x_205_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_205_, 0, v___x_204_);
return v___x_205_;
}
}
}
else
{
lean_object* v___x_206_; uint8_t v___x_207_; 
v___x_206_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__6));
v___x_207_ = lean_string_dec_eq(v_name_160_, v___x_206_);
if (v___x_207_ == 0)
{
lean_object* v___x_208_; uint8_t v___x_209_; 
v___x_208_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__7));
v___x_209_ = lean_string_dec_eq(v_name_160_, v___x_208_);
if (v___x_209_ == 0)
{
lean_object* v___x_210_; 
v___x_210_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_210_, 0, v_value_161_);
return v___x_210_;
}
else
{
lean_object* v___x_211_; lean_object* v___x_212_; lean_object* v___x_213_; lean_object* v___x_214_; lean_object* v___x_215_; 
lean_dec_ref(v_value_161_);
v___x_211_ = lean_unsigned_to_nat(15u);
v___x_212_ = lean_unsigned_to_nat(12u);
v___x_213_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_159_, v___x_211_, v___x_212_);
v___x_214_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_213_);
lean_dec(v___x_213_);
v___x_215_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_215_, 0, v___x_214_);
return v___x_215_;
}
}
else
{
lean_object* v___x_216_; lean_object* v___x_217_; lean_object* v___x_218_; lean_object* v___x_219_; lean_object* v___x_220_; 
lean_dec_ref(v_value_161_);
v___x_216_ = lean_unsigned_to_nat(2u);
v___x_217_ = lean_unsigned_to_nat(12u);
v___x_218_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_159_, v___x_216_, v___x_217_);
v___x_219_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_218_);
lean_dec(v___x_218_);
v___x_220_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_220_, 0, v___x_219_);
return v___x_220_;
}
}
}
else
{
lean_object* v___x_221_; uint8_t v___x_222_; 
v___x_221_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__8));
v___x_222_ = lean_string_dec_eq(v_name_160_, v___x_221_);
if (v___x_222_ == 0)
{
lean_object* v___x_223_; 
v___x_223_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_223_, 0, v_value_161_);
return v___x_223_;
}
else
{
lean_object* v___x_224_; lean_object* v___x_225_; lean_object* v___x_226_; lean_object* v___x_227_; lean_object* v___x_228_; lean_object* v___x_229_; lean_object* v___x_230_; lean_object* v___x_231_; lean_object* v___x_232_; lean_object* v___x_233_; lean_object* v___x_234_; 
lean_dec_ref(v_value_161_);
v___x_224_ = lean_unsigned_to_nat(41u);
v___x_225_ = lean_unsigned_to_nat(8u);
v___x_226_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_159_, v___x_224_, v___x_225_);
v___x_227_ = l_Rat_instNatCast___lam__0(v___x_226_);
v___x_228_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__9, &lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__9_once, _init_lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__9);
v___x_229_ = lean_unsigned_to_nat(49u);
v___x_230_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_159_, v___x_229_, v___x_225_);
v___x_231_ = l_Rat_instNatCast___lam__0(v___x_230_);
v___x_232_ = l_Rat_mul(v___x_228_, v___x_231_);
v___x_233_ = l_Rat_add(v___x_227_, v___x_232_);
v___x_234_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_234_, 0, v___x_233_);
return v___x_234_;
}
}
v___jp_162_:
{
lean_object* v___x_163_; lean_object* v___x_164_; 
v___x_163_ = lp_lean1090_Lean1090_Impl_cbWrapAngle(v_value_161_);
v___x_164_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_164_, 0, v___x_163_);
return v___x_164_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBAdjustValue___boxed(lean_object* v_register_235_, lean_object* v_word_236_, lean_object* v_name_237_, lean_object* v_value_238_){
_start:
{
lean_object* v_res_239_; 
v_res_239_ = lp_lean1090_Lean1090_Impl_commBAdjustValue(v_register_235_, v_word_236_, v_name_237_, v_value_238_);
lean_dec_ref(v_name_237_);
lean_dec(v_word_236_);
lean_dec(v_register_235_);
return v_res_239_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(lean_object* v_name_240_, lean_object* v_x_241_){
_start:
{
if (lean_obj_tag(v_x_241_) == 0)
{
lean_object* v___x_242_; 
v___x_242_ = lean_box(0);
return v___x_242_;
}
else
{
lean_object* v_head_243_; lean_object* v_tail_244_; lean_object* v_name_245_; uint8_t v___x_246_; 
v_head_243_ = lean_ctor_get(v_x_241_, 0);
v_tail_244_ = lean_ctor_get(v_x_241_, 1);
v_name_245_ = lean_ctor_get(v_head_243_, 0);
v___x_246_ = lean_string_dec_eq(v_name_245_, v_name_240_);
if (v___x_246_ == 0)
{
v_x_241_ = v_tail_244_;
goto _start;
}
else
{
lean_object* v___x_248_; 
lean_inc(v_head_243_);
v___x_248_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_248_, 0, v_head_243_);
return v___x_248_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0___boxed(lean_object* v_name_249_, lean_object* v_x_250_){
_start:
{
lean_object* v_res_251_; 
v_res_251_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(v_name_249_, v_x_250_);
lean_dec(v_x_250_);
lean_dec_ref(v_name_249_);
return v_res_251_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBValue(lean_object* v_register_252_, lean_object* v_word_253_, lean_object* v_name_254_){
_start:
{
lean_object* v___x_255_; 
v___x_255_ = lp_lean1090_Lean1090_Impl_commBLayout(v_register_252_);
if (lean_obj_tag(v___x_255_) == 0)
{
lean_object* v___x_256_; 
v___x_256_ = lean_box(0);
return v___x_256_;
}
else
{
lean_object* v_val_257_; lean_object* v___x_258_; 
v_val_257_ = lean_ctor_get(v___x_255_, 0);
lean_inc(v_val_257_);
lean_dec_ref_known(v___x_255_, 1);
v___x_258_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(v_name_254_, v_val_257_);
lean_dec(v_val_257_);
if (lean_obj_tag(v___x_258_) == 0)
{
lean_object* v___x_259_; 
v___x_259_ = lean_box(0);
return v___x_259_;
}
else
{
lean_object* v_val_260_; lean_object* v___x_262_; uint8_t v_isShared_263_; uint8_t v_isSharedCheck_376_; 
v_val_260_ = lean_ctor_get(v___x_258_, 0);
v_isSharedCheck_376_ = !lean_is_exclusive(v___x_258_);
if (v_isSharedCheck_376_ == 0)
{
v___x_262_ = v___x_258_;
v_isShared_263_ = v_isSharedCheck_376_;
goto v_resetjp_261_;
}
else
{
lean_inc(v_val_260_);
lean_dec(v___x_258_);
v___x_262_ = lean_box(0);
v_isShared_263_ = v_isSharedCheck_376_;
goto v_resetjp_261_;
}
v_resetjp_261_:
{
lean_object* v___x_264_; 
v___x_264_ = lp_lean1090_Lean1090_Impl_payloadValue(v_val_260_, v_word_253_);
if (lean_obj_tag(v___x_264_) == 0)
{
lean_del_object(v___x_262_);
return v___x_264_;
}
else
{
lean_object* v_val_265_; lean_object* v___x_271_; uint8_t v___x_272_; 
v_val_265_ = lean_ctor_get(v___x_264_, 0);
lean_inc(v_val_265_);
v___x_271_ = lean_unsigned_to_nat(16u);
v___x_272_ = lean_nat_dec_eq(v_register_252_, v___x_271_);
if (v___x_272_ == 0)
{
lean_object* v___x_273_; uint8_t v___x_274_; 
v___x_273_ = lean_unsigned_to_nat(64u);
v___x_274_ = lean_nat_dec_eq(v_register_252_, v___x_273_);
if (v___x_274_ == 0)
{
lean_object* v___x_275_; uint8_t v___x_276_; 
v___x_275_ = lean_unsigned_to_nat(68u);
v___x_276_ = lean_nat_dec_eq(v_register_252_, v___x_275_);
if (v___x_276_ == 0)
{
lean_object* v___x_277_; uint8_t v___x_278_; 
v___x_277_ = lean_unsigned_to_nat(80u);
v___x_278_ = lean_nat_dec_eq(v_register_252_, v___x_277_);
if (v___x_278_ == 0)
{
lean_object* v___x_279_; uint8_t v___x_280_; 
v___x_279_ = lean_unsigned_to_nat(96u);
v___x_280_ = lean_nat_dec_eq(v_register_252_, v___x_279_);
if (v___x_280_ == 0)
{
lean_dec(v_val_265_);
lean_del_object(v___x_262_);
return v___x_264_;
}
else
{
lean_object* v___x_281_; uint8_t v___x_282_; 
v___x_281_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__0));
v___x_282_ = lean_string_dec_eq(v_name_254_, v___x_281_);
if (v___x_282_ == 0)
{
lean_object* v___x_283_; uint8_t v___x_284_; 
lean_dec(v_val_265_);
lean_del_object(v___x_262_);
v___x_283_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__1));
v___x_284_ = lean_string_dec_eq(v_name_254_, v___x_283_);
if (v___x_284_ == 0)
{
lean_object* v___x_285_; uint8_t v___x_286_; 
v___x_285_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__2));
v___x_286_ = lean_string_dec_eq(v_name_254_, v___x_285_);
if (v___x_286_ == 0)
{
return v___x_264_;
}
else
{
lean_object* v___x_288_; uint8_t v_isShared_289_; uint8_t v_isSharedCheck_295_; 
v_isSharedCheck_295_ = !lean_is_exclusive(v___x_264_);
if (v_isSharedCheck_295_ == 0)
{
lean_object* v_unused_296_; 
v_unused_296_ = lean_ctor_get(v___x_264_, 0);
lean_dec(v_unused_296_);
v___x_288_ = v___x_264_;
v_isShared_289_ = v_isSharedCheck_295_;
goto v_resetjp_287_;
}
else
{
lean_dec(v___x_264_);
v___x_288_ = lean_box(0);
v_isShared_289_ = v_isSharedCheck_295_;
goto v_resetjp_287_;
}
v_resetjp_287_:
{
lean_object* v___x_290_; lean_object* v___x_291_; lean_object* v___x_293_; 
v___x_290_ = lean_unsigned_to_nat(47u);
v___x_291_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_253_, v___x_290_);
if (v_isShared_289_ == 0)
{
lean_ctor_set(v___x_288_, 0, v___x_291_);
v___x_293_ = v___x_288_;
goto v_reusejp_292_;
}
else
{
lean_object* v_reuseFailAlloc_294_; 
v_reuseFailAlloc_294_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_294_, 0, v___x_291_);
v___x_293_ = v_reuseFailAlloc_294_;
goto v_reusejp_292_;
}
v_reusejp_292_:
{
return v___x_293_;
}
}
}
}
else
{
lean_object* v___x_298_; uint8_t v_isShared_299_; uint8_t v_isSharedCheck_305_; 
v_isSharedCheck_305_ = !lean_is_exclusive(v___x_264_);
if (v_isSharedCheck_305_ == 0)
{
lean_object* v_unused_306_; 
v_unused_306_ = lean_ctor_get(v___x_264_, 0);
lean_dec(v_unused_306_);
v___x_298_ = v___x_264_;
v_isShared_299_ = v_isSharedCheck_305_;
goto v_resetjp_297_;
}
else
{
lean_dec(v___x_264_);
v___x_298_ = lean_box(0);
v_isShared_299_ = v_isSharedCheck_305_;
goto v_resetjp_297_;
}
v_resetjp_297_:
{
lean_object* v___x_300_; lean_object* v___x_301_; lean_object* v___x_303_; 
v___x_300_ = lean_unsigned_to_nat(36u);
v___x_301_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_253_, v___x_300_);
if (v_isShared_299_ == 0)
{
lean_ctor_set(v___x_298_, 0, v___x_301_);
v___x_303_ = v___x_298_;
goto v_reusejp_302_;
}
else
{
lean_object* v_reuseFailAlloc_304_; 
v_reuseFailAlloc_304_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_304_, 0, v___x_301_);
v___x_303_ = v_reuseFailAlloc_304_;
goto v_reusejp_302_;
}
v_reusejp_302_:
{
return v___x_303_;
}
}
}
}
else
{
lean_dec_ref_known(v___x_264_, 1);
goto v___jp_266_;
}
}
}
else
{
lean_object* v___x_307_; uint8_t v___x_308_; 
v___x_307_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__3));
v___x_308_ = lean_string_dec_eq(v_name_254_, v___x_307_);
if (v___x_308_ == 0)
{
lean_object* v___x_309_; uint8_t v___x_310_; 
lean_dec(v_val_265_);
lean_del_object(v___x_262_);
v___x_309_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__4));
v___x_310_ = lean_string_dec_eq(v_name_254_, v___x_309_);
if (v___x_310_ == 0)
{
return v___x_264_;
}
else
{
lean_object* v___x_311_; lean_object* v___x_312_; lean_object* v___x_313_; lean_object* v___x_314_; uint8_t v___x_315_; 
v___x_311_ = lean_unsigned_to_nat(37u);
v___x_312_ = lean_unsigned_to_nat(9u);
v___x_313_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_253_, v___x_311_, v___x_312_);
v___x_314_ = lean_unsigned_to_nat(511u);
v___x_315_ = lean_nat_dec_eq(v___x_313_, v___x_314_);
lean_dec(v___x_313_);
if (v___x_315_ == 0)
{
return v___x_264_;
}
else
{
lean_object* v___x_316_; 
lean_dec_ref_known(v___x_264_, 1);
v___x_316_ = lean_box(0);
return v___x_316_;
}
}
}
else
{
lean_dec_ref_known(v___x_264_, 1);
goto v___jp_266_;
}
}
}
else
{
lean_object* v___x_317_; uint8_t v___x_318_; 
lean_dec(v_val_265_);
lean_del_object(v___x_262_);
v___x_317_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__5));
v___x_318_ = lean_string_dec_eq(v_name_254_, v___x_317_);
if (v___x_318_ == 0)
{
return v___x_264_;
}
else
{
lean_object* v___x_320_; uint8_t v_isShared_321_; uint8_t v_isSharedCheck_326_; 
v_isSharedCheck_326_ = !lean_is_exclusive(v___x_264_);
if (v_isSharedCheck_326_ == 0)
{
lean_object* v_unused_327_; 
v_unused_327_ = lean_ctor_get(v___x_264_, 0);
lean_dec(v_unused_327_);
v___x_320_ = v___x_264_;
v_isShared_321_ = v_isSharedCheck_326_;
goto v_resetjp_319_;
}
else
{
lean_dec(v___x_264_);
v___x_320_ = lean_box(0);
v_isShared_321_ = v_isSharedCheck_326_;
goto v_resetjp_319_;
}
v_resetjp_319_:
{
lean_object* v___x_322_; lean_object* v___x_324_; 
v___x_322_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_253_);
if (v_isShared_321_ == 0)
{
lean_ctor_set(v___x_320_, 0, v___x_322_);
v___x_324_ = v___x_320_;
goto v_reusejp_323_;
}
else
{
lean_object* v_reuseFailAlloc_325_; 
v_reuseFailAlloc_325_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_325_, 0, v___x_322_);
v___x_324_ = v_reuseFailAlloc_325_;
goto v_reusejp_323_;
}
v_reusejp_323_:
{
return v___x_324_;
}
}
}
}
}
else
{
lean_object* v___x_328_; uint8_t v___x_329_; 
lean_dec(v_val_265_);
lean_del_object(v___x_262_);
v___x_328_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__6));
v___x_329_ = lean_string_dec_eq(v_name_254_, v___x_328_);
if (v___x_329_ == 0)
{
lean_object* v___x_330_; uint8_t v___x_331_; 
v___x_330_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__7));
v___x_331_ = lean_string_dec_eq(v_name_254_, v___x_330_);
if (v___x_331_ == 0)
{
return v___x_264_;
}
else
{
lean_object* v___x_333_; uint8_t v_isShared_334_; uint8_t v_isSharedCheck_342_; 
v_isSharedCheck_342_ = !lean_is_exclusive(v___x_264_);
if (v_isSharedCheck_342_ == 0)
{
lean_object* v_unused_343_; 
v_unused_343_ = lean_ctor_get(v___x_264_, 0);
lean_dec(v_unused_343_);
v___x_333_ = v___x_264_;
v_isShared_334_ = v_isSharedCheck_342_;
goto v_resetjp_332_;
}
else
{
lean_dec(v___x_264_);
v___x_333_ = lean_box(0);
v_isShared_334_ = v_isSharedCheck_342_;
goto v_resetjp_332_;
}
v_resetjp_332_:
{
lean_object* v___x_335_; lean_object* v___x_336_; lean_object* v___x_337_; lean_object* v___x_338_; lean_object* v___x_340_; 
v___x_335_ = lean_unsigned_to_nat(15u);
v___x_336_ = lean_unsigned_to_nat(12u);
v___x_337_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_253_, v___x_335_, v___x_336_);
v___x_338_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_337_);
lean_dec(v___x_337_);
if (v_isShared_334_ == 0)
{
lean_ctor_set(v___x_333_, 0, v___x_338_);
v___x_340_ = v___x_333_;
goto v_reusejp_339_;
}
else
{
lean_object* v_reuseFailAlloc_341_; 
v_reuseFailAlloc_341_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_341_, 0, v___x_338_);
v___x_340_ = v_reuseFailAlloc_341_;
goto v_reusejp_339_;
}
v_reusejp_339_:
{
return v___x_340_;
}
}
}
}
else
{
lean_object* v___x_345_; uint8_t v_isShared_346_; uint8_t v_isSharedCheck_354_; 
v_isSharedCheck_354_ = !lean_is_exclusive(v___x_264_);
if (v_isSharedCheck_354_ == 0)
{
lean_object* v_unused_355_; 
v_unused_355_ = lean_ctor_get(v___x_264_, 0);
lean_dec(v_unused_355_);
v___x_345_ = v___x_264_;
v_isShared_346_ = v_isSharedCheck_354_;
goto v_resetjp_344_;
}
else
{
lean_dec(v___x_264_);
v___x_345_ = lean_box(0);
v_isShared_346_ = v_isSharedCheck_354_;
goto v_resetjp_344_;
}
v_resetjp_344_:
{
lean_object* v___x_347_; lean_object* v___x_348_; lean_object* v___x_349_; lean_object* v___x_350_; lean_object* v___x_352_; 
v___x_347_ = lean_unsigned_to_nat(2u);
v___x_348_ = lean_unsigned_to_nat(12u);
v___x_349_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_253_, v___x_347_, v___x_348_);
v___x_350_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_349_);
lean_dec(v___x_349_);
if (v_isShared_346_ == 0)
{
lean_ctor_set(v___x_345_, 0, v___x_350_);
v___x_352_ = v___x_345_;
goto v_reusejp_351_;
}
else
{
lean_object* v_reuseFailAlloc_353_; 
v_reuseFailAlloc_353_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_353_, 0, v___x_350_);
v___x_352_ = v_reuseFailAlloc_353_;
goto v_reusejp_351_;
}
v_reusejp_351_:
{
return v___x_352_;
}
}
}
}
}
else
{
lean_object* v___x_356_; uint8_t v___x_357_; 
lean_dec(v_val_265_);
lean_del_object(v___x_262_);
v___x_356_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__8));
v___x_357_ = lean_string_dec_eq(v_name_254_, v___x_356_);
if (v___x_357_ == 0)
{
return v___x_264_;
}
else
{
lean_object* v___x_359_; uint8_t v_isShared_360_; uint8_t v_isSharedCheck_374_; 
v_isSharedCheck_374_ = !lean_is_exclusive(v___x_264_);
if (v_isSharedCheck_374_ == 0)
{
lean_object* v_unused_375_; 
v_unused_375_ = lean_ctor_get(v___x_264_, 0);
lean_dec(v_unused_375_);
v___x_359_ = v___x_264_;
v_isShared_360_ = v_isSharedCheck_374_;
goto v_resetjp_358_;
}
else
{
lean_dec(v___x_264_);
v___x_359_ = lean_box(0);
v_isShared_360_ = v_isSharedCheck_374_;
goto v_resetjp_358_;
}
v_resetjp_358_:
{
lean_object* v___x_361_; lean_object* v___x_362_; lean_object* v___x_363_; lean_object* v___x_364_; lean_object* v___x_365_; lean_object* v___x_366_; lean_object* v___x_367_; lean_object* v___x_368_; lean_object* v___x_369_; lean_object* v___x_370_; lean_object* v___x_372_; 
v___x_361_ = lean_unsigned_to_nat(41u);
v___x_362_ = lean_unsigned_to_nat(8u);
v___x_363_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_253_, v___x_361_, v___x_362_);
v___x_364_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_363_);
v___x_365_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_366_ = lean_unsigned_to_nat(49u);
v___x_367_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_253_, v___x_366_, v___x_362_);
v___x_368_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_367_);
v___x_369_ = l_Rat_mul(v___x_365_, v___x_368_);
v___x_370_ = l_Rat_add(v___x_364_, v___x_369_);
if (v_isShared_360_ == 0)
{
lean_ctor_set(v___x_359_, 0, v___x_370_);
v___x_372_ = v___x_359_;
goto v_reusejp_371_;
}
else
{
lean_object* v_reuseFailAlloc_373_; 
v_reuseFailAlloc_373_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_373_, 0, v___x_370_);
v___x_372_ = v_reuseFailAlloc_373_;
goto v_reusejp_371_;
}
v_reusejp_371_:
{
return v___x_372_;
}
}
}
}
v___jp_266_:
{
lean_object* v___x_267_; lean_object* v___x_269_; 
v___x_267_ = lp_lean1090_Lean1090_Impl_cbWrapAngle(v_val_265_);
if (v_isShared_263_ == 0)
{
lean_ctor_set(v___x_262_, 0, v___x_267_);
v___x_269_ = v___x_262_;
goto v_reusejp_268_;
}
else
{
lean_object* v_reuseFailAlloc_270_; 
v_reuseFailAlloc_270_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_270_, 0, v___x_267_);
v___x_269_ = v_reuseFailAlloc_270_;
goto v_reusejp_268_;
}
v_reusejp_268_:
{
return v___x_269_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBValue___boxed(lean_object* v_register_377_, lean_object* v_word_378_, lean_object* v_name_379_){
_start:
{
lean_object* v_res_380_; 
v_res_380_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_377_, v_word_378_, v_name_379_);
lean_dec_ref(v_name_379_);
lean_dec(v_word_378_);
lean_dec(v_register_377_);
return v_res_380_;
}
}
LEAN_EXPORT uint32_t lp_lean1090_Lean1090_Impl_cbCharacter(lean_object* v_code_381_){
_start:
{
lean_object* v___x_393_; uint8_t v___x_394_; 
v___x_393_ = lean_unsigned_to_nat(1u);
v___x_394_ = lean_nat_dec_le(v___x_393_, v_code_381_);
if (v___x_394_ == 0)
{
goto v___jp_387_;
}
else
{
lean_object* v___x_395_; uint8_t v___x_396_; 
v___x_395_ = lean_unsigned_to_nat(26u);
v___x_396_ = lean_nat_dec_le(v_code_381_, v___x_395_);
if (v___x_396_ == 0)
{
goto v___jp_387_;
}
else
{
lean_object* v___x_397_; lean_object* v___x_398_; uint32_t v___x_399_; 
v___x_397_ = lean_unsigned_to_nat(64u);
v___x_398_ = lean_nat_add(v___x_397_, v_code_381_);
v___x_399_ = l_Char_ofNat(v___x_398_);
lean_dec(v___x_398_);
return v___x_399_;
}
}
v___jp_382_:
{
lean_object* v___x_383_; uint8_t v___x_384_; 
v___x_383_ = lean_unsigned_to_nat(32u);
v___x_384_ = lean_nat_dec_eq(v_code_381_, v___x_383_);
if (v___x_384_ == 0)
{
uint32_t v___x_385_; 
v___x_385_ = 35;
return v___x_385_;
}
else
{
uint32_t v___x_386_; 
v___x_386_ = 32;
return v___x_386_;
}
}
v___jp_387_:
{
lean_object* v___x_388_; uint8_t v___x_389_; 
v___x_388_ = lean_unsigned_to_nat(48u);
v___x_389_ = lean_nat_dec_le(v___x_388_, v_code_381_);
if (v___x_389_ == 0)
{
goto v___jp_382_;
}
else
{
lean_object* v___x_390_; uint8_t v___x_391_; 
v___x_390_ = lean_unsigned_to_nat(57u);
v___x_391_ = lean_nat_dec_le(v_code_381_, v___x_390_);
if (v___x_391_ == 0)
{
goto v___jp_382_;
}
else
{
uint32_t v___x_392_; 
v___x_392_ = l_Char_ofNat(v_code_381_);
return v___x_392_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCharacter___boxed(lean_object* v_code_400_){
_start:
{
uint32_t v_res_401_; lean_object* v_r_402_; 
v_res_401_ = lp_lean1090_Lean1090_Impl_cbCharacter(v_code_400_);
lean_dec(v_code_400_);
v_r_402_ = lean_box_uint32(v_res_401_);
return v_r_402_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(lean_object* v_a_403_, lean_object* v_a_404_){
_start:
{
if (lean_obj_tag(v_a_403_) == 0)
{
lean_object* v___x_405_; 
v___x_405_ = l_List_reverse___redArg(v_a_404_);
return v___x_405_;
}
else
{
lean_object* v_head_406_; lean_object* v_tail_407_; lean_object* v___x_409_; uint8_t v_isShared_410_; uint8_t v_isSharedCheck_417_; 
v_head_406_ = lean_ctor_get(v_a_403_, 0);
v_tail_407_ = lean_ctor_get(v_a_403_, 1);
v_isSharedCheck_417_ = !lean_is_exclusive(v_a_403_);
if (v_isSharedCheck_417_ == 0)
{
v___x_409_ = v_a_403_;
v_isShared_410_ = v_isSharedCheck_417_;
goto v_resetjp_408_;
}
else
{
lean_inc(v_tail_407_);
lean_inc(v_head_406_);
lean_dec(v_a_403_);
v___x_409_ = lean_box(0);
v_isShared_410_ = v_isSharedCheck_417_;
goto v_resetjp_408_;
}
v_resetjp_408_:
{
uint32_t v___x_411_; lean_object* v___x_412_; lean_object* v___x_414_; 
v___x_411_ = lp_lean1090_Lean1090_Impl_cbCharacter(v_head_406_);
lean_dec(v_head_406_);
v___x_412_ = lean_box_uint32(v___x_411_);
if (v_isShared_410_ == 0)
{
lean_ctor_set(v___x_409_, 1, v_a_404_);
lean_ctor_set(v___x_409_, 0, v___x_412_);
v___x_414_ = v___x_409_;
goto v_reusejp_413_;
}
else
{
lean_object* v_reuseFailAlloc_416_; 
v_reuseFailAlloc_416_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_416_, 0, v___x_412_);
lean_ctor_set(v_reuseFailAlloc_416_, 1, v_a_404_);
v___x_414_ = v_reuseFailAlloc_416_;
goto v_reusejp_413_;
}
v_reusejp_413_:
{
v_a_403_ = v_tail_407_;
v_a_404_ = v___x_414_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbCallsign_spec__0(lean_object* v_a_418_, lean_object* v_a_419_){
_start:
{
if (lean_obj_tag(v_a_418_) == 0)
{
lean_object* v___x_420_; 
v___x_420_ = l_List_reverse___redArg(v_a_419_);
return v___x_420_;
}
else
{
lean_object* v_head_421_; lean_object* v_tail_422_; lean_object* v___x_424_; uint8_t v_isShared_425_; uint8_t v_isSharedCheck_433_; 
v_head_421_ = lean_ctor_get(v_a_418_, 0);
v_tail_422_ = lean_ctor_get(v_a_418_, 1);
v_isSharedCheck_433_ = !lean_is_exclusive(v_a_418_);
if (v_isSharedCheck_433_ == 0)
{
v___x_424_ = v_a_418_;
v_isShared_425_ = v_isSharedCheck_433_;
goto v_resetjp_423_;
}
else
{
lean_inc(v_tail_422_);
lean_inc(v_head_421_);
lean_dec(v_a_418_);
v___x_424_ = lean_box(0);
v_isShared_425_ = v_isSharedCheck_433_;
goto v_resetjp_423_;
}
v_resetjp_423_:
{
lean_object* v___x_426_; uint8_t v___x_427_; 
v___x_426_ = lean_unsigned_to_nat(32u);
v___x_427_ = lean_nat_dec_eq(v_head_421_, v___x_426_);
if (v___x_427_ == 0)
{
lean_object* v___x_429_; 
if (v_isShared_425_ == 0)
{
lean_ctor_set(v___x_424_, 1, v_a_419_);
v___x_429_ = v___x_424_;
goto v_reusejp_428_;
}
else
{
lean_object* v_reuseFailAlloc_431_; 
v_reuseFailAlloc_431_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_431_, 0, v_head_421_);
lean_ctor_set(v_reuseFailAlloc_431_, 1, v_a_419_);
v___x_429_ = v_reuseFailAlloc_431_;
goto v_reusejp_428_;
}
v_reusejp_428_:
{
v_a_418_ = v_tail_422_;
v_a_419_ = v___x_429_;
goto _start;
}
}
else
{
lean_del_object(v___x_424_);
lean_dec(v_head_421_);
v_a_418_ = v_tail_422_;
goto _start;
}
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbCallsign___closed__0(void){
_start:
{
lean_object* v___x_434_; lean_object* v___x_435_; 
v___x_434_ = lean_unsigned_to_nat(8u);
v___x_435_ = l_List_range(v___x_434_);
return v___x_435_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCallsign(lean_object* v_word_436_){
_start:
{
lean_object* v___x_437_; lean_object* v___x_438_; lean_object* v___x_439_; lean_object* v___x_440_; lean_object* v___x_441_; lean_object* v___x_442_; 
v___x_437_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbCallsign___closed__0, &lp_lean1090_Lean1090_Impl_cbCallsign___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbCallsign___closed__0);
v___x_438_ = lean_box(0);
v___x_439_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_adsbCallsign_spec__0(v_word_436_, v___x_437_, v___x_438_);
v___x_440_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbCallsign_spec__0(v___x_439_, v___x_438_);
v___x_441_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(v___x_440_, v___x_438_);
v___x_442_ = lean_string_mk(v___x_441_);
return v___x_442_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCallsign___boxed(lean_object* v_word_443_){
_start:
{
lean_object* v_res_444_; 
v_res_444_ = lp_lean1090_Lean1090_Impl_cbCallsign(v_word_443_);
lean_dec(v_word_443_);
return v_res_444_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbThreat(lean_object* v_word_445_){
_start:
{
lean_object* v___x_446_; lean_object* v___x_447_; lean_object* v___x_448_; lean_object* v___x_449_; uint8_t v___x_450_; 
v___x_446_ = lean_unsigned_to_nat(29u);
v___x_447_ = lean_unsigned_to_nat(2u);
v___x_448_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_445_, v___x_446_, v___x_447_);
v___x_449_ = lean_unsigned_to_nat(0u);
v___x_450_ = lean_nat_dec_eq(v___x_448_, v___x_449_);
if (v___x_450_ == 0)
{
lean_object* v___x_451_; uint8_t v___x_452_; 
v___x_451_ = lean_unsigned_to_nat(1u);
v___x_452_ = lean_nat_dec_eq(v___x_448_, v___x_451_);
if (v___x_452_ == 0)
{
uint8_t v___x_453_; 
v___x_453_ = lean_nat_dec_eq(v___x_448_, v___x_447_);
lean_dec(v___x_448_);
if (v___x_453_ == 0)
{
lean_object* v___x_454_; 
v___x_454_ = lean_box(3);
return v___x_454_;
}
else
{
lean_object* v___x_455_; lean_object* v___x_456_; lean_object* v_range_457_; lean_object* v___x_458_; lean_object* v___x_459_; lean_object* v_bearing_460_; lean_object* v___x_461_; lean_object* v___x_462_; lean_object* v___x_463_; lean_object* v___x_464_; lean_object* v___y_466_; uint8_t v___x_476_; 
v___x_455_ = lean_unsigned_to_nat(44u);
v___x_456_ = lean_unsigned_to_nat(7u);
v_range_457_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_445_, v___x_455_, v___x_456_);
v___x_458_ = lean_unsigned_to_nat(51u);
v___x_459_ = lean_unsigned_to_nat(6u);
v_bearing_460_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_445_, v___x_458_, v___x_459_);
v___x_461_ = lean_unsigned_to_nat(31u);
v___x_462_ = lean_unsigned_to_nat(13u);
v___x_463_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_445_, v___x_461_, v___x_462_);
v___x_464_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v___x_463_);
lean_dec(v___x_463_);
v___x_476_ = lean_nat_dec_eq(v_range_457_, v___x_449_);
if (v___x_476_ == 0)
{
lean_object* v___x_477_; lean_object* v___x_478_; lean_object* v___x_479_; lean_object* v___x_480_; lean_object* v___x_481_; 
v___x_477_ = lean_nat_sub(v_range_457_, v___x_451_);
lean_dec(v_range_457_);
v___x_478_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_477_);
v___x_479_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_480_ = l_Rat_div(v___x_478_, v___x_479_);
lean_dec_ref(v___x_478_);
v___x_481_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_481_, 0, v___x_480_);
v___y_466_ = v___x_481_;
goto v___jp_465_;
}
else
{
lean_object* v___x_482_; 
lean_dec(v_range_457_);
v___x_482_ = lean_box(0);
v___y_466_ = v___x_482_;
goto v___jp_465_;
}
v___jp_465_:
{
uint8_t v___x_467_; 
v___x_467_ = lean_nat_dec_eq(v_bearing_460_, v___x_449_);
if (v___x_467_ == 0)
{
lean_object* v___x_468_; lean_object* v___x_469_; lean_object* v___x_470_; lean_object* v___x_471_; lean_object* v___x_472_; lean_object* v___x_473_; 
v___x_468_ = lean_nat_sub(v_bearing_460_, v___x_451_);
lean_dec(v_bearing_460_);
v___x_469_ = lean_nat_mul(v___x_459_, v___x_468_);
lean_dec(v___x_468_);
v___x_470_ = lean_unsigned_to_nat(3u);
v___x_471_ = lean_nat_add(v___x_469_, v___x_470_);
lean_dec(v___x_469_);
v___x_472_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_472_, 0, v___x_471_);
v___x_473_ = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(v___x_473_, 0, v___x_464_);
lean_ctor_set(v___x_473_, 1, v___y_466_);
lean_ctor_set(v___x_473_, 2, v___x_472_);
return v___x_473_;
}
else
{
lean_object* v___x_474_; lean_object* v___x_475_; 
lean_dec(v_bearing_460_);
v___x_474_ = lean_box(0);
v___x_475_ = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(v___x_475_, 0, v___x_464_);
lean_ctor_set(v___x_475_, 1, v___y_466_);
lean_ctor_set(v___x_475_, 2, v___x_474_);
return v___x_475_;
}
}
}
}
else
{
lean_object* v___x_483_; lean_object* v___x_484_; lean_object* v___x_485_; lean_object* v___x_486_; 
lean_dec(v___x_448_);
v___x_483_ = lean_unsigned_to_nat(31u);
v___x_484_ = lean_unsigned_to_nat(24u);
v___x_485_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_445_, v___x_483_, v___x_484_);
v___x_486_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_486_, 0, v___x_485_);
return v___x_486_;
}
}
else
{
lean_object* v___x_487_; 
lean_dec(v___x_448_);
v___x_487_ = lean_box(0);
return v___x_487_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbThreat___boxed(lean_object* v_word_488_){
_start:
{
lean_object* v_res_489_; 
v_res_489_ = lp_lean1090_Lean1090_Impl_cbThreat(v_word_488_);
lean_dec(v_word_488_);
return v_res_489_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0(void){
_start:
{
lean_object* v___x_490_; lean_object* v___x_491_; 
v___x_490_ = lean_unsigned_to_nat(20u);
v___x_491_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_490_);
return v___x_491_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1(void){
_start:
{
lean_object* v___x_492_; lean_object* v___x_493_; lean_object* v___x_494_; 
v___x_492_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0);
v___x_493_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0);
v___x_494_ = l_Rat_div(v___x_493_, v___x_492_);
return v___x_494_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2(void){
_start:
{
lean_object* v___x_495_; lean_object* v___x_496_; 
v___x_495_ = lean_unsigned_to_nat(251u);
v___x_496_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_495_);
return v___x_496_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3(void){
_start:
{
lean_object* v___x_497_; lean_object* v___x_498_; lean_object* v___x_499_; 
v___x_497_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0);
v___x_498_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2);
v___x_499_ = l_Rat_div(v___x_498_, v___x_497_);
return v___x_499_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4(void){
_start:
{
lean_object* v___x_500_; lean_object* v___x_501_; 
v___x_500_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3);
v___x_501_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_501_, 0, v___x_500_);
return v___x_501_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5(void){
_start:
{
lean_object* v___x_502_; lean_object* v___x_503_; 
v___x_502_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1);
v___x_503_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_503_, 0, v___x_502_);
return v___x_503_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange(lean_object* v_code_504_){
_start:
{
lean_object* v___x_505_; uint8_t v___x_506_; 
v___x_505_ = lean_unsigned_to_nat(0u);
v___x_506_ = lean_nat_dec_eq(v_code_504_, v___x_505_);
if (v___x_506_ == 0)
{
lean_object* v___x_507_; uint8_t v___x_508_; 
v___x_507_ = lean_unsigned_to_nat(1u);
v___x_508_ = lean_nat_dec_eq(v_code_504_, v___x_507_);
if (v___x_508_ == 0)
{
lean_object* v___x_509_; uint8_t v___x_510_; 
v___x_509_ = lean_unsigned_to_nat(127u);
v___x_510_ = lean_nat_dec_eq(v_code_504_, v___x_509_);
if (v___x_510_ == 0)
{
lean_object* v___x_511_; lean_object* v___x_512_; lean_object* v___x_513_; lean_object* v___x_514_; lean_object* v___x_515_; lean_object* v___x_516_; 
v___x_511_ = lean_nat_sub(v_code_504_, v___x_507_);
v___x_512_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_511_);
v___x_513_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_514_ = l_Rat_div(v___x_512_, v___x_513_);
lean_dec_ref(v___x_512_);
v___x_515_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1);
v___x_516_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_516_, 0, v___x_514_);
lean_ctor_set(v___x_516_, 1, v___x_515_);
return v___x_516_;
}
else
{
lean_object* v___x_517_; 
v___x_517_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4);
return v___x_517_;
}
}
else
{
lean_object* v___x_518_; 
v___x_518_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5);
return v___x_518_;
}
}
else
{
lean_object* v___x_519_; 
v___x_519_ = lean_box(0);
return v___x_519_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange___boxed(lean_object* v_code_520_){
_start:
{
lean_object* v_res_521_; 
v_res_521_ = lp_lean1090_Lean1090_Impl_standardThreatRange(v_code_520_);
lean_dec(v_code_520_);
return v_res_521_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatBearing(lean_object* v_code_522_){
_start:
{
lean_object* v___x_523_; uint8_t v___x_524_; 
v___x_523_ = lean_unsigned_to_nat(0u);
v___x_524_ = lean_nat_dec_eq(v_code_522_, v___x_523_);
if (v___x_524_ == 0)
{
lean_object* v___x_525_; uint8_t v___x_526_; 
v___x_525_ = lean_unsigned_to_nat(60u);
v___x_526_ = lean_nat_dec_le(v_code_522_, v___x_525_);
if (v___x_526_ == 0)
{
lean_object* v___x_527_; 
v___x_527_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_527_, 0, v_code_522_);
return v___x_527_;
}
else
{
lean_object* v___x_528_; lean_object* v___x_529_; lean_object* v___x_530_; lean_object* v___x_531_; lean_object* v___x_532_; lean_object* v___x_533_; 
v___x_528_ = lean_unsigned_to_nat(6u);
v___x_529_ = lean_unsigned_to_nat(1u);
v___x_530_ = lean_nat_sub(v_code_522_, v___x_529_);
v___x_531_ = lean_nat_mul(v___x_528_, v___x_530_);
lean_dec(v___x_530_);
v___x_532_ = lean_nat_mul(v___x_528_, v_code_522_);
lean_dec(v_code_522_);
v___x_533_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_533_, 0, v___x_531_);
lean_ctor_set(v___x_533_, 1, v___x_532_);
return v___x_533_;
}
}
else
{
lean_object* v___x_534_; 
lean_dec(v_code_522_);
v___x_534_ = lean_box(0);
return v___x_534_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat(lean_object* v_word_539_){
_start:
{
lean_object* v___x_540_; uint8_t v___x_541_; 
v___x_540_ = lean_cstr_to_nat("72057594037927936");
v___x_541_ = lean_nat_dec_le(v___x_540_, v_word_539_);
if (v___x_541_ == 0)
{
lean_object* v___x_542_; lean_object* v___x_543_; lean_object* v___x_544_; lean_object* v___x_545_; uint8_t v___x_546_; 
v___x_542_ = lean_unsigned_to_nat(2u);
v___x_543_ = lean_unsigned_to_nat(29u);
v___x_544_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_539_, v___x_543_, v___x_542_);
v___x_545_ = lean_unsigned_to_nat(0u);
v___x_546_ = lean_nat_dec_eq(v___x_544_, v___x_545_);
if (v___x_546_ == 0)
{
lean_object* v___x_547_; uint8_t v___x_548_; 
v___x_547_ = lean_unsigned_to_nat(1u);
v___x_548_ = lean_nat_dec_eq(v___x_544_, v___x_547_);
if (v___x_548_ == 0)
{
uint8_t v___x_549_; 
v___x_549_ = lean_nat_dec_eq(v___x_544_, v___x_542_);
lean_dec(v___x_544_);
if (v___x_549_ == 0)
{
lean_object* v___x_550_; 
v___x_550_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__0));
return v___x_550_;
}
else
{
lean_object* v___x_551_; lean_object* v___x_552_; lean_object* v___x_553_; lean_object* v___x_554_; lean_object* v___x_555_; lean_object* v___x_556_; lean_object* v___x_557_; lean_object* v___x_558_; lean_object* v___x_559_; lean_object* v___x_560_; lean_object* v___x_561_; lean_object* v___x_562_; lean_object* v___x_563_; lean_object* v___x_564_; 
v___x_551_ = lean_unsigned_to_nat(31u);
v___x_552_ = lean_unsigned_to_nat(13u);
v___x_553_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_539_, v___x_551_, v___x_552_);
v___x_554_ = lp_lean1090_Lean1090_Impl_Altitude_decodeGillham(v___x_553_);
lean_dec(v___x_553_);
v___x_555_ = lean_unsigned_to_nat(44u);
v___x_556_ = lean_unsigned_to_nat(7u);
v___x_557_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_539_, v___x_555_, v___x_556_);
v___x_558_ = lp_lean1090_Lean1090_Impl_standardThreatRange(v___x_557_);
lean_dec(v___x_557_);
v___x_559_ = lean_unsigned_to_nat(51u);
v___x_560_ = lean_unsigned_to_nat(6u);
v___x_561_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_539_, v___x_559_, v___x_560_);
v___x_562_ = lp_lean1090_Lean1090_Impl_standardThreatBearing(v___x_561_);
v___x_563_ = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(v___x_563_, 0, v___x_554_);
lean_ctor_set(v___x_563_, 1, v___x_558_);
lean_ctor_set(v___x_563_, 2, v___x_562_);
v___x_564_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_564_, 0, v___x_563_);
return v___x_564_;
}
}
else
{
lean_object* v___x_565_; lean_object* v___x_566_; uint8_t v___x_567_; 
lean_dec(v___x_544_);
v___x_565_ = lean_unsigned_to_nat(55u);
v___x_566_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_539_, v___x_565_, v___x_542_);
v___x_567_ = lean_nat_dec_eq(v___x_566_, v___x_545_);
lean_dec(v___x_566_);
if (v___x_567_ == 0)
{
lean_object* v___x_568_; 
v___x_568_ = lean_box(0);
return v___x_568_;
}
else
{
lean_object* v___x_569_; lean_object* v___x_570_; lean_object* v___x_571_; lean_object* v___x_572_; lean_object* v___x_573_; 
v___x_569_ = lean_unsigned_to_nat(31u);
v___x_570_ = lean_unsigned_to_nat(24u);
v___x_571_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_539_, v___x_569_, v___x_570_);
v___x_572_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_572_, 0, v___x_571_);
v___x_573_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_573_, 0, v___x_572_);
return v___x_573_;
}
}
}
else
{
lean_object* v___x_574_; 
lean_dec(v___x_544_);
v___x_574_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__1));
return v___x_574_;
}
}
else
{
lean_object* v___x_575_; 
v___x_575_ = lean_box(0);
return v___x_575_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat___boxed(lean_object* v_word_576_){
_start:
{
lean_object* v_res_577_; 
v_res_577_ = lp_lean1090_Lean1090_Impl_cbStandardThreat(v_word_576_);
lean_dec(v_word_576_);
return v_res_577_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbDashPlaceholder(lean_object* v_code_578_){
_start:
{
lean_object* v___x_579_; uint8_t v___x_580_; 
v___x_579_ = lean_unsigned_to_nat(0u);
v___x_580_ = lean_nat_dec_eq(v_code_578_, v___x_579_);
if (v___x_580_ == 0)
{
lean_object* v___x_581_; uint8_t v___x_582_; 
v___x_581_ = lean_unsigned_to_nat(32u);
v___x_582_ = lean_nat_dec_eq(v_code_578_, v___x_581_);
if (v___x_582_ == 0)
{
lean_object* v___x_583_; uint8_t v___x_584_; 
v___x_583_ = lean_unsigned_to_nat(45u);
v___x_584_ = lean_nat_dec_eq(v_code_578_, v___x_583_);
return v___x_584_;
}
else
{
return v___x_582_;
}
}
else
{
return v___x_580_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDashPlaceholder___boxed(lean_object* v_code_585_){
_start:
{
uint8_t v_res_586_; lean_object* v_r_587_; 
v_res_586_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v_code_585_);
lean_dec(v_code_585_);
v_r_587_ = lean_box(v_res_586_);
return v_r_587_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(lean_object* v_word_588_, lean_object* v_a_589_, lean_object* v_a_590_){
_start:
{
if (lean_obj_tag(v_a_589_) == 0)
{
lean_object* v___x_591_; 
v___x_591_ = l_List_reverse___redArg(v_a_590_);
return v___x_591_;
}
else
{
lean_object* v_head_592_; lean_object* v_tail_593_; lean_object* v___x_595_; uint8_t v_isShared_596_; uint8_t v_isSharedCheck_606_; 
v_head_592_ = lean_ctor_get(v_a_589_, 0);
v_tail_593_ = lean_ctor_get(v_a_589_, 1);
v_isSharedCheck_606_ = !lean_is_exclusive(v_a_589_);
if (v_isSharedCheck_606_ == 0)
{
v___x_595_ = v_a_589_;
v_isShared_596_ = v_isSharedCheck_606_;
goto v_resetjp_594_;
}
else
{
lean_inc(v_tail_593_);
lean_inc(v_head_592_);
lean_dec(v_a_589_);
v___x_595_ = lean_box(0);
v_isShared_596_ = v_isSharedCheck_606_;
goto v_resetjp_594_;
}
v_resetjp_594_:
{
lean_object* v___x_597_; lean_object* v___x_598_; lean_object* v___x_599_; lean_object* v___x_600_; lean_object* v___x_601_; lean_object* v___x_603_; 
v___x_597_ = lean_unsigned_to_nat(2u);
v___x_598_ = lean_unsigned_to_nat(6u);
v___x_599_ = lean_nat_mul(v___x_598_, v_head_592_);
lean_dec(v_head_592_);
v___x_600_ = lean_nat_add(v___x_597_, v___x_599_);
lean_dec(v___x_599_);
v___x_601_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_588_, v___x_600_, v___x_598_);
lean_dec(v___x_600_);
if (v_isShared_596_ == 0)
{
lean_ctor_set(v___x_595_, 1, v_a_590_);
lean_ctor_set(v___x_595_, 0, v___x_601_);
v___x_603_ = v___x_595_;
goto v_reusejp_602_;
}
else
{
lean_object* v_reuseFailAlloc_605_; 
v_reuseFailAlloc_605_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_605_, 0, v___x_601_);
lean_ctor_set(v_reuseFailAlloc_605_, 1, v_a_590_);
v___x_603_ = v_reuseFailAlloc_605_;
goto v_reusejp_602_;
}
v_reusejp_602_:
{
v_a_589_ = v_tail_593_;
v_a_590_ = v___x_603_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0___boxed(lean_object* v_word_607_, lean_object* v_a_608_, lean_object* v_a_609_){
_start:
{
lean_object* v_res_610_; 
v_res_610_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(v_word_607_, v_a_608_, v_a_609_);
lean_dec(v_word_607_);
return v_res_610_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__1(lean_object* v_a_611_, lean_object* v_a_612_){
_start:
{
if (lean_obj_tag(v_a_611_) == 0)
{
lean_object* v___x_613_; 
v___x_613_ = l_List_reverse___redArg(v_a_612_);
return v___x_613_;
}
else
{
lean_object* v_head_614_; lean_object* v_tail_615_; lean_object* v___x_617_; uint8_t v_isShared_618_; uint8_t v_isSharedCheck_625_; 
v_head_614_ = lean_ctor_get(v_a_611_, 0);
v_tail_615_ = lean_ctor_get(v_a_611_, 1);
v_isSharedCheck_625_ = !lean_is_exclusive(v_a_611_);
if (v_isSharedCheck_625_ == 0)
{
v___x_617_ = v_a_611_;
v_isShared_618_ = v_isSharedCheck_625_;
goto v_resetjp_616_;
}
else
{
lean_inc(v_tail_615_);
lean_inc(v_head_614_);
lean_dec(v_a_611_);
v___x_617_ = lean_box(0);
v_isShared_618_ = v_isSharedCheck_625_;
goto v_resetjp_616_;
}
v_resetjp_616_:
{
uint8_t v___x_619_; 
v___x_619_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v_head_614_);
if (v___x_619_ == 0)
{
lean_object* v___x_621_; 
if (v_isShared_618_ == 0)
{
lean_ctor_set(v___x_617_, 1, v_a_612_);
v___x_621_ = v___x_617_;
goto v_reusejp_620_;
}
else
{
lean_object* v_reuseFailAlloc_623_; 
v_reuseFailAlloc_623_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_623_, 0, v_head_614_);
lean_ctor_set(v_reuseFailAlloc_623_, 1, v_a_612_);
v___x_621_ = v_reuseFailAlloc_623_;
goto v_reusejp_620_;
}
v_reusejp_620_:
{
v_a_611_ = v_tail_615_;
v_a_612_ = v___x_621_;
goto _start;
}
}
else
{
lean_del_object(v___x_617_);
lean_dec(v_head_614_);
v_a_611_ = v_tail_615_;
goto _start;
}
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0(void){
_start:
{
lean_object* v___x_626_; lean_object* v___x_627_; 
v___x_626_ = lean_unsigned_to_nat(7u);
v___x_627_ = l_List_range(v___x_626_);
return v___x_627_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistrationCodes(lean_object* v_word_628_){
_start:
{
lean_object* v___x_629_; lean_object* v___x_630_; lean_object* v___x_631_; lean_object* v___x_632_; 
v___x_629_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0, &lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0);
v___x_630_ = lean_box(0);
v___x_631_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(v_word_628_, v___x_629_, v___x_630_);
v___x_632_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__1(v___x_631_, v___x_630_);
return v___x_632_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistrationCodes___boxed(lean_object* v_word_633_){
_start:
{
lean_object* v_res_634_; 
v_res_634_ = lp_lean1090_Lean1090_Impl_cbRegistrationCodes(v_word_633_);
lean_dec(v_word_633_);
return v_res_634_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistration(lean_object* v_word_635_){
_start:
{
lean_object* v___x_636_; lean_object* v___x_637_; lean_object* v___x_638_; uint8_t v___x_639_; 
v___x_636_ = lean_unsigned_to_nat(1u);
v___x_637_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_635_, v___x_636_, v___x_636_);
v___x_638_ = lean_unsigned_to_nat(0u);
v___x_639_ = lean_nat_dec_eq(v___x_637_, v___x_638_);
lean_dec(v___x_637_);
if (v___x_639_ == 0)
{
lean_object* v___x_640_; lean_object* v___x_641_; lean_object* v___x_642_; lean_object* v___x_643_; lean_object* v___x_644_; 
v___x_640_ = lp_lean1090_Lean1090_Impl_cbRegistrationCodes(v_word_635_);
v___x_641_ = lean_box(0);
v___x_642_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(v___x_640_, v___x_641_);
v___x_643_ = lean_string_mk(v___x_642_);
v___x_644_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_644_, 0, v___x_643_);
return v___x_644_;
}
else
{
lean_object* v___x_645_; 
v___x_645_ = lean_box(0);
return v___x_645_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistration___boxed(lean_object* v_word_646_){
_start:
{
lean_object* v_res_647_; 
v_res_647_ = lp_lean1090_Lean1090_Impl_cbRegistration(v_word_646_);
lean_dec(v_word_646_);
return v_res_647_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(lean_object* v_word_648_, lean_object* v_x_649_){
_start:
{
if (lean_obj_tag(v_x_649_) == 0)
{
uint8_t v___x_650_; 
v___x_650_ = 1;
return v___x_650_;
}
else
{
lean_object* v_head_651_; lean_object* v_tail_652_; lean_object* v___x_653_; lean_object* v___x_654_; lean_object* v___x_655_; uint8_t v___x_656_; 
v_head_651_ = lean_ctor_get(v_x_649_, 0);
v_tail_652_ = lean_ctor_get(v_x_649_, 1);
v___x_653_ = lean_unsigned_to_nat(1u);
v___x_654_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_648_, v_head_651_, v___x_653_);
v___x_655_ = lean_unsigned_to_nat(0u);
v___x_656_ = lean_nat_dec_eq(v___x_654_, v___x_655_);
lean_dec(v___x_654_);
if (v___x_656_ == 0)
{
return v___x_656_;
}
else
{
v_x_649_ = v_tail_652_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0___boxed(lean_object* v_word_658_, lean_object* v_x_659_){
_start:
{
uint8_t v_res_660_; lean_object* v_r_661_; 
v_res_660_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(v_word_658_, v_x_659_);
lean_dec(v_x_659_);
lean_dec(v_word_658_);
v_r_661_ = lean_box(v_res_660_);
return v_r_661_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid17(lean_object* v_word_683_){
_start:
{
lean_object* v___x_684_; lean_object* v___x_685_; lean_object* v___x_686_; uint8_t v___x_687_; 
v___x_684_ = lean_unsigned_to_nat(7u);
v___x_685_ = lean_unsigned_to_nat(1u);
v___x_686_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_683_, v___x_684_, v___x_685_);
v___x_687_ = lean_nat_dec_eq(v___x_686_, v___x_685_);
lean_dec(v___x_686_);
if (v___x_687_ == 0)
{
return v___x_687_;
}
else
{
lean_object* v___x_688_; lean_object* v___x_689_; lean_object* v___x_690_; lean_object* v___x_691_; uint8_t v___x_692_; 
v___x_688_ = lean_unsigned_to_nat(30u);
v___x_689_ = lean_unsigned_to_nat(27u);
v___x_690_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_683_, v___x_688_, v___x_689_);
v___x_691_ = lean_unsigned_to_nat(0u);
v___x_692_ = lean_nat_dec_eq(v___x_690_, v___x_691_);
lean_dec(v___x_690_);
if (v___x_692_ == 0)
{
return v___x_692_;
}
else
{
lean_object* v___x_693_; uint8_t v___x_694_; 
v___x_693_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbValid17___closed__6));
v___x_694_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(v_word_683_, v___x_693_);
return v___x_694_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid17___boxed(lean_object* v_word_695_){
_start:
{
uint8_t v_res_696_; lean_object* v_r_697_; 
v_res_696_ = lp_lean1090_Lean1090_Impl_cbValid17(v_word_695_);
lean_dec(v_word_695_);
v_r_697_ = lean_box(v_res_696_);
return v_r_697_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(lean_object* v_word_761_, lean_object* v_x_762_){
_start:
{
if (lean_obj_tag(v_x_762_) == 0)
{
uint8_t v___x_763_; 
v___x_763_ = 1;
return v___x_763_;
}
else
{
lean_object* v_head_764_; lean_object* v_tail_765_; uint8_t v___y_767_; lean_object* v___x_769_; lean_object* v_allowed_770_; lean_object* v___x_771_; uint8_t v___x_772_; 
v_head_764_ = lean_ctor_get(v_x_762_, 0);
v_tail_765_ = lean_ctor_get(v_x_762_, 1);
v___x_769_ = lean_unsigned_to_nat(56u);
v_allowed_770_ = ((lean_object*)(lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__20));
v___x_771_ = lean_nat_sub(v___x_769_, v_head_764_);
v___x_772_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v___x_771_, v_allowed_770_);
lean_dec(v___x_771_);
if (v___x_772_ == 0)
{
lean_object* v___x_773_; lean_object* v___x_774_; lean_object* v___x_775_; lean_object* v___x_776_; uint8_t v___x_777_; 
v___x_773_ = lean_unsigned_to_nat(1u);
v___x_774_ = lean_nat_add(v_head_764_, v___x_773_);
v___x_775_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_761_, v___x_774_, v___x_773_);
lean_dec(v___x_774_);
v___x_776_ = lean_unsigned_to_nat(0u);
v___x_777_ = lean_nat_dec_eq(v___x_775_, v___x_776_);
lean_dec(v___x_775_);
v___y_767_ = v___x_777_;
goto v___jp_766_;
}
else
{
v___y_767_ = v___x_772_;
goto v___jp_766_;
}
v___jp_766_:
{
if (v___y_767_ == 0)
{
return v___y_767_;
}
else
{
v_x_762_ = v_tail_765_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___boxed(lean_object* v_word_778_, lean_object* v_x_779_){
_start:
{
uint8_t v_res_780_; lean_object* v_r_781_; 
v_res_780_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(v_word_778_, v_x_779_);
lean_dec(v_x_779_);
lean_dec(v_word_778_);
v_r_781_ = lean_box(v_res_780_);
return v_r_781_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(lean_object* v_word_782_, lean_object* v_x_783_){
_start:
{
if (lean_obj_tag(v_x_783_) == 0)
{
uint8_t v___x_784_; 
v___x_784_ = 1;
return v___x_784_;
}
else
{
lean_object* v_head_785_; lean_object* v_tail_786_; lean_object* v___x_787_; lean_object* v___x_788_; lean_object* v___x_789_; lean_object* v___x_790_; uint8_t v___x_791_; 
v_head_785_ = lean_ctor_get(v_x_783_, 0);
v_tail_786_ = lean_ctor_get(v_x_783_, 1);
v___x_787_ = lean_unsigned_to_nat(57u);
v___x_788_ = lean_nat_sub(v___x_787_, v_head_785_);
v___x_789_ = lean_unsigned_to_nat(1u);
v___x_790_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_782_, v___x_788_, v___x_789_);
lean_dec(v___x_788_);
v___x_791_ = lean_nat_dec_eq(v___x_790_, v___x_789_);
lean_dec(v___x_790_);
if (v___x_791_ == 0)
{
return v___x_791_;
}
else
{
v_x_783_ = v_tail_786_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1___boxed(lean_object* v_word_793_, lean_object* v_x_794_){
_start:
{
uint8_t v_res_795_; lean_object* v_r_796_; 
v_res_795_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(v_word_793_, v_x_794_);
lean_dec(v_x_794_);
lean_dec(v_word_793_);
v_r_796_ = lean_box(v_res_795_);
return v_r_796_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid18___closed__0(void){
_start:
{
lean_object* v___x_797_; lean_object* v___x_798_; 
v___x_797_ = lean_unsigned_to_nat(56u);
v___x_798_ = l_List_range(v___x_797_);
return v___x_798_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid18(lean_object* v_word_811_){
_start:
{
lean_object* v___x_812_; uint8_t v___x_813_; 
v___x_812_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid18___closed__0, &lp_lean1090_Lean1090_Impl_cbValid18___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid18___closed__0);
v___x_813_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(v_word_811_, v___x_812_);
if (v___x_813_ == 0)
{
return v___x_813_;
}
else
{
lean_object* v___x_814_; uint8_t v___x_815_; 
v___x_814_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbValid18___closed__4));
v___x_815_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(v_word_811_, v___x_814_);
return v___x_815_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid18___boxed(lean_object* v_word_816_){
_start:
{
uint8_t v_res_817_; lean_object* v_r_818_; 
v_res_817_ = lp_lean1090_Lean1090_Impl_cbValid18(v_word_816_);
lean_dec(v_word_816_);
v_r_818_ = lean_box(v_res_817_);
return v_r_818_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(lean_object* v_word_855_, lean_object* v_x_856_){
_start:
{
if (lean_obj_tag(v_x_856_) == 0)
{
uint8_t v___x_857_; 
v___x_857_ = 1;
return v___x_857_;
}
else
{
lean_object* v_head_858_; lean_object* v_tail_859_; uint8_t v___y_861_; lean_object* v_allowed_863_; lean_object* v___x_864_; lean_object* v___x_865_; uint8_t v___x_866_; 
v_head_858_ = lean_ctor_get(v_x_856_, 0);
v_tail_859_ = lean_ctor_get(v_x_856_, 1);
v_allowed_863_ = ((lean_object*)(lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__11));
v___x_864_ = lean_unsigned_to_nat(112u);
v___x_865_ = lean_nat_sub(v___x_864_, v_head_858_);
v___x_866_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v___x_865_, v_allowed_863_);
lean_dec(v___x_865_);
if (v___x_866_ == 0)
{
lean_object* v___x_867_; lean_object* v___x_868_; lean_object* v___x_869_; lean_object* v___x_870_; uint8_t v___x_871_; 
v___x_867_ = lean_unsigned_to_nat(1u);
v___x_868_ = lean_nat_add(v_head_858_, v___x_867_);
v___x_869_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_855_, v___x_868_, v___x_867_);
lean_dec(v___x_868_);
v___x_870_ = lean_unsigned_to_nat(0u);
v___x_871_ = lean_nat_dec_eq(v___x_869_, v___x_870_);
lean_dec(v___x_869_);
v___y_861_ = v___x_871_;
goto v___jp_860_;
}
else
{
v___y_861_ = v___x_866_;
goto v___jp_860_;
}
v___jp_860_:
{
if (v___y_861_ == 0)
{
return v___y_861_;
}
else
{
v_x_856_ = v_tail_859_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___boxed(lean_object* v_word_872_, lean_object* v_x_873_){
_start:
{
uint8_t v_res_874_; lean_object* v_r_875_; 
v_res_874_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(v_word_872_, v_x_873_);
lean_dec(v_x_873_);
lean_dec(v_word_872_);
v_r_875_ = lean_box(v_res_874_);
return v_r_875_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid19(lean_object* v_word_876_){
_start:
{
lean_object* v___x_877_; uint8_t v___x_878_; 
v___x_877_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid18___closed__0, &lp_lean1090_Lean1090_Impl_cbValid18___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid18___closed__0);
v___x_878_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(v_word_876_, v___x_877_);
return v___x_878_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid19___boxed(lean_object* v_word_879_){
_start:
{
uint8_t v_res_880_; lean_object* v_r_881_; 
v_res_880_ = lp_lean1090_Lean1090_Impl_cbValid19(v_word_879_);
lean_dec(v_word_879_);
v_r_881_ = lean_box(v_res_880_);
return v_r_881_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbValid21_spec__0(lean_object* v_a_882_, lean_object* v_a_883_){
_start:
{
if (lean_obj_tag(v_a_882_) == 0)
{
lean_object* v___x_884_; 
v___x_884_ = l_List_reverse___redArg(v_a_883_);
return v___x_884_;
}
else
{
lean_object* v_head_885_; lean_object* v_tail_886_; lean_object* v___x_888_; uint8_t v_isShared_889_; uint8_t v_isSharedCheck_898_; 
v_head_885_ = lean_ctor_get(v_a_882_, 0);
v_tail_886_ = lean_ctor_get(v_a_882_, 1);
v_isSharedCheck_898_ = !lean_is_exclusive(v_a_882_);
if (v_isSharedCheck_898_ == 0)
{
v___x_888_ = v_a_882_;
v_isShared_889_ = v_isSharedCheck_898_;
goto v_resetjp_887_;
}
else
{
lean_inc(v_tail_886_);
lean_inc(v_head_885_);
lean_dec(v_a_882_);
v___x_888_ = lean_box(0);
v_isShared_889_ = v_isSharedCheck_898_;
goto v_resetjp_887_;
}
v_resetjp_887_:
{
uint32_t v___x_890_; uint32_t v___x_891_; uint8_t v___x_892_; 
v___x_890_ = lp_lean1090_Lean1090_Impl_cbCharacter(v_head_885_);
v___x_891_ = 35;
v___x_892_ = lean_uint32_dec_eq(v___x_890_, v___x_891_);
if (v___x_892_ == 0)
{
lean_del_object(v___x_888_);
lean_dec(v_head_885_);
v_a_882_ = v_tail_886_;
goto _start;
}
else
{
lean_object* v___x_895_; 
if (v_isShared_889_ == 0)
{
lean_ctor_set(v___x_888_, 1, v_a_883_);
v___x_895_ = v___x_888_;
goto v_reusejp_894_;
}
else
{
lean_object* v_reuseFailAlloc_897_; 
v_reuseFailAlloc_897_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_897_, 0, v_head_885_);
lean_ctor_set(v_reuseFailAlloc_897_, 1, v_a_883_);
v___x_895_ = v_reuseFailAlloc_897_;
goto v_reusejp_894_;
}
v_reusejp_894_:
{
v_a_882_ = v_tail_886_;
v_a_883_ = v___x_895_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid21(lean_object* v_word_899_){
_start:
{
uint8_t v___y_901_; lean_object* v_codes_914_; lean_object* v___x_915_; lean_object* v___x_916_; lean_object* v___x_917_; uint8_t v___x_918_; 
v_codes_914_ = lp_lean1090_Lean1090_Impl_cbRegistrationCodes(v_word_899_);
v___x_915_ = lean_unsigned_to_nat(1u);
v___x_916_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_899_, v___x_915_, v___x_915_);
v___x_917_ = lean_unsigned_to_nat(0u);
v___x_918_ = lean_nat_dec_eq(v___x_916_, v___x_917_);
lean_dec(v___x_916_);
if (v___x_918_ == 0)
{
lean_object* v___x_919_; lean_object* v___x_920_; lean_object* v___x_921_; lean_object* v___x_922_; uint8_t v___x_923_; 
v___x_919_ = lean_box(0);
v___x_920_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbValid21_spec__0(v_codes_914_, v___x_919_);
v___x_921_ = l_List_lengthTR___redArg(v___x_920_);
lean_dec(v___x_920_);
v___x_922_ = lean_unsigned_to_nat(2u);
v___x_923_ = lean_nat_dec_le(v___x_921_, v___x_922_);
lean_dec(v___x_921_);
v___y_901_ = v___x_923_;
goto v___jp_900_;
}
else
{
uint8_t v___x_924_; 
v___x_924_ = l_List_isEmpty___redArg(v_codes_914_);
lean_dec(v_codes_914_);
v___y_901_ = v___x_924_;
goto v___jp_900_;
}
v___jp_900_:
{
if (v___y_901_ == 0)
{
return v___y_901_;
}
else
{
lean_object* v___x_902_; lean_object* v___x_903_; lean_object* v___x_904_; lean_object* v___x_905_; uint8_t v___x_906_; 
v___x_902_ = lean_unsigned_to_nat(44u);
v___x_903_ = lean_unsigned_to_nat(1u);
v___x_904_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_899_, v___x_902_, v___x_903_);
v___x_905_ = lean_unsigned_to_nat(0u);
v___x_906_ = lean_nat_dec_eq(v___x_904_, v___x_905_);
lean_dec(v___x_904_);
if (v___x_906_ == 0)
{
return v___x_906_;
}
else
{
lean_object* v___x_907_; lean_object* v___x_908_; lean_object* v___x_909_; uint8_t v___x_910_; 
v___x_907_ = lean_unsigned_to_nat(45u);
v___x_908_ = lean_unsigned_to_nat(6u);
v___x_909_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_899_, v___x_907_, v___x_908_);
v___x_910_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v___x_909_);
lean_dec(v___x_909_);
if (v___x_910_ == 0)
{
return v___x_910_;
}
else
{
lean_object* v___x_911_; lean_object* v___x_912_; uint8_t v___x_913_; 
v___x_911_ = lean_unsigned_to_nat(51u);
v___x_912_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_899_, v___x_911_, v___x_908_);
v___x_913_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v___x_912_);
lean_dec(v___x_912_);
return v___x_913_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid21___boxed(lean_object* v_word_925_){
_start:
{
uint8_t v_res_926_; lean_object* v_r_927_; 
v_res_926_ = lp_lean1090_Lean1090_Impl_cbValid21(v_word_925_);
lean_dec(v_word_925_);
v_r_927_ = lean_box(v_res_926_);
return v_r_927_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___closed__0(void){
_start:
{
lean_object* v___x_928_; lean_object* v___x_929_; 
v___x_928_ = lean_unsigned_to_nat(50000u);
v___x_929_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_928_);
return v___x_929_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0(lean_object* v_code_930_){
_start:
{
lean_object* v___x_931_; lean_object* v___x_932_; uint8_t v___x_933_; 
v___x_931_ = lp_lean1090_Lean1090_Impl_cbSelected(v_code_930_);
v___x_932_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___closed__0);
v___x_933_ = l_Rat_instDecidableLe(v___x_931_, v___x_932_);
return v___x_933_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0___boxed(lean_object* v_code_934_){
_start:
{
uint8_t v_res_935_; lean_object* v_r_936_; 
v_res_935_ = lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___lam__0(v_code_934_);
lean_dec(v_code_934_);
v_r_936_ = lean_box(v_res_935_);
return v_r_936_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__1(void){
_start:
{
lean_object* v___f_938_; lean_object* v___x_939_; lean_object* v___x_940_; 
v___f_938_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__0));
v___x_939_ = lean_unsigned_to_nat(4096u);
v___x_940_ = l_Array_ofFn___redArg(v___x_939_, v___f_938_);
return v___x_940_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedValid40Table(void){
_start:
{
lean_object* v___x_941_; 
v___x_941_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__1, &lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbSelectedValid40Table___closed__1);
return v___x_941_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbSelectedValid40(lean_object* v_word_942_, lean_object* v_start_943_){
_start:
{
lean_object* v___x_944_; lean_object* v___x_945_; lean_object* v___x_946_; lean_object* v___x_947_; uint8_t v___x_948_; 
v___x_944_ = lp_lean1090_Lean1090_Impl_cbSelectedValid40Table;
v___x_945_ = lean_unsigned_to_nat(12u);
v___x_946_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_942_, v_start_943_, v___x_945_);
v___x_947_ = lean_array_fget_borrowed(v___x_944_, v___x_946_);
lean_dec(v___x_946_);
v___x_948_ = lean_unbox(v___x_947_);
return v___x_948_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedValid40___boxed(lean_object* v_word_949_, lean_object* v_start_950_){
_start:
{
uint8_t v_res_951_; lean_object* v_r_952_; 
v_res_951_ = lp_lean1090_Lean1090_Impl_cbSelectedValid40(v_word_949_, v_start_950_);
lean_dec(v_start_950_);
lean_dec(v_word_949_);
v_r_952_ = lean_box(v_res_951_);
return v_r_952_;
}
}
static lean_object* _init_lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___closed__0(void){
_start:
{
lean_object* v___x_953_; lean_object* v___x_954_; 
v___x_953_ = lean_unsigned_to_nat(1200u);
v___x_954_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_953_);
return v___x_954_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0(size_t v_sz_955_, size_t v_i_956_, lean_object* v_bs_957_){
_start:
{
uint8_t v___x_958_; 
v___x_958_ = lean_usize_dec_lt(v_i_956_, v_sz_955_);
if (v___x_958_ == 0)
{
return v_bs_957_;
}
else
{
lean_object* v_v_959_; lean_object* v___x_960_; lean_object* v_bs_x27_961_; uint8_t v___y_963_; lean_object* v___x_969_; uint8_t v___x_970_; 
v_v_959_ = lean_array_uget(v_bs_957_, v_i_956_);
v___x_960_ = lean_unsigned_to_nat(0u);
v_bs_x27_961_ = lean_array_uset(v_bs_957_, v_i_956_, v___x_960_);
v___x_969_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4);
lean_inc(v_v_959_);
v___x_970_ = l_Rat_instDecidableLe(v___x_969_, v_v_959_);
if (v___x_970_ == 0)
{
lean_dec(v_v_959_);
v___y_963_ = v___x_970_;
goto v___jp_962_;
}
else
{
lean_object* v___x_971_; uint8_t v___x_972_; 
v___x_971_ = lean_obj_once(&lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___closed__0, &lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___closed__0_once, _init_lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___closed__0);
v___x_972_ = l_Rat_instDecidableLe(v_v_959_, v___x_971_);
v___y_963_ = v___x_972_;
goto v___jp_962_;
}
v___jp_962_:
{
size_t v___x_964_; size_t v___x_965_; lean_object* v___x_966_; lean_object* v___x_967_; 
v___x_964_ = ((size_t)1ULL);
v___x_965_ = lean_usize_add(v_i_956_, v___x_964_);
v___x_966_ = lean_box(v___y_963_);
v___x_967_ = lean_array_uset(v_bs_x27_961_, v_i_956_, v___x_966_);
v_i_956_ = v___x_965_;
v_bs_957_ = v___x_967_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0___boxed(lean_object* v_sz_973_, lean_object* v_i_974_, lean_object* v_bs_975_){
_start:
{
size_t v_sz_boxed_976_; size_t v_i_boxed_977_; lean_object* v_res_978_; 
v_sz_boxed_976_ = lean_unbox_usize(v_sz_973_);
lean_dec(v_sz_973_);
v_i_boxed_977_ = lean_unbox_usize(v_i_974_);
lean_dec(v_i_974_);
v_res_978_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0(v_sz_boxed_976_, v_i_boxed_977_, v_bs_975_);
return v_res_978_;
}
}
static size_t _init_lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__0(void){
_start:
{
lean_object* v___x_979_; size_t v_sz_980_; 
v___x_979_ = lp_lean1090_Lean1090_Impl_cbQNHValueTable;
v_sz_980_ = lean_array_size(v___x_979_);
return v_sz_980_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__1(void){
_start:
{
lean_object* v___x_981_; size_t v___x_982_; size_t v_sz_983_; lean_object* v___x_984_; 
v___x_981_ = lp_lean1090_Lean1090_Impl_cbQNHValueTable;
v___x_982_ = ((size_t)0ULL);
v_sz_983_ = lean_usize_once(&lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__0);
v___x_984_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbQNHValid40Table_spec__0(v_sz_983_, v___x_982_, v___x_981_);
return v___x_984_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHValid40Table(void){
_start:
{
lean_object* v___x_985_; 
v___x_985_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValid40Table___closed__1);
return v___x_985_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbQNHValid40(lean_object* v_word_986_){
_start:
{
lean_object* v___x_987_; lean_object* v___x_988_; lean_object* v___x_989_; lean_object* v___x_990_; lean_object* v___x_991_; uint8_t v___x_992_; 
v___x_987_ = lp_lean1090_Lean1090_Impl_cbQNHValid40Table;
v___x_988_ = lean_unsigned_to_nat(28u);
v___x_989_ = lean_unsigned_to_nat(12u);
v___x_990_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_986_, v___x_988_, v___x_989_);
v___x_991_ = lean_array_fget_borrowed(v___x_987_, v___x_990_);
lean_dec(v___x_990_);
v___x_992_ = lean_unbox(v___x_991_);
return v___x_992_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHValid40___boxed(lean_object* v_word_993_){
_start:
{
uint8_t v_res_994_; lean_object* v_r_995_; 
v_res_994_ = lp_lean1090_Lean1090_Impl_cbQNHValid40(v_word_993_);
lean_dec(v_word_993_);
v_r_995_ = lean_box(v_res_994_);
return v_r_995_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid40(lean_object* v_word_996_){
_start:
{
uint8_t v___y_998_; lean_object* v___x_1016_; lean_object* v___x_1017_; lean_object* v___x_1018_; uint8_t v___x_1019_; 
v___x_1016_ = lean_unsigned_to_nat(1u);
v___x_1017_ = lean_unsigned_to_nat(2u);
v___x_1018_ = lean_unsigned_to_nat(12u);
v___x_1019_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_996_, v___x_1016_, v___x_1017_, v___x_1018_);
if (v___x_1019_ == 0)
{
v___y_998_ = v___x_1019_;
goto v___jp_997_;
}
else
{
lean_object* v___x_1020_; lean_object* v___x_1021_; uint8_t v___x_1022_; 
v___x_1020_ = lean_unsigned_to_nat(14u);
v___x_1021_ = lean_unsigned_to_nat(15u);
v___x_1022_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_996_, v___x_1020_, v___x_1021_, v___x_1018_);
v___y_998_ = v___x_1022_;
goto v___jp_997_;
}
v___jp_997_:
{
if (v___y_998_ == 0)
{
return v___y_998_;
}
else
{
lean_object* v___x_999_; lean_object* v___x_1000_; lean_object* v___x_1001_; uint8_t v___x_1002_; 
v___x_999_ = lean_unsigned_to_nat(27u);
v___x_1000_ = lean_unsigned_to_nat(28u);
v___x_1001_ = lean_unsigned_to_nat(12u);
v___x_1002_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_996_, v___x_999_, v___x_1000_, v___x_1001_);
if (v___x_1002_ == 0)
{
return v___x_1002_;
}
else
{
lean_object* v___x_1003_; lean_object* v___x_1004_; lean_object* v___x_1005_; lean_object* v___x_1006_; uint8_t v___x_1007_; 
v___x_1003_ = lean_unsigned_to_nat(40u);
v___x_1004_ = lean_unsigned_to_nat(8u);
v___x_1005_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_996_, v___x_1003_, v___x_1004_);
v___x_1006_ = lean_unsigned_to_nat(0u);
v___x_1007_ = lean_nat_dec_eq(v___x_1005_, v___x_1006_);
lean_dec(v___x_1005_);
if (v___x_1007_ == 0)
{
return v___x_1007_;
}
else
{
lean_object* v___x_1008_; lean_object* v___x_1009_; lean_object* v___x_1010_; uint8_t v___x_1011_; 
v___x_1008_ = lean_unsigned_to_nat(52u);
v___x_1009_ = lean_unsigned_to_nat(2u);
v___x_1010_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_996_, v___x_1008_, v___x_1009_);
v___x_1011_ = lean_nat_dec_eq(v___x_1010_, v___x_1006_);
lean_dec(v___x_1010_);
if (v___x_1011_ == 0)
{
return v___x_1011_;
}
else
{
uint8_t v___x_1012_; 
v___x_1012_ = lp_lean1090_Lean1090_Impl_cbSelectedValid40(v_word_996_, v___x_1009_);
if (v___x_1012_ == 0)
{
return v___x_1012_;
}
else
{
lean_object* v___x_1013_; uint8_t v___x_1014_; 
v___x_1013_ = lean_unsigned_to_nat(15u);
v___x_1014_ = lp_lean1090_Lean1090_Impl_cbSelectedValid40(v_word_996_, v___x_1013_);
if (v___x_1014_ == 0)
{
return v___x_1014_;
}
else
{
uint8_t v___x_1015_; 
v___x_1015_ = lp_lean1090_Lean1090_Impl_cbQNHValid40(v_word_996_);
return v___x_1015_;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid40___boxed(lean_object* v_word_1023_){
_start:
{
uint8_t v_res_1024_; lean_object* v_r_1025_; 
v_res_1024_ = lp_lean1090_Lean1090_Impl_cbValid40(v_word_1023_);
lean_dec(v_word_1023_);
v_r_1025_ = lean_box(v_res_1024_);
return v_r_1025_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0(void){
_start:
{
lean_object* v___x_1026_; lean_object* v___x_1027_; 
v___x_1026_ = lean_unsigned_to_nat(60u);
v___x_1027_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1026_);
return v___x_1027_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid44(lean_object* v_word_1028_){
_start:
{
lean_object* v___x_1052_; lean_object* v___x_1053_; lean_object* v___x_1054_; uint8_t v___x_1055_; 
v___x_1052_ = lean_unsigned_to_nat(1u);
v___x_1053_ = lean_unsigned_to_nat(4u);
v___x_1054_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1028_, v___x_1052_, v___x_1053_);
v___x_1055_ = lean_nat_dec_eq(v___x_1054_, v___x_1052_);
if (v___x_1055_ == 0)
{
lean_object* v___x_1056_; uint8_t v___x_1057_; 
v___x_1056_ = lean_unsigned_to_nat(2u);
v___x_1057_ = lean_nat_dec_eq(v___x_1054_, v___x_1056_);
lean_dec(v___x_1054_);
if (v___x_1057_ == 0)
{
return v___x_1057_;
}
else
{
goto v___jp_1029_;
}
}
else
{
lean_dec(v___x_1054_);
goto v___jp_1029_;
}
v___jp_1029_:
{
lean_object* v___x_1030_; lean_object* v___x_1031_; lean_object* v___x_1032_; uint8_t v___x_1033_; 
v___x_1030_ = lean_unsigned_to_nat(5u);
v___x_1031_ = lean_unsigned_to_nat(6u);
v___x_1032_ = lean_unsigned_to_nat(18u);
v___x_1033_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1028_, v___x_1030_, v___x_1031_, v___x_1032_);
if (v___x_1033_ == 0)
{
return v___x_1033_;
}
else
{
lean_object* v___x_1034_; lean_object* v___x_1035_; lean_object* v___x_1036_; uint8_t v___x_1037_; 
v___x_1034_ = lean_unsigned_to_nat(9u);
v___x_1035_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1028_, v___x_1031_, v___x_1034_);
v___x_1036_ = lean_unsigned_to_nat(250u);
v___x_1037_ = lean_nat_dec_le(v___x_1035_, v___x_1036_);
lean_dec(v___x_1035_);
if (v___x_1037_ == 0)
{
return v___x_1037_;
}
else
{
lean_object* v___x_1038_; lean_object* v___x_1039_; uint8_t v___x_1040_; 
v___x_1038_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
v___x_1039_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_1028_);
lean_inc_ref(v___x_1039_);
v___x_1040_ = l_Rat_instDecidableLe(v___x_1038_, v___x_1039_);
if (v___x_1040_ == 0)
{
lean_dec_ref(v___x_1039_);
return v___x_1040_;
}
else
{
lean_object* v___x_1041_; uint8_t v___x_1042_; 
v___x_1041_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid44___closed__0, &lp_lean1090_Lean1090_Impl_cbValid44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0);
v___x_1042_ = l_Rat_instDecidableLe(v___x_1039_, v___x_1041_);
if (v___x_1042_ == 0)
{
return v___x_1042_;
}
else
{
lean_object* v___x_1043_; lean_object* v___x_1044_; lean_object* v___x_1045_; uint8_t v___x_1046_; 
v___x_1043_ = lean_unsigned_to_nat(35u);
v___x_1044_ = lean_unsigned_to_nat(36u);
v___x_1045_ = lean_unsigned_to_nat(11u);
v___x_1046_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1028_, v___x_1043_, v___x_1044_, v___x_1045_);
if (v___x_1046_ == 0)
{
return v___x_1046_;
}
else
{
lean_object* v___x_1047_; lean_object* v___x_1048_; lean_object* v___x_1049_; lean_object* v___x_1050_; uint8_t v___x_1051_; 
v___x_1047_ = lean_unsigned_to_nat(47u);
v___x_1048_ = lean_unsigned_to_nat(10u);
v___x_1049_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1028_, v___x_1047_, v___x_1048_);
v___x_1050_ = lean_unsigned_to_nat(0u);
v___x_1051_ = lean_nat_dec_eq(v___x_1049_, v___x_1050_);
lean_dec(v___x_1049_);
return v___x_1051_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid44___boxed(lean_object* v_word_1058_){
_start:
{
uint8_t v_res_1059_; lean_object* v_r_1060_; 
v_res_1059_ = lp_lean1090_Lean1090_Impl_cbValid44(v_word_1058_);
lean_dec(v_word_1058_);
v_r_1060_ = lean_box(v_res_1059_);
return v_r_1060_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid45(lean_object* v_word_1061_){
_start:
{
uint8_t v___y_1063_; lean_object* v___x_1072_; lean_object* v___x_1073_; lean_object* v___x_1074_; lean_object* v___x_1075_; uint8_t v___x_1076_; 
v___x_1072_ = lean_unsigned_to_nat(1u);
v___x_1073_ = lean_unsigned_to_nat(15u);
v___x_1074_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1061_, v___x_1072_, v___x_1073_);
v___x_1075_ = lean_unsigned_to_nat(0u);
v___x_1076_ = lean_nat_dec_eq(v___x_1074_, v___x_1075_);
lean_dec(v___x_1074_);
if (v___x_1076_ == 0)
{
return v___x_1076_;
}
else
{
lean_object* v___x_1077_; lean_object* v___x_1078_; lean_object* v___x_1079_; uint8_t v___x_1080_; 
v___x_1077_ = lean_unsigned_to_nat(52u);
v___x_1078_ = lean_unsigned_to_nat(5u);
v___x_1079_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1061_, v___x_1077_, v___x_1078_);
v___x_1080_ = lean_nat_dec_eq(v___x_1079_, v___x_1075_);
lean_dec(v___x_1079_);
if (v___x_1080_ == 0)
{
return v___x_1080_;
}
else
{
lean_object* v___x_1081_; lean_object* v___x_1082_; uint8_t v___x_1083_; 
v___x_1081_ = lean_unsigned_to_nat(16u);
v___x_1082_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1061_, v___x_1081_, v___x_1072_);
v___x_1083_ = lean_nat_dec_eq(v___x_1082_, v___x_1075_);
lean_dec(v___x_1082_);
if (v___x_1083_ == 0)
{
lean_object* v___x_1084_; lean_object* v___x_1085_; lean_object* v___x_1086_; lean_object* v___x_1087_; lean_object* v___x_1088_; lean_object* v___x_1089_; uint8_t v___x_1090_; 
v___x_1084_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
v___x_1085_ = lean_unsigned_to_nat(17u);
v___x_1086_ = lean_unsigned_to_nat(10u);
v___x_1087_ = lp_lean1090_Lean1090_Impl_cbSigned(v_word_1061_, v___x_1085_, v___x_1086_);
v___x_1088_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v___x_1089_ = l_Rat_div(v___x_1087_, v___x_1088_);
lean_dec_ref(v___x_1087_);
lean_inc_ref(v___x_1089_);
v___x_1090_ = l_Rat_instDecidableLe(v___x_1084_, v___x_1089_);
if (v___x_1090_ == 0)
{
lean_dec_ref(v___x_1089_);
return v___x_1090_;
}
else
{
lean_object* v___x_1091_; uint8_t v___x_1092_; 
v___x_1091_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid44___closed__0, &lp_lean1090_Lean1090_Impl_cbValid44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0);
v___x_1092_ = l_Rat_instDecidableLe(v___x_1089_, v___x_1091_);
v___y_1063_ = v___x_1092_;
goto v___jp_1062_;
}
}
else
{
lean_object* v___x_1093_; lean_object* v___x_1094_; lean_object* v___x_1095_; uint8_t v___x_1096_; 
v___x_1093_ = lean_unsigned_to_nat(18u);
v___x_1094_ = lean_unsigned_to_nat(9u);
v___x_1095_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1061_, v___x_1093_, v___x_1094_);
v___x_1096_ = lean_nat_dec_eq(v___x_1095_, v___x_1075_);
lean_dec(v___x_1095_);
v___y_1063_ = v___x_1096_;
goto v___jp_1062_;
}
}
}
v___jp_1062_:
{
if (v___y_1063_ == 0)
{
return v___y_1063_;
}
else
{
lean_object* v___x_1064_; lean_object* v___x_1065_; lean_object* v___x_1066_; uint8_t v___x_1067_; 
v___x_1064_ = lean_unsigned_to_nat(27u);
v___x_1065_ = lean_unsigned_to_nat(28u);
v___x_1066_ = lean_unsigned_to_nat(11u);
v___x_1067_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1061_, v___x_1064_, v___x_1065_, v___x_1066_);
if (v___x_1067_ == 0)
{
return v___x_1067_;
}
else
{
lean_object* v___x_1068_; lean_object* v___x_1069_; lean_object* v___x_1070_; uint8_t v___x_1071_; 
v___x_1068_ = lean_unsigned_to_nat(39u);
v___x_1069_ = lean_unsigned_to_nat(40u);
v___x_1070_ = lean_unsigned_to_nat(12u);
v___x_1071_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1061_, v___x_1068_, v___x_1069_, v___x_1070_);
return v___x_1071_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid45___boxed(lean_object* v_word_1097_){
_start:
{
uint8_t v_res_1098_; lean_object* v_r_1099_; 
v_res_1098_ = lp_lean1090_Lean1090_Impl_cbValid45(v_word_1097_);
lean_dec(v_word_1097_);
v_r_1099_ = lean_box(v_res_1098_);
return v_r_1099_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1100_; lean_object* v___x_1101_; 
v___x_1100_ = lean_unsigned_to_nat(45u);
v___x_1101_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1100_);
return v___x_1101_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0(lean_object* v_code_1102_){
_start:
{
uint8_t v___x_1103_; lean_object* v___x_1104_; lean_object* v___x_1105_; lean_object* v___x_1106_; lean_object* v___x_1107_; lean_object* v___x_1108_; lean_object* v___x_1109_; lean_object* v___x_1110_; lean_object* v___x_1111_; uint8_t v___x_1112_; 
v___x_1103_ = 1;
v___x_1104_ = lean_unsigned_to_nat(10u);
v___x_1105_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1103_, v___x_1104_, v_code_1102_);
v___x_1106_ = l_Rat_ofInt(v___x_1105_);
v___x_1107_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0);
v___x_1108_ = l_Rat_mul(v___x_1106_, v___x_1107_);
lean_dec_ref(v___x_1106_);
v___x_1109_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1110_ = l_Rat_div(v___x_1108_, v___x_1109_);
lean_dec_ref(v___x_1108_);
v___x_1111_ = l_Rat_abs(v___x_1110_);
v___x_1112_ = l_Rat_instDecidableLe(v___x_1111_, v___x_1107_);
return v___x_1112_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___boxed(lean_object* v_code_1113_){
_start:
{
uint8_t v_res_1114_; lean_object* v_r_1115_; 
v_res_1114_ = lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0(v_code_1113_);
v_r_1115_ = lean_box(v_res_1114_);
return v_r_1115_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__1(void){
_start:
{
lean_object* v___f_1117_; lean_object* v___x_1118_; lean_object* v___x_1119_; 
v___f_1117_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__0));
v___x_1118_ = lean_unsigned_to_nat(1024u);
v___x_1119_ = l_Array_ofFn___redArg(v___x_1118_, v___f_1117_);
return v___x_1119_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table(void){
_start:
{
lean_object* v___x_1120_; 
v___x_1120_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__1, &lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table___closed__1);
return v___x_1120_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbRollValid50(lean_object* v_word_1121_){
_start:
{
lean_object* v___x_1122_; lean_object* v___x_1123_; lean_object* v___x_1124_; lean_object* v___x_1125_; lean_object* v___x_1126_; uint8_t v___x_1127_; 
v___x_1122_ = lp_lean1090_Lean1090_Impl_cbRollValid50Table;
v___x_1123_ = lean_unsigned_to_nat(2u);
v___x_1124_ = lean_unsigned_to_nat(10u);
v___x_1125_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1121_, v___x_1123_, v___x_1124_);
v___x_1126_ = lean_array_fget_borrowed(v___x_1122_, v___x_1125_);
lean_dec(v___x_1125_);
v___x_1127_ = lean_unbox(v___x_1126_);
return v___x_1127_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollValid50___boxed(lean_object* v_word_1128_){
_start:
{
uint8_t v_res_1129_; lean_object* v_r_1130_; 
v_res_1129_ = lp_lean1090_Lean1090_Impl_cbRollValid50(v_word_1128_);
lean_dec(v_word_1128_);
v_r_1130_ = lean_box(v_res_1129_);
return v_r_1130_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid50(lean_object* v_word_1131_){
_start:
{
uint8_t v___y_1133_; lean_object* v___x_1160_; lean_object* v___x_1161_; lean_object* v___x_1162_; uint8_t v___x_1163_; 
v___x_1160_ = lean_unsigned_to_nat(1u);
v___x_1161_ = lean_unsigned_to_nat(2u);
v___x_1162_ = lean_unsigned_to_nat(10u);
v___x_1163_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1131_, v___x_1160_, v___x_1161_, v___x_1162_);
if (v___x_1163_ == 0)
{
v___y_1133_ = v___x_1163_;
goto v___jp_1132_;
}
else
{
lean_object* v___x_1164_; lean_object* v___x_1165_; lean_object* v___x_1166_; uint8_t v___x_1167_; 
v___x_1164_ = lean_unsigned_to_nat(12u);
v___x_1165_ = lean_unsigned_to_nat(13u);
v___x_1166_ = lean_unsigned_to_nat(11u);
v___x_1167_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1131_, v___x_1164_, v___x_1165_, v___x_1166_);
v___y_1133_ = v___x_1167_;
goto v___jp_1132_;
}
v___jp_1132_:
{
if (v___y_1133_ == 0)
{
return v___y_1133_;
}
else
{
lean_object* v___x_1134_; lean_object* v___x_1135_; lean_object* v___x_1136_; uint8_t v___x_1137_; 
v___x_1134_ = lean_unsigned_to_nat(24u);
v___x_1135_ = lean_unsigned_to_nat(25u);
v___x_1136_ = lean_unsigned_to_nat(10u);
v___x_1137_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1131_, v___x_1134_, v___x_1135_, v___x_1136_);
if (v___x_1137_ == 0)
{
return v___x_1137_;
}
else
{
lean_object* v___x_1138_; lean_object* v___x_1139_; uint8_t v___x_1140_; 
v___x_1138_ = lean_unsigned_to_nat(35u);
v___x_1139_ = lean_unsigned_to_nat(36u);
v___x_1140_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1131_, v___x_1138_, v___x_1139_, v___x_1136_);
if (v___x_1140_ == 0)
{
return v___x_1140_;
}
else
{
lean_object* v___x_1141_; lean_object* v___x_1142_; uint8_t v___x_1143_; 
v___x_1141_ = lean_unsigned_to_nat(46u);
v___x_1142_ = lean_unsigned_to_nat(47u);
v___x_1143_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1131_, v___x_1141_, v___x_1142_, v___x_1136_);
if (v___x_1143_ == 0)
{
return v___x_1143_;
}
else
{
uint8_t v___x_1144_; 
v___x_1144_ = lp_lean1090_Lean1090_Impl_cbRollValid50(v_word_1131_);
if (v___x_1144_ == 0)
{
return v___x_1144_;
}
else
{
lean_object* v___x_1145_; lean_object* v___x_1146_; lean_object* v___x_1147_; lean_object* v___x_1148_; uint8_t v___x_1149_; 
v___x_1145_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1131_, v___x_1135_, v___x_1136_);
v___x_1146_ = lean_unsigned_to_nat(2u);
v___x_1147_ = lean_nat_mul(v___x_1145_, v___x_1146_);
lean_dec(v___x_1145_);
v___x_1148_ = lean_unsigned_to_nat(700u);
v___x_1149_ = lean_nat_dec_le(v___x_1147_, v___x_1148_);
lean_dec(v___x_1147_);
if (v___x_1149_ == 0)
{
return v___x_1149_;
}
else
{
lean_object* v___x_1150_; lean_object* v___x_1151_; lean_object* v___x_1152_; uint8_t v___x_1153_; 
v___x_1150_ = lean_unsigned_to_nat(1u);
v___x_1151_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1131_, v___x_1141_, v___x_1150_);
v___x_1152_ = lean_unsigned_to_nat(0u);
v___x_1153_ = lean_nat_dec_eq(v___x_1151_, v___x_1152_);
lean_dec(v___x_1151_);
if (v___x_1153_ == 0)
{
lean_object* v___x_1154_; lean_object* v___x_1155_; lean_object* v___x_1156_; uint8_t v___x_1157_; 
v___x_1154_ = lean_unsigned_to_nat(80u);
v___x_1155_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1131_, v___x_1142_, v___x_1136_);
v___x_1156_ = lean_nat_mul(v___x_1155_, v___x_1146_);
lean_dec(v___x_1155_);
v___x_1157_ = lean_nat_dec_le(v___x_1154_, v___x_1156_);
if (v___x_1157_ == 0)
{
lean_dec(v___x_1156_);
return v___x_1157_;
}
else
{
lean_object* v___x_1158_; uint8_t v___x_1159_; 
v___x_1158_ = lean_unsigned_to_nat(600u);
v___x_1159_ = lean_nat_dec_le(v___x_1156_, v___x_1158_);
lean_dec(v___x_1156_);
return v___x_1159_;
}
}
else
{
return v___x_1153_;
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid50___boxed(lean_object* v_word_1168_){
_start:
{
uint8_t v_res_1169_; lean_object* v_r_1170_; 
v_res_1169_ = lp_lean1090_Lean1090_Impl_cbValid50(v_word_1168_);
lean_dec(v_word_1168_);
v_r_1170_ = lean_box(v_res_1169_);
return v_r_1170_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbMachValid60Table_spec__0(size_t v_sz_1171_, size_t v_i_1172_, lean_object* v_bs_1173_){
_start:
{
uint8_t v___x_1174_; 
v___x_1174_ = lean_usize_dec_lt(v_i_1172_, v_sz_1171_);
if (v___x_1174_ == 0)
{
return v_bs_1173_;
}
else
{
lean_object* v_v_1175_; lean_object* v___x_1176_; lean_object* v_bs_x27_1177_; lean_object* v___x_1178_; uint8_t v___x_1179_; size_t v___x_1180_; size_t v___x_1181_; lean_object* v___x_1182_; lean_object* v___x_1183_; 
v_v_1175_ = lean_array_uget(v_bs_1173_, v_i_1172_);
v___x_1176_ = lean_unsigned_to_nat(0u);
v_bs_x27_1177_ = lean_array_uset(v_bs_1173_, v_i_1172_, v___x_1176_);
v___x_1178_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0);
v___x_1179_ = l_Rat_instDecidableLe(v_v_1175_, v___x_1178_);
v___x_1180_ = ((size_t)1ULL);
v___x_1181_ = lean_usize_add(v_i_1172_, v___x_1180_);
v___x_1182_ = lean_box(v___x_1179_);
v___x_1183_ = lean_array_uset(v_bs_x27_1177_, v_i_1172_, v___x_1182_);
v_i_1172_ = v___x_1181_;
v_bs_1173_ = v___x_1183_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbMachValid60Table_spec__0___boxed(lean_object* v_sz_1185_, lean_object* v_i_1186_, lean_object* v_bs_1187_){
_start:
{
size_t v_sz_boxed_1188_; size_t v_i_boxed_1189_; lean_object* v_res_1190_; 
v_sz_boxed_1188_ = lean_unbox_usize(v_sz_1185_);
lean_dec(v_sz_1185_);
v_i_boxed_1189_ = lean_unbox_usize(v_i_1186_);
lean_dec(v_i_1186_);
v_res_1190_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbMachValid60Table_spec__0(v_sz_boxed_1188_, v_i_boxed_1189_, v_bs_1187_);
return v_res_1190_;
}
}
static size_t _init_lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__0(void){
_start:
{
lean_object* v___x_1191_; size_t v_sz_1192_; 
v___x_1191_ = lp_lean1090_Lean1090_Impl_cbMachValueTable;
v_sz_1192_ = lean_array_size(v___x_1191_);
return v_sz_1192_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__1(void){
_start:
{
lean_object* v___x_1193_; size_t v___x_1194_; size_t v_sz_1195_; lean_object* v___x_1196_; 
v___x_1193_ = lp_lean1090_Lean1090_Impl_cbMachValueTable;
v___x_1194_ = ((size_t)0ULL);
v_sz_1195_ = lean_usize_once(&lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__0, &lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__0);
v___x_1196_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean1090_Impl_cbMachValid60Table_spec__0(v_sz_1195_, v___x_1194_, v___x_1193_);
return v___x_1196_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachValid60Table(void){
_start:
{
lean_object* v___x_1197_; 
v___x_1197_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__1, &lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbMachValid60Table___closed__1);
return v___x_1197_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbMachValid60(lean_object* v_word_1198_){
_start:
{
lean_object* v___x_1199_; lean_object* v___x_1200_; lean_object* v___x_1201_; lean_object* v___x_1202_; lean_object* v___x_1203_; uint8_t v___x_1204_; 
v___x_1199_ = lp_lean1090_Lean1090_Impl_cbMachValid60Table;
v___x_1200_ = lean_unsigned_to_nat(25u);
v___x_1201_ = lean_unsigned_to_nat(10u);
v___x_1202_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1198_, v___x_1200_, v___x_1201_);
v___x_1203_ = lean_array_fget_borrowed(v___x_1199_, v___x_1202_);
lean_dec(v___x_1202_);
v___x_1204_ = lean_unbox(v___x_1203_);
return v___x_1204_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachValid60___boxed(lean_object* v_word_1205_){
_start:
{
uint8_t v_res_1206_; lean_object* v_r_1207_; 
v_res_1206_ = lp_lean1090_Lean1090_Impl_cbMachValid60(v_word_1205_);
lean_dec(v_word_1205_);
v_r_1207_ = lean_box(v_res_1206_);
return v_r_1207_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1208_; lean_object* v___x_1209_; 
v___x_1208_ = lean_unsigned_to_nat(6000u);
v___x_1209_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1208_);
return v___x_1209_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0(lean_object* v_code_1210_){
_start:
{
lean_object* v___x_1211_; lean_object* v___x_1212_; lean_object* v___x_1213_; lean_object* v___x_1214_; uint8_t v___x_1215_; 
v___x_1211_ = lean_unsigned_to_nat(47u);
v___x_1212_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_code_1210_, v___x_1211_);
v___x_1213_ = l_Rat_abs(v___x_1212_);
v___x_1214_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___closed__0);
v___x_1215_ = l_Rat_instDecidableLe(v___x_1213_, v___x_1214_);
return v___x_1215_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0___boxed(lean_object* v_code_1216_){
_start:
{
uint8_t v_res_1217_; lean_object* v_r_1218_; 
v_res_1217_ = lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___lam__0(v_code_1216_);
lean_dec(v_code_1216_);
v_r_1218_ = lean_box(v_res_1217_);
return v_r_1218_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__1(void){
_start:
{
lean_object* v___f_1220_; lean_object* v___x_1221_; lean_object* v___x_1222_; 
v___f_1220_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__0));
v___x_1221_ = lean_unsigned_to_nat(1024u);
v___x_1222_ = l_Array_ofFn___redArg(v___x_1221_, v___f_1220_);
return v___x_1222_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalValid60Table(void){
_start:
{
lean_object* v___x_1223_; 
v___x_1223_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__1, &lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVerticalValid60Table___closed__1);
return v___x_1223_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbVerticalValid60(lean_object* v_word_1224_){
_start:
{
lean_object* v___x_1225_; lean_object* v___x_1226_; lean_object* v___x_1227_; lean_object* v___x_1228_; lean_object* v___x_1229_; uint8_t v___x_1230_; 
v___x_1225_ = lp_lean1090_Lean1090_Impl_cbVerticalValid60Table;
v___x_1226_ = lean_unsigned_to_nat(47u);
v___x_1227_ = lean_unsigned_to_nat(10u);
v___x_1228_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1224_, v___x_1226_, v___x_1227_);
v___x_1229_ = lean_array_fget_borrowed(v___x_1225_, v___x_1228_);
lean_dec(v___x_1228_);
v___x_1230_ = lean_unbox(v___x_1229_);
return v___x_1230_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalValid60___boxed(lean_object* v_word_1231_){
_start:
{
uint8_t v_res_1232_; lean_object* v_r_1233_; 
v_res_1232_ = lp_lean1090_Lean1090_Impl_cbVerticalValid60(v_word_1231_);
lean_dec(v_word_1231_);
v_r_1233_ = lean_box(v_res_1232_);
return v_r_1233_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid60(lean_object* v_word_1234_){
_start:
{
uint8_t v___y_1236_; lean_object* v___x_1253_; lean_object* v___x_1254_; lean_object* v___x_1255_; uint8_t v___x_1256_; 
v___x_1253_ = lean_unsigned_to_nat(1u);
v___x_1254_ = lean_unsigned_to_nat(2u);
v___x_1255_ = lean_unsigned_to_nat(11u);
v___x_1256_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1234_, v___x_1253_, v___x_1254_, v___x_1255_);
if (v___x_1256_ == 0)
{
v___y_1236_ = v___x_1256_;
goto v___jp_1235_;
}
else
{
lean_object* v___x_1257_; lean_object* v___x_1258_; lean_object* v___x_1259_; uint8_t v___x_1260_; 
v___x_1257_ = lean_unsigned_to_nat(13u);
v___x_1258_ = lean_unsigned_to_nat(14u);
v___x_1259_ = lean_unsigned_to_nat(10u);
v___x_1260_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1234_, v___x_1257_, v___x_1258_, v___x_1259_);
v___y_1236_ = v___x_1260_;
goto v___jp_1235_;
}
v___jp_1235_:
{
if (v___y_1236_ == 0)
{
return v___y_1236_;
}
else
{
lean_object* v___x_1237_; lean_object* v___x_1238_; lean_object* v___x_1239_; uint8_t v___x_1240_; 
v___x_1237_ = lean_unsigned_to_nat(24u);
v___x_1238_ = lean_unsigned_to_nat(25u);
v___x_1239_ = lean_unsigned_to_nat(10u);
v___x_1240_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1234_, v___x_1237_, v___x_1238_, v___x_1239_);
if (v___x_1240_ == 0)
{
return v___x_1240_;
}
else
{
lean_object* v___x_1241_; lean_object* v___x_1242_; uint8_t v___x_1243_; 
v___x_1241_ = lean_unsigned_to_nat(35u);
v___x_1242_ = lean_unsigned_to_nat(36u);
v___x_1243_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1234_, v___x_1241_, v___x_1242_, v___x_1239_);
if (v___x_1243_ == 0)
{
return v___x_1243_;
}
else
{
lean_object* v___x_1244_; lean_object* v___x_1245_; uint8_t v___x_1246_; 
v___x_1244_ = lean_unsigned_to_nat(46u);
v___x_1245_ = lean_unsigned_to_nat(47u);
v___x_1246_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_1234_, v___x_1244_, v___x_1245_, v___x_1239_);
if (v___x_1246_ == 0)
{
return v___x_1246_;
}
else
{
lean_object* v___x_1247_; lean_object* v___x_1248_; lean_object* v___x_1249_; uint8_t v___x_1250_; 
v___x_1247_ = lean_unsigned_to_nat(14u);
v___x_1248_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1234_, v___x_1247_, v___x_1239_);
v___x_1249_ = lean_unsigned_to_nat(500u);
v___x_1250_ = lean_nat_dec_le(v___x_1248_, v___x_1249_);
lean_dec(v___x_1248_);
if (v___x_1250_ == 0)
{
return v___x_1250_;
}
else
{
uint8_t v___x_1251_; 
v___x_1251_ = lp_lean1090_Lean1090_Impl_cbMachValid60(v_word_1234_);
if (v___x_1251_ == 0)
{
return v___x_1251_;
}
else
{
uint8_t v___x_1252_; 
v___x_1252_ = lp_lean1090_Lean1090_Impl_cbVerticalValid60(v_word_1234_);
return v___x_1252_;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid60___boxed(lean_object* v_word_1261_){
_start:
{
uint8_t v_res_1262_; lean_object* v_r_1263_; 
v_res_1262_ = lp_lean1090_Lean1090_Impl_cbValid60(v_word_1261_);
lean_dec(v_word_1261_);
v_r_1263_ = lean_box(v_res_1262_);
return v_r_1263_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBPayloadLimit(void){
_start:
{
lean_object* v___x_1264_; 
v___x_1264_ = lean_cstr_to_nat("72057594037927936");
return v___x_1264_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_bdsWireValid(lean_object* v_register_1265_, lean_object* v_word_1266_){
_start:
{
lean_object* v___x_1267_; uint8_t v___x_1268_; 
v___x_1267_ = lp_lean1090_Lean1090_Impl_commBPayloadLimit;
v___x_1268_ = lean_nat_dec_lt(v_word_1266_, v___x_1267_);
if (v___x_1268_ == 0)
{
return v___x_1268_;
}
else
{
lean_object* v___x_1269_; uint8_t v___x_1270_; 
v___x_1269_ = lean_unsigned_to_nat(5u);
v___x_1270_ = lean_nat_dec_eq(v_register_1265_, v___x_1269_);
if (v___x_1270_ == 0)
{
lean_object* v___x_1271_; uint8_t v___x_1272_; 
v___x_1271_ = lean_unsigned_to_nat(101u);
v___x_1272_ = lean_nat_dec_eq(v_register_1265_, v___x_1271_);
if (v___x_1272_ == 0)
{
lean_object* v___x_1273_; uint8_t v___x_1274_; 
v___x_1273_ = lean_unsigned_to_nat(16u);
v___x_1274_ = lean_nat_dec_eq(v_register_1265_, v___x_1273_);
if (v___x_1274_ == 0)
{
lean_object* v___x_1275_; uint8_t v___x_1276_; 
v___x_1275_ = lean_unsigned_to_nat(23u);
v___x_1276_ = lean_nat_dec_eq(v_register_1265_, v___x_1275_);
if (v___x_1276_ == 0)
{
lean_object* v___x_1277_; uint8_t v___x_1278_; 
v___x_1277_ = lean_unsigned_to_nat(24u);
v___x_1278_ = lean_nat_dec_eq(v_register_1265_, v___x_1277_);
if (v___x_1278_ == 0)
{
lean_object* v___x_1279_; uint8_t v___x_1280_; 
v___x_1279_ = lean_unsigned_to_nat(25u);
v___x_1280_ = lean_nat_dec_eq(v_register_1265_, v___x_1279_);
if (v___x_1280_ == 0)
{
lean_object* v___x_1281_; uint8_t v___x_1282_; 
v___x_1281_ = lean_unsigned_to_nat(32u);
v___x_1282_ = lean_nat_dec_eq(v_register_1265_, v___x_1281_);
if (v___x_1282_ == 0)
{
lean_object* v___x_1283_; uint8_t v___x_1284_; 
v___x_1283_ = lean_unsigned_to_nat(33u);
v___x_1284_ = lean_nat_dec_eq(v_register_1265_, v___x_1283_);
if (v___x_1284_ == 0)
{
lean_object* v___x_1285_; uint8_t v___x_1286_; 
v___x_1285_ = lean_unsigned_to_nat(48u);
v___x_1286_ = lean_nat_dec_eq(v_register_1265_, v___x_1285_);
if (v___x_1286_ == 0)
{
lean_object* v___x_1287_; uint8_t v___x_1288_; 
v___x_1287_ = lean_unsigned_to_nat(64u);
v___x_1288_ = lean_nat_dec_eq(v_register_1265_, v___x_1287_);
if (v___x_1288_ == 0)
{
lean_object* v___x_1289_; uint8_t v___x_1290_; 
v___x_1289_ = lean_unsigned_to_nat(68u);
v___x_1290_ = lean_nat_dec_eq(v_register_1265_, v___x_1289_);
if (v___x_1290_ == 0)
{
lean_object* v___x_1291_; uint8_t v___x_1292_; 
v___x_1291_ = lean_unsigned_to_nat(69u);
v___x_1292_ = lean_nat_dec_eq(v_register_1265_, v___x_1291_);
if (v___x_1292_ == 0)
{
lean_object* v___x_1293_; uint8_t v___x_1294_; 
v___x_1293_ = lean_unsigned_to_nat(80u);
v___x_1294_ = lean_nat_dec_eq(v_register_1265_, v___x_1293_);
if (v___x_1294_ == 0)
{
lean_object* v___x_1295_; uint8_t v___x_1296_; 
v___x_1295_ = lean_unsigned_to_nat(96u);
v___x_1296_ = lean_nat_dec_eq(v_register_1265_, v___x_1295_);
if (v___x_1296_ == 0)
{
return v___x_1296_;
}
else
{
uint8_t v___x_1297_; 
v___x_1297_ = lp_lean1090_Lean1090_Impl_cbValid60(v_word_1266_);
return v___x_1297_;
}
}
else
{
uint8_t v___x_1298_; 
v___x_1298_ = lp_lean1090_Lean1090_Impl_cbValid50(v_word_1266_);
return v___x_1298_;
}
}
else
{
uint8_t v___x_1299_; 
v___x_1299_ = lp_lean1090_Lean1090_Impl_cbValid45(v_word_1266_);
return v___x_1299_;
}
}
else
{
uint8_t v___x_1300_; 
v___x_1300_ = lp_lean1090_Lean1090_Impl_cbValid44(v_word_1266_);
return v___x_1300_;
}
}
else
{
uint8_t v___x_1301_; 
v___x_1301_ = lp_lean1090_Lean1090_Impl_cbValid40(v_word_1266_);
return v___x_1301_;
}
}
else
{
lean_object* v___x_1302_; lean_object* v___x_1303_; lean_object* v___x_1304_; uint8_t v___x_1305_; 
v___x_1302_ = lean_unsigned_to_nat(1u);
v___x_1303_ = lean_unsigned_to_nat(8u);
v___x_1304_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1266_, v___x_1302_, v___x_1303_);
v___x_1305_ = lean_nat_dec_eq(v___x_1304_, v___x_1285_);
lean_dec(v___x_1304_);
return v___x_1305_;
}
}
else
{
uint8_t v___x_1306_; 
v___x_1306_ = lp_lean1090_Lean1090_Impl_cbValid21(v_word_1266_);
return v___x_1306_;
}
}
else
{
lean_object* v___x_1307_; lean_object* v___x_1308_; lean_object* v___x_1309_; uint8_t v___x_1310_; 
v___x_1307_ = lean_unsigned_to_nat(1u);
v___x_1308_ = lean_unsigned_to_nat(8u);
v___x_1309_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1266_, v___x_1307_, v___x_1308_);
v___x_1310_ = lean_nat_dec_eq(v___x_1309_, v___x_1281_);
lean_dec(v___x_1309_);
return v___x_1310_;
}
}
else
{
uint8_t v___x_1311_; 
v___x_1311_ = lp_lean1090_Lean1090_Impl_cbValid19(v_word_1266_);
return v___x_1311_;
}
}
else
{
uint8_t v___x_1312_; 
v___x_1312_ = lp_lean1090_Lean1090_Impl_cbValid18(v_word_1266_);
return v___x_1312_;
}
}
else
{
uint8_t v___x_1313_; 
v___x_1313_ = lp_lean1090_Lean1090_Impl_cbValid17(v_word_1266_);
return v___x_1313_;
}
}
else
{
lean_object* v___x_1314_; lean_object* v___x_1315_; lean_object* v___x_1316_; uint8_t v___x_1317_; 
v___x_1314_ = lean_unsigned_to_nat(1u);
v___x_1315_ = lean_unsigned_to_nat(8u);
v___x_1316_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1266_, v___x_1314_, v___x_1315_);
v___x_1317_ = lean_nat_dec_eq(v___x_1316_, v___x_1273_);
lean_dec(v___x_1316_);
if (v___x_1317_ == 0)
{
return v___x_1317_;
}
else
{
lean_object* v___x_1318_; lean_object* v___x_1319_; lean_object* v___x_1320_; uint8_t v___x_1321_; 
v___x_1318_ = lean_unsigned_to_nat(10u);
v___x_1319_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1266_, v___x_1318_, v___x_1269_);
v___x_1320_ = lean_unsigned_to_nat(0u);
v___x_1321_ = lean_nat_dec_eq(v___x_1319_, v___x_1320_);
lean_dec(v___x_1319_);
return v___x_1321_;
}
}
}
else
{
lean_object* v___x_1322_; lean_object* v___x_1323_; lean_object* v___x_1324_; uint8_t v___x_1325_; 
v___x_1322_ = lean_unsigned_to_nat(1u);
v___x_1323_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1266_, v___x_1322_, v___x_1269_);
v___x_1324_ = lean_unsigned_to_nat(31u);
v___x_1325_ = lean_nat_dec_eq(v___x_1323_, v___x_1324_);
lean_dec(v___x_1323_);
if (v___x_1325_ == 0)
{
return v___x_1325_;
}
else
{
lean_object* v___x_1326_; lean_object* v___x_1327_; lean_object* v___x_1328_; lean_object* v___x_1329_; uint8_t v___x_1330_; 
v___x_1326_ = lean_unsigned_to_nat(6u);
v___x_1327_ = lean_unsigned_to_nat(3u);
v___x_1328_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1266_, v___x_1326_, v___x_1327_);
v___x_1329_ = lean_unsigned_to_nat(2u);
v___x_1330_ = lean_nat_dec_lt(v___x_1328_, v___x_1329_);
lean_dec(v___x_1328_);
if (v___x_1330_ == 0)
{
return v___x_1330_;
}
else
{
uint8_t v___x_1331_; 
v___x_1331_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1266_);
return v___x_1331_;
}
}
}
}
else
{
lean_object* v___x_1332_; lean_object* v_tc_1333_; lean_object* v___x_1340_; uint8_t v___x_1341_; 
v___x_1332_ = lean_unsigned_to_nat(1u);
v_tc_1333_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1266_, v___x_1332_, v___x_1269_);
v___x_1340_ = lean_unsigned_to_nat(9u);
v___x_1341_ = lean_nat_dec_le(v___x_1340_, v_tc_1333_);
if (v___x_1341_ == 0)
{
goto v___jp_1334_;
}
else
{
lean_object* v___x_1342_; uint8_t v___x_1343_; 
v___x_1342_ = lean_unsigned_to_nat(18u);
v___x_1343_ = lean_nat_dec_le(v_tc_1333_, v___x_1342_);
if (v___x_1343_ == 0)
{
goto v___jp_1334_;
}
else
{
uint8_t v___x_1344_; 
lean_dec(v_tc_1333_);
v___x_1344_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1266_);
return v___x_1344_;
}
}
v___jp_1334_:
{
lean_object* v___x_1335_; uint8_t v___x_1336_; 
v___x_1335_ = lean_unsigned_to_nat(20u);
v___x_1336_ = lean_nat_dec_le(v___x_1335_, v_tc_1333_);
if (v___x_1336_ == 0)
{
lean_dec(v_tc_1333_);
return v___x_1336_;
}
else
{
lean_object* v___x_1337_; uint8_t v___x_1338_; 
v___x_1337_ = lean_unsigned_to_nat(22u);
v___x_1338_ = lean_nat_dec_le(v_tc_1333_, v___x_1337_);
lean_dec(v_tc_1333_);
if (v___x_1338_ == 0)
{
return v___x_1338_;
}
else
{
uint8_t v___x_1339_; 
v___x_1339_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1266_);
return v___x_1339_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsWireValid___boxed(lean_object* v_register_1345_, lean_object* v_word_1346_){
_start:
{
uint8_t v_res_1347_; lean_object* v_r_1348_; 
v_res_1347_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1345_, v_word_1346_);
lean_dec(v_word_1346_);
lean_dec(v_register_1345_);
v_r_1348_ = lean_box(v_res_1347_);
return v_r_1348_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_bdsLayout___closed__0(void){
_start:
{
lean_object* v___x_1349_; lean_object* v___x_1350_; 
v___x_1349_ = lp_lean1090_Lean1090_Impl_adsbPositionLayout;
v___x_1350_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1350_, 0, v___x_1349_);
return v___x_1350_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsLayout(lean_object* v_register_1351_, lean_object* v_word_1352_){
_start:
{
lean_object* v___x_1353_; uint8_t v___x_1354_; 
v___x_1353_ = lean_unsigned_to_nat(5u);
v___x_1354_ = lean_nat_dec_eq(v_register_1351_, v___x_1353_);
if (v___x_1354_ == 0)
{
lean_object* v___x_1355_; uint8_t v___x_1356_; 
v___x_1355_ = lean_unsigned_to_nat(101u);
v___x_1356_ = lean_nat_dec_eq(v_register_1351_, v___x_1355_);
if (v___x_1356_ == 0)
{
lean_object* v___x_1357_; 
v___x_1357_ = lp_lean1090_Lean1090_Impl_commBLayout(v_register_1351_);
return v___x_1357_;
}
else
{
lean_object* v___x_1358_; 
v___x_1358_ = lp_lean1090_Lean1090_Impl_adsbLayout(v_word_1352_);
return v___x_1358_;
}
}
else
{
lean_object* v___x_1359_; 
v___x_1359_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_bdsLayout___closed__0, &lp_lean1090_Lean1090_Impl_bdsLayout___closed__0_once, _init_lp_lean1090_Lean1090_Impl_bdsLayout___closed__0);
return v___x_1359_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsLayout___boxed(lean_object* v_register_1360_, lean_object* v_word_1361_){
_start:
{
lean_object* v_res_1362_; 
v_res_1362_ = lp_lean1090_Lean1090_Impl_bdsLayout(v_register_1360_, v_word_1361_);
lean_dec(v_word_1361_);
lean_dec(v_register_1360_);
return v_res_1362_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeBDS(lean_object* v_register_1363_, lean_object* v_word_1364_){
_start:
{
lean_object* v___x_1365_; 
v___x_1365_ = lp_lean1090_Lean1090_Impl_bdsLayout(v_register_1363_, v_word_1364_);
if (lean_obj_tag(v___x_1365_) == 0)
{
lean_object* v___x_1366_; 
lean_dec(v_register_1363_);
v___x_1366_ = lean_box(0);
return v___x_1366_;
}
else
{
lean_object* v_val_1367_; lean_object* v___x_1369_; uint8_t v_isShared_1370_; uint8_t v_isSharedCheck_1378_; 
v_val_1367_ = lean_ctor_get(v___x_1365_, 0);
v_isSharedCheck_1378_ = !lean_is_exclusive(v___x_1365_);
if (v_isSharedCheck_1378_ == 0)
{
v___x_1369_ = v___x_1365_;
v_isShared_1370_ = v_isSharedCheck_1378_;
goto v_resetjp_1368_;
}
else
{
lean_inc(v_val_1367_);
lean_dec(v___x_1365_);
v___x_1369_ = lean_box(0);
v_isShared_1370_ = v_isSharedCheck_1378_;
goto v_resetjp_1368_;
}
v_resetjp_1368_:
{
uint8_t v___x_1371_; 
v___x_1371_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1363_, v_word_1364_);
if (v___x_1371_ == 0)
{
lean_object* v___x_1372_; 
lean_del_object(v___x_1369_);
lean_dec(v_val_1367_);
lean_dec(v_register_1363_);
v___x_1372_ = lean_box(0);
return v___x_1372_;
}
else
{
lean_object* v___x_1373_; lean_object* v___x_1374_; lean_object* v___x_1376_; 
v___x_1373_ = lp_lean1090_Lean1090_Impl_decodePayloadFields(v_val_1367_, v_word_1364_);
v___x_1374_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1374_, 0, v_register_1363_);
lean_ctor_set(v___x_1374_, 1, v___x_1373_);
if (v_isShared_1370_ == 0)
{
lean_ctor_set(v___x_1369_, 0, v___x_1374_);
v___x_1376_ = v___x_1369_;
goto v_reusejp_1375_;
}
else
{
lean_object* v_reuseFailAlloc_1377_; 
v_reuseFailAlloc_1377_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1377_, 0, v___x_1374_);
v___x_1376_ = v_reuseFailAlloc_1377_;
goto v_reusejp_1375_;
}
v_reusejp_1375_:
{
return v___x_1376_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeBDS___boxed(lean_object* v_register_1379_, lean_object* v_word_1380_){
_start:
{
lean_object* v_res_1381_; 
v_res_1381_ = lp_lean1090_Lean1090_Impl_decodeBDS(v_register_1379_, v_word_1380_);
lean_dec(v_word_1380_);
return v_res_1381_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__0(void){
_start:
{
lean_object* v___x_1382_; lean_object* v___x_1383_; 
v___x_1382_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0);
v___x_1383_ = l_Rat_neg(v___x_1382_);
return v___x_1383_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1(void){
_start:
{
lean_object* v___x_1384_; lean_object* v___x_1385_; 
v___x_1384_ = lean_unsigned_to_nat(2u);
v___x_1385_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1384_);
return v___x_1385_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__2(void){
_start:
{
lean_object* v___x_1386_; lean_object* v___x_1387_; lean_object* v___x_1388_; 
v___x_1386_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1387_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__0, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__0);
v___x_1388_ = l_Rat_div(v___x_1387_, v___x_1386_);
return v___x_1388_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGaussian(lean_object* v_value_1389_, lean_object* v_mu_1390_, lean_object* v_sigma_1391_){
_start:
{
lean_object* v___x_1392_; lean_object* v___x_1393_; lean_object* v___x_1394_; lean_object* v_z_1395_; lean_object* v___x_1396_; lean_object* v___x_1397_; lean_object* v___x_1398_; 
v___x_1392_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_mu_1390_);
v___x_1393_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_value_1389_, v___x_1392_);
v___x_1394_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_sigma_1391_);
v_z_1395_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1393_, v___x_1394_);
lean_dec_ref(v___x_1393_);
v___x_1396_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__2, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__2);
lean_inc_ref(v_z_1395_);
v___x_1397_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1396_, v_z_1395_);
v___x_1398_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1397_, v_z_1395_);
lean_dec_ref(v___x_1397_);
return v___x_1398_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbLaplace(lean_object* v_value_1399_, lean_object* v_median_1400_, lean_object* v_scale_1401_){
_start:
{
lean_object* v___x_1402_; uint8_t v___x_1403_; 
v___x_1402_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_scale_1401_);
v___x_1403_ = l_Rat_instDecidableLe(v_scale_1401_, v___x_1402_);
if (v___x_1403_ == 0)
{
lean_object* v___x_1404_; lean_object* v___x_1405_; lean_object* v___x_1406_; lean_object* v___x_1407_; lean_object* v___x_1408_; lean_object* v___x_1409_; 
v___x_1404_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_median_1400_);
v___x_1405_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_value_1399_, v___x_1404_);
v___x_1406_ = l_Rat_abs(v___x_1405_);
v___x_1407_ = l_Rat_neg(v___x_1406_);
v___x_1408_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_scale_1401_);
v___x_1409_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1407_, v___x_1408_);
lean_dec_ref(v___x_1407_);
return v___x_1409_;
}
else
{
lean_dec_ref(v_scale_1401_);
lean_dec_ref(v_median_1400_);
lean_dec_ref(v_value_1399_);
return v___x_1402_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScoreField(lean_object* v_value_1410_, lean_object* v_score_1411_){
_start:
{
if (lean_obj_tag(v_value_1410_) == 0)
{
lean_object* v___x_1412_; 
lean_dec_ref(v_score_1411_);
v___x_1412_ = lean_box(0);
return v___x_1412_;
}
else
{
lean_object* v_val_1413_; lean_object* v___x_1414_; lean_object* v___x_1415_; lean_object* v___x_1416_; 
v_val_1413_ = lean_ctor_get(v_value_1410_, 0);
lean_inc(v_val_1413_);
lean_dec_ref_known(v_value_1410_, 1);
v___x_1414_ = lean_apply_1(v_score_1411_, v_val_1413_);
v___x_1415_ = lean_box(0);
v___x_1416_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1416_, 0, v___x_1414_);
lean_ctor_set(v___x_1416_, 1, v___x_1415_);
return v___x_1416_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1417_; lean_object* v___x_1418_; 
v___x_1417_ = lean_unsigned_to_nat(142u);
v___x_1418_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1417_);
return v___x_1418_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1(void){
_start:
{
lean_object* v___x_1419_; lean_object* v___x_1420_; 
v___x_1419_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0);
v___x_1420_ = l_Rat_neg(v___x_1419_);
return v___x_1420_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2(void){
_start:
{
lean_object* v___x_1421_; lean_object* v___x_1422_; lean_object* v___x_1423_; 
v___x_1421_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1422_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1);
v___x_1423_ = l_Rat_div(v___x_1422_, v___x_1421_);
return v___x_1423_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3(void){
_start:
{
lean_object* v___x_1424_; lean_object* v___x_1425_; 
v___x_1424_ = lean_unsigned_to_nat(164u);
v___x_1425_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1424_);
return v___x_1425_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4(void){
_start:
{
lean_object* v___x_1426_; lean_object* v___x_1427_; lean_object* v___x_1428_; 
v___x_1426_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1427_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3);
v___x_1428_ = l_Rat_div(v___x_1427_, v___x_1426_);
return v___x_1428_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0(lean_object* v_x_1429_){
_start:
{
lean_object* v___x_1430_; lean_object* v___x_1431_; lean_object* v___x_1432_; 
v___x_1430_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2);
v___x_1431_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4);
v___x_1432_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1429_, v___x_1430_, v___x_1431_);
return v___x_1432_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0(void){
_start:
{
lean_object* v___x_1433_; lean_object* v___x_1434_; 
v___x_1433_ = lean_unsigned_to_nat(393u);
v___x_1434_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1433_);
return v___x_1434_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1(void){
_start:
{
lean_object* v___x_1435_; lean_object* v___x_1436_; 
v___x_1435_ = lean_unsigned_to_nat(290u);
v___x_1436_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1435_);
return v___x_1436_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1(lean_object* v_x_1437_){
_start:
{
lean_object* v___x_1438_; lean_object* v___x_1439_; lean_object* v___x_1440_; 
v___x_1438_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0);
v___x_1439_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1);
v___x_1440_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1437_, v___x_1438_, v___x_1439_);
return v___x_1440_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0(void){
_start:
{
lean_object* v___x_1441_; lean_object* v___x_1442_; 
v___x_1441_ = lean_unsigned_to_nat(52u);
v___x_1442_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1441_);
return v___x_1442_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1(void){
_start:
{
lean_object* v___x_1443_; lean_object* v___x_1444_; 
v___x_1443_ = lean_unsigned_to_nat(29u);
v___x_1444_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1443_);
return v___x_1444_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2(lean_object* v_x_1445_){
_start:
{
lean_object* v___x_1446_; lean_object* v___x_1447_; lean_object* v___x_1448_; 
v___x_1446_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0);
v___x_1447_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1);
v___x_1448_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1445_, v___x_1446_, v___x_1447_);
return v___x_1448_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0(void){
_start:
{
lean_object* v___x_1449_; lean_object* v___x_1450_; 
v___x_1449_ = lean_unsigned_to_nat(272u);
v___x_1450_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1449_);
return v___x_1450_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1(void){
_start:
{
lean_object* v___x_1451_; lean_object* v___x_1452_; 
v___x_1451_ = lean_unsigned_to_nat(55u);
v___x_1452_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1451_);
return v___x_1452_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4(lean_object* v_x_1453_){
_start:
{
lean_object* v___x_1454_; lean_object* v___x_1455_; lean_object* v___x_1456_; 
v___x_1454_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0);
v___x_1455_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1);
v___x_1456_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1453_, v___x_1454_, v___x_1455_);
return v___x_1456_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0(void){
_start:
{
lean_object* v___x_1457_; lean_object* v___x_1458_; 
v___x_1457_ = lean_unsigned_to_nat(69u);
v___x_1458_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1457_);
return v___x_1458_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1(void){
_start:
{
lean_object* v___x_1459_; lean_object* v___x_1460_; 
v___x_1459_ = lean_unsigned_to_nat(100u);
v___x_1460_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1459_);
return v___x_1460_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2(void){
_start:
{
lean_object* v___x_1461_; lean_object* v___x_1462_; lean_object* v___x_1463_; 
v___x_1461_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1462_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0);
v___x_1463_ = l_Rat_div(v___x_1462_, v___x_1461_);
return v___x_1463_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3(void){
_start:
{
lean_object* v___x_1464_; lean_object* v___x_1465_; 
v___x_1464_ = lean_unsigned_to_nat(21u);
v___x_1465_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1464_);
return v___x_1465_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4(void){
_start:
{
lean_object* v___x_1466_; lean_object* v___x_1467_; lean_object* v___x_1468_; 
v___x_1466_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1467_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3);
v___x_1468_ = l_Rat_div(v___x_1467_, v___x_1466_);
return v___x_1468_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3(lean_object* v_x_1469_){
_start:
{
lean_object* v___x_1470_; lean_object* v___x_1471_; lean_object* v___x_1472_; 
v___x_1470_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2);
v___x_1471_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4);
v___x_1472_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1469_, v___x_1470_, v___x_1471_);
return v___x_1472_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0(void){
_start:
{
lean_object* v___x_1473_; lean_object* v___x_1474_; 
v___x_1473_ = lean_unsigned_to_nat(298u);
v___x_1474_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1473_);
return v___x_1474_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1(void){
_start:
{
lean_object* v___x_1475_; lean_object* v___x_1476_; 
v___x_1475_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0);
v___x_1476_ = l_Rat_neg(v___x_1475_);
return v___x_1476_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2(void){
_start:
{
lean_object* v___x_1477_; lean_object* v___x_1478_; 
v___x_1477_ = lean_unsigned_to_nat(1669u);
v___x_1478_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1477_);
return v___x_1478_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5(lean_object* v_x_1479_){
_start:
{
lean_object* v___x_1480_; lean_object* v___x_1481_; lean_object* v___x_1482_; 
v___x_1480_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1);
v___x_1481_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2);
v___x_1482_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1479_, v___x_1480_, v___x_1481_);
return v___x_1482_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0(void){
_start:
{
lean_object* v___x_1483_; lean_object* v___x_1484_; 
v___x_1483_ = lean_unsigned_to_nat(418u);
v___x_1484_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1483_);
return v___x_1484_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1(void){
_start:
{
lean_object* v___x_1485_; lean_object* v___x_1486_; 
v___x_1485_ = lean_unsigned_to_nat(129u);
v___x_1486_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1485_);
return v___x_1486_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6(lean_object* v_x_1487_){
_start:
{
lean_object* v___x_1488_; lean_object* v___x_1489_; lean_object* v___x_1490_; 
v___x_1488_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0);
v___x_1489_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1);
v___x_1490_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1487_, v___x_1488_, v___x_1489_);
return v___x_1490_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0(void){
_start:
{
lean_object* v___x_1491_; lean_object* v___x_1492_; 
v___x_1491_ = lean_unsigned_to_nat(413u);
v___x_1492_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1491_);
return v___x_1492_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1(void){
_start:
{
lean_object* v___x_1493_; lean_object* v___x_1494_; 
v___x_1493_ = lean_unsigned_to_nat(120u);
v___x_1494_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1493_);
return v___x_1494_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7(lean_object* v_x_1495_){
_start:
{
lean_object* v___x_1496_; lean_object* v___x_1497_; lean_object* v___x_1498_; 
v___x_1496_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0);
v___x_1497_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1);
v___x_1498_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1495_, v___x_1496_, v___x_1497_);
return v___x_1498_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0(void){
_start:
{
lean_object* v___x_1499_; lean_object* v___x_1500_; 
v___x_1499_ = lean_unsigned_to_nat(70u);
v___x_1500_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1499_);
return v___x_1500_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1(void){
_start:
{
lean_object* v___x_1501_; lean_object* v___x_1502_; lean_object* v___x_1503_; 
v___x_1501_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1502_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0);
v___x_1503_ = l_Rat_div(v___x_1502_, v___x_1501_);
return v___x_1503_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8(lean_object* v_x_1504_){
_start:
{
lean_object* v___x_1505_; lean_object* v___x_1506_; lean_object* v___x_1507_; 
v___x_1505_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1506_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1);
v___x_1507_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1504_, v___x_1505_, v___x_1506_);
return v___x_1507_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__9(lean_object* v_x_1508_){
_start:
{
lean_object* v___x_1509_; lean_object* v___x_1510_; lean_object* v___x_1511_; 
v___x_1509_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1510_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1511_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1508_, v___x_1509_, v___x_1510_);
return v___x_1511_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0(void){
_start:
{
lean_object* v___x_1512_; lean_object* v___x_1513_; 
v___x_1512_ = lean_unsigned_to_nat(24688u);
v___x_1513_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1512_);
return v___x_1513_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1(void){
_start:
{
lean_object* v___x_1514_; lean_object* v___x_1515_; 
v___x_1514_ = lean_unsigned_to_nat(10844u);
v___x_1515_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1514_);
return v___x_1515_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10(lean_object* v_x_1516_){
_start:
{
lean_object* v___x_1517_; lean_object* v___x_1518_; lean_object* v___x_1519_; 
v___x_1517_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0);
v___x_1518_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1);
v___x_1519_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1516_, v___x_1517_, v___x_1518_);
return v___x_1519_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0(void){
_start:
{
lean_object* v___x_1520_; lean_object* v___x_1521_; 
v___x_1520_ = lean_unsigned_to_nat(10132u);
v___x_1521_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1520_);
return v___x_1521_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1(void){
_start:
{
lean_object* v___x_1522_; lean_object* v___x_1523_; lean_object* v___x_1524_; 
v___x_1522_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1523_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0);
v___x_1524_ = l_Rat_div(v___x_1523_, v___x_1522_);
return v___x_1524_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2(void){
_start:
{
lean_object* v___x_1525_; lean_object* v___x_1526_; 
v___x_1525_ = lean_unsigned_to_nat(54u);
v___x_1526_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1525_);
return v___x_1526_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3(void){
_start:
{
lean_object* v___x_1527_; lean_object* v___x_1528_; lean_object* v___x_1529_; 
v___x_1527_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1528_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2);
v___x_1529_ = l_Rat_div(v___x_1528_, v___x_1527_);
return v___x_1529_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11(lean_object* v_x_1530_){
_start:
{
lean_object* v___x_1531_; lean_object* v___x_1532_; lean_object* v___x_1533_; 
v___x_1531_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1);
v___x_1532_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3);
v___x_1533_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1530_, v___x_1531_, v___x_1532_);
return v___x_1533_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5(void){
_start:
{
lean_object* v___x_1539_; lean_object* v___x_1540_; 
v___x_1539_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3);
v___x_1540_ = l_Rat_neg(v___x_1539_);
return v___x_1540_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6(void){
_start:
{
lean_object* v___x_1541_; lean_object* v___x_1542_; 
v___x_1541_ = lean_unsigned_to_nat(990u);
v___x_1542_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1541_);
return v___x_1542_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7(void){
_start:
{
lean_object* v___x_1543_; lean_object* v___x_1544_; lean_object* v___x_1545_; 
v___x_1543_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1544_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6);
v___x_1545_ = l_Rat_div(v___x_1544_, v___x_1543_);
return v___x_1545_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms(lean_object* v_register_1563_, lean_object* v_word_1564_){
_start:
{
lean_object* v___x_1565_; uint8_t v___x_1566_; 
v___x_1565_ = lean_unsigned_to_nat(64u);
v___x_1566_ = lean_nat_dec_eq(v_register_1563_, v___x_1565_);
if (v___x_1566_ == 0)
{
lean_object* v___x_1567_; uint8_t v___x_1568_; 
v___x_1567_ = lean_unsigned_to_nat(80u);
v___x_1568_ = lean_nat_dec_eq(v_register_1563_, v___x_1567_);
if (v___x_1568_ == 0)
{
lean_object* v___x_1569_; uint8_t v___x_1570_; 
v___x_1569_ = lean_unsigned_to_nat(96u);
v___x_1570_ = lean_nat_dec_eq(v_register_1563_, v___x_1569_);
if (v___x_1570_ == 0)
{
lean_object* v___x_1571_; uint8_t v___x_1572_; 
v___x_1571_ = lean_unsigned_to_nat(68u);
v___x_1572_ = lean_nat_dec_eq(v_register_1563_, v___x_1571_);
if (v___x_1572_ == 0)
{
lean_object* v___x_1573_; uint8_t v___x_1574_; 
v___x_1573_ = lean_unsigned_to_nat(69u);
v___x_1574_ = lean_nat_dec_eq(v_register_1563_, v___x_1573_);
if (v___x_1574_ == 0)
{
lean_object* v___x_1575_; 
v___x_1575_ = lean_box(0);
return v___x_1575_;
}
else
{
lean_object* v___f_1576_; lean_object* v___f_1577_; lean_object* v___x_1578_; lean_object* v___x_1579_; lean_object* v___x_1580_; lean_object* v___x_1581_; lean_object* v___x_1582_; lean_object* v___x_1583_; lean_object* v___x_1584_; 
v___f_1576_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__0));
v___f_1577_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1));
v___x_1578_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__2));
v___x_1579_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1578_);
v___x_1580_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1579_, v___f_1576_);
v___x_1581_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__3));
v___x_1582_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1581_);
v___x_1583_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1582_, v___f_1577_);
v___x_1584_ = l_List_appendTR___redArg(v___x_1580_, v___x_1583_);
return v___x_1584_;
}
}
else
{
lean_object* v___f_1585_; lean_object* v___f_1586_; lean_object* v___x_1587_; lean_object* v___x_1588_; lean_object* v___x_1589_; lean_object* v___x_1590_; lean_object* v___x_1591_; lean_object* v___x_1592_; lean_object* v___x_1593_; lean_object* v___x_1594_; lean_object* v___x_1595_; lean_object* v___x_1596_; lean_object* v___x_1597_; lean_object* v___x_1598_; lean_object* v___x_1599_; lean_object* v___x_1600_; 
v___f_1585_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__4));
v___f_1586_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1));
v___x_1587_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_1564_);
v___x_1588_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5);
v___x_1589_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7);
v___x_1590_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1587_, v___x_1588_, v___x_1589_);
v___x_1591_ = lean_box(0);
v___x_1592_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1592_, 0, v___x_1590_);
lean_ctor_set(v___x_1592_, 1, v___x_1591_);
v___x_1593_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__8));
v___x_1594_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1593_);
v___x_1595_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1594_, v___f_1585_);
v___x_1596_ = l_List_appendTR___redArg(v___x_1592_, v___x_1595_);
v___x_1597_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__9));
v___x_1598_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1597_);
v___x_1599_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1598_, v___f_1586_);
v___x_1600_ = l_List_appendTR___redArg(v___x_1596_, v___x_1599_);
return v___x_1600_;
}
}
else
{
lean_object* v___f_1601_; lean_object* v___f_1602_; lean_object* v___f_1603_; lean_object* v___x_1604_; lean_object* v___x_1605_; lean_object* v___x_1606_; lean_object* v___y_1608_; lean_object* v___x_1615_; lean_object* v___x_1616_; 
v___f_1601_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__10));
v___f_1602_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__11));
v___f_1603_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__12));
v___x_1604_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13));
v___x_1605_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1604_);
v___x_1606_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1605_, v___f_1601_);
v___x_1615_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14));
v___x_1616_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1615_);
if (lean_obj_tag(v___x_1616_) == 0)
{
v___y_1608_ = v___x_1616_;
goto v___jp_1607_;
}
else
{
lean_object* v___x_1618_; uint8_t v_isShared_1619_; uint8_t v_isSharedCheck_1624_; 
v_isSharedCheck_1624_ = !lean_is_exclusive(v___x_1616_);
if (v_isSharedCheck_1624_ == 0)
{
lean_object* v_unused_1625_; 
v_unused_1625_ = lean_ctor_get(v___x_1616_, 0);
lean_dec(v_unused_1625_);
v___x_1618_ = v___x_1616_;
v_isShared_1619_ = v_isSharedCheck_1624_;
goto v_resetjp_1617_;
}
else
{
lean_dec(v___x_1616_);
v___x_1618_ = lean_box(0);
v_isShared_1619_ = v_isSharedCheck_1624_;
goto v_resetjp_1617_;
}
v_resetjp_1617_:
{
lean_object* v___x_1620_; lean_object* v___x_1622_; 
v___x_1620_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_1564_);
if (v_isShared_1619_ == 0)
{
lean_ctor_set(v___x_1618_, 0, v___x_1620_);
v___x_1622_ = v___x_1618_;
goto v_reusejp_1621_;
}
else
{
lean_object* v_reuseFailAlloc_1623_; 
v_reuseFailAlloc_1623_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1623_, 0, v___x_1620_);
v___x_1622_ = v_reuseFailAlloc_1623_;
goto v_reusejp_1621_;
}
v_reusejp_1621_:
{
v___y_1608_ = v___x_1622_;
goto v___jp_1607_;
}
}
}
v___jp_1607_:
{
lean_object* v___x_1609_; lean_object* v___x_1610_; lean_object* v___x_1611_; lean_object* v___x_1612_; lean_object* v___x_1613_; lean_object* v___x_1614_; 
v___x_1609_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___y_1608_, v___f_1602_);
v___x_1610_ = l_List_appendTR___redArg(v___x_1606_, v___x_1609_);
v___x_1611_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__2));
v___x_1612_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1611_);
v___x_1613_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1612_, v___f_1603_);
v___x_1614_ = l_List_appendTR___redArg(v___x_1610_, v___x_1613_);
return v___x_1614_;
}
}
}
else
{
lean_object* v___f_1626_; lean_object* v___f_1627_; lean_object* v___f_1628_; lean_object* v___f_1629_; lean_object* v___x_1630_; lean_object* v___x_1631_; lean_object* v___x_1632_; lean_object* v___x_1633_; lean_object* v___x_1634_; lean_object* v___x_1635_; lean_object* v___x_1636_; lean_object* v___x_1637_; lean_object* v___x_1638_; lean_object* v___x_1639_; lean_object* v___x_1640_; lean_object* v___x_1641_; lean_object* v___x_1642_; lean_object* v___x_1643_; lean_object* v___x_1644_; 
v___f_1626_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__15));
v___f_1627_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__16));
v___f_1628_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__17));
v___f_1629_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__18));
v___x_1630_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19));
v___x_1631_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1630_);
v___x_1632_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1631_, v___f_1629_);
v___x_1633_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__4));
v___x_1634_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1633_);
v___x_1635_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1634_, v___f_1628_);
v___x_1636_ = l_List_appendTR___redArg(v___x_1632_, v___x_1635_);
v___x_1637_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__20));
v___x_1638_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1637_);
v___x_1639_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1638_, v___f_1627_);
v___x_1640_ = l_List_appendTR___redArg(v___x_1636_, v___x_1639_);
v___x_1641_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__21));
v___x_1642_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1641_);
v___x_1643_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1642_, v___f_1626_);
v___x_1644_ = l_List_appendTR___redArg(v___x_1640_, v___x_1643_);
return v___x_1644_;
}
}
else
{
lean_object* v___f_1645_; lean_object* v___f_1646_; lean_object* v___y_1648_; lean_object* v___x_1658_; lean_object* v___x_1659_; 
v___f_1645_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__22));
v___f_1646_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__23));
v___x_1658_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__24));
v___x_1659_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1658_);
if (lean_obj_tag(v___x_1659_) == 0)
{
v___y_1648_ = v___x_1659_;
goto v___jp_1647_;
}
else
{
lean_object* v___x_1661_; uint8_t v_isShared_1662_; uint8_t v_isSharedCheck_1667_; 
v_isSharedCheck_1667_ = !lean_is_exclusive(v___x_1659_);
if (v_isSharedCheck_1667_ == 0)
{
lean_object* v_unused_1668_; 
v_unused_1668_ = lean_ctor_get(v___x_1659_, 0);
lean_dec(v_unused_1668_);
v___x_1661_ = v___x_1659_;
v_isShared_1662_ = v_isSharedCheck_1667_;
goto v_resetjp_1660_;
}
else
{
lean_dec(v___x_1659_);
v___x_1661_ = lean_box(0);
v_isShared_1662_ = v_isSharedCheck_1667_;
goto v_resetjp_1660_;
}
v_resetjp_1660_:
{
lean_object* v___x_1663_; lean_object* v___x_1665_; 
v___x_1663_ = lp_lean1090_Lean1090_Impl_cbQNH64(v_word_1564_);
if (v_isShared_1662_ == 0)
{
lean_ctor_set(v___x_1661_, 0, v___x_1663_);
v___x_1665_ = v___x_1661_;
goto v_reusejp_1664_;
}
else
{
lean_object* v_reuseFailAlloc_1666_; 
v_reuseFailAlloc_1666_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1666_, 0, v___x_1663_);
v___x_1665_ = v_reuseFailAlloc_1666_;
goto v_reusejp_1664_;
}
v_reusejp_1664_:
{
v___y_1648_ = v___x_1665_;
goto v___jp_1647_;
}
}
}
v___jp_1647_:
{
lean_object* v___x_1649_; lean_object* v___x_1650_; lean_object* v___x_1651_; lean_object* v___x_1652_; lean_object* v___x_1653_; lean_object* v___x_1654_; lean_object* v___x_1655_; lean_object* v___x_1656_; lean_object* v___x_1657_; 
v___x_1649_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___y_1648_, v___f_1646_);
v___x_1650_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__6));
v___x_1651_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1650_);
v___x_1652_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1651_, v___f_1645_);
v___x_1653_ = l_List_appendTR___redArg(v___x_1649_, v___x_1652_);
v___x_1654_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__7));
v___x_1655_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1563_, v_word_1564_, v___x_1654_);
v___x_1656_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1655_, v___f_1645_);
v___x_1657_ = l_List_appendTR___redArg(v___x_1653_, v___x_1656_);
return v___x_1657_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___boxed(lean_object* v_register_1669_, lean_object* v_word_1670_){
_start:
{
lean_object* v_res_1671_; 
v_res_1671_ = lp_lean1090_Lean1090_Impl_cbDensityTerms(v_register_1669_, v_word_1670_);
lean_dec(v_word_1670_);
lean_dec(v_register_1669_);
return v_res_1671_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_cbDensity_spec__0(lean_object* v_x_1672_, lean_object* v_x_1673_){
_start:
{
if (lean_obj_tag(v_x_1673_) == 0)
{
return v_x_1672_;
}
else
{
lean_object* v_head_1674_; lean_object* v_tail_1675_; lean_object* v___x_1676_; 
v_head_1674_ = lean_ctor_get(v_x_1673_, 0);
lean_inc(v_head_1674_);
v_tail_1675_ = lean_ctor_get(v_x_1673_, 1);
lean_inc(v_tail_1675_);
lean_dec_ref_known(v_x_1673_, 2);
v___x_1676_ = lp_lean1090_Lean1090_Impl_Binary64_add(v_x_1672_, v_head_1674_);
v_x_1672_ = v___x_1676_;
v_x_1673_ = v_tail_1675_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensity(lean_object* v_register_1678_, lean_object* v_word_1679_){
_start:
{
lean_object* v_terms_1680_; uint8_t v___x_1681_; 
v_terms_1680_ = lp_lean1090_Lean1090_Impl_cbDensityTerms(v_register_1678_, v_word_1679_);
v___x_1681_ = l_List_isEmpty___redArg(v_terms_1680_);
if (v___x_1681_ == 0)
{
lean_object* v___x_1682_; lean_object* v___x_1683_; lean_object* v___x_1684_; lean_object* v___x_1685_; lean_object* v___x_1686_; 
v___x_1682_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc(v_terms_1680_);
v___x_1683_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_cbDensity_spec__0(v___x_1682_, v_terms_1680_);
v___x_1684_ = l_List_lengthTR___redArg(v_terms_1680_);
lean_dec(v_terms_1680_);
v___x_1685_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1684_);
v___x_1686_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1683_, v___x_1685_);
lean_dec_ref(v___x_1683_);
return v___x_1686_;
}
else
{
lean_object* v___x_1687_; 
lean_dec(v_terms_1680_);
v___x_1687_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1687_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensity___boxed(lean_object* v_register_1688_, lean_object* v_word_1689_){
_start:
{
lean_object* v_res_1690_; 
v_res_1690_ = lp_lean1090_Lean1090_Impl_cbDensity(v_register_1688_, v_word_1689_);
lean_dec(v_word_1689_);
lean_dec(v_register_1688_);
return v_res_1690_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1691_; lean_object* v___x_1692_; 
v___x_1691_ = lean_unsigned_to_nat(1023u);
v___x_1692_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1691_);
return v___x_1692_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0(lean_object* v_code_1693_){
_start:
{
lean_object* v___x_1694_; lean_object* v___x_1695_; lean_object* v___x_1696_; lean_object* v___x_1697_; lean_object* v___x_1698_; lean_object* v___x_1699_; lean_object* v___x_1700_; lean_object* v___x_1701_; lean_object* v___x_1702_; lean_object* v___x_1703_; lean_object* v___x_1704_; 
v___x_1694_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1695_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1696_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1693_);
v___x_1697_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___lam__0___closed__0);
v___x_1698_ = l_Rat_sub(v___x_1696_, v___x_1697_);
v___x_1699_ = l_Rat_mul(v___x_1695_, v___x_1698_);
v___x_1700_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_1699_);
v___x_1701_ = l_Rat_abs(v___x_1700_);
v___x_1702_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1703_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1701_, v___x_1702_);
lean_dec_ref(v___x_1701_);
v___x_1704_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v___x_1694_, v___x_1703_);
return v___x_1704_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1(void){
_start:
{
lean_object* v___f_1706_; lean_object* v___x_1707_; lean_object* v___x_1708_; 
v___f_1706_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__0));
v___x_1707_ = lean_unsigned_to_nat(2047u);
v___x_1708_ = l_Array_ofFn___redArg(v___x_1707_, v___f_1706_);
return v___x_1708_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable(void){
_start:
{
lean_object* v___x_1709_; 
v___x_1709_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1, &lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbWindPenaltyTable___closed__1);
return v___x_1709_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenalty50(lean_object* v_word_1710_){
_start:
{
lean_object* v___x_1711_; lean_object* v___x_1712_; lean_object* v___x_1713_; lean_object* v___x_1714_; uint8_t v___x_1715_; 
v___x_1711_ = lean_unsigned_to_nat(46u);
v___x_1712_ = lean_unsigned_to_nat(1u);
v___x_1713_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1710_, v___x_1711_, v___x_1712_);
v___x_1714_ = lean_unsigned_to_nat(0u);
v___x_1715_ = lean_nat_dec_eq(v___x_1713_, v___x_1714_);
lean_dec(v___x_1713_);
if (v___x_1715_ == 0)
{
lean_object* v___x_1716_; lean_object* v___x_1717_; uint8_t v___x_1718_; 
v___x_1716_ = lean_unsigned_to_nat(24u);
v___x_1717_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1710_, v___x_1716_, v___x_1712_);
v___x_1718_ = lean_nat_dec_eq(v___x_1717_, v___x_1714_);
lean_dec(v___x_1717_);
if (v___x_1718_ == 0)
{
lean_object* v___x_1719_; lean_object* v___x_1720_; lean_object* v_tas_1721_; lean_object* v___x_1722_; lean_object* v_gs_1723_; lean_object* v___x_1724_; lean_object* v___x_1725_; lean_object* v___x_1726_; lean_object* v___x_1727_; lean_object* v___x_1728_; 
v___x_1719_ = lean_unsigned_to_nat(47u);
v___x_1720_ = lean_unsigned_to_nat(10u);
v_tas_1721_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1710_, v___x_1719_, v___x_1720_);
v___x_1722_ = lean_unsigned_to_nat(25u);
v_gs_1723_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1710_, v___x_1722_, v___x_1720_);
v___x_1724_ = lp_lean1090_Lean1090_Impl_cbWindPenaltyTable;
v___x_1725_ = lean_unsigned_to_nat(1023u);
v___x_1726_ = lean_nat_add(v_tas_1721_, v___x_1725_);
lean_dec(v_tas_1721_);
v___x_1727_ = lean_nat_sub(v___x_1726_, v_gs_1723_);
lean_dec(v_gs_1723_);
lean_dec(v___x_1726_);
v___x_1728_ = lean_array_fget_borrowed(v___x_1724_, v___x_1727_);
lean_dec(v___x_1727_);
lean_inc(v___x_1728_);
return v___x_1728_;
}
else
{
lean_object* v___x_1729_; 
v___x_1729_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1729_;
}
}
else
{
lean_object* v___x_1730_; 
v___x_1730_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1730_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindPenalty50___boxed(lean_object* v_word_1731_){
_start:
{
lean_object* v_res_1732_; 
v_res_1732_ = lp_lean1090_Lean1090_Impl_cbWindPenalty50(v_word_1731_);
lean_dec(v_word_1731_);
return v_res_1732_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0(void){
_start:
{
lean_object* v___x_1733_; lean_object* v_k_1734_; 
v___x_1733_ = lean_cstr_to_nat("2251799813685248");
v_k_1734_ = lean_nat_to_int(v___x_1733_);
return v_k_1734_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__1(void){
_start:
{
lean_object* v___x_1735_; lean_object* v___x_1736_; 
v___x_1735_ = lean_unsigned_to_nat(250u);
v___x_1736_ = lean_nat_to_int(v___x_1735_);
return v___x_1736_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__2(void){
_start:
{
lean_object* v_k_1737_; lean_object* v___x_1738_; lean_object* v___x_1739_; 
v_k_1737_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0);
v___x_1738_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__1, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__1);
v___x_1739_ = lean_int_mul(v___x_1738_, v_k_1737_);
return v___x_1739_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__3(void){
_start:
{
lean_object* v___x_1740_; lean_object* v___x_1741_; 
v___x_1740_ = lean_unsigned_to_nat(250u);
v___x_1741_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1740_);
return v___x_1741_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__4(void){
_start:
{
lean_object* v___x_1742_; lean_object* v___x_1743_; 
v___x_1742_ = lean_unsigned_to_nat(800u);
v___x_1743_ = lean_nat_to_int(v___x_1742_);
return v___x_1743_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__5(void){
_start:
{
lean_object* v_k_1744_; lean_object* v___x_1745_; lean_object* v___x_1746_; 
v_k_1744_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0);
v___x_1745_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__4, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__4);
v___x_1746_ = lean_int_mul(v___x_1745_, v_k_1744_);
return v___x_1746_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbRatioOutside250800(lean_object* v_q_1747_){
_start:
{
lean_object* v_num_1748_; lean_object* v_den_1749_; lean_object* v_d_1750_; lean_object* v_k_1751_; lean_object* v___x_1752_; lean_object* v___x_1753_; lean_object* v_e_1754_; lean_object* v_c_1755_; lean_object* v___x_1756_; lean_object* v_lower_1757_; lean_object* v___x_1758_; uint8_t v___x_1759_; 
v_num_1748_ = lean_ctor_get(v_q_1747_, 0);
v_den_1749_ = lean_ctor_get(v_q_1747_, 1);
lean_inc(v_den_1749_);
v_d_1750_ = lean_nat_to_int(v_den_1749_);
v_k_1751_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__0);
v___x_1752_ = lean_nat_abs(v_num_1748_);
v___x_1753_ = lean_nat_to_int(v___x_1752_);
v_e_1754_ = lean_int_add(v___x_1753_, v_d_1750_);
lean_dec(v___x_1753_);
v_c_1755_ = lean_int_mul(v_k_1751_, v_num_1748_);
v___x_1756_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__2, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__2);
v_lower_1757_ = lean_int_mul(v___x_1756_, v_d_1750_);
v___x_1758_ = lean_int_add(v_c_1755_, v_e_1754_);
v___x_1759_ = lean_int_dec_lt(v___x_1758_, v_lower_1757_);
if (v___x_1759_ == 0)
{
lean_object* v___x_1766_; lean_object* v_upper_1767_; lean_object* v___x_1768_; uint8_t v___x_1769_; 
v___x_1766_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__5, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__5);
v_upper_1767_ = lean_int_mul(v___x_1766_, v_d_1750_);
lean_dec(v_d_1750_);
v___x_1768_ = lean_int_sub(v_c_1755_, v_e_1754_);
lean_dec(v_e_1754_);
lean_dec(v_c_1755_);
v___x_1769_ = lean_int_dec_lt(v_upper_1767_, v___x_1768_);
if (v___x_1769_ == 0)
{
uint8_t v___x_1770_; 
v___x_1770_ = lean_int_dec_le(v_lower_1757_, v___x_1768_);
lean_dec(v___x_1768_);
lean_dec(v_lower_1757_);
if (v___x_1770_ == 0)
{
lean_dec(v_upper_1767_);
lean_dec(v___x_1758_);
goto v___jp_1760_;
}
else
{
uint8_t v___x_1771_; 
v___x_1771_ = lean_int_dec_le(v___x_1758_, v_upper_1767_);
lean_dec(v_upper_1767_);
lean_dec(v___x_1758_);
if (v___x_1771_ == 0)
{
goto v___jp_1760_;
}
else
{
lean_dec_ref(v_q_1747_);
return v___x_1769_;
}
}
}
else
{
lean_dec(v___x_1768_);
lean_dec(v_upper_1767_);
lean_dec(v___x_1758_);
lean_dec(v_lower_1757_);
lean_dec_ref(v_q_1747_);
return v___x_1769_;
}
v___jp_1760_:
{
lean_object* v_rounded_1761_; lean_object* v___x_1762_; uint8_t v___x_1763_; 
v_rounded_1761_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_q_1747_);
v___x_1762_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__3, &lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbRatioOutside250800___closed__3);
lean_inc_ref(v_rounded_1761_);
v___x_1763_ = l_Rat_blt(v_rounded_1761_, v___x_1762_);
if (v___x_1763_ == 0)
{
lean_object* v___x_1764_; uint8_t v___x_1765_; 
v___x_1764_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4);
v___x_1765_ = l_Rat_blt(v___x_1764_, v_rounded_1761_);
return v___x_1765_;
}
else
{
lean_dec_ref(v_rounded_1761_);
return v___x_1763_;
}
}
}
else
{
lean_dec(v___x_1758_);
lean_dec(v_lower_1757_);
lean_dec(v_c_1755_);
lean_dec(v_e_1754_);
lean_dec(v_d_1750_);
lean_dec_ref(v_q_1747_);
return v___x_1759_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRatioOutside250800___boxed(lean_object* v_q_1772_){
_start:
{
uint8_t v_res_1773_; lean_object* v_r_1774_; 
v_res_1773_ = lp_lean1090_Lean1090_Impl_cbRatioOutside250800(v_q_1772_);
v_r_1774_ = lean_box(v_res_1773_);
return v_r_1774_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0(void){
_start:
{
lean_object* v___x_1775_; lean_object* v___x_1776_; 
v___x_1775_ = lean_unsigned_to_nat(3u);
v___x_1776_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1775_);
return v___x_1776_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1(void){
_start:
{
lean_object* v___x_1777_; lean_object* v___x_1778_; 
v___x_1777_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__0, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0);
v___x_1778_ = l_Rat_neg(v___x_1777_);
return v___x_1778_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__2(void){
_start:
{
lean_object* v___x_1779_; lean_object* v___x_1780_; 
v___x_1779_ = lean_unsigned_to_nat(5u);
v___x_1780_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1779_);
return v___x_1780_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__3(void){
_start:
{
lean_object* v___x_1781_; lean_object* v___x_1782_; lean_object* v___x_1783_; 
v___x_1781_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1782_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__0, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0);
v___x_1783_ = l_Rat_div(v___x_1782_, v___x_1781_);
return v___x_1783_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__4(void){
_start:
{
lean_object* v___x_1784_; lean_object* v___x_1785_; 
v___x_1784_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__3, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__3);
v___x_1785_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_1784_);
return v___x_1785_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPenalty(lean_object* v_register_1786_, lean_object* v_word_1787_){
_start:
{
lean_object* v___x_1790_; uint8_t v___x_1791_; 
v___x_1790_ = lean_unsigned_to_nat(80u);
v___x_1791_ = lean_nat_dec_eq(v_register_1786_, v___x_1790_);
if (v___x_1791_ == 0)
{
lean_object* v___x_1792_; uint8_t v___x_1793_; 
v___x_1792_ = lean_unsigned_to_nat(96u);
v___x_1793_ = lean_nat_dec_eq(v_register_1786_, v___x_1792_);
if (v___x_1793_ == 0)
{
lean_object* v___x_1794_; 
v___x_1794_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1794_;
}
else
{
lean_object* v___x_1795_; lean_object* v___x_1796_; 
v___x_1795_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13));
v___x_1796_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1786_, v_word_1787_, v___x_1795_);
if (lean_obj_tag(v___x_1796_) == 1)
{
lean_object* v_val_1797_; lean_object* v___x_1798_; lean_object* v___x_1799_; 
v_val_1797_ = lean_ctor_get(v___x_1796_, 0);
lean_inc(v_val_1797_);
lean_dec_ref_known(v___x_1796_, 1);
v___x_1798_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14));
v___x_1799_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1786_, v_word_1787_, v___x_1798_);
if (lean_obj_tag(v___x_1799_) == 1)
{
lean_object* v_mach_1800_; lean_object* v___x_1801_; uint8_t v___y_1803_; uint8_t v___x_1805_; 
lean_dec_ref_known(v___x_1799_, 1);
v_mach_1800_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_1787_);
v___x_1801_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_mach_1800_);
v___x_1805_ = l_Rat_blt(v___x_1801_, v_mach_1800_);
if (v___x_1805_ == 0)
{
lean_dec_ref(v_mach_1800_);
lean_dec(v_val_1797_);
return v___x_1801_;
}
else
{
if (v___x_1805_ == 0)
{
lean_dec_ref(v_mach_1800_);
lean_dec(v_val_1797_);
v___y_1803_ = v___x_1805_;
goto v___jp_1802_;
}
else
{
lean_object* v___x_1806_; uint8_t v___x_1807_; 
v___x_1806_ = l_Rat_div(v_val_1797_, v_mach_1800_);
lean_dec(v_val_1797_);
v___x_1807_ = lp_lean1090_Lean1090_Impl_cbRatioOutside250800(v___x_1806_);
v___y_1803_ = v___x_1807_;
goto v___jp_1802_;
}
}
v___jp_1802_:
{
if (v___y_1803_ == 0)
{
return v___x_1801_;
}
else
{
lean_object* v___x_1804_; 
v___x_1804_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__1, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1);
return v___x_1804_;
}
}
}
else
{
lean_dec(v___x_1799_);
lean_dec(v_val_1797_);
goto v___jp_1788_;
}
}
else
{
lean_dec(v___x_1796_);
goto v___jp_1788_;
}
}
}
else
{
lean_object* v_p_1808_; uint8_t v___y_1810_; lean_object* v___x_1813_; lean_object* v___x_1814_; 
v_p_1808_ = lp_lean1090_Lean1090_Impl_cbWindPenalty50(v_word_1787_);
v___x_1813_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19));
v___x_1814_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1786_, v_word_1787_, v___x_1813_);
if (lean_obj_tag(v___x_1814_) == 1)
{
lean_object* v_val_1815_; lean_object* v___x_1816_; lean_object* v___x_1817_; 
v_val_1815_ = lean_ctor_get(v___x_1814_, 0);
lean_inc(v_val_1815_);
lean_dec_ref_known(v___x_1814_, 1);
v___x_1816_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBAdjustValue___closed__4));
v___x_1817_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1786_, v_word_1787_, v___x_1816_);
if (lean_obj_tag(v___x_1817_) == 1)
{
lean_object* v_val_1818_; uint8_t v___y_1820_; lean_object* v___x_1824_; lean_object* v___x_1825_; uint8_t v___x_1826_; 
v_val_1818_ = lean_ctor_get(v___x_1817_, 0);
lean_inc(v_val_1818_);
lean_dec_ref_known(v___x_1817_, 1);
v___x_1824_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__2, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__2);
lean_inc(v_val_1815_);
v___x_1825_ = l_Rat_abs(v_val_1815_);
v___x_1826_ = l_Rat_blt(v___x_1824_, v___x_1825_);
if (v___x_1826_ == 0)
{
v___y_1820_ = v___x_1826_;
goto v___jp_1819_;
}
else
{
lean_object* v___x_1827_; lean_object* v___x_1828_; uint8_t v___x_1829_; 
v___x_1827_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__4, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__4);
lean_inc(v_val_1818_);
v___x_1828_ = l_Rat_abs(v_val_1818_);
v___x_1829_ = l_Rat_blt(v___x_1827_, v___x_1828_);
v___y_1820_ = v___x_1829_;
goto v___jp_1819_;
}
v___jp_1819_:
{
if (v___y_1820_ == 0)
{
lean_dec(v_val_1818_);
lean_dec(v_val_1815_);
return v_p_1808_;
}
else
{
lean_object* v___x_1821_; uint8_t v___x_1822_; uint8_t v___x_1823_; 
v___x_1821_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1822_ = l_Rat_blt(v___x_1821_, v_val_1815_);
v___x_1823_ = l_Rat_blt(v___x_1821_, v_val_1818_);
if (v___x_1823_ == 0)
{
if (v___x_1822_ == 0)
{
return v_p_1808_;
}
else
{
v___y_1810_ = v___x_1823_;
goto v___jp_1809_;
}
}
else
{
v___y_1810_ = v___x_1822_;
goto v___jp_1809_;
}
}
}
}
else
{
lean_dec(v___x_1817_);
lean_dec(v_val_1815_);
return v_p_1808_;
}
}
else
{
lean_dec(v___x_1814_);
return v_p_1808_;
}
v___jp_1809_:
{
if (v___y_1810_ == 0)
{
lean_object* v___x_1811_; lean_object* v___x_1812_; 
v___x_1811_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1812_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_p_1808_, v___x_1811_);
return v___x_1812_;
}
else
{
return v_p_1808_;
}
}
}
v___jp_1788_:
{
lean_object* v___x_1789_; 
v___x_1789_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1789_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPenalty___boxed(lean_object* v_register_1830_, lean_object* v_word_1831_){
_start:
{
lean_object* v_res_1832_; 
v_res_1832_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_1830_, v_word_1831_);
lean_dec(v_word_1831_);
lean_dec(v_register_1830_);
return v_res_1832_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCombinedScore(lean_object* v_register_1833_, lean_object* v_word_1834_){
_start:
{
lean_object* v___x_1835_; lean_object* v___x_1836_; lean_object* v___x_1837_; 
v___x_1835_ = lp_lean1090_Lean1090_Impl_cbDensity(v_register_1833_, v_word_1834_);
v___x_1836_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_1833_, v_word_1834_);
v___x_1837_ = lp_lean1090_Lean1090_Impl_Binary64_add(v___x_1835_, v___x_1836_);
return v___x_1837_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCombinedScore___boxed(lean_object* v_register_1838_, lean_object* v_word_1839_){
_start:
{
lean_object* v_res_1840_; 
v_res_1840_ = lp_lean1090_Lean1090_Impl_cbCombinedScore(v_register_1838_, v_word_1839_);
lean_dec(v_word_1839_);
lean_dec(v_register_1838_);
return v_res_1840_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHScoreTable___lam__0(lean_object* v_code_1841_){
_start:
{
lean_object* v___x_1842_; lean_object* v___x_1843_; lean_object* v___x_1844_; lean_object* v___x_1845_; lean_object* v___x_1846_; lean_object* v___x_1847_; lean_object* v___x_1848_; lean_object* v___x_1849_; 
v___x_1842_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1841_);
v___x_1843_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__3);
v___x_1844_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1842_, v___x_1843_);
lean_dec_ref(v___x_1842_);
v___x_1845_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__4);
v___x_1846_ = lp_lean1090_Lean1090_Impl_Binary64_add(v___x_1844_, v___x_1845_);
v___x_1847_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1);
v___x_1848_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3);
v___x_1849_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1846_, v___x_1847_, v___x_1848_);
return v___x_1849_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1851_; lean_object* v___x_1852_; lean_object* v___x_1853_; 
v___f_1851_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__0));
v___x_1852_ = lean_unsigned_to_nat(4096u);
v___x_1853_ = l_Array_ofFn___redArg(v___x_1852_, v___f_1851_);
return v___x_1853_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable(void){
_start:
{
lean_object* v___x_1854_; 
v___x_1854_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1);
return v___x_1854_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0(lean_object* v_code_1855_){
_start:
{
lean_object* v___x_1856_; lean_object* v___x_1857_; lean_object* v___x_1858_; lean_object* v___x_1859_; 
v___x_1856_ = lp_lean1090_Lean1090_Impl_cbSelected(v_code_1855_);
v___x_1857_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0);
v___x_1858_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1);
v___x_1859_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1856_, v___x_1857_, v___x_1858_);
return v___x_1859_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0___boxed(lean_object* v_code_1860_){
_start:
{
lean_object* v_res_1861_; 
v_res_1861_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0(v_code_1860_);
lean_dec(v_code_1860_);
return v_res_1861_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1863_; lean_object* v___x_1864_; lean_object* v___x_1865_; 
v___f_1863_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__0));
v___x_1864_ = lean_unsigned_to_nat(4096u);
v___x_1865_ = l_Array_ofFn___redArg(v___x_1864_, v___f_1863_);
return v___x_1865_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable(void){
_start:
{
lean_object* v___x_1866_; 
v___x_1866_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1);
return v___x_1866_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1867_; lean_object* v___x_1868_; lean_object* v___x_1869_; 
v___x_1867_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1868_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRollValid50Table___lam__0___closed__0);
v___x_1869_ = l_Rat_div(v___x_1868_, v___x_1867_);
return v___x_1869_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0(lean_object* v_code_1870_){
_start:
{
uint8_t v___x_1871_; lean_object* v___x_1872_; lean_object* v___x_1873_; lean_object* v___x_1874_; lean_object* v___x_1875_; lean_object* v___x_1876_; lean_object* v___x_1877_; lean_object* v___x_1878_; lean_object* v___x_1879_; 
v___x_1871_ = 1;
v___x_1872_ = lean_unsigned_to_nat(10u);
v___x_1873_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1871_, v___x_1872_, v_code_1870_);
v___x_1874_ = l_Rat_ofInt(v___x_1873_);
v___x_1875_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0);
v___x_1876_ = l_Rat_mul(v___x_1874_, v___x_1875_);
lean_dec_ref(v___x_1874_);
v___x_1877_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1878_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__1);
v___x_1879_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1876_, v___x_1877_, v___x_1878_);
return v___x_1879_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1881_; lean_object* v___x_1882_; lean_object* v___x_1883_; 
v___f_1881_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__0));
v___x_1882_ = lean_unsigned_to_nat(1024u);
v___x_1883_ = l_Array_ofFn___redArg(v___x_1882_, v___f_1881_);
return v___x_1883_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable(void){
_start:
{
lean_object* v___x_1884_; 
v___x_1884_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1);
return v___x_1884_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1885_; lean_object* v___x_1886_; 
v___x_1885_ = lean_unsigned_to_nat(8u);
v___x_1886_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1885_);
return v___x_1886_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1(void){
_start:
{
lean_object* v___x_1887_; lean_object* v___x_1888_; lean_object* v___x_1889_; 
v___x_1887_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1888_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0);
v___x_1889_ = l_Rat_div(v___x_1888_, v___x_1887_);
return v___x_1889_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0(lean_object* v_code_1890_){
_start:
{
uint8_t v___x_1891_; lean_object* v___x_1892_; lean_object* v___x_1893_; lean_object* v___x_1894_; lean_object* v___x_1895_; lean_object* v___x_1896_; lean_object* v___x_1897_; lean_object* v___x_1898_; lean_object* v___x_1899_; 
v___x_1891_ = 1;
v___x_1892_ = lean_unsigned_to_nat(10u);
v___x_1893_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1891_, v___x_1892_, v_code_1890_);
v___x_1894_ = l_Rat_ofInt(v___x_1893_);
v___x_1895_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1);
v___x_1896_ = l_Rat_mul(v___x_1894_, v___x_1895_);
lean_dec_ref(v___x_1894_);
v___x_1897_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1898_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1);
v___x_1899_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1896_, v___x_1897_, v___x_1898_);
return v___x_1899_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1901_; lean_object* v___x_1902_; lean_object* v___x_1903_; 
v___f_1901_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__0));
v___x_1902_ = lean_unsigned_to_nat(1024u);
v___x_1903_ = l_Array_ofFn___redArg(v___x_1902_, v___f_1901_);
return v___x_1903_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable(void){
_start:
{
lean_object* v___x_1904_; 
v___x_1904_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1);
return v___x_1904_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTASScoreTable___lam__0(lean_object* v_code_1905_){
_start:
{
lean_object* v___x_1906_; lean_object* v___x_1907_; lean_object* v___x_1908_; lean_object* v___x_1909_; lean_object* v___x_1910_; lean_object* v___x_1911_; 
v___x_1906_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1905_);
v___x_1907_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1908_ = l_Rat_mul(v___x_1906_, v___x_1907_);
lean_dec_ref(v___x_1906_);
v___x_1909_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0);
v___x_1910_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1);
v___x_1911_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1908_, v___x_1909_, v___x_1910_);
return v___x_1911_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1913_; lean_object* v___x_1914_; lean_object* v___x_1915_; 
v___f_1913_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__0));
v___x_1914_ = lean_unsigned_to_nat(1024u);
v___x_1915_ = l_Array_ofFn___redArg(v___x_1914_, v___f_1913_);
return v___x_1915_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable(void){
_start:
{
lean_object* v___x_1916_; 
v___x_1916_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1);
return v___x_1916_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___lam__0(lean_object* v_code_1917_){
_start:
{
lean_object* v___x_1918_; lean_object* v___x_1919_; lean_object* v___x_1920_; lean_object* v___x_1921_; lean_object* v___x_1922_; lean_object* v___x_1923_; 
v___x_1918_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1917_);
v___x_1919_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1920_ = l_Rat_mul(v___x_1918_, v___x_1919_);
lean_dec_ref(v___x_1918_);
v___x_1921_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0);
v___x_1922_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1);
v___x_1923_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1920_, v___x_1921_, v___x_1922_);
return v___x_1923_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1925_; lean_object* v___x_1926_; lean_object* v___x_1927_; 
v___f_1925_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__0));
v___x_1926_ = lean_unsigned_to_nat(1024u);
v___x_1927_ = l_Array_ofFn___redArg(v___x_1926_, v___f_1925_);
return v___x_1927_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable(void){
_start:
{
lean_object* v___x_1928_; 
v___x_1928_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1);
return v___x_1928_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbIASScoreTable___lam__0(lean_object* v_code_1929_){
_start:
{
lean_object* v___x_1930_; lean_object* v___x_1931_; lean_object* v___x_1932_; lean_object* v___x_1933_; 
v___x_1930_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1929_);
v___x_1931_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0);
v___x_1932_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1);
v___x_1933_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1930_, v___x_1931_, v___x_1932_);
return v___x_1933_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1935_; lean_object* v___x_1936_; lean_object* v___x_1937_; 
v___f_1935_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__0));
v___x_1936_ = lean_unsigned_to_nat(1024u);
v___x_1937_ = l_Array_ofFn___redArg(v___x_1936_, v___f_1935_);
return v___x_1937_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable(void){
_start:
{
lean_object* v___x_1938_; 
v___x_1938_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1);
return v___x_1938_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachScoreTable___lam__0(lean_object* v_code_1939_){
_start:
{
lean_object* v___x_1940_; lean_object* v___x_1941_; lean_object* v___x_1942_; lean_object* v___x_1943_; lean_object* v___x_1944_; lean_object* v___x_1945_; lean_object* v___x_1946_; lean_object* v___x_1947_; 
v___x_1940_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1939_);
v___x_1941_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__2);
v___x_1942_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1940_, v___x_1941_);
lean_dec_ref(v___x_1940_);
v___x_1943_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbMachValueTable___lam__0___closed__3);
v___x_1944_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1942_, v___x_1943_);
lean_dec_ref(v___x_1942_);
v___x_1945_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2);
v___x_1946_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4);
v___x_1947_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1944_, v___x_1945_, v___x_1946_);
return v___x_1947_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1949_; lean_object* v___x_1950_; lean_object* v___x_1951_; 
v___f_1949_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__0));
v___x_1950_ = lean_unsigned_to_nat(1024u);
v___x_1951_ = l_Array_ofFn___redArg(v___x_1950_, v___f_1949_);
return v___x_1951_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable(void){
_start:
{
lean_object* v___x_1952_; 
v___x_1952_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1);
return v___x_1952_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___lam__0(lean_object* v_code_1953_){
_start:
{
lean_object* v___y_1955_; lean_object* v___x_1959_; lean_object* v___x_1960_; lean_object* v___x_1961_; uint8_t v___x_1964_; 
v___x_1959_ = lean_unsigned_to_nat(512u);
v___x_1960_ = lean_nat_mod(v_code_1953_, v___x_1959_);
v___x_1961_ = lean_unsigned_to_nat(0u);
v___x_1964_ = lean_nat_dec_eq(v___x_1960_, v___x_1961_);
if (v___x_1964_ == 0)
{
lean_object* v___x_1965_; uint8_t v___x_1966_; 
v___x_1965_ = lean_unsigned_to_nat(511u);
v___x_1966_ = lean_nat_dec_eq(v___x_1960_, v___x_1965_);
lean_dec(v___x_1960_);
if (v___x_1966_ == 0)
{
uint8_t v___x_1967_; lean_object* v___x_1968_; lean_object* v___x_1969_; lean_object* v___x_1970_; lean_object* v___x_1971_; lean_object* v___x_1972_; 
v___x_1967_ = 1;
v___x_1968_ = lean_unsigned_to_nat(10u);
v___x_1969_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1967_, v___x_1968_, v_code_1953_);
v___x_1970_ = l_Rat_ofInt(v___x_1969_);
v___x_1971_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__0, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__0);
v___x_1972_ = l_Rat_mul(v___x_1970_, v___x_1971_);
lean_dec_ref(v___x_1970_);
v___y_1955_ = v___x_1972_;
goto v___jp_1954_;
}
else
{
lean_dec(v_code_1953_);
goto v___jp_1962_;
}
}
else
{
lean_dec(v___x_1960_);
lean_dec(v_code_1953_);
goto v___jp_1962_;
}
v___jp_1954_:
{
lean_object* v___x_1956_; lean_object* v___x_1957_; lean_object* v___x_1958_; 
v___x_1956_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1);
v___x_1957_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2);
v___x_1958_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___y_1955_, v___x_1956_, v___x_1957_);
return v___x_1958_;
}
v___jp_1962_:
{
lean_object* v___x_1963_; 
v___x_1963_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___y_1955_ = v___x_1963_;
goto v___jp_1954_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1974_; lean_object* v___x_1975_; lean_object* v___x_1976_; 
v___f_1974_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__0));
v___x_1975_ = lean_unsigned_to_nat(1024u);
v___x_1976_ = l_Array_ofFn___redArg(v___x_1975_, v___f_1974_);
return v___x_1976_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable(void){
_start:
{
lean_object* v___x_1977_; 
v___x_1977_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1);
return v___x_1977_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___lam__0(lean_object* v_code_1978_){
_start:
{
lean_object* v___y_1980_; uint8_t v___x_1984_; lean_object* v___x_1985_; lean_object* v___x_1986_; lean_object* v___x_1987_; lean_object* v___x_1988_; lean_object* v_initial_1989_; lean_object* v___x_1990_; uint8_t v___x_1991_; 
v___x_1984_ = 1;
v___x_1985_ = lean_unsigned_to_nat(11u);
v___x_1986_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1984_, v___x_1985_, v_code_1978_);
v___x_1987_ = l_Rat_ofInt(v___x_1986_);
v___x_1988_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v_initial_1989_ = l_Rat_div(v___x_1987_, v___x_1988_);
lean_dec_ref(v___x_1987_);
v___x_1990_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
lean_inc_ref(v_initial_1989_);
v___x_1991_ = l_Rat_blt(v_initial_1989_, v___x_1990_);
if (v___x_1991_ == 0)
{
v___y_1980_ = v_initial_1989_;
goto v___jp_1979_;
}
else
{
lean_object* v___x_1992_; lean_object* v___x_1993_; 
v___x_1992_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1993_ = l_Rat_add(v_initial_1989_, v___x_1992_);
v___y_1980_ = v___x_1993_;
goto v___jp_1979_;
}
v___jp_1979_:
{
lean_object* v___x_1981_; lean_object* v___x_1982_; lean_object* v___x_1983_; 
v___x_1981_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5);
v___x_1982_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7);
v___x_1983_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___y_1980_, v___x_1981_, v___x_1982_);
return v___x_1983_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1995_; lean_object* v___x_1996_; lean_object* v___x_1997_; 
v___f_1995_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__0));
v___x_1996_ = lean_unsigned_to_nat(2048u);
v___x_1997_ = l_Array_ofFn___redArg(v___x_1996_, v___f_1995_);
return v___x_1997_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable(void){
_start:
{
lean_object* v___x_1998_; 
v___x_1998_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1);
return v___x_1998_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindScoreTable___lam__0(lean_object* v_code_1999_){
_start:
{
lean_object* v___x_2000_; lean_object* v___x_2001_; lean_object* v___x_2002_; lean_object* v___x_2003_; 
v___x_2000_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1999_);
v___x_2001_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0);
v___x_2002_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1);
v___x_2003_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_2000_, v___x_2001_, v___x_2002_);
return v___x_2003_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1(void){
_start:
{
lean_object* v___f_2005_; lean_object* v___x_2006_; lean_object* v___x_2007_; 
v___f_2005_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__0));
v___x_2006_ = lean_unsigned_to_nat(512u);
v___x_2007_ = l_Array_ofFn___redArg(v___x_2006_, v___f_2005_);
return v___x_2007_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable(void){
_start:
{
lean_object* v___x_2008_; 
v___x_2008_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1);
return v___x_2008_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPressureScoreTable___lam__0(lean_object* v_code_2009_){
_start:
{
lean_object* v___x_2010_; lean_object* v___x_2011_; lean_object* v___x_2012_; lean_object* v___x_2013_; 
v___x_2010_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_2009_);
v___x_2011_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0);
v___x_2012_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1);
v___x_2013_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_2010_, v___x_2011_, v___x_2012_);
return v___x_2013_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1(void){
_start:
{
lean_object* v___f_2015_; lean_object* v___x_2016_; lean_object* v___x_2017_; 
v___f_2015_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__0));
v___x_2016_ = lean_unsigned_to_nat(2048u);
v___x_2017_ = l_Array_ofFn___redArg(v___x_2016_, v___f_2015_);
return v___x_2017_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable(void){
_start:
{
lean_object* v___x_2018_; 
v___x_2018_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1);
return v___x_2018_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_2019_; lean_object* v___x_2020_; lean_object* v___x_2021_; 
v___x_2019_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v___x_2020_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNHValueTable___lam__0___closed__0);
v___x_2021_ = l_Rat_div(v___x_2020_, v___x_2019_);
return v___x_2021_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0(lean_object* v_code_2022_){
_start:
{
uint8_t v___x_2023_; lean_object* v___x_2024_; lean_object* v___x_2025_; lean_object* v___x_2026_; lean_object* v___x_2027_; lean_object* v___x_2028_; lean_object* v___x_2029_; lean_object* v___x_2030_; lean_object* v___x_2031_; 
v___x_2023_ = 1;
v___x_2024_ = lean_unsigned_to_nat(10u);
v___x_2025_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_2023_, v___x_2024_, v_code_2022_);
v___x_2026_ = l_Rat_ofInt(v___x_2025_);
v___x_2027_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0);
v___x_2028_ = l_Rat_mul(v___x_2026_, v___x_2027_);
lean_dec_ref(v___x_2026_);
v___x_2029_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2);
v___x_2030_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4);
v___x_2031_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_2028_, v___x_2029_, v___x_2030_);
return v___x_2031_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1(void){
_start:
{
lean_object* v___f_2033_; lean_object* v___x_2034_; lean_object* v___x_2035_; 
v___f_2033_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__0));
v___x_2034_ = lean_unsigned_to_nat(1024u);
v___x_2035_ = l_Array_ofFn___redArg(v___x_2034_, v___f_2033_);
return v___x_2035_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable(void){
_start:
{
lean_object* v___x_2036_; 
v___x_2036_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1);
return v___x_2036_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg(lean_object* v_width_2037_, lean_object* v_table_2038_, lean_object* v_word_2039_, lean_object* v_start_2040_){
_start:
{
lean_object* v___x_2041_; lean_object* v___x_2042_; 
v___x_2041_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2039_, v_start_2040_, v_width_2037_);
v___x_2042_ = lean_array_fget_borrowed(v_table_2038_, v___x_2041_);
lean_dec(v___x_2041_);
lean_inc(v___x_2042_);
return v___x_2042_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg___boxed(lean_object* v_width_2043_, lean_object* v_table_2044_, lean_object* v_word_2045_, lean_object* v_start_2046_){
_start:
{
lean_object* v_res_2047_; 
v_res_2047_ = lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg(v_width_2043_, v_table_2044_, v_word_2045_, v_start_2046_);
lean_dec(v_start_2046_);
lean_dec(v_word_2045_);
lean_dec_ref(v_table_2044_);
lean_dec(v_width_2043_);
return v_res_2047_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet(lean_object* v_width_2048_, lean_object* v_table_2049_, lean_object* v_size_2050_, lean_object* v_word_2051_, lean_object* v_start_2052_){
_start:
{
lean_object* v___x_2053_; lean_object* v___x_2054_; 
v___x_2053_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2051_, v_start_2052_, v_width_2048_);
v___x_2054_ = lean_array_fget_borrowed(v_table_2049_, v___x_2053_);
lean_dec(v___x_2053_);
lean_inc(v___x_2054_);
return v___x_2054_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___boxed(lean_object* v_width_2055_, lean_object* v_table_2056_, lean_object* v_size_2057_, lean_object* v_word_2058_, lean_object* v_start_2059_){
_start:
{
lean_object* v_res_2060_; 
v_res_2060_ = lp_lean1090_Lean1090_Impl_cbDensityTableGet(v_width_2055_, v_table_2056_, v_size_2057_, v_word_2058_, v_start_2059_);
lean_dec(v_start_2059_);
lean_dec(v_word_2058_);
lean_dec_ref(v_table_2056_);
lean_dec(v_width_2055_);
return v_res_2060_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTermsFast(lean_object* v_register_2061_, lean_object* v_word_2062_){
_start:
{
lean_object* v___x_2063_; uint8_t v___x_2064_; 
v___x_2063_ = lean_unsigned_to_nat(64u);
v___x_2064_ = lean_nat_dec_eq(v_register_2061_, v___x_2063_);
if (v___x_2064_ == 0)
{
lean_object* v___x_2065_; uint8_t v___x_2066_; 
v___x_2065_ = lean_unsigned_to_nat(80u);
v___x_2066_ = lean_nat_dec_eq(v_register_2061_, v___x_2065_);
if (v___x_2066_ == 0)
{
lean_object* v___x_2067_; uint8_t v___x_2068_; 
v___x_2067_ = lean_unsigned_to_nat(96u);
v___x_2068_ = lean_nat_dec_eq(v_register_2061_, v___x_2067_);
if (v___x_2068_ == 0)
{
lean_object* v___x_2069_; uint8_t v___x_2070_; 
v___x_2069_ = lean_unsigned_to_nat(68u);
v___x_2070_ = lean_nat_dec_eq(v_register_2061_, v___x_2069_);
if (v___x_2070_ == 0)
{
lean_object* v___x_2071_; uint8_t v___x_2072_; 
v___x_2071_ = lean_unsigned_to_nat(69u);
v___x_2072_ = lean_nat_dec_eq(v_register_2061_, v___x_2071_);
if (v___x_2072_ == 0)
{
lean_object* v___x_2073_; 
v___x_2073_ = lean_box(0);
return v___x_2073_;
}
else
{
lean_object* v___x_2074_; lean_object* v___x_2075_; lean_object* v___x_2076_; lean_object* v___x_2077_; lean_object* v___y_2079_; uint8_t v___x_2093_; 
v___x_2074_ = lean_unsigned_to_nat(16u);
v___x_2075_ = lean_unsigned_to_nat(1u);
v___x_2076_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2074_, v___x_2075_);
v___x_2077_ = lean_unsigned_to_nat(0u);
v___x_2093_ = lean_nat_dec_eq(v___x_2076_, v___x_2077_);
lean_dec(v___x_2076_);
if (v___x_2093_ == 0)
{
lean_object* v___x_2094_; lean_object* v___x_2095_; lean_object* v___x_2096_; lean_object* v___x_2097_; lean_object* v___x_2098_; lean_object* v___x_2099_; lean_object* v___x_2100_; 
v___x_2094_ = lean_unsigned_to_nat(10u);
v___x_2095_ = lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable;
v___x_2096_ = lean_unsigned_to_nat(17u);
v___x_2097_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2096_, v___x_2094_);
v___x_2098_ = lean_array_fget_borrowed(v___x_2095_, v___x_2097_);
lean_dec(v___x_2097_);
v___x_2099_ = lean_box(0);
lean_inc(v___x_2098_);
v___x_2100_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2100_, 0, v___x_2098_);
lean_ctor_set(v___x_2100_, 1, v___x_2099_);
v___y_2079_ = v___x_2100_;
goto v___jp_2078_;
}
else
{
lean_object* v___x_2101_; 
v___x_2101_ = lean_box(0);
v___y_2079_ = v___x_2101_;
goto v___jp_2078_;
}
v___jp_2078_:
{
lean_object* v___x_2080_; lean_object* v___x_2081_; uint8_t v___x_2082_; 
v___x_2080_ = lean_unsigned_to_nat(27u);
v___x_2081_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2080_, v___x_2075_);
v___x_2082_ = lean_nat_dec_eq(v___x_2081_, v___x_2077_);
lean_dec(v___x_2081_);
if (v___x_2082_ == 0)
{
lean_object* v___x_2083_; lean_object* v___x_2084_; lean_object* v___x_2085_; lean_object* v___x_2086_; lean_object* v___x_2087_; lean_object* v___x_2088_; lean_object* v___x_2089_; lean_object* v___x_2090_; 
v___x_2083_ = lean_unsigned_to_nat(11u);
v___x_2084_ = lp_lean1090_Lean1090_Impl_cbPressureScoreTable;
v___x_2085_ = lean_unsigned_to_nat(28u);
v___x_2086_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2085_, v___x_2083_);
v___x_2087_ = lean_array_fget_borrowed(v___x_2084_, v___x_2086_);
lean_dec(v___x_2086_);
v___x_2088_ = lean_box(0);
lean_inc(v___x_2087_);
v___x_2089_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2089_, 0, v___x_2087_);
lean_ctor_set(v___x_2089_, 1, v___x_2088_);
v___x_2090_ = l_List_appendTR___redArg(v___y_2079_, v___x_2089_);
return v___x_2090_;
}
else
{
lean_object* v___x_2091_; lean_object* v___x_2092_; 
v___x_2091_ = lean_box(0);
v___x_2092_ = l_List_appendTR___redArg(v___y_2079_, v___x_2091_);
return v___x_2092_;
}
}
}
}
else
{
lean_object* v___x_2102_; lean_object* v___x_2103_; lean_object* v___x_2104_; lean_object* v___x_2105_; lean_object* v___x_2106_; lean_object* v___x_2107_; lean_object* v___x_2108_; lean_object* v___x_2109_; lean_object* v___x_2110_; lean_object* v___x_2111_; lean_object* v___x_2112_; lean_object* v___y_2114_; uint8_t v___x_2126_; 
v___x_2102_ = lean_unsigned_to_nat(11u);
v___x_2103_ = lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable;
v___x_2104_ = lean_unsigned_to_nat(24u);
v___x_2105_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2104_, v___x_2102_);
v___x_2106_ = lean_array_fget_borrowed(v___x_2103_, v___x_2105_);
lean_dec(v___x_2105_);
v___x_2107_ = lean_box(0);
lean_inc(v___x_2106_);
v___x_2108_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2108_, 0, v___x_2106_);
lean_ctor_set(v___x_2108_, 1, v___x_2107_);
v___x_2109_ = lean_unsigned_to_nat(5u);
v___x_2110_ = lean_unsigned_to_nat(1u);
v___x_2111_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2109_, v___x_2110_);
v___x_2112_ = lean_unsigned_to_nat(0u);
v___x_2126_ = lean_nat_dec_eq(v___x_2111_, v___x_2112_);
lean_dec(v___x_2111_);
if (v___x_2126_ == 0)
{
lean_object* v___x_2127_; lean_object* v___x_2128_; lean_object* v___x_2129_; lean_object* v___x_2130_; lean_object* v___x_2131_; lean_object* v___x_2132_; 
v___x_2127_ = lean_unsigned_to_nat(9u);
v___x_2128_ = lp_lean1090_Lean1090_Impl_cbWindScoreTable;
v___x_2129_ = lean_unsigned_to_nat(6u);
v___x_2130_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2129_, v___x_2127_);
v___x_2131_ = lean_array_fget_borrowed(v___x_2128_, v___x_2130_);
lean_dec(v___x_2130_);
lean_inc(v___x_2131_);
v___x_2132_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2132_, 0, v___x_2131_);
lean_ctor_set(v___x_2132_, 1, v___x_2107_);
v___y_2114_ = v___x_2132_;
goto v___jp_2113_;
}
else
{
v___y_2114_ = v___x_2107_;
goto v___jp_2113_;
}
v___jp_2113_:
{
lean_object* v___x_2115_; lean_object* v___x_2116_; lean_object* v___x_2117_; uint8_t v___x_2118_; 
v___x_2115_ = l_List_appendTR___redArg(v___x_2108_, v___y_2114_);
v___x_2116_ = lean_unsigned_to_nat(35u);
v___x_2117_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2116_, v___x_2110_);
v___x_2118_ = lean_nat_dec_eq(v___x_2117_, v___x_2112_);
lean_dec(v___x_2117_);
if (v___x_2118_ == 0)
{
lean_object* v___x_2119_; lean_object* v___x_2120_; lean_object* v___x_2121_; lean_object* v___x_2122_; lean_object* v___x_2123_; lean_object* v___x_2124_; 
v___x_2119_ = lp_lean1090_Lean1090_Impl_cbPressureScoreTable;
v___x_2120_ = lean_unsigned_to_nat(36u);
v___x_2121_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2120_, v___x_2102_);
v___x_2122_ = lean_array_fget_borrowed(v___x_2119_, v___x_2121_);
lean_dec(v___x_2121_);
lean_inc(v___x_2122_);
v___x_2123_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2123_, 0, v___x_2122_);
lean_ctor_set(v___x_2123_, 1, v___x_2107_);
v___x_2124_ = l_List_appendTR___redArg(v___x_2115_, v___x_2123_);
return v___x_2124_;
}
else
{
lean_object* v___x_2125_; 
v___x_2125_ = l_List_appendTR___redArg(v___x_2115_, v___x_2107_);
return v___x_2125_;
}
}
}
}
else
{
lean_object* v___x_2133_; lean_object* v___x_2134_; lean_object* v___x_2135_; lean_object* v___x_2136_; lean_object* v___y_2138_; lean_object* v___y_2139_; lean_object* v___y_2155_; uint8_t v___x_2167_; 
v___x_2133_ = lean_unsigned_to_nat(13u);
v___x_2134_ = lean_unsigned_to_nat(1u);
v___x_2135_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2133_, v___x_2134_);
v___x_2136_ = lean_unsigned_to_nat(0u);
v___x_2167_ = lean_nat_dec_eq(v___x_2135_, v___x_2136_);
lean_dec(v___x_2135_);
if (v___x_2167_ == 0)
{
lean_object* v___x_2168_; lean_object* v___x_2169_; lean_object* v___x_2170_; lean_object* v___x_2171_; lean_object* v___x_2172_; lean_object* v___x_2173_; lean_object* v___x_2174_; 
v___x_2168_ = lean_unsigned_to_nat(10u);
v___x_2169_ = lp_lean1090_Lean1090_Impl_cbIASScoreTable;
v___x_2170_ = lean_unsigned_to_nat(14u);
v___x_2171_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2170_, v___x_2168_);
v___x_2172_ = lean_array_fget_borrowed(v___x_2169_, v___x_2171_);
lean_dec(v___x_2171_);
v___x_2173_ = lean_box(0);
lean_inc(v___x_2172_);
v___x_2174_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2174_, 0, v___x_2172_);
lean_ctor_set(v___x_2174_, 1, v___x_2173_);
v___y_2155_ = v___x_2174_;
goto v___jp_2154_;
}
else
{
lean_object* v___x_2175_; 
v___x_2175_ = lean_box(0);
v___y_2155_ = v___x_2175_;
goto v___jp_2154_;
}
v___jp_2137_:
{
lean_object* v___x_2140_; lean_object* v___x_2141_; lean_object* v___x_2142_; uint8_t v___x_2143_; 
v___x_2140_ = l_List_appendTR___redArg(v___y_2138_, v___y_2139_);
v___x_2141_ = lean_unsigned_to_nat(46u);
v___x_2142_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2141_, v___x_2134_);
v___x_2143_ = lean_nat_dec_eq(v___x_2142_, v___x_2136_);
lean_dec(v___x_2142_);
if (v___x_2143_ == 0)
{
lean_object* v___x_2144_; lean_object* v___x_2145_; lean_object* v___x_2146_; lean_object* v___x_2147_; lean_object* v___x_2148_; lean_object* v___x_2149_; lean_object* v___x_2150_; lean_object* v___x_2151_; 
v___x_2144_ = lean_unsigned_to_nat(10u);
v___x_2145_ = lp_lean1090_Lean1090_Impl_cbVerticalScoreTable;
v___x_2146_ = lean_unsigned_to_nat(47u);
v___x_2147_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2146_, v___x_2144_);
v___x_2148_ = lean_array_fget_borrowed(v___x_2145_, v___x_2147_);
lean_dec(v___x_2147_);
v___x_2149_ = lean_box(0);
lean_inc(v___x_2148_);
v___x_2150_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2150_, 0, v___x_2148_);
lean_ctor_set(v___x_2150_, 1, v___x_2149_);
v___x_2151_ = l_List_appendTR___redArg(v___x_2140_, v___x_2150_);
return v___x_2151_;
}
else
{
lean_object* v___x_2152_; lean_object* v___x_2153_; 
v___x_2152_ = lean_box(0);
v___x_2153_ = l_List_appendTR___redArg(v___x_2140_, v___x_2152_);
return v___x_2153_;
}
}
v___jp_2154_:
{
lean_object* v___x_2156_; lean_object* v___x_2157_; uint8_t v___x_2158_; 
v___x_2156_ = lean_unsigned_to_nat(24u);
v___x_2157_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2156_, v___x_2134_);
v___x_2158_ = lean_nat_dec_eq(v___x_2157_, v___x_2136_);
lean_dec(v___x_2157_);
if (v___x_2158_ == 0)
{
lean_object* v___x_2159_; lean_object* v___x_2160_; lean_object* v___x_2161_; lean_object* v___x_2162_; lean_object* v___x_2163_; lean_object* v___x_2164_; lean_object* v___x_2165_; 
v___x_2159_ = lean_unsigned_to_nat(10u);
v___x_2160_ = lp_lean1090_Lean1090_Impl_cbMachScoreTable;
v___x_2161_ = lean_unsigned_to_nat(25u);
v___x_2162_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2161_, v___x_2159_);
v___x_2163_ = lean_array_fget_borrowed(v___x_2160_, v___x_2162_);
lean_dec(v___x_2162_);
v___x_2164_ = lean_box(0);
lean_inc(v___x_2163_);
v___x_2165_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2165_, 0, v___x_2163_);
lean_ctor_set(v___x_2165_, 1, v___x_2164_);
v___y_2138_ = v___y_2155_;
v___y_2139_ = v___x_2165_;
goto v___jp_2137_;
}
else
{
lean_object* v___x_2166_; 
v___x_2166_ = lean_box(0);
v___y_2138_ = v___y_2155_;
v___y_2139_ = v___x_2166_;
goto v___jp_2137_;
}
}
}
}
else
{
lean_object* v___x_2176_; lean_object* v___x_2177_; lean_object* v___x_2178_; lean_object* v___y_2180_; lean_object* v___y_2181_; lean_object* v___y_2197_; lean_object* v___y_2198_; lean_object* v___y_2212_; lean_object* v___y_2215_; uint8_t v___x_2231_; 
v___x_2176_ = lean_unsigned_to_nat(1u);
v___x_2177_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2176_, v___x_2176_);
v___x_2178_ = lean_unsigned_to_nat(0u);
v___x_2231_ = lean_nat_dec_eq(v___x_2177_, v___x_2178_);
lean_dec(v___x_2177_);
if (v___x_2231_ == 0)
{
lean_object* v___x_2232_; lean_object* v___x_2233_; lean_object* v___x_2234_; lean_object* v___x_2235_; lean_object* v___x_2236_; lean_object* v___x_2237_; lean_object* v___x_2238_; 
v___x_2232_ = lean_unsigned_to_nat(10u);
v___x_2233_ = lp_lean1090_Lean1090_Impl_cbRollScoreTable;
v___x_2234_ = lean_unsigned_to_nat(2u);
v___x_2235_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2234_, v___x_2232_);
v___x_2236_ = lean_array_fget_borrowed(v___x_2233_, v___x_2235_);
lean_dec(v___x_2235_);
v___x_2237_ = lean_box(0);
lean_inc(v___x_2236_);
v___x_2238_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2238_, 0, v___x_2236_);
lean_ctor_set(v___x_2238_, 1, v___x_2237_);
v___y_2215_ = v___x_2238_;
goto v___jp_2214_;
}
else
{
lean_object* v___x_2239_; 
v___x_2239_ = lean_box(0);
v___y_2215_ = v___x_2239_;
goto v___jp_2214_;
}
v___jp_2179_:
{
lean_object* v___x_2182_; lean_object* v___x_2183_; lean_object* v___x_2184_; uint8_t v___x_2185_; 
v___x_2182_ = l_List_appendTR___redArg(v___y_2180_, v___y_2181_);
v___x_2183_ = lean_unsigned_to_nat(24u);
v___x_2184_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2183_, v___x_2176_);
v___x_2185_ = lean_nat_dec_eq(v___x_2184_, v___x_2178_);
lean_dec(v___x_2184_);
if (v___x_2185_ == 0)
{
lean_object* v___x_2186_; lean_object* v___x_2187_; lean_object* v___x_2188_; lean_object* v___x_2189_; lean_object* v___x_2190_; lean_object* v___x_2191_; lean_object* v___x_2192_; lean_object* v___x_2193_; 
v___x_2186_ = lean_unsigned_to_nat(10u);
v___x_2187_ = lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable;
v___x_2188_ = lean_unsigned_to_nat(25u);
v___x_2189_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2188_, v___x_2186_);
v___x_2190_ = lean_array_fget_borrowed(v___x_2187_, v___x_2189_);
lean_dec(v___x_2189_);
v___x_2191_ = lean_box(0);
lean_inc(v___x_2190_);
v___x_2192_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2192_, 0, v___x_2190_);
lean_ctor_set(v___x_2192_, 1, v___x_2191_);
v___x_2193_ = l_List_appendTR___redArg(v___x_2182_, v___x_2192_);
return v___x_2193_;
}
else
{
lean_object* v___x_2194_; lean_object* v___x_2195_; 
v___x_2194_ = lean_box(0);
v___x_2195_ = l_List_appendTR___redArg(v___x_2182_, v___x_2194_);
return v___x_2195_;
}
}
v___jp_2196_:
{
lean_object* v___x_2199_; lean_object* v___x_2200_; lean_object* v___x_2201_; uint8_t v___x_2202_; 
v___x_2199_ = l_List_appendTR___redArg(v___y_2197_, v___y_2198_);
v___x_2200_ = lean_unsigned_to_nat(46u);
v___x_2201_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2200_, v___x_2176_);
v___x_2202_ = lean_nat_dec_eq(v___x_2201_, v___x_2178_);
lean_dec(v___x_2201_);
if (v___x_2202_ == 0)
{
lean_object* v___x_2203_; lean_object* v___x_2204_; lean_object* v___x_2205_; lean_object* v___x_2206_; lean_object* v___x_2207_; lean_object* v___x_2208_; lean_object* v___x_2209_; 
v___x_2203_ = lean_unsigned_to_nat(10u);
v___x_2204_ = lp_lean1090_Lean1090_Impl_cbTASScoreTable;
v___x_2205_ = lean_unsigned_to_nat(47u);
v___x_2206_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2205_, v___x_2203_);
v___x_2207_ = lean_array_fget_borrowed(v___x_2204_, v___x_2206_);
lean_dec(v___x_2206_);
v___x_2208_ = lean_box(0);
lean_inc(v___x_2207_);
v___x_2209_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2209_, 0, v___x_2207_);
lean_ctor_set(v___x_2209_, 1, v___x_2208_);
v___y_2180_ = v___x_2199_;
v___y_2181_ = v___x_2209_;
goto v___jp_2179_;
}
else
{
lean_object* v___x_2210_; 
v___x_2210_ = lean_box(0);
v___y_2180_ = v___x_2199_;
v___y_2181_ = v___x_2210_;
goto v___jp_2179_;
}
}
v___jp_2211_:
{
lean_object* v___x_2213_; 
v___x_2213_ = lean_box(0);
v___y_2197_ = v___y_2212_;
v___y_2198_ = v___x_2213_;
goto v___jp_2196_;
}
v___jp_2214_:
{
lean_object* v___x_2216_; lean_object* v___x_2217_; uint8_t v___x_2218_; 
v___x_2216_ = lean_unsigned_to_nat(35u);
v___x_2217_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2216_, v___x_2176_);
v___x_2218_ = lean_nat_dec_eq(v___x_2217_, v___x_2178_);
lean_dec(v___x_2217_);
if (v___x_2218_ == 0)
{
lean_object* v___x_2219_; lean_object* v___x_2220_; lean_object* v___x_2221_; lean_object* v___x_2222_; uint8_t v___x_2223_; 
v___x_2219_ = lean_unsigned_to_nat(37u);
v___x_2220_ = lean_unsigned_to_nat(9u);
v___x_2221_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2219_, v___x_2220_);
v___x_2222_ = lean_unsigned_to_nat(511u);
v___x_2223_ = lean_nat_dec_eq(v___x_2221_, v___x_2222_);
lean_dec(v___x_2221_);
if (v___x_2223_ == 0)
{
lean_object* v___x_2224_; lean_object* v___x_2225_; lean_object* v___x_2226_; lean_object* v___x_2227_; lean_object* v___x_2228_; lean_object* v___x_2229_; lean_object* v___x_2230_; 
v___x_2224_ = lean_unsigned_to_nat(10u);
v___x_2225_ = lp_lean1090_Lean1090_Impl_cbRateScoreTable;
v___x_2226_ = lean_unsigned_to_nat(36u);
v___x_2227_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2226_, v___x_2224_);
v___x_2228_ = lean_array_fget_borrowed(v___x_2225_, v___x_2227_);
lean_dec(v___x_2227_);
v___x_2229_ = lean_box(0);
lean_inc(v___x_2228_);
v___x_2230_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2230_, 0, v___x_2228_);
lean_ctor_set(v___x_2230_, 1, v___x_2229_);
v___y_2197_ = v___y_2215_;
v___y_2198_ = v___x_2230_;
goto v___jp_2196_;
}
else
{
v___y_2212_ = v___y_2215_;
goto v___jp_2211_;
}
}
else
{
v___y_2212_ = v___y_2215_;
goto v___jp_2211_;
}
}
}
}
else
{
lean_object* v___x_2240_; lean_object* v___x_2241_; lean_object* v___x_2242_; lean_object* v___x_2243_; lean_object* v___y_2245_; lean_object* v___y_2246_; lean_object* v___y_2262_; uint8_t v___x_2273_; 
v___x_2240_ = lean_unsigned_to_nat(27u);
v___x_2241_ = lean_unsigned_to_nat(1u);
v___x_2242_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2240_, v___x_2241_);
v___x_2243_ = lean_unsigned_to_nat(0u);
v___x_2273_ = lean_nat_dec_eq(v___x_2242_, v___x_2243_);
lean_dec(v___x_2242_);
if (v___x_2273_ == 0)
{
lean_object* v___x_2274_; lean_object* v___x_2275_; lean_object* v___x_2276_; lean_object* v___x_2277_; lean_object* v___x_2278_; lean_object* v___x_2279_; lean_object* v___x_2280_; 
v___x_2274_ = lean_unsigned_to_nat(12u);
v___x_2275_ = lp_lean1090_Lean1090_Impl_cbQNHScoreTable;
v___x_2276_ = lean_unsigned_to_nat(28u);
v___x_2277_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2276_, v___x_2274_);
v___x_2278_ = lean_array_fget_borrowed(v___x_2275_, v___x_2277_);
lean_dec(v___x_2277_);
v___x_2279_ = lean_box(0);
lean_inc(v___x_2278_);
v___x_2280_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2280_, 0, v___x_2278_);
lean_ctor_set(v___x_2280_, 1, v___x_2279_);
v___y_2262_ = v___x_2280_;
goto v___jp_2261_;
}
else
{
lean_object* v___x_2281_; 
v___x_2281_ = lean_box(0);
v___y_2262_ = v___x_2281_;
goto v___jp_2261_;
}
v___jp_2244_:
{
lean_object* v___x_2247_; lean_object* v___x_2248_; lean_object* v___x_2249_; uint8_t v___x_2250_; 
v___x_2247_ = l_List_appendTR___redArg(v___y_2245_, v___y_2246_);
v___x_2248_ = lean_unsigned_to_nat(14u);
v___x_2249_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2248_, v___x_2241_);
v___x_2250_ = lean_nat_dec_eq(v___x_2249_, v___x_2243_);
lean_dec(v___x_2249_);
if (v___x_2250_ == 0)
{
lean_object* v___x_2251_; lean_object* v___x_2252_; lean_object* v___x_2253_; lean_object* v___x_2254_; lean_object* v___x_2255_; lean_object* v___x_2256_; lean_object* v___x_2257_; lean_object* v___x_2258_; 
v___x_2251_ = lean_unsigned_to_nat(12u);
v___x_2252_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable;
v___x_2253_ = lean_unsigned_to_nat(15u);
v___x_2254_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2253_, v___x_2251_);
v___x_2255_ = lean_array_fget_borrowed(v___x_2252_, v___x_2254_);
lean_dec(v___x_2254_);
v___x_2256_ = lean_box(0);
lean_inc(v___x_2255_);
v___x_2257_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2257_, 0, v___x_2255_);
lean_ctor_set(v___x_2257_, 1, v___x_2256_);
v___x_2258_ = l_List_appendTR___redArg(v___x_2247_, v___x_2257_);
return v___x_2258_;
}
else
{
lean_object* v___x_2259_; lean_object* v___x_2260_; 
v___x_2259_ = lean_box(0);
v___x_2260_ = l_List_appendTR___redArg(v___x_2247_, v___x_2259_);
return v___x_2260_;
}
}
v___jp_2261_:
{
lean_object* v___x_2263_; uint8_t v___x_2264_; 
v___x_2263_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2241_, v___x_2241_);
v___x_2264_ = lean_nat_dec_eq(v___x_2263_, v___x_2243_);
lean_dec(v___x_2263_);
if (v___x_2264_ == 0)
{
lean_object* v___x_2265_; lean_object* v___x_2266_; lean_object* v___x_2267_; lean_object* v___x_2268_; lean_object* v___x_2269_; lean_object* v___x_2270_; lean_object* v___x_2271_; 
v___x_2265_ = lean_unsigned_to_nat(12u);
v___x_2266_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable;
v___x_2267_ = lean_unsigned_to_nat(2u);
v___x_2268_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2062_, v___x_2267_, v___x_2265_);
v___x_2269_ = lean_array_fget_borrowed(v___x_2266_, v___x_2268_);
lean_dec(v___x_2268_);
v___x_2270_ = lean_box(0);
lean_inc(v___x_2269_);
v___x_2271_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2271_, 0, v___x_2269_);
lean_ctor_set(v___x_2271_, 1, v___x_2270_);
v___y_2245_ = v___y_2262_;
v___y_2246_ = v___x_2271_;
goto v___jp_2244_;
}
else
{
lean_object* v___x_2272_; 
v___x_2272_ = lean_box(0);
v___y_2245_ = v___y_2262_;
v___y_2246_ = v___x_2272_;
goto v___jp_2244_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTermsFast___boxed(lean_object* v_register_2282_, lean_object* v_word_2283_){
_start:
{
lean_object* v_res_2284_; 
v_res_2284_ = lp_lean1090_Lean1090_Impl_cbDensityTermsFast(v_register_2282_, v_word_2283_);
lean_dec(v_word_2283_);
lean_dec(v_register_2282_);
return v_res_2284_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0(lean_object* v_register_2285_, lean_object* v_word_2286_, lean_object* v_x_2287_){
_start:
{
lean_object* v___x_2288_; lean_object* v___x_2289_; uint8_t v___x_2290_; 
v___x_2288_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__1, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1);
v___x_2289_ = lp_lean1090_Lean1090_Impl_cbCombinedScore(v_register_2285_, v_word_2286_);
v___x_2290_ = l_Rat_instDecidableLe(v___x_2288_, v___x_2289_);
return v___x_2290_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed(lean_object* v_register_2291_, lean_object* v_word_2292_, lean_object* v_x_2293_){
_start:
{
uint8_t v_res_2294_; lean_object* v_r_2295_; 
v_res_2294_ = lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0(v_register_2291_, v_word_2292_, v_x_2293_);
lean_dec(v_word_2292_);
lean_dec(v_register_2291_);
v_r_2295_ = lean_box(v_res_2294_);
return v_r_2295_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses(lean_object* v_register_2296_, lean_object* v_word_2297_){
_start:
{
lean_object* v___f_2298_; lean_object* v___x_2299_; lean_object* v___x_2300_; uint8_t v___x_2301_; 
lean_inc(v_word_2297_);
lean_inc(v_register_2296_);
v___f_2298_ = lean_alloc_closure((void*)(lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed), 3, 2);
lean_closure_set(v___f_2298_, 0, v_register_2296_);
lean_closure_set(v___f_2298_, 1, v_word_2297_);
v___x_2299_ = lp_lean1090_Lean1090_Impl_cbDensityTermsFast(v_register_2296_, v_word_2297_);
v___x_2300_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_2296_, v_word_2297_);
lean_dec(v_word_2297_);
lean_dec(v_register_2296_);
v___x_2301_ = lp_lean1090_Lean1090_Impl_ScoreGate_choose(v___x_2299_, v___x_2300_, v___f_2298_);
return v___x_2301_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScorePasses___boxed(lean_object* v_register_2302_, lean_object* v_word_2303_){
_start:
{
uint8_t v_res_2304_; lean_object* v_r_2305_; 
v_res_2304_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2302_, v_word_2303_);
v_r_2305_ = lean_box(v_res_2304_);
return v_r_2305_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBCoreEligible(lean_object* v_register_2343_, lean_object* v_word_2344_){
_start:
{
uint8_t v___y_2346_; lean_object* v___x_2350_; uint8_t v___x_2351_; 
v___x_2350_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBCoreRegisters));
v___x_2351_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_2343_, v___x_2350_);
if (v___x_2351_ == 0)
{
v___y_2346_ = v___x_2351_;
goto v___jp_2345_;
}
else
{
uint8_t v___x_2352_; 
v___x_2352_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_2343_, v_word_2344_);
v___y_2346_ = v___x_2352_;
goto v___jp_2345_;
}
v___jp_2345_:
{
if (v___y_2346_ == 0)
{
lean_dec(v_word_2344_);
lean_dec(v_register_2343_);
return v___y_2346_;
}
else
{
lean_object* v___x_2347_; uint8_t v___x_2348_; 
v___x_2347_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__4));
v___x_2348_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_2343_, v___x_2347_);
if (v___x_2348_ == 0)
{
lean_dec(v_word_2344_);
lean_dec(v_register_2343_);
return v___y_2346_;
}
else
{
uint8_t v___x_2349_; 
v___x_2349_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2343_, v_word_2344_);
return v___x_2349_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBCoreEligible___boxed(lean_object* v_register_2353_, lean_object* v_word_2354_){
_start:
{
uint8_t v_res_2355_; lean_object* v_r_2356_; 
v_res_2355_ = lp_lean1090_Lean1090_Impl_commBCoreEligible(v_register_2353_, v_word_2354_);
v_r_2356_ = lean_box(v_res_2355_);
return v_r_2356_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBPositionEligible(lean_object* v_df_2357_, lean_object* v_outerAltitude_2358_, lean_object* v_word_2359_){
_start:
{
lean_object* v___x_2360_; uint8_t v___x_2361_; 
v___x_2360_ = lean_unsigned_to_nat(20u);
v___x_2361_ = lean_nat_dec_eq(v_df_2357_, v___x_2360_);
if (v___x_2361_ == 0)
{
lean_dec(v_outerAltitude_2358_);
return v___x_2361_;
}
else
{
lean_object* v___x_2362_; lean_object* v___x_2363_; lean_object* v_tc_2364_; lean_object* v___x_2365_; uint8_t v___x_2366_; 
v___x_2362_ = lean_unsigned_to_nat(1u);
v___x_2363_ = lean_unsigned_to_nat(5u);
v_tc_2364_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2359_, v___x_2362_, v___x_2363_);
v___x_2365_ = lean_unsigned_to_nat(9u);
v___x_2366_ = lean_nat_dec_le(v___x_2365_, v_tc_2364_);
if (v___x_2366_ == 0)
{
lean_dec(v_tc_2364_);
lean_dec(v_outerAltitude_2358_);
return v___x_2366_;
}
else
{
lean_object* v___x_2367_; uint8_t v___x_2368_; 
v___x_2367_ = lean_unsigned_to_nat(22u);
v___x_2368_ = lean_nat_dec_lt(v_tc_2364_, v___x_2367_);
if (v___x_2368_ == 0)
{
lean_dec(v_tc_2364_);
lean_dec(v_outerAltitude_2358_);
return v___x_2368_;
}
else
{
lean_object* v___x_2369_; uint8_t v___x_2370_; 
v___x_2369_ = lean_unsigned_to_nat(19u);
v___x_2370_ = lean_nat_dec_eq(v_tc_2364_, v___x_2369_);
lean_dec(v_tc_2364_);
if (v___x_2370_ == 0)
{
uint8_t v___x_2371_; 
v___x_2371_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v___x_2363_, v_word_2359_);
if (v___x_2371_ == 0)
{
lean_dec(v_outerAltitude_2358_);
return v___x_2371_;
}
else
{
lean_object* v___x_2372_; lean_object* v___x_2373_; uint8_t v___x_2374_; 
v___x_2372_ = lean_alloc_closure((void*)(l_Int_instDecidableEq___boxed), 2, 0);
v___x_2373_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_word_2359_);
v___x_2374_ = l_Option_instDecidableEq___redArg(v___x_2372_, v___x_2373_, v_outerAltitude_2358_);
return v___x_2374_;
}
}
else
{
uint8_t v___x_2375_; 
lean_dec(v_outerAltitude_2358_);
v___x_2375_ = 0;
return v___x_2375_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBPositionEligible___boxed(lean_object* v_df_2376_, lean_object* v_outerAltitude_2377_, lean_object* v_word_2378_){
_start:
{
uint8_t v_res_2379_; lean_object* v_r_2380_; 
v_res_2379_ = lp_lean1090_Lean1090_Impl_commBPositionEligible(v_df_2376_, v_outerAltitude_2377_, v_word_2378_);
lean_dec(v_word_2378_);
lean_dec(v_df_2376_);
v_r_2380_ = lean_box(v_res_2379_);
return v_r_2380_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg(){
_start:
{
uint8_t v___x_2382_; 
v___x_2382_ = 0;
return v___x_2382_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg___boxed(lean_object* v___dummy_2383_){
_start:
{
uint8_t v_res_2384_; lean_object* v_r_2385_; 
v_res_2384_ = lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg();
v_r_2385_ = lean_box(v_res_2384_);
return v_r_2385_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBOperationEligible(lean_object* v___word_2386_){
_start:
{
uint8_t v___x_2387_; 
v___x_2387_ = 0;
return v___x_2387_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBOperationEligible___boxed(lean_object* v___word_2388_){
_start:
{
uint8_t v_res_2389_; lean_object* v_r_2390_; 
v_res_2389_ = lp_lean1090_Lean1090_Impl_commBOperationEligible(v___word_2388_);
lean_dec(v___word_2388_);
v_r_2390_ = lean_box(v_res_2389_);
return v_r_2390_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBEligible(lean_object* v_df_2391_, lean_object* v_outerAltitude_2392_, lean_object* v_register_2393_, lean_object* v_word_2394_){
_start:
{
lean_object* v___x_2405_; uint8_t v___x_2406_; 
v___x_2405_ = lean_unsigned_to_nat(20u);
v___x_2406_ = lean_nat_dec_eq(v_df_2391_, v___x_2405_);
if (v___x_2406_ == 0)
{
lean_object* v___x_2407_; uint8_t v___x_2408_; 
v___x_2407_ = lean_unsigned_to_nat(21u);
v___x_2408_ = lean_nat_dec_eq(v_df_2391_, v___x_2407_);
if (v___x_2408_ == 0)
{
lean_dec(v_word_2394_);
lean_dec(v_register_2393_);
lean_dec(v_outerAltitude_2392_);
return v___x_2408_;
}
else
{
goto v___jp_2395_;
}
}
else
{
goto v___jp_2395_;
}
v___jp_2395_:
{
lean_object* v___x_2396_; uint8_t v___x_2397_; 
v___x_2396_ = lean_unsigned_to_nat(0u);
v___x_2397_ = lean_nat_dec_eq(v_word_2394_, v___x_2396_);
if (v___x_2397_ == 0)
{
lean_object* v___x_2398_; uint8_t v___x_2399_; 
v___x_2398_ = lean_unsigned_to_nat(5u);
v___x_2399_ = lean_nat_dec_eq(v_register_2393_, v___x_2398_);
if (v___x_2399_ == 0)
{
lean_object* v___x_2400_; uint8_t v___x_2401_; 
lean_dec(v_outerAltitude_2392_);
v___x_2400_ = lean_unsigned_to_nat(101u);
v___x_2401_ = lean_nat_dec_eq(v_register_2393_, v___x_2400_);
if (v___x_2401_ == 0)
{
uint8_t v___x_2402_; 
v___x_2402_ = lp_lean1090_Lean1090_Impl_commBCoreEligible(v_register_2393_, v_word_2394_);
return v___x_2402_;
}
else
{
lean_dec(v_word_2394_);
lean_dec(v_register_2393_);
return v___x_2399_;
}
}
else
{
uint8_t v___x_2403_; 
lean_dec(v_register_2393_);
v___x_2403_ = lp_lean1090_Lean1090_Impl_commBPositionEligible(v_df_2391_, v_outerAltitude_2392_, v_word_2394_);
lean_dec(v_word_2394_);
return v___x_2403_;
}
}
else
{
uint8_t v___x_2404_; 
lean_dec(v_word_2394_);
lean_dec(v_register_2393_);
lean_dec(v_outerAltitude_2392_);
v___x_2404_ = 0;
return v___x_2404_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBEligible___boxed(lean_object* v_df_2409_, lean_object* v_outerAltitude_2410_, lean_object* v_register_2411_, lean_object* v_word_2412_){
_start:
{
uint8_t v_res_2413_; lean_object* v_r_2414_; 
v_res_2413_ = lp_lean1090_Lean1090_Impl_commBEligible(v_df_2409_, v_outerAltitude_2410_, v_register_2411_, v_word_2412_);
lean_dec(v_df_2409_);
v_r_2414_ = lean_box(v_res_2413_);
return v_r_2414_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBRegisters___closed__2(void){
_start:
{
lean_object* v___x_2421_; lean_object* v___x_2422_; lean_object* v___x_2423_; 
v___x_2421_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBRegisters___closed__1));
v___x_2422_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBRegisters___closed__0));
v___x_2423_ = l_List_appendTR___redArg(v___x_2422_, v___x_2421_);
return v___x_2423_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBRegisters(void){
_start:
{
lean_object* v___x_2424_; 
v___x_2424_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_commBRegisters___closed__2, &lp_lean1090_Lean1090_Impl_commBRegisters___closed__2_once, _init_lp_lean1090_Lean1090_Impl_commBRegisters___closed__2);
return v___x_2424_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(lean_object* v_df_2425_, lean_object* v_outerAltitude_2426_, lean_object* v_word_2427_, lean_object* v_a_2428_, lean_object* v_a_2429_){
_start:
{
if (lean_obj_tag(v_a_2428_) == 0)
{
lean_object* v___x_2430_; 
lean_dec(v_word_2427_);
lean_dec(v_outerAltitude_2426_);
v___x_2430_ = lean_array_to_list(v_a_2429_);
return v___x_2430_;
}
else
{
lean_object* v_head_2431_; lean_object* v_tail_2432_; lean_object* v___x_2434_; uint8_t v_isShared_2435_; uint8_t v_isSharedCheck_2446_; 
v_head_2431_ = lean_ctor_get(v_a_2428_, 0);
v_tail_2432_ = lean_ctor_get(v_a_2428_, 1);
v_isSharedCheck_2446_ = !lean_is_exclusive(v_a_2428_);
if (v_isSharedCheck_2446_ == 0)
{
v___x_2434_ = v_a_2428_;
v_isShared_2435_ = v_isSharedCheck_2446_;
goto v_resetjp_2433_;
}
else
{
lean_inc(v_tail_2432_);
lean_inc(v_head_2431_);
lean_dec(v_a_2428_);
v___x_2434_ = lean_box(0);
v_isShared_2435_ = v_isSharedCheck_2446_;
goto v_resetjp_2433_;
}
v_resetjp_2433_:
{
uint8_t v___x_2436_; 
lean_inc(v_word_2427_);
lean_inc(v_head_2431_);
lean_inc(v_outerAltitude_2426_);
v___x_2436_ = lp_lean1090_Lean1090_Impl_commBEligible(v_df_2425_, v_outerAltitude_2426_, v_head_2431_, v_word_2427_);
if (v___x_2436_ == 0)
{
lean_del_object(v___x_2434_);
lean_dec(v_head_2431_);
v_a_2428_ = v_tail_2432_;
goto _start;
}
else
{
lean_object* v___x_2438_; 
lean_inc(v_head_2431_);
v___x_2438_ = lp_lean1090_Lean1090_Impl_decodeBDS(v_head_2431_, v_word_2427_);
if (lean_obj_tag(v___x_2438_) == 0)
{
lean_del_object(v___x_2434_);
lean_dec(v_head_2431_);
v_a_2428_ = v_tail_2432_;
goto _start;
}
else
{
lean_object* v_val_2440_; lean_object* v___x_2442_; 
v_val_2440_ = lean_ctor_get(v___x_2438_, 0);
lean_inc(v_val_2440_);
lean_dec_ref_known(v___x_2438_, 1);
if (v_isShared_2435_ == 0)
{
lean_ctor_set_tag(v___x_2434_, 0);
lean_ctor_set(v___x_2434_, 1, v_val_2440_);
v___x_2442_ = v___x_2434_;
goto v_reusejp_2441_;
}
else
{
lean_object* v_reuseFailAlloc_2445_; 
v_reuseFailAlloc_2445_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2445_, 0, v_head_2431_);
lean_ctor_set(v_reuseFailAlloc_2445_, 1, v_val_2440_);
v___x_2442_ = v_reuseFailAlloc_2445_;
goto v_reusejp_2441_;
}
v_reusejp_2441_:
{
lean_object* v___x_2443_; 
v___x_2443_ = lean_array_push(v_a_2429_, v___x_2442_);
v_a_2428_ = v_tail_2432_;
v_a_2429_ = v___x_2443_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0___boxed(lean_object* v_df_2447_, lean_object* v_outerAltitude_2448_, lean_object* v_word_2449_, lean_object* v_a_2450_, lean_object* v_a_2451_){
_start:
{
lean_object* v_res_2452_; 
v_res_2452_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(v_df_2447_, v_outerAltitude_2448_, v_word_2449_, v_a_2450_, v_a_2451_);
lean_dec(v_df_2447_);
return v_res_2452_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_inferCommB(lean_object* v_df_2455_, lean_object* v_outerAltitude_2456_, lean_object* v_word_2457_){
_start:
{
lean_object* v___x_2458_; lean_object* v___x_2459_; lean_object* v___x_2460_; 
v___x_2458_ = lp_lean1090_Lean1090_Impl_commBRegisters;
v___x_2459_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_inferCommB___closed__0));
v___x_2460_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(v_df_2455_, v_outerAltitude_2456_, v_word_2457_, v___x_2458_, v___x_2459_);
return v___x_2460_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_inferCommB___boxed(lean_object* v_df_2461_, lean_object* v_outerAltitude_2462_, lean_object* v_word_2463_){
_start:
{
lean_object* v_res_2464_; 
v_res_2464_ = lp_lean1090_Lean1090_Impl_inferCommB(v_df_2461_, v_outerAltitude_2462_, v_word_2463_);
lean_dec(v_df_2461_);
return v_res_2464_;
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
