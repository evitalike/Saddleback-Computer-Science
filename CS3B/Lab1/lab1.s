/* -- Lab1.s */
/* This is a comment */
@ This is also a comment

	.global _start  @ Provide program starting address to Linker

_start:
	mov r0, #8
	mov r1, #255
	mov r2, #5000
	mov r3, #-96
	movs r4, r3
	mov r5, r2
	
	mov r0, #0  @ Exit status code set to 0 indicates "normal completion"
	mov r7, #1	@ Service command code (1) will terminate this program
	svc 0

	.end
