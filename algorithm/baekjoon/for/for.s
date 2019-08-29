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
	movl	$128, %esi
	movq	___stdinp@GOTPCREL(%rip), %rax
	leaq	-160(%rbp), %rcx
	xorl	%edx, %edx
	movl	$128, %edi
	movl	%edi, %r8d
	movl	$11, %edi
	movl	%edi, %r9d
	leaq	-19(%rbp), %r10
	movq	___stack_chk_guard@GOTPCREL(%rip), %r11
	movq	(%r11), %r11
	movq	%r11, -8(%rbp)
	movl	$0, -164(%rbp)
	movq	%r10, %rdi
	movl	%esi, -176(%rbp)        ## 4-byte Spill
	movl	%edx, %esi
	movl	%edx, -180(%rbp)        ## 4-byte Spill
	movq	%r9, %rdx
	movq	%r8, -192(%rbp)         ## 8-byte Spill
	movq	%rax, -200(%rbp)        ## 8-byte Spill
	movq	%rcx, -208(%rbp)        ## 8-byte Spill
	callq	_memset
	movq	-208(%rbp), %rax        ## 8-byte Reload
	movq	%rax, %rdi
	movl	-180(%rbp), %esi        ## 4-byte Reload
	movq	-192(%rbp), %rdx        ## 8-byte Reload
	callq	_memset
	movq	-200(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rdx
	movq	-208(%rbp), %rdi        ## 8-byte Reload
	movl	-176(%rbp), %esi        ## 4-byte Reload
	callq	_fgets
	leaq	-160(%rbp), %rdi
	movq	%rax, -216(%rbp)        ## 8-byte Spill
	callq	_strlen
	subq	$1, %rax
	movb	$0, -160(%rbp,%rax)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	$11, %eax
	movl	%eax, %ecx
	xorl	%edx, %edx
	leaq	L_.str(%rip), %r8
	leaq	-160(%rbp), %r9
	leaq	-19(%rbp), %rdi
	movq	%rcx, %rsi
	movb	$0, %al
	callq	___snprintf_chk
	leaq	L_.str.1(%rip), %rdi
	leaq	-19(%rbp), %rsi
	movl	%eax, -220(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	$128, %edx
	movl	%edx, %ecx
	leaq	-160(%rbp), %rsi
	movq	%rsi, %rdi
	addq	$10, %rdi
	movq	%rdi, -232(%rbp)        ## 8-byte Spill
	movq	%rsi, %rdi
	movl	%eax, -236(%rbp)        ## 4-byte Spill
	movq	%rcx, -248(%rbp)        ## 8-byte Spill
	movq	%rsi, -256(%rbp)        ## 8-byte Spill
	callq	_strlen
	movq	-256(%rbp), %rdi        ## 8-byte Reload
	movq	-232(%rbp), %rsi        ## 8-byte Reload
	movq	%rax, %rdx
	movq	-248(%rbp), %rcx        ## 8-byte Reload
	callq	___memmove_chk
	leaq	-160(%rbp), %rdi
	movq	%rax, -264(%rbp)        ## 8-byte Spill
	callq	_strlen
	cmpq	$10, %rax
	ja	LBB0_3
## BB#2:
	leaq	L_.str.1(%rip), %rdi
	leaq	-160(%rbp), %rsi
	movb	$0, %al
	callq	_printf
	movl	%eax, -268(%rbp)        ## 4-byte Spill
	jmp	LBB0_4
LBB0_3:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_1
LBB0_4:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB0_6
## BB#5:                                ## %SP_return
	xorl	%eax, %eax
	addq	$272, %rsp              ## imm = 0x110
	popq	%rbp
	retq
LBB0_6:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%s"

L_.str.1:                               ## @.str.1
	.asciz	"%s\n"


.subsections_via_symbols
