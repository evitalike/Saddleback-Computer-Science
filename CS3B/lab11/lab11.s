/*	lab11.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

.data
	arru8List: 	.byte 1,2,3,4,5		@use ldrb
	u8Sum:		.byte 0
	
	arrsList:	.hword -1,1,-2,2,3	@use ldrsh
	sSum: 		.hword 0
	
	arriList:	.word 1024, -1024, 2049, -2049, 4100	@use ldr
	iSum:		.word 0
	
	u8SumMsg:	.asciz "u8Sum = "
	sSumMsg:	.asciz "sSum = "
	iSumMsg:	.asciz "iSum = "
	LF:			.byte 10
	szU8Sum:	.skip 	12
	szSSum:		.skip 	12
	szISum:		.skip 	12
	
.text

	.global _start				@provide program start
	.equ	BUFSIZE,20			@size of input buffer

_start:
@ ----------------------------------------------	
@Adding array of 8 bit unsigned integers
	mov		r3, #5				@ r3 = 5 (beginning index)
	ldr		r4, =arru8List		@ r4 = &arru8List
	mov		r5, #0				@ r5 = 0 (ending index)
	
@ for (int i = 5; i = 0; i--)
u8SumLoop:
	cmp r3, #0					@ compare r3 and 0
	beq u8SumEndLoop			@ branch if index is 0
	ldrb r6, [R4], #1			@ r6 = arru8List[i], increment r4 to next array location
	sub r3, #1					@ r3--
	add r5, r6					@ r5 = sum of arruList
	
	b u8SumLoop					@repeat until index is 0
	
u8SumEndLoop:
	ldr r3, =u8Sum				@load &u8Sum
	strb r5, [r3]				@store sum into u8Sum

@ ----------------------------------------------
@Adding array of 16 bit short integers
	mov		r3, #5				@ r3 = 5 (beginning index)
	ldr		r4, =arrsList		@ r4 = &arrsList
	mov		r5, #0				@ r5 = 0 (ending index)
	
@ for (int i = 5; i = 0; i--)
sSumLoop:
	cmp r3, #0					@ compare r3 and 0
	beq sSumEndLoop				@ branch if index is 0
	ldrsh r6, [R4], #2			@ r6 = arrsList[i], increment r4 to next array location
	sub r3, #1					@ r3--
	add r5, r6					@ r5 = sum of arrsList
	
	b sSumLoop					@repeat until index is 0
	
sSumEndLoop:
	ldr r3, =sSum				@load &sSum
	strh r5, [r3]				@store sum into sSum

@ ----------------------------------------------
@Adding array of 32 bit signed integers
	mov		r3, #5				@ r3 = 5 (beginning index)
	ldr		r4, =arriList		@ r4 = &arriList
	mov		r5, #0				@ r5 = 0 (ending index)
	
@ for (int i = 5; i = 0; i--)
iSumLoop:
	cmp r3, #0					@ compare r3 and 0
	beq iSumEndLoop				@ branch if index is 0
	ldr r6, [R4], #4			@ r6 = arriList[i], increment r4 to next array location
	sub r3, #1					@ r3--
	add r5, r6					@ r5 = sum of arriList
	
	b iSumLoop					@repeat until index is 0
	
iSumEndLoop:
	ldr r3, =iSum				@load &iSum
	str r5, [r3]				@store sum into iSum
	
@ ----------------------------------------------
@ display sums to screen
	ldr		r1, =LF
	bl		putch

@display u8Sum
	ldr		r1, =u8SumMsg
	bl		putstring
	
	ldr		r0, =u8Sum
	ldrb	r0, [r0]
	ldr		r1, =szU8Sum
	bl		intasc32
	bl		putstring
	
	ldr		r1, =LF
	bl		putch
	
@display sSum
	ldr		r1, =sSumMsg
	bl		putstring
	
	ldr		r0, =sSum
	ldrsh	r0, [r0]
	ldr		r1, =szSSum
	bl		intasc32
	bl		putstring
	
	ldr		r1, =LF
	bl		putch
	
@display iSum
	ldr		r1, =iSumMsg
	bl		putstring
	
	ldr		r0, =iSum
	ldr		r0, [r0]
	ldr		r1, =szISum
	bl		intasc32
	bl		putstring
	
	ldr		r1, =LF
	bl		putch
	
@ Load memory adresses of arrays for memory dump
	ldr		r0, =u8Sum
	ldr		r1, =sSum
	ldr		r2, =iSum
	ldr		r3, =arru8List
	ldr		r4, =arrsList
	ldr		r5, =arriList

@ Call service command to terminate program successfully
	mov r0, #0
	mov r7, #1
	svc 0
	
.end	
