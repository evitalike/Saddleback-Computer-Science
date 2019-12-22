/*	lab6.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

	.data
msgtxt:	.ascii "A"
		.text
		
		
		.global _start
		
_start:
		ldr r1, =msgtxt
		mov r2, #1
		bl v_asc
		
		mov r0, #0
		mov r7, #1
		svc 0
		
		
v_asc:	mov r0, #1
		mov r7, #4
		svc 0
		bx LR
		
		.end
