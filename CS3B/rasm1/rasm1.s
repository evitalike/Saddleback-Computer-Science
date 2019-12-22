/*	RASM1.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */
	
.data
	szMsg1:	.asciz	"Enter a value: "
	szMsg3: .asciz	" Name: Aaron Geesink\nClass: CS 3B\n  Lab: RASM1\n Date: 9/26/2019\n\n"
	szMsg4:	.asciz	"\nThe addresses of the 4 ints:\n"
	
	lParen: .asciz "("
	rParen: .asciz ")"
	plus: 	.asciz " + "
	minus: 	.asciz " - "
	equal: 	.asciz " = "
	tab:	.asciz "    "
	
	cCR:	.byte	10
	szValA:	.skip 	12
	szValB:	.skip 	12
	szValC:	.skip 	12
	szValD:	.skip 	12
	result: .skip	12
	szHex:	.skip	12

.text

	.global _start			@provide program start
	.equ	BUFSIZE,20		@size of input buffer
	
_start:

@display header info
	ldr 	r1, =szMsg3		@R1 = *szMsg3
	bl	putstring			@print szMsg3

@Input first number
	ldr 	r1, =szMsg1		@R1 = *szMsg1
	bl	putstring			@print szMsg1
	
	ldr		r1, =szValA		@R1 = *szValA
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl getstring			@read in the string
	
@Input second number
	ldr 	r1, =szMsg1		@R1 = *szMsg1
	bl	putstring			@print szMsg1
	
	ldr		r1, =szValB		@R1 = *szValB
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl getstring			@read in the string
	
@Input third number
	ldr 	r1, =szMsg1		@R1 = *szMsg1
	bl	putstring			@print szMsg1
	
	ldr		r1, =szValC		@R1 = *szValC
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl getstring			@read in the string
	
@Input fourth number
	ldr 	r1, =szMsg1		@R1 = *szMsg1
	bl	putstring			@print szMsg1
	
	ldr		r1, =szValD		@R1 = *szValD
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl getstring			@read in the string
	
@ put the result of (szValA + szValB) - (szValC + szValD) into result
	ldr		r1, =szValA		@r1 = *szValA
	bl		ascint32		@r0 = szValA converted to int
	mov r2, r0				@r2 = r0

	ldr		r1, =szValB		@r1 = *szValB
	bl		ascint32		@r0 = szValB converted to int
	add r2, r0, r2			@r2 = r0 + r2
	
	ldr		r1, =szValC		@r1 = *szValC
	bl		ascint32		@r0 = szValC converted to int
	mov r3, r0				@r3 = r0
	
	ldr		r1, =szValD		@r1 = *szValD
	bl		ascint32		@r0 = szValD converted to int
	add r3, r0, r3			@r3 = r0 + r3
	
	sub r0, r2, r3			@r0 = r2 - r3

@Equation that was performed displayed to the console
	ldr 	r1, =lParen		@R1 = *lParen
	bl	putch				@print lParen
	
	ldr 	r1, =szValA		@R1 = *szValA
	bl	putstring			@print szValA
	
	ldr 	r1, =plus		@R1 = *plus
	bl	putstring			@print plus
	
	ldr 	r1, =szValB		@R1 = *szValB
	bl	putstring			@print szValB
	
	ldr 	r1, =rParen		@R1 = *rParen
	bl	putch				@print rParen
	
	ldr 	r1, =minus		@R1 = *minus
	bl	putstring			@print minus
	
	ldr 	r1, =lParen		@R1 = *lParen
	bl	putch				@print lParen
	
	ldr 	r1, =szValC		@R1 = *szValC
	bl	putstring			@print szValC
	
	ldr 	r1, =plus		@R1 = *plus
	bl	putstring			@print plus
	
	ldr 	r1, =szValD		@R1 = *szValD
	bl	putstring			@print szValD
	
	ldr 	r1, =rParen		@R1 = *rParen
	bl	putch				@print rParen
	
	ldr 	r1, =equal		@R1 = *equal
	bl	putstring			@print equal
	
	ldr 	r1, =result		@R1 = *result
	bl 	intasc32			@converts result into ascii
	bl putstring			@print result
	

@ Display the addresses in memory of A, B, C, and D

	ldr 	r1, =szMsg4		@R1 = *szMsg4
	bl	putstring			@print szMsg4

	ldr 	r0, =szValA		@r0 = *szValA
	ldr		r1, =szHex		@r1 = *szHex
	mov 	r2, #8			@r2 = 8
	bl	hexToChar			@hex value in r0 converted to ascii and stored in the address stored by r1
	bl	putstring			@print sizeHex
	
	ldr		r1, =tab		@r1 = *tab
	bl	putstring			@print tab
	
	ldr 	r0, =szValB		@r0 = *szValB
	ldr		r1, =szHex		@r1 = *szHex
	mov 	r2, #8			@r2 = 8
	bl	hexToChar			@hex value in r0 converted to ascii and stored in the address stored by r1
	bl	putstring			@print sizeHex
	
	ldr		r1, =tab		@r1 = *tab
	bl	putstring			@print tab
	
	ldr 	r0, =szValC		@r0 = *szValC
	ldr		r1, =szHex		@r1 = *szHex
	mov 	r2, #8			@r2 = 8
	bl	hexToChar			@hex value in r0 converted to ascii and stored in the address stored by r1
	bl	putstring			@print sizeHex
	
	ldr		r1, =tab		@r1 = *tab
	bl	putstring			@print tab
	
	ldr 	r0, =szValD		@r0 = *szValD
	ldr		r1, =szHex		@r1 = *szHex
	mov 	r2, #8			@r2 = 8
	bl	hexToChar			@hex value in r0 converted to ascii and stored in the address stored by r1
	bl	putstring			@print sizeHex
	
	ldr		r1, =cCR		@r1 = *cCR
	bl		putch			@print carriage return

	
@ Call service command to terminate program successfully
	mov r0, #0				
	mov r7, #1
	svc 0
	
.end
