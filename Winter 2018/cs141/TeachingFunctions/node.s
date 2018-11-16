	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movl	$1, %edi
	movl	$0, -4(%rbp)
	callq	_CreateNode
	movq	%rax, %rdi
	callq	_Insert
	movl	$4, %edi
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	callq	_CreateNode
	movq	%rax, %rdi
	callq	_Insert
	movl	$2, %edi
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	callq	_CreateNode
	movq	%rax, %rdi
	callq	_Insert
	movl	$5, %edi
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	callq	_CreateNode
	movq	%rax, %rdi
	callq	_Insert
	movl	$3, %edi
	movq	%rax, -40(%rbp)         ## 8-byte Spill
	callq	_CreateNode
	movq	%rax, %rdi
	callq	_Insert
	movq	_ptrFirst(%rip), %rdi
	movq	%rax, -48(%rbp)         ## 8-byte Spill
	callq	_PrintListRecursive
	movq	_ptrFirst(%rip), %rdi
	movq	%rax, -56(%rbp)         ## 8-byte Spill
	callq	_ClearListRecursive
	xorl	%ecx, %ecx
	movq	%rax, -64(%rbp)         ## 8-byte Spill
	movl	%ecx, %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_Insert
	.p2align	4, 0x90
_Insert:                                ## @Insert
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	$0, -16(%rbp)
	callq	_isEmpty
	cmpl	$0, %eax
	je	LBB1_2
## BB#1:
	movq	-8(%rbp), %rax
	movq	%rax, _ptrFirst(%rip)
	movq	-8(%rbp), %rax
	movq	%rax, _ptrLast(%rip)
	jmp	LBB1_12
LBB1_2:
	movq	-8(%rbp), %rax
	movl	(%rax), %ecx
	movq	_ptrFirst(%rip), %rax
	cmpl	(%rax), %ecx
	jg	LBB1_4
## BB#3:
	movq	-8(%rbp), %rdi
	callq	_AddEnd
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	jmp	LBB1_11
LBB1_4:
	movq	-8(%rbp), %rax
	movl	(%rax), %ecx
	movq	_ptrLast(%rip), %rax
	cmpl	(%rax), %ecx
	jl	LBB1_6
## BB#5:
	movq	-8(%rbp), %rdi
	callq	_AddEnd
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	jmp	LBB1_10
LBB1_6:
	movq	_ptrFirst(%rip), %rax
	movq	%rax, -16(%rbp)
LBB1_7:                                 ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movl	(%rax), %ecx
	movq	-8(%rbp), %rax
	cmpl	(%rax), %ecx
	jg	LBB1_9
## BB#8:                                ##   in Loop: Header=BB1_7 Depth=1
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	LBB1_7
LBB1_9:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	%rax, 8(%rcx)
LBB1_10:
	jmp	LBB1_11
LBB1_11:
	jmp	LBB1_12
LBB1_12:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_CreateNode
	.p2align	4, 0x90
_CreateNode:                            ## @CreateNode
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$16, %eax
	movl	%eax, %ecx
	movl	%edi, -4(%rbp)
	movq	%rcx, %rdi
	callq	_malloc
	movq	%rax, -16(%rbp)
	movl	-4(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	movq	-16(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-16(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_PrintListRecursive
	.p2align	4, 0x90
_PrintListRecursive:                    ## @PrintListRecursive
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi9:
	.cfi_def_cfa_offset 16
Lcfi10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi11:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	LBB3_2
## BB#1:
	leaq	L_.str(%rip), %rdi
	movq	-8(%rbp), %rax
	movl	(%rax), %esi
	movb	$0, %al
	callq	_printf
	movq	-8(%rbp), %rdi
	movq	8(%rdi), %rdi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	callq	_PrintListRecursive
	movq	%rax, -24(%rbp)         ## 8-byte Spill
LBB3_2:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_ClearListRecursive
	.p2align	4, 0x90
_ClearListRecursive:                    ## @ClearListRecursive
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi12:
	.cfi_def_cfa_offset 16
Lcfi13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi14:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	LBB4_2
## BB#1:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdi
	callq	_ClearListRecursive
	movq	-8(%rbp), %rdi
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	callq	_free
LBB4_2:
	movq	$0, _ptrFirst(%rip)
	movq	$0, _ptrLast(%rip)
	movq	-8(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_isEmpty
	.p2align	4, 0x90
_isEmpty:                               ## @isEmpty
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi15:
	.cfi_def_cfa_offset 16
Lcfi16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi17:
	.cfi_def_cfa_register %rbp
	cmpq	$0, _ptrFirst(%rip)
	sete	%al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_AddBeginning
	.p2align	4, 0x90
_AddBeginning:                          ## @AddBeginning
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi18:
	.cfi_def_cfa_offset 16
Lcfi19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi20:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	callq	_isEmpty
	cmpl	$0, %eax
	je	LBB6_2
## BB#1:
	movq	-8(%rbp), %rax
	movq	%rax, _ptrFirst(%rip)
	movq	-8(%rbp), %rax
	movq	%rax, _ptrLast(%rip)
	jmp	LBB6_3
LBB6_2:
	movq	_ptrFirst(%rip), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-8(%rbp), %rax
	movq	%rax, _ptrFirst(%rip)
LBB6_3:
	movq	-8(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_AddEnd
	.p2align	4, 0x90
_AddEnd:                                ## @AddEnd
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi21:
	.cfi_def_cfa_offset 16
Lcfi22:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi23:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	callq	_isEmpty
	cmpl	$0, %eax
	je	LBB7_2
## BB#1:
	movq	-8(%rbp), %rax
	movq	%rax, _ptrFirst(%rip)
	movq	-8(%rbp), %rax
	movq	%rax, _ptrLast(%rip)
	jmp	LBB7_3
LBB7_2:
	movq	-8(%rbp), %rax
	movq	_ptrLast(%rip), %rcx
	movq	%rax, 8(%rcx)
	movq	-8(%rbp), %rax
	movq	%rax, _ptrLast(%rip)
LBB7_3:
	movq	-8(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_ptrFirst               ## @ptrFirst
.zerofill __DATA,__common,_ptrFirst,8,3
	.globl	_ptrLast                ## @ptrLast
.zerofill __DATA,__common,_ptrLast,8,3
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d "


.subsections_via_symbols
