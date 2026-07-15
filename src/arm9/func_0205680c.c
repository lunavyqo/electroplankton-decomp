// addr 0x0205680c size 0x24
// float isunordered — either NaN → 1, else 0 (MWCC soft-float runtime)
asm void func_0205680c()
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    movlo r0, #1
    bxlo lr
    cmp r3, r1, lsl #1
    movlo r0, #1
    bxlo lr
    mov r0, #0
    bx lr
}
