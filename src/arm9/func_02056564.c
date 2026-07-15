// addr 0x02056564 size 0x48
// soft-float float cmp → 0/1/2/3 (split NaN checks) (MWCC soft-float runtime)
asm void func_02056564()
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    movlo r0, #3
    bxlo lr
    cmp r3, r1, lsl #1
    movlo r0, #3
    bxlo lr
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    moveq r0, #0
    movlt r0, #1
    movgt r0, #2
    bx lr
}
