// addr 0x02056830 size 0x24
// float isordered — either NaN → 0, else 1 (MWCC soft-float runtime)
asm void func_02056830()
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    movlo r0, #0
    bxlo lr
    cmp r3, r1, lsl #1
    movlo r0, #0
    bxlo lr
    mov r0, #1
    bx lr
}
