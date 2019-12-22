/*	lab16.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

.data
	iVal1:		.word 0
	iVal2:		.word 0
	
	szMsg1:		.asciz "Enter an integer to see its factorial: "
	szMsg2:		.asciz "\nThat number's factorial is: "
	szMsg3:		.asciz "\nFinding factorials until segfault:\n"
	szMsg4:		.asciz "! = "
	szVal1:		.skip 12
	szVal2:		.skip 12
	LF:			.byte 10
	
.text
	.global _start			@provide program start
	.equ	BUFSIZE,20		@size of input buffer

_start:

@ask user for input of an integer
	ldr		r1, =szMsg1
	bl		putstring
	
	ldr		r1, =szVal1
	ldr		r2, =BUFSIZE
	bl		getstring
	bl		ascint32		@turn ascii into integer
	ldr		r1, =iVal1		@r1 = &szVal1
	str 	r0, [r1]		@store iVal1 into memory
	
	bl		fact			@ calculate the factorial and store it into r0
	ldr		r1, =iVal1
	str		r0, [r1]
	ldr		r1, =szVal1
	bl		intasc32
	
	ldr		r1, =szMsg2
	bl		putstring
	
	ldr		r1, =szVal1
	bl		putstring
	
	
	ldr		r1, =szMsg3
	bl		putstring
	
	mov		r0, #0
	ldr		r1, =iVal1
	str		r0, [r1]
	
loop:
	ldr		r0, =iVal1
	ldr		r0, [r1]
	ldr		r1, =szVal1
	bl		intasc32		@store n as ascii
	bl		fact			@find fact(n)
	ldr		r1, =szVal2
	bl		intasc32		@store fact(n) as ascii

	@display calculation to console
	ldr		r1, =szVal1		
	bl		putstring
	
	ldr		r1, =szMsg4
	bl 		putstring
	
	ldr		r1, =szVal2
	bl 		putstring
	
	ldr		r1, =LF
	bl 		putch
	
	@ store n + 1 into iVal1
	ldr		r1, =iVal1
	ldr		r0,	[r1]
	add		r0, #1
	str		r0,	[r1]
	
	b		loop		@loop until segfault
	
	@ Call service command to terminate program successfully
	mov r0, #0
	mov r7, #1
	svc 0
	
@End of Program
	.end