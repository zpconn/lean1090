
.lake/build/ir/Impl/Parity.c.o.export:     file format elf64-x86-64


Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_step:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_step___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_wordBit:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_wordBit___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_cachedBit:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_cachedBit___boxed:

Disassembly of section .text.lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0:

0000000000000000 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0>:
   0:	push   %rbp
   1:	push   %r15
   3:	push   %r14
   5:	push   %r13
   7:	push   %r12
   9:	push   %rbx
   a:	sub    $0x28,%rsp
   e:	mov    %r9,%rbx
  11:	mov    %r8,%rax
  14:	mov    %rcx,0x20(%rsp)
  19:	mov    %rdx,0x18(%rsp)
  1e:	mov    %rsi,0x8(%rsp)
  23:	mov    %rdi,%rcx
  26:	mov    %rdi,0x10(%rsp)
  2b:	sub    $0x2,%rcx
  2f:	mov    $0x1,%r13d
  35:	cmovae %rcx,%r13
  39:	nopl   0x0(%rax)
  40:	mov    %rax,%rbp
  43:	test   $0x1,%bl
  46:	jne    60 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x60>
  48:	movzbl 0x7(%rbx),%eax
  4c:	test   %eax,%eax
  4e:	jne    6e <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x6e>
  50:	jmp    2ef <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2ef>
  55:	data16 cs nopw 0x0(%rax,%rax,1)
  60:	mov    %rbx,%rax
  63:	shr    $1,%rax
  66:	test   %eax,%eax
  68:	je     2ef <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2ef>
  6e:	mov    0x8(%rbx),%r14
  72:	mov    0x10(%rbx),%rbx
  76:	mov    %r13,%r12
  79:	testb  $0x1,0x10(%rsp)
  7e:	je     18b <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x18b>
  84:	test   $0x1,%r12b
  88:	je     1a7 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x1a7>
  8e:	test   $0x1,%r14b
  92:	je     1cd <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x1cd>
  98:	shr    $1,%r12
  9b:	shr    $1,%r14
  9e:	mov    $0x1,%r15d
  a4:	sub    %r14,%r12
  a7:	jb     c4 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xc4>
  a9:	lea    0x1(,%r12,2),%r15
  b1:	test   $0x1,%r15b
  b5:	je     1e0 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x1e0>
  bb:	cmp    $0x81,%r15
  c2:	jae    110 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x110>
  c4:	shr    $1,%r15
  c7:	mov    %r15,%rax
  ca:	xor    %esi,%esi
  cc:	mov    0x20(%rsp),%rcx
  d1:	bt     %rax,%rcx
  d5:	setb   %sil
  d9:	mov    %rbp,%rdi
  dc:	call   e1 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xe1>
  e1:	test   $0x1,%bpl
  e5:	jne    40 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x40>
  eb:	mov    0x0(%rbp),%ecx
  ee:	cmp    $0x2,%ecx
  f1:	jl     20f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x20f>
  f7:	dec    %ecx
  f9:	mov    %ecx,0x0(%rbp)
  fc:	jmp    40 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x40>
 101:	data16 data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)
 110:	cmp    $0x101,%r15
 117:	jae    152 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x152>
 119:	mov    $0x1,%r12d
 11f:	cmp    $0x80,%r15
 126:	jb     12f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x12f>
 128:	add    $0xffffffffffffff80,%r15
 12c:	mov    %r15,%r12
 12f:	test   $0x1,%r12b
 133:	jne    179 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x179>
 135:	mov    %r12,%rdi
 138:	call   13d <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x13d>
 13d:	mov    (%r12),%ecx
 141:	cmp    $0x2,%ecx
 144:	jl     27c <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x27c>
 14a:	dec    %ecx
 14c:	mov    %ecx,(%r12)
 150:	jmp    17f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x17f>
 152:	mov    0x8(%rsp),%rdi
 157:	mov    %r15,%rsi
 15a:	call   15f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x15f>
 15f:	movzbl %al,%esi
 162:	mov    %rbp,%rdi
 165:	call   16a <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x16a>
 16a:	test   $0x1,%bpl
 16e:	jne    40 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x40>
 174:	jmp    eb <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xeb>
 179:	shr    $1,%r12
 17c:	mov    %r12,%rax
 17f:	xor    %esi,%esi
 181:	mov    0x18(%rsp),%rcx
 186:	jmp    d1 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xd1>
 18b:	mov    $0x3,%esi
 190:	mov    0x10(%rsp),%rdi
 195:	call   19a <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x19a>
 19a:	mov    %rax,%r12
 19d:	test   $0x1,%r12b
 1a1:	jne    8e <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x8e>
 1a7:	mov    %r12,%rdi
 1aa:	mov    %r14,%rsi
 1ad:	call   1b2 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x1b2>
 1b2:	mov    %rax,%r15
 1b5:	mov    (%r12),%eax
 1b9:	cmp    $0x2,%eax
 1bc:	jl     297 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x297>
 1c2:	dec    %eax
 1c4:	mov    %eax,(%r12)
 1c8:	jmp    b1 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xb1>
 1cd:	mov    %r12,%rdi
 1d0:	mov    %r14,%rsi
 1d3:	call   1d8 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x1d8>
 1d8:	mov    %rax,%r15
 1db:	jmp    b1 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xb1>
 1e0:	mov    $0x81,%esi
 1e5:	mov    %r15,%rdi
 1e8:	call   1ed <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x1ed>
 1ed:	test   %al,%al
 1ef:	je     22a <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x22a>
 1f1:	mov    %r15,%rdi
 1f4:	call   1f9 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x1f9>
 1f9:	mov    (%r15),%ecx
 1fc:	cmp    $0x2,%ecx
 1ff:	jl     2ac <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2ac>
 205:	dec    %ecx
 207:	mov    %ecx,(%r15)
 20a:	jmp    ca <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xca>
 20f:	test   %ecx,%ecx
 211:	je     40 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x40>
 217:	mov    %rbp,%rdi
 21a:	mov    %rax,%r14
 21d:	call   222 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x222>
 222:	mov    %r14,%rax
 225:	jmp    40 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x40>
 22a:	mov    $0x101,%esi
 22f:	mov    %r15,%rdi
 232:	call   237 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x237>
 237:	test   %al,%al
 239:	je     25d <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x25d>
 23b:	mov    $0x81,%esi
 240:	mov    %r15,%rdi
 243:	call   248 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x248>
 248:	mov    %rax,%r12
 24b:	mov    (%r15),%eax
 24e:	cmp    $0x2,%eax
 251:	jl     2c3 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2c3>
 253:	dec    %eax
 255:	mov    %eax,(%r15)
 258:	jmp    12f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x12f>
 25d:	mov    0x8(%rsp),%rdi
 262:	mov    %r15,%rsi
 265:	call   26a <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x26a>
 26a:	mov    (%r15),%ecx
 26d:	cmp    $0x2,%ecx
 270:	jl     2d8 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2d8>
 272:	dec    %ecx
 274:	mov    %ecx,(%r15)
 277:	jmp    15f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x15f>
 27c:	test   %ecx,%ecx
 27e:	je     17f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x17f>
 284:	mov    %r12,%rdi
 287:	mov    %rax,%r14
 28a:	call   28f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x28f>
 28f:	mov    %r14,%rax
 292:	jmp    17f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x17f>
 297:	test   %eax,%eax
 299:	je     b1 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xb1>
 29f:	mov    %r12,%rdi
 2a2:	call   2a7 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2a7>
 2a7:	jmp    b1 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xb1>
 2ac:	mov    %rax,%r14
 2af:	test   %ecx,%ecx
 2b1:	je     2bb <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2bb>
 2b3:	mov    %r15,%rdi
 2b6:	call   2bb <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2bb>
 2bb:	mov    %r14,%rax
 2be:	jmp    ca <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xca>
 2c3:	test   %eax,%eax
 2c5:	je     12f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x12f>
 2cb:	mov    %r15,%rdi
 2ce:	call   2d3 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2d3>
 2d3:	jmp    12f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x12f>
 2d8:	mov    %eax,%r14d
 2db:	test   %ecx,%ecx
 2dd:	je     2e7 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2e7>
 2df:	mov    %r15,%rdi
 2e2:	call   2e7 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2e7>
 2e7:	mov    %r14d,%eax
 2ea:	jmp    15f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x15f>
 2ef:	mov    %rbp,%rax
 2f2:	add    $0x28,%rsp
 2f6:	pop    %rbx
 2f7:	pop    %r12
 2f9:	pop    %r13
 2fb:	pop    %r14
 2fd:	pop    %r15
 2ff:	pop    %rbp
 300:	ret

Disassembly of section .text.lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_syndrome:

Disassembly of section .text._init_lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_syndrome___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_checksum:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_checksum___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_interrogator:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_interrogator___boxed:

Disassembly of section .text.initialize_lean1090_Impl_Parity:
