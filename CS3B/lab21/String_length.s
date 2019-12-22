/*  --- lab21.s ---   */
/*  Garrett Geesink  */
/*  CS3B 3 PM Class  */
/*  Tuesday/Thursday */
.global String_length

.equ NULL, 0

String_length:
	push {r1-r2,LR}
	mov r2, #0
mainlp:
	ldrb r1, [r0], #1
	cmp r1, #0
	addne r2, #1
	bne mainlp
	mov r0, r2
	pop {r1-r2,LR}
	bx LR
.end