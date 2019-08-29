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
	subq	$32, %rsp
	leaq	L_.str(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movl	$0, -4(%rbp)
	movb	$0, %al
	callq	_scanf
	movl	$6, -12(%rbp)
	movl	$12, -16(%rbp)
	movl	-8(%rbp), %ecx
	subl	$1, %ecx
	movl	%ecx, %edi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	callq	__print_block
	movl	$1, %edi
	callq	__print_first_line
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	movl	$1, %edi
	callq	__print_second_line
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	movl	$1, %edi
	callq	__print_third_line
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_first_line
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	movl	$1, %edi
	callq	__print_first_line
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
	movl	-12(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -12(%rbp)
	movl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_second_line
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	movl	$1, %edi
	callq	__print_second_line
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
	movl	-12(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -12(%rbp)
	movl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_third_line
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	movl	$1, %edi
	callq	__print_third_line
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
	movl	-12(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -12(%rbp)
	movl	$6, -12(%rbp)
	movl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_first_line
	movl	-16(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	movl	$1, %edi
	callq	__print_first_line
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
	movl	-16(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -16(%rbp)
	movl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_second_line
	movl	-16(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	movl	$1, %edi
	callq	__print_second_line
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
	movl	-16(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -16(%rbp)
	movl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_third_line
	movl	-16(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	movl	$1, %edi
	callq	__print_third_line
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
	movl	-16(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -16(%rbp)
	movl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_first_line
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_first_line
	movl	-16(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_first_line
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	movl	$1, %edi
	callq	__print_first_line
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
	movl	-12(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -12(%rbp)
	movl	-16(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -16(%rbp)
	movl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_second_line
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_second_line
	movl	-16(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_second_line
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	movl	$1, %edi
	callq	__print_second_line
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
	movl	-12(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -12(%rbp)
	movl	-16(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -16(%rbp)
	movl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_third_line
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_third_line
	movl	-16(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	xorl	%edi, %edi
	callq	__print_third_line
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	callq	__print_block
	movl	$1, %edi
	callq	__print_third_line
	xorl	%eax, %eax
	movl	-8(%rbp), %ecx
	addl	$-1, %ecx
	movl	%ecx, -8(%rbp)
	movl	-12(%rbp), %ecx
	subl	$2, %ecx
	movl	%ecx, -12(%rbp)
	movl	-16(%rbp), %ecx
	subl	$2, %ecx
	movl	%ecx, -16(%rbp)
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__print_block:                          ## @_print_block
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
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	$0, -8(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	LBB1_4
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -12(%rbp)         ## 4-byte Spill
## BB#3:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB1_1
LBB1_4:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__print_first_line:                     ## @_print_first_line
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
	leaq	L_.str.2(%rip), %rax
	movl	%edi, -4(%rbp)
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	cmpl	$0, -4(%rbp)
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	je	LBB2_2
## BB#1:
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -12(%rbp)         ## 4-byte Spill
LBB2_2:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__print_second_line:                    ## @_print_second_line
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
	subq	$16, %rsp
	leaq	L_.str.4(%rip), %rax
	movl	%edi, -4(%rbp)
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	cmpl	$0, -4(%rbp)
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	je	LBB3_2
## BB#1:
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -12(%rbp)         ## 4-byte Spill
LBB3_2:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__print_third_line:                     ## @_print_third_line
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
	subq	$16, %rsp
	leaq	L_.str.5(%rip), %rax
	movl	%edi, -4(%rbp)
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	cmpl	$0, -4(%rbp)
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	je	LBB4_2
## BB#1:
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -12(%rbp)         ## 4-byte Spill
LBB4_2:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

L_.str.1:                               ## @.str.1
	.asciz	" "

L_.str.2:                               ## @.str.2
	.asciz	"*"

L_.str.3:                               ## @.str.3
	.asciz	"\n"

L_.str.4:                               ## @.str.4
	.asciz	"* *"

L_.str.5:                               ## @.str.5
	.asciz	"*****"


.subsections_via_symbols
