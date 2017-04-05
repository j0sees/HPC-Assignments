	.file	"HPC_A1_Task01_Time_02.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	movl	$0, %eax
	jmp	.L2
.L3:
	addl	$1, %eax
.L2:
	cmpl	$999999999, %eax
	jle	.L3
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
