// Lean compiler output
// Module: Impl.JSON
// Imports: public import Init public meta import Init public import Impl.Message public import Impl.Numeric public import Lean.Data.Json.Basic
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
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* l_Int_pow(lean_object*, lean_object*);
lean_object* lean_int_ediv(lean_object*, lean_object*);
lean_object* lean_int_emod(lean_object*, lean_object*);
lean_object* l_List_range(lean_object*);
lean_object* lean_nat_pow(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
uint32_t l_Char_ofNat(lean_object*);
lean_object* lean_string_mk(lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* l_Lean_Json_mkObj(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_frameOracleAltitude(lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
lean_object* lean_string_utf8_byte_size(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint8_t lean_string_memcmp(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Spec_Presentation_Missing_ctorIdx(uint8_t);
lean_object* l_List_foldl___at___00Array_appendList_spec__0___redArg(lean_object*, lean_object*);
double lp_lean1090_Lean1090_Impl_Numeric_eval(lean_object*);
uint64_t lean_float_to_bits(double);
lean_object* lean_uint64_to_nat(uint64_t);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_fromBits(lean_object*);
lean_object* lean_nat_log2(lean_object*);
lean_object* lean_int_mul(lean_object*, lean_object*);
double lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(lean_object*);
lean_object* lean_array_mk(lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* l_Int_toNat(lean_object*);
lean_object* l_List_getD___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_integer(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_floating(double);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_floating___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_rational(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_digits_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_digits_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_digits(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_digits___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_raw_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_raw_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_raw(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_raw___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_value_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_value_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_value(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_value___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_label_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_label_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_label(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_label___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_optional(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_optional___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_numeric_spec__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_numeric_spec__0___closed__0;
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_numeric_spec__0(lean_object*, lean_object*);
static const lean_array_object lp_lean1090_Lean1090_Impl_JSON_numeric___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_numeric___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_numeric___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_numeric(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_numeric___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_number(uint8_t, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_number___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_textField(uint8_t, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_textField___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_naturals_spec__0_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_naturals_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_naturals_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_naturals_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_naturals(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_naturals___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_booleans_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_booleans_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_booleans(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_booleans___boxed(lean_object*, lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_parity___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "parity"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_parity___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_parity___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_parity___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "odd"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_parity___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_parity___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_parity___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "even"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_parity___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_parity___closed__2_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_parity(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_parity___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "subtype"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "version"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "HRD"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "SILs"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__3_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "SIL"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__4_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "BAI"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__5_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "TAH"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__6_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "NACp"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__7_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__7_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__8_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "GVA"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__9 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__9_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "BAQ"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__10 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__10_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "NICa"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__11 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__11_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "NICs"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__12 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__12_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "reserved_status_data"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__13 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__13_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "id"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__14 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__14_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "status"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__15 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__15_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "data"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__16 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__16_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__17;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___boxed(lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "tc"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "bds"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "altitude"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "source"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__3_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "time_sync"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__4_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__4_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__5_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "lat_cpr"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__6_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "lon_cpr"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__7_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__7_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__8_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__6_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__8_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__9 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__9_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "altitude_feet"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__10 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__10_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "05"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__11 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__11_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__11_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__12 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__12_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__12_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__13 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__13_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "NUCp"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__14 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__14_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "NICb"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__15 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__15_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "height_metres"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__16 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__16_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "vrate_src"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__17 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__17_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "vertical_rate"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__18 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__18_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "geo_minus_baro"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__19 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__19_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "airspeed"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__20 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__20_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "airspeed_type"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__21 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__21_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "TAS"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__22 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__22_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "IAS"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__23 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__23_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "id25_27"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__24 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__24_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__24_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__25 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__25_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__25_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__26 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__26_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "_id"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__27 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__27_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "unused"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__28 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__28_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__28_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__29 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__29_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "65"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__30 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__30_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__31_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__30_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__31 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__31_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__32_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__31_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__32 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__32_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__33_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__32_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__33 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__33_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__34_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "62"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__34 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__34_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__35_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__34_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__35 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__35_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__36_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__35_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__36 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__36_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__37_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__36_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__37 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__37_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__38_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "selected_altitude"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__38 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__38_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__39_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "nic_baro"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__39 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__39_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__40_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "tcas_operational"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__40 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__40_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__41_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__40_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__41 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__41_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__42_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__39_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__41_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__42 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__42_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__43_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "mode_status"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__43 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__43_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__44_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "autopilot"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__44 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__44_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__45_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "vnav_mode"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__45 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__45_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__46_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "alt_hold"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__46 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__46_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__47_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "approach_mode"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__47 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__47_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__48_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "lnav_mode"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__48 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__48_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__49_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__48_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__49 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__49_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__50_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__47_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__49_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__50 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__50_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__51_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__46_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__50_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__51 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__51_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__52_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__45_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__51_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__52 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__52_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__53_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__44_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__52_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__53 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__53_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__54_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "61"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__54 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__54_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__55_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__54_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__55 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__55_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__56_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__55_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__56 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__56_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__57_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__56_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__57 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__57_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__58_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "emergency_state"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__58 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__58_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__59_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "squawk"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__59 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__59_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__60_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "09"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__60 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__60_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__61_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__60_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__61 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__61_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__62_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__61_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__62 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__62_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__63_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__62_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__63 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__63_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__64_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "NACv"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__64 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__64_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__65_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__64_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__65 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__65_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__66_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "reserved_data"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__66 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__66_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__67_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__66_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__67 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__67_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__68_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "06"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__68 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__68_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__69_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__68_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__69 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__69_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__70_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__69_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__70 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__70_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__71_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__7_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__71 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__71_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__72_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__6_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__71_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__72 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__72_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__73_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "08"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__73 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__73_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__74_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__73_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__74 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__74_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__75_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__74_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__75 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__75_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__76_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__75_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__76 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__76_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__77_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "callsign"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__77 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__77_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__78_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "wake_vortex"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__78 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__78_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__79_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "NoPosition"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__79 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__79_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__80_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__79_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__80 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__80_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__81_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__80_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__81 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__81_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_adsb___closed__82_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__81_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___closed__82 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__82_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "threat_identity"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "threat_altitude"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "threat_bearing"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__2_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_oracleThreat(lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "lower"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "upper"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "unassigned"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "threat_range"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__3_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "less_than"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__4_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "estimate"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__5_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "tolerance"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__6_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "greater_than"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__7_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_standardThreat(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__1(uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__0___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__0(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_JSON_commB_spec__2(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_JSON_commB_spec__2___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "vrate_barometric"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "vrate_inertial"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "groundspeed"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "turbulence"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__3_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "wind_shear"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__4_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "microburst"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__5_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "icing"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__6_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_adsb___closed__78_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__7_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__6_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__7_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__8_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__5_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__8_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__9 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__9_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__4_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__9_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__10 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__10_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__3_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__10_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__11 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__11_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "static_pressure"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__12 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__12_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "radio_height"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__13 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__13_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "figure_of_merit"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__14 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__14_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "wind_speed"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__15 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__15_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "pressure"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__16 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__16_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "selected_mcp"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__17 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__17_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "selected_fms"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__18 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__18_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "target_altitude_source"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__19 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__19_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "target_source"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__20 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__20_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "issued_ra"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__21 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__21_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "terminated"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__22 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__22_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "multiple"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__23 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__23_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__23_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__24 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__24_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__22_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__24_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__25 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__25_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__21_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__25_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__26 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__26_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "corrective"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__27 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__27_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "downward_sense"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__28 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__28_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "increased_rate"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__29 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__29_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "sense_reversal"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__30 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__30_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__31_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "altitude_crossing"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__31 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__31_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__32_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "positive"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__32 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__32_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__33_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "no_below"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__33 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__33_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__34_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "no_above"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__34 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__34_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__35_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "no_left"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__35 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__35_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__36_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "no_right"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__36 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__36_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__37_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__36_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__37 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__37_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__38_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__35_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__37_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__38 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__38_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__39_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__34_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__38_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__39 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__39_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__40_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__33_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__39_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__40 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__40_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__41_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__32_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__40_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__41 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__41_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__42_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__31_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__41_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__42 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__42_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__43_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__30_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__42_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__43 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__43_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__44_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__29_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__43_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__44 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__44_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__45_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__28_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__44_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__45 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__45_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__46_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__27_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__45_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__46 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__46_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__47_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "registration"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__47 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__47_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__48_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "airline"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__48 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__48_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__49_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "config"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__49 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__49_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__50_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "ovc"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__50 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__50_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__51_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "acas"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__51 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__51_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__52_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "level5"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__52 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__52_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__53_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "mode_s"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__53 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__53_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__54_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "identification"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__54 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__54_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__55_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "squitter"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__55 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__55_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__56_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "sic"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__56 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__56_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__57_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "gicb"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__57 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__57_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__58_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "acas_hybrid"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__58 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__58_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__59_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "acas_ra"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__59 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__59_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__60_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__59_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__60 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__60_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__61_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__58_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__60_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__61 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__61_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__62_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__57_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__61_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__62 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__62_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__63_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__56_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__62_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__63 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__63_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__64_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__55_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__63_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__64 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__64_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__65_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__54_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__64_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__65 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__65_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__66_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__53_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__65_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__66 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__66_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__67_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__52_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__66_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__67 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__67_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__68_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__51_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__67_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__68 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__68_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__69_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__50_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__68_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__69 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__69_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__70_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__49_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__69_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__70 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__70_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__71_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "subnet"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__71 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__71_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__72_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__71_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__72 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__72_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_commB___closed__73_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "dte"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___closed__73 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_commB___closed__73_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_commB(uint8_t, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_altitude(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_altitude___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_identity(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_message_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_message_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_message_spec__1(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_message_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_message_spec__2_spec__2(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_message_spec__2(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "tisb"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__0_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "ADSB_ES_NT"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__1_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "ADSB_ES_NT_ALT"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__2_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "TISB_FINE"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__3_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "TISB_COARSE"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__4_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "TISB_MANAGE"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__5_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "TISB_ADSB_RELAY"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__6_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "TISB_ADSB"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__7_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "Reserved"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__8 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__8_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__8_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__9 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__9_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__7_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__9_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__10 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__10_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__6_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__10_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__11 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__11_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__5_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__11_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__12 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__12_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__4_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__12_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__13 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__13_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__3_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__13_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__14 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__14_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__2_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__14_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__15 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__15_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__1_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__15_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__16 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__16_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "icao24"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__17 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__17_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "df"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__18 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__18_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "0"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__19 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__19_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__19_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__20 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__20_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__18_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__20_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__21 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__21_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__21_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__22 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__22_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "4"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__23 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__23_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "5"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__24 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__24_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "11"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__25 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__25_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__25_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__26 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__26_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__18_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__26_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__27 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__27_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "capability"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__28 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__28_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "level1"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__29 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__29_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "AG_RESERVED"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__30 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__30_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__31_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "ground"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__31 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__31_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__32_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "airborne"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__32 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__32_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__33_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "ground/airborne"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__33 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__33_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__34_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "AG_DR0"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__34 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__34_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__35_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__34_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__35 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__35_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__36_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__33_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__35_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__36 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__36_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__37_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__32_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__36_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__37 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__37_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__38_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__31_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__37_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__38 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__38_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__39_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__30_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__38_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__39 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__39_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__40_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__30_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__39_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__40 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__40_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__41_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__30_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__40_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__41 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__41_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__42_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__29_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__41_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__42 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__42_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__43_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "16"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__43 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__43_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__44_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__43_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__44 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__44_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__45_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__18_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__44_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__45 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__45_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__46_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "vs"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__46 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__46_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__47_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "sl"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__47 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__47_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__48_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "ri"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__48 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__48_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__49_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "17"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__49 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__49_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__50_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "18"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__50 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__50_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__51_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "ExtendedSquitterMilitary"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__51 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__51_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__52_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__51_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__52 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__52_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__53_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__18_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__52_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__53 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__53_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__54_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "af"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__54 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__54_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__55_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "20"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__55 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__55_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__56_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "21"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__56 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__56_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__57_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "CommDExtended"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__57 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__57_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__58_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__57_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__58 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__58_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_JSON_message___closed__59_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__18_value),((lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__58_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__59 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__59_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__60_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "spare"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__60 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__60_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__61_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "nd"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__61 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__61_value;
static const lean_string_object lp_lean1090_Lean1090_Impl_JSON_message___closed__62_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "md"};
static const lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__62 = (const lean_object*)&lp_lean1090_Lean1090_Impl_JSON_message___closed__62_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_JSON_message___closed__63_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_JSON_message___closed__63;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_message(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_message___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_integer(lean_object* v_value_1_){
_start:
{
lean_object* v___x_2_; lean_object* v___x_3_; lean_object* v___x_4_; 
v___x_2_ = lean_unsigned_to_nat(0u);
v___x_3_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_3_, 0, v_value_1_);
lean_ctor_set(v___x_3_, 1, v___x_2_);
v___x_4_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_4_, 0, v___x_3_);
return v___x_4_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_floating(double v_value_5_){
_start:
{
uint64_t v___x_6_; lean_object* v___x_7_; lean_object* v___x_8_; 
v___x_6_ = lean_float_to_bits(v_value_5_);
v___x_7_ = lean_uint64_to_nat(v___x_6_);
v___x_8_ = lp_lean1090_Lean1090_Impl_Binary64_fromBits(v___x_7_);
lean_dec(v___x_7_);
if (lean_obj_tag(v___x_8_) == 0)
{
lean_object* v___x_9_; 
v___x_9_ = lean_box(0);
return v___x_9_;
}
else
{
lean_object* v_val_10_; lean_object* v___x_12_; uint8_t v_isShared_13_; uint8_t v_isSharedCheck_31_; 
v_val_10_ = lean_ctor_get(v___x_8_, 0);
v_isSharedCheck_31_ = !lean_is_exclusive(v___x_8_);
if (v_isSharedCheck_31_ == 0)
{
v___x_12_ = v___x_8_;
v_isShared_13_ = v_isSharedCheck_31_;
goto v_resetjp_11_;
}
else
{
lean_inc(v_val_10_);
lean_dec(v___x_8_);
v___x_12_ = lean_box(0);
v_isShared_13_ = v_isSharedCheck_31_;
goto v_resetjp_11_;
}
v_resetjp_11_:
{
lean_object* v_num_14_; lean_object* v_den_15_; lean_object* v___x_17_; uint8_t v_isShared_18_; uint8_t v_isSharedCheck_30_; 
v_num_14_ = lean_ctor_get(v_val_10_, 0);
v_den_15_ = lean_ctor_get(v_val_10_, 1);
v_isSharedCheck_30_ = !lean_is_exclusive(v_val_10_);
if (v_isSharedCheck_30_ == 0)
{
v___x_17_ = v_val_10_;
v_isShared_18_ = v_isSharedCheck_30_;
goto v_resetjp_16_;
}
else
{
lean_inc(v_den_15_);
lean_inc(v_num_14_);
lean_dec(v_val_10_);
v___x_17_ = lean_box(0);
v_isShared_18_ = v_isSharedCheck_30_;
goto v_resetjp_16_;
}
v_resetjp_16_:
{
lean_object* v_exponent_19_; lean_object* v___x_20_; lean_object* v___x_21_; lean_object* v___x_22_; lean_object* v___x_23_; lean_object* v___x_25_; 
v_exponent_19_ = lean_nat_log2(v_den_15_);
lean_dec(v_den_15_);
v___x_20_ = lean_unsigned_to_nat(5u);
v___x_21_ = lean_nat_pow(v___x_20_, v_exponent_19_);
v___x_22_ = lean_nat_to_int(v___x_21_);
v___x_23_ = lean_int_mul(v_num_14_, v___x_22_);
lean_dec(v___x_22_);
lean_dec(v_num_14_);
if (v_isShared_18_ == 0)
{
lean_ctor_set(v___x_17_, 1, v_exponent_19_);
lean_ctor_set(v___x_17_, 0, v___x_23_);
v___x_25_ = v___x_17_;
goto v_reusejp_24_;
}
else
{
lean_object* v_reuseFailAlloc_29_; 
v_reuseFailAlloc_29_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_29_, 0, v___x_23_);
lean_ctor_set(v_reuseFailAlloc_29_, 1, v_exponent_19_);
v___x_25_ = v_reuseFailAlloc_29_;
goto v_reusejp_24_;
}
v_reusejp_24_:
{
lean_object* v___x_27_; 
if (v_isShared_13_ == 0)
{
lean_ctor_set_tag(v___x_12_, 2);
lean_ctor_set(v___x_12_, 0, v___x_25_);
v___x_27_ = v___x_12_;
goto v_reusejp_26_;
}
else
{
lean_object* v_reuseFailAlloc_28_; 
v_reuseFailAlloc_28_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_28_, 0, v___x_25_);
v___x_27_ = v_reuseFailAlloc_28_;
goto v_reusejp_26_;
}
v_reusejp_26_:
{
return v___x_27_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_floating___boxed(lean_object* v_value_32_){
_start:
{
double v_value_boxed_33_; lean_object* v_res_34_; 
v_value_boxed_33_ = lean_unbox_float(v_value_32_);
lean_dec_ref(v_value_32_);
v_res_34_ = lp_lean1090_Lean1090_Impl_JSON_floating(v_value_boxed_33_);
return v_res_34_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_rational(lean_object* v_value_35_){
_start:
{
lean_object* v_num_36_; lean_object* v_den_37_; lean_object* v___x_38_; uint8_t v___x_39_; 
v_num_36_ = lean_ctor_get(v_value_35_, 0);
v_den_37_ = lean_ctor_get(v_value_35_, 1);
v___x_38_ = lean_unsigned_to_nat(1u);
v___x_39_ = lean_nat_dec_eq(v_den_37_, v___x_38_);
if (v___x_39_ == 0)
{
double v___x_40_; lean_object* v___x_41_; 
v___x_40_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_value_35_);
v___x_41_ = lp_lean1090_Lean1090_Impl_JSON_floating(v___x_40_);
return v___x_41_;
}
else
{
lean_object* v___x_42_; 
lean_inc(v_num_36_);
lean_dec_ref(v_value_35_);
v___x_42_ = lp_lean1090_Lean1090_Impl_JSON_integer(v_num_36_);
return v___x_42_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_digits_spec__0(lean_object* v_base_43_, lean_object* v_value_44_, lean_object* v_a_45_, lean_object* v_a_46_){
_start:
{
if (lean_obj_tag(v_a_45_) == 0)
{
lean_object* v___x_47_; 
v___x_47_ = l_List_reverse___redArg(v_a_46_);
return v___x_47_;
}
else
{
lean_object* v_head_48_; lean_object* v_tail_49_; lean_object* v___x_51_; uint8_t v_isShared_52_; uint8_t v_isSharedCheck_71_; 
v_head_48_ = lean_ctor_get(v_a_45_, 0);
v_tail_49_ = lean_ctor_get(v_a_45_, 1);
v_isSharedCheck_71_ = !lean_is_exclusive(v_a_45_);
if (v_isSharedCheck_71_ == 0)
{
v___x_51_ = v_a_45_;
v_isShared_52_ = v_isSharedCheck_71_;
goto v_resetjp_50_;
}
else
{
lean_inc(v_tail_49_);
lean_inc(v_head_48_);
lean_dec(v_a_45_);
v___x_51_ = lean_box(0);
v_isShared_52_ = v_isSharedCheck_71_;
goto v_resetjp_50_;
}
v_resetjp_50_:
{
uint32_t v___y_54_; lean_object* v___x_60_; lean_object* v___x_61_; lean_object* v_digit_62_; lean_object* v___x_63_; uint8_t v___x_64_; 
v___x_60_ = lean_nat_pow(v_base_43_, v_head_48_);
lean_dec(v_head_48_);
v___x_61_ = lean_nat_div(v_value_44_, v___x_60_);
lean_dec(v___x_60_);
v_digit_62_ = lean_nat_mod(v___x_61_, v_base_43_);
lean_dec(v___x_61_);
v___x_63_ = lean_unsigned_to_nat(10u);
v___x_64_ = lean_nat_dec_lt(v_digit_62_, v___x_63_);
if (v___x_64_ == 0)
{
lean_object* v___x_65_; lean_object* v___x_66_; uint32_t v___x_67_; 
v___x_65_ = lean_unsigned_to_nat(87u);
v___x_66_ = lean_nat_add(v___x_65_, v_digit_62_);
lean_dec(v_digit_62_);
v___x_67_ = l_Char_ofNat(v___x_66_);
lean_dec(v___x_66_);
v___y_54_ = v___x_67_;
goto v___jp_53_;
}
else
{
lean_object* v___x_68_; lean_object* v___x_69_; uint32_t v___x_70_; 
v___x_68_ = lean_unsigned_to_nat(48u);
v___x_69_ = lean_nat_add(v___x_68_, v_digit_62_);
lean_dec(v_digit_62_);
v___x_70_ = l_Char_ofNat(v___x_69_);
lean_dec(v___x_69_);
v___y_54_ = v___x_70_;
goto v___jp_53_;
}
v___jp_53_:
{
lean_object* v___x_55_; lean_object* v___x_57_; 
v___x_55_ = lean_box_uint32(v___y_54_);
if (v_isShared_52_ == 0)
{
lean_ctor_set(v___x_51_, 1, v_a_46_);
lean_ctor_set(v___x_51_, 0, v___x_55_);
v___x_57_ = v___x_51_;
goto v_reusejp_56_;
}
else
{
lean_object* v_reuseFailAlloc_59_; 
v_reuseFailAlloc_59_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_59_, 0, v___x_55_);
lean_ctor_set(v_reuseFailAlloc_59_, 1, v_a_46_);
v___x_57_ = v_reuseFailAlloc_59_;
goto v_reusejp_56_;
}
v_reusejp_56_:
{
v_a_45_ = v_tail_49_;
v_a_46_ = v___x_57_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_digits_spec__0___boxed(lean_object* v_base_72_, lean_object* v_value_73_, lean_object* v_a_74_, lean_object* v_a_75_){
_start:
{
lean_object* v_res_76_; 
v_res_76_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_digits_spec__0(v_base_72_, v_value_73_, v_a_74_, v_a_75_);
lean_dec(v_value_73_);
lean_dec(v_base_72_);
return v_res_76_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_digits(lean_object* v_base_77_, lean_object* v_width_78_, lean_object* v_value_79_){
_start:
{
lean_object* v___x_80_; lean_object* v___x_81_; lean_object* v___x_82_; lean_object* v___x_83_; lean_object* v___x_84_; 
v___x_80_ = l_List_range(v_width_78_);
v___x_81_ = l_List_reverse___redArg(v___x_80_);
v___x_82_ = lean_box(0);
v___x_83_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_digits_spec__0(v_base_77_, v_value_79_, v___x_81_, v___x_82_);
v___x_84_ = lean_string_mk(v___x_83_);
return v___x_84_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_digits___boxed(lean_object* v_base_85_, lean_object* v_width_86_, lean_object* v_value_87_){
_start:
{
lean_object* v_res_88_; 
v_res_88_ = lp_lean1090_Lean1090_Impl_JSON_digits(v_base_85_, v_width_86_, v_value_87_);
lean_dec(v_value_87_);
lean_dec(v_base_85_);
return v_res_88_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_raw_spec__0(lean_object* v_key_89_, lean_object* v_x_90_){
_start:
{
if (lean_obj_tag(v_x_90_) == 0)
{
lean_object* v___x_91_; 
v___x_91_ = lean_box(0);
return v___x_91_;
}
else
{
lean_object* v_head_92_; lean_object* v_tail_93_; lean_object* v_name_94_; uint8_t v___x_95_; 
v_head_92_ = lean_ctor_get(v_x_90_, 0);
v_tail_93_ = lean_ctor_get(v_x_90_, 1);
v_name_94_ = lean_ctor_get(v_head_92_, 0);
v___x_95_ = lean_string_dec_eq(v_name_94_, v_key_89_);
if (v___x_95_ == 0)
{
v_x_90_ = v_tail_93_;
goto _start;
}
else
{
lean_object* v___x_97_; 
lean_inc(v_head_92_);
v___x_97_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_97_, 0, v_head_92_);
return v___x_97_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_raw_spec__0___boxed(lean_object* v_key_98_, lean_object* v_x_99_){
_start:
{
lean_object* v_res_100_; 
v_res_100_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_raw_spec__0(v_key_98_, v_x_99_);
lean_dec(v_x_99_);
lean_dec_ref(v_key_98_);
return v_res_100_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_raw(lean_object* v_record_101_, lean_object* v_key_102_){
_start:
{
lean_object* v_fields_103_; lean_object* v___x_104_; 
v_fields_103_ = lean_ctor_get(v_record_101_, 1);
v___x_104_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_raw_spec__0(v_key_102_, v_fields_103_);
if (lean_obj_tag(v___x_104_) == 0)
{
lean_object* v___x_105_; 
v___x_105_ = lean_unsigned_to_nat(0u);
return v___x_105_;
}
else
{
lean_object* v_val_106_; lean_object* v_code_107_; 
v_val_106_ = lean_ctor_get(v___x_104_, 0);
lean_inc(v_val_106_);
lean_dec_ref_known(v___x_104_, 1);
v_code_107_ = lean_ctor_get(v_val_106_, 1);
lean_inc(v_code_107_);
lean_dec(v_val_106_);
return v_code_107_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_raw___boxed(lean_object* v_record_108_, lean_object* v_key_109_){
_start:
{
lean_object* v_res_110_; 
v_res_110_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_108_, v_key_109_);
lean_dec_ref(v_key_109_);
lean_dec_ref(v_record_108_);
return v_res_110_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_value_spec__0(lean_object* v_key_111_, lean_object* v_x_112_){
_start:
{
if (lean_obj_tag(v_x_112_) == 0)
{
lean_object* v___x_113_; 
v___x_113_ = lean_box(0);
return v___x_113_;
}
else
{
lean_object* v_head_114_; lean_object* v_tail_115_; lean_object* v_fst_116_; uint8_t v___x_117_; 
v_head_114_ = lean_ctor_get(v_x_112_, 0);
v_tail_115_ = lean_ctor_get(v_x_112_, 1);
v_fst_116_ = lean_ctor_get(v_head_114_, 0);
v___x_117_ = lean_string_dec_eq(v_fst_116_, v_key_111_);
if (v___x_117_ == 0)
{
v_x_112_ = v_tail_115_;
goto _start;
}
else
{
lean_object* v___x_119_; 
lean_inc(v_head_114_);
v___x_119_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_119_, 0, v_head_114_);
return v___x_119_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_value_spec__0___boxed(lean_object* v_key_120_, lean_object* v_x_121_){
_start:
{
lean_object* v_res_122_; 
v_res_122_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_value_spec__0(v_key_120_, v_x_121_);
lean_dec(v_x_121_);
lean_dec_ref(v_key_120_);
return v_res_122_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_value(uint8_t v_oracle_123_, lean_object* v_p_124_, lean_object* v_key_125_){
_start:
{
lean_object* v___y_127_; 
if (v_oracle_123_ == 0)
{
lean_object* v_standardValues_132_; 
v_standardValues_132_ = lean_ctor_get(v_p_124_, 1);
v___y_127_ = v_standardValues_132_;
goto v___jp_126_;
}
else
{
lean_object* v_oracleValues_133_; 
v_oracleValues_133_ = lean_ctor_get(v_p_124_, 2);
v___y_127_ = v_oracleValues_133_;
goto v___jp_126_;
}
v___jp_126_:
{
lean_object* v___x_128_; 
v___x_128_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_value_spec__0(v_key_125_, v___y_127_);
if (lean_obj_tag(v___x_128_) == 0)
{
lean_object* v___x_129_; 
v___x_129_ = lean_box(0);
return v___x_129_;
}
else
{
lean_object* v_val_130_; lean_object* v_snd_131_; 
v_val_130_ = lean_ctor_get(v___x_128_, 0);
lean_inc(v_val_130_);
lean_dec_ref_known(v___x_128_, 1);
v_snd_131_ = lean_ctor_get(v_val_130_, 1);
lean_inc(v_snd_131_);
lean_dec(v_val_130_);
return v_snd_131_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_value___boxed(lean_object* v_oracle_134_, lean_object* v_p_135_, lean_object* v_key_136_){
_start:
{
uint8_t v_oracle_boxed_137_; lean_object* v_res_138_; 
v_oracle_boxed_137_ = lean_unbox(v_oracle_134_);
v_res_138_ = lp_lean1090_Lean1090_Impl_JSON_value(v_oracle_boxed_137_, v_p_135_, v_key_136_);
lean_dec_ref(v_key_136_);
lean_dec_ref(v_p_135_);
return v_res_138_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_label_spec__0(lean_object* v_key_139_, lean_object* v_x_140_){
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
lean_object* v_head_142_; lean_object* v_tail_143_; lean_object* v_fst_144_; uint8_t v___x_145_; 
v_head_142_ = lean_ctor_get(v_x_140_, 0);
v_tail_143_ = lean_ctor_get(v_x_140_, 1);
v_fst_144_ = lean_ctor_get(v_head_142_, 0);
v___x_145_ = lean_string_dec_eq(v_fst_144_, v_key_139_);
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
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_label_spec__0___boxed(lean_object* v_key_148_, lean_object* v_x_149_){
_start:
{
lean_object* v_res_150_; 
v_res_150_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_label_spec__0(v_key_148_, v_x_149_);
lean_dec(v_x_149_);
lean_dec_ref(v_key_148_);
return v_res_150_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_label(uint8_t v_oracle_151_, lean_object* v_p_152_, lean_object* v_key_153_){
_start:
{
lean_object* v___y_155_; 
if (v_oracle_151_ == 0)
{
lean_object* v_standardLabels_160_; 
v_standardLabels_160_ = lean_ctor_get(v_p_152_, 3);
v___y_155_ = v_standardLabels_160_;
goto v___jp_154_;
}
else
{
lean_object* v_oracleLabels_161_; 
v_oracleLabels_161_ = lean_ctor_get(v_p_152_, 4);
v___y_155_ = v_oracleLabels_161_;
goto v___jp_154_;
}
v___jp_154_:
{
lean_object* v___x_156_; 
v___x_156_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_label_spec__0(v_key_153_, v___y_155_);
if (lean_obj_tag(v___x_156_) == 0)
{
lean_object* v___x_157_; 
v___x_157_ = lean_box(0);
return v___x_157_;
}
else
{
lean_object* v_val_158_; lean_object* v_snd_159_; 
v_val_158_ = lean_ctor_get(v___x_156_, 0);
lean_inc(v_val_158_);
lean_dec_ref_known(v___x_156_, 1);
v_snd_159_ = lean_ctor_get(v_val_158_, 1);
lean_inc(v_snd_159_);
lean_dec(v_val_158_);
return v_snd_159_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_label___boxed(lean_object* v_oracle_162_, lean_object* v_p_163_, lean_object* v_key_164_){
_start:
{
uint8_t v_oracle_boxed_165_; lean_object* v_res_166_; 
v_oracle_boxed_165_ = lean_unbox(v_oracle_162_);
v_res_166_ = lp_lean1090_Lean1090_Impl_JSON_label(v_oracle_boxed_165_, v_p_163_, v_key_164_);
lean_dec_ref(v_key_164_);
lean_dec_ref(v_p_163_);
return v_res_166_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_optional(lean_object* v_key_167_, lean_object* v_entry_168_, uint8_t v_omitMissing_169_){
_start:
{
if (lean_obj_tag(v_entry_168_) == 0)
{
if (v_omitMissing_169_ == 0)
{
lean_object* v___x_170_; lean_object* v___x_171_; lean_object* v___x_172_; lean_object* v___x_173_; 
v___x_170_ = lean_box(0);
v___x_171_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_171_, 0, v_key_167_);
lean_ctor_set(v___x_171_, 1, v___x_170_);
v___x_172_ = lean_box(0);
v___x_173_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_173_, 0, v___x_171_);
lean_ctor_set(v___x_173_, 1, v___x_172_);
return v___x_173_;
}
else
{
lean_object* v___x_174_; 
lean_dec_ref(v_key_167_);
v___x_174_ = lean_box(0);
return v___x_174_;
}
}
else
{
lean_object* v_val_175_; lean_object* v___x_176_; lean_object* v___x_177_; lean_object* v___x_178_; 
v_val_175_ = lean_ctor_get(v_entry_168_, 0);
lean_inc(v_val_175_);
v___x_176_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_176_, 0, v_key_167_);
lean_ctor_set(v___x_176_, 1, v_val_175_);
v___x_177_ = lean_box(0);
v___x_178_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_178_, 0, v___x_176_);
lean_ctor_set(v___x_178_, 1, v___x_177_);
return v___x_178_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_optional___boxed(lean_object* v_key_179_, lean_object* v_entry_180_, lean_object* v_omitMissing_181_){
_start:
{
uint8_t v_omitMissing_boxed_182_; lean_object* v_res_183_; 
v_omitMissing_boxed_182_ = lean_unbox(v_omitMissing_181_);
v_res_183_ = lp_lean1090_Lean1090_Impl_JSON_optional(v_key_179_, v_entry_180_, v_omitMissing_boxed_182_);
lean_dec(v_entry_180_);
return v_res_183_;
}
}
static lean_object* _init_lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_numeric_spec__0___closed__0(void){
_start:
{
uint8_t v___x_184_; lean_object* v___x_185_; 
v___x_184_ = 0;
v___x_185_ = lp_lean1090_Lean1090_Spec_Presentation_Missing_ctorIdx(v___x_184_);
return v___x_185_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_numeric_spec__0(lean_object* v_a_186_, lean_object* v_a_187_){
_start:
{
if (lean_obj_tag(v_a_186_) == 0)
{
lean_object* v___x_188_; 
v___x_188_ = lean_array_to_list(v_a_187_);
return v___x_188_;
}
else
{
lean_object* v_head_189_; lean_object* v_tail_190_; lean_object* v_key_191_; lean_object* v_value_192_; uint8_t v_missing_193_; lean_object* v___y_195_; 
v_head_189_ = lean_ctor_get(v_a_186_, 0);
lean_inc(v_head_189_);
v_tail_190_ = lean_ctor_get(v_a_186_, 1);
lean_inc(v_tail_190_);
lean_dec_ref_known(v_a_186_, 2);
v_key_191_ = lean_ctor_get(v_head_189_, 0);
lean_inc_ref(v_key_191_);
v_value_192_ = lean_ctor_get(v_head_189_, 1);
lean_inc(v_value_192_);
v_missing_193_ = lean_ctor_get_uint8(v_head_189_, sizeof(void*)*2);
lean_dec(v_head_189_);
if (lean_obj_tag(v_value_192_) == 0)
{
lean_object* v___x_202_; 
v___x_202_ = lean_box(0);
v___y_195_ = v___x_202_;
goto v___jp_194_;
}
else
{
lean_object* v_val_203_; lean_object* v___x_205_; uint8_t v_isShared_206_; uint8_t v_isSharedCheck_212_; 
v_val_203_ = lean_ctor_get(v_value_192_, 0);
v_isSharedCheck_212_ = !lean_is_exclusive(v_value_192_);
if (v_isSharedCheck_212_ == 0)
{
v___x_205_ = v_value_192_;
v_isShared_206_ = v_isSharedCheck_212_;
goto v_resetjp_204_;
}
else
{
lean_inc(v_val_203_);
lean_dec(v_value_192_);
v___x_205_ = lean_box(0);
v_isShared_206_ = v_isSharedCheck_212_;
goto v_resetjp_204_;
}
v_resetjp_204_:
{
double v___x_207_; lean_object* v___x_208_; lean_object* v___x_210_; 
v___x_207_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_val_203_);
v___x_208_ = lp_lean1090_Lean1090_Impl_JSON_floating(v___x_207_);
if (v_isShared_206_ == 0)
{
lean_ctor_set(v___x_205_, 0, v___x_208_);
v___x_210_ = v___x_205_;
goto v_reusejp_209_;
}
else
{
lean_object* v_reuseFailAlloc_211_; 
v_reuseFailAlloc_211_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_211_, 0, v___x_208_);
v___x_210_ = v_reuseFailAlloc_211_;
goto v_reusejp_209_;
}
v_reusejp_209_:
{
v___y_195_ = v___x_210_;
goto v___jp_194_;
}
}
}
v___jp_194_:
{
lean_object* v___x_196_; lean_object* v___x_197_; uint8_t v___x_198_; lean_object* v___x_199_; lean_object* v___x_200_; 
v___x_196_ = lp_lean1090_Lean1090_Spec_Presentation_Missing_ctorIdx(v_missing_193_);
v___x_197_ = lean_obj_once(&lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_numeric_spec__0___closed__0, &lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_numeric_spec__0___closed__0_once, _init_lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_numeric_spec__0___closed__0);
v___x_198_ = lean_nat_dec_eq(v___x_196_, v___x_197_);
lean_dec(v___x_196_);
v___x_199_ = lp_lean1090_Lean1090_Impl_JSON_optional(v_key_191_, v___y_195_, v___x_198_);
lean_dec(v___y_195_);
v___x_200_ = l_List_foldl___at___00Array_appendList_spec__0___redArg(v_a_187_, v___x_199_);
v_a_186_ = v_tail_190_;
v_a_187_ = v___x_200_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_numeric(uint8_t v_oracle_215_, lean_object* v_p_216_){
_start:
{
lean_object* v___y_218_; 
if (v_oracle_215_ == 0)
{
lean_object* v_standardFloats_221_; 
v_standardFloats_221_ = lean_ctor_get(v_p_216_, 5);
lean_inc(v_standardFloats_221_);
lean_dec_ref(v_p_216_);
v___y_218_ = v_standardFloats_221_;
goto v___jp_217_;
}
else
{
lean_object* v_oracleFloats_222_; 
v_oracleFloats_222_ = lean_ctor_get(v_p_216_, 6);
lean_inc(v_oracleFloats_222_);
lean_dec_ref(v_p_216_);
v___y_218_ = v_oracleFloats_222_;
goto v___jp_217_;
}
v___jp_217_:
{
lean_object* v___x_219_; lean_object* v___x_220_; 
v___x_219_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_numeric___closed__0));
v___x_220_ = lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_numeric_spec__0(v___y_218_, v___x_219_);
return v___x_220_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_numeric___boxed(lean_object* v_oracle_223_, lean_object* v_p_224_){
_start:
{
uint8_t v_oracle_boxed_225_; lean_object* v_res_226_; 
v_oracle_boxed_225_ = lean_unbox(v_oracle_223_);
v_res_226_ = lp_lean1090_Lean1090_Impl_JSON_numeric(v_oracle_boxed_225_, v_p_224_);
return v_res_226_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_number(uint8_t v_oracle_227_, lean_object* v_p_228_, lean_object* v_key_229_, lean_object* v_rename_230_, uint8_t v_omitMissing_231_){
_start:
{
lean_object* v___x_232_; 
v___x_232_ = lp_lean1090_Lean1090_Impl_JSON_value(v_oracle_227_, v_p_228_, v_key_229_);
if (lean_obj_tag(v___x_232_) == 0)
{
lean_object* v___x_233_; lean_object* v___x_234_; 
v___x_233_ = lean_box(0);
v___x_234_ = lp_lean1090_Lean1090_Impl_JSON_optional(v_rename_230_, v___x_233_, v_omitMissing_231_);
return v___x_234_;
}
else
{
lean_object* v_val_235_; lean_object* v___x_237_; uint8_t v_isShared_238_; uint8_t v_isSharedCheck_244_; 
v_val_235_ = lean_ctor_get(v___x_232_, 0);
v_isSharedCheck_244_ = !lean_is_exclusive(v___x_232_);
if (v_isSharedCheck_244_ == 0)
{
v___x_237_ = v___x_232_;
v_isShared_238_ = v_isSharedCheck_244_;
goto v_resetjp_236_;
}
else
{
lean_inc(v_val_235_);
lean_dec(v___x_232_);
v___x_237_ = lean_box(0);
v_isShared_238_ = v_isSharedCheck_244_;
goto v_resetjp_236_;
}
v_resetjp_236_:
{
lean_object* v___x_239_; lean_object* v___x_241_; 
v___x_239_ = lp_lean1090_Lean1090_Impl_JSON_rational(v_val_235_);
if (v_isShared_238_ == 0)
{
lean_ctor_set(v___x_237_, 0, v___x_239_);
v___x_241_ = v___x_237_;
goto v_reusejp_240_;
}
else
{
lean_object* v_reuseFailAlloc_243_; 
v_reuseFailAlloc_243_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_243_, 0, v___x_239_);
v___x_241_ = v_reuseFailAlloc_243_;
goto v_reusejp_240_;
}
v_reusejp_240_:
{
lean_object* v___x_242_; 
v___x_242_ = lp_lean1090_Lean1090_Impl_JSON_optional(v_rename_230_, v___x_241_, v_omitMissing_231_);
lean_dec_ref(v___x_241_);
return v___x_242_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_number___boxed(lean_object* v_oracle_245_, lean_object* v_p_246_, lean_object* v_key_247_, lean_object* v_rename_248_, lean_object* v_omitMissing_249_){
_start:
{
uint8_t v_oracle_boxed_250_; uint8_t v_omitMissing_boxed_251_; lean_object* v_res_252_; 
v_oracle_boxed_250_ = lean_unbox(v_oracle_245_);
v_omitMissing_boxed_251_ = lean_unbox(v_omitMissing_249_);
v_res_252_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_boxed_250_, v_p_246_, v_key_247_, v_rename_248_, v_omitMissing_boxed_251_);
lean_dec_ref(v_key_247_);
lean_dec_ref(v_p_246_);
return v_res_252_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_textField(uint8_t v_oracle_253_, lean_object* v_p_254_, lean_object* v_key_255_, lean_object* v_rename_256_, uint8_t v_omitMissing_257_){
_start:
{
lean_object* v___x_258_; 
v___x_258_ = lp_lean1090_Lean1090_Impl_JSON_label(v_oracle_253_, v_p_254_, v_key_255_);
if (lean_obj_tag(v___x_258_) == 0)
{
lean_object* v___x_259_; lean_object* v___x_260_; 
v___x_259_ = lean_box(0);
v___x_260_ = lp_lean1090_Lean1090_Impl_JSON_optional(v_rename_256_, v___x_259_, v_omitMissing_257_);
return v___x_260_;
}
else
{
lean_object* v_val_261_; lean_object* v___x_263_; uint8_t v_isShared_264_; uint8_t v_isSharedCheck_270_; 
v_val_261_ = lean_ctor_get(v___x_258_, 0);
v_isSharedCheck_270_ = !lean_is_exclusive(v___x_258_);
if (v_isSharedCheck_270_ == 0)
{
v___x_263_ = v___x_258_;
v_isShared_264_ = v_isSharedCheck_270_;
goto v_resetjp_262_;
}
else
{
lean_inc(v_val_261_);
lean_dec(v___x_258_);
v___x_263_ = lean_box(0);
v_isShared_264_ = v_isSharedCheck_270_;
goto v_resetjp_262_;
}
v_resetjp_262_:
{
lean_object* v___x_265_; lean_object* v___x_267_; 
v___x_265_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_265_, 0, v_val_261_);
if (v_isShared_264_ == 0)
{
lean_ctor_set(v___x_263_, 0, v___x_265_);
v___x_267_ = v___x_263_;
goto v_reusejp_266_;
}
else
{
lean_object* v_reuseFailAlloc_269_; 
v_reuseFailAlloc_269_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_269_, 0, v___x_265_);
v___x_267_ = v_reuseFailAlloc_269_;
goto v_reusejp_266_;
}
v_reusejp_266_:
{
lean_object* v___x_268_; 
v___x_268_ = lp_lean1090_Lean1090_Impl_JSON_optional(v_rename_256_, v___x_267_, v_omitMissing_257_);
lean_dec_ref(v___x_267_);
return v___x_268_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_textField___boxed(lean_object* v_oracle_271_, lean_object* v_p_272_, lean_object* v_key_273_, lean_object* v_rename_274_, lean_object* v_omitMissing_275_){
_start:
{
uint8_t v_oracle_boxed_276_; uint8_t v_omitMissing_boxed_277_; lean_object* v_res_278_; 
v_oracle_boxed_276_ = lean_unbox(v_oracle_271_);
v_omitMissing_boxed_277_ = lean_unbox(v_omitMissing_275_);
v_res_278_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_boxed_276_, v_p_272_, v_key_273_, v_rename_274_, v_omitMissing_boxed_277_);
lean_dec_ref(v_key_273_);
lean_dec_ref(v_p_272_);
return v_res_278_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_naturals_spec__0_spec__0(lean_object* v_record_279_, lean_object* v_a_280_, lean_object* v_a_281_){
_start:
{
if (lean_obj_tag(v_a_280_) == 0)
{
lean_object* v___x_282_; 
v___x_282_ = l_List_reverse___redArg(v_a_281_);
return v___x_282_;
}
else
{
lean_object* v_head_283_; lean_object* v_tail_284_; lean_object* v___x_286_; uint8_t v_isShared_287_; uint8_t v_isSharedCheck_296_; 
v_head_283_ = lean_ctor_get(v_a_280_, 0);
v_tail_284_ = lean_ctor_get(v_a_280_, 1);
v_isSharedCheck_296_ = !lean_is_exclusive(v_a_280_);
if (v_isSharedCheck_296_ == 0)
{
v___x_286_ = v_a_280_;
v_isShared_287_ = v_isSharedCheck_296_;
goto v_resetjp_285_;
}
else
{
lean_inc(v_tail_284_);
lean_inc(v_head_283_);
lean_dec(v_a_280_);
v___x_286_ = lean_box(0);
v_isShared_287_ = v_isSharedCheck_296_;
goto v_resetjp_285_;
}
v_resetjp_285_:
{
lean_object* v___x_288_; lean_object* v___x_289_; lean_object* v___x_290_; lean_object* v___x_291_; lean_object* v___x_293_; 
v___x_288_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_279_, v_head_283_);
v___x_289_ = lean_nat_to_int(v___x_288_);
v___x_290_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_289_);
v___x_291_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_291_, 0, v_head_283_);
lean_ctor_set(v___x_291_, 1, v___x_290_);
if (v_isShared_287_ == 0)
{
lean_ctor_set(v___x_286_, 1, v_a_281_);
lean_ctor_set(v___x_286_, 0, v___x_291_);
v___x_293_ = v___x_286_;
goto v_reusejp_292_;
}
else
{
lean_object* v_reuseFailAlloc_295_; 
v_reuseFailAlloc_295_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_295_, 0, v___x_291_);
lean_ctor_set(v_reuseFailAlloc_295_, 1, v_a_281_);
v___x_293_ = v_reuseFailAlloc_295_;
goto v_reusejp_292_;
}
v_reusejp_292_:
{
v_a_280_ = v_tail_284_;
v_a_281_ = v___x_293_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_naturals_spec__0_spec__0___boxed(lean_object* v_record_297_, lean_object* v_a_298_, lean_object* v_a_299_){
_start:
{
lean_object* v_res_300_; 
v_res_300_ = lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_naturals_spec__0_spec__0(v_record_297_, v_a_298_, v_a_299_);
lean_dec_ref(v_record_297_);
return v_res_300_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_naturals_spec__0(lean_object* v_record_301_, lean_object* v_a_302_, lean_object* v_a_303_){
_start:
{
if (lean_obj_tag(v_a_302_) == 0)
{
lean_object* v___x_304_; 
v___x_304_ = l_List_reverse___redArg(v_a_303_);
return v___x_304_;
}
else
{
lean_object* v_head_305_; lean_object* v_tail_306_; lean_object* v___x_308_; uint8_t v_isShared_309_; uint8_t v_isSharedCheck_318_; 
v_head_305_ = lean_ctor_get(v_a_302_, 0);
v_tail_306_ = lean_ctor_get(v_a_302_, 1);
v_isSharedCheck_318_ = !lean_is_exclusive(v_a_302_);
if (v_isSharedCheck_318_ == 0)
{
v___x_308_ = v_a_302_;
v_isShared_309_ = v_isSharedCheck_318_;
goto v_resetjp_307_;
}
else
{
lean_inc(v_tail_306_);
lean_inc(v_head_305_);
lean_dec(v_a_302_);
v___x_308_ = lean_box(0);
v_isShared_309_ = v_isSharedCheck_318_;
goto v_resetjp_307_;
}
v_resetjp_307_:
{
lean_object* v___x_310_; lean_object* v___x_311_; lean_object* v___x_312_; lean_object* v___x_313_; lean_object* v___x_315_; 
v___x_310_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_301_, v_head_305_);
v___x_311_ = lean_nat_to_int(v___x_310_);
v___x_312_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_311_);
v___x_313_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_313_, 0, v_head_305_);
lean_ctor_set(v___x_313_, 1, v___x_312_);
if (v_isShared_309_ == 0)
{
lean_ctor_set(v___x_308_, 1, v_a_303_);
lean_ctor_set(v___x_308_, 0, v___x_313_);
v___x_315_ = v___x_308_;
goto v_reusejp_314_;
}
else
{
lean_object* v_reuseFailAlloc_317_; 
v_reuseFailAlloc_317_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_317_, 0, v___x_313_);
lean_ctor_set(v_reuseFailAlloc_317_, 1, v_a_303_);
v___x_315_ = v_reuseFailAlloc_317_;
goto v_reusejp_314_;
}
v_reusejp_314_:
{
lean_object* v___x_316_; 
v___x_316_ = lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_naturals_spec__0_spec__0(v_record_301_, v_tail_306_, v___x_315_);
return v___x_316_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_naturals_spec__0___boxed(lean_object* v_record_319_, lean_object* v_a_320_, lean_object* v_a_321_){
_start:
{
lean_object* v_res_322_; 
v_res_322_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_naturals_spec__0(v_record_319_, v_a_320_, v_a_321_);
lean_dec_ref(v_record_319_);
return v_res_322_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_naturals(lean_object* v_record_323_, lean_object* v_keys_324_){
_start:
{
lean_object* v___x_325_; lean_object* v___x_326_; 
v___x_325_ = lean_box(0);
v___x_326_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_naturals_spec__0(v_record_323_, v_keys_324_, v___x_325_);
return v___x_326_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_naturals___boxed(lean_object* v_record_327_, lean_object* v_keys_328_){
_start:
{
lean_object* v_res_329_; 
v_res_329_ = lp_lean1090_Lean1090_Impl_JSON_naturals(v_record_327_, v_keys_328_);
lean_dec_ref(v_record_327_);
return v_res_329_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_booleans_spec__0(lean_object* v_record_330_, lean_object* v_a_331_, lean_object* v_a_332_){
_start:
{
if (lean_obj_tag(v_a_331_) == 0)
{
lean_object* v___x_333_; 
v___x_333_ = l_List_reverse___redArg(v_a_332_);
return v___x_333_;
}
else
{
lean_object* v_head_334_; lean_object* v_tail_335_; lean_object* v___x_337_; uint8_t v_isShared_338_; uint8_t v_isSharedCheck_352_; 
v_head_334_ = lean_ctor_get(v_a_331_, 0);
v_tail_335_ = lean_ctor_get(v_a_331_, 1);
v_isSharedCheck_352_ = !lean_is_exclusive(v_a_331_);
if (v_isSharedCheck_352_ == 0)
{
v___x_337_ = v_a_331_;
v_isShared_338_ = v_isSharedCheck_352_;
goto v_resetjp_336_;
}
else
{
lean_inc(v_tail_335_);
lean_inc(v_head_334_);
lean_dec(v_a_331_);
v___x_337_ = lean_box(0);
v_isShared_338_ = v_isSharedCheck_352_;
goto v_resetjp_336_;
}
v_resetjp_336_:
{
uint8_t v___y_340_; lean_object* v___x_347_; lean_object* v___x_348_; uint8_t v___x_349_; 
v___x_347_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_330_, v_head_334_);
v___x_348_ = lean_unsigned_to_nat(0u);
v___x_349_ = lean_nat_dec_eq(v___x_347_, v___x_348_);
lean_dec(v___x_347_);
if (v___x_349_ == 0)
{
uint8_t v___x_350_; 
v___x_350_ = 1;
v___y_340_ = v___x_350_;
goto v___jp_339_;
}
else
{
uint8_t v___x_351_; 
v___x_351_ = 0;
v___y_340_ = v___x_351_;
goto v___jp_339_;
}
v___jp_339_:
{
lean_object* v___x_341_; lean_object* v___x_342_; lean_object* v___x_344_; 
v___x_341_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_341_, 0, v___y_340_);
v___x_342_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_342_, 0, v_head_334_);
lean_ctor_set(v___x_342_, 1, v___x_341_);
if (v_isShared_338_ == 0)
{
lean_ctor_set(v___x_337_, 1, v_a_332_);
lean_ctor_set(v___x_337_, 0, v___x_342_);
v___x_344_ = v___x_337_;
goto v_reusejp_343_;
}
else
{
lean_object* v_reuseFailAlloc_346_; 
v_reuseFailAlloc_346_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_346_, 0, v___x_342_);
lean_ctor_set(v_reuseFailAlloc_346_, 1, v_a_332_);
v___x_344_ = v_reuseFailAlloc_346_;
goto v_reusejp_343_;
}
v_reusejp_343_:
{
v_a_331_ = v_tail_335_;
v_a_332_ = v___x_344_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_booleans_spec__0___boxed(lean_object* v_record_353_, lean_object* v_a_354_, lean_object* v_a_355_){
_start:
{
lean_object* v_res_356_; 
v_res_356_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_booleans_spec__0(v_record_353_, v_a_354_, v_a_355_);
lean_dec_ref(v_record_353_);
return v_res_356_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_booleans(lean_object* v_record_357_, lean_object* v_keys_358_){
_start:
{
lean_object* v___x_359_; lean_object* v___x_360_; 
v___x_359_ = lean_box(0);
v___x_360_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_booleans_spec__0(v_record_357_, v_keys_358_, v___x_359_);
return v___x_360_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_booleans___boxed(lean_object* v_record_361_, lean_object* v_keys_362_){
_start:
{
lean_object* v_res_363_; 
v_res_363_ = lp_lean1090_Lean1090_Impl_JSON_booleans(v_record_361_, v_keys_362_);
lean_dec_ref(v_record_361_);
return v_res_363_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_parity(lean_object* v_record_367_){
_start:
{
lean_object* v___x_368_; lean_object* v___y_370_; lean_object* v___x_375_; lean_object* v___x_376_; uint8_t v___x_377_; 
v___x_368_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_parity___closed__0));
v___x_375_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_367_, v___x_368_);
v___x_376_ = lean_unsigned_to_nat(0u);
v___x_377_ = lean_nat_dec_eq(v___x_375_, v___x_376_);
lean_dec(v___x_375_);
if (v___x_377_ == 0)
{
lean_object* v___x_378_; 
v___x_378_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_parity___closed__1));
v___y_370_ = v___x_378_;
goto v___jp_369_;
}
else
{
lean_object* v___x_379_; 
v___x_379_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_parity___closed__2));
v___y_370_ = v___x_379_;
goto v___jp_369_;
}
v___jp_369_:
{
lean_object* v___x_371_; lean_object* v___x_372_; lean_object* v___x_373_; lean_object* v___x_374_; 
lean_inc_ref(v___y_370_);
v___x_371_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_371_, 0, v___y_370_);
v___x_372_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_372_, 0, v___x_368_);
lean_ctor_set(v___x_372_, 1, v___x_371_);
v___x_373_ = lean_box(0);
v___x_374_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_374_, 0, v___x_372_);
lean_ctor_set(v___x_374_, 1, v___x_373_);
return v___x_374_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_parity___boxed(lean_object* v_record_380_){
_start:
{
lean_object* v_res_381_; 
v_res_381_ = lp_lean1090_Lean1090_Impl_JSON_parity(v_record_380_);
lean_dec_ref(v_record_380_);
return v_res_381_;
}
}
static lean_object* _init_lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0(void){
_start:
{
lean_object* v___x_382_; lean_object* v___x_383_; 
v___x_382_ = lean_unsigned_to_nat(256u);
v___x_383_ = lean_nat_to_int(v___x_382_);
return v___x_383_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0(lean_object* v_data_384_, lean_object* v_a_385_, lean_object* v_a_386_){
_start:
{
if (lean_obj_tag(v_a_385_) == 0)
{
lean_object* v___x_387_; 
lean_dec(v_data_384_);
v___x_387_ = l_List_reverse___redArg(v_a_386_);
return v___x_387_;
}
else
{
lean_object* v_head_388_; lean_object* v_tail_389_; lean_object* v___x_391_; uint8_t v_isShared_392_; uint8_t v_isSharedCheck_405_; 
v_head_388_ = lean_ctor_get(v_a_385_, 0);
v_tail_389_ = lean_ctor_get(v_a_385_, 1);
v_isSharedCheck_405_ = !lean_is_exclusive(v_a_385_);
if (v_isSharedCheck_405_ == 0)
{
v___x_391_ = v_a_385_;
v_isShared_392_ = v_isSharedCheck_405_;
goto v_resetjp_390_;
}
else
{
lean_inc(v_tail_389_);
lean_inc(v_head_388_);
lean_dec(v_a_385_);
v___x_391_ = lean_box(0);
v_isShared_392_ = v_isSharedCheck_405_;
goto v_resetjp_390_;
}
v_resetjp_390_:
{
lean_object* v___x_393_; lean_object* v___x_394_; lean_object* v___x_395_; lean_object* v___x_396_; lean_object* v___x_397_; lean_object* v___x_398_; lean_object* v___x_399_; lean_object* v___x_400_; lean_object* v___x_402_; 
lean_inc(v_data_384_);
v___x_393_ = lean_nat_to_int(v_data_384_);
v___x_394_ = lean_obj_once(&lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0, &lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0_once, _init_lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0);
v___x_395_ = lean_unsigned_to_nat(4u);
v___x_396_ = lean_nat_sub(v___x_395_, v_head_388_);
lean_dec(v_head_388_);
v___x_397_ = l_Int_pow(v___x_394_, v___x_396_);
lean_dec(v___x_396_);
v___x_398_ = lean_int_ediv(v___x_393_, v___x_397_);
lean_dec(v___x_397_);
lean_dec(v___x_393_);
v___x_399_ = lean_int_emod(v___x_398_, v___x_394_);
lean_dec(v___x_398_);
v___x_400_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_399_);
if (v_isShared_392_ == 0)
{
lean_ctor_set(v___x_391_, 1, v_a_386_);
lean_ctor_set(v___x_391_, 0, v___x_400_);
v___x_402_ = v___x_391_;
goto v_reusejp_401_;
}
else
{
lean_object* v_reuseFailAlloc_404_; 
v_reuseFailAlloc_404_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_404_, 0, v___x_400_);
lean_ctor_set(v_reuseFailAlloc_404_, 1, v_a_386_);
v___x_402_ = v_reuseFailAlloc_404_;
goto v_reusejp_401_;
}
v_reusejp_401_:
{
v_a_385_ = v_tail_389_;
v_a_386_ = v___x_402_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0(lean_object* v_data_406_, lean_object* v_a_407_, lean_object* v_a_408_){
_start:
{
if (lean_obj_tag(v_a_407_) == 0)
{
lean_object* v___x_409_; 
lean_dec(v_data_406_);
v___x_409_ = l_List_reverse___redArg(v_a_408_);
return v___x_409_;
}
else
{
lean_object* v_head_410_; lean_object* v_tail_411_; lean_object* v___x_413_; uint8_t v_isShared_414_; uint8_t v_isSharedCheck_427_; 
v_head_410_ = lean_ctor_get(v_a_407_, 0);
v_tail_411_ = lean_ctor_get(v_a_407_, 1);
v_isSharedCheck_427_ = !lean_is_exclusive(v_a_407_);
if (v_isSharedCheck_427_ == 0)
{
v___x_413_ = v_a_407_;
v_isShared_414_ = v_isSharedCheck_427_;
goto v_resetjp_412_;
}
else
{
lean_inc(v_tail_411_);
lean_inc(v_head_410_);
lean_dec(v_a_407_);
v___x_413_ = lean_box(0);
v_isShared_414_ = v_isSharedCheck_427_;
goto v_resetjp_412_;
}
v_resetjp_412_:
{
lean_object* v___x_415_; lean_object* v___x_416_; lean_object* v___x_417_; lean_object* v___x_418_; lean_object* v___x_419_; lean_object* v___x_420_; lean_object* v___x_421_; lean_object* v___x_422_; lean_object* v___x_424_; 
lean_inc(v_data_406_);
v___x_415_ = lean_nat_to_int(v_data_406_);
v___x_416_ = lean_obj_once(&lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0, &lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0_once, _init_lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0);
v___x_417_ = lean_unsigned_to_nat(4u);
v___x_418_ = lean_nat_sub(v___x_417_, v_head_410_);
lean_dec(v_head_410_);
v___x_419_ = l_Int_pow(v___x_416_, v___x_418_);
lean_dec(v___x_418_);
v___x_420_ = lean_int_ediv(v___x_415_, v___x_419_);
lean_dec(v___x_419_);
lean_dec(v___x_415_);
v___x_421_ = lean_int_emod(v___x_420_, v___x_416_);
lean_dec(v___x_420_);
v___x_422_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_421_);
if (v_isShared_414_ == 0)
{
lean_ctor_set(v___x_413_, 1, v_a_408_);
lean_ctor_set(v___x_413_, 0, v___x_422_);
v___x_424_ = v___x_413_;
goto v_reusejp_423_;
}
else
{
lean_object* v_reuseFailAlloc_426_; 
v_reuseFailAlloc_426_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_426_, 0, v___x_422_);
lean_ctor_set(v_reuseFailAlloc_426_, 1, v_a_408_);
v___x_424_ = v_reuseFailAlloc_426_;
goto v_reusejp_423_;
}
v_reusejp_423_:
{
lean_object* v___x_425_; 
v___x_425_ = lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0(v_data_406_, v_tail_411_, v___x_424_);
return v___x_425_;
}
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__17(void){
_start:
{
lean_object* v___x_447_; lean_object* v___x_448_; 
v___x_447_ = lean_unsigned_to_nat(5u);
v___x_448_ = l_List_range(v___x_447_);
return v___x_448_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus(lean_object* v_record_449_){
_start:
{
lean_object* v___x_450_; lean_object* v_subtype_451_; lean_object* v___x_452_; uint8_t v___x_453_; 
v___x_450_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__0));
v_subtype_451_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_449_, v___x_450_);
v___x_452_ = lean_unsigned_to_nat(2u);
v___x_453_ = lean_nat_dec_le(v___x_452_, v_subtype_451_);
if (v___x_453_ == 0)
{
lean_object* v___x_454_; lean_object* v_version_455_; lean_object* v___x_456_; lean_object* v___x_457_; lean_object* v___x_458_; lean_object* v___x_459_; lean_object* v___x_460_; lean_object* v___y_462_; lean_object* v___y_463_; lean_object* v___y_468_; lean_object* v___y_469_; lean_object* v___y_470_; lean_object* v___y_471_; uint8_t v___y_481_; lean_object* v___y_482_; lean_object* v___y_483_; lean_object* v___y_484_; uint8_t v___y_490_; lean_object* v___y_491_; lean_object* v___y_492_; lean_object* v___y_493_; lean_object* v___x_495_; uint8_t v___x_496_; lean_object* v___y_498_; 
v___x_454_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__1));
v_version_455_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_449_, v___x_454_);
lean_inc(v_version_455_);
v___x_456_ = lean_nat_to_int(v_version_455_);
v___x_457_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_456_);
v___x_458_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_458_, 0, v___x_454_);
lean_ctor_set(v___x_458_, 1, v___x_457_);
v___x_459_ = lean_box(0);
v___x_460_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_460_, 0, v___x_458_);
lean_ctor_set(v___x_460_, 1, v___x_459_);
v___x_495_ = lean_unsigned_to_nat(1u);
v___x_496_ = lean_nat_dec_eq(v_version_455_, v___x_495_);
if (v___x_496_ == 0)
{
uint8_t v___x_507_; 
v___x_507_ = lean_nat_dec_eq(v_version_455_, v___x_452_);
if (v___x_507_ == 0)
{
lean_object* v___x_508_; 
lean_dec(v_version_455_);
lean_dec(v_subtype_451_);
v___x_508_ = l_List_appendTR___redArg(v___x_460_, v___x_459_);
return v___x_508_;
}
else
{
goto v___jp_504_;
}
}
else
{
goto v___jp_504_;
}
v___jp_461_:
{
lean_object* v___x_464_; lean_object* v___x_465_; lean_object* v___x_466_; 
v___x_464_ = l_List_appendTR___redArg(v___y_462_, v___y_463_);
v___x_465_ = lp_lean1090_Lean1090_Impl_JSON_naturals(v_record_449_, v___x_464_);
v___x_466_ = l_List_appendTR___redArg(v___x_460_, v___x_465_);
return v___x_466_;
}
v___jp_467_:
{
lean_object* v___x_472_; lean_object* v___x_473_; lean_object* v___x_474_; lean_object* v___x_475_; lean_object* v___x_476_; uint8_t v___x_477_; 
v___x_472_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__2));
lean_inc(v___y_468_);
v___x_473_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_473_, 0, v___x_472_);
lean_ctor_set(v___x_473_, 1, v___y_468_);
lean_inc_ref(v___y_471_);
v___x_474_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_474_, 0, v___y_471_);
lean_ctor_set(v___x_474_, 1, v___x_473_);
lean_inc_ref(v___y_470_);
v___x_475_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_475_, 0, v___y_470_);
lean_ctor_set(v___x_475_, 1, v___x_474_);
v___x_476_ = l_List_appendTR___redArg(v___y_469_, v___x_475_);
v___x_477_ = lean_nat_dec_eq(v_version_455_, v___x_452_);
lean_dec(v_version_455_);
if (v___x_477_ == 0)
{
v___y_462_ = v___x_476_;
v___y_463_ = v___y_468_;
goto v___jp_461_;
}
else
{
lean_object* v___x_478_; lean_object* v___x_479_; 
v___x_478_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__3));
v___x_479_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_479_, 0, v___x_478_);
lean_ctor_set(v___x_479_, 1, v___y_468_);
v___y_462_ = v___x_476_;
v___y_463_ = v___x_479_;
goto v___jp_461_;
}
}
v___jp_480_:
{
lean_object* v___x_485_; lean_object* v___x_486_; 
v___x_485_ = l_List_appendTR___redArg(v___y_483_, v___y_484_);
v___x_486_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__4));
if (v___y_481_ == 0)
{
lean_object* v___x_487_; 
v___x_487_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__5));
v___y_468_ = v___y_482_;
v___y_469_ = v___x_485_;
v___y_470_ = v___x_486_;
v___y_471_ = v___x_487_;
goto v___jp_467_;
}
else
{
lean_object* v___x_488_; 
v___x_488_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__6));
v___y_468_ = v___y_482_;
v___y_469_ = v___x_485_;
v___y_470_ = v___x_486_;
v___y_471_ = v___x_488_;
goto v___jp_467_;
}
}
v___jp_489_:
{
lean_object* v___x_494_; 
lean_inc(v___y_491_);
lean_inc_ref(v___y_493_);
v___x_494_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_494_, 0, v___y_493_);
lean_ctor_set(v___x_494_, 1, v___y_491_);
v___y_481_ = v___y_490_;
v___y_482_ = v___y_491_;
v___y_483_ = v___y_492_;
v___y_484_ = v___x_494_;
goto v___jp_480_;
}
v___jp_497_:
{
lean_object* v___x_499_; lean_object* v___x_500_; uint8_t v___x_501_; 
v___x_499_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__8));
lean_inc_ref(v___y_498_);
v___x_500_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_500_, 0, v___y_498_);
lean_ctor_set(v___x_500_, 1, v___x_499_);
v___x_501_ = lean_nat_dec_eq(v_subtype_451_, v___x_495_);
lean_dec(v_subtype_451_);
if (v___x_501_ == 0)
{
if (v___x_496_ == 0)
{
lean_object* v___x_502_; 
v___x_502_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__9));
v___y_490_ = v___x_501_;
v___y_491_ = v___x_459_;
v___y_492_ = v___x_500_;
v___y_493_ = v___x_502_;
goto v___jp_489_;
}
else
{
lean_object* v___x_503_; 
v___x_503_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__10));
v___y_490_ = v___x_501_;
v___y_491_ = v___x_459_;
v___y_492_ = v___x_500_;
v___y_493_ = v___x_503_;
goto v___jp_489_;
}
}
else
{
v___y_481_ = v___x_501_;
v___y_482_ = v___x_459_;
v___y_483_ = v___x_500_;
v___y_484_ = v___x_459_;
goto v___jp_480_;
}
}
v___jp_504_:
{
if (v___x_496_ == 0)
{
lean_object* v___x_505_; 
v___x_505_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__11));
v___y_498_ = v___x_505_;
goto v___jp_497_;
}
else
{
lean_object* v___x_506_; 
v___x_506_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__12));
v___y_498_ = v___x_506_;
goto v___jp_497_;
}
}
}
else
{
lean_object* v___x_509_; lean_object* v_data_510_; lean_object* v___x_511_; lean_object* v___x_512_; lean_object* v___x_513_; lean_object* v___x_514_; lean_object* v___x_515_; lean_object* v___x_516_; lean_object* v___x_517_; lean_object* v___x_518_; lean_object* v___x_519_; lean_object* v___x_520_; lean_object* v___x_521_; lean_object* v___x_522_; lean_object* v___x_523_; lean_object* v___x_524_; lean_object* v___x_525_; lean_object* v___x_526_; lean_object* v___x_527_; 
v___x_509_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__13));
v_data_510_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_449_, v___x_509_);
v___x_511_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__14));
v___x_512_ = lean_nat_to_int(v_subtype_451_);
v___x_513_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_512_);
v___x_514_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_514_, 0, v___x_511_);
lean_ctor_set(v___x_514_, 1, v___x_513_);
v___x_515_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__15));
v___x_516_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__16));
v___x_517_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__17, &lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__17_once, _init_lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__17);
v___x_518_ = lean_box(0);
v___x_519_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0(v_data_510_, v___x_517_, v___x_518_);
v___x_520_ = lean_array_mk(v___x_519_);
v___x_521_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_521_, 0, v___x_520_);
v___x_522_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_522_, 0, v___x_516_);
lean_ctor_set(v___x_522_, 1, v___x_521_);
v___x_523_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_523_, 0, v___x_522_);
lean_ctor_set(v___x_523_, 1, v___x_518_);
v___x_524_ = l_Lean_Json_mkObj(v___x_523_);
lean_dec_ref_known(v___x_523_, 2);
v___x_525_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_525_, 0, v___x_515_);
lean_ctor_set(v___x_525_, 1, v___x_524_);
v___x_526_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_526_, 0, v___x_525_);
lean_ctor_set(v___x_526_, 1, v___x_518_);
v___x_527_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_527_, 0, v___x_514_);
lean_ctor_set(v___x_527_, 1, v___x_526_);
return v___x_527_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_operationStatus___boxed(lean_object* v_record_528_){
_start:
{
lean_object* v_res_529_; 
v_res_529_ = lp_lean1090_Lean1090_Impl_JSON_operationStatus(v_record_528_);
lean_dec_ref(v_record_528_);
return v_res_529_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb(uint8_t v_oracle_682_, lean_object* v_record_683_, lean_object* v_p_684_){
_start:
{
lean_object* v___y_686_; lean_object* v___y_687_; uint8_t v___y_688_; lean_object* v___y_689_; lean_object* v___x_692_; lean_object* v_tc_693_; lean_object* v___x_703_; uint8_t v___x_704_; 
v___x_692_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__0));
v_tc_693_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_683_, v___x_692_);
v___x_703_ = lean_unsigned_to_nat(0u);
v___x_704_ = lean_nat_dec_eq(v_tc_693_, v___x_703_);
if (v___x_704_ == 0)
{
lean_object* v___x_705_; uint8_t v___x_706_; 
v___x_705_ = lean_unsigned_to_nat(4u);
v___x_706_ = lean_nat_dec_le(v_tc_693_, v___x_705_);
if (v___x_706_ == 0)
{
lean_object* v___x_707_; uint8_t v___x_708_; lean_object* v___y_710_; lean_object* v___y_711_; lean_object* v___y_727_; 
v___x_707_ = lean_unsigned_to_nat(8u);
v___x_708_ = lean_nat_dec_le(v_tc_693_, v___x_707_);
if (v___x_708_ == 0)
{
uint8_t v___x_729_; uint8_t v___y_731_; lean_object* v___y_749_; uint8_t v___y_750_; lean_object* v___y_751_; lean_object* v___y_763_; uint8_t v___y_764_; lean_object* v___y_767_; lean_object* v___y_768_; uint8_t v___y_769_; lean_object* v___y_770_; lean_object* v___y_771_; lean_object* v___y_775_; uint8_t v___y_776_; lean_object* v___x_784_; uint8_t v___x_785_; 
v___x_729_ = 1;
v___x_784_ = lean_unsigned_to_nat(18u);
v___x_785_ = lean_nat_dec_le(v_tc_693_, v___x_784_);
if (v___x_785_ == 0)
{
lean_object* v___x_786_; lean_object* v_st_787_; uint8_t v___y_789_; lean_object* v___x_875_; uint8_t v___x_876_; 
v___x_786_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__0));
v_st_787_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_683_, v___x_786_);
v___x_875_ = lean_unsigned_to_nat(20u);
v___x_876_ = lean_nat_dec_le(v___x_875_, v_tc_693_);
if (v___x_876_ == 0)
{
v___y_789_ = v___x_708_;
goto v___jp_788_;
}
else
{
lean_object* v___x_877_; uint8_t v___x_878_; 
v___x_877_ = lean_unsigned_to_nat(22u);
v___x_878_ = lean_nat_dec_le(v_tc_693_, v___x_877_);
if (v___x_878_ == 0)
{
v___y_789_ = v___x_878_;
goto v___jp_788_;
}
else
{
lean_dec(v_st_787_);
v___y_731_ = v___x_878_;
goto v___jp_730_;
}
}
v___jp_788_:
{
lean_object* v___x_790_; uint8_t v___x_791_; 
v___x_790_ = lean_unsigned_to_nat(19u);
v___x_791_ = lean_nat_dec_eq(v_tc_693_, v___x_790_);
if (v___x_791_ == 0)
{
lean_object* v___x_792_; uint8_t v___x_793_; 
lean_dec(v_st_787_);
v___x_792_ = lean_unsigned_to_nat(28u);
v___x_793_ = lean_nat_dec_eq(v_tc_693_, v___x_792_);
if (v___x_793_ == 0)
{
lean_object* v___x_794_; uint8_t v___x_795_; 
v___x_794_ = lean_unsigned_to_nat(29u);
v___x_795_ = lean_nat_dec_eq(v_tc_693_, v___x_794_);
if (v___x_795_ == 0)
{
lean_object* v___x_796_; uint8_t v___x_797_; 
lean_dec_ref(v_p_684_);
v___x_796_ = lean_unsigned_to_nat(31u);
v___x_797_ = lean_nat_dec_eq(v_tc_693_, v___x_796_);
if (v___x_797_ == 0)
{
lean_object* v___x_798_; uint8_t v___x_799_; 
v___x_798_ = lean_unsigned_to_nat(25u);
v___x_799_ = lean_nat_dec_le(v___x_798_, v_tc_693_);
if (v___x_799_ == 0)
{
goto v___jp_694_;
}
else
{
lean_object* v___x_800_; uint8_t v___x_801_; 
v___x_800_ = lean_unsigned_to_nat(27u);
v___x_801_ = lean_nat_dec_le(v_tc_693_, v___x_800_);
if (v___x_801_ == 0)
{
goto v___jp_694_;
}
else
{
lean_object* v___x_802_; lean_object* v___x_803_; lean_object* v___x_804_; lean_object* v___x_805_; lean_object* v___x_806_; lean_object* v___x_807_; lean_object* v___x_808_; lean_object* v___x_809_; lean_object* v___x_810_; lean_object* v___x_811_; lean_object* v___x_812_; 
v___x_802_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__26));
v___x_803_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__27));
v___x_804_ = lean_nat_to_int(v_tc_693_);
v___x_805_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_804_);
v___x_806_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_806_, 0, v___x_803_);
lean_ctor_set(v___x_806_, 1, v___x_805_);
v___x_807_ = lean_box(0);
v___x_808_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_808_, 0, v___x_806_);
lean_ctor_set(v___x_808_, 1, v___x_807_);
v___x_809_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_809_, 0, v___x_802_);
lean_ctor_set(v___x_809_, 1, v___x_808_);
v___x_810_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__29));
v___x_811_ = lp_lean1090_Lean1090_Impl_JSON_naturals(v_record_683_, v___x_810_);
v___x_812_ = l_List_appendTR___redArg(v___x_809_, v___x_811_);
return v___x_812_;
}
}
}
else
{
lean_object* v___x_813_; lean_object* v___x_814_; lean_object* v___x_815_; 
lean_dec(v_tc_693_);
v___x_813_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__33));
v___x_814_ = lp_lean1090_Lean1090_Impl_JSON_operationStatus(v_record_683_);
v___x_815_ = l_List_appendTR___redArg(v___x_813_, v___x_814_);
return v___x_815_;
}
}
else
{
lean_object* v___x_816_; lean_object* v___x_817_; lean_object* v___x_818_; lean_object* v___x_819_; lean_object* v___x_820_; lean_object* v___x_821_; lean_object* v___x_822_; lean_object* v___x_823_; lean_object* v___x_824_; lean_object* v___x_825_; lean_object* v___x_826_; lean_object* v___x_827_; lean_object* v___x_828_; lean_object* v___x_829_; lean_object* v___x_830_; lean_object* v___x_831_; lean_object* v___x_832_; lean_object* v___x_833_; uint8_t v___x_834_; 
lean_dec(v_tc_693_);
v___x_816_ = lean_box(0);
v___x_817_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__37));
v___x_818_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__3));
v___x_819_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_682_, v_p_684_, v___x_818_, v___x_818_, v___x_793_);
v___x_820_ = l_List_appendTR___redArg(v___x_817_, v___x_819_);
v___x_821_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__38));
v___x_822_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_682_, v_p_684_, v___x_821_, v___x_821_, v___x_729_);
v___x_823_ = l_List_appendTR___redArg(v___x_820_, v___x_822_);
v___x_824_ = lp_lean1090_Lean1090_Impl_JSON_numeric(v_oracle_682_, v_p_684_);
v___x_825_ = l_List_appendTR___redArg(v___x_823_, v___x_824_);
v___x_826_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__8));
v___x_827_ = lp_lean1090_Lean1090_Impl_JSON_naturals(v_record_683_, v___x_826_);
v___x_828_ = l_List_appendTR___redArg(v___x_825_, v___x_827_);
v___x_829_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__42));
v___x_830_ = lp_lean1090_Lean1090_Impl_JSON_booleans(v_record_683_, v___x_829_);
v___x_831_ = l_List_appendTR___redArg(v___x_828_, v___x_830_);
v___x_832_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__43));
v___x_833_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_683_, v___x_832_);
v___x_834_ = lean_nat_dec_eq(v___x_833_, v___x_703_);
lean_dec(v___x_833_);
if (v___x_834_ == 0)
{
lean_object* v___x_835_; lean_object* v___x_836_; lean_object* v___x_837_; 
v___x_835_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__53));
v___x_836_ = lp_lean1090_Lean1090_Impl_JSON_booleans(v_record_683_, v___x_835_);
v___x_837_ = l_List_appendTR___redArg(v___x_831_, v___x_836_);
return v___x_837_;
}
else
{
lean_object* v___x_838_; 
v___x_838_ = l_List_appendTR___redArg(v___x_831_, v___x_816_);
return v___x_838_;
}
}
}
else
{
lean_object* v___x_839_; lean_object* v___x_840_; lean_object* v___x_841_; lean_object* v___x_842_; lean_object* v___x_843_; lean_object* v___x_844_; lean_object* v___x_845_; lean_object* v___x_846_; 
lean_dec(v_tc_693_);
v___x_839_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__57));
v___x_840_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_682_, v_p_684_, v___x_786_, v___x_786_, v___x_791_);
v___x_841_ = l_List_appendTR___redArg(v___x_839_, v___x_840_);
v___x_842_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__58));
v___x_843_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_682_, v_p_684_, v___x_842_, v___x_842_, v___x_791_);
v___x_844_ = l_List_appendTR___redArg(v___x_841_, v___x_843_);
v___x_845_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__59));
v___x_846_ = lp_lean1090_Lean1090_Impl_JSON_value(v_oracle_682_, v_p_684_, v___x_845_);
lean_dec_ref(v_p_684_);
if (lean_obj_tag(v___x_846_) == 0)
{
lean_object* v___x_847_; 
v___x_847_ = lean_box(0);
v___y_686_ = v___x_844_;
v___y_687_ = v___x_845_;
v___y_688_ = v___x_791_;
v___y_689_ = v___x_847_;
goto v___jp_685_;
}
else
{
lean_object* v_val_848_; lean_object* v___x_850_; uint8_t v_isShared_851_; uint8_t v_isSharedCheck_859_; 
v_val_848_ = lean_ctor_get(v___x_846_, 0);
v_isSharedCheck_859_ = !lean_is_exclusive(v___x_846_);
if (v_isSharedCheck_859_ == 0)
{
v___x_850_ = v___x_846_;
v_isShared_851_ = v_isSharedCheck_859_;
goto v_resetjp_849_;
}
else
{
lean_inc(v_val_848_);
lean_dec(v___x_846_);
v___x_850_ = lean_box(0);
v_isShared_851_ = v_isSharedCheck_859_;
goto v_resetjp_849_;
}
v_resetjp_849_:
{
lean_object* v_num_852_; lean_object* v___x_853_; lean_object* v___x_854_; lean_object* v___x_855_; lean_object* v___x_857_; 
v_num_852_ = lean_ctor_get(v_val_848_, 0);
lean_inc(v_num_852_);
lean_dec(v_val_848_);
v___x_853_ = l_Int_toNat(v_num_852_);
lean_dec(v_num_852_);
v___x_854_ = lp_lean1090_Lean1090_Impl_JSON_digits(v___x_707_, v___x_705_, v___x_853_);
lean_dec(v___x_853_);
v___x_855_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_855_, 0, v___x_854_);
if (v_isShared_851_ == 0)
{
lean_ctor_set(v___x_850_, 0, v___x_855_);
v___x_857_ = v___x_850_;
goto v_reusejp_856_;
}
else
{
lean_object* v_reuseFailAlloc_858_; 
v_reuseFailAlloc_858_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_858_, 0, v___x_855_);
v___x_857_ = v_reuseFailAlloc_858_;
goto v_reusejp_856_;
}
v_reusejp_856_:
{
v___y_686_ = v___x_844_;
v___y_687_ = v___x_845_;
v___y_688_ = v___x_791_;
v___y_689_ = v___x_857_;
goto v___jp_685_;
}
}
}
}
}
else
{
lean_object* v___x_860_; lean_object* v___x_861_; lean_object* v___x_862_; lean_object* v___x_863_; lean_object* v___x_864_; uint8_t v___x_865_; 
lean_dec(v_tc_693_);
v___x_860_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__63));
v___x_861_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__65));
v___x_862_ = lp_lean1090_Lean1090_Impl_JSON_naturals(v_record_683_, v___x_861_);
v___x_863_ = l_List_appendTR___redArg(v___x_860_, v___x_862_);
v___x_864_ = lean_unsigned_to_nat(1u);
v___x_865_ = lean_nat_dec_eq(v_st_787_, v___x_864_);
if (v___x_865_ == 0)
{
lean_object* v___x_866_; uint8_t v___x_867_; 
v___x_866_ = lean_unsigned_to_nat(2u);
v___x_867_ = lean_nat_dec_eq(v_st_787_, v___x_866_);
if (v___x_867_ == 0)
{
lean_object* v___x_868_; uint8_t v___x_869_; 
v___x_868_ = lean_unsigned_to_nat(3u);
v___x_869_ = lean_nat_dec_eq(v_st_787_, v___x_868_);
if (v___x_869_ == 0)
{
uint8_t v___x_870_; 
v___x_870_ = lean_nat_dec_eq(v_st_787_, v___x_705_);
lean_dec(v_st_787_);
if (v___x_870_ == 0)
{
if (v_oracle_682_ == 0)
{
lean_object* v___x_871_; lean_object* v___x_872_; 
v___x_871_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__67));
v___x_872_ = lp_lean1090_Lean1090_Impl_JSON_naturals(v_record_683_, v___x_871_);
v___y_749_ = v___x_863_;
v___y_750_ = v___y_789_;
v___y_751_ = v___x_872_;
goto v___jp_748_;
}
else
{
lean_object* v___x_873_; lean_object* v___x_874_; 
v___x_873_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__66));
v___x_874_ = lp_lean1090_Lean1090_Impl_JSON_number(v___x_729_, v_p_684_, v___x_873_, v___x_873_, v___x_870_);
v___y_749_ = v___x_863_;
v___y_750_ = v___y_789_;
v___y_751_ = v___x_874_;
goto v___jp_748_;
}
}
else
{
v___y_775_ = v___x_863_;
v___y_776_ = v___y_789_;
goto v___jp_774_;
}
}
else
{
lean_dec(v_st_787_);
v___y_775_ = v___x_863_;
v___y_776_ = v___y_789_;
goto v___jp_774_;
}
}
else
{
lean_dec(v_st_787_);
v___y_763_ = v___x_863_;
v___y_764_ = v___y_789_;
goto v___jp_762_;
}
}
else
{
lean_dec(v_st_787_);
v___y_763_ = v___x_863_;
v___y_764_ = v___y_789_;
goto v___jp_762_;
}
}
}
}
else
{
v___y_731_ = v___x_729_;
goto v___jp_730_;
}
v___jp_730_:
{
lean_object* v___x_732_; lean_object* v___x_733_; lean_object* v___x_734_; lean_object* v___x_735_; lean_object* v___x_736_; lean_object* v___x_737_; lean_object* v___x_738_; lean_object* v___x_739_; lean_object* v___x_740_; lean_object* v___x_741_; lean_object* v___x_742_; lean_object* v___x_743_; lean_object* v___x_744_; 
v___x_732_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__13));
lean_inc(v_tc_693_);
v___x_733_ = lean_nat_to_int(v_tc_693_);
v___x_734_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_733_);
v___x_735_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_735_, 0, v___x_692_);
lean_ctor_set(v___x_735_, 1, v___x_734_);
v___x_736_ = lean_box(0);
v___x_737_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_737_, 0, v___x_735_);
lean_ctor_set(v___x_737_, 1, v___x_736_);
v___x_738_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_738_, 0, v___x_732_);
lean_ctor_set(v___x_738_, 1, v___x_737_);
v___x_739_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__14));
v___x_740_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_682_, v_p_684_, v___x_739_, v___x_739_, v___x_708_);
v___x_741_ = l_List_appendTR___redArg(v___x_738_, v___x_740_);
v___x_742_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__15));
v___x_743_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_682_, v_p_684_, v___x_742_, v___x_742_, v___x_729_);
v___x_744_ = l_List_appendTR___redArg(v___x_741_, v___x_743_);
if (v_oracle_682_ == 0)
{
if (v___y_731_ == 0)
{
lean_dec(v_tc_693_);
v___y_727_ = v___x_744_;
goto v___jp_726_;
}
else
{
lean_object* v___x_745_; uint8_t v___x_746_; 
v___x_745_ = lean_unsigned_to_nat(20u);
v___x_746_ = lean_nat_dec_le(v___x_745_, v_tc_693_);
lean_dec(v_tc_693_);
if (v___x_746_ == 0)
{
v___y_727_ = v___x_744_;
goto v___jp_726_;
}
else
{
lean_object* v___x_747_; 
v___x_747_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__16));
v___y_710_ = v___x_744_;
v___y_711_ = v___x_747_;
goto v___jp_709_;
}
}
}
else
{
lean_dec(v_tc_693_);
v___y_727_ = v___x_744_;
goto v___jp_726_;
}
}
v___jp_748_:
{
lean_object* v___x_752_; lean_object* v___x_753_; lean_object* v___x_754_; lean_object* v___x_755_; lean_object* v___x_756_; lean_object* v___x_757_; lean_object* v___x_758_; lean_object* v___x_759_; lean_object* v___x_760_; lean_object* v___x_761_; 
v___x_752_ = l_List_appendTR___redArg(v___y_749_, v___y_751_);
v___x_753_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__17));
v___x_754_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_682_, v_p_684_, v___x_753_, v___x_753_, v___y_750_);
v___x_755_ = l_List_appendTR___redArg(v___x_752_, v___x_754_);
v___x_756_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__18));
v___x_757_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_682_, v_p_684_, v___x_756_, v___x_756_, v___x_729_);
v___x_758_ = l_List_appendTR___redArg(v___x_755_, v___x_757_);
v___x_759_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__19));
v___x_760_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_682_, v_p_684_, v___x_759_, v___x_759_, v___y_750_);
lean_dec_ref(v_p_684_);
v___x_761_ = l_List_appendTR___redArg(v___x_758_, v___x_760_);
return v___x_761_;
}
v___jp_762_:
{
lean_object* v___x_765_; 
lean_inc_ref(v_p_684_);
v___x_765_ = lp_lean1090_Lean1090_Impl_JSON_numeric(v_oracle_682_, v_p_684_);
v___y_749_ = v___y_763_;
v___y_750_ = v___y_764_;
v___y_751_ = v___x_765_;
goto v___jp_748_;
}
v___jp_766_:
{
lean_object* v___x_772_; lean_object* v___x_773_; 
lean_inc_ref(v___y_771_);
v___x_772_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_682_, v_p_684_, v___y_768_, v___y_771_, v___x_729_);
v___x_773_ = l_List_appendTR___redArg(v___y_770_, v___x_772_);
v___y_749_ = v___y_767_;
v___y_750_ = v___y_769_;
v___y_751_ = v___x_773_;
goto v___jp_748_;
}
v___jp_774_:
{
lean_object* v___x_777_; lean_object* v___x_778_; lean_object* v___x_779_; lean_object* v___x_780_; uint8_t v___x_781_; 
lean_inc_ref(v_p_684_);
v___x_777_ = lp_lean1090_Lean1090_Impl_JSON_numeric(v_oracle_682_, v_p_684_);
v___x_778_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__20));
v___x_779_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__21));
v___x_780_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_683_, v___x_779_);
v___x_781_ = lean_nat_dec_eq(v___x_780_, v___x_703_);
lean_dec(v___x_780_);
if (v___x_781_ == 0)
{
lean_object* v___x_782_; 
v___x_782_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__22));
v___y_767_ = v___y_775_;
v___y_768_ = v___x_778_;
v___y_769_ = v___y_776_;
v___y_770_ = v___x_777_;
v___y_771_ = v___x_782_;
goto v___jp_766_;
}
else
{
lean_object* v___x_783_; 
v___x_783_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__23));
v___y_767_ = v___y_775_;
v___y_768_ = v___x_778_;
v___y_769_ = v___y_776_;
v___y_770_ = v___x_777_;
v___y_771_ = v___x_783_;
goto v___jp_766_;
}
}
}
else
{
lean_object* v___x_879_; lean_object* v___x_880_; lean_object* v___x_881_; lean_object* v___x_882_; lean_object* v___x_883_; lean_object* v___x_884_; lean_object* v___x_885_; lean_object* v___x_886_; lean_object* v___x_887_; lean_object* v___x_888_; lean_object* v___x_889_; lean_object* v___x_890_; lean_object* v___x_891_; lean_object* v___x_892_; lean_object* v___x_893_; lean_object* v___x_894_; lean_object* v___x_895_; 
v___x_879_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__70));
v___x_880_ = lean_nat_to_int(v_tc_693_);
v___x_881_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_880_);
v___x_882_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_882_, 0, v___x_692_);
lean_ctor_set(v___x_882_, 1, v___x_881_);
v___x_883_ = lean_box(0);
v___x_884_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_884_, 0, v___x_882_);
lean_ctor_set(v___x_884_, 1, v___x_883_);
v___x_885_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_885_, 0, v___x_879_);
lean_ctor_set(v___x_885_, 1, v___x_884_);
v___x_886_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__14));
v___x_887_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_682_, v_p_684_, v___x_886_, v___x_886_, v___x_706_);
v___x_888_ = l_List_appendTR___redArg(v___x_885_, v___x_887_);
v___x_889_ = lp_lean1090_Lean1090_Impl_JSON_numeric(v_oracle_682_, v_p_684_);
v___x_890_ = l_List_appendTR___redArg(v___x_888_, v___x_889_);
v___x_891_ = lp_lean1090_Lean1090_Impl_JSON_parity(v_record_683_);
v___x_892_ = l_List_appendTR___redArg(v___x_890_, v___x_891_);
v___x_893_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__72));
v___x_894_ = lp_lean1090_Lean1090_Impl_JSON_naturals(v_record_683_, v___x_893_);
v___x_895_ = l_List_appendTR___redArg(v___x_892_, v___x_894_);
return v___x_895_;
}
v___jp_709_:
{
lean_object* v___x_712_; lean_object* v___x_713_; lean_object* v___x_714_; lean_object* v___x_715_; lean_object* v___x_716_; lean_object* v___x_717_; lean_object* v___x_718_; lean_object* v___x_719_; lean_object* v___x_720_; lean_object* v___x_721_; lean_object* v___x_722_; lean_object* v___x_723_; lean_object* v___x_724_; lean_object* v___x_725_; 
v___x_712_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__2));
v___x_713_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_682_, v_p_684_, v___y_711_, v___x_712_, v___x_708_);
v___x_714_ = l_List_appendTR___redArg(v___y_710_, v___x_713_);
v___x_715_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__3));
v___x_716_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_682_, v_p_684_, v___x_715_, v___x_715_, v___x_708_);
lean_dec_ref(v_p_684_);
v___x_717_ = l_List_appendTR___redArg(v___x_714_, v___x_716_);
v___x_718_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__5));
v___x_719_ = lp_lean1090_Lean1090_Impl_JSON_booleans(v_record_683_, v___x_718_);
v___x_720_ = l_List_appendTR___redArg(v___x_717_, v___x_719_);
v___x_721_ = lp_lean1090_Lean1090_Impl_JSON_parity(v_record_683_);
v___x_722_ = l_List_appendTR___redArg(v___x_720_, v___x_721_);
v___x_723_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__9));
v___x_724_ = lp_lean1090_Lean1090_Impl_JSON_naturals(v_record_683_, v___x_723_);
v___x_725_ = l_List_appendTR___redArg(v___x_722_, v___x_724_);
return v___x_725_;
}
v___jp_726_:
{
lean_object* v___x_728_; 
v___x_728_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__10));
v___y_710_ = v___y_727_;
v___y_711_ = v___x_728_;
goto v___jp_709_;
}
}
else
{
lean_object* v___x_896_; lean_object* v___x_897_; lean_object* v___x_898_; lean_object* v___x_899_; lean_object* v___x_900_; lean_object* v___x_901_; lean_object* v___x_902_; 
lean_dec(v_tc_693_);
v___x_896_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__76));
v___x_897_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__77));
v___x_898_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_682_, v_p_684_, v___x_897_, v___x_897_, v___x_704_);
v___x_899_ = l_List_appendTR___redArg(v___x_896_, v___x_898_);
v___x_900_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__78));
v___x_901_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_682_, v_p_684_, v___x_900_, v___x_900_, v___x_704_);
lean_dec_ref(v_p_684_);
v___x_902_ = l_List_appendTR___redArg(v___x_899_, v___x_901_);
return v___x_902_;
}
}
else
{
lean_object* v___x_903_; 
lean_dec(v_tc_693_);
lean_dec_ref(v_p_684_);
v___x_903_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__82));
return v___x_903_;
}
v___jp_685_:
{
lean_object* v___x_690_; lean_object* v___x_691_; 
lean_inc_ref(v___y_687_);
v___x_690_ = lp_lean1090_Lean1090_Impl_JSON_optional(v___y_687_, v___y_689_, v___y_688_);
lean_dec(v___y_689_);
v___x_691_ = l_List_appendTR___redArg(v___y_686_, v___x_690_);
return v___x_691_;
}
v___jp_694_:
{
lean_object* v___x_695_; lean_object* v___x_696_; lean_object* v___x_697_; lean_object* v___x_698_; lean_object* v___x_699_; lean_object* v___x_700_; lean_object* v___x_701_; lean_object* v___x_702_; 
v___x_695_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1));
v___x_696_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_operationStatus___closed__14));
v___x_697_ = l_Nat_reprFast(v_tc_693_);
v___x_698_ = lean_string_append(v___x_696_, v___x_697_);
lean_dec_ref(v___x_697_);
v___x_699_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_699_, 0, v___x_698_);
v___x_700_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_700_, 0, v___x_695_);
lean_ctor_set(v___x_700_, 1, v___x_699_);
v___x_701_ = lean_box(0);
v___x_702_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_702_, 0, v___x_700_);
lean_ctor_set(v___x_702_, 1, v___x_701_);
return v___x_702_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_adsb___boxed(lean_object* v_oracle_904_, lean_object* v_record_905_, lean_object* v_p_906_){
_start:
{
uint8_t v_oracle_boxed_907_; lean_object* v_res_908_; 
v_oracle_boxed_907_ = lean_unbox(v_oracle_904_);
v_res_908_ = lp_lean1090_Lean1090_Impl_JSON_adsb(v_oracle_boxed_907_, v_record_905_, v_p_906_);
lean_dec_ref(v_record_905_);
return v_res_908_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_oracleThreat(lean_object* v_p_912_){
_start:
{
lean_object* v___y_914_; uint8_t v___y_915_; lean_object* v___y_916_; lean_object* v___y_917_; lean_object* v_oracleThreat_920_; 
v_oracleThreat_920_ = lean_ctor_get(v_p_912_, 8);
if (lean_obj_tag(v_oracleThreat_920_) == 1)
{
lean_object* v_val_921_; 
v_val_921_ = lean_ctor_get(v_oracleThreat_920_, 0);
lean_inc(v_val_921_);
switch(lean_obj_tag(v_val_921_))
{
case 1:
{
lean_object* v_icao24_922_; lean_object* v___x_924_; uint8_t v_isShared_925_; uint8_t v_isSharedCheck_936_; 
lean_dec_ref(v_p_912_);
v_icao24_922_ = lean_ctor_get(v_val_921_, 0);
v_isSharedCheck_936_ = !lean_is_exclusive(v_val_921_);
if (v_isSharedCheck_936_ == 0)
{
v___x_924_ = v_val_921_;
v_isShared_925_ = v_isSharedCheck_936_;
goto v_resetjp_923_;
}
else
{
lean_inc(v_icao24_922_);
lean_dec(v_val_921_);
v___x_924_ = lean_box(0);
v_isShared_925_ = v_isSharedCheck_936_;
goto v_resetjp_923_;
}
v_resetjp_923_:
{
lean_object* v___x_926_; lean_object* v___x_927_; lean_object* v___x_928_; lean_object* v___x_929_; lean_object* v___x_931_; 
v___x_926_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__0));
v___x_927_ = lean_unsigned_to_nat(16u);
v___x_928_ = lean_unsigned_to_nat(6u);
v___x_929_ = lp_lean1090_Lean1090_Impl_JSON_digits(v___x_927_, v___x_928_, v_icao24_922_);
lean_dec(v_icao24_922_);
if (v_isShared_925_ == 0)
{
lean_ctor_set_tag(v___x_924_, 3);
lean_ctor_set(v___x_924_, 0, v___x_929_);
v___x_931_ = v___x_924_;
goto v_reusejp_930_;
}
else
{
lean_object* v_reuseFailAlloc_935_; 
v_reuseFailAlloc_935_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_935_, 0, v___x_929_);
v___x_931_ = v_reuseFailAlloc_935_;
goto v_reusejp_930_;
}
v_reusejp_930_:
{
lean_object* v___x_932_; lean_object* v___x_933_; lean_object* v___x_934_; 
v___x_932_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_932_, 0, v___x_926_);
lean_ctor_set(v___x_932_, 1, v___x_931_);
v___x_933_ = lean_box(0);
v___x_934_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_934_, 0, v___x_932_);
lean_ctor_set(v___x_934_, 1, v___x_933_);
return v___x_934_;
}
}
}
case 2:
{
lean_object* v_altitude_937_; lean_object* v_bearingDeg_938_; lean_object* v___x_939_; lean_object* v___y_941_; 
v_altitude_937_ = lean_ctor_get(v_val_921_, 0);
lean_inc(v_altitude_937_);
v_bearingDeg_938_ = lean_ctor_get(v_val_921_, 2);
lean_inc(v_bearingDeg_938_);
lean_dec_ref_known(v_val_921_, 3);
v___x_939_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__1));
if (lean_obj_tag(v_altitude_937_) == 0)
{
lean_object* v___x_959_; 
v___x_959_ = lean_box(0);
v___y_941_ = v___x_959_;
goto v___jp_940_;
}
else
{
lean_object* v_val_960_; lean_object* v___x_962_; uint8_t v_isShared_963_; uint8_t v_isSharedCheck_968_; 
v_val_960_ = lean_ctor_get(v_altitude_937_, 0);
v_isSharedCheck_968_ = !lean_is_exclusive(v_altitude_937_);
if (v_isSharedCheck_968_ == 0)
{
v___x_962_ = v_altitude_937_;
v_isShared_963_ = v_isSharedCheck_968_;
goto v_resetjp_961_;
}
else
{
lean_inc(v_val_960_);
lean_dec(v_altitude_937_);
v___x_962_ = lean_box(0);
v_isShared_963_ = v_isSharedCheck_968_;
goto v_resetjp_961_;
}
v_resetjp_961_:
{
lean_object* v___x_964_; lean_object* v___x_966_; 
v___x_964_ = lp_lean1090_Lean1090_Impl_JSON_integer(v_val_960_);
if (v_isShared_963_ == 0)
{
lean_ctor_set(v___x_962_, 0, v___x_964_);
v___x_966_ = v___x_962_;
goto v_reusejp_965_;
}
else
{
lean_object* v_reuseFailAlloc_967_; 
v_reuseFailAlloc_967_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_967_, 0, v___x_964_);
v___x_966_ = v_reuseFailAlloc_967_;
goto v_reusejp_965_;
}
v_reusejp_965_:
{
v___y_941_ = v___x_966_;
goto v___jp_940_;
}
}
}
v___jp_940_:
{
uint8_t v___x_942_; lean_object* v___x_943_; uint8_t v___x_944_; lean_object* v___x_945_; lean_object* v___x_946_; lean_object* v___x_947_; 
v___x_942_ = 0;
v___x_943_ = lp_lean1090_Lean1090_Impl_JSON_optional(v___x_939_, v___y_941_, v___x_942_);
lean_dec(v___y_941_);
v___x_944_ = 1;
v___x_945_ = lp_lean1090_Lean1090_Impl_JSON_numeric(v___x_944_, v_p_912_);
v___x_946_ = l_List_appendTR___redArg(v___x_943_, v___x_945_);
v___x_947_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__2));
if (lean_obj_tag(v_bearingDeg_938_) == 0)
{
lean_object* v___x_948_; 
v___x_948_ = lean_box(0);
v___y_914_ = v___x_947_;
v___y_915_ = v___x_942_;
v___y_916_ = v___x_946_;
v___y_917_ = v___x_948_;
goto v___jp_913_;
}
else
{
lean_object* v_val_949_; lean_object* v___x_951_; uint8_t v_isShared_952_; uint8_t v_isSharedCheck_958_; 
v_val_949_ = lean_ctor_get(v_bearingDeg_938_, 0);
v_isSharedCheck_958_ = !lean_is_exclusive(v_bearingDeg_938_);
if (v_isSharedCheck_958_ == 0)
{
v___x_951_ = v_bearingDeg_938_;
v_isShared_952_ = v_isSharedCheck_958_;
goto v_resetjp_950_;
}
else
{
lean_inc(v_val_949_);
lean_dec(v_bearingDeg_938_);
v___x_951_ = lean_box(0);
v_isShared_952_ = v_isSharedCheck_958_;
goto v_resetjp_950_;
}
v_resetjp_950_:
{
lean_object* v___x_953_; lean_object* v___x_954_; lean_object* v___x_956_; 
v___x_953_ = lean_nat_to_int(v_val_949_);
v___x_954_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_953_);
if (v_isShared_952_ == 0)
{
lean_ctor_set(v___x_951_, 0, v___x_954_);
v___x_956_ = v___x_951_;
goto v_reusejp_955_;
}
else
{
lean_object* v_reuseFailAlloc_957_; 
v_reuseFailAlloc_957_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_957_, 0, v___x_954_);
v___x_956_ = v_reuseFailAlloc_957_;
goto v_reusejp_955_;
}
v_reusejp_955_:
{
v___y_914_ = v___x_947_;
v___y_915_ = v___x_942_;
v___y_916_ = v___x_946_;
v___y_917_ = v___x_956_;
goto v___jp_913_;
}
}
}
}
}
default: 
{
lean_object* v___x_969_; 
lean_dec(v_val_921_);
lean_dec_ref(v_p_912_);
v___x_969_ = lean_box(0);
return v___x_969_;
}
}
}
else
{
lean_object* v___x_970_; 
lean_dec_ref(v_p_912_);
v___x_970_ = lean_box(0);
return v___x_970_;
}
v___jp_913_:
{
lean_object* v___x_918_; lean_object* v___x_919_; 
lean_inc_ref(v___y_914_);
v___x_918_ = lp_lean1090_Lean1090_Impl_JSON_optional(v___y_914_, v___y_917_, v___y_915_);
lean_dec(v___y_917_);
v___x_919_ = l_List_appendTR___redArg(v___y_916_, v___x_918_);
return v___x_919_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_standardThreat(lean_object* v_p_979_){
_start:
{
lean_object* v___y_981_; lean_object* v___y_982_; lean_object* v___y_983_; lean_object* v___y_984_; lean_object* v_standardThreat_990_; 
v_standardThreat_990_ = lean_ctor_get(v_p_979_, 7);
lean_inc(v_standardThreat_990_);
lean_dec_ref(v_p_979_);
if (lean_obj_tag(v_standardThreat_990_) == 1)
{
lean_object* v_val_991_; 
v_val_991_ = lean_ctor_get(v_standardThreat_990_, 0);
lean_inc(v_val_991_);
lean_dec_ref_known(v_standardThreat_990_, 1);
switch(lean_obj_tag(v_val_991_))
{
case 1:
{
lean_object* v_icao24_992_; lean_object* v___x_994_; uint8_t v_isShared_995_; uint8_t v_isSharedCheck_1006_; 
v_icao24_992_ = lean_ctor_get(v_val_991_, 0);
v_isSharedCheck_1006_ = !lean_is_exclusive(v_val_991_);
if (v_isSharedCheck_1006_ == 0)
{
v___x_994_ = v_val_991_;
v_isShared_995_ = v_isSharedCheck_1006_;
goto v_resetjp_993_;
}
else
{
lean_inc(v_icao24_992_);
lean_dec(v_val_991_);
v___x_994_ = lean_box(0);
v_isShared_995_ = v_isSharedCheck_1006_;
goto v_resetjp_993_;
}
v_resetjp_993_:
{
lean_object* v___x_996_; lean_object* v___x_997_; lean_object* v___x_998_; lean_object* v___x_999_; lean_object* v___x_1001_; 
v___x_996_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__0));
v___x_997_ = lean_unsigned_to_nat(16u);
v___x_998_ = lean_unsigned_to_nat(6u);
v___x_999_ = lp_lean1090_Lean1090_Impl_JSON_digits(v___x_997_, v___x_998_, v_icao24_992_);
lean_dec(v_icao24_992_);
if (v_isShared_995_ == 0)
{
lean_ctor_set_tag(v___x_994_, 3);
lean_ctor_set(v___x_994_, 0, v___x_999_);
v___x_1001_ = v___x_994_;
goto v_reusejp_1000_;
}
else
{
lean_object* v_reuseFailAlloc_1005_; 
v_reuseFailAlloc_1005_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1005_, 0, v___x_999_);
v___x_1001_ = v_reuseFailAlloc_1005_;
goto v_reusejp_1000_;
}
v_reusejp_1000_:
{
lean_object* v___x_1002_; lean_object* v___x_1003_; lean_object* v___x_1004_; 
v___x_1002_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1002_, 0, v___x_996_);
lean_ctor_set(v___x_1002_, 1, v___x_1001_);
v___x_1003_ = lean_box(0);
v___x_1004_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1004_, 0, v___x_1002_);
lean_ctor_set(v___x_1004_, 1, v___x_1003_);
return v___x_1004_;
}
}
}
case 2:
{
lean_object* v_altitudeFeet_1007_; lean_object* v_range_1008_; lean_object* v_bearing_1009_; lean_object* v___y_1011_; lean_object* v___y_1012_; lean_object* v___y_1013_; lean_object* v___x_1045_; lean_object* v___y_1047_; 
v_altitudeFeet_1007_ = lean_ctor_get(v_val_991_, 0);
lean_inc(v_altitudeFeet_1007_);
v_range_1008_ = lean_ctor_get(v_val_991_, 1);
lean_inc(v_range_1008_);
v_bearing_1009_ = lean_ctor_get(v_val_991_, 2);
lean_inc(v_bearing_1009_);
lean_dec_ref_known(v_val_991_, 3);
v___x_1045_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__1));
if (lean_obj_tag(v_altitudeFeet_1007_) == 0)
{
lean_object* v___x_1084_; 
v___x_1084_ = lean_box(0);
v___y_1047_ = v___x_1084_;
goto v___jp_1046_;
}
else
{
lean_object* v_val_1085_; lean_object* v___x_1087_; uint8_t v_isShared_1088_; uint8_t v_isSharedCheck_1093_; 
v_val_1085_ = lean_ctor_get(v_altitudeFeet_1007_, 0);
v_isSharedCheck_1093_ = !lean_is_exclusive(v_altitudeFeet_1007_);
if (v_isSharedCheck_1093_ == 0)
{
v___x_1087_ = v_altitudeFeet_1007_;
v_isShared_1088_ = v_isSharedCheck_1093_;
goto v_resetjp_1086_;
}
else
{
lean_inc(v_val_1085_);
lean_dec(v_altitudeFeet_1007_);
v___x_1087_ = lean_box(0);
v_isShared_1088_ = v_isSharedCheck_1093_;
goto v_resetjp_1086_;
}
v_resetjp_1086_:
{
lean_object* v___x_1089_; lean_object* v___x_1091_; 
v___x_1089_ = lp_lean1090_Lean1090_Impl_JSON_integer(v_val_1085_);
if (v_isShared_1088_ == 0)
{
lean_ctor_set(v___x_1087_, 0, v___x_1089_);
v___x_1091_ = v___x_1087_;
goto v_reusejp_1090_;
}
else
{
lean_object* v_reuseFailAlloc_1092_; 
v_reuseFailAlloc_1092_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1092_, 0, v___x_1089_);
v___x_1091_ = v_reuseFailAlloc_1092_;
goto v_reusejp_1090_;
}
v_reusejp_1090_:
{
v___y_1047_ = v___x_1091_;
goto v___jp_1046_;
}
}
}
v___jp_1010_:
{
lean_object* v___x_1014_; lean_object* v___x_1015_; 
lean_inc_ref(v___y_1012_);
v___x_1014_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1014_, 0, v___y_1012_);
lean_ctor_set(v___x_1014_, 1, v___y_1013_);
v___x_1015_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_oracleThreat___closed__2));
switch(lean_obj_tag(v_bearing_1009_))
{
case 0:
{
lean_object* v___x_1016_; 
v___x_1016_ = lean_box(0);
v___y_981_ = v___x_1015_;
v___y_982_ = v___x_1014_;
v___y_983_ = v___y_1011_;
v___y_984_ = v___x_1016_;
goto v___jp_980_;
}
case 1:
{
lean_object* v_lower_1017_; lean_object* v_upper_1018_; lean_object* v___x_1020_; uint8_t v_isShared_1021_; uint8_t v_isSharedCheck_1036_; 
v_lower_1017_ = lean_ctor_get(v_bearing_1009_, 0);
v_upper_1018_ = lean_ctor_get(v_bearing_1009_, 1);
v_isSharedCheck_1036_ = !lean_is_exclusive(v_bearing_1009_);
if (v_isSharedCheck_1036_ == 0)
{
v___x_1020_ = v_bearing_1009_;
v_isShared_1021_ = v_isSharedCheck_1036_;
goto v_resetjp_1019_;
}
else
{
lean_inc(v_upper_1018_);
lean_inc(v_lower_1017_);
lean_dec(v_bearing_1009_);
v___x_1020_ = lean_box(0);
v_isShared_1021_ = v_isSharedCheck_1036_;
goto v_resetjp_1019_;
}
v_resetjp_1019_:
{
lean_object* v___x_1022_; lean_object* v___x_1023_; lean_object* v___x_1024_; lean_object* v___x_1026_; 
v___x_1022_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__0));
v___x_1023_ = lean_nat_to_int(v_lower_1017_);
v___x_1024_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_1023_);
if (v_isShared_1021_ == 0)
{
lean_ctor_set_tag(v___x_1020_, 0);
lean_ctor_set(v___x_1020_, 1, v___x_1024_);
lean_ctor_set(v___x_1020_, 0, v___x_1022_);
v___x_1026_ = v___x_1020_;
goto v_reusejp_1025_;
}
else
{
lean_object* v_reuseFailAlloc_1035_; 
v_reuseFailAlloc_1035_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1035_, 0, v___x_1022_);
lean_ctor_set(v_reuseFailAlloc_1035_, 1, v___x_1024_);
v___x_1026_ = v_reuseFailAlloc_1035_;
goto v_reusejp_1025_;
}
v_reusejp_1025_:
{
lean_object* v___x_1027_; lean_object* v___x_1028_; lean_object* v___x_1029_; lean_object* v___x_1030_; lean_object* v___x_1031_; lean_object* v___x_1032_; lean_object* v___x_1033_; lean_object* v___x_1034_; 
v___x_1027_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__1));
v___x_1028_ = lean_nat_to_int(v_upper_1018_);
v___x_1029_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_1028_);
v___x_1030_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1030_, 0, v___x_1027_);
lean_ctor_set(v___x_1030_, 1, v___x_1029_);
v___x_1031_ = lean_box(0);
v___x_1032_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1032_, 0, v___x_1030_);
lean_ctor_set(v___x_1032_, 1, v___x_1031_);
v___x_1033_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1033_, 0, v___x_1026_);
lean_ctor_set(v___x_1033_, 1, v___x_1032_);
v___x_1034_ = l_Lean_Json_mkObj(v___x_1033_);
lean_dec_ref_known(v___x_1033_, 2);
v___y_981_ = v___x_1015_;
v___y_982_ = v___x_1014_;
v___y_983_ = v___y_1011_;
v___y_984_ = v___x_1034_;
goto v___jp_980_;
}
}
}
default: 
{
lean_object* v_code_1037_; lean_object* v___x_1038_; lean_object* v___x_1039_; lean_object* v___x_1040_; lean_object* v___x_1041_; lean_object* v___x_1042_; lean_object* v___x_1043_; lean_object* v___x_1044_; 
v_code_1037_ = lean_ctor_get(v_bearing_1009_, 0);
lean_inc(v_code_1037_);
lean_dec_ref_known(v_bearing_1009_, 1);
v___x_1038_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__2));
v___x_1039_ = lean_nat_to_int(v_code_1037_);
v___x_1040_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_1039_);
v___x_1041_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1041_, 0, v___x_1038_);
lean_ctor_set(v___x_1041_, 1, v___x_1040_);
v___x_1042_ = lean_box(0);
v___x_1043_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1043_, 0, v___x_1041_);
lean_ctor_set(v___x_1043_, 1, v___x_1042_);
v___x_1044_ = l_Lean_Json_mkObj(v___x_1043_);
lean_dec_ref_known(v___x_1043_, 2);
v___y_981_ = v___x_1015_;
v___y_982_ = v___x_1014_;
v___y_983_ = v___y_1011_;
v___y_984_ = v___x_1044_;
goto v___jp_980_;
}
}
}
v___jp_1046_:
{
uint8_t v___x_1048_; lean_object* v___x_1049_; lean_object* v___x_1050_; 
v___x_1048_ = 0;
v___x_1049_ = lp_lean1090_Lean1090_Impl_JSON_optional(v___x_1045_, v___y_1047_, v___x_1048_);
lean_dec(v___y_1047_);
v___x_1050_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__3));
switch(lean_obj_tag(v_range_1008_))
{
case 0:
{
lean_object* v___x_1051_; 
v___x_1051_ = lean_box(0);
v___y_1011_ = v___x_1049_;
v___y_1012_ = v___x_1050_;
v___y_1013_ = v___x_1051_;
goto v___jp_1010_;
}
case 1:
{
lean_object* v_upper_1052_; lean_object* v___x_1053_; lean_object* v___x_1054_; lean_object* v___x_1055_; lean_object* v___x_1056_; lean_object* v___x_1057_; lean_object* v___x_1058_; 
v_upper_1052_ = lean_ctor_get(v_range_1008_, 0);
lean_inc_ref(v_upper_1052_);
lean_dec_ref_known(v_range_1008_, 1);
v___x_1053_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__4));
v___x_1054_ = lp_lean1090_Lean1090_Impl_JSON_rational(v_upper_1052_);
v___x_1055_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1055_, 0, v___x_1053_);
lean_ctor_set(v___x_1055_, 1, v___x_1054_);
v___x_1056_ = lean_box(0);
v___x_1057_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1057_, 0, v___x_1055_);
lean_ctor_set(v___x_1057_, 1, v___x_1056_);
v___x_1058_ = l_Lean_Json_mkObj(v___x_1057_);
lean_dec_ref_known(v___x_1057_, 2);
v___y_1011_ = v___x_1049_;
v___y_1012_ = v___x_1050_;
v___y_1013_ = v___x_1058_;
goto v___jp_1010_;
}
case 2:
{
lean_object* v_centre_1059_; lean_object* v_tolerance_1060_; lean_object* v___x_1062_; uint8_t v_isShared_1063_; uint8_t v_isSharedCheck_1076_; 
v_centre_1059_ = lean_ctor_get(v_range_1008_, 0);
v_tolerance_1060_ = lean_ctor_get(v_range_1008_, 1);
v_isSharedCheck_1076_ = !lean_is_exclusive(v_range_1008_);
if (v_isSharedCheck_1076_ == 0)
{
v___x_1062_ = v_range_1008_;
v_isShared_1063_ = v_isSharedCheck_1076_;
goto v_resetjp_1061_;
}
else
{
lean_inc(v_tolerance_1060_);
lean_inc(v_centre_1059_);
lean_dec(v_range_1008_);
v___x_1062_ = lean_box(0);
v_isShared_1063_ = v_isSharedCheck_1076_;
goto v_resetjp_1061_;
}
v_resetjp_1061_:
{
lean_object* v___x_1064_; lean_object* v___x_1065_; lean_object* v___x_1067_; 
v___x_1064_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__5));
v___x_1065_ = lp_lean1090_Lean1090_Impl_JSON_rational(v_centre_1059_);
if (v_isShared_1063_ == 0)
{
lean_ctor_set_tag(v___x_1062_, 0);
lean_ctor_set(v___x_1062_, 1, v___x_1065_);
lean_ctor_set(v___x_1062_, 0, v___x_1064_);
v___x_1067_ = v___x_1062_;
goto v_reusejp_1066_;
}
else
{
lean_object* v_reuseFailAlloc_1075_; 
v_reuseFailAlloc_1075_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1075_, 0, v___x_1064_);
lean_ctor_set(v_reuseFailAlloc_1075_, 1, v___x_1065_);
v___x_1067_ = v_reuseFailAlloc_1075_;
goto v_reusejp_1066_;
}
v_reusejp_1066_:
{
lean_object* v___x_1068_; lean_object* v___x_1069_; lean_object* v___x_1070_; lean_object* v___x_1071_; lean_object* v___x_1072_; lean_object* v___x_1073_; lean_object* v___x_1074_; 
v___x_1068_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__6));
v___x_1069_ = lp_lean1090_Lean1090_Impl_JSON_rational(v_tolerance_1060_);
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
v___x_1074_ = l_Lean_Json_mkObj(v___x_1073_);
lean_dec_ref_known(v___x_1073_, 2);
v___y_1011_ = v___x_1049_;
v___y_1012_ = v___x_1050_;
v___y_1013_ = v___x_1074_;
goto v___jp_1010_;
}
}
}
default: 
{
lean_object* v_lower_1077_; lean_object* v___x_1078_; lean_object* v___x_1079_; lean_object* v___x_1080_; lean_object* v___x_1081_; lean_object* v___x_1082_; lean_object* v___x_1083_; 
v_lower_1077_ = lean_ctor_get(v_range_1008_, 0);
lean_inc_ref(v_lower_1077_);
lean_dec_ref_known(v_range_1008_, 1);
v___x_1078_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_standardThreat___closed__7));
v___x_1079_ = lp_lean1090_Lean1090_Impl_JSON_rational(v_lower_1077_);
v___x_1080_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1080_, 0, v___x_1078_);
lean_ctor_set(v___x_1080_, 1, v___x_1079_);
v___x_1081_ = lean_box(0);
v___x_1082_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1082_, 0, v___x_1080_);
lean_ctor_set(v___x_1082_, 1, v___x_1081_);
v___x_1083_ = l_Lean_Json_mkObj(v___x_1082_);
lean_dec_ref_known(v___x_1082_, 2);
v___y_1011_ = v___x_1049_;
v___y_1012_ = v___x_1050_;
v___y_1013_ = v___x_1083_;
goto v___jp_1010_;
}
}
}
}
default: 
{
lean_object* v___x_1094_; 
lean_dec(v_val_991_);
v___x_1094_ = lean_box(0);
return v___x_1094_;
}
}
}
else
{
lean_object* v___x_1095_; 
lean_dec(v_standardThreat_990_);
v___x_1095_ = lean_box(0);
return v___x_1095_;
}
v___jp_980_:
{
lean_object* v___x_985_; lean_object* v___x_986_; lean_object* v___x_987_; lean_object* v___x_988_; lean_object* v___x_989_; 
lean_inc_ref(v___y_981_);
v___x_985_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_985_, 0, v___y_981_);
lean_ctor_set(v___x_985_, 1, v___y_984_);
v___x_986_ = lean_box(0);
v___x_987_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_987_, 0, v___x_985_);
lean_ctor_set(v___x_987_, 1, v___x_986_);
v___x_988_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_988_, 0, v___y_982_);
lean_ctor_set(v___x_988_, 1, v___x_987_);
v___x_989_ = l_List_appendTR___redArg(v___y_983_, v___x_988_);
return v___x_989_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__1(uint8_t v_oracle_1096_, lean_object* v_p_1097_, lean_object* v_register_1098_, lean_object* v_a_1099_, lean_object* v_a_1100_){
_start:
{
if (lean_obj_tag(v_a_1099_) == 0)
{
lean_object* v___x_1101_; 
v___x_1101_ = lean_array_to_list(v_a_1100_);
return v___x_1101_;
}
else
{
lean_object* v_head_1102_; lean_object* v_tail_1103_; lean_object* v___x_1104_; uint8_t v___x_1105_; lean_object* v___x_1106_; lean_object* v___x_1107_; 
v_head_1102_ = lean_ctor_get(v_a_1099_, 0);
lean_inc_n(v_head_1102_, 2);
v_tail_1103_ = lean_ctor_get(v_a_1099_, 1);
lean_inc(v_tail_1103_);
lean_dec_ref_known(v_a_1099_, 2);
v___x_1104_ = lean_unsigned_to_nat(68u);
v___x_1105_ = lean_nat_dec_eq(v_register_1098_, v___x_1104_);
v___x_1106_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_1096_, v_p_1097_, v_head_1102_, v_head_1102_, v___x_1105_);
lean_dec(v_head_1102_);
v___x_1107_ = l_List_foldl___at___00Array_appendList_spec__0___redArg(v_a_1100_, v___x_1106_);
v_a_1099_ = v_tail_1103_;
v_a_1100_ = v___x_1107_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__1___boxed(lean_object* v_oracle_1109_, lean_object* v_p_1110_, lean_object* v_register_1111_, lean_object* v_a_1112_, lean_object* v_a_1113_){
_start:
{
uint8_t v_oracle_boxed_1114_; lean_object* v_res_1115_; 
v_oracle_boxed_1114_ = lean_unbox(v_oracle_1109_);
v_res_1115_ = lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__1(v_oracle_boxed_1114_, v_p_1110_, v_register_1111_, v_a_1112_, v_a_1113_);
lean_dec(v_register_1111_);
lean_dec_ref(v_p_1110_);
return v_res_1115_;
}
}
static lean_object* _init_lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__0___closed__0(void){
_start:
{
lean_object* v___x_1116_; lean_object* v___x_1117_; 
v___x_1116_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1));
v___x_1117_ = lean_string_utf8_byte_size(v___x_1116_);
return v___x_1117_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__0(uint8_t v___y_1118_, lean_object* v_a_1119_, lean_object* v_a_1120_){
_start:
{
if (lean_obj_tag(v_a_1119_) == 0)
{
lean_object* v___x_1121_; 
v___x_1121_ = lean_array_to_list(v_a_1120_);
return v___x_1121_;
}
else
{
lean_object* v_head_1122_; lean_object* v_tail_1123_; lean_object* v_name_1124_; lean_object* v_code_1125_; lean_object* v___x_1127_; uint8_t v_isShared_1128_; uint8_t v_isSharedCheck_1146_; 
v_head_1122_ = lean_ctor_get(v_a_1119_, 0);
lean_inc(v_head_1122_);
v_tail_1123_ = lean_ctor_get(v_a_1119_, 1);
lean_inc(v_tail_1123_);
lean_dec_ref_known(v_a_1119_, 2);
v_name_1124_ = lean_ctor_get(v_head_1122_, 0);
v_code_1125_ = lean_ctor_get(v_head_1122_, 1);
v_isSharedCheck_1146_ = !lean_is_exclusive(v_head_1122_);
if (v_isSharedCheck_1146_ == 0)
{
v___x_1127_ = v_head_1122_;
v_isShared_1128_ = v_isSharedCheck_1146_;
goto v_resetjp_1126_;
}
else
{
lean_inc(v_code_1125_);
lean_inc(v_name_1124_);
lean_dec(v_head_1122_);
v___x_1127_ = lean_box(0);
v_isShared_1128_ = v_isSharedCheck_1146_;
goto v_resetjp_1126_;
}
v_resetjp_1126_:
{
lean_object* v___x_1129_; lean_object* v___x_1130_; lean_object* v___x_1131_; uint8_t v___x_1132_; 
v___x_1129_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1));
v___x_1130_ = lean_string_utf8_byte_size(v_name_1124_);
v___x_1131_ = lean_obj_once(&lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__0___closed__0, &lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__0___closed__0_once, _init_lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__0___closed__0);
v___x_1132_ = lean_nat_dec_le(v___x_1131_, v___x_1130_);
if (v___x_1132_ == 0)
{
lean_del_object(v___x_1127_);
lean_dec(v_code_1125_);
lean_dec_ref(v_name_1124_);
v_a_1119_ = v_tail_1123_;
goto _start;
}
else
{
lean_object* v___x_1134_; uint8_t v___x_1135_; 
v___x_1134_ = lean_unsigned_to_nat(0u);
v___x_1135_ = lean_string_memcmp(v_name_1124_, v___x_1129_, v___x_1134_, v___x_1134_, v___x_1131_);
if (v___x_1135_ == 0)
{
lean_del_object(v___x_1127_);
lean_dec(v_code_1125_);
lean_dec_ref(v_name_1124_);
v_a_1119_ = v_tail_1123_;
goto _start;
}
else
{
uint8_t v___x_1137_; 
v___x_1137_ = lean_nat_dec_eq(v_code_1125_, v___x_1134_);
lean_dec(v_code_1125_);
if (v___x_1137_ == 0)
{
if (v___y_1118_ == 0)
{
lean_del_object(v___x_1127_);
lean_dec_ref(v_name_1124_);
v_a_1119_ = v_tail_1123_;
goto _start;
}
else
{
lean_object* v___x_1139_; lean_object* v___x_1141_; 
v___x_1139_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_1139_, 0, v___y_1118_);
if (v_isShared_1128_ == 0)
{
lean_ctor_set(v___x_1127_, 1, v___x_1139_);
v___x_1141_ = v___x_1127_;
goto v_reusejp_1140_;
}
else
{
lean_object* v_reuseFailAlloc_1144_; 
v_reuseFailAlloc_1144_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1144_, 0, v_name_1124_);
lean_ctor_set(v_reuseFailAlloc_1144_, 1, v___x_1139_);
v___x_1141_ = v_reuseFailAlloc_1144_;
goto v_reusejp_1140_;
}
v_reusejp_1140_:
{
lean_object* v___x_1142_; 
v___x_1142_ = lean_array_push(v_a_1120_, v___x_1141_);
v_a_1119_ = v_tail_1123_;
v_a_1120_ = v___x_1142_;
goto _start;
}
}
}
else
{
lean_del_object(v___x_1127_);
lean_dec_ref(v_name_1124_);
v_a_1119_ = v_tail_1123_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__0___boxed(lean_object* v___y_1147_, lean_object* v_a_1148_, lean_object* v_a_1149_){
_start:
{
uint8_t v___y_1575__boxed_1150_; lean_object* v_res_1151_; 
v___y_1575__boxed_1150_ = lean_unbox(v___y_1147_);
v_res_1151_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__0(v___y_1575__boxed_1150_, v_a_1148_, v_a_1149_);
return v_res_1151_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_JSON_commB_spec__2(lean_object* v_register_1152_, lean_object* v_a_1153_, lean_object* v_a_1154_){
_start:
{
if (lean_obj_tag(v_a_1153_) == 0)
{
lean_object* v___x_1155_; 
v___x_1155_ = l_List_reverse___redArg(v_a_1154_);
return v___x_1155_;
}
else
{
lean_object* v_head_1156_; lean_object* v_tail_1157_; lean_object* v___x_1159_; uint8_t v_isShared_1160_; uint8_t v_isSharedCheck_1175_; 
v_head_1156_ = lean_ctor_get(v_a_1153_, 0);
v_tail_1157_ = lean_ctor_get(v_a_1153_, 1);
v_isSharedCheck_1175_ = !lean_is_exclusive(v_a_1153_);
if (v_isSharedCheck_1175_ == 0)
{
v___x_1159_ = v_a_1153_;
v_isShared_1160_ = v_isSharedCheck_1175_;
goto v_resetjp_1158_;
}
else
{
lean_inc(v_tail_1157_);
lean_inc(v_head_1156_);
lean_dec(v_a_1153_);
v___x_1159_ = lean_box(0);
v_isShared_1160_ = v_isSharedCheck_1175_;
goto v_resetjp_1158_;
}
v_resetjp_1158_:
{
lean_object* v_fst_1161_; lean_object* v___x_1162_; uint8_t v___x_1163_; 
v_fst_1161_ = lean_ctor_get(v_head_1156_, 0);
v___x_1162_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1));
v___x_1163_ = lean_string_dec_eq(v_fst_1161_, v___x_1162_);
if (v___x_1163_ == 0)
{
lean_object* v___x_1164_; uint8_t v___x_1165_; 
v___x_1164_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__0));
v___x_1165_ = lean_string_dec_eq(v_fst_1161_, v___x_1164_);
if (v___x_1165_ == 0)
{
lean_object* v___x_1166_; uint8_t v___x_1167_; 
v___x_1166_ = lean_unsigned_to_nat(5u);
v___x_1167_ = lean_nat_dec_eq(v_register_1152_, v___x_1166_);
if (v___x_1167_ == 0)
{
lean_del_object(v___x_1159_);
lean_dec(v_head_1156_);
v_a_1153_ = v_tail_1157_;
goto _start;
}
else
{
lean_object* v___x_1170_; 
if (v_isShared_1160_ == 0)
{
lean_ctor_set(v___x_1159_, 1, v_a_1154_);
v___x_1170_ = v___x_1159_;
goto v_reusejp_1169_;
}
else
{
lean_object* v_reuseFailAlloc_1172_; 
v_reuseFailAlloc_1172_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1172_, 0, v_head_1156_);
lean_ctor_set(v_reuseFailAlloc_1172_, 1, v_a_1154_);
v___x_1170_ = v_reuseFailAlloc_1172_;
goto v_reusejp_1169_;
}
v_reusejp_1169_:
{
v_a_1153_ = v_tail_1157_;
v_a_1154_ = v___x_1170_;
goto _start;
}
}
}
else
{
lean_del_object(v___x_1159_);
lean_dec(v_head_1156_);
v_a_1153_ = v_tail_1157_;
goto _start;
}
}
else
{
lean_del_object(v___x_1159_);
lean_dec(v_head_1156_);
v_a_1153_ = v_tail_1157_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_JSON_commB_spec__2___boxed(lean_object* v_register_1176_, lean_object* v_a_1177_, lean_object* v_a_1178_){
_start:
{
lean_object* v_res_1179_; 
v_res_1179_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_JSON_commB_spec__2(v_register_1176_, v_a_1177_, v_a_1178_);
lean_dec(v_register_1176_);
return v_res_1179_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_commB(uint8_t v_oracle_1314_, lean_object* v_register_1315_, lean_object* v_record_1316_, lean_object* v_p_1317_){
_start:
{
lean_object* v___x_1318_; uint8_t v___x_1319_; 
v___x_1318_ = lean_unsigned_to_nat(5u);
v___x_1319_ = lean_nat_dec_eq(v_register_1315_, v___x_1318_);
if (v___x_1319_ == 0)
{
lean_object* v___x_1320_; uint8_t v___x_1321_; 
v___x_1320_ = lean_unsigned_to_nat(101u);
v___x_1321_ = lean_nat_dec_eq(v_register_1315_, v___x_1320_);
if (v___x_1321_ == 0)
{
lean_object* v___x_1322_; lean_object* v___x_1323_; lean_object* v___x_1324_; lean_object* v___x_1325_; lean_object* v___x_1326_; lean_object* v___x_1327_; lean_object* v___x_1328_; lean_object* v_tag_1329_; uint8_t v___y_1331_; lean_object* v___y_1337_; lean_object* v___y_1338_; uint8_t v___x_1341_; 
v___x_1322_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1));
v___x_1323_ = lean_unsigned_to_nat(16u);
v___x_1324_ = lean_unsigned_to_nat(2u);
v___x_1325_ = lp_lean1090_Lean1090_Impl_JSON_digits(v___x_1323_, v___x_1324_, v_register_1315_);
v___x_1326_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1326_, 0, v___x_1325_);
v___x_1327_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1327_, 0, v___x_1322_);
lean_ctor_set(v___x_1327_, 1, v___x_1326_);
v___x_1328_ = lean_box(0);
v_tag_1329_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_tag_1329_, 0, v___x_1327_);
lean_ctor_set(v_tag_1329_, 1, v___x_1328_);
v___x_1341_ = lean_nat_dec_eq(v_register_1315_, v___x_1323_);
if (v___x_1341_ == 0)
{
uint8_t v___x_1342_; lean_object* v___x_1343_; uint8_t v___x_1344_; 
v___x_1342_ = 1;
v___x_1343_ = lean_unsigned_to_nat(23u);
v___x_1344_ = lean_nat_dec_eq(v_register_1315_, v___x_1343_);
if (v___x_1344_ == 0)
{
lean_object* v___x_1345_; uint8_t v___x_1346_; 
v___x_1345_ = lean_unsigned_to_nat(24u);
v___x_1346_ = lean_nat_dec_eq(v_register_1315_, v___x_1345_);
if (v___x_1346_ == 0)
{
lean_object* v___x_1347_; uint8_t v___x_1348_; 
v___x_1347_ = lean_unsigned_to_nat(25u);
v___x_1348_ = lean_nat_dec_eq(v_register_1315_, v___x_1347_);
if (v___x_1348_ == 0)
{
lean_object* v___x_1349_; uint8_t v___x_1350_; 
v___x_1349_ = lean_unsigned_to_nat(32u);
v___x_1350_ = lean_nat_dec_eq(v_register_1315_, v___x_1349_);
if (v___x_1350_ == 0)
{
lean_object* v___x_1351_; uint8_t v___x_1352_; 
v___x_1351_ = lean_unsigned_to_nat(33u);
v___x_1352_ = lean_nat_dec_eq(v_register_1315_, v___x_1351_);
if (v___x_1352_ == 0)
{
lean_object* v___x_1353_; uint8_t v___x_1354_; 
v___x_1353_ = lean_unsigned_to_nat(48u);
v___x_1354_ = lean_nat_dec_eq(v_register_1315_, v___x_1353_);
if (v___x_1354_ == 0)
{
lean_object* v___x_1355_; uint8_t v___x_1356_; 
v___x_1355_ = lean_unsigned_to_nat(64u);
v___x_1356_ = lean_nat_dec_eq(v_register_1315_, v___x_1355_);
if (v___x_1356_ == 0)
{
lean_object* v___x_1357_; uint8_t v___x_1358_; 
lean_dec_ref(v_record_1316_);
v___x_1357_ = lean_unsigned_to_nat(68u);
v___x_1358_ = lean_nat_dec_eq(v_register_1315_, v___x_1357_);
if (v___x_1358_ == 0)
{
lean_object* v___x_1359_; uint8_t v___x_1360_; 
v___x_1359_ = lean_unsigned_to_nat(69u);
v___x_1360_ = lean_nat_dec_eq(v_register_1315_, v___x_1359_);
if (v___x_1360_ == 0)
{
lean_object* v___x_1361_; uint8_t v___x_1362_; 
v___x_1361_ = lean_unsigned_to_nat(80u);
v___x_1362_ = lean_nat_dec_eq(v_register_1315_, v___x_1361_);
if (v___x_1362_ == 0)
{
lean_object* v___x_1363_; uint8_t v___x_1364_; 
v___x_1363_ = lean_unsigned_to_nat(96u);
v___x_1364_ = lean_nat_dec_eq(v_register_1315_, v___x_1363_);
if (v___x_1364_ == 0)
{
lean_object* v___x_1365_; 
lean_dec_ref(v_p_1317_);
v___x_1365_ = l_List_appendTR___redArg(v_tag_1329_, v___x_1328_);
return v___x_1365_;
}
else
{
lean_object* v___x_1366_; lean_object* v___x_1367_; lean_object* v___x_1368_; lean_object* v___x_1369_; lean_object* v___x_1370_; lean_object* v___x_1371_; lean_object* v___x_1372_; lean_object* v___x_1373_; lean_object* v___x_1374_; lean_object* v___x_1375_; lean_object* v___x_1376_; 
lean_inc_ref(v_p_1317_);
v___x_1366_ = lp_lean1090_Lean1090_Impl_JSON_numeric(v_oracle_1314_, v_p_1317_);
v___x_1367_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__23));
v___x_1368_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_1314_, v_p_1317_, v___x_1367_, v___x_1367_, v___x_1342_);
v___x_1369_ = l_List_appendTR___redArg(v___x_1366_, v___x_1368_);
v___x_1370_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__0));
v___x_1371_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_1314_, v_p_1317_, v___x_1370_, v___x_1370_, v___x_1342_);
v___x_1372_ = l_List_appendTR___redArg(v___x_1369_, v___x_1371_);
v___x_1373_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__1));
v___x_1374_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_1314_, v_p_1317_, v___x_1373_, v___x_1373_, v___x_1342_);
lean_dec_ref(v_p_1317_);
v___x_1375_ = l_List_appendTR___redArg(v___x_1372_, v___x_1374_);
v___x_1376_ = l_List_appendTR___redArg(v_tag_1329_, v___x_1375_);
return v___x_1376_;
}
}
else
{
lean_object* v___x_1377_; lean_object* v___x_1378_; lean_object* v___x_1379_; lean_object* v___x_1380_; lean_object* v___x_1381_; lean_object* v___x_1382_; lean_object* v___x_1383_; lean_object* v___x_1384_; 
lean_inc_ref(v_p_1317_);
v___x_1377_ = lp_lean1090_Lean1090_Impl_JSON_numeric(v_oracle_1314_, v_p_1317_);
v___x_1378_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__2));
v___x_1379_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_1314_, v_p_1317_, v___x_1378_, v___x_1378_, v___x_1360_);
v___x_1380_ = l_List_appendTR___redArg(v___x_1377_, v___x_1379_);
v___x_1381_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__22));
v___x_1382_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_1314_, v_p_1317_, v___x_1381_, v___x_1381_, v___x_1360_);
lean_dec_ref(v_p_1317_);
v___x_1383_ = l_List_appendTR___redArg(v___x_1380_, v___x_1382_);
v___x_1384_ = l_List_appendTR___redArg(v_tag_1329_, v___x_1383_);
return v___x_1384_;
}
}
else
{
lean_object* v___x_1385_; lean_object* v___x_1386_; lean_object* v___x_1387_; lean_object* v___x_1388_; lean_object* v___x_1389_; lean_object* v___x_1390_; lean_object* v___x_1391_; lean_object* v___x_1392_; lean_object* v___x_1393_; lean_object* v___x_1394_; lean_object* v___x_1395_; lean_object* v___x_1396_; 
v___x_1385_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__11));
v___x_1386_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_numeric___closed__0));
v___x_1387_ = lp_lean1090___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__1(v_oracle_1314_, v_p_1317_, v_register_1315_, v___x_1385_, v___x_1386_);
v___x_1388_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__12));
v___x_1389_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_1314_, v_p_1317_, v___x_1388_, v___x_1388_, v___x_1358_);
v___x_1390_ = l_List_appendTR___redArg(v___x_1387_, v___x_1389_);
v___x_1391_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__13));
v___x_1392_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_1314_, v_p_1317_, v___x_1391_, v___x_1391_, v___x_1358_);
v___x_1393_ = l_List_appendTR___redArg(v___x_1390_, v___x_1392_);
v___x_1394_ = lp_lean1090_Lean1090_Impl_JSON_numeric(v_oracle_1314_, v_p_1317_);
v___x_1395_ = l_List_appendTR___redArg(v___x_1393_, v___x_1394_);
v___x_1396_ = l_List_appendTR___redArg(v_tag_1329_, v___x_1395_);
return v___x_1396_;
}
}
else
{
lean_object* v___x_1397_; lean_object* v___x_1398_; lean_object* v___x_1399_; lean_object* v___x_1400_; lean_object* v___x_1401_; lean_object* v___x_1402_; lean_object* v___x_1403_; lean_object* v___x_1404_; lean_object* v___x_1405_; lean_object* v___x_1406_; lean_object* v___x_1407_; lean_object* v___x_1408_; lean_object* v___x_1409_; lean_object* v___x_1410_; 
v___x_1397_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__14));
v___x_1398_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_1314_, v_p_1317_, v___x_1397_, v___x_1397_, v___x_1356_);
v___x_1399_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__3));
v___x_1400_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_1314_, v_p_1317_, v___x_1399_, v___x_1399_, v___x_1356_);
v___x_1401_ = l_List_appendTR___redArg(v___x_1398_, v___x_1400_);
v___x_1402_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__15));
v___x_1403_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_1314_, v_p_1317_, v___x_1402_, v___x_1402_, v___x_1356_);
v___x_1404_ = l_List_appendTR___redArg(v___x_1401_, v___x_1403_);
v___x_1405_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__16));
v___x_1406_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_1314_, v_p_1317_, v___x_1405_, v___x_1405_, v___x_1356_);
v___x_1407_ = l_List_appendTR___redArg(v___x_1404_, v___x_1406_);
v___x_1408_ = lp_lean1090_Lean1090_Impl_JSON_numeric(v_oracle_1314_, v_p_1317_);
v___x_1409_ = l_List_appendTR___redArg(v___x_1407_, v___x_1408_);
v___x_1410_ = l_List_appendTR___redArg(v_tag_1329_, v___x_1409_);
return v___x_1410_;
}
}
else
{
lean_object* v___x_1411_; lean_object* v___x_1412_; lean_object* v___x_1413_; lean_object* v___x_1414_; lean_object* v___x_1415_; lean_object* v___x_1416_; lean_object* v___x_1417_; lean_object* v___y_1419_; lean_object* v___x_1422_; lean_object* v___x_1423_; lean_object* v___x_1424_; uint8_t v___x_1425_; 
v___x_1411_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__17));
v___x_1412_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_1314_, v_p_1317_, v___x_1411_, v___x_1411_, v___x_1342_);
v___x_1413_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__18));
v___x_1414_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_1314_, v_p_1317_, v___x_1413_, v___x_1413_, v___x_1342_);
v___x_1415_ = l_List_appendTR___redArg(v___x_1412_, v___x_1414_);
lean_inc_ref(v_p_1317_);
v___x_1416_ = lp_lean1090_Lean1090_Impl_JSON_numeric(v_oracle_1314_, v_p_1317_);
v___x_1417_ = l_List_appendTR___redArg(v___x_1415_, v___x_1416_);
v___x_1422_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__19));
v___x_1423_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_1316_, v___x_1422_);
lean_dec_ref(v_record_1316_);
v___x_1424_ = lean_unsigned_to_nat(0u);
v___x_1425_ = lean_nat_dec_eq(v___x_1423_, v___x_1424_);
lean_dec(v___x_1423_);
if (v___x_1425_ == 0)
{
lean_object* v___x_1426_; lean_object* v___x_1427_; 
v___x_1426_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__20));
v___x_1427_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_1314_, v_p_1317_, v___x_1422_, v___x_1426_, v___x_1425_);
lean_dec_ref(v_p_1317_);
v___y_1419_ = v___x_1427_;
goto v___jp_1418_;
}
else
{
lean_dec_ref(v_p_1317_);
v___y_1419_ = v___x_1328_;
goto v___jp_1418_;
}
v___jp_1418_:
{
lean_object* v___x_1420_; lean_object* v___x_1421_; 
v___x_1420_ = l_List_appendTR___redArg(v___x_1417_, v___y_1419_);
v___x_1421_ = l_List_appendTR___redArg(v_tag_1329_, v___x_1420_);
return v___x_1421_;
}
}
}
else
{
lean_object* v___x_1428_; lean_object* v___x_1429_; lean_object* v___x_1430_; lean_object* v___y_1432_; lean_object* v___x_1436_; lean_object* v___x_1437_; uint8_t v___x_1438_; 
v___x_1428_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__21));
v___x_1429_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__26));
v___x_1430_ = lp_lean1090_Lean1090_Impl_JSON_booleans(v_record_1316_, v___x_1429_);
v___x_1436_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_record_1316_, v___x_1428_);
v___x_1437_ = lean_unsigned_to_nat(0u);
v___x_1438_ = lean_nat_dec_eq(v___x_1436_, v___x_1437_);
lean_dec(v___x_1436_);
if (v___x_1438_ == 0)
{
lean_object* v___x_1439_; lean_object* v___x_1440_; 
v___x_1439_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__46));
v___x_1440_ = lp_lean1090_Lean1090_Impl_JSON_booleans(v_record_1316_, v___x_1439_);
lean_dec_ref(v_record_1316_);
v___y_1432_ = v___x_1440_;
goto v___jp_1431_;
}
else
{
lean_dec_ref(v_record_1316_);
v___y_1432_ = v___x_1328_;
goto v___jp_1431_;
}
v___jp_1431_:
{
lean_object* v___x_1433_; 
v___x_1433_ = l_List_appendTR___redArg(v___x_1430_, v___y_1432_);
if (v_oracle_1314_ == 0)
{
lean_object* v___x_1434_; 
v___x_1434_ = lp_lean1090_Lean1090_Impl_JSON_standardThreat(v_p_1317_);
v___y_1337_ = v___x_1433_;
v___y_1338_ = v___x_1434_;
goto v___jp_1336_;
}
else
{
lean_object* v___x_1435_; 
v___x_1435_ = lp_lean1090_Lean1090_Impl_JSON_oracleThreat(v_p_1317_);
v___y_1337_ = v___x_1433_;
v___y_1338_ = v___x_1435_;
goto v___jp_1336_;
}
}
}
}
else
{
lean_object* v___x_1441_; lean_object* v___x_1442_; lean_object* v___x_1443_; lean_object* v___x_1444_; lean_object* v___x_1445_; lean_object* v___x_1446_; 
lean_dec_ref(v_record_1316_);
v___x_1441_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__47));
v___x_1442_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_1314_, v_p_1317_, v___x_1441_, v___x_1441_, v___x_1350_);
v___x_1443_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__48));
v___x_1444_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_1314_, v_p_1317_, v___x_1443_, v___x_1443_, v___x_1342_);
lean_dec_ref(v_p_1317_);
v___x_1445_ = l_List_appendTR___redArg(v___x_1442_, v___x_1444_);
v___x_1446_ = l_List_appendTR___redArg(v_tag_1329_, v___x_1445_);
return v___x_1446_;
}
}
else
{
lean_object* v___x_1447_; lean_object* v___x_1448_; lean_object* v___x_1449_; 
lean_dec_ref(v_record_1316_);
v___x_1447_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__77));
v___x_1448_ = lp_lean1090_Lean1090_Impl_JSON_textField(v_oracle_1314_, v_p_1317_, v___x_1447_, v___x_1447_, v___x_1348_);
lean_dec_ref(v_p_1317_);
v___x_1449_ = l_List_appendTR___redArg(v_tag_1329_, v___x_1448_);
return v___x_1449_;
}
}
else
{
lean_dec_ref(v_p_1317_);
v___y_1331_ = v___x_1348_;
goto v___jp_1330_;
}
}
else
{
lean_dec_ref(v_p_1317_);
v___y_1331_ = v___x_1342_;
goto v___jp_1330_;
}
}
else
{
lean_dec_ref(v_p_1317_);
v___y_1331_ = v___x_1342_;
goto v___jp_1330_;
}
}
else
{
lean_object* v___x_1450_; lean_object* v___x_1451_; lean_object* v___x_1452_; lean_object* v___x_1453_; lean_object* v___x_1454_; lean_object* v___x_1455_; lean_object* v___x_1456_; lean_object* v___x_1457_; lean_object* v___x_1458_; 
v___x_1450_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__70));
v___x_1451_ = lp_lean1090_Lean1090_Impl_JSON_booleans(v_record_1316_, v___x_1450_);
v___x_1452_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__72));
v___x_1453_ = lp_lean1090_Lean1090_Impl_JSON_naturals(v_record_1316_, v___x_1452_);
lean_dec_ref(v_record_1316_);
v___x_1454_ = l_List_appendTR___redArg(v___x_1451_, v___x_1453_);
v___x_1455_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_commB___closed__73));
v___x_1456_ = lp_lean1090_Lean1090_Impl_JSON_number(v_oracle_1314_, v_p_1317_, v___x_1455_, v___x_1455_, v___x_1321_);
lean_dec_ref(v_p_1317_);
v___x_1457_ = l_List_appendTR___redArg(v___x_1454_, v___x_1456_);
v___x_1458_ = l_List_appendTR___redArg(v_tag_1329_, v___x_1457_);
return v___x_1458_;
}
v___jp_1330_:
{
lean_object* v_fields_1332_; lean_object* v___x_1333_; lean_object* v___x_1334_; lean_object* v___x_1335_; 
v_fields_1332_ = lean_ctor_get(v_record_1316_, 1);
lean_inc(v_fields_1332_);
lean_dec_ref(v_record_1316_);
v___x_1333_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_numeric___closed__0));
v___x_1334_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_commB_spec__0(v___y_1331_, v_fields_1332_, v___x_1333_);
v___x_1335_ = l_List_appendTR___redArg(v_tag_1329_, v___x_1334_);
return v___x_1335_;
}
v___jp_1336_:
{
lean_object* v___x_1339_; lean_object* v___x_1340_; 
v___x_1339_ = l_List_appendTR___redArg(v___y_1337_, v___y_1338_);
v___x_1340_ = l_List_appendTR___redArg(v_tag_1329_, v___x_1339_);
return v___x_1340_;
}
}
else
{
lean_object* v___x_1459_; 
lean_dec_ref(v_p_1317_);
v___x_1459_ = lp_lean1090_Lean1090_Impl_JSON_operationStatus(v_record_1316_);
lean_dec_ref(v_record_1316_);
return v___x_1459_;
}
}
else
{
lean_object* v___x_1460_; lean_object* v___x_1461_; lean_object* v___x_1462_; 
v___x_1460_ = lp_lean1090_Lean1090_Impl_JSON_adsb(v_oracle_1314_, v_record_1316_, v_p_1317_);
lean_dec_ref(v_record_1316_);
v___x_1461_ = lean_box(0);
v___x_1462_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_JSON_commB_spec__2(v_register_1315_, v___x_1460_, v___x_1461_);
return v___x_1462_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_commB___boxed(lean_object* v_oracle_1463_, lean_object* v_register_1464_, lean_object* v_record_1465_, lean_object* v_p_1466_){
_start:
{
uint8_t v_oracle_boxed_1467_; lean_object* v_res_1468_; 
v_oracle_boxed_1467_ = lean_unbox(v_oracle_1463_);
v_res_1468_ = lp_lean1090_Lean1090_Impl_JSON_commB(v_oracle_boxed_1467_, v_register_1464_, v_record_1465_, v_p_1466_);
lean_dec(v_register_1464_);
return v_res_1468_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_altitude(uint8_t v_oracle_1469_, lean_object* v_message_1470_){
_start:
{
if (v_oracle_1469_ == 0)
{
lean_object* v_decoded_1471_; lean_object* v_altitude_1472_; lean_object* v___x_1473_; lean_object* v___y_1475_; 
v_decoded_1471_ = lean_ctor_get(v_message_1470_, 1);
lean_inc_ref(v_decoded_1471_);
lean_dec_ref(v_message_1470_);
v_altitude_1472_ = lean_ctor_get(v_decoded_1471_, 3);
lean_inc(v_altitude_1472_);
lean_dec_ref(v_decoded_1471_);
v___x_1473_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__2));
if (lean_obj_tag(v_altitude_1472_) == 0)
{
lean_object* v___x_1478_; lean_object* v___x_1479_; 
v___x_1478_ = lean_box(0);
v___x_1479_ = lp_lean1090_Lean1090_Impl_JSON_optional(v___x_1473_, v___x_1478_, v_oracle_1469_);
return v___x_1479_;
}
else
{
lean_object* v_val_1480_; 
v_val_1480_ = lean_ctor_get(v_altitude_1472_, 0);
lean_inc(v_val_1480_);
lean_dec_ref_known(v_altitude_1472_, 1);
if (lean_obj_tag(v_val_1480_) == 0)
{
lean_object* v_height_1481_; lean_object* v___x_1482_; 
v_height_1481_ = lean_ctor_get(v_val_1480_, 0);
lean_inc(v_height_1481_);
lean_dec_ref_known(v_val_1480_, 1);
v___x_1482_ = lp_lean1090_Lean1090_Impl_JSON_integer(v_height_1481_);
v___y_1475_ = v___x_1482_;
goto v___jp_1474_;
}
else
{
lean_object* v_height_1483_; lean_object* v___x_1484_; lean_object* v___x_1485_; 
v_height_1483_ = lean_ctor_get(v_val_1480_, 0);
lean_inc(v_height_1483_);
lean_dec_ref_known(v_val_1480_, 1);
v___x_1484_ = lean_nat_to_int(v_height_1483_);
v___x_1485_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_1484_);
v___y_1475_ = v___x_1485_;
goto v___jp_1474_;
}
}
v___jp_1474_:
{
lean_object* v___x_1476_; lean_object* v___x_1477_; 
v___x_1476_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1476_, 0, v___y_1475_);
v___x_1477_ = lp_lean1090_Lean1090_Impl_JSON_optional(v___x_1473_, v___x_1476_, v_oracle_1469_);
lean_dec_ref_known(v___x_1476_, 1);
return v___x_1477_;
}
}
else
{
lean_object* v_fields_1486_; lean_object* v___x_1487_; lean_object* v___y_1489_; lean_object* v___x_1492_; 
v_fields_1486_ = lean_ctor_get(v_message_1470_, 0);
lean_inc_ref(v_fields_1486_);
lean_dec_ref(v_message_1470_);
v___x_1487_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__2));
v___x_1492_ = lp_lean1090_Lean1090_Impl_frameOracleAltitude(v_fields_1486_);
lean_dec_ref(v_fields_1486_);
if (lean_obj_tag(v___x_1492_) == 0)
{
lean_object* v___x_1493_; 
v___x_1493_ = lean_box(0);
v___y_1489_ = v___x_1493_;
goto v___jp_1488_;
}
else
{
lean_object* v_val_1494_; lean_object* v___x_1496_; uint8_t v_isShared_1497_; uint8_t v_isSharedCheck_1502_; 
v_val_1494_ = lean_ctor_get(v___x_1492_, 0);
v_isSharedCheck_1502_ = !lean_is_exclusive(v___x_1492_);
if (v_isSharedCheck_1502_ == 0)
{
v___x_1496_ = v___x_1492_;
v_isShared_1497_ = v_isSharedCheck_1502_;
goto v_resetjp_1495_;
}
else
{
lean_inc(v_val_1494_);
lean_dec(v___x_1492_);
v___x_1496_ = lean_box(0);
v_isShared_1497_ = v_isSharedCheck_1502_;
goto v_resetjp_1495_;
}
v_resetjp_1495_:
{
lean_object* v___x_1498_; lean_object* v___x_1500_; 
v___x_1498_ = lp_lean1090_Lean1090_Impl_JSON_integer(v_val_1494_);
if (v_isShared_1497_ == 0)
{
lean_ctor_set(v___x_1496_, 0, v___x_1498_);
v___x_1500_ = v___x_1496_;
goto v_reusejp_1499_;
}
else
{
lean_object* v_reuseFailAlloc_1501_; 
v_reuseFailAlloc_1501_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1501_, 0, v___x_1498_);
v___x_1500_ = v_reuseFailAlloc_1501_;
goto v_reusejp_1499_;
}
v_reusejp_1499_:
{
v___y_1489_ = v___x_1500_;
goto v___jp_1488_;
}
}
}
v___jp_1488_:
{
uint8_t v___x_1490_; lean_object* v___x_1491_; 
v___x_1490_ = 0;
v___x_1491_ = lp_lean1090_Lean1090_Impl_JSON_optional(v___x_1487_, v___y_1489_, v___x_1490_);
lean_dec(v___y_1489_);
return v___x_1491_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_altitude___boxed(lean_object* v_oracle_1503_, lean_object* v_message_1504_){
_start:
{
uint8_t v_oracle_boxed_1505_; lean_object* v_res_1506_; 
v_oracle_boxed_1505_ = lean_unbox(v_oracle_1503_);
v_res_1506_ = lp_lean1090_Lean1090_Impl_JSON_altitude(v_oracle_boxed_1505_, v_message_1504_);
return v_res_1506_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_identity(lean_object* v_message_1507_){
_start:
{
lean_object* v_decoded_1508_; lean_object* v_identity_1509_; lean_object* v___x_1510_; lean_object* v___y_1512_; 
v_decoded_1508_ = lean_ctor_get(v_message_1507_, 1);
lean_inc_ref(v_decoded_1508_);
lean_dec_ref(v_message_1507_);
v_identity_1509_ = lean_ctor_get(v_decoded_1508_, 4);
lean_inc(v_identity_1509_);
lean_dec_ref(v_decoded_1508_);
v___x_1510_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__59));
if (lean_obj_tag(v_identity_1509_) == 0)
{
lean_object* v___x_1515_; 
v___x_1515_ = lean_box(0);
v___y_1512_ = v___x_1515_;
goto v___jp_1511_;
}
else
{
lean_object* v_val_1516_; lean_object* v___x_1518_; uint8_t v_isShared_1519_; uint8_t v_isSharedCheck_1527_; 
v_val_1516_ = lean_ctor_get(v_identity_1509_, 0);
v_isSharedCheck_1527_ = !lean_is_exclusive(v_identity_1509_);
if (v_isSharedCheck_1527_ == 0)
{
v___x_1518_ = v_identity_1509_;
v_isShared_1519_ = v_isSharedCheck_1527_;
goto v_resetjp_1517_;
}
else
{
lean_inc(v_val_1516_);
lean_dec(v_identity_1509_);
v___x_1518_ = lean_box(0);
v_isShared_1519_ = v_isSharedCheck_1527_;
goto v_resetjp_1517_;
}
v_resetjp_1517_:
{
lean_object* v___x_1520_; lean_object* v___x_1521_; lean_object* v___x_1522_; lean_object* v___x_1523_; lean_object* v___x_1525_; 
v___x_1520_ = lean_unsigned_to_nat(8u);
v___x_1521_ = lean_unsigned_to_nat(4u);
v___x_1522_ = lp_lean1090_Lean1090_Impl_JSON_digits(v___x_1520_, v___x_1521_, v_val_1516_);
lean_dec(v_val_1516_);
v___x_1523_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1523_, 0, v___x_1522_);
if (v_isShared_1519_ == 0)
{
lean_ctor_set(v___x_1518_, 0, v___x_1523_);
v___x_1525_ = v___x_1518_;
goto v_reusejp_1524_;
}
else
{
lean_object* v_reuseFailAlloc_1526_; 
v_reuseFailAlloc_1526_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1526_, 0, v___x_1523_);
v___x_1525_ = v_reuseFailAlloc_1526_;
goto v_reusejp_1524_;
}
v_reusejp_1524_:
{
v___y_1512_ = v___x_1525_;
goto v___jp_1511_;
}
}
}
v___jp_1511_:
{
uint8_t v___x_1513_; lean_object* v___x_1514_; 
v___x_1513_ = 0;
v___x_1514_ = lp_lean1090_Lean1090_Impl_JSON_optional(v___x_1510_, v___y_1512_, v___x_1513_);
lean_dec(v___y_1512_);
return v___x_1514_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_message_spec__0(lean_object* v_fst_1528_, lean_object* v_x_1529_){
_start:
{
if (lean_obj_tag(v_x_1529_) == 0)
{
lean_object* v___x_1530_; 
v___x_1530_ = lean_box(0);
return v___x_1530_;
}
else
{
lean_object* v_head_1531_; lean_object* v_tail_1532_; lean_object* v_fst_1533_; uint8_t v___x_1534_; 
v_head_1531_ = lean_ctor_get(v_x_1529_, 0);
v_tail_1532_ = lean_ctor_get(v_x_1529_, 1);
v_fst_1533_ = lean_ctor_get(v_head_1531_, 0);
v___x_1534_ = lean_nat_dec_eq(v_fst_1533_, v_fst_1528_);
if (v___x_1534_ == 0)
{
v_x_1529_ = v_tail_1532_;
goto _start;
}
else
{
lean_object* v___x_1536_; 
lean_inc(v_head_1531_);
v___x_1536_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1536_, 0, v_head_1531_);
return v___x_1536_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_message_spec__0___boxed(lean_object* v_fst_1537_, lean_object* v_x_1538_){
_start:
{
lean_object* v_res_1539_; 
v_res_1539_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_message_spec__0(v_fst_1537_, v_x_1538_);
lean_dec(v_x_1538_);
lean_dec(v_fst_1537_);
return v_res_1539_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_message_spec__1(lean_object* v___x_1540_, uint8_t v_oracle_1541_, lean_object* v_a_1542_, lean_object* v_a_1543_){
_start:
{
if (lean_obj_tag(v_a_1542_) == 0)
{
lean_object* v___x_1544_; 
v___x_1544_ = lean_array_to_list(v_a_1543_);
return v___x_1544_;
}
else
{
lean_object* v_head_1545_; lean_object* v_tail_1546_; lean_object* v_fst_1547_; lean_object* v_snd_1548_; lean_object* v_semanticCommB_1549_; lean_object* v___x_1550_; 
v_head_1545_ = lean_ctor_get(v_a_1542_, 0);
lean_inc(v_head_1545_);
v_tail_1546_ = lean_ctor_get(v_a_1542_, 1);
lean_inc(v_tail_1546_);
lean_dec_ref_known(v_a_1542_, 2);
v_fst_1547_ = lean_ctor_get(v_head_1545_, 0);
lean_inc(v_fst_1547_);
v_snd_1548_ = lean_ctor_get(v_head_1545_, 1);
lean_inc(v_snd_1548_);
lean_dec(v_head_1545_);
v_semanticCommB_1549_ = lean_ctor_get(v___x_1540_, 8);
v___x_1550_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_JSON_message_spec__0(v_fst_1547_, v_semanticCommB_1549_);
if (lean_obj_tag(v___x_1550_) == 0)
{
lean_dec(v_snd_1548_);
lean_dec(v_fst_1547_);
v_a_1542_ = v_tail_1546_;
goto _start;
}
else
{
lean_object* v_val_1552_; lean_object* v_snd_1553_; lean_object* v___x_1555_; uint8_t v_isShared_1556_; uint8_t v_isSharedCheck_1569_; 
v_val_1552_ = lean_ctor_get(v___x_1550_, 0);
lean_inc(v_val_1552_);
lean_dec_ref_known(v___x_1550_, 1);
v_snd_1553_ = lean_ctor_get(v_val_1552_, 1);
v_isSharedCheck_1569_ = !lean_is_exclusive(v_val_1552_);
if (v_isSharedCheck_1569_ == 0)
{
lean_object* v_unused_1570_; 
v_unused_1570_ = lean_ctor_get(v_val_1552_, 0);
lean_dec(v_unused_1570_);
v___x_1555_ = v_val_1552_;
v_isShared_1556_ = v_isSharedCheck_1569_;
goto v_resetjp_1554_;
}
else
{
lean_inc(v_snd_1553_);
lean_dec(v_val_1552_);
v___x_1555_ = lean_box(0);
v_isShared_1556_ = v_isSharedCheck_1569_;
goto v_resetjp_1554_;
}
v_resetjp_1554_:
{
lean_object* v___x_1557_; lean_object* v___x_1558_; lean_object* v___x_1559_; lean_object* v___x_1560_; lean_object* v___x_1561_; lean_object* v___x_1562_; lean_object* v___x_1563_; lean_object* v___x_1565_; 
v___x_1557_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_adsb___closed__1));
v___x_1558_ = lean_unsigned_to_nat(16u);
v___x_1559_ = lean_unsigned_to_nat(2u);
v___x_1560_ = lp_lean1090_Lean1090_Impl_JSON_digits(v___x_1558_, v___x_1559_, v_fst_1547_);
v___x_1561_ = lean_string_append(v___x_1557_, v___x_1560_);
lean_dec_ref(v___x_1560_);
v___x_1562_ = lp_lean1090_Lean1090_Impl_JSON_commB(v_oracle_1541_, v_fst_1547_, v_snd_1548_, v_snd_1553_);
lean_dec(v_fst_1547_);
v___x_1563_ = l_Lean_Json_mkObj(v___x_1562_);
lean_dec(v___x_1562_);
if (v_isShared_1556_ == 0)
{
lean_ctor_set(v___x_1555_, 1, v___x_1563_);
lean_ctor_set(v___x_1555_, 0, v___x_1561_);
v___x_1565_ = v___x_1555_;
goto v_reusejp_1564_;
}
else
{
lean_object* v_reuseFailAlloc_1568_; 
v_reuseFailAlloc_1568_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1568_, 0, v___x_1561_);
lean_ctor_set(v_reuseFailAlloc_1568_, 1, v___x_1563_);
v___x_1565_ = v_reuseFailAlloc_1568_;
goto v_reusejp_1564_;
}
v_reusejp_1564_:
{
lean_object* v___x_1566_; 
v___x_1566_ = lean_array_push(v_a_1543_, v___x_1565_);
v_a_1542_ = v_tail_1546_;
v_a_1543_ = v___x_1566_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_message_spec__1___boxed(lean_object* v___x_1571_, lean_object* v_oracle_1572_, lean_object* v_a_1573_, lean_object* v_a_1574_){
_start:
{
uint8_t v_oracle_boxed_1575_; lean_object* v_res_1576_; 
v_oracle_boxed_1575_ = lean_unbox(v_oracle_1572_);
v_res_1576_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_message_spec__1(v___x_1571_, v_oracle_boxed_1575_, v_a_1573_, v_a_1574_);
lean_dec_ref(v___x_1571_);
return v_res_1576_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_message_spec__2_spec__2(lean_object* v_md_1577_, lean_object* v_a_1578_, lean_object* v_a_1579_){
_start:
{
if (lean_obj_tag(v_a_1578_) == 0)
{
lean_object* v___x_1580_; 
lean_dec(v_md_1577_);
v___x_1580_ = l_List_reverse___redArg(v_a_1579_);
return v___x_1580_;
}
else
{
lean_object* v_head_1581_; lean_object* v_tail_1582_; lean_object* v___x_1584_; uint8_t v_isShared_1585_; uint8_t v_isSharedCheck_1598_; 
v_head_1581_ = lean_ctor_get(v_a_1578_, 0);
v_tail_1582_ = lean_ctor_get(v_a_1578_, 1);
v_isSharedCheck_1598_ = !lean_is_exclusive(v_a_1578_);
if (v_isSharedCheck_1598_ == 0)
{
v___x_1584_ = v_a_1578_;
v_isShared_1585_ = v_isSharedCheck_1598_;
goto v_resetjp_1583_;
}
else
{
lean_inc(v_tail_1582_);
lean_inc(v_head_1581_);
lean_dec(v_a_1578_);
v___x_1584_ = lean_box(0);
v_isShared_1585_ = v_isSharedCheck_1598_;
goto v_resetjp_1583_;
}
v_resetjp_1583_:
{
lean_object* v___x_1586_; lean_object* v___x_1587_; lean_object* v___x_1588_; lean_object* v___x_1589_; lean_object* v___x_1590_; lean_object* v___x_1591_; lean_object* v___x_1592_; lean_object* v___x_1593_; lean_object* v___x_1595_; 
lean_inc(v_md_1577_);
v___x_1586_ = lean_nat_to_int(v_md_1577_);
v___x_1587_ = lean_obj_once(&lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0, &lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0_once, _init_lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0);
v___x_1588_ = lean_unsigned_to_nat(9u);
v___x_1589_ = lean_nat_sub(v___x_1588_, v_head_1581_);
lean_dec(v_head_1581_);
v___x_1590_ = l_Int_pow(v___x_1587_, v___x_1589_);
lean_dec(v___x_1589_);
v___x_1591_ = lean_int_ediv(v___x_1586_, v___x_1590_);
lean_dec(v___x_1590_);
lean_dec(v___x_1586_);
v___x_1592_ = lean_int_emod(v___x_1591_, v___x_1587_);
lean_dec(v___x_1591_);
v___x_1593_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_1592_);
if (v_isShared_1585_ == 0)
{
lean_ctor_set(v___x_1584_, 1, v_a_1579_);
lean_ctor_set(v___x_1584_, 0, v___x_1593_);
v___x_1595_ = v___x_1584_;
goto v_reusejp_1594_;
}
else
{
lean_object* v_reuseFailAlloc_1597_; 
v_reuseFailAlloc_1597_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1597_, 0, v___x_1593_);
lean_ctor_set(v_reuseFailAlloc_1597_, 1, v_a_1579_);
v___x_1595_ = v_reuseFailAlloc_1597_;
goto v_reusejp_1594_;
}
v_reusejp_1594_:
{
v_a_1578_ = v_tail_1582_;
v_a_1579_ = v___x_1595_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_message_spec__2(lean_object* v_md_1599_, lean_object* v_a_1600_, lean_object* v_a_1601_){
_start:
{
if (lean_obj_tag(v_a_1600_) == 0)
{
lean_object* v___x_1602_; 
lean_dec(v_md_1599_);
v___x_1602_ = l_List_reverse___redArg(v_a_1601_);
return v___x_1602_;
}
else
{
lean_object* v_head_1603_; lean_object* v_tail_1604_; lean_object* v___x_1606_; uint8_t v_isShared_1607_; uint8_t v_isSharedCheck_1620_; 
v_head_1603_ = lean_ctor_get(v_a_1600_, 0);
v_tail_1604_ = lean_ctor_get(v_a_1600_, 1);
v_isSharedCheck_1620_ = !lean_is_exclusive(v_a_1600_);
if (v_isSharedCheck_1620_ == 0)
{
v___x_1606_ = v_a_1600_;
v_isShared_1607_ = v_isSharedCheck_1620_;
goto v_resetjp_1605_;
}
else
{
lean_inc(v_tail_1604_);
lean_inc(v_head_1603_);
lean_dec(v_a_1600_);
v___x_1606_ = lean_box(0);
v_isShared_1607_ = v_isSharedCheck_1620_;
goto v_resetjp_1605_;
}
v_resetjp_1605_:
{
lean_object* v___x_1608_; lean_object* v___x_1609_; lean_object* v___x_1610_; lean_object* v___x_1611_; lean_object* v___x_1612_; lean_object* v___x_1613_; lean_object* v___x_1614_; lean_object* v___x_1615_; lean_object* v___x_1617_; 
lean_inc(v_md_1599_);
v___x_1608_ = lean_nat_to_int(v_md_1599_);
v___x_1609_ = lean_obj_once(&lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0, &lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0_once, _init_lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_operationStatus_spec__0_spec__0___closed__0);
v___x_1610_ = lean_unsigned_to_nat(9u);
v___x_1611_ = lean_nat_sub(v___x_1610_, v_head_1603_);
lean_dec(v_head_1603_);
v___x_1612_ = l_Int_pow(v___x_1609_, v___x_1611_);
lean_dec(v___x_1611_);
v___x_1613_ = lean_int_ediv(v___x_1608_, v___x_1612_);
lean_dec(v___x_1612_);
lean_dec(v___x_1608_);
v___x_1614_ = lean_int_emod(v___x_1613_, v___x_1609_);
lean_dec(v___x_1613_);
v___x_1615_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_1614_);
if (v_isShared_1607_ == 0)
{
lean_ctor_set(v___x_1606_, 1, v_a_1601_);
lean_ctor_set(v___x_1606_, 0, v___x_1615_);
v___x_1617_ = v___x_1606_;
goto v_reusejp_1616_;
}
else
{
lean_object* v_reuseFailAlloc_1619_; 
v_reuseFailAlloc_1619_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1619_, 0, v___x_1615_);
lean_ctor_set(v_reuseFailAlloc_1619_, 1, v_a_1601_);
v___x_1617_ = v_reuseFailAlloc_1619_;
goto v_reusejp_1616_;
}
v_reusejp_1616_:
{
lean_object* v___x_1618_; 
v___x_1618_ = lp_lean1090_List_mapTR_loop___at___00List_mapTR_loop___at___00Lean1090_Impl_JSON_message_spec__2_spec__2(v_md_1599_, v_tail_1604_, v___x_1617_);
return v___x_1618_;
}
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_JSON_message___closed__63(void){
_start:
{
lean_object* v___x_1733_; lean_object* v___x_1734_; 
v___x_1733_ = lean_unsigned_to_nat(10u);
v___x_1734_ = l_List_range(v___x_1733_);
return v___x_1734_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_message(uint8_t v_oracle_1735_, lean_object* v_m_1736_){
_start:
{
lean_object* v___y_1738_; lean_object* v___y_1739_; lean_object* v___y_1743_; uint8_t v___y_1744_; lean_object* v___y_1745_; lean_object* v___y_1746_; lean_object* v_decoded_1755_; lean_object* v_fields_1756_; lean_object* v_address_1757_; lean_object* v_adsb_1758_; lean_object* v_commB_1759_; lean_object* v_semanticADSB_1760_; lean_object* v___y_1762_; lean_object* v___y_1763_; lean_object* v___y_1764_; lean_object* v___y_1770_; uint8_t v___y_1771_; lean_object* v___y_1772_; lean_object* v___y_1773_; lean_object* v___y_1781_; lean_object* v___y_1782_; lean_object* v___y_1783_; lean_object* v___y_1784_; lean_object* v___y_1793_; lean_object* v___y_1794_; uint8_t v___y_1795_; lean_object* v___y_1796_; lean_object* v___y_1797_; lean_object* v___x_1809_; lean_object* v___y_1811_; 
v_decoded_1755_ = lean_ctor_get(v_m_1736_, 1);
v_fields_1756_ = lean_ctor_get(v_m_1736_, 0);
lean_inc_ref(v_fields_1756_);
v_address_1757_ = lean_ctor_get(v_decoded_1755_, 1);
lean_inc(v_address_1757_);
v_adsb_1758_ = lean_ctor_get(v_decoded_1755_, 5);
v_commB_1759_ = lean_ctor_get(v_decoded_1755_, 6);
v_semanticADSB_1760_ = lean_ctor_get(v_decoded_1755_, 7);
v___x_1809_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__17));
if (lean_obj_tag(v_address_1757_) == 0)
{
lean_object* v___x_1963_; 
v___x_1963_ = lean_box(0);
v___y_1811_ = v___x_1963_;
goto v___jp_1810_;
}
else
{
lean_object* v_val_1964_; lean_object* v___x_1966_; uint8_t v_isShared_1967_; uint8_t v_isSharedCheck_1975_; 
v_val_1964_ = lean_ctor_get(v_address_1757_, 0);
v_isSharedCheck_1975_ = !lean_is_exclusive(v_address_1757_);
if (v_isSharedCheck_1975_ == 0)
{
v___x_1966_ = v_address_1757_;
v_isShared_1967_ = v_isSharedCheck_1975_;
goto v_resetjp_1965_;
}
else
{
lean_inc(v_val_1964_);
lean_dec(v_address_1757_);
v___x_1966_ = lean_box(0);
v_isShared_1967_ = v_isSharedCheck_1975_;
goto v_resetjp_1965_;
}
v_resetjp_1965_:
{
lean_object* v___x_1968_; lean_object* v___x_1969_; lean_object* v___x_1970_; lean_object* v___x_1971_; lean_object* v___x_1973_; 
v___x_1968_ = lean_unsigned_to_nat(16u);
v___x_1969_ = lean_unsigned_to_nat(6u);
v___x_1970_ = lp_lean1090_Lean1090_Impl_JSON_digits(v___x_1968_, v___x_1969_, v_val_1964_);
lean_dec(v_val_1964_);
v___x_1971_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1971_, 0, v___x_1970_);
if (v_isShared_1967_ == 0)
{
lean_ctor_set(v___x_1966_, 0, v___x_1971_);
v___x_1973_ = v___x_1966_;
goto v_reusejp_1972_;
}
else
{
lean_object* v_reuseFailAlloc_1974_; 
v_reuseFailAlloc_1974_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1974_, 0, v___x_1971_);
v___x_1973_ = v_reuseFailAlloc_1974_;
goto v_reusejp_1972_;
}
v_reusejp_1972_:
{
v___y_1811_ = v___x_1973_;
goto v___jp_1810_;
}
}
}
v___jp_1737_:
{
lean_object* v___x_1740_; lean_object* v___x_1741_; 
v___x_1740_ = l_List_appendTR___redArg(v___y_1738_, v___y_1739_);
v___x_1741_ = l_Lean_Json_mkObj(v___x_1740_);
lean_dec(v___x_1740_);
return v___x_1741_;
}
v___jp_1742_:
{
lean_object* v___x_1747_; lean_object* v___x_1748_; lean_object* v___x_1749_; lean_object* v___x_1750_; 
lean_inc_ref(v___y_1746_);
v___x_1747_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1747_, 0, v___y_1746_);
lean_inc_ref(v___y_1743_);
v___x_1748_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1748_, 0, v___y_1743_);
lean_ctor_set(v___x_1748_, 1, v___x_1747_);
v___x_1749_ = lean_box(0);
v___x_1750_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1750_, 0, v___x_1748_);
lean_ctor_set(v___x_1750_, 1, v___x_1749_);
if (v___y_1744_ == 0)
{
lean_object* v___x_1751_; lean_object* v___x_1752_; 
v___x_1751_ = lp_lean1090_Lean1090_Impl_JSON_altitude(v_oracle_1735_, v_m_1736_);
v___x_1752_ = l_List_appendTR___redArg(v___x_1750_, v___x_1751_);
v___y_1738_ = v___y_1745_;
v___y_1739_ = v___x_1752_;
goto v___jp_1737_;
}
else
{
lean_object* v___x_1753_; lean_object* v___x_1754_; 
v___x_1753_ = lp_lean1090_Lean1090_Impl_JSON_identity(v_m_1736_);
v___x_1754_ = l_List_appendTR___redArg(v___x_1750_, v___x_1753_);
v___y_1738_ = v___y_1745_;
v___y_1739_ = v___x_1754_;
goto v___jp_1737_;
}
}
v___jp_1761_:
{
lean_object* v___x_1765_; lean_object* v___x_1766_; lean_object* v___x_1767_; lean_object* v___x_1768_; 
v___x_1765_ = l_List_appendTR___redArg(v___y_1763_, v___y_1764_);
v___x_1766_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_numeric___closed__0));
v___x_1767_ = lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_JSON_message_spec__1(v_decoded_1755_, v_oracle_1735_, v_commB_1759_, v___x_1766_);
lean_dec_ref(v_decoded_1755_);
v___x_1768_ = l_List_appendTR___redArg(v___x_1765_, v___x_1767_);
v___y_1738_ = v___y_1762_;
v___y_1739_ = v___x_1768_;
goto v___jp_1737_;
}
v___jp_1769_:
{
lean_object* v___x_1774_; lean_object* v___x_1775_; lean_object* v___x_1776_; lean_object* v___x_1777_; 
lean_inc_ref(v___y_1773_);
v___x_1774_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1774_, 0, v___y_1773_);
lean_inc_ref(v___y_1770_);
v___x_1775_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1775_, 0, v___y_1770_);
lean_ctor_set(v___x_1775_, 1, v___x_1774_);
v___x_1776_ = lean_box(0);
v___x_1777_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1777_, 0, v___x_1775_);
lean_ctor_set(v___x_1777_, 1, v___x_1776_);
if (v___y_1771_ == 0)
{
lean_object* v___x_1778_; 
v___x_1778_ = lp_lean1090_Lean1090_Impl_JSON_altitude(v_oracle_1735_, v_m_1736_);
v___y_1762_ = v___y_1772_;
v___y_1763_ = v___x_1777_;
v___y_1764_ = v___x_1778_;
goto v___jp_1761_;
}
else
{
lean_object* v___x_1779_; 
v___x_1779_ = lp_lean1090_Lean1090_Impl_JSON_identity(v_m_1736_);
v___y_1762_ = v___y_1772_;
v___y_1763_ = v___x_1777_;
v___y_1764_ = v___x_1779_;
goto v___jp_1761_;
}
}
v___jp_1780_:
{
lean_object* v___x_1785_; 
v___x_1785_ = l_List_appendTR___redArg(v___y_1783_, v___y_1784_);
if (lean_obj_tag(v_adsb_1758_) == 1)
{
if (lean_obj_tag(v_semanticADSB_1760_) == 1)
{
lean_object* v_val_1786_; lean_object* v_val_1787_; lean_object* v___x_1788_; lean_object* v___x_1789_; 
lean_dec(v___y_1781_);
v_val_1786_ = lean_ctor_get(v_adsb_1758_, 0);
lean_inc(v_val_1786_);
lean_dec_ref_known(v_adsb_1758_, 1);
v_val_1787_ = lean_ctor_get(v_semanticADSB_1760_, 0);
lean_inc(v_val_1787_);
lean_dec_ref_known(v_semanticADSB_1760_, 1);
v___x_1788_ = lp_lean1090_Lean1090_Impl_JSON_adsb(v_oracle_1735_, v_val_1786_, v_val_1787_);
lean_dec(v_val_1786_);
v___x_1789_ = l_List_appendTR___redArg(v___x_1785_, v___x_1788_);
v___y_1738_ = v___y_1782_;
v___y_1739_ = v___x_1789_;
goto v___jp_1737_;
}
else
{
lean_object* v___x_1790_; 
lean_dec_ref_known(v_adsb_1758_, 1);
lean_dec(v_semanticADSB_1760_);
v___x_1790_ = l_List_appendTR___redArg(v___x_1785_, v___y_1781_);
v___y_1738_ = v___y_1782_;
v___y_1739_ = v___x_1790_;
goto v___jp_1737_;
}
}
else
{
lean_object* v___x_1791_; 
lean_dec(v_semanticADSB_1760_);
lean_dec(v_adsb_1758_);
v___x_1791_ = l_List_appendTR___redArg(v___x_1785_, v___y_1781_);
v___y_1738_ = v___y_1782_;
v___y_1739_ = v___x_1791_;
goto v___jp_1737_;
}
}
v___jp_1792_:
{
lean_object* v___x_1798_; lean_object* v___x_1799_; lean_object* v___x_1800_; lean_object* v___x_1801_; 
lean_inc_ref(v___y_1797_);
v___x_1798_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1798_, 0, v___y_1797_);
lean_inc_ref(v___y_1794_);
v___x_1799_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1799_, 0, v___y_1794_);
lean_ctor_set(v___x_1799_, 1, v___x_1798_);
v___x_1800_ = lean_box(0);
v___x_1801_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1801_, 0, v___x_1799_);
lean_ctor_set(v___x_1801_, 1, v___x_1800_);
if (v___y_1795_ == 0)
{
lean_dec(v___y_1796_);
v___y_1781_ = v___x_1800_;
v___y_1782_ = v___y_1793_;
v___y_1783_ = v___x_1801_;
v___y_1784_ = v___x_1800_;
goto v___jp_1780_;
}
else
{
lean_object* v___x_1802_; lean_object* v___x_1803_; lean_object* v___x_1804_; lean_object* v___x_1805_; lean_object* v___x_1806_; lean_object* v___x_1807_; lean_object* v___x_1808_; 
v___x_1802_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__0));
v___x_1803_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__8));
v___x_1804_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__16));
v___x_1805_ = l_List_getD___redArg(v___x_1804_, v___y_1796_, v___x_1803_);
v___x_1806_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1806_, 0, v___x_1805_);
v___x_1807_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1807_, 0, v___x_1802_);
lean_ctor_set(v___x_1807_, 1, v___x_1806_);
v___x_1808_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1808_, 0, v___x_1807_);
lean_ctor_set(v___x_1808_, 1, v___x_1800_);
v___y_1781_ = v___x_1800_;
v___y_1782_ = v___y_1793_;
v___y_1783_ = v___x_1801_;
v___y_1784_ = v___x_1808_;
goto v___jp_1780_;
}
}
v___jp_1810_:
{
lean_object* v_body_1812_; lean_object* v_parity_1813_; lean_object* v___x_1815_; uint8_t v_isShared_1816_; uint8_t v_isSharedCheck_1962_; 
v_body_1812_ = lean_ctor_get(v_fields_1756_, 0);
v_parity_1813_ = lean_ctor_get(v_fields_1756_, 1);
v_isSharedCheck_1962_ = !lean_is_exclusive(v_fields_1756_);
if (v_isSharedCheck_1962_ == 0)
{
v___x_1815_ = v_fields_1756_;
v_isShared_1816_ = v_isSharedCheck_1962_;
goto v_resetjp_1814_;
}
else
{
lean_inc(v_parity_1813_);
lean_inc(v_body_1812_);
lean_dec(v_fields_1756_);
v___x_1815_ = lean_box(0);
v_isShared_1816_ = v_isSharedCheck_1962_;
goto v_resetjp_1814_;
}
v_resetjp_1814_:
{
uint8_t v___x_1817_; lean_object* v_address_1818_; 
v___x_1817_ = 1;
v_address_1818_ = lp_lean1090_Lean1090_Impl_JSON_optional(v___x_1809_, v___y_1811_, v___x_1817_);
lean_dec(v___y_1811_);
switch(lean_obj_tag(v_body_1812_))
{
case 0:
{
lean_object* v___x_1819_; lean_object* v___x_1820_; lean_object* v___x_1821_; 
lean_dec_ref_known(v_body_1812_, 1);
lean_del_object(v___x_1815_);
lean_dec(v_parity_1813_);
v___x_1819_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__22));
v___x_1820_ = lp_lean1090_Lean1090_Impl_JSON_altitude(v_oracle_1735_, v_m_1736_);
v___x_1821_ = l_List_appendTR___redArg(v___x_1819_, v___x_1820_);
v___y_1738_ = v_address_1818_;
v___y_1739_ = v___x_1821_;
goto v___jp_1737_;
}
case 1:
{
uint8_t v_identity_1822_; lean_object* v___x_1823_; 
lean_del_object(v___x_1815_);
lean_dec(v_parity_1813_);
v_identity_1822_ = lean_ctor_get_uint8(v_body_1812_, sizeof(void*)*1);
lean_dec_ref_known(v_body_1812_, 1);
v___x_1823_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__18));
if (v_identity_1822_ == 0)
{
lean_object* v___x_1824_; 
v___x_1824_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__23));
v___y_1743_ = v___x_1823_;
v___y_1744_ = v_identity_1822_;
v___y_1745_ = v_address_1818_;
v___y_1746_ = v___x_1824_;
goto v___jp_1742_;
}
else
{
lean_object* v___x_1825_; 
v___x_1825_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__24));
v___y_1743_ = v___x_1823_;
v___y_1744_ = v_identity_1822_;
v___y_1745_ = v_address_1818_;
v___y_1746_ = v___x_1825_;
goto v___jp_1742_;
}
}
case 2:
{
lean_object* v___x_1827_; uint8_t v_isShared_1828_; uint8_t v_isSharedCheck_1851_; 
lean_dec(v_parity_1813_);
v_isSharedCheck_1851_ = !lean_is_exclusive(v_m_1736_);
if (v_isSharedCheck_1851_ == 0)
{
lean_object* v_unused_1852_; lean_object* v_unused_1853_; 
v_unused_1852_ = lean_ctor_get(v_m_1736_, 1);
lean_dec(v_unused_1852_);
v_unused_1853_ = lean_ctor_get(v_m_1736_, 0);
lean_dec(v_unused_1853_);
v___x_1827_ = v_m_1736_;
v_isShared_1828_ = v_isSharedCheck_1851_;
goto v_resetjp_1826_;
}
else
{
lean_dec(v_m_1736_);
v___x_1827_ = lean_box(0);
v_isShared_1828_ = v_isSharedCheck_1851_;
goto v_resetjp_1826_;
}
v_resetjp_1826_:
{
lean_object* v_ca_1829_; lean_object* v___x_1831_; uint8_t v_isShared_1832_; uint8_t v_isSharedCheck_1849_; 
v_ca_1829_ = lean_ctor_get(v_body_1812_, 0);
v_isSharedCheck_1849_ = !lean_is_exclusive(v_body_1812_);
if (v_isSharedCheck_1849_ == 0)
{
lean_object* v_unused_1850_; 
v_unused_1850_ = lean_ctor_get(v_body_1812_, 1);
lean_dec(v_unused_1850_);
v___x_1831_ = v_body_1812_;
v_isShared_1832_ = v_isSharedCheck_1849_;
goto v_resetjp_1830_;
}
else
{
lean_inc(v_ca_1829_);
lean_dec(v_body_1812_);
v___x_1831_ = lean_box(0);
v_isShared_1832_ = v_isSharedCheck_1849_;
goto v_resetjp_1830_;
}
v_resetjp_1830_:
{
lean_object* v___x_1833_; lean_object* v___x_1834_; lean_object* v___x_1835_; lean_object* v___x_1836_; lean_object* v___x_1837_; lean_object* v___x_1838_; lean_object* v___x_1839_; lean_object* v___x_1841_; 
v___x_1833_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__27));
v___x_1834_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__28));
v___x_1835_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__30));
v___x_1836_ = lean_box(0);
v___x_1837_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__42));
v___x_1838_ = l_List_getD___redArg(v___x_1837_, v_ca_1829_, v___x_1835_);
v___x_1839_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1839_, 0, v___x_1838_);
if (v_isShared_1832_ == 0)
{
lean_ctor_set_tag(v___x_1831_, 0);
lean_ctor_set(v___x_1831_, 1, v___x_1839_);
lean_ctor_set(v___x_1831_, 0, v___x_1834_);
v___x_1841_ = v___x_1831_;
goto v_reusejp_1840_;
}
else
{
lean_object* v_reuseFailAlloc_1848_; 
v_reuseFailAlloc_1848_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1848_, 0, v___x_1834_);
lean_ctor_set(v_reuseFailAlloc_1848_, 1, v___x_1839_);
v___x_1841_ = v_reuseFailAlloc_1848_;
goto v_reusejp_1840_;
}
v_reusejp_1840_:
{
lean_object* v___x_1843_; 
if (v_isShared_1816_ == 0)
{
lean_ctor_set_tag(v___x_1815_, 1);
lean_ctor_set(v___x_1815_, 1, v___x_1836_);
lean_ctor_set(v___x_1815_, 0, v___x_1841_);
v___x_1843_ = v___x_1815_;
goto v_reusejp_1842_;
}
else
{
lean_object* v_reuseFailAlloc_1847_; 
v_reuseFailAlloc_1847_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1847_, 0, v___x_1841_);
lean_ctor_set(v_reuseFailAlloc_1847_, 1, v___x_1836_);
v___x_1843_ = v_reuseFailAlloc_1847_;
goto v_reusejp_1842_;
}
v_reusejp_1842_:
{
lean_object* v___x_1845_; 
if (v_isShared_1828_ == 0)
{
lean_ctor_set_tag(v___x_1827_, 1);
lean_ctor_set(v___x_1827_, 1, v___x_1843_);
lean_ctor_set(v___x_1827_, 0, v___x_1833_);
v___x_1845_ = v___x_1827_;
goto v_reusejp_1844_;
}
else
{
lean_object* v_reuseFailAlloc_1846_; 
v_reuseFailAlloc_1846_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1846_, 0, v___x_1833_);
lean_ctor_set(v_reuseFailAlloc_1846_, 1, v___x_1843_);
v___x_1845_ = v_reuseFailAlloc_1846_;
goto v_reusejp_1844_;
}
v_reusejp_1844_:
{
v___y_1738_ = v_address_1818_;
v___y_1739_ = v___x_1845_;
goto v___jp_1737_;
}
}
}
}
}
}
case 3:
{
lean_object* v_fields_1854_; lean_object* v___x_1856_; uint8_t v_isShared_1857_; uint8_t v_isSharedCheck_1885_; 
lean_dec(v_parity_1813_);
v_fields_1854_ = lean_ctor_get(v_body_1812_, 0);
v_isSharedCheck_1885_ = !lean_is_exclusive(v_body_1812_);
if (v_isSharedCheck_1885_ == 0)
{
lean_object* v_unused_1886_; 
v_unused_1886_ = lean_ctor_get(v_body_1812_, 1);
lean_dec(v_unused_1886_);
v___x_1856_ = v_body_1812_;
v_isShared_1857_ = v_isSharedCheck_1885_;
goto v_resetjp_1855_;
}
else
{
lean_inc(v_fields_1854_);
lean_dec(v_body_1812_);
v___x_1856_ = lean_box(0);
v_isShared_1857_ = v_isSharedCheck_1885_;
goto v_resetjp_1855_;
}
v_resetjp_1855_:
{
lean_object* v_vs_1858_; lean_object* v_sl_1859_; lean_object* v_ri_1860_; lean_object* v___x_1861_; lean_object* v___x_1862_; lean_object* v___x_1863_; lean_object* v___x_1864_; lean_object* v___x_1866_; 
v_vs_1858_ = lean_ctor_get(v_fields_1854_, 0);
lean_inc(v_vs_1858_);
v_sl_1859_ = lean_ctor_get(v_fields_1854_, 3);
lean_inc(v_sl_1859_);
v_ri_1860_ = lean_ctor_get(v_fields_1854_, 5);
lean_inc(v_ri_1860_);
lean_dec_ref(v_fields_1854_);
v___x_1861_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__45));
v___x_1862_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__46));
v___x_1863_ = lean_nat_to_int(v_vs_1858_);
v___x_1864_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_1863_);
if (v_isShared_1857_ == 0)
{
lean_ctor_set_tag(v___x_1856_, 0);
lean_ctor_set(v___x_1856_, 1, v___x_1864_);
lean_ctor_set(v___x_1856_, 0, v___x_1862_);
v___x_1866_ = v___x_1856_;
goto v_reusejp_1865_;
}
else
{
lean_object* v_reuseFailAlloc_1884_; 
v_reuseFailAlloc_1884_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1884_, 0, v___x_1862_);
lean_ctor_set(v_reuseFailAlloc_1884_, 1, v___x_1864_);
v___x_1866_ = v_reuseFailAlloc_1884_;
goto v_reusejp_1865_;
}
v_reusejp_1865_:
{
lean_object* v___x_1867_; lean_object* v___x_1868_; lean_object* v___x_1869_; lean_object* v___x_1871_; 
v___x_1867_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__47));
v___x_1868_ = lean_nat_to_int(v_sl_1859_);
v___x_1869_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_1868_);
if (v_isShared_1816_ == 0)
{
lean_ctor_set(v___x_1815_, 1, v___x_1869_);
lean_ctor_set(v___x_1815_, 0, v___x_1867_);
v___x_1871_ = v___x_1815_;
goto v_reusejp_1870_;
}
else
{
lean_object* v_reuseFailAlloc_1883_; 
v_reuseFailAlloc_1883_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1883_, 0, v___x_1867_);
lean_ctor_set(v_reuseFailAlloc_1883_, 1, v___x_1869_);
v___x_1871_ = v_reuseFailAlloc_1883_;
goto v_reusejp_1870_;
}
v_reusejp_1870_:
{
lean_object* v___x_1872_; lean_object* v___x_1873_; lean_object* v___x_1874_; lean_object* v___x_1875_; lean_object* v___x_1876_; lean_object* v___x_1877_; lean_object* v___x_1878_; lean_object* v___x_1879_; lean_object* v___x_1880_; lean_object* v___x_1881_; lean_object* v___x_1882_; 
v___x_1872_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__48));
v___x_1873_ = lean_nat_to_int(v_ri_1860_);
v___x_1874_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_1873_);
v___x_1875_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1875_, 0, v___x_1872_);
lean_ctor_set(v___x_1875_, 1, v___x_1874_);
v___x_1876_ = lean_box(0);
v___x_1877_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1877_, 0, v___x_1875_);
lean_ctor_set(v___x_1877_, 1, v___x_1876_);
v___x_1878_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1878_, 0, v___x_1871_);
lean_ctor_set(v___x_1878_, 1, v___x_1877_);
v___x_1879_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1879_, 0, v___x_1866_);
lean_ctor_set(v___x_1879_, 1, v___x_1878_);
v___x_1880_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1880_, 0, v___x_1861_);
lean_ctor_set(v___x_1880_, 1, v___x_1879_);
v___x_1881_ = lp_lean1090_Lean1090_Impl_JSON_altitude(v_oracle_1735_, v_m_1736_);
v___x_1882_ = l_List_appendTR___redArg(v___x_1880_, v___x_1881_);
v___y_1738_ = v_address_1818_;
v___y_1739_ = v___x_1882_;
goto v___jp_1737_;
}
}
}
}
case 4:
{
uint8_t v_supplementary_1887_; lean_object* v_control_1888_; lean_object* v___x_1889_; 
lean_inc(v_semanticADSB_1760_);
lean_inc(v_adsb_1758_);
lean_del_object(v___x_1815_);
lean_dec(v_parity_1813_);
lean_dec_ref(v_m_1736_);
v_supplementary_1887_ = lean_ctor_get_uint8(v_body_1812_, sizeof(void*)*3);
v_control_1888_ = lean_ctor_get(v_body_1812_, 0);
lean_inc(v_control_1888_);
lean_dec_ref_known(v_body_1812_, 3);
v___x_1889_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__18));
if (v_supplementary_1887_ == 0)
{
lean_object* v___x_1890_; 
v___x_1890_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__49));
v___y_1793_ = v_address_1818_;
v___y_1794_ = v___x_1889_;
v___y_1795_ = v_supplementary_1887_;
v___y_1796_ = v_control_1888_;
v___y_1797_ = v___x_1890_;
goto v___jp_1792_;
}
else
{
lean_object* v___x_1891_; 
v___x_1891_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__50));
v___y_1793_ = v_address_1818_;
v___y_1794_ = v___x_1889_;
v___y_1795_ = v_supplementary_1887_;
v___y_1796_ = v_control_1888_;
v___y_1797_ = v___x_1891_;
goto v___jp_1792_;
}
}
case 5:
{
lean_object* v___x_1893_; uint8_t v_isShared_1894_; uint8_t v_isSharedCheck_1915_; 
lean_dec(v_parity_1813_);
v_isSharedCheck_1915_ = !lean_is_exclusive(v_m_1736_);
if (v_isSharedCheck_1915_ == 0)
{
lean_object* v_unused_1916_; lean_object* v_unused_1917_; 
v_unused_1916_ = lean_ctor_get(v_m_1736_, 1);
lean_dec(v_unused_1916_);
v_unused_1917_ = lean_ctor_get(v_m_1736_, 0);
lean_dec(v_unused_1917_);
v___x_1893_ = v_m_1736_;
v_isShared_1894_ = v_isSharedCheck_1915_;
goto v_resetjp_1892_;
}
else
{
lean_dec(v_m_1736_);
v___x_1893_ = lean_box(0);
v_isShared_1894_ = v_isSharedCheck_1915_;
goto v_resetjp_1892_;
}
v_resetjp_1892_:
{
lean_object* v_af_1895_; lean_object* v___x_1897_; uint8_t v_isShared_1898_; uint8_t v_isSharedCheck_1913_; 
v_af_1895_ = lean_ctor_get(v_body_1812_, 0);
v_isSharedCheck_1913_ = !lean_is_exclusive(v_body_1812_);
if (v_isSharedCheck_1913_ == 0)
{
lean_object* v_unused_1914_; 
v_unused_1914_ = lean_ctor_get(v_body_1812_, 1);
lean_dec(v_unused_1914_);
v___x_1897_ = v_body_1812_;
v_isShared_1898_ = v_isSharedCheck_1913_;
goto v_resetjp_1896_;
}
else
{
lean_inc(v_af_1895_);
lean_dec(v_body_1812_);
v___x_1897_ = lean_box(0);
v_isShared_1898_ = v_isSharedCheck_1913_;
goto v_resetjp_1896_;
}
v_resetjp_1896_:
{
lean_object* v___x_1899_; lean_object* v___x_1900_; lean_object* v___x_1901_; lean_object* v___x_1902_; lean_object* v___x_1904_; 
v___x_1899_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__53));
v___x_1900_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__54));
v___x_1901_ = lean_nat_to_int(v_af_1895_);
v___x_1902_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_1901_);
if (v_isShared_1898_ == 0)
{
lean_ctor_set_tag(v___x_1897_, 0);
lean_ctor_set(v___x_1897_, 1, v___x_1902_);
lean_ctor_set(v___x_1897_, 0, v___x_1900_);
v___x_1904_ = v___x_1897_;
goto v_reusejp_1903_;
}
else
{
lean_object* v_reuseFailAlloc_1912_; 
v_reuseFailAlloc_1912_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1912_, 0, v___x_1900_);
lean_ctor_set(v_reuseFailAlloc_1912_, 1, v___x_1902_);
v___x_1904_ = v_reuseFailAlloc_1912_;
goto v_reusejp_1903_;
}
v_reusejp_1903_:
{
lean_object* v___x_1905_; lean_object* v___x_1907_; 
v___x_1905_ = lean_box(0);
if (v_isShared_1816_ == 0)
{
lean_ctor_set_tag(v___x_1815_, 1);
lean_ctor_set(v___x_1815_, 1, v___x_1905_);
lean_ctor_set(v___x_1815_, 0, v___x_1904_);
v___x_1907_ = v___x_1815_;
goto v_reusejp_1906_;
}
else
{
lean_object* v_reuseFailAlloc_1911_; 
v_reuseFailAlloc_1911_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1911_, 0, v___x_1904_);
lean_ctor_set(v_reuseFailAlloc_1911_, 1, v___x_1905_);
v___x_1907_ = v_reuseFailAlloc_1911_;
goto v_reusejp_1906_;
}
v_reusejp_1906_:
{
lean_object* v___x_1909_; 
if (v_isShared_1894_ == 0)
{
lean_ctor_set_tag(v___x_1893_, 1);
lean_ctor_set(v___x_1893_, 1, v___x_1907_);
lean_ctor_set(v___x_1893_, 0, v___x_1899_);
v___x_1909_ = v___x_1893_;
goto v_reusejp_1908_;
}
else
{
lean_object* v_reuseFailAlloc_1910_; 
v_reuseFailAlloc_1910_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1910_, 0, v___x_1899_);
lean_ctor_set(v_reuseFailAlloc_1910_, 1, v___x_1907_);
v___x_1909_ = v_reuseFailAlloc_1910_;
goto v_reusejp_1908_;
}
v_reusejp_1908_:
{
v___y_1738_ = v_address_1818_;
v___y_1739_ = v___x_1909_;
goto v___jp_1737_;
}
}
}
}
}
}
case 6:
{
uint8_t v_identity_1918_; lean_object* v___x_1919_; 
lean_inc(v_commB_1759_);
lean_inc_ref(v_decoded_1755_);
lean_del_object(v___x_1815_);
lean_dec(v_parity_1813_);
v_identity_1918_ = lean_ctor_get_uint8(v_body_1812_, sizeof(void*)*2);
lean_dec_ref_known(v_body_1812_, 2);
v___x_1919_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__18));
if (v_identity_1918_ == 0)
{
lean_object* v___x_1920_; 
v___x_1920_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__55));
v___y_1770_ = v___x_1919_;
v___y_1771_ = v_identity_1918_;
v___y_1772_ = v_address_1818_;
v___y_1773_ = v___x_1920_;
goto v___jp_1769_;
}
else
{
lean_object* v___x_1921_; 
v___x_1921_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__56));
v___y_1770_ = v___x_1919_;
v___y_1771_ = v_identity_1918_;
v___y_1772_ = v_address_1818_;
v___y_1773_ = v___x_1921_;
goto v___jp_1769_;
}
}
default: 
{
lean_object* v___x_1923_; uint8_t v_isShared_1924_; uint8_t v_isSharedCheck_1959_; 
v_isSharedCheck_1959_ = !lean_is_exclusive(v_m_1736_);
if (v_isSharedCheck_1959_ == 0)
{
lean_object* v_unused_1960_; lean_object* v_unused_1961_; 
v_unused_1960_ = lean_ctor_get(v_m_1736_, 1);
lean_dec(v_unused_1960_);
v_unused_1961_ = lean_ctor_get(v_m_1736_, 0);
lean_dec(v_unused_1961_);
v___x_1923_ = v_m_1736_;
v_isShared_1924_ = v_isSharedCheck_1959_;
goto v_resetjp_1922_;
}
else
{
lean_dec(v_m_1736_);
v___x_1923_ = lean_box(0);
v_isShared_1924_ = v_isSharedCheck_1959_;
goto v_resetjp_1922_;
}
v_resetjp_1922_:
{
lean_object* v_spare_1925_; lean_object* v_nd_1926_; lean_object* v_md_1927_; lean_object* v___x_1928_; lean_object* v___x_1929_; lean_object* v___x_1930_; lean_object* v___x_1931_; lean_object* v___x_1933_; 
v_spare_1925_ = lean_ctor_get(v_body_1812_, 0);
lean_inc(v_spare_1925_);
v_nd_1926_ = lean_ctor_get(v_body_1812_, 2);
lean_inc(v_nd_1926_);
v_md_1927_ = lean_ctor_get(v_body_1812_, 3);
lean_inc(v_md_1927_);
lean_dec_ref_known(v_body_1812_, 4);
v___x_1928_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__59));
v___x_1929_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__60));
v___x_1930_ = lean_nat_to_int(v_spare_1925_);
v___x_1931_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_1930_);
if (v_isShared_1816_ == 0)
{
lean_ctor_set(v___x_1815_, 1, v___x_1931_);
lean_ctor_set(v___x_1815_, 0, v___x_1929_);
v___x_1933_ = v___x_1815_;
goto v_reusejp_1932_;
}
else
{
lean_object* v_reuseFailAlloc_1958_; 
v_reuseFailAlloc_1958_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1958_, 0, v___x_1929_);
lean_ctor_set(v_reuseFailAlloc_1958_, 1, v___x_1931_);
v___x_1933_ = v_reuseFailAlloc_1958_;
goto v_reusejp_1932_;
}
v_reusejp_1932_:
{
lean_object* v___x_1934_; lean_object* v___x_1935_; lean_object* v___x_1936_; lean_object* v___x_1938_; 
v___x_1934_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__61));
v___x_1935_ = lean_nat_to_int(v_nd_1926_);
v___x_1936_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_1935_);
if (v_isShared_1924_ == 0)
{
lean_ctor_set(v___x_1923_, 1, v___x_1936_);
lean_ctor_set(v___x_1923_, 0, v___x_1934_);
v___x_1938_ = v___x_1923_;
goto v_reusejp_1937_;
}
else
{
lean_object* v_reuseFailAlloc_1957_; 
v_reuseFailAlloc_1957_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1957_, 0, v___x_1934_);
lean_ctor_set(v_reuseFailAlloc_1957_, 1, v___x_1936_);
v___x_1938_ = v_reuseFailAlloc_1957_;
goto v_reusejp_1937_;
}
v_reusejp_1937_:
{
lean_object* v___x_1939_; lean_object* v___x_1940_; lean_object* v___x_1941_; lean_object* v___x_1942_; lean_object* v___x_1943_; lean_object* v___x_1944_; lean_object* v___x_1945_; lean_object* v___x_1946_; lean_object* v___x_1947_; lean_object* v___x_1948_; lean_object* v___x_1949_; lean_object* v___x_1950_; lean_object* v___x_1951_; lean_object* v___x_1952_; lean_object* v___x_1953_; lean_object* v___x_1954_; lean_object* v___x_1955_; lean_object* v___x_1956_; 
v___x_1939_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_message___closed__62));
v___x_1940_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_JSON_message___closed__63, &lp_lean1090_Lean1090_Impl_JSON_message___closed__63_once, _init_lp_lean1090_Lean1090_Impl_JSON_message___closed__63);
v___x_1941_ = lean_box(0);
v___x_1942_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_JSON_message_spec__2(v_md_1927_, v___x_1940_, v___x_1941_);
v___x_1943_ = lean_array_mk(v___x_1942_);
v___x_1944_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_1944_, 0, v___x_1943_);
v___x_1945_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1945_, 0, v___x_1939_);
lean_ctor_set(v___x_1945_, 1, v___x_1944_);
v___x_1946_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_JSON_parity___closed__0));
v___x_1947_ = lean_unsigned_to_nat(16u);
v___x_1948_ = lean_unsigned_to_nat(6u);
v___x_1949_ = lp_lean1090_Lean1090_Impl_JSON_digits(v___x_1947_, v___x_1948_, v_parity_1813_);
lean_dec(v_parity_1813_);
v___x_1950_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1950_, 0, v___x_1949_);
v___x_1951_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1951_, 0, v___x_1946_);
lean_ctor_set(v___x_1951_, 1, v___x_1950_);
v___x_1952_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1952_, 0, v___x_1951_);
lean_ctor_set(v___x_1952_, 1, v___x_1941_);
v___x_1953_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1953_, 0, v___x_1945_);
lean_ctor_set(v___x_1953_, 1, v___x_1952_);
v___x_1954_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1954_, 0, v___x_1938_);
lean_ctor_set(v___x_1954_, 1, v___x_1953_);
v___x_1955_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1955_, 0, v___x_1933_);
lean_ctor_set(v___x_1955_, 1, v___x_1954_);
v___x_1956_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1956_, 0, v___x_1928_);
lean_ctor_set(v___x_1956_, 1, v___x_1955_);
v___y_1738_ = v_address_1818_;
v___y_1739_ = v___x_1956_;
goto v___jp_1737_;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_JSON_message___boxed(lean_object* v_oracle_1976_, lean_object* v_m_1977_){
_start:
{
uint8_t v_oracle_boxed_1978_; lean_object* v_res_1979_; 
v_oracle_boxed_1978_ = lean_unbox(v_oracle_1976_);
v_res_1979_ = lp_lean1090_Lean1090_Impl_JSON_message(v_oracle_boxed_1978_, v_m_1977_);
return v_res_1979_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Impl_Message(uint8_t builtin);
lean_object* initialize_lean1090_Impl_Numeric(uint8_t builtin);
lean_object* initialize_Lean_Data_Json_Basic(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_JSON(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
lean_initialize();
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_Message(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_Numeric(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean_Data_Json_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
