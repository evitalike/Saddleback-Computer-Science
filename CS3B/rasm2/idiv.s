	.global iDiv

@IDIV functionality
negative1: @for negating and getting sign bit (-) (IVAL1)
	MOV 	R6, #-1				@moves constant -1 to R6
	MVN 	R0, R0				@negate R0 (IVAL1)
	ADD 	R0, R0, #1			@add 1 (2's comp) to R0
	BAL 	continue1			@Branch always to continue1 label addr

negative2: @for negating and getting sign (-) bit (IVAL2)
	MOV 	R7, #-1				@move constant -1 to R7
	MVN 	R1, R1				@negate R1 (ival2)
	ADD 	R1, R1, #1			@Add 1 (2's comp) to R1
	BAL 	continue2

iDiv:
	push 	{r1,r2,r4-r7,lr}
	MOV 	R3, #0				@Initialize counter to 0 (R3 = 0)
	MOV 	R6, #1				@Initialize R6 -> (positive sign bit ival1)
	MOV 	R7, #1				@Initialize R7 -> (positive sign bit ival2)
	CMP 	R0, #0				@Compare R0 with 0

	BLT 	negative1			@If less than, ival1 is negative, branc to neg1 label

	CMP 	R0, R1				@Compare R0 and R1
	BLT 	val1LessThanVal2
	
continue1: 
	CMP 	R1, #0				@Compare R1 with 0
	BLT 	negative2			@(C is 0 or Z is 1) ival2 is negative

continue2:
	MUL 	R5, R6, R7			@Multiplies (R5=R6*R7) to get sign bit

iDivLoop:
	SUBS 	R0, R0, R1			@Sub ival1 with ival2
	ADD 	R3, R3, #1			@Count how many subs (R0 = R0 + 1)

	CMP 	R0, R1				@Compares R1 w/ R2

	BLT 	endDivision			@(C is 0 or Z is 1) BRANCH to endDivision label if statement

	B 		iDivLoop 			@while loop, sentinel value = R1 < R2

endDivision:
	MUL 	R0, R5, R0			@mult sign bit to remainder
	MUL 	R3, R5, r3			@mult sign bit to quotient

	mov 	r4, r0
	mov		r0,	r3
	mov		r3, r4

	pop 	{r1,r2,r4-r7,lr}
	BX 		LR					@branch back through LR

val1LessThanVal2:
	mov		r3, r0
	MOV 	R0, #0				@R3 -> 0
	
	pop 	{r1,r2,r4-r7,lr}
	BX 		LR

@END OF IDIV
.end