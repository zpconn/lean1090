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
lean_object* lean_array_get_size(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
size_t lean_array_size(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
size_t lean_usize_add(size_t, size_t);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
lean_object* l_IO_eprintln___at___00__private_Init_System_IO_0__IO_eprintlnAux_spec__0(lean_object*);
lean_object* lean_get_stdout();
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_string_push(lean_object*, uint32_t);
lean_object* lean_get_stdin();
lean_object* lean_string_utf8_byte_size(lean_object*);
lean_object* l_String_Slice_trimAscii(lean_object*);
lean_object* l_String_Slice_toString(lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_io_mono_nanos_now();
lean_object* lp_lean1090_Lean1090_Impl_decode(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_JSON_raw(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* l_Rat_floor(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_streamStep(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_uget(lean_object*, size_t);
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
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consumeMessages_spec__0(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consumeMessages_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consumeMessages(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consumeMessages___boxed(lean_object*, lean_object*);
static const lean_string_object lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 34, .m_capacity = 34, .m_length = 33, .m_data = "decoder rejected a corpus message"};
static const lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0___closed__0 = (const lean_object*)&lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0___closed__0_value;
static const lean_ctor_object lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0___closed__0_value)}};
static const lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0___closed__1 = (const lean_object*)&lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0___closed__1_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce_spec__0(lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce___closed__0 = (const lean_object*)&lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce___boxed(lean_object*, lean_object*, lean_object*);
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
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consumeMessages_spec__0(lean_object* v_as_756_, size_t v_sz_757_, size_t v_i_758_, lean_object* v_b_759_){
_start:
{
uint8_t v___x_761_; 
v___x_761_ = lean_usize_dec_lt(v_i_758_, v_sz_757_);
if (v___x_761_ == 0)
{
lean_object* v___x_762_; 
v___x_762_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_762_, 0, v_b_759_);
return v___x_762_;
}
else
{
lean_object* v_a_763_; lean_object* v_fields_764_; lean_object* v_decoded_765_; lean_object* v_parity_766_; lean_object* v_commB_767_; lean_object* v_semanticCommB_768_; lean_object* v___x_769_; lean_object* v___x_770_; lean_object* v___x_771_; lean_object* v___x_772_; lean_object* v___x_773_; lean_object* v___x_774_; lean_object* v___x_775_; size_t v___x_776_; size_t v___x_777_; 
v_a_763_ = lean_array_uget_borrowed(v_as_756_, v_i_758_);
v_fields_764_ = lean_ctor_get(v_a_763_, 0);
v_decoded_765_ = lean_ctor_get(v_a_763_, 1);
v_parity_766_ = lean_ctor_get(v_fields_764_, 1);
v_commB_767_ = lean_ctor_get(v_decoded_765_, 6);
v_semanticCommB_768_ = lean_ctor_get(v_decoded_765_, 8);
v___x_769_ = lean_nat_add(v_b_759_, v_parity_766_);
lean_dec(v_b_759_);
v___x_770_ = l_List_lengthTR___redArg(v_commB_767_);
v___x_771_ = lean_nat_add(v___x_769_, v___x_770_);
lean_dec(v___x_770_);
lean_dec(v___x_769_);
v___x_772_ = l_List_lengthTR___redArg(v_semanticCommB_768_);
v___x_773_ = lean_nat_add(v___x_771_, v___x_772_);
lean_dec(v___x_772_);
lean_dec(v___x_771_);
v___x_774_ = lean_cstr_to_nat("4294967296");
v___x_775_ = lean_nat_mod(v___x_773_, v___x_774_);
lean_dec(v___x_773_);
v___x_776_ = ((size_t)1ULL);
v___x_777_ = lean_usize_add(v_i_758_, v___x_776_);
v_i_758_ = v___x_777_;
v_b_759_ = v___x_775_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consumeMessages_spec__0___boxed(lean_object* v_as_779_, lean_object* v_sz_780_, lean_object* v_i_781_, lean_object* v_b_782_, lean_object* v___y_783_){
_start:
{
size_t v_sz_boxed_784_; size_t v_i_boxed_785_; lean_object* v_res_786_; 
v_sz_boxed_784_ = lean_unbox_usize(v_sz_780_);
lean_dec(v_sz_780_);
v_i_boxed_785_ = lean_unbox_usize(v_i_781_);
lean_dec(v_i_781_);
v_res_786_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consumeMessages_spec__0(v_as_779_, v_sz_boxed_784_, v_i_boxed_785_, v_b_782_);
lean_dec_ref(v_as_779_);
return v_res_786_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consumeMessages(lean_object* v_output_787_){
_start:
{
lean_object* v___x_789_; lean_object* v___x_790_; uint8_t v___x_791_; 
v___x_789_ = lean_array_get_size(v_output_787_);
v___x_790_ = lean_unsigned_to_nat(172432u);
v___x_791_ = lean_nat_dec_eq(v___x_789_, v___x_790_);
if (v___x_791_ == 0)
{
lean_object* v___x_792_; lean_object* v___x_793_; 
v___x_792_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__1));
v___x_793_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_793_, 0, v___x_792_);
return v___x_793_;
}
else
{
lean_object* v_checksum_794_; size_t v_sz_795_; size_t v___x_796_; lean_object* v___x_797_; 
v_checksum_794_ = lean_unsigned_to_nat(0u);
v_sz_795_ = lean_array_size(v_output_787_);
v___x_796_ = ((size_t)0ULL);
v___x_797_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consumeMessages_spec__0(v_output_787_, v_sz_795_, v___x_796_, v_checksum_794_);
if (lean_obj_tag(v___x_797_) == 0)
{
lean_object* v_a_798_; lean_object* v___x_799_; lean_object* v___x_800_; lean_object* v___x_801_; lean_object* v___x_802_; lean_object* v___x_803_; lean_object* v___x_804_; lean_object* v___x_805_; lean_object* v___x_806_; 
v_a_798_ = lean_ctor_get(v___x_797_, 0);
lean_inc(v_a_798_);
lean_dec_ref_known(v___x_797_, 1);
v___x_799_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__2));
v___x_800_ = l_Nat_reprFast(v___x_789_);
v___x_801_ = lean_string_append(v___x_799_, v___x_800_);
lean_dec_ref(v___x_800_);
v___x_802_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume___closed__4));
v___x_803_ = lean_string_append(v___x_801_, v___x_802_);
v___x_804_ = l_Nat_reprFast(v_a_798_);
v___x_805_ = lean_string_append(v___x_803_, v___x_804_);
lean_dec_ref(v___x_804_);
v___x_806_ = l_IO_eprintln___at___00__private_Init_System_IO_0__IO_eprintlnAux_spec__0(v___x_805_);
return v___x_806_;
}
else
{
lean_object* v_a_807_; lean_object* v___x_809_; uint8_t v_isShared_810_; uint8_t v_isSharedCheck_814_; 
v_a_807_ = lean_ctor_get(v___x_797_, 0);
v_isSharedCheck_814_ = !lean_is_exclusive(v___x_797_);
if (v_isSharedCheck_814_ == 0)
{
v___x_809_ = v___x_797_;
v_isShared_810_ = v_isSharedCheck_814_;
goto v_resetjp_808_;
}
else
{
lean_inc(v_a_807_);
lean_dec(v___x_797_);
v___x_809_ = lean_box(0);
v_isShared_810_ = v_isSharedCheck_814_;
goto v_resetjp_808_;
}
v_resetjp_808_:
{
lean_object* v___x_812_; 
if (v_isShared_810_ == 0)
{
v___x_812_ = v___x_809_;
goto v_reusejp_811_;
}
else
{
lean_object* v_reuseFailAlloc_813_; 
v_reuseFailAlloc_813_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_813_, 0, v_a_807_);
v___x_812_ = v_reuseFailAlloc_813_;
goto v_reusejp_811_;
}
v_reusejp_811_:
{
return v___x_812_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consumeMessages___boxed(lean_object* v_output_815_, lean_object* v_a_816_){
_start:
{
lean_object* v_res_817_; 
v_res_817_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consumeMessages(v_output_815_);
lean_dec_ref(v_output_815_);
return v_res_817_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0(lean_object* v_as_821_, size_t v_sz_822_, size_t v_i_823_, lean_object* v_b_824_){
_start:
{
uint8_t v___x_826_; 
v___x_826_ = lean_usize_dec_lt(v_i_823_, v_sz_822_);
if (v___x_826_ == 0)
{
lean_object* v___x_827_; 
v___x_827_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_827_, 0, v_b_824_);
return v___x_827_;
}
else
{
lean_object* v_a_828_; lean_object* v_bytes_829_; lean_object* v___x_830_; 
v_a_828_ = lean_array_uget_borrowed(v_as_821_, v_i_823_);
v_bytes_829_ = lean_ctor_get(v_a_828_, 1);
v___x_830_ = lp_lean1090_Lean1090_Impl_decode(v_bytes_829_);
if (lean_obj_tag(v___x_830_) == 1)
{
lean_object* v_val_831_; lean_object* v___x_832_; size_t v___x_833_; size_t v___x_834_; 
v_val_831_ = lean_ctor_get(v___x_830_, 0);
lean_inc(v_val_831_);
lean_dec_ref_known(v___x_830_, 1);
v___x_832_ = lean_array_push(v_b_824_, v_val_831_);
v___x_833_ = ((size_t)1ULL);
v___x_834_ = lean_usize_add(v_i_823_, v___x_833_);
v_i_823_ = v___x_834_;
v_b_824_ = v___x_832_;
goto _start;
}
else
{
lean_object* v___x_836_; lean_object* v___x_837_; 
lean_dec(v___x_830_);
lean_dec_ref(v_b_824_);
v___x_836_ = ((lean_object*)(lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0___closed__1));
v___x_837_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_837_, 0, v___x_836_);
return v___x_837_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0___boxed(lean_object* v_as_838_, lean_object* v_sz_839_, lean_object* v_i_840_, lean_object* v_b_841_, lean_object* v___y_842_){
_start:
{
size_t v_sz_boxed_843_; size_t v_i_boxed_844_; lean_object* v_res_845_; 
v_sz_boxed_843_ = lean_unbox_usize(v_sz_839_);
lean_dec(v_sz_839_);
v_i_boxed_844_ = lean_unbox_usize(v_i_840_);
lean_dec(v_i_840_);
v_res_845_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0(v_as_838_, v_sz_boxed_843_, v_i_boxed_844_, v_b_841_);
lean_dec_ref(v_as_838_);
return v_res_845_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce(lean_object* v_inputs_846_){
_start:
{
lean_object* v___x_848_; lean_object* v_output_849_; lean_object* v___x_850_; size_t v_sz_851_; size_t v___x_852_; lean_object* v___x_853_; 
v___x_848_ = lean_array_get_size(v_inputs_846_);
v_output_849_ = lean_mk_empty_array_with_capacity(v___x_848_);
v___x_850_ = lean_io_mono_nanos_now();
v_sz_851_ = lean_array_size(v_inputs_846_);
v___x_852_ = ((size_t)0ULL);
v___x_853_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0(v_inputs_846_, v_sz_851_, v___x_852_, v_output_849_);
if (lean_obj_tag(v___x_853_) == 0)
{
lean_object* v_a_854_; lean_object* v___x_855_; lean_object* v___x_856_; 
v_a_854_ = lean_ctor_get(v___x_853_, 0);
lean_inc(v_a_854_);
lean_dec_ref_known(v___x_853_, 1);
v___x_855_ = lean_io_mono_nanos_now();
v___x_856_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consumeMessages(v_a_854_);
lean_dec(v_a_854_);
if (lean_obj_tag(v___x_856_) == 0)
{
lean_object* v___x_858_; uint8_t v_isShared_859_; uint8_t v_isSharedCheck_866_; 
v_isSharedCheck_866_ = !lean_is_exclusive(v___x_856_);
if (v_isSharedCheck_866_ == 0)
{
lean_object* v_unused_867_; 
v_unused_867_ = lean_ctor_get(v___x_856_, 0);
lean_dec(v_unused_867_);
v___x_858_ = v___x_856_;
v_isShared_859_ = v_isSharedCheck_866_;
goto v_resetjp_857_;
}
else
{
lean_dec(v___x_856_);
v___x_858_ = lean_box(0);
v_isShared_859_ = v_isSharedCheck_866_;
goto v_resetjp_857_;
}
v_resetjp_857_:
{
lean_object* v___x_860_; lean_object* v___x_861_; lean_object* v___x_862_; lean_object* v___x_864_; 
v___x_860_ = lean_nat_sub(v___x_855_, v___x_850_);
lean_dec(v___x_850_);
lean_dec(v___x_855_);
v___x_861_ = lean_unsigned_to_nat(0u);
v___x_862_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_862_, 0, v___x_860_);
lean_ctor_set(v___x_862_, 1, v___x_861_);
if (v_isShared_859_ == 0)
{
lean_ctor_set(v___x_858_, 0, v___x_862_);
v___x_864_ = v___x_858_;
goto v_reusejp_863_;
}
else
{
lean_object* v_reuseFailAlloc_865_; 
v_reuseFailAlloc_865_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_865_, 0, v___x_862_);
v___x_864_ = v_reuseFailAlloc_865_;
goto v_reusejp_863_;
}
v_reusejp_863_:
{
return v___x_864_;
}
}
}
else
{
lean_object* v_a_868_; lean_object* v___x_870_; uint8_t v_isShared_871_; uint8_t v_isSharedCheck_875_; 
lean_dec(v___x_855_);
lean_dec(v___x_850_);
v_a_868_ = lean_ctor_get(v___x_856_, 0);
v_isSharedCheck_875_ = !lean_is_exclusive(v___x_856_);
if (v_isSharedCheck_875_ == 0)
{
v___x_870_ = v___x_856_;
v_isShared_871_ = v_isSharedCheck_875_;
goto v_resetjp_869_;
}
else
{
lean_inc(v_a_868_);
lean_dec(v___x_856_);
v___x_870_ = lean_box(0);
v_isShared_871_ = v_isSharedCheck_875_;
goto v_resetjp_869_;
}
v_resetjp_869_:
{
lean_object* v___x_873_; 
if (v_isShared_871_ == 0)
{
v___x_873_ = v___x_870_;
goto v_reusejp_872_;
}
else
{
lean_object* v_reuseFailAlloc_874_; 
v_reuseFailAlloc_874_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_874_, 0, v_a_868_);
v___x_873_ = v_reuseFailAlloc_874_;
goto v_reusejp_872_;
}
v_reusejp_872_:
{
return v___x_873_;
}
}
}
}
else
{
lean_object* v_a_876_; lean_object* v___x_878_; uint8_t v_isShared_879_; uint8_t v_isSharedCheck_883_; 
lean_dec(v___x_850_);
v_a_876_ = lean_ctor_get(v___x_853_, 0);
v_isSharedCheck_883_ = !lean_is_exclusive(v___x_853_);
if (v_isSharedCheck_883_ == 0)
{
v___x_878_ = v___x_853_;
v_isShared_879_ = v_isSharedCheck_883_;
goto v_resetjp_877_;
}
else
{
lean_inc(v_a_876_);
lean_dec(v___x_853_);
v___x_878_ = lean_box(0);
v_isShared_879_ = v_isSharedCheck_883_;
goto v_resetjp_877_;
}
v_resetjp_877_:
{
lean_object* v___x_881_; 
if (v_isShared_879_ == 0)
{
v___x_881_ = v___x_878_;
goto v_reusejp_880_;
}
else
{
lean_object* v_reuseFailAlloc_882_; 
v_reuseFailAlloc_882_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_882_, 0, v_a_876_);
v___x_881_ = v_reuseFailAlloc_882_;
goto v_reusejp_880_;
}
v_reusejp_880_:
{
return v___x_881_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce___boxed(lean_object* v_inputs_884_, lean_object* v_a_885_){
_start:
{
lean_object* v_res_886_; 
v_res_886_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce(v_inputs_884_);
lean_dec_ref(v_inputs_884_);
return v_res_886_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce_spec__0(lean_object* v_geo_887_, lean_object* v_as_888_, size_t v_sz_889_, size_t v_i_890_, lean_object* v_b_891_){
_start:
{
uint8_t v___x_893_; 
v___x_893_ = lean_usize_dec_lt(v_i_890_, v_sz_889_);
if (v___x_893_ == 0)
{
lean_object* v___x_894_; 
lean_dec_ref(v_geo_887_);
v___x_894_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_894_, 0, v_b_891_);
return v___x_894_;
}
else
{
lean_object* v_a_895_; lean_object* v_timestamp_896_; lean_object* v_bytes_897_; lean_object* v___x_898_; 
v_a_895_ = lean_array_uget_borrowed(v_as_888_, v_i_890_);
v_timestamp_896_ = lean_ctor_get(v_a_895_, 0);
v_bytes_897_ = lean_ctor_get(v_a_895_, 1);
v___x_898_ = lp_lean1090_Lean1090_Impl_decode(v_bytes_897_);
if (lean_obj_tag(v___x_898_) == 1)
{
lean_object* v_val_899_; lean_object* v_fst_900_; lean_object* v_snd_901_; lean_object* v___x_903_; uint8_t v_isShared_904_; uint8_t v_isSharedCheck_922_; 
v_val_899_ = lean_ctor_get(v___x_898_, 0);
lean_inc(v_val_899_);
lean_dec_ref_known(v___x_898_, 1);
v_fst_900_ = lean_ctor_get(v_b_891_, 0);
v_snd_901_ = lean_ctor_get(v_b_891_, 1);
v_isSharedCheck_922_ = !lean_is_exclusive(v_b_891_);
if (v_isSharedCheck_922_ == 0)
{
v___x_903_ = v_b_891_;
v_isShared_904_ = v_isSharedCheck_922_;
goto v_resetjp_902_;
}
else
{
lean_inc(v_snd_901_);
lean_inc(v_fst_900_);
lean_dec(v_b_891_);
v___x_903_ = lean_box(0);
v_isShared_904_ = v_isSharedCheck_922_;
goto v_resetjp_902_;
}
v_resetjp_902_:
{
lean_object* v___x_905_; lean_object* v_fst_906_; lean_object* v_snd_907_; lean_object* v___x_909_; uint8_t v_isShared_910_; uint8_t v_isSharedCheck_921_; 
lean_inc(v_val_899_);
lean_inc_ref(v_timestamp_896_);
lean_inc_ref(v_geo_887_);
v___x_905_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance(v_geo_887_, v_snd_901_, v_timestamp_896_, v_val_899_);
v_fst_906_ = lean_ctor_get(v___x_905_, 0);
v_snd_907_ = lean_ctor_get(v___x_905_, 1);
v_isSharedCheck_921_ = !lean_is_exclusive(v___x_905_);
if (v_isSharedCheck_921_ == 0)
{
v___x_909_ = v___x_905_;
v_isShared_910_ = v_isSharedCheck_921_;
goto v_resetjp_908_;
}
else
{
lean_inc(v_snd_907_);
lean_inc(v_fst_906_);
lean_dec(v___x_905_);
v___x_909_ = lean_box(0);
v_isShared_910_ = v_isSharedCheck_921_;
goto v_resetjp_908_;
}
v_resetjp_908_:
{
lean_object* v___x_912_; 
if (v_isShared_904_ == 0)
{
lean_ctor_set(v___x_903_, 1, v_snd_907_);
lean_ctor_set(v___x_903_, 0, v_val_899_);
v___x_912_ = v___x_903_;
goto v_reusejp_911_;
}
else
{
lean_object* v_reuseFailAlloc_920_; 
v_reuseFailAlloc_920_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_920_, 0, v_val_899_);
lean_ctor_set(v_reuseFailAlloc_920_, 1, v_snd_907_);
v___x_912_ = v_reuseFailAlloc_920_;
goto v_reusejp_911_;
}
v_reusejp_911_:
{
lean_object* v___x_913_; lean_object* v___x_915_; 
v___x_913_ = lean_array_push(v_fst_900_, v___x_912_);
if (v_isShared_910_ == 0)
{
lean_ctor_set(v___x_909_, 1, v_fst_906_);
lean_ctor_set(v___x_909_, 0, v___x_913_);
v___x_915_ = v___x_909_;
goto v_reusejp_914_;
}
else
{
lean_object* v_reuseFailAlloc_919_; 
v_reuseFailAlloc_919_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_919_, 0, v___x_913_);
lean_ctor_set(v_reuseFailAlloc_919_, 1, v_fst_906_);
v___x_915_ = v_reuseFailAlloc_919_;
goto v_reusejp_914_;
}
v_reusejp_914_:
{
size_t v___x_916_; size_t v___x_917_; 
v___x_916_ = ((size_t)1ULL);
v___x_917_ = lean_usize_add(v_i_890_, v___x_916_);
v_i_890_ = v___x_917_;
v_b_891_ = v___x_915_;
goto _start;
}
}
}
}
}
else
{
lean_object* v___x_923_; lean_object* v___x_924_; 
lean_dec(v___x_898_);
lean_dec_ref(v_b_891_);
lean_dec_ref(v_geo_887_);
v___x_923_ = ((lean_object*)(lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0___closed__1));
v___x_924_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_924_, 0, v___x_923_);
return v___x_924_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce_spec__0___boxed(lean_object* v_geo_925_, lean_object* v_as_926_, lean_object* v_sz_927_, lean_object* v_i_928_, lean_object* v_b_929_, lean_object* v___y_930_){
_start:
{
size_t v_sz_boxed_931_; size_t v_i_boxed_932_; lean_object* v_res_933_; 
v_sz_boxed_931_ = lean_unbox_usize(v_sz_927_);
lean_dec(v_sz_927_);
v_i_boxed_932_ = lean_unbox_usize(v_i_928_);
lean_dec(v_i_928_);
v_res_933_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce_spec__0(v_geo_925_, v_as_926_, v_sz_boxed_931_, v_i_boxed_932_, v_b_929_);
lean_dec_ref(v_as_926_);
return v_res_933_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce(lean_object* v_inputs_937_, lean_object* v_geo_938_){
_start:
{
lean_object* v___x_940_; lean_object* v_output_941_; lean_object* v_state_942_; lean_object* v___x_943_; lean_object* v___x_944_; size_t v_sz_945_; size_t v___x_946_; lean_object* v___x_947_; 
v___x_940_ = lean_array_get_size(v_inputs_937_);
v_output_941_ = lean_mk_empty_array_with_capacity(v___x_940_);
v_state_942_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce___closed__0));
v___x_943_ = lean_io_mono_nanos_now();
v___x_944_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_944_, 0, v_output_941_);
lean_ctor_set(v___x_944_, 1, v_state_942_);
v_sz_945_ = lean_array_size(v_inputs_937_);
v___x_946_ = ((size_t)0ULL);
v___x_947_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce_spec__0(v_geo_938_, v_inputs_937_, v_sz_945_, v___x_946_, v___x_944_);
if (lean_obj_tag(v___x_947_) == 0)
{
lean_object* v_a_948_; lean_object* v_fst_949_; lean_object* v_snd_950_; lean_object* v___x_952_; uint8_t v_isShared_953_; uint8_t v_isSharedCheck_976_; 
v_a_948_ = lean_ctor_get(v___x_947_, 0);
lean_inc(v_a_948_);
lean_dec_ref_known(v___x_947_, 1);
v_fst_949_ = lean_ctor_get(v_a_948_, 0);
v_snd_950_ = lean_ctor_get(v_a_948_, 1);
v_isSharedCheck_976_ = !lean_is_exclusive(v_a_948_);
if (v_isSharedCheck_976_ == 0)
{
v___x_952_ = v_a_948_;
v_isShared_953_ = v_isSharedCheck_976_;
goto v_resetjp_951_;
}
else
{
lean_inc(v_snd_950_);
lean_inc(v_fst_949_);
lean_dec(v_a_948_);
v___x_952_ = lean_box(0);
v_isShared_953_ = v_isSharedCheck_976_;
goto v_resetjp_951_;
}
v_resetjp_951_:
{
lean_object* v___x_954_; lean_object* v___x_955_; 
v___x_954_ = lean_io_mono_nanos_now();
v___x_955_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_consume(v_fst_949_, v_snd_950_);
lean_dec(v_fst_949_);
if (lean_obj_tag(v___x_955_) == 0)
{
lean_object* v_a_956_; lean_object* v___x_958_; uint8_t v_isShared_959_; uint8_t v_isSharedCheck_967_; 
v_a_956_ = lean_ctor_get(v___x_955_, 0);
v_isSharedCheck_967_ = !lean_is_exclusive(v___x_955_);
if (v_isSharedCheck_967_ == 0)
{
v___x_958_ = v___x_955_;
v_isShared_959_ = v_isSharedCheck_967_;
goto v_resetjp_957_;
}
else
{
lean_inc(v_a_956_);
lean_dec(v___x_955_);
v___x_958_ = lean_box(0);
v_isShared_959_ = v_isSharedCheck_967_;
goto v_resetjp_957_;
}
v_resetjp_957_:
{
lean_object* v___x_960_; lean_object* v___x_962_; 
v___x_960_ = lean_nat_sub(v___x_954_, v___x_943_);
lean_dec(v___x_943_);
lean_dec(v___x_954_);
if (v_isShared_953_ == 0)
{
lean_ctor_set(v___x_952_, 1, v_a_956_);
lean_ctor_set(v___x_952_, 0, v___x_960_);
v___x_962_ = v___x_952_;
goto v_reusejp_961_;
}
else
{
lean_object* v_reuseFailAlloc_966_; 
v_reuseFailAlloc_966_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_966_, 0, v___x_960_);
lean_ctor_set(v_reuseFailAlloc_966_, 1, v_a_956_);
v___x_962_ = v_reuseFailAlloc_966_;
goto v_reusejp_961_;
}
v_reusejp_961_:
{
lean_object* v___x_964_; 
if (v_isShared_959_ == 0)
{
lean_ctor_set(v___x_958_, 0, v___x_962_);
v___x_964_ = v___x_958_;
goto v_reusejp_963_;
}
else
{
lean_object* v_reuseFailAlloc_965_; 
v_reuseFailAlloc_965_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_965_, 0, v___x_962_);
v___x_964_ = v_reuseFailAlloc_965_;
goto v_reusejp_963_;
}
v_reusejp_963_:
{
return v___x_964_;
}
}
}
}
else
{
lean_object* v_a_968_; lean_object* v___x_970_; uint8_t v_isShared_971_; uint8_t v_isSharedCheck_975_; 
lean_dec(v___x_954_);
lean_del_object(v___x_952_);
lean_dec(v___x_943_);
v_a_968_ = lean_ctor_get(v___x_955_, 0);
v_isSharedCheck_975_ = !lean_is_exclusive(v___x_955_);
if (v_isSharedCheck_975_ == 0)
{
v___x_970_ = v___x_955_;
v_isShared_971_ = v_isSharedCheck_975_;
goto v_resetjp_969_;
}
else
{
lean_inc(v_a_968_);
lean_dec(v___x_955_);
v___x_970_ = lean_box(0);
v_isShared_971_ = v_isSharedCheck_975_;
goto v_resetjp_969_;
}
v_resetjp_969_:
{
lean_object* v___x_973_; 
if (v_isShared_971_ == 0)
{
v___x_973_ = v___x_970_;
goto v_reusejp_972_;
}
else
{
lean_object* v_reuseFailAlloc_974_; 
v_reuseFailAlloc_974_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_974_, 0, v_a_968_);
v___x_973_ = v_reuseFailAlloc_974_;
goto v_reusejp_972_;
}
v_reusejp_972_:
{
return v___x_973_;
}
}
}
}
}
else
{
lean_object* v_a_977_; lean_object* v___x_979_; uint8_t v_isShared_980_; uint8_t v_isSharedCheck_984_; 
lean_dec(v___x_943_);
v_a_977_ = lean_ctor_get(v___x_947_, 0);
v_isSharedCheck_984_ = !lean_is_exclusive(v___x_947_);
if (v_isSharedCheck_984_ == 0)
{
v___x_979_ = v___x_947_;
v_isShared_980_ = v_isSharedCheck_984_;
goto v_resetjp_978_;
}
else
{
lean_inc(v_a_977_);
lean_dec(v___x_947_);
v___x_979_ = lean_box(0);
v_isShared_980_ = v_isSharedCheck_984_;
goto v_resetjp_978_;
}
v_resetjp_978_:
{
lean_object* v___x_982_; 
if (v_isShared_980_ == 0)
{
v___x_982_ = v___x_979_;
goto v_reusejp_981_;
}
else
{
lean_object* v_reuseFailAlloc_983_; 
v_reuseFailAlloc_983_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_983_, 0, v_a_977_);
v___x_982_ = v_reuseFailAlloc_983_;
goto v_reusejp_981_;
}
v_reusejp_981_:
{
return v___x_982_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce___boxed(lean_object* v_inputs_985_, lean_object* v_geo_986_, lean_object* v_a_987_){
_start:
{
lean_object* v_res_988_; 
v_res_988_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce(v_inputs_985_, v_geo_986_);
lean_dec_ref(v_inputs_985_);
return v_res_988_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce(lean_object* v_inputs_989_, lean_object* v_geo_990_, uint8_t v_cpr_991_){
_start:
{
if (v_cpr_991_ == 0)
{
lean_object* v___x_993_; 
lean_dec_ref(v_geo_990_);
v___x_993_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce(v_inputs_989_);
return v___x_993_;
}
else
{
lean_object* v___x_994_; 
v___x_994_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce(v_inputs_989_, v_geo_990_);
return v___x_994_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce___boxed(lean_object* v_inputs_995_, lean_object* v_geo_996_, lean_object* v_cpr_997_, lean_object* v_a_998_){
_start:
{
uint8_t v_cpr_boxed_999_; lean_object* v_res_1000_; 
v_cpr_boxed_999_ = lean_unbox(v_cpr_997_);
v_res_1000_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce(v_inputs_995_, v_geo_996_, v_cpr_boxed_999_);
lean_dec_ref(v_inputs_995_);
return v_res_1000_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0_spec__0(lean_object* v_s_1001_){
_start:
{
lean_object* v___x_1003_; lean_object* v_putStr_1004_; lean_object* v___x_1005_; 
v___x_1003_ = lean_get_stdout();
v_putStr_1004_ = lean_ctor_get(v___x_1003_, 4);
lean_inc_ref(v_putStr_1004_);
lean_dec_ref(v___x_1003_);
v___x_1005_ = lean_apply_2(v_putStr_1004_, v_s_1001_, lean_box(0));
return v___x_1005_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0_spec__0___boxed(lean_object* v_s_1006_, lean_object* v_a_1007_){
_start:
{
lean_object* v_res_1008_; 
v_res_1008_ = lp_lean1090_IO_print___at___00IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0_spec__0(v_s_1006_);
return v_res_1008_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(lean_object* v_s_1009_){
_start:
{
uint32_t v___x_1011_; lean_object* v___x_1012_; lean_object* v___x_1013_; 
v___x_1011_ = 10;
v___x_1012_ = lean_string_push(v_s_1009_, v___x_1011_);
v___x_1013_ = lp_lean1090_IO_print___at___00IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0_spec__0(v___x_1012_);
return v___x_1013_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0___boxed(lean_object* v_s_1014_, lean_object* v_a_1015_){
_start:
{
lean_object* v_res_1016_; 
v_res_1016_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v_s_1014_);
return v_res_1016_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg(lean_object* v_val_1023_, lean_object* v_inputs_1024_, lean_object* v_geo_1025_, uint8_t v_cpr_1026_){
_start:
{
lean_object* v_getLine_1028_; lean_object* v___x_1029_; lean_object* v___x_1030_; 
v_getLine_1028_ = lean_ctor_get(v_val_1023_, 3);
v___x_1029_ = lean_box(0);
lean_inc_ref(v_getLine_1028_);
v___x_1030_ = lean_apply_1(v_getLine_1028_, lean_box(0));
if (lean_obj_tag(v___x_1030_) == 0)
{
lean_object* v_a_1031_; lean_object* v___x_1033_; uint8_t v_isShared_1034_; uint8_t v_isSharedCheck_1077_; 
v_a_1031_ = lean_ctor_get(v___x_1030_, 0);
v_isSharedCheck_1077_ = !lean_is_exclusive(v___x_1030_);
if (v_isSharedCheck_1077_ == 0)
{
v___x_1033_ = v___x_1030_;
v_isShared_1034_ = v_isSharedCheck_1077_;
goto v_resetjp_1032_;
}
else
{
lean_inc(v_a_1031_);
lean_dec(v___x_1030_);
v___x_1033_ = lean_box(0);
v_isShared_1034_ = v_isSharedCheck_1077_;
goto v_resetjp_1032_;
}
v_resetjp_1032_:
{
lean_object* v___x_1035_; lean_object* v___x_1036_; uint8_t v___x_1037_; 
v___x_1035_ = lean_string_utf8_byte_size(v_a_1031_);
v___x_1036_ = lean_unsigned_to_nat(0u);
v___x_1037_ = lean_nat_dec_eq(v___x_1035_, v___x_1036_);
if (v___x_1037_ == 0)
{
lean_object* v___x_1038_; lean_object* v___x_1039_; lean_object* v___x_1040_; lean_object* v___x_1041_; uint8_t v___x_1042_; 
v___x_1038_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1038_, 0, v_a_1031_);
lean_ctor_set(v___x_1038_, 1, v___x_1036_);
lean_ctor_set(v___x_1038_, 2, v___x_1035_);
v___x_1039_ = l_String_Slice_trimAscii(v___x_1038_);
v___x_1040_ = l_String_Slice_toString(v___x_1039_);
lean_dec_ref(v___x_1039_);
v___x_1041_ = ((lean_object*)(lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__0));
v___x_1042_ = lean_string_dec_eq(v___x_1040_, v___x_1041_);
if (v___x_1042_ == 0)
{
lean_object* v___x_1043_; uint8_t v___x_1044_; 
v___x_1043_ = ((lean_object*)(lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__1));
v___x_1044_ = lean_string_dec_eq(v___x_1040_, v___x_1043_);
lean_dec_ref(v___x_1040_);
if (v___x_1044_ == 0)
{
lean_object* v___x_1045_; lean_object* v___x_1047_; 
lean_dec_ref(v_geo_1025_);
lean_dec_ref(v_val_1023_);
v___x_1045_ = ((lean_object*)(lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__3));
if (v_isShared_1034_ == 0)
{
lean_ctor_set_tag(v___x_1033_, 1);
lean_ctor_set(v___x_1033_, 0, v___x_1045_);
v___x_1047_ = v___x_1033_;
goto v_reusejp_1046_;
}
else
{
lean_object* v_reuseFailAlloc_1048_; 
v_reuseFailAlloc_1048_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1048_, 0, v___x_1045_);
v___x_1047_ = v_reuseFailAlloc_1048_;
goto v_reusejp_1046_;
}
v_reusejp_1046_:
{
return v___x_1047_;
}
}
else
{
lean_object* v___x_1049_; 
lean_del_object(v___x_1033_);
lean_inc_ref(v_geo_1025_);
v___x_1049_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce(v_inputs_1024_, v_geo_1025_, v_cpr_1026_);
if (lean_obj_tag(v___x_1049_) == 0)
{
lean_object* v_a_1050_; lean_object* v_fst_1051_; lean_object* v_snd_1052_; lean_object* v___x_1053_; lean_object* v___x_1054_; lean_object* v___x_1055_; lean_object* v___x_1056_; lean_object* v___x_1057_; lean_object* v___x_1058_; 
v_a_1050_ = lean_ctor_get(v___x_1049_, 0);
lean_inc(v_a_1050_);
lean_dec_ref_known(v___x_1049_, 1);
v_fst_1051_ = lean_ctor_get(v_a_1050_, 0);
lean_inc(v_fst_1051_);
v_snd_1052_ = lean_ctor_get(v_a_1050_, 1);
lean_inc(v_snd_1052_);
lean_dec(v_a_1050_);
v___x_1053_ = l_Nat_reprFast(v_fst_1051_);
v___x_1054_ = ((lean_object*)(lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__4));
v___x_1055_ = lean_string_append(v___x_1053_, v___x_1054_);
v___x_1056_ = l_Nat_reprFast(v_snd_1052_);
v___x_1057_ = lean_string_append(v___x_1055_, v___x_1056_);
lean_dec_ref(v___x_1056_);
v___x_1058_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_1057_);
if (lean_obj_tag(v___x_1058_) == 0)
{
lean_object* v___x_1059_; lean_object* v_flush_1060_; lean_object* v___x_1061_; 
lean_dec_ref_known(v___x_1058_, 1);
v___x_1059_ = lean_get_stdout();
v_flush_1060_ = lean_ctor_get(v___x_1059_, 0);
lean_inc_ref(v_flush_1060_);
lean_dec_ref(v___x_1059_);
v___x_1061_ = lean_apply_1(v_flush_1060_, lean_box(0));
if (lean_obj_tag(v___x_1061_) == 0)
{
lean_dec_ref_known(v___x_1061_, 1);
goto _start;
}
else
{
lean_dec_ref(v_geo_1025_);
lean_dec_ref(v_val_1023_);
return v___x_1061_;
}
}
else
{
lean_dec_ref(v_geo_1025_);
lean_dec_ref(v_val_1023_);
return v___x_1058_;
}
}
else
{
lean_object* v_a_1063_; lean_object* v___x_1065_; uint8_t v_isShared_1066_; uint8_t v_isSharedCheck_1070_; 
lean_dec_ref(v_geo_1025_);
lean_dec_ref(v_val_1023_);
v_a_1063_ = lean_ctor_get(v___x_1049_, 0);
v_isSharedCheck_1070_ = !lean_is_exclusive(v___x_1049_);
if (v_isSharedCheck_1070_ == 0)
{
v___x_1065_ = v___x_1049_;
v_isShared_1066_ = v_isSharedCheck_1070_;
goto v_resetjp_1064_;
}
else
{
lean_inc(v_a_1063_);
lean_dec(v___x_1049_);
v___x_1065_ = lean_box(0);
v_isShared_1066_ = v_isSharedCheck_1070_;
goto v_resetjp_1064_;
}
v_resetjp_1064_:
{
lean_object* v___x_1068_; 
if (v_isShared_1066_ == 0)
{
v___x_1068_ = v___x_1065_;
goto v_reusejp_1067_;
}
else
{
lean_object* v_reuseFailAlloc_1069_; 
v_reuseFailAlloc_1069_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1069_, 0, v_a_1063_);
v___x_1068_ = v_reuseFailAlloc_1069_;
goto v_reusejp_1067_;
}
v_reusejp_1067_:
{
return v___x_1068_;
}
}
}
}
}
else
{
lean_object* v___x_1072_; 
lean_dec_ref(v___x_1040_);
lean_dec_ref(v_geo_1025_);
lean_dec_ref(v_val_1023_);
if (v_isShared_1034_ == 0)
{
lean_ctor_set(v___x_1033_, 0, v___x_1029_);
v___x_1072_ = v___x_1033_;
goto v_reusejp_1071_;
}
else
{
lean_object* v_reuseFailAlloc_1073_; 
v_reuseFailAlloc_1073_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1073_, 0, v___x_1029_);
v___x_1072_ = v_reuseFailAlloc_1073_;
goto v_reusejp_1071_;
}
v_reusejp_1071_:
{
return v___x_1072_;
}
}
}
else
{
lean_object* v___x_1075_; 
lean_dec(v_a_1031_);
lean_dec_ref(v_geo_1025_);
lean_dec_ref(v_val_1023_);
if (v_isShared_1034_ == 0)
{
lean_ctor_set(v___x_1033_, 0, v___x_1029_);
v___x_1075_ = v___x_1033_;
goto v_reusejp_1074_;
}
else
{
lean_object* v_reuseFailAlloc_1076_; 
v_reuseFailAlloc_1076_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1076_, 0, v___x_1029_);
v___x_1075_ = v_reuseFailAlloc_1076_;
goto v_reusejp_1074_;
}
v_reusejp_1074_:
{
return v___x_1075_;
}
}
}
}
else
{
lean_object* v_a_1078_; lean_object* v___x_1080_; uint8_t v_isShared_1081_; uint8_t v_isSharedCheck_1085_; 
lean_dec_ref(v_geo_1025_);
lean_dec_ref(v_val_1023_);
v_a_1078_ = lean_ctor_get(v___x_1030_, 0);
v_isSharedCheck_1085_ = !lean_is_exclusive(v___x_1030_);
if (v_isSharedCheck_1085_ == 0)
{
v___x_1080_ = v___x_1030_;
v_isShared_1081_ = v_isSharedCheck_1085_;
goto v_resetjp_1079_;
}
else
{
lean_inc(v_a_1078_);
lean_dec(v___x_1030_);
v___x_1080_ = lean_box(0);
v_isShared_1081_ = v_isSharedCheck_1085_;
goto v_resetjp_1079_;
}
v_resetjp_1079_:
{
lean_object* v___x_1083_; 
if (v_isShared_1081_ == 0)
{
v___x_1083_ = v___x_1080_;
goto v_reusejp_1082_;
}
else
{
lean_object* v_reuseFailAlloc_1084_; 
v_reuseFailAlloc_1084_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1084_, 0, v_a_1078_);
v___x_1083_ = v_reuseFailAlloc_1084_;
goto v_reusejp_1082_;
}
v_reusejp_1082_:
{
return v___x_1083_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___boxed(lean_object* v_val_1086_, lean_object* v_inputs_1087_, lean_object* v_geo_1088_, lean_object* v_cpr_1089_, lean_object* v___y_1090_){
_start:
{
uint8_t v_cpr_boxed_1091_; lean_object* v_res_1092_; 
v_cpr_boxed_1091_ = lean_unbox(v_cpr_1089_);
v_res_1092_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg(v_val_1086_, v_inputs_1087_, v_geo_1088_, v_cpr_boxed_1091_);
lean_dec_ref(v_inputs_1087_);
return v_res_1092_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker(lean_object* v_inputs_1094_, lean_object* v_geo_1095_, uint8_t v_cpr_1096_){
_start:
{
lean_object* v___x_1098_; lean_object* v___x_1099_; lean_object* v___x_1100_; lean_object* v___x_1101_; lean_object* v___x_1102_; 
v___x_1098_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker___closed__0));
v___x_1099_ = lean_array_get_size(v_inputs_1094_);
v___x_1100_ = l_Nat_reprFast(v___x_1099_);
v___x_1101_ = lean_string_append(v___x_1098_, v___x_1100_);
lean_dec_ref(v___x_1100_);
v___x_1102_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_1101_);
if (lean_obj_tag(v___x_1102_) == 0)
{
lean_object* v___x_1103_; lean_object* v_flush_1104_; lean_object* v___x_1105_; 
lean_dec_ref_known(v___x_1102_, 1);
v___x_1103_ = lean_get_stdout();
v_flush_1104_ = lean_ctor_get(v___x_1103_, 0);
lean_inc_ref(v_flush_1104_);
lean_dec_ref(v___x_1103_);
v___x_1105_ = lean_apply_1(v_flush_1104_, lean_box(0));
if (lean_obj_tag(v___x_1105_) == 0)
{
lean_object* v___x_1106_; lean_object* v___x_1107_; lean_object* v___x_1108_; 
lean_dec_ref_known(v___x_1105_, 1);
v___x_1106_ = lean_get_stdin();
v___x_1107_ = lean_box(0);
v___x_1108_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg(v___x_1106_, v_inputs_1094_, v_geo_1095_, v_cpr_1096_);
if (lean_obj_tag(v___x_1108_) == 0)
{
lean_object* v___x_1110_; uint8_t v_isShared_1111_; uint8_t v_isSharedCheck_1115_; 
v_isSharedCheck_1115_ = !lean_is_exclusive(v___x_1108_);
if (v_isSharedCheck_1115_ == 0)
{
lean_object* v_unused_1116_; 
v_unused_1116_ = lean_ctor_get(v___x_1108_, 0);
lean_dec(v_unused_1116_);
v___x_1110_ = v___x_1108_;
v_isShared_1111_ = v_isSharedCheck_1115_;
goto v_resetjp_1109_;
}
else
{
lean_dec(v___x_1108_);
v___x_1110_ = lean_box(0);
v_isShared_1111_ = v_isSharedCheck_1115_;
goto v_resetjp_1109_;
}
v_resetjp_1109_:
{
lean_object* v___x_1113_; 
if (v_isShared_1111_ == 0)
{
lean_ctor_set(v___x_1110_, 0, v___x_1107_);
v___x_1113_ = v___x_1110_;
goto v_reusejp_1112_;
}
else
{
lean_object* v_reuseFailAlloc_1114_; 
v_reuseFailAlloc_1114_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1114_, 0, v___x_1107_);
v___x_1113_ = v_reuseFailAlloc_1114_;
goto v_reusejp_1112_;
}
v_reusejp_1112_:
{
return v___x_1113_;
}
}
}
else
{
return v___x_1108_;
}
}
else
{
lean_dec_ref(v_geo_1095_);
return v___x_1105_;
}
}
else
{
lean_dec_ref(v_geo_1095_);
return v___x_1102_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker___boxed(lean_object* v_inputs_1117_, lean_object* v_geo_1118_, lean_object* v_cpr_1119_, lean_object* v_a_1120_){
_start:
{
uint8_t v_cpr_boxed_1121_; lean_object* v_res_1122_; 
v_cpr_boxed_1121_ = lean_unbox(v_cpr_1119_);
v_res_1122_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker(v_inputs_1117_, v_geo_1118_, v_cpr_boxed_1121_);
lean_dec_ref(v_inputs_1117_);
return v_res_1122_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1(lean_object* v_val_1123_, lean_object* v_inputs_1124_, lean_object* v_geo_1125_, uint8_t v_cpr_1126_, lean_object* v_inst_1127_, lean_object* v_a_1128_){
_start:
{
lean_object* v___x_1130_; 
v___x_1130_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg(v_val_1123_, v_inputs_1124_, v_geo_1125_, v_cpr_1126_);
return v___x_1130_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___boxed(lean_object* v_val_1131_, lean_object* v_inputs_1132_, lean_object* v_geo_1133_, lean_object* v_cpr_1134_, lean_object* v_inst_1135_, lean_object* v_a_1136_, lean_object* v___y_1137_){
_start:
{
uint8_t v_cpr_boxed_1138_; lean_object* v_res_1139_; 
v_cpr_boxed_1138_ = lean_unbox(v_cpr_1134_);
v_res_1139_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1(v_val_1131_, v_inputs_1132_, v_geo_1133_, v_cpr_boxed_1138_, v_inst_1135_, v_a_1136_);
lean_dec_ref(v_inputs_1132_);
return v_res_1139_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(lean_object* v_value_1140_){
_start:
{
double v___x_1141_; uint64_t v___x_1142_; lean_object* v___x_1143_; 
v___x_1141_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_value_1140_);
v___x_1142_ = lean_float_to_bits(v___x_1141_);
v___x_1143_ = lean_uint64_to_nat(v___x_1142_);
return v___x_1143_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0_spec__1(size_t v_sz_1144_, size_t v_i_1145_, lean_object* v_bs_1146_){
_start:
{
uint8_t v___x_1147_; 
v___x_1147_ = lean_usize_dec_lt(v_i_1145_, v_sz_1144_);
if (v___x_1147_ == 0)
{
return v_bs_1146_;
}
else
{
lean_object* v_v_1148_; lean_object* v___x_1149_; lean_object* v_bs_x27_1150_; lean_object* v___x_1151_; lean_object* v___x_1152_; size_t v___x_1153_; size_t v___x_1154_; lean_object* v___x_1155_; 
v_v_1148_ = lean_array_uget(v_bs_1146_, v_i_1145_);
v___x_1149_ = lean_unsigned_to_nat(0u);
v_bs_x27_1150_ = lean_array_uset(v_bs_1146_, v_i_1145_, v___x_1149_);
v___x_1151_ = l_Lean_JsonNumber_fromNat(v_v_1148_);
v___x_1152_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1152_, 0, v___x_1151_);
v___x_1153_ = ((size_t)1ULL);
v___x_1154_ = lean_usize_add(v_i_1145_, v___x_1153_);
v___x_1155_ = lean_array_uset(v_bs_x27_1150_, v_i_1145_, v___x_1152_);
v_i_1145_ = v___x_1154_;
v_bs_1146_ = v___x_1155_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0_spec__1___boxed(lean_object* v_sz_1157_, lean_object* v_i_1158_, lean_object* v_bs_1159_){
_start:
{
size_t v_sz_boxed_1160_; size_t v_i_boxed_1161_; lean_object* v_res_1162_; 
v_sz_boxed_1160_ = lean_unbox_usize(v_sz_1157_);
lean_dec(v_sz_1157_);
v_i_boxed_1161_ = lean_unbox_usize(v_i_1158_);
lean_dec(v_i_1158_);
v_res_1162_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0_spec__1(v_sz_boxed_1160_, v_i_boxed_1161_, v_bs_1159_);
return v_res_1162_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0(lean_object* v_a_1163_){
_start:
{
size_t v_sz_1164_; size_t v___x_1165_; lean_object* v___x_1166_; lean_object* v___x_1167_; 
v_sz_1164_ = lean_array_size(v_a_1163_);
v___x_1165_ = ((size_t)0ULL);
v___x_1166_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0_spec__1(v_sz_1164_, v___x_1165_, v_a_1163_);
v___x_1167_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_1167_, 0, v___x_1166_);
return v___x_1167_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0(lean_object* v_a_1168_){
_start:
{
lean_object* v___x_1169_; lean_object* v___x_1170_; 
v___x_1169_ = lean_array_mk(v_a_1168_);
v___x_1170_ = lp_lean1090_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0_spec__0(v___x_1169_);
return v___x_1170_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson(lean_object* v_p_1171_){
_start:
{
if (lean_obj_tag(v_p_1171_) == 0)
{
lean_object* v___x_1172_; 
v___x_1172_ = lean_box(0);
return v___x_1172_;
}
else
{
lean_object* v_val_1173_; lean_object* v_lat_1174_; lean_object* v_lon_1175_; lean_object* v___x_1177_; uint8_t v_isShared_1178_; uint8_t v_isSharedCheck_1187_; 
v_val_1173_ = lean_ctor_get(v_p_1171_, 0);
lean_inc(v_val_1173_);
lean_dec_ref_known(v_p_1171_, 1);
v_lat_1174_ = lean_ctor_get(v_val_1173_, 0);
v_lon_1175_ = lean_ctor_get(v_val_1173_, 1);
v_isSharedCheck_1187_ = !lean_is_exclusive(v_val_1173_);
if (v_isSharedCheck_1187_ == 0)
{
v___x_1177_ = v_val_1173_;
v_isShared_1178_ = v_isSharedCheck_1187_;
goto v_resetjp_1176_;
}
else
{
lean_inc(v_lon_1175_);
lean_inc(v_lat_1174_);
lean_dec(v_val_1173_);
v___x_1177_ = lean_box(0);
v_isShared_1178_ = v_isSharedCheck_1187_;
goto v_resetjp_1176_;
}
v_resetjp_1176_:
{
lean_object* v___x_1179_; lean_object* v___x_1180_; lean_object* v___x_1181_; lean_object* v___x_1183_; 
v___x_1179_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(v_lat_1174_);
v___x_1180_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(v_lon_1175_);
v___x_1181_ = lean_box(0);
if (v_isShared_1178_ == 0)
{
lean_ctor_set_tag(v___x_1177_, 1);
lean_ctor_set(v___x_1177_, 1, v___x_1181_);
lean_ctor_set(v___x_1177_, 0, v___x_1180_);
v___x_1183_ = v___x_1177_;
goto v_reusejp_1182_;
}
else
{
lean_object* v_reuseFailAlloc_1186_; 
v_reuseFailAlloc_1186_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1186_, 0, v___x_1180_);
lean_ctor_set(v_reuseFailAlloc_1186_, 1, v___x_1181_);
v___x_1183_ = v_reuseFailAlloc_1186_;
goto v_reusejp_1182_;
}
v_reusejp_1182_:
{
lean_object* v___x_1184_; lean_object* v___x_1185_; 
v___x_1184_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1184_, 0, v___x_1179_);
lean_ctor_set(v___x_1184_, 1, v___x_1183_);
v___x_1185_ = lp_lean1090_Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0(v___x_1184_);
return v___x_1185_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean_Option_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__0(lean_object* v_x_1188_){
_start:
{
if (lean_obj_tag(v_x_1188_) == 0)
{
lean_object* v___x_1189_; 
v___x_1189_ = lean_box(0);
return v___x_1189_;
}
else
{
lean_object* v_val_1190_; lean_object* v___x_1192_; uint8_t v_isShared_1193_; uint8_t v_isSharedCheck_1198_; 
v_val_1190_ = lean_ctor_get(v_x_1188_, 0);
v_isSharedCheck_1198_ = !lean_is_exclusive(v_x_1188_);
if (v_isSharedCheck_1198_ == 0)
{
v___x_1192_ = v_x_1188_;
v_isShared_1193_ = v_isSharedCheck_1198_;
goto v_resetjp_1191_;
}
else
{
lean_inc(v_val_1190_);
lean_dec(v_x_1188_);
v___x_1192_ = lean_box(0);
v_isShared_1193_ = v_isSharedCheck_1198_;
goto v_resetjp_1191_;
}
v_resetjp_1191_:
{
lean_object* v___x_1194_; lean_object* v___x_1196_; 
v___x_1194_ = l_Lean_JsonNumber_fromInt(v_val_1190_);
if (v_isShared_1193_ == 0)
{
lean_ctor_set_tag(v___x_1192_, 2);
lean_ctor_set(v___x_1192_, 0, v___x_1194_);
v___x_1196_ = v___x_1192_;
goto v_reusejp_1195_;
}
else
{
lean_object* v_reuseFailAlloc_1197_; 
v_reuseFailAlloc_1197_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1197_, 0, v___x_1194_);
v___x_1196_ = v_reuseFailAlloc_1197_;
goto v_reusejp_1195_;
}
v_reusejp_1195_:
{
return v___x_1196_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean_Option_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__1(lean_object* v_x_1199_){
_start:
{
if (lean_obj_tag(v_x_1199_) == 0)
{
lean_object* v___x_1200_; 
v___x_1200_ = lean_box(0);
return v___x_1200_;
}
else
{
lean_object* v_val_1201_; lean_object* v___x_1203_; uint8_t v_isShared_1204_; uint8_t v_isSharedCheck_1208_; 
v_val_1201_ = lean_ctor_get(v_x_1199_, 0);
v_isSharedCheck_1208_ = !lean_is_exclusive(v_x_1199_);
if (v_isSharedCheck_1208_ == 0)
{
v___x_1203_ = v_x_1199_;
v_isShared_1204_ = v_isSharedCheck_1208_;
goto v_resetjp_1202_;
}
else
{
lean_inc(v_val_1201_);
lean_dec(v_x_1199_);
v___x_1203_ = lean_box(0);
v_isShared_1204_ = v_isSharedCheck_1208_;
goto v_resetjp_1202_;
}
v_resetjp_1202_:
{
lean_object* v___x_1206_; 
if (v_isShared_1204_ == 0)
{
lean_ctor_set_tag(v___x_1203_, 3);
v___x_1206_ = v___x_1203_;
goto v_reusejp_1205_;
}
else
{
lean_object* v_reuseFailAlloc_1207_; 
v_reuseFailAlloc_1207_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1207_, 0, v_val_1201_);
v___x_1206_ = v_reuseFailAlloc_1207_;
goto v_reusejp_1205_;
}
v_reusejp_1205_:
{
return v___x_1206_;
}
}
}
}
}
LEAN_EXPORT uint8_t lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___lam__0(lean_object* v_a_1209_, lean_object* v_b_1210_){
_start:
{
lean_object* v_fst_1211_; lean_object* v_fst_1212_; uint8_t v___x_1213_; 
v_fst_1211_ = lean_ctor_get(v_a_1209_, 0);
v_fst_1212_ = lean_ctor_get(v_b_1210_, 0);
v___x_1213_ = lean_nat_dec_le(v_fst_1211_, v_fst_1212_);
return v___x_1213_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___lam__0___boxed(lean_object* v_a_1214_, lean_object* v_b_1215_){
_start:
{
uint8_t v_res_1216_; lean_object* v_r_1217_; 
v_res_1216_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___lam__0(v_a_1214_, v_b_1215_);
lean_dec_ref(v_b_1215_);
lean_dec_ref(v_a_1214_);
v_r_1217_ = lean_box(v_res_1216_);
return v_r_1217_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3(lean_object* v_a_1223_, lean_object* v_a_1224_){
_start:
{
if (lean_obj_tag(v_a_1223_) == 0)
{
lean_object* v___x_1225_; 
v___x_1225_ = l_List_reverse___redArg(v_a_1224_);
return v___x_1225_;
}
else
{
lean_object* v_head_1226_; lean_object* v_snd_1227_; lean_object* v_tail_1228_; lean_object* v___x_1230_; uint8_t v_isShared_1231_; uint8_t v_isSharedCheck_1271_; 
v_head_1226_ = lean_ctor_get(v_a_1223_, 0);
lean_inc(v_head_1226_);
v_snd_1227_ = lean_ctor_get(v_head_1226_, 1);
lean_inc(v_snd_1227_);
v_tail_1228_ = lean_ctor_get(v_a_1223_, 1);
v_isSharedCheck_1271_ = !lean_is_exclusive(v_a_1223_);
if (v_isSharedCheck_1271_ == 0)
{
lean_object* v_unused_1272_; 
v_unused_1272_ = lean_ctor_get(v_a_1223_, 0);
lean_dec(v_unused_1272_);
v___x_1230_ = v_a_1223_;
v_isShared_1231_ = v_isSharedCheck_1271_;
goto v_resetjp_1229_;
}
else
{
lean_inc(v_tail_1228_);
lean_dec(v_a_1223_);
v___x_1230_ = lean_box(0);
v_isShared_1231_ = v_isSharedCheck_1271_;
goto v_resetjp_1229_;
}
v_resetjp_1229_:
{
lean_object* v_fst_1232_; lean_object* v___x_1234_; uint8_t v_isShared_1235_; uint8_t v_isSharedCheck_1269_; 
v_fst_1232_ = lean_ctor_get(v_head_1226_, 0);
v_isSharedCheck_1269_ = !lean_is_exclusive(v_head_1226_);
if (v_isSharedCheck_1269_ == 0)
{
lean_object* v_unused_1270_; 
v_unused_1270_ = lean_ctor_get(v_head_1226_, 1);
lean_dec(v_unused_1270_);
v___x_1234_ = v_head_1226_;
v_isShared_1235_ = v_isSharedCheck_1269_;
goto v_resetjp_1233_;
}
else
{
lean_inc(v_fst_1232_);
lean_dec(v_head_1226_);
v___x_1234_ = lean_box(0);
v_isShared_1235_ = v_isSharedCheck_1269_;
goto v_resetjp_1233_;
}
v_resetjp_1233_:
{
lean_object* v_position_1236_; lean_object* v_lastAltitude_1237_; lean_object* v_airport_1238_; lean_object* v_seenBDS_1239_; lean_object* v___x_1240_; lean_object* v___x_1241_; lean_object* v___x_1242_; lean_object* v___x_1244_; 
v_position_1236_ = lean_ctor_get(v_snd_1227_, 1);
lean_inc(v_position_1236_);
v_lastAltitude_1237_ = lean_ctor_get(v_snd_1227_, 2);
lean_inc(v_lastAltitude_1237_);
v_airport_1238_ = lean_ctor_get(v_snd_1227_, 3);
lean_inc(v_airport_1238_);
v_seenBDS_1239_ = lean_ctor_get(v_snd_1227_, 4);
lean_inc(v_seenBDS_1239_);
lean_dec(v_snd_1227_);
v___x_1240_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__0));
v___x_1241_ = l_Lean_JsonNumber_fromNat(v_fst_1232_);
v___x_1242_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1242_, 0, v___x_1241_);
if (v_isShared_1235_ == 0)
{
lean_ctor_set(v___x_1234_, 1, v___x_1242_);
lean_ctor_set(v___x_1234_, 0, v___x_1240_);
v___x_1244_ = v___x_1234_;
goto v_reusejp_1243_;
}
else
{
lean_object* v_reuseFailAlloc_1268_; 
v_reuseFailAlloc_1268_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1268_, 0, v___x_1240_);
lean_ctor_set(v_reuseFailAlloc_1268_, 1, v___x_1242_);
v___x_1244_ = v_reuseFailAlloc_1268_;
goto v_reusejp_1243_;
}
v_reusejp_1243_:
{
lean_object* v___x_1245_; lean_object* v___x_1246_; lean_object* v___x_1247_; lean_object* v___x_1248_; lean_object* v___x_1249_; lean_object* v___x_1250_; lean_object* v___x_1251_; lean_object* v___x_1252_; lean_object* v___x_1253_; lean_object* v___x_1254_; lean_object* v___x_1255_; lean_object* v___x_1256_; lean_object* v___x_1257_; lean_object* v___x_1259_; 
v___x_1245_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__1));
v___x_1246_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson(v_position_1236_);
v___x_1247_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1247_, 0, v___x_1245_);
lean_ctor_set(v___x_1247_, 1, v___x_1246_);
v___x_1248_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__2));
v___x_1249_ = lp_lean1090_Lean_Option_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__0(v_lastAltitude_1237_);
v___x_1250_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1250_, 0, v___x_1248_);
lean_ctor_set(v___x_1250_, 1, v___x_1249_);
v___x_1251_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__3));
v___x_1252_ = lp_lean1090_Lean_Option_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__1(v_airport_1238_);
v___x_1253_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1253_, 0, v___x_1251_);
lean_ctor_set(v___x_1253_, 1, v___x_1252_);
v___x_1254_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__4));
v___x_1255_ = lp_lean1090_Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson_spec__0(v_seenBDS_1239_);
v___x_1256_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1256_, 0, v___x_1254_);
lean_ctor_set(v___x_1256_, 1, v___x_1255_);
v___x_1257_ = lean_box(0);
if (v_isShared_1231_ == 0)
{
lean_ctor_set(v___x_1230_, 1, v___x_1257_);
lean_ctor_set(v___x_1230_, 0, v___x_1256_);
v___x_1259_ = v___x_1230_;
goto v_reusejp_1258_;
}
else
{
lean_object* v_reuseFailAlloc_1267_; 
v_reuseFailAlloc_1267_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1267_, 0, v___x_1256_);
lean_ctor_set(v_reuseFailAlloc_1267_, 1, v___x_1257_);
v___x_1259_ = v_reuseFailAlloc_1267_;
goto v_reusejp_1258_;
}
v_reusejp_1258_:
{
lean_object* v___x_1260_; lean_object* v___x_1261_; lean_object* v___x_1262_; lean_object* v___x_1263_; lean_object* v___x_1264_; lean_object* v___x_1265_; 
v___x_1260_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1260_, 0, v___x_1253_);
lean_ctor_set(v___x_1260_, 1, v___x_1259_);
v___x_1261_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1261_, 0, v___x_1250_);
lean_ctor_set(v___x_1261_, 1, v___x_1260_);
v___x_1262_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1262_, 0, v___x_1247_);
lean_ctor_set(v___x_1262_, 1, v___x_1261_);
v___x_1263_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1263_, 0, v___x_1244_);
lean_ctor_set(v___x_1263_, 1, v___x_1262_);
v___x_1264_ = l_Lean_Json_mkObj(v___x_1263_);
lean_dec_ref_known(v___x_1263_, 2);
v___x_1265_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1265_, 0, v___x_1264_);
lean_ctor_set(v___x_1265_, 1, v_a_1224_);
v_a_1223_ = v_tail_1228_;
v_a_1224_ = v___x_1265_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg(lean_object* v_inputs_1275_, lean_object* v_geo_1276_, lean_object* v_range_1277_, lean_object* v_b_1278_, lean_object* v_i_1279_){
_start:
{
lean_object* v_stop_1281_; lean_object* v_step_1282_; uint8_t v___x_1283_; 
v_stop_1281_ = lean_ctor_get(v_range_1277_, 1);
v_step_1282_ = lean_ctor_get(v_range_1277_, 2);
v___x_1283_ = lean_nat_dec_lt(v_i_1279_, v_stop_1281_);
if (v___x_1283_ == 0)
{
lean_object* v___x_1284_; 
lean_dec(v_i_1279_);
lean_dec_ref(v_geo_1276_);
v___x_1284_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1284_, 0, v_b_1278_);
return v___x_1284_;
}
else
{
lean_object* v_input_1285_; lean_object* v_timestamp_1286_; lean_object* v_bytes_1287_; lean_object* v___x_1289_; uint8_t v_isShared_1290_; uint8_t v_isSharedCheck_1344_; 
v_input_1285_ = lean_array_fget(v_inputs_1275_, v_i_1279_);
v_timestamp_1286_ = lean_ctor_get(v_input_1285_, 0);
v_bytes_1287_ = lean_ctor_get(v_input_1285_, 1);
v_isSharedCheck_1344_ = !lean_is_exclusive(v_input_1285_);
if (v_isSharedCheck_1344_ == 0)
{
v___x_1289_ = v_input_1285_;
v_isShared_1290_ = v_isSharedCheck_1344_;
goto v_resetjp_1288_;
}
else
{
lean_inc(v_bytes_1287_);
lean_inc(v_timestamp_1286_);
lean_dec(v_input_1285_);
v___x_1289_ = lean_box(0);
v_isShared_1290_ = v_isSharedCheck_1344_;
goto v_resetjp_1288_;
}
v_resetjp_1288_:
{
lean_object* v___x_1291_; 
v___x_1291_ = lp_lean1090_Lean1090_Impl_decode(v_bytes_1287_);
lean_dec(v_bytes_1287_);
if (lean_obj_tag(v___x_1291_) == 1)
{
lean_object* v_val_1292_; lean_object* v___x_1294_; uint8_t v_isShared_1295_; uint8_t v_isSharedCheck_1341_; 
v_val_1292_ = lean_ctor_get(v___x_1291_, 0);
v_isSharedCheck_1341_ = !lean_is_exclusive(v___x_1291_);
if (v_isSharedCheck_1341_ == 0)
{
v___x_1294_ = v___x_1291_;
v_isShared_1295_ = v_isSharedCheck_1341_;
goto v_resetjp_1293_;
}
else
{
lean_inc(v_val_1292_);
lean_dec(v___x_1291_);
v___x_1294_ = lean_box(0);
v_isShared_1295_ = v_isSharedCheck_1341_;
goto v_resetjp_1293_;
}
v_resetjp_1293_:
{
lean_object* v_next_1296_; lean_object* v_fst_1297_; lean_object* v_snd_1298_; lean_object* v___x_1300_; uint8_t v_isShared_1301_; uint8_t v_isSharedCheck_1340_; 
lean_inc(v_val_1292_);
lean_inc_ref(v_geo_1276_);
v_next_1296_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance(v_geo_1276_, v_b_1278_, v_timestamp_1286_, v_val_1292_);
v_fst_1297_ = lean_ctor_get(v_next_1296_, 0);
v_snd_1298_ = lean_ctor_get(v_next_1296_, 1);
v_isSharedCheck_1340_ = !lean_is_exclusive(v_next_1296_);
if (v_isSharedCheck_1340_ == 0)
{
v___x_1300_ = v_next_1296_;
v_isShared_1301_ = v_isSharedCheck_1340_;
goto v_resetjp_1299_;
}
else
{
lean_inc(v_snd_1298_);
lean_inc(v_fst_1297_);
lean_dec(v_next_1296_);
v___x_1300_ = lean_box(0);
v_isShared_1301_ = v_isSharedCheck_1340_;
goto v_resetjp_1299_;
}
v_resetjp_1299_:
{
uint8_t v___y_1303_; lean_object* v_fields_1337_; lean_object* v_body_1338_; 
v_fields_1337_ = lean_ctor_get(v_val_1292_, 0);
lean_inc_ref(v_fields_1337_);
lean_dec(v_val_1292_);
v_body_1338_ = lean_ctor_get(v_fields_1337_, 0);
lean_inc_ref(v_body_1338_);
lean_dec_ref(v_fields_1337_);
if (lean_obj_tag(v_body_1338_) == 4)
{
lean_dec_ref_known(v_body_1338_, 3);
v___y_1303_ = v___x_1283_;
goto v___jp_1302_;
}
else
{
uint8_t v___x_1339_; 
lean_dec_ref(v_body_1338_);
v___x_1339_ = 0;
v___y_1303_ = v___x_1339_;
goto v___jp_1302_;
}
v___jp_1302_:
{
lean_object* v___x_1304_; lean_object* v___x_1305_; lean_object* v___x_1307_; 
v___x_1304_ = ((lean_object*)(lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___closed__0));
lean_inc(v_i_1279_);
v___x_1305_ = l_Lean_JsonNumber_fromNat(v_i_1279_);
if (v_isShared_1295_ == 0)
{
lean_ctor_set_tag(v___x_1294_, 2);
lean_ctor_set(v___x_1294_, 0, v___x_1305_);
v___x_1307_ = v___x_1294_;
goto v_reusejp_1306_;
}
else
{
lean_object* v_reuseFailAlloc_1336_; 
v_reuseFailAlloc_1336_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1336_, 0, v___x_1305_);
v___x_1307_ = v_reuseFailAlloc_1336_;
goto v_reusejp_1306_;
}
v_reusejp_1306_:
{
lean_object* v___x_1309_; 
if (v_isShared_1301_ == 0)
{
lean_ctor_set(v___x_1300_, 1, v___x_1307_);
lean_ctor_set(v___x_1300_, 0, v___x_1304_);
v___x_1309_ = v___x_1300_;
goto v_reusejp_1308_;
}
else
{
lean_object* v_reuseFailAlloc_1335_; 
v_reuseFailAlloc_1335_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1335_, 0, v___x_1304_);
lean_ctor_set(v_reuseFailAlloc_1335_, 1, v___x_1307_);
v___x_1309_ = v_reuseFailAlloc_1335_;
goto v_reusejp_1308_;
}
v_reusejp_1308_:
{
lean_object* v___x_1310_; lean_object* v___x_1311_; lean_object* v___x_1313_; 
v___x_1310_ = ((lean_object*)(lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3___closed__1));
v___x_1311_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson(v_snd_1298_);
if (v_isShared_1290_ == 0)
{
lean_ctor_set(v___x_1289_, 1, v___x_1311_);
lean_ctor_set(v___x_1289_, 0, v___x_1310_);
v___x_1313_ = v___x_1289_;
goto v_reusejp_1312_;
}
else
{
lean_object* v_reuseFailAlloc_1334_; 
v_reuseFailAlloc_1334_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1334_, 0, v___x_1310_);
lean_ctor_set(v_reuseFailAlloc_1334_, 1, v___x_1311_);
v___x_1313_ = v_reuseFailAlloc_1334_;
goto v_reusejp_1312_;
}
v_reusejp_1312_:
{
lean_object* v___x_1314_; lean_object* v___x_1315_; lean_object* v___x_1316_; lean_object* v___x_1317_; lean_object* v___x_1318_; lean_object* v___x_1319_; lean_object* v___x_1320_; lean_object* v___x_1321_; lean_object* v___x_1322_; lean_object* v___x_1323_; 
v___x_1314_ = ((lean_object*)(lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___closed__1));
v___x_1315_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_1315_, 0, v___y_1303_);
v___x_1316_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1316_, 0, v___x_1314_);
lean_ctor_set(v___x_1316_, 1, v___x_1315_);
v___x_1317_ = lean_box(0);
v___x_1318_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1318_, 0, v___x_1316_);
lean_ctor_set(v___x_1318_, 1, v___x_1317_);
v___x_1319_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1319_, 0, v___x_1313_);
lean_ctor_set(v___x_1319_, 1, v___x_1318_);
v___x_1320_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1320_, 0, v___x_1309_);
lean_ctor_set(v___x_1320_, 1, v___x_1319_);
v___x_1321_ = l_Lean_Json_mkObj(v___x_1320_);
lean_dec_ref_known(v___x_1320_, 2);
v___x_1322_ = l_Lean_Json_compress(v___x_1321_);
v___x_1323_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_1322_);
if (lean_obj_tag(v___x_1323_) == 0)
{
lean_object* v___x_1324_; 
lean_dec_ref_known(v___x_1323_, 1);
v___x_1324_ = lean_nat_add(v_i_1279_, v_step_1282_);
lean_dec(v_i_1279_);
v_b_1278_ = v_fst_1297_;
v_i_1279_ = v___x_1324_;
goto _start;
}
else
{
lean_object* v_a_1326_; lean_object* v___x_1328_; uint8_t v_isShared_1329_; uint8_t v_isSharedCheck_1333_; 
lean_dec(v_fst_1297_);
lean_dec(v_i_1279_);
lean_dec_ref(v_geo_1276_);
v_a_1326_ = lean_ctor_get(v___x_1323_, 0);
v_isSharedCheck_1333_ = !lean_is_exclusive(v___x_1323_);
if (v_isSharedCheck_1333_ == 0)
{
v___x_1328_ = v___x_1323_;
v_isShared_1329_ = v_isSharedCheck_1333_;
goto v_resetjp_1327_;
}
else
{
lean_inc(v_a_1326_);
lean_dec(v___x_1323_);
v___x_1328_ = lean_box(0);
v_isShared_1329_ = v_isSharedCheck_1333_;
goto v_resetjp_1327_;
}
v_resetjp_1327_:
{
lean_object* v___x_1331_; 
if (v_isShared_1329_ == 0)
{
v___x_1331_ = v___x_1328_;
goto v_reusejp_1330_;
}
else
{
lean_object* v_reuseFailAlloc_1332_; 
v_reuseFailAlloc_1332_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1332_, 0, v_a_1326_);
v___x_1331_ = v_reuseFailAlloc_1332_;
goto v_reusejp_1330_;
}
v_reusejp_1330_:
{
return v___x_1331_;
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
lean_object* v___x_1342_; lean_object* v___x_1343_; 
lean_dec(v___x_1291_);
lean_del_object(v___x_1289_);
lean_dec_ref(v_timestamp_1286_);
lean_dec(v_i_1279_);
lean_dec_ref(v_b_1278_);
lean_dec_ref(v_geo_1276_);
v___x_1342_ = ((lean_object*)(lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runDecodeOnce_spec__0___closed__1));
v___x_1343_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1343_, 0, v___x_1342_);
return v___x_1343_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg___boxed(lean_object* v_inputs_1345_, lean_object* v_geo_1346_, lean_object* v_range_1347_, lean_object* v_b_1348_, lean_object* v_i_1349_, lean_object* v___y_1350_){
_start:
{
lean_object* v_res_1351_; 
v_res_1351_ = lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg(v_inputs_1345_, v_geo_1346_, v_range_1347_, v_b_1348_, v_i_1349_);
lean_dec_ref(v_range_1347_);
lean_dec_ref(v_inputs_1345_);
return v_res_1351_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4_spec__5(size_t v_sz_1352_, size_t v_i_1353_, lean_object* v_bs_1354_){
_start:
{
uint8_t v___x_1355_; 
v___x_1355_ = lean_usize_dec_lt(v_i_1353_, v_sz_1352_);
if (v___x_1355_ == 0)
{
return v_bs_1354_;
}
else
{
lean_object* v_v_1356_; lean_object* v___x_1357_; lean_object* v_bs_x27_1358_; size_t v___x_1359_; size_t v___x_1360_; lean_object* v___x_1361_; 
v_v_1356_ = lean_array_uget(v_bs_1354_, v_i_1353_);
v___x_1357_ = lean_unsigned_to_nat(0u);
v_bs_x27_1358_ = lean_array_uset(v_bs_1354_, v_i_1353_, v___x_1357_);
v___x_1359_ = ((size_t)1ULL);
v___x_1360_ = lean_usize_add(v_i_1353_, v___x_1359_);
v___x_1361_ = lean_array_uset(v_bs_x27_1358_, v_i_1353_, v_v_1356_);
v_i_1353_ = v___x_1360_;
v_bs_1354_ = v___x_1361_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4_spec__5___boxed(lean_object* v_sz_1363_, lean_object* v_i_1364_, lean_object* v_bs_1365_){
_start:
{
size_t v_sz_boxed_1366_; size_t v_i_boxed_1367_; lean_object* v_res_1368_; 
v_sz_boxed_1366_ = lean_unbox_usize(v_sz_1363_);
lean_dec(v_sz_1363_);
v_i_boxed_1367_ = lean_unbox_usize(v_i_1364_);
lean_dec(v_i_1364_);
v_res_1368_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4_spec__5(v_sz_boxed_1366_, v_i_boxed_1367_, v_bs_1365_);
return v_res_1368_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4(lean_object* v_a_1369_){
_start:
{
size_t v_sz_1370_; size_t v___x_1371_; lean_object* v___x_1372_; lean_object* v___x_1373_; 
v_sz_1370_ = lean_array_size(v_a_1369_);
v___x_1371_ = ((size_t)0ULL);
v___x_1372_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4_spec__5(v_sz_1370_, v___x_1371_, v_a_1369_);
v___x_1373_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_1373_, 0, v___x_1372_);
return v___x_1373_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4(lean_object* v_a_1374_){
_start:
{
lean_object* v___x_1375_; lean_object* v___x_1376_; 
v___x_1375_ = lean_array_mk(v_a_1374_);
v___x_1376_ = lp_lean1090_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4_spec__4(v___x_1375_);
return v___x_1376_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking(lean_object* v_inputs_1386_, lean_object* v_geo_1387_){
_start:
{
lean_object* v___f_1389_; lean_object* v___x_1390_; lean_object* v_state_1391_; lean_object* v___x_1392_; lean_object* v___x_1393_; lean_object* v___x_1394_; lean_object* v___x_1395_; lean_object* v___x_1396_; 
v___f_1389_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__0));
v___x_1390_ = lean_box(0);
v_state_1391_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runCPROnce___closed__0));
v___x_1392_ = lean_unsigned_to_nat(0u);
v___x_1393_ = lean_array_get_size(v_inputs_1386_);
v___x_1394_ = lean_unsigned_to_nat(1u);
v___x_1395_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1395_, 0, v___x_1392_);
lean_ctor_set(v___x_1395_, 1, v___x_1393_);
lean_ctor_set(v___x_1395_, 2, v___x_1394_);
v___x_1396_ = lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg(v_inputs_1386_, v_geo_1387_, v___x_1395_, v_state_1391_, v___x_1392_);
lean_dec_ref_known(v___x_1395_, 3);
if (lean_obj_tag(v___x_1396_) == 0)
{
lean_object* v_a_1397_; lean_object* v_aircraft_1398_; lean_object* v_reference_1399_; lean_object* v___x_1401_; uint8_t v_isShared_1402_; uint8_t v_isSharedCheck_1420_; 
v_a_1397_ = lean_ctor_get(v___x_1396_, 0);
lean_inc(v_a_1397_);
lean_dec_ref_known(v___x_1396_, 1);
v_aircraft_1398_ = lean_ctor_get(v_a_1397_, 0);
v_reference_1399_ = lean_ctor_get(v_a_1397_, 1);
v_isSharedCheck_1420_ = !lean_is_exclusive(v_a_1397_);
if (v_isSharedCheck_1420_ == 0)
{
v___x_1401_ = v_a_1397_;
v_isShared_1402_ = v_isSharedCheck_1420_;
goto v_resetjp_1400_;
}
else
{
lean_inc(v_reference_1399_);
lean_inc(v_aircraft_1398_);
lean_dec(v_a_1397_);
v___x_1401_ = lean_box(0);
v_isShared_1402_ = v_isSharedCheck_1420_;
goto v_resetjp_1400_;
}
v_resetjp_1400_:
{
lean_object* v___x_1403_; lean_object* v___x_1404_; lean_object* v___x_1405_; lean_object* v___x_1406_; lean_object* v___x_1408_; 
v___x_1403_ = l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(v_aircraft_1398_, v___f_1389_);
v___x_1404_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__3));
v___x_1405_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__4));
v___x_1406_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_positionJson(v_reference_1399_);
if (v_isShared_1402_ == 0)
{
lean_ctor_set(v___x_1401_, 1, v___x_1406_);
lean_ctor_set(v___x_1401_, 0, v___x_1405_);
v___x_1408_ = v___x_1401_;
goto v_reusejp_1407_;
}
else
{
lean_object* v_reuseFailAlloc_1419_; 
v_reuseFailAlloc_1419_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1419_, 0, v___x_1405_);
lean_ctor_set(v_reuseFailAlloc_1419_, 1, v___x_1406_);
v___x_1408_ = v_reuseFailAlloc_1419_;
goto v_reusejp_1407_;
}
v_reusejp_1407_:
{
lean_object* v___x_1409_; lean_object* v___x_1410_; lean_object* v___x_1411_; lean_object* v___x_1412_; lean_object* v___x_1413_; lean_object* v___x_1414_; lean_object* v___x_1415_; lean_object* v___x_1416_; lean_object* v___x_1417_; lean_object* v___x_1418_; 
v___x_1409_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___closed__5));
v___x_1410_ = lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__3(v___x_1403_, v___x_1390_);
v___x_1411_ = lp_lean1090_Lean_List_toJson___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__4(v___x_1410_);
v___x_1412_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1412_, 0, v___x_1409_);
lean_ctor_set(v___x_1412_, 1, v___x_1411_);
v___x_1413_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1413_, 0, v___x_1412_);
lean_ctor_set(v___x_1413_, 1, v___x_1390_);
v___x_1414_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1414_, 0, v___x_1408_);
lean_ctor_set(v___x_1414_, 1, v___x_1413_);
v___x_1415_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1415_, 0, v___x_1404_);
lean_ctor_set(v___x_1415_, 1, v___x_1414_);
v___x_1416_ = l_Lean_Json_mkObj(v___x_1415_);
lean_dec_ref_known(v___x_1415_, 2);
v___x_1417_ = l_Lean_Json_compress(v___x_1416_);
v___x_1418_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_1417_);
return v___x_1418_;
}
}
}
else
{
lean_object* v_a_1421_; lean_object* v___x_1423_; uint8_t v_isShared_1424_; uint8_t v_isSharedCheck_1428_; 
v_a_1421_ = lean_ctor_get(v___x_1396_, 0);
v_isSharedCheck_1428_ = !lean_is_exclusive(v___x_1396_);
if (v_isSharedCheck_1428_ == 0)
{
v___x_1423_ = v___x_1396_;
v_isShared_1424_ = v_isSharedCheck_1428_;
goto v_resetjp_1422_;
}
else
{
lean_inc(v_a_1421_);
lean_dec(v___x_1396_);
v___x_1423_ = lean_box(0);
v_isShared_1424_ = v_isSharedCheck_1428_;
goto v_resetjp_1422_;
}
v_resetjp_1422_:
{
lean_object* v___x_1426_; 
if (v_isShared_1424_ == 0)
{
v___x_1426_ = v___x_1423_;
goto v_reusejp_1425_;
}
else
{
lean_object* v_reuseFailAlloc_1427_; 
v_reuseFailAlloc_1427_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1427_, 0, v_a_1421_);
v___x_1426_ = v_reuseFailAlloc_1427_;
goto v_reusejp_1425_;
}
v_reusejp_1425_:
{
return v___x_1426_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking___boxed(lean_object* v_inputs_1429_, lean_object* v_geo_1430_, lean_object* v_a_1431_){
_start:
{
lean_object* v_res_1432_; 
v_res_1432_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking(v_inputs_1429_, v_geo_1430_);
lean_dec_ref(v_inputs_1429_);
return v_res_1432_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2(lean_object* v_inputs_1433_, lean_object* v_geo_1434_, lean_object* v_range_1435_, lean_object* v_b_1436_, lean_object* v_i_1437_, lean_object* v_hs_1438_, lean_object* v_hl_1439_){
_start:
{
lean_object* v___x_1441_; 
v___x_1441_ = lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___redArg(v_inputs_1433_, v_geo_1434_, v_range_1435_, v_b_1436_, v_i_1437_);
return v___x_1441_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2___boxed(lean_object* v_inputs_1442_, lean_object* v_geo_1443_, lean_object* v_range_1444_, lean_object* v_b_1445_, lean_object* v_i_1446_, lean_object* v_hs_1447_, lean_object* v_hl_1448_, lean_object* v___y_1449_){
_start:
{
lean_object* v_res_1450_; 
v_res_1450_ = lp_lean1090___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking_spec__2(v_inputs_1442_, v_geo_1443_, v_range_1444_, v_b_1445_, v_i_1446_, v_hs_1447_, v_hl_1448_);
lean_dec_ref(v_range_1444_);
lean_dec_ref(v_inputs_1442_);
return v_res_1450_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg(lean_object* v_a_1457_, lean_object* v___x_1458_, lean_object* v_as_x27_1459_, lean_object* v_b_1460_){
_start:
{
if (lean_obj_tag(v_as_x27_1459_) == 0)
{
lean_object* v___x_1462_; 
lean_dec_ref(v___x_1458_);
v___x_1462_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1462_, 0, v_b_1460_);
return v___x_1462_;
}
else
{
lean_object* v_head_1463_; lean_object* v_tail_1464_; lean_object* v___x_1465_; uint8_t v___x_1466_; lean_object* v___x_1467_; 
v_head_1463_ = lean_ctor_get(v_as_x27_1459_, 0);
v_tail_1464_ = lean_ctor_get(v_as_x27_1459_, 1);
v___x_1465_ = lean_box(0);
v___x_1466_ = lean_unbox(v_head_1463_);
lean_inc_ref(v___x_1458_);
v___x_1467_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_runOnce(v_a_1457_, v___x_1458_, v___x_1466_);
if (lean_obj_tag(v___x_1467_) == 0)
{
lean_object* v_a_1468_; lean_object* v_snd_1469_; lean_object* v___x_1470_; lean_object* v___y_1472_; uint8_t v___x_1487_; 
v_a_1468_ = lean_ctor_get(v___x_1467_, 0);
lean_inc(v_a_1468_);
lean_dec_ref_known(v___x_1467_, 1);
v_snd_1469_ = lean_ctor_get(v_a_1468_, 1);
lean_inc(v_snd_1469_);
lean_dec(v_a_1468_);
v___x_1470_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__0));
v___x_1487_ = lean_unbox(v_head_1463_);
if (v___x_1487_ == 0)
{
lean_object* v___x_1488_; 
v___x_1488_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__4));
v___y_1472_ = v___x_1488_;
goto v___jp_1471_;
}
else
{
lean_object* v___x_1489_; 
v___x_1489_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__5));
v___y_1472_ = v___x_1489_;
goto v___jp_1471_;
}
v___jp_1471_:
{
lean_object* v___x_1473_; lean_object* v___x_1474_; lean_object* v___x_1475_; lean_object* v___x_1476_; lean_object* v___x_1477_; lean_object* v___x_1478_; lean_object* v___x_1479_; lean_object* v___x_1480_; lean_object* v___x_1481_; lean_object* v___x_1482_; lean_object* v___x_1483_; lean_object* v___x_1484_; lean_object* v___x_1485_; 
v___x_1473_ = lean_string_append(v___x_1470_, v___y_1472_);
v___x_1474_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__1));
v___x_1475_ = lean_string_append(v___x_1473_, v___x_1474_);
v___x_1476_ = lean_array_get_size(v_a_1457_);
v___x_1477_ = l_Nat_reprFast(v___x_1476_);
v___x_1478_ = lean_string_append(v___x_1475_, v___x_1477_);
lean_dec_ref(v___x_1477_);
v___x_1479_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__2));
v___x_1480_ = lean_string_append(v___x_1478_, v___x_1479_);
v___x_1481_ = l_Nat_reprFast(v_snd_1469_);
v___x_1482_ = lean_string_append(v___x_1480_, v___x_1481_);
lean_dec_ref(v___x_1481_);
v___x_1483_ = ((lean_object*)(lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___closed__3));
v___x_1484_ = lean_string_append(v___x_1482_, v___x_1483_);
v___x_1485_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_1484_);
if (lean_obj_tag(v___x_1485_) == 0)
{
lean_dec_ref_known(v___x_1485_, 1);
v_as_x27_1459_ = v_tail_1464_;
v_b_1460_ = v___x_1465_;
goto _start;
}
else
{
lean_dec_ref(v___x_1458_);
return v___x_1485_;
}
}
}
else
{
lean_object* v_a_1490_; lean_object* v___x_1492_; uint8_t v_isShared_1493_; uint8_t v_isSharedCheck_1497_; 
lean_dec_ref(v___x_1458_);
v_a_1490_ = lean_ctor_get(v___x_1467_, 0);
v_isSharedCheck_1497_ = !lean_is_exclusive(v___x_1467_);
if (v_isSharedCheck_1497_ == 0)
{
v___x_1492_ = v___x_1467_;
v_isShared_1493_ = v_isSharedCheck_1497_;
goto v_resetjp_1491_;
}
else
{
lean_inc(v_a_1490_);
lean_dec(v___x_1467_);
v___x_1492_ = lean_box(0);
v_isShared_1493_ = v_isSharedCheck_1497_;
goto v_resetjp_1491_;
}
v_resetjp_1491_:
{
lean_object* v___x_1495_; 
if (v_isShared_1493_ == 0)
{
v___x_1495_ = v___x_1492_;
goto v_reusejp_1494_;
}
else
{
lean_object* v_reuseFailAlloc_1496_; 
v_reuseFailAlloc_1496_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1496_, 0, v_a_1490_);
v___x_1495_ = v_reuseFailAlloc_1496_;
goto v_reusejp_1494_;
}
v_reusejp_1494_:
{
return v___x_1495_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg___boxed(lean_object* v_a_1498_, lean_object* v___x_1499_, lean_object* v_as_x27_1500_, lean_object* v_b_1501_, lean_object* v___y_1502_){
_start:
{
lean_object* v_res_1503_; 
v_res_1503_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg(v_a_1498_, v___x_1499_, v_as_x27_1500_, v_b_1501_);
lean_dec(v_as_x27_1500_);
lean_dec_ref(v_a_1498_);
return v_res_1503_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__1(lean_object* v_a_1504_, lean_object* v_a_1505_){
_start:
{
if (lean_obj_tag(v_a_1504_) == 0)
{
lean_object* v___x_1506_; 
v___x_1506_ = l_List_reverse___redArg(v_a_1505_);
return v___x_1506_;
}
else
{
lean_object* v_head_1507_; lean_object* v_tail_1508_; lean_object* v___x_1510_; uint8_t v_isShared_1511_; uint8_t v_isSharedCheck_1519_; 
v_head_1507_ = lean_ctor_get(v_a_1504_, 0);
v_tail_1508_ = lean_ctor_get(v_a_1504_, 1);
v_isSharedCheck_1519_ = !lean_is_exclusive(v_a_1504_);
if (v_isSharedCheck_1519_ == 0)
{
v___x_1510_ = v_a_1504_;
v_isShared_1511_ = v_isSharedCheck_1519_;
goto v_resetjp_1509_;
}
else
{
lean_inc(v_tail_1508_);
lean_inc(v_head_1507_);
lean_dec(v_a_1504_);
v___x_1510_ = lean_box(0);
v_isShared_1511_ = v_isSharedCheck_1519_;
goto v_resetjp_1509_;
}
v_resetjp_1509_:
{
uint8_t v___x_1512_; lean_object* v___x_1513_; lean_object* v___x_1514_; lean_object* v___x_1516_; 
v___x_1512_ = lean_unbox(v_head_1507_);
lean_dec(v_head_1507_);
v___x_1513_ = lean_uint8_to_nat(v___x_1512_);
v___x_1514_ = l_Nat_reprFast(v___x_1513_);
if (v_isShared_1511_ == 0)
{
lean_ctor_set(v___x_1510_, 1, v_a_1505_);
lean_ctor_set(v___x_1510_, 0, v___x_1514_);
v___x_1516_ = v___x_1510_;
goto v_reusejp_1515_;
}
else
{
lean_object* v_reuseFailAlloc_1518_; 
v_reuseFailAlloc_1518_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1518_, 0, v___x_1514_);
lean_ctor_set(v_reuseFailAlloc_1518_, 1, v_a_1505_);
v___x_1516_ = v_reuseFailAlloc_1518_;
goto v_reusejp_1515_;
}
v_reusejp_1515_:
{
v_a_1504_ = v_tail_1508_;
v_a_1505_ = v___x_1516_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__2(lean_object* v_as_1520_, size_t v_sz_1521_, size_t v_i_1522_, lean_object* v_b_1523_){
_start:
{
uint8_t v___x_1525_; 
v___x_1525_ = lean_usize_dec_lt(v_i_1522_, v_sz_1521_);
if (v___x_1525_ == 0)
{
lean_object* v___x_1526_; 
v___x_1526_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1526_, 0, v_b_1523_);
return v___x_1526_;
}
else
{
lean_object* v_a_1527_; lean_object* v_timestamp_1528_; lean_object* v_bytes_1529_; lean_object* v___x_1530_; lean_object* v___x_1531_; lean_object* v___x_1532_; lean_object* v___x_1533_; lean_object* v___x_1534_; lean_object* v___x_1535_; lean_object* v___x_1536_; lean_object* v___x_1537_; lean_object* v___x_1538_; lean_object* v___x_1539_; 
v_a_1527_ = lean_array_uget_borrowed(v_as_1520_, v_i_1522_);
v_timestamp_1528_ = lean_ctor_get(v_a_1527_, 0);
v_bytes_1529_ = lean_ctor_get(v_a_1527_, 1);
v___x_1530_ = lean_box(0);
lean_inc_ref(v_timestamp_1528_);
v___x_1531_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(v_timestamp_1528_);
v___x_1532_ = l_Nat_reprFast(v___x_1531_);
v___x_1533_ = ((lean_object*)(lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__4));
v___x_1534_ = lean_string_append(v___x_1532_, v___x_1533_);
v___x_1535_ = lean_box(0);
lean_inc(v_bytes_1529_);
v___x_1536_ = lp_lean1090_List_mapTR_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__1(v_bytes_1529_, v___x_1535_);
v___x_1537_ = l_String_intercalate(v___x_1533_, v___x_1536_);
v___x_1538_ = lean_string_append(v___x_1534_, v___x_1537_);
lean_dec_ref(v___x_1537_);
v___x_1539_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_1538_);
if (lean_obj_tag(v___x_1539_) == 0)
{
size_t v___x_1540_; size_t v___x_1541_; 
lean_dec_ref_known(v___x_1539_, 1);
v___x_1540_ = ((size_t)1ULL);
v___x_1541_ = lean_usize_add(v_i_1522_, v___x_1540_);
v_i_1522_ = v___x_1541_;
v_b_1523_ = v___x_1530_;
goto _start;
}
else
{
return v___x_1539_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__2___boxed(lean_object* v_as_1543_, lean_object* v_sz_1544_, lean_object* v_i_1545_, lean_object* v_b_1546_, lean_object* v___y_1547_){
_start:
{
size_t v_sz_boxed_1548_; size_t v_i_boxed_1549_; lean_object* v_res_1550_; 
v_sz_boxed_1548_ = lean_unbox_usize(v_sz_1544_);
lean_dec(v_sz_1544_);
v_i_boxed_1549_ = lean_unbox_usize(v_i_1545_);
lean_dec(v_i_1545_);
v_res_1550_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__2(v_as_1543_, v_sz_boxed_1548_, v_i_boxed_1549_, v_b_1546_);
lean_dec_ref(v_as_1543_);
return v_res_1550_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___redArg(lean_object* v_as_x27_1551_, lean_object* v_b_1552_){
_start:
{
if (lean_obj_tag(v_as_x27_1551_) == 0)
{
lean_object* v___x_1554_; 
v___x_1554_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1554_, 0, v_b_1552_);
return v___x_1554_;
}
else
{
lean_object* v_head_1555_; lean_object* v_position_1556_; lean_object* v_tail_1557_; lean_object* v_icao_1558_; lean_object* v_lat_1559_; lean_object* v_lon_1560_; lean_object* v___x_1561_; lean_object* v___x_1562_; lean_object* v___x_1563_; lean_object* v___x_1564_; lean_object* v___x_1565_; lean_object* v___x_1566_; lean_object* v___x_1567_; lean_object* v___x_1568_; lean_object* v___x_1569_; lean_object* v___x_1570_; lean_object* v___x_1571_; 
v_head_1555_ = lean_ctor_get(v_as_x27_1551_, 0);
v_position_1556_ = lean_ctor_get(v_head_1555_, 1);
v_tail_1557_ = lean_ctor_get(v_as_x27_1551_, 1);
v_icao_1558_ = lean_ctor_get(v_head_1555_, 0);
v_lat_1559_ = lean_ctor_get(v_position_1556_, 0);
v_lon_1560_ = lean_ctor_get(v_position_1556_, 1);
v___x_1561_ = lean_box(0);
v___x_1562_ = ((lean_object*)(lp_lean1090___private_Init_While_0__repeatM_erased___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__1___redArg___closed__4));
lean_inc_ref(v_icao_1558_);
v___x_1563_ = lean_string_append(v_icao_1558_, v___x_1562_);
lean_inc_ref(v_lat_1559_);
v___x_1564_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(v_lat_1559_);
v___x_1565_ = l_Nat_reprFast(v___x_1564_);
v___x_1566_ = lean_string_append(v___x_1563_, v___x_1565_);
lean_dec_ref(v___x_1565_);
v___x_1567_ = lean_string_append(v___x_1566_, v___x_1562_);
lean_inc_ref(v_lon_1560_);
v___x_1568_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_floatBits(v_lon_1560_);
v___x_1569_ = l_Nat_reprFast(v___x_1568_);
v___x_1570_ = lean_string_append(v___x_1567_, v___x_1569_);
lean_dec_ref(v___x_1569_);
v___x_1571_ = lp_lean1090_IO_println___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker_spec__0(v___x_1570_);
if (lean_obj_tag(v___x_1571_) == 0)
{
lean_dec_ref_known(v___x_1571_, 1);
v_as_x27_1551_ = v_tail_1557_;
v_b_1552_ = v___x_1561_;
goto _start;
}
else
{
return v___x_1571_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___redArg___boxed(lean_object* v_as_x27_1573_, lean_object* v_b_1574_, lean_object* v___y_1575_){
_start:
{
lean_object* v_res_1576_; 
v_res_1576_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___redArg(v_as_x27_1573_, v_b_1574_);
lean_dec(v_as_x27_1573_);
return v_res_1576_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute(lean_object* v_mode_1586_, lean_object* v_path_1587_){
_start:
{
lean_object* v___x_1589_; 
v___x_1589_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadInputs(v_path_1587_);
if (lean_obj_tag(v___x_1589_) == 0)
{
lean_object* v_a_1590_; lean_object* v___x_1591_; 
v_a_1590_ = lean_ctor_get(v___x_1589_, 0);
lean_inc(v_a_1590_);
lean_dec_ref_known(v___x_1589_, 1);
v___x_1591_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_loadAirports();
if (lean_obj_tag(v___x_1591_) == 0)
{
lean_object* v_a_1592_; lean_object* v___x_1594_; uint8_t v_isShared_1595_; uint8_t v_isSharedCheck_1654_; 
v_a_1592_ = lean_ctor_get(v___x_1591_, 0);
v_isSharedCheck_1654_ = !lean_is_exclusive(v___x_1591_);
if (v_isSharedCheck_1654_ == 0)
{
v___x_1594_ = v___x_1591_;
v_isShared_1595_ = v_isSharedCheck_1654_;
goto v_resetjp_1593_;
}
else
{
lean_inc(v_a_1592_);
lean_dec(v___x_1591_);
v___x_1594_ = lean_box(0);
v_isShared_1595_ = v_isSharedCheck_1654_;
goto v_resetjp_1593_;
}
v_resetjp_1593_:
{
lean_object* v___x_1596_; lean_object* v___x_1597_; uint8_t v___x_1598_; 
lean_inc(v_a_1592_);
v___x_1596_ = lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography(v_a_1592_);
v___x_1597_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__0));
v___x_1598_ = lean_string_dec_eq(v_mode_1586_, v___x_1597_);
if (v___x_1598_ == 0)
{
lean_object* v___x_1599_; uint8_t v___x_1600_; 
v___x_1599_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__1));
v___x_1600_ = lean_string_dec_eq(v_mode_1586_, v___x_1599_);
if (v___x_1600_ == 0)
{
lean_object* v___x_1601_; uint8_t v___x_1602_; 
v___x_1601_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__2));
v___x_1602_ = lean_string_dec_eq(v_mode_1586_, v___x_1601_);
if (v___x_1602_ == 0)
{
lean_object* v___x_1603_; uint8_t v___x_1604_; 
v___x_1603_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__3));
v___x_1604_ = lean_string_dec_eq(v_mode_1586_, v___x_1603_);
if (v___x_1604_ == 0)
{
lean_object* v___x_1605_; uint8_t v___x_1606_; 
lean_dec_ref(v___x_1596_);
v___x_1605_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__4));
v___x_1606_ = lean_string_dec_eq(v_mode_1586_, v___x_1605_);
if (v___x_1606_ == 0)
{
lean_object* v___x_1607_; uint8_t v___x_1608_; 
lean_dec(v_a_1590_);
v___x_1607_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__5));
v___x_1608_ = lean_string_dec_eq(v_mode_1586_, v___x_1607_);
if (v___x_1608_ == 0)
{
lean_object* v___x_1609_; lean_object* v___x_1611_; 
lean_dec(v_a_1592_);
v___x_1609_ = ((lean_object*)(lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___closed__7));
if (v_isShared_1595_ == 0)
{
lean_ctor_set_tag(v___x_1594_, 1);
lean_ctor_set(v___x_1594_, 0, v___x_1609_);
v___x_1611_ = v___x_1594_;
goto v_reusejp_1610_;
}
else
{
lean_object* v_reuseFailAlloc_1612_; 
v_reuseFailAlloc_1612_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1612_, 0, v___x_1609_);
v___x_1611_ = v_reuseFailAlloc_1612_;
goto v_reusejp_1610_;
}
v_reusejp_1610_:
{
return v___x_1611_;
}
}
else
{
lean_object* v___x_1613_; lean_object* v___x_1614_; 
lean_del_object(v___x_1594_);
v___x_1613_ = lean_box(0);
v___x_1614_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___redArg(v_a_1592_, v___x_1613_);
lean_dec(v_a_1592_);
if (lean_obj_tag(v___x_1614_) == 0)
{
lean_object* v___x_1616_; uint8_t v_isShared_1617_; uint8_t v_isSharedCheck_1621_; 
v_isSharedCheck_1621_ = !lean_is_exclusive(v___x_1614_);
if (v_isSharedCheck_1621_ == 0)
{
lean_object* v_unused_1622_; 
v_unused_1622_ = lean_ctor_get(v___x_1614_, 0);
lean_dec(v_unused_1622_);
v___x_1616_ = v___x_1614_;
v_isShared_1617_ = v_isSharedCheck_1621_;
goto v_resetjp_1615_;
}
else
{
lean_dec(v___x_1614_);
v___x_1616_ = lean_box(0);
v_isShared_1617_ = v_isSharedCheck_1621_;
goto v_resetjp_1615_;
}
v_resetjp_1615_:
{
lean_object* v___x_1619_; 
if (v_isShared_1617_ == 0)
{
lean_ctor_set(v___x_1616_, 0, v___x_1613_);
v___x_1619_ = v___x_1616_;
goto v_reusejp_1618_;
}
else
{
lean_object* v_reuseFailAlloc_1620_; 
v_reuseFailAlloc_1620_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1620_, 0, v___x_1613_);
v___x_1619_ = v_reuseFailAlloc_1620_;
goto v_reusejp_1618_;
}
v_reusejp_1618_:
{
return v___x_1619_;
}
}
}
else
{
return v___x_1614_;
}
}
}
else
{
lean_object* v___x_1623_; size_t v_sz_1624_; size_t v___x_1625_; lean_object* v___x_1626_; 
lean_del_object(v___x_1594_);
lean_dec(v_a_1592_);
v___x_1623_ = lean_box(0);
v_sz_1624_ = lean_array_size(v_a_1590_);
v___x_1625_ = ((size_t)0ULL);
v___x_1626_ = lp_lean1090___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__2(v_a_1590_, v_sz_1624_, v___x_1625_, v___x_1623_);
lean_dec(v_a_1590_);
if (lean_obj_tag(v___x_1626_) == 0)
{
lean_object* v___x_1628_; uint8_t v_isShared_1629_; uint8_t v_isSharedCheck_1633_; 
v_isSharedCheck_1633_ = !lean_is_exclusive(v___x_1626_);
if (v_isSharedCheck_1633_ == 0)
{
lean_object* v_unused_1634_; 
v_unused_1634_ = lean_ctor_get(v___x_1626_, 0);
lean_dec(v_unused_1634_);
v___x_1628_ = v___x_1626_;
v_isShared_1629_ = v_isSharedCheck_1633_;
goto v_resetjp_1627_;
}
else
{
lean_dec(v___x_1626_);
v___x_1628_ = lean_box(0);
v_isShared_1629_ = v_isSharedCheck_1633_;
goto v_resetjp_1627_;
}
v_resetjp_1627_:
{
lean_object* v___x_1631_; 
if (v_isShared_1629_ == 0)
{
lean_ctor_set(v___x_1628_, 0, v___x_1623_);
v___x_1631_ = v___x_1628_;
goto v_reusejp_1630_;
}
else
{
lean_object* v_reuseFailAlloc_1632_; 
v_reuseFailAlloc_1632_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1632_, 0, v___x_1623_);
v___x_1631_ = v_reuseFailAlloc_1632_;
goto v_reusejp_1630_;
}
v_reusejp_1630_:
{
return v___x_1631_;
}
}
}
else
{
return v___x_1626_;
}
}
}
else
{
lean_object* v___x_1635_; 
lean_del_object(v___x_1594_);
lean_dec(v_a_1592_);
v___x_1635_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_auditTracking(v_a_1590_, v___x_1596_);
lean_dec(v_a_1590_);
return v___x_1635_;
}
}
else
{
lean_object* v___x_1636_; lean_object* v___x_1637_; lean_object* v___x_1638_; lean_object* v___x_1639_; lean_object* v___x_1640_; lean_object* v___x_1641_; lean_object* v___x_1642_; 
lean_del_object(v___x_1594_);
lean_dec(v_a_1592_);
v___x_1636_ = lean_box(0);
v___x_1637_ = lean_box(v___x_1602_);
v___x_1638_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1638_, 0, v___x_1637_);
lean_ctor_set(v___x_1638_, 1, v___x_1636_);
v___x_1639_ = lean_box(v___x_1600_);
v___x_1640_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1640_, 0, v___x_1639_);
lean_ctor_set(v___x_1640_, 1, v___x_1638_);
v___x_1641_ = lean_box(0);
v___x_1642_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg(v_a_1590_, v___x_1596_, v___x_1640_, v___x_1641_);
lean_dec_ref_known(v___x_1640_, 2);
lean_dec(v_a_1590_);
if (lean_obj_tag(v___x_1642_) == 0)
{
lean_object* v___x_1644_; uint8_t v_isShared_1645_; uint8_t v_isSharedCheck_1649_; 
v_isSharedCheck_1649_ = !lean_is_exclusive(v___x_1642_);
if (v_isSharedCheck_1649_ == 0)
{
lean_object* v_unused_1650_; 
v_unused_1650_ = lean_ctor_get(v___x_1642_, 0);
lean_dec(v_unused_1650_);
v___x_1644_ = v___x_1642_;
v_isShared_1645_ = v_isSharedCheck_1649_;
goto v_resetjp_1643_;
}
else
{
lean_dec(v___x_1642_);
v___x_1644_ = lean_box(0);
v_isShared_1645_ = v_isSharedCheck_1649_;
goto v_resetjp_1643_;
}
v_resetjp_1643_:
{
lean_object* v___x_1647_; 
if (v_isShared_1645_ == 0)
{
lean_ctor_set(v___x_1644_, 0, v___x_1641_);
v___x_1647_ = v___x_1644_;
goto v_reusejp_1646_;
}
else
{
lean_object* v_reuseFailAlloc_1648_; 
v_reuseFailAlloc_1648_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1648_, 0, v___x_1641_);
v___x_1647_ = v_reuseFailAlloc_1648_;
goto v_reusejp_1646_;
}
v_reusejp_1646_:
{
return v___x_1647_;
}
}
}
else
{
return v___x_1642_;
}
}
}
else
{
lean_object* v___x_1651_; 
lean_del_object(v___x_1594_);
lean_dec(v_a_1592_);
v___x_1651_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker(v_a_1590_, v___x_1596_, v___x_1600_);
lean_dec(v_a_1590_);
return v___x_1651_;
}
}
else
{
uint8_t v___x_1652_; lean_object* v___x_1653_; 
lean_del_object(v___x_1594_);
lean_dec(v_a_1592_);
v___x_1652_ = 0;
v___x_1653_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_worker(v_a_1590_, v___x_1596_, v___x_1652_);
lean_dec(v_a_1590_);
return v___x_1653_;
}
}
}
else
{
lean_object* v_a_1655_; lean_object* v___x_1657_; uint8_t v_isShared_1658_; uint8_t v_isSharedCheck_1662_; 
lean_dec(v_a_1590_);
v_a_1655_ = lean_ctor_get(v___x_1591_, 0);
v_isSharedCheck_1662_ = !lean_is_exclusive(v___x_1591_);
if (v_isSharedCheck_1662_ == 0)
{
v___x_1657_ = v___x_1591_;
v_isShared_1658_ = v_isSharedCheck_1662_;
goto v_resetjp_1656_;
}
else
{
lean_inc(v_a_1655_);
lean_dec(v___x_1591_);
v___x_1657_ = lean_box(0);
v_isShared_1658_ = v_isSharedCheck_1662_;
goto v_resetjp_1656_;
}
v_resetjp_1656_:
{
lean_object* v___x_1660_; 
if (v_isShared_1658_ == 0)
{
v___x_1660_ = v___x_1657_;
goto v_reusejp_1659_;
}
else
{
lean_object* v_reuseFailAlloc_1661_; 
v_reuseFailAlloc_1661_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1661_, 0, v_a_1655_);
v___x_1660_ = v_reuseFailAlloc_1661_;
goto v_reusejp_1659_;
}
v_reusejp_1659_:
{
return v___x_1660_;
}
}
}
}
else
{
lean_object* v_a_1663_; lean_object* v___x_1665_; uint8_t v_isShared_1666_; uint8_t v_isSharedCheck_1670_; 
v_a_1663_ = lean_ctor_get(v___x_1589_, 0);
v_isSharedCheck_1670_ = !lean_is_exclusive(v___x_1589_);
if (v_isSharedCheck_1670_ == 0)
{
v___x_1665_ = v___x_1589_;
v_isShared_1666_ = v_isSharedCheck_1670_;
goto v_resetjp_1664_;
}
else
{
lean_inc(v_a_1663_);
lean_dec(v___x_1589_);
v___x_1665_ = lean_box(0);
v_isShared_1666_ = v_isSharedCheck_1670_;
goto v_resetjp_1664_;
}
v_resetjp_1664_:
{
lean_object* v___x_1668_; 
if (v_isShared_1666_ == 0)
{
v___x_1668_ = v___x_1665_;
goto v_reusejp_1667_;
}
else
{
lean_object* v_reuseFailAlloc_1669_; 
v_reuseFailAlloc_1669_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1669_, 0, v_a_1663_);
v___x_1668_ = v_reuseFailAlloc_1669_;
goto v_reusejp_1667_;
}
v_reusejp_1667_:
{
return v___x_1668_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute___boxed(lean_object* v_mode_1671_, lean_object* v_path_1672_, lean_object* v_a_1673_){
_start:
{
lean_object* v_res_1674_; 
v_res_1674_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute(v_mode_1671_, v_path_1672_);
lean_dec_ref(v_path_1672_);
lean_dec_ref(v_mode_1671_);
return v_res_1674_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0(lean_object* v_as_1675_, lean_object* v_as_x27_1676_, lean_object* v_b_1677_, lean_object* v_a_1678_){
_start:
{
lean_object* v___x_1680_; 
v___x_1680_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___redArg(v_as_x27_1676_, v_b_1677_);
return v___x_1680_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0___boxed(lean_object* v_as_1681_, lean_object* v_as_x27_1682_, lean_object* v_b_1683_, lean_object* v_a_1684_, lean_object* v___y_1685_){
_start:
{
lean_object* v_res_1686_; 
v_res_1686_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__0(v_as_1681_, v_as_x27_1682_, v_b_1683_, v_a_1684_);
lean_dec(v_as_x27_1682_);
lean_dec(v_as_1681_);
return v_res_1686_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3(lean_object* v_a_1687_, lean_object* v___x_1688_, lean_object* v_as_1689_, lean_object* v_as_x27_1690_, lean_object* v_b_1691_, lean_object* v_a_1692_){
_start:
{
lean_object* v___x_1694_; 
v___x_1694_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___redArg(v_a_1687_, v___x_1688_, v_as_x27_1690_, v_b_1691_);
return v___x_1694_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3___boxed(lean_object* v_a_1695_, lean_object* v___x_1696_, lean_object* v_as_1697_, lean_object* v_as_x27_1698_, lean_object* v_b_1699_, lean_object* v_a_1700_, lean_object* v___y_1701_){
_start:
{
lean_object* v_res_1702_; 
v_res_1702_ = lp_lean1090_List_forIn_x27_loop___at___00__private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute_spec__3(v_a_1695_, v___x_1696_, v_as_1697_, v_as_x27_1698_, v_b_1699_, v_a_1700_);
lean_dec(v_as_x27_1698_);
lean_dec(v_as_1697_);
lean_dec_ref(v_a_1695_);
return v_res_1702_;
}
}
static lean_object* _init_lp_lean1090_main___boxed__const__1(void){
_start:
{
uint32_t v___x_1704_; lean_object* v___x_1705_; 
v___x_1704_ = 2;
v___x_1705_ = lean_box_uint32(v___x_1704_);
return v___x_1705_;
}
}
static lean_object* _init_lp_lean1090_main___boxed__const__2(void){
_start:
{
uint32_t v___x_1706_; lean_object* v___x_1707_; 
v___x_1706_ = 0;
v___x_1707_ = lean_box_uint32(v___x_1706_);
return v___x_1707_;
}
}
LEAN_EXPORT lean_object* _lean_main(lean_object* v_args_1708_){
_start:
{
if (lean_obj_tag(v_args_1708_) == 1)
{
lean_object* v_tail_1730_; 
v_tail_1730_ = lean_ctor_get(v_args_1708_, 1);
lean_inc(v_tail_1730_);
if (lean_obj_tag(v_tail_1730_) == 1)
{
lean_object* v_tail_1731_; 
v_tail_1731_ = lean_ctor_get(v_tail_1730_, 1);
if (lean_obj_tag(v_tail_1731_) == 0)
{
lean_object* v_head_1732_; lean_object* v_head_1733_; lean_object* v___x_1734_; 
v_head_1732_ = lean_ctor_get(v_args_1708_, 0);
lean_inc(v_head_1732_);
lean_dec_ref_known(v_args_1708_, 2);
v_head_1733_ = lean_ctor_get(v_tail_1730_, 0);
lean_inc(v_head_1733_);
lean_dec_ref_known(v_tail_1730_, 2);
v___x_1734_ = lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_execute(v_head_1732_, v_head_1733_);
lean_dec(v_head_1733_);
lean_dec(v_head_1732_);
if (lean_obj_tag(v___x_1734_) == 0)
{
lean_object* v___x_1736_; uint8_t v_isShared_1737_; uint8_t v_isSharedCheck_1742_; 
v_isSharedCheck_1742_ = !lean_is_exclusive(v___x_1734_);
if (v_isSharedCheck_1742_ == 0)
{
lean_object* v_unused_1743_; 
v_unused_1743_ = lean_ctor_get(v___x_1734_, 0);
lean_dec(v_unused_1743_);
v___x_1736_ = v___x_1734_;
v_isShared_1737_ = v_isSharedCheck_1742_;
goto v_resetjp_1735_;
}
else
{
lean_dec(v___x_1734_);
v___x_1736_ = lean_box(0);
v_isShared_1737_ = v_isSharedCheck_1742_;
goto v_resetjp_1735_;
}
v_resetjp_1735_:
{
lean_object* v___x_1738_; lean_object* v___x_1740_; 
v___x_1738_ = lp_lean1090_main___boxed__const__2;
if (v_isShared_1737_ == 0)
{
lean_ctor_set(v___x_1736_, 0, v___x_1738_);
v___x_1740_ = v___x_1736_;
goto v_reusejp_1739_;
}
else
{
lean_object* v_reuseFailAlloc_1741_; 
v_reuseFailAlloc_1741_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1741_, 0, v___x_1738_);
v___x_1740_ = v_reuseFailAlloc_1741_;
goto v_reusejp_1739_;
}
v_reusejp_1739_:
{
return v___x_1740_;
}
}
}
else
{
lean_object* v_a_1744_; lean_object* v___x_1746_; uint8_t v_isShared_1747_; uint8_t v_isSharedCheck_1751_; 
v_a_1744_ = lean_ctor_get(v___x_1734_, 0);
v_isSharedCheck_1751_ = !lean_is_exclusive(v___x_1734_);
if (v_isSharedCheck_1751_ == 0)
{
v___x_1746_ = v___x_1734_;
v_isShared_1747_ = v_isSharedCheck_1751_;
goto v_resetjp_1745_;
}
else
{
lean_inc(v_a_1744_);
lean_dec(v___x_1734_);
v___x_1746_ = lean_box(0);
v_isShared_1747_ = v_isSharedCheck_1751_;
goto v_resetjp_1745_;
}
v_resetjp_1745_:
{
lean_object* v___x_1749_; 
if (v_isShared_1747_ == 0)
{
v___x_1749_ = v___x_1746_;
goto v_reusejp_1748_;
}
else
{
lean_object* v_reuseFailAlloc_1750_; 
v_reuseFailAlloc_1750_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1750_, 0, v_a_1744_);
v___x_1749_ = v_reuseFailAlloc_1750_;
goto v_reusejp_1748_;
}
v_reusejp_1748_:
{
return v___x_1749_;
}
}
}
}
else
{
lean_dec_ref_known(v_tail_1730_, 2);
lean_dec_ref_known(v_args_1708_, 2);
goto v___jp_1710_;
}
}
else
{
lean_dec(v_tail_1730_);
lean_dec_ref_known(v_args_1708_, 2);
goto v___jp_1710_;
}
}
else
{
lean_dec(v_args_1708_);
goto v___jp_1710_;
}
v___jp_1710_:
{
lean_object* v___x_1711_; lean_object* v___x_1712_; 
v___x_1711_ = ((lean_object*)(lp_lean1090_main___closed__0));
v___x_1712_ = l_IO_eprintln___at___00__private_Init_System_IO_0__IO_eprintlnAux_spec__0(v___x_1711_);
if (lean_obj_tag(v___x_1712_) == 0)
{
lean_object* v___x_1714_; uint8_t v_isShared_1715_; uint8_t v_isSharedCheck_1720_; 
v_isSharedCheck_1720_ = !lean_is_exclusive(v___x_1712_);
if (v_isSharedCheck_1720_ == 0)
{
lean_object* v_unused_1721_; 
v_unused_1721_ = lean_ctor_get(v___x_1712_, 0);
lean_dec(v_unused_1721_);
v___x_1714_ = v___x_1712_;
v_isShared_1715_ = v_isSharedCheck_1720_;
goto v_resetjp_1713_;
}
else
{
lean_dec(v___x_1712_);
v___x_1714_ = lean_box(0);
v_isShared_1715_ = v_isSharedCheck_1720_;
goto v_resetjp_1713_;
}
v_resetjp_1713_:
{
lean_object* v___x_1716_; lean_object* v___x_1718_; 
v___x_1716_ = lp_lean1090_main___boxed__const__1;
if (v_isShared_1715_ == 0)
{
lean_ctor_set(v___x_1714_, 0, v___x_1716_);
v___x_1718_ = v___x_1714_;
goto v_reusejp_1717_;
}
else
{
lean_object* v_reuseFailAlloc_1719_; 
v_reuseFailAlloc_1719_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1719_, 0, v___x_1716_);
v___x_1718_ = v_reuseFailAlloc_1719_;
goto v_reusejp_1717_;
}
v_reusejp_1717_:
{
return v___x_1718_;
}
}
}
else
{
lean_object* v_a_1722_; lean_object* v___x_1724_; uint8_t v_isShared_1725_; uint8_t v_isSharedCheck_1729_; 
v_a_1722_ = lean_ctor_get(v___x_1712_, 0);
v_isSharedCheck_1729_ = !lean_is_exclusive(v___x_1712_);
if (v_isSharedCheck_1729_ == 0)
{
v___x_1724_ = v___x_1712_;
v_isShared_1725_ = v_isSharedCheck_1729_;
goto v_resetjp_1723_;
}
else
{
lean_inc(v_a_1722_);
lean_dec(v___x_1712_);
v___x_1724_ = lean_box(0);
v_isShared_1725_ = v_isSharedCheck_1729_;
goto v_resetjp_1723_;
}
v_resetjp_1723_:
{
lean_object* v___x_1727_; 
if (v_isShared_1725_ == 0)
{
v___x_1727_ = v___x_1724_;
goto v_reusejp_1726_;
}
else
{
lean_object* v_reuseFailAlloc_1728_; 
v_reuseFailAlloc_1728_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1728_, 0, v_a_1722_);
v___x_1727_ = v_reuseFailAlloc_1728_;
goto v_reusejp_1726_;
}
v_reusejp_1726_:
{
return v___x_1727_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_main___boxed(lean_object* v_args_1752_, lean_object* v_a_1753_){
_start:
{
lean_object* v_res_1754_; 
v_res_1754_ = _lean_main(v_args_1752_);
return v_res_1754_;
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
