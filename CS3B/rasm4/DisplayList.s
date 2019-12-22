.global DisplayList

.text
	cLF:	.byte 10

@ ============= DisplayList function ================
@ Displays the contents of the linked list
@ ===================================================
.balign 4
DisplayList:
		push {r4-r8, r10-r12, lr}

		mov r4, r0		@ Store the pointer to the list

		ldr r1, =cLF	@ Output endline
		bl putch

		mov r0, r4		@ Print the list
		bl List_print

		ldr r1, =cLF	@ Output endline
		bl putch

		pop {r4-r8, r10-r12, pc}
		
@ ============ void List_print(r0 list) ===============
List_print:
	push {lr}

	ldr r1, =print_string_and_endline	@ Put each string plus an endline 
	bl List_foreach

	pop {pc}
	
@ ========== void print_string_and_endline(r1 str) ==============
print_string_and_endline:
	push {lr}

	bl putstring			@ Display string specified

	ldr r1, =cLF			@ Put an endline
	bl putch

	pop {pc}
	
@ =======  void List_foreach(r0 list, r1 actionRoutine) =========
List_foreach:
	push {r4-r8, r10-r12, lr}

	mov r4, r0				@ Preserve the arguments in non-volatile registers
	mov r5, r1
	
	ldr r6, [r4]			@ Use r6 as the "current" pointer, starting at the head

	lforeach__while__current_not_null:
		cmp r6, #0			@ Compare the current node with null
		beq lforeach__end
	
		ldr r1, [r6]		@ Load r1 with the data pointer of the current node
		blx r5				@ branch to the action routine

		ldr r6, [r6, #4]	@ Load current node pointer with its own next pointer
		bal lforeach__while__current_not_null

	lforeach__end:
		pop {r4-r8, r10-r12, pc}
