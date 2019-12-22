/*	lab15.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

.data
	iVal1:		.word 0
	iVal2:		.word 0
	iVal3:		.word 0
	
	szMsg1:		.asciz "Name: Aaron Geesink\nAssignment: Lab 15\nDate: 10/08/2019\nEnter x: "
	szMsg2:		.asciz "Enter y: "
	LF:			.byte 10
	szVal1:		.skip 12
	szVal2:		.skip 12
	szVal3:		.skip 12
	szDiv:		.asciz " / "
	szEq:		.asciz " = "
	
.text
	.global _start			@provide program start
	.equ	BUFSIZE,20		@size of input buffer

_start:

	ldr 	r1, =szMsg1		@r1 = &szMsg1
	bl 		putstring		@display input msg
	
	ldr		r1, =szVal1		@r1 = &szVal1
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl 		getstring		@read in the string
	bl		ascint32		@turn ascii into integer
	ldr		r1, =iVal1		@r1 = &szVal1
	str 	r0, [r1]		@store iVal1 into memory
	
	ldr 	r1, =szMsg2		@r1 = &inputMsg
	bl 		putstring		@display input msg
	
	ldr		r1, =szVal2		@r1 = &szVal2
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl 		getstring		@read in the string
	bl		ascint32		@turn ascii into integer
	ldr		r1, =iVal2		@r1 = &szVal2
	str 	r0, [r1]		@store iVal2 into memory
	
@ load x and y for division
	ldr		r0, =iVal1		@load address of iVal from memory
	ldr		r0, [r0]		@dereference address to get iVal
	
	ldr		r1, =iVal2		@load address of iVal from memory
	ldr		r1, [r1]		@dereference address to get iVal
	
	bl 		IDIV
	ldr		r1, =iVal3
	str		r0, [r1]
	ldr		r1, =szVal3
	bl		intasc32
	
	ldr		r1, =szVal1
	bl		putstring
	
	ldr		r1, =szDiv
	bl		putstring
	
	ldr		r1, =szVal2
	bl		putstring
	
	ldr		r1, =szEq
	bl		putstring
	
	ldr		r1, =szVal3
	bl		putstring
	
	ldr		r1, =LF
	bl		putch
	
	ldr		r1, =iVal1
	
	@ Call service command to terminate program successfully
	mov r0, #0
	mov r7, #1
	svc 0

@IDIV functionality

negative1: @for negating and getting sign bit (-) (IVAL1)
	MOV R6, #-1				@moves constant -1 to R6
	MVN R0, R0				@negate R0 (IVAL1)
	ADD R0, R0, #1			@add 1 (2's comp) to R0

	BAL continue1			@Branch always to continue1 label addr

negative2: @for negating and getting sign (-) bit (IVAL2)
	MOV R7, #-1				@move constant -1 to R7
	MVN R1, R1				@negate R1 (ival2)
	ADD R1, R1, #1			@Add 1 (2's comp) to R1

	BAL continue2

IDIV:
	MOV R3, #0				@Initialize counter to 0 (R3 = 0)
	MOV R6, #1				@Initialize R6 (positive sign bit ival1)
	MOV R7, #1				@Initialize R7 (positive sign bit ival2)

	CMP R0, #0				@Compare R0 with 0

	BLT negative1			@If less than, ival1 is negative, branch to neg1 label

	CMP R0, R1				@Compare R0 and R1
	BLT val1LessThanVal2
	
continue1: 
	CMP R1, #0				@Compare R1 with 0
	BLT negative2			@(C is 0 or Z is 1) ival2 is negative

continue2:
	MUL R5, R6, R7			@Multiplies (R5=R6*R7) to get sign bit

iDivLoop:
	SUBS R0, R0, R1			@Sub ival1 with ival2
	ADD R3, R3, #1			@CCount how many suvs (R0 = R0 + 1)

	CMP R0, R1				@Compares R1 w/ R2

	BLT endDivision			@(C is 0 or Z is 1) BRANCH to endDivision label if statement

	B iDivLoop 				@while loop, sentinel value = R1 < R2

endDivision:
	mov R4, R3
	MUL R3, R5, R0			@mult sign bit to remainder
	MUL R0, R5, R4			@mult sign bit to quotient

	BX LR					@branch back through LR

val1LessThanVal2:			
	MOV R0, #0				@R0 -> 0
	BX LR

@END OF IDIV
.end					@End of Program
