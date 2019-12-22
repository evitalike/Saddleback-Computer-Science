/* -- Lab3.s */

	.global _start  @ Provide program starting address to Linker

_start:
	ldr r1, =0xFFFFFF6B
	ldr r2, =0xFFFFEF1F
	add r7, r1, r2
	
	mov r0, #0  @ Exit status code set to 0 indicates "normal completion"
	mov r7, #1	@ Service command code (1) will terminate this program
	svc 0

	.end
