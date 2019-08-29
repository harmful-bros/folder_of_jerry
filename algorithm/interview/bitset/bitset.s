	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## BB#0:
	pushq	%rbp
Ltmp5:
	.cfi_def_cfa_offset 16
Ltmp6:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp7:
	.cfi_def_cfa_register %rbp
	subq	$592, %rsp              ## imm = 0x250
	leaq	-401(%rbp), %rax
	movl	$0, -500(%rbp)
	leaq	-512(%rbp), %rcx
	movq	%rcx, -496(%rbp)
	movq	%rcx, -488(%rbp)
	movq	%rcx, -480(%rbp)
	movq	$0, -512(%rbp)
	leaq	-520(%rbp), %rdx
	movq	%rdx, -448(%rbp)
	movq	$255, -456(%rbp)
	movq	-448(%rbp), %rdx
	movq	%rdx, -432(%rbp)
	movq	$255, -440(%rbp)
	movq	-432(%rbp), %rdx
	movq	%rdx, -416(%rbp)
	movq	$255, -424(%rbp)
	movq	-416(%rbp), %rdx
	movq	$255, (%rdx)
	movq	-520(%rbp), %rdx
	movq	%rdx, -512(%rbp)
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	movq	%rcx, %rsi
	movq	%rax, -552(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__1lsIcNS_11char_traitsIcEELm8EEERNS_13basic_ostreamIT_T0_EES7_RKNS_6bitsetIXT1_EEE
	movq	%rax, -80(%rbp)
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rax
	movq	%rax, -88(%rbp)
	movq	-80(%rbp), %rdi
	callq	*%rax
	movl	$5, -524(%rbp)
	movl	$32, -528(%rbp)
	leaq	-536(%rbp), %rcx
	movq	%rcx, -72(%rbp)
	movq	%rcx, -64(%rbp)
	movq	%rcx, -56(%rbp)
	movq	$0, -536(%rbp)
	movl	-524(%rbp), %r8d
	movl	-528(%rbp), %r9d
	xorl	%r9d, %r8d
	movslq	%r8d, %rdx
	leaq	-544(%rbp), %rsi
	movq	%rsi, -40(%rbp)
	movq	%rdx, -48(%rbp)
	movq	-40(%rbp), %rsi
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	movq	-24(%rbp), %rsi
	movq	%rsi, -8(%rbp)
	movq	%rdx, -16(%rbp)
	movq	-8(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-544(%rbp), %rdx
	movq	%rdx, -536(%rbp)
	movq	%rcx, -368(%rbp)
	movq	%rcx, -352(%rbp)
	movq	$0, -360(%rbp)
	movq	-352(%rbp), %rdx
	leaq	-344(%rbp), %rsi
	movq	%rsi, -312(%rbp)
	movq	%rdx, -320(%rbp)
	movl	$0, -324(%rbp)
	movq	-312(%rbp), %rdx
	movq	-320(%rbp), %rsi
	movq	%rdx, -288(%rbp)
	movq	%rsi, -296(%rbp)
	movl	$0, -300(%rbp)
	movq	-288(%rbp), %rdx
	movq	-296(%rbp), %rsi
	movq	%rsi, (%rdx)
	movl	-300(%rbp), %r8d
	movl	%r8d, 8(%rdx)
	movl	-336(%rbp), %r8d
	movq	-344(%rbp), %rdx
	movq	%rdx, -384(%rbp)
	movl	%r8d, -376(%rbp)
	movq	%rcx, -272(%rbp)
	movq	$6, -280(%rbp)
	movq	-272(%rbp), %rcx
	leaq	-264(%rbp), %rdx
	movq	%rdx, -232(%rbp)
	movq	%rcx, -240(%rbp)
	movl	$6, -244(%rbp)
	movq	-232(%rbp), %rcx
	movq	-240(%rbp), %rdx
	movq	%rcx, -208(%rbp)
	movq	%rdx, -216(%rbp)
	movl	$6, -220(%rbp)
	movq	-208(%rbp), %rcx
	movq	-216(%rbp), %rdx
	movq	%rdx, (%rcx)
	movl	-220(%rbp), %r8d
	movl	%r8d, 8(%rcx)
	movl	-256(%rbp), %r8d
	movq	-264(%rbp), %rcx
	movq	%rcx, -400(%rbp)
	movl	%r8d, -392(%rbp)
	movb	$1, -401(%rbp)
	movq	-384(%rbp), %rcx
	movl	-376(%rbp), %r8d
	movq	-400(%rbp), %rdx
	movl	-392(%rbp), %r9d
	movq	%rcx, -144(%rbp)
	movl	%r8d, -136(%rbp)
	movq	%rdx, -160(%rbp)
	movl	%r9d, -152(%rbp)
	movq	-552(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -168(%rbp)
	movq	-168(%rbp), %rdx
	testb	$1, (%rdx)
	movq	%rax, -560(%rbp)        ## 8-byte Spill
	je	LBB0_3
## BB#1:
	movq	-144(%rbp), %rax
	movq	-136(%rbp), %rcx
	movq	%rcx, -176(%rbp)
	movq	%rax, -184(%rbp)
	leaq	-160(%rbp), %rax
	movq	%rax, -112(%rbp)
	leaq	-144(%rbp), %rax
	movq	%rax, -120(%rbp)
	movq	-112(%rbp), %rax
	movq	(%rax), %rcx
	movq	-144(%rbp), %rdx
	subq	%rdx, %rcx
	movl	8(%rax), %esi
	movl	%esi, %eax
	leaq	(%rax,%rcx,8), %rax
	movl	-136(%rbp), %esi
	movl	%esi, %ecx
	subq	%rcx, %rax
	movq	-184(%rbp), %rdi
	movl	-176(%rbp), %esi
Ltmp2:
	movq	%rax, %rdx
	callq	__ZNSt3__117__count_bool_trueINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeE
Ltmp3:
	movq	%rax, -568(%rbp)        ## 8-byte Spill
	jmp	LBB0_2
LBB0_2:                                 ## %.noexc.i
	movq	-568(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -128(%rbp)
	jmp	LBB0_6
LBB0_3:
	movq	-144(%rbp), %rax
	movq	-136(%rbp), %rcx
	movq	%rcx, -192(%rbp)
	movq	%rax, -200(%rbp)
	leaq	-160(%rbp), %rax
	movq	%rax, -96(%rbp)
	leaq	-144(%rbp), %rax
	movq	%rax, -104(%rbp)
	movq	-96(%rbp), %rax
	movq	(%rax), %rcx
	movq	-144(%rbp), %rdx
	subq	%rdx, %rcx
	movl	8(%rax), %esi
	movl	%esi, %eax
	leaq	(%rax,%rcx,8), %rax
	movl	-136(%rbp), %esi
	movl	%esi, %ecx
	subq	%rcx, %rax
	movq	-200(%rbp), %rdi
	movl	-192(%rbp), %esi
Ltmp0:
	movq	%rax, %rdx
	callq	__ZNSt3__118__count_bool_falseINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeE
Ltmp1:
	movq	%rax, -576(%rbp)        ## 8-byte Spill
	jmp	LBB0_4
LBB0_4:                                 ## %.noexc1.i
	movq	-576(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -128(%rbp)
	jmp	LBB0_6
LBB0_5:
Ltmp4:
	movl	%edx, %ecx
	movq	%rax, %rdi
	movl	%ecx, -580(%rbp)        ## 4-byte Spill
	callq	___clang_call_terminate
LBB0_6:                                 ## %_ZNKSt3__16bitsetILm6EE5countEv.exit
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	movq	-128(%rbp), %rsi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEm
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rsi
	movq	%rax, -464(%rbp)
	movq	%rsi, -472(%rbp)
	movq	-464(%rbp), %rdi
	callq	*-472(%rbp)
	xorl	%ecx, %ecx
	movq	%rax, -592(%rbp)        ## 8-byte Spill
	movl	%ecx, %eax
	addq	$592, %rsp              ## imm = 0x250
	popq	%rbp
	retq
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table0:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\257\200"              ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset0 = Lfunc_begin0-Lfunc_begin0       ## >> Call Site 1 <<
	.long	Lset0
Lset1 = Ltmp2-Lfunc_begin0              ##   Call between Lfunc_begin0 and Ltmp2
	.long	Lset1
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset2 = Ltmp2-Lfunc_begin0              ## >> Call Site 2 <<
	.long	Lset2
Lset3 = Ltmp1-Ltmp2                     ##   Call between Ltmp2 and Ltmp1
	.long	Lset3
Lset4 = Ltmp4-Lfunc_begin0              ##     jumps to Ltmp4
	.long	Lset4
	.byte	1                       ##   On action: 1
Lset5 = Ltmp1-Lfunc_begin0              ## >> Call Site 3 <<
	.long	Lset5
Lset6 = Lfunc_end0-Ltmp1                ##   Call between Ltmp1 and Lfunc_end0
	.long	Lset6
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__1lsIcNS_11char_traitsIcEELm8EEERNS_13basic_ostreamIT_T0_EES7_RKNS_6bitsetIXT1_EEE
	.weak_definition	__ZNSt3__1lsIcNS_11char_traitsIcEELm8EEERNS_13basic_ostreamIT_T0_EES7_RKNS_6bitsetIXT1_EEE
	.p2align	4, 0x90
__ZNSt3__1lsIcNS_11char_traitsIcEELm8EEERNS_13basic_ostreamIT_T0_EES7_RKNS_6bitsetIXT1_EEE: ## @_ZNSt3__1lsIcNS_11char_traitsIcEELm8EEERNS_13basic_ostreamIT_T0_EES7_RKNS_6bitsetIXT1_EEE
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
## BB#0:
	pushq	%rbp
Ltmp25:
	.cfi_def_cfa_offset 16
Ltmp26:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp27:
	.cfi_def_cfa_register %rbp
	subq	$224, %rsp
	movq	%rdi, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	-72(%rbp), %rdi
	movq	(%rdi), %rax
	movq	-24(%rax), %rax
	movq	%rdi, %rcx
	addq	%rax, %rcx
	leaq	-112(%rbp), %rax
	movq	%rdi, -144(%rbp)        ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rsi, -152(%rbp)        ## 8-byte Spill
	movq	%rcx, %rsi
	movq	%rax, -160(%rbp)        ## 8-byte Spill
	callq	__ZNKSt3__18ios_base6getlocEv
	movq	-160(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -64(%rbp)
Ltmp8:
	movq	__ZNSt3__15ctypeIcE2idE@GOTPCREL(%rip), %rsi
	movq	%rax, %rdi
	callq	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp9:
	movq	%rax, -168(%rbp)        ## 8-byte Spill
	jmp	LBB1_1
LBB1_1:                                 ## %_ZNSt3__19use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE.exit
	movq	-168(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -176(%rbp)        ## 8-byte Spill
## BB#2:
	movq	-176(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -48(%rbp)
	movb	$48, -49(%rbp)
	movq	-48(%rbp), %rcx
	movq	(%rcx), %rdx
	movq	56(%rdx), %rdx
	movsbl	-49(%rbp), %esi
Ltmp10:
	movq	%rcx, %rdi
	callq	*%rdx
Ltmp11:
	movb	%al, -177(%rbp)         ## 1-byte Spill
	jmp	LBB1_3
LBB1_3:                                 ## %_ZNKSt3__15ctypeIcE5widenEc.exit
	jmp	LBB1_4
LBB1_4:
	movq	-72(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rax
Ltmp12:
	leaq	-136(%rbp), %rdi
	movq	%rax, %rsi
	callq	__ZNKSt3__18ios_base6getlocEv
Ltmp13:
	jmp	LBB1_5
LBB1_5:
	leaq	-136(%rbp), %rax
	movq	%rax, -40(%rbp)
Ltmp15:
	movq	__ZNSt3__15ctypeIcE2idE@GOTPCREL(%rip), %rsi
	movq	%rax, %rdi
	callq	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp16:
	movq	%rax, -192(%rbp)        ## 8-byte Spill
	jmp	LBB1_6
LBB1_6:                                 ## %_ZNSt3__19use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE.exit1
	movq	-192(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -200(%rbp)        ## 8-byte Spill
## BB#7:
	movq	-200(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movb	$49, -25(%rbp)
	movq	-24(%rbp), %rcx
	movq	(%rcx), %rdx
	movq	56(%rdx), %rdx
	movsbl	-25(%rbp), %esi
Ltmp17:
	movq	%rcx, %rdi
	callq	*%rdx
Ltmp18:
	movb	%al, -201(%rbp)         ## 1-byte Spill
	jmp	LBB1_8
LBB1_8:                                 ## %_ZNKSt3__15ctypeIcE5widenEc.exit2
	jmp	LBB1_9
LBB1_9:
	movq	-152(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -8(%rbp)
	movb	-177(%rbp), %cl         ## 1-byte Reload
	movb	%cl, -9(%rbp)
	movb	-201(%rbp), %dl         ## 1-byte Reload
	movb	%dl, -10(%rbp)
	movq	-8(%rbp), %rsi
	movsbl	-10(%rbp), %ecx
	movsbl	-9(%rbp), %edx
Ltmp19:
	leaq	-104(%rbp), %rdi
	callq	__ZNKSt3__16bitsetILm8EE9to_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EES8_S8_
Ltmp20:
	jmp	LBB1_10
LBB1_10:                                ## %_ZNKSt3__16bitsetILm8EE9to_stringIcNS_11char_traitsIcEEEENS_12basic_stringIT_T0_NS_9allocatorIS6_EEEES6_S6_.exit
	jmp	LBB1_11
LBB1_11:
Ltmp22:
	leaq	-104(%rbp), %rsi
	movq	-144(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__1lsIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_ostreamIT_T0_EES9_RKNS_12basic_stringIS6_S7_T1_EE
Ltmp23:
	movq	%rax, -216(%rbp)        ## 8-byte Spill
	jmp	LBB1_12
LBB1_12:
	leaq	-104(%rbp), %rdi
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
	leaq	-136(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	leaq	-112(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movq	-216(%rbp), %rax        ## 8-byte Reload
	addq	$224, %rsp
	popq	%rbp
	retq
LBB1_13:
Ltmp14:
	movl	%edx, %ecx
	movq	%rax, -120(%rbp)
	movl	%ecx, -124(%rbp)
	jmp	LBB1_17
LBB1_14:
Ltmp21:
	movl	%edx, %ecx
	movq	%rax, -120(%rbp)
	movl	%ecx, -124(%rbp)
	jmp	LBB1_16
LBB1_15:
Ltmp24:
	leaq	-104(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -120(%rbp)
	movl	%ecx, -124(%rbp)
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
LBB1_16:
	leaq	-136(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
LBB1_17:
	leaq	-112(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
## BB#18:
	movq	-120(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table1:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\303\200"              ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	65                      ## Call site table length
Lset7 = Lfunc_begin1-Lfunc_begin1       ## >> Call Site 1 <<
	.long	Lset7
Lset8 = Ltmp8-Lfunc_begin1              ##   Call between Lfunc_begin1 and Ltmp8
	.long	Lset8
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset9 = Ltmp8-Lfunc_begin1              ## >> Call Site 2 <<
	.long	Lset9
Lset10 = Ltmp13-Ltmp8                   ##   Call between Ltmp8 and Ltmp13
	.long	Lset10
Lset11 = Ltmp14-Lfunc_begin1            ##     jumps to Ltmp14
	.long	Lset11
	.byte	0                       ##   On action: cleanup
Lset12 = Ltmp15-Lfunc_begin1            ## >> Call Site 3 <<
	.long	Lset12
Lset13 = Ltmp20-Ltmp15                  ##   Call between Ltmp15 and Ltmp20
	.long	Lset13
Lset14 = Ltmp21-Lfunc_begin1            ##     jumps to Ltmp21
	.long	Lset14
	.byte	0                       ##   On action: cleanup
Lset15 = Ltmp22-Lfunc_begin1            ## >> Call Site 4 <<
	.long	Lset15
Lset16 = Ltmp23-Ltmp22                  ##   Call between Ltmp22 and Ltmp23
	.long	Lset16
Lset17 = Ltmp24-Lfunc_begin1            ##     jumps to Ltmp24
	.long	Lset17
	.byte	0                       ##   On action: cleanup
Lset18 = Ltmp23-Lfunc_begin1            ## >> Call Site 5 <<
	.long	Lset18
Lset19 = Lfunc_end1-Ltmp23              ##   Call between Ltmp23 and Lfunc_end1
	.long	Lset19
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.private_extern	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.globl	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.weak_definition	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.p2align	4, 0x90
__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_: ## @_ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception2
## BB#0:
	pushq	%rbp
Ltmp33:
	.cfi_def_cfa_offset 16
Ltmp34:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp35:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movq	%rdi, -72(%rbp)
	movq	%rdi, %rax
	movq	(%rdi), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rdi
	movq	%rdi, -32(%rbp)
	movb	$10, -33(%rbp)
	movq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rcx
	movq	%rcx, %rdi
	movq	%rax, -80(%rbp)         ## 8-byte Spill
	movq	%rcx, -88(%rbp)         ## 8-byte Spill
	callq	__ZNKSt3__18ios_base6getlocEv
	movq	-88(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -24(%rbp)
Ltmp28:
	movq	__ZNSt3__15ctypeIcE2idE@GOTPCREL(%rip), %rsi
	movq	%rax, %rdi
	callq	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp29:
	movq	%rax, -96(%rbp)         ## 8-byte Spill
	jmp	LBB2_1
LBB2_1:                                 ## %_ZNSt3__19use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE.exit.i
	movb	-33(%rbp), %al
	movq	-96(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, -8(%rbp)
	movb	%al, -9(%rbp)
	movq	-8(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	56(%rsi), %rsi
	movsbl	-9(%rbp), %edi
Ltmp30:
	movl	%edi, -100(%rbp)        ## 4-byte Spill
	movq	%rdx, %rdi
	movl	-100(%rbp), %r8d        ## 4-byte Reload
	movq	%rsi, -112(%rbp)        ## 8-byte Spill
	movl	%r8d, %esi
	movq	-112(%rbp), %rdx        ## 8-byte Reload
	callq	*%rdx
Ltmp31:
	movb	%al, -113(%rbp)         ## 1-byte Spill
	jmp	LBB2_3
LBB2_2:
Ltmp32:
	leaq	-48(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -56(%rbp)
	movl	%ecx, -60(%rbp)
	callq	__ZNSt3__16localeD1Ev
	movq	-56(%rbp), %rdi
	callq	__Unwind_Resume
LBB2_3:                                 ## %_ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc.exit
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	movb	-113(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %esi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE3putEc
	movq	-72(%rbp), %rdi
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
	movq	-72(%rbp), %rdi
	movq	%rax, -136(%rbp)        ## 8-byte Spill
	movq	%rdi, %rax
	addq	$144, %rsp
	popq	%rbp
	retq
Lfunc_end2:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table2:
Lexception2:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset20 = Lfunc_begin2-Lfunc_begin2      ## >> Call Site 1 <<
	.long	Lset20
Lset21 = Ltmp28-Lfunc_begin2            ##   Call between Lfunc_begin2 and Ltmp28
	.long	Lset21
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset22 = Ltmp28-Lfunc_begin2            ## >> Call Site 2 <<
	.long	Lset22
Lset23 = Ltmp31-Ltmp28                  ##   Call between Ltmp28 and Ltmp31
	.long	Lset23
Lset24 = Ltmp32-Lfunc_begin2            ##     jumps to Ltmp32
	.long	Lset24
	.byte	0                       ##   On action: cleanup
Lset25 = Ltmp31-Lfunc_begin2            ## >> Call Site 3 <<
	.long	Lset25
Lset26 = Lfunc_end2-Ltmp31              ##   Call between Ltmp31 and Lfunc_end2
	.long	Lset26
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__1lsIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_ostreamIT_T0_EES9_RKNS_12basic_stringIS6_S7_T1_EE
	.weak_definition	__ZNSt3__1lsIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_ostreamIT_T0_EES9_RKNS_12basic_stringIS6_S7_T1_EE
	.p2align	4, 0x90
__ZNSt3__1lsIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_ostreamIT_T0_EES9_RKNS_12basic_stringIS6_S7_T1_EE: ## @_ZNSt3__1lsIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_ostreamIT_T0_EES9_RKNS_12basic_stringIS6_S7_T1_EE
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp36:
	.cfi_def_cfa_offset 16
Ltmp37:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp38:
	.cfi_def_cfa_register %rbp
	subq	$256, %rsp              ## imm = 0x100
	movq	%rdi, -200(%rbp)
	movq	%rsi, -208(%rbp)
	movq	-200(%rbp), %rdi
	movq	-208(%rbp), %rsi
	movq	%rsi, -192(%rbp)
	movq	-192(%rbp), %rsi
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rsi
	movq	%rsi, -176(%rbp)
	movq	-176(%rbp), %rax
	movq	%rax, -168(%rbp)
	movq	-168(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rax
	movzbl	(%rax), %ecx
	andl	$1, %ecx
	cmpl	$0, %ecx
	movq	%rdi, -216(%rbp)        ## 8-byte Spill
	movq	%rsi, -224(%rbp)        ## 8-byte Spill
	je	LBB3_2
## BB#1:
	movq	-224(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -232(%rbp)        ## 8-byte Spill
	jmp	LBB3_3
LBB3_2:
	movq	-224(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -152(%rbp)
	movq	-152(%rbp), %rcx
	movq	%rcx, -144(%rbp)
	movq	-144(%rbp), %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	%rcx, -232(%rbp)        ## 8-byte Spill
LBB3_3:                                 ## %_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4dataEv.exit
	movq	-232(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rsi
	movq	-208(%rbp), %rax
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rcx
	movzbl	(%rcx), %edx
	andl	$1, %edx
	cmpl	$0, %edx
	movq	%rsi, -240(%rbp)        ## 8-byte Spill
	movq	%rax, -248(%rbp)        ## 8-byte Spill
	je	LBB3_5
## BB#4:
	movq	-248(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -256(%rbp)        ## 8-byte Spill
	jmp	LBB3_6
LBB3_5:
	movq	-248(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -256(%rbp)        ## 8-byte Spill
LBB3_6:                                 ## %_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4sizeEv.exit
	movq	-256(%rbp), %rax        ## 8-byte Reload
	movq	-216(%rbp), %rdi        ## 8-byte Reload
	movq	-240(%rbp), %rsi        ## 8-byte Reload
	movq	%rax, %rdx
	callq	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	addq	$256, %rsp              ## imm = 0x100
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.weak_definition	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.p2align	4, 0x90
__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m: ## @_ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
Lfunc_begin3:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception3
## BB#0:
	pushq	%rbp
Ltmp60:
	.cfi_def_cfa_offset 16
Ltmp61:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp62:
	.cfi_def_cfa_register %rbp
	subq	$384, %rsp              ## imm = 0x180
	movq	%rdi, -184(%rbp)
	movq	%rsi, -192(%rbp)
	movq	%rdx, -200(%rbp)
	movq	-184(%rbp), %rsi
Ltmp39:
	leaq	-216(%rbp), %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_
Ltmp40:
	jmp	LBB4_1
LBB4_1:
	leaq	-216(%rbp), %rax
	movq	%rax, -176(%rbp)
	movq	-176(%rbp), %rax
	movb	(%rax), %cl
	movb	%cl, -249(%rbp)         ## 1-byte Spill
## BB#2:
	movb	-249(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB4_3
	jmp	LBB4_26
LBB4_3:
	leaq	-240(%rbp), %rax
	movq	-184(%rbp), %rcx
	movq	%rax, -160(%rbp)
	movq	%rcx, -168(%rbp)
	movq	-160(%rbp), %rax
	movq	-168(%rbp), %rcx
	movq	%rax, -144(%rbp)
	movq	%rcx, -152(%rbp)
	movq	-144(%rbp), %rax
	movq	-152(%rbp), %rcx
	movq	(%rcx), %rdx
	movq	-24(%rdx), %rdx
	addq	%rdx, %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	40(%rcx), %rcx
	movq	%rcx, (%rax)
	movq	-192(%rbp), %rsi
	movq	-184(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movl	8(%rax), %edi
	movq	%rsi, -264(%rbp)        ## 8-byte Spill
	movl	%edi, -268(%rbp)        ## 4-byte Spill
## BB#4:
	movl	-268(%rbp), %eax        ## 4-byte Reload
	andl	$176, %eax
	cmpl	$32, %eax
	jne	LBB4_6
## BB#5:
	movq	-192(%rbp), %rax
	addq	-200(%rbp), %rax
	movq	%rax, -280(%rbp)        ## 8-byte Spill
	jmp	LBB4_7
LBB4_6:
	movq	-192(%rbp), %rax
	movq	%rax, -280(%rbp)        ## 8-byte Spill
LBB4_7:
	movq	-280(%rbp), %rax        ## 8-byte Reload
	movq	-192(%rbp), %rcx
	addq	-200(%rbp), %rcx
	movq	-184(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	-24(%rsi), %rsi
	addq	%rsi, %rdx
	movq	-184(%rbp), %rsi
	movq	(%rsi), %rdi
	movq	-24(%rdi), %rdi
	addq	%rdi, %rsi
	movq	%rsi, -72(%rbp)
	movq	-72(%rbp), %rsi
	movq	%rax, -288(%rbp)        ## 8-byte Spill
	movq	%rcx, -296(%rbp)        ## 8-byte Spill
	movq	%rdx, -304(%rbp)        ## 8-byte Spill
	movq	%rsi, -312(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__111char_traitsIcE3eofEv
	movq	-312(%rbp), %rcx        ## 8-byte Reload
	movl	144(%rcx), %esi
	movl	%eax, %edi
	callq	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	testb	$1, %al
	jne	LBB4_8
	jmp	LBB4_13
LBB4_8:
	movq	-312(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -32(%rbp)
	movb	$32, -33(%rbp)
	movq	-32(%rbp), %rsi
Ltmp42:
	leaq	-48(%rbp), %rdi
	callq	__ZNKSt3__18ios_base6getlocEv
Ltmp43:
	jmp	LBB4_9
LBB4_9:                                 ## %.noexc
	leaq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
Ltmp44:
	movq	__ZNSt3__15ctypeIcE2idE@GOTPCREL(%rip), %rsi
	movq	%rax, %rdi
	callq	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp45:
	movq	%rax, -320(%rbp)        ## 8-byte Spill
	jmp	LBB4_10
LBB4_10:                                ## %_ZNSt3__19use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE.exit.i.i
	movb	-33(%rbp), %al
	movq	-320(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -8(%rbp)
	movb	%al, -9(%rbp)
	movq	-8(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	56(%rsi), %rsi
	movsbl	-9(%rbp), %edi
Ltmp46:
	movl	%edi, -324(%rbp)        ## 4-byte Spill
	movq	%rdx, %rdi
	movl	-324(%rbp), %r8d        ## 4-byte Reload
	movq	%rsi, -336(%rbp)        ## 8-byte Spill
	movl	%r8d, %esi
	movq	-336(%rbp), %rdx        ## 8-byte Reload
	callq	*%rdx
Ltmp47:
	movb	%al, -337(%rbp)         ## 1-byte Spill
	jmp	LBB4_12
LBB4_11:
Ltmp48:
	movl	%edx, %ecx
	movq	%rax, -56(%rbp)
	movl	%ecx, -60(%rbp)
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movq	-56(%rbp), %rax
	movl	-60(%rbp), %ecx
	movq	%rax, -352(%rbp)        ## 8-byte Spill
	movl	%ecx, -356(%rbp)        ## 4-byte Spill
	jmp	LBB4_21
LBB4_12:                                ## %_ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc.exit.i
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movb	-337(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %ecx
	movq	-312(%rbp), %rdi        ## 8-byte Reload
	movl	%ecx, 144(%rdi)
LBB4_13:                                ## %_ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillEv.exit
	movq	-312(%rbp), %rax        ## 8-byte Reload
	movl	144(%rax), %ecx
	movb	%cl, %dl
	movb	%dl, -357(%rbp)         ## 1-byte Spill
## BB#14:
	movq	-240(%rbp), %rdi
Ltmp49:
	movb	-357(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %r9d
	movq	-264(%rbp), %rsi        ## 8-byte Reload
	movq	-288(%rbp), %rdx        ## 8-byte Reload
	movq	-296(%rbp), %rcx        ## 8-byte Reload
	movq	-304(%rbp), %r8         ## 8-byte Reload
	callq	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
Ltmp50:
	movq	%rax, -368(%rbp)        ## 8-byte Spill
	jmp	LBB4_15
LBB4_15:
	leaq	-248(%rbp), %rax
	movq	-368(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -248(%rbp)
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	cmpq	$0, (%rax)
	jne	LBB4_25
## BB#16:
	movq	-184(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rax
	movq	%rax, -112(%rbp)
	movl	$5, -116(%rbp)
	movq	-112(%rbp), %rax
	movq	%rax, -96(%rbp)
	movl	$5, -100(%rbp)
	movq	-96(%rbp), %rax
	movl	32(%rax), %edx
	orl	$5, %edx
Ltmp51:
	movq	%rax, %rdi
	movl	%edx, %esi
	callq	__ZNSt3__18ios_base5clearEj
Ltmp52:
	jmp	LBB4_17
LBB4_17:                                ## %_ZNSt3__19basic_iosIcNS_11char_traitsIcEEE8setstateEj.exit
	jmp	LBB4_18
LBB4_18:
	jmp	LBB4_25
LBB4_19:
Ltmp41:
	movl	%edx, %ecx
	movq	%rax, -224(%rbp)
	movl	%ecx, -228(%rbp)
	jmp	LBB4_22
LBB4_20:
Ltmp53:
	movl	%edx, %ecx
	movq	%rax, -352(%rbp)        ## 8-byte Spill
	movl	%ecx, -356(%rbp)        ## 4-byte Spill
	jmp	LBB4_21
LBB4_21:                                ## %.body
	movl	-356(%rbp), %eax        ## 4-byte Reload
	movq	-352(%rbp), %rcx        ## 8-byte Reload
	leaq	-216(%rbp), %rdi
	movq	%rcx, -224(%rbp)
	movl	%eax, -228(%rbp)
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
LBB4_22:
	movq	-224(%rbp), %rdi
	callq	___cxa_begin_catch
	movq	-184(%rbp), %rdi
	movq	(%rdi), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rdi
Ltmp54:
	movq	%rax, -376(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__18ios_base33__set_badbit_and_consider_rethrowEv
Ltmp55:
	jmp	LBB4_23
LBB4_23:
	callq	___cxa_end_catch
LBB4_24:
	movq	-184(%rbp), %rax
	addq	$384, %rsp              ## imm = 0x180
	popq	%rbp
	retq
LBB4_25:
	jmp	LBB4_26
LBB4_26:
	leaq	-216(%rbp), %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
	jmp	LBB4_24
LBB4_27:
Ltmp56:
	movl	%edx, %ecx
	movq	%rax, -224(%rbp)
	movl	%ecx, -228(%rbp)
Ltmp57:
	callq	___cxa_end_catch
Ltmp58:
	jmp	LBB4_28
LBB4_28:
	jmp	LBB4_29
LBB4_29:
	movq	-224(%rbp), %rdi
	callq	__Unwind_Resume
LBB4_30:
Ltmp59:
	movl	%edx, %ecx
	movq	%rax, %rdi
	movl	%ecx, -380(%rbp)        ## 4-byte Spill
	callq	___clang_call_terminate
Lfunc_end3:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table4:
Lexception3:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\201\201\200\200"      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	117                     ## Call site table length
Lset27 = Ltmp39-Lfunc_begin3            ## >> Call Site 1 <<
	.long	Lset27
Lset28 = Ltmp40-Ltmp39                  ##   Call between Ltmp39 and Ltmp40
	.long	Lset28
Lset29 = Ltmp41-Lfunc_begin3            ##     jumps to Ltmp41
	.long	Lset29
	.byte	5                       ##   On action: 3
Lset30 = Ltmp42-Lfunc_begin3            ## >> Call Site 2 <<
	.long	Lset30
Lset31 = Ltmp43-Ltmp42                  ##   Call between Ltmp42 and Ltmp43
	.long	Lset31
Lset32 = Ltmp53-Lfunc_begin3            ##     jumps to Ltmp53
	.long	Lset32
	.byte	5                       ##   On action: 3
Lset33 = Ltmp44-Lfunc_begin3            ## >> Call Site 3 <<
	.long	Lset33
Lset34 = Ltmp47-Ltmp44                  ##   Call between Ltmp44 and Ltmp47
	.long	Lset34
Lset35 = Ltmp48-Lfunc_begin3            ##     jumps to Ltmp48
	.long	Lset35
	.byte	3                       ##   On action: 2
Lset36 = Ltmp49-Lfunc_begin3            ## >> Call Site 4 <<
	.long	Lset36
Lset37 = Ltmp52-Ltmp49                  ##   Call between Ltmp49 and Ltmp52
	.long	Lset37
Lset38 = Ltmp53-Lfunc_begin3            ##     jumps to Ltmp53
	.long	Lset38
	.byte	5                       ##   On action: 3
Lset39 = Ltmp52-Lfunc_begin3            ## >> Call Site 5 <<
	.long	Lset39
Lset40 = Ltmp54-Ltmp52                  ##   Call between Ltmp52 and Ltmp54
	.long	Lset40
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset41 = Ltmp54-Lfunc_begin3            ## >> Call Site 6 <<
	.long	Lset41
Lset42 = Ltmp55-Ltmp54                  ##   Call between Ltmp54 and Ltmp55
	.long	Lset42
Lset43 = Ltmp56-Lfunc_begin3            ##     jumps to Ltmp56
	.long	Lset43
	.byte	0                       ##   On action: cleanup
Lset44 = Ltmp55-Lfunc_begin3            ## >> Call Site 7 <<
	.long	Lset44
Lset45 = Ltmp57-Ltmp55                  ##   Call between Ltmp55 and Ltmp57
	.long	Lset45
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset46 = Ltmp57-Lfunc_begin3            ## >> Call Site 8 <<
	.long	Lset46
Lset47 = Ltmp58-Ltmp57                  ##   Call between Ltmp57 and Ltmp58
	.long	Lset47
Lset48 = Ltmp59-Lfunc_begin3            ##     jumps to Ltmp59
	.long	Lset48
	.byte	5                       ##   On action: 3
Lset49 = Ltmp58-Lfunc_begin3            ## >> Call Site 9 <<
	.long	Lset49
Lset50 = Lfunc_end3-Ltmp58              ##   Call between Ltmp58 and Lfunc_end3
	.long	Lset50
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	0                       ## >> Action Record 1 <<
                                        ##   Cleanup
	.byte	0                       ##   No further actions
	.byte	1                       ## >> Action Record 2 <<
                                        ##   Catch TypeInfo 1
	.byte	125                     ##   Continue to action 1
	.byte	1                       ## >> Action Record 3 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.private_extern	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.globl	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.weak_definition	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.p2align	4, 0x90
__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_: ## @_ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
Lfunc_begin4:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception4
## BB#0:
	pushq	%rbp
Ltmp66:
	.cfi_def_cfa_offset 16
Ltmp67:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp68:
	.cfi_def_cfa_register %rbp
	subq	$480, %rsp              ## imm = 0x1E0
	movb	%r9b, %al
	movq	%rdi, -312(%rbp)
	movq	%rsi, -320(%rbp)
	movq	%rdx, -328(%rbp)
	movq	%rcx, -336(%rbp)
	movq	%r8, -344(%rbp)
	movb	%al, -345(%rbp)
	cmpq	$0, -312(%rbp)
	jne	LBB5_2
## BB#1:
	movq	-312(%rbp), %rax
	movq	%rax, -304(%rbp)
	jmp	LBB5_26
LBB5_2:
	movq	-336(%rbp), %rax
	movq	-320(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, -360(%rbp)
	movq	-344(%rbp), %rax
	movq	%rax, -296(%rbp)
	movq	-296(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -368(%rbp)
	movq	-368(%rbp), %rax
	cmpq	-360(%rbp), %rax
	jle	LBB5_4
## BB#3:
	movq	-360(%rbp), %rax
	movq	-368(%rbp), %rcx
	subq	%rax, %rcx
	movq	%rcx, -368(%rbp)
	jmp	LBB5_5
LBB5_4:
	movq	$0, -368(%rbp)
LBB5_5:
	movq	-328(%rbp), %rax
	movq	-320(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, -376(%rbp)
	cmpq	$0, -376(%rbp)
	jle	LBB5_9
## BB#6:
	movq	-312(%rbp), %rax
	movq	-320(%rbp), %rcx
	movq	-376(%rbp), %rdx
	movq	%rax, -224(%rbp)
	movq	%rcx, -232(%rbp)
	movq	%rdx, -240(%rbp)
	movq	-224(%rbp), %rax
	movq	(%rax), %rcx
	movq	96(%rcx), %rcx
	movq	-232(%rbp), %rsi
	movq	-240(%rbp), %rdx
	movq	%rax, %rdi
	callq	*%rcx
	cmpq	-376(%rbp), %rax
	je	LBB5_8
## BB#7:
	movq	$0, -312(%rbp)
	movq	-312(%rbp), %rax
	movq	%rax, -304(%rbp)
	jmp	LBB5_26
LBB5_8:
	jmp	LBB5_9
LBB5_9:
	cmpq	$0, -368(%rbp)
	jle	LBB5_21
## BB#10:
	xorl	%esi, %esi
	movl	$24, %eax
	movl	%eax, %edx
	leaq	-400(%rbp), %rcx
	movq	-368(%rbp), %rdi
	movb	-345(%rbp), %r8b
	movq	%rcx, -200(%rbp)
	movq	%rdi, -208(%rbp)
	movb	%r8b, -209(%rbp)
	movq	-200(%rbp), %rcx
	movq	-208(%rbp), %rdi
	movb	-209(%rbp), %r8b
	movq	%rcx, -176(%rbp)
	movq	%rdi, -184(%rbp)
	movb	%r8b, -185(%rbp)
	movq	-176(%rbp), %rcx
	movq	%rcx, -168(%rbp)
	movq	-168(%rbp), %rdi
	movq	%rdi, -160(%rbp)
	movq	-160(%rbp), %rdi
	movq	%rdi, -152(%rbp)
	movq	-152(%rbp), %rdi
	movq	%rdi, %r9
	movq	%r9, -144(%rbp)
	movq	%rcx, -424(%rbp)        ## 8-byte Spill
	callq	_memset
	movq	-184(%rbp), %rsi
	movq	-424(%rbp), %rdi        ## 8-byte Reload
	movsbl	-185(%rbp), %edx
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEmc
	leaq	-400(%rbp), %rcx
	movq	-312(%rbp), %rsi
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rdi
	movq	%rdi, -112(%rbp)
	movq	-112(%rbp), %rdi
	movq	%rdi, -104(%rbp)
	movq	-104(%rbp), %rdi
	movzbl	(%rdi), %eax
	andl	$1, %eax
	cmpl	$0, %eax
	movq	%rsi, -432(%rbp)        ## 8-byte Spill
	movq	%rcx, -440(%rbp)        ## 8-byte Spill
	je	LBB5_12
## BB#11:
	movq	-440(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -448(%rbp)        ## 8-byte Spill
	jmp	LBB5_13
LBB5_12:
	movq	-440(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	%rcx, -88(%rbp)
	movq	-88(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	-80(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -448(%rbp)        ## 8-byte Spill
LBB5_13:                                ## %_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4dataEv.exit
	movq	-448(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -32(%rbp)
	movq	-368(%rbp), %rcx
	movq	-432(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -8(%rbp)
	movq	%rax, -16(%rbp)
	movq	%rcx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rsi
	movq	96(%rsi), %rsi
	movq	-16(%rbp), %rdi
Ltmp63:
	movq	%rdi, -456(%rbp)        ## 8-byte Spill
	movq	%rax, %rdi
	movq	-456(%rbp), %rax        ## 8-byte Reload
	movq	%rsi, -464(%rbp)        ## 8-byte Spill
	movq	%rax, %rsi
	movq	%rcx, %rdx
	movq	-464(%rbp), %rcx        ## 8-byte Reload
	callq	*%rcx
Ltmp64:
	movq	%rax, -472(%rbp)        ## 8-byte Spill
	jmp	LBB5_14
LBB5_14:                                ## %_ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl.exit
	jmp	LBB5_15
LBB5_15:
	movq	-472(%rbp), %rax        ## 8-byte Reload
	cmpq	-368(%rbp), %rax
	je	LBB5_18
## BB#16:
	movq	$0, -312(%rbp)
	movq	-312(%rbp), %rax
	movq	%rax, -304(%rbp)
	movl	$1, -416(%rbp)
	jmp	LBB5_19
LBB5_17:
Ltmp65:
	leaq	-400(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -408(%rbp)
	movl	%ecx, -412(%rbp)
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
	jmp	LBB5_27
LBB5_18:
	movl	$0, -416(%rbp)
LBB5_19:
	leaq	-400(%rbp), %rdi
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
	movl	-416(%rbp), %eax
	testl	%eax, %eax
	movl	%eax, -476(%rbp)        ## 4-byte Spill
	je	LBB5_20
	jmp	LBB5_29
LBB5_29:
	movl	-476(%rbp), %eax        ## 4-byte Reload
	subl	$1, %eax
	movl	%eax, -480(%rbp)        ## 4-byte Spill
	je	LBB5_26
	jmp	LBB5_28
LBB5_20:
	jmp	LBB5_21
LBB5_21:
	movq	-336(%rbp), %rax
	movq	-328(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, -376(%rbp)
	cmpq	$0, -376(%rbp)
	jle	LBB5_25
## BB#22:
	movq	-312(%rbp), %rax
	movq	-328(%rbp), %rcx
	movq	-376(%rbp), %rdx
	movq	%rax, -248(%rbp)
	movq	%rcx, -256(%rbp)
	movq	%rdx, -264(%rbp)
	movq	-248(%rbp), %rax
	movq	(%rax), %rcx
	movq	96(%rcx), %rcx
	movq	-256(%rbp), %rsi
	movq	-264(%rbp), %rdx
	movq	%rax, %rdi
	callq	*%rcx
	cmpq	-376(%rbp), %rax
	je	LBB5_24
## BB#23:
	movq	$0, -312(%rbp)
	movq	-312(%rbp), %rax
	movq	%rax, -304(%rbp)
	jmp	LBB5_26
LBB5_24:
	jmp	LBB5_25
LBB5_25:
	movq	-344(%rbp), %rax
	movq	%rax, -272(%rbp)
	movq	$0, -280(%rbp)
	movq	-272(%rbp), %rax
	movq	24(%rax), %rcx
	movq	%rcx, -288(%rbp)
	movq	-280(%rbp), %rcx
	movq	%rcx, 24(%rax)
	movq	-312(%rbp), %rax
	movq	%rax, -304(%rbp)
LBB5_26:
	movq	-304(%rbp), %rax
	addq	$480, %rsp              ## imm = 0x1E0
	popq	%rbp
	retq
LBB5_27:
	movq	-408(%rbp), %rdi
	callq	__Unwind_Resume
LBB5_28:
Lfunc_end4:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table5:
Lexception4:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset51 = Lfunc_begin4-Lfunc_begin4      ## >> Call Site 1 <<
	.long	Lset51
Lset52 = Ltmp63-Lfunc_begin4            ##   Call between Lfunc_begin4 and Ltmp63
	.long	Lset52
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset53 = Ltmp63-Lfunc_begin4            ## >> Call Site 2 <<
	.long	Lset53
Lset54 = Ltmp64-Ltmp63                  ##   Call between Ltmp63 and Ltmp64
	.long	Lset54
Lset55 = Ltmp65-Lfunc_begin4            ##     jumps to Ltmp65
	.long	Lset55
	.byte	0                       ##   On action: cleanup
Lset56 = Ltmp64-Lfunc_begin4            ## >> Call Site 3 <<
	.long	Lset56
Lset57 = Lfunc_end4-Ltmp64              ##   Call between Ltmp64 and Lfunc_end4
	.long	Lset57
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.private_extern	___clang_call_terminate
	.globl	___clang_call_terminate
	.weak_definition	___clang_call_terminate
	.p2align	4, 0x90
___clang_call_terminate:                ## @__clang_call_terminate
## BB#0:
	pushq	%rax
	callq	___cxa_begin_catch
	movq	%rax, (%rsp)            ## 8-byte Spill
	callq	__ZSt9terminatev

	.globl	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	.weak_definition	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE11eq_int_typeEii: ## @_ZNSt3__111char_traitsIcE11eq_int_typeEii
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp69:
	.cfi_def_cfa_offset 16
Ltmp70:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp71:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %esi
	cmpl	-8(%rbp), %esi
	sete	%al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__111char_traitsIcE3eofEv
	.weak_definition	__ZNSt3__111char_traitsIcE3eofEv
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE3eofEv:       ## @_ZNSt3__111char_traitsIcE3eofEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp72:
	.cfi_def_cfa_offset 16
Ltmp73:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp74:
	.cfi_def_cfa_register %rbp
	movl	$4294967295, %eax       ## imm = 0xFFFFFFFF
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNKSt3__16bitsetILm8EE9to_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EES8_S8_
	.weak_definition	__ZNKSt3__16bitsetILm8EE9to_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EES8_S8_
	.p2align	4, 0x90
__ZNKSt3__16bitsetILm8EE9to_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EES8_S8_: ## @_ZNKSt3__16bitsetILm8EE9to_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EES8_S8_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp75:
	.cfi_def_cfa_offset 16
Ltmp76:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp77:
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	subq	$456, %rsp              ## imm = 0x1C8
Ltmp78:
	.cfi_offset %rbx, -24
	movb	%cl, %al
	movb	%dl, %r8b
	movq	%rdi, %r9
	xorl	%ecx, %ecx
	movl	$24, %edx
                                        ## kill: %RDX<def> %EDX<kill>
	movq	%rsi, -328(%rbp)
	movb	%r8b, -329(%rbp)
	movb	%al, -330(%rbp)
	movq	-328(%rbp), %rsi
	movb	$0, -331(%rbp)
	movb	-329(%rbp), %al
	movq	%rdi, -304(%rbp)
	movq	$8, -312(%rbp)
	movb	%al, -313(%rbp)
	movq	-304(%rbp), %r10
	movq	-312(%rbp), %r11
	movb	-313(%rbp), %al
	movq	%r10, -280(%rbp)
	movq	%r11, -288(%rbp)
	movb	%al, -289(%rbp)
	movq	-280(%rbp), %r10
	movq	%r10, -272(%rbp)
	movq	-272(%rbp), %r11
	movq	%r11, -264(%rbp)
	movq	-264(%rbp), %r11
	movq	%r11, -256(%rbp)
	movq	-256(%rbp), %r11
	movq	%r11, %rbx
	movq	%rbx, -248(%rbp)
	movq	%rdi, -384(%rbp)        ## 8-byte Spill
	movq	%r11, %rdi
	movq	%rsi, -392(%rbp)        ## 8-byte Spill
	movl	%ecx, %esi
	movq	%r9, -400(%rbp)         ## 8-byte Spill
	movq	%r10, -408(%rbp)        ## 8-byte Spill
	callq	_memset
	movq	-288(%rbp), %rsi
	movq	-408(%rbp), %rdi        ## 8-byte Reload
	movsbl	-289(%rbp), %edx
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEmc
	movq	$0, -344(%rbp)
LBB9_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpq	$8, -344(%rbp)
	jae	LBB9_11
## BB#2:                                ##   in Loop: Header=BB9_1 Depth=1
	movq	-344(%rbp), %rax
	movq	-392(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -232(%rbp)
	movq	%rax, -240(%rbp)
	movq	-232(%rbp), %rdx
	movq	%rdx, -200(%rbp)
	movq	%rax, -208(%rbp)
	movq	-200(%rbp), %rax
	movb	-208(%rbp), %cl
	movl	$1, %esi
	movl	%esi, %edx
	shlq	%cl, %rdx
	leaq	-192(%rbp), %rdi
	movq	%rdi, -160(%rbp)
	movq	%rax, -168(%rbp)
	movq	%rdx, -176(%rbp)
	movq	-160(%rbp), %rax
	movq	-168(%rbp), %rdi
	movq	%rax, -136(%rbp)
	movq	%rdi, -144(%rbp)
	movq	%rdx, -152(%rbp)
	movq	-136(%rbp), %rax
	movq	-144(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-152(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-192(%rbp), %rax
	movq	-184(%rbp), %rdx
	movq	%rax, -224(%rbp)
	movq	%rdx, -216(%rbp)
	movq	-224(%rbp), %rax
	movq	%rdx, -416(%rbp)        ## 8-byte Spill
	movq	%rax, -424(%rbp)        ## 8-byte Spill
## BB#3:                                ##   in Loop: Header=BB9_1 Depth=1
	leaq	-376(%rbp), %rax
	movq	-424(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -376(%rbp)
	movq	-416(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -368(%rbp)
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	(%rdx), %rdx
	andq	8(%rax), %rdx
	cmpq	$0, %rdx
	je	LBB9_9
## BB#4:                                ##   in Loop: Header=BB9_1 Depth=1
	movl	$7, %eax
	movl	%eax, %ecx
	movb	-330(%rbp), %dl
	subq	-344(%rbp), %rcx
	movq	-384(%rbp), %rsi        ## 8-byte Reload
	movq	%rsi, -120(%rbp)
	movq	%rcx, -128(%rbp)
	movq	-120(%rbp), %rcx
	movq	%rcx, -112(%rbp)
	movq	-112(%rbp), %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rdi
	movq	%rdi, -96(%rbp)
	movq	-96(%rbp), %rdi
	movq	%rdi, -88(%rbp)
	movq	-88(%rbp), %rdi
	movzbl	(%rdi), %eax
	andl	$1, %eax
	cmpl	$0, %eax
	movb	%dl, -425(%rbp)         ## 1-byte Spill
	movq	%rcx, -440(%rbp)        ## 8-byte Spill
	je	LBB9_6
## BB#5:                                ##   in Loop: Header=BB9_1 Depth=1
	movq	-440(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -448(%rbp)        ## 8-byte Spill
	jmp	LBB9_7
LBB9_6:                                 ##   in Loop: Header=BB9_1 Depth=1
	movq	-440(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rcx
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	%rcx, -448(%rbp)        ## 8-byte Spill
LBB9_7:                                 ## %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEixEm.exit
                                        ##   in Loop: Header=BB9_1 Depth=1
	movq	-448(%rbp), %rax        ## 8-byte Reload
	addq	-128(%rbp), %rax
	movq	%rax, -456(%rbp)        ## 8-byte Spill
## BB#8:                                ##   in Loop: Header=BB9_1 Depth=1
	movq	-456(%rbp), %rax        ## 8-byte Reload
	movb	-425(%rbp), %cl         ## 1-byte Reload
	movb	%cl, (%rax)
LBB9_9:                                 ##   in Loop: Header=BB9_1 Depth=1
	jmp	LBB9_10
LBB9_10:                                ##   in Loop: Header=BB9_1 Depth=1
	movq	-344(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -344(%rbp)
	jmp	LBB9_1
LBB9_11:
	movb	$1, -331(%rbp)
	testb	$1, -331(%rbp)
	jne	LBB9_13
## BB#12:
	movq	-384(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
LBB9_13:
	movq	-400(%rbp), %rax        ## 8-byte Reload
	addq	$456, %rsp              ## imm = 0x1C8
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__117__count_bool_trueINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeE
	.weak_definition	__ZNSt3__117__count_bool_trueINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeE
	.p2align	4, 0x90
__ZNSt3__117__count_bool_trueINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeE: ## @_ZNSt3__117__count_bool_trueINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeE
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp79:
	.cfi_def_cfa_offset 16
Ltmp80:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp81:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -112(%rbp)
	movl	%esi, -104(%rbp)
	movq	%rdx, -120(%rbp)
	movq	$0, -128(%rbp)
	cmpl	$0, -104(%rbp)
	je	LBB10_5
## BB#1:
	leaq	-56(%rbp), %rax
	leaq	-120(%rbp), %rcx
	leaq	-136(%rbp), %rdx
	movl	$64, %esi
	subl	-104(%rbp), %esi
	movl	%esi, %esi
	movl	%esi, %edi
	movq	%rdi, -136(%rbp)
	movq	%rdx, -80(%rbp)
	movq	%rcx, -88(%rbp)
	movq	-80(%rbp), %rcx
	movq	-88(%rbp), %rdx
	movq	%rcx, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	-64(%rbp), %rdx
	movq	%rax, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movq	%rdx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	-48(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB10_3
## BB#2:
	movq	-72(%rbp), %rax
	movq	%rax, -168(%rbp)        ## 8-byte Spill
	jmp	LBB10_4
LBB10_3:
	movq	-64(%rbp), %rax
	movq	%rax, -168(%rbp)        ## 8-byte Spill
LBB10_4:                                ## %_ZNSt3__13minImEERKT_S3_S3_.exit
	movq	-168(%rbp), %rax        ## 8-byte Reload
	movq	$-1, %rcx
	movq	(%rax), %rax
	movq	%rax, -144(%rbp)
	movl	-104(%rbp), %edx
	movl	%edx, %eax
	movq	%rcx, -176(%rbp)        ## 8-byte Spill
	movq	%rax, %rcx
                                        ## kill: %CL<def> %RCX<kill>
	movq	-176(%rbp), %rax        ## 8-byte Reload
	shlq	%cl, %rax
	movq	-136(%rbp), %rsi
	subq	-144(%rbp), %rsi
	movq	%rsi, %rcx
                                        ## kill: %CL<def> %RCX<kill>
	movq	-176(%rbp), %rsi        ## 8-byte Reload
	shrq	%cl, %rsi
	andq	%rsi, %rax
	movq	%rax, -152(%rbp)
	movq	-112(%rbp), %rax
	movq	(%rax), %rax
	andq	-152(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	shrq	%rsi
	movabsq	$6148914691236517205, %rdi ## imm = 0x5555555555555555
	andq	%rdi, %rsi
	subq	%rsi, %rax
	movabsq	$3689348814741910323, %rsi ## imm = 0x3333333333333333
	movq	%rax, %rdi
	andq	%rsi, %rdi
	shrq	$2, %rax
	andq	%rsi, %rax
	addq	%rax, %rdi
	movq	%rdi, %rax
	shrq	$4, %rax
	addq	%rax, %rdi
	movabsq	$1085102592571150095, %rax ## imm = 0xF0F0F0F0F0F0F0F
	andq	%rax, %rdi
	movabsq	$72340172838076673, %rax ## imm = 0x101010101010101
	imulq	%rax, %rdi
	shrq	$56, %rdi
	movl	%edi, %edx
	movslq	%edx, %rax
	movq	%rax, -128(%rbp)
	movq	-144(%rbp), %rax
	movq	-120(%rbp), %rsi
	subq	%rax, %rsi
	movq	%rsi, -120(%rbp)
	movq	-112(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -112(%rbp)
LBB10_5:
	jmp	LBB10_6
LBB10_6:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$64, -120(%rbp)
	jb	LBB10_9
## BB#7:                                ##   in Loop: Header=BB10_6 Depth=1
	movq	-112(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	shrq	%rcx
	movabsq	$6148914691236517205, %rdx ## imm = 0x5555555555555555
	andq	%rdx, %rcx
	subq	%rcx, %rax
	movabsq	$3689348814741910323, %rcx ## imm = 0x3333333333333333
	movq	%rax, %rdx
	andq	%rcx, %rdx
	shrq	$2, %rax
	andq	%rcx, %rax
	addq	%rax, %rdx
	movq	%rdx, %rax
	shrq	$4, %rax
	addq	%rax, %rdx
	movabsq	$1085102592571150095, %rax ## imm = 0xF0F0F0F0F0F0F0F
	andq	%rax, %rdx
	movabsq	$72340172838076673, %rax ## imm = 0x101010101010101
	imulq	%rax, %rdx
	shrq	$56, %rdx
	movl	%edx, %esi
	movslq	%esi, %rax
	addq	-128(%rbp), %rax
	movq	%rax, -128(%rbp)
## BB#8:                                ##   in Loop: Header=BB10_6 Depth=1
	movq	-112(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -112(%rbp)
	movq	-120(%rbp), %rax
	subq	$64, %rax
	movq	%rax, -120(%rbp)
	jmp	LBB10_6
LBB10_9:
	cmpq	$0, -120(%rbp)
	jbe	LBB10_11
## BB#10:
	movq	$-1, %rax
	movl	$64, %ecx
	movl	%ecx, %edx
	subq	-120(%rbp), %rdx
	movq	%rdx, %rcx
                                        ## kill: %CL<def> %RCX<kill>
	shrq	%cl, %rax
	movq	%rax, -160(%rbp)
	movq	-112(%rbp), %rax
	movq	(%rax), %rax
	andq	-160(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdx
	shrq	%rdx
	movabsq	$6148914691236517205, %rsi ## imm = 0x5555555555555555
	andq	%rsi, %rdx
	subq	%rdx, %rax
	movabsq	$3689348814741910323, %rdx ## imm = 0x3333333333333333
	movq	%rax, %rsi
	andq	%rdx, %rsi
	shrq	$2, %rax
	andq	%rdx, %rax
	addq	%rax, %rsi
	movq	%rsi, %rax
	shrq	$4, %rax
	addq	%rax, %rsi
	movabsq	$1085102592571150095, %rax ## imm = 0xF0F0F0F0F0F0F0F
	andq	%rax, %rsi
	movabsq	$72340172838076673, %rax ## imm = 0x101010101010101
	imulq	%rax, %rsi
	shrq	$56, %rsi
	movl	%esi, %edi
	movslq	%edi, %rax
	addq	-128(%rbp), %rax
	movq	%rax, -128(%rbp)
LBB10_11:
	movq	-128(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__118__count_bool_falseINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeE
	.weak_definition	__ZNSt3__118__count_bool_falseINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeE
	.p2align	4, 0x90
__ZNSt3__118__count_bool_falseINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeE: ## @_ZNSt3__118__count_bool_falseINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeE
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp82:
	.cfi_def_cfa_offset 16
Ltmp83:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp84:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -112(%rbp)
	movl	%esi, -104(%rbp)
	movq	%rdx, -120(%rbp)
	movq	$0, -128(%rbp)
	cmpl	$0, -104(%rbp)
	je	LBB11_5
## BB#1:
	leaq	-56(%rbp), %rax
	leaq	-120(%rbp), %rcx
	leaq	-136(%rbp), %rdx
	movl	$64, %esi
	subl	-104(%rbp), %esi
	movl	%esi, %esi
	movl	%esi, %edi
	movq	%rdi, -136(%rbp)
	movq	%rdx, -80(%rbp)
	movq	%rcx, -88(%rbp)
	movq	-80(%rbp), %rcx
	movq	-88(%rbp), %rdx
	movq	%rcx, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	-64(%rbp), %rdx
	movq	%rax, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movq	%rdx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	-48(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB11_3
## BB#2:
	movq	-72(%rbp), %rax
	movq	%rax, -168(%rbp)        ## 8-byte Spill
	jmp	LBB11_4
LBB11_3:
	movq	-64(%rbp), %rax
	movq	%rax, -168(%rbp)        ## 8-byte Spill
LBB11_4:                                ## %_ZNSt3__13minImEERKT_S3_S3_.exit
	movq	-168(%rbp), %rax        ## 8-byte Reload
	movq	$-1, %rcx
	movq	(%rax), %rax
	movq	%rax, -144(%rbp)
	movl	-104(%rbp), %edx
	movl	%edx, %eax
	movq	%rcx, -176(%rbp)        ## 8-byte Spill
	movq	%rax, %rcx
                                        ## kill: %CL<def> %RCX<kill>
	movq	-176(%rbp), %rax        ## 8-byte Reload
	shlq	%cl, %rax
	movq	-136(%rbp), %rsi
	subq	-144(%rbp), %rsi
	movq	%rsi, %rcx
                                        ## kill: %CL<def> %RCX<kill>
	movq	-176(%rbp), %rsi        ## 8-byte Reload
	shrq	%cl, %rsi
	andq	%rsi, %rax
	movq	%rax, -152(%rbp)
	movq	-112(%rbp), %rax
	movq	(%rax), %rax
	xorq	$-1, %rax
	andq	-152(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	shrq	%rsi
	movabsq	$6148914691236517205, %rdi ## imm = 0x5555555555555555
	andq	%rdi, %rsi
	subq	%rsi, %rax
	movabsq	$3689348814741910323, %rsi ## imm = 0x3333333333333333
	movq	%rax, %rdi
	andq	%rsi, %rdi
	shrq	$2, %rax
	andq	%rsi, %rax
	addq	%rax, %rdi
	movq	%rdi, %rax
	shrq	$4, %rax
	addq	%rax, %rdi
	movabsq	$1085102592571150095, %rax ## imm = 0xF0F0F0F0F0F0F0F
	andq	%rax, %rdi
	movabsq	$72340172838076673, %rax ## imm = 0x101010101010101
	imulq	%rax, %rdi
	shrq	$56, %rdi
	movl	%edi, %edx
	movslq	%edx, %rax
	movq	%rax, -128(%rbp)
	movq	-144(%rbp), %rax
	movq	-120(%rbp), %rsi
	subq	%rax, %rsi
	movq	%rsi, -120(%rbp)
	movq	-112(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -112(%rbp)
LBB11_5:
	jmp	LBB11_6
LBB11_6:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$64, -120(%rbp)
	jb	LBB11_9
## BB#7:                                ##   in Loop: Header=BB11_6 Depth=1
	movq	-112(%rbp), %rax
	movq	(%rax), %rax
	xorq	$-1, %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	shrq	%rcx
	movabsq	$6148914691236517205, %rdx ## imm = 0x5555555555555555
	andq	%rdx, %rcx
	subq	%rcx, %rax
	movabsq	$3689348814741910323, %rcx ## imm = 0x3333333333333333
	movq	%rax, %rdx
	andq	%rcx, %rdx
	shrq	$2, %rax
	andq	%rcx, %rax
	addq	%rax, %rdx
	movq	%rdx, %rax
	shrq	$4, %rax
	addq	%rax, %rdx
	movabsq	$1085102592571150095, %rax ## imm = 0xF0F0F0F0F0F0F0F
	andq	%rax, %rdx
	movabsq	$72340172838076673, %rax ## imm = 0x101010101010101
	imulq	%rax, %rdx
	shrq	$56, %rdx
	movl	%edx, %esi
	movslq	%esi, %rax
	addq	-128(%rbp), %rax
	movq	%rax, -128(%rbp)
## BB#8:                                ##   in Loop: Header=BB11_6 Depth=1
	movq	-112(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -112(%rbp)
	movq	-120(%rbp), %rax
	subq	$64, %rax
	movq	%rax, -120(%rbp)
	jmp	LBB11_6
LBB11_9:
	cmpq	$0, -120(%rbp)
	jbe	LBB11_11
## BB#10:
	movq	$-1, %rax
	movl	$64, %ecx
	movl	%ecx, %edx
	subq	-120(%rbp), %rdx
	movq	%rdx, %rcx
                                        ## kill: %CL<def> %RCX<kill>
	shrq	%cl, %rax
	movq	%rax, -160(%rbp)
	movq	-112(%rbp), %rax
	movq	(%rax), %rax
	xorq	$-1, %rax
	andq	-160(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdx
	shrq	%rdx
	movabsq	$6148914691236517205, %rsi ## imm = 0x5555555555555555
	andq	%rsi, %rdx
	subq	%rdx, %rax
	movabsq	$3689348814741910323, %rdx ## imm = 0x3333333333333333
	movq	%rax, %rsi
	andq	%rdx, %rsi
	shrq	$2, %rax
	andq	%rdx, %rax
	addq	%rax, %rsi
	movq	%rsi, %rax
	shrq	$4, %rax
	addq	%rax, %rsi
	movabsq	$1085102592571150095, %rax ## imm = 0xF0F0F0F0F0F0F0F
	andq	%rax, %rsi
	movabsq	$72340172838076673, %rax ## imm = 0x101010101010101
	imulq	%rax, %rsi
	shrq	$56, %rsi
	movl	%esi, %edi
	movslq	%edi, %rax
	addq	-128(%rbp), %rax
	movq	%rax, -128(%rbp)
LBB11_11:
	movq	-128(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__const
	.globl	__ZZNSt3__117__count_bool_trueINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeEE15__bits_per_word ## @_ZZNSt3__117__count_bool_trueINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeEE15__bits_per_word
	.weak_definition	__ZZNSt3__117__count_bool_trueINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeEE15__bits_per_word
	.p2align	2
__ZZNSt3__117__count_bool_trueINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeEE15__bits_per_word:
	.long	64                      ## 0x40

	.globl	__ZZNSt3__118__count_bool_falseINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeEE15__bits_per_word ## @_ZZNSt3__118__count_bool_falseINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeEE15__bits_per_word
	.weak_definition	__ZZNSt3__118__count_bool_falseINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeEE15__bits_per_word
	.p2align	2
__ZZNSt3__118__count_bool_falseINS_8__bitsetILm1ELm6EEELb1EEENS_14__bit_iteratorIT_XT0_EXLi0EEE15difference_typeES5_NS4_9size_typeEE15__bits_per_word:
	.long	64                      ## 0x40


.subsections_via_symbols
