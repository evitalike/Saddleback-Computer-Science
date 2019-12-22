/*	lab10.s 
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
	
@ put the result of (szValA + szValB) - (szValC + szValD) into r0
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
	
	ldr 	r4, =szValA
	ldr 	r5, =szValB
	ldr 	r6, =szValC
	ldr 	r7, =szValD
	
@ Call service command to terminate program successfully
	mov r0, #0				
	mov r7, #1
	svc 0
	
.end
