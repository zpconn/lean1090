// Lean compiler output
// Module: Impl.Bits
// Imports: public import Init public meta import Init public import Impl.PayloadBits
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
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
uint64_t lean_uint64_shift_left(uint64_t, uint64_t);
uint64_t lean_uint8_to_uint64(uint8_t);
uint64_t lean_uint64_add(uint64_t, uint64_t);
lean_object* l_List_foldl___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_uint8_to_nat(uint8_t);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_nat_pow(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* l_BitVec_ofNat(lean_object*, lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
uint64_t lean_uint64_sub(uint64_t, uint64_t);
uint64_t lean_uint64_land(uint64_t, uint64_t);
lean_object* lean_uint64_to_nat(uint64_t);
lean_object* l_List_lengthTR___redArg(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_shiftl(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_lean1090_Lean1090_Impl_bytesWord___lam__0(uint64_t, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesWord___lam__0___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_bytesWord___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_bytesWord___lam__0___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_bytesWord___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_bytesWord___closed__0_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_bytesWord___boxed__const__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 0}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
LEAN_EXPORT const lean_object* lp_lean1090_Lean1090_Impl_bytesWord___boxed__const__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_bytesWord___boxed__const__1_value;
LEAN_EXPORT uint64_t lp_lean1090_Lean1090_Impl_bytesWord(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesWord___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesWordPrefix(lean_object*, lean_object*, uint64_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesWordPrefix___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__1(uint64_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesValue(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_field(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_field___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_packFields(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_packFields___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameBytes(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameBytes___boxed(lean_object*);
LEAN_EXPORT uint64_t lp_lean1090_Lean1090_Impl_bytesWord___lam__0(uint64_t v_word_1_, uint8_t v_byte_2_){
_start:
{
uint64_t v___x_3_; uint64_t v___x_4_; uint64_t v___x_5_; uint64_t v___x_6_; 
v___x_3_ = 8ULL;
v___x_4_ = lean_uint64_shift_left(v_word_1_, v___x_3_);
v___x_5_ = lean_uint8_to_uint64(v_byte_2_);
v___x_6_ = lean_uint64_add(v___x_4_, v___x_5_);
return v___x_6_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesWord___lam__0___boxed(lean_object* v_word_7_, lean_object* v_byte_8_){
_start:
{
uint64_t v_word_boxed_9_; uint8_t v_byte_boxed_10_; uint64_t v_res_11_; lean_object* v_r_12_; 
v_word_boxed_9_ = lean_unbox_uint64(v_word_7_);
lean_dec_ref(v_word_7_);
v_byte_boxed_10_ = lean_unbox(v_byte_8_);
v_res_11_ = lp_lean1090_Lean1090_Impl_bytesWord___lam__0(v_word_boxed_9_, v_byte_boxed_10_);
v_r_12_ = lean_box_uint64(v_res_11_);
return v_r_12_;
}
}
LEAN_EXPORT uint64_t lp_lean1090_Lean1090_Impl_bytesWord(lean_object* v_bytes_16_){
_start:
{
lean_object* v___f_17_; lean_object* v___x_18_; lean_object* v___x_19_; uint64_t v___x_20_; 
v___f_17_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_bytesWord___closed__0));
v___x_18_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_bytesWord___boxed__const__1));
v___x_19_ = l_List_foldl___redArg(v___f_17_, v___x_18_, v_bytes_16_);
v___x_20_ = lean_unbox_uint64(v___x_19_);
lean_dec(v___x_19_);
return v___x_20_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesWord___boxed(lean_object* v_bytes_21_){
_start:
{
uint64_t v_res_22_; lean_object* v_r_23_; 
v_res_22_ = lp_lean1090_Lean1090_Impl_bytesWord(v_bytes_21_);
v_r_23_ = lean_box_uint64(v_res_22_);
return v_r_23_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesWordPrefix(lean_object* v_x_24_, lean_object* v_x_25_, uint64_t v_x_26_){
_start:
{
lean_object* v_zero_27_; uint8_t v_isZero_28_; 
v_zero_27_ = lean_unsigned_to_nat(0u);
v_isZero_28_ = lean_nat_dec_eq(v_x_24_, v_zero_27_);
if (v_isZero_28_ == 1)
{
lean_object* v___x_29_; lean_object* v___x_30_; 
lean_dec(v_x_24_);
v___x_29_ = lean_box_uint64(v_x_26_);
v___x_30_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_30_, 0, v___x_29_);
lean_ctor_set(v___x_30_, 1, v_x_25_);
return v___x_30_;
}
else
{
if (lean_obj_tag(v_x_25_) == 0)
{
lean_object* v___x_31_; lean_object* v___x_32_; 
lean_dec(v_x_24_);
v___x_31_ = lean_box_uint64(v_x_26_);
v___x_32_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_32_, 0, v___x_31_);
lean_ctor_set(v___x_32_, 1, v_x_25_);
return v___x_32_;
}
else
{
lean_object* v_head_33_; lean_object* v_tail_34_; lean_object* v_one_35_; lean_object* v_n_36_; uint64_t v___x_37_; uint64_t v___x_38_; uint8_t v___x_39_; uint64_t v___x_40_; uint64_t v___x_41_; 
v_head_33_ = lean_ctor_get(v_x_25_, 0);
lean_inc(v_head_33_);
v_tail_34_ = lean_ctor_get(v_x_25_, 1);
lean_inc(v_tail_34_);
lean_dec_ref_known(v_x_25_, 2);
v_one_35_ = lean_unsigned_to_nat(1u);
v_n_36_ = lean_nat_sub(v_x_24_, v_one_35_);
lean_dec(v_x_24_);
v___x_37_ = 8ULL;
v___x_38_ = lean_uint64_shift_left(v_x_26_, v___x_37_);
v___x_39_ = lean_unbox(v_head_33_);
lean_dec(v_head_33_);
v___x_40_ = lean_uint8_to_uint64(v___x_39_);
v___x_41_ = lean_uint64_add(v___x_38_, v___x_40_);
v_x_24_ = v_n_36_;
v_x_25_ = v_tail_34_;
v_x_26_ = v___x_41_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesWordPrefix___boxed(lean_object* v_x_43_, lean_object* v_x_44_, lean_object* v_x_45_){
_start:
{
uint64_t v_x_66__boxed_46_; lean_object* v_res_47_; 
v_x_66__boxed_46_ = lean_unbox_uint64(v_x_45_);
lean_dec_ref(v_x_45_);
v_res_47_ = lp_lean1090_Lean1090_Impl_bytesWordPrefix(v_x_43_, v_x_44_, v_x_66__boxed_46_);
return v_res_47_;
}
}
LEAN_EXPORT uint64_t lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__1(uint64_t v_x_48_, lean_object* v_x_49_){
_start:
{
if (lean_obj_tag(v_x_49_) == 0)
{
return v_x_48_;
}
else
{
lean_object* v_head_50_; lean_object* v_tail_51_; uint64_t v___x_52_; uint64_t v___x_53_; uint8_t v___x_54_; uint64_t v___x_55_; uint64_t v___x_56_; 
v_head_50_ = lean_ctor_get(v_x_49_, 0);
v_tail_51_ = lean_ctor_get(v_x_49_, 1);
v___x_52_ = 8ULL;
v___x_53_ = lean_uint64_shift_left(v_x_48_, v___x_52_);
v___x_54_ = lean_unbox(v_head_50_);
v___x_55_ = lean_uint8_to_uint64(v___x_54_);
v___x_56_ = lean_uint64_add(v___x_53_, v___x_55_);
v_x_48_ = v___x_56_;
v_x_49_ = v_tail_51_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__1___boxed(lean_object* v_x_58_, lean_object* v_x_59_){
_start:
{
uint64_t v_x_187__boxed_60_; uint64_t v_res_61_; lean_object* v_r_62_; 
v_x_187__boxed_60_ = lean_unbox_uint64(v_x_58_);
lean_dec_ref(v_x_58_);
v_res_61_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__1(v_x_187__boxed_60_, v_x_59_);
lean_dec(v_x_59_);
v_r_62_ = lean_box_uint64(v_res_61_);
return v_r_62_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0(lean_object* v_x_63_, lean_object* v_x_64_){
_start:
{
if (lean_obj_tag(v_x_64_) == 0)
{
return v_x_63_;
}
else
{
lean_object* v_head_65_; lean_object* v_tail_66_; lean_object* v___x_67_; lean_object* v___x_68_; uint8_t v___x_69_; lean_object* v___x_70_; lean_object* v___x_71_; 
v_head_65_ = lean_ctor_get(v_x_64_, 0);
v_tail_66_ = lean_ctor_get(v_x_64_, 1);
v___x_67_ = lean_unsigned_to_nat(256u);
v___x_68_ = lean_nat_mul(v___x_67_, v_x_63_);
lean_dec(v_x_63_);
v___x_69_ = lean_unbox(v_head_65_);
v___x_70_ = lean_uint8_to_nat(v___x_69_);
v___x_71_ = lean_nat_add(v___x_68_, v___x_70_);
lean_dec(v___x_68_);
v_x_63_ = v___x_71_;
v_x_64_ = v_tail_66_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0___boxed(lean_object* v_x_73_, lean_object* v_x_74_){
_start:
{
lean_object* v_res_75_; 
v_res_75_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0(v_x_73_, v_x_74_);
lean_dec(v_x_74_);
return v_res_75_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesValue(lean_object* v_bytes_76_){
_start:
{
lean_object* v_count_77_; lean_object* v___x_78_; uint8_t v___x_79_; 
v_count_77_ = l_List_lengthTR___redArg(v_bytes_76_);
v___x_78_ = lean_unsigned_to_nat(8u);
v___x_79_ = lean_nat_dec_le(v_count_77_, v___x_78_);
if (v___x_79_ == 0)
{
lean_object* v___x_80_; uint8_t v___x_81_; 
v___x_80_ = lean_unsigned_to_nat(16u);
v___x_81_ = lean_nat_dec_le(v_count_77_, v___x_80_);
if (v___x_81_ == 0)
{
lean_object* v___x_82_; lean_object* v___x_83_; 
lean_dec(v_count_77_);
v___x_82_ = lean_unsigned_to_nat(0u);
v___x_83_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0(v___x_82_, v_bytes_76_);
lean_dec(v_bytes_76_);
return v___x_83_;
}
else
{
uint64_t v___x_84_; lean_object* v___x_85_; lean_object* v_fst_86_; lean_object* v_snd_87_; uint64_t v___x_88_; lean_object* v___x_89_; lean_object* v___x_90_; lean_object* v___x_91_; lean_object* v___x_92_; uint64_t v___x_93_; lean_object* v___x_94_; lean_object* v___x_95_; 
v___x_84_ = 0ULL;
v___x_85_ = lp_lean1090_Lean1090_Impl_bytesWordPrefix(v___x_78_, v_bytes_76_, v___x_84_);
v_fst_86_ = lean_ctor_get(v___x_85_, 0);
lean_inc(v_fst_86_);
v_snd_87_ = lean_ctor_get(v___x_85_, 1);
lean_inc(v_snd_87_);
lean_dec_ref(v___x_85_);
v___x_88_ = lean_unbox_uint64(v_fst_86_);
lean_dec(v_fst_86_);
v___x_89_ = lean_uint64_to_nat(v___x_88_);
v___x_90_ = lean_nat_sub(v_count_77_, v___x_78_);
lean_dec(v_count_77_);
v___x_91_ = lean_nat_mul(v___x_78_, v___x_90_);
lean_dec(v___x_90_);
v___x_92_ = lean_nat_shiftl(v___x_89_, v___x_91_);
lean_dec(v___x_91_);
lean_dec(v___x_89_);
v___x_93_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__1(v___x_84_, v_snd_87_);
lean_dec(v_snd_87_);
v___x_94_ = lean_uint64_to_nat(v___x_93_);
v___x_95_ = lean_nat_add(v___x_92_, v___x_94_);
lean_dec(v___x_94_);
lean_dec(v___x_92_);
return v___x_95_;
}
}
else
{
uint64_t v___x_96_; uint64_t v___x_97_; lean_object* v___x_98_; 
lean_dec(v_count_77_);
v___x_96_ = 0ULL;
v___x_97_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__1(v___x_96_, v_bytes_76_);
lean_dec(v_bytes_76_);
v___x_98_ = lean_uint64_to_nat(v___x_97_);
return v___x_98_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_field(lean_object* v_total_99_, lean_object* v_start_100_, lean_object* v_width_101_, lean_object* v_word_102_){
_start:
{
lean_object* v___x_103_; uint8_t v___x_104_; 
v___x_103_ = lean_unsigned_to_nat(64u);
v___x_104_ = lean_nat_dec_lt(v_width_101_, v___x_103_);
if (v___x_104_ == 0)
{
lean_object* v___x_105_; lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_108_; lean_object* v___x_109_; lean_object* v___x_110_; 
v___x_105_ = lean_unsigned_to_nat(2u);
v___x_106_ = lean_nat_sub(v_total_99_, v_start_100_);
v___x_107_ = lean_nat_sub(v___x_106_, v_width_101_);
lean_dec(v___x_106_);
v___x_108_ = lean_nat_pow(v___x_105_, v___x_107_);
lean_dec(v___x_107_);
v___x_109_ = lean_nat_div(v_word_102_, v___x_108_);
lean_dec(v___x_108_);
v___x_110_ = l_BitVec_ofNat(v_width_101_, v___x_109_);
lean_dec(v___x_109_);
return v___x_110_;
}
else
{
lean_object* v___x_111_; lean_object* v___x_112_; lean_object* v___x_113_; uint64_t v___x_114_; uint64_t v___x_115_; uint64_t v___x_116_; uint64_t v___x_117_; uint64_t v___x_118_; uint64_t v___x_119_; lean_object* v___x_120_; 
v___x_111_ = lean_nat_sub(v_total_99_, v_start_100_);
v___x_112_ = lean_nat_sub(v___x_111_, v_width_101_);
lean_dec(v___x_111_);
v___x_113_ = lean_nat_shiftr(v_word_102_, v___x_112_);
lean_dec(v___x_112_);
v___x_114_ = lean_uint64_of_nat(v___x_113_);
lean_dec(v___x_113_);
v___x_115_ = 1ULL;
v___x_116_ = lean_uint64_of_nat(v_width_101_);
v___x_117_ = lean_uint64_shift_left(v___x_115_, v___x_116_);
v___x_118_ = lean_uint64_sub(v___x_117_, v___x_115_);
v___x_119_ = lean_uint64_land(v___x_114_, v___x_118_);
v___x_120_ = lean_uint64_to_nat(v___x_119_);
return v___x_120_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_field___boxed(lean_object* v_total_121_, lean_object* v_start_122_, lean_object* v_width_123_, lean_object* v_word_124_){
_start:
{
lean_object* v_res_125_; 
v_res_125_ = lp_lean1090_Lean1090_Impl_field(v_total_121_, v_start_122_, v_width_123_, v_word_124_);
lean_dec(v_word_124_);
lean_dec(v_width_123_);
lean_dec(v_start_122_);
lean_dec(v_total_121_);
return v_res_125_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0(lean_object* v_x_126_, lean_object* v_x_127_){
_start:
{
if (lean_obj_tag(v_x_127_) == 0)
{
return v_x_126_;
}
else
{
lean_object* v_head_128_; lean_object* v_tail_129_; lean_object* v_fst_130_; lean_object* v_snd_131_; lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; lean_object* v___x_136_; 
v_head_128_ = lean_ctor_get(v_x_127_, 0);
v_tail_129_ = lean_ctor_get(v_x_127_, 1);
v_fst_130_ = lean_ctor_get(v_head_128_, 0);
v_snd_131_ = lean_ctor_get(v_head_128_, 1);
v___x_132_ = lean_unsigned_to_nat(2u);
v___x_133_ = lean_nat_pow(v___x_132_, v_fst_130_);
v___x_134_ = lean_nat_mul(v_x_126_, v___x_133_);
lean_dec(v_x_126_);
v___x_135_ = lean_nat_mod(v_snd_131_, v___x_133_);
lean_dec(v___x_133_);
v___x_136_ = lean_nat_add(v___x_134_, v___x_135_);
lean_dec(v___x_135_);
lean_dec(v___x_134_);
v_x_126_ = v___x_136_;
v_x_127_ = v_tail_129_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0___boxed(lean_object* v_x_138_, lean_object* v_x_139_){
_start:
{
lean_object* v_res_140_; 
v_res_140_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0(v_x_138_, v_x_139_);
lean_dec(v_x_139_);
return v_res_140_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_packFields(lean_object* v_fields_141_){
_start:
{
lean_object* v___x_142_; lean_object* v___x_143_; 
v___x_142_ = lean_unsigned_to_nat(0u);
v___x_143_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0(v___x_142_, v_fields_141_);
return v___x_143_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_packFields___boxed(lean_object* v_fields_144_){
_start:
{
lean_object* v_res_145_; 
v_res_145_ = lp_lean1090_Lean1090_Impl_packFields(v_fields_144_);
lean_dec(v_fields_144_);
return v_res_145_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameBytes(lean_object* v_df_146_){
_start:
{
lean_object* v___x_147_; uint8_t v___x_148_; 
v___x_147_ = lean_unsigned_to_nat(16u);
v___x_148_ = lean_nat_dec_lt(v_df_146_, v___x_147_);
if (v___x_148_ == 0)
{
lean_object* v___x_149_; 
v___x_149_ = lean_unsigned_to_nat(14u);
return v___x_149_;
}
else
{
lean_object* v___x_150_; 
v___x_150_ = lean_unsigned_to_nat(7u);
return v___x_150_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameBytes___boxed(lean_object* v_df_151_){
_start:
{
lean_object* v_res_152_; 
v_res_152_ = lp_lean1090_Lean1090_Impl_frameBytes(v_df_151_);
lean_dec(v_df_151_);
return v_res_152_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Impl_PayloadBits(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_Bits(uint8_t builtin) {
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
res = initialize_lean1090_Impl_PayloadBits(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
