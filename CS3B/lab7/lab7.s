/*	lab7.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */


.data
		msgtxt:	
		.ascii "Aaron Geesink"
		
		lbracket:
		.ascii "["
		
		rbracket:
		.ascii "]"
		.text
		
	.global _start
	
_start:
		bl v_byte_bracket
		
		mov r0, #0
		mov r7, #1
		svc 0
		
v_byte_bracket:
		ldr r1, =lbracket
		mov r2, #1

		mov r0, #1
		mov r7, #4
		svc 0
		
		ldr r1, =msgtxt
		mov r2, #13

		mov r0, #1
		mov r7, #4
		svc 0
		
		ldr r1, =rbracket
		mov r2, #1

		mov r0, #1
		mov r7, #4
		svc 0
		
		bx LR	
	
		.end
