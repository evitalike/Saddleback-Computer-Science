/*	exam1.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */
	
.data
	szMsgX:	.asciz	"Enter x: "
	szMsgY:	.asciz	"Enter y: "
	szMsgZ:	.asciz	"Enter z: "

	szMsg1: .asciz	"Author: Aaron Geesink\nDate: 10/01/2019\nProgram: Exam 1\n\n"
	
	lParen: .asciz "("
	rParen: .asciz ")"
	plus: 	.asciz " + "
	minus: 	.asciz " - "
	equal: 	.asciz " = "
	times:	.asciz " * "
	tab:	.asciz "    "
	div4:	.asciz "/4"
	
	cCR:	.byte	10
	szValX:		.skip 	12
	szValY:		.skip 	12
	szValZ:		.skip 	12
	result: .skip	12
	szHex:	.skip	12
	
	iX:		.word 0
	iY:		.word 0
	iZ:		.word 0

.text

	.global _start			@provide program start
	.equ	BUFSIZE,20		@size of input buffer
	
_start:

@display header info
	ldr 	r1, =szMsg1		@R1 = *szMsg1
	bl	putstring			@print szMsg1

@Input first number
	ldr 	r1, =szMsgX		@R1 = *szMsgX
	bl	putstring			@print szMsgX
	
	ldr		r1, =szValX			@R1 = *szValX
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl getstring			@read in the string
	
@Input second number
	ldr 	r1, =szMsgY		@R1 = *szMsgY
	bl	putstring			@print szMsgY
	
	ldr		r1, =szValY			@R1 = *szValY
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl getstring			@read in the string
	
@Input third number
	ldr 	r1, =szMsgZ		@R1 = *szMsgZ
	bl	putstring			@print szMsgZ
	
	ldr		r1, =szValZ			@R1 = *szValZ
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl getstring			@read in the string
	
@ put the result of (szValX * szValY + iZ - szValX)/4 into result
	ldr		r1, =szValX			@r1 = *szValX
	bl		ascint32		@r0 = szValX converted to int
	mov r2, r0				@r2 = r0

	ldr		r1, =szValY			@r1 = *szValY
	bl		ascint32		@r0 = szValY converted to int
	mul r2, r0, r2			@r2 = r0 + r2
	
	ldr		r1, =szValZ			@r1 = *szValZ
	bl		ascint32		@r0 = szValZ converted to int
	add r2, r0, r2			@r3 = r0
	
	ldr		r1, =szValX			@r1 = *szValX
	bl		ascint32		@r0 = szValX converted to int
	sub r2, r2, r0			@r2 = r2 - r0
	
	asr	r2, #2				@shift result right by 2 (divide by four)
	mov r0, r2				@move the result in r2 into r0
	ldr r1, =result			@get adress of string result will be stored in
	bl intasc32				@covert result into ascii and store into memory
	
	

@Equation that was performed displayed to the console
	ldr		r1, =cCR		@load newline
	bl	putch				@print newline

	ldr 	r1, =lParen		@R1 = *lParen
	bl	putch				@print lParen
	
	ldr 	r1, =szValX			@R1 = *szValX
	bl	putstring			@print szValX
	
	ldr 	r1, =times		@R1 = *times
	bl	putstring			@print times
	
	ldr 	r1, =szValY			@R1 = *szValY
	bl	putstring			@print szValY
	
	ldr 	r1, =plus		@R1 = *plus
	bl	putstring			@print plus
	
	ldr 	r1, =szValZ			@R1 = *szValZ
	bl	putstring			@print szValZ
	
	ldr 	r1, =minus		@R1 = *minus
	bl	putstring			@print minus
	
	ldr 	r1, =szValX			@R1 = *szValX
	bl	putstring			@print szValX
	
	ldr 	r1, =rParen		@R1 = *rParen
	bl	putch				@print rParen
	
	ldr 	r1, =div4		@R1 = *div4
	bl	putstring			@print div4
	
	ldr 	r1, =equal		@R1 = *equal
	bl	putstring			@print equal
	
	ldr 	r1, =result		@R1 = *result
	bl	putstring			@print result
	
	ldr		r1, =cCR		@load newline
	bl	putch				@print newline
	
	ldr	r1, =szValX
	bl ascint32
	ldr r1, =iX
	str r0, [r1]
	
	ldr	r1, =szValY
	bl ascint32
	ldr r1, =iY
	str r0, [r1]
	
	ldr	r1, =szValZ
	bl ascint32
	ldr r1, =iZ
	str r0, [r1]
	
	ldr r1, =iX

	
@ Call service command to terminate program successfully
	mov r0, #0				
	mov r7, #1
	svc 0
	
.end
