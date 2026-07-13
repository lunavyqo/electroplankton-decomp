
// addr 0x020559ec size 0x104
// _d_dtof — double to float (MWCC soft-float runtime)

asm float func_020559ec(double x)
{
    and r2, r1, #0x80000000
    mov r12, r1, lsr #0x14
    bics r12, r12, #0x800
    beq zero_exp
    mov r3, r12, lsl #0x15
    cmn r3, #0x200000
    bhs special
    subs r12, r12, #0x380
    bls under
    cmp r12, #0xff
    bge overflow
    mov r1, r1, lsl #0xc
    orr r3, r2, r1, lsr #9
    orr r3, r3, r0, lsr #29
    movs r1, r0, lsl #3
    orr r0, r3, r12, lsl #23
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
special:
    orrs r3, r0, r1, lsl #12
    bne nan
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
nan:
    mvn r0, #0x80000000
    bx lr
zero_exp:
    orrs r3, r0, r1, lsl #12
    bne under_zero
    mov r0, r2
    bx lr
under:
    cmn r12, #0x17
    beq round_under
    bmi under_zero
    mov r1, r1, lsl #0xb
    orr r1, r1, #0x80000000
    mov r3, r1, lsr #8
    orr r3, r3, r0, lsr #29
    rsb r12, r12, #1
    movs r1, r0, lsl #3
    orr r0, r2, r3, lsr r12
    rsb r12, r12, #0x20
    mov r3, r3, lsl r12
    orrne r3, r3, #1
    movs r1, r3
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
round_under:
    orr r0, r0, r1, lsl #12
    movs r1, r0
    mov r0, r2
    addne r0, r0, #1
    bx lr
under_zero:
    mov r0, r2
    bx lr
overflow:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
}
