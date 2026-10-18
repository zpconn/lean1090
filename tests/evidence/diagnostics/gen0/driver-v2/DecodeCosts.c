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
lean_object* lp_lean1090_Option_repr___at___00Lean1090_Spec_instReprCommBThreat_repr_spec__0(lean_object*, lean_object*);
lean_object* l_Std_Format_pretty(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_string_to_utf8(lean_object*);
lean_object* lean_byte_array_size(lean_object*);
lean_object* lean_byte_array_data(lean_object*);
size_t lean_usize_of_nat(lean_object*);
lean_object* lp_lean1090_Lean1090_Spec_instReprMessage_repr___redArg(lean_object*);
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
uint8_t lp_lean1090_Lean1090_Impl_commBCoreEligible(lean_object*, lean_object*);
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
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 96, .m_capacity = 96, .m_length = 95, .m_data = "mode must be all, adsb, commb, other, df0..df31, score40/44/45/50/60 or candidate40/44/45/50/60"};
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
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(64) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__0_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(68) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__1_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(69) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__2 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__2_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(80) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__3 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__3_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(96) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__4 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__4_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "score40"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__5 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__5_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "candidate40"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__6 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__6_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "score44"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__7 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__7_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "candidate44"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__8 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__8_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "score45"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__9 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__9_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "candidate45"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__10 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__10_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "score50"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__11 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__11_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "candidate50"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__12 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__12_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "score60"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__13 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__13_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "candidate60"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__14 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__14_value;
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
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0(uint8_t, lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__0_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__0_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__1_value;
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0(uint8_t, lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
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
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = "incomplete retained scores"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__0 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__0_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__0_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__1 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__1_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__2 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__2_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__2_value),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__2_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__3 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__3_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "passes"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__4 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__4_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "df20"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__5 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__5_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "df21"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__6 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__6_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "nonempty_commb"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__7 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__7_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "non_additive_probe"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__8 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__8_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 1}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(1, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__9 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__9_value;
static const lean_ctor_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__8_value),((lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__9_value)}};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__10 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__10_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "probe_scope"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__11 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__11_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "score_only"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__12 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__12_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "hard_checks_and_score"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__13 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__13_value;
static const lean_string_object l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "candidate"};
static const lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__14 = (const lean_object*)&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__14_value;
static lean_once_cell_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__15;
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
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister(lean_object* v_mode_408_){
_start:
{
lean_object* v___x_419_; uint8_t v___x_420_; 
v___x_419_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__5));
v___x_420_ = lean_string_dec_eq(v_mode_408_, v___x_419_);
if (v___x_420_ == 0)
{
lean_object* v___x_421_; uint8_t v___x_422_; 
v___x_421_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__6));
v___x_422_ = lean_string_dec_eq(v_mode_408_, v___x_421_);
if (v___x_422_ == 0)
{
lean_object* v___x_423_; uint8_t v___x_424_; 
v___x_423_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__7));
v___x_424_ = lean_string_dec_eq(v_mode_408_, v___x_423_);
if (v___x_424_ == 0)
{
lean_object* v___x_425_; uint8_t v___x_426_; 
v___x_425_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__8));
v___x_426_ = lean_string_dec_eq(v_mode_408_, v___x_425_);
if (v___x_426_ == 0)
{
lean_object* v___x_427_; uint8_t v___x_428_; 
v___x_427_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__9));
v___x_428_ = lean_string_dec_eq(v_mode_408_, v___x_427_);
if (v___x_428_ == 0)
{
lean_object* v___x_429_; uint8_t v___x_430_; 
v___x_429_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__10));
v___x_430_ = lean_string_dec_eq(v_mode_408_, v___x_429_);
if (v___x_430_ == 0)
{
lean_object* v___x_431_; uint8_t v___x_432_; 
v___x_431_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__11));
v___x_432_ = lean_string_dec_eq(v_mode_408_, v___x_431_);
if (v___x_432_ == 0)
{
lean_object* v___x_433_; uint8_t v___x_434_; 
v___x_433_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__12));
v___x_434_ = lean_string_dec_eq(v_mode_408_, v___x_433_);
if (v___x_434_ == 0)
{
lean_object* v___x_435_; uint8_t v___x_436_; 
v___x_435_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__13));
v___x_436_ = lean_string_dec_eq(v_mode_408_, v___x_435_);
if (v___x_436_ == 0)
{
lean_object* v___x_437_; uint8_t v___x_438_; 
v___x_437_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__14));
v___x_438_ = lean_string_dec_eq(v_mode_408_, v___x_437_);
if (v___x_438_ == 0)
{
lean_object* v___x_439_; 
v___x_439_ = lean_box(0);
return v___x_439_;
}
else
{
goto v___jp_417_;
}
}
else
{
goto v___jp_417_;
}
}
else
{
goto v___jp_415_;
}
}
else
{
goto v___jp_415_;
}
}
else
{
goto v___jp_413_;
}
}
else
{
goto v___jp_413_;
}
}
else
{
goto v___jp_411_;
}
}
else
{
goto v___jp_411_;
}
}
else
{
goto v___jp_409_;
}
}
else
{
goto v___jp_409_;
}
v___jp_409_:
{
lean_object* v___x_410_; 
v___x_410_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__0));
return v___x_410_;
}
v___jp_411_:
{
lean_object* v___x_412_; 
v___x_412_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__1));
return v___x_412_;
}
v___jp_413_:
{
lean_object* v___x_414_; 
v___x_414_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__2));
return v___x_414_;
}
v___jp_415_:
{
lean_object* v___x_416_; 
v___x_416_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__3));
return v___x_416_;
}
v___jp_417_:
{
lean_object* v___x_418_; 
v___x_418_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___closed__4));
return v___x_418_;
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister___boxed(lean_object* v_mode_440_){
_start:
{
lean_object* v_res_441_; 
v_res_441_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister(v_mode_440_);
lean_dec_ref(v_mode_440_);
return v_res_441_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(uint8_t v_enabled_443_, lean_object* v_expected_444_){
_start:
{
if (v_enabled_443_ == 0)
{
lean_object* v___x_446_; lean_object* v___x_447_; 
v___x_446_ = lean_box(0);
v___x_447_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_447_, 0, v___x_446_);
return v___x_447_;
}
else
{
lean_object* v___x_448_; lean_object* v_getLine_449_; lean_object* v___x_450_; 
v___x_448_ = lean_get_stdin();
v_getLine_449_ = lean_ctor_get(v___x_448_, 3);
lean_inc_ref(v_getLine_449_);
lean_dec_ref(v___x_448_);
v___x_450_ = lean_apply_1(v_getLine_449_, lean_box(0));
if (lean_obj_tag(v___x_450_) == 0)
{
lean_object* v_a_451_; lean_object* v___x_453_; uint8_t v_isShared_454_; uint8_t v_isSharedCheck_471_; 
v_a_451_ = lean_ctor_get(v___x_450_, 0);
v_isSharedCheck_471_ = !lean_is_exclusive(v___x_450_);
if (v_isSharedCheck_471_ == 0)
{
v___x_453_ = v___x_450_;
v_isShared_454_ = v_isSharedCheck_471_;
goto v_resetjp_452_;
}
else
{
lean_inc(v_a_451_);
lean_dec(v___x_450_);
v___x_453_ = lean_box(0);
v_isShared_454_ = v_isSharedCheck_471_;
goto v_resetjp_452_;
}
v_resetjp_452_:
{
lean_object* v___x_455_; lean_object* v___x_456_; lean_object* v___x_457_; lean_object* v___x_458_; lean_object* v___x_459_; uint8_t v___x_460_; 
v___x_455_ = lean_unsigned_to_nat(0u);
v___x_456_ = lean_string_utf8_byte_size(v_a_451_);
v___x_457_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_457_, 0, v_a_451_);
lean_ctor_set(v___x_457_, 1, v___x_455_);
lean_ctor_set(v___x_457_, 2, v___x_456_);
v___x_458_ = l_String_Slice_trimAscii(v___x_457_);
v___x_459_ = l_String_Slice_toString(v___x_458_);
lean_dec_ref(v___x_458_);
v___x_460_ = lean_string_dec_eq(v___x_459_, v_expected_444_);
lean_dec_ref(v___x_459_);
if (v___x_460_ == 0)
{
lean_object* v___x_461_; lean_object* v___x_462_; lean_object* v___x_463_; lean_object* v___x_465_; 
v___x_461_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command___closed__0));
v___x_462_ = lean_string_append(v___x_461_, v_expected_444_);
v___x_463_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_463_, 0, v___x_462_);
if (v_isShared_454_ == 0)
{
lean_ctor_set_tag(v___x_453_, 1);
lean_ctor_set(v___x_453_, 0, v___x_463_);
v___x_465_ = v___x_453_;
goto v_reusejp_464_;
}
else
{
lean_object* v_reuseFailAlloc_466_; 
v_reuseFailAlloc_466_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_466_, 0, v___x_463_);
v___x_465_ = v_reuseFailAlloc_466_;
goto v_reusejp_464_;
}
v_reusejp_464_:
{
return v___x_465_;
}
}
else
{
lean_object* v___x_467_; lean_object* v___x_469_; 
v___x_467_ = lean_box(0);
if (v_isShared_454_ == 0)
{
lean_ctor_set(v___x_453_, 0, v___x_467_);
v___x_469_ = v___x_453_;
goto v_reusejp_468_;
}
else
{
lean_object* v_reuseFailAlloc_470_; 
v_reuseFailAlloc_470_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_470_, 0, v___x_467_);
v___x_469_ = v_reuseFailAlloc_470_;
goto v_reusejp_468_;
}
v_reusejp_468_:
{
return v___x_469_;
}
}
}
}
else
{
lean_object* v_a_472_; lean_object* v___x_474_; uint8_t v_isShared_475_; uint8_t v_isSharedCheck_479_; 
v_a_472_ = lean_ctor_get(v___x_450_, 0);
v_isSharedCheck_479_ = !lean_is_exclusive(v___x_450_);
if (v_isSharedCheck_479_ == 0)
{
v___x_474_ = v___x_450_;
v_isShared_475_ = v_isSharedCheck_479_;
goto v_resetjp_473_;
}
else
{
lean_inc(v_a_472_);
lean_dec(v___x_450_);
v___x_474_ = lean_box(0);
v_isShared_475_ = v_isSharedCheck_479_;
goto v_resetjp_473_;
}
v_resetjp_473_:
{
lean_object* v___x_477_; 
if (v_isShared_475_ == 0)
{
v___x_477_ = v___x_474_;
goto v_reusejp_476_;
}
else
{
lean_object* v_reuseFailAlloc_478_; 
v_reuseFailAlloc_478_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_478_, 0, v_a_472_);
v___x_477_ = v_reuseFailAlloc_478_;
goto v_reusejp_476_;
}
v_reusejp_476_:
{
return v___x_477_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command___boxed(lean_object* v_enabled_480_, lean_object* v_expected_481_, lean_object* v_a_482_){
_start:
{
uint8_t v_enabled_boxed_483_; lean_object* v_res_484_; 
v_enabled_boxed_483_ = lean_unbox(v_enabled_480_);
v_res_484_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_enabled_boxed_483_, v_expected_481_);
lean_dec_ref(v_expected_481_);
return v_res_484_;
}
}
static uint64_t _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_offsetBasis(void){
_start:
{
uint64_t v___x_485_; 
v___x_485_ = 14695981039346656037ULL;
return v___x_485_;
}
}
static uint64_t _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prime(void){
_start:
{
uint64_t v___x_486_; 
v___x_486_ = 1099511628211ULL;
return v___x_486_;
}
}
LEAN_EXPORT uint64_t l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(lean_object* v_as_487_, size_t v_i_488_, size_t v_stop_489_, uint64_t v_b_490_){
_start:
{
uint8_t v___x_491_; 
v___x_491_ = lean_usize_dec_eq(v_i_488_, v_stop_489_);
if (v___x_491_ == 0)
{
lean_object* v___x_492_; uint8_t v___x_493_; uint64_t v___x_494_; uint64_t v___x_495_; uint64_t v___x_496_; uint64_t v___x_497_; size_t v___x_498_; size_t v___x_499_; 
v___x_492_ = lean_array_uget_borrowed(v_as_487_, v_i_488_);
v___x_493_ = lean_unbox(v___x_492_);
v___x_494_ = lean_uint8_to_uint64(v___x_493_);
v___x_495_ = lean_uint64_xor(v_b_490_, v___x_494_);
v___x_496_ = 1099511628211ULL;
v___x_497_ = lean_uint64_mul(v___x_495_, v___x_496_);
v___x_498_ = ((size_t)1ULL);
v___x_499_ = lean_usize_add(v_i_488_, v___x_498_);
v_i_488_ = v___x_499_;
v_b_490_ = v___x_497_;
goto _start;
}
else
{
return v_b_490_;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0___boxed(lean_object* v_as_501_, lean_object* v_i_502_, lean_object* v_stop_503_, lean_object* v_b_504_){
_start:
{
size_t v_i_boxed_505_; size_t v_stop_boxed_506_; uint64_t v_b_boxed_507_; uint64_t v_res_508_; lean_object* v_r_509_; 
v_i_boxed_505_ = lean_unbox_usize(v_i_502_);
lean_dec(v_i_502_);
v_stop_boxed_506_ = lean_unbox_usize(v_stop_503_);
lean_dec(v_stop_503_);
v_b_boxed_507_ = lean_unbox_uint64(v_b_504_);
lean_dec_ref(v_b_504_);
v_res_508_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(v_as_501_, v_i_boxed_505_, v_stop_boxed_506_, v_b_boxed_507_);
lean_dec_ref(v_as_501_);
v_r_509_ = lean_box_uint64(v_res_508_);
return v_r_509_;
}
}
LEAN_EXPORT uint64_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes(uint64_t v_hash_510_, lean_object* v_bytes_511_){
_start:
{
lean_object* v___x_512_; lean_object* v___x_513_; lean_object* v___x_514_; uint8_t v___x_515_; 
v___x_512_ = lean_byte_array_data(v_bytes_511_);
v___x_513_ = lean_unsigned_to_nat(0u);
v___x_514_ = lean_array_get_size(v___x_512_);
v___x_515_ = lean_nat_dec_lt(v___x_513_, v___x_514_);
if (v___x_515_ == 0)
{
lean_dec_ref(v___x_512_);
return v_hash_510_;
}
else
{
uint8_t v___x_516_; 
v___x_516_ = lean_nat_dec_le(v___x_514_, v___x_514_);
if (v___x_516_ == 0)
{
if (v___x_515_ == 0)
{
lean_dec_ref(v___x_512_);
return v_hash_510_;
}
else
{
size_t v___x_517_; size_t v___x_518_; uint64_t v___x_519_; 
v___x_517_ = ((size_t)0ULL);
v___x_518_ = lean_usize_of_nat(v___x_514_);
v___x_519_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(v___x_512_, v___x_517_, v___x_518_, v_hash_510_);
lean_dec_ref(v___x_512_);
return v___x_519_;
}
}
else
{
size_t v___x_520_; size_t v___x_521_; uint64_t v___x_522_; 
v___x_520_ = ((size_t)0ULL);
v___x_521_ = lean_usize_of_nat(v___x_514_);
v___x_522_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(v___x_512_, v___x_520_, v___x_521_, v_hash_510_);
lean_dec_ref(v___x_512_);
return v___x_522_;
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes___boxed(lean_object* v_hash_523_, lean_object* v_bytes_524_){
_start:
{
uint64_t v_hash_boxed_525_; uint64_t v_res_526_; lean_object* v_r_527_; 
v_hash_boxed_525_ = lean_unbox_uint64(v_hash_523_);
lean_dec_ref(v_hash_523_);
v_res_526_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes(v_hash_boxed_525_, v_bytes_524_);
v_r_527_ = lean_box_uint64(v_res_526_);
return v_r_527_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(lean_object* v_digest_528_, lean_object* v_bytes_529_){
_start:
{
lean_object* v_count_530_; lean_object* v_bytes_531_; uint64_t v_value_532_; lean_object* v___x_534_; uint8_t v_isShared_535_; uint8_t v_isSharedCheck_544_; 
v_count_530_ = lean_ctor_get(v_digest_528_, 0);
v_bytes_531_ = lean_ctor_get(v_digest_528_, 1);
v_value_532_ = lean_ctor_get_uint64(v_digest_528_, sizeof(void*)*2);
v_isSharedCheck_544_ = !lean_is_exclusive(v_digest_528_);
if (v_isSharedCheck_544_ == 0)
{
v___x_534_ = v_digest_528_;
v_isShared_535_ = v_isSharedCheck_544_;
goto v_resetjp_533_;
}
else
{
lean_inc(v_bytes_531_);
lean_inc(v_count_530_);
lean_dec(v_digest_528_);
v___x_534_ = lean_box(0);
v_isShared_535_ = v_isSharedCheck_544_;
goto v_resetjp_533_;
}
v_resetjp_533_:
{
lean_object* v___x_536_; lean_object* v___x_537_; lean_object* v___x_538_; lean_object* v___x_539_; uint64_t v___x_540_; lean_object* v___x_542_; 
v___x_536_ = lean_unsigned_to_nat(1u);
v___x_537_ = lean_nat_add(v_count_530_, v___x_536_);
lean_dec(v_count_530_);
v___x_538_ = lean_byte_array_size(v_bytes_529_);
v___x_539_ = lean_nat_add(v_bytes_531_, v___x_538_);
lean_dec(v_bytes_531_);
v___x_540_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes(v_value_532_, v_bytes_529_);
if (v_isShared_535_ == 0)
{
lean_ctor_set(v___x_534_, 1, v___x_539_);
lean_ctor_set(v___x_534_, 0, v___x_537_);
v___x_542_ = v___x_534_;
goto v_reusejp_541_;
}
else
{
lean_object* v_reuseFailAlloc_543_; 
v_reuseFailAlloc_543_ = lean_alloc_ctor(0, 2, 8);
lean_ctor_set(v_reuseFailAlloc_543_, 0, v___x_537_);
lean_ctor_set(v_reuseFailAlloc_543_, 1, v___x_539_);
v___x_542_ = v_reuseFailAlloc_543_;
goto v_reusejp_541_;
}
v_reusejp_541_:
{
lean_ctor_set_uint64(v___x_542_, sizeof(void*)*2, v___x_540_);
return v___x_542_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__1(lean_object* v_a_545_, lean_object* v_a_546_){
_start:
{
if (lean_obj_tag(v_a_545_) == 0)
{
lean_object* v___x_547_; 
v___x_547_ = l_List_reverse___redArg(v_a_546_);
return v___x_547_;
}
else
{
lean_object* v_head_548_; lean_object* v_tail_549_; lean_object* v___x_551_; uint8_t v_isShared_552_; uint8_t v_isSharedCheck_558_; 
v_head_548_ = lean_ctor_get(v_a_545_, 0);
v_tail_549_ = lean_ctor_get(v_a_545_, 1);
v_isSharedCheck_558_ = !lean_is_exclusive(v_a_545_);
if (v_isSharedCheck_558_ == 0)
{
v___x_551_ = v_a_545_;
v_isShared_552_ = v_isSharedCheck_558_;
goto v_resetjp_550_;
}
else
{
lean_inc(v_tail_549_);
lean_inc(v_head_548_);
lean_dec(v_a_545_);
v___x_551_ = lean_box(0);
v_isShared_552_ = v_isSharedCheck_558_;
goto v_resetjp_550_;
}
v_resetjp_550_:
{
lean_object* v_count_553_; lean_object* v___x_555_; 
v_count_553_ = lean_ctor_get(v_head_548_, 0);
lean_inc(v_count_553_);
lean_dec(v_head_548_);
if (v_isShared_552_ == 0)
{
lean_ctor_set(v___x_551_, 1, v_a_546_);
lean_ctor_set(v___x_551_, 0, v_count_553_);
v___x_555_ = v___x_551_;
goto v_reusejp_554_;
}
else
{
lean_object* v_reuseFailAlloc_557_; 
v_reuseFailAlloc_557_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_557_, 0, v_count_553_);
lean_ctor_set(v_reuseFailAlloc_557_, 1, v_a_546_);
v___x_555_ = v_reuseFailAlloc_557_;
goto v_reusejp_554_;
}
v_reusejp_554_:
{
v_a_545_ = v_tail_549_;
v_a_546_ = v___x_555_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(lean_object* v_inputs_562_, lean_object* v_output_563_, lean_object* v_range_564_, lean_object* v_b_565_, lean_object* v_i_566_){
_start:
{
lean_object* v_stop_568_; lean_object* v_step_569_; uint8_t v___x_570_; 
v_stop_568_ = lean_ctor_get(v_range_564_, 1);
v_step_569_ = lean_ctor_get(v_range_564_, 2);
v___x_570_ = lean_nat_dec_lt(v_i_566_, v_stop_568_);
if (v___x_570_ == 0)
{
lean_object* v___x_571_; 
lean_dec(v_i_566_);
v___x_571_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_571_, 0, v_b_565_);
return v___x_571_;
}
else
{
lean_object* v___x_572_; uint8_t v___x_573_; 
v___x_572_ = lean_array_get_size(v_inputs_562_);
v___x_573_ = lean_nat_dec_lt(v_i_566_, v___x_572_);
if (v___x_573_ == 0)
{
lean_object* v___x_574_; lean_object* v___x_575_; 
lean_dec(v_i_566_);
lean_dec_ref(v_b_565_);
v___x_574_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___closed__1));
v___x_575_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_575_, 0, v___x_574_);
return v___x_575_;
}
else
{
lean_object* v_fst_576_; lean_object* v_snd_577_; lean_object* v___x_579_; uint8_t v_isShared_580_; uint8_t v_isSharedCheck_606_; 
v_fst_576_ = lean_ctor_get(v_b_565_, 0);
v_snd_577_ = lean_ctor_get(v_b_565_, 1);
v_isSharedCheck_606_ = !lean_is_exclusive(v_b_565_);
if (v_isSharedCheck_606_ == 0)
{
v___x_579_ = v_b_565_;
v_isShared_580_ = v_isSharedCheck_606_;
goto v_resetjp_578_;
}
else
{
lean_inc(v_snd_577_);
lean_inc(v_fst_576_);
lean_dec(v_b_565_);
v___x_579_ = lean_box(0);
v_isShared_580_ = v_isSharedCheck_606_;
goto v_resetjp_578_;
}
v_resetjp_578_:
{
lean_object* v___x_581_; lean_object* v___x_582_; lean_object* v___x_583_; lean_object* v___x_584_; lean_object* v___x_585_; lean_object* v___x_586_; lean_object* v_df_587_; lean_object* v___x_588_; lean_object* v___x_589_; lean_object* v_bytes_590_; lean_object* v_total_591_; lean_object* v___y_593_; lean_object* v___x_599_; uint8_t v___x_600_; 
v___x_581_ = lean_array_fget_borrowed(v_inputs_562_, v_i_566_);
v___x_582_ = lean_array_fget_borrowed(v_output_563_, v_i_566_);
v___x_583_ = lean_unsigned_to_nat(0u);
lean_inc(v___x_582_);
v___x_584_ = lp_lean1090_Lean1090_Spec_instReprMessage_repr___redArg(v___x_582_);
v___x_585_ = lean_unsigned_to_nat(120u);
v___x_586_ = l_Std_Format_pretty(v___x_584_, v___x_585_, v___x_583_, v___x_583_);
v_df_587_ = lean_ctor_get(v___x_581_, 0);
v___x_588_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__0));
v___x_589_ = lean_string_append(v___x_586_, v___x_588_);
v_bytes_590_ = lean_string_to_utf8(v___x_589_);
lean_dec_ref(v___x_589_);
lean_inc_ref(v_bytes_590_);
v_total_591_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(v_fst_576_, v_bytes_590_);
v___x_599_ = lean_array_get_size(v_snd_577_);
v___x_600_ = lean_nat_dec_lt(v_df_587_, v___x_599_);
if (v___x_600_ == 0)
{
lean_dec_ref(v_bytes_590_);
v___y_593_ = v_snd_577_;
goto v___jp_592_;
}
else
{
lean_object* v_v_601_; lean_object* v___x_602_; lean_object* v_xs_x27_603_; lean_object* v___x_604_; lean_object* v___x_605_; 
v_v_601_ = lean_array_fget(v_snd_577_, v_df_587_);
v___x_602_ = lean_box(0);
v_xs_x27_603_ = lean_array_fset(v_snd_577_, v_df_587_, v___x_602_);
v___x_604_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(v_v_601_, v_bytes_590_);
v___x_605_ = lean_array_fset(v_xs_x27_603_, v_df_587_, v___x_604_);
v___y_593_ = v___x_605_;
goto v___jp_592_;
}
v___jp_592_:
{
lean_object* v___x_595_; 
if (v_isShared_580_ == 0)
{
lean_ctor_set(v___x_579_, 1, v___y_593_);
lean_ctor_set(v___x_579_, 0, v_total_591_);
v___x_595_ = v___x_579_;
goto v_reusejp_594_;
}
else
{
lean_object* v_reuseFailAlloc_598_; 
v_reuseFailAlloc_598_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_598_, 0, v_total_591_);
lean_ctor_set(v_reuseFailAlloc_598_, 1, v___y_593_);
v___x_595_ = v_reuseFailAlloc_598_;
goto v_reusejp_594_;
}
v_reusejp_594_:
{
lean_object* v___x_596_; 
v___x_596_ = lean_nat_add(v_i_566_, v_step_569_);
lean_dec(v_i_566_);
v_b_565_ = v___x_595_;
v_i_566_ = v___x_596_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___boxed(lean_object* v_inputs_607_, lean_object* v_output_608_, lean_object* v_range_609_, lean_object* v_b_610_, lean_object* v_i_611_, lean_object* v___y_612_){
_start:
{
lean_object* v_res_613_; 
v_res_613_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(v_inputs_607_, v_output_608_, v_range_609_, v_b_610_, v_i_611_);
lean_dec_ref(v_range_609_);
lean_dec_ref(v_output_608_);
lean_dec_ref(v_inputs_607_);
return v_res_613_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3(void){
_start:
{
lean_object* v_total_620_; lean_object* v___x_621_; lean_object* v_byDF_622_; 
v_total_620_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__2));
v___x_621_ = lean_unsigned_to_nat(32u);
v_byDF_622_ = lean_mk_array(v___x_621_, v_total_620_);
return v_byDF_622_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4(void){
_start:
{
lean_object* v_byDF_623_; lean_object* v_total_624_; lean_object* v___x_625_; 
v_byDF_623_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3);
v_total_624_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__2));
v___x_625_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_625_, 0, v_total_624_);
lean_ctor_set(v___x_625_, 1, v_byDF_623_);
return v___x_625_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume(lean_object* v_inputs_629_, lean_object* v_output_630_){
_start:
{
lean_object* v___x_632_; lean_object* v___x_633_; uint8_t v___x_634_; 
v___x_632_ = lean_array_get_size(v_output_630_);
v___x_633_ = lean_array_get_size(v_inputs_629_);
v___x_634_ = lean_nat_dec_eq(v___x_632_, v___x_633_);
if (v___x_634_ == 0)
{
lean_object* v___x_635_; lean_object* v___x_636_; 
v___x_635_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__1));
v___x_636_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_636_, 0, v___x_635_);
return v___x_636_;
}
else
{
lean_object* v___x_637_; lean_object* v___x_638_; lean_object* v___x_639_; lean_object* v___x_640_; lean_object* v___x_641_; 
v___x_637_ = lean_unsigned_to_nat(0u);
v___x_638_ = lean_unsigned_to_nat(1u);
v___x_639_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_639_, 0, v___x_637_);
lean_ctor_set(v___x_639_, 1, v___x_632_);
lean_ctor_set(v___x_639_, 2, v___x_638_);
v___x_640_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4);
v___x_641_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(v_inputs_629_, v_output_630_, v___x_639_, v___x_640_, v___x_637_);
lean_dec_ref_known(v___x_639_, 3);
if (lean_obj_tag(v___x_641_) == 0)
{
lean_object* v_a_642_; lean_object* v___x_644_; uint8_t v_isShared_645_; uint8_t v_isSharedCheck_667_; 
v_a_642_ = lean_ctor_get(v___x_641_, 0);
v_isSharedCheck_667_ = !lean_is_exclusive(v___x_641_);
if (v_isSharedCheck_667_ == 0)
{
v___x_644_ = v___x_641_;
v_isShared_645_ = v_isSharedCheck_667_;
goto v_resetjp_643_;
}
else
{
lean_inc(v_a_642_);
lean_dec(v___x_641_);
v___x_644_ = lean_box(0);
v_isShared_645_ = v_isSharedCheck_667_;
goto v_resetjp_643_;
}
v_resetjp_643_:
{
lean_object* v_fst_646_; lean_object* v_snd_647_; lean_object* v___x_649_; uint8_t v_isShared_650_; uint8_t v_isSharedCheck_666_; 
v_fst_646_ = lean_ctor_get(v_a_642_, 0);
v_snd_647_ = lean_ctor_get(v_a_642_, 1);
v_isSharedCheck_666_ = !lean_is_exclusive(v_a_642_);
if (v_isSharedCheck_666_ == 0)
{
v___x_649_ = v_a_642_;
v_isShared_650_ = v_isSharedCheck_666_;
goto v_resetjp_648_;
}
else
{
lean_inc(v_snd_647_);
lean_inc(v_fst_646_);
lean_dec(v_a_642_);
v___x_649_ = lean_box(0);
v_isShared_650_ = v_isSharedCheck_666_;
goto v_resetjp_648_;
}
v_resetjp_648_:
{
lean_object* v___x_651_; lean_object* v___x_652_; lean_object* v___x_653_; lean_object* v___x_654_; uint8_t v___x_655_; 
lean_inc(v_snd_647_);
v___x_651_ = lean_array_to_list(v_snd_647_);
v___x_652_ = lean_box(0);
v___x_653_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__1(v___x_651_, v___x_652_);
v___x_654_ = l_List_sum___at___00Lean_PersistentHashMap_subarrayMeasure_spec__2(v___x_653_);
lean_dec(v___x_653_);
v___x_655_ = lean_nat_dec_eq(v___x_654_, v___x_632_);
lean_dec(v___x_654_);
if (v___x_655_ == 0)
{
lean_object* v___x_656_; lean_object* v___x_658_; 
lean_del_object(v___x_649_);
lean_dec(v_snd_647_);
lean_dec(v_fst_646_);
v___x_656_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__6));
if (v_isShared_645_ == 0)
{
lean_ctor_set_tag(v___x_644_, 1);
lean_ctor_set(v___x_644_, 0, v___x_656_);
v___x_658_ = v___x_644_;
goto v_reusejp_657_;
}
else
{
lean_object* v_reuseFailAlloc_659_; 
v_reuseFailAlloc_659_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_659_, 0, v___x_656_);
v___x_658_ = v_reuseFailAlloc_659_;
goto v_reusejp_657_;
}
v_reusejp_657_:
{
return v___x_658_;
}
}
else
{
lean_object* v___x_661_; 
if (v_isShared_650_ == 0)
{
v___x_661_ = v___x_649_;
goto v_reusejp_660_;
}
else
{
lean_object* v_reuseFailAlloc_665_; 
v_reuseFailAlloc_665_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_665_, 0, v_fst_646_);
lean_ctor_set(v_reuseFailAlloc_665_, 1, v_snd_647_);
v___x_661_ = v_reuseFailAlloc_665_;
goto v_reusejp_660_;
}
v_reusejp_660_:
{
lean_object* v___x_663_; 
if (v_isShared_645_ == 0)
{
lean_ctor_set(v___x_644_, 0, v___x_661_);
v___x_663_ = v___x_644_;
goto v_reusejp_662_;
}
else
{
lean_object* v_reuseFailAlloc_664_; 
v_reuseFailAlloc_664_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_664_, 0, v___x_661_);
v___x_663_ = v_reuseFailAlloc_664_;
goto v_reusejp_662_;
}
v_reusejp_662_:
{
return v___x_663_;
}
}
}
}
}
}
else
{
return v___x_641_;
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___boxed(lean_object* v_inputs_668_, lean_object* v_output_669_, lean_object* v_a_670_){
_start:
{
lean_object* v_res_671_; 
v_res_671_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume(v_inputs_668_, v_output_669_);
lean_dec_ref(v_output_669_);
lean_dec_ref(v_inputs_668_);
return v_res_671_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0(lean_object* v_inputs_672_, lean_object* v_output_673_, lean_object* v_range_674_, lean_object* v_b_675_, lean_object* v_i_676_, lean_object* v_hs_677_, lean_object* v_hl_678_){
_start:
{
lean_object* v___x_680_; 
v___x_680_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(v_inputs_672_, v_output_673_, v_range_674_, v_b_675_, v_i_676_);
return v___x_680_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___boxed(lean_object* v_inputs_681_, lean_object* v_output_682_, lean_object* v_range_683_, lean_object* v_b_684_, lean_object* v_i_685_, lean_object* v_hs_686_, lean_object* v_hl_687_, lean_object* v___y_688_){
_start:
{
lean_object* v_res_689_; 
v_res_689_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0(v_inputs_681_, v_output_682_, v_range_683_, v_b_684_, v_i_685_, v_hs_686_, v_hl_687_);
lean_dec_ref(v_range_683_);
lean_dec_ref(v_output_682_);
lean_dec_ref(v_inputs_681_);
return v_res_689_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(lean_object* v_digest_693_){
_start:
{
lean_object* v_count_694_; lean_object* v_bytes_695_; uint64_t v_value_696_; lean_object* v___x_697_; lean_object* v___x_698_; lean_object* v___x_699_; lean_object* v___x_700_; lean_object* v___x_701_; lean_object* v___x_702_; lean_object* v___x_703_; lean_object* v___x_704_; lean_object* v___x_705_; lean_object* v___x_706_; lean_object* v___x_707_; lean_object* v___x_708_; lean_object* v___x_709_; lean_object* v___x_710_; lean_object* v___x_711_; lean_object* v___x_712_; lean_object* v___x_713_; lean_object* v___x_714_; 
v_count_694_ = lean_ctor_get(v_digest_693_, 0);
lean_inc(v_count_694_);
v_bytes_695_ = lean_ctor_get(v_digest_693_, 1);
lean_inc(v_bytes_695_);
v_value_696_ = lean_ctor_get_uint64(v_digest_693_, sizeof(void*)*2);
lean_dec_ref(v_digest_693_);
v___x_697_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0));
v___x_698_ = l_Lean_JsonNumber_fromNat(v_count_694_);
v___x_699_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_699_, 0, v___x_698_);
v___x_700_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_700_, 0, v___x_697_);
lean_ctor_set(v___x_700_, 1, v___x_699_);
v___x_701_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__1));
v___x_702_ = l_Lean_JsonNumber_fromNat(v_bytes_695_);
v___x_703_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_703_, 0, v___x_702_);
v___x_704_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_704_, 0, v___x_701_);
lean_ctor_set(v___x_704_, 1, v___x_703_);
v___x_705_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__2));
v___x_706_ = lean_uint64_to_nat(v_value_696_);
v___x_707_ = l_Lean_JsonNumber_fromNat(v___x_706_);
v___x_708_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_708_, 0, v___x_707_);
v___x_709_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_709_, 0, v___x_705_);
lean_ctor_set(v___x_709_, 1, v___x_708_);
v___x_710_ = lean_box(0);
v___x_711_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_711_, 0, v___x_709_);
lean_ctor_set(v___x_711_, 1, v___x_710_);
v___x_712_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_712_, 0, v___x_704_);
lean_ctor_set(v___x_712_, 1, v___x_711_);
v___x_713_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_713_, 0, v___x_700_);
lean_ctor_set(v___x_713_, 1, v___x_712_);
v___x_714_ = l_Lean_Json_mkObj(v___x_713_);
lean_dec_ref_known(v___x_713_, 2);
return v___x_714_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0(lean_object* v_as_716_, size_t v_sz_717_, size_t v_i_718_, lean_object* v_b_719_){
_start:
{
uint8_t v___x_721_; 
v___x_721_ = lean_usize_dec_lt(v_i_718_, v_sz_717_);
if (v___x_721_ == 0)
{
lean_object* v___x_722_; 
v___x_722_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_722_, 0, v_b_719_);
return v___x_722_;
}
else
{
lean_object* v_a_723_; lean_object* v_df_724_; lean_object* v_bytes_725_; lean_object* v___x_726_; 
v_a_723_ = lean_array_uget_borrowed(v_as_716_, v_i_718_);
v_df_724_ = lean_ctor_get(v_a_723_, 0);
v_bytes_725_ = lean_ctor_get(v_a_723_, 1);
v___x_726_ = lp_lean1090_Lean1090_Impl_decode(v_bytes_725_);
if (lean_obj_tag(v___x_726_) == 1)
{
lean_object* v_val_727_; lean_object* v___x_728_; size_t v___x_729_; size_t v___x_730_; 
v_val_727_ = lean_ctor_get(v___x_726_, 0);
lean_inc(v_val_727_);
lean_dec_ref_known(v___x_726_, 1);
v___x_728_ = lean_array_push(v_b_719_, v_val_727_);
v___x_729_ = ((size_t)1ULL);
v___x_730_ = lean_usize_add(v_i_718_, v___x_729_);
v_i_718_ = v___x_730_;
v_b_719_ = v___x_728_;
goto _start;
}
else
{
lean_object* v___x_732_; lean_object* v___x_733_; lean_object* v___x_734_; lean_object* v___x_735_; lean_object* v___x_736_; 
lean_dec(v___x_726_);
lean_dec_ref(v_b_719_);
v___x_732_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0___closed__0));
lean_inc(v_df_724_);
v___x_733_ = l_Nat_reprFast(v_df_724_);
v___x_734_ = lean_string_append(v___x_732_, v___x_733_);
lean_dec_ref(v___x_733_);
v___x_735_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_735_, 0, v___x_734_);
v___x_736_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_736_, 0, v___x_735_);
return v___x_736_;
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0___boxed(lean_object* v_as_737_, lean_object* v_sz_738_, lean_object* v_i_739_, lean_object* v_b_740_, lean_object* v___y_741_){
_start:
{
size_t v_sz_boxed_742_; size_t v_i_boxed_743_; lean_object* v_res_744_; 
v_sz_boxed_742_ = lean_unbox_usize(v_sz_738_);
lean_dec(v_sz_738_);
v_i_boxed_743_ = lean_unbox_usize(v_i_739_);
lean_dec(v_i_739_);
v_res_744_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0(v_as_737_, v_sz_boxed_742_, v_i_boxed_743_, v_b_740_);
lean_dec_ref(v_as_737_);
return v_res_744_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode(lean_object* v_inputs_745_){
_start:
{
lean_object* v___x_747_; lean_object* v_output_748_; lean_object* v___x_749_; size_t v_sz_750_; size_t v___x_751_; lean_object* v___x_752_; 
v___x_747_ = lean_array_get_size(v_inputs_745_);
v_output_748_ = lean_mk_empty_array_with_capacity(v___x_747_);
v___x_749_ = lean_io_get_num_heartbeats();
v_sz_750_ = lean_array_size(v_inputs_745_);
v___x_751_ = ((size_t)0ULL);
v___x_752_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0(v_inputs_745_, v_sz_750_, v___x_751_, v_output_748_);
if (lean_obj_tag(v___x_752_) == 0)
{
lean_object* v_a_753_; lean_object* v___x_755_; uint8_t v_isShared_756_; uint8_t v_isSharedCheck_763_; 
v_a_753_ = lean_ctor_get(v___x_752_, 0);
v_isSharedCheck_763_ = !lean_is_exclusive(v___x_752_);
if (v_isSharedCheck_763_ == 0)
{
v___x_755_ = v___x_752_;
v_isShared_756_ = v_isSharedCheck_763_;
goto v_resetjp_754_;
}
else
{
lean_inc(v_a_753_);
lean_dec(v___x_752_);
v___x_755_ = lean_box(0);
v_isShared_756_ = v_isSharedCheck_763_;
goto v_resetjp_754_;
}
v_resetjp_754_:
{
lean_object* v___x_757_; lean_object* v___x_758_; lean_object* v___x_759_; lean_object* v___x_761_; 
v___x_757_ = lean_io_get_num_heartbeats();
v___x_758_ = lean_nat_sub(v___x_757_, v___x_749_);
lean_dec(v___x_749_);
lean_dec(v___x_757_);
v___x_759_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_759_, 0, v_a_753_);
lean_ctor_set(v___x_759_, 1, v___x_758_);
if (v_isShared_756_ == 0)
{
lean_ctor_set(v___x_755_, 0, v___x_759_);
v___x_761_ = v___x_755_;
goto v_reusejp_760_;
}
else
{
lean_object* v_reuseFailAlloc_762_; 
v_reuseFailAlloc_762_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_762_, 0, v___x_759_);
v___x_761_ = v_reuseFailAlloc_762_;
goto v_reusejp_760_;
}
v_reusejp_760_:
{
return v___x_761_;
}
}
}
else
{
lean_object* v_a_764_; lean_object* v___x_766_; uint8_t v_isShared_767_; uint8_t v_isSharedCheck_771_; 
lean_dec(v___x_749_);
v_a_764_ = lean_ctor_get(v___x_752_, 0);
v_isSharedCheck_771_ = !lean_is_exclusive(v___x_752_);
if (v_isSharedCheck_771_ == 0)
{
v___x_766_ = v___x_752_;
v_isShared_767_ = v_isSharedCheck_771_;
goto v_resetjp_765_;
}
else
{
lean_inc(v_a_764_);
lean_dec(v___x_752_);
v___x_766_ = lean_box(0);
v_isShared_767_ = v_isSharedCheck_771_;
goto v_resetjp_765_;
}
v_resetjp_765_:
{
lean_object* v___x_769_; 
if (v_isShared_767_ == 0)
{
v___x_769_ = v___x_766_;
goto v_reusejp_768_;
}
else
{
lean_object* v_reuseFailAlloc_770_; 
v_reuseFailAlloc_770_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_770_, 0, v_a_764_);
v___x_769_ = v_reuseFailAlloc_770_;
goto v_reusejp_768_;
}
v_reusejp_768_:
{
return v___x_769_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode___boxed(lean_object* v_inputs_772_, lean_object* v_a_773_){
_start:
{
lean_object* v_res_774_; 
v_res_774_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode(v_inputs_772_);
lean_dec_ref(v_inputs_772_);
return v_res_774_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_bump(lean_object* v_values_775_, lean_object* v_key_776_){
_start:
{
if (lean_obj_tag(v_values_775_) == 0)
{
lean_object* v___x_777_; lean_object* v___x_778_; lean_object* v___x_779_; 
v___x_777_ = lean_unsigned_to_nat(1u);
v___x_778_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_778_, 0, v_key_776_);
lean_ctor_set(v___x_778_, 1, v___x_777_);
v___x_779_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_779_, 0, v___x_778_);
lean_ctor_set(v___x_779_, 1, v_values_775_);
return v___x_779_;
}
else
{
lean_object* v_head_780_; lean_object* v_tail_781_; lean_object* v___x_783_; uint8_t v_isShared_784_; uint8_t v_isSharedCheck_806_; 
v_head_780_ = lean_ctor_get(v_values_775_, 0);
v_tail_781_ = lean_ctor_get(v_values_775_, 1);
v_isSharedCheck_806_ = !lean_is_exclusive(v_values_775_);
if (v_isSharedCheck_806_ == 0)
{
v___x_783_ = v_values_775_;
v_isShared_784_ = v_isSharedCheck_806_;
goto v_resetjp_782_;
}
else
{
lean_inc(v_tail_781_);
lean_inc(v_head_780_);
lean_dec(v_values_775_);
v___x_783_ = lean_box(0);
v_isShared_784_ = v_isSharedCheck_806_;
goto v_resetjp_782_;
}
v_resetjp_782_:
{
lean_object* v_fst_785_; lean_object* v_snd_786_; uint8_t v___x_787_; 
v_fst_785_ = lean_ctor_get(v_head_780_, 0);
v_snd_786_ = lean_ctor_get(v_head_780_, 1);
v___x_787_ = lean_nat_dec_eq(v_fst_785_, v_key_776_);
if (v___x_787_ == 0)
{
lean_object* v___x_788_; lean_object* v___x_790_; 
v___x_788_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_bump(v_tail_781_, v_key_776_);
if (v_isShared_784_ == 0)
{
lean_ctor_set(v___x_783_, 1, v___x_788_);
v___x_790_ = v___x_783_;
goto v_reusejp_789_;
}
else
{
lean_object* v_reuseFailAlloc_791_; 
v_reuseFailAlloc_791_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_791_, 0, v_head_780_);
lean_ctor_set(v_reuseFailAlloc_791_, 1, v___x_788_);
v___x_790_ = v_reuseFailAlloc_791_;
goto v_reusejp_789_;
}
v_reusejp_789_:
{
return v___x_790_;
}
}
else
{
lean_object* v___x_793_; uint8_t v_isShared_794_; uint8_t v_isSharedCheck_803_; 
lean_inc(v_snd_786_);
lean_inc(v_fst_785_);
lean_dec(v_key_776_);
v_isSharedCheck_803_ = !lean_is_exclusive(v_head_780_);
if (v_isSharedCheck_803_ == 0)
{
lean_object* v_unused_804_; lean_object* v_unused_805_; 
v_unused_804_ = lean_ctor_get(v_head_780_, 1);
lean_dec(v_unused_804_);
v_unused_805_ = lean_ctor_get(v_head_780_, 0);
lean_dec(v_unused_805_);
v___x_793_ = v_head_780_;
v_isShared_794_ = v_isSharedCheck_803_;
goto v_resetjp_792_;
}
else
{
lean_dec(v_head_780_);
v___x_793_ = lean_box(0);
v_isShared_794_ = v_isSharedCheck_803_;
goto v_resetjp_792_;
}
v_resetjp_792_:
{
lean_object* v___x_795_; lean_object* v___x_796_; lean_object* v___x_798_; 
v___x_795_ = lean_unsigned_to_nat(1u);
v___x_796_ = lean_nat_add(v_snd_786_, v___x_795_);
lean_dec(v_snd_786_);
if (v_isShared_794_ == 0)
{
lean_ctor_set(v___x_793_, 1, v___x_796_);
v___x_798_ = v___x_793_;
goto v_reusejp_797_;
}
else
{
lean_object* v_reuseFailAlloc_802_; 
v_reuseFailAlloc_802_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_802_, 0, v_fst_785_);
lean_ctor_set(v_reuseFailAlloc_802_, 1, v___x_796_);
v___x_798_ = v_reuseFailAlloc_802_;
goto v_reusejp_797_;
}
v_reusejp_797_:
{
lean_object* v___x_800_; 
if (v_isShared_784_ == 0)
{
lean_ctor_set(v___x_783_, 0, v___x_798_);
v___x_800_ = v___x_783_;
goto v_reusejp_799_;
}
else
{
lean_object* v_reuseFailAlloc_801_; 
v_reuseFailAlloc_801_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_801_, 0, v___x_798_);
lean_ctor_set(v_reuseFailAlloc_801_, 1, v_tail_781_);
v___x_800_ = v_reuseFailAlloc_801_;
goto v_reusejp_799_;
}
v_reusejp_799_:
{
return v___x_800_;
}
}
}
}
}
}
}
}
LEAN_EXPORT uint8_t l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0(lean_object* v_register_823_, lean_object* v_x_824_){
_start:
{
if (lean_obj_tag(v_x_824_) == 0)
{
uint8_t v___x_825_; 
v___x_825_ = 0;
return v___x_825_;
}
else
{
lean_object* v_head_826_; lean_object* v_tail_827_; lean_object* v_fst_828_; uint8_t v___x_829_; 
v_head_826_ = lean_ctor_get(v_x_824_, 0);
v_tail_827_ = lean_ctor_get(v_x_824_, 1);
v_fst_828_ = lean_ctor_get(v_head_826_, 0);
v___x_829_ = lean_nat_dec_eq(v_fst_828_, v_register_823_);
if (v___x_829_ == 0)
{
v_x_824_ = v_tail_827_;
goto _start;
}
else
{
return v___x_829_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0___boxed(lean_object* v_register_831_, lean_object* v_x_832_){
_start:
{
uint8_t v_res_833_; lean_object* v_r_834_; 
v_res_833_ = l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0(v_register_831_, v_x_832_);
lean_dec(v_x_832_);
lean_dec(v_register_831_);
v_r_834_ = lean_box(v_res_833_);
return v_r_834_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(lean_object* v_register_841_, lean_object* v_df_842_, lean_object* v_as_x27_843_, lean_object* v_b_844_){
_start:
{
if (lean_obj_tag(v_as_x27_843_) == 0)
{
lean_object* v___x_846_; 
lean_dec(v_df_842_);
lean_dec(v_register_841_);
v___x_846_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_846_, 0, v_b_844_);
return v___x_846_;
}
else
{
lean_object* v_head_847_; lean_object* v_tail_848_; uint8_t v___y_850_; uint8_t v___y_851_; uint8_t v___y_852_; uint8_t v___y_853_; uint8_t v___y_854_; uint8_t v___y_855_; uint8_t v___y_856_; lean_object* v_fields_886_; lean_object* v_body_887_; 
v_head_847_ = lean_ctor_get(v_as_x27_843_, 0);
v_tail_848_ = lean_ctor_get(v_as_x27_843_, 1);
v_fields_886_ = lean_ctor_get(v_head_847_, 0);
v_body_887_ = lean_ctor_get(v_fields_886_, 0);
if (lean_obj_tag(v_body_887_) == 6)
{
lean_object* v_decoded_888_; lean_object* v_mb_889_; uint8_t v___y_891_; uint8_t v___y_892_; uint8_t v___y_893_; uint8_t v___y_894_; uint8_t v___y_895_; uint8_t v___y_896_; uint8_t v___y_897_; uint8_t v___y_898_; uint8_t v___y_913_; uint8_t v___y_914_; uint8_t v___y_915_; uint8_t v___y_916_; uint8_t v___y_917_; uint8_t v___y_918_; uint8_t v___y_922_; uint8_t v___y_923_; uint8_t v___y_924_; lean_object* v___y_925_; uint8_t v___y_926_; uint8_t v___y_927_; uint8_t v___y_936_; lean_object* v___y_937_; uint8_t v___y_938_; uint8_t v___y_944_; lean_object* v___y_945_; uint8_t v___y_946_; lean_object* v___x_947_; uint8_t v___x_948_; 
v_decoded_888_ = lean_ctor_get(v_head_847_, 1);
v_mb_889_ = lean_ctor_get(v_body_887_, 1);
v___x_947_ = lean_unsigned_to_nat(0u);
v___x_948_ = lean_nat_dec_eq(v_mb_889_, v___x_947_);
if (v___x_948_ == 0)
{
uint8_t v___x_949_; lean_object* v___x_950_; uint8_t v___x_951_; 
v___x_949_ = 1;
v___x_950_ = lean_unsigned_to_nat(5u);
v___x_951_ = lean_nat_dec_eq(v_register_841_, v___x_950_);
if (v___x_951_ == 0)
{
lean_object* v___x_952_; uint8_t v___x_953_; 
v___x_952_ = lean_unsigned_to_nat(101u);
v___x_953_ = lean_nat_dec_eq(v_register_841_, v___x_952_);
if (v___x_953_ == 0)
{
v___y_936_ = v___x_949_;
v___y_937_ = v___x_950_;
v___y_938_ = v___x_949_;
goto v___jp_935_;
}
else
{
v___y_944_ = v___x_949_;
v___y_945_ = v___x_950_;
v___y_946_ = v___x_951_;
goto v___jp_943_;
}
}
else
{
lean_object* v___x_954_; uint8_t v___x_955_; 
v___x_954_ = lean_unsigned_to_nat(20u);
v___x_955_ = lean_nat_dec_eq(v_df_842_, v___x_954_);
if (v___x_955_ == 0)
{
v___y_944_ = v___x_949_;
v___y_945_ = v___x_950_;
v___y_946_ = v___x_955_;
goto v___jp_943_;
}
else
{
lean_object* v___x_956_; lean_object* v___x_957_; lean_object* v___x_958_; uint8_t v___x_959_; 
v___x_956_ = lean_unsigned_to_nat(1u);
v___x_957_ = lp_lean1090_Lean1090_Impl_payloadBits(v_mb_889_, v___x_956_, v___x_950_);
v___x_958_ = lean_unsigned_to_nat(9u);
v___x_959_ = lean_nat_dec_le(v___x_958_, v___x_957_);
if (v___x_959_ == 0)
{
lean_dec(v___x_957_);
v___y_944_ = v___x_949_;
v___y_945_ = v___x_950_;
v___y_946_ = v___x_959_;
goto v___jp_943_;
}
else
{
lean_object* v___x_960_; uint8_t v___x_961_; 
v___x_960_ = lean_unsigned_to_nat(22u);
v___x_961_ = lean_nat_dec_lt(v___x_957_, v___x_960_);
if (v___x_961_ == 0)
{
lean_dec(v___x_957_);
v___y_944_ = v___x_949_;
v___y_945_ = v___x_950_;
v___y_946_ = v___x_961_;
goto v___jp_943_;
}
else
{
lean_object* v___x_962_; uint8_t v___x_963_; 
v___x_962_ = lean_unsigned_to_nat(19u);
v___x_963_ = lean_nat_dec_eq(v___x_957_, v___x_962_);
lean_dec(v___x_957_);
if (v___x_963_ == 0)
{
v___y_944_ = v___x_949_;
v___y_945_ = v___x_950_;
v___y_946_ = v___x_951_;
goto v___jp_943_;
}
else
{
v___y_913_ = v___x_949_;
v___y_914_ = v___x_948_;
v___y_915_ = v___x_948_;
v___y_916_ = v___x_948_;
v___y_917_ = v___x_948_;
v___y_918_ = v___x_948_;
goto v___jp_912_;
}
}
}
}
}
}
else
{
uint8_t v___x_964_; 
v___x_964_ = 0;
v___y_913_ = v___x_964_;
v___y_914_ = v___x_964_;
v___y_915_ = v___x_964_;
v___y_916_ = v___x_964_;
v___y_917_ = v___x_964_;
v___y_918_ = v___x_964_;
goto v___jp_912_;
}
v___jp_890_:
{
if (v___y_898_ == 0)
{
lean_object* v___x_899_; lean_object* v___x_900_; lean_object* v___x_901_; lean_object* v___x_902_; lean_object* v___x_903_; lean_object* v___x_904_; lean_object* v___x_905_; lean_object* v___x_906_; lean_object* v___x_907_; lean_object* v___x_908_; lean_object* v___x_909_; lean_object* v___x_910_; lean_object* v___x_911_; 
lean_dec_ref(v_b_844_);
v___x_899_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__0));
v___x_900_ = l_Nat_reprFast(v_df_842_);
v___x_901_ = lean_string_append(v___x_899_, v___x_900_);
lean_dec_ref(v___x_900_);
v___x_902_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__1));
v___x_903_ = lean_string_append(v___x_901_, v___x_902_);
v___x_904_ = l_Nat_reprFast(v_register_841_);
v___x_905_ = lean_string_append(v___x_903_, v___x_904_);
lean_dec_ref(v___x_904_);
v___x_906_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__2));
v___x_907_ = lean_string_append(v___x_905_, v___x_906_);
lean_inc(v_mb_889_);
v___x_908_ = l_Nat_reprFast(v_mb_889_);
v___x_909_ = lean_string_append(v___x_907_, v___x_908_);
lean_dec_ref(v___x_908_);
v___x_910_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_910_, 0, v___x_909_);
v___x_911_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_911_, 0, v___x_910_);
return v___x_911_;
}
else
{
v___y_850_ = v___y_892_;
v___y_851_ = v___y_891_;
v___y_852_ = v___y_893_;
v___y_853_ = v___y_894_;
v___y_854_ = v___y_895_;
v___y_855_ = v___y_896_;
v___y_856_ = v___y_897_;
goto v___jp_849_;
}
}
v___jp_912_:
{
lean_object* v_commB_919_; uint8_t v___x_920_; 
v_commB_919_ = lean_ctor_get(v_decoded_888_, 6);
v___x_920_ = l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0(v_register_841_, v_commB_919_);
if (v___x_920_ == 0)
{
if (v___y_918_ == 0)
{
v___y_850_ = v___y_914_;
v___y_851_ = v___y_913_;
v___y_852_ = v___y_915_;
v___y_853_ = v___x_920_;
v___y_854_ = v___y_918_;
v___y_855_ = v___y_916_;
v___y_856_ = v___y_917_;
goto v___jp_849_;
}
else
{
v___y_891_ = v___y_913_;
v___y_892_ = v___y_914_;
v___y_893_ = v___y_915_;
v___y_894_ = v___x_920_;
v___y_895_ = v___y_918_;
v___y_896_ = v___y_916_;
v___y_897_ = v___y_917_;
v___y_898_ = v___x_920_;
goto v___jp_890_;
}
}
else
{
v___y_891_ = v___y_913_;
v___y_892_ = v___y_914_;
v___y_893_ = v___y_915_;
v___y_894_ = v___x_920_;
v___y_895_ = v___y_918_;
v___y_896_ = v___y_916_;
v___y_897_ = v___y_917_;
v___y_898_ = v___y_918_;
goto v___jp_890_;
}
}
v___jp_921_:
{
if (v___y_926_ == 0)
{
v___y_913_ = v___y_923_;
v___y_914_ = v___y_922_;
v___y_915_ = v___y_927_;
v___y_916_ = v___y_924_;
v___y_917_ = v___y_926_;
v___y_918_ = v___y_926_;
goto v___jp_912_;
}
else
{
uint8_t v___x_928_; 
v___x_928_ = lean_nat_dec_eq(v_register_841_, v___y_925_);
if (v___x_928_ == 0)
{
lean_object* v___x_929_; uint8_t v___x_930_; 
v___x_929_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored));
v___x_930_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_841_, v___x_929_);
if (v___x_930_ == 0)
{
v___y_913_ = v___y_923_;
v___y_914_ = v___y_922_;
v___y_915_ = v___y_927_;
v___y_916_ = v___y_924_;
v___y_917_ = v___y_926_;
v___y_918_ = v___y_926_;
goto v___jp_912_;
}
else
{
v___y_913_ = v___y_923_;
v___y_914_ = v___y_922_;
v___y_915_ = v___y_927_;
v___y_916_ = v___y_924_;
v___y_917_ = v___y_926_;
v___y_918_ = v___y_927_;
goto v___jp_912_;
}
}
else
{
lean_object* v___x_931_; lean_object* v___x_932_; lean_object* v___x_933_; uint8_t v___x_934_; 
v___x_931_ = lean_alloc_closure((void*)(l_Int_instDecidableEq___boxed), 2, 0);
v___x_932_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_mb_889_);
v___x_933_ = lp_lean1090_Lean1090_Impl_frameOracleAltitude(v_fields_886_);
v___x_934_ = l_Option_instDecidableEq___redArg(v___x_931_, v___x_932_, v___x_933_);
v___y_913_ = v___y_923_;
v___y_914_ = v___y_922_;
v___y_915_ = v___y_927_;
v___y_916_ = v___y_924_;
v___y_917_ = v___y_926_;
v___y_918_ = v___x_934_;
goto v___jp_912_;
}
}
}
v___jp_935_:
{
uint8_t v___x_939_; 
v___x_939_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_841_, v_mb_889_);
if (v___x_939_ == 0)
{
v___y_922_ = v___y_938_;
v___y_923_ = v___y_936_;
v___y_924_ = v___x_939_;
v___y_925_ = v___y_937_;
v___y_926_ = v___x_939_;
v___y_927_ = v___x_939_;
goto v___jp_921_;
}
else
{
lean_object* v___x_940_; uint8_t v___x_941_; 
v___x_940_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored));
v___x_941_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_841_, v___x_940_);
if (v___x_941_ == 0)
{
v___y_922_ = v___y_938_;
v___y_923_ = v___y_936_;
v___y_924_ = v___x_941_;
v___y_925_ = v___y_937_;
v___y_926_ = v___x_939_;
v___y_927_ = v___x_941_;
goto v___jp_921_;
}
else
{
uint8_t v___x_942_; 
v___x_942_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_841_, v_mb_889_);
v___y_922_ = v___y_938_;
v___y_923_ = v___y_936_;
v___y_924_ = v___x_941_;
v___y_925_ = v___y_937_;
v___y_926_ = v___x_939_;
v___y_927_ = v___x_942_;
goto v___jp_921_;
}
}
}
v___jp_943_:
{
if (v___y_946_ == 0)
{
v___y_913_ = v___y_944_;
v___y_914_ = v___y_946_;
v___y_915_ = v___y_946_;
v___y_916_ = v___y_946_;
v___y_917_ = v___y_946_;
v___y_918_ = v___y_946_;
goto v___jp_912_;
}
else
{
v___y_936_ = v___y_944_;
v___y_937_ = v___y_945_;
v___y_938_ = v___y_946_;
goto v___jp_935_;
}
}
}
else
{
lean_object* v___x_965_; lean_object* v___x_966_; 
lean_dec_ref(v_b_844_);
lean_dec(v_df_842_);
lean_dec(v_register_841_);
v___x_965_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__4));
v___x_966_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_966_, 0, v___x_965_);
return v___x_966_;
}
v___jp_849_:
{
lean_object* v_nonempty_857_; lean_object* v_hardAttempts_858_; lean_object* v_hardPass_859_; lean_object* v_scoreAttempts_860_; lean_object* v_scorePass_861_; lean_object* v_eligible_862_; lean_object* v_accepted_863_; lean_object* v___x_865_; uint8_t v_isShared_866_; uint8_t v_isSharedCheck_885_; 
v_nonempty_857_ = lean_ctor_get(v_b_844_, 0);
v_hardAttempts_858_ = lean_ctor_get(v_b_844_, 1);
v_hardPass_859_ = lean_ctor_get(v_b_844_, 2);
v_scoreAttempts_860_ = lean_ctor_get(v_b_844_, 3);
v_scorePass_861_ = lean_ctor_get(v_b_844_, 4);
v_eligible_862_ = lean_ctor_get(v_b_844_, 5);
v_accepted_863_ = lean_ctor_get(v_b_844_, 6);
v_isSharedCheck_885_ = !lean_is_exclusive(v_b_844_);
if (v_isSharedCheck_885_ == 0)
{
v___x_865_ = v_b_844_;
v_isShared_866_ = v_isSharedCheck_885_;
goto v_resetjp_864_;
}
else
{
lean_inc(v_accepted_863_);
lean_inc(v_eligible_862_);
lean_inc(v_scorePass_861_);
lean_inc(v_scoreAttempts_860_);
lean_inc(v_hardPass_859_);
lean_inc(v_hardAttempts_858_);
lean_inc(v_nonempty_857_);
lean_dec(v_b_844_);
v___x_865_ = lean_box(0);
v_isShared_866_ = v_isSharedCheck_885_;
goto v_resetjp_864_;
}
v_resetjp_864_:
{
lean_object* v___x_867_; lean_object* v___x_868_; lean_object* v___x_869_; lean_object* v___x_870_; lean_object* v___x_871_; lean_object* v___x_872_; lean_object* v___x_873_; lean_object* v___x_874_; lean_object* v___x_875_; lean_object* v___x_876_; lean_object* v___x_877_; lean_object* v___x_878_; lean_object* v___x_879_; lean_object* v___x_880_; lean_object* v___x_882_; 
v___x_867_ = l_Bool_toNat(v___y_851_);
v___x_868_ = lean_nat_add(v_nonempty_857_, v___x_867_);
lean_dec(v___x_867_);
lean_dec(v_nonempty_857_);
v___x_869_ = l_Bool_toNat(v___y_850_);
v___x_870_ = lean_nat_add(v_hardAttempts_858_, v___x_869_);
lean_dec(v___x_869_);
lean_dec(v_hardAttempts_858_);
v___x_871_ = l_Bool_toNat(v___y_856_);
v___x_872_ = lean_nat_add(v_hardPass_859_, v___x_871_);
lean_dec(v___x_871_);
lean_dec(v_hardPass_859_);
v___x_873_ = l_Bool_toNat(v___y_855_);
v___x_874_ = lean_nat_add(v_scoreAttempts_860_, v___x_873_);
lean_dec(v___x_873_);
lean_dec(v_scoreAttempts_860_);
v___x_875_ = l_Bool_toNat(v___y_852_);
v___x_876_ = lean_nat_add(v_scorePass_861_, v___x_875_);
lean_dec(v___x_875_);
lean_dec(v_scorePass_861_);
v___x_877_ = l_Bool_toNat(v___y_854_);
v___x_878_ = lean_nat_add(v_eligible_862_, v___x_877_);
lean_dec(v___x_877_);
lean_dec(v_eligible_862_);
v___x_879_ = l_Bool_toNat(v___y_853_);
v___x_880_ = lean_nat_add(v_accepted_863_, v___x_879_);
lean_dec(v___x_879_);
lean_dec(v_accepted_863_);
if (v_isShared_866_ == 0)
{
lean_ctor_set(v___x_865_, 6, v___x_880_);
lean_ctor_set(v___x_865_, 5, v___x_878_);
lean_ctor_set(v___x_865_, 4, v___x_876_);
lean_ctor_set(v___x_865_, 3, v___x_874_);
lean_ctor_set(v___x_865_, 2, v___x_872_);
lean_ctor_set(v___x_865_, 1, v___x_870_);
lean_ctor_set(v___x_865_, 0, v___x_868_);
v___x_882_ = v___x_865_;
goto v_reusejp_881_;
}
else
{
lean_object* v_reuseFailAlloc_884_; 
v_reuseFailAlloc_884_ = lean_alloc_ctor(0, 7, 0);
lean_ctor_set(v_reuseFailAlloc_884_, 0, v___x_868_);
lean_ctor_set(v_reuseFailAlloc_884_, 1, v___x_870_);
lean_ctor_set(v_reuseFailAlloc_884_, 2, v___x_872_);
lean_ctor_set(v_reuseFailAlloc_884_, 3, v___x_874_);
lean_ctor_set(v_reuseFailAlloc_884_, 4, v___x_876_);
lean_ctor_set(v_reuseFailAlloc_884_, 5, v___x_878_);
lean_ctor_set(v_reuseFailAlloc_884_, 6, v___x_880_);
v___x_882_ = v_reuseFailAlloc_884_;
goto v_reusejp_881_;
}
v_reusejp_881_:
{
v_as_x27_843_ = v_tail_848_;
v_b_844_ = v___x_882_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___boxed(lean_object* v_register_967_, lean_object* v_df_968_, lean_object* v_as_x27_969_, lean_object* v_b_970_, lean_object* v___y_971_){
_start:
{
lean_object* v_res_972_; 
v_res_972_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(v_register_967_, v_df_968_, v_as_x27_969_, v_b_970_);
lean_dec(v_as_x27_969_);
return v_res_972_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus(lean_object* v_df_975_, lean_object* v_register_976_, lean_object* v_messages_977_){
_start:
{
lean_object* v_count_979_; lean_object* v___x_980_; 
v_count_979_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus___closed__0));
v___x_980_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(v_register_976_, v_df_975_, v_messages_977_, v_count_979_);
return v___x_980_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus___boxed(lean_object* v_df_981_, lean_object* v_register_982_, lean_object* v_messages_983_, lean_object* v_a_984_){
_start:
{
lean_object* v_res_985_; 
v_res_985_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus(v_df_981_, v_register_982_, v_messages_983_);
lean_dec(v_messages_983_);
return v_res_985_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1(lean_object* v_register_986_, lean_object* v_df_987_, lean_object* v_as_988_, lean_object* v_as_x27_989_, lean_object* v_b_990_, lean_object* v_a_991_){
_start:
{
lean_object* v___x_993_; 
v___x_993_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(v_register_986_, v_df_987_, v_as_x27_989_, v_b_990_);
return v___x_993_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___boxed(lean_object* v_register_994_, lean_object* v_df_995_, lean_object* v_as_996_, lean_object* v_as_x27_997_, lean_object* v_b_998_, lean_object* v_a_999_, lean_object* v___y_1000_){
_start:
{
lean_object* v_res_1001_; 
v_res_1001_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1(v_register_994_, v_df_995_, v_as_996_, v_as_x27_997_, v_b_998_, v_a_999_);
lean_dec(v_as_x27_997_);
lean_dec(v_as_996_);
return v_res_1001_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(lean_object* v_a_1012_, lean_object* v_a_1013_, lean_object* v_as_x27_1014_, lean_object* v_b_1015_){
_start:
{
if (lean_obj_tag(v_as_x27_1014_) == 0)
{
lean_object* v___x_1017_; 
lean_dec(v_a_1012_);
v___x_1017_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1017_, 0, v_b_1015_);
return v___x_1017_;
}
else
{
lean_object* v_head_1018_; lean_object* v_tail_1019_; lean_object* v_rows_1020_; lean_object* v___x_1021_; 
v_head_1018_ = lean_ctor_get(v_as_x27_1014_, 0);
v_tail_1019_ = lean_ctor_get(v_as_x27_1014_, 1);
v_rows_1020_ = lean_box(0);
lean_inc(v_head_1018_);
lean_inc(v_a_1012_);
v___x_1021_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus(v_a_1012_, v_head_1018_, v_a_1013_);
if (lean_obj_tag(v___x_1021_) == 0)
{
lean_object* v_a_1022_; lean_object* v_nonempty_1023_; lean_object* v_hardAttempts_1024_; lean_object* v_hardPass_1025_; lean_object* v_scoreAttempts_1026_; lean_object* v_scorePass_1027_; lean_object* v_eligible_1028_; lean_object* v_accepted_1029_; lean_object* v___x_1030_; lean_object* v___x_1031_; lean_object* v___x_1032_; lean_object* v___x_1033_; lean_object* v___x_1034_; lean_object* v___x_1035_; lean_object* v___x_1036_; lean_object* v___x_1037_; lean_object* v___x_1038_; lean_object* v___x_1039_; lean_object* v___x_1040_; lean_object* v___x_1041_; lean_object* v___x_1042_; lean_object* v___x_1043_; lean_object* v___x_1044_; lean_object* v___x_1045_; lean_object* v___x_1046_; lean_object* v___x_1047_; lean_object* v___x_1048_; lean_object* v___x_1049_; lean_object* v___x_1050_; lean_object* v___x_1051_; lean_object* v___x_1052_; lean_object* v___x_1053_; lean_object* v___x_1054_; lean_object* v___x_1055_; lean_object* v___x_1056_; lean_object* v___x_1057_; lean_object* v___x_1058_; lean_object* v___x_1059_; lean_object* v___x_1060_; lean_object* v___x_1061_; lean_object* v___x_1062_; lean_object* v___x_1063_; lean_object* v___x_1064_; lean_object* v___x_1065_; lean_object* v___x_1066_; lean_object* v___x_1067_; lean_object* v___x_1068_; lean_object* v___x_1069_; lean_object* v___x_1070_; lean_object* v___x_1071_; lean_object* v___x_1072_; lean_object* v___x_1073_; lean_object* v___x_1074_; lean_object* v___x_1075_; lean_object* v___x_1076_; lean_object* v___x_1077_; lean_object* v___x_1078_; lean_object* v___x_1079_; lean_object* v___x_1080_; lean_object* v___x_1081_; 
v_a_1022_ = lean_ctor_get(v___x_1021_, 0);
lean_inc(v_a_1022_);
lean_dec_ref_known(v___x_1021_, 1);
v_nonempty_1023_ = lean_ctor_get(v_a_1022_, 0);
lean_inc(v_nonempty_1023_);
v_hardAttempts_1024_ = lean_ctor_get(v_a_1022_, 1);
lean_inc(v_hardAttempts_1024_);
v_hardPass_1025_ = lean_ctor_get(v_a_1022_, 2);
lean_inc(v_hardPass_1025_);
v_scoreAttempts_1026_ = lean_ctor_get(v_a_1022_, 3);
lean_inc(v_scoreAttempts_1026_);
v_scorePass_1027_ = lean_ctor_get(v_a_1022_, 4);
lean_inc(v_scorePass_1027_);
v_eligible_1028_ = lean_ctor_get(v_a_1022_, 5);
lean_inc(v_eligible_1028_);
v_accepted_1029_ = lean_ctor_get(v_a_1022_, 6);
lean_inc(v_accepted_1029_);
lean_dec(v_a_1022_);
v___x_1030_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__0));
lean_inc(v_head_1018_);
v___x_1031_ = l_Lean_JsonNumber_fromNat(v_head_1018_);
v___x_1032_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1032_, 0, v___x_1031_);
v___x_1033_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1033_, 0, v___x_1030_);
lean_ctor_set(v___x_1033_, 1, v___x_1032_);
v___x_1034_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__1));
v___x_1035_ = l_List_lengthTR___redArg(v_a_1013_);
v___x_1036_ = l_Lean_JsonNumber_fromNat(v___x_1035_);
v___x_1037_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1037_, 0, v___x_1036_);
v___x_1038_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1038_, 0, v___x_1034_);
lean_ctor_set(v___x_1038_, 1, v___x_1037_);
v___x_1039_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__2));
v___x_1040_ = l_Lean_JsonNumber_fromNat(v_nonempty_1023_);
v___x_1041_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1041_, 0, v___x_1040_);
v___x_1042_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1042_, 0, v___x_1039_);
lean_ctor_set(v___x_1042_, 1, v___x_1041_);
v___x_1043_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__3));
v___x_1044_ = l_Lean_JsonNumber_fromNat(v_hardAttempts_1024_);
v___x_1045_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1045_, 0, v___x_1044_);
v___x_1046_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1046_, 0, v___x_1043_);
lean_ctor_set(v___x_1046_, 1, v___x_1045_);
v___x_1047_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__4));
v___x_1048_ = l_Lean_JsonNumber_fromNat(v_hardPass_1025_);
v___x_1049_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1049_, 0, v___x_1048_);
v___x_1050_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1050_, 0, v___x_1047_);
lean_ctor_set(v___x_1050_, 1, v___x_1049_);
v___x_1051_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__5));
v___x_1052_ = l_Lean_JsonNumber_fromNat(v_scoreAttempts_1026_);
v___x_1053_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1053_, 0, v___x_1052_);
v___x_1054_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1054_, 0, v___x_1051_);
lean_ctor_set(v___x_1054_, 1, v___x_1053_);
v___x_1055_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__6));
v___x_1056_ = l_Lean_JsonNumber_fromNat(v_scorePass_1027_);
v___x_1057_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1057_, 0, v___x_1056_);
v___x_1058_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1058_, 0, v___x_1055_);
lean_ctor_set(v___x_1058_, 1, v___x_1057_);
v___x_1059_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__7));
v___x_1060_ = l_Lean_JsonNumber_fromNat(v_eligible_1028_);
v___x_1061_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1061_, 0, v___x_1060_);
v___x_1062_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1062_, 0, v___x_1059_);
lean_ctor_set(v___x_1062_, 1, v___x_1061_);
v___x_1063_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__8));
v___x_1064_ = l_Lean_JsonNumber_fromNat(v_accepted_1029_);
v___x_1065_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1065_, 0, v___x_1064_);
lean_inc_ref(v___x_1065_);
v___x_1066_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1066_, 0, v___x_1063_);
lean_ctor_set(v___x_1066_, 1, v___x_1065_);
v___x_1067_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__9));
v___x_1068_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1068_, 0, v___x_1067_);
lean_ctor_set(v___x_1068_, 1, v___x_1065_);
v___x_1069_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1069_, 0, v___x_1068_);
lean_ctor_set(v___x_1069_, 1, v_rows_1020_);
v___x_1070_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1070_, 0, v___x_1066_);
lean_ctor_set(v___x_1070_, 1, v___x_1069_);
v___x_1071_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1071_, 0, v___x_1062_);
lean_ctor_set(v___x_1071_, 1, v___x_1070_);
v___x_1072_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1072_, 0, v___x_1058_);
lean_ctor_set(v___x_1072_, 1, v___x_1071_);
v___x_1073_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1073_, 0, v___x_1054_);
lean_ctor_set(v___x_1073_, 1, v___x_1072_);
v___x_1074_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1074_, 0, v___x_1050_);
lean_ctor_set(v___x_1074_, 1, v___x_1073_);
v___x_1075_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1075_, 0, v___x_1046_);
lean_ctor_set(v___x_1075_, 1, v___x_1074_);
v___x_1076_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1076_, 0, v___x_1042_);
lean_ctor_set(v___x_1076_, 1, v___x_1075_);
v___x_1077_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1077_, 0, v___x_1038_);
lean_ctor_set(v___x_1077_, 1, v___x_1076_);
v___x_1078_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1078_, 0, v___x_1033_);
lean_ctor_set(v___x_1078_, 1, v___x_1077_);
v___x_1079_ = l_Lean_Json_mkObj(v___x_1078_);
lean_dec_ref_known(v___x_1078_, 2);
v___x_1080_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1080_, 0, v___x_1079_);
lean_ctor_set(v___x_1080_, 1, v_rows_1020_);
v___x_1081_ = l_List_appendTR___redArg(v_b_1015_, v___x_1080_);
v_as_x27_1014_ = v_tail_1019_;
v_b_1015_ = v___x_1081_;
goto _start;
}
else
{
lean_object* v_a_1083_; lean_object* v___x_1085_; uint8_t v_isShared_1086_; uint8_t v_isSharedCheck_1090_; 
lean_dec(v_b_1015_);
lean_dec(v_a_1012_);
v_a_1083_ = lean_ctor_get(v___x_1021_, 0);
v_isSharedCheck_1090_ = !lean_is_exclusive(v___x_1021_);
if (v_isSharedCheck_1090_ == 0)
{
v___x_1085_ = v___x_1021_;
v_isShared_1086_ = v_isSharedCheck_1090_;
goto v_resetjp_1084_;
}
else
{
lean_inc(v_a_1083_);
lean_dec(v___x_1021_);
v___x_1085_ = lean_box(0);
v_isShared_1086_ = v_isSharedCheck_1090_;
goto v_resetjp_1084_;
}
v_resetjp_1084_:
{
lean_object* v___x_1088_; 
if (v_isShared_1086_ == 0)
{
v___x_1088_ = v___x_1085_;
goto v_reusejp_1087_;
}
else
{
lean_object* v_reuseFailAlloc_1089_; 
v_reuseFailAlloc_1089_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1089_, 0, v_a_1083_);
v___x_1088_ = v_reuseFailAlloc_1089_;
goto v_reusejp_1087_;
}
v_reusejp_1087_:
{
return v___x_1088_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___boxed(lean_object* v_a_1091_, lean_object* v_a_1092_, lean_object* v_as_x27_1093_, lean_object* v_b_1094_, lean_object* v___y_1095_){
_start:
{
lean_object* v_res_1096_; 
v_res_1096_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(v_a_1091_, v_a_1092_, v_as_x27_1093_, v_b_1094_);
lean_dec(v_as_x27_1093_);
lean_dec(v_a_1092_);
return v_res_1096_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(lean_object* v_inputs_1100_, lean_object* v_a_1101_, lean_object* v_output_1102_, lean_object* v_range_1103_, lean_object* v_b_1104_, lean_object* v_i_1105_){
_start:
{
lean_object* v_stop_1107_; lean_object* v_step_1108_; lean_object* v_a_1110_; uint8_t v___x_1113_; 
v_stop_1107_ = lean_ctor_get(v_range_1103_, 1);
v_step_1108_ = lean_ctor_get(v_range_1103_, 2);
v___x_1113_ = lean_nat_dec_lt(v_i_1105_, v_stop_1107_);
if (v___x_1113_ == 0)
{
lean_object* v___x_1114_; 
lean_dec(v_i_1105_);
v___x_1114_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1114_, 0, v_b_1104_);
return v___x_1114_;
}
else
{
lean_object* v___x_1115_; uint8_t v___x_1116_; 
v___x_1115_ = lean_array_get_size(v_inputs_1100_);
v___x_1116_ = lean_nat_dec_lt(v_i_1105_, v___x_1115_);
if (v___x_1116_ == 0)
{
lean_object* v___x_1117_; lean_object* v___x_1118_; 
lean_dec(v_i_1105_);
lean_dec(v_b_1104_);
v___x_1117_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___closed__1));
v___x_1118_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1118_, 0, v___x_1117_);
return v___x_1118_;
}
else
{
lean_object* v___x_1119_; lean_object* v_df_1120_; lean_object* v___x_1122_; uint8_t v_isShared_1123_; uint8_t v_isSharedCheck_1129_; 
v___x_1119_ = lean_array_fget(v_inputs_1100_, v_i_1105_);
v_df_1120_ = lean_ctor_get(v___x_1119_, 0);
v_isSharedCheck_1129_ = !lean_is_exclusive(v___x_1119_);
if (v_isSharedCheck_1129_ == 0)
{
lean_object* v_unused_1130_; 
v_unused_1130_ = lean_ctor_get(v___x_1119_, 1);
lean_dec(v_unused_1130_);
v___x_1122_ = v___x_1119_;
v_isShared_1123_ = v_isSharedCheck_1129_;
goto v_resetjp_1121_;
}
else
{
lean_inc(v_df_1120_);
lean_dec(v___x_1119_);
v___x_1122_ = lean_box(0);
v_isShared_1123_ = v_isSharedCheck_1129_;
goto v_resetjp_1121_;
}
v_resetjp_1121_:
{
uint8_t v___x_1124_; 
v___x_1124_ = lean_nat_dec_eq(v_df_1120_, v_a_1101_);
lean_dec(v_df_1120_);
if (v___x_1124_ == 0)
{
lean_del_object(v___x_1122_);
v_a_1110_ = v_b_1104_;
goto v___jp_1109_;
}
else
{
lean_object* v___x_1125_; lean_object* v___x_1127_; 
v___x_1125_ = lean_array_fget_borrowed(v_output_1102_, v_i_1105_);
lean_inc(v___x_1125_);
if (v_isShared_1123_ == 0)
{
lean_ctor_set_tag(v___x_1122_, 1);
lean_ctor_set(v___x_1122_, 1, v_b_1104_);
lean_ctor_set(v___x_1122_, 0, v___x_1125_);
v___x_1127_ = v___x_1122_;
goto v_reusejp_1126_;
}
else
{
lean_object* v_reuseFailAlloc_1128_; 
v_reuseFailAlloc_1128_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1128_, 0, v___x_1125_);
lean_ctor_set(v_reuseFailAlloc_1128_, 1, v_b_1104_);
v___x_1127_ = v_reuseFailAlloc_1128_;
goto v_reusejp_1126_;
}
v_reusejp_1126_:
{
v_a_1110_ = v___x_1127_;
goto v___jp_1109_;
}
}
}
}
}
v___jp_1109_:
{
lean_object* v___x_1111_; 
v___x_1111_ = lean_nat_add(v_i_1105_, v_step_1108_);
lean_dec(v_i_1105_);
v_b_1104_ = v_a_1110_;
v_i_1105_ = v___x_1111_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___boxed(lean_object* v_inputs_1131_, lean_object* v_a_1132_, lean_object* v_output_1133_, lean_object* v_range_1134_, lean_object* v_b_1135_, lean_object* v_i_1136_, lean_object* v___y_1137_){
_start:
{
lean_object* v_res_1138_; 
v_res_1138_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(v_inputs_1131_, v_a_1132_, v_output_1133_, v_range_1134_, v_b_1135_, v_i_1136_);
lean_dec_ref(v_range_1134_);
lean_dec_ref(v_output_1133_);
lean_dec(v_a_1132_);
lean_dec_ref(v_inputs_1131_);
return v_res_1138_;
}
}
LEAN_EXPORT uint8_t l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___lam__0(lean_object* v_a_1139_, lean_object* v_b_1140_){
_start:
{
lean_object* v_fst_1141_; lean_object* v_fst_1142_; uint8_t v___x_1143_; 
v_fst_1141_ = lean_ctor_get(v_a_1139_, 0);
v_fst_1142_ = lean_ctor_get(v_b_1140_, 0);
v___x_1143_ = lean_nat_dec_le(v_fst_1141_, v_fst_1142_);
return v___x_1143_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___lam__0___boxed(lean_object* v_a_1144_, lean_object* v_b_1145_){
_start:
{
uint8_t v_res_1146_; lean_object* v_r_1147_; 
v_res_1146_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___lam__0(v_a_1144_, v_b_1145_);
lean_dec_ref(v_b_1145_);
lean_dec_ref(v_a_1144_);
v_r_1147_ = lean_box(v_res_1146_);
return v_r_1147_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3(lean_object* v_a_1149_, lean_object* v_a_1150_){
_start:
{
if (lean_obj_tag(v_a_1149_) == 0)
{
lean_object* v___x_1151_; 
v___x_1151_ = l_List_reverse___redArg(v_a_1150_);
return v___x_1151_;
}
else
{
lean_object* v_head_1152_; lean_object* v_tail_1153_; lean_object* v___x_1155_; uint8_t v_isShared_1156_; uint8_t v_isSharedCheck_1181_; 
v_head_1152_ = lean_ctor_get(v_a_1149_, 0);
v_tail_1153_ = lean_ctor_get(v_a_1149_, 1);
v_isSharedCheck_1181_ = !lean_is_exclusive(v_a_1149_);
if (v_isSharedCheck_1181_ == 0)
{
v___x_1155_ = v_a_1149_;
v_isShared_1156_ = v_isSharedCheck_1181_;
goto v_resetjp_1154_;
}
else
{
lean_inc(v_tail_1153_);
lean_inc(v_head_1152_);
lean_dec(v_a_1149_);
v___x_1155_ = lean_box(0);
v_isShared_1156_ = v_isSharedCheck_1181_;
goto v_resetjp_1154_;
}
v_resetjp_1154_:
{
lean_object* v_fst_1157_; lean_object* v_snd_1158_; lean_object* v___x_1160_; uint8_t v_isShared_1161_; uint8_t v_isSharedCheck_1180_; 
v_fst_1157_ = lean_ctor_get(v_head_1152_, 0);
v_snd_1158_ = lean_ctor_get(v_head_1152_, 1);
v_isSharedCheck_1180_ = !lean_is_exclusive(v_head_1152_);
if (v_isSharedCheck_1180_ == 0)
{
v___x_1160_ = v_head_1152_;
v_isShared_1161_ = v_isSharedCheck_1180_;
goto v_resetjp_1159_;
}
else
{
lean_inc(v_snd_1158_);
lean_inc(v_fst_1157_);
lean_dec(v_head_1152_);
v___x_1160_ = lean_box(0);
v_isShared_1161_ = v_isSharedCheck_1180_;
goto v_resetjp_1159_;
}
v_resetjp_1159_:
{
lean_object* v___x_1162_; lean_object* v___x_1163_; lean_object* v___x_1164_; lean_object* v___x_1165_; lean_object* v___x_1167_; 
v___x_1162_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0));
v___x_1163_ = ((lean_object*)(l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3___closed__0));
v___x_1164_ = l_Lean_JsonNumber_fromNat(v_fst_1157_);
v___x_1165_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1165_, 0, v___x_1164_);
if (v_isShared_1161_ == 0)
{
lean_ctor_set(v___x_1160_, 1, v___x_1165_);
lean_ctor_set(v___x_1160_, 0, v___x_1163_);
v___x_1167_ = v___x_1160_;
goto v_reusejp_1166_;
}
else
{
lean_object* v_reuseFailAlloc_1179_; 
v_reuseFailAlloc_1179_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1179_, 0, v___x_1163_);
lean_ctor_set(v_reuseFailAlloc_1179_, 1, v___x_1165_);
v___x_1167_ = v_reuseFailAlloc_1179_;
goto v_reusejp_1166_;
}
v_reusejp_1166_:
{
lean_object* v___x_1168_; lean_object* v___x_1169_; lean_object* v___x_1170_; lean_object* v___x_1171_; lean_object* v___x_1173_; 
v___x_1168_ = l_Lean_JsonNumber_fromNat(v_snd_1158_);
v___x_1169_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1169_, 0, v___x_1168_);
v___x_1170_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1170_, 0, v___x_1162_);
lean_ctor_set(v___x_1170_, 1, v___x_1169_);
v___x_1171_ = lean_box(0);
if (v_isShared_1156_ == 0)
{
lean_ctor_set(v___x_1155_, 1, v___x_1171_);
lean_ctor_set(v___x_1155_, 0, v___x_1170_);
v___x_1173_ = v___x_1155_;
goto v_reusejp_1172_;
}
else
{
lean_object* v_reuseFailAlloc_1178_; 
v_reuseFailAlloc_1178_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1178_, 0, v___x_1170_);
lean_ctor_set(v_reuseFailAlloc_1178_, 1, v___x_1171_);
v___x_1173_ = v_reuseFailAlloc_1178_;
goto v_reusejp_1172_;
}
v_reusejp_1172_:
{
lean_object* v___x_1174_; lean_object* v___x_1175_; lean_object* v___x_1176_; 
v___x_1174_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1174_, 0, v___x_1167_);
lean_ctor_set(v___x_1174_, 1, v___x_1173_);
v___x_1175_ = l_Lean_Json_mkObj(v___x_1174_);
lean_dec_ref_known(v___x_1174_, 2);
v___x_1176_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1176_, 0, v___x_1175_);
lean_ctor_set(v___x_1176_, 1, v_a_1150_);
v_a_1149_ = v_tail_1153_;
v_a_1150_ = v___x_1176_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__2(lean_object* v_a_1182_, lean_object* v_a_1183_){
_start:
{
if (lean_obj_tag(v_a_1182_) == 0)
{
lean_object* v___x_1184_; 
v___x_1184_ = l_List_reverse___redArg(v_a_1183_);
return v___x_1184_;
}
else
{
lean_object* v_head_1185_; lean_object* v_tail_1186_; lean_object* v___x_1188_; uint8_t v_isShared_1189_; uint8_t v_isSharedCheck_1195_; 
v_head_1185_ = lean_ctor_get(v_a_1182_, 0);
v_tail_1186_ = lean_ctor_get(v_a_1182_, 1);
v_isSharedCheck_1195_ = !lean_is_exclusive(v_a_1182_);
if (v_isSharedCheck_1195_ == 0)
{
v___x_1188_ = v_a_1182_;
v_isShared_1189_ = v_isSharedCheck_1195_;
goto v_resetjp_1187_;
}
else
{
lean_inc(v_tail_1186_);
lean_inc(v_head_1185_);
lean_dec(v_a_1182_);
v___x_1188_ = lean_box(0);
v_isShared_1189_ = v_isSharedCheck_1195_;
goto v_resetjp_1187_;
}
v_resetjp_1187_:
{
lean_object* v_snd_1190_; lean_object* v___x_1192_; 
v_snd_1190_ = lean_ctor_get(v_head_1185_, 1);
lean_inc(v_snd_1190_);
lean_dec(v_head_1185_);
if (v_isShared_1189_ == 0)
{
lean_ctor_set(v___x_1188_, 1, v_a_1183_);
lean_ctor_set(v___x_1188_, 0, v_snd_1190_);
v___x_1192_ = v___x_1188_;
goto v_reusejp_1191_;
}
else
{
lean_object* v_reuseFailAlloc_1194_; 
v_reuseFailAlloc_1194_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1194_, 0, v_snd_1190_);
lean_ctor_set(v_reuseFailAlloc_1194_, 1, v_a_1183_);
v___x_1192_ = v_reuseFailAlloc_1194_;
goto v_reusejp_1191_;
}
v_reusejp_1191_:
{
v_a_1182_ = v_tail_1186_;
v_a_1183_ = v___x_1192_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(lean_object* v_as_x27_1196_, lean_object* v_b_1197_){
_start:
{
if (lean_obj_tag(v_as_x27_1196_) == 0)
{
lean_object* v___x_1199_; 
v___x_1199_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1199_, 0, v_b_1197_);
return v___x_1199_;
}
else
{
lean_object* v_head_1200_; lean_object* v_decoded_1201_; lean_object* v_adsb_1202_; 
v_head_1200_ = lean_ctor_get(v_as_x27_1196_, 0);
v_decoded_1201_ = lean_ctor_get(v_head_1200_, 1);
v_adsb_1202_ = lean_ctor_get(v_decoded_1201_, 5);
if (lean_obj_tag(v_adsb_1202_) == 1)
{
lean_object* v_val_1203_; lean_object* v_tail_1204_; lean_object* v_kind_1205_; lean_object* v___x_1206_; 
v_val_1203_ = lean_ctor_get(v_adsb_1202_, 0);
v_tail_1204_ = lean_ctor_get(v_as_x27_1196_, 1);
v_kind_1205_ = lean_ctor_get(v_val_1203_, 0);
lean_inc(v_kind_1205_);
v___x_1206_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_bump(v_b_1197_, v_kind_1205_);
v_as_x27_1196_ = v_tail_1204_;
v_b_1197_ = v___x_1206_;
goto _start;
}
else
{
lean_object* v_tail_1208_; 
v_tail_1208_ = lean_ctor_get(v_as_x27_1196_, 1);
v_as_x27_1196_ = v_tail_1208_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg___boxed(lean_object* v_as_x27_1210_, lean_object* v_b_1211_, lean_object* v___y_1212_){
_start:
{
lean_object* v_res_1213_; 
v_res_1213_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(v_as_x27_1210_, v_b_1211_);
lean_dec(v_as_x27_1210_);
return v_res_1213_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5(size_t v_sz_1214_, size_t v_i_1215_, lean_object* v_bs_1216_){
_start:
{
uint8_t v___x_1217_; 
v___x_1217_ = lean_usize_dec_lt(v_i_1215_, v_sz_1214_);
if (v___x_1217_ == 0)
{
return v_bs_1216_;
}
else
{
lean_object* v_v_1218_; lean_object* v___x_1219_; lean_object* v_bs_x27_1220_; size_t v___x_1221_; size_t v___x_1222_; lean_object* v___x_1223_; 
v_v_1218_ = lean_array_uget(v_bs_1216_, v_i_1215_);
v___x_1219_ = lean_unsigned_to_nat(0u);
v_bs_x27_1220_ = lean_array_uset(v_bs_1216_, v_i_1215_, v___x_1219_);
v___x_1221_ = ((size_t)1ULL);
v___x_1222_ = lean_usize_add(v_i_1215_, v___x_1221_);
v___x_1223_ = lean_array_uset(v_bs_x27_1220_, v_i_1215_, v_v_1218_);
v_i_1215_ = v___x_1222_;
v_bs_1216_ = v___x_1223_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5___boxed(lean_object* v_sz_1225_, lean_object* v_i_1226_, lean_object* v_bs_1227_){
_start:
{
size_t v_sz_boxed_1228_; size_t v_i_boxed_1229_; lean_object* v_res_1230_; 
v_sz_boxed_1228_ = lean_unbox_usize(v_sz_1225_);
lean_dec(v_sz_1225_);
v_i_boxed_1229_ = lean_unbox_usize(v_i_1226_);
lean_dec(v_i_1226_);
v_res_1230_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5(v_sz_boxed_1228_, v_i_boxed_1229_, v_bs_1227_);
return v_res_1230_;
}
}
LEAN_EXPORT lean_object* l_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4(lean_object* v_a_1231_){
_start:
{
size_t v_sz_1232_; size_t v___x_1233_; lean_object* v___x_1234_; lean_object* v___x_1235_; 
v_sz_1232_ = lean_array_size(v_a_1231_);
v___x_1233_ = ((size_t)0ULL);
v___x_1234_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5(v_sz_1232_, v___x_1233_, v_a_1231_);
v___x_1235_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_1235_, 0, v___x_1234_);
return v___x_1235_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(lean_object* v_a_1236_){
_start:
{
lean_object* v___x_1237_; lean_object* v___x_1238_; 
v___x_1237_ = lean_array_mk(v_a_1236_);
v___x_1238_ = l_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4(v___x_1237_);
return v___x_1238_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(lean_object* v_output_1290_, lean_object* v_inputs_1291_, lean_object* v_as_x27_1292_, lean_object* v_b_1293_){
_start:
{
if (lean_obj_tag(v_as_x27_1292_) == 0)
{
lean_object* v___x_1295_; 
v___x_1295_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1295_, 0, v_b_1293_);
return v___x_1295_;
}
else
{
lean_object* v_head_1296_; lean_object* v_tail_1297_; lean_object* v___f_1298_; lean_object* v_rows_1299_; lean_object* v___x_1300_; lean_object* v___x_1301_; lean_object* v___x_1302_; lean_object* v___x_1303_; lean_object* v___x_1304_; 
v_head_1296_ = lean_ctor_get(v_as_x27_1292_, 0);
v_tail_1297_ = lean_ctor_get(v_as_x27_1292_, 1);
v___f_1298_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__0));
v_rows_1299_ = lean_box(0);
v___x_1300_ = lean_unsigned_to_nat(0u);
v___x_1301_ = lean_array_get_size(v_output_1290_);
v___x_1302_ = lean_unsigned_to_nat(1u);
v___x_1303_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1303_, 0, v___x_1300_);
lean_ctor_set(v___x_1303_, 1, v___x_1301_);
lean_ctor_set(v___x_1303_, 2, v___x_1302_);
v___x_1304_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(v_inputs_1291_, v_head_1296_, v_output_1290_, v___x_1303_, v_rows_1299_, v___x_1300_);
lean_dec_ref_known(v___x_1303_, 3);
if (lean_obj_tag(v___x_1304_) == 0)
{
lean_object* v_a_1305_; lean_object* v___x_1306_; lean_object* v_a_1307_; lean_object* v___x_1309_; uint8_t v_isShared_1310_; uint8_t v_isSharedCheck_1401_; 
v_a_1305_ = lean_ctor_get(v___x_1304_, 0);
lean_inc(v_a_1305_);
lean_dec_ref_known(v___x_1304_, 1);
v___x_1306_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(v_a_1305_, v_rows_1299_);
v_a_1307_ = lean_ctor_get(v___x_1306_, 0);
v_isSharedCheck_1401_ = !lean_is_exclusive(v___x_1306_);
if (v_isSharedCheck_1401_ == 0)
{
v___x_1309_ = v___x_1306_;
v_isShared_1310_ = v_isSharedCheck_1401_;
goto v_resetjp_1308_;
}
else
{
lean_inc(v_a_1307_);
lean_dec(v___x_1306_);
v___x_1309_ = lean_box(0);
v_isShared_1310_ = v_isSharedCheck_1401_;
goto v_resetjp_1308_;
}
v_resetjp_1308_:
{
lean_object* v___y_1312_; lean_object* v___y_1313_; lean_object* v___y_1314_; lean_object* v___y_1315_; lean_object* v___y_1316_; lean_object* v___y_1317_; lean_object* v___y_1318_; lean_object* v___y_1319_; lean_object* v___y_1352_; lean_object* v___y_1353_; lean_object* v___y_1354_; lean_object* v___y_1355_; lean_object* v___y_1356_; lean_object* v___y_1357_; lean_object* v___y_1358_; lean_object* v___y_1359_; lean_object* v___y_1363_; lean_object* v___y_1364_; lean_object* v___y_1365_; lean_object* v___y_1366_; lean_object* v_registers_1388_; lean_object* v___x_1397_; uint8_t v___x_1398_; 
v___x_1397_ = lean_unsigned_to_nat(20u);
v___x_1398_ = lean_nat_dec_eq(v_head_1296_, v___x_1397_);
if (v___x_1398_ == 0)
{
lean_object* v___x_1399_; uint8_t v___x_1400_; 
v___x_1399_ = lean_unsigned_to_nat(21u);
v___x_1400_ = lean_nat_dec_eq(v_head_1296_, v___x_1399_);
if (v___x_1400_ == 0)
{
v_registers_1388_ = v_rows_1299_;
goto v___jp_1387_;
}
else
{
goto v___jp_1393_;
}
}
else
{
goto v___jp_1393_;
}
v___jp_1311_:
{
lean_object* v___x_1320_; lean_object* v___x_1322_; 
v___x_1320_ = l_Lean_JsonNumber_fromNat(v___y_1319_);
if (v_isShared_1310_ == 0)
{
lean_ctor_set_tag(v___x_1309_, 2);
lean_ctor_set(v___x_1309_, 0, v___x_1320_);
v___x_1322_ = v___x_1309_;
goto v_reusejp_1321_;
}
else
{
lean_object* v_reuseFailAlloc_1350_; 
v_reuseFailAlloc_1350_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1350_, 0, v___x_1320_);
v___x_1322_ = v_reuseFailAlloc_1350_;
goto v_reusejp_1321_;
}
v_reusejp_1321_:
{
lean_object* v___x_1323_; lean_object* v___x_1324_; lean_object* v___x_1325_; lean_object* v___x_1326_; lean_object* v___x_1327_; lean_object* v___x_1328_; lean_object* v___x_1329_; lean_object* v___x_1330_; lean_object* v___x_1331_; lean_object* v___x_1332_; lean_object* v___x_1333_; lean_object* v___x_1334_; lean_object* v___x_1335_; lean_object* v___x_1336_; lean_object* v___x_1337_; lean_object* v___x_1338_; lean_object* v___x_1339_; lean_object* v___x_1340_; lean_object* v___x_1341_; lean_object* v___x_1342_; lean_object* v___x_1343_; lean_object* v___x_1344_; lean_object* v___x_1345_; lean_object* v___x_1346_; lean_object* v___x_1347_; lean_object* v___x_1348_; 
lean_inc_ref(v___y_1313_);
v___x_1323_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1323_, 0, v___y_1313_);
lean_ctor_set(v___x_1323_, 1, v___x_1322_);
v___x_1324_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__1));
lean_inc(v_a_1307_);
v___x_1325_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__2(v_a_1307_, v___y_1317_);
v___x_1326_ = l_List_sum___at___00Lean_PersistentHashMap_subarrayMeasure_spec__2(v___x_1325_);
lean_dec(v___x_1325_);
v___x_1327_ = l_Lean_JsonNumber_fromNat(v___x_1326_);
v___x_1328_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1328_, 0, v___x_1327_);
v___x_1329_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1329_, 0, v___x_1324_);
lean_ctor_set(v___x_1329_, 1, v___x_1328_);
v___x_1330_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__2));
v___x_1331_ = l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(v_a_1307_, v___f_1298_);
v___x_1332_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3(v___x_1331_, v_rows_1299_);
v___x_1333_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___x_1332_);
v___x_1334_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1334_, 0, v___x_1330_);
lean_ctor_set(v___x_1334_, 1, v___x_1333_);
v___x_1335_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__4));
v___x_1336_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___y_1318_);
v___x_1337_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1337_, 0, v___x_1335_);
lean_ctor_set(v___x_1337_, 1, v___x_1336_);
v___x_1338_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1338_, 0, v___x_1337_);
lean_ctor_set(v___x_1338_, 1, v_rows_1299_);
v___x_1339_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1339_, 0, v___x_1334_);
lean_ctor_set(v___x_1339_, 1, v___x_1338_);
v___x_1340_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1340_, 0, v___x_1329_);
lean_ctor_set(v___x_1340_, 1, v___x_1339_);
v___x_1341_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1341_, 0, v___x_1323_);
lean_ctor_set(v___x_1341_, 1, v___x_1340_);
v___x_1342_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1342_, 0, v___y_1312_);
lean_ctor_set(v___x_1342_, 1, v___x_1341_);
v___x_1343_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1343_, 0, v___y_1314_);
lean_ctor_set(v___x_1343_, 1, v___x_1342_);
v___x_1344_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1344_, 0, v___y_1315_);
lean_ctor_set(v___x_1344_, 1, v___x_1343_);
v___x_1345_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1345_, 0, v___y_1316_);
lean_ctor_set(v___x_1345_, 1, v___x_1344_);
v___x_1346_ = l_Lean_Json_mkObj(v___x_1345_);
lean_dec_ref_known(v___x_1345_, 2);
v___x_1347_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1347_, 0, v___x_1346_);
lean_ctor_set(v___x_1347_, 1, v_rows_1299_);
v___x_1348_ = l_List_appendTR___redArg(v_b_1293_, v___x_1347_);
v_as_x27_1292_ = v_tail_1297_;
v_b_1293_ = v___x_1348_;
goto _start;
}
}
v___jp_1351_:
{
lean_object* v___x_1360_; lean_object* v___x_1361_; 
v___x_1360_ = lean_unsigned_to_nat(2u);
v___x_1361_ = lean_nat_mul(v___y_1355_, v___x_1360_);
lean_dec(v___y_1355_);
v___y_1312_ = v___y_1352_;
v___y_1313_ = v___y_1353_;
v___y_1314_ = v___y_1354_;
v___y_1315_ = v___y_1356_;
v___y_1316_ = v___y_1357_;
v___y_1317_ = v___y_1358_;
v___y_1318_ = v___y_1359_;
v___y_1319_ = v___x_1361_;
goto v___jp_1311_;
}
v___jp_1362_:
{
lean_object* v___x_1367_; lean_object* v___x_1368_; lean_object* v___x_1369_; lean_object* v___x_1370_; lean_object* v___x_1371_; lean_object* v___x_1372_; lean_object* v___x_1373_; lean_object* v___x_1374_; lean_object* v___x_1375_; lean_object* v___x_1376_; lean_object* v___x_1377_; lean_object* v___x_1378_; lean_object* v___x_1379_; lean_object* v___x_1380_; lean_object* v___x_1381_; lean_object* v___x_1382_; lean_object* v___x_1383_; uint8_t v___x_1384_; 
v___x_1367_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6));
lean_inc(v_head_1296_);
v___x_1368_ = l_Lean_JsonNumber_fromNat(v_head_1296_);
v___x_1369_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1369_, 0, v___x_1368_);
v___x_1370_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1370_, 0, v___x_1367_);
lean_ctor_set(v___x_1370_, 1, v___x_1369_);
v___x_1371_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0));
v___x_1372_ = l_List_lengthTR___redArg(v_a_1305_);
lean_dec(v_a_1305_);
lean_inc(v___x_1372_);
v___x_1373_ = l_Lean_JsonNumber_fromNat(v___x_1372_);
v___x_1374_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1374_, 0, v___x_1373_);
lean_inc_ref(v___x_1374_);
v___x_1375_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1375_, 0, v___x_1371_);
lean_ctor_set(v___x_1375_, 1, v___x_1374_);
v___x_1376_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__3));
v___x_1377_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1377_, 0, v___x_1376_);
lean_ctor_set(v___x_1377_, 1, v___x_1374_);
v___x_1378_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__4));
v___x_1379_ = lean_nat_mul(v___x_1372_, v___y_1366_);
v___x_1380_ = l_Lean_JsonNumber_fromNat(v___x_1379_);
v___x_1381_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1381_, 0, v___x_1380_);
v___x_1382_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1382_, 0, v___x_1378_);
lean_ctor_set(v___x_1382_, 1, v___x_1381_);
v___x_1383_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__5));
v___x_1384_ = lean_nat_dec_eq(v_head_1296_, v___y_1363_);
if (v___x_1384_ == 0)
{
lean_object* v___x_1385_; uint8_t v___x_1386_; 
v___x_1385_ = lean_unsigned_to_nat(18u);
v___x_1386_ = lean_nat_dec_eq(v_head_1296_, v___x_1385_);
if (v___x_1386_ == 0)
{
lean_dec(v___x_1372_);
v___y_1312_ = v___x_1382_;
v___y_1313_ = v___x_1383_;
v___y_1314_ = v___x_1377_;
v___y_1315_ = v___x_1375_;
v___y_1316_ = v___x_1370_;
v___y_1317_ = v___y_1364_;
v___y_1318_ = v___y_1365_;
v___y_1319_ = v___x_1300_;
goto v___jp_1311_;
}
else
{
v___y_1352_ = v___x_1382_;
v___y_1353_ = v___x_1383_;
v___y_1354_ = v___x_1377_;
v___y_1355_ = v___x_1372_;
v___y_1356_ = v___x_1375_;
v___y_1357_ = v___x_1370_;
v___y_1358_ = v___y_1364_;
v___y_1359_ = v___y_1365_;
goto v___jp_1351_;
}
}
else
{
v___y_1352_ = v___x_1382_;
v___y_1353_ = v___x_1383_;
v___y_1354_ = v___x_1377_;
v___y_1355_ = v___x_1372_;
v___y_1356_ = v___x_1375_;
v___y_1357_ = v___x_1370_;
v___y_1358_ = v___y_1364_;
v___y_1359_ = v___y_1365_;
goto v___jp_1351_;
}
}
v___jp_1387_:
{
lean_object* v___x_1389_; lean_object* v___x_1390_; uint8_t v___x_1391_; 
v___x_1389_ = lean_unsigned_to_nat(17u);
v___x_1390_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__20));
v___x_1391_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_head_1296_, v___x_1390_);
if (v___x_1391_ == 0)
{
v___y_1363_ = v___x_1389_;
v___y_1364_ = v_rows_1299_;
v___y_1365_ = v_registers_1388_;
v___y_1366_ = v___x_1302_;
goto v___jp_1362_;
}
else
{
lean_object* v___x_1392_; 
v___x_1392_ = lean_unsigned_to_nat(2u);
v___y_1363_ = v___x_1389_;
v___y_1364_ = v_rows_1299_;
v___y_1365_ = v_registers_1388_;
v___y_1366_ = v___x_1392_;
goto v___jp_1362_;
}
}
v___jp_1393_:
{
lean_object* v___x_1394_; lean_object* v___x_1395_; 
v___x_1394_ = lp_lean1090_Lean1090_Impl_commBRegisters;
lean_inc(v_head_1296_);
v___x_1395_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(v_head_1296_, v_a_1305_, v___x_1394_, v_rows_1299_);
if (lean_obj_tag(v___x_1395_) == 0)
{
lean_object* v_a_1396_; 
v_a_1396_ = lean_ctor_get(v___x_1395_, 0);
lean_inc(v_a_1396_);
lean_dec_ref_known(v___x_1395_, 1);
v_registers_1388_ = v_a_1396_;
goto v___jp_1387_;
}
else
{
lean_del_object(v___x_1309_);
lean_dec(v_a_1307_);
lean_dec(v_a_1305_);
lean_dec(v_b_1293_);
return v___x_1395_;
}
}
}
}
else
{
lean_object* v_a_1402_; lean_object* v___x_1404_; uint8_t v_isShared_1405_; uint8_t v_isSharedCheck_1409_; 
lean_dec(v_b_1293_);
v_a_1402_ = lean_ctor_get(v___x_1304_, 0);
v_isSharedCheck_1409_ = !lean_is_exclusive(v___x_1304_);
if (v_isSharedCheck_1409_ == 0)
{
v___x_1404_ = v___x_1304_;
v_isShared_1405_ = v_isSharedCheck_1409_;
goto v_resetjp_1403_;
}
else
{
lean_inc(v_a_1402_);
lean_dec(v___x_1304_);
v___x_1404_ = lean_box(0);
v_isShared_1405_ = v_isSharedCheck_1409_;
goto v_resetjp_1403_;
}
v_resetjp_1403_:
{
lean_object* v___x_1407_; 
if (v_isShared_1405_ == 0)
{
v___x_1407_ = v___x_1404_;
goto v_reusejp_1406_;
}
else
{
lean_object* v_reuseFailAlloc_1408_; 
v_reuseFailAlloc_1408_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1408_, 0, v_a_1402_);
v___x_1407_ = v_reuseFailAlloc_1408_;
goto v_reusejp_1406_;
}
v_reusejp_1406_:
{
return v___x_1407_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___boxed(lean_object* v_output_1410_, lean_object* v_inputs_1411_, lean_object* v_as_x27_1412_, lean_object* v_b_1413_, lean_object* v___y_1414_){
_start:
{
lean_object* v_res_1415_; 
v_res_1415_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(v_output_1410_, v_inputs_1411_, v_as_x27_1412_, v_b_1413_);
lean_dec(v_as_x27_1412_);
lean_dec_ref(v_inputs_1411_);
lean_dec_ref(v_output_1410_);
return v_res_1415_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(lean_object* v_inputs_1416_, lean_object* v_output_1417_, lean_object* v_as_1418_, lean_object* v_as_x27_1419_, lean_object* v_b_1420_){
_start:
{
if (lean_obj_tag(v_as_x27_1419_) == 0)
{
lean_object* v___x_1422_; 
v___x_1422_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1422_, 0, v_b_1420_);
return v___x_1422_;
}
else
{
lean_object* v_head_1423_; lean_object* v_tail_1424_; lean_object* v___f_1425_; lean_object* v_rows_1426_; lean_object* v___x_1427_; lean_object* v___x_1428_; lean_object* v___x_1429_; lean_object* v___x_1430_; lean_object* v___x_1431_; 
v_head_1423_ = lean_ctor_get(v_as_x27_1419_, 0);
v_tail_1424_ = lean_ctor_get(v_as_x27_1419_, 1);
v___f_1425_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__0));
v_rows_1426_ = lean_box(0);
v___x_1427_ = lean_unsigned_to_nat(0u);
v___x_1428_ = lean_array_get_size(v_output_1417_);
v___x_1429_ = lean_unsigned_to_nat(1u);
v___x_1430_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1430_, 0, v___x_1427_);
lean_ctor_set(v___x_1430_, 1, v___x_1428_);
lean_ctor_set(v___x_1430_, 2, v___x_1429_);
v___x_1431_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(v_inputs_1416_, v_head_1423_, v_output_1417_, v___x_1430_, v_rows_1426_, v___x_1427_);
lean_dec_ref_known(v___x_1430_, 3);
if (lean_obj_tag(v___x_1431_) == 0)
{
lean_object* v_a_1432_; lean_object* v___x_1433_; lean_object* v_a_1434_; lean_object* v___x_1436_; uint8_t v_isShared_1437_; uint8_t v_isSharedCheck_1528_; 
v_a_1432_ = lean_ctor_get(v___x_1431_, 0);
lean_inc(v_a_1432_);
lean_dec_ref_known(v___x_1431_, 1);
v___x_1433_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(v_a_1432_, v_rows_1426_);
v_a_1434_ = lean_ctor_get(v___x_1433_, 0);
v_isSharedCheck_1528_ = !lean_is_exclusive(v___x_1433_);
if (v_isSharedCheck_1528_ == 0)
{
v___x_1436_ = v___x_1433_;
v_isShared_1437_ = v_isSharedCheck_1528_;
goto v_resetjp_1435_;
}
else
{
lean_inc(v_a_1434_);
lean_dec(v___x_1433_);
v___x_1436_ = lean_box(0);
v_isShared_1437_ = v_isSharedCheck_1528_;
goto v_resetjp_1435_;
}
v_resetjp_1435_:
{
lean_object* v___y_1439_; lean_object* v___y_1440_; lean_object* v___y_1441_; lean_object* v___y_1442_; lean_object* v___y_1443_; lean_object* v___y_1444_; lean_object* v___y_1445_; lean_object* v___y_1446_; lean_object* v___y_1479_; lean_object* v___y_1480_; lean_object* v___y_1481_; lean_object* v___y_1482_; lean_object* v___y_1483_; lean_object* v___y_1484_; lean_object* v___y_1485_; lean_object* v___y_1486_; lean_object* v___y_1490_; lean_object* v___y_1491_; lean_object* v___y_1492_; lean_object* v___y_1493_; lean_object* v_registers_1515_; lean_object* v___x_1524_; uint8_t v___x_1525_; 
v___x_1524_ = lean_unsigned_to_nat(20u);
v___x_1525_ = lean_nat_dec_eq(v_head_1423_, v___x_1524_);
if (v___x_1525_ == 0)
{
lean_object* v___x_1526_; uint8_t v___x_1527_; 
v___x_1526_ = lean_unsigned_to_nat(21u);
v___x_1527_ = lean_nat_dec_eq(v_head_1423_, v___x_1526_);
if (v___x_1527_ == 0)
{
v_registers_1515_ = v_rows_1426_;
goto v___jp_1514_;
}
else
{
goto v___jp_1520_;
}
}
else
{
goto v___jp_1520_;
}
v___jp_1438_:
{
lean_object* v___x_1447_; lean_object* v___x_1449_; 
v___x_1447_ = l_Lean_JsonNumber_fromNat(v___y_1446_);
if (v_isShared_1437_ == 0)
{
lean_ctor_set_tag(v___x_1436_, 2);
lean_ctor_set(v___x_1436_, 0, v___x_1447_);
v___x_1449_ = v___x_1436_;
goto v_reusejp_1448_;
}
else
{
lean_object* v_reuseFailAlloc_1477_; 
v_reuseFailAlloc_1477_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1477_, 0, v___x_1447_);
v___x_1449_ = v_reuseFailAlloc_1477_;
goto v_reusejp_1448_;
}
v_reusejp_1448_:
{
lean_object* v___x_1450_; lean_object* v___x_1451_; lean_object* v___x_1452_; lean_object* v___x_1453_; lean_object* v___x_1454_; lean_object* v___x_1455_; lean_object* v___x_1456_; lean_object* v___x_1457_; lean_object* v___x_1458_; lean_object* v___x_1459_; lean_object* v___x_1460_; lean_object* v___x_1461_; lean_object* v___x_1462_; lean_object* v___x_1463_; lean_object* v___x_1464_; lean_object* v___x_1465_; lean_object* v___x_1466_; lean_object* v___x_1467_; lean_object* v___x_1468_; lean_object* v___x_1469_; lean_object* v___x_1470_; lean_object* v___x_1471_; lean_object* v___x_1472_; lean_object* v___x_1473_; lean_object* v___x_1474_; lean_object* v___x_1475_; lean_object* v___x_1476_; 
lean_inc_ref(v___y_1442_);
v___x_1450_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1450_, 0, v___y_1442_);
lean_ctor_set(v___x_1450_, 1, v___x_1449_);
v___x_1451_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__1));
lean_inc(v_a_1434_);
v___x_1452_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__2(v_a_1434_, v___y_1445_);
v___x_1453_ = l_List_sum___at___00Lean_PersistentHashMap_subarrayMeasure_spec__2(v___x_1452_);
lean_dec(v___x_1452_);
v___x_1454_ = l_Lean_JsonNumber_fromNat(v___x_1453_);
v___x_1455_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1455_, 0, v___x_1454_);
v___x_1456_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1456_, 0, v___x_1451_);
lean_ctor_set(v___x_1456_, 1, v___x_1455_);
v___x_1457_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__2));
v___x_1458_ = l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(v_a_1434_, v___f_1425_);
v___x_1459_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3(v___x_1458_, v_rows_1426_);
v___x_1460_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___x_1459_);
v___x_1461_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1461_, 0, v___x_1457_);
lean_ctor_set(v___x_1461_, 1, v___x_1460_);
v___x_1462_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__4));
v___x_1463_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___y_1443_);
v___x_1464_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1464_, 0, v___x_1462_);
lean_ctor_set(v___x_1464_, 1, v___x_1463_);
v___x_1465_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1465_, 0, v___x_1464_);
lean_ctor_set(v___x_1465_, 1, v_rows_1426_);
v___x_1466_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1466_, 0, v___x_1461_);
lean_ctor_set(v___x_1466_, 1, v___x_1465_);
v___x_1467_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1467_, 0, v___x_1456_);
lean_ctor_set(v___x_1467_, 1, v___x_1466_);
v___x_1468_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1468_, 0, v___x_1450_);
lean_ctor_set(v___x_1468_, 1, v___x_1467_);
v___x_1469_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1469_, 0, v___y_1439_);
lean_ctor_set(v___x_1469_, 1, v___x_1468_);
v___x_1470_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1470_, 0, v___y_1441_);
lean_ctor_set(v___x_1470_, 1, v___x_1469_);
v___x_1471_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1471_, 0, v___y_1440_);
lean_ctor_set(v___x_1471_, 1, v___x_1470_);
v___x_1472_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1472_, 0, v___y_1444_);
lean_ctor_set(v___x_1472_, 1, v___x_1471_);
v___x_1473_ = l_Lean_Json_mkObj(v___x_1472_);
lean_dec_ref_known(v___x_1472_, 2);
v___x_1474_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1474_, 0, v___x_1473_);
lean_ctor_set(v___x_1474_, 1, v_rows_1426_);
v___x_1475_ = l_List_appendTR___redArg(v_b_1420_, v___x_1474_);
v___x_1476_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(v_output_1417_, v_inputs_1416_, v_tail_1424_, v___x_1475_);
return v___x_1476_;
}
}
v___jp_1478_:
{
lean_object* v___x_1487_; lean_object* v___x_1488_; 
v___x_1487_ = lean_unsigned_to_nat(2u);
v___x_1488_ = lean_nat_mul(v___y_1486_, v___x_1487_);
lean_dec(v___y_1486_);
v___y_1439_ = v___y_1479_;
v___y_1440_ = v___y_1480_;
v___y_1441_ = v___y_1481_;
v___y_1442_ = v___y_1482_;
v___y_1443_ = v___y_1483_;
v___y_1444_ = v___y_1485_;
v___y_1445_ = v___y_1484_;
v___y_1446_ = v___x_1488_;
goto v___jp_1438_;
}
v___jp_1489_:
{
lean_object* v___x_1494_; lean_object* v___x_1495_; lean_object* v___x_1496_; lean_object* v___x_1497_; lean_object* v___x_1498_; lean_object* v___x_1499_; lean_object* v___x_1500_; lean_object* v___x_1501_; lean_object* v___x_1502_; lean_object* v___x_1503_; lean_object* v___x_1504_; lean_object* v___x_1505_; lean_object* v___x_1506_; lean_object* v___x_1507_; lean_object* v___x_1508_; lean_object* v___x_1509_; lean_object* v___x_1510_; uint8_t v___x_1511_; 
v___x_1494_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6));
lean_inc(v_head_1423_);
v___x_1495_ = l_Lean_JsonNumber_fromNat(v_head_1423_);
v___x_1496_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1496_, 0, v___x_1495_);
v___x_1497_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1497_, 0, v___x_1494_);
lean_ctor_set(v___x_1497_, 1, v___x_1496_);
v___x_1498_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0));
v___x_1499_ = l_List_lengthTR___redArg(v_a_1432_);
lean_dec(v_a_1432_);
lean_inc(v___x_1499_);
v___x_1500_ = l_Lean_JsonNumber_fromNat(v___x_1499_);
v___x_1501_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1501_, 0, v___x_1500_);
lean_inc_ref(v___x_1501_);
v___x_1502_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1502_, 0, v___x_1498_);
lean_ctor_set(v___x_1502_, 1, v___x_1501_);
v___x_1503_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__3));
v___x_1504_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1504_, 0, v___x_1503_);
lean_ctor_set(v___x_1504_, 1, v___x_1501_);
v___x_1505_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__4));
v___x_1506_ = lean_nat_mul(v___x_1499_, v___y_1493_);
v___x_1507_ = l_Lean_JsonNumber_fromNat(v___x_1506_);
v___x_1508_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1508_, 0, v___x_1507_);
v___x_1509_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1509_, 0, v___x_1505_);
lean_ctor_set(v___x_1509_, 1, v___x_1508_);
v___x_1510_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__5));
v___x_1511_ = lean_nat_dec_eq(v_head_1423_, v___y_1490_);
if (v___x_1511_ == 0)
{
lean_object* v___x_1512_; uint8_t v___x_1513_; 
v___x_1512_ = lean_unsigned_to_nat(18u);
v___x_1513_ = lean_nat_dec_eq(v_head_1423_, v___x_1512_);
if (v___x_1513_ == 0)
{
lean_dec(v___x_1499_);
v___y_1439_ = v___x_1509_;
v___y_1440_ = v___x_1502_;
v___y_1441_ = v___x_1504_;
v___y_1442_ = v___x_1510_;
v___y_1443_ = v___y_1491_;
v___y_1444_ = v___x_1497_;
v___y_1445_ = v___y_1492_;
v___y_1446_ = v___x_1427_;
goto v___jp_1438_;
}
else
{
v___y_1479_ = v___x_1509_;
v___y_1480_ = v___x_1502_;
v___y_1481_ = v___x_1504_;
v___y_1482_ = v___x_1510_;
v___y_1483_ = v___y_1491_;
v___y_1484_ = v___y_1492_;
v___y_1485_ = v___x_1497_;
v___y_1486_ = v___x_1499_;
goto v___jp_1478_;
}
}
else
{
v___y_1479_ = v___x_1509_;
v___y_1480_ = v___x_1502_;
v___y_1481_ = v___x_1504_;
v___y_1482_ = v___x_1510_;
v___y_1483_ = v___y_1491_;
v___y_1484_ = v___y_1492_;
v___y_1485_ = v___x_1497_;
v___y_1486_ = v___x_1499_;
goto v___jp_1478_;
}
}
v___jp_1514_:
{
lean_object* v___x_1516_; lean_object* v___x_1517_; uint8_t v___x_1518_; 
v___x_1516_ = lean_unsigned_to_nat(17u);
v___x_1517_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__20));
v___x_1518_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_head_1423_, v___x_1517_);
if (v___x_1518_ == 0)
{
v___y_1490_ = v___x_1516_;
v___y_1491_ = v_registers_1515_;
v___y_1492_ = v_rows_1426_;
v___y_1493_ = v___x_1429_;
goto v___jp_1489_;
}
else
{
lean_object* v___x_1519_; 
v___x_1519_ = lean_unsigned_to_nat(2u);
v___y_1490_ = v___x_1516_;
v___y_1491_ = v_registers_1515_;
v___y_1492_ = v_rows_1426_;
v___y_1493_ = v___x_1519_;
goto v___jp_1489_;
}
}
v___jp_1520_:
{
lean_object* v___x_1521_; lean_object* v___x_1522_; 
v___x_1521_ = lp_lean1090_Lean1090_Impl_commBRegisters;
lean_inc(v_head_1423_);
v___x_1522_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(v_head_1423_, v_a_1432_, v___x_1521_, v_rows_1426_);
if (lean_obj_tag(v___x_1522_) == 0)
{
lean_object* v_a_1523_; 
v_a_1523_ = lean_ctor_get(v___x_1522_, 0);
lean_inc(v_a_1523_);
lean_dec_ref_known(v___x_1522_, 1);
v_registers_1515_ = v_a_1523_;
goto v___jp_1514_;
}
else
{
lean_del_object(v___x_1436_);
lean_dec(v_a_1434_);
lean_dec(v_a_1432_);
lean_dec(v_b_1420_);
return v___x_1522_;
}
}
}
}
else
{
lean_object* v_a_1529_; lean_object* v___x_1531_; uint8_t v_isShared_1532_; uint8_t v_isSharedCheck_1536_; 
lean_dec(v_b_1420_);
v_a_1529_ = lean_ctor_get(v___x_1431_, 0);
v_isSharedCheck_1536_ = !lean_is_exclusive(v___x_1431_);
if (v_isSharedCheck_1536_ == 0)
{
v___x_1531_ = v___x_1431_;
v_isShared_1532_ = v_isSharedCheck_1536_;
goto v_resetjp_1530_;
}
else
{
lean_inc(v_a_1529_);
lean_dec(v___x_1431_);
v___x_1531_ = lean_box(0);
v_isShared_1532_ = v_isSharedCheck_1536_;
goto v_resetjp_1530_;
}
v_resetjp_1530_:
{
lean_object* v___x_1534_; 
if (v_isShared_1532_ == 0)
{
v___x_1534_ = v___x_1531_;
goto v_reusejp_1533_;
}
else
{
lean_object* v_reuseFailAlloc_1535_; 
v_reuseFailAlloc_1535_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1535_, 0, v_a_1529_);
v___x_1534_ = v_reuseFailAlloc_1535_;
goto v_reusejp_1533_;
}
v_reusejp_1533_:
{
return v___x_1534_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___boxed(lean_object* v_inputs_1537_, lean_object* v_output_1538_, lean_object* v_as_1539_, lean_object* v_as_x27_1540_, lean_object* v_b_1541_, lean_object* v___y_1542_){
_start:
{
lean_object* v_res_1543_; 
v_res_1543_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(v_inputs_1537_, v_output_1538_, v_as_1539_, v_as_x27_1540_, v_b_1541_);
lean_dec(v_as_x27_1540_);
lean_dec(v_as_1539_);
lean_dec_ref(v_output_1538_);
lean_dec_ref(v_inputs_1537_);
return v_res_1543_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0(void){
_start:
{
lean_object* v___x_1544_; lean_object* v___x_1545_; 
v___x_1544_ = lean_unsigned_to_nat(32u);
v___x_1545_ = l_List_range(v___x_1544_);
return v___x_1545_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census(lean_object* v_inputs_1559_, lean_object* v_output_1560_){
_start:
{
lean_object* v_rows_1562_; lean_object* v___x_1563_; lean_object* v___x_1564_; 
v_rows_1562_ = lean_box(0);
v___x_1563_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0);
v___x_1564_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(v_inputs_1559_, v_output_1560_, v___x_1563_, v___x_1563_, v_rows_1562_);
if (lean_obj_tag(v___x_1564_) == 0)
{
lean_object* v_a_1565_; lean_object* v___x_1567_; uint8_t v_isShared_1568_; uint8_t v_isSharedCheck_1581_; 
v_a_1565_ = lean_ctor_get(v___x_1564_, 0);
v_isSharedCheck_1581_ = !lean_is_exclusive(v___x_1564_);
if (v_isSharedCheck_1581_ == 0)
{
v___x_1567_ = v___x_1564_;
v_isShared_1568_ = v_isSharedCheck_1581_;
goto v_resetjp_1566_;
}
else
{
lean_inc(v_a_1565_);
lean_dec(v___x_1564_);
v___x_1567_ = lean_box(0);
v_isShared_1568_ = v_isSharedCheck_1581_;
goto v_resetjp_1566_;
}
v_resetjp_1566_:
{
lean_object* v___x_1569_; lean_object* v___x_1570_; lean_object* v___x_1571_; lean_object* v___x_1572_; lean_object* v___x_1573_; lean_object* v___x_1574_; lean_object* v___x_1575_; lean_object* v___x_1576_; lean_object* v___x_1577_; lean_object* v___x_1579_; 
v___x_1569_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__3));
v___x_1570_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__6));
v___x_1571_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__7));
v___x_1572_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v_a_1565_);
v___x_1573_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1573_, 0, v___x_1571_);
lean_ctor_set(v___x_1573_, 1, v___x_1572_);
v___x_1574_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1574_, 0, v___x_1573_);
lean_ctor_set(v___x_1574_, 1, v_rows_1562_);
v___x_1575_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1575_, 0, v___x_1570_);
lean_ctor_set(v___x_1575_, 1, v___x_1574_);
v___x_1576_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1576_, 0, v___x_1569_);
lean_ctor_set(v___x_1576_, 1, v___x_1575_);
v___x_1577_ = l_Lean_Json_mkObj(v___x_1576_);
lean_dec_ref_known(v___x_1576_, 2);
if (v_isShared_1568_ == 0)
{
lean_ctor_set(v___x_1567_, 0, v___x_1577_);
v___x_1579_ = v___x_1567_;
goto v_reusejp_1578_;
}
else
{
lean_object* v_reuseFailAlloc_1580_; 
v_reuseFailAlloc_1580_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1580_, 0, v___x_1577_);
v___x_1579_ = v_reuseFailAlloc_1580_;
goto v_reusejp_1578_;
}
v_reusejp_1578_:
{
return v___x_1579_;
}
}
}
else
{
lean_object* v_a_1582_; lean_object* v___x_1584_; uint8_t v_isShared_1585_; uint8_t v_isSharedCheck_1589_; 
v_a_1582_ = lean_ctor_get(v___x_1564_, 0);
v_isSharedCheck_1589_ = !lean_is_exclusive(v___x_1564_);
if (v_isSharedCheck_1589_ == 0)
{
v___x_1584_ = v___x_1564_;
v_isShared_1585_ = v_isSharedCheck_1589_;
goto v_resetjp_1583_;
}
else
{
lean_inc(v_a_1582_);
lean_dec(v___x_1564_);
v___x_1584_ = lean_box(0);
v_isShared_1585_ = v_isSharedCheck_1589_;
goto v_resetjp_1583_;
}
v_resetjp_1583_:
{
lean_object* v___x_1587_; 
if (v_isShared_1585_ == 0)
{
v___x_1587_ = v___x_1584_;
goto v_reusejp_1586_;
}
else
{
lean_object* v_reuseFailAlloc_1588_; 
v_reuseFailAlloc_1588_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1588_, 0, v_a_1582_);
v___x_1587_ = v_reuseFailAlloc_1588_;
goto v_reusejp_1586_;
}
v_reusejp_1586_:
{
return v___x_1587_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___boxed(lean_object* v_inputs_1590_, lean_object* v_output_1591_, lean_object* v_a_1592_){
_start:
{
lean_object* v_res_1593_; 
v_res_1593_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census(v_inputs_1590_, v_output_1591_);
lean_dec_ref(v_output_1591_);
lean_dec_ref(v_inputs_1590_);
return v_res_1593_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0(lean_object* v_inputs_1594_, lean_object* v_a_1595_, lean_object* v_output_1596_, lean_object* v_range_1597_, lean_object* v_b_1598_, lean_object* v_i_1599_, lean_object* v_hs_1600_, lean_object* v_hl_1601_){
_start:
{
lean_object* v___x_1603_; 
v___x_1603_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(v_inputs_1594_, v_a_1595_, v_output_1596_, v_range_1597_, v_b_1598_, v_i_1599_);
return v___x_1603_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___boxed(lean_object* v_inputs_1604_, lean_object* v_a_1605_, lean_object* v_output_1606_, lean_object* v_range_1607_, lean_object* v_b_1608_, lean_object* v_i_1609_, lean_object* v_hs_1610_, lean_object* v_hl_1611_, lean_object* v___y_1612_){
_start:
{
lean_object* v_res_1613_; 
v_res_1613_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0(v_inputs_1604_, v_a_1605_, v_output_1606_, v_range_1607_, v_b_1608_, v_i_1609_, v_hs_1610_, v_hl_1611_);
lean_dec_ref(v_range_1607_);
lean_dec_ref(v_output_1606_);
lean_dec(v_a_1605_);
lean_dec_ref(v_inputs_1604_);
return v_res_1613_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1(lean_object* v_as_1614_, lean_object* v_as_x27_1615_, lean_object* v_b_1616_, lean_object* v_a_1617_){
_start:
{
lean_object* v___x_1619_; 
v___x_1619_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(v_as_x27_1615_, v_b_1616_);
return v___x_1619_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___boxed(lean_object* v_as_1620_, lean_object* v_as_x27_1621_, lean_object* v_b_1622_, lean_object* v_a_1623_, lean_object* v___y_1624_){
_start:
{
lean_object* v_res_1625_; 
v_res_1625_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1(v_as_1620_, v_as_x27_1621_, v_b_1622_, v_a_1623_);
lean_dec(v_as_x27_1621_);
lean_dec(v_as_1620_);
return v_res_1625_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5(lean_object* v_a_1626_, lean_object* v_a_1627_, lean_object* v_as_1628_, lean_object* v_as_x27_1629_, lean_object* v_b_1630_, lean_object* v_a_1631_){
_start:
{
lean_object* v___x_1633_; 
v___x_1633_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(v_a_1626_, v_a_1627_, v_as_x27_1629_, v_b_1630_);
return v___x_1633_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___boxed(lean_object* v_a_1634_, lean_object* v_a_1635_, lean_object* v_as_1636_, lean_object* v_as_x27_1637_, lean_object* v_b_1638_, lean_object* v_a_1639_, lean_object* v___y_1640_){
_start:
{
lean_object* v_res_1641_; 
v_res_1641_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5(v_a_1634_, v_a_1635_, v_as_1636_, v_as_x27_1637_, v_b_1638_, v_a_1639_);
lean_dec(v_as_x27_1637_);
lean_dec(v_as_1636_);
lean_dec(v_a_1635_);
return v_res_1641_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6(lean_object* v_inputs_1642_, lean_object* v_output_1643_, lean_object* v_as_1644_, lean_object* v_as_x27_1645_, lean_object* v_b_1646_, lean_object* v_a_1647_){
_start:
{
lean_object* v___x_1649_; 
v___x_1649_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(v_inputs_1642_, v_output_1643_, v_as_1644_, v_as_x27_1645_, v_b_1646_);
return v___x_1649_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___boxed(lean_object* v_inputs_1650_, lean_object* v_output_1651_, lean_object* v_as_1652_, lean_object* v_as_x27_1653_, lean_object* v_b_1654_, lean_object* v_a_1655_, lean_object* v___y_1656_){
_start:
{
lean_object* v_res_1657_; 
v_res_1657_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6(v_inputs_1650_, v_output_1651_, v_as_1652_, v_as_x27_1653_, v_b_1654_, v_a_1655_);
lean_dec(v_as_x27_1653_);
lean_dec(v_as_1652_);
lean_dec_ref(v_output_1651_);
lean_dec_ref(v_inputs_1650_);
return v_res_1657_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7(lean_object* v_output_1658_, lean_object* v_inputs_1659_, lean_object* v_as_1660_, lean_object* v_as_x27_1661_, lean_object* v_b_1662_, lean_object* v_a_1663_){
_start:
{
lean_object* v___x_1665_; 
v___x_1665_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(v_output_1658_, v_inputs_1659_, v_as_x27_1661_, v_b_1662_);
return v___x_1665_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___boxed(lean_object* v_output_1666_, lean_object* v_inputs_1667_, lean_object* v_as_1668_, lean_object* v_as_x27_1669_, lean_object* v_b_1670_, lean_object* v_a_1671_, lean_object* v___y_1672_){
_start:
{
lean_object* v_res_1673_; 
v_res_1673_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7(v_output_1666_, v_inputs_1667_, v_as_1668_, v_as_x27_1669_, v_b_1670_, v_a_1671_);
lean_dec(v_as_x27_1669_);
lean_dec(v_as_1668_);
lean_dec_ref(v_inputs_1667_);
lean_dec_ref(v_output_1666_);
return v_res_1673_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(lean_object* v_a_1674_, lean_object* v_as_1675_, size_t v_i_1676_, size_t v_stop_1677_, lean_object* v_b_1678_){
_start:
{
lean_object* v___y_1680_; uint8_t v___x_1684_; 
v___x_1684_ = lean_usize_dec_eq(v_i_1676_, v_stop_1677_);
if (v___x_1684_ == 0)
{
lean_object* v___x_1685_; lean_object* v_df_1686_; lean_object* v___x_1687_; uint8_t v___x_1688_; 
v___x_1685_ = lean_array_uget_borrowed(v_as_1675_, v_i_1676_);
v_df_1686_ = lean_ctor_get(v___x_1685_, 0);
lean_inc_ref(v_a_1674_);
lean_inc(v_df_1686_);
v___x_1687_ = lean_apply_1(v_a_1674_, v_df_1686_);
v___x_1688_ = lean_unbox(v___x_1687_);
if (v___x_1688_ == 0)
{
v___y_1680_ = v_b_1678_;
goto v___jp_1679_;
}
else
{
lean_object* v___x_1689_; 
lean_inc(v___x_1685_);
v___x_1689_ = lean_array_push(v_b_1678_, v___x_1685_);
v___y_1680_ = v___x_1689_;
goto v___jp_1679_;
}
}
else
{
lean_dec_ref(v_a_1674_);
return v_b_1678_;
}
v___jp_1679_:
{
size_t v___x_1681_; size_t v___x_1682_; 
v___x_1681_ = ((size_t)1ULL);
v___x_1682_ = lean_usize_add(v_i_1676_, v___x_1681_);
v_i_1676_ = v___x_1682_;
v_b_1678_ = v___y_1680_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1___boxed(lean_object* v_a_1690_, lean_object* v_as_1691_, lean_object* v_i_1692_, lean_object* v_stop_1693_, lean_object* v_b_1694_){
_start:
{
size_t v_i_boxed_1695_; size_t v_stop_boxed_1696_; lean_object* v_res_1697_; 
v_i_boxed_1695_ = lean_unbox_usize(v_i_1692_);
lean_dec(v_i_1692_);
v_stop_boxed_1696_ = lean_unbox_usize(v_stop_1693_);
lean_dec(v_stop_1693_);
v_res_1697_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(v_a_1690_, v_as_1691_, v_i_boxed_1695_, v_stop_boxed_1696_, v_b_1694_);
lean_dec_ref(v_as_1691_);
return v_res_1697_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0(lean_object* v_a_1699_, lean_object* v_a_1700_){
_start:
{
if (lean_obj_tag(v_a_1699_) == 0)
{
lean_object* v___x_1701_; 
v___x_1701_ = l_List_reverse___redArg(v_a_1700_);
return v___x_1701_;
}
else
{
lean_object* v_head_1702_; lean_object* v_tail_1703_; lean_object* v___x_1705_; uint8_t v_isShared_1706_; uint8_t v_isSharedCheck_1730_; 
v_head_1702_ = lean_ctor_get(v_a_1699_, 0);
v_tail_1703_ = lean_ctor_get(v_a_1699_, 1);
v_isSharedCheck_1730_ = !lean_is_exclusive(v_a_1699_);
if (v_isSharedCheck_1730_ == 0)
{
v___x_1705_ = v_a_1699_;
v_isShared_1706_ = v_isSharedCheck_1730_;
goto v_resetjp_1704_;
}
else
{
lean_inc(v_tail_1703_);
lean_inc(v_head_1702_);
lean_dec(v_a_1699_);
v___x_1705_ = lean_box(0);
v_isShared_1706_ = v_isSharedCheck_1730_;
goto v_resetjp_1704_;
}
v_resetjp_1704_:
{
lean_object* v_fst_1707_; lean_object* v_snd_1708_; lean_object* v___x_1710_; uint8_t v_isShared_1711_; uint8_t v_isSharedCheck_1729_; 
v_fst_1707_ = lean_ctor_get(v_head_1702_, 0);
v_snd_1708_ = lean_ctor_get(v_head_1702_, 1);
v_isSharedCheck_1729_ = !lean_is_exclusive(v_head_1702_);
if (v_isSharedCheck_1729_ == 0)
{
v___x_1710_ = v_head_1702_;
v_isShared_1711_ = v_isSharedCheck_1729_;
goto v_resetjp_1709_;
}
else
{
lean_inc(v_snd_1708_);
lean_inc(v_fst_1707_);
lean_dec(v_head_1702_);
v___x_1710_ = lean_box(0);
v_isShared_1711_ = v_isSharedCheck_1729_;
goto v_resetjp_1709_;
}
v_resetjp_1709_:
{
lean_object* v___x_1712_; lean_object* v___x_1713_; lean_object* v___x_1714_; lean_object* v___x_1715_; lean_object* v___x_1716_; lean_object* v___x_1718_; 
v___x_1712_ = ((lean_object*)(l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0___closed__0));
v___x_1713_ = lean_box(0);
v___x_1714_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6));
v___x_1715_ = l_Lean_JsonNumber_fromNat(v_snd_1708_);
v___x_1716_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1716_, 0, v___x_1715_);
if (v_isShared_1711_ == 0)
{
lean_ctor_set(v___x_1710_, 1, v___x_1716_);
lean_ctor_set(v___x_1710_, 0, v___x_1714_);
v___x_1718_ = v___x_1710_;
goto v_reusejp_1717_;
}
else
{
lean_object* v_reuseFailAlloc_1728_; 
v_reuseFailAlloc_1728_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1728_, 0, v___x_1714_);
lean_ctor_set(v_reuseFailAlloc_1728_, 1, v___x_1716_);
v___x_1718_ = v_reuseFailAlloc_1728_;
goto v_reusejp_1717_;
}
v_reusejp_1717_:
{
lean_object* v___x_1719_; lean_object* v___x_1720_; lean_object* v___x_1722_; 
v___x_1719_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(v_fst_1707_);
v___x_1720_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1720_, 0, v___x_1712_);
lean_ctor_set(v___x_1720_, 1, v___x_1719_);
if (v_isShared_1706_ == 0)
{
lean_ctor_set(v___x_1705_, 1, v___x_1713_);
lean_ctor_set(v___x_1705_, 0, v___x_1720_);
v___x_1722_ = v___x_1705_;
goto v_reusejp_1721_;
}
else
{
lean_object* v_reuseFailAlloc_1727_; 
v_reuseFailAlloc_1727_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1727_, 0, v___x_1720_);
lean_ctor_set(v_reuseFailAlloc_1727_, 1, v___x_1713_);
v___x_1722_ = v_reuseFailAlloc_1727_;
goto v_reusejp_1721_;
}
v_reusejp_1721_:
{
lean_object* v___x_1723_; lean_object* v___x_1724_; lean_object* v___x_1725_; 
v___x_1723_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1723_, 0, v___x_1718_);
lean_ctor_set(v___x_1723_, 1, v___x_1722_);
v___x_1724_ = l_Lean_Json_mkObj(v___x_1723_);
lean_dec_ref_known(v___x_1723_, 2);
v___x_1725_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1725_, 0, v___x_1724_);
lean_ctor_set(v___x_1725_, 1, v_a_1700_);
v_a_1699_ = v_tail_1703_;
v_a_1700_ = v___x_1725_;
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
lean_object* v___x_1741_; lean_object* v___x_1742_; 
v___x_1741_ = lean_unsigned_to_nat(172432u);
v___x_1742_ = l_Lean_JsonNumber_fromNat(v___x_1741_);
return v___x_1742_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8(void){
_start:
{
lean_object* v___x_1743_; lean_object* v___x_1744_; 
v___x_1743_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__7, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__7_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__7);
v___x_1744_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1744_, 0, v___x_1743_);
return v___x_1744_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9(void){
_start:
{
lean_object* v___x_1745_; lean_object* v___x_1746_; lean_object* v___x_1747_; 
v___x_1745_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8);
v___x_1746_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__6));
v___x_1747_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1747_, 0, v___x_1746_);
lean_ctor_set(v___x_1747_, 1, v___x_1745_);
return v___x_1747_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10(void){
_start:
{
lean_object* v___x_1748_; lean_object* v___x_1749_; lean_object* v___x_1750_; 
v___x_1748_ = lean_box(0);
v___x_1749_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9);
v___x_1750_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1750_, 0, v___x_1749_);
lean_ctor_set(v___x_1750_, 1, v___x_1748_);
return v___x_1750_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode(lean_object* v_mode_1769_, lean_object* v_inputs_1770_, uint8_t v_withCensus_1771_, uint8_t v_wait_1772_){
_start:
{
lean_object* v___x_1774_; lean_object* v___x_1775_; 
lean_inc_ref(v_mode_1769_);
v___x_1774_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select(v_mode_1769_);
v___x_1775_ = l_IO_ofExcept___at___00Std_Time_Database_TZdb_parseTZIfFromDisk_spec__0___redArg(v___x_1774_);
if (lean_obj_tag(v___x_1775_) == 0)
{
lean_object* v_a_1776_; lean_object* v___x_1777_; lean_object* v___y_1779_; lean_object* v___x_1902_; lean_object* v___x_1903_; uint8_t v___x_1904_; 
v_a_1776_ = lean_ctor_get(v___x_1775_, 0);
lean_inc(v_a_1776_);
lean_dec_ref_known(v___x_1775_, 1);
v___x_1777_ = lean_unsigned_to_nat(0u);
v___x_1902_ = lean_array_get_size(v_inputs_1770_);
v___x_1903_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__21));
v___x_1904_ = lean_nat_dec_lt(v___x_1777_, v___x_1902_);
if (v___x_1904_ == 0)
{
lean_dec(v_a_1776_);
v___y_1779_ = v___x_1903_;
goto v___jp_1778_;
}
else
{
uint8_t v___x_1905_; 
v___x_1905_ = lean_nat_dec_le(v___x_1902_, v___x_1902_);
if (v___x_1905_ == 0)
{
if (v___x_1904_ == 0)
{
lean_dec(v_a_1776_);
v___y_1779_ = v___x_1903_;
goto v___jp_1778_;
}
else
{
size_t v___x_1906_; size_t v___x_1907_; lean_object* v___x_1908_; 
v___x_1906_ = ((size_t)0ULL);
v___x_1907_ = lean_usize_of_nat(v___x_1902_);
v___x_1908_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(v_a_1776_, v_inputs_1770_, v___x_1906_, v___x_1907_, v___x_1903_);
v___y_1779_ = v___x_1908_;
goto v___jp_1778_;
}
}
else
{
size_t v___x_1909_; size_t v___x_1910_; lean_object* v___x_1911_; 
v___x_1909_ = ((size_t)0ULL);
v___x_1910_ = lean_usize_of_nat(v___x_1902_);
v___x_1911_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(v_a_1776_, v_inputs_1770_, v___x_1909_, v___x_1910_, v___x_1903_);
v___y_1779_ = v___x_1911_;
goto v___jp_1778_;
}
}
v___jp_1778_:
{
lean_object* v___x_1780_; lean_object* v___x_1781_; lean_object* v___x_1782_; lean_object* v___x_1783_; lean_object* v___x_1784_; lean_object* v___x_1785_; lean_object* v___x_1786_; lean_object* v___x_1787_; lean_object* v___x_1788_; lean_object* v___x_1789_; lean_object* v___x_1790_; lean_object* v___x_1791_; lean_object* v___x_1792_; lean_object* v___x_1793_; lean_object* v___x_1794_; lean_object* v___x_1795_; 
v___x_1780_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__3));
v___x_1781_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__4));
v___x_1782_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1782_, 0, v_mode_1769_);
v___x_1783_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1783_, 0, v___x_1781_);
lean_ctor_set(v___x_1783_, 1, v___x_1782_);
v___x_1784_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__5));
v___x_1785_ = lean_array_get_size(v___y_1779_);
v___x_1786_ = l_Lean_JsonNumber_fromNat(v___x_1785_);
v___x_1787_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1787_, 0, v___x_1786_);
v___x_1788_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1788_, 0, v___x_1784_);
lean_ctor_set(v___x_1788_, 1, v___x_1787_);
v___x_1789_ = lean_box(0);
v___x_1790_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10);
v___x_1791_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1791_, 0, v___x_1788_);
lean_ctor_set(v___x_1791_, 1, v___x_1790_);
lean_inc_ref(v___x_1783_);
v___x_1792_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1792_, 0, v___x_1783_);
lean_ctor_set(v___x_1792_, 1, v___x_1791_);
v___x_1793_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1793_, 0, v___x_1780_);
lean_ctor_set(v___x_1793_, 1, v___x_1792_);
v___x_1794_ = l_Lean_Json_mkObj(v___x_1793_);
lean_dec_ref_known(v___x_1793_, 2);
v___x_1795_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_1794_);
if (lean_obj_tag(v___x_1795_) == 0)
{
lean_object* v___x_1797_; uint8_t v_isShared_1798_; uint8_t v_isSharedCheck_1900_; 
v_isSharedCheck_1900_ = !lean_is_exclusive(v___x_1795_);
if (v_isSharedCheck_1900_ == 0)
{
lean_object* v_unused_1901_; 
v_unused_1901_ = lean_ctor_get(v___x_1795_, 0);
lean_dec(v_unused_1901_);
v___x_1797_ = v___x_1795_;
v_isShared_1798_ = v_isSharedCheck_1900_;
goto v_resetjp_1796_;
}
else
{
lean_dec(v___x_1795_);
v___x_1797_ = lean_box(0);
v_isShared_1798_ = v_isSharedCheck_1900_;
goto v_resetjp_1796_;
}
v_resetjp_1796_:
{
lean_object* v___x_1799_; lean_object* v___x_1800_; 
v___x_1799_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__11));
v___x_1800_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_wait_1772_, v___x_1799_);
if (lean_obj_tag(v___x_1800_) == 0)
{
lean_object* v___x_1802_; uint8_t v_isShared_1803_; uint8_t v_isSharedCheck_1898_; 
v_isSharedCheck_1898_ = !lean_is_exclusive(v___x_1800_);
if (v_isSharedCheck_1898_ == 0)
{
lean_object* v_unused_1899_; 
v_unused_1899_ = lean_ctor_get(v___x_1800_, 0);
lean_dec(v_unused_1899_);
v___x_1802_ = v___x_1800_;
v_isShared_1803_ = v_isSharedCheck_1898_;
goto v_resetjp_1801_;
}
else
{
lean_dec(v___x_1800_);
v___x_1802_ = lean_box(0);
v_isShared_1803_ = v_isSharedCheck_1898_;
goto v_resetjp_1801_;
}
v_resetjp_1801_:
{
lean_object* v___x_1804_; 
v___x_1804_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode(v___y_1779_);
if (lean_obj_tag(v___x_1804_) == 0)
{
lean_object* v_a_1805_; lean_object* v_fst_1806_; lean_object* v_snd_1807_; lean_object* v___x_1809_; uint8_t v_isShared_1810_; uint8_t v_isSharedCheck_1889_; 
v_a_1805_ = lean_ctor_get(v___x_1804_, 0);
lean_inc(v_a_1805_);
lean_dec_ref_known(v___x_1804_, 1);
v_fst_1806_ = lean_ctor_get(v_a_1805_, 0);
v_snd_1807_ = lean_ctor_get(v_a_1805_, 1);
v_isSharedCheck_1889_ = !lean_is_exclusive(v_a_1805_);
if (v_isSharedCheck_1889_ == 0)
{
v___x_1809_ = v_a_1805_;
v_isShared_1810_ = v_isSharedCheck_1889_;
goto v_resetjp_1808_;
}
else
{
lean_inc(v_snd_1807_);
lean_inc(v_fst_1806_);
lean_dec(v_a_1805_);
v___x_1809_ = lean_box(0);
v_isShared_1810_ = v_isSharedCheck_1889_;
goto v_resetjp_1808_;
}
v_resetjp_1808_:
{
lean_object* v___x_1811_; lean_object* v___x_1812_; lean_object* v___x_1813_; lean_object* v___x_1814_; lean_object* v___x_1816_; 
v___x_1811_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__14));
v___x_1812_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__15));
v___x_1813_ = lean_array_get_size(v_fst_1806_);
v___x_1814_ = l_Lean_JsonNumber_fromNat(v___x_1813_);
if (v_isShared_1803_ == 0)
{
lean_ctor_set_tag(v___x_1802_, 2);
lean_ctor_set(v___x_1802_, 0, v___x_1814_);
v___x_1816_ = v___x_1802_;
goto v_reusejp_1815_;
}
else
{
lean_object* v_reuseFailAlloc_1888_; 
v_reuseFailAlloc_1888_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1888_, 0, v___x_1814_);
v___x_1816_ = v_reuseFailAlloc_1888_;
goto v_reusejp_1815_;
}
v_reusejp_1815_:
{
lean_object* v___x_1818_; 
if (v_isShared_1810_ == 0)
{
lean_ctor_set(v___x_1809_, 1, v___x_1816_);
lean_ctor_set(v___x_1809_, 0, v___x_1812_);
v___x_1818_ = v___x_1809_;
goto v_reusejp_1817_;
}
else
{
lean_object* v_reuseFailAlloc_1887_; 
v_reuseFailAlloc_1887_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1887_, 0, v___x_1812_);
lean_ctor_set(v_reuseFailAlloc_1887_, 1, v___x_1816_);
v___x_1818_ = v_reuseFailAlloc_1887_;
goto v_reusejp_1817_;
}
v_reusejp_1817_:
{
lean_object* v___x_1819_; lean_object* v___x_1820_; lean_object* v___x_1822_; 
v___x_1819_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__16));
v___x_1820_ = l_Lean_JsonNumber_fromNat(v_snd_1807_);
if (v_isShared_1798_ == 0)
{
lean_ctor_set_tag(v___x_1797_, 2);
lean_ctor_set(v___x_1797_, 0, v___x_1820_);
v___x_1822_ = v___x_1797_;
goto v_reusejp_1821_;
}
else
{
lean_object* v_reuseFailAlloc_1886_; 
v_reuseFailAlloc_1886_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1886_, 0, v___x_1820_);
v___x_1822_ = v_reuseFailAlloc_1886_;
goto v_reusejp_1821_;
}
v_reusejp_1821_:
{
lean_object* v___x_1823_; lean_object* v___x_1824_; lean_object* v___x_1825_; lean_object* v___x_1826_; lean_object* v___x_1827_; lean_object* v___x_1828_; lean_object* v___x_1829_; 
v___x_1823_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1823_, 0, v___x_1819_);
lean_ctor_set(v___x_1823_, 1, v___x_1822_);
v___x_1824_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1824_, 0, v___x_1823_);
lean_ctor_set(v___x_1824_, 1, v___x_1789_);
lean_inc_ref(v___x_1824_);
v___x_1825_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1825_, 0, v___x_1818_);
lean_ctor_set(v___x_1825_, 1, v___x_1824_);
lean_inc_ref(v___x_1783_);
v___x_1826_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1826_, 0, v___x_1783_);
lean_ctor_set(v___x_1826_, 1, v___x_1825_);
v___x_1827_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1827_, 0, v___x_1811_);
lean_ctor_set(v___x_1827_, 1, v___x_1826_);
v___x_1828_ = l_Lean_Json_mkObj(v___x_1827_);
lean_dec_ref_known(v___x_1827_, 2);
v___x_1829_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_1828_);
if (lean_obj_tag(v___x_1829_) == 0)
{
lean_object* v___x_1830_; lean_object* v___x_1831_; 
lean_dec_ref_known(v___x_1829_, 1);
v___x_1830_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__17));
v___x_1831_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_wait_1772_, v___x_1830_);
if (lean_obj_tag(v___x_1831_) == 0)
{
lean_object* v___x_1832_; 
lean_dec_ref_known(v___x_1831_, 1);
v___x_1832_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume(v___y_1779_, v_fst_1806_);
if (lean_obj_tag(v___x_1832_) == 0)
{
lean_object* v_a_1833_; lean_object* v_fst_1834_; lean_object* v_snd_1835_; lean_object* v___x_1837_; uint8_t v_isShared_1838_; uint8_t v_isSharedCheck_1877_; 
v_a_1833_ = lean_ctor_get(v___x_1832_, 0);
lean_inc(v_a_1833_);
lean_dec_ref_known(v___x_1832_, 1);
v_fst_1834_ = lean_ctor_get(v_a_1833_, 0);
v_snd_1835_ = lean_ctor_get(v_a_1833_, 1);
v_isSharedCheck_1877_ = !lean_is_exclusive(v_a_1833_);
if (v_isSharedCheck_1877_ == 0)
{
v___x_1837_ = v_a_1833_;
v_isShared_1838_ = v_isSharedCheck_1877_;
goto v_resetjp_1836_;
}
else
{
lean_inc(v_snd_1835_);
lean_inc(v_fst_1834_);
lean_dec(v_a_1833_);
v___x_1837_ = lean_box(0);
v_isShared_1838_ = v_isSharedCheck_1877_;
goto v_resetjp_1836_;
}
v_resetjp_1836_:
{
lean_object* v___x_1839_; lean_object* v___x_1840_; lean_object* v___x_1841_; lean_object* v___x_1843_; 
v___x_1839_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__20));
v___x_1840_ = ((lean_object*)(l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0___closed__0));
v___x_1841_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(v_fst_1834_);
if (v_isShared_1838_ == 0)
{
lean_ctor_set(v___x_1837_, 1, v___x_1841_);
lean_ctor_set(v___x_1837_, 0, v___x_1840_);
v___x_1843_ = v___x_1837_;
goto v_reusejp_1842_;
}
else
{
lean_object* v_reuseFailAlloc_1876_; 
v_reuseFailAlloc_1876_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1876_, 0, v___x_1840_);
lean_ctor_set(v_reuseFailAlloc_1876_, 1, v___x_1841_);
v___x_1843_ = v_reuseFailAlloc_1876_;
goto v_reusejp_1842_;
}
v_reusejp_1842_:
{
lean_object* v___x_1844_; lean_object* v___x_1845_; lean_object* v___x_1846_; lean_object* v___x_1847_; lean_object* v___x_1848_; lean_object* v___x_1849_; lean_object* v___x_1850_; lean_object* v___x_1851_; lean_object* v___x_1852_; lean_object* v___x_1853_; lean_object* v___x_1854_; lean_object* v___x_1855_; 
v___x_1844_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__7));
v___x_1845_ = lean_array_to_list(v_snd_1835_);
v___x_1846_ = l_List_zipIdxTR___redArg(v___x_1845_, v___x_1777_);
v___x_1847_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0(v___x_1846_, v___x_1789_);
v___x_1848_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___x_1847_);
v___x_1849_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1849_, 0, v___x_1844_);
lean_ctor_set(v___x_1849_, 1, v___x_1848_);
v___x_1850_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1850_, 0, v___x_1849_);
lean_ctor_set(v___x_1850_, 1, v___x_1824_);
v___x_1851_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1851_, 0, v___x_1843_);
lean_ctor_set(v___x_1851_, 1, v___x_1850_);
v___x_1852_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1852_, 0, v___x_1783_);
lean_ctor_set(v___x_1852_, 1, v___x_1851_);
v___x_1853_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1853_, 0, v___x_1839_);
lean_ctor_set(v___x_1853_, 1, v___x_1852_);
v___x_1854_ = l_Lean_Json_mkObj(v___x_1853_);
lean_dec_ref_known(v___x_1853_, 2);
v___x_1855_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_1854_);
if (lean_obj_tag(v___x_1855_) == 0)
{
lean_object* v___x_1857_; uint8_t v_isShared_1858_; uint8_t v_isSharedCheck_1874_; 
v_isSharedCheck_1874_ = !lean_is_exclusive(v___x_1855_);
if (v_isSharedCheck_1874_ == 0)
{
lean_object* v_unused_1875_; 
v_unused_1875_ = lean_ctor_get(v___x_1855_, 0);
lean_dec(v_unused_1875_);
v___x_1857_ = v___x_1855_;
v_isShared_1858_ = v_isSharedCheck_1874_;
goto v_resetjp_1856_;
}
else
{
lean_dec(v___x_1855_);
v___x_1857_ = lean_box(0);
v_isShared_1858_ = v_isSharedCheck_1874_;
goto v_resetjp_1856_;
}
v_resetjp_1856_:
{
if (v_withCensus_1771_ == 0)
{
lean_object* v___x_1859_; lean_object* v___x_1861_; 
lean_dec(v_fst_1806_);
lean_dec_ref(v___y_1779_);
v___x_1859_ = lean_box(0);
if (v_isShared_1858_ == 0)
{
lean_ctor_set(v___x_1857_, 0, v___x_1859_);
v___x_1861_ = v___x_1857_;
goto v_reusejp_1860_;
}
else
{
lean_object* v_reuseFailAlloc_1862_; 
v_reuseFailAlloc_1862_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1862_, 0, v___x_1859_);
v___x_1861_ = v_reuseFailAlloc_1862_;
goto v_reusejp_1860_;
}
v_reusejp_1860_:
{
return v___x_1861_;
}
}
else
{
lean_object* v___x_1863_; 
lean_del_object(v___x_1857_);
v___x_1863_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census(v___y_1779_, v_fst_1806_);
lean_dec(v_fst_1806_);
lean_dec_ref(v___y_1779_);
if (lean_obj_tag(v___x_1863_) == 0)
{
lean_object* v_a_1864_; lean_object* v___x_1865_; 
v_a_1864_ = lean_ctor_get(v___x_1863_, 0);
lean_inc(v_a_1864_);
lean_dec_ref_known(v___x_1863_, 1);
v___x_1865_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v_a_1864_);
return v___x_1865_;
}
else
{
lean_object* v_a_1866_; lean_object* v___x_1868_; uint8_t v_isShared_1869_; uint8_t v_isSharedCheck_1873_; 
v_a_1866_ = lean_ctor_get(v___x_1863_, 0);
v_isSharedCheck_1873_ = !lean_is_exclusive(v___x_1863_);
if (v_isSharedCheck_1873_ == 0)
{
v___x_1868_ = v___x_1863_;
v_isShared_1869_ = v_isSharedCheck_1873_;
goto v_resetjp_1867_;
}
else
{
lean_inc(v_a_1866_);
lean_dec(v___x_1863_);
v___x_1868_ = lean_box(0);
v_isShared_1869_ = v_isSharedCheck_1873_;
goto v_resetjp_1867_;
}
v_resetjp_1867_:
{
lean_object* v___x_1871_; 
if (v_isShared_1869_ == 0)
{
v___x_1871_ = v___x_1868_;
goto v_reusejp_1870_;
}
else
{
lean_object* v_reuseFailAlloc_1872_; 
v_reuseFailAlloc_1872_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1872_, 0, v_a_1866_);
v___x_1871_ = v_reuseFailAlloc_1872_;
goto v_reusejp_1870_;
}
v_reusejp_1870_:
{
return v___x_1871_;
}
}
}
}
}
}
else
{
lean_dec(v_fst_1806_);
lean_dec_ref(v___y_1779_);
return v___x_1855_;
}
}
}
}
else
{
lean_object* v_a_1878_; lean_object* v___x_1880_; uint8_t v_isShared_1881_; uint8_t v_isSharedCheck_1885_; 
lean_dec_ref_known(v___x_1824_, 2);
lean_dec(v_fst_1806_);
lean_dec_ref_known(v___x_1783_, 2);
lean_dec_ref(v___y_1779_);
v_a_1878_ = lean_ctor_get(v___x_1832_, 0);
v_isSharedCheck_1885_ = !lean_is_exclusive(v___x_1832_);
if (v_isSharedCheck_1885_ == 0)
{
v___x_1880_ = v___x_1832_;
v_isShared_1881_ = v_isSharedCheck_1885_;
goto v_resetjp_1879_;
}
else
{
lean_inc(v_a_1878_);
lean_dec(v___x_1832_);
v___x_1880_ = lean_box(0);
v_isShared_1881_ = v_isSharedCheck_1885_;
goto v_resetjp_1879_;
}
v_resetjp_1879_:
{
lean_object* v___x_1883_; 
if (v_isShared_1881_ == 0)
{
v___x_1883_ = v___x_1880_;
goto v_reusejp_1882_;
}
else
{
lean_object* v_reuseFailAlloc_1884_; 
v_reuseFailAlloc_1884_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1884_, 0, v_a_1878_);
v___x_1883_ = v_reuseFailAlloc_1884_;
goto v_reusejp_1882_;
}
v_reusejp_1882_:
{
return v___x_1883_;
}
}
}
}
else
{
lean_dec_ref_known(v___x_1824_, 2);
lean_dec(v_fst_1806_);
lean_dec_ref_known(v___x_1783_, 2);
lean_dec_ref(v___y_1779_);
return v___x_1831_;
}
}
else
{
lean_dec_ref_known(v___x_1824_, 2);
lean_dec(v_fst_1806_);
lean_dec_ref_known(v___x_1783_, 2);
lean_dec_ref(v___y_1779_);
return v___x_1829_;
}
}
}
}
}
}
else
{
lean_object* v_a_1890_; lean_object* v___x_1892_; uint8_t v_isShared_1893_; uint8_t v_isSharedCheck_1897_; 
lean_del_object(v___x_1802_);
lean_del_object(v___x_1797_);
lean_dec_ref_known(v___x_1783_, 2);
lean_dec_ref(v___y_1779_);
v_a_1890_ = lean_ctor_get(v___x_1804_, 0);
v_isSharedCheck_1897_ = !lean_is_exclusive(v___x_1804_);
if (v_isSharedCheck_1897_ == 0)
{
v___x_1892_ = v___x_1804_;
v_isShared_1893_ = v_isSharedCheck_1897_;
goto v_resetjp_1891_;
}
else
{
lean_inc(v_a_1890_);
lean_dec(v___x_1804_);
v___x_1892_ = lean_box(0);
v_isShared_1893_ = v_isSharedCheck_1897_;
goto v_resetjp_1891_;
}
v_resetjp_1891_:
{
lean_object* v___x_1895_; 
if (v_isShared_1893_ == 0)
{
v___x_1895_ = v___x_1892_;
goto v_reusejp_1894_;
}
else
{
lean_object* v_reuseFailAlloc_1896_; 
v_reuseFailAlloc_1896_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1896_, 0, v_a_1890_);
v___x_1895_ = v_reuseFailAlloc_1896_;
goto v_reusejp_1894_;
}
v_reusejp_1894_:
{
return v___x_1895_;
}
}
}
}
}
else
{
lean_del_object(v___x_1797_);
lean_dec_ref_known(v___x_1783_, 2);
lean_dec_ref(v___y_1779_);
return v___x_1800_;
}
}
}
else
{
lean_dec_ref_known(v___x_1783_, 2);
lean_dec_ref(v___y_1779_);
return v___x_1795_;
}
}
}
else
{
lean_object* v_a_1912_; lean_object* v___x_1914_; uint8_t v_isShared_1915_; uint8_t v_isSharedCheck_1919_; 
lean_dec_ref(v_mode_1769_);
v_a_1912_ = lean_ctor_get(v___x_1775_, 0);
v_isSharedCheck_1919_ = !lean_is_exclusive(v___x_1775_);
if (v_isSharedCheck_1919_ == 0)
{
v___x_1914_ = v___x_1775_;
v_isShared_1915_ = v_isSharedCheck_1919_;
goto v_resetjp_1913_;
}
else
{
lean_inc(v_a_1912_);
lean_dec(v___x_1775_);
v___x_1914_ = lean_box(0);
v_isShared_1915_ = v_isSharedCheck_1919_;
goto v_resetjp_1913_;
}
v_resetjp_1913_:
{
lean_object* v___x_1917_; 
if (v_isShared_1915_ == 0)
{
v___x_1917_ = v___x_1914_;
goto v_reusejp_1916_;
}
else
{
lean_object* v_reuseFailAlloc_1918_; 
v_reuseFailAlloc_1918_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1918_, 0, v_a_1912_);
v___x_1917_ = v_reuseFailAlloc_1918_;
goto v_reusejp_1916_;
}
v_reusejp_1916_:
{
return v___x_1917_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___boxed(lean_object* v_mode_1920_, lean_object* v_inputs_1921_, lean_object* v_withCensus_1922_, lean_object* v_wait_1923_, lean_object* v_a_1924_){
_start:
{
uint8_t v_withCensus_boxed_1925_; uint8_t v_wait_boxed_1926_; lean_object* v_res_1927_; 
v_withCensus_boxed_1925_ = lean_unbox(v_withCensus_1922_);
v_wait_boxed_1926_ = lean_unbox(v_wait_1923_);
v_res_1927_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode(v_mode_1920_, v_inputs_1921_, v_withCensus_boxed_1925_, v_wait_boxed_1926_);
lean_dec_ref(v_inputs_1921_);
return v_res_1927_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0(uint8_t v_candidate_1934_, lean_object* v_register_1935_, lean_object* v_as_1936_, size_t v_sz_1937_, size_t v_i_1938_, lean_object* v_b_1939_){
_start:
{
lean_object* v_a_1942_; uint8_t v___x_1946_; 
v___x_1946_ = lean_usize_dec_lt(v_i_1938_, v_sz_1937_);
if (v___x_1946_ == 0)
{
lean_object* v___x_1947_; 
v___x_1947_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1947_, 0, v_b_1939_);
return v___x_1947_;
}
else
{
lean_object* v_fst_1948_; lean_object* v_snd_1949_; lean_object* v___x_1951_; uint8_t v_isShared_1952_; uint8_t v_isSharedCheck_2015_; 
v_fst_1948_ = lean_ctor_get(v_b_1939_, 0);
v_snd_1949_ = lean_ctor_get(v_b_1939_, 1);
v_isSharedCheck_2015_ = !lean_is_exclusive(v_b_1939_);
if (v_isSharedCheck_2015_ == 0)
{
v___x_1951_ = v_b_1939_;
v_isShared_1952_ = v_isSharedCheck_2015_;
goto v_resetjp_1950_;
}
else
{
lean_inc(v_snd_1949_);
lean_inc(v_fst_1948_);
lean_dec(v_b_1939_);
v___x_1951_ = lean_box(0);
v_isShared_1952_ = v_isSharedCheck_2015_;
goto v_resetjp_1950_;
}
v_resetjp_1950_:
{
lean_object* v_a_1953_; lean_object* v_df_1954_; lean_object* v_bytes_1955_; lean_object* v___x_1957_; uint8_t v_isShared_1958_; uint8_t v_isSharedCheck_2014_; 
v_a_1953_ = lean_array_uget(v_as_1936_, v_i_1938_);
v_df_1954_ = lean_ctor_get(v_a_1953_, 0);
v_bytes_1955_ = lean_ctor_get(v_a_1953_, 1);
v_isSharedCheck_2014_ = !lean_is_exclusive(v_a_1953_);
if (v_isSharedCheck_2014_ == 0)
{
v___x_1957_ = v_a_1953_;
v_isShared_1958_ = v_isSharedCheck_2014_;
goto v_resetjp_1956_;
}
else
{
lean_inc(v_bytes_1955_);
lean_inc(v_df_1954_);
lean_dec(v_a_1953_);
v___x_1957_ = lean_box(0);
v_isShared_1958_ = v_isSharedCheck_2014_;
goto v_resetjp_1956_;
}
v_resetjp_1956_:
{
lean_object* v___y_1960_; lean_object* v___y_1961_; lean_object* v___y_1962_; lean_object* v_nonempty_1969_; lean_object* v___x_2007_; uint8_t v___x_2008_; 
v_nonempty_1969_ = lean_unsigned_to_nat(0u);
v___x_2007_ = lean_unsigned_to_nat(20u);
v___x_2008_ = lean_nat_dec_eq(v_df_1954_, v___x_2007_);
if (v___x_2008_ == 0)
{
lean_object* v___x_2009_; uint8_t v___x_2010_; 
v___x_2009_ = lean_unsigned_to_nat(21u);
v___x_2010_ = lean_nat_dec_eq(v_df_1954_, v___x_2009_);
if (v___x_2010_ == 0)
{
lean_object* v___x_2012_; 
lean_dec(v_bytes_1955_);
lean_dec(v_df_1954_);
lean_del_object(v___x_1951_);
if (v_isShared_1958_ == 0)
{
lean_ctor_set(v___x_1957_, 1, v_snd_1949_);
lean_ctor_set(v___x_1957_, 0, v_fst_1948_);
v___x_2012_ = v___x_1957_;
goto v_reusejp_2011_;
}
else
{
lean_object* v_reuseFailAlloc_2013_; 
v_reuseFailAlloc_2013_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2013_, 0, v_fst_1948_);
lean_ctor_set(v_reuseFailAlloc_2013_, 1, v_snd_1949_);
v___x_2012_ = v_reuseFailAlloc_2013_;
goto v_reusejp_2011_;
}
v_reusejp_2011_:
{
v_a_1942_ = v___x_2012_;
goto v___jp_1941_;
}
}
else
{
lean_del_object(v___x_1957_);
goto v___jp_1970_;
}
}
else
{
lean_del_object(v___x_1957_);
goto v___jp_1970_;
}
v___jp_1959_:
{
lean_object* v___x_1963_; lean_object* v___x_1964_; lean_object* v___x_1965_; lean_object* v___x_1967_; 
v___x_1963_ = lp_lean1090_Lean1090_Impl_frameOracleAltitude(v___y_1962_);
lean_dec_ref(v___y_1962_);
v___x_1964_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1964_, 0, v_df_1954_);
lean_ctor_set(v___x_1964_, 1, v___y_1961_);
lean_ctor_set(v___x_1964_, 2, v___x_1963_);
v___x_1965_ = lean_array_push(v_fst_1948_, v___x_1964_);
if (v_isShared_1952_ == 0)
{
lean_ctor_set(v___x_1951_, 1, v___y_1960_);
lean_ctor_set(v___x_1951_, 0, v___x_1965_);
v___x_1967_ = v___x_1951_;
goto v_reusejp_1966_;
}
else
{
lean_object* v_reuseFailAlloc_1968_; 
v_reuseFailAlloc_1968_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1968_, 0, v___x_1965_);
lean_ctor_set(v_reuseFailAlloc_1968_, 1, v___y_1960_);
v___x_1967_ = v_reuseFailAlloc_1968_;
goto v_reusejp_1966_;
}
v_reusejp_1966_:
{
v_a_1942_ = v___x_1967_;
goto v___jp_1941_;
}
}
v___jp_1970_:
{
lean_object* v___x_1971_; 
v___x_1971_ = lp_lean1090_Lean1090_Impl_decodeFrame(v_bytes_1955_);
lean_dec(v_bytes_1955_);
if (lean_obj_tag(v___x_1971_) == 1)
{
lean_object* v_val_1972_; lean_object* v___x_1974_; uint8_t v_isShared_1975_; uint8_t v_isSharedCheck_2004_; 
v_val_1972_ = lean_ctor_get(v___x_1971_, 0);
v_isSharedCheck_2004_ = !lean_is_exclusive(v___x_1971_);
if (v_isSharedCheck_2004_ == 0)
{
v___x_1974_ = v___x_1971_;
v_isShared_1975_ = v_isSharedCheck_2004_;
goto v_resetjp_1973_;
}
else
{
lean_inc(v_val_1972_);
lean_dec(v___x_1971_);
v___x_1974_ = lean_box(0);
v_isShared_1975_ = v_isSharedCheck_2004_;
goto v_resetjp_1973_;
}
v_resetjp_1973_:
{
lean_object* v_body_1976_; 
v_body_1976_ = lean_ctor_get(v_val_1972_, 0);
if (lean_obj_tag(v_body_1976_) == 6)
{
lean_object* v_mb_1977_; uint8_t v___x_1978_; 
lean_del_object(v___x_1974_);
v_mb_1977_ = lean_ctor_get(v_body_1976_, 1);
v___x_1978_ = lean_nat_dec_eq(v_mb_1977_, v_nonempty_1969_);
if (v___x_1978_ == 0)
{
lean_object* v___x_1979_; lean_object* v___x_1980_; 
v___x_1979_ = lean_unsigned_to_nat(1u);
v___x_1980_ = lean_nat_add(v_snd_1949_, v___x_1979_);
lean_dec(v_snd_1949_);
if (v_candidate_1934_ == 0)
{
uint8_t v___x_1981_; 
v___x_1981_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1935_, v_mb_1977_);
if (v___x_1981_ == 0)
{
lean_object* v___x_1983_; uint8_t v_isShared_1984_; uint8_t v_isSharedCheck_1988_; 
lean_dec(v_df_1954_);
lean_del_object(v___x_1951_);
v_isSharedCheck_1988_ = !lean_is_exclusive(v_val_1972_);
if (v_isSharedCheck_1988_ == 0)
{
lean_object* v_unused_1989_; lean_object* v_unused_1990_; 
v_unused_1989_ = lean_ctor_get(v_val_1972_, 1);
lean_dec(v_unused_1989_);
v_unused_1990_ = lean_ctor_get(v_val_1972_, 0);
lean_dec(v_unused_1990_);
v___x_1983_ = v_val_1972_;
v_isShared_1984_ = v_isSharedCheck_1988_;
goto v_resetjp_1982_;
}
else
{
lean_dec(v_val_1972_);
v___x_1983_ = lean_box(0);
v_isShared_1984_ = v_isSharedCheck_1988_;
goto v_resetjp_1982_;
}
v_resetjp_1982_:
{
lean_object* v___x_1986_; 
if (v_isShared_1984_ == 0)
{
lean_ctor_set(v___x_1983_, 1, v___x_1980_);
lean_ctor_set(v___x_1983_, 0, v_fst_1948_);
v___x_1986_ = v___x_1983_;
goto v_reusejp_1985_;
}
else
{
lean_object* v_reuseFailAlloc_1987_; 
v_reuseFailAlloc_1987_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1987_, 0, v_fst_1948_);
lean_ctor_set(v_reuseFailAlloc_1987_, 1, v___x_1980_);
v___x_1986_ = v_reuseFailAlloc_1987_;
goto v_reusejp_1985_;
}
v_reusejp_1985_:
{
v_a_1942_ = v___x_1986_;
goto v___jp_1941_;
}
}
}
else
{
lean_inc(v_mb_1977_);
v___y_1960_ = v___x_1980_;
v___y_1961_ = v_mb_1977_;
v___y_1962_ = v_val_1972_;
goto v___jp_1959_;
}
}
else
{
lean_inc(v_mb_1977_);
v___y_1960_ = v___x_1980_;
v___y_1961_ = v_mb_1977_;
v___y_1962_ = v_val_1972_;
goto v___jp_1959_;
}
}
else
{
lean_object* v___x_1992_; uint8_t v_isShared_1993_; uint8_t v_isSharedCheck_1997_; 
lean_dec(v_df_1954_);
lean_del_object(v___x_1951_);
v_isSharedCheck_1997_ = !lean_is_exclusive(v_val_1972_);
if (v_isSharedCheck_1997_ == 0)
{
lean_object* v_unused_1998_; lean_object* v_unused_1999_; 
v_unused_1998_ = lean_ctor_get(v_val_1972_, 1);
lean_dec(v_unused_1998_);
v_unused_1999_ = lean_ctor_get(v_val_1972_, 0);
lean_dec(v_unused_1999_);
v___x_1992_ = v_val_1972_;
v_isShared_1993_ = v_isSharedCheck_1997_;
goto v_resetjp_1991_;
}
else
{
lean_dec(v_val_1972_);
v___x_1992_ = lean_box(0);
v_isShared_1993_ = v_isSharedCheck_1997_;
goto v_resetjp_1991_;
}
v_resetjp_1991_:
{
lean_object* v___x_1995_; 
if (v_isShared_1993_ == 0)
{
lean_ctor_set(v___x_1992_, 1, v_snd_1949_);
lean_ctor_set(v___x_1992_, 0, v_fst_1948_);
v___x_1995_ = v___x_1992_;
goto v_reusejp_1994_;
}
else
{
lean_object* v_reuseFailAlloc_1996_; 
v_reuseFailAlloc_1996_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1996_, 0, v_fst_1948_);
lean_ctor_set(v_reuseFailAlloc_1996_, 1, v_snd_1949_);
v___x_1995_ = v_reuseFailAlloc_1996_;
goto v_reusejp_1994_;
}
v_reusejp_1994_:
{
v_a_1942_ = v___x_1995_;
goto v___jp_1941_;
}
}
}
}
else
{
lean_object* v___x_2000_; lean_object* v___x_2002_; 
lean_dec(v_val_1972_);
lean_dec(v_df_1954_);
lean_del_object(v___x_1951_);
lean_dec(v_snd_1949_);
lean_dec(v_fst_1948_);
v___x_2000_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__1));
if (v_isShared_1975_ == 0)
{
lean_ctor_set(v___x_1974_, 0, v___x_2000_);
v___x_2002_ = v___x_1974_;
goto v_reusejp_2001_;
}
else
{
lean_object* v_reuseFailAlloc_2003_; 
v_reuseFailAlloc_2003_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2003_, 0, v___x_2000_);
v___x_2002_ = v_reuseFailAlloc_2003_;
goto v_reusejp_2001_;
}
v_reusejp_2001_:
{
return v___x_2002_;
}
}
}
}
else
{
lean_object* v___x_2005_; lean_object* v___x_2006_; 
lean_dec(v___x_1971_);
lean_dec(v_df_1954_);
lean_del_object(v___x_1951_);
lean_dec(v_snd_1949_);
lean_dec(v_fst_1948_);
v___x_2005_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__3));
v___x_2006_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2006_, 0, v___x_2005_);
return v___x_2006_;
}
}
}
}
}
v___jp_1941_:
{
size_t v___x_1943_; size_t v___x_1944_; 
v___x_1943_ = ((size_t)1ULL);
v___x_1944_ = lean_usize_add(v_i_1938_, v___x_1943_);
v_i_1938_ = v___x_1944_;
v_b_1939_ = v_a_1942_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___boxed(lean_object* v_candidate_2016_, lean_object* v_register_2017_, lean_object* v_as_2018_, lean_object* v_sz_2019_, lean_object* v_i_2020_, lean_object* v_b_2021_, lean_object* v___y_2022_){
_start:
{
uint8_t v_candidate_boxed_2023_; size_t v_sz_boxed_2024_; size_t v_i_boxed_2025_; lean_object* v_res_2026_; 
v_candidate_boxed_2023_ = lean_unbox(v_candidate_2016_);
v_sz_boxed_2024_ = lean_unbox_usize(v_sz_2019_);
lean_dec(v_sz_2019_);
v_i_boxed_2025_ = lean_unbox_usize(v_i_2020_);
lean_dec(v_i_2020_);
v_res_2026_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0(v_candidate_boxed_2023_, v_register_2017_, v_as_2018_, v_sz_boxed_2024_, v_i_boxed_2025_, v_b_2021_);
lean_dec_ref(v_as_2018_);
lean_dec(v_register_2017_);
return v_res_2026_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores(lean_object* v_inputs_2032_, lean_object* v_register_2033_, uint8_t v_candidate_2034_){
_start:
{
lean_object* v___x_2036_; size_t v_sz_2037_; size_t v___x_2038_; lean_object* v___x_2039_; 
v___x_2036_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__1));
v_sz_2037_ = lean_array_size(v_inputs_2032_);
v___x_2038_ = ((size_t)0ULL);
v___x_2039_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0(v_candidate_2034_, v_register_2033_, v_inputs_2032_, v_sz_2037_, v___x_2038_, v___x_2036_);
if (lean_obj_tag(v___x_2039_) == 0)
{
lean_object* v_a_2040_; lean_object* v___x_2042_; uint8_t v_isShared_2043_; uint8_t v_isSharedCheck_2056_; 
v_a_2040_ = lean_ctor_get(v___x_2039_, 0);
v_isSharedCheck_2056_ = !lean_is_exclusive(v___x_2039_);
if (v_isSharedCheck_2056_ == 0)
{
v___x_2042_ = v___x_2039_;
v_isShared_2043_ = v_isSharedCheck_2056_;
goto v_resetjp_2041_;
}
else
{
lean_inc(v_a_2040_);
lean_dec(v___x_2039_);
v___x_2042_ = lean_box(0);
v_isShared_2043_ = v_isSharedCheck_2056_;
goto v_resetjp_2041_;
}
v_resetjp_2041_:
{
lean_object* v_fst_2044_; lean_object* v_snd_2045_; lean_object* v___x_2047_; uint8_t v_isShared_2048_; uint8_t v_isSharedCheck_2055_; 
v_fst_2044_ = lean_ctor_get(v_a_2040_, 0);
v_snd_2045_ = lean_ctor_get(v_a_2040_, 1);
v_isSharedCheck_2055_ = !lean_is_exclusive(v_a_2040_);
if (v_isSharedCheck_2055_ == 0)
{
v___x_2047_ = v_a_2040_;
v_isShared_2048_ = v_isSharedCheck_2055_;
goto v_resetjp_2046_;
}
else
{
lean_inc(v_snd_2045_);
lean_inc(v_fst_2044_);
lean_dec(v_a_2040_);
v___x_2047_ = lean_box(0);
v_isShared_2048_ = v_isSharedCheck_2055_;
goto v_resetjp_2046_;
}
v_resetjp_2046_:
{
lean_object* v___x_2050_; 
if (v_isShared_2048_ == 0)
{
v___x_2050_ = v___x_2047_;
goto v_reusejp_2049_;
}
else
{
lean_object* v_reuseFailAlloc_2054_; 
v_reuseFailAlloc_2054_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2054_, 0, v_fst_2044_);
lean_ctor_set(v_reuseFailAlloc_2054_, 1, v_snd_2045_);
v___x_2050_ = v_reuseFailAlloc_2054_;
goto v_reusejp_2049_;
}
v_reusejp_2049_:
{
lean_object* v___x_2052_; 
if (v_isShared_2043_ == 0)
{
lean_ctor_set(v___x_2042_, 0, v___x_2050_);
v___x_2052_ = v___x_2042_;
goto v_reusejp_2051_;
}
else
{
lean_object* v_reuseFailAlloc_2053_; 
v_reuseFailAlloc_2053_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2053_, 0, v___x_2050_);
v___x_2052_ = v_reuseFailAlloc_2053_;
goto v_reusejp_2051_;
}
v_reusejp_2051_:
{
return v___x_2052_;
}
}
}
}
}
else
{
return v___x_2039_;
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___boxed(lean_object* v_inputs_2057_, lean_object* v_register_2058_, lean_object* v_candidate_2059_, lean_object* v_a_2060_){
_start:
{
uint8_t v_candidate_boxed_2061_; lean_object* v_res_2062_; 
v_candidate_boxed_2061_ = lean_unbox(v_candidate_2059_);
v_res_2062_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores(v_inputs_2057_, v_register_2058_, v_candidate_boxed_2061_);
lean_dec(v_register_2058_);
lean_dec_ref(v_inputs_2057_);
return v_res_2062_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0(uint8_t v_candidate_2063_, lean_object* v_register_2064_, lean_object* v_as_2065_, size_t v_sz_2066_, size_t v_i_2067_, lean_object* v_b_2068_){
_start:
{
uint8_t v___y_2071_; uint8_t v___x_2077_; 
v___x_2077_ = lean_usize_dec_lt(v_i_2067_, v_sz_2066_);
if (v___x_2077_ == 0)
{
lean_object* v___x_2078_; 
v___x_2078_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2078_, 0, v_b_2068_);
return v___x_2078_;
}
else
{
lean_object* v_a_2079_; 
v_a_2079_ = lean_array_uget_borrowed(v_as_2065_, v_i_2067_);
if (v_candidate_2063_ == 0)
{
lean_object* v_word_2080_; uint8_t v___x_2081_; 
v_word_2080_ = lean_ctor_get(v_a_2079_, 1);
v___x_2081_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2064_, v_word_2080_);
v___y_2071_ = v___x_2081_;
goto v___jp_2070_;
}
else
{
lean_object* v_word_2082_; uint8_t v___x_2083_; 
v_word_2082_ = lean_ctor_get(v_a_2079_, 1);
v___x_2083_ = lp_lean1090_Lean1090_Impl_commBCoreEligible(v_register_2064_, v_word_2082_);
v___y_2071_ = v___x_2083_;
goto v___jp_2070_;
}
}
v___jp_2070_:
{
lean_object* v___x_2072_; lean_object* v___x_2073_; size_t v___x_2074_; size_t v___x_2075_; 
v___x_2072_ = lean_box(v___y_2071_);
v___x_2073_ = lean_array_push(v_b_2068_, v___x_2072_);
v___x_2074_ = ((size_t)1ULL);
v___x_2075_ = lean_usize_add(v_i_2067_, v___x_2074_);
v_i_2067_ = v___x_2075_;
v_b_2068_ = v___x_2073_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0___boxed(lean_object* v_candidate_2084_, lean_object* v_register_2085_, lean_object* v_as_2086_, lean_object* v_sz_2087_, lean_object* v_i_2088_, lean_object* v_b_2089_, lean_object* v___y_2090_){
_start:
{
uint8_t v_candidate_boxed_2091_; size_t v_sz_boxed_2092_; size_t v_i_boxed_2093_; lean_object* v_res_2094_; 
v_candidate_boxed_2091_ = lean_unbox(v_candidate_2084_);
v_sz_boxed_2092_ = lean_unbox_usize(v_sz_2087_);
lean_dec(v_sz_2087_);
v_i_boxed_2093_ = lean_unbox_usize(v_i_2088_);
lean_dec(v_i_2088_);
v_res_2094_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0(v_candidate_boxed_2091_, v_register_2085_, v_as_2086_, v_sz_boxed_2092_, v_i_boxed_2093_, v_b_2089_);
lean_dec_ref(v_as_2086_);
lean_dec(v_register_2085_);
return v_res_2094_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores(lean_object* v_register_2095_, lean_object* v_inputs_2096_, uint8_t v_candidate_2097_){
_start:
{
lean_object* v___x_2099_; lean_object* v_output_2100_; lean_object* v___x_2101_; size_t v_sz_2102_; size_t v___x_2103_; lean_object* v___x_2104_; 
v___x_2099_ = lean_array_get_size(v_inputs_2096_);
v_output_2100_ = lean_mk_empty_array_with_capacity(v___x_2099_);
v___x_2101_ = lean_io_get_num_heartbeats();
v_sz_2102_ = lean_array_size(v_inputs_2096_);
v___x_2103_ = ((size_t)0ULL);
v___x_2104_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0(v_candidate_2097_, v_register_2095_, v_inputs_2096_, v_sz_2102_, v___x_2103_, v_output_2100_);
if (lean_obj_tag(v___x_2104_) == 0)
{
lean_object* v_a_2105_; lean_object* v___x_2107_; uint8_t v_isShared_2108_; uint8_t v_isSharedCheck_2115_; 
v_a_2105_ = lean_ctor_get(v___x_2104_, 0);
v_isSharedCheck_2115_ = !lean_is_exclusive(v___x_2104_);
if (v_isSharedCheck_2115_ == 0)
{
v___x_2107_ = v___x_2104_;
v_isShared_2108_ = v_isSharedCheck_2115_;
goto v_resetjp_2106_;
}
else
{
lean_inc(v_a_2105_);
lean_dec(v___x_2104_);
v___x_2107_ = lean_box(0);
v_isShared_2108_ = v_isSharedCheck_2115_;
goto v_resetjp_2106_;
}
v_resetjp_2106_:
{
lean_object* v___x_2109_; lean_object* v___x_2110_; lean_object* v___x_2111_; lean_object* v___x_2113_; 
v___x_2109_ = lean_io_get_num_heartbeats();
v___x_2110_ = lean_nat_sub(v___x_2109_, v___x_2101_);
lean_dec(v___x_2101_);
lean_dec(v___x_2109_);
v___x_2111_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2111_, 0, v_a_2105_);
lean_ctor_set(v___x_2111_, 1, v___x_2110_);
if (v_isShared_2108_ == 0)
{
lean_ctor_set(v___x_2107_, 0, v___x_2111_);
v___x_2113_ = v___x_2107_;
goto v_reusejp_2112_;
}
else
{
lean_object* v_reuseFailAlloc_2114_; 
v_reuseFailAlloc_2114_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2114_, 0, v___x_2111_);
v___x_2113_ = v_reuseFailAlloc_2114_;
goto v_reusejp_2112_;
}
v_reusejp_2112_:
{
return v___x_2113_;
}
}
}
else
{
lean_object* v_a_2116_; lean_object* v___x_2118_; uint8_t v_isShared_2119_; uint8_t v_isSharedCheck_2123_; 
lean_dec(v___x_2101_);
v_a_2116_ = lean_ctor_get(v___x_2104_, 0);
v_isSharedCheck_2123_ = !lean_is_exclusive(v___x_2104_);
if (v_isSharedCheck_2123_ == 0)
{
v___x_2118_ = v___x_2104_;
v_isShared_2119_ = v_isSharedCheck_2123_;
goto v_resetjp_2117_;
}
else
{
lean_inc(v_a_2116_);
lean_dec(v___x_2104_);
v___x_2118_ = lean_box(0);
v_isShared_2119_ = v_isSharedCheck_2123_;
goto v_resetjp_2117_;
}
v_resetjp_2117_:
{
lean_object* v___x_2121_; 
if (v_isShared_2119_ == 0)
{
v___x_2121_ = v___x_2118_;
goto v_reusejp_2120_;
}
else
{
lean_object* v_reuseFailAlloc_2122_; 
v_reuseFailAlloc_2122_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2122_, 0, v_a_2116_);
v___x_2121_ = v_reuseFailAlloc_2122_;
goto v_reusejp_2120_;
}
v_reusejp_2120_:
{
return v___x_2121_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores___boxed(lean_object* v_register_2124_, lean_object* v_inputs_2125_, lean_object* v_candidate_2126_, lean_object* v_a_2127_){
_start:
{
uint8_t v_candidate_boxed_2128_; lean_object* v_res_2129_; 
v_candidate_boxed_2128_ = lean_unbox(v_candidate_2126_);
v_res_2129_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores(v_register_2124_, v_inputs_2125_, v_candidate_boxed_2128_);
lean_dec_ref(v_inputs_2125_);
lean_dec(v_register_2124_);
return v_res_2129_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(lean_object* v_fst_2136_, lean_object* v_fst_2137_, lean_object* v_range_2138_, lean_object* v_b_2139_, lean_object* v_i_2140_){
_start:
{
lean_object* v_stop_2142_; lean_object* v_step_2143_; uint8_t v___x_2144_; 
v_stop_2142_ = lean_ctor_get(v_range_2138_, 1);
v_step_2143_ = lean_ctor_get(v_range_2138_, 2);
v___x_2144_ = lean_nat_dec_lt(v_i_2140_, v_stop_2142_);
if (v___x_2144_ == 0)
{
lean_object* v___x_2145_; 
lean_dec(v_i_2140_);
v___x_2145_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2145_, 0, v_b_2139_);
return v___x_2145_;
}
else
{
lean_object* v___x_2146_; uint8_t v___x_2147_; 
v___x_2146_ = lean_array_get_size(v_fst_2136_);
v___x_2147_ = lean_nat_dec_lt(v_i_2140_, v___x_2146_);
if (v___x_2147_ == 0)
{
lean_object* v___x_2148_; lean_object* v___x_2149_; 
lean_dec(v_i_2140_);
lean_dec_ref(v_b_2139_);
v___x_2148_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__1));
v___x_2149_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2149_, 0, v___x_2148_);
return v___x_2149_;
}
else
{
lean_object* v_snd_2150_; lean_object* v_fst_2151_; lean_object* v___x_2153_; uint8_t v_isShared_2154_; uint8_t v_isSharedCheck_2203_; 
v_snd_2150_ = lean_ctor_get(v_b_2139_, 1);
v_fst_2151_ = lean_ctor_get(v_b_2139_, 0);
v_isSharedCheck_2203_ = !lean_is_exclusive(v_b_2139_);
if (v_isSharedCheck_2203_ == 0)
{
v___x_2153_ = v_b_2139_;
v_isShared_2154_ = v_isSharedCheck_2203_;
goto v_resetjp_2152_;
}
else
{
lean_inc(v_snd_2150_);
lean_inc(v_fst_2151_);
lean_dec(v_b_2139_);
v___x_2153_ = lean_box(0);
v_isShared_2154_ = v_isSharedCheck_2203_;
goto v_resetjp_2152_;
}
v_resetjp_2152_:
{
lean_object* v_fst_2155_; lean_object* v_snd_2156_; lean_object* v___x_2158_; uint8_t v_isShared_2159_; uint8_t v_isSharedCheck_2202_; 
v_fst_2155_ = lean_ctor_get(v_snd_2150_, 0);
v_snd_2156_ = lean_ctor_get(v_snd_2150_, 1);
v_isSharedCheck_2202_ = !lean_is_exclusive(v_snd_2150_);
if (v_isSharedCheck_2202_ == 0)
{
v___x_2158_ = v_snd_2150_;
v_isShared_2159_ = v_isSharedCheck_2202_;
goto v_resetjp_2157_;
}
else
{
lean_inc(v_snd_2156_);
lean_inc(v_fst_2155_);
lean_dec(v_snd_2150_);
v___x_2158_ = lean_box(0);
v_isShared_2159_ = v_isSharedCheck_2202_;
goto v_resetjp_2157_;
}
v_resetjp_2157_:
{
lean_object* v___x_2160_; lean_object* v_df_2161_; lean_object* v_word_2162_; lean_object* v_outerAltitude_2163_; lean_object* v___x_2164_; lean_object* v___x_2165_; lean_object* v___x_2166_; lean_object* v___x_2167_; lean_object* v___x_2168_; lean_object* v___x_2169_; lean_object* v___x_2170_; lean_object* v___x_2171_; lean_object* v___x_2172_; lean_object* v___x_2173_; lean_object* v___x_2174_; lean_object* v___x_2175_; lean_object* v___x_2176_; lean_object* v___y_2178_; uint8_t v___x_2199_; 
v___x_2160_ = lean_array_fget_borrowed(v_fst_2136_, v_i_2140_);
v_df_2161_ = lean_ctor_get(v___x_2160_, 0);
v_word_2162_ = lean_ctor_get(v___x_2160_, 1);
v_outerAltitude_2163_ = lean_ctor_get(v___x_2160_, 2);
lean_inc(v_df_2161_);
v___x_2164_ = l_Nat_reprFast(v_df_2161_);
v___x_2165_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__2));
v___x_2166_ = lean_string_append(v___x_2164_, v___x_2165_);
v___x_2167_ = lean_unsigned_to_nat(0u);
lean_inc(v_outerAltitude_2163_);
v___x_2168_ = lp_lean1090_Option_repr___at___00Lean1090_Spec_instReprCommBThreat_repr_spec__0(v_outerAltitude_2163_, v___x_2167_);
v___x_2169_ = lean_unsigned_to_nat(120u);
v___x_2170_ = l_Std_Format_pretty(v___x_2168_, v___x_2169_, v___x_2167_, v___x_2167_);
v___x_2171_ = lean_string_append(v___x_2166_, v___x_2170_);
lean_dec_ref(v___x_2170_);
v___x_2172_ = lean_string_append(v___x_2171_, v___x_2165_);
lean_inc(v_word_2162_);
v___x_2173_ = l_Nat_reprFast(v_word_2162_);
v___x_2174_ = lean_string_append(v___x_2172_, v___x_2173_);
lean_dec_ref(v___x_2173_);
v___x_2175_ = lean_string_append(v___x_2174_, v___x_2165_);
v___x_2176_ = lean_array_fget_borrowed(v_fst_2137_, v_i_2140_);
v___x_2199_ = lean_unbox(v___x_2176_);
if (v___x_2199_ == 0)
{
lean_object* v___x_2200_; 
v___x_2200_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__3));
v___y_2178_ = v___x_2200_;
goto v___jp_2177_;
}
else
{
lean_object* v___x_2201_; 
v___x_2201_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__4));
v___y_2178_ = v___x_2201_;
goto v___jp_2177_;
}
v___jp_2177_:
{
lean_object* v___x_2179_; lean_object* v___x_2180_; lean_object* v___x_2181_; lean_object* v___x_2182_; lean_object* v___x_2183_; uint8_t v___x_2184_; lean_object* v___x_2185_; lean_object* v___x_2186_; lean_object* v___x_2187_; uint8_t v___x_2188_; lean_object* v___x_2189_; lean_object* v___x_2190_; lean_object* v___x_2192_; 
v___x_2179_ = lean_string_append(v___x_2175_, v___y_2178_);
v___x_2180_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__0));
v___x_2181_ = lean_string_append(v___x_2179_, v___x_2180_);
v___x_2182_ = lean_string_to_utf8(v___x_2181_);
lean_dec_ref(v___x_2181_);
v___x_2183_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(v_fst_2151_, v___x_2182_);
v___x_2184_ = lean_unbox(v___x_2176_);
v___x_2185_ = l_Bool_toNat(v___x_2184_);
v___x_2186_ = lean_nat_add(v_fst_2155_, v___x_2185_);
lean_dec(v___x_2185_);
lean_dec(v_fst_2155_);
v___x_2187_ = lean_unsigned_to_nat(20u);
v___x_2188_ = lean_nat_dec_eq(v_df_2161_, v___x_2187_);
v___x_2189_ = l_Bool_toNat(v___x_2188_);
v___x_2190_ = lean_nat_add(v_snd_2156_, v___x_2189_);
lean_dec(v___x_2189_);
lean_dec(v_snd_2156_);
if (v_isShared_2159_ == 0)
{
lean_ctor_set(v___x_2158_, 1, v___x_2190_);
lean_ctor_set(v___x_2158_, 0, v___x_2186_);
v___x_2192_ = v___x_2158_;
goto v_reusejp_2191_;
}
else
{
lean_object* v_reuseFailAlloc_2198_; 
v_reuseFailAlloc_2198_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2198_, 0, v___x_2186_);
lean_ctor_set(v_reuseFailAlloc_2198_, 1, v___x_2190_);
v___x_2192_ = v_reuseFailAlloc_2198_;
goto v_reusejp_2191_;
}
v_reusejp_2191_:
{
lean_object* v___x_2194_; 
if (v_isShared_2154_ == 0)
{
lean_ctor_set(v___x_2153_, 1, v___x_2192_);
lean_ctor_set(v___x_2153_, 0, v___x_2183_);
v___x_2194_ = v___x_2153_;
goto v_reusejp_2193_;
}
else
{
lean_object* v_reuseFailAlloc_2197_; 
v_reuseFailAlloc_2197_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2197_, 0, v___x_2183_);
lean_ctor_set(v_reuseFailAlloc_2197_, 1, v___x_2192_);
v___x_2194_ = v_reuseFailAlloc_2197_;
goto v_reusejp_2193_;
}
v_reusejp_2193_:
{
lean_object* v___x_2195_; 
v___x_2195_ = lean_nat_add(v_i_2140_, v_step_2143_);
lean_dec(v_i_2140_);
v_b_2139_ = v___x_2194_;
v_i_2140_ = v___x_2195_;
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
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___boxed(lean_object* v_fst_2204_, lean_object* v_fst_2205_, lean_object* v_range_2206_, lean_object* v_b_2207_, lean_object* v_i_2208_, lean_object* v___y_2209_){
_start:
{
lean_object* v_res_2210_; 
v_res_2210_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(v_fst_2204_, v_fst_2205_, v_range_2206_, v_b_2207_, v_i_2208_);
lean_dec_ref(v_range_2206_);
lean_dec_ref(v_fst_2205_);
lean_dec_ref(v_fst_2204_);
return v_res_2210_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__15(void){
_start:
{
lean_object* v___x_2233_; lean_object* v___x_2234_; 
v___x_2233_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__14));
v___x_2234_ = lean_string_utf8_byte_size(v___x_2233_);
return v___x_2234_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode(lean_object* v_mode_2235_, lean_object* v_register_2236_, lean_object* v_inputs_2237_, uint8_t v_wait_2238_){
_start:
{
lean_object* v___y_2241_; lean_object* v___y_2242_; lean_object* v___y_2243_; lean_object* v___y_2244_; lean_object* v___y_2245_; lean_object* v___y_2246_; uint8_t v___y_2247_; lean_object* v___y_2248_; lean_object* v___y_2249_; lean_object* v___y_2250_; lean_object* v___y_2251_; uint8_t v___y_2397_; lean_object* v___x_2434_; lean_object* v___x_2435_; lean_object* v___x_2436_; uint8_t v___x_2437_; 
v___x_2434_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__14));
v___x_2435_ = lean_string_utf8_byte_size(v_mode_2235_);
v___x_2436_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__15, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__15_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__15);
v___x_2437_ = lean_nat_dec_le(v___x_2436_, v___x_2435_);
if (v___x_2437_ == 0)
{
v___y_2397_ = v___x_2437_;
goto v___jp_2396_;
}
else
{
lean_object* v___x_2438_; uint8_t v___x_2439_; 
v___x_2438_ = lean_unsigned_to_nat(0u);
v___x_2439_ = lean_string_memcmp(v_mode_2235_, v___x_2434_, v___x_2438_, v___x_2438_, v___x_2436_);
v___y_2397_ = v___x_2439_;
goto v___jp_2396_;
}
v___jp_2240_:
{
lean_object* v___x_2252_; lean_object* v___x_2253_; lean_object* v___x_2254_; lean_object* v___x_2255_; lean_object* v___x_2256_; lean_object* v___x_2257_; lean_object* v___x_2258_; lean_object* v___x_2259_; lean_object* v___x_2260_; lean_object* v___x_2261_; lean_object* v___x_2262_; 
lean_inc_ref(v___y_2251_);
v___x_2252_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_2252_, 0, v___y_2251_);
lean_inc_ref(v___y_2250_);
v___x_2253_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2253_, 0, v___y_2250_);
lean_ctor_set(v___x_2253_, 1, v___x_2252_);
v___x_2254_ = lean_box(0);
lean_inc_ref(v___x_2253_);
v___x_2255_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2255_, 0, v___x_2253_);
lean_ctor_set(v___x_2255_, 1, v___x_2254_);
lean_inc_ref(v___y_2242_);
v___x_2256_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2256_, 0, v___y_2242_);
lean_ctor_set(v___x_2256_, 1, v___x_2255_);
v___x_2257_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2257_, 0, v___y_2249_);
lean_ctor_set(v___x_2257_, 1, v___x_2256_);
v___x_2258_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2258_, 0, v___y_2245_);
lean_ctor_set(v___x_2258_, 1, v___x_2257_);
lean_inc_ref(v___y_2241_);
v___x_2259_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2259_, 0, v___y_2241_);
lean_ctor_set(v___x_2259_, 1, v___x_2258_);
lean_inc_ref(v___y_2248_);
v___x_2260_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2260_, 0, v___y_2248_);
lean_ctor_set(v___x_2260_, 1, v___x_2259_);
v___x_2261_ = l_Lean_Json_mkObj(v___x_2260_);
lean_dec_ref_known(v___x_2260_, 2);
v___x_2262_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_2261_);
if (lean_obj_tag(v___x_2262_) == 0)
{
lean_object* v___x_2264_; uint8_t v_isShared_2265_; uint8_t v_isSharedCheck_2394_; 
v_isSharedCheck_2394_ = !lean_is_exclusive(v___x_2262_);
if (v_isSharedCheck_2394_ == 0)
{
lean_object* v_unused_2395_; 
v_unused_2395_ = lean_ctor_get(v___x_2262_, 0);
lean_dec(v_unused_2395_);
v___x_2264_ = v___x_2262_;
v_isShared_2265_ = v_isSharedCheck_2394_;
goto v_resetjp_2263_;
}
else
{
lean_dec(v___x_2262_);
v___x_2264_ = lean_box(0);
v_isShared_2265_ = v_isSharedCheck_2394_;
goto v_resetjp_2263_;
}
v_resetjp_2263_:
{
lean_object* v___x_2266_; lean_object* v___x_2267_; 
v___x_2266_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__11));
v___x_2267_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_wait_2238_, v___x_2266_);
if (lean_obj_tag(v___x_2267_) == 0)
{
lean_object* v___x_2269_; uint8_t v_isShared_2270_; uint8_t v_isSharedCheck_2392_; 
v_isSharedCheck_2392_ = !lean_is_exclusive(v___x_2267_);
if (v_isSharedCheck_2392_ == 0)
{
lean_object* v_unused_2393_; 
v_unused_2393_ = lean_ctor_get(v___x_2267_, 0);
lean_dec(v_unused_2393_);
v___x_2269_ = v___x_2267_;
v_isShared_2270_ = v_isSharedCheck_2392_;
goto v_resetjp_2268_;
}
else
{
lean_dec(v___x_2267_);
v___x_2269_ = lean_box(0);
v_isShared_2270_ = v_isSharedCheck_2392_;
goto v_resetjp_2268_;
}
v_resetjp_2268_:
{
lean_object* v___x_2271_; 
v___x_2271_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores(v_register_2236_, v___y_2243_, v___y_2247_);
if (lean_obj_tag(v___x_2271_) == 0)
{
lean_object* v_a_2272_; lean_object* v_fst_2273_; lean_object* v_snd_2274_; lean_object* v___x_2276_; uint8_t v_isShared_2277_; uint8_t v_isSharedCheck_2383_; 
v_a_2272_ = lean_ctor_get(v___x_2271_, 0);
lean_inc(v_a_2272_);
lean_dec_ref_known(v___x_2271_, 1);
v_fst_2273_ = lean_ctor_get(v_a_2272_, 0);
v_snd_2274_ = lean_ctor_get(v_a_2272_, 1);
v_isSharedCheck_2383_ = !lean_is_exclusive(v_a_2272_);
if (v_isSharedCheck_2383_ == 0)
{
v___x_2276_ = v_a_2272_;
v_isShared_2277_ = v_isSharedCheck_2383_;
goto v_resetjp_2275_;
}
else
{
lean_inc(v_snd_2274_);
lean_inc(v_fst_2273_);
lean_dec(v_a_2272_);
v___x_2276_ = lean_box(0);
v_isShared_2277_ = v_isSharedCheck_2383_;
goto v_resetjp_2275_;
}
v_resetjp_2275_:
{
lean_object* v___x_2278_; lean_object* v___x_2280_; 
v___x_2278_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__13));
lean_inc_ref(v___y_2244_);
if (v_isShared_2277_ == 0)
{
lean_ctor_set(v___x_2276_, 1, v___x_2278_);
lean_ctor_set(v___x_2276_, 0, v___y_2244_);
v___x_2280_ = v___x_2276_;
goto v_reusejp_2279_;
}
else
{
lean_object* v_reuseFailAlloc_2382_; 
v_reuseFailAlloc_2382_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2382_, 0, v___y_2244_);
lean_ctor_set(v_reuseFailAlloc_2382_, 1, v___x_2278_);
v___x_2280_ = v_reuseFailAlloc_2382_;
goto v_reusejp_2279_;
}
v_reusejp_2279_:
{
lean_object* v___x_2281_; lean_object* v___x_2282_; lean_object* v___x_2283_; lean_object* v___x_2285_; 
v___x_2281_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__15));
v___x_2282_ = lean_array_get_size(v_fst_2273_);
v___x_2283_ = l_Lean_JsonNumber_fromNat(v___x_2282_);
if (v_isShared_2270_ == 0)
{
lean_ctor_set_tag(v___x_2269_, 2);
lean_ctor_set(v___x_2269_, 0, v___x_2283_);
v___x_2285_ = v___x_2269_;
goto v_reusejp_2284_;
}
else
{
lean_object* v_reuseFailAlloc_2381_; 
v_reuseFailAlloc_2381_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2381_, 0, v___x_2283_);
v___x_2285_ = v_reuseFailAlloc_2381_;
goto v_reusejp_2284_;
}
v_reusejp_2284_:
{
lean_object* v___x_2286_; lean_object* v___x_2287_; lean_object* v___x_2288_; lean_object* v___x_2290_; 
v___x_2286_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2286_, 0, v___x_2281_);
lean_ctor_set(v___x_2286_, 1, v___x_2285_);
v___x_2287_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__16));
v___x_2288_ = l_Lean_JsonNumber_fromNat(v_snd_2274_);
if (v_isShared_2265_ == 0)
{
lean_ctor_set_tag(v___x_2264_, 2);
lean_ctor_set(v___x_2264_, 0, v___x_2288_);
v___x_2290_ = v___x_2264_;
goto v_reusejp_2289_;
}
else
{
lean_object* v_reuseFailAlloc_2380_; 
v_reuseFailAlloc_2380_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2380_, 0, v___x_2288_);
v___x_2290_ = v_reuseFailAlloc_2380_;
goto v_reusejp_2289_;
}
v_reusejp_2289_:
{
lean_object* v___x_2291_; lean_object* v___x_2292_; lean_object* v___x_2293_; lean_object* v___x_2294_; lean_object* v___x_2295_; lean_object* v___x_2296_; lean_object* v___x_2297_; 
v___x_2291_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2291_, 0, v___x_2287_);
lean_ctor_set(v___x_2291_, 1, v___x_2290_);
v___x_2292_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2292_, 0, v___x_2291_);
lean_ctor_set(v___x_2292_, 1, v___x_2254_);
lean_inc_ref(v___x_2292_);
v___x_2293_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2293_, 0, v___x_2286_);
lean_ctor_set(v___x_2293_, 1, v___x_2292_);
lean_inc_ref(v___y_2241_);
v___x_2294_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2294_, 0, v___y_2241_);
lean_ctor_set(v___x_2294_, 1, v___x_2293_);
v___x_2295_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2295_, 0, v___x_2280_);
lean_ctor_set(v___x_2295_, 1, v___x_2294_);
v___x_2296_ = l_Lean_Json_mkObj(v___x_2295_);
lean_dec_ref_known(v___x_2295_, 2);
v___x_2297_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_2296_);
if (lean_obj_tag(v___x_2297_) == 0)
{
lean_object* v___x_2299_; uint8_t v_isShared_2300_; uint8_t v_isSharedCheck_2378_; 
v_isSharedCheck_2378_ = !lean_is_exclusive(v___x_2297_);
if (v_isSharedCheck_2378_ == 0)
{
lean_object* v_unused_2379_; 
v_unused_2379_ = lean_ctor_get(v___x_2297_, 0);
lean_dec(v_unused_2379_);
v___x_2299_ = v___x_2297_;
v_isShared_2300_ = v_isSharedCheck_2378_;
goto v_resetjp_2298_;
}
else
{
lean_dec(v___x_2297_);
v___x_2299_ = lean_box(0);
v_isShared_2300_ = v_isSharedCheck_2378_;
goto v_resetjp_2298_;
}
v_resetjp_2298_:
{
lean_object* v___x_2301_; lean_object* v___x_2302_; 
v___x_2301_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__17));
v___x_2302_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_wait_2238_, v___x_2301_);
if (lean_obj_tag(v___x_2302_) == 0)
{
lean_object* v___x_2304_; uint8_t v_isShared_2305_; uint8_t v_isSharedCheck_2376_; 
v_isSharedCheck_2376_ = !lean_is_exclusive(v___x_2302_);
if (v_isSharedCheck_2376_ == 0)
{
lean_object* v_unused_2377_; 
v_unused_2377_ = lean_ctor_get(v___x_2302_, 0);
lean_dec(v_unused_2377_);
v___x_2304_ = v___x_2302_;
v_isShared_2305_ = v_isSharedCheck_2376_;
goto v_resetjp_2303_;
}
else
{
lean_dec(v___x_2302_);
v___x_2304_ = lean_box(0);
v_isShared_2305_ = v_isSharedCheck_2376_;
goto v_resetjp_2303_;
}
v_resetjp_2303_:
{
uint8_t v___x_2306_; 
v___x_2306_ = lean_nat_dec_eq(v___x_2282_, v___y_2246_);
if (v___x_2306_ == 0)
{
lean_object* v___x_2307_; lean_object* v___x_2309_; 
lean_del_object(v___x_2299_);
lean_dec_ref_known(v___x_2292_, 2);
lean_dec(v_fst_2273_);
lean_dec_ref_known(v___x_2253_, 2);
lean_dec(v___y_2246_);
lean_dec_ref(v___y_2243_);
lean_dec_ref(v___y_2241_);
lean_dec(v_register_2236_);
v___x_2307_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__1));
if (v_isShared_2305_ == 0)
{
lean_ctor_set_tag(v___x_2304_, 1);
lean_ctor_set(v___x_2304_, 0, v___x_2307_);
v___x_2309_ = v___x_2304_;
goto v_reusejp_2308_;
}
else
{
lean_object* v_reuseFailAlloc_2310_; 
v_reuseFailAlloc_2310_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2310_, 0, v___x_2307_);
v___x_2309_ = v_reuseFailAlloc_2310_;
goto v_reusejp_2308_;
}
v_reusejp_2308_:
{
return v___x_2309_;
}
}
else
{
lean_object* v___x_2311_; lean_object* v___x_2312_; lean_object* v___x_2313_; lean_object* v___x_2314_; lean_object* v___x_2315_; 
lean_del_object(v___x_2304_);
v___x_2311_ = lean_unsigned_to_nat(0u);
v___x_2312_ = lean_unsigned_to_nat(1u);
v___x_2313_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_2313_, 0, v___x_2311_);
lean_ctor_set(v___x_2313_, 1, v___x_2282_);
lean_ctor_set(v___x_2313_, 2, v___x_2312_);
v___x_2314_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__3));
v___x_2315_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(v___y_2243_, v_fst_2273_, v___x_2313_, v___x_2314_, v___x_2311_);
lean_dec_ref_known(v___x_2313_, 3);
lean_dec(v_fst_2273_);
lean_dec_ref(v___y_2243_);
if (lean_obj_tag(v___x_2315_) == 0)
{
lean_object* v_a_2316_; lean_object* v_snd_2317_; lean_object* v_fst_2318_; lean_object* v___x_2320_; uint8_t v_isShared_2321_; uint8_t v_isSharedCheck_2367_; 
v_a_2316_ = lean_ctor_get(v___x_2315_, 0);
lean_inc(v_a_2316_);
lean_dec_ref_known(v___x_2315_, 1);
v_snd_2317_ = lean_ctor_get(v_a_2316_, 1);
v_fst_2318_ = lean_ctor_get(v_a_2316_, 0);
v_isSharedCheck_2367_ = !lean_is_exclusive(v_a_2316_);
if (v_isSharedCheck_2367_ == 0)
{
v___x_2320_ = v_a_2316_;
v_isShared_2321_ = v_isSharedCheck_2367_;
goto v_resetjp_2319_;
}
else
{
lean_inc(v_snd_2317_);
lean_inc(v_fst_2318_);
lean_dec(v_a_2316_);
v___x_2320_ = lean_box(0);
v_isShared_2321_ = v_isSharedCheck_2367_;
goto v_resetjp_2319_;
}
v_resetjp_2319_:
{
lean_object* v_fst_2322_; lean_object* v_snd_2323_; lean_object* v___x_2325_; uint8_t v_isShared_2326_; uint8_t v_isSharedCheck_2366_; 
v_fst_2322_ = lean_ctor_get(v_snd_2317_, 0);
v_snd_2323_ = lean_ctor_get(v_snd_2317_, 1);
v_isSharedCheck_2366_ = !lean_is_exclusive(v_snd_2317_);
if (v_isSharedCheck_2366_ == 0)
{
v___x_2325_ = v_snd_2317_;
v_isShared_2326_ = v_isSharedCheck_2366_;
goto v_resetjp_2324_;
}
else
{
lean_inc(v_snd_2323_);
lean_inc(v_fst_2322_);
lean_dec(v_snd_2317_);
v___x_2325_ = lean_box(0);
v_isShared_2326_ = v_isSharedCheck_2366_;
goto v_resetjp_2324_;
}
v_resetjp_2324_:
{
lean_object* v___x_2327_; lean_object* v___x_2329_; 
v___x_2327_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__19));
lean_inc_ref(v___y_2244_);
if (v_isShared_2326_ == 0)
{
lean_ctor_set(v___x_2325_, 1, v___x_2327_);
lean_ctor_set(v___x_2325_, 0, v___y_2244_);
v___x_2329_ = v___x_2325_;
goto v_reusejp_2328_;
}
else
{
lean_object* v_reuseFailAlloc_2365_; 
v_reuseFailAlloc_2365_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2365_, 0, v___y_2244_);
lean_ctor_set(v_reuseFailAlloc_2365_, 1, v___x_2327_);
v___x_2329_ = v_reuseFailAlloc_2365_;
goto v_reusejp_2328_;
}
v_reusejp_2328_:
{
lean_object* v___x_2330_; lean_object* v___x_2331_; lean_object* v___x_2333_; 
v___x_2330_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__0));
v___x_2331_ = l_Lean_JsonNumber_fromNat(v_register_2236_);
if (v_isShared_2300_ == 0)
{
lean_ctor_set_tag(v___x_2299_, 2);
lean_ctor_set(v___x_2299_, 0, v___x_2331_);
v___x_2333_ = v___x_2299_;
goto v_reusejp_2332_;
}
else
{
lean_object* v_reuseFailAlloc_2364_; 
v_reuseFailAlloc_2364_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2364_, 0, v___x_2331_);
v___x_2333_ = v_reuseFailAlloc_2364_;
goto v_reusejp_2332_;
}
v_reusejp_2332_:
{
lean_object* v___x_2335_; 
if (v_isShared_2321_ == 0)
{
lean_ctor_set(v___x_2320_, 1, v___x_2333_);
lean_ctor_set(v___x_2320_, 0, v___x_2330_);
v___x_2335_ = v___x_2320_;
goto v_reusejp_2334_;
}
else
{
lean_object* v_reuseFailAlloc_2363_; 
v_reuseFailAlloc_2363_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2363_, 0, v___x_2330_);
lean_ctor_set(v_reuseFailAlloc_2363_, 1, v___x_2333_);
v___x_2335_ = v_reuseFailAlloc_2363_;
goto v_reusejp_2334_;
}
v_reusejp_2334_:
{
lean_object* v___x_2336_; lean_object* v___x_2337_; lean_object* v___x_2338_; lean_object* v___x_2339_; lean_object* v___x_2340_; lean_object* v___x_2341_; lean_object* v___x_2342_; lean_object* v___x_2343_; lean_object* v___x_2344_; lean_object* v___x_2345_; lean_object* v___x_2346_; lean_object* v___x_2347_; lean_object* v___x_2348_; lean_object* v___x_2349_; lean_object* v___x_2350_; lean_object* v___x_2351_; lean_object* v___x_2352_; lean_object* v___x_2353_; lean_object* v___x_2354_; lean_object* v___x_2355_; lean_object* v___x_2356_; lean_object* v___x_2357_; lean_object* v___x_2358_; lean_object* v___x_2359_; lean_object* v___x_2360_; lean_object* v___x_2361_; lean_object* v___x_2362_; 
v___x_2336_ = ((lean_object*)(l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0___closed__0));
v___x_2337_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(v_fst_2318_);
v___x_2338_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2338_, 0, v___x_2336_);
lean_ctor_set(v___x_2338_, 1, v___x_2337_);
v___x_2339_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__4));
v___x_2340_ = l_Lean_JsonNumber_fromNat(v_fst_2322_);
v___x_2341_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2341_, 0, v___x_2340_);
v___x_2342_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2342_, 0, v___x_2339_);
lean_ctor_set(v___x_2342_, 1, v___x_2341_);
v___x_2343_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__5));
lean_inc(v_snd_2323_);
v___x_2344_ = l_Lean_JsonNumber_fromNat(v_snd_2323_);
v___x_2345_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2345_, 0, v___x_2344_);
v___x_2346_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2346_, 0, v___x_2343_);
lean_ctor_set(v___x_2346_, 1, v___x_2345_);
v___x_2347_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__6));
v___x_2348_ = lean_nat_sub(v___y_2246_, v_snd_2323_);
lean_dec(v_snd_2323_);
lean_dec(v___y_2246_);
v___x_2349_ = l_Lean_JsonNumber_fromNat(v___x_2348_);
v___x_2350_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2350_, 0, v___x_2349_);
v___x_2351_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2351_, 0, v___x_2347_);
lean_ctor_set(v___x_2351_, 1, v___x_2350_);
v___x_2352_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2352_, 0, v___x_2351_);
lean_ctor_set(v___x_2352_, 1, v___x_2292_);
v___x_2353_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2353_, 0, v___x_2346_);
lean_ctor_set(v___x_2353_, 1, v___x_2352_);
v___x_2354_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2354_, 0, v___x_2342_);
lean_ctor_set(v___x_2354_, 1, v___x_2353_);
v___x_2355_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2355_, 0, v___x_2338_);
lean_ctor_set(v___x_2355_, 1, v___x_2354_);
v___x_2356_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2356_, 0, v___x_2253_);
lean_ctor_set(v___x_2356_, 1, v___x_2355_);
lean_inc_ref(v___y_2242_);
v___x_2357_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2357_, 0, v___y_2242_);
lean_ctor_set(v___x_2357_, 1, v___x_2356_);
v___x_2358_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2358_, 0, v___x_2335_);
lean_ctor_set(v___x_2358_, 1, v___x_2357_);
v___x_2359_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2359_, 0, v___y_2241_);
lean_ctor_set(v___x_2359_, 1, v___x_2358_);
v___x_2360_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2360_, 0, v___x_2329_);
lean_ctor_set(v___x_2360_, 1, v___x_2359_);
v___x_2361_ = l_Lean_Json_mkObj(v___x_2360_);
lean_dec_ref_known(v___x_2360_, 2);
v___x_2362_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_2361_);
return v___x_2362_;
}
}
}
}
}
}
else
{
lean_object* v_a_2368_; lean_object* v___x_2370_; uint8_t v_isShared_2371_; uint8_t v_isSharedCheck_2375_; 
lean_del_object(v___x_2299_);
lean_dec_ref_known(v___x_2292_, 2);
lean_dec_ref_known(v___x_2253_, 2);
lean_dec(v___y_2246_);
lean_dec_ref(v___y_2241_);
lean_dec(v_register_2236_);
v_a_2368_ = lean_ctor_get(v___x_2315_, 0);
v_isSharedCheck_2375_ = !lean_is_exclusive(v___x_2315_);
if (v_isSharedCheck_2375_ == 0)
{
v___x_2370_ = v___x_2315_;
v_isShared_2371_ = v_isSharedCheck_2375_;
goto v_resetjp_2369_;
}
else
{
lean_inc(v_a_2368_);
lean_dec(v___x_2315_);
v___x_2370_ = lean_box(0);
v_isShared_2371_ = v_isSharedCheck_2375_;
goto v_resetjp_2369_;
}
v_resetjp_2369_:
{
lean_object* v___x_2373_; 
if (v_isShared_2371_ == 0)
{
v___x_2373_ = v___x_2370_;
goto v_reusejp_2372_;
}
else
{
lean_object* v_reuseFailAlloc_2374_; 
v_reuseFailAlloc_2374_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2374_, 0, v_a_2368_);
v___x_2373_ = v_reuseFailAlloc_2374_;
goto v_reusejp_2372_;
}
v_reusejp_2372_:
{
return v___x_2373_;
}
}
}
}
}
}
else
{
lean_del_object(v___x_2299_);
lean_dec_ref_known(v___x_2292_, 2);
lean_dec(v_fst_2273_);
lean_dec_ref_known(v___x_2253_, 2);
lean_dec(v___y_2246_);
lean_dec_ref(v___y_2243_);
lean_dec_ref(v___y_2241_);
lean_dec(v_register_2236_);
return v___x_2302_;
}
}
}
else
{
lean_dec_ref_known(v___x_2292_, 2);
lean_dec(v_fst_2273_);
lean_dec_ref_known(v___x_2253_, 2);
lean_dec(v___y_2246_);
lean_dec_ref(v___y_2243_);
lean_dec_ref(v___y_2241_);
lean_dec(v_register_2236_);
return v___x_2297_;
}
}
}
}
}
}
else
{
lean_object* v_a_2384_; lean_object* v___x_2386_; uint8_t v_isShared_2387_; uint8_t v_isSharedCheck_2391_; 
lean_del_object(v___x_2269_);
lean_del_object(v___x_2264_);
lean_dec_ref_known(v___x_2253_, 2);
lean_dec(v___y_2246_);
lean_dec_ref(v___y_2243_);
lean_dec_ref(v___y_2241_);
lean_dec(v_register_2236_);
v_a_2384_ = lean_ctor_get(v___x_2271_, 0);
v_isSharedCheck_2391_ = !lean_is_exclusive(v___x_2271_);
if (v_isSharedCheck_2391_ == 0)
{
v___x_2386_ = v___x_2271_;
v_isShared_2387_ = v_isSharedCheck_2391_;
goto v_resetjp_2385_;
}
else
{
lean_inc(v_a_2384_);
lean_dec(v___x_2271_);
v___x_2386_ = lean_box(0);
v_isShared_2387_ = v_isSharedCheck_2391_;
goto v_resetjp_2385_;
}
v_resetjp_2385_:
{
lean_object* v___x_2389_; 
if (v_isShared_2387_ == 0)
{
v___x_2389_ = v___x_2386_;
goto v_reusejp_2388_;
}
else
{
lean_object* v_reuseFailAlloc_2390_; 
v_reuseFailAlloc_2390_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2390_, 0, v_a_2384_);
v___x_2389_ = v_reuseFailAlloc_2390_;
goto v_reusejp_2388_;
}
v_reusejp_2388_:
{
return v___x_2389_;
}
}
}
}
}
else
{
lean_del_object(v___x_2264_);
lean_dec_ref_known(v___x_2253_, 2);
lean_dec(v___y_2246_);
lean_dec_ref(v___y_2243_);
lean_dec_ref(v___y_2241_);
lean_dec(v_register_2236_);
return v___x_2267_;
}
}
}
else
{
lean_dec_ref_known(v___x_2253_, 2);
lean_dec(v___y_2246_);
lean_dec_ref(v___y_2243_);
lean_dec_ref(v___y_2241_);
lean_dec(v_register_2236_);
return v___x_2262_;
}
}
v___jp_2396_:
{
lean_object* v___x_2398_; 
v___x_2398_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores(v_inputs_2237_, v_register_2236_, v___y_2397_);
if (lean_obj_tag(v___x_2398_) == 0)
{
lean_object* v_a_2399_; lean_object* v_fst_2400_; lean_object* v_snd_2401_; lean_object* v___x_2403_; uint8_t v_isShared_2404_; uint8_t v_isSharedCheck_2425_; 
v_a_2399_ = lean_ctor_get(v___x_2398_, 0);
lean_inc(v_a_2399_);
lean_dec_ref_known(v___x_2398_, 1);
v_fst_2400_ = lean_ctor_get(v_a_2399_, 0);
v_snd_2401_ = lean_ctor_get(v_a_2399_, 1);
v_isSharedCheck_2425_ = !lean_is_exclusive(v_a_2399_);
if (v_isSharedCheck_2425_ == 0)
{
v___x_2403_ = v_a_2399_;
v_isShared_2404_ = v_isSharedCheck_2425_;
goto v_resetjp_2402_;
}
else
{
lean_inc(v_snd_2401_);
lean_inc(v_fst_2400_);
lean_dec(v_a_2399_);
v___x_2403_ = lean_box(0);
v_isShared_2404_ = v_isSharedCheck_2425_;
goto v_resetjp_2402_;
}
v_resetjp_2402_:
{
lean_object* v___x_2405_; lean_object* v___x_2406_; lean_object* v___x_2407_; lean_object* v___x_2408_; lean_object* v___x_2410_; 
v___x_2405_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__0));
v___x_2406_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__3));
v___x_2407_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__4));
v___x_2408_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_2408_, 0, v_mode_2235_);
if (v_isShared_2404_ == 0)
{
lean_ctor_set(v___x_2403_, 1, v___x_2408_);
lean_ctor_set(v___x_2403_, 0, v___x_2407_);
v___x_2410_ = v___x_2403_;
goto v_reusejp_2409_;
}
else
{
lean_object* v_reuseFailAlloc_2424_; 
v_reuseFailAlloc_2424_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2424_, 0, v___x_2407_);
lean_ctor_set(v_reuseFailAlloc_2424_, 1, v___x_2408_);
v___x_2410_ = v_reuseFailAlloc_2424_;
goto v_reusejp_2409_;
}
v_reusejp_2409_:
{
lean_object* v___x_2411_; lean_object* v___x_2412_; lean_object* v___x_2413_; lean_object* v___x_2414_; lean_object* v___x_2415_; lean_object* v___x_2416_; lean_object* v___x_2417_; lean_object* v___x_2418_; lean_object* v___x_2419_; lean_object* v___x_2420_; lean_object* v___x_2421_; 
v___x_2411_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__5));
v___x_2412_ = lean_array_get_size(v_fst_2400_);
v___x_2413_ = l_Lean_JsonNumber_fromNat(v___x_2412_);
v___x_2414_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2414_, 0, v___x_2413_);
v___x_2415_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2415_, 0, v___x_2411_);
lean_ctor_set(v___x_2415_, 1, v___x_2414_);
v___x_2416_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__7));
v___x_2417_ = l_Lean_JsonNumber_fromNat(v_snd_2401_);
v___x_2418_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2418_, 0, v___x_2417_);
v___x_2419_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2419_, 0, v___x_2416_);
lean_ctor_set(v___x_2419_, 1, v___x_2418_);
v___x_2420_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__10));
v___x_2421_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__11));
if (v___y_2397_ == 0)
{
lean_object* v___x_2422_; 
v___x_2422_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__12));
v___y_2241_ = v___x_2410_;
v___y_2242_ = v___x_2420_;
v___y_2243_ = v_fst_2400_;
v___y_2244_ = v___x_2405_;
v___y_2245_ = v___x_2415_;
v___y_2246_ = v___x_2412_;
v___y_2247_ = v___y_2397_;
v___y_2248_ = v___x_2406_;
v___y_2249_ = v___x_2419_;
v___y_2250_ = v___x_2421_;
v___y_2251_ = v___x_2422_;
goto v___jp_2240_;
}
else
{
lean_object* v___x_2423_; 
v___x_2423_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__13));
v___y_2241_ = v___x_2410_;
v___y_2242_ = v___x_2420_;
v___y_2243_ = v_fst_2400_;
v___y_2244_ = v___x_2405_;
v___y_2245_ = v___x_2415_;
v___y_2246_ = v___x_2412_;
v___y_2247_ = v___y_2397_;
v___y_2248_ = v___x_2406_;
v___y_2249_ = v___x_2419_;
v___y_2250_ = v___x_2421_;
v___y_2251_ = v___x_2423_;
goto v___jp_2240_;
}
}
}
}
else
{
lean_object* v_a_2426_; lean_object* v___x_2428_; uint8_t v_isShared_2429_; uint8_t v_isSharedCheck_2433_; 
lean_dec(v_register_2236_);
lean_dec_ref(v_mode_2235_);
v_a_2426_ = lean_ctor_get(v___x_2398_, 0);
v_isSharedCheck_2433_ = !lean_is_exclusive(v___x_2398_);
if (v_isSharedCheck_2433_ == 0)
{
v___x_2428_ = v___x_2398_;
v_isShared_2429_ = v_isSharedCheck_2433_;
goto v_resetjp_2427_;
}
else
{
lean_inc(v_a_2426_);
lean_dec(v___x_2398_);
v___x_2428_ = lean_box(0);
v_isShared_2429_ = v_isSharedCheck_2433_;
goto v_resetjp_2427_;
}
v_resetjp_2427_:
{
lean_object* v___x_2431_; 
if (v_isShared_2429_ == 0)
{
v___x_2431_ = v___x_2428_;
goto v_reusejp_2430_;
}
else
{
lean_object* v_reuseFailAlloc_2432_; 
v_reuseFailAlloc_2432_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2432_, 0, v_a_2426_);
v___x_2431_ = v_reuseFailAlloc_2432_;
goto v_reusejp_2430_;
}
v_reusejp_2430_:
{
return v___x_2431_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___boxed(lean_object* v_mode_2440_, lean_object* v_register_2441_, lean_object* v_inputs_2442_, lean_object* v_wait_2443_, lean_object* v_a_2444_){
_start:
{
uint8_t v_wait_boxed_2445_; lean_object* v_res_2446_; 
v_wait_boxed_2445_ = lean_unbox(v_wait_2443_);
v_res_2446_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode(v_mode_2440_, v_register_2441_, v_inputs_2442_, v_wait_boxed_2445_);
lean_dec_ref(v_inputs_2442_);
return v_res_2446_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0(lean_object* v_fst_2447_, lean_object* v_fst_2448_, lean_object* v_range_2449_, lean_object* v_b_2450_, lean_object* v_i_2451_, lean_object* v_hs_2452_, lean_object* v_hl_2453_){
_start:
{
lean_object* v___x_2455_; 
v___x_2455_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(v_fst_2447_, v_fst_2448_, v_range_2449_, v_b_2450_, v_i_2451_);
return v___x_2455_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___boxed(lean_object* v_fst_2456_, lean_object* v_fst_2457_, lean_object* v_range_2458_, lean_object* v_b_2459_, lean_object* v_i_2460_, lean_object* v_hs_2461_, lean_object* v_hl_2462_, lean_object* v___y_2463_){
_start:
{
lean_object* v_res_2464_; 
v_res_2464_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0(v_fst_2456_, v_fst_2457_, v_range_2458_, v_b_2459_, v_i_2460_, v_hs_2461_, v_hl_2462_);
lean_dec_ref(v_range_2458_);
lean_dec_ref(v_fst_2457_);
lean_dec_ref(v_fst_2456_);
return v_res_2464_;
}
}
LEAN_EXPORT uint8_t l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(lean_object* v_a_2465_, lean_object* v_x_2466_){
_start:
{
if (lean_obj_tag(v_x_2466_) == 0)
{
uint8_t v___x_2467_; 
v___x_2467_ = 0;
return v___x_2467_;
}
else
{
lean_object* v_head_2468_; lean_object* v_tail_2469_; uint8_t v___x_2470_; 
v_head_2468_ = lean_ctor_get(v_x_2466_, 0);
v_tail_2469_ = lean_ctor_get(v_x_2466_, 1);
v___x_2470_ = lean_string_dec_eq(v_a_2465_, v_head_2468_);
if (v___x_2470_ == 0)
{
v_x_2466_ = v_tail_2469_;
goto _start;
}
else
{
return v___x_2470_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1___boxed(lean_object* v_a_2472_, lean_object* v_x_2473_){
_start:
{
uint8_t v_res_2474_; lean_object* v_r_2475_; 
v_res_2474_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v_a_2472_, v_x_2473_);
lean_dec(v_x_2473_);
lean_dec_ref(v_a_2472_);
v_r_2475_ = lean_box(v_res_2474_);
return v_r_2475_;
}
}
LEAN_EXPORT uint8_t l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0(lean_object* v_x_2478_){
_start:
{
if (lean_obj_tag(v_x_2478_) == 0)
{
uint8_t v___x_2479_; 
v___x_2479_ = 0;
return v___x_2479_;
}
else
{
lean_object* v_head_2480_; lean_object* v_tail_2481_; lean_object* v___x_2482_; uint8_t v___x_2483_; 
v_head_2480_ = lean_ctor_get(v_x_2478_, 0);
v_tail_2481_ = lean_ctor_get(v_x_2478_, 1);
v___x_2482_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__0));
v___x_2483_ = lean_string_dec_eq(v_head_2480_, v___x_2482_);
if (v___x_2483_ == 0)
{
lean_object* v___x_2484_; uint8_t v___x_2485_; 
v___x_2484_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__1));
v___x_2485_ = lean_string_dec_eq(v_head_2480_, v___x_2484_);
if (v___x_2485_ == 0)
{
uint8_t v___x_2486_; 
v___x_2486_ = 1;
return v___x_2486_;
}
else
{
v_x_2478_ = v_tail_2481_;
goto _start;
}
}
else
{
v_x_2478_ = v_tail_2481_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___boxed(lean_object* v_x_2489_){
_start:
{
uint8_t v_res_2490_; lean_object* v_r_2491_; 
v_res_2490_ = l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0(v_x_2489_);
lean_dec(v_x_2489_);
v_r_2491_ = lean_box(v_res_2490_);
return v_r_2491_;
}
}
LEAN_EXPORT lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute(lean_object* v_args_2501_){
_start:
{
if (lean_obj_tag(v_args_2501_) == 1)
{
lean_object* v_tail_2506_; 
v_tail_2506_ = lean_ctor_get(v_args_2501_, 1);
lean_inc(v_tail_2506_);
if (lean_obj_tag(v_tail_2506_) == 1)
{
lean_object* v_head_2507_; lean_object* v_head_2508_; lean_object* v_tail_2509_; uint8_t v___x_2510_; 
v_head_2507_ = lean_ctor_get(v_args_2501_, 0);
lean_inc(v_head_2507_);
lean_dec_ref_known(v_args_2501_, 2);
v_head_2508_ = lean_ctor_get(v_tail_2506_, 0);
lean_inc(v_head_2508_);
v_tail_2509_ = lean_ctor_get(v_tail_2506_, 1);
lean_inc(v_tail_2509_);
lean_dec_ref_known(v_tail_2506_, 2);
v___x_2510_ = l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0(v_tail_2509_);
if (v___x_2510_ == 0)
{
lean_object* v___x_2511_; 
v___x_2511_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs(v_head_2508_);
lean_dec(v_head_2508_);
if (lean_obj_tag(v___x_2511_) == 0)
{
lean_object* v_a_2512_; lean_object* v___x_2514_; uint8_t v_isShared_2515_; uint8_t v_isSharedCheck_2532_; 
v_a_2512_ = lean_ctor_get(v___x_2511_, 0);
v_isSharedCheck_2532_ = !lean_is_exclusive(v___x_2511_);
if (v_isSharedCheck_2532_ == 0)
{
v___x_2514_ = v___x_2511_;
v_isShared_2515_ = v_isSharedCheck_2532_;
goto v_resetjp_2513_;
}
else
{
lean_inc(v_a_2512_);
lean_dec(v___x_2511_);
v___x_2514_ = lean_box(0);
v_isShared_2515_ = v_isSharedCheck_2532_;
goto v_resetjp_2513_;
}
v_resetjp_2513_:
{
lean_object* v___x_2516_; 
v___x_2516_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister(v_head_2507_);
if (lean_obj_tag(v___x_2516_) == 1)
{
lean_object* v_val_2517_; lean_object* v___x_2518_; uint8_t v___x_2519_; 
v_val_2517_ = lean_ctor_get(v___x_2516_, 0);
lean_inc(v_val_2517_);
lean_dec_ref_known(v___x_2516_, 1);
v___x_2518_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__0));
v___x_2519_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v___x_2518_, v_tail_2509_);
if (v___x_2519_ == 0)
{
lean_object* v___x_2520_; uint8_t v___x_2521_; lean_object* v___x_2522_; 
lean_del_object(v___x_2514_);
v___x_2520_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__1));
v___x_2521_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v___x_2520_, v_tail_2509_);
lean_dec(v_tail_2509_);
v___x_2522_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode(v_head_2507_, v_val_2517_, v_a_2512_, v___x_2521_);
lean_dec(v_a_2512_);
return v___x_2522_;
}
else
{
lean_object* v___x_2523_; lean_object* v___x_2525_; 
lean_dec(v_val_2517_);
lean_dec(v_a_2512_);
lean_dec(v_tail_2509_);
lean_dec(v_head_2507_);
v___x_2523_ = ((lean_object*)(l_Lean1090_Diagnostics_DecodeCosts_execute___closed__3));
if (v_isShared_2515_ == 0)
{
lean_ctor_set_tag(v___x_2514_, 1);
lean_ctor_set(v___x_2514_, 0, v___x_2523_);
v___x_2525_ = v___x_2514_;
goto v_reusejp_2524_;
}
else
{
lean_object* v_reuseFailAlloc_2526_; 
v_reuseFailAlloc_2526_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2526_, 0, v___x_2523_);
v___x_2525_ = v_reuseFailAlloc_2526_;
goto v_reusejp_2524_;
}
v_reusejp_2524_:
{
return v___x_2525_;
}
}
}
else
{
lean_object* v___x_2527_; uint8_t v___x_2528_; lean_object* v___x_2529_; uint8_t v___x_2530_; lean_object* v___x_2531_; 
lean_dec(v___x_2516_);
lean_del_object(v___x_2514_);
v___x_2527_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__0));
v___x_2528_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v___x_2527_, v_tail_2509_);
v___x_2529_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__1));
v___x_2530_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v___x_2529_, v_tail_2509_);
lean_dec(v_tail_2509_);
v___x_2531_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode(v_head_2507_, v_a_2512_, v___x_2528_, v___x_2530_);
lean_dec(v_a_2512_);
return v___x_2531_;
}
}
}
else
{
lean_object* v_a_2533_; lean_object* v___x_2535_; uint8_t v_isShared_2536_; uint8_t v_isSharedCheck_2540_; 
lean_dec(v_tail_2509_);
lean_dec(v_head_2507_);
v_a_2533_ = lean_ctor_get(v___x_2511_, 0);
v_isSharedCheck_2540_ = !lean_is_exclusive(v___x_2511_);
if (v_isSharedCheck_2540_ == 0)
{
v___x_2535_ = v___x_2511_;
v_isShared_2536_ = v_isSharedCheck_2540_;
goto v_resetjp_2534_;
}
else
{
lean_inc(v_a_2533_);
lean_dec(v___x_2511_);
v___x_2535_ = lean_box(0);
v_isShared_2536_ = v_isSharedCheck_2540_;
goto v_resetjp_2534_;
}
v_resetjp_2534_:
{
lean_object* v___x_2538_; 
if (v_isShared_2536_ == 0)
{
v___x_2538_ = v___x_2535_;
goto v_reusejp_2537_;
}
else
{
lean_object* v_reuseFailAlloc_2539_; 
v_reuseFailAlloc_2539_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2539_, 0, v_a_2533_);
v___x_2538_ = v_reuseFailAlloc_2539_;
goto v_reusejp_2537_;
}
v_reusejp_2537_:
{
return v___x_2538_;
}
}
}
}
else
{
lean_object* v___x_2541_; lean_object* v___x_2542_; 
lean_dec(v_tail_2509_);
lean_dec(v_head_2508_);
lean_dec(v_head_2507_);
v___x_2541_ = ((lean_object*)(l_Lean1090_Diagnostics_DecodeCosts_execute___closed__5));
v___x_2542_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2542_, 0, v___x_2541_);
return v___x_2542_;
}
}
else
{
lean_dec(v_tail_2506_);
lean_dec_ref_known(v_args_2501_, 2);
goto v___jp_2503_;
}
}
else
{
lean_dec(v_args_2501_);
goto v___jp_2503_;
}
v___jp_2503_:
{
lean_object* v___x_2504_; lean_object* v___x_2505_; 
v___x_2504_ = ((lean_object*)(l_Lean1090_Diagnostics_DecodeCosts_execute___closed__1));
v___x_2505_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2505_, 0, v___x_2504_);
return v___x_2505_;
}
}
}
LEAN_EXPORT lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute___boxed(lean_object* v_args_2543_, lean_object* v_a_2544_){
_start:
{
lean_object* v_res_2545_; 
v_res_2545_ = l_Lean1090_Diagnostics_DecodeCosts_execute(v_args_2543_);
return v_res_2545_;
}
}
LEAN_EXPORT lean_object* _lean_main(lean_object* v_args_2546_){
_start:
{
lean_object* v___x_2548_; 
v___x_2548_ = l_Lean1090_Diagnostics_DecodeCosts_execute(v_args_2546_);
return v___x_2548_;
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_args_2549_, lean_object* v_a_2550_){
_start:
{
lean_object* v_res_2551_; 
v_res_2551_ = _lean_main(v_args_2549_);
return v_res_2551_;
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
