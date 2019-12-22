/*	aBubbleSort.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

.global aBubbleSort
  array                 .req r0
  i                     .req r1
  j                     .req r2
  size                	.req r3
  sentinel              .req r4
  laterElement          .req r5
  earlierElement        .req r6
  laterElementPtr       .req r7
  earlierElementPtr     .req r8
  temp                  .req r10

aBubbleSort:
    push {r4-r8, r10-r12, lr}

    mov size, r1
    mov i, #0

    aBubbleSortOuterLoop:
        cmp i, size
        bge aBubbleSortEnd
        mov j, #0

        @sub sentinel, size, temp

        aBubbleSortInnerLoop:
            @cmp j, sentinel
            @bge bbl__endfor__j_lt_sentinel
            cmp j, size
            bge aBubbleSortInnerLoopEnd
        
            add earlierElementPtr, array, j, asl #2
            ldr earlierElement, [earlierElementPtr]

            add temp, j, #1
            add laterElementPtr, array, temp, asl #2
            ldr laterElement, [laterElementPtr]

            cmp laterElement, earlierElement
            bge aBubbleSortLaterGTEarlier
                str laterElement, [earlierElementPtr]
                str earlierElement, [laterElementPtr] 
            aBubbleSortLaterGTEarlier:

            add j, j, #1
            b aBubbleSortInnerLoop
            
        aBubbleSortInnerLoopEnd:

        add i, i, #1
        b aBubbleSortOuterLoop

    aBubbleSortEnd:    
    pop {r4-r8, r10-r12, pc}
