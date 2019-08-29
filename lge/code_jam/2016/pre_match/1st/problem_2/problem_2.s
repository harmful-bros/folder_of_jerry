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
	subq	$160, %rsp
	xorl	%eax, %eax
	movl	$64, %ecx
	movl	%ecx, %edx
	leaq	-80(%rbp), %r8
	movq	___stack_chk_guard@GOTPCREL(%rip), %r9
	movq	(%r9), %r9
	movq	%r9, -8(%rbp)
	movl	$0, -84(%rbp)
	movl	%edi, -88(%rbp)
	movq	%rsi, -96(%rbp)
	movl	$0, -104(%rbp)
	movl	$0, -108(%rbp)
	movq	$0, -120(%rbp)
	movq	$0, -128(%rbp)
	movq	$0, -136(%rbp)
	movq	%r8, %rdi
	movl	%eax, %esi
	callq	_memset
	cmpl	$2, -88(%rbp)
	je	LBB0_2
## BB#1:
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -140(%rbp)        ## 4-byte Spill
	jmp	LBB0_17
LBB0_2:
	leaq	L_.str.1(%rip), %rsi
	movq	___stdinp@GOTPCREL(%rip), %rax
	movq	-96(%rbp), %rcx
	movq	8(%rcx), %rdi
	movq	(%rax), %rdx
	callq	_freopen
	movq	%rax, -120(%rbp)
	cmpq	$0, -120(%rbp)
	jne	LBB0_4
## BB#3:
	jmp	LBB0_17
LBB0_4:
	leaq	L_.str.2(%rip), %rsi
	movq	-96(%rbp), %rax
	movq	8(%rax), %rdi
	callq	_strstr
	movl	$64, %ecx
	movl	%ecx, %esi
	xorl	%edx, %edx
	leaq	L_.str.3(%rip), %r8
	leaq	-80(%rbp), %rdi
	movq	%rax, -136(%rbp)
	movq	-136(%rbp), %rax
	movq	-96(%rbp), %r9
	movq	8(%r9), %r9
	subq	%r9, %rax
	movq	-96(%rbp), %r9
	movq	8(%r9), %r9
	movb	$0, (%r9,%rax)
	movq	-96(%rbp), %rax
	movq	8(%rax), %r9
	movq	%rsi, -152(%rbp)        ## 8-byte Spill
	movq	-152(%rbp), %rcx        ## 8-byte Reload
	movb	$0, %al
	callq	___snprintf_chk
	leaq	L_.str.4(%rip), %rsi
	leaq	-80(%rbp), %rdi
	movl	%eax, -156(%rbp)        ## 4-byte Spill
	callq	_fopen
	movq	%rax, -128(%rbp)
	cmpq	$0, -128(%rbp)
	jne	LBB0_6
## BB#5:
	jmp	LBB0_17
LBB0_6:
	leaq	-104(%rbp), %rdi
	movl	$65, %esi
	callq	__input_case
	cmpl	$0, %eax
	jge	LBB0_8
## BB#7:
	jmp	LBB0_17
LBB0_8:
	movl	$0, -100(%rbp)
	movl	$0, -100(%rbp)
LBB0_9:                                 ## =>This Inner Loop Header: Depth=1
	movl	-100(%rbp), %eax
	cmpl	-104(%rbp), %eax
	jge	LBB0_16
## BB#10:                               ##   in Loop: Header=BB0_9 Depth=1
	leaq	-108(%rbp), %rdi
	movl	$100000, %esi           ## imm = 0x186A0
	callq	__input_case
	cmpl	$0, %eax
	jge	LBB0_12
## BB#11:
	jmp	LBB0_17
LBB0_12:                                ##   in Loop: Header=BB0_9 Depth=1
	movq	-128(%rbp), %rdi
	movl	-108(%rbp), %esi
	callq	__find_to_matching_figure
	cmpl	$0, %eax
	jge	LBB0_14
## BB#13:
	jmp	LBB0_17
LBB0_14:                                ##   in Loop: Header=BB0_9 Depth=1
	jmp	LBB0_15
LBB0_15:                                ##   in Loop: Header=BB0_9 Depth=1
	movl	-100(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -100(%rbp)
	jmp	LBB0_9
LBB0_16:
	jmp	LBB0_17
LBB0_17:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB0_19
## BB#18:                               ## %SP_return
	xorl	%eax, %eax
	addq	$160, %rsp
	popq	%rbp
	retq
LBB0_19:                                ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.p2align	4, 0x90
__input_case:                           ## @_input_case
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
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	cmpq	$0, -16(%rbp)
	jne	LBB1_2
## BB#1:
	jmp	LBB1_5
LBB1_2:
	leaq	L_.str.6(%rip), %rdi
	movq	-16(%rbp), %rsi
	movb	$0, %al
	callq	_scanf
	movl	$1, %esi
	movl	$100000, %ecx           ## imm = 0x186A0
	movl	$65, %edx
	movq	-16(%rbp), %rdi
	movl	(%rdi), %edi
	cmpl	$65, -20(%rbp)
	cmovel	%edx, %ecx
	movl	%ecx, %edx
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	callq	__check_overflow
	cmpl	$0, %eax
	jge	LBB1_4
## BB#3:
	jmp	LBB1_5
LBB1_4:
	movl	$0, -4(%rbp)
	jmp	LBB1_6
LBB1_5:
	movl	$-1, -4(%rbp)
LBB1_6:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__find_to_matching_figure:              ## @_find_to_matching_figure
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
	subq	$144, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	%rdi, -96(%rbp)
	movl	%esi, -100(%rbp)
	cmpq	$0, -96(%rbp)
	jne	LBB2_2
## BB#1:
	jmp	LBB2_14
LBB2_2:
	xorl	%esi, %esi
	movl	$64, %eax
	movl	%eax, %edx
	leaq	-80(%rbp), %rcx
	movq	%rcx, %rdi
	callq	_memset
	movslq	-100(%rbp), %rcx
	shlq	$2, %rcx
	movq	%rcx, %rdi
	callq	__allocate_memory
	movq	%rax, -80(%rbp)
	movslq	-100(%rbp), %rax
	shlq	$2, %rax
	movq	%rax, %rdi
	callq	__allocate_memory
	movq	%rax, -48(%rbp)
	cmpq	$0, -80(%rbp)
	je	LBB2_4
## BB#3:
	cmpq	$0, -48(%rbp)
	jne	LBB2_5
LBB2_4:
	jmp	LBB2_14
LBB2_5:
	leaq	-80(%rbp), %rdi
	movl	-100(%rbp), %esi
	callq	__set_data_in_array
	cmpl	$0, %eax
	jge	LBB2_7
## BB#6:
	jmp	LBB2_14
LBB2_7:
	leaq	-80(%rbp), %rax
	addq	$32, %rax
	movl	-100(%rbp), %esi
	movq	%rax, %rdi
	callq	__set_data_in_array
	cmpl	$0, %eax
	jge	LBB2_9
## BB#8:
	jmp	LBB2_14
LBB2_9:
	movb	$1, %al
	movq	-96(%rbp), %rdi
	movq	-56(%rbp), %rcx
	cmpq	-24(%rbp), %rcx
	movq	%rdi, -112(%rbp)        ## 8-byte Spill
	movb	%al, -113(%rbp)         ## 1-byte Spill
	jne	LBB2_13
## BB#10:
	movb	$1, %al
	movl	-72(%rbp), %ecx
	cmpl	-40(%rbp), %ecx
	movb	%al, -113(%rbp)         ## 1-byte Spill
	jne	LBB2_13
## BB#11:
	movb	$1, %al
	movl	-68(%rbp), %ecx
	cmpl	-36(%rbp), %ecx
	movb	%al, -113(%rbp)         ## 1-byte Spill
	jne	LBB2_13
## BB#12:
	movl	-64(%rbp), %eax
	cmpl	-32(%rbp), %eax
	setne	%cl
	movb	%cl, -113(%rbp)         ## 1-byte Spill
LBB2_13:
	movb	-113(%rbp), %al         ## 1-byte Reload
	leaq	L_.str.5(%rip), %rsi
	movl	$1, %ecx
	xorl	%edx, %edx
	testb	$1, %al
	cmovnel	%edx, %ecx
	movq	-112(%rbp), %rdi        ## 8-byte Reload
	movl	%ecx, %edx
	movb	$0, %al
	callq	_fprintf
	leaq	-80(%rbp), %rsi
	addq	$32, %rsi
	movq	%rsi, %rdi
	movl	%eax, -120(%rbp)        ## 4-byte Spill
	callq	__free_memory
	leaq	-80(%rbp), %rsi
	movq	%rsi, %rdi
	movl	%eax, -124(%rbp)        ## 4-byte Spill
	callq	__free_memory
	movl	$0, -84(%rbp)
	movl	%eax, -128(%rbp)        ## 4-byte Spill
	jmp	LBB2_15
LBB2_14:
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	callq	__free_memory
	movq	-80(%rbp), %rdi
	movl	%eax, -132(%rbp)        ## 4-byte Spill
	callq	__free_memory
	movl	$-1, -84(%rbp)
	movl	%eax, -136(%rbp)        ## 4-byte Spill
LBB2_15:
	movl	-84(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -140(%rbp)        ## 4-byte Spill
	jne	LBB2_17
## BB#16:                               ## %SP_return
	movl	-140(%rbp), %eax        ## 4-byte Reload
	addq	$144, %rsp
	popq	%rbp
	retq
LBB2_17:                                ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.p2align	4, 0x90
__allocate_memory:                      ## @_allocate_memory
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
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_malloc
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	LBB3_2
## BB#1:
	jmp	LBB3_3
LBB3_2:
	xorl	%esi, %esi
	movq	$-1, %rcx
	movq	-16(%rbp), %rdi
	movq	-8(%rbp), %rdx
	callq	___memset_chk
	movq	%rax, -24(%rbp)         ## 8-byte Spill
LBB3_3:
	movq	-16(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__set_data_in_array:                    ## @_set_data_in_array
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
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	cmpq	$0, -16(%rbp)
	jne	LBB4_2
## BB#1:
	jmp	LBB4_19
LBB4_2:
	movl	$0, -24(%rbp)
LBB4_3:                                 ## =>This Inner Loop Header: Depth=1
	movl	-24(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jge	LBB4_16
## BB#4:                                ##   in Loop: Header=BB4_3 Depth=1
	leaq	L_.str.6(%rip), %rdi
	movslq	-24(%rbp), %rax
	movq	-16(%rbp), %rcx
	shlq	$2, %rax
	addq	(%rcx), %rax
	movq	%rax, %rsi
	movb	$0, %al
	callq	_scanf
	movslq	-24(%rbp), %rcx
	movq	-16(%rbp), %rsi
	movq	(%rsi), %rsi
	movl	(%rsi,%rcx,4), %edi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	callq	_abs
	movl	%eax, -28(%rbp)
	movslq	-28(%rbp), %rcx
	movq	-16(%rbp), %rsi
	addq	24(%rsi), %rcx
	movq	%rcx, 24(%rsi)
	cmpl	$0, -24(%rbp)
	je	LBB4_13
## BB#5:                                ##   in Loop: Header=BB4_3 Depth=1
	movq	-16(%rbp), %rax
	movl	12(%rax), %ecx
	cmpl	-28(%rbp), %ecx
	jle	LBB4_7
## BB#6:                                ##   in Loop: Header=BB4_3 Depth=1
	movl	-28(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 12(%rcx)
	jmp	LBB4_10
LBB4_7:                                 ##   in Loop: Header=BB4_3 Depth=1
	movq	-16(%rbp), %rax
	movl	16(%rax), %ecx
	cmpl	-28(%rbp), %ecx
	jge	LBB4_9
## BB#8:                                ##   in Loop: Header=BB4_3 Depth=1
	movl	-28(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 16(%rcx)
LBB4_9:                                 ##   in Loop: Header=BB4_3 Depth=1
	jmp	LBB4_10
LBB4_10:                                ##   in Loop: Header=BB4_3 Depth=1
	movslq	-24(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	(%rcx), %rcx
	movl	(%rcx,%rax,4), %edi
	callq	__check_sign
	movl	%eax, -40(%rbp)
	movl	-36(%rbp), %eax
	cmpl	-40(%rbp), %eax
	je	LBB4_12
## BB#11:                               ##   in Loop: Header=BB4_3 Depth=1
	movq	-16(%rbp), %rax
	movl	8(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, 8(%rax)
	movl	-40(%rbp), %ecx
	movl	%ecx, -36(%rbp)
LBB4_12:                                ##   in Loop: Header=BB4_3 Depth=1
	jmp	LBB4_14
LBB4_13:                                ##   in Loop: Header=BB4_3 Depth=1
	movl	-28(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 16(%rcx)
	movq	-16(%rbp), %rcx
	movl	%eax, 12(%rcx)
	movq	-16(%rbp), %rcx
	movq	(%rcx), %rcx
	movl	(%rcx), %edi
	callq	__check_sign
	movl	%eax, -36(%rbp)
	movl	%eax, -32(%rbp)
LBB4_14:                                ##   in Loop: Header=BB4_3 Depth=1
	jmp	LBB4_15
LBB4_15:                                ##   in Loop: Header=BB4_3 Depth=1
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	jmp	LBB4_3
LBB4_16:
	movl	-32(%rbp), %eax
	cmpl	-40(%rbp), %eax
	je	LBB4_18
## BB#17:
	movq	-16(%rbp), %rax
	movl	8(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, 8(%rax)
LBB4_18:
	movl	$0, -4(%rbp)
	jmp	LBB4_20
LBB4_19:
	movl	$-1, -4(%rbp)
LBB4_20:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__free_memory:                          ## @_free_memory
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
	subq	$16, %rsp
	movq	%rdi, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	LBB5_2
## BB#1:
	jmp	LBB5_5
LBB5_2:
	movq	-16(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB5_4
## BB#3:
	movq	-16(%rbp), %rax
	movq	(%rax), %rdi
	callq	_free
	movq	-16(%rbp), %rax
	movq	$0, (%rax)
LBB5_4:
	movl	$0, -4(%rbp)
	jmp	LBB5_6
LBB5_5:
	movl	$-1, -4(%rbp)
LBB5_6:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__check_sign:                           ## @_check_sign
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
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	sarl	$31, %edi
	movl	%edi, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__check_overflow:                       ## @_check_overflow
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
	movb	$1, %al
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	-4(%rbp), %edx
	cmpl	-8(%rbp), %edx
	movb	%al, -13(%rbp)          ## 1-byte Spill
	jl	LBB7_2
## BB#1:
	movl	-4(%rbp), %eax
	cmpl	-12(%rbp), %eax
	setg	%cl
	movb	%cl, -13(%rbp)          ## 1-byte Spill
LBB7_2:
	movb	-13(%rbp), %al          ## 1-byte Reload
	xorl	%ecx, %ecx
	movl	$4294967295, %edx       ## imm = 0xFFFFFFFF
	testb	$1, %al
	cmovnel	%edx, %ecx
	movl	%ecx, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Argument number error.\n"

L_.str.1:                               ## @.str.1
	.asciz	"r"

L_.str.2:                               ## @.str.2
	.asciz	"."

L_.str.3:                               ## @.str.3
	.asciz	"%s.out"

L_.str.4:                               ## @.str.4
	.asciz	"w"

L_.str.5:                               ## @.str.5
	.asciz	"%d\n"

L_.str.6:                               ## @.str.6
	.asciz	"%d"


.subsections_via_symbols
