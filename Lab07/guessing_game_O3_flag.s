	.file	"GuessingGame.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"======================================== "
	.align 8
.LC1:
	.string	"|         Pick a number 1-10           | "
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"Make a guess: "
.LC3:
	.string	"%d"
.LC4:
	.string	"You got it! "
.LC5:
	.string	"No guess lower! "
.LC6:
	.string	"No guess higher! "
	.section	.rodata.str1.8
	.align 8
.LC7:
	.string	"=================================================== "
	.align 8
.LC8:
	.string	"| Here are the results of your guessing abilities | "
	.align 8
.LC9:
	.string	"Game %d took you %d guesses. \n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	xorl	%edi, %edi
	movl	$1717986919, %r14d
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	subq	$48, %rsp
	.cfi_def_cfa_offset 96
	leaq	16(%rsp), %r12
	call	time
	leaq	20(%r12), %r13
	movl	%eax, %edi
	call	srand
	.p2align 4,,10
	.p2align 3
.L4:
	movl	$.LC0, %edi
	xorl	%ebx, %ebx
	call	puts
	movl	$.LC1, %edi
	call	puts
	movl	$.LC0, %edi
	call	puts
	call	rand
	movl	%eax, %ebp
	imull	%r14d
	movl	%ebp, %eax
	sarl	$31, %eax
	sarl	$2, %edx
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %eax
	addl	%eax, %eax
	subl	%eax, %ebp
	addl	$1, %ebp
	.p2align 4,,10
	.p2align 3
.L9:
	movl	$.LC2, %edi
	xorl	%eax, %eax
	addl	$1, %ebx
	call	printf
	leaq	12(%rsp), %rsi
	xorl	%eax, %eax
	movl	$.LC3, %edi
	call	__isoc99_scanf
	cmpl	12(%rsp), %ebp
	je	.L13
	jge	.L5
	movl	$.LC5, %edi
	call	puts
	.p2align 4,,3
	jmp	.L9
	.p2align 4,,10
	.p2align 3
.L5:
	movl	$.LC6, %edi
	call	puts
	.p2align 4,,3
	jmp	.L9
	.p2align 4,,10
	.p2align 3
.L13:
	movl	$.LC4, %edi
	addq	$4, %r12
	call	puts
	movl	%ebx, -4(%r12)
	cmpq	%r13, %r12
	jne	.L4
	movl	$.LC7, %edi
	xorl	%ebx, %ebx
	call	puts
	movl	$.LC8, %edi
	call	puts
	movl	$.LC7, %edi
	call	puts
.L8:
	movl	16(%rsp,%rbx,4), %edx
	movl	%ebx, %esi
	xorl	%eax, %eax
	movl	$.LC9, %edi
	addq	$1, %rbx
	call	printf
	cmpq	$5, %rbx
	jne	.L8
	addq	$48, %rsp
	.cfi_def_cfa_offset 48
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.text
	.p2align 4,,15
	.globl	guessingGame
	.type	guessingGame, @function
guessingGame:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$.LC0, %edi
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	xorl	%ebx, %ebx
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	call	puts
	movl	$.LC1, %edi
	call	puts
	movl	$.LC0, %edi
	call	puts
	call	rand
	movl	$1717986919, %edx
	movl	%eax, %ebp
	imull	%edx
	movl	%ebp, %eax
	sarl	$31, %eax
	sarl	$2, %edx
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %eax
	addl	%eax, %eax
	subl	%eax, %ebp
	addl	$1, %ebp
	.p2align 4,,10
	.p2align 3
.L18:
	movl	$.LC2, %edi
	xorl	%eax, %eax
	addl	$1, %ebx
	call	printf
	leaq	12(%rsp), %rsi
	xorl	%eax, %eax
	movl	$.LC3, %edi
	call	__isoc99_scanf
	movl	12(%rsp), %edx
	cmpl	%ebp, %edx
	je	.L20
	cmpl	%edx, %ebp
	jge	.L16
	movl	$.LC5, %edi
	call	puts
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L16:
	movl	$.LC6, %edi
	call	puts
	.p2align 4,,3
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L20:
	movl	$.LC4, %edi
	call	puts
	addq	$24, %rsp
	.cfi_def_cfa_offset 24
	movl	%ebx, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE8:
	.size	guessingGame, .-guessingGame
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
