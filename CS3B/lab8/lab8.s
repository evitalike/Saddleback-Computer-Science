/* -- lab8.s 
	Programmed by Aaron Geesink
	Barnett CS3B
*/

.data				@initialize memory with 3 0s
	iX: .word 0 
	iY: .word 0
	iSum: .word 0

	.global _start
	
_start:
	ldr r1, =iX 	@ r1 <- &iX
	mov r3, #5 		@ r3 <- 5
	str r3, [r1] 	@ *r1 <- r3
	
	ldr r2, =iY 	@ r2 <- &iY
	mov r3, #10 	@ r3 <- 10
	str r3, [r2] 	@ *r2 <- r3
	
	ldr r3, =iSum	@ r3 <- &iSum
	ldr r1, [r1]	@ r1 <- *r1
	ldr r2, [r2]	@ r2 <- *r2
	add r0, r1, r2	@ r0 = r1 + r2 (r0 = 5 + 10)
	str r0, [r3]	@ *r3 <- r0
	
	mov r0, #0
	mov r7, #1
	svc 0