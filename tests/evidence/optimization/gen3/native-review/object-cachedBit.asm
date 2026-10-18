
.lake/build/ir/Impl/Parity.c.o.export:     file format elf64-x86-64


Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_step:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_step___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_wordBit:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_wordBit___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_cachedBit:

0000000000000000 <lp_lean1090_Lean1090_Impl_Parity_cachedBit>:
   0:	push   %r15
   2:	push   %r14
   4:	push   %r12
   6:	push   %rbx
   7:	push   %rax
   8:	test   $0x1,%cl
   b:	je     73 <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x73>
   d:	cmp    $0x81,%rcx
  14:	jae    2c <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x2c>
  16:	shr    $1,%rcx
  19:	bt     %rcx,%rsi
  1d:	setb   %al
  20:	add    $0x8,%rsp
  24:	pop    %rbx
  25:	pop    %r12
  27:	pop    %r14
  29:	pop    %r15
  2b:	ret
  2c:	cmp    $0x101,%rcx
  33:	jae    de <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0xde>
  39:	mov    $0x1,%ebx
  3e:	cmp    $0x80,%rcx
  45:	jb     4e <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x4e>
  47:	add    $0xffffffffffffff80,%rcx
  4b:	mov    %rcx,%rbx
  4e:	test   $0x1,%bl
  51:	jne    d2 <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0xd2>
  53:	mov    %rdx,%r14
  56:	mov    %rbx,%rdi
  59:	call   5e <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x5e>
  5e:	mov    (%rbx),%ecx
  60:	cmp    $0x2,%ecx
  63:	jl     f1 <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0xf1>
  69:	dec    %ecx
  6b:	mov    %ecx,(%rbx)
  6d:	bt     %rax,%r14
  71:	jmp    1d <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x1d>
  73:	mov    %rsi,%r12
  76:	mov    %rdi,%r15
  79:	mov    %rdx,%r14
  7c:	mov    $0x81,%esi
  81:	mov    %rcx,%rbx
  84:	mov    %rcx,%rdi
  87:	call   8c <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x8c>
  8c:	test   %al,%al
  8e:	je     a3 <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0xa3>
  90:	mov    %rbx,%rdi
  93:	call   98 <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x98>
  98:	mov    %rax,%rcx
  9b:	mov    %r12,%rsi
  9e:	jmp    19 <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x19>
  a3:	mov    $0x101,%esi
  a8:	mov    %rbx,%rdi
  ab:	call   b0 <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0xb0>
  b0:	mov    %rbx,%rcx
  b3:	test   %al,%al
  b5:	mov    %r15,%rdi
  b8:	je     de <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0xde>
  ba:	mov    $0x81,%esi
  bf:	mov    %rcx,%rdi
  c2:	call   c7 <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0xc7>
  c7:	mov    %r14,%rdx
  ca:	mov    %rax,%rbx
  cd:	test   $0x1,%bl
  d0:	je     53 <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x53>
  d2:	shr    $1,%rbx
  d5:	bt     %rbx,%rdx
  d9:	jmp    1d <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x1d>
  de:	mov    %rcx,%rsi
  e1:	add    $0x8,%rsp
  e5:	pop    %rbx
  e6:	pop    %r12
  e8:	pop    %r14
  ea:	pop    %r15
  ec:	jmp    f1 <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0xf1>
  f1:	mov    %rax,%r15
  f4:	test   %ecx,%ecx
  f6:	je     100 <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x100>
  f8:	mov    %rbx,%rdi
  fb:	call   100 <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x100>
 100:	bt     %r15,%r14
 104:	jmp    1d <lp_lean1090_Lean1090_Impl_Parity_cachedBit+0x1d>

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_cachedBit___boxed:

Disassembly of section .text.lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0:

Disassembly of section .text.lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_syndrome:

Disassembly of section .text._init_lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_syndrome___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_checksum:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_checksum___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_interrogator:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_interrogator___boxed:

Disassembly of section .text.initialize_lean1090_Impl_Parity:
