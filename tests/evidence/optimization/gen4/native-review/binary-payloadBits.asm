
.lake/build/bin/lean1090:     file format elf64-x86-64


Disassembly of section .text:

0000000000b4e540 <lp_lean1090_Lean1090_Impl_payloadBits>:
  b4e540:	push   %r15
  b4e542:	push   %r14
  b4e544:	push   %r12
  b4e546:	push   %rbx
  b4e547:	push   %rax
  b4e548:	mov    %rdx,%rbx
  b4e54b:	mov    %rdi,%r14
  b4e54e:	test   $0x1,%sil
  b4e552:	je     b4e650 <lp_lean1090_Lean1090_Impl_payloadBits+0x110>
  b4e558:	mov    $0x1,%r15d
  b4e55e:	cmp    $0x2,%rsi
  b4e562:	jb     b4e56b <lp_lean1090_Lean1090_Impl_payloadBits+0x2b>
  b4e564:	add    $0xfffffffffffffffe,%rsi
  b4e568:	mov    %rsi,%r15
  b4e56b:	test   $0x1,%r15b
  b4e56f:	je     b4e66a <lp_lean1090_Lean1090_Impl_payloadBits+0x12a>
  b4e575:	test   $0x1,%bl
  b4e578:	je     b4e7ad <lp_lean1090_Lean1090_Impl_payloadBits+0x26d>
  b4e57e:	shr    $1,%r15
  b4e581:	mov    %rbx,%rdi
  b4e584:	shr    $1,%rdi
  b4e587:	add    %r15,%rdi
  b4e58a:	js     b4e7bd <lp_lean1090_Lean1090_Impl_payloadBits+0x27d>
  b4e590:	lea    0x1(,%rdi,2),%rax
  b4e598:	test   $0x1,%al
  b4e59a:	je     b4e68b <lp_lean1090_Lean1090_Impl_payloadBits+0x14b>
  b4e5a0:	mov    $0x1,%r15d
  b4e5a6:	cmp    $0x71,%rax
  b4e5aa:	ja     b4e5b9 <lp_lean1090_Lean1090_Impl_payloadBits+0x79>
  b4e5ac:	and    $0xfffffffffffffffe,%rax
  b4e5b0:	mov    $0x71,%r15d
  b4e5b6:	sub    %rax,%r15
  b4e5b9:	test   $0x1,%bl
  b4e5bc:	je     b4e6b6 <lp_lean1090_Lean1090_Impl_payloadBits+0x176>
  b4e5c2:	cmp    $0x81,%rbx
  b4e5c9:	jae    b4e6cb <lp_lean1090_Lean1090_Impl_payloadBits+0x18b>
  b4e5cf:	test   $0x1,%r14b
  b4e5d3:	jne    b4e601 <lp_lean1090_Lean1090_Impl_payloadBits+0xc1>
  b4e5d5:	mov    %r14,%rdi
  b4e5d8:	call   4897df0 <lean_uint64_of_big_nat>
  b4e5dd:	mov    %rax,%r14
  b4e5e0:	test   $0x1,%r15b
  b4e5e4:	je     b4e60a <lp_lean1090_Lean1090_Impl_payloadBits+0xca>
  b4e5e6:	shr    $1,%r15
  b4e5e9:	mov    %r15,%rcx
  b4e5ec:	shr    %cl,%r14
  b4e5ef:	test   $0x1,%bl
  b4e5f2:	jne    b4e62e <lp_lean1090_Lean1090_Impl_payloadBits+0xee>
  b4e5f4:	mov    %rbx,%rdi
  b4e5f7:	call   4897df0 <lean_uint64_of_big_nat>
  b4e5fc:	mov    %rax,%rbx
  b4e5ff:	jmp    b4e631 <lp_lean1090_Lean1090_Impl_payloadBits+0xf1>
  b4e601:	shr    $1,%r14
  b4e604:	test   $0x1,%r15b
  b4e608:	jne    b4e5e6 <lp_lean1090_Lean1090_Impl_payloadBits+0xa6>
  b4e60a:	mov    %r15,%rdi
  b4e60d:	call   4897df0 <lean_uint64_of_big_nat>
  b4e612:	mov    %rax,%rcx
  b4e615:	mov    (%r15),%eax
  b4e618:	cmp    $0x2,%eax
  b4e61b:	jl     b4e853 <lp_lean1090_Lean1090_Impl_payloadBits+0x313>
  b4e621:	dec    %eax
  b4e623:	mov    %eax,(%r15)
  b4e626:	shr    %cl,%r14
  b4e629:	test   $0x1,%bl
  b4e62c:	je     b4e5f4 <lp_lean1090_Lean1090_Impl_payloadBits+0xb4>
  b4e62e:	shr    $1,%rbx
  b4e631:	mov    $0xffffffffffffffff,%rax
  b4e638:	mov    %ebx,%ecx
  b4e63a:	shl    %cl,%rax
  b4e63d:	not    %rax
  b4e640:	and    %rax,%r14
  b4e643:	lea    0x1(,%r14,2),%rax
  b4e64b:	jmp    b4e7a1 <lp_lean1090_Lean1090_Impl_payloadBits+0x261>
  b4e650:	mov    %rsi,%rdi
  b4e653:	mov    $0x3,%esi
  b4e658:	call   48946d0 <lean_nat_big_sub>
  b4e65d:	mov    %rax,%r15
  b4e660:	test   $0x1,%r15b
  b4e664:	jne    b4e575 <lp_lean1090_Lean1090_Impl_payloadBits+0x35>
  b4e66a:	mov    %r15,%rdi
  b4e66d:	mov    %rbx,%rsi
  b4e670:	call   48944b0 <lean_nat_big_add>
  b4e675:	mov    (%r15),%ecx
  b4e678:	cmp    $0x2,%ecx
  b4e67b:	jl     b4e88b <lp_lean1090_Lean1090_Impl_payloadBits+0x34b>
  b4e681:	dec    %ecx
  b4e683:	mov    %ecx,(%r15)
  b4e686:	jmp    b4e598 <lp_lean1090_Lean1090_Impl_payloadBits+0x58>
  b4e68b:	mov    $0x71,%edi
  b4e690:	mov    %rax,%rsi
  b4e693:	mov    %rax,%r12
  b4e696:	call   48946d0 <lean_nat_big_sub>
  b4e69b:	mov    %rax,%r15
  b4e69e:	mov    (%r12),%eax
  b4e6a2:	cmp    $0x2,%eax
  b4e6a5:	jl     b4e8a2 <lp_lean1090_Lean1090_Impl_payloadBits+0x362>
  b4e6ab:	dec    %eax
  b4e6ad:	mov    %eax,(%r12)
  b4e6b1:	jmp    b4e5b9 <lp_lean1090_Lean1090_Impl_payloadBits+0x79>
  b4e6b6:	mov    $0x81,%esi
  b4e6bb:	mov    %rbx,%rdi
  b4e6be:	call   48952a0 <lean_nat_big_lt>
  b4e6c3:	test   %al,%al
  b4e6c5:	jne    b4e5cf <lp_lean1090_Lean1090_Impl_payloadBits+0x8f>
  b4e6cb:	mov    $0x5,%edi
  b4e6d0:	mov    %r15,%rsi
  b4e6d3:	call   4895d40 <lean_nat_pow>
  b4e6d8:	mov    %rax,%r12
  b4e6db:	test   $0x1,%r15b
  b4e6df:	jne    b4e6f2 <lp_lean1090_Lean1090_Impl_payloadBits+0x1b2>
  b4e6e1:	mov    (%r15),%eax
  b4e6e4:	cmp    $0x2,%eax
  b4e6e7:	jl     b4e876 <lp_lean1090_Lean1090_Impl_payloadBits+0x336>
  b4e6ed:	dec    %eax
  b4e6ef:	mov    %eax,(%r15)
  b4e6f2:	movabs $0x7fffffff00000000,%r15
  b4e6fc:	test   $0x1,%r14b
  b4e700:	je     b4e7c7 <lp_lean1090_Lean1090_Impl_payloadBits+0x287>
  b4e706:	test   $0x1,%r12b
  b4e70a:	je     b4e7f3 <lp_lean1090_Lean1090_Impl_payloadBits+0x2b3>
  b4e710:	shr    $1,%r12
  b4e713:	je     b4e72d <lp_lean1090_Lean1090_Impl_payloadBits+0x1ed>
  b4e715:	shr    $1,%r14
  b4e718:	mov    %r14,%rax
  b4e71b:	or     %r12,%rax
  b4e71e:	test   %r15,%rax
  b4e721:	je     b4e735 <lp_lean1090_Lean1090_Impl_payloadBits+0x1f5>
  b4e723:	mov    %r14,%rax
  b4e726:	xor    %edx,%edx
  b4e728:	div    %r12
  b4e72b:	jmp    b4e73d <lp_lean1090_Lean1090_Impl_payloadBits+0x1fd>
  b4e72d:	mov    $0x1,%r14d
  b4e733:	jmp    b4e745 <lp_lean1090_Lean1090_Impl_payloadBits+0x205>
  b4e735:	mov    %r14d,%eax
  b4e738:	xor    %edx,%edx
  b4e73a:	div    %r12d
  b4e73d:	lea    0x1(,%rax,2),%r14
  b4e745:	mov    $0x5,%edi
  b4e74a:	mov    %rbx,%rsi
  b4e74d:	call   4895d40 <lean_nat_pow>
  b4e752:	mov    %rax,%rbx
  b4e755:	test   $0x1,%r14b
  b4e759:	je     b4e7e1 <lp_lean1090_Lean1090_Impl_payloadBits+0x2a1>
  b4e75f:	test   $0x1,%bl
  b4e762:	je     b4e819 <lp_lean1090_Lean1090_Impl_payloadBits+0x2d9>
  b4e768:	shr    $1,%rbx
  b4e76b:	je     b4e78d <lp_lean1090_Lean1090_Impl_payloadBits+0x24d>
  b4e76d:	shr    $1,%r14
  b4e770:	mov    %r14,%rax
  b4e773:	or     %rbx,%rax
  b4e776:	test   %r15,%rax
  b4e779:	je     b4e792 <lp_lean1090_Lean1090_Impl_payloadBits+0x252>
  b4e77b:	mov    %r14,%rax
  b4e77e:	xor    %edx,%edx
  b4e780:	div    %rbx
  b4e783:	lea    0x1(,%rdx,2),%rax
  b4e78b:	jmp    b4e7a1 <lp_lean1090_Lean1090_Impl_payloadBits+0x261>
  b4e78d:	mov    %r14,%rax
  b4e790:	jmp    b4e7a1 <lp_lean1090_Lean1090_Impl_payloadBits+0x261>
  b4e792:	mov    %r14d,%eax
  b4e795:	xor    %edx,%edx
  b4e797:	div    %ebx
  b4e799:	lea    0x1(,%rdx,2),%rax
  b4e7a1:	add    $0x8,%rsp
  b4e7a5:	pop    %rbx
  b4e7a6:	pop    %r12
  b4e7a8:	pop    %r14
  b4e7aa:	pop    %r15
  b4e7ac:	ret
  b4e7ad:	mov    %r15,%rdi
  b4e7b0:	mov    %rbx,%rsi
  b4e7b3:	call   48944b0 <lean_nat_big_add>
  b4e7b8:	jmp    b4e598 <lp_lean1090_Lean1090_Impl_payloadBits+0x58>
  b4e7bd:	call   4894310 <lean_big_usize_to_nat>
  b4e7c2:	jmp    b4e598 <lp_lean1090_Lean1090_Impl_payloadBits+0x58>
  b4e7c7:	mov    %r14,%rdi
  b4e7ca:	mov    %r12,%rsi
  b4e7cd:	call   4894c70 <lean_nat_big_div>
  b4e7d2:	mov    %rax,%r14
  b4e7d5:	test   $0x1,%r12b
  b4e7d9:	jne    b4e745 <lp_lean1090_Lean1090_Impl_payloadBits+0x205>
  b4e7df:	jmp    b4e801 <lp_lean1090_Lean1090_Impl_payloadBits+0x2c1>
  b4e7e1:	mov    %r14,%rdi
  b4e7e4:	mov    %rbx,%rsi
  b4e7e7:	call   4895010 <lean_nat_big_mod>
  b4e7ec:	test   $0x1,%bl
  b4e7ef:	je     b4e824 <lp_lean1090_Lean1090_Impl_payloadBits+0x2e4>
  b4e7f1:	jmp    b4e83d <lp_lean1090_Lean1090_Impl_payloadBits+0x2fd>
  b4e7f3:	mov    %r14,%rdi
  b4e7f6:	mov    %r12,%rsi
  b4e7f9:	call   4894c70 <lean_nat_big_div>
  b4e7fe:	mov    %rax,%r14
  b4e801:	mov    (%r12),%eax
  b4e805:	cmp    $0x2,%eax
  b4e808:	jl     b4e8b7 <lp_lean1090_Lean1090_Impl_payloadBits+0x377>
  b4e80e:	dec    %eax
  b4e810:	mov    %eax,(%r12)
  b4e814:	jmp    b4e745 <lp_lean1090_Lean1090_Impl_payloadBits+0x205>
  b4e819:	mov    %r14,%rdi
  b4e81c:	mov    %rbx,%rsi
  b4e81f:	call   4895010 <lean_nat_big_mod>
  b4e824:	mov    (%rbx),%ecx
  b4e826:	cmp    $0x2,%ecx
  b4e829:	jl     b4e8cc <lp_lean1090_Lean1090_Impl_payloadBits+0x38c>
  b4e82f:	dec    %ecx
  b4e831:	mov    %ecx,(%rbx)
  b4e833:	test   $0x1,%r14b
  b4e837:	jne    b4e7a1 <lp_lean1090_Lean1090_Impl_payloadBits+0x261>
  b4e83d:	mov    (%r14),%ecx
  b4e840:	cmp    $0x2,%ecx
  b4e843:	jl     b4e8e7 <lp_lean1090_Lean1090_Impl_payloadBits+0x3a7>
  b4e849:	dec    %ecx
  b4e84b:	mov    %ecx,(%r14)
  b4e84e:	jmp    b4e7a1 <lp_lean1090_Lean1090_Impl_payloadBits+0x261>
  b4e853:	mov    %rcx,%r12
  b4e856:	test   %eax,%eax
  b4e858:	je     b4e862 <lp_lean1090_Lean1090_Impl_payloadBits+0x322>
  b4e85a:	mov    %r15,%rdi
  b4e85d:	call   4891df0 <lean_dec_ref_cold>
  b4e862:	mov    %r12,%rcx
  b4e865:	shr    %cl,%r14
  b4e868:	test   $0x1,%bl
  b4e86b:	je     b4e5f4 <lp_lean1090_Lean1090_Impl_payloadBits+0xb4>
  b4e871:	jmp    b4e62e <lp_lean1090_Lean1090_Impl_payloadBits+0xee>
  b4e876:	test   %eax,%eax
  b4e878:	je     b4e6f2 <lp_lean1090_Lean1090_Impl_payloadBits+0x1b2>
  b4e87e:	mov    %r15,%rdi
  b4e881:	call   4891df0 <lean_dec_ref_cold>
  b4e886:	jmp    b4e6f2 <lp_lean1090_Lean1090_Impl_payloadBits+0x1b2>
  b4e88b:	mov    %rax,%r12
  b4e88e:	test   %ecx,%ecx
  b4e890:	je     b4e89a <lp_lean1090_Lean1090_Impl_payloadBits+0x35a>
  b4e892:	mov    %r15,%rdi
  b4e895:	call   4891df0 <lean_dec_ref_cold>
  b4e89a:	mov    %r12,%rax
  b4e89d:	jmp    b4e598 <lp_lean1090_Lean1090_Impl_payloadBits+0x58>
  b4e8a2:	test   %eax,%eax
  b4e8a4:	je     b4e5b9 <lp_lean1090_Lean1090_Impl_payloadBits+0x79>
  b4e8aa:	mov    %r12,%rdi
  b4e8ad:	call   4891df0 <lean_dec_ref_cold>
  b4e8b2:	jmp    b4e5b9 <lp_lean1090_Lean1090_Impl_payloadBits+0x79>
  b4e8b7:	test   %eax,%eax
  b4e8b9:	je     b4e745 <lp_lean1090_Lean1090_Impl_payloadBits+0x205>
  b4e8bf:	mov    %r12,%rdi
  b4e8c2:	call   4891df0 <lean_dec_ref_cold>
  b4e8c7:	jmp    b4e745 <lp_lean1090_Lean1090_Impl_payloadBits+0x205>
  b4e8cc:	test   %ecx,%ecx
  b4e8ce:	je     b4e833 <lp_lean1090_Lean1090_Impl_payloadBits+0x2f3>
  b4e8d4:	mov    %rbx,%rdi
  b4e8d7:	mov    %rax,%rbx
  b4e8da:	call   4891df0 <lean_dec_ref_cold>
  b4e8df:	mov    %rbx,%rax
  b4e8e2:	jmp    b4e833 <lp_lean1090_Lean1090_Impl_payloadBits+0x2f3>
  b4e8e7:	mov    %rax,%rbx
  b4e8ea:	test   %ecx,%ecx
  b4e8ec:	je     b4e8f6 <lp_lean1090_Lean1090_Impl_payloadBits+0x3b6>
  b4e8ee:	mov    %r14,%rdi
  b4e8f1:	call   4891df0 <lean_dec_ref_cold>
  b4e8f6:	mov    %rbx,%rax
  b4e8f9:	jmp    b4e7a1 <lp_lean1090_Lean1090_Impl_payloadBits+0x261>

Disassembly of section .init:

Disassembly of section .fini:

Disassembly of section .plt:
