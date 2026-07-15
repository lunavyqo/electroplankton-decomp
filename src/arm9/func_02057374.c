// addr 0x02057374 size 0x40
// _f_ftoul — float to unsigned long (soft-float) (MWCC soft-float runtime)
asm void func_02057374()
{
    tst r0, #0x80000000
    bne loc_02057398
    mov r1, #0x9e
    subs r1, r1, r0, lsr #23
    blt loc_020573ac
    mov r2, r0, lsl #8
    orr r0, r2, #0x80000000
    mov r0, r0, lsr r1
    bx lr
loc_02057398:
    mov r2, #0xff000000
    cmp r2, r0, lsl #1
    movhs r0, #0
    mvnlo r0, #0
    bx lr
loc_020573ac:
    mvn r0, #0
    bx lr
}
