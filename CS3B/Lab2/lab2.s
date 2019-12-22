/* -- Lab2.s */

	.global _start  @ Provide program starting address to Linker

_start:
	mov r3, #3

	
	mul r2, r3, r3
	mov r4, #6
	mul r0, r2, r4
	mov r2, r0
	mov r4, #9
	mul r1, r3, r4
	sub r2, r2, r1
	add r2, r2, #2
	
	mov r0, #0  @ Exit status code set to 0 indicates "normal completion"
	mov r7, #1	@ Service command code (1) will terminate this program
	svc 0

	.end
