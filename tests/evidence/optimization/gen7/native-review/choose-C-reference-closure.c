static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0(void){
_start:
{
lean_object* v___x_204_; lean_object* v___x_205_; 
v___x_204_ = lean_cstr_to_nat("1099511627776");
v___x_205_ = lean_nat_to_int(v___x_204_);
return v___x_205_;
}
}

static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1(void){
_start:
{
lean_object* v___x_206_; lean_object* v___x_207_; 
v___x_206_ = lean_unsigned_to_nat(3u);
v___x_207_ = lean_nat_to_int(v___x_206_);
return v___x_207_;
}
}

static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__2(void){
_start:
{
lean_object* v___x_208_; lean_object* v___x_209_; 
v___x_208_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1, &lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1);
v___x_209_ = lean_int_neg(v___x_208_);
return v___x_209_;
}
}

static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__0(void){
_start:
{
lean_object* v___x_193_; lean_object* v___x_194_; 
v___x_193_ = lean_unsigned_to_nat(0u);
v___x_194_ = lean_nat_to_int(v___x_193_);
return v___x_194_;
}
}

static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__1(void){
_start:
{
lean_object* v___x_195_; lean_object* v___x_196_; 
v___x_195_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__0, &lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__0_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__0);
v___x_196_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_196_, 0, v___x_195_);
lean_ctor_set(v___x_196_, 1, v___x_195_);
return v___x_196_;
}
}

LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_ScoreGate_choose(lean_object* v_terms_210_, lean_object* v_penalty_211_, lean_object* v_fallback_212_){
_start:
{
lean_object* v_num_213_; lean_object* v_den_214_; lean_object* v_denominator_215_; lean_object* v_totals_216_; lean_object* v___x_217_; lean_object* v___x_218_; lean_object* v_p_219_; lean_object* v___y_221_; lean_object* v___x_246_; lean_object* v___x_247_; uint8_t v___x_248_; 
v_num_213_ = lean_ctor_get(v_penalty_211_, 0);
lean_inc(v_num_213_);
v_den_214_ = lean_ctor_get(v_penalty_211_, 1);
lean_inc(v_den_214_);
lean_inc(v_terms_210_);
v_denominator_215_ = lp_lean1090_Lean1090_Impl_ScoreGate_commonDenominator(v_terms_210_, v_penalty_211_);
v_totals_216_ = lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals(v_denominator_215_, v_terms_210_);
v___x_217_ = lean_nat_div(v_denominator_215_, v_den_214_);
lean_dec(v_den_214_);
v___x_218_ = lean_nat_to_int(v___x_217_);
v_p_219_ = lean_int_mul(v_num_213_, v___x_218_);
lean_dec(v___x_218_);
lean_dec(v_num_213_);
v___x_246_ = l_List_lengthTR___redArg(v_terms_210_);
lean_dec(v_terms_210_);
v___x_247_ = lean_unsigned_to_nat(1u);
v___x_248_ = lean_nat_dec_le(v___x_246_, v___x_247_);
if (v___x_248_ == 0)
{
v___y_221_ = v___x_246_;
goto v___jp_220_;
}
else
{
lean_dec(v___x_246_);
v___y_221_ = v___x_247_;
goto v___jp_220_;
}
v___jp_220_:
{
lean_object* v_fst_222_; lean_object* v_snd_223_; lean_object* v_n_224_; lean_object* v___x_225_; lean_object* v_c_226_; lean_object* v___x_227_; lean_object* v___x_228_; lean_object* v___x_229_; lean_object* v___x_230_; lean_object* v_e_231_; lean_object* v___x_232_; lean_object* v_scaledCenter_233_; lean_object* v_scaledError_234_; lean_object* v___x_235_; lean_object* v___x_236_; lean_object* v___x_237_; lean_object* v_threshold_238_; lean_object* v___x_239_; uint8_t v___x_240_; 
v_fst_222_ = lean_ctor_get(v_totals_216_, 0);
lean_inc(v_fst_222_);
v_snd_223_ = lean_ctor_get(v_totals_216_, 1);
lean_inc(v_snd_223_);
lean_dec_ref(v_totals_216_);
v_n_224_ = lean_nat_to_int(v___y_221_);
v___x_225_ = lean_int_mul(v_n_224_, v_p_219_);
v_c_226_ = lean_int_add(v_fst_222_, v___x_225_);
lean_dec(v___x_225_);
lean_dec(v_fst_222_);
v___x_227_ = lean_nat_abs(v_p_219_);
lean_dec(v_p_219_);
v___x_228_ = lean_nat_to_int(v___x_227_);
v___x_229_ = lean_int_add(v_snd_223_, v___x_228_);
lean_dec(v___x_228_);
lean_dec(v_snd_223_);
v___x_230_ = lean_nat_to_int(v_denominator_215_);
v_e_231_ = lean_int_add(v___x_229_, v___x_230_);
lean_dec(v___x_229_);
v___x_232_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0, &lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0);
v_scaledCenter_233_ = lean_int_mul(v___x_232_, v_c_226_);
lean_dec(v_c_226_);
v_scaledError_234_ = lean_int_mul(v_n_224_, v_e_231_);
lean_dec(v_e_231_);
v___x_235_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__2, &lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__2_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__2);
v___x_236_ = lean_int_mul(v___x_235_, v_n_224_);
lean_dec(v_n_224_);
v___x_237_ = lean_int_mul(v___x_236_, v___x_230_);
lean_dec(v___x_230_);
lean_dec(v___x_236_);
v_threshold_238_ = lean_int_mul(v___x_237_, v___x_232_);
lean_dec(v___x_237_);
v___x_239_ = lean_int_sub(v_scaledCenter_233_, v_scaledError_234_);
v___x_240_ = lean_int_dec_le(v_threshold_238_, v___x_239_);
lean_dec(v___x_239_);
if (v___x_240_ == 0)
{
lean_object* v___x_241_; uint8_t v___x_242_; 
v___x_241_ = lean_int_add(v_scaledCenter_233_, v_scaledError_234_);
lean_dec(v_scaledError_234_);
lean_dec(v_scaledCenter_233_);
v___x_242_ = lean_int_dec_lt(v___x_241_, v_threshold_238_);
lean_dec(v_threshold_238_);
lean_dec(v___x_241_);
if (v___x_242_ == 0)
{
lean_object* v___x_243_; lean_object* v___x_244_; uint8_t v___x_245_; 
v___x_243_ = lean_box(0);
v___x_244_ = lean_apply_1(v_fallback_212_, v___x_243_);
v___x_245_ = lean_unbox(v___x_244_);
return v___x_245_;
}
else
{
lean_dec_ref(v_fallback_212_);
return v___x_240_;
}
}
else
{
lean_dec(v_threshold_238_);
lean_dec(v_scaledError_234_);
lean_dec(v_scaledCenter_233_);
lean_dec_ref(v_fallback_212_);
return v___x_240_;
}
}
}
}

LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_commonDenominator(lean_object* v_terms_110_, lean_object* v_penalty_111_){
_start:
{
lean_object* v_den_112_; lean_object* v___x_114_; uint8_t v_isShared_115_; uint8_t v_isSharedCheck_125_; 
v_den_112_ = lean_ctor_get(v_penalty_111_, 1);
v_isSharedCheck_125_ = !lean_is_exclusive(v_penalty_111_);
if (v_isSharedCheck_125_ == 0)
{
lean_object* v_unused_126_; 
v_unused_126_ = lean_ctor_get(v_penalty_111_, 0);
lean_dec(v_unused_126_);
v___x_114_ = v_penalty_111_;
v_isShared_115_ = v_isSharedCheck_125_;
goto v_resetjp_113_;
}
else
{
lean_inc(v_den_112_);
lean_dec(v_penalty_111_);
v___x_114_ = lean_box(0);
v_isShared_115_ = v_isSharedCheck_125_;
goto v_resetjp_113_;
}
v_resetjp_113_:
{
lean_object* v___x_116_; lean_object* v___x_117_; lean_object* v_denominators_119_; 
v___x_116_ = lean_box(0);
v___x_117_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__0(v_terms_110_, v___x_116_);
if (v_isShared_115_ == 0)
{
lean_ctor_set_tag(v___x_114_, 1);
lean_ctor_set(v___x_114_, 1, v___x_117_);
lean_ctor_set(v___x_114_, 0, v_den_112_);
v_denominators_119_ = v___x_114_;
goto v_reusejp_118_;
}
else
{
lean_object* v_reuseFailAlloc_124_; 
v_reuseFailAlloc_124_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_124_, 0, v_den_112_);
lean_ctor_set(v_reuseFailAlloc_124_, 1, v___x_117_);
v_denominators_119_ = v_reuseFailAlloc_124_;
goto v_reusejp_118_;
}
v_reusejp_118_:
{
lean_object* v___x_120_; lean_object* v_largest_121_; uint8_t v___x_122_; 
v___x_120_ = lean_unsigned_to_nat(1u);
v_largest_121_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__1(v___x_120_, v_denominators_119_);
v___x_122_ = lp_lean1090_List_all___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__2(v_largest_121_, v_denominators_119_);
if (v___x_122_ == 0)
{
lean_object* v___x_123_; 
lean_dec(v_largest_121_);
v___x_123_ = lp_lean1090_List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3(v_denominators_119_);
lean_dec_ref(v_denominators_119_);
return v___x_123_;
}
else
{
lean_dec_ref(v_denominators_119_);
return v_largest_121_;
}
}
}
}
}

LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals(lean_object* v_denominator_197_, lean_object* v_terms_198_){
_start:
{
lean_object* v___x_199_; lean_object* v___x_200_; 
v___x_199_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__1, &lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__1_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__1);
v___x_200_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0(v_denominator_197_, v___x_199_, v_terms_198_);
return v___x_200_;
}
}

LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__2(lean_object* v_largest_69_, lean_object* v_x_70_){
_start:
{
if (lean_obj_tag(v_x_70_) == 0)
{
uint8_t v___x_71_; 
v___x_71_ = 1;
return v___x_71_;
}
else
{
lean_object* v_head_72_; lean_object* v_tail_73_; lean_object* v___x_74_; lean_object* v___x_75_; uint8_t v___x_76_; 
v_head_72_ = lean_ctor_get(v_x_70_, 0);
v_tail_73_ = lean_ctor_get(v_x_70_, 1);
v___x_74_ = lean_nat_mod(v_largest_69_, v_head_72_);
v___x_75_ = lean_unsigned_to_nat(0u);
v___x_76_ = lean_nat_dec_eq(v___x_74_, v___x_75_);
lean_dec(v___x_74_);
if (v___x_76_ == 0)
{
return v___x_76_;
}
else
{
v_x_70_ = v_tail_73_;
goto _start;
}
}
}
}

LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__1(lean_object* v_x_59_, lean_object* v_x_60_){
_start:
{
if (lean_obj_tag(v_x_60_) == 0)
{
lean_inc(v_x_59_);
return v_x_59_;
}
else
{
lean_object* v_head_61_; lean_object* v_tail_62_; uint8_t v___x_63_; 
v_head_61_ = lean_ctor_get(v_x_60_, 0);
v_tail_62_ = lean_ctor_get(v_x_60_, 1);
v___x_63_ = lean_nat_dec_le(v_x_59_, v_head_61_);
if (v___x_63_ == 0)
{
v_x_60_ = v_tail_62_;
goto _start;
}
else
{
v_x_59_ = v_head_61_;
v_x_60_ = v_tail_62_;
goto _start;
}
}
}
}

LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0(lean_object* v_denominator_165_, lean_object* v_x_166_, lean_object* v_x_167_){
_start:
{
if (lean_obj_tag(v_x_167_) == 0)
{
return v_x_166_;
}
else
{
lean_object* v_head_168_; lean_object* v_tail_169_; lean_object* v_num_170_; lean_object* v_den_171_; lean_object* v_fst_172_; lean_object* v_snd_173_; lean_object* v___x_175_; uint8_t v_isShared_176_; uint8_t v_isSharedCheck_188_; 
v_head_168_ = lean_ctor_get(v_x_167_, 0);
v_tail_169_ = lean_ctor_get(v_x_167_, 1);
v_num_170_ = lean_ctor_get(v_head_168_, 0);
v_den_171_ = lean_ctor_get(v_head_168_, 1);
v_fst_172_ = lean_ctor_get(v_x_166_, 0);
v_snd_173_ = lean_ctor_get(v_x_166_, 1);
v_isSharedCheck_188_ = !lean_is_exclusive(v_x_166_);
if (v_isSharedCheck_188_ == 0)
{
v___x_175_ = v_x_166_;
v_isShared_176_ = v_isSharedCheck_188_;
goto v_resetjp_174_;
}
else
{
lean_inc(v_snd_173_);
lean_inc(v_fst_172_);
lean_dec(v_x_166_);
v___x_175_ = lean_box(0);
v_isShared_176_ = v_isSharedCheck_188_;
goto v_resetjp_174_;
}
v_resetjp_174_:
{
lean_object* v___x_177_; lean_object* v___x_178_; lean_object* v_numerator_179_; lean_object* v___x_180_; lean_object* v___x_181_; lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_185_; 
v___x_177_ = lean_nat_div(v_denominator_165_, v_den_171_);
v___x_178_ = lean_nat_to_int(v___x_177_);
v_numerator_179_ = lean_int_mul(v_num_170_, v___x_178_);
lean_dec(v___x_178_);
v___x_180_ = lean_int_add(v_fst_172_, v_numerator_179_);
lean_dec(v_fst_172_);
v___x_181_ = lean_nat_abs(v_numerator_179_);
lean_dec(v_numerator_179_);
v___x_182_ = lean_nat_to_int(v___x_181_);
v___x_183_ = lean_int_add(v_snd_173_, v___x_182_);
lean_dec(v___x_182_);
lean_dec(v_snd_173_);
if (v_isShared_176_ == 0)
{
lean_ctor_set(v___x_175_, 1, v___x_183_);
lean_ctor_set(v___x_175_, 0, v___x_180_);
v___x_185_ = v___x_175_;
goto v_reusejp_184_;
}
else
{
lean_object* v_reuseFailAlloc_187_; 
v_reuseFailAlloc_187_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_187_, 0, v___x_180_);
lean_ctor_set(v_reuseFailAlloc_187_, 1, v___x_183_);
v___x_185_ = v_reuseFailAlloc_187_;
goto v_reusejp_184_;
}
v_reusejp_184_:
{
lean_object* v___x_186_; 
v___x_186_ = lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0(v_denominator_165_, v___x_185_, v_tail_169_);
return v___x_186_;
}
}
}
}
}

LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0(lean_object* v_denominator_137_, lean_object* v_x_138_, lean_object* v_x_139_){
_start:
{
if (lean_obj_tag(v_x_139_) == 0)
{
return v_x_138_;
}
else
{
lean_object* v_head_140_; lean_object* v_tail_141_; lean_object* v_num_142_; lean_object* v_den_143_; lean_object* v_fst_144_; lean_object* v_snd_145_; lean_object* v___x_147_; uint8_t v_isShared_148_; uint8_t v_isSharedCheck_160_; 
v_head_140_ = lean_ctor_get(v_x_139_, 0);
v_tail_141_ = lean_ctor_get(v_x_139_, 1);
v_num_142_ = lean_ctor_get(v_head_140_, 0);
v_den_143_ = lean_ctor_get(v_head_140_, 1);
v_fst_144_ = lean_ctor_get(v_x_138_, 0);
v_snd_145_ = lean_ctor_get(v_x_138_, 1);
v_isSharedCheck_160_ = !lean_is_exclusive(v_x_138_);
if (v_isSharedCheck_160_ == 0)
{
v___x_147_ = v_x_138_;
v_isShared_148_ = v_isSharedCheck_160_;
goto v_resetjp_146_;
}
else
{
lean_inc(v_snd_145_);
lean_inc(v_fst_144_);
lean_dec(v_x_138_);
v___x_147_ = lean_box(0);
v_isShared_148_ = v_isSharedCheck_160_;
goto v_resetjp_146_;
}
v_resetjp_146_:
{
lean_object* v___x_149_; lean_object* v___x_150_; lean_object* v_numerator_151_; lean_object* v___x_152_; lean_object* v___x_153_; lean_object* v___x_154_; lean_object* v___x_155_; lean_object* v___x_157_; 
v___x_149_ = lean_nat_div(v_denominator_137_, v_den_143_);
v___x_150_ = lean_nat_to_int(v___x_149_);
v_numerator_151_ = lean_int_mul(v_num_142_, v___x_150_);
lean_dec(v___x_150_);
v___x_152_ = lean_int_add(v_fst_144_, v_numerator_151_);
lean_dec(v_fst_144_);
v___x_153_ = lean_nat_abs(v_numerator_151_);
lean_dec(v_numerator_151_);
v___x_154_ = lean_nat_to_int(v___x_153_);
v___x_155_ = lean_int_add(v_snd_145_, v___x_154_);
lean_dec(v___x_154_);
lean_dec(v_snd_145_);
if (v_isShared_148_ == 0)
{
lean_ctor_set(v___x_147_, 1, v___x_155_);
lean_ctor_set(v___x_147_, 0, v___x_152_);
v___x_157_ = v___x_147_;
goto v_reusejp_156_;
}
else
{
lean_object* v_reuseFailAlloc_159_; 
v_reuseFailAlloc_159_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_159_, 0, v___x_152_);
lean_ctor_set(v_reuseFailAlloc_159_, 1, v___x_155_);
v___x_157_ = v_reuseFailAlloc_159_;
goto v_reusejp_156_;
}
v_reusejp_156_:
{
v_x_138_ = v___x_157_;
v_x_139_ = v_tail_141_;
goto _start;
}
}
}
}
}

LEAN_EXPORT lean_object* lp_lean1090_List_foldr___at___00List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3_spec__3(lean_object* v_init_82_, lean_object* v_x_83_){
_start:
{
if (lean_obj_tag(v_x_83_) == 0)
{
lean_inc(v_init_82_);
return v_init_82_;
}
else
{
lean_object* v_head_84_; lean_object* v_tail_85_; lean_object* v___x_86_; lean_object* v___x_87_; 
v_head_84_ = lean_ctor_get(v_x_83_, 0);
v_tail_85_ = lean_ctor_get(v_x_83_, 1);
v___x_86_ = lp_lean1090_List_foldr___at___00List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3_spec__3(v_init_82_, v_tail_85_);
v___x_87_ = lean_nat_mul(v_head_84_, v___x_86_);
lean_dec(v___x_86_);
return v___x_87_;
}
}
}

LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__0(lean_object* v_a_96_, lean_object* v_a_97_){
_start:
{
if (lean_obj_tag(v_a_96_) == 0)
{
lean_object* v___x_98_; 
v___x_98_ = l_List_reverse___redArg(v_a_97_);
return v___x_98_;
}
else
{
lean_object* v_head_99_; lean_object* v_tail_100_; lean_object* v___x_102_; uint8_t v_isShared_103_; uint8_t v_isSharedCheck_109_; 
v_head_99_ = lean_ctor_get(v_a_96_, 0);
v_tail_100_ = lean_ctor_get(v_a_96_, 1);
v_isSharedCheck_109_ = !lean_is_exclusive(v_a_96_);
if (v_isSharedCheck_109_ == 0)
{
v___x_102_ = v_a_96_;
v_isShared_103_ = v_isSharedCheck_109_;
goto v_resetjp_101_;
}
else
{
lean_inc(v_tail_100_);
lean_inc(v_head_99_);
lean_dec(v_a_96_);
v___x_102_ = lean_box(0);
v_isShared_103_ = v_isSharedCheck_109_;
goto v_resetjp_101_;
}
v_resetjp_101_:
{
lean_object* v_den_104_; lean_object* v___x_106_; 
v_den_104_ = lean_ctor_get(v_head_99_, 1);
lean_inc(v_den_104_);
lean_dec(v_head_99_);
if (v_isShared_103_ == 0)
{
lean_ctor_set(v___x_102_, 1, v_a_97_);
lean_ctor_set(v___x_102_, 0, v_den_104_);
v___x_106_ = v___x_102_;
goto v_reusejp_105_;
}
else
{
lean_object* v_reuseFailAlloc_108_; 
v_reuseFailAlloc_108_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_108_, 0, v_den_104_);
lean_ctor_set(v_reuseFailAlloc_108_, 1, v_a_97_);
v___x_106_ = v_reuseFailAlloc_108_;
goto v_reusejp_105_;
}
v_reusejp_105_:
{
v_a_96_ = v_tail_100_;
v_a_97_ = v___x_106_;
goto _start;
}
}
}
}
}

LEAN_EXPORT lean_object* lp_lean1090_List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3(lean_object* v_l_91_){
_start:
{
lean_object* v___x_92_; lean_object* v___x_93_; 
v___x_92_ = lean_unsigned_to_nat(1u);
v___x_93_ = lp_lean1090_List_foldr___at___00List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3_spec__3(v___x_92_, v_l_91_);
return v___x_93_;
}
}
