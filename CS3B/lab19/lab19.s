/*	lab19.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

.data				
	filename:	.asciz "output.txt"
	string:		.asciz "cat in the hat"
	readString:	.skip 20
	
	cLF:		.byte 10
	
.text
	.global _start			@provide program start address to the linker

_start:
@Linux syscall to open the file with the name
	ldr r0, =filename

	mov r1, #01102
	mov r2, #0644

	mov r7, #5
	svc 0
	mov r4, r0

@Get the length of the string
	ldr r1, =string
	bl	String_Length
	mov r5, r0

@Write to the file
	mov r0, r4
	ldr r1, =string
	mov r2, r5
	mov r7, #4
	svc 0
	
@close the file
	mov r0, r4
	mov r7, #6

@Linux syscall to open the file with the name
	ldr r0, =filename

	mov r1, #00
	mov r2, #0644

	mov r7, #5
	svc 0
	mov r4, r0

@Read from the file
	mov r0, r4
	ldr r1, =readString
	mov r2, r5
	mov r7, #3
	svc 0
	
	ldr r1, =readString
	bl putstring
	
	ldr r1, =cLF
	bl putch

@Service command to terminate the program successfully
	mov r0, #0
	mov r7, #1
	svc 0

@End of Program
	.end