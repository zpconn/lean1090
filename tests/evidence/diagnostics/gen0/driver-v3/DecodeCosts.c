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
static const lean_string_object l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "poll"};
static const lean_object* l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg___closed__0 = (const lean_object*)&l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg___closed__0_value;
static const lean_string_object l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 30, .m_capacity = 30, .m_length = 29, .m_data = "expected diagnostic command: "};
static const lean_object* l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg___closed__1 = (const lean_object*)&l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg___closed__1_value;
LEAN_EXPORT lean_object* l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg(lean_object*);
LEAN_EXPORT lean_object* l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
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
LEAN_EXPORT lean_object* l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg(lean_object* v_expected_444_){
_start:
{
lean_object* v___x_446_; lean_object* v___x_447_; lean_object* v_getLine_448_; lean_object* v___x_449_; 
v___x_446_ = lean_box(0);
v___x_447_ = lean_get_stdin();
v_getLine_448_ = lean_ctor_get(v___x_447_, 3);
lean_inc_ref(v_getLine_448_);
lean_dec_ref(v___x_447_);
v___x_449_ = lean_apply_1(v_getLine_448_, lean_box(0));
if (lean_obj_tag(v___x_449_) == 0)
{
lean_object* v_a_450_; lean_object* v___x_452_; uint8_t v_isShared_453_; uint8_t v_isSharedCheck_472_; 
v_a_450_ = lean_ctor_get(v___x_449_, 0);
v_isSharedCheck_472_ = !lean_is_exclusive(v___x_449_);
if (v_isSharedCheck_472_ == 0)
{
v___x_452_ = v___x_449_;
v_isShared_453_ = v_isSharedCheck_472_;
goto v_resetjp_451_;
}
else
{
lean_inc(v_a_450_);
lean_dec(v___x_449_);
v___x_452_ = lean_box(0);
v_isShared_453_ = v_isSharedCheck_472_;
goto v_resetjp_451_;
}
v_resetjp_451_:
{
lean_object* v___x_454_; lean_object* v___x_455_; lean_object* v___x_456_; lean_object* v___x_457_; lean_object* v___x_458_; lean_object* v___x_459_; uint8_t v___x_460_; 
v___x_454_ = lean_unsigned_to_nat(0u);
v___x_455_ = lean_string_utf8_byte_size(v_a_450_);
v___x_456_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_456_, 0, v_a_450_);
lean_ctor_set(v___x_456_, 1, v___x_454_);
lean_ctor_set(v___x_456_, 2, v___x_455_);
v___x_457_ = l_String_Slice_trimAscii(v___x_456_);
v___x_458_ = l_String_Slice_toString(v___x_457_);
lean_dec_ref(v___x_457_);
v___x_459_ = ((lean_object*)(l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg___closed__0));
v___x_460_ = lean_string_dec_eq(v___x_458_, v___x_459_);
if (v___x_460_ == 0)
{
uint8_t v___x_461_; 
v___x_461_ = lean_string_dec_eq(v___x_458_, v_expected_444_);
lean_dec_ref(v___x_458_);
if (v___x_461_ == 0)
{
lean_object* v___x_462_; lean_object* v___x_463_; lean_object* v___x_464_; lean_object* v___x_466_; 
v___x_462_ = ((lean_object*)(l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg___closed__1));
v___x_463_ = lean_string_append(v___x_462_, v_expected_444_);
v___x_464_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_464_, 0, v___x_463_);
if (v_isShared_453_ == 0)
{
lean_ctor_set_tag(v___x_452_, 1);
lean_ctor_set(v___x_452_, 0, v___x_464_);
v___x_466_ = v___x_452_;
goto v_reusejp_465_;
}
else
{
lean_object* v_reuseFailAlloc_467_; 
v_reuseFailAlloc_467_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_467_, 0, v___x_464_);
v___x_466_ = v_reuseFailAlloc_467_;
goto v_reusejp_465_;
}
v_reusejp_465_:
{
return v___x_466_;
}
}
else
{
lean_object* v___x_469_; 
if (v_isShared_453_ == 0)
{
lean_ctor_set(v___x_452_, 0, v___x_446_);
v___x_469_ = v___x_452_;
goto v_reusejp_468_;
}
else
{
lean_object* v_reuseFailAlloc_470_; 
v_reuseFailAlloc_470_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_470_, 0, v___x_446_);
v___x_469_ = v_reuseFailAlloc_470_;
goto v_reusejp_468_;
}
v_reusejp_468_:
{
return v___x_469_;
}
}
}
else
{
lean_dec_ref(v___x_458_);
lean_del_object(v___x_452_);
goto _start;
}
}
}
else
{
lean_object* v_a_473_; lean_object* v___x_475_; uint8_t v_isShared_476_; uint8_t v_isSharedCheck_480_; 
v_a_473_ = lean_ctor_get(v___x_449_, 0);
v_isSharedCheck_480_ = !lean_is_exclusive(v___x_449_);
if (v_isSharedCheck_480_ == 0)
{
v___x_475_ = v___x_449_;
v_isShared_476_ = v_isSharedCheck_480_;
goto v_resetjp_474_;
}
else
{
lean_inc(v_a_473_);
lean_dec(v___x_449_);
v___x_475_ = lean_box(0);
v_isShared_476_ = v_isSharedCheck_480_;
goto v_resetjp_474_;
}
v_resetjp_474_:
{
lean_object* v___x_478_; 
if (v_isShared_476_ == 0)
{
v___x_478_ = v___x_475_;
goto v_reusejp_477_;
}
else
{
lean_object* v_reuseFailAlloc_479_; 
v_reuseFailAlloc_479_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_479_, 0, v_a_473_);
v___x_478_ = v_reuseFailAlloc_479_;
goto v_reusejp_477_;
}
v_reusejp_477_:
{
return v___x_478_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg___boxed(lean_object* v_expected_481_, lean_object* v___y_482_){
_start:
{
lean_object* v_res_483_; 
v_res_483_ = l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg(v_expected_481_);
lean_dec_ref(v_expected_481_);
return v_res_483_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(uint8_t v_enabled_484_, lean_object* v_expected_485_){
_start:
{
if (v_enabled_484_ == 0)
{
lean_object* v___x_487_; lean_object* v___x_488_; 
v___x_487_ = lean_box(0);
v___x_488_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_488_, 0, v___x_487_);
return v___x_488_;
}
else
{
lean_object* v___x_489_; lean_object* v___x_490_; 
v___x_489_ = lean_box(0);
v___x_490_ = l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg(v_expected_485_);
if (lean_obj_tag(v___x_490_) == 0)
{
lean_object* v___x_492_; uint8_t v_isShared_493_; uint8_t v_isSharedCheck_497_; 
v_isSharedCheck_497_ = !lean_is_exclusive(v___x_490_);
if (v_isSharedCheck_497_ == 0)
{
lean_object* v_unused_498_; 
v_unused_498_ = lean_ctor_get(v___x_490_, 0);
lean_dec(v_unused_498_);
v___x_492_ = v___x_490_;
v_isShared_493_ = v_isSharedCheck_497_;
goto v_resetjp_491_;
}
else
{
lean_dec(v___x_490_);
v___x_492_ = lean_box(0);
v_isShared_493_ = v_isSharedCheck_497_;
goto v_resetjp_491_;
}
v_resetjp_491_:
{
lean_object* v___x_495_; 
if (v_isShared_493_ == 0)
{
lean_ctor_set(v___x_492_, 0, v___x_489_);
v___x_495_ = v___x_492_;
goto v_reusejp_494_;
}
else
{
lean_object* v_reuseFailAlloc_496_; 
v_reuseFailAlloc_496_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_496_, 0, v___x_489_);
v___x_495_ = v_reuseFailAlloc_496_;
goto v_reusejp_494_;
}
v_reusejp_494_:
{
return v___x_495_;
}
}
}
else
{
return v___x_490_;
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command___boxed(lean_object* v_enabled_499_, lean_object* v_expected_500_, lean_object* v_a_501_){
_start:
{
uint8_t v_enabled_boxed_502_; lean_object* v_res_503_; 
v_enabled_boxed_502_ = lean_unbox(v_enabled_499_);
v_res_503_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_enabled_boxed_502_, v_expected_500_);
lean_dec_ref(v_expected_500_);
return v_res_503_;
}
}
LEAN_EXPORT lean_object* l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0(lean_object* v_expected_504_, lean_object* v_inst_505_, lean_object* v_a_506_){
_start:
{
lean_object* v___x_508_; 
v___x_508_ = l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___redArg(v_expected_504_);
return v___x_508_;
}
}
LEAN_EXPORT lean_object* l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0___boxed(lean_object* v_expected_509_, lean_object* v_inst_510_, lean_object* v_a_511_, lean_object* v___y_512_){
_start:
{
lean_object* v_res_513_; 
v_res_513_ = l___private_Init_While_0__repeatM_erased___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command_spec__0(v_expected_509_, v_inst_510_, v_a_511_);
lean_dec_ref(v_expected_509_);
return v_res_513_;
}
}
static uint64_t _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_offsetBasis(void){
_start:
{
uint64_t v___x_514_; 
v___x_514_ = 14695981039346656037ULL;
return v___x_514_;
}
}
static uint64_t _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prime(void){
_start:
{
uint64_t v___x_515_; 
v___x_515_ = 1099511628211ULL;
return v___x_515_;
}
}
LEAN_EXPORT uint64_t l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(lean_object* v_as_516_, size_t v_i_517_, size_t v_stop_518_, uint64_t v_b_519_){
_start:
{
uint8_t v___x_520_; 
v___x_520_ = lean_usize_dec_eq(v_i_517_, v_stop_518_);
if (v___x_520_ == 0)
{
lean_object* v___x_521_; uint8_t v___x_522_; uint64_t v___x_523_; uint64_t v___x_524_; uint64_t v___x_525_; uint64_t v___x_526_; size_t v___x_527_; size_t v___x_528_; 
v___x_521_ = lean_array_uget_borrowed(v_as_516_, v_i_517_);
v___x_522_ = lean_unbox(v___x_521_);
v___x_523_ = lean_uint8_to_uint64(v___x_522_);
v___x_524_ = lean_uint64_xor(v_b_519_, v___x_523_);
v___x_525_ = 1099511628211ULL;
v___x_526_ = lean_uint64_mul(v___x_524_, v___x_525_);
v___x_527_ = ((size_t)1ULL);
v___x_528_ = lean_usize_add(v_i_517_, v___x_527_);
v_i_517_ = v___x_528_;
v_b_519_ = v___x_526_;
goto _start;
}
else
{
return v_b_519_;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0___boxed(lean_object* v_as_530_, lean_object* v_i_531_, lean_object* v_stop_532_, lean_object* v_b_533_){
_start:
{
size_t v_i_boxed_534_; size_t v_stop_boxed_535_; uint64_t v_b_boxed_536_; uint64_t v_res_537_; lean_object* v_r_538_; 
v_i_boxed_534_ = lean_unbox_usize(v_i_531_);
lean_dec(v_i_531_);
v_stop_boxed_535_ = lean_unbox_usize(v_stop_532_);
lean_dec(v_stop_532_);
v_b_boxed_536_ = lean_unbox_uint64(v_b_533_);
lean_dec_ref(v_b_533_);
v_res_537_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(v_as_530_, v_i_boxed_534_, v_stop_boxed_535_, v_b_boxed_536_);
lean_dec_ref(v_as_530_);
v_r_538_ = lean_box_uint64(v_res_537_);
return v_r_538_;
}
}
LEAN_EXPORT uint64_t l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes(uint64_t v_hash_539_, lean_object* v_bytes_540_){
_start:
{
lean_object* v___x_541_; lean_object* v___x_542_; lean_object* v___x_543_; uint8_t v___x_544_; 
v___x_541_ = lean_byte_array_data(v_bytes_540_);
v___x_542_ = lean_unsigned_to_nat(0u);
v___x_543_ = lean_array_get_size(v___x_541_);
v___x_544_ = lean_nat_dec_lt(v___x_542_, v___x_543_);
if (v___x_544_ == 0)
{
lean_dec_ref(v___x_541_);
return v_hash_539_;
}
else
{
uint8_t v___x_545_; 
v___x_545_ = lean_nat_dec_le(v___x_543_, v___x_543_);
if (v___x_545_ == 0)
{
if (v___x_544_ == 0)
{
lean_dec_ref(v___x_541_);
return v_hash_539_;
}
else
{
size_t v___x_546_; size_t v___x_547_; uint64_t v___x_548_; 
v___x_546_ = ((size_t)0ULL);
v___x_547_ = lean_usize_of_nat(v___x_543_);
v___x_548_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(v___x_541_, v___x_546_, v___x_547_, v_hash_539_);
lean_dec_ref(v___x_541_);
return v___x_548_;
}
}
else
{
size_t v___x_549_; size_t v___x_550_; uint64_t v___x_551_; 
v___x_549_ = ((size_t)0ULL);
v___x_550_ = lean_usize_of_nat(v___x_543_);
v___x_551_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes_spec__0(v___x_541_, v___x_549_, v___x_550_, v_hash_539_);
lean_dec_ref(v___x_541_);
return v___x_551_;
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes___boxed(lean_object* v_hash_552_, lean_object* v_bytes_553_){
_start:
{
uint64_t v_hash_boxed_554_; uint64_t v_res_555_; lean_object* v_r_556_; 
v_hash_boxed_554_ = lean_unbox_uint64(v_hash_552_);
lean_dec_ref(v_hash_552_);
v_res_555_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes(v_hash_boxed_554_, v_bytes_553_);
v_r_556_ = lean_box_uint64(v_res_555_);
return v_r_556_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(lean_object* v_digest_557_, lean_object* v_bytes_558_){
_start:
{
lean_object* v_count_559_; lean_object* v_bytes_560_; uint64_t v_value_561_; lean_object* v___x_563_; uint8_t v_isShared_564_; uint8_t v_isSharedCheck_573_; 
v_count_559_ = lean_ctor_get(v_digest_557_, 0);
v_bytes_560_ = lean_ctor_get(v_digest_557_, 1);
v_value_561_ = lean_ctor_get_uint64(v_digest_557_, sizeof(void*)*2);
v_isSharedCheck_573_ = !lean_is_exclusive(v_digest_557_);
if (v_isSharedCheck_573_ == 0)
{
v___x_563_ = v_digest_557_;
v_isShared_564_ = v_isSharedCheck_573_;
goto v_resetjp_562_;
}
else
{
lean_inc(v_bytes_560_);
lean_inc(v_count_559_);
lean_dec(v_digest_557_);
v___x_563_ = lean_box(0);
v_isShared_564_ = v_isSharedCheck_573_;
goto v_resetjp_562_;
}
v_resetjp_562_:
{
lean_object* v___x_565_; lean_object* v___x_566_; lean_object* v___x_567_; lean_object* v___x_568_; uint64_t v___x_569_; lean_object* v___x_571_; 
v___x_565_ = lean_unsigned_to_nat(1u);
v___x_566_ = lean_nat_add(v_count_559_, v___x_565_);
lean_dec(v_count_559_);
v___x_567_ = lean_byte_array_size(v_bytes_558_);
v___x_568_ = lean_nat_add(v_bytes_560_, v___x_567_);
lean_dec(v_bytes_560_);
v___x_569_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_hashBytes(v_value_561_, v_bytes_558_);
if (v_isShared_564_ == 0)
{
lean_ctor_set(v___x_563_, 1, v___x_568_);
lean_ctor_set(v___x_563_, 0, v___x_566_);
v___x_571_ = v___x_563_;
goto v_reusejp_570_;
}
else
{
lean_object* v_reuseFailAlloc_572_; 
v_reuseFailAlloc_572_ = lean_alloc_ctor(0, 2, 8);
lean_ctor_set(v_reuseFailAlloc_572_, 0, v___x_566_);
lean_ctor_set(v_reuseFailAlloc_572_, 1, v___x_568_);
v___x_571_ = v_reuseFailAlloc_572_;
goto v_reusejp_570_;
}
v_reusejp_570_:
{
lean_ctor_set_uint64(v___x_571_, sizeof(void*)*2, v___x_569_);
return v___x_571_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__1(lean_object* v_a_574_, lean_object* v_a_575_){
_start:
{
if (lean_obj_tag(v_a_574_) == 0)
{
lean_object* v___x_576_; 
v___x_576_ = l_List_reverse___redArg(v_a_575_);
return v___x_576_;
}
else
{
lean_object* v_head_577_; lean_object* v_tail_578_; lean_object* v___x_580_; uint8_t v_isShared_581_; uint8_t v_isSharedCheck_587_; 
v_head_577_ = lean_ctor_get(v_a_574_, 0);
v_tail_578_ = lean_ctor_get(v_a_574_, 1);
v_isSharedCheck_587_ = !lean_is_exclusive(v_a_574_);
if (v_isSharedCheck_587_ == 0)
{
v___x_580_ = v_a_574_;
v_isShared_581_ = v_isSharedCheck_587_;
goto v_resetjp_579_;
}
else
{
lean_inc(v_tail_578_);
lean_inc(v_head_577_);
lean_dec(v_a_574_);
v___x_580_ = lean_box(0);
v_isShared_581_ = v_isSharedCheck_587_;
goto v_resetjp_579_;
}
v_resetjp_579_:
{
lean_object* v_count_582_; lean_object* v___x_584_; 
v_count_582_ = lean_ctor_get(v_head_577_, 0);
lean_inc(v_count_582_);
lean_dec(v_head_577_);
if (v_isShared_581_ == 0)
{
lean_ctor_set(v___x_580_, 1, v_a_575_);
lean_ctor_set(v___x_580_, 0, v_count_582_);
v___x_584_ = v___x_580_;
goto v_reusejp_583_;
}
else
{
lean_object* v_reuseFailAlloc_586_; 
v_reuseFailAlloc_586_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_586_, 0, v_count_582_);
lean_ctor_set(v_reuseFailAlloc_586_, 1, v_a_575_);
v___x_584_ = v_reuseFailAlloc_586_;
goto v_reusejp_583_;
}
v_reusejp_583_:
{
v_a_574_ = v_tail_578_;
v_a_575_ = v___x_584_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(lean_object* v_inputs_591_, lean_object* v_output_592_, lean_object* v_range_593_, lean_object* v_b_594_, lean_object* v_i_595_){
_start:
{
lean_object* v_stop_597_; lean_object* v_step_598_; uint8_t v___x_599_; 
v_stop_597_ = lean_ctor_get(v_range_593_, 1);
v_step_598_ = lean_ctor_get(v_range_593_, 2);
v___x_599_ = lean_nat_dec_lt(v_i_595_, v_stop_597_);
if (v___x_599_ == 0)
{
lean_object* v___x_600_; 
lean_dec(v_i_595_);
v___x_600_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_600_, 0, v_b_594_);
return v___x_600_;
}
else
{
lean_object* v___x_601_; uint8_t v___x_602_; 
v___x_601_ = lean_array_get_size(v_inputs_591_);
v___x_602_ = lean_nat_dec_lt(v_i_595_, v___x_601_);
if (v___x_602_ == 0)
{
lean_object* v___x_603_; lean_object* v___x_604_; 
lean_dec(v_i_595_);
lean_dec_ref(v_b_594_);
v___x_603_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___closed__1));
v___x_604_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_604_, 0, v___x_603_);
return v___x_604_;
}
else
{
lean_object* v_fst_605_; lean_object* v_snd_606_; lean_object* v___x_608_; uint8_t v_isShared_609_; uint8_t v_isSharedCheck_635_; 
v_fst_605_ = lean_ctor_get(v_b_594_, 0);
v_snd_606_ = lean_ctor_get(v_b_594_, 1);
v_isSharedCheck_635_ = !lean_is_exclusive(v_b_594_);
if (v_isSharedCheck_635_ == 0)
{
v___x_608_ = v_b_594_;
v_isShared_609_ = v_isSharedCheck_635_;
goto v_resetjp_607_;
}
else
{
lean_inc(v_snd_606_);
lean_inc(v_fst_605_);
lean_dec(v_b_594_);
v___x_608_ = lean_box(0);
v_isShared_609_ = v_isSharedCheck_635_;
goto v_resetjp_607_;
}
v_resetjp_607_:
{
lean_object* v___x_610_; lean_object* v___x_611_; lean_object* v___x_612_; lean_object* v___x_613_; lean_object* v___x_614_; lean_object* v___x_615_; lean_object* v_df_616_; lean_object* v___x_617_; lean_object* v___x_618_; lean_object* v_bytes_619_; lean_object* v_total_620_; lean_object* v___y_622_; lean_object* v___x_628_; uint8_t v___x_629_; 
v___x_610_ = lean_array_fget_borrowed(v_inputs_591_, v_i_595_);
v___x_611_ = lean_array_fget_borrowed(v_output_592_, v_i_595_);
v___x_612_ = lean_unsigned_to_nat(0u);
lean_inc(v___x_611_);
v___x_613_ = lp_lean1090_Lean1090_Spec_instReprMessage_repr___redArg(v___x_611_);
v___x_614_ = lean_unsigned_to_nat(120u);
v___x_615_ = l_Std_Format_pretty(v___x_613_, v___x_614_, v___x_612_, v___x_612_);
v_df_616_ = lean_ctor_get(v___x_610_, 0);
v___x_617_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__0));
v___x_618_ = lean_string_append(v___x_615_, v___x_617_);
v_bytes_619_ = lean_string_to_utf8(v___x_618_);
lean_dec_ref(v___x_618_);
lean_inc_ref(v_bytes_619_);
v_total_620_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(v_fst_605_, v_bytes_619_);
v___x_628_ = lean_array_get_size(v_snd_606_);
v___x_629_ = lean_nat_dec_lt(v_df_616_, v___x_628_);
if (v___x_629_ == 0)
{
lean_dec_ref(v_bytes_619_);
v___y_622_ = v_snd_606_;
goto v___jp_621_;
}
else
{
lean_object* v_v_630_; lean_object* v___x_631_; lean_object* v_xs_x27_632_; lean_object* v___x_633_; lean_object* v___x_634_; 
v_v_630_ = lean_array_fget(v_snd_606_, v_df_616_);
v___x_631_ = lean_box(0);
v_xs_x27_632_ = lean_array_fset(v_snd_606_, v_df_616_, v___x_631_);
v___x_633_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(v_v_630_, v_bytes_619_);
v___x_634_ = lean_array_fset(v_xs_x27_632_, v_df_616_, v___x_633_);
v___y_622_ = v___x_634_;
goto v___jp_621_;
}
v___jp_621_:
{
lean_object* v___x_624_; 
if (v_isShared_609_ == 0)
{
lean_ctor_set(v___x_608_, 1, v___y_622_);
lean_ctor_set(v___x_608_, 0, v_total_620_);
v___x_624_ = v___x_608_;
goto v_reusejp_623_;
}
else
{
lean_object* v_reuseFailAlloc_627_; 
v_reuseFailAlloc_627_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_627_, 0, v_total_620_);
lean_ctor_set(v_reuseFailAlloc_627_, 1, v___y_622_);
v___x_624_ = v_reuseFailAlloc_627_;
goto v_reusejp_623_;
}
v_reusejp_623_:
{
lean_object* v___x_625_; 
v___x_625_ = lean_nat_add(v_i_595_, v_step_598_);
lean_dec(v_i_595_);
v_b_594_ = v___x_624_;
v_i_595_ = v___x_625_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg___boxed(lean_object* v_inputs_636_, lean_object* v_output_637_, lean_object* v_range_638_, lean_object* v_b_639_, lean_object* v_i_640_, lean_object* v___y_641_){
_start:
{
lean_object* v_res_642_; 
v_res_642_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(v_inputs_636_, v_output_637_, v_range_638_, v_b_639_, v_i_640_);
lean_dec_ref(v_range_638_);
lean_dec_ref(v_output_637_);
lean_dec_ref(v_inputs_636_);
return v_res_642_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3(void){
_start:
{
lean_object* v_total_649_; lean_object* v___x_650_; lean_object* v_byDF_651_; 
v_total_649_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__2));
v___x_650_ = lean_unsigned_to_nat(32u);
v_byDF_651_ = lean_mk_array(v___x_650_, v_total_649_);
return v_byDF_651_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4(void){
_start:
{
lean_object* v_byDF_652_; lean_object* v_total_653_; lean_object* v___x_654_; 
v_byDF_652_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__3);
v_total_653_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__2));
v___x_654_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_654_, 0, v_total_653_);
lean_ctor_set(v___x_654_, 1, v_byDF_652_);
return v___x_654_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume(lean_object* v_inputs_658_, lean_object* v_output_659_){
_start:
{
lean_object* v___x_661_; lean_object* v___x_662_; uint8_t v___x_663_; 
v___x_661_ = lean_array_get_size(v_output_659_);
v___x_662_ = lean_array_get_size(v_inputs_658_);
v___x_663_ = lean_nat_dec_eq(v___x_661_, v___x_662_);
if (v___x_663_ == 0)
{
lean_object* v___x_664_; lean_object* v___x_665_; 
v___x_664_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__1));
v___x_665_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_665_, 0, v___x_664_);
return v___x_665_;
}
else
{
lean_object* v___x_666_; lean_object* v___x_667_; lean_object* v___x_668_; lean_object* v___x_669_; lean_object* v___x_670_; 
v___x_666_ = lean_unsigned_to_nat(0u);
v___x_667_ = lean_unsigned_to_nat(1u);
v___x_668_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_668_, 0, v___x_666_);
lean_ctor_set(v___x_668_, 1, v___x_661_);
lean_ctor_set(v___x_668_, 2, v___x_667_);
v___x_669_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__4);
v___x_670_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(v_inputs_658_, v_output_659_, v___x_668_, v___x_669_, v___x_666_);
lean_dec_ref_known(v___x_668_, 3);
if (lean_obj_tag(v___x_670_) == 0)
{
lean_object* v_a_671_; lean_object* v___x_673_; uint8_t v_isShared_674_; uint8_t v_isSharedCheck_696_; 
v_a_671_ = lean_ctor_get(v___x_670_, 0);
v_isSharedCheck_696_ = !lean_is_exclusive(v___x_670_);
if (v_isSharedCheck_696_ == 0)
{
v___x_673_ = v___x_670_;
v_isShared_674_ = v_isSharedCheck_696_;
goto v_resetjp_672_;
}
else
{
lean_inc(v_a_671_);
lean_dec(v___x_670_);
v___x_673_ = lean_box(0);
v_isShared_674_ = v_isSharedCheck_696_;
goto v_resetjp_672_;
}
v_resetjp_672_:
{
lean_object* v_fst_675_; lean_object* v_snd_676_; lean_object* v___x_678_; uint8_t v_isShared_679_; uint8_t v_isSharedCheck_695_; 
v_fst_675_ = lean_ctor_get(v_a_671_, 0);
v_snd_676_ = lean_ctor_get(v_a_671_, 1);
v_isSharedCheck_695_ = !lean_is_exclusive(v_a_671_);
if (v_isSharedCheck_695_ == 0)
{
v___x_678_ = v_a_671_;
v_isShared_679_ = v_isSharedCheck_695_;
goto v_resetjp_677_;
}
else
{
lean_inc(v_snd_676_);
lean_inc(v_fst_675_);
lean_dec(v_a_671_);
v___x_678_ = lean_box(0);
v_isShared_679_ = v_isSharedCheck_695_;
goto v_resetjp_677_;
}
v_resetjp_677_:
{
lean_object* v___x_680_; lean_object* v___x_681_; lean_object* v___x_682_; lean_object* v___x_683_; uint8_t v___x_684_; 
lean_inc(v_snd_676_);
v___x_680_ = lean_array_to_list(v_snd_676_);
v___x_681_ = lean_box(0);
v___x_682_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__1(v___x_680_, v___x_681_);
v___x_683_ = l_List_sum___at___00Lean_PersistentHashMap_subarrayMeasure_spec__2(v___x_682_);
lean_dec(v___x_682_);
v___x_684_ = lean_nat_dec_eq(v___x_683_, v___x_661_);
lean_dec(v___x_683_);
if (v___x_684_ == 0)
{
lean_object* v___x_685_; lean_object* v___x_687_; 
lean_del_object(v___x_678_);
lean_dec(v_snd_676_);
lean_dec(v_fst_675_);
v___x_685_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___closed__6));
if (v_isShared_674_ == 0)
{
lean_ctor_set_tag(v___x_673_, 1);
lean_ctor_set(v___x_673_, 0, v___x_685_);
v___x_687_ = v___x_673_;
goto v_reusejp_686_;
}
else
{
lean_object* v_reuseFailAlloc_688_; 
v_reuseFailAlloc_688_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_688_, 0, v___x_685_);
v___x_687_ = v_reuseFailAlloc_688_;
goto v_reusejp_686_;
}
v_reusejp_686_:
{
return v___x_687_;
}
}
else
{
lean_object* v___x_690_; 
if (v_isShared_679_ == 0)
{
v___x_690_ = v___x_678_;
goto v_reusejp_689_;
}
else
{
lean_object* v_reuseFailAlloc_694_; 
v_reuseFailAlloc_694_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_694_, 0, v_fst_675_);
lean_ctor_set(v_reuseFailAlloc_694_, 1, v_snd_676_);
v___x_690_ = v_reuseFailAlloc_694_;
goto v_reusejp_689_;
}
v_reusejp_689_:
{
lean_object* v___x_692_; 
if (v_isShared_674_ == 0)
{
lean_ctor_set(v___x_673_, 0, v___x_690_);
v___x_692_ = v___x_673_;
goto v_reusejp_691_;
}
else
{
lean_object* v_reuseFailAlloc_693_; 
v_reuseFailAlloc_693_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_693_, 0, v___x_690_);
v___x_692_ = v_reuseFailAlloc_693_;
goto v_reusejp_691_;
}
v_reusejp_691_:
{
return v___x_692_;
}
}
}
}
}
}
else
{
return v___x_670_;
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume___boxed(lean_object* v_inputs_697_, lean_object* v_output_698_, lean_object* v_a_699_){
_start:
{
lean_object* v_res_700_; 
v_res_700_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume(v_inputs_697_, v_output_698_);
lean_dec_ref(v_output_698_);
lean_dec_ref(v_inputs_697_);
return v_res_700_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0(lean_object* v_inputs_701_, lean_object* v_output_702_, lean_object* v_range_703_, lean_object* v_b_704_, lean_object* v_i_705_, lean_object* v_hs_706_, lean_object* v_hl_707_){
_start:
{
lean_object* v___x_709_; 
v___x_709_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___redArg(v_inputs_701_, v_output_702_, v_range_703_, v_b_704_, v_i_705_);
return v___x_709_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0___boxed(lean_object* v_inputs_710_, lean_object* v_output_711_, lean_object* v_range_712_, lean_object* v_b_713_, lean_object* v_i_714_, lean_object* v_hs_715_, lean_object* v_hl_716_, lean_object* v___y_717_){
_start:
{
lean_object* v_res_718_; 
v_res_718_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume_spec__0(v_inputs_710_, v_output_711_, v_range_712_, v_b_713_, v_i_714_, v_hs_715_, v_hl_716_);
lean_dec_ref(v_range_712_);
lean_dec_ref(v_output_711_);
lean_dec_ref(v_inputs_710_);
return v_res_718_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(lean_object* v_digest_722_){
_start:
{
lean_object* v_count_723_; lean_object* v_bytes_724_; uint64_t v_value_725_; lean_object* v___x_726_; lean_object* v___x_727_; lean_object* v___x_728_; lean_object* v___x_729_; lean_object* v___x_730_; lean_object* v___x_731_; lean_object* v___x_732_; lean_object* v___x_733_; lean_object* v___x_734_; lean_object* v___x_735_; lean_object* v___x_736_; lean_object* v___x_737_; lean_object* v___x_738_; lean_object* v___x_739_; lean_object* v___x_740_; lean_object* v___x_741_; lean_object* v___x_742_; lean_object* v___x_743_; 
v_count_723_ = lean_ctor_get(v_digest_722_, 0);
lean_inc(v_count_723_);
v_bytes_724_ = lean_ctor_get(v_digest_722_, 1);
lean_inc(v_bytes_724_);
v_value_725_ = lean_ctor_get_uint64(v_digest_722_, sizeof(void*)*2);
lean_dec_ref(v_digest_722_);
v___x_726_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0));
v___x_727_ = l_Lean_JsonNumber_fromNat(v_count_723_);
v___x_728_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_728_, 0, v___x_727_);
v___x_729_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_729_, 0, v___x_726_);
lean_ctor_set(v___x_729_, 1, v___x_728_);
v___x_730_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__1));
v___x_731_ = l_Lean_JsonNumber_fromNat(v_bytes_724_);
v___x_732_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_732_, 0, v___x_731_);
v___x_733_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_733_, 0, v___x_730_);
lean_ctor_set(v___x_733_, 1, v___x_732_);
v___x_734_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__2));
v___x_735_ = lean_uint64_to_nat(v_value_725_);
v___x_736_ = l_Lean_JsonNumber_fromNat(v___x_735_);
v___x_737_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_737_, 0, v___x_736_);
v___x_738_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_738_, 0, v___x_734_);
lean_ctor_set(v___x_738_, 1, v___x_737_);
v___x_739_ = lean_box(0);
v___x_740_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_740_, 0, v___x_738_);
lean_ctor_set(v___x_740_, 1, v___x_739_);
v___x_741_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_741_, 0, v___x_733_);
lean_ctor_set(v___x_741_, 1, v___x_740_);
v___x_742_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_742_, 0, v___x_729_);
lean_ctor_set(v___x_742_, 1, v___x_741_);
v___x_743_ = l_Lean_Json_mkObj(v___x_742_);
lean_dec_ref_known(v___x_742_, 2);
return v___x_743_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0(lean_object* v_as_745_, size_t v_sz_746_, size_t v_i_747_, lean_object* v_b_748_){
_start:
{
uint8_t v___x_750_; 
v___x_750_ = lean_usize_dec_lt(v_i_747_, v_sz_746_);
if (v___x_750_ == 0)
{
lean_object* v___x_751_; 
v___x_751_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_751_, 0, v_b_748_);
return v___x_751_;
}
else
{
lean_object* v_a_752_; lean_object* v_df_753_; lean_object* v_bytes_754_; lean_object* v___x_755_; 
v_a_752_ = lean_array_uget_borrowed(v_as_745_, v_i_747_);
v_df_753_ = lean_ctor_get(v_a_752_, 0);
v_bytes_754_ = lean_ctor_get(v_a_752_, 1);
v___x_755_ = lp_lean1090_Lean1090_Impl_decode(v_bytes_754_);
if (lean_obj_tag(v___x_755_) == 1)
{
lean_object* v_val_756_; lean_object* v___x_757_; size_t v___x_758_; size_t v___x_759_; 
v_val_756_ = lean_ctor_get(v___x_755_, 0);
lean_inc(v_val_756_);
lean_dec_ref_known(v___x_755_, 1);
v___x_757_ = lean_array_push(v_b_748_, v_val_756_);
v___x_758_ = ((size_t)1ULL);
v___x_759_ = lean_usize_add(v_i_747_, v___x_758_);
v_i_747_ = v___x_759_;
v_b_748_ = v___x_757_;
goto _start;
}
else
{
lean_object* v___x_761_; lean_object* v___x_762_; lean_object* v___x_763_; lean_object* v___x_764_; lean_object* v___x_765_; 
lean_dec(v___x_755_);
lean_dec_ref(v_b_748_);
v___x_761_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0___closed__0));
lean_inc(v_df_753_);
v___x_762_ = l_Nat_reprFast(v_df_753_);
v___x_763_ = lean_string_append(v___x_761_, v___x_762_);
lean_dec_ref(v___x_762_);
v___x_764_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_764_, 0, v___x_763_);
v___x_765_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_765_, 0, v___x_764_);
return v___x_765_;
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0___boxed(lean_object* v_as_766_, lean_object* v_sz_767_, lean_object* v_i_768_, lean_object* v_b_769_, lean_object* v___y_770_){
_start:
{
size_t v_sz_boxed_771_; size_t v_i_boxed_772_; lean_object* v_res_773_; 
v_sz_boxed_771_ = lean_unbox_usize(v_sz_767_);
lean_dec(v_sz_767_);
v_i_boxed_772_ = lean_unbox_usize(v_i_768_);
lean_dec(v_i_768_);
v_res_773_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0(v_as_766_, v_sz_boxed_771_, v_i_boxed_772_, v_b_769_);
lean_dec_ref(v_as_766_);
return v_res_773_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode(lean_object* v_inputs_774_){
_start:
{
lean_object* v___x_776_; lean_object* v_output_777_; lean_object* v___x_778_; size_t v_sz_779_; size_t v___x_780_; lean_object* v___x_781_; 
v___x_776_ = lean_array_get_size(v_inputs_774_);
v_output_777_ = lean_mk_empty_array_with_capacity(v___x_776_);
v___x_778_ = lean_io_get_num_heartbeats();
v_sz_779_ = lean_array_size(v_inputs_774_);
v___x_780_ = ((size_t)0ULL);
v___x_781_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode_spec__0(v_inputs_774_, v_sz_779_, v___x_780_, v_output_777_);
if (lean_obj_tag(v___x_781_) == 0)
{
lean_object* v_a_782_; lean_object* v___x_784_; uint8_t v_isShared_785_; uint8_t v_isSharedCheck_792_; 
v_a_782_ = lean_ctor_get(v___x_781_, 0);
v_isSharedCheck_792_ = !lean_is_exclusive(v___x_781_);
if (v_isSharedCheck_792_ == 0)
{
v___x_784_ = v___x_781_;
v_isShared_785_ = v_isSharedCheck_792_;
goto v_resetjp_783_;
}
else
{
lean_inc(v_a_782_);
lean_dec(v___x_781_);
v___x_784_ = lean_box(0);
v_isShared_785_ = v_isSharedCheck_792_;
goto v_resetjp_783_;
}
v_resetjp_783_:
{
lean_object* v___x_786_; lean_object* v___x_787_; lean_object* v___x_788_; lean_object* v___x_790_; 
v___x_786_ = lean_io_get_num_heartbeats();
v___x_787_ = lean_nat_sub(v___x_786_, v___x_778_);
lean_dec(v___x_778_);
lean_dec(v___x_786_);
v___x_788_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_788_, 0, v_a_782_);
lean_ctor_set(v___x_788_, 1, v___x_787_);
if (v_isShared_785_ == 0)
{
lean_ctor_set(v___x_784_, 0, v___x_788_);
v___x_790_ = v___x_784_;
goto v_reusejp_789_;
}
else
{
lean_object* v_reuseFailAlloc_791_; 
v_reuseFailAlloc_791_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_791_, 0, v___x_788_);
v___x_790_ = v_reuseFailAlloc_791_;
goto v_reusejp_789_;
}
v_reusejp_789_:
{
return v___x_790_;
}
}
}
else
{
lean_object* v_a_793_; lean_object* v___x_795_; uint8_t v_isShared_796_; uint8_t v_isSharedCheck_800_; 
lean_dec(v___x_778_);
v_a_793_ = lean_ctor_get(v___x_781_, 0);
v_isSharedCheck_800_ = !lean_is_exclusive(v___x_781_);
if (v_isSharedCheck_800_ == 0)
{
v___x_795_ = v___x_781_;
v_isShared_796_ = v_isSharedCheck_800_;
goto v_resetjp_794_;
}
else
{
lean_inc(v_a_793_);
lean_dec(v___x_781_);
v___x_795_ = lean_box(0);
v_isShared_796_ = v_isSharedCheck_800_;
goto v_resetjp_794_;
}
v_resetjp_794_:
{
lean_object* v___x_798_; 
if (v_isShared_796_ == 0)
{
v___x_798_ = v___x_795_;
goto v_reusejp_797_;
}
else
{
lean_object* v_reuseFailAlloc_799_; 
v_reuseFailAlloc_799_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_799_, 0, v_a_793_);
v___x_798_ = v_reuseFailAlloc_799_;
goto v_reusejp_797_;
}
v_reusejp_797_:
{
return v___x_798_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode___boxed(lean_object* v_inputs_801_, lean_object* v_a_802_){
_start:
{
lean_object* v_res_803_; 
v_res_803_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode(v_inputs_801_);
lean_dec_ref(v_inputs_801_);
return v_res_803_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_bump(lean_object* v_values_804_, lean_object* v_key_805_){
_start:
{
if (lean_obj_tag(v_values_804_) == 0)
{
lean_object* v___x_806_; lean_object* v___x_807_; lean_object* v___x_808_; 
v___x_806_ = lean_unsigned_to_nat(1u);
v___x_807_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_807_, 0, v_key_805_);
lean_ctor_set(v___x_807_, 1, v___x_806_);
v___x_808_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_808_, 0, v___x_807_);
lean_ctor_set(v___x_808_, 1, v_values_804_);
return v___x_808_;
}
else
{
lean_object* v_head_809_; lean_object* v_tail_810_; lean_object* v___x_812_; uint8_t v_isShared_813_; uint8_t v_isSharedCheck_835_; 
v_head_809_ = lean_ctor_get(v_values_804_, 0);
v_tail_810_ = lean_ctor_get(v_values_804_, 1);
v_isSharedCheck_835_ = !lean_is_exclusive(v_values_804_);
if (v_isSharedCheck_835_ == 0)
{
v___x_812_ = v_values_804_;
v_isShared_813_ = v_isSharedCheck_835_;
goto v_resetjp_811_;
}
else
{
lean_inc(v_tail_810_);
lean_inc(v_head_809_);
lean_dec(v_values_804_);
v___x_812_ = lean_box(0);
v_isShared_813_ = v_isSharedCheck_835_;
goto v_resetjp_811_;
}
v_resetjp_811_:
{
lean_object* v_fst_814_; lean_object* v_snd_815_; uint8_t v___x_816_; 
v_fst_814_ = lean_ctor_get(v_head_809_, 0);
v_snd_815_ = lean_ctor_get(v_head_809_, 1);
v___x_816_ = lean_nat_dec_eq(v_fst_814_, v_key_805_);
if (v___x_816_ == 0)
{
lean_object* v___x_817_; lean_object* v___x_819_; 
v___x_817_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_bump(v_tail_810_, v_key_805_);
if (v_isShared_813_ == 0)
{
lean_ctor_set(v___x_812_, 1, v___x_817_);
v___x_819_ = v___x_812_;
goto v_reusejp_818_;
}
else
{
lean_object* v_reuseFailAlloc_820_; 
v_reuseFailAlloc_820_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_820_, 0, v_head_809_);
lean_ctor_set(v_reuseFailAlloc_820_, 1, v___x_817_);
v___x_819_ = v_reuseFailAlloc_820_;
goto v_reusejp_818_;
}
v_reusejp_818_:
{
return v___x_819_;
}
}
else
{
lean_object* v___x_822_; uint8_t v_isShared_823_; uint8_t v_isSharedCheck_832_; 
lean_inc(v_snd_815_);
lean_inc(v_fst_814_);
lean_dec(v_key_805_);
v_isSharedCheck_832_ = !lean_is_exclusive(v_head_809_);
if (v_isSharedCheck_832_ == 0)
{
lean_object* v_unused_833_; lean_object* v_unused_834_; 
v_unused_833_ = lean_ctor_get(v_head_809_, 1);
lean_dec(v_unused_833_);
v_unused_834_ = lean_ctor_get(v_head_809_, 0);
lean_dec(v_unused_834_);
v___x_822_ = v_head_809_;
v_isShared_823_ = v_isSharedCheck_832_;
goto v_resetjp_821_;
}
else
{
lean_dec(v_head_809_);
v___x_822_ = lean_box(0);
v_isShared_823_ = v_isSharedCheck_832_;
goto v_resetjp_821_;
}
v_resetjp_821_:
{
lean_object* v___x_824_; lean_object* v___x_825_; lean_object* v___x_827_; 
v___x_824_ = lean_unsigned_to_nat(1u);
v___x_825_ = lean_nat_add(v_snd_815_, v___x_824_);
lean_dec(v_snd_815_);
if (v_isShared_823_ == 0)
{
lean_ctor_set(v___x_822_, 1, v___x_825_);
v___x_827_ = v___x_822_;
goto v_reusejp_826_;
}
else
{
lean_object* v_reuseFailAlloc_831_; 
v_reuseFailAlloc_831_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_831_, 0, v_fst_814_);
lean_ctor_set(v_reuseFailAlloc_831_, 1, v___x_825_);
v___x_827_ = v_reuseFailAlloc_831_;
goto v_reusejp_826_;
}
v_reusejp_826_:
{
lean_object* v___x_829_; 
if (v_isShared_813_ == 0)
{
lean_ctor_set(v___x_812_, 0, v___x_827_);
v___x_829_ = v___x_812_;
goto v_reusejp_828_;
}
else
{
lean_object* v_reuseFailAlloc_830_; 
v_reuseFailAlloc_830_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_830_, 0, v___x_827_);
lean_ctor_set(v_reuseFailAlloc_830_, 1, v_tail_810_);
v___x_829_ = v_reuseFailAlloc_830_;
goto v_reusejp_828_;
}
v_reusejp_828_:
{
return v___x_829_;
}
}
}
}
}
}
}
}
LEAN_EXPORT uint8_t l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0(lean_object* v_register_852_, lean_object* v_x_853_){
_start:
{
if (lean_obj_tag(v_x_853_) == 0)
{
uint8_t v___x_854_; 
v___x_854_ = 0;
return v___x_854_;
}
else
{
lean_object* v_head_855_; lean_object* v_tail_856_; lean_object* v_fst_857_; uint8_t v___x_858_; 
v_head_855_ = lean_ctor_get(v_x_853_, 0);
v_tail_856_ = lean_ctor_get(v_x_853_, 1);
v_fst_857_ = lean_ctor_get(v_head_855_, 0);
v___x_858_ = lean_nat_dec_eq(v_fst_857_, v_register_852_);
if (v___x_858_ == 0)
{
v_x_853_ = v_tail_856_;
goto _start;
}
else
{
return v___x_858_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0___boxed(lean_object* v_register_860_, lean_object* v_x_861_){
_start:
{
uint8_t v_res_862_; lean_object* v_r_863_; 
v_res_862_ = l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0(v_register_860_, v_x_861_);
lean_dec(v_x_861_);
lean_dec(v_register_860_);
v_r_863_ = lean_box(v_res_862_);
return v_r_863_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(lean_object* v_register_870_, lean_object* v_df_871_, lean_object* v_as_x27_872_, lean_object* v_b_873_){
_start:
{
if (lean_obj_tag(v_as_x27_872_) == 0)
{
lean_object* v___x_875_; 
lean_dec(v_df_871_);
lean_dec(v_register_870_);
v___x_875_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_875_, 0, v_b_873_);
return v___x_875_;
}
else
{
lean_object* v_head_876_; lean_object* v_tail_877_; uint8_t v___y_879_; uint8_t v___y_880_; uint8_t v___y_881_; uint8_t v___y_882_; uint8_t v___y_883_; uint8_t v___y_884_; uint8_t v___y_885_; lean_object* v_fields_915_; lean_object* v_body_916_; 
v_head_876_ = lean_ctor_get(v_as_x27_872_, 0);
v_tail_877_ = lean_ctor_get(v_as_x27_872_, 1);
v_fields_915_ = lean_ctor_get(v_head_876_, 0);
v_body_916_ = lean_ctor_get(v_fields_915_, 0);
if (lean_obj_tag(v_body_916_) == 6)
{
lean_object* v_decoded_917_; lean_object* v_mb_918_; uint8_t v___y_920_; uint8_t v___y_921_; uint8_t v___y_922_; uint8_t v___y_923_; uint8_t v___y_924_; uint8_t v___y_925_; uint8_t v___y_926_; uint8_t v___y_927_; uint8_t v___y_942_; uint8_t v___y_943_; uint8_t v___y_944_; uint8_t v___y_945_; uint8_t v___y_946_; uint8_t v___y_947_; lean_object* v___y_951_; uint8_t v___y_952_; uint8_t v___y_953_; uint8_t v___y_954_; uint8_t v___y_955_; uint8_t v___y_956_; lean_object* v___y_965_; uint8_t v___y_966_; uint8_t v___y_967_; lean_object* v___y_973_; uint8_t v___y_974_; uint8_t v___y_975_; lean_object* v___x_976_; uint8_t v___x_977_; 
v_decoded_917_ = lean_ctor_get(v_head_876_, 1);
v_mb_918_ = lean_ctor_get(v_body_916_, 1);
v___x_976_ = lean_unsigned_to_nat(0u);
v___x_977_ = lean_nat_dec_eq(v_mb_918_, v___x_976_);
if (v___x_977_ == 0)
{
uint8_t v___x_978_; lean_object* v___x_979_; uint8_t v___x_980_; 
v___x_978_ = 1;
v___x_979_ = lean_unsigned_to_nat(5u);
v___x_980_ = lean_nat_dec_eq(v_register_870_, v___x_979_);
if (v___x_980_ == 0)
{
lean_object* v___x_981_; uint8_t v___x_982_; 
v___x_981_ = lean_unsigned_to_nat(101u);
v___x_982_ = lean_nat_dec_eq(v_register_870_, v___x_981_);
if (v___x_982_ == 0)
{
v___y_965_ = v___x_979_;
v___y_966_ = v___x_978_;
v___y_967_ = v___x_978_;
goto v___jp_964_;
}
else
{
v___y_973_ = v___x_979_;
v___y_974_ = v___x_978_;
v___y_975_ = v___x_980_;
goto v___jp_972_;
}
}
else
{
lean_object* v___x_983_; uint8_t v___x_984_; 
v___x_983_ = lean_unsigned_to_nat(20u);
v___x_984_ = lean_nat_dec_eq(v_df_871_, v___x_983_);
if (v___x_984_ == 0)
{
v___y_973_ = v___x_979_;
v___y_974_ = v___x_978_;
v___y_975_ = v___x_984_;
goto v___jp_972_;
}
else
{
lean_object* v___x_985_; lean_object* v___x_986_; lean_object* v___x_987_; uint8_t v___x_988_; 
v___x_985_ = lean_unsigned_to_nat(1u);
v___x_986_ = lp_lean1090_Lean1090_Impl_payloadBits(v_mb_918_, v___x_985_, v___x_979_);
v___x_987_ = lean_unsigned_to_nat(9u);
v___x_988_ = lean_nat_dec_le(v___x_987_, v___x_986_);
if (v___x_988_ == 0)
{
lean_dec(v___x_986_);
v___y_973_ = v___x_979_;
v___y_974_ = v___x_978_;
v___y_975_ = v___x_988_;
goto v___jp_972_;
}
else
{
lean_object* v___x_989_; uint8_t v___x_990_; 
v___x_989_ = lean_unsigned_to_nat(22u);
v___x_990_ = lean_nat_dec_lt(v___x_986_, v___x_989_);
if (v___x_990_ == 0)
{
lean_dec(v___x_986_);
v___y_973_ = v___x_979_;
v___y_974_ = v___x_978_;
v___y_975_ = v___x_990_;
goto v___jp_972_;
}
else
{
lean_object* v___x_991_; uint8_t v___x_992_; 
v___x_991_ = lean_unsigned_to_nat(19u);
v___x_992_ = lean_nat_dec_eq(v___x_986_, v___x_991_);
lean_dec(v___x_986_);
if (v___x_992_ == 0)
{
v___y_973_ = v___x_979_;
v___y_974_ = v___x_978_;
v___y_975_ = v___x_980_;
goto v___jp_972_;
}
else
{
v___y_942_ = v___x_977_;
v___y_943_ = v___x_977_;
v___y_944_ = v___x_978_;
v___y_945_ = v___x_977_;
v___y_946_ = v___x_977_;
v___y_947_ = v___x_977_;
goto v___jp_941_;
}
}
}
}
}
}
else
{
uint8_t v___x_993_; 
v___x_993_ = 0;
v___y_942_ = v___x_993_;
v___y_943_ = v___x_993_;
v___y_944_ = v___x_993_;
v___y_945_ = v___x_993_;
v___y_946_ = v___x_993_;
v___y_947_ = v___x_993_;
goto v___jp_941_;
}
v___jp_919_:
{
if (v___y_927_ == 0)
{
lean_object* v___x_928_; lean_object* v___x_929_; lean_object* v___x_930_; lean_object* v___x_931_; lean_object* v___x_932_; lean_object* v___x_933_; lean_object* v___x_934_; lean_object* v___x_935_; lean_object* v___x_936_; lean_object* v___x_937_; lean_object* v___x_938_; lean_object* v___x_939_; lean_object* v___x_940_; 
lean_dec_ref(v_b_873_);
v___x_928_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__0));
v___x_929_ = l_Nat_reprFast(v_df_871_);
v___x_930_ = lean_string_append(v___x_928_, v___x_929_);
lean_dec_ref(v___x_929_);
v___x_931_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__1));
v___x_932_ = lean_string_append(v___x_930_, v___x_931_);
v___x_933_ = l_Nat_reprFast(v_register_870_);
v___x_934_ = lean_string_append(v___x_932_, v___x_933_);
lean_dec_ref(v___x_933_);
v___x_935_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__2));
v___x_936_ = lean_string_append(v___x_934_, v___x_935_);
lean_inc(v_mb_918_);
v___x_937_ = l_Nat_reprFast(v_mb_918_);
v___x_938_ = lean_string_append(v___x_936_, v___x_937_);
lean_dec_ref(v___x_937_);
v___x_939_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_939_, 0, v___x_938_);
v___x_940_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_940_, 0, v___x_939_);
return v___x_940_;
}
else
{
v___y_879_ = v___y_920_;
v___y_880_ = v___y_921_;
v___y_881_ = v___y_922_;
v___y_882_ = v___y_923_;
v___y_883_ = v___y_925_;
v___y_884_ = v___y_924_;
v___y_885_ = v___y_926_;
goto v___jp_878_;
}
}
v___jp_941_:
{
lean_object* v_commB_948_; uint8_t v___x_949_; 
v_commB_948_ = lean_ctor_get(v_decoded_917_, 6);
v___x_949_ = l_List_any___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__0(v_register_870_, v_commB_948_);
if (v___x_949_ == 0)
{
if (v___y_947_ == 0)
{
v___y_879_ = v___y_942_;
v___y_880_ = v___x_949_;
v___y_881_ = v___y_947_;
v___y_882_ = v___y_943_;
v___y_883_ = v___y_945_;
v___y_884_ = v___y_944_;
v___y_885_ = v___y_946_;
goto v___jp_878_;
}
else
{
v___y_920_ = v___y_942_;
v___y_921_ = v___x_949_;
v___y_922_ = v___y_947_;
v___y_923_ = v___y_943_;
v___y_924_ = v___y_944_;
v___y_925_ = v___y_945_;
v___y_926_ = v___y_946_;
v___y_927_ = v___x_949_;
goto v___jp_919_;
}
}
else
{
v___y_920_ = v___y_942_;
v___y_921_ = v___x_949_;
v___y_922_ = v___y_947_;
v___y_923_ = v___y_943_;
v___y_924_ = v___y_944_;
v___y_925_ = v___y_945_;
v___y_926_ = v___y_946_;
v___y_927_ = v___y_947_;
goto v___jp_919_;
}
}
v___jp_950_:
{
if (v___y_952_ == 0)
{
v___y_942_ = v___y_956_;
v___y_943_ = v___y_952_;
v___y_944_ = v___y_954_;
v___y_945_ = v___y_953_;
v___y_946_ = v___y_955_;
v___y_947_ = v___y_952_;
goto v___jp_941_;
}
else
{
uint8_t v___x_957_; 
v___x_957_ = lean_nat_dec_eq(v_register_870_, v___y_951_);
if (v___x_957_ == 0)
{
lean_object* v___x_958_; uint8_t v___x_959_; 
v___x_958_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored));
v___x_959_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_870_, v___x_958_);
if (v___x_959_ == 0)
{
v___y_942_ = v___y_956_;
v___y_943_ = v___y_952_;
v___y_944_ = v___y_954_;
v___y_945_ = v___y_953_;
v___y_946_ = v___y_955_;
v___y_947_ = v___y_952_;
goto v___jp_941_;
}
else
{
v___y_942_ = v___y_956_;
v___y_943_ = v___y_952_;
v___y_944_ = v___y_954_;
v___y_945_ = v___y_953_;
v___y_946_ = v___y_955_;
v___y_947_ = v___y_956_;
goto v___jp_941_;
}
}
else
{
lean_object* v___x_960_; lean_object* v___x_961_; lean_object* v___x_962_; uint8_t v___x_963_; 
v___x_960_ = lean_alloc_closure((void*)(l_Int_instDecidableEq___boxed), 2, 0);
v___x_961_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_mb_918_);
v___x_962_ = lp_lean1090_Lean1090_Impl_frameOracleAltitude(v_fields_915_);
v___x_963_ = l_Option_instDecidableEq___redArg(v___x_960_, v___x_961_, v___x_962_);
v___y_942_ = v___y_956_;
v___y_943_ = v___y_952_;
v___y_944_ = v___y_954_;
v___y_945_ = v___y_953_;
v___y_946_ = v___y_955_;
v___y_947_ = v___x_963_;
goto v___jp_941_;
}
}
}
v___jp_964_:
{
uint8_t v___x_968_; 
v___x_968_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_870_, v_mb_918_);
if (v___x_968_ == 0)
{
v___y_951_ = v___y_965_;
v___y_952_ = v___x_968_;
v___y_953_ = v___x_968_;
v___y_954_ = v___y_966_;
v___y_955_ = v___y_967_;
v___y_956_ = v___x_968_;
goto v___jp_950_;
}
else
{
lean_object* v___x_969_; uint8_t v___x_970_; 
v___x_969_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scored));
v___x_970_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_register_870_, v___x_969_);
if (v___x_970_ == 0)
{
v___y_951_ = v___y_965_;
v___y_952_ = v___x_968_;
v___y_953_ = v___x_970_;
v___y_954_ = v___y_966_;
v___y_955_ = v___y_967_;
v___y_956_ = v___x_970_;
goto v___jp_950_;
}
else
{
uint8_t v___x_971_; 
v___x_971_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_870_, v_mb_918_);
v___y_951_ = v___y_965_;
v___y_952_ = v___x_968_;
v___y_953_ = v___x_970_;
v___y_954_ = v___y_966_;
v___y_955_ = v___y_967_;
v___y_956_ = v___x_971_;
goto v___jp_950_;
}
}
}
v___jp_972_:
{
if (v___y_975_ == 0)
{
v___y_942_ = v___y_975_;
v___y_943_ = v___y_975_;
v___y_944_ = v___y_974_;
v___y_945_ = v___y_975_;
v___y_946_ = v___y_975_;
v___y_947_ = v___y_975_;
goto v___jp_941_;
}
else
{
v___y_965_ = v___y_973_;
v___y_966_ = v___y_974_;
v___y_967_ = v___y_975_;
goto v___jp_964_;
}
}
}
else
{
lean_object* v___x_994_; lean_object* v___x_995_; 
lean_dec_ref(v_b_873_);
lean_dec(v_df_871_);
lean_dec(v_register_870_);
v___x_994_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___closed__4));
v___x_995_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_995_, 0, v___x_994_);
return v___x_995_;
}
v___jp_878_:
{
lean_object* v_nonempty_886_; lean_object* v_hardAttempts_887_; lean_object* v_hardPass_888_; lean_object* v_scoreAttempts_889_; lean_object* v_scorePass_890_; lean_object* v_eligible_891_; lean_object* v_accepted_892_; lean_object* v___x_894_; uint8_t v_isShared_895_; uint8_t v_isSharedCheck_914_; 
v_nonempty_886_ = lean_ctor_get(v_b_873_, 0);
v_hardAttempts_887_ = lean_ctor_get(v_b_873_, 1);
v_hardPass_888_ = lean_ctor_get(v_b_873_, 2);
v_scoreAttempts_889_ = lean_ctor_get(v_b_873_, 3);
v_scorePass_890_ = lean_ctor_get(v_b_873_, 4);
v_eligible_891_ = lean_ctor_get(v_b_873_, 5);
v_accepted_892_ = lean_ctor_get(v_b_873_, 6);
v_isSharedCheck_914_ = !lean_is_exclusive(v_b_873_);
if (v_isSharedCheck_914_ == 0)
{
v___x_894_ = v_b_873_;
v_isShared_895_ = v_isSharedCheck_914_;
goto v_resetjp_893_;
}
else
{
lean_inc(v_accepted_892_);
lean_inc(v_eligible_891_);
lean_inc(v_scorePass_890_);
lean_inc(v_scoreAttempts_889_);
lean_inc(v_hardPass_888_);
lean_inc(v_hardAttempts_887_);
lean_inc(v_nonempty_886_);
lean_dec(v_b_873_);
v___x_894_ = lean_box(0);
v_isShared_895_ = v_isSharedCheck_914_;
goto v_resetjp_893_;
}
v_resetjp_893_:
{
lean_object* v___x_896_; lean_object* v___x_897_; lean_object* v___x_898_; lean_object* v___x_899_; lean_object* v___x_900_; lean_object* v___x_901_; lean_object* v___x_902_; lean_object* v___x_903_; lean_object* v___x_904_; lean_object* v___x_905_; lean_object* v___x_906_; lean_object* v___x_907_; lean_object* v___x_908_; lean_object* v___x_909_; lean_object* v___x_911_; 
v___x_896_ = l_Bool_toNat(v___y_884_);
v___x_897_ = lean_nat_add(v_nonempty_886_, v___x_896_);
lean_dec(v___x_896_);
lean_dec(v_nonempty_886_);
v___x_898_ = l_Bool_toNat(v___y_885_);
v___x_899_ = lean_nat_add(v_hardAttempts_887_, v___x_898_);
lean_dec(v___x_898_);
lean_dec(v_hardAttempts_887_);
v___x_900_ = l_Bool_toNat(v___y_882_);
v___x_901_ = lean_nat_add(v_hardPass_888_, v___x_900_);
lean_dec(v___x_900_);
lean_dec(v_hardPass_888_);
v___x_902_ = l_Bool_toNat(v___y_883_);
v___x_903_ = lean_nat_add(v_scoreAttempts_889_, v___x_902_);
lean_dec(v___x_902_);
lean_dec(v_scoreAttempts_889_);
v___x_904_ = l_Bool_toNat(v___y_879_);
v___x_905_ = lean_nat_add(v_scorePass_890_, v___x_904_);
lean_dec(v___x_904_);
lean_dec(v_scorePass_890_);
v___x_906_ = l_Bool_toNat(v___y_881_);
v___x_907_ = lean_nat_add(v_eligible_891_, v___x_906_);
lean_dec(v___x_906_);
lean_dec(v_eligible_891_);
v___x_908_ = l_Bool_toNat(v___y_880_);
v___x_909_ = lean_nat_add(v_accepted_892_, v___x_908_);
lean_dec(v___x_908_);
lean_dec(v_accepted_892_);
if (v_isShared_895_ == 0)
{
lean_ctor_set(v___x_894_, 6, v___x_909_);
lean_ctor_set(v___x_894_, 5, v___x_907_);
lean_ctor_set(v___x_894_, 4, v___x_905_);
lean_ctor_set(v___x_894_, 3, v___x_903_);
lean_ctor_set(v___x_894_, 2, v___x_901_);
lean_ctor_set(v___x_894_, 1, v___x_899_);
lean_ctor_set(v___x_894_, 0, v___x_897_);
v___x_911_ = v___x_894_;
goto v_reusejp_910_;
}
else
{
lean_object* v_reuseFailAlloc_913_; 
v_reuseFailAlloc_913_ = lean_alloc_ctor(0, 7, 0);
lean_ctor_set(v_reuseFailAlloc_913_, 0, v___x_897_);
lean_ctor_set(v_reuseFailAlloc_913_, 1, v___x_899_);
lean_ctor_set(v_reuseFailAlloc_913_, 2, v___x_901_);
lean_ctor_set(v_reuseFailAlloc_913_, 3, v___x_903_);
lean_ctor_set(v_reuseFailAlloc_913_, 4, v___x_905_);
lean_ctor_set(v_reuseFailAlloc_913_, 5, v___x_907_);
lean_ctor_set(v_reuseFailAlloc_913_, 6, v___x_909_);
v___x_911_ = v_reuseFailAlloc_913_;
goto v_reusejp_910_;
}
v_reusejp_910_:
{
v_as_x27_872_ = v_tail_877_;
v_b_873_ = v___x_911_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg___boxed(lean_object* v_register_996_, lean_object* v_df_997_, lean_object* v_as_x27_998_, lean_object* v_b_999_, lean_object* v___y_1000_){
_start:
{
lean_object* v_res_1001_; 
v_res_1001_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(v_register_996_, v_df_997_, v_as_x27_998_, v_b_999_);
lean_dec(v_as_x27_998_);
return v_res_1001_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus(lean_object* v_df_1004_, lean_object* v_register_1005_, lean_object* v_messages_1006_){
_start:
{
lean_object* v_count_1008_; lean_object* v___x_1009_; 
v_count_1008_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus___closed__0));
v___x_1009_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(v_register_1005_, v_df_1004_, v_messages_1006_, v_count_1008_);
return v___x_1009_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus___boxed(lean_object* v_df_1010_, lean_object* v_register_1011_, lean_object* v_messages_1012_, lean_object* v_a_1013_){
_start:
{
lean_object* v_res_1014_; 
v_res_1014_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus(v_df_1010_, v_register_1011_, v_messages_1012_);
lean_dec(v_messages_1012_);
return v_res_1014_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1(lean_object* v_register_1015_, lean_object* v_df_1016_, lean_object* v_as_1017_, lean_object* v_as_x27_1018_, lean_object* v_b_1019_, lean_object* v_a_1020_){
_start:
{
lean_object* v___x_1022_; 
v___x_1022_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___redArg(v_register_1015_, v_df_1016_, v_as_x27_1018_, v_b_1019_);
return v___x_1022_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1___boxed(lean_object* v_register_1023_, lean_object* v_df_1024_, lean_object* v_as_1025_, lean_object* v_as_x27_1026_, lean_object* v_b_1027_, lean_object* v_a_1028_, lean_object* v___y_1029_){
_start:
{
lean_object* v_res_1030_; 
v_res_1030_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus_spec__1(v_register_1023_, v_df_1024_, v_as_1025_, v_as_x27_1026_, v_b_1027_, v_a_1028_);
lean_dec(v_as_x27_1026_);
lean_dec(v_as_1025_);
return v_res_1030_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(lean_object* v_a_1041_, lean_object* v_a_1042_, lean_object* v_as_x27_1043_, lean_object* v_b_1044_){
_start:
{
if (lean_obj_tag(v_as_x27_1043_) == 0)
{
lean_object* v___x_1046_; 
lean_dec(v_a_1041_);
v___x_1046_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1046_, 0, v_b_1044_);
return v___x_1046_;
}
else
{
lean_object* v_head_1047_; lean_object* v_tail_1048_; lean_object* v_rows_1049_; lean_object* v___x_1050_; 
v_head_1047_ = lean_ctor_get(v_as_x27_1043_, 0);
v_tail_1048_ = lean_ctor_get(v_as_x27_1043_, 1);
v_rows_1049_ = lean_box(0);
lean_inc(v_head_1047_);
lean_inc(v_a_1041_);
v___x_1050_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_registerCensus(v_a_1041_, v_head_1047_, v_a_1042_);
if (lean_obj_tag(v___x_1050_) == 0)
{
lean_object* v_a_1051_; lean_object* v_nonempty_1052_; lean_object* v_hardAttempts_1053_; lean_object* v_hardPass_1054_; lean_object* v_scoreAttempts_1055_; lean_object* v_scorePass_1056_; lean_object* v_eligible_1057_; lean_object* v_accepted_1058_; lean_object* v___x_1059_; lean_object* v___x_1060_; lean_object* v___x_1061_; lean_object* v___x_1062_; lean_object* v___x_1063_; lean_object* v___x_1064_; lean_object* v___x_1065_; lean_object* v___x_1066_; lean_object* v___x_1067_; lean_object* v___x_1068_; lean_object* v___x_1069_; lean_object* v___x_1070_; lean_object* v___x_1071_; lean_object* v___x_1072_; lean_object* v___x_1073_; lean_object* v___x_1074_; lean_object* v___x_1075_; lean_object* v___x_1076_; lean_object* v___x_1077_; lean_object* v___x_1078_; lean_object* v___x_1079_; lean_object* v___x_1080_; lean_object* v___x_1081_; lean_object* v___x_1082_; lean_object* v___x_1083_; lean_object* v___x_1084_; lean_object* v___x_1085_; lean_object* v___x_1086_; lean_object* v___x_1087_; lean_object* v___x_1088_; lean_object* v___x_1089_; lean_object* v___x_1090_; lean_object* v___x_1091_; lean_object* v___x_1092_; lean_object* v___x_1093_; lean_object* v___x_1094_; lean_object* v___x_1095_; lean_object* v___x_1096_; lean_object* v___x_1097_; lean_object* v___x_1098_; lean_object* v___x_1099_; lean_object* v___x_1100_; lean_object* v___x_1101_; lean_object* v___x_1102_; lean_object* v___x_1103_; lean_object* v___x_1104_; lean_object* v___x_1105_; lean_object* v___x_1106_; lean_object* v___x_1107_; lean_object* v___x_1108_; lean_object* v___x_1109_; lean_object* v___x_1110_; 
v_a_1051_ = lean_ctor_get(v___x_1050_, 0);
lean_inc(v_a_1051_);
lean_dec_ref_known(v___x_1050_, 1);
v_nonempty_1052_ = lean_ctor_get(v_a_1051_, 0);
lean_inc(v_nonempty_1052_);
v_hardAttempts_1053_ = lean_ctor_get(v_a_1051_, 1);
lean_inc(v_hardAttempts_1053_);
v_hardPass_1054_ = lean_ctor_get(v_a_1051_, 2);
lean_inc(v_hardPass_1054_);
v_scoreAttempts_1055_ = lean_ctor_get(v_a_1051_, 3);
lean_inc(v_scoreAttempts_1055_);
v_scorePass_1056_ = lean_ctor_get(v_a_1051_, 4);
lean_inc(v_scorePass_1056_);
v_eligible_1057_ = lean_ctor_get(v_a_1051_, 5);
lean_inc(v_eligible_1057_);
v_accepted_1058_ = lean_ctor_get(v_a_1051_, 6);
lean_inc(v_accepted_1058_);
lean_dec(v_a_1051_);
v___x_1059_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__0));
lean_inc(v_head_1047_);
v___x_1060_ = l_Lean_JsonNumber_fromNat(v_head_1047_);
v___x_1061_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1061_, 0, v___x_1060_);
v___x_1062_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1062_, 0, v___x_1059_);
lean_ctor_set(v___x_1062_, 1, v___x_1061_);
v___x_1063_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__1));
v___x_1064_ = l_List_lengthTR___redArg(v_a_1042_);
v___x_1065_ = l_Lean_JsonNumber_fromNat(v___x_1064_);
v___x_1066_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1066_, 0, v___x_1065_);
v___x_1067_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1067_, 0, v___x_1063_);
lean_ctor_set(v___x_1067_, 1, v___x_1066_);
v___x_1068_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__2));
v___x_1069_ = l_Lean_JsonNumber_fromNat(v_nonempty_1052_);
v___x_1070_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1070_, 0, v___x_1069_);
v___x_1071_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1071_, 0, v___x_1068_);
lean_ctor_set(v___x_1071_, 1, v___x_1070_);
v___x_1072_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__3));
v___x_1073_ = l_Lean_JsonNumber_fromNat(v_hardAttempts_1053_);
v___x_1074_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1074_, 0, v___x_1073_);
v___x_1075_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1075_, 0, v___x_1072_);
lean_ctor_set(v___x_1075_, 1, v___x_1074_);
v___x_1076_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__4));
v___x_1077_ = l_Lean_JsonNumber_fromNat(v_hardPass_1054_);
v___x_1078_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1078_, 0, v___x_1077_);
v___x_1079_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1079_, 0, v___x_1076_);
lean_ctor_set(v___x_1079_, 1, v___x_1078_);
v___x_1080_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__5));
v___x_1081_ = l_Lean_JsonNumber_fromNat(v_scoreAttempts_1055_);
v___x_1082_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1082_, 0, v___x_1081_);
v___x_1083_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1083_, 0, v___x_1080_);
lean_ctor_set(v___x_1083_, 1, v___x_1082_);
v___x_1084_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__6));
v___x_1085_ = l_Lean_JsonNumber_fromNat(v_scorePass_1056_);
v___x_1086_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1086_, 0, v___x_1085_);
v___x_1087_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1087_, 0, v___x_1084_);
lean_ctor_set(v___x_1087_, 1, v___x_1086_);
v___x_1088_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__7));
v___x_1089_ = l_Lean_JsonNumber_fromNat(v_eligible_1057_);
v___x_1090_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1090_, 0, v___x_1089_);
v___x_1091_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1091_, 0, v___x_1088_);
lean_ctor_set(v___x_1091_, 1, v___x_1090_);
v___x_1092_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__8));
v___x_1093_ = l_Lean_JsonNumber_fromNat(v_accepted_1058_);
v___x_1094_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1094_, 0, v___x_1093_);
lean_inc_ref(v___x_1094_);
v___x_1095_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1095_, 0, v___x_1092_);
lean_ctor_set(v___x_1095_, 1, v___x_1094_);
v___x_1096_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__9));
v___x_1097_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1097_, 0, v___x_1096_);
lean_ctor_set(v___x_1097_, 1, v___x_1094_);
v___x_1098_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1098_, 0, v___x_1097_);
lean_ctor_set(v___x_1098_, 1, v_rows_1049_);
v___x_1099_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1099_, 0, v___x_1095_);
lean_ctor_set(v___x_1099_, 1, v___x_1098_);
v___x_1100_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1100_, 0, v___x_1091_);
lean_ctor_set(v___x_1100_, 1, v___x_1099_);
v___x_1101_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1101_, 0, v___x_1087_);
lean_ctor_set(v___x_1101_, 1, v___x_1100_);
v___x_1102_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1102_, 0, v___x_1083_);
lean_ctor_set(v___x_1102_, 1, v___x_1101_);
v___x_1103_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1103_, 0, v___x_1079_);
lean_ctor_set(v___x_1103_, 1, v___x_1102_);
v___x_1104_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1104_, 0, v___x_1075_);
lean_ctor_set(v___x_1104_, 1, v___x_1103_);
v___x_1105_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1105_, 0, v___x_1071_);
lean_ctor_set(v___x_1105_, 1, v___x_1104_);
v___x_1106_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1106_, 0, v___x_1067_);
lean_ctor_set(v___x_1106_, 1, v___x_1105_);
v___x_1107_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1107_, 0, v___x_1062_);
lean_ctor_set(v___x_1107_, 1, v___x_1106_);
v___x_1108_ = l_Lean_Json_mkObj(v___x_1107_);
lean_dec_ref_known(v___x_1107_, 2);
v___x_1109_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1109_, 0, v___x_1108_);
lean_ctor_set(v___x_1109_, 1, v_rows_1049_);
v___x_1110_ = l_List_appendTR___redArg(v_b_1044_, v___x_1109_);
v_as_x27_1043_ = v_tail_1048_;
v_b_1044_ = v___x_1110_;
goto _start;
}
else
{
lean_object* v_a_1112_; lean_object* v___x_1114_; uint8_t v_isShared_1115_; uint8_t v_isSharedCheck_1119_; 
lean_dec(v_b_1044_);
lean_dec(v_a_1041_);
v_a_1112_ = lean_ctor_get(v___x_1050_, 0);
v_isSharedCheck_1119_ = !lean_is_exclusive(v___x_1050_);
if (v_isSharedCheck_1119_ == 0)
{
v___x_1114_ = v___x_1050_;
v_isShared_1115_ = v_isSharedCheck_1119_;
goto v_resetjp_1113_;
}
else
{
lean_inc(v_a_1112_);
lean_dec(v___x_1050_);
v___x_1114_ = lean_box(0);
v_isShared_1115_ = v_isSharedCheck_1119_;
goto v_resetjp_1113_;
}
v_resetjp_1113_:
{
lean_object* v___x_1117_; 
if (v_isShared_1115_ == 0)
{
v___x_1117_ = v___x_1114_;
goto v_reusejp_1116_;
}
else
{
lean_object* v_reuseFailAlloc_1118_; 
v_reuseFailAlloc_1118_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1118_, 0, v_a_1112_);
v___x_1117_ = v_reuseFailAlloc_1118_;
goto v_reusejp_1116_;
}
v_reusejp_1116_:
{
return v___x_1117_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___boxed(lean_object* v_a_1120_, lean_object* v_a_1121_, lean_object* v_as_x27_1122_, lean_object* v_b_1123_, lean_object* v___y_1124_){
_start:
{
lean_object* v_res_1125_; 
v_res_1125_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(v_a_1120_, v_a_1121_, v_as_x27_1122_, v_b_1123_);
lean_dec(v_as_x27_1122_);
lean_dec(v_a_1121_);
return v_res_1125_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(lean_object* v_inputs_1129_, lean_object* v_a_1130_, lean_object* v_output_1131_, lean_object* v_range_1132_, lean_object* v_b_1133_, lean_object* v_i_1134_){
_start:
{
lean_object* v_stop_1136_; lean_object* v_step_1137_; lean_object* v_a_1139_; uint8_t v___x_1142_; 
v_stop_1136_ = lean_ctor_get(v_range_1132_, 1);
v_step_1137_ = lean_ctor_get(v_range_1132_, 2);
v___x_1142_ = lean_nat_dec_lt(v_i_1134_, v_stop_1136_);
if (v___x_1142_ == 0)
{
lean_object* v___x_1143_; 
lean_dec(v_i_1134_);
v___x_1143_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1143_, 0, v_b_1133_);
return v___x_1143_;
}
else
{
lean_object* v___x_1144_; uint8_t v___x_1145_; 
v___x_1144_ = lean_array_get_size(v_inputs_1129_);
v___x_1145_ = lean_nat_dec_lt(v_i_1134_, v___x_1144_);
if (v___x_1145_ == 0)
{
lean_object* v___x_1146_; lean_object* v___x_1147_; 
lean_dec(v_i_1134_);
lean_dec(v_b_1133_);
v___x_1146_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___closed__1));
v___x_1147_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1147_, 0, v___x_1146_);
return v___x_1147_;
}
else
{
lean_object* v___x_1148_; lean_object* v_df_1149_; lean_object* v___x_1151_; uint8_t v_isShared_1152_; uint8_t v_isSharedCheck_1158_; 
v___x_1148_ = lean_array_fget(v_inputs_1129_, v_i_1134_);
v_df_1149_ = lean_ctor_get(v___x_1148_, 0);
v_isSharedCheck_1158_ = !lean_is_exclusive(v___x_1148_);
if (v_isSharedCheck_1158_ == 0)
{
lean_object* v_unused_1159_; 
v_unused_1159_ = lean_ctor_get(v___x_1148_, 1);
lean_dec(v_unused_1159_);
v___x_1151_ = v___x_1148_;
v_isShared_1152_ = v_isSharedCheck_1158_;
goto v_resetjp_1150_;
}
else
{
lean_inc(v_df_1149_);
lean_dec(v___x_1148_);
v___x_1151_ = lean_box(0);
v_isShared_1152_ = v_isSharedCheck_1158_;
goto v_resetjp_1150_;
}
v_resetjp_1150_:
{
uint8_t v___x_1153_; 
v___x_1153_ = lean_nat_dec_eq(v_df_1149_, v_a_1130_);
lean_dec(v_df_1149_);
if (v___x_1153_ == 0)
{
lean_del_object(v___x_1151_);
v_a_1139_ = v_b_1133_;
goto v___jp_1138_;
}
else
{
lean_object* v___x_1154_; lean_object* v___x_1156_; 
v___x_1154_ = lean_array_fget_borrowed(v_output_1131_, v_i_1134_);
lean_inc(v___x_1154_);
if (v_isShared_1152_ == 0)
{
lean_ctor_set_tag(v___x_1151_, 1);
lean_ctor_set(v___x_1151_, 1, v_b_1133_);
lean_ctor_set(v___x_1151_, 0, v___x_1154_);
v___x_1156_ = v___x_1151_;
goto v_reusejp_1155_;
}
else
{
lean_object* v_reuseFailAlloc_1157_; 
v_reuseFailAlloc_1157_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1157_, 0, v___x_1154_);
lean_ctor_set(v_reuseFailAlloc_1157_, 1, v_b_1133_);
v___x_1156_ = v_reuseFailAlloc_1157_;
goto v_reusejp_1155_;
}
v_reusejp_1155_:
{
v_a_1139_ = v___x_1156_;
goto v___jp_1138_;
}
}
}
}
}
v___jp_1138_:
{
lean_object* v___x_1140_; 
v___x_1140_ = lean_nat_add(v_i_1134_, v_step_1137_);
lean_dec(v_i_1134_);
v_b_1133_ = v_a_1139_;
v_i_1134_ = v___x_1140_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg___boxed(lean_object* v_inputs_1160_, lean_object* v_a_1161_, lean_object* v_output_1162_, lean_object* v_range_1163_, lean_object* v_b_1164_, lean_object* v_i_1165_, lean_object* v___y_1166_){
_start:
{
lean_object* v_res_1167_; 
v_res_1167_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(v_inputs_1160_, v_a_1161_, v_output_1162_, v_range_1163_, v_b_1164_, v_i_1165_);
lean_dec_ref(v_range_1163_);
lean_dec_ref(v_output_1162_);
lean_dec(v_a_1161_);
lean_dec_ref(v_inputs_1160_);
return v_res_1167_;
}
}
LEAN_EXPORT uint8_t l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___lam__0(lean_object* v_a_1168_, lean_object* v_b_1169_){
_start:
{
lean_object* v_fst_1170_; lean_object* v_fst_1171_; uint8_t v___x_1172_; 
v_fst_1170_ = lean_ctor_get(v_a_1168_, 0);
v_fst_1171_ = lean_ctor_get(v_b_1169_, 0);
v___x_1172_ = lean_nat_dec_le(v_fst_1170_, v_fst_1171_);
return v___x_1172_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___lam__0___boxed(lean_object* v_a_1173_, lean_object* v_b_1174_){
_start:
{
uint8_t v_res_1175_; lean_object* v_r_1176_; 
v_res_1175_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___lam__0(v_a_1173_, v_b_1174_);
lean_dec_ref(v_b_1174_);
lean_dec_ref(v_a_1173_);
v_r_1176_ = lean_box(v_res_1175_);
return v_r_1176_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3(lean_object* v_a_1178_, lean_object* v_a_1179_){
_start:
{
if (lean_obj_tag(v_a_1178_) == 0)
{
lean_object* v___x_1180_; 
v___x_1180_ = l_List_reverse___redArg(v_a_1179_);
return v___x_1180_;
}
else
{
lean_object* v_head_1181_; lean_object* v_tail_1182_; lean_object* v___x_1184_; uint8_t v_isShared_1185_; uint8_t v_isSharedCheck_1210_; 
v_head_1181_ = lean_ctor_get(v_a_1178_, 0);
v_tail_1182_ = lean_ctor_get(v_a_1178_, 1);
v_isSharedCheck_1210_ = !lean_is_exclusive(v_a_1178_);
if (v_isSharedCheck_1210_ == 0)
{
v___x_1184_ = v_a_1178_;
v_isShared_1185_ = v_isSharedCheck_1210_;
goto v_resetjp_1183_;
}
else
{
lean_inc(v_tail_1182_);
lean_inc(v_head_1181_);
lean_dec(v_a_1178_);
v___x_1184_ = lean_box(0);
v_isShared_1185_ = v_isSharedCheck_1210_;
goto v_resetjp_1183_;
}
v_resetjp_1183_:
{
lean_object* v_fst_1186_; lean_object* v_snd_1187_; lean_object* v___x_1189_; uint8_t v_isShared_1190_; uint8_t v_isSharedCheck_1209_; 
v_fst_1186_ = lean_ctor_get(v_head_1181_, 0);
v_snd_1187_ = lean_ctor_get(v_head_1181_, 1);
v_isSharedCheck_1209_ = !lean_is_exclusive(v_head_1181_);
if (v_isSharedCheck_1209_ == 0)
{
v___x_1189_ = v_head_1181_;
v_isShared_1190_ = v_isSharedCheck_1209_;
goto v_resetjp_1188_;
}
else
{
lean_inc(v_snd_1187_);
lean_inc(v_fst_1186_);
lean_dec(v_head_1181_);
v___x_1189_ = lean_box(0);
v_isShared_1190_ = v_isSharedCheck_1209_;
goto v_resetjp_1188_;
}
v_resetjp_1188_:
{
lean_object* v___x_1191_; lean_object* v___x_1192_; lean_object* v___x_1193_; lean_object* v___x_1194_; lean_object* v___x_1196_; 
v___x_1191_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0));
v___x_1192_ = ((lean_object*)(l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3___closed__0));
v___x_1193_ = l_Lean_JsonNumber_fromNat(v_fst_1186_);
v___x_1194_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1194_, 0, v___x_1193_);
if (v_isShared_1190_ == 0)
{
lean_ctor_set(v___x_1189_, 1, v___x_1194_);
lean_ctor_set(v___x_1189_, 0, v___x_1192_);
v___x_1196_ = v___x_1189_;
goto v_reusejp_1195_;
}
else
{
lean_object* v_reuseFailAlloc_1208_; 
v_reuseFailAlloc_1208_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1208_, 0, v___x_1192_);
lean_ctor_set(v_reuseFailAlloc_1208_, 1, v___x_1194_);
v___x_1196_ = v_reuseFailAlloc_1208_;
goto v_reusejp_1195_;
}
v_reusejp_1195_:
{
lean_object* v___x_1197_; lean_object* v___x_1198_; lean_object* v___x_1199_; lean_object* v___x_1200_; lean_object* v___x_1202_; 
v___x_1197_ = l_Lean_JsonNumber_fromNat(v_snd_1187_);
v___x_1198_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1198_, 0, v___x_1197_);
v___x_1199_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1199_, 0, v___x_1191_);
lean_ctor_set(v___x_1199_, 1, v___x_1198_);
v___x_1200_ = lean_box(0);
if (v_isShared_1185_ == 0)
{
lean_ctor_set(v___x_1184_, 1, v___x_1200_);
lean_ctor_set(v___x_1184_, 0, v___x_1199_);
v___x_1202_ = v___x_1184_;
goto v_reusejp_1201_;
}
else
{
lean_object* v_reuseFailAlloc_1207_; 
v_reuseFailAlloc_1207_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1207_, 0, v___x_1199_);
lean_ctor_set(v_reuseFailAlloc_1207_, 1, v___x_1200_);
v___x_1202_ = v_reuseFailAlloc_1207_;
goto v_reusejp_1201_;
}
v_reusejp_1201_:
{
lean_object* v___x_1203_; lean_object* v___x_1204_; lean_object* v___x_1205_; 
v___x_1203_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1203_, 0, v___x_1196_);
lean_ctor_set(v___x_1203_, 1, v___x_1202_);
v___x_1204_ = l_Lean_Json_mkObj(v___x_1203_);
lean_dec_ref_known(v___x_1203_, 2);
v___x_1205_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1205_, 0, v___x_1204_);
lean_ctor_set(v___x_1205_, 1, v_a_1179_);
v_a_1178_ = v_tail_1182_;
v_a_1179_ = v___x_1205_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__2(lean_object* v_a_1211_, lean_object* v_a_1212_){
_start:
{
if (lean_obj_tag(v_a_1211_) == 0)
{
lean_object* v___x_1213_; 
v___x_1213_ = l_List_reverse___redArg(v_a_1212_);
return v___x_1213_;
}
else
{
lean_object* v_head_1214_; lean_object* v_tail_1215_; lean_object* v___x_1217_; uint8_t v_isShared_1218_; uint8_t v_isSharedCheck_1224_; 
v_head_1214_ = lean_ctor_get(v_a_1211_, 0);
v_tail_1215_ = lean_ctor_get(v_a_1211_, 1);
v_isSharedCheck_1224_ = !lean_is_exclusive(v_a_1211_);
if (v_isSharedCheck_1224_ == 0)
{
v___x_1217_ = v_a_1211_;
v_isShared_1218_ = v_isSharedCheck_1224_;
goto v_resetjp_1216_;
}
else
{
lean_inc(v_tail_1215_);
lean_inc(v_head_1214_);
lean_dec(v_a_1211_);
v___x_1217_ = lean_box(0);
v_isShared_1218_ = v_isSharedCheck_1224_;
goto v_resetjp_1216_;
}
v_resetjp_1216_:
{
lean_object* v_snd_1219_; lean_object* v___x_1221_; 
v_snd_1219_ = lean_ctor_get(v_head_1214_, 1);
lean_inc(v_snd_1219_);
lean_dec(v_head_1214_);
if (v_isShared_1218_ == 0)
{
lean_ctor_set(v___x_1217_, 1, v_a_1212_);
lean_ctor_set(v___x_1217_, 0, v_snd_1219_);
v___x_1221_ = v___x_1217_;
goto v_reusejp_1220_;
}
else
{
lean_object* v_reuseFailAlloc_1223_; 
v_reuseFailAlloc_1223_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1223_, 0, v_snd_1219_);
lean_ctor_set(v_reuseFailAlloc_1223_, 1, v_a_1212_);
v___x_1221_ = v_reuseFailAlloc_1223_;
goto v_reusejp_1220_;
}
v_reusejp_1220_:
{
v_a_1211_ = v_tail_1215_;
v_a_1212_ = v___x_1221_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(lean_object* v_as_x27_1225_, lean_object* v_b_1226_){
_start:
{
if (lean_obj_tag(v_as_x27_1225_) == 0)
{
lean_object* v___x_1228_; 
v___x_1228_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1228_, 0, v_b_1226_);
return v___x_1228_;
}
else
{
lean_object* v_head_1229_; lean_object* v_decoded_1230_; lean_object* v_adsb_1231_; 
v_head_1229_ = lean_ctor_get(v_as_x27_1225_, 0);
v_decoded_1230_ = lean_ctor_get(v_head_1229_, 1);
v_adsb_1231_ = lean_ctor_get(v_decoded_1230_, 5);
if (lean_obj_tag(v_adsb_1231_) == 1)
{
lean_object* v_val_1232_; lean_object* v_tail_1233_; lean_object* v_kind_1234_; lean_object* v___x_1235_; 
v_val_1232_ = lean_ctor_get(v_adsb_1231_, 0);
v_tail_1233_ = lean_ctor_get(v_as_x27_1225_, 1);
v_kind_1234_ = lean_ctor_get(v_val_1232_, 0);
lean_inc(v_kind_1234_);
v___x_1235_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_bump(v_b_1226_, v_kind_1234_);
v_as_x27_1225_ = v_tail_1233_;
v_b_1226_ = v___x_1235_;
goto _start;
}
else
{
lean_object* v_tail_1237_; 
v_tail_1237_ = lean_ctor_get(v_as_x27_1225_, 1);
v_as_x27_1225_ = v_tail_1237_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg___boxed(lean_object* v_as_x27_1239_, lean_object* v_b_1240_, lean_object* v___y_1241_){
_start:
{
lean_object* v_res_1242_; 
v_res_1242_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(v_as_x27_1239_, v_b_1240_);
lean_dec(v_as_x27_1239_);
return v_res_1242_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5(size_t v_sz_1243_, size_t v_i_1244_, lean_object* v_bs_1245_){
_start:
{
uint8_t v___x_1246_; 
v___x_1246_ = lean_usize_dec_lt(v_i_1244_, v_sz_1243_);
if (v___x_1246_ == 0)
{
return v_bs_1245_;
}
else
{
lean_object* v_v_1247_; lean_object* v___x_1248_; lean_object* v_bs_x27_1249_; size_t v___x_1250_; size_t v___x_1251_; lean_object* v___x_1252_; 
v_v_1247_ = lean_array_uget(v_bs_1245_, v_i_1244_);
v___x_1248_ = lean_unsigned_to_nat(0u);
v_bs_x27_1249_ = lean_array_uset(v_bs_1245_, v_i_1244_, v___x_1248_);
v___x_1250_ = ((size_t)1ULL);
v___x_1251_ = lean_usize_add(v_i_1244_, v___x_1250_);
v___x_1252_ = lean_array_uset(v_bs_x27_1249_, v_i_1244_, v_v_1247_);
v_i_1244_ = v___x_1251_;
v_bs_1245_ = v___x_1252_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5___boxed(lean_object* v_sz_1254_, lean_object* v_i_1255_, lean_object* v_bs_1256_){
_start:
{
size_t v_sz_boxed_1257_; size_t v_i_boxed_1258_; lean_object* v_res_1259_; 
v_sz_boxed_1257_ = lean_unbox_usize(v_sz_1254_);
lean_dec(v_sz_1254_);
v_i_boxed_1258_ = lean_unbox_usize(v_i_1255_);
lean_dec(v_i_1255_);
v_res_1259_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5(v_sz_boxed_1257_, v_i_boxed_1258_, v_bs_1256_);
return v_res_1259_;
}
}
LEAN_EXPORT lean_object* l_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4(lean_object* v_a_1260_){
_start:
{
size_t v_sz_1261_; size_t v___x_1262_; lean_object* v___x_1263_; lean_object* v___x_1264_; 
v_sz_1261_ = lean_array_size(v_a_1260_);
v___x_1262_ = ((size_t)0ULL);
v___x_1263_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4_spec__5(v_sz_1261_, v___x_1262_, v_a_1260_);
v___x_1264_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_1264_, 0, v___x_1263_);
return v___x_1264_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(lean_object* v_a_1265_){
_start:
{
lean_object* v___x_1266_; lean_object* v___x_1267_; 
v___x_1266_ = lean_array_mk(v_a_1265_);
v___x_1267_ = l_Lean_Array_toJson___at___00Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4_spec__4(v___x_1266_);
return v___x_1267_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(lean_object* v_output_1319_, lean_object* v_inputs_1320_, lean_object* v_as_x27_1321_, lean_object* v_b_1322_){
_start:
{
if (lean_obj_tag(v_as_x27_1321_) == 0)
{
lean_object* v___x_1324_; 
v___x_1324_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1324_, 0, v_b_1322_);
return v___x_1324_;
}
else
{
lean_object* v_head_1325_; lean_object* v_tail_1326_; lean_object* v___f_1327_; lean_object* v_rows_1328_; lean_object* v___x_1329_; lean_object* v___x_1330_; lean_object* v___x_1331_; lean_object* v___x_1332_; lean_object* v___x_1333_; 
v_head_1325_ = lean_ctor_get(v_as_x27_1321_, 0);
v_tail_1326_ = lean_ctor_get(v_as_x27_1321_, 1);
v___f_1327_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__0));
v_rows_1328_ = lean_box(0);
v___x_1329_ = lean_unsigned_to_nat(0u);
v___x_1330_ = lean_array_get_size(v_output_1319_);
v___x_1331_ = lean_unsigned_to_nat(1u);
v___x_1332_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1332_, 0, v___x_1329_);
lean_ctor_set(v___x_1332_, 1, v___x_1330_);
lean_ctor_set(v___x_1332_, 2, v___x_1331_);
v___x_1333_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(v_inputs_1320_, v_head_1325_, v_output_1319_, v___x_1332_, v_rows_1328_, v___x_1329_);
lean_dec_ref_known(v___x_1332_, 3);
if (lean_obj_tag(v___x_1333_) == 0)
{
lean_object* v_a_1334_; lean_object* v___x_1335_; lean_object* v_a_1336_; lean_object* v___x_1338_; uint8_t v_isShared_1339_; uint8_t v_isSharedCheck_1430_; 
v_a_1334_ = lean_ctor_get(v___x_1333_, 0);
lean_inc(v_a_1334_);
lean_dec_ref_known(v___x_1333_, 1);
v___x_1335_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(v_a_1334_, v_rows_1328_);
v_a_1336_ = lean_ctor_get(v___x_1335_, 0);
v_isSharedCheck_1430_ = !lean_is_exclusive(v___x_1335_);
if (v_isSharedCheck_1430_ == 0)
{
v___x_1338_ = v___x_1335_;
v_isShared_1339_ = v_isSharedCheck_1430_;
goto v_resetjp_1337_;
}
else
{
lean_inc(v_a_1336_);
lean_dec(v___x_1335_);
v___x_1338_ = lean_box(0);
v_isShared_1339_ = v_isSharedCheck_1430_;
goto v_resetjp_1337_;
}
v_resetjp_1337_:
{
lean_object* v___y_1341_; lean_object* v___y_1342_; lean_object* v___y_1343_; lean_object* v___y_1344_; lean_object* v___y_1345_; lean_object* v___y_1346_; lean_object* v___y_1347_; lean_object* v___y_1348_; lean_object* v___y_1381_; lean_object* v___y_1382_; lean_object* v___y_1383_; lean_object* v___y_1384_; lean_object* v___y_1385_; lean_object* v___y_1386_; lean_object* v___y_1387_; lean_object* v___y_1388_; lean_object* v___y_1392_; lean_object* v___y_1393_; lean_object* v___y_1394_; lean_object* v___y_1395_; lean_object* v_registers_1417_; lean_object* v___x_1426_; uint8_t v___x_1427_; 
v___x_1426_ = lean_unsigned_to_nat(20u);
v___x_1427_ = lean_nat_dec_eq(v_head_1325_, v___x_1426_);
if (v___x_1427_ == 0)
{
lean_object* v___x_1428_; uint8_t v___x_1429_; 
v___x_1428_ = lean_unsigned_to_nat(21u);
v___x_1429_ = lean_nat_dec_eq(v_head_1325_, v___x_1428_);
if (v___x_1429_ == 0)
{
v_registers_1417_ = v_rows_1328_;
goto v___jp_1416_;
}
else
{
goto v___jp_1422_;
}
}
else
{
goto v___jp_1422_;
}
v___jp_1340_:
{
lean_object* v___x_1349_; lean_object* v___x_1351_; 
v___x_1349_ = l_Lean_JsonNumber_fromNat(v___y_1348_);
if (v_isShared_1339_ == 0)
{
lean_ctor_set_tag(v___x_1338_, 2);
lean_ctor_set(v___x_1338_, 0, v___x_1349_);
v___x_1351_ = v___x_1338_;
goto v_reusejp_1350_;
}
else
{
lean_object* v_reuseFailAlloc_1379_; 
v_reuseFailAlloc_1379_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1379_, 0, v___x_1349_);
v___x_1351_ = v_reuseFailAlloc_1379_;
goto v_reusejp_1350_;
}
v_reusejp_1350_:
{
lean_object* v___x_1352_; lean_object* v___x_1353_; lean_object* v___x_1354_; lean_object* v___x_1355_; lean_object* v___x_1356_; lean_object* v___x_1357_; lean_object* v___x_1358_; lean_object* v___x_1359_; lean_object* v___x_1360_; lean_object* v___x_1361_; lean_object* v___x_1362_; lean_object* v___x_1363_; lean_object* v___x_1364_; lean_object* v___x_1365_; lean_object* v___x_1366_; lean_object* v___x_1367_; lean_object* v___x_1368_; lean_object* v___x_1369_; lean_object* v___x_1370_; lean_object* v___x_1371_; lean_object* v___x_1372_; lean_object* v___x_1373_; lean_object* v___x_1374_; lean_object* v___x_1375_; lean_object* v___x_1376_; lean_object* v___x_1377_; 
lean_inc_ref(v___y_1343_);
v___x_1352_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1352_, 0, v___y_1343_);
lean_ctor_set(v___x_1352_, 1, v___x_1351_);
v___x_1353_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__1));
lean_inc(v_a_1336_);
v___x_1354_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__2(v_a_1336_, v___y_1341_);
v___x_1355_ = l_List_sum___at___00Lean_PersistentHashMap_subarrayMeasure_spec__2(v___x_1354_);
lean_dec(v___x_1354_);
v___x_1356_ = l_Lean_JsonNumber_fromNat(v___x_1355_);
v___x_1357_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1357_, 0, v___x_1356_);
v___x_1358_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1358_, 0, v___x_1353_);
lean_ctor_set(v___x_1358_, 1, v___x_1357_);
v___x_1359_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__2));
v___x_1360_ = l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(v_a_1336_, v___f_1327_);
v___x_1361_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3(v___x_1360_, v_rows_1328_);
v___x_1362_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___x_1361_);
v___x_1363_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1363_, 0, v___x_1359_);
lean_ctor_set(v___x_1363_, 1, v___x_1362_);
v___x_1364_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__4));
v___x_1365_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___y_1345_);
v___x_1366_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1366_, 0, v___x_1364_);
lean_ctor_set(v___x_1366_, 1, v___x_1365_);
v___x_1367_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1367_, 0, v___x_1366_);
lean_ctor_set(v___x_1367_, 1, v_rows_1328_);
v___x_1368_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1368_, 0, v___x_1363_);
lean_ctor_set(v___x_1368_, 1, v___x_1367_);
v___x_1369_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1369_, 0, v___x_1358_);
lean_ctor_set(v___x_1369_, 1, v___x_1368_);
v___x_1370_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1370_, 0, v___x_1352_);
lean_ctor_set(v___x_1370_, 1, v___x_1369_);
v___x_1371_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1371_, 0, v___y_1344_);
lean_ctor_set(v___x_1371_, 1, v___x_1370_);
v___x_1372_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1372_, 0, v___y_1347_);
lean_ctor_set(v___x_1372_, 1, v___x_1371_);
v___x_1373_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1373_, 0, v___y_1346_);
lean_ctor_set(v___x_1373_, 1, v___x_1372_);
v___x_1374_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1374_, 0, v___y_1342_);
lean_ctor_set(v___x_1374_, 1, v___x_1373_);
v___x_1375_ = l_Lean_Json_mkObj(v___x_1374_);
lean_dec_ref_known(v___x_1374_, 2);
v___x_1376_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1376_, 0, v___x_1375_);
lean_ctor_set(v___x_1376_, 1, v_rows_1328_);
v___x_1377_ = l_List_appendTR___redArg(v_b_1322_, v___x_1376_);
v_as_x27_1321_ = v_tail_1326_;
v_b_1322_ = v___x_1377_;
goto _start;
}
}
v___jp_1380_:
{
lean_object* v___x_1389_; lean_object* v___x_1390_; 
v___x_1389_ = lean_unsigned_to_nat(2u);
v___x_1390_ = lean_nat_mul(v___y_1383_, v___x_1389_);
lean_dec(v___y_1383_);
v___y_1341_ = v___y_1381_;
v___y_1342_ = v___y_1382_;
v___y_1343_ = v___y_1384_;
v___y_1344_ = v___y_1385_;
v___y_1345_ = v___y_1386_;
v___y_1346_ = v___y_1388_;
v___y_1347_ = v___y_1387_;
v___y_1348_ = v___x_1390_;
goto v___jp_1340_;
}
v___jp_1391_:
{
lean_object* v___x_1396_; lean_object* v___x_1397_; lean_object* v___x_1398_; lean_object* v___x_1399_; lean_object* v___x_1400_; lean_object* v___x_1401_; lean_object* v___x_1402_; lean_object* v___x_1403_; lean_object* v___x_1404_; lean_object* v___x_1405_; lean_object* v___x_1406_; lean_object* v___x_1407_; lean_object* v___x_1408_; lean_object* v___x_1409_; lean_object* v___x_1410_; lean_object* v___x_1411_; lean_object* v___x_1412_; uint8_t v___x_1413_; 
v___x_1396_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6));
lean_inc(v_head_1325_);
v___x_1397_ = l_Lean_JsonNumber_fromNat(v_head_1325_);
v___x_1398_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1398_, 0, v___x_1397_);
v___x_1399_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1399_, 0, v___x_1396_);
lean_ctor_set(v___x_1399_, 1, v___x_1398_);
v___x_1400_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0));
v___x_1401_ = l_List_lengthTR___redArg(v_a_1334_);
lean_dec(v_a_1334_);
lean_inc(v___x_1401_);
v___x_1402_ = l_Lean_JsonNumber_fromNat(v___x_1401_);
v___x_1403_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1403_, 0, v___x_1402_);
lean_inc_ref(v___x_1403_);
v___x_1404_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1404_, 0, v___x_1400_);
lean_ctor_set(v___x_1404_, 1, v___x_1403_);
v___x_1405_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__3));
v___x_1406_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1406_, 0, v___x_1405_);
lean_ctor_set(v___x_1406_, 1, v___x_1403_);
v___x_1407_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__4));
v___x_1408_ = lean_nat_mul(v___x_1401_, v___y_1395_);
v___x_1409_ = l_Lean_JsonNumber_fromNat(v___x_1408_);
v___x_1410_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1410_, 0, v___x_1409_);
v___x_1411_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1411_, 0, v___x_1407_);
lean_ctor_set(v___x_1411_, 1, v___x_1410_);
v___x_1412_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__5));
v___x_1413_ = lean_nat_dec_eq(v_head_1325_, v___y_1394_);
if (v___x_1413_ == 0)
{
lean_object* v___x_1414_; uint8_t v___x_1415_; 
v___x_1414_ = lean_unsigned_to_nat(18u);
v___x_1415_ = lean_nat_dec_eq(v_head_1325_, v___x_1414_);
if (v___x_1415_ == 0)
{
lean_dec(v___x_1401_);
v___y_1341_ = v___y_1392_;
v___y_1342_ = v___x_1399_;
v___y_1343_ = v___x_1412_;
v___y_1344_ = v___x_1411_;
v___y_1345_ = v___y_1393_;
v___y_1346_ = v___x_1404_;
v___y_1347_ = v___x_1406_;
v___y_1348_ = v___x_1329_;
goto v___jp_1340_;
}
else
{
v___y_1381_ = v___y_1392_;
v___y_1382_ = v___x_1399_;
v___y_1383_ = v___x_1401_;
v___y_1384_ = v___x_1412_;
v___y_1385_ = v___x_1411_;
v___y_1386_ = v___y_1393_;
v___y_1387_ = v___x_1406_;
v___y_1388_ = v___x_1404_;
goto v___jp_1380_;
}
}
else
{
v___y_1381_ = v___y_1392_;
v___y_1382_ = v___x_1399_;
v___y_1383_ = v___x_1401_;
v___y_1384_ = v___x_1412_;
v___y_1385_ = v___x_1411_;
v___y_1386_ = v___y_1393_;
v___y_1387_ = v___x_1406_;
v___y_1388_ = v___x_1404_;
goto v___jp_1380_;
}
}
v___jp_1416_:
{
lean_object* v___x_1418_; lean_object* v___x_1419_; uint8_t v___x_1420_; 
v___x_1418_ = lean_unsigned_to_nat(17u);
v___x_1419_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__20));
v___x_1420_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_head_1325_, v___x_1419_);
if (v___x_1420_ == 0)
{
v___y_1392_ = v_rows_1328_;
v___y_1393_ = v_registers_1417_;
v___y_1394_ = v___x_1418_;
v___y_1395_ = v___x_1331_;
goto v___jp_1391_;
}
else
{
lean_object* v___x_1421_; 
v___x_1421_ = lean_unsigned_to_nat(2u);
v___y_1392_ = v_rows_1328_;
v___y_1393_ = v_registers_1417_;
v___y_1394_ = v___x_1418_;
v___y_1395_ = v___x_1421_;
goto v___jp_1391_;
}
}
v___jp_1422_:
{
lean_object* v___x_1423_; lean_object* v___x_1424_; 
v___x_1423_ = lp_lean1090_Lean1090_Impl_commBRegisters;
lean_inc(v_head_1325_);
v___x_1424_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(v_head_1325_, v_a_1334_, v___x_1423_, v_rows_1328_);
if (lean_obj_tag(v___x_1424_) == 0)
{
lean_object* v_a_1425_; 
v_a_1425_ = lean_ctor_get(v___x_1424_, 0);
lean_inc(v_a_1425_);
lean_dec_ref_known(v___x_1424_, 1);
v_registers_1417_ = v_a_1425_;
goto v___jp_1416_;
}
else
{
lean_del_object(v___x_1338_);
lean_dec(v_a_1336_);
lean_dec(v_a_1334_);
lean_dec(v_b_1322_);
return v___x_1424_;
}
}
}
}
else
{
lean_object* v_a_1431_; lean_object* v___x_1433_; uint8_t v_isShared_1434_; uint8_t v_isSharedCheck_1438_; 
lean_dec(v_b_1322_);
v_a_1431_ = lean_ctor_get(v___x_1333_, 0);
v_isSharedCheck_1438_ = !lean_is_exclusive(v___x_1333_);
if (v_isSharedCheck_1438_ == 0)
{
v___x_1433_ = v___x_1333_;
v_isShared_1434_ = v_isSharedCheck_1438_;
goto v_resetjp_1432_;
}
else
{
lean_inc(v_a_1431_);
lean_dec(v___x_1333_);
v___x_1433_ = lean_box(0);
v_isShared_1434_ = v_isSharedCheck_1438_;
goto v_resetjp_1432_;
}
v_resetjp_1432_:
{
lean_object* v___x_1436_; 
if (v_isShared_1434_ == 0)
{
v___x_1436_ = v___x_1433_;
goto v_reusejp_1435_;
}
else
{
lean_object* v_reuseFailAlloc_1437_; 
v_reuseFailAlloc_1437_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1437_, 0, v_a_1431_);
v___x_1436_ = v_reuseFailAlloc_1437_;
goto v_reusejp_1435_;
}
v_reusejp_1435_:
{
return v___x_1436_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___boxed(lean_object* v_output_1439_, lean_object* v_inputs_1440_, lean_object* v_as_x27_1441_, lean_object* v_b_1442_, lean_object* v___y_1443_){
_start:
{
lean_object* v_res_1444_; 
v_res_1444_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(v_output_1439_, v_inputs_1440_, v_as_x27_1441_, v_b_1442_);
lean_dec(v_as_x27_1441_);
lean_dec_ref(v_inputs_1440_);
lean_dec_ref(v_output_1439_);
return v_res_1444_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(lean_object* v_inputs_1445_, lean_object* v_output_1446_, lean_object* v_as_1447_, lean_object* v_as_x27_1448_, lean_object* v_b_1449_){
_start:
{
if (lean_obj_tag(v_as_x27_1448_) == 0)
{
lean_object* v___x_1451_; 
v___x_1451_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1451_, 0, v_b_1449_);
return v___x_1451_;
}
else
{
lean_object* v_head_1452_; lean_object* v_tail_1453_; lean_object* v___f_1454_; lean_object* v_rows_1455_; lean_object* v___x_1456_; lean_object* v___x_1457_; lean_object* v___x_1458_; lean_object* v___x_1459_; lean_object* v___x_1460_; 
v_head_1452_ = lean_ctor_get(v_as_x27_1448_, 0);
v_tail_1453_ = lean_ctor_get(v_as_x27_1448_, 1);
v___f_1454_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__0));
v_rows_1455_ = lean_box(0);
v___x_1456_ = lean_unsigned_to_nat(0u);
v___x_1457_ = lean_array_get_size(v_output_1446_);
v___x_1458_ = lean_unsigned_to_nat(1u);
v___x_1459_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1459_, 0, v___x_1456_);
lean_ctor_set(v___x_1459_, 1, v___x_1457_);
lean_ctor_set(v___x_1459_, 2, v___x_1458_);
v___x_1460_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(v_inputs_1445_, v_head_1452_, v_output_1446_, v___x_1459_, v_rows_1455_, v___x_1456_);
lean_dec_ref_known(v___x_1459_, 3);
if (lean_obj_tag(v___x_1460_) == 0)
{
lean_object* v_a_1461_; lean_object* v___x_1462_; lean_object* v_a_1463_; lean_object* v___x_1465_; uint8_t v_isShared_1466_; uint8_t v_isSharedCheck_1557_; 
v_a_1461_ = lean_ctor_get(v___x_1460_, 0);
lean_inc(v_a_1461_);
lean_dec_ref_known(v___x_1460_, 1);
v___x_1462_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(v_a_1461_, v_rows_1455_);
v_a_1463_ = lean_ctor_get(v___x_1462_, 0);
v_isSharedCheck_1557_ = !lean_is_exclusive(v___x_1462_);
if (v_isSharedCheck_1557_ == 0)
{
v___x_1465_ = v___x_1462_;
v_isShared_1466_ = v_isSharedCheck_1557_;
goto v_resetjp_1464_;
}
else
{
lean_inc(v_a_1463_);
lean_dec(v___x_1462_);
v___x_1465_ = lean_box(0);
v_isShared_1466_ = v_isSharedCheck_1557_;
goto v_resetjp_1464_;
}
v_resetjp_1464_:
{
lean_object* v___y_1468_; lean_object* v___y_1469_; lean_object* v___y_1470_; lean_object* v___y_1471_; lean_object* v___y_1472_; lean_object* v___y_1473_; lean_object* v___y_1474_; lean_object* v___y_1475_; lean_object* v___y_1508_; lean_object* v___y_1509_; lean_object* v___y_1510_; lean_object* v___y_1511_; lean_object* v___y_1512_; lean_object* v___y_1513_; lean_object* v___y_1514_; lean_object* v___y_1515_; lean_object* v___y_1519_; lean_object* v___y_1520_; lean_object* v___y_1521_; lean_object* v___y_1522_; lean_object* v_registers_1544_; lean_object* v___x_1553_; uint8_t v___x_1554_; 
v___x_1553_ = lean_unsigned_to_nat(20u);
v___x_1554_ = lean_nat_dec_eq(v_head_1452_, v___x_1553_);
if (v___x_1554_ == 0)
{
lean_object* v___x_1555_; uint8_t v___x_1556_; 
v___x_1555_ = lean_unsigned_to_nat(21u);
v___x_1556_ = lean_nat_dec_eq(v_head_1452_, v___x_1555_);
if (v___x_1556_ == 0)
{
v_registers_1544_ = v_rows_1455_;
goto v___jp_1543_;
}
else
{
goto v___jp_1549_;
}
}
else
{
goto v___jp_1549_;
}
v___jp_1467_:
{
lean_object* v___x_1476_; lean_object* v___x_1478_; 
v___x_1476_ = l_Lean_JsonNumber_fromNat(v___y_1475_);
if (v_isShared_1466_ == 0)
{
lean_ctor_set_tag(v___x_1465_, 2);
lean_ctor_set(v___x_1465_, 0, v___x_1476_);
v___x_1478_ = v___x_1465_;
goto v_reusejp_1477_;
}
else
{
lean_object* v_reuseFailAlloc_1506_; 
v_reuseFailAlloc_1506_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1506_, 0, v___x_1476_);
v___x_1478_ = v_reuseFailAlloc_1506_;
goto v_reusejp_1477_;
}
v_reusejp_1477_:
{
lean_object* v___x_1479_; lean_object* v___x_1480_; lean_object* v___x_1481_; lean_object* v___x_1482_; lean_object* v___x_1483_; lean_object* v___x_1484_; lean_object* v___x_1485_; lean_object* v___x_1486_; lean_object* v___x_1487_; lean_object* v___x_1488_; lean_object* v___x_1489_; lean_object* v___x_1490_; lean_object* v___x_1491_; lean_object* v___x_1492_; lean_object* v___x_1493_; lean_object* v___x_1494_; lean_object* v___x_1495_; lean_object* v___x_1496_; lean_object* v___x_1497_; lean_object* v___x_1498_; lean_object* v___x_1499_; lean_object* v___x_1500_; lean_object* v___x_1501_; lean_object* v___x_1502_; lean_object* v___x_1503_; lean_object* v___x_1504_; lean_object* v___x_1505_; 
lean_inc_ref(v___y_1474_);
v___x_1479_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1479_, 0, v___y_1474_);
lean_ctor_set(v___x_1479_, 1, v___x_1478_);
v___x_1480_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__1));
lean_inc(v_a_1463_);
v___x_1481_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__2(v_a_1463_, v___y_1469_);
v___x_1482_ = l_List_sum___at___00Lean_PersistentHashMap_subarrayMeasure_spec__2(v___x_1481_);
lean_dec(v___x_1481_);
v___x_1483_ = l_Lean_JsonNumber_fromNat(v___x_1482_);
v___x_1484_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1484_, 0, v___x_1483_);
v___x_1485_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1485_, 0, v___x_1480_);
lean_ctor_set(v___x_1485_, 1, v___x_1484_);
v___x_1486_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__2));
v___x_1487_ = l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(v_a_1463_, v___f_1454_);
v___x_1488_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__3(v___x_1487_, v_rows_1455_);
v___x_1489_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___x_1488_);
v___x_1490_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1490_, 0, v___x_1486_);
lean_ctor_set(v___x_1490_, 1, v___x_1489_);
v___x_1491_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__4));
v___x_1492_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___y_1470_);
v___x_1493_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1493_, 0, v___x_1491_);
lean_ctor_set(v___x_1493_, 1, v___x_1492_);
v___x_1494_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1494_, 0, v___x_1493_);
lean_ctor_set(v___x_1494_, 1, v_rows_1455_);
v___x_1495_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1495_, 0, v___x_1490_);
lean_ctor_set(v___x_1495_, 1, v___x_1494_);
v___x_1496_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1496_, 0, v___x_1485_);
lean_ctor_set(v___x_1496_, 1, v___x_1495_);
v___x_1497_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1497_, 0, v___x_1479_);
lean_ctor_set(v___x_1497_, 1, v___x_1496_);
v___x_1498_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1498_, 0, v___y_1473_);
lean_ctor_set(v___x_1498_, 1, v___x_1497_);
v___x_1499_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1499_, 0, v___y_1472_);
lean_ctor_set(v___x_1499_, 1, v___x_1498_);
v___x_1500_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1500_, 0, v___y_1468_);
lean_ctor_set(v___x_1500_, 1, v___x_1499_);
v___x_1501_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1501_, 0, v___y_1471_);
lean_ctor_set(v___x_1501_, 1, v___x_1500_);
v___x_1502_ = l_Lean_Json_mkObj(v___x_1501_);
lean_dec_ref_known(v___x_1501_, 2);
v___x_1503_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1503_, 0, v___x_1502_);
lean_ctor_set(v___x_1503_, 1, v_rows_1455_);
v___x_1504_ = l_List_appendTR___redArg(v_b_1449_, v___x_1503_);
v___x_1505_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(v_output_1446_, v_inputs_1445_, v_tail_1453_, v___x_1504_);
return v___x_1505_;
}
}
v___jp_1507_:
{
lean_object* v___x_1516_; lean_object* v___x_1517_; 
v___x_1516_ = lean_unsigned_to_nat(2u);
v___x_1517_ = lean_nat_mul(v___y_1514_, v___x_1516_);
lean_dec(v___y_1514_);
v___y_1468_ = v___y_1508_;
v___y_1469_ = v___y_1509_;
v___y_1470_ = v___y_1510_;
v___y_1471_ = v___y_1511_;
v___y_1472_ = v___y_1512_;
v___y_1473_ = v___y_1513_;
v___y_1474_ = v___y_1515_;
v___y_1475_ = v___x_1517_;
goto v___jp_1467_;
}
v___jp_1518_:
{
lean_object* v___x_1523_; lean_object* v___x_1524_; lean_object* v___x_1525_; lean_object* v___x_1526_; lean_object* v___x_1527_; lean_object* v___x_1528_; lean_object* v___x_1529_; lean_object* v___x_1530_; lean_object* v___x_1531_; lean_object* v___x_1532_; lean_object* v___x_1533_; lean_object* v___x_1534_; lean_object* v___x_1535_; lean_object* v___x_1536_; lean_object* v___x_1537_; lean_object* v___x_1538_; lean_object* v___x_1539_; uint8_t v___x_1540_; 
v___x_1523_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6));
lean_inc(v_head_1452_);
v___x_1524_ = l_Lean_JsonNumber_fromNat(v_head_1452_);
v___x_1525_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1525_, 0, v___x_1524_);
v___x_1526_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1526_, 0, v___x_1523_);
lean_ctor_set(v___x_1526_, 1, v___x_1525_);
v___x_1527_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson___closed__0));
v___x_1528_ = l_List_lengthTR___redArg(v_a_1461_);
lean_dec(v_a_1461_);
lean_inc(v___x_1528_);
v___x_1529_ = l_Lean_JsonNumber_fromNat(v___x_1528_);
v___x_1530_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1530_, 0, v___x_1529_);
lean_inc_ref(v___x_1530_);
v___x_1531_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1531_, 0, v___x_1527_);
lean_ctor_set(v___x_1531_, 1, v___x_1530_);
v___x_1532_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__3));
v___x_1533_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1533_, 0, v___x_1532_);
lean_ctor_set(v___x_1533_, 1, v___x_1530_);
v___x_1534_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__4));
v___x_1535_ = lean_nat_mul(v___x_1528_, v___y_1522_);
v___x_1536_ = l_Lean_JsonNumber_fromNat(v___x_1535_);
v___x_1537_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1537_, 0, v___x_1536_);
v___x_1538_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1538_, 0, v___x_1534_);
lean_ctor_set(v___x_1538_, 1, v___x_1537_);
v___x_1539_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__5));
v___x_1540_ = lean_nat_dec_eq(v_head_1452_, v___y_1521_);
if (v___x_1540_ == 0)
{
lean_object* v___x_1541_; uint8_t v___x_1542_; 
v___x_1541_ = lean_unsigned_to_nat(18u);
v___x_1542_ = lean_nat_dec_eq(v_head_1452_, v___x_1541_);
if (v___x_1542_ == 0)
{
lean_dec(v___x_1528_);
v___y_1468_ = v___x_1531_;
v___y_1469_ = v___y_1519_;
v___y_1470_ = v___y_1520_;
v___y_1471_ = v___x_1526_;
v___y_1472_ = v___x_1533_;
v___y_1473_ = v___x_1538_;
v___y_1474_ = v___x_1539_;
v___y_1475_ = v___x_1456_;
goto v___jp_1467_;
}
else
{
v___y_1508_ = v___x_1531_;
v___y_1509_ = v___y_1519_;
v___y_1510_ = v___y_1520_;
v___y_1511_ = v___x_1526_;
v___y_1512_ = v___x_1533_;
v___y_1513_ = v___x_1538_;
v___y_1514_ = v___x_1528_;
v___y_1515_ = v___x_1539_;
goto v___jp_1507_;
}
}
else
{
v___y_1508_ = v___x_1531_;
v___y_1509_ = v___y_1519_;
v___y_1510_ = v___y_1520_;
v___y_1511_ = v___x_1526_;
v___y_1512_ = v___x_1533_;
v___y_1513_ = v___x_1538_;
v___y_1514_ = v___x_1528_;
v___y_1515_ = v___x_1539_;
goto v___jp_1507_;
}
}
v___jp_1543_:
{
lean_object* v___x_1545_; lean_object* v___x_1546_; uint8_t v___x_1547_; 
v___x_1545_ = lean_unsigned_to_nat(17u);
v___x_1546_ = ((lean_object*)(l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg___closed__20));
v___x_1547_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_head_1452_, v___x_1546_);
if (v___x_1547_ == 0)
{
v___y_1519_ = v_rows_1455_;
v___y_1520_ = v_registers_1544_;
v___y_1521_ = v___x_1545_;
v___y_1522_ = v___x_1458_;
goto v___jp_1518_;
}
else
{
lean_object* v___x_1548_; 
v___x_1548_ = lean_unsigned_to_nat(2u);
v___y_1519_ = v_rows_1455_;
v___y_1520_ = v_registers_1544_;
v___y_1521_ = v___x_1545_;
v___y_1522_ = v___x_1548_;
goto v___jp_1518_;
}
}
v___jp_1549_:
{
lean_object* v___x_1550_; lean_object* v___x_1551_; 
v___x_1550_ = lp_lean1090_Lean1090_Impl_commBRegisters;
lean_inc(v_head_1452_);
v___x_1551_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(v_head_1452_, v_a_1461_, v___x_1550_, v_rows_1455_);
if (lean_obj_tag(v___x_1551_) == 0)
{
lean_object* v_a_1552_; 
v_a_1552_ = lean_ctor_get(v___x_1551_, 0);
lean_inc(v_a_1552_);
lean_dec_ref_known(v___x_1551_, 1);
v_registers_1544_ = v_a_1552_;
goto v___jp_1543_;
}
else
{
lean_del_object(v___x_1465_);
lean_dec(v_a_1463_);
lean_dec(v_a_1461_);
lean_dec(v_b_1449_);
return v___x_1551_;
}
}
}
}
else
{
lean_object* v_a_1558_; lean_object* v___x_1560_; uint8_t v_isShared_1561_; uint8_t v_isSharedCheck_1565_; 
lean_dec(v_b_1449_);
v_a_1558_ = lean_ctor_get(v___x_1460_, 0);
v_isSharedCheck_1565_ = !lean_is_exclusive(v___x_1460_);
if (v_isSharedCheck_1565_ == 0)
{
v___x_1560_ = v___x_1460_;
v_isShared_1561_ = v_isSharedCheck_1565_;
goto v_resetjp_1559_;
}
else
{
lean_inc(v_a_1558_);
lean_dec(v___x_1460_);
v___x_1560_ = lean_box(0);
v_isShared_1561_ = v_isSharedCheck_1565_;
goto v_resetjp_1559_;
}
v_resetjp_1559_:
{
lean_object* v___x_1563_; 
if (v_isShared_1561_ == 0)
{
v___x_1563_ = v___x_1560_;
goto v_reusejp_1562_;
}
else
{
lean_object* v_reuseFailAlloc_1564_; 
v_reuseFailAlloc_1564_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1564_, 0, v_a_1558_);
v___x_1563_ = v_reuseFailAlloc_1564_;
goto v_reusejp_1562_;
}
v_reusejp_1562_:
{
return v___x_1563_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg___boxed(lean_object* v_inputs_1566_, lean_object* v_output_1567_, lean_object* v_as_1568_, lean_object* v_as_x27_1569_, lean_object* v_b_1570_, lean_object* v___y_1571_){
_start:
{
lean_object* v_res_1572_; 
v_res_1572_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(v_inputs_1566_, v_output_1567_, v_as_1568_, v_as_x27_1569_, v_b_1570_);
lean_dec(v_as_x27_1569_);
lean_dec(v_as_1568_);
lean_dec_ref(v_output_1567_);
lean_dec_ref(v_inputs_1566_);
return v_res_1572_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0(void){
_start:
{
lean_object* v___x_1573_; lean_object* v___x_1574_; 
v___x_1573_ = lean_unsigned_to_nat(32u);
v___x_1574_ = l_List_range(v___x_1573_);
return v___x_1574_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census(lean_object* v_inputs_1588_, lean_object* v_output_1589_){
_start:
{
lean_object* v_rows_1591_; lean_object* v___x_1592_; lean_object* v___x_1593_; 
v_rows_1591_ = lean_box(0);
v___x_1592_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__0);
v___x_1593_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(v_inputs_1588_, v_output_1589_, v___x_1592_, v___x_1592_, v_rows_1591_);
if (lean_obj_tag(v___x_1593_) == 0)
{
lean_object* v_a_1594_; lean_object* v___x_1596_; uint8_t v_isShared_1597_; uint8_t v_isSharedCheck_1610_; 
v_a_1594_ = lean_ctor_get(v___x_1593_, 0);
v_isSharedCheck_1610_ = !lean_is_exclusive(v___x_1593_);
if (v_isSharedCheck_1610_ == 0)
{
v___x_1596_ = v___x_1593_;
v_isShared_1597_ = v_isSharedCheck_1610_;
goto v_resetjp_1595_;
}
else
{
lean_inc(v_a_1594_);
lean_dec(v___x_1593_);
v___x_1596_ = lean_box(0);
v_isShared_1597_ = v_isSharedCheck_1610_;
goto v_resetjp_1595_;
}
v_resetjp_1595_:
{
lean_object* v___x_1598_; lean_object* v___x_1599_; lean_object* v___x_1600_; lean_object* v___x_1601_; lean_object* v___x_1602_; lean_object* v___x_1603_; lean_object* v___x_1604_; lean_object* v___x_1605_; lean_object* v___x_1606_; lean_object* v___x_1608_; 
v___x_1598_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__3));
v___x_1599_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__6));
v___x_1600_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__7));
v___x_1601_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v_a_1594_);
v___x_1602_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1602_, 0, v___x_1600_);
lean_ctor_set(v___x_1602_, 1, v___x_1601_);
v___x_1603_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1603_, 0, v___x_1602_);
lean_ctor_set(v___x_1603_, 1, v_rows_1591_);
v___x_1604_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1604_, 0, v___x_1599_);
lean_ctor_set(v___x_1604_, 1, v___x_1603_);
v___x_1605_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1605_, 0, v___x_1598_);
lean_ctor_set(v___x_1605_, 1, v___x_1604_);
v___x_1606_ = l_Lean_Json_mkObj(v___x_1605_);
lean_dec_ref_known(v___x_1605_, 2);
if (v_isShared_1597_ == 0)
{
lean_ctor_set(v___x_1596_, 0, v___x_1606_);
v___x_1608_ = v___x_1596_;
goto v_reusejp_1607_;
}
else
{
lean_object* v_reuseFailAlloc_1609_; 
v_reuseFailAlloc_1609_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1609_, 0, v___x_1606_);
v___x_1608_ = v_reuseFailAlloc_1609_;
goto v_reusejp_1607_;
}
v_reusejp_1607_:
{
return v___x_1608_;
}
}
}
else
{
lean_object* v_a_1611_; lean_object* v___x_1613_; uint8_t v_isShared_1614_; uint8_t v_isSharedCheck_1618_; 
v_a_1611_ = lean_ctor_get(v___x_1593_, 0);
v_isSharedCheck_1618_ = !lean_is_exclusive(v___x_1593_);
if (v_isSharedCheck_1618_ == 0)
{
v___x_1613_ = v___x_1593_;
v_isShared_1614_ = v_isSharedCheck_1618_;
goto v_resetjp_1612_;
}
else
{
lean_inc(v_a_1611_);
lean_dec(v___x_1593_);
v___x_1613_ = lean_box(0);
v_isShared_1614_ = v_isSharedCheck_1618_;
goto v_resetjp_1612_;
}
v_resetjp_1612_:
{
lean_object* v___x_1616_; 
if (v_isShared_1614_ == 0)
{
v___x_1616_ = v___x_1613_;
goto v_reusejp_1615_;
}
else
{
lean_object* v_reuseFailAlloc_1617_; 
v_reuseFailAlloc_1617_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1617_, 0, v_a_1611_);
v___x_1616_ = v_reuseFailAlloc_1617_;
goto v_reusejp_1615_;
}
v_reusejp_1615_:
{
return v___x_1616_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___boxed(lean_object* v_inputs_1619_, lean_object* v_output_1620_, lean_object* v_a_1621_){
_start:
{
lean_object* v_res_1622_; 
v_res_1622_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census(v_inputs_1619_, v_output_1620_);
lean_dec_ref(v_output_1620_);
lean_dec_ref(v_inputs_1619_);
return v_res_1622_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0(lean_object* v_inputs_1623_, lean_object* v_a_1624_, lean_object* v_output_1625_, lean_object* v_range_1626_, lean_object* v_b_1627_, lean_object* v_i_1628_, lean_object* v_hs_1629_, lean_object* v_hl_1630_){
_start:
{
lean_object* v___x_1632_; 
v___x_1632_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___redArg(v_inputs_1623_, v_a_1624_, v_output_1625_, v_range_1626_, v_b_1627_, v_i_1628_);
return v___x_1632_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0___boxed(lean_object* v_inputs_1633_, lean_object* v_a_1634_, lean_object* v_output_1635_, lean_object* v_range_1636_, lean_object* v_b_1637_, lean_object* v_i_1638_, lean_object* v_hs_1639_, lean_object* v_hl_1640_, lean_object* v___y_1641_){
_start:
{
lean_object* v_res_1642_; 
v_res_1642_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__0(v_inputs_1633_, v_a_1634_, v_output_1635_, v_range_1636_, v_b_1637_, v_i_1638_, v_hs_1639_, v_hl_1640_);
lean_dec_ref(v_range_1636_);
lean_dec_ref(v_output_1635_);
lean_dec(v_a_1634_);
lean_dec_ref(v_inputs_1633_);
return v_res_1642_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1(lean_object* v_as_1643_, lean_object* v_as_x27_1644_, lean_object* v_b_1645_, lean_object* v_a_1646_){
_start:
{
lean_object* v___x_1648_; 
v___x_1648_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___redArg(v_as_x27_1644_, v_b_1645_);
return v___x_1648_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1___boxed(lean_object* v_as_1649_, lean_object* v_as_x27_1650_, lean_object* v_b_1651_, lean_object* v_a_1652_, lean_object* v___y_1653_){
_start:
{
lean_object* v_res_1654_; 
v_res_1654_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__1(v_as_1649_, v_as_x27_1650_, v_b_1651_, v_a_1652_);
lean_dec(v_as_x27_1650_);
lean_dec(v_as_1649_);
return v_res_1654_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5(lean_object* v_a_1655_, lean_object* v_a_1656_, lean_object* v_as_1657_, lean_object* v_as_x27_1658_, lean_object* v_b_1659_, lean_object* v_a_1660_){
_start:
{
lean_object* v___x_1662_; 
v___x_1662_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg(v_a_1655_, v_a_1656_, v_as_x27_1658_, v_b_1659_);
return v___x_1662_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___boxed(lean_object* v_a_1663_, lean_object* v_a_1664_, lean_object* v_as_1665_, lean_object* v_as_x27_1666_, lean_object* v_b_1667_, lean_object* v_a_1668_, lean_object* v___y_1669_){
_start:
{
lean_object* v_res_1670_; 
v_res_1670_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5(v_a_1663_, v_a_1664_, v_as_1665_, v_as_x27_1666_, v_b_1667_, v_a_1668_);
lean_dec(v_as_x27_1666_);
lean_dec(v_as_1665_);
lean_dec(v_a_1664_);
return v_res_1670_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6(lean_object* v_inputs_1671_, lean_object* v_output_1672_, lean_object* v_as_1673_, lean_object* v_as_x27_1674_, lean_object* v_b_1675_, lean_object* v_a_1676_){
_start:
{
lean_object* v___x_1678_; 
v___x_1678_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___redArg(v_inputs_1671_, v_output_1672_, v_as_1673_, v_as_x27_1674_, v_b_1675_);
return v___x_1678_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6___boxed(lean_object* v_inputs_1679_, lean_object* v_output_1680_, lean_object* v_as_1681_, lean_object* v_as_x27_1682_, lean_object* v_b_1683_, lean_object* v_a_1684_, lean_object* v___y_1685_){
_start:
{
lean_object* v_res_1686_; 
v_res_1686_ = l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6(v_inputs_1679_, v_output_1680_, v_as_1681_, v_as_x27_1682_, v_b_1683_, v_a_1684_);
lean_dec(v_as_x27_1682_);
lean_dec(v_as_1681_);
lean_dec_ref(v_output_1680_);
lean_dec_ref(v_inputs_1679_);
return v_res_1686_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7(lean_object* v_output_1687_, lean_object* v_inputs_1688_, lean_object* v_as_1689_, lean_object* v_as_x27_1690_, lean_object* v_b_1691_, lean_object* v_a_1692_){
_start:
{
lean_object* v___x_1694_; 
v___x_1694_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___redArg(v_output_1687_, v_inputs_1688_, v_as_x27_1690_, v_b_1691_);
return v___x_1694_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7___boxed(lean_object* v_output_1695_, lean_object* v_inputs_1696_, lean_object* v_as_1697_, lean_object* v_as_x27_1698_, lean_object* v_b_1699_, lean_object* v_a_1700_, lean_object* v___y_1701_){
_start:
{
lean_object* v_res_1702_; 
v_res_1702_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__6_spec__7(v_output_1695_, v_inputs_1696_, v_as_1697_, v_as_x27_1698_, v_b_1699_, v_a_1700_);
lean_dec(v_as_x27_1698_);
lean_dec(v_as_1697_);
lean_dec_ref(v_inputs_1696_);
lean_dec_ref(v_output_1695_);
return v_res_1702_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(lean_object* v_a_1703_, lean_object* v_as_1704_, size_t v_i_1705_, size_t v_stop_1706_, lean_object* v_b_1707_){
_start:
{
lean_object* v___y_1709_; uint8_t v___x_1713_; 
v___x_1713_ = lean_usize_dec_eq(v_i_1705_, v_stop_1706_);
if (v___x_1713_ == 0)
{
lean_object* v___x_1714_; lean_object* v_df_1715_; lean_object* v___x_1716_; uint8_t v___x_1717_; 
v___x_1714_ = lean_array_uget_borrowed(v_as_1704_, v_i_1705_);
v_df_1715_ = lean_ctor_get(v___x_1714_, 0);
lean_inc_ref(v_a_1703_);
lean_inc(v_df_1715_);
v___x_1716_ = lean_apply_1(v_a_1703_, v_df_1715_);
v___x_1717_ = lean_unbox(v___x_1716_);
if (v___x_1717_ == 0)
{
v___y_1709_ = v_b_1707_;
goto v___jp_1708_;
}
else
{
lean_object* v___x_1718_; 
lean_inc(v___x_1714_);
v___x_1718_ = lean_array_push(v_b_1707_, v___x_1714_);
v___y_1709_ = v___x_1718_;
goto v___jp_1708_;
}
}
else
{
lean_dec_ref(v_a_1703_);
return v_b_1707_;
}
v___jp_1708_:
{
size_t v___x_1710_; size_t v___x_1711_; 
v___x_1710_ = ((size_t)1ULL);
v___x_1711_ = lean_usize_add(v_i_1705_, v___x_1710_);
v_i_1705_ = v___x_1711_;
v_b_1707_ = v___y_1709_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1___boxed(lean_object* v_a_1719_, lean_object* v_as_1720_, lean_object* v_i_1721_, lean_object* v_stop_1722_, lean_object* v_b_1723_){
_start:
{
size_t v_i_boxed_1724_; size_t v_stop_boxed_1725_; lean_object* v_res_1726_; 
v_i_boxed_1724_ = lean_unbox_usize(v_i_1721_);
lean_dec(v_i_1721_);
v_stop_boxed_1725_ = lean_unbox_usize(v_stop_1722_);
lean_dec(v_stop_1722_);
v_res_1726_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(v_a_1719_, v_as_1720_, v_i_boxed_1724_, v_stop_boxed_1725_, v_b_1723_);
lean_dec_ref(v_as_1720_);
return v_res_1726_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0(lean_object* v_a_1728_, lean_object* v_a_1729_){
_start:
{
if (lean_obj_tag(v_a_1728_) == 0)
{
lean_object* v___x_1730_; 
v___x_1730_ = l_List_reverse___redArg(v_a_1729_);
return v___x_1730_;
}
else
{
lean_object* v_head_1731_; lean_object* v_tail_1732_; lean_object* v___x_1734_; uint8_t v_isShared_1735_; uint8_t v_isSharedCheck_1759_; 
v_head_1731_ = lean_ctor_get(v_a_1728_, 0);
v_tail_1732_ = lean_ctor_get(v_a_1728_, 1);
v_isSharedCheck_1759_ = !lean_is_exclusive(v_a_1728_);
if (v_isSharedCheck_1759_ == 0)
{
v___x_1734_ = v_a_1728_;
v_isShared_1735_ = v_isSharedCheck_1759_;
goto v_resetjp_1733_;
}
else
{
lean_inc(v_tail_1732_);
lean_inc(v_head_1731_);
lean_dec(v_a_1728_);
v___x_1734_ = lean_box(0);
v_isShared_1735_ = v_isSharedCheck_1759_;
goto v_resetjp_1733_;
}
v_resetjp_1733_:
{
lean_object* v_fst_1736_; lean_object* v_snd_1737_; lean_object* v___x_1739_; uint8_t v_isShared_1740_; uint8_t v_isSharedCheck_1758_; 
v_fst_1736_ = lean_ctor_get(v_head_1731_, 0);
v_snd_1737_ = lean_ctor_get(v_head_1731_, 1);
v_isSharedCheck_1758_ = !lean_is_exclusive(v_head_1731_);
if (v_isSharedCheck_1758_ == 0)
{
v___x_1739_ = v_head_1731_;
v_isShared_1740_ = v_isSharedCheck_1758_;
goto v_resetjp_1738_;
}
else
{
lean_inc(v_snd_1737_);
lean_inc(v_fst_1736_);
lean_dec(v_head_1731_);
v___x_1739_ = lean_box(0);
v_isShared_1740_ = v_isSharedCheck_1758_;
goto v_resetjp_1738_;
}
v_resetjp_1738_:
{
lean_object* v___x_1741_; lean_object* v___x_1742_; lean_object* v___x_1743_; lean_object* v___x_1744_; lean_object* v___x_1745_; lean_object* v___x_1747_; 
v___x_1741_ = ((lean_object*)(l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0___closed__0));
v___x_1742_ = lean_box(0);
v___x_1743_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select___closed__6));
v___x_1744_ = l_Lean_JsonNumber_fromNat(v_snd_1737_);
v___x_1745_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1745_, 0, v___x_1744_);
if (v_isShared_1740_ == 0)
{
lean_ctor_set(v___x_1739_, 1, v___x_1745_);
lean_ctor_set(v___x_1739_, 0, v___x_1743_);
v___x_1747_ = v___x_1739_;
goto v_reusejp_1746_;
}
else
{
lean_object* v_reuseFailAlloc_1757_; 
v_reuseFailAlloc_1757_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1757_, 0, v___x_1743_);
lean_ctor_set(v_reuseFailAlloc_1757_, 1, v___x_1745_);
v___x_1747_ = v_reuseFailAlloc_1757_;
goto v_reusejp_1746_;
}
v_reusejp_1746_:
{
lean_object* v___x_1748_; lean_object* v___x_1749_; lean_object* v___x_1751_; 
v___x_1748_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(v_fst_1736_);
v___x_1749_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1749_, 0, v___x_1741_);
lean_ctor_set(v___x_1749_, 1, v___x_1748_);
if (v_isShared_1735_ == 0)
{
lean_ctor_set(v___x_1734_, 1, v___x_1742_);
lean_ctor_set(v___x_1734_, 0, v___x_1749_);
v___x_1751_ = v___x_1734_;
goto v_reusejp_1750_;
}
else
{
lean_object* v_reuseFailAlloc_1756_; 
v_reuseFailAlloc_1756_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1756_, 0, v___x_1749_);
lean_ctor_set(v_reuseFailAlloc_1756_, 1, v___x_1742_);
v___x_1751_ = v_reuseFailAlloc_1756_;
goto v_reusejp_1750_;
}
v_reusejp_1750_:
{
lean_object* v___x_1752_; lean_object* v___x_1753_; lean_object* v___x_1754_; 
v___x_1752_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1752_, 0, v___x_1747_);
lean_ctor_set(v___x_1752_, 1, v___x_1751_);
v___x_1753_ = l_Lean_Json_mkObj(v___x_1752_);
lean_dec_ref_known(v___x_1752_, 2);
v___x_1754_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1754_, 0, v___x_1753_);
lean_ctor_set(v___x_1754_, 1, v_a_1729_);
v_a_1728_ = v_tail_1732_;
v_a_1729_ = v___x_1754_;
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
lean_object* v___x_1770_; lean_object* v___x_1771_; 
v___x_1770_ = lean_unsigned_to_nat(172432u);
v___x_1771_ = l_Lean_JsonNumber_fromNat(v___x_1770_);
return v___x_1771_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8(void){
_start:
{
lean_object* v___x_1772_; lean_object* v___x_1773_; 
v___x_1772_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__7, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__7_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__7);
v___x_1773_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1773_, 0, v___x_1772_);
return v___x_1773_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9(void){
_start:
{
lean_object* v___x_1774_; lean_object* v___x_1775_; lean_object* v___x_1776_; 
v___x_1774_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__8);
v___x_1775_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__6));
v___x_1776_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1776_, 0, v___x_1775_);
lean_ctor_set(v___x_1776_, 1, v___x_1774_);
return v___x_1776_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10(void){
_start:
{
lean_object* v___x_1777_; lean_object* v___x_1778_; lean_object* v___x_1779_; 
v___x_1777_ = lean_box(0);
v___x_1778_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__9);
v___x_1779_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1779_, 0, v___x_1778_);
lean_ctor_set(v___x_1779_, 1, v___x_1777_);
return v___x_1779_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode(lean_object* v_mode_1798_, lean_object* v_inputs_1799_, uint8_t v_withCensus_1800_, uint8_t v_wait_1801_){
_start:
{
lean_object* v___x_1803_; lean_object* v___x_1804_; 
lean_inc_ref(v_mode_1798_);
v___x_1803_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_select(v_mode_1798_);
v___x_1804_ = l_IO_ofExcept___at___00Std_Time_Database_TZdb_parseTZIfFromDisk_spec__0___redArg(v___x_1803_);
if (lean_obj_tag(v___x_1804_) == 0)
{
lean_object* v_a_1805_; lean_object* v___x_1806_; lean_object* v___y_1808_; lean_object* v___x_1931_; lean_object* v___x_1932_; uint8_t v___x_1933_; 
v_a_1805_ = lean_ctor_get(v___x_1804_, 0);
lean_inc(v_a_1805_);
lean_dec_ref_known(v___x_1804_, 1);
v___x_1806_ = lean_unsigned_to_nat(0u);
v___x_1931_ = lean_array_get_size(v_inputs_1799_);
v___x_1932_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__21));
v___x_1933_ = lean_nat_dec_lt(v___x_1806_, v___x_1931_);
if (v___x_1933_ == 0)
{
lean_dec(v_a_1805_);
v___y_1808_ = v___x_1932_;
goto v___jp_1807_;
}
else
{
uint8_t v___x_1934_; 
v___x_1934_ = lean_nat_dec_le(v___x_1931_, v___x_1931_);
if (v___x_1934_ == 0)
{
if (v___x_1933_ == 0)
{
lean_dec(v_a_1805_);
v___y_1808_ = v___x_1932_;
goto v___jp_1807_;
}
else
{
size_t v___x_1935_; size_t v___x_1936_; lean_object* v___x_1937_; 
v___x_1935_ = ((size_t)0ULL);
v___x_1936_ = lean_usize_of_nat(v___x_1931_);
v___x_1937_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(v_a_1805_, v_inputs_1799_, v___x_1935_, v___x_1936_, v___x_1932_);
v___y_1808_ = v___x_1937_;
goto v___jp_1807_;
}
}
else
{
size_t v___x_1938_; size_t v___x_1939_; lean_object* v___x_1940_; 
v___x_1938_ = ((size_t)0ULL);
v___x_1939_ = lean_usize_of_nat(v___x_1931_);
v___x_1940_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__1(v_a_1805_, v_inputs_1799_, v___x_1938_, v___x_1939_, v___x_1932_);
v___y_1808_ = v___x_1940_;
goto v___jp_1807_;
}
}
v___jp_1807_:
{
lean_object* v___x_1809_; lean_object* v___x_1810_; lean_object* v___x_1811_; lean_object* v___x_1812_; lean_object* v___x_1813_; lean_object* v___x_1814_; lean_object* v___x_1815_; lean_object* v___x_1816_; lean_object* v___x_1817_; lean_object* v___x_1818_; lean_object* v___x_1819_; lean_object* v___x_1820_; lean_object* v___x_1821_; lean_object* v___x_1822_; lean_object* v___x_1823_; lean_object* v___x_1824_; 
v___x_1809_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__3));
v___x_1810_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__4));
v___x_1811_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1811_, 0, v_mode_1798_);
v___x_1812_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1812_, 0, v___x_1810_);
lean_ctor_set(v___x_1812_, 1, v___x_1811_);
v___x_1813_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__5));
v___x_1814_ = lean_array_get_size(v___y_1808_);
v___x_1815_ = l_Lean_JsonNumber_fromNat(v___x_1814_);
v___x_1816_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1816_, 0, v___x_1815_);
v___x_1817_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1817_, 0, v___x_1813_);
lean_ctor_set(v___x_1817_, 1, v___x_1816_);
v___x_1818_ = lean_box(0);
v___x_1819_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__10);
v___x_1820_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1820_, 0, v___x_1817_);
lean_ctor_set(v___x_1820_, 1, v___x_1819_);
lean_inc_ref(v___x_1812_);
v___x_1821_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1821_, 0, v___x_1812_);
lean_ctor_set(v___x_1821_, 1, v___x_1820_);
v___x_1822_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1822_, 0, v___x_1809_);
lean_ctor_set(v___x_1822_, 1, v___x_1821_);
v___x_1823_ = l_Lean_Json_mkObj(v___x_1822_);
lean_dec_ref_known(v___x_1822_, 2);
v___x_1824_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_1823_);
if (lean_obj_tag(v___x_1824_) == 0)
{
lean_object* v___x_1826_; uint8_t v_isShared_1827_; uint8_t v_isSharedCheck_1929_; 
v_isSharedCheck_1929_ = !lean_is_exclusive(v___x_1824_);
if (v_isSharedCheck_1929_ == 0)
{
lean_object* v_unused_1930_; 
v_unused_1930_ = lean_ctor_get(v___x_1824_, 0);
lean_dec(v_unused_1930_);
v___x_1826_ = v___x_1824_;
v_isShared_1827_ = v_isSharedCheck_1929_;
goto v_resetjp_1825_;
}
else
{
lean_dec(v___x_1824_);
v___x_1826_ = lean_box(0);
v_isShared_1827_ = v_isSharedCheck_1929_;
goto v_resetjp_1825_;
}
v_resetjp_1825_:
{
lean_object* v___x_1828_; lean_object* v___x_1829_; 
v___x_1828_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__11));
v___x_1829_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_wait_1801_, v___x_1828_);
if (lean_obj_tag(v___x_1829_) == 0)
{
lean_object* v___x_1831_; uint8_t v_isShared_1832_; uint8_t v_isSharedCheck_1927_; 
v_isSharedCheck_1927_ = !lean_is_exclusive(v___x_1829_);
if (v_isSharedCheck_1927_ == 0)
{
lean_object* v_unused_1928_; 
v_unused_1928_ = lean_ctor_get(v___x_1829_, 0);
lean_dec(v_unused_1928_);
v___x_1831_ = v___x_1829_;
v_isShared_1832_ = v_isSharedCheck_1927_;
goto v_resetjp_1830_;
}
else
{
lean_dec(v___x_1829_);
v___x_1831_ = lean_box(0);
v_isShared_1832_ = v_isSharedCheck_1927_;
goto v_resetjp_1830_;
}
v_resetjp_1830_:
{
lean_object* v___x_1833_; 
v___x_1833_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runDecode(v___y_1808_);
if (lean_obj_tag(v___x_1833_) == 0)
{
lean_object* v_a_1834_; lean_object* v_fst_1835_; lean_object* v_snd_1836_; lean_object* v___x_1838_; uint8_t v_isShared_1839_; uint8_t v_isSharedCheck_1918_; 
v_a_1834_ = lean_ctor_get(v___x_1833_, 0);
lean_inc(v_a_1834_);
lean_dec_ref_known(v___x_1833_, 1);
v_fst_1835_ = lean_ctor_get(v_a_1834_, 0);
v_snd_1836_ = lean_ctor_get(v_a_1834_, 1);
v_isSharedCheck_1918_ = !lean_is_exclusive(v_a_1834_);
if (v_isSharedCheck_1918_ == 0)
{
v___x_1838_ = v_a_1834_;
v_isShared_1839_ = v_isSharedCheck_1918_;
goto v_resetjp_1837_;
}
else
{
lean_inc(v_snd_1836_);
lean_inc(v_fst_1835_);
lean_dec(v_a_1834_);
v___x_1838_ = lean_box(0);
v_isShared_1839_ = v_isSharedCheck_1918_;
goto v_resetjp_1837_;
}
v_resetjp_1837_:
{
lean_object* v___x_1840_; lean_object* v___x_1841_; lean_object* v___x_1842_; lean_object* v___x_1843_; lean_object* v___x_1845_; 
v___x_1840_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__14));
v___x_1841_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__15));
v___x_1842_ = lean_array_get_size(v_fst_1835_);
v___x_1843_ = l_Lean_JsonNumber_fromNat(v___x_1842_);
if (v_isShared_1832_ == 0)
{
lean_ctor_set_tag(v___x_1831_, 2);
lean_ctor_set(v___x_1831_, 0, v___x_1843_);
v___x_1845_ = v___x_1831_;
goto v_reusejp_1844_;
}
else
{
lean_object* v_reuseFailAlloc_1917_; 
v_reuseFailAlloc_1917_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1917_, 0, v___x_1843_);
v___x_1845_ = v_reuseFailAlloc_1917_;
goto v_reusejp_1844_;
}
v_reusejp_1844_:
{
lean_object* v___x_1847_; 
if (v_isShared_1839_ == 0)
{
lean_ctor_set(v___x_1838_, 1, v___x_1845_);
lean_ctor_set(v___x_1838_, 0, v___x_1841_);
v___x_1847_ = v___x_1838_;
goto v_reusejp_1846_;
}
else
{
lean_object* v_reuseFailAlloc_1916_; 
v_reuseFailAlloc_1916_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1916_, 0, v___x_1841_);
lean_ctor_set(v_reuseFailAlloc_1916_, 1, v___x_1845_);
v___x_1847_ = v_reuseFailAlloc_1916_;
goto v_reusejp_1846_;
}
v_reusejp_1846_:
{
lean_object* v___x_1848_; lean_object* v___x_1849_; lean_object* v___x_1851_; 
v___x_1848_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__16));
v___x_1849_ = l_Lean_JsonNumber_fromNat(v_snd_1836_);
if (v_isShared_1827_ == 0)
{
lean_ctor_set_tag(v___x_1826_, 2);
lean_ctor_set(v___x_1826_, 0, v___x_1849_);
v___x_1851_ = v___x_1826_;
goto v_reusejp_1850_;
}
else
{
lean_object* v_reuseFailAlloc_1915_; 
v_reuseFailAlloc_1915_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1915_, 0, v___x_1849_);
v___x_1851_ = v_reuseFailAlloc_1915_;
goto v_reusejp_1850_;
}
v_reusejp_1850_:
{
lean_object* v___x_1852_; lean_object* v___x_1853_; lean_object* v___x_1854_; lean_object* v___x_1855_; lean_object* v___x_1856_; lean_object* v___x_1857_; lean_object* v___x_1858_; 
v___x_1852_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1852_, 0, v___x_1848_);
lean_ctor_set(v___x_1852_, 1, v___x_1851_);
v___x_1853_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1853_, 0, v___x_1852_);
lean_ctor_set(v___x_1853_, 1, v___x_1818_);
lean_inc_ref(v___x_1853_);
v___x_1854_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1854_, 0, v___x_1847_);
lean_ctor_set(v___x_1854_, 1, v___x_1853_);
lean_inc_ref(v___x_1812_);
v___x_1855_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1855_, 0, v___x_1812_);
lean_ctor_set(v___x_1855_, 1, v___x_1854_);
v___x_1856_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1856_, 0, v___x_1840_);
lean_ctor_set(v___x_1856_, 1, v___x_1855_);
v___x_1857_ = l_Lean_Json_mkObj(v___x_1856_);
lean_dec_ref_known(v___x_1856_, 2);
v___x_1858_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_1857_);
if (lean_obj_tag(v___x_1858_) == 0)
{
lean_object* v___x_1859_; lean_object* v___x_1860_; 
lean_dec_ref_known(v___x_1858_, 1);
v___x_1859_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__17));
v___x_1860_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_wait_1801_, v___x_1859_);
if (lean_obj_tag(v___x_1860_) == 0)
{
lean_object* v___x_1861_; 
lean_dec_ref_known(v___x_1860_, 1);
v___x_1861_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_consume(v___y_1808_, v_fst_1835_);
if (lean_obj_tag(v___x_1861_) == 0)
{
lean_object* v_a_1862_; lean_object* v_fst_1863_; lean_object* v_snd_1864_; lean_object* v___x_1866_; uint8_t v_isShared_1867_; uint8_t v_isSharedCheck_1906_; 
v_a_1862_ = lean_ctor_get(v___x_1861_, 0);
lean_inc(v_a_1862_);
lean_dec_ref_known(v___x_1861_, 1);
v_fst_1863_ = lean_ctor_get(v_a_1862_, 0);
v_snd_1864_ = lean_ctor_get(v_a_1862_, 1);
v_isSharedCheck_1906_ = !lean_is_exclusive(v_a_1862_);
if (v_isSharedCheck_1906_ == 0)
{
v___x_1866_ = v_a_1862_;
v_isShared_1867_ = v_isSharedCheck_1906_;
goto v_resetjp_1865_;
}
else
{
lean_inc(v_snd_1864_);
lean_inc(v_fst_1863_);
lean_dec(v_a_1862_);
v___x_1866_ = lean_box(0);
v_isShared_1867_ = v_isSharedCheck_1906_;
goto v_resetjp_1865_;
}
v_resetjp_1865_:
{
lean_object* v___x_1868_; lean_object* v___x_1869_; lean_object* v___x_1870_; lean_object* v___x_1872_; 
v___x_1868_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__20));
v___x_1869_ = ((lean_object*)(l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0___closed__0));
v___x_1870_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(v_fst_1863_);
if (v_isShared_1867_ == 0)
{
lean_ctor_set(v___x_1866_, 1, v___x_1870_);
lean_ctor_set(v___x_1866_, 0, v___x_1869_);
v___x_1872_ = v___x_1866_;
goto v_reusejp_1871_;
}
else
{
lean_object* v_reuseFailAlloc_1905_; 
v_reuseFailAlloc_1905_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1905_, 0, v___x_1869_);
lean_ctor_set(v_reuseFailAlloc_1905_, 1, v___x_1870_);
v___x_1872_ = v_reuseFailAlloc_1905_;
goto v_reusejp_1871_;
}
v_reusejp_1871_:
{
lean_object* v___x_1873_; lean_object* v___x_1874_; lean_object* v___x_1875_; lean_object* v___x_1876_; lean_object* v___x_1877_; lean_object* v___x_1878_; lean_object* v___x_1879_; lean_object* v___x_1880_; lean_object* v___x_1881_; lean_object* v___x_1882_; lean_object* v___x_1883_; lean_object* v___x_1884_; 
v___x_1873_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census___closed__7));
v___x_1874_ = lean_array_to_list(v_snd_1864_);
v___x_1875_ = l_List_zipIdxTR___redArg(v___x_1874_, v___x_1806_);
v___x_1876_ = l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0(v___x_1875_, v___x_1818_);
v___x_1877_ = l_Lean_List_toJson___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__4(v___x_1876_);
v___x_1878_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1878_, 0, v___x_1873_);
lean_ctor_set(v___x_1878_, 1, v___x_1877_);
v___x_1879_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1879_, 0, v___x_1878_);
lean_ctor_set(v___x_1879_, 1, v___x_1853_);
v___x_1880_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1880_, 0, v___x_1872_);
lean_ctor_set(v___x_1880_, 1, v___x_1879_);
v___x_1881_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1881_, 0, v___x_1812_);
lean_ctor_set(v___x_1881_, 1, v___x_1880_);
v___x_1882_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1882_, 0, v___x_1868_);
lean_ctor_set(v___x_1882_, 1, v___x_1881_);
v___x_1883_ = l_Lean_Json_mkObj(v___x_1882_);
lean_dec_ref_known(v___x_1882_, 2);
v___x_1884_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_1883_);
if (lean_obj_tag(v___x_1884_) == 0)
{
lean_object* v___x_1886_; uint8_t v_isShared_1887_; uint8_t v_isSharedCheck_1903_; 
v_isSharedCheck_1903_ = !lean_is_exclusive(v___x_1884_);
if (v_isSharedCheck_1903_ == 0)
{
lean_object* v_unused_1904_; 
v_unused_1904_ = lean_ctor_get(v___x_1884_, 0);
lean_dec(v_unused_1904_);
v___x_1886_ = v___x_1884_;
v_isShared_1887_ = v_isSharedCheck_1903_;
goto v_resetjp_1885_;
}
else
{
lean_dec(v___x_1884_);
v___x_1886_ = lean_box(0);
v_isShared_1887_ = v_isSharedCheck_1903_;
goto v_resetjp_1885_;
}
v_resetjp_1885_:
{
if (v_withCensus_1800_ == 0)
{
lean_object* v___x_1888_; lean_object* v___x_1890_; 
lean_dec(v_fst_1835_);
lean_dec_ref(v___y_1808_);
v___x_1888_ = lean_box(0);
if (v_isShared_1887_ == 0)
{
lean_ctor_set(v___x_1886_, 0, v___x_1888_);
v___x_1890_ = v___x_1886_;
goto v_reusejp_1889_;
}
else
{
lean_object* v_reuseFailAlloc_1891_; 
v_reuseFailAlloc_1891_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1891_, 0, v___x_1888_);
v___x_1890_ = v_reuseFailAlloc_1891_;
goto v_reusejp_1889_;
}
v_reusejp_1889_:
{
return v___x_1890_;
}
}
else
{
lean_object* v___x_1892_; 
lean_del_object(v___x_1886_);
v___x_1892_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census(v___y_1808_, v_fst_1835_);
lean_dec(v_fst_1835_);
lean_dec_ref(v___y_1808_);
if (lean_obj_tag(v___x_1892_) == 0)
{
lean_object* v_a_1893_; lean_object* v___x_1894_; 
v_a_1893_ = lean_ctor_get(v___x_1892_, 0);
lean_inc(v_a_1893_);
lean_dec_ref_known(v___x_1892_, 1);
v___x_1894_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v_a_1893_);
return v___x_1894_;
}
else
{
lean_object* v_a_1895_; lean_object* v___x_1897_; uint8_t v_isShared_1898_; uint8_t v_isSharedCheck_1902_; 
v_a_1895_ = lean_ctor_get(v___x_1892_, 0);
v_isSharedCheck_1902_ = !lean_is_exclusive(v___x_1892_);
if (v_isSharedCheck_1902_ == 0)
{
v___x_1897_ = v___x_1892_;
v_isShared_1898_ = v_isSharedCheck_1902_;
goto v_resetjp_1896_;
}
else
{
lean_inc(v_a_1895_);
lean_dec(v___x_1892_);
v___x_1897_ = lean_box(0);
v_isShared_1898_ = v_isSharedCheck_1902_;
goto v_resetjp_1896_;
}
v_resetjp_1896_:
{
lean_object* v___x_1900_; 
if (v_isShared_1898_ == 0)
{
v___x_1900_ = v___x_1897_;
goto v_reusejp_1899_;
}
else
{
lean_object* v_reuseFailAlloc_1901_; 
v_reuseFailAlloc_1901_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1901_, 0, v_a_1895_);
v___x_1900_ = v_reuseFailAlloc_1901_;
goto v_reusejp_1899_;
}
v_reusejp_1899_:
{
return v___x_1900_;
}
}
}
}
}
}
else
{
lean_dec(v_fst_1835_);
lean_dec_ref(v___y_1808_);
return v___x_1884_;
}
}
}
}
else
{
lean_object* v_a_1907_; lean_object* v___x_1909_; uint8_t v_isShared_1910_; uint8_t v_isSharedCheck_1914_; 
lean_dec_ref_known(v___x_1853_, 2);
lean_dec(v_fst_1835_);
lean_dec_ref_known(v___x_1812_, 2);
lean_dec_ref(v___y_1808_);
v_a_1907_ = lean_ctor_get(v___x_1861_, 0);
v_isSharedCheck_1914_ = !lean_is_exclusive(v___x_1861_);
if (v_isSharedCheck_1914_ == 0)
{
v___x_1909_ = v___x_1861_;
v_isShared_1910_ = v_isSharedCheck_1914_;
goto v_resetjp_1908_;
}
else
{
lean_inc(v_a_1907_);
lean_dec(v___x_1861_);
v___x_1909_ = lean_box(0);
v_isShared_1910_ = v_isSharedCheck_1914_;
goto v_resetjp_1908_;
}
v_resetjp_1908_:
{
lean_object* v___x_1912_; 
if (v_isShared_1910_ == 0)
{
v___x_1912_ = v___x_1909_;
goto v_reusejp_1911_;
}
else
{
lean_object* v_reuseFailAlloc_1913_; 
v_reuseFailAlloc_1913_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1913_, 0, v_a_1907_);
v___x_1912_ = v_reuseFailAlloc_1913_;
goto v_reusejp_1911_;
}
v_reusejp_1911_:
{
return v___x_1912_;
}
}
}
}
else
{
lean_dec_ref_known(v___x_1853_, 2);
lean_dec(v_fst_1835_);
lean_dec_ref_known(v___x_1812_, 2);
lean_dec_ref(v___y_1808_);
return v___x_1860_;
}
}
else
{
lean_dec_ref_known(v___x_1853_, 2);
lean_dec(v_fst_1835_);
lean_dec_ref_known(v___x_1812_, 2);
lean_dec_ref(v___y_1808_);
return v___x_1858_;
}
}
}
}
}
}
else
{
lean_object* v_a_1919_; lean_object* v___x_1921_; uint8_t v_isShared_1922_; uint8_t v_isSharedCheck_1926_; 
lean_del_object(v___x_1831_);
lean_del_object(v___x_1826_);
lean_dec_ref_known(v___x_1812_, 2);
lean_dec_ref(v___y_1808_);
v_a_1919_ = lean_ctor_get(v___x_1833_, 0);
v_isSharedCheck_1926_ = !lean_is_exclusive(v___x_1833_);
if (v_isSharedCheck_1926_ == 0)
{
v___x_1921_ = v___x_1833_;
v_isShared_1922_ = v_isSharedCheck_1926_;
goto v_resetjp_1920_;
}
else
{
lean_inc(v_a_1919_);
lean_dec(v___x_1833_);
v___x_1921_ = lean_box(0);
v_isShared_1922_ = v_isSharedCheck_1926_;
goto v_resetjp_1920_;
}
v_resetjp_1920_:
{
lean_object* v___x_1924_; 
if (v_isShared_1922_ == 0)
{
v___x_1924_ = v___x_1921_;
goto v_reusejp_1923_;
}
else
{
lean_object* v_reuseFailAlloc_1925_; 
v_reuseFailAlloc_1925_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1925_, 0, v_a_1919_);
v___x_1924_ = v_reuseFailAlloc_1925_;
goto v_reusejp_1923_;
}
v_reusejp_1923_:
{
return v___x_1924_;
}
}
}
}
}
else
{
lean_del_object(v___x_1826_);
lean_dec_ref_known(v___x_1812_, 2);
lean_dec_ref(v___y_1808_);
return v___x_1829_;
}
}
}
else
{
lean_dec_ref_known(v___x_1812_, 2);
lean_dec_ref(v___y_1808_);
return v___x_1824_;
}
}
}
else
{
lean_object* v_a_1941_; lean_object* v___x_1943_; uint8_t v_isShared_1944_; uint8_t v_isSharedCheck_1948_; 
lean_dec_ref(v_mode_1798_);
v_a_1941_ = lean_ctor_get(v___x_1804_, 0);
v_isSharedCheck_1948_ = !lean_is_exclusive(v___x_1804_);
if (v_isSharedCheck_1948_ == 0)
{
v___x_1943_ = v___x_1804_;
v_isShared_1944_ = v_isSharedCheck_1948_;
goto v_resetjp_1942_;
}
else
{
lean_inc(v_a_1941_);
lean_dec(v___x_1804_);
v___x_1943_ = lean_box(0);
v_isShared_1944_ = v_isSharedCheck_1948_;
goto v_resetjp_1942_;
}
v_resetjp_1942_:
{
lean_object* v___x_1946_; 
if (v_isShared_1944_ == 0)
{
v___x_1946_ = v___x_1943_;
goto v_reusejp_1945_;
}
else
{
lean_object* v_reuseFailAlloc_1947_; 
v_reuseFailAlloc_1947_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1947_, 0, v_a_1941_);
v___x_1946_ = v_reuseFailAlloc_1947_;
goto v_reusejp_1945_;
}
v_reusejp_1945_:
{
return v___x_1946_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___boxed(lean_object* v_mode_1949_, lean_object* v_inputs_1950_, lean_object* v_withCensus_1951_, lean_object* v_wait_1952_, lean_object* v_a_1953_){
_start:
{
uint8_t v_withCensus_boxed_1954_; uint8_t v_wait_boxed_1955_; lean_object* v_res_1956_; 
v_withCensus_boxed_1954_ = lean_unbox(v_withCensus_1951_);
v_wait_boxed_1955_ = lean_unbox(v_wait_1952_);
v_res_1956_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode(v_mode_1949_, v_inputs_1950_, v_withCensus_boxed_1954_, v_wait_boxed_1955_);
lean_dec_ref(v_inputs_1950_);
return v_res_1956_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0(uint8_t v_candidate_1963_, lean_object* v_register_1964_, lean_object* v_as_1965_, size_t v_sz_1966_, size_t v_i_1967_, lean_object* v_b_1968_){
_start:
{
lean_object* v_a_1971_; uint8_t v___x_1975_; 
v___x_1975_ = lean_usize_dec_lt(v_i_1967_, v_sz_1966_);
if (v___x_1975_ == 0)
{
lean_object* v___x_1976_; 
v___x_1976_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1976_, 0, v_b_1968_);
return v___x_1976_;
}
else
{
lean_object* v_fst_1977_; lean_object* v_snd_1978_; lean_object* v___x_1980_; uint8_t v_isShared_1981_; uint8_t v_isSharedCheck_2044_; 
v_fst_1977_ = lean_ctor_get(v_b_1968_, 0);
v_snd_1978_ = lean_ctor_get(v_b_1968_, 1);
v_isSharedCheck_2044_ = !lean_is_exclusive(v_b_1968_);
if (v_isSharedCheck_2044_ == 0)
{
v___x_1980_ = v_b_1968_;
v_isShared_1981_ = v_isSharedCheck_2044_;
goto v_resetjp_1979_;
}
else
{
lean_inc(v_snd_1978_);
lean_inc(v_fst_1977_);
lean_dec(v_b_1968_);
v___x_1980_ = lean_box(0);
v_isShared_1981_ = v_isSharedCheck_2044_;
goto v_resetjp_1979_;
}
v_resetjp_1979_:
{
lean_object* v_a_1982_; lean_object* v_df_1983_; lean_object* v_bytes_1984_; lean_object* v___x_1986_; uint8_t v_isShared_1987_; uint8_t v_isSharedCheck_2043_; 
v_a_1982_ = lean_array_uget(v_as_1965_, v_i_1967_);
v_df_1983_ = lean_ctor_get(v_a_1982_, 0);
v_bytes_1984_ = lean_ctor_get(v_a_1982_, 1);
v_isSharedCheck_2043_ = !lean_is_exclusive(v_a_1982_);
if (v_isSharedCheck_2043_ == 0)
{
v___x_1986_ = v_a_1982_;
v_isShared_1987_ = v_isSharedCheck_2043_;
goto v_resetjp_1985_;
}
else
{
lean_inc(v_bytes_1984_);
lean_inc(v_df_1983_);
lean_dec(v_a_1982_);
v___x_1986_ = lean_box(0);
v_isShared_1987_ = v_isSharedCheck_2043_;
goto v_resetjp_1985_;
}
v_resetjp_1985_:
{
lean_object* v___y_1989_; lean_object* v___y_1990_; lean_object* v___y_1991_; lean_object* v_nonempty_1998_; lean_object* v___x_2036_; uint8_t v___x_2037_; 
v_nonempty_1998_ = lean_unsigned_to_nat(0u);
v___x_2036_ = lean_unsigned_to_nat(20u);
v___x_2037_ = lean_nat_dec_eq(v_df_1983_, v___x_2036_);
if (v___x_2037_ == 0)
{
lean_object* v___x_2038_; uint8_t v___x_2039_; 
v___x_2038_ = lean_unsigned_to_nat(21u);
v___x_2039_ = lean_nat_dec_eq(v_df_1983_, v___x_2038_);
if (v___x_2039_ == 0)
{
lean_object* v___x_2041_; 
lean_dec(v_bytes_1984_);
lean_dec(v_df_1983_);
lean_del_object(v___x_1980_);
if (v_isShared_1987_ == 0)
{
lean_ctor_set(v___x_1986_, 1, v_snd_1978_);
lean_ctor_set(v___x_1986_, 0, v_fst_1977_);
v___x_2041_ = v___x_1986_;
goto v_reusejp_2040_;
}
else
{
lean_object* v_reuseFailAlloc_2042_; 
v_reuseFailAlloc_2042_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2042_, 0, v_fst_1977_);
lean_ctor_set(v_reuseFailAlloc_2042_, 1, v_snd_1978_);
v___x_2041_ = v_reuseFailAlloc_2042_;
goto v_reusejp_2040_;
}
v_reusejp_2040_:
{
v_a_1971_ = v___x_2041_;
goto v___jp_1970_;
}
}
else
{
lean_del_object(v___x_1986_);
goto v___jp_1999_;
}
}
else
{
lean_del_object(v___x_1986_);
goto v___jp_1999_;
}
v___jp_1988_:
{
lean_object* v___x_1992_; lean_object* v___x_1993_; lean_object* v___x_1994_; lean_object* v___x_1996_; 
v___x_1992_ = lp_lean1090_Lean1090_Impl_frameOracleAltitude(v___y_1990_);
lean_dec_ref(v___y_1990_);
v___x_1993_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1993_, 0, v_df_1983_);
lean_ctor_set(v___x_1993_, 1, v___y_1989_);
lean_ctor_set(v___x_1993_, 2, v___x_1992_);
v___x_1994_ = lean_array_push(v_fst_1977_, v___x_1993_);
if (v_isShared_1981_ == 0)
{
lean_ctor_set(v___x_1980_, 1, v___y_1991_);
lean_ctor_set(v___x_1980_, 0, v___x_1994_);
v___x_1996_ = v___x_1980_;
goto v_reusejp_1995_;
}
else
{
lean_object* v_reuseFailAlloc_1997_; 
v_reuseFailAlloc_1997_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1997_, 0, v___x_1994_);
lean_ctor_set(v_reuseFailAlloc_1997_, 1, v___y_1991_);
v___x_1996_ = v_reuseFailAlloc_1997_;
goto v_reusejp_1995_;
}
v_reusejp_1995_:
{
v_a_1971_ = v___x_1996_;
goto v___jp_1970_;
}
}
v___jp_1999_:
{
lean_object* v___x_2000_; 
v___x_2000_ = lp_lean1090_Lean1090_Impl_decodeFrame(v_bytes_1984_);
lean_dec(v_bytes_1984_);
if (lean_obj_tag(v___x_2000_) == 1)
{
lean_object* v_val_2001_; lean_object* v___x_2003_; uint8_t v_isShared_2004_; uint8_t v_isSharedCheck_2033_; 
v_val_2001_ = lean_ctor_get(v___x_2000_, 0);
v_isSharedCheck_2033_ = !lean_is_exclusive(v___x_2000_);
if (v_isSharedCheck_2033_ == 0)
{
v___x_2003_ = v___x_2000_;
v_isShared_2004_ = v_isSharedCheck_2033_;
goto v_resetjp_2002_;
}
else
{
lean_inc(v_val_2001_);
lean_dec(v___x_2000_);
v___x_2003_ = lean_box(0);
v_isShared_2004_ = v_isSharedCheck_2033_;
goto v_resetjp_2002_;
}
v_resetjp_2002_:
{
lean_object* v_body_2005_; 
v_body_2005_ = lean_ctor_get(v_val_2001_, 0);
if (lean_obj_tag(v_body_2005_) == 6)
{
lean_object* v_mb_2006_; uint8_t v___x_2007_; 
lean_del_object(v___x_2003_);
v_mb_2006_ = lean_ctor_get(v_body_2005_, 1);
v___x_2007_ = lean_nat_dec_eq(v_mb_2006_, v_nonempty_1998_);
if (v___x_2007_ == 0)
{
lean_object* v___x_2008_; lean_object* v___x_2009_; 
v___x_2008_ = lean_unsigned_to_nat(1u);
v___x_2009_ = lean_nat_add(v_snd_1978_, v___x_2008_);
lean_dec(v_snd_1978_);
if (v_candidate_1963_ == 0)
{
uint8_t v___x_2010_; 
v___x_2010_ = lp_lean1090_Lean1090_Impl_bdsWireValid(v_register_1964_, v_mb_2006_);
if (v___x_2010_ == 0)
{
lean_object* v___x_2012_; uint8_t v_isShared_2013_; uint8_t v_isSharedCheck_2017_; 
lean_dec(v_df_1983_);
lean_del_object(v___x_1980_);
v_isSharedCheck_2017_ = !lean_is_exclusive(v_val_2001_);
if (v_isSharedCheck_2017_ == 0)
{
lean_object* v_unused_2018_; lean_object* v_unused_2019_; 
v_unused_2018_ = lean_ctor_get(v_val_2001_, 1);
lean_dec(v_unused_2018_);
v_unused_2019_ = lean_ctor_get(v_val_2001_, 0);
lean_dec(v_unused_2019_);
v___x_2012_ = v_val_2001_;
v_isShared_2013_ = v_isSharedCheck_2017_;
goto v_resetjp_2011_;
}
else
{
lean_dec(v_val_2001_);
v___x_2012_ = lean_box(0);
v_isShared_2013_ = v_isSharedCheck_2017_;
goto v_resetjp_2011_;
}
v_resetjp_2011_:
{
lean_object* v___x_2015_; 
if (v_isShared_2013_ == 0)
{
lean_ctor_set(v___x_2012_, 1, v___x_2009_);
lean_ctor_set(v___x_2012_, 0, v_fst_1977_);
v___x_2015_ = v___x_2012_;
goto v_reusejp_2014_;
}
else
{
lean_object* v_reuseFailAlloc_2016_; 
v_reuseFailAlloc_2016_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2016_, 0, v_fst_1977_);
lean_ctor_set(v_reuseFailAlloc_2016_, 1, v___x_2009_);
v___x_2015_ = v_reuseFailAlloc_2016_;
goto v_reusejp_2014_;
}
v_reusejp_2014_:
{
v_a_1971_ = v___x_2015_;
goto v___jp_1970_;
}
}
}
else
{
lean_inc(v_mb_2006_);
v___y_1989_ = v_mb_2006_;
v___y_1990_ = v_val_2001_;
v___y_1991_ = v___x_2009_;
goto v___jp_1988_;
}
}
else
{
lean_inc(v_mb_2006_);
v___y_1989_ = v_mb_2006_;
v___y_1990_ = v_val_2001_;
v___y_1991_ = v___x_2009_;
goto v___jp_1988_;
}
}
else
{
lean_object* v___x_2021_; uint8_t v_isShared_2022_; uint8_t v_isSharedCheck_2026_; 
lean_dec(v_df_1983_);
lean_del_object(v___x_1980_);
v_isSharedCheck_2026_ = !lean_is_exclusive(v_val_2001_);
if (v_isSharedCheck_2026_ == 0)
{
lean_object* v_unused_2027_; lean_object* v_unused_2028_; 
v_unused_2027_ = lean_ctor_get(v_val_2001_, 1);
lean_dec(v_unused_2027_);
v_unused_2028_ = lean_ctor_get(v_val_2001_, 0);
lean_dec(v_unused_2028_);
v___x_2021_ = v_val_2001_;
v_isShared_2022_ = v_isSharedCheck_2026_;
goto v_resetjp_2020_;
}
else
{
lean_dec(v_val_2001_);
v___x_2021_ = lean_box(0);
v_isShared_2022_ = v_isSharedCheck_2026_;
goto v_resetjp_2020_;
}
v_resetjp_2020_:
{
lean_object* v___x_2024_; 
if (v_isShared_2022_ == 0)
{
lean_ctor_set(v___x_2021_, 1, v_snd_1978_);
lean_ctor_set(v___x_2021_, 0, v_fst_1977_);
v___x_2024_ = v___x_2021_;
goto v_reusejp_2023_;
}
else
{
lean_object* v_reuseFailAlloc_2025_; 
v_reuseFailAlloc_2025_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2025_, 0, v_fst_1977_);
lean_ctor_set(v_reuseFailAlloc_2025_, 1, v_snd_1978_);
v___x_2024_ = v_reuseFailAlloc_2025_;
goto v_reusejp_2023_;
}
v_reusejp_2023_:
{
v_a_1971_ = v___x_2024_;
goto v___jp_1970_;
}
}
}
}
else
{
lean_object* v___x_2029_; lean_object* v___x_2031_; 
lean_dec(v_val_2001_);
lean_dec(v_df_1983_);
lean_del_object(v___x_1980_);
lean_dec(v_snd_1978_);
lean_dec(v_fst_1977_);
v___x_2029_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__1));
if (v_isShared_2004_ == 0)
{
lean_ctor_set(v___x_2003_, 0, v___x_2029_);
v___x_2031_ = v___x_2003_;
goto v_reusejp_2030_;
}
else
{
lean_object* v_reuseFailAlloc_2032_; 
v_reuseFailAlloc_2032_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2032_, 0, v___x_2029_);
v___x_2031_ = v_reuseFailAlloc_2032_;
goto v_reusejp_2030_;
}
v_reusejp_2030_:
{
return v___x_2031_;
}
}
}
}
else
{
lean_object* v___x_2034_; lean_object* v___x_2035_; 
lean_dec(v___x_2000_);
lean_dec(v_df_1983_);
lean_del_object(v___x_1980_);
lean_dec(v_snd_1978_);
lean_dec(v_fst_1977_);
v___x_2034_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___closed__3));
v___x_2035_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2035_, 0, v___x_2034_);
return v___x_2035_;
}
}
}
}
}
v___jp_1970_:
{
size_t v___x_1972_; size_t v___x_1973_; 
v___x_1972_ = ((size_t)1ULL);
v___x_1973_ = lean_usize_add(v_i_1967_, v___x_1972_);
v_i_1967_ = v___x_1973_;
v_b_1968_ = v_a_1971_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0___boxed(lean_object* v_candidate_2045_, lean_object* v_register_2046_, lean_object* v_as_2047_, lean_object* v_sz_2048_, lean_object* v_i_2049_, lean_object* v_b_2050_, lean_object* v___y_2051_){
_start:
{
uint8_t v_candidate_boxed_2052_; size_t v_sz_boxed_2053_; size_t v_i_boxed_2054_; lean_object* v_res_2055_; 
v_candidate_boxed_2052_ = lean_unbox(v_candidate_2045_);
v_sz_boxed_2053_ = lean_unbox_usize(v_sz_2048_);
lean_dec(v_sz_2048_);
v_i_boxed_2054_ = lean_unbox_usize(v_i_2049_);
lean_dec(v_i_2049_);
v_res_2055_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0(v_candidate_boxed_2052_, v_register_2046_, v_as_2047_, v_sz_boxed_2053_, v_i_boxed_2054_, v_b_2050_);
lean_dec_ref(v_as_2047_);
lean_dec(v_register_2046_);
return v_res_2055_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores(lean_object* v_inputs_2061_, lean_object* v_register_2062_, uint8_t v_candidate_2063_){
_start:
{
lean_object* v___x_2065_; size_t v_sz_2066_; size_t v___x_2067_; lean_object* v___x_2068_; 
v___x_2065_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___closed__1));
v_sz_2066_ = lean_array_size(v_inputs_2061_);
v___x_2067_ = ((size_t)0ULL);
v___x_2068_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores_spec__0(v_candidate_2063_, v_register_2062_, v_inputs_2061_, v_sz_2066_, v___x_2067_, v___x_2065_);
if (lean_obj_tag(v___x_2068_) == 0)
{
lean_object* v_a_2069_; lean_object* v___x_2071_; uint8_t v_isShared_2072_; uint8_t v_isSharedCheck_2085_; 
v_a_2069_ = lean_ctor_get(v___x_2068_, 0);
v_isSharedCheck_2085_ = !lean_is_exclusive(v___x_2068_);
if (v_isSharedCheck_2085_ == 0)
{
v___x_2071_ = v___x_2068_;
v_isShared_2072_ = v_isSharedCheck_2085_;
goto v_resetjp_2070_;
}
else
{
lean_inc(v_a_2069_);
lean_dec(v___x_2068_);
v___x_2071_ = lean_box(0);
v_isShared_2072_ = v_isSharedCheck_2085_;
goto v_resetjp_2070_;
}
v_resetjp_2070_:
{
lean_object* v_fst_2073_; lean_object* v_snd_2074_; lean_object* v___x_2076_; uint8_t v_isShared_2077_; uint8_t v_isSharedCheck_2084_; 
v_fst_2073_ = lean_ctor_get(v_a_2069_, 0);
v_snd_2074_ = lean_ctor_get(v_a_2069_, 1);
v_isSharedCheck_2084_ = !lean_is_exclusive(v_a_2069_);
if (v_isSharedCheck_2084_ == 0)
{
v___x_2076_ = v_a_2069_;
v_isShared_2077_ = v_isSharedCheck_2084_;
goto v_resetjp_2075_;
}
else
{
lean_inc(v_snd_2074_);
lean_inc(v_fst_2073_);
lean_dec(v_a_2069_);
v___x_2076_ = lean_box(0);
v_isShared_2077_ = v_isSharedCheck_2084_;
goto v_resetjp_2075_;
}
v_resetjp_2075_:
{
lean_object* v___x_2079_; 
if (v_isShared_2077_ == 0)
{
v___x_2079_ = v___x_2076_;
goto v_reusejp_2078_;
}
else
{
lean_object* v_reuseFailAlloc_2083_; 
v_reuseFailAlloc_2083_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2083_, 0, v_fst_2073_);
lean_ctor_set(v_reuseFailAlloc_2083_, 1, v_snd_2074_);
v___x_2079_ = v_reuseFailAlloc_2083_;
goto v_reusejp_2078_;
}
v_reusejp_2078_:
{
lean_object* v___x_2081_; 
if (v_isShared_2072_ == 0)
{
lean_ctor_set(v___x_2071_, 0, v___x_2079_);
v___x_2081_ = v___x_2071_;
goto v_reusejp_2080_;
}
else
{
lean_object* v_reuseFailAlloc_2082_; 
v_reuseFailAlloc_2082_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2082_, 0, v___x_2079_);
v___x_2081_ = v_reuseFailAlloc_2082_;
goto v_reusejp_2080_;
}
v_reusejp_2080_:
{
return v___x_2081_;
}
}
}
}
}
else
{
return v___x_2068_;
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores___boxed(lean_object* v_inputs_2086_, lean_object* v_register_2087_, lean_object* v_candidate_2088_, lean_object* v_a_2089_){
_start:
{
uint8_t v_candidate_boxed_2090_; lean_object* v_res_2091_; 
v_candidate_boxed_2090_ = lean_unbox(v_candidate_2088_);
v_res_2091_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores(v_inputs_2086_, v_register_2087_, v_candidate_boxed_2090_);
lean_dec(v_register_2087_);
lean_dec_ref(v_inputs_2086_);
return v_res_2091_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0(uint8_t v_candidate_2092_, lean_object* v_register_2093_, lean_object* v_as_2094_, size_t v_sz_2095_, size_t v_i_2096_, lean_object* v_b_2097_){
_start:
{
uint8_t v___y_2100_; uint8_t v___x_2106_; 
v___x_2106_ = lean_usize_dec_lt(v_i_2096_, v_sz_2095_);
if (v___x_2106_ == 0)
{
lean_object* v___x_2107_; 
v___x_2107_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2107_, 0, v_b_2097_);
return v___x_2107_;
}
else
{
lean_object* v_a_2108_; 
v_a_2108_ = lean_array_uget_borrowed(v_as_2094_, v_i_2096_);
if (v_candidate_2092_ == 0)
{
lean_object* v_word_2109_; uint8_t v___x_2110_; 
v_word_2109_ = lean_ctor_get(v_a_2108_, 1);
v___x_2110_ = lp_lean1090_Lean1090_Impl_cbScorePasses(v_register_2093_, v_word_2109_);
v___y_2100_ = v___x_2110_;
goto v___jp_2099_;
}
else
{
lean_object* v_word_2111_; uint8_t v___x_2112_; 
v_word_2111_ = lean_ctor_get(v_a_2108_, 1);
v___x_2112_ = lp_lean1090_Lean1090_Impl_commBCoreEligible(v_register_2093_, v_word_2111_);
v___y_2100_ = v___x_2112_;
goto v___jp_2099_;
}
}
v___jp_2099_:
{
lean_object* v___x_2101_; lean_object* v___x_2102_; size_t v___x_2103_; size_t v___x_2104_; 
v___x_2101_ = lean_box(v___y_2100_);
v___x_2102_ = lean_array_push(v_b_2097_, v___x_2101_);
v___x_2103_ = ((size_t)1ULL);
v___x_2104_ = lean_usize_add(v_i_2096_, v___x_2103_);
v_i_2096_ = v___x_2104_;
v_b_2097_ = v___x_2102_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0___boxed(lean_object* v_candidate_2113_, lean_object* v_register_2114_, lean_object* v_as_2115_, lean_object* v_sz_2116_, lean_object* v_i_2117_, lean_object* v_b_2118_, lean_object* v___y_2119_){
_start:
{
uint8_t v_candidate_boxed_2120_; size_t v_sz_boxed_2121_; size_t v_i_boxed_2122_; lean_object* v_res_2123_; 
v_candidate_boxed_2120_ = lean_unbox(v_candidate_2113_);
v_sz_boxed_2121_ = lean_unbox_usize(v_sz_2116_);
lean_dec(v_sz_2116_);
v_i_boxed_2122_ = lean_unbox_usize(v_i_2117_);
lean_dec(v_i_2117_);
v_res_2123_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0(v_candidate_boxed_2120_, v_register_2114_, v_as_2115_, v_sz_boxed_2121_, v_i_boxed_2122_, v_b_2118_);
lean_dec_ref(v_as_2115_);
lean_dec(v_register_2114_);
return v_res_2123_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores(lean_object* v_register_2124_, lean_object* v_inputs_2125_, uint8_t v_candidate_2126_){
_start:
{
lean_object* v___x_2128_; lean_object* v_output_2129_; lean_object* v___x_2130_; size_t v_sz_2131_; size_t v___x_2132_; lean_object* v___x_2133_; 
v___x_2128_ = lean_array_get_size(v_inputs_2125_);
v_output_2129_ = lean_mk_empty_array_with_capacity(v___x_2128_);
v___x_2130_ = lean_io_get_num_heartbeats();
v_sz_2131_ = lean_array_size(v_inputs_2125_);
v___x_2132_ = ((size_t)0ULL);
v___x_2133_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores_spec__0(v_candidate_2126_, v_register_2124_, v_inputs_2125_, v_sz_2131_, v___x_2132_, v_output_2129_);
if (lean_obj_tag(v___x_2133_) == 0)
{
lean_object* v_a_2134_; lean_object* v___x_2136_; uint8_t v_isShared_2137_; uint8_t v_isSharedCheck_2144_; 
v_a_2134_ = lean_ctor_get(v___x_2133_, 0);
v_isSharedCheck_2144_ = !lean_is_exclusive(v___x_2133_);
if (v_isSharedCheck_2144_ == 0)
{
v___x_2136_ = v___x_2133_;
v_isShared_2137_ = v_isSharedCheck_2144_;
goto v_resetjp_2135_;
}
else
{
lean_inc(v_a_2134_);
lean_dec(v___x_2133_);
v___x_2136_ = lean_box(0);
v_isShared_2137_ = v_isSharedCheck_2144_;
goto v_resetjp_2135_;
}
v_resetjp_2135_:
{
lean_object* v___x_2138_; lean_object* v___x_2139_; lean_object* v___x_2140_; lean_object* v___x_2142_; 
v___x_2138_ = lean_io_get_num_heartbeats();
v___x_2139_ = lean_nat_sub(v___x_2138_, v___x_2130_);
lean_dec(v___x_2130_);
lean_dec(v___x_2138_);
v___x_2140_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2140_, 0, v_a_2134_);
lean_ctor_set(v___x_2140_, 1, v___x_2139_);
if (v_isShared_2137_ == 0)
{
lean_ctor_set(v___x_2136_, 0, v___x_2140_);
v___x_2142_ = v___x_2136_;
goto v_reusejp_2141_;
}
else
{
lean_object* v_reuseFailAlloc_2143_; 
v_reuseFailAlloc_2143_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2143_, 0, v___x_2140_);
v___x_2142_ = v_reuseFailAlloc_2143_;
goto v_reusejp_2141_;
}
v_reusejp_2141_:
{
return v___x_2142_;
}
}
}
else
{
lean_object* v_a_2145_; lean_object* v___x_2147_; uint8_t v_isShared_2148_; uint8_t v_isSharedCheck_2152_; 
lean_dec(v___x_2130_);
v_a_2145_ = lean_ctor_get(v___x_2133_, 0);
v_isSharedCheck_2152_ = !lean_is_exclusive(v___x_2133_);
if (v_isSharedCheck_2152_ == 0)
{
v___x_2147_ = v___x_2133_;
v_isShared_2148_ = v_isSharedCheck_2152_;
goto v_resetjp_2146_;
}
else
{
lean_inc(v_a_2145_);
lean_dec(v___x_2133_);
v___x_2147_ = lean_box(0);
v_isShared_2148_ = v_isSharedCheck_2152_;
goto v_resetjp_2146_;
}
v_resetjp_2146_:
{
lean_object* v___x_2150_; 
if (v_isShared_2148_ == 0)
{
v___x_2150_ = v___x_2147_;
goto v_reusejp_2149_;
}
else
{
lean_object* v_reuseFailAlloc_2151_; 
v_reuseFailAlloc_2151_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2151_, 0, v_a_2145_);
v___x_2150_ = v_reuseFailAlloc_2151_;
goto v_reusejp_2149_;
}
v_reusejp_2149_:
{
return v___x_2150_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores___boxed(lean_object* v_register_2153_, lean_object* v_inputs_2154_, lean_object* v_candidate_2155_, lean_object* v_a_2156_){
_start:
{
uint8_t v_candidate_boxed_2157_; lean_object* v_res_2158_; 
v_candidate_boxed_2157_ = lean_unbox(v_candidate_2155_);
v_res_2158_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores(v_register_2153_, v_inputs_2154_, v_candidate_boxed_2157_);
lean_dec_ref(v_inputs_2154_);
lean_dec(v_register_2153_);
return v_res_2158_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(lean_object* v_fst_2165_, lean_object* v_fst_2166_, lean_object* v_range_2167_, lean_object* v_b_2168_, lean_object* v_i_2169_){
_start:
{
lean_object* v_stop_2171_; lean_object* v_step_2172_; uint8_t v___x_2173_; 
v_stop_2171_ = lean_ctor_get(v_range_2167_, 1);
v_step_2172_ = lean_ctor_get(v_range_2167_, 2);
v___x_2173_ = lean_nat_dec_lt(v_i_2169_, v_stop_2171_);
if (v___x_2173_ == 0)
{
lean_object* v___x_2174_; 
lean_dec(v_i_2169_);
v___x_2174_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2174_, 0, v_b_2168_);
return v___x_2174_;
}
else
{
lean_object* v___x_2175_; uint8_t v___x_2176_; 
v___x_2175_ = lean_array_get_size(v_fst_2165_);
v___x_2176_ = lean_nat_dec_lt(v_i_2169_, v___x_2175_);
if (v___x_2176_ == 0)
{
lean_object* v___x_2177_; lean_object* v___x_2178_; 
lean_dec(v_i_2169_);
lean_dec_ref(v_b_2168_);
v___x_2177_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__1));
v___x_2178_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2178_, 0, v___x_2177_);
return v___x_2178_;
}
else
{
lean_object* v_snd_2179_; lean_object* v_fst_2180_; lean_object* v___x_2182_; uint8_t v_isShared_2183_; uint8_t v_isSharedCheck_2232_; 
v_snd_2179_ = lean_ctor_get(v_b_2168_, 1);
v_fst_2180_ = lean_ctor_get(v_b_2168_, 0);
v_isSharedCheck_2232_ = !lean_is_exclusive(v_b_2168_);
if (v_isSharedCheck_2232_ == 0)
{
v___x_2182_ = v_b_2168_;
v_isShared_2183_ = v_isSharedCheck_2232_;
goto v_resetjp_2181_;
}
else
{
lean_inc(v_snd_2179_);
lean_inc(v_fst_2180_);
lean_dec(v_b_2168_);
v___x_2182_ = lean_box(0);
v_isShared_2183_ = v_isSharedCheck_2232_;
goto v_resetjp_2181_;
}
v_resetjp_2181_:
{
lean_object* v_fst_2184_; lean_object* v_snd_2185_; lean_object* v___x_2187_; uint8_t v_isShared_2188_; uint8_t v_isSharedCheck_2231_; 
v_fst_2184_ = lean_ctor_get(v_snd_2179_, 0);
v_snd_2185_ = lean_ctor_get(v_snd_2179_, 1);
v_isSharedCheck_2231_ = !lean_is_exclusive(v_snd_2179_);
if (v_isSharedCheck_2231_ == 0)
{
v___x_2187_ = v_snd_2179_;
v_isShared_2188_ = v_isSharedCheck_2231_;
goto v_resetjp_2186_;
}
else
{
lean_inc(v_snd_2185_);
lean_inc(v_fst_2184_);
lean_dec(v_snd_2179_);
v___x_2187_ = lean_box(0);
v_isShared_2188_ = v_isSharedCheck_2231_;
goto v_resetjp_2186_;
}
v_resetjp_2186_:
{
lean_object* v___x_2189_; lean_object* v_df_2190_; lean_object* v_word_2191_; lean_object* v_outerAltitude_2192_; lean_object* v___x_2193_; lean_object* v___x_2194_; lean_object* v___x_2195_; lean_object* v___x_2196_; lean_object* v___x_2197_; lean_object* v___x_2198_; lean_object* v___x_2199_; lean_object* v___x_2200_; lean_object* v___x_2201_; lean_object* v___x_2202_; lean_object* v___x_2203_; lean_object* v___x_2204_; lean_object* v___x_2205_; lean_object* v___y_2207_; uint8_t v___x_2228_; 
v___x_2189_ = lean_array_fget_borrowed(v_fst_2165_, v_i_2169_);
v_df_2190_ = lean_ctor_get(v___x_2189_, 0);
v_word_2191_ = lean_ctor_get(v___x_2189_, 1);
v_outerAltitude_2192_ = lean_ctor_get(v___x_2189_, 2);
lean_inc(v_df_2190_);
v___x_2193_ = l_Nat_reprFast(v_df_2190_);
v___x_2194_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__2));
v___x_2195_ = lean_string_append(v___x_2193_, v___x_2194_);
v___x_2196_ = lean_unsigned_to_nat(0u);
lean_inc(v_outerAltitude_2192_);
v___x_2197_ = lp_lean1090_Option_repr___at___00Lean1090_Spec_instReprCommBThreat_repr_spec__0(v_outerAltitude_2192_, v___x_2196_);
v___x_2198_ = lean_unsigned_to_nat(120u);
v___x_2199_ = l_Std_Format_pretty(v___x_2197_, v___x_2198_, v___x_2196_, v___x_2196_);
v___x_2200_ = lean_string_append(v___x_2195_, v___x_2199_);
lean_dec_ref(v___x_2199_);
v___x_2201_ = lean_string_append(v___x_2200_, v___x_2194_);
lean_inc(v_word_2191_);
v___x_2202_ = l_Nat_reprFast(v_word_2191_);
v___x_2203_ = lean_string_append(v___x_2201_, v___x_2202_);
lean_dec_ref(v___x_2202_);
v___x_2204_ = lean_string_append(v___x_2203_, v___x_2194_);
v___x_2205_ = lean_array_fget_borrowed(v_fst_2166_, v_i_2169_);
v___x_2228_ = lean_unbox(v___x_2205_);
if (v___x_2228_ == 0)
{
lean_object* v___x_2229_; 
v___x_2229_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__3));
v___y_2207_ = v___x_2229_;
goto v___jp_2206_;
}
else
{
lean_object* v___x_2230_; 
v___x_2230_ = ((lean_object*)(l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___closed__4));
v___y_2207_ = v___x_2230_;
goto v___jp_2206_;
}
v___jp_2206_:
{
lean_object* v___x_2208_; lean_object* v___x_2209_; lean_object* v___x_2210_; lean_object* v___x_2211_; lean_object* v___x_2212_; uint8_t v___x_2213_; lean_object* v___x_2214_; lean_object* v___x_2215_; lean_object* v___x_2216_; uint8_t v___x_2217_; lean_object* v___x_2218_; lean_object* v___x_2219_; lean_object* v___x_2221_; 
v___x_2208_ = lean_string_append(v___x_2204_, v___y_2207_);
v___x_2209_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs___closed__0));
v___x_2210_ = lean_string_append(v___x_2208_, v___x_2209_);
v___x_2211_ = lean_string_to_utf8(v___x_2210_);
lean_dec_ref(v___x_2210_);
v___x_2212_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_extend(v_fst_2180_, v___x_2211_);
v___x_2213_ = lean_unbox(v___x_2205_);
v___x_2214_ = l_Bool_toNat(v___x_2213_);
v___x_2215_ = lean_nat_add(v_fst_2184_, v___x_2214_);
lean_dec(v___x_2214_);
lean_dec(v_fst_2184_);
v___x_2216_ = lean_unsigned_to_nat(20u);
v___x_2217_ = lean_nat_dec_eq(v_df_2190_, v___x_2216_);
v___x_2218_ = l_Bool_toNat(v___x_2217_);
v___x_2219_ = lean_nat_add(v_snd_2185_, v___x_2218_);
lean_dec(v___x_2218_);
lean_dec(v_snd_2185_);
if (v_isShared_2188_ == 0)
{
lean_ctor_set(v___x_2187_, 1, v___x_2219_);
lean_ctor_set(v___x_2187_, 0, v___x_2215_);
v___x_2221_ = v___x_2187_;
goto v_reusejp_2220_;
}
else
{
lean_object* v_reuseFailAlloc_2227_; 
v_reuseFailAlloc_2227_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2227_, 0, v___x_2215_);
lean_ctor_set(v_reuseFailAlloc_2227_, 1, v___x_2219_);
v___x_2221_ = v_reuseFailAlloc_2227_;
goto v_reusejp_2220_;
}
v_reusejp_2220_:
{
lean_object* v___x_2223_; 
if (v_isShared_2183_ == 0)
{
lean_ctor_set(v___x_2182_, 1, v___x_2221_);
lean_ctor_set(v___x_2182_, 0, v___x_2212_);
v___x_2223_ = v___x_2182_;
goto v_reusejp_2222_;
}
else
{
lean_object* v_reuseFailAlloc_2226_; 
v_reuseFailAlloc_2226_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2226_, 0, v___x_2212_);
lean_ctor_set(v_reuseFailAlloc_2226_, 1, v___x_2221_);
v___x_2223_ = v_reuseFailAlloc_2226_;
goto v_reusejp_2222_;
}
v_reusejp_2222_:
{
lean_object* v___x_2224_; 
v___x_2224_ = lean_nat_add(v_i_2169_, v_step_2172_);
lean_dec(v_i_2169_);
v_b_2168_ = v___x_2223_;
v_i_2169_ = v___x_2224_;
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
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg___boxed(lean_object* v_fst_2233_, lean_object* v_fst_2234_, lean_object* v_range_2235_, lean_object* v_b_2236_, lean_object* v_i_2237_, lean_object* v___y_2238_){
_start:
{
lean_object* v_res_2239_; 
v_res_2239_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(v_fst_2233_, v_fst_2234_, v_range_2235_, v_b_2236_, v_i_2237_);
lean_dec_ref(v_range_2235_);
lean_dec_ref(v_fst_2234_);
lean_dec_ref(v_fst_2233_);
return v_res_2239_;
}
}
static lean_object* _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__15(void){
_start:
{
lean_object* v___x_2262_; lean_object* v___x_2263_; 
v___x_2262_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__14));
v___x_2263_ = lean_string_utf8_byte_size(v___x_2262_);
return v___x_2263_;
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode(lean_object* v_mode_2264_, lean_object* v_register_2265_, lean_object* v_inputs_2266_, uint8_t v_wait_2267_){
_start:
{
lean_object* v___y_2270_; lean_object* v___y_2271_; lean_object* v___y_2272_; uint8_t v___y_2273_; lean_object* v___y_2274_; lean_object* v___y_2275_; lean_object* v___y_2276_; lean_object* v___y_2277_; lean_object* v___y_2278_; lean_object* v___y_2279_; lean_object* v___y_2280_; uint8_t v___y_2426_; lean_object* v___x_2463_; lean_object* v___x_2464_; lean_object* v___x_2465_; uint8_t v___x_2466_; 
v___x_2463_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__14));
v___x_2464_ = lean_string_utf8_byte_size(v_mode_2264_);
v___x_2465_ = lean_obj_once(&l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__15, &l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__15_once, _init_l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__15);
v___x_2466_ = lean_nat_dec_le(v___x_2465_, v___x_2464_);
if (v___x_2466_ == 0)
{
v___y_2426_ = v___x_2466_;
goto v___jp_2425_;
}
else
{
lean_object* v___x_2467_; uint8_t v___x_2468_; 
v___x_2467_ = lean_unsigned_to_nat(0u);
v___x_2468_ = lean_string_memcmp(v_mode_2264_, v___x_2463_, v___x_2467_, v___x_2467_, v___x_2465_);
v___y_2426_ = v___x_2468_;
goto v___jp_2425_;
}
v___jp_2269_:
{
lean_object* v___x_2281_; lean_object* v___x_2282_; lean_object* v___x_2283_; lean_object* v___x_2284_; lean_object* v___x_2285_; lean_object* v___x_2286_; lean_object* v___x_2287_; lean_object* v___x_2288_; lean_object* v___x_2289_; lean_object* v___x_2290_; lean_object* v___x_2291_; 
lean_inc_ref(v___y_2280_);
v___x_2281_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_2281_, 0, v___y_2280_);
lean_inc_ref(v___y_2279_);
v___x_2282_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2282_, 0, v___y_2279_);
lean_ctor_set(v___x_2282_, 1, v___x_2281_);
v___x_2283_ = lean_box(0);
lean_inc_ref(v___x_2282_);
v___x_2284_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2284_, 0, v___x_2282_);
lean_ctor_set(v___x_2284_, 1, v___x_2283_);
lean_inc_ref(v___y_2274_);
v___x_2285_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2285_, 0, v___y_2274_);
lean_ctor_set(v___x_2285_, 1, v___x_2284_);
v___x_2286_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2286_, 0, v___y_2275_);
lean_ctor_set(v___x_2286_, 1, v___x_2285_);
v___x_2287_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2287_, 0, v___y_2271_);
lean_ctor_set(v___x_2287_, 1, v___x_2286_);
lean_inc_ref(v___y_2278_);
v___x_2288_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2288_, 0, v___y_2278_);
lean_ctor_set(v___x_2288_, 1, v___x_2287_);
lean_inc_ref(v___y_2270_);
v___x_2289_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2289_, 0, v___y_2270_);
lean_ctor_set(v___x_2289_, 1, v___x_2288_);
v___x_2290_ = l_Lean_Json_mkObj(v___x_2289_);
lean_dec_ref_known(v___x_2289_, 2);
v___x_2291_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_2290_);
if (lean_obj_tag(v___x_2291_) == 0)
{
lean_object* v___x_2293_; uint8_t v_isShared_2294_; uint8_t v_isSharedCheck_2423_; 
v_isSharedCheck_2423_ = !lean_is_exclusive(v___x_2291_);
if (v_isSharedCheck_2423_ == 0)
{
lean_object* v_unused_2424_; 
v_unused_2424_ = lean_ctor_get(v___x_2291_, 0);
lean_dec(v_unused_2424_);
v___x_2293_ = v___x_2291_;
v_isShared_2294_ = v_isSharedCheck_2423_;
goto v_resetjp_2292_;
}
else
{
lean_dec(v___x_2291_);
v___x_2293_ = lean_box(0);
v_isShared_2294_ = v_isSharedCheck_2423_;
goto v_resetjp_2292_;
}
v_resetjp_2292_:
{
lean_object* v___x_2295_; lean_object* v___x_2296_; 
v___x_2295_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__11));
v___x_2296_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_wait_2267_, v___x_2295_);
if (lean_obj_tag(v___x_2296_) == 0)
{
lean_object* v___x_2298_; uint8_t v_isShared_2299_; uint8_t v_isSharedCheck_2421_; 
v_isSharedCheck_2421_ = !lean_is_exclusive(v___x_2296_);
if (v_isSharedCheck_2421_ == 0)
{
lean_object* v_unused_2422_; 
v_unused_2422_ = lean_ctor_get(v___x_2296_, 0);
lean_dec(v_unused_2422_);
v___x_2298_ = v___x_2296_;
v_isShared_2299_ = v_isSharedCheck_2421_;
goto v_resetjp_2297_;
}
else
{
lean_dec(v___x_2296_);
v___x_2298_ = lean_box(0);
v_isShared_2299_ = v_isSharedCheck_2421_;
goto v_resetjp_2297_;
}
v_resetjp_2297_:
{
lean_object* v___x_2300_; 
v___x_2300_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_runScores(v_register_2265_, v___y_2277_, v___y_2273_);
if (lean_obj_tag(v___x_2300_) == 0)
{
lean_object* v_a_2301_; lean_object* v_fst_2302_; lean_object* v_snd_2303_; lean_object* v___x_2305_; uint8_t v_isShared_2306_; uint8_t v_isSharedCheck_2412_; 
v_a_2301_ = lean_ctor_get(v___x_2300_, 0);
lean_inc(v_a_2301_);
lean_dec_ref_known(v___x_2300_, 1);
v_fst_2302_ = lean_ctor_get(v_a_2301_, 0);
v_snd_2303_ = lean_ctor_get(v_a_2301_, 1);
v_isSharedCheck_2412_ = !lean_is_exclusive(v_a_2301_);
if (v_isSharedCheck_2412_ == 0)
{
v___x_2305_ = v_a_2301_;
v_isShared_2306_ = v_isSharedCheck_2412_;
goto v_resetjp_2304_;
}
else
{
lean_inc(v_snd_2303_);
lean_inc(v_fst_2302_);
lean_dec(v_a_2301_);
v___x_2305_ = lean_box(0);
v_isShared_2306_ = v_isSharedCheck_2412_;
goto v_resetjp_2304_;
}
v_resetjp_2304_:
{
lean_object* v___x_2307_; lean_object* v___x_2309_; 
v___x_2307_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__13));
lean_inc_ref(v___y_2276_);
if (v_isShared_2306_ == 0)
{
lean_ctor_set(v___x_2305_, 1, v___x_2307_);
lean_ctor_set(v___x_2305_, 0, v___y_2276_);
v___x_2309_ = v___x_2305_;
goto v_reusejp_2308_;
}
else
{
lean_object* v_reuseFailAlloc_2411_; 
v_reuseFailAlloc_2411_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2411_, 0, v___y_2276_);
lean_ctor_set(v_reuseFailAlloc_2411_, 1, v___x_2307_);
v___x_2309_ = v_reuseFailAlloc_2411_;
goto v_reusejp_2308_;
}
v_reusejp_2308_:
{
lean_object* v___x_2310_; lean_object* v___x_2311_; lean_object* v___x_2312_; lean_object* v___x_2314_; 
v___x_2310_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__15));
v___x_2311_ = lean_array_get_size(v_fst_2302_);
v___x_2312_ = l_Lean_JsonNumber_fromNat(v___x_2311_);
if (v_isShared_2299_ == 0)
{
lean_ctor_set_tag(v___x_2298_, 2);
lean_ctor_set(v___x_2298_, 0, v___x_2312_);
v___x_2314_ = v___x_2298_;
goto v_reusejp_2313_;
}
else
{
lean_object* v_reuseFailAlloc_2410_; 
v_reuseFailAlloc_2410_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2410_, 0, v___x_2312_);
v___x_2314_ = v_reuseFailAlloc_2410_;
goto v_reusejp_2313_;
}
v_reusejp_2313_:
{
lean_object* v___x_2315_; lean_object* v___x_2316_; lean_object* v___x_2317_; lean_object* v___x_2319_; 
v___x_2315_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2315_, 0, v___x_2310_);
lean_ctor_set(v___x_2315_, 1, v___x_2314_);
v___x_2316_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__16));
v___x_2317_ = l_Lean_JsonNumber_fromNat(v_snd_2303_);
if (v_isShared_2294_ == 0)
{
lean_ctor_set_tag(v___x_2293_, 2);
lean_ctor_set(v___x_2293_, 0, v___x_2317_);
v___x_2319_ = v___x_2293_;
goto v_reusejp_2318_;
}
else
{
lean_object* v_reuseFailAlloc_2409_; 
v_reuseFailAlloc_2409_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2409_, 0, v___x_2317_);
v___x_2319_ = v_reuseFailAlloc_2409_;
goto v_reusejp_2318_;
}
v_reusejp_2318_:
{
lean_object* v___x_2320_; lean_object* v___x_2321_; lean_object* v___x_2322_; lean_object* v___x_2323_; lean_object* v___x_2324_; lean_object* v___x_2325_; lean_object* v___x_2326_; 
v___x_2320_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2320_, 0, v___x_2316_);
lean_ctor_set(v___x_2320_, 1, v___x_2319_);
v___x_2321_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2321_, 0, v___x_2320_);
lean_ctor_set(v___x_2321_, 1, v___x_2283_);
lean_inc_ref(v___x_2321_);
v___x_2322_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2322_, 0, v___x_2315_);
lean_ctor_set(v___x_2322_, 1, v___x_2321_);
lean_inc_ref(v___y_2278_);
v___x_2323_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2323_, 0, v___y_2278_);
lean_ctor_set(v___x_2323_, 1, v___x_2322_);
v___x_2324_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2324_, 0, v___x_2309_);
lean_ctor_set(v___x_2324_, 1, v___x_2323_);
v___x_2325_ = l_Lean_Json_mkObj(v___x_2324_);
lean_dec_ref_known(v___x_2324_, 2);
v___x_2326_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_2325_);
if (lean_obj_tag(v___x_2326_) == 0)
{
lean_object* v___x_2328_; uint8_t v_isShared_2329_; uint8_t v_isSharedCheck_2407_; 
v_isSharedCheck_2407_ = !lean_is_exclusive(v___x_2326_);
if (v_isSharedCheck_2407_ == 0)
{
lean_object* v_unused_2408_; 
v_unused_2408_ = lean_ctor_get(v___x_2326_, 0);
lean_dec(v_unused_2408_);
v___x_2328_ = v___x_2326_;
v_isShared_2329_ = v_isSharedCheck_2407_;
goto v_resetjp_2327_;
}
else
{
lean_dec(v___x_2326_);
v___x_2328_ = lean_box(0);
v_isShared_2329_ = v_isSharedCheck_2407_;
goto v_resetjp_2327_;
}
v_resetjp_2327_:
{
lean_object* v___x_2330_; lean_object* v___x_2331_; 
v___x_2330_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__17));
v___x_2331_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_command(v_wait_2267_, v___x_2330_);
if (lean_obj_tag(v___x_2331_) == 0)
{
lean_object* v___x_2333_; uint8_t v_isShared_2334_; uint8_t v_isSharedCheck_2405_; 
v_isSharedCheck_2405_ = !lean_is_exclusive(v___x_2331_);
if (v_isSharedCheck_2405_ == 0)
{
lean_object* v_unused_2406_; 
v_unused_2406_ = lean_ctor_get(v___x_2331_, 0);
lean_dec(v_unused_2406_);
v___x_2333_ = v___x_2331_;
v_isShared_2334_ = v_isSharedCheck_2405_;
goto v_resetjp_2332_;
}
else
{
lean_dec(v___x_2331_);
v___x_2333_ = lean_box(0);
v_isShared_2334_ = v_isSharedCheck_2405_;
goto v_resetjp_2332_;
}
v_resetjp_2332_:
{
uint8_t v___x_2335_; 
v___x_2335_ = lean_nat_dec_eq(v___x_2311_, v___y_2272_);
if (v___x_2335_ == 0)
{
lean_object* v___x_2336_; lean_object* v___x_2338_; 
lean_del_object(v___x_2328_);
lean_dec_ref_known(v___x_2321_, 2);
lean_dec(v_fst_2302_);
lean_dec_ref_known(v___x_2282_, 2);
lean_dec_ref(v___y_2278_);
lean_dec_ref(v___y_2277_);
lean_dec(v___y_2272_);
lean_dec(v_register_2265_);
v___x_2336_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__1));
if (v_isShared_2334_ == 0)
{
lean_ctor_set_tag(v___x_2333_, 1);
lean_ctor_set(v___x_2333_, 0, v___x_2336_);
v___x_2338_ = v___x_2333_;
goto v_reusejp_2337_;
}
else
{
lean_object* v_reuseFailAlloc_2339_; 
v_reuseFailAlloc_2339_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2339_, 0, v___x_2336_);
v___x_2338_ = v_reuseFailAlloc_2339_;
goto v_reusejp_2337_;
}
v_reusejp_2337_:
{
return v___x_2338_;
}
}
else
{
lean_object* v___x_2340_; lean_object* v___x_2341_; lean_object* v___x_2342_; lean_object* v___x_2343_; lean_object* v___x_2344_; 
lean_del_object(v___x_2333_);
v___x_2340_ = lean_unsigned_to_nat(0u);
v___x_2341_ = lean_unsigned_to_nat(1u);
v___x_2342_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_2342_, 0, v___x_2340_);
lean_ctor_set(v___x_2342_, 1, v___x_2311_);
lean_ctor_set(v___x_2342_, 2, v___x_2341_);
v___x_2343_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__3));
v___x_2344_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(v___y_2277_, v_fst_2302_, v___x_2342_, v___x_2343_, v___x_2340_);
lean_dec_ref_known(v___x_2342_, 3);
lean_dec(v_fst_2302_);
lean_dec_ref(v___y_2277_);
if (lean_obj_tag(v___x_2344_) == 0)
{
lean_object* v_a_2345_; lean_object* v_snd_2346_; lean_object* v_fst_2347_; lean_object* v___x_2349_; uint8_t v_isShared_2350_; uint8_t v_isSharedCheck_2396_; 
v_a_2345_ = lean_ctor_get(v___x_2344_, 0);
lean_inc(v_a_2345_);
lean_dec_ref_known(v___x_2344_, 1);
v_snd_2346_ = lean_ctor_get(v_a_2345_, 1);
v_fst_2347_ = lean_ctor_get(v_a_2345_, 0);
v_isSharedCheck_2396_ = !lean_is_exclusive(v_a_2345_);
if (v_isSharedCheck_2396_ == 0)
{
v___x_2349_ = v_a_2345_;
v_isShared_2350_ = v_isSharedCheck_2396_;
goto v_resetjp_2348_;
}
else
{
lean_inc(v_snd_2346_);
lean_inc(v_fst_2347_);
lean_dec(v_a_2345_);
v___x_2349_ = lean_box(0);
v_isShared_2350_ = v_isSharedCheck_2396_;
goto v_resetjp_2348_;
}
v_resetjp_2348_:
{
lean_object* v_fst_2351_; lean_object* v_snd_2352_; lean_object* v___x_2354_; uint8_t v_isShared_2355_; uint8_t v_isSharedCheck_2395_; 
v_fst_2351_ = lean_ctor_get(v_snd_2346_, 0);
v_snd_2352_ = lean_ctor_get(v_snd_2346_, 1);
v_isSharedCheck_2395_ = !lean_is_exclusive(v_snd_2346_);
if (v_isSharedCheck_2395_ == 0)
{
v___x_2354_ = v_snd_2346_;
v_isShared_2355_ = v_isSharedCheck_2395_;
goto v_resetjp_2353_;
}
else
{
lean_inc(v_snd_2352_);
lean_inc(v_fst_2351_);
lean_dec(v_snd_2346_);
v___x_2354_ = lean_box(0);
v_isShared_2355_ = v_isSharedCheck_2395_;
goto v_resetjp_2353_;
}
v_resetjp_2353_:
{
lean_object* v___x_2356_; lean_object* v___x_2358_; 
v___x_2356_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__19));
lean_inc_ref(v___y_2276_);
if (v_isShared_2355_ == 0)
{
lean_ctor_set(v___x_2354_, 1, v___x_2356_);
lean_ctor_set(v___x_2354_, 0, v___y_2276_);
v___x_2358_ = v___x_2354_;
goto v_reusejp_2357_;
}
else
{
lean_object* v_reuseFailAlloc_2394_; 
v_reuseFailAlloc_2394_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2394_, 0, v___y_2276_);
lean_ctor_set(v_reuseFailAlloc_2394_, 1, v___x_2356_);
v___x_2358_ = v_reuseFailAlloc_2394_;
goto v_reusejp_2357_;
}
v_reusejp_2357_:
{
lean_object* v___x_2359_; lean_object* v___x_2360_; lean_object* v___x_2362_; 
v___x_2359_ = ((lean_object*)(l_List_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_census_spec__5___redArg___closed__0));
v___x_2360_ = l_Lean_JsonNumber_fromNat(v_register_2265_);
if (v_isShared_2329_ == 0)
{
lean_ctor_set_tag(v___x_2328_, 2);
lean_ctor_set(v___x_2328_, 0, v___x_2360_);
v___x_2362_ = v___x_2328_;
goto v_reusejp_2361_;
}
else
{
lean_object* v_reuseFailAlloc_2393_; 
v_reuseFailAlloc_2393_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2393_, 0, v___x_2360_);
v___x_2362_ = v_reuseFailAlloc_2393_;
goto v_reusejp_2361_;
}
v_reusejp_2361_:
{
lean_object* v___x_2364_; 
if (v_isShared_2350_ == 0)
{
lean_ctor_set(v___x_2349_, 1, v___x_2362_);
lean_ctor_set(v___x_2349_, 0, v___x_2359_);
v___x_2364_ = v___x_2349_;
goto v_reusejp_2363_;
}
else
{
lean_object* v_reuseFailAlloc_2392_; 
v_reuseFailAlloc_2392_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2392_, 0, v___x_2359_);
lean_ctor_set(v_reuseFailAlloc_2392_, 1, v___x_2362_);
v___x_2364_ = v_reuseFailAlloc_2392_;
goto v_reusejp_2363_;
}
v_reusejp_2363_:
{
lean_object* v___x_2365_; lean_object* v___x_2366_; lean_object* v___x_2367_; lean_object* v___x_2368_; lean_object* v___x_2369_; lean_object* v___x_2370_; lean_object* v___x_2371_; lean_object* v___x_2372_; lean_object* v___x_2373_; lean_object* v___x_2374_; lean_object* v___x_2375_; lean_object* v___x_2376_; lean_object* v___x_2377_; lean_object* v___x_2378_; lean_object* v___x_2379_; lean_object* v___x_2380_; lean_object* v___x_2381_; lean_object* v___x_2382_; lean_object* v___x_2383_; lean_object* v___x_2384_; lean_object* v___x_2385_; lean_object* v___x_2386_; lean_object* v___x_2387_; lean_object* v___x_2388_; lean_object* v___x_2389_; lean_object* v___x_2390_; lean_object* v___x_2391_; 
v___x_2365_ = ((lean_object*)(l_List_mapTR_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode_spec__0___closed__0));
v___x_2366_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_digestJson(v_fst_2347_);
v___x_2367_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2367_, 0, v___x_2365_);
lean_ctor_set(v___x_2367_, 1, v___x_2366_);
v___x_2368_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__4));
v___x_2369_ = l_Lean_JsonNumber_fromNat(v_fst_2351_);
v___x_2370_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2370_, 0, v___x_2369_);
v___x_2371_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2371_, 0, v___x_2368_);
lean_ctor_set(v___x_2371_, 1, v___x_2370_);
v___x_2372_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__5));
lean_inc(v_snd_2352_);
v___x_2373_ = l_Lean_JsonNumber_fromNat(v_snd_2352_);
v___x_2374_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2374_, 0, v___x_2373_);
v___x_2375_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2375_, 0, v___x_2372_);
lean_ctor_set(v___x_2375_, 1, v___x_2374_);
v___x_2376_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__6));
v___x_2377_ = lean_nat_sub(v___y_2272_, v_snd_2352_);
lean_dec(v_snd_2352_);
lean_dec(v___y_2272_);
v___x_2378_ = l_Lean_JsonNumber_fromNat(v___x_2377_);
v___x_2379_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2379_, 0, v___x_2378_);
v___x_2380_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2380_, 0, v___x_2376_);
lean_ctor_set(v___x_2380_, 1, v___x_2379_);
v___x_2381_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2381_, 0, v___x_2380_);
lean_ctor_set(v___x_2381_, 1, v___x_2321_);
v___x_2382_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2382_, 0, v___x_2375_);
lean_ctor_set(v___x_2382_, 1, v___x_2381_);
v___x_2383_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2383_, 0, v___x_2371_);
lean_ctor_set(v___x_2383_, 1, v___x_2382_);
v___x_2384_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2384_, 0, v___x_2367_);
lean_ctor_set(v___x_2384_, 1, v___x_2383_);
v___x_2385_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2385_, 0, v___x_2282_);
lean_ctor_set(v___x_2385_, 1, v___x_2384_);
lean_inc_ref(v___y_2274_);
v___x_2386_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2386_, 0, v___y_2274_);
lean_ctor_set(v___x_2386_, 1, v___x_2385_);
v___x_2387_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2387_, 0, v___x_2364_);
lean_ctor_set(v___x_2387_, 1, v___x_2386_);
v___x_2388_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2388_, 0, v___y_2278_);
lean_ctor_set(v___x_2388_, 1, v___x_2387_);
v___x_2389_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2389_, 0, v___x_2358_);
lean_ctor_set(v___x_2389_, 1, v___x_2388_);
v___x_2390_ = l_Lean_Json_mkObj(v___x_2389_);
lean_dec_ref_known(v___x_2389_, 2);
v___x_2391_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_emit(v___x_2390_);
return v___x_2391_;
}
}
}
}
}
}
else
{
lean_object* v_a_2397_; lean_object* v___x_2399_; uint8_t v_isShared_2400_; uint8_t v_isSharedCheck_2404_; 
lean_del_object(v___x_2328_);
lean_dec_ref_known(v___x_2321_, 2);
lean_dec_ref_known(v___x_2282_, 2);
lean_dec_ref(v___y_2278_);
lean_dec(v___y_2272_);
lean_dec(v_register_2265_);
v_a_2397_ = lean_ctor_get(v___x_2344_, 0);
v_isSharedCheck_2404_ = !lean_is_exclusive(v___x_2344_);
if (v_isSharedCheck_2404_ == 0)
{
v___x_2399_ = v___x_2344_;
v_isShared_2400_ = v_isSharedCheck_2404_;
goto v_resetjp_2398_;
}
else
{
lean_inc(v_a_2397_);
lean_dec(v___x_2344_);
v___x_2399_ = lean_box(0);
v_isShared_2400_ = v_isSharedCheck_2404_;
goto v_resetjp_2398_;
}
v_resetjp_2398_:
{
lean_object* v___x_2402_; 
if (v_isShared_2400_ == 0)
{
v___x_2402_ = v___x_2399_;
goto v_reusejp_2401_;
}
else
{
lean_object* v_reuseFailAlloc_2403_; 
v_reuseFailAlloc_2403_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2403_, 0, v_a_2397_);
v___x_2402_ = v_reuseFailAlloc_2403_;
goto v_reusejp_2401_;
}
v_reusejp_2401_:
{
return v___x_2402_;
}
}
}
}
}
}
else
{
lean_del_object(v___x_2328_);
lean_dec_ref_known(v___x_2321_, 2);
lean_dec(v_fst_2302_);
lean_dec_ref_known(v___x_2282_, 2);
lean_dec_ref(v___y_2278_);
lean_dec_ref(v___y_2277_);
lean_dec(v___y_2272_);
lean_dec(v_register_2265_);
return v___x_2331_;
}
}
}
else
{
lean_dec_ref_known(v___x_2321_, 2);
lean_dec(v_fst_2302_);
lean_dec_ref_known(v___x_2282_, 2);
lean_dec_ref(v___y_2278_);
lean_dec_ref(v___y_2277_);
lean_dec(v___y_2272_);
lean_dec(v_register_2265_);
return v___x_2326_;
}
}
}
}
}
}
else
{
lean_object* v_a_2413_; lean_object* v___x_2415_; uint8_t v_isShared_2416_; uint8_t v_isSharedCheck_2420_; 
lean_del_object(v___x_2298_);
lean_del_object(v___x_2293_);
lean_dec_ref_known(v___x_2282_, 2);
lean_dec_ref(v___y_2278_);
lean_dec_ref(v___y_2277_);
lean_dec(v___y_2272_);
lean_dec(v_register_2265_);
v_a_2413_ = lean_ctor_get(v___x_2300_, 0);
v_isSharedCheck_2420_ = !lean_is_exclusive(v___x_2300_);
if (v_isSharedCheck_2420_ == 0)
{
v___x_2415_ = v___x_2300_;
v_isShared_2416_ = v_isSharedCheck_2420_;
goto v_resetjp_2414_;
}
else
{
lean_inc(v_a_2413_);
lean_dec(v___x_2300_);
v___x_2415_ = lean_box(0);
v_isShared_2416_ = v_isSharedCheck_2420_;
goto v_resetjp_2414_;
}
v_resetjp_2414_:
{
lean_object* v___x_2418_; 
if (v_isShared_2416_ == 0)
{
v___x_2418_ = v___x_2415_;
goto v_reusejp_2417_;
}
else
{
lean_object* v_reuseFailAlloc_2419_; 
v_reuseFailAlloc_2419_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2419_, 0, v_a_2413_);
v___x_2418_ = v_reuseFailAlloc_2419_;
goto v_reusejp_2417_;
}
v_reusejp_2417_:
{
return v___x_2418_;
}
}
}
}
}
else
{
lean_del_object(v___x_2293_);
lean_dec_ref_known(v___x_2282_, 2);
lean_dec_ref(v___y_2278_);
lean_dec_ref(v___y_2277_);
lean_dec(v___y_2272_);
lean_dec(v_register_2265_);
return v___x_2296_;
}
}
}
else
{
lean_dec_ref_known(v___x_2282_, 2);
lean_dec_ref(v___y_2278_);
lean_dec_ref(v___y_2277_);
lean_dec(v___y_2272_);
lean_dec(v_register_2265_);
return v___x_2291_;
}
}
v___jp_2425_:
{
lean_object* v___x_2427_; 
v___x_2427_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_prepareScores(v_inputs_2266_, v_register_2265_, v___y_2426_);
if (lean_obj_tag(v___x_2427_) == 0)
{
lean_object* v_a_2428_; lean_object* v_fst_2429_; lean_object* v_snd_2430_; lean_object* v___x_2432_; uint8_t v_isShared_2433_; uint8_t v_isSharedCheck_2454_; 
v_a_2428_ = lean_ctor_get(v___x_2427_, 0);
lean_inc(v_a_2428_);
lean_dec_ref_known(v___x_2427_, 1);
v_fst_2429_ = lean_ctor_get(v_a_2428_, 0);
v_snd_2430_ = lean_ctor_get(v_a_2428_, 1);
v_isSharedCheck_2454_ = !lean_is_exclusive(v_a_2428_);
if (v_isSharedCheck_2454_ == 0)
{
v___x_2432_ = v_a_2428_;
v_isShared_2433_ = v_isSharedCheck_2454_;
goto v_resetjp_2431_;
}
else
{
lean_inc(v_snd_2430_);
lean_inc(v_fst_2429_);
lean_dec(v_a_2428_);
v___x_2432_ = lean_box(0);
v_isShared_2433_ = v_isSharedCheck_2454_;
goto v_resetjp_2431_;
}
v_resetjp_2431_:
{
lean_object* v___x_2434_; lean_object* v___x_2435_; lean_object* v___x_2436_; lean_object* v___x_2437_; lean_object* v___x_2439_; 
v___x_2434_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__0));
v___x_2435_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__3));
v___x_2436_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__4));
v___x_2437_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_2437_, 0, v_mode_2264_);
if (v_isShared_2433_ == 0)
{
lean_ctor_set(v___x_2432_, 1, v___x_2437_);
lean_ctor_set(v___x_2432_, 0, v___x_2436_);
v___x_2439_ = v___x_2432_;
goto v_reusejp_2438_;
}
else
{
lean_object* v_reuseFailAlloc_2453_; 
v_reuseFailAlloc_2453_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2453_, 0, v___x_2436_);
lean_ctor_set(v_reuseFailAlloc_2453_, 1, v___x_2437_);
v___x_2439_ = v_reuseFailAlloc_2453_;
goto v_reusejp_2438_;
}
v_reusejp_2438_:
{
lean_object* v___x_2440_; lean_object* v___x_2441_; lean_object* v___x_2442_; lean_object* v___x_2443_; lean_object* v___x_2444_; lean_object* v___x_2445_; lean_object* v___x_2446_; lean_object* v___x_2447_; lean_object* v___x_2448_; lean_object* v___x_2449_; lean_object* v___x_2450_; 
v___x_2440_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode___closed__5));
v___x_2441_ = lean_array_get_size(v_fst_2429_);
v___x_2442_ = l_Lean_JsonNumber_fromNat(v___x_2441_);
v___x_2443_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2443_, 0, v___x_2442_);
v___x_2444_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2444_, 0, v___x_2440_);
lean_ctor_set(v___x_2444_, 1, v___x_2443_);
v___x_2445_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__7));
v___x_2446_ = l_Lean_JsonNumber_fromNat(v_snd_2430_);
v___x_2447_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2447_, 0, v___x_2446_);
v___x_2448_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2448_, 0, v___x_2445_);
lean_ctor_set(v___x_2448_, 1, v___x_2447_);
v___x_2449_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__10));
v___x_2450_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__11));
if (v___y_2426_ == 0)
{
lean_object* v___x_2451_; 
v___x_2451_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__12));
v___y_2270_ = v___x_2435_;
v___y_2271_ = v___x_2444_;
v___y_2272_ = v___x_2441_;
v___y_2273_ = v___y_2426_;
v___y_2274_ = v___x_2449_;
v___y_2275_ = v___x_2448_;
v___y_2276_ = v___x_2434_;
v___y_2277_ = v_fst_2429_;
v___y_2278_ = v___x_2439_;
v___y_2279_ = v___x_2450_;
v___y_2280_ = v___x_2451_;
goto v___jp_2269_;
}
else
{
lean_object* v___x_2452_; 
v___x_2452_ = ((lean_object*)(l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___closed__13));
v___y_2270_ = v___x_2435_;
v___y_2271_ = v___x_2444_;
v___y_2272_ = v___x_2441_;
v___y_2273_ = v___y_2426_;
v___y_2274_ = v___x_2449_;
v___y_2275_ = v___x_2448_;
v___y_2276_ = v___x_2434_;
v___y_2277_ = v_fst_2429_;
v___y_2278_ = v___x_2439_;
v___y_2279_ = v___x_2450_;
v___y_2280_ = v___x_2452_;
goto v___jp_2269_;
}
}
}
}
else
{
lean_object* v_a_2455_; lean_object* v___x_2457_; uint8_t v_isShared_2458_; uint8_t v_isSharedCheck_2462_; 
lean_dec(v_register_2265_);
lean_dec_ref(v_mode_2264_);
v_a_2455_ = lean_ctor_get(v___x_2427_, 0);
v_isSharedCheck_2462_ = !lean_is_exclusive(v___x_2427_);
if (v_isSharedCheck_2462_ == 0)
{
v___x_2457_ = v___x_2427_;
v_isShared_2458_ = v_isSharedCheck_2462_;
goto v_resetjp_2456_;
}
else
{
lean_inc(v_a_2455_);
lean_dec(v___x_2427_);
v___x_2457_ = lean_box(0);
v_isShared_2458_ = v_isSharedCheck_2462_;
goto v_resetjp_2456_;
}
v_resetjp_2456_:
{
lean_object* v___x_2460_; 
if (v_isShared_2458_ == 0)
{
v___x_2460_ = v___x_2457_;
goto v_reusejp_2459_;
}
else
{
lean_object* v_reuseFailAlloc_2461_; 
v_reuseFailAlloc_2461_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2461_, 0, v_a_2455_);
v___x_2460_ = v_reuseFailAlloc_2461_;
goto v_reusejp_2459_;
}
v_reusejp_2459_:
{
return v___x_2460_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode___boxed(lean_object* v_mode_2469_, lean_object* v_register_2470_, lean_object* v_inputs_2471_, lean_object* v_wait_2472_, lean_object* v_a_2473_){
_start:
{
uint8_t v_wait_boxed_2474_; lean_object* v_res_2475_; 
v_wait_boxed_2474_ = lean_unbox(v_wait_2472_);
v_res_2475_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode(v_mode_2469_, v_register_2470_, v_inputs_2471_, v_wait_boxed_2474_);
lean_dec_ref(v_inputs_2471_);
return v_res_2475_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0(lean_object* v_fst_2476_, lean_object* v_fst_2477_, lean_object* v_range_2478_, lean_object* v_b_2479_, lean_object* v_i_2480_, lean_object* v_hs_2481_, lean_object* v_hl_2482_){
_start:
{
lean_object* v___x_2484_; 
v___x_2484_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___redArg(v_fst_2476_, v_fst_2477_, v_range_2478_, v_b_2479_, v_i_2480_);
return v___x_2484_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0___boxed(lean_object* v_fst_2485_, lean_object* v_fst_2486_, lean_object* v_range_2487_, lean_object* v_b_2488_, lean_object* v_i_2489_, lean_object* v_hs_2490_, lean_object* v_hl_2491_, lean_object* v___y_2492_){
_start:
{
lean_object* v_res_2493_; 
v_res_2493_ = l___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode_spec__0(v_fst_2485_, v_fst_2486_, v_range_2487_, v_b_2488_, v_i_2489_, v_hs_2490_, v_hl_2491_);
lean_dec_ref(v_range_2487_);
lean_dec_ref(v_fst_2486_);
lean_dec_ref(v_fst_2485_);
return v_res_2493_;
}
}
LEAN_EXPORT uint8_t l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(lean_object* v_a_2494_, lean_object* v_x_2495_){
_start:
{
if (lean_obj_tag(v_x_2495_) == 0)
{
uint8_t v___x_2496_; 
v___x_2496_ = 0;
return v___x_2496_;
}
else
{
lean_object* v_head_2497_; lean_object* v_tail_2498_; uint8_t v___x_2499_; 
v_head_2497_ = lean_ctor_get(v_x_2495_, 0);
v_tail_2498_ = lean_ctor_get(v_x_2495_, 1);
v___x_2499_ = lean_string_dec_eq(v_a_2494_, v_head_2497_);
if (v___x_2499_ == 0)
{
v_x_2495_ = v_tail_2498_;
goto _start;
}
else
{
return v___x_2499_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1___boxed(lean_object* v_a_2501_, lean_object* v_x_2502_){
_start:
{
uint8_t v_res_2503_; lean_object* v_r_2504_; 
v_res_2503_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v_a_2501_, v_x_2502_);
lean_dec(v_x_2502_);
lean_dec_ref(v_a_2501_);
v_r_2504_ = lean_box(v_res_2503_);
return v_r_2504_;
}
}
LEAN_EXPORT uint8_t l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0(lean_object* v_x_2507_){
_start:
{
if (lean_obj_tag(v_x_2507_) == 0)
{
uint8_t v___x_2508_; 
v___x_2508_ = 0;
return v___x_2508_;
}
else
{
lean_object* v_head_2509_; lean_object* v_tail_2510_; lean_object* v___x_2511_; uint8_t v___x_2512_; 
v_head_2509_ = lean_ctor_get(v_x_2507_, 0);
v_tail_2510_ = lean_ctor_get(v_x_2507_, 1);
v___x_2511_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__0));
v___x_2512_ = lean_string_dec_eq(v_head_2509_, v___x_2511_);
if (v___x_2512_ == 0)
{
lean_object* v___x_2513_; uint8_t v___x_2514_; 
v___x_2513_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__1));
v___x_2514_ = lean_string_dec_eq(v_head_2509_, v___x_2513_);
if (v___x_2514_ == 0)
{
uint8_t v___x_2515_; 
v___x_2515_ = 1;
return v___x_2515_;
}
else
{
v_x_2507_ = v_tail_2510_;
goto _start;
}
}
else
{
v_x_2507_ = v_tail_2510_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___boxed(lean_object* v_x_2518_){
_start:
{
uint8_t v_res_2519_; lean_object* v_r_2520_; 
v_res_2519_ = l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0(v_x_2518_);
lean_dec(v_x_2518_);
v_r_2520_ = lean_box(v_res_2519_);
return v_r_2520_;
}
}
LEAN_EXPORT lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute(lean_object* v_args_2530_){
_start:
{
if (lean_obj_tag(v_args_2530_) == 1)
{
lean_object* v_tail_2535_; 
v_tail_2535_ = lean_ctor_get(v_args_2530_, 1);
lean_inc(v_tail_2535_);
if (lean_obj_tag(v_tail_2535_) == 1)
{
lean_object* v_head_2536_; lean_object* v_head_2537_; lean_object* v_tail_2538_; uint8_t v___x_2539_; 
v_head_2536_ = lean_ctor_get(v_args_2530_, 0);
lean_inc(v_head_2536_);
lean_dec_ref_known(v_args_2530_, 2);
v_head_2537_ = lean_ctor_get(v_tail_2535_, 0);
lean_inc(v_head_2537_);
v_tail_2538_ = lean_ctor_get(v_tail_2535_, 1);
lean_inc(v_tail_2538_);
lean_dec_ref_known(v_tail_2535_, 2);
v___x_2539_ = l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0(v_tail_2538_);
if (v___x_2539_ == 0)
{
lean_object* v___x_2540_; 
v___x_2540_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_loadInputs(v_head_2537_);
lean_dec(v_head_2537_);
if (lean_obj_tag(v___x_2540_) == 0)
{
lean_object* v_a_2541_; lean_object* v___x_2543_; uint8_t v_isShared_2544_; uint8_t v_isSharedCheck_2561_; 
v_a_2541_ = lean_ctor_get(v___x_2540_, 0);
v_isSharedCheck_2561_ = !lean_is_exclusive(v___x_2540_);
if (v_isSharedCheck_2561_ == 0)
{
v___x_2543_ = v___x_2540_;
v_isShared_2544_ = v_isSharedCheck_2561_;
goto v_resetjp_2542_;
}
else
{
lean_inc(v_a_2541_);
lean_dec(v___x_2540_);
v___x_2543_ = lean_box(0);
v_isShared_2544_ = v_isSharedCheck_2561_;
goto v_resetjp_2542_;
}
v_resetjp_2542_:
{
lean_object* v___x_2545_; 
v___x_2545_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreRegister(v_head_2536_);
if (lean_obj_tag(v___x_2545_) == 1)
{
lean_object* v_val_2546_; lean_object* v___x_2547_; uint8_t v___x_2548_; 
v_val_2546_ = lean_ctor_get(v___x_2545_, 0);
lean_inc(v_val_2546_);
lean_dec_ref_known(v___x_2545_, 1);
v___x_2547_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__0));
v___x_2548_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v___x_2547_, v_tail_2538_);
if (v___x_2548_ == 0)
{
lean_object* v___x_2549_; uint8_t v___x_2550_; lean_object* v___x_2551_; 
lean_del_object(v___x_2543_);
v___x_2549_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__1));
v___x_2550_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v___x_2549_, v_tail_2538_);
lean_dec(v_tail_2538_);
v___x_2551_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_scoreMode(v_head_2536_, v_val_2546_, v_a_2541_, v___x_2550_);
lean_dec(v_a_2541_);
return v___x_2551_;
}
else
{
lean_object* v___x_2552_; lean_object* v___x_2554_; 
lean_dec(v_val_2546_);
lean_dec(v_a_2541_);
lean_dec(v_tail_2538_);
lean_dec(v_head_2536_);
v___x_2552_ = ((lean_object*)(l_Lean1090_Diagnostics_DecodeCosts_execute___closed__3));
if (v_isShared_2544_ == 0)
{
lean_ctor_set_tag(v___x_2543_, 1);
lean_ctor_set(v___x_2543_, 0, v___x_2552_);
v___x_2554_ = v___x_2543_;
goto v_reusejp_2553_;
}
else
{
lean_object* v_reuseFailAlloc_2555_; 
v_reuseFailAlloc_2555_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2555_, 0, v___x_2552_);
v___x_2554_ = v_reuseFailAlloc_2555_;
goto v_reusejp_2553_;
}
v_reusejp_2553_:
{
return v___x_2554_;
}
}
}
else
{
lean_object* v___x_2556_; uint8_t v___x_2557_; lean_object* v___x_2558_; uint8_t v___x_2559_; lean_object* v___x_2560_; 
lean_dec(v___x_2545_);
lean_del_object(v___x_2543_);
v___x_2556_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__0));
v___x_2557_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v___x_2556_, v_tail_2538_);
v___x_2558_ = ((lean_object*)(l_List_any___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__0___closed__1));
v___x_2559_ = l_List_elem___at___00Lean1090_Diagnostics_DecodeCosts_execute_spec__1(v___x_2558_, v_tail_2538_);
lean_dec(v_tail_2538_);
v___x_2560_ = l___private_review_diagnostics_DecodeCosts_0__Lean1090_Diagnostics_DecodeCosts_decodeMode(v_head_2536_, v_a_2541_, v___x_2557_, v___x_2559_);
lean_dec(v_a_2541_);
return v___x_2560_;
}
}
}
else
{
lean_object* v_a_2562_; lean_object* v___x_2564_; uint8_t v_isShared_2565_; uint8_t v_isSharedCheck_2569_; 
lean_dec(v_tail_2538_);
lean_dec(v_head_2536_);
v_a_2562_ = lean_ctor_get(v___x_2540_, 0);
v_isSharedCheck_2569_ = !lean_is_exclusive(v___x_2540_);
if (v_isSharedCheck_2569_ == 0)
{
v___x_2564_ = v___x_2540_;
v_isShared_2565_ = v_isSharedCheck_2569_;
goto v_resetjp_2563_;
}
else
{
lean_inc(v_a_2562_);
lean_dec(v___x_2540_);
v___x_2564_ = lean_box(0);
v_isShared_2565_ = v_isSharedCheck_2569_;
goto v_resetjp_2563_;
}
v_resetjp_2563_:
{
lean_object* v___x_2567_; 
if (v_isShared_2565_ == 0)
{
v___x_2567_ = v___x_2564_;
goto v_reusejp_2566_;
}
else
{
lean_object* v_reuseFailAlloc_2568_; 
v_reuseFailAlloc_2568_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2568_, 0, v_a_2562_);
v___x_2567_ = v_reuseFailAlloc_2568_;
goto v_reusejp_2566_;
}
v_reusejp_2566_:
{
return v___x_2567_;
}
}
}
}
else
{
lean_object* v___x_2570_; lean_object* v___x_2571_; 
lean_dec(v_tail_2538_);
lean_dec(v_head_2537_);
lean_dec(v_head_2536_);
v___x_2570_ = ((lean_object*)(l_Lean1090_Diagnostics_DecodeCosts_execute___closed__5));
v___x_2571_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2571_, 0, v___x_2570_);
return v___x_2571_;
}
}
else
{
lean_dec_ref_known(v_args_2530_, 2);
lean_dec(v_tail_2535_);
goto v___jp_2532_;
}
}
else
{
lean_dec(v_args_2530_);
goto v___jp_2532_;
}
v___jp_2532_:
{
lean_object* v___x_2533_; lean_object* v___x_2534_; 
v___x_2533_ = ((lean_object*)(l_Lean1090_Diagnostics_DecodeCosts_execute___closed__1));
v___x_2534_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2534_, 0, v___x_2533_);
return v___x_2534_;
}
}
}
LEAN_EXPORT lean_object* l_Lean1090_Diagnostics_DecodeCosts_execute___boxed(lean_object* v_args_2572_, lean_object* v_a_2573_){
_start:
{
lean_object* v_res_2574_; 
v_res_2574_ = l_Lean1090_Diagnostics_DecodeCosts_execute(v_args_2572_);
return v_res_2574_;
}
}
LEAN_EXPORT lean_object* _lean_main(lean_object* v_args_2575_){
_start:
{
lean_object* v___x_2577_; 
v___x_2577_ = l_Lean1090_Diagnostics_DecodeCosts_execute(v_args_2575_);
return v___x_2577_;
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_args_2578_, lean_object* v_a_2579_){
_start:
{
lean_object* v_res_2580_; 
v_res_2580_ = _lean_main(v_args_2578_);
return v_res_2580_;
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
