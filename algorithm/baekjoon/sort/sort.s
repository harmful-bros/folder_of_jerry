	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI0_0:
	.quad	4602678819172646912     ## double 0.5
	.section	__TEXT,__text,regular,pure_instructions
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
	subq	$112, %rsp
	leaq	L_.str(%rip), %rdi
	leaq	-80(%rbp), %rsi
	movl	$0, -76(%rbp)
	movb	$0, %al
	callq	_scanf
	movl	$0, -84(%rbp)
	movl	%eax, -88(%rbp)         ## 4-byte Spill
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-84(%rbp), %eax
	cmpl	-80(%rbp), %eax
	jge	LBB0_4
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	leaq	L_.str(%rip), %rdi
	leaq	_data(%rip), %rax
	movslq	-84(%rbp), %rcx
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, %rsi
	movb	$0, %al
	callq	_scanf
	leaq	_mode(%rip), %rcx
	leaq	_data(%rip), %rsi
	movslq	-84(%rbp), %rdi
	cvtsi2sdl	(%rsi,%rdi,4), %xmm0
	addsd	_sum(%rip), %xmm0
	movsd	%xmm0, _sum(%rip)
	movslq	-84(%rbp), %rdi
	movl	(%rsi,%rdi,4), %edx
	addl	$4000, %edx             ## imm = 0xFA0
	movslq	%edx, %rdi
	movl	(%rcx,%rdi,8), %edx
	addl	$1, %edx
	movl	%edx, (%rcx,%rdi,8)
	movslq	-84(%rbp), %rdi
	movl	(%rsi,%rdi,4), %edx
	movslq	-84(%rbp), %rdi
	movl	(%rsi,%rdi,4), %r8d
	addl	$4000, %r8d             ## imm = 0xFA0
	movslq	%r8d, %rsi
	movl	%edx, 4(%rcx,%rsi,8)
	movl	%eax, -92(%rbp)         ## 4-byte Spill
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-84(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -84(%rbp)
	jmp	LBB0_1
LBB0_4:
	leaq	L_.str.1(%rip), %rdi
	movsd	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movsd	_sum(%rip), %xmm1       ## xmm1 = mem[0],zero
	cvtsi2sdl	-80(%rbp), %xmm2
	divsd	%xmm2, %xmm1
	addsd	%xmm0, %xmm1
                                        ## implicit-def: %XMM0
	roundsd	$9, %xmm1, %xmm0
	cvttsd2si	%xmm0, %rsi
	movb	$0, %al
	callq	_printf
	leaq	-32(%rbp), %rdx
	leaq	_data(%rip), %rsi
	movslq	-80(%rbp), %rdi
	shlq	$2, %rdi
	movq	%rsi, %rcx
	addq	%rdi, %rcx
	movq	%rsi, -56(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-56(%rbp), %rcx
	movq	-64(%rbp), %rsi
	movq	%rcx, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rdi
	movq	-48(%rbp), %rsi
	movl	%eax, -96(%rbp)         ## 4-byte Spill
	callq	__ZNSt3__16__sortIRNS_6__lessIiiEEPiEEvT0_S5_T_
	leaq	L_.str.2(%rip), %rdi
	leaq	_data(%rip), %rcx
	movl	-80(%rbp), %eax
	sarl	$1, %eax
	movslq	%eax, %rdx
	movl	(%rcx,%rdx,4), %esi
	movb	$0, %al
	callq	_printf
	leaq	-24(%rbp), %rdx
	leaq	__ZL8_compareNSt3__14pairIiiEES1_(%rip), %rcx
	leaq	_mode(%rip), %rdi
	movq	%rdi, %r8
	addq	$64008, %r8             ## imm = 0xFA08
	movq	%rdi, -8(%rbp)
	movq	%r8, -16(%rbp)
	movq	%rcx, -24(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movl	%eax, -100(%rbp)        ## 4-byte Spill
	callq	__ZNSt3__16__sortIRPFbNS_4pairIiiEES2_EPS2_EEvT0_S7_T_
	movl	_mode(%rip), %eax
	cmpl	_mode+8(%rip), %eax
	jne	LBB0_6
## BB#5:
	leaq	L_.str.2(%rip), %rdi
	movl	_mode+12(%rip), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -104(%rbp)        ## 4-byte Spill
	jmp	LBB0_7
LBB0_6:
	leaq	L_.str.2(%rip), %rdi
	movl	_mode+4(%rip), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -108(%rbp)        ## 4-byte Spill
LBB0_7:
	leaq	L_.str.2(%rip), %rdi
	leaq	_data(%rip), %rax
	movl	-80(%rbp), %ecx
	subl	$1, %ecx
	movslq	%ecx, %rdx
	movl	(%rax,%rdx,4), %ecx
	subl	_data(%rip), %ecx
	movl	%ecx, %esi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -112(%rbp)        ## 4-byte Spill
	movl	%ecx, %eax
	addq	$112, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__ZL8_compareNSt3__14pairIiiEES1_:      ## @_ZL8_compareNSt3__14pairIiiEES1_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movl	-16(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jne	LBB1_2
## BB#1:
	movl	-12(%rbp), %eax
	cmpl	-20(%rbp), %eax
	setl	%cl
	andb	$1, %cl
	movb	%cl, -1(%rbp)
	jmp	LBB1_3
LBB1_2:
	movl	-16(%rbp), %eax
	cmpl	-24(%rbp), %eax
	setg	%cl
	andb	$1, %cl
	movb	%cl, -1(%rbp)
LBB1_3:
	movb	-1(%rbp), %al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__16__sortIRPFbNS_4pairIiiEES2_EPS2_EEvT0_S7_T_
	.weak_definition	__ZNSt3__16__sortIRPFbNS_4pairIiiEES2_EPS2_EEvT0_S7_T_
	.p2align	4, 0x90
__ZNSt3__16__sortIRPFbNS_4pairIiiEES2_EPS2_EEvT0_S7_T_: ## @_ZNSt3__16__sortIRPFbNS_4pairIiiEES2_EPS2_EEvT0_S7_T_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$2912, %rsp             ## imm = 0xB60
	movq	%rdi, -2568(%rbp)
	movq	%rsi, -2576(%rbp)
	movq	%rdx, -2584(%rbp)
	movq	$6, -2592(%rbp)
LBB2_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB2_2 Depth 2
                                        ##       Child Loop BB2_17 Depth 3
                                        ##       Child Loop BB2_20 Depth 3
                                        ##       Child Loop BB2_29 Depth 3
                                        ##         Child Loop BB2_30 Depth 4
                                        ##         Child Loop BB2_33 Depth 4
                                        ##     Child Loop BB2_45 Depth 2
                                        ##       Child Loop BB2_46 Depth 3
                                        ##       Child Loop BB2_49 Depth 3
	jmp	LBB2_2
LBB2_2:                                 ##   Parent Loop BB2_1 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB2_17 Depth 3
                                        ##       Child Loop BB2_20 Depth 3
                                        ##       Child Loop BB2_29 Depth 3
                                        ##         Child Loop BB2_30 Depth 4
                                        ##         Child Loop BB2_33 Depth 4
	movq	-2576(%rbp), %rax
	movq	-2568(%rbp), %rcx
	subq	%rcx, %rax
	sarq	$3, %rax
	movq	%rax, -2600(%rbp)
	movq	%rax, %rcx
	subq	$5, %rcx
	movq	%rax, -2824(%rbp)       ## 8-byte Spill
	movq	%rcx, -2832(%rbp)       ## 8-byte Spill
	ja	LBB2_10
## BB#74:
	leaq	LJTI2_0(%rip), %rax
	movq	-2824(%rbp), %rcx       ## 8-byte Reload
	movslq	(%rax,%rcx,4), %rdx
	addq	%rax, %rdx
	jmpq	*%rdx
LBB2_3:
	jmp	LBB2_73
LBB2_4:
	leaq	-2616(%rbp), %rax
	leaq	-2608(%rbp), %rcx
	movq	-2584(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2576(%rbp), %rsi
	addq	$-8, %rsi
	movq	%rsi, -2576(%rbp)
	movq	%rcx, -2552(%rbp)
	movq	%rsi, -2560(%rbp)
	movq	-2552(%rbp), %rcx
	movq	-2560(%rbp), %rsi
	movq	%rcx, -2536(%rbp)
	movq	%rsi, -2544(%rbp)
	movq	-2536(%rbp), %rcx
	movq	-2544(%rbp), %rsi
	movq	%rsi, -2528(%rbp)
	movq	-2528(%rbp), %rsi
	movq	%rsi, -2520(%rbp)
	movq	-2520(%rbp), %rsi
	movq	%rsi, -2488(%rbp)
	movq	-2488(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-2544(%rbp), %rsi
	movq	%rsi, -2504(%rbp)
	movq	-2504(%rbp), %rsi
	movq	%rsi, -2496(%rbp)
	movq	-2496(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -2512(%rbp)
	movq	-2512(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-2568(%rbp), %rcx
	movq	%rax, -2472(%rbp)
	movq	%rcx, -2480(%rbp)
	movq	-2472(%rbp), %rax
	movq	-2480(%rbp), %rcx
	movq	%rax, -2456(%rbp)
	movq	%rcx, -2464(%rbp)
	movq	-2456(%rbp), %rax
	movq	-2464(%rbp), %rcx
	movq	%rcx, -2448(%rbp)
	movq	-2448(%rbp), %rcx
	movq	%rcx, -2440(%rbp)
	movq	-2440(%rbp), %rcx
	movq	%rcx, -2408(%rbp)
	movq	-2408(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-2464(%rbp), %rcx
	movq	%rcx, -2424(%rbp)
	movq	-2424(%rbp), %rcx
	movq	%rcx, -2416(%rbp)
	movq	-2416(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -2432(%rbp)
	movq	-2432(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-2608(%rbp), %rdi
	movq	-2616(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB2_5
	jmp	LBB2_6
LBB2_5:
	leaq	-2284(%rbp), %rax
	leaq	-2348(%rbp), %rcx
	movq	-2568(%rbp), %rdx
	movq	-2576(%rbp), %rsi
	movq	%rdx, -2392(%rbp)
	movq	%rsi, -2400(%rbp)
	movq	-2392(%rbp), %rdx
	movq	-2400(%rbp), %rsi
	movq	%rdx, -2376(%rbp)
	movq	%rsi, -2384(%rbp)
	movq	-2376(%rbp), %rdx
	movq	-2384(%rbp), %rsi
	movq	%rdx, -2360(%rbp)
	movq	%rsi, -2368(%rbp)
	movq	-2360(%rbp), %rsi
	movq	-2368(%rbp), %rdi
	movq	%rsi, -2336(%rbp)
	movq	%rdi, -2344(%rbp)
	movq	-2336(%rbp), %rsi
	movq	%rsi, -2328(%rbp)
	movq	-2328(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, -2348(%rbp)
	movq	-2344(%rbp), %rsi
	movq	%rsi, -2312(%rbp)
	movq	-2312(%rbp), %rsi
	movl	(%rsi), %r8d
	movq	-2336(%rbp), %rsi
	movl	%r8d, (%rsi)
	movq	%rcx, -2320(%rbp)
	movq	-2320(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-2344(%rbp), %rcx
	movl	%r8d, (%rcx)
	addq	$4, %rdx
	movq	-2384(%rbp), %rcx
	addq	$4, %rcx
	movq	%rdx, -2296(%rbp)
	movq	%rcx, -2304(%rbp)
	movq	-2296(%rbp), %rcx
	movq	-2304(%rbp), %rdx
	movq	%rcx, -2272(%rbp)
	movq	%rdx, -2280(%rbp)
	movq	-2272(%rbp), %rcx
	movq	%rcx, -2264(%rbp)
	movq	-2264(%rbp), %rcx
	movl	(%rcx), %r8d
	movl	%r8d, -2284(%rbp)
	movq	-2280(%rbp), %rcx
	movq	%rcx, -2248(%rbp)
	movq	-2248(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-2272(%rbp), %rcx
	movl	%r8d, (%rcx)
	movq	%rax, -2256(%rbp)
	movq	-2256(%rbp), %rax
	movl	(%rax), %r8d
	movq	-2280(%rbp), %rax
	movl	%r8d, (%rax)
LBB2_6:
	jmp	LBB2_73
LBB2_7:
	movq	-2568(%rbp), %rdi
	movq	-2568(%rbp), %rax
	addq	$8, %rax
	movq	-2576(%rbp), %rcx
	addq	$-8, %rcx
	movq	%rcx, -2576(%rbp)
	movq	-2584(%rbp), %rdx
	movq	%rax, %rsi
	movq	%rdx, -2840(%rbp)       ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-2840(%rbp), %rcx       ## 8-byte Reload
	callq	__ZNSt3__17__sort3IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_T_
	movl	%eax, -2844(%rbp)       ## 4-byte Spill
	jmp	LBB2_73
LBB2_8:
	movq	-2568(%rbp), %rdi
	movq	-2568(%rbp), %rax
	addq	$8, %rax
	movq	-2568(%rbp), %rcx
	addq	$16, %rcx
	movq	-2576(%rbp), %rdx
	addq	$-8, %rdx
	movq	%rdx, -2576(%rbp)
	movq	-2584(%rbp), %r8
	movq	%rax, %rsi
	movq	%rdx, -2856(%rbp)       ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-2856(%rbp), %rcx       ## 8-byte Reload
	callq	__ZNSt3__17__sort4IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_T_
	movl	%eax, -2860(%rbp)       ## 4-byte Spill
	jmp	LBB2_73
LBB2_9:
	movq	-2568(%rbp), %rdi
	movq	-2568(%rbp), %rax
	addq	$8, %rax
	movq	-2568(%rbp), %rcx
	addq	$16, %rcx
	movq	-2568(%rbp), %rdx
	addq	$24, %rdx
	movq	-2576(%rbp), %rsi
	addq	$-8, %rsi
	movq	%rsi, -2576(%rbp)
	movq	-2584(%rbp), %r9
	movq	%rsi, -2872(%rbp)       ## 8-byte Spill
	movq	%rax, %rsi
	movq	%rdx, -2880(%rbp)       ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-2880(%rbp), %rcx       ## 8-byte Reload
	movq	-2872(%rbp), %r8        ## 8-byte Reload
	callq	__ZNSt3__17__sort5IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_S7_T_
	movl	%eax, -2884(%rbp)       ## 4-byte Spill
	jmp	LBB2_73
LBB2_10:                                ##   in Loop: Header=BB2_2 Depth=2
	cmpq	$6, -2600(%rbp)
	jg	LBB2_12
## BB#11:
	movq	-2568(%rbp), %rdi
	movq	-2576(%rbp), %rsi
	movq	-2584(%rbp), %rdx
	callq	__ZNSt3__118__insertion_sort_3IRPFbNS_4pairIiiEES2_EPS2_EEvT0_S7_T_
	jmp	LBB2_73
LBB2_12:                                ##   in Loop: Header=BB2_2 Depth=2
	movq	-2568(%rbp), %rax
	movq	%rax, -2624(%rbp)
	movq	-2576(%rbp), %rax
	movq	%rax, -2632(%rbp)
	movq	-2632(%rbp), %rax
	addq	$-8, %rax
	movq	%rax, -2632(%rbp)
	cmpq	$1000, -2600(%rbp)      ## imm = 0x3E8
	jl	LBB2_14
## BB#13:                               ##   in Loop: Header=BB2_2 Depth=2
	movl	$2, %eax
	movl	%eax, %ecx
	movq	-2600(%rbp), %rax
	cqto
	idivq	%rcx
	movq	%rax, -2648(%rbp)
	movq	-2648(%rbp), %rax
	shlq	$3, %rax
	addq	-2624(%rbp), %rax
	movq	%rax, -2624(%rbp)
	movq	-2648(%rbp), %rax
	cqto
	idivq	%rcx
	movq	%rax, -2648(%rbp)
	movq	-2568(%rbp), %rdi
	movq	-2568(%rbp), %rax
	movq	-2648(%rbp), %rcx
	shlq	$3, %rcx
	addq	%rcx, %rax
	movq	-2624(%rbp), %rcx
	movq	-2624(%rbp), %rsi
	movq	-2648(%rbp), %r8
	shlq	$3, %r8
	addq	%r8, %rsi
	movq	-2632(%rbp), %r8
	movq	-2584(%rbp), %r9
	movq	%rsi, -2896(%rbp)       ## 8-byte Spill
	movq	%rax, %rsi
	movq	%rcx, %rdx
	movq	-2896(%rbp), %rcx       ## 8-byte Reload
	callq	__ZNSt3__17__sort5IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_S7_T_
	movl	%eax, -2636(%rbp)
	jmp	LBB2_15
LBB2_14:                                ##   in Loop: Header=BB2_2 Depth=2
	movl	$2, %eax
	movl	%eax, %ecx
	movq	-2600(%rbp), %rax
	cqto
	idivq	%rcx
	movq	%rax, -2648(%rbp)
	movq	-2648(%rbp), %rax
	shlq	$3, %rax
	addq	-2624(%rbp), %rax
	movq	%rax, -2624(%rbp)
	movq	-2568(%rbp), %rdi
	movq	-2624(%rbp), %rsi
	movq	-2632(%rbp), %rax
	movq	-2584(%rbp), %rcx
	movq	%rax, %rdx
	callq	__ZNSt3__17__sort3IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_T_
	movl	%eax, -2636(%rbp)
LBB2_15:                                ##   in Loop: Header=BB2_2 Depth=2
	leaq	-2680(%rbp), %rax
	leaq	-2672(%rbp), %rcx
	movq	-2568(%rbp), %rdx
	movq	%rdx, -2656(%rbp)
	movq	-2632(%rbp), %rdx
	movq	%rdx, -2664(%rbp)
	movq	-2584(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2656(%rbp), %rsi
	movq	%rcx, -2232(%rbp)
	movq	%rsi, -2240(%rbp)
	movq	-2232(%rbp), %rcx
	movq	-2240(%rbp), %rsi
	movq	%rcx, -2216(%rbp)
	movq	%rsi, -2224(%rbp)
	movq	-2216(%rbp), %rcx
	movq	-2224(%rbp), %rsi
	movq	%rsi, -2208(%rbp)
	movq	-2208(%rbp), %rsi
	movq	%rsi, -2200(%rbp)
	movq	-2200(%rbp), %rsi
	movq	%rsi, -2168(%rbp)
	movq	-2168(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-2224(%rbp), %rsi
	movq	%rsi, -2184(%rbp)
	movq	-2184(%rbp), %rsi
	movq	%rsi, -2176(%rbp)
	movq	-2176(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -2192(%rbp)
	movq	-2192(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-2624(%rbp), %rcx
	movq	%rax, -2152(%rbp)
	movq	%rcx, -2160(%rbp)
	movq	-2152(%rbp), %rax
	movq	-2160(%rbp), %rcx
	movq	%rax, -2136(%rbp)
	movq	%rcx, -2144(%rbp)
	movq	-2136(%rbp), %rax
	movq	-2144(%rbp), %rcx
	movq	%rcx, -2128(%rbp)
	movq	-2128(%rbp), %rcx
	movq	%rcx, -2120(%rbp)
	movq	-2120(%rbp), %rcx
	movq	%rcx, -2088(%rbp)
	movq	-2088(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-2144(%rbp), %rcx
	movq	%rcx, -2104(%rbp)
	movq	-2104(%rbp), %rcx
	movq	%rcx, -2096(%rbp)
	movq	-2096(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -2112(%rbp)
	movq	-2112(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-2672(%rbp), %rdi
	movq	-2680(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB2_43
## BB#16:                               ##   in Loop: Header=BB2_2 Depth=2
	jmp	LBB2_17
LBB2_17:                                ##   Parent Loop BB2_1 Depth=1
                                        ##     Parent Loop BB2_2 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movq	-2656(%rbp), %rax
	movq	-2664(%rbp), %rcx
	addq	$-8, %rcx
	movq	%rcx, -2664(%rbp)
	cmpq	%rcx, %rax
	jne	LBB2_39
## BB#18:                               ##   in Loop: Header=BB2_2 Depth=2
	leaq	-2696(%rbp), %rax
	leaq	-2688(%rbp), %rcx
	movq	-2656(%rbp), %rdx
	addq	$8, %rdx
	movq	%rdx, -2656(%rbp)
	movq	-2576(%rbp), %rdx
	movq	%rdx, -2664(%rbp)
	movq	-2584(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2568(%rbp), %rsi
	movq	%rcx, -1912(%rbp)
	movq	%rsi, -1920(%rbp)
	movq	-1912(%rbp), %rcx
	movq	-1920(%rbp), %rsi
	movq	%rcx, -1896(%rbp)
	movq	%rsi, -1904(%rbp)
	movq	-1896(%rbp), %rcx
	movq	-1904(%rbp), %rsi
	movq	%rsi, -1888(%rbp)
	movq	-1888(%rbp), %rsi
	movq	%rsi, -1880(%rbp)
	movq	-1880(%rbp), %rsi
	movq	%rsi, -1848(%rbp)
	movq	-1848(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-1904(%rbp), %rsi
	movq	%rsi, -1864(%rbp)
	movq	-1864(%rbp), %rsi
	movq	%rsi, -1856(%rbp)
	movq	-1856(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -1872(%rbp)
	movq	-1872(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-2664(%rbp), %rcx
	addq	$-8, %rcx
	movq	%rcx, -2664(%rbp)
	movq	%rax, -1512(%rbp)
	movq	%rcx, -1520(%rbp)
	movq	-1512(%rbp), %rax
	movq	-1520(%rbp), %rcx
	movq	%rax, -1496(%rbp)
	movq	%rcx, -1504(%rbp)
	movq	-1496(%rbp), %rax
	movq	-1504(%rbp), %rcx
	movq	%rcx, -1488(%rbp)
	movq	-1488(%rbp), %rcx
	movq	%rcx, -1480(%rbp)
	movq	-1480(%rbp), %rcx
	movq	%rcx, -1448(%rbp)
	movq	-1448(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-1504(%rbp), %rcx
	movq	%rcx, -1464(%rbp)
	movq	-1464(%rbp), %rcx
	movq	%rcx, -1456(%rbp)
	movq	-1456(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -1472(%rbp)
	movq	-1472(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-2688(%rbp), %rdi
	movq	-2696(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB2_26
## BB#19:                               ##   in Loop: Header=BB2_2 Depth=2
	jmp	LBB2_20
LBB2_20:                                ##   Parent Loop BB2_1 Depth=1
                                        ##     Parent Loop BB2_2 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movq	-2656(%rbp), %rax
	cmpq	-2664(%rbp), %rax
	jne	LBB2_22
## BB#21:
	jmp	LBB2_73
LBB2_22:                                ##   in Loop: Header=BB2_20 Depth=3
	leaq	-2712(%rbp), %rax
	leaq	-2704(%rbp), %rcx
	movq	-2584(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2568(%rbp), %rsi
	movq	%rcx, -1272(%rbp)
	movq	%rsi, -1280(%rbp)
	movq	-1272(%rbp), %rcx
	movq	-1280(%rbp), %rsi
	movq	%rcx, -1256(%rbp)
	movq	%rsi, -1264(%rbp)
	movq	-1256(%rbp), %rcx
	movq	-1264(%rbp), %rsi
	movq	%rsi, -1248(%rbp)
	movq	-1248(%rbp), %rsi
	movq	%rsi, -1240(%rbp)
	movq	-1240(%rbp), %rsi
	movq	%rsi, -1208(%rbp)
	movq	-1208(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-1264(%rbp), %rsi
	movq	%rsi, -1224(%rbp)
	movq	-1224(%rbp), %rsi
	movq	%rsi, -1216(%rbp)
	movq	-1216(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -1232(%rbp)
	movq	-1232(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-2656(%rbp), %rcx
	movq	%rax, -872(%rbp)
	movq	%rcx, -880(%rbp)
	movq	-872(%rbp), %rax
	movq	-880(%rbp), %rcx
	movq	%rax, -856(%rbp)
	movq	%rcx, -864(%rbp)
	movq	-856(%rbp), %rax
	movq	-864(%rbp), %rcx
	movq	%rcx, -848(%rbp)
	movq	-848(%rbp), %rcx
	movq	%rcx, -840(%rbp)
	movq	-840(%rbp), %rcx
	movq	%rcx, -808(%rbp)
	movq	-808(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-864(%rbp), %rcx
	movq	%rcx, -824(%rbp)
	movq	-824(%rbp), %rcx
	movq	%rcx, -816(%rbp)
	movq	-816(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -832(%rbp)
	movq	-832(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-2704(%rbp), %rdi
	movq	-2712(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB2_23
	jmp	LBB2_24
LBB2_23:                                ##   in Loop: Header=BB2_2 Depth=2
	leaq	-364(%rbp), %rax
	leaq	-428(%rbp), %rcx
	movq	-2656(%rbp), %rdx
	movq	-2664(%rbp), %rsi
	movq	%rdx, -472(%rbp)
	movq	%rsi, -480(%rbp)
	movq	-472(%rbp), %rdx
	movq	-480(%rbp), %rsi
	movq	%rdx, -456(%rbp)
	movq	%rsi, -464(%rbp)
	movq	-456(%rbp), %rdx
	movq	-464(%rbp), %rsi
	movq	%rdx, -440(%rbp)
	movq	%rsi, -448(%rbp)
	movq	-440(%rbp), %rsi
	movq	-448(%rbp), %rdi
	movq	%rsi, -416(%rbp)
	movq	%rdi, -424(%rbp)
	movq	-416(%rbp), %rsi
	movq	%rsi, -408(%rbp)
	movq	-408(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, -428(%rbp)
	movq	-424(%rbp), %rsi
	movq	%rsi, -392(%rbp)
	movq	-392(%rbp), %rsi
	movl	(%rsi), %r8d
	movq	-416(%rbp), %rsi
	movl	%r8d, (%rsi)
	movq	%rcx, -400(%rbp)
	movq	-400(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-424(%rbp), %rcx
	movl	%r8d, (%rcx)
	addq	$4, %rdx
	movq	-464(%rbp), %rcx
	addq	$4, %rcx
	movq	%rdx, -376(%rbp)
	movq	%rcx, -384(%rbp)
	movq	-376(%rbp), %rcx
	movq	-384(%rbp), %rdx
	movq	%rcx, -352(%rbp)
	movq	%rdx, -360(%rbp)
	movq	-352(%rbp), %rcx
	movq	%rcx, -344(%rbp)
	movq	-344(%rbp), %rcx
	movl	(%rcx), %r8d
	movl	%r8d, -364(%rbp)
	movq	-360(%rbp), %rcx
	movq	%rcx, -328(%rbp)
	movq	-328(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-352(%rbp), %rcx
	movl	%r8d, (%rcx)
	movq	%rax, -336(%rbp)
	movq	-336(%rbp), %rax
	movl	(%rax), %r8d
	movq	-360(%rbp), %rax
	movl	%r8d, (%rax)
	movl	-2636(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -2636(%rbp)
	movq	-2656(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -2656(%rbp)
	jmp	LBB2_25
LBB2_24:                                ##   in Loop: Header=BB2_20 Depth=3
	movq	-2656(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -2656(%rbp)
	jmp	LBB2_20
LBB2_25:                                ##   in Loop: Header=BB2_2 Depth=2
	jmp	LBB2_26
LBB2_26:                                ##   in Loop: Header=BB2_2 Depth=2
	movq	-2656(%rbp), %rax
	cmpq	-2664(%rbp), %rax
	jne	LBB2_28
## BB#27:
	jmp	LBB2_73
LBB2_28:                                ##   in Loop: Header=BB2_2 Depth=2
	jmp	LBB2_29
LBB2_29:                                ##   Parent Loop BB2_1 Depth=1
                                        ##     Parent Loop BB2_2 Depth=2
                                        ## =>    This Loop Header: Depth=3
                                        ##         Child Loop BB2_30 Depth 4
                                        ##         Child Loop BB2_33 Depth 4
	jmp	LBB2_30
LBB2_30:                                ##   Parent Loop BB2_1 Depth=1
                                        ##     Parent Loop BB2_2 Depth=2
                                        ##       Parent Loop BB2_29 Depth=3
                                        ## =>      This Inner Loop Header: Depth=4
	leaq	-2728(%rbp), %rax
	leaq	-2720(%rbp), %rcx
	movq	-2584(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2568(%rbp), %rsi
	movq	%rcx, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	-152(%rbp), %rcx
	movq	-160(%rbp), %rsi
	movq	%rcx, -136(%rbp)
	movq	%rsi, -144(%rbp)
	movq	-136(%rbp), %rcx
	movq	-144(%rbp), %rsi
	movq	%rsi, -128(%rbp)
	movq	-128(%rbp), %rsi
	movq	%rsi, -120(%rbp)
	movq	-120(%rbp), %rsi
	movq	%rsi, -88(%rbp)
	movq	-88(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-144(%rbp), %rsi
	movq	%rsi, -104(%rbp)
	movq	-104(%rbp), %rsi
	movq	%rsi, -96(%rbp)
	movq	-96(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -112(%rbp)
	movq	-112(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-2656(%rbp), %rcx
	movq	%rax, -72(%rbp)
	movq	%rcx, -80(%rbp)
	movq	-72(%rbp), %rax
	movq	-80(%rbp), %rcx
	movq	%rax, -56(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-64(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-2720(%rbp), %rdi
	movq	-2728(%rbp), %rsi
	callq	*%rdx
	xorb	$-1, %al
	testb	$1, %al
	jne	LBB2_31
	jmp	LBB2_32
LBB2_31:                                ##   in Loop: Header=BB2_30 Depth=4
	movq	-2656(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -2656(%rbp)
	jmp	LBB2_30
LBB2_32:                                ##   in Loop: Header=BB2_29 Depth=3
	jmp	LBB2_33
LBB2_33:                                ##   Parent Loop BB2_1 Depth=1
                                        ##     Parent Loop BB2_2 Depth=2
                                        ##       Parent Loop BB2_29 Depth=3
                                        ## =>      This Inner Loop Header: Depth=4
	leaq	-2744(%rbp), %rax
	leaq	-2736(%rbp), %rcx
	movq	-2584(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2568(%rbp), %rsi
	movq	%rcx, -232(%rbp)
	movq	%rsi, -240(%rbp)
	movq	-232(%rbp), %rcx
	movq	-240(%rbp), %rsi
	movq	%rcx, -216(%rbp)
	movq	%rsi, -224(%rbp)
	movq	-216(%rbp), %rcx
	movq	-224(%rbp), %rsi
	movq	%rsi, -208(%rbp)
	movq	-208(%rbp), %rsi
	movq	%rsi, -200(%rbp)
	movq	-200(%rbp), %rsi
	movq	%rsi, -168(%rbp)
	movq	-168(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-224(%rbp), %rsi
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rsi
	movq	%rsi, -176(%rbp)
	movq	-176(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -192(%rbp)
	movq	-192(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-2664(%rbp), %rcx
	addq	$-8, %rcx
	movq	%rcx, -2664(%rbp)
	movq	%rax, -312(%rbp)
	movq	%rcx, -320(%rbp)
	movq	-312(%rbp), %rax
	movq	-320(%rbp), %rcx
	movq	%rax, -296(%rbp)
	movq	%rcx, -304(%rbp)
	movq	-296(%rbp), %rax
	movq	-304(%rbp), %rcx
	movq	%rcx, -288(%rbp)
	movq	-288(%rbp), %rcx
	movq	%rcx, -280(%rbp)
	movq	-280(%rbp), %rcx
	movq	%rcx, -248(%rbp)
	movq	-248(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-304(%rbp), %rcx
	movq	%rcx, -264(%rbp)
	movq	-264(%rbp), %rcx
	movq	%rcx, -256(%rbp)
	movq	-256(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -272(%rbp)
	movq	-272(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-2736(%rbp), %rdi
	movq	-2744(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB2_34
	jmp	LBB2_35
LBB2_34:                                ##   in Loop: Header=BB2_33 Depth=4
	jmp	LBB2_33
LBB2_35:                                ##   in Loop: Header=BB2_29 Depth=3
	movq	-2656(%rbp), %rax
	cmpq	-2664(%rbp), %rax
	jb	LBB2_37
## BB#36:                               ##   in Loop: Header=BB2_2 Depth=2
	jmp	LBB2_38
LBB2_37:                                ##   in Loop: Header=BB2_29 Depth=3
	leaq	-524(%rbp), %rax
	leaq	-588(%rbp), %rcx
	movq	-2656(%rbp), %rdx
	movq	-2664(%rbp), %rsi
	movq	%rdx, -632(%rbp)
	movq	%rsi, -640(%rbp)
	movq	-632(%rbp), %rdx
	movq	-640(%rbp), %rsi
	movq	%rdx, -616(%rbp)
	movq	%rsi, -624(%rbp)
	movq	-616(%rbp), %rdx
	movq	-624(%rbp), %rsi
	movq	%rdx, -600(%rbp)
	movq	%rsi, -608(%rbp)
	movq	-600(%rbp), %rsi
	movq	-608(%rbp), %rdi
	movq	%rsi, -576(%rbp)
	movq	%rdi, -584(%rbp)
	movq	-576(%rbp), %rsi
	movq	%rsi, -568(%rbp)
	movq	-568(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, -588(%rbp)
	movq	-584(%rbp), %rsi
	movq	%rsi, -552(%rbp)
	movq	-552(%rbp), %rsi
	movl	(%rsi), %r8d
	movq	-576(%rbp), %rsi
	movl	%r8d, (%rsi)
	movq	%rcx, -560(%rbp)
	movq	-560(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-584(%rbp), %rcx
	movl	%r8d, (%rcx)
	addq	$4, %rdx
	movq	-624(%rbp), %rcx
	addq	$4, %rcx
	movq	%rdx, -536(%rbp)
	movq	%rcx, -544(%rbp)
	movq	-536(%rbp), %rcx
	movq	-544(%rbp), %rdx
	movq	%rcx, -512(%rbp)
	movq	%rdx, -520(%rbp)
	movq	-512(%rbp), %rcx
	movq	%rcx, -504(%rbp)
	movq	-504(%rbp), %rcx
	movl	(%rcx), %r8d
	movl	%r8d, -524(%rbp)
	movq	-520(%rbp), %rcx
	movq	%rcx, -488(%rbp)
	movq	-488(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-512(%rbp), %rcx
	movl	%r8d, (%rcx)
	movq	%rax, -496(%rbp)
	movq	-496(%rbp), %rax
	movl	(%rax), %r8d
	movq	-520(%rbp), %rax
	movl	%r8d, (%rax)
	movl	-2636(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -2636(%rbp)
	movq	-2656(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -2656(%rbp)
	jmp	LBB2_29
LBB2_38:                                ##   in Loop: Header=BB2_2 Depth=2
	movq	-2656(%rbp), %rax
	movq	%rax, -2568(%rbp)
	jmp	LBB2_2
LBB2_39:                                ##   in Loop: Header=BB2_17 Depth=3
	leaq	-2760(%rbp), %rax
	leaq	-2752(%rbp), %rcx
	movq	-2584(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2664(%rbp), %rsi
	movq	%rcx, -712(%rbp)
	movq	%rsi, -720(%rbp)
	movq	-712(%rbp), %rcx
	movq	-720(%rbp), %rsi
	movq	%rcx, -696(%rbp)
	movq	%rsi, -704(%rbp)
	movq	-696(%rbp), %rcx
	movq	-704(%rbp), %rsi
	movq	%rsi, -688(%rbp)
	movq	-688(%rbp), %rsi
	movq	%rsi, -680(%rbp)
	movq	-680(%rbp), %rsi
	movq	%rsi, -648(%rbp)
	movq	-648(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-704(%rbp), %rsi
	movq	%rsi, -664(%rbp)
	movq	-664(%rbp), %rsi
	movq	%rsi, -656(%rbp)
	movq	-656(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -672(%rbp)
	movq	-672(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-2624(%rbp), %rcx
	movq	%rax, -792(%rbp)
	movq	%rcx, -800(%rbp)
	movq	-792(%rbp), %rax
	movq	-800(%rbp), %rcx
	movq	%rax, -776(%rbp)
	movq	%rcx, -784(%rbp)
	movq	-776(%rbp), %rax
	movq	-784(%rbp), %rcx
	movq	%rcx, -768(%rbp)
	movq	-768(%rbp), %rcx
	movq	%rcx, -760(%rbp)
	movq	-760(%rbp), %rcx
	movq	%rcx, -728(%rbp)
	movq	-728(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-784(%rbp), %rcx
	movq	%rcx, -744(%rbp)
	movq	-744(%rbp), %rcx
	movq	%rcx, -736(%rbp)
	movq	-736(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -752(%rbp)
	movq	-752(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-2752(%rbp), %rdi
	movq	-2760(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB2_40
	jmp	LBB2_41
LBB2_40:                                ##   in Loop: Header=BB2_1 Depth=1
	leaq	-924(%rbp), %rax
	leaq	-988(%rbp), %rcx
	movq	-2656(%rbp), %rdx
	movq	-2664(%rbp), %rsi
	movq	%rdx, -1032(%rbp)
	movq	%rsi, -1040(%rbp)
	movq	-1032(%rbp), %rdx
	movq	-1040(%rbp), %rsi
	movq	%rdx, -1016(%rbp)
	movq	%rsi, -1024(%rbp)
	movq	-1016(%rbp), %rdx
	movq	-1024(%rbp), %rsi
	movq	%rdx, -1000(%rbp)
	movq	%rsi, -1008(%rbp)
	movq	-1000(%rbp), %rsi
	movq	-1008(%rbp), %rdi
	movq	%rsi, -976(%rbp)
	movq	%rdi, -984(%rbp)
	movq	-976(%rbp), %rsi
	movq	%rsi, -968(%rbp)
	movq	-968(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, -988(%rbp)
	movq	-984(%rbp), %rsi
	movq	%rsi, -952(%rbp)
	movq	-952(%rbp), %rsi
	movl	(%rsi), %r8d
	movq	-976(%rbp), %rsi
	movl	%r8d, (%rsi)
	movq	%rcx, -960(%rbp)
	movq	-960(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-984(%rbp), %rcx
	movl	%r8d, (%rcx)
	addq	$4, %rdx
	movq	-1024(%rbp), %rcx
	addq	$4, %rcx
	movq	%rdx, -936(%rbp)
	movq	%rcx, -944(%rbp)
	movq	-936(%rbp), %rcx
	movq	-944(%rbp), %rdx
	movq	%rcx, -912(%rbp)
	movq	%rdx, -920(%rbp)
	movq	-912(%rbp), %rcx
	movq	%rcx, -904(%rbp)
	movq	-904(%rbp), %rcx
	movl	(%rcx), %r8d
	movl	%r8d, -924(%rbp)
	movq	-920(%rbp), %rcx
	movq	%rcx, -888(%rbp)
	movq	-888(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-912(%rbp), %rcx
	movl	%r8d, (%rcx)
	movq	%rax, -896(%rbp)
	movq	-896(%rbp), %rax
	movl	(%rax), %r8d
	movq	-920(%rbp), %rax
	movl	%r8d, (%rax)
	movl	-2636(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -2636(%rbp)
	jmp	LBB2_42
LBB2_41:                                ##   in Loop: Header=BB2_17 Depth=3
	jmp	LBB2_17
LBB2_42:                                ##   in Loop: Header=BB2_1 Depth=1
	jmp	LBB2_43
LBB2_43:                                ##   in Loop: Header=BB2_1 Depth=1
	movq	-2656(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -2656(%rbp)
	movq	-2656(%rbp), %rax
	cmpq	-2664(%rbp), %rax
	jae	LBB2_57
## BB#44:                               ##   in Loop: Header=BB2_1 Depth=1
	jmp	LBB2_45
LBB2_45:                                ##   Parent Loop BB2_1 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB2_46 Depth 3
                                        ##       Child Loop BB2_49 Depth 3
	jmp	LBB2_46
LBB2_46:                                ##   Parent Loop BB2_1 Depth=1
                                        ##     Parent Loop BB2_45 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	leaq	-2776(%rbp), %rax
	leaq	-2768(%rbp), %rcx
	movq	-2584(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2656(%rbp), %rsi
	movq	%rcx, -1112(%rbp)
	movq	%rsi, -1120(%rbp)
	movq	-1112(%rbp), %rcx
	movq	-1120(%rbp), %rsi
	movq	%rcx, -1096(%rbp)
	movq	%rsi, -1104(%rbp)
	movq	-1096(%rbp), %rcx
	movq	-1104(%rbp), %rsi
	movq	%rsi, -1088(%rbp)
	movq	-1088(%rbp), %rsi
	movq	%rsi, -1080(%rbp)
	movq	-1080(%rbp), %rsi
	movq	%rsi, -1048(%rbp)
	movq	-1048(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-1104(%rbp), %rsi
	movq	%rsi, -1064(%rbp)
	movq	-1064(%rbp), %rsi
	movq	%rsi, -1056(%rbp)
	movq	-1056(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -1072(%rbp)
	movq	-1072(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-2624(%rbp), %rcx
	movq	%rax, -1192(%rbp)
	movq	%rcx, -1200(%rbp)
	movq	-1192(%rbp), %rax
	movq	-1200(%rbp), %rcx
	movq	%rax, -1176(%rbp)
	movq	%rcx, -1184(%rbp)
	movq	-1176(%rbp), %rax
	movq	-1184(%rbp), %rcx
	movq	%rcx, -1168(%rbp)
	movq	-1168(%rbp), %rcx
	movq	%rcx, -1160(%rbp)
	movq	-1160(%rbp), %rcx
	movq	%rcx, -1128(%rbp)
	movq	-1128(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-1184(%rbp), %rcx
	movq	%rcx, -1144(%rbp)
	movq	-1144(%rbp), %rcx
	movq	%rcx, -1136(%rbp)
	movq	-1136(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -1152(%rbp)
	movq	-1152(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-2768(%rbp), %rdi
	movq	-2776(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB2_47
	jmp	LBB2_48
LBB2_47:                                ##   in Loop: Header=BB2_46 Depth=3
	movq	-2656(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -2656(%rbp)
	jmp	LBB2_46
LBB2_48:                                ##   in Loop: Header=BB2_45 Depth=2
	jmp	LBB2_49
LBB2_49:                                ##   Parent Loop BB2_1 Depth=1
                                        ##     Parent Loop BB2_45 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	leaq	-2792(%rbp), %rax
	leaq	-2784(%rbp), %rcx
	movq	-2584(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2664(%rbp), %rsi
	addq	$-8, %rsi
	movq	%rsi, -2664(%rbp)
	movq	%rcx, -1352(%rbp)
	movq	%rsi, -1360(%rbp)
	movq	-1352(%rbp), %rcx
	movq	-1360(%rbp), %rsi
	movq	%rcx, -1336(%rbp)
	movq	%rsi, -1344(%rbp)
	movq	-1336(%rbp), %rcx
	movq	-1344(%rbp), %rsi
	movq	%rsi, -1328(%rbp)
	movq	-1328(%rbp), %rsi
	movq	%rsi, -1320(%rbp)
	movq	-1320(%rbp), %rsi
	movq	%rsi, -1288(%rbp)
	movq	-1288(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-1344(%rbp), %rsi
	movq	%rsi, -1304(%rbp)
	movq	-1304(%rbp), %rsi
	movq	%rsi, -1296(%rbp)
	movq	-1296(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -1312(%rbp)
	movq	-1312(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-2624(%rbp), %rcx
	movq	%rax, -1432(%rbp)
	movq	%rcx, -1440(%rbp)
	movq	-1432(%rbp), %rax
	movq	-1440(%rbp), %rcx
	movq	%rax, -1416(%rbp)
	movq	%rcx, -1424(%rbp)
	movq	-1416(%rbp), %rax
	movq	-1424(%rbp), %rcx
	movq	%rcx, -1408(%rbp)
	movq	-1408(%rbp), %rcx
	movq	%rcx, -1400(%rbp)
	movq	-1400(%rbp), %rcx
	movq	%rcx, -1368(%rbp)
	movq	-1368(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-1424(%rbp), %rcx
	movq	%rcx, -1384(%rbp)
	movq	-1384(%rbp), %rcx
	movq	%rcx, -1376(%rbp)
	movq	-1376(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -1392(%rbp)
	movq	-1392(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-2784(%rbp), %rdi
	movq	-2792(%rbp), %rsi
	callq	*%rdx
	xorb	$-1, %al
	testb	$1, %al
	jne	LBB2_50
	jmp	LBB2_51
LBB2_50:                                ##   in Loop: Header=BB2_49 Depth=3
	jmp	LBB2_49
LBB2_51:                                ##   in Loop: Header=BB2_45 Depth=2
	movq	-2656(%rbp), %rax
	cmpq	-2664(%rbp), %rax
	jbe	LBB2_53
## BB#52:                               ##   in Loop: Header=BB2_1 Depth=1
	jmp	LBB2_56
LBB2_53:                                ##   in Loop: Header=BB2_45 Depth=2
	leaq	-1564(%rbp), %rax
	leaq	-1628(%rbp), %rcx
	movq	-2656(%rbp), %rdx
	movq	-2664(%rbp), %rsi
	movq	%rdx, -1672(%rbp)
	movq	%rsi, -1680(%rbp)
	movq	-1672(%rbp), %rdx
	movq	-1680(%rbp), %rsi
	movq	%rdx, -1656(%rbp)
	movq	%rsi, -1664(%rbp)
	movq	-1656(%rbp), %rdx
	movq	-1664(%rbp), %rsi
	movq	%rdx, -1640(%rbp)
	movq	%rsi, -1648(%rbp)
	movq	-1640(%rbp), %rsi
	movq	-1648(%rbp), %rdi
	movq	%rsi, -1616(%rbp)
	movq	%rdi, -1624(%rbp)
	movq	-1616(%rbp), %rsi
	movq	%rsi, -1608(%rbp)
	movq	-1608(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, -1628(%rbp)
	movq	-1624(%rbp), %rsi
	movq	%rsi, -1592(%rbp)
	movq	-1592(%rbp), %rsi
	movl	(%rsi), %r8d
	movq	-1616(%rbp), %rsi
	movl	%r8d, (%rsi)
	movq	%rcx, -1600(%rbp)
	movq	-1600(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-1624(%rbp), %rcx
	movl	%r8d, (%rcx)
	addq	$4, %rdx
	movq	-1664(%rbp), %rcx
	addq	$4, %rcx
	movq	%rdx, -1576(%rbp)
	movq	%rcx, -1584(%rbp)
	movq	-1576(%rbp), %rcx
	movq	-1584(%rbp), %rdx
	movq	%rcx, -1552(%rbp)
	movq	%rdx, -1560(%rbp)
	movq	-1552(%rbp), %rcx
	movq	%rcx, -1544(%rbp)
	movq	-1544(%rbp), %rcx
	movl	(%rcx), %r8d
	movl	%r8d, -1564(%rbp)
	movq	-1560(%rbp), %rcx
	movq	%rcx, -1528(%rbp)
	movq	-1528(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-1552(%rbp), %rcx
	movl	%r8d, (%rcx)
	movq	%rax, -1536(%rbp)
	movq	-1536(%rbp), %rax
	movl	(%rax), %r8d
	movq	-1560(%rbp), %rax
	movl	%r8d, (%rax)
	movl	-2636(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -2636(%rbp)
	movq	-2624(%rbp), %rax
	cmpq	-2656(%rbp), %rax
	jne	LBB2_55
## BB#54:                               ##   in Loop: Header=BB2_45 Depth=2
	movq	-2664(%rbp), %rax
	movq	%rax, -2624(%rbp)
LBB2_55:                                ##   in Loop: Header=BB2_45 Depth=2
	movq	-2656(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -2656(%rbp)
	jmp	LBB2_45
LBB2_56:                                ##   in Loop: Header=BB2_1 Depth=1
	jmp	LBB2_57
LBB2_57:                                ##   in Loop: Header=BB2_1 Depth=1
	movq	-2656(%rbp), %rax
	cmpq	-2624(%rbp), %rax
	je	LBB2_60
## BB#58:                               ##   in Loop: Header=BB2_1 Depth=1
	leaq	-2808(%rbp), %rax
	leaq	-2800(%rbp), %rcx
	movq	-2584(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2624(%rbp), %rsi
	movq	%rcx, -1752(%rbp)
	movq	%rsi, -1760(%rbp)
	movq	-1752(%rbp), %rcx
	movq	-1760(%rbp), %rsi
	movq	%rcx, -1736(%rbp)
	movq	%rsi, -1744(%rbp)
	movq	-1736(%rbp), %rcx
	movq	-1744(%rbp), %rsi
	movq	%rsi, -1728(%rbp)
	movq	-1728(%rbp), %rsi
	movq	%rsi, -1720(%rbp)
	movq	-1720(%rbp), %rsi
	movq	%rsi, -1688(%rbp)
	movq	-1688(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-1744(%rbp), %rsi
	movq	%rsi, -1704(%rbp)
	movq	-1704(%rbp), %rsi
	movq	%rsi, -1696(%rbp)
	movq	-1696(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -1712(%rbp)
	movq	-1712(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-2656(%rbp), %rcx
	movq	%rax, -1832(%rbp)
	movq	%rcx, -1840(%rbp)
	movq	-1832(%rbp), %rax
	movq	-1840(%rbp), %rcx
	movq	%rax, -1816(%rbp)
	movq	%rcx, -1824(%rbp)
	movq	-1816(%rbp), %rax
	movq	-1824(%rbp), %rcx
	movq	%rcx, -1808(%rbp)
	movq	-1808(%rbp), %rcx
	movq	%rcx, -1800(%rbp)
	movq	-1800(%rbp), %rcx
	movq	%rcx, -1768(%rbp)
	movq	-1768(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-1824(%rbp), %rcx
	movq	%rcx, -1784(%rbp)
	movq	-1784(%rbp), %rcx
	movq	%rcx, -1776(%rbp)
	movq	-1776(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -1792(%rbp)
	movq	-1792(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-2800(%rbp), %rdi
	movq	-2808(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB2_59
	jmp	LBB2_60
LBB2_59:                                ##   in Loop: Header=BB2_1 Depth=1
	leaq	-1964(%rbp), %rax
	leaq	-2028(%rbp), %rcx
	movq	-2656(%rbp), %rdx
	movq	-2624(%rbp), %rsi
	movq	%rdx, -2072(%rbp)
	movq	%rsi, -2080(%rbp)
	movq	-2072(%rbp), %rdx
	movq	-2080(%rbp), %rsi
	movq	%rdx, -2056(%rbp)
	movq	%rsi, -2064(%rbp)
	movq	-2056(%rbp), %rdx
	movq	-2064(%rbp), %rsi
	movq	%rdx, -2040(%rbp)
	movq	%rsi, -2048(%rbp)
	movq	-2040(%rbp), %rsi
	movq	-2048(%rbp), %rdi
	movq	%rsi, -2016(%rbp)
	movq	%rdi, -2024(%rbp)
	movq	-2016(%rbp), %rsi
	movq	%rsi, -2008(%rbp)
	movq	-2008(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, -2028(%rbp)
	movq	-2024(%rbp), %rsi
	movq	%rsi, -1992(%rbp)
	movq	-1992(%rbp), %rsi
	movl	(%rsi), %r8d
	movq	-2016(%rbp), %rsi
	movl	%r8d, (%rsi)
	movq	%rcx, -2000(%rbp)
	movq	-2000(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-2024(%rbp), %rcx
	movl	%r8d, (%rcx)
	addq	$4, %rdx
	movq	-2064(%rbp), %rcx
	addq	$4, %rcx
	movq	%rdx, -1976(%rbp)
	movq	%rcx, -1984(%rbp)
	movq	-1976(%rbp), %rcx
	movq	-1984(%rbp), %rdx
	movq	%rcx, -1952(%rbp)
	movq	%rdx, -1960(%rbp)
	movq	-1952(%rbp), %rcx
	movq	%rcx, -1944(%rbp)
	movq	-1944(%rbp), %rcx
	movl	(%rcx), %r8d
	movl	%r8d, -1964(%rbp)
	movq	-1960(%rbp), %rcx
	movq	%rcx, -1928(%rbp)
	movq	-1928(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-1952(%rbp), %rcx
	movl	%r8d, (%rcx)
	movq	%rax, -1936(%rbp)
	movq	-1936(%rbp), %rax
	movl	(%rax), %r8d
	movq	-1960(%rbp), %rax
	movl	%r8d, (%rax)
	movl	-2636(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -2636(%rbp)
LBB2_60:                                ##   in Loop: Header=BB2_1 Depth=1
	cmpl	$0, -2636(%rbp)
	jne	LBB2_69
## BB#61:                               ##   in Loop: Header=BB2_1 Depth=1
	movq	-2568(%rbp), %rdi
	movq	-2656(%rbp), %rsi
	movq	-2584(%rbp), %rdx
	callq	__ZNSt3__127__insertion_sort_incompleteIRPFbNS_4pairIiiEES2_EPS2_EEbT0_S7_T_
	andb	$1, %al
	movb	%al, -2809(%rbp)
	movq	-2656(%rbp), %rdx
	addq	$8, %rdx
	movq	-2576(%rbp), %rsi
	movq	-2584(%rbp), %rdi
	movq	%rdi, -2904(%rbp)       ## 8-byte Spill
	movq	%rdx, %rdi
	movq	-2904(%rbp), %rdx       ## 8-byte Reload
	callq	__ZNSt3__127__insertion_sort_incompleteIRPFbNS_4pairIiiEES2_EPS2_EEbT0_S7_T_
	testb	$1, %al
	jne	LBB2_62
	jmp	LBB2_65
LBB2_62:                                ##   in Loop: Header=BB2_1 Depth=1
	testb	$1, -2809(%rbp)
	je	LBB2_64
## BB#63:
	jmp	LBB2_73
LBB2_64:                                ##   in Loop: Header=BB2_1 Depth=1
	movq	-2656(%rbp), %rax
	movq	%rax, -2576(%rbp)
	jmp	LBB2_1
LBB2_65:                                ##   in Loop: Header=BB2_1 Depth=1
	testb	$1, -2809(%rbp)
	je	LBB2_67
## BB#66:                               ##   in Loop: Header=BB2_1 Depth=1
	movq	-2656(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -2656(%rbp)
	movq	%rax, -2568(%rbp)
	jmp	LBB2_1
LBB2_67:                                ##   in Loop: Header=BB2_1 Depth=1
	jmp	LBB2_68
LBB2_68:                                ##   in Loop: Header=BB2_1 Depth=1
	jmp	LBB2_69
LBB2_69:                                ##   in Loop: Header=BB2_1 Depth=1
	movq	-2656(%rbp), %rax
	movq	-2568(%rbp), %rcx
	subq	%rcx, %rax
	sarq	$3, %rax
	movq	-2576(%rbp), %rcx
	movq	-2656(%rbp), %rdx
	subq	%rdx, %rcx
	sarq	$3, %rcx
	cmpq	%rcx, %rax
	jge	LBB2_71
## BB#70:                               ##   in Loop: Header=BB2_1 Depth=1
	movq	-2568(%rbp), %rdi
	movq	-2656(%rbp), %rsi
	movq	-2584(%rbp), %rdx
	callq	__ZNSt3__16__sortIRPFbNS_4pairIiiEES2_EPS2_EEvT0_S7_T_
	movq	-2656(%rbp), %rdx
	addq	$8, %rdx
	movq	%rdx, -2656(%rbp)
	movq	%rdx, -2568(%rbp)
	jmp	LBB2_72
LBB2_71:                                ##   in Loop: Header=BB2_1 Depth=1
	movq	-2656(%rbp), %rax
	addq	$8, %rax
	movq	-2576(%rbp), %rsi
	movq	-2584(%rbp), %rdx
	movq	%rax, %rdi
	callq	__ZNSt3__16__sortIRPFbNS_4pairIiiEES2_EPS2_EEvT0_S7_T_
	movq	-2656(%rbp), %rax
	movq	%rax, -2576(%rbp)
LBB2_72:                                ##   in Loop: Header=BB2_1 Depth=1
	jmp	LBB2_1
LBB2_73:
	addq	$2912, %rsp             ## imm = 0xB60
	popq	%rbp
	retq
	.cfi_endproc
	.p2align	2, 0x90
	.data_region jt32
L2_0_set_3 = LBB2_3-LJTI2_0
L2_0_set_4 = LBB2_4-LJTI2_0
L2_0_set_7 = LBB2_7-LJTI2_0
L2_0_set_8 = LBB2_8-LJTI2_0
L2_0_set_9 = LBB2_9-LJTI2_0
LJTI2_0:
	.long	L2_0_set_3
	.long	L2_0_set_3
	.long	L2_0_set_4
	.long	L2_0_set_7
	.long	L2_0_set_8
	.long	L2_0_set_9
	.end_data_region

	.globl	__ZNSt3__17__sort3IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_T_
	.weak_definition	__ZNSt3__17__sort3IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_T_
	.p2align	4, 0x90
__ZNSt3__17__sort3IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_T_: ## @_ZNSt3__17__sort3IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_T_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	subq	$1728, %rsp             ## imm = 0x6C0
	leaq	-1664(%rbp), %rax
	leaq	-1656(%rbp), %r8
	movq	%rdi, -1616(%rbp)
	movq	%rsi, -1624(%rbp)
	movq	%rdx, -1632(%rbp)
	movq	%rcx, -1640(%rbp)
	movl	$0, -1644(%rbp)
	movq	-1640(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-1624(%rbp), %rdx
	movq	%r8, -1592(%rbp)
	movq	%rdx, -1600(%rbp)
	movq	-1592(%rbp), %rdx
	movq	-1600(%rbp), %rsi
	movq	%rdx, -1576(%rbp)
	movq	%rsi, -1584(%rbp)
	movq	-1576(%rbp), %rdx
	movq	-1584(%rbp), %rsi
	movq	%rsi, -1568(%rbp)
	movq	-1568(%rbp), %rsi
	movq	%rsi, -1560(%rbp)
	movq	-1560(%rbp), %rsi
	movq	%rsi, -1528(%rbp)
	movq	-1528(%rbp), %rsi
	movl	(%rsi), %r9d
	movl	%r9d, (%rdx)
	movq	-1584(%rbp), %rsi
	movq	%rsi, -1544(%rbp)
	movq	-1544(%rbp), %rsi
	movq	%rsi, -1536(%rbp)
	movq	-1536(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -1552(%rbp)
	movq	-1552(%rbp), %rsi
	movl	(%rsi), %r9d
	movl	%r9d, 4(%rdx)
	movq	-1616(%rbp), %rdx
	movq	%rax, -1352(%rbp)
	movq	%rdx, -1360(%rbp)
	movq	-1352(%rbp), %rax
	movq	-1360(%rbp), %rdx
	movq	%rax, -1336(%rbp)
	movq	%rdx, -1344(%rbp)
	movq	-1336(%rbp), %rax
	movq	-1344(%rbp), %rdx
	movq	%rdx, -1328(%rbp)
	movq	-1328(%rbp), %rdx
	movq	%rdx, -1320(%rbp)
	movq	-1320(%rbp), %rdx
	movq	%rdx, -1288(%rbp)
	movq	-1288(%rbp), %rdx
	movl	(%rdx), %r9d
	movl	%r9d, (%rax)
	movq	-1344(%rbp), %rdx
	movq	%rdx, -1304(%rbp)
	movq	-1304(%rbp), %rdx
	movq	%rdx, -1296(%rbp)
	movq	-1296(%rbp), %rdx
	addq	$4, %rdx
	movq	%rdx, -1312(%rbp)
	movq	-1312(%rbp), %rdx
	movl	(%rdx), %r9d
	movl	%r9d, 4(%rax)
	movq	-1656(%rbp), %rdi
	movq	-1664(%rbp), %rsi
	callq	*%rcx
	testb	$1, %al
	jne	LBB3_6
## BB#1:
	leaq	-1680(%rbp), %rax
	leaq	-1672(%rbp), %rcx
	movq	-1640(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-1632(%rbp), %rsi
	movq	%rcx, -792(%rbp)
	movq	%rsi, -800(%rbp)
	movq	-792(%rbp), %rcx
	movq	-800(%rbp), %rsi
	movq	%rcx, -776(%rbp)
	movq	%rsi, -784(%rbp)
	movq	-776(%rbp), %rcx
	movq	-784(%rbp), %rsi
	movq	%rsi, -768(%rbp)
	movq	-768(%rbp), %rsi
	movq	%rsi, -760(%rbp)
	movq	-760(%rbp), %rsi
	movq	%rsi, -728(%rbp)
	movq	-728(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-784(%rbp), %rsi
	movq	%rsi, -744(%rbp)
	movq	-744(%rbp), %rsi
	movq	%rsi, -736(%rbp)
	movq	-736(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -752(%rbp)
	movq	-752(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-1624(%rbp), %rcx
	movq	%rax, -392(%rbp)
	movq	%rcx, -400(%rbp)
	movq	-392(%rbp), %rax
	movq	-400(%rbp), %rcx
	movq	%rax, -376(%rbp)
	movq	%rcx, -384(%rbp)
	movq	-376(%rbp), %rax
	movq	-384(%rbp), %rcx
	movq	%rcx, -368(%rbp)
	movq	-368(%rbp), %rcx
	movq	%rcx, -360(%rbp)
	movq	-360(%rbp), %rcx
	movq	%rcx, -328(%rbp)
	movq	-328(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-384(%rbp), %rcx
	movq	%rcx, -344(%rbp)
	movq	-344(%rbp), %rcx
	movq	%rcx, -336(%rbp)
	movq	-336(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -352(%rbp)
	movq	-352(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-1672(%rbp), %rdi
	movq	-1680(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB3_3
## BB#2:
	movl	-1644(%rbp), %eax
	movl	%eax, -1604(%rbp)
	jmp	LBB3_11
LBB3_3:
	leaq	-1696(%rbp), %rax
	leaq	-1688(%rbp), %rcx
	leaq	-44(%rbp), %rdx
	leaq	-108(%rbp), %rsi
	movq	-1624(%rbp), %rdi
	movq	-1632(%rbp), %r8
	movq	%rdi, -152(%rbp)
	movq	%r8, -160(%rbp)
	movq	-152(%rbp), %rdi
	movq	-160(%rbp), %r8
	movq	%rdi, -136(%rbp)
	movq	%r8, -144(%rbp)
	movq	-136(%rbp), %rdi
	movq	-144(%rbp), %r8
	movq	%rdi, -120(%rbp)
	movq	%r8, -128(%rbp)
	movq	-120(%rbp), %r8
	movq	-128(%rbp), %r9
	movq	%r8, -96(%rbp)
	movq	%r9, -104(%rbp)
	movq	-96(%rbp), %r8
	movq	%r8, -88(%rbp)
	movq	-88(%rbp), %r8
	movl	(%r8), %r10d
	movl	%r10d, -108(%rbp)
	movq	-104(%rbp), %r8
	movq	%r8, -72(%rbp)
	movq	-72(%rbp), %r8
	movl	(%r8), %r10d
	movq	-96(%rbp), %r8
	movl	%r10d, (%r8)
	movq	%rsi, -80(%rbp)
	movq	-80(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-104(%rbp), %rsi
	movl	%r10d, (%rsi)
	addq	$4, %rdi
	movq	-144(%rbp), %rsi
	addq	$4, %rsi
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	-56(%rbp), %rsi
	movq	-64(%rbp), %rdi
	movq	%rsi, -32(%rbp)
	movq	%rdi, -40(%rbp)
	movq	-32(%rbp), %rsi
	movq	%rsi, -24(%rbp)
	movq	-24(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, -44(%rbp)
	movq	-40(%rbp), %rsi
	movq	%rsi, -8(%rbp)
	movq	-8(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-32(%rbp), %rsi
	movl	%r10d, (%rsi)
	movq	%rdx, -16(%rbp)
	movq	-16(%rbp), %rdx
	movl	(%rdx), %r10d
	movq	-40(%rbp), %rdx
	movl	%r10d, (%rdx)
	movl	$1, -1644(%rbp)
	movq	-1640(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-1624(%rbp), %rsi
	movq	%rcx, -232(%rbp)
	movq	%rsi, -240(%rbp)
	movq	-232(%rbp), %rcx
	movq	-240(%rbp), %rsi
	movq	%rcx, -216(%rbp)
	movq	%rsi, -224(%rbp)
	movq	-216(%rbp), %rcx
	movq	-224(%rbp), %rsi
	movq	%rsi, -208(%rbp)
	movq	-208(%rbp), %rsi
	movq	%rsi, -200(%rbp)
	movq	-200(%rbp), %rsi
	movq	%rsi, -168(%rbp)
	movq	-168(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, (%rcx)
	movq	-224(%rbp), %rsi
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rsi
	movq	%rsi, -176(%rbp)
	movq	-176(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -192(%rbp)
	movq	-192(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, 4(%rcx)
	movq	-1616(%rbp), %rcx
	movq	%rax, -312(%rbp)
	movq	%rcx, -320(%rbp)
	movq	-312(%rbp), %rax
	movq	-320(%rbp), %rcx
	movq	%rax, -296(%rbp)
	movq	%rcx, -304(%rbp)
	movq	-296(%rbp), %rax
	movq	-304(%rbp), %rcx
	movq	%rcx, -288(%rbp)
	movq	-288(%rbp), %rcx
	movq	%rcx, -280(%rbp)
	movq	-280(%rbp), %rcx
	movq	%rcx, -248(%rbp)
	movq	-248(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, (%rax)
	movq	-304(%rbp), %rcx
	movq	%rcx, -264(%rbp)
	movq	-264(%rbp), %rcx
	movq	%rcx, -256(%rbp)
	movq	-256(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -272(%rbp)
	movq	-272(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, 4(%rax)
	movq	-1688(%rbp), %rdi
	movq	-1696(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB3_4
	jmp	LBB3_5
LBB3_4:
	leaq	-444(%rbp), %rax
	leaq	-508(%rbp), %rcx
	movq	-1616(%rbp), %rdx
	movq	-1624(%rbp), %rsi
	movq	%rdx, -552(%rbp)
	movq	%rsi, -560(%rbp)
	movq	-552(%rbp), %rdx
	movq	-560(%rbp), %rsi
	movq	%rdx, -536(%rbp)
	movq	%rsi, -544(%rbp)
	movq	-536(%rbp), %rdx
	movq	-544(%rbp), %rsi
	movq	%rdx, -520(%rbp)
	movq	%rsi, -528(%rbp)
	movq	-520(%rbp), %rsi
	movq	-528(%rbp), %rdi
	movq	%rsi, -496(%rbp)
	movq	%rdi, -504(%rbp)
	movq	-496(%rbp), %rsi
	movq	%rsi, -488(%rbp)
	movq	-488(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, -508(%rbp)
	movq	-504(%rbp), %rsi
	movq	%rsi, -472(%rbp)
	movq	-472(%rbp), %rsi
	movl	(%rsi), %r8d
	movq	-496(%rbp), %rsi
	movl	%r8d, (%rsi)
	movq	%rcx, -480(%rbp)
	movq	-480(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-504(%rbp), %rcx
	movl	%r8d, (%rcx)
	addq	$4, %rdx
	movq	-544(%rbp), %rcx
	addq	$4, %rcx
	movq	%rdx, -456(%rbp)
	movq	%rcx, -464(%rbp)
	movq	-456(%rbp), %rcx
	movq	-464(%rbp), %rdx
	movq	%rcx, -432(%rbp)
	movq	%rdx, -440(%rbp)
	movq	-432(%rbp), %rcx
	movq	%rcx, -424(%rbp)
	movq	-424(%rbp), %rcx
	movl	(%rcx), %r8d
	movl	%r8d, -444(%rbp)
	movq	-440(%rbp), %rcx
	movq	%rcx, -408(%rbp)
	movq	-408(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-432(%rbp), %rcx
	movl	%r8d, (%rcx)
	movq	%rax, -416(%rbp)
	movq	-416(%rbp), %rax
	movl	(%rax), %r8d
	movq	-440(%rbp), %rax
	movl	%r8d, (%rax)
	movl	$2, -1644(%rbp)
LBB3_5:
	movl	-1644(%rbp), %eax
	movl	%eax, -1604(%rbp)
	jmp	LBB3_11
LBB3_6:
	leaq	-1712(%rbp), %rax
	leaq	-1704(%rbp), %rcx
	movq	-1640(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-1632(%rbp), %rsi
	movq	%rcx, -632(%rbp)
	movq	%rsi, -640(%rbp)
	movq	-632(%rbp), %rcx
	movq	-640(%rbp), %rsi
	movq	%rcx, -616(%rbp)
	movq	%rsi, -624(%rbp)
	movq	-616(%rbp), %rcx
	movq	-624(%rbp), %rsi
	movq	%rsi, -608(%rbp)
	movq	-608(%rbp), %rsi
	movq	%rsi, -600(%rbp)
	movq	-600(%rbp), %rsi
	movq	%rsi, -568(%rbp)
	movq	-568(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-624(%rbp), %rsi
	movq	%rsi, -584(%rbp)
	movq	-584(%rbp), %rsi
	movq	%rsi, -576(%rbp)
	movq	-576(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -592(%rbp)
	movq	-592(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-1624(%rbp), %rcx
	movq	%rax, -712(%rbp)
	movq	%rcx, -720(%rbp)
	movq	-712(%rbp), %rax
	movq	-720(%rbp), %rcx
	movq	%rax, -696(%rbp)
	movq	%rcx, -704(%rbp)
	movq	-696(%rbp), %rax
	movq	-704(%rbp), %rcx
	movq	%rcx, -688(%rbp)
	movq	-688(%rbp), %rcx
	movq	%rcx, -680(%rbp)
	movq	-680(%rbp), %rcx
	movq	%rcx, -648(%rbp)
	movq	-648(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-704(%rbp), %rcx
	movq	%rcx, -664(%rbp)
	movq	-664(%rbp), %rcx
	movq	%rcx, -656(%rbp)
	movq	-656(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -672(%rbp)
	movq	-672(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-1704(%rbp), %rdi
	movq	-1712(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB3_7
	jmp	LBB3_8
LBB3_7:
	leaq	-844(%rbp), %rax
	leaq	-908(%rbp), %rcx
	movq	-1616(%rbp), %rdx
	movq	-1632(%rbp), %rsi
	movq	%rdx, -952(%rbp)
	movq	%rsi, -960(%rbp)
	movq	-952(%rbp), %rdx
	movq	-960(%rbp), %rsi
	movq	%rdx, -936(%rbp)
	movq	%rsi, -944(%rbp)
	movq	-936(%rbp), %rdx
	movq	-944(%rbp), %rsi
	movq	%rdx, -920(%rbp)
	movq	%rsi, -928(%rbp)
	movq	-920(%rbp), %rsi
	movq	-928(%rbp), %rdi
	movq	%rsi, -896(%rbp)
	movq	%rdi, -904(%rbp)
	movq	-896(%rbp), %rsi
	movq	%rsi, -888(%rbp)
	movq	-888(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, -908(%rbp)
	movq	-904(%rbp), %rsi
	movq	%rsi, -872(%rbp)
	movq	-872(%rbp), %rsi
	movl	(%rsi), %r8d
	movq	-896(%rbp), %rsi
	movl	%r8d, (%rsi)
	movq	%rcx, -880(%rbp)
	movq	-880(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-904(%rbp), %rcx
	movl	%r8d, (%rcx)
	addq	$4, %rdx
	movq	-944(%rbp), %rcx
	addq	$4, %rcx
	movq	%rdx, -856(%rbp)
	movq	%rcx, -864(%rbp)
	movq	-856(%rbp), %rcx
	movq	-864(%rbp), %rdx
	movq	%rcx, -832(%rbp)
	movq	%rdx, -840(%rbp)
	movq	-832(%rbp), %rcx
	movq	%rcx, -824(%rbp)
	movq	-824(%rbp), %rcx
	movl	(%rcx), %r8d
	movl	%r8d, -844(%rbp)
	movq	-840(%rbp), %rcx
	movq	%rcx, -808(%rbp)
	movq	-808(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-832(%rbp), %rcx
	movl	%r8d, (%rcx)
	movq	%rax, -816(%rbp)
	movq	-816(%rbp), %rax
	movl	(%rax), %r8d
	movq	-840(%rbp), %rax
	movl	%r8d, (%rax)
	movl	$1, -1644(%rbp)
	movl	-1644(%rbp), %r8d
	movl	%r8d, -1604(%rbp)
	jmp	LBB3_11
LBB3_8:
	leaq	-1728(%rbp), %rax
	leaq	-1720(%rbp), %rcx
	leaq	-1004(%rbp), %rdx
	leaq	-1068(%rbp), %rsi
	movq	-1616(%rbp), %rdi
	movq	-1624(%rbp), %r8
	movq	%rdi, -1112(%rbp)
	movq	%r8, -1120(%rbp)
	movq	-1112(%rbp), %rdi
	movq	-1120(%rbp), %r8
	movq	%rdi, -1096(%rbp)
	movq	%r8, -1104(%rbp)
	movq	-1096(%rbp), %rdi
	movq	-1104(%rbp), %r8
	movq	%rdi, -1080(%rbp)
	movq	%r8, -1088(%rbp)
	movq	-1080(%rbp), %r8
	movq	-1088(%rbp), %r9
	movq	%r8, -1056(%rbp)
	movq	%r9, -1064(%rbp)
	movq	-1056(%rbp), %r8
	movq	%r8, -1048(%rbp)
	movq	-1048(%rbp), %r8
	movl	(%r8), %r10d
	movl	%r10d, -1068(%rbp)
	movq	-1064(%rbp), %r8
	movq	%r8, -1032(%rbp)
	movq	-1032(%rbp), %r8
	movl	(%r8), %r10d
	movq	-1056(%rbp), %r8
	movl	%r10d, (%r8)
	movq	%rsi, -1040(%rbp)
	movq	-1040(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-1064(%rbp), %rsi
	movl	%r10d, (%rsi)
	addq	$4, %rdi
	movq	-1104(%rbp), %rsi
	addq	$4, %rsi
	movq	%rdi, -1016(%rbp)
	movq	%rsi, -1024(%rbp)
	movq	-1016(%rbp), %rsi
	movq	-1024(%rbp), %rdi
	movq	%rsi, -992(%rbp)
	movq	%rdi, -1000(%rbp)
	movq	-992(%rbp), %rsi
	movq	%rsi, -984(%rbp)
	movq	-984(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, -1004(%rbp)
	movq	-1000(%rbp), %rsi
	movq	%rsi, -968(%rbp)
	movq	-968(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-992(%rbp), %rsi
	movl	%r10d, (%rsi)
	movq	%rdx, -976(%rbp)
	movq	-976(%rbp), %rdx
	movl	(%rdx), %r10d
	movq	-1000(%rbp), %rdx
	movl	%r10d, (%rdx)
	movl	$1, -1644(%rbp)
	movq	-1640(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-1632(%rbp), %rsi
	movq	%rcx, -1192(%rbp)
	movq	%rsi, -1200(%rbp)
	movq	-1192(%rbp), %rcx
	movq	-1200(%rbp), %rsi
	movq	%rcx, -1176(%rbp)
	movq	%rsi, -1184(%rbp)
	movq	-1176(%rbp), %rcx
	movq	-1184(%rbp), %rsi
	movq	%rsi, -1168(%rbp)
	movq	-1168(%rbp), %rsi
	movq	%rsi, -1160(%rbp)
	movq	-1160(%rbp), %rsi
	movq	%rsi, -1128(%rbp)
	movq	-1128(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, (%rcx)
	movq	-1184(%rbp), %rsi
	movq	%rsi, -1144(%rbp)
	movq	-1144(%rbp), %rsi
	movq	%rsi, -1136(%rbp)
	movq	-1136(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -1152(%rbp)
	movq	-1152(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, 4(%rcx)
	movq	-1624(%rbp), %rcx
	movq	%rax, -1272(%rbp)
	movq	%rcx, -1280(%rbp)
	movq	-1272(%rbp), %rax
	movq	-1280(%rbp), %rcx
	movq	%rax, -1256(%rbp)
	movq	%rcx, -1264(%rbp)
	movq	-1256(%rbp), %rax
	movq	-1264(%rbp), %rcx
	movq	%rcx, -1248(%rbp)
	movq	-1248(%rbp), %rcx
	movq	%rcx, -1240(%rbp)
	movq	-1240(%rbp), %rcx
	movq	%rcx, -1208(%rbp)
	movq	-1208(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, (%rax)
	movq	-1264(%rbp), %rcx
	movq	%rcx, -1224(%rbp)
	movq	-1224(%rbp), %rcx
	movq	%rcx, -1216(%rbp)
	movq	-1216(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -1232(%rbp)
	movq	-1232(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, 4(%rax)
	movq	-1720(%rbp), %rdi
	movq	-1728(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB3_9
	jmp	LBB3_10
LBB3_9:
	leaq	-1404(%rbp), %rax
	leaq	-1468(%rbp), %rcx
	movq	-1624(%rbp), %rdx
	movq	-1632(%rbp), %rsi
	movq	%rdx, -1512(%rbp)
	movq	%rsi, -1520(%rbp)
	movq	-1512(%rbp), %rdx
	movq	-1520(%rbp), %rsi
	movq	%rdx, -1496(%rbp)
	movq	%rsi, -1504(%rbp)
	movq	-1496(%rbp), %rdx
	movq	-1504(%rbp), %rsi
	movq	%rdx, -1480(%rbp)
	movq	%rsi, -1488(%rbp)
	movq	-1480(%rbp), %rsi
	movq	-1488(%rbp), %rdi
	movq	%rsi, -1456(%rbp)
	movq	%rdi, -1464(%rbp)
	movq	-1456(%rbp), %rsi
	movq	%rsi, -1448(%rbp)
	movq	-1448(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, -1468(%rbp)
	movq	-1464(%rbp), %rsi
	movq	%rsi, -1432(%rbp)
	movq	-1432(%rbp), %rsi
	movl	(%rsi), %r8d
	movq	-1456(%rbp), %rsi
	movl	%r8d, (%rsi)
	movq	%rcx, -1440(%rbp)
	movq	-1440(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-1464(%rbp), %rcx
	movl	%r8d, (%rcx)
	addq	$4, %rdx
	movq	-1504(%rbp), %rcx
	addq	$4, %rcx
	movq	%rdx, -1416(%rbp)
	movq	%rcx, -1424(%rbp)
	movq	-1416(%rbp), %rcx
	movq	-1424(%rbp), %rdx
	movq	%rcx, -1392(%rbp)
	movq	%rdx, -1400(%rbp)
	movq	-1392(%rbp), %rcx
	movq	%rcx, -1384(%rbp)
	movq	-1384(%rbp), %rcx
	movl	(%rcx), %r8d
	movl	%r8d, -1404(%rbp)
	movq	-1400(%rbp), %rcx
	movq	%rcx, -1368(%rbp)
	movq	-1368(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-1392(%rbp), %rcx
	movl	%r8d, (%rcx)
	movq	%rax, -1376(%rbp)
	movq	-1376(%rbp), %rax
	movl	(%rax), %r8d
	movq	-1400(%rbp), %rax
	movl	%r8d, (%rax)
	movl	$2, -1644(%rbp)
LBB3_10:
	movl	-1644(%rbp), %eax
	movl	%eax, -1604(%rbp)
LBB3_11:
	movl	-1604(%rbp), %eax
	addq	$1728, %rsp             ## imm = 0x6C0
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__17__sort4IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_T_
	.weak_definition	__ZNSt3__17__sort4IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_T_
	.p2align	4, 0x90
__ZNSt3__17__sort4IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_T_: ## @_ZNSt3__17__sort4IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_T_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp12:
	.cfi_def_cfa_offset 16
Ltmp13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp14:
	.cfi_def_cfa_register %rbp
	subq	$1072, %rsp             ## imm = 0x430
	movq	%rdi, -968(%rbp)
	movq	%rsi, -976(%rbp)
	movq	%rdx, -984(%rbp)
	movq	%rcx, -992(%rbp)
	movq	%r8, -1000(%rbp)
	movq	-968(%rbp), %rdi
	movq	-976(%rbp), %rsi
	movq	-984(%rbp), %rdx
	movq	-1000(%rbp), %rcx
	callq	__ZNSt3__17__sort3IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_T_
	leaq	-1024(%rbp), %rcx
	leaq	-1016(%rbp), %rdx
	movl	%eax, -1004(%rbp)
	movq	-1000(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-992(%rbp), %rdi
	movq	%rdx, -952(%rbp)
	movq	%rdi, -960(%rbp)
	movq	-952(%rbp), %rdx
	movq	-960(%rbp), %rdi
	movq	%rdx, -936(%rbp)
	movq	%rdi, -944(%rbp)
	movq	-936(%rbp), %rdx
	movq	-944(%rbp), %rdi
	movq	%rdi, -928(%rbp)
	movq	-928(%rbp), %rdi
	movq	%rdi, -920(%rbp)
	movq	-920(%rbp), %rdi
	movq	%rdi, -888(%rbp)
	movq	-888(%rbp), %rdi
	movl	(%rdi), %eax
	movl	%eax, (%rdx)
	movq	-944(%rbp), %rdi
	movq	%rdi, -904(%rbp)
	movq	-904(%rbp), %rdi
	movq	%rdi, -896(%rbp)
	movq	-896(%rbp), %rdi
	addq	$4, %rdi
	movq	%rdi, -912(%rbp)
	movq	-912(%rbp), %rdi
	movl	(%rdi), %eax
	movl	%eax, 4(%rdx)
	movq	-984(%rbp), %rdx
	movq	%rcx, -712(%rbp)
	movq	%rdx, -720(%rbp)
	movq	-712(%rbp), %rcx
	movq	-720(%rbp), %rdx
	movq	%rcx, -696(%rbp)
	movq	%rdx, -704(%rbp)
	movq	-696(%rbp), %rcx
	movq	-704(%rbp), %rdx
	movq	%rdx, -688(%rbp)
	movq	-688(%rbp), %rdx
	movq	%rdx, -680(%rbp)
	movq	-680(%rbp), %rdx
	movq	%rdx, -648(%rbp)
	movq	-648(%rbp), %rdx
	movl	(%rdx), %eax
	movl	%eax, (%rcx)
	movq	-704(%rbp), %rdx
	movq	%rdx, -664(%rbp)
	movq	-664(%rbp), %rdx
	movq	%rdx, -656(%rbp)
	movq	-656(%rbp), %rdx
	addq	$4, %rdx
	movq	%rdx, -672(%rbp)
	movq	-672(%rbp), %rdx
	movl	(%rdx), %eax
	movl	%eax, 4(%rcx)
	movq	-1016(%rbp), %rdi
	movq	-1024(%rbp), %rcx
	movq	%rsi, -1064(%rbp)       ## 8-byte Spill
	movq	%rcx, %rsi
	movq	-1064(%rbp), %rcx       ## 8-byte Reload
	callq	*%rcx
	testb	$1, %al
	jne	LBB4_1
	jmp	LBB4_6
LBB4_1:
	leaq	-1040(%rbp), %rax
	leaq	-1032(%rbp), %rcx
	leaq	-204(%rbp), %rdx
	leaq	-268(%rbp), %rsi
	movq	-984(%rbp), %rdi
	movq	-992(%rbp), %r8
	movq	%rdi, -312(%rbp)
	movq	%r8, -320(%rbp)
	movq	-312(%rbp), %rdi
	movq	-320(%rbp), %r8
	movq	%rdi, -296(%rbp)
	movq	%r8, -304(%rbp)
	movq	-296(%rbp), %rdi
	movq	-304(%rbp), %r8
	movq	%rdi, -280(%rbp)
	movq	%r8, -288(%rbp)
	movq	-280(%rbp), %r8
	movq	-288(%rbp), %r9
	movq	%r8, -256(%rbp)
	movq	%r9, -264(%rbp)
	movq	-256(%rbp), %r8
	movq	%r8, -248(%rbp)
	movq	-248(%rbp), %r8
	movl	(%r8), %r10d
	movl	%r10d, -268(%rbp)
	movq	-264(%rbp), %r8
	movq	%r8, -232(%rbp)
	movq	-232(%rbp), %r8
	movl	(%r8), %r10d
	movq	-256(%rbp), %r8
	movl	%r10d, (%r8)
	movq	%rsi, -240(%rbp)
	movq	-240(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-264(%rbp), %rsi
	movl	%r10d, (%rsi)
	addq	$4, %rdi
	movq	-304(%rbp), %rsi
	addq	$4, %rsi
	movq	%rdi, -216(%rbp)
	movq	%rsi, -224(%rbp)
	movq	-216(%rbp), %rsi
	movq	-224(%rbp), %rdi
	movq	%rsi, -192(%rbp)
	movq	%rdi, -200(%rbp)
	movq	-192(%rbp), %rsi
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, -204(%rbp)
	movq	-200(%rbp), %rsi
	movq	%rsi, -168(%rbp)
	movq	-168(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-192(%rbp), %rsi
	movl	%r10d, (%rsi)
	movq	%rdx, -176(%rbp)
	movq	-176(%rbp), %rdx
	movl	(%rdx), %r10d
	movq	-200(%rbp), %rdx
	movl	%r10d, (%rdx)
	movl	-1004(%rbp), %r10d
	addl	$1, %r10d
	movl	%r10d, -1004(%rbp)
	movq	-1000(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-984(%rbp), %rsi
	movq	%rcx, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	-72(%rbp), %rcx
	movq	-80(%rbp), %rsi
	movq	%rcx, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	-56(%rbp), %rcx
	movq	-64(%rbp), %rsi
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rsi
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rsi
	movq	%rsi, -8(%rbp)
	movq	-8(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, (%rcx)
	movq	-64(%rbp), %rsi
	movq	%rsi, -24(%rbp)
	movq	-24(%rbp), %rsi
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, 4(%rcx)
	movq	-976(%rbp), %rcx
	movq	%rax, -152(%rbp)
	movq	%rcx, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	-160(%rbp), %rcx
	movq	%rax, -136(%rbp)
	movq	%rcx, -144(%rbp)
	movq	-136(%rbp), %rax
	movq	-144(%rbp), %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	%rcx, -88(%rbp)
	movq	-88(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, (%rax)
	movq	-144(%rbp), %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -112(%rbp)
	movq	-112(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, 4(%rax)
	movq	-1032(%rbp), %rdi
	movq	-1040(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB4_2
	jmp	LBB4_5
LBB4_2:
	leaq	-1056(%rbp), %rax
	leaq	-1048(%rbp), %rcx
	leaq	-364(%rbp), %rdx
	leaq	-428(%rbp), %rsi
	movq	-976(%rbp), %rdi
	movq	-984(%rbp), %r8
	movq	%rdi, -472(%rbp)
	movq	%r8, -480(%rbp)
	movq	-472(%rbp), %rdi
	movq	-480(%rbp), %r8
	movq	%rdi, -456(%rbp)
	movq	%r8, -464(%rbp)
	movq	-456(%rbp), %rdi
	movq	-464(%rbp), %r8
	movq	%rdi, -440(%rbp)
	movq	%r8, -448(%rbp)
	movq	-440(%rbp), %r8
	movq	-448(%rbp), %r9
	movq	%r8, -416(%rbp)
	movq	%r9, -424(%rbp)
	movq	-416(%rbp), %r8
	movq	%r8, -408(%rbp)
	movq	-408(%rbp), %r8
	movl	(%r8), %r10d
	movl	%r10d, -428(%rbp)
	movq	-424(%rbp), %r8
	movq	%r8, -392(%rbp)
	movq	-392(%rbp), %r8
	movl	(%r8), %r10d
	movq	-416(%rbp), %r8
	movl	%r10d, (%r8)
	movq	%rsi, -400(%rbp)
	movq	-400(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-424(%rbp), %rsi
	movl	%r10d, (%rsi)
	addq	$4, %rdi
	movq	-464(%rbp), %rsi
	addq	$4, %rsi
	movq	%rdi, -376(%rbp)
	movq	%rsi, -384(%rbp)
	movq	-376(%rbp), %rsi
	movq	-384(%rbp), %rdi
	movq	%rsi, -352(%rbp)
	movq	%rdi, -360(%rbp)
	movq	-352(%rbp), %rsi
	movq	%rsi, -344(%rbp)
	movq	-344(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, -364(%rbp)
	movq	-360(%rbp), %rsi
	movq	%rsi, -328(%rbp)
	movq	-328(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-352(%rbp), %rsi
	movl	%r10d, (%rsi)
	movq	%rdx, -336(%rbp)
	movq	-336(%rbp), %rdx
	movl	(%rdx), %r10d
	movq	-360(%rbp), %rdx
	movl	%r10d, (%rdx)
	movl	-1004(%rbp), %r10d
	addl	$1, %r10d
	movl	%r10d, -1004(%rbp)
	movq	-1000(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-976(%rbp), %rsi
	movq	%rcx, -552(%rbp)
	movq	%rsi, -560(%rbp)
	movq	-552(%rbp), %rcx
	movq	-560(%rbp), %rsi
	movq	%rcx, -536(%rbp)
	movq	%rsi, -544(%rbp)
	movq	-536(%rbp), %rcx
	movq	-544(%rbp), %rsi
	movq	%rsi, -528(%rbp)
	movq	-528(%rbp), %rsi
	movq	%rsi, -520(%rbp)
	movq	-520(%rbp), %rsi
	movq	%rsi, -488(%rbp)
	movq	-488(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, (%rcx)
	movq	-544(%rbp), %rsi
	movq	%rsi, -504(%rbp)
	movq	-504(%rbp), %rsi
	movq	%rsi, -496(%rbp)
	movq	-496(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -512(%rbp)
	movq	-512(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, 4(%rcx)
	movq	-968(%rbp), %rcx
	movq	%rax, -632(%rbp)
	movq	%rcx, -640(%rbp)
	movq	-632(%rbp), %rax
	movq	-640(%rbp), %rcx
	movq	%rax, -616(%rbp)
	movq	%rcx, -624(%rbp)
	movq	-616(%rbp), %rax
	movq	-624(%rbp), %rcx
	movq	%rcx, -608(%rbp)
	movq	-608(%rbp), %rcx
	movq	%rcx, -600(%rbp)
	movq	-600(%rbp), %rcx
	movq	%rcx, -568(%rbp)
	movq	-568(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, (%rax)
	movq	-624(%rbp), %rcx
	movq	%rcx, -584(%rbp)
	movq	-584(%rbp), %rcx
	movq	%rcx, -576(%rbp)
	movq	-576(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -592(%rbp)
	movq	-592(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, 4(%rax)
	movq	-1048(%rbp), %rdi
	movq	-1056(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB4_3
	jmp	LBB4_4
LBB4_3:
	leaq	-764(%rbp), %rax
	leaq	-828(%rbp), %rcx
	movq	-968(%rbp), %rdx
	movq	-976(%rbp), %rsi
	movq	%rdx, -872(%rbp)
	movq	%rsi, -880(%rbp)
	movq	-872(%rbp), %rdx
	movq	-880(%rbp), %rsi
	movq	%rdx, -856(%rbp)
	movq	%rsi, -864(%rbp)
	movq	-856(%rbp), %rdx
	movq	-864(%rbp), %rsi
	movq	%rdx, -840(%rbp)
	movq	%rsi, -848(%rbp)
	movq	-840(%rbp), %rsi
	movq	-848(%rbp), %rdi
	movq	%rsi, -816(%rbp)
	movq	%rdi, -824(%rbp)
	movq	-816(%rbp), %rsi
	movq	%rsi, -808(%rbp)
	movq	-808(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, -828(%rbp)
	movq	-824(%rbp), %rsi
	movq	%rsi, -792(%rbp)
	movq	-792(%rbp), %rsi
	movl	(%rsi), %r8d
	movq	-816(%rbp), %rsi
	movl	%r8d, (%rsi)
	movq	%rcx, -800(%rbp)
	movq	-800(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-824(%rbp), %rcx
	movl	%r8d, (%rcx)
	addq	$4, %rdx
	movq	-864(%rbp), %rcx
	addq	$4, %rcx
	movq	%rdx, -776(%rbp)
	movq	%rcx, -784(%rbp)
	movq	-776(%rbp), %rcx
	movq	-784(%rbp), %rdx
	movq	%rcx, -752(%rbp)
	movq	%rdx, -760(%rbp)
	movq	-752(%rbp), %rcx
	movq	%rcx, -744(%rbp)
	movq	-744(%rbp), %rcx
	movl	(%rcx), %r8d
	movl	%r8d, -764(%rbp)
	movq	-760(%rbp), %rcx
	movq	%rcx, -728(%rbp)
	movq	-728(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-752(%rbp), %rcx
	movl	%r8d, (%rcx)
	movq	%rax, -736(%rbp)
	movq	-736(%rbp), %rax
	movl	(%rax), %r8d
	movq	-760(%rbp), %rax
	movl	%r8d, (%rax)
	movl	-1004(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -1004(%rbp)
LBB4_4:
	jmp	LBB4_5
LBB4_5:
	jmp	LBB4_6
LBB4_6:
	movl	-1004(%rbp), %eax
	addq	$1072, %rsp             ## imm = 0x430
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__17__sort5IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_S7_T_
	.weak_definition	__ZNSt3__17__sort5IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_S7_T_
	.p2align	4, 0x90
__ZNSt3__17__sort5IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_S7_T_: ## @_ZNSt3__17__sort5IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_S7_T_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp15:
	.cfi_def_cfa_offset 16
Ltmp16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp17:
	.cfi_def_cfa_register %rbp
	subq	$1408, %rsp             ## imm = 0x580
	movq	%rdi, -1288(%rbp)
	movq	%rsi, -1296(%rbp)
	movq	%rdx, -1304(%rbp)
	movq	%rcx, -1312(%rbp)
	movq	%r8, -1320(%rbp)
	movq	%r9, -1328(%rbp)
	movq	-1288(%rbp), %rdi
	movq	-1296(%rbp), %rsi
	movq	-1304(%rbp), %rdx
	movq	-1312(%rbp), %rcx
	movq	-1328(%rbp), %r8
	callq	__ZNSt3__17__sort4IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_T_
	leaq	-1352(%rbp), %rcx
	leaq	-1344(%rbp), %rdx
	movl	%eax, -1332(%rbp)
	movq	-1328(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-1320(%rbp), %rdi
	movq	%rdx, -1272(%rbp)
	movq	%rdi, -1280(%rbp)
	movq	-1272(%rbp), %rdx
	movq	-1280(%rbp), %rdi
	movq	%rdx, -1256(%rbp)
	movq	%rdi, -1264(%rbp)
	movq	-1256(%rbp), %rdx
	movq	-1264(%rbp), %rdi
	movq	%rdi, -1248(%rbp)
	movq	-1248(%rbp), %rdi
	movq	%rdi, -1240(%rbp)
	movq	-1240(%rbp), %rdi
	movq	%rdi, -1208(%rbp)
	movq	-1208(%rbp), %rdi
	movl	(%rdi), %eax
	movl	%eax, (%rdx)
	movq	-1264(%rbp), %rdi
	movq	%rdi, -1224(%rbp)
	movq	-1224(%rbp), %rdi
	movq	%rdi, -1216(%rbp)
	movq	-1216(%rbp), %rdi
	addq	$4, %rdi
	movq	%rdi, -1232(%rbp)
	movq	-1232(%rbp), %rdi
	movl	(%rdi), %eax
	movl	%eax, 4(%rdx)
	movq	-1312(%rbp), %rdx
	movq	%rcx, -1032(%rbp)
	movq	%rdx, -1040(%rbp)
	movq	-1032(%rbp), %rcx
	movq	-1040(%rbp), %rdx
	movq	%rcx, -1016(%rbp)
	movq	%rdx, -1024(%rbp)
	movq	-1016(%rbp), %rcx
	movq	-1024(%rbp), %rdx
	movq	%rdx, -1008(%rbp)
	movq	-1008(%rbp), %rdx
	movq	%rdx, -1000(%rbp)
	movq	-1000(%rbp), %rdx
	movq	%rdx, -968(%rbp)
	movq	-968(%rbp), %rdx
	movl	(%rdx), %eax
	movl	%eax, (%rcx)
	movq	-1024(%rbp), %rdx
	movq	%rdx, -984(%rbp)
	movq	-984(%rbp), %rdx
	movq	%rdx, -976(%rbp)
	movq	-976(%rbp), %rdx
	addq	$4, %rdx
	movq	%rdx, -992(%rbp)
	movq	-992(%rbp), %rdx
	movl	(%rdx), %eax
	movl	%eax, 4(%rcx)
	movq	-1344(%rbp), %rdi
	movq	-1352(%rbp), %rcx
	movq	%rsi, -1408(%rbp)       ## 8-byte Spill
	movq	%rcx, %rsi
	movq	-1408(%rbp), %rcx       ## 8-byte Reload
	callq	*%rcx
	testb	$1, %al
	jne	LBB5_1
	jmp	LBB5_8
LBB5_1:
	leaq	-1368(%rbp), %rax
	leaq	-1360(%rbp), %rcx
	leaq	-524(%rbp), %rdx
	leaq	-588(%rbp), %rsi
	movq	-1312(%rbp), %rdi
	movq	-1320(%rbp), %r8
	movq	%rdi, -632(%rbp)
	movq	%r8, -640(%rbp)
	movq	-632(%rbp), %rdi
	movq	-640(%rbp), %r8
	movq	%rdi, -616(%rbp)
	movq	%r8, -624(%rbp)
	movq	-616(%rbp), %rdi
	movq	-624(%rbp), %r8
	movq	%rdi, -600(%rbp)
	movq	%r8, -608(%rbp)
	movq	-600(%rbp), %r8
	movq	-608(%rbp), %r9
	movq	%r8, -576(%rbp)
	movq	%r9, -584(%rbp)
	movq	-576(%rbp), %r8
	movq	%r8, -568(%rbp)
	movq	-568(%rbp), %r8
	movl	(%r8), %r10d
	movl	%r10d, -588(%rbp)
	movq	-584(%rbp), %r8
	movq	%r8, -552(%rbp)
	movq	-552(%rbp), %r8
	movl	(%r8), %r10d
	movq	-576(%rbp), %r8
	movl	%r10d, (%r8)
	movq	%rsi, -560(%rbp)
	movq	-560(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-584(%rbp), %rsi
	movl	%r10d, (%rsi)
	addq	$4, %rdi
	movq	-624(%rbp), %rsi
	addq	$4, %rsi
	movq	%rdi, -536(%rbp)
	movq	%rsi, -544(%rbp)
	movq	-536(%rbp), %rsi
	movq	-544(%rbp), %rdi
	movq	%rsi, -512(%rbp)
	movq	%rdi, -520(%rbp)
	movq	-512(%rbp), %rsi
	movq	%rsi, -504(%rbp)
	movq	-504(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, -524(%rbp)
	movq	-520(%rbp), %rsi
	movq	%rsi, -488(%rbp)
	movq	-488(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-512(%rbp), %rsi
	movl	%r10d, (%rsi)
	movq	%rdx, -496(%rbp)
	movq	-496(%rbp), %rdx
	movl	(%rdx), %r10d
	movq	-520(%rbp), %rdx
	movl	%r10d, (%rdx)
	movl	-1332(%rbp), %r10d
	addl	$1, %r10d
	movl	%r10d, -1332(%rbp)
	movq	-1328(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-1312(%rbp), %rsi
	movq	%rcx, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	-152(%rbp), %rcx
	movq	-160(%rbp), %rsi
	movq	%rcx, -136(%rbp)
	movq	%rsi, -144(%rbp)
	movq	-136(%rbp), %rcx
	movq	-144(%rbp), %rsi
	movq	%rsi, -128(%rbp)
	movq	-128(%rbp), %rsi
	movq	%rsi, -120(%rbp)
	movq	-120(%rbp), %rsi
	movq	%rsi, -88(%rbp)
	movq	-88(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, (%rcx)
	movq	-144(%rbp), %rsi
	movq	%rsi, -104(%rbp)
	movq	-104(%rbp), %rsi
	movq	%rsi, -96(%rbp)
	movq	-96(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -112(%rbp)
	movq	-112(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, 4(%rcx)
	movq	-1304(%rbp), %rcx
	movq	%rax, -72(%rbp)
	movq	%rcx, -80(%rbp)
	movq	-72(%rbp), %rax
	movq	-80(%rbp), %rcx
	movq	%rax, -56(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, (%rax)
	movq	-64(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, 4(%rax)
	movq	-1360(%rbp), %rdi
	movq	-1368(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB5_2
	jmp	LBB5_7
LBB5_2:
	leaq	-1384(%rbp), %rax
	leaq	-1376(%rbp), %rcx
	leaq	-204(%rbp), %rdx
	leaq	-268(%rbp), %rsi
	movq	-1304(%rbp), %rdi
	movq	-1312(%rbp), %r8
	movq	%rdi, -312(%rbp)
	movq	%r8, -320(%rbp)
	movq	-312(%rbp), %rdi
	movq	-320(%rbp), %r8
	movq	%rdi, -296(%rbp)
	movq	%r8, -304(%rbp)
	movq	-296(%rbp), %rdi
	movq	-304(%rbp), %r8
	movq	%rdi, -280(%rbp)
	movq	%r8, -288(%rbp)
	movq	-280(%rbp), %r8
	movq	-288(%rbp), %r9
	movq	%r8, -256(%rbp)
	movq	%r9, -264(%rbp)
	movq	-256(%rbp), %r8
	movq	%r8, -248(%rbp)
	movq	-248(%rbp), %r8
	movl	(%r8), %r10d
	movl	%r10d, -268(%rbp)
	movq	-264(%rbp), %r8
	movq	%r8, -232(%rbp)
	movq	-232(%rbp), %r8
	movl	(%r8), %r10d
	movq	-256(%rbp), %r8
	movl	%r10d, (%r8)
	movq	%rsi, -240(%rbp)
	movq	-240(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-264(%rbp), %rsi
	movl	%r10d, (%rsi)
	addq	$4, %rdi
	movq	-304(%rbp), %rsi
	addq	$4, %rsi
	movq	%rdi, -216(%rbp)
	movq	%rsi, -224(%rbp)
	movq	-216(%rbp), %rsi
	movq	-224(%rbp), %rdi
	movq	%rsi, -192(%rbp)
	movq	%rdi, -200(%rbp)
	movq	-192(%rbp), %rsi
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, -204(%rbp)
	movq	-200(%rbp), %rsi
	movq	%rsi, -168(%rbp)
	movq	-168(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-192(%rbp), %rsi
	movl	%r10d, (%rsi)
	movq	%rdx, -176(%rbp)
	movq	-176(%rbp), %rdx
	movl	(%rdx), %r10d
	movq	-200(%rbp), %rdx
	movl	%r10d, (%rdx)
	movl	-1332(%rbp), %r10d
	addl	$1, %r10d
	movl	%r10d, -1332(%rbp)
	movq	-1328(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-1304(%rbp), %rsi
	movq	%rcx, -392(%rbp)
	movq	%rsi, -400(%rbp)
	movq	-392(%rbp), %rcx
	movq	-400(%rbp), %rsi
	movq	%rcx, -376(%rbp)
	movq	%rsi, -384(%rbp)
	movq	-376(%rbp), %rcx
	movq	-384(%rbp), %rsi
	movq	%rsi, -368(%rbp)
	movq	-368(%rbp), %rsi
	movq	%rsi, -360(%rbp)
	movq	-360(%rbp), %rsi
	movq	%rsi, -328(%rbp)
	movq	-328(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, (%rcx)
	movq	-384(%rbp), %rsi
	movq	%rsi, -344(%rbp)
	movq	-344(%rbp), %rsi
	movq	%rsi, -336(%rbp)
	movq	-336(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -352(%rbp)
	movq	-352(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, 4(%rcx)
	movq	-1296(%rbp), %rcx
	movq	%rax, -472(%rbp)
	movq	%rcx, -480(%rbp)
	movq	-472(%rbp), %rax
	movq	-480(%rbp), %rcx
	movq	%rax, -456(%rbp)
	movq	%rcx, -464(%rbp)
	movq	-456(%rbp), %rax
	movq	-464(%rbp), %rcx
	movq	%rcx, -448(%rbp)
	movq	-448(%rbp), %rcx
	movq	%rcx, -440(%rbp)
	movq	-440(%rbp), %rcx
	movq	%rcx, -408(%rbp)
	movq	-408(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, (%rax)
	movq	-464(%rbp), %rcx
	movq	%rcx, -424(%rbp)
	movq	-424(%rbp), %rcx
	movq	%rcx, -416(%rbp)
	movq	-416(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -432(%rbp)
	movq	-432(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, 4(%rax)
	movq	-1376(%rbp), %rdi
	movq	-1384(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB5_3
	jmp	LBB5_6
LBB5_3:
	leaq	-1400(%rbp), %rax
	leaq	-1392(%rbp), %rcx
	leaq	-684(%rbp), %rdx
	leaq	-748(%rbp), %rsi
	movq	-1296(%rbp), %rdi
	movq	-1304(%rbp), %r8
	movq	%rdi, -792(%rbp)
	movq	%r8, -800(%rbp)
	movq	-792(%rbp), %rdi
	movq	-800(%rbp), %r8
	movq	%rdi, -776(%rbp)
	movq	%r8, -784(%rbp)
	movq	-776(%rbp), %rdi
	movq	-784(%rbp), %r8
	movq	%rdi, -760(%rbp)
	movq	%r8, -768(%rbp)
	movq	-760(%rbp), %r8
	movq	-768(%rbp), %r9
	movq	%r8, -736(%rbp)
	movq	%r9, -744(%rbp)
	movq	-736(%rbp), %r8
	movq	%r8, -728(%rbp)
	movq	-728(%rbp), %r8
	movl	(%r8), %r10d
	movl	%r10d, -748(%rbp)
	movq	-744(%rbp), %r8
	movq	%r8, -712(%rbp)
	movq	-712(%rbp), %r8
	movl	(%r8), %r10d
	movq	-736(%rbp), %r8
	movl	%r10d, (%r8)
	movq	%rsi, -720(%rbp)
	movq	-720(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-744(%rbp), %rsi
	movl	%r10d, (%rsi)
	addq	$4, %rdi
	movq	-784(%rbp), %rsi
	addq	$4, %rsi
	movq	%rdi, -696(%rbp)
	movq	%rsi, -704(%rbp)
	movq	-696(%rbp), %rsi
	movq	-704(%rbp), %rdi
	movq	%rsi, -672(%rbp)
	movq	%rdi, -680(%rbp)
	movq	-672(%rbp), %rsi
	movq	%rsi, -664(%rbp)
	movq	-664(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, -684(%rbp)
	movq	-680(%rbp), %rsi
	movq	%rsi, -648(%rbp)
	movq	-648(%rbp), %rsi
	movl	(%rsi), %r10d
	movq	-672(%rbp), %rsi
	movl	%r10d, (%rsi)
	movq	%rdx, -656(%rbp)
	movq	-656(%rbp), %rdx
	movl	(%rdx), %r10d
	movq	-680(%rbp), %rdx
	movl	%r10d, (%rdx)
	movl	-1332(%rbp), %r10d
	addl	$1, %r10d
	movl	%r10d, -1332(%rbp)
	movq	-1328(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-1296(%rbp), %rsi
	movq	%rcx, -872(%rbp)
	movq	%rsi, -880(%rbp)
	movq	-872(%rbp), %rcx
	movq	-880(%rbp), %rsi
	movq	%rcx, -856(%rbp)
	movq	%rsi, -864(%rbp)
	movq	-856(%rbp), %rcx
	movq	-864(%rbp), %rsi
	movq	%rsi, -848(%rbp)
	movq	-848(%rbp), %rsi
	movq	%rsi, -840(%rbp)
	movq	-840(%rbp), %rsi
	movq	%rsi, -808(%rbp)
	movq	-808(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, (%rcx)
	movq	-864(%rbp), %rsi
	movq	%rsi, -824(%rbp)
	movq	-824(%rbp), %rsi
	movq	%rsi, -816(%rbp)
	movq	-816(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -832(%rbp)
	movq	-832(%rbp), %rsi
	movl	(%rsi), %r10d
	movl	%r10d, 4(%rcx)
	movq	-1288(%rbp), %rcx
	movq	%rax, -952(%rbp)
	movq	%rcx, -960(%rbp)
	movq	-952(%rbp), %rax
	movq	-960(%rbp), %rcx
	movq	%rax, -936(%rbp)
	movq	%rcx, -944(%rbp)
	movq	-936(%rbp), %rax
	movq	-944(%rbp), %rcx
	movq	%rcx, -928(%rbp)
	movq	-928(%rbp), %rcx
	movq	%rcx, -920(%rbp)
	movq	-920(%rbp), %rcx
	movq	%rcx, -888(%rbp)
	movq	-888(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, (%rax)
	movq	-944(%rbp), %rcx
	movq	%rcx, -904(%rbp)
	movq	-904(%rbp), %rcx
	movq	%rcx, -896(%rbp)
	movq	-896(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -912(%rbp)
	movq	-912(%rbp), %rcx
	movl	(%rcx), %r10d
	movl	%r10d, 4(%rax)
	movq	-1392(%rbp), %rdi
	movq	-1400(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB5_4
	jmp	LBB5_5
LBB5_4:
	leaq	-1084(%rbp), %rax
	leaq	-1148(%rbp), %rcx
	movq	-1288(%rbp), %rdx
	movq	-1296(%rbp), %rsi
	movq	%rdx, -1192(%rbp)
	movq	%rsi, -1200(%rbp)
	movq	-1192(%rbp), %rdx
	movq	-1200(%rbp), %rsi
	movq	%rdx, -1176(%rbp)
	movq	%rsi, -1184(%rbp)
	movq	-1176(%rbp), %rdx
	movq	-1184(%rbp), %rsi
	movq	%rdx, -1160(%rbp)
	movq	%rsi, -1168(%rbp)
	movq	-1160(%rbp), %rsi
	movq	-1168(%rbp), %rdi
	movq	%rsi, -1136(%rbp)
	movq	%rdi, -1144(%rbp)
	movq	-1136(%rbp), %rsi
	movq	%rsi, -1128(%rbp)
	movq	-1128(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, -1148(%rbp)
	movq	-1144(%rbp), %rsi
	movq	%rsi, -1112(%rbp)
	movq	-1112(%rbp), %rsi
	movl	(%rsi), %r8d
	movq	-1136(%rbp), %rsi
	movl	%r8d, (%rsi)
	movq	%rcx, -1120(%rbp)
	movq	-1120(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-1144(%rbp), %rcx
	movl	%r8d, (%rcx)
	addq	$4, %rdx
	movq	-1184(%rbp), %rcx
	addq	$4, %rcx
	movq	%rdx, -1096(%rbp)
	movq	%rcx, -1104(%rbp)
	movq	-1096(%rbp), %rcx
	movq	-1104(%rbp), %rdx
	movq	%rcx, -1072(%rbp)
	movq	%rdx, -1080(%rbp)
	movq	-1072(%rbp), %rcx
	movq	%rcx, -1064(%rbp)
	movq	-1064(%rbp), %rcx
	movl	(%rcx), %r8d
	movl	%r8d, -1084(%rbp)
	movq	-1080(%rbp), %rcx
	movq	%rcx, -1048(%rbp)
	movq	-1048(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-1072(%rbp), %rcx
	movl	%r8d, (%rcx)
	movq	%rax, -1056(%rbp)
	movq	-1056(%rbp), %rax
	movl	(%rax), %r8d
	movq	-1080(%rbp), %rax
	movl	%r8d, (%rax)
	movl	-1332(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -1332(%rbp)
LBB5_5:
	jmp	LBB5_6
LBB5_6:
	jmp	LBB5_7
LBB5_7:
	jmp	LBB5_8
LBB5_8:
	movl	-1332(%rbp), %eax
	addq	$1408, %rsp             ## imm = 0x580
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__118__insertion_sort_3IRPFbNS_4pairIiiEES2_EPS2_EEvT0_S7_T_
	.weak_definition	__ZNSt3__118__insertion_sort_3IRPFbNS_4pairIiiEES2_EPS2_EEvT0_S7_T_
	.p2align	4, 0x90
__ZNSt3__118__insertion_sort_3IRPFbNS_4pairIiiEES2_EPS2_EEvT0_S7_T_: ## @_ZNSt3__118__insertion_sort_3IRPFbNS_4pairIiiEES2_EPS2_EEvT0_S7_T_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp18:
	.cfi_def_cfa_offset 16
Ltmp19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp20:
	.cfi_def_cfa_register %rbp
	subq	$528, %rsp              ## imm = 0x210
	movq	%rdi, -416(%rbp)
	movq	%rsi, -424(%rbp)
	movq	%rdx, -432(%rbp)
	movq	-416(%rbp), %rdx
	addq	$16, %rdx
	movq	%rdx, -440(%rbp)
	movq	-416(%rbp), %rdi
	movq	-416(%rbp), %rdx
	addq	$8, %rdx
	movq	-440(%rbp), %rsi
	movq	-432(%rbp), %rcx
	movq	%rsi, -504(%rbp)        ## 8-byte Spill
	movq	%rdx, %rsi
	movq	-504(%rbp), %rdx        ## 8-byte Reload
	callq	__ZNSt3__17__sort3IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_T_
	movq	-440(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -448(%rbp)
	movl	%eax, -508(%rbp)        ## 4-byte Spill
LBB6_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB6_4 Depth 2
	movq	-448(%rbp), %rax
	cmpq	-424(%rbp), %rax
	je	LBB6_11
## BB#2:                                ##   in Loop: Header=BB6_1 Depth=1
	leaq	-464(%rbp), %rax
	leaq	-456(%rbp), %rcx
	movq	-432(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-448(%rbp), %rsi
	movq	%rcx, -400(%rbp)
	movq	%rsi, -408(%rbp)
	movq	-400(%rbp), %rcx
	movq	-408(%rbp), %rsi
	movq	%rcx, -384(%rbp)
	movq	%rsi, -392(%rbp)
	movq	-384(%rbp), %rcx
	movq	-392(%rbp), %rsi
	movq	%rsi, -376(%rbp)
	movq	-376(%rbp), %rsi
	movq	%rsi, -368(%rbp)
	movq	-368(%rbp), %rsi
	movq	%rsi, -336(%rbp)
	movq	-336(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-392(%rbp), %rsi
	movq	%rsi, -352(%rbp)
	movq	-352(%rbp), %rsi
	movq	%rsi, -344(%rbp)
	movq	-344(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -360(%rbp)
	movq	-360(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-440(%rbp), %rcx
	movq	%rax, -280(%rbp)
	movq	%rcx, -288(%rbp)
	movq	-280(%rbp), %rax
	movq	-288(%rbp), %rcx
	movq	%rax, -264(%rbp)
	movq	%rcx, -272(%rbp)
	movq	-264(%rbp), %rax
	movq	-272(%rbp), %rcx
	movq	%rcx, -256(%rbp)
	movq	-256(%rbp), %rcx
	movq	%rcx, -248(%rbp)
	movq	-248(%rbp), %rcx
	movq	%rcx, -216(%rbp)
	movq	-216(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-272(%rbp), %rcx
	movq	%rcx, -232(%rbp)
	movq	-232(%rbp), %rcx
	movq	%rcx, -224(%rbp)
	movq	-224(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -240(%rbp)
	movq	-240(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-456(%rbp), %rdi
	movq	-464(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB6_3
	jmp	LBB6_9
LBB6_3:                                 ##   in Loop: Header=BB6_1 Depth=1
	movq	-448(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -472(%rbp)
	movq	-440(%rbp), %rax
	movq	%rax, -480(%rbp)
	movq	-448(%rbp), %rax
	movq	%rax, -440(%rbp)
LBB6_4:                                 ##   Parent Loop BB6_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-440(%rbp), %rax
	movq	-480(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rax, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movl	(%rcx), %edx
	movl	%edx, (%rax)
	movq	-48(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movl	(%rcx), %edx
	movl	%edx, 4(%rax)
	movq	-480(%rbp), %rax
	movq	%rax, -440(%rbp)
## BB#5:                                ##   in Loop: Header=BB6_4 Depth=2
	xorl	%eax, %eax
	movb	%al, %cl
	movq	-440(%rbp), %rdx
	cmpq	-416(%rbp), %rdx
	movb	%cl, -509(%rbp)         ## 1-byte Spill
	je	LBB6_7
## BB#6:                                ##   in Loop: Header=BB6_4 Depth=2
	leaq	-496(%rbp), %rax
	leaq	-472(%rbp), %rcx
	leaq	-488(%rbp), %rdx
	movq	-432(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rdx, -120(%rbp)
	movq	%rcx, -128(%rbp)
	movq	-120(%rbp), %rcx
	movq	-128(%rbp), %rdx
	movq	%rcx, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	-104(%rbp), %rcx
	movq	-112(%rbp), %rdx
	movq	%rdx, -96(%rbp)
	movq	-96(%rbp), %rdx
	movq	%rdx, -88(%rbp)
	movq	-88(%rbp), %rdx
	movq	%rdx, -56(%rbp)
	movq	-56(%rbp), %rdx
	movl	(%rdx), %edi
	movl	%edi, (%rcx)
	movq	-112(%rbp), %rdx
	movq	%rdx, -72(%rbp)
	movq	-72(%rbp), %rdx
	movq	%rdx, -64(%rbp)
	movq	-64(%rbp), %rdx
	addq	$4, %rdx
	movq	%rdx, -80(%rbp)
	movq	-80(%rbp), %rdx
	movl	(%rdx), %edi
	movl	%edi, 4(%rcx)
	movq	-480(%rbp), %rcx
	addq	$-8, %rcx
	movq	%rcx, -480(%rbp)
	movq	%rax, -200(%rbp)
	movq	%rcx, -208(%rbp)
	movq	-200(%rbp), %rax
	movq	-208(%rbp), %rcx
	movq	%rax, -184(%rbp)
	movq	%rcx, -192(%rbp)
	movq	-184(%rbp), %rax
	movq	-192(%rbp), %rcx
	movq	%rcx, -176(%rbp)
	movq	-176(%rbp), %rcx
	movq	%rcx, -168(%rbp)
	movq	-168(%rbp), %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-192(%rbp), %rcx
	movq	%rcx, -152(%rbp)
	movq	-152(%rbp), %rcx
	movq	%rcx, -144(%rbp)
	movq	-144(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -160(%rbp)
	movq	-160(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-488(%rbp), %rdi
	movq	-496(%rbp), %rax
	movq	%rsi, -520(%rbp)        ## 8-byte Spill
	movq	%rax, %rsi
	movq	-520(%rbp), %rax        ## 8-byte Reload
	callq	*%rax
	movb	%al, -509(%rbp)         ## 1-byte Spill
LBB6_7:                                 ##   in Loop: Header=BB6_4 Depth=2
	movb	-509(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB6_4
## BB#8:                                ##   in Loop: Header=BB6_1 Depth=1
	leaq	-472(%rbp), %rax
	movq	-440(%rbp), %rcx
	movq	%rax, -296(%rbp)
	movq	-296(%rbp), %rax
	movq	%rcx, -320(%rbp)
	movq	%rax, -328(%rbp)
	movq	-320(%rbp), %rax
	movq	-328(%rbp), %rcx
	movq	%rcx, -312(%rbp)
	movq	-312(%rbp), %rcx
	movl	(%rcx), %edx
	movl	%edx, (%rax)
	movq	-328(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -304(%rbp)
	movq	-304(%rbp), %rcx
	movl	(%rcx), %edx
	movl	%edx, 4(%rax)
LBB6_9:                                 ##   in Loop: Header=BB6_1 Depth=1
	movq	-448(%rbp), %rax
	movq	%rax, -440(%rbp)
## BB#10:                               ##   in Loop: Header=BB6_1 Depth=1
	movq	-448(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -448(%rbp)
	jmp	LBB6_1
LBB6_11:
	addq	$528, %rsp              ## imm = 0x210
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__127__insertion_sort_incompleteIRPFbNS_4pairIiiEES2_EPS2_EEbT0_S7_T_
	.weak_definition	__ZNSt3__127__insertion_sort_incompleteIRPFbNS_4pairIiiEES2_EPS2_EEbT0_S7_T_
	.p2align	4, 0x90
__ZNSt3__127__insertion_sort_incompleteIRPFbNS_4pairIiiEES2_EPS2_EEbT0_S7_T_: ## @_ZNSt3__127__insertion_sort_incompleteIRPFbNS_4pairIiiEES2_EPS2_EEbT0_S7_T_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp21:
	.cfi_def_cfa_offset 16
Ltmp22:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp23:
	.cfi_def_cfa_register %rbp
	subq	$944, %rsp              ## imm = 0x3B0
	movq	%rdi, -744(%rbp)
	movq	%rsi, -752(%rbp)
	movq	%rdx, -760(%rbp)
	movq	-752(%rbp), %rdx
	movq	-744(%rbp), %rsi
	subq	%rsi, %rdx
	sarq	$3, %rdx
	movq	%rdx, %rsi
	subq	$5, %rsi
	movq	%rdx, -856(%rbp)        ## 8-byte Spill
	movq	%rsi, -864(%rbp)        ## 8-byte Spill
	ja	LBB7_8
## BB#23:
	leaq	LJTI7_0(%rip), %rax
	movq	-856(%rbp), %rcx        ## 8-byte Reload
	movslq	(%rax,%rcx,4), %rdx
	addq	%rax, %rdx
	jmpq	*%rdx
LBB7_1:
	movb	$1, -729(%rbp)
	jmp	LBB7_22
LBB7_2:
	leaq	-776(%rbp), %rax
	leaq	-768(%rbp), %rcx
	movq	-760(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-752(%rbp), %rsi
	addq	$-8, %rsi
	movq	%rsi, -752(%rbp)
	movq	%rcx, -720(%rbp)
	movq	%rsi, -728(%rbp)
	movq	-720(%rbp), %rcx
	movq	-728(%rbp), %rsi
	movq	%rcx, -704(%rbp)
	movq	%rsi, -712(%rbp)
	movq	-704(%rbp), %rcx
	movq	-712(%rbp), %rsi
	movq	%rsi, -696(%rbp)
	movq	-696(%rbp), %rsi
	movq	%rsi, -688(%rbp)
	movq	-688(%rbp), %rsi
	movq	%rsi, -656(%rbp)
	movq	-656(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-712(%rbp), %rsi
	movq	%rsi, -672(%rbp)
	movq	-672(%rbp), %rsi
	movq	%rsi, -664(%rbp)
	movq	-664(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -680(%rbp)
	movq	-680(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-744(%rbp), %rcx
	movq	%rax, -600(%rbp)
	movq	%rcx, -608(%rbp)
	movq	-600(%rbp), %rax
	movq	-608(%rbp), %rcx
	movq	%rax, -584(%rbp)
	movq	%rcx, -592(%rbp)
	movq	-584(%rbp), %rax
	movq	-592(%rbp), %rcx
	movq	%rcx, -576(%rbp)
	movq	-576(%rbp), %rcx
	movq	%rcx, -568(%rbp)
	movq	-568(%rbp), %rcx
	movq	%rcx, -536(%rbp)
	movq	-536(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-592(%rbp), %rcx
	movq	%rcx, -552(%rbp)
	movq	-552(%rbp), %rcx
	movq	%rcx, -544(%rbp)
	movq	-544(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -560(%rbp)
	movq	-560(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-768(%rbp), %rdi
	movq	-776(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB7_3
	jmp	LBB7_4
LBB7_3:
	leaq	-204(%rbp), %rax
	leaq	-268(%rbp), %rcx
	movq	-744(%rbp), %rdx
	movq	-752(%rbp), %rsi
	movq	%rdx, -312(%rbp)
	movq	%rsi, -320(%rbp)
	movq	-312(%rbp), %rdx
	movq	-320(%rbp), %rsi
	movq	%rdx, -296(%rbp)
	movq	%rsi, -304(%rbp)
	movq	-296(%rbp), %rdx
	movq	-304(%rbp), %rsi
	movq	%rdx, -280(%rbp)
	movq	%rsi, -288(%rbp)
	movq	-280(%rbp), %rsi
	movq	-288(%rbp), %rdi
	movq	%rsi, -256(%rbp)
	movq	%rdi, -264(%rbp)
	movq	-256(%rbp), %rsi
	movq	%rsi, -248(%rbp)
	movq	-248(%rbp), %rsi
	movl	(%rsi), %r8d
	movl	%r8d, -268(%rbp)
	movq	-264(%rbp), %rsi
	movq	%rsi, -232(%rbp)
	movq	-232(%rbp), %rsi
	movl	(%rsi), %r8d
	movq	-256(%rbp), %rsi
	movl	%r8d, (%rsi)
	movq	%rcx, -240(%rbp)
	movq	-240(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-264(%rbp), %rcx
	movl	%r8d, (%rcx)
	addq	$4, %rdx
	movq	-304(%rbp), %rcx
	addq	$4, %rcx
	movq	%rdx, -216(%rbp)
	movq	%rcx, -224(%rbp)
	movq	-216(%rbp), %rcx
	movq	-224(%rbp), %rdx
	movq	%rcx, -192(%rbp)
	movq	%rdx, -200(%rbp)
	movq	-192(%rbp), %rcx
	movq	%rcx, -184(%rbp)
	movq	-184(%rbp), %rcx
	movl	(%rcx), %r8d
	movl	%r8d, -204(%rbp)
	movq	-200(%rbp), %rcx
	movq	%rcx, -168(%rbp)
	movq	-168(%rbp), %rcx
	movl	(%rcx), %r8d
	movq	-192(%rbp), %rcx
	movl	%r8d, (%rcx)
	movq	%rax, -176(%rbp)
	movq	-176(%rbp), %rax
	movl	(%rax), %r8d
	movq	-200(%rbp), %rax
	movl	%r8d, (%rax)
LBB7_4:
	movb	$1, -729(%rbp)
	jmp	LBB7_22
LBB7_5:
	movq	-744(%rbp), %rdi
	movq	-744(%rbp), %rax
	addq	$8, %rax
	movq	-752(%rbp), %rcx
	addq	$-8, %rcx
	movq	%rcx, -752(%rbp)
	movq	-760(%rbp), %rdx
	movq	%rax, %rsi
	movq	%rdx, -872(%rbp)        ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-872(%rbp), %rcx        ## 8-byte Reload
	callq	__ZNSt3__17__sort3IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_T_
	movb	$1, -729(%rbp)
	movl	%eax, -876(%rbp)        ## 4-byte Spill
	jmp	LBB7_22
LBB7_6:
	movq	-744(%rbp), %rdi
	movq	-744(%rbp), %rax
	addq	$8, %rax
	movq	-744(%rbp), %rcx
	addq	$16, %rcx
	movq	-752(%rbp), %rdx
	addq	$-8, %rdx
	movq	%rdx, -752(%rbp)
	movq	-760(%rbp), %r8
	movq	%rax, %rsi
	movq	%rdx, -888(%rbp)        ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-888(%rbp), %rcx        ## 8-byte Reload
	callq	__ZNSt3__17__sort4IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_T_
	movb	$1, -729(%rbp)
	movl	%eax, -892(%rbp)        ## 4-byte Spill
	jmp	LBB7_22
LBB7_7:
	movq	-744(%rbp), %rdi
	movq	-744(%rbp), %rax
	addq	$8, %rax
	movq	-744(%rbp), %rcx
	addq	$16, %rcx
	movq	-744(%rbp), %rdx
	addq	$24, %rdx
	movq	-752(%rbp), %rsi
	addq	$-8, %rsi
	movq	%rsi, -752(%rbp)
	movq	-760(%rbp), %r9
	movq	%rsi, -904(%rbp)        ## 8-byte Spill
	movq	%rax, %rsi
	movq	%rdx, -912(%rbp)        ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-912(%rbp), %rcx        ## 8-byte Reload
	movq	-904(%rbp), %r8         ## 8-byte Reload
	callq	__ZNSt3__17__sort5IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_S7_S7_T_
	movb	$1, -729(%rbp)
	movl	%eax, -916(%rbp)        ## 4-byte Spill
	jmp	LBB7_22
LBB7_8:
	movq	-744(%rbp), %rax
	addq	$16, %rax
	movq	%rax, -784(%rbp)
	movq	-744(%rbp), %rdi
	movq	-744(%rbp), %rax
	addq	$8, %rax
	movq	-784(%rbp), %rdx
	movq	-760(%rbp), %rcx
	movq	%rax, %rsi
	callq	__ZNSt3__17__sort3IRPFbNS_4pairIiiEES2_EPS2_EEjT0_S7_S7_T_
	movl	$8, -788(%rbp)
	movl	$0, -792(%rbp)
	movq	-784(%rbp), %rcx
	addq	$8, %rcx
	movq	%rcx, -800(%rbp)
	movl	%eax, -920(%rbp)        ## 4-byte Spill
LBB7_9:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB7_12 Depth 2
	movq	-800(%rbp), %rax
	cmpq	-752(%rbp), %rax
	je	LBB7_21
## BB#10:                               ##   in Loop: Header=BB7_9 Depth=1
	leaq	-816(%rbp), %rax
	leaq	-808(%rbp), %rcx
	movq	-760(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-800(%rbp), %rsi
	movq	%rcx, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	-72(%rbp), %rcx
	movq	-80(%rbp), %rsi
	movq	%rcx, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	-56(%rbp), %rcx
	movq	-64(%rbp), %rsi
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rsi
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rsi
	movq	%rsi, -8(%rbp)
	movq	-8(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, (%rcx)
	movq	-64(%rbp), %rsi
	movq	%rsi, -24(%rbp)
	movq	-24(%rbp), %rsi
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rsi
	addq	$4, %rsi
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rsi
	movl	(%rsi), %edi
	movl	%edi, 4(%rcx)
	movq	-784(%rbp), %rcx
	movq	%rax, -152(%rbp)
	movq	%rcx, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	-160(%rbp), %rcx
	movq	%rax, -136(%rbp)
	movq	%rcx, -144(%rbp)
	movq	-136(%rbp), %rax
	movq	-144(%rbp), %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	%rcx, -88(%rbp)
	movq	-88(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-144(%rbp), %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -112(%rbp)
	movq	-112(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-808(%rbp), %rdi
	movq	-816(%rbp), %rsi
	callq	*%rdx
	testb	$1, %al
	jne	LBB7_11
	jmp	LBB7_19
LBB7_11:                                ##   in Loop: Header=BB7_9 Depth=1
	movq	-800(%rbp), %rax
	movq	%rax, -328(%rbp)
	movq	-328(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -824(%rbp)
	movq	-784(%rbp), %rax
	movq	%rax, -832(%rbp)
	movq	-800(%rbp), %rax
	movq	%rax, -784(%rbp)
LBB7_12:                                ##   Parent Loop BB7_9 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-784(%rbp), %rax
	movq	-832(%rbp), %rcx
	movq	%rcx, -336(%rbp)
	movq	-336(%rbp), %rcx
	movq	%rax, -360(%rbp)
	movq	%rcx, -368(%rbp)
	movq	-360(%rbp), %rax
	movq	-368(%rbp), %rcx
	movq	%rcx, -352(%rbp)
	movq	-352(%rbp), %rcx
	movl	(%rcx), %edx
	movl	%edx, (%rax)
	movq	-368(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -344(%rbp)
	movq	-344(%rbp), %rcx
	movl	(%rcx), %edx
	movl	%edx, 4(%rax)
	movq	-832(%rbp), %rax
	movq	%rax, -784(%rbp)
## BB#13:                               ##   in Loop: Header=BB7_12 Depth=2
	xorl	%eax, %eax
	movb	%al, %cl
	movq	-784(%rbp), %rdx
	cmpq	-744(%rbp), %rdx
	movb	%cl, -921(%rbp)         ## 1-byte Spill
	je	LBB7_15
## BB#14:                               ##   in Loop: Header=BB7_12 Depth=2
	leaq	-848(%rbp), %rax
	leaq	-824(%rbp), %rcx
	leaq	-840(%rbp), %rdx
	movq	-760(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rdx, -440(%rbp)
	movq	%rcx, -448(%rbp)
	movq	-440(%rbp), %rcx
	movq	-448(%rbp), %rdx
	movq	%rcx, -424(%rbp)
	movq	%rdx, -432(%rbp)
	movq	-424(%rbp), %rcx
	movq	-432(%rbp), %rdx
	movq	%rdx, -416(%rbp)
	movq	-416(%rbp), %rdx
	movq	%rdx, -408(%rbp)
	movq	-408(%rbp), %rdx
	movq	%rdx, -376(%rbp)
	movq	-376(%rbp), %rdx
	movl	(%rdx), %edi
	movl	%edi, (%rcx)
	movq	-432(%rbp), %rdx
	movq	%rdx, -392(%rbp)
	movq	-392(%rbp), %rdx
	movq	%rdx, -384(%rbp)
	movq	-384(%rbp), %rdx
	addq	$4, %rdx
	movq	%rdx, -400(%rbp)
	movq	-400(%rbp), %rdx
	movl	(%rdx), %edi
	movl	%edi, 4(%rcx)
	movq	-832(%rbp), %rcx
	addq	$-8, %rcx
	movq	%rcx, -832(%rbp)
	movq	%rax, -520(%rbp)
	movq	%rcx, -528(%rbp)
	movq	-520(%rbp), %rax
	movq	-528(%rbp), %rcx
	movq	%rax, -504(%rbp)
	movq	%rcx, -512(%rbp)
	movq	-504(%rbp), %rax
	movq	-512(%rbp), %rcx
	movq	%rcx, -496(%rbp)
	movq	-496(%rbp), %rcx
	movq	%rcx, -488(%rbp)
	movq	-488(%rbp), %rcx
	movq	%rcx, -456(%rbp)
	movq	-456(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, (%rax)
	movq	-512(%rbp), %rcx
	movq	%rcx, -472(%rbp)
	movq	-472(%rbp), %rcx
	movq	%rcx, -464(%rbp)
	movq	-464(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -480(%rbp)
	movq	-480(%rbp), %rcx
	movl	(%rcx), %edi
	movl	%edi, 4(%rax)
	movq	-840(%rbp), %rdi
	movq	-848(%rbp), %rax
	movq	%rsi, -936(%rbp)        ## 8-byte Spill
	movq	%rax, %rsi
	movq	-936(%rbp), %rax        ## 8-byte Reload
	callq	*%rax
	movb	%al, -921(%rbp)         ## 1-byte Spill
LBB7_15:                                ##   in Loop: Header=BB7_12 Depth=2
	movb	-921(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB7_12
## BB#16:                               ##   in Loop: Header=BB7_9 Depth=1
	leaq	-824(%rbp), %rax
	movq	-784(%rbp), %rcx
	movq	%rax, -616(%rbp)
	movq	-616(%rbp), %rax
	movq	%rcx, -640(%rbp)
	movq	%rax, -648(%rbp)
	movq	-640(%rbp), %rax
	movq	-648(%rbp), %rcx
	movq	%rcx, -632(%rbp)
	movq	-632(%rbp), %rcx
	movl	(%rcx), %edx
	movl	%edx, (%rax)
	movq	-648(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, -624(%rbp)
	movq	-624(%rbp), %rcx
	movl	(%rcx), %edx
	movl	%edx, 4(%rax)
	movl	-792(%rbp), %edx
	addl	$1, %edx
	movl	%edx, -792(%rbp)
	cmpl	$8, %edx
	jne	LBB7_18
## BB#17:
	movq	-800(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -800(%rbp)
	cmpq	-752(%rbp), %rax
	sete	%cl
	andb	$1, %cl
	movb	%cl, -729(%rbp)
	jmp	LBB7_22
LBB7_18:                                ##   in Loop: Header=BB7_9 Depth=1
	jmp	LBB7_19
LBB7_19:                                ##   in Loop: Header=BB7_9 Depth=1
	movq	-800(%rbp), %rax
	movq	%rax, -784(%rbp)
## BB#20:                               ##   in Loop: Header=BB7_9 Depth=1
	movq	-800(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -800(%rbp)
	jmp	LBB7_9
LBB7_21:
	movb	$1, -729(%rbp)
LBB7_22:
	movb	-729(%rbp), %al
	andb	$1, %al
	movzbl	%al, %eax
	addq	$944, %rsp              ## imm = 0x3B0
	popq	%rbp
	retq
	.cfi_endproc
	.p2align	2, 0x90
	.data_region jt32
L7_0_set_1 = LBB7_1-LJTI7_0
L7_0_set_2 = LBB7_2-LJTI7_0
L7_0_set_5 = LBB7_5-LJTI7_0
L7_0_set_6 = LBB7_6-LJTI7_0
L7_0_set_7 = LBB7_7-LJTI7_0
LJTI7_0:
	.long	L7_0_set_1
	.long	L7_0_set_1
	.long	L7_0_set_2
	.long	L7_0_set_5
	.long	L7_0_set_6
	.long	L7_0_set_7
	.end_data_region

	.globl	_data                   ## @data
.zerofill __DATA,__common,_data,2000000,4
	.globl	_sum                    ## @sum
.zerofill __DATA,__common,_sum,8,3
	.globl	_mode                   ## @mode
.zerofill __DATA,__common,_mode,64008,4
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

L_.str.1:                               ## @.str.1
	.asciz	"%lld\n"

L_.str.2:                               ## @.str.2
	.asciz	"%d\n"


.subsections_via_symbols
