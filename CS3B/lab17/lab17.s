/*	lab17.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

.data
	szVal1:			.skip 12
	
	szMsg1:			.asciz "Testing the string: "
	szMsg2:			.asciz "\nlength: "
	szString1:		.asciz "Cat in the hat"
	szString2:		.asciz "Test String"
	
	cLF:			.byte 10
	
.text
	.global _start			@provide program start
	.equ	BUFSIZE, 20		@size of input buffer

_start:

	ldr 	r1, =szMsg1
	bl		putstring
	ldr		r1, =szString1
	bl		putstring
	
	bl		String_Length
	ldr		r1, =szVal1
	bl		intasc32
	
	ldr 	r1, =szMsg2
	bl		putstring
	ldr		r1, =szVal1
	bl		putstring
	
	ldr		r1, =cLF
	bl		putch
	
	ldr 	r1, =szMsg1
	bl		putstring
	ldr		r1, =szString2
	bl		putstring
	
	bl		String_Length
	ldr		r1, =szVal1
	bl		intasc32
	
	ldr 	r1, =szMsg2
	bl		putstring
	ldr		r1, =szVal1
	bl		putstring
	
	ldr		r1, =cLF
	bl		putch
	
	@ Call service command to terminate program successfully
	mov r0, #0
	mov r7, #1
	svc 0

@End of Program
	.end