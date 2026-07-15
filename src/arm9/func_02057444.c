// addr 0x02057444 size 0x1e0
// _f_mul — single-precision multiply (soft-float) (MWCC soft-float runtime)
asm void func_02057444()
{
    eor r2, r0, r1
    and r2, r2, #0x80000000
    mov ip, #0xff
    ands r3, ip, r0, lsr #23
    mov r0, r0, lsl #8
    cmpne r3, #0xff
    beq loc_020574c0
    orr r0, r0, #0x80000000
    ands ip, ip, r1, lsr #23
    mov r1, r1, lsl #8
    cmpne ip, #0xff
    beq loc_02057500
    orr r1, r1, #0x80000000
loc_02057478:
    add ip, r3, ip
    umull r1, r3, r0, r1
    movs r0, r3
    addpl r0, r0, r0
    subpl ip, ip, #1
    subs ip, ip, #0x7f
    bmi loc_0205758c
    cmp ip, #0xfe
    bge loc_020575f8
    ands r3, r0, #0xff
    orr r0, r2, r0, lsr #8
    add r0, r0, ip, lsl #23
    tst r3, #0x80
    bxeq lr
    orrs r1, r1, r3, lsl #25
    andeqs r3, r0, #1
    addne r0, r0, #1
    bx lr
loc_020574c0:
    cmp r3, #0
    beq loc_02057514
    movs r0, r0, lsl #1
    bne loc_020575e8
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq loc_020574f4
    cmp ip, #0xff
    blt loc_020575dc
    cmp r1, #0
    beq loc_020575dc
    b loc_020575e8
loc_020574f4:
    cmp r1, #0
    beq loc_020575f0
    b loc_020575dc
loc_02057500:
    cmp ip, #0
    beq loc_02057570
loc_02057508:
    movs r1, r1, lsl #1
    bne loc_020575e8
    b loc_020575dc
loc_02057514:
    movs r0, r0, lsl #1
    beq loc_0205754c
    mov r0, r0, lsr #1
    clz r3, r0
    movs r0, r0, lsl r3
    rsb r3, r3, #1
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #8
    ands ip, ip, #0xff
    beq loc_02057570
    cmp ip, #0xff
    beq loc_02057508
    orr r1, r1, #0x80000000
    b loc_02057478
loc_0205754c:
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq loc_0205761c
    cmp ip, #0xff
    blt loc_0205761c
    cmp r1, #0
    beq loc_020575f0
    b loc_020575e8
loc_02057570:
    movs r1, r1, lsl #1
    beq loc_0205761c
    mov r1, r1, lsr #1
    clz ip, r1
    movs r1, r1, lsl ip
    rsb ip, ip, #1
    b loc_02057478
loc_0205758c:
    cmn ip, #0x18
    beq loc_020575d4
    bmi loc_02057614
    cmp r1, #0
    orrne r0, r0, #1
    mov r3, r0
    mov r0, r0, lsr #8
    rsb ip, ip, #0
    orr r0, r2, r0, lsr ip
    rsb ip, ip, #0x18
    movs r1, r3, lsl ip
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
loc_020575d4:
    mov r0, r0, lsl #1
    b loc_02057604
loc_020575dc:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
loc_020575e8:
    mvn r0, #0x80000000
    bx lr
loc_020575f0:
    mvn r0, #0x80000000
    bx lr
loc_020575f8:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
loc_02057604:
    movs r1, r0
    mov r0, r2
    addne r0, r0, #1
    bx lr
loc_02057614:
    mov r0, r2
    bx lr
loc_0205761c:
    mov r0, r2
    bx lr
}
