// Lean compiler output
// Module: Impl.CPRPolicy
// Imports: public import Init public meta import Init public import Model.Types public import Impl.CPR public import Impl.Binary64
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
uint8_t l_Rat_blt(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_div(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_sub(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_CPR_absQ(lean_object*);
lean_object* l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(lean_object*);
uint8_t l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(lean_object*, lean_object*);
lean_object* l_Nat_decLe___boxed(lean_object*, lean_object*);
lean_object* l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(lean_object*, lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
uint8_t lean_int_dec_lt(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_distanceLT(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_distanceLT___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_distanceGT(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_distanceGT___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_speedGT(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_speedGT___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_initial(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_CPR_Policy_insertCode___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Nat_decLe___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_insertCode___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_CPR_Policy_insertCode___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_insertCode(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_stableSupported(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_stableSupported___boxed(lean_object*);
static const lean_ctor_object lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(96) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__0 = (const lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__0_value;
static const lean_ctor_object lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(80) << 1) | 1)),((lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__0_value)}};
static const lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__1 = (const lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__1_value;
static const lean_ctor_object lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(69) << 1) | 1)),((lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__1_value)}};
static const lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__2 = (const lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__2_value;
static const lean_ctor_object lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(68) << 1) | 1)),((lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__2_value)}};
static const lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__3 = (const lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__3_value;
static const lean_ctor_object lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(64) << 1) | 1)),((lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__3_value)}};
static const lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__4 = (const lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__4_value;
static const lean_ctor_object lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(33) << 1) | 1)),((lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__4_value)}};
static const lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__5 = (const lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__5_value;
static const lean_ctor_object lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(32) << 1) | 1)),((lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__5_value)}};
static const lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__6 = (const lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__6_value;
static const lean_ctor_object lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(9) << 1) | 1)),((lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__6_value)}};
static const lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__7 = (const lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__7_value;
static const lean_ctor_object lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(8) << 1) | 1)),((lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__7_value)}};
static const lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__8 = (const lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__8_value;
static const lean_ctor_object lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(6) << 1) | 1)),((lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__8_value)}};
static const lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__9 = (const lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__9_value;
static const lean_ctor_object lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__9_value)}};
static const lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__10 = (const lean_object*)&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__10_value;
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_updateBDS17(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0___closed__0;
LEAN_EXPORT uint8_t lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_nearAirport(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_nearAirport___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_nearestAirport_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_nearestAirport(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__4;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__5;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_stepAirborne___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_stepAirborne___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_stepAirborne(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_stepSurface___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_stepSurface___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_stepSurface(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(8) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__0_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(9) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__1_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(97) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__2_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(98) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__3_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(101) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__4_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode(uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_step(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_lowerAltitude(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_lowerAltitude___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_updateGlobalReference___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_updateGlobalReference___lam__0___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateGlobalReference_spec__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateGlobalReference_spec__0___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateGlobalReference_spec__0(lean_object*, lean_object*, lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_CPR_Policy_updateGlobalReference___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_CPR_Policy_updateGlobalReference___lam__0___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_updateGlobalReference___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_CPR_Policy_updateGlobalReference___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_updateGlobalReference(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_CPR_Policy_streamStep_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_CPR_Policy_streamStep_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_CPR_Policy_streamStep_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_CPR_Policy_streamStep_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_streamStep(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_decodePositions_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodePositions(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodePositions(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_distanceLT(lean_object* v_distance_1_, lean_object* v_threshold_2_){
_start:
{
switch(lean_obj_tag(v_distance_1_))
{
case 0:
{
lean_object* v_km_3_; uint8_t v___x_4_; 
v_km_3_ = lean_ctor_get(v_distance_1_, 0);
lean_inc_ref(v_km_3_);
lean_dec_ref_known(v_distance_1_, 1);
v___x_4_ = l_Rat_blt(v_km_3_, v_threshold_2_);
return v___x_4_;
}
case 3:
{
uint8_t v___x_5_; 
lean_dec_ref(v_threshold_2_);
v___x_5_ = 1;
return v___x_5_;
}
default: 
{
uint8_t v___x_6_; 
lean_dec_ref(v_threshold_2_);
lean_dec(v_distance_1_);
v___x_6_ = 0;
return v___x_6_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_distanceLT___boxed(lean_object* v_distance_7_, lean_object* v_threshold_8_){
_start:
{
uint8_t v_res_9_; lean_object* v_r_10_; 
v_res_9_ = lp_lean1090_Lean1090_Impl_CPR_Policy_distanceLT(v_distance_7_, v_threshold_8_);
v_r_10_ = lean_box(v_res_9_);
return v_r_10_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_distanceGT(lean_object* v_distance_11_, lean_object* v_threshold_12_){
_start:
{
switch(lean_obj_tag(v_distance_11_))
{
case 0:
{
lean_object* v_km_13_; uint8_t v___x_14_; 
v_km_13_ = lean_ctor_get(v_distance_11_, 0);
lean_inc_ref(v_km_13_);
lean_dec_ref_known(v_distance_11_, 1);
v___x_14_ = l_Rat_blt(v_threshold_12_, v_km_13_);
return v___x_14_;
}
case 2:
{
uint8_t v___x_15_; 
lean_dec_ref(v_threshold_12_);
v___x_15_ = 1;
return v___x_15_;
}
default: 
{
uint8_t v___x_16_; 
lean_dec_ref(v_threshold_12_);
lean_dec(v_distance_11_);
v___x_16_ = 0;
return v___x_16_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_distanceGT___boxed(lean_object* v_distance_17_, lean_object* v_threshold_18_){
_start:
{
uint8_t v_res_19_; lean_object* v_r_20_; 
v_res_19_ = lp_lean1090_Lean1090_Impl_CPR_Policy_distanceGT(v_distance_17_, v_threshold_18_);
v_r_20_ = lean_box(v_res_19_);
return v_r_20_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_speedGT(lean_object* v_distance_21_, lean_object* v_hours_22_, lean_object* v_threshold_23_){
_start:
{
switch(lean_obj_tag(v_distance_21_))
{
case 0:
{
lean_object* v_km_24_; lean_object* v___x_25_; uint8_t v___x_26_; 
v_km_24_ = lean_ctor_get(v_distance_21_, 0);
v___x_25_ = lp_lean1090_Lean1090_Impl_Binary64_div(v_km_24_, v_hours_22_);
v___x_26_ = l_Rat_blt(v_threshold_23_, v___x_25_);
return v___x_26_;
}
case 2:
{
uint8_t v___x_27_; 
lean_dec_ref(v_threshold_23_);
lean_dec_ref(v_hours_22_);
v___x_27_ = 1;
return v___x_27_;
}
default: 
{
uint8_t v___x_28_; 
lean_dec_ref(v_threshold_23_);
lean_dec_ref(v_hours_22_);
v___x_28_ = 0;
return v___x_28_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_speedGT___boxed(lean_object* v_distance_29_, lean_object* v_hours_30_, lean_object* v_threshold_31_){
_start:
{
uint8_t v_res_32_; lean_object* v_r_33_; 
v_res_32_ = lp_lean1090_Lean1090_Impl_CPR_Policy_speedGT(v_distance_29_, v_hours_30_, v_threshold_31_);
lean_dec(v_distance_29_);
v_r_33_ = lean_box(v_res_32_);
return v_r_33_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_initial(lean_object* v_timestamp_34_){
_start:
{
lean_object* v___x_35_; lean_object* v___x_36_; lean_object* v___x_37_; lean_object* v___x_38_; 
v___x_35_ = lean_box(0);
v___x_36_ = lean_box(0);
v___x_37_ = lean_unsigned_to_nat(0u);
lean_inc_ref_n(v_timestamp_34_, 2);
v___x_38_ = lean_alloc_ctor(0, 11, 0);
lean_ctor_set(v___x_38_, 0, v_timestamp_34_);
lean_ctor_set(v___x_38_, 1, v___x_35_);
lean_ctor_set(v___x_38_, 2, v___x_35_);
lean_ctor_set(v___x_38_, 3, v___x_35_);
lean_ctor_set(v___x_38_, 4, v___x_36_);
lean_ctor_set(v___x_38_, 5, v___x_36_);
lean_ctor_set(v___x_38_, 6, v___x_37_);
lean_ctor_set(v___x_38_, 7, v_timestamp_34_);
lean_ctor_set(v___x_38_, 8, v___x_35_);
lean_ctor_set(v___x_38_, 9, v_timestamp_34_);
lean_ctor_set(v___x_38_, 10, v___x_35_);
return v___x_38_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_insertCode(lean_object* v_code_40_, lean_object* v_codes_41_){
_start:
{
uint8_t v___x_42_; 
v___x_42_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_code_40_, v_codes_41_);
if (v___x_42_ == 0)
{
lean_object* v___f_43_; lean_object* v___x_44_; lean_object* v___x_45_; 
v___f_43_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_insertCode___closed__0));
v___x_44_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_44_, 0, v_code_40_);
lean_ctor_set(v___x_44_, 1, v_codes_41_);
v___x_45_ = l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(v___x_44_, v___f_43_);
return v___x_45_;
}
else
{
lean_dec(v_code_40_);
return v_codes_41_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_stableSupported(lean_object* v_state_46_){
_start:
{
lean_object* v_supportedBDS_47_; lean_object* v_bds17Count_48_; lean_object* v___x_49_; uint8_t v___x_50_; 
v_supportedBDS_47_ = lean_ctor_get(v_state_46_, 5);
v_bds17Count_48_ = lean_ctor_get(v_state_46_, 6);
v___x_49_ = lean_unsigned_to_nat(3u);
v___x_50_ = lean_nat_dec_le(v___x_49_, v_bds17Count_48_);
if (v___x_50_ == 0)
{
lean_object* v___x_51_; 
v___x_51_ = lean_box(0);
return v___x_51_;
}
else
{
lean_object* v___x_52_; 
lean_inc(v_supportedBDS_47_);
v___x_52_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_52_, 0, v_supportedBDS_47_);
return v___x_52_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_stableSupported___boxed(lean_object* v_state_53_){
_start:
{
lean_object* v_res_54_; 
v_res_54_ = lp_lean1090_Lean1090_Impl_CPR_Policy_stableSupported(v_state_53_);
lean_dec_ref(v_state_53_);
return v_res_54_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0(lean_object* v_x_88_, lean_object* v_x_89_){
_start:
{
if (lean_obj_tag(v_x_89_) == 0)
{
return v_x_88_;
}
else
{
lean_object* v_head_90_; lean_object* v_tail_91_; lean_object* v_permitted_92_; uint8_t v___x_93_; 
v_head_90_ = lean_ctor_get(v_x_89_, 0);
lean_inc(v_head_90_);
v_tail_91_ = lean_ctor_get(v_x_89_, 1);
lean_inc(v_tail_91_);
lean_dec_ref_known(v_x_89_, 2);
v_permitted_92_ = ((lean_object*)(lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0___closed__10));
v___x_93_ = l_List_elem___at___00Lean_Meta_Occurrences_contains_spec__0(v_head_90_, v_permitted_92_);
if (v___x_93_ == 0)
{
lean_dec(v_head_90_);
v_x_89_ = v_tail_91_;
goto _start;
}
else
{
lean_object* v___x_95_; 
v___x_95_ = lp_lean1090_Lean1090_Impl_CPR_Policy_insertCode(v_head_90_, v_x_88_);
v_x_88_ = v___x_95_;
v_x_89_ = v_tail_91_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_updateBDS17(lean_object* v_state_97_, lean_object* v_reported_98_){
_start:
{
lean_object* v_timestamp_99_; lean_object* v_position_100_; lean_object* v_lastAltitude_101_; lean_object* v_airport_102_; lean_object* v_seenBDS_103_; lean_object* v_supportedBDS_104_; lean_object* v_bds17Count_105_; lean_object* v_oddTimestamp_106_; lean_object* v_oddMessage_107_; lean_object* v_evenTimestamp_108_; lean_object* v_evenMessage_109_; lean_object* v___x_111_; uint8_t v_isShared_112_; uint8_t v_isSharedCheck_124_; 
v_timestamp_99_ = lean_ctor_get(v_state_97_, 0);
v_position_100_ = lean_ctor_get(v_state_97_, 1);
v_lastAltitude_101_ = lean_ctor_get(v_state_97_, 2);
v_airport_102_ = lean_ctor_get(v_state_97_, 3);
v_seenBDS_103_ = lean_ctor_get(v_state_97_, 4);
v_supportedBDS_104_ = lean_ctor_get(v_state_97_, 5);
v_bds17Count_105_ = lean_ctor_get(v_state_97_, 6);
v_oddTimestamp_106_ = lean_ctor_get(v_state_97_, 7);
v_oddMessage_107_ = lean_ctor_get(v_state_97_, 8);
v_evenTimestamp_108_ = lean_ctor_get(v_state_97_, 9);
v_evenMessage_109_ = lean_ctor_get(v_state_97_, 10);
v_isSharedCheck_124_ = !lean_is_exclusive(v_state_97_);
if (v_isSharedCheck_124_ == 0)
{
v___x_111_ = v_state_97_;
v_isShared_112_ = v_isSharedCheck_124_;
goto v_resetjp_110_;
}
else
{
lean_inc(v_evenMessage_109_);
lean_inc(v_evenTimestamp_108_);
lean_inc(v_oddMessage_107_);
lean_inc(v_oddTimestamp_106_);
lean_inc(v_bds17Count_105_);
lean_inc(v_supportedBDS_104_);
lean_inc(v_seenBDS_103_);
lean_inc(v_airport_102_);
lean_inc(v_lastAltitude_101_);
lean_inc(v_position_100_);
lean_inc(v_timestamp_99_);
lean_dec(v_state_97_);
v___x_111_ = lean_box(0);
v_isShared_112_ = v_isSharedCheck_124_;
goto v_resetjp_110_;
}
v_resetjp_110_:
{
lean_object* v_supported_113_; lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v___x_116_; uint8_t v___x_117_; 
v_supported_113_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateBDS17_spec__0(v_supportedBDS_104_, v_reported_98_);
v___x_114_ = lean_unsigned_to_nat(255u);
v___x_115_ = lean_unsigned_to_nat(1u);
v___x_116_ = lean_nat_add(v_bds17Count_105_, v___x_115_);
lean_dec(v_bds17Count_105_);
v___x_117_ = lean_nat_dec_le(v___x_114_, v___x_116_);
if (v___x_117_ == 0)
{
lean_object* v___x_119_; 
if (v_isShared_112_ == 0)
{
lean_ctor_set(v___x_111_, 6, v___x_116_);
lean_ctor_set(v___x_111_, 5, v_supported_113_);
v___x_119_ = v___x_111_;
goto v_reusejp_118_;
}
else
{
lean_object* v_reuseFailAlloc_120_; 
v_reuseFailAlloc_120_ = lean_alloc_ctor(0, 11, 0);
lean_ctor_set(v_reuseFailAlloc_120_, 0, v_timestamp_99_);
lean_ctor_set(v_reuseFailAlloc_120_, 1, v_position_100_);
lean_ctor_set(v_reuseFailAlloc_120_, 2, v_lastAltitude_101_);
lean_ctor_set(v_reuseFailAlloc_120_, 3, v_airport_102_);
lean_ctor_set(v_reuseFailAlloc_120_, 4, v_seenBDS_103_);
lean_ctor_set(v_reuseFailAlloc_120_, 5, v_supported_113_);
lean_ctor_set(v_reuseFailAlloc_120_, 6, v___x_116_);
lean_ctor_set(v_reuseFailAlloc_120_, 7, v_oddTimestamp_106_);
lean_ctor_set(v_reuseFailAlloc_120_, 8, v_oddMessage_107_);
lean_ctor_set(v_reuseFailAlloc_120_, 9, v_evenTimestamp_108_);
lean_ctor_set(v_reuseFailAlloc_120_, 10, v_evenMessage_109_);
v___x_119_ = v_reuseFailAlloc_120_;
goto v_reusejp_118_;
}
v_reusejp_118_:
{
return v___x_119_;
}
}
else
{
lean_object* v___x_122_; 
lean_dec(v___x_116_);
if (v_isShared_112_ == 0)
{
lean_ctor_set(v___x_111_, 6, v___x_114_);
lean_ctor_set(v___x_111_, 5, v_supported_113_);
v___x_122_ = v___x_111_;
goto v_reusejp_121_;
}
else
{
lean_object* v_reuseFailAlloc_123_; 
v_reuseFailAlloc_123_ = lean_alloc_ctor(0, 11, 0);
lean_ctor_set(v_reuseFailAlloc_123_, 0, v_timestamp_99_);
lean_ctor_set(v_reuseFailAlloc_123_, 1, v_position_100_);
lean_ctor_set(v_reuseFailAlloc_123_, 2, v_lastAltitude_101_);
lean_ctor_set(v_reuseFailAlloc_123_, 3, v_airport_102_);
lean_ctor_set(v_reuseFailAlloc_123_, 4, v_seenBDS_103_);
lean_ctor_set(v_reuseFailAlloc_123_, 5, v_supported_113_);
lean_ctor_set(v_reuseFailAlloc_123_, 6, v___x_114_);
lean_ctor_set(v_reuseFailAlloc_123_, 7, v_oddTimestamp_106_);
lean_ctor_set(v_reuseFailAlloc_123_, 8, v_oddMessage_107_);
lean_ctor_set(v_reuseFailAlloc_123_, 9, v_evenTimestamp_108_);
lean_ctor_set(v_reuseFailAlloc_123_, 10, v_evenMessage_109_);
v___x_122_ = v_reuseFailAlloc_123_;
goto v_reusejp_121_;
}
v_reusejp_121_:
{
return v___x_122_;
}
}
}
}
}
static lean_object* _init_lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0___closed__0(void){
_start:
{
lean_object* v___x_125_; lean_object* v___x_126_; 
v___x_125_ = lean_unsigned_to_nat(10u);
v___x_126_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_125_);
return v___x_126_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0(lean_object* v_geo_127_, lean_object* v_p_128_, lean_object* v_x_129_){
_start:
{
if (lean_obj_tag(v_x_129_) == 0)
{
uint8_t v___x_130_; 
lean_dec_ref(v_p_128_);
lean_dec_ref(v_geo_127_);
v___x_130_ = 0;
return v___x_130_;
}
else
{
lean_object* v_head_131_; lean_object* v_tail_132_; lean_object* v_distanceKm_133_; lean_object* v_position_134_; lean_object* v___x_135_; lean_object* v___x_136_; uint8_t v___x_137_; 
v_head_131_ = lean_ctor_get(v_x_129_, 0);
lean_inc(v_head_131_);
v_tail_132_ = lean_ctor_get(v_x_129_, 1);
lean_inc(v_tail_132_);
lean_dec_ref_known(v_x_129_, 2);
v_distanceKm_133_ = lean_ctor_get(v_geo_127_, 0);
v_position_134_ = lean_ctor_get(v_head_131_, 1);
lean_inc_ref(v_position_134_);
lean_dec(v_head_131_);
lean_inc_ref(v_distanceKm_133_);
lean_inc_ref(v_p_128_);
v___x_135_ = lean_apply_2(v_distanceKm_133_, v_p_128_, v_position_134_);
v___x_136_ = lean_obj_once(&lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0___closed__0, &lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0___closed__0_once, _init_lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0___closed__0);
v___x_137_ = lp_lean1090_Lean1090_Impl_CPR_Policy_distanceLT(v___x_135_, v___x_136_);
if (v___x_137_ == 0)
{
v_x_129_ = v_tail_132_;
goto _start;
}
else
{
lean_dec(v_tail_132_);
lean_dec_ref(v_p_128_);
lean_dec_ref(v_geo_127_);
return v___x_137_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0___boxed(lean_object* v_geo_139_, lean_object* v_p_140_, lean_object* v_x_141_){
_start:
{
uint8_t v_res_142_; lean_object* v_r_143_; 
v_res_142_ = lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0(v_geo_139_, v_p_140_, v_x_141_);
v_r_143_ = lean_box(v_res_142_);
return v_r_143_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_nearAirport(lean_object* v_geo_144_, lean_object* v_p_145_){
_start:
{
lean_object* v_airports_146_; uint8_t v___x_147_; 
v_airports_146_ = lean_ctor_get(v_geo_144_, 1);
lean_inc(v_airports_146_);
v___x_147_ = lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0(v_geo_144_, v_p_145_, v_airports_146_);
return v___x_147_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_nearAirport___boxed(lean_object* v_geo_148_, lean_object* v_p_149_){
_start:
{
uint8_t v_res_150_; lean_object* v_r_151_; 
v_res_150_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nearAirport(v_geo_148_, v_p_149_);
v_r_151_ = lean_box(v_res_150_);
return v_r_151_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_nearestAirport_spec__0(lean_object* v_geo_152_, lean_object* v_p_153_, lean_object* v_x_154_, lean_object* v_x_155_){
_start:
{
if (lean_obj_tag(v_x_155_) == 0)
{
lean_dec_ref(v_p_153_);
lean_dec_ref(v_geo_152_);
return v_x_154_;
}
else
{
lean_object* v_head_156_; lean_object* v_tail_157_; lean_object* v___x_159_; uint8_t v_isShared_160_; uint8_t v_isSharedCheck_194_; 
v_head_156_ = lean_ctor_get(v_x_155_, 0);
v_tail_157_ = lean_ctor_get(v_x_155_, 1);
v_isSharedCheck_194_ = !lean_is_exclusive(v_x_155_);
if (v_isSharedCheck_194_ == 0)
{
v___x_159_ = v_x_155_;
v_isShared_160_ = v_isSharedCheck_194_;
goto v_resetjp_158_;
}
else
{
lean_inc(v_tail_157_);
lean_inc(v_head_156_);
lean_dec(v_x_155_);
v___x_159_ = lean_box(0);
v_isShared_160_ = v_isSharedCheck_194_;
goto v_resetjp_158_;
}
v_resetjp_158_:
{
lean_object* v_distanceKm_161_; lean_object* v_icao_162_; lean_object* v_position_163_; lean_object* v___x_165_; uint8_t v_isShared_166_; uint8_t v_isSharedCheck_193_; 
v_distanceKm_161_ = lean_ctor_get(v_geo_152_, 0);
v_icao_162_ = lean_ctor_get(v_head_156_, 0);
v_position_163_ = lean_ctor_get(v_head_156_, 1);
v_isSharedCheck_193_ = !lean_is_exclusive(v_head_156_);
if (v_isSharedCheck_193_ == 0)
{
v___x_165_ = v_head_156_;
v_isShared_166_ = v_isSharedCheck_193_;
goto v_resetjp_164_;
}
else
{
lean_inc(v_position_163_);
lean_inc(v_icao_162_);
lean_dec(v_head_156_);
v___x_165_ = lean_box(0);
v_isShared_166_ = v_isSharedCheck_193_;
goto v_resetjp_164_;
}
v_resetjp_164_:
{
lean_object* v_distance_167_; lean_object* v___x_174_; uint8_t v___x_175_; 
lean_inc_ref(v_distanceKm_161_);
lean_inc_ref(v_p_153_);
v_distance_167_ = lean_apply_2(v_distanceKm_161_, v_p_153_, v_position_163_);
v___x_174_ = lean_obj_once(&lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0___closed__0, &lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0___closed__0_once, _init_lp_lean1090_List_any___at___00Lean1090_Impl_CPR_Policy_nearAirport_spec__0___closed__0);
lean_inc(v_distance_167_);
v___x_175_ = lp_lean1090_Lean1090_Impl_CPR_Policy_distanceLT(v_distance_167_, v___x_174_);
if (v___x_175_ == 0)
{
lean_dec(v_distance_167_);
lean_del_object(v___x_165_);
lean_dec_ref(v_icao_162_);
lean_del_object(v___x_159_);
v_x_155_ = v_tail_157_;
goto _start;
}
else
{
if (lean_obj_tag(v_x_154_) == 0)
{
lean_object* v___x_178_; 
lean_del_object(v___x_165_);
if (v_isShared_160_ == 0)
{
lean_ctor_set_tag(v___x_159_, 0);
lean_ctor_set(v___x_159_, 1, v_icao_162_);
lean_ctor_set(v___x_159_, 0, v_distance_167_);
v___x_178_ = v___x_159_;
goto v_reusejp_177_;
}
else
{
lean_object* v_reuseFailAlloc_181_; 
v_reuseFailAlloc_181_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_181_, 0, v_distance_167_);
lean_ctor_set(v_reuseFailAlloc_181_, 1, v_icao_162_);
v___x_178_ = v_reuseFailAlloc_181_;
goto v_reusejp_177_;
}
v_reusejp_177_:
{
lean_object* v___x_179_; 
v___x_179_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_179_, 0, v___x_178_);
v_x_154_ = v___x_179_;
v_x_155_ = v_tail_157_;
goto _start;
}
}
else
{
lean_del_object(v___x_159_);
switch(lean_obj_tag(v_distance_167_))
{
case 0:
{
lean_object* v_val_182_; lean_object* v_fst_183_; 
v_val_182_ = lean_ctor_get(v_x_154_, 0);
v_fst_183_ = lean_ctor_get(v_val_182_, 0);
if (lean_obj_tag(v_fst_183_) == 0)
{
lean_object* v_km_184_; lean_object* v_km_185_; uint8_t v___x_186_; 
v_km_184_ = lean_ctor_get(v_distance_167_, 0);
lean_inc_ref(v_km_184_);
v_km_185_ = lean_ctor_get(v_fst_183_, 0);
lean_inc_ref(v_km_185_);
v___x_186_ = l_Rat_blt(v_km_184_, v_km_185_);
if (v___x_186_ == 0)
{
lean_dec_ref_known(v_distance_167_, 1);
lean_del_object(v___x_165_);
lean_dec_ref(v_icao_162_);
v_x_155_ = v_tail_157_;
goto _start;
}
else
{
lean_dec_ref_known(v_x_154_, 1);
goto v___jp_168_;
}
}
else
{
lean_dec_ref_known(v_distance_167_, 1);
lean_del_object(v___x_165_);
lean_dec_ref(v_icao_162_);
v_x_155_ = v_tail_157_;
goto _start;
}
}
case 3:
{
lean_object* v_val_189_; lean_object* v_fst_190_; 
v_val_189_ = lean_ctor_get(v_x_154_, 0);
v_fst_190_ = lean_ctor_get(v_val_189_, 0);
if (lean_obj_tag(v_fst_190_) == 0)
{
lean_dec_ref_known(v_x_154_, 1);
goto v___jp_168_;
}
else
{
lean_del_object(v___x_165_);
lean_dec_ref(v_icao_162_);
v_x_155_ = v_tail_157_;
goto _start;
}
}
default: 
{
lean_dec(v_distance_167_);
lean_del_object(v___x_165_);
lean_dec_ref(v_icao_162_);
v_x_155_ = v_tail_157_;
goto _start;
}
}
}
}
v___jp_168_:
{
lean_object* v___x_170_; 
if (v_isShared_166_ == 0)
{
lean_ctor_set(v___x_165_, 1, v_icao_162_);
lean_ctor_set(v___x_165_, 0, v_distance_167_);
v___x_170_ = v___x_165_;
goto v_reusejp_169_;
}
else
{
lean_object* v_reuseFailAlloc_173_; 
v_reuseFailAlloc_173_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_173_, 0, v_distance_167_);
lean_ctor_set(v_reuseFailAlloc_173_, 1, v_icao_162_);
v___x_170_ = v_reuseFailAlloc_173_;
goto v_reusejp_169_;
}
v_reusejp_169_:
{
lean_object* v___x_171_; 
v___x_171_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_171_, 0, v___x_170_);
v_x_154_ = v___x_171_;
v_x_155_ = v_tail_157_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_nearestAirport(lean_object* v_geo_195_, lean_object* v_p_196_){
_start:
{
lean_object* v_airports_197_; lean_object* v___x_198_; lean_object* v_best_199_; 
v_airports_197_ = lean_ctor_get(v_geo_195_, 1);
lean_inc(v_airports_197_);
v___x_198_ = lean_box(0);
v_best_199_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_nearestAirport_spec__0(v_geo_195_, v_p_196_, v___x_198_, v_airports_197_);
if (lean_obj_tag(v_best_199_) == 0)
{
return v___x_198_;
}
else
{
lean_object* v_val_200_; lean_object* v___x_202_; uint8_t v_isShared_203_; uint8_t v_isSharedCheck_208_; 
v_val_200_ = lean_ctor_get(v_best_199_, 0);
v_isSharedCheck_208_ = !lean_is_exclusive(v_best_199_);
if (v_isSharedCheck_208_ == 0)
{
v___x_202_ = v_best_199_;
v_isShared_203_ = v_isSharedCheck_208_;
goto v_resetjp_201_;
}
else
{
lean_inc(v_val_200_);
lean_dec(v_best_199_);
v___x_202_ = lean_box(0);
v_isShared_203_ = v_isSharedCheck_208_;
goto v_resetjp_201_;
}
v_resetjp_201_:
{
lean_object* v_snd_204_; lean_object* v___x_206_; 
v_snd_204_ = lean_ctor_get(v_val_200_, 1);
lean_inc(v_snd_204_);
lean_dec(v_val_200_);
if (v_isShared_203_ == 0)
{
lean_ctor_set(v___x_202_, 0, v_snd_204_);
v___x_206_ = v___x_202_;
goto v_reusejp_205_;
}
else
{
lean_object* v_reuseFailAlloc_207_; 
v_reuseFailAlloc_207_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_207_, 0, v_snd_204_);
v___x_206_ = v_reuseFailAlloc_207_;
goto v_reusejp_205_;
}
v_reusejp_205_:
{
return v___x_206_;
}
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__0(void){
_start:
{
lean_object* v___x_209_; lean_object* v___x_210_; 
v___x_209_ = lean_unsigned_to_nat(500u);
v___x_210_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_209_);
return v___x_210_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__1(void){
_start:
{
lean_object* v___x_211_; lean_object* v___x_212_; 
v___x_211_ = lean_unsigned_to_nat(30u);
v___x_212_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_211_);
return v___x_212_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__2(void){
_start:
{
lean_object* v___x_213_; lean_object* v___x_214_; 
v___x_213_ = lean_unsigned_to_nat(3600u);
v___x_214_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_213_);
return v___x_214_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__3(void){
_start:
{
lean_object* v___x_215_; lean_object* v___x_216_; 
v___x_215_ = lean_unsigned_to_nat(1200u);
v___x_216_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_215_);
return v___x_216_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__4(void){
_start:
{
lean_object* v___x_217_; lean_object* v___x_218_; 
v___x_217_ = lean_unsigned_to_nat(1800u);
v___x_218_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_217_);
return v___x_218_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__5(void){
_start:
{
lean_object* v___x_219_; lean_object* v___x_220_; 
v___x_219_ = lean_unsigned_to_nat(0u);
v___x_220_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_219_);
return v___x_220_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion(lean_object* v_geo_221_, lean_object* v_state_222_, lean_object* v_timestamp_223_, lean_object* v_candidate_224_){
_start:
{
uint8_t v___y_226_; uint8_t v___y_227_; lean_object* v_position_230_; 
v_position_230_ = lean_ctor_get(v_state_222_, 1);
lean_inc(v_position_230_);
if (lean_obj_tag(v_position_230_) == 0)
{
uint8_t v___x_231_; 
lean_dec_ref(v_candidate_224_);
lean_dec_ref(v_timestamp_223_);
lean_dec_ref(v_state_222_);
lean_dec_ref(v_geo_221_);
v___x_231_ = 1;
return v___x_231_;
}
else
{
lean_object* v_timestamp_232_; lean_object* v_val_233_; lean_object* v_distanceKm_234_; lean_object* v_distance_235_; lean_object* v___x_236_; lean_object* v_dt_237_; uint8_t v___y_239_; lean_object* v___x_244_; lean_object* v_hours_245_; uint8_t v___y_247_; lean_object* v___x_250_; uint8_t v___x_251_; 
v_timestamp_232_ = lean_ctor_get(v_state_222_, 0);
lean_inc_ref(v_timestamp_232_);
lean_dec_ref(v_state_222_);
v_val_233_ = lean_ctor_get(v_position_230_, 0);
lean_inc(v_val_233_);
lean_dec_ref_known(v_position_230_, 1);
v_distanceKm_234_ = lean_ctor_get(v_geo_221_, 0);
lean_inc_ref(v_distanceKm_234_);
lean_dec_ref(v_geo_221_);
v_distance_235_ = lean_apply_2(v_distanceKm_234_, v_candidate_224_, v_val_233_);
v___x_236_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_timestamp_223_, v_timestamp_232_);
v_dt_237_ = lp_lean1090_Lean1090_Impl_CPR_absQ(v___x_236_);
v___x_244_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__2, &lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__2);
v_hours_245_ = lp_lean1090_Lean1090_Impl_Binary64_div(v_dt_237_, v___x_244_);
v___x_250_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__4, &lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__4_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__4);
lean_inc_ref(v_dt_237_);
v___x_251_ = l_Rat_blt(v_dt_237_, v___x_250_);
if (v___x_251_ == 0)
{
v___y_247_ = v___x_251_;
goto v___jp_246_;
}
else
{
lean_object* v___x_252_; uint8_t v___x_253_; 
v___x_252_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__5, &lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__5_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__5);
lean_inc_ref(v_hours_245_);
v___x_253_ = l_Rat_blt(v___x_252_, v_hours_245_);
v___y_247_ = v___x_253_;
goto v___jp_246_;
}
v___jp_238_:
{
lean_object* v___x_240_; uint8_t v___x_241_; 
v___x_240_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__0);
v___x_241_ = lp_lean1090_Lean1090_Impl_CPR_Policy_distanceGT(v_distance_235_, v___x_240_);
if (v___x_241_ == 0)
{
lean_dec_ref(v_dt_237_);
v___y_226_ = v___y_239_;
v___y_227_ = v___x_241_;
goto v___jp_225_;
}
else
{
lean_object* v___x_242_; uint8_t v___x_243_; 
v___x_242_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__1);
v___x_243_ = l_Rat_blt(v_dt_237_, v___x_242_);
v___y_226_ = v___y_239_;
v___y_227_ = v___x_243_;
goto v___jp_225_;
}
}
v___jp_246_:
{
if (v___y_247_ == 0)
{
lean_dec_ref(v_hours_245_);
v___y_239_ = v___y_247_;
goto v___jp_238_;
}
else
{
lean_object* v___x_248_; uint8_t v___x_249_; 
v___x_248_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__3);
v___x_249_ = lp_lean1090_Lean1090_Impl_CPR_Policy_speedGT(v_distance_235_, v_hours_245_, v___x_248_);
v___y_239_ = v___x_249_;
goto v___jp_238_;
}
}
}
v___jp_225_:
{
if (v___y_226_ == 0)
{
if (v___y_227_ == 0)
{
uint8_t v___x_228_; 
v___x_228_ = 1;
return v___x_228_;
}
else
{
return v___y_226_;
}
}
else
{
uint8_t v___x_229_; 
v___x_229_ = 0;
return v___x_229_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___boxed(lean_object* v_geo_254_, lean_object* v_state_255_, lean_object* v_timestamp_256_, lean_object* v_candidate_257_){
_start:
{
uint8_t v_res_258_; lean_object* v_r_259_; 
v_res_258_ = lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion(v_geo_254_, v_state_255_, v_timestamp_256_, v_candidate_257_);
v_r_259_ = lean_box(v_res_258_);
return v_r_259_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_stepAirborne___closed__0(void){
_start:
{
lean_object* v___x_260_; lean_object* v___x_261_; 
v___x_260_ = lean_unsigned_to_nat(180u);
v___x_261_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_260_);
return v___x_261_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_stepAirborne(lean_object* v_geo_262_, lean_object* v_updateReference_263_, lean_object* v_state_264_, lean_object* v_reference_265_, lean_object* v_timestamp_266_, lean_object* v_code_267_, lean_object* v_altitude_268_, lean_object* v_metadata_269_){
_start:
{
uint8_t v_odd_270_; lean_object* v___y_272_; uint8_t v___y_273_; lean_object* v_fst_274_; lean_object* v_snd_275_; uint8_t v___y_317_; lean_object* v___y_318_; lean_object* v_val_319_; uint8_t v___y_347_; lean_object* v___y_348_; lean_object* v___y_351_; uint8_t v___y_352_; uint8_t v___y_364_; lean_object* v___y_365_; uint8_t v___x_367_; lean_object* v___y_369_; lean_object* v___y_370_; lean_object* v___y_390_; 
v_odd_270_ = lean_ctor_get_uint8(v_code_267_, sizeof(void*)*2);
v___x_367_ = 1;
if (v_odd_270_ == 0)
{
lean_object* v_oddTimestamp_393_; 
v_oddTimestamp_393_ = lean_ctor_get(v_state_264_, 7);
lean_inc_ref(v_oddTimestamp_393_);
v___y_390_ = v_oddTimestamp_393_;
goto v___jp_389_;
}
else
{
lean_object* v_evenTimestamp_394_; 
v_evenTimestamp_394_ = lean_ctor_get(v_state_264_, 9);
lean_inc_ref(v_evenTimestamp_394_);
v___y_390_ = v_evenTimestamp_394_;
goto v___jp_389_;
}
v___jp_271_:
{
if (v_odd_270_ == 0)
{
lean_object* v_timestamp_276_; lean_object* v_position_277_; lean_object* v_lastAltitude_278_; lean_object* v_airport_279_; lean_object* v_seenBDS_280_; lean_object* v_supportedBDS_281_; lean_object* v_bds17Count_282_; lean_object* v_oddTimestamp_283_; lean_object* v_oddMessage_284_; lean_object* v___x_286_; uint8_t v_isShared_287_; uint8_t v_isSharedCheck_293_; 
v_timestamp_276_ = lean_ctor_get(v_fst_274_, 0);
v_position_277_ = lean_ctor_get(v_fst_274_, 1);
v_lastAltitude_278_ = lean_ctor_get(v_fst_274_, 2);
v_airport_279_ = lean_ctor_get(v_fst_274_, 3);
v_seenBDS_280_ = lean_ctor_get(v_fst_274_, 4);
v_supportedBDS_281_ = lean_ctor_get(v_fst_274_, 5);
v_bds17Count_282_ = lean_ctor_get(v_fst_274_, 6);
v_oddTimestamp_283_ = lean_ctor_get(v_fst_274_, 7);
v_oddMessage_284_ = lean_ctor_get(v_fst_274_, 8);
v_isSharedCheck_293_ = !lean_is_exclusive(v_fst_274_);
if (v_isSharedCheck_293_ == 0)
{
lean_object* v_unused_294_; lean_object* v_unused_295_; 
v_unused_294_ = lean_ctor_get(v_fst_274_, 10);
lean_dec(v_unused_294_);
v_unused_295_ = lean_ctor_get(v_fst_274_, 9);
lean_dec(v_unused_295_);
v___x_286_ = v_fst_274_;
v_isShared_287_ = v_isSharedCheck_293_;
goto v_resetjp_285_;
}
else
{
lean_inc(v_oddMessage_284_);
lean_inc(v_oddTimestamp_283_);
lean_inc(v_bds17Count_282_);
lean_inc(v_supportedBDS_281_);
lean_inc(v_seenBDS_280_);
lean_inc(v_airport_279_);
lean_inc(v_lastAltitude_278_);
lean_inc(v_position_277_);
lean_inc(v_timestamp_276_);
lean_dec(v_fst_274_);
v___x_286_ = lean_box(0);
v_isShared_287_ = v_isSharedCheck_293_;
goto v_resetjp_285_;
}
v_resetjp_285_:
{
lean_object* v___x_288_; lean_object* v___x_290_; 
v___x_288_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_288_, 0, v_code_267_);
if (v_isShared_287_ == 0)
{
lean_ctor_set(v___x_286_, 10, v___x_288_);
lean_ctor_set(v___x_286_, 9, v_timestamp_266_);
v___x_290_ = v___x_286_;
goto v_reusejp_289_;
}
else
{
lean_object* v_reuseFailAlloc_292_; 
v_reuseFailAlloc_292_ = lean_alloc_ctor(0, 11, 0);
lean_ctor_set(v_reuseFailAlloc_292_, 0, v_timestamp_276_);
lean_ctor_set(v_reuseFailAlloc_292_, 1, v_position_277_);
lean_ctor_set(v_reuseFailAlloc_292_, 2, v_lastAltitude_278_);
lean_ctor_set(v_reuseFailAlloc_292_, 3, v_airport_279_);
lean_ctor_set(v_reuseFailAlloc_292_, 4, v_seenBDS_280_);
lean_ctor_set(v_reuseFailAlloc_292_, 5, v_supportedBDS_281_);
lean_ctor_set(v_reuseFailAlloc_292_, 6, v_bds17Count_282_);
lean_ctor_set(v_reuseFailAlloc_292_, 7, v_oddTimestamp_283_);
lean_ctor_set(v_reuseFailAlloc_292_, 8, v_oddMessage_284_);
lean_ctor_set(v_reuseFailAlloc_292_, 9, v_timestamp_266_);
lean_ctor_set(v_reuseFailAlloc_292_, 10, v___x_288_);
v___x_290_ = v_reuseFailAlloc_292_;
goto v_reusejp_289_;
}
v_reusejp_289_:
{
lean_object* v___x_291_; 
v___x_291_ = lean_alloc_ctor(0, 3, 1);
lean_ctor_set(v___x_291_, 0, v___x_290_);
lean_ctor_set(v___x_291_, 1, v_snd_275_);
lean_ctor_set(v___x_291_, 2, v___y_272_);
lean_ctor_set_uint8(v___x_291_, sizeof(void*)*3, v___y_273_);
return v___x_291_;
}
}
}
else
{
lean_object* v_timestamp_296_; lean_object* v_position_297_; lean_object* v_lastAltitude_298_; lean_object* v_airport_299_; lean_object* v_seenBDS_300_; lean_object* v_supportedBDS_301_; lean_object* v_bds17Count_302_; lean_object* v_evenTimestamp_303_; lean_object* v_evenMessage_304_; lean_object* v___x_306_; uint8_t v_isShared_307_; uint8_t v_isSharedCheck_313_; 
v_timestamp_296_ = lean_ctor_get(v_fst_274_, 0);
v_position_297_ = lean_ctor_get(v_fst_274_, 1);
v_lastAltitude_298_ = lean_ctor_get(v_fst_274_, 2);
v_airport_299_ = lean_ctor_get(v_fst_274_, 3);
v_seenBDS_300_ = lean_ctor_get(v_fst_274_, 4);
v_supportedBDS_301_ = lean_ctor_get(v_fst_274_, 5);
v_bds17Count_302_ = lean_ctor_get(v_fst_274_, 6);
v_evenTimestamp_303_ = lean_ctor_get(v_fst_274_, 9);
v_evenMessage_304_ = lean_ctor_get(v_fst_274_, 10);
v_isSharedCheck_313_ = !lean_is_exclusive(v_fst_274_);
if (v_isSharedCheck_313_ == 0)
{
lean_object* v_unused_314_; lean_object* v_unused_315_; 
v_unused_314_ = lean_ctor_get(v_fst_274_, 8);
lean_dec(v_unused_314_);
v_unused_315_ = lean_ctor_get(v_fst_274_, 7);
lean_dec(v_unused_315_);
v___x_306_ = v_fst_274_;
v_isShared_307_ = v_isSharedCheck_313_;
goto v_resetjp_305_;
}
else
{
lean_inc(v_evenMessage_304_);
lean_inc(v_evenTimestamp_303_);
lean_inc(v_bds17Count_302_);
lean_inc(v_supportedBDS_301_);
lean_inc(v_seenBDS_300_);
lean_inc(v_airport_299_);
lean_inc(v_lastAltitude_298_);
lean_inc(v_position_297_);
lean_inc(v_timestamp_296_);
lean_dec(v_fst_274_);
v___x_306_ = lean_box(0);
v_isShared_307_ = v_isSharedCheck_313_;
goto v_resetjp_305_;
}
v_resetjp_305_:
{
lean_object* v___x_308_; lean_object* v___x_310_; 
v___x_308_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_308_, 0, v_code_267_);
if (v_isShared_307_ == 0)
{
lean_ctor_set(v___x_306_, 8, v___x_308_);
lean_ctor_set(v___x_306_, 7, v_timestamp_266_);
v___x_310_ = v___x_306_;
goto v_reusejp_309_;
}
else
{
lean_object* v_reuseFailAlloc_312_; 
v_reuseFailAlloc_312_ = lean_alloc_ctor(0, 11, 0);
lean_ctor_set(v_reuseFailAlloc_312_, 0, v_timestamp_296_);
lean_ctor_set(v_reuseFailAlloc_312_, 1, v_position_297_);
lean_ctor_set(v_reuseFailAlloc_312_, 2, v_lastAltitude_298_);
lean_ctor_set(v_reuseFailAlloc_312_, 3, v_airport_299_);
lean_ctor_set(v_reuseFailAlloc_312_, 4, v_seenBDS_300_);
lean_ctor_set(v_reuseFailAlloc_312_, 5, v_supportedBDS_301_);
lean_ctor_set(v_reuseFailAlloc_312_, 6, v_bds17Count_302_);
lean_ctor_set(v_reuseFailAlloc_312_, 7, v_timestamp_266_);
lean_ctor_set(v_reuseFailAlloc_312_, 8, v___x_308_);
lean_ctor_set(v_reuseFailAlloc_312_, 9, v_evenTimestamp_303_);
lean_ctor_set(v_reuseFailAlloc_312_, 10, v_evenMessage_304_);
v___x_310_ = v_reuseFailAlloc_312_;
goto v_reusejp_309_;
}
v_reusejp_309_:
{
lean_object* v___x_311_; 
v___x_311_ = lean_alloc_ctor(0, 3, 1);
lean_ctor_set(v___x_311_, 0, v___x_310_);
lean_ctor_set(v___x_311_, 1, v_snd_275_);
lean_ctor_set(v___x_311_, 2, v___y_272_);
lean_ctor_set_uint8(v___x_311_, sizeof(void*)*3, v___y_273_);
return v___x_311_;
}
}
}
}
v___jp_316_:
{
uint8_t v___x_320_; 
lean_inc_ref(v_val_319_);
lean_inc_ref(v_timestamp_266_);
lean_inc_ref(v_state_264_);
v___x_320_ = lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion(v_geo_262_, v_state_264_, v_timestamp_266_, v_val_319_);
if (v___x_320_ == 0)
{
lean_object* v___x_321_; 
lean_dec_ref(v_val_319_);
lean_dec(v___y_318_);
lean_dec_ref(v_metadata_269_);
lean_dec(v_altitude_268_);
lean_dec_ref(v_updateReference_263_);
v___x_321_ = lean_box(0);
v___y_272_ = v___x_321_;
v___y_273_ = v___y_317_;
v_fst_274_ = v_state_264_;
v_snd_275_ = v_reference_265_;
goto v___jp_271_;
}
else
{
lean_object* v_seenBDS_322_; lean_object* v_supportedBDS_323_; lean_object* v_bds17Count_324_; lean_object* v_oddTimestamp_325_; lean_object* v_oddMessage_326_; lean_object* v_evenTimestamp_327_; lean_object* v_evenMessage_328_; lean_object* v___x_330_; uint8_t v_isShared_331_; uint8_t v_isSharedCheck_341_; 
v_seenBDS_322_ = lean_ctor_get(v_state_264_, 4);
v_supportedBDS_323_ = lean_ctor_get(v_state_264_, 5);
v_bds17Count_324_ = lean_ctor_get(v_state_264_, 6);
v_oddTimestamp_325_ = lean_ctor_get(v_state_264_, 7);
v_oddMessage_326_ = lean_ctor_get(v_state_264_, 8);
v_evenTimestamp_327_ = lean_ctor_get(v_state_264_, 9);
v_evenMessage_328_ = lean_ctor_get(v_state_264_, 10);
v_isSharedCheck_341_ = !lean_is_exclusive(v_state_264_);
if (v_isSharedCheck_341_ == 0)
{
lean_object* v_unused_342_; lean_object* v_unused_343_; lean_object* v_unused_344_; lean_object* v_unused_345_; 
v_unused_342_ = lean_ctor_get(v_state_264_, 3);
lean_dec(v_unused_342_);
v_unused_343_ = lean_ctor_get(v_state_264_, 2);
lean_dec(v_unused_343_);
v_unused_344_ = lean_ctor_get(v_state_264_, 1);
lean_dec(v_unused_344_);
v_unused_345_ = lean_ctor_get(v_state_264_, 0);
lean_dec(v_unused_345_);
v___x_330_ = v_state_264_;
v_isShared_331_ = v_isSharedCheck_341_;
goto v_resetjp_329_;
}
else
{
lean_inc(v_evenMessage_328_);
lean_inc(v_evenTimestamp_327_);
lean_inc(v_oddMessage_326_);
lean_inc(v_oddTimestamp_325_);
lean_inc(v_bds17Count_324_);
lean_inc(v_supportedBDS_323_);
lean_inc(v_seenBDS_322_);
lean_dec(v_state_264_);
v___x_330_ = lean_box(0);
v_isShared_331_ = v_isSharedCheck_341_;
goto v_resetjp_329_;
}
v_resetjp_329_:
{
lean_object* v___x_332_; lean_object* v___x_333_; lean_object* v___x_334_; lean_object* v___x_336_; 
v___x_332_ = lean_box(0);
v___x_333_ = lean_unsigned_to_nat(5u);
v___x_334_ = lp_lean1090_Lean1090_Impl_CPR_Policy_insertCode(v___x_333_, v_seenBDS_322_);
lean_inc(v_altitude_268_);
lean_inc(v___y_318_);
lean_inc_ref(v_timestamp_266_);
if (v_isShared_331_ == 0)
{
lean_ctor_set(v___x_330_, 4, v___x_334_);
lean_ctor_set(v___x_330_, 3, v___x_332_);
lean_ctor_set(v___x_330_, 2, v_altitude_268_);
lean_ctor_set(v___x_330_, 1, v___y_318_);
lean_ctor_set(v___x_330_, 0, v_timestamp_266_);
v___x_336_ = v___x_330_;
goto v_reusejp_335_;
}
else
{
lean_object* v_reuseFailAlloc_340_; 
v_reuseFailAlloc_340_ = lean_alloc_ctor(0, 11, 0);
lean_ctor_set(v_reuseFailAlloc_340_, 0, v_timestamp_266_);
lean_ctor_set(v_reuseFailAlloc_340_, 1, v___y_318_);
lean_ctor_set(v_reuseFailAlloc_340_, 2, v_altitude_268_);
lean_ctor_set(v_reuseFailAlloc_340_, 3, v___x_332_);
lean_ctor_set(v_reuseFailAlloc_340_, 4, v___x_334_);
lean_ctor_set(v_reuseFailAlloc_340_, 5, v_supportedBDS_323_);
lean_ctor_set(v_reuseFailAlloc_340_, 6, v_bds17Count_324_);
lean_ctor_set(v_reuseFailAlloc_340_, 7, v_oddTimestamp_325_);
lean_ctor_set(v_reuseFailAlloc_340_, 8, v_oddMessage_326_);
lean_ctor_set(v_reuseFailAlloc_340_, 9, v_evenTimestamp_327_);
lean_ctor_set(v_reuseFailAlloc_340_, 10, v_evenMessage_328_);
v___x_336_ = v_reuseFailAlloc_340_;
goto v_reusejp_335_;
}
v_reusejp_335_:
{
lean_object* v___x_337_; lean_object* v___x_338_; uint8_t v___x_339_; 
lean_inc_ref(v_code_267_);
v___x_337_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_337_, 0, v_code_267_);
lean_ctor_set(v___x_337_, 1, v_altitude_268_);
lean_ctor_set(v___x_337_, 2, v_metadata_269_);
lean_ctor_set(v___x_337_, 3, v_val_319_);
v___x_338_ = lean_apply_1(v_updateReference_263_, v___x_337_);
v___x_339_ = lean_unbox(v___x_338_);
if (v___x_339_ == 0)
{
v___y_272_ = v___y_318_;
v___y_273_ = v___y_317_;
v_fst_274_ = v___x_336_;
v_snd_275_ = v_reference_265_;
goto v___jp_271_;
}
else
{
lean_dec(v_reference_265_);
lean_inc(v___y_318_);
v___y_272_ = v___y_318_;
v___y_273_ = v___y_317_;
v_fst_274_ = v___x_336_;
v_snd_275_ = v___y_318_;
goto v___jp_271_;
}
}
}
}
}
v___jp_346_:
{
if (lean_obj_tag(v___y_348_) == 0)
{
lean_dec_ref(v_metadata_269_);
lean_dec(v_altitude_268_);
lean_dec_ref(v_updateReference_263_);
lean_dec_ref(v_geo_262_);
v___y_272_ = v___y_348_;
v___y_273_ = v___y_347_;
v_fst_274_ = v_state_264_;
v_snd_275_ = v_reference_265_;
goto v___jp_271_;
}
else
{
lean_object* v_val_349_; 
v_val_349_ = lean_ctor_get(v___y_348_, 0);
lean_inc(v_val_349_);
v___y_317_ = v___y_347_;
v___y_318_ = v___y_348_;
v_val_319_ = v_val_349_;
goto v___jp_316_;
}
}
v___jp_350_:
{
lean_object* v_timestamp_353_; lean_object* v_position_354_; lean_object* v___x_355_; lean_object* v___x_356_; uint8_t v___x_357_; 
v_timestamp_353_ = lean_ctor_get(v_state_264_, 0);
v_position_354_ = lean_ctor_get(v_state_264_, 1);
lean_inc_ref(v_timestamp_353_);
lean_inc_ref(v_timestamp_266_);
v___x_355_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_timestamp_266_, v_timestamp_353_);
v___x_356_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_stepAirborne___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_stepAirborne___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_stepAirborne___closed__0);
v___x_357_ = l_Rat_blt(v___x_355_, v___x_356_);
if (v___x_357_ == 0)
{
v___y_347_ = v___y_352_;
v___y_348_ = v___y_351_;
goto v___jp_346_;
}
else
{
lean_dec(v___y_351_);
if (lean_obj_tag(v_position_354_) == 0)
{
lean_inc(v_position_354_);
lean_dec_ref(v_metadata_269_);
lean_dec(v_altitude_268_);
lean_dec_ref(v_updateReference_263_);
lean_dec_ref(v_geo_262_);
v___y_272_ = v_position_354_;
v___y_273_ = v___y_352_;
v_fst_274_ = v_state_264_;
v_snd_275_ = v_reference_265_;
goto v___jp_271_;
}
else
{
lean_object* v_val_358_; lean_object* v_localPosition_359_; uint8_t v___x_360_; lean_object* v___x_361_; lean_object* v___x_362_; 
v_val_358_ = lean_ctor_get(v_position_354_, 0);
v_localPosition_359_ = lean_ctor_get(v_geo_262_, 2);
v___x_360_ = 0;
v___x_361_ = lean_box(v___x_360_);
lean_inc_ref(v_localPosition_359_);
lean_inc(v_val_358_);
lean_inc_ref(v_code_267_);
v___x_362_ = lean_apply_3(v_localPosition_359_, v___x_361_, v_code_267_, v_val_358_);
v___y_347_ = v___y_352_;
v___y_348_ = v___x_362_;
goto v___jp_346_;
}
}
}
v___jp_363_:
{
if (lean_obj_tag(v___y_365_) == 0)
{
v___y_351_ = v___y_365_;
v___y_352_ = v___y_364_;
goto v___jp_350_;
}
else
{
if (v___y_364_ == 0)
{
lean_object* v_val_366_; 
v_val_366_ = lean_ctor_get(v___y_365_, 0);
lean_inc(v_val_366_);
v___y_317_ = v___y_364_;
v___y_318_ = v___y_365_;
v_val_319_ = v_val_366_;
goto v___jp_316_;
}
else
{
v___y_351_ = v___y_365_;
v___y_352_ = v___y_364_;
goto v___jp_350_;
}
}
}
v___jp_368_:
{
lean_object* v_gap_371_; lean_object* v___x_372_; uint8_t v___x_373_; 
lean_inc_ref(v_timestamp_266_);
v_gap_371_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_timestamp_266_, v___y_369_);
v___x_372_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__5, &lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__5_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__5);
lean_inc_ref(v_gap_371_);
v___x_373_ = l_Rat_blt(v_gap_371_, v___x_372_);
if (v___x_373_ == 0)
{
lean_object* v___x_374_; lean_object* v___x_375_; uint8_t v___x_376_; 
v___x_374_ = lp_lean1090_Lean1090_Impl_CPR_absQ(v_gap_371_);
v___x_375_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_validMotion___closed__1);
v___x_376_ = l_Rat_blt(v___x_374_, v___x_375_);
if (v___x_376_ == 0)
{
lean_object* v___x_377_; 
lean_dec(v___y_370_);
v___x_377_ = lean_box(0);
v___y_351_ = v___x_377_;
v___y_352_ = v___x_373_;
goto v___jp_350_;
}
else
{
if (lean_obj_tag(v___y_370_) == 0)
{
lean_object* v___x_378_; 
v___x_378_ = lean_box(0);
v___y_351_ = v___x_378_;
v___y_352_ = v___x_373_;
goto v___jp_350_;
}
else
{
if (v_odd_270_ == 0)
{
lean_object* v_val_379_; lean_object* v_globalPosition_380_; lean_object* v___x_381_; lean_object* v___x_382_; 
v_val_379_ = lean_ctor_get(v___y_370_, 0);
lean_inc(v_val_379_);
lean_dec_ref_known(v___y_370_, 1);
v_globalPosition_380_ = lean_ctor_get(v_geo_262_, 3);
v___x_381_ = lean_box(v_odd_270_);
lean_inc_ref(v_globalPosition_380_);
lean_inc_ref(v_code_267_);
v___x_382_ = lean_apply_3(v_globalPosition_380_, v_code_267_, v_val_379_, v___x_381_);
v___y_364_ = v___x_373_;
v___y_365_ = v___x_382_;
goto v___jp_363_;
}
else
{
lean_object* v_val_383_; lean_object* v_globalPosition_384_; lean_object* v___x_385_; lean_object* v___x_386_; 
v_val_383_ = lean_ctor_get(v___y_370_, 0);
lean_inc(v_val_383_);
lean_dec_ref_known(v___y_370_, 1);
v_globalPosition_384_ = lean_ctor_get(v_geo_262_, 3);
v___x_385_ = lean_box(v___x_367_);
lean_inc_ref(v_globalPosition_384_);
lean_inc_ref(v_code_267_);
v___x_386_ = lean_apply_3(v_globalPosition_384_, v_val_383_, v_code_267_, v___x_385_);
v___y_364_ = v___x_373_;
v___y_365_ = v___x_386_;
goto v___jp_363_;
}
}
}
}
else
{
lean_object* v___x_387_; lean_object* v___x_388_; 
lean_dec_ref(v_gap_371_);
lean_dec(v___y_370_);
lean_dec_ref(v_metadata_269_);
lean_dec(v_altitude_268_);
lean_dec_ref(v_code_267_);
lean_dec_ref(v_timestamp_266_);
lean_dec_ref(v_updateReference_263_);
lean_dec_ref(v_geo_262_);
v___x_387_ = lean_box(0);
v___x_388_ = lean_alloc_ctor(0, 3, 1);
lean_ctor_set(v___x_388_, 0, v_state_264_);
lean_ctor_set(v___x_388_, 1, v_reference_265_);
lean_ctor_set(v___x_388_, 2, v___x_387_);
lean_ctor_set_uint8(v___x_388_, sizeof(void*)*3, v___x_367_);
return v___x_388_;
}
}
v___jp_389_:
{
if (v_odd_270_ == 0)
{
lean_object* v_oddMessage_391_; 
v_oddMessage_391_ = lean_ctor_get(v_state_264_, 8);
lean_inc(v_oddMessage_391_);
v___y_369_ = v___y_390_;
v___y_370_ = v_oddMessage_391_;
goto v___jp_368_;
}
else
{
lean_object* v_evenMessage_392_; 
v_evenMessage_392_ = lean_ctor_get(v_state_264_, 10);
lean_inc(v_evenMessage_392_);
v___y_369_ = v___y_390_;
v___y_370_ = v_evenMessage_392_;
goto v___jp_368_;
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_stepSurface___closed__0(void){
_start:
{
lean_object* v___x_395_; lean_object* v___x_396_; 
v___x_395_ = lean_unsigned_to_nat(1u);
v___x_396_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_395_);
return v___x_396_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_stepSurface(lean_object* v_geo_397_, lean_object* v_state_398_, lean_object* v_reference_399_, lean_object* v_timestamp_400_, lean_object* v_code_401_){
_start:
{
lean_object* v___y_403_; lean_object* v_position_406_; lean_object* v_airport_407_; lean_object* v_seenBDS_408_; lean_object* v_supportedBDS_409_; lean_object* v_bds17Count_410_; lean_object* v_oddTimestamp_411_; lean_object* v_oddMessage_412_; lean_object* v_evenTimestamp_413_; lean_object* v_evenMessage_414_; lean_object* v___y_416_; lean_object* v___y_417_; lean_object* v___y_425_; lean_object* v_val_426_; 
v_position_406_ = lean_ctor_get(v_state_398_, 1);
v_airport_407_ = lean_ctor_get(v_state_398_, 3);
v_seenBDS_408_ = lean_ctor_get(v_state_398_, 4);
v_supportedBDS_409_ = lean_ctor_get(v_state_398_, 5);
v_bds17Count_410_ = lean_ctor_get(v_state_398_, 6);
v_oddTimestamp_411_ = lean_ctor_get(v_state_398_, 7);
v_oddMessage_412_ = lean_ctor_get(v_state_398_, 8);
v_evenTimestamp_413_ = lean_ctor_get(v_state_398_, 9);
v_evenMessage_414_ = lean_ctor_get(v_state_398_, 10);
if (lean_obj_tag(v_position_406_) == 0)
{
goto v___jp_428_;
}
else
{
lean_object* v_val_437_; lean_object* v_distanceKm_438_; lean_object* v_localPosition_439_; uint8_t v___x_440_; lean_object* v___x_441_; lean_object* v___x_442_; 
v_val_437_ = lean_ctor_get(v_position_406_, 0);
v_distanceKm_438_ = lean_ctor_get(v_geo_397_, 0);
v_localPosition_439_ = lean_ctor_get(v_geo_397_, 2);
v___x_440_ = 1;
v___x_441_ = lean_box(v___x_440_);
lean_inc_ref(v_localPosition_439_);
lean_inc(v_val_437_);
lean_inc_ref(v_code_401_);
v___x_442_ = lean_apply_3(v_localPosition_439_, v___x_441_, v_code_401_, v_val_437_);
if (lean_obj_tag(v___x_442_) == 0)
{
goto v___jp_428_;
}
else
{
lean_object* v_val_443_; lean_object* v___x_444_; lean_object* v___x_445_; uint8_t v___x_446_; 
v_val_443_ = lean_ctor_get(v___x_442_, 0);
lean_inc_n(v_val_443_, 2);
lean_inc_ref(v_distanceKm_438_);
lean_inc(v_val_437_);
v___x_444_ = lean_apply_2(v_distanceKm_438_, v_val_437_, v_val_443_);
v___x_445_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_stepSurface___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_stepSurface___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_stepSurface___closed__0);
v___x_446_ = lp_lean1090_Lean1090_Impl_CPR_Policy_distanceLT(v___x_444_, v___x_445_);
if (v___x_446_ == 0)
{
lean_dec_ref_known(v___x_442_, 1);
lean_dec(v_val_443_);
goto v___jp_428_;
}
else
{
lean_inc(v_evenMessage_414_);
lean_inc_ref(v_evenTimestamp_413_);
lean_inc(v_oddMessage_412_);
lean_inc_ref(v_oddTimestamp_411_);
lean_inc(v_bds17Count_410_);
lean_inc(v_supportedBDS_409_);
lean_inc(v_seenBDS_408_);
lean_inc(v_airport_407_);
lean_dec_ref(v_code_401_);
lean_dec_ref(v_state_398_);
v___y_425_ = v___x_442_;
v_val_426_ = v_val_443_;
goto v___jp_424_;
}
}
}
v___jp_402_:
{
uint8_t v___x_404_; lean_object* v___x_405_; 
v___x_404_ = 0;
v___x_405_ = lean_alloc_ctor(0, 3, 1);
lean_ctor_set(v___x_405_, 0, v_state_398_);
lean_ctor_set(v___x_405_, 1, v_reference_399_);
lean_ctor_set(v___x_405_, 2, v___y_403_);
lean_ctor_set_uint8(v___x_405_, sizeof(void*)*3, v___x_404_);
return v___x_405_;
}
v___jp_415_:
{
lean_object* v___x_418_; lean_object* v___x_419_; lean_object* v___x_420_; lean_object* v_state_421_; uint8_t v___x_422_; lean_object* v___x_423_; 
v___x_418_ = lean_box(0);
v___x_419_ = lean_unsigned_to_nat(6u);
v___x_420_ = lp_lean1090_Lean1090_Impl_CPR_Policy_insertCode(v___x_419_, v_seenBDS_408_);
lean_inc(v___y_416_);
v_state_421_ = lean_alloc_ctor(0, 11, 0);
lean_ctor_set(v_state_421_, 0, v_timestamp_400_);
lean_ctor_set(v_state_421_, 1, v___y_416_);
lean_ctor_set(v_state_421_, 2, v___x_418_);
lean_ctor_set(v_state_421_, 3, v___y_417_);
lean_ctor_set(v_state_421_, 4, v___x_420_);
lean_ctor_set(v_state_421_, 5, v_supportedBDS_409_);
lean_ctor_set(v_state_421_, 6, v_bds17Count_410_);
lean_ctor_set(v_state_421_, 7, v_oddTimestamp_411_);
lean_ctor_set(v_state_421_, 8, v_oddMessage_412_);
lean_ctor_set(v_state_421_, 9, v_evenTimestamp_413_);
lean_ctor_set(v_state_421_, 10, v_evenMessage_414_);
v___x_422_ = 0;
v___x_423_ = lean_alloc_ctor(0, 3, 1);
lean_ctor_set(v___x_423_, 0, v_state_421_);
lean_ctor_set(v___x_423_, 1, v_reference_399_);
lean_ctor_set(v___x_423_, 2, v___y_416_);
lean_ctor_set_uint8(v___x_423_, sizeof(void*)*3, v___x_422_);
return v___x_423_;
}
v___jp_424_:
{
if (lean_obj_tag(v_airport_407_) == 0)
{
lean_object* v___x_427_; 
v___x_427_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nearestAirport(v_geo_397_, v_val_426_);
v___y_416_ = v___y_425_;
v___y_417_ = v___x_427_;
goto v___jp_415_;
}
else
{
lean_dec_ref(v_val_426_);
lean_dec_ref(v_geo_397_);
v___y_416_ = v___y_425_;
v___y_417_ = v_airport_407_;
goto v___jp_415_;
}
}
v___jp_428_:
{
if (lean_obj_tag(v_reference_399_) == 0)
{
lean_dec_ref(v_code_401_);
lean_dec_ref(v_timestamp_400_);
lean_dec_ref(v_geo_397_);
v___y_403_ = v_reference_399_;
goto v___jp_402_;
}
else
{
lean_object* v_val_429_; lean_object* v_localPosition_430_; uint8_t v___x_431_; lean_object* v___x_432_; lean_object* v___x_433_; 
v_val_429_ = lean_ctor_get(v_reference_399_, 0);
v_localPosition_430_ = lean_ctor_get(v_geo_397_, 2);
v___x_431_ = 1;
v___x_432_ = lean_box(v___x_431_);
lean_inc_ref(v_localPosition_430_);
lean_inc(v_val_429_);
v___x_433_ = lean_apply_3(v_localPosition_430_, v___x_432_, v_code_401_, v_val_429_);
if (lean_obj_tag(v___x_433_) == 0)
{
lean_dec_ref(v_timestamp_400_);
lean_dec_ref(v_geo_397_);
v___y_403_ = v___x_433_;
goto v___jp_402_;
}
else
{
if (lean_obj_tag(v_position_406_) == 0)
{
lean_object* v_val_434_; uint8_t v___x_435_; 
v_val_434_ = lean_ctor_get(v___x_433_, 0);
lean_inc_n(v_val_434_, 2);
lean_inc_ref(v_geo_397_);
v___x_435_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nearAirport(v_geo_397_, v_val_434_);
if (v___x_435_ == 0)
{
lean_dec(v_val_434_);
lean_dec_ref_known(v___x_433_, 1);
lean_dec_ref(v_timestamp_400_);
lean_dec_ref(v_geo_397_);
v___y_403_ = v_position_406_;
goto v___jp_402_;
}
else
{
lean_inc(v_evenMessage_414_);
lean_inc_ref(v_evenTimestamp_413_);
lean_inc(v_oddMessage_412_);
lean_inc_ref(v_oddTimestamp_411_);
lean_inc(v_bds17Count_410_);
lean_inc(v_supportedBDS_409_);
lean_inc(v_seenBDS_408_);
lean_inc(v_airport_407_);
lean_dec_ref(v_state_398_);
v___y_425_ = v___x_433_;
v_val_426_ = v_val_434_;
goto v___jp_424_;
}
}
else
{
lean_object* v_val_436_; 
lean_inc(v_evenMessage_414_);
lean_inc_ref(v_evenTimestamp_413_);
lean_inc(v_oddMessage_412_);
lean_inc_ref(v_oddTimestamp_411_);
lean_inc(v_bds17Count_410_);
lean_inc(v_supportedBDS_409_);
lean_inc(v_seenBDS_408_);
lean_inc(v_airport_407_);
lean_dec_ref(v_state_398_);
v_val_436_ = lean_ctor_get(v___x_433_, 0);
lean_inc(v_val_436_);
v___y_425_ = v___x_433_;
v_val_426_ = v_val_436_;
goto v___jp_424_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode(uint8_t v_x_457_){
_start:
{
switch(v_x_457_)
{
case 0:
{
lean_object* v___x_458_; 
v___x_458_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__0));
return v___x_458_;
}
case 1:
{
lean_object* v___x_459_; 
v___x_459_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__1));
return v___x_459_;
}
case 2:
{
lean_object* v___x_460_; 
v___x_460_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__2));
return v___x_460_;
}
case 3:
{
lean_object* v___x_461_; 
v___x_461_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__3));
return v___x_461_;
}
case 4:
{
lean_object* v___x_462_; 
v___x_462_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___closed__4));
return v___x_462_;
}
default: 
{
lean_object* v___x_463_; 
v___x_463_ = lean_box(0);
return v___x_463_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode___boxed(lean_object* v_x_464_){
_start:
{
uint8_t v_x_91__boxed_465_; lean_object* v_res_466_; 
v_x_91__boxed_465_ = lean_unbox(v_x_464_);
v_res_466_ = lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode(v_x_91__boxed_465_);
return v_res_466_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_step(lean_object* v_geo_467_, lean_object* v_updateReference_468_, lean_object* v_state_469_, lean_object* v_reference_470_, lean_object* v_timestamp_471_, lean_object* v_message_472_){
_start:
{
lean_object* v___y_474_; 
switch(lean_obj_tag(v_message_472_))
{
case 0:
{
lean_object* v_code_478_; lean_object* v_altitude_479_; lean_object* v_metadata_480_; lean_object* v___x_481_; 
v_code_478_ = lean_ctor_get(v_message_472_, 0);
lean_inc_ref(v_code_478_);
v_altitude_479_ = lean_ctor_get(v_message_472_, 1);
lean_inc(v_altitude_479_);
v_metadata_480_ = lean_ctor_get(v_message_472_, 2);
lean_inc_ref(v_metadata_480_);
lean_dec_ref_known(v_message_472_, 3);
v___x_481_ = lp_lean1090_Lean1090_Impl_CPR_Policy_stepAirborne(v_geo_467_, v_updateReference_468_, v_state_469_, v_reference_470_, v_timestamp_471_, v_code_478_, v_altitude_479_, v_metadata_480_);
return v___x_481_;
}
case 1:
{
lean_object* v_code_482_; lean_object* v___x_483_; 
lean_dec_ref(v_updateReference_468_);
v_code_482_ = lean_ctor_get(v_message_472_, 0);
lean_inc_ref(v_code_482_);
lean_dec_ref_known(v_message_472_, 1);
v___x_483_ = lp_lean1090_Lean1090_Impl_CPR_Policy_stepSurface(v_geo_467_, v_state_469_, v_reference_470_, v_timestamp_471_, v_code_482_);
return v___x_483_;
}
default: 
{
uint8_t v_kind_484_; lean_object* v___x_485_; 
lean_dec_ref(v_timestamp_471_);
lean_dec_ref(v_updateReference_468_);
lean_dec_ref(v_geo_467_);
v_kind_484_ = lean_ctor_get_uint8(v_message_472_, 0);
lean_dec_ref_known(v_message_472_, 0);
v___x_485_ = lp_lean1090_Lean1090_Impl_CPR_Policy_otherCode(v_kind_484_);
if (lean_obj_tag(v___x_485_) == 0)
{
v___y_474_ = v_state_469_;
goto v___jp_473_;
}
else
{
lean_object* v_val_486_; lean_object* v_timestamp_487_; lean_object* v_position_488_; lean_object* v_lastAltitude_489_; lean_object* v_airport_490_; lean_object* v_seenBDS_491_; lean_object* v_supportedBDS_492_; lean_object* v_bds17Count_493_; lean_object* v_oddTimestamp_494_; lean_object* v_oddMessage_495_; lean_object* v_evenTimestamp_496_; lean_object* v_evenMessage_497_; lean_object* v___x_499_; uint8_t v_isShared_500_; uint8_t v_isSharedCheck_505_; 
v_val_486_ = lean_ctor_get(v___x_485_, 0);
lean_inc(v_val_486_);
lean_dec_ref_known(v___x_485_, 1);
v_timestamp_487_ = lean_ctor_get(v_state_469_, 0);
v_position_488_ = lean_ctor_get(v_state_469_, 1);
v_lastAltitude_489_ = lean_ctor_get(v_state_469_, 2);
v_airport_490_ = lean_ctor_get(v_state_469_, 3);
v_seenBDS_491_ = lean_ctor_get(v_state_469_, 4);
v_supportedBDS_492_ = lean_ctor_get(v_state_469_, 5);
v_bds17Count_493_ = lean_ctor_get(v_state_469_, 6);
v_oddTimestamp_494_ = lean_ctor_get(v_state_469_, 7);
v_oddMessage_495_ = lean_ctor_get(v_state_469_, 8);
v_evenTimestamp_496_ = lean_ctor_get(v_state_469_, 9);
v_evenMessage_497_ = lean_ctor_get(v_state_469_, 10);
v_isSharedCheck_505_ = !lean_is_exclusive(v_state_469_);
if (v_isSharedCheck_505_ == 0)
{
v___x_499_ = v_state_469_;
v_isShared_500_ = v_isSharedCheck_505_;
goto v_resetjp_498_;
}
else
{
lean_inc(v_evenMessage_497_);
lean_inc(v_evenTimestamp_496_);
lean_inc(v_oddMessage_495_);
lean_inc(v_oddTimestamp_494_);
lean_inc(v_bds17Count_493_);
lean_inc(v_supportedBDS_492_);
lean_inc(v_seenBDS_491_);
lean_inc(v_airport_490_);
lean_inc(v_lastAltitude_489_);
lean_inc(v_position_488_);
lean_inc(v_timestamp_487_);
lean_dec(v_state_469_);
v___x_499_ = lean_box(0);
v_isShared_500_ = v_isSharedCheck_505_;
goto v_resetjp_498_;
}
v_resetjp_498_:
{
lean_object* v___x_501_; lean_object* v___x_503_; 
v___x_501_ = lp_lean1090_Lean1090_Impl_CPR_Policy_insertCode(v_val_486_, v_seenBDS_491_);
if (v_isShared_500_ == 0)
{
lean_ctor_set(v___x_499_, 4, v___x_501_);
v___x_503_ = v___x_499_;
goto v_reusejp_502_;
}
else
{
lean_object* v_reuseFailAlloc_504_; 
v_reuseFailAlloc_504_ = lean_alloc_ctor(0, 11, 0);
lean_ctor_set(v_reuseFailAlloc_504_, 0, v_timestamp_487_);
lean_ctor_set(v_reuseFailAlloc_504_, 1, v_position_488_);
lean_ctor_set(v_reuseFailAlloc_504_, 2, v_lastAltitude_489_);
lean_ctor_set(v_reuseFailAlloc_504_, 3, v_airport_490_);
lean_ctor_set(v_reuseFailAlloc_504_, 4, v___x_501_);
lean_ctor_set(v_reuseFailAlloc_504_, 5, v_supportedBDS_492_);
lean_ctor_set(v_reuseFailAlloc_504_, 6, v_bds17Count_493_);
lean_ctor_set(v_reuseFailAlloc_504_, 7, v_oddTimestamp_494_);
lean_ctor_set(v_reuseFailAlloc_504_, 8, v_oddMessage_495_);
lean_ctor_set(v_reuseFailAlloc_504_, 9, v_evenTimestamp_496_);
lean_ctor_set(v_reuseFailAlloc_504_, 10, v_evenMessage_497_);
v___x_503_ = v_reuseFailAlloc_504_;
goto v_reusejp_502_;
}
v_reusejp_502_:
{
v___y_474_ = v___x_503_;
goto v___jp_473_;
}
}
}
}
}
v___jp_473_:
{
lean_object* v___x_475_; uint8_t v___x_476_; lean_object* v___x_477_; 
v___x_475_ = lean_box(0);
v___x_476_ = 0;
v___x_477_ = lean_alloc_ctor(0, 3, 1);
lean_ctor_set(v___x_477_, 0, v___y_474_);
lean_ctor_set(v___x_477_, 1, v_reference_470_);
lean_ctor_set(v___x_477_, 2, v___x_475_);
lean_ctor_set_uint8(v___x_477_, sizeof(void*)*3, v___x_476_);
return v___x_477_;
}
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_lowerAltitude(lean_object* v_a_506_, lean_object* v_b_507_){
_start:
{
if (lean_obj_tag(v_a_506_) == 0)
{
if (lean_obj_tag(v_b_507_) == 1)
{
uint8_t v___x_508_; 
v___x_508_ = 1;
return v___x_508_;
}
else
{
uint8_t v___x_509_; 
v___x_509_ = 0;
return v___x_509_;
}
}
else
{
if (lean_obj_tag(v_b_507_) == 1)
{
lean_object* v_val_510_; lean_object* v_val_511_; uint8_t v___x_512_; 
v_val_510_ = lean_ctor_get(v_a_506_, 0);
v_val_511_ = lean_ctor_get(v_b_507_, 0);
v___x_512_ = lean_int_dec_lt(v_val_510_, v_val_511_);
return v___x_512_;
}
else
{
uint8_t v___x_513_; 
v___x_513_ = 0;
return v___x_513_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_lowerAltitude___boxed(lean_object* v_a_514_, lean_object* v_b_515_){
_start:
{
uint8_t v_res_516_; lean_object* v_r_517_; 
v_res_516_ = lp_lean1090_Lean1090_Impl_CPR_Policy_lowerAltitude(v_a_514_, v_b_515_);
lean_dec(v_b_515_);
lean_dec(v_a_514_);
v_r_517_ = lean_box(v_res_516_);
return v_r_517_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_CPR_Policy_updateGlobalReference___lam__0(lean_object* v_a_518_, lean_object* v_b_519_){
_start:
{
lean_object* v_fst_520_; lean_object* v_fst_521_; uint8_t v___x_522_; 
v_fst_520_ = lean_ctor_get(v_a_518_, 0);
v_fst_521_ = lean_ctor_get(v_b_519_, 0);
v___x_522_ = lean_nat_dec_le(v_fst_520_, v_fst_521_);
return v___x_522_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_updateGlobalReference___lam__0___boxed(lean_object* v_a_523_, lean_object* v_b_524_){
_start:
{
uint8_t v_res_525_; lean_object* v_r_526_; 
v_res_525_ = lp_lean1090_Lean1090_Impl_CPR_Policy_updateGlobalReference___lam__0(v_a_523_, v_b_524_);
lean_dec_ref(v_b_524_);
lean_dec_ref(v_a_523_);
v_r_526_ = lean_box(v_res_525_);
return v_r_526_;
}
}
static lean_object* _init_lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateGlobalReference_spec__0___closed__0(void){
_start:
{
lean_object* v___x_527_; lean_object* v___x_528_; 
v___x_527_ = lean_unsigned_to_nat(300u);
v___x_528_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_527_);
return v___x_528_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateGlobalReference_spec__0(lean_object* v_timestamp_529_, lean_object* v_x_530_, lean_object* v_x_531_){
_start:
{
if (lean_obj_tag(v_x_531_) == 0)
{
lean_dec_ref(v_timestamp_529_);
return v_x_530_;
}
else
{
lean_object* v_head_532_; lean_object* v_snd_533_; lean_object* v___x_535_; uint8_t v_isShared_536_; uint8_t v_isSharedCheck_574_; 
v_head_532_ = lean_ctor_get(v_x_531_, 0);
lean_inc(v_head_532_);
v_snd_533_ = lean_ctor_get(v_head_532_, 1);
v_isSharedCheck_574_ = !lean_is_exclusive(v_head_532_);
if (v_isSharedCheck_574_ == 0)
{
lean_object* v_unused_575_; 
v_unused_575_ = lean_ctor_get(v_head_532_, 0);
lean_dec(v_unused_575_);
v___x_535_ = v_head_532_;
v_isShared_536_ = v_isSharedCheck_574_;
goto v_resetjp_534_;
}
else
{
lean_inc(v_snd_533_);
lean_dec(v_head_532_);
v___x_535_ = lean_box(0);
v_isShared_536_ = v_isSharedCheck_574_;
goto v_resetjp_534_;
}
v_resetjp_534_:
{
lean_object* v_tail_537_; lean_object* v___x_539_; uint8_t v_isShared_540_; uint8_t v_isSharedCheck_572_; 
v_tail_537_ = lean_ctor_get(v_x_531_, 1);
v_isSharedCheck_572_ = !lean_is_exclusive(v_x_531_);
if (v_isSharedCheck_572_ == 0)
{
lean_object* v_unused_573_; 
v_unused_573_ = lean_ctor_get(v_x_531_, 0);
lean_dec(v_unused_573_);
v___x_539_ = v_x_531_;
v_isShared_540_ = v_isSharedCheck_572_;
goto v_resetjp_538_;
}
else
{
lean_inc(v_tail_537_);
lean_dec(v_x_531_);
v___x_539_ = lean_box(0);
v_isShared_540_ = v_isSharedCheck_572_;
goto v_resetjp_538_;
}
v_resetjp_538_:
{
lean_object* v_timestamp_541_; lean_object* v_position_542_; lean_object* v_lastAltitude_543_; lean_object* v___x_544_; lean_object* v___x_545_; uint8_t v___x_546_; 
v_timestamp_541_ = lean_ctor_get(v_snd_533_, 0);
lean_inc_ref(v_timestamp_541_);
v_position_542_ = lean_ctor_get(v_snd_533_, 1);
lean_inc(v_position_542_);
v_lastAltitude_543_ = lean_ctor_get(v_snd_533_, 2);
lean_inc(v_lastAltitude_543_);
lean_dec(v_snd_533_);
lean_inc_ref(v_timestamp_529_);
v___x_544_ = lp_lean1090_Lean1090_Impl_Binary64_sub(v_timestamp_529_, v_timestamp_541_);
v___x_545_ = lean_obj_once(&lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateGlobalReference_spec__0___closed__0, &lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateGlobalReference_spec__0___closed__0_once, _init_lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateGlobalReference_spec__0___closed__0);
v___x_546_ = l_Rat_blt(v___x_544_, v___x_545_);
if (v___x_546_ == 0)
{
lean_dec(v_lastAltitude_543_);
lean_dec(v_position_542_);
lean_del_object(v___x_539_);
lean_del_object(v___x_535_);
v_x_531_ = v_tail_537_;
goto _start;
}
else
{
if (lean_obj_tag(v_position_542_) == 0)
{
lean_dec(v_lastAltitude_543_);
lean_del_object(v___x_539_);
lean_del_object(v___x_535_);
v_x_531_ = v_tail_537_;
goto _start;
}
else
{
lean_object* v_val_549_; lean_object* v___x_551_; uint8_t v_isShared_552_; uint8_t v_isSharedCheck_571_; 
v_val_549_ = lean_ctor_get(v_position_542_, 0);
v_isSharedCheck_571_ = !lean_is_exclusive(v_position_542_);
if (v_isSharedCheck_571_ == 0)
{
v___x_551_ = v_position_542_;
v_isShared_552_ = v_isSharedCheck_571_;
goto v_resetjp_550_;
}
else
{
lean_inc(v_val_549_);
lean_dec(v_position_542_);
v___x_551_ = lean_box(0);
v_isShared_552_ = v_isSharedCheck_571_;
goto v_resetjp_550_;
}
v_resetjp_550_:
{
uint8_t v___y_554_; 
if (lean_obj_tag(v_x_530_) == 0)
{
lean_object* v___x_564_; 
lean_del_object(v___x_551_);
lean_del_object(v___x_535_);
if (v_isShared_540_ == 0)
{
lean_ctor_set_tag(v___x_539_, 0);
lean_ctor_set(v___x_539_, 1, v_val_549_);
lean_ctor_set(v___x_539_, 0, v_lastAltitude_543_);
v___x_564_ = v___x_539_;
goto v_reusejp_563_;
}
else
{
lean_object* v_reuseFailAlloc_567_; 
v_reuseFailAlloc_567_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_567_, 0, v_lastAltitude_543_);
lean_ctor_set(v_reuseFailAlloc_567_, 1, v_val_549_);
v___x_564_ = v_reuseFailAlloc_567_;
goto v_reusejp_563_;
}
v_reusejp_563_:
{
lean_object* v___x_565_; 
v___x_565_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_565_, 0, v___x_564_);
v_x_530_ = v___x_565_;
v_x_531_ = v_tail_537_;
goto _start;
}
}
else
{
lean_del_object(v___x_539_);
if (v___x_546_ == 0)
{
v___y_554_ = v___x_546_;
goto v___jp_553_;
}
else
{
lean_object* v_val_568_; lean_object* v_fst_569_; uint8_t v___x_570_; 
v_val_568_ = lean_ctor_get(v_x_530_, 0);
v_fst_569_ = lean_ctor_get(v_val_568_, 0);
v___x_570_ = lp_lean1090_Lean1090_Impl_CPR_Policy_lowerAltitude(v_lastAltitude_543_, v_fst_569_);
v___y_554_ = v___x_570_;
goto v___jp_553_;
}
}
v___jp_553_:
{
if (v___y_554_ == 0)
{
lean_del_object(v___x_551_);
lean_dec(v_val_549_);
lean_dec(v_lastAltitude_543_);
lean_del_object(v___x_535_);
v_x_531_ = v_tail_537_;
goto _start;
}
else
{
lean_object* v___x_557_; 
lean_dec(v_x_530_);
if (v_isShared_536_ == 0)
{
lean_ctor_set(v___x_535_, 1, v_val_549_);
lean_ctor_set(v___x_535_, 0, v_lastAltitude_543_);
v___x_557_ = v___x_535_;
goto v_reusejp_556_;
}
else
{
lean_object* v_reuseFailAlloc_562_; 
v_reuseFailAlloc_562_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_562_, 0, v_lastAltitude_543_);
lean_ctor_set(v_reuseFailAlloc_562_, 1, v_val_549_);
v___x_557_ = v_reuseFailAlloc_562_;
goto v_reusejp_556_;
}
v_reusejp_556_:
{
lean_object* v___x_559_; 
if (v_isShared_552_ == 0)
{
lean_ctor_set(v___x_551_, 0, v___x_557_);
v___x_559_ = v___x_551_;
goto v_reusejp_558_;
}
else
{
lean_object* v_reuseFailAlloc_561_; 
v_reuseFailAlloc_561_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_561_, 0, v___x_557_);
v___x_559_ = v_reuseFailAlloc_561_;
goto v_reusejp_558_;
}
v_reusejp_558_:
{
v_x_530_ = v___x_559_;
v_x_531_ = v_tail_537_;
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
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_updateGlobalReference(lean_object* v_aircraft_577_, lean_object* v_reference_578_, lean_object* v_timestamp_579_){
_start:
{
lean_object* v___f_580_; lean_object* v_ordered_581_; lean_object* v___x_582_; lean_object* v_best_583_; 
v___f_580_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_updateGlobalReference___closed__0));
v_ordered_581_ = l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(v_aircraft_577_, v___f_580_);
v___x_582_ = lean_box(0);
v_best_583_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_updateGlobalReference_spec__0(v_timestamp_579_, v___x_582_, v_ordered_581_);
if (lean_obj_tag(v_best_583_) == 0)
{
uint8_t v___x_584_; lean_object* v___x_585_; lean_object* v___x_586_; 
v___x_584_ = 0;
v___x_585_ = lean_box(v___x_584_);
v___x_586_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_586_, 0, v_reference_578_);
lean_ctor_set(v___x_586_, 1, v___x_585_);
return v___x_586_;
}
else
{
lean_object* v_val_587_; lean_object* v___x_589_; uint8_t v_isShared_590_; uint8_t v_isSharedCheck_605_; 
lean_dec(v_reference_578_);
v_val_587_ = lean_ctor_get(v_best_583_, 0);
v_isSharedCheck_605_ = !lean_is_exclusive(v_best_583_);
if (v_isSharedCheck_605_ == 0)
{
v___x_589_ = v_best_583_;
v_isShared_590_ = v_isSharedCheck_605_;
goto v_resetjp_588_;
}
else
{
lean_inc(v_val_587_);
lean_dec(v_best_583_);
v___x_589_ = lean_box(0);
v_isShared_590_ = v_isSharedCheck_605_;
goto v_resetjp_588_;
}
v_resetjp_588_:
{
lean_object* v_snd_591_; lean_object* v___x_593_; uint8_t v_isShared_594_; uint8_t v_isSharedCheck_603_; 
v_snd_591_ = lean_ctor_get(v_val_587_, 1);
v_isSharedCheck_603_ = !lean_is_exclusive(v_val_587_);
if (v_isSharedCheck_603_ == 0)
{
lean_object* v_unused_604_; 
v_unused_604_ = lean_ctor_get(v_val_587_, 0);
lean_dec(v_unused_604_);
v___x_593_ = v_val_587_;
v_isShared_594_ = v_isSharedCheck_603_;
goto v_resetjp_592_;
}
else
{
lean_inc(v_snd_591_);
lean_dec(v_val_587_);
v___x_593_ = lean_box(0);
v_isShared_594_ = v_isSharedCheck_603_;
goto v_resetjp_592_;
}
v_resetjp_592_:
{
lean_object* v___x_596_; 
if (v_isShared_590_ == 0)
{
lean_ctor_set(v___x_589_, 0, v_snd_591_);
v___x_596_ = v___x_589_;
goto v_reusejp_595_;
}
else
{
lean_object* v_reuseFailAlloc_602_; 
v_reuseFailAlloc_602_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_602_, 0, v_snd_591_);
v___x_596_ = v_reuseFailAlloc_602_;
goto v_reusejp_595_;
}
v_reusejp_595_:
{
uint8_t v___x_597_; lean_object* v___x_598_; lean_object* v___x_600_; 
v___x_597_ = 1;
v___x_598_ = lean_box(v___x_597_);
if (v_isShared_594_ == 0)
{
lean_ctor_set(v___x_593_, 1, v___x_598_);
lean_ctor_set(v___x_593_, 0, v___x_596_);
v___x_600_ = v___x_593_;
goto v_reusejp_599_;
}
else
{
lean_object* v_reuseFailAlloc_601_; 
v_reuseFailAlloc_601_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_601_, 0, v___x_596_);
lean_ctor_set(v_reuseFailAlloc_601_, 1, v___x_598_);
v___x_600_ = v_reuseFailAlloc_601_;
goto v_reusejp_599_;
}
v_reusejp_599_:
{
return v___x_600_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_CPR_Policy_streamStep_spec__0(lean_object* v_report_606_, lean_object* v_a_607_, lean_object* v_a_608_){
_start:
{
if (lean_obj_tag(v_a_607_) == 0)
{
lean_object* v___x_609_; 
v___x_609_ = l_List_reverse___redArg(v_a_608_);
return v___x_609_;
}
else
{
lean_object* v_head_610_; lean_object* v_tail_611_; lean_object* v___x_613_; uint8_t v_isShared_614_; uint8_t v_isSharedCheck_623_; 
v_head_610_ = lean_ctor_get(v_a_607_, 0);
v_tail_611_ = lean_ctor_get(v_a_607_, 1);
v_isSharedCheck_623_ = !lean_is_exclusive(v_a_607_);
if (v_isSharedCheck_623_ == 0)
{
v___x_613_ = v_a_607_;
v_isShared_614_ = v_isSharedCheck_623_;
goto v_resetjp_612_;
}
else
{
lean_inc(v_tail_611_);
lean_inc(v_head_610_);
lean_dec(v_a_607_);
v___x_613_ = lean_box(0);
v_isShared_614_ = v_isSharedCheck_623_;
goto v_resetjp_612_;
}
v_resetjp_612_:
{
lean_object* v_fst_615_; lean_object* v_address_616_; uint8_t v___x_617_; 
v_fst_615_ = lean_ctor_get(v_head_610_, 0);
v_address_616_ = lean_ctor_get(v_report_606_, 0);
v___x_617_ = lean_nat_dec_eq(v_fst_615_, v_address_616_);
if (v___x_617_ == 0)
{
lean_object* v___x_619_; 
if (v_isShared_614_ == 0)
{
lean_ctor_set(v___x_613_, 1, v_a_608_);
v___x_619_ = v___x_613_;
goto v_reusejp_618_;
}
else
{
lean_object* v_reuseFailAlloc_621_; 
v_reuseFailAlloc_621_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_621_, 0, v_head_610_);
lean_ctor_set(v_reuseFailAlloc_621_, 1, v_a_608_);
v___x_619_ = v_reuseFailAlloc_621_;
goto v_reusejp_618_;
}
v_reusejp_618_:
{
v_a_607_ = v_tail_611_;
v_a_608_ = v___x_619_;
goto _start;
}
}
else
{
lean_del_object(v___x_613_);
lean_dec(v_head_610_);
v_a_607_ = v_tail_611_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_CPR_Policy_streamStep_spec__0___boxed(lean_object* v_report_624_, lean_object* v_a_625_, lean_object* v_a_626_){
_start:
{
lean_object* v_res_627_; 
v_res_627_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_CPR_Policy_streamStep_spec__0(v_report_624_, v_a_625_, v_a_626_);
lean_dec_ref(v_report_624_);
return v_res_627_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_CPR_Policy_streamStep_spec__1(lean_object* v_report_628_, lean_object* v_x_629_){
_start:
{
if (lean_obj_tag(v_x_629_) == 0)
{
lean_object* v___x_630_; 
v___x_630_ = lean_box(0);
return v___x_630_;
}
else
{
lean_object* v_head_631_; lean_object* v_tail_632_; lean_object* v_fst_633_; lean_object* v_address_634_; uint8_t v___x_635_; 
v_head_631_ = lean_ctor_get(v_x_629_, 0);
v_tail_632_ = lean_ctor_get(v_x_629_, 1);
v_fst_633_ = lean_ctor_get(v_head_631_, 0);
v_address_634_ = lean_ctor_get(v_report_628_, 0);
v___x_635_ = lean_nat_dec_eq(v_fst_633_, v_address_634_);
if (v___x_635_ == 0)
{
v_x_629_ = v_tail_632_;
goto _start;
}
else
{
lean_object* v___x_637_; 
lean_inc(v_head_631_);
v___x_637_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_637_, 0, v_head_631_);
return v___x_637_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_find_x3f___at___00Lean1090_Impl_CPR_Policy_streamStep_spec__1___boxed(lean_object* v_report_638_, lean_object* v_x_639_){
_start:
{
lean_object* v_res_640_; 
v_res_640_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_CPR_Policy_streamStep_spec__1(v_report_638_, v_x_639_);
lean_dec(v_x_639_);
lean_dec_ref(v_report_638_);
return v_res_640_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_streamStep(lean_object* v_geo_641_, lean_object* v_updateReference_642_, lean_object* v_stream_643_, lean_object* v_report_644_){
_start:
{
lean_object* v_aircraft_645_; lean_object* v_reference_646_; lean_object* v___x_648_; uint8_t v_isShared_649_; uint8_t v_isSharedCheck_672_; 
v_aircraft_645_ = lean_ctor_get(v_stream_643_, 0);
v_reference_646_ = lean_ctor_get(v_stream_643_, 1);
v_isSharedCheck_672_ = !lean_is_exclusive(v_stream_643_);
if (v_isSharedCheck_672_ == 0)
{
v___x_648_ = v_stream_643_;
v_isShared_649_ = v_isSharedCheck_672_;
goto v_resetjp_647_;
}
else
{
lean_inc(v_reference_646_);
lean_inc(v_aircraft_645_);
lean_dec(v_stream_643_);
v___x_648_ = lean_box(0);
v_isShared_649_ = v_isSharedCheck_672_;
goto v_resetjp_647_;
}
v_resetjp_647_:
{
lean_object* v___y_651_; lean_object* v___x_667_; 
v___x_667_ = lp_lean1090_List_find_x3f___at___00Lean1090_Impl_CPR_Policy_streamStep_spec__1(v_report_644_, v_aircraft_645_);
if (lean_obj_tag(v___x_667_) == 0)
{
lean_object* v_timestamp_668_; lean_object* v___x_669_; 
v_timestamp_668_ = lean_ctor_get(v_report_644_, 1);
lean_inc_ref(v_timestamp_668_);
v___x_669_ = lp_lean1090_Lean1090_Impl_CPR_Policy_initial(v_timestamp_668_);
v___y_651_ = v___x_669_;
goto v___jp_650_;
}
else
{
lean_object* v_val_670_; lean_object* v_snd_671_; 
v_val_670_ = lean_ctor_get(v___x_667_, 0);
lean_inc(v_val_670_);
lean_dec_ref_known(v___x_667_, 1);
v_snd_671_ = lean_ctor_get(v_val_670_, 1);
lean_inc(v_snd_671_);
lean_dec(v_val_670_);
v___y_651_ = v_snd_671_;
goto v___jp_650_;
}
v___jp_650_:
{
lean_object* v_address_652_; lean_object* v_timestamp_653_; lean_object* v_message_654_; lean_object* v_result_655_; lean_object* v_state_656_; lean_object* v_reference_657_; lean_object* v_resolved_658_; lean_object* v___x_659_; lean_object* v_remaining_660_; lean_object* v___x_661_; lean_object* v___x_662_; lean_object* v___x_664_; 
v_address_652_ = lean_ctor_get(v_report_644_, 0);
lean_inc(v_address_652_);
v_timestamp_653_ = lean_ctor_get(v_report_644_, 1);
v_message_654_ = lean_ctor_get(v_report_644_, 2);
lean_inc_ref(v_message_654_);
lean_inc_ref(v_timestamp_653_);
v_result_655_ = lp_lean1090_Lean1090_Impl_CPR_Policy_step(v_geo_641_, v_updateReference_642_, v___y_651_, v_reference_646_, v_timestamp_653_, v_message_654_);
v_state_656_ = lean_ctor_get(v_result_655_, 0);
lean_inc_ref(v_state_656_);
v_reference_657_ = lean_ctor_get(v_result_655_, 1);
lean_inc(v_reference_657_);
v_resolved_658_ = lean_ctor_get(v_result_655_, 2);
lean_inc(v_resolved_658_);
lean_dec_ref(v_result_655_);
v___x_659_ = lean_box(0);
v_remaining_660_ = lp_lean1090_List_filterTR_loop___at___00Lean1090_Impl_CPR_Policy_streamStep_spec__0(v_report_644_, v_aircraft_645_, v___x_659_);
lean_dec_ref(v_report_644_);
v___x_661_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_661_, 0, v_address_652_);
lean_ctor_set(v___x_661_, 1, v_state_656_);
v___x_662_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_662_, 0, v___x_661_);
lean_ctor_set(v___x_662_, 1, v_remaining_660_);
if (v_isShared_649_ == 0)
{
lean_ctor_set(v___x_648_, 1, v_reference_657_);
lean_ctor_set(v___x_648_, 0, v___x_662_);
v___x_664_ = v___x_648_;
goto v_reusejp_663_;
}
else
{
lean_object* v_reuseFailAlloc_666_; 
v_reuseFailAlloc_666_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_666_, 0, v___x_662_);
lean_ctor_set(v_reuseFailAlloc_666_, 1, v_reference_657_);
v___x_664_ = v_reuseFailAlloc_666_;
goto v_reusejp_663_;
}
v_reusejp_663_:
{
lean_object* v___x_665_; 
v___x_665_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_665_, 0, v___x_664_);
lean_ctor_set(v___x_665_, 1, v_resolved_658_);
return v___x_665_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_decodePositions_spec__0(lean_object* v_geo_673_, lean_object* v_updateReference_674_, lean_object* v_x_675_, lean_object* v_x_676_){
_start:
{
if (lean_obj_tag(v_x_676_) == 0)
{
lean_dec_ref(v_updateReference_674_);
lean_dec_ref(v_geo_673_);
return v_x_675_;
}
else
{
lean_object* v_head_677_; lean_object* v_tail_678_; lean_object* v___x_680_; uint8_t v_isShared_681_; uint8_t v_isSharedCheck_698_; 
v_head_677_ = lean_ctor_get(v_x_676_, 0);
v_tail_678_ = lean_ctor_get(v_x_676_, 1);
v_isSharedCheck_698_ = !lean_is_exclusive(v_x_676_);
if (v_isSharedCheck_698_ == 0)
{
v___x_680_ = v_x_676_;
v_isShared_681_ = v_isSharedCheck_698_;
goto v_resetjp_679_;
}
else
{
lean_inc(v_tail_678_);
lean_inc(v_head_677_);
lean_dec(v_x_676_);
v___x_680_ = lean_box(0);
v_isShared_681_ = v_isSharedCheck_698_;
goto v_resetjp_679_;
}
v_resetjp_679_:
{
lean_object* v_fst_682_; lean_object* v_snd_683_; lean_object* v___x_684_; lean_object* v_fst_685_; lean_object* v_snd_686_; lean_object* v___x_688_; uint8_t v_isShared_689_; uint8_t v_isSharedCheck_697_; 
v_fst_682_ = lean_ctor_get(v_x_675_, 0);
lean_inc(v_fst_682_);
v_snd_683_ = lean_ctor_get(v_x_675_, 1);
lean_inc(v_snd_683_);
lean_dec_ref(v_x_675_);
lean_inc_ref(v_updateReference_674_);
lean_inc_ref(v_geo_673_);
v___x_684_ = lp_lean1090_Lean1090_Impl_CPR_Policy_streamStep(v_geo_673_, v_updateReference_674_, v_fst_682_, v_head_677_);
v_fst_685_ = lean_ctor_get(v___x_684_, 0);
v_snd_686_ = lean_ctor_get(v___x_684_, 1);
v_isSharedCheck_697_ = !lean_is_exclusive(v___x_684_);
if (v_isSharedCheck_697_ == 0)
{
v___x_688_ = v___x_684_;
v_isShared_689_ = v_isSharedCheck_697_;
goto v_resetjp_687_;
}
else
{
lean_inc(v_snd_686_);
lean_inc(v_fst_685_);
lean_dec(v___x_684_);
v___x_688_ = lean_box(0);
v_isShared_689_ = v_isSharedCheck_697_;
goto v_resetjp_687_;
}
v_resetjp_687_:
{
lean_object* v___x_691_; 
if (v_isShared_681_ == 0)
{
lean_ctor_set(v___x_680_, 1, v_snd_683_);
lean_ctor_set(v___x_680_, 0, v_snd_686_);
v___x_691_ = v___x_680_;
goto v_reusejp_690_;
}
else
{
lean_object* v_reuseFailAlloc_696_; 
v_reuseFailAlloc_696_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_696_, 0, v_snd_686_);
lean_ctor_set(v_reuseFailAlloc_696_, 1, v_snd_683_);
v___x_691_ = v_reuseFailAlloc_696_;
goto v_reusejp_690_;
}
v_reusejp_690_:
{
lean_object* v___x_693_; 
if (v_isShared_689_ == 0)
{
lean_ctor_set(v___x_688_, 1, v___x_691_);
v___x_693_ = v___x_688_;
goto v_reusejp_692_;
}
else
{
lean_object* v_reuseFailAlloc_695_; 
v_reuseFailAlloc_695_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_695_, 0, v_fst_685_);
lean_ctor_set(v_reuseFailAlloc_695_, 1, v___x_691_);
v___x_693_ = v_reuseFailAlloc_695_;
goto v_reusejp_692_;
}
v_reusejp_692_:
{
v_x_675_ = v___x_693_;
v_x_676_ = v_tail_678_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodePositions(lean_object* v_geo_699_, lean_object* v_updateReference_700_, lean_object* v_reference_701_, lean_object* v_reports_702_){
_start:
{
lean_object* v___x_703_; lean_object* v___x_704_; lean_object* v___x_705_; lean_object* v___x_706_; lean_object* v_fst_707_; lean_object* v_snd_708_; lean_object* v___x_710_; uint8_t v_isShared_711_; uint8_t v_isSharedCheck_716_; 
v___x_703_ = lean_box(0);
v___x_704_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_704_, 0, v___x_703_);
lean_ctor_set(v___x_704_, 1, v_reference_701_);
v___x_705_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_705_, 0, v___x_704_);
lean_ctor_set(v___x_705_, 1, v___x_703_);
v___x_706_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_CPR_Policy_decodePositions_spec__0(v_geo_699_, v_updateReference_700_, v___x_705_, v_reports_702_);
v_fst_707_ = lean_ctor_get(v___x_706_, 0);
v_snd_708_ = lean_ctor_get(v___x_706_, 1);
v_isSharedCheck_716_ = !lean_is_exclusive(v___x_706_);
if (v_isSharedCheck_716_ == 0)
{
v___x_710_ = v___x_706_;
v_isShared_711_ = v_isSharedCheck_716_;
goto v_resetjp_709_;
}
else
{
lean_inc(v_snd_708_);
lean_inc(v_fst_707_);
lean_dec(v___x_706_);
v___x_710_ = lean_box(0);
v_isShared_711_ = v_isSharedCheck_716_;
goto v_resetjp_709_;
}
v_resetjp_709_:
{
lean_object* v___x_712_; lean_object* v___x_714_; 
v___x_712_ = l_List_reverse___redArg(v_snd_708_);
if (v_isShared_711_ == 0)
{
lean_ctor_set(v___x_710_, 1, v___x_712_);
v___x_714_ = v___x_710_;
goto v_reusejp_713_;
}
else
{
lean_object* v_reuseFailAlloc_715_; 
v_reuseFailAlloc_715_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_715_, 0, v_fst_707_);
lean_ctor_set(v_reuseFailAlloc_715_, 1, v___x_712_);
v___x_714_ = v_reuseFailAlloc_715_;
goto v_reusejp_713_;
}
v_reusejp_713_:
{
return v___x_714_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodePositions(lean_object* v_geo_717_, lean_object* v_updateReference_718_, lean_object* v_reference_719_, lean_object* v_reports_720_){
_start:
{
lean_object* v___x_721_; 
v___x_721_ = lp_lean1090_Lean1090_Impl_CPR_Policy_decodePositions(v_geo_717_, v_updateReference_718_, v_reference_719_, v_reports_720_);
return v___x_721_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Model_Types(uint8_t builtin);
lean_object* initialize_lean1090_Impl_CPR(uint8_t builtin);
lean_object* initialize_lean1090_Impl_Binary64(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_CPRPolicy(uint8_t builtin) {
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
res = initialize_lean1090_Impl_CPR(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_Binary64(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
