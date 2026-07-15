// addr 0x02056664 size 0x38
// soft-float float equality/compare helper (MWCC soft-float runtime)
asm void func_02056664()
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    bhs loc_02056678
    movs r2, #1
    bx lr
loc_02056678:
    cmp r3, r1, lsl #1
    bhs loc_02056688
    movs r2, #1
    bx lr
loc_02056688:
    orr r3, r0, r1
    movs r3, r3, lsl #1
    bxeq lr
    cmp r0, r1
    bx lr
}
