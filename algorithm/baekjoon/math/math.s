	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90
___cxx_global_var_init:                 ## @__cxx_global_var_init
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
	subq	$240, %rsp
	leaq	_que_arr(%rip), %rax
	movq	%rax, -224(%rbp)        ## 8-byte Spill
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-224(%rbp), %rax        ## 8-byte Reload
	leaq	_que_arr(%rip), %rcx
	addq	$96, %rcx
	leaq	-32(%rbp), %rdx
	leaq	-56(%rbp), %rsi
	leaq	-104(%rbp), %rdi
	leaq	-128(%rbp), %r8
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %r9
	movq	%r9, -208(%rbp)
	movq	-208(%rbp), %r9
	movq	%r9, -200(%rbp)
	movq	-200(%rbp), %r9
	movq	%r9, -192(%rbp)
	movq	-192(%rbp), %r9
	movq	%r9, -168(%rbp)
	movq	-168(%rbp), %r9
	movq	%r9, -160(%rbp)
	movq	-160(%rbp), %r10
	movq	%r10, -152(%rbp)
	movq	-152(%rbp), %r10
	movq	$0, (%r10)
	movq	$0, 8(%r10)
	movq	$0, 16(%r10)
	addq	$24, %r10
	movq	%r10, -136(%rbp)
	movq	$0, -144(%rbp)
	movq	-136(%rbp), %r10
	movq	-144(%rbp), %r11
	movq	%r10, -120(%rbp)
	movq	%r11, -128(%rbp)
	movq	-120(%rbp), %r10
	movq	%r8, -112(%rbp)
	movq	-112(%rbp), %r8
	movq	(%r8), %r8
	movq	%r10, -96(%rbp)
	movq	%r8, -104(%rbp)
	movq	-96(%rbp), %r8
	movq	%r8, %r10
	movq	%r10, -88(%rbp)
	movq	%rdi, -80(%rbp)
	movq	-80(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, (%r8)
	movq	$0, 32(%r9)
	addq	$40, %r9
	movq	%r9, -64(%rbp)
	movq	$0, -72(%rbp)
	movq	-64(%rbp), %rdi
	movq	-72(%rbp), %r8
	movq	%rdi, -48(%rbp)
	movq	%r8, -56(%rbp)
	movq	-48(%rbp), %rdi
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rsi
	movq	%rsi, %rdi
	movq	%rdi, -16(%rbp)
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rsi)
	addq	$48, %rax
	cmpq	%rcx, %rax
	movq	%rax, -224(%rbp)        ## 8-byte Spill
	jne	LBB0_1
## BB#2:
	leaq	___cxx_global_array_dtor(%rip), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	___dso_handle@GOTPCREL(%rip), %rdx
	callq	___cxa_atexit
	movl	%eax, -228(%rbp)        ## 4-byte Spill
	addq	$240, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
___cxx_global_array_dtor:               ## @__cxx_global_array_dtor
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
	subq	$32, %rsp
	leaq	_que_arr(%rip), %rax
	addq	$96, %rax
	movq	%rdi, -8(%rbp)
	movq	%rax, -16(%rbp)         ## 8-byte Spill
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax         ## 8-byte Reload
	addq	$-48, %rax
	movq	%rax, %rdi
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	callq	__ZNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEED1Ev
	leaq	_que_arr(%rip), %rax
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	cmpq	%rax, %rdi
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	jne	LBB1_1
## BB#2:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEED1Ev
	.p2align	4, 0x90
__ZNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEED1Ev: ## @_ZNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEED1Ev
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
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
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
	subq	$80, %rsp
	leaq	L_.str(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movl	$0, -4(%rbp)
	movb	$0, %al
	callq	_scanf
	leaq	L_.str(%rip), %rdi
	leaq	-12(%rbp), %rsi
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	L_.str(%rip), %rdi
	leaq	-16(%rbp), %rsi
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	leaq	_que_arr(%rip), %rsi
	movb	$0, -17(%rbp)
	movl	-12(%rbp), %edi
	movl	-16(%rbp), %ecx
	movb	-17(%rbp), %dl
	andb	$1, %dl
	movzbl	%dl, %r8d
	movl	%r8d, %r9d
	imulq	$48, %r9, %r9
	addq	%r9, %rsi
	movq	%rsi, -48(%rbp)         ## 8-byte Spill
	movl	%ecx, %esi
	movq	-48(%rbp), %rdx         ## 8-byte Reload
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	callq	__ZL10_gcd_whileiiRNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEEE
	movl	$0, -28(%rbp)
	movl	%eax, -56(%rbp)         ## 4-byte Spill
LBB3_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-28(%rbp), %eax
	movl	-8(%rbp), %ecx
	subl	$2, %ecx
	cmpl	%ecx, %eax
	jge	LBB3_4
## BB#2:                                ##   in Loop: Header=BB3_1 Depth=1
	leaq	L_.str(%rip), %rdi
	leaq	-24(%rbp), %rsi
	movb	$0, %al
	callq	_scanf
	leaq	_que_arr(%rip), %rsi
	movb	-17(%rbp), %cl
	andb	$1, %cl
	movzbl	%cl, %edx
	movl	%edx, %edi
	imulq	$48, %rdi, %rdi
	movq	%rsi, %r8
	addq	%rdi, %r8
	movb	-17(%rbp), %cl
	andb	$1, %cl
	movzbl	%cl, %edx
	xorl	$1, %edx
	movslq	%edx, %rdi
	imulq	$48, %rdi, %rdi
	addq	%rdi, %rsi
	movl	-24(%rbp), %edx
	movq	%r8, %rdi
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	callq	__ZL14_delete_in_queRNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEEES6_i
	movb	-17(%rbp), %cl
	andb	$1, %cl
	movzbl	%cl, %edx
	xorl	$1, %edx
	cmpl	$0, %edx
	setne	%cl
	andb	$1, %cl
	movb	%cl, -17(%rbp)
	movl	%eax, -64(%rbp)         ## 4-byte Spill
## BB#3:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -28(%rbp)
	jmp	LBB3_1
LBB3_4:
	leaq	_que_arr(%rip), %rdi
	callq	__ZL13_print_in_queRNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEEE
	leaq	_que_arr(%rip), %rdi
	addq	$48, %rdi
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	callq	__ZL13_print_in_queRNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEEE
	xorl	%ecx, %ecx
	movl	%eax, -72(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__ZL10_gcd_whileiiRNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEEE: ## @_ZL10_gcd_whileiiRNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEEE
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
	subq	$48, %rsp
	leaq	L_.str.1(%rip), %rax
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	movl	-20(%rbp), %esi
	movl	%esi, -40(%rbp)
	movl	-24(%rbp), %esi
	movl	%esi, -44(%rbp)
	movl	-20(%rbp), %esi
	movl	-24(%rbp), %edx
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -48(%rbp)         ## 4-byte Spill
LBB4_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -24(%rbp)
	je	LBB4_7
## BB#2:                                ##   in Loop: Header=BB4_1 Depth=1
	movl	-20(%rbp), %eax
	cltd
	idivl	-24(%rbp)
	movl	%edx, -36(%rbp)
	movl	-24(%rbp), %edx
	movl	%edx, -20(%rbp)
	movl	-36(%rbp), %edx
	movl	%edx, -24(%rbp)
	cmpl	$0, -36(%rbp)
	je	LBB4_6
## BB#3:                                ##   in Loop: Header=BB4_1 Depth=1
	movl	-36(%rbp), %eax
	cmpl	-40(%rbp), %eax
	je	LBB4_6
## BB#4:                                ##   in Loop: Header=BB4_1 Depth=1
	movl	-36(%rbp), %eax
	cmpl	-44(%rbp), %eax
	je	LBB4_6
## BB#5:                                ##   in Loop: Header=BB4_1 Depth=1
	leaq	-36(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	__ZNSt3__15dequeIiNS_9allocatorIiEEE9push_backERKi
LBB4_6:                                 ##   in Loop: Header=BB4_1 Depth=1
	jmp	LBB4_1
LBB4_7:
	movl	-20(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__ZL14_delete_in_queRNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEEES6_i: ## @_ZL14_delete_in_queRNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEEES6_i
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
	subq	$96, %rsp
	movq	%rdi, -80(%rbp)
	movq	%rsi, -88(%rbp)
	movl	%edx, -92(%rbp)
LBB5_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-80(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	cmpq	$0, (%rax)
	sete	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	jne	LBB5_2
	jmp	LBB5_3
LBB5_2:                                 ##   in Loop: Header=BB5_1 Depth=1
	movq	-80(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	32(%rax), %rdx
	shrq	$10, %rdx
	movq	(%rcx,%rdx,8), %rcx
	movq	32(%rax), %rax
	andq	$1023, %rax             ## imm = 0x3FF
	movl	(%rcx,%rax,4), %edi
	movl	-92(%rbp), %esi
	movq	-88(%rbp), %rdx
	callq	__ZL10_gcd_whileiiRNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEEE
	movq	-80(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rdi
	movl	%eax, -96(%rbp)         ## 4-byte Spill
	callq	__ZNSt3__15dequeIiNS_9allocatorIiEEE9pop_frontEv
	jmp	LBB5_1
LBB5_3:
	xorl	%eax, %eax
	addq	$96, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__ZL13_print_in_queRNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEEE: ## @_ZL13_print_in_queRNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEEE
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
	subq	$96, %rsp
	movq	%rdi, -80(%rbp)
LBB6_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-80(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	cmpq	$0, (%rax)
	sete	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	jne	LBB6_2
	jmp	LBB6_3
LBB6_2:                                 ##   in Loop: Header=BB6_1 Depth=1
	leaq	L_.str.2(%rip), %rdi
	movq	-80(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	32(%rax), %rdx
	shrq	$10, %rdx
	movq	(%rcx,%rdx,8), %rcx
	movq	32(%rax), %rax
	andq	$1023, %rax             ## imm = 0x3FF
	movl	(%rcx,%rax,4), %esi
	movb	$0, %al
	callq	_printf
	movq	-80(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rdi
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	callq	__ZNSt3__15dequeIiNS_9allocatorIiEEE9pop_frontEv
	jmp	LBB6_1
LBB6_3:
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -88(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$96, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEED2Ev
	.p2align	4, 0x90
__ZNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEED2Ev: ## @_ZNSt3__15queueIiNS_5dequeIiNS_9allocatorIiEEEEED2Ev
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
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__15dequeIiNS_9allocatorIiEEED1Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15dequeIiNS_9allocatorIiEEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__15dequeIiNS_9allocatorIiEEED1Ev
	.p2align	4, 0x90
__ZNSt3__15dequeIiNS_9allocatorIiEEED1Ev: ## @_ZNSt3__15dequeIiNS_9allocatorIiEEED1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp24:
	.cfi_def_cfa_offset 16
Ltmp25:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp26:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__15dequeIiNS_9allocatorIiEEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15dequeIiNS_9allocatorIiEEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__15dequeIiNS_9allocatorIiEEED2Ev
	.p2align	4, 0x90
__ZNSt3__15dequeIiNS_9allocatorIiEEED2Ev: ## @_ZNSt3__15dequeIiNS_9allocatorIiEEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp27:
	.cfi_def_cfa_offset 16
Ltmp28:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp29:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEED2Ev
	.p2align	4, 0x90
__ZNSt3__112__deque_baseIiNS_9allocatorIiEEED2Ev: ## @_ZNSt3__112__deque_baseIiNS_9allocatorIiEEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp30:
	.cfi_def_cfa_offset 16
Ltmp31:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp32:
	.cfi_def_cfa_register %rbp
	subq	$160, %rsp
	movq	%rdi, -104(%rbp)
	movq	-104(%rbp), %rdi
	movq	%rdi, -144(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE5clearEv
	movq	-144(%rbp), %rdi        ## 8-byte Reload
	movq	%rdi, -96(%rbp)
	movq	-96(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -112(%rbp)
	movq	%rdi, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -120(%rbp)
LBB10_1:                                ## =>This Inner Loop Header: Depth=1
	movq	-112(%rbp), %rax
	cmpq	-120(%rbp), %rax
	je	LBB10_5
## BB#2:                                ##   in Loop: Header=BB10_1 Depth=1
	movq	-144(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -152(%rbp)        ## 8-byte Spill
## BB#3:                                ##   in Loop: Header=BB10_1 Depth=1
	movq	-112(%rbp), %rax
	movq	(%rax), %rax
	movq	-152(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -40(%rbp)
	movq	%rax, -48(%rbp)
	movq	$1024, -56(%rbp)        ## imm = 0x400
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	-56(%rbp), %rsi
	movq	%rax, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZdlPv
## BB#4:                                ##   in Loop: Header=BB10_1 Depth=1
	movq	-112(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -112(%rbp)
	jmp	LBB10_1
LBB10_5:
	movq	-144(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEED1Ev
	addq	$160, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE5clearEv
	.weak_definition	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE5clearEv
	.p2align	4, 0x90
__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE5clearEv: ## @_ZNSt3__112__deque_baseIiNS_9allocatorIiEEE5clearEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp33:
	.cfi_def_cfa_offset 16
Ltmp34:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp35:
	.cfi_def_cfa_register %rbp
	subq	$464, %rsp              ## imm = 0x1D0
	movq	%rdi, -320(%rbp)
	movq	-320(%rbp), %rdi
	movq	%rdi, -312(%rbp)
	movq	-312(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -304(%rbp)
	movq	-304(%rbp), %rax
	movq	%rax, -296(%rbp)
	movq	-296(%rbp), %rax
	movq	%rdi, -368(%rbp)        ## 8-byte Spill
	movq	%rax, -376(%rbp)        ## 8-byte Spill
## BB#1:
	movq	-376(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -328(%rbp)
	movq	-368(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE5beginEv
	movq	%rax, -344(%rbp)
	movq	%rdx, -336(%rbp)
	movq	-368(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE3endEv
	movq	%rax, -360(%rbp)
	movq	%rdx, -352(%rbp)
LBB11_2:                                ## =>This Inner Loop Header: Depth=1
	leaq	-360(%rbp), %rax
	leaq	-344(%rbp), %rcx
	movq	%rcx, -280(%rbp)
	movq	%rax, -288(%rbp)
	movq	-280(%rbp), %rax
	movq	-288(%rbp), %rcx
	movq	%rax, -264(%rbp)
	movq	%rcx, -272(%rbp)
	movq	-264(%rbp), %rax
	movq	8(%rax), %rax
	movq	-272(%rbp), %rcx
	cmpq	8(%rcx), %rax
	sete	%dl
	xorb	$-1, %dl
	movb	%dl, -377(%rbp)         ## 1-byte Spill
## BB#3:                                ##   in Loop: Header=BB11_2 Depth=1
	movb	-377(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB11_4
	jmp	LBB11_11
LBB11_4:                                ##   in Loop: Header=BB11_2 Depth=1
	leaq	-344(%rbp), %rax
	movq	-328(%rbp), %rcx
	movq	%rax, -136(%rbp)
	movq	-136(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rcx, -392(%rbp)        ## 8-byte Spill
	movq	%rax, -400(%rbp)        ## 8-byte Spill
## BB#5:                                ##   in Loop: Header=BB11_2 Depth=1
	movq	-400(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	-392(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -56(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-56(%rbp), %rcx
	movq	-64(%rbp), %rsi
	movq	%rcx, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rcx
	movq	-48(%rbp), %rsi
	movq	%rcx, -16(%rbp)
	movq	%rsi, -24(%rbp)
## BB#6:                                ##   in Loop: Header=BB11_2 Depth=1
	jmp	LBB11_7
LBB11_7:                                ##   in Loop: Header=BB11_2 Depth=1
	leaq	-344(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	8(%rax), %rcx
	addq	$4, %rcx
	movq	%rcx, 8(%rax)
	movq	(%rax), %rdx
	movq	(%rdx), %rdx
	subq	%rdx, %rcx
	sarq	$2, %rcx
	cmpq	$1024, %rcx             ## imm = 0x400
	movq	%rax, -408(%rbp)        ## 8-byte Spill
	jne	LBB11_9
## BB#8:                                ##   in Loop: Header=BB11_2 Depth=1
	movq	-408(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$8, %rcx
	movq	%rcx, (%rax)
	movq	(%rax), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, 8(%rax)
LBB11_9:                                ## %_ZNSt3__116__deque_iteratorIiPiRiPS1_lLl1024EEppEv.exit
                                        ##   in Loop: Header=BB11_2 Depth=1
	jmp	LBB11_10
LBB11_10:                               ##   in Loop: Header=BB11_2 Depth=1
	jmp	LBB11_2
LBB11_11:
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	%rcx, -416(%rbp)        ## 8-byte Spill
## BB#12:
	movq	-416(%rbp), %rax        ## 8-byte Reload
	movq	$0, (%rax)
LBB11_13:                               ## =>This Inner Loop Header: Depth=1
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	16(%rcx), %rdx
	movq	8(%rcx), %rcx
	subq	%rcx, %rdx
	sarq	$3, %rdx
	movq	%rdx, -424(%rbp)        ## 8-byte Spill
## BB#14:                               ##   in Loop: Header=BB11_13 Depth=1
	movq	-424(%rbp), %rax        ## 8-byte Reload
	cmpq	$2, %rax
	jbe	LBB11_18
## BB#15:                               ##   in Loop: Header=BB11_13 Depth=1
	movq	-328(%rbp), %rax
	movq	-368(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rdx
	movq	8(%rdx), %rdx
	movq	%rax, -432(%rbp)        ## 8-byte Spill
	movq	%rdx, -440(%rbp)        ## 8-byte Spill
## BB#16:                               ##   in Loop: Header=BB11_13 Depth=1
	movq	-440(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-432(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -176(%rbp)
	movq	%rcx, -184(%rbp)
	movq	$1024, -192(%rbp)       ## imm = 0x400
	movq	-176(%rbp), %rcx
	movq	-184(%rbp), %rsi
	movq	-192(%rbp), %rdi
	movq	%rcx, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	%rdi, -168(%rbp)
	movq	-160(%rbp), %rcx
	movq	%rcx, -144(%rbp)
	movq	-144(%rbp), %rdi
	callq	__ZdlPv
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -248(%rbp)
	movq	-248(%rbp), %rcx
	movq	8(%rcx), %rdx
	addq	$8, %rdx
	movq	%rcx, -216(%rbp)
	movq	%rdx, -224(%rbp)
	movq	-216(%rbp), %rcx
	movq	-224(%rbp), %rdx
	movq	%rcx, -200(%rbp)
	movq	%rdx, -208(%rbp)
	movq	-200(%rbp), %rcx
	movq	-208(%rbp), %rdx
	movq	%rdx, 8(%rcx)
## BB#17:                               ##   in Loop: Header=BB11_13 Depth=1
	jmp	LBB11_13
LBB11_18:
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -256(%rbp)
	movq	-256(%rbp), %rcx
	movq	16(%rcx), %rdx
	movq	8(%rcx), %rcx
	subq	%rcx, %rdx
	sarq	$3, %rdx
	movq	%rdx, -448(%rbp)        ## 8-byte Spill
## BB#19:
	movq	-448(%rbp), %rax        ## 8-byte Reload
	subq	$1, %rax
	movq	%rax, -456(%rbp)        ## 8-byte Spill
	je	LBB11_20
	jmp	LBB11_23
LBB11_23:
	movq	-448(%rbp), %rax        ## 8-byte Reload
	subq	$2, %rax
	movq	%rax, -464(%rbp)        ## 8-byte Spill
	je	LBB11_21
	jmp	LBB11_22
LBB11_20:
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	$512, 32(%rax)          ## imm = 0x200
	jmp	LBB11_22
LBB11_21:
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	$1024, 32(%rax)         ## imm = 0x400
LBB11_22:
	addq	$464, %rsp              ## imm = 0x1D0
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEED1Ev
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEED1Ev: ## @_ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEED1Ev
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
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

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

	.globl	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE5beginEv
	.weak_definition	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE5beginEv
	.p2align	4, 0x90
__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE5beginEv: ## @_ZNSt3__112__deque_baseIiNS_9allocatorIiEEE5beginEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp39:
	.cfi_def_cfa_offset 16
Ltmp40:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp41:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -88(%rbp)
	movq	-88(%rbp), %rdi
	movq	%rdi, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	8(%rax), %rax
	movq	32(%rdi), %rcx
	shrq	$10, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rax
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	16(%rcx), %rdx
	cmpq	8(%rcx), %rdx
	sete	%sil
	movq	%rdi, -104(%rbp)        ## 8-byte Spill
	movq	%rax, -112(%rbp)        ## 8-byte Spill
	movb	%sil, -113(%rbp)        ## 1-byte Spill
## BB#1:
	movb	-113(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB14_2
	jmp	LBB14_3
LBB14_2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -128(%rbp)        ## 8-byte Spill
	jmp	LBB14_4
LBB14_3:
	movq	-96(%rbp), %rax
	movq	(%rax), %rax
	movq	-104(%rbp), %rcx        ## 8-byte Reload
	movq	32(%rcx), %rdx
	andq	$1023, %rdx             ## imm = 0x3FF
	shlq	$2, %rdx
	addq	%rdx, %rax
	movq	%rax, -128(%rbp)        ## 8-byte Spill
LBB14_4:
	movq	-128(%rbp), %rax        ## 8-byte Reload
	leaq	-80(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-112(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -40(%rbp)
	movq	%rax, -48(%rbp)
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rsi
	movq	%rdx, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-80(%rbp), %rax
	movq	-72(%rbp), %rdx
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE3endEv
	.weak_definition	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE3endEv
	.p2align	4, 0x90
__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE3endEv: ## @_ZNSt3__112__deque_baseIiNS_9allocatorIiEEE3endEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp42:
	.cfi_def_cfa_offset 16
Ltmp43:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp44:
	.cfi_def_cfa_register %rbp
	subq	$40, %rsp
	movq	%rdi, -112(%rbp)
	movq	-112(%rbp), %rdi
	movq	%rdi, -88(%rbp)
	movq	-88(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	%rdi, -136(%rbp)        ## 8-byte Spill
	movq	%rax, -144(%rbp)        ## 8-byte Spill
## BB#1:
	movq	-144(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-136(%rbp), %rdx        ## 8-byte Reload
	addq	32(%rdx), %rcx
	movq	%rcx, -120(%rbp)
	movq	%rdx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	-120(%rbp), %rsi
	shrq	$10, %rsi
	shlq	$3, %rsi
	addq	%rsi, %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rsi
	movq	16(%rsi), %rdi
	cmpq	8(%rsi), %rdi
	sete	%r8b
	movq	%rcx, -152(%rbp)        ## 8-byte Spill
	movb	%r8b, -153(%rbp)        ## 1-byte Spill
## BB#2:
	movb	-153(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB15_3
	jmp	LBB15_4
LBB15_3:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -168(%rbp)        ## 8-byte Spill
	jmp	LBB15_5
LBB15_4:
	movq	-128(%rbp), %rax
	movq	(%rax), %rax
	movq	-120(%rbp), %rcx
	andq	$1023, %rcx             ## imm = 0x3FF
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -168(%rbp)        ## 8-byte Spill
LBB15_5:
	movq	-168(%rbp), %rax        ## 8-byte Reload
	leaq	-104(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	-152(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -48(%rbp)
	movq	%rax, -56(%rbp)
	movq	-40(%rbp), %rdx
	movq	-48(%rbp), %rsi
	movq	%rdx, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rax, -32(%rbp)
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-32(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-104(%rbp), %rax
	movq	-96(%rbp), %rdx
	addq	$40, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEED2Ev
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEED2Ev: ## @_ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp45:
	.cfi_def_cfa_offset 16
Ltmp46:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp47:
	.cfi_def_cfa_register %rbp
	subq	$320, %rsp              ## imm = 0x140
	movq	%rdi, -280(%rbp)
	movq	-280(%rbp), %rdi
	movq	%rdi, -272(%rbp)
	movq	-272(%rbp), %rax
	movq	8(%rax), %rcx
	movq	%rax, -248(%rbp)
	movq	%rcx, -256(%rbp)
	movq	-248(%rbp), %rax
	movq	-256(%rbp), %rcx
	movq	%rax, -232(%rbp)
	movq	%rcx, -240(%rbp)
	movq	-232(%rbp), %rax
	movq	%rdi, -288(%rbp)        ## 8-byte Spill
	movq	%rax, -296(%rbp)        ## 8-byte Spill
LBB16_1:                                ## =>This Inner Loop Header: Depth=1
	movq	-240(%rbp), %rax
	movq	-296(%rbp), %rcx        ## 8-byte Reload
	cmpq	16(%rcx), %rax
	je	LBB16_3
## BB#2:                                ##   in Loop: Header=BB16_1 Depth=1
	movq	-296(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -208(%rbp)
	movq	-208(%rbp), %rcx
	movq	%rcx, -200(%rbp)
	movq	-200(%rbp), %rcx
	movq	16(%rax), %rdx
	addq	$-8, %rdx
	movq	%rdx, 16(%rax)
	movq	%rdx, -192(%rbp)
	movq	-192(%rbp), %rdx
	movq	%rcx, -160(%rbp)
	movq	%rdx, -168(%rbp)
	movq	-160(%rbp), %rcx
	movq	-168(%rbp), %rdx
	movq	%rcx, -144(%rbp)
	movq	%rdx, -152(%rbp)
	movq	-144(%rbp), %rcx
	movq	-152(%rbp), %rdx
	movq	%rcx, -120(%rbp)
	movq	%rdx, -128(%rbp)
	jmp	LBB16_1
LBB16_3:                                ## %_ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE5clearEv.exit
	movq	-288(%rbp), %rax        ## 8-byte Reload
	cmpq	$0, (%rax)
	je	LBB16_6
## BB#4:
	movq	-288(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	(%rax), %rdx
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rsi
	movq	%rsi, -24(%rbp)
	movq	-24(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %rsi
	subq	%rsi, %rdi
	sarq	$3, %rdi
	movq	%rcx, -304(%rbp)        ## 8-byte Spill
	movq	%rdx, -312(%rbp)        ## 8-byte Spill
	movq	%rdi, -320(%rbp)        ## 8-byte Spill
## BB#5:
	movq	-304(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -72(%rbp)
	movq	-312(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -80(%rbp)
	movq	-320(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -88(%rbp)
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %rdi
	movq	-88(%rbp), %r8
	movq	%rsi, -48(%rbp)
	movq	%rdi, -56(%rbp)
	movq	%r8, -64(%rbp)
	movq	-56(%rbp), %rsi
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rdi
	callq	__ZdlPv
LBB16_6:
	addq	$320, %rsp              ## imm = 0x140
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15dequeIiNS_9allocatorIiEEE9push_backERKi
	.weak_definition	__ZNSt3__15dequeIiNS_9allocatorIiEEE9push_backERKi
	.p2align	4, 0x90
__ZNSt3__15dequeIiNS_9allocatorIiEEE9push_backERKi: ## @_ZNSt3__15dequeIiNS_9allocatorIiEEE9push_backERKi
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp48:
	.cfi_def_cfa_offset 16
Ltmp49:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp50:
	.cfi_def_cfa_register %rbp
	subq	$320, %rsp              ## imm = 0x140
	movq	%rdi, -248(%rbp)
	movq	%rsi, -256(%rbp)
	movq	-248(%rbp), %rsi
	movq	%rsi, %rdi
	movq	%rdi, -240(%rbp)
	movq	-240(%rbp), %rdi
	addq	$40, %rdi
	movq	%rdi, -232(%rbp)
	movq	-232(%rbp), %rdi
	movq	%rdi, -224(%rbp)
	movq	-224(%rbp), %rdi
	movq	%rdi, -264(%rbp)
	movq	%rsi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	%rdi, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	16(%rcx), %rdx
	movq	8(%rcx), %rcx
	subq	%rcx, %rdx
	sarq	$3, %rdx
	cmpq	$0, %rdx
	movq	%rsi, -288(%rbp)        ## 8-byte Spill
	movq	%rdi, -296(%rbp)        ## 8-byte Spill
	movq	%rax, -304(%rbp)        ## 8-byte Spill
	jne	LBB17_2
## BB#1:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -312(%rbp)        ## 8-byte Spill
	jmp	LBB17_3
LBB17_2:
	movq	-304(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	16(%rax), %rcx
	movq	8(%rax), %rax
	subq	%rax, %rcx
	sarq	$3, %rcx
	shlq	$10, %rcx
	subq	$1, %rcx
	movq	%rcx, -312(%rbp)        ## 8-byte Spill
LBB17_3:                                ## %_ZNKSt3__15dequeIiNS_9allocatorIiEEE12__back_spareEv.exit
	movq	-312(%rbp), %rax        ## 8-byte Reload
	movq	-296(%rbp), %rcx        ## 8-byte Reload
	movq	32(%rcx), %rdx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	addq	(%rcx), %rdx
	subq	%rdx, %rax
	cmpq	$0, %rax
	jne	LBB17_5
## BB#4:
	movq	-288(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__15dequeIiNS_9allocatorIiEEE19__add_back_capacityEv
LBB17_5:
	movq	-264(%rbp), %rax
	movq	-288(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, %rdi
	movq	%rax, -320(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__112__deque_baseIiNS_9allocatorIiEEE3endEv
	leaq	-280(%rbp), %rcx
	movq	%rax, -280(%rbp)
	movq	%rdx, -272(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	-256(%rbp), %rcx
	movq	-320(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -160(%rbp)
	movq	%rax, -168(%rbp)
	movq	%rcx, -176(%rbp)
	movq	-160(%rbp), %rax
	movq	-168(%rbp), %rcx
	movq	-176(%rbp), %rdx
	movq	%rdx, -152(%rbp)
	movq	-152(%rbp), %rdx
	movq	%rax, -128(%rbp)
	movq	%rcx, -136(%rbp)
	movq	%rdx, -144(%rbp)
	movq	-128(%rbp), %rax
	movq	-136(%rbp), %rcx
	movq	-144(%rbp), %rdx
	movq	%rdx, -112(%rbp)
	movq	-112(%rbp), %rdx
	movq	%rax, -88(%rbp)
	movq	%rcx, -96(%rbp)
	movq	%rdx, -104(%rbp)
	movq	-96(%rbp), %rax
	movq	-104(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	-80(%rbp), %rcx
	movl	(%rcx), %esi
	movl	%esi, (%rax)
	movq	-288(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -208(%rbp)
	movq	-208(%rbp), %rax
	movq	%rax, -200(%rbp)
	movq	-200(%rbp), %rax
	movq	(%rax), %rcx
	addq	$1, %rcx
	movq	%rcx, (%rax)
	addq	$320, %rsp              ## imm = 0x140
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15dequeIiNS_9allocatorIiEEE19__add_back_capacityEv
	.weak_definition	__ZNSt3__15dequeIiNS_9allocatorIiEEE19__add_back_capacityEv
	.p2align	4, 0x90
__ZNSt3__15dequeIiNS_9allocatorIiEEE19__add_back_capacityEv: ## @_ZNSt3__15dequeIiNS_9allocatorIiEEE19__add_back_capacityEv
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## BB#0:
	pushq	%rbp
Ltmp65:
	.cfi_def_cfa_offset 16
Ltmp66:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp67:
	.cfi_def_cfa_register %rbp
	subq	$3376, %rsp             ## imm = 0xD30
	movq	%rdi, -3032(%rbp)
	movq	-3032(%rbp), %rdi
	movq	%rdi, %rax
	movq	%rax, -3024(%rbp)
	movq	-3024(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -3016(%rbp)
	movq	-3016(%rbp), %rax
	movq	%rax, -3008(%rbp)
	movq	-3008(%rbp), %rax
	movq	%rax, -3040(%rbp)
	movq	%rdi, -3000(%rbp)
	movq	-3000(%rbp), %rax
	cmpq	$1024, 32(%rax)         ## imm = 0x400
	movq	%rdi, -3208(%rbp)       ## 8-byte Spill
	jb	LBB18_14
## BB#1:
	leaq	-3048(%rbp), %rax
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	32(%rcx), %rdx
	subq	$1024, %rdx             ## imm = 0x400
	movq	%rdx, 32(%rcx)
	movq	%rcx, -2992(%rbp)
	movq	-2992(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -3048(%rbp)
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -2824(%rbp)
	movq	-2824(%rbp), %rcx
	movq	8(%rcx), %rdx
	addq	$8, %rdx
	movq	%rcx, -2792(%rbp)
	movq	%rdx, -2800(%rbp)
	movq	-2792(%rbp), %rcx
	movq	-2800(%rbp), %rdx
	movq	%rcx, -2776(%rbp)
	movq	%rdx, -2784(%rbp)
	movq	-2776(%rbp), %rcx
	movq	-2784(%rbp), %rdx
	movq	%rdx, 8(%rcx)
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -2256(%rbp)
	movq	%rax, -2264(%rbp)
	movq	-2256(%rbp), %rax
	movq	16(%rax), %rcx
	movq	%rax, -2248(%rbp)
	movq	-2248(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -2240(%rbp)
	movq	-2240(%rbp), %rdx
	movq	%rdx, -2232(%rbp)
	movq	-2232(%rbp), %rdx
	cmpq	(%rdx), %rcx
	movq	%rax, -3216(%rbp)       ## 8-byte Spill
	jne	LBB18_13
## BB#2:
	movq	-3216(%rbp), %rax       ## 8-byte Reload
	movq	8(%rax), %rcx
	cmpq	(%rax), %rcx
	jbe	LBB18_6
## BB#3:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movl	$2, %eax
	movl	%eax, %edx
	movq	-3216(%rbp), %rsi       ## 8-byte Reload
	movq	8(%rsi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	movq	%rdi, -2272(%rbp)
	movq	-2272(%rbp), %rdi
	addq	$1, %rdi
	movq	%rdi, %rax
	movq	%rdx, -3224(%rbp)       ## 8-byte Spill
	cqto
	movq	-3224(%rbp), %rdi       ## 8-byte Reload
	idivq	%rdi
	movq	%rax, -2272(%rbp)
	movq	8(%rsi), %rax
	movq	16(%rsi), %r8
	movq	8(%rsi), %r9
	subq	-2272(%rbp), %rcx
	shlq	$3, %rcx
	addq	%rcx, %r9
	movq	%rax, -2056(%rbp)
	movq	%r8, -2064(%rbp)
	movq	%r9, -2072(%rbp)
	movq	-2056(%rbp), %rax
	movq	%rax, -2048(%rbp)
	movq	-2048(%rbp), %rax
	movq	-2064(%rbp), %rcx
	movq	%rcx, -2000(%rbp)
	movq	-2000(%rbp), %rcx
	movq	-2072(%rbp), %r8
	movq	%r8, -2008(%rbp)
	movq	-2008(%rbp), %r8
	movq	%rax, -2016(%rbp)
	movq	%rcx, -2024(%rbp)
	movq	%r8, -2032(%rbp)
	movq	-2024(%rbp), %rax
	movq	-2016(%rbp), %rcx
	subq	%rcx, %rax
	sarq	$3, %rax
	movq	%rax, -2040(%rbp)
	cmpq	$0, -2040(%rbp)
	jbe	LBB18_5
## BB#4:
	movq	-2032(%rbp), %rax
	movq	-2016(%rbp), %rcx
	movq	-2040(%rbp), %rdx
	shlq	$3, %rdx
	movq	%rax, %rdi
	movq	%rcx, %rsi
	callq	_memmove
	movq	%rax, -3232(%rbp)       ## 8-byte Spill
LBB18_5:                                ## %_ZNSt3__14moveIPPiS2_EET0_T_S4_S3_.exit.i
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-2032(%rbp), %rdx
	movq	-2040(%rbp), %rsi
	shlq	$3, %rsi
	addq	%rsi, %rdx
	movq	-3216(%rbp), %rsi       ## 8-byte Reload
	movq	%rdx, 16(%rsi)
	movq	-2272(%rbp), %rdx
	movq	8(%rsi), %rdi
	subq	%rdx, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rdi
	movq	%rdi, 8(%rsi)
	jmp	LBB18_12
LBB18_6:
	leaq	-1688(%rbp), %rax
	leaq	-2296(%rbp), %rcx
	leaq	-2288(%rbp), %rdx
	movq	-3216(%rbp), %rsi       ## 8-byte Reload
	movq	%rsi, -1992(%rbp)
	movq	-1992(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -1984(%rbp)
	movq	-1984(%rbp), %rdi
	movq	%rdi, -1976(%rbp)
	movq	-1976(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -2288(%rbp)
	movq	$1, -2296(%rbp)
	movq	%rdx, -1712(%rbp)
	movq	%rcx, -1720(%rbp)
	movq	-1712(%rbp), %rcx
	movq	-1720(%rbp), %rdx
	movq	%rcx, -1696(%rbp)
	movq	%rdx, -1704(%rbp)
	movq	-1696(%rbp), %rcx
	movq	-1704(%rbp), %rdx
	movq	%rax, -1664(%rbp)
	movq	%rcx, -1672(%rbp)
	movq	%rdx, -1680(%rbp)
	movq	-1672(%rbp), %rax
	movq	(%rax), %rax
	movq	-1680(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB18_8
## BB#7:
	movq	-1704(%rbp), %rax
	movq	%rax, -3240(%rbp)       ## 8-byte Spill
	jmp	LBB18_9
LBB18_8:
	movq	-1696(%rbp), %rax
	movq	%rax, -3240(%rbp)       ## 8-byte Spill
LBB18_9:                                ## %_ZNSt3__13maxImEERKT_S3_S3_.exit.i
	movq	-3240(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rax
	movq	%rax, -2280(%rbp)
	movq	%rax, %rcx
	shrq	$2, %rcx
	movq	-3216(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -1592(%rbp)
	addq	$24, %rdx
	movq	%rdx, -1584(%rbp)
	movq	%rdx, -1576(%rbp)
	leaq	-2336(%rbp), %rsi
	movq	%rsi, %rdi
	movq	%rsi, -3248(%rbp)       ## 8-byte Spill
	movq	%rax, %rsi
	movq	%rdx, -3256(%rbp)       ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-3256(%rbp), %rcx       ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC1EmmS4_
	movq	-3216(%rbp), %rax       ## 8-byte Reload
	movq	8(%rax), %rcx
	leaq	-2344(%rbp), %rdx
	movq	%rdx, -1616(%rbp)
	movq	%rcx, -1624(%rbp)
	movq	-1616(%rbp), %rdx
	movq	%rdx, -1600(%rbp)
	movq	%rcx, -1608(%rbp)
	movq	-1600(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	16(%rax), %rcx
	leaq	-2368(%rbp), %rdx
	movq	%rdx, -1648(%rbp)
	movq	%rcx, -1656(%rbp)
	movq	-1648(%rbp), %rdx
	movq	%rdx, -1632(%rbp)
	movq	%rcx, -1640(%rbp)
	movq	-1632(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	-2344(%rbp), %rsi
	movq	-2368(%rbp), %rdx
Ltmp62:
	movq	-3248(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
Ltmp63:
	jmp	LBB18_10
LBB18_10:
	leaq	-2336(%rbp), %rax
	leaq	-1968(%rbp), %rcx
	leaq	-1872(%rbp), %rdx
	leaq	-1824(%rbp), %rsi
	leaq	-1776(%rbp), %rdi
	movq	-3216(%rbp), %r8        ## 8-byte Reload
	movq	%r8, -1760(%rbp)
	movq	%rax, -1768(%rbp)
	movq	-1760(%rbp), %r9
	movq	%r9, -1752(%rbp)
	movq	-1752(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -1776(%rbp)
	movq	-1768(%rbp), %r9
	movq	%r9, -1736(%rbp)
	movq	-1736(%rbp), %r9
	movq	(%r9), %r9
	movq	-1760(%rbp), %r10
	movq	%r9, (%r10)
	movq	%rdi, -1744(%rbp)
	movq	-1744(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-1768(%rbp), %r9
	movq	%rdi, (%r9)
	addq	$8, %r8
	movq	%rax, %rdi
	addq	$8, %rdi
	movq	%r8, -1808(%rbp)
	movq	%rdi, -1816(%rbp)
	movq	-1808(%rbp), %rdi
	movq	%rdi, -1800(%rbp)
	movq	-1800(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -1824(%rbp)
	movq	-1816(%rbp), %rdi
	movq	%rdi, -1784(%rbp)
	movq	-1784(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-1808(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -1792(%rbp)
	movq	-1792(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-1816(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-3216(%rbp), %rsi       ## 8-byte Reload
	addq	$16, %rsi
	movq	%rax, %rdi
	addq	$16, %rdi
	movq	%rsi, -1856(%rbp)
	movq	%rdi, -1864(%rbp)
	movq	-1856(%rbp), %rsi
	movq	%rsi, -1848(%rbp)
	movq	-1848(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -1872(%rbp)
	movq	-1864(%rbp), %rsi
	movq	%rsi, -1832(%rbp)
	movq	-1832(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-1856(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rdx, -1840(%rbp)
	movq	-1840(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-1864(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-3216(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -1896(%rbp)
	movq	-1896(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -1888(%rbp)
	movq	-1888(%rbp), %rsi
	movq	%rsi, -1880(%rbp)
	movq	-1880(%rbp), %rsi
	movq	%rax, -1920(%rbp)
	movq	-1920(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -1912(%rbp)
	movq	-1912(%rbp), %rdi
	movq	%rdi, -1904(%rbp)
	movq	-1904(%rbp), %rdi
	movq	%rsi, -1952(%rbp)
	movq	%rdi, -1960(%rbp)
	movq	-1952(%rbp), %rsi
	movq	%rsi, -1944(%rbp)
	movq	-1944(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -1968(%rbp)
	movq	-1960(%rbp), %rsi
	movq	%rsi, -1928(%rbp)
	movq	-1928(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-1952(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rcx, -1936(%rbp)
	movq	-1936(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-1960(%rbp), %rsi
	movq	%rcx, (%rsi)
	movq	%rax, %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	jmp	LBB18_12
LBB18_11:
Ltmp64:
	leaq	-2336(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -2352(%rbp)
	movl	%ecx, -2356(%rbp)
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	movq	-2352(%rbp), %rax
	movq	%rax, -3264(%rbp)       ## 8-byte Spill
	jmp	LBB18_52
LBB18_12:
	jmp	LBB18_13
LBB18_13:                               ## %_ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE9push_backERKS1_.exit
	movq	-3216(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2096(%rbp)
	movq	-2096(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -2088(%rbp)
	movq	-2088(%rbp), %rcx
	movq	%rcx, -2080(%rbp)
	movq	-2080(%rbp), %rcx
	movq	16(%rax), %rdx
	movq	%rdx, -2104(%rbp)
	movq	-2104(%rbp), %rdx
	movq	-2264(%rbp), %rsi
	movq	%rcx, -2192(%rbp)
	movq	%rdx, -2200(%rbp)
	movq	%rsi, -2208(%rbp)
	movq	-2192(%rbp), %rcx
	movq	-2200(%rbp), %rdx
	movq	-2208(%rbp), %rsi
	movq	%rsi, -2184(%rbp)
	movq	-2184(%rbp), %rsi
	movq	%rcx, -2160(%rbp)
	movq	%rdx, -2168(%rbp)
	movq	%rsi, -2176(%rbp)
	movq	-2160(%rbp), %rcx
	movq	-2168(%rbp), %rdx
	movq	-2176(%rbp), %rsi
	movq	%rsi, -2144(%rbp)
	movq	-2144(%rbp), %rsi
	movq	%rcx, -2120(%rbp)
	movq	%rdx, -2128(%rbp)
	movq	%rsi, -2136(%rbp)
	movq	-2128(%rbp), %rcx
	movq	-2136(%rbp), %rdx
	movq	%rdx, -2112(%rbp)
	movq	-2112(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	16(%rax), %rcx
	addq	$8, %rcx
	movq	%rcx, 16(%rax)
	jmp	LBB18_50
LBB18_14:
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1568(%rbp)
	movq	-1568(%rbp), %rax
	movq	16(%rax), %rcx
	movq	8(%rax), %rax
	subq	%rax, %rcx
	sarq	$3, %rcx
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1560(%rbp)
	movq	-1560(%rbp), %rax
	movq	%rax, -1552(%rbp)
	movq	-1552(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -1544(%rbp)
	movq	-1544(%rbp), %rdx
	movq	%rdx, -1536(%rbp)
	movq	-1536(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	(%rax), %rax
	subq	%rax, %rdx
	sarq	$3, %rdx
	cmpq	%rdx, %rcx
	jae	LBB18_31
## BB#15:
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1528(%rbp)
	movq	-1528(%rbp), %rax
	movq	%rax, -1520(%rbp)
	movq	-1520(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -1512(%rbp)
	movq	-1512(%rbp), %rcx
	movq	%rcx, -1504(%rbp)
	movq	-1504(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	16(%rax), %rax
	subq	%rax, %rcx
	sarq	$3, %rcx
	cmpq	$0, %rcx
	je	LBB18_17
## BB#16:
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	-3040(%rbp), %rcx
	movq	%rcx, -1488(%rbp)
	movq	$1024, -1496(%rbp)      ## imm = 0x400
	movq	-1488(%rbp), %rcx
	movq	-1496(%rbp), %rdx
	movq	%rcx, -1464(%rbp)
	movq	%rdx, -1472(%rbp)
	movq	$0, -1480(%rbp)
	movq	-1472(%rbp), %rcx
	shlq	$2, %rcx
	movq	%rcx, -1456(%rbp)
	movq	-1456(%rbp), %rdi
	movq	%rax, -3272(%rbp)       ## 8-byte Spill
	callq	__Znwm
	leaq	-3056(%rbp), %rsi
	movq	%rax, -3056(%rbp)
	movq	-3272(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE9push_backEOS1_
	jmp	LBB18_30
LBB18_17:
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	-3040(%rbp), %rcx
	movq	%rcx, -1440(%rbp)
	movq	$1024, -1448(%rbp)      ## imm = 0x400
	movq	-1440(%rbp), %rcx
	movq	-1448(%rbp), %rdx
	movq	%rcx, -1416(%rbp)
	movq	%rdx, -1424(%rbp)
	movq	$0, -1432(%rbp)
	movq	-1424(%rbp), %rcx
	shlq	$2, %rcx
	movq	%rcx, -1408(%rbp)
	movq	-1408(%rbp), %rdi
	movq	%rax, -3280(%rbp)       ## 8-byte Spill
	callq	__Znwm
	leaq	-3064(%rbp), %rsi
	movq	%rax, -3064(%rbp)
	movq	-3280(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE10push_frontEOS1_
	leaq	-3072(%rbp), %rax
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1400(%rbp)
	movq	-1400(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -3072(%rbp)
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1392(%rbp)
	movq	-1392(%rbp), %rcx
	movq	8(%rcx), %rdx
	addq	$8, %rdx
	movq	%rcx, -1360(%rbp)
	movq	%rdx, -1368(%rbp)
	movq	-1360(%rbp), %rcx
	movq	-1368(%rbp), %rdx
	movq	%rcx, -1344(%rbp)
	movq	%rdx, -1352(%rbp)
	movq	-1344(%rbp), %rcx
	movq	-1352(%rbp), %rdx
	movq	%rdx, 8(%rcx)
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1160(%rbp)
	movq	%rax, -1168(%rbp)
	movq	-1160(%rbp), %rax
	movq	16(%rax), %rcx
	movq	%rax, -1152(%rbp)
	movq	-1152(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -1144(%rbp)
	movq	-1144(%rbp), %rdx
	movq	%rdx, -1136(%rbp)
	movq	-1136(%rbp), %rdx
	cmpq	(%rdx), %rcx
	movq	%rax, -3288(%rbp)       ## 8-byte Spill
	jne	LBB18_29
## BB#18:
	movq	-3288(%rbp), %rax       ## 8-byte Reload
	movq	8(%rax), %rcx
	cmpq	(%rax), %rcx
	jbe	LBB18_22
## BB#19:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movl	$2, %eax
	movl	%eax, %edx
	movq	-3288(%rbp), %rsi       ## 8-byte Reload
	movq	8(%rsi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	movq	%rdi, -1176(%rbp)
	movq	-1176(%rbp), %rdi
	addq	$1, %rdi
	movq	%rdi, %rax
	movq	%rdx, -3296(%rbp)       ## 8-byte Spill
	cqto
	movq	-3296(%rbp), %rdi       ## 8-byte Reload
	idivq	%rdi
	movq	%rax, -1176(%rbp)
	movq	8(%rsi), %rax
	movq	16(%rsi), %r8
	movq	8(%rsi), %r9
	subq	-1176(%rbp), %rcx
	shlq	$3, %rcx
	addq	%rcx, %r9
	movq	%rax, -960(%rbp)
	movq	%r8, -968(%rbp)
	movq	%r9, -976(%rbp)
	movq	-960(%rbp), %rax
	movq	%rax, -952(%rbp)
	movq	-952(%rbp), %rax
	movq	-968(%rbp), %rcx
	movq	%rcx, -904(%rbp)
	movq	-904(%rbp), %rcx
	movq	-976(%rbp), %r8
	movq	%r8, -912(%rbp)
	movq	-912(%rbp), %r8
	movq	%rax, -920(%rbp)
	movq	%rcx, -928(%rbp)
	movq	%r8, -936(%rbp)
	movq	-928(%rbp), %rax
	movq	-920(%rbp), %rcx
	subq	%rcx, %rax
	sarq	$3, %rax
	movq	%rax, -944(%rbp)
	cmpq	$0, -944(%rbp)
	jbe	LBB18_21
## BB#20:
	movq	-936(%rbp), %rax
	movq	-920(%rbp), %rcx
	movq	-944(%rbp), %rdx
	shlq	$3, %rdx
	movq	%rax, %rdi
	movq	%rcx, %rsi
	callq	_memmove
	movq	%rax, -3304(%rbp)       ## 8-byte Spill
LBB18_21:                               ## %_ZNSt3__14moveIPPiS2_EET0_T_S4_S3_.exit.i2
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-936(%rbp), %rdx
	movq	-944(%rbp), %rsi
	shlq	$3, %rsi
	addq	%rsi, %rdx
	movq	-3288(%rbp), %rsi       ## 8-byte Reload
	movq	%rdx, 16(%rsi)
	movq	-1176(%rbp), %rdx
	movq	8(%rsi), %rdi
	subq	%rdx, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rdi
	movq	%rdi, 8(%rsi)
	jmp	LBB18_28
LBB18_22:
	leaq	-592(%rbp), %rax
	leaq	-1200(%rbp), %rcx
	leaq	-1192(%rbp), %rdx
	movq	-3288(%rbp), %rsi       ## 8-byte Reload
	movq	%rsi, -896(%rbp)
	movq	-896(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -888(%rbp)
	movq	-888(%rbp), %rdi
	movq	%rdi, -880(%rbp)
	movq	-880(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -1192(%rbp)
	movq	$1, -1200(%rbp)
	movq	%rdx, -616(%rbp)
	movq	%rcx, -624(%rbp)
	movq	-616(%rbp), %rcx
	movq	-624(%rbp), %rdx
	movq	%rcx, -600(%rbp)
	movq	%rdx, -608(%rbp)
	movq	-600(%rbp), %rcx
	movq	-608(%rbp), %rdx
	movq	%rax, -568(%rbp)
	movq	%rcx, -576(%rbp)
	movq	%rdx, -584(%rbp)
	movq	-576(%rbp), %rax
	movq	(%rax), %rax
	movq	-584(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB18_24
## BB#23:
	movq	-608(%rbp), %rax
	movq	%rax, -3312(%rbp)       ## 8-byte Spill
	jmp	LBB18_25
LBB18_24:
	movq	-600(%rbp), %rax
	movq	%rax, -3312(%rbp)       ## 8-byte Spill
LBB18_25:                               ## %_ZNSt3__13maxImEERKT_S3_S3_.exit.i3
	movq	-3312(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rax
	movq	%rax, -1184(%rbp)
	movq	%rax, %rcx
	shrq	$2, %rcx
	movq	-3288(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -496(%rbp)
	addq	$24, %rdx
	movq	%rdx, -488(%rbp)
	movq	%rdx, -480(%rbp)
	leaq	-1240(%rbp), %rsi
	movq	%rsi, %rdi
	movq	%rsi, -3320(%rbp)       ## 8-byte Spill
	movq	%rax, %rsi
	movq	%rdx, -3328(%rbp)       ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-3328(%rbp), %rcx       ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC1EmmS4_
	movq	-3288(%rbp), %rax       ## 8-byte Reload
	movq	8(%rax), %rcx
	leaq	-1248(%rbp), %rdx
	movq	%rdx, -520(%rbp)
	movq	%rcx, -528(%rbp)
	movq	-520(%rbp), %rdx
	movq	%rdx, -504(%rbp)
	movq	%rcx, -512(%rbp)
	movq	-504(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	16(%rax), %rcx
	leaq	-1272(%rbp), %rdx
	movq	%rdx, -552(%rbp)
	movq	%rcx, -560(%rbp)
	movq	-552(%rbp), %rdx
	movq	%rdx, -536(%rbp)
	movq	%rcx, -544(%rbp)
	movq	-536(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	-1248(%rbp), %rsi
	movq	-1272(%rbp), %rdx
Ltmp59:
	movq	-3320(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
Ltmp60:
	jmp	LBB18_26
LBB18_26:
	leaq	-1240(%rbp), %rax
	leaq	-872(%rbp), %rcx
	leaq	-776(%rbp), %rdx
	leaq	-728(%rbp), %rsi
	leaq	-680(%rbp), %rdi
	movq	-3288(%rbp), %r8        ## 8-byte Reload
	movq	%r8, -664(%rbp)
	movq	%rax, -672(%rbp)
	movq	-664(%rbp), %r9
	movq	%r9, -656(%rbp)
	movq	-656(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -680(%rbp)
	movq	-672(%rbp), %r9
	movq	%r9, -640(%rbp)
	movq	-640(%rbp), %r9
	movq	(%r9), %r9
	movq	-664(%rbp), %r10
	movq	%r9, (%r10)
	movq	%rdi, -648(%rbp)
	movq	-648(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-672(%rbp), %r9
	movq	%rdi, (%r9)
	addq	$8, %r8
	movq	%rax, %rdi
	addq	$8, %rdi
	movq	%r8, -712(%rbp)
	movq	%rdi, -720(%rbp)
	movq	-712(%rbp), %rdi
	movq	%rdi, -704(%rbp)
	movq	-704(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -728(%rbp)
	movq	-720(%rbp), %rdi
	movq	%rdi, -688(%rbp)
	movq	-688(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-712(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -696(%rbp)
	movq	-696(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-720(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-3288(%rbp), %rsi       ## 8-byte Reload
	addq	$16, %rsi
	movq	%rax, %rdi
	addq	$16, %rdi
	movq	%rsi, -760(%rbp)
	movq	%rdi, -768(%rbp)
	movq	-760(%rbp), %rsi
	movq	%rsi, -752(%rbp)
	movq	-752(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -776(%rbp)
	movq	-768(%rbp), %rsi
	movq	%rsi, -736(%rbp)
	movq	-736(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-760(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rdx, -744(%rbp)
	movq	-744(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-768(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-3288(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -800(%rbp)
	movq	-800(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -792(%rbp)
	movq	-792(%rbp), %rsi
	movq	%rsi, -784(%rbp)
	movq	-784(%rbp), %rsi
	movq	%rax, -824(%rbp)
	movq	-824(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -816(%rbp)
	movq	-816(%rbp), %rdi
	movq	%rdi, -808(%rbp)
	movq	-808(%rbp), %rdi
	movq	%rsi, -856(%rbp)
	movq	%rdi, -864(%rbp)
	movq	-856(%rbp), %rsi
	movq	%rsi, -848(%rbp)
	movq	-848(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -872(%rbp)
	movq	-864(%rbp), %rsi
	movq	%rsi, -832(%rbp)
	movq	-832(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-856(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rcx, -840(%rbp)
	movq	-840(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-864(%rbp), %rsi
	movq	%rcx, (%rsi)
	movq	%rax, %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	jmp	LBB18_28
LBB18_27:
Ltmp61:
	leaq	-1240(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -1256(%rbp)
	movl	%ecx, -1260(%rbp)
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	movq	-1256(%rbp), %rax
	movq	%rax, -3264(%rbp)       ## 8-byte Spill
	jmp	LBB18_52
LBB18_28:
	jmp	LBB18_29
LBB18_29:                               ## %_ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE9push_backERKS1_.exit4
	movq	-3288(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1000(%rbp)
	movq	-1000(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -992(%rbp)
	movq	-992(%rbp), %rcx
	movq	%rcx, -984(%rbp)
	movq	-984(%rbp), %rcx
	movq	16(%rax), %rdx
	movq	%rdx, -1008(%rbp)
	movq	-1008(%rbp), %rdx
	movq	-1168(%rbp), %rsi
	movq	%rcx, -1096(%rbp)
	movq	%rdx, -1104(%rbp)
	movq	%rsi, -1112(%rbp)
	movq	-1096(%rbp), %rcx
	movq	-1104(%rbp), %rdx
	movq	-1112(%rbp), %rsi
	movq	%rsi, -1088(%rbp)
	movq	-1088(%rbp), %rsi
	movq	%rcx, -1064(%rbp)
	movq	%rdx, -1072(%rbp)
	movq	%rsi, -1080(%rbp)
	movq	-1064(%rbp), %rcx
	movq	-1072(%rbp), %rdx
	movq	-1080(%rbp), %rsi
	movq	%rsi, -1048(%rbp)
	movq	-1048(%rbp), %rsi
	movq	%rcx, -1024(%rbp)
	movq	%rdx, -1032(%rbp)
	movq	%rsi, -1040(%rbp)
	movq	-1032(%rbp), %rcx
	movq	-1040(%rbp), %rdx
	movq	%rdx, -1016(%rbp)
	movq	-1016(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	16(%rax), %rcx
	addq	$8, %rcx
	movq	%rcx, 16(%rax)
LBB18_30:
	jmp	LBB18_49
LBB18_31:
	leaq	-400(%rbp), %rax
	leaq	-3128(%rbp), %rcx
	leaq	-3120(%rbp), %rdx
	movq	-3208(%rbp), %rsi       ## 8-byte Reload
	movq	%rsi, -472(%rbp)
	movq	-472(%rbp), %rsi
	movq	%rsi, -464(%rbp)
	movq	-464(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -456(%rbp)
	movq	-456(%rbp), %rdi
	movq	%rdi, -448(%rbp)
	movq	-448(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %rsi
	subq	%rsi, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -3120(%rbp)
	movq	$1, -3128(%rbp)
	movq	%rdx, -424(%rbp)
	movq	%rcx, -432(%rbp)
	movq	-424(%rbp), %rcx
	movq	-432(%rbp), %rdx
	movq	%rcx, -408(%rbp)
	movq	%rdx, -416(%rbp)
	movq	-408(%rbp), %rcx
	movq	-416(%rbp), %rdx
	movq	%rax, -376(%rbp)
	movq	%rcx, -384(%rbp)
	movq	%rdx, -392(%rbp)
	movq	-384(%rbp), %rax
	movq	(%rax), %rax
	movq	-392(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB18_33
## BB#32:
	movq	-416(%rbp), %rax
	movq	%rax, -3336(%rbp)       ## 8-byte Spill
	jmp	LBB18_34
LBB18_33:
	movq	-408(%rbp), %rax
	movq	%rax, -3336(%rbp)       ## 8-byte Spill
LBB18_34:                               ## %_ZNSt3__13maxImEERKT_S3_S3_.exit
	movq	-3336(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rsi
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -368(%rbp)
	movq	8(%rax), %rcx
	movq	16(%rax), %rdx
	subq	%rcx, %rdx
	sarq	$3, %rdx
	movq	%rax, -360(%rbp)
	addq	$24, %rax
	movq	%rax, -352(%rbp)
	movq	%rax, -344(%rbp)
	leaq	-3112(%rbp), %rdi
	movq	%rax, %rcx
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC1EmmS4_
	movq	-3040(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	$1024, -48(%rbp)        ## imm = 0x400
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	$1024, -24(%rbp)        ## imm = 0x400
	movq	$0, -32(%rbp)
	movq	-24(%rbp), %rax
	shlq	$2, %rax
	movq	%rax, -8(%rbp)
Ltmp51:
	movq	%rax, %rdi
	callq	__Znwm
Ltmp52:
	movq	%rax, -3344(%rbp)       ## 8-byte Spill
	jmp	LBB18_35
LBB18_35:                               ## %_ZNSt3__116allocator_traitsINS_9allocatorIiEEE8allocateERS2_m.exit
	movq	-3344(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -3352(%rbp)       ## 8-byte Spill
## BB#36:
	movq	-3040(%rbp), %rax
	leaq	-3184(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	%rax, -88(%rbp)
	movq	$1024, -96(%rbp)        ## imm = 0x400
	movq	-80(%rbp), %rax
	movq	-88(%rbp), %rdx
	movq	%rax, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	$1024, -72(%rbp)        ## imm = 0x400
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-72(%rbp), %rdx
	movq	%rdx, 8(%rax)
	leaq	-3152(%rbp), %rax
	movq	%rax, -296(%rbp)
	movq	-3352(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -304(%rbp)
	movq	%rcx, -312(%rbp)
	movq	-296(%rbp), %rsi
	movq	-304(%rbp), %rdi
	movq	%rsi, -256(%rbp)
	movq	%rdi, -264(%rbp)
	movq	%rcx, -272(%rbp)
	movq	-256(%rbp), %rsi
	movq	-264(%rbp), %rdi
	movq	%rcx, -248(%rbp)
	movq	-3184(%rbp), %rcx
	movq	-3176(%rbp), %r8
	movq	%r8, -280(%rbp)
	movq	%rcx, -288(%rbp)
	movq	-288(%rbp), %rcx
	movq	-280(%rbp), %r8
	movq	%rcx, -224(%rbp)
	movq	%r8, -216(%rbp)
	movq	%rsi, -232(%rbp)
	movq	%rdi, -240(%rbp)
	movq	-232(%rbp), %rcx
	movq	-224(%rbp), %rsi
	movq	-216(%rbp), %r8
	movq	%rsi, -176(%rbp)
	movq	%r8, -168(%rbp)
	movq	%rcx, -184(%rbp)
	movq	%rdi, -192(%rbp)
	movq	-184(%rbp), %rcx
	leaq	-192(%rbp), %rsi
	movq	%rsi, -160(%rbp)
	movq	-192(%rbp), %rsi
	leaq	-176(%rbp), %rdi
	movq	%rdi, -104(%rbp)
	movq	-176(%rbp), %rdi
	movq	-168(%rbp), %r8
	movq	%r8, -200(%rbp)
	movq	%rdi, -208(%rbp)
	movq	-208(%rbp), %rdi
	movq	-200(%rbp), %r8
	movq	%rdi, -136(%rbp)
	movq	%r8, -128(%rbp)
	movq	%rcx, -144(%rbp)
	movq	%rsi, -152(%rbp)
	movq	-144(%rbp), %rcx
	leaq	-152(%rbp), %rsi
	movq	%rsi, -120(%rbp)
	movq	-152(%rbp), %rsi
	movq	%rsi, (%rcx)
	leaq	-136(%rbp), %rsi
	movq	%rsi, -112(%rbp)
	movq	-136(%rbp), %rsi
	movq	-128(%rbp), %rdi
	movq	%rdi, 16(%rcx)
	movq	%rsi, 8(%rcx)
	movq	%rax, -336(%rbp)
	movq	%rax, -328(%rbp)
	movq	%rax, -320(%rbp)
	movq	-3152(%rbp), %rax
	movq	%rax, -3192(%rbp)
Ltmp54:
	leaq	-3112(%rbp), %rdi
	leaq	-3192(%rbp), %rsi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE9push_backEOS1_
Ltmp55:
	jmp	LBB18_37
LBB18_37:
	leaq	-3152(%rbp), %rax
	movq	%rax, -1312(%rbp)
	movq	-1312(%rbp), %rax
	movq	%rax, -1304(%rbp)
	movq	-1304(%rbp), %rcx
	movq	%rcx, -1296(%rbp)
	movq	-1296(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -1320(%rbp)
	movq	%rax, -1288(%rbp)
	movq	-1288(%rbp), %rax
	movq	%rax, -1280(%rbp)
	movq	-1280(%rbp), %rax
	movq	$0, (%rax)
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1328(%rbp)
	movq	-1328(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -3200(%rbp)
LBB18_38:                               ## =>This Inner Loop Header: Depth=1
	movq	-3200(%rbp), %rax
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1336(%rbp)
	movq	-1336(%rbp), %rcx
	cmpq	8(%rcx), %rax
	je	LBB18_45
## BB#39:                               ##   in Loop: Header=BB18_38 Depth=1
	movq	-3200(%rbp), %rax
	addq	$-8, %rax
	movq	%rax, -3200(%rbp)
Ltmp56:
	leaq	-3112(%rbp), %rdi
	movq	%rax, %rsi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE10push_frontERKS1_
Ltmp57:
	jmp	LBB18_40
LBB18_40:                               ##   in Loop: Header=BB18_38 Depth=1
	jmp	LBB18_38
LBB18_41:
Ltmp53:
	movl	%edx, %ecx
	movq	%rax, -3160(%rbp)
	movl	%ecx, -3164(%rbp)
	jmp	LBB18_48
LBB18_42:
Ltmp58:
	leaq	-3152(%rbp), %rcx
	movl	%edx, %esi
	movq	%rax, -3160(%rbp)
	movl	%esi, -3164(%rbp)
	movq	%rcx, -2528(%rbp)
	movq	-2528(%rbp), %rax
	movq	%rax, -2520(%rbp)
	movq	-2520(%rbp), %rax
	movq	%rax, -2496(%rbp)
	movq	$0, -2504(%rbp)
	movq	-2496(%rbp), %rax
	movq	%rax, -2488(%rbp)
	movq	-2488(%rbp), %rcx
	movq	%rcx, -2480(%rbp)
	movq	-2480(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -2512(%rbp)
	movq	-2504(%rbp), %rcx
	movq	%rax, -2400(%rbp)
	movq	-2400(%rbp), %rdx
	movq	%rdx, -2392(%rbp)
	movq	-2392(%rbp), %rdx
	movq	%rcx, (%rdx)
	cmpq	$0, -2512(%rbp)
	movq	%rax, -3360(%rbp)       ## 8-byte Spill
	je	LBB18_44
## BB#43:
	movq	-3360(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2384(%rbp)
	movq	-2384(%rbp), %rcx
	movq	%rcx, -2376(%rbp)
	movq	-2376(%rbp), %rcx
	addq	$8, %rcx
	movq	-2512(%rbp), %rdx
	movq	%rcx, -2464(%rbp)
	movq	%rdx, -2472(%rbp)
	movq	-2464(%rbp), %rcx
	movq	(%rcx), %rdx
	movq	-2472(%rbp), %rsi
	movq	8(%rcx), %rcx
	movq	%rdx, -2440(%rbp)
	movq	%rsi, -2448(%rbp)
	movq	%rcx, -2456(%rbp)
	movq	-2440(%rbp), %rcx
	movq	-2448(%rbp), %rdx
	movq	-2456(%rbp), %rsi
	movq	%rcx, -2416(%rbp)
	movq	%rdx, -2424(%rbp)
	movq	%rsi, -2432(%rbp)
	movq	-2424(%rbp), %rcx
	movq	%rcx, -2408(%rbp)
	movq	-2408(%rbp), %rdi
	callq	__ZdlPv
LBB18_44:                               ## %_ZNSt3__110unique_ptrIPiNS_22__allocator_destructorINS_9allocatorIiEEEEED1Ev.exit1
	jmp	LBB18_48
LBB18_45:
	leaq	-3152(%rbp), %rax
	leaq	-2768(%rbp), %rcx
	leaq	-3112(%rbp), %rdx
	leaq	-2672(%rbp), %rsi
	leaq	-2624(%rbp), %rdi
	leaq	-2576(%rbp), %r8
	movq	-3208(%rbp), %r9        ## 8-byte Reload
	movq	%r9, -2560(%rbp)
	movq	%rdx, -2568(%rbp)
	movq	-2560(%rbp), %r9
	movq	%r9, -2552(%rbp)
	movq	-2552(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -2576(%rbp)
	movq	-2568(%rbp), %r9
	movq	%r9, -2536(%rbp)
	movq	-2536(%rbp), %r9
	movq	(%r9), %r9
	movq	-2560(%rbp), %r10
	movq	%r9, (%r10)
	movq	%r8, -2544(%rbp)
	movq	-2544(%rbp), %r8
	movq	(%r8), %r8
	movq	-2568(%rbp), %r9
	movq	%r8, (%r9)
	movq	-3208(%rbp), %r8        ## 8-byte Reload
	addq	$8, %r8
	movq	%rdx, %r9
	addq	$8, %r9
	movq	%r8, -2608(%rbp)
	movq	%r9, -2616(%rbp)
	movq	-2608(%rbp), %r8
	movq	%r8, -2600(%rbp)
	movq	-2600(%rbp), %r8
	movq	(%r8), %r8
	movq	%r8, -2624(%rbp)
	movq	-2616(%rbp), %r8
	movq	%r8, -2584(%rbp)
	movq	-2584(%rbp), %r8
	movq	(%r8), %r8
	movq	-2608(%rbp), %r9
	movq	%r8, (%r9)
	movq	%rdi, -2592(%rbp)
	movq	-2592(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-2616(%rbp), %r8
	movq	%rdi, (%r8)
	movq	-3208(%rbp), %rdi       ## 8-byte Reload
	addq	$16, %rdi
	movq	%rdx, %r8
	addq	$16, %r8
	movq	%rdi, -2656(%rbp)
	movq	%r8, -2664(%rbp)
	movq	-2656(%rbp), %rdi
	movq	%rdi, -2648(%rbp)
	movq	-2648(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -2672(%rbp)
	movq	-2664(%rbp), %rdi
	movq	%rdi, -2632(%rbp)
	movq	-2632(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-2656(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -2640(%rbp)
	movq	-2640(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-2664(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-3208(%rbp), %rsi       ## 8-byte Reload
	movq	%rsi, -2696(%rbp)
	movq	-2696(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -2688(%rbp)
	movq	-2688(%rbp), %rsi
	movq	%rsi, -2680(%rbp)
	movq	-2680(%rbp), %rsi
	movq	%rdx, -2720(%rbp)
	movq	-2720(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -2712(%rbp)
	movq	-2712(%rbp), %rdx
	movq	%rdx, -2704(%rbp)
	movq	-2704(%rbp), %rdx
	movq	%rsi, -2752(%rbp)
	movq	%rdx, -2760(%rbp)
	movq	-2752(%rbp), %rdx
	movq	%rdx, -2744(%rbp)
	movq	-2744(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -2768(%rbp)
	movq	-2760(%rbp), %rdx
	movq	%rdx, -2728(%rbp)
	movq	-2728(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2752(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	%rcx, -2736(%rbp)
	movq	-2736(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-2760(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	%rax, -2984(%rbp)
	movq	-2984(%rbp), %rax
	movq	%rax, -2976(%rbp)
	movq	-2976(%rbp), %rax
	movq	%rax, -2952(%rbp)
	movq	$0, -2960(%rbp)
	movq	-2952(%rbp), %rax
	movq	%rax, -2944(%rbp)
	movq	-2944(%rbp), %rcx
	movq	%rcx, -2936(%rbp)
	movq	-2936(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -2968(%rbp)
	movq	-2960(%rbp), %rcx
	movq	%rax, -2856(%rbp)
	movq	-2856(%rbp), %rdx
	movq	%rdx, -2848(%rbp)
	movq	-2848(%rbp), %rdx
	movq	%rcx, (%rdx)
	cmpq	$0, -2968(%rbp)
	movq	%rax, -3368(%rbp)       ## 8-byte Spill
	je	LBB18_47
## BB#46:
	movq	-3368(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2840(%rbp)
	movq	-2840(%rbp), %rcx
	movq	%rcx, -2832(%rbp)
	movq	-2832(%rbp), %rcx
	addq	$8, %rcx
	movq	-2968(%rbp), %rdx
	movq	%rcx, -2920(%rbp)
	movq	%rdx, -2928(%rbp)
	movq	-2920(%rbp), %rcx
	movq	(%rcx), %rdx
	movq	-2928(%rbp), %rsi
	movq	8(%rcx), %rcx
	movq	%rdx, -2896(%rbp)
	movq	%rsi, -2904(%rbp)
	movq	%rcx, -2912(%rbp)
	movq	-2896(%rbp), %rcx
	movq	-2904(%rbp), %rdx
	movq	-2912(%rbp), %rsi
	movq	%rcx, -2872(%rbp)
	movq	%rdx, -2880(%rbp)
	movq	%rsi, -2888(%rbp)
	movq	-2880(%rbp), %rcx
	movq	%rcx, -2864(%rbp)
	movq	-2864(%rbp), %rdi
	callq	__ZdlPv
LBB18_47:                               ## %_ZNSt3__110unique_ptrIPiNS_22__allocator_destructorINS_9allocatorIiEEEEED1Ev.exit
	leaq	-3112(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	jmp	LBB18_49
LBB18_48:
	leaq	-3112(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	jmp	LBB18_51
LBB18_49:
	jmp	LBB18_50
LBB18_50:
	addq	$3376, %rsp             ## imm = 0xD30
	popq	%rbp
	retq
LBB18_51:
	movq	-3160(%rbp), %rax
	movq	%rax, -3264(%rbp)       ## 8-byte Spill
LBB18_52:                               ## %unwind_resume
	movq	-3264(%rbp), %rax       ## 8-byte Reload
	movq	%rax, %rdi
	callq	__Unwind_Resume
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table18:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\352\200\200"          ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	104                     ## Call site table length
Lset0 = Lfunc_begin0-Lfunc_begin0       ## >> Call Site 1 <<
	.long	Lset0
Lset1 = Ltmp62-Lfunc_begin0             ##   Call between Lfunc_begin0 and Ltmp62
	.long	Lset1
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset2 = Ltmp62-Lfunc_begin0             ## >> Call Site 2 <<
	.long	Lset2
Lset3 = Ltmp63-Ltmp62                   ##   Call between Ltmp62 and Ltmp63
	.long	Lset3
Lset4 = Ltmp64-Lfunc_begin0             ##     jumps to Ltmp64
	.long	Lset4
	.byte	0                       ##   On action: cleanup
Lset5 = Ltmp63-Lfunc_begin0             ## >> Call Site 3 <<
	.long	Lset5
Lset6 = Ltmp59-Ltmp63                   ##   Call between Ltmp63 and Ltmp59
	.long	Lset6
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset7 = Ltmp59-Lfunc_begin0             ## >> Call Site 4 <<
	.long	Lset7
Lset8 = Ltmp60-Ltmp59                   ##   Call between Ltmp59 and Ltmp60
	.long	Lset8
Lset9 = Ltmp61-Lfunc_begin0             ##     jumps to Ltmp61
	.long	Lset9
	.byte	0                       ##   On action: cleanup
Lset10 = Ltmp60-Lfunc_begin0            ## >> Call Site 5 <<
	.long	Lset10
Lset11 = Ltmp51-Ltmp60                  ##   Call between Ltmp60 and Ltmp51
	.long	Lset11
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset12 = Ltmp51-Lfunc_begin0            ## >> Call Site 6 <<
	.long	Lset12
Lset13 = Ltmp52-Ltmp51                  ##   Call between Ltmp51 and Ltmp52
	.long	Lset13
Lset14 = Ltmp53-Lfunc_begin0            ##     jumps to Ltmp53
	.long	Lset14
	.byte	0                       ##   On action: cleanup
Lset15 = Ltmp54-Lfunc_begin0            ## >> Call Site 7 <<
	.long	Lset15
Lset16 = Ltmp57-Ltmp54                  ##   Call between Ltmp54 and Ltmp57
	.long	Lset16
Lset17 = Ltmp58-Lfunc_begin0            ##     jumps to Ltmp58
	.long	Lset17
	.byte	0                       ##   On action: cleanup
Lset18 = Ltmp57-Lfunc_begin0            ## >> Call Site 8 <<
	.long	Lset18
Lset19 = Lfunc_end0-Ltmp57              ##   Call between Ltmp57 and Lfunc_end0
	.long	Lset19
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE9push_backEOS1_
	.weak_definition	__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE9push_backEOS1_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE9push_backEOS1_: ## @_ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE9push_backEOS1_
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
## BB#0:
	pushq	%rbp
Ltmp71:
	.cfi_def_cfa_offset 16
Ltmp72:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp73:
	.cfi_def_cfa_register %rbp
	subq	$848, %rsp              ## imm = 0x350
	movq	%rdi, -696(%rbp)
	movq	%rsi, -704(%rbp)
	movq	-696(%rbp), %rsi
	movq	16(%rsi), %rdi
	movq	%rsi, -688(%rbp)
	movq	-688(%rbp), %rax
	addq	$24, %rax
	movq	%rax, -680(%rbp)
	movq	-680(%rbp), %rax
	movq	%rax, -672(%rbp)
	movq	-672(%rbp), %rax
	cmpq	(%rax), %rdi
	movq	%rsi, -816(%rbp)        ## 8-byte Spill
	jne	LBB19_14
## BB#1:
	movq	-816(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	cmpq	(%rax), %rcx
	jbe	LBB19_5
## BB#2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movl	$2, %eax
	movl	%eax, %edx
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	movq	8(%rsi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	movq	%rdi, -712(%rbp)
	movq	-712(%rbp), %rdi
	addq	$1, %rdi
	movq	%rdi, %rax
	movq	%rdx, -824(%rbp)        ## 8-byte Spill
	cqto
	movq	-824(%rbp), %rdi        ## 8-byte Reload
	idivq	%rdi
	movq	%rax, -712(%rbp)
	movq	8(%rsi), %rax
	movq	16(%rsi), %r8
	movq	8(%rsi), %r9
	subq	-712(%rbp), %rcx
	shlq	$3, %rcx
	addq	%rcx, %r9
	movq	%rax, -488(%rbp)
	movq	%r8, -496(%rbp)
	movq	%r9, -504(%rbp)
	movq	-488(%rbp), %rax
	movq	%rax, -480(%rbp)
	movq	-480(%rbp), %rax
	movq	-496(%rbp), %rcx
	movq	%rcx, -432(%rbp)
	movq	-432(%rbp), %rcx
	movq	-504(%rbp), %r8
	movq	%r8, -440(%rbp)
	movq	-440(%rbp), %r8
	movq	%rax, -448(%rbp)
	movq	%rcx, -456(%rbp)
	movq	%r8, -464(%rbp)
	movq	-456(%rbp), %rax
	movq	-448(%rbp), %rcx
	subq	%rcx, %rax
	sarq	$3, %rax
	movq	%rax, -472(%rbp)
	cmpq	$0, -472(%rbp)
	jbe	LBB19_4
## BB#3:
	movq	-464(%rbp), %rax
	movq	-448(%rbp), %rcx
	movq	-472(%rbp), %rdx
	shlq	$3, %rdx
	movq	%rax, %rdi
	movq	%rcx, %rsi
	callq	_memmove
	movq	%rax, -832(%rbp)        ## 8-byte Spill
LBB19_4:                                ## %_ZNSt3__14moveIPPiS2_EET0_T_S4_S3_.exit
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-464(%rbp), %rdx
	movq	-472(%rbp), %rsi
	shlq	$3, %rsi
	addq	%rsi, %rdx
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	movq	%rdx, 16(%rsi)
	movq	-712(%rbp), %rdx
	movq	8(%rsi), %rdi
	subq	%rdx, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rdi
	movq	%rdi, 8(%rsi)
	jmp	LBB19_13
LBB19_5:
	leaq	-120(%rbp), %rax
	leaq	-736(%rbp), %rcx
	leaq	-728(%rbp), %rdx
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	movq	%rsi, -424(%rbp)
	movq	-424(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -416(%rbp)
	movq	-416(%rbp), %rdi
	movq	%rdi, -408(%rbp)
	movq	-408(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -728(%rbp)
	movq	$1, -736(%rbp)
	movq	%rdx, -144(%rbp)
	movq	%rcx, -152(%rbp)
	movq	-144(%rbp), %rcx
	movq	-152(%rbp), %rdx
	movq	%rcx, -128(%rbp)
	movq	%rdx, -136(%rbp)
	movq	-128(%rbp), %rcx
	movq	-136(%rbp), %rdx
	movq	%rax, -96(%rbp)
	movq	%rcx, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	-104(%rbp), %rax
	movq	(%rax), %rax
	movq	-112(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB19_7
## BB#6:
	movq	-136(%rbp), %rax
	movq	%rax, -840(%rbp)        ## 8-byte Spill
	jmp	LBB19_8
LBB19_7:
	movq	-128(%rbp), %rax
	movq	%rax, -840(%rbp)        ## 8-byte Spill
LBB19_8:                                ## %_ZNSt3__13maxImEERKT_S3_S3_.exit
	movq	-840(%rbp), %rax        ## 8-byte Reload
	leaq	-776(%rbp), %rdi
	movq	(%rax), %rax
	movq	%rax, -720(%rbp)
	movq	-720(%rbp), %rsi
	movq	-720(%rbp), %rax
	shrq	$2, %rax
	movq	-816(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	%rdx, -848(%rbp)        ## 8-byte Spill
	movq	%rax, %rdx
	movq	-848(%rbp), %rcx        ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC1EmmS4_
	leaq	-784(%rbp), %rax
	movq	-816(%rbp), %rcx        ## 8-byte Reload
	movq	8(%rcx), %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-48(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#9:
	leaq	-808(%rbp), %rax
	movq	-816(%rbp), %rcx        ## 8-byte Reload
	movq	16(%rcx), %rdx
	movq	%rax, -80(%rbp)
	movq	%rdx, -88(%rbp)
	movq	-80(%rbp), %rax
	movq	-88(%rbp), %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#10:
	movq	-784(%rbp), %rsi
	movq	-808(%rbp), %rdx
Ltmp68:
	leaq	-776(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
Ltmp69:
	jmp	LBB19_11
LBB19_11:
	leaq	-776(%rbp), %rax
	leaq	-400(%rbp), %rcx
	leaq	-304(%rbp), %rdx
	leaq	-256(%rbp), %rsi
	leaq	-208(%rbp), %rdi
	movq	-816(%rbp), %r8         ## 8-byte Reload
	movq	%r8, -192(%rbp)
	movq	%rax, -200(%rbp)
	movq	-192(%rbp), %r9
	movq	%r9, -184(%rbp)
	movq	-184(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -208(%rbp)
	movq	-200(%rbp), %r9
	movq	%r9, -168(%rbp)
	movq	-168(%rbp), %r9
	movq	(%r9), %r9
	movq	-192(%rbp), %r10
	movq	%r9, (%r10)
	movq	%rdi, -176(%rbp)
	movq	-176(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-200(%rbp), %r9
	movq	%rdi, (%r9)
	addq	$8, %r8
	movq	%rax, %rdi
	addq	$8, %rdi
	movq	%r8, -240(%rbp)
	movq	%rdi, -248(%rbp)
	movq	-240(%rbp), %rdi
	movq	%rdi, -232(%rbp)
	movq	-232(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -256(%rbp)
	movq	-248(%rbp), %rdi
	movq	%rdi, -216(%rbp)
	movq	-216(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-240(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -224(%rbp)
	movq	-224(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-248(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	addq	$16, %rsi
	movq	%rax, %rdi
	addq	$16, %rdi
	movq	%rsi, -288(%rbp)
	movq	%rdi, -296(%rbp)
	movq	-288(%rbp), %rsi
	movq	%rsi, -280(%rbp)
	movq	-280(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -304(%rbp)
	movq	-296(%rbp), %rsi
	movq	%rsi, -264(%rbp)
	movq	-264(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-288(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rdx, -272(%rbp)
	movq	-272(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-296(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-816(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -328(%rbp)
	movq	-328(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -320(%rbp)
	movq	-320(%rbp), %rsi
	movq	%rsi, -312(%rbp)
	movq	-312(%rbp), %rsi
	movq	%rax, -352(%rbp)
	movq	-352(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -344(%rbp)
	movq	-344(%rbp), %rdi
	movq	%rdi, -336(%rbp)
	movq	-336(%rbp), %rdi
	movq	%rsi, -384(%rbp)
	movq	%rdi, -392(%rbp)
	movq	-384(%rbp), %rsi
	movq	%rsi, -376(%rbp)
	movq	-376(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -400(%rbp)
	movq	-392(%rbp), %rsi
	movq	%rsi, -360(%rbp)
	movq	-360(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-384(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rcx, -368(%rbp)
	movq	-368(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-392(%rbp), %rsi
	movq	%rcx, (%rsi)
	movq	%rax, %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	jmp	LBB19_13
LBB19_12:
Ltmp70:
	leaq	-776(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -792(%rbp)
	movl	%ecx, -796(%rbp)
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	jmp	LBB19_15
LBB19_13:
	jmp	LBB19_14
LBB19_14:
	movq	-816(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -528(%rbp)
	movq	-528(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -520(%rbp)
	movq	-520(%rbp), %rcx
	movq	%rcx, -512(%rbp)
	movq	-512(%rbp), %rcx
	movq	16(%rax), %rdx
	movq	%rdx, -536(%rbp)
	movq	-536(%rbp), %rdx
	movq	-704(%rbp), %rsi
	movq	%rsi, -544(%rbp)
	movq	-544(%rbp), %rsi
	movq	%rcx, -632(%rbp)
	movq	%rdx, -640(%rbp)
	movq	%rsi, -648(%rbp)
	movq	-632(%rbp), %rcx
	movq	-640(%rbp), %rdx
	movq	-648(%rbp), %rsi
	movq	%rsi, -624(%rbp)
	movq	-624(%rbp), %rsi
	movq	%rcx, -600(%rbp)
	movq	%rdx, -608(%rbp)
	movq	%rsi, -616(%rbp)
	movq	-600(%rbp), %rcx
	movq	-608(%rbp), %rdx
	movq	-616(%rbp), %rsi
	movq	%rsi, -584(%rbp)
	movq	-584(%rbp), %rsi
	movq	%rcx, -560(%rbp)
	movq	%rdx, -568(%rbp)
	movq	%rsi, -576(%rbp)
	movq	-568(%rbp), %rcx
	movq	-576(%rbp), %rdx
	movq	%rdx, -552(%rbp)
	movq	-552(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	16(%rax), %rcx
	addq	$8, %rcx
	movq	%rcx, 16(%rax)
	addq	$848, %rsp              ## imm = 0x350
	popq	%rbp
	retq
LBB19_15:
	movq	-792(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table19:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset20 = Lfunc_begin1-Lfunc_begin1      ## >> Call Site 1 <<
	.long	Lset20
Lset21 = Ltmp68-Lfunc_begin1            ##   Call between Lfunc_begin1 and Ltmp68
	.long	Lset21
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset22 = Ltmp68-Lfunc_begin1            ## >> Call Site 2 <<
	.long	Lset22
Lset23 = Ltmp69-Ltmp68                  ##   Call between Ltmp68 and Ltmp69
	.long	Lset23
Lset24 = Ltmp70-Lfunc_begin1            ##     jumps to Ltmp70
	.long	Lset24
	.byte	0                       ##   On action: cleanup
Lset25 = Ltmp69-Lfunc_begin1            ## >> Call Site 3 <<
	.long	Lset25
Lset26 = Lfunc_end1-Ltmp69              ##   Call between Ltmp69 and Lfunc_end1
	.long	Lset26
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE10push_frontEOS1_
	.weak_definition	__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE10push_frontEOS1_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE10push_frontEOS1_: ## @_ZNSt3__114__split_bufferIPiNS_9allocatorIS1_EEE10push_frontEOS1_
Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception2
## BB#0:
	pushq	%rbp
Ltmp77:
	.cfi_def_cfa_offset 16
Ltmp78:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp79:
	.cfi_def_cfa_register %rbp
	subq	$880, %rsp              ## imm = 0x370
	movq	%rdi, -720(%rbp)
	movq	%rsi, -728(%rbp)
	movq	-720(%rbp), %rsi
	movq	8(%rsi), %rdi
	cmpq	(%rsi), %rdi
	movq	%rsi, -840(%rbp)        ## 8-byte Spill
	jne	LBB20_14
## BB#1:
	movq	-840(%rbp), %rax        ## 8-byte Reload
	movq	16(%rax), %rcx
	movq	%rax, -712(%rbp)
	movq	-712(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -704(%rbp)
	movq	-704(%rbp), %rdx
	movq	%rdx, -696(%rbp)
	movq	-696(%rbp), %rdx
	cmpq	(%rdx), %rcx
	jae	LBB20_5
## BB#2:
	movl	$2, %eax
	movl	%eax, %ecx
	movq	-840(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -528(%rbp)
	movq	-528(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -520(%rbp)
	movq	-520(%rbp), %rsi
	movq	%rsi, -512(%rbp)
	movq	-512(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	16(%rdx), %rdi
	subq	%rdi, %rsi
	sarq	$3, %rsi
	movq	%rsi, -736(%rbp)
	movq	-736(%rbp), %rsi
	addq	$1, %rsi
	movq	%rsi, %rax
	cqto
	idivq	%rcx
	movq	%rax, -736(%rbp)
	movq	-840(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	16(%rax), %rsi
	movq	16(%rax), %rdi
	movq	-736(%rbp), %r8
	shlq	$3, %r8
	addq	%r8, %rdi
	movq	%rcx, -488(%rbp)
	movq	%rsi, -496(%rbp)
	movq	%rdi, -504(%rbp)
	movq	-488(%rbp), %rcx
	movq	%rcx, -480(%rbp)
	movq	-480(%rbp), %rcx
	movq	-496(%rbp), %rsi
	movq	%rsi, -432(%rbp)
	movq	-432(%rbp), %rsi
	movq	-504(%rbp), %rdi
	movq	%rdi, -440(%rbp)
	movq	-440(%rbp), %rdi
	movq	%rcx, -448(%rbp)
	movq	%rsi, -456(%rbp)
	movq	%rdi, -464(%rbp)
	movq	-456(%rbp), %rcx
	movq	-448(%rbp), %rsi
	subq	%rsi, %rcx
	sarq	$3, %rcx
	movq	%rcx, -472(%rbp)
	cmpq	$0, -472(%rbp)
	jbe	LBB20_4
## BB#3:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-472(%rbp), %rdx
	movq	-464(%rbp), %rsi
	subq	%rdx, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rsi
	movq	%rsi, -464(%rbp)
	movq	-464(%rbp), %rcx
	movq	-448(%rbp), %rdx
	movq	-472(%rbp), %rsi
	shlq	$3, %rsi
	movq	%rcx, %rdi
	movq	%rsi, -848(%rbp)        ## 8-byte Spill
	movq	%rdx, %rsi
	movq	-848(%rbp), %rdx        ## 8-byte Reload
	callq	_memmove
	movq	%rax, -856(%rbp)        ## 8-byte Spill
LBB20_4:                                ## %_ZNSt3__113move_backwardIPPiS2_EET0_T_S4_S3_.exit
	movq	-464(%rbp), %rax
	movq	-840(%rbp), %rcx        ## 8-byte Reload
	movq	%rax, 8(%rcx)
	movq	-736(%rbp), %rax
	shlq	$3, %rax
	addq	16(%rcx), %rax
	movq	%rax, 16(%rcx)
	jmp	LBB20_13
LBB20_5:
	leaq	-56(%rbp), %rax
	leaq	-760(%rbp), %rcx
	leaq	-752(%rbp), %rdx
	movq	-840(%rbp), %rsi        ## 8-byte Reload
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -176(%rbp)
	movq	-176(%rbp), %rdi
	movq	%rdi, -168(%rbp)
	movq	-168(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -752(%rbp)
	movq	$1, -760(%rbp)
	movq	%rdx, -80(%rbp)
	movq	%rcx, -88(%rbp)
	movq	-80(%rbp), %rcx
	movq	-88(%rbp), %rdx
	movq	%rcx, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rcx
	movq	-72(%rbp), %rdx
	movq	%rax, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movq	%rdx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	-48(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB20_7
## BB#6:
	movq	-72(%rbp), %rax
	movq	%rax, -864(%rbp)        ## 8-byte Spill
	jmp	LBB20_8
LBB20_7:
	movq	-64(%rbp), %rax
	movq	%rax, -864(%rbp)        ## 8-byte Spill
LBB20_8:                                ## %_ZNSt3__13maxImEERKT_S3_S3_.exit
	movq	-864(%rbp), %rax        ## 8-byte Reload
	leaq	-800(%rbp), %rdi
	movq	(%rax), %rax
	movq	%rax, -744(%rbp)
	movq	-744(%rbp), %rsi
	movq	-744(%rbp), %rax
	addq	$3, %rax
	shrq	$2, %rax
	movq	-840(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	%rdx, -872(%rbp)        ## 8-byte Spill
	movq	%rax, %rdx
	movq	-872(%rbp), %rcx        ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC1EmmS4_
	leaq	-808(%rbp), %rax
	movq	-840(%rbp), %rcx        ## 8-byte Reload
	movq	8(%rcx), %rdx
	movq	%rax, -120(%rbp)
	movq	%rdx, -128(%rbp)
	movq	-120(%rbp), %rax
	movq	-128(%rbp), %rdx
	movq	%rax, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	-104(%rbp), %rax
	movq	-112(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#9:
	leaq	-832(%rbp), %rax
	movq	-840(%rbp), %rcx        ## 8-byte Reload
	movq	16(%rcx), %rdx
	movq	%rax, -152(%rbp)
	movq	%rdx, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	-160(%rbp), %rdx
	movq	%rax, -136(%rbp)
	movq	%rdx, -144(%rbp)
	movq	-136(%rbp), %rax
	movq	-144(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#10:
	movq	-808(%rbp), %rsi
	movq	-832(%rbp), %rdx
Ltmp74:
	leaq	-800(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
Ltmp75:
	jmp	LBB20_11
LBB20_11:
	leaq	-800(%rbp), %rax
	leaq	-424(%rbp), %rcx
	leaq	-328(%rbp), %rdx
	leaq	-280(%rbp), %rsi
	leaq	-232(%rbp), %rdi
	movq	-840(%rbp), %r8         ## 8-byte Reload
	movq	%r8, -216(%rbp)
	movq	%rax, -224(%rbp)
	movq	-216(%rbp), %r9
	movq	%r9, -208(%rbp)
	movq	-208(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -232(%rbp)
	movq	-224(%rbp), %r9
	movq	%r9, -192(%rbp)
	movq	-192(%rbp), %r9
	movq	(%r9), %r9
	movq	-216(%rbp), %r10
	movq	%r9, (%r10)
	movq	%rdi, -200(%rbp)
	movq	-200(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-224(%rbp), %r9
	movq	%rdi, (%r9)
	addq	$8, %r8
	movq	%rax, %rdi
	addq	$8, %rdi
	movq	%r8, -264(%rbp)
	movq	%rdi, -272(%rbp)
	movq	-264(%rbp), %rdi
	movq	%rdi, -256(%rbp)
	movq	-256(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -280(%rbp)
	movq	-272(%rbp), %rdi
	movq	%rdi, -240(%rbp)
	movq	-240(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-264(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -248(%rbp)
	movq	-248(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-272(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-840(%rbp), %rsi        ## 8-byte Reload
	addq	$16, %rsi
	movq	%rax, %rdi
	addq	$16, %rdi
	movq	%rsi, -312(%rbp)
	movq	%rdi, -320(%rbp)
	movq	-312(%rbp), %rsi
	movq	%rsi, -304(%rbp)
	movq	-304(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -328(%rbp)
	movq	-320(%rbp), %rsi
	movq	%rsi, -288(%rbp)
	movq	-288(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-312(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rdx, -296(%rbp)
	movq	-296(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-320(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-840(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -352(%rbp)
	movq	-352(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -344(%rbp)
	movq	-344(%rbp), %rsi
	movq	%rsi, -336(%rbp)
	movq	-336(%rbp), %rsi
	movq	%rax, -376(%rbp)
	movq	-376(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -368(%rbp)
	movq	-368(%rbp), %rdi
	movq	%rdi, -360(%rbp)
	movq	-360(%rbp), %rdi
	movq	%rsi, -408(%rbp)
	movq	%rdi, -416(%rbp)
	movq	-408(%rbp), %rsi
	movq	%rsi, -400(%rbp)
	movq	-400(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -424(%rbp)
	movq	-416(%rbp), %rsi
	movq	%rsi, -384(%rbp)
	movq	-384(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-408(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rcx, -392(%rbp)
	movq	-392(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-416(%rbp), %rsi
	movq	%rcx, (%rsi)
	movq	%rax, %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	jmp	LBB20_13
LBB20_12:
Ltmp76:
	leaq	-800(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -816(%rbp)
	movl	%ecx, -820(%rbp)
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	jmp	LBB20_15
LBB20_13:
	jmp	LBB20_14
LBB20_14:
	movq	-840(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -552(%rbp)
	movq	-552(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -544(%rbp)
	movq	-544(%rbp), %rcx
	movq	%rcx, -536(%rbp)
	movq	-536(%rbp), %rcx
	movq	8(%rax), %rdx
	addq	$-8, %rdx
	movq	%rdx, -560(%rbp)
	movq	-560(%rbp), %rdx
	movq	-728(%rbp), %rsi
	movq	%rsi, -568(%rbp)
	movq	-568(%rbp), %rsi
	movq	%rcx, -656(%rbp)
	movq	%rdx, -664(%rbp)
	movq	%rsi, -672(%rbp)
	movq	-656(%rbp), %rcx
	movq	-664(%rbp), %rdx
	movq	-672(%rbp), %rsi
	movq	%rsi, -648(%rbp)
	movq	-648(%rbp), %rsi
	movq	%rcx, -624(%rbp)
	movq	%rdx, -632(%rbp)
	movq	%rsi, -640(%rbp)
	movq	-624(%rbp), %rcx
	movq	-632(%rbp), %rdx
	movq	-640(%rbp), %rsi
	movq	%rsi, -608(%rbp)
	movq	-608(%rbp), %rsi
	movq	%rcx, -584(%rbp)
	movq	%rdx, -592(%rbp)
	movq	%rsi, -600(%rbp)
	movq	-592(%rbp), %rcx
	movq	-600(%rbp), %rdx
	movq	%rdx, -576(%rbp)
	movq	-576(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	8(%rax), %rcx
	addq	$-8, %rcx
	movq	%rcx, 8(%rax)
	addq	$880, %rsp              ## imm = 0x370
	popq	%rbp
	retq
LBB20_15:
	movq	-816(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end2:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table20:
Lexception2:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset27 = Lfunc_begin2-Lfunc_begin2      ## >> Call Site 1 <<
	.long	Lset27
Lset28 = Ltmp74-Lfunc_begin2            ##   Call between Lfunc_begin2 and Ltmp74
	.long	Lset28
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset29 = Ltmp74-Lfunc_begin2            ## >> Call Site 2 <<
	.long	Lset29
Lset30 = Ltmp75-Ltmp74                  ##   Call between Ltmp74 and Ltmp75
	.long	Lset30
Lset31 = Ltmp76-Lfunc_begin2            ##     jumps to Ltmp76
	.long	Lset31
	.byte	0                       ##   On action: cleanup
Lset32 = Ltmp75-Lfunc_begin2            ## >> Call Site 3 <<
	.long	Lset32
Lset33 = Lfunc_end2-Ltmp75              ##   Call between Ltmp75 and Lfunc_end2
	.long	Lset33
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC1EmmS4_
	.weak_def_can_be_hidden	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC1EmmS4_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC1EmmS4_: ## @_ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC1EmmS4_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp80:
	.cfi_def_cfa_offset 16
Ltmp81:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp82:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rcx
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC2EmmS4_
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE9push_backEOS1_
	.weak_definition	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE9push_backEOS1_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE9push_backEOS1_: ## @_ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE9push_backEOS1_
Lfunc_begin3:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception3
## BB#0:
	pushq	%rbp
Ltmp86:
	.cfi_def_cfa_offset 16
Ltmp87:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp88:
	.cfi_def_cfa_register %rbp
	subq	$848, %rsp              ## imm = 0x350
	movq	%rdi, -696(%rbp)
	movq	%rsi, -704(%rbp)
	movq	-696(%rbp), %rsi
	movq	16(%rsi), %rdi
	movq	%rsi, -688(%rbp)
	movq	-688(%rbp), %rax
	addq	$24, %rax
	movq	%rax, -680(%rbp)
	movq	-680(%rbp), %rax
	movq	%rax, -672(%rbp)
	movq	-672(%rbp), %rax
	cmpq	(%rax), %rdi
	movq	%rsi, -816(%rbp)        ## 8-byte Spill
	jne	LBB22_14
## BB#1:
	movq	-816(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	cmpq	(%rax), %rcx
	jbe	LBB22_5
## BB#2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movl	$2, %eax
	movl	%eax, %edx
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	movq	8(%rsi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	movq	%rdi, -712(%rbp)
	movq	-712(%rbp), %rdi
	addq	$1, %rdi
	movq	%rdi, %rax
	movq	%rdx, -824(%rbp)        ## 8-byte Spill
	cqto
	movq	-824(%rbp), %rdi        ## 8-byte Reload
	idivq	%rdi
	movq	%rax, -712(%rbp)
	movq	8(%rsi), %rax
	movq	16(%rsi), %r8
	movq	8(%rsi), %r9
	subq	-712(%rbp), %rcx
	shlq	$3, %rcx
	addq	%rcx, %r9
	movq	%rax, -488(%rbp)
	movq	%r8, -496(%rbp)
	movq	%r9, -504(%rbp)
	movq	-488(%rbp), %rax
	movq	%rax, -480(%rbp)
	movq	-480(%rbp), %rax
	movq	-496(%rbp), %rcx
	movq	%rcx, -432(%rbp)
	movq	-432(%rbp), %rcx
	movq	-504(%rbp), %r8
	movq	%r8, -440(%rbp)
	movq	-440(%rbp), %r8
	movq	%rax, -448(%rbp)
	movq	%rcx, -456(%rbp)
	movq	%r8, -464(%rbp)
	movq	-456(%rbp), %rax
	movq	-448(%rbp), %rcx
	subq	%rcx, %rax
	sarq	$3, %rax
	movq	%rax, -472(%rbp)
	cmpq	$0, -472(%rbp)
	jbe	LBB22_4
## BB#3:
	movq	-464(%rbp), %rax
	movq	-448(%rbp), %rcx
	movq	-472(%rbp), %rdx
	shlq	$3, %rdx
	movq	%rax, %rdi
	movq	%rcx, %rsi
	callq	_memmove
	movq	%rax, -832(%rbp)        ## 8-byte Spill
LBB22_4:                                ## %_ZNSt3__14moveIPPiS2_EET0_T_S4_S3_.exit
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-464(%rbp), %rdx
	movq	-472(%rbp), %rsi
	shlq	$3, %rsi
	addq	%rsi, %rdx
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	movq	%rdx, 16(%rsi)
	movq	-712(%rbp), %rdx
	movq	8(%rsi), %rdi
	subq	%rdx, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rdi
	movq	%rdi, 8(%rsi)
	jmp	LBB22_13
LBB22_5:
	leaq	-120(%rbp), %rax
	leaq	-736(%rbp), %rcx
	leaq	-728(%rbp), %rdx
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	movq	%rsi, -424(%rbp)
	movq	-424(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -416(%rbp)
	movq	-416(%rbp), %rdi
	movq	%rdi, -408(%rbp)
	movq	-408(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -728(%rbp)
	movq	$1, -736(%rbp)
	movq	%rdx, -144(%rbp)
	movq	%rcx, -152(%rbp)
	movq	-144(%rbp), %rcx
	movq	-152(%rbp), %rdx
	movq	%rcx, -128(%rbp)
	movq	%rdx, -136(%rbp)
	movq	-128(%rbp), %rcx
	movq	-136(%rbp), %rdx
	movq	%rax, -96(%rbp)
	movq	%rcx, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	-104(%rbp), %rax
	movq	(%rax), %rax
	movq	-112(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB22_7
## BB#6:
	movq	-136(%rbp), %rax
	movq	%rax, -840(%rbp)        ## 8-byte Spill
	jmp	LBB22_8
LBB22_7:
	movq	-128(%rbp), %rax
	movq	%rax, -840(%rbp)        ## 8-byte Spill
LBB22_8:                                ## %_ZNSt3__13maxImEERKT_S3_S3_.exit
	movq	-840(%rbp), %rax        ## 8-byte Reload
	leaq	-776(%rbp), %rdi
	movq	(%rax), %rax
	movq	%rax, -720(%rbp)
	movq	-720(%rbp), %rsi
	movq	-720(%rbp), %rax
	shrq	$2, %rax
	movq	-816(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	8(%rdx), %rcx
	movq	%rax, %rdx
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC1EmmS4_
	leaq	-784(%rbp), %rax
	movq	-816(%rbp), %rcx        ## 8-byte Reload
	movq	8(%rcx), %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-48(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#9:
	leaq	-808(%rbp), %rax
	movq	-816(%rbp), %rcx        ## 8-byte Reload
	movq	16(%rcx), %rdx
	movq	%rax, -80(%rbp)
	movq	%rdx, -88(%rbp)
	movq	-80(%rbp), %rax
	movq	-88(%rbp), %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#10:
	movq	-784(%rbp), %rsi
	movq	-808(%rbp), %rdx
Ltmp83:
	leaq	-776(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
Ltmp84:
	jmp	LBB22_11
LBB22_11:
	leaq	-776(%rbp), %rax
	leaq	-400(%rbp), %rcx
	leaq	-304(%rbp), %rdx
	leaq	-256(%rbp), %rsi
	leaq	-208(%rbp), %rdi
	movq	-816(%rbp), %r8         ## 8-byte Reload
	movq	%r8, -192(%rbp)
	movq	%rax, -200(%rbp)
	movq	-192(%rbp), %r9
	movq	%r9, -184(%rbp)
	movq	-184(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -208(%rbp)
	movq	-200(%rbp), %r9
	movq	%r9, -168(%rbp)
	movq	-168(%rbp), %r9
	movq	(%r9), %r9
	movq	-192(%rbp), %r10
	movq	%r9, (%r10)
	movq	%rdi, -176(%rbp)
	movq	-176(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-200(%rbp), %r9
	movq	%rdi, (%r9)
	addq	$8, %r8
	movq	%rax, %rdi
	addq	$8, %rdi
	movq	%r8, -240(%rbp)
	movq	%rdi, -248(%rbp)
	movq	-240(%rbp), %rdi
	movq	%rdi, -232(%rbp)
	movq	-232(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -256(%rbp)
	movq	-248(%rbp), %rdi
	movq	%rdi, -216(%rbp)
	movq	-216(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-240(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -224(%rbp)
	movq	-224(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-248(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	addq	$16, %rsi
	movq	%rax, %rdi
	addq	$16, %rdi
	movq	%rsi, -288(%rbp)
	movq	%rdi, -296(%rbp)
	movq	-288(%rbp), %rsi
	movq	%rsi, -280(%rbp)
	movq	-280(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -304(%rbp)
	movq	-296(%rbp), %rsi
	movq	%rsi, -264(%rbp)
	movq	-264(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-288(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rdx, -272(%rbp)
	movq	-272(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-296(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-816(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -328(%rbp)
	movq	-328(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -320(%rbp)
	movq	-320(%rbp), %rsi
	movq	%rsi, -312(%rbp)
	movq	-312(%rbp), %rsi
	movq	%rax, -352(%rbp)
	movq	-352(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -344(%rbp)
	movq	-344(%rbp), %rdi
	movq	%rdi, -336(%rbp)
	movq	-336(%rbp), %rdi
	movq	%rsi, -384(%rbp)
	movq	%rdi, -392(%rbp)
	movq	-384(%rbp), %rsi
	movq	%rsi, -376(%rbp)
	movq	-376(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -400(%rbp)
	movq	-392(%rbp), %rsi
	movq	%rsi, -360(%rbp)
	movq	-360(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-384(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rcx, -368(%rbp)
	movq	-368(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-392(%rbp), %rsi
	movq	%rcx, (%rsi)
	movq	%rax, %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	jmp	LBB22_13
LBB22_12:
Ltmp85:
	leaq	-776(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -792(%rbp)
	movl	%ecx, -796(%rbp)
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	jmp	LBB22_15
LBB22_13:
	jmp	LBB22_14
LBB22_14:
	movq	-816(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -528(%rbp)
	movq	-528(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -520(%rbp)
	movq	-520(%rbp), %rcx
	movq	%rcx, -512(%rbp)
	movq	-512(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	16(%rax), %rdx
	movq	%rdx, -536(%rbp)
	movq	-536(%rbp), %rdx
	movq	-704(%rbp), %rsi
	movq	%rsi, -544(%rbp)
	movq	-544(%rbp), %rsi
	movq	%rcx, -632(%rbp)
	movq	%rdx, -640(%rbp)
	movq	%rsi, -648(%rbp)
	movq	-632(%rbp), %rcx
	movq	-640(%rbp), %rdx
	movq	-648(%rbp), %rsi
	movq	%rsi, -624(%rbp)
	movq	-624(%rbp), %rsi
	movq	%rcx, -600(%rbp)
	movq	%rdx, -608(%rbp)
	movq	%rsi, -616(%rbp)
	movq	-600(%rbp), %rcx
	movq	-608(%rbp), %rdx
	movq	-616(%rbp), %rsi
	movq	%rsi, -584(%rbp)
	movq	-584(%rbp), %rsi
	movq	%rcx, -560(%rbp)
	movq	%rdx, -568(%rbp)
	movq	%rsi, -576(%rbp)
	movq	-568(%rbp), %rcx
	movq	-576(%rbp), %rdx
	movq	%rdx, -552(%rbp)
	movq	-552(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	16(%rax), %rcx
	addq	$8, %rcx
	movq	%rcx, 16(%rax)
	addq	$848, %rsp              ## imm = 0x350
	popq	%rbp
	retq
LBB22_15:
	movq	-792(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end3:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table22:
Lexception3:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset34 = Lfunc_begin3-Lfunc_begin3      ## >> Call Site 1 <<
	.long	Lset34
Lset35 = Ltmp83-Lfunc_begin3            ##   Call between Lfunc_begin3 and Ltmp83
	.long	Lset35
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset36 = Ltmp83-Lfunc_begin3            ## >> Call Site 2 <<
	.long	Lset36
Lset37 = Ltmp84-Ltmp83                  ##   Call between Ltmp83 and Ltmp84
	.long	Lset37
Lset38 = Ltmp85-Lfunc_begin3            ##     jumps to Ltmp85
	.long	Lset38
	.byte	0                       ##   On action: cleanup
Lset39 = Ltmp84-Lfunc_begin3            ## >> Call Site 3 <<
	.long	Lset39
Lset40 = Lfunc_end3-Ltmp84              ##   Call between Ltmp84 and Lfunc_end3
	.long	Lset40
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE10push_frontERKS1_
	.weak_definition	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE10push_frontERKS1_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE10push_frontERKS1_: ## @_ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE10push_frontERKS1_
Lfunc_begin4:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception4
## BB#0:
	pushq	%rbp
Ltmp92:
	.cfi_def_cfa_offset 16
Ltmp93:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp94:
	.cfi_def_cfa_register %rbp
	subq	$864, %rsp              ## imm = 0x360
	movq	%rdi, -712(%rbp)
	movq	%rsi, -720(%rbp)
	movq	-712(%rbp), %rsi
	movq	8(%rsi), %rdi
	cmpq	(%rsi), %rdi
	movq	%rsi, -832(%rbp)        ## 8-byte Spill
	jne	LBB23_14
## BB#1:
	movq	-832(%rbp), %rax        ## 8-byte Reload
	movq	16(%rax), %rcx
	movq	%rax, -704(%rbp)
	movq	-704(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -696(%rbp)
	movq	-696(%rbp), %rdx
	movq	%rdx, -688(%rbp)
	movq	-688(%rbp), %rdx
	cmpq	(%rdx), %rcx
	jae	LBB23_5
## BB#2:
	movl	$2, %eax
	movl	%eax, %ecx
	movq	-832(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -528(%rbp)
	movq	-528(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -520(%rbp)
	movq	-520(%rbp), %rsi
	movq	%rsi, -512(%rbp)
	movq	-512(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	16(%rdx), %rdi
	subq	%rdi, %rsi
	sarq	$3, %rsi
	movq	%rsi, -728(%rbp)
	movq	-728(%rbp), %rsi
	addq	$1, %rsi
	movq	%rsi, %rax
	cqto
	idivq	%rcx
	movq	%rax, -728(%rbp)
	movq	-832(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	16(%rax), %rsi
	movq	16(%rax), %rdi
	movq	-728(%rbp), %r8
	shlq	$3, %r8
	addq	%r8, %rdi
	movq	%rcx, -488(%rbp)
	movq	%rsi, -496(%rbp)
	movq	%rdi, -504(%rbp)
	movq	-488(%rbp), %rcx
	movq	%rcx, -480(%rbp)
	movq	-480(%rbp), %rcx
	movq	-496(%rbp), %rsi
	movq	%rsi, -432(%rbp)
	movq	-432(%rbp), %rsi
	movq	-504(%rbp), %rdi
	movq	%rdi, -440(%rbp)
	movq	-440(%rbp), %rdi
	movq	%rcx, -448(%rbp)
	movq	%rsi, -456(%rbp)
	movq	%rdi, -464(%rbp)
	movq	-456(%rbp), %rcx
	movq	-448(%rbp), %rsi
	subq	%rsi, %rcx
	sarq	$3, %rcx
	movq	%rcx, -472(%rbp)
	cmpq	$0, -472(%rbp)
	jbe	LBB23_4
## BB#3:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-472(%rbp), %rdx
	movq	-464(%rbp), %rsi
	subq	%rdx, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rsi
	movq	%rsi, -464(%rbp)
	movq	-464(%rbp), %rcx
	movq	-448(%rbp), %rdx
	movq	-472(%rbp), %rsi
	shlq	$3, %rsi
	movq	%rcx, %rdi
	movq	%rsi, -840(%rbp)        ## 8-byte Spill
	movq	%rdx, %rsi
	movq	-840(%rbp), %rdx        ## 8-byte Reload
	callq	_memmove
	movq	%rax, -848(%rbp)        ## 8-byte Spill
LBB23_4:                                ## %_ZNSt3__113move_backwardIPPiS2_EET0_T_S4_S3_.exit
	movq	-464(%rbp), %rax
	movq	-832(%rbp), %rcx        ## 8-byte Reload
	movq	%rax, 8(%rcx)
	movq	-728(%rbp), %rax
	shlq	$3, %rax
	addq	16(%rcx), %rax
	movq	%rax, 16(%rcx)
	jmp	LBB23_13
LBB23_5:
	leaq	-56(%rbp), %rax
	leaq	-752(%rbp), %rcx
	leaq	-744(%rbp), %rdx
	movq	-832(%rbp), %rsi        ## 8-byte Reload
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -176(%rbp)
	movq	-176(%rbp), %rdi
	movq	%rdi, -168(%rbp)
	movq	-168(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -744(%rbp)
	movq	$1, -752(%rbp)
	movq	%rdx, -80(%rbp)
	movq	%rcx, -88(%rbp)
	movq	-80(%rbp), %rcx
	movq	-88(%rbp), %rdx
	movq	%rcx, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rcx
	movq	-72(%rbp), %rdx
	movq	%rax, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movq	%rdx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	-48(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB23_7
## BB#6:
	movq	-72(%rbp), %rax
	movq	%rax, -856(%rbp)        ## 8-byte Spill
	jmp	LBB23_8
LBB23_7:
	movq	-64(%rbp), %rax
	movq	%rax, -856(%rbp)        ## 8-byte Spill
LBB23_8:                                ## %_ZNSt3__13maxImEERKT_S3_S3_.exit
	movq	-856(%rbp), %rax        ## 8-byte Reload
	leaq	-792(%rbp), %rdi
	movq	(%rax), %rax
	movq	%rax, -736(%rbp)
	movq	-736(%rbp), %rsi
	movq	-736(%rbp), %rax
	addq	$3, %rax
	shrq	$2, %rax
	movq	-832(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	8(%rdx), %rcx
	movq	%rax, %rdx
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC1EmmS4_
	leaq	-800(%rbp), %rax
	movq	-832(%rbp), %rcx        ## 8-byte Reload
	movq	8(%rcx), %rdx
	movq	%rax, -120(%rbp)
	movq	%rdx, -128(%rbp)
	movq	-120(%rbp), %rax
	movq	-128(%rbp), %rdx
	movq	%rax, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	-104(%rbp), %rax
	movq	-112(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#9:
	leaq	-824(%rbp), %rax
	movq	-832(%rbp), %rcx        ## 8-byte Reload
	movq	16(%rcx), %rdx
	movq	%rax, -152(%rbp)
	movq	%rdx, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	-160(%rbp), %rdx
	movq	%rax, -136(%rbp)
	movq	%rdx, -144(%rbp)
	movq	-136(%rbp), %rax
	movq	-144(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#10:
	movq	-800(%rbp), %rsi
	movq	-824(%rbp), %rdx
Ltmp89:
	leaq	-792(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
Ltmp90:
	jmp	LBB23_11
LBB23_11:
	leaq	-792(%rbp), %rax
	leaq	-424(%rbp), %rcx
	leaq	-328(%rbp), %rdx
	leaq	-280(%rbp), %rsi
	leaq	-232(%rbp), %rdi
	movq	-832(%rbp), %r8         ## 8-byte Reload
	movq	%r8, -216(%rbp)
	movq	%rax, -224(%rbp)
	movq	-216(%rbp), %r9
	movq	%r9, -208(%rbp)
	movq	-208(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -232(%rbp)
	movq	-224(%rbp), %r9
	movq	%r9, -192(%rbp)
	movq	-192(%rbp), %r9
	movq	(%r9), %r9
	movq	-216(%rbp), %r10
	movq	%r9, (%r10)
	movq	%rdi, -200(%rbp)
	movq	-200(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-224(%rbp), %r9
	movq	%rdi, (%r9)
	addq	$8, %r8
	movq	%rax, %rdi
	addq	$8, %rdi
	movq	%r8, -264(%rbp)
	movq	%rdi, -272(%rbp)
	movq	-264(%rbp), %rdi
	movq	%rdi, -256(%rbp)
	movq	-256(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -280(%rbp)
	movq	-272(%rbp), %rdi
	movq	%rdi, -240(%rbp)
	movq	-240(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-264(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -248(%rbp)
	movq	-248(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-272(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-832(%rbp), %rsi        ## 8-byte Reload
	addq	$16, %rsi
	movq	%rax, %rdi
	addq	$16, %rdi
	movq	%rsi, -312(%rbp)
	movq	%rdi, -320(%rbp)
	movq	-312(%rbp), %rsi
	movq	%rsi, -304(%rbp)
	movq	-304(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -328(%rbp)
	movq	-320(%rbp), %rsi
	movq	%rsi, -288(%rbp)
	movq	-288(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-312(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rdx, -296(%rbp)
	movq	-296(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-320(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-832(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -352(%rbp)
	movq	-352(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -344(%rbp)
	movq	-344(%rbp), %rsi
	movq	%rsi, -336(%rbp)
	movq	-336(%rbp), %rsi
	movq	%rax, -376(%rbp)
	movq	-376(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -368(%rbp)
	movq	-368(%rbp), %rdi
	movq	%rdi, -360(%rbp)
	movq	-360(%rbp), %rdi
	movq	%rsi, -408(%rbp)
	movq	%rdi, -416(%rbp)
	movq	-408(%rbp), %rsi
	movq	%rsi, -400(%rbp)
	movq	-400(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -424(%rbp)
	movq	-416(%rbp), %rsi
	movq	%rsi, -384(%rbp)
	movq	-384(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-408(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rcx, -392(%rbp)
	movq	-392(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-416(%rbp), %rsi
	movq	%rcx, (%rsi)
	movq	%rax, %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	jmp	LBB23_13
LBB23_12:
Ltmp91:
	leaq	-792(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -808(%rbp)
	movl	%ecx, -812(%rbp)
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	jmp	LBB23_15
LBB23_13:
	jmp	LBB23_14
LBB23_14:
	movq	-832(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -552(%rbp)
	movq	-552(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -544(%rbp)
	movq	-544(%rbp), %rcx
	movq	%rcx, -536(%rbp)
	movq	-536(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	8(%rax), %rdx
	addq	$-8, %rdx
	movq	%rdx, -560(%rbp)
	movq	-560(%rbp), %rdx
	movq	-720(%rbp), %rsi
	movq	%rcx, -648(%rbp)
	movq	%rdx, -656(%rbp)
	movq	%rsi, -664(%rbp)
	movq	-648(%rbp), %rcx
	movq	-656(%rbp), %rdx
	movq	-664(%rbp), %rsi
	movq	%rsi, -640(%rbp)
	movq	-640(%rbp), %rsi
	movq	%rcx, -616(%rbp)
	movq	%rdx, -624(%rbp)
	movq	%rsi, -632(%rbp)
	movq	-616(%rbp), %rcx
	movq	-624(%rbp), %rdx
	movq	-632(%rbp), %rsi
	movq	%rsi, -600(%rbp)
	movq	-600(%rbp), %rsi
	movq	%rcx, -576(%rbp)
	movq	%rdx, -584(%rbp)
	movq	%rsi, -592(%rbp)
	movq	-584(%rbp), %rcx
	movq	-592(%rbp), %rdx
	movq	%rdx, -568(%rbp)
	movq	-568(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	8(%rax), %rcx
	addq	$-8, %rcx
	movq	%rcx, 8(%rax)
	addq	$864, %rsp              ## imm = 0x360
	popq	%rbp
	retq
LBB23_15:
	movq	-808(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end4:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table23:
Lexception4:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset41 = Lfunc_begin4-Lfunc_begin4      ## >> Call Site 1 <<
	.long	Lset41
Lset42 = Ltmp89-Lfunc_begin4            ##   Call between Lfunc_begin4 and Ltmp89
	.long	Lset42
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset43 = Ltmp89-Lfunc_begin4            ## >> Call Site 2 <<
	.long	Lset43
Lset44 = Ltmp90-Ltmp89                  ##   Call between Ltmp89 and Ltmp90
	.long	Lset44
Lset45 = Ltmp91-Lfunc_begin4            ##     jumps to Ltmp91
	.long	Lset45
	.byte	0                       ##   On action: cleanup
Lset46 = Ltmp90-Lfunc_begin4            ## >> Call Site 3 <<
	.long	Lset46
Lset47 = Lfunc_end4-Ltmp90              ##   Call between Ltmp90 and Lfunc_end4
	.long	Lset47
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev: ## @_ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp95:
	.cfi_def_cfa_offset 16
Ltmp96:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp97:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
	.weak_definition	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_: ## @_ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp98:
	.cfi_def_cfa_offset 16
Ltmp99:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp100:
	.cfi_def_cfa_register %rbp
	subq	$112, %rsp
	movq	%rsi, -208(%rbp)
	movq	%rdx, -216(%rbp)
	movq	%rdi, -224(%rbp)
	movq	-224(%rbp), %rdx
	movq	%rdx, -200(%rbp)
	movq	-200(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -192(%rbp)
	movq	-192(%rbp), %rsi
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rsi
	movq	8(%rsi), %rsi
	movq	%rsi, -232(%rbp)
	movq	%rdx, -240(%rbp)        ## 8-byte Spill
LBB25_1:                                ## =>This Inner Loop Header: Depth=1
	leaq	-216(%rbp), %rax
	leaq	-208(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	cmpq	(%rcx), %rax
	je	LBB25_4
## BB#2:                                ##   in Loop: Header=BB25_1 Depth=1
	leaq	-208(%rbp), %rax
	movq	-232(%rbp), %rcx
	movq	-240(%rbp), %rdx        ## 8-byte Reload
	movq	16(%rdx), %rsi
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rsi
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	movq	%rcx, -136(%rbp)
	movq	%rsi, -144(%rbp)
	movq	%rax, -152(%rbp)
	movq	-136(%rbp), %rax
	movq	-144(%rbp), %rcx
	movq	-152(%rbp), %rsi
	movq	%rsi, -128(%rbp)
	movq	-128(%rbp), %rsi
	movq	%rax, -104(%rbp)
	movq	%rcx, -112(%rbp)
	movq	%rsi, -120(%rbp)
	movq	-104(%rbp), %rax
	movq	-112(%rbp), %rcx
	movq	-120(%rbp), %rsi
	movq	%rsi, -88(%rbp)
	movq	-88(%rbp), %rsi
	movq	%rax, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	-72(%rbp), %rax
	movq	-80(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, (%rax)
	movq	16(%rdx), %rax
	addq	$8, %rax
	movq	%rax, 16(%rdx)
## BB#3:                                ##   in Loop: Header=BB25_1 Depth=1
	leaq	-208(%rbp), %rax
	movq	%rax, -176(%rbp)
	movq	-176(%rbp), %rax
	movq	(%rax), %rcx
	addq	$8, %rcx
	movq	%rcx, (%rax)
	jmp	LBB25_1
LBB25_4:
	addq	$112, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC2EmmS4_
	.weak_def_can_be_hidden	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC2EmmS4_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC2EmmS4_: ## @_ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEEC2EmmS4_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp101:
	.cfi_def_cfa_offset 16
Ltmp102:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp103:
	.cfi_def_cfa_register %rbp
	subq	$256, %rsp              ## imm = 0x100
	leaq	-136(%rbp), %rax
	leaq	-168(%rbp), %r8
	movq	%rdi, -208(%rbp)
	movq	%rsi, -216(%rbp)
	movq	%rdx, -224(%rbp)
	movq	%rcx, -232(%rbp)
	movq	-208(%rbp), %rcx
	movq	%rcx, %rdx
	addq	$24, %rdx
	movq	-232(%rbp), %rsi
	movq	%rdx, -184(%rbp)
	movq	$0, -192(%rbp)
	movq	%rsi, -200(%rbp)
	movq	-184(%rbp), %rdx
	movq	-192(%rbp), %rsi
	movq	-200(%rbp), %rdi
	movq	%rdx, -160(%rbp)
	movq	%rsi, -168(%rbp)
	movq	%rdi, -176(%rbp)
	movq	-160(%rbp), %rdx
	movq	%r8, -152(%rbp)
	movq	-152(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-176(%rbp), %rdi
	movq	%rdi, -104(%rbp)
	movq	-104(%rbp), %rdi
	movq	%rdx, -128(%rbp)
	movq	%rsi, -136(%rbp)
	movq	%rdi, -144(%rbp)
	movq	-128(%rbp), %rdx
	movq	%rax, -120(%rbp)
	movq	-120(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	movq	-144(%rbp), %rax
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rax
	movq	%rax, 8(%rdx)
	cmpq	$0, -216(%rbp)
	movq	%rcx, -240(%rbp)        ## 8-byte Spill
	je	LBB26_2
## BB#1:
	movq	-240(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	-216(%rbp), %rdx
	movq	%rcx, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rcx
	movq	-72(%rbp), %rdx
	movq	%rcx, -40(%rbp)
	movq	%rdx, -48(%rbp)
	movq	$0, -56(%rbp)
	movq	-48(%rbp), %rcx
	shlq	$3, %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rdi
	callq	__Znwm
	movq	%rax, -248(%rbp)        ## 8-byte Spill
	jmp	LBB26_3
LBB26_2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -248(%rbp)        ## 8-byte Spill
	jmp	LBB26_3
LBB26_3:
	movq	-248(%rbp), %rax        ## 8-byte Reload
	movq	-240(%rbp), %rcx        ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	(%rcx), %rax
	movq	-224(%rbp), %rdx
	shlq	$3, %rdx
	addq	%rdx, %rax
	movq	%rax, 16(%rcx)
	movq	%rax, 8(%rcx)
	movq	(%rcx), %rax
	movq	-216(%rbp), %rdx
	shlq	$3, %rdx
	addq	%rdx, %rax
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -88(%rbp)
	movq	-88(%rbp), %rdx
	movq	%rdx, -80(%rbp)
	movq	-80(%rbp), %rdx
	movq	%rax, (%rdx)
	addq	$256, %rsp              ## imm = 0x100
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED2Ev
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED2Ev: ## @_ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp104:
	.cfi_def_cfa_offset 16
Ltmp105:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp106:
	.cfi_def_cfa_register %rbp
	subq	$320, %rsp              ## imm = 0x140
	movq	%rdi, -280(%rbp)
	movq	-280(%rbp), %rdi
	movq	%rdi, -272(%rbp)
	movq	-272(%rbp), %rax
	movq	8(%rax), %rcx
	movq	%rax, -248(%rbp)
	movq	%rcx, -256(%rbp)
	movq	-248(%rbp), %rax
	movq	-256(%rbp), %rcx
	movq	%rax, -232(%rbp)
	movq	%rcx, -240(%rbp)
	movq	-232(%rbp), %rax
	movq	%rdi, -288(%rbp)        ## 8-byte Spill
	movq	%rax, -296(%rbp)        ## 8-byte Spill
LBB27_1:                                ## =>This Inner Loop Header: Depth=1
	movq	-240(%rbp), %rax
	movq	-296(%rbp), %rcx        ## 8-byte Reload
	cmpq	16(%rcx), %rax
	je	LBB27_3
## BB#2:                                ##   in Loop: Header=BB27_1 Depth=1
	movq	-296(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -208(%rbp)
	movq	-208(%rbp), %rcx
	movq	%rcx, -200(%rbp)
	movq	-200(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	16(%rax), %rdx
	addq	$-8, %rdx
	movq	%rdx, 16(%rax)
	movq	%rdx, -192(%rbp)
	movq	-192(%rbp), %rdx
	movq	%rcx, -160(%rbp)
	movq	%rdx, -168(%rbp)
	movq	-160(%rbp), %rcx
	movq	-168(%rbp), %rdx
	movq	%rcx, -144(%rbp)
	movq	%rdx, -152(%rbp)
	movq	-144(%rbp), %rcx
	movq	-152(%rbp), %rdx
	movq	%rcx, -120(%rbp)
	movq	%rdx, -128(%rbp)
	jmp	LBB27_1
LBB27_3:                                ## %_ZNSt3__114__split_bufferIPiRNS_9allocatorIS1_EEE5clearEv.exit
	movq	-288(%rbp), %rax        ## 8-byte Reload
	cmpq	$0, (%rax)
	je	LBB27_6
## BB#4:
	movq	-288(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	(%rax), %rdx
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rsi
	movq	%rsi, -24(%rbp)
	movq	-24(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %rsi
	subq	%rsi, %rdi
	sarq	$3, %rdi
	movq	%rcx, -304(%rbp)        ## 8-byte Spill
	movq	%rdx, -312(%rbp)        ## 8-byte Spill
	movq	%rdi, -320(%rbp)        ## 8-byte Spill
## BB#5:
	movq	-304(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -72(%rbp)
	movq	-312(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -80(%rbp)
	movq	-320(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -88(%rbp)
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %rdi
	movq	-88(%rbp), %r8
	movq	%rsi, -48(%rbp)
	movq	%rdi, -56(%rbp)
	movq	%r8, -64(%rbp)
	movq	-56(%rbp), %rsi
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rdi
	callq	__ZdlPv
LBB27_6:
	addq	$320, %rsp              ## imm = 0x140
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15dequeIiNS_9allocatorIiEEE9pop_frontEv
	.weak_definition	__ZNSt3__15dequeIiNS_9allocatorIiEEE9pop_frontEv
	.p2align	4, 0x90
__ZNSt3__15dequeIiNS_9allocatorIiEEE9pop_frontEv: ## @_ZNSt3__15dequeIiNS_9allocatorIiEEE9pop_frontEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp107:
	.cfi_def_cfa_offset 16
Ltmp108:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp109:
	.cfi_def_cfa_register %rbp
	subq	$288, %rsp              ## imm = 0x120
	movq	%rdi, -264(%rbp)
	movq	-264(%rbp), %rdi
	movq	%rdi, %rax
	movq	%rax, -256(%rbp)
	movq	-256(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -248(%rbp)
	movq	-248(%rbp), %rax
	movq	%rax, -240(%rbp)
	movq	-240(%rbp), %rax
	movq	%rax, -272(%rbp)
	movq	-272(%rbp), %rax
	movq	%rdi, %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	32(%rdi), %rdx
	shrq	$10, %rdx
	movq	(%rcx,%rdx,8), %rcx
	movq	32(%rdi), %rdx
	andq	$1023, %rdx             ## imm = 0x3FF
	shlq	$2, %rdx
	addq	%rdx, %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	%rax, -56(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	%rax, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	%rax, -16(%rbp)
	movq	%rcx, -24(%rbp)
	movq	%rdi, %rax
	movq	%rax, -104(%rbp)
	movq	-104(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	(%rax), %rcx
	addq	$-1, %rcx
	movq	%rcx, (%rax)
	movq	32(%rdi), %rax
	addq	$1, %rax
	movq	%rax, 32(%rdi)
	cmpq	$2048, %rax             ## imm = 0x800
	movq	%rdi, -280(%rbp)        ## 8-byte Spill
	jb	LBB28_2
## BB#1:
	movq	-272(%rbp), %rax
	movq	-280(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -112(%rbp)
	movq	-112(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	(%rcx), %rcx
	movq	%rax, -160(%rbp)
	movq	%rcx, -168(%rbp)
	movq	$1024, -176(%rbp)       ## imm = 0x400
	movq	-160(%rbp), %rax
	movq	-168(%rbp), %rcx
	movq	-176(%rbp), %rdx
	movq	%rax, -136(%rbp)
	movq	%rcx, -144(%rbp)
	movq	%rdx, -152(%rbp)
	movq	-144(%rbp), %rax
	movq	%rax, -128(%rbp)
	movq	-128(%rbp), %rdi
	callq	__ZdlPv
	movq	-280(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -232(%rbp)
	movq	-232(%rbp), %rax
	movq	8(%rax), %rcx
	addq	$8, %rcx
	movq	%rax, -200(%rbp)
	movq	%rcx, -208(%rbp)
	movq	-200(%rbp), %rax
	movq	-208(%rbp), %rcx
	movq	%rax, -184(%rbp)
	movq	%rcx, -192(%rbp)
	movq	-184(%rbp), %rax
	movq	-192(%rbp), %rcx
	movq	%rcx, 8(%rax)
	movq	-280(%rbp), %rax        ## 8-byte Reload
	movq	32(%rax), %rcx
	subq	$1024, %rcx             ## imm = 0x400
	movq	%rcx, 32(%rax)
LBB28_2:
	addq	$288, %rsp              ## imm = 0x120
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90
__GLOBAL__sub_I_math.ii:                ## @_GLOBAL__sub_I_math.ii
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp110:
	.cfi_def_cfa_offset 16
Ltmp111:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp112:
	.cfi_def_cfa_register %rbp
	callq	___cxx_global_var_init
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_que_arr                ## @que_arr
.zerofill __DATA,__common,_que_arr,96,4
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

L_.str.1:                               ## @.str.1
	.asciz	"@@@@ %d %d\n"

L_.str.2:                               ## @.str.2
	.asciz	"%d "

L_.str.3:                               ## @.str.3
	.asciz	"\n"

	.section	__DATA,__mod_init_func,mod_init_funcs
	.p2align	3
	.quad	__GLOBAL__sub_I_math.ii

.subsections_via_symbols
