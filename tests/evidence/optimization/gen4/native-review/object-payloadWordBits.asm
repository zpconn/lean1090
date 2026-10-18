
.lake/build/ir/Impl/PayloadBits.c.o.export:     file format elf64-x86-64


Disassembly of section .text.lp_lean1090_Lean1090_Impl_payloadWordBits:

0000000000000000 <lp_lean1090_Lean1090_Impl_payloadWordBits>:
   0:	push   %r15
   2:	push   %r14
   4:	push   %rbx
   5:	mov    %rdx,%r14
   8:	mov    %rsi,%r15
   b:	mov    %rdi,%rbx
   e:	test   $0x1,%r15b
  12:	jne    2a <lp_lean1090_Lean1090_Impl_payloadWordBits+0x2a>
  14:	mov    %r15,%rdi
  17:	call   1c <lp_lean1090_Lean1090_Impl_payloadWordBits+0x1c>
  1c:	mov    %rax,%r15
  1f:	test   $0x1,%r14b
  23:	je     33 <lp_lean1090_Lean1090_Impl_payloadWordBits+0x33>
  25:	shr    $1,%r14
  28:	jmp    3e <lp_lean1090_Lean1090_Impl_payloadWordBits+0x3e>
  2a:	shr    $1,%r15
  2d:	test   $0x1,%r14b
  31:	jne    25 <lp_lean1090_Lean1090_Impl_payloadWordBits+0x25>
  33:	mov    %r14,%rdi
  36:	call   3b <lp_lean1090_Lean1090_Impl_payloadWordBits+0x3b>
  3b:	mov    %rax,%r14
  3e:	mov    %r15d,%ecx
  41:	shr    %cl,%rbx
  44:	mov    $0xffffffffffffffff,%rax
  4b:	mov    %r14d,%ecx
  4e:	shl    %cl,%rax
  51:	not    %rax
  54:	and    %rbx,%rax
  57:	lea    0x1(,%rax,2),%rax
  5f:	pop    %rbx
  60:	pop    %r14
  62:	pop    %r15
  64:	ret

Disassembly of section .text.lp_lean1090_Lean1090_Impl_payloadWordBits___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_payloadBits:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_payloadBits___boxed:

Disassembly of section .text.lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_decodePayloadFields_spec__0:

Disassembly of section .text.lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_decodePayloadFields_spec__0___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_decodePayloadFields:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_decodePayloadFields___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_payloadInteger:

Disassembly of section .text._init_lp_lean1090_Lean1090_Impl_payloadInteger___closed__0:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_payloadInteger___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_payloadValue:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_payloadValue___boxed:

Disassembly of section .text.initialize_lean1090_Impl_PayloadBits:
