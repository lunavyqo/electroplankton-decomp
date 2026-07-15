// addr 0x02057340 size 0x34
// _f_ftol — float to signed long (soft-float) (MWCC soft-float runtime)
asm void func_02057340()
{
    bic r1, r0, #0x80000000
    mov r2, #0x9e
    subs r2, r2, r1, lsr #23
    ble loc_02057368
    mov r1, r1, lsl #8
    orr r1, r1, #0x80000000
    cmp r0, #0
    mov r0, r1, lsr r2
    rsbmi r0, r0, #0
    bx lr
loc_02057368:
    mvn r0, r0, asr #31
    add r0, r0, #0x80000000
    bx lr
}
