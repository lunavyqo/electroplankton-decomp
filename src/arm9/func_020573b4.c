// addr 0x020573b4 size 0x48
// _f_utof — unsigned int to float (soft-float) (MWCC soft-float runtime)
asm void func_020573b4()
{
    cmp r0, #0
    bxeq lr
    mov r3, #0x9e
    bmi loc_020573d0
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
loc_020573d0:
    ands r2, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    tst r2, #0x80
    bxeq lr
    ands r1, r2, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
}
