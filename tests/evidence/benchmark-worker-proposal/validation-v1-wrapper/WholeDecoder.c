// Lean compiler output
// Module: Bench.WholeDecoder
// Imports: public import Init public meta import Init public import Impl public import Impl.JSON public import Lean.Data.Json.Parser public import Lean.Data.Json.FromToJson.Basic
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
lean_object* lean_get_stdout();
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_array_get_size(lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
lean_object* lean_string_push(lean_object*, uint32_t);
lean_object* lean_get_stdin();
lean_object* lean_string_utf8_byte_size(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* l_String_Slice_trimAscii(lean_object*);
lean_object* l_String_Slice_toString(lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_io_mono_nanos_now();
size_t lean_array_size(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uget(lean_object*, size_t);
lean_object* lp_lean1090_Lean1090_Impl_decode(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
size_t lean_usize_add(size_t, size_t);
lean_object* lp_lean1090_Lean1090_Impl_JSON_raw(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* l_Rat_floor(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_streamStep(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* l_IO_eprintln___at___00__private_Init_System_IO_0__IO_eprintlnAux_spec__0(lean_object*);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
lean_object* l_Lean_JsonNumber_fromNat(lean_object*);
lean_object* l_IO_ofExcept___at___00Std_Time_Database_TZdb_parseTZIfFromDisk_spec__0___redArg(lean_object*);
lean_object* l_Lean_Json_getObjVal_x3f(lean_object*, lean_object*);
lean_object* l_Lean_Json_getNum_x3f(lean_object*);
lean_object* l_Rat_ofInt(lean_object*);
lean_object* lean_nat_pow(lean_object*, lean_object*);
lean_object* l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(lean_object*);
lean_object* l_Rat_div(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_round(lean_object*);
extern lean_object* lp_lean1090_Lean1090_Impl_Binary64_maxFinite;
lean_object* l_Rat_abs(lean_object*);
uint8_t l_Rat_blt(lean_object*, lean_object*);
lean_object* l_Lean_Json_getStr_x3f(lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
double lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(lean_object*);
uint64_t lean_float_to_bits(double);
lean_object* lean_uint64_to_nat(uint64_t);
lean_object* lean_array_mk(lean_object*);
lean_object* l_Lean_JsonNumber_fromInt(lean_object*);
lean_object* l_Lean_Json_mkObj(lean_object*);
lean_object* lean_array_fget(lean_object*, lean_object*);
lean_object* l_Lean_Json_compress(lean_object*);
uint8_t lean_uint32_dec_le(uint32_t, uint32_t);
lean_object* lean_uint32_to_nat(uint32_t);
lean_object* l_IO_FS_readFile(lean_object*);
lean_object* l_String_splitOnAux(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_List_zipIdxTR___redArg(lean_object*, lean_object*);
lean_object* lean_string_data(lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
uint8_t lean_uint8_of_nat(lean_object*);
lean_object* l_Lean_Json_parse(lean_object*);
lean_object* lean_string_length(lean_object*);
lean_object* l_List_drop___redArg(lean_object*, lean_object*);
lean_object* lean_string_mk(lean_object*);
uint8_t lean_string_memcmp(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_String_Slice_Pos_prevn(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Json_getArr_x3f(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography(lean_object*);
lean_object* lean_uint8_to_nat(uint8_t);
lean_object* l_String_intercalate(lean_object*, lean_object*);
lean_object* l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_expectedMessages;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_airportPath___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 47, .m_capacity = 47, .m_length = 46, .m_data = "vendor/rs1090/crates/rs1090/data/airports.json"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_airportPath___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_airportPath___closed__0_value;
LEAN_EXPORT const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_airportPath = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_airportPath___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_nibble(uint32_t);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_nibble___boxed(lean_object*);
static const lean_ctor_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_hexBytes___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_hexBytes___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_hexBytes___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_hexBytes(lean_object*);
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "non-finite input number"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number___closed__0_value;
static const lean_ctor_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number___closed__0_value)}};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number___closed__1 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number___closed__1_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number(lean_object*);
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "line "};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__0 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__0_value;
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = ": expected timestamp,frame"};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__1 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__1_value;
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 28, .m_capacity = 28, .m_length = 27, .m_data = ": invalid hexadecimal digit"};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__2 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__2_value;
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 33, .m_capacity = 33, .m_length = 32, .m_data = ": expected 7 or 14 message bytes"};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__3 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__3_value;
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ","};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__4 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__4_value;
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = ": missing Beast prefix"};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__5 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__5_value;
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "\r"};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__6 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__6_value;
static lean_once_cell_t lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__7;
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "\n"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs___closed__0_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 33, .m_capacity = 33, .m_length = 32, .m_data = "expected 172432 messages, found "};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs___closed__1 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs___closed__1_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "lon"};
static const lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___closed__0 = (const lean_object*)&lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___closed__0_value;
static const lean_string_object lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "lat"};
static const lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___closed__1 = (const lean_object*)&lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___closed__1_value;
static const lean_string_object lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "icao"};
static const lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___closed__2 = (const lean_object*)&lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___closed__2_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 30, .m_capacity = 30, .m_length = 29, .m_data = "expected 6903 pinned airports"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports___closed__0_value;
static const lean_ctor_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports___closed__0_value)}};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports___closed__1 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports___closed__1_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports();
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports___boxed(lean_object*);
static const lean_string_object lp_lean1090_List_find_x3f___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "altitude_feet"};
static const lean_object* lp_lean1090_List_find_x3f___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport_spec__0___closed__0 = (const lean_object*)&lp_lean1090_List_find_x3f___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport_spec__0___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport_spec__0___boxed(lean_object*);
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "tc"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__0_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "parity"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__1 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__1_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "lat_cpr"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__2 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__2_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "lon_cpr"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__3 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__3_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "time_sync"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__4 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__4_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "ss"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__5 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__5_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "saf_or_nicb"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__6 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__6_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance___lam__0___boxed(lean_object*);
static const lean_closure_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance___lam__0___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume_spec__0(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = "incomplete retained output"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__0_value;
static const lean_ctor_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__0_value)}};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__1 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__1_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "consumed messages="};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__2 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__2_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = " aircraft="};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__3 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__3_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = " checksum="};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__4 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__4_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 34, .m_capacity = 34, .m_length = 33, .m_data = "decoder rejected a corpus message"};
static const lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0___closed__0 = (const lean_object*)&lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0___closed__0_value;
static const lean_ctor_object lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0___closed__0_value)}};
static const lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0___closed__1 = (const lean_object*)&lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0___closed__1_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0(uint8_t, lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "quit"};
static const lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__0 = (const lean_object*)&lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__0_value;
static const lean_string_object lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "run"};
static const lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__1 = (const lean_object*)&lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__1_value;
static const lean_string_object lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "unknown worker command"};
static const lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__2 = (const lean_object*)&lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__2_value;
static const lean_ctor_object lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__2_value)}};
static const lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__3 = (const lean_object*)&lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__3_value;
static const lean_string_object lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = " "};
static const lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__4 = (const lean_object*)&lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__4_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg(lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "ready "};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1(lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0_spec__1(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0_spec__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean_Option_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean_Option_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__1(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___lam__0___boxed(lean_object*, lean_object*);
static const lean_string_object lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "address"};
static const lean_object* lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__0 = (const lean_object*)&lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__0_value;
static const lean_string_object lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "position"};
static const lean_object* lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__1 = (const lean_object*)&lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__1_value;
static const lean_string_object lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "altitude"};
static const lean_object* lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__2 = (const lean_object*)&lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__2_value;
static const lean_string_object lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "airport"};
static const lean_object* lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__3 = (const lean_object*)&lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__3_value;
static const lean_string_object lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "seen"};
static const lean_object* lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__4 = (const lean_object*)&lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__4_value;
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3(lean_object*, lean_object*);
static const lean_string_object lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "id"};
static const lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___closed__0 = (const lean_object*)&lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___closed__0_value;
static const lean_string_object lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "routed"};
static const lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___closed__1 = (const lean_object*)&lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___closed__1_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4_spec__5(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4_spec__5___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4(lean_object*);
static const lean_closure_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___lam__0___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__0_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "final"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__1 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__1_value;
static const lean_ctor_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 1}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(1, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__2 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__2_value;
static const lean_ctor_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__1_value),((lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__2_value)}};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__3 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__3_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "reference"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__4 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__4_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "aircraft"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__5 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__5_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "check mode="};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__0 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__0_value;
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = " messages="};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__1 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__1_value;
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = " positions="};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__2 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__2_value;
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = " ok"};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__3 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__3_value;
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "decode"};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__4 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__4_value;
static const lean_string_object lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "cpr"};
static const lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__5 = (const lean_object*)&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__5_value;
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__2(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "--worker-decode"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__0_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "--worker-cpr"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__1 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__1_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "--check"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__2 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__2_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "--audit-tracking"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__3 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__3_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "--audit-inputs"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__4 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__4_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "--audit-airports"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__5 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__5_value;
static const lean_string_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "unknown mode"};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__6 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__6_value;
static const lean_ctor_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__6_value)}};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__7 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__7_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090_main___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 119, .m_capacity = 119, .m_length = 118, .m_data = "usage: lean1090-bench --worker-decode|--worker-cpr|--check|--audit-inputs|--audit-airports|--audit-tracking CORPUS.csv"};
static const lean_object* lp_lean1090_main___closed__0 = (const lean_object*)&lp_lean1090_main___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090_main___boxed__const__1;
LEAN_EXPORT lean_object* lp_lean1090_main___boxed__const__2;
LEAN_EXPORT lean_object* _lean_main(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_main___boxed(lean_object*, lean_object*);
static lean_object* _init_lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_expectedMessages(void){
_start:
{
lean_object* v___x_1_; 
v___x_1_ = lean_unsigned_to_nat(172432u);
return v___x_1_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_nibble(uint32_t v_c_4_){
_start:
{
uint32_t v___x_25_; uint8_t v___x_26_; 
v___x_25_ = 48;
v___x_26_ = lean_uint32_dec_le(v___x_25_, v_c_4_);
if (v___x_26_ == 0)
{
goto v___jp_16_;
}
else
{
uint32_t v___x_27_; uint8_t v___x_28_; 
v___x_27_ = 57;
v___x_28_ = lean_uint32_dec_le(v_c_4_, v___x_27_);
if (v___x_28_ == 0)
{
goto v___jp_16_;
}
else
{
lean_object* v___x_29_; lean_object* v___x_30_; lean_object* v___x_31_; lean_object* v___x_32_; 
v___x_29_ = lean_unsigned_to_nat(48u);
v___x_30_ = lean_uint32_to_nat(v_c_4_);
v___x_31_ = lean_nat_sub(v___x_30_, v___x_29_);
lean_dec(v___x_30_);
v___x_32_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_32_, 0, v___x_31_);
return v___x_32_;
}
}
v___jp_5_:
{
uint32_t v___x_6_; uint8_t v___x_7_; 
v___x_6_ = 65;
v___x_7_ = lean_uint32_dec_le(v___x_6_, v_c_4_);
if (v___x_7_ == 0)
{
lean_object* v___x_8_; 
v___x_8_ = lean_box(0);
return v___x_8_;
}
else
{
uint32_t v___x_9_; uint8_t v___x_10_; 
v___x_9_ = 70;
v___x_10_ = lean_uint32_dec_le(v_c_4_, v___x_9_);
if (v___x_10_ == 0)
{
lean_object* v___x_11_; 
v___x_11_ = lean_box(0);
return v___x_11_;
}
else
{
lean_object* v___x_12_; lean_object* v___x_13_; lean_object* v___x_14_; lean_object* v___x_15_; 
v___x_12_ = lean_uint32_to_nat(v_c_4_);
v___x_13_ = lean_unsigned_to_nat(55u);
v___x_14_ = lean_nat_sub(v___x_12_, v___x_13_);
lean_dec(v___x_12_);
v___x_15_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_15_, 0, v___x_14_);
return v___x_15_;
}
}
}
v___jp_16_:
{
uint32_t v___x_17_; uint8_t v___x_18_; 
v___x_17_ = 97;
v___x_18_ = lean_uint32_dec_le(v___x_17_, v_c_4_);
if (v___x_18_ == 0)
{
goto v___jp_5_;
}
else
{
uint32_t v___x_19_; uint8_t v___x_20_; 
v___x_19_ = 102;
v___x_20_ = lean_uint32_dec_le(v_c_4_, v___x_19_);
if (v___x_20_ == 0)
{
goto v___jp_5_;
}
else
{
lean_object* v___x_21_; lean_object* v___x_22_; lean_object* v___x_23_; lean_object* v___x_24_; 
v___x_21_ = lean_uint32_to_nat(v_c_4_);
v___x_22_ = lean_unsigned_to_nat(87u);
v___x_23_ = lean_nat_sub(v___x_21_, v___x_22_);
lean_dec(v___x_21_);
v___x_24_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_24_, 0, v___x_23_);
return v___x_24_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_nibble___boxed(lean_object* v_c_33_){
_start:
{
uint32_t v_c_boxed_34_; lean_object* v_res_35_; 
v_c_boxed_34_ = lean_unbox_uint32(v_c_33_);
lean_dec(v_c_33_);
v_res_35_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_nibble(v_c_boxed_34_);
return v_res_35_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_hexBytes(lean_object* v_x_38_){
_start:
{
if (lean_obj_tag(v_x_38_) == 0)
{
lean_object* v___x_39_; 
v___x_39_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_hexBytes___closed__0));
return v___x_39_;
}
else
{
lean_object* v_tail_40_; 
v_tail_40_ = lean_ctor_get(v_x_38_, 1);
lean_inc(v_tail_40_);
if (lean_obj_tag(v_tail_40_) == 1)
{
lean_object* v_head_41_; lean_object* v_head_42_; lean_object* v_tail_43_; lean_object* v___x_45_; uint8_t v_isShared_46_; uint8_t v_isSharedCheck_72_; 
v_head_41_ = lean_ctor_get(v_x_38_, 0);
lean_inc(v_head_41_);
lean_dec_ref_known(v_x_38_, 2);
v_head_42_ = lean_ctor_get(v_tail_40_, 0);
v_tail_43_ = lean_ctor_get(v_tail_40_, 1);
v_isSharedCheck_72_ = !lean_is_exclusive(v_tail_40_);
if (v_isSharedCheck_72_ == 0)
{
v___x_45_ = v_tail_40_;
v_isShared_46_ = v_isSharedCheck_72_;
goto v_resetjp_44_;
}
else
{
lean_inc(v_tail_43_);
lean_inc(v_head_42_);
lean_dec(v_tail_40_);
v___x_45_ = lean_box(0);
v_isShared_46_ = v_isSharedCheck_72_;
goto v_resetjp_44_;
}
v_resetjp_44_:
{
uint32_t v___x_47_; lean_object* v___x_48_; 
v___x_47_ = lean_unbox_uint32(v_head_41_);
lean_dec(v_head_41_);
v___x_48_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_nibble(v___x_47_);
if (lean_obj_tag(v___x_48_) == 0)
{
lean_object* v___x_49_; 
lean_del_object(v___x_45_);
lean_dec(v_tail_43_);
lean_dec(v_head_42_);
v___x_49_ = lean_box(0);
return v___x_49_;
}
else
{
lean_object* v_val_50_; uint32_t v___x_51_; lean_object* v___x_52_; 
v_val_50_ = lean_ctor_get(v___x_48_, 0);
lean_inc(v_val_50_);
lean_dec_ref_known(v___x_48_, 1);
v___x_51_ = lean_unbox_uint32(v_head_42_);
lean_dec(v_head_42_);
v___x_52_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_nibble(v___x_51_);
if (lean_obj_tag(v___x_52_) == 0)
{
lean_object* v___x_53_; 
lean_dec(v_val_50_);
lean_del_object(v___x_45_);
lean_dec(v_tail_43_);
v___x_53_ = lean_box(0);
return v___x_53_;
}
else
{
lean_object* v_val_54_; lean_object* v___x_55_; 
v_val_54_ = lean_ctor_get(v___x_52_, 0);
lean_inc(v_val_54_);
lean_dec_ref_known(v___x_52_, 1);
v___x_55_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_hexBytes(v_tail_43_);
if (lean_obj_tag(v___x_55_) == 0)
{
lean_dec(v_val_54_);
lean_dec(v_val_50_);
lean_del_object(v___x_45_);
return v___x_55_;
}
else
{
lean_object* v_val_56_; lean_object* v___x_58_; uint8_t v_isShared_59_; uint8_t v_isSharedCheck_71_; 
v_val_56_ = lean_ctor_get(v___x_55_, 0);
v_isSharedCheck_71_ = !lean_is_exclusive(v___x_55_);
if (v_isSharedCheck_71_ == 0)
{
v___x_58_ = v___x_55_;
v_isShared_59_ = v_isSharedCheck_71_;
goto v_resetjp_57_;
}
else
{
lean_inc(v_val_56_);
lean_dec(v___x_55_);
v___x_58_ = lean_box(0);
v_isShared_59_ = v_isSharedCheck_71_;
goto v_resetjp_57_;
}
v_resetjp_57_:
{
lean_object* v___x_60_; lean_object* v___x_61_; lean_object* v___x_62_; uint8_t v___x_63_; lean_object* v___x_64_; lean_object* v___x_66_; 
v___x_60_ = lean_unsigned_to_nat(16u);
v___x_61_ = lean_nat_mul(v_val_50_, v___x_60_);
lean_dec(v_val_50_);
v___x_62_ = lean_nat_add(v___x_61_, v_val_54_);
lean_dec(v_val_54_);
lean_dec(v___x_61_);
v___x_63_ = lean_uint8_of_nat(v___x_62_);
lean_dec(v___x_62_);
v___x_64_ = lean_box(v___x_63_);
if (v_isShared_46_ == 0)
{
lean_ctor_set(v___x_45_, 1, v_val_56_);
lean_ctor_set(v___x_45_, 0, v___x_64_);
v___x_66_ = v___x_45_;
goto v_reusejp_65_;
}
else
{
lean_object* v_reuseFailAlloc_70_; 
v_reuseFailAlloc_70_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_70_, 0, v___x_64_);
lean_ctor_set(v_reuseFailAlloc_70_, 1, v_val_56_);
v___x_66_ = v_reuseFailAlloc_70_;
goto v_reusejp_65_;
}
v_reusejp_65_:
{
lean_object* v___x_68_; 
if (v_isShared_59_ == 0)
{
lean_ctor_set(v___x_58_, 0, v___x_66_);
v___x_68_ = v___x_58_;
goto v_reusejp_67_;
}
else
{
lean_object* v_reuseFailAlloc_69_; 
v_reuseFailAlloc_69_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_69_, 0, v___x_66_);
v___x_68_ = v_reuseFailAlloc_69_;
goto v_reusejp_67_;
}
v_reusejp_67_:
{
return v___x_68_;
}
}
}
}
}
}
}
}
else
{
lean_object* v___x_73_; 
lean_dec(v_tail_40_);
lean_dec_ref_known(v_x_38_, 2);
v___x_73_ = lean_box(0);
return v___x_73_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number(lean_object* v_json_77_){
_start:
{
lean_object* v___x_78_; 
v___x_78_ = l_Lean_Json_getNum_x3f(v_json_77_);
if (lean_obj_tag(v___x_78_) == 0)
{
lean_object* v_a_79_; lean_object* v___x_81_; uint8_t v_isShared_82_; uint8_t v_isSharedCheck_86_; 
v_a_79_ = lean_ctor_get(v___x_78_, 0);
v_isSharedCheck_86_ = !lean_is_exclusive(v___x_78_);
if (v_isSharedCheck_86_ == 0)
{
v___x_81_ = v___x_78_;
v_isShared_82_ = v_isSharedCheck_86_;
goto v_resetjp_80_;
}
else
{
lean_inc(v_a_79_);
lean_dec(v___x_78_);
v___x_81_ = lean_box(0);
v_isShared_82_ = v_isSharedCheck_86_;
goto v_resetjp_80_;
}
v_resetjp_80_:
{
lean_object* v___x_84_; 
if (v_isShared_82_ == 0)
{
v___x_84_ = v___x_81_;
goto v_reusejp_83_;
}
else
{
lean_object* v_reuseFailAlloc_85_; 
v_reuseFailAlloc_85_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_85_, 0, v_a_79_);
v___x_84_ = v_reuseFailAlloc_85_;
goto v_reusejp_83_;
}
v_reusejp_83_:
{
return v___x_84_;
}
}
}
else
{
lean_object* v_a_87_; lean_object* v___x_89_; uint8_t v_isShared_90_; uint8_t v_isSharedCheck_106_; 
v_a_87_ = lean_ctor_get(v___x_78_, 0);
v_isSharedCheck_106_ = !lean_is_exclusive(v___x_78_);
if (v_isSharedCheck_106_ == 0)
{
v___x_89_ = v___x_78_;
v_isShared_90_ = v_isSharedCheck_106_;
goto v_resetjp_88_;
}
else
{
lean_inc(v_a_87_);
lean_dec(v___x_78_);
v___x_89_ = lean_box(0);
v_isShared_90_ = v_isSharedCheck_106_;
goto v_resetjp_88_;
}
v_resetjp_88_:
{
lean_object* v_mantissa_91_; lean_object* v_exponent_92_; lean_object* v___x_93_; lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; lean_object* v___x_99_; lean_object* v___x_100_; uint8_t v___x_101_; 
v_mantissa_91_ = lean_ctor_get(v_a_87_, 0);
lean_inc(v_mantissa_91_);
v_exponent_92_ = lean_ctor_get(v_a_87_, 1);
lean_inc(v_exponent_92_);
lean_dec(v_a_87_);
v___x_93_ = l_Rat_ofInt(v_mantissa_91_);
v___x_94_ = lean_unsigned_to_nat(10u);
v___x_95_ = lean_nat_pow(v___x_94_, v_exponent_92_);
lean_dec(v_exponent_92_);
v___x_96_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_95_);
v___x_97_ = l_Rat_div(v___x_93_, v___x_96_);
lean_dec_ref(v___x_93_);
v___x_98_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_97_);
v___x_99_ = lp_lean1090_Lean1090_Impl_Binary64_maxFinite;
lean_inc_ref(v___x_98_);
v___x_100_ = l_Rat_abs(v___x_98_);
v___x_101_ = l_Rat_blt(v___x_99_, v___x_100_);
if (v___x_101_ == 0)
{
lean_object* v___x_103_; 
if (v_isShared_90_ == 0)
{
lean_ctor_set(v___x_89_, 0, v___x_98_);
v___x_103_ = v___x_89_;
goto v_reusejp_102_;
}
else
{
lean_object* v_reuseFailAlloc_104_; 
v_reuseFailAlloc_104_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_104_, 0, v___x_98_);
v___x_103_ = v_reuseFailAlloc_104_;
goto v_reusejp_102_;
}
v_reusejp_102_:
{
return v___x_103_;
}
}
else
{
lean_object* v___x_105_; 
lean_dec_ref(v___x_98_);
lean_del_object(v___x_89_);
v___x_105_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number___closed__1));
return v___x_105_;
}
}
}
}
}
static lean_object* _init_lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__7(void){
_start:
{
lean_object* v___x_114_; lean_object* v___x_115_; 
v___x_114_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__6));
v___x_115_ = lean_string_utf8_byte_size(v___x_114_);
return v___x_115_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg(lean_object* v___y_116_, lean_object* v_as_x27_117_, lean_object* v_b_118_){
_start:
{
if (lean_obj_tag(v_as_x27_117_) == 0)
{
lean_object* v___x_120_; 
v___x_120_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_120_, 0, v_b_118_);
return v___x_120_;
}
else
{
lean_object* v_head_121_; lean_object* v_tail_122_; lean_object* v___y_124_; lean_object* v___y_125_; lean_object* v_fst_139_; lean_object* v_snd_140_; lean_object* v___y_152_; lean_object* v___y_153_; lean_object* v___y_178_; lean_object* v___y_179_; uint8_t v___y_193_; lean_object* v___y_194_; uint8_t v___y_222_; lean_object* v___x_235_; lean_object* v___x_236_; uint8_t v___x_237_; 
v_head_121_ = lean_ctor_get(v_as_x27_117_, 0);
v_tail_122_ = lean_ctor_get(v_as_x27_117_, 1);
v_fst_139_ = lean_ctor_get(v_head_121_, 0);
v_snd_140_ = lean_ctor_get(v_head_121_, 1);
v___x_235_ = lean_string_utf8_byte_size(v_fst_139_);
v___x_236_ = lean_unsigned_to_nat(0u);
v___x_237_ = lean_nat_dec_eq(v___x_235_, v___x_236_);
if (v___x_237_ == 0)
{
v___y_222_ = v___x_237_;
goto v___jp_221_;
}
else
{
lean_object* v___x_238_; lean_object* v___x_239_; lean_object* v___x_240_; uint8_t v___x_241_; 
v___x_238_ = lean_unsigned_to_nat(1u);
v___x_239_ = lean_nat_add(v_snd_140_, v___x_238_);
v___x_240_ = l_List_lengthTR___redArg(v___y_116_);
v___x_241_ = lean_nat_dec_eq(v___x_239_, v___x_240_);
lean_dec(v___x_240_);
lean_dec(v___x_239_);
if (v___x_241_ == 0)
{
v___y_222_ = v___x_241_;
goto v___jp_221_;
}
else
{
v_as_x27_117_ = v_tail_122_;
goto _start;
}
}
v___jp_123_:
{
lean_object* v___x_126_; 
v___x_126_ = l_IO_ofExcept___at___00Std_Time_Database_TZdb_parseTZIfFromDisk_spec__0___redArg(v___y_125_);
if (lean_obj_tag(v___x_126_) == 0)
{
lean_object* v_a_127_; lean_object* v___x_128_; lean_object* v___x_129_; 
v_a_127_ = lean_ctor_get(v___x_126_, 0);
lean_inc(v_a_127_);
lean_dec_ref_known(v___x_126_, 1);
v___x_128_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_128_, 0, v_a_127_);
lean_ctor_set(v___x_128_, 1, v___y_124_);
v___x_129_ = lean_array_push(v_b_118_, v___x_128_);
v_as_x27_117_ = v_tail_122_;
v_b_118_ = v___x_129_;
goto _start;
}
else
{
lean_object* v_a_131_; lean_object* v___x_133_; uint8_t v_isShared_134_; uint8_t v_isSharedCheck_138_; 
lean_dec(v___y_124_);
lean_dec_ref(v_b_118_);
v_a_131_ = lean_ctor_get(v___x_126_, 0);
v_isSharedCheck_138_ = !lean_is_exclusive(v___x_126_);
if (v_isSharedCheck_138_ == 0)
{
v___x_133_ = v___x_126_;
v_isShared_134_ = v_isSharedCheck_138_;
goto v_resetjp_132_;
}
else
{
lean_inc(v_a_131_);
lean_dec(v___x_126_);
v___x_133_ = lean_box(0);
v_isShared_134_ = v_isSharedCheck_138_;
goto v_resetjp_132_;
}
v_resetjp_132_:
{
lean_object* v___x_136_; 
if (v_isShared_134_ == 0)
{
v___x_136_ = v___x_133_;
goto v_reusejp_135_;
}
else
{
lean_object* v_reuseFailAlloc_137_; 
v_reuseFailAlloc_137_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_137_, 0, v_a_131_);
v___x_136_ = v_reuseFailAlloc_137_;
goto v_reusejp_135_;
}
v_reusejp_135_:
{
return v___x_136_;
}
}
}
}
v___jp_141_:
{
lean_object* v___x_142_; lean_object* v___x_143_; lean_object* v___x_144_; lean_object* v___x_145_; lean_object* v___x_146_; lean_object* v___x_147_; lean_object* v___x_148_; lean_object* v___x_149_; lean_object* v___x_150_; 
v___x_142_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__0));
v___x_143_ = lean_unsigned_to_nat(1u);
v___x_144_ = lean_nat_add(v_snd_140_, v___x_143_);
v___x_145_ = l_Nat_reprFast(v___x_144_);
v___x_146_ = lean_string_append(v___x_142_, v___x_145_);
lean_dec_ref(v___x_145_);
v___x_147_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__1));
v___x_148_ = lean_string_append(v___x_146_, v___x_147_);
v___x_149_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_149_, 0, v___x_148_);
v___x_150_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_150_, 0, v___x_149_);
return v___x_150_;
}
v___jp_151_:
{
lean_object* v___x_154_; lean_object* v___x_155_; 
v___x_154_ = lean_string_data(v___y_152_);
v___x_155_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_hexBytes(v___x_154_);
if (lean_obj_tag(v___x_155_) == 1)
{
lean_object* v_val_156_; lean_object* v___x_157_; 
v_val_156_ = lean_ctor_get(v___x_155_, 0);
lean_inc(v_val_156_);
lean_dec_ref_known(v___x_155_, 1);
v___x_157_ = l_Lean_Json_parse(v___y_153_);
if (lean_obj_tag(v___x_157_) == 0)
{
lean_object* v_a_158_; lean_object* v___x_160_; uint8_t v_isShared_161_; uint8_t v_isSharedCheck_165_; 
v_a_158_ = lean_ctor_get(v___x_157_, 0);
v_isSharedCheck_165_ = !lean_is_exclusive(v___x_157_);
if (v_isSharedCheck_165_ == 0)
{
v___x_160_ = v___x_157_;
v_isShared_161_ = v_isSharedCheck_165_;
goto v_resetjp_159_;
}
else
{
lean_inc(v_a_158_);
lean_dec(v___x_157_);
v___x_160_ = lean_box(0);
v_isShared_161_ = v_isSharedCheck_165_;
goto v_resetjp_159_;
}
v_resetjp_159_:
{
lean_object* v___x_163_; 
if (v_isShared_161_ == 0)
{
v___x_163_ = v___x_160_;
goto v_reusejp_162_;
}
else
{
lean_object* v_reuseFailAlloc_164_; 
v_reuseFailAlloc_164_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_164_, 0, v_a_158_);
v___x_163_ = v_reuseFailAlloc_164_;
goto v_reusejp_162_;
}
v_reusejp_162_:
{
v___y_124_ = v_val_156_;
v___y_125_ = v___x_163_;
goto v___jp_123_;
}
}
}
else
{
lean_object* v_a_166_; lean_object* v___x_167_; 
v_a_166_ = lean_ctor_get(v___x_157_, 0);
lean_inc(v_a_166_);
lean_dec_ref_known(v___x_157_, 1);
v___x_167_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number(v_a_166_);
v___y_124_ = v_val_156_;
v___y_125_ = v___x_167_;
goto v___jp_123_;
}
}
else
{
lean_object* v___x_168_; lean_object* v___x_169_; lean_object* v___x_170_; lean_object* v___x_171_; lean_object* v___x_172_; lean_object* v___x_173_; lean_object* v___x_174_; lean_object* v___x_175_; lean_object* v___x_176_; 
lean_dec(v___x_155_);
lean_dec_ref(v___y_153_);
lean_dec_ref(v_b_118_);
v___x_168_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__0));
v___x_169_ = lean_unsigned_to_nat(1u);
v___x_170_ = lean_nat_add(v_snd_140_, v___x_169_);
v___x_171_ = l_Nat_reprFast(v___x_170_);
v___x_172_ = lean_string_append(v___x_168_, v___x_171_);
lean_dec_ref(v___x_171_);
v___x_173_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__2));
v___x_174_ = lean_string_append(v___x_172_, v___x_173_);
v___x_175_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_175_, 0, v___x_174_);
v___x_176_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_176_, 0, v___x_175_);
return v___x_176_;
}
}
v___jp_177_:
{
lean_object* v___x_180_; lean_object* v___x_181_; uint8_t v___x_182_; 
v___x_180_ = lean_string_length(v___y_178_);
v___x_181_ = lean_unsigned_to_nat(28u);
v___x_182_ = lean_nat_dec_eq(v___x_180_, v___x_181_);
if (v___x_182_ == 0)
{
lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_185_; lean_object* v___x_186_; lean_object* v___x_187_; lean_object* v___x_188_; lean_object* v___x_189_; lean_object* v___x_190_; lean_object* v___x_191_; 
lean_dec_ref(v___y_179_);
lean_dec_ref(v___y_178_);
lean_dec_ref(v_b_118_);
v___x_183_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__0));
v___x_184_ = lean_unsigned_to_nat(1u);
v___x_185_ = lean_nat_add(v_snd_140_, v___x_184_);
v___x_186_ = l_Nat_reprFast(v___x_185_);
v___x_187_ = lean_string_append(v___x_183_, v___x_186_);
lean_dec_ref(v___x_186_);
v___x_188_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__3));
v___x_189_ = lean_string_append(v___x_187_, v___x_188_);
v___x_190_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_190_, 0, v___x_189_);
v___x_191_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_191_, 0, v___x_190_);
return v___x_191_;
}
else
{
v___y_152_ = v___y_178_;
v___y_153_ = v___y_179_;
goto v___jp_151_;
}
}
v___jp_192_:
{
lean_object* v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; lean_object* v___x_198_; 
v___x_195_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__4));
v___x_196_ = lean_unsigned_to_nat(0u);
v___x_197_ = lean_box(0);
v___x_198_ = l_String_splitOnAux(v___y_194_, v___x_195_, v___x_196_, v___x_196_, v___x_196_, v___x_197_);
lean_dec_ref(v___y_194_);
if (lean_obj_tag(v___x_198_) == 1)
{
lean_object* v_tail_199_; 
v_tail_199_ = lean_ctor_get(v___x_198_, 1);
lean_inc(v_tail_199_);
if (lean_obj_tag(v_tail_199_) == 1)
{
lean_object* v_tail_200_; 
v_tail_200_ = lean_ctor_get(v_tail_199_, 1);
if (lean_obj_tag(v_tail_200_) == 0)
{
lean_object* v_head_201_; lean_object* v_head_202_; lean_object* v___x_203_; lean_object* v___x_204_; uint8_t v___x_205_; 
v_head_201_ = lean_ctor_get(v___x_198_, 0);
lean_inc(v_head_201_);
lean_dec_ref_known(v___x_198_, 2);
v_head_202_ = lean_ctor_get(v_tail_199_, 0);
lean_inc(v_head_202_);
lean_dec_ref_known(v_tail_199_, 2);
v___x_203_ = lean_string_length(v_head_202_);
v___x_204_ = lean_unsigned_to_nat(18u);
v___x_205_ = lean_nat_dec_lt(v___x_203_, v___x_204_);
if (v___x_205_ == 0)
{
lean_object* v___x_206_; lean_object* v___x_207_; lean_object* v___x_208_; lean_object* v___x_209_; lean_object* v___x_210_; uint8_t v___x_211_; 
v___x_206_ = lean_string_data(v_head_202_);
v___x_207_ = l_List_drop___redArg(v___x_204_, v___x_206_);
lean_dec(v___x_206_);
v___x_208_ = lean_string_mk(v___x_207_);
v___x_209_ = lean_string_length(v___x_208_);
v___x_210_ = lean_unsigned_to_nat(14u);
v___x_211_ = lean_nat_dec_eq(v___x_209_, v___x_210_);
if (v___x_211_ == 0)
{
v___y_178_ = v___x_208_;
v___y_179_ = v_head_201_;
goto v___jp_177_;
}
else
{
if (v___y_193_ == 0)
{
v___y_152_ = v___x_208_;
v___y_153_ = v_head_201_;
goto v___jp_151_;
}
else
{
v___y_178_ = v___x_208_;
v___y_179_ = v_head_201_;
goto v___jp_177_;
}
}
}
else
{
lean_object* v___x_212_; lean_object* v___x_213_; lean_object* v___x_214_; lean_object* v___x_215_; lean_object* v___x_216_; lean_object* v___x_217_; lean_object* v___x_218_; lean_object* v___x_219_; lean_object* v___x_220_; 
lean_dec(v_head_202_);
lean_dec(v_head_201_);
lean_dec_ref(v_b_118_);
v___x_212_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__0));
v___x_213_ = lean_unsigned_to_nat(1u);
v___x_214_ = lean_nat_add(v_snd_140_, v___x_213_);
v___x_215_ = l_Nat_reprFast(v___x_214_);
v___x_216_ = lean_string_append(v___x_212_, v___x_215_);
lean_dec_ref(v___x_215_);
v___x_217_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__5));
v___x_218_ = lean_string_append(v___x_216_, v___x_217_);
v___x_219_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_219_, 0, v___x_218_);
v___x_220_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_220_, 0, v___x_219_);
return v___x_220_;
}
}
else
{
lean_dec_ref_known(v_tail_199_, 2);
lean_dec_ref_known(v___x_198_, 2);
lean_dec_ref(v_b_118_);
goto v___jp_141_;
}
}
else
{
lean_dec(v_tail_199_);
lean_dec_ref_known(v___x_198_, 2);
lean_dec_ref(v_b_118_);
goto v___jp_141_;
}
}
else
{
lean_dec(v___x_198_);
lean_dec_ref(v_b_118_);
goto v___jp_141_;
}
}
v___jp_221_:
{
lean_object* v___x_223_; lean_object* v___x_224_; lean_object* v___x_225_; uint8_t v___x_226_; 
v___x_223_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__6));
v___x_224_ = lean_string_utf8_byte_size(v_fst_139_);
v___x_225_ = lean_obj_once(&lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__7, &lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__7_once, _init_lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___closed__7);
v___x_226_ = lean_nat_dec_le(v___x_225_, v___x_224_);
if (v___x_226_ == 0)
{
lean_inc(v_fst_139_);
v___y_193_ = v___y_222_;
v___y_194_ = v_fst_139_;
goto v___jp_192_;
}
else
{
lean_object* v___x_227_; lean_object* v___x_228_; uint8_t v___x_229_; 
v___x_227_ = lean_unsigned_to_nat(0u);
v___x_228_ = lean_nat_sub(v___x_224_, v___x_225_);
v___x_229_ = lean_string_memcmp(v_fst_139_, v___x_223_, v___x_228_, v___x_227_, v___x_225_);
lean_dec(v___x_228_);
if (v___x_229_ == 0)
{
lean_inc(v_fst_139_);
v___y_193_ = v___y_222_;
v___y_194_ = v_fst_139_;
goto v___jp_192_;
}
else
{
lean_object* v___x_230_; lean_object* v___x_231_; lean_object* v___x_232_; lean_object* v___x_233_; lean_object* v___x_234_; 
v___x_230_ = lean_unsigned_to_nat(1u);
lean_inc_n(v_fst_139_, 2);
v___x_231_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_231_, 0, v_fst_139_);
lean_ctor_set(v___x_231_, 1, v___x_227_);
lean_ctor_set(v___x_231_, 2, v___x_224_);
v___x_232_ = l_String_Slice_Pos_prevn(v___x_231_, v___x_224_, v___x_230_);
lean_dec_ref_known(v___x_231_, 3);
v___x_233_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_233_, 0, v_fst_139_);
lean_ctor_set(v___x_233_, 1, v___x_227_);
lean_ctor_set(v___x_233_, 2, v___x_232_);
v___x_234_ = l_String_Slice_toString(v___x_233_);
lean_dec_ref_known(v___x_233_, 3);
v___y_193_ = v___y_222_;
v___y_194_ = v___x_234_;
goto v___jp_192_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg___boxed(lean_object* v___y_243_, lean_object* v_as_x27_244_, lean_object* v_b_245_, lean_object* v___y_246_){
_start:
{
lean_object* v_res_247_; 
v_res_247_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg(v___y_243_, v_as_x27_244_, v_b_245_);
lean_dec(v_as_x27_244_);
lean_dec(v___y_243_);
return v_res_247_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs(lean_object* v_path_250_){
_start:
{
lean_object* v___x_252_; 
v___x_252_ = l_IO_FS_readFile(v_path_250_);
if (lean_obj_tag(v___x_252_) == 0)
{
lean_object* v_a_253_; lean_object* v___x_254_; lean_object* v___x_255_; lean_object* v___x_256_; lean_object* v___x_257_; lean_object* v___x_258_; lean_object* v___x_259_; lean_object* v___x_260_; lean_object* v___x_261_; 
v_a_253_ = lean_ctor_get(v___x_252_, 0);
lean_inc(v_a_253_);
lean_dec_ref_known(v___x_252_, 1);
v___x_254_ = lean_unsigned_to_nat(172432u);
v___x_255_ = lean_mk_empty_array_with_capacity(v___x_254_);
v___x_256_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs___closed__0));
v___x_257_ = lean_unsigned_to_nat(0u);
v___x_258_ = lean_box(0);
v___x_259_ = l_String_splitOnAux(v_a_253_, v___x_256_, v___x_257_, v___x_257_, v___x_257_, v___x_258_);
lean_dec(v_a_253_);
lean_inc(v___x_259_);
v___x_260_ = l_List_zipIdxTR___redArg(v___x_259_, v___x_257_);
v___x_261_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg(v___x_259_, v___x_260_, v___x_255_);
lean_dec(v___x_260_);
lean_dec(v___x_259_);
if (lean_obj_tag(v___x_261_) == 0)
{
lean_object* v_a_262_; lean_object* v___x_263_; uint8_t v___x_264_; 
v_a_262_ = lean_ctor_get(v___x_261_, 0);
lean_inc(v_a_262_);
v___x_263_ = lean_array_get_size(v_a_262_);
lean_dec(v_a_262_);
v___x_264_ = lean_nat_dec_eq(v___x_263_, v___x_254_);
if (v___x_264_ == 0)
{
lean_object* v___x_266_; uint8_t v_isShared_267_; uint8_t v_isSharedCheck_275_; 
v_isSharedCheck_275_ = !lean_is_exclusive(v___x_261_);
if (v_isSharedCheck_275_ == 0)
{
lean_object* v_unused_276_; 
v_unused_276_ = lean_ctor_get(v___x_261_, 0);
lean_dec(v_unused_276_);
v___x_266_ = v___x_261_;
v_isShared_267_ = v_isSharedCheck_275_;
goto v_resetjp_265_;
}
else
{
lean_dec(v___x_261_);
v___x_266_ = lean_box(0);
v_isShared_267_ = v_isSharedCheck_275_;
goto v_resetjp_265_;
}
v_resetjp_265_:
{
lean_object* v___x_268_; lean_object* v___x_269_; lean_object* v___x_270_; lean_object* v___x_271_; lean_object* v___x_273_; 
v___x_268_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs___closed__1));
v___x_269_ = l_Nat_reprFast(v___x_263_);
v___x_270_ = lean_string_append(v___x_268_, v___x_269_);
lean_dec_ref(v___x_269_);
v___x_271_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_271_, 0, v___x_270_);
if (v_isShared_267_ == 0)
{
lean_ctor_set_tag(v___x_266_, 1);
lean_ctor_set(v___x_266_, 0, v___x_271_);
v___x_273_ = v___x_266_;
goto v_reusejp_272_;
}
else
{
lean_object* v_reuseFailAlloc_274_; 
v_reuseFailAlloc_274_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_274_, 0, v___x_271_);
v___x_273_ = v_reuseFailAlloc_274_;
goto v_reusejp_272_;
}
v_reusejp_272_:
{
return v___x_273_;
}
}
}
else
{
return v___x_261_;
}
}
else
{
return v___x_261_;
}
}
else
{
lean_object* v_a_277_; lean_object* v___x_279_; uint8_t v_isShared_280_; uint8_t v_isSharedCheck_284_; 
v_a_277_ = lean_ctor_get(v___x_252_, 0);
v_isSharedCheck_284_ = !lean_is_exclusive(v___x_252_);
if (v_isSharedCheck_284_ == 0)
{
v___x_279_ = v___x_252_;
v_isShared_280_ = v_isSharedCheck_284_;
goto v_resetjp_278_;
}
else
{
lean_inc(v_a_277_);
lean_dec(v___x_252_);
v___x_279_ = lean_box(0);
v_isShared_280_ = v_isSharedCheck_284_;
goto v_resetjp_278_;
}
v_resetjp_278_:
{
lean_object* v___x_282_; 
if (v_isShared_280_ == 0)
{
v___x_282_ = v___x_279_;
goto v_reusejp_281_;
}
else
{
lean_object* v_reuseFailAlloc_283_; 
v_reuseFailAlloc_283_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_283_, 0, v_a_277_);
v___x_282_ = v_reuseFailAlloc_283_;
goto v_reusejp_281_;
}
v_reusejp_281_:
{
return v___x_282_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs___boxed(lean_object* v_path_285_, lean_object* v_a_286_){
_start:
{
lean_object* v_res_287_; 
v_res_287_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs(v_path_285_);
lean_dec_ref(v_path_285_);
return v_res_287_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0(lean_object* v___y_288_, lean_object* v_as_289_, lean_object* v_as_x27_290_, lean_object* v_b_291_, lean_object* v_a_292_){
_start:
{
lean_object* v___x_294_; 
v___x_294_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___redArg(v___y_288_, v_as_x27_290_, v_b_291_);
return v___x_294_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0___boxed(lean_object* v___y_295_, lean_object* v_as_296_, lean_object* v_as_x27_297_, lean_object* v_b_298_, lean_object* v_a_299_, lean_object* v___y_300_){
_start:
{
lean_object* v_res_301_; 
v_res_301_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs_spec__0(v___y_295_, v_as_296_, v_as_x27_297_, v_b_298_, v_a_299_);
lean_dec(v_as_x27_297_);
lean_dec(v_as_296_);
lean_dec(v___y_295_);
return v_res_301_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0(lean_object* v_as_305_, size_t v_sz_306_, size_t v_i_307_, lean_object* v_b_308_){
_start:
{
lean_object* v___y_311_; lean_object* v___y_312_; lean_object* v___y_313_; uint8_t v___x_330_; 
v___x_330_ = lean_usize_dec_lt(v_i_307_, v_sz_306_);
if (v___x_330_ == 0)
{
lean_object* v___x_331_; 
v___x_331_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_331_, 0, v_b_308_);
return v___x_331_;
}
else
{
lean_object* v_a_332_; lean_object* v___y_334_; lean_object* v___y_335_; lean_object* v___y_359_; lean_object* v___x_382_; lean_object* v___x_383_; 
v_a_332_ = lean_array_uget_borrowed(v_as_305_, v_i_307_);
v___x_382_ = ((lean_object*)(lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___closed__2));
lean_inc(v_a_332_);
v___x_383_ = l_Lean_Json_getObjVal_x3f(v_a_332_, v___x_382_);
if (lean_obj_tag(v___x_383_) == 0)
{
lean_object* v_a_384_; lean_object* v___x_386_; uint8_t v_isShared_387_; uint8_t v_isSharedCheck_391_; 
v_a_384_ = lean_ctor_get(v___x_383_, 0);
v_isSharedCheck_391_ = !lean_is_exclusive(v___x_383_);
if (v_isSharedCheck_391_ == 0)
{
v___x_386_ = v___x_383_;
v_isShared_387_ = v_isSharedCheck_391_;
goto v_resetjp_385_;
}
else
{
lean_inc(v_a_384_);
lean_dec(v___x_383_);
v___x_386_ = lean_box(0);
v_isShared_387_ = v_isSharedCheck_391_;
goto v_resetjp_385_;
}
v_resetjp_385_:
{
lean_object* v___x_389_; 
if (v_isShared_387_ == 0)
{
v___x_389_ = v___x_386_;
goto v_reusejp_388_;
}
else
{
lean_object* v_reuseFailAlloc_390_; 
v_reuseFailAlloc_390_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_390_, 0, v_a_384_);
v___x_389_ = v_reuseFailAlloc_390_;
goto v_reusejp_388_;
}
v_reusejp_388_:
{
v___y_359_ = v___x_389_;
goto v___jp_358_;
}
}
}
else
{
lean_object* v_a_392_; lean_object* v___x_393_; 
v_a_392_ = lean_ctor_get(v___x_383_, 0);
lean_inc(v_a_392_);
lean_dec_ref_known(v___x_383_, 1);
v___x_393_ = l_Lean_Json_getStr_x3f(v_a_392_);
v___y_359_ = v___x_393_;
goto v___jp_358_;
}
v___jp_333_:
{
lean_object* v___x_336_; 
v___x_336_ = l_IO_ofExcept___at___00Std_Time_Database_TZdb_parseTZIfFromDisk_spec__0___redArg(v___y_335_);
if (lean_obj_tag(v___x_336_) == 0)
{
lean_object* v_a_337_; lean_object* v___x_338_; lean_object* v___x_339_; 
v_a_337_ = lean_ctor_get(v___x_336_, 0);
lean_inc(v_a_337_);
lean_dec_ref_known(v___x_336_, 1);
v___x_338_ = ((lean_object*)(lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___closed__0));
lean_inc(v_a_332_);
v___x_339_ = l_Lean_Json_getObjVal_x3f(v_a_332_, v___x_338_);
if (lean_obj_tag(v___x_339_) == 0)
{
lean_object* v_a_340_; lean_object* v___x_342_; uint8_t v_isShared_343_; uint8_t v_isSharedCheck_347_; 
v_a_340_ = lean_ctor_get(v___x_339_, 0);
v_isSharedCheck_347_ = !lean_is_exclusive(v___x_339_);
if (v_isSharedCheck_347_ == 0)
{
v___x_342_ = v___x_339_;
v_isShared_343_ = v_isSharedCheck_347_;
goto v_resetjp_341_;
}
else
{
lean_inc(v_a_340_);
lean_dec(v___x_339_);
v___x_342_ = lean_box(0);
v_isShared_343_ = v_isSharedCheck_347_;
goto v_resetjp_341_;
}
v_resetjp_341_:
{
lean_object* v___x_345_; 
if (v_isShared_343_ == 0)
{
v___x_345_ = v___x_342_;
goto v_reusejp_344_;
}
else
{
lean_object* v_reuseFailAlloc_346_; 
v_reuseFailAlloc_346_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_346_, 0, v_a_340_);
v___x_345_ = v_reuseFailAlloc_346_;
goto v_reusejp_344_;
}
v_reusejp_344_:
{
v___y_311_ = v_a_337_;
v___y_312_ = v___y_334_;
v___y_313_ = v___x_345_;
goto v___jp_310_;
}
}
}
else
{
lean_object* v_a_348_; lean_object* v___x_349_; 
v_a_348_ = lean_ctor_get(v___x_339_, 0);
lean_inc(v_a_348_);
lean_dec_ref_known(v___x_339_, 1);
v___x_349_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number(v_a_348_);
v___y_311_ = v_a_337_;
v___y_312_ = v___y_334_;
v___y_313_ = v___x_349_;
goto v___jp_310_;
}
}
else
{
lean_object* v_a_350_; lean_object* v___x_352_; uint8_t v_isShared_353_; uint8_t v_isSharedCheck_357_; 
lean_dec_ref(v___y_334_);
lean_dec(v_b_308_);
v_a_350_ = lean_ctor_get(v___x_336_, 0);
v_isSharedCheck_357_ = !lean_is_exclusive(v___x_336_);
if (v_isSharedCheck_357_ == 0)
{
v___x_352_ = v___x_336_;
v_isShared_353_ = v_isSharedCheck_357_;
goto v_resetjp_351_;
}
else
{
lean_inc(v_a_350_);
lean_dec(v___x_336_);
v___x_352_ = lean_box(0);
v_isShared_353_ = v_isSharedCheck_357_;
goto v_resetjp_351_;
}
v_resetjp_351_:
{
lean_object* v___x_355_; 
if (v_isShared_353_ == 0)
{
v___x_355_ = v___x_352_;
goto v_reusejp_354_;
}
else
{
lean_object* v_reuseFailAlloc_356_; 
v_reuseFailAlloc_356_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_356_, 0, v_a_350_);
v___x_355_ = v_reuseFailAlloc_356_;
goto v_reusejp_354_;
}
v_reusejp_354_:
{
return v___x_355_;
}
}
}
}
v___jp_358_:
{
lean_object* v___x_360_; 
v___x_360_ = l_IO_ofExcept___at___00Std_Time_Database_TZdb_parseTZIfFromDisk_spec__0___redArg(v___y_359_);
if (lean_obj_tag(v___x_360_) == 0)
{
lean_object* v_a_361_; lean_object* v___x_362_; lean_object* v___x_363_; 
v_a_361_ = lean_ctor_get(v___x_360_, 0);
lean_inc(v_a_361_);
lean_dec_ref_known(v___x_360_, 1);
v___x_362_ = ((lean_object*)(lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___closed__1));
lean_inc(v_a_332_);
v___x_363_ = l_Lean_Json_getObjVal_x3f(v_a_332_, v___x_362_);
if (lean_obj_tag(v___x_363_) == 0)
{
lean_object* v_a_364_; lean_object* v___x_366_; uint8_t v_isShared_367_; uint8_t v_isSharedCheck_371_; 
v_a_364_ = lean_ctor_get(v___x_363_, 0);
v_isSharedCheck_371_ = !lean_is_exclusive(v___x_363_);
if (v_isSharedCheck_371_ == 0)
{
v___x_366_ = v___x_363_;
v_isShared_367_ = v_isSharedCheck_371_;
goto v_resetjp_365_;
}
else
{
lean_inc(v_a_364_);
lean_dec(v___x_363_);
v___x_366_ = lean_box(0);
v_isShared_367_ = v_isSharedCheck_371_;
goto v_resetjp_365_;
}
v_resetjp_365_:
{
lean_object* v___x_369_; 
if (v_isShared_367_ == 0)
{
v___x_369_ = v___x_366_;
goto v_reusejp_368_;
}
else
{
lean_object* v_reuseFailAlloc_370_; 
v_reuseFailAlloc_370_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_370_, 0, v_a_364_);
v___x_369_ = v_reuseFailAlloc_370_;
goto v_reusejp_368_;
}
v_reusejp_368_:
{
v___y_334_ = v_a_361_;
v___y_335_ = v___x_369_;
goto v___jp_333_;
}
}
}
else
{
lean_object* v_a_372_; lean_object* v___x_373_; 
v_a_372_ = lean_ctor_get(v___x_363_, 0);
lean_inc(v_a_372_);
lean_dec_ref_known(v___x_363_, 1);
v___x_373_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_number(v_a_372_);
v___y_334_ = v_a_361_;
v___y_335_ = v___x_373_;
goto v___jp_333_;
}
}
else
{
lean_object* v_a_374_; lean_object* v___x_376_; uint8_t v_isShared_377_; uint8_t v_isSharedCheck_381_; 
lean_dec(v_b_308_);
v_a_374_ = lean_ctor_get(v___x_360_, 0);
v_isSharedCheck_381_ = !lean_is_exclusive(v___x_360_);
if (v_isSharedCheck_381_ == 0)
{
v___x_376_ = v___x_360_;
v_isShared_377_ = v_isSharedCheck_381_;
goto v_resetjp_375_;
}
else
{
lean_inc(v_a_374_);
lean_dec(v___x_360_);
v___x_376_ = lean_box(0);
v_isShared_377_ = v_isSharedCheck_381_;
goto v_resetjp_375_;
}
v_resetjp_375_:
{
lean_object* v___x_379_; 
if (v_isShared_377_ == 0)
{
v___x_379_ = v___x_376_;
goto v_reusejp_378_;
}
else
{
lean_object* v_reuseFailAlloc_380_; 
v_reuseFailAlloc_380_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_380_, 0, v_a_374_);
v___x_379_ = v_reuseFailAlloc_380_;
goto v_reusejp_378_;
}
v_reusejp_378_:
{
return v___x_379_;
}
}
}
}
}
v___jp_310_:
{
lean_object* v___x_314_; 
v___x_314_ = l_IO_ofExcept___at___00Std_Time_Database_TZdb_parseTZIfFromDisk_spec__0___redArg(v___y_313_);
if (lean_obj_tag(v___x_314_) == 0)
{
lean_object* v_a_315_; lean_object* v___x_316_; lean_object* v___x_317_; lean_object* v___x_318_; size_t v___x_319_; size_t v___x_320_; 
v_a_315_ = lean_ctor_get(v___x_314_, 0);
lean_inc(v_a_315_);
lean_dec_ref_known(v___x_314_, 1);
v___x_316_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_316_, 0, v___y_311_);
lean_ctor_set(v___x_316_, 1, v_a_315_);
v___x_317_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_317_, 0, v___y_312_);
lean_ctor_set(v___x_317_, 1, v___x_316_);
v___x_318_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_318_, 0, v___x_317_);
lean_ctor_set(v___x_318_, 1, v_b_308_);
v___x_319_ = ((size_t)1ULL);
v___x_320_ = lean_usize_add(v_i_307_, v___x_319_);
v_i_307_ = v___x_320_;
v_b_308_ = v___x_318_;
goto _start;
}
else
{
lean_object* v_a_322_; lean_object* v___x_324_; uint8_t v_isShared_325_; uint8_t v_isSharedCheck_329_; 
lean_dec_ref(v___y_312_);
lean_dec_ref(v___y_311_);
lean_dec(v_b_308_);
v_a_322_ = lean_ctor_get(v___x_314_, 0);
v_isSharedCheck_329_ = !lean_is_exclusive(v___x_314_);
if (v_isSharedCheck_329_ == 0)
{
v___x_324_ = v___x_314_;
v_isShared_325_ = v_isSharedCheck_329_;
goto v_resetjp_323_;
}
else
{
lean_inc(v_a_322_);
lean_dec(v___x_314_);
v___x_324_ = lean_box(0);
v_isShared_325_ = v_isSharedCheck_329_;
goto v_resetjp_323_;
}
v_resetjp_323_:
{
lean_object* v___x_327_; 
if (v_isShared_325_ == 0)
{
v___x_327_ = v___x_324_;
goto v_reusejp_326_;
}
else
{
lean_object* v_reuseFailAlloc_328_; 
v_reuseFailAlloc_328_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_328_, 0, v_a_322_);
v___x_327_ = v_reuseFailAlloc_328_;
goto v_reusejp_326_;
}
v_reusejp_326_:
{
return v___x_327_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0___boxed(lean_object* v_as_394_, lean_object* v_sz_395_, lean_object* v_i_396_, lean_object* v_b_397_, lean_object* v___y_398_){
_start:
{
size_t v_sz_boxed_399_; size_t v_i_boxed_400_; lean_object* v_res_401_; 
v_sz_boxed_399_ = lean_unbox_usize(v_sz_395_);
lean_dec(v_sz_395_);
v_i_boxed_400_ = lean_unbox_usize(v_i_396_);
lean_dec(v_i_396_);
v_res_401_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0(v_as_394_, v_sz_boxed_399_, v_i_boxed_400_, v_b_397_);
lean_dec_ref(v_as_394_);
return v_res_401_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports(){
_start:
{
lean_object* v___x_406_; lean_object* v___x_407_; 
v___x_406_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_airportPath___closed__0));
v___x_407_ = l_IO_FS_readFile(v___x_406_);
if (lean_obj_tag(v___x_407_) == 0)
{
lean_object* v_a_408_; lean_object* v___x_409_; lean_object* v___x_410_; 
v_a_408_ = lean_ctor_get(v___x_407_, 0);
lean_inc(v_a_408_);
lean_dec_ref_known(v___x_407_, 1);
v___x_409_ = l_Lean_Json_parse(v_a_408_);
v___x_410_ = l_IO_ofExcept___at___00Std_Time_Database_TZdb_parseTZIfFromDisk_spec__0___redArg(v___x_409_);
if (lean_obj_tag(v___x_410_) == 0)
{
lean_object* v_a_411_; lean_object* v___x_412_; lean_object* v___x_413_; 
v_a_411_ = lean_ctor_get(v___x_410_, 0);
lean_inc(v_a_411_);
lean_dec_ref_known(v___x_410_, 1);
v___x_412_ = l_Lean_Json_getArr_x3f(v_a_411_);
v___x_413_ = l_IO_ofExcept___at___00Std_Time_Database_TZdb_parseTZIfFromDisk_spec__0___redArg(v___x_412_);
if (lean_obj_tag(v___x_413_) == 0)
{
lean_object* v_a_414_; lean_object* v___x_416_; uint8_t v_isShared_417_; uint8_t v_isSharedCheck_438_; 
v_a_414_ = lean_ctor_get(v___x_413_, 0);
v_isSharedCheck_438_ = !lean_is_exclusive(v___x_413_);
if (v_isSharedCheck_438_ == 0)
{
v___x_416_ = v___x_413_;
v_isShared_417_ = v_isSharedCheck_438_;
goto v_resetjp_415_;
}
else
{
lean_inc(v_a_414_);
lean_dec(v___x_413_);
v___x_416_ = lean_box(0);
v_isShared_417_ = v_isSharedCheck_438_;
goto v_resetjp_415_;
}
v_resetjp_415_:
{
lean_object* v___x_418_; lean_object* v___x_419_; uint8_t v___x_420_; 
v___x_418_ = lean_array_get_size(v_a_414_);
v___x_419_ = lean_unsigned_to_nat(6903u);
v___x_420_ = lean_nat_dec_eq(v___x_418_, v___x_419_);
if (v___x_420_ == 0)
{
lean_object* v___x_421_; lean_object* v___x_423_; 
lean_dec(v_a_414_);
v___x_421_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports___closed__1));
if (v_isShared_417_ == 0)
{
lean_ctor_set_tag(v___x_416_, 1);
lean_ctor_set(v___x_416_, 0, v___x_421_);
v___x_423_ = v___x_416_;
goto v_reusejp_422_;
}
else
{
lean_object* v_reuseFailAlloc_424_; 
v_reuseFailAlloc_424_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_424_, 0, v___x_421_);
v___x_423_ = v_reuseFailAlloc_424_;
goto v_reusejp_422_;
}
v_reusejp_422_:
{
return v___x_423_;
}
}
else
{
lean_object* v___x_425_; size_t v_sz_426_; size_t v___x_427_; lean_object* v___x_428_; 
lean_del_object(v___x_416_);
v___x_425_ = lean_box(0);
v_sz_426_ = lean_array_size(v_a_414_);
v___x_427_ = ((size_t)0ULL);
v___x_428_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports_spec__0(v_a_414_, v_sz_426_, v___x_427_, v___x_425_);
lean_dec(v_a_414_);
if (lean_obj_tag(v___x_428_) == 0)
{
lean_object* v_a_429_; lean_object* v___x_431_; uint8_t v_isShared_432_; uint8_t v_isSharedCheck_437_; 
v_a_429_ = lean_ctor_get(v___x_428_, 0);
v_isSharedCheck_437_ = !lean_is_exclusive(v___x_428_);
if (v_isSharedCheck_437_ == 0)
{
v___x_431_ = v___x_428_;
v_isShared_432_ = v_isSharedCheck_437_;
goto v_resetjp_430_;
}
else
{
lean_inc(v_a_429_);
lean_dec(v___x_428_);
v___x_431_ = lean_box(0);
v_isShared_432_ = v_isSharedCheck_437_;
goto v_resetjp_430_;
}
v_resetjp_430_:
{
lean_object* v___x_433_; lean_object* v___x_435_; 
v___x_433_ = l_List_reverse___redArg(v_a_429_);
if (v_isShared_432_ == 0)
{
lean_ctor_set(v___x_431_, 0, v___x_433_);
v___x_435_ = v___x_431_;
goto v_reusejp_434_;
}
else
{
lean_object* v_reuseFailAlloc_436_; 
v_reuseFailAlloc_436_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_436_, 0, v___x_433_);
v___x_435_ = v_reuseFailAlloc_436_;
goto v_reusejp_434_;
}
v_reusejp_434_:
{
return v___x_435_;
}
}
}
else
{
return v___x_428_;
}
}
}
}
else
{
lean_object* v_a_439_; lean_object* v___x_441_; uint8_t v_isShared_442_; uint8_t v_isSharedCheck_446_; 
v_a_439_ = lean_ctor_get(v___x_413_, 0);
v_isSharedCheck_446_ = !lean_is_exclusive(v___x_413_);
if (v_isSharedCheck_446_ == 0)
{
v___x_441_ = v___x_413_;
v_isShared_442_ = v_isSharedCheck_446_;
goto v_resetjp_440_;
}
else
{
lean_inc(v_a_439_);
lean_dec(v___x_413_);
v___x_441_ = lean_box(0);
v_isShared_442_ = v_isSharedCheck_446_;
goto v_resetjp_440_;
}
v_resetjp_440_:
{
lean_object* v___x_444_; 
if (v_isShared_442_ == 0)
{
v___x_444_ = v___x_441_;
goto v_reusejp_443_;
}
else
{
lean_object* v_reuseFailAlloc_445_; 
v_reuseFailAlloc_445_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_445_, 0, v_a_439_);
v___x_444_ = v_reuseFailAlloc_445_;
goto v_reusejp_443_;
}
v_reusejp_443_:
{
return v___x_444_;
}
}
}
}
else
{
lean_object* v_a_447_; lean_object* v___x_449_; uint8_t v_isShared_450_; uint8_t v_isSharedCheck_454_; 
v_a_447_ = lean_ctor_get(v___x_410_, 0);
v_isSharedCheck_454_ = !lean_is_exclusive(v___x_410_);
if (v_isSharedCheck_454_ == 0)
{
v___x_449_ = v___x_410_;
v_isShared_450_ = v_isSharedCheck_454_;
goto v_resetjp_448_;
}
else
{
lean_inc(v_a_447_);
lean_dec(v___x_410_);
v___x_449_ = lean_box(0);
v_isShared_450_ = v_isSharedCheck_454_;
goto v_resetjp_448_;
}
v_resetjp_448_:
{
lean_object* v___x_452_; 
if (v_isShared_450_ == 0)
{
v___x_452_ = v___x_449_;
goto v_reusejp_451_;
}
else
{
lean_object* v_reuseFailAlloc_453_; 
v_reuseFailAlloc_453_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_453_, 0, v_a_447_);
v___x_452_ = v_reuseFailAlloc_453_;
goto v_reusejp_451_;
}
v_reusejp_451_:
{
return v___x_452_;
}
}
}
}
else
{
lean_object* v_a_455_; lean_object* v___x_457_; uint8_t v_isShared_458_; uint8_t v_isSharedCheck_462_; 
v_a_455_ = lean_ctor_get(v___x_407_, 0);
v_isSharedCheck_462_ = !lean_is_exclusive(v___x_407_);
if (v_isSharedCheck_462_ == 0)
{
v___x_457_ = v___x_407_;
v_isShared_458_ = v_isSharedCheck_462_;
goto v_resetjp_456_;
}
else
{
lean_inc(v_a_455_);
lean_dec(v___x_407_);
v___x_457_ = lean_box(0);
v_isShared_458_ = v_isSharedCheck_462_;
goto v_resetjp_456_;
}
v_resetjp_456_:
{
lean_object* v___x_460_; 
if (v_isShared_458_ == 0)
{
v___x_460_ = v___x_457_;
goto v_reusejp_459_;
}
else
{
lean_object* v_reuseFailAlloc_461_; 
v_reuseFailAlloc_461_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_461_, 0, v_a_455_);
v___x_460_ = v_reuseFailAlloc_461_;
goto v_reusejp_459_;
}
v_reusejp_459_:
{
return v___x_460_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports___boxed(lean_object* v_a_463_){
_start:
{
lean_object* v_res_464_; 
v_res_464_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports();
return v_res_464_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport_spec__0(lean_object* v_x_466_){
_start:
{
if (lean_obj_tag(v_x_466_) == 0)
{
lean_object* v___x_467_; 
v___x_467_ = lean_box(0);
return v___x_467_;
}
else
{
lean_object* v_head_468_; lean_object* v_tail_469_; lean_object* v_fst_470_; lean_object* v___x_471_; uint8_t v___x_472_; 
v_head_468_ = lean_ctor_get(v_x_466_, 0);
v_tail_469_ = lean_ctor_get(v_x_466_, 1);
v_fst_470_ = lean_ctor_get(v_head_468_, 0);
v___x_471_ = ((lean_object*)(lp_lean1090_List_find_x3f___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport_spec__0___closed__0));
v___x_472_ = lean_string_dec_eq(v_fst_470_, v___x_471_);
if (v___x_472_ == 0)
{
v_x_466_ = v_tail_469_;
goto _start;
}
else
{
lean_object* v___x_474_; 
lean_inc(v_head_468_);
v___x_474_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_474_, 0, v_head_468_);
return v___x_474_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport_spec__0___boxed(lean_object* v_x_475_){
_start:
{
lean_object* v_res_476_; 
v_res_476_ = lp_lean1090_List_find_x3f___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport_spec__0(v_x_475_);
lean_dec(v_x_475_);
return v_res_476_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport(lean_object* v_timestamp_484_, lean_object* v_message_485_){
_start:
{
lean_object* v_fields_486_; lean_object* v_body_487_; 
v_fields_486_ = lean_ctor_get(v_message_485_, 0);
v_body_487_ = lean_ctor_get(v_fields_486_, 0);
if (lean_obj_tag(v_body_487_) == 4)
{
lean_object* v_decoded_488_; lean_object* v_address_489_; 
v_decoded_488_ = lean_ctor_get(v_message_485_, 1);
lean_inc_ref(v_decoded_488_);
lean_dec_ref(v_message_485_);
v_address_489_ = lean_ctor_get(v_decoded_488_, 1);
lean_inc(v_address_489_);
if (lean_obj_tag(v_address_489_) == 0)
{
lean_object* v___x_490_; 
lean_dec_ref(v_decoded_488_);
lean_dec_ref(v_timestamp_484_);
v___x_490_ = lean_box(0);
return v___x_490_;
}
else
{
lean_object* v_adsb_491_; lean_object* v_semanticADSB_492_; lean_object* v_val_493_; lean_object* v___x_495_; uint8_t v_isShared_496_; uint8_t v_isSharedCheck_621_; 
v_adsb_491_ = lean_ctor_get(v_decoded_488_, 5);
lean_inc(v_adsb_491_);
v_semanticADSB_492_ = lean_ctor_get(v_decoded_488_, 7);
lean_inc(v_semanticADSB_492_);
lean_dec_ref(v_decoded_488_);
v_val_493_ = lean_ctor_get(v_address_489_, 0);
v_isSharedCheck_621_ = !lean_is_exclusive(v_address_489_);
if (v_isSharedCheck_621_ == 0)
{
v___x_495_ = v_address_489_;
v_isShared_496_ = v_isSharedCheck_621_;
goto v_resetjp_494_;
}
else
{
lean_inc(v_val_493_);
lean_dec(v_address_489_);
v___x_495_ = lean_box(0);
v_isShared_496_ = v_isSharedCheck_621_;
goto v_resetjp_494_;
}
v_resetjp_494_:
{
lean_object* v___y_498_; uint8_t v___y_504_; 
if (lean_obj_tag(v_adsb_491_) == 0)
{
lean_object* v___x_506_; 
lean_del_object(v___x_495_);
lean_dec(v_val_493_);
lean_dec(v_semanticADSB_492_);
lean_dec_ref(v_timestamp_484_);
v___x_506_ = lean_box(0);
return v___x_506_;
}
else
{
if (lean_obj_tag(v_semanticADSB_492_) == 0)
{
lean_object* v___x_507_; 
lean_dec_ref_known(v_adsb_491_, 1);
lean_del_object(v___x_495_);
lean_dec(v_val_493_);
lean_dec_ref(v_timestamp_484_);
v___x_507_ = lean_box(0);
return v___x_507_;
}
else
{
lean_object* v_val_508_; lean_object* v___x_510_; uint8_t v_isShared_511_; uint8_t v_isSharedCheck_620_; 
v_val_508_ = lean_ctor_get(v_adsb_491_, 0);
v_isSharedCheck_620_ = !lean_is_exclusive(v_adsb_491_);
if (v_isSharedCheck_620_ == 0)
{
v___x_510_ = v_adsb_491_;
v_isShared_511_ = v_isSharedCheck_620_;
goto v_resetjp_509_;
}
else
{
lean_inc(v_val_508_);
lean_dec(v_adsb_491_);
v___x_510_ = lean_box(0);
v_isShared_511_ = v_isSharedCheck_620_;
goto v_resetjp_509_;
}
v_resetjp_509_:
{
lean_object* v_val_512_; lean_object* v___x_514_; uint8_t v_isShared_515_; uint8_t v_isSharedCheck_619_; 
v_val_512_ = lean_ctor_get(v_semanticADSB_492_, 0);
v_isSharedCheck_619_ = !lean_is_exclusive(v_semanticADSB_492_);
if (v_isSharedCheck_619_ == 0)
{
v___x_514_ = v_semanticADSB_492_;
v_isShared_515_ = v_isSharedCheck_619_;
goto v_resetjp_513_;
}
else
{
lean_inc(v_val_512_);
lean_dec(v_semanticADSB_492_);
v___x_514_ = lean_box(0);
v_isShared_515_ = v_isSharedCheck_619_;
goto v_resetjp_513_;
}
v_resetjp_513_:
{
lean_object* v___x_516_; lean_object* v___x_517_; lean_object* v___x_532_; lean_object* v___x_533_; lean_object* v___x_534_; uint8_t v___x_540_; lean_object* v___x_541_; lean_object* v___x_542_; lean_object* v___x_543_; lean_object* v___x_544_; lean_object* v___x_545_; lean_object* v___y_547_; lean_object* v___y_548_; lean_object* v___y_549_; lean_object* v___y_550_; lean_object* v___y_559_; uint8_t v___y_560_; lean_object* v___y_561_; lean_object* v___y_571_; uint8_t v___y_572_; lean_object* v___y_576_; lean_object* v___x_612_; uint8_t v___x_613_; 
v___x_516_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__0));
v___x_517_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_val_508_, v___x_516_);
v___x_532_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__1));
v___x_533_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_val_508_, v___x_532_);
v___x_534_ = lean_unsigned_to_nat(1u);
v___x_540_ = lean_nat_dec_eq(v___x_533_, v___x_534_);
lean_dec(v___x_533_);
v___x_541_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__2));
v___x_542_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_val_508_, v___x_541_);
v___x_543_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__3));
v___x_544_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_val_508_, v___x_543_);
v___x_545_ = lean_alloc_ctor(0, 2, 1);
lean_ctor_set(v___x_545_, 0, v___x_542_);
lean_ctor_set(v___x_545_, 1, v___x_544_);
lean_ctor_set_uint8(v___x_545_, sizeof(void*)*2, v___x_540_);
v___x_612_ = lean_unsigned_to_nat(5u);
v___x_613_ = lean_nat_dec_le(v___x_612_, v___x_517_);
if (v___x_613_ == 0)
{
lean_del_object(v___x_510_);
goto v___jp_607_;
}
else
{
lean_object* v___x_614_; uint8_t v___x_615_; 
v___x_614_ = lean_unsigned_to_nat(8u);
v___x_615_ = lean_nat_dec_le(v___x_517_, v___x_614_);
if (v___x_615_ == 0)
{
lean_del_object(v___x_510_);
goto v___jp_607_;
}
else
{
lean_object* v___x_617_; 
lean_dec(v___x_517_);
lean_del_object(v___x_514_);
lean_dec(v_val_512_);
lean_dec(v_val_508_);
if (v_isShared_511_ == 0)
{
lean_ctor_set(v___x_510_, 0, v___x_545_);
v___x_617_ = v___x_510_;
goto v_reusejp_616_;
}
else
{
lean_object* v_reuseFailAlloc_618_; 
v_reuseFailAlloc_618_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_618_, 0, v___x_545_);
v___x_617_ = v_reuseFailAlloc_618_;
goto v_reusejp_616_;
}
v_reusejp_616_:
{
v___y_498_ = v___x_617_;
goto v___jp_497_;
}
}
}
v___jp_518_:
{
lean_object* v___x_519_; uint8_t v___x_520_; 
v___x_519_ = lean_unsigned_to_nat(19u);
v___x_520_ = lean_nat_dec_eq(v___x_517_, v___x_519_);
if (v___x_520_ == 0)
{
lean_object* v___x_521_; uint8_t v___x_522_; 
v___x_521_ = lean_unsigned_to_nat(28u);
v___x_522_ = lean_nat_dec_eq(v___x_517_, v___x_521_);
if (v___x_522_ == 0)
{
lean_object* v___x_523_; uint8_t v___x_524_; 
v___x_523_ = lean_unsigned_to_nat(29u);
v___x_524_ = lean_nat_dec_eq(v___x_517_, v___x_523_);
if (v___x_524_ == 0)
{
lean_object* v___x_525_; uint8_t v___x_526_; 
v___x_525_ = lean_unsigned_to_nat(31u);
v___x_526_ = lean_nat_dec_eq(v___x_517_, v___x_525_);
lean_dec(v___x_517_);
if (v___x_526_ == 0)
{
uint8_t v___x_527_; 
v___x_527_ = 5;
v___y_504_ = v___x_527_;
goto v___jp_503_;
}
else
{
uint8_t v___x_528_; 
v___x_528_ = 4;
v___y_504_ = v___x_528_;
goto v___jp_503_;
}
}
else
{
uint8_t v___x_529_; 
lean_dec(v___x_517_);
v___x_529_ = 3;
v___y_504_ = v___x_529_;
goto v___jp_503_;
}
}
else
{
uint8_t v___x_530_; 
lean_dec(v___x_517_);
v___x_530_ = 2;
v___y_504_ = v___x_530_;
goto v___jp_503_;
}
}
else
{
uint8_t v___x_531_; 
lean_dec(v___x_517_);
v___x_531_ = 1;
v___y_504_ = v___x_531_;
goto v___jp_503_;
}
}
v___jp_535_:
{
uint8_t v___x_536_; 
v___x_536_ = lean_nat_dec_le(v___x_534_, v___x_517_);
if (v___x_536_ == 0)
{
goto v___jp_518_;
}
else
{
lean_object* v___x_537_; uint8_t v___x_538_; 
v___x_537_ = lean_unsigned_to_nat(4u);
v___x_538_ = lean_nat_dec_le(v___x_517_, v___x_537_);
if (v___x_538_ == 0)
{
goto v___jp_518_;
}
else
{
uint8_t v___x_539_; 
lean_dec(v___x_517_);
v___x_539_ = 0;
v___y_504_ = v___x_539_;
goto v___jp_503_;
}
}
}
v___jp_546_:
{
lean_object* v___x_551_; uint8_t v___x_552_; lean_object* v___x_553_; lean_object* v___x_554_; uint8_t v___x_555_; lean_object* v___x_556_; lean_object* v___x_557_; 
v___x_551_ = lean_unsigned_to_nat(20u);
v___x_552_ = lean_nat_dec_le(v___x_551_, v___x_517_);
lean_dec(v___x_517_);
v___x_553_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__4));
v___x_554_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_val_508_, v___x_553_);
lean_dec(v_val_508_);
v___x_555_ = lean_nat_dec_eq(v___x_554_, v___x_534_);
lean_dec(v___x_554_);
v___x_556_ = lean_alloc_ctor(0, 3, 2);
lean_ctor_set(v___x_556_, 0, v___y_548_);
lean_ctor_set(v___x_556_, 1, v___y_549_);
lean_ctor_set(v___x_556_, 2, v___y_550_);
lean_ctor_set_uint8(v___x_556_, sizeof(void*)*3, v___x_552_);
lean_ctor_set_uint8(v___x_556_, sizeof(void*)*3 + 1, v___x_555_);
v___x_557_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_557_, 0, v___x_545_);
lean_ctor_set(v___x_557_, 1, v___y_547_);
lean_ctor_set(v___x_557_, 2, v___x_556_);
v___y_498_ = v___x_557_;
goto v___jp_497_;
}
v___jp_558_:
{
lean_object* v___x_562_; lean_object* v___x_563_; 
v___x_562_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__5));
v___x_563_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_val_508_, v___x_562_);
if (v___y_560_ == 0)
{
lean_object* v___x_564_; 
lean_del_object(v___x_514_);
v___x_564_ = lean_box(0);
v___y_547_ = v___y_559_;
v___y_548_ = v___y_561_;
v___y_549_ = v___x_563_;
v___y_550_ = v___x_564_;
goto v___jp_546_;
}
else
{
lean_object* v___x_565_; lean_object* v___x_566_; lean_object* v___x_568_; 
v___x_565_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport___closed__6));
v___x_566_ = lp_lean1090_Lean1090_Impl_JSON_raw(v_val_508_, v___x_565_);
if (v_isShared_515_ == 0)
{
lean_ctor_set(v___x_514_, 0, v___x_566_);
v___x_568_ = v___x_514_;
goto v_reusejp_567_;
}
else
{
lean_object* v_reuseFailAlloc_569_; 
v_reuseFailAlloc_569_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_569_, 0, v___x_566_);
v___x_568_ = v_reuseFailAlloc_569_;
goto v_reusejp_567_;
}
v_reusejp_567_:
{
v___y_547_ = v___y_559_;
v___y_548_ = v___y_561_;
v___y_549_ = v___x_563_;
v___y_550_ = v___x_568_;
goto v___jp_546_;
}
}
}
v___jp_570_:
{
lean_object* v___x_573_; lean_object* v___x_574_; 
v___x_573_ = lean_unsigned_to_nat(29u);
v___x_574_ = lean_nat_sub(v___x_573_, v___x_517_);
v___y_559_ = v___y_571_;
v___y_560_ = v___y_572_;
v___y_561_ = v___x_574_;
goto v___jp_558_;
}
v___jp_575_:
{
lean_object* v___x_577_; uint8_t v___x_578_; 
v___x_577_ = lean_unsigned_to_nat(19u);
v___x_578_ = lean_nat_dec_lt(v___x_517_, v___x_577_);
if (v___x_578_ == 0)
{
lean_object* v___x_579_; uint8_t v___x_580_; 
v___x_579_ = lean_unsigned_to_nat(20u);
v___x_580_ = lean_nat_dec_eq(v___x_517_, v___x_579_);
if (v___x_580_ == 0)
{
lean_object* v___x_581_; uint8_t v___x_582_; 
v___x_581_ = lean_unsigned_to_nat(21u);
v___x_582_ = lean_nat_dec_eq(v___x_517_, v___x_581_);
if (v___x_582_ == 0)
{
lean_object* v___x_583_; 
v___x_583_ = lean_unsigned_to_nat(0u);
v___y_559_ = v___y_576_;
v___y_560_ = v___x_578_;
v___y_561_ = v___x_583_;
goto v___jp_558_;
}
else
{
v___y_571_ = v___y_576_;
v___y_572_ = v___x_578_;
goto v___jp_570_;
}
}
else
{
v___y_571_ = v___y_576_;
v___y_572_ = v___x_578_;
goto v___jp_570_;
}
}
else
{
lean_object* v___x_584_; lean_object* v___x_585_; 
v___x_584_ = lean_unsigned_to_nat(18u);
v___x_585_ = lean_nat_sub(v___x_584_, v___x_517_);
v___y_559_ = v___y_576_;
v___y_560_ = v___x_578_;
v___y_561_ = v___x_585_;
goto v___jp_558_;
}
}
v___jp_586_:
{
lean_object* v___x_587_; 
v___x_587_ = lean_box(0);
v___y_576_ = v___x_587_;
goto v___jp_575_;
}
v___jp_588_:
{
lean_object* v_oracleValues_589_; lean_object* v___x_590_; 
v_oracleValues_589_ = lean_ctor_get(v_val_512_, 2);
lean_inc(v_oracleValues_589_);
lean_dec(v_val_512_);
v___x_590_ = lp_lean1090_List_find_x3f___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport_spec__0(v_oracleValues_589_);
lean_dec(v_oracleValues_589_);
if (lean_obj_tag(v___x_590_) == 0)
{
goto v___jp_586_;
}
else
{
lean_object* v_val_591_; lean_object* v_snd_592_; 
v_val_591_ = lean_ctor_get(v___x_590_, 0);
lean_inc(v_val_591_);
lean_dec_ref_known(v___x_590_, 1);
v_snd_592_ = lean_ctor_get(v_val_591_, 1);
lean_inc(v_snd_592_);
lean_dec(v_val_591_);
if (lean_obj_tag(v_snd_592_) == 0)
{
goto v___jp_586_;
}
else
{
lean_object* v_val_593_; lean_object* v___x_595_; uint8_t v_isShared_596_; uint8_t v_isSharedCheck_601_; 
v_val_593_ = lean_ctor_get(v_snd_592_, 0);
v_isSharedCheck_601_ = !lean_is_exclusive(v_snd_592_);
if (v_isSharedCheck_601_ == 0)
{
v___x_595_ = v_snd_592_;
v_isShared_596_ = v_isSharedCheck_601_;
goto v_resetjp_594_;
}
else
{
lean_inc(v_val_593_);
lean_dec(v_snd_592_);
v___x_595_ = lean_box(0);
v_isShared_596_ = v_isSharedCheck_601_;
goto v_resetjp_594_;
}
v_resetjp_594_:
{
lean_object* v___x_597_; lean_object* v___x_599_; 
v___x_597_ = l_Rat_floor(v_val_593_);
if (v_isShared_596_ == 0)
{
lean_ctor_set(v___x_595_, 0, v___x_597_);
v___x_599_ = v___x_595_;
goto v_reusejp_598_;
}
else
{
lean_object* v_reuseFailAlloc_600_; 
v_reuseFailAlloc_600_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_600_, 0, v___x_597_);
v___x_599_ = v_reuseFailAlloc_600_;
goto v_reusejp_598_;
}
v_reusejp_598_:
{
v___y_576_ = v___x_599_;
goto v___jp_575_;
}
}
}
}
}
v___jp_602_:
{
lean_object* v___x_603_; uint8_t v___x_604_; 
v___x_603_ = lean_unsigned_to_nat(20u);
v___x_604_ = lean_nat_dec_le(v___x_603_, v___x_517_);
if (v___x_604_ == 0)
{
lean_dec_ref_known(v___x_545_, 2);
lean_del_object(v___x_514_);
lean_dec(v_val_512_);
lean_dec(v_val_508_);
goto v___jp_535_;
}
else
{
lean_object* v___x_605_; uint8_t v___x_606_; 
v___x_605_ = lean_unsigned_to_nat(22u);
v___x_606_ = lean_nat_dec_le(v___x_517_, v___x_605_);
if (v___x_606_ == 0)
{
lean_dec_ref_known(v___x_545_, 2);
lean_del_object(v___x_514_);
lean_dec(v_val_512_);
lean_dec(v_val_508_);
goto v___jp_535_;
}
else
{
goto v___jp_588_;
}
}
}
v___jp_607_:
{
lean_object* v___x_608_; uint8_t v___x_609_; 
v___x_608_ = lean_unsigned_to_nat(9u);
v___x_609_ = lean_nat_dec_le(v___x_608_, v___x_517_);
if (v___x_609_ == 0)
{
goto v___jp_602_;
}
else
{
lean_object* v___x_610_; uint8_t v___x_611_; 
v___x_610_ = lean_unsigned_to_nat(18u);
v___x_611_ = lean_nat_dec_le(v___x_517_, v___x_610_);
if (v___x_611_ == 0)
{
goto v___jp_602_;
}
else
{
goto v___jp_588_;
}
}
}
}
}
}
}
v___jp_497_:
{
lean_object* v___x_499_; lean_object* v___x_501_; 
v___x_499_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_499_, 0, v_val_493_);
lean_ctor_set(v___x_499_, 1, v_timestamp_484_);
lean_ctor_set(v___x_499_, 2, v___y_498_);
if (v_isShared_496_ == 0)
{
lean_ctor_set(v___x_495_, 0, v___x_499_);
v___x_501_ = v___x_495_;
goto v_reusejp_500_;
}
else
{
lean_object* v_reuseFailAlloc_502_; 
v_reuseFailAlloc_502_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_502_, 0, v___x_499_);
v___x_501_ = v_reuseFailAlloc_502_;
goto v_reusejp_500_;
}
v_reusejp_500_:
{
return v___x_501_;
}
}
v___jp_503_:
{
lean_object* v___x_505_; 
v___x_505_ = lean_alloc_ctor(2, 0, 1);
lean_ctor_set_uint8(v___x_505_, 0, v___y_504_);
v___y_498_ = v___x_505_;
goto v___jp_497_;
}
}
}
}
else
{
lean_object* v___x_622_; 
lean_dec_ref(v_message_485_);
lean_dec_ref(v_timestamp_484_);
v___x_622_ = lean_box(0);
return v___x_622_;
}
}
}
LEAN_EXPORT uint8_t lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance___lam__0(lean_object* v_x_623_){
_start:
{
uint8_t v___x_624_; 
v___x_624_ = 0;
return v___x_624_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance___lam__0___boxed(lean_object* v_x_625_){
_start:
{
uint8_t v_res_626_; lean_object* v_r_627_; 
v_res_626_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance___lam__0(v_x_625_);
lean_dec_ref(v_x_625_);
v_r_627_ = lean_box(v_res_626_);
return v_r_627_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance(lean_object* v_geo_629_, lean_object* v_state_630_, lean_object* v_timestamp_631_, lean_object* v_message_632_){
_start:
{
lean_object* v___x_633_; 
v___x_633_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_trackingReport(v_timestamp_631_, v_message_632_);
if (lean_obj_tag(v___x_633_) == 0)
{
lean_object* v___x_634_; lean_object* v___x_635_; 
lean_dec_ref(v_geo_629_);
v___x_634_ = lean_box(0);
v___x_635_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_635_, 0, v_state_630_);
lean_ctor_set(v___x_635_, 1, v___x_634_);
return v___x_635_;
}
else
{
lean_object* v_val_636_; lean_object* v___f_637_; lean_object* v___x_638_; 
v_val_636_ = lean_ctor_get(v___x_633_, 0);
lean_inc(v_val_636_);
lean_dec_ref_known(v___x_633_, 1);
v___f_637_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance___closed__0));
v___x_638_ = lp_lean1090_Lean1090_Impl_CPR_Policy_streamStep(v_geo_629_, v___f_637_, v_state_630_, v_val_636_);
return v___x_638_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume_spec__0(lean_object* v_as_639_, size_t v_sz_640_, size_t v_i_641_, lean_object* v_b_642_){
_start:
{
uint8_t v___x_644_; 
v___x_644_ = lean_usize_dec_lt(v_i_641_, v_sz_640_);
if (v___x_644_ == 0)
{
lean_object* v___x_645_; 
v___x_645_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_645_, 0, v_b_642_);
return v___x_645_;
}
else
{
lean_object* v_fst_646_; lean_object* v_snd_647_; lean_object* v___x_649_; uint8_t v_isShared_650_; uint8_t v_isSharedCheck_676_; 
v_fst_646_ = lean_ctor_get(v_b_642_, 0);
v_snd_647_ = lean_ctor_get(v_b_642_, 1);
v_isSharedCheck_676_ = !lean_is_exclusive(v_b_642_);
if (v_isSharedCheck_676_ == 0)
{
v___x_649_ = v_b_642_;
v_isShared_650_ = v_isSharedCheck_676_;
goto v_resetjp_648_;
}
else
{
lean_inc(v_snd_647_);
lean_inc(v_fst_646_);
lean_dec(v_b_642_);
v___x_649_ = lean_box(0);
v_isShared_650_ = v_isSharedCheck_676_;
goto v_resetjp_648_;
}
v_resetjp_648_:
{
lean_object* v_a_651_; lean_object* v_positions_653_; lean_object* v_position_673_; 
v_a_651_ = lean_array_uget_borrowed(v_as_639_, v_i_641_);
v_position_673_ = lean_ctor_get(v_a_651_, 1);
if (lean_obj_tag(v_position_673_) == 0)
{
v_positions_653_ = v_fst_646_;
goto v___jp_652_;
}
else
{
lean_object* v___x_674_; lean_object* v___x_675_; 
v___x_674_ = lean_unsigned_to_nat(1u);
v___x_675_ = lean_nat_add(v_fst_646_, v___x_674_);
lean_dec(v_fst_646_);
v_positions_653_ = v___x_675_;
goto v___jp_652_;
}
v___jp_652_:
{
lean_object* v_message_654_; lean_object* v_fields_655_; lean_object* v_decoded_656_; lean_object* v_parity_657_; lean_object* v_commB_658_; lean_object* v_semanticCommB_659_; lean_object* v___x_660_; lean_object* v___x_661_; lean_object* v___x_662_; lean_object* v___x_663_; lean_object* v___x_664_; lean_object* v___x_665_; lean_object* v___x_666_; lean_object* v___x_668_; 
v_message_654_ = lean_ctor_get(v_a_651_, 0);
v_fields_655_ = lean_ctor_get(v_message_654_, 0);
v_decoded_656_ = lean_ctor_get(v_message_654_, 1);
v_parity_657_ = lean_ctor_get(v_fields_655_, 1);
v_commB_658_ = lean_ctor_get(v_decoded_656_, 6);
v_semanticCommB_659_ = lean_ctor_get(v_decoded_656_, 8);
v___x_660_ = lean_nat_add(v_snd_647_, v_parity_657_);
lean_dec(v_snd_647_);
v___x_661_ = l_List_lengthTR___redArg(v_commB_658_);
v___x_662_ = lean_nat_add(v___x_660_, v___x_661_);
lean_dec(v___x_661_);
lean_dec(v___x_660_);
v___x_663_ = l_List_lengthTR___redArg(v_semanticCommB_659_);
v___x_664_ = lean_nat_add(v___x_662_, v___x_663_);
lean_dec(v___x_663_);
lean_dec(v___x_662_);
v___x_665_ = lean_cstr_to_nat("4294967296");
v___x_666_ = lean_nat_mod(v___x_664_, v___x_665_);
lean_dec(v___x_664_);
if (v_isShared_650_ == 0)
{
lean_ctor_set(v___x_649_, 1, v___x_666_);
lean_ctor_set(v___x_649_, 0, v_positions_653_);
v___x_668_ = v___x_649_;
goto v_reusejp_667_;
}
else
{
lean_object* v_reuseFailAlloc_672_; 
v_reuseFailAlloc_672_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_672_, 0, v_positions_653_);
lean_ctor_set(v_reuseFailAlloc_672_, 1, v___x_666_);
v___x_668_ = v_reuseFailAlloc_672_;
goto v_reusejp_667_;
}
v_reusejp_667_:
{
size_t v___x_669_; size_t v___x_670_; 
v___x_669_ = ((size_t)1ULL);
v___x_670_ = lean_usize_add(v_i_641_, v___x_669_);
v_i_641_ = v___x_670_;
v_b_642_ = v___x_668_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume_spec__0___boxed(lean_object* v_as_677_, lean_object* v_sz_678_, lean_object* v_i_679_, lean_object* v_b_680_, lean_object* v___y_681_){
_start:
{
size_t v_sz_boxed_682_; size_t v_i_boxed_683_; lean_object* v_res_684_; 
v_sz_boxed_682_ = lean_unbox_usize(v_sz_678_);
lean_dec(v_sz_678_);
v_i_boxed_683_ = lean_unbox_usize(v_i_679_);
lean_dec(v_i_679_);
v_res_684_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume_spec__0(v_as_677_, v_sz_boxed_682_, v_i_boxed_683_, v_b_680_);
lean_dec_ref(v_as_677_);
return v_res_684_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume(lean_object* v_output_691_, lean_object* v_state_692_){
_start:
{
lean_object* v___x_694_; lean_object* v___x_695_; uint8_t v___x_696_; 
v___x_694_ = lean_array_get_size(v_output_691_);
v___x_695_ = lean_unsigned_to_nat(172432u);
v___x_696_ = lean_nat_dec_eq(v___x_694_, v___x_695_);
if (v___x_696_ == 0)
{
lean_object* v___x_697_; lean_object* v___x_698_; 
lean_dec_ref(v_state_692_);
v___x_697_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__1));
v___x_698_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_698_, 0, v___x_697_);
return v___x_698_;
}
else
{
lean_object* v_aircraft_699_; lean_object* v___x_701_; uint8_t v_isShared_702_; uint8_t v_isSharedCheck_750_; 
v_aircraft_699_ = lean_ctor_get(v_state_692_, 0);
v_isSharedCheck_750_ = !lean_is_exclusive(v_state_692_);
if (v_isSharedCheck_750_ == 0)
{
lean_object* v_unused_751_; 
v_unused_751_ = lean_ctor_get(v_state_692_, 1);
lean_dec(v_unused_751_);
v___x_701_ = v_state_692_;
v_isShared_702_ = v_isSharedCheck_750_;
goto v_resetjp_700_;
}
else
{
lean_inc(v_aircraft_699_);
lean_dec(v_state_692_);
v___x_701_ = lean_box(0);
v_isShared_702_ = v_isSharedCheck_750_;
goto v_resetjp_700_;
}
v_resetjp_700_:
{
lean_object* v_positions_703_; lean_object* v_checksum_704_; lean_object* v___x_706_; 
v_positions_703_ = lean_unsigned_to_nat(0u);
v_checksum_704_ = l_List_lengthTR___redArg(v_aircraft_699_);
lean_dec(v_aircraft_699_);
lean_inc(v_checksum_704_);
if (v_isShared_702_ == 0)
{
lean_ctor_set(v___x_701_, 1, v_checksum_704_);
lean_ctor_set(v___x_701_, 0, v_positions_703_);
v___x_706_ = v___x_701_;
goto v_reusejp_705_;
}
else
{
lean_object* v_reuseFailAlloc_749_; 
v_reuseFailAlloc_749_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_749_, 0, v_positions_703_);
lean_ctor_set(v_reuseFailAlloc_749_, 1, v_checksum_704_);
v___x_706_ = v_reuseFailAlloc_749_;
goto v_reusejp_705_;
}
v_reusejp_705_:
{
size_t v_sz_707_; size_t v___x_708_; lean_object* v___x_709_; 
v_sz_707_ = lean_array_size(v_output_691_);
v___x_708_ = ((size_t)0ULL);
v___x_709_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume_spec__0(v_output_691_, v_sz_707_, v___x_708_, v___x_706_);
if (lean_obj_tag(v___x_709_) == 0)
{
lean_object* v_a_710_; lean_object* v_fst_711_; lean_object* v_snd_712_; lean_object* v___x_713_; lean_object* v___x_714_; lean_object* v___x_715_; lean_object* v___x_716_; lean_object* v___x_717_; lean_object* v___x_718_; lean_object* v___x_719_; lean_object* v___x_720_; lean_object* v___x_721_; lean_object* v___x_722_; lean_object* v___x_723_; lean_object* v___x_724_; 
v_a_710_ = lean_ctor_get(v___x_709_, 0);
lean_inc(v_a_710_);
lean_dec_ref_known(v___x_709_, 1);
v_fst_711_ = lean_ctor_get(v_a_710_, 0);
lean_inc(v_fst_711_);
v_snd_712_ = lean_ctor_get(v_a_710_, 1);
lean_inc(v_snd_712_);
lean_dec(v_a_710_);
v___x_713_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__2));
v___x_714_ = l_Nat_reprFast(v___x_694_);
v___x_715_ = lean_string_append(v___x_713_, v___x_714_);
lean_dec_ref(v___x_714_);
v___x_716_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__3));
v___x_717_ = lean_string_append(v___x_715_, v___x_716_);
v___x_718_ = l_Nat_reprFast(v_checksum_704_);
v___x_719_ = lean_string_append(v___x_717_, v___x_718_);
lean_dec_ref(v___x_718_);
v___x_720_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__4));
v___x_721_ = lean_string_append(v___x_719_, v___x_720_);
v___x_722_ = l_Nat_reprFast(v_snd_712_);
v___x_723_ = lean_string_append(v___x_721_, v___x_722_);
lean_dec_ref(v___x_722_);
v___x_724_ = l_IO_eprintln___at___00__private_Init_System_IO_0__IO_eprintlnAux_spec__0(v___x_723_);
if (lean_obj_tag(v___x_724_) == 0)
{
lean_object* v___x_726_; uint8_t v_isShared_727_; uint8_t v_isSharedCheck_731_; 
v_isSharedCheck_731_ = !lean_is_exclusive(v___x_724_);
if (v_isSharedCheck_731_ == 0)
{
lean_object* v_unused_732_; 
v_unused_732_ = lean_ctor_get(v___x_724_, 0);
lean_dec(v_unused_732_);
v___x_726_ = v___x_724_;
v_isShared_727_ = v_isSharedCheck_731_;
goto v_resetjp_725_;
}
else
{
lean_dec(v___x_724_);
v___x_726_ = lean_box(0);
v_isShared_727_ = v_isSharedCheck_731_;
goto v_resetjp_725_;
}
v_resetjp_725_:
{
lean_object* v___x_729_; 
if (v_isShared_727_ == 0)
{
lean_ctor_set(v___x_726_, 0, v_fst_711_);
v___x_729_ = v___x_726_;
goto v_reusejp_728_;
}
else
{
lean_object* v_reuseFailAlloc_730_; 
v_reuseFailAlloc_730_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_730_, 0, v_fst_711_);
v___x_729_ = v_reuseFailAlloc_730_;
goto v_reusejp_728_;
}
v_reusejp_728_:
{
return v___x_729_;
}
}
}
else
{
lean_object* v_a_733_; lean_object* v___x_735_; uint8_t v_isShared_736_; uint8_t v_isSharedCheck_740_; 
lean_dec(v_fst_711_);
v_a_733_ = lean_ctor_get(v___x_724_, 0);
v_isSharedCheck_740_ = !lean_is_exclusive(v___x_724_);
if (v_isSharedCheck_740_ == 0)
{
v___x_735_ = v___x_724_;
v_isShared_736_ = v_isSharedCheck_740_;
goto v_resetjp_734_;
}
else
{
lean_inc(v_a_733_);
lean_dec(v___x_724_);
v___x_735_ = lean_box(0);
v_isShared_736_ = v_isSharedCheck_740_;
goto v_resetjp_734_;
}
v_resetjp_734_:
{
lean_object* v___x_738_; 
if (v_isShared_736_ == 0)
{
v___x_738_ = v___x_735_;
goto v_reusejp_737_;
}
else
{
lean_object* v_reuseFailAlloc_739_; 
v_reuseFailAlloc_739_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_739_, 0, v_a_733_);
v___x_738_ = v_reuseFailAlloc_739_;
goto v_reusejp_737_;
}
v_reusejp_737_:
{
return v___x_738_;
}
}
}
}
else
{
lean_object* v_a_741_; lean_object* v___x_743_; uint8_t v_isShared_744_; uint8_t v_isSharedCheck_748_; 
lean_dec(v_checksum_704_);
v_a_741_ = lean_ctor_get(v___x_709_, 0);
v_isSharedCheck_748_ = !lean_is_exclusive(v___x_709_);
if (v_isSharedCheck_748_ == 0)
{
v___x_743_ = v___x_709_;
v_isShared_744_ = v_isSharedCheck_748_;
goto v_resetjp_742_;
}
else
{
lean_inc(v_a_741_);
lean_dec(v___x_709_);
v___x_743_ = lean_box(0);
v_isShared_744_ = v_isSharedCheck_748_;
goto v_resetjp_742_;
}
v_resetjp_742_:
{
lean_object* v___x_746_; 
if (v_isShared_744_ == 0)
{
v___x_746_ = v___x_743_;
goto v_reusejp_745_;
}
else
{
lean_object* v_reuseFailAlloc_747_; 
v_reuseFailAlloc_747_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_747_, 0, v_a_741_);
v___x_746_ = v_reuseFailAlloc_747_;
goto v_reusejp_745_;
}
v_reusejp_745_:
{
return v___x_746_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___boxed(lean_object* v_output_752_, lean_object* v_state_753_, lean_object* v_a_754_){
_start:
{
lean_object* v_res_755_; 
v_res_755_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume(v_output_752_, v_state_753_);
lean_dec_ref(v_output_752_);
return v_res_755_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0(uint8_t v_cpr_759_, lean_object* v_geo_760_, lean_object* v_as_761_, size_t v_sz_762_, size_t v_i_763_, lean_object* v_b_764_){
_start:
{
uint8_t v___x_766_; 
v___x_766_ = lean_usize_dec_lt(v_i_763_, v_sz_762_);
if (v___x_766_ == 0)
{
lean_object* v___x_767_; 
lean_dec_ref(v_geo_760_);
v___x_767_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_767_, 0, v_b_764_);
return v___x_767_;
}
else
{
lean_object* v_a_768_; lean_object* v_timestamp_769_; lean_object* v_bytes_770_; lean_object* v___x_772_; uint8_t v_isShared_773_; uint8_t v_isSharedCheck_801_; 
v_a_768_ = lean_array_uget(v_as_761_, v_i_763_);
v_timestamp_769_ = lean_ctor_get(v_a_768_, 0);
v_bytes_770_ = lean_ctor_get(v_a_768_, 1);
v_isSharedCheck_801_ = !lean_is_exclusive(v_a_768_);
if (v_isSharedCheck_801_ == 0)
{
v___x_772_ = v_a_768_;
v_isShared_773_ = v_isSharedCheck_801_;
goto v_resetjp_771_;
}
else
{
lean_inc(v_bytes_770_);
lean_inc(v_timestamp_769_);
lean_dec(v_a_768_);
v___x_772_ = lean_box(0);
v_isShared_773_ = v_isSharedCheck_801_;
goto v_resetjp_771_;
}
v_resetjp_771_:
{
lean_object* v___x_774_; 
v___x_774_ = lp_lean1090_Lean1090_Impl_decode(v_bytes_770_);
lean_dec(v_bytes_770_);
if (lean_obj_tag(v___x_774_) == 1)
{
lean_object* v_val_775_; lean_object* v_fst_776_; lean_object* v_snd_777_; lean_object* v___x_779_; uint8_t v_isShared_780_; uint8_t v_isSharedCheck_798_; 
v_val_775_ = lean_ctor_get(v___x_774_, 0);
lean_inc(v_val_775_);
lean_dec_ref_known(v___x_774_, 1);
v_fst_776_ = lean_ctor_get(v_b_764_, 0);
v_snd_777_ = lean_ctor_get(v_b_764_, 1);
v_isSharedCheck_798_ = !lean_is_exclusive(v_b_764_);
if (v_isSharedCheck_798_ == 0)
{
v___x_779_ = v_b_764_;
v_isShared_780_ = v_isSharedCheck_798_;
goto v_resetjp_778_;
}
else
{
lean_inc(v_snd_777_);
lean_inc(v_fst_776_);
lean_dec(v_b_764_);
v___x_779_ = lean_box(0);
v_isShared_780_ = v_isSharedCheck_798_;
goto v_resetjp_778_;
}
v_resetjp_778_:
{
lean_object* v_state_782_; lean_object* v_position_783_; 
if (v_cpr_759_ == 0)
{
lean_object* v_position_794_; 
lean_dec_ref(v_timestamp_769_);
v_position_794_ = lean_box(0);
v_state_782_ = v_snd_777_;
v_position_783_ = v_position_794_;
goto v___jp_781_;
}
else
{
lean_object* v___x_795_; lean_object* v_fst_796_; lean_object* v_snd_797_; 
lean_inc(v_val_775_);
lean_inc_ref(v_geo_760_);
v___x_795_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance(v_geo_760_, v_snd_777_, v_timestamp_769_, v_val_775_);
v_fst_796_ = lean_ctor_get(v___x_795_, 0);
lean_inc(v_fst_796_);
v_snd_797_ = lean_ctor_get(v___x_795_, 1);
lean_inc(v_snd_797_);
lean_dec_ref(v___x_795_);
v_state_782_ = v_fst_796_;
v_position_783_ = v_snd_797_;
goto v___jp_781_;
}
v___jp_781_:
{
lean_object* v___x_785_; 
if (v_isShared_773_ == 0)
{
lean_ctor_set(v___x_772_, 1, v_position_783_);
lean_ctor_set(v___x_772_, 0, v_val_775_);
v___x_785_ = v___x_772_;
goto v_reusejp_784_;
}
else
{
lean_object* v_reuseFailAlloc_793_; 
v_reuseFailAlloc_793_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_793_, 0, v_val_775_);
lean_ctor_set(v_reuseFailAlloc_793_, 1, v_position_783_);
v___x_785_ = v_reuseFailAlloc_793_;
goto v_reusejp_784_;
}
v_reusejp_784_:
{
lean_object* v___x_786_; lean_object* v___x_788_; 
v___x_786_ = lean_array_push(v_fst_776_, v___x_785_);
if (v_isShared_780_ == 0)
{
lean_ctor_set(v___x_779_, 1, v_state_782_);
lean_ctor_set(v___x_779_, 0, v___x_786_);
v___x_788_ = v___x_779_;
goto v_reusejp_787_;
}
else
{
lean_object* v_reuseFailAlloc_792_; 
v_reuseFailAlloc_792_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_792_, 0, v___x_786_);
lean_ctor_set(v_reuseFailAlloc_792_, 1, v_state_782_);
v___x_788_ = v_reuseFailAlloc_792_;
goto v_reusejp_787_;
}
v_reusejp_787_:
{
size_t v___x_789_; size_t v___x_790_; 
v___x_789_ = ((size_t)1ULL);
v___x_790_ = lean_usize_add(v_i_763_, v___x_789_);
v_i_763_ = v___x_790_;
v_b_764_ = v___x_788_;
goto _start;
}
}
}
}
}
else
{
lean_object* v___x_799_; lean_object* v___x_800_; 
lean_dec(v___x_774_);
lean_del_object(v___x_772_);
lean_dec_ref(v_timestamp_769_);
lean_dec_ref(v_b_764_);
lean_dec_ref(v_geo_760_);
v___x_799_ = ((lean_object*)(lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0___closed__1));
v___x_800_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_800_, 0, v___x_799_);
return v___x_800_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0___boxed(lean_object* v_cpr_802_, lean_object* v_geo_803_, lean_object* v_as_804_, lean_object* v_sz_805_, lean_object* v_i_806_, lean_object* v_b_807_, lean_object* v___y_808_){
_start:
{
uint8_t v_cpr_boxed_809_; size_t v_sz_boxed_810_; size_t v_i_boxed_811_; lean_object* v_res_812_; 
v_cpr_boxed_809_ = lean_unbox(v_cpr_802_);
v_sz_boxed_810_ = lean_unbox_usize(v_sz_805_);
lean_dec(v_sz_805_);
v_i_boxed_811_ = lean_unbox_usize(v_i_806_);
lean_dec(v_i_806_);
v_res_812_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0(v_cpr_boxed_809_, v_geo_803_, v_as_804_, v_sz_boxed_810_, v_i_boxed_811_, v_b_807_);
lean_dec_ref(v_as_804_);
return v_res_812_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce(lean_object* v_inputs_816_, lean_object* v_geo_817_, uint8_t v_cpr_818_){
_start:
{
lean_object* v___x_820_; lean_object* v_output_821_; lean_object* v_state_822_; lean_object* v___x_823_; lean_object* v___x_824_; size_t v_sz_825_; size_t v___x_826_; lean_object* v___x_827_; 
v___x_820_ = lean_array_get_size(v_inputs_816_);
v_output_821_ = lean_mk_empty_array_with_capacity(v___x_820_);
v_state_822_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce___closed__0));
v___x_823_ = lean_io_mono_nanos_now();
v___x_824_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_824_, 0, v_output_821_);
lean_ctor_set(v___x_824_, 1, v_state_822_);
v_sz_825_ = lean_array_size(v_inputs_816_);
v___x_826_ = ((size_t)0ULL);
v___x_827_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0(v_cpr_818_, v_geo_817_, v_inputs_816_, v_sz_825_, v___x_826_, v___x_824_);
if (lean_obj_tag(v___x_827_) == 0)
{
lean_object* v_a_828_; lean_object* v_fst_829_; lean_object* v_snd_830_; lean_object* v___x_832_; uint8_t v_isShared_833_; uint8_t v_isSharedCheck_856_; 
v_a_828_ = lean_ctor_get(v___x_827_, 0);
lean_inc(v_a_828_);
lean_dec_ref_known(v___x_827_, 1);
v_fst_829_ = lean_ctor_get(v_a_828_, 0);
v_snd_830_ = lean_ctor_get(v_a_828_, 1);
v_isSharedCheck_856_ = !lean_is_exclusive(v_a_828_);
if (v_isSharedCheck_856_ == 0)
{
v___x_832_ = v_a_828_;
v_isShared_833_ = v_isSharedCheck_856_;
goto v_resetjp_831_;
}
else
{
lean_inc(v_snd_830_);
lean_inc(v_fst_829_);
lean_dec(v_a_828_);
v___x_832_ = lean_box(0);
v_isShared_833_ = v_isSharedCheck_856_;
goto v_resetjp_831_;
}
v_resetjp_831_:
{
lean_object* v___x_834_; lean_object* v___x_835_; 
v___x_834_ = lean_io_mono_nanos_now();
v___x_835_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume(v_fst_829_, v_snd_830_);
lean_dec(v_fst_829_);
if (lean_obj_tag(v___x_835_) == 0)
{
lean_object* v_a_836_; lean_object* v___x_838_; uint8_t v_isShared_839_; uint8_t v_isSharedCheck_847_; 
v_a_836_ = lean_ctor_get(v___x_835_, 0);
v_isSharedCheck_847_ = !lean_is_exclusive(v___x_835_);
if (v_isSharedCheck_847_ == 0)
{
v___x_838_ = v___x_835_;
v_isShared_839_ = v_isSharedCheck_847_;
goto v_resetjp_837_;
}
else
{
lean_inc(v_a_836_);
lean_dec(v___x_835_);
v___x_838_ = lean_box(0);
v_isShared_839_ = v_isSharedCheck_847_;
goto v_resetjp_837_;
}
v_resetjp_837_:
{
lean_object* v___x_840_; lean_object* v___x_842_; 
v___x_840_ = lean_nat_sub(v___x_834_, v___x_823_);
lean_dec(v___x_823_);
lean_dec(v___x_834_);
if (v_isShared_833_ == 0)
{
lean_ctor_set(v___x_832_, 1, v_a_836_);
lean_ctor_set(v___x_832_, 0, v___x_840_);
v___x_842_ = v___x_832_;
goto v_reusejp_841_;
}
else
{
lean_object* v_reuseFailAlloc_846_; 
v_reuseFailAlloc_846_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_846_, 0, v___x_840_);
lean_ctor_set(v_reuseFailAlloc_846_, 1, v_a_836_);
v___x_842_ = v_reuseFailAlloc_846_;
goto v_reusejp_841_;
}
v_reusejp_841_:
{
lean_object* v___x_844_; 
if (v_isShared_839_ == 0)
{
lean_ctor_set(v___x_838_, 0, v___x_842_);
v___x_844_ = v___x_838_;
goto v_reusejp_843_;
}
else
{
lean_object* v_reuseFailAlloc_845_; 
v_reuseFailAlloc_845_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_845_, 0, v___x_842_);
v___x_844_ = v_reuseFailAlloc_845_;
goto v_reusejp_843_;
}
v_reusejp_843_:
{
return v___x_844_;
}
}
}
}
else
{
lean_object* v_a_848_; lean_object* v___x_850_; uint8_t v_isShared_851_; uint8_t v_isSharedCheck_855_; 
lean_dec(v___x_834_);
lean_del_object(v___x_832_);
lean_dec(v___x_823_);
v_a_848_ = lean_ctor_get(v___x_835_, 0);
v_isSharedCheck_855_ = !lean_is_exclusive(v___x_835_);
if (v_isSharedCheck_855_ == 0)
{
v___x_850_ = v___x_835_;
v_isShared_851_ = v_isSharedCheck_855_;
goto v_resetjp_849_;
}
else
{
lean_inc(v_a_848_);
lean_dec(v___x_835_);
v___x_850_ = lean_box(0);
v_isShared_851_ = v_isSharedCheck_855_;
goto v_resetjp_849_;
}
v_resetjp_849_:
{
lean_object* v___x_853_; 
if (v_isShared_851_ == 0)
{
v___x_853_ = v___x_850_;
goto v_reusejp_852_;
}
else
{
lean_object* v_reuseFailAlloc_854_; 
v_reuseFailAlloc_854_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_854_, 0, v_a_848_);
v___x_853_ = v_reuseFailAlloc_854_;
goto v_reusejp_852_;
}
v_reusejp_852_:
{
return v___x_853_;
}
}
}
}
}
else
{
lean_object* v_a_857_; lean_object* v___x_859_; uint8_t v_isShared_860_; uint8_t v_isSharedCheck_864_; 
lean_dec(v___x_823_);
v_a_857_ = lean_ctor_get(v___x_827_, 0);
v_isSharedCheck_864_ = !lean_is_exclusive(v___x_827_);
if (v_isSharedCheck_864_ == 0)
{
v___x_859_ = v___x_827_;
v_isShared_860_ = v_isSharedCheck_864_;
goto v_resetjp_858_;
}
else
{
lean_inc(v_a_857_);
lean_dec(v___x_827_);
v___x_859_ = lean_box(0);
v_isShared_860_ = v_isSharedCheck_864_;
goto v_resetjp_858_;
}
v_resetjp_858_:
{
lean_object* v___x_862_; 
if (v_isShared_860_ == 0)
{
v___x_862_ = v___x_859_;
goto v_reusejp_861_;
}
else
{
lean_object* v_reuseFailAlloc_863_; 
v_reuseFailAlloc_863_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_863_, 0, v_a_857_);
v___x_862_ = v_reuseFailAlloc_863_;
goto v_reusejp_861_;
}
v_reusejp_861_:
{
return v___x_862_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce___boxed(lean_object* v_inputs_865_, lean_object* v_geo_866_, lean_object* v_cpr_867_, lean_object* v_a_868_){
_start:
{
uint8_t v_cpr_boxed_869_; lean_object* v_res_870_; 
v_cpr_boxed_869_ = lean_unbox(v_cpr_867_);
v_res_870_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce(v_inputs_865_, v_geo_866_, v_cpr_boxed_869_);
lean_dec_ref(v_inputs_865_);
return v_res_870_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0_spec__0(lean_object* v_s_871_){
_start:
{
lean_object* v___x_873_; lean_object* v_putStr_874_; lean_object* v___x_875_; 
v___x_873_ = lean_get_stdout();
v_putStr_874_ = lean_ctor_get(v___x_873_, 4);
lean_inc_ref(v_putStr_874_);
lean_dec_ref(v___x_873_);
v___x_875_ = lean_apply_2(v_putStr_874_, v_s_871_, lean_box(0));
return v___x_875_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0_spec__0___boxed(lean_object* v_s_876_, lean_object* v_a_877_){
_start:
{
lean_object* v_res_878_; 
v_res_878_ = lp_lean1090_IO_print___at___00IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0_spec__0(v_s_876_);
return v_res_878_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(lean_object* v_s_879_){
_start:
{
uint32_t v___x_881_; lean_object* v___x_882_; lean_object* v___x_883_; 
v___x_881_ = 10;
v___x_882_ = lean_string_push(v_s_879_, v___x_881_);
v___x_883_ = lp_lean1090_IO_print___at___00IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0_spec__0(v___x_882_);
return v___x_883_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0___boxed(lean_object* v_s_884_, lean_object* v_a_885_){
_start:
{
lean_object* v_res_886_; 
v_res_886_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v_s_884_);
return v_res_886_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg(lean_object* v_val_893_, lean_object* v_inputs_894_, lean_object* v_geo_895_, uint8_t v_cpr_896_){
_start:
{
lean_object* v_getLine_898_; lean_object* v___x_899_; lean_object* v___x_900_; 
v_getLine_898_ = lean_ctor_get(v_val_893_, 3);
v___x_899_ = lean_box(0);
lean_inc_ref(v_getLine_898_);
v___x_900_ = lean_apply_1(v_getLine_898_, lean_box(0));
if (lean_obj_tag(v___x_900_) == 0)
{
lean_object* v_a_901_; lean_object* v___x_903_; uint8_t v_isShared_904_; uint8_t v_isSharedCheck_947_; 
v_a_901_ = lean_ctor_get(v___x_900_, 0);
v_isSharedCheck_947_ = !lean_is_exclusive(v___x_900_);
if (v_isSharedCheck_947_ == 0)
{
v___x_903_ = v___x_900_;
v_isShared_904_ = v_isSharedCheck_947_;
goto v_resetjp_902_;
}
else
{
lean_inc(v_a_901_);
lean_dec(v___x_900_);
v___x_903_ = lean_box(0);
v_isShared_904_ = v_isSharedCheck_947_;
goto v_resetjp_902_;
}
v_resetjp_902_:
{
lean_object* v___x_905_; lean_object* v___x_906_; uint8_t v___x_907_; 
v___x_905_ = lean_string_utf8_byte_size(v_a_901_);
v___x_906_ = lean_unsigned_to_nat(0u);
v___x_907_ = lean_nat_dec_eq(v___x_905_, v___x_906_);
if (v___x_907_ == 0)
{
lean_object* v___x_908_; lean_object* v___x_909_; lean_object* v___x_910_; lean_object* v___x_911_; uint8_t v___x_912_; 
v___x_908_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_908_, 0, v_a_901_);
lean_ctor_set(v___x_908_, 1, v___x_906_);
lean_ctor_set(v___x_908_, 2, v___x_905_);
v___x_909_ = l_String_Slice_trimAscii(v___x_908_);
v___x_910_ = l_String_Slice_toString(v___x_909_);
lean_dec_ref(v___x_909_);
v___x_911_ = ((lean_object*)(lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__0));
v___x_912_ = lean_string_dec_eq(v___x_910_, v___x_911_);
if (v___x_912_ == 0)
{
lean_object* v___x_913_; uint8_t v___x_914_; 
v___x_913_ = ((lean_object*)(lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__1));
v___x_914_ = lean_string_dec_eq(v___x_910_, v___x_913_);
lean_dec_ref(v___x_910_);
if (v___x_914_ == 0)
{
lean_object* v___x_915_; lean_object* v___x_917_; 
lean_dec_ref(v_geo_895_);
lean_dec_ref(v_val_893_);
v___x_915_ = ((lean_object*)(lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__3));
if (v_isShared_904_ == 0)
{
lean_ctor_set_tag(v___x_903_, 1);
lean_ctor_set(v___x_903_, 0, v___x_915_);
v___x_917_ = v___x_903_;
goto v_reusejp_916_;
}
else
{
lean_object* v_reuseFailAlloc_918_; 
v_reuseFailAlloc_918_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_918_, 0, v___x_915_);
v___x_917_ = v_reuseFailAlloc_918_;
goto v_reusejp_916_;
}
v_reusejp_916_:
{
return v___x_917_;
}
}
else
{
lean_object* v___x_919_; 
lean_del_object(v___x_903_);
lean_inc_ref(v_geo_895_);
v___x_919_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce(v_inputs_894_, v_geo_895_, v_cpr_896_);
if (lean_obj_tag(v___x_919_) == 0)
{
lean_object* v_a_920_; lean_object* v_fst_921_; lean_object* v_snd_922_; lean_object* v___x_923_; lean_object* v___x_924_; lean_object* v___x_925_; lean_object* v___x_926_; lean_object* v___x_927_; lean_object* v___x_928_; 
v_a_920_ = lean_ctor_get(v___x_919_, 0);
lean_inc(v_a_920_);
lean_dec_ref_known(v___x_919_, 1);
v_fst_921_ = lean_ctor_get(v_a_920_, 0);
lean_inc(v_fst_921_);
v_snd_922_ = lean_ctor_get(v_a_920_, 1);
lean_inc(v_snd_922_);
lean_dec(v_a_920_);
v___x_923_ = l_Nat_reprFast(v_fst_921_);
v___x_924_ = ((lean_object*)(lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__4));
v___x_925_ = lean_string_append(v___x_923_, v___x_924_);
v___x_926_ = l_Nat_reprFast(v_snd_922_);
v___x_927_ = lean_string_append(v___x_925_, v___x_926_);
lean_dec_ref(v___x_926_);
v___x_928_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_927_);
if (lean_obj_tag(v___x_928_) == 0)
{
lean_object* v___x_929_; lean_object* v_flush_930_; lean_object* v___x_931_; 
lean_dec_ref_known(v___x_928_, 1);
v___x_929_ = lean_get_stdout();
v_flush_930_ = lean_ctor_get(v___x_929_, 0);
lean_inc_ref(v_flush_930_);
lean_dec_ref(v___x_929_);
v___x_931_ = lean_apply_1(v_flush_930_, lean_box(0));
if (lean_obj_tag(v___x_931_) == 0)
{
lean_dec_ref_known(v___x_931_, 1);
goto _start;
}
else
{
lean_dec_ref(v_geo_895_);
lean_dec_ref(v_val_893_);
return v___x_931_;
}
}
else
{
lean_dec_ref(v_geo_895_);
lean_dec_ref(v_val_893_);
return v___x_928_;
}
}
else
{
lean_object* v_a_933_; lean_object* v___x_935_; uint8_t v_isShared_936_; uint8_t v_isSharedCheck_940_; 
lean_dec_ref(v_geo_895_);
lean_dec_ref(v_val_893_);
v_a_933_ = lean_ctor_get(v___x_919_, 0);
v_isSharedCheck_940_ = !lean_is_exclusive(v___x_919_);
if (v_isSharedCheck_940_ == 0)
{
v___x_935_ = v___x_919_;
v_isShared_936_ = v_isSharedCheck_940_;
goto v_resetjp_934_;
}
else
{
lean_inc(v_a_933_);
lean_dec(v___x_919_);
v___x_935_ = lean_box(0);
v_isShared_936_ = v_isSharedCheck_940_;
goto v_resetjp_934_;
}
v_resetjp_934_:
{
lean_object* v___x_938_; 
if (v_isShared_936_ == 0)
{
v___x_938_ = v___x_935_;
goto v_reusejp_937_;
}
else
{
lean_object* v_reuseFailAlloc_939_; 
v_reuseFailAlloc_939_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_939_, 0, v_a_933_);
v___x_938_ = v_reuseFailAlloc_939_;
goto v_reusejp_937_;
}
v_reusejp_937_:
{
return v___x_938_;
}
}
}
}
}
else
{
lean_object* v___x_942_; 
lean_dec_ref(v___x_910_);
lean_dec_ref(v_geo_895_);
lean_dec_ref(v_val_893_);
if (v_isShared_904_ == 0)
{
lean_ctor_set(v___x_903_, 0, v___x_899_);
v___x_942_ = v___x_903_;
goto v_reusejp_941_;
}
else
{
lean_object* v_reuseFailAlloc_943_; 
v_reuseFailAlloc_943_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_943_, 0, v___x_899_);
v___x_942_ = v_reuseFailAlloc_943_;
goto v_reusejp_941_;
}
v_reusejp_941_:
{
return v___x_942_;
}
}
}
else
{
lean_object* v___x_945_; 
lean_dec(v_a_901_);
lean_dec_ref(v_geo_895_);
lean_dec_ref(v_val_893_);
if (v_isShared_904_ == 0)
{
lean_ctor_set(v___x_903_, 0, v___x_899_);
v___x_945_ = v___x_903_;
goto v_reusejp_944_;
}
else
{
lean_object* v_reuseFailAlloc_946_; 
v_reuseFailAlloc_946_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_946_, 0, v___x_899_);
v___x_945_ = v_reuseFailAlloc_946_;
goto v_reusejp_944_;
}
v_reusejp_944_:
{
return v___x_945_;
}
}
}
}
else
{
lean_object* v_a_948_; lean_object* v___x_950_; uint8_t v_isShared_951_; uint8_t v_isSharedCheck_955_; 
lean_dec_ref(v_geo_895_);
lean_dec_ref(v_val_893_);
v_a_948_ = lean_ctor_get(v___x_900_, 0);
v_isSharedCheck_955_ = !lean_is_exclusive(v___x_900_);
if (v_isSharedCheck_955_ == 0)
{
v___x_950_ = v___x_900_;
v_isShared_951_ = v_isSharedCheck_955_;
goto v_resetjp_949_;
}
else
{
lean_inc(v_a_948_);
lean_dec(v___x_900_);
v___x_950_ = lean_box(0);
v_isShared_951_ = v_isSharedCheck_955_;
goto v_resetjp_949_;
}
v_resetjp_949_:
{
lean_object* v___x_953_; 
if (v_isShared_951_ == 0)
{
v___x_953_ = v___x_950_;
goto v_reusejp_952_;
}
else
{
lean_object* v_reuseFailAlloc_954_; 
v_reuseFailAlloc_954_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_954_, 0, v_a_948_);
v___x_953_ = v_reuseFailAlloc_954_;
goto v_reusejp_952_;
}
v_reusejp_952_:
{
return v___x_953_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___boxed(lean_object* v_val_956_, lean_object* v_inputs_957_, lean_object* v_geo_958_, lean_object* v_cpr_959_, lean_object* v___y_960_){
_start:
{
uint8_t v_cpr_boxed_961_; lean_object* v_res_962_; 
v_cpr_boxed_961_ = lean_unbox(v_cpr_959_);
v_res_962_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg(v_val_956_, v_inputs_957_, v_geo_958_, v_cpr_boxed_961_);
lean_dec_ref(v_inputs_957_);
return v_res_962_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker(lean_object* v_inputs_964_, lean_object* v_geo_965_, uint8_t v_cpr_966_){
_start:
{
lean_object* v___x_968_; lean_object* v___x_969_; lean_object* v___x_970_; lean_object* v___x_971_; lean_object* v___x_972_; 
v___x_968_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker___closed__0));
v___x_969_ = lean_array_get_size(v_inputs_964_);
v___x_970_ = l_Nat_reprFast(v___x_969_);
v___x_971_ = lean_string_append(v___x_968_, v___x_970_);
lean_dec_ref(v___x_970_);
v___x_972_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_971_);
if (lean_obj_tag(v___x_972_) == 0)
{
lean_object* v___x_973_; lean_object* v_flush_974_; lean_object* v___x_975_; 
lean_dec_ref_known(v___x_972_, 1);
v___x_973_ = lean_get_stdout();
v_flush_974_ = lean_ctor_get(v___x_973_, 0);
lean_inc_ref(v_flush_974_);
lean_dec_ref(v___x_973_);
v___x_975_ = lean_apply_1(v_flush_974_, lean_box(0));
if (lean_obj_tag(v___x_975_) == 0)
{
lean_object* v___x_976_; lean_object* v___x_977_; lean_object* v___x_978_; 
lean_dec_ref_known(v___x_975_, 1);
v___x_976_ = lean_get_stdin();
v___x_977_ = lean_box(0);
v___x_978_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg(v___x_976_, v_inputs_964_, v_geo_965_, v_cpr_966_);
if (lean_obj_tag(v___x_978_) == 0)
{
lean_object* v___x_980_; uint8_t v_isShared_981_; uint8_t v_isSharedCheck_985_; 
v_isSharedCheck_985_ = !lean_is_exclusive(v___x_978_);
if (v_isSharedCheck_985_ == 0)
{
lean_object* v_unused_986_; 
v_unused_986_ = lean_ctor_get(v___x_978_, 0);
lean_dec(v_unused_986_);
v___x_980_ = v___x_978_;
v_isShared_981_ = v_isSharedCheck_985_;
goto v_resetjp_979_;
}
else
{
lean_dec(v___x_978_);
v___x_980_ = lean_box(0);
v_isShared_981_ = v_isSharedCheck_985_;
goto v_resetjp_979_;
}
v_resetjp_979_:
{
lean_object* v___x_983_; 
if (v_isShared_981_ == 0)
{
lean_ctor_set(v___x_980_, 0, v___x_977_);
v___x_983_ = v___x_980_;
goto v_reusejp_982_;
}
else
{
lean_object* v_reuseFailAlloc_984_; 
v_reuseFailAlloc_984_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_984_, 0, v___x_977_);
v___x_983_ = v_reuseFailAlloc_984_;
goto v_reusejp_982_;
}
v_reusejp_982_:
{
return v___x_983_;
}
}
}
else
{
return v___x_978_;
}
}
else
{
lean_dec_ref(v_geo_965_);
return v___x_975_;
}
}
else
{
lean_dec_ref(v_geo_965_);
return v___x_972_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker___boxed(lean_object* v_inputs_987_, lean_object* v_geo_988_, lean_object* v_cpr_989_, lean_object* v_a_990_){
_start:
{
uint8_t v_cpr_boxed_991_; lean_object* v_res_992_; 
v_cpr_boxed_991_ = lean_unbox(v_cpr_989_);
v_res_992_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker(v_inputs_987_, v_geo_988_, v_cpr_boxed_991_);
lean_dec_ref(v_inputs_987_);
return v_res_992_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1(lean_object* v_val_993_, lean_object* v_inputs_994_, lean_object* v_geo_995_, uint8_t v_cpr_996_, lean_object* v_inst_997_, lean_object* v_a_998_){
_start:
{
lean_object* v___x_1000_; 
v___x_1000_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg(v_val_993_, v_inputs_994_, v_geo_995_, v_cpr_996_);
return v___x_1000_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___boxed(lean_object* v_val_1001_, lean_object* v_inputs_1002_, lean_object* v_geo_1003_, lean_object* v_cpr_1004_, lean_object* v_inst_1005_, lean_object* v_a_1006_, lean_object* v___y_1007_){
_start:
{
uint8_t v_cpr_boxed_1008_; lean_object* v_res_1009_; 
v_cpr_boxed_1008_ = lean_unbox(v_cpr_1004_);
v_res_1009_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1(v_val_1001_, v_inputs_1002_, v_geo_1003_, v_cpr_boxed_1008_, v_inst_1005_, v_a_1006_);
lean_dec_ref(v_inputs_1002_);
return v_res_1009_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(lean_object* v_value_1010_){
_start:
{
double v___x_1011_; uint64_t v___x_1012_; lean_object* v___x_1013_; 
v___x_1011_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_value_1010_);
v___x_1012_ = lean_float_to_bits(v___x_1011_);
v___x_1013_ = lean_uint64_to_nat(v___x_1012_);
return v___x_1013_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0_spec__1(size_t v_sz_1014_, size_t v_i_1015_, lean_object* v_bs_1016_){
_start:
{
uint8_t v___x_1017_; 
v___x_1017_ = lean_usize_dec_lt(v_i_1015_, v_sz_1014_);
if (v___x_1017_ == 0)
{
return v_bs_1016_;
}
else
{
lean_object* v_v_1018_; lean_object* v___x_1019_; lean_object* v_bs_x27_1020_; lean_object* v___x_1021_; lean_object* v___x_1022_; size_t v___x_1023_; size_t v___x_1024_; lean_object* v___x_1025_; 
v_v_1018_ = lean_array_uget(v_bs_1016_, v_i_1015_);
v___x_1019_ = lean_unsigned_to_nat(0u);
v_bs_x27_1020_ = lean_array_uset(v_bs_1016_, v_i_1015_, v___x_1019_);
v___x_1021_ = l_Lean_JsonNumber_fromNat(v_v_1018_);
v___x_1022_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1022_, 0, v___x_1021_);
v___x_1023_ = ((size_t)1ULL);
v___x_1024_ = lean_usize_add(v_i_1015_, v___x_1023_);
v___x_1025_ = lean_array_uset(v_bs_x27_1020_, v_i_1015_, v___x_1022_);
v_i_1015_ = v___x_1024_;
v_bs_1016_ = v___x_1025_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0_spec__1___boxed(lean_object* v_sz_1027_, lean_object* v_i_1028_, lean_object* v_bs_1029_){
_start:
{
size_t v_sz_boxed_1030_; size_t v_i_boxed_1031_; lean_object* v_res_1032_; 
v_sz_boxed_1030_ = lean_unbox_usize(v_sz_1027_);
lean_dec(v_sz_1027_);
v_i_boxed_1031_ = lean_unbox_usize(v_i_1028_);
lean_dec(v_i_1028_);
v_res_1032_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0_spec__1(v_sz_boxed_1030_, v_i_boxed_1031_, v_bs_1029_);
return v_res_1032_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0(lean_object* v_a_1033_){
_start:
{
size_t v_sz_1034_; size_t v___x_1035_; lean_object* v___x_1036_; lean_object* v___x_1037_; 
v_sz_1034_ = lean_array_size(v_a_1033_);
v___x_1035_ = ((size_t)0ULL);
v___x_1036_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0_spec__1(v_sz_1034_, v___x_1035_, v_a_1033_);
v___x_1037_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_1037_, 0, v___x_1036_);
return v___x_1037_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0(lean_object* v_a_1038_){
_start:
{
lean_object* v___x_1039_; lean_object* v___x_1040_; 
v___x_1039_ = lean_array_mk(v_a_1038_);
v___x_1040_ = lp_lean1090_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0(v___x_1039_);
return v___x_1040_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson(lean_object* v_p_1041_){
_start:
{
if (lean_obj_tag(v_p_1041_) == 0)
{
lean_object* v___x_1042_; 
v___x_1042_ = lean_box(0);
return v___x_1042_;
}
else
{
lean_object* v_val_1043_; lean_object* v_lat_1044_; lean_object* v_lon_1045_; lean_object* v___x_1047_; uint8_t v_isShared_1048_; uint8_t v_isSharedCheck_1057_; 
v_val_1043_ = lean_ctor_get(v_p_1041_, 0);
lean_inc(v_val_1043_);
lean_dec_ref_known(v_p_1041_, 1);
v_lat_1044_ = lean_ctor_get(v_val_1043_, 0);
v_lon_1045_ = lean_ctor_get(v_val_1043_, 1);
v_isSharedCheck_1057_ = !lean_is_exclusive(v_val_1043_);
if (v_isSharedCheck_1057_ == 0)
{
v___x_1047_ = v_val_1043_;
v_isShared_1048_ = v_isSharedCheck_1057_;
goto v_resetjp_1046_;
}
else
{
lean_inc(v_lon_1045_);
lean_inc(v_lat_1044_);
lean_dec(v_val_1043_);
v___x_1047_ = lean_box(0);
v_isShared_1048_ = v_isSharedCheck_1057_;
goto v_resetjp_1046_;
}
v_resetjp_1046_:
{
lean_object* v___x_1049_; lean_object* v___x_1050_; lean_object* v___x_1051_; lean_object* v___x_1053_; 
v___x_1049_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(v_lat_1044_);
v___x_1050_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(v_lon_1045_);
v___x_1051_ = lean_box(0);
if (v_isShared_1048_ == 0)
{
lean_ctor_set_tag(v___x_1047_, 1);
lean_ctor_set(v___x_1047_, 1, v___x_1051_);
lean_ctor_set(v___x_1047_, 0, v___x_1050_);
v___x_1053_ = v___x_1047_;
goto v_reusejp_1052_;
}
else
{
lean_object* v_reuseFailAlloc_1056_; 
v_reuseFailAlloc_1056_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1056_, 0, v___x_1050_);
lean_ctor_set(v_reuseFailAlloc_1056_, 1, v___x_1051_);
v___x_1053_ = v_reuseFailAlloc_1056_;
goto v_reusejp_1052_;
}
v_reusejp_1052_:
{
lean_object* v___x_1054_; lean_object* v___x_1055_; 
v___x_1054_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1054_, 0, v___x_1049_);
lean_ctor_set(v___x_1054_, 1, v___x_1053_);
v___x_1055_ = lp_lean1090_Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0(v___x_1054_);
return v___x_1055_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean_Option_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__0(lean_object* v_x_1058_){
_start:
{
if (lean_obj_tag(v_x_1058_) == 0)
{
lean_object* v___x_1059_; 
v___x_1059_ = lean_box(0);
return v___x_1059_;
}
else
{
lean_object* v_val_1060_; lean_object* v___x_1062_; uint8_t v_isShared_1063_; uint8_t v_isSharedCheck_1068_; 
v_val_1060_ = lean_ctor_get(v_x_1058_, 0);
v_isSharedCheck_1068_ = !lean_is_exclusive(v_x_1058_);
if (v_isSharedCheck_1068_ == 0)
{
v___x_1062_ = v_x_1058_;
v_isShared_1063_ = v_isSharedCheck_1068_;
goto v_resetjp_1061_;
}
else
{
lean_inc(v_val_1060_);
lean_dec(v_x_1058_);
v___x_1062_ = lean_box(0);
v_isShared_1063_ = v_isSharedCheck_1068_;
goto v_resetjp_1061_;
}
v_resetjp_1061_:
{
lean_object* v___x_1064_; lean_object* v___x_1066_; 
v___x_1064_ = l_Lean_JsonNumber_fromInt(v_val_1060_);
if (v_isShared_1063_ == 0)
{
lean_ctor_set_tag(v___x_1062_, 2);
lean_ctor_set(v___x_1062_, 0, v___x_1064_);
v___x_1066_ = v___x_1062_;
goto v_reusejp_1065_;
}
else
{
lean_object* v_reuseFailAlloc_1067_; 
v_reuseFailAlloc_1067_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1067_, 0, v___x_1064_);
v___x_1066_ = v_reuseFailAlloc_1067_;
goto v_reusejp_1065_;
}
v_reusejp_1065_:
{
return v___x_1066_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean_Option_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__1(lean_object* v_x_1069_){
_start:
{
if (lean_obj_tag(v_x_1069_) == 0)
{
lean_object* v___x_1070_; 
v___x_1070_ = lean_box(0);
return v___x_1070_;
}
else
{
lean_object* v_val_1071_; lean_object* v___x_1073_; uint8_t v_isShared_1074_; uint8_t v_isSharedCheck_1078_; 
v_val_1071_ = lean_ctor_get(v_x_1069_, 0);
v_isSharedCheck_1078_ = !lean_is_exclusive(v_x_1069_);
if (v_isSharedCheck_1078_ == 0)
{
v___x_1073_ = v_x_1069_;
v_isShared_1074_ = v_isSharedCheck_1078_;
goto v_resetjp_1072_;
}
else
{
lean_inc(v_val_1071_);
lean_dec(v_x_1069_);
v___x_1073_ = lean_box(0);
v_isShared_1074_ = v_isSharedCheck_1078_;
goto v_resetjp_1072_;
}
v_resetjp_1072_:
{
lean_object* v___x_1076_; 
if (v_isShared_1074_ == 0)
{
lean_ctor_set_tag(v___x_1073_, 3);
v___x_1076_ = v___x_1073_;
goto v_reusejp_1075_;
}
else
{
lean_object* v_reuseFailAlloc_1077_; 
v_reuseFailAlloc_1077_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1077_, 0, v_val_1071_);
v___x_1076_ = v_reuseFailAlloc_1077_;
goto v_reusejp_1075_;
}
v_reusejp_1075_:
{
return v___x_1076_;
}
}
}
}
}
LEAN_EXPORT uint8_t lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___lam__0(lean_object* v_a_1079_, lean_object* v_b_1080_){
_start:
{
lean_object* v_fst_1081_; lean_object* v_fst_1082_; uint8_t v___x_1083_; 
v_fst_1081_ = lean_ctor_get(v_a_1079_, 0);
v_fst_1082_ = lean_ctor_get(v_b_1080_, 0);
v___x_1083_ = lean_nat_dec_le(v_fst_1081_, v_fst_1082_);
return v___x_1083_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___lam__0___boxed(lean_object* v_a_1084_, lean_object* v_b_1085_){
_start:
{
uint8_t v_res_1086_; lean_object* v_r_1087_; 
v_res_1086_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___lam__0(v_a_1084_, v_b_1085_);
lean_dec_ref(v_b_1085_);
lean_dec_ref(v_a_1084_);
v_r_1087_ = lean_box(v_res_1086_);
return v_r_1087_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3(lean_object* v_a_1093_, lean_object* v_a_1094_){
_start:
{
if (lean_obj_tag(v_a_1093_) == 0)
{
lean_object* v___x_1095_; 
v___x_1095_ = l_List_reverse___redArg(v_a_1094_);
return v___x_1095_;
}
else
{
lean_object* v_head_1096_; lean_object* v_snd_1097_; lean_object* v_tail_1098_; lean_object* v___x_1100_; uint8_t v_isShared_1101_; uint8_t v_isSharedCheck_1141_; 
v_head_1096_ = lean_ctor_get(v_a_1093_, 0);
lean_inc(v_head_1096_);
v_snd_1097_ = lean_ctor_get(v_head_1096_, 1);
lean_inc(v_snd_1097_);
v_tail_1098_ = lean_ctor_get(v_a_1093_, 1);
v_isSharedCheck_1141_ = !lean_is_exclusive(v_a_1093_);
if (v_isSharedCheck_1141_ == 0)
{
lean_object* v_unused_1142_; 
v_unused_1142_ = lean_ctor_get(v_a_1093_, 0);
lean_dec(v_unused_1142_);
v___x_1100_ = v_a_1093_;
v_isShared_1101_ = v_isSharedCheck_1141_;
goto v_resetjp_1099_;
}
else
{
lean_inc(v_tail_1098_);
lean_dec(v_a_1093_);
v___x_1100_ = lean_box(0);
v_isShared_1101_ = v_isSharedCheck_1141_;
goto v_resetjp_1099_;
}
v_resetjp_1099_:
{
lean_object* v_fst_1102_; lean_object* v___x_1104_; uint8_t v_isShared_1105_; uint8_t v_isSharedCheck_1139_; 
v_fst_1102_ = lean_ctor_get(v_head_1096_, 0);
v_isSharedCheck_1139_ = !lean_is_exclusive(v_head_1096_);
if (v_isSharedCheck_1139_ == 0)
{
lean_object* v_unused_1140_; 
v_unused_1140_ = lean_ctor_get(v_head_1096_, 1);
lean_dec(v_unused_1140_);
v___x_1104_ = v_head_1096_;
v_isShared_1105_ = v_isSharedCheck_1139_;
goto v_resetjp_1103_;
}
else
{
lean_inc(v_fst_1102_);
lean_dec(v_head_1096_);
v___x_1104_ = lean_box(0);
v_isShared_1105_ = v_isSharedCheck_1139_;
goto v_resetjp_1103_;
}
v_resetjp_1103_:
{
lean_object* v_position_1106_; lean_object* v_lastAltitude_1107_; lean_object* v_airport_1108_; lean_object* v_seenBDS_1109_; lean_object* v___x_1110_; lean_object* v___x_1111_; lean_object* v___x_1112_; lean_object* v___x_1114_; 
v_position_1106_ = lean_ctor_get(v_snd_1097_, 1);
lean_inc(v_position_1106_);
v_lastAltitude_1107_ = lean_ctor_get(v_snd_1097_, 2);
lean_inc(v_lastAltitude_1107_);
v_airport_1108_ = lean_ctor_get(v_snd_1097_, 3);
lean_inc(v_airport_1108_);
v_seenBDS_1109_ = lean_ctor_get(v_snd_1097_, 4);
lean_inc(v_seenBDS_1109_);
lean_dec(v_snd_1097_);
v___x_1110_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__0));
v___x_1111_ = l_Lean_JsonNumber_fromNat(v_fst_1102_);
v___x_1112_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1112_, 0, v___x_1111_);
if (v_isShared_1105_ == 0)
{
lean_ctor_set(v___x_1104_, 1, v___x_1112_);
lean_ctor_set(v___x_1104_, 0, v___x_1110_);
v___x_1114_ = v___x_1104_;
goto v_reusejp_1113_;
}
else
{
lean_object* v_reuseFailAlloc_1138_; 
v_reuseFailAlloc_1138_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1138_, 0, v___x_1110_);
lean_ctor_set(v_reuseFailAlloc_1138_, 1, v___x_1112_);
v___x_1114_ = v_reuseFailAlloc_1138_;
goto v_reusejp_1113_;
}
v_reusejp_1113_:
{
lean_object* v___x_1115_; lean_object* v___x_1116_; lean_object* v___x_1117_; lean_object* v___x_1118_; lean_object* v___x_1119_; lean_object* v___x_1120_; lean_object* v___x_1121_; lean_object* v___x_1122_; lean_object* v___x_1123_; lean_object* v___x_1124_; lean_object* v___x_1125_; lean_object* v___x_1126_; lean_object* v___x_1127_; lean_object* v___x_1129_; 
v___x_1115_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__1));
v___x_1116_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson(v_position_1106_);
v___x_1117_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1117_, 0, v___x_1115_);
lean_ctor_set(v___x_1117_, 1, v___x_1116_);
v___x_1118_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__2));
v___x_1119_ = lp_lean1090_Lean_Option_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__0(v_lastAltitude_1107_);
v___x_1120_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1120_, 0, v___x_1118_);
lean_ctor_set(v___x_1120_, 1, v___x_1119_);
v___x_1121_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__3));
v___x_1122_ = lp_lean1090_Lean_Option_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__1(v_airport_1108_);
v___x_1123_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1123_, 0, v___x_1121_);
lean_ctor_set(v___x_1123_, 1, v___x_1122_);
v___x_1124_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__4));
v___x_1125_ = lp_lean1090_Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0(v_seenBDS_1109_);
v___x_1126_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1126_, 0, v___x_1124_);
lean_ctor_set(v___x_1126_, 1, v___x_1125_);
v___x_1127_ = lean_box(0);
if (v_isShared_1101_ == 0)
{
lean_ctor_set(v___x_1100_, 1, v___x_1127_);
lean_ctor_set(v___x_1100_, 0, v___x_1126_);
v___x_1129_ = v___x_1100_;
goto v_reusejp_1128_;
}
else
{
lean_object* v_reuseFailAlloc_1137_; 
v_reuseFailAlloc_1137_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1137_, 0, v___x_1126_);
lean_ctor_set(v_reuseFailAlloc_1137_, 1, v___x_1127_);
v___x_1129_ = v_reuseFailAlloc_1137_;
goto v_reusejp_1128_;
}
v_reusejp_1128_:
{
lean_object* v___x_1130_; lean_object* v___x_1131_; lean_object* v___x_1132_; lean_object* v___x_1133_; lean_object* v___x_1134_; lean_object* v___x_1135_; 
v___x_1130_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1130_, 0, v___x_1123_);
lean_ctor_set(v___x_1130_, 1, v___x_1129_);
v___x_1131_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1131_, 0, v___x_1120_);
lean_ctor_set(v___x_1131_, 1, v___x_1130_);
v___x_1132_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1132_, 0, v___x_1117_);
lean_ctor_set(v___x_1132_, 1, v___x_1131_);
v___x_1133_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1133_, 0, v___x_1114_);
lean_ctor_set(v___x_1133_, 1, v___x_1132_);
v___x_1134_ = l_Lean_Json_mkObj(v___x_1133_);
lean_dec_ref_known(v___x_1133_, 2);
v___x_1135_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1135_, 0, v___x_1134_);
lean_ctor_set(v___x_1135_, 1, v_a_1094_);
v_a_1093_ = v_tail_1098_;
v_a_1094_ = v___x_1135_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg(lean_object* v_inputs_1145_, lean_object* v_geo_1146_, lean_object* v_range_1147_, lean_object* v_b_1148_, lean_object* v_i_1149_){
_start:
{
lean_object* v_stop_1151_; lean_object* v_step_1152_; uint8_t v___x_1153_; 
v_stop_1151_ = lean_ctor_get(v_range_1147_, 1);
v_step_1152_ = lean_ctor_get(v_range_1147_, 2);
v___x_1153_ = lean_nat_dec_lt(v_i_1149_, v_stop_1151_);
if (v___x_1153_ == 0)
{
lean_object* v___x_1154_; 
lean_dec(v_i_1149_);
lean_dec_ref(v_geo_1146_);
v___x_1154_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1154_, 0, v_b_1148_);
return v___x_1154_;
}
else
{
lean_object* v_input_1155_; lean_object* v_timestamp_1156_; lean_object* v_bytes_1157_; lean_object* v___x_1159_; uint8_t v_isShared_1160_; uint8_t v_isSharedCheck_1214_; 
v_input_1155_ = lean_array_fget(v_inputs_1145_, v_i_1149_);
v_timestamp_1156_ = lean_ctor_get(v_input_1155_, 0);
v_bytes_1157_ = lean_ctor_get(v_input_1155_, 1);
v_isSharedCheck_1214_ = !lean_is_exclusive(v_input_1155_);
if (v_isSharedCheck_1214_ == 0)
{
v___x_1159_ = v_input_1155_;
v_isShared_1160_ = v_isSharedCheck_1214_;
goto v_resetjp_1158_;
}
else
{
lean_inc(v_bytes_1157_);
lean_inc(v_timestamp_1156_);
lean_dec(v_input_1155_);
v___x_1159_ = lean_box(0);
v_isShared_1160_ = v_isSharedCheck_1214_;
goto v_resetjp_1158_;
}
v_resetjp_1158_:
{
lean_object* v___x_1161_; 
v___x_1161_ = lp_lean1090_Lean1090_Impl_decode(v_bytes_1157_);
lean_dec(v_bytes_1157_);
if (lean_obj_tag(v___x_1161_) == 1)
{
lean_object* v_val_1162_; lean_object* v___x_1164_; uint8_t v_isShared_1165_; uint8_t v_isSharedCheck_1211_; 
v_val_1162_ = lean_ctor_get(v___x_1161_, 0);
v_isSharedCheck_1211_ = !lean_is_exclusive(v___x_1161_);
if (v_isSharedCheck_1211_ == 0)
{
v___x_1164_ = v___x_1161_;
v_isShared_1165_ = v_isSharedCheck_1211_;
goto v_resetjp_1163_;
}
else
{
lean_inc(v_val_1162_);
lean_dec(v___x_1161_);
v___x_1164_ = lean_box(0);
v_isShared_1165_ = v_isSharedCheck_1211_;
goto v_resetjp_1163_;
}
v_resetjp_1163_:
{
lean_object* v_next_1166_; lean_object* v_fst_1167_; lean_object* v_snd_1168_; lean_object* v___x_1170_; uint8_t v_isShared_1171_; uint8_t v_isSharedCheck_1210_; 
lean_inc(v_val_1162_);
lean_inc_ref(v_geo_1146_);
v_next_1166_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance(v_geo_1146_, v_b_1148_, v_timestamp_1156_, v_val_1162_);
v_fst_1167_ = lean_ctor_get(v_next_1166_, 0);
v_snd_1168_ = lean_ctor_get(v_next_1166_, 1);
v_isSharedCheck_1210_ = !lean_is_exclusive(v_next_1166_);
if (v_isSharedCheck_1210_ == 0)
{
v___x_1170_ = v_next_1166_;
v_isShared_1171_ = v_isSharedCheck_1210_;
goto v_resetjp_1169_;
}
else
{
lean_inc(v_snd_1168_);
lean_inc(v_fst_1167_);
lean_dec(v_next_1166_);
v___x_1170_ = lean_box(0);
v_isShared_1171_ = v_isSharedCheck_1210_;
goto v_resetjp_1169_;
}
v_resetjp_1169_:
{
uint8_t v___y_1173_; lean_object* v_fields_1207_; lean_object* v_body_1208_; 
v_fields_1207_ = lean_ctor_get(v_val_1162_, 0);
lean_inc_ref(v_fields_1207_);
lean_dec(v_val_1162_);
v_body_1208_ = lean_ctor_get(v_fields_1207_, 0);
lean_inc_ref(v_body_1208_);
lean_dec_ref(v_fields_1207_);
if (lean_obj_tag(v_body_1208_) == 4)
{
lean_dec_ref_known(v_body_1208_, 3);
v___y_1173_ = v___x_1153_;
goto v___jp_1172_;
}
else
{
uint8_t v___x_1209_; 
lean_dec_ref(v_body_1208_);
v___x_1209_ = 0;
v___y_1173_ = v___x_1209_;
goto v___jp_1172_;
}
v___jp_1172_:
{
lean_object* v___x_1174_; lean_object* v___x_1175_; lean_object* v___x_1177_; 
v___x_1174_ = ((lean_object*)(lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___closed__0));
lean_inc(v_i_1149_);
v___x_1175_ = l_Lean_JsonNumber_fromNat(v_i_1149_);
if (v_isShared_1165_ == 0)
{
lean_ctor_set_tag(v___x_1164_, 2);
lean_ctor_set(v___x_1164_, 0, v___x_1175_);
v___x_1177_ = v___x_1164_;
goto v_reusejp_1176_;
}
else
{
lean_object* v_reuseFailAlloc_1206_; 
v_reuseFailAlloc_1206_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1206_, 0, v___x_1175_);
v___x_1177_ = v_reuseFailAlloc_1206_;
goto v_reusejp_1176_;
}
v_reusejp_1176_:
{
lean_object* v___x_1179_; 
if (v_isShared_1171_ == 0)
{
lean_ctor_set(v___x_1170_, 1, v___x_1177_);
lean_ctor_set(v___x_1170_, 0, v___x_1174_);
v___x_1179_ = v___x_1170_;
goto v_reusejp_1178_;
}
else
{
lean_object* v_reuseFailAlloc_1205_; 
v_reuseFailAlloc_1205_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1205_, 0, v___x_1174_);
lean_ctor_set(v_reuseFailAlloc_1205_, 1, v___x_1177_);
v___x_1179_ = v_reuseFailAlloc_1205_;
goto v_reusejp_1178_;
}
v_reusejp_1178_:
{
lean_object* v___x_1180_; lean_object* v___x_1181_; lean_object* v___x_1183_; 
v___x_1180_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__1));
v___x_1181_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson(v_snd_1168_);
if (v_isShared_1160_ == 0)
{
lean_ctor_set(v___x_1159_, 1, v___x_1181_);
lean_ctor_set(v___x_1159_, 0, v___x_1180_);
v___x_1183_ = v___x_1159_;
goto v_reusejp_1182_;
}
else
{
lean_object* v_reuseFailAlloc_1204_; 
v_reuseFailAlloc_1204_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1204_, 0, v___x_1180_);
lean_ctor_set(v_reuseFailAlloc_1204_, 1, v___x_1181_);
v___x_1183_ = v_reuseFailAlloc_1204_;
goto v_reusejp_1182_;
}
v_reusejp_1182_:
{
lean_object* v___x_1184_; lean_object* v___x_1185_; lean_object* v___x_1186_; lean_object* v___x_1187_; lean_object* v___x_1188_; lean_object* v___x_1189_; lean_object* v___x_1190_; lean_object* v___x_1191_; lean_object* v___x_1192_; lean_object* v___x_1193_; 
v___x_1184_ = ((lean_object*)(lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___closed__1));
v___x_1185_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_1185_, 0, v___y_1173_);
v___x_1186_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1186_, 0, v___x_1184_);
lean_ctor_set(v___x_1186_, 1, v___x_1185_);
v___x_1187_ = lean_box(0);
v___x_1188_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1188_, 0, v___x_1186_);
lean_ctor_set(v___x_1188_, 1, v___x_1187_);
v___x_1189_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1189_, 0, v___x_1183_);
lean_ctor_set(v___x_1189_, 1, v___x_1188_);
v___x_1190_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1190_, 0, v___x_1179_);
lean_ctor_set(v___x_1190_, 1, v___x_1189_);
v___x_1191_ = l_Lean_Json_mkObj(v___x_1190_);
lean_dec_ref_known(v___x_1190_, 2);
v___x_1192_ = l_Lean_Json_compress(v___x_1191_);
v___x_1193_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_1192_);
if (lean_obj_tag(v___x_1193_) == 0)
{
lean_object* v___x_1194_; 
lean_dec_ref_known(v___x_1193_, 1);
v___x_1194_ = lean_nat_add(v_i_1149_, v_step_1152_);
lean_dec(v_i_1149_);
v_b_1148_ = v_fst_1167_;
v_i_1149_ = v___x_1194_;
goto _start;
}
else
{
lean_object* v_a_1196_; lean_object* v___x_1198_; uint8_t v_isShared_1199_; uint8_t v_isSharedCheck_1203_; 
lean_dec(v_fst_1167_);
lean_dec(v_i_1149_);
lean_dec_ref(v_geo_1146_);
v_a_1196_ = lean_ctor_get(v___x_1193_, 0);
v_isSharedCheck_1203_ = !lean_is_exclusive(v___x_1193_);
if (v_isSharedCheck_1203_ == 0)
{
v___x_1198_ = v___x_1193_;
v_isShared_1199_ = v_isSharedCheck_1203_;
goto v_resetjp_1197_;
}
else
{
lean_inc(v_a_1196_);
lean_dec(v___x_1193_);
v___x_1198_ = lean_box(0);
v_isShared_1199_ = v_isSharedCheck_1203_;
goto v_resetjp_1197_;
}
v_resetjp_1197_:
{
lean_object* v___x_1201_; 
if (v_isShared_1199_ == 0)
{
v___x_1201_ = v___x_1198_;
goto v_reusejp_1200_;
}
else
{
lean_object* v_reuseFailAlloc_1202_; 
v_reuseFailAlloc_1202_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1202_, 0, v_a_1196_);
v___x_1201_ = v_reuseFailAlloc_1202_;
goto v_reusejp_1200_;
}
v_reusejp_1200_:
{
return v___x_1201_;
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
else
{
lean_object* v___x_1212_; lean_object* v___x_1213_; 
lean_dec(v___x_1161_);
lean_del_object(v___x_1159_);
lean_dec_ref(v_timestamp_1156_);
lean_dec(v_i_1149_);
lean_dec_ref(v_b_1148_);
lean_dec_ref(v_geo_1146_);
v___x_1212_ = ((lean_object*)(lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce_spec__0___closed__1));
v___x_1213_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1213_, 0, v___x_1212_);
return v___x_1213_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___boxed(lean_object* v_inputs_1215_, lean_object* v_geo_1216_, lean_object* v_range_1217_, lean_object* v_b_1218_, lean_object* v_i_1219_, lean_object* v___y_1220_){
_start:
{
lean_object* v_res_1221_; 
v_res_1221_ = lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg(v_inputs_1215_, v_geo_1216_, v_range_1217_, v_b_1218_, v_i_1219_);
lean_dec_ref(v_range_1217_);
lean_dec_ref(v_inputs_1215_);
return v_res_1221_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4_spec__5(size_t v_sz_1222_, size_t v_i_1223_, lean_object* v_bs_1224_){
_start:
{
uint8_t v___x_1225_; 
v___x_1225_ = lean_usize_dec_lt(v_i_1223_, v_sz_1222_);
if (v___x_1225_ == 0)
{
return v_bs_1224_;
}
else
{
lean_object* v_v_1226_; lean_object* v___x_1227_; lean_object* v_bs_x27_1228_; size_t v___x_1229_; size_t v___x_1230_; lean_object* v___x_1231_; 
v_v_1226_ = lean_array_uget(v_bs_1224_, v_i_1223_);
v___x_1227_ = lean_unsigned_to_nat(0u);
v_bs_x27_1228_ = lean_array_uset(v_bs_1224_, v_i_1223_, v___x_1227_);
v___x_1229_ = ((size_t)1ULL);
v___x_1230_ = lean_usize_add(v_i_1223_, v___x_1229_);
v___x_1231_ = lean_array_uset(v_bs_x27_1228_, v_i_1223_, v_v_1226_);
v_i_1223_ = v___x_1230_;
v_bs_1224_ = v___x_1231_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4_spec__5___boxed(lean_object* v_sz_1233_, lean_object* v_i_1234_, lean_object* v_bs_1235_){
_start:
{
size_t v_sz_boxed_1236_; size_t v_i_boxed_1237_; lean_object* v_res_1238_; 
v_sz_boxed_1236_ = lean_unbox_usize(v_sz_1233_);
lean_dec(v_sz_1233_);
v_i_boxed_1237_ = lean_unbox_usize(v_i_1234_);
lean_dec(v_i_1234_);
v_res_1238_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4_spec__5(v_sz_boxed_1236_, v_i_boxed_1237_, v_bs_1235_);
return v_res_1238_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4(lean_object* v_a_1239_){
_start:
{
size_t v_sz_1240_; size_t v___x_1241_; lean_object* v___x_1242_; lean_object* v___x_1243_; 
v_sz_1240_ = lean_array_size(v_a_1239_);
v___x_1241_ = ((size_t)0ULL);
v___x_1242_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4_spec__5(v_sz_1240_, v___x_1241_, v_a_1239_);
v___x_1243_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_1243_, 0, v___x_1242_);
return v___x_1243_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4(lean_object* v_a_1244_){
_start:
{
lean_object* v___x_1245_; lean_object* v___x_1246_; 
v___x_1245_ = lean_array_mk(v_a_1244_);
v___x_1246_ = lp_lean1090_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4(v___x_1245_);
return v___x_1246_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking(lean_object* v_inputs_1256_, lean_object* v_geo_1257_){
_start:
{
lean_object* v___f_1259_; lean_object* v___x_1260_; lean_object* v_state_1261_; lean_object* v___x_1262_; lean_object* v___x_1263_; lean_object* v___x_1264_; lean_object* v___x_1265_; lean_object* v___x_1266_; 
v___f_1259_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__0));
v___x_1260_ = lean_box(0);
v_state_1261_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce___closed__0));
v___x_1262_ = lean_unsigned_to_nat(0u);
v___x_1263_ = lean_array_get_size(v_inputs_1256_);
v___x_1264_ = lean_unsigned_to_nat(1u);
v___x_1265_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1265_, 0, v___x_1262_);
lean_ctor_set(v___x_1265_, 1, v___x_1263_);
lean_ctor_set(v___x_1265_, 2, v___x_1264_);
v___x_1266_ = lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg(v_inputs_1256_, v_geo_1257_, v___x_1265_, v_state_1261_, v___x_1262_);
lean_dec_ref_known(v___x_1265_, 3);
if (lean_obj_tag(v___x_1266_) == 0)
{
lean_object* v_a_1267_; lean_object* v_aircraft_1268_; lean_object* v_reference_1269_; lean_object* v___x_1271_; uint8_t v_isShared_1272_; uint8_t v_isSharedCheck_1290_; 
v_a_1267_ = lean_ctor_get(v___x_1266_, 0);
lean_inc(v_a_1267_);
lean_dec_ref_known(v___x_1266_, 1);
v_aircraft_1268_ = lean_ctor_get(v_a_1267_, 0);
v_reference_1269_ = lean_ctor_get(v_a_1267_, 1);
v_isSharedCheck_1290_ = !lean_is_exclusive(v_a_1267_);
if (v_isSharedCheck_1290_ == 0)
{
v___x_1271_ = v_a_1267_;
v_isShared_1272_ = v_isSharedCheck_1290_;
goto v_resetjp_1270_;
}
else
{
lean_inc(v_reference_1269_);
lean_inc(v_aircraft_1268_);
lean_dec(v_a_1267_);
v___x_1271_ = lean_box(0);
v_isShared_1272_ = v_isSharedCheck_1290_;
goto v_resetjp_1270_;
}
v_resetjp_1270_:
{
lean_object* v___x_1273_; lean_object* v___x_1274_; lean_object* v___x_1275_; lean_object* v___x_1276_; lean_object* v___x_1278_; 
v___x_1273_ = l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(v_aircraft_1268_, v___f_1259_);
v___x_1274_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__3));
v___x_1275_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__4));
v___x_1276_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson(v_reference_1269_);
if (v_isShared_1272_ == 0)
{
lean_ctor_set(v___x_1271_, 1, v___x_1276_);
lean_ctor_set(v___x_1271_, 0, v___x_1275_);
v___x_1278_ = v___x_1271_;
goto v_reusejp_1277_;
}
else
{
lean_object* v_reuseFailAlloc_1289_; 
v_reuseFailAlloc_1289_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1289_, 0, v___x_1275_);
lean_ctor_set(v_reuseFailAlloc_1289_, 1, v___x_1276_);
v___x_1278_ = v_reuseFailAlloc_1289_;
goto v_reusejp_1277_;
}
v_reusejp_1277_:
{
lean_object* v___x_1279_; lean_object* v___x_1280_; lean_object* v___x_1281_; lean_object* v___x_1282_; lean_object* v___x_1283_; lean_object* v___x_1284_; lean_object* v___x_1285_; lean_object* v___x_1286_; lean_object* v___x_1287_; lean_object* v___x_1288_; 
v___x_1279_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__5));
v___x_1280_ = lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3(v___x_1273_, v___x_1260_);
v___x_1281_ = lp_lean1090_Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4(v___x_1280_);
v___x_1282_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1282_, 0, v___x_1279_);
lean_ctor_set(v___x_1282_, 1, v___x_1281_);
v___x_1283_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1283_, 0, v___x_1282_);
lean_ctor_set(v___x_1283_, 1, v___x_1260_);
v___x_1284_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1284_, 0, v___x_1278_);
lean_ctor_set(v___x_1284_, 1, v___x_1283_);
v___x_1285_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1285_, 0, v___x_1274_);
lean_ctor_set(v___x_1285_, 1, v___x_1284_);
v___x_1286_ = l_Lean_Json_mkObj(v___x_1285_);
lean_dec_ref_known(v___x_1285_, 2);
v___x_1287_ = l_Lean_Json_compress(v___x_1286_);
v___x_1288_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_1287_);
return v___x_1288_;
}
}
}
else
{
lean_object* v_a_1291_; lean_object* v___x_1293_; uint8_t v_isShared_1294_; uint8_t v_isSharedCheck_1298_; 
v_a_1291_ = lean_ctor_get(v___x_1266_, 0);
v_isSharedCheck_1298_ = !lean_is_exclusive(v___x_1266_);
if (v_isSharedCheck_1298_ == 0)
{
v___x_1293_ = v___x_1266_;
v_isShared_1294_ = v_isSharedCheck_1298_;
goto v_resetjp_1292_;
}
else
{
lean_inc(v_a_1291_);
lean_dec(v___x_1266_);
v___x_1293_ = lean_box(0);
v_isShared_1294_ = v_isSharedCheck_1298_;
goto v_resetjp_1292_;
}
v_resetjp_1292_:
{
lean_object* v___x_1296_; 
if (v_isShared_1294_ == 0)
{
v___x_1296_ = v___x_1293_;
goto v_reusejp_1295_;
}
else
{
lean_object* v_reuseFailAlloc_1297_; 
v_reuseFailAlloc_1297_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1297_, 0, v_a_1291_);
v___x_1296_ = v_reuseFailAlloc_1297_;
goto v_reusejp_1295_;
}
v_reusejp_1295_:
{
return v___x_1296_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___boxed(lean_object* v_inputs_1299_, lean_object* v_geo_1300_, lean_object* v_a_1301_){
_start:
{
lean_object* v_res_1302_; 
v_res_1302_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking(v_inputs_1299_, v_geo_1300_);
lean_dec_ref(v_inputs_1299_);
return v_res_1302_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2(lean_object* v_inputs_1303_, lean_object* v_geo_1304_, lean_object* v_range_1305_, lean_object* v_b_1306_, lean_object* v_i_1307_, lean_object* v_hs_1308_, lean_object* v_hl_1309_){
_start:
{
lean_object* v___x_1311_; 
v___x_1311_ = lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg(v_inputs_1303_, v_geo_1304_, v_range_1305_, v_b_1306_, v_i_1307_);
return v___x_1311_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___boxed(lean_object* v_inputs_1312_, lean_object* v_geo_1313_, lean_object* v_range_1314_, lean_object* v_b_1315_, lean_object* v_i_1316_, lean_object* v_hs_1317_, lean_object* v_hl_1318_, lean_object* v___y_1319_){
_start:
{
lean_object* v_res_1320_; 
v_res_1320_ = lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2(v_inputs_1312_, v_geo_1313_, v_range_1314_, v_b_1315_, v_i_1316_, v_hs_1317_, v_hl_1318_);
lean_dec_ref(v_range_1314_);
lean_dec_ref(v_inputs_1312_);
return v_res_1320_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg(lean_object* v_a_1327_, lean_object* v___x_1328_, lean_object* v_as_x27_1329_, lean_object* v_b_1330_){
_start:
{
if (lean_obj_tag(v_as_x27_1329_) == 0)
{
lean_object* v___x_1332_; 
lean_dec_ref(v___x_1328_);
v___x_1332_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1332_, 0, v_b_1330_);
return v___x_1332_;
}
else
{
lean_object* v_head_1333_; lean_object* v_tail_1334_; lean_object* v___x_1335_; uint8_t v___x_1336_; lean_object* v___x_1337_; 
v_head_1333_ = lean_ctor_get(v_as_x27_1329_, 0);
v_tail_1334_ = lean_ctor_get(v_as_x27_1329_, 1);
v___x_1335_ = lean_box(0);
v___x_1336_ = lean_unbox(v_head_1333_);
lean_inc_ref(v___x_1328_);
v___x_1337_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce(v_a_1327_, v___x_1328_, v___x_1336_);
if (lean_obj_tag(v___x_1337_) == 0)
{
lean_object* v_a_1338_; lean_object* v_snd_1339_; lean_object* v___x_1340_; lean_object* v___y_1342_; uint8_t v___x_1357_; 
v_a_1338_ = lean_ctor_get(v___x_1337_, 0);
lean_inc(v_a_1338_);
lean_dec_ref_known(v___x_1337_, 1);
v_snd_1339_ = lean_ctor_get(v_a_1338_, 1);
lean_inc(v_snd_1339_);
lean_dec(v_a_1338_);
v___x_1340_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__0));
v___x_1357_ = lean_unbox(v_head_1333_);
if (v___x_1357_ == 0)
{
lean_object* v___x_1358_; 
v___x_1358_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__4));
v___y_1342_ = v___x_1358_;
goto v___jp_1341_;
}
else
{
lean_object* v___x_1359_; 
v___x_1359_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__5));
v___y_1342_ = v___x_1359_;
goto v___jp_1341_;
}
v___jp_1341_:
{
lean_object* v___x_1343_; lean_object* v___x_1344_; lean_object* v___x_1345_; lean_object* v___x_1346_; lean_object* v___x_1347_; lean_object* v___x_1348_; lean_object* v___x_1349_; lean_object* v___x_1350_; lean_object* v___x_1351_; lean_object* v___x_1352_; lean_object* v___x_1353_; lean_object* v___x_1354_; lean_object* v___x_1355_; 
v___x_1343_ = lean_string_append(v___x_1340_, v___y_1342_);
v___x_1344_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__1));
v___x_1345_ = lean_string_append(v___x_1343_, v___x_1344_);
v___x_1346_ = lean_array_get_size(v_a_1327_);
v___x_1347_ = l_Nat_reprFast(v___x_1346_);
v___x_1348_ = lean_string_append(v___x_1345_, v___x_1347_);
lean_dec_ref(v___x_1347_);
v___x_1349_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__2));
v___x_1350_ = lean_string_append(v___x_1348_, v___x_1349_);
v___x_1351_ = l_Nat_reprFast(v_snd_1339_);
v___x_1352_ = lean_string_append(v___x_1350_, v___x_1351_);
lean_dec_ref(v___x_1351_);
v___x_1353_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__3));
v___x_1354_ = lean_string_append(v___x_1352_, v___x_1353_);
v___x_1355_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_1354_);
if (lean_obj_tag(v___x_1355_) == 0)
{
lean_dec_ref_known(v___x_1355_, 1);
v_as_x27_1329_ = v_tail_1334_;
v_b_1330_ = v___x_1335_;
goto _start;
}
else
{
lean_dec_ref(v___x_1328_);
return v___x_1355_;
}
}
}
else
{
lean_object* v_a_1360_; lean_object* v___x_1362_; uint8_t v_isShared_1363_; uint8_t v_isSharedCheck_1367_; 
lean_dec_ref(v___x_1328_);
v_a_1360_ = lean_ctor_get(v___x_1337_, 0);
v_isSharedCheck_1367_ = !lean_is_exclusive(v___x_1337_);
if (v_isSharedCheck_1367_ == 0)
{
v___x_1362_ = v___x_1337_;
v_isShared_1363_ = v_isSharedCheck_1367_;
goto v_resetjp_1361_;
}
else
{
lean_inc(v_a_1360_);
lean_dec(v___x_1337_);
v___x_1362_ = lean_box(0);
v_isShared_1363_ = v_isSharedCheck_1367_;
goto v_resetjp_1361_;
}
v_resetjp_1361_:
{
lean_object* v___x_1365_; 
if (v_isShared_1363_ == 0)
{
v___x_1365_ = v___x_1362_;
goto v_reusejp_1364_;
}
else
{
lean_object* v_reuseFailAlloc_1366_; 
v_reuseFailAlloc_1366_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1366_, 0, v_a_1360_);
v___x_1365_ = v_reuseFailAlloc_1366_;
goto v_reusejp_1364_;
}
v_reusejp_1364_:
{
return v___x_1365_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___boxed(lean_object* v_a_1368_, lean_object* v___x_1369_, lean_object* v_as_x27_1370_, lean_object* v_b_1371_, lean_object* v___y_1372_){
_start:
{
lean_object* v_res_1373_; 
v_res_1373_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg(v_a_1368_, v___x_1369_, v_as_x27_1370_, v_b_1371_);
lean_dec(v_as_x27_1370_);
lean_dec_ref(v_a_1368_);
return v_res_1373_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__1(lean_object* v_a_1374_, lean_object* v_a_1375_){
_start:
{
if (lean_obj_tag(v_a_1374_) == 0)
{
lean_object* v___x_1376_; 
v___x_1376_ = l_List_reverse___redArg(v_a_1375_);
return v___x_1376_;
}
else
{
lean_object* v_head_1377_; lean_object* v_tail_1378_; lean_object* v___x_1380_; uint8_t v_isShared_1381_; uint8_t v_isSharedCheck_1389_; 
v_head_1377_ = lean_ctor_get(v_a_1374_, 0);
v_tail_1378_ = lean_ctor_get(v_a_1374_, 1);
v_isSharedCheck_1389_ = !lean_is_exclusive(v_a_1374_);
if (v_isSharedCheck_1389_ == 0)
{
v___x_1380_ = v_a_1374_;
v_isShared_1381_ = v_isSharedCheck_1389_;
goto v_resetjp_1379_;
}
else
{
lean_inc(v_tail_1378_);
lean_inc(v_head_1377_);
lean_dec(v_a_1374_);
v___x_1380_ = lean_box(0);
v_isShared_1381_ = v_isSharedCheck_1389_;
goto v_resetjp_1379_;
}
v_resetjp_1379_:
{
uint8_t v___x_1382_; lean_object* v___x_1383_; lean_object* v___x_1384_; lean_object* v___x_1386_; 
v___x_1382_ = lean_unbox(v_head_1377_);
lean_dec(v_head_1377_);
v___x_1383_ = lean_uint8_to_nat(v___x_1382_);
v___x_1384_ = l_Nat_reprFast(v___x_1383_);
if (v_isShared_1381_ == 0)
{
lean_ctor_set(v___x_1380_, 1, v_a_1375_);
lean_ctor_set(v___x_1380_, 0, v___x_1384_);
v___x_1386_ = v___x_1380_;
goto v_reusejp_1385_;
}
else
{
lean_object* v_reuseFailAlloc_1388_; 
v_reuseFailAlloc_1388_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1388_, 0, v___x_1384_);
lean_ctor_set(v_reuseFailAlloc_1388_, 1, v_a_1375_);
v___x_1386_ = v_reuseFailAlloc_1388_;
goto v_reusejp_1385_;
}
v_reusejp_1385_:
{
v_a_1374_ = v_tail_1378_;
v_a_1375_ = v___x_1386_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__2(lean_object* v_as_1390_, size_t v_sz_1391_, size_t v_i_1392_, lean_object* v_b_1393_){
_start:
{
uint8_t v___x_1395_; 
v___x_1395_ = lean_usize_dec_lt(v_i_1392_, v_sz_1391_);
if (v___x_1395_ == 0)
{
lean_object* v___x_1396_; 
v___x_1396_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1396_, 0, v_b_1393_);
return v___x_1396_;
}
else
{
lean_object* v_a_1397_; lean_object* v_timestamp_1398_; lean_object* v_bytes_1399_; lean_object* v___x_1400_; lean_object* v___x_1401_; lean_object* v___x_1402_; lean_object* v___x_1403_; lean_object* v___x_1404_; lean_object* v___x_1405_; lean_object* v___x_1406_; lean_object* v___x_1407_; lean_object* v___x_1408_; lean_object* v___x_1409_; 
v_a_1397_ = lean_array_uget_borrowed(v_as_1390_, v_i_1392_);
v_timestamp_1398_ = lean_ctor_get(v_a_1397_, 0);
v_bytes_1399_ = lean_ctor_get(v_a_1397_, 1);
v___x_1400_ = lean_box(0);
lean_inc_ref(v_timestamp_1398_);
v___x_1401_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(v_timestamp_1398_);
v___x_1402_ = l_Nat_reprFast(v___x_1401_);
v___x_1403_ = ((lean_object*)(lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__4));
v___x_1404_ = lean_string_append(v___x_1402_, v___x_1403_);
v___x_1405_ = lean_box(0);
lean_inc(v_bytes_1399_);
v___x_1406_ = lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__1(v_bytes_1399_, v___x_1405_);
v___x_1407_ = l_String_intercalate(v___x_1403_, v___x_1406_);
v___x_1408_ = lean_string_append(v___x_1404_, v___x_1407_);
lean_dec_ref(v___x_1407_);
v___x_1409_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_1408_);
if (lean_obj_tag(v___x_1409_) == 0)
{
size_t v___x_1410_; size_t v___x_1411_; 
lean_dec_ref_known(v___x_1409_, 1);
v___x_1410_ = ((size_t)1ULL);
v___x_1411_ = lean_usize_add(v_i_1392_, v___x_1410_);
v_i_1392_ = v___x_1411_;
v_b_1393_ = v___x_1400_;
goto _start;
}
else
{
return v___x_1409_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__2___boxed(lean_object* v_as_1413_, lean_object* v_sz_1414_, lean_object* v_i_1415_, lean_object* v_b_1416_, lean_object* v___y_1417_){
_start:
{
size_t v_sz_boxed_1418_; size_t v_i_boxed_1419_; lean_object* v_res_1420_; 
v_sz_boxed_1418_ = lean_unbox_usize(v_sz_1414_);
lean_dec(v_sz_1414_);
v_i_boxed_1419_ = lean_unbox_usize(v_i_1415_);
lean_dec(v_i_1415_);
v_res_1420_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__2(v_as_1413_, v_sz_boxed_1418_, v_i_boxed_1419_, v_b_1416_);
lean_dec_ref(v_as_1413_);
return v_res_1420_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___redArg(lean_object* v_as_x27_1421_, lean_object* v_b_1422_){
_start:
{
if (lean_obj_tag(v_as_x27_1421_) == 0)
{
lean_object* v___x_1424_; 
v___x_1424_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1424_, 0, v_b_1422_);
return v___x_1424_;
}
else
{
lean_object* v_head_1425_; lean_object* v_position_1426_; lean_object* v_tail_1427_; lean_object* v_icao_1428_; lean_object* v_lat_1429_; lean_object* v_lon_1430_; lean_object* v___x_1431_; lean_object* v___x_1432_; lean_object* v___x_1433_; lean_object* v___x_1434_; lean_object* v___x_1435_; lean_object* v___x_1436_; lean_object* v___x_1437_; lean_object* v___x_1438_; lean_object* v___x_1439_; lean_object* v___x_1440_; lean_object* v___x_1441_; 
v_head_1425_ = lean_ctor_get(v_as_x27_1421_, 0);
v_position_1426_ = lean_ctor_get(v_head_1425_, 1);
v_tail_1427_ = lean_ctor_get(v_as_x27_1421_, 1);
v_icao_1428_ = lean_ctor_get(v_head_1425_, 0);
v_lat_1429_ = lean_ctor_get(v_position_1426_, 0);
v_lon_1430_ = lean_ctor_get(v_position_1426_, 1);
v___x_1431_ = lean_box(0);
v___x_1432_ = ((lean_object*)(lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__4));
lean_inc_ref(v_icao_1428_);
v___x_1433_ = lean_string_append(v_icao_1428_, v___x_1432_);
lean_inc_ref(v_lat_1429_);
v___x_1434_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(v_lat_1429_);
v___x_1435_ = l_Nat_reprFast(v___x_1434_);
v___x_1436_ = lean_string_append(v___x_1433_, v___x_1435_);
lean_dec_ref(v___x_1435_);
v___x_1437_ = lean_string_append(v___x_1436_, v___x_1432_);
lean_inc_ref(v_lon_1430_);
v___x_1438_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(v_lon_1430_);
v___x_1439_ = l_Nat_reprFast(v___x_1438_);
v___x_1440_ = lean_string_append(v___x_1437_, v___x_1439_);
lean_dec_ref(v___x_1439_);
v___x_1441_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_1440_);
if (lean_obj_tag(v___x_1441_) == 0)
{
lean_dec_ref_known(v___x_1441_, 1);
v_as_x27_1421_ = v_tail_1427_;
v_b_1422_ = v___x_1431_;
goto _start;
}
else
{
return v___x_1441_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___redArg___boxed(lean_object* v_as_x27_1443_, lean_object* v_b_1444_, lean_object* v___y_1445_){
_start:
{
lean_object* v_res_1446_; 
v_res_1446_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___redArg(v_as_x27_1443_, v_b_1444_);
lean_dec(v_as_x27_1443_);
return v_res_1446_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute(lean_object* v_mode_1456_, lean_object* v_path_1457_){
_start:
{
lean_object* v___x_1459_; 
v___x_1459_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs(v_path_1457_);
if (lean_obj_tag(v___x_1459_) == 0)
{
lean_object* v_a_1460_; lean_object* v___x_1461_; 
v_a_1460_ = lean_ctor_get(v___x_1459_, 0);
lean_inc(v_a_1460_);
lean_dec_ref_known(v___x_1459_, 1);
v___x_1461_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports();
if (lean_obj_tag(v___x_1461_) == 0)
{
lean_object* v_a_1462_; lean_object* v___x_1464_; uint8_t v_isShared_1465_; uint8_t v_isSharedCheck_1524_; 
v_a_1462_ = lean_ctor_get(v___x_1461_, 0);
v_isSharedCheck_1524_ = !lean_is_exclusive(v___x_1461_);
if (v_isSharedCheck_1524_ == 0)
{
v___x_1464_ = v___x_1461_;
v_isShared_1465_ = v_isSharedCheck_1524_;
goto v_resetjp_1463_;
}
else
{
lean_inc(v_a_1462_);
lean_dec(v___x_1461_);
v___x_1464_ = lean_box(0);
v_isShared_1465_ = v_isSharedCheck_1524_;
goto v_resetjp_1463_;
}
v_resetjp_1463_:
{
lean_object* v___x_1466_; lean_object* v___x_1467_; uint8_t v___x_1468_; 
lean_inc(v_a_1462_);
v___x_1466_ = lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography(v_a_1462_);
v___x_1467_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__0));
v___x_1468_ = lean_string_dec_eq(v_mode_1456_, v___x_1467_);
if (v___x_1468_ == 0)
{
lean_object* v___x_1469_; uint8_t v___x_1470_; 
v___x_1469_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__1));
v___x_1470_ = lean_string_dec_eq(v_mode_1456_, v___x_1469_);
if (v___x_1470_ == 0)
{
lean_object* v___x_1471_; uint8_t v___x_1472_; 
v___x_1471_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__2));
v___x_1472_ = lean_string_dec_eq(v_mode_1456_, v___x_1471_);
if (v___x_1472_ == 0)
{
lean_object* v___x_1473_; uint8_t v___x_1474_; 
v___x_1473_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__3));
v___x_1474_ = lean_string_dec_eq(v_mode_1456_, v___x_1473_);
if (v___x_1474_ == 0)
{
lean_object* v___x_1475_; uint8_t v___x_1476_; 
lean_dec_ref(v___x_1466_);
v___x_1475_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__4));
v___x_1476_ = lean_string_dec_eq(v_mode_1456_, v___x_1475_);
if (v___x_1476_ == 0)
{
lean_object* v___x_1477_; uint8_t v___x_1478_; 
lean_dec(v_a_1460_);
v___x_1477_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__5));
v___x_1478_ = lean_string_dec_eq(v_mode_1456_, v___x_1477_);
if (v___x_1478_ == 0)
{
lean_object* v___x_1479_; lean_object* v___x_1481_; 
lean_dec(v_a_1462_);
v___x_1479_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__7));
if (v_isShared_1465_ == 0)
{
lean_ctor_set_tag(v___x_1464_, 1);
lean_ctor_set(v___x_1464_, 0, v___x_1479_);
v___x_1481_ = v___x_1464_;
goto v_reusejp_1480_;
}
else
{
lean_object* v_reuseFailAlloc_1482_; 
v_reuseFailAlloc_1482_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1482_, 0, v___x_1479_);
v___x_1481_ = v_reuseFailAlloc_1482_;
goto v_reusejp_1480_;
}
v_reusejp_1480_:
{
return v___x_1481_;
}
}
else
{
lean_object* v___x_1483_; lean_object* v___x_1484_; 
lean_del_object(v___x_1464_);
v___x_1483_ = lean_box(0);
v___x_1484_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___redArg(v_a_1462_, v___x_1483_);
lean_dec(v_a_1462_);
if (lean_obj_tag(v___x_1484_) == 0)
{
lean_object* v___x_1486_; uint8_t v_isShared_1487_; uint8_t v_isSharedCheck_1491_; 
v_isSharedCheck_1491_ = !lean_is_exclusive(v___x_1484_);
if (v_isSharedCheck_1491_ == 0)
{
lean_object* v_unused_1492_; 
v_unused_1492_ = lean_ctor_get(v___x_1484_, 0);
lean_dec(v_unused_1492_);
v___x_1486_ = v___x_1484_;
v_isShared_1487_ = v_isSharedCheck_1491_;
goto v_resetjp_1485_;
}
else
{
lean_dec(v___x_1484_);
v___x_1486_ = lean_box(0);
v_isShared_1487_ = v_isSharedCheck_1491_;
goto v_resetjp_1485_;
}
v_resetjp_1485_:
{
lean_object* v___x_1489_; 
if (v_isShared_1487_ == 0)
{
lean_ctor_set(v___x_1486_, 0, v___x_1483_);
v___x_1489_ = v___x_1486_;
goto v_reusejp_1488_;
}
else
{
lean_object* v_reuseFailAlloc_1490_; 
v_reuseFailAlloc_1490_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1490_, 0, v___x_1483_);
v___x_1489_ = v_reuseFailAlloc_1490_;
goto v_reusejp_1488_;
}
v_reusejp_1488_:
{
return v___x_1489_;
}
}
}
else
{
return v___x_1484_;
}
}
}
else
{
lean_object* v___x_1493_; size_t v_sz_1494_; size_t v___x_1495_; lean_object* v___x_1496_; 
lean_del_object(v___x_1464_);
lean_dec(v_a_1462_);
v___x_1493_ = lean_box(0);
v_sz_1494_ = lean_array_size(v_a_1460_);
v___x_1495_ = ((size_t)0ULL);
v___x_1496_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__2(v_a_1460_, v_sz_1494_, v___x_1495_, v___x_1493_);
lean_dec(v_a_1460_);
if (lean_obj_tag(v___x_1496_) == 0)
{
lean_object* v___x_1498_; uint8_t v_isShared_1499_; uint8_t v_isSharedCheck_1503_; 
v_isSharedCheck_1503_ = !lean_is_exclusive(v___x_1496_);
if (v_isSharedCheck_1503_ == 0)
{
lean_object* v_unused_1504_; 
v_unused_1504_ = lean_ctor_get(v___x_1496_, 0);
lean_dec(v_unused_1504_);
v___x_1498_ = v___x_1496_;
v_isShared_1499_ = v_isSharedCheck_1503_;
goto v_resetjp_1497_;
}
else
{
lean_dec(v___x_1496_);
v___x_1498_ = lean_box(0);
v_isShared_1499_ = v_isSharedCheck_1503_;
goto v_resetjp_1497_;
}
v_resetjp_1497_:
{
lean_object* v___x_1501_; 
if (v_isShared_1499_ == 0)
{
lean_ctor_set(v___x_1498_, 0, v___x_1493_);
v___x_1501_ = v___x_1498_;
goto v_reusejp_1500_;
}
else
{
lean_object* v_reuseFailAlloc_1502_; 
v_reuseFailAlloc_1502_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1502_, 0, v___x_1493_);
v___x_1501_ = v_reuseFailAlloc_1502_;
goto v_reusejp_1500_;
}
v_reusejp_1500_:
{
return v___x_1501_;
}
}
}
else
{
return v___x_1496_;
}
}
}
else
{
lean_object* v___x_1505_; 
lean_del_object(v___x_1464_);
lean_dec(v_a_1462_);
v___x_1505_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking(v_a_1460_, v___x_1466_);
lean_dec(v_a_1460_);
return v___x_1505_;
}
}
else
{
lean_object* v___x_1506_; lean_object* v___x_1507_; lean_object* v___x_1508_; lean_object* v___x_1509_; lean_object* v___x_1510_; lean_object* v___x_1511_; lean_object* v___x_1512_; 
lean_del_object(v___x_1464_);
lean_dec(v_a_1462_);
v___x_1506_ = lean_box(0);
v___x_1507_ = lean_box(v___x_1472_);
v___x_1508_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1508_, 0, v___x_1507_);
lean_ctor_set(v___x_1508_, 1, v___x_1506_);
v___x_1509_ = lean_box(v___x_1470_);
v___x_1510_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1510_, 0, v___x_1509_);
lean_ctor_set(v___x_1510_, 1, v___x_1508_);
v___x_1511_ = lean_box(0);
v___x_1512_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg(v_a_1460_, v___x_1466_, v___x_1510_, v___x_1511_);
lean_dec_ref_known(v___x_1510_, 2);
lean_dec(v_a_1460_);
if (lean_obj_tag(v___x_1512_) == 0)
{
lean_object* v___x_1514_; uint8_t v_isShared_1515_; uint8_t v_isSharedCheck_1519_; 
v_isSharedCheck_1519_ = !lean_is_exclusive(v___x_1512_);
if (v_isSharedCheck_1519_ == 0)
{
lean_object* v_unused_1520_; 
v_unused_1520_ = lean_ctor_get(v___x_1512_, 0);
lean_dec(v_unused_1520_);
v___x_1514_ = v___x_1512_;
v_isShared_1515_ = v_isSharedCheck_1519_;
goto v_resetjp_1513_;
}
else
{
lean_dec(v___x_1512_);
v___x_1514_ = lean_box(0);
v_isShared_1515_ = v_isSharedCheck_1519_;
goto v_resetjp_1513_;
}
v_resetjp_1513_:
{
lean_object* v___x_1517_; 
if (v_isShared_1515_ == 0)
{
lean_ctor_set(v___x_1514_, 0, v___x_1511_);
v___x_1517_ = v___x_1514_;
goto v_reusejp_1516_;
}
else
{
lean_object* v_reuseFailAlloc_1518_; 
v_reuseFailAlloc_1518_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1518_, 0, v___x_1511_);
v___x_1517_ = v_reuseFailAlloc_1518_;
goto v_reusejp_1516_;
}
v_reusejp_1516_:
{
return v___x_1517_;
}
}
}
else
{
return v___x_1512_;
}
}
}
else
{
lean_object* v___x_1521_; 
lean_del_object(v___x_1464_);
lean_dec(v_a_1462_);
v___x_1521_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker(v_a_1460_, v___x_1466_, v___x_1470_);
lean_dec(v_a_1460_);
return v___x_1521_;
}
}
else
{
uint8_t v___x_1522_; lean_object* v___x_1523_; 
lean_del_object(v___x_1464_);
lean_dec(v_a_1462_);
v___x_1522_ = 0;
v___x_1523_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker(v_a_1460_, v___x_1466_, v___x_1522_);
lean_dec(v_a_1460_);
return v___x_1523_;
}
}
}
else
{
lean_object* v_a_1525_; lean_object* v___x_1527_; uint8_t v_isShared_1528_; uint8_t v_isSharedCheck_1532_; 
lean_dec(v_a_1460_);
v_a_1525_ = lean_ctor_get(v___x_1461_, 0);
v_isSharedCheck_1532_ = !lean_is_exclusive(v___x_1461_);
if (v_isSharedCheck_1532_ == 0)
{
v___x_1527_ = v___x_1461_;
v_isShared_1528_ = v_isSharedCheck_1532_;
goto v_resetjp_1526_;
}
else
{
lean_inc(v_a_1525_);
lean_dec(v___x_1461_);
v___x_1527_ = lean_box(0);
v_isShared_1528_ = v_isSharedCheck_1532_;
goto v_resetjp_1526_;
}
v_resetjp_1526_:
{
lean_object* v___x_1530_; 
if (v_isShared_1528_ == 0)
{
v___x_1530_ = v___x_1527_;
goto v_reusejp_1529_;
}
else
{
lean_object* v_reuseFailAlloc_1531_; 
v_reuseFailAlloc_1531_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1531_, 0, v_a_1525_);
v___x_1530_ = v_reuseFailAlloc_1531_;
goto v_reusejp_1529_;
}
v_reusejp_1529_:
{
return v___x_1530_;
}
}
}
}
else
{
lean_object* v_a_1533_; lean_object* v___x_1535_; uint8_t v_isShared_1536_; uint8_t v_isSharedCheck_1540_; 
v_a_1533_ = lean_ctor_get(v___x_1459_, 0);
v_isSharedCheck_1540_ = !lean_is_exclusive(v___x_1459_);
if (v_isSharedCheck_1540_ == 0)
{
v___x_1535_ = v___x_1459_;
v_isShared_1536_ = v_isSharedCheck_1540_;
goto v_resetjp_1534_;
}
else
{
lean_inc(v_a_1533_);
lean_dec(v___x_1459_);
v___x_1535_ = lean_box(0);
v_isShared_1536_ = v_isSharedCheck_1540_;
goto v_resetjp_1534_;
}
v_resetjp_1534_:
{
lean_object* v___x_1538_; 
if (v_isShared_1536_ == 0)
{
v___x_1538_ = v___x_1535_;
goto v_reusejp_1537_;
}
else
{
lean_object* v_reuseFailAlloc_1539_; 
v_reuseFailAlloc_1539_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1539_, 0, v_a_1533_);
v___x_1538_ = v_reuseFailAlloc_1539_;
goto v_reusejp_1537_;
}
v_reusejp_1537_:
{
return v___x_1538_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___boxed(lean_object* v_mode_1541_, lean_object* v_path_1542_, lean_object* v_a_1543_){
_start:
{
lean_object* v_res_1544_; 
v_res_1544_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute(v_mode_1541_, v_path_1542_);
lean_dec_ref(v_path_1542_);
lean_dec_ref(v_mode_1541_);
return v_res_1544_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0(lean_object* v_as_1545_, lean_object* v_as_x27_1546_, lean_object* v_b_1547_, lean_object* v_a_1548_){
_start:
{
lean_object* v___x_1550_; 
v___x_1550_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___redArg(v_as_x27_1546_, v_b_1547_);
return v___x_1550_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___boxed(lean_object* v_as_1551_, lean_object* v_as_x27_1552_, lean_object* v_b_1553_, lean_object* v_a_1554_, lean_object* v___y_1555_){
_start:
{
lean_object* v_res_1556_; 
v_res_1556_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0(v_as_1551_, v_as_x27_1552_, v_b_1553_, v_a_1554_);
lean_dec(v_as_x27_1552_);
lean_dec(v_as_1551_);
return v_res_1556_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3(lean_object* v_a_1557_, lean_object* v___x_1558_, lean_object* v_as_1559_, lean_object* v_as_x27_1560_, lean_object* v_b_1561_, lean_object* v_a_1562_){
_start:
{
lean_object* v___x_1564_; 
v___x_1564_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg(v_a_1557_, v___x_1558_, v_as_x27_1560_, v_b_1561_);
return v___x_1564_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___boxed(lean_object* v_a_1565_, lean_object* v___x_1566_, lean_object* v_as_1567_, lean_object* v_as_x27_1568_, lean_object* v_b_1569_, lean_object* v_a_1570_, lean_object* v___y_1571_){
_start:
{
lean_object* v_res_1572_; 
v_res_1572_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3(v_a_1565_, v___x_1566_, v_as_1567_, v_as_x27_1568_, v_b_1569_, v_a_1570_);
lean_dec(v_as_x27_1568_);
lean_dec(v_as_1567_);
lean_dec_ref(v_a_1565_);
return v_res_1572_;
}
}
static lean_object* _init_lp_lean1090_main___boxed__const__1(void){
_start:
{
uint32_t v___x_1574_; lean_object* v___x_1575_; 
v___x_1574_ = 2;
v___x_1575_ = lean_box_uint32(v___x_1574_);
return v___x_1575_;
}
}
static lean_object* _init_lp_lean1090_main___boxed__const__2(void){
_start:
{
uint32_t v___x_1576_; lean_object* v___x_1577_; 
v___x_1576_ = 0;
v___x_1577_ = lean_box_uint32(v___x_1576_);
return v___x_1577_;
}
}
LEAN_EXPORT lean_object* _lean_main(lean_object* v_args_1578_){
_start:
{
if (lean_obj_tag(v_args_1578_) == 1)
{
lean_object* v_tail_1600_; 
v_tail_1600_ = lean_ctor_get(v_args_1578_, 1);
lean_inc(v_tail_1600_);
if (lean_obj_tag(v_tail_1600_) == 1)
{
lean_object* v_tail_1601_; 
v_tail_1601_ = lean_ctor_get(v_tail_1600_, 1);
if (lean_obj_tag(v_tail_1601_) == 0)
{
lean_object* v_head_1602_; lean_object* v_head_1603_; lean_object* v___x_1604_; 
v_head_1602_ = lean_ctor_get(v_args_1578_, 0);
lean_inc(v_head_1602_);
lean_dec_ref_known(v_args_1578_, 2);
v_head_1603_ = lean_ctor_get(v_tail_1600_, 0);
lean_inc(v_head_1603_);
lean_dec_ref_known(v_tail_1600_, 2);
v___x_1604_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute(v_head_1602_, v_head_1603_);
lean_dec(v_head_1603_);
lean_dec(v_head_1602_);
if (lean_obj_tag(v___x_1604_) == 0)
{
lean_object* v___x_1606_; uint8_t v_isShared_1607_; uint8_t v_isSharedCheck_1612_; 
v_isSharedCheck_1612_ = !lean_is_exclusive(v___x_1604_);
if (v_isSharedCheck_1612_ == 0)
{
lean_object* v_unused_1613_; 
v_unused_1613_ = lean_ctor_get(v___x_1604_, 0);
lean_dec(v_unused_1613_);
v___x_1606_ = v___x_1604_;
v_isShared_1607_ = v_isSharedCheck_1612_;
goto v_resetjp_1605_;
}
else
{
lean_dec(v___x_1604_);
v___x_1606_ = lean_box(0);
v_isShared_1607_ = v_isSharedCheck_1612_;
goto v_resetjp_1605_;
}
v_resetjp_1605_:
{
lean_object* v___x_1608_; lean_object* v___x_1610_; 
v___x_1608_ = lp_lean1090_main___boxed__const__2;
if (v_isShared_1607_ == 0)
{
lean_ctor_set(v___x_1606_, 0, v___x_1608_);
v___x_1610_ = v___x_1606_;
goto v_reusejp_1609_;
}
else
{
lean_object* v_reuseFailAlloc_1611_; 
v_reuseFailAlloc_1611_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1611_, 0, v___x_1608_);
v___x_1610_ = v_reuseFailAlloc_1611_;
goto v_reusejp_1609_;
}
v_reusejp_1609_:
{
return v___x_1610_;
}
}
}
else
{
lean_object* v_a_1614_; lean_object* v___x_1616_; uint8_t v_isShared_1617_; uint8_t v_isSharedCheck_1621_; 
v_a_1614_ = lean_ctor_get(v___x_1604_, 0);
v_isSharedCheck_1621_ = !lean_is_exclusive(v___x_1604_);
if (v_isSharedCheck_1621_ == 0)
{
v___x_1616_ = v___x_1604_;
v_isShared_1617_ = v_isSharedCheck_1621_;
goto v_resetjp_1615_;
}
else
{
lean_inc(v_a_1614_);
lean_dec(v___x_1604_);
v___x_1616_ = lean_box(0);
v_isShared_1617_ = v_isSharedCheck_1621_;
goto v_resetjp_1615_;
}
v_resetjp_1615_:
{
lean_object* v___x_1619_; 
if (v_isShared_1617_ == 0)
{
v___x_1619_ = v___x_1616_;
goto v_reusejp_1618_;
}
else
{
lean_object* v_reuseFailAlloc_1620_; 
v_reuseFailAlloc_1620_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1620_, 0, v_a_1614_);
v___x_1619_ = v_reuseFailAlloc_1620_;
goto v_reusejp_1618_;
}
v_reusejp_1618_:
{
return v___x_1619_;
}
}
}
}
else
{
lean_dec_ref_known(v_tail_1600_, 2);
lean_dec_ref_known(v_args_1578_, 2);
goto v___jp_1580_;
}
}
else
{
lean_dec(v_tail_1600_);
lean_dec_ref_known(v_args_1578_, 2);
goto v___jp_1580_;
}
}
else
{
lean_dec(v_args_1578_);
goto v___jp_1580_;
}
v___jp_1580_:
{
lean_object* v___x_1581_; lean_object* v___x_1582_; 
v___x_1581_ = ((lean_object*)(lp_lean1090_main___closed__0));
v___x_1582_ = l_IO_eprintln___at___00__private_Init_System_IO_0__IO_eprintlnAux_spec__0(v___x_1581_);
if (lean_obj_tag(v___x_1582_) == 0)
{
lean_object* v___x_1584_; uint8_t v_isShared_1585_; uint8_t v_isSharedCheck_1590_; 
v_isSharedCheck_1590_ = !lean_is_exclusive(v___x_1582_);
if (v_isSharedCheck_1590_ == 0)
{
lean_object* v_unused_1591_; 
v_unused_1591_ = lean_ctor_get(v___x_1582_, 0);
lean_dec(v_unused_1591_);
v___x_1584_ = v___x_1582_;
v_isShared_1585_ = v_isSharedCheck_1590_;
goto v_resetjp_1583_;
}
else
{
lean_dec(v___x_1582_);
v___x_1584_ = lean_box(0);
v_isShared_1585_ = v_isSharedCheck_1590_;
goto v_resetjp_1583_;
}
v_resetjp_1583_:
{
lean_object* v___x_1586_; lean_object* v___x_1588_; 
v___x_1586_ = lp_lean1090_main___boxed__const__1;
if (v_isShared_1585_ == 0)
{
lean_ctor_set(v___x_1584_, 0, v___x_1586_);
v___x_1588_ = v___x_1584_;
goto v_reusejp_1587_;
}
else
{
lean_object* v_reuseFailAlloc_1589_; 
v_reuseFailAlloc_1589_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1589_, 0, v___x_1586_);
v___x_1588_ = v_reuseFailAlloc_1589_;
goto v_reusejp_1587_;
}
v_reusejp_1587_:
{
return v___x_1588_;
}
}
}
else
{
lean_object* v_a_1592_; lean_object* v___x_1594_; uint8_t v_isShared_1595_; uint8_t v_isSharedCheck_1599_; 
v_a_1592_ = lean_ctor_get(v___x_1582_, 0);
v_isSharedCheck_1599_ = !lean_is_exclusive(v___x_1582_);
if (v_isSharedCheck_1599_ == 0)
{
v___x_1594_ = v___x_1582_;
v_isShared_1595_ = v_isSharedCheck_1599_;
goto v_resetjp_1593_;
}
else
{
lean_inc(v_a_1592_);
lean_dec(v___x_1582_);
v___x_1594_ = lean_box(0);
v_isShared_1595_ = v_isSharedCheck_1599_;
goto v_resetjp_1593_;
}
v_resetjp_1593_:
{
lean_object* v___x_1597_; 
if (v_isShared_1595_ == 0)
{
v___x_1597_ = v___x_1594_;
goto v_reusejp_1596_;
}
else
{
lean_object* v_reuseFailAlloc_1598_; 
v_reuseFailAlloc_1598_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1598_, 0, v_a_1592_);
v___x_1597_ = v_reuseFailAlloc_1598_;
goto v_reusejp_1596_;
}
v_reusejp_1596_:
{
return v___x_1597_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_main___boxed(lean_object* v_args_1622_, lean_object* v_a_1623_){
_start:
{
lean_object* v_res_1624_; 
v_res_1624_ = _lean_main(v_args_1622_);
return v_res_1624_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Impl(uint8_t builtin);
lean_object* initialize_lean1090_Impl_JSON(uint8_t builtin);
lean_object* initialize_Lean_Data_Json_Parser(uint8_t builtin);
lean_object* initialize_Lean_Data_Json_FromToJson_Basic(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Bench_WholeDecoder(uint8_t builtin) {
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
res = initialize_lean1090_Impl(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_JSON(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean_Data_Json_Parser(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean_Data_Json_FromToJson_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_expectedMessages = _init_lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_expectedMessages();
lean_mark_persistent(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_expectedMessages);
lp_lean1090_main___boxed__const__1 = _init_lp_lean1090_main___boxed__const__1();
lean_mark_persistent(lp_lean1090_main___boxed__const__1);
lp_lean1090_main___boxed__const__2 = _init_lp_lean1090_main___boxed__const__2();
lean_mark_persistent(lp_lean1090_main___boxed__const__2);
return lean_io_result_mk_ok(lean_box(0));
}
char ** lean_setup_args(int argc, char ** argv);
#if defined(WIN32) || defined(_WIN32)
#include <windows.h>
#endif
lean_object* run_main(int argc, char ** argv) {
    lean_object* in = lean_box(0);
    int i = argc;
    while (i > 1) {
      lean_object* n;
      i--;
      n = lean_alloc_ctor(1,2,0); lean_ctor_set(n, 0, lean_mk_string(argv[i])); lean_ctor_set(n, 1, in);
      in = n;
    }
    return _lean_main(in);
}
int main(int argc, char ** argv) {
#if defined(WIN32) || defined(_WIN32)
  SetErrorMode(SEM_FAILCRITICALERRORS);
  SetConsoleOutputCP(CP_UTF8);
#endif
  lean_object* res;
  argv = lean_setup_args(argc, argv);
  res = initialize_lean1090_Bench_WholeDecoder(1 /* builtin */);
  lean_io_mark_end_initialization();
  if (lean_io_result_is_ok(res)) {
    lean_dec_ref(res);
    lean_init_task_manager();
    res = lean_run_main(&run_main, argc, argv);
  }
  lean_finalize_task_manager();
  if (lean_io_result_is_ok(res)) {
    int ret = lean_unbox_uint32(lean_io_result_get_value(res));
    lean_dec_ref(res);
    return ret;
  } else {
    lean_io_result_show_error(res);
    lean_dec_ref(res);
    return 1;
  }
}
#ifdef __cplusplus
}
#endif
