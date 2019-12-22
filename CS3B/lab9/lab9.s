/*	lab9.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */
	
.data
	szMsg1:	.asciz	"Enter a value: "
	szMsg2: .asciz	"You Just typed: "
	cCR:	.byte	10
	szValA:	.skip 	12
	szValB:	.skip 	12
	szValC:	.skip 	12
	szValD:	.skip 	12
.text

	.global _start			@provide program start
	.equ	BUFSIZE,20		@size of input buffer
	
_start:

@Input first number
	ldr 	r1, =szMsg1		@R1 = *szMsg1
	bl	putstring			@print szMsg1
	
	ldr		r1, =szValA		@R1 = *szValA
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl getstring			@read in the string
	
	ldr 	r1, =szMsg2		@R1 = *szMsg2
	bl putstring			@print szMsg2
	
	ldr 	r1, =szValA		@R1 = *szInput
	bl putstring			@print szInput
	
	ldr		r1, =cCR		@r1 = *carriage
	bl putch				@print CR
	
@Input second number
	ldr 	r1, =szMsg1		@R1 = *szMsg1
	bl	putstring			@print szMsg1
	
	ldr		r1, =szValB		@R1 = *szValB
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl getstring			@read in the string
	
	ldr 	r1, =szMsg2		@R1 = *szMsg2
	bl putstring			@print szMsg2
	
	ldr 	r1, =szValB		@R1 = *szInput
	bl putstring			@print szInput
	
	ldr		r1, =cCR		@r1 = *carriage
	bl putch				@print CR
	
@Input third number
	ldr 	r1, =szMsg1		@R1 = *szMsg1
	bl	putstring			@print szMsg1
	
	ldr		r1, =szValC		@R1 = *szValC
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl getstring			@read in the string
	
	ldr 	r1, =szMsg2		@R1 = *szMsg2
	bl putstring			@print szMsg2
	
	ldr 	r1, =szValC		@R1 = *szInput
	bl putstring			@print szInput
	
	ldr		r1, =cCR		@r1 = *carriage
	bl putch				@print CR
	
@Input fourth number
	ldr 	r1, =szMsg1		@R1 = *szMsg1
	bl	putstring			@print szMsg1
	
	ldr		r1, =szValD		@R1 = *szValD
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl getstring			@read in the string
	
	ldr 	r1, =szMsg2		@R1 = *szMsg2
	bl putstring			@print szMsg2
	
	ldr 	r1, =szValD		@R1 = *szInput
	bl putstring			@print szInput
	
	ldr		r1, =cCR		@r1 = *carriage
	bl putch				@print CR
	
	mov r0, #0
	mov r7, #1
	svc 0
.end
