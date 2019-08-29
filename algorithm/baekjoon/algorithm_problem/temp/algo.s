	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$272, %rsp              ## imm = 0x110
	leaq	L_.str(%rip), %rdi
	leaq	-128(%rbp), %rsi
	movl	$0, -124(%rbp)
	movb	$0, %al
	callq	_scanf
	movl	$0, -132(%rbp)
	movl	%eax, -164(%rbp)        ## 4-byte Spill
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-132(%rbp), %eax
	cmpl	-128(%rbp), %eax
	jge	LBB0_6
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	leaq	L_.str.1(%rip), %rdi
	leaq	-136(%rbp), %rsi
	movb	$0, %al
	callq	_scanf
	cmpl	$0, -136(%rbp)
	movl	%eax, -168(%rbp)        ## 4-byte Spill
	je	LBB0_4
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	leaq	_init(%rip), %rax
	movl	$1, %edx
	movslq	-132(%rbp), %rsi
	movq	%rax, %rdi
	callq	__ZNSt3__16bitsetILm100000EE3setEmb
	movq	%rax, -176(%rbp)        ## 8-byte Spill
LBB0_4:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_5
LBB0_5:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	-132(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -132(%rbp)
	jmp	LBB0_1
LBB0_6:
	movl	$0, -132(%rbp)
LBB0_7:                                 ## =>This Inner Loop Header: Depth=1
	movl	-132(%rbp), %eax
	cmpl	-128(%rbp), %eax
	jge	LBB0_12
## BB#8:                                ##   in Loop: Header=BB0_7 Depth=1
	leaq	L_.str.1(%rip), %rdi
	leaq	-136(%rbp), %rsi
	movb	$0, %al
	callq	_scanf
	cmpl	$0, -136(%rbp)
	movl	%eax, -180(%rbp)        ## 4-byte Spill
	je	LBB0_10
## BB#9:                                ##   in Loop: Header=BB0_7 Depth=1
	leaq	_ret(%rip), %rax
	movl	$1, %edx
	movslq	-132(%rbp), %rsi
	movq	%rax, %rdi
	callq	__ZNSt3__16bitsetILm100000EE3setEmb
	movq	%rax, -192(%rbp)        ## 8-byte Spill
LBB0_10:                                ##   in Loop: Header=BB0_7 Depth=1
	jmp	LBB0_11
LBB0_11:                                ##   in Loop: Header=BB0_7 Depth=1
	movl	-132(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -132(%rbp)
	jmp	LBB0_7
LBB0_12:
	movl	$0, -140(%rbp)
	movl	$1, -132(%rbp)
LBB0_13:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_15 Depth 2
	movl	-132(%rbp), %eax
	movl	-128(%rbp), %ecx
	subl	$1, %ecx
	cmpl	%ecx, %eax
	jge	LBB0_20
## BB#14:                               ##   in Loop: Header=BB0_13 Depth=1
	leaq	_init(%rip), %rax
	movl	-140(%rbp), %ecx
	addl	$1, %ecx
	movl	%ecx, -140(%rbp)
	movl	-132(%rbp), %ecx
	subl	$1, %ecx
	movslq	%ecx, %rsi
	movq	%rax, %rdi
	callq	__ZNSt3__16bitsetILm100000EE4flipEm
	leaq	_init(%rip), %rsi
	movslq	-132(%rbp), %rdi
	movq	%rdi, -200(%rbp)        ## 8-byte Spill
	movq	%rsi, %rdi
	movq	-200(%rbp), %rsi        ## 8-byte Reload
	movq	%rax, -208(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__16bitsetILm100000EE4flipEm
	leaq	_init(%rip), %rsi
	movl	-132(%rbp), %ecx
	addl	$1, %ecx
	movslq	%ecx, %rdi
	movq	%rdi, -216(%rbp)        ## 8-byte Spill
	movq	%rsi, %rdi
	movq	-216(%rbp), %rsi        ## 8-byte Reload
	movq	%rax, -224(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__16bitsetILm100000EE4flipEm
	movl	$0, -144(%rbp)
	movq	%rax, -232(%rbp)        ## 8-byte Spill
LBB0_15:                                ##   Parent Loop BB0_13 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-144(%rbp), %eax
	cmpl	-128(%rbp), %eax
	jge	LBB0_18
## BB#16:                               ##   in Loop: Header=BB0_15 Depth=2
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rax
	leaq	-160(%rbp), %rcx
	movslq	-144(%rbp), %rdx
	leaq	_init(%rip), %rsi
	movq	%rsi, -112(%rbp)
	movq	%rdx, -120(%rbp)
	movq	-112(%rbp), %rsi
	movq	%rsi, -80(%rbp)
	movq	%rdx, -88(%rbp)
	movq	-80(%rbp), %rsi
	movq	%rdx, %rdi
	shrq	$6, %rdi
	leaq	(%rsi,%rdi,8), %rsi
	movb	%dl, %r8b
	movl	$1, %r9d
	movl	%r9d, %edx
	movq	%rcx, -240(%rbp)        ## 8-byte Spill
	movb	%r8b, %cl
	shlq	%cl, %rdx
	leaq	-72(%rbp), %rdi
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-40(%rbp), %rsi
	movq	-48(%rbp), %rdi
	movq	%rsi, -16(%rbp)
	movq	%rdi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	movq	-16(%rbp), %rdx
	movq	-24(%rbp), %rsi
	movq	%rsi, (%rdx)
	movq	-32(%rbp), %rsi
	movq	%rsi, 8(%rdx)
	movq	-72(%rbp), %rdx
	movq	-64(%rbp), %rsi
	movq	%rdx, -104(%rbp)
	movq	%rsi, -96(%rbp)
	movq	-104(%rbp), %rdx
	movq	%rdx, -160(%rbp)
	movq	%rsi, -152(%rbp)
	movq	-240(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rsi
	movq	(%rsi), %rdi
	movq	(%rdi), %rdi
	andq	8(%rsi), %rdi
	cmpq	$0, %rdi
	setne	%cl
	andb	$1, %cl
	movzbl	%cl, %esi
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	movq	%rax, -248(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEb
	movq	%rax, -256(%rbp)        ## 8-byte Spill
## BB#17:                               ##   in Loop: Header=BB0_15 Depth=2
	movl	-144(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -144(%rbp)
	jmp	LBB0_15
LBB0_18:                                ##   in Loop: Header=BB0_13 Depth=1
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -260(%rbp)        ## 4-byte Spill
## BB#19:                               ##   in Loop: Header=BB0_13 Depth=1
	movl	-132(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -132(%rbp)
	jmp	LBB0_13
LBB0_20:
	leaq	L_.str.3(%rip), %rdi
	movl	-140(%rbp), %esi
	movb	$0, %al
	callq	_printf
	xorl	%esi, %esi
	movl	%eax, -264(%rbp)        ## 4-byte Spill
	movl	%esi, %eax
	addq	$272, %rsp              ## imm = 0x110
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16bitsetILm100000EE3setEmb
	.weak_definition	__ZNSt3__16bitsetILm100000EE3setEmb
	.p2align	4, 0x90
__ZNSt3__16bitsetILm100000EE3setEmb:    ## @_ZNSt3__16bitsetILm100000EE3setEmb
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$256, %rsp              ## imm = 0x100
	movb	%dl, %al
	movq	%rdi, -168(%rbp)
	movq	%rsi, -176(%rbp)
	andb	$1, %al
	movb	%al, -177(%rbp)
	movq	-168(%rbp), %rsi
	cmpq	$100000, -176(%rbp)     ## imm = 0x186A0
	movq	%rsi, -224(%rbp)        ## 8-byte Spill
	jb	LBB1_5
## BB#1:
	movl	$16, %eax
	movl	%eax, %edi
	callq	___cxa_allocate_exception
	movq	%rax, %rdi
	movq	%rax, -152(%rbp)
	leaq	L_.str.4(%rip), %rax
	movq	%rax, -160(%rbp)
	movq	-152(%rbp), %rcx
	movq	%rcx, -136(%rbp)
	movq	%rax, -144(%rbp)
	movq	-136(%rbp), %rcx
Ltmp3:
	movq	%rdi, -232(%rbp)        ## 8-byte Spill
	movq	%rcx, %rdi
	movq	%rax, %rsi
	movq	%rcx, -240(%rbp)        ## 8-byte Spill
	callq	__ZNSt11logic_errorC2EPKc
Ltmp4:
	jmp	LBB1_2
LBB1_2:                                 ## %_ZNSt12out_of_rangeC1EPKc.exit
	movq	__ZTVSt12out_of_range@GOTPCREL(%rip), %rax
	addq	$16, %rax
	movq	-240(%rbp), %rcx        ## 8-byte Reload
	movq	%rax, (%rcx)
## BB#3:
	movq	__ZTISt12out_of_range@GOTPCREL(%rip), %rax
	movq	__ZNSt12out_of_rangeD1Ev@GOTPCREL(%rip), %rcx
	movq	-232(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	movq	%rcx, %rdx
	callq	___cxa_throw
LBB1_4:
Ltmp5:
	movl	%edx, %ecx
	movq	%rax, -192(%rbp)
	movl	%ecx, -196(%rbp)
	movq	-232(%rbp), %rdi        ## 8-byte Reload
	callq	___cxa_free_exception
	jmp	LBB1_9
LBB1_5:
	leaq	-216(%rbp), %rax
	movq	-176(%rbp), %rcx
	movq	-224(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -120(%rbp)
	movq	%rcx, -128(%rbp)
	movq	-120(%rbp), %rsi
	movq	%rsi, -88(%rbp)
	movq	%rcx, -96(%rbp)
	movq	-88(%rbp), %rsi
	movq	%rcx, %rdi
	shrq	$6, %rdi
	leaq	(%rsi,%rdi,8), %rsi
	movb	%cl, %r8b
	movl	$1, %r9d
	movl	%r9d, %ecx
	movq	%rcx, -248(%rbp)        ## 8-byte Spill
	movb	%r8b, %cl
	movq	-248(%rbp), %rdi        ## 8-byte Reload
	shlq	%cl, %rdi
	leaq	-80(%rbp), %r10
	movq	%r10, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdi, -64(%rbp)
	movq	-48(%rbp), %rsi
	movq	-56(%rbp), %r10
	movq	%rsi, -24(%rbp)
	movq	%r10, -32(%rbp)
	movq	%rdi, -40(%rbp)
	movq	-24(%rbp), %rsi
	movq	-32(%rbp), %rdi
	movq	%rdi, (%rsi)
	movq	-40(%rbp), %rdi
	movq	%rdi, 8(%rsi)
	movq	-80(%rbp), %rsi
	movq	-72(%rbp), %rdi
	movq	%rsi, -112(%rbp)
	movq	%rdi, -104(%rbp)
	movq	-112(%rbp), %rsi
	movq	%rsi, -216(%rbp)
	movq	%rdi, -208(%rbp)
	movb	-177(%rbp), %cl
	movq	%rax, -8(%rbp)
	andb	$1, %cl
	movb	%cl, -9(%rbp)
	movq	-8(%rbp), %rax
	testb	$1, -9(%rbp)
	movq	%rax, -256(%rbp)        ## 8-byte Spill
	je	LBB1_7
## BB#6:
	movq	-256(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	(%rax), %rdx
	orq	(%rdx), %rcx
	movq	%rcx, (%rdx)
	jmp	LBB1_8
LBB1_7:
	movq	-256(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	xorq	$-1, %rcx
	movq	(%rax), %rdx
	andq	(%rdx), %rcx
	movq	%rcx, (%rdx)
LBB1_8:                                 ## %_ZNSt3__115__bit_referenceINS_8__bitsetILm1563ELm100000EEELb1EEaSEb.exit
	movq	-224(%rbp), %rax        ## 8-byte Reload
	addq	$256, %rsp              ## imm = 0x100
	popq	%rbp
	retq
LBB1_9:
	movq	-192(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table1:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset0 = Lfunc_begin0-Lfunc_begin0       ## >> Call Site 1 <<
	.long	Lset0
Lset1 = Ltmp3-Lfunc_begin0              ##   Call between Lfunc_begin0 and Ltmp3
	.long	Lset1
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset2 = Ltmp3-Lfunc_begin0              ## >> Call Site 2 <<
	.long	Lset2
Lset3 = Ltmp4-Ltmp3                     ##   Call between Ltmp3 and Ltmp4
	.long	Lset3
Lset4 = Ltmp5-Lfunc_begin0              ##     jumps to Ltmp5
	.long	Lset4
	.byte	0                       ##   On action: cleanup
Lset5 = Ltmp4-Lfunc_begin0              ## >> Call Site 3 <<
	.long	Lset5
Lset6 = Lfunc_end0-Ltmp4                ##   Call between Ltmp4 and Lfunc_end0
	.long	Lset6
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__16bitsetILm100000EE4flipEm
	.weak_definition	__ZNSt3__16bitsetILm100000EE4flipEm
	.p2align	4, 0x90
__ZNSt3__16bitsetILm100000EE4flipEm:    ## @_ZNSt3__16bitsetILm100000EE4flipEm
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
## BB#0:
	pushq	%rbp
Ltmp12:
	.cfi_def_cfa_offset 16
Ltmp13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp14:
	.cfi_def_cfa_register %rbp
	subq	$240, %rsp
	movq	%rdi, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	-152(%rbp), %rsi
	cmpq	$100000, -160(%rbp)     ## imm = 0x186A0
	movq	%rsi, -200(%rbp)        ## 8-byte Spill
	jb	LBB2_5
## BB#1:
	movl	$16, %eax
	movl	%eax, %edi
	callq	___cxa_allocate_exception
	movq	%rax, %rdi
	movq	%rax, -136(%rbp)
	leaq	L_.str.5(%rip), %rax
	movq	%rax, -144(%rbp)
	movq	-136(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	%rax, -128(%rbp)
	movq	-120(%rbp), %rcx
Ltmp9:
	movq	%rdi, -208(%rbp)        ## 8-byte Spill
	movq	%rcx, %rdi
	movq	%rax, %rsi
	movq	%rcx, -216(%rbp)        ## 8-byte Spill
	callq	__ZNSt11logic_errorC2EPKc
Ltmp10:
	jmp	LBB2_2
LBB2_2:                                 ## %_ZNSt12out_of_rangeC1EPKc.exit
	movq	__ZTVSt12out_of_range@GOTPCREL(%rip), %rax
	addq	$16, %rax
	movq	-216(%rbp), %rcx        ## 8-byte Reload
	movq	%rax, (%rcx)
## BB#3:
	movq	__ZTISt12out_of_range@GOTPCREL(%rip), %rax
	movq	__ZNSt12out_of_rangeD1Ev@GOTPCREL(%rip), %rcx
	movq	-208(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	movq	%rcx, %rdx
	callq	___cxa_throw
LBB2_4:
Ltmp11:
	movl	%edx, %ecx
	movq	%rax, -168(%rbp)
	movl	%ecx, -172(%rbp)
	movq	-208(%rbp), %rdi        ## 8-byte Reload
	callq	___cxa_free_exception
	jmp	LBB2_9
LBB2_5:
	leaq	-192(%rbp), %rax
	movq	-160(%rbp), %rcx
	movq	-200(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -104(%rbp)
	movq	%rcx, -112(%rbp)
	movq	-104(%rbp), %rsi
	movq	%rcx, %rdi
	shrq	$6, %rdi
	leaq	(%rsi,%rdi,8), %rsi
	movb	%cl, %r8b
	movl	$1, %r9d
	movl	%r9d, %ecx
	movq	%rcx, -224(%rbp)        ## 8-byte Spill
	movb	%r8b, %cl
	movq	-224(%rbp), %rdi        ## 8-byte Reload
	shlq	%cl, %rdi
	leaq	-96(%rbp), %r10
	movq	%r10, -64(%rbp)
	movq	%rsi, -72(%rbp)
	movq	%rdi, -80(%rbp)
	movq	-64(%rbp), %rsi
	movq	-72(%rbp), %r10
	movq	%rsi, -40(%rbp)
	movq	%r10, -48(%rbp)
	movq	%rdi, -56(%rbp)
	movq	-40(%rbp), %rsi
	movq	-48(%rbp), %rdi
	movq	%rdi, (%rsi)
	movq	-56(%rbp), %rdi
	movq	%rdi, 8(%rsi)
	movq	-96(%rbp), %rsi
	movq	-88(%rbp), %rdi
	movq	%rsi, -192(%rbp)
	movq	%rdi, -184(%rbp)
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	movq	%rsi, -8(%rbp)
	movq	-8(%rbp), %rsi
	movq	(%rsi), %rdi
	movq	(%rdi), %rdi
	andq	8(%rsi), %rdi
	cmpq	$0, %rdi
	setne	%cl
	xorb	$-1, %cl
	movq	%rax, -24(%rbp)
	andb	$1, %cl
	movb	%cl, -25(%rbp)
	movq	-24(%rbp), %rax
	testb	$1, -25(%rbp)
	movq	%rax, -232(%rbp)        ## 8-byte Spill
	je	LBB2_7
## BB#6:
	movq	-232(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	(%rax), %rdx
	orq	(%rdx), %rcx
	movq	%rcx, (%rdx)
	jmp	LBB2_8
LBB2_7:
	movq	-232(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	xorq	$-1, %rcx
	movq	(%rax), %rdx
	andq	(%rdx), %rcx
	movq	%rcx, (%rdx)
LBB2_8:                                 ## %_ZNSt3__115__bit_referenceINS_8__bitsetILm1563ELm100000EEELb1EEaSEb.exit
	movq	-200(%rbp), %rax        ## 8-byte Reload
	addq	$240, %rsp
	popq	%rbp
	retq
LBB2_9:
	movq	-168(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table2:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset7 = Lfunc_begin1-Lfunc_begin1       ## >> Call Site 1 <<
	.long	Lset7
Lset8 = Ltmp9-Lfunc_begin1              ##   Call between Lfunc_begin1 and Ltmp9
	.long	Lset8
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset9 = Ltmp9-Lfunc_begin1              ## >> Call Site 2 <<
	.long	Lset9
Lset10 = Ltmp10-Ltmp9                   ##   Call between Ltmp9 and Ltmp10
	.long	Lset10
Lset11 = Ltmp11-Lfunc_begin1            ##     jumps to Ltmp11
	.long	Lset11
	.byte	0                       ##   On action: cleanup
Lset12 = Ltmp10-Lfunc_begin1            ## >> Call Site 3 <<
	.long	Lset12
Lset13 = Lfunc_end1-Ltmp10              ##   Call between Ltmp10 and Lfunc_end1
	.long	Lset13
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.globl	_init                   ## @init
.zerofill __DATA,__common,_init,12504,3
	.globl	_ret                    ## @ret
.zerofill __DATA,__common,_ret,12504,3
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

L_.str.1:                               ## @.str.1
	.asciz	"%1d"

L_.str.2:                               ## @.str.2
	.asciz	"\n"

L_.str.3:                               ## @.str.3
	.asciz	"%d\n"

L_.str.4:                               ## @.str.4
	.asciz	"bitset set argument out of range"

L_.str.5:                               ## @.str.5
	.asciz	"bitset flip argument out of range"


.subsections_via_symbols
