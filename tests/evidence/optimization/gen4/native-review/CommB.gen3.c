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
lean_object* l_Array_ofFn___redArg(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_commBLayout(lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_payloadValue(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbLayout(lean_object*);
extern lean_object* lp_lean1090_Lean1090_Impl_adsbPositionLayout;
lean_object* lp_lean1090_Lean1090_Impl_decodePayloadFields(lean_object*, lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
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
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbMach64___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbMach64___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbMach64___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbMach64___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbMach64___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbMach64___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_cbMach64___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_cbMach64___closed__3;
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
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMach64___closed__0(void){
_start:
{
lean_object* v___x_104_; lean_object* v___x_105_; 
v___x_104_ = lean_unsigned_to_nat(125u);
v___x_105_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_104_);
return v___x_105_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMach64___closed__1(void){
_start:
{
lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_108_; 
v___x_106_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMach64___closed__0, &lp_lean1090_Lean1090_Impl_cbMach64___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbMach64___closed__0);
v___x_107_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_108_ = l_Rat_div(v___x_107_, v___x_106_);
return v___x_108_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMach64___closed__2(void){
_start:
{
lean_object* v___x_109_; lean_object* v___x_110_; 
v___x_109_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMach64___closed__1, &lp_lean1090_Lean1090_Impl_cbMach64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbMach64___closed__1);
v___x_110_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_109_);
return v___x_110_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMach64___closed__3(void){
_start:
{
lean_object* v___x_111_; lean_object* v___x_112_; 
v___x_111_ = lean_unsigned_to_nat(512u);
v___x_112_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_111_);
return v___x_112_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMach64(lean_object* v_word_113_){
_start:
{
lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v___x_116_; lean_object* v___x_117_; lean_object* v___x_118_; lean_object* v___x_119_; lean_object* v___x_120_; lean_object* v___x_121_; 
v___x_114_ = lean_unsigned_to_nat(25u);
v___x_115_ = lean_unsigned_to_nat(10u);
v___x_116_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_113_, v___x_114_, v___x_115_);
v___x_117_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_116_);
v___x_118_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMach64___closed__2, &lp_lean1090_Lean1090_Impl_cbMach64___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbMach64___closed__2);
v___x_119_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_117_, v___x_118_);
lean_dec_ref(v___x_117_);
v___x_120_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMach64___closed__3, &lp_lean1090_Lean1090_Impl_cbMach64___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbMach64___closed__3);
v___x_121_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_119_, v___x_120_);
lean_dec_ref(v___x_119_);
return v___x_121_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMach64___boxed(lean_object* v_word_122_){
_start:
{
lean_object* v_res_123_; 
v_res_123_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_122_);
lean_dec(v_word_122_);
return v_res_123_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0(void){
_start:
{
lean_object* v___x_124_; lean_object* v___x_125_; 
v___x_124_ = lean_unsigned_to_nat(360u);
v___x_125_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_124_);
return v___x_125_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWrapAngle(lean_object* v_value_126_){
_start:
{
lean_object* v___x_127_; uint8_t v___x_128_; 
v___x_127_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_value_126_);
v___x_128_ = l_Rat_blt(v_value_126_, v___x_127_);
if (v___x_128_ == 0)
{
return v_value_126_;
}
else
{
lean_object* v___x_129_; lean_object* v___x_130_; 
v___x_129_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0, &lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbWrapAngle___closed__0);
v___x_130_ = l_Rat_add(v_value_126_, v___x_129_);
return v___x_130_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(lean_object* v_name_131_, lean_object* v_x_132_){
_start:
{
if (lean_obj_tag(v_x_132_) == 0)
{
lean_object* v___x_133_; 
v___x_133_ = lean_box(0);
return v___x_133_;
}
else
{
lean_object* v_head_134_; lean_object* v_tail_135_; lean_object* v_name_136_; uint8_t v___x_137_; 
v_head_134_ = lean_ctor_get(v_x_132_, 0);
v_tail_135_ = lean_ctor_get(v_x_132_, 1);
v_name_136_ = lean_ctor_get(v_head_134_, 0);
v___x_137_ = lean_string_dec_eq(v_name_136_, v_name_131_);
if (v___x_137_ == 0)
{
v_x_132_ = v_tail_135_;
goto _start;
}
else
{
lean_object* v___x_139_; 
lean_inc(v_head_134_);
v___x_139_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_139_, 0, v_head_134_);
return v___x_139_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0___boxed(lean_object* v_name_140_, lean_object* v_x_141_){
_start:
{
lean_object* v_res_142_; 
v_res_142_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(v_name_140_, v_x_141_);
lean_dec(v_x_141_);
lean_dec_ref(v_name_140_);
return v_res_142_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBValue(lean_object* v_register_152_, lean_object* v_word_153_, lean_object* v_name_154_){
_start:
{
lean_object* v___x_155_; 
v___x_155_ = lp_lean1090_Lean1090_Impl_commBLayout(v_register_152_);
if (lean_obj_tag(v___x_155_) == 0)
{
lean_object* v___x_156_; 
v___x_156_ = lean_box(0);
return v___x_156_;
}
else
{
lean_object* v_val_157_; lean_object* v___x_158_; 
v_val_157_ = lean_ctor_get(v___x_155_, 0);
lean_inc(v_val_157_);
lean_dec_ref_known(v___x_155_, 1);
v___x_158_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_commBValue_spec__0(v_name_154_, v_val_157_);
lean_dec(v_val_157_);
if (lean_obj_tag(v___x_158_) == 0)
{
lean_object* v___x_159_; 
v___x_159_ = lean_box(0);
return v___x_159_;
}
else
{
lean_object* v_val_160_; lean_object* v___x_162_; uint8_t v_isShared_163_; uint8_t v_isSharedCheck_276_; 
v_val_160_ = lean_ctor_get(v___x_158_, 0);
v_isSharedCheck_276_ = !lean_is_exclusive(v___x_158_);
if (v_isSharedCheck_276_ == 0)
{
v___x_162_ = v___x_158_;
v_isShared_163_ = v_isSharedCheck_276_;
goto v_resetjp_161_;
}
else
{
lean_inc(v_val_160_);
lean_dec(v___x_158_);
v___x_162_ = lean_box(0);
v_isShared_163_ = v_isSharedCheck_276_;
goto v_resetjp_161_;
}
v_resetjp_161_:
{
lean_object* v___x_164_; 
v___x_164_ = lp_lean1090_Lean1090_Impl_payloadValue(v_val_160_, v_word_153_);
if (lean_obj_tag(v___x_164_) == 0)
{
lean_del_object(v___x_162_);
return v___x_164_;
}
else
{
lean_object* v_val_165_; lean_object* v___x_171_; uint8_t v___x_172_; 
v_val_165_ = lean_ctor_get(v___x_164_, 0);
lean_inc(v_val_165_);
v___x_171_ = lean_unsigned_to_nat(16u);
v___x_172_ = lean_nat_dec_eq(v_register_152_, v___x_171_);
if (v___x_172_ == 0)
{
lean_object* v___x_173_; uint8_t v___x_174_; 
v___x_173_ = lean_unsigned_to_nat(64u);
v___x_174_ = lean_nat_dec_eq(v_register_152_, v___x_173_);
if (v___x_174_ == 0)
{
lean_object* v___x_175_; uint8_t v___x_176_; 
v___x_175_ = lean_unsigned_to_nat(68u);
v___x_176_ = lean_nat_dec_eq(v_register_152_, v___x_175_);
if (v___x_176_ == 0)
{
lean_object* v___x_177_; uint8_t v___x_178_; 
v___x_177_ = lean_unsigned_to_nat(80u);
v___x_178_ = lean_nat_dec_eq(v_register_152_, v___x_177_);
if (v___x_178_ == 0)
{
lean_object* v___x_179_; uint8_t v___x_180_; 
v___x_179_ = lean_unsigned_to_nat(96u);
v___x_180_ = lean_nat_dec_eq(v_register_152_, v___x_179_);
if (v___x_180_ == 0)
{
lean_dec(v_val_165_);
lean_del_object(v___x_162_);
return v___x_164_;
}
else
{
lean_object* v___x_181_; uint8_t v___x_182_; 
v___x_181_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__0));
v___x_182_ = lean_string_dec_eq(v_name_154_, v___x_181_);
if (v___x_182_ == 0)
{
lean_object* v___x_183_; uint8_t v___x_184_; 
lean_dec(v_val_165_);
lean_del_object(v___x_162_);
v___x_183_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__1));
v___x_184_ = lean_string_dec_eq(v_name_154_, v___x_183_);
if (v___x_184_ == 0)
{
lean_object* v___x_185_; uint8_t v___x_186_; 
v___x_185_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__2));
v___x_186_ = lean_string_dec_eq(v_name_154_, v___x_185_);
if (v___x_186_ == 0)
{
return v___x_164_;
}
else
{
lean_object* v___x_188_; uint8_t v_isShared_189_; uint8_t v_isSharedCheck_195_; 
v_isSharedCheck_195_ = !lean_is_exclusive(v___x_164_);
if (v_isSharedCheck_195_ == 0)
{
lean_object* v_unused_196_; 
v_unused_196_ = lean_ctor_get(v___x_164_, 0);
lean_dec(v_unused_196_);
v___x_188_ = v___x_164_;
v_isShared_189_ = v_isSharedCheck_195_;
goto v_resetjp_187_;
}
else
{
lean_dec(v___x_164_);
v___x_188_ = lean_box(0);
v_isShared_189_ = v_isSharedCheck_195_;
goto v_resetjp_187_;
}
v_resetjp_187_:
{
lean_object* v___x_190_; lean_object* v___x_191_; lean_object* v___x_193_; 
v___x_190_ = lean_unsigned_to_nat(47u);
v___x_191_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_153_, v___x_190_);
if (v_isShared_189_ == 0)
{
lean_ctor_set(v___x_188_, 0, v___x_191_);
v___x_193_ = v___x_188_;
goto v_reusejp_192_;
}
else
{
lean_object* v_reuseFailAlloc_194_; 
v_reuseFailAlloc_194_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_194_, 0, v___x_191_);
v___x_193_ = v_reuseFailAlloc_194_;
goto v_reusejp_192_;
}
v_reusejp_192_:
{
return v___x_193_;
}
}
}
}
else
{
lean_object* v___x_198_; uint8_t v_isShared_199_; uint8_t v_isSharedCheck_205_; 
v_isSharedCheck_205_ = !lean_is_exclusive(v___x_164_);
if (v_isSharedCheck_205_ == 0)
{
lean_object* v_unused_206_; 
v_unused_206_ = lean_ctor_get(v___x_164_, 0);
lean_dec(v_unused_206_);
v___x_198_ = v___x_164_;
v_isShared_199_ = v_isSharedCheck_205_;
goto v_resetjp_197_;
}
else
{
lean_dec(v___x_164_);
v___x_198_ = lean_box(0);
v_isShared_199_ = v_isSharedCheck_205_;
goto v_resetjp_197_;
}
v_resetjp_197_:
{
lean_object* v___x_200_; lean_object* v___x_201_; lean_object* v___x_203_; 
v___x_200_ = lean_unsigned_to_nat(36u);
v___x_201_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_153_, v___x_200_);
if (v_isShared_199_ == 0)
{
lean_ctor_set(v___x_198_, 0, v___x_201_);
v___x_203_ = v___x_198_;
goto v_reusejp_202_;
}
else
{
lean_object* v_reuseFailAlloc_204_; 
v_reuseFailAlloc_204_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_204_, 0, v___x_201_);
v___x_203_ = v_reuseFailAlloc_204_;
goto v_reusejp_202_;
}
v_reusejp_202_:
{
return v___x_203_;
}
}
}
}
else
{
lean_dec_ref_known(v___x_164_, 1);
goto v___jp_166_;
}
}
}
else
{
lean_object* v___x_207_; uint8_t v___x_208_; 
v___x_207_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__3));
v___x_208_ = lean_string_dec_eq(v_name_154_, v___x_207_);
if (v___x_208_ == 0)
{
lean_object* v___x_209_; uint8_t v___x_210_; 
lean_dec(v_val_165_);
lean_del_object(v___x_162_);
v___x_209_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__4));
v___x_210_ = lean_string_dec_eq(v_name_154_, v___x_209_);
if (v___x_210_ == 0)
{
return v___x_164_;
}
else
{
lean_object* v___x_211_; lean_object* v___x_212_; lean_object* v___x_213_; lean_object* v___x_214_; uint8_t v___x_215_; 
v___x_211_ = lean_unsigned_to_nat(37u);
v___x_212_ = lean_unsigned_to_nat(9u);
v___x_213_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_153_, v___x_211_, v___x_212_);
v___x_214_ = lean_unsigned_to_nat(511u);
v___x_215_ = lean_nat_dec_eq(v___x_213_, v___x_214_);
lean_dec(v___x_213_);
if (v___x_215_ == 0)
{
return v___x_164_;
}
else
{
lean_object* v___x_216_; 
lean_dec_ref_known(v___x_164_, 1);
v___x_216_ = lean_box(0);
return v___x_216_;
}
}
}
else
{
lean_dec_ref_known(v___x_164_, 1);
goto v___jp_166_;
}
}
}
else
{
lean_object* v___x_217_; uint8_t v___x_218_; 
lean_dec(v_val_165_);
lean_del_object(v___x_162_);
v___x_217_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__5));
v___x_218_ = lean_string_dec_eq(v_name_154_, v___x_217_);
if (v___x_218_ == 0)
{
return v___x_164_;
}
else
{
lean_object* v___x_220_; uint8_t v_isShared_221_; uint8_t v_isSharedCheck_226_; 
v_isSharedCheck_226_ = !lean_is_exclusive(v___x_164_);
if (v_isSharedCheck_226_ == 0)
{
lean_object* v_unused_227_; 
v_unused_227_ = lean_ctor_get(v___x_164_, 0);
lean_dec(v_unused_227_);
v___x_220_ = v___x_164_;
v_isShared_221_ = v_isSharedCheck_226_;
goto v_resetjp_219_;
}
else
{
lean_dec(v___x_164_);
v___x_220_ = lean_box(0);
v_isShared_221_ = v_isSharedCheck_226_;
goto v_resetjp_219_;
}
v_resetjp_219_:
{
lean_object* v___x_222_; lean_object* v___x_224_; 
v___x_222_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_153_);
if (v_isShared_221_ == 0)
{
lean_ctor_set(v___x_220_, 0, v___x_222_);
v___x_224_ = v___x_220_;
goto v_reusejp_223_;
}
else
{
lean_object* v_reuseFailAlloc_225_; 
v_reuseFailAlloc_225_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_225_, 0, v___x_222_);
v___x_224_ = v_reuseFailAlloc_225_;
goto v_reusejp_223_;
}
v_reusejp_223_:
{
return v___x_224_;
}
}
}
}
}
else
{
lean_object* v___x_228_; uint8_t v___x_229_; 
lean_dec(v_val_165_);
lean_del_object(v___x_162_);
v___x_228_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__6));
v___x_229_ = lean_string_dec_eq(v_name_154_, v___x_228_);
if (v___x_229_ == 0)
{
lean_object* v___x_230_; uint8_t v___x_231_; 
v___x_230_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__7));
v___x_231_ = lean_string_dec_eq(v_name_154_, v___x_230_);
if (v___x_231_ == 0)
{
return v___x_164_;
}
else
{
lean_object* v___x_233_; uint8_t v_isShared_234_; uint8_t v_isSharedCheck_242_; 
v_isSharedCheck_242_ = !lean_is_exclusive(v___x_164_);
if (v_isSharedCheck_242_ == 0)
{
lean_object* v_unused_243_; 
v_unused_243_ = lean_ctor_get(v___x_164_, 0);
lean_dec(v_unused_243_);
v___x_233_ = v___x_164_;
v_isShared_234_ = v_isSharedCheck_242_;
goto v_resetjp_232_;
}
else
{
lean_dec(v___x_164_);
v___x_233_ = lean_box(0);
v_isShared_234_ = v_isSharedCheck_242_;
goto v_resetjp_232_;
}
v_resetjp_232_:
{
lean_object* v___x_235_; lean_object* v___x_236_; lean_object* v___x_237_; lean_object* v___x_238_; lean_object* v___x_240_; 
v___x_235_ = lean_unsigned_to_nat(15u);
v___x_236_ = lean_unsigned_to_nat(12u);
v___x_237_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_153_, v___x_235_, v___x_236_);
v___x_238_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_237_);
lean_dec(v___x_237_);
if (v_isShared_234_ == 0)
{
lean_ctor_set(v___x_233_, 0, v___x_238_);
v___x_240_ = v___x_233_;
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
else
{
lean_object* v___x_245_; uint8_t v_isShared_246_; uint8_t v_isSharedCheck_254_; 
v_isSharedCheck_254_ = !lean_is_exclusive(v___x_164_);
if (v_isSharedCheck_254_ == 0)
{
lean_object* v_unused_255_; 
v_unused_255_ = lean_ctor_get(v___x_164_, 0);
lean_dec(v_unused_255_);
v___x_245_ = v___x_164_;
v_isShared_246_ = v_isSharedCheck_254_;
goto v_resetjp_244_;
}
else
{
lean_dec(v___x_164_);
v___x_245_ = lean_box(0);
v_isShared_246_ = v_isSharedCheck_254_;
goto v_resetjp_244_;
}
v_resetjp_244_:
{
lean_object* v___x_247_; lean_object* v___x_248_; lean_object* v___x_249_; lean_object* v___x_250_; lean_object* v___x_252_; 
v___x_247_ = lean_unsigned_to_nat(2u);
v___x_248_ = lean_unsigned_to_nat(12u);
v___x_249_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_153_, v___x_247_, v___x_248_);
v___x_250_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_249_);
lean_dec(v___x_249_);
if (v_isShared_246_ == 0)
{
lean_ctor_set(v___x_245_, 0, v___x_250_);
v___x_252_ = v___x_245_;
goto v_reusejp_251_;
}
else
{
lean_object* v_reuseFailAlloc_253_; 
v_reuseFailAlloc_253_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_253_, 0, v___x_250_);
v___x_252_ = v_reuseFailAlloc_253_;
goto v_reusejp_251_;
}
v_reusejp_251_:
{
return v___x_252_;
}
}
}
}
}
else
{
lean_object* v___x_256_; uint8_t v___x_257_; 
lean_dec(v_val_165_);
lean_del_object(v___x_162_);
v___x_256_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__8));
v___x_257_ = lean_string_dec_eq(v_name_154_, v___x_256_);
if (v___x_257_ == 0)
{
return v___x_164_;
}
else
{
lean_object* v___x_259_; uint8_t v_isShared_260_; uint8_t v_isSharedCheck_274_; 
v_isSharedCheck_274_ = !lean_is_exclusive(v___x_164_);
if (v_isSharedCheck_274_ == 0)
{
lean_object* v_unused_275_; 
v_unused_275_ = lean_ctor_get(v___x_164_, 0);
lean_dec(v_unused_275_);
v___x_259_ = v___x_164_;
v_isShared_260_ = v_isSharedCheck_274_;
goto v_resetjp_258_;
}
else
{
lean_dec(v___x_164_);
v___x_259_ = lean_box(0);
v_isShared_260_ = v_isSharedCheck_274_;
goto v_resetjp_258_;
}
v_resetjp_258_:
{
lean_object* v___x_261_; lean_object* v___x_262_; lean_object* v___x_263_; lean_object* v___x_264_; lean_object* v___x_265_; lean_object* v___x_266_; lean_object* v___x_267_; lean_object* v___x_268_; lean_object* v___x_269_; lean_object* v___x_270_; lean_object* v___x_272_; 
v___x_261_ = lean_unsigned_to_nat(41u);
v___x_262_ = lean_unsigned_to_nat(8u);
v___x_263_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_153_, v___x_261_, v___x_262_);
v___x_264_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_263_);
v___x_265_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_266_ = lean_unsigned_to_nat(49u);
v___x_267_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_153_, v___x_266_, v___x_262_);
v___x_268_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_267_);
v___x_269_ = l_Rat_mul(v___x_265_, v___x_268_);
v___x_270_ = l_Rat_add(v___x_264_, v___x_269_);
if (v_isShared_260_ == 0)
{
lean_ctor_set(v___x_259_, 0, v___x_270_);
v___x_272_ = v___x_259_;
goto v_reusejp_271_;
}
else
{
lean_object* v_reuseFailAlloc_273_; 
v_reuseFailAlloc_273_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_273_, 0, v___x_270_);
v___x_272_ = v_reuseFailAlloc_273_;
goto v_reusejp_271_;
}
v_reusejp_271_:
{
return v___x_272_;
}
}
}
}
v___jp_166_:
{
lean_object* v___x_167_; lean_object* v___x_169_; 
v___x_167_ = lp_lean1090_Lean1090_Impl_cbWrapAngle(v_val_165_);
if (v_isShared_163_ == 0)
{
lean_ctor_set(v___x_162_, 0, v___x_167_);
v___x_169_ = v___x_162_;
goto v_reusejp_168_;
}
else
{
lean_object* v_reuseFailAlloc_170_; 
v_reuseFailAlloc_170_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_170_, 0, v___x_167_);
v___x_169_ = v_reuseFailAlloc_170_;
goto v_reusejp_168_;
}
v_reusejp_168_:
{
return v___x_169_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBValue___boxed(lean_object* v_register_277_, lean_object* v_word_278_, lean_object* v_name_279_){
_start:
{
lean_object* v_res_280_; 
v_res_280_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_277_, v_word_278_, v_name_279_);
lean_dec_ref(v_name_279_);
lean_dec(v_word_278_);
lean_dec(v_register_277_);
return v_res_280_;
}
}
LEAN_EXPORT uint32_t lp_lean1090_Lean1090_Impl_cbCharacter(lean_object* v_code_281_){
_start:
{
lean_object* v___x_293_; uint8_t v___x_294_; 
v___x_293_ = lean_unsigned_to_nat(1u);
v___x_294_ = lean_nat_dec_le(v___x_293_, v_code_281_);
if (v___x_294_ == 0)
{
goto v___jp_287_;
}
else
{
lean_object* v___x_295_; uint8_t v___x_296_; 
v___x_295_ = lean_unsigned_to_nat(26u);
v___x_296_ = lean_nat_dec_le(v_code_281_, v___x_295_);
if (v___x_296_ == 0)
{
goto v___jp_287_;
}
else
{
lean_object* v___x_297_; lean_object* v___x_298_; uint32_t v___x_299_; 
v___x_297_ = lean_unsigned_to_nat(64u);
v___x_298_ = lean_nat_add(v___x_297_, v_code_281_);
v___x_299_ = l_Char_ofNat(v___x_298_);
lean_dec(v___x_298_);
return v___x_299_;
}
}
v___jp_282_:
{
lean_object* v___x_283_; uint8_t v___x_284_; 
v___x_283_ = lean_unsigned_to_nat(32u);
v___x_284_ = lean_nat_dec_eq(v_code_281_, v___x_283_);
if (v___x_284_ == 0)
{
uint32_t v___x_285_; 
v___x_285_ = 35;
return v___x_285_;
}
else
{
uint32_t v___x_286_; 
v___x_286_ = 32;
return v___x_286_;
}
}
v___jp_287_:
{
lean_object* v___x_288_; uint8_t v___x_289_; 
v___x_288_ = lean_unsigned_to_nat(48u);
v___x_289_ = lean_nat_dec_le(v___x_288_, v_code_281_);
if (v___x_289_ == 0)
{
goto v___jp_282_;
}
else
{
lean_object* v___x_290_; uint8_t v___x_291_; 
v___x_290_ = lean_unsigned_to_nat(57u);
v___x_291_ = lean_nat_dec_le(v_code_281_, v___x_290_);
if (v___x_291_ == 0)
{
goto v___jp_282_;
}
else
{
uint32_t v___x_292_; 
v___x_292_ = l_Char_ofNat(v_code_281_);
return v___x_292_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCharacter___boxed(lean_object* v_code_300_){
_start:
{
uint32_t v_res_301_; lean_object* v_r_302_; 
v_res_301_ = lp_lean1090_Lean1090_Impl_cbCharacter(v_code_300_);
lean_dec(v_code_300_);
v_r_302_ = lean_box_uint32(v_res_301_);
return v_r_302_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(lean_object* v_a_303_, lean_object* v_a_304_){
_start:
{
if (lean_obj_tag(v_a_303_) == 0)
{
lean_object* v___x_305_; 
v___x_305_ = l_List_reverse___redArg(v_a_304_);
return v___x_305_;
}
else
{
lean_object* v_head_306_; lean_object* v_tail_307_; lean_object* v___x_309_; uint8_t v_isShared_310_; uint8_t v_isSharedCheck_317_; 
v_head_306_ = lean_ctor_get(v_a_303_, 0);
v_tail_307_ = lean_ctor_get(v_a_303_, 1);
v_isSharedCheck_317_ = !lean_is_exclusive(v_a_303_);
if (v_isSharedCheck_317_ == 0)
{
v___x_309_ = v_a_303_;
v_isShared_310_ = v_isSharedCheck_317_;
goto v_resetjp_308_;
}
else
{
lean_inc(v_tail_307_);
lean_inc(v_head_306_);
lean_dec(v_a_303_);
v___x_309_ = lean_box(0);
v_isShared_310_ = v_isSharedCheck_317_;
goto v_resetjp_308_;
}
v_resetjp_308_:
{
uint32_t v___x_311_; lean_object* v___x_312_; lean_object* v___x_314_; 
v___x_311_ = lp_lean1090_Lean1090_Impl_cbCharacter(v_head_306_);
lean_dec(v_head_306_);
v___x_312_ = lean_box_uint32(v___x_311_);
if (v_isShared_310_ == 0)
{
lean_ctor_set(v___x_309_, 1, v_a_304_);
lean_ctor_set(v___x_309_, 0, v___x_312_);
v___x_314_ = v___x_309_;
goto v_reusejp_313_;
}
else
{
lean_object* v_reuseFailAlloc_316_; 
v_reuseFailAlloc_316_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_316_, 0, v___x_312_);
lean_ctor_set(v_reuseFailAlloc_316_, 1, v_a_304_);
v___x_314_ = v_reuseFailAlloc_316_;
goto v_reusejp_313_;
}
v_reusejp_313_:
{
v_a_303_ = v_tail_307_;
v_a_304_ = v___x_314_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbCallsign_spec__0(lean_object* v_a_318_, lean_object* v_a_319_){
_start:
{
if (lean_obj_tag(v_a_318_) == 0)
{
lean_object* v___x_320_; 
v___x_320_ = l_List_reverse___redArg(v_a_319_);
return v___x_320_;
}
else
{
lean_object* v_head_321_; lean_object* v_tail_322_; lean_object* v___x_324_; uint8_t v_isShared_325_; uint8_t v_isSharedCheck_333_; 
v_head_321_ = lean_ctor_get(v_a_318_, 0);
v_tail_322_ = lean_ctor_get(v_a_318_, 1);
v_isSharedCheck_333_ = !lean_is_exclusive(v_a_318_);
if (v_isSharedCheck_333_ == 0)
{
v___x_324_ = v_a_318_;
v_isShared_325_ = v_isSharedCheck_333_;
goto v_resetjp_323_;
}
else
{
lean_inc(v_tail_322_);
lean_inc(v_head_321_);
lean_dec(v_a_318_);
v___x_324_ = lean_box(0);
v_isShared_325_ = v_isSharedCheck_333_;
goto v_resetjp_323_;
}
v_resetjp_323_:
{
lean_object* v___x_326_; uint8_t v___x_327_; 
v___x_326_ = lean_unsigned_to_nat(32u);
v___x_327_ = lean_nat_dec_eq(v_head_321_, v___x_326_);
if (v___x_327_ == 0)
{
lean_object* v___x_329_; 
if (v_isShared_325_ == 0)
{
lean_ctor_set(v___x_324_, 1, v_a_319_);
v___x_329_ = v___x_324_;
goto v_reusejp_328_;
}
else
{
lean_object* v_reuseFailAlloc_331_; 
v_reuseFailAlloc_331_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_331_, 0, v_head_321_);
lean_ctor_set(v_reuseFailAlloc_331_, 1, v_a_319_);
v___x_329_ = v_reuseFailAlloc_331_;
goto v_reusejp_328_;
}
v_reusejp_328_:
{
v_a_318_ = v_tail_322_;
v_a_319_ = v___x_329_;
goto _start;
}
}
else
{
lean_del_object(v___x_324_);
lean_dec(v_head_321_);
v_a_318_ = v_tail_322_;
goto _start;
}
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbCallsign___closed__0(void){
_start:
{
lean_object* v___x_334_; lean_object* v___x_335_; 
v___x_334_ = lean_unsigned_to_nat(8u);
v___x_335_ = l_List_range(v___x_334_);
return v___x_335_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCallsign(lean_object* v_word_336_){
_start:
{
lean_object* v___x_337_; lean_object* v___x_338_; lean_object* v___x_339_; lean_object* v___x_340_; lean_object* v___x_341_; lean_object* v___x_342_; 
v___x_337_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbCallsign___closed__0, &lp_lean1090_Lean1090_Impl_cbCallsign___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbCallsign___closed__0);
v___x_338_ = lean_box(0);
v___x_339_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_adsbCallsign_spec__0(v_word_336_, v___x_337_, v___x_338_);
v___x_340_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbCallsign_spec__0(v___x_339_, v___x_338_);
v___x_341_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(v___x_340_, v___x_338_);
v___x_342_ = lean_string_mk(v___x_341_);
return v___x_342_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCallsign___boxed(lean_object* v_word_343_){
_start:
{
lean_object* v_res_344_; 
v_res_344_ = lp_lean1090_Lean1090_Impl_cbCallsign(v_word_343_);
lean_dec(v_word_343_);
return v_res_344_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbThreat(lean_object* v_word_345_){
_start:
{
lean_object* v___x_346_; lean_object* v___x_347_; lean_object* v___x_348_; lean_object* v___x_349_; uint8_t v___x_350_; 
v___x_346_ = lean_unsigned_to_nat(29u);
v___x_347_ = lean_unsigned_to_nat(2u);
v___x_348_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_345_, v___x_346_, v___x_347_);
v___x_349_ = lean_unsigned_to_nat(0u);
v___x_350_ = lean_nat_dec_eq(v___x_348_, v___x_349_);
if (v___x_350_ == 0)
{
lean_object* v___x_351_; uint8_t v___x_352_; 
v___x_351_ = lean_unsigned_to_nat(1u);
v___x_352_ = lean_nat_dec_eq(v___x_348_, v___x_351_);
if (v___x_352_ == 0)
{
uint8_t v___x_353_; 
v___x_353_ = lean_nat_dec_eq(v___x_348_, v___x_347_);
lean_dec(v___x_348_);
if (v___x_353_ == 0)
{
lean_object* v___x_354_; 
v___x_354_ = lean_box(3);
return v___x_354_;
}
else
{
lean_object* v___x_355_; lean_object* v___x_356_; lean_object* v_range_357_; lean_object* v___x_358_; lean_object* v___x_359_; lean_object* v_bearing_360_; lean_object* v___x_361_; lean_object* v___x_362_; lean_object* v___x_363_; lean_object* v___x_364_; lean_object* v___y_366_; uint8_t v___x_376_; 
v___x_355_ = lean_unsigned_to_nat(44u);
v___x_356_ = lean_unsigned_to_nat(7u);
v_range_357_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_345_, v___x_355_, v___x_356_);
v___x_358_ = lean_unsigned_to_nat(51u);
v___x_359_ = lean_unsigned_to_nat(6u);
v_bearing_360_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_345_, v___x_358_, v___x_359_);
v___x_361_ = lean_unsigned_to_nat(31u);
v___x_362_ = lean_unsigned_to_nat(13u);
v___x_363_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_345_, v___x_361_, v___x_362_);
v___x_364_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v___x_363_);
lean_dec(v___x_363_);
v___x_376_ = lean_nat_dec_eq(v_range_357_, v___x_349_);
if (v___x_376_ == 0)
{
lean_object* v___x_377_; lean_object* v___x_378_; lean_object* v___x_379_; lean_object* v___x_380_; lean_object* v___x_381_; 
v___x_377_ = lean_nat_sub(v_range_357_, v___x_351_);
lean_dec(v_range_357_);
v___x_378_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_377_);
v___x_379_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_380_ = l_Rat_div(v___x_378_, v___x_379_);
lean_dec_ref(v___x_378_);
v___x_381_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_381_, 0, v___x_380_);
v___y_366_ = v___x_381_;
goto v___jp_365_;
}
else
{
lean_object* v___x_382_; 
lean_dec(v_range_357_);
v___x_382_ = lean_box(0);
v___y_366_ = v___x_382_;
goto v___jp_365_;
}
v___jp_365_:
{
uint8_t v___x_367_; 
v___x_367_ = lean_nat_dec_eq(v_bearing_360_, v___x_349_);
if (v___x_367_ == 0)
{
lean_object* v___x_368_; lean_object* v___x_369_; lean_object* v___x_370_; lean_object* v___x_371_; lean_object* v___x_372_; lean_object* v___x_373_; 
v___x_368_ = lean_nat_sub(v_bearing_360_, v___x_351_);
lean_dec(v_bearing_360_);
v___x_369_ = lean_nat_mul(v___x_359_, v___x_368_);
lean_dec(v___x_368_);
v___x_370_ = lean_unsigned_to_nat(3u);
v___x_371_ = lean_nat_add(v___x_369_, v___x_370_);
lean_dec(v___x_369_);
v___x_372_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_372_, 0, v___x_371_);
v___x_373_ = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(v___x_373_, 0, v___x_364_);
lean_ctor_set(v___x_373_, 1, v___y_366_);
lean_ctor_set(v___x_373_, 2, v___x_372_);
return v___x_373_;
}
else
{
lean_object* v___x_374_; lean_object* v___x_375_; 
lean_dec(v_bearing_360_);
v___x_374_ = lean_box(0);
v___x_375_ = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(v___x_375_, 0, v___x_364_);
lean_ctor_set(v___x_375_, 1, v___y_366_);
lean_ctor_set(v___x_375_, 2, v___x_374_);
return v___x_375_;
}
}
}
}
else
{
lean_object* v___x_383_; lean_object* v___x_384_; lean_object* v___x_385_; lean_object* v___x_386_; 
lean_dec(v___x_348_);
v___x_383_ = lean_unsigned_to_nat(31u);
v___x_384_ = lean_unsigned_to_nat(24u);
v___x_385_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_345_, v___x_383_, v___x_384_);
v___x_386_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_386_, 0, v___x_385_);
return v___x_386_;
}
}
else
{
lean_object* v___x_387_; 
lean_dec(v___x_348_);
v___x_387_ = lean_box(0);
return v___x_387_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbThreat___boxed(lean_object* v_word_388_){
_start:
{
lean_object* v_res_389_; 
v_res_389_ = lp_lean1090_Lean1090_Impl_cbThreat(v_word_388_);
lean_dec(v_word_388_);
return v_res_389_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0(void){
_start:
{
lean_object* v___x_390_; lean_object* v___x_391_; 
v___x_390_ = lean_unsigned_to_nat(20u);
v___x_391_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_390_);
return v___x_391_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1(void){
_start:
{
lean_object* v___x_392_; lean_object* v___x_393_; lean_object* v___x_394_; 
v___x_392_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0);
v___x_393_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__0, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__0);
v___x_394_ = l_Rat_div(v___x_393_, v___x_392_);
return v___x_394_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2(void){
_start:
{
lean_object* v___x_395_; lean_object* v___x_396_; 
v___x_395_ = lean_unsigned_to_nat(251u);
v___x_396_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_395_);
return v___x_396_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3(void){
_start:
{
lean_object* v___x_397_; lean_object* v___x_398_; lean_object* v___x_399_; 
v___x_397_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__0);
v___x_398_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__2);
v___x_399_ = l_Rat_div(v___x_398_, v___x_397_);
return v___x_399_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4(void){
_start:
{
lean_object* v___x_400_; lean_object* v___x_401_; 
v___x_400_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__3);
v___x_401_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_401_, 0, v___x_400_);
return v___x_401_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5(void){
_start:
{
lean_object* v___x_402_; lean_object* v___x_403_; 
v___x_402_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1);
v___x_403_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_403_, 0, v___x_402_);
return v___x_403_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange(lean_object* v_code_404_){
_start:
{
lean_object* v___x_405_; uint8_t v___x_406_; 
v___x_405_ = lean_unsigned_to_nat(0u);
v___x_406_ = lean_nat_dec_eq(v_code_404_, v___x_405_);
if (v___x_406_ == 0)
{
lean_object* v___x_407_; uint8_t v___x_408_; 
v___x_407_ = lean_unsigned_to_nat(1u);
v___x_408_ = lean_nat_dec_eq(v_code_404_, v___x_407_);
if (v___x_408_ == 0)
{
lean_object* v___x_409_; uint8_t v___x_410_; 
v___x_409_ = lean_unsigned_to_nat(127u);
v___x_410_ = lean_nat_dec_eq(v_code_404_, v___x_409_);
if (v___x_410_ == 0)
{
lean_object* v___x_411_; lean_object* v___x_412_; lean_object* v___x_413_; lean_object* v___x_414_; lean_object* v___x_415_; lean_object* v___x_416_; 
v___x_411_ = lean_nat_sub(v_code_404_, v___x_407_);
v___x_412_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_411_);
v___x_413_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_414_ = l_Rat_div(v___x_412_, v___x_413_);
lean_dec_ref(v___x_412_);
v___x_415_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__1);
v___x_416_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_416_, 0, v___x_414_);
lean_ctor_set(v___x_416_, 1, v___x_415_);
return v___x_416_;
}
else
{
lean_object* v___x_417_; 
v___x_417_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__4);
return v___x_417_;
}
}
else
{
lean_object* v___x_418_; 
v___x_418_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5, &lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5_once, _init_lp_lean1090_Lean1090_Impl_standardThreatRange___closed__5);
return v___x_418_;
}
}
else
{
lean_object* v___x_419_; 
v___x_419_ = lean_box(0);
return v___x_419_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatRange___boxed(lean_object* v_code_420_){
_start:
{
lean_object* v_res_421_; 
v_res_421_ = lp_lean1090_Lean1090_Impl_standardThreatRange(v_code_420_);
lean_dec(v_code_420_);
return v_res_421_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_standardThreatBearing(lean_object* v_code_422_){
_start:
{
lean_object* v___x_423_; uint8_t v___x_424_; 
v___x_423_ = lean_unsigned_to_nat(0u);
v___x_424_ = lean_nat_dec_eq(v_code_422_, v___x_423_);
if (v___x_424_ == 0)
{
lean_object* v___x_425_; uint8_t v___x_426_; 
v___x_425_ = lean_unsigned_to_nat(60u);
v___x_426_ = lean_nat_dec_le(v_code_422_, v___x_425_);
if (v___x_426_ == 0)
{
lean_object* v___x_427_; 
v___x_427_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_427_, 0, v_code_422_);
return v___x_427_;
}
else
{
lean_object* v___x_428_; lean_object* v___x_429_; lean_object* v___x_430_; lean_object* v___x_431_; lean_object* v___x_432_; lean_object* v___x_433_; 
v___x_428_ = lean_unsigned_to_nat(6u);
v___x_429_ = lean_unsigned_to_nat(1u);
v___x_430_ = lean_nat_sub(v_code_422_, v___x_429_);
v___x_431_ = lean_nat_mul(v___x_428_, v___x_430_);
lean_dec(v___x_430_);
v___x_432_ = lean_nat_mul(v___x_428_, v_code_422_);
lean_dec(v_code_422_);
v___x_433_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_433_, 0, v___x_431_);
lean_ctor_set(v___x_433_, 1, v___x_432_);
return v___x_433_;
}
}
else
{
lean_object* v___x_434_; 
lean_dec(v_code_422_);
v___x_434_ = lean_box(0);
return v___x_434_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat(lean_object* v_word_439_){
_start:
{
lean_object* v___x_440_; uint8_t v___x_441_; 
v___x_440_ = lean_cstr_to_nat("72057594037927936");
v___x_441_ = lean_nat_dec_le(v___x_440_, v_word_439_);
if (v___x_441_ == 0)
{
lean_object* v___x_442_; lean_object* v___x_443_; lean_object* v___x_444_; lean_object* v___x_445_; uint8_t v___x_446_; 
v___x_442_ = lean_unsigned_to_nat(2u);
v___x_443_ = lean_unsigned_to_nat(29u);
v___x_444_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_439_, v___x_443_, v___x_442_);
v___x_445_ = lean_unsigned_to_nat(0u);
v___x_446_ = lean_nat_dec_eq(v___x_444_, v___x_445_);
if (v___x_446_ == 0)
{
lean_object* v___x_447_; uint8_t v___x_448_; 
v___x_447_ = lean_unsigned_to_nat(1u);
v___x_448_ = lean_nat_dec_eq(v___x_444_, v___x_447_);
if (v___x_448_ == 0)
{
uint8_t v___x_449_; 
v___x_449_ = lean_nat_dec_eq(v___x_444_, v___x_442_);
lean_dec(v___x_444_);
if (v___x_449_ == 0)
{
lean_object* v___x_450_; 
v___x_450_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__0));
return v___x_450_;
}
else
{
lean_object* v___x_451_; lean_object* v___x_452_; lean_object* v___x_453_; lean_object* v___x_454_; lean_object* v___x_455_; lean_object* v___x_456_; lean_object* v___x_457_; lean_object* v___x_458_; lean_object* v___x_459_; lean_object* v___x_460_; lean_object* v___x_461_; lean_object* v___x_462_; lean_object* v___x_463_; lean_object* v___x_464_; 
v___x_451_ = lean_unsigned_to_nat(31u);
v___x_452_ = lean_unsigned_to_nat(13u);
v___x_453_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_439_, v___x_451_, v___x_452_);
v___x_454_ = lp_lean1090_Lean1090_Impl_Altitude_decodeGillham(v___x_453_);
lean_dec(v___x_453_);
v___x_455_ = lean_unsigned_to_nat(44u);
v___x_456_ = lean_unsigned_to_nat(7u);
v___x_457_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_439_, v___x_455_, v___x_456_);
v___x_458_ = lp_lean1090_Lean1090_Impl_standardThreatRange(v___x_457_);
lean_dec(v___x_457_);
v___x_459_ = lean_unsigned_to_nat(51u);
v___x_460_ = lean_unsigned_to_nat(6u);
v___x_461_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_439_, v___x_459_, v___x_460_);
v___x_462_ = lp_lean1090_Lean1090_Impl_standardThreatBearing(v___x_461_);
v___x_463_ = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(v___x_463_, 0, v___x_454_);
lean_ctor_set(v___x_463_, 1, v___x_458_);
lean_ctor_set(v___x_463_, 2, v___x_462_);
v___x_464_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_464_, 0, v___x_463_);
return v___x_464_;
}
}
else
{
lean_object* v___x_465_; lean_object* v___x_466_; uint8_t v___x_467_; 
lean_dec(v___x_444_);
v___x_465_ = lean_unsigned_to_nat(55u);
v___x_466_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_439_, v___x_465_, v___x_442_);
v___x_467_ = lean_nat_dec_eq(v___x_466_, v___x_445_);
lean_dec(v___x_466_);
if (v___x_467_ == 0)
{
lean_object* v___x_468_; 
v___x_468_ = lean_box(0);
return v___x_468_;
}
else
{
lean_object* v___x_469_; lean_object* v___x_470_; lean_object* v___x_471_; lean_object* v___x_472_; lean_object* v___x_473_; 
v___x_469_ = lean_unsigned_to_nat(31u);
v___x_470_ = lean_unsigned_to_nat(24u);
v___x_471_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_439_, v___x_469_, v___x_470_);
v___x_472_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_472_, 0, v___x_471_);
v___x_473_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_473_, 0, v___x_472_);
return v___x_473_;
}
}
}
else
{
lean_object* v___x_474_; 
lean_dec(v___x_444_);
v___x_474_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbStandardThreat___closed__1));
return v___x_474_;
}
}
else
{
lean_object* v___x_475_; 
v___x_475_ = lean_box(0);
return v___x_475_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat___boxed(lean_object* v_word_476_){
_start:
{
lean_object* v_res_477_; 
v_res_477_ = lp_lean1090_Lean1090_Impl_cbStandardThreat(v_word_476_);
lean_dec(v_word_476_);
return v_res_477_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbDashPlaceholder(lean_object* v_code_478_){
_start:
{
lean_object* v___x_479_; uint8_t v___x_480_; 
v___x_479_ = lean_unsigned_to_nat(0u);
v___x_480_ = lean_nat_dec_eq(v_code_478_, v___x_479_);
if (v___x_480_ == 0)
{
lean_object* v___x_481_; uint8_t v___x_482_; 
v___x_481_ = lean_unsigned_to_nat(32u);
v___x_482_ = lean_nat_dec_eq(v_code_478_, v___x_481_);
if (v___x_482_ == 0)
{
lean_object* v___x_483_; uint8_t v___x_484_; 
v___x_483_ = lean_unsigned_to_nat(45u);
v___x_484_ = lean_nat_dec_eq(v_code_478_, v___x_483_);
return v___x_484_;
}
else
{
return v___x_482_;
}
}
else
{
return v___x_480_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDashPlaceholder___boxed(lean_object* v_code_485_){
_start:
{
uint8_t v_res_486_; lean_object* v_r_487_; 
v_res_486_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v_code_485_);
lean_dec(v_code_485_);
v_r_487_ = lean_box(v_res_486_);
return v_r_487_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(lean_object* v_word_488_, lean_object* v_a_489_, lean_object* v_a_490_){
_start:
{
if (lean_obj_tag(v_a_489_) == 0)
{
lean_object* v___x_491_; 
v___x_491_ = l_List_reverse___redArg(v_a_490_);
return v___x_491_;
}
else
{
lean_object* v_head_492_; lean_object* v_tail_493_; lean_object* v___x_495_; uint8_t v_isShared_496_; uint8_t v_isSharedCheck_506_; 
v_head_492_ = lean_ctor_get(v_a_489_, 0);
v_tail_493_ = lean_ctor_get(v_a_489_, 1);
v_isSharedCheck_506_ = !lean_is_exclusive(v_a_489_);
if (v_isSharedCheck_506_ == 0)
{
v___x_495_ = v_a_489_;
v_isShared_496_ = v_isSharedCheck_506_;
goto v_resetjp_494_;
}
else
{
lean_inc(v_tail_493_);
lean_inc(v_head_492_);
lean_dec(v_a_489_);
v___x_495_ = lean_box(0);
v_isShared_496_ = v_isSharedCheck_506_;
goto v_resetjp_494_;
}
v_resetjp_494_:
{
lean_object* v___x_497_; lean_object* v___x_498_; lean_object* v___x_499_; lean_object* v___x_500_; lean_object* v___x_501_; lean_object* v___x_503_; 
v___x_497_ = lean_unsigned_to_nat(2u);
v___x_498_ = lean_unsigned_to_nat(6u);
v___x_499_ = lean_nat_mul(v___x_498_, v_head_492_);
lean_dec(v_head_492_);
v___x_500_ = lean_nat_add(v___x_497_, v___x_499_);
lean_dec(v___x_499_);
v___x_501_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_488_, v___x_500_, v___x_498_);
lean_dec(v___x_500_);
if (v_isShared_496_ == 0)
{
lean_ctor_set(v___x_495_, 1, v_a_490_);
lean_ctor_set(v___x_495_, 0, v___x_501_);
v___x_503_ = v___x_495_;
goto v_reusejp_502_;
}
else
{
lean_object* v_reuseFailAlloc_505_; 
v_reuseFailAlloc_505_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_505_, 0, v___x_501_);
lean_ctor_set(v_reuseFailAlloc_505_, 1, v_a_490_);
v___x_503_ = v_reuseFailAlloc_505_;
goto v_reusejp_502_;
}
v_reusejp_502_:
{
v_a_489_ = v_tail_493_;
v_a_490_ = v___x_503_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0___boxed(lean_object* v_word_507_, lean_object* v_a_508_, lean_object* v_a_509_){
_start:
{
lean_object* v_res_510_; 
v_res_510_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(v_word_507_, v_a_508_, v_a_509_);
lean_dec(v_word_507_);
return v_res_510_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__1(lean_object* v_a_511_, lean_object* v_a_512_){
_start:
{
if (lean_obj_tag(v_a_511_) == 0)
{
lean_object* v___x_513_; 
v___x_513_ = l_List_reverse___redArg(v_a_512_);
return v___x_513_;
}
else
{
lean_object* v_head_514_; lean_object* v_tail_515_; lean_object* v___x_517_; uint8_t v_isShared_518_; uint8_t v_isSharedCheck_525_; 
v_head_514_ = lean_ctor_get(v_a_511_, 0);
v_tail_515_ = lean_ctor_get(v_a_511_, 1);
v_isSharedCheck_525_ = !lean_is_exclusive(v_a_511_);
if (v_isSharedCheck_525_ == 0)
{
v___x_517_ = v_a_511_;
v_isShared_518_ = v_isSharedCheck_525_;
goto v_resetjp_516_;
}
else
{
lean_inc(v_tail_515_);
lean_inc(v_head_514_);
lean_dec(v_a_511_);
v___x_517_ = lean_box(0);
v_isShared_518_ = v_isSharedCheck_525_;
goto v_resetjp_516_;
}
v_resetjp_516_:
{
uint8_t v___x_519_; 
v___x_519_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v_head_514_);
if (v___x_519_ == 0)
{
lean_object* v___x_521_; 
if (v_isShared_518_ == 0)
{
lean_ctor_set(v___x_517_, 1, v_a_512_);
v___x_521_ = v___x_517_;
goto v_reusejp_520_;
}
else
{
lean_object* v_reuseFailAlloc_523_; 
v_reuseFailAlloc_523_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_523_, 0, v_head_514_);
lean_ctor_set(v_reuseFailAlloc_523_, 1, v_a_512_);
v___x_521_ = v_reuseFailAlloc_523_;
goto v_reusejp_520_;
}
v_reusejp_520_:
{
v_a_511_ = v_tail_515_;
v_a_512_ = v___x_521_;
goto _start;
}
}
else
{
lean_del_object(v___x_517_);
lean_dec(v_head_514_);
v_a_511_ = v_tail_515_;
goto _start;
}
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0(void){
_start:
{
lean_object* v___x_526_; lean_object* v___x_527_; 
v___x_526_ = lean_unsigned_to_nat(7u);
v___x_527_ = l_List_range(v___x_526_);
return v___x_527_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistrationCodes(lean_object* v_word_528_){
_start:
{
lean_object* v___x_529_; lean_object* v___x_530_; lean_object* v___x_531_; lean_object* v___x_532_; 
v___x_529_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0, &lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRegistrationCodes___closed__0);
v___x_530_ = lean_box(0);
v___x_531_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__0(v_word_528_, v___x_529_, v___x_530_);
v___x_532_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbRegistrationCodes_spec__1(v___x_531_, v___x_530_);
return v___x_532_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistrationCodes___boxed(lean_object* v_word_533_){
_start:
{
lean_object* v_res_534_; 
v_res_534_ = lp_lean1090_Lean1090_Impl_cbRegistrationCodes(v_word_533_);
lean_dec(v_word_533_);
return v_res_534_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistration(lean_object* v_word_535_){
_start:
{
lean_object* v___x_536_; lean_object* v___x_537_; lean_object* v___x_538_; uint8_t v___x_539_; 
v___x_536_ = lean_unsigned_to_nat(1u);
v___x_537_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_535_, v___x_536_, v___x_536_);
v___x_538_ = lean_unsigned_to_nat(0u);
v___x_539_ = lean_nat_dec_eq(v___x_537_, v___x_538_);
lean_dec(v___x_537_);
if (v___x_539_ == 0)
{
lean_object* v___x_540_; lean_object* v___x_541_; lean_object* v___x_542_; lean_object* v___x_543_; lean_object* v___x_544_; 
v___x_540_ = lp_lean1090_Lean1090_Impl_cbRegistrationCodes(v_word_535_);
v___x_541_ = lean_box(0);
v___x_542_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(v___x_540_, v___x_541_);
v___x_543_ = lean_string_mk(v___x_542_);
v___x_544_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_544_, 0, v___x_543_);
return v___x_544_;
}
else
{
lean_object* v___x_545_; 
v___x_545_ = lean_box(0);
return v___x_545_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRegistration___boxed(lean_object* v_word_546_){
_start:
{
lean_object* v_res_547_; 
v_res_547_ = lp_lean1090_Lean1090_Impl_cbRegistration(v_word_546_);
lean_dec(v_word_546_);
return v_res_547_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(lean_object* v_word_548_, lean_object* v_x_549_){
_start:
{
if (lean_obj_tag(v_x_549_) == 0)
{
uint8_t v___x_550_; 
v___x_550_ = 1;
return v___x_550_;
}
else
{
lean_object* v_head_551_; lean_object* v_tail_552_; lean_object* v___x_553_; lean_object* v___x_554_; lean_object* v___x_555_; uint8_t v___x_556_; 
v_head_551_ = lean_ctor_get(v_x_549_, 0);
v_tail_552_ = lean_ctor_get(v_x_549_, 1);
v___x_553_ = lean_unsigned_to_nat(1u);
v___x_554_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_548_, v_head_551_, v___x_553_);
v___x_555_ = lean_unsigned_to_nat(0u);
v___x_556_ = lean_nat_dec_eq(v___x_554_, v___x_555_);
lean_dec(v___x_554_);
if (v___x_556_ == 0)
{
return v___x_556_;
}
else
{
v_x_549_ = v_tail_552_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0___boxed(lean_object* v_word_558_, lean_object* v_x_559_){
_start:
{
uint8_t v_res_560_; lean_object* v_r_561_; 
v_res_560_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(v_word_558_, v_x_559_);
lean_dec(v_x_559_);
lean_dec(v_word_558_);
v_r_561_ = lean_box(v_res_560_);
return v_r_561_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid17(lean_object* v_word_583_){
_start:
{
lean_object* v___x_584_; lean_object* v___x_585_; lean_object* v___x_586_; uint8_t v___x_587_; 
v___x_584_ = lean_unsigned_to_nat(7u);
v___x_585_ = lean_unsigned_to_nat(1u);
v___x_586_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_583_, v___x_584_, v___x_585_);
v___x_587_ = lean_nat_dec_eq(v___x_586_, v___x_585_);
lean_dec(v___x_586_);
if (v___x_587_ == 0)
{
return v___x_587_;
}
else
{
lean_object* v___x_588_; lean_object* v___x_589_; lean_object* v___x_590_; lean_object* v___x_591_; uint8_t v___x_592_; 
v___x_588_ = lean_unsigned_to_nat(30u);
v___x_589_ = lean_unsigned_to_nat(27u);
v___x_590_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_583_, v___x_588_, v___x_589_);
v___x_591_ = lean_unsigned_to_nat(0u);
v___x_592_ = lean_nat_dec_eq(v___x_590_, v___x_591_);
lean_dec(v___x_590_);
if (v___x_592_ == 0)
{
return v___x_592_;
}
else
{
lean_object* v___x_593_; uint8_t v___x_594_; 
v___x_593_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbValid17___closed__6));
v___x_594_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid17_spec__0(v_word_583_, v___x_593_);
return v___x_594_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid17___boxed(lean_object* v_word_595_){
_start:
{
uint8_t v_res_596_; lean_object* v_r_597_; 
v_res_596_ = lp_lean1090_Lean1090_Impl_cbValid17(v_word_595_);
lean_dec(v_word_595_);
v_r_597_ = lean_box(v_res_596_);
return v_r_597_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(lean_object* v_word_661_, lean_object* v_x_662_){
_start:
{
if (lean_obj_tag(v_x_662_) == 0)
{
uint8_t v___x_663_; 
v___x_663_ = 1;
return v___x_663_;
}
else
{
lean_object* v_head_664_; lean_object* v_tail_665_; uint8_t v___y_667_; lean_object* v___x_669_; lean_object* v_allowed_670_; lean_object* v___x_671_; uint8_t v___x_672_; 
v_head_664_ = lean_ctor_get(v_x_662_, 0);
v_tail_665_ = lean_ctor_get(v_x_662_, 1);
v___x_669_ = lean_unsigned_to_nat(56u);
v_allowed_670_ = ((lean_object*)(lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___closed__20));
v___x_671_ = lean_nat_sub(v___x_669_, v_head_664_);
v___x_672_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v___x_671_, v_allowed_670_);
lean_dec(v___x_671_);
if (v___x_672_ == 0)
{
lean_object* v___x_673_; lean_object* v___x_674_; lean_object* v___x_675_; lean_object* v___x_676_; uint8_t v___x_677_; 
v___x_673_ = lean_unsigned_to_nat(1u);
v___x_674_ = lean_nat_add(v_head_664_, v___x_673_);
v___x_675_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_661_, v___x_674_, v___x_673_);
lean_dec(v___x_674_);
v___x_676_ = lean_unsigned_to_nat(0u);
v___x_677_ = lean_nat_dec_eq(v___x_675_, v___x_676_);
lean_dec(v___x_675_);
v___y_667_ = v___x_677_;
goto v___jp_666_;
}
else
{
v___y_667_ = v___x_672_;
goto v___jp_666_;
}
v___jp_666_:
{
if (v___y_667_ == 0)
{
return v___y_667_;
}
else
{
v_x_662_ = v_tail_665_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0___boxed(lean_object* v_word_678_, lean_object* v_x_679_){
_start:
{
uint8_t v_res_680_; lean_object* v_r_681_; 
v_res_680_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(v_word_678_, v_x_679_);
lean_dec(v_x_679_);
lean_dec(v_word_678_);
v_r_681_ = lean_box(v_res_680_);
return v_r_681_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(lean_object* v_word_682_, lean_object* v_x_683_){
_start:
{
if (lean_obj_tag(v_x_683_) == 0)
{
uint8_t v___x_684_; 
v___x_684_ = 1;
return v___x_684_;
}
else
{
lean_object* v_head_685_; lean_object* v_tail_686_; lean_object* v___x_687_; lean_object* v___x_688_; lean_object* v___x_689_; lean_object* v___x_690_; uint8_t v___x_691_; 
v_head_685_ = lean_ctor_get(v_x_683_, 0);
v_tail_686_ = lean_ctor_get(v_x_683_, 1);
v___x_687_ = lean_unsigned_to_nat(57u);
v___x_688_ = lean_nat_sub(v___x_687_, v_head_685_);
v___x_689_ = lean_unsigned_to_nat(1u);
v___x_690_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_682_, v___x_688_, v___x_689_);
lean_dec(v___x_688_);
v___x_691_ = lean_nat_dec_eq(v___x_690_, v___x_689_);
lean_dec(v___x_690_);
if (v___x_691_ == 0)
{
return v___x_691_;
}
else
{
v_x_683_ = v_tail_686_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1___boxed(lean_object* v_word_693_, lean_object* v_x_694_){
_start:
{
uint8_t v_res_695_; lean_object* v_r_696_; 
v_res_695_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(v_word_693_, v_x_694_);
lean_dec(v_x_694_);
lean_dec(v_word_693_);
v_r_696_ = lean_box(v_res_695_);
return v_r_696_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid18___closed__0(void){
_start:
{
lean_object* v___x_697_; lean_object* v___x_698_; 
v___x_697_ = lean_unsigned_to_nat(56u);
v___x_698_ = l_List_range(v___x_697_);
return v___x_698_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid18(lean_object* v_word_711_){
_start:
{
lean_object* v___x_712_; uint8_t v___x_713_; 
v___x_712_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid18___closed__0, &lp_lean1090_Lean1090_Impl_cbValid18___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid18___closed__0);
v___x_713_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__0(v_word_711_, v___x_712_);
if (v___x_713_ == 0)
{
return v___x_713_;
}
else
{
lean_object* v___x_714_; uint8_t v___x_715_; 
v___x_714_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbValid18___closed__4));
v___x_715_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid18_spec__1(v_word_711_, v___x_714_);
return v___x_715_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid18___boxed(lean_object* v_word_716_){
_start:
{
uint8_t v_res_717_; lean_object* v_r_718_; 
v_res_717_ = lp_lean1090_Lean1090_Impl_cbValid18(v_word_716_);
lean_dec(v_word_716_);
v_r_718_ = lean_box(v_res_717_);
return v_r_718_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(lean_object* v_word_755_, lean_object* v_x_756_){
_start:
{
if (lean_obj_tag(v_x_756_) == 0)
{
uint8_t v___x_757_; 
v___x_757_ = 1;
return v___x_757_;
}
else
{
lean_object* v_head_758_; lean_object* v_tail_759_; uint8_t v___y_761_; lean_object* v_allowed_763_; lean_object* v___x_764_; lean_object* v___x_765_; uint8_t v___x_766_; 
v_head_758_ = lean_ctor_get(v_x_756_, 0);
v_tail_759_ = lean_ctor_get(v_x_756_, 1);
v_allowed_763_ = ((lean_object*)(lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___closed__11));
v___x_764_ = lean_unsigned_to_nat(112u);
v___x_765_ = lean_nat_sub(v___x_764_, v_head_758_);
v___x_766_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v___x_765_, v_allowed_763_);
lean_dec(v___x_765_);
if (v___x_766_ == 0)
{
lean_object* v___x_767_; lean_object* v___x_768_; lean_object* v___x_769_; lean_object* v___x_770_; uint8_t v___x_771_; 
v___x_767_ = lean_unsigned_to_nat(1u);
v___x_768_ = lean_nat_add(v_head_758_, v___x_767_);
v___x_769_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_755_, v___x_768_, v___x_767_);
lean_dec(v___x_768_);
v___x_770_ = lean_unsigned_to_nat(0u);
v___x_771_ = lean_nat_dec_eq(v___x_769_, v___x_770_);
lean_dec(v___x_769_);
v___y_761_ = v___x_771_;
goto v___jp_760_;
}
else
{
v___y_761_ = v___x_766_;
goto v___jp_760_;
}
v___jp_760_:
{
if (v___y_761_ == 0)
{
return v___y_761_;
}
else
{
v_x_756_ = v_tail_759_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0___boxed(lean_object* v_word_772_, lean_object* v_x_773_){
_start:
{
uint8_t v_res_774_; lean_object* v_r_775_; 
v_res_774_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(v_word_772_, v_x_773_);
lean_dec(v_x_773_);
lean_dec(v_word_772_);
v_r_775_ = lean_box(v_res_774_);
return v_r_775_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid19(lean_object* v_word_776_){
_start:
{
lean_object* v___x_777_; uint8_t v___x_778_; 
v___x_777_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid18___closed__0, &lp_lean1090_Lean1090_Impl_cbValid18___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid18___closed__0);
v___x_778_ = lp_lean1090_List_all___at___00Lean1090_Impl_cbValid19_spec__0(v_word_776_, v___x_777_);
return v___x_778_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid19___boxed(lean_object* v_word_779_){
_start:
{
uint8_t v_res_780_; lean_object* v_r_781_; 
v_res_780_ = lp_lean1090_Lean1090_Impl_cbValid19(v_word_779_);
lean_dec(v_word_779_);
v_r_781_ = lean_box(v_res_780_);
return v_r_781_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbValid21_spec__0(lean_object* v_a_782_, lean_object* v_a_783_){
_start:
{
if (lean_obj_tag(v_a_782_) == 0)
{
lean_object* v___x_784_; 
v___x_784_ = l_List_reverse___redArg(v_a_783_);
return v___x_784_;
}
else
{
lean_object* v_head_785_; lean_object* v_tail_786_; lean_object* v___x_788_; uint8_t v_isShared_789_; uint8_t v_isSharedCheck_798_; 
v_head_785_ = lean_ctor_get(v_a_782_, 0);
v_tail_786_ = lean_ctor_get(v_a_782_, 1);
v_isSharedCheck_798_ = !lean_is_exclusive(v_a_782_);
if (v_isSharedCheck_798_ == 0)
{
v___x_788_ = v_a_782_;
v_isShared_789_ = v_isSharedCheck_798_;
goto v_resetjp_787_;
}
else
{
lean_inc(v_tail_786_);
lean_inc(v_head_785_);
lean_dec(v_a_782_);
v___x_788_ = lean_box(0);
v_isShared_789_ = v_isSharedCheck_798_;
goto v_resetjp_787_;
}
v_resetjp_787_:
{
uint32_t v___x_790_; uint32_t v___x_791_; uint8_t v___x_792_; 
v___x_790_ = lp_lean1090_Lean1090_Impl_cbCharacter(v_head_785_);
v___x_791_ = 35;
v___x_792_ = lean_uint32_dec_eq(v___x_790_, v___x_791_);
if (v___x_792_ == 0)
{
lean_del_object(v___x_788_);
lean_dec(v_head_785_);
v_a_782_ = v_tail_786_;
goto _start;
}
else
{
lean_object* v___x_795_; 
if (v_isShared_789_ == 0)
{
lean_ctor_set(v___x_788_, 1, v_a_783_);
v___x_795_ = v___x_788_;
goto v_reusejp_794_;
}
else
{
lean_object* v_reuseFailAlloc_797_; 
v_reuseFailAlloc_797_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_797_, 0, v_head_785_);
lean_ctor_set(v_reuseFailAlloc_797_, 1, v_a_783_);
v___x_795_ = v_reuseFailAlloc_797_;
goto v_reusejp_794_;
}
v_reusejp_794_:
{
v_a_782_ = v_tail_786_;
v_a_783_ = v___x_795_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid21(lean_object* v_word_799_){
_start:
{
uint8_t v___y_801_; lean_object* v_codes_814_; lean_object* v___x_815_; lean_object* v___x_816_; lean_object* v___x_817_; uint8_t v___x_818_; 
v_codes_814_ = lp_lean1090_Lean1090_Impl_cbRegistrationCodes(v_word_799_);
v___x_815_ = lean_unsigned_to_nat(1u);
v___x_816_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_799_, v___x_815_, v___x_815_);
v___x_817_ = lean_unsigned_to_nat(0u);
v___x_818_ = lean_nat_dec_eq(v___x_816_, v___x_817_);
lean_dec(v___x_816_);
if (v___x_818_ == 0)
{
lean_object* v___x_819_; lean_object* v___x_820_; lean_object* v___x_821_; lean_object* v___x_822_; uint8_t v___x_823_; 
v___x_819_ = lean_box(0);
v___x_820_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_cbValid21_spec__0(v_codes_814_, v___x_819_);
v___x_821_ = l_List_lengthTR___redArg(v___x_820_);
lean_dec(v___x_820_);
v___x_822_ = lean_unsigned_to_nat(2u);
v___x_823_ = lean_nat_dec_le(v___x_821_, v___x_822_);
lean_dec(v___x_821_);
v___y_801_ = v___x_823_;
goto v___jp_800_;
}
else
{
uint8_t v___x_824_; 
v___x_824_ = l_List_isEmpty___redArg(v_codes_814_);
lean_dec(v_codes_814_);
v___y_801_ = v___x_824_;
goto v___jp_800_;
}
v___jp_800_:
{
if (v___y_801_ == 0)
{
return v___y_801_;
}
else
{
lean_object* v___x_802_; lean_object* v___x_803_; lean_object* v___x_804_; lean_object* v___x_805_; uint8_t v___x_806_; 
v___x_802_ = lean_unsigned_to_nat(44u);
v___x_803_ = lean_unsigned_to_nat(1u);
v___x_804_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_799_, v___x_802_, v___x_803_);
v___x_805_ = lean_unsigned_to_nat(0u);
v___x_806_ = lean_nat_dec_eq(v___x_804_, v___x_805_);
lean_dec(v___x_804_);
if (v___x_806_ == 0)
{
return v___x_806_;
}
else
{
lean_object* v___x_807_; lean_object* v___x_808_; lean_object* v___x_809_; uint8_t v___x_810_; 
v___x_807_ = lean_unsigned_to_nat(45u);
v___x_808_ = lean_unsigned_to_nat(6u);
v___x_809_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_799_, v___x_807_, v___x_808_);
v___x_810_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v___x_809_);
lean_dec(v___x_809_);
if (v___x_810_ == 0)
{
return v___x_810_;
}
else
{
lean_object* v___x_811_; lean_object* v___x_812_; uint8_t v___x_813_; 
v___x_811_ = lean_unsigned_to_nat(51u);
v___x_812_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_799_, v___x_811_, v___x_808_);
v___x_813_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v___x_812_);
lean_dec(v___x_812_);
return v___x_813_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid21___boxed(lean_object* v_word_825_){
_start:
{
uint8_t v_res_826_; lean_object* v_r_827_; 
v_res_826_ = lp_lean1090_Lean1090_Impl_cbValid21(v_word_825_);
lean_dec(v_word_825_);
v_r_827_ = lean_box(v_res_826_);
return v_r_827_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid40___closed__0(void){
_start:
{
lean_object* v___x_828_; lean_object* v___x_829_; 
v___x_828_ = lean_unsigned_to_nat(50000u);
v___x_829_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_828_);
return v___x_829_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid40___closed__1(void){
_start:
{
lean_object* v___x_830_; lean_object* v___x_831_; 
v___x_830_ = lean_unsigned_to_nat(1200u);
v___x_831_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_830_);
return v___x_831_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid40(lean_object* v_word_832_){
_start:
{
uint8_t v___y_834_; lean_object* v___x_861_; lean_object* v___x_862_; lean_object* v___x_863_; uint8_t v___x_864_; 
v___x_861_ = lean_unsigned_to_nat(1u);
v___x_862_ = lean_unsigned_to_nat(2u);
v___x_863_ = lean_unsigned_to_nat(12u);
v___x_864_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_832_, v___x_861_, v___x_862_, v___x_863_);
if (v___x_864_ == 0)
{
v___y_834_ = v___x_864_;
goto v___jp_833_;
}
else
{
lean_object* v___x_865_; lean_object* v___x_866_; uint8_t v___x_867_; 
v___x_865_ = lean_unsigned_to_nat(14u);
v___x_866_ = lean_unsigned_to_nat(15u);
v___x_867_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_832_, v___x_865_, v___x_866_, v___x_863_);
v___y_834_ = v___x_867_;
goto v___jp_833_;
}
v___jp_833_:
{
if (v___y_834_ == 0)
{
return v___y_834_;
}
else
{
lean_object* v___x_835_; lean_object* v___x_836_; lean_object* v___x_837_; uint8_t v___x_838_; 
v___x_835_ = lean_unsigned_to_nat(27u);
v___x_836_ = lean_unsigned_to_nat(28u);
v___x_837_ = lean_unsigned_to_nat(12u);
v___x_838_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_832_, v___x_835_, v___x_836_, v___x_837_);
if (v___x_838_ == 0)
{
return v___x_838_;
}
else
{
lean_object* v___x_839_; lean_object* v___x_840_; lean_object* v___x_841_; lean_object* v___x_842_; uint8_t v___x_843_; 
v___x_839_ = lean_unsigned_to_nat(40u);
v___x_840_ = lean_unsigned_to_nat(8u);
v___x_841_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_832_, v___x_839_, v___x_840_);
v___x_842_ = lean_unsigned_to_nat(0u);
v___x_843_ = lean_nat_dec_eq(v___x_841_, v___x_842_);
lean_dec(v___x_841_);
if (v___x_843_ == 0)
{
return v___x_843_;
}
else
{
lean_object* v___x_844_; lean_object* v___x_845_; lean_object* v___x_846_; uint8_t v___x_847_; 
v___x_844_ = lean_unsigned_to_nat(52u);
v___x_845_ = lean_unsigned_to_nat(2u);
v___x_846_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_832_, v___x_844_, v___x_845_);
v___x_847_ = lean_nat_dec_eq(v___x_846_, v___x_842_);
lean_dec(v___x_846_);
if (v___x_847_ == 0)
{
return v___x_847_;
}
else
{
lean_object* v___x_848_; lean_object* v___x_849_; lean_object* v___x_850_; uint8_t v___x_851_; 
v___x_848_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_832_, v___x_845_, v___x_837_);
v___x_849_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_848_);
lean_dec(v___x_848_);
v___x_850_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid40___closed__0, &lp_lean1090_Lean1090_Impl_cbValid40___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid40___closed__0);
v___x_851_ = l_Rat_instDecidableLe(v___x_849_, v___x_850_);
if (v___x_851_ == 0)
{
return v___x_851_;
}
else
{
lean_object* v___x_852_; lean_object* v___x_853_; lean_object* v___x_854_; uint8_t v___x_855_; 
v___x_852_ = lean_unsigned_to_nat(15u);
v___x_853_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_832_, v___x_852_, v___x_837_);
v___x_854_ = lp_lean1090_Lean1090_Impl_cbSelected(v___x_853_);
lean_dec(v___x_853_);
v___x_855_ = l_Rat_instDecidableLe(v___x_854_, v___x_850_);
if (v___x_855_ == 0)
{
return v___x_855_;
}
else
{
lean_object* v___x_856_; lean_object* v___x_857_; uint8_t v___x_858_; 
v___x_856_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__4, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__4);
v___x_857_ = lp_lean1090_Lean1090_Impl_cbQNH64(v_word_832_);
lean_inc_ref(v___x_857_);
v___x_858_ = l_Rat_instDecidableLe(v___x_856_, v___x_857_);
if (v___x_858_ == 0)
{
lean_dec_ref(v___x_857_);
return v___x_858_;
}
else
{
lean_object* v___x_859_; uint8_t v___x_860_; 
v___x_859_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid40___closed__1, &lp_lean1090_Lean1090_Impl_cbValid40___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbValid40___closed__1);
v___x_860_ = l_Rat_instDecidableLe(v___x_857_, v___x_859_);
return v___x_860_;
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid40___boxed(lean_object* v_word_868_){
_start:
{
uint8_t v_res_869_; lean_object* v_r_870_; 
v_res_869_ = lp_lean1090_Lean1090_Impl_cbValid40(v_word_868_);
lean_dec(v_word_868_);
v_r_870_ = lean_box(v_res_869_);
return v_r_870_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0(void){
_start:
{
lean_object* v___x_871_; lean_object* v___x_872_; 
v___x_871_ = lean_unsigned_to_nat(60u);
v___x_872_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_871_);
return v___x_872_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid44(lean_object* v_word_873_){
_start:
{
lean_object* v___x_897_; lean_object* v___x_898_; lean_object* v___x_899_; uint8_t v___x_900_; 
v___x_897_ = lean_unsigned_to_nat(1u);
v___x_898_ = lean_unsigned_to_nat(4u);
v___x_899_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_873_, v___x_897_, v___x_898_);
v___x_900_ = lean_nat_dec_eq(v___x_899_, v___x_897_);
if (v___x_900_ == 0)
{
lean_object* v___x_901_; uint8_t v___x_902_; 
v___x_901_ = lean_unsigned_to_nat(2u);
v___x_902_ = lean_nat_dec_eq(v___x_899_, v___x_901_);
lean_dec(v___x_899_);
if (v___x_902_ == 0)
{
return v___x_902_;
}
else
{
goto v___jp_874_;
}
}
else
{
lean_dec(v___x_899_);
goto v___jp_874_;
}
v___jp_874_:
{
lean_object* v___x_875_; lean_object* v___x_876_; lean_object* v___x_877_; uint8_t v___x_878_; 
v___x_875_ = lean_unsigned_to_nat(5u);
v___x_876_ = lean_unsigned_to_nat(6u);
v___x_877_ = lean_unsigned_to_nat(18u);
v___x_878_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_873_, v___x_875_, v___x_876_, v___x_877_);
if (v___x_878_ == 0)
{
return v___x_878_;
}
else
{
lean_object* v___x_879_; lean_object* v___x_880_; lean_object* v___x_881_; uint8_t v___x_882_; 
v___x_879_ = lean_unsigned_to_nat(9u);
v___x_880_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_873_, v___x_876_, v___x_879_);
v___x_881_ = lean_unsigned_to_nat(250u);
v___x_882_ = lean_nat_dec_le(v___x_880_, v___x_881_);
lean_dec(v___x_880_);
if (v___x_882_ == 0)
{
return v___x_882_;
}
else
{
lean_object* v___x_883_; lean_object* v___x_884_; uint8_t v___x_885_; 
v___x_883_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
v___x_884_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_873_);
lean_inc_ref(v___x_884_);
v___x_885_ = l_Rat_instDecidableLe(v___x_883_, v___x_884_);
if (v___x_885_ == 0)
{
lean_dec_ref(v___x_884_);
return v___x_885_;
}
else
{
lean_object* v___x_886_; uint8_t v___x_887_; 
v___x_886_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid44___closed__0, &lp_lean1090_Lean1090_Impl_cbValid44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0);
v___x_887_ = l_Rat_instDecidableLe(v___x_884_, v___x_886_);
if (v___x_887_ == 0)
{
return v___x_887_;
}
else
{
lean_object* v___x_888_; lean_object* v___x_889_; lean_object* v___x_890_; uint8_t v___x_891_; 
v___x_888_ = lean_unsigned_to_nat(35u);
v___x_889_ = lean_unsigned_to_nat(36u);
v___x_890_ = lean_unsigned_to_nat(11u);
v___x_891_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_873_, v___x_888_, v___x_889_, v___x_890_);
if (v___x_891_ == 0)
{
return v___x_891_;
}
else
{
lean_object* v___x_892_; lean_object* v___x_893_; lean_object* v___x_894_; lean_object* v___x_895_; uint8_t v___x_896_; 
v___x_892_ = lean_unsigned_to_nat(47u);
v___x_893_ = lean_unsigned_to_nat(10u);
v___x_894_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_873_, v___x_892_, v___x_893_);
v___x_895_ = lean_unsigned_to_nat(0u);
v___x_896_ = lean_nat_dec_eq(v___x_894_, v___x_895_);
lean_dec(v___x_894_);
return v___x_896_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid44___boxed(lean_object* v_word_903_){
_start:
{
uint8_t v_res_904_; lean_object* v_r_905_; 
v_res_904_ = lp_lean1090_Lean1090_Impl_cbValid44(v_word_903_);
lean_dec(v_word_903_);
v_r_905_ = lean_box(v_res_904_);
return v_r_905_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid45(lean_object* v_word_906_){
_start:
{
uint8_t v___y_908_; lean_object* v___x_917_; lean_object* v___x_918_; lean_object* v___x_919_; lean_object* v___x_920_; uint8_t v___x_921_; 
v___x_917_ = lean_unsigned_to_nat(1u);
v___x_918_ = lean_unsigned_to_nat(15u);
v___x_919_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_906_, v___x_917_, v___x_918_);
v___x_920_ = lean_unsigned_to_nat(0u);
v___x_921_ = lean_nat_dec_eq(v___x_919_, v___x_920_);
lean_dec(v___x_919_);
if (v___x_921_ == 0)
{
return v___x_921_;
}
else
{
lean_object* v___x_922_; lean_object* v___x_923_; lean_object* v___x_924_; uint8_t v___x_925_; 
v___x_922_ = lean_unsigned_to_nat(52u);
v___x_923_ = lean_unsigned_to_nat(5u);
v___x_924_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_906_, v___x_922_, v___x_923_);
v___x_925_ = lean_nat_dec_eq(v___x_924_, v___x_920_);
lean_dec(v___x_924_);
if (v___x_925_ == 0)
{
return v___x_925_;
}
else
{
lean_object* v___x_926_; lean_object* v___x_927_; uint8_t v___x_928_; 
v___x_926_ = lean_unsigned_to_nat(16u);
v___x_927_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_906_, v___x_926_, v___x_917_);
v___x_928_ = lean_nat_dec_eq(v___x_927_, v___x_920_);
lean_dec(v___x_927_);
if (v___x_928_ == 0)
{
lean_object* v___x_929_; lean_object* v___x_930_; lean_object* v___x_931_; lean_object* v___x_932_; lean_object* v___x_933_; lean_object* v___x_934_; uint8_t v___x_935_; 
v___x_929_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
v___x_930_ = lean_unsigned_to_nat(17u);
v___x_931_ = lean_unsigned_to_nat(10u);
v___x_932_ = lp_lean1090_Lean1090_Impl_cbSigned(v_word_906_, v___x_930_, v___x_931_);
v___x_933_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v___x_934_ = l_Rat_div(v___x_932_, v___x_933_);
lean_dec_ref(v___x_932_);
lean_inc_ref(v___x_934_);
v___x_935_ = l_Rat_instDecidableLe(v___x_929_, v___x_934_);
if (v___x_935_ == 0)
{
lean_dec_ref(v___x_934_);
return v___x_935_;
}
else
{
lean_object* v___x_936_; uint8_t v___x_937_; 
v___x_936_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid44___closed__0, &lp_lean1090_Lean1090_Impl_cbValid44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid44___closed__0);
v___x_937_ = l_Rat_instDecidableLe(v___x_934_, v___x_936_);
v___y_908_ = v___x_937_;
goto v___jp_907_;
}
}
else
{
lean_object* v___x_938_; lean_object* v___x_939_; lean_object* v___x_940_; uint8_t v___x_941_; 
v___x_938_ = lean_unsigned_to_nat(18u);
v___x_939_ = lean_unsigned_to_nat(9u);
v___x_940_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_906_, v___x_938_, v___x_939_);
v___x_941_ = lean_nat_dec_eq(v___x_940_, v___x_920_);
lean_dec(v___x_940_);
v___y_908_ = v___x_941_;
goto v___jp_907_;
}
}
}
v___jp_907_:
{
if (v___y_908_ == 0)
{
return v___y_908_;
}
else
{
lean_object* v___x_909_; lean_object* v___x_910_; lean_object* v___x_911_; uint8_t v___x_912_; 
v___x_909_ = lean_unsigned_to_nat(27u);
v___x_910_ = lean_unsigned_to_nat(28u);
v___x_911_ = lean_unsigned_to_nat(11u);
v___x_912_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_906_, v___x_909_, v___x_910_, v___x_911_);
if (v___x_912_ == 0)
{
return v___x_912_;
}
else
{
lean_object* v___x_913_; lean_object* v___x_914_; lean_object* v___x_915_; uint8_t v___x_916_; 
v___x_913_ = lean_unsigned_to_nat(39u);
v___x_914_ = lean_unsigned_to_nat(40u);
v___x_915_ = lean_unsigned_to_nat(12u);
v___x_916_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_906_, v___x_913_, v___x_914_, v___x_915_);
return v___x_916_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid45___boxed(lean_object* v_word_942_){
_start:
{
uint8_t v_res_943_; lean_object* v_r_944_; 
v_res_943_ = lp_lean1090_Lean1090_Impl_cbValid45(v_word_942_);
lean_dec(v_word_942_);
v_r_944_ = lean_box(v_res_943_);
return v_r_944_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid50___closed__0(void){
_start:
{
lean_object* v___x_945_; lean_object* v___x_946_; 
v___x_945_ = lean_unsigned_to_nat(45u);
v___x_946_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_945_);
return v___x_946_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid50(lean_object* v_word_947_){
_start:
{
uint8_t v___y_949_; lean_object* v___x_982_; lean_object* v___x_983_; lean_object* v___x_984_; uint8_t v___x_985_; 
v___x_982_ = lean_unsigned_to_nat(1u);
v___x_983_ = lean_unsigned_to_nat(2u);
v___x_984_ = lean_unsigned_to_nat(10u);
v___x_985_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_947_, v___x_982_, v___x_983_, v___x_984_);
if (v___x_985_ == 0)
{
v___y_949_ = v___x_985_;
goto v___jp_948_;
}
else
{
lean_object* v___x_986_; lean_object* v___x_987_; lean_object* v___x_988_; uint8_t v___x_989_; 
v___x_986_ = lean_unsigned_to_nat(12u);
v___x_987_ = lean_unsigned_to_nat(13u);
v___x_988_ = lean_unsigned_to_nat(11u);
v___x_989_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_947_, v___x_986_, v___x_987_, v___x_988_);
v___y_949_ = v___x_989_;
goto v___jp_948_;
}
v___jp_948_:
{
if (v___y_949_ == 0)
{
return v___y_949_;
}
else
{
lean_object* v___x_950_; lean_object* v___x_951_; lean_object* v___x_952_; uint8_t v___x_953_; 
v___x_950_ = lean_unsigned_to_nat(24u);
v___x_951_ = lean_unsigned_to_nat(25u);
v___x_952_ = lean_unsigned_to_nat(10u);
v___x_953_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_947_, v___x_950_, v___x_951_, v___x_952_);
if (v___x_953_ == 0)
{
return v___x_953_;
}
else
{
lean_object* v___x_954_; lean_object* v___x_955_; uint8_t v___x_956_; 
v___x_954_ = lean_unsigned_to_nat(35u);
v___x_955_ = lean_unsigned_to_nat(36u);
v___x_956_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_947_, v___x_954_, v___x_955_, v___x_952_);
if (v___x_956_ == 0)
{
return v___x_956_;
}
else
{
lean_object* v___x_957_; lean_object* v___x_958_; uint8_t v___x_959_; 
v___x_957_ = lean_unsigned_to_nat(46u);
v___x_958_ = lean_unsigned_to_nat(47u);
v___x_959_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_947_, v___x_957_, v___x_958_, v___x_952_);
if (v___x_959_ == 0)
{
return v___x_959_;
}
else
{
lean_object* v___x_960_; lean_object* v___x_961_; lean_object* v___x_962_; lean_object* v___x_963_; lean_object* v___x_964_; lean_object* v___x_965_; lean_object* v___x_966_; uint8_t v___x_967_; 
v___x_960_ = lean_unsigned_to_nat(2u);
v___x_961_ = lp_lean1090_Lean1090_Impl_cbSigned(v_word_947_, v___x_960_, v___x_952_);
v___x_962_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid50___closed__0, &lp_lean1090_Lean1090_Impl_cbValid50___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid50___closed__0);
v___x_963_ = l_Rat_mul(v___x_961_, v___x_962_);
lean_dec_ref(v___x_961_);
v___x_964_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_965_ = l_Rat_div(v___x_963_, v___x_964_);
lean_dec_ref(v___x_963_);
v___x_966_ = l_Rat_abs(v___x_965_);
v___x_967_ = l_Rat_instDecidableLe(v___x_966_, v___x_962_);
if (v___x_967_ == 0)
{
return v___x_967_;
}
else
{
lean_object* v___x_968_; lean_object* v___x_969_; lean_object* v___x_970_; uint8_t v___x_971_; 
v___x_968_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_947_, v___x_951_, v___x_952_);
v___x_969_ = lean_nat_mul(v___x_968_, v___x_960_);
lean_dec(v___x_968_);
v___x_970_ = lean_unsigned_to_nat(700u);
v___x_971_ = lean_nat_dec_le(v___x_969_, v___x_970_);
lean_dec(v___x_969_);
if (v___x_971_ == 0)
{
return v___x_971_;
}
else
{
lean_object* v___x_972_; lean_object* v___x_973_; lean_object* v___x_974_; uint8_t v___x_975_; 
v___x_972_ = lean_unsigned_to_nat(1u);
v___x_973_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_947_, v___x_957_, v___x_972_);
v___x_974_ = lean_unsigned_to_nat(0u);
v___x_975_ = lean_nat_dec_eq(v___x_973_, v___x_974_);
lean_dec(v___x_973_);
if (v___x_975_ == 0)
{
lean_object* v___x_976_; lean_object* v___x_977_; lean_object* v___x_978_; uint8_t v___x_979_; 
v___x_976_ = lean_unsigned_to_nat(80u);
v___x_977_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_947_, v___x_958_, v___x_952_);
v___x_978_ = lean_nat_mul(v___x_977_, v___x_960_);
lean_dec(v___x_977_);
v___x_979_ = lean_nat_dec_le(v___x_976_, v___x_978_);
if (v___x_979_ == 0)
{
lean_dec(v___x_978_);
return v___x_979_;
}
else
{
lean_object* v___x_980_; uint8_t v___x_981_; 
v___x_980_ = lean_unsigned_to_nat(600u);
v___x_981_ = lean_nat_dec_le(v___x_978_, v___x_980_);
lean_dec(v___x_978_);
return v___x_981_;
}
}
else
{
return v___x_975_;
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid50___boxed(lean_object* v_word_990_){
_start:
{
uint8_t v_res_991_; lean_object* v_r_992_; 
v_res_991_ = lp_lean1090_Lean1090_Impl_cbValid50(v_word_990_);
lean_dec(v_word_990_);
v_r_992_ = lean_box(v_res_991_);
return v_r_992_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbValid60___closed__0(void){
_start:
{
lean_object* v___x_993_; lean_object* v___x_994_; 
v___x_993_ = lean_unsigned_to_nat(6000u);
v___x_994_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_993_);
return v___x_994_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbValid60(lean_object* v_word_995_){
_start:
{
uint8_t v___y_997_; lean_object* v___x_1019_; lean_object* v___x_1020_; lean_object* v___x_1021_; uint8_t v___x_1022_; 
v___x_1019_ = lean_unsigned_to_nat(1u);
v___x_1020_ = lean_unsigned_to_nat(2u);
v___x_1021_ = lean_unsigned_to_nat(11u);
v___x_1022_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_995_, v___x_1019_, v___x_1020_, v___x_1021_);
if (v___x_1022_ == 0)
{
v___y_997_ = v___x_1022_;
goto v___jp_996_;
}
else
{
lean_object* v___x_1023_; lean_object* v___x_1024_; lean_object* v___x_1025_; uint8_t v___x_1026_; 
v___x_1023_ = lean_unsigned_to_nat(13u);
v___x_1024_ = lean_unsigned_to_nat(14u);
v___x_1025_ = lean_unsigned_to_nat(10u);
v___x_1026_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_995_, v___x_1023_, v___x_1024_, v___x_1025_);
v___y_997_ = v___x_1026_;
goto v___jp_996_;
}
v___jp_996_:
{
if (v___y_997_ == 0)
{
return v___y_997_;
}
else
{
lean_object* v___x_998_; lean_object* v___x_999_; lean_object* v___x_1000_; uint8_t v___x_1001_; 
v___x_998_ = lean_unsigned_to_nat(24u);
v___x_999_ = lean_unsigned_to_nat(25u);
v___x_1000_ = lean_unsigned_to_nat(10u);
v___x_1001_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_995_, v___x_998_, v___x_999_, v___x_1000_);
if (v___x_1001_ == 0)
{
return v___x_1001_;
}
else
{
lean_object* v___x_1002_; lean_object* v___x_1003_; uint8_t v___x_1004_; 
v___x_1002_ = lean_unsigned_to_nat(35u);
v___x_1003_ = lean_unsigned_to_nat(36u);
v___x_1004_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_995_, v___x_1002_, v___x_1003_, v___x_1000_);
if (v___x_1004_ == 0)
{
return v___x_1004_;
}
else
{
lean_object* v___x_1005_; lean_object* v___x_1006_; uint8_t v___x_1007_; 
v___x_1005_ = lean_unsigned_to_nat(46u);
v___x_1006_ = lean_unsigned_to_nat(47u);
v___x_1007_ = lp_lean1090_Lean1090_Impl_cbStatus(v_word_995_, v___x_1005_, v___x_1006_, v___x_1000_);
if (v___x_1007_ == 0)
{
return v___x_1007_;
}
else
{
lean_object* v___x_1008_; lean_object* v___x_1009_; lean_object* v___x_1010_; uint8_t v___x_1011_; 
v___x_1008_ = lean_unsigned_to_nat(14u);
v___x_1009_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_995_, v___x_1008_, v___x_1000_);
v___x_1010_ = lean_unsigned_to_nat(500u);
v___x_1011_ = lean_nat_dec_le(v___x_1009_, v___x_1010_);
lean_dec(v___x_1009_);
if (v___x_1011_ == 0)
{
return v___x_1011_;
}
else
{
lean_object* v___x_1012_; lean_object* v___x_1013_; uint8_t v___x_1014_; 
v___x_1012_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_995_);
v___x_1013_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__0, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__0);
v___x_1014_ = l_Rat_instDecidableLe(v___x_1012_, v___x_1013_);
if (v___x_1014_ == 0)
{
return v___x_1014_;
}
else
{
lean_object* v___x_1015_; lean_object* v___x_1016_; lean_object* v___x_1017_; uint8_t v___x_1018_; 
v___x_1015_ = lp_lean1090_Lean1090_Impl_cbVertical60(v_word_995_, v___x_1006_);
v___x_1016_ = l_Rat_abs(v___x_1015_);
v___x_1017_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid60___closed__0, &lp_lean1090_Lean1090_Impl_cbValid60___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid60___closed__0);
v___x_1018_ = l_Rat_instDecidableLe(v___x_1016_, v___x_1017_);
return v___x_1018_;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbValid60___boxed(lean_object* v_word_1027_){
_start:
{
uint8_t v_res_1028_; lean_object* v_r_1029_; 
v_res_1028_ = lp_lean1090_Lean1090_Impl_cbValid60(v_word_1027_);
lean_dec(v_word_1027_);
v_r_1029_ = lean_box(v_res_1028_);
return v_r_1029_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_bdsWireValid(lean_object* v_register_1030_, lean_object* v_word_1031_){
_start:
{
lean_object* v___x_1032_; uint8_t v___x_1033_; 
v___x_1032_ = lean_cstr_to_nat("72057594037927936");
v___x_1033_ = lean_nat_dec_lt(v_word_1031_, v___x_1032_);
if (v___x_1033_ == 0)
{
return v___x_1033_;
}
else
{
lean_object* v___x_1034_; uint8_t v___x_1035_; 
v___x_1034_ = lean_unsigned_to_nat(5u);
v___x_1035_ = lean_nat_dec_eq(v_register_1030_, v___x_1034_);
if (v___x_1035_ == 0)
{
lean_object* v___x_1036_; uint8_t v___x_1037_; 
v___x_1036_ = lean_unsigned_to_nat(101u);
v___x_1037_ = lean_nat_dec_eq(v_register_1030_, v___x_1036_);
if (v___x_1037_ == 0)
{
lean_object* v___x_1038_; uint8_t v___x_1039_; 
v___x_1038_ = lean_unsigned_to_nat(16u);
v___x_1039_ = lean_nat_dec_eq(v_register_1030_, v___x_1038_);
if (v___x_1039_ == 0)
{
lean_object* v___x_1040_; uint8_t v___x_1041_; 
v___x_1040_ = lean_unsigned_to_nat(23u);
v___x_1041_ = lean_nat_dec_eq(v_register_1030_, v___x_1040_);
if (v___x_1041_ == 0)
{
lean_object* v___x_1042_; uint8_t v___x_1043_; 
v___x_1042_ = lean_unsigned_to_nat(24u);
v___x_1043_ = lean_nat_dec_eq(v_register_1030_, v___x_1042_);
if (v___x_1043_ == 0)
{
lean_object* v___x_1044_; uint8_t v___x_1045_; 
v___x_1044_ = lean_unsigned_to_nat(25u);
v___x_1045_ = lean_nat_dec_eq(v_register_1030_, v___x_1044_);
if (v___x_1045_ == 0)
{
lean_object* v___x_1046_; uint8_t v___x_1047_; 
v___x_1046_ = lean_unsigned_to_nat(32u);
v___x_1047_ = lean_nat_dec_eq(v_register_1030_, v___x_1046_);
if (v___x_1047_ == 0)
{
lean_object* v___x_1048_; uint8_t v___x_1049_; 
v___x_1048_ = lean_unsigned_to_nat(33u);
v___x_1049_ = lean_nat_dec_eq(v_register_1030_, v___x_1048_);
if (v___x_1049_ == 0)
{
lean_object* v___x_1050_; uint8_t v___x_1051_; 
v___x_1050_ = lean_unsigned_to_nat(48u);
v___x_1051_ = lean_nat_dec_eq(v_register_1030_, v___x_1050_);
if (v___x_1051_ == 0)
{
lean_object* v___x_1052_; uint8_t v___x_1053_; 
v___x_1052_ = lean_unsigned_to_nat(64u);
v___x_1053_ = lean_nat_dec_eq(v_register_1030_, v___x_1052_);
if (v___x_1053_ == 0)
{
lean_object* v___x_1054_; uint8_t v___x_1055_; 
v___x_1054_ = lean_unsigned_to_nat(68u);
v___x_1055_ = lean_nat_dec_eq(v_register_1030_, v___x_1054_);
if (v___x_1055_ == 0)
{
lean_object* v___x_1056_; uint8_t v___x_1057_; 
v___x_1056_ = lean_unsigned_to_nat(69u);
v___x_1057_ = lean_nat_dec_eq(v_register_1030_, v___x_1056_);
if (v___x_1057_ == 0)
{
lean_object* v___x_1058_; uint8_t v___x_1059_; 
v___x_1058_ = lean_unsigned_to_nat(80u);
v___x_1059_ = lean_nat_dec_eq(v_register_1030_, v___x_1058_);
if (v___x_1059_ == 0)
{
lean_object* v___x_1060_; uint8_t v___x_1061_; 
v___x_1060_ = lean_unsigned_to_nat(96u);
v___x_1061_ = lean_nat_dec_eq(v_register_1030_, v___x_1060_);
if (v___x_1061_ == 0)
{
return v___x_1061_;
}
else
{
uint8_t v___x_1062_; 
v___x_1062_ = lp_lean1090_Lean1090_Impl_cbValid60(v_word_1031_);
return v___x_1062_;
}
}
else
{
uint8_t v___x_1063_; 
v___x_1063_ = lp_lean1090_Lean1090_Impl_cbValid50(v_word_1031_);
return v___x_1063_;
}
}
else
{
uint8_t v___x_1064_; 
v___x_1064_ = lp_lean1090_Lean1090_Impl_cbValid45(v_word_1031_);
return v___x_1064_;
}
}
else
{
uint8_t v___x_1065_; 
v___x_1065_ = lp_lean1090_Lean1090_Impl_cbValid44(v_word_1031_);
return v___x_1065_;
}
}
else
{
uint8_t v___x_1066_; 
v___x_1066_ = lp_lean1090_Lean1090_Impl_cbValid40(v_word_1031_);
return v___x_1066_;
}
}
else
{
lean_object* v___x_1067_; lean_object* v___x_1068_; lean_object* v___x_1069_; uint8_t v___x_1070_; 
v___x_1067_ = lean_unsigned_to_nat(1u);
v___x_1068_ = lean_unsigned_to_nat(8u);
v___x_1069_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1031_, v___x_1067_, v___x_1068_);
v___x_1070_ = lean_nat_dec_eq(v___x_1069_, v___x_1050_);
lean_dec(v___x_1069_);
return v___x_1070_;
}
}
else
{
uint8_t v___x_1071_; 
v___x_1071_ = lp_lean1090_Lean1090_Impl_cbValid21(v_word_1031_);
return v___x_1071_;
}
}
else
{
lean_object* v___x_1072_; lean_object* v___x_1073_; lean_object* v___x_1074_; uint8_t v___x_1075_; 
v___x_1072_ = lean_unsigned_to_nat(1u);
v___x_1073_ = lean_unsigned_to_nat(8u);
v___x_1074_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1031_, v___x_1072_, v___x_1073_);
v___x_1075_ = lean_nat_dec_eq(v___x_1074_, v___x_1046_);
lean_dec(v___x_1074_);
return v___x_1075_;
}
}
else
{
uint8_t v___x_1076_; 
v___x_1076_ = lp_lean1090_Lean1090_Impl_cbValid19(v_word_1031_);
return v___x_1076_;
}
}
else
{
uint8_t v___x_1077_; 
v___x_1077_ = lp_lean1090_Lean1090_Impl_cbValid18(v_word_1031_);
return v___x_1077_;
}
}
else
{
uint8_t v___x_1078_; 
v___x_1078_ = lp_lean1090_Lean1090_Impl_cbValid17(v_word_1031_);
return v___x_1078_;
}
}
else
{
lean_object* v___x_1079_; lean_object* v___x_1080_; lean_object* v___x_1081_; uint8_t v___x_1082_; 
v___x_1079_ = lean_unsigned_to_nat(1u);
v___x_1080_ = lean_unsigned_to_nat(8u);
v___x_1081_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1031_, v___x_1079_, v___x_1080_);
v___x_1082_ = lean_nat_dec_eq(v___x_1081_, v___x_1038_);
lean_dec(v___x_1081_);
if (v___x_1082_ == 0)
{
return v___x_1082_;
}
else
{
lean_object* v___x_1083_; lean_object* v___x_1084_; lean_object* v___x_1085_; uint8_t v___x_1086_; 
v___x_1083_ = lean_unsigned_to_nat(10u);
v___x_1084_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1031_, v___x_1083_, v___x_1034_);
v___x_1085_ = lean_unsigned_to_nat(0u);
v___x_1086_ = lean_nat_dec_eq(v___x_1084_, v___x_1085_);
lean_dec(v___x_1084_);
return v___x_1086_;
}
}
}
else
{
lean_object* v___x_1087_; lean_object* v___x_1088_; lean_object* v___x_1089_; uint8_t v___x_1090_; 
v___x_1087_ = lean_unsigned_to_nat(1u);
v___x_1088_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1031_, v___x_1087_, v___x_1034_);
v___x_1089_ = lean_unsigned_to_nat(31u);
v___x_1090_ = lean_nat_dec_eq(v___x_1088_, v___x_1089_);
lean_dec(v___x_1088_);
if (v___x_1090_ == 0)
{
return v___x_1090_;
}
else
{
lean_object* v___x_1091_; lean_object* v___x_1092_; lean_object* v___x_1093_; lean_object* v___x_1094_; uint8_t v___x_1095_; 
v___x_1091_ = lean_unsigned_to_nat(6u);
v___x_1092_ = lean_unsigned_to_nat(3u);
v___x_1093_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1031_, v___x_1091_, v___x_1092_);
v___x_1094_ = lean_unsigned_to_nat(2u);
v___x_1095_ = lean_nat_dec_lt(v___x_1093_, v___x_1094_);
lean_dec(v___x_1093_);
if (v___x_1095_ == 0)
{
return v___x_1095_;
}
else
{
uint8_t v___x_1096_; 
v___x_1096_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1031_);
return v___x_1096_;
}
}
}
}
else
{
lean_object* v___x_1097_; lean_object* v_tc_1098_; lean_object* v___x_1105_; uint8_t v___x_1106_; 
v___x_1097_ = lean_unsigned_to_nat(1u);
v_tc_1098_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1031_, v___x_1097_, v___x_1034_);
v___x_1105_ = lean_unsigned_to_nat(9u);
v___x_1106_ = lean_nat_dec_le(v___x_1105_, v_tc_1098_);
if (v___x_1106_ == 0)
{
goto v___jp_1099_;
}
else
{
lean_object* v___x_1107_; uint8_t v___x_1108_; 
v___x_1107_ = lean_unsigned_to_nat(18u);
v___x_1108_ = lean_nat_dec_le(v_tc_1098_, v___x_1107_);
if (v___x_1108_ == 0)
{
goto v___jp_1099_;
}
else
{
uint8_t v___x_1109_; 
lean_dec(v_tc_1098_);
v___x_1109_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1031_);
return v___x_1109_;
}
}
v___jp_1099_:
{
lean_object* v___x_1100_; uint8_t v___x_1101_; 
v___x_1100_ = lean_unsigned_to_nat(20u);
v___x_1101_ = lean_nat_dec_le(v___x_1100_, v_tc_1098_);
if (v___x_1101_ == 0)
{
lean_dec(v_tc_1098_);
return v___x_1101_;
}
else
{
lean_object* v___x_1102_; uint8_t v___x_1103_; 
v___x_1102_ = lean_unsigned_to_nat(22u);
v___x_1103_ = lean_nat_dec_le(v_tc_1098_, v___x_1102_);
lean_dec(v_tc_1098_);
if (v___x_1103_ == 0)
{
return v___x_1103_;
}
else
{
uint8_t v___x_1104_; 
v___x_1104_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_word_1031_);
return v___x_1104_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsWireValid___boxed(lean_object* v_register_1110_, lean_object* v_word_1111_){
_start:
{
uint8_t v_res_1112_; lean_object* v_r_1113_; 
v_res_1112_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1110_, v_word_1111_);
lean_dec(v_word_1111_);
lean_dec(v_register_1110_);
v_r_1113_ = lean_box(v_res_1112_);
return v_r_1113_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_bdsLayout___closed__0(void){
_start:
{
lean_object* v___x_1114_; lean_object* v___x_1115_; 
v___x_1114_ = lp_lean1090_Lean1090_Impl_adsbPositionLayout;
v___x_1115_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1115_, 0, v___x_1114_);
return v___x_1115_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsLayout(lean_object* v_register_1116_, lean_object* v_word_1117_){
_start:
{
lean_object* v___x_1118_; uint8_t v___x_1119_; 
v___x_1118_ = lean_unsigned_to_nat(5u);
v___x_1119_ = lean_nat_dec_eq(v_register_1116_, v___x_1118_);
if (v___x_1119_ == 0)
{
lean_object* v___x_1120_; uint8_t v___x_1121_; 
v___x_1120_ = lean_unsigned_to_nat(101u);
v___x_1121_ = lean_nat_dec_eq(v_register_1116_, v___x_1120_);
if (v___x_1121_ == 0)
{
lean_object* v___x_1122_; 
v___x_1122_ = lp_lean1090_Lean1090_Impl_commBLayout(v_register_1116_);
return v___x_1122_;
}
else
{
lean_object* v___x_1123_; 
v___x_1123_ = lp_lean1090_Lean1090_Impl_adsbLayout(v_word_1117_);
return v___x_1123_;
}
}
else
{
lean_object* v___x_1124_; 
v___x_1124_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_bdsLayout___closed__0, &lp_lean1090_Lean1090_Impl_bdsLayout___closed__0_once, _init_lp_lean1090_Lean1090_Impl_bdsLayout___closed__0);
return v___x_1124_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bdsLayout___boxed(lean_object* v_register_1125_, lean_object* v_word_1126_){
_start:
{
lean_object* v_res_1127_; 
v_res_1127_ = lp_lean1090_Lean1090_Impl_bdsLayout(v_register_1125_, v_word_1126_);
lean_dec(v_word_1126_);
lean_dec(v_register_1125_);
return v_res_1127_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeBDS(lean_object* v_register_1128_, lean_object* v_word_1129_){
_start:
{
lean_object* v___x_1130_; 
v___x_1130_ = lp_lean1090_Lean1090_Impl_bdsLayout(v_register_1128_, v_word_1129_);
if (lean_obj_tag(v___x_1130_) == 0)
{
lean_object* v___x_1131_; 
lean_dec(v_register_1128_);
v___x_1131_ = lean_box(0);
return v___x_1131_;
}
else
{
lean_object* v_val_1132_; lean_object* v___x_1134_; uint8_t v_isShared_1135_; uint8_t v_isSharedCheck_1143_; 
v_val_1132_ = lean_ctor_get(v___x_1130_, 0);
v_isSharedCheck_1143_ = !lean_is_exclusive(v___x_1130_);
if (v_isSharedCheck_1143_ == 0)
{
v___x_1134_ = v___x_1130_;
v_isShared_1135_ = v_isSharedCheck_1143_;
goto v_resetjp_1133_;
}
else
{
lean_inc(v_val_1132_);
lean_dec(v___x_1130_);
v___x_1134_ = lean_box(0);
v_isShared_1135_ = v_isSharedCheck_1143_;
goto v_resetjp_1133_;
}
v_resetjp_1133_:
{
uint8_t v___x_1136_; 
v___x_1136_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1128_, v_word_1129_);
if (v___x_1136_ == 0)
{
lean_object* v___x_1137_; 
lean_del_object(v___x_1134_);
lean_dec(v_val_1132_);
lean_dec(v_register_1128_);
v___x_1137_ = lean_box(0);
return v___x_1137_;
}
else
{
lean_object* v___x_1138_; lean_object* v___x_1139_; lean_object* v___x_1141_; 
v___x_1138_ = lp_lean1090_Lean1090_Impl_decodePayloadFields(v_val_1132_, v_word_1129_);
v___x_1139_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1139_, 0, v_register_1128_);
lean_ctor_set(v___x_1139_, 1, v___x_1138_);
if (v_isShared_1135_ == 0)
{
lean_ctor_set(v___x_1134_, 0, v___x_1139_);
v___x_1141_ = v___x_1134_;
goto v_reusejp_1140_;
}
else
{
lean_object* v_reuseFailAlloc_1142_; 
v_reuseFailAlloc_1142_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1142_, 0, v___x_1139_);
v___x_1141_ = v_reuseFailAlloc_1142_;
goto v_reusejp_1140_;
}
v_reusejp_1140_:
{
return v___x_1141_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeBDS___boxed(lean_object* v_register_1144_, lean_object* v_word_1145_){
_start:
{
lean_object* v_res_1146_; 
v_res_1146_ = lp_lean1090_Lean1090_Impl_decodeBDS(v_register_1144_, v_word_1145_);
lean_dec(v_word_1145_);
return v_res_1146_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__0(void){
_start:
{
lean_object* v___x_1147_; lean_object* v___x_1148_; 
v___x_1147_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__0, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__0);
v___x_1148_ = l_Rat_neg(v___x_1147_);
return v___x_1148_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1(void){
_start:
{
lean_object* v___x_1149_; lean_object* v___x_1150_; 
v___x_1149_ = lean_unsigned_to_nat(2u);
v___x_1150_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1149_);
return v___x_1150_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__2(void){
_start:
{
lean_object* v___x_1151_; lean_object* v___x_1152_; lean_object* v___x_1153_; 
v___x_1151_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1152_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__0, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__0);
v___x_1153_ = l_Rat_div(v___x_1152_, v___x_1151_);
return v___x_1153_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGaussian(lean_object* v_value_1154_, lean_object* v_mu_1155_, lean_object* v_sigma_1156_){
_start:
{
lean_object* v___x_1157_; lean_object* v___x_1158_; lean_object* v___x_1159_; lean_object* v_z_1160_; lean_object* v___x_1161_; lean_object* v___x_1162_; lean_object* v___x_1163_; 
v___x_1157_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_mu_1155_);
v___x_1158_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_value_1154_, v___x_1157_);
v___x_1159_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_sigma_1156_);
v_z_1160_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1158_, v___x_1159_);
lean_dec_ref(v___x_1158_);
v___x_1161_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__2, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__2);
lean_inc_ref(v_z_1160_);
v___x_1162_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1161_, v_z_1160_);
v___x_1163_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1162_, v_z_1160_);
lean_dec_ref(v___x_1162_);
return v___x_1163_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbLaplace(lean_object* v_value_1164_, lean_object* v_median_1165_, lean_object* v_scale_1166_){
_start:
{
lean_object* v___x_1167_; uint8_t v___x_1168_; 
v___x_1167_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_scale_1166_);
v___x_1168_ = l_Rat_instDecidableLe(v_scale_1166_, v___x_1167_);
if (v___x_1168_ == 0)
{
lean_object* v___x_1169_; lean_object* v___x_1170_; lean_object* v___x_1171_; lean_object* v___x_1172_; lean_object* v___x_1173_; lean_object* v___x_1174_; 
v___x_1169_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_median_1165_);
v___x_1170_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_value_1164_, v___x_1169_);
v___x_1171_ = l_Rat_abs(v___x_1170_);
v___x_1172_ = l_Rat_neg(v___x_1171_);
v___x_1173_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_scale_1166_);
v___x_1174_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1172_, v___x_1173_);
lean_dec_ref(v___x_1172_);
return v___x_1174_;
}
else
{
lean_dec_ref(v_scale_1166_);
lean_dec_ref(v_median_1165_);
lean_dec_ref(v_value_1164_);
return v___x_1167_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScoreField(lean_object* v_value_1175_, lean_object* v_score_1176_){
_start:
{
if (lean_obj_tag(v_value_1175_) == 0)
{
lean_object* v___x_1177_; 
lean_dec_ref(v_score_1176_);
v___x_1177_ = lean_box(0);
return v___x_1177_;
}
else
{
lean_object* v_val_1178_; lean_object* v___x_1179_; lean_object* v___x_1180_; lean_object* v___x_1181_; 
v_val_1178_ = lean_ctor_get(v_value_1175_, 0);
lean_inc(v_val_1178_);
lean_dec_ref_known(v_value_1175_, 1);
v___x_1179_ = lean_apply_1(v_score_1176_, v_val_1178_);
v___x_1180_ = lean_box(0);
v___x_1181_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1181_, 0, v___x_1179_);
lean_ctor_set(v___x_1181_, 1, v___x_1180_);
return v___x_1181_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1182_; lean_object* v___x_1183_; 
v___x_1182_ = lean_unsigned_to_nat(142u);
v___x_1183_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1182_);
return v___x_1183_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1(void){
_start:
{
lean_object* v___x_1184_; lean_object* v___x_1185_; 
v___x_1184_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__0);
v___x_1185_ = l_Rat_neg(v___x_1184_);
return v___x_1185_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2(void){
_start:
{
lean_object* v___x_1186_; lean_object* v___x_1187_; lean_object* v___x_1188_; 
v___x_1186_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1187_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__1);
v___x_1188_ = l_Rat_div(v___x_1187_, v___x_1186_);
return v___x_1188_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3(void){
_start:
{
lean_object* v___x_1189_; lean_object* v___x_1190_; 
v___x_1189_ = lean_unsigned_to_nat(164u);
v___x_1190_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1189_);
return v___x_1190_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4(void){
_start:
{
lean_object* v___x_1191_; lean_object* v___x_1192_; lean_object* v___x_1193_; 
v___x_1191_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1192_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__3);
v___x_1193_ = l_Rat_div(v___x_1192_, v___x_1191_);
return v___x_1193_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0(lean_object* v_x_1194_){
_start:
{
lean_object* v___x_1195_; lean_object* v___x_1196_; lean_object* v___x_1197_; 
v___x_1195_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2);
v___x_1196_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4);
v___x_1197_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1194_, v___x_1195_, v___x_1196_);
return v___x_1197_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0(void){
_start:
{
lean_object* v___x_1198_; lean_object* v___x_1199_; 
v___x_1198_ = lean_unsigned_to_nat(393u);
v___x_1199_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1198_);
return v___x_1199_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1(void){
_start:
{
lean_object* v___x_1200_; lean_object* v___x_1201_; 
v___x_1200_ = lean_unsigned_to_nat(290u);
v___x_1201_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1200_);
return v___x_1201_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1(lean_object* v_x_1202_){
_start:
{
lean_object* v___x_1203_; lean_object* v___x_1204_; lean_object* v___x_1205_; 
v___x_1203_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0);
v___x_1204_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1);
v___x_1205_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1202_, v___x_1203_, v___x_1204_);
return v___x_1205_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0(void){
_start:
{
lean_object* v___x_1206_; lean_object* v___x_1207_; 
v___x_1206_ = lean_unsigned_to_nat(52u);
v___x_1207_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1206_);
return v___x_1207_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1(void){
_start:
{
lean_object* v___x_1208_; lean_object* v___x_1209_; 
v___x_1208_ = lean_unsigned_to_nat(29u);
v___x_1209_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1208_);
return v___x_1209_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2(lean_object* v_x_1210_){
_start:
{
lean_object* v___x_1211_; lean_object* v___x_1212_; lean_object* v___x_1213_; 
v___x_1211_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0);
v___x_1212_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1);
v___x_1213_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1210_, v___x_1211_, v___x_1212_);
return v___x_1213_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0(void){
_start:
{
lean_object* v___x_1214_; lean_object* v___x_1215_; 
v___x_1214_ = lean_unsigned_to_nat(272u);
v___x_1215_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1214_);
return v___x_1215_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1(void){
_start:
{
lean_object* v___x_1216_; lean_object* v___x_1217_; 
v___x_1216_ = lean_unsigned_to_nat(55u);
v___x_1217_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1216_);
return v___x_1217_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4(lean_object* v_x_1218_){
_start:
{
lean_object* v___x_1219_; lean_object* v___x_1220_; lean_object* v___x_1221_; 
v___x_1219_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0);
v___x_1220_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1);
v___x_1221_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1218_, v___x_1219_, v___x_1220_);
return v___x_1221_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0(void){
_start:
{
lean_object* v___x_1222_; lean_object* v___x_1223_; 
v___x_1222_ = lean_unsigned_to_nat(69u);
v___x_1223_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1222_);
return v___x_1223_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1(void){
_start:
{
lean_object* v___x_1224_; lean_object* v___x_1225_; 
v___x_1224_ = lean_unsigned_to_nat(100u);
v___x_1225_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1224_);
return v___x_1225_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2(void){
_start:
{
lean_object* v___x_1226_; lean_object* v___x_1227_; lean_object* v___x_1228_; 
v___x_1226_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1227_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__0);
v___x_1228_ = l_Rat_div(v___x_1227_, v___x_1226_);
return v___x_1228_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3(void){
_start:
{
lean_object* v___x_1229_; lean_object* v___x_1230_; 
v___x_1229_ = lean_unsigned_to_nat(21u);
v___x_1230_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1229_);
return v___x_1230_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4(void){
_start:
{
lean_object* v___x_1231_; lean_object* v___x_1232_; lean_object* v___x_1233_; 
v___x_1231_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1232_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3);
v___x_1233_ = l_Rat_div(v___x_1232_, v___x_1231_);
return v___x_1233_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3(lean_object* v_x_1234_){
_start:
{
lean_object* v___x_1235_; lean_object* v___x_1236_; lean_object* v___x_1237_; 
v___x_1235_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2);
v___x_1236_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4);
v___x_1237_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1234_, v___x_1235_, v___x_1236_);
return v___x_1237_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0(void){
_start:
{
lean_object* v___x_1238_; lean_object* v___x_1239_; 
v___x_1238_ = lean_unsigned_to_nat(298u);
v___x_1239_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1238_);
return v___x_1239_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1(void){
_start:
{
lean_object* v___x_1240_; lean_object* v___x_1241_; 
v___x_1240_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__0);
v___x_1241_ = l_Rat_neg(v___x_1240_);
return v___x_1241_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2(void){
_start:
{
lean_object* v___x_1242_; lean_object* v___x_1243_; 
v___x_1242_ = lean_unsigned_to_nat(1669u);
v___x_1243_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1242_);
return v___x_1243_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5(lean_object* v_x_1244_){
_start:
{
lean_object* v___x_1245_; lean_object* v___x_1246_; lean_object* v___x_1247_; 
v___x_1245_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1);
v___x_1246_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2);
v___x_1247_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1244_, v___x_1245_, v___x_1246_);
return v___x_1247_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0(void){
_start:
{
lean_object* v___x_1248_; lean_object* v___x_1249_; 
v___x_1248_ = lean_unsigned_to_nat(418u);
v___x_1249_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1248_);
return v___x_1249_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1(void){
_start:
{
lean_object* v___x_1250_; lean_object* v___x_1251_; 
v___x_1250_ = lean_unsigned_to_nat(129u);
v___x_1251_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1250_);
return v___x_1251_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6(lean_object* v_x_1252_){
_start:
{
lean_object* v___x_1253_; lean_object* v___x_1254_; lean_object* v___x_1255_; 
v___x_1253_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0);
v___x_1254_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1);
v___x_1255_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1252_, v___x_1253_, v___x_1254_);
return v___x_1255_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0(void){
_start:
{
lean_object* v___x_1256_; lean_object* v___x_1257_; 
v___x_1256_ = lean_unsigned_to_nat(413u);
v___x_1257_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1256_);
return v___x_1257_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1(void){
_start:
{
lean_object* v___x_1258_; lean_object* v___x_1259_; 
v___x_1258_ = lean_unsigned_to_nat(120u);
v___x_1259_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1258_);
return v___x_1259_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7(lean_object* v_x_1260_){
_start:
{
lean_object* v___x_1261_; lean_object* v___x_1262_; lean_object* v___x_1263_; 
v___x_1261_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0);
v___x_1262_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1);
v___x_1263_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1260_, v___x_1261_, v___x_1262_);
return v___x_1263_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0(void){
_start:
{
lean_object* v___x_1264_; lean_object* v___x_1265_; 
v___x_1264_ = lean_unsigned_to_nat(70u);
v___x_1265_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1264_);
return v___x_1265_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1(void){
_start:
{
lean_object* v___x_1266_; lean_object* v___x_1267_; lean_object* v___x_1268_; 
v___x_1266_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1267_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__0);
v___x_1268_ = l_Rat_div(v___x_1267_, v___x_1266_);
return v___x_1268_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8(lean_object* v_x_1269_){
_start:
{
lean_object* v___x_1270_; lean_object* v___x_1271_; lean_object* v___x_1272_; 
v___x_1270_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1271_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1);
v___x_1272_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1269_, v___x_1270_, v___x_1271_);
return v___x_1272_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__9(lean_object* v_x_1273_){
_start:
{
lean_object* v___x_1274_; lean_object* v___x_1275_; lean_object* v___x_1276_; 
v___x_1274_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1275_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1276_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1273_, v___x_1274_, v___x_1275_);
return v___x_1276_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0(void){
_start:
{
lean_object* v___x_1277_; lean_object* v___x_1278_; 
v___x_1277_ = lean_unsigned_to_nat(24688u);
v___x_1278_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1277_);
return v___x_1278_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1(void){
_start:
{
lean_object* v___x_1279_; lean_object* v___x_1280_; 
v___x_1279_ = lean_unsigned_to_nat(10844u);
v___x_1280_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1279_);
return v___x_1280_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10(lean_object* v_x_1281_){
_start:
{
lean_object* v___x_1282_; lean_object* v___x_1283_; lean_object* v___x_1284_; 
v___x_1282_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0);
v___x_1283_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1);
v___x_1284_ = lp_lean1090_Lean1090_Impl_cbGaussian(v_x_1281_, v___x_1282_, v___x_1283_);
return v___x_1284_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0(void){
_start:
{
lean_object* v___x_1285_; lean_object* v___x_1286_; 
v___x_1285_ = lean_unsigned_to_nat(10132u);
v___x_1286_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1285_);
return v___x_1286_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1(void){
_start:
{
lean_object* v___x_1287_; lean_object* v___x_1288_; lean_object* v___x_1289_; 
v___x_1287_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1288_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__0);
v___x_1289_ = l_Rat_div(v___x_1288_, v___x_1287_);
return v___x_1289_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2(void){
_start:
{
lean_object* v___x_1290_; lean_object* v___x_1291_; 
v___x_1290_ = lean_unsigned_to_nat(54u);
v___x_1291_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1290_);
return v___x_1291_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3(void){
_start:
{
lean_object* v___x_1292_; lean_object* v___x_1293_; lean_object* v___x_1294_; 
v___x_1292_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1293_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__2);
v___x_1294_ = l_Rat_div(v___x_1293_, v___x_1292_);
return v___x_1294_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11(lean_object* v_x_1295_){
_start:
{
lean_object* v___x_1296_; lean_object* v___x_1297_; lean_object* v___x_1298_; 
v___x_1296_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1);
v___x_1297_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3);
v___x_1298_ = lp_lean1090_Lean1090_Impl_cbLaplace(v_x_1295_, v___x_1296_, v___x_1297_);
return v___x_1298_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5(void){
_start:
{
lean_object* v___x_1304_; lean_object* v___x_1305_; 
v___x_1304_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__3);
v___x_1305_ = l_Rat_neg(v___x_1304_);
return v___x_1305_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6(void){
_start:
{
lean_object* v___x_1306_; lean_object* v___x_1307_; 
v___x_1306_ = lean_unsigned_to_nat(990u);
v___x_1307_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1306_);
return v___x_1307_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7(void){
_start:
{
lean_object* v___x_1308_; lean_object* v___x_1309_; lean_object* v___x_1310_; 
v___x_1308_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1309_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__6);
v___x_1310_ = l_Rat_div(v___x_1309_, v___x_1308_);
return v___x_1310_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms(lean_object* v_register_1328_, lean_object* v_word_1329_){
_start:
{
lean_object* v___x_1330_; uint8_t v___x_1331_; 
v___x_1330_ = lean_unsigned_to_nat(64u);
v___x_1331_ = lean_nat_dec_eq(v_register_1328_, v___x_1330_);
if (v___x_1331_ == 0)
{
lean_object* v___x_1332_; uint8_t v___x_1333_; 
v___x_1332_ = lean_unsigned_to_nat(80u);
v___x_1333_ = lean_nat_dec_eq(v_register_1328_, v___x_1332_);
if (v___x_1333_ == 0)
{
lean_object* v___x_1334_; uint8_t v___x_1335_; 
v___x_1334_ = lean_unsigned_to_nat(96u);
v___x_1335_ = lean_nat_dec_eq(v_register_1328_, v___x_1334_);
if (v___x_1335_ == 0)
{
lean_object* v___x_1336_; uint8_t v___x_1337_; 
v___x_1336_ = lean_unsigned_to_nat(68u);
v___x_1337_ = lean_nat_dec_eq(v_register_1328_, v___x_1336_);
if (v___x_1337_ == 0)
{
lean_object* v___x_1338_; uint8_t v___x_1339_; 
v___x_1338_ = lean_unsigned_to_nat(69u);
v___x_1339_ = lean_nat_dec_eq(v_register_1328_, v___x_1338_);
if (v___x_1339_ == 0)
{
lean_object* v___x_1340_; 
v___x_1340_ = lean_box(0);
return v___x_1340_;
}
else
{
lean_object* v___f_1341_; lean_object* v___f_1342_; lean_object* v___x_1343_; lean_object* v___x_1344_; lean_object* v___x_1345_; lean_object* v___x_1346_; lean_object* v___x_1347_; lean_object* v___x_1348_; lean_object* v___x_1349_; 
v___f_1341_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__0));
v___f_1342_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1));
v___x_1343_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__2));
v___x_1344_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1343_);
v___x_1345_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1344_, v___f_1341_);
v___x_1346_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__3));
v___x_1347_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1346_);
v___x_1348_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1347_, v___f_1342_);
v___x_1349_ = l_List_appendTR___redArg(v___x_1345_, v___x_1348_);
return v___x_1349_;
}
}
else
{
lean_object* v___f_1350_; lean_object* v___f_1351_; lean_object* v___x_1352_; lean_object* v___x_1353_; lean_object* v___x_1354_; lean_object* v___x_1355_; lean_object* v___x_1356_; lean_object* v___x_1357_; lean_object* v___x_1358_; lean_object* v___x_1359_; lean_object* v___x_1360_; lean_object* v___x_1361_; lean_object* v___x_1362_; lean_object* v___x_1363_; lean_object* v___x_1364_; lean_object* v___x_1365_; 
v___f_1350_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__4));
v___f_1351_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__1));
v___x_1352_ = lp_lean1090_Lean1090_Impl_cbTemperature44(v_word_1329_);
v___x_1353_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5);
v___x_1354_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7);
v___x_1355_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1352_, v___x_1353_, v___x_1354_);
v___x_1356_ = lean_box(0);
v___x_1357_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1357_, 0, v___x_1355_);
lean_ctor_set(v___x_1357_, 1, v___x_1356_);
v___x_1358_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__8));
v___x_1359_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1358_);
v___x_1360_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1359_, v___f_1350_);
v___x_1361_ = l_List_appendTR___redArg(v___x_1357_, v___x_1360_);
v___x_1362_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__9));
v___x_1363_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1362_);
v___x_1364_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1363_, v___f_1351_);
v___x_1365_ = l_List_appendTR___redArg(v___x_1361_, v___x_1364_);
return v___x_1365_;
}
}
else
{
lean_object* v___f_1366_; lean_object* v___f_1367_; lean_object* v___f_1368_; lean_object* v___x_1369_; lean_object* v___x_1370_; lean_object* v___x_1371_; lean_object* v___y_1373_; lean_object* v___x_1380_; lean_object* v___x_1381_; 
v___f_1366_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__10));
v___f_1367_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__11));
v___f_1368_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__12));
v___x_1369_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13));
v___x_1370_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1369_);
v___x_1371_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1370_, v___f_1366_);
v___x_1380_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14));
v___x_1381_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1380_);
if (lean_obj_tag(v___x_1381_) == 0)
{
v___y_1373_ = v___x_1381_;
goto v___jp_1372_;
}
else
{
lean_object* v___x_1383_; uint8_t v_isShared_1384_; uint8_t v_isSharedCheck_1389_; 
v_isSharedCheck_1389_ = !lean_is_exclusive(v___x_1381_);
if (v_isSharedCheck_1389_ == 0)
{
lean_object* v_unused_1390_; 
v_unused_1390_ = lean_ctor_get(v___x_1381_, 0);
lean_dec(v_unused_1390_);
v___x_1383_ = v___x_1381_;
v_isShared_1384_ = v_isSharedCheck_1389_;
goto v_resetjp_1382_;
}
else
{
lean_dec(v___x_1381_);
v___x_1383_ = lean_box(0);
v_isShared_1384_ = v_isSharedCheck_1389_;
goto v_resetjp_1382_;
}
v_resetjp_1382_:
{
lean_object* v___x_1385_; lean_object* v___x_1387_; 
v___x_1385_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_1329_);
if (v_isShared_1384_ == 0)
{
lean_ctor_set(v___x_1383_, 0, v___x_1385_);
v___x_1387_ = v___x_1383_;
goto v_reusejp_1386_;
}
else
{
lean_object* v_reuseFailAlloc_1388_; 
v_reuseFailAlloc_1388_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1388_, 0, v___x_1385_);
v___x_1387_ = v_reuseFailAlloc_1388_;
goto v_reusejp_1386_;
}
v_reusejp_1386_:
{
v___y_1373_ = v___x_1387_;
goto v___jp_1372_;
}
}
}
v___jp_1372_:
{
lean_object* v___x_1374_; lean_object* v___x_1375_; lean_object* v___x_1376_; lean_object* v___x_1377_; lean_object* v___x_1378_; lean_object* v___x_1379_; 
v___x_1374_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___y_1373_, v___f_1367_);
v___x_1375_ = l_List_appendTR___redArg(v___x_1371_, v___x_1374_);
v___x_1376_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__2));
v___x_1377_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1376_);
v___x_1378_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1377_, v___f_1368_);
v___x_1379_ = l_List_appendTR___redArg(v___x_1375_, v___x_1378_);
return v___x_1379_;
}
}
}
else
{
lean_object* v___f_1391_; lean_object* v___f_1392_; lean_object* v___f_1393_; lean_object* v___f_1394_; lean_object* v___x_1395_; lean_object* v___x_1396_; lean_object* v___x_1397_; lean_object* v___x_1398_; lean_object* v___x_1399_; lean_object* v___x_1400_; lean_object* v___x_1401_; lean_object* v___x_1402_; lean_object* v___x_1403_; lean_object* v___x_1404_; lean_object* v___x_1405_; lean_object* v___x_1406_; lean_object* v___x_1407_; lean_object* v___x_1408_; lean_object* v___x_1409_; 
v___f_1391_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__15));
v___f_1392_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__16));
v___f_1393_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__17));
v___f_1394_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__18));
v___x_1395_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19));
v___x_1396_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1395_);
v___x_1397_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1396_, v___f_1394_);
v___x_1398_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__4));
v___x_1399_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1398_);
v___x_1400_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1399_, v___f_1393_);
v___x_1401_ = l_List_appendTR___redArg(v___x_1397_, v___x_1400_);
v___x_1402_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__20));
v___x_1403_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1402_);
v___x_1404_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1403_, v___f_1392_);
v___x_1405_ = l_List_appendTR___redArg(v___x_1401_, v___x_1404_);
v___x_1406_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__21));
v___x_1407_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1406_);
v___x_1408_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1407_, v___f_1391_);
v___x_1409_ = l_List_appendTR___redArg(v___x_1405_, v___x_1408_);
return v___x_1409_;
}
}
else
{
lean_object* v___f_1410_; lean_object* v___f_1411_; lean_object* v___y_1413_; lean_object* v___x_1423_; lean_object* v___x_1424_; 
v___f_1410_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__22));
v___f_1411_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__23));
v___x_1423_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__24));
v___x_1424_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1423_);
if (lean_obj_tag(v___x_1424_) == 0)
{
v___y_1413_ = v___x_1424_;
goto v___jp_1412_;
}
else
{
lean_object* v___x_1426_; uint8_t v_isShared_1427_; uint8_t v_isSharedCheck_1432_; 
v_isSharedCheck_1432_ = !lean_is_exclusive(v___x_1424_);
if (v_isSharedCheck_1432_ == 0)
{
lean_object* v_unused_1433_; 
v_unused_1433_ = lean_ctor_get(v___x_1424_, 0);
lean_dec(v_unused_1433_);
v___x_1426_ = v___x_1424_;
v_isShared_1427_ = v_isSharedCheck_1432_;
goto v_resetjp_1425_;
}
else
{
lean_dec(v___x_1424_);
v___x_1426_ = lean_box(0);
v_isShared_1427_ = v_isSharedCheck_1432_;
goto v_resetjp_1425_;
}
v_resetjp_1425_:
{
lean_object* v___x_1428_; lean_object* v___x_1430_; 
v___x_1428_ = lp_lean1090_Lean1090_Impl_cbQNH64(v_word_1329_);
if (v_isShared_1427_ == 0)
{
lean_ctor_set(v___x_1426_, 0, v___x_1428_);
v___x_1430_ = v___x_1426_;
goto v_reusejp_1429_;
}
else
{
lean_object* v_reuseFailAlloc_1431_; 
v_reuseFailAlloc_1431_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1431_, 0, v___x_1428_);
v___x_1430_ = v_reuseFailAlloc_1431_;
goto v_reusejp_1429_;
}
v_reusejp_1429_:
{
v___y_1413_ = v___x_1430_;
goto v___jp_1412_;
}
}
}
v___jp_1412_:
{
lean_object* v___x_1414_; lean_object* v___x_1415_; lean_object* v___x_1416_; lean_object* v___x_1417_; lean_object* v___x_1418_; lean_object* v___x_1419_; lean_object* v___x_1420_; lean_object* v___x_1421_; lean_object* v___x_1422_; 
v___x_1414_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___y_1413_, v___f_1411_);
v___x_1415_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__6));
v___x_1416_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1415_);
v___x_1417_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1416_, v___f_1410_);
v___x_1418_ = l_List_appendTR___redArg(v___x_1414_, v___x_1417_);
v___x_1419_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__7));
v___x_1420_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1328_, v_word_1329_, v___x_1419_);
v___x_1421_ = lp_lean1090_Lean1090_Impl_cbScoreField(v___x_1420_, v___f_1410_);
v___x_1422_ = l_List_appendTR___redArg(v___x_1418_, v___x_1421_);
return v___x_1422_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTerms___boxed(lean_object* v_register_1434_, lean_object* v_word_1435_){
_start:
{
lean_object* v_res_1436_; 
v_res_1436_ = lp_lean1090_Lean1090_Impl_cbDensityTerms(v_register_1434_, v_word_1435_);
lean_dec(v_word_1435_);
lean_dec(v_register_1434_);
return v_res_1436_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_cbDensity_spec__0(lean_object* v_x_1437_, lean_object* v_x_1438_){
_start:
{
if (lean_obj_tag(v_x_1438_) == 0)
{
return v_x_1437_;
}
else
{
lean_object* v_head_1439_; lean_object* v_tail_1440_; lean_object* v___x_1441_; 
v_head_1439_ = lean_ctor_get(v_x_1438_, 0);
lean_inc(v_head_1439_);
v_tail_1440_ = lean_ctor_get(v_x_1438_, 1);
lean_inc(v_tail_1440_);
lean_dec_ref_known(v_x_1438_, 2);
v___x_1441_ = lp_lean1090_Lean1090_Impl_Binary64_add(v_x_1437_, v_head_1439_);
v_x_1437_ = v___x_1441_;
v_x_1438_ = v_tail_1440_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensity(lean_object* v_register_1443_, lean_object* v_word_1444_){
_start:
{
lean_object* v_terms_1445_; uint8_t v___x_1446_; 
v_terms_1445_ = lp_lean1090_Lean1090_Impl_cbDensityTerms(v_register_1443_, v_word_1444_);
v___x_1446_ = l_List_isEmpty___redArg(v_terms_1445_);
if (v___x_1446_ == 0)
{
lean_object* v___x_1447_; lean_object* v___x_1448_; lean_object* v___x_1449_; lean_object* v___x_1450_; lean_object* v___x_1451_; 
v___x_1447_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc(v_terms_1445_);
v___x_1448_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_cbDensity_spec__0(v___x_1447_, v_terms_1445_);
v___x_1449_ = l_List_lengthTR___redArg(v_terms_1445_);
lean_dec(v_terms_1445_);
v___x_1450_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1449_);
v___x_1451_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1448_, v___x_1450_);
lean_dec_ref(v___x_1448_);
return v___x_1451_;
}
else
{
lean_object* v___x_1452_; 
lean_dec(v_terms_1445_);
v___x_1452_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1452_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensity___boxed(lean_object* v_register_1453_, lean_object* v_word_1454_){
_start:
{
lean_object* v_res_1455_; 
v_res_1455_ = lp_lean1090_Lean1090_Impl_cbDensity(v_register_1453_, v_word_1454_);
lean_dec(v_word_1454_);
lean_dec(v_register_1453_);
return v_res_1455_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0(void){
_start:
{
lean_object* v___x_1456_; lean_object* v___x_1457_; 
v___x_1456_ = lean_unsigned_to_nat(5u);
v___x_1457_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1456_);
return v___x_1457_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1(void){
_start:
{
lean_object* v___x_1458_; lean_object* v___x_1459_; 
v___x_1458_ = lean_unsigned_to_nat(3u);
v___x_1459_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1458_);
return v___x_1459_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__2(void){
_start:
{
lean_object* v___x_1460_; lean_object* v___x_1461_; lean_object* v___x_1462_; 
v___x_1460_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1461_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__1, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1);
v___x_1462_ = l_Rat_div(v___x_1461_, v___x_1460_);
return v___x_1462_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__3(void){
_start:
{
lean_object* v___x_1463_; lean_object* v___x_1464_; 
v___x_1463_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__2, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__2);
v___x_1464_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_1463_);
return v___x_1464_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__4(void){
_start:
{
lean_object* v___x_1465_; lean_object* v___x_1466_; 
v___x_1465_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__1, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__1);
v___x_1466_ = l_Rat_neg(v___x_1465_);
return v___x_1466_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__5(void){
_start:
{
lean_object* v___x_1467_; lean_object* v___x_1468_; 
v___x_1467_ = lean_unsigned_to_nat(250u);
v___x_1468_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1467_);
return v___x_1468_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPenalty(lean_object* v_register_1469_, lean_object* v_word_1470_){
_start:
{
lean_object* v___y_1474_; uint8_t v___y_1475_; lean_object* v___y_1479_; lean_object* v___y_1480_; lean_object* v___y_1481_; uint8_t v___y_1482_; lean_object* v___y_1487_; lean_object* v___x_1502_; uint8_t v___x_1503_; 
v___x_1502_ = lean_unsigned_to_nat(80u);
v___x_1503_ = lean_nat_dec_eq(v_register_1469_, v___x_1502_);
if (v___x_1503_ == 0)
{
lean_object* v___x_1504_; uint8_t v___x_1505_; 
v___x_1504_ = lean_unsigned_to_nat(96u);
v___x_1505_ = lean_nat_dec_eq(v_register_1469_, v___x_1504_);
if (v___x_1505_ == 0)
{
lean_object* v___x_1506_; 
v___x_1506_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1506_;
}
else
{
lean_object* v___x_1507_; lean_object* v___x_1508_; 
v___x_1507_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__13));
v___x_1508_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1469_, v_word_1470_, v___x_1507_);
if (lean_obj_tag(v___x_1508_) == 1)
{
lean_object* v_val_1509_; lean_object* v___x_1510_; lean_object* v___x_1511_; 
v_val_1509_ = lean_ctor_get(v___x_1508_, 0);
lean_inc(v_val_1509_);
lean_dec_ref_known(v___x_1508_, 1);
v___x_1510_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__14));
v___x_1511_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1469_, v_word_1470_, v___x_1510_);
if (lean_obj_tag(v___x_1511_) == 1)
{
lean_object* v_mach_1512_; lean_object* v___x_1513_; uint8_t v___y_1515_; uint8_t v___x_1517_; uint8_t v___y_1519_; 
lean_dec_ref_known(v___x_1511_, 1);
v_mach_1512_ = lp_lean1090_Lean1090_Impl_cbMach64(v_word_1470_);
v___x_1513_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
lean_inc_ref(v_mach_1512_);
v___x_1517_ = l_Rat_blt(v___x_1513_, v_mach_1512_);
if (v___x_1517_ == 0)
{
lean_dec_ref(v_mach_1512_);
lean_dec(v_val_1509_);
return v___x_1513_;
}
else
{
lean_object* v_ratio_1520_; lean_object* v___x_1521_; uint8_t v___x_1522_; 
v_ratio_1520_ = lp_lean1090_Lean1090_Impl_Binary64_div(v_val_1509_, v_mach_1512_);
lean_dec(v_val_1509_);
v___x_1521_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__5, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__5);
lean_inc_ref(v_ratio_1520_);
v___x_1522_ = l_Rat_blt(v_ratio_1520_, v___x_1521_);
if (v___x_1522_ == 0)
{
lean_object* v___x_1523_; uint8_t v___x_1524_; 
v___x_1523_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__4, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__4);
v___x_1524_ = l_Rat_blt(v___x_1523_, v_ratio_1520_);
v___y_1519_ = v___x_1524_;
goto v___jp_1518_;
}
else
{
lean_dec_ref(v_ratio_1520_);
v___y_1519_ = v___x_1517_;
goto v___jp_1518_;
}
}
v___jp_1514_:
{
if (v___y_1515_ == 0)
{
return v___x_1513_;
}
else
{
lean_object* v___x_1516_; 
v___x_1516_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__4, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__4);
return v___x_1516_;
}
}
v___jp_1518_:
{
if (v___x_1517_ == 0)
{
v___y_1515_ = v___x_1517_;
goto v___jp_1514_;
}
else
{
v___y_1515_ = v___y_1519_;
goto v___jp_1514_;
}
}
}
else
{
lean_dec(v___x_1511_);
lean_dec(v_val_1509_);
goto v___jp_1471_;
}
}
else
{
lean_dec(v___x_1508_);
goto v___jp_1471_;
}
}
}
else
{
lean_object* v___x_1525_; lean_object* v___x_1526_; 
v___x_1525_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__20));
v___x_1526_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1469_, v_word_1470_, v___x_1525_);
if (lean_obj_tag(v___x_1526_) == 1)
{
lean_object* v_val_1527_; lean_object* v___x_1528_; lean_object* v___x_1529_; 
v_val_1527_ = lean_ctor_get(v___x_1526_, 0);
lean_inc(v_val_1527_);
lean_dec_ref_known(v___x_1526_, 1);
v___x_1528_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__21));
v___x_1529_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1469_, v_word_1470_, v___x_1528_);
if (lean_obj_tag(v___x_1529_) == 1)
{
lean_object* v_val_1530_; lean_object* v___x_1531_; lean_object* v___x_1532_; lean_object* v___x_1533_; lean_object* v___x_1534_; lean_object* v___x_1535_; lean_object* v___x_1536_; 
v_val_1530_ = lean_ctor_get(v___x_1529_, 0);
lean_inc(v_val_1530_);
lean_dec_ref_known(v___x_1529_, 1);
v___x_1531_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1532_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_val_1527_, v_val_1530_);
v___x_1533_ = l_Rat_abs(v___x_1532_);
v___x_1534_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__1);
v___x_1535_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1533_, v___x_1534_);
lean_dec_ref(v___x_1533_);
v___x_1536_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v___x_1531_, v___x_1535_);
v___y_1487_ = v___x_1536_;
goto v___jp_1486_;
}
else
{
lean_dec(v___x_1529_);
lean_dec(v_val_1527_);
goto v___jp_1500_;
}
}
else
{
lean_dec(v___x_1526_);
goto v___jp_1500_;
}
}
v___jp_1471_:
{
lean_object* v___x_1472_; 
v___x_1472_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
return v___x_1472_;
}
v___jp_1473_:
{
if (v___y_1475_ == 0)
{
lean_object* v___x_1476_; lean_object* v___x_1477_; 
v___x_1476_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1477_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v___y_1474_, v___x_1476_);
return v___x_1477_;
}
else
{
return v___y_1474_;
}
}
v___jp_1478_:
{
if (v___y_1482_ == 0)
{
lean_dec_ref(v___y_1481_);
lean_dec_ref(v___y_1479_);
return v___y_1480_;
}
else
{
lean_object* v___x_1483_; uint8_t v___x_1484_; uint8_t v___x_1485_; 
v___x_1483_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1484_ = l_Rat_blt(v___x_1483_, v___y_1481_);
v___x_1485_ = l_Rat_blt(v___x_1483_, v___y_1479_);
if (v___x_1485_ == 0)
{
if (v___x_1484_ == 0)
{
return v___y_1480_;
}
else
{
v___y_1474_ = v___y_1480_;
v___y_1475_ = v___x_1485_;
goto v___jp_1473_;
}
}
else
{
v___y_1474_ = v___y_1480_;
v___y_1475_ = v___x_1484_;
goto v___jp_1473_;
}
}
}
v___jp_1486_:
{
lean_object* v___x_1488_; lean_object* v___x_1489_; 
v___x_1488_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__19));
v___x_1489_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1469_, v_word_1470_, v___x_1488_);
if (lean_obj_tag(v___x_1489_) == 1)
{
lean_object* v_val_1490_; lean_object* v___x_1491_; lean_object* v___x_1492_; 
v_val_1490_ = lean_ctor_get(v___x_1489_, 0);
lean_inc(v_val_1490_);
lean_dec_ref_known(v___x_1489_, 1);
v___x_1491_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBValue___closed__4));
v___x_1492_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1469_, v_word_1470_, v___x_1491_);
if (lean_obj_tag(v___x_1492_) == 1)
{
lean_object* v_val_1493_; lean_object* v___x_1494_; lean_object* v___x_1495_; uint8_t v___x_1496_; 
v_val_1493_ = lean_ctor_get(v___x_1492_, 0);
lean_inc(v_val_1493_);
lean_dec_ref_known(v___x_1492_, 1);
v___x_1494_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__0, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__0);
lean_inc(v_val_1490_);
v___x_1495_ = l_Rat_abs(v_val_1490_);
v___x_1496_ = l_Rat_blt(v___x_1494_, v___x_1495_);
if (v___x_1496_ == 0)
{
v___y_1479_ = v_val_1493_;
v___y_1480_ = v___y_1487_;
v___y_1481_ = v_val_1490_;
v___y_1482_ = v___x_1496_;
goto v___jp_1478_;
}
else
{
lean_object* v___x_1497_; lean_object* v___x_1498_; uint8_t v___x_1499_; 
v___x_1497_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__3, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__3);
lean_inc(v_val_1493_);
v___x_1498_ = l_Rat_abs(v_val_1493_);
v___x_1499_ = l_Rat_blt(v___x_1497_, v___x_1498_);
v___y_1479_ = v_val_1493_;
v___y_1480_ = v___y_1487_;
v___y_1481_ = v_val_1490_;
v___y_1482_ = v___x_1499_;
goto v___jp_1478_;
}
}
else
{
lean_dec(v___x_1492_);
lean_dec(v_val_1490_);
return v___y_1487_;
}
}
else
{
lean_dec(v___x_1489_);
return v___y_1487_;
}
}
v___jp_1500_:
{
lean_object* v___x_1501_; 
v___x_1501_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___y_1487_ = v___x_1501_;
goto v___jp_1486_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPenalty___boxed(lean_object* v_register_1537_, lean_object* v_word_1538_){
_start:
{
lean_object* v_res_1539_; 
v_res_1539_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_1537_, v_word_1538_);
lean_dec(v_word_1538_);
lean_dec(v_register_1537_);
return v_res_1539_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCombinedScore(lean_object* v_register_1540_, lean_object* v_word_1541_){
_start:
{
lean_object* v___x_1542_; lean_object* v___x_1543_; lean_object* v___x_1544_; 
v___x_1542_ = lp_lean1090_Lean1090_Impl_cbDensity(v_register_1540_, v_word_1541_);
v___x_1543_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_1540_, v_word_1541_);
v___x_1544_ = lp_lean1090_Lean1090_Impl_Binary64_add(v___x_1542_, v___x_1543_);
return v___x_1544_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbCombinedScore___boxed(lean_object* v_register_1545_, lean_object* v_word_1546_){
_start:
{
lean_object* v_res_1547_; 
v_res_1547_ = lp_lean1090_Lean1090_Impl_cbCombinedScore(v_register_1545_, v_word_1546_);
lean_dec(v_word_1546_);
lean_dec(v_register_1545_);
return v_res_1547_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbQNHScoreTable___lam__0(lean_object* v_code_1548_){
_start:
{
lean_object* v___x_1549_; lean_object* v___x_1550_; lean_object* v___x_1551_; lean_object* v___x_1552_; lean_object* v___x_1553_; lean_object* v___x_1554_; lean_object* v___x_1555_; lean_object* v___x_1556_; 
v___x_1549_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1548_);
v___x_1550_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__3, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__3);
v___x_1551_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1549_, v___x_1550_);
lean_dec_ref(v___x_1549_);
v___x_1552_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__4, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__4);
v___x_1553_ = lp_lean1090_Lean1090_Impl_Binary64_add(v___x_1551_, v___x_1552_);
v___x_1554_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__1);
v___x_1555_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__11___closed__3);
v___x_1556_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1553_, v___x_1554_, v___x_1555_);
return v___x_1556_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1558_; lean_object* v___x_1559_; lean_object* v___x_1560_; 
v___f_1558_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__0));
v___x_1559_ = lean_unsigned_to_nat(4096u);
v___x_1560_ = l_Array_ofFn___redArg(v___x_1559_, v___f_1558_);
return v___x_1560_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable(void){
_start:
{
lean_object* v___x_1561_; 
v___x_1561_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNHScoreTable___closed__1);
return v___x_1561_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0(lean_object* v_code_1562_){
_start:
{
lean_object* v___x_1563_; lean_object* v___x_1564_; lean_object* v___x_1565_; lean_object* v___x_1566_; 
v___x_1563_ = lp_lean1090_Lean1090_Impl_cbSelected(v_code_1562_);
v___x_1564_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__0);
v___x_1565_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__10___closed__1);
v___x_1566_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1563_, v___x_1564_, v___x_1565_);
return v___x_1566_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0___boxed(lean_object* v_code_1567_){
_start:
{
lean_object* v_res_1568_; 
v_res_1568_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___lam__0(v_code_1567_);
lean_dec(v_code_1567_);
return v_res_1568_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1570_; lean_object* v___x_1571_; lean_object* v___x_1572_; 
v___f_1570_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__0));
v___x_1571_ = lean_unsigned_to_nat(4096u);
v___x_1572_ = l_Array_ofFn___redArg(v___x_1571_, v___f_1570_);
return v___x_1572_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable(void){
_start:
{
lean_object* v___x_1573_; 
v___x_1573_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbSelectedScoreTable___closed__1);
return v___x_1573_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1574_; lean_object* v___x_1575_; lean_object* v___x_1576_; 
v___x_1574_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1575_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbValid50___closed__0, &lp_lean1090_Lean1090_Impl_cbValid50___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbValid50___closed__0);
v___x_1576_ = l_Rat_div(v___x_1575_, v___x_1574_);
return v___x_1576_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0(lean_object* v_code_1577_){
_start:
{
uint8_t v___x_1578_; lean_object* v___x_1579_; lean_object* v___x_1580_; lean_object* v___x_1581_; lean_object* v___x_1582_; lean_object* v___x_1583_; lean_object* v___x_1584_; lean_object* v___x_1585_; lean_object* v___x_1586_; 
v___x_1578_ = 1;
v___x_1579_ = lean_unsigned_to_nat(10u);
v___x_1580_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1578_, v___x_1579_, v_code_1577_);
v___x_1581_ = l_Rat_ofInt(v___x_1580_);
v___x_1582_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___lam__0___closed__0);
v___x_1583_ = l_Rat_mul(v___x_1581_, v___x_1582_);
lean_dec_ref(v___x_1581_);
v___x_1584_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1585_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__1, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__1);
v___x_1586_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1583_, v___x_1584_, v___x_1585_);
return v___x_1586_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1588_; lean_object* v___x_1589_; lean_object* v___x_1590_; 
v___f_1588_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__0));
v___x_1589_ = lean_unsigned_to_nat(1024u);
v___x_1590_ = l_Array_ofFn___redArg(v___x_1589_, v___f_1588_);
return v___x_1590_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable(void){
_start:
{
lean_object* v___x_1591_; 
v___x_1591_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRollScoreTable___closed__1);
return v___x_1591_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1592_; lean_object* v___x_1593_; 
v___x_1592_ = lean_unsigned_to_nat(8u);
v___x_1593_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1592_);
return v___x_1593_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1(void){
_start:
{
lean_object* v___x_1594_; lean_object* v___x_1595_; lean_object* v___x_1596_; 
v___x_1594_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1595_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__0);
v___x_1596_ = l_Rat_div(v___x_1595_, v___x_1594_);
return v___x_1596_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0(lean_object* v_code_1597_){
_start:
{
uint8_t v___x_1598_; lean_object* v___x_1599_; lean_object* v___x_1600_; lean_object* v___x_1601_; lean_object* v___x_1602_; lean_object* v___x_1603_; lean_object* v___x_1604_; lean_object* v___x_1605_; lean_object* v___x_1606_; 
v___x_1598_ = 1;
v___x_1599_ = lean_unsigned_to_nat(10u);
v___x_1600_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1598_, v___x_1599_, v_code_1597_);
v___x_1601_ = l_Rat_ofInt(v___x_1600_);
v___x_1602_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___lam__0___closed__1);
v___x_1603_ = l_Rat_mul(v___x_1601_, v___x_1602_);
lean_dec_ref(v___x_1601_);
v___x_1604_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___x_1605_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__8___closed__1);
v___x_1606_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1603_, v___x_1604_, v___x_1605_);
return v___x_1606_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1608_; lean_object* v___x_1609_; lean_object* v___x_1610_; 
v___f_1608_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__0));
v___x_1609_ = lean_unsigned_to_nat(1024u);
v___x_1610_ = l_Array_ofFn___redArg(v___x_1609_, v___f_1608_);
return v___x_1610_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable(void){
_start:
{
lean_object* v___x_1611_; 
v___x_1611_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbRateScoreTable___closed__1);
return v___x_1611_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTASScoreTable___lam__0(lean_object* v_code_1612_){
_start:
{
lean_object* v___x_1613_; lean_object* v___x_1614_; lean_object* v___x_1615_; lean_object* v___x_1616_; lean_object* v___x_1617_; lean_object* v___x_1618_; 
v___x_1613_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1612_);
v___x_1614_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1615_ = l_Rat_mul(v___x_1613_, v___x_1614_);
lean_dec_ref(v___x_1613_);
v___x_1616_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__0);
v___x_1617_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__7___closed__1);
v___x_1618_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1615_, v___x_1616_, v___x_1617_);
return v___x_1618_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1620_; lean_object* v___x_1621_; lean_object* v___x_1622_; 
v___f_1620_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__0));
v___x_1621_ = lean_unsigned_to_nat(1024u);
v___x_1622_ = l_Array_ofFn___redArg(v___x_1621_, v___f_1620_);
return v___x_1622_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable(void){
_start:
{
lean_object* v___x_1623_; 
v___x_1623_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTASScoreTable___closed__1);
return v___x_1623_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___lam__0(lean_object* v_code_1624_){
_start:
{
lean_object* v___x_1625_; lean_object* v___x_1626_; lean_object* v___x_1627_; lean_object* v___x_1628_; lean_object* v___x_1629_; lean_object* v___x_1630_; 
v___x_1625_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1624_);
v___x_1626_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGaussian___closed__1, &lp_lean1090_Lean1090_Impl_cbGaussian___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGaussian___closed__1);
v___x_1627_ = l_Rat_mul(v___x_1625_, v___x_1626_);
lean_dec_ref(v___x_1625_);
v___x_1628_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__0);
v___x_1629_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__6___closed__1);
v___x_1630_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1627_, v___x_1628_, v___x_1629_);
return v___x_1630_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1632_; lean_object* v___x_1633_; lean_object* v___x_1634_; 
v___f_1632_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__0));
v___x_1633_ = lean_unsigned_to_nat(1024u);
v___x_1634_ = l_Array_ofFn___redArg(v___x_1633_, v___f_1632_);
return v___x_1634_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable(void){
_start:
{
lean_object* v___x_1635_; 
v___x_1635_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable___closed__1);
return v___x_1635_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbIASScoreTable___lam__0(lean_object* v_code_1636_){
_start:
{
lean_object* v___x_1637_; lean_object* v___x_1638_; lean_object* v___x_1639_; lean_object* v___x_1640_; 
v___x_1637_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1636_);
v___x_1638_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__0);
v___x_1639_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__4___closed__1);
v___x_1640_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1637_, v___x_1638_, v___x_1639_);
return v___x_1640_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1642_; lean_object* v___x_1643_; lean_object* v___x_1644_; 
v___f_1642_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__0));
v___x_1643_ = lean_unsigned_to_nat(1024u);
v___x_1644_ = l_Array_ofFn___redArg(v___x_1643_, v___f_1642_);
return v___x_1644_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable(void){
_start:
{
lean_object* v___x_1645_; 
v___x_1645_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbIASScoreTable___closed__1);
return v___x_1645_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbMachScoreTable___lam__0(lean_object* v_code_1646_){
_start:
{
lean_object* v___x_1647_; lean_object* v___x_1648_; lean_object* v___x_1649_; lean_object* v___x_1650_; lean_object* v___x_1651_; lean_object* v___x_1652_; lean_object* v___x_1653_; lean_object* v___x_1654_; 
v___x_1647_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1646_);
v___x_1648_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMach64___closed__2, &lp_lean1090_Lean1090_Impl_cbMach64___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbMach64___closed__2);
v___x_1649_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v___x_1647_, v___x_1648_);
lean_dec_ref(v___x_1647_);
v___x_1650_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMach64___closed__3, &lp_lean1090_Lean1090_Impl_cbMach64___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbMach64___closed__3);
v___x_1651_ = lp_lean1090_Lean1090_Impl_Binary64_div(v___x_1649_, v___x_1650_);
lean_dec_ref(v___x_1649_);
v___x_1652_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__2);
v___x_1653_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__3___closed__4);
v___x_1654_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1651_, v___x_1652_, v___x_1653_);
return v___x_1654_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1656_; lean_object* v___x_1657_; lean_object* v___x_1658_; 
v___f_1656_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__0));
v___x_1657_ = lean_unsigned_to_nat(1024u);
v___x_1658_ = l_Array_ofFn___redArg(v___x_1657_, v___f_1656_);
return v___x_1658_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable(void){
_start:
{
lean_object* v___x_1659_; 
v___x_1659_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbMachScoreTable___closed__1);
return v___x_1659_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___lam__0(lean_object* v_code_1660_){
_start:
{
lean_object* v___y_1662_; lean_object* v___x_1666_; lean_object* v___x_1667_; lean_object* v___x_1668_; uint8_t v___x_1671_; 
v___x_1666_ = lean_unsigned_to_nat(512u);
v___x_1667_ = lean_nat_mod(v_code_1660_, v___x_1666_);
v___x_1668_ = lean_unsigned_to_nat(0u);
v___x_1671_ = lean_nat_dec_eq(v___x_1667_, v___x_1668_);
if (v___x_1671_ == 0)
{
lean_object* v___x_1672_; uint8_t v___x_1673_; 
v___x_1672_ = lean_unsigned_to_nat(511u);
v___x_1673_ = lean_nat_dec_eq(v___x_1667_, v___x_1672_);
lean_dec(v___x_1667_);
if (v___x_1673_ == 0)
{
uint8_t v___x_1674_; lean_object* v___x_1675_; lean_object* v___x_1676_; lean_object* v___x_1677_; lean_object* v___x_1678_; lean_object* v___x_1679_; 
v___x_1674_ = 1;
v___x_1675_ = lean_unsigned_to_nat(10u);
v___x_1676_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1674_, v___x_1675_, v_code_1660_);
v___x_1677_ = l_Rat_ofInt(v___x_1676_);
v___x_1678_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__0, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__0);
v___x_1679_ = l_Rat_mul(v___x_1677_, v___x_1678_);
lean_dec_ref(v___x_1677_);
v___y_1662_ = v___x_1679_;
goto v___jp_1661_;
}
else
{
lean_dec(v_code_1660_);
goto v___jp_1669_;
}
}
else
{
lean_dec(v___x_1667_);
lean_dec(v_code_1660_);
goto v___jp_1669_;
}
v___jp_1661_:
{
lean_object* v___x_1663_; lean_object* v___x_1664_; lean_object* v___x_1665_; 
v___x_1663_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__1);
v___x_1664_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__5___closed__2);
v___x_1665_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___y_1662_, v___x_1663_, v___x_1664_);
return v___x_1665_;
}
v___jp_1669_:
{
lean_object* v___x_1670_; 
v___x_1670_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVertical60___closed__1, &lp_lean1090_Lean1090_Impl_cbVertical60___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVertical60___closed__1);
v___y_1662_ = v___x_1670_;
goto v___jp_1661_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1681_; lean_object* v___x_1682_; lean_object* v___x_1683_; 
v___f_1681_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__0));
v___x_1682_ = lean_unsigned_to_nat(1024u);
v___x_1683_ = l_Array_ofFn___redArg(v___x_1682_, v___f_1681_);
return v___x_1683_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable(void){
_start:
{
lean_object* v___x_1684_; 
v___x_1684_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbVerticalScoreTable___closed__1);
return v___x_1684_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___lam__0(lean_object* v_code_1685_){
_start:
{
lean_object* v___y_1687_; uint8_t v___x_1691_; lean_object* v___x_1692_; lean_object* v___x_1693_; lean_object* v___x_1694_; lean_object* v___x_1695_; lean_object* v_initial_1696_; lean_object* v___x_1697_; uint8_t v___x_1698_; 
v___x_1691_ = 1;
v___x_1692_ = lean_unsigned_to_nat(11u);
v___x_1693_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1691_, v___x_1692_, v_code_1685_);
v___x_1694_ = l_Rat_ofInt(v___x_1693_);
v___x_1695_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v_initial_1696_ = l_Rat_div(v___x_1694_, v___x_1695_);
lean_dec_ref(v___x_1694_);
v___x_1697_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__2);
lean_inc_ref(v_initial_1696_);
v___x_1698_ = l_Rat_blt(v_initial_1696_, v___x_1697_);
if (v___x_1698_ == 0)
{
v___y_1687_ = v_initial_1696_;
goto v___jp_1686_;
}
else
{
lean_object* v___x_1699_; lean_object* v___x_1700_; 
v___x_1699_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__3);
v___x_1700_ = l_Rat_add(v_initial_1696_, v___x_1699_);
v___y_1687_ = v___x_1700_;
goto v___jp_1686_;
}
v___jp_1686_:
{
lean_object* v___x_1688_; lean_object* v___x_1689_; lean_object* v___x_1690_; 
v___x_1688_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__5);
v___x_1689_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7, &lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___closed__7);
v___x_1690_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___y_1687_, v___x_1688_, v___x_1689_);
return v___x_1690_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1702_; lean_object* v___x_1703_; lean_object* v___x_1704_; 
v___f_1702_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__0));
v___x_1703_ = lean_unsigned_to_nat(2048u);
v___x_1704_ = l_Array_ofFn___redArg(v___x_1703_, v___f_1702_);
return v___x_1704_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable(void){
_start:
{
lean_object* v___x_1705_; 
v___x_1705_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable___closed__1);
return v___x_1705_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbWindScoreTable___lam__0(lean_object* v_code_1706_){
_start:
{
lean_object* v___x_1707_; lean_object* v___x_1708_; lean_object* v___x_1709_; lean_object* v___x_1710_; 
v___x_1707_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1706_);
v___x_1708_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__0);
v___x_1709_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__2___closed__1);
v___x_1710_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1707_, v___x_1708_, v___x_1709_);
return v___x_1710_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1712_; lean_object* v___x_1713_; lean_object* v___x_1714_; 
v___f_1712_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__0));
v___x_1713_ = lean_unsigned_to_nat(512u);
v___x_1714_ = l_Array_ofFn___redArg(v___x_1713_, v___f_1712_);
return v___x_1714_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable(void){
_start:
{
lean_object* v___x_1715_; 
v___x_1715_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbWindScoreTable___closed__1);
return v___x_1715_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbPressureScoreTable___lam__0(lean_object* v_code_1716_){
_start:
{
lean_object* v___x_1717_; lean_object* v___x_1718_; lean_object* v___x_1719_; lean_object* v___x_1720_; 
v___x_1717_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_code_1716_);
v___x_1718_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__0);
v___x_1719_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__1___closed__1);
v___x_1720_ = lp_lean1090_Lean1090_Impl_cbLaplace(v___x_1717_, v___x_1718_, v___x_1719_);
return v___x_1720_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1722_; lean_object* v___x_1723_; lean_object* v___x_1724_; 
v___f_1722_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__0));
v___x_1723_ = lean_unsigned_to_nat(2048u);
v___x_1724_ = l_Array_ofFn___redArg(v___x_1723_, v___f_1722_);
return v___x_1724_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable(void){
_start:
{
lean_object* v___x_1725_; 
v___x_1725_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbPressureScoreTable___closed__1);
return v___x_1725_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_1726_; lean_object* v___x_1727_; lean_object* v___x_1728_; 
v___x_1726_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature44___closed__0);
v___x_1727_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbQNH64___closed__0, &lp_lean1090_Lean1090_Impl_cbQNH64___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbQNH64___closed__0);
v___x_1728_ = l_Rat_div(v___x_1727_, v___x_1726_);
return v___x_1728_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0(lean_object* v_code_1729_){
_start:
{
uint8_t v___x_1730_; lean_object* v___x_1731_; lean_object* v___x_1732_; lean_object* v___x_1733_; lean_object* v___x_1734_; lean_object* v___x_1735_; lean_object* v___x_1736_; lean_object* v___x_1737_; lean_object* v___x_1738_; 
v___x_1730_ = 1;
v___x_1731_ = lean_unsigned_to_nat(10u);
v___x_1732_ = lp_lean1090_Lean1090_Impl_payloadInteger(v___x_1730_, v___x_1731_, v_code_1729_);
v___x_1733_ = l_Rat_ofInt(v___x_1732_);
v___x_1734_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___lam__0___closed__0);
v___x_1735_ = l_Rat_mul(v___x_1733_, v___x_1734_);
lean_dec_ref(v___x_1733_);
v___x_1736_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__2);
v___x_1737_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4, &lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbDensityTerms___lam__0___closed__4);
v___x_1738_ = lp_lean1090_Lean1090_Impl_cbGaussian(v___x_1735_, v___x_1736_, v___x_1737_);
return v___x_1738_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1(void){
_start:
{
lean_object* v___f_1740_; lean_object* v___x_1741_; lean_object* v___x_1742_; 
v___f_1740_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__0));
v___x_1741_ = lean_unsigned_to_nat(1024u);
v___x_1742_ = l_Array_ofFn___redArg(v___x_1741_, v___f_1740_);
return v___x_1742_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable(void){
_start:
{
lean_object* v___x_1743_; 
v___x_1743_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1, &lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable___closed__1);
return v___x_1743_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg(lean_object* v_width_1744_, lean_object* v_table_1745_, lean_object* v_word_1746_, lean_object* v_start_1747_){
_start:
{
lean_object* v___x_1748_; lean_object* v___x_1749_; 
v___x_1748_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1746_, v_start_1747_, v_width_1744_);
v___x_1749_ = lean_array_fget_borrowed(v_table_1745_, v___x_1748_);
lean_dec(v___x_1748_);
lean_inc(v___x_1749_);
return v___x_1749_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg___boxed(lean_object* v_width_1750_, lean_object* v_table_1751_, lean_object* v_word_1752_, lean_object* v_start_1753_){
_start:
{
lean_object* v_res_1754_; 
v_res_1754_ = lp_lean1090_Lean1090_Impl_cbDensityTableGet___redArg(v_width_1750_, v_table_1751_, v_word_1752_, v_start_1753_);
lean_dec(v_start_1753_);
lean_dec(v_word_1752_);
lean_dec_ref(v_table_1751_);
lean_dec(v_width_1750_);
return v_res_1754_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet(lean_object* v_width_1755_, lean_object* v_table_1756_, lean_object* v_size_1757_, lean_object* v_word_1758_, lean_object* v_start_1759_){
_start:
{
lean_object* v___x_1760_; lean_object* v___x_1761_; 
v___x_1760_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1758_, v_start_1759_, v_width_1755_);
v___x_1761_ = lean_array_fget_borrowed(v_table_1756_, v___x_1760_);
lean_dec(v___x_1760_);
lean_inc(v___x_1761_);
return v___x_1761_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTableGet___boxed(lean_object* v_width_1762_, lean_object* v_table_1763_, lean_object* v_size_1764_, lean_object* v_word_1765_, lean_object* v_start_1766_){
_start:
{
lean_object* v_res_1767_; 
v_res_1767_ = lp_lean1090_Lean1090_Impl_cbDensityTableGet(v_width_1762_, v_table_1763_, v_size_1764_, v_word_1765_, v_start_1766_);
lean_dec(v_start_1766_);
lean_dec(v_word_1765_);
lean_dec_ref(v_table_1763_);
lean_dec(v_width_1762_);
return v_res_1767_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTermsFast(lean_object* v_register_1768_, lean_object* v_word_1769_){
_start:
{
lean_object* v___x_1770_; uint8_t v___x_1771_; 
v___x_1770_ = lean_unsigned_to_nat(64u);
v___x_1771_ = lean_nat_dec_eq(v_register_1768_, v___x_1770_);
if (v___x_1771_ == 0)
{
lean_object* v___x_1772_; uint8_t v___x_1773_; 
v___x_1772_ = lean_unsigned_to_nat(80u);
v___x_1773_ = lean_nat_dec_eq(v_register_1768_, v___x_1772_);
if (v___x_1773_ == 0)
{
lean_object* v___x_1774_; uint8_t v___x_1775_; 
v___x_1774_ = lean_unsigned_to_nat(96u);
v___x_1775_ = lean_nat_dec_eq(v_register_1768_, v___x_1774_);
if (v___x_1775_ == 0)
{
lean_object* v___x_1776_; uint8_t v___x_1777_; 
v___x_1776_ = lean_unsigned_to_nat(68u);
v___x_1777_ = lean_nat_dec_eq(v_register_1768_, v___x_1776_);
if (v___x_1777_ == 0)
{
lean_object* v___x_1778_; uint8_t v___x_1779_; 
v___x_1778_ = lean_unsigned_to_nat(69u);
v___x_1779_ = lean_nat_dec_eq(v_register_1768_, v___x_1778_);
if (v___x_1779_ == 0)
{
lean_object* v___x_1780_; 
v___x_1780_ = lean_box(0);
return v___x_1780_;
}
else
{
lean_object* v___x_1781_; lean_object* v___x_1782_; lean_object* v___x_1783_; lean_object* v___x_1784_; lean_object* v___y_1786_; uint8_t v___x_1800_; 
v___x_1781_ = lean_unsigned_to_nat(16u);
v___x_1782_ = lean_unsigned_to_nat(1u);
v___x_1783_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1781_, v___x_1782_);
v___x_1784_ = lean_unsigned_to_nat(0u);
v___x_1800_ = lean_nat_dec_eq(v___x_1783_, v___x_1784_);
lean_dec(v___x_1783_);
if (v___x_1800_ == 0)
{
lean_object* v___x_1801_; lean_object* v___x_1802_; lean_object* v___x_1803_; lean_object* v___x_1804_; lean_object* v___x_1805_; lean_object* v___x_1806_; lean_object* v___x_1807_; 
v___x_1801_ = lean_unsigned_to_nat(10u);
v___x_1802_ = lp_lean1090_Lean1090_Impl_cbTemperature45ScoreTable;
v___x_1803_ = lean_unsigned_to_nat(17u);
v___x_1804_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1803_, v___x_1801_);
v___x_1805_ = lean_array_fget_borrowed(v___x_1802_, v___x_1804_);
lean_dec(v___x_1804_);
v___x_1806_ = lean_box(0);
lean_inc(v___x_1805_);
v___x_1807_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1807_, 0, v___x_1805_);
lean_ctor_set(v___x_1807_, 1, v___x_1806_);
v___y_1786_ = v___x_1807_;
goto v___jp_1785_;
}
else
{
lean_object* v___x_1808_; 
v___x_1808_ = lean_box(0);
v___y_1786_ = v___x_1808_;
goto v___jp_1785_;
}
v___jp_1785_:
{
lean_object* v___x_1787_; lean_object* v___x_1788_; uint8_t v___x_1789_; 
v___x_1787_ = lean_unsigned_to_nat(27u);
v___x_1788_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1787_, v___x_1782_);
v___x_1789_ = lean_nat_dec_eq(v___x_1788_, v___x_1784_);
lean_dec(v___x_1788_);
if (v___x_1789_ == 0)
{
lean_object* v___x_1790_; lean_object* v___x_1791_; lean_object* v___x_1792_; lean_object* v___x_1793_; lean_object* v___x_1794_; lean_object* v___x_1795_; lean_object* v___x_1796_; lean_object* v___x_1797_; 
v___x_1790_ = lean_unsigned_to_nat(11u);
v___x_1791_ = lp_lean1090_Lean1090_Impl_cbPressureScoreTable;
v___x_1792_ = lean_unsigned_to_nat(28u);
v___x_1793_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1792_, v___x_1790_);
v___x_1794_ = lean_array_fget_borrowed(v___x_1791_, v___x_1793_);
lean_dec(v___x_1793_);
v___x_1795_ = lean_box(0);
lean_inc(v___x_1794_);
v___x_1796_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1796_, 0, v___x_1794_);
lean_ctor_set(v___x_1796_, 1, v___x_1795_);
v___x_1797_ = l_List_appendTR___redArg(v___y_1786_, v___x_1796_);
return v___x_1797_;
}
else
{
lean_object* v___x_1798_; lean_object* v___x_1799_; 
v___x_1798_ = lean_box(0);
v___x_1799_ = l_List_appendTR___redArg(v___y_1786_, v___x_1798_);
return v___x_1799_;
}
}
}
}
else
{
lean_object* v___x_1809_; lean_object* v___x_1810_; lean_object* v___x_1811_; lean_object* v___x_1812_; lean_object* v___x_1813_; lean_object* v___x_1814_; lean_object* v___x_1815_; lean_object* v___x_1816_; lean_object* v___x_1817_; lean_object* v___x_1818_; lean_object* v___x_1819_; lean_object* v___y_1821_; uint8_t v___x_1833_; 
v___x_1809_ = lean_unsigned_to_nat(11u);
v___x_1810_ = lp_lean1090_Lean1090_Impl_cbTemperature44ScoreTable;
v___x_1811_ = lean_unsigned_to_nat(24u);
v___x_1812_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1811_, v___x_1809_);
v___x_1813_ = lean_array_fget_borrowed(v___x_1810_, v___x_1812_);
lean_dec(v___x_1812_);
v___x_1814_ = lean_box(0);
lean_inc(v___x_1813_);
v___x_1815_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1815_, 0, v___x_1813_);
lean_ctor_set(v___x_1815_, 1, v___x_1814_);
v___x_1816_ = lean_unsigned_to_nat(5u);
v___x_1817_ = lean_unsigned_to_nat(1u);
v___x_1818_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1816_, v___x_1817_);
v___x_1819_ = lean_unsigned_to_nat(0u);
v___x_1833_ = lean_nat_dec_eq(v___x_1818_, v___x_1819_);
lean_dec(v___x_1818_);
if (v___x_1833_ == 0)
{
lean_object* v___x_1834_; lean_object* v___x_1835_; lean_object* v___x_1836_; lean_object* v___x_1837_; lean_object* v___x_1838_; lean_object* v___x_1839_; 
v___x_1834_ = lean_unsigned_to_nat(9u);
v___x_1835_ = lp_lean1090_Lean1090_Impl_cbWindScoreTable;
v___x_1836_ = lean_unsigned_to_nat(6u);
v___x_1837_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1836_, v___x_1834_);
v___x_1838_ = lean_array_fget_borrowed(v___x_1835_, v___x_1837_);
lean_dec(v___x_1837_);
lean_inc(v___x_1838_);
v___x_1839_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1839_, 0, v___x_1838_);
lean_ctor_set(v___x_1839_, 1, v___x_1814_);
v___y_1821_ = v___x_1839_;
goto v___jp_1820_;
}
else
{
v___y_1821_ = v___x_1814_;
goto v___jp_1820_;
}
v___jp_1820_:
{
lean_object* v___x_1822_; lean_object* v___x_1823_; lean_object* v___x_1824_; uint8_t v___x_1825_; 
v___x_1822_ = l_List_appendTR___redArg(v___x_1815_, v___y_1821_);
v___x_1823_ = lean_unsigned_to_nat(35u);
v___x_1824_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1823_, v___x_1817_);
v___x_1825_ = lean_nat_dec_eq(v___x_1824_, v___x_1819_);
lean_dec(v___x_1824_);
if (v___x_1825_ == 0)
{
lean_object* v___x_1826_; lean_object* v___x_1827_; lean_object* v___x_1828_; lean_object* v___x_1829_; lean_object* v___x_1830_; lean_object* v___x_1831_; 
v___x_1826_ = lp_lean1090_Lean1090_Impl_cbPressureScoreTable;
v___x_1827_ = lean_unsigned_to_nat(36u);
v___x_1828_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1827_, v___x_1809_);
v___x_1829_ = lean_array_fget_borrowed(v___x_1826_, v___x_1828_);
lean_dec(v___x_1828_);
lean_inc(v___x_1829_);
v___x_1830_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1830_, 0, v___x_1829_);
lean_ctor_set(v___x_1830_, 1, v___x_1814_);
v___x_1831_ = l_List_appendTR___redArg(v___x_1822_, v___x_1830_);
return v___x_1831_;
}
else
{
lean_object* v___x_1832_; 
v___x_1832_ = l_List_appendTR___redArg(v___x_1822_, v___x_1814_);
return v___x_1832_;
}
}
}
}
else
{
lean_object* v___x_1840_; lean_object* v___x_1841_; lean_object* v___x_1842_; lean_object* v___x_1843_; lean_object* v___y_1845_; lean_object* v___y_1846_; lean_object* v___y_1862_; uint8_t v___x_1874_; 
v___x_1840_ = lean_unsigned_to_nat(13u);
v___x_1841_ = lean_unsigned_to_nat(1u);
v___x_1842_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1840_, v___x_1841_);
v___x_1843_ = lean_unsigned_to_nat(0u);
v___x_1874_ = lean_nat_dec_eq(v___x_1842_, v___x_1843_);
lean_dec(v___x_1842_);
if (v___x_1874_ == 0)
{
lean_object* v___x_1875_; lean_object* v___x_1876_; lean_object* v___x_1877_; lean_object* v___x_1878_; lean_object* v___x_1879_; lean_object* v___x_1880_; lean_object* v___x_1881_; 
v___x_1875_ = lean_unsigned_to_nat(10u);
v___x_1876_ = lp_lean1090_Lean1090_Impl_cbIASScoreTable;
v___x_1877_ = lean_unsigned_to_nat(14u);
v___x_1878_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1877_, v___x_1875_);
v___x_1879_ = lean_array_fget_borrowed(v___x_1876_, v___x_1878_);
lean_dec(v___x_1878_);
v___x_1880_ = lean_box(0);
lean_inc(v___x_1879_);
v___x_1881_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1881_, 0, v___x_1879_);
lean_ctor_set(v___x_1881_, 1, v___x_1880_);
v___y_1862_ = v___x_1881_;
goto v___jp_1861_;
}
else
{
lean_object* v___x_1882_; 
v___x_1882_ = lean_box(0);
v___y_1862_ = v___x_1882_;
goto v___jp_1861_;
}
v___jp_1844_:
{
lean_object* v___x_1847_; lean_object* v___x_1848_; lean_object* v___x_1849_; uint8_t v___x_1850_; 
v___x_1847_ = l_List_appendTR___redArg(v___y_1845_, v___y_1846_);
v___x_1848_ = lean_unsigned_to_nat(46u);
v___x_1849_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1848_, v___x_1841_);
v___x_1850_ = lean_nat_dec_eq(v___x_1849_, v___x_1843_);
lean_dec(v___x_1849_);
if (v___x_1850_ == 0)
{
lean_object* v___x_1851_; lean_object* v___x_1852_; lean_object* v___x_1853_; lean_object* v___x_1854_; lean_object* v___x_1855_; lean_object* v___x_1856_; lean_object* v___x_1857_; lean_object* v___x_1858_; 
v___x_1851_ = lean_unsigned_to_nat(10u);
v___x_1852_ = lp_lean1090_Lean1090_Impl_cbVerticalScoreTable;
v___x_1853_ = lean_unsigned_to_nat(47u);
v___x_1854_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1853_, v___x_1851_);
v___x_1855_ = lean_array_fget_borrowed(v___x_1852_, v___x_1854_);
lean_dec(v___x_1854_);
v___x_1856_ = lean_box(0);
lean_inc(v___x_1855_);
v___x_1857_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1857_, 0, v___x_1855_);
lean_ctor_set(v___x_1857_, 1, v___x_1856_);
v___x_1858_ = l_List_appendTR___redArg(v___x_1847_, v___x_1857_);
return v___x_1858_;
}
else
{
lean_object* v___x_1859_; lean_object* v___x_1860_; 
v___x_1859_ = lean_box(0);
v___x_1860_ = l_List_appendTR___redArg(v___x_1847_, v___x_1859_);
return v___x_1860_;
}
}
v___jp_1861_:
{
lean_object* v___x_1863_; lean_object* v___x_1864_; uint8_t v___x_1865_; 
v___x_1863_ = lean_unsigned_to_nat(24u);
v___x_1864_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1863_, v___x_1841_);
v___x_1865_ = lean_nat_dec_eq(v___x_1864_, v___x_1843_);
lean_dec(v___x_1864_);
if (v___x_1865_ == 0)
{
lean_object* v___x_1866_; lean_object* v___x_1867_; lean_object* v___x_1868_; lean_object* v___x_1869_; lean_object* v___x_1870_; lean_object* v___x_1871_; lean_object* v___x_1872_; 
v___x_1866_ = lean_unsigned_to_nat(10u);
v___x_1867_ = lp_lean1090_Lean1090_Impl_cbMachScoreTable;
v___x_1868_ = lean_unsigned_to_nat(25u);
v___x_1869_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1868_, v___x_1866_);
v___x_1870_ = lean_array_fget_borrowed(v___x_1867_, v___x_1869_);
lean_dec(v___x_1869_);
v___x_1871_ = lean_box(0);
lean_inc(v___x_1870_);
v___x_1872_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1872_, 0, v___x_1870_);
lean_ctor_set(v___x_1872_, 1, v___x_1871_);
v___y_1845_ = v___y_1862_;
v___y_1846_ = v___x_1872_;
goto v___jp_1844_;
}
else
{
lean_object* v___x_1873_; 
v___x_1873_ = lean_box(0);
v___y_1845_ = v___y_1862_;
v___y_1846_ = v___x_1873_;
goto v___jp_1844_;
}
}
}
}
else
{
lean_object* v___x_1883_; lean_object* v___x_1884_; lean_object* v___x_1885_; lean_object* v___y_1887_; lean_object* v___y_1888_; lean_object* v___y_1904_; lean_object* v___y_1905_; lean_object* v___y_1919_; lean_object* v___y_1922_; uint8_t v___x_1938_; 
v___x_1883_ = lean_unsigned_to_nat(1u);
v___x_1884_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1883_, v___x_1883_);
v___x_1885_ = lean_unsigned_to_nat(0u);
v___x_1938_ = lean_nat_dec_eq(v___x_1884_, v___x_1885_);
lean_dec(v___x_1884_);
if (v___x_1938_ == 0)
{
lean_object* v___x_1939_; lean_object* v___x_1940_; lean_object* v___x_1941_; lean_object* v___x_1942_; lean_object* v___x_1943_; lean_object* v___x_1944_; lean_object* v___x_1945_; 
v___x_1939_ = lean_unsigned_to_nat(10u);
v___x_1940_ = lp_lean1090_Lean1090_Impl_cbRollScoreTable;
v___x_1941_ = lean_unsigned_to_nat(2u);
v___x_1942_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1941_, v___x_1939_);
v___x_1943_ = lean_array_fget_borrowed(v___x_1940_, v___x_1942_);
lean_dec(v___x_1942_);
v___x_1944_ = lean_box(0);
lean_inc(v___x_1943_);
v___x_1945_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1945_, 0, v___x_1943_);
lean_ctor_set(v___x_1945_, 1, v___x_1944_);
v___y_1922_ = v___x_1945_;
goto v___jp_1921_;
}
else
{
lean_object* v___x_1946_; 
v___x_1946_ = lean_box(0);
v___y_1922_ = v___x_1946_;
goto v___jp_1921_;
}
v___jp_1886_:
{
lean_object* v___x_1889_; lean_object* v___x_1890_; lean_object* v___x_1891_; uint8_t v___x_1892_; 
v___x_1889_ = l_List_appendTR___redArg(v___y_1887_, v___y_1888_);
v___x_1890_ = lean_unsigned_to_nat(24u);
v___x_1891_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1890_, v___x_1883_);
v___x_1892_ = lean_nat_dec_eq(v___x_1891_, v___x_1885_);
lean_dec(v___x_1891_);
if (v___x_1892_ == 0)
{
lean_object* v___x_1893_; lean_object* v___x_1894_; lean_object* v___x_1895_; lean_object* v___x_1896_; lean_object* v___x_1897_; lean_object* v___x_1898_; lean_object* v___x_1899_; lean_object* v___x_1900_; 
v___x_1893_ = lean_unsigned_to_nat(10u);
v___x_1894_ = lp_lean1090_Lean1090_Impl_cbGroundSpeedScoreTable;
v___x_1895_ = lean_unsigned_to_nat(25u);
v___x_1896_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1895_, v___x_1893_);
v___x_1897_ = lean_array_fget_borrowed(v___x_1894_, v___x_1896_);
lean_dec(v___x_1896_);
v___x_1898_ = lean_box(0);
lean_inc(v___x_1897_);
v___x_1899_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1899_, 0, v___x_1897_);
lean_ctor_set(v___x_1899_, 1, v___x_1898_);
v___x_1900_ = l_List_appendTR___redArg(v___x_1889_, v___x_1899_);
return v___x_1900_;
}
else
{
lean_object* v___x_1901_; lean_object* v___x_1902_; 
v___x_1901_ = lean_box(0);
v___x_1902_ = l_List_appendTR___redArg(v___x_1889_, v___x_1901_);
return v___x_1902_;
}
}
v___jp_1903_:
{
lean_object* v___x_1906_; lean_object* v___x_1907_; lean_object* v___x_1908_; uint8_t v___x_1909_; 
v___x_1906_ = l_List_appendTR___redArg(v___y_1904_, v___y_1905_);
v___x_1907_ = lean_unsigned_to_nat(46u);
v___x_1908_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1907_, v___x_1883_);
v___x_1909_ = lean_nat_dec_eq(v___x_1908_, v___x_1885_);
lean_dec(v___x_1908_);
if (v___x_1909_ == 0)
{
lean_object* v___x_1910_; lean_object* v___x_1911_; lean_object* v___x_1912_; lean_object* v___x_1913_; lean_object* v___x_1914_; lean_object* v___x_1915_; lean_object* v___x_1916_; 
v___x_1910_ = lean_unsigned_to_nat(10u);
v___x_1911_ = lp_lean1090_Lean1090_Impl_cbTASScoreTable;
v___x_1912_ = lean_unsigned_to_nat(47u);
v___x_1913_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1912_, v___x_1910_);
v___x_1914_ = lean_array_fget_borrowed(v___x_1911_, v___x_1913_);
lean_dec(v___x_1913_);
v___x_1915_ = lean_box(0);
lean_inc(v___x_1914_);
v___x_1916_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1916_, 0, v___x_1914_);
lean_ctor_set(v___x_1916_, 1, v___x_1915_);
v___y_1887_ = v___x_1906_;
v___y_1888_ = v___x_1916_;
goto v___jp_1886_;
}
else
{
lean_object* v___x_1917_; 
v___x_1917_ = lean_box(0);
v___y_1887_ = v___x_1906_;
v___y_1888_ = v___x_1917_;
goto v___jp_1886_;
}
}
v___jp_1918_:
{
lean_object* v___x_1920_; 
v___x_1920_ = lean_box(0);
v___y_1904_ = v___y_1919_;
v___y_1905_ = v___x_1920_;
goto v___jp_1903_;
}
v___jp_1921_:
{
lean_object* v___x_1923_; lean_object* v___x_1924_; uint8_t v___x_1925_; 
v___x_1923_ = lean_unsigned_to_nat(35u);
v___x_1924_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1923_, v___x_1883_);
v___x_1925_ = lean_nat_dec_eq(v___x_1924_, v___x_1885_);
lean_dec(v___x_1924_);
if (v___x_1925_ == 0)
{
lean_object* v___x_1926_; lean_object* v___x_1927_; lean_object* v___x_1928_; lean_object* v___x_1929_; uint8_t v___x_1930_; 
v___x_1926_ = lean_unsigned_to_nat(37u);
v___x_1927_ = lean_unsigned_to_nat(9u);
v___x_1928_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1926_, v___x_1927_);
v___x_1929_ = lean_unsigned_to_nat(511u);
v___x_1930_ = lean_nat_dec_eq(v___x_1928_, v___x_1929_);
lean_dec(v___x_1928_);
if (v___x_1930_ == 0)
{
lean_object* v___x_1931_; lean_object* v___x_1932_; lean_object* v___x_1933_; lean_object* v___x_1934_; lean_object* v___x_1935_; lean_object* v___x_1936_; lean_object* v___x_1937_; 
v___x_1931_ = lean_unsigned_to_nat(10u);
v___x_1932_ = lp_lean1090_Lean1090_Impl_cbRateScoreTable;
v___x_1933_ = lean_unsigned_to_nat(36u);
v___x_1934_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1933_, v___x_1931_);
v___x_1935_ = lean_array_fget_borrowed(v___x_1932_, v___x_1934_);
lean_dec(v___x_1934_);
v___x_1936_ = lean_box(0);
lean_inc(v___x_1935_);
v___x_1937_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1937_, 0, v___x_1935_);
lean_ctor_set(v___x_1937_, 1, v___x_1936_);
v___y_1904_ = v___y_1922_;
v___y_1905_ = v___x_1937_;
goto v___jp_1903_;
}
else
{
v___y_1919_ = v___y_1922_;
goto v___jp_1918_;
}
}
else
{
v___y_1919_ = v___y_1922_;
goto v___jp_1918_;
}
}
}
}
else
{
lean_object* v___x_1947_; lean_object* v___x_1948_; lean_object* v___x_1949_; lean_object* v___x_1950_; lean_object* v___y_1952_; lean_object* v___y_1953_; lean_object* v___y_1969_; uint8_t v___x_1980_; 
v___x_1947_ = lean_unsigned_to_nat(27u);
v___x_1948_ = lean_unsigned_to_nat(1u);
v___x_1949_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1947_, v___x_1948_);
v___x_1950_ = lean_unsigned_to_nat(0u);
v___x_1980_ = lean_nat_dec_eq(v___x_1949_, v___x_1950_);
lean_dec(v___x_1949_);
if (v___x_1980_ == 0)
{
lean_object* v___x_1981_; lean_object* v___x_1982_; lean_object* v___x_1983_; lean_object* v___x_1984_; lean_object* v___x_1985_; lean_object* v___x_1986_; lean_object* v___x_1987_; 
v___x_1981_ = lean_unsigned_to_nat(12u);
v___x_1982_ = lp_lean1090_Lean1090_Impl_cbQNHScoreTable;
v___x_1983_ = lean_unsigned_to_nat(28u);
v___x_1984_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1983_, v___x_1981_);
v___x_1985_ = lean_array_fget_borrowed(v___x_1982_, v___x_1984_);
lean_dec(v___x_1984_);
v___x_1986_ = lean_box(0);
lean_inc(v___x_1985_);
v___x_1987_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1987_, 0, v___x_1985_);
lean_ctor_set(v___x_1987_, 1, v___x_1986_);
v___y_1969_ = v___x_1987_;
goto v___jp_1968_;
}
else
{
lean_object* v___x_1988_; 
v___x_1988_ = lean_box(0);
v___y_1969_ = v___x_1988_;
goto v___jp_1968_;
}
v___jp_1951_:
{
lean_object* v___x_1954_; lean_object* v___x_1955_; lean_object* v___x_1956_; uint8_t v___x_1957_; 
v___x_1954_ = l_List_appendTR___redArg(v___y_1952_, v___y_1953_);
v___x_1955_ = lean_unsigned_to_nat(14u);
v___x_1956_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1955_, v___x_1948_);
v___x_1957_ = lean_nat_dec_eq(v___x_1956_, v___x_1950_);
lean_dec(v___x_1956_);
if (v___x_1957_ == 0)
{
lean_object* v___x_1958_; lean_object* v___x_1959_; lean_object* v___x_1960_; lean_object* v___x_1961_; lean_object* v___x_1962_; lean_object* v___x_1963_; lean_object* v___x_1964_; lean_object* v___x_1965_; 
v___x_1958_ = lean_unsigned_to_nat(12u);
v___x_1959_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable;
v___x_1960_ = lean_unsigned_to_nat(15u);
v___x_1961_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1960_, v___x_1958_);
v___x_1962_ = lean_array_fget_borrowed(v___x_1959_, v___x_1961_);
lean_dec(v___x_1961_);
v___x_1963_ = lean_box(0);
lean_inc(v___x_1962_);
v___x_1964_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1964_, 0, v___x_1962_);
lean_ctor_set(v___x_1964_, 1, v___x_1963_);
v___x_1965_ = l_List_appendTR___redArg(v___x_1954_, v___x_1964_);
return v___x_1965_;
}
else
{
lean_object* v___x_1966_; lean_object* v___x_1967_; 
v___x_1966_ = lean_box(0);
v___x_1967_ = l_List_appendTR___redArg(v___x_1954_, v___x_1966_);
return v___x_1967_;
}
}
v___jp_1968_:
{
lean_object* v___x_1970_; uint8_t v___x_1971_; 
v___x_1970_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1948_, v___x_1948_);
v___x_1971_ = lean_nat_dec_eq(v___x_1970_, v___x_1950_);
lean_dec(v___x_1970_);
if (v___x_1971_ == 0)
{
lean_object* v___x_1972_; lean_object* v___x_1973_; lean_object* v___x_1974_; lean_object* v___x_1975_; lean_object* v___x_1976_; lean_object* v___x_1977_; lean_object* v___x_1978_; 
v___x_1972_ = lean_unsigned_to_nat(12u);
v___x_1973_ = lp_lean1090_Lean1090_Impl_cbSelectedScoreTable;
v___x_1974_ = lean_unsigned_to_nat(2u);
v___x_1975_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1769_, v___x_1974_, v___x_1972_);
v___x_1976_ = lean_array_fget_borrowed(v___x_1973_, v___x_1975_);
lean_dec(v___x_1975_);
v___x_1977_ = lean_box(0);
lean_inc(v___x_1976_);
v___x_1978_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1978_, 0, v___x_1976_);
lean_ctor_set(v___x_1978_, 1, v___x_1977_);
v___y_1952_ = v___y_1969_;
v___y_1953_ = v___x_1978_;
goto v___jp_1951_;
}
else
{
lean_object* v___x_1979_; 
v___x_1979_ = lean_box(0);
v___y_1952_ = v___y_1969_;
v___y_1953_ = v___x_1979_;
goto v___jp_1951_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbDensityTermsFast___boxed(lean_object* v_register_1989_, lean_object* v_word_1990_){
_start:
{
lean_object* v_res_1991_; 
v_res_1991_ = lp_lean1090_Lean1090_Impl_cbDensityTermsFast(v_register_1989_, v_word_1990_);
lean_dec(v_word_1990_);
lean_dec(v_register_1989_);
return v_res_1991_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0(lean_object* v_register_1992_, lean_object* v_word_1993_, lean_object* v_x_1994_){
_start:
{
lean_object* v___x_1995_; lean_object* v___x_1996_; uint8_t v___x_1997_; 
v___x_1995_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_cbPenalty___closed__4, &lp_lean1090_Lean1090_Impl_cbPenalty___closed__4_once, _init_lp_lean1090_Lean1090_Impl_cbPenalty___closed__4);
v___x_1996_ = lp_lean1090_Lean1090_Impl_cbCombinedScore(v_register_1992_, v_word_1993_);
v___x_1997_ = l_Rat_instDecidableLe(v___x_1995_, v___x_1996_);
return v___x_1997_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed(lean_object* v_register_1998_, lean_object* v_word_1999_, lean_object* v_x_2000_){
_start:
{
uint8_t v_res_2001_; lean_object* v_r_2002_; 
v_res_2001_ = lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0(v_register_1998_, v_word_1999_, v_x_2000_);
lean_dec(v_word_1999_);
lean_dec(v_register_1998_);
v_r_2002_ = lean_box(v_res_2001_);
return v_r_2002_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses(lean_object* v_register_2003_, lean_object* v_word_2004_){
_start:
{
lean_object* v___f_2005_; lean_object* v___x_2006_; lean_object* v___x_2007_; uint8_t v___x_2008_; 
lean_inc(v_word_2004_);
lean_inc(v_register_2003_);
v___f_2005_ = lean_alloc_closure((void*)(lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed), 3, 2);
lean_closure_set(v___f_2005_, 0, v_register_2003_);
lean_closure_set(v___f_2005_, 1, v_word_2004_);
v___x_2006_ = lp_lean1090_Lean1090_Impl_cbDensityTermsFast(v_register_2003_, v_word_2004_);
v___x_2007_ = lp_lean1090_Lean1090_Impl_cbPenalty(v_register_2003_, v_word_2004_);
lean_dec(v_word_2004_);
lean_dec(v_register_2003_);
v___x_2008_ = lp_lean1090_Lean1090_Impl_ScoreGate_choose(v___x_2006_, v___x_2007_, v___f_2005_);
return v___x_2008_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_cbScorePasses___boxed(lean_object* v_register_2009_, lean_object* v_word_2010_){
_start:
{
uint8_t v_res_2011_; lean_object* v_r_2012_; 
v_res_2011_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2009_, v_word_2010_);
v_r_2012_ = lean_box(v_res_2011_);
return v_r_2012_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBCoreEligible(lean_object* v_register_2050_, lean_object* v_word_2051_){
_start:
{
uint8_t v___y_2053_; lean_object* v___x_2057_; uint8_t v___x_2058_; 
v___x_2057_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBCoreRegisters));
v___x_2058_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_2050_, v___x_2057_);
if (v___x_2058_ == 0)
{
v___y_2053_ = v___x_2058_;
goto v___jp_2052_;
}
else
{
uint8_t v___x_2059_; 
v___x_2059_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_2050_, v_word_2051_);
v___y_2053_ = v___x_2059_;
goto v___jp_2052_;
}
v___jp_2052_:
{
if (v___y_2053_ == 0)
{
lean_dec(v_word_2051_);
lean_dec(v_register_2050_);
return v___y_2053_;
}
else
{
lean_object* v___x_2054_; uint8_t v___x_2055_; 
v___x_2054_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBCoreRegisters___closed__4));
v___x_2055_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_2050_, v___x_2054_);
if (v___x_2055_ == 0)
{
lean_dec(v_word_2051_);
lean_dec(v_register_2050_);
return v___y_2053_;
}
else
{
uint8_t v___x_2056_; 
v___x_2056_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2050_, v_word_2051_);
return v___x_2056_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBCoreEligible___boxed(lean_object* v_register_2060_, lean_object* v_word_2061_){
_start:
{
uint8_t v_res_2062_; lean_object* v_r_2063_; 
v_res_2062_ = lp_lean1090_Lean1090_Impl_commBCoreEligible(v_register_2060_, v_word_2061_);
v_r_2063_ = lean_box(v_res_2062_);
return v_r_2063_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBPositionEligible(lean_object* v_df_2064_, lean_object* v_outerAltitude_2065_, lean_object* v_word_2066_){
_start:
{
lean_object* v___x_2067_; uint8_t v___x_2068_; 
v___x_2067_ = lean_unsigned_to_nat(20u);
v___x_2068_ = lean_nat_dec_eq(v_df_2064_, v___x_2067_);
if (v___x_2068_ == 0)
{
lean_dec(v_outerAltitude_2065_);
return v___x_2068_;
}
else
{
lean_object* v___x_2069_; lean_object* v___x_2070_; lean_object* v_tc_2071_; lean_object* v___x_2072_; uint8_t v___x_2073_; 
v___x_2069_ = lean_unsigned_to_nat(1u);
v___x_2070_ = lean_unsigned_to_nat(5u);
v_tc_2071_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_2066_, v___x_2069_, v___x_2070_);
v___x_2072_ = lean_unsigned_to_nat(9u);
v___x_2073_ = lean_nat_dec_le(v___x_2072_, v_tc_2071_);
if (v___x_2073_ == 0)
{
lean_dec(v_tc_2071_);
lean_dec(v_outerAltitude_2065_);
return v___x_2073_;
}
else
{
lean_object* v___x_2074_; uint8_t v___x_2075_; 
v___x_2074_ = lean_unsigned_to_nat(22u);
v___x_2075_ = lean_nat_dec_lt(v_tc_2071_, v___x_2074_);
if (v___x_2075_ == 0)
{
lean_dec(v_tc_2071_);
lean_dec(v_outerAltitude_2065_);
return v___x_2075_;
}
else
{
lean_object* v___x_2076_; uint8_t v___x_2077_; 
v___x_2076_ = lean_unsigned_to_nat(19u);
v___x_2077_ = lean_nat_dec_eq(v_tc_2071_, v___x_2076_);
lean_dec(v_tc_2071_);
if (v___x_2077_ == 0)
{
uint8_t v___x_2078_; 
v___x_2078_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v___x_2070_, v_word_2066_);
if (v___x_2078_ == 0)
{
lean_dec(v_outerAltitude_2065_);
return v___x_2078_;
}
else
{
lean_object* v___x_2079_; lean_object* v___x_2080_; uint8_t v___x_2081_; 
v___x_2079_ = lean_alloc_closure((void*)(l_Int_instDecidableEq___boxed), 2, 0);
v___x_2080_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_word_2066_);
v___x_2081_ = l_Option_instDecidableEq___redArg(v___x_2079_, v___x_2080_, v_outerAltitude_2065_);
return v___x_2081_;
}
}
else
{
uint8_t v___x_2082_; 
lean_dec(v_outerAltitude_2065_);
v___x_2082_ = 0;
return v___x_2082_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBPositionEligible___boxed(lean_object* v_df_2083_, lean_object* v_outerAltitude_2084_, lean_object* v_word_2085_){
_start:
{
uint8_t v_res_2086_; lean_object* v_r_2087_; 
v_res_2086_ = lp_lean1090_Lean1090_Impl_commBPositionEligible(v_df_2083_, v_outerAltitude_2084_, v_word_2085_);
lean_dec(v_word_2085_);
lean_dec(v_df_2083_);
v_r_2087_ = lean_box(v_res_2086_);
return v_r_2087_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg(){
_start:
{
uint8_t v___x_2089_; 
v___x_2089_ = 0;
return v___x_2089_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg___boxed(lean_object* v___dummy_2090_){
_start:
{
uint8_t v_res_2091_; lean_object* v_r_2092_; 
v_res_2091_ = lp_lean1090_Lean1090_Impl_commBOperationEligible___redArg();
v_r_2092_ = lean_box(v_res_2091_);
return v_r_2092_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBOperationEligible(lean_object* v___word_2093_){
_start:
{
uint8_t v___x_2094_; 
v___x_2094_ = 0;
return v___x_2094_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBOperationEligible___boxed(lean_object* v___word_2095_){
_start:
{
uint8_t v_res_2096_; lean_object* v_r_2097_; 
v_res_2096_ = lp_lean1090_Lean1090_Impl_commBOperationEligible(v___word_2095_);
lean_dec(v___word_2095_);
v_r_2097_ = lean_box(v_res_2096_);
return v_r_2097_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_commBEligible(lean_object* v_df_2098_, lean_object* v_outerAltitude_2099_, lean_object* v_register_2100_, lean_object* v_word_2101_){
_start:
{
lean_object* v___x_2112_; uint8_t v___x_2113_; 
v___x_2112_ = lean_unsigned_to_nat(20u);
v___x_2113_ = lean_nat_dec_eq(v_df_2098_, v___x_2112_);
if (v___x_2113_ == 0)
{
lean_object* v___x_2114_; uint8_t v___x_2115_; 
v___x_2114_ = lean_unsigned_to_nat(21u);
v___x_2115_ = lean_nat_dec_eq(v_df_2098_, v___x_2114_);
if (v___x_2115_ == 0)
{
lean_dec(v_word_2101_);
lean_dec(v_register_2100_);
lean_dec(v_outerAltitude_2099_);
return v___x_2115_;
}
else
{
goto v___jp_2102_;
}
}
else
{
goto v___jp_2102_;
}
v___jp_2102_:
{
lean_object* v___x_2103_; uint8_t v___x_2104_; 
v___x_2103_ = lean_unsigned_to_nat(0u);
v___x_2104_ = lean_nat_dec_eq(v_word_2101_, v___x_2103_);
if (v___x_2104_ == 0)
{
lean_object* v___x_2105_; uint8_t v___x_2106_; 
v___x_2105_ = lean_unsigned_to_nat(5u);
v___x_2106_ = lean_nat_dec_eq(v_register_2100_, v___x_2105_);
if (v___x_2106_ == 0)
{
lean_object* v___x_2107_; uint8_t v___x_2108_; 
lean_dec(v_outerAltitude_2099_);
v___x_2107_ = lean_unsigned_to_nat(101u);
v___x_2108_ = lean_nat_dec_eq(v_register_2100_, v___x_2107_);
if (v___x_2108_ == 0)
{
uint8_t v___x_2109_; 
v___x_2109_ = lp_lean1090_Lean1090_Impl_commBCoreEligible(v_register_2100_, v_word_2101_);
return v___x_2109_;
}
else
{
lean_dec(v_word_2101_);
lean_dec(v_register_2100_);
return v___x_2106_;
}
}
else
{
uint8_t v___x_2110_; 
lean_dec(v_register_2100_);
v___x_2110_ = lp_lean1090_Lean1090_Impl_commBPositionEligible(v_df_2098_, v_outerAltitude_2099_, v_word_2101_);
lean_dec(v_word_2101_);
return v___x_2110_;
}
}
else
{
uint8_t v___x_2111_; 
lean_dec(v_word_2101_);
lean_dec(v_register_2100_);
lean_dec(v_outerAltitude_2099_);
v___x_2111_ = 0;
return v___x_2111_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_commBEligible___boxed(lean_object* v_df_2116_, lean_object* v_outerAltitude_2117_, lean_object* v_register_2118_, lean_object* v_word_2119_){
_start:
{
uint8_t v_res_2120_; lean_object* v_r_2121_; 
v_res_2120_ = lp_lean1090_Lean1090_Impl_commBEligible(v_df_2116_, v_outerAltitude_2117_, v_register_2118_, v_word_2119_);
lean_dec(v_df_2116_);
v_r_2121_ = lean_box(v_res_2120_);
return v_r_2121_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBRegisters___closed__2(void){
_start:
{
lean_object* v___x_2128_; lean_object* v___x_2129_; lean_object* v___x_2130_; 
v___x_2128_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBRegisters___closed__1));
v___x_2129_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_commBRegisters___closed__0));
v___x_2130_ = l_List_appendTR___redArg(v___x_2129_, v___x_2128_);
return v___x_2130_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_commBRegisters(void){
_start:
{
lean_object* v___x_2131_; 
v___x_2131_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_commBRegisters___closed__2, &lp_lean1090_Lean1090_Impl_commBRegisters___closed__2_once, _init_lp_lean1090_Lean1090_Impl_commBRegisters___closed__2);
return v___x_2131_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(lean_object* v_df_2132_, lean_object* v_outerAltitude_2133_, lean_object* v_word_2134_, lean_object* v_a_2135_, lean_object* v_a_2136_){
_start:
{
if (lean_obj_tag(v_a_2135_) == 0)
{
lean_object* v___x_2137_; 
lean_dec(v_word_2134_);
lean_dec(v_outerAltitude_2133_);
v___x_2137_ = lean_array_to_list(v_a_2136_);
return v___x_2137_;
}
else
{
lean_object* v_head_2138_; lean_object* v_tail_2139_; lean_object* v___x_2141_; uint8_t v_isShared_2142_; uint8_t v_isSharedCheck_2153_; 
v_head_2138_ = lean_ctor_get(v_a_2135_, 0);
v_tail_2139_ = lean_ctor_get(v_a_2135_, 1);
v_isSharedCheck_2153_ = !lean_is_exclusive(v_a_2135_);
if (v_isSharedCheck_2153_ == 0)
{
v___x_2141_ = v_a_2135_;
v_isShared_2142_ = v_isSharedCheck_2153_;
goto v_resetjp_2140_;
}
else
{
lean_inc(v_tail_2139_);
lean_inc(v_head_2138_);
lean_dec(v_a_2135_);
v___x_2141_ = lean_box(0);
v_isShared_2142_ = v_isSharedCheck_2153_;
goto v_resetjp_2140_;
}
v_resetjp_2140_:
{
uint8_t v___x_2143_; 
lean_inc(v_word_2134_);
lean_inc(v_head_2138_);
lean_inc(v_outerAltitude_2133_);
v___x_2143_ = lp_lean1090_Lean1090_Impl_commBEligible(v_df_2132_, v_outerAltitude_2133_, v_head_2138_, v_word_2134_);
if (v___x_2143_ == 0)
{
lean_del_object(v___x_2141_);
lean_dec(v_head_2138_);
v_a_2135_ = v_tail_2139_;
goto _start;
}
else
{
lean_object* v___x_2145_; 
lean_inc(v_head_2138_);
v___x_2145_ = lp_lean1090_Lean1090_Impl_decodeBDS(v_head_2138_, v_word_2134_);
if (lean_obj_tag(v___x_2145_) == 0)
{
lean_del_object(v___x_2141_);
lean_dec(v_head_2138_);
v_a_2135_ = v_tail_2139_;
goto _start;
}
else
{
lean_object* v_val_2147_; lean_object* v___x_2149_; 
v_val_2147_ = lean_ctor_get(v___x_2145_, 0);
lean_inc(v_val_2147_);
lean_dec_ref_known(v___x_2145_, 1);
if (v_isShared_2142_ == 0)
{
lean_ctor_set_tag(v___x_2141_, 0);
lean_ctor_set(v___x_2141_, 1, v_val_2147_);
v___x_2149_ = v___x_2141_;
goto v_reusejp_2148_;
}
else
{
lean_object* v_reuseFailAlloc_2152_; 
v_reuseFailAlloc_2152_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2152_, 0, v_head_2138_);
lean_ctor_set(v_reuseFailAlloc_2152_, 1, v_val_2147_);
v___x_2149_ = v_reuseFailAlloc_2152_;
goto v_reusejp_2148_;
}
v_reusejp_2148_:
{
lean_object* v___x_2150_; 
v___x_2150_ = lean_array_push(v_a_2136_, v___x_2149_);
v_a_2135_ = v_tail_2139_;
v_a_2136_ = v___x_2150_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0___boxed(lean_object* v_df_2154_, lean_object* v_outerAltitude_2155_, lean_object* v_word_2156_, lean_object* v_a_2157_, lean_object* v_a_2158_){
_start:
{
lean_object* v_res_2159_; 
v_res_2159_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(v_df_2154_, v_outerAltitude_2155_, v_word_2156_, v_a_2157_, v_a_2158_);
lean_dec(v_df_2154_);
return v_res_2159_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_inferCommB(lean_object* v_df_2162_, lean_object* v_outerAltitude_2163_, lean_object* v_word_2164_){
_start:
{
lean_object* v___x_2165_; lean_object* v___x_2166_; lean_object* v___x_2167_; 
v___x_2165_ = lp_lean1090_Lean1090_Impl_commBRegisters;
v___x_2166_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_inferCommB___closed__0));
v___x_2167_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0(v_df_2162_, v_outerAltitude_2163_, v_word_2164_, v___x_2165_, v___x_2166_);
return v___x_2167_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_inferCommB___boxed(lean_object* v_df_2168_, lean_object* v_outerAltitude_2169_, lean_object* v_word_2170_){
_start:
{
lean_object* v_res_2171_; 
v_res_2171_ = lp_lean1090_Lean1090_Impl_inferCommB(v_df_2168_, v_outerAltitude_2169_, v_word_2170_);
lean_dec(v_df_2168_);
return v_res_2171_;
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
