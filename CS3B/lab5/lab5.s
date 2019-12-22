/* -- lab5.s */

	.data
addr_value1:	.float 4.0
addr_value2:	.float 6.0221415e23

	.global _start
	
_start:
	VLDR S1, addr_value1	@ loads addr_value1 value into single precision register 1
	VLDR S2, addr_value2	@ loads addr_value2 value into single precision register 2
	
	VMUL.F32 S0, S1, S2		@ S0 = S1 x S2
	
	mov r7, #1
	svc 0
	
	.end
