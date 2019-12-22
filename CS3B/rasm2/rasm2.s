@*****************************************************************************
@Name:		Aaron Geesink
@Program:	RASM2.s
@Class:		CS 3B
@Lab:		RASM2
@Date:		October 14, 2018 at 3:00 PM
@Purpose:
@	Input numeric information from the keyboard, perform addition, subtraction, 
@ 	multiplication, and division. Check for overflow upon all operations.
@*****************************************************************************

	.data
iInput1:			.word 0
iInput2:			.word 0

iSum:				.word 0
iDiff:				.word 0
iProd:				.word 0
iQuot:				.word 0
iRemain:			.word 0

strInput1:			.skip 12
strInput2:			.skip 12

strSum:				.skip 12	
strDiff:			.skip 12	
strProd:			.skip 12	
strQuot:			.skip 12	
strRemain:			.skip 12	

strName:			.asciz "Name:		Aaron Geesink\n"
strProgram:			.asciz "Program:	rasm2.s\n"
strClass:			.asciz "Class:		CS 3B\n"
strDate:			.asciz "Date:		October 14, 2019\n"

strFirst:			.asciz "\nEnter your first number: "
strSecond:			.asciz "Enter your second number: "
strSumMsg:			.asciz "The sum is: "
strDiffMsg:			.asciz "\nThe difference is: "	
strProdMsg:			.asciz "\nThe product is: "	
strQuotMsg:			.asciz "\nThe quotient is: "	
strRemainMsg:		.asciz "\nThe remainder is: "		

strOverflowAdd:		.asciz "OVERFLOW OCCURRED WHEN ADDING"
strOverflowSub:		.asciz "OVERFLOW OCCURRED WHEN SUBTRACTING"
strOverflowMul:		.asciz "\nOVERFLOW OCCURRED WHEN MULTIPLYING"
strOverflow:		.asciz "OVERFLOW OCCURRED. RE-ENTER VALUE\n"
strInvalid:		 	.asciz "INVALID NUMERIC STRING. RE-ENTER VALUE"
strZeroDiv:			.asciz "\nYou cannot divide by 0. There is NO quotient or remainder\n"
strGoodbye: 		.asciz "\nThanks for using my program!! Good day!\n\n"
cLF:				.byte 10
	
.text
	.global _start				@provide program start
	.equ	BUFSIZE, 512		@size of input buffer

_start:

@display the header
	ldr 	r1, =strName	@r1 = &strName
	bl 		putstring		@display Name
	ldr 	r1, =strProgram	@r1 = &strProgram
	bl 		putstring		@display Program
	ldr 	r1, =strClass	@r1 = &strClass
	bl 		putstring		@display Class
	ldr 	r1, =strDate	@r1 = &strDate
	bl 		putstring		@display Date

getNum1:
@obtain number 1
	ldr		r1, =strFirst	@r1 = &strFirst
	bl 		putstring		@prompt input for number 1
	
	ldr		r1, =strInput1	@r1 = &strInput1
	ldr		r2, =BUFSIZE	@r2 = &BUFSIZE
	bl		getstring		@user input for number 1
	cmp 	r0, #0			@compare strInput1 to the null char
	beq		terminate		@end program if enter key pressed
	bl		ascint32		@turn number 1 into integer
	bvs		overflow1		@branch if inputted number causes overflow
	cmpcs	r0, #0			@test number for invalid numeric string
	beq		invalid1		@branch if inputted number is not numeric
	ldr		r1, =iInput1	@r1 = &iInput1
	str		r0, [r1]		@store number 1 into memory
	
getNum2:
@obtain number 2
	ldr		r1, =strSecond	@r1 = &strSecond
	bl 		putstring		@prompt input for number 2
	
	ldr		r1, =strInput2	@r1 = &strInput2
	ldr		r2, =BUFSIZE	@r2 = &BUFSIZE
	bl		getstring		@user input for number 2
	cmp 	r0, #0			@compare strInput2 to the null char
	beq		terminate		@end program if enter key pressed
	bl		ascint32		@turn number 2 into integer
	bvs		overflow2		@branch if inputted number causes overflow
	cmpcs	r0, #0			@test number for invalid numeric string
	beq		invalid2		@branch if inputted number is not numeric
	ldr		r1, =iInput2	@r1 = &iInput2
	str		r0, [r1]		@store number 2 into memory
	
@add number 1 with 2
add:
	ldr		r0,	=iInput1	@r0 = &iInput1
	ldr		r0, [r0]		@obtain number 1 from memory
	
	ldr		r1,	=iInput2	@r0 = &iInput2
	ldr		r1, [r1]		@obtain number 2 from memory
	
	adds	r0, r1, r0		@add number 1 and number 2
	bvs		addOverflow		@display addition overflow error
	
	ldr		r1, =iSum		@r1 = &iSum
	str		r0, [r1]		@store sum into iSum
	ldr		r1, =strSum		@r1 = &strSum
	bl		intasc32		@store sum as a string into memory
	
	ldr		r1, =strSumMsg	@r1 = &strSumMsg
	bl		putstring		@display strSumMsg
	ldr		r1, =strSum		@r1 = &strSum
	bl 		putstring		@display sum
	
@subtract number 1 with 2
subtract:
	ldr		r0,	=iInput1	@r0 = &iInput1
	ldr		r0, [r0]		@obtain number 1 from memory
	
	ldr		r1,	=iInput2	@r0 = &iInput2
	ldr		r1, [r1]		@obtain number 2 from memory
	
	subs	r1, r0, r1		@subtract number 1 with number 2
	bvs		subOverflow		@display subtraction overflow error
	
	mov		r0, r1			@mov difference into r0
	ldr		r1, =iDiff		@r1 = &iDiff
	str		r0, [r1]		@store diferrence into iDiff
	ldr		r1, =strDiff	@r1 = &strDiff
	bl		intasc32		@store difference as a string into memory
	
	ldr		r1, =strDiffMsg	@r1 = &strDiffMsg
	bl		putstring		@display strSumMsg
	ldr		r1, =strDiff	@r1 = &strDiff
	bl 		putstring		@display Diff
	
@multiply number 1 with 2
multiply:
	ldr		r1,	=iInput1	@r0 = &iInput1
	ldr		r1, [r1]		@obtain number 1 from memory
	
	ldr		r2,	=iInput2	@r0 = &iInput2
	ldr		r2, [r2]		@obtain number 2 from memory
	
	muls	r0, r1, r2		@multiply number 1 and number 2
	cmp		r0, r1
	bvs		mulOverflow		@display multiplication overflow error
	
	ldr		r1, =iProd		@r1 = &iQuot
	str		r0, [r1]		@store product into iProd
	
	ldr		r1, =strProd	@r1 = &strProd
	bl		intasc32		@store product as a string into memory
	
	ldr		r1, =strProdMsg	@r1 = &strProdMsg
	bl		putstring		@display strProdMsg
	ldr		r1, =strProd	@r1 = &strProd
	bl 		putstring		@display product
	
@Divide number 1 with 2, and determine quotient and remainder
divide:
	ldr		r0,	=iInput1	@r0 = &iInput1
	ldr		r0, [r0]		@obtain number 1 from memory
	
	ldr		r1,	=iInput2	@r0 = &iInput2
	ldr		r1, [r1]		@obtain number 2 from memory
	
	cmp		r1, #0			@compare number 2 to zero
	beq		divByZero		@if number 2 is zero, branch to error
	
	bl		iDiv			@divide number 1 by number 2
	
	ldr		r1, =iQuot		@r1 = &iQuot
	str		r0, [r1]		@store quotient into iQuot
	ldr		r1, =strQuot	@r1 = &strQuot
	bl		intasc32		@store quotient as a string into memory
	
	ldr		r1, =iRemain	@r1 = &iRemain
	str		r3, [r1]		@store remainder into iRemain
	ldr		r1, =strRemain	@r1 = &strRemain
	mov		r0, r3			@mov remainder into r0 for intasc32
	bl		intasc32		@store remainder as a string into memory
	
	ldr		r1, =strQuotMsg	@r1 = &strQuotMsg
	bl		putstring		@display strProdMsg
	ldr		r1, =strQuot	@r1 = &strQuot
	bl 		putstring		@display product
	
	ldr		r1, =strRemainMsg	@r1 = &strRemainMsg
	bl		putstring		@display strProdMsg
	ldr		r1, =strRemain	@r1 = &strRemain
	bl 		putstring		@display product

@loop back to number input
	ldr		r1, =cLF
	bl		putch
	b 		getNum1

terminate:
@ Call service command to terminate program successfully
	ldr		r1, =strGoodbye	@r1 = &strGoodbye
	bl 		putstring		@display goodbye to screen
	
	mov r0, #0
	mov r7, #1
	svc 0
	
overflow1:
	ldr		r1, =strOverflow	@r1 = &strOverflow
	bl 		putstring		@display overflow error to screen
	b		getNum1			@ask user for number 1
	
overflow2:
	ldr		r1, =strOverflow	@r1 = &strOverflow
	bl 		putstring		@display overflow error to screen
	b		getNum2			@ask user for number 2
	
invalid1:
	ldr		r1, =strInvalid	@r1 = &strInvalid
	bl 		putstring		@display invalid error to screen
	b		getNum1			@ask user for number 1

invalid2:
	ldr		r1, =strInvalid	@r1 = &strInvalid
	bl 		putstring		@display invalid error to screen
	
	ldr		r1, =cLF
	bl		putch
	
	b		getNum2			@ask user for number 2

addOverflow:
	ldr		r1, =strOverflowAdd	@r1 = &strOverflowAdd
	bl		putstring		@display addition overflow error
	b		subtract		@branch to subtraction
	
subOverflow:
	ldr		r1, =strOverflowSub	@r1 = &strOverflowSub
	bl		putstring		@display subtraction overflow error
	b		multiply		@branch to multiplication
	
mulOverflow:
	ldr		r1, =strOverflowMul	@r1 = &strOverflowMul
	bl		putstring		@display multiplication overflow error
	b		divide			@branch to division

divByZero:
	ldr		r1, =strZeroDiv	@r1 = &strZeroDiv
	bl 		putstring		@display divide by zero error to screen
	b		getNum1			@restart to number input
.end