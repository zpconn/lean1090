// Lean compiler output
// Module: Impl.Semantics
// Imports: public import Init public meta import Init public import Model.Types public import Impl.CommB public import Impl.Presentation
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
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_payloadValue(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbBarometricSetting(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbAirspeed(lean_object*);
lean_object* l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Presentation_standardGeoMinusBaro(lean_object*);
lean_object* l_Rat_ofInt(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbVerticalRate(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Presentation_standardGNSSHeightMetres(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_payloadBits(lean_object*, lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbSelectedAltitude(lean_object*);
lean_object* l_BitVec_ofNat(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_identityCode(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Presentation_standardVelocityComponents(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbNUCp(lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbMovement(lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbAltitude(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbGeoMinusBaro(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbOracleVelocityComponents(lean_object*);
lean_object* l_List_getD___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Presentation_standardVerticalSource(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Presentation_oracleVerticalSource(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbCallsign(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Presentation_velocityTrack(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Presentation_velocitySpeed(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Presentation_oracleADSBFloats(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbLayout(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Presentation_oracleCommBFloats(lean_object*, lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_cbSigned(lean_object*, lean_object*, lean_object*);
lean_object* l_Rat_div(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_commBValue(lean_object*, lean_object*, lean_object*);
uint8_t lp_lean1090_Lean1090_Impl_cbDashPlaceholder(lean_object*);
lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(lean_object*, lean_object*);
lean_object* lean_string_mk(lean_object*);
uint8_t l_instDecidableEqRat_decEq(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_cbRegistration(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_cbCallsign(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_cbThreat(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_cbStandardThreat(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_commBLayout(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_tableValues(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_tableValues___boxed(lean_object*, lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "Reserved"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "n/a"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "<7000kg"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "<34,000kg"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__3_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "<136,000kg"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__4_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "High vortex"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__5_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "Heavy"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__6_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "High performance"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__7_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "Rotorcraft"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__8_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__8_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__9 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__9_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__7_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__9_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__10 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__10_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__6_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__10_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__11 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__11_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__5_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__11_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__12 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__12_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__4_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__12_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__13 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__13_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__3_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__13_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__14 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__14_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__2_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__14_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__15 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__15_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__15_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__16 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__16_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "Glider"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__17 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__17_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "Lighter than air"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__18 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__18_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "Parachutist"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__19 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__19_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "Ultralight"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__20 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__20_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "UAV"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__21 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__21_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "Space"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__22 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__22_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__22_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__23 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__23_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__21_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__23_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__24 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__24_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__0_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__24_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__25 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__25_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__20_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__25_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__26 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__26_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__19_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__26_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__27 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__27_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__18_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__27_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__28 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__28_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__17_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__28_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__29 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__29_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__29_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__30 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__30_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__31_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "Obstruction"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__31 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__31_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__32_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "Surface service vehicle"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__32 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__32_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__33_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "Surface emergency vehicle"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__33 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__33_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___boxed(lean_object*, lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "none"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "general"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "medical"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "minimum_fuel"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__3_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "no_communication"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__4_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "unlawful_interference"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__5_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "downed_aircraft"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__6_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "reserved"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__7_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__7_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__8_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__6_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__8_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__9 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__9_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__5_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__9_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__10 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__10_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__4_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__10_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__11 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__11_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__3_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__11_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__12 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__12_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__2_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__12_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__13 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__13_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__13_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__14 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__14_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__0_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__14_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__15 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__15_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency(lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "barometric_setting"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "airspeed"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "geo_minus_baro"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "vertical_rate"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__3_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "north_velocity"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__4_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "height_metres"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__5_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "altitude_feet"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__6_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "selected_altitude"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__7_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "squawk"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__8_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "east_velocity"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__9 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__9_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "NUCp"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__10 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__10_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "NICb"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__11 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__11_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "groundspeed"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__12 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__12_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_oracleReservedVelocityData(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_oracleReservedVelocityData___boxed(lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbOracleValues___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "reserved_data"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbOracleValues___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbOracleValues___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbOracleValues(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbOracleValues___boxed(lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "TAS"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "IAS"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "airspeed_type"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "source"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__3_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "GNSS"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__4_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "barometric"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__5_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "FMS"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__6_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "MCP/FCU"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__7_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "subtype"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__8_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "no_information"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__9 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__9_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "emergency_priority"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__10 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__10_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "acas_ra"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__11 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__11_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__11_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__12 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__12_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__10_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__12_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__13 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__13_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__9_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__13_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__14 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__14_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "emergency_state"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__15 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__15_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "vrate_src"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__16 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__16_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "callsign"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__17 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__17_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "wake_vortex"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__18 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__18_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___boxed(lean_object*, lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_adsbStandardFloats___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "track"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardFloats___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbStandardFloats___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardFloats(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardFloats___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsb(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsb___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_Semantics_airline_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_Semantics_airline_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_airline(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_airline___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__2;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "Severe"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__3_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__3_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__4_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "Moderate"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__5_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__5_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__6_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "Light"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__7_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__7_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__8_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "Nil"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__9 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__9_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__9_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__10 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__10_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBLabels_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBLabels_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "turbulence"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "wind_shear"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "microburst"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "icing"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__3_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__18_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__4_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__3_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__4_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__5_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__2_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__5_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__6_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__6_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__7_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__0_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__7_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__8_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "figure_of_merit"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__9 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__9_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "Invalid"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__10 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__10_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "INS"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__11 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__11_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "DMEDME"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__12 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__12_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "VORDME"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__13 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__13_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__13_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__14 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__14_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__12_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__14_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__15 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__15_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__4_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__15_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__16 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__16_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__11_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__16_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__17 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__17_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__10_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__17_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__18 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__18_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "target_altitude_source"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__19 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__19_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "Unknown"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__20 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__20_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "AircraftAltitude"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__21 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__21_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "FcpMcuSelectedAltitude"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__22 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__22_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "FmsSelectedAltitude"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__23 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__23_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__23_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__24 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__24_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__22_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__24_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__25 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__25_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__21_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__25_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__26 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__26_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__20_value),((lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__26_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__27 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__27_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "registration"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__28 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__28_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "airline"};
static const lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__29 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__29_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___boxed(lean_object*, lean_object*);
static const lean_string_object lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "temperature"};
static const lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0___closed__0 = (const lean_object*)&lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0___closed__0_value;
static lean_once_cell_t lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBStandardFloats(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBStandardFloats___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commB_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commB_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_commB(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_commB___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0(lean_object* v_word_1_, lean_object* v_a_2_, lean_object* v_a_3_){
_start:
{
if (lean_obj_tag(v_a_2_) == 0)
{
lean_object* v___x_4_; 
v___x_4_ = l_List_reverse___redArg(v_a_3_);
return v___x_4_;
}
else
{
lean_object* v_head_5_; lean_object* v_tail_6_; lean_object* v___x_8_; uint8_t v_isShared_9_; uint8_t v_isSharedCheck_17_; 
v_head_5_ = lean_ctor_get(v_a_2_, 0);
v_tail_6_ = lean_ctor_get(v_a_2_, 1);
v_isSharedCheck_17_ = !lean_is_exclusive(v_a_2_);
if (v_isSharedCheck_17_ == 0)
{
v___x_8_ = v_a_2_;
v_isShared_9_ = v_isSharedCheck_17_;
goto v_resetjp_7_;
}
else
{
lean_inc(v_tail_6_);
lean_inc(v_head_5_);
lean_dec(v_a_2_);
v___x_8_ = lean_box(0);
v_isShared_9_ = v_isSharedCheck_17_;
goto v_resetjp_7_;
}
v_resetjp_7_:
{
lean_object* v_name_10_; lean_object* v___x_11_; lean_object* v___x_12_; lean_object* v___x_14_; 
v_name_10_ = lean_ctor_get(v_head_5_, 0);
lean_inc_ref(v_name_10_);
v___x_11_ = lp_lean1090_Lean1090_Impl_payloadValue(v_head_5_, v_word_1_);
v___x_12_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_12_, 0, v_name_10_);
lean_ctor_set(v___x_12_, 1, v___x_11_);
if (v_isShared_9_ == 0)
{
lean_ctor_set(v___x_8_, 1, v_a_3_);
lean_ctor_set(v___x_8_, 0, v___x_12_);
v___x_14_ = v___x_8_;
goto v_reusejp_13_;
}
else
{
lean_object* v_reuseFailAlloc_16_; 
v_reuseFailAlloc_16_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_16_, 0, v___x_12_);
lean_ctor_set(v_reuseFailAlloc_16_, 1, v_a_3_);
v___x_14_ = v_reuseFailAlloc_16_;
goto v_reusejp_13_;
}
v_reusejp_13_:
{
v_a_2_ = v_tail_6_;
v_a_3_ = v___x_14_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0___boxed(lean_object* v_word_18_, lean_object* v_a_19_, lean_object* v_a_20_){
_start:
{
lean_object* v_res_21_; 
v_res_21_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0(v_word_18_, v_a_19_, v_a_20_);
lean_dec(v_word_18_);
return v_res_21_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_tableValues(lean_object* v_layout_22_, lean_object* v_word_23_){
_start:
{
lean_object* v___x_24_; lean_object* v___x_25_; 
v___x_24_ = lean_box(0);
v___x_25_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0(v_word_23_, v_layout_22_, v___x_24_);
return v___x_25_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_tableValues___boxed(lean_object* v_layout_26_, lean_object* v_word_27_){
_start:
{
lean_object* v_res_28_; 
v_res_28_ = lp_lean1090_Lean1090_Impl_Semantics_tableValues(v_layout_26_, v_word_27_);
lean_dec(v_word_27_);
return v_res_28_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex(lean_object* v_tc_95_, lean_object* v_category_96_){
_start:
{
lean_object* v___x_97_; uint8_t v___x_98_; 
v___x_97_ = lean_unsigned_to_nat(1u);
v___x_98_ = lean_nat_dec_eq(v_tc_95_, v___x_97_);
if (v___x_98_ == 0)
{
lean_object* v___x_99_; uint8_t v___x_100_; 
v___x_99_ = lean_unsigned_to_nat(0u);
v___x_100_ = lean_nat_dec_eq(v_category_96_, v___x_99_);
if (v___x_100_ == 0)
{
lean_object* v___x_101_; uint8_t v___x_102_; 
v___x_101_ = lean_unsigned_to_nat(2u);
v___x_102_ = lean_nat_dec_eq(v_tc_95_, v___x_101_);
if (v___x_102_ == 0)
{
lean_object* v___x_103_; uint8_t v___x_104_; 
v___x_103_ = lean_unsigned_to_nat(3u);
v___x_104_ = lean_nat_dec_eq(v_tc_95_, v___x_103_);
if (v___x_104_ == 0)
{
lean_object* v___x_105_; uint8_t v___x_106_; 
v___x_105_ = lean_unsigned_to_nat(4u);
v___x_106_ = lean_nat_dec_eq(v_tc_95_, v___x_105_);
if (v___x_106_ == 0)
{
lean_object* v___x_107_; 
lean_dec(v_category_96_);
v___x_107_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__0));
return v___x_107_;
}
else
{
lean_object* v___x_108_; lean_object* v___x_109_; lean_object* v___x_110_; 
v___x_108_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__16));
v___x_109_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__0));
v___x_110_ = l_List_getD___redArg(v___x_108_, v_category_96_, v___x_109_);
return v___x_110_;
}
}
else
{
lean_object* v___x_111_; lean_object* v___x_112_; lean_object* v___x_113_; 
v___x_111_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__0));
v___x_112_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__30));
v___x_113_ = l_List_getD___redArg(v___x_112_, v_category_96_, v___x_111_);
return v___x_113_;
}
}
else
{
uint8_t v___x_114_; 
v___x_114_ = lean_nat_dec_eq(v_category_96_, v___x_97_);
if (v___x_114_ == 0)
{
lean_object* v___x_115_; uint8_t v___x_116_; 
v___x_115_ = lean_unsigned_to_nat(3u);
v___x_116_ = lean_nat_dec_eq(v_category_96_, v___x_115_);
lean_dec(v_category_96_);
if (v___x_116_ == 0)
{
lean_object* v___x_117_; 
v___x_117_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__31));
return v___x_117_;
}
else
{
lean_object* v___x_118_; 
v___x_118_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__32));
return v___x_118_;
}
}
else
{
lean_object* v___x_119_; 
lean_dec(v_category_96_);
v___x_119_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__33));
return v___x_119_;
}
}
}
else
{
lean_object* v___x_120_; 
lean_dec(v_category_96_);
v___x_120_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__1));
return v___x_120_;
}
}
else
{
lean_object* v___x_121_; 
lean_dec(v_category_96_);
v___x_121_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__0));
return v___x_121_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___boxed(lean_object* v_tc_122_, lean_object* v_category_123_){
_start:
{
lean_object* v_res_124_; 
v_res_124_ = lp_lean1090_Lean1090_Impl_Semantics_wakeVortex(v_tc_122_, v_category_123_);
lean_dec(v_tc_122_);
return v_res_124_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_emergency(lean_object* v_code_157_){
_start:
{
lean_object* v___x_158_; lean_object* v___x_159_; lean_object* v___x_160_; 
v___x_158_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__7));
v___x_159_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__15));
v___x_160_ = l_List_getD___redArg(v___x_159_, v_code_157_, v___x_158_);
return v___x_160_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues(lean_object* v_word_174_){
_start:
{
lean_object* v___y_176_; lean_object* v___y_177_; lean_object* v___y_186_; lean_object* v___y_187_; lean_object* v___y_188_; lean_object* v___y_189_; lean_object* v___y_190_; lean_object* v___y_191_; lean_object* v___y_200_; lean_object* v___y_201_; lean_object* v___y_202_; lean_object* v___y_203_; lean_object* v___y_204_; lean_object* v___y_217_; lean_object* v___y_218_; lean_object* v___y_219_; lean_object* v___y_220_; lean_object* v___y_221_; lean_object* v___y_222_; lean_object* v___y_223_; lean_object* v___y_231_; lean_object* v___y_232_; lean_object* v___y_233_; lean_object* v___y_234_; lean_object* v___y_235_; lean_object* v___y_236_; lean_object* v___y_251_; lean_object* v___y_252_; lean_object* v___y_253_; lean_object* v___y_254_; lean_object* v___y_255_; lean_object* v___y_270_; lean_object* v___y_271_; lean_object* v___y_272_; lean_object* v___y_273_; lean_object* v___y_274_; lean_object* v___y_289_; lean_object* v___y_290_; lean_object* v___y_291_; lean_object* v___y_292_; lean_object* v___y_293_; lean_object* v___y_301_; lean_object* v___y_302_; lean_object* v___y_303_; lean_object* v___y_304_; uint8_t v___y_319_; lean_object* v___y_320_; lean_object* v___y_321_; lean_object* v___y_322_; lean_object* v___y_323_; lean_object* v___x_340_; lean_object* v___x_341_; lean_object* v_tc_342_; lean_object* v___y_385_; lean_object* v___y_400_; uint8_t v___x_410_; 
v___x_340_ = lean_unsigned_to_nat(1u);
v___x_341_ = lean_unsigned_to_nat(5u);
v_tc_342_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_174_, v___x_340_, v___x_341_);
v___x_410_ = lean_nat_dec_le(v___x_341_, v_tc_342_);
if (v___x_410_ == 0)
{
goto v___jp_405_;
}
else
{
lean_object* v___x_411_; uint8_t v___x_412_; 
v___x_411_ = lean_unsigned_to_nat(8u);
v___x_412_ = lean_nat_dec_le(v_tc_342_, v___x_411_);
if (v___x_412_ == 0)
{
goto v___jp_405_;
}
else
{
lean_object* v___x_413_; lean_object* v___x_414_; lean_object* v___x_415_; lean_object* v___x_416_; lean_object* v___x_417_; lean_object* v___x_418_; lean_object* v___x_419_; lean_object* v___x_420_; lean_object* v___x_421_; lean_object* v___x_422_; lean_object* v___x_423_; lean_object* v___x_424_; lean_object* v___x_425_; lean_object* v___x_426_; 
v___x_413_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__10));
v___x_414_ = lp_lean1090_Lean1090_Impl_adsbNUCp(v_tc_342_);
lean_dec(v_tc_342_);
v___x_415_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_414_);
v___x_416_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_416_, 0, v___x_415_);
v___x_417_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_417_, 0, v___x_413_);
lean_ctor_set(v___x_417_, 1, v___x_416_);
v___x_418_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__12));
v___x_419_ = lean_unsigned_to_nat(6u);
v___x_420_ = lean_unsigned_to_nat(7u);
v___x_421_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_174_, v___x_419_, v___x_420_);
v___x_422_ = lp_lean1090_Lean1090_Impl_adsbMovement(v___x_421_);
lean_dec(v___x_421_);
v___x_423_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_423_, 0, v___x_418_);
lean_ctor_set(v___x_423_, 1, v___x_422_);
v___x_424_ = lean_box(0);
v___x_425_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_425_, 0, v___x_423_);
lean_ctor_set(v___x_425_, 1, v___x_424_);
v___x_426_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_426_, 0, v___x_417_);
lean_ctor_set(v___x_426_, 1, v___x_425_);
return v___x_426_;
}
}
v___jp_175_:
{
lean_object* v___x_178_; lean_object* v___x_179_; lean_object* v___x_180_; lean_object* v___x_181_; lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; 
lean_inc_ref(v___y_176_);
v___x_178_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_178_, 0, v___y_176_);
lean_ctor_set(v___x_178_, 1, v___y_177_);
v___x_179_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__0));
v___x_180_ = lp_lean1090_Lean1090_Impl_adsbBarometricSetting(v_word_174_);
v___x_181_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_181_, 0, v___x_179_);
lean_ctor_set(v___x_181_, 1, v___x_180_);
v___x_182_ = lean_box(0);
v___x_183_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_183_, 0, v___x_181_);
lean_ctor_set(v___x_183_, 1, v___x_182_);
v___x_184_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_184_, 0, v___x_178_);
lean_ctor_set(v___x_184_, 1, v___x_183_);
return v___x_184_;
}
v___jp_185_:
{
lean_object* v___x_192_; lean_object* v___x_193_; lean_object* v___x_194_; lean_object* v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; lean_object* v___x_198_; 
lean_inc_ref(v___y_186_);
v___x_192_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_192_, 0, v___y_186_);
lean_ctor_set(v___x_192_, 1, v___y_191_);
v___x_193_ = lean_box(0);
v___x_194_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_194_, 0, v___x_192_);
lean_ctor_set(v___x_194_, 1, v___x_193_);
v___x_195_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_195_, 0, v___y_187_);
lean_ctor_set(v___x_195_, 1, v___x_194_);
v___x_196_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_196_, 0, v___y_189_);
lean_ctor_set(v___x_196_, 1, v___x_195_);
v___x_197_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_197_, 0, v___y_188_);
lean_ctor_set(v___x_197_, 1, v___x_196_);
v___x_198_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_198_, 0, v___y_190_);
lean_ctor_set(v___x_198_, 1, v___x_197_);
return v___x_198_;
}
v___jp_199_:
{
lean_object* v___x_205_; 
v___x_205_ = lp_lean1090_Lean1090_Impl_adsbAirspeed(v_word_174_);
if (lean_obj_tag(v___x_205_) == 0)
{
lean_object* v___x_206_; 
v___x_206_ = lean_box(0);
v___y_186_ = v___y_200_;
v___y_187_ = v___y_201_;
v___y_188_ = v___y_202_;
v___y_189_ = v___y_203_;
v___y_190_ = v___y_204_;
v___y_191_ = v___x_206_;
goto v___jp_185_;
}
else
{
lean_object* v_val_207_; lean_object* v___x_209_; uint8_t v_isShared_210_; uint8_t v_isSharedCheck_215_; 
v_val_207_ = lean_ctor_get(v___x_205_, 0);
v_isSharedCheck_215_ = !lean_is_exclusive(v___x_205_);
if (v_isSharedCheck_215_ == 0)
{
v___x_209_ = v___x_205_;
v_isShared_210_ = v_isSharedCheck_215_;
goto v_resetjp_208_;
}
else
{
lean_inc(v_val_207_);
lean_dec(v___x_205_);
v___x_209_ = lean_box(0);
v_isShared_210_ = v_isSharedCheck_215_;
goto v_resetjp_208_;
}
v_resetjp_208_:
{
lean_object* v___x_211_; lean_object* v___x_213_; 
v___x_211_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_val_207_);
if (v_isShared_210_ == 0)
{
lean_ctor_set(v___x_209_, 0, v___x_211_);
v___x_213_ = v___x_209_;
goto v_reusejp_212_;
}
else
{
lean_object* v_reuseFailAlloc_214_; 
v_reuseFailAlloc_214_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_214_, 0, v___x_211_);
v___x_213_ = v_reuseFailAlloc_214_;
goto v_reusejp_212_;
}
v_reusejp_212_:
{
v___y_186_ = v___y_200_;
v___y_187_ = v___y_201_;
v___y_188_ = v___y_202_;
v___y_189_ = v___y_203_;
v___y_190_ = v___y_204_;
v___y_191_ = v___x_213_;
goto v___jp_185_;
}
}
}
}
v___jp_216_:
{
lean_object* v___x_224_; lean_object* v___x_225_; uint8_t v___x_226_; 
lean_inc_ref(v___y_221_);
v___x_224_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_224_, 0, v___y_221_);
lean_ctor_set(v___x_224_, 1, v___y_223_);
v___x_225_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__1));
v___x_226_ = lean_nat_dec_eq(v___y_218_, v___y_222_);
if (v___x_226_ == 0)
{
lean_object* v___x_227_; uint8_t v___x_228_; 
v___x_227_ = lean_unsigned_to_nat(4u);
v___x_228_ = lean_nat_dec_eq(v___y_218_, v___x_227_);
lean_dec(v___y_218_);
if (v___x_228_ == 0)
{
lean_object* v___x_229_; 
v___x_229_ = lean_box(0);
v___y_186_ = v___x_225_;
v___y_187_ = v___x_224_;
v___y_188_ = v___y_217_;
v___y_189_ = v___y_219_;
v___y_190_ = v___y_220_;
v___y_191_ = v___x_229_;
goto v___jp_185_;
}
else
{
v___y_200_ = v___x_225_;
v___y_201_ = v___x_224_;
v___y_202_ = v___y_217_;
v___y_203_ = v___y_219_;
v___y_204_ = v___y_220_;
goto v___jp_199_;
}
}
else
{
lean_dec(v___y_218_);
v___y_200_ = v___x_225_;
v___y_201_ = v___x_224_;
v___y_202_ = v___y_217_;
v___y_203_ = v___y_219_;
v___y_204_ = v___y_220_;
goto v___jp_199_;
}
}
v___jp_230_:
{
lean_object* v___x_237_; lean_object* v___x_238_; lean_object* v___x_239_; 
lean_inc_ref(v___y_231_);
v___x_237_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_237_, 0, v___y_231_);
lean_ctor_set(v___x_237_, 1, v___y_236_);
v___x_238_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__2));
v___x_239_ = lp_lean1090_Lean1090_Impl_Presentation_standardGeoMinusBaro(v_word_174_);
if (lean_obj_tag(v___x_239_) == 0)
{
lean_object* v___x_240_; 
v___x_240_ = lean_box(0);
v___y_217_ = v___y_232_;
v___y_218_ = v___y_233_;
v___y_219_ = v___x_237_;
v___y_220_ = v___y_234_;
v___y_221_ = v___x_238_;
v___y_222_ = v___y_235_;
v___y_223_ = v___x_240_;
goto v___jp_216_;
}
else
{
lean_object* v_val_241_; lean_object* v___x_243_; uint8_t v_isShared_244_; uint8_t v_isSharedCheck_249_; 
v_val_241_ = lean_ctor_get(v___x_239_, 0);
v_isSharedCheck_249_ = !lean_is_exclusive(v___x_239_);
if (v_isSharedCheck_249_ == 0)
{
v___x_243_ = v___x_239_;
v_isShared_244_ = v_isSharedCheck_249_;
goto v_resetjp_242_;
}
else
{
lean_inc(v_val_241_);
lean_dec(v___x_239_);
v___x_243_ = lean_box(0);
v_isShared_244_ = v_isSharedCheck_249_;
goto v_resetjp_242_;
}
v_resetjp_242_:
{
lean_object* v___x_245_; lean_object* v___x_247_; 
v___x_245_ = l_Rat_ofInt(v_val_241_);
if (v_isShared_244_ == 0)
{
lean_ctor_set(v___x_243_, 0, v___x_245_);
v___x_247_ = v___x_243_;
goto v_reusejp_246_;
}
else
{
lean_object* v_reuseFailAlloc_248_; 
v_reuseFailAlloc_248_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_248_, 0, v___x_245_);
v___x_247_ = v_reuseFailAlloc_248_;
goto v_reusejp_246_;
}
v_reusejp_246_:
{
v___y_217_ = v___y_232_;
v___y_218_ = v___y_233_;
v___y_219_ = v___x_237_;
v___y_220_ = v___y_234_;
v___y_221_ = v___x_238_;
v___y_222_ = v___y_235_;
v___y_223_ = v___x_247_;
goto v___jp_216_;
}
}
}
}
v___jp_250_:
{
lean_object* v___x_256_; lean_object* v___x_257_; lean_object* v___x_258_; 
lean_inc_ref(v___y_252_);
v___x_256_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_256_, 0, v___y_252_);
lean_ctor_set(v___x_256_, 1, v___y_255_);
v___x_257_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__3));
v___x_258_ = lp_lean1090_Lean1090_Impl_adsbVerticalRate(v_word_174_);
if (lean_obj_tag(v___x_258_) == 0)
{
lean_object* v___x_259_; 
v___x_259_ = lean_box(0);
v___y_231_ = v___x_257_;
v___y_232_ = v___x_256_;
v___y_233_ = v___y_251_;
v___y_234_ = v___y_253_;
v___y_235_ = v___y_254_;
v___y_236_ = v___x_259_;
goto v___jp_230_;
}
else
{
lean_object* v_val_260_; lean_object* v___x_262_; uint8_t v_isShared_263_; uint8_t v_isSharedCheck_268_; 
v_val_260_ = lean_ctor_get(v___x_258_, 0);
v_isSharedCheck_268_ = !lean_is_exclusive(v___x_258_);
if (v_isSharedCheck_268_ == 0)
{
v___x_262_ = v___x_258_;
v_isShared_263_ = v_isSharedCheck_268_;
goto v_resetjp_261_;
}
else
{
lean_inc(v_val_260_);
lean_dec(v___x_258_);
v___x_262_ = lean_box(0);
v_isShared_263_ = v_isSharedCheck_268_;
goto v_resetjp_261_;
}
v_resetjp_261_:
{
lean_object* v___x_264_; lean_object* v___x_266_; 
v___x_264_ = l_Rat_ofInt(v_val_260_);
if (v_isShared_263_ == 0)
{
lean_ctor_set(v___x_262_, 0, v___x_264_);
v___x_266_ = v___x_262_;
goto v_reusejp_265_;
}
else
{
lean_object* v_reuseFailAlloc_267_; 
v_reuseFailAlloc_267_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_267_, 0, v___x_264_);
v___x_266_ = v_reuseFailAlloc_267_;
goto v_reusejp_265_;
}
v_reusejp_265_:
{
v___y_231_ = v___x_257_;
v___y_232_ = v___x_256_;
v___y_233_ = v___y_251_;
v___y_234_ = v___y_253_;
v___y_235_ = v___y_254_;
v___y_236_ = v___x_266_;
goto v___jp_230_;
}
}
}
}
v___jp_269_:
{
lean_object* v___x_275_; lean_object* v___x_276_; 
lean_inc_ref(v___y_270_);
v___x_275_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_275_, 0, v___y_270_);
lean_ctor_set(v___x_275_, 1, v___y_274_);
v___x_276_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__4));
if (lean_obj_tag(v___y_272_) == 0)
{
lean_object* v___x_277_; 
v___x_277_ = lean_box(0);
v___y_251_ = v___y_271_;
v___y_252_ = v___x_276_;
v___y_253_ = v___x_275_;
v___y_254_ = v___y_273_;
v___y_255_ = v___x_277_;
goto v___jp_250_;
}
else
{
lean_object* v_val_278_; lean_object* v___x_280_; uint8_t v_isShared_281_; uint8_t v_isSharedCheck_287_; 
v_val_278_ = lean_ctor_get(v___y_272_, 0);
v_isSharedCheck_287_ = !lean_is_exclusive(v___y_272_);
if (v_isSharedCheck_287_ == 0)
{
v___x_280_ = v___y_272_;
v_isShared_281_ = v_isSharedCheck_287_;
goto v_resetjp_279_;
}
else
{
lean_inc(v_val_278_);
lean_dec(v___y_272_);
v___x_280_ = lean_box(0);
v_isShared_281_ = v_isSharedCheck_287_;
goto v_resetjp_279_;
}
v_resetjp_279_:
{
lean_object* v_snd_282_; lean_object* v___x_283_; lean_object* v___x_285_; 
v_snd_282_ = lean_ctor_get(v_val_278_, 1);
lean_inc(v_snd_282_);
lean_dec(v_val_278_);
v___x_283_ = l_Rat_ofInt(v_snd_282_);
if (v_isShared_281_ == 0)
{
lean_ctor_set(v___x_280_, 0, v___x_283_);
v___x_285_ = v___x_280_;
goto v_reusejp_284_;
}
else
{
lean_object* v_reuseFailAlloc_286_; 
v_reuseFailAlloc_286_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_286_, 0, v___x_283_);
v___x_285_ = v_reuseFailAlloc_286_;
goto v_reusejp_284_;
}
v_reusejp_284_:
{
v___y_251_ = v___y_271_;
v___y_252_ = v___x_276_;
v___y_253_ = v___x_275_;
v___y_254_ = v___y_273_;
v___y_255_ = v___x_285_;
goto v___jp_250_;
}
}
}
}
v___jp_288_:
{
lean_object* v___x_294_; lean_object* v___x_295_; lean_object* v___x_296_; lean_object* v___x_297_; lean_object* v___x_298_; lean_object* v___x_299_; 
lean_inc_ref(v___y_291_);
v___x_294_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_294_, 0, v___y_291_);
lean_ctor_set(v___x_294_, 1, v___y_293_);
v___x_295_ = lean_box(0);
v___x_296_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_296_, 0, v___x_294_);
lean_ctor_set(v___x_296_, 1, v___x_295_);
v___x_297_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_297_, 0, v___y_292_);
lean_ctor_set(v___x_297_, 1, v___x_296_);
v___x_298_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_298_, 0, v___y_289_);
lean_ctor_set(v___x_298_, 1, v___x_297_);
v___x_299_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_299_, 0, v___y_290_);
lean_ctor_set(v___x_299_, 1, v___x_298_);
return v___x_299_;
}
v___jp_300_:
{
lean_object* v___x_305_; lean_object* v___x_306_; lean_object* v___x_307_; 
lean_inc_ref(v___y_303_);
v___x_305_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_305_, 0, v___y_303_);
lean_ctor_set(v___x_305_, 1, v___y_304_);
v___x_306_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__5));
v___x_307_ = lp_lean1090_Lean1090_Impl_Presentation_standardGNSSHeightMetres(v_word_174_);
if (lean_obj_tag(v___x_307_) == 0)
{
lean_object* v___x_308_; 
v___x_308_ = lean_box(0);
v___y_289_ = v___y_301_;
v___y_290_ = v___y_302_;
v___y_291_ = v___x_306_;
v___y_292_ = v___x_305_;
v___y_293_ = v___x_308_;
goto v___jp_288_;
}
else
{
lean_object* v_val_309_; lean_object* v___x_311_; uint8_t v_isShared_312_; uint8_t v_isSharedCheck_317_; 
v_val_309_ = lean_ctor_get(v___x_307_, 0);
v_isSharedCheck_317_ = !lean_is_exclusive(v___x_307_);
if (v_isSharedCheck_317_ == 0)
{
v___x_311_ = v___x_307_;
v_isShared_312_ = v_isSharedCheck_317_;
goto v_resetjp_310_;
}
else
{
lean_inc(v_val_309_);
lean_dec(v___x_307_);
v___x_311_ = lean_box(0);
v_isShared_312_ = v_isSharedCheck_317_;
goto v_resetjp_310_;
}
v_resetjp_310_:
{
lean_object* v___x_313_; lean_object* v___x_315_; 
v___x_313_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_val_309_);
if (v_isShared_312_ == 0)
{
lean_ctor_set(v___x_311_, 0, v___x_313_);
v___x_315_ = v___x_311_;
goto v_reusejp_314_;
}
else
{
lean_object* v_reuseFailAlloc_316_; 
v_reuseFailAlloc_316_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_316_, 0, v___x_313_);
v___x_315_ = v_reuseFailAlloc_316_;
goto v_reusejp_314_;
}
v_reusejp_314_:
{
v___y_289_ = v___y_301_;
v___y_290_ = v___y_302_;
v___y_291_ = v___x_306_;
v___y_292_ = v___x_305_;
v___y_293_ = v___x_315_;
goto v___jp_288_;
}
}
}
}
v___jp_318_:
{
lean_object* v___x_324_; lean_object* v___x_325_; 
lean_inc_ref(v___y_322_);
v___x_324_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_324_, 0, v___y_322_);
lean_ctor_set(v___x_324_, 1, v___y_323_);
v___x_325_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__6));
if (v___y_319_ == 0)
{
lean_object* v___x_326_; 
v___x_326_ = lean_box(0);
v___y_301_ = v___x_324_;
v___y_302_ = v___y_320_;
v___y_303_ = v___x_325_;
v___y_304_ = v___x_326_;
goto v___jp_300_;
}
else
{
lean_object* v___x_327_; lean_object* v___x_328_; lean_object* v___x_329_; 
v___x_327_ = lean_unsigned_to_nat(12u);
v___x_328_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_174_, v___y_321_, v___x_327_);
v___x_329_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(v___x_328_);
lean_dec(v___x_328_);
if (lean_obj_tag(v___x_329_) == 0)
{
lean_object* v___x_330_; 
v___x_330_ = lean_box(0);
v___y_301_ = v___x_324_;
v___y_302_ = v___y_320_;
v___y_303_ = v___x_325_;
v___y_304_ = v___x_330_;
goto v___jp_300_;
}
else
{
lean_object* v_val_331_; lean_object* v___x_333_; uint8_t v_isShared_334_; uint8_t v_isSharedCheck_339_; 
v_val_331_ = lean_ctor_get(v___x_329_, 0);
v_isSharedCheck_339_ = !lean_is_exclusive(v___x_329_);
if (v_isSharedCheck_339_ == 0)
{
v___x_333_ = v___x_329_;
v_isShared_334_ = v_isSharedCheck_339_;
goto v_resetjp_332_;
}
else
{
lean_inc(v_val_331_);
lean_dec(v___x_329_);
v___x_333_ = lean_box(0);
v_isShared_334_ = v_isSharedCheck_339_;
goto v_resetjp_332_;
}
v_resetjp_332_:
{
lean_object* v___x_335_; lean_object* v___x_337_; 
v___x_335_ = l_Rat_ofInt(v_val_331_);
if (v_isShared_334_ == 0)
{
lean_ctor_set(v___x_333_, 0, v___x_335_);
v___x_337_ = v___x_333_;
goto v_reusejp_336_;
}
else
{
lean_object* v_reuseFailAlloc_338_; 
v_reuseFailAlloc_338_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_338_, 0, v___x_335_);
v___x_337_ = v_reuseFailAlloc_338_;
goto v_reusejp_336_;
}
v_reusejp_336_:
{
v___y_301_ = v___x_324_;
v___y_302_ = v___y_320_;
v___y_303_ = v___x_325_;
v___y_304_ = v___x_337_;
goto v___jp_300_;
}
}
}
}
}
v___jp_343_:
{
lean_object* v___x_344_; uint8_t v___x_345_; 
v___x_344_ = lean_unsigned_to_nat(19u);
v___x_345_ = lean_nat_dec_eq(v_tc_342_, v___x_344_);
if (v___x_345_ == 0)
{
lean_object* v___x_346_; uint8_t v___x_347_; 
v___x_346_ = lean_unsigned_to_nat(28u);
v___x_347_ = lean_nat_dec_eq(v_tc_342_, v___x_346_);
if (v___x_347_ == 0)
{
lean_object* v___x_348_; uint8_t v___x_349_; 
v___x_348_ = lean_unsigned_to_nat(29u);
v___x_349_ = lean_nat_dec_eq(v_tc_342_, v___x_348_);
lean_dec(v_tc_342_);
if (v___x_349_ == 0)
{
lean_object* v___x_350_; 
v___x_350_ = lean_box(0);
return v___x_350_;
}
else
{
lean_object* v___x_351_; lean_object* v___x_352_; 
v___x_351_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__7));
v___x_352_ = lp_lean1090_Lean1090_Impl_adsbSelectedAltitude(v_word_174_);
if (lean_obj_tag(v___x_352_) == 0)
{
lean_object* v___x_353_; 
v___x_353_ = lean_box(0);
v___y_176_ = v___x_351_;
v___y_177_ = v___x_353_;
goto v___jp_175_;
}
else
{
lean_object* v_val_354_; lean_object* v___x_356_; uint8_t v_isShared_357_; uint8_t v_isSharedCheck_362_; 
v_val_354_ = lean_ctor_get(v___x_352_, 0);
v_isSharedCheck_362_ = !lean_is_exclusive(v___x_352_);
if (v_isSharedCheck_362_ == 0)
{
v___x_356_ = v___x_352_;
v_isShared_357_ = v_isSharedCheck_362_;
goto v_resetjp_355_;
}
else
{
lean_inc(v_val_354_);
lean_dec(v___x_352_);
v___x_356_ = lean_box(0);
v_isShared_357_ = v_isSharedCheck_362_;
goto v_resetjp_355_;
}
v_resetjp_355_:
{
lean_object* v___x_358_; lean_object* v___x_360_; 
v___x_358_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_val_354_);
if (v_isShared_357_ == 0)
{
lean_ctor_set(v___x_356_, 0, v___x_358_);
v___x_360_ = v___x_356_;
goto v_reusejp_359_;
}
else
{
lean_object* v_reuseFailAlloc_361_; 
v_reuseFailAlloc_361_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_361_, 0, v___x_358_);
v___x_360_ = v_reuseFailAlloc_361_;
goto v_reusejp_359_;
}
v_reusejp_359_:
{
v___y_176_ = v___x_351_;
v___y_177_ = v___x_360_;
goto v___jp_175_;
}
}
}
}
}
else
{
lean_object* v___x_363_; lean_object* v___x_364_; lean_object* v___x_365_; lean_object* v___x_366_; lean_object* v___x_367_; lean_object* v___x_368_; lean_object* v___x_369_; lean_object* v___x_370_; lean_object* v___x_371_; lean_object* v___x_372_; lean_object* v___x_373_; 
lean_dec(v_tc_342_);
v___x_363_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__8));
v___x_364_ = lean_unsigned_to_nat(13u);
v___x_365_ = lean_unsigned_to_nat(12u);
v___x_366_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_174_, v___x_365_, v___x_364_);
v___x_367_ = l_BitVec_ofNat(v___x_364_, v___x_366_);
lean_dec(v___x_366_);
v___x_368_ = lp_lean1090_Lean1090_Impl_identityCode(v___x_367_);
lean_dec(v___x_367_);
v___x_369_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_368_);
v___x_370_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_370_, 0, v___x_369_);
v___x_371_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_371_, 0, v___x_363_);
lean_ctor_set(v___x_371_, 1, v___x_370_);
v___x_372_ = lean_box(0);
v___x_373_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_373_, 0, v___x_371_);
lean_ctor_set(v___x_373_, 1, v___x_372_);
return v___x_373_;
}
}
else
{
lean_object* v_components_374_; lean_object* v___x_375_; lean_object* v___x_376_; lean_object* v_subtype_377_; lean_object* v___x_378_; 
lean_dec(v_tc_342_);
v_components_374_ = lp_lean1090_Lean1090_Impl_Presentation_standardVelocityComponents(v_word_174_);
v___x_375_ = lean_unsigned_to_nat(6u);
v___x_376_ = lean_unsigned_to_nat(3u);
v_subtype_377_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_174_, v___x_375_, v___x_376_);
v___x_378_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__9));
if (lean_obj_tag(v_components_374_) == 0)
{
lean_object* v___x_379_; 
v___x_379_ = lean_box(0);
v___y_270_ = v___x_378_;
v___y_271_ = v_subtype_377_;
v___y_272_ = v_components_374_;
v___y_273_ = v___x_376_;
v___y_274_ = v___x_379_;
goto v___jp_269_;
}
else
{
lean_object* v_val_380_; lean_object* v_fst_381_; lean_object* v___x_382_; lean_object* v___x_383_; 
v_val_380_ = lean_ctor_get(v_components_374_, 0);
lean_inc(v_val_380_);
v_fst_381_ = lean_ctor_get(v_val_380_, 0);
lean_inc(v_fst_381_);
lean_dec(v_val_380_);
v___x_382_ = l_Rat_ofInt(v_fst_381_);
v___x_383_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_383_, 0, v___x_382_);
v___y_270_ = v___x_378_;
v___y_271_ = v_subtype_377_;
v___y_272_ = v_components_374_;
v___y_273_ = v___x_376_;
v___y_274_ = v___x_383_;
goto v___jp_269_;
}
}
}
v___jp_384_:
{
lean_object* v___x_386_; lean_object* v___x_387_; lean_object* v___x_388_; lean_object* v___x_389_; lean_object* v___x_390_; lean_object* v___x_391_; lean_object* v___x_392_; uint8_t v___x_393_; 
v___x_386_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__10));
v___x_387_ = lp_lean1090_Lean1090_Impl_adsbNUCp(v_tc_342_);
v___x_388_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_387_);
v___x_389_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_389_, 0, v___x_388_);
v___x_390_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_390_, 0, v___x_386_);
lean_ctor_set(v___x_390_, 1, v___x_389_);
v___x_391_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__11));
v___x_392_ = lean_unsigned_to_nat(19u);
v___x_393_ = lean_nat_dec_lt(v_tc_342_, v___x_392_);
lean_dec(v_tc_342_);
if (v___x_393_ == 0)
{
lean_object* v___x_394_; 
v___x_394_ = lean_box(0);
v___y_319_ = v___x_393_;
v___y_320_ = v___x_390_;
v___y_321_ = v___y_385_;
v___y_322_ = v___x_391_;
v___y_323_ = v___x_394_;
goto v___jp_318_;
}
else
{
lean_object* v___x_395_; lean_object* v___x_396_; lean_object* v___x_397_; lean_object* v___x_398_; 
v___x_395_ = lean_unsigned_to_nat(8u);
v___x_396_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_174_, v___x_395_, v___x_340_);
v___x_397_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_396_);
v___x_398_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_398_, 0, v___x_397_);
v___y_319_ = v___x_393_;
v___y_320_ = v___x_390_;
v___y_321_ = v___y_385_;
v___y_322_ = v___x_391_;
v___y_323_ = v___x_398_;
goto v___jp_318_;
}
}
v___jp_399_:
{
lean_object* v___x_401_; uint8_t v___x_402_; 
v___x_401_ = lean_unsigned_to_nat(20u);
v___x_402_ = lean_nat_dec_le(v___x_401_, v_tc_342_);
if (v___x_402_ == 0)
{
goto v___jp_343_;
}
else
{
lean_object* v___x_403_; uint8_t v___x_404_; 
v___x_403_ = lean_unsigned_to_nat(22u);
v___x_404_ = lean_nat_dec_le(v_tc_342_, v___x_403_);
if (v___x_404_ == 0)
{
goto v___jp_343_;
}
else
{
v___y_385_ = v___y_400_;
goto v___jp_384_;
}
}
}
v___jp_405_:
{
lean_object* v___x_406_; uint8_t v___x_407_; 
v___x_406_ = lean_unsigned_to_nat(9u);
v___x_407_ = lean_nat_dec_le(v___x_406_, v_tc_342_);
if (v___x_407_ == 0)
{
v___y_400_ = v___x_406_;
goto v___jp_399_;
}
else
{
lean_object* v___x_408_; uint8_t v___x_409_; 
v___x_408_ = lean_unsigned_to_nat(18u);
v___x_409_ = lean_nat_dec_le(v_tc_342_, v___x_408_);
if (v___x_409_ == 0)
{
v___y_400_ = v___x_406_;
goto v___jp_399_;
}
else
{
v___y_385_ = v___x_406_;
goto v___jp_384_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___boxed(lean_object* v_word_427_){
_start:
{
lean_object* v_res_428_; 
v_res_428_ = lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues(v_word_427_);
lean_dec(v_word_427_);
return v_res_428_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_oracleReservedVelocityData(lean_object* v_word_429_){
_start:
{
lean_object* v___x_430_; lean_object* v___x_431_; lean_object* v___x_432_; lean_object* v___x_433_; lean_object* v___x_434_; lean_object* v___x_435_; lean_object* v___x_436_; lean_object* v___x_437_; lean_object* v___x_438_; lean_object* v___x_439_; lean_object* v___x_440_; lean_object* v___x_441_; lean_object* v___x_442_; lean_object* v___x_443_; 
v___x_430_ = lean_unsigned_to_nat(14u);
v___x_431_ = lean_unsigned_to_nat(8u);
v___x_432_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_429_, v___x_430_, v___x_431_);
v___x_433_ = lean_unsigned_to_nat(256u);
v___x_434_ = lean_unsigned_to_nat(22u);
v___x_435_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_429_, v___x_434_, v___x_431_);
v___x_436_ = lean_nat_mul(v___x_433_, v___x_435_);
lean_dec(v___x_435_);
v___x_437_ = lean_nat_add(v___x_432_, v___x_436_);
lean_dec(v___x_436_);
lean_dec(v___x_432_);
v___x_438_ = lean_unsigned_to_nat(65536u);
v___x_439_ = lean_unsigned_to_nat(30u);
v___x_440_ = lean_unsigned_to_nat(6u);
v___x_441_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_429_, v___x_439_, v___x_440_);
v___x_442_ = lean_nat_mul(v___x_438_, v___x_441_);
lean_dec(v___x_441_);
v___x_443_ = lean_nat_add(v___x_437_, v___x_442_);
lean_dec(v___x_442_);
lean_dec(v___x_437_);
return v___x_443_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_oracleReservedVelocityData___boxed(lean_object* v_word_444_){
_start:
{
lean_object* v_res_445_; 
v_res_445_ = lp_lean1090_Lean1090_Impl_Semantics_oracleReservedVelocityData(v_word_444_);
lean_dec(v_word_444_);
return v_res_445_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbOracleValues(lean_object* v_word_447_){
_start:
{
lean_object* v___y_449_; lean_object* v___y_450_; lean_object* v___y_459_; lean_object* v___y_460_; lean_object* v___y_461_; lean_object* v___y_462_; lean_object* v___y_469_; lean_object* v___y_470_; lean_object* v___y_471_; lean_object* v___x_485_; lean_object* v___x_486_; lean_object* v___y_488_; lean_object* v___y_489_; lean_object* v___y_490_; lean_object* v___y_491_; lean_object* v___y_492_; lean_object* v___y_493_; lean_object* v___y_494_; lean_object* v___y_507_; lean_object* v___y_508_; lean_object* v___y_509_; lean_object* v___y_510_; lean_object* v___y_511_; lean_object* v___y_512_; lean_object* v___y_525_; lean_object* v___y_526_; lean_object* v___y_527_; lean_object* v___y_528_; lean_object* v___y_529_; lean_object* v___y_530_; lean_object* v___y_531_; lean_object* v___y_539_; lean_object* v___y_540_; lean_object* v___y_541_; lean_object* v___y_542_; lean_object* v___y_543_; lean_object* v___y_544_; lean_object* v___y_559_; lean_object* v___y_560_; lean_object* v___y_561_; lean_object* v___y_562_; lean_object* v___y_563_; lean_object* v___y_578_; uint8_t v___y_579_; lean_object* v___y_580_; lean_object* v___y_581_; lean_object* v___y_582_; lean_object* v___y_583_; lean_object* v___y_590_; lean_object* v___y_591_; lean_object* v___y_592_; lean_object* v___y_593_; lean_object* v___y_594_; uint8_t v___y_595_; lean_object* v_tc_599_; lean_object* v___x_633_; uint8_t v___x_634_; 
v___x_485_ = lean_unsigned_to_nat(1u);
v___x_486_ = lean_unsigned_to_nat(5u);
v_tc_599_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_447_, v___x_485_, v___x_486_);
v___x_633_ = lean_unsigned_to_nat(9u);
v___x_634_ = lean_nat_dec_le(v___x_633_, v_tc_599_);
if (v___x_634_ == 0)
{
goto v___jp_628_;
}
else
{
lean_object* v___x_635_; uint8_t v___x_636_; 
v___x_635_ = lean_unsigned_to_nat(18u);
v___x_636_ = lean_nat_dec_le(v_tc_599_, v___x_635_);
if (v___x_636_ == 0)
{
goto v___jp_628_;
}
else
{
goto v___jp_614_;
}
}
v___jp_448_:
{
lean_object* v___x_451_; lean_object* v___x_452_; lean_object* v___x_453_; lean_object* v___x_454_; lean_object* v___x_455_; lean_object* v___x_456_; lean_object* v___x_457_; 
v___x_451_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbOracleValues___closed__0));
v___x_452_ = lp_lean1090_Lean1090_Impl_Semantics_oracleReservedVelocityData(v_word_447_);
v___x_453_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_452_);
v___x_454_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_454_, 0, v___x_453_);
v___x_455_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_455_, 0, v___x_451_);
lean_ctor_set(v___x_455_, 1, v___x_454_);
v___x_456_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_456_, 0, v___x_455_);
lean_ctor_set(v___x_456_, 1, v___y_449_);
v___x_457_ = l_List_appendTR___redArg(v___y_450_, v___x_456_);
return v___x_457_;
}
v___jp_458_:
{
lean_object* v___x_463_; lean_object* v___x_464_; lean_object* v___x_465_; lean_object* v___x_466_; lean_object* v___x_467_; 
lean_inc_ref(v___y_461_);
v___x_463_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_463_, 0, v___y_461_);
lean_ctor_set(v___x_463_, 1, v___y_462_);
v___x_464_ = lean_box(0);
v___x_465_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_465_, 0, v___x_463_);
lean_ctor_set(v___x_465_, 1, v___x_464_);
v___x_466_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_466_, 0, v___y_460_);
lean_ctor_set(v___x_466_, 1, v___x_465_);
v___x_467_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_467_, 0, v___y_459_);
lean_ctor_set(v___x_467_, 1, v___x_466_);
return v___x_467_;
}
v___jp_468_:
{
lean_object* v___x_472_; lean_object* v___x_473_; lean_object* v___x_474_; 
lean_inc_ref(v___y_469_);
v___x_472_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_472_, 0, v___y_469_);
lean_ctor_set(v___x_472_, 1, v___y_471_);
v___x_473_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__6));
v___x_474_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_word_447_);
if (lean_obj_tag(v___x_474_) == 0)
{
lean_object* v___x_475_; 
v___x_475_ = lean_box(0);
v___y_459_ = v___y_470_;
v___y_460_ = v___x_472_;
v___y_461_ = v___x_473_;
v___y_462_ = v___x_475_;
goto v___jp_458_;
}
else
{
lean_object* v_val_476_; lean_object* v___x_478_; uint8_t v_isShared_479_; uint8_t v_isSharedCheck_484_; 
v_val_476_ = lean_ctor_get(v___x_474_, 0);
v_isSharedCheck_484_ = !lean_is_exclusive(v___x_474_);
if (v_isSharedCheck_484_ == 0)
{
v___x_478_ = v___x_474_;
v_isShared_479_ = v_isSharedCheck_484_;
goto v_resetjp_477_;
}
else
{
lean_inc(v_val_476_);
lean_dec(v___x_474_);
v___x_478_ = lean_box(0);
v_isShared_479_ = v_isSharedCheck_484_;
goto v_resetjp_477_;
}
v_resetjp_477_:
{
lean_object* v___x_480_; lean_object* v___x_482_; 
v___x_480_ = l_Rat_ofInt(v_val_476_);
if (v_isShared_479_ == 0)
{
lean_ctor_set(v___x_478_, 0, v___x_480_);
v___x_482_ = v___x_478_;
goto v_reusejp_481_;
}
else
{
lean_object* v_reuseFailAlloc_483_; 
v_reuseFailAlloc_483_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_483_, 0, v___x_480_);
v___x_482_ = v_reuseFailAlloc_483_;
goto v_reusejp_481_;
}
v_reusejp_481_:
{
v___y_459_ = v___y_470_;
v___y_460_ = v___x_472_;
v___y_461_ = v___x_473_;
v___y_462_ = v___x_482_;
goto v___jp_458_;
}
}
}
}
v___jp_487_:
{
lean_object* v___x_495_; lean_object* v___x_496_; lean_object* v___x_497_; lean_object* v___x_498_; lean_object* v___x_499_; lean_object* v___x_500_; lean_object* v___x_501_; lean_object* v___x_502_; uint8_t v___x_503_; 
lean_inc_ref(v___y_488_);
v___x_495_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_495_, 0, v___y_488_);
lean_ctor_set(v___x_495_, 1, v___y_494_);
v___x_496_ = lean_box(0);
v___x_497_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_497_, 0, v___x_495_);
lean_ctor_set(v___x_497_, 1, v___x_496_);
v___x_498_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_498_, 0, v___y_492_);
lean_ctor_set(v___x_498_, 1, v___x_497_);
v___x_499_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_499_, 0, v___y_493_);
lean_ctor_set(v___x_499_, 1, v___x_498_);
v___x_500_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_500_, 0, v___y_490_);
lean_ctor_set(v___x_500_, 1, v___x_499_);
v___x_501_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_501_, 0, v___y_489_);
lean_ctor_set(v___x_501_, 1, v___x_500_);
v___x_502_ = lean_unsigned_to_nat(0u);
v___x_503_ = lean_nat_dec_eq(v___y_491_, v___x_502_);
if (v___x_503_ == 0)
{
uint8_t v___x_504_; 
v___x_504_ = lean_nat_dec_le(v___x_486_, v___y_491_);
lean_dec(v___y_491_);
if (v___x_504_ == 0)
{
lean_object* v___x_505_; 
v___x_505_ = l_List_appendTR___redArg(v___x_501_, v___x_496_);
return v___x_505_;
}
else
{
v___y_449_ = v___x_496_;
v___y_450_ = v___x_501_;
goto v___jp_448_;
}
}
else
{
lean_dec(v___y_491_);
v___y_449_ = v___x_496_;
v___y_450_ = v___x_501_;
goto v___jp_448_;
}
}
v___jp_506_:
{
lean_object* v___x_513_; 
v___x_513_ = lp_lean1090_Lean1090_Impl_adsbAirspeed(v_word_447_);
if (lean_obj_tag(v___x_513_) == 0)
{
lean_object* v___x_514_; 
v___x_514_ = lean_box(0);
v___y_488_ = v___y_507_;
v___y_489_ = v___y_508_;
v___y_490_ = v___y_509_;
v___y_491_ = v___y_511_;
v___y_492_ = v___y_510_;
v___y_493_ = v___y_512_;
v___y_494_ = v___x_514_;
goto v___jp_487_;
}
else
{
lean_object* v_val_515_; lean_object* v___x_517_; uint8_t v_isShared_518_; uint8_t v_isSharedCheck_523_; 
v_val_515_ = lean_ctor_get(v___x_513_, 0);
v_isSharedCheck_523_ = !lean_is_exclusive(v___x_513_);
if (v_isSharedCheck_523_ == 0)
{
v___x_517_ = v___x_513_;
v_isShared_518_ = v_isSharedCheck_523_;
goto v_resetjp_516_;
}
else
{
lean_inc(v_val_515_);
lean_dec(v___x_513_);
v___x_517_ = lean_box(0);
v_isShared_518_ = v_isSharedCheck_523_;
goto v_resetjp_516_;
}
v_resetjp_516_:
{
lean_object* v___x_519_; lean_object* v___x_521_; 
v___x_519_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_val_515_);
if (v_isShared_518_ == 0)
{
lean_ctor_set(v___x_517_, 0, v___x_519_);
v___x_521_ = v___x_517_;
goto v_reusejp_520_;
}
else
{
lean_object* v_reuseFailAlloc_522_; 
v_reuseFailAlloc_522_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_522_, 0, v___x_519_);
v___x_521_ = v_reuseFailAlloc_522_;
goto v_reusejp_520_;
}
v_reusejp_520_:
{
v___y_488_ = v___y_507_;
v___y_489_ = v___y_508_;
v___y_490_ = v___y_509_;
v___y_491_ = v___y_511_;
v___y_492_ = v___y_510_;
v___y_493_ = v___y_512_;
v___y_494_ = v___x_521_;
goto v___jp_487_;
}
}
}
}
v___jp_524_:
{
lean_object* v___x_532_; lean_object* v___x_533_; uint8_t v___x_534_; 
lean_inc_ref(v___y_526_);
v___x_532_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_532_, 0, v___y_526_);
lean_ctor_set(v___x_532_, 1, v___y_531_);
v___x_533_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__1));
v___x_534_ = lean_nat_dec_eq(v___y_529_, v___y_525_);
if (v___x_534_ == 0)
{
lean_object* v___x_535_; uint8_t v___x_536_; 
v___x_535_ = lean_unsigned_to_nat(4u);
v___x_536_ = lean_nat_dec_eq(v___y_529_, v___x_535_);
if (v___x_536_ == 0)
{
lean_object* v___x_537_; 
v___x_537_ = lean_box(0);
v___y_488_ = v___x_533_;
v___y_489_ = v___y_527_;
v___y_490_ = v___y_528_;
v___y_491_ = v___y_529_;
v___y_492_ = v___x_532_;
v___y_493_ = v___y_530_;
v___y_494_ = v___x_537_;
goto v___jp_487_;
}
else
{
v___y_507_ = v___x_533_;
v___y_508_ = v___y_527_;
v___y_509_ = v___y_528_;
v___y_510_ = v___x_532_;
v___y_511_ = v___y_529_;
v___y_512_ = v___y_530_;
goto v___jp_506_;
}
}
else
{
v___y_507_ = v___x_533_;
v___y_508_ = v___y_527_;
v___y_509_ = v___y_528_;
v___y_510_ = v___x_532_;
v___y_511_ = v___y_529_;
v___y_512_ = v___y_530_;
goto v___jp_506_;
}
}
v___jp_538_:
{
lean_object* v___x_545_; lean_object* v___x_546_; lean_object* v___x_547_; 
lean_inc_ref(v___y_542_);
v___x_545_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_545_, 0, v___y_542_);
lean_ctor_set(v___x_545_, 1, v___y_544_);
v___x_546_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__2));
v___x_547_ = lp_lean1090_Lean1090_Impl_adsbGeoMinusBaro(v_word_447_);
if (lean_obj_tag(v___x_547_) == 0)
{
lean_object* v___x_548_; 
v___x_548_ = lean_box(0);
v___y_525_ = v___y_539_;
v___y_526_ = v___x_546_;
v___y_527_ = v___y_540_;
v___y_528_ = v___y_541_;
v___y_529_ = v___y_543_;
v___y_530_ = v___x_545_;
v___y_531_ = v___x_548_;
goto v___jp_524_;
}
else
{
lean_object* v_val_549_; lean_object* v___x_551_; uint8_t v_isShared_552_; uint8_t v_isSharedCheck_557_; 
v_val_549_ = lean_ctor_get(v___x_547_, 0);
v_isSharedCheck_557_ = !lean_is_exclusive(v___x_547_);
if (v_isSharedCheck_557_ == 0)
{
v___x_551_ = v___x_547_;
v_isShared_552_ = v_isSharedCheck_557_;
goto v_resetjp_550_;
}
else
{
lean_inc(v_val_549_);
lean_dec(v___x_547_);
v___x_551_ = lean_box(0);
v_isShared_552_ = v_isSharedCheck_557_;
goto v_resetjp_550_;
}
v_resetjp_550_:
{
lean_object* v___x_553_; lean_object* v___x_555_; 
v___x_553_ = l_Rat_ofInt(v_val_549_);
if (v_isShared_552_ == 0)
{
lean_ctor_set(v___x_551_, 0, v___x_553_);
v___x_555_ = v___x_551_;
goto v_reusejp_554_;
}
else
{
lean_object* v_reuseFailAlloc_556_; 
v_reuseFailAlloc_556_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_556_, 0, v___x_553_);
v___x_555_ = v_reuseFailAlloc_556_;
goto v_reusejp_554_;
}
v_reusejp_554_:
{
v___y_525_ = v___y_539_;
v___y_526_ = v___x_546_;
v___y_527_ = v___y_540_;
v___y_528_ = v___y_541_;
v___y_529_ = v___y_543_;
v___y_530_ = v___x_545_;
v___y_531_ = v___x_555_;
goto v___jp_524_;
}
}
}
}
v___jp_558_:
{
lean_object* v___x_564_; lean_object* v___x_565_; lean_object* v___x_566_; 
lean_inc_ref(v___y_561_);
v___x_564_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_564_, 0, v___y_561_);
lean_ctor_set(v___x_564_, 1, v___y_563_);
v___x_565_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__3));
v___x_566_ = lp_lean1090_Lean1090_Impl_adsbVerticalRate(v_word_447_);
if (lean_obj_tag(v___x_566_) == 0)
{
lean_object* v___x_567_; 
v___x_567_ = lean_box(0);
v___y_539_ = v___y_559_;
v___y_540_ = v___y_560_;
v___y_541_ = v___x_564_;
v___y_542_ = v___x_565_;
v___y_543_ = v___y_562_;
v___y_544_ = v___x_567_;
goto v___jp_538_;
}
else
{
lean_object* v_val_568_; lean_object* v___x_570_; uint8_t v_isShared_571_; uint8_t v_isSharedCheck_576_; 
v_val_568_ = lean_ctor_get(v___x_566_, 0);
v_isSharedCheck_576_ = !lean_is_exclusive(v___x_566_);
if (v_isSharedCheck_576_ == 0)
{
v___x_570_ = v___x_566_;
v_isShared_571_ = v_isSharedCheck_576_;
goto v_resetjp_569_;
}
else
{
lean_inc(v_val_568_);
lean_dec(v___x_566_);
v___x_570_ = lean_box(0);
v_isShared_571_ = v_isSharedCheck_576_;
goto v_resetjp_569_;
}
v_resetjp_569_:
{
lean_object* v___x_572_; lean_object* v___x_574_; 
v___x_572_ = l_Rat_ofInt(v_val_568_);
if (v_isShared_571_ == 0)
{
lean_ctor_set(v___x_570_, 0, v___x_572_);
v___x_574_ = v___x_570_;
goto v_reusejp_573_;
}
else
{
lean_object* v_reuseFailAlloc_575_; 
v_reuseFailAlloc_575_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_575_, 0, v___x_572_);
v___x_574_ = v_reuseFailAlloc_575_;
goto v_reusejp_573_;
}
v_reusejp_573_:
{
v___y_539_ = v___y_559_;
v___y_540_ = v___y_560_;
v___y_541_ = v___x_564_;
v___y_542_ = v___x_565_;
v___y_543_ = v___y_562_;
v___y_544_ = v___x_574_;
goto v___jp_538_;
}
}
}
}
v___jp_577_:
{
lean_object* v___x_584_; lean_object* v___x_585_; 
lean_inc_ref(v___y_580_);
v___x_584_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_584_, 0, v___y_580_);
lean_ctor_set(v___x_584_, 1, v___y_583_);
v___x_585_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__4));
if (v___y_579_ == 0)
{
lean_object* v___x_586_; 
lean_dec(v___y_581_);
v___x_586_ = lean_box(0);
v___y_559_ = v___y_578_;
v___y_560_ = v___x_584_;
v___y_561_ = v___x_585_;
v___y_562_ = v___y_582_;
v___y_563_ = v___x_586_;
goto v___jp_558_;
}
else
{
lean_object* v___x_587_; lean_object* v___x_588_; 
v___x_587_ = l_Rat_ofInt(v___y_581_);
v___x_588_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_588_, 0, v___x_587_);
v___y_559_ = v___y_578_;
v___y_560_ = v___x_584_;
v___y_561_ = v___x_585_;
v___y_562_ = v___y_582_;
v___y_563_ = v___x_588_;
goto v___jp_558_;
}
}
v___jp_589_:
{
if (v___y_595_ == 0)
{
lean_object* v___x_596_; 
lean_dec(v___y_592_);
v___x_596_ = lean_box(0);
v___y_578_ = v___y_590_;
v___y_579_ = v___y_595_;
v___y_580_ = v___y_591_;
v___y_581_ = v___y_593_;
v___y_582_ = v___y_594_;
v___y_583_ = v___x_596_;
goto v___jp_577_;
}
else
{
lean_object* v___x_597_; lean_object* v___x_598_; 
v___x_597_ = l_Rat_ofInt(v___y_592_);
v___x_598_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_598_, 0, v___x_597_);
v___y_578_ = v___y_590_;
v___y_579_ = v___y_595_;
v___y_580_ = v___y_591_;
v___y_581_ = v___y_593_;
v___y_582_ = v___y_594_;
v___y_583_ = v___x_598_;
goto v___jp_577_;
}
}
v___jp_600_:
{
lean_object* v___x_601_; uint8_t v___x_602_; 
v___x_601_ = lean_unsigned_to_nat(19u);
v___x_602_ = lean_nat_dec_eq(v_tc_599_, v___x_601_);
lean_dec(v_tc_599_);
if (v___x_602_ == 0)
{
lean_object* v___x_603_; 
v___x_603_ = lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues(v_word_447_);
return v___x_603_;
}
else
{
lean_object* v___x_604_; lean_object* v_fst_605_; lean_object* v_snd_606_; lean_object* v___x_607_; lean_object* v___x_608_; lean_object* v_subtype_609_; lean_object* v___x_610_; uint8_t v___x_611_; 
v___x_604_ = lp_lean1090_Lean1090_Impl_adsbOracleVelocityComponents(v_word_447_);
v_fst_605_ = lean_ctor_get(v___x_604_, 0);
lean_inc(v_fst_605_);
v_snd_606_ = lean_ctor_get(v___x_604_, 1);
lean_inc(v_snd_606_);
lean_dec_ref(v___x_604_);
v___x_607_ = lean_unsigned_to_nat(6u);
v___x_608_ = lean_unsigned_to_nat(3u);
v_subtype_609_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_447_, v___x_607_, v___x_608_);
v___x_610_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__9));
v___x_611_ = lean_nat_dec_eq(v_subtype_609_, v___x_485_);
if (v___x_611_ == 0)
{
lean_object* v___x_612_; uint8_t v___x_613_; 
v___x_612_ = lean_unsigned_to_nat(2u);
v___x_613_ = lean_nat_dec_eq(v_subtype_609_, v___x_612_);
v___y_590_ = v___x_608_;
v___y_591_ = v___x_610_;
v___y_592_ = v_fst_605_;
v___y_593_ = v_snd_606_;
v___y_594_ = v_subtype_609_;
v___y_595_ = v___x_613_;
goto v___jp_589_;
}
else
{
v___y_590_ = v___x_608_;
v___y_591_ = v___x_610_;
v___y_592_ = v_fst_605_;
v___y_593_ = v_snd_606_;
v___y_594_ = v_subtype_609_;
v___y_595_ = v___x_611_;
goto v___jp_589_;
}
}
}
v___jp_614_:
{
lean_object* v___x_615_; lean_object* v___x_616_; lean_object* v___x_617_; lean_object* v___x_618_; lean_object* v___x_619_; lean_object* v___x_620_; lean_object* v___x_621_; uint8_t v___x_622_; 
v___x_615_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__10));
v___x_616_ = lp_lean1090_Lean1090_Impl_adsbNUCp(v_tc_599_);
v___x_617_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_616_);
v___x_618_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_618_, 0, v___x_617_);
v___x_619_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_619_, 0, v___x_615_);
lean_ctor_set(v___x_619_, 1, v___x_618_);
v___x_620_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__11));
v___x_621_ = lean_unsigned_to_nat(19u);
v___x_622_ = lean_nat_dec_lt(v_tc_599_, v___x_621_);
lean_dec(v_tc_599_);
if (v___x_622_ == 0)
{
lean_object* v___x_623_; 
v___x_623_ = lean_box(0);
v___y_469_ = v___x_620_;
v___y_470_ = v___x_619_;
v___y_471_ = v___x_623_;
goto v___jp_468_;
}
else
{
lean_object* v___x_624_; lean_object* v___x_625_; lean_object* v___x_626_; lean_object* v___x_627_; 
v___x_624_ = lean_unsigned_to_nat(8u);
v___x_625_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_447_, v___x_624_, v___x_485_);
v___x_626_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_625_);
v___x_627_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_627_, 0, v___x_626_);
v___y_469_ = v___x_620_;
v___y_470_ = v___x_619_;
v___y_471_ = v___x_627_;
goto v___jp_468_;
}
}
v___jp_628_:
{
lean_object* v___x_629_; uint8_t v___x_630_; 
v___x_629_ = lean_unsigned_to_nat(20u);
v___x_630_ = lean_nat_dec_le(v___x_629_, v_tc_599_);
if (v___x_630_ == 0)
{
goto v___jp_600_;
}
else
{
lean_object* v___x_631_; uint8_t v___x_632_; 
v___x_631_ = lean_unsigned_to_nat(22u);
v___x_632_ = lean_nat_dec_le(v_tc_599_, v___x_631_);
if (v___x_632_ == 0)
{
goto v___jp_600_;
}
else
{
goto v___jp_614_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbOracleValues___boxed(lean_object* v_word_637_){
_start:
{
lean_object* v_res_638_; 
v_res_638_ = lp_lean1090_Lean1090_Impl_Semantics_adsbOracleValues(v_word_637_);
lean_dec(v_word_637_);
return v_res_638_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels(uint8_t v_oracle_664_, lean_object* v_word_665_){
_start:
{
lean_object* v___y_667_; lean_object* v___y_668_; lean_object* v___y_674_; lean_object* v___y_675_; lean_object* v___y_681_; lean_object* v___y_682_; lean_object* v___y_683_; lean_object* v___y_689_; lean_object* v___y_690_; lean_object* v___y_691_; lean_object* v___x_693_; lean_object* v___y_695_; lean_object* v___y_696_; lean_object* v___y_704_; lean_object* v___y_705_; lean_object* v___x_716_; lean_object* v_tc_717_; lean_object* v___y_725_; lean_object* v___y_760_; uint8_t v___x_770_; 
v___x_693_ = lean_unsigned_to_nat(1u);
v___x_716_ = lean_unsigned_to_nat(5u);
v_tc_717_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_665_, v___x_693_, v___x_716_);
v___x_770_ = lean_nat_dec_le(v___x_693_, v_tc_717_);
if (v___x_770_ == 0)
{
goto v___jp_765_;
}
else
{
lean_object* v___x_771_; uint8_t v___x_772_; 
v___x_771_ = lean_unsigned_to_nat(4u);
v___x_772_ = lean_nat_dec_le(v_tc_717_, v___x_771_);
if (v___x_772_ == 0)
{
goto v___jp_765_;
}
else
{
lean_object* v___x_773_; lean_object* v___x_774_; lean_object* v___x_775_; lean_object* v___x_776_; lean_object* v___x_777_; lean_object* v___x_778_; lean_object* v___x_779_; lean_object* v___x_780_; lean_object* v___x_781_; lean_object* v___x_782_; lean_object* v___x_783_; lean_object* v___x_784_; lean_object* v___x_785_; lean_object* v___x_786_; 
v___x_773_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__17));
v___x_774_ = lp_lean1090_Lean1090_Impl_adsbCallsign(v_word_665_);
v___x_775_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_775_, 0, v___x_774_);
v___x_776_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_776_, 0, v___x_773_);
lean_ctor_set(v___x_776_, 1, v___x_775_);
v___x_777_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__18));
v___x_778_ = lean_unsigned_to_nat(6u);
v___x_779_ = lean_unsigned_to_nat(3u);
v___x_780_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_665_, v___x_778_, v___x_779_);
v___x_781_ = lp_lean1090_Lean1090_Impl_Semantics_wakeVortex(v_tc_717_, v___x_780_);
lean_dec(v_tc_717_);
v___x_782_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_782_, 0, v___x_781_);
v___x_783_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_783_, 0, v___x_777_);
lean_ctor_set(v___x_783_, 1, v___x_782_);
v___x_784_ = lean_box(0);
v___x_785_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_785_, 0, v___x_783_);
lean_ctor_set(v___x_785_, 1, v___x_784_);
v___x_786_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_786_, 0, v___x_776_);
lean_ctor_set(v___x_786_, 1, v___x_785_);
return v___x_786_;
}
}
v___jp_666_:
{
lean_object* v___x_669_; lean_object* v___x_670_; lean_object* v___x_671_; lean_object* v___x_672_; 
lean_inc_ref(v___y_668_);
v___x_669_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_669_, 0, v___y_668_);
lean_inc_ref(v___y_667_);
v___x_670_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_670_, 0, v___y_667_);
lean_ctor_set(v___x_670_, 1, v___x_669_);
v___x_671_ = lean_box(0);
v___x_672_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_672_, 0, v___x_670_);
lean_ctor_set(v___x_672_, 1, v___x_671_);
return v___x_672_;
}
v___jp_673_:
{
lean_object* v___x_676_; lean_object* v___x_677_; lean_object* v___x_678_; lean_object* v___x_679_; 
lean_inc_ref(v___y_675_);
v___x_676_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_676_, 0, v___y_675_);
lean_inc_ref(v___y_674_);
v___x_677_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_677_, 0, v___y_674_);
lean_ctor_set(v___x_677_, 1, v___x_676_);
v___x_678_ = lean_box(0);
v___x_679_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_679_, 0, v___x_677_);
lean_ctor_set(v___x_679_, 1, v___x_678_);
return v___x_679_;
}
v___jp_680_:
{
lean_object* v___x_684_; lean_object* v___x_685_; lean_object* v___x_686_; lean_object* v___x_687_; 
lean_inc_ref(v___y_682_);
v___x_684_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_684_, 0, v___y_682_);
lean_ctor_set(v___x_684_, 1, v___y_683_);
v___x_685_ = lean_box(0);
v___x_686_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_686_, 0, v___x_684_);
lean_ctor_set(v___x_686_, 1, v___x_685_);
v___x_687_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_687_, 0, v___y_681_);
lean_ctor_set(v___x_687_, 1, v___x_686_);
return v___x_687_;
}
v___jp_688_:
{
lean_object* v___x_692_; 
lean_inc_ref(v___y_691_);
v___x_692_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_692_, 0, v___y_691_);
v___y_681_ = v___y_689_;
v___y_682_ = v___y_690_;
v___y_683_ = v___x_692_;
goto v___jp_680_;
}
v___jp_694_:
{
lean_object* v___x_697_; lean_object* v___x_698_; lean_object* v___x_699_; uint8_t v___x_700_; 
v___x_697_ = lean_unsigned_to_nat(25u);
v___x_698_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_665_, v___x_697_, v___x_693_);
v___x_699_ = lean_unsigned_to_nat(0u);
v___x_700_ = lean_nat_dec_eq(v___x_698_, v___x_699_);
lean_dec(v___x_698_);
if (v___x_700_ == 0)
{
lean_object* v___x_701_; 
v___x_701_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__0));
v___y_689_ = v___y_695_;
v___y_690_ = v___y_696_;
v___y_691_ = v___x_701_;
goto v___jp_688_;
}
else
{
lean_object* v___x_702_; 
v___x_702_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__1));
v___y_689_ = v___y_695_;
v___y_690_ = v___y_696_;
v___y_691_ = v___x_702_;
goto v___jp_688_;
}
}
v___jp_703_:
{
lean_object* v___x_706_; lean_object* v___x_707_; lean_object* v___x_708_; lean_object* v___x_709_; lean_object* v___x_710_; lean_object* v___x_711_; uint8_t v___x_712_; 
v___x_706_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_706_, 0, v___y_705_);
lean_inc_ref(v___y_704_);
v___x_707_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_707_, 0, v___y_704_);
lean_ctor_set(v___x_707_, 1, v___x_706_);
v___x_708_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__2));
v___x_709_ = lean_unsigned_to_nat(6u);
v___x_710_ = lean_unsigned_to_nat(3u);
v___x_711_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_665_, v___x_709_, v___x_710_);
v___x_712_ = lean_nat_dec_eq(v___x_711_, v___x_710_);
if (v___x_712_ == 0)
{
lean_object* v___x_713_; uint8_t v___x_714_; 
v___x_713_ = lean_unsigned_to_nat(4u);
v___x_714_ = lean_nat_dec_eq(v___x_711_, v___x_713_);
lean_dec(v___x_711_);
if (v___x_714_ == 0)
{
lean_object* v___x_715_; 
v___x_715_ = lean_box(0);
v___y_681_ = v___x_707_;
v___y_682_ = v___x_708_;
v___y_683_ = v___x_715_;
goto v___jp_680_;
}
else
{
v___y_695_ = v___x_707_;
v___y_696_ = v___x_708_;
goto v___jp_694_;
}
}
else
{
lean_dec(v___x_711_);
v___y_695_ = v___x_707_;
v___y_696_ = v___x_708_;
goto v___jp_694_;
}
}
v___jp_718_:
{
lean_object* v___x_719_; lean_object* v___x_720_; uint8_t v___x_721_; 
v___x_719_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__3));
v___x_720_ = lean_unsigned_to_nat(19u);
v___x_721_ = lean_nat_dec_lt(v_tc_717_, v___x_720_);
lean_dec(v_tc_717_);
if (v___x_721_ == 0)
{
lean_object* v___x_722_; 
v___x_722_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__4));
v___y_667_ = v___x_719_;
v___y_668_ = v___x_722_;
goto v___jp_666_;
}
else
{
lean_object* v___x_723_; 
v___x_723_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__5));
v___y_667_ = v___x_719_;
v___y_668_ = v___x_723_;
goto v___jp_666_;
}
}
v___jp_724_:
{
lean_object* v___x_726_; uint8_t v___x_727_; 
v___x_726_ = lean_unsigned_to_nat(19u);
v___x_727_ = lean_nat_dec_eq(v_tc_717_, v___x_726_);
if (v___x_727_ == 0)
{
lean_object* v___x_728_; uint8_t v___x_729_; 
v___x_728_ = lean_unsigned_to_nat(28u);
v___x_729_ = lean_nat_dec_eq(v_tc_717_, v___x_728_);
if (v___x_729_ == 0)
{
lean_object* v___x_730_; uint8_t v___x_731_; 
v___x_730_ = lean_unsigned_to_nat(29u);
v___x_731_ = lean_nat_dec_eq(v_tc_717_, v___x_730_);
lean_dec(v_tc_717_);
if (v___x_731_ == 0)
{
lean_object* v___x_732_; 
v___x_732_ = lean_box(0);
return v___x_732_;
}
else
{
lean_object* v___x_733_; lean_object* v___x_734_; lean_object* v___x_735_; uint8_t v___x_736_; 
v___x_733_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__3));
v___x_734_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_665_, v___y_725_, v___x_693_);
v___x_735_ = lean_unsigned_to_nat(0u);
v___x_736_ = lean_nat_dec_eq(v___x_734_, v___x_735_);
lean_dec(v___x_734_);
if (v___x_736_ == 0)
{
lean_object* v___x_737_; 
v___x_737_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__6));
v___y_674_ = v___x_733_;
v___y_675_ = v___x_737_;
goto v___jp_673_;
}
else
{
lean_object* v___x_738_; 
v___x_738_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__7));
v___y_674_ = v___x_733_;
v___y_675_ = v___x_738_;
goto v___jp_673_;
}
}
}
else
{
lean_object* v___x_739_; lean_object* v___x_740_; lean_object* v___x_741_; lean_object* v___x_742_; lean_object* v___x_743_; lean_object* v___x_744_; lean_object* v___x_745_; lean_object* v___x_746_; lean_object* v___x_747_; lean_object* v___x_748_; lean_object* v___x_749_; lean_object* v___x_750_; lean_object* v___x_751_; lean_object* v___x_752_; lean_object* v___x_753_; lean_object* v___x_754_; lean_object* v___x_755_; 
lean_dec(v_tc_717_);
v___x_739_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__8));
v___x_740_ = lean_box(0);
v___x_741_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__14));
v___x_742_ = lean_unsigned_to_nat(6u);
v___x_743_ = lean_unsigned_to_nat(3u);
v___x_744_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_665_, v___x_742_, v___x_743_);
v___x_745_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_emergency___closed__7));
v___x_746_ = l_List_getD___redArg(v___x_741_, v___x_744_, v___x_745_);
v___x_747_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_747_, 0, v___x_746_);
v___x_748_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_748_, 0, v___x_739_);
lean_ctor_set(v___x_748_, 1, v___x_747_);
v___x_749_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__15));
v___x_750_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_665_, v___y_725_, v___x_743_);
v___x_751_ = lp_lean1090_Lean1090_Impl_Semantics_emergency(v___x_750_);
v___x_752_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_752_, 0, v___x_751_);
v___x_753_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_753_, 0, v___x_749_);
lean_ctor_set(v___x_753_, 1, v___x_752_);
v___x_754_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_754_, 0, v___x_753_);
lean_ctor_set(v___x_754_, 1, v___x_740_);
v___x_755_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_755_, 0, v___x_748_);
lean_ctor_set(v___x_755_, 1, v___x_754_);
return v___x_755_;
}
}
else
{
lean_object* v___x_756_; 
lean_dec(v_tc_717_);
v___x_756_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__16));
if (v_oracle_664_ == 0)
{
lean_object* v___x_757_; 
v___x_757_ = lp_lean1090_Lean1090_Impl_Presentation_standardVerticalSource(v_word_665_);
v___y_704_ = v___x_756_;
v___y_705_ = v___x_757_;
goto v___jp_703_;
}
else
{
lean_object* v___x_758_; 
v___x_758_ = lp_lean1090_Lean1090_Impl_Presentation_oracleVerticalSource(v_word_665_);
v___y_704_ = v___x_756_;
v___y_705_ = v___x_758_;
goto v___jp_703_;
}
}
}
v___jp_759_:
{
lean_object* v___x_761_; uint8_t v___x_762_; 
v___x_761_ = lean_unsigned_to_nat(20u);
v___x_762_ = lean_nat_dec_le(v___x_761_, v_tc_717_);
if (v___x_762_ == 0)
{
v___y_725_ = v___y_760_;
goto v___jp_724_;
}
else
{
lean_object* v___x_763_; uint8_t v___x_764_; 
v___x_763_ = lean_unsigned_to_nat(22u);
v___x_764_ = lean_nat_dec_le(v_tc_717_, v___x_763_);
if (v___x_764_ == 0)
{
v___y_725_ = v___y_760_;
goto v___jp_724_;
}
else
{
goto v___jp_718_;
}
}
}
v___jp_765_:
{
lean_object* v___x_766_; uint8_t v___x_767_; 
v___x_766_ = lean_unsigned_to_nat(9u);
v___x_767_ = lean_nat_dec_le(v___x_766_, v_tc_717_);
if (v___x_767_ == 0)
{
v___y_760_ = v___x_766_;
goto v___jp_759_;
}
else
{
lean_object* v___x_768_; uint8_t v___x_769_; 
v___x_768_ = lean_unsigned_to_nat(18u);
v___x_769_ = lean_nat_dec_le(v_tc_717_, v___x_768_);
if (v___x_769_ == 0)
{
v___y_760_ = v___x_766_;
goto v___jp_759_;
}
else
{
goto v___jp_718_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___boxed(lean_object* v_oracle_787_, lean_object* v_word_788_){
_start:
{
uint8_t v_oracle_boxed_789_; lean_object* v_res_790_; 
v_oracle_boxed_789_ = lean_unbox(v_oracle_787_);
v_res_790_ = lp_lean1090_Lean1090_Impl_Semantics_adsbLabels(v_oracle_boxed_789_, v_word_788_);
lean_dec(v_word_788_);
return v_res_790_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardFloats(lean_object* v_word_792_){
_start:
{
lean_object* v___y_794_; uint8_t v___y_795_; lean_object* v___y_796_; lean_object* v___y_797_; lean_object* v___y_803_; lean_object* v___y_804_; lean_object* v___y_805_; lean_object* v___x_830_; lean_object* v___x_831_; lean_object* v_tc_832_; lean_object* v___x_833_; uint8_t v___x_834_; 
v___x_830_ = lean_unsigned_to_nat(1u);
v___x_831_ = lean_unsigned_to_nat(5u);
v_tc_832_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_792_, v___x_830_, v___x_831_);
v___x_833_ = lean_unsigned_to_nat(19u);
v___x_834_ = lean_nat_dec_eq(v_tc_832_, v___x_833_);
lean_dec(v_tc_832_);
if (v___x_834_ == 0)
{
lean_object* v___x_835_; 
v___x_835_ = lp_lean1090_Lean1090_Impl_Presentation_oracleADSBFloats(v_word_792_);
return v___x_835_;
}
else
{
lean_object* v___x_836_; lean_object* v___x_837_; lean_object* v_subtype_838_; uint8_t v___x_839_; 
v___x_836_ = lean_unsigned_to_nat(6u);
v___x_837_ = lean_unsigned_to_nat(3u);
v_subtype_838_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_792_, v___x_836_, v___x_837_);
v___x_839_ = lean_nat_dec_eq(v_subtype_838_, v___x_830_);
if (v___x_839_ == 0)
{
lean_object* v___x_840_; uint8_t v___x_841_; 
v___x_840_ = lean_unsigned_to_nat(2u);
v___x_841_ = lean_nat_dec_eq(v_subtype_838_, v___x_840_);
lean_dec(v_subtype_838_);
if (v___x_841_ == 0)
{
lean_object* v___x_842_; 
v___x_842_ = lp_lean1090_Lean1090_Impl_Presentation_oracleADSBFloats(v_word_792_);
return v___x_842_;
}
else
{
goto v___jp_821_;
}
}
else
{
lean_dec(v_subtype_838_);
goto v___jp_821_;
}
}
v___jp_793_:
{
lean_object* v___x_798_; lean_object* v___x_799_; lean_object* v___x_800_; lean_object* v___x_801_; 
lean_inc_ref(v___y_794_);
v___x_798_ = lean_alloc_ctor(0, 2, 1);
lean_ctor_set(v___x_798_, 0, v___y_794_);
lean_ctor_set(v___x_798_, 1, v___y_797_);
lean_ctor_set_uint8(v___x_798_, sizeof(void*)*2, v___y_795_);
v___x_799_ = lean_box(0);
v___x_800_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_800_, 0, v___x_798_);
lean_ctor_set(v___x_800_, 1, v___x_799_);
v___x_801_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_801_, 0, v___y_796_);
lean_ctor_set(v___x_801_, 1, v___x_800_);
return v___x_801_;
}
v___jp_802_:
{
uint8_t v___x_806_; lean_object* v___x_807_; lean_object* v___x_808_; 
v___x_806_ = 1;
lean_inc_ref(v___y_804_);
v___x_807_ = lean_alloc_ctor(0, 2, 1);
lean_ctor_set(v___x_807_, 0, v___y_804_);
lean_ctor_set(v___x_807_, 1, v___y_805_);
lean_ctor_set_uint8(v___x_807_, sizeof(void*)*2, v___x_806_);
v___x_808_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardFloats___closed__0));
if (lean_obj_tag(v___y_803_) == 0)
{
lean_object* v___x_809_; 
v___x_809_ = lean_box(0);
v___y_794_ = v___x_808_;
v___y_795_ = v___x_806_;
v___y_796_ = v___x_807_;
v___y_797_ = v___x_809_;
goto v___jp_793_;
}
else
{
lean_object* v_val_810_; lean_object* v___x_812_; uint8_t v_isShared_813_; uint8_t v_isSharedCheck_820_; 
v_val_810_ = lean_ctor_get(v___y_803_, 0);
v_isSharedCheck_820_ = !lean_is_exclusive(v___y_803_);
if (v_isSharedCheck_820_ == 0)
{
v___x_812_ = v___y_803_;
v_isShared_813_ = v_isSharedCheck_820_;
goto v_resetjp_811_;
}
else
{
lean_inc(v_val_810_);
lean_dec(v___y_803_);
v___x_812_ = lean_box(0);
v_isShared_813_ = v_isSharedCheck_820_;
goto v_resetjp_811_;
}
v_resetjp_811_:
{
lean_object* v_fst_814_; lean_object* v_snd_815_; lean_object* v___x_816_; lean_object* v___x_818_; 
v_fst_814_ = lean_ctor_get(v_val_810_, 0);
lean_inc(v_fst_814_);
v_snd_815_ = lean_ctor_get(v_val_810_, 1);
lean_inc(v_snd_815_);
lean_dec(v_val_810_);
v___x_816_ = lp_lean1090_Lean1090_Impl_Presentation_velocityTrack(v_fst_814_, v_snd_815_);
if (v_isShared_813_ == 0)
{
lean_ctor_set(v___x_812_, 0, v___x_816_);
v___x_818_ = v___x_812_;
goto v_reusejp_817_;
}
else
{
lean_object* v_reuseFailAlloc_819_; 
v_reuseFailAlloc_819_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_819_, 0, v___x_816_);
v___x_818_ = v_reuseFailAlloc_819_;
goto v_reusejp_817_;
}
v_reusejp_817_:
{
v___y_794_ = v___x_808_;
v___y_795_ = v___x_806_;
v___y_796_ = v___x_807_;
v___y_797_ = v___x_818_;
goto v___jp_793_;
}
}
}
}
v___jp_821_:
{
lean_object* v_components_822_; lean_object* v___x_823_; 
v_components_822_ = lp_lean1090_Lean1090_Impl_Presentation_standardVelocityComponents(v_word_792_);
v___x_823_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues___closed__12));
if (lean_obj_tag(v_components_822_) == 0)
{
lean_object* v___x_824_; 
v___x_824_ = lean_box(0);
v___y_803_ = v_components_822_;
v___y_804_ = v___x_823_;
v___y_805_ = v___x_824_;
goto v___jp_802_;
}
else
{
lean_object* v_val_825_; lean_object* v_fst_826_; lean_object* v_snd_827_; lean_object* v___x_828_; lean_object* v___x_829_; 
v_val_825_ = lean_ctor_get(v_components_822_, 0);
lean_inc(v_val_825_);
v_fst_826_ = lean_ctor_get(v_val_825_, 0);
lean_inc(v_fst_826_);
v_snd_827_ = lean_ctor_get(v_val_825_, 1);
lean_inc(v_snd_827_);
lean_dec(v_val_825_);
v___x_828_ = lp_lean1090_Lean1090_Impl_Presentation_velocitySpeed(v_fst_826_, v_snd_827_);
v___x_829_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_829_, 0, v___x_828_);
v___y_803_ = v_components_822_;
v___y_804_ = v___x_823_;
v___y_805_ = v___x_829_;
goto v___jp_802_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsbStandardFloats___boxed(lean_object* v_word_843_){
_start:
{
lean_object* v_res_844_; 
v_res_844_ = lp_lean1090_Lean1090_Impl_Semantics_adsbStandardFloats(v_word_843_);
lean_dec(v_word_843_);
return v_res_844_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsb(lean_object* v_word_845_){
_start:
{
lean_object* v___y_847_; lean_object* v___x_859_; 
v___x_859_ = lp_lean1090_Lean1090_Impl_adsbLayout(v_word_845_);
if (lean_obj_tag(v___x_859_) == 0)
{
lean_object* v___x_860_; 
v___x_860_ = lean_box(0);
v___y_847_ = v___x_860_;
goto v___jp_846_;
}
else
{
lean_object* v_val_861_; 
v_val_861_ = lean_ctor_get(v___x_859_, 0);
lean_inc(v_val_861_);
lean_dec_ref_known(v___x_859_, 1);
v___y_847_ = v_val_861_;
goto v___jp_846_;
}
v___jp_846_:
{
lean_object* v___x_848_; lean_object* v___x_849_; lean_object* v___x_850_; uint8_t v___x_851_; lean_object* v___x_852_; uint8_t v___x_853_; lean_object* v___x_854_; lean_object* v___x_855_; lean_object* v___x_856_; lean_object* v___x_857_; lean_object* v___x_858_; 
v___x_848_ = lp_lean1090_Lean1090_Impl_Semantics_tableValues(v___y_847_, v_word_845_);
v___x_849_ = lp_lean1090_Lean1090_Impl_Semantics_adsbStandardValues(v_word_845_);
v___x_850_ = lp_lean1090_Lean1090_Impl_Semantics_adsbOracleValues(v_word_845_);
v___x_851_ = 0;
v___x_852_ = lp_lean1090_Lean1090_Impl_Semantics_adsbLabels(v___x_851_, v_word_845_);
v___x_853_ = 1;
v___x_854_ = lp_lean1090_Lean1090_Impl_Semantics_adsbLabels(v___x_853_, v_word_845_);
v___x_855_ = lp_lean1090_Lean1090_Impl_Semantics_adsbStandardFloats(v_word_845_);
v___x_856_ = lp_lean1090_Lean1090_Impl_Presentation_oracleADSBFloats(v_word_845_);
v___x_857_ = lean_box(0);
v___x_858_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v___x_858_, 0, v___x_848_);
lean_ctor_set(v___x_858_, 1, v___x_849_);
lean_ctor_set(v___x_858_, 2, v___x_850_);
lean_ctor_set(v___x_858_, 3, v___x_852_);
lean_ctor_set(v___x_858_, 4, v___x_854_);
lean_ctor_set(v___x_858_, 5, v___x_855_);
lean_ctor_set(v___x_858_, 6, v___x_856_);
lean_ctor_set(v___x_858_, 7, v___x_857_);
lean_ctor_set(v___x_858_, 8, v___x_857_);
return v___x_858_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsb___boxed(lean_object* v_word_862_){
_start:
{
lean_object* v_res_863_; 
v_res_863_ = lp_lean1090_Lean1090_Impl_Semantics_adsb(v_word_862_);
lean_dec(v_word_862_);
return v_res_863_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_Semantics_airline_spec__0(lean_object* v___x_864_, lean_object* v_a_865_, lean_object* v_a_866_){
_start:
{
if (lean_obj_tag(v_a_865_) == 0)
{
lean_object* v___x_867_; 
v___x_867_ = l_List_reverse___redArg(v_a_866_);
return v___x_867_;
}
else
{
lean_object* v_head_868_; lean_object* v_tail_869_; lean_object* v___x_871_; uint8_t v_isShared_872_; uint8_t v_isSharedCheck_882_; 
v_head_868_ = lean_ctor_get(v_a_865_, 0);
v_tail_869_ = lean_ctor_get(v_a_865_, 1);
v_isSharedCheck_882_ = !lean_is_exclusive(v_a_865_);
if (v_isSharedCheck_882_ == 0)
{
v___x_871_ = v_a_865_;
v_isShared_872_ = v_isSharedCheck_882_;
goto v_resetjp_870_;
}
else
{
lean_inc(v_tail_869_);
lean_inc(v_head_868_);
lean_dec(v_a_865_);
v___x_871_ = lean_box(0);
v_isShared_872_ = v_isSharedCheck_882_;
goto v_resetjp_870_;
}
v_resetjp_870_:
{
uint8_t v___x_878_; 
v___x_878_ = lp_lean1090_Lean1090_Impl_cbDashPlaceholder(v_head_868_);
if (v___x_878_ == 0)
{
goto v___jp_873_;
}
else
{
lean_object* v___x_879_; uint8_t v___x_880_; 
v___x_879_ = lean_unsigned_to_nat(0u);
v___x_880_ = lean_nat_dec_eq(v___x_864_, v___x_879_);
if (v___x_880_ == 0)
{
lean_del_object(v___x_871_);
lean_dec(v_head_868_);
v_a_865_ = v_tail_869_;
goto _start;
}
else
{
goto v___jp_873_;
}
}
v___jp_873_:
{
lean_object* v___x_875_; 
if (v_isShared_872_ == 0)
{
lean_ctor_set(v___x_871_, 1, v_a_866_);
v___x_875_ = v___x_871_;
goto v_reusejp_874_;
}
else
{
lean_object* v_reuseFailAlloc_877_; 
v_reuseFailAlloc_877_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_877_, 0, v_head_868_);
lean_ctor_set(v_reuseFailAlloc_877_, 1, v_a_866_);
v___x_875_ = v_reuseFailAlloc_877_;
goto v_reusejp_874_;
}
v_reusejp_874_:
{
v_a_865_ = v_tail_869_;
v_a_866_ = v___x_875_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_Semantics_airline_spec__0___boxed(lean_object* v___x_883_, lean_object* v_a_884_, lean_object* v_a_885_){
_start:
{
lean_object* v_res_886_; 
v_res_886_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_Semantics_airline_spec__0(v___x_883_, v_a_884_, v_a_885_);
lean_dec(v___x_883_);
return v_res_886_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_airline(lean_object* v_word_887_){
_start:
{
lean_object* v___x_888_; lean_object* v___x_889_; lean_object* v___x_890_; lean_object* v___x_891_; uint8_t v___x_892_; 
v___x_888_ = lean_unsigned_to_nat(44u);
v___x_889_ = lean_unsigned_to_nat(1u);
v___x_890_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_887_, v___x_888_, v___x_889_);
v___x_891_ = lean_unsigned_to_nat(0u);
v___x_892_ = lean_nat_dec_eq(v___x_890_, v___x_891_);
if (v___x_892_ == 0)
{
lean_object* v___x_893_; lean_object* v___x_894_; lean_object* v___x_895_; lean_object* v___x_896_; lean_object* v___x_897_; lean_object* v___x_898_; lean_object* v___x_899_; lean_object* v___x_900_; lean_object* v___x_901_; lean_object* v___x_902_; lean_object* v___x_903_; lean_object* v___x_904_; 
v___x_893_ = lean_unsigned_to_nat(45u);
v___x_894_ = lean_unsigned_to_nat(6u);
v___x_895_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_887_, v___x_893_, v___x_894_);
v___x_896_ = lean_unsigned_to_nat(51u);
v___x_897_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_887_, v___x_896_, v___x_894_);
v___x_898_ = lean_box(0);
v___x_899_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_899_, 0, v___x_897_);
lean_ctor_set(v___x_899_, 1, v___x_898_);
v___x_900_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_900_, 0, v___x_895_);
lean_ctor_set(v___x_900_, 1, v___x_899_);
v___x_901_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_Semantics_airline_spec__0(v___x_890_, v___x_900_, v___x_898_);
lean_dec(v___x_890_);
v___x_902_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_cbCallsign_spec__1(v___x_901_, v___x_898_);
v___x_903_ = lean_string_mk(v___x_902_);
v___x_904_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_904_, 0, v___x_903_);
return v___x_904_;
}
else
{
lean_object* v___x_905_; 
lean_dec(v___x_890_);
v___x_905_ = lean_box(0);
return v___x_905_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_airline___boxed(lean_object* v_word_906_){
_start:
{
lean_object* v_res_907_; 
v_res_907_ = lp_lean1090_Lean1090_Impl_Semantics_airline(v_word_906_);
lean_dec(v_word_906_);
return v_res_907_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__0(void){
_start:
{
lean_object* v___x_908_; lean_object* v___x_909_; 
v___x_908_ = lean_unsigned_to_nat(0u);
v___x_909_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_908_);
return v___x_909_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__1(void){
_start:
{
lean_object* v___x_910_; lean_object* v___x_911_; 
v___x_910_ = lean_unsigned_to_nat(1u);
v___x_911_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_910_);
return v___x_911_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__2(void){
_start:
{
lean_object* v___x_912_; lean_object* v___x_913_; 
v___x_912_ = lean_unsigned_to_nat(2u);
v___x_913_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_912_);
return v___x_913_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard(lean_object* v_value_926_){
_start:
{
if (lean_obj_tag(v_value_926_) == 0)
{
lean_object* v___x_927_; 
v___x_927_ = lean_box(0);
return v___x_927_;
}
else
{
lean_object* v_val_928_; lean_object* v___x_929_; uint8_t v___x_930_; 
v_val_928_ = lean_ctor_get(v_value_926_, 0);
v___x_929_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__0, &lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__0);
v___x_930_ = l_instDecidableEqRat_decEq(v_val_928_, v___x_929_);
if (v___x_930_ == 0)
{
lean_object* v___x_931_; uint8_t v___x_932_; 
v___x_931_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__1, &lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__1);
v___x_932_ = l_instDecidableEqRat_decEq(v_val_928_, v___x_931_);
if (v___x_932_ == 0)
{
lean_object* v___x_933_; uint8_t v___x_934_; 
v___x_933_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__2, &lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__2_once, _init_lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__2);
v___x_934_ = l_instDecidableEqRat_decEq(v_val_928_, v___x_933_);
if (v___x_934_ == 0)
{
lean_object* v___x_935_; 
v___x_935_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__4));
return v___x_935_;
}
else
{
lean_object* v___x_936_; 
v___x_936_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__6));
return v___x_936_;
}
}
else
{
lean_object* v___x_937_; 
v___x_937_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__8));
return v___x_937_;
}
}
else
{
lean_object* v___x_938_; 
v___x_938_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_hazard___closed__10));
return v___x_938_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_hazard___boxed(lean_object* v_value_939_){
_start:
{
lean_object* v_res_940_; 
v_res_940_ = lp_lean1090_Lean1090_Impl_Semantics_hazard(v_value_939_);
lean_dec(v_value_939_);
return v_res_940_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBLabels_spec__0(lean_object* v_register_941_, lean_object* v_word_942_, lean_object* v_a_943_, lean_object* v_a_944_){
_start:
{
if (lean_obj_tag(v_a_943_) == 0)
{
lean_object* v___x_945_; 
v___x_945_ = l_List_reverse___redArg(v_a_944_);
return v___x_945_;
}
else
{
lean_object* v_head_946_; lean_object* v_tail_947_; lean_object* v___x_949_; uint8_t v_isShared_950_; uint8_t v_isSharedCheck_958_; 
v_head_946_ = lean_ctor_get(v_a_943_, 0);
v_tail_947_ = lean_ctor_get(v_a_943_, 1);
v_isSharedCheck_958_ = !lean_is_exclusive(v_a_943_);
if (v_isSharedCheck_958_ == 0)
{
v___x_949_ = v_a_943_;
v_isShared_950_ = v_isSharedCheck_958_;
goto v_resetjp_948_;
}
else
{
lean_inc(v_tail_947_);
lean_inc(v_head_946_);
lean_dec(v_a_943_);
v___x_949_ = lean_box(0);
v_isShared_950_ = v_isSharedCheck_958_;
goto v_resetjp_948_;
}
v_resetjp_948_:
{
lean_object* v___x_951_; lean_object* v___x_952_; lean_object* v___x_953_; lean_object* v___x_955_; 
v___x_951_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_941_, v_word_942_, v_head_946_);
v___x_952_ = lp_lean1090_Lean1090_Impl_Semantics_hazard(v___x_951_);
lean_dec(v___x_951_);
v___x_953_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_953_, 0, v_head_946_);
lean_ctor_set(v___x_953_, 1, v___x_952_);
if (v_isShared_950_ == 0)
{
lean_ctor_set(v___x_949_, 1, v_a_944_);
lean_ctor_set(v___x_949_, 0, v___x_953_);
v___x_955_ = v___x_949_;
goto v_reusejp_954_;
}
else
{
lean_object* v_reuseFailAlloc_957_; 
v_reuseFailAlloc_957_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_957_, 0, v___x_953_);
lean_ctor_set(v_reuseFailAlloc_957_, 1, v_a_944_);
v___x_955_ = v_reuseFailAlloc_957_;
goto v_reusejp_954_;
}
v_reusejp_954_:
{
v_a_943_ = v_tail_947_;
v_a_944_ = v___x_955_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBLabels_spec__0___boxed(lean_object* v_register_959_, lean_object* v_word_960_, lean_object* v_a_961_, lean_object* v_a_962_){
_start:
{
lean_object* v_res_963_; 
v_res_963_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBLabels_spec__0(v_register_959_, v_word_960_, v_a_961_, v_a_962_);
lean_dec(v_word_960_);
lean_dec(v_register_959_);
return v_res_963_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels(lean_object* v_register_1022_, lean_object* v_word_1023_){
_start:
{
lean_object* v___x_1024_; uint8_t v___x_1025_; 
v___x_1024_ = lean_unsigned_to_nat(32u);
v___x_1025_ = lean_nat_dec_eq(v_register_1022_, v___x_1024_);
if (v___x_1025_ == 0)
{
lean_object* v___x_1026_; uint8_t v___x_1027_; 
v___x_1026_ = lean_unsigned_to_nat(33u);
v___x_1027_ = lean_nat_dec_eq(v_register_1022_, v___x_1026_);
if (v___x_1027_ == 0)
{
lean_object* v___x_1028_; uint8_t v___x_1029_; 
v___x_1028_ = lean_unsigned_to_nat(64u);
v___x_1029_ = lean_nat_dec_eq(v_register_1022_, v___x_1028_);
if (v___x_1029_ == 0)
{
lean_object* v___x_1030_; uint8_t v___x_1031_; 
v___x_1030_ = lean_unsigned_to_nat(68u);
v___x_1031_ = lean_nat_dec_eq(v_register_1022_, v___x_1030_);
if (v___x_1031_ == 0)
{
lean_object* v___x_1032_; uint8_t v___x_1033_; 
v___x_1032_ = lean_unsigned_to_nat(69u);
v___x_1033_ = lean_nat_dec_eq(v_register_1022_, v___x_1032_);
if (v___x_1033_ == 0)
{
lean_object* v___x_1034_; 
v___x_1034_ = lean_box(0);
return v___x_1034_;
}
else
{
lean_object* v___x_1035_; lean_object* v___x_1036_; lean_object* v___x_1037_; 
v___x_1035_ = lean_box(0);
v___x_1036_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__8));
v___x_1037_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBLabels_spec__0(v_register_1022_, v_word_1023_, v___x_1036_, v___x_1035_);
return v___x_1037_;
}
}
else
{
lean_object* v___x_1038_; lean_object* v___x_1039_; lean_object* v___x_1040_; lean_object* v___x_1041_; lean_object* v___x_1042_; lean_object* v___x_1043_; lean_object* v___x_1044_; lean_object* v___x_1045_; lean_object* v___x_1046_; lean_object* v___x_1047_; lean_object* v___x_1048_; lean_object* v___x_1049_; lean_object* v___x_1050_; lean_object* v___x_1051_; lean_object* v___x_1052_; lean_object* v___x_1053_; 
v___x_1038_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__9));
v___x_1039_ = lean_box(0);
v___x_1040_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__18));
v___x_1041_ = lean_unsigned_to_nat(1u);
v___x_1042_ = lean_unsigned_to_nat(4u);
v___x_1043_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1023_, v___x_1041_, v___x_1042_);
v___x_1044_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_wakeVortex___closed__0));
v___x_1045_ = l_List_getD___redArg(v___x_1040_, v___x_1043_, v___x_1044_);
v___x_1046_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1046_, 0, v___x_1045_);
v___x_1047_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1047_, 0, v___x_1038_);
lean_ctor_set(v___x_1047_, 1, v___x_1046_);
v___x_1048_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__0));
v___x_1049_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1022_, v_word_1023_, v___x_1048_);
v___x_1050_ = lp_lean1090_Lean1090_Impl_Semantics_hazard(v___x_1049_);
lean_dec(v___x_1049_);
v___x_1051_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1051_, 0, v___x_1048_);
lean_ctor_set(v___x_1051_, 1, v___x_1050_);
v___x_1052_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1052_, 0, v___x_1051_);
lean_ctor_set(v___x_1052_, 1, v___x_1039_);
v___x_1053_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1053_, 0, v___x_1047_);
lean_ctor_set(v___x_1053_, 1, v___x_1052_);
return v___x_1053_;
}
}
else
{
lean_object* v___x_1054_; lean_object* v___x_1055_; lean_object* v___x_1056_; lean_object* v___x_1057_; lean_object* v___x_1058_; lean_object* v___x_1059_; lean_object* v___x_1060_; lean_object* v___x_1061_; lean_object* v___x_1062_; lean_object* v___x_1063_; lean_object* v___x_1064_; 
v___x_1054_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__19));
v___x_1055_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__20));
v___x_1056_ = lean_box(0);
v___x_1057_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__27));
v___x_1058_ = lean_unsigned_to_nat(55u);
v___x_1059_ = lean_unsigned_to_nat(2u);
v___x_1060_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_1023_, v___x_1058_, v___x_1059_);
v___x_1061_ = l_List_getD___redArg(v___x_1057_, v___x_1060_, v___x_1055_);
v___x_1062_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1062_, 0, v___x_1061_);
v___x_1063_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1063_, 0, v___x_1054_);
lean_ctor_set(v___x_1063_, 1, v___x_1062_);
v___x_1064_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1064_, 0, v___x_1063_);
lean_ctor_set(v___x_1064_, 1, v___x_1056_);
return v___x_1064_;
}
}
else
{
lean_object* v___x_1065_; lean_object* v___x_1066_; lean_object* v___x_1067_; lean_object* v___x_1068_; lean_object* v___x_1069_; lean_object* v___x_1070_; lean_object* v___x_1071_; lean_object* v___x_1072_; lean_object* v___x_1073_; 
v___x_1065_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__28));
v___x_1066_ = lp_lean1090_Lean1090_Impl_cbRegistration(v_word_1023_);
v___x_1067_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1067_, 0, v___x_1065_);
lean_ctor_set(v___x_1067_, 1, v___x_1066_);
v___x_1068_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_commBLabels___closed__29));
v___x_1069_ = lp_lean1090_Lean1090_Impl_Semantics_airline(v_word_1023_);
v___x_1070_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1070_, 0, v___x_1068_);
lean_ctor_set(v___x_1070_, 1, v___x_1069_);
v___x_1071_ = lean_box(0);
v___x_1072_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1072_, 0, v___x_1070_);
lean_ctor_set(v___x_1072_, 1, v___x_1071_);
v___x_1073_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1073_, 0, v___x_1067_);
lean_ctor_set(v___x_1073_, 1, v___x_1072_);
return v___x_1073_;
}
}
else
{
lean_object* v___x_1074_; lean_object* v___x_1075_; lean_object* v___x_1076_; lean_object* v___x_1077_; lean_object* v___x_1078_; lean_object* v___x_1079_; 
v___x_1074_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Semantics_adsbLabels___closed__17));
v___x_1075_ = lp_lean1090_Lean1090_Impl_cbCallsign(v_word_1023_);
v___x_1076_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1076_, 0, v___x_1075_);
v___x_1077_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1077_, 0, v___x_1074_);
lean_ctor_set(v___x_1077_, 1, v___x_1076_);
v___x_1078_ = lean_box(0);
v___x_1079_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1079_, 0, v___x_1077_);
lean_ctor_set(v___x_1079_, 1, v___x_1078_);
return v___x_1079_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBLabels___boxed(lean_object* v_register_1080_, lean_object* v_word_1081_){
_start:
{
lean_object* v_res_1082_; 
v_res_1082_ = lp_lean1090_Lean1090_Impl_Semantics_commBLabels(v_register_1080_, v_word_1081_);
lean_dec(v_word_1081_);
lean_dec(v_register_1080_);
return v_res_1082_;
}
}
static lean_object* _init_lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0___closed__1(void){
_start:
{
lean_object* v___x_1084_; lean_object* v___x_1085_; 
v___x_1084_ = lean_unsigned_to_nat(4u);
v___x_1085_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1084_);
return v___x_1085_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0(lean_object* v_register_1086_, lean_object* v_word_1087_, lean_object* v_a_1088_, lean_object* v_a_1089_){
_start:
{
if (lean_obj_tag(v_a_1088_) == 0)
{
lean_object* v___x_1090_; 
v___x_1090_ = l_List_reverse___redArg(v_a_1089_);
return v___x_1090_;
}
else
{
lean_object* v_head_1091_; lean_object* v_tail_1092_; lean_object* v___x_1094_; uint8_t v_isShared_1095_; uint8_t v_isSharedCheck_1125_; 
v_head_1091_ = lean_ctor_get(v_a_1088_, 0);
v_tail_1092_ = lean_ctor_get(v_a_1088_, 1);
v_isSharedCheck_1125_ = !lean_is_exclusive(v_a_1088_);
if (v_isSharedCheck_1125_ == 0)
{
v___x_1094_ = v_a_1088_;
v_isShared_1095_ = v_isSharedCheck_1125_;
goto v_resetjp_1093_;
}
else
{
lean_inc(v_tail_1092_);
lean_inc(v_head_1091_);
lean_dec(v_a_1088_);
v___x_1094_ = lean_box(0);
v_isShared_1095_ = v_isSharedCheck_1125_;
goto v_resetjp_1093_;
}
v_resetjp_1093_:
{
lean_object* v___y_1097_; lean_object* v___x_1102_; uint8_t v___x_1103_; 
v___x_1102_ = lean_unsigned_to_nat(68u);
v___x_1103_ = lean_nat_dec_eq(v_register_1086_, v___x_1102_);
if (v___x_1103_ == 0)
{
v___y_1097_ = v_head_1091_;
goto v___jp_1096_;
}
else
{
lean_object* v_key_1104_; uint8_t v_missing_1105_; lean_object* v___x_1106_; uint8_t v___x_1107_; 
v_key_1104_ = lean_ctor_get(v_head_1091_, 0);
v_missing_1105_ = lean_ctor_get_uint8(v_head_1091_, sizeof(void*)*2);
v___x_1106_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0___closed__0));
v___x_1107_ = lean_string_dec_eq(v_key_1104_, v___x_1106_);
if (v___x_1107_ == 0)
{
v___y_1097_ = v_head_1091_;
goto v___jp_1096_;
}
else
{
lean_object* v___x_1109_; uint8_t v_isShared_1110_; uint8_t v_isSharedCheck_1122_; 
lean_inc_ref(v_key_1104_);
v_isSharedCheck_1122_ = !lean_is_exclusive(v_head_1091_);
if (v_isSharedCheck_1122_ == 0)
{
lean_object* v_unused_1123_; lean_object* v_unused_1124_; 
v_unused_1123_ = lean_ctor_get(v_head_1091_, 1);
lean_dec(v_unused_1123_);
v_unused_1124_ = lean_ctor_get(v_head_1091_, 0);
lean_dec(v_unused_1124_);
v___x_1109_ = v_head_1091_;
v_isShared_1110_ = v_isSharedCheck_1122_;
goto v_resetjp_1108_;
}
else
{
lean_dec(v_head_1091_);
v___x_1109_ = lean_box(0);
v_isShared_1110_ = v_isSharedCheck_1122_;
goto v_resetjp_1108_;
}
v_resetjp_1108_:
{
uint8_t v___x_1111_; lean_object* v___x_1112_; lean_object* v___x_1113_; lean_object* v___x_1114_; lean_object* v___x_1115_; lean_object* v___x_1116_; lean_object* v___x_1117_; lean_object* v___x_1118_; lean_object* v___x_1120_; 
v___x_1111_ = 1;
v___x_1112_ = lean_unsigned_to_nat(24u);
v___x_1113_ = lean_unsigned_to_nat(11u);
v___x_1114_ = lp_lean1090_Lean1090_Impl_cbSigned(v_word_1087_, v___x_1112_, v___x_1113_);
v___x_1115_ = lean_obj_once(&lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0___closed__1, &lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0___closed__1_once, _init_lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0___closed__1);
v___x_1116_ = l_Rat_div(v___x_1114_, v___x_1115_);
lean_dec_ref(v___x_1114_);
v___x_1117_ = lean_alloc_ctor(0, 1, 1);
lean_ctor_set(v___x_1117_, 0, v___x_1116_);
lean_ctor_set_uint8(v___x_1117_, sizeof(void*)*1, v___x_1111_);
v___x_1118_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1118_, 0, v___x_1117_);
if (v_isShared_1110_ == 0)
{
lean_ctor_set(v___x_1109_, 1, v___x_1118_);
v___x_1120_ = v___x_1109_;
goto v_reusejp_1119_;
}
else
{
lean_object* v_reuseFailAlloc_1121_; 
v_reuseFailAlloc_1121_ = lean_alloc_ctor(0, 2, 1);
lean_ctor_set(v_reuseFailAlloc_1121_, 0, v_key_1104_);
lean_ctor_set(v_reuseFailAlloc_1121_, 1, v___x_1118_);
lean_ctor_set_uint8(v_reuseFailAlloc_1121_, sizeof(void*)*2, v_missing_1105_);
v___x_1120_ = v_reuseFailAlloc_1121_;
goto v_reusejp_1119_;
}
v_reusejp_1119_:
{
v___y_1097_ = v___x_1120_;
goto v___jp_1096_;
}
}
}
}
v___jp_1096_:
{
lean_object* v___x_1099_; 
if (v_isShared_1095_ == 0)
{
lean_ctor_set(v___x_1094_, 1, v_a_1089_);
lean_ctor_set(v___x_1094_, 0, v___y_1097_);
v___x_1099_ = v___x_1094_;
goto v_reusejp_1098_;
}
else
{
lean_object* v_reuseFailAlloc_1101_; 
v_reuseFailAlloc_1101_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1101_, 0, v___y_1097_);
lean_ctor_set(v_reuseFailAlloc_1101_, 1, v_a_1089_);
v___x_1099_ = v_reuseFailAlloc_1101_;
goto v_reusejp_1098_;
}
v_reusejp_1098_:
{
v_a_1088_ = v_tail_1092_;
v_a_1089_ = v___x_1099_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0___boxed(lean_object* v_register_1126_, lean_object* v_word_1127_, lean_object* v_a_1128_, lean_object* v_a_1129_){
_start:
{
lean_object* v_res_1130_; 
v_res_1130_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0(v_register_1126_, v_word_1127_, v_a_1128_, v_a_1129_);
lean_dec(v_word_1127_);
lean_dec(v_register_1126_);
return v_res_1130_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBStandardFloats(lean_object* v_register_1131_, lean_object* v_word_1132_){
_start:
{
lean_object* v___x_1133_; uint8_t v___x_1134_; 
v___x_1133_ = lean_unsigned_to_nat(48u);
v___x_1134_ = lean_nat_dec_eq(v_register_1131_, v___x_1133_);
if (v___x_1134_ == 0)
{
lean_object* v___x_1135_; lean_object* v___x_1136_; lean_object* v___x_1137_; 
v___x_1135_ = lp_lean1090_Lean1090_Impl_Presentation_oracleCommBFloats(v_register_1131_, v_word_1132_);
v___x_1136_ = lean_box(0);
v___x_1137_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloats_spec__0(v_register_1131_, v_word_1132_, v___x_1135_, v___x_1136_);
return v___x_1137_;
}
else
{
lean_object* v___x_1138_; 
v___x_1138_ = lean_box(0);
return v___x_1138_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_commBStandardFloats___boxed(lean_object* v_register_1139_, lean_object* v_word_1140_){
_start:
{
lean_object* v_res_1141_; 
v_res_1141_ = lp_lean1090_Lean1090_Impl_Semantics_commBStandardFloats(v_register_1139_, v_word_1140_);
lean_dec(v_word_1140_);
lean_dec(v_register_1139_);
return v_res_1141_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commB_spec__0(lean_object* v_register_1142_, lean_object* v_word_1143_, lean_object* v_a_1144_, lean_object* v_a_1145_){
_start:
{
if (lean_obj_tag(v_a_1144_) == 0)
{
lean_object* v___x_1146_; 
v___x_1146_ = l_List_reverse___redArg(v_a_1145_);
return v___x_1146_;
}
else
{
lean_object* v_head_1147_; lean_object* v_tail_1148_; lean_object* v___x_1150_; uint8_t v_isShared_1151_; uint8_t v_isSharedCheck_1159_; 
v_head_1147_ = lean_ctor_get(v_a_1144_, 0);
v_tail_1148_ = lean_ctor_get(v_a_1144_, 1);
v_isSharedCheck_1159_ = !lean_is_exclusive(v_a_1144_);
if (v_isSharedCheck_1159_ == 0)
{
v___x_1150_ = v_a_1144_;
v_isShared_1151_ = v_isSharedCheck_1159_;
goto v_resetjp_1149_;
}
else
{
lean_inc(v_tail_1148_);
lean_inc(v_head_1147_);
lean_dec(v_a_1144_);
v___x_1150_ = lean_box(0);
v_isShared_1151_ = v_isSharedCheck_1159_;
goto v_resetjp_1149_;
}
v_resetjp_1149_:
{
lean_object* v_name_1152_; lean_object* v___x_1153_; lean_object* v___x_1154_; lean_object* v___x_1156_; 
v_name_1152_ = lean_ctor_get(v_head_1147_, 0);
lean_inc_ref(v_name_1152_);
lean_dec(v_head_1147_);
v___x_1153_ = lp_lean1090_Lean1090_Impl_commBValue(v_register_1142_, v_word_1143_, v_name_1152_);
v___x_1154_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1154_, 0, v_name_1152_);
lean_ctor_set(v___x_1154_, 1, v___x_1153_);
if (v_isShared_1151_ == 0)
{
lean_ctor_set(v___x_1150_, 1, v_a_1145_);
lean_ctor_set(v___x_1150_, 0, v___x_1154_);
v___x_1156_ = v___x_1150_;
goto v_reusejp_1155_;
}
else
{
lean_object* v_reuseFailAlloc_1158_; 
v_reuseFailAlloc_1158_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1158_, 0, v___x_1154_);
lean_ctor_set(v_reuseFailAlloc_1158_, 1, v_a_1145_);
v___x_1156_ = v_reuseFailAlloc_1158_;
goto v_reusejp_1155_;
}
v_reusejp_1155_:
{
v_a_1144_ = v_tail_1148_;
v_a_1145_ = v___x_1156_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commB_spec__0___boxed(lean_object* v_register_1160_, lean_object* v_word_1161_, lean_object* v_a_1162_, lean_object* v_a_1163_){
_start:
{
lean_object* v_res_1164_; 
v_res_1164_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commB_spec__0(v_register_1160_, v_word_1161_, v_a_1162_, v_a_1163_);
lean_dec(v_word_1161_);
lean_dec(v_register_1160_);
return v_res_1164_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_commB(lean_object* v_register_1165_, lean_object* v_word_1166_){
_start:
{
lean_object* v___y_1168_; lean_object* v___y_1169_; lean_object* v___y_1170_; lean_object* v___y_1171_; lean_object* v___y_1172_; uint8_t v___y_1173_; lean_object* v___y_1174_; lean_object* v___y_1181_; lean_object* v___x_1192_; uint8_t v___x_1193_; 
v___x_1192_ = lean_unsigned_to_nat(5u);
v___x_1193_ = lean_nat_dec_eq(v_register_1165_, v___x_1192_);
if (v___x_1193_ == 0)
{
lean_object* v___x_1194_; uint8_t v___x_1195_; 
v___x_1194_ = lean_unsigned_to_nat(101u);
v___x_1195_ = lean_nat_dec_eq(v_register_1165_, v___x_1194_);
if (v___x_1195_ == 0)
{
lean_object* v___x_1196_; 
v___x_1196_ = lp_lean1090_Lean1090_Impl_commBLayout(v_register_1165_);
if (lean_obj_tag(v___x_1196_) == 0)
{
lean_object* v___x_1197_; 
v___x_1197_ = lean_box(0);
v___y_1181_ = v___x_1197_;
goto v___jp_1180_;
}
else
{
lean_object* v_val_1198_; 
v_val_1198_ = lean_ctor_get(v___x_1196_, 0);
lean_inc(v_val_1198_);
lean_dec_ref_known(v___x_1196_, 1);
v___y_1181_ = v_val_1198_;
goto v___jp_1180_;
}
}
else
{
lean_object* v___x_1199_; 
v___x_1199_ = lp_lean1090_Lean1090_Impl_Semantics_adsb(v_word_1166_);
return v___x_1199_;
}
}
else
{
lean_object* v___x_1200_; 
v___x_1200_ = lp_lean1090_Lean1090_Impl_Semantics_adsb(v_word_1166_);
return v___x_1200_;
}
v___jp_1167_:
{
if (v___y_1173_ == 0)
{
lean_object* v___x_1175_; lean_object* v___x_1176_; 
v___x_1175_ = lean_box(0);
lean_inc(v___y_1168_);
lean_inc(v___y_1169_);
v___x_1176_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v___x_1176_, 0, v___y_1169_);
lean_ctor_set(v___x_1176_, 1, v___y_1169_);
lean_ctor_set(v___x_1176_, 2, v___y_1171_);
lean_ctor_set(v___x_1176_, 3, v___y_1168_);
lean_ctor_set(v___x_1176_, 4, v___y_1168_);
lean_ctor_set(v___x_1176_, 5, v___y_1172_);
lean_ctor_set(v___x_1176_, 6, v___y_1170_);
lean_ctor_set(v___x_1176_, 7, v___y_1174_);
lean_ctor_set(v___x_1176_, 8, v___x_1175_);
return v___x_1176_;
}
else
{
lean_object* v___x_1177_; lean_object* v___x_1178_; lean_object* v___x_1179_; 
v___x_1177_ = lp_lean1090_Lean1090_Impl_cbThreat(v_word_1166_);
v___x_1178_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1178_, 0, v___x_1177_);
lean_inc(v___y_1168_);
lean_inc(v___y_1169_);
v___x_1179_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v___x_1179_, 0, v___y_1169_);
lean_ctor_set(v___x_1179_, 1, v___y_1169_);
lean_ctor_set(v___x_1179_, 2, v___y_1171_);
lean_ctor_set(v___x_1179_, 3, v___y_1168_);
lean_ctor_set(v___x_1179_, 4, v___y_1168_);
lean_ctor_set(v___x_1179_, 5, v___y_1172_);
lean_ctor_set(v___x_1179_, 6, v___y_1170_);
lean_ctor_set(v___x_1179_, 7, v___y_1174_);
lean_ctor_set(v___x_1179_, 8, v___x_1178_);
return v___x_1179_;
}
}
v___jp_1180_:
{
lean_object* v___x_1182_; lean_object* v___x_1183_; lean_object* v___x_1184_; lean_object* v___x_1185_; lean_object* v___x_1186_; lean_object* v___x_1187_; lean_object* v___x_1188_; uint8_t v___x_1189_; 
lean_inc(v___y_1181_);
v___x_1182_ = lp_lean1090_Lean1090_Impl_Semantics_tableValues(v___y_1181_, v_word_1166_);
v___x_1183_ = lean_box(0);
v___x_1184_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commB_spec__0(v_register_1165_, v_word_1166_, v___y_1181_, v___x_1183_);
v___x_1185_ = lp_lean1090_Lean1090_Impl_Semantics_commBLabels(v_register_1165_, v_word_1166_);
v___x_1186_ = lp_lean1090_Lean1090_Impl_Semantics_commBStandardFloats(v_register_1165_, v_word_1166_);
v___x_1187_ = lp_lean1090_Lean1090_Impl_Presentation_oracleCommBFloats(v_register_1165_, v_word_1166_);
v___x_1188_ = lean_unsigned_to_nat(48u);
v___x_1189_ = lean_nat_dec_eq(v_register_1165_, v___x_1188_);
if (v___x_1189_ == 0)
{
lean_object* v___x_1190_; 
v___x_1190_ = lean_box(0);
v___y_1168_ = v___x_1185_;
v___y_1169_ = v___x_1182_;
v___y_1170_ = v___x_1187_;
v___y_1171_ = v___x_1184_;
v___y_1172_ = v___x_1186_;
v___y_1173_ = v___x_1189_;
v___y_1174_ = v___x_1190_;
goto v___jp_1167_;
}
else
{
lean_object* v___x_1191_; 
v___x_1191_ = lp_lean1090_Lean1090_Impl_cbStandardThreat(v_word_1166_);
v___y_1168_ = v___x_1185_;
v___y_1169_ = v___x_1182_;
v___y_1170_ = v___x_1187_;
v___y_1171_ = v___x_1184_;
v___y_1172_ = v___x_1186_;
v___y_1173_ = v___x_1189_;
v___y_1174_ = v___x_1191_;
goto v___jp_1167_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Semantics_commB___boxed(lean_object* v_register_1201_, lean_object* v_word_1202_){
_start:
{
lean_object* v_res_1203_; 
v_res_1203_ = lp_lean1090_Lean1090_Impl_Semantics_commB(v_register_1201_, v_word_1202_);
lean_dec(v_word_1202_);
lean_dec(v_register_1201_);
return v_res_1203_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Model_Types(uint8_t builtin);
lean_object* initialize_lean1090_Impl_CommB(uint8_t builtin);
lean_object* initialize_lean1090_Impl_Presentation(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_Semantics(uint8_t builtin) {
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
res = initialize_lean1090_Impl_CommB(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_Presentation(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
