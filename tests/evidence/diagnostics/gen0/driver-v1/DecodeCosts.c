// Lean compiler output
// Module: review.diagnostics.DecodeCosts
// Imports: public import Init public meta import Init public import Impl public import Lean.Data.Json.Parser public import Lean.Data.Json.FromToJson.Basic
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
lean_object* lean_mk_array(lean_object*, lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* lp_lean1090_Lean1090_Impl_decode(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
size_t lean_usize_add(size_t, size_t);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
uint8_t lean_usize_dec_eq(size_t, size_t);
uint64_t lean_uint8_to_uint64(uint8_t);
uint64_t lean_uint64_xor(uint64_t, uint64_t);
uint64_t lean_uint64_mul(uint64_t, uint64_t);
lean_object* lean_get_stdin();
lean_object* lean_string_utf8_byte_size(lean_object*);
lean_object* l_String_Slice_trimAscii(lean_object*);
lean_object* l_String_Slice_toString(lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* l_List_range(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_array_get_size(lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_array_fget(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
lean_object* l_Lean_JsonNumber_fromNat(lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* l_List_sum___at___00Lean_PersistentHashMap_subarrayMeasure_spec__2(lean_object*);
lean_object* l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(lean_object*, lean_object*);
lean_object* l_Lean_Json_mkObj(lean_object*);
lean_object* lean_array_mk(lean_object*);
size_t lean_array_size(lean_object*);
lean_object* lean_array_uget(lean_object*, size_t);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
uint8_t l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(lean_object*, lean_object*);
extern lean_object* lp_lean1090_Lean1090_Impl_commBRegisters;
lean_object* l_Bool_toNat(uint8_t);
lean_object* l_Int_instDecidableEq___boxed(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbAltitude(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_frameOracleAltitude(lean_object*);
uint8_t l_Option_instDecidableEq___redArg(lean_object*, lean_object*, lean_object*);
uint8_t lp_lean1090_Lean1090_Impl_bdsWireValid(lean_object*, lean_object*);
uint8_t lp_lean1090_Lean1090_Impl_cbScorePasses(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_payloadBits(lean_object*, lean_object*, lean_object*);
lean_object* lean_string_to_utf8(lean_object*);
lean_object* lean_byte_array_size(lean_object*);
lean_object* lean_byte_array_data(lean_object*);
size_t lean_usize_of_nat(lean_object*);
lean_object* lp_lean1090_Lean1090_Spec_instReprMessage_repr___redArg(lean_object*);
lean_object* l_Std_Format_pretty(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_fset(lean_object*, lean_object*, lean_object*);
lean_object* lean_array_to_list(lean_object*);
uint8_t lean_string_memcmp(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_String_Slice_Pos_nextn(lean_object*, lean_object*, lean_object*);
lean_object* l_String_Slice_toNat_x3f(lean_object*);
lean_object* l_IO_ofExcept___at___00Std_Time_Database_TZdb_parseTZIfFromDisk_spec__0___redArg(lean_object*);
lean_object* l_Lean_Json_compress(lean_object*);
lean_object* lean_string_push(lean_object*, uint32_t);
lean_object* lean_get_stdout();
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_io_get_num_heartbeats();
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_uint64_to_nat(uint64_t);
lean_object* l_List_zipIdxTR___redArg(lean_object*, lean_object*);
uint8_t lean_uint32_dec_le(uint32_t, uint32_t);
lean_object* lean_uint32_to_nat(uint32_t);
lean_object* l_IO_FS_readFile(lean_object*);
lean_object* l_String_splitOnAux(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lean_uint8_of_nat(lean_object*);
lean_object* l_List_head_x3f___redArg(lean_object*);
lean_object* lean_uint8_to_nat(uint8_t);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* lean_string_length(lean_object*);
lean_object* lean_string_data(lean_object*);
lean_object* l_List_drop___redArg(lean_object*, lean_object*);
lean_object* l_String_Slice_Pos_prevn(lean_object*, lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_decodeFrame(lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_nibble(uint32_t);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_nibble___boxed(lean_object*);
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hexBytes___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hexBytes___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hexBytes___closed__0_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hexBytes(lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "empty message"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__0_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__0_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__1 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__1_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "invalid hexadecimal digit"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__2 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__2_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__2_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__3 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__3_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 31, .m_capacity = 31, .m_length = 30, .m_data = "expected 7 or 14 message bytes"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__4 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__4_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__4_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__5 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__5_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "row "};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__6 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__6_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = ": expected timestamp,frame"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__7 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__7_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ","};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__8 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__8_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "missing Beast prefix"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__9 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__9_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__9_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__10 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__10_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "\r"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__11 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__11_value;
static lean_once_cell_t l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__12;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "\n"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__0_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 40, .m_capacity = 40, .m_length = 39, .m_data = "expected full 172432-row corpus, found "};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__1_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs(lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_IO_print___at___00IO_println___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_IO_print___at___00IO_println___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit_spec__0_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_IO_println___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_IO_println___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__0___boxed(lean_object*, lean_object*);
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(21) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__0_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(20) << 1) | 1)),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__0_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__1_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(18) << 1) | 1)),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__1_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__2 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__2_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(17) << 1) | 1)),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__2_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__3 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__3_value;
LEAN_EXPORT uint8_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1(uint8_t, uint8_t, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__2(lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__2___boxed(lean_object*);
LEAN_EXPORT uint8_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__3(lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__3___boxed(lean_object*);
LEAN_EXPORT uint8_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__4(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__4___boxed(lean_object*, lean_object*);
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 72, .m_capacity = 72, .m_length = 71, .m_data = "mode must be all, adsb, commb, other, df0..df31, or score40/44/45/50/60"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__0_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__0_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__1_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "all"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__2 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__2_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "adsb"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__3 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__3_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "commb"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__4 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__4_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "other"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__5 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__5_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "df"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6_value;
static lean_once_cell_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__7;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "DF must be 0..31"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__8 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__8_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__8_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__9 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__9_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "invalid DF number"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__10 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__10_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__10_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__11 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__11_value;
static const lean_closure_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__2___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__12 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__12_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__12_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__13 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__13_value;
static const lean_closure_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__3___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__14 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__14_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__14_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__15 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__15_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select(lean_object*);
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "score40"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__0_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "score44"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__1_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "score45"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__2 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__2_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "score50"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__3 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__3_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "score60"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__4 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__4_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(96) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__5 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__5_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(80) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__6 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__6_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(69) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__7 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__7_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(68) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__8 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__8_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(64) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__9 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__9_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister(lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___boxed(lean_object*);
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 30, .m_capacity = 30, .m_length = 29, .m_data = "expected diagnostic command: "};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command___closed__0_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint64_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_offsetBasis;
LEAN_EXPORT uint64_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prime;
LEAN_EXPORT uint64_t l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(lean_object*, size_t, size_t, uint64_t);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint64_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes(uint64_t, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__1(lean_object*, lean_object*);
static const lean_string_object l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "missing retained input"};
static const lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___closed__0 = (const lean_object*)&l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___closed__0_value;
static const lean_ctor_object l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___closed__0_value)}};
static const lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___closed__1 = (const lean_object*)&l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___closed__1_value;
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = "incomplete retained output"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__0_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__0_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__1_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(37, 35, 34, 132, 228, 156, 242, 203)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__2 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__2_value;
static lean_once_cell_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3;
static lean_once_cell_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 31, .m_capacity = 31, .m_length = 30, .m_data = "DF digest cardinality mismatch"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__5 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__5_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__5_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__6 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__6_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "count"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "repr_bytes"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__1_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "fnv1a64_decimal"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__2 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__2_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(lean_object*);
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = "decoder rejected corpus DF"};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0___closed__0 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0___closed__0_value;
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode(lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_bump(lean_object*, lean_object*);
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(96) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__0_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(80) << 1) | 1)),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__0_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__1_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(69) << 1) | 1)),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__1_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__2 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__2_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(68) << 1) | 1)),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__2_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__3 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__3_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(64) << 1) | 1)),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__3_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__4 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__4_value;
LEAN_EXPORT const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored___closed__4_value;
LEAN_EXPORT uint8_t l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 28, .m_capacity = 28, .m_length = 27, .m_data = "census shadow disagrees: DF"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__0_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = " register="};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__1 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__1_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = " word="};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__2 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__2_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 38, .m_capacity = 38, .m_length = 37, .m_data = "Comm-B census received a different DF"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__3 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__3_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__3_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__4 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__4_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*7 + 0, .m_other = 7, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus___closed__0_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "register_decimal"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__0_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "eligibility_slots"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__1 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__1_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "nonempty"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__2 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__2_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "hard_attempt_predictions"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__3 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__3_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "hard_pass"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__4 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__4_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "score_attempt_predictions"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__5 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__5_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "score_pass"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__6 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__6_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "eligible"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__7 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__7_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "accepted"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__8 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__8_value;
static const lean_string_object l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 30, .m_capacity = 30, .m_length = 29, .m_data = "decodeBDS_recheck_predictions"};
static const lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__9 = (const lean_object*)&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__9_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "missing census input"};
static const lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___closed__0 = (const lean_object*)&l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___closed__0_value;
static const lean_ctor_object l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___closed__0_value)}};
static const lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___closed__1 = (const lean_object*)&l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___closed__1_value;
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___lam__0___boxed(lean_object*, lean_object*);
static const lean_string_object l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "kind"};
static const lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3___closed__0 = (const lean_object*)&l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3___closed__0_value;
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4(lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(lean_object*);
static const lean_closure_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___lam__0___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__0_value;
static const lean_string_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "adsb_accepted"};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__1 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__1_value;
static const lean_string_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "adsb_payload_kinds"};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__2 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__2_value;
static const lean_string_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 29, .m_capacity = 29, .m_length = 28, .m_data = "decodeFrame_call_predictions"};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__3 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__3_value;
static const lean_string_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "crc_call_predictions"};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__4 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__4_value;
static const lean_string_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 31, .m_capacity = 31, .m_length = 30, .m_data = "adsbHardValid_call_predictions"};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__5 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__5_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(31) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__6 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__6_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(30) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__6_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__7 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__7_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(29) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__7_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__8 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__8_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(28) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__8_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__9 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__9_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(27) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__9_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__10 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__10_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(26) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__10_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__11 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__11_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(25) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__11_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__12 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__12_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(24) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__12_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__13 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__13_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(21) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__13_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__14 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__14_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(20) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__14_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__15 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__15_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(17) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__15_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__16 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__16_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(16) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__16_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__17 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__17_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__17_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__18 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__18_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(4) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__18_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__19 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__19_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__19_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__20 = (const lean_object*)&l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__20_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "post_decode_shadow_census"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__1_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__1_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__2 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__2_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3___closed__0_value),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__2_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__3 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__3_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "native_call_counts"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__4 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__4_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 1}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__5 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__5_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__4_value),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__5_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__6 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__6_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "per_df"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__7 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__7_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "digest"};
static const lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0___closed__0 = (const lean_object*)&l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0___closed__0_value;
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0(lean_object*, lean_object*);
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "phase"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__0_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "prepared"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__1_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__1_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__2 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__2_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__0_value),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__2_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__3 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__3_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "mode"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__4 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__4_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "selected"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__5 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__5_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "corpus_rows"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__6 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__6_value;
static lean_once_cell_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__7;
static lean_once_cell_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8;
static lean_once_cell_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9;
static lean_once_cell_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "run"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__11 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__11_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "decoded"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__12 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__12_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__12_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__13 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__13_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__0_value),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__13_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__14 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__14_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "retained"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__15 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__15_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "loop_small_allocations"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__16 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__16_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "consume"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__17 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__17_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "result"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__18 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__18_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__18_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__19 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__19_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__0_value),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__19_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__20 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__20_value;
static const lean_array_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__21 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__21_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode(lean_object*, lean_object*, uint8_t, uint8_t);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "score expected Comm-B"};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__0 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__0_value;
static const lean_ctor_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__0_value)}};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__1 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__1_value;
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "score frame rejected"};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__2 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__2_value;
static const lean_ctor_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__2_value)}};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__3 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__3_value;
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0(lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__0_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__0_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__1_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0(lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "missing score input"};
static const lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__0 = (const lean_object*)&l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__0_value;
static const lean_ctor_object l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__0_value)}};
static const lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__1 = (const lean_object*)&l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__1_value;
static const lean_string_object l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ":"};
static const lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__2 = (const lean_object*)&l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__2_value;
static const lean_string_object l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "false"};
static const lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__3 = (const lean_object*)&l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__3_value;
static const lean_string_object l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "true"};
static const lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__4 = (const lean_object*)&l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__4_value;
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "nonempty_commb"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__0_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "non_additive_probe"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__1_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 1}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(1, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__2 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__2_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__1_value),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__2_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__3 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__3_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__3_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__4 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__4_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = "incomplete retained scores"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__5 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__5_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__5_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__6 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__6_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__7 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__7_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__2_value),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__7_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__8 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__8_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "passes"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__9 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__9_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "df20"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__10 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__10_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "df21"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__11 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__11_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode(lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1___boxed(lean_object*, lean_object*);
static const lean_string_object l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "--census"};
static const lean_object* l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__0 = (const lean_object*)&l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__0_value;
static const lean_string_object l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "--wait"};
static const lean_object* l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__1 = (const lean_object*)&l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__1_value;
LEAN_EXPORT uint8_t l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___boxed(lean_object*);
static const lean_string_object l_Lean1090_Diagnostics_DecodeCosts_execute___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 52, .m_capacity = 52, .m_length = 51, .m_data = "usage: decode-costs MODE CORPUS [--census] [--wait]"};
static const lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute___closed__0 = (const lean_object*)&l_Lean1090_Diagnostics_DecodeCosts_execute___closed__0_value;
static const lean_ctor_object l_Lean1090_Diagnostics_DecodeCosts_execute___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_Lean1090_Diagnostics_DecodeCosts_execute___closed__0_value)}};
static const lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute___closed__1 = (const lean_object*)&l_Lean1090_Diagnostics_DecodeCosts_execute___closed__1_value;
static const lean_string_object l_Lean1090_Diagnostics_DecodeCosts_execute___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 35, .m_capacity = 35, .m_length = 34, .m_data = "--census is for whole-decode modes"};
static const lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute___closed__2 = (const lean_object*)&l_Lean1090_Diagnostics_DecodeCosts_execute___closed__2_value;
static const lean_ctor_object l_Lean1090_Diagnostics_DecodeCosts_execute___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_Lean1090_Diagnostics_DecodeCosts_execute___closed__2_value)}};
static const lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute___closed__3 = (const lean_object*)&l_Lean1090_Diagnostics_DecodeCosts_execute___closed__3_value;
static const lean_string_object l_Lean1090_Diagnostics_DecodeCosts_execute___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "unknown diagnostic flag"};
static const lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute___closed__4 = (const lean_object*)&l_Lean1090_Diagnostics_DecodeCosts_execute___closed__4_value;
static const lean_ctor_object l_Lean1090_Diagnostics_DecodeCosts_execute___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_Lean1090_Diagnostics_DecodeCosts_execute___closed__4_value)}};
static const lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute___closed__5 = (const lean_object*)&l_Lean1090_Diagnostics_DecodeCosts_execute___closed__5_value;
LEAN_EXPORT lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute(lean_object*);
LEAN_EXPORT lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* _lean_main(lean_object*);
LEAN_EXPORT lean_object* l_main___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_nibble(uint32_t v_c_1_){
_start:
{
uint32_t v___x_22_; uint8_t v___x_23_; 
v___x_22_ = 48;
v___x_23_ = lean_uint32_dec_le(v___x_22_, v_c_1_);
if (v___x_23_ == 0)
{
goto v___jp_13_;
}
else
{
uint32_t v___x_24_; uint8_t v___x_25_; 
v___x_24_ = 57;
v___x_25_ = lean_uint32_dec_le(v_c_1_, v___x_24_);
if (v___x_25_ == 0)
{
goto v___jp_13_;
}
else
{
lean_object* v___x_26_; lean_object* v___x_27_; lean_object* v___x_28_; lean_object* v___x_29_; 
v___x_26_ = lean_unsigned_to_nat(48u);
v___x_27_ = lean_uint32_to_nat(v_c_1_);
v___x_28_ = lean_nat_sub(v___x_27_, v___x_26_);
lean_dec(v___x_27_);
v___x_29_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_29_, 0, v___x_28_);
return v___x_29_;
}
}
v___jp_2_:
{
uint32_t v___x_3_; uint8_t v___x_4_; 
v___x_3_ = 65;
v___x_4_ = lean_uint32_dec_le(v___x_3_, v_c_1_);
if (v___x_4_ == 0)
{
lean_object* v___x_5_; 
v___x_5_ = lean_box(0);
return v___x_5_;
}
else
{
uint32_t v___x_6_; uint8_t v___x_7_; 
v___x_6_ = 70;
v___x_7_ = lean_uint32_dec_le(v_c_1_, v___x_6_);
if (v___x_7_ == 0)
{
lean_object* v___x_8_; 
v___x_8_ = lean_box(0);
return v___x_8_;
}
else
{
lean_object* v___x_9_; lean_object* v___x_10_; lean_object* v___x_11_; lean_object* v___x_12_; 
v___x_9_ = lean_uint32_to_nat(v_c_1_);
v___x_10_ = lean_unsigned_to_nat(55u);
v___x_11_ = lean_nat_sub(v___x_9_, v___x_10_);
lean_dec(v___x_9_);
v___x_12_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_12_, 0, v___x_11_);
return v___x_12_;
}
}
}
v___jp_13_:
{
uint32_t v___x_14_; uint8_t v___x_15_; 
v___x_14_ = 97;
v___x_15_ = lean_uint32_dec_le(v___x_14_, v_c_1_);
if (v___x_15_ == 0)
{
goto v___jp_2_;
}
else
{
uint32_t v___x_16_; uint8_t v___x_17_; 
v___x_16_ = 102;
v___x_17_ = lean_uint32_dec_le(v_c_1_, v___x_16_);
if (v___x_17_ == 0)
{
goto v___jp_2_;
}
else
{
lean_object* v___x_18_; lean_object* v___x_19_; lean_object* v___x_20_; lean_object* v___x_21_; 
v___x_18_ = lean_uint32_to_nat(v_c_1_);
v___x_19_ = lean_unsigned_to_nat(87u);
v___x_20_ = lean_nat_sub(v___x_18_, v___x_19_);
lean_dec(v___x_18_);
v___x_21_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_21_, 0, v___x_20_);
return v___x_21_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_nibble___boxed(lean_object* v_c_30_){
_start:
{
uint32_t v_c_boxed_31_; lean_object* v_res_32_; 
v_c_boxed_31_ = lean_unbox_uint32(v_c_30_);
lean_dec(v_c_30_);
v_res_32_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_nibble(v_c_boxed_31_);
return v_res_32_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hexBytes(lean_object* v_x_35_){
_start:
{
if (lean_obj_tag(v_x_35_) == 0)
{
lean_object* v___x_36_; 
v___x_36_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hexBytes___closed__0));
return v___x_36_;
}
else
{
lean_object* v_tail_37_; 
v_tail_37_ = lean_ctor_get(v_x_35_, 1);
lean_inc(v_tail_37_);
if (lean_obj_tag(v_tail_37_) == 1)
{
lean_object* v_head_38_; lean_object* v_head_39_; lean_object* v_tail_40_; lean_object* v___x_42_; uint8_t v_isShared_43_; uint8_t v_isSharedCheck_69_; 
v_head_38_ = lean_ctor_get(v_x_35_, 0);
lean_inc(v_head_38_);
lean_dec_ref_known(v_x_35_, 2);
v_head_39_ = lean_ctor_get(v_tail_37_, 0);
v_tail_40_ = lean_ctor_get(v_tail_37_, 1);
v_isSharedCheck_69_ = !lean_is_exclusive(v_tail_37_);
if (v_isSharedCheck_69_ == 0)
{
v___x_42_ = v_tail_37_;
v_isShared_43_ = v_isSharedCheck_69_;
goto v_resetjp_41_;
}
else
{
lean_inc(v_tail_40_);
lean_inc(v_head_39_);
lean_dec(v_tail_37_);
v___x_42_ = lean_box(0);
v_isShared_43_ = v_isSharedCheck_69_;
goto v_resetjp_41_;
}
v_resetjp_41_:
{
uint32_t v___x_44_; lean_object* v___x_45_; 
v___x_44_ = lean_unbox_uint32(v_head_38_);
lean_dec(v_head_38_);
v___x_45_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_nibble(v___x_44_);
if (lean_obj_tag(v___x_45_) == 0)
{
lean_object* v___x_46_; 
lean_del_object(v___x_42_);
lean_dec(v_tail_40_);
lean_dec(v_head_39_);
v___x_46_ = lean_box(0);
return v___x_46_;
}
else
{
lean_object* v_val_47_; uint32_t v___x_48_; lean_object* v___x_49_; 
v_val_47_ = lean_ctor_get(v___x_45_, 0);
lean_inc(v_val_47_);
lean_dec_ref_known(v___x_45_, 1);
v___x_48_ = lean_unbox_uint32(v_head_39_);
lean_dec(v_head_39_);
v___x_49_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_nibble(v___x_48_);
if (lean_obj_tag(v___x_49_) == 0)
{
lean_object* v___x_50_; 
lean_dec(v_val_47_);
lean_del_object(v___x_42_);
lean_dec(v_tail_40_);
v___x_50_ = lean_box(0);
return v___x_50_;
}
else
{
lean_object* v_val_51_; lean_object* v___x_52_; 
v_val_51_ = lean_ctor_get(v___x_49_, 0);
lean_inc(v_val_51_);
lean_dec_ref_known(v___x_49_, 1);
v___x_52_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hexBytes(v_tail_40_);
if (lean_obj_tag(v___x_52_) == 0)
{
lean_dec(v_val_51_);
lean_dec(v_val_47_);
lean_del_object(v___x_42_);
return v___x_52_;
}
else
{
lean_object* v_val_53_; lean_object* v___x_55_; uint8_t v_isShared_56_; uint8_t v_isSharedCheck_68_; 
v_val_53_ = lean_ctor_get(v___x_52_, 0);
v_isSharedCheck_68_ = !lean_is_exclusive(v___x_52_);
if (v_isSharedCheck_68_ == 0)
{
v___x_55_ = v___x_52_;
v_isShared_56_ = v_isSharedCheck_68_;
goto v_resetjp_54_;
}
else
{
lean_inc(v_val_53_);
lean_dec(v___x_52_);
v___x_55_ = lean_box(0);
v_isShared_56_ = v_isSharedCheck_68_;
goto v_resetjp_54_;
}
v_resetjp_54_:
{
lean_object* v___x_57_; lean_object* v___x_58_; lean_object* v___x_59_; uint8_t v___x_60_; lean_object* v___x_61_; lean_object* v___x_63_; 
v___x_57_ = lean_unsigned_to_nat(16u);
v___x_58_ = lean_nat_mul(v_val_47_, v___x_57_);
lean_dec(v_val_47_);
v___x_59_ = lean_nat_add(v___x_58_, v_val_51_);
lean_dec(v_val_51_);
lean_dec(v___x_58_);
v___x_60_ = lean_uint8_of_nat(v___x_59_);
lean_dec(v___x_59_);
v___x_61_ = lean_box(v___x_60_);
if (v_isShared_43_ == 0)
{
lean_ctor_set(v___x_42_, 1, v_val_53_);
lean_ctor_set(v___x_42_, 0, v___x_61_);
v___x_63_ = v___x_42_;
goto v_reusejp_62_;
}
else
{
lean_object* v_reuseFailAlloc_67_; 
v_reuseFailAlloc_67_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_67_, 0, v___x_61_);
lean_ctor_set(v_reuseFailAlloc_67_, 1, v_val_53_);
v___x_63_ = v_reuseFailAlloc_67_;
goto v_reusejp_62_;
}
v_reusejp_62_:
{
lean_object* v___x_65_; 
if (v_isShared_56_ == 0)
{
lean_ctor_set(v___x_55_, 0, v___x_63_);
v___x_65_ = v___x_55_;
goto v_reusejp_64_;
}
else
{
lean_object* v_reuseFailAlloc_66_; 
v_reuseFailAlloc_66_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_66_, 0, v___x_63_);
v___x_65_ = v_reuseFailAlloc_66_;
goto v_reusejp_64_;
}
v_reusejp_64_:
{
return v___x_65_;
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
lean_object* v___x_70_; 
lean_dec_ref_known(v_x_35_, 2);
lean_dec(v_tail_37_);
v___x_70_ = lean_box(0);
return v___x_70_;
}
}
}
}
static lean_object* _init_l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__12(void){
_start:
{
lean_object* v___x_87_; lean_object* v___x_88_; 
v___x_87_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__11));
v___x_88_ = lean_string_utf8_byte_size(v___x_87_);
return v___x_88_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg(lean_object* v___y_89_, lean_object* v_as_x27_90_, lean_object* v_b_91_){
_start:
{
if (lean_obj_tag(v_as_x27_90_) == 0)
{
lean_object* v___x_93_; 
v___x_93_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_93_, 0, v_b_91_);
return v___x_93_;
}
else
{
lean_object* v_head_94_; lean_object* v_tail_95_; lean_object* v___y_97_; lean_object* v___y_120_; lean_object* v_fst_126_; lean_object* v_snd_127_; uint8_t v___y_139_; lean_object* v___y_140_; uint8_t v___y_159_; lean_object* v___x_172_; lean_object* v___x_173_; uint8_t v___x_174_; 
v_head_94_ = lean_ctor_get(v_as_x27_90_, 0);
v_tail_95_ = lean_ctor_get(v_as_x27_90_, 1);
v_fst_126_ = lean_ctor_get(v_head_94_, 0);
v_snd_127_ = lean_ctor_get(v_head_94_, 1);
v___x_172_ = lean_string_utf8_byte_size(v_fst_126_);
v___x_173_ = lean_unsigned_to_nat(0u);
v___x_174_ = lean_nat_dec_eq(v___x_172_, v___x_173_);
if (v___x_174_ == 0)
{
v___y_159_ = v___x_174_;
goto v___jp_158_;
}
else
{
lean_object* v___x_175_; lean_object* v___x_176_; lean_object* v___x_177_; uint8_t v___x_178_; 
v___x_175_ = lean_unsigned_to_nat(1u);
v___x_176_ = lean_nat_add(v_snd_127_, v___x_175_);
v___x_177_ = l_List_lengthTR___redArg(v___y_89_);
v___x_178_ = lean_nat_dec_eq(v___x_176_, v___x_177_);
lean_dec(v___x_177_);
lean_dec(v___x_176_);
if (v___x_178_ == 0)
{
v___y_159_ = v___x_178_;
goto v___jp_158_;
}
else
{
v_as_x27_90_ = v_tail_95_;
goto _start;
}
}
v___jp_96_:
{
lean_object* v___x_98_; 
v___x_98_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hexBytes(v___y_97_);
if (lean_obj_tag(v___x_98_) == 1)
{
lean_object* v_val_99_; lean_object* v___x_101_; uint8_t v_isShared_102_; uint8_t v_isSharedCheck_116_; 
v_val_99_ = lean_ctor_get(v___x_98_, 0);
v_isSharedCheck_116_ = !lean_is_exclusive(v___x_98_);
if (v_isSharedCheck_116_ == 0)
{
v___x_101_ = v___x_98_;
v_isShared_102_ = v_isSharedCheck_116_;
goto v_resetjp_100_;
}
else
{
lean_inc(v_val_99_);
lean_dec(v___x_98_);
v___x_101_ = lean_box(0);
v_isShared_102_ = v_isSharedCheck_116_;
goto v_resetjp_100_;
}
v_resetjp_100_:
{
lean_object* v___x_103_; 
v___x_103_ = l_List_head_x3f___redArg(v_val_99_);
if (lean_obj_tag(v___x_103_) == 1)
{
lean_object* v_val_104_; uint8_t v___x_105_; lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_108_; lean_object* v___x_109_; lean_object* v___x_110_; 
lean_del_object(v___x_101_);
v_val_104_ = lean_ctor_get(v___x_103_, 0);
lean_inc(v_val_104_);
lean_dec_ref_known(v___x_103_, 1);
v___x_105_ = lean_unbox(v_val_104_);
lean_dec(v_val_104_);
v___x_106_ = lean_uint8_to_nat(v___x_105_);
v___x_107_ = lean_unsigned_to_nat(3u);
v___x_108_ = lean_nat_shiftr(v___x_106_, v___x_107_);
v___x_109_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_109_, 0, v___x_108_);
lean_ctor_set(v___x_109_, 1, v_val_99_);
v___x_110_ = lean_array_push(v_b_91_, v___x_109_);
v_as_x27_90_ = v_tail_95_;
v_b_91_ = v___x_110_;
goto _start;
}
else
{
lean_object* v___x_112_; lean_object* v___x_114_; 
lean_dec(v___x_103_);
lean_dec(v_val_99_);
lean_dec_ref(v_b_91_);
v___x_112_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__1));
if (v_isShared_102_ == 0)
{
lean_ctor_set(v___x_101_, 0, v___x_112_);
v___x_114_ = v___x_101_;
goto v_reusejp_113_;
}
else
{
lean_object* v_reuseFailAlloc_115_; 
v_reuseFailAlloc_115_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_115_, 0, v___x_112_);
v___x_114_ = v_reuseFailAlloc_115_;
goto v_reusejp_113_;
}
v_reusejp_113_:
{
return v___x_114_;
}
}
}
}
else
{
lean_object* v___x_117_; lean_object* v___x_118_; 
lean_dec(v___x_98_);
lean_dec_ref(v_b_91_);
v___x_117_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__3));
v___x_118_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_118_, 0, v___x_117_);
return v___x_118_;
}
}
v___jp_119_:
{
lean_object* v___x_121_; lean_object* v___x_122_; uint8_t v___x_123_; 
v___x_121_ = l_List_lengthTR___redArg(v___y_120_);
v___x_122_ = lean_unsigned_to_nat(28u);
v___x_123_ = lean_nat_dec_eq(v___x_121_, v___x_122_);
lean_dec(v___x_121_);
if (v___x_123_ == 0)
{
lean_object* v___x_124_; lean_object* v___x_125_; 
lean_dec(v___y_120_);
lean_dec_ref(v_b_91_);
v___x_124_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__5));
v___x_125_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_125_, 0, v___x_124_);
return v___x_125_;
}
else
{
v___y_97_ = v___y_120_;
goto v___jp_96_;
}
}
v___jp_128_:
{
lean_object* v___x_129_; lean_object* v___x_130_; lean_object* v___x_131_; lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; lean_object* v___x_136_; lean_object* v___x_137_; 
v___x_129_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__6));
v___x_130_ = lean_unsigned_to_nat(1u);
v___x_131_ = lean_nat_add(v_snd_127_, v___x_130_);
v___x_132_ = l_Nat_reprFast(v___x_131_);
v___x_133_ = lean_string_append(v___x_129_, v___x_132_);
lean_dec_ref(v___x_132_);
v___x_134_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__7));
v___x_135_ = lean_string_append(v___x_133_, v___x_134_);
v___x_136_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_136_, 0, v___x_135_);
v___x_137_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_137_, 0, v___x_136_);
return v___x_137_;
}
v___jp_138_:
{
lean_object* v___x_141_; lean_object* v___x_142_; lean_object* v___x_143_; lean_object* v___x_144_; 
v___x_141_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__8));
v___x_142_ = lean_unsigned_to_nat(0u);
v___x_143_ = lean_box(0);
v___x_144_ = l_String_splitOnAux(v___y_140_, v___x_141_, v___x_142_, v___x_142_, v___x_142_, v___x_143_);
lean_dec_ref(v___y_140_);
if (lean_obj_tag(v___x_144_) == 1)
{
lean_object* v_tail_145_; 
v_tail_145_ = lean_ctor_get(v___x_144_, 1);
lean_inc(v_tail_145_);
lean_dec_ref_known(v___x_144_, 2);
if (lean_obj_tag(v_tail_145_) == 1)
{
lean_object* v_tail_146_; 
v_tail_146_ = lean_ctor_get(v_tail_145_, 1);
if (lean_obj_tag(v_tail_146_) == 0)
{
lean_object* v_head_147_; lean_object* v___x_148_; lean_object* v___x_149_; uint8_t v___x_150_; 
v_head_147_ = lean_ctor_get(v_tail_145_, 0);
lean_inc(v_head_147_);
lean_dec_ref_known(v_tail_145_, 2);
v___x_148_ = lean_string_length(v_head_147_);
v___x_149_ = lean_unsigned_to_nat(18u);
v___x_150_ = lean_nat_dec_lt(v___x_148_, v___x_149_);
if (v___x_150_ == 0)
{
lean_object* v___x_151_; lean_object* v___x_152_; lean_object* v___x_153_; lean_object* v___x_154_; uint8_t v___x_155_; 
v___x_151_ = lean_string_data(v_head_147_);
v___x_152_ = l_List_drop___redArg(v___x_149_, v___x_151_);
lean_dec(v___x_151_);
v___x_153_ = l_List_lengthTR___redArg(v___x_152_);
v___x_154_ = lean_unsigned_to_nat(14u);
v___x_155_ = lean_nat_dec_eq(v___x_153_, v___x_154_);
lean_dec(v___x_153_);
if (v___x_155_ == 0)
{
v___y_120_ = v___x_152_;
goto v___jp_119_;
}
else
{
if (v___y_139_ == 0)
{
v___y_97_ = v___x_152_;
goto v___jp_96_;
}
else
{
v___y_120_ = v___x_152_;
goto v___jp_119_;
}
}
}
else
{
lean_object* v___x_156_; lean_object* v___x_157_; 
lean_dec(v_head_147_);
lean_dec_ref(v_b_91_);
v___x_156_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__10));
v___x_157_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_157_, 0, v___x_156_);
return v___x_157_;
}
}
else
{
lean_dec_ref_known(v_tail_145_, 2);
lean_dec_ref(v_b_91_);
goto v___jp_128_;
}
}
else
{
lean_dec(v_tail_145_);
lean_dec_ref(v_b_91_);
goto v___jp_128_;
}
}
else
{
lean_dec(v___x_144_);
lean_dec_ref(v_b_91_);
goto v___jp_128_;
}
}
v___jp_158_:
{
lean_object* v___x_160_; lean_object* v___x_161_; lean_object* v___x_162_; uint8_t v___x_163_; 
v___x_160_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__11));
v___x_161_ = lean_string_utf8_byte_size(v_fst_126_);
v___x_162_ = lean_obj_once(&l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__12, &l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__12_once, _init_l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___closed__12);
v___x_163_ = lean_nat_dec_le(v___x_162_, v___x_161_);
if (v___x_163_ == 0)
{
lean_inc(v_fst_126_);
v___y_139_ = v___y_159_;
v___y_140_ = v_fst_126_;
goto v___jp_138_;
}
else
{
lean_object* v___x_164_; lean_object* v___x_165_; uint8_t v___x_166_; 
v___x_164_ = lean_unsigned_to_nat(0u);
v___x_165_ = lean_nat_sub(v___x_161_, v___x_162_);
v___x_166_ = lean_string_memcmp(v_fst_126_, v___x_160_, v___x_165_, v___x_164_, v___x_162_);
lean_dec(v___x_165_);
if (v___x_166_ == 0)
{
lean_inc(v_fst_126_);
v___y_139_ = v___y_159_;
v___y_140_ = v_fst_126_;
goto v___jp_138_;
}
else
{
lean_object* v___x_167_; lean_object* v___x_168_; lean_object* v___x_169_; lean_object* v___x_170_; lean_object* v___x_171_; 
v___x_167_ = lean_unsigned_to_nat(1u);
lean_inc_n(v_fst_126_, 2);
v___x_168_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_168_, 0, v_fst_126_);
lean_ctor_set(v___x_168_, 1, v___x_164_);
lean_ctor_set(v___x_168_, 2, v___x_161_);
v___x_169_ = l_String_Slice_Pos_prevn(v___x_168_, v___x_161_, v___x_167_);
lean_dec_ref_known(v___x_168_, 3);
v___x_170_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_170_, 0, v_fst_126_);
lean_ctor_set(v___x_170_, 1, v___x_164_);
lean_ctor_set(v___x_170_, 2, v___x_169_);
v___x_171_ = l_String_Slice_toString(v___x_170_);
lean_dec_ref_known(v___x_170_, 3);
v___y_139_ = v___y_159_;
v___y_140_ = v___x_171_;
goto v___jp_138_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg___boxed(lean_object* v___y_180_, lean_object* v_as_x27_181_, lean_object* v_b_182_, lean_object* v___y_183_){
_start:
{
lean_object* v_res_184_; 
v_res_184_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg(v___y_180_, v_as_x27_181_, v_b_182_);
lean_dec(v_as_x27_181_);
lean_dec(v___y_180_);
return v_res_184_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs(lean_object* v_path_187_){
_start:
{
lean_object* v___x_189_; 
v___x_189_ = l_IO_FS_readFile(v_path_187_);
if (lean_obj_tag(v___x_189_) == 0)
{
lean_object* v_a_190_; lean_object* v___x_191_; lean_object* v___x_192_; lean_object* v___x_193_; lean_object* v___x_194_; lean_object* v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; lean_object* v___x_198_; 
v_a_190_ = lean_ctor_get(v___x_189_, 0);
lean_inc(v_a_190_);
lean_dec_ref_known(v___x_189_, 1);
v___x_191_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__0));
v___x_192_ = lean_unsigned_to_nat(0u);
v___x_193_ = lean_box(0);
v___x_194_ = l_String_splitOnAux(v_a_190_, v___x_191_, v___x_192_, v___x_192_, v___x_192_, v___x_193_);
lean_dec(v_a_190_);
v___x_195_ = lean_unsigned_to_nat(172432u);
v___x_196_ = lean_mk_empty_array_with_capacity(v___x_195_);
lean_inc(v___x_194_);
v___x_197_ = l_List_zipIdxTR___redArg(v___x_194_, v___x_192_);
v___x_198_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg(v___x_194_, v___x_197_, v___x_196_);
lean_dec(v___x_197_);
lean_dec(v___x_194_);
if (lean_obj_tag(v___x_198_) == 0)
{
lean_object* v_a_199_; lean_object* v___x_200_; uint8_t v___x_201_; 
v_a_199_ = lean_ctor_get(v___x_198_, 0);
lean_inc(v_a_199_);
v___x_200_ = lean_array_get_size(v_a_199_);
lean_dec(v_a_199_);
v___x_201_ = lean_nat_dec_eq(v___x_200_, v___x_195_);
if (v___x_201_ == 0)
{
lean_object* v___x_203_; uint8_t v_isShared_204_; uint8_t v_isSharedCheck_212_; 
v_isSharedCheck_212_ = !lean_is_exclusive(v___x_198_);
if (v_isSharedCheck_212_ == 0)
{
lean_object* v_unused_213_; 
v_unused_213_ = lean_ctor_get(v___x_198_, 0);
lean_dec(v_unused_213_);
v___x_203_ = v___x_198_;
v_isShared_204_ = v_isSharedCheck_212_;
goto v_resetjp_202_;
}
else
{
lean_dec(v___x_198_);
v___x_203_ = lean_box(0);
v_isShared_204_ = v_isSharedCheck_212_;
goto v_resetjp_202_;
}
v_resetjp_202_:
{
lean_object* v___x_205_; lean_object* v___x_206_; lean_object* v___x_207_; lean_object* v___x_208_; lean_object* v___x_210_; 
v___x_205_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__1));
v___x_206_ = l_Nat_reprFast(v___x_200_);
v___x_207_ = lean_string_append(v___x_205_, v___x_206_);
lean_dec_ref(v___x_206_);
v___x_208_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_208_, 0, v___x_207_);
if (v_isShared_204_ == 0)
{
lean_ctor_set_tag(v___x_203_, 1);
lean_ctor_set(v___x_203_, 0, v___x_208_);
v___x_210_ = v___x_203_;
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
return v___x_210_;
}
}
}
else
{
return v___x_198_;
}
}
else
{
return v___x_198_;
}
}
else
{
lean_object* v_a_214_; lean_object* v___x_216_; uint8_t v_isShared_217_; uint8_t v_isSharedCheck_221_; 
v_a_214_ = lean_ctor_get(v___x_189_, 0);
v_isSharedCheck_221_ = !lean_is_exclusive(v___x_189_);
if (v_isSharedCheck_221_ == 0)
{
v___x_216_ = v___x_189_;
v_isShared_217_ = v_isSharedCheck_221_;
goto v_resetjp_215_;
}
else
{
lean_inc(v_a_214_);
lean_dec(v___x_189_);
v___x_216_ = lean_box(0);
v_isShared_217_ = v_isSharedCheck_221_;
goto v_resetjp_215_;
}
v_resetjp_215_:
{
lean_object* v___x_219_; 
if (v_isShared_217_ == 0)
{
v___x_219_ = v___x_216_;
goto v_reusejp_218_;
}
else
{
lean_object* v_reuseFailAlloc_220_; 
v_reuseFailAlloc_220_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_220_, 0, v_a_214_);
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
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___boxed(lean_object* v_path_222_, lean_object* v_a_223_){
_start:
{
lean_object* v_res_224_; 
v_res_224_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs(v_path_222_);
lean_dec_ref(v_path_222_);
return v_res_224_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0(lean_object* v___y_225_, lean_object* v_as_226_, lean_object* v_as_x27_227_, lean_object* v_b_228_, lean_object* v_a_229_){
_start:
{
lean_object* v___x_231_; 
v___x_231_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___redArg(v___y_225_, v_as_x27_227_, v_b_228_);
return v___x_231_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0___boxed(lean_object* v___y_232_, lean_object* v_as_233_, lean_object* v_as_x27_234_, lean_object* v_b_235_, lean_object* v_a_236_, lean_object* v___y_237_){
_start:
{
lean_object* v_res_238_; 
v_res_238_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs_spec__0(v___y_232_, v_as_233_, v_as_x27_234_, v_b_235_, v_a_236_);
lean_dec(v_as_x27_234_);
lean_dec(v_as_233_);
lean_dec(v___y_232_);
return v_res_238_;
}
}
LEAN_EXPORT lean_object* l_IO_print___at___00IO_println___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit_spec__0_spec__0(lean_object* v_s_239_){
_start:
{
lean_object* v___x_241_; lean_object* v_putStr_242_; lean_object* v___x_243_; 
v___x_241_ = lean_get_stdout();
v_putStr_242_ = lean_ctor_get(v___x_241_, 4);
lean_inc_ref(v_putStr_242_);
lean_dec_ref(v___x_241_);
v___x_243_ = lean_apply_2(v_putStr_242_, v_s_239_, lean_box(0));
return v___x_243_;
}
}
LEAN_EXPORT lean_object* l_IO_print___at___00IO_println___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit_spec__0_spec__0___boxed(lean_object* v_s_244_, lean_object* v_a_245_){
_start:
{
lean_object* v_res_246_; 
v_res_246_ = l_IO_print___at___00IO_println___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit_spec__0_spec__0(v_s_244_);
return v_res_246_;
}
}
LEAN_EXPORT lean_object* l_IO_println___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit_spec__0(lean_object* v_s_247_){
_start:
{
uint32_t v___x_249_; lean_object* v___x_250_; lean_object* v___x_251_; 
v___x_249_ = 10;
v___x_250_ = lean_string_push(v_s_247_, v___x_249_);
v___x_251_ = l_IO_print___at___00IO_println___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit_spec__0_spec__0(v___x_250_);
return v___x_251_;
}
}
LEAN_EXPORT lean_object* l_IO_println___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit_spec__0___boxed(lean_object* v_s_252_, lean_object* v_a_253_){
_start:
{
lean_object* v_res_254_; 
v_res_254_ = l_IO_println___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit_spec__0(v_s_252_);
return v_res_254_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(lean_object* v_value_255_){
_start:
{
lean_object* v___x_257_; lean_object* v___x_258_; 
v___x_257_ = l_Lean_Json_compress(v_value_255_);
v___x_258_ = l_IO_println___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit_spec__0(v___x_257_);
if (lean_obj_tag(v___x_258_) == 0)
{
lean_object* v___x_259_; lean_object* v_flush_260_; lean_object* v___x_261_; 
lean_dec_ref_known(v___x_258_, 1);
v___x_259_ = lean_get_stdout();
v_flush_260_ = lean_ctor_get(v___x_259_, 0);
lean_inc_ref(v_flush_260_);
lean_dec_ref(v___x_259_);
v___x_261_ = lean_apply_1(v_flush_260_, lean_box(0));
return v___x_261_;
}
else
{
return v___x_258_;
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit___boxed(lean_object* v_value_262_, lean_object* v_a_263_){
_start:
{
lean_object* v_res_264_; 
v_res_264_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v_value_262_);
return v_res_264_;
}
}
LEAN_EXPORT uint8_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__0(lean_object* v_val_265_, lean_object* v_n_266_){
_start:
{
uint8_t v___x_267_; 
v___x_267_ = lean_nat_dec_eq(v_n_266_, v_val_265_);
return v___x_267_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__0___boxed(lean_object* v_val_268_, lean_object* v_n_269_){
_start:
{
uint8_t v_res_270_; lean_object* v_r_271_; 
v_res_270_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__0(v_val_268_, v_n_269_);
lean_dec(v_n_269_);
lean_dec(v_val_268_);
v_r_271_ = lean_box(v_res_270_);
return v_r_271_;
}
}
LEAN_EXPORT uint8_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1(uint8_t v___x_284_, uint8_t v___x_285_, lean_object* v_df_286_){
_start:
{
lean_object* v___x_287_; uint8_t v___x_288_; 
v___x_287_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___closed__3));
v___x_288_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_df_286_, v___x_287_);
if (v___x_288_ == 0)
{
return v___x_284_;
}
else
{
return v___x_285_;
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___boxed(lean_object* v___x_289_, lean_object* v___x_290_, lean_object* v_df_291_){
_start:
{
uint8_t v___x_1009__boxed_292_; uint8_t v___x_1010__boxed_293_; uint8_t v_res_294_; lean_object* v_r_295_; 
v___x_1009__boxed_292_ = lean_unbox(v___x_289_);
v___x_1010__boxed_293_ = lean_unbox(v___x_290_);
v_res_294_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1(v___x_1009__boxed_292_, v___x_1010__boxed_293_, v_df_291_);
lean_dec(v_df_291_);
v_r_295_ = lean_box(v_res_294_);
return v_r_295_;
}
}
LEAN_EXPORT uint8_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__2(lean_object* v_df_296_){
_start:
{
lean_object* v___x_297_; uint8_t v___x_298_; 
v___x_297_ = lean_unsigned_to_nat(20u);
v___x_298_ = lean_nat_dec_eq(v_df_296_, v___x_297_);
if (v___x_298_ == 0)
{
lean_object* v___x_299_; uint8_t v___x_300_; 
v___x_299_ = lean_unsigned_to_nat(21u);
v___x_300_ = lean_nat_dec_eq(v_df_296_, v___x_299_);
return v___x_300_;
}
else
{
return v___x_298_;
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__2___boxed(lean_object* v_df_301_){
_start:
{
uint8_t v_res_302_; lean_object* v_r_303_; 
v_res_302_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__2(v_df_301_);
lean_dec(v_df_301_);
v_r_303_ = lean_box(v_res_302_);
return v_r_303_;
}
}
LEAN_EXPORT uint8_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__3(lean_object* v_df_304_){
_start:
{
lean_object* v___x_305_; uint8_t v___x_306_; 
v___x_305_ = lean_unsigned_to_nat(17u);
v___x_306_ = lean_nat_dec_eq(v_df_304_, v___x_305_);
if (v___x_306_ == 0)
{
lean_object* v___x_307_; uint8_t v___x_308_; 
v___x_307_ = lean_unsigned_to_nat(18u);
v___x_308_ = lean_nat_dec_eq(v_df_304_, v___x_307_);
return v___x_308_;
}
else
{
return v___x_306_;
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__3___boxed(lean_object* v_df_309_){
_start:
{
uint8_t v_res_310_; lean_object* v_r_311_; 
v_res_310_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__3(v_df_309_);
lean_dec(v_df_309_);
v_r_311_ = lean_box(v_res_310_);
return v_r_311_;
}
}
LEAN_EXPORT uint8_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__4(uint8_t v___x_312_, lean_object* v_x_313_){
_start:
{
return v___x_312_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__4___boxed(lean_object* v___x_314_, lean_object* v_x_315_){
_start:
{
uint8_t v___x_1047__boxed_316_; uint8_t v_res_317_; lean_object* v_r_318_; 
v___x_1047__boxed_316_ = lean_unbox(v___x_314_);
v_res_317_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__4(v___x_1047__boxed_316_, v_x_315_);
lean_dec(v_x_315_);
v_r_318_ = lean_box(v_res_317_);
return v_r_318_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__7(void){
_start:
{
lean_object* v___x_327_; lean_object* v___x_328_; 
v___x_327_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6));
v___x_328_ = lean_string_utf8_byte_size(v___x_327_);
return v___x_328_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select(lean_object* v_mode_341_){
_start:
{
lean_object* v___x_344_; uint8_t v___x_345_; 
v___x_344_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__2));
v___x_345_ = lean_string_dec_eq(v_mode_341_, v___x_344_);
if (v___x_345_ == 0)
{
lean_object* v___x_346_; uint8_t v___x_347_; 
v___x_346_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__3));
v___x_347_ = lean_string_dec_eq(v_mode_341_, v___x_346_);
if (v___x_347_ == 0)
{
lean_object* v___x_348_; uint8_t v___x_349_; 
v___x_348_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__4));
v___x_349_ = lean_string_dec_eq(v_mode_341_, v___x_348_);
if (v___x_349_ == 0)
{
lean_object* v___x_350_; uint8_t v___x_351_; 
v___x_350_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__5));
v___x_351_ = lean_string_dec_eq(v_mode_341_, v___x_350_);
if (v___x_351_ == 0)
{
lean_object* v___x_352_; lean_object* v___x_353_; lean_object* v___x_354_; uint8_t v___x_355_; 
v___x_352_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6));
v___x_353_ = lean_string_utf8_byte_size(v_mode_341_);
v___x_354_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__7, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__7_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__7);
v___x_355_ = lean_nat_dec_le(v___x_354_, v___x_353_);
if (v___x_355_ == 0)
{
lean_dec_ref(v_mode_341_);
goto v___jp_342_;
}
else
{
lean_object* v___x_356_; uint8_t v___x_357_; 
v___x_356_ = lean_unsigned_to_nat(0u);
v___x_357_ = lean_string_memcmp(v_mode_341_, v___x_352_, v___x_356_, v___x_356_, v___x_354_);
if (v___x_357_ == 0)
{
lean_dec_ref(v_mode_341_);
goto v___jp_342_;
}
else
{
lean_object* v___x_358_; lean_object* v___x_359_; lean_object* v___x_360_; lean_object* v___x_361_; lean_object* v___x_362_; lean_object* v___x_363_; lean_object* v___x_364_; lean_object* v___x_365_; 
v___x_358_ = lean_unsigned_to_nat(2u);
lean_inc_ref(v_mode_341_);
v___x_359_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_359_, 0, v_mode_341_);
lean_ctor_set(v___x_359_, 1, v___x_356_);
lean_ctor_set(v___x_359_, 2, v___x_353_);
v___x_360_ = l_String_Slice_Pos_nextn(v___x_359_, v___x_356_, v___x_358_);
lean_dec_ref_known(v___x_359_, 3);
v___x_361_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_361_, 0, v_mode_341_);
lean_ctor_set(v___x_361_, 1, v___x_360_);
lean_ctor_set(v___x_361_, 2, v___x_353_);
v___x_362_ = l_String_Slice_toString(v___x_361_);
lean_dec_ref_known(v___x_361_, 3);
v___x_363_ = lean_string_utf8_byte_size(v___x_362_);
v___x_364_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_364_, 0, v___x_362_);
lean_ctor_set(v___x_364_, 1, v___x_356_);
lean_ctor_set(v___x_364_, 2, v___x_363_);
v___x_365_ = l_String_Slice_toNat_x3f(v___x_364_);
lean_dec_ref_known(v___x_364_, 3);
if (lean_obj_tag(v___x_365_) == 1)
{
lean_object* v_val_366_; lean_object* v___x_368_; uint8_t v_isShared_369_; uint8_t v_isSharedCheck_377_; 
v_val_366_ = lean_ctor_get(v___x_365_, 0);
v_isSharedCheck_377_ = !lean_is_exclusive(v___x_365_);
if (v_isSharedCheck_377_ == 0)
{
v___x_368_ = v___x_365_;
v_isShared_369_ = v_isSharedCheck_377_;
goto v_resetjp_367_;
}
else
{
lean_inc(v_val_366_);
lean_dec(v___x_365_);
v___x_368_ = lean_box(0);
v_isShared_369_ = v_isSharedCheck_377_;
goto v_resetjp_367_;
}
v_resetjp_367_:
{
lean_object* v___x_370_; uint8_t v___x_371_; 
v___x_370_ = lean_unsigned_to_nat(32u);
v___x_371_ = lean_nat_dec_le(v___x_370_, v_val_366_);
if (v___x_371_ == 0)
{
lean_object* v___f_372_; lean_object* v___x_374_; 
v___f_372_ = lean_alloc_closure((void*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__0___boxed), 2, 1);
lean_closure_set(v___f_372_, 0, v_val_366_);
if (v_isShared_369_ == 0)
{
lean_ctor_set(v___x_368_, 0, v___f_372_);
v___x_374_ = v___x_368_;
goto v_reusejp_373_;
}
else
{
lean_object* v_reuseFailAlloc_375_; 
v_reuseFailAlloc_375_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_375_, 0, v___f_372_);
v___x_374_ = v_reuseFailAlloc_375_;
goto v_reusejp_373_;
}
v_reusejp_373_:
{
return v___x_374_;
}
}
else
{
lean_object* v___x_376_; 
lean_del_object(v___x_368_);
lean_dec(v_val_366_);
v___x_376_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__9));
return v___x_376_;
}
}
}
else
{
lean_object* v___x_378_; 
lean_dec(v___x_365_);
v___x_378_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__11));
return v___x_378_;
}
}
}
}
else
{
lean_object* v___x_379_; lean_object* v___x_380_; lean_object* v___f_381_; lean_object* v___x_382_; 
lean_dec_ref(v_mode_341_);
v___x_379_ = lean_box(v___x_351_);
v___x_380_ = lean_box(v___x_349_);
v___f_381_ = lean_alloc_closure((void*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__1___boxed), 3, 2);
lean_closure_set(v___f_381_, 0, v___x_379_);
lean_closure_set(v___f_381_, 1, v___x_380_);
v___x_382_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_382_, 0, v___f_381_);
return v___x_382_;
}
}
else
{
lean_object* v___x_383_; 
lean_dec_ref(v_mode_341_);
v___x_383_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__13));
return v___x_383_;
}
}
else
{
lean_object* v___x_384_; 
lean_dec_ref(v_mode_341_);
v___x_384_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__15));
return v___x_384_;
}
}
else
{
lean_object* v___x_385_; lean_object* v___f_386_; lean_object* v___x_387_; 
lean_dec_ref(v_mode_341_);
v___x_385_ = lean_box(v___x_345_);
v___f_386_ = lean_alloc_closure((void*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___lam__4___boxed), 2, 1);
lean_closure_set(v___f_386_, 0, v___x_385_);
v___x_387_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_387_, 0, v___f_386_);
return v___x_387_;
}
v___jp_342_:
{
lean_object* v___x_343_; 
v___x_343_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__1));
return v___x_343_;
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister(lean_object* v_mode_403_){
_start:
{
lean_object* v___x_404_; uint8_t v___x_405_; 
v___x_404_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__0));
v___x_405_ = lean_string_dec_eq(v_mode_403_, v___x_404_);
if (v___x_405_ == 0)
{
lean_object* v___x_406_; uint8_t v___x_407_; 
v___x_406_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__1));
v___x_407_ = lean_string_dec_eq(v_mode_403_, v___x_406_);
if (v___x_407_ == 0)
{
lean_object* v___x_408_; uint8_t v___x_409_; 
v___x_408_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__2));
v___x_409_ = lean_string_dec_eq(v_mode_403_, v___x_408_);
if (v___x_409_ == 0)
{
lean_object* v___x_410_; uint8_t v___x_411_; 
v___x_410_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__3));
v___x_411_ = lean_string_dec_eq(v_mode_403_, v___x_410_);
if (v___x_411_ == 0)
{
lean_object* v___x_412_; uint8_t v___x_413_; 
v___x_412_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__4));
v___x_413_ = lean_string_dec_eq(v_mode_403_, v___x_412_);
if (v___x_413_ == 0)
{
lean_object* v___x_414_; 
v___x_414_ = lean_box(0);
return v___x_414_;
}
else
{
lean_object* v___x_415_; 
v___x_415_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__5));
return v___x_415_;
}
}
else
{
lean_object* v___x_416_; 
v___x_416_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__6));
return v___x_416_;
}
}
else
{
lean_object* v___x_417_; 
v___x_417_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__7));
return v___x_417_;
}
}
else
{
lean_object* v___x_418_; 
v___x_418_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__8));
return v___x_418_;
}
}
else
{
lean_object* v___x_419_; 
v___x_419_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__9));
return v___x_419_;
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___boxed(lean_object* v_mode_420_){
_start:
{
lean_object* v_res_421_; 
v_res_421_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister(v_mode_420_);
lean_dec_ref(v_mode_420_);
return v_res_421_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(uint8_t v_enabled_423_, lean_object* v_expected_424_){
_start:
{
if (v_enabled_423_ == 0)
{
lean_object* v___x_426_; lean_object* v___x_427_; 
v___x_426_ = lean_box(0);
v___x_427_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_427_, 0, v___x_426_);
return v___x_427_;
}
else
{
lean_object* v___x_428_; lean_object* v_getLine_429_; lean_object* v___x_430_; 
v___x_428_ = lean_get_stdin();
v_getLine_429_ = lean_ctor_get(v___x_428_, 3);
lean_inc_ref(v_getLine_429_);
lean_dec_ref(v___x_428_);
v___x_430_ = lean_apply_1(v_getLine_429_, lean_box(0));
if (lean_obj_tag(v___x_430_) == 0)
{
lean_object* v_a_431_; lean_object* v___x_433_; uint8_t v_isShared_434_; uint8_t v_isSharedCheck_451_; 
v_a_431_ = lean_ctor_get(v___x_430_, 0);
v_isSharedCheck_451_ = !lean_is_exclusive(v___x_430_);
if (v_isSharedCheck_451_ == 0)
{
v___x_433_ = v___x_430_;
v_isShared_434_ = v_isSharedCheck_451_;
goto v_resetjp_432_;
}
else
{
lean_inc(v_a_431_);
lean_dec(v___x_430_);
v___x_433_ = lean_box(0);
v_isShared_434_ = v_isSharedCheck_451_;
goto v_resetjp_432_;
}
v_resetjp_432_:
{
lean_object* v___x_435_; lean_object* v___x_436_; lean_object* v___x_437_; lean_object* v___x_438_; lean_object* v___x_439_; uint8_t v___x_440_; 
v___x_435_ = lean_unsigned_to_nat(0u);
v___x_436_ = lean_string_utf8_byte_size(v_a_431_);
v___x_437_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_437_, 0, v_a_431_);
lean_ctor_set(v___x_437_, 1, v___x_435_);
lean_ctor_set(v___x_437_, 2, v___x_436_);
v___x_438_ = l_String_Slice_trimAscii(v___x_437_);
v___x_439_ = l_String_Slice_toString(v___x_438_);
lean_dec_ref(v___x_438_);
v___x_440_ = lean_string_dec_eq(v___x_439_, v_expected_424_);
lean_dec_ref(v___x_439_);
if (v___x_440_ == 0)
{
lean_object* v___x_441_; lean_object* v___x_442_; lean_object* v___x_443_; lean_object* v___x_445_; 
v___x_441_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command___closed__0));
v___x_442_ = lean_string_append(v___x_441_, v_expected_424_);
v___x_443_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_443_, 0, v___x_442_);
if (v_isShared_434_ == 0)
{
lean_ctor_set_tag(v___x_433_, 1);
lean_ctor_set(v___x_433_, 0, v___x_443_);
v___x_445_ = v___x_433_;
goto v_reusejp_444_;
}
else
{
lean_object* v_reuseFailAlloc_446_; 
v_reuseFailAlloc_446_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_446_, 0, v___x_443_);
v___x_445_ = v_reuseFailAlloc_446_;
goto v_reusejp_444_;
}
v_reusejp_444_:
{
return v___x_445_;
}
}
else
{
lean_object* v___x_447_; lean_object* v___x_449_; 
v___x_447_ = lean_box(0);
if (v_isShared_434_ == 0)
{
lean_ctor_set(v___x_433_, 0, v___x_447_);
v___x_449_ = v___x_433_;
goto v_reusejp_448_;
}
else
{
lean_object* v_reuseFailAlloc_450_; 
v_reuseFailAlloc_450_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_450_, 0, v___x_447_);
v___x_449_ = v_reuseFailAlloc_450_;
goto v_reusejp_448_;
}
v_reusejp_448_:
{
return v___x_449_;
}
}
}
}
else
{
lean_object* v_a_452_; lean_object* v___x_454_; uint8_t v_isShared_455_; uint8_t v_isSharedCheck_459_; 
v_a_452_ = lean_ctor_get(v___x_430_, 0);
v_isSharedCheck_459_ = !lean_is_exclusive(v___x_430_);
if (v_isSharedCheck_459_ == 0)
{
v___x_454_ = v___x_430_;
v_isShared_455_ = v_isSharedCheck_459_;
goto v_resetjp_453_;
}
else
{
lean_inc(v_a_452_);
lean_dec(v___x_430_);
v___x_454_ = lean_box(0);
v_isShared_455_ = v_isSharedCheck_459_;
goto v_resetjp_453_;
}
v_resetjp_453_:
{
lean_object* v___x_457_; 
if (v_isShared_455_ == 0)
{
v___x_457_ = v___x_454_;
goto v_reusejp_456_;
}
else
{
lean_object* v_reuseFailAlloc_458_; 
v_reuseFailAlloc_458_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_458_, 0, v_a_452_);
v___x_457_ = v_reuseFailAlloc_458_;
goto v_reusejp_456_;
}
v_reusejp_456_:
{
return v___x_457_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command___boxed(lean_object* v_enabled_460_, lean_object* v_expected_461_, lean_object* v_a_462_){
_start:
{
uint8_t v_enabled_boxed_463_; lean_object* v_res_464_; 
v_enabled_boxed_463_ = lean_unbox(v_enabled_460_);
v_res_464_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_enabled_boxed_463_, v_expected_461_);
lean_dec_ref(v_expected_461_);
return v_res_464_;
}
}
static uint64_t _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_offsetBasis(void){
_start:
{
uint64_t v___x_465_; 
v___x_465_ = 14695981039346656037ULL;
return v___x_465_;
}
}
static uint64_t _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prime(void){
_start:
{
uint64_t v___x_466_; 
v___x_466_ = 1099511628211ULL;
return v___x_466_;
}
}
LEAN_EXPORT uint64_t l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(lean_object* v_as_467_, size_t v_i_468_, size_t v_stop_469_, uint64_t v_b_470_){
_start:
{
uint8_t v___x_471_; 
v___x_471_ = lean_usize_dec_eq(v_i_468_, v_stop_469_);
if (v___x_471_ == 0)
{
lean_object* v___x_472_; uint8_t v___x_473_; uint64_t v___x_474_; uint64_t v___x_475_; uint64_t v___x_476_; uint64_t v___x_477_; size_t v___x_478_; size_t v___x_479_; 
v___x_472_ = lean_array_uget_borrowed(v_as_467_, v_i_468_);
v___x_473_ = lean_unbox(v___x_472_);
v___x_474_ = lean_uint8_to_uint64(v___x_473_);
v___x_475_ = lean_uint64_xor(v_b_470_, v___x_474_);
v___x_476_ = 1099511628211ULL;
v___x_477_ = lean_uint64_mul(v___x_475_, v___x_476_);
v___x_478_ = ((size_t)1ULL);
v___x_479_ = lean_usize_add(v_i_468_, v___x_478_);
v_i_468_ = v___x_479_;
v_b_470_ = v___x_477_;
goto _start;
}
else
{
return v_b_470_;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0___boxed(lean_object* v_as_481_, lean_object* v_i_482_, lean_object* v_stop_483_, lean_object* v_b_484_){
_start:
{
size_t v_i_boxed_485_; size_t v_stop_boxed_486_; uint64_t v_b_boxed_487_; uint64_t v_res_488_; lean_object* v_r_489_; 
v_i_boxed_485_ = lean_unbox_usize(v_i_482_);
lean_dec(v_i_482_);
v_stop_boxed_486_ = lean_unbox_usize(v_stop_483_);
lean_dec(v_stop_483_);
v_b_boxed_487_ = lean_unbox_uint64(v_b_484_);
lean_dec_ref(v_b_484_);
v_res_488_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(v_as_481_, v_i_boxed_485_, v_stop_boxed_486_, v_b_boxed_487_);
lean_dec_ref(v_as_481_);
v_r_489_ = lean_box_uint64(v_res_488_);
return v_r_489_;
}
}
LEAN_EXPORT uint64_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes(uint64_t v_hash_490_, lean_object* v_bytes_491_){
_start:
{
lean_object* v___x_492_; lean_object* v___x_493_; lean_object* v___x_494_; uint8_t v___x_495_; 
v___x_492_ = lean_byte_array_data(v_bytes_491_);
v___x_493_ = lean_unsigned_to_nat(0u);
v___x_494_ = lean_array_get_size(v___x_492_);
v___x_495_ = lean_nat_dec_lt(v___x_493_, v___x_494_);
if (v___x_495_ == 0)
{
lean_dec_ref(v___x_492_);
return v_hash_490_;
}
else
{
uint8_t v___x_496_; 
v___x_496_ = lean_nat_dec_le(v___x_494_, v___x_494_);
if (v___x_496_ == 0)
{
if (v___x_495_ == 0)
{
lean_dec_ref(v___x_492_);
return v_hash_490_;
}
else
{
size_t v___x_497_; size_t v___x_498_; uint64_t v___x_499_; 
v___x_497_ = ((size_t)0ULL);
v___x_498_ = lean_usize_of_nat(v___x_494_);
v___x_499_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(v___x_492_, v___x_497_, v___x_498_, v_hash_490_);
lean_dec_ref(v___x_492_);
return v___x_499_;
}
}
else
{
size_t v___x_500_; size_t v___x_501_; uint64_t v___x_502_; 
v___x_500_ = ((size_t)0ULL);
v___x_501_ = lean_usize_of_nat(v___x_494_);
v___x_502_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(v___x_492_, v___x_500_, v___x_501_, v_hash_490_);
lean_dec_ref(v___x_492_);
return v___x_502_;
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes___boxed(lean_object* v_hash_503_, lean_object* v_bytes_504_){
_start:
{
uint64_t v_hash_boxed_505_; uint64_t v_res_506_; lean_object* v_r_507_; 
v_hash_boxed_505_ = lean_unbox_uint64(v_hash_503_);
lean_dec_ref(v_hash_503_);
v_res_506_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes(v_hash_boxed_505_, v_bytes_504_);
v_r_507_ = lean_box_uint64(v_res_506_);
return v_r_507_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(lean_object* v_digest_508_, lean_object* v_bytes_509_){
_start:
{
lean_object* v_count_510_; lean_object* v_bytes_511_; uint64_t v_value_512_; lean_object* v___x_514_; uint8_t v_isShared_515_; uint8_t v_isSharedCheck_524_; 
v_count_510_ = lean_ctor_get(v_digest_508_, 0);
v_bytes_511_ = lean_ctor_get(v_digest_508_, 1);
v_value_512_ = lean_ctor_get_uint64(v_digest_508_, sizeof(void*)*2);
v_isSharedCheck_524_ = !lean_is_exclusive(v_digest_508_);
if (v_isSharedCheck_524_ == 0)
{
v___x_514_ = v_digest_508_;
v_isShared_515_ = v_isSharedCheck_524_;
goto v_resetjp_513_;
}
else
{
lean_inc(v_bytes_511_);
lean_inc(v_count_510_);
lean_dec(v_digest_508_);
v___x_514_ = lean_box(0);
v_isShared_515_ = v_isSharedCheck_524_;
goto v_resetjp_513_;
}
v_resetjp_513_:
{
lean_object* v___x_516_; lean_object* v___x_517_; lean_object* v___x_518_; lean_object* v___x_519_; uint64_t v___x_520_; lean_object* v___x_522_; 
v___x_516_ = lean_unsigned_to_nat(1u);
v___x_517_ = lean_nat_add(v_count_510_, v___x_516_);
lean_dec(v_count_510_);
v___x_518_ = lean_byte_array_size(v_bytes_509_);
v___x_519_ = lean_nat_add(v_bytes_511_, v___x_518_);
lean_dec(v_bytes_511_);
v___x_520_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes(v_value_512_, v_bytes_509_);
if (v_isShared_515_ == 0)
{
lean_ctor_set(v___x_514_, 1, v___x_519_);
lean_ctor_set(v___x_514_, 0, v___x_517_);
v___x_522_ = v___x_514_;
goto v_reusejp_521_;
}
else
{
lean_object* v_reuseFailAlloc_523_; 
v_reuseFailAlloc_523_ = lean_alloc_ctor(0, 2, 8);
lean_ctor_set(v_reuseFailAlloc_523_, 0, v___x_517_);
lean_ctor_set(v_reuseFailAlloc_523_, 1, v___x_519_);
v___x_522_ = v_reuseFailAlloc_523_;
goto v_reusejp_521_;
}
v_reusejp_521_:
{
lean_ctor_set_uint64(v___x_522_, sizeof(void*)*2, v___x_520_);
return v___x_522_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__1(lean_object* v_a_525_, lean_object* v_a_526_){
_start:
{
if (lean_obj_tag(v_a_525_) == 0)
{
lean_object* v___x_527_; 
v___x_527_ = l_List_reverse___redArg(v_a_526_);
return v___x_527_;
}
else
{
lean_object* v_head_528_; lean_object* v_tail_529_; lean_object* v___x_531_; uint8_t v_isShared_532_; uint8_t v_isSharedCheck_538_; 
v_head_528_ = lean_ctor_get(v_a_525_, 0);
v_tail_529_ = lean_ctor_get(v_a_525_, 1);
v_isSharedCheck_538_ = !lean_is_exclusive(v_a_525_);
if (v_isSharedCheck_538_ == 0)
{
v___x_531_ = v_a_525_;
v_isShared_532_ = v_isSharedCheck_538_;
goto v_resetjp_530_;
}
else
{
lean_inc(v_tail_529_);
lean_inc(v_head_528_);
lean_dec(v_a_525_);
v___x_531_ = lean_box(0);
v_isShared_532_ = v_isSharedCheck_538_;
goto v_resetjp_530_;
}
v_resetjp_530_:
{
lean_object* v_count_533_; lean_object* v___x_535_; 
v_count_533_ = lean_ctor_get(v_head_528_, 0);
lean_inc(v_count_533_);
lean_dec(v_head_528_);
if (v_isShared_532_ == 0)
{
lean_ctor_set(v___x_531_, 1, v_a_526_);
lean_ctor_set(v___x_531_, 0, v_count_533_);
v___x_535_ = v___x_531_;
goto v_reusejp_534_;
}
else
{
lean_object* v_reuseFailAlloc_537_; 
v_reuseFailAlloc_537_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_537_, 0, v_count_533_);
lean_ctor_set(v_reuseFailAlloc_537_, 1, v_a_526_);
v___x_535_ = v_reuseFailAlloc_537_;
goto v_reusejp_534_;
}
v_reusejp_534_:
{
v_a_525_ = v_tail_529_;
v_a_526_ = v___x_535_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(lean_object* v_inputs_542_, lean_object* v_output_543_, lean_object* v_range_544_, lean_object* v_b_545_, lean_object* v_i_546_){
_start:
{
lean_object* v_stop_548_; lean_object* v_step_549_; uint8_t v___x_550_; 
v_stop_548_ = lean_ctor_get(v_range_544_, 1);
v_step_549_ = lean_ctor_get(v_range_544_, 2);
v___x_550_ = lean_nat_dec_lt(v_i_546_, v_stop_548_);
if (v___x_550_ == 0)
{
lean_object* v___x_551_; 
lean_dec(v_i_546_);
v___x_551_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_551_, 0, v_b_545_);
return v___x_551_;
}
else
{
lean_object* v___x_552_; uint8_t v___x_553_; 
v___x_552_ = lean_array_get_size(v_inputs_542_);
v___x_553_ = lean_nat_dec_lt(v_i_546_, v___x_552_);
if (v___x_553_ == 0)
{
lean_object* v___x_554_; lean_object* v___x_555_; 
lean_dec(v_i_546_);
lean_dec_ref(v_b_545_);
v___x_554_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___closed__1));
v___x_555_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_555_, 0, v___x_554_);
return v___x_555_;
}
else
{
lean_object* v_fst_556_; lean_object* v_snd_557_; lean_object* v___x_559_; uint8_t v_isShared_560_; uint8_t v_isSharedCheck_586_; 
v_fst_556_ = lean_ctor_get(v_b_545_, 0);
v_snd_557_ = lean_ctor_get(v_b_545_, 1);
v_isSharedCheck_586_ = !lean_is_exclusive(v_b_545_);
if (v_isSharedCheck_586_ == 0)
{
v___x_559_ = v_b_545_;
v_isShared_560_ = v_isSharedCheck_586_;
goto v_resetjp_558_;
}
else
{
lean_inc(v_snd_557_);
lean_inc(v_fst_556_);
lean_dec(v_b_545_);
v___x_559_ = lean_box(0);
v_isShared_560_ = v_isSharedCheck_586_;
goto v_resetjp_558_;
}
v_resetjp_558_:
{
lean_object* v___x_561_; lean_object* v___x_562_; lean_object* v___x_563_; lean_object* v___x_564_; lean_object* v___x_565_; lean_object* v___x_566_; lean_object* v_df_567_; lean_object* v___x_568_; lean_object* v___x_569_; lean_object* v_bytes_570_; lean_object* v_total_571_; lean_object* v___y_573_; lean_object* v___x_579_; uint8_t v___x_580_; 
v___x_561_ = lean_array_fget_borrowed(v_inputs_542_, v_i_546_);
v___x_562_ = lean_array_fget_borrowed(v_output_543_, v_i_546_);
v___x_563_ = lean_unsigned_to_nat(0u);
lean_inc(v___x_562_);
v___x_564_ = lp_lean1090_Lean1090_Spec_instReprMessage_repr___redArg(v___x_562_);
v___x_565_ = lean_unsigned_to_nat(120u);
v___x_566_ = l_Std_Format_pretty(v___x_564_, v___x_565_, v___x_563_, v___x_563_);
v_df_567_ = lean_ctor_get(v___x_561_, 0);
v___x_568_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__0));
v___x_569_ = lean_string_append(v___x_566_, v___x_568_);
v_bytes_570_ = lean_string_to_utf8(v___x_569_);
lean_dec_ref(v___x_569_);
lean_inc_ref(v_bytes_570_);
v_total_571_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(v_fst_556_, v_bytes_570_);
v___x_579_ = lean_array_get_size(v_snd_557_);
v___x_580_ = lean_nat_dec_lt(v_df_567_, v___x_579_);
if (v___x_580_ == 0)
{
lean_dec_ref(v_bytes_570_);
v___y_573_ = v_snd_557_;
goto v___jp_572_;
}
else
{
lean_object* v_v_581_; lean_object* v___x_582_; lean_object* v_xs_x27_583_; lean_object* v___x_584_; lean_object* v___x_585_; 
v_v_581_ = lean_array_fget(v_snd_557_, v_df_567_);
v___x_582_ = lean_box(0);
v_xs_x27_583_ = lean_array_fset(v_snd_557_, v_df_567_, v___x_582_);
v___x_584_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(v_v_581_, v_bytes_570_);
v___x_585_ = lean_array_fset(v_xs_x27_583_, v_df_567_, v___x_584_);
v___y_573_ = v___x_585_;
goto v___jp_572_;
}
v___jp_572_:
{
lean_object* v___x_575_; 
if (v_isShared_560_ == 0)
{
lean_ctor_set(v___x_559_, 1, v___y_573_);
lean_ctor_set(v___x_559_, 0, v_total_571_);
v___x_575_ = v___x_559_;
goto v_reusejp_574_;
}
else
{
lean_object* v_reuseFailAlloc_578_; 
v_reuseFailAlloc_578_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_578_, 0, v_total_571_);
lean_ctor_set(v_reuseFailAlloc_578_, 1, v___y_573_);
v___x_575_ = v_reuseFailAlloc_578_;
goto v_reusejp_574_;
}
v_reusejp_574_:
{
lean_object* v___x_576_; 
v___x_576_ = lean_nat_add(v_i_546_, v_step_549_);
lean_dec(v_i_546_);
v_b_545_ = v___x_575_;
v_i_546_ = v___x_576_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___boxed(lean_object* v_inputs_587_, lean_object* v_output_588_, lean_object* v_range_589_, lean_object* v_b_590_, lean_object* v_i_591_, lean_object* v___y_592_){
_start:
{
lean_object* v_res_593_; 
v_res_593_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(v_inputs_587_, v_output_588_, v_range_589_, v_b_590_, v_i_591_);
lean_dec_ref(v_range_589_);
lean_dec_ref(v_output_588_);
lean_dec_ref(v_inputs_587_);
return v_res_593_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3(void){
_start:
{
lean_object* v_total_600_; lean_object* v___x_601_; lean_object* v_byDF_602_; 
v_total_600_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__2));
v___x_601_ = lean_unsigned_to_nat(32u);
v_byDF_602_ = lean_mk_array(v___x_601_, v_total_600_);
return v_byDF_602_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4(void){
_start:
{
lean_object* v_byDF_603_; lean_object* v_total_604_; lean_object* v___x_605_; 
v_byDF_603_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3);
v_total_604_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__2));
v___x_605_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_605_, 0, v_total_604_);
lean_ctor_set(v___x_605_, 1, v_byDF_603_);
return v___x_605_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume(lean_object* v_inputs_609_, lean_object* v_output_610_){
_start:
{
lean_object* v___x_612_; lean_object* v___x_613_; uint8_t v___x_614_; 
v___x_612_ = lean_array_get_size(v_output_610_);
v___x_613_ = lean_array_get_size(v_inputs_609_);
v___x_614_ = lean_nat_dec_eq(v___x_612_, v___x_613_);
if (v___x_614_ == 0)
{
lean_object* v___x_615_; lean_object* v___x_616_; 
v___x_615_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__1));
v___x_616_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_616_, 0, v___x_615_);
return v___x_616_;
}
else
{
lean_object* v___x_617_; lean_object* v___x_618_; lean_object* v___x_619_; lean_object* v___x_620_; lean_object* v___x_621_; 
v___x_617_ = lean_unsigned_to_nat(0u);
v___x_618_ = lean_unsigned_to_nat(1u);
v___x_619_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_619_, 0, v___x_617_);
lean_ctor_set(v___x_619_, 1, v___x_612_);
lean_ctor_set(v___x_619_, 2, v___x_618_);
v___x_620_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4);
v___x_621_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(v_inputs_609_, v_output_610_, v___x_619_, v___x_620_, v___x_617_);
lean_dec_ref_known(v___x_619_, 3);
if (lean_obj_tag(v___x_621_) == 0)
{
lean_object* v_a_622_; lean_object* v___x_624_; uint8_t v_isShared_625_; uint8_t v_isSharedCheck_647_; 
v_a_622_ = lean_ctor_get(v___x_621_, 0);
v_isSharedCheck_647_ = !lean_is_exclusive(v___x_621_);
if (v_isSharedCheck_647_ == 0)
{
v___x_624_ = v___x_621_;
v_isShared_625_ = v_isSharedCheck_647_;
goto v_resetjp_623_;
}
else
{
lean_inc(v_a_622_);
lean_dec(v___x_621_);
v___x_624_ = lean_box(0);
v_isShared_625_ = v_isSharedCheck_647_;
goto v_resetjp_623_;
}
v_resetjp_623_:
{
lean_object* v_fst_626_; lean_object* v_snd_627_; lean_object* v___x_629_; uint8_t v_isShared_630_; uint8_t v_isSharedCheck_646_; 
v_fst_626_ = lean_ctor_get(v_a_622_, 0);
v_snd_627_ = lean_ctor_get(v_a_622_, 1);
v_isSharedCheck_646_ = !lean_is_exclusive(v_a_622_);
if (v_isSharedCheck_646_ == 0)
{
v___x_629_ = v_a_622_;
v_isShared_630_ = v_isSharedCheck_646_;
goto v_resetjp_628_;
}
else
{
lean_inc(v_snd_627_);
lean_inc(v_fst_626_);
lean_dec(v_a_622_);
v___x_629_ = lean_box(0);
v_isShared_630_ = v_isSharedCheck_646_;
goto v_resetjp_628_;
}
v_resetjp_628_:
{
lean_object* v___x_631_; lean_object* v___x_632_; lean_object* v___x_633_; lean_object* v___x_634_; uint8_t v___x_635_; 
lean_inc(v_snd_627_);
v___x_631_ = lean_array_to_list(v_snd_627_);
v___x_632_ = lean_box(0);
v___x_633_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__1(v___x_631_, v___x_632_);
v___x_634_ = l_List_sum___at___00Lean_PersistentHashMap_subarrayMeasure_spec__2(v___x_633_);
lean_dec(v___x_633_);
v___x_635_ = lean_nat_dec_eq(v___x_634_, v___x_612_);
lean_dec(v___x_634_);
if (v___x_635_ == 0)
{
lean_object* v___x_636_; lean_object* v___x_638_; 
lean_del_object(v___x_629_);
lean_dec(v_snd_627_);
lean_dec(v_fst_626_);
v___x_636_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__6));
if (v_isShared_625_ == 0)
{
lean_ctor_set_tag(v___x_624_, 1);
lean_ctor_set(v___x_624_, 0, v___x_636_);
v___x_638_ = v___x_624_;
goto v_reusejp_637_;
}
else
{
lean_object* v_reuseFailAlloc_639_; 
v_reuseFailAlloc_639_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_639_, 0, v___x_636_);
v___x_638_ = v_reuseFailAlloc_639_;
goto v_reusejp_637_;
}
v_reusejp_637_:
{
return v___x_638_;
}
}
else
{
lean_object* v___x_641_; 
if (v_isShared_630_ == 0)
{
v___x_641_ = v___x_629_;
goto v_reusejp_640_;
}
else
{
lean_object* v_reuseFailAlloc_645_; 
v_reuseFailAlloc_645_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_645_, 0, v_fst_626_);
lean_ctor_set(v_reuseFailAlloc_645_, 1, v_snd_627_);
v___x_641_ = v_reuseFailAlloc_645_;
goto v_reusejp_640_;
}
v_reusejp_640_:
{
lean_object* v___x_643_; 
if (v_isShared_625_ == 0)
{
lean_ctor_set(v___x_624_, 0, v___x_641_);
v___x_643_ = v___x_624_;
goto v_reusejp_642_;
}
else
{
lean_object* v_reuseFailAlloc_644_; 
v_reuseFailAlloc_644_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_644_, 0, v___x_641_);
v___x_643_ = v_reuseFailAlloc_644_;
goto v_reusejp_642_;
}
v_reusejp_642_:
{
return v___x_643_;
}
}
}
}
}
}
else
{
return v___x_621_;
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___boxed(lean_object* v_inputs_648_, lean_object* v_output_649_, lean_object* v_a_650_){
_start:
{
lean_object* v_res_651_; 
v_res_651_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume(v_inputs_648_, v_output_649_);
lean_dec_ref(v_output_649_);
lean_dec_ref(v_inputs_648_);
return v_res_651_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0(lean_object* v_inputs_652_, lean_object* v_output_653_, lean_object* v_range_654_, lean_object* v_b_655_, lean_object* v_i_656_, lean_object* v_hs_657_, lean_object* v_hl_658_){
_start:
{
lean_object* v___x_660_; 
v___x_660_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(v_inputs_652_, v_output_653_, v_range_654_, v_b_655_, v_i_656_);
return v___x_660_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___boxed(lean_object* v_inputs_661_, lean_object* v_output_662_, lean_object* v_range_663_, lean_object* v_b_664_, lean_object* v_i_665_, lean_object* v_hs_666_, lean_object* v_hl_667_, lean_object* v___y_668_){
_start:
{
lean_object* v_res_669_; 
v_res_669_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0(v_inputs_661_, v_output_662_, v_range_663_, v_b_664_, v_i_665_, v_hs_666_, v_hl_667_);
lean_dec_ref(v_range_663_);
lean_dec_ref(v_output_662_);
lean_dec_ref(v_inputs_661_);
return v_res_669_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(lean_object* v_digest_673_){
_start:
{
lean_object* v_count_674_; lean_object* v_bytes_675_; uint64_t v_value_676_; lean_object* v___x_677_; lean_object* v___x_678_; lean_object* v___x_679_; lean_object* v___x_680_; lean_object* v___x_681_; lean_object* v___x_682_; lean_object* v___x_683_; lean_object* v___x_684_; lean_object* v___x_685_; lean_object* v___x_686_; lean_object* v___x_687_; lean_object* v___x_688_; lean_object* v___x_689_; lean_object* v___x_690_; lean_object* v___x_691_; lean_object* v___x_692_; lean_object* v___x_693_; lean_object* v___x_694_; 
v_count_674_ = lean_ctor_get(v_digest_673_, 0);
lean_inc(v_count_674_);
v_bytes_675_ = lean_ctor_get(v_digest_673_, 1);
lean_inc(v_bytes_675_);
v_value_676_ = lean_ctor_get_uint64(v_digest_673_, sizeof(void*)*2);
lean_dec_ref(v_digest_673_);
v___x_677_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0));
v___x_678_ = l_Lean_JsonNumber_fromNat(v_count_674_);
v___x_679_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_679_, 0, v___x_678_);
v___x_680_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_680_, 0, v___x_677_);
lean_ctor_set(v___x_680_, 1, v___x_679_);
v___x_681_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__1));
v___x_682_ = l_Lean_JsonNumber_fromNat(v_bytes_675_);
v___x_683_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_683_, 0, v___x_682_);
v___x_684_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_684_, 0, v___x_681_);
lean_ctor_set(v___x_684_, 1, v___x_683_);
v___x_685_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__2));
v___x_686_ = lean_uint64_to_nat(v_value_676_);
v___x_687_ = l_Lean_JsonNumber_fromNat(v___x_686_);
v___x_688_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_688_, 0, v___x_687_);
v___x_689_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_689_, 0, v___x_685_);
lean_ctor_set(v___x_689_, 1, v___x_688_);
v___x_690_ = lean_box(0);
v___x_691_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_691_, 0, v___x_689_);
lean_ctor_set(v___x_691_, 1, v___x_690_);
v___x_692_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_692_, 0, v___x_684_);
lean_ctor_set(v___x_692_, 1, v___x_691_);
v___x_693_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_693_, 0, v___x_680_);
lean_ctor_set(v___x_693_, 1, v___x_692_);
v___x_694_ = l_Lean_Json_mkObj(v___x_693_);
lean_dec_ref_known(v___x_693_, 2);
return v___x_694_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0(lean_object* v_as_696_, size_t v_sz_697_, size_t v_i_698_, lean_object* v_b_699_){
_start:
{
uint8_t v___x_701_; 
v___x_701_ = lean_usize_dec_lt(v_i_698_, v_sz_697_);
if (v___x_701_ == 0)
{
lean_object* v___x_702_; 
v___x_702_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_702_, 0, v_b_699_);
return v___x_702_;
}
else
{
lean_object* v_a_703_; lean_object* v_df_704_; lean_object* v_bytes_705_; lean_object* v___x_706_; 
v_a_703_ = lean_array_uget_borrowed(v_as_696_, v_i_698_);
v_df_704_ = lean_ctor_get(v_a_703_, 0);
v_bytes_705_ = lean_ctor_get(v_a_703_, 1);
v___x_706_ = lp_lean1090_Lean1090_Impl_decode(v_bytes_705_);
if (lean_obj_tag(v___x_706_) == 1)
{
lean_object* v_val_707_; lean_object* v___x_708_; size_t v___x_709_; size_t v___x_710_; 
v_val_707_ = lean_ctor_get(v___x_706_, 0);
lean_inc(v_val_707_);
lean_dec_ref_known(v___x_706_, 1);
v___x_708_ = lean_array_push(v_b_699_, v_val_707_);
v___x_709_ = ((size_t)1ULL);
v___x_710_ = lean_usize_add(v_i_698_, v___x_709_);
v_i_698_ = v___x_710_;
v_b_699_ = v___x_708_;
goto _start;
}
else
{
lean_object* v___x_712_; lean_object* v___x_713_; lean_object* v___x_714_; lean_object* v___x_715_; lean_object* v___x_716_; 
lean_dec(v___x_706_);
lean_dec_ref(v_b_699_);
v___x_712_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0___closed__0));
lean_inc(v_df_704_);
v___x_713_ = l_Nat_reprFast(v_df_704_);
v___x_714_ = lean_string_append(v___x_712_, v___x_713_);
lean_dec_ref(v___x_713_);
v___x_715_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_715_, 0, v___x_714_);
v___x_716_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_716_, 0, v___x_715_);
return v___x_716_;
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0___boxed(lean_object* v_as_717_, lean_object* v_sz_718_, lean_object* v_i_719_, lean_object* v_b_720_, lean_object* v___y_721_){
_start:
{
size_t v_sz_boxed_722_; size_t v_i_boxed_723_; lean_object* v_res_724_; 
v_sz_boxed_722_ = lean_unbox_usize(v_sz_718_);
lean_dec(v_sz_718_);
v_i_boxed_723_ = lean_unbox_usize(v_i_719_);
lean_dec(v_i_719_);
v_res_724_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0(v_as_717_, v_sz_boxed_722_, v_i_boxed_723_, v_b_720_);
lean_dec_ref(v_as_717_);
return v_res_724_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode(lean_object* v_inputs_725_){
_start:
{
lean_object* v___x_727_; lean_object* v_output_728_; lean_object* v___x_729_; size_t v_sz_730_; size_t v___x_731_; lean_object* v___x_732_; 
v___x_727_ = lean_array_get_size(v_inputs_725_);
v_output_728_ = lean_mk_empty_array_with_capacity(v___x_727_);
v___x_729_ = lean_io_get_num_heartbeats();
v_sz_730_ = lean_array_size(v_inputs_725_);
v___x_731_ = ((size_t)0ULL);
v___x_732_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0(v_inputs_725_, v_sz_730_, v___x_731_, v_output_728_);
if (lean_obj_tag(v___x_732_) == 0)
{
lean_object* v_a_733_; lean_object* v___x_735_; uint8_t v_isShared_736_; uint8_t v_isSharedCheck_743_; 
v_a_733_ = lean_ctor_get(v___x_732_, 0);
v_isSharedCheck_743_ = !lean_is_exclusive(v___x_732_);
if (v_isSharedCheck_743_ == 0)
{
v___x_735_ = v___x_732_;
v_isShared_736_ = v_isSharedCheck_743_;
goto v_resetjp_734_;
}
else
{
lean_inc(v_a_733_);
lean_dec(v___x_732_);
v___x_735_ = lean_box(0);
v_isShared_736_ = v_isSharedCheck_743_;
goto v_resetjp_734_;
}
v_resetjp_734_:
{
lean_object* v___x_737_; lean_object* v___x_738_; lean_object* v___x_739_; lean_object* v___x_741_; 
v___x_737_ = lean_io_get_num_heartbeats();
v___x_738_ = lean_nat_sub(v___x_737_, v___x_729_);
lean_dec(v___x_729_);
lean_dec(v___x_737_);
v___x_739_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_739_, 0, v_a_733_);
lean_ctor_set(v___x_739_, 1, v___x_738_);
if (v_isShared_736_ == 0)
{
lean_ctor_set(v___x_735_, 0, v___x_739_);
v___x_741_ = v___x_735_;
goto v_reusejp_740_;
}
else
{
lean_object* v_reuseFailAlloc_742_; 
v_reuseFailAlloc_742_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_742_, 0, v___x_739_);
v___x_741_ = v_reuseFailAlloc_742_;
goto v_reusejp_740_;
}
v_reusejp_740_:
{
return v___x_741_;
}
}
}
else
{
lean_object* v_a_744_; lean_object* v___x_746_; uint8_t v_isShared_747_; uint8_t v_isSharedCheck_751_; 
lean_dec(v___x_729_);
v_a_744_ = lean_ctor_get(v___x_732_, 0);
v_isSharedCheck_751_ = !lean_is_exclusive(v___x_732_);
if (v_isSharedCheck_751_ == 0)
{
v___x_746_ = v___x_732_;
v_isShared_747_ = v_isSharedCheck_751_;
goto v_resetjp_745_;
}
else
{
lean_inc(v_a_744_);
lean_dec(v___x_732_);
v___x_746_ = lean_box(0);
v_isShared_747_ = v_isSharedCheck_751_;
goto v_resetjp_745_;
}
v_resetjp_745_:
{
lean_object* v___x_749_; 
if (v_isShared_747_ == 0)
{
v___x_749_ = v___x_746_;
goto v_reusejp_748_;
}
else
{
lean_object* v_reuseFailAlloc_750_; 
v_reuseFailAlloc_750_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_750_, 0, v_a_744_);
v___x_749_ = v_reuseFailAlloc_750_;
goto v_reusejp_748_;
}
v_reusejp_748_:
{
return v___x_749_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode___boxed(lean_object* v_inputs_752_, lean_object* v_a_753_){
_start:
{
lean_object* v_res_754_; 
v_res_754_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode(v_inputs_752_);
lean_dec_ref(v_inputs_752_);
return v_res_754_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_bump(lean_object* v_values_755_, lean_object* v_key_756_){
_start:
{
if (lean_obj_tag(v_values_755_) == 0)
{
lean_object* v___x_757_; lean_object* v___x_758_; lean_object* v___x_759_; 
v___x_757_ = lean_unsigned_to_nat(1u);
v___x_758_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_758_, 0, v_key_756_);
lean_ctor_set(v___x_758_, 1, v___x_757_);
v___x_759_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_759_, 0, v___x_758_);
lean_ctor_set(v___x_759_, 1, v_values_755_);
return v___x_759_;
}
else
{
lean_object* v_head_760_; lean_object* v_tail_761_; lean_object* v___x_763_; uint8_t v_isShared_764_; uint8_t v_isSharedCheck_786_; 
v_head_760_ = lean_ctor_get(v_values_755_, 0);
v_tail_761_ = lean_ctor_get(v_values_755_, 1);
v_isSharedCheck_786_ = !lean_is_exclusive(v_values_755_);
if (v_isSharedCheck_786_ == 0)
{
v___x_763_ = v_values_755_;
v_isShared_764_ = v_isSharedCheck_786_;
goto v_resetjp_762_;
}
else
{
lean_inc(v_tail_761_);
lean_inc(v_head_760_);
lean_dec(v_values_755_);
v___x_763_ = lean_box(0);
v_isShared_764_ = v_isSharedCheck_786_;
goto v_resetjp_762_;
}
v_resetjp_762_:
{
lean_object* v_fst_765_; lean_object* v_snd_766_; uint8_t v___x_767_; 
v_fst_765_ = lean_ctor_get(v_head_760_, 0);
v_snd_766_ = lean_ctor_get(v_head_760_, 1);
v___x_767_ = lean_nat_dec_eq(v_fst_765_, v_key_756_);
if (v___x_767_ == 0)
{
lean_object* v___x_768_; lean_object* v___x_770_; 
v___x_768_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_bump(v_tail_761_, v_key_756_);
if (v_isShared_764_ == 0)
{
lean_ctor_set(v___x_763_, 1, v___x_768_);
v___x_770_ = v___x_763_;
goto v_reusejp_769_;
}
else
{
lean_object* v_reuseFailAlloc_771_; 
v_reuseFailAlloc_771_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_771_, 0, v_head_760_);
lean_ctor_set(v_reuseFailAlloc_771_, 1, v___x_768_);
v___x_770_ = v_reuseFailAlloc_771_;
goto v_reusejp_769_;
}
v_reusejp_769_:
{
return v___x_770_;
}
}
else
{
lean_object* v___x_773_; uint8_t v_isShared_774_; uint8_t v_isSharedCheck_783_; 
lean_inc(v_snd_766_);
lean_inc(v_fst_765_);
lean_dec(v_key_756_);
v_isSharedCheck_783_ = !lean_is_exclusive(v_head_760_);
if (v_isSharedCheck_783_ == 0)
{
lean_object* v_unused_784_; lean_object* v_unused_785_; 
v_unused_784_ = lean_ctor_get(v_head_760_, 1);
lean_dec(v_unused_784_);
v_unused_785_ = lean_ctor_get(v_head_760_, 0);
lean_dec(v_unused_785_);
v___x_773_ = v_head_760_;
v_isShared_774_ = v_isSharedCheck_783_;
goto v_resetjp_772_;
}
else
{
lean_dec(v_head_760_);
v___x_773_ = lean_box(0);
v_isShared_774_ = v_isSharedCheck_783_;
goto v_resetjp_772_;
}
v_resetjp_772_:
{
lean_object* v___x_775_; lean_object* v___x_776_; lean_object* v___x_778_; 
v___x_775_ = lean_unsigned_to_nat(1u);
v___x_776_ = lean_nat_add(v_snd_766_, v___x_775_);
lean_dec(v_snd_766_);
if (v_isShared_774_ == 0)
{
lean_ctor_set(v___x_773_, 1, v___x_776_);
v___x_778_ = v___x_773_;
goto v_reusejp_777_;
}
else
{
lean_object* v_reuseFailAlloc_782_; 
v_reuseFailAlloc_782_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_782_, 0, v_fst_765_);
lean_ctor_set(v_reuseFailAlloc_782_, 1, v___x_776_);
v___x_778_ = v_reuseFailAlloc_782_;
goto v_reusejp_777_;
}
v_reusejp_777_:
{
lean_object* v___x_780_; 
if (v_isShared_764_ == 0)
{
lean_ctor_set(v___x_763_, 0, v___x_778_);
v___x_780_ = v___x_763_;
goto v_reusejp_779_;
}
else
{
lean_object* v_reuseFailAlloc_781_; 
v_reuseFailAlloc_781_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_781_, 0, v___x_778_);
lean_ctor_set(v_reuseFailAlloc_781_, 1, v_tail_761_);
v___x_780_ = v_reuseFailAlloc_781_;
goto v_reusejp_779_;
}
v_reusejp_779_:
{
return v___x_780_;
}
}
}
}
}
}
}
}
LEAN_EXPORT uint8_t l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0(lean_object* v_register_803_, lean_object* v_x_804_){
_start:
{
if (lean_obj_tag(v_x_804_) == 0)
{
uint8_t v___x_805_; 
v___x_805_ = 0;
return v___x_805_;
}
else
{
lean_object* v_head_806_; lean_object* v_tail_807_; lean_object* v_fst_808_; uint8_t v___x_809_; 
v_head_806_ = lean_ctor_get(v_x_804_, 0);
v_tail_807_ = lean_ctor_get(v_x_804_, 1);
v_fst_808_ = lean_ctor_get(v_head_806_, 0);
v___x_809_ = lean_nat_dec_eq(v_fst_808_, v_register_803_);
if (v___x_809_ == 0)
{
v_x_804_ = v_tail_807_;
goto _start;
}
else
{
return v___x_809_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0___boxed(lean_object* v_register_811_, lean_object* v_x_812_){
_start:
{
uint8_t v_res_813_; lean_object* v_r_814_; 
v_res_813_ = l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0(v_register_811_, v_x_812_);
lean_dec(v_x_812_);
lean_dec(v_register_811_);
v_r_814_ = lean_box(v_res_813_);
return v_r_814_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(lean_object* v_register_821_, lean_object* v_df_822_, lean_object* v_as_x27_823_, lean_object* v_b_824_){
_start:
{
if (lean_obj_tag(v_as_x27_823_) == 0)
{
lean_object* v___x_826_; 
lean_dec(v_df_822_);
lean_dec(v_register_821_);
v___x_826_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_826_, 0, v_b_824_);
return v___x_826_;
}
else
{
lean_object* v_head_827_; lean_object* v_tail_828_; uint8_t v___y_830_; uint8_t v___y_831_; uint8_t v___y_832_; uint8_t v___y_833_; uint8_t v___y_834_; uint8_t v___y_835_; uint8_t v___y_836_; lean_object* v_fields_866_; lean_object* v_body_867_; 
v_head_827_ = lean_ctor_get(v_as_x27_823_, 0);
v_tail_828_ = lean_ctor_get(v_as_x27_823_, 1);
v_fields_866_ = lean_ctor_get(v_head_827_, 0);
v_body_867_ = lean_ctor_get(v_fields_866_, 0);
if (lean_obj_tag(v_body_867_) == 6)
{
lean_object* v_decoded_868_; lean_object* v_mb_869_; uint8_t v___y_871_; uint8_t v___y_872_; uint8_t v___y_873_; uint8_t v___y_874_; uint8_t v___y_875_; uint8_t v___y_876_; uint8_t v___y_877_; uint8_t v___y_878_; uint8_t v___y_893_; uint8_t v___y_894_; uint8_t v___y_895_; uint8_t v___y_896_; uint8_t v___y_897_; uint8_t v___y_898_; uint8_t v___y_902_; uint8_t v___y_903_; lean_object* v___y_904_; uint8_t v___y_905_; uint8_t v___y_906_; uint8_t v___y_907_; lean_object* v___y_916_; uint8_t v___y_917_; uint8_t v___y_918_; lean_object* v___y_924_; uint8_t v___y_925_; uint8_t v___y_926_; lean_object* v___x_927_; uint8_t v___x_928_; 
v_decoded_868_ = lean_ctor_get(v_head_827_, 1);
v_mb_869_ = lean_ctor_get(v_body_867_, 1);
v___x_927_ = lean_unsigned_to_nat(0u);
v___x_928_ = lean_nat_dec_eq(v_mb_869_, v___x_927_);
if (v___x_928_ == 0)
{
uint8_t v___x_929_; lean_object* v___x_930_; uint8_t v___x_931_; 
v___x_929_ = 1;
v___x_930_ = lean_unsigned_to_nat(5u);
v___x_931_ = lean_nat_dec_eq(v_register_821_, v___x_930_);
if (v___x_931_ == 0)
{
lean_object* v___x_932_; uint8_t v___x_933_; 
v___x_932_ = lean_unsigned_to_nat(101u);
v___x_933_ = lean_nat_dec_eq(v_register_821_, v___x_932_);
if (v___x_933_ == 0)
{
v___y_916_ = v___x_930_;
v___y_917_ = v___x_929_;
v___y_918_ = v___x_929_;
goto v___jp_915_;
}
else
{
v___y_924_ = v___x_930_;
v___y_925_ = v___x_929_;
v___y_926_ = v___x_931_;
goto v___jp_923_;
}
}
else
{
lean_object* v___x_934_; uint8_t v___x_935_; 
v___x_934_ = lean_unsigned_to_nat(20u);
v___x_935_ = lean_nat_dec_eq(v_df_822_, v___x_934_);
if (v___x_935_ == 0)
{
v___y_924_ = v___x_930_;
v___y_925_ = v___x_929_;
v___y_926_ = v___x_935_;
goto v___jp_923_;
}
else
{
lean_object* v___x_936_; lean_object* v___x_937_; lean_object* v___x_938_; uint8_t v___x_939_; 
v___x_936_ = lean_unsigned_to_nat(1u);
v___x_937_ = lp_lean1090_Lean1090_Impl_payloadBits(v_mb_869_, v___x_936_, v___x_930_);
v___x_938_ = lean_unsigned_to_nat(9u);
v___x_939_ = lean_nat_dec_le(v___x_938_, v___x_937_);
if (v___x_939_ == 0)
{
lean_dec(v___x_937_);
v___y_924_ = v___x_930_;
v___y_925_ = v___x_929_;
v___y_926_ = v___x_939_;
goto v___jp_923_;
}
else
{
lean_object* v___x_940_; uint8_t v___x_941_; 
v___x_940_ = lean_unsigned_to_nat(22u);
v___x_941_ = lean_nat_dec_lt(v___x_937_, v___x_940_);
if (v___x_941_ == 0)
{
lean_dec(v___x_937_);
v___y_924_ = v___x_930_;
v___y_925_ = v___x_929_;
v___y_926_ = v___x_941_;
goto v___jp_923_;
}
else
{
lean_object* v___x_942_; uint8_t v___x_943_; 
v___x_942_ = lean_unsigned_to_nat(19u);
v___x_943_ = lean_nat_dec_eq(v___x_937_, v___x_942_);
lean_dec(v___x_937_);
if (v___x_943_ == 0)
{
v___y_924_ = v___x_930_;
v___y_925_ = v___x_929_;
v___y_926_ = v___x_931_;
goto v___jp_923_;
}
else
{
v___y_893_ = v___x_928_;
v___y_894_ = v___x_928_;
v___y_895_ = v___x_928_;
v___y_896_ = v___x_928_;
v___y_897_ = v___x_929_;
v___y_898_ = v___x_928_;
goto v___jp_892_;
}
}
}
}
}
}
else
{
uint8_t v___x_944_; 
v___x_944_ = 0;
v___y_893_ = v___x_944_;
v___y_894_ = v___x_944_;
v___y_895_ = v___x_944_;
v___y_896_ = v___x_944_;
v___y_897_ = v___x_944_;
v___y_898_ = v___x_944_;
goto v___jp_892_;
}
v___jp_870_:
{
if (v___y_878_ == 0)
{
lean_object* v___x_879_; lean_object* v___x_880_; lean_object* v___x_881_; lean_object* v___x_882_; lean_object* v___x_883_; lean_object* v___x_884_; lean_object* v___x_885_; lean_object* v___x_886_; lean_object* v___x_887_; lean_object* v___x_888_; lean_object* v___x_889_; lean_object* v___x_890_; lean_object* v___x_891_; 
lean_dec_ref(v_b_824_);
v___x_879_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__0));
v___x_880_ = l_Nat_reprFast(v_df_822_);
v___x_881_ = lean_string_append(v___x_879_, v___x_880_);
lean_dec_ref(v___x_880_);
v___x_882_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__1));
v___x_883_ = lean_string_append(v___x_881_, v___x_882_);
v___x_884_ = l_Nat_reprFast(v_register_821_);
v___x_885_ = lean_string_append(v___x_883_, v___x_884_);
lean_dec_ref(v___x_884_);
v___x_886_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__2));
v___x_887_ = lean_string_append(v___x_885_, v___x_886_);
lean_inc(v_mb_869_);
v___x_888_ = l_Nat_reprFast(v_mb_869_);
v___x_889_ = lean_string_append(v___x_887_, v___x_888_);
lean_dec_ref(v___x_888_);
v___x_890_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_890_, 0, v___x_889_);
v___x_891_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_891_, 0, v___x_890_);
return v___x_891_;
}
else
{
v___y_830_ = v___y_871_;
v___y_831_ = v___y_872_;
v___y_832_ = v___y_873_;
v___y_833_ = v___y_874_;
v___y_834_ = v___y_875_;
v___y_835_ = v___y_876_;
v___y_836_ = v___y_877_;
goto v___jp_829_;
}
}
v___jp_892_:
{
lean_object* v_commB_899_; uint8_t v___x_900_; 
v_commB_899_ = lean_ctor_get(v_decoded_868_, 6);
v___x_900_ = l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0(v_register_821_, v_commB_899_);
if (v___x_900_ == 0)
{
if (v___y_898_ == 0)
{
v___y_830_ = v___y_893_;
v___y_831_ = v___y_894_;
v___y_832_ = v___y_898_;
v___y_833_ = v___y_895_;
v___y_834_ = v___y_896_;
v___y_835_ = v___x_900_;
v___y_836_ = v___y_897_;
goto v___jp_829_;
}
else
{
v___y_871_ = v___y_893_;
v___y_872_ = v___y_894_;
v___y_873_ = v___y_898_;
v___y_874_ = v___y_895_;
v___y_875_ = v___y_896_;
v___y_876_ = v___x_900_;
v___y_877_ = v___y_897_;
v___y_878_ = v___x_900_;
goto v___jp_870_;
}
}
else
{
v___y_871_ = v___y_893_;
v___y_872_ = v___y_894_;
v___y_873_ = v___y_898_;
v___y_874_ = v___y_895_;
v___y_875_ = v___y_896_;
v___y_876_ = v___x_900_;
v___y_877_ = v___y_897_;
v___y_878_ = v___y_898_;
goto v___jp_870_;
}
}
v___jp_901_:
{
if (v___y_905_ == 0)
{
v___y_893_ = v___y_902_;
v___y_894_ = v___y_903_;
v___y_895_ = v___y_905_;
v___y_896_ = v___y_907_;
v___y_897_ = v___y_906_;
v___y_898_ = v___y_905_;
goto v___jp_892_;
}
else
{
uint8_t v___x_908_; 
v___x_908_ = lean_nat_dec_eq(v_register_821_, v___y_904_);
if (v___x_908_ == 0)
{
lean_object* v___x_909_; uint8_t v___x_910_; 
v___x_909_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored));
v___x_910_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_821_, v___x_909_);
if (v___x_910_ == 0)
{
v___y_893_ = v___y_902_;
v___y_894_ = v___y_903_;
v___y_895_ = v___y_905_;
v___y_896_ = v___y_907_;
v___y_897_ = v___y_906_;
v___y_898_ = v___y_905_;
goto v___jp_892_;
}
else
{
v___y_893_ = v___y_902_;
v___y_894_ = v___y_903_;
v___y_895_ = v___y_905_;
v___y_896_ = v___y_907_;
v___y_897_ = v___y_906_;
v___y_898_ = v___y_907_;
goto v___jp_892_;
}
}
else
{
lean_object* v___x_911_; lean_object* v___x_912_; lean_object* v___x_913_; uint8_t v___x_914_; 
v___x_911_ = lean_alloc_closure((void*)(l_Int_instDecidableEq___boxed), 2, 0);
v___x_912_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_mb_869_);
v___x_913_ = lp_lean1090_Lean1090_Impl_frameOracleAltitude(v_fields_866_);
v___x_914_ = l_Option_instDecidableEq___redArg(v___x_911_, v___x_912_, v___x_913_);
v___y_893_ = v___y_902_;
v___y_894_ = v___y_903_;
v___y_895_ = v___y_905_;
v___y_896_ = v___y_907_;
v___y_897_ = v___y_906_;
v___y_898_ = v___x_914_;
goto v___jp_892_;
}
}
}
v___jp_915_:
{
uint8_t v___x_919_; 
v___x_919_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_821_, v_mb_869_);
if (v___x_919_ == 0)
{
v___y_902_ = v___y_918_;
v___y_903_ = v___x_919_;
v___y_904_ = v___y_916_;
v___y_905_ = v___x_919_;
v___y_906_ = v___y_917_;
v___y_907_ = v___x_919_;
goto v___jp_901_;
}
else
{
lean_object* v___x_920_; uint8_t v___x_921_; 
v___x_920_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored));
v___x_921_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_821_, v___x_920_);
if (v___x_921_ == 0)
{
v___y_902_ = v___y_918_;
v___y_903_ = v___x_921_;
v___y_904_ = v___y_916_;
v___y_905_ = v___x_919_;
v___y_906_ = v___y_917_;
v___y_907_ = v___x_921_;
goto v___jp_901_;
}
else
{
uint8_t v___x_922_; 
v___x_922_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_821_, v_mb_869_);
v___y_902_ = v___y_918_;
v___y_903_ = v___x_921_;
v___y_904_ = v___y_916_;
v___y_905_ = v___x_919_;
v___y_906_ = v___y_917_;
v___y_907_ = v___x_922_;
goto v___jp_901_;
}
}
}
v___jp_923_:
{
if (v___y_926_ == 0)
{
v___y_893_ = v___y_926_;
v___y_894_ = v___y_926_;
v___y_895_ = v___y_926_;
v___y_896_ = v___y_926_;
v___y_897_ = v___y_925_;
v___y_898_ = v___y_926_;
goto v___jp_892_;
}
else
{
v___y_916_ = v___y_924_;
v___y_917_ = v___y_925_;
v___y_918_ = v___y_926_;
goto v___jp_915_;
}
}
}
else
{
lean_object* v___x_945_; lean_object* v___x_946_; 
lean_dec_ref(v_b_824_);
lean_dec(v_df_822_);
lean_dec(v_register_821_);
v___x_945_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__4));
v___x_946_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_946_, 0, v___x_945_);
return v___x_946_;
}
v___jp_829_:
{
lean_object* v_nonempty_837_; lean_object* v_hardAttempts_838_; lean_object* v_hardPass_839_; lean_object* v_scoreAttempts_840_; lean_object* v_scorePass_841_; lean_object* v_eligible_842_; lean_object* v_accepted_843_; lean_object* v___x_845_; uint8_t v_isShared_846_; uint8_t v_isSharedCheck_865_; 
v_nonempty_837_ = lean_ctor_get(v_b_824_, 0);
v_hardAttempts_838_ = lean_ctor_get(v_b_824_, 1);
v_hardPass_839_ = lean_ctor_get(v_b_824_, 2);
v_scoreAttempts_840_ = lean_ctor_get(v_b_824_, 3);
v_scorePass_841_ = lean_ctor_get(v_b_824_, 4);
v_eligible_842_ = lean_ctor_get(v_b_824_, 5);
v_accepted_843_ = lean_ctor_get(v_b_824_, 6);
v_isSharedCheck_865_ = !lean_is_exclusive(v_b_824_);
if (v_isSharedCheck_865_ == 0)
{
v___x_845_ = v_b_824_;
v_isShared_846_ = v_isSharedCheck_865_;
goto v_resetjp_844_;
}
else
{
lean_inc(v_accepted_843_);
lean_inc(v_eligible_842_);
lean_inc(v_scorePass_841_);
lean_inc(v_scoreAttempts_840_);
lean_inc(v_hardPass_839_);
lean_inc(v_hardAttempts_838_);
lean_inc(v_nonempty_837_);
lean_dec(v_b_824_);
v___x_845_ = lean_box(0);
v_isShared_846_ = v_isSharedCheck_865_;
goto v_resetjp_844_;
}
v_resetjp_844_:
{
lean_object* v___x_847_; lean_object* v___x_848_; lean_object* v___x_849_; lean_object* v___x_850_; lean_object* v___x_851_; lean_object* v___x_852_; lean_object* v___x_853_; lean_object* v___x_854_; lean_object* v___x_855_; lean_object* v___x_856_; lean_object* v___x_857_; lean_object* v___x_858_; lean_object* v___x_859_; lean_object* v___x_860_; lean_object* v___x_862_; 
v___x_847_ = l_Bool_toNat(v___y_836_);
v___x_848_ = lean_nat_add(v_nonempty_837_, v___x_847_);
lean_dec(v___x_847_);
lean_dec(v_nonempty_837_);
v___x_849_ = l_Bool_toNat(v___y_830_);
v___x_850_ = lean_nat_add(v_hardAttempts_838_, v___x_849_);
lean_dec(v___x_849_);
lean_dec(v_hardAttempts_838_);
v___x_851_ = l_Bool_toNat(v___y_833_);
v___x_852_ = lean_nat_add(v_hardPass_839_, v___x_851_);
lean_dec(v___x_851_);
lean_dec(v_hardPass_839_);
v___x_853_ = l_Bool_toNat(v___y_831_);
v___x_854_ = lean_nat_add(v_scoreAttempts_840_, v___x_853_);
lean_dec(v___x_853_);
lean_dec(v_scoreAttempts_840_);
v___x_855_ = l_Bool_toNat(v___y_834_);
v___x_856_ = lean_nat_add(v_scorePass_841_, v___x_855_);
lean_dec(v___x_855_);
lean_dec(v_scorePass_841_);
v___x_857_ = l_Bool_toNat(v___y_832_);
v___x_858_ = lean_nat_add(v_eligible_842_, v___x_857_);
lean_dec(v___x_857_);
lean_dec(v_eligible_842_);
v___x_859_ = l_Bool_toNat(v___y_835_);
v___x_860_ = lean_nat_add(v_accepted_843_, v___x_859_);
lean_dec(v___x_859_);
lean_dec(v_accepted_843_);
if (v_isShared_846_ == 0)
{
lean_ctor_set(v___x_845_, 6, v___x_860_);
lean_ctor_set(v___x_845_, 5, v___x_858_);
lean_ctor_set(v___x_845_, 4, v___x_856_);
lean_ctor_set(v___x_845_, 3, v___x_854_);
lean_ctor_set(v___x_845_, 2, v___x_852_);
lean_ctor_set(v___x_845_, 1, v___x_850_);
lean_ctor_set(v___x_845_, 0, v___x_848_);
v___x_862_ = v___x_845_;
goto v_reusejp_861_;
}
else
{
lean_object* v_reuseFailAlloc_864_; 
v_reuseFailAlloc_864_ = lean_alloc_ctor(0, 7, 0);
lean_ctor_set(v_reuseFailAlloc_864_, 0, v___x_848_);
lean_ctor_set(v_reuseFailAlloc_864_, 1, v___x_850_);
lean_ctor_set(v_reuseFailAlloc_864_, 2, v___x_852_);
lean_ctor_set(v_reuseFailAlloc_864_, 3, v___x_854_);
lean_ctor_set(v_reuseFailAlloc_864_, 4, v___x_856_);
lean_ctor_set(v_reuseFailAlloc_864_, 5, v___x_858_);
lean_ctor_set(v_reuseFailAlloc_864_, 6, v___x_860_);
v___x_862_ = v_reuseFailAlloc_864_;
goto v_reusejp_861_;
}
v_reusejp_861_:
{
v_as_x27_823_ = v_tail_828_;
v_b_824_ = v___x_862_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___boxed(lean_object* v_register_947_, lean_object* v_df_948_, lean_object* v_as_x27_949_, lean_object* v_b_950_, lean_object* v___y_951_){
_start:
{
lean_object* v_res_952_; 
v_res_952_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(v_register_947_, v_df_948_, v_as_x27_949_, v_b_950_);
lean_dec(v_as_x27_949_);
return v_res_952_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus(lean_object* v_df_955_, lean_object* v_register_956_, lean_object* v_messages_957_){
_start:
{
lean_object* v_count_959_; lean_object* v___x_960_; 
v_count_959_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus___closed__0));
v___x_960_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(v_register_956_, v_df_955_, v_messages_957_, v_count_959_);
return v___x_960_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus___boxed(lean_object* v_df_961_, lean_object* v_register_962_, lean_object* v_messages_963_, lean_object* v_a_964_){
_start:
{
lean_object* v_res_965_; 
v_res_965_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus(v_df_961_, v_register_962_, v_messages_963_);
lean_dec(v_messages_963_);
return v_res_965_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1(lean_object* v_register_966_, lean_object* v_df_967_, lean_object* v_as_968_, lean_object* v_as_x27_969_, lean_object* v_b_970_, lean_object* v_a_971_){
_start:
{
lean_object* v___x_973_; 
v___x_973_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(v_register_966_, v_df_967_, v_as_x27_969_, v_b_970_);
return v___x_973_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___boxed(lean_object* v_register_974_, lean_object* v_df_975_, lean_object* v_as_976_, lean_object* v_as_x27_977_, lean_object* v_b_978_, lean_object* v_a_979_, lean_object* v___y_980_){
_start:
{
lean_object* v_res_981_; 
v_res_981_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1(v_register_974_, v_df_975_, v_as_976_, v_as_x27_977_, v_b_978_, v_a_979_);
lean_dec(v_as_x27_977_);
lean_dec(v_as_976_);
return v_res_981_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(lean_object* v_a_992_, lean_object* v_a_993_, lean_object* v_as_x27_994_, lean_object* v_b_995_){
_start:
{
if (lean_obj_tag(v_as_x27_994_) == 0)
{
lean_object* v___x_997_; 
lean_dec(v_a_992_);
v___x_997_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_997_, 0, v_b_995_);
return v___x_997_;
}
else
{
lean_object* v_head_998_; lean_object* v_tail_999_; lean_object* v_rows_1000_; lean_object* v___x_1001_; 
v_head_998_ = lean_ctor_get(v_as_x27_994_, 0);
v_tail_999_ = lean_ctor_get(v_as_x27_994_, 1);
v_rows_1000_ = lean_box(0);
lean_inc(v_head_998_);
lean_inc(v_a_992_);
v___x_1001_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus(v_a_992_, v_head_998_, v_a_993_);
if (lean_obj_tag(v___x_1001_) == 0)
{
lean_object* v_a_1002_; lean_object* v_nonempty_1003_; lean_object* v_hardAttempts_1004_; lean_object* v_hardPass_1005_; lean_object* v_scoreAttempts_1006_; lean_object* v_scorePass_1007_; lean_object* v_eligible_1008_; lean_object* v_accepted_1009_; lean_object* v___x_1010_; lean_object* v___x_1011_; lean_object* v___x_1012_; lean_object* v___x_1013_; lean_object* v___x_1014_; lean_object* v___x_1015_; lean_object* v___x_1016_; lean_object* v___x_1017_; lean_object* v___x_1018_; lean_object* v___x_1019_; lean_object* v___x_1020_; lean_object* v___x_1021_; lean_object* v___x_1022_; lean_object* v___x_1023_; lean_object* v___x_1024_; lean_object* v___x_1025_; lean_object* v___x_1026_; lean_object* v___x_1027_; lean_object* v___x_1028_; lean_object* v___x_1029_; lean_object* v___x_1030_; lean_object* v___x_1031_; lean_object* v___x_1032_; lean_object* v___x_1033_; lean_object* v___x_1034_; lean_object* v___x_1035_; lean_object* v___x_1036_; lean_object* v___x_1037_; lean_object* v___x_1038_; lean_object* v___x_1039_; lean_object* v___x_1040_; lean_object* v___x_1041_; lean_object* v___x_1042_; lean_object* v___x_1043_; lean_object* v___x_1044_; lean_object* v___x_1045_; lean_object* v___x_1046_; lean_object* v___x_1047_; lean_object* v___x_1048_; lean_object* v___x_1049_; lean_object* v___x_1050_; lean_object* v___x_1051_; lean_object* v___x_1052_; lean_object* v___x_1053_; lean_object* v___x_1054_; lean_object* v___x_1055_; lean_object* v___x_1056_; lean_object* v___x_1057_; lean_object* v___x_1058_; lean_object* v___x_1059_; lean_object* v___x_1060_; lean_object* v___x_1061_; 
v_a_1002_ = lean_ctor_get(v___x_1001_, 0);
lean_inc(v_a_1002_);
lean_dec_ref_known(v___x_1001_, 1);
v_nonempty_1003_ = lean_ctor_get(v_a_1002_, 0);
lean_inc(v_nonempty_1003_);
v_hardAttempts_1004_ = lean_ctor_get(v_a_1002_, 1);
lean_inc(v_hardAttempts_1004_);
v_hardPass_1005_ = lean_ctor_get(v_a_1002_, 2);
lean_inc(v_hardPass_1005_);
v_scoreAttempts_1006_ = lean_ctor_get(v_a_1002_, 3);
lean_inc(v_scoreAttempts_1006_);
v_scorePass_1007_ = lean_ctor_get(v_a_1002_, 4);
lean_inc(v_scorePass_1007_);
v_eligible_1008_ = lean_ctor_get(v_a_1002_, 5);
lean_inc(v_eligible_1008_);
v_accepted_1009_ = lean_ctor_get(v_a_1002_, 6);
lean_inc(v_accepted_1009_);
lean_dec(v_a_1002_);
v___x_1010_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__0));
lean_inc(v_head_998_);
v___x_1011_ = l_Lean_JsonNumber_fromNat(v_head_998_);
v___x_1012_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1012_, 0, v___x_1011_);
v___x_1013_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1013_, 0, v___x_1010_);
lean_ctor_set(v___x_1013_, 1, v___x_1012_);
v___x_1014_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__1));
v___x_1015_ = l_List_lengthTR___redArg(v_a_993_);
v___x_1016_ = l_Lean_JsonNumber_fromNat(v___x_1015_);
v___x_1017_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1017_, 0, v___x_1016_);
v___x_1018_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1018_, 0, v___x_1014_);
lean_ctor_set(v___x_1018_, 1, v___x_1017_);
v___x_1019_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__2));
v___x_1020_ = l_Lean_JsonNumber_fromNat(v_nonempty_1003_);
v___x_1021_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1021_, 0, v___x_1020_);
v___x_1022_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1022_, 0, v___x_1019_);
lean_ctor_set(v___x_1022_, 1, v___x_1021_);
v___x_1023_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__3));
v___x_1024_ = l_Lean_JsonNumber_fromNat(v_hardAttempts_1004_);
v___x_1025_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1025_, 0, v___x_1024_);
v___x_1026_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1026_, 0, v___x_1023_);
lean_ctor_set(v___x_1026_, 1, v___x_1025_);
v___x_1027_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__4));
v___x_1028_ = l_Lean_JsonNumber_fromNat(v_hardPass_1005_);
v___x_1029_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1029_, 0, v___x_1028_);
v___x_1030_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1030_, 0, v___x_1027_);
lean_ctor_set(v___x_1030_, 1, v___x_1029_);
v___x_1031_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__5));
v___x_1032_ = l_Lean_JsonNumber_fromNat(v_scoreAttempts_1006_);
v___x_1033_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1033_, 0, v___x_1032_);
v___x_1034_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1034_, 0, v___x_1031_);
lean_ctor_set(v___x_1034_, 1, v___x_1033_);
v___x_1035_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__6));
v___x_1036_ = l_Lean_JsonNumber_fromNat(v_scorePass_1007_);
v___x_1037_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1037_, 0, v___x_1036_);
v___x_1038_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1038_, 0, v___x_1035_);
lean_ctor_set(v___x_1038_, 1, v___x_1037_);
v___x_1039_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__7));
v___x_1040_ = l_Lean_JsonNumber_fromNat(v_eligible_1008_);
v___x_1041_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1041_, 0, v___x_1040_);
v___x_1042_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1042_, 0, v___x_1039_);
lean_ctor_set(v___x_1042_, 1, v___x_1041_);
v___x_1043_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__8));
v___x_1044_ = l_Lean_JsonNumber_fromNat(v_accepted_1009_);
v___x_1045_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1045_, 0, v___x_1044_);
lean_inc_ref(v___x_1045_);
v___x_1046_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1046_, 0, v___x_1043_);
lean_ctor_set(v___x_1046_, 1, v___x_1045_);
v___x_1047_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__9));
v___x_1048_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1048_, 0, v___x_1047_);
lean_ctor_set(v___x_1048_, 1, v___x_1045_);
v___x_1049_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1049_, 0, v___x_1048_);
lean_ctor_set(v___x_1049_, 1, v_rows_1000_);
v___x_1050_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1050_, 0, v___x_1046_);
lean_ctor_set(v___x_1050_, 1, v___x_1049_);
v___x_1051_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1051_, 0, v___x_1042_);
lean_ctor_set(v___x_1051_, 1, v___x_1050_);
v___x_1052_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1052_, 0, v___x_1038_);
lean_ctor_set(v___x_1052_, 1, v___x_1051_);
v___x_1053_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1053_, 0, v___x_1034_);
lean_ctor_set(v___x_1053_, 1, v___x_1052_);
v___x_1054_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1054_, 0, v___x_1030_);
lean_ctor_set(v___x_1054_, 1, v___x_1053_);
v___x_1055_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1055_, 0, v___x_1026_);
lean_ctor_set(v___x_1055_, 1, v___x_1054_);
v___x_1056_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1056_, 0, v___x_1022_);
lean_ctor_set(v___x_1056_, 1, v___x_1055_);
v___x_1057_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1057_, 0, v___x_1018_);
lean_ctor_set(v___x_1057_, 1, v___x_1056_);
v___x_1058_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1058_, 0, v___x_1013_);
lean_ctor_set(v___x_1058_, 1, v___x_1057_);
v___x_1059_ = l_Lean_Json_mkObj(v___x_1058_);
lean_dec_ref_known(v___x_1058_, 2);
v___x_1060_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1060_, 0, v___x_1059_);
lean_ctor_set(v___x_1060_, 1, v_rows_1000_);
v___x_1061_ = l_List_appendTR___redArg(v_b_995_, v___x_1060_);
v_as_x27_994_ = v_tail_999_;
v_b_995_ = v___x_1061_;
goto _start;
}
else
{
lean_object* v_a_1063_; lean_object* v___x_1065_; uint8_t v_isShared_1066_; uint8_t v_isSharedCheck_1070_; 
lean_dec(v_b_995_);
lean_dec(v_a_992_);
v_a_1063_ = lean_ctor_get(v___x_1001_, 0);
v_isSharedCheck_1070_ = !lean_is_exclusive(v___x_1001_);
if (v_isSharedCheck_1070_ == 0)
{
v___x_1065_ = v___x_1001_;
v_isShared_1066_ = v_isSharedCheck_1070_;
goto v_resetjp_1064_;
}
else
{
lean_inc(v_a_1063_);
lean_dec(v___x_1001_);
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
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___boxed(lean_object* v_a_1071_, lean_object* v_a_1072_, lean_object* v_as_x27_1073_, lean_object* v_b_1074_, lean_object* v___y_1075_){
_start:
{
lean_object* v_res_1076_; 
v_res_1076_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(v_a_1071_, v_a_1072_, v_as_x27_1073_, v_b_1074_);
lean_dec(v_as_x27_1073_);
lean_dec(v_a_1072_);
return v_res_1076_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(lean_object* v_inputs_1080_, lean_object* v_a_1081_, lean_object* v_output_1082_, lean_object* v_range_1083_, lean_object* v_b_1084_, lean_object* v_i_1085_){
_start:
{
lean_object* v_stop_1087_; lean_object* v_step_1088_; lean_object* v_a_1090_; uint8_t v___x_1093_; 
v_stop_1087_ = lean_ctor_get(v_range_1083_, 1);
v_step_1088_ = lean_ctor_get(v_range_1083_, 2);
v___x_1093_ = lean_nat_dec_lt(v_i_1085_, v_stop_1087_);
if (v___x_1093_ == 0)
{
lean_object* v___x_1094_; 
lean_dec(v_i_1085_);
v___x_1094_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1094_, 0, v_b_1084_);
return v___x_1094_;
}
else
{
lean_object* v___x_1095_; uint8_t v___x_1096_; 
v___x_1095_ = lean_array_get_size(v_inputs_1080_);
v___x_1096_ = lean_nat_dec_lt(v_i_1085_, v___x_1095_);
if (v___x_1096_ == 0)
{
lean_object* v___x_1097_; lean_object* v___x_1098_; 
lean_dec(v_i_1085_);
lean_dec(v_b_1084_);
v___x_1097_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___closed__1));
v___x_1098_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1098_, 0, v___x_1097_);
return v___x_1098_;
}
else
{
lean_object* v___x_1099_; lean_object* v_df_1100_; lean_object* v___x_1102_; uint8_t v_isShared_1103_; uint8_t v_isSharedCheck_1109_; 
v___x_1099_ = lean_array_fget(v_inputs_1080_, v_i_1085_);
v_df_1100_ = lean_ctor_get(v___x_1099_, 0);
v_isSharedCheck_1109_ = !lean_is_exclusive(v___x_1099_);
if (v_isSharedCheck_1109_ == 0)
{
lean_object* v_unused_1110_; 
v_unused_1110_ = lean_ctor_get(v___x_1099_, 1);
lean_dec(v_unused_1110_);
v___x_1102_ = v___x_1099_;
v_isShared_1103_ = v_isSharedCheck_1109_;
goto v_resetjp_1101_;
}
else
{
lean_inc(v_df_1100_);
lean_dec(v___x_1099_);
v___x_1102_ = lean_box(0);
v_isShared_1103_ = v_isSharedCheck_1109_;
goto v_resetjp_1101_;
}
v_resetjp_1101_:
{
uint8_t v___x_1104_; 
v___x_1104_ = lean_nat_dec_eq(v_df_1100_, v_a_1081_);
lean_dec(v_df_1100_);
if (v___x_1104_ == 0)
{
lean_del_object(v___x_1102_);
v_a_1090_ = v_b_1084_;
goto v___jp_1089_;
}
else
{
lean_object* v___x_1105_; lean_object* v___x_1107_; 
v___x_1105_ = lean_array_fget_borrowed(v_output_1082_, v_i_1085_);
lean_inc(v___x_1105_);
if (v_isShared_1103_ == 0)
{
lean_ctor_set_tag(v___x_1102_, 1);
lean_ctor_set(v___x_1102_, 1, v_b_1084_);
lean_ctor_set(v___x_1102_, 0, v___x_1105_);
v___x_1107_ = v___x_1102_;
goto v_reusejp_1106_;
}
else
{
lean_object* v_reuseFailAlloc_1108_; 
v_reuseFailAlloc_1108_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1108_, 0, v___x_1105_);
lean_ctor_set(v_reuseFailAlloc_1108_, 1, v_b_1084_);
v___x_1107_ = v_reuseFailAlloc_1108_;
goto v_reusejp_1106_;
}
v_reusejp_1106_:
{
v_a_1090_ = v___x_1107_;
goto v___jp_1089_;
}
}
}
}
}
v___jp_1089_:
{
lean_object* v___x_1091_; 
v___x_1091_ = lean_nat_add(v_i_1085_, v_step_1088_);
lean_dec(v_i_1085_);
v_b_1084_ = v_a_1090_;
v_i_1085_ = v___x_1091_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___boxed(lean_object* v_inputs_1111_, lean_object* v_a_1112_, lean_object* v_output_1113_, lean_object* v_range_1114_, lean_object* v_b_1115_, lean_object* v_i_1116_, lean_object* v___y_1117_){
_start:
{
lean_object* v_res_1118_; 
v_res_1118_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(v_inputs_1111_, v_a_1112_, v_output_1113_, v_range_1114_, v_b_1115_, v_i_1116_);
lean_dec_ref(v_range_1114_);
lean_dec_ref(v_output_1113_);
lean_dec(v_a_1112_);
lean_dec_ref(v_inputs_1111_);
return v_res_1118_;
}
}
LEAN_EXPORT uint8_t l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___lam__0(lean_object* v_a_1119_, lean_object* v_b_1120_){
_start:
{
lean_object* v_fst_1121_; lean_object* v_fst_1122_; uint8_t v___x_1123_; 
v_fst_1121_ = lean_ctor_get(v_a_1119_, 0);
v_fst_1122_ = lean_ctor_get(v_b_1120_, 0);
v___x_1123_ = lean_nat_dec_le(v_fst_1121_, v_fst_1122_);
return v___x_1123_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___lam__0___boxed(lean_object* v_a_1124_, lean_object* v_b_1125_){
_start:
{
uint8_t v_res_1126_; lean_object* v_r_1127_; 
v_res_1126_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___lam__0(v_a_1124_, v_b_1125_);
lean_dec_ref(v_b_1125_);
lean_dec_ref(v_a_1124_);
v_r_1127_ = lean_box(v_res_1126_);
return v_r_1127_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3(lean_object* v_a_1129_, lean_object* v_a_1130_){
_start:
{
if (lean_obj_tag(v_a_1129_) == 0)
{
lean_object* v___x_1131_; 
v___x_1131_ = l_List_reverse___redArg(v_a_1130_);
return v___x_1131_;
}
else
{
lean_object* v_head_1132_; lean_object* v_tail_1133_; lean_object* v___x_1135_; uint8_t v_isShared_1136_; uint8_t v_isSharedCheck_1161_; 
v_head_1132_ = lean_ctor_get(v_a_1129_, 0);
v_tail_1133_ = lean_ctor_get(v_a_1129_, 1);
v_isSharedCheck_1161_ = !lean_is_exclusive(v_a_1129_);
if (v_isSharedCheck_1161_ == 0)
{
v___x_1135_ = v_a_1129_;
v_isShared_1136_ = v_isSharedCheck_1161_;
goto v_resetjp_1134_;
}
else
{
lean_inc(v_tail_1133_);
lean_inc(v_head_1132_);
lean_dec(v_a_1129_);
v___x_1135_ = lean_box(0);
v_isShared_1136_ = v_isSharedCheck_1161_;
goto v_resetjp_1134_;
}
v_resetjp_1134_:
{
lean_object* v_fst_1137_; lean_object* v_snd_1138_; lean_object* v___x_1140_; uint8_t v_isShared_1141_; uint8_t v_isSharedCheck_1160_; 
v_fst_1137_ = lean_ctor_get(v_head_1132_, 0);
v_snd_1138_ = lean_ctor_get(v_head_1132_, 1);
v_isSharedCheck_1160_ = !lean_is_exclusive(v_head_1132_);
if (v_isSharedCheck_1160_ == 0)
{
v___x_1140_ = v_head_1132_;
v_isShared_1141_ = v_isSharedCheck_1160_;
goto v_resetjp_1139_;
}
else
{
lean_inc(v_snd_1138_);
lean_inc(v_fst_1137_);
lean_dec(v_head_1132_);
v___x_1140_ = lean_box(0);
v_isShared_1141_ = v_isSharedCheck_1160_;
goto v_resetjp_1139_;
}
v_resetjp_1139_:
{
lean_object* v___x_1142_; lean_object* v___x_1143_; lean_object* v___x_1144_; lean_object* v___x_1145_; lean_object* v___x_1147_; 
v___x_1142_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0));
v___x_1143_ = ((lean_object*)(l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3___closed__0));
v___x_1144_ = l_Lean_JsonNumber_fromNat(v_fst_1137_);
v___x_1145_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1145_, 0, v___x_1144_);
if (v_isShared_1141_ == 0)
{
lean_ctor_set(v___x_1140_, 1, v___x_1145_);
lean_ctor_set(v___x_1140_, 0, v___x_1143_);
v___x_1147_ = v___x_1140_;
goto v_reusejp_1146_;
}
else
{
lean_object* v_reuseFailAlloc_1159_; 
v_reuseFailAlloc_1159_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1159_, 0, v___x_1143_);
lean_ctor_set(v_reuseFailAlloc_1159_, 1, v___x_1145_);
v___x_1147_ = v_reuseFailAlloc_1159_;
goto v_reusejp_1146_;
}
v_reusejp_1146_:
{
lean_object* v___x_1148_; lean_object* v___x_1149_; lean_object* v___x_1150_; lean_object* v___x_1151_; lean_object* v___x_1153_; 
v___x_1148_ = l_Lean_JsonNumber_fromNat(v_snd_1138_);
v___x_1149_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1149_, 0, v___x_1148_);
v___x_1150_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1150_, 0, v___x_1142_);
lean_ctor_set(v___x_1150_, 1, v___x_1149_);
v___x_1151_ = lean_box(0);
if (v_isShared_1136_ == 0)
{
lean_ctor_set(v___x_1135_, 1, v___x_1151_);
lean_ctor_set(v___x_1135_, 0, v___x_1150_);
v___x_1153_ = v___x_1135_;
goto v_reusejp_1152_;
}
else
{
lean_object* v_reuseFailAlloc_1158_; 
v_reuseFailAlloc_1158_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1158_, 0, v___x_1150_);
lean_ctor_set(v_reuseFailAlloc_1158_, 1, v___x_1151_);
v___x_1153_ = v_reuseFailAlloc_1158_;
goto v_reusejp_1152_;
}
v_reusejp_1152_:
{
lean_object* v___x_1154_; lean_object* v___x_1155_; lean_object* v___x_1156_; 
v___x_1154_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1154_, 0, v___x_1147_);
lean_ctor_set(v___x_1154_, 1, v___x_1153_);
v___x_1155_ = l_Lean_Json_mkObj(v___x_1154_);
lean_dec_ref_known(v___x_1154_, 2);
v___x_1156_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1156_, 0, v___x_1155_);
lean_ctor_set(v___x_1156_, 1, v_a_1130_);
v_a_1129_ = v_tail_1133_;
v_a_1130_ = v___x_1156_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__2(lean_object* v_a_1162_, lean_object* v_a_1163_){
_start:
{
if (lean_obj_tag(v_a_1162_) == 0)
{
lean_object* v___x_1164_; 
v___x_1164_ = l_List_reverse___redArg(v_a_1163_);
return v___x_1164_;
}
else
{
lean_object* v_head_1165_; lean_object* v_tail_1166_; lean_object* v___x_1168_; uint8_t v_isShared_1169_; uint8_t v_isSharedCheck_1175_; 
v_head_1165_ = lean_ctor_get(v_a_1162_, 0);
v_tail_1166_ = lean_ctor_get(v_a_1162_, 1);
v_isSharedCheck_1175_ = !lean_is_exclusive(v_a_1162_);
if (v_isSharedCheck_1175_ == 0)
{
v___x_1168_ = v_a_1162_;
v_isShared_1169_ = v_isSharedCheck_1175_;
goto v_resetjp_1167_;
}
else
{
lean_inc(v_tail_1166_);
lean_inc(v_head_1165_);
lean_dec(v_a_1162_);
v___x_1168_ = lean_box(0);
v_isShared_1169_ = v_isSharedCheck_1175_;
goto v_resetjp_1167_;
}
v_resetjp_1167_:
{
lean_object* v_snd_1170_; lean_object* v___x_1172_; 
v_snd_1170_ = lean_ctor_get(v_head_1165_, 1);
lean_inc(v_snd_1170_);
lean_dec(v_head_1165_);
if (v_isShared_1169_ == 0)
{
lean_ctor_set(v___x_1168_, 1, v_a_1163_);
lean_ctor_set(v___x_1168_, 0, v_snd_1170_);
v___x_1172_ = v___x_1168_;
goto v_reusejp_1171_;
}
else
{
lean_object* v_reuseFailAlloc_1174_; 
v_reuseFailAlloc_1174_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1174_, 0, v_snd_1170_);
lean_ctor_set(v_reuseFailAlloc_1174_, 1, v_a_1163_);
v___x_1172_ = v_reuseFailAlloc_1174_;
goto v_reusejp_1171_;
}
v_reusejp_1171_:
{
v_a_1162_ = v_tail_1166_;
v_a_1163_ = v___x_1172_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(lean_object* v_as_x27_1176_, lean_object* v_b_1177_){
_start:
{
if (lean_obj_tag(v_as_x27_1176_) == 0)
{
lean_object* v___x_1179_; 
v___x_1179_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1179_, 0, v_b_1177_);
return v___x_1179_;
}
else
{
lean_object* v_head_1180_; lean_object* v_decoded_1181_; lean_object* v_adsb_1182_; 
v_head_1180_ = lean_ctor_get(v_as_x27_1176_, 0);
v_decoded_1181_ = lean_ctor_get(v_head_1180_, 1);
v_adsb_1182_ = lean_ctor_get(v_decoded_1181_, 5);
if (lean_obj_tag(v_adsb_1182_) == 1)
{
lean_object* v_val_1183_; lean_object* v_tail_1184_; lean_object* v_kind_1185_; lean_object* v___x_1186_; 
v_val_1183_ = lean_ctor_get(v_adsb_1182_, 0);
v_tail_1184_ = lean_ctor_get(v_as_x27_1176_, 1);
v_kind_1185_ = lean_ctor_get(v_val_1183_, 0);
lean_inc(v_kind_1185_);
v___x_1186_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_bump(v_b_1177_, v_kind_1185_);
v_as_x27_1176_ = v_tail_1184_;
v_b_1177_ = v___x_1186_;
goto _start;
}
else
{
lean_object* v_tail_1188_; 
v_tail_1188_ = lean_ctor_get(v_as_x27_1176_, 1);
v_as_x27_1176_ = v_tail_1188_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg___boxed(lean_object* v_as_x27_1190_, lean_object* v_b_1191_, lean_object* v___y_1192_){
_start:
{
lean_object* v_res_1193_; 
v_res_1193_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(v_as_x27_1190_, v_b_1191_);
lean_dec(v_as_x27_1190_);
return v_res_1193_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5(size_t v_sz_1194_, size_t v_i_1195_, lean_object* v_bs_1196_){
_start:
{
uint8_t v___x_1197_; 
v___x_1197_ = lean_usize_dec_lt(v_i_1195_, v_sz_1194_);
if (v___x_1197_ == 0)
{
return v_bs_1196_;
}
else
{
lean_object* v_v_1198_; lean_object* v___x_1199_; lean_object* v_bs_x27_1200_; size_t v___x_1201_; size_t v___x_1202_; lean_object* v___x_1203_; 
v_v_1198_ = lean_array_uget(v_bs_1196_, v_i_1195_);
v___x_1199_ = lean_unsigned_to_nat(0u);
v_bs_x27_1200_ = lean_array_uset(v_bs_1196_, v_i_1195_, v___x_1199_);
v___x_1201_ = ((size_t)1ULL);
v___x_1202_ = lean_usize_add(v_i_1195_, v___x_1201_);
v___x_1203_ = lean_array_uset(v_bs_x27_1200_, v_i_1195_, v_v_1198_);
v_i_1195_ = v___x_1202_;
v_bs_1196_ = v___x_1203_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5___boxed(lean_object* v_sz_1205_, lean_object* v_i_1206_, lean_object* v_bs_1207_){
_start:
{
size_t v_sz_boxed_1208_; size_t v_i_boxed_1209_; lean_object* v_res_1210_; 
v_sz_boxed_1208_ = lean_unbox_usize(v_sz_1205_);
lean_dec(v_sz_1205_);
v_i_boxed_1209_ = lean_unbox_usize(v_i_1206_);
lean_dec(v_i_1206_);
v_res_1210_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5(v_sz_boxed_1208_, v_i_boxed_1209_, v_bs_1207_);
return v_res_1210_;
}
}
LEAN_EXPORT lean_object* l_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4(lean_object* v_a_1211_){
_start:
{
size_t v_sz_1212_; size_t v___x_1213_; lean_object* v___x_1214_; lean_object* v___x_1215_; 
v_sz_1212_ = lean_array_size(v_a_1211_);
v___x_1213_ = ((size_t)0ULL);
v___x_1214_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5(v_sz_1212_, v___x_1213_, v_a_1211_);
v___x_1215_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_1215_, 0, v___x_1214_);
return v___x_1215_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(lean_object* v_a_1216_){
_start:
{
lean_object* v___x_1217_; lean_object* v___x_1218_; 
v___x_1217_ = lean_array_mk(v_a_1216_);
v___x_1218_ = l_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4(v___x_1217_);
return v___x_1218_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(lean_object* v_output_1270_, lean_object* v_inputs_1271_, lean_object* v_as_x27_1272_, lean_object* v_b_1273_){
_start:
{
if (lean_obj_tag(v_as_x27_1272_) == 0)
{
lean_object* v___x_1275_; 
v___x_1275_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1275_, 0, v_b_1273_);
return v___x_1275_;
}
else
{
lean_object* v_head_1276_; lean_object* v_tail_1277_; lean_object* v___f_1278_; lean_object* v_rows_1279_; lean_object* v___x_1280_; lean_object* v___x_1281_; lean_object* v___x_1282_; lean_object* v___x_1283_; lean_object* v___x_1284_; 
v_head_1276_ = lean_ctor_get(v_as_x27_1272_, 0);
v_tail_1277_ = lean_ctor_get(v_as_x27_1272_, 1);
v___f_1278_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__0));
v_rows_1279_ = lean_box(0);
v___x_1280_ = lean_unsigned_to_nat(0u);
v___x_1281_ = lean_array_get_size(v_output_1270_);
v___x_1282_ = lean_unsigned_to_nat(1u);
v___x_1283_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1283_, 0, v___x_1280_);
lean_ctor_set(v___x_1283_, 1, v___x_1281_);
lean_ctor_set(v___x_1283_, 2, v___x_1282_);
v___x_1284_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(v_inputs_1271_, v_head_1276_, v_output_1270_, v___x_1283_, v_rows_1279_, v___x_1280_);
lean_dec_ref_known(v___x_1283_, 3);
if (lean_obj_tag(v___x_1284_) == 0)
{
lean_object* v_a_1285_; lean_object* v___x_1286_; lean_object* v_a_1287_; lean_object* v___x_1289_; uint8_t v_isShared_1290_; uint8_t v_isSharedCheck_1381_; 
v_a_1285_ = lean_ctor_get(v___x_1284_, 0);
lean_inc(v_a_1285_);
lean_dec_ref_known(v___x_1284_, 1);
v___x_1286_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(v_a_1285_, v_rows_1279_);
v_a_1287_ = lean_ctor_get(v___x_1286_, 0);
v_isSharedCheck_1381_ = !lean_is_exclusive(v___x_1286_);
if (v_isSharedCheck_1381_ == 0)
{
v___x_1289_ = v___x_1286_;
v_isShared_1290_ = v_isSharedCheck_1381_;
goto v_resetjp_1288_;
}
else
{
lean_inc(v_a_1287_);
lean_dec(v___x_1286_);
v___x_1289_ = lean_box(0);
v_isShared_1290_ = v_isSharedCheck_1381_;
goto v_resetjp_1288_;
}
v_resetjp_1288_:
{
lean_object* v___y_1292_; lean_object* v___y_1293_; lean_object* v___y_1294_; lean_object* v___y_1295_; lean_object* v___y_1296_; lean_object* v___y_1297_; lean_object* v___y_1298_; lean_object* v___y_1299_; lean_object* v___y_1332_; lean_object* v___y_1333_; lean_object* v___y_1334_; lean_object* v___y_1335_; lean_object* v___y_1336_; lean_object* v___y_1337_; lean_object* v___y_1338_; lean_object* v___y_1339_; lean_object* v___y_1343_; lean_object* v___y_1344_; lean_object* v___y_1345_; lean_object* v___y_1346_; lean_object* v_registers_1368_; lean_object* v___x_1377_; uint8_t v___x_1378_; 
v___x_1377_ = lean_unsigned_to_nat(20u);
v___x_1378_ = lean_nat_dec_eq(v_head_1276_, v___x_1377_);
if (v___x_1378_ == 0)
{
lean_object* v___x_1379_; uint8_t v___x_1380_; 
v___x_1379_ = lean_unsigned_to_nat(21u);
v___x_1380_ = lean_nat_dec_eq(v_head_1276_, v___x_1379_);
if (v___x_1380_ == 0)
{
v_registers_1368_ = v_rows_1279_;
goto v___jp_1367_;
}
else
{
goto v___jp_1373_;
}
}
else
{
goto v___jp_1373_;
}
v___jp_1291_:
{
lean_object* v___x_1300_; lean_object* v___x_1302_; 
v___x_1300_ = l_Lean_JsonNumber_fromNat(v___y_1299_);
if (v_isShared_1290_ == 0)
{
lean_ctor_set_tag(v___x_1289_, 2);
lean_ctor_set(v___x_1289_, 0, v___x_1300_);
v___x_1302_ = v___x_1289_;
goto v_reusejp_1301_;
}
else
{
lean_object* v_reuseFailAlloc_1330_; 
v_reuseFailAlloc_1330_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1330_, 0, v___x_1300_);
v___x_1302_ = v_reuseFailAlloc_1330_;
goto v_reusejp_1301_;
}
v_reusejp_1301_:
{
lean_object* v___x_1303_; lean_object* v___x_1304_; lean_object* v___x_1305_; lean_object* v___x_1306_; lean_object* v___x_1307_; lean_object* v___x_1308_; lean_object* v___x_1309_; lean_object* v___x_1310_; lean_object* v___x_1311_; lean_object* v___x_1312_; lean_object* v___x_1313_; lean_object* v___x_1314_; lean_object* v___x_1315_; lean_object* v___x_1316_; lean_object* v___x_1317_; lean_object* v___x_1318_; lean_object* v___x_1319_; lean_object* v___x_1320_; lean_object* v___x_1321_; lean_object* v___x_1322_; lean_object* v___x_1323_; lean_object* v___x_1324_; lean_object* v___x_1325_; lean_object* v___x_1326_; lean_object* v___x_1327_; lean_object* v___x_1328_; 
lean_inc_ref(v___y_1293_);
v___x_1303_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1303_, 0, v___y_1293_);
lean_ctor_set(v___x_1303_, 1, v___x_1302_);
v___x_1304_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__1));
lean_inc(v_a_1287_);
v___x_1305_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__2(v_a_1287_, v___y_1298_);
v___x_1306_ = l_List_sum___at___00Lean_PersistentHashMap_subarrayMeasure_spec__2(v___x_1305_);
lean_dec(v___x_1305_);
v___x_1307_ = l_Lean_JsonNumber_fromNat(v___x_1306_);
v___x_1308_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1308_, 0, v___x_1307_);
v___x_1309_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1309_, 0, v___x_1304_);
lean_ctor_set(v___x_1309_, 1, v___x_1308_);
v___x_1310_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__2));
v___x_1311_ = l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(v_a_1287_, v___f_1278_);
v___x_1312_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3(v___x_1311_, v_rows_1279_);
v___x_1313_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___x_1312_);
v___x_1314_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1314_, 0, v___x_1310_);
lean_ctor_set(v___x_1314_, 1, v___x_1313_);
v___x_1315_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__4));
v___x_1316_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___y_1295_);
v___x_1317_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1317_, 0, v___x_1315_);
lean_ctor_set(v___x_1317_, 1, v___x_1316_);
v___x_1318_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1318_, 0, v___x_1317_);
lean_ctor_set(v___x_1318_, 1, v_rows_1279_);
v___x_1319_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1319_, 0, v___x_1314_);
lean_ctor_set(v___x_1319_, 1, v___x_1318_);
v___x_1320_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1320_, 0, v___x_1309_);
lean_ctor_set(v___x_1320_, 1, v___x_1319_);
v___x_1321_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1321_, 0, v___x_1303_);
lean_ctor_set(v___x_1321_, 1, v___x_1320_);
v___x_1322_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1322_, 0, v___y_1297_);
lean_ctor_set(v___x_1322_, 1, v___x_1321_);
v___x_1323_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1323_, 0, v___y_1292_);
lean_ctor_set(v___x_1323_, 1, v___x_1322_);
v___x_1324_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1324_, 0, v___y_1294_);
lean_ctor_set(v___x_1324_, 1, v___x_1323_);
v___x_1325_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1325_, 0, v___y_1296_);
lean_ctor_set(v___x_1325_, 1, v___x_1324_);
v___x_1326_ = l_Lean_Json_mkObj(v___x_1325_);
lean_dec_ref_known(v___x_1325_, 2);
v___x_1327_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1327_, 0, v___x_1326_);
lean_ctor_set(v___x_1327_, 1, v_rows_1279_);
v___x_1328_ = l_List_appendTR___redArg(v_b_1273_, v___x_1327_);
v_as_x27_1272_ = v_tail_1277_;
v_b_1273_ = v___x_1328_;
goto _start;
}
}
v___jp_1331_:
{
lean_object* v___x_1340_; lean_object* v___x_1341_; 
v___x_1340_ = lean_unsigned_to_nat(2u);
v___x_1341_ = lean_nat_mul(v___y_1338_, v___x_1340_);
lean_dec(v___y_1338_);
v___y_1292_ = v___y_1332_;
v___y_1293_ = v___y_1333_;
v___y_1294_ = v___y_1335_;
v___y_1295_ = v___y_1334_;
v___y_1296_ = v___y_1337_;
v___y_1297_ = v___y_1336_;
v___y_1298_ = v___y_1339_;
v___y_1299_ = v___x_1341_;
goto v___jp_1291_;
}
v___jp_1342_:
{
lean_object* v___x_1347_; lean_object* v___x_1348_; lean_object* v___x_1349_; lean_object* v___x_1350_; lean_object* v___x_1351_; lean_object* v___x_1352_; lean_object* v___x_1353_; lean_object* v___x_1354_; lean_object* v___x_1355_; lean_object* v___x_1356_; lean_object* v___x_1357_; lean_object* v___x_1358_; lean_object* v___x_1359_; lean_object* v___x_1360_; lean_object* v___x_1361_; lean_object* v___x_1362_; lean_object* v___x_1363_; uint8_t v___x_1364_; 
v___x_1347_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6));
lean_inc(v_head_1276_);
v___x_1348_ = l_Lean_JsonNumber_fromNat(v_head_1276_);
v___x_1349_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1349_, 0, v___x_1348_);
v___x_1350_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1350_, 0, v___x_1347_);
lean_ctor_set(v___x_1350_, 1, v___x_1349_);
v___x_1351_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0));
v___x_1352_ = l_List_lengthTR___redArg(v_a_1285_);
lean_dec(v_a_1285_);
lean_inc(v___x_1352_);
v___x_1353_ = l_Lean_JsonNumber_fromNat(v___x_1352_);
v___x_1354_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1354_, 0, v___x_1353_);
lean_inc_ref(v___x_1354_);
v___x_1355_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1355_, 0, v___x_1351_);
lean_ctor_set(v___x_1355_, 1, v___x_1354_);
v___x_1356_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__3));
v___x_1357_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1357_, 0, v___x_1356_);
lean_ctor_set(v___x_1357_, 1, v___x_1354_);
v___x_1358_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__4));
v___x_1359_ = lean_nat_mul(v___x_1352_, v___y_1346_);
v___x_1360_ = l_Lean_JsonNumber_fromNat(v___x_1359_);
v___x_1361_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1361_, 0, v___x_1360_);
v___x_1362_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1362_, 0, v___x_1358_);
lean_ctor_set(v___x_1362_, 1, v___x_1361_);
v___x_1363_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__5));
v___x_1364_ = lean_nat_dec_eq(v_head_1276_, v___y_1344_);
if (v___x_1364_ == 0)
{
lean_object* v___x_1365_; uint8_t v___x_1366_; 
v___x_1365_ = lean_unsigned_to_nat(18u);
v___x_1366_ = lean_nat_dec_eq(v_head_1276_, v___x_1365_);
if (v___x_1366_ == 0)
{
lean_dec(v___x_1352_);
v___y_1292_ = v___x_1357_;
v___y_1293_ = v___x_1363_;
v___y_1294_ = v___x_1355_;
v___y_1295_ = v___y_1343_;
v___y_1296_ = v___x_1350_;
v___y_1297_ = v___x_1362_;
v___y_1298_ = v___y_1345_;
v___y_1299_ = v___x_1280_;
goto v___jp_1291_;
}
else
{
v___y_1332_ = v___x_1357_;
v___y_1333_ = v___x_1363_;
v___y_1334_ = v___y_1343_;
v___y_1335_ = v___x_1355_;
v___y_1336_ = v___x_1362_;
v___y_1337_ = v___x_1350_;
v___y_1338_ = v___x_1352_;
v___y_1339_ = v___y_1345_;
goto v___jp_1331_;
}
}
else
{
v___y_1332_ = v___x_1357_;
v___y_1333_ = v___x_1363_;
v___y_1334_ = v___y_1343_;
v___y_1335_ = v___x_1355_;
v___y_1336_ = v___x_1362_;
v___y_1337_ = v___x_1350_;
v___y_1338_ = v___x_1352_;
v___y_1339_ = v___y_1345_;
goto v___jp_1331_;
}
}
v___jp_1367_:
{
lean_object* v___x_1369_; lean_object* v___x_1370_; uint8_t v___x_1371_; 
v___x_1369_ = lean_unsigned_to_nat(17u);
v___x_1370_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__20));
v___x_1371_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_head_1276_, v___x_1370_);
if (v___x_1371_ == 0)
{
v___y_1343_ = v_registers_1368_;
v___y_1344_ = v___x_1369_;
v___y_1345_ = v_rows_1279_;
v___y_1346_ = v___x_1282_;
goto v___jp_1342_;
}
else
{
lean_object* v___x_1372_; 
v___x_1372_ = lean_unsigned_to_nat(2u);
v___y_1343_ = v_registers_1368_;
v___y_1344_ = v___x_1369_;
v___y_1345_ = v_rows_1279_;
v___y_1346_ = v___x_1372_;
goto v___jp_1342_;
}
}
v___jp_1373_:
{
lean_object* v___x_1374_; lean_object* v___x_1375_; 
v___x_1374_ = lp_lean1090_Lean1090_Impl_commBRegisters;
lean_inc(v_head_1276_);
v___x_1375_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(v_head_1276_, v_a_1285_, v___x_1374_, v_rows_1279_);
if (lean_obj_tag(v___x_1375_) == 0)
{
lean_object* v_a_1376_; 
v_a_1376_ = lean_ctor_get(v___x_1375_, 0);
lean_inc(v_a_1376_);
lean_dec_ref_known(v___x_1375_, 1);
v_registers_1368_ = v_a_1376_;
goto v___jp_1367_;
}
else
{
lean_del_object(v___x_1289_);
lean_dec(v_a_1287_);
lean_dec(v_a_1285_);
lean_dec(v_b_1273_);
return v___x_1375_;
}
}
}
}
else
{
lean_object* v_a_1382_; lean_object* v___x_1384_; uint8_t v_isShared_1385_; uint8_t v_isSharedCheck_1389_; 
lean_dec(v_b_1273_);
v_a_1382_ = lean_ctor_get(v___x_1284_, 0);
v_isSharedCheck_1389_ = !lean_is_exclusive(v___x_1284_);
if (v_isSharedCheck_1389_ == 0)
{
v___x_1384_ = v___x_1284_;
v_isShared_1385_ = v_isSharedCheck_1389_;
goto v_resetjp_1383_;
}
else
{
lean_inc(v_a_1382_);
lean_dec(v___x_1284_);
v___x_1384_ = lean_box(0);
v_isShared_1385_ = v_isSharedCheck_1389_;
goto v_resetjp_1383_;
}
v_resetjp_1383_:
{
lean_object* v___x_1387_; 
if (v_isShared_1385_ == 0)
{
v___x_1387_ = v___x_1384_;
goto v_reusejp_1386_;
}
else
{
lean_object* v_reuseFailAlloc_1388_; 
v_reuseFailAlloc_1388_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1388_, 0, v_a_1382_);
v___x_1387_ = v_reuseFailAlloc_1388_;
goto v_reusejp_1386_;
}
v_reusejp_1386_:
{
return v___x_1387_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___boxed(lean_object* v_output_1390_, lean_object* v_inputs_1391_, lean_object* v_as_x27_1392_, lean_object* v_b_1393_, lean_object* v___y_1394_){
_start:
{
lean_object* v_res_1395_; 
v_res_1395_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(v_output_1390_, v_inputs_1391_, v_as_x27_1392_, v_b_1393_);
lean_dec(v_as_x27_1392_);
lean_dec_ref(v_inputs_1391_);
lean_dec_ref(v_output_1390_);
return v_res_1395_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(lean_object* v_inputs_1396_, lean_object* v_output_1397_, lean_object* v_as_1398_, lean_object* v_as_x27_1399_, lean_object* v_b_1400_){
_start:
{
if (lean_obj_tag(v_as_x27_1399_) == 0)
{
lean_object* v___x_1402_; 
v___x_1402_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1402_, 0, v_b_1400_);
return v___x_1402_;
}
else
{
lean_object* v_head_1403_; lean_object* v_tail_1404_; lean_object* v___f_1405_; lean_object* v_rows_1406_; lean_object* v___x_1407_; lean_object* v___x_1408_; lean_object* v___x_1409_; lean_object* v___x_1410_; lean_object* v___x_1411_; 
v_head_1403_ = lean_ctor_get(v_as_x27_1399_, 0);
v_tail_1404_ = lean_ctor_get(v_as_x27_1399_, 1);
v___f_1405_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__0));
v_rows_1406_ = lean_box(0);
v___x_1407_ = lean_unsigned_to_nat(0u);
v___x_1408_ = lean_array_get_size(v_output_1397_);
v___x_1409_ = lean_unsigned_to_nat(1u);
v___x_1410_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1410_, 0, v___x_1407_);
lean_ctor_set(v___x_1410_, 1, v___x_1408_);
lean_ctor_set(v___x_1410_, 2, v___x_1409_);
v___x_1411_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(v_inputs_1396_, v_head_1403_, v_output_1397_, v___x_1410_, v_rows_1406_, v___x_1407_);
lean_dec_ref_known(v___x_1410_, 3);
if (lean_obj_tag(v___x_1411_) == 0)
{
lean_object* v_a_1412_; lean_object* v___x_1413_; lean_object* v_a_1414_; lean_object* v___x_1416_; uint8_t v_isShared_1417_; uint8_t v_isSharedCheck_1508_; 
v_a_1412_ = lean_ctor_get(v___x_1411_, 0);
lean_inc(v_a_1412_);
lean_dec_ref_known(v___x_1411_, 1);
v___x_1413_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(v_a_1412_, v_rows_1406_);
v_a_1414_ = lean_ctor_get(v___x_1413_, 0);
v_isSharedCheck_1508_ = !lean_is_exclusive(v___x_1413_);
if (v_isSharedCheck_1508_ == 0)
{
v___x_1416_ = v___x_1413_;
v_isShared_1417_ = v_isSharedCheck_1508_;
goto v_resetjp_1415_;
}
else
{
lean_inc(v_a_1414_);
lean_dec(v___x_1413_);
v___x_1416_ = lean_box(0);
v_isShared_1417_ = v_isSharedCheck_1508_;
goto v_resetjp_1415_;
}
v_resetjp_1415_:
{
lean_object* v___y_1419_; lean_object* v___y_1420_; lean_object* v___y_1421_; lean_object* v___y_1422_; lean_object* v___y_1423_; lean_object* v___y_1424_; lean_object* v___y_1425_; lean_object* v___y_1426_; lean_object* v___y_1459_; lean_object* v___y_1460_; lean_object* v___y_1461_; lean_object* v___y_1462_; lean_object* v___y_1463_; lean_object* v___y_1464_; lean_object* v___y_1465_; lean_object* v___y_1466_; lean_object* v___y_1470_; lean_object* v___y_1471_; lean_object* v___y_1472_; lean_object* v___y_1473_; lean_object* v_registers_1495_; lean_object* v___x_1504_; uint8_t v___x_1505_; 
v___x_1504_ = lean_unsigned_to_nat(20u);
v___x_1505_ = lean_nat_dec_eq(v_head_1403_, v___x_1504_);
if (v___x_1505_ == 0)
{
lean_object* v___x_1506_; uint8_t v___x_1507_; 
v___x_1506_ = lean_unsigned_to_nat(21u);
v___x_1507_ = lean_nat_dec_eq(v_head_1403_, v___x_1506_);
if (v___x_1507_ == 0)
{
v_registers_1495_ = v_rows_1406_;
goto v___jp_1494_;
}
else
{
goto v___jp_1500_;
}
}
else
{
goto v___jp_1500_;
}
v___jp_1418_:
{
lean_object* v___x_1427_; lean_object* v___x_1429_; 
v___x_1427_ = l_Lean_JsonNumber_fromNat(v___y_1426_);
if (v_isShared_1417_ == 0)
{
lean_ctor_set_tag(v___x_1416_, 2);
lean_ctor_set(v___x_1416_, 0, v___x_1427_);
v___x_1429_ = v___x_1416_;
goto v_reusejp_1428_;
}
else
{
lean_object* v_reuseFailAlloc_1457_; 
v_reuseFailAlloc_1457_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1457_, 0, v___x_1427_);
v___x_1429_ = v_reuseFailAlloc_1457_;
goto v_reusejp_1428_;
}
v_reusejp_1428_:
{
lean_object* v___x_1430_; lean_object* v___x_1431_; lean_object* v___x_1432_; lean_object* v___x_1433_; lean_object* v___x_1434_; lean_object* v___x_1435_; lean_object* v___x_1436_; lean_object* v___x_1437_; lean_object* v___x_1438_; lean_object* v___x_1439_; lean_object* v___x_1440_; lean_object* v___x_1441_; lean_object* v___x_1442_; lean_object* v___x_1443_; lean_object* v___x_1444_; lean_object* v___x_1445_; lean_object* v___x_1446_; lean_object* v___x_1447_; lean_object* v___x_1448_; lean_object* v___x_1449_; lean_object* v___x_1450_; lean_object* v___x_1451_; lean_object* v___x_1452_; lean_object* v___x_1453_; lean_object* v___x_1454_; lean_object* v___x_1455_; lean_object* v___x_1456_; 
lean_inc_ref(v___y_1419_);
v___x_1430_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1430_, 0, v___y_1419_);
lean_ctor_set(v___x_1430_, 1, v___x_1429_);
v___x_1431_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__1));
lean_inc(v_a_1414_);
v___x_1432_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__2(v_a_1414_, v___y_1425_);
v___x_1433_ = l_List_sum___at___00Lean_PersistentHashMap_subarrayMeasure_spec__2(v___x_1432_);
lean_dec(v___x_1432_);
v___x_1434_ = l_Lean_JsonNumber_fromNat(v___x_1433_);
v___x_1435_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1435_, 0, v___x_1434_);
v___x_1436_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1436_, 0, v___x_1431_);
lean_ctor_set(v___x_1436_, 1, v___x_1435_);
v___x_1437_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__2));
v___x_1438_ = l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(v_a_1414_, v___f_1405_);
v___x_1439_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3(v___x_1438_, v_rows_1406_);
v___x_1440_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___x_1439_);
v___x_1441_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1441_, 0, v___x_1437_);
lean_ctor_set(v___x_1441_, 1, v___x_1440_);
v___x_1442_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__4));
v___x_1443_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___y_1421_);
v___x_1444_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1444_, 0, v___x_1442_);
lean_ctor_set(v___x_1444_, 1, v___x_1443_);
v___x_1445_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1445_, 0, v___x_1444_);
lean_ctor_set(v___x_1445_, 1, v_rows_1406_);
v___x_1446_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1446_, 0, v___x_1441_);
lean_ctor_set(v___x_1446_, 1, v___x_1445_);
v___x_1447_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1447_, 0, v___x_1436_);
lean_ctor_set(v___x_1447_, 1, v___x_1446_);
v___x_1448_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1448_, 0, v___x_1430_);
lean_ctor_set(v___x_1448_, 1, v___x_1447_);
v___x_1449_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1449_, 0, v___y_1423_);
lean_ctor_set(v___x_1449_, 1, v___x_1448_);
v___x_1450_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1450_, 0, v___y_1420_);
lean_ctor_set(v___x_1450_, 1, v___x_1449_);
v___x_1451_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1451_, 0, v___y_1424_);
lean_ctor_set(v___x_1451_, 1, v___x_1450_);
v___x_1452_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1452_, 0, v___y_1422_);
lean_ctor_set(v___x_1452_, 1, v___x_1451_);
v___x_1453_ = l_Lean_Json_mkObj(v___x_1452_);
lean_dec_ref_known(v___x_1452_, 2);
v___x_1454_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1454_, 0, v___x_1453_);
lean_ctor_set(v___x_1454_, 1, v_rows_1406_);
v___x_1455_ = l_List_appendTR___redArg(v_b_1400_, v___x_1454_);
v___x_1456_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(v_output_1397_, v_inputs_1396_, v_tail_1404_, v___x_1455_);
return v___x_1456_;
}
}
v___jp_1458_:
{
lean_object* v___x_1467_; lean_object* v___x_1468_; 
v___x_1467_ = lean_unsigned_to_nat(2u);
v___x_1468_ = lean_nat_mul(v___y_1462_, v___x_1467_);
lean_dec(v___y_1462_);
v___y_1419_ = v___y_1459_;
v___y_1420_ = v___y_1461_;
v___y_1421_ = v___y_1460_;
v___y_1422_ = v___y_1463_;
v___y_1423_ = v___y_1464_;
v___y_1424_ = v___y_1465_;
v___y_1425_ = v___y_1466_;
v___y_1426_ = v___x_1468_;
goto v___jp_1418_;
}
v___jp_1469_:
{
lean_object* v___x_1474_; lean_object* v___x_1475_; lean_object* v___x_1476_; lean_object* v___x_1477_; lean_object* v___x_1478_; lean_object* v___x_1479_; lean_object* v___x_1480_; lean_object* v___x_1481_; lean_object* v___x_1482_; lean_object* v___x_1483_; lean_object* v___x_1484_; lean_object* v___x_1485_; lean_object* v___x_1486_; lean_object* v___x_1487_; lean_object* v___x_1488_; lean_object* v___x_1489_; lean_object* v___x_1490_; uint8_t v___x_1491_; 
v___x_1474_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6));
lean_inc(v_head_1403_);
v___x_1475_ = l_Lean_JsonNumber_fromNat(v_head_1403_);
v___x_1476_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1476_, 0, v___x_1475_);
v___x_1477_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1477_, 0, v___x_1474_);
lean_ctor_set(v___x_1477_, 1, v___x_1476_);
v___x_1478_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0));
v___x_1479_ = l_List_lengthTR___redArg(v_a_1412_);
lean_dec(v_a_1412_);
lean_inc(v___x_1479_);
v___x_1480_ = l_Lean_JsonNumber_fromNat(v___x_1479_);
v___x_1481_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1481_, 0, v___x_1480_);
lean_inc_ref(v___x_1481_);
v___x_1482_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1482_, 0, v___x_1478_);
lean_ctor_set(v___x_1482_, 1, v___x_1481_);
v___x_1483_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__3));
v___x_1484_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1484_, 0, v___x_1483_);
lean_ctor_set(v___x_1484_, 1, v___x_1481_);
v___x_1485_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__4));
v___x_1486_ = lean_nat_mul(v___x_1479_, v___y_1473_);
v___x_1487_ = l_Lean_JsonNumber_fromNat(v___x_1486_);
v___x_1488_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1488_, 0, v___x_1487_);
v___x_1489_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1489_, 0, v___x_1485_);
lean_ctor_set(v___x_1489_, 1, v___x_1488_);
v___x_1490_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__5));
v___x_1491_ = lean_nat_dec_eq(v_head_1403_, v___y_1470_);
if (v___x_1491_ == 0)
{
lean_object* v___x_1492_; uint8_t v___x_1493_; 
v___x_1492_ = lean_unsigned_to_nat(18u);
v___x_1493_ = lean_nat_dec_eq(v_head_1403_, v___x_1492_);
if (v___x_1493_ == 0)
{
lean_dec(v___x_1479_);
v___y_1419_ = v___x_1490_;
v___y_1420_ = v___x_1484_;
v___y_1421_ = v___y_1471_;
v___y_1422_ = v___x_1477_;
v___y_1423_ = v___x_1489_;
v___y_1424_ = v___x_1482_;
v___y_1425_ = v___y_1472_;
v___y_1426_ = v___x_1407_;
goto v___jp_1418_;
}
else
{
v___y_1459_ = v___x_1490_;
v___y_1460_ = v___y_1471_;
v___y_1461_ = v___x_1484_;
v___y_1462_ = v___x_1479_;
v___y_1463_ = v___x_1477_;
v___y_1464_ = v___x_1489_;
v___y_1465_ = v___x_1482_;
v___y_1466_ = v___y_1472_;
goto v___jp_1458_;
}
}
else
{
v___y_1459_ = v___x_1490_;
v___y_1460_ = v___y_1471_;
v___y_1461_ = v___x_1484_;
v___y_1462_ = v___x_1479_;
v___y_1463_ = v___x_1477_;
v___y_1464_ = v___x_1489_;
v___y_1465_ = v___x_1482_;
v___y_1466_ = v___y_1472_;
goto v___jp_1458_;
}
}
v___jp_1494_:
{
lean_object* v___x_1496_; lean_object* v___x_1497_; uint8_t v___x_1498_; 
v___x_1496_ = lean_unsigned_to_nat(17u);
v___x_1497_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__20));
v___x_1498_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_head_1403_, v___x_1497_);
if (v___x_1498_ == 0)
{
v___y_1470_ = v___x_1496_;
v___y_1471_ = v_registers_1495_;
v___y_1472_ = v_rows_1406_;
v___y_1473_ = v___x_1409_;
goto v___jp_1469_;
}
else
{
lean_object* v___x_1499_; 
v___x_1499_ = lean_unsigned_to_nat(2u);
v___y_1470_ = v___x_1496_;
v___y_1471_ = v_registers_1495_;
v___y_1472_ = v_rows_1406_;
v___y_1473_ = v___x_1499_;
goto v___jp_1469_;
}
}
v___jp_1500_:
{
lean_object* v___x_1501_; lean_object* v___x_1502_; 
v___x_1501_ = lp_lean1090_Lean1090_Impl_commBRegisters;
lean_inc(v_head_1403_);
v___x_1502_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(v_head_1403_, v_a_1412_, v___x_1501_, v_rows_1406_);
if (lean_obj_tag(v___x_1502_) == 0)
{
lean_object* v_a_1503_; 
v_a_1503_ = lean_ctor_get(v___x_1502_, 0);
lean_inc(v_a_1503_);
lean_dec_ref_known(v___x_1502_, 1);
v_registers_1495_ = v_a_1503_;
goto v___jp_1494_;
}
else
{
lean_del_object(v___x_1416_);
lean_dec(v_a_1414_);
lean_dec(v_a_1412_);
lean_dec(v_b_1400_);
return v___x_1502_;
}
}
}
}
else
{
lean_object* v_a_1509_; lean_object* v___x_1511_; uint8_t v_isShared_1512_; uint8_t v_isSharedCheck_1516_; 
lean_dec(v_b_1400_);
v_a_1509_ = lean_ctor_get(v___x_1411_, 0);
v_isSharedCheck_1516_ = !lean_is_exclusive(v___x_1411_);
if (v_isSharedCheck_1516_ == 0)
{
v___x_1511_ = v___x_1411_;
v_isShared_1512_ = v_isSharedCheck_1516_;
goto v_resetjp_1510_;
}
else
{
lean_inc(v_a_1509_);
lean_dec(v___x_1411_);
v___x_1511_ = lean_box(0);
v_isShared_1512_ = v_isSharedCheck_1516_;
goto v_resetjp_1510_;
}
v_resetjp_1510_:
{
lean_object* v___x_1514_; 
if (v_isShared_1512_ == 0)
{
v___x_1514_ = v___x_1511_;
goto v_reusejp_1513_;
}
else
{
lean_object* v_reuseFailAlloc_1515_; 
v_reuseFailAlloc_1515_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1515_, 0, v_a_1509_);
v___x_1514_ = v_reuseFailAlloc_1515_;
goto v_reusejp_1513_;
}
v_reusejp_1513_:
{
return v___x_1514_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___boxed(lean_object* v_inputs_1517_, lean_object* v_output_1518_, lean_object* v_as_1519_, lean_object* v_as_x27_1520_, lean_object* v_b_1521_, lean_object* v___y_1522_){
_start:
{
lean_object* v_res_1523_; 
v_res_1523_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(v_inputs_1517_, v_output_1518_, v_as_1519_, v_as_x27_1520_, v_b_1521_);
lean_dec(v_as_x27_1520_);
lean_dec(v_as_1519_);
lean_dec_ref(v_output_1518_);
lean_dec_ref(v_inputs_1517_);
return v_res_1523_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0(void){
_start:
{
lean_object* v___x_1524_; lean_object* v___x_1525_; 
v___x_1524_ = lean_unsigned_to_nat(32u);
v___x_1525_ = l_List_range(v___x_1524_);
return v___x_1525_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census(lean_object* v_inputs_1539_, lean_object* v_output_1540_){
_start:
{
lean_object* v_rows_1542_; lean_object* v___x_1543_; lean_object* v___x_1544_; 
v_rows_1542_ = lean_box(0);
v___x_1543_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0);
v___x_1544_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(v_inputs_1539_, v_output_1540_, v___x_1543_, v___x_1543_, v_rows_1542_);
if (lean_obj_tag(v___x_1544_) == 0)
{
lean_object* v_a_1545_; lean_object* v___x_1547_; uint8_t v_isShared_1548_; uint8_t v_isSharedCheck_1561_; 
v_a_1545_ = lean_ctor_get(v___x_1544_, 0);
v_isSharedCheck_1561_ = !lean_is_exclusive(v___x_1544_);
if (v_isSharedCheck_1561_ == 0)
{
v___x_1547_ = v___x_1544_;
v_isShared_1548_ = v_isSharedCheck_1561_;
goto v_resetjp_1546_;
}
else
{
lean_inc(v_a_1545_);
lean_dec(v___x_1544_);
v___x_1547_ = lean_box(0);
v_isShared_1548_ = v_isSharedCheck_1561_;
goto v_resetjp_1546_;
}
v_resetjp_1546_:
{
lean_object* v___x_1549_; lean_object* v___x_1550_; lean_object* v___x_1551_; lean_object* v___x_1552_; lean_object* v___x_1553_; lean_object* v___x_1554_; lean_object* v___x_1555_; lean_object* v___x_1556_; lean_object* v___x_1557_; lean_object* v___x_1559_; 
v___x_1549_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__3));
v___x_1550_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__6));
v___x_1551_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__7));
v___x_1552_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v_a_1545_);
v___x_1553_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1553_, 0, v___x_1551_);
lean_ctor_set(v___x_1553_, 1, v___x_1552_);
v___x_1554_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1554_, 0, v___x_1553_);
lean_ctor_set(v___x_1554_, 1, v_rows_1542_);
v___x_1555_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1555_, 0, v___x_1550_);
lean_ctor_set(v___x_1555_, 1, v___x_1554_);
v___x_1556_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1556_, 0, v___x_1549_);
lean_ctor_set(v___x_1556_, 1, v___x_1555_);
v___x_1557_ = l_Lean_Json_mkObj(v___x_1556_);
lean_dec_ref_known(v___x_1556_, 2);
if (v_isShared_1548_ == 0)
{
lean_ctor_set(v___x_1547_, 0, v___x_1557_);
v___x_1559_ = v___x_1547_;
goto v_reusejp_1558_;
}
else
{
lean_object* v_reuseFailAlloc_1560_; 
v_reuseFailAlloc_1560_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1560_, 0, v___x_1557_);
v___x_1559_ = v_reuseFailAlloc_1560_;
goto v_reusejp_1558_;
}
v_reusejp_1558_:
{
return v___x_1559_;
}
}
}
else
{
lean_object* v_a_1562_; lean_object* v___x_1564_; uint8_t v_isShared_1565_; uint8_t v_isSharedCheck_1569_; 
v_a_1562_ = lean_ctor_get(v___x_1544_, 0);
v_isSharedCheck_1569_ = !lean_is_exclusive(v___x_1544_);
if (v_isSharedCheck_1569_ == 0)
{
v___x_1564_ = v___x_1544_;
v_isShared_1565_ = v_isSharedCheck_1569_;
goto v_resetjp_1563_;
}
else
{
lean_inc(v_a_1562_);
lean_dec(v___x_1544_);
v___x_1564_ = lean_box(0);
v_isShared_1565_ = v_isSharedCheck_1569_;
goto v_resetjp_1563_;
}
v_resetjp_1563_:
{
lean_object* v___x_1567_; 
if (v_isShared_1565_ == 0)
{
v___x_1567_ = v___x_1564_;
goto v_reusejp_1566_;
}
else
{
lean_object* v_reuseFailAlloc_1568_; 
v_reuseFailAlloc_1568_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1568_, 0, v_a_1562_);
v___x_1567_ = v_reuseFailAlloc_1568_;
goto v_reusejp_1566_;
}
v_reusejp_1566_:
{
return v___x_1567_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___boxed(lean_object* v_inputs_1570_, lean_object* v_output_1571_, lean_object* v_a_1572_){
_start:
{
lean_object* v_res_1573_; 
v_res_1573_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census(v_inputs_1570_, v_output_1571_);
lean_dec_ref(v_output_1571_);
lean_dec_ref(v_inputs_1570_);
return v_res_1573_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0(lean_object* v_inputs_1574_, lean_object* v_a_1575_, lean_object* v_output_1576_, lean_object* v_range_1577_, lean_object* v_b_1578_, lean_object* v_i_1579_, lean_object* v_hs_1580_, lean_object* v_hl_1581_){
_start:
{
lean_object* v___x_1583_; 
v___x_1583_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(v_inputs_1574_, v_a_1575_, v_output_1576_, v_range_1577_, v_b_1578_, v_i_1579_);
return v___x_1583_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___boxed(lean_object* v_inputs_1584_, lean_object* v_a_1585_, lean_object* v_output_1586_, lean_object* v_range_1587_, lean_object* v_b_1588_, lean_object* v_i_1589_, lean_object* v_hs_1590_, lean_object* v_hl_1591_, lean_object* v___y_1592_){
_start:
{
lean_object* v_res_1593_; 
v_res_1593_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0(v_inputs_1584_, v_a_1585_, v_output_1586_, v_range_1587_, v_b_1588_, v_i_1589_, v_hs_1590_, v_hl_1591_);
lean_dec_ref(v_range_1587_);
lean_dec_ref(v_output_1586_);
lean_dec(v_a_1585_);
lean_dec_ref(v_inputs_1584_);
return v_res_1593_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1(lean_object* v_as_1594_, lean_object* v_as_x27_1595_, lean_object* v_b_1596_, lean_object* v_a_1597_){
_start:
{
lean_object* v___x_1599_; 
v___x_1599_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(v_as_x27_1595_, v_b_1596_);
return v___x_1599_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___boxed(lean_object* v_as_1600_, lean_object* v_as_x27_1601_, lean_object* v_b_1602_, lean_object* v_a_1603_, lean_object* v___y_1604_){
_start:
{
lean_object* v_res_1605_; 
v_res_1605_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1(v_as_1600_, v_as_x27_1601_, v_b_1602_, v_a_1603_);
lean_dec(v_as_x27_1601_);
lean_dec(v_as_1600_);
return v_res_1605_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5(lean_object* v_a_1606_, lean_object* v_a_1607_, lean_object* v_as_1608_, lean_object* v_as_x27_1609_, lean_object* v_b_1610_, lean_object* v_a_1611_){
_start:
{
lean_object* v___x_1613_; 
v___x_1613_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(v_a_1606_, v_a_1607_, v_as_x27_1609_, v_b_1610_);
return v___x_1613_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___boxed(lean_object* v_a_1614_, lean_object* v_a_1615_, lean_object* v_as_1616_, lean_object* v_as_x27_1617_, lean_object* v_b_1618_, lean_object* v_a_1619_, lean_object* v___y_1620_){
_start:
{
lean_object* v_res_1621_; 
v_res_1621_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5(v_a_1614_, v_a_1615_, v_as_1616_, v_as_x27_1617_, v_b_1618_, v_a_1619_);
lean_dec(v_as_x27_1617_);
lean_dec(v_as_1616_);
lean_dec(v_a_1615_);
return v_res_1621_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6(lean_object* v_inputs_1622_, lean_object* v_output_1623_, lean_object* v_as_1624_, lean_object* v_as_x27_1625_, lean_object* v_b_1626_, lean_object* v_a_1627_){
_start:
{
lean_object* v___x_1629_; 
v___x_1629_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(v_inputs_1622_, v_output_1623_, v_as_1624_, v_as_x27_1625_, v_b_1626_);
return v___x_1629_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___boxed(lean_object* v_inputs_1630_, lean_object* v_output_1631_, lean_object* v_as_1632_, lean_object* v_as_x27_1633_, lean_object* v_b_1634_, lean_object* v_a_1635_, lean_object* v___y_1636_){
_start:
{
lean_object* v_res_1637_; 
v_res_1637_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6(v_inputs_1630_, v_output_1631_, v_as_1632_, v_as_x27_1633_, v_b_1634_, v_a_1635_);
lean_dec(v_as_x27_1633_);
lean_dec(v_as_1632_);
lean_dec_ref(v_output_1631_);
lean_dec_ref(v_inputs_1630_);
return v_res_1637_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7(lean_object* v_output_1638_, lean_object* v_inputs_1639_, lean_object* v_as_1640_, lean_object* v_as_x27_1641_, lean_object* v_b_1642_, lean_object* v_a_1643_){
_start:
{
lean_object* v___x_1645_; 
v___x_1645_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(v_output_1638_, v_inputs_1639_, v_as_x27_1641_, v_b_1642_);
return v___x_1645_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___boxed(lean_object* v_output_1646_, lean_object* v_inputs_1647_, lean_object* v_as_1648_, lean_object* v_as_x27_1649_, lean_object* v_b_1650_, lean_object* v_a_1651_, lean_object* v___y_1652_){
_start:
{
lean_object* v_res_1653_; 
v_res_1653_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7(v_output_1646_, v_inputs_1647_, v_as_1648_, v_as_x27_1649_, v_b_1650_, v_a_1651_);
lean_dec(v_as_x27_1649_);
lean_dec(v_as_1648_);
lean_dec_ref(v_inputs_1647_);
lean_dec_ref(v_output_1646_);
return v_res_1653_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(lean_object* v_a_1654_, lean_object* v_as_1655_, size_t v_i_1656_, size_t v_stop_1657_, lean_object* v_b_1658_){
_start:
{
lean_object* v___y_1660_; uint8_t v___x_1664_; 
v___x_1664_ = lean_usize_dec_eq(v_i_1656_, v_stop_1657_);
if (v___x_1664_ == 0)
{
lean_object* v___x_1665_; lean_object* v_df_1666_; lean_object* v___x_1667_; uint8_t v___x_1668_; 
v___x_1665_ = lean_array_uget_borrowed(v_as_1655_, v_i_1656_);
v_df_1666_ = lean_ctor_get(v___x_1665_, 0);
lean_inc_ref(v_a_1654_);
lean_inc(v_df_1666_);
v___x_1667_ = lean_apply_1(v_a_1654_, v_df_1666_);
v___x_1668_ = lean_unbox(v___x_1667_);
if (v___x_1668_ == 0)
{
v___y_1660_ = v_b_1658_;
goto v___jp_1659_;
}
else
{
lean_object* v___x_1669_; 
lean_inc(v___x_1665_);
v___x_1669_ = lean_array_push(v_b_1658_, v___x_1665_);
v___y_1660_ = v___x_1669_;
goto v___jp_1659_;
}
}
else
{
lean_dec_ref(v_a_1654_);
return v_b_1658_;
}
v___jp_1659_:
{
size_t v___x_1661_; size_t v___x_1662_; 
v___x_1661_ = ((size_t)1ULL);
v___x_1662_ = lean_usize_add(v_i_1656_, v___x_1661_);
v_i_1656_ = v___x_1662_;
v_b_1658_ = v___y_1660_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1___boxed(lean_object* v_a_1670_, lean_object* v_as_1671_, lean_object* v_i_1672_, lean_object* v_stop_1673_, lean_object* v_b_1674_){
_start:
{
size_t v_i_boxed_1675_; size_t v_stop_boxed_1676_; lean_object* v_res_1677_; 
v_i_boxed_1675_ = lean_unbox_usize(v_i_1672_);
lean_dec(v_i_1672_);
v_stop_boxed_1676_ = lean_unbox_usize(v_stop_1673_);
lean_dec(v_stop_1673_);
v_res_1677_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(v_a_1670_, v_as_1671_, v_i_boxed_1675_, v_stop_boxed_1676_, v_b_1674_);
lean_dec_ref(v_as_1671_);
return v_res_1677_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0(lean_object* v_a_1679_, lean_object* v_a_1680_){
_start:
{
if (lean_obj_tag(v_a_1679_) == 0)
{
lean_object* v___x_1681_; 
v___x_1681_ = l_List_reverse___redArg(v_a_1680_);
return v___x_1681_;
}
else
{
lean_object* v_head_1682_; lean_object* v_tail_1683_; lean_object* v___x_1685_; uint8_t v_isShared_1686_; uint8_t v_isSharedCheck_1710_; 
v_head_1682_ = lean_ctor_get(v_a_1679_, 0);
v_tail_1683_ = lean_ctor_get(v_a_1679_, 1);
v_isSharedCheck_1710_ = !lean_is_exclusive(v_a_1679_);
if (v_isSharedCheck_1710_ == 0)
{
v___x_1685_ = v_a_1679_;
v_isShared_1686_ = v_isSharedCheck_1710_;
goto v_resetjp_1684_;
}
else
{
lean_inc(v_tail_1683_);
lean_inc(v_head_1682_);
lean_dec(v_a_1679_);
v___x_1685_ = lean_box(0);
v_isShared_1686_ = v_isSharedCheck_1710_;
goto v_resetjp_1684_;
}
v_resetjp_1684_:
{
lean_object* v_fst_1687_; lean_object* v_snd_1688_; lean_object* v___x_1690_; uint8_t v_isShared_1691_; uint8_t v_isSharedCheck_1709_; 
v_fst_1687_ = lean_ctor_get(v_head_1682_, 0);
v_snd_1688_ = lean_ctor_get(v_head_1682_, 1);
v_isSharedCheck_1709_ = !lean_is_exclusive(v_head_1682_);
if (v_isSharedCheck_1709_ == 0)
{
v___x_1690_ = v_head_1682_;
v_isShared_1691_ = v_isSharedCheck_1709_;
goto v_resetjp_1689_;
}
else
{
lean_inc(v_snd_1688_);
lean_inc(v_fst_1687_);
lean_dec(v_head_1682_);
v___x_1690_ = lean_box(0);
v_isShared_1691_ = v_isSharedCheck_1709_;
goto v_resetjp_1689_;
}
v_resetjp_1689_:
{
lean_object* v___x_1692_; lean_object* v___x_1693_; lean_object* v___x_1694_; lean_object* v___x_1695_; lean_object* v___x_1696_; lean_object* v___x_1698_; 
v___x_1692_ = ((lean_object*)(l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0___closed__0));
v___x_1693_ = lean_box(0);
v___x_1694_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6));
v___x_1695_ = l_Lean_JsonNumber_fromNat(v_snd_1688_);
v___x_1696_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1696_, 0, v___x_1695_);
if (v_isShared_1691_ == 0)
{
lean_ctor_set(v___x_1690_, 1, v___x_1696_);
lean_ctor_set(v___x_1690_, 0, v___x_1694_);
v___x_1698_ = v___x_1690_;
goto v_reusejp_1697_;
}
else
{
lean_object* v_reuseFailAlloc_1708_; 
v_reuseFailAlloc_1708_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1708_, 0, v___x_1694_);
lean_ctor_set(v_reuseFailAlloc_1708_, 1, v___x_1696_);
v___x_1698_ = v_reuseFailAlloc_1708_;
goto v_reusejp_1697_;
}
v_reusejp_1697_:
{
lean_object* v___x_1699_; lean_object* v___x_1700_; lean_object* v___x_1702_; 
v___x_1699_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(v_fst_1687_);
v___x_1700_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1700_, 0, v___x_1692_);
lean_ctor_set(v___x_1700_, 1, v___x_1699_);
if (v_isShared_1686_ == 0)
{
lean_ctor_set(v___x_1685_, 1, v___x_1693_);
lean_ctor_set(v___x_1685_, 0, v___x_1700_);
v___x_1702_ = v___x_1685_;
goto v_reusejp_1701_;
}
else
{
lean_object* v_reuseFailAlloc_1707_; 
v_reuseFailAlloc_1707_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1707_, 0, v___x_1700_);
lean_ctor_set(v_reuseFailAlloc_1707_, 1, v___x_1693_);
v___x_1702_ = v_reuseFailAlloc_1707_;
goto v_reusejp_1701_;
}
v_reusejp_1701_:
{
lean_object* v___x_1703_; lean_object* v___x_1704_; lean_object* v___x_1705_; 
v___x_1703_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1703_, 0, v___x_1698_);
lean_ctor_set(v___x_1703_, 1, v___x_1702_);
v___x_1704_ = l_Lean_Json_mkObj(v___x_1703_);
lean_dec_ref_known(v___x_1703_, 2);
v___x_1705_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1705_, 0, v___x_1704_);
lean_ctor_set(v___x_1705_, 1, v_a_1680_);
v_a_1679_ = v_tail_1683_;
v_a_1680_ = v___x_1705_;
goto _start;
}
}
}
}
}
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__7(void){
_start:
{
lean_object* v___x_1721_; lean_object* v___x_1722_; 
v___x_1721_ = lean_unsigned_to_nat(172432u);
v___x_1722_ = l_Lean_JsonNumber_fromNat(v___x_1721_);
return v___x_1722_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8(void){
_start:
{
lean_object* v___x_1723_; lean_object* v___x_1724_; 
v___x_1723_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__7, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__7_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__7);
v___x_1724_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1724_, 0, v___x_1723_);
return v___x_1724_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9(void){
_start:
{
lean_object* v___x_1725_; lean_object* v___x_1726_; lean_object* v___x_1727_; 
v___x_1725_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8);
v___x_1726_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__6));
v___x_1727_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1727_, 0, v___x_1726_);
lean_ctor_set(v___x_1727_, 1, v___x_1725_);
return v___x_1727_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10(void){
_start:
{
lean_object* v___x_1728_; lean_object* v___x_1729_; lean_object* v___x_1730_; 
v___x_1728_ = lean_box(0);
v___x_1729_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9);
v___x_1730_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1730_, 0, v___x_1729_);
lean_ctor_set(v___x_1730_, 1, v___x_1728_);
return v___x_1730_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode(lean_object* v_mode_1749_, lean_object* v_inputs_1750_, uint8_t v_withCensus_1751_, uint8_t v_wait_1752_){
_start:
{
lean_object* v___x_1754_; lean_object* v___x_1755_; 
lean_inc_ref(v_mode_1749_);
v___x_1754_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select(v_mode_1749_);
v___x_1755_ = l_IO_ofExcept___at___00Std_Time_Database_TZdb_parseTZIfFromDisk_spec__0___redArg(v___x_1754_);
if (lean_obj_tag(v___x_1755_) == 0)
{
lean_object* v_a_1756_; lean_object* v___x_1757_; lean_object* v___y_1759_; lean_object* v___x_1882_; lean_object* v___x_1883_; uint8_t v___x_1884_; 
v_a_1756_ = lean_ctor_get(v___x_1755_, 0);
lean_inc(v_a_1756_);
lean_dec_ref_known(v___x_1755_, 1);
v___x_1757_ = lean_unsigned_to_nat(0u);
v___x_1882_ = lean_array_get_size(v_inputs_1750_);
v___x_1883_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__21));
v___x_1884_ = lean_nat_dec_lt(v___x_1757_, v___x_1882_);
if (v___x_1884_ == 0)
{
lean_dec(v_a_1756_);
v___y_1759_ = v___x_1883_;
goto v___jp_1758_;
}
else
{
uint8_t v___x_1885_; 
v___x_1885_ = lean_nat_dec_le(v___x_1882_, v___x_1882_);
if (v___x_1885_ == 0)
{
if (v___x_1884_ == 0)
{
lean_dec(v_a_1756_);
v___y_1759_ = v___x_1883_;
goto v___jp_1758_;
}
else
{
size_t v___x_1886_; size_t v___x_1887_; lean_object* v___x_1888_; 
v___x_1886_ = ((size_t)0ULL);
v___x_1887_ = lean_usize_of_nat(v___x_1882_);
v___x_1888_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(v_a_1756_, v_inputs_1750_, v___x_1886_, v___x_1887_, v___x_1883_);
v___y_1759_ = v___x_1888_;
goto v___jp_1758_;
}
}
else
{
size_t v___x_1889_; size_t v___x_1890_; lean_object* v___x_1891_; 
v___x_1889_ = ((size_t)0ULL);
v___x_1890_ = lean_usize_of_nat(v___x_1882_);
v___x_1891_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(v_a_1756_, v_inputs_1750_, v___x_1889_, v___x_1890_, v___x_1883_);
v___y_1759_ = v___x_1891_;
goto v___jp_1758_;
}
}
v___jp_1758_:
{
lean_object* v___x_1760_; lean_object* v___x_1761_; lean_object* v___x_1762_; lean_object* v___x_1763_; lean_object* v___x_1764_; lean_object* v___x_1765_; lean_object* v___x_1766_; lean_object* v___x_1767_; lean_object* v___x_1768_; lean_object* v___x_1769_; lean_object* v___x_1770_; lean_object* v___x_1771_; lean_object* v___x_1772_; lean_object* v___x_1773_; lean_object* v___x_1774_; lean_object* v___x_1775_; 
v___x_1760_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__3));
v___x_1761_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__4));
v___x_1762_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1762_, 0, v_mode_1749_);
v___x_1763_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1763_, 0, v___x_1761_);
lean_ctor_set(v___x_1763_, 1, v___x_1762_);
v___x_1764_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__5));
v___x_1765_ = lean_array_get_size(v___y_1759_);
v___x_1766_ = l_Lean_JsonNumber_fromNat(v___x_1765_);
v___x_1767_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1767_, 0, v___x_1766_);
v___x_1768_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1768_, 0, v___x_1764_);
lean_ctor_set(v___x_1768_, 1, v___x_1767_);
v___x_1769_ = lean_box(0);
v___x_1770_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10);
v___x_1771_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1771_, 0, v___x_1768_);
lean_ctor_set(v___x_1771_, 1, v___x_1770_);
lean_inc_ref(v___x_1763_);
v___x_1772_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1772_, 0, v___x_1763_);
lean_ctor_set(v___x_1772_, 1, v___x_1771_);
v___x_1773_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1773_, 0, v___x_1760_);
lean_ctor_set(v___x_1773_, 1, v___x_1772_);
v___x_1774_ = l_Lean_Json_mkObj(v___x_1773_);
lean_dec_ref_known(v___x_1773_, 2);
v___x_1775_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_1774_);
if (lean_obj_tag(v___x_1775_) == 0)
{
lean_object* v___x_1777_; uint8_t v_isShared_1778_; uint8_t v_isSharedCheck_1880_; 
v_isSharedCheck_1880_ = !lean_is_exclusive(v___x_1775_);
if (v_isSharedCheck_1880_ == 0)
{
lean_object* v_unused_1881_; 
v_unused_1881_ = lean_ctor_get(v___x_1775_, 0);
lean_dec(v_unused_1881_);
v___x_1777_ = v___x_1775_;
v_isShared_1778_ = v_isSharedCheck_1880_;
goto v_resetjp_1776_;
}
else
{
lean_dec(v___x_1775_);
v___x_1777_ = lean_box(0);
v_isShared_1778_ = v_isSharedCheck_1880_;
goto v_resetjp_1776_;
}
v_resetjp_1776_:
{
lean_object* v___x_1779_; lean_object* v___x_1780_; 
v___x_1779_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__11));
v___x_1780_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_wait_1752_, v___x_1779_);
if (lean_obj_tag(v___x_1780_) == 0)
{
lean_object* v___x_1782_; uint8_t v_isShared_1783_; uint8_t v_isSharedCheck_1878_; 
v_isSharedCheck_1878_ = !lean_is_exclusive(v___x_1780_);
if (v_isSharedCheck_1878_ == 0)
{
lean_object* v_unused_1879_; 
v_unused_1879_ = lean_ctor_get(v___x_1780_, 0);
lean_dec(v_unused_1879_);
v___x_1782_ = v___x_1780_;
v_isShared_1783_ = v_isSharedCheck_1878_;
goto v_resetjp_1781_;
}
else
{
lean_dec(v___x_1780_);
v___x_1782_ = lean_box(0);
v_isShared_1783_ = v_isSharedCheck_1878_;
goto v_resetjp_1781_;
}
v_resetjp_1781_:
{
lean_object* v___x_1784_; 
v___x_1784_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode(v___y_1759_);
if (lean_obj_tag(v___x_1784_) == 0)
{
lean_object* v_a_1785_; lean_object* v_fst_1786_; lean_object* v_snd_1787_; lean_object* v___x_1789_; uint8_t v_isShared_1790_; uint8_t v_isSharedCheck_1869_; 
v_a_1785_ = lean_ctor_get(v___x_1784_, 0);
lean_inc(v_a_1785_);
lean_dec_ref_known(v___x_1784_, 1);
v_fst_1786_ = lean_ctor_get(v_a_1785_, 0);
v_snd_1787_ = lean_ctor_get(v_a_1785_, 1);
v_isSharedCheck_1869_ = !lean_is_exclusive(v_a_1785_);
if (v_isSharedCheck_1869_ == 0)
{
v___x_1789_ = v_a_1785_;
v_isShared_1790_ = v_isSharedCheck_1869_;
goto v_resetjp_1788_;
}
else
{
lean_inc(v_snd_1787_);
lean_inc(v_fst_1786_);
lean_dec(v_a_1785_);
v___x_1789_ = lean_box(0);
v_isShared_1790_ = v_isSharedCheck_1869_;
goto v_resetjp_1788_;
}
v_resetjp_1788_:
{
lean_object* v___x_1791_; lean_object* v___x_1792_; lean_object* v___x_1793_; lean_object* v___x_1794_; lean_object* v___x_1796_; 
v___x_1791_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__14));
v___x_1792_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__15));
v___x_1793_ = lean_array_get_size(v_fst_1786_);
v___x_1794_ = l_Lean_JsonNumber_fromNat(v___x_1793_);
if (v_isShared_1783_ == 0)
{
lean_ctor_set_tag(v___x_1782_, 2);
lean_ctor_set(v___x_1782_, 0, v___x_1794_);
v___x_1796_ = v___x_1782_;
goto v_reusejp_1795_;
}
else
{
lean_object* v_reuseFailAlloc_1868_; 
v_reuseFailAlloc_1868_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1868_, 0, v___x_1794_);
v___x_1796_ = v_reuseFailAlloc_1868_;
goto v_reusejp_1795_;
}
v_reusejp_1795_:
{
lean_object* v___x_1798_; 
if (v_isShared_1790_ == 0)
{
lean_ctor_set(v___x_1789_, 1, v___x_1796_);
lean_ctor_set(v___x_1789_, 0, v___x_1792_);
v___x_1798_ = v___x_1789_;
goto v_reusejp_1797_;
}
else
{
lean_object* v_reuseFailAlloc_1867_; 
v_reuseFailAlloc_1867_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1867_, 0, v___x_1792_);
lean_ctor_set(v_reuseFailAlloc_1867_, 1, v___x_1796_);
v___x_1798_ = v_reuseFailAlloc_1867_;
goto v_reusejp_1797_;
}
v_reusejp_1797_:
{
lean_object* v___x_1799_; lean_object* v___x_1800_; lean_object* v___x_1802_; 
v___x_1799_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__16));
v___x_1800_ = l_Lean_JsonNumber_fromNat(v_snd_1787_);
if (v_isShared_1778_ == 0)
{
lean_ctor_set_tag(v___x_1777_, 2);
lean_ctor_set(v___x_1777_, 0, v___x_1800_);
v___x_1802_ = v___x_1777_;
goto v_reusejp_1801_;
}
else
{
lean_object* v_reuseFailAlloc_1866_; 
v_reuseFailAlloc_1866_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1866_, 0, v___x_1800_);
v___x_1802_ = v_reuseFailAlloc_1866_;
goto v_reusejp_1801_;
}
v_reusejp_1801_:
{
lean_object* v___x_1803_; lean_object* v___x_1804_; lean_object* v___x_1805_; lean_object* v___x_1806_; lean_object* v___x_1807_; lean_object* v___x_1808_; lean_object* v___x_1809_; 
v___x_1803_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1803_, 0, v___x_1799_);
lean_ctor_set(v___x_1803_, 1, v___x_1802_);
v___x_1804_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1804_, 0, v___x_1803_);
lean_ctor_set(v___x_1804_, 1, v___x_1769_);
lean_inc_ref(v___x_1804_);
v___x_1805_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1805_, 0, v___x_1798_);
lean_ctor_set(v___x_1805_, 1, v___x_1804_);
lean_inc_ref(v___x_1763_);
v___x_1806_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1806_, 0, v___x_1763_);
lean_ctor_set(v___x_1806_, 1, v___x_1805_);
v___x_1807_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1807_, 0, v___x_1791_);
lean_ctor_set(v___x_1807_, 1, v___x_1806_);
v___x_1808_ = l_Lean_Json_mkObj(v___x_1807_);
lean_dec_ref_known(v___x_1807_, 2);
v___x_1809_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_1808_);
if (lean_obj_tag(v___x_1809_) == 0)
{
lean_object* v___x_1810_; lean_object* v___x_1811_; 
lean_dec_ref_known(v___x_1809_, 1);
v___x_1810_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__17));
v___x_1811_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_wait_1752_, v___x_1810_);
if (lean_obj_tag(v___x_1811_) == 0)
{
lean_object* v___x_1812_; 
lean_dec_ref_known(v___x_1811_, 1);
v___x_1812_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume(v___y_1759_, v_fst_1786_);
if (lean_obj_tag(v___x_1812_) == 0)
{
lean_object* v_a_1813_; lean_object* v_fst_1814_; lean_object* v_snd_1815_; lean_object* v___x_1817_; uint8_t v_isShared_1818_; uint8_t v_isSharedCheck_1857_; 
v_a_1813_ = lean_ctor_get(v___x_1812_, 0);
lean_inc(v_a_1813_);
lean_dec_ref_known(v___x_1812_, 1);
v_fst_1814_ = lean_ctor_get(v_a_1813_, 0);
v_snd_1815_ = lean_ctor_get(v_a_1813_, 1);
v_isSharedCheck_1857_ = !lean_is_exclusive(v_a_1813_);
if (v_isSharedCheck_1857_ == 0)
{
v___x_1817_ = v_a_1813_;
v_isShared_1818_ = v_isSharedCheck_1857_;
goto v_resetjp_1816_;
}
else
{
lean_inc(v_snd_1815_);
lean_inc(v_fst_1814_);
lean_dec(v_a_1813_);
v___x_1817_ = lean_box(0);
v_isShared_1818_ = v_isSharedCheck_1857_;
goto v_resetjp_1816_;
}
v_resetjp_1816_:
{
lean_object* v___x_1819_; lean_object* v___x_1820_; lean_object* v___x_1821_; lean_object* v___x_1823_; 
v___x_1819_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__20));
v___x_1820_ = ((lean_object*)(l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0___closed__0));
v___x_1821_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(v_fst_1814_);
if (v_isShared_1818_ == 0)
{
lean_ctor_set(v___x_1817_, 1, v___x_1821_);
lean_ctor_set(v___x_1817_, 0, v___x_1820_);
v___x_1823_ = v___x_1817_;
goto v_reusejp_1822_;
}
else
{
lean_object* v_reuseFailAlloc_1856_; 
v_reuseFailAlloc_1856_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1856_, 0, v___x_1820_);
lean_ctor_set(v_reuseFailAlloc_1856_, 1, v___x_1821_);
v___x_1823_ = v_reuseFailAlloc_1856_;
goto v_reusejp_1822_;
}
v_reusejp_1822_:
{
lean_object* v___x_1824_; lean_object* v___x_1825_; lean_object* v___x_1826_; lean_object* v___x_1827_; lean_object* v___x_1828_; lean_object* v___x_1829_; lean_object* v___x_1830_; lean_object* v___x_1831_; lean_object* v___x_1832_; lean_object* v___x_1833_; lean_object* v___x_1834_; lean_object* v___x_1835_; 
v___x_1824_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__7));
v___x_1825_ = lean_array_to_list(v_snd_1815_);
v___x_1826_ = l_List_zipIdxTR___redArg(v___x_1825_, v___x_1757_);
v___x_1827_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0(v___x_1826_, v___x_1769_);
v___x_1828_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___x_1827_);
v___x_1829_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1829_, 0, v___x_1824_);
lean_ctor_set(v___x_1829_, 1, v___x_1828_);
v___x_1830_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1830_, 0, v___x_1829_);
lean_ctor_set(v___x_1830_, 1, v___x_1804_);
v___x_1831_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1831_, 0, v___x_1823_);
lean_ctor_set(v___x_1831_, 1, v___x_1830_);
v___x_1832_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1832_, 0, v___x_1763_);
lean_ctor_set(v___x_1832_, 1, v___x_1831_);
v___x_1833_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1833_, 0, v___x_1819_);
lean_ctor_set(v___x_1833_, 1, v___x_1832_);
v___x_1834_ = l_Lean_Json_mkObj(v___x_1833_);
lean_dec_ref_known(v___x_1833_, 2);
v___x_1835_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_1834_);
if (lean_obj_tag(v___x_1835_) == 0)
{
lean_object* v___x_1837_; uint8_t v_isShared_1838_; uint8_t v_isSharedCheck_1854_; 
v_isSharedCheck_1854_ = !lean_is_exclusive(v___x_1835_);
if (v_isSharedCheck_1854_ == 0)
{
lean_object* v_unused_1855_; 
v_unused_1855_ = lean_ctor_get(v___x_1835_, 0);
lean_dec(v_unused_1855_);
v___x_1837_ = v___x_1835_;
v_isShared_1838_ = v_isSharedCheck_1854_;
goto v_resetjp_1836_;
}
else
{
lean_dec(v___x_1835_);
v___x_1837_ = lean_box(0);
v_isShared_1838_ = v_isSharedCheck_1854_;
goto v_resetjp_1836_;
}
v_resetjp_1836_:
{
if (v_withCensus_1751_ == 0)
{
lean_object* v___x_1839_; lean_object* v___x_1841_; 
lean_dec(v_fst_1786_);
lean_dec_ref(v___y_1759_);
v___x_1839_ = lean_box(0);
if (v_isShared_1838_ == 0)
{
lean_ctor_set(v___x_1837_, 0, v___x_1839_);
v___x_1841_ = v___x_1837_;
goto v_reusejp_1840_;
}
else
{
lean_object* v_reuseFailAlloc_1842_; 
v_reuseFailAlloc_1842_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1842_, 0, v___x_1839_);
v___x_1841_ = v_reuseFailAlloc_1842_;
goto v_reusejp_1840_;
}
v_reusejp_1840_:
{
return v___x_1841_;
}
}
else
{
lean_object* v___x_1843_; 
lean_del_object(v___x_1837_);
v___x_1843_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census(v___y_1759_, v_fst_1786_);
lean_dec(v_fst_1786_);
lean_dec_ref(v___y_1759_);
if (lean_obj_tag(v___x_1843_) == 0)
{
lean_object* v_a_1844_; lean_object* v___x_1845_; 
v_a_1844_ = lean_ctor_get(v___x_1843_, 0);
lean_inc(v_a_1844_);
lean_dec_ref_known(v___x_1843_, 1);
v___x_1845_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v_a_1844_);
return v___x_1845_;
}
else
{
lean_object* v_a_1846_; lean_object* v___x_1848_; uint8_t v_isShared_1849_; uint8_t v_isSharedCheck_1853_; 
v_a_1846_ = lean_ctor_get(v___x_1843_, 0);
v_isSharedCheck_1853_ = !lean_is_exclusive(v___x_1843_);
if (v_isSharedCheck_1853_ == 0)
{
v___x_1848_ = v___x_1843_;
v_isShared_1849_ = v_isSharedCheck_1853_;
goto v_resetjp_1847_;
}
else
{
lean_inc(v_a_1846_);
lean_dec(v___x_1843_);
v___x_1848_ = lean_box(0);
v_isShared_1849_ = v_isSharedCheck_1853_;
goto v_resetjp_1847_;
}
v_resetjp_1847_:
{
lean_object* v___x_1851_; 
if (v_isShared_1849_ == 0)
{
v___x_1851_ = v___x_1848_;
goto v_reusejp_1850_;
}
else
{
lean_object* v_reuseFailAlloc_1852_; 
v_reuseFailAlloc_1852_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1852_, 0, v_a_1846_);
v___x_1851_ = v_reuseFailAlloc_1852_;
goto v_reusejp_1850_;
}
v_reusejp_1850_:
{
return v___x_1851_;
}
}
}
}
}
}
else
{
lean_dec(v_fst_1786_);
lean_dec_ref(v___y_1759_);
return v___x_1835_;
}
}
}
}
else
{
lean_object* v_a_1858_; lean_object* v___x_1860_; uint8_t v_isShared_1861_; uint8_t v_isSharedCheck_1865_; 
lean_dec_ref_known(v___x_1804_, 2);
lean_dec(v_fst_1786_);
lean_dec_ref_known(v___x_1763_, 2);
lean_dec_ref(v___y_1759_);
v_a_1858_ = lean_ctor_get(v___x_1812_, 0);
v_isSharedCheck_1865_ = !lean_is_exclusive(v___x_1812_);
if (v_isSharedCheck_1865_ == 0)
{
v___x_1860_ = v___x_1812_;
v_isShared_1861_ = v_isSharedCheck_1865_;
goto v_resetjp_1859_;
}
else
{
lean_inc(v_a_1858_);
lean_dec(v___x_1812_);
v___x_1860_ = lean_box(0);
v_isShared_1861_ = v_isSharedCheck_1865_;
goto v_resetjp_1859_;
}
v_resetjp_1859_:
{
lean_object* v___x_1863_; 
if (v_isShared_1861_ == 0)
{
v___x_1863_ = v___x_1860_;
goto v_reusejp_1862_;
}
else
{
lean_object* v_reuseFailAlloc_1864_; 
v_reuseFailAlloc_1864_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1864_, 0, v_a_1858_);
v___x_1863_ = v_reuseFailAlloc_1864_;
goto v_reusejp_1862_;
}
v_reusejp_1862_:
{
return v___x_1863_;
}
}
}
}
else
{
lean_dec_ref_known(v___x_1804_, 2);
lean_dec(v_fst_1786_);
lean_dec_ref_known(v___x_1763_, 2);
lean_dec_ref(v___y_1759_);
return v___x_1811_;
}
}
else
{
lean_dec_ref_known(v___x_1804_, 2);
lean_dec(v_fst_1786_);
lean_dec_ref_known(v___x_1763_, 2);
lean_dec_ref(v___y_1759_);
return v___x_1809_;
}
}
}
}
}
}
else
{
lean_object* v_a_1870_; lean_object* v___x_1872_; uint8_t v_isShared_1873_; uint8_t v_isSharedCheck_1877_; 
lean_del_object(v___x_1782_);
lean_del_object(v___x_1777_);
lean_dec_ref_known(v___x_1763_, 2);
lean_dec_ref(v___y_1759_);
v_a_1870_ = lean_ctor_get(v___x_1784_, 0);
v_isSharedCheck_1877_ = !lean_is_exclusive(v___x_1784_);
if (v_isSharedCheck_1877_ == 0)
{
v___x_1872_ = v___x_1784_;
v_isShared_1873_ = v_isSharedCheck_1877_;
goto v_resetjp_1871_;
}
else
{
lean_inc(v_a_1870_);
lean_dec(v___x_1784_);
v___x_1872_ = lean_box(0);
v_isShared_1873_ = v_isSharedCheck_1877_;
goto v_resetjp_1871_;
}
v_resetjp_1871_:
{
lean_object* v___x_1875_; 
if (v_isShared_1873_ == 0)
{
v___x_1875_ = v___x_1872_;
goto v_reusejp_1874_;
}
else
{
lean_object* v_reuseFailAlloc_1876_; 
v_reuseFailAlloc_1876_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1876_, 0, v_a_1870_);
v___x_1875_ = v_reuseFailAlloc_1876_;
goto v_reusejp_1874_;
}
v_reusejp_1874_:
{
return v___x_1875_;
}
}
}
}
}
else
{
lean_del_object(v___x_1777_);
lean_dec_ref_known(v___x_1763_, 2);
lean_dec_ref(v___y_1759_);
return v___x_1780_;
}
}
}
else
{
lean_dec_ref_known(v___x_1763_, 2);
lean_dec_ref(v___y_1759_);
return v___x_1775_;
}
}
}
else
{
lean_object* v_a_1892_; lean_object* v___x_1894_; uint8_t v_isShared_1895_; uint8_t v_isSharedCheck_1899_; 
lean_dec_ref(v_mode_1749_);
v_a_1892_ = lean_ctor_get(v___x_1755_, 0);
v_isSharedCheck_1899_ = !lean_is_exclusive(v___x_1755_);
if (v_isSharedCheck_1899_ == 0)
{
v___x_1894_ = v___x_1755_;
v_isShared_1895_ = v_isSharedCheck_1899_;
goto v_resetjp_1893_;
}
else
{
lean_inc(v_a_1892_);
lean_dec(v___x_1755_);
v___x_1894_ = lean_box(0);
v_isShared_1895_ = v_isSharedCheck_1899_;
goto v_resetjp_1893_;
}
v_resetjp_1893_:
{
lean_object* v___x_1897_; 
if (v_isShared_1895_ == 0)
{
v___x_1897_ = v___x_1894_;
goto v_reusejp_1896_;
}
else
{
lean_object* v_reuseFailAlloc_1898_; 
v_reuseFailAlloc_1898_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1898_, 0, v_a_1892_);
v___x_1897_ = v_reuseFailAlloc_1898_;
goto v_reusejp_1896_;
}
v_reusejp_1896_:
{
return v___x_1897_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___boxed(lean_object* v_mode_1900_, lean_object* v_inputs_1901_, lean_object* v_withCensus_1902_, lean_object* v_wait_1903_, lean_object* v_a_1904_){
_start:
{
uint8_t v_withCensus_boxed_1905_; uint8_t v_wait_boxed_1906_; lean_object* v_res_1907_; 
v_withCensus_boxed_1905_ = lean_unbox(v_withCensus_1902_);
v_wait_boxed_1906_ = lean_unbox(v_wait_1903_);
v_res_1907_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode(v_mode_1900_, v_inputs_1901_, v_withCensus_boxed_1905_, v_wait_boxed_1906_);
lean_dec_ref(v_inputs_1901_);
return v_res_1907_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0(lean_object* v_register_1914_, lean_object* v_as_1915_, size_t v_sz_1916_, size_t v_i_1917_, lean_object* v_b_1918_){
_start:
{
lean_object* v_a_1921_; uint8_t v___x_1925_; 
v___x_1925_ = lean_usize_dec_lt(v_i_1917_, v_sz_1916_);
if (v___x_1925_ == 0)
{
lean_object* v___x_1926_; 
v___x_1926_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1926_, 0, v_b_1918_);
return v___x_1926_;
}
else
{
lean_object* v_fst_1927_; lean_object* v_snd_1928_; lean_object* v___x_1930_; uint8_t v_isShared_1931_; uint8_t v_isSharedCheck_1984_; 
v_fst_1927_ = lean_ctor_get(v_b_1918_, 0);
v_snd_1928_ = lean_ctor_get(v_b_1918_, 1);
v_isSharedCheck_1984_ = !lean_is_exclusive(v_b_1918_);
if (v_isSharedCheck_1984_ == 0)
{
v___x_1930_ = v_b_1918_;
v_isShared_1931_ = v_isSharedCheck_1984_;
goto v_resetjp_1929_;
}
else
{
lean_inc(v_snd_1928_);
lean_inc(v_fst_1927_);
lean_dec(v_b_1918_);
v___x_1930_ = lean_box(0);
v_isShared_1931_ = v_isSharedCheck_1984_;
goto v_resetjp_1929_;
}
v_resetjp_1929_:
{
lean_object* v_a_1932_; lean_object* v_df_1933_; lean_object* v_bytes_1934_; lean_object* v___x_1936_; uint8_t v_isShared_1937_; uint8_t v_isSharedCheck_1983_; 
v_a_1932_ = lean_array_uget(v_as_1915_, v_i_1917_);
v_df_1933_ = lean_ctor_get(v_a_1932_, 0);
v_bytes_1934_ = lean_ctor_get(v_a_1932_, 1);
v_isSharedCheck_1983_ = !lean_is_exclusive(v_a_1932_);
if (v_isSharedCheck_1983_ == 0)
{
v___x_1936_ = v_a_1932_;
v_isShared_1937_ = v_isSharedCheck_1983_;
goto v_resetjp_1935_;
}
else
{
lean_inc(v_bytes_1934_);
lean_inc(v_df_1933_);
lean_dec(v_a_1932_);
v___x_1936_ = lean_box(0);
v_isShared_1937_ = v_isSharedCheck_1983_;
goto v_resetjp_1935_;
}
v_resetjp_1935_:
{
lean_object* v_nonempty_1938_; lean_object* v___x_1976_; uint8_t v___x_1977_; 
v_nonempty_1938_ = lean_unsigned_to_nat(0u);
v___x_1976_ = lean_unsigned_to_nat(20u);
v___x_1977_ = lean_nat_dec_eq(v_df_1933_, v___x_1976_);
if (v___x_1977_ == 0)
{
lean_object* v___x_1978_; uint8_t v___x_1979_; 
v___x_1978_ = lean_unsigned_to_nat(21u);
v___x_1979_ = lean_nat_dec_eq(v_df_1933_, v___x_1978_);
if (v___x_1979_ == 0)
{
lean_object* v___x_1981_; 
lean_dec(v_bytes_1934_);
lean_dec(v_df_1933_);
lean_del_object(v___x_1930_);
if (v_isShared_1937_ == 0)
{
lean_ctor_set(v___x_1936_, 1, v_snd_1928_);
lean_ctor_set(v___x_1936_, 0, v_fst_1927_);
v___x_1981_ = v___x_1936_;
goto v_reusejp_1980_;
}
else
{
lean_object* v_reuseFailAlloc_1982_; 
v_reuseFailAlloc_1982_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1982_, 0, v_fst_1927_);
lean_ctor_set(v_reuseFailAlloc_1982_, 1, v_snd_1928_);
v___x_1981_ = v_reuseFailAlloc_1982_;
goto v_reusejp_1980_;
}
v_reusejp_1980_:
{
v_a_1921_ = v___x_1981_;
goto v___jp_1920_;
}
}
else
{
lean_del_object(v___x_1936_);
goto v___jp_1939_;
}
}
else
{
lean_del_object(v___x_1936_);
goto v___jp_1939_;
}
v___jp_1939_:
{
lean_object* v___x_1940_; 
v___x_1940_ = lp_lean1090_Lean1090_Impl_decodeFrame(v_bytes_1934_);
lean_dec(v_bytes_1934_);
if (lean_obj_tag(v___x_1940_) == 1)
{
lean_object* v_val_1941_; lean_object* v___x_1943_; uint8_t v_isShared_1944_; uint8_t v_isSharedCheck_1973_; 
v_val_1941_ = lean_ctor_get(v___x_1940_, 0);
v_isSharedCheck_1973_ = !lean_is_exclusive(v___x_1940_);
if (v_isSharedCheck_1973_ == 0)
{
v___x_1943_ = v___x_1940_;
v_isShared_1944_ = v_isSharedCheck_1973_;
goto v_resetjp_1942_;
}
else
{
lean_inc(v_val_1941_);
lean_dec(v___x_1940_);
v___x_1943_ = lean_box(0);
v_isShared_1944_ = v_isSharedCheck_1973_;
goto v_resetjp_1942_;
}
v_resetjp_1942_:
{
lean_object* v_body_1945_; lean_object* v___x_1947_; uint8_t v_isShared_1948_; uint8_t v_isSharedCheck_1971_; 
v_body_1945_ = lean_ctor_get(v_val_1941_, 0);
v_isSharedCheck_1971_ = !lean_is_exclusive(v_val_1941_);
if (v_isSharedCheck_1971_ == 0)
{
lean_object* v_unused_1972_; 
v_unused_1972_ = lean_ctor_get(v_val_1941_, 1);
lean_dec(v_unused_1972_);
v___x_1947_ = v_val_1941_;
v_isShared_1948_ = v_isSharedCheck_1971_;
goto v_resetjp_1946_;
}
else
{
lean_inc(v_body_1945_);
lean_dec(v_val_1941_);
v___x_1947_ = lean_box(0);
v_isShared_1948_ = v_isSharedCheck_1971_;
goto v_resetjp_1946_;
}
v_resetjp_1946_:
{
if (lean_obj_tag(v_body_1945_) == 6)
{
lean_object* v_mb_1949_; uint8_t v___x_1950_; 
lean_del_object(v___x_1943_);
v_mb_1949_ = lean_ctor_get(v_body_1945_, 1);
lean_inc(v_mb_1949_);
lean_dec_ref_known(v_body_1945_, 2);
v___x_1950_ = lean_nat_dec_eq(v_mb_1949_, v_nonempty_1938_);
if (v___x_1950_ == 0)
{
lean_object* v___x_1951_; lean_object* v___x_1952_; uint8_t v___x_1953_; 
v___x_1951_ = lean_unsigned_to_nat(1u);
v___x_1952_ = lean_nat_add(v_snd_1928_, v___x_1951_);
lean_dec(v_snd_1928_);
v___x_1953_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1914_, v_mb_1949_);
if (v___x_1953_ == 0)
{
lean_object* v___x_1955_; 
lean_dec(v_mb_1949_);
lean_del_object(v___x_1947_);
lean_dec(v_df_1933_);
if (v_isShared_1931_ == 0)
{
lean_ctor_set(v___x_1930_, 1, v___x_1952_);
v___x_1955_ = v___x_1930_;
goto v_reusejp_1954_;
}
else
{
lean_object* v_reuseFailAlloc_1956_; 
v_reuseFailAlloc_1956_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1956_, 0, v_fst_1927_);
lean_ctor_set(v_reuseFailAlloc_1956_, 1, v___x_1952_);
v___x_1955_ = v_reuseFailAlloc_1956_;
goto v_reusejp_1954_;
}
v_reusejp_1954_:
{
v_a_1921_ = v___x_1955_;
goto v___jp_1920_;
}
}
else
{
lean_object* v___x_1958_; 
if (v_isShared_1948_ == 0)
{
lean_ctor_set(v___x_1947_, 1, v_mb_1949_);
lean_ctor_set(v___x_1947_, 0, v_df_1933_);
v___x_1958_ = v___x_1947_;
goto v_reusejp_1957_;
}
else
{
lean_object* v_reuseFailAlloc_1963_; 
v_reuseFailAlloc_1963_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1963_, 0, v_df_1933_);
lean_ctor_set(v_reuseFailAlloc_1963_, 1, v_mb_1949_);
v___x_1958_ = v_reuseFailAlloc_1963_;
goto v_reusejp_1957_;
}
v_reusejp_1957_:
{
lean_object* v___x_1959_; lean_object* v___x_1961_; 
v___x_1959_ = lean_array_push(v_fst_1927_, v___x_1958_);
if (v_isShared_1931_ == 0)
{
lean_ctor_set(v___x_1930_, 1, v___x_1952_);
lean_ctor_set(v___x_1930_, 0, v___x_1959_);
v___x_1961_ = v___x_1930_;
goto v_reusejp_1960_;
}
else
{
lean_object* v_reuseFailAlloc_1962_; 
v_reuseFailAlloc_1962_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1962_, 0, v___x_1959_);
lean_ctor_set(v_reuseFailAlloc_1962_, 1, v___x_1952_);
v___x_1961_ = v_reuseFailAlloc_1962_;
goto v_reusejp_1960_;
}
v_reusejp_1960_:
{
v_a_1921_ = v___x_1961_;
goto v___jp_1920_;
}
}
}
}
else
{
lean_object* v___x_1965_; 
lean_dec(v_mb_1949_);
lean_del_object(v___x_1947_);
lean_dec(v_df_1933_);
if (v_isShared_1931_ == 0)
{
v___x_1965_ = v___x_1930_;
goto v_reusejp_1964_;
}
else
{
lean_object* v_reuseFailAlloc_1966_; 
v_reuseFailAlloc_1966_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1966_, 0, v_fst_1927_);
lean_ctor_set(v_reuseFailAlloc_1966_, 1, v_snd_1928_);
v___x_1965_ = v_reuseFailAlloc_1966_;
goto v_reusejp_1964_;
}
v_reusejp_1964_:
{
v_a_1921_ = v___x_1965_;
goto v___jp_1920_;
}
}
}
else
{
lean_object* v___x_1967_; lean_object* v___x_1969_; 
lean_del_object(v___x_1947_);
lean_dec_ref(v_body_1945_);
lean_dec(v_df_1933_);
lean_del_object(v___x_1930_);
lean_dec(v_snd_1928_);
lean_dec(v_fst_1927_);
v___x_1967_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__1));
if (v_isShared_1944_ == 0)
{
lean_ctor_set(v___x_1943_, 0, v___x_1967_);
v___x_1969_ = v___x_1943_;
goto v_reusejp_1968_;
}
else
{
lean_object* v_reuseFailAlloc_1970_; 
v_reuseFailAlloc_1970_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1970_, 0, v___x_1967_);
v___x_1969_ = v_reuseFailAlloc_1970_;
goto v_reusejp_1968_;
}
v_reusejp_1968_:
{
return v___x_1969_;
}
}
}
}
}
else
{
lean_object* v___x_1974_; lean_object* v___x_1975_; 
lean_dec(v___x_1940_);
lean_dec(v_df_1933_);
lean_del_object(v___x_1930_);
lean_dec(v_snd_1928_);
lean_dec(v_fst_1927_);
v___x_1974_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__3));
v___x_1975_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1975_, 0, v___x_1974_);
return v___x_1975_;
}
}
}
}
}
v___jp_1920_:
{
size_t v___x_1922_; size_t v___x_1923_; 
v___x_1922_ = ((size_t)1ULL);
v___x_1923_ = lean_usize_add(v_i_1917_, v___x_1922_);
v_i_1917_ = v___x_1923_;
v_b_1918_ = v_a_1921_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___boxed(lean_object* v_register_1985_, lean_object* v_as_1986_, lean_object* v_sz_1987_, lean_object* v_i_1988_, lean_object* v_b_1989_, lean_object* v___y_1990_){
_start:
{
size_t v_sz_boxed_1991_; size_t v_i_boxed_1992_; lean_object* v_res_1993_; 
v_sz_boxed_1991_ = lean_unbox_usize(v_sz_1987_);
lean_dec(v_sz_1987_);
v_i_boxed_1992_ = lean_unbox_usize(v_i_1988_);
lean_dec(v_i_1988_);
v_res_1993_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0(v_register_1985_, v_as_1986_, v_sz_boxed_1991_, v_i_boxed_1992_, v_b_1989_);
lean_dec_ref(v_as_1986_);
lean_dec(v_register_1985_);
return v_res_1993_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores(lean_object* v_inputs_1999_, lean_object* v_register_2000_){
_start:
{
lean_object* v___x_2002_; size_t v_sz_2003_; size_t v___x_2004_; lean_object* v___x_2005_; 
v___x_2002_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__1));
v_sz_2003_ = lean_array_size(v_inputs_1999_);
v___x_2004_ = ((size_t)0ULL);
v___x_2005_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0(v_register_2000_, v_inputs_1999_, v_sz_2003_, v___x_2004_, v___x_2002_);
if (lean_obj_tag(v___x_2005_) == 0)
{
lean_object* v_a_2006_; lean_object* v___x_2008_; uint8_t v_isShared_2009_; uint8_t v_isSharedCheck_2022_; 
v_a_2006_ = lean_ctor_get(v___x_2005_, 0);
v_isSharedCheck_2022_ = !lean_is_exclusive(v___x_2005_);
if (v_isSharedCheck_2022_ == 0)
{
v___x_2008_ = v___x_2005_;
v_isShared_2009_ = v_isSharedCheck_2022_;
goto v_resetjp_2007_;
}
else
{
lean_inc(v_a_2006_);
lean_dec(v___x_2005_);
v___x_2008_ = lean_box(0);
v_isShared_2009_ = v_isSharedCheck_2022_;
goto v_resetjp_2007_;
}
v_resetjp_2007_:
{
lean_object* v_fst_2010_; lean_object* v_snd_2011_; lean_object* v___x_2013_; uint8_t v_isShared_2014_; uint8_t v_isSharedCheck_2021_; 
v_fst_2010_ = lean_ctor_get(v_a_2006_, 0);
v_snd_2011_ = lean_ctor_get(v_a_2006_, 1);
v_isSharedCheck_2021_ = !lean_is_exclusive(v_a_2006_);
if (v_isSharedCheck_2021_ == 0)
{
v___x_2013_ = v_a_2006_;
v_isShared_2014_ = v_isSharedCheck_2021_;
goto v_resetjp_2012_;
}
else
{
lean_inc(v_snd_2011_);
lean_inc(v_fst_2010_);
lean_dec(v_a_2006_);
v___x_2013_ = lean_box(0);
v_isShared_2014_ = v_isSharedCheck_2021_;
goto v_resetjp_2012_;
}
v_resetjp_2012_:
{
lean_object* v___x_2016_; 
if (v_isShared_2014_ == 0)
{
v___x_2016_ = v___x_2013_;
goto v_reusejp_2015_;
}
else
{
lean_object* v_reuseFailAlloc_2020_; 
v_reuseFailAlloc_2020_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2020_, 0, v_fst_2010_);
lean_ctor_set(v_reuseFailAlloc_2020_, 1, v_snd_2011_);
v___x_2016_ = v_reuseFailAlloc_2020_;
goto v_reusejp_2015_;
}
v_reusejp_2015_:
{
lean_object* v___x_2018_; 
if (v_isShared_2009_ == 0)
{
lean_ctor_set(v___x_2008_, 0, v___x_2016_);
v___x_2018_ = v___x_2008_;
goto v_reusejp_2017_;
}
else
{
lean_object* v_reuseFailAlloc_2019_; 
v_reuseFailAlloc_2019_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2019_, 0, v___x_2016_);
v___x_2018_ = v_reuseFailAlloc_2019_;
goto v_reusejp_2017_;
}
v_reusejp_2017_:
{
return v___x_2018_;
}
}
}
}
}
else
{
return v___x_2005_;
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___boxed(lean_object* v_inputs_2023_, lean_object* v_register_2024_, lean_object* v_a_2025_){
_start:
{
lean_object* v_res_2026_; 
v_res_2026_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores(v_inputs_2023_, v_register_2024_);
lean_dec(v_register_2024_);
lean_dec_ref(v_inputs_2023_);
return v_res_2026_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0(lean_object* v_register_2027_, lean_object* v_as_2028_, size_t v_sz_2029_, size_t v_i_2030_, lean_object* v_b_2031_){
_start:
{
uint8_t v___x_2033_; 
v___x_2033_ = lean_usize_dec_lt(v_i_2030_, v_sz_2029_);
if (v___x_2033_ == 0)
{
lean_object* v___x_2034_; 
v___x_2034_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2034_, 0, v_b_2031_);
return v___x_2034_;
}
else
{
lean_object* v_a_2035_; lean_object* v_word_2036_; uint8_t v___x_2037_; lean_object* v___x_2038_; lean_object* v___x_2039_; size_t v___x_2040_; size_t v___x_2041_; 
v_a_2035_ = lean_array_uget_borrowed(v_as_2028_, v_i_2030_);
v_word_2036_ = lean_ctor_get(v_a_2035_, 1);
v___x_2037_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2027_, v_word_2036_);
v___x_2038_ = lean_box(v___x_2037_);
v___x_2039_ = lean_array_push(v_b_2031_, v___x_2038_);
v___x_2040_ = ((size_t)1ULL);
v___x_2041_ = lean_usize_add(v_i_2030_, v___x_2040_);
v_i_2030_ = v___x_2041_;
v_b_2031_ = v___x_2039_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0___boxed(lean_object* v_register_2043_, lean_object* v_as_2044_, lean_object* v_sz_2045_, lean_object* v_i_2046_, lean_object* v_b_2047_, lean_object* v___y_2048_){
_start:
{
size_t v_sz_boxed_2049_; size_t v_i_boxed_2050_; lean_object* v_res_2051_; 
v_sz_boxed_2049_ = lean_unbox_usize(v_sz_2045_);
lean_dec(v_sz_2045_);
v_i_boxed_2050_ = lean_unbox_usize(v_i_2046_);
lean_dec(v_i_2046_);
v_res_2051_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0(v_register_2043_, v_as_2044_, v_sz_boxed_2049_, v_i_boxed_2050_, v_b_2047_);
lean_dec_ref(v_as_2044_);
lean_dec(v_register_2043_);
return v_res_2051_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores(lean_object* v_register_2052_, lean_object* v_inputs_2053_){
_start:
{
lean_object* v___x_2055_; lean_object* v_output_2056_; lean_object* v___x_2057_; size_t v_sz_2058_; size_t v___x_2059_; lean_object* v___x_2060_; 
v___x_2055_ = lean_array_get_size(v_inputs_2053_);
v_output_2056_ = lean_mk_empty_array_with_capacity(v___x_2055_);
v___x_2057_ = lean_io_get_num_heartbeats();
v_sz_2058_ = lean_array_size(v_inputs_2053_);
v___x_2059_ = ((size_t)0ULL);
v___x_2060_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0(v_register_2052_, v_inputs_2053_, v_sz_2058_, v___x_2059_, v_output_2056_);
if (lean_obj_tag(v___x_2060_) == 0)
{
lean_object* v_a_2061_; lean_object* v___x_2063_; uint8_t v_isShared_2064_; uint8_t v_isSharedCheck_2071_; 
v_a_2061_ = lean_ctor_get(v___x_2060_, 0);
v_isSharedCheck_2071_ = !lean_is_exclusive(v___x_2060_);
if (v_isSharedCheck_2071_ == 0)
{
v___x_2063_ = v___x_2060_;
v_isShared_2064_ = v_isSharedCheck_2071_;
goto v_resetjp_2062_;
}
else
{
lean_inc(v_a_2061_);
lean_dec(v___x_2060_);
v___x_2063_ = lean_box(0);
v_isShared_2064_ = v_isSharedCheck_2071_;
goto v_resetjp_2062_;
}
v_resetjp_2062_:
{
lean_object* v___x_2065_; lean_object* v___x_2066_; lean_object* v___x_2067_; lean_object* v___x_2069_; 
v___x_2065_ = lean_io_get_num_heartbeats();
v___x_2066_ = lean_nat_sub(v___x_2065_, v___x_2057_);
lean_dec(v___x_2057_);
lean_dec(v___x_2065_);
v___x_2067_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2067_, 0, v_a_2061_);
lean_ctor_set(v___x_2067_, 1, v___x_2066_);
if (v_isShared_2064_ == 0)
{
lean_ctor_set(v___x_2063_, 0, v___x_2067_);
v___x_2069_ = v___x_2063_;
goto v_reusejp_2068_;
}
else
{
lean_object* v_reuseFailAlloc_2070_; 
v_reuseFailAlloc_2070_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2070_, 0, v___x_2067_);
v___x_2069_ = v_reuseFailAlloc_2070_;
goto v_reusejp_2068_;
}
v_reusejp_2068_:
{
return v___x_2069_;
}
}
}
else
{
lean_object* v_a_2072_; lean_object* v___x_2074_; uint8_t v_isShared_2075_; uint8_t v_isSharedCheck_2079_; 
lean_dec(v___x_2057_);
v_a_2072_ = lean_ctor_get(v___x_2060_, 0);
v_isSharedCheck_2079_ = !lean_is_exclusive(v___x_2060_);
if (v_isSharedCheck_2079_ == 0)
{
v___x_2074_ = v___x_2060_;
v_isShared_2075_ = v_isSharedCheck_2079_;
goto v_resetjp_2073_;
}
else
{
lean_inc(v_a_2072_);
lean_dec(v___x_2060_);
v___x_2074_ = lean_box(0);
v_isShared_2075_ = v_isSharedCheck_2079_;
goto v_resetjp_2073_;
}
v_resetjp_2073_:
{
lean_object* v___x_2077_; 
if (v_isShared_2075_ == 0)
{
v___x_2077_ = v___x_2074_;
goto v_reusejp_2076_;
}
else
{
lean_object* v_reuseFailAlloc_2078_; 
v_reuseFailAlloc_2078_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2078_, 0, v_a_2072_);
v___x_2077_ = v_reuseFailAlloc_2078_;
goto v_reusejp_2076_;
}
v_reusejp_2076_:
{
return v___x_2077_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores___boxed(lean_object* v_register_2080_, lean_object* v_inputs_2081_, lean_object* v_a_2082_){
_start:
{
lean_object* v_res_2083_; 
v_res_2083_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores(v_register_2080_, v_inputs_2081_);
lean_dec_ref(v_inputs_2081_);
lean_dec(v_register_2080_);
return v_res_2083_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(lean_object* v_fst_2090_, lean_object* v_fst_2091_, lean_object* v_range_2092_, lean_object* v_b_2093_, lean_object* v_i_2094_){
_start:
{
lean_object* v_stop_2096_; lean_object* v_step_2097_; uint8_t v___x_2098_; 
v_stop_2096_ = lean_ctor_get(v_range_2092_, 1);
v_step_2097_ = lean_ctor_get(v_range_2092_, 2);
v___x_2098_ = lean_nat_dec_lt(v_i_2094_, v_stop_2096_);
if (v___x_2098_ == 0)
{
lean_object* v___x_2099_; 
lean_dec(v_i_2094_);
v___x_2099_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2099_, 0, v_b_2093_);
return v___x_2099_;
}
else
{
lean_object* v___x_2100_; uint8_t v___x_2101_; 
v___x_2100_ = lean_array_get_size(v_fst_2090_);
v___x_2101_ = lean_nat_dec_lt(v_i_2094_, v___x_2100_);
if (v___x_2101_ == 0)
{
lean_object* v___x_2102_; lean_object* v___x_2103_; 
lean_dec(v_i_2094_);
lean_dec_ref(v_b_2093_);
v___x_2102_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__1));
v___x_2103_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2103_, 0, v___x_2102_);
return v___x_2103_;
}
else
{
lean_object* v_snd_2104_; lean_object* v_fst_2105_; lean_object* v___x_2107_; uint8_t v_isShared_2108_; uint8_t v_isSharedCheck_2150_; 
v_snd_2104_ = lean_ctor_get(v_b_2093_, 1);
v_fst_2105_ = lean_ctor_get(v_b_2093_, 0);
v_isSharedCheck_2150_ = !lean_is_exclusive(v_b_2093_);
if (v_isSharedCheck_2150_ == 0)
{
v___x_2107_ = v_b_2093_;
v_isShared_2108_ = v_isSharedCheck_2150_;
goto v_resetjp_2106_;
}
else
{
lean_inc(v_snd_2104_);
lean_inc(v_fst_2105_);
lean_dec(v_b_2093_);
v___x_2107_ = lean_box(0);
v_isShared_2108_ = v_isSharedCheck_2150_;
goto v_resetjp_2106_;
}
v_resetjp_2106_:
{
lean_object* v_fst_2109_; lean_object* v_snd_2110_; lean_object* v___x_2112_; uint8_t v_isShared_2113_; uint8_t v_isSharedCheck_2149_; 
v_fst_2109_ = lean_ctor_get(v_snd_2104_, 0);
v_snd_2110_ = lean_ctor_get(v_snd_2104_, 1);
v_isSharedCheck_2149_ = !lean_is_exclusive(v_snd_2104_);
if (v_isSharedCheck_2149_ == 0)
{
v___x_2112_ = v_snd_2104_;
v_isShared_2113_ = v_isSharedCheck_2149_;
goto v_resetjp_2111_;
}
else
{
lean_inc(v_snd_2110_);
lean_inc(v_fst_2109_);
lean_dec(v_snd_2104_);
v___x_2112_ = lean_box(0);
v_isShared_2113_ = v_isSharedCheck_2149_;
goto v_resetjp_2111_;
}
v_resetjp_2111_:
{
lean_object* v___x_2114_; lean_object* v_df_2115_; lean_object* v_word_2116_; lean_object* v___x_2117_; lean_object* v___x_2118_; lean_object* v___x_2119_; lean_object* v___x_2120_; lean_object* v___x_2121_; lean_object* v___x_2122_; lean_object* v___x_2123_; lean_object* v___y_2125_; uint8_t v___x_2146_; 
v___x_2114_ = lean_array_fget_borrowed(v_fst_2090_, v_i_2094_);
v_df_2115_ = lean_ctor_get(v___x_2114_, 0);
v_word_2116_ = lean_ctor_get(v___x_2114_, 1);
lean_inc(v_df_2115_);
v___x_2117_ = l_Nat_reprFast(v_df_2115_);
v___x_2118_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__2));
v___x_2119_ = lean_string_append(v___x_2117_, v___x_2118_);
lean_inc(v_word_2116_);
v___x_2120_ = l_Nat_reprFast(v_word_2116_);
v___x_2121_ = lean_string_append(v___x_2119_, v___x_2120_);
lean_dec_ref(v___x_2120_);
v___x_2122_ = lean_string_append(v___x_2121_, v___x_2118_);
v___x_2123_ = lean_array_fget_borrowed(v_fst_2091_, v_i_2094_);
v___x_2146_ = lean_unbox(v___x_2123_);
if (v___x_2146_ == 0)
{
lean_object* v___x_2147_; 
v___x_2147_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__3));
v___y_2125_ = v___x_2147_;
goto v___jp_2124_;
}
else
{
lean_object* v___x_2148_; 
v___x_2148_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__4));
v___y_2125_ = v___x_2148_;
goto v___jp_2124_;
}
v___jp_2124_:
{
lean_object* v___x_2126_; lean_object* v___x_2127_; lean_object* v___x_2128_; lean_object* v___x_2129_; lean_object* v___x_2130_; uint8_t v___x_2131_; lean_object* v___x_2132_; lean_object* v___x_2133_; lean_object* v___x_2134_; uint8_t v___x_2135_; lean_object* v___x_2136_; lean_object* v___x_2137_; lean_object* v___x_2139_; 
v___x_2126_ = lean_string_append(v___x_2122_, v___y_2125_);
v___x_2127_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__0));
v___x_2128_ = lean_string_append(v___x_2126_, v___x_2127_);
v___x_2129_ = lean_string_to_utf8(v___x_2128_);
lean_dec_ref(v___x_2128_);
v___x_2130_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(v_fst_2105_, v___x_2129_);
v___x_2131_ = lean_unbox(v___x_2123_);
v___x_2132_ = l_Bool_toNat(v___x_2131_);
v___x_2133_ = lean_nat_add(v_fst_2109_, v___x_2132_);
lean_dec(v___x_2132_);
lean_dec(v_fst_2109_);
v___x_2134_ = lean_unsigned_to_nat(20u);
v___x_2135_ = lean_nat_dec_eq(v_df_2115_, v___x_2134_);
v___x_2136_ = l_Bool_toNat(v___x_2135_);
v___x_2137_ = lean_nat_add(v_snd_2110_, v___x_2136_);
lean_dec(v___x_2136_);
lean_dec(v_snd_2110_);
if (v_isShared_2113_ == 0)
{
lean_ctor_set(v___x_2112_, 1, v___x_2137_);
lean_ctor_set(v___x_2112_, 0, v___x_2133_);
v___x_2139_ = v___x_2112_;
goto v_reusejp_2138_;
}
else
{
lean_object* v_reuseFailAlloc_2145_; 
v_reuseFailAlloc_2145_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2145_, 0, v___x_2133_);
lean_ctor_set(v_reuseFailAlloc_2145_, 1, v___x_2137_);
v___x_2139_ = v_reuseFailAlloc_2145_;
goto v_reusejp_2138_;
}
v_reusejp_2138_:
{
lean_object* v___x_2141_; 
if (v_isShared_2108_ == 0)
{
lean_ctor_set(v___x_2107_, 1, v___x_2139_);
lean_ctor_set(v___x_2107_, 0, v___x_2130_);
v___x_2141_ = v___x_2107_;
goto v_reusejp_2140_;
}
else
{
lean_object* v_reuseFailAlloc_2144_; 
v_reuseFailAlloc_2144_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2144_, 0, v___x_2130_);
lean_ctor_set(v_reuseFailAlloc_2144_, 1, v___x_2139_);
v___x_2141_ = v_reuseFailAlloc_2144_;
goto v_reusejp_2140_;
}
v_reusejp_2140_:
{
lean_object* v___x_2142_; 
v___x_2142_ = lean_nat_add(v_i_2094_, v_step_2097_);
lean_dec(v_i_2094_);
v_b_2093_ = v___x_2141_;
v_i_2094_ = v___x_2142_;
goto _start;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___boxed(lean_object* v_fst_2151_, lean_object* v_fst_2152_, lean_object* v_range_2153_, lean_object* v_b_2154_, lean_object* v_i_2155_, lean_object* v___y_2156_){
_start:
{
lean_object* v_res_2157_; 
v_res_2157_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(v_fst_2151_, v_fst_2152_, v_range_2153_, v_b_2154_, v_i_2155_);
lean_dec_ref(v_range_2153_);
lean_dec_ref(v_fst_2152_);
lean_dec_ref(v_fst_2151_);
return v_res_2157_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode(lean_object* v_mode_2179_, lean_object* v_register_2180_, lean_object* v_inputs_2181_, uint8_t v_wait_2182_){
_start:
{
lean_object* v___x_2184_; 
v___x_2184_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores(v_inputs_2181_, v_register_2180_);
if (lean_obj_tag(v___x_2184_) == 0)
{
lean_object* v_a_2185_; lean_object* v_fst_2186_; lean_object* v_snd_2187_; lean_object* v___x_2189_; uint8_t v_isShared_2190_; uint8_t v_isSharedCheck_2345_; 
v_a_2185_ = lean_ctor_get(v___x_2184_, 0);
lean_inc(v_a_2185_);
lean_dec_ref_known(v___x_2184_, 1);
v_fst_2186_ = lean_ctor_get(v_a_2185_, 0);
v_snd_2187_ = lean_ctor_get(v_a_2185_, 1);
v_isSharedCheck_2345_ = !lean_is_exclusive(v_a_2185_);
if (v_isSharedCheck_2345_ == 0)
{
v___x_2189_ = v_a_2185_;
v_isShared_2190_ = v_isSharedCheck_2345_;
goto v_resetjp_2188_;
}
else
{
lean_inc(v_snd_2187_);
lean_inc(v_fst_2186_);
lean_dec(v_a_2185_);
v___x_2189_ = lean_box(0);
v_isShared_2190_ = v_isSharedCheck_2345_;
goto v_resetjp_2188_;
}
v_resetjp_2188_:
{
lean_object* v___x_2191_; lean_object* v___x_2192_; lean_object* v___x_2193_; lean_object* v___x_2195_; 
v___x_2191_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__3));
v___x_2192_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__4));
v___x_2193_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_2193_, 0, v_mode_2179_);
if (v_isShared_2190_ == 0)
{
lean_ctor_set(v___x_2189_, 1, v___x_2193_);
lean_ctor_set(v___x_2189_, 0, v___x_2192_);
v___x_2195_ = v___x_2189_;
goto v_reusejp_2194_;
}
else
{
lean_object* v_reuseFailAlloc_2344_; 
v_reuseFailAlloc_2344_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2344_, 0, v___x_2192_);
lean_ctor_set(v_reuseFailAlloc_2344_, 1, v___x_2193_);
v___x_2195_ = v_reuseFailAlloc_2344_;
goto v_reusejp_2194_;
}
v_reusejp_2194_:
{
lean_object* v___x_2196_; lean_object* v___x_2197_; lean_object* v___x_2198_; lean_object* v___x_2199_; lean_object* v___x_2200_; lean_object* v___x_2201_; lean_object* v___x_2202_; lean_object* v___x_2203_; lean_object* v___x_2204_; lean_object* v___x_2205_; lean_object* v___x_2206_; lean_object* v___x_2207_; lean_object* v___x_2208_; lean_object* v___x_2209_; lean_object* v___x_2210_; lean_object* v___x_2211_; lean_object* v___x_2212_; lean_object* v___x_2213_; 
v___x_2196_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__5));
v___x_2197_ = lean_array_get_size(v_fst_2186_);
v___x_2198_ = l_Lean_JsonNumber_fromNat(v___x_2197_);
v___x_2199_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2199_, 0, v___x_2198_);
v___x_2200_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2200_, 0, v___x_2196_);
lean_ctor_set(v___x_2200_, 1, v___x_2199_);
v___x_2201_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__0));
v___x_2202_ = l_Lean_JsonNumber_fromNat(v_snd_2187_);
v___x_2203_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2203_, 0, v___x_2202_);
v___x_2204_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2204_, 0, v___x_2201_);
lean_ctor_set(v___x_2204_, 1, v___x_2203_);
v___x_2205_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__3));
v___x_2206_ = lean_box(0);
v___x_2207_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__4));
v___x_2208_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2208_, 0, v___x_2204_);
lean_ctor_set(v___x_2208_, 1, v___x_2207_);
v___x_2209_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2209_, 0, v___x_2200_);
lean_ctor_set(v___x_2209_, 1, v___x_2208_);
lean_inc_ref(v___x_2195_);
v___x_2210_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2210_, 0, v___x_2195_);
lean_ctor_set(v___x_2210_, 1, v___x_2209_);
v___x_2211_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2211_, 0, v___x_2191_);
lean_ctor_set(v___x_2211_, 1, v___x_2210_);
v___x_2212_ = l_Lean_Json_mkObj(v___x_2211_);
lean_dec_ref_known(v___x_2211_, 2);
v___x_2213_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_2212_);
if (lean_obj_tag(v___x_2213_) == 0)
{
lean_object* v___x_2215_; uint8_t v_isShared_2216_; uint8_t v_isSharedCheck_2342_; 
v_isSharedCheck_2342_ = !lean_is_exclusive(v___x_2213_);
if (v_isSharedCheck_2342_ == 0)
{
lean_object* v_unused_2343_; 
v_unused_2343_ = lean_ctor_get(v___x_2213_, 0);
lean_dec(v_unused_2343_);
v___x_2215_ = v___x_2213_;
v_isShared_2216_ = v_isSharedCheck_2342_;
goto v_resetjp_2214_;
}
else
{
lean_dec(v___x_2213_);
v___x_2215_ = lean_box(0);
v_isShared_2216_ = v_isSharedCheck_2342_;
goto v_resetjp_2214_;
}
v_resetjp_2214_:
{
lean_object* v___x_2217_; lean_object* v___x_2218_; 
v___x_2217_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__11));
v___x_2218_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_wait_2182_, v___x_2217_);
if (lean_obj_tag(v___x_2218_) == 0)
{
lean_object* v___x_2220_; uint8_t v_isShared_2221_; uint8_t v_isSharedCheck_2340_; 
v_isSharedCheck_2340_ = !lean_is_exclusive(v___x_2218_);
if (v_isSharedCheck_2340_ == 0)
{
lean_object* v_unused_2341_; 
v_unused_2341_ = lean_ctor_get(v___x_2218_, 0);
lean_dec(v_unused_2341_);
v___x_2220_ = v___x_2218_;
v_isShared_2221_ = v_isSharedCheck_2340_;
goto v_resetjp_2219_;
}
else
{
lean_dec(v___x_2218_);
v___x_2220_ = lean_box(0);
v_isShared_2221_ = v_isSharedCheck_2340_;
goto v_resetjp_2219_;
}
v_resetjp_2219_:
{
lean_object* v___x_2222_; 
v___x_2222_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores(v_register_2180_, v_fst_2186_);
if (lean_obj_tag(v___x_2222_) == 0)
{
lean_object* v_a_2223_; lean_object* v_fst_2224_; lean_object* v_snd_2225_; lean_object* v___x_2227_; uint8_t v_isShared_2228_; uint8_t v_isSharedCheck_2331_; 
v_a_2223_ = lean_ctor_get(v___x_2222_, 0);
lean_inc(v_a_2223_);
lean_dec_ref_known(v___x_2222_, 1);
v_fst_2224_ = lean_ctor_get(v_a_2223_, 0);
v_snd_2225_ = lean_ctor_get(v_a_2223_, 1);
v_isSharedCheck_2331_ = !lean_is_exclusive(v_a_2223_);
if (v_isSharedCheck_2331_ == 0)
{
v___x_2227_ = v_a_2223_;
v_isShared_2228_ = v_isSharedCheck_2331_;
goto v_resetjp_2226_;
}
else
{
lean_inc(v_snd_2225_);
lean_inc(v_fst_2224_);
lean_dec(v_a_2223_);
v___x_2227_ = lean_box(0);
v_isShared_2228_ = v_isSharedCheck_2331_;
goto v_resetjp_2226_;
}
v_resetjp_2226_:
{
lean_object* v___x_2229_; lean_object* v___x_2230_; lean_object* v___x_2231_; lean_object* v___x_2232_; lean_object* v___x_2234_; 
v___x_2229_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__14));
v___x_2230_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__15));
v___x_2231_ = lean_array_get_size(v_fst_2224_);
v___x_2232_ = l_Lean_JsonNumber_fromNat(v___x_2231_);
if (v_isShared_2221_ == 0)
{
lean_ctor_set_tag(v___x_2220_, 2);
lean_ctor_set(v___x_2220_, 0, v___x_2232_);
v___x_2234_ = v___x_2220_;
goto v_reusejp_2233_;
}
else
{
lean_object* v_reuseFailAlloc_2330_; 
v_reuseFailAlloc_2330_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2330_, 0, v___x_2232_);
v___x_2234_ = v_reuseFailAlloc_2330_;
goto v_reusejp_2233_;
}
v_reusejp_2233_:
{
lean_object* v___x_2236_; 
if (v_isShared_2228_ == 0)
{
lean_ctor_set(v___x_2227_, 1, v___x_2234_);
lean_ctor_set(v___x_2227_, 0, v___x_2230_);
v___x_2236_ = v___x_2227_;
goto v_reusejp_2235_;
}
else
{
lean_object* v_reuseFailAlloc_2329_; 
v_reuseFailAlloc_2329_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2329_, 0, v___x_2230_);
lean_ctor_set(v_reuseFailAlloc_2329_, 1, v___x_2234_);
v___x_2236_ = v_reuseFailAlloc_2329_;
goto v_reusejp_2235_;
}
v_reusejp_2235_:
{
lean_object* v___x_2237_; lean_object* v___x_2238_; lean_object* v___x_2240_; 
v___x_2237_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__16));
v___x_2238_ = l_Lean_JsonNumber_fromNat(v_snd_2225_);
if (v_isShared_2216_ == 0)
{
lean_ctor_set_tag(v___x_2215_, 2);
lean_ctor_set(v___x_2215_, 0, v___x_2238_);
v___x_2240_ = v___x_2215_;
goto v_reusejp_2239_;
}
else
{
lean_object* v_reuseFailAlloc_2328_; 
v_reuseFailAlloc_2328_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2328_, 0, v___x_2238_);
v___x_2240_ = v_reuseFailAlloc_2328_;
goto v_reusejp_2239_;
}
v_reusejp_2239_:
{
lean_object* v___x_2241_; lean_object* v___x_2242_; lean_object* v___x_2243_; lean_object* v___x_2244_; lean_object* v___x_2245_; lean_object* v___x_2246_; lean_object* v___x_2247_; 
v___x_2241_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2241_, 0, v___x_2237_);
lean_ctor_set(v___x_2241_, 1, v___x_2240_);
v___x_2242_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2242_, 0, v___x_2241_);
lean_ctor_set(v___x_2242_, 1, v___x_2206_);
lean_inc_ref(v___x_2242_);
v___x_2243_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2243_, 0, v___x_2236_);
lean_ctor_set(v___x_2243_, 1, v___x_2242_);
lean_inc_ref(v___x_2195_);
v___x_2244_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2244_, 0, v___x_2195_);
lean_ctor_set(v___x_2244_, 1, v___x_2243_);
v___x_2245_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2245_, 0, v___x_2229_);
lean_ctor_set(v___x_2245_, 1, v___x_2244_);
v___x_2246_ = l_Lean_Json_mkObj(v___x_2245_);
lean_dec_ref_known(v___x_2245_, 2);
v___x_2247_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_2246_);
if (lean_obj_tag(v___x_2247_) == 0)
{
lean_object* v___x_2249_; uint8_t v_isShared_2250_; uint8_t v_isSharedCheck_2326_; 
v_isSharedCheck_2326_ = !lean_is_exclusive(v___x_2247_);
if (v_isSharedCheck_2326_ == 0)
{
lean_object* v_unused_2327_; 
v_unused_2327_ = lean_ctor_get(v___x_2247_, 0);
lean_dec(v_unused_2327_);
v___x_2249_ = v___x_2247_;
v_isShared_2250_ = v_isSharedCheck_2326_;
goto v_resetjp_2248_;
}
else
{
lean_dec(v___x_2247_);
v___x_2249_ = lean_box(0);
v_isShared_2250_ = v_isSharedCheck_2326_;
goto v_resetjp_2248_;
}
v_resetjp_2248_:
{
lean_object* v___x_2251_; lean_object* v___x_2252_; 
v___x_2251_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__17));
v___x_2252_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_wait_2182_, v___x_2251_);
if (lean_obj_tag(v___x_2252_) == 0)
{
lean_object* v___x_2254_; uint8_t v_isShared_2255_; uint8_t v_isSharedCheck_2324_; 
v_isSharedCheck_2324_ = !lean_is_exclusive(v___x_2252_);
if (v_isSharedCheck_2324_ == 0)
{
lean_object* v_unused_2325_; 
v_unused_2325_ = lean_ctor_get(v___x_2252_, 0);
lean_dec(v_unused_2325_);
v___x_2254_ = v___x_2252_;
v_isShared_2255_ = v_isSharedCheck_2324_;
goto v_resetjp_2253_;
}
else
{
lean_dec(v___x_2252_);
v___x_2254_ = lean_box(0);
v_isShared_2255_ = v_isSharedCheck_2324_;
goto v_resetjp_2253_;
}
v_resetjp_2253_:
{
uint8_t v___x_2256_; 
v___x_2256_ = lean_nat_dec_eq(v___x_2231_, v___x_2197_);
if (v___x_2256_ == 0)
{
lean_object* v___x_2257_; lean_object* v___x_2259_; 
lean_del_object(v___x_2249_);
lean_dec_ref_known(v___x_2242_, 2);
lean_dec(v_fst_2224_);
lean_dec_ref(v___x_2195_);
lean_dec(v_fst_2186_);
lean_dec(v_register_2180_);
v___x_2257_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__6));
if (v_isShared_2255_ == 0)
{
lean_ctor_set_tag(v___x_2254_, 1);
lean_ctor_set(v___x_2254_, 0, v___x_2257_);
v___x_2259_ = v___x_2254_;
goto v_reusejp_2258_;
}
else
{
lean_object* v_reuseFailAlloc_2260_; 
v_reuseFailAlloc_2260_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2260_, 0, v___x_2257_);
v___x_2259_ = v_reuseFailAlloc_2260_;
goto v_reusejp_2258_;
}
v_reusejp_2258_:
{
return v___x_2259_;
}
}
else
{
lean_object* v___x_2261_; lean_object* v___x_2262_; lean_object* v___x_2263_; lean_object* v___x_2264_; lean_object* v___x_2265_; 
lean_del_object(v___x_2254_);
v___x_2261_ = lean_unsigned_to_nat(0u);
v___x_2262_ = lean_unsigned_to_nat(1u);
v___x_2263_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_2263_, 0, v___x_2261_);
lean_ctor_set(v___x_2263_, 1, v___x_2231_);
lean_ctor_set(v___x_2263_, 2, v___x_2262_);
v___x_2264_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__8));
v___x_2265_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(v_fst_2186_, v_fst_2224_, v___x_2263_, v___x_2264_, v___x_2261_);
lean_dec_ref_known(v___x_2263_, 3);
lean_dec(v_fst_2224_);
lean_dec(v_fst_2186_);
if (lean_obj_tag(v___x_2265_) == 0)
{
lean_object* v_a_2266_; lean_object* v_snd_2267_; lean_object* v_fst_2268_; lean_object* v___x_2270_; uint8_t v_isShared_2271_; uint8_t v_isSharedCheck_2315_; 
v_a_2266_ = lean_ctor_get(v___x_2265_, 0);
lean_inc(v_a_2266_);
lean_dec_ref_known(v___x_2265_, 1);
v_snd_2267_ = lean_ctor_get(v_a_2266_, 1);
v_fst_2268_ = lean_ctor_get(v_a_2266_, 0);
v_isSharedCheck_2315_ = !lean_is_exclusive(v_a_2266_);
if (v_isSharedCheck_2315_ == 0)
{
v___x_2270_ = v_a_2266_;
v_isShared_2271_ = v_isSharedCheck_2315_;
goto v_resetjp_2269_;
}
else
{
lean_inc(v_snd_2267_);
lean_inc(v_fst_2268_);
lean_dec(v_a_2266_);
v___x_2270_ = lean_box(0);
v_isShared_2271_ = v_isSharedCheck_2315_;
goto v_resetjp_2269_;
}
v_resetjp_2269_:
{
lean_object* v_fst_2272_; lean_object* v_snd_2273_; lean_object* v___x_2275_; uint8_t v_isShared_2276_; uint8_t v_isSharedCheck_2314_; 
v_fst_2272_ = lean_ctor_get(v_snd_2267_, 0);
v_snd_2273_ = lean_ctor_get(v_snd_2267_, 1);
v_isSharedCheck_2314_ = !lean_is_exclusive(v_snd_2267_);
if (v_isSharedCheck_2314_ == 0)
{
v___x_2275_ = v_snd_2267_;
v_isShared_2276_ = v_isSharedCheck_2314_;
goto v_resetjp_2274_;
}
else
{
lean_inc(v_snd_2273_);
lean_inc(v_fst_2272_);
lean_dec(v_snd_2267_);
v___x_2275_ = lean_box(0);
v_isShared_2276_ = v_isSharedCheck_2314_;
goto v_resetjp_2274_;
}
v_resetjp_2274_:
{
lean_object* v___x_2277_; lean_object* v___x_2278_; lean_object* v___x_2279_; lean_object* v___x_2281_; 
v___x_2277_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__20));
v___x_2278_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__0));
v___x_2279_ = l_Lean_JsonNumber_fromNat(v_register_2180_);
if (v_isShared_2250_ == 0)
{
lean_ctor_set_tag(v___x_2249_, 2);
lean_ctor_set(v___x_2249_, 0, v___x_2279_);
v___x_2281_ = v___x_2249_;
goto v_reusejp_2280_;
}
else
{
lean_object* v_reuseFailAlloc_2313_; 
v_reuseFailAlloc_2313_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2313_, 0, v___x_2279_);
v___x_2281_ = v_reuseFailAlloc_2313_;
goto v_reusejp_2280_;
}
v_reusejp_2280_:
{
lean_object* v___x_2283_; 
if (v_isShared_2276_ == 0)
{
lean_ctor_set(v___x_2275_, 1, v___x_2281_);
lean_ctor_set(v___x_2275_, 0, v___x_2278_);
v___x_2283_ = v___x_2275_;
goto v_reusejp_2282_;
}
else
{
lean_object* v_reuseFailAlloc_2312_; 
v_reuseFailAlloc_2312_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2312_, 0, v___x_2278_);
lean_ctor_set(v_reuseFailAlloc_2312_, 1, v___x_2281_);
v___x_2283_ = v_reuseFailAlloc_2312_;
goto v_reusejp_2282_;
}
v_reusejp_2282_:
{
lean_object* v___x_2284_; lean_object* v___x_2285_; lean_object* v___x_2287_; 
v___x_2284_ = ((lean_object*)(l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0___closed__0));
v___x_2285_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(v_fst_2268_);
if (v_isShared_2271_ == 0)
{
lean_ctor_set(v___x_2270_, 1, v___x_2285_);
lean_ctor_set(v___x_2270_, 0, v___x_2284_);
v___x_2287_ = v___x_2270_;
goto v_reusejp_2286_;
}
else
{
lean_object* v_reuseFailAlloc_2311_; 
v_reuseFailAlloc_2311_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2311_, 0, v___x_2284_);
lean_ctor_set(v_reuseFailAlloc_2311_, 1, v___x_2285_);
v___x_2287_ = v_reuseFailAlloc_2311_;
goto v_reusejp_2286_;
}
v_reusejp_2286_:
{
lean_object* v___x_2288_; lean_object* v___x_2289_; lean_object* v___x_2290_; lean_object* v___x_2291_; lean_object* v___x_2292_; lean_object* v___x_2293_; lean_object* v___x_2294_; lean_object* v___x_2295_; lean_object* v___x_2296_; lean_object* v___x_2297_; lean_object* v___x_2298_; lean_object* v___x_2299_; lean_object* v___x_2300_; lean_object* v___x_2301_; lean_object* v___x_2302_; lean_object* v___x_2303_; lean_object* v___x_2304_; lean_object* v___x_2305_; lean_object* v___x_2306_; lean_object* v___x_2307_; lean_object* v___x_2308_; lean_object* v___x_2309_; lean_object* v___x_2310_; 
v___x_2288_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__9));
v___x_2289_ = l_Lean_JsonNumber_fromNat(v_fst_2272_);
v___x_2290_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2290_, 0, v___x_2289_);
v___x_2291_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2291_, 0, v___x_2288_);
lean_ctor_set(v___x_2291_, 1, v___x_2290_);
v___x_2292_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__10));
lean_inc(v_snd_2273_);
v___x_2293_ = l_Lean_JsonNumber_fromNat(v_snd_2273_);
v___x_2294_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2294_, 0, v___x_2293_);
v___x_2295_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2295_, 0, v___x_2292_);
lean_ctor_set(v___x_2295_, 1, v___x_2294_);
v___x_2296_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__11));
v___x_2297_ = lean_nat_sub(v___x_2197_, v_snd_2273_);
lean_dec(v_snd_2273_);
v___x_2298_ = l_Lean_JsonNumber_fromNat(v___x_2297_);
v___x_2299_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2299_, 0, v___x_2298_);
v___x_2300_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2300_, 0, v___x_2296_);
lean_ctor_set(v___x_2300_, 1, v___x_2299_);
v___x_2301_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2301_, 0, v___x_2300_);
lean_ctor_set(v___x_2301_, 1, v___x_2242_);
v___x_2302_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2302_, 0, v___x_2295_);
lean_ctor_set(v___x_2302_, 1, v___x_2301_);
v___x_2303_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2303_, 0, v___x_2291_);
lean_ctor_set(v___x_2303_, 1, v___x_2302_);
v___x_2304_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2304_, 0, v___x_2287_);
lean_ctor_set(v___x_2304_, 1, v___x_2303_);
v___x_2305_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2305_, 0, v___x_2205_);
lean_ctor_set(v___x_2305_, 1, v___x_2304_);
v___x_2306_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2306_, 0, v___x_2283_);
lean_ctor_set(v___x_2306_, 1, v___x_2305_);
v___x_2307_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2307_, 0, v___x_2195_);
lean_ctor_set(v___x_2307_, 1, v___x_2306_);
v___x_2308_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2308_, 0, v___x_2277_);
lean_ctor_set(v___x_2308_, 1, v___x_2307_);
v___x_2309_ = l_Lean_Json_mkObj(v___x_2308_);
lean_dec_ref_known(v___x_2308_, 2);
v___x_2310_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_2309_);
return v___x_2310_;
}
}
}
}
}
}
else
{
lean_object* v_a_2316_; lean_object* v___x_2318_; uint8_t v_isShared_2319_; uint8_t v_isSharedCheck_2323_; 
lean_del_object(v___x_2249_);
lean_dec_ref_known(v___x_2242_, 2);
lean_dec_ref(v___x_2195_);
lean_dec(v_register_2180_);
v_a_2316_ = lean_ctor_get(v___x_2265_, 0);
v_isSharedCheck_2323_ = !lean_is_exclusive(v___x_2265_);
if (v_isSharedCheck_2323_ == 0)
{
v___x_2318_ = v___x_2265_;
v_isShared_2319_ = v_isSharedCheck_2323_;
goto v_resetjp_2317_;
}
else
{
lean_inc(v_a_2316_);
lean_dec(v___x_2265_);
v___x_2318_ = lean_box(0);
v_isShared_2319_ = v_isSharedCheck_2323_;
goto v_resetjp_2317_;
}
v_resetjp_2317_:
{
lean_object* v___x_2321_; 
if (v_isShared_2319_ == 0)
{
v___x_2321_ = v___x_2318_;
goto v_reusejp_2320_;
}
else
{
lean_object* v_reuseFailAlloc_2322_; 
v_reuseFailAlloc_2322_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2322_, 0, v_a_2316_);
v___x_2321_ = v_reuseFailAlloc_2322_;
goto v_reusejp_2320_;
}
v_reusejp_2320_:
{
return v___x_2321_;
}
}
}
}
}
}
else
{
lean_del_object(v___x_2249_);
lean_dec_ref_known(v___x_2242_, 2);
lean_dec(v_fst_2224_);
lean_dec_ref(v___x_2195_);
lean_dec(v_fst_2186_);
lean_dec(v_register_2180_);
return v___x_2252_;
}
}
}
else
{
lean_dec_ref_known(v___x_2242_, 2);
lean_dec(v_fst_2224_);
lean_dec_ref(v___x_2195_);
lean_dec(v_fst_2186_);
lean_dec(v_register_2180_);
return v___x_2247_;
}
}
}
}
}
}
else
{
lean_object* v_a_2332_; lean_object* v___x_2334_; uint8_t v_isShared_2335_; uint8_t v_isSharedCheck_2339_; 
lean_del_object(v___x_2220_);
lean_del_object(v___x_2215_);
lean_dec_ref(v___x_2195_);
lean_dec(v_fst_2186_);
lean_dec(v_register_2180_);
v_a_2332_ = lean_ctor_get(v___x_2222_, 0);
v_isSharedCheck_2339_ = !lean_is_exclusive(v___x_2222_);
if (v_isSharedCheck_2339_ == 0)
{
v___x_2334_ = v___x_2222_;
v_isShared_2335_ = v_isSharedCheck_2339_;
goto v_resetjp_2333_;
}
else
{
lean_inc(v_a_2332_);
lean_dec(v___x_2222_);
v___x_2334_ = lean_box(0);
v_isShared_2335_ = v_isSharedCheck_2339_;
goto v_resetjp_2333_;
}
v_resetjp_2333_:
{
lean_object* v___x_2337_; 
if (v_isShared_2335_ == 0)
{
v___x_2337_ = v___x_2334_;
goto v_reusejp_2336_;
}
else
{
lean_object* v_reuseFailAlloc_2338_; 
v_reuseFailAlloc_2338_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2338_, 0, v_a_2332_);
v___x_2337_ = v_reuseFailAlloc_2338_;
goto v_reusejp_2336_;
}
v_reusejp_2336_:
{
return v___x_2337_;
}
}
}
}
}
else
{
lean_del_object(v___x_2215_);
lean_dec_ref(v___x_2195_);
lean_dec(v_fst_2186_);
lean_dec(v_register_2180_);
return v___x_2218_;
}
}
}
else
{
lean_dec_ref(v___x_2195_);
lean_dec(v_fst_2186_);
lean_dec(v_register_2180_);
return v___x_2213_;
}
}
}
}
else
{
lean_object* v_a_2346_; lean_object* v___x_2348_; uint8_t v_isShared_2349_; uint8_t v_isSharedCheck_2353_; 
lean_dec(v_register_2180_);
lean_dec_ref(v_mode_2179_);
v_a_2346_ = lean_ctor_get(v___x_2184_, 0);
v_isSharedCheck_2353_ = !lean_is_exclusive(v___x_2184_);
if (v_isSharedCheck_2353_ == 0)
{
v___x_2348_ = v___x_2184_;
v_isShared_2349_ = v_isSharedCheck_2353_;
goto v_resetjp_2347_;
}
else
{
lean_inc(v_a_2346_);
lean_dec(v___x_2184_);
v___x_2348_ = lean_box(0);
v_isShared_2349_ = v_isSharedCheck_2353_;
goto v_resetjp_2347_;
}
v_resetjp_2347_:
{
lean_object* v___x_2351_; 
if (v_isShared_2349_ == 0)
{
v___x_2351_ = v___x_2348_;
goto v_reusejp_2350_;
}
else
{
lean_object* v_reuseFailAlloc_2352_; 
v_reuseFailAlloc_2352_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2352_, 0, v_a_2346_);
v___x_2351_ = v_reuseFailAlloc_2352_;
goto v_reusejp_2350_;
}
v_reusejp_2350_:
{
return v___x_2351_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___boxed(lean_object* v_mode_2354_, lean_object* v_register_2355_, lean_object* v_inputs_2356_, lean_object* v_wait_2357_, lean_object* v_a_2358_){
_start:
{
uint8_t v_wait_boxed_2359_; lean_object* v_res_2360_; 
v_wait_boxed_2359_ = lean_unbox(v_wait_2357_);
v_res_2360_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode(v_mode_2354_, v_register_2355_, v_inputs_2356_, v_wait_boxed_2359_);
lean_dec_ref(v_inputs_2356_);
return v_res_2360_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0(lean_object* v_fst_2361_, lean_object* v_fst_2362_, lean_object* v_range_2363_, lean_object* v_b_2364_, lean_object* v_i_2365_, lean_object* v_hs_2366_, lean_object* v_hl_2367_){
_start:
{
lean_object* v___x_2369_; 
v___x_2369_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(v_fst_2361_, v_fst_2362_, v_range_2363_, v_b_2364_, v_i_2365_);
return v___x_2369_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___boxed(lean_object* v_fst_2370_, lean_object* v_fst_2371_, lean_object* v_range_2372_, lean_object* v_b_2373_, lean_object* v_i_2374_, lean_object* v_hs_2375_, lean_object* v_hl_2376_, lean_object* v___y_2377_){
_start:
{
lean_object* v_res_2378_; 
v_res_2378_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0(v_fst_2370_, v_fst_2371_, v_range_2372_, v_b_2373_, v_i_2374_, v_hs_2375_, v_hl_2376_);
lean_dec_ref(v_range_2372_);
lean_dec_ref(v_fst_2371_);
lean_dec_ref(v_fst_2370_);
return v_res_2378_;
}
}
LEAN_EXPORT uint8_t l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(lean_object* v_a_2379_, lean_object* v_x_2380_){
_start:
{
if (lean_obj_tag(v_x_2380_) == 0)
{
uint8_t v___x_2381_; 
v___x_2381_ = 0;
return v___x_2381_;
}
else
{
lean_object* v_head_2382_; lean_object* v_tail_2383_; uint8_t v___x_2384_; 
v_head_2382_ = lean_ctor_get(v_x_2380_, 0);
v_tail_2383_ = lean_ctor_get(v_x_2380_, 1);
v___x_2384_ = lean_string_dec_eq(v_a_2379_, v_head_2382_);
if (v___x_2384_ == 0)
{
v_x_2380_ = v_tail_2383_;
goto _start;
}
else
{
return v___x_2384_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1___boxed(lean_object* v_a_2386_, lean_object* v_x_2387_){
_start:
{
uint8_t v_res_2388_; lean_object* v_r_2389_; 
v_res_2388_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v_a_2386_, v_x_2387_);
lean_dec(v_x_2387_);
lean_dec_ref(v_a_2386_);
v_r_2389_ = lean_box(v_res_2388_);
return v_r_2389_;
}
}
LEAN_EXPORT uint8_t l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0(lean_object* v_x_2392_){
_start:
{
if (lean_obj_tag(v_x_2392_) == 0)
{
uint8_t v___x_2393_; 
v___x_2393_ = 0;
return v___x_2393_;
}
else
{
lean_object* v_head_2394_; lean_object* v_tail_2395_; lean_object* v___x_2396_; uint8_t v___x_2397_; 
v_head_2394_ = lean_ctor_get(v_x_2392_, 0);
v_tail_2395_ = lean_ctor_get(v_x_2392_, 1);
v___x_2396_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__0));
v___x_2397_ = lean_string_dec_eq(v_head_2394_, v___x_2396_);
if (v___x_2397_ == 0)
{
lean_object* v___x_2398_; uint8_t v___x_2399_; 
v___x_2398_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__1));
v___x_2399_ = lean_string_dec_eq(v_head_2394_, v___x_2398_);
if (v___x_2399_ == 0)
{
uint8_t v___x_2400_; 
v___x_2400_ = 1;
return v___x_2400_;
}
else
{
v_x_2392_ = v_tail_2395_;
goto _start;
}
}
else
{
v_x_2392_ = v_tail_2395_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___boxed(lean_object* v_x_2403_){
_start:
{
uint8_t v_res_2404_; lean_object* v_r_2405_; 
v_res_2404_ = l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0(v_x_2403_);
lean_dec(v_x_2403_);
v_r_2405_ = lean_box(v_res_2404_);
return v_r_2405_;
}
}
LEAN_EXPORT lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute(lean_object* v_args_2415_){
_start:
{
if (lean_obj_tag(v_args_2415_) == 1)
{
lean_object* v_tail_2420_; 
v_tail_2420_ = lean_ctor_get(v_args_2415_, 1);
lean_inc(v_tail_2420_);
if (lean_obj_tag(v_tail_2420_) == 1)
{
lean_object* v_head_2421_; lean_object* v_head_2422_; lean_object* v_tail_2423_; uint8_t v___x_2424_; 
v_head_2421_ = lean_ctor_get(v_args_2415_, 0);
lean_inc(v_head_2421_);
lean_dec_ref_known(v_args_2415_, 2);
v_head_2422_ = lean_ctor_get(v_tail_2420_, 0);
lean_inc(v_head_2422_);
v_tail_2423_ = lean_ctor_get(v_tail_2420_, 1);
lean_inc(v_tail_2423_);
lean_dec_ref_known(v_tail_2420_, 2);
v___x_2424_ = l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0(v_tail_2423_);
if (v___x_2424_ == 0)
{
lean_object* v___x_2425_; 
v___x_2425_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs(v_head_2422_);
lean_dec(v_head_2422_);
if (lean_obj_tag(v___x_2425_) == 0)
{
lean_object* v_a_2426_; lean_object* v___x_2428_; uint8_t v_isShared_2429_; uint8_t v_isSharedCheck_2446_; 
v_a_2426_ = lean_ctor_get(v___x_2425_, 0);
v_isSharedCheck_2446_ = !lean_is_exclusive(v___x_2425_);
if (v_isSharedCheck_2446_ == 0)
{
v___x_2428_ = v___x_2425_;
v_isShared_2429_ = v_isSharedCheck_2446_;
goto v_resetjp_2427_;
}
else
{
lean_inc(v_a_2426_);
lean_dec(v___x_2425_);
v___x_2428_ = lean_box(0);
v_isShared_2429_ = v_isSharedCheck_2446_;
goto v_resetjp_2427_;
}
v_resetjp_2427_:
{
lean_object* v___x_2430_; 
v___x_2430_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister(v_head_2421_);
if (lean_obj_tag(v___x_2430_) == 1)
{
lean_object* v_val_2431_; lean_object* v___x_2432_; uint8_t v___x_2433_; 
v_val_2431_ = lean_ctor_get(v___x_2430_, 0);
lean_inc(v_val_2431_);
lean_dec_ref_known(v___x_2430_, 1);
v___x_2432_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__0));
v___x_2433_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v___x_2432_, v_tail_2423_);
if (v___x_2433_ == 0)
{
lean_object* v___x_2434_; uint8_t v___x_2435_; lean_object* v___x_2436_; 
lean_del_object(v___x_2428_);
v___x_2434_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__1));
v___x_2435_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v___x_2434_, v_tail_2423_);
lean_dec(v_tail_2423_);
v___x_2436_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode(v_head_2421_, v_val_2431_, v_a_2426_, v___x_2435_);
lean_dec(v_a_2426_);
return v___x_2436_;
}
else
{
lean_object* v___x_2437_; lean_object* v___x_2439_; 
lean_dec(v_val_2431_);
lean_dec(v_a_2426_);
lean_dec(v_tail_2423_);
lean_dec(v_head_2421_);
v___x_2437_ = ((lean_object*)(l_Lean1090_Diagnostics_DecodeCosts_execute___closed__3));
if (v_isShared_2429_ == 0)
{
lean_ctor_set_tag(v___x_2428_, 1);
lean_ctor_set(v___x_2428_, 0, v___x_2437_);
v___x_2439_ = v___x_2428_;
goto v_reusejp_2438_;
}
else
{
lean_object* v_reuseFailAlloc_2440_; 
v_reuseFailAlloc_2440_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2440_, 0, v___x_2437_);
v___x_2439_ = v_reuseFailAlloc_2440_;
goto v_reusejp_2438_;
}
v_reusejp_2438_:
{
return v___x_2439_;
}
}
}
else
{
lean_object* v___x_2441_; uint8_t v___x_2442_; lean_object* v___x_2443_; uint8_t v___x_2444_; lean_object* v___x_2445_; 
lean_dec(v___x_2430_);
lean_del_object(v___x_2428_);
v___x_2441_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__0));
v___x_2442_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v___x_2441_, v_tail_2423_);
v___x_2443_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__1));
v___x_2444_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v___x_2443_, v_tail_2423_);
lean_dec(v_tail_2423_);
v___x_2445_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode(v_head_2421_, v_a_2426_, v___x_2442_, v___x_2444_);
lean_dec(v_a_2426_);
return v___x_2445_;
}
}
}
else
{
lean_object* v_a_2447_; lean_object* v___x_2449_; uint8_t v_isShared_2450_; uint8_t v_isSharedCheck_2454_; 
lean_dec(v_tail_2423_);
lean_dec(v_head_2421_);
v_a_2447_ = lean_ctor_get(v___x_2425_, 0);
v_isSharedCheck_2454_ = !lean_is_exclusive(v___x_2425_);
if (v_isSharedCheck_2454_ == 0)
{
v___x_2449_ = v___x_2425_;
v_isShared_2450_ = v_isSharedCheck_2454_;
goto v_resetjp_2448_;
}
else
{
lean_inc(v_a_2447_);
lean_dec(v___x_2425_);
v___x_2449_ = lean_box(0);
v_isShared_2450_ = v_isSharedCheck_2454_;
goto v_resetjp_2448_;
}
v_resetjp_2448_:
{
lean_object* v___x_2452_; 
if (v_isShared_2450_ == 0)
{
v___x_2452_ = v___x_2449_;
goto v_reusejp_2451_;
}
else
{
lean_object* v_reuseFailAlloc_2453_; 
v_reuseFailAlloc_2453_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2453_, 0, v_a_2447_);
v___x_2452_ = v_reuseFailAlloc_2453_;
goto v_reusejp_2451_;
}
v_reusejp_2451_:
{
return v___x_2452_;
}
}
}
}
else
{
lean_object* v___x_2455_; lean_object* v___x_2456_; 
lean_dec(v_tail_2423_);
lean_dec(v_head_2422_);
lean_dec(v_head_2421_);
v___x_2455_ = ((lean_object*)(l_Lean1090_Diagnostics_DecodeCosts_execute___closed__5));
v___x_2456_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2456_, 0, v___x_2455_);
return v___x_2456_;
}
}
else
{
lean_dec(v_tail_2420_);
lean_dec_ref_known(v_args_2415_, 2);
goto v___jp_2417_;
}
}
else
{
lean_dec(v_args_2415_);
goto v___jp_2417_;
}
v___jp_2417_:
{
lean_object* v___x_2418_; lean_object* v___x_2419_; 
v___x_2418_ = ((lean_object*)(l_Lean1090_Diagnostics_DecodeCosts_execute___closed__1));
v___x_2419_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2419_, 0, v___x_2418_);
return v___x_2419_;
}
}
}
LEAN_EXPORT lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute___boxed(lean_object* v_args_2457_, lean_object* v_a_2458_){
_start:
{
lean_object* v_res_2459_; 
v_res_2459_ = l_Lean1090_Diagnostics_DecodeCosts_execute(v_args_2457_);
return v_res_2459_;
}
}
LEAN_EXPORT lean_object* _lean_main(lean_object* v_args_2460_){
_start:
{
lean_object* v___x_2462_; 
v___x_2462_ = l_Lean1090_Diagnostics_DecodeCosts_execute(v_args_2460_);
return v___x_2462_;
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_args_2463_, lean_object* v_a_2464_){
_start:
{
lean_object* v_res_2465_; 
v_res_2465_ = _lean_main(v_args_2463_);
return v_res_2465_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Impl(uint8_t builtin);
lean_object* initialize_Lean_Data_Json_Parser(uint8_t builtin);
lean_object* initialize_Lean_Data_Json_FromToJson_Basic(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_review_diagnostics_DecodeCosts(uint8_t builtin) {
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
res = initialize_Lean_Data_Json_Parser(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean_Data_Json_FromToJson_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_offsetBasis = _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_offsetBasis();
l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prime = _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prime();
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
  res = initialize_review_diagnostics_DecodeCosts(1 /* builtin */);
  lean_io_mark_end_initialization();
  if (lean_io_result_is_ok(res)) {
    lean_dec_ref(res);
    lean_init_task_manager();
    res = lean_run_main(&run_main, argc, argv);
  }
  lean_finalize_task_manager();
  if (lean_io_result_is_ok(res)) {
    int ret = 0;
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
