// addr 0x02055c10 size 0x364
// _d_mul — double-precision multiply (soft-float) (MWCC soft-float runtime)
asm void func_02055c10()
{
    stmdb sp!, {r4, r5, r6, r7, lr}
    eor lr, r1, r3
    and lr, lr, #0x80000000
    mov ip, r1, lsr #0x14
    mov r1, r1, lsl #0xb
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #0xb
    movs r6, ip, lsl #0x15
    cmnne r6, #0x200000
    beq loc_02055d18
    orr r1, r1, #0x80000000
    bic ip, ip, #0x800
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    cmnne r5, #0x200000
    beq loc_02055d60
    orr r3, r3, #0x80000000
    bic r4, r4, #0x800
loc_02055c64:
    add ip, r4, ip
    umull r5, r4, r0, r2
    umull r7, r6, r0, r3
    adds r4, r7, r4
    adc r6, r6, #0
    umull r7, r0, r1, r2
    adds r4, r7, r4
    adcs r0, r0, r6
    umull r7, r2, r1, r3
    adc r1, r2, #0
    adds r0, r0, r7
    adc r1, r1, #0
    orrs r4, r4, r5
    orrne r0, r0, #1
    cmp r1, #0
    blt loc_02055cb0
    sub ip, ip, #1
    adds r0, r0, r0
    adc r1, r1, r1
loc_02055cb0:
    add ip, ip, #2
    subs ip, ip, #0x400
    bmi loc_02055e4c
    beq loc_02055e4c
    mov r6, ip, lsl #0x14
    cmn r6, #0x100000
    bmi loc_02055f4c
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
loc_02055d18:
    bics ip, ip, #0x800
    beq loc_02055d74
    orrs r6, r0, r1, lsl #1
    bne loc_02055f00
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    beq loc_02055d54
    cmn r5, #0x200000
    bne loc_02055eec
    orrs r5, r2, r3, lsl #1
    beq loc_02055eec
    b loc_02055f00
loc_02055d54:
    orrs r5, r3, r2
    beq loc_02055f14
    b loc_02055eec
loc_02055d60:
    bics r4, r4, #0x800
    beq loc_02055e08
    orrs r6, r2, r3, lsl #1
    bne loc_02055f00
    b loc_02055eec
loc_02055d74:
    orrs r6, r0, r1, lsl #1
    beq loc_02055ddc
    mov ip, #1
    cmp r1, #0
    bne loc_02055d98
    sub ip, ip, #0x20
    movs r1, r0
    mov r0, #0
    bmi loc_02055db4
loc_02055d98:
    clz r6, r1
    movs r1, r1, lsl r6
    rsb r6, r6, #0x20
    orr r1, r1, r0, lsr r6
    rsb r6, r6, #0x20
    mov r0, r0, lsl r6
    sub ip, ip, r6
loc_02055db4:
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    cmnne r5, #0x200000
    beq loc_02055d60
    orr r3, r3, #0x80000000
    bic r4, r4, #0x800
    b loc_02055c64
loc_02055ddc:
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    beq loc_02055f60
    cmn r5, #0x200000
    bne loc_02055f60
    orrs r6, r2, r3, lsl #1
    beq loc_02055f14
    b loc_02055f00
loc_02055e08:
    orrs r5, r2, r3, lsl #1
    beq loc_02055f60
    mov r4, #1
    cmp r3, #0
    bne loc_02055e2c
    sub r4, r4, #0x20
    movs r3, r2
    mov r2, #0
    bmi loc_02055c64
loc_02055e2c:
    clz r6, r3
    movs r3, r3, lsl r6
    rsb r6, r6, #0x20
    orr r3, r3, r2, lsr r6
    rsb r6, r6, #0x20
    mov r2, r2, lsl r6
    sub r4, r4, r6
    b loc_02055c64
loc_02055e4c:
    cmn ip, #0x34
    beq loc_02055ee4
    bmi loc_02055f3c
    mov r2, r1
    mov r3, r0
    add r4, ip, #0x34
    cmp r4, #0x20
    movge r2, r3
    movge r3, #0
    subge r4, r4, #0x20
    rsb r5, r4, #0x20
    mov r2, r2, lsl r4
    orr r2, r2, r3, lsr r5
    movs r3, r3, lsl r4
    orrne r2, r2, #1
    rsb ip, ip, #0xc
    cmp ip, #0x20
    movge r0, r1
    movge r1, #0
    subge ip, ip, #0x20
    rsb r4, ip, #0x20
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    cmp r2, #0
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
loc_02055ee4:
    orr r0, r0, r1, lsl #1
    b loc_02055f24
loc_02055eec:
    ldr r1, [pc, #0x7c]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
loc_02055f00:
    mov r1, r3
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
loc_02055f14:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
loc_02055f24:
    movs r2, r0
    mov r1, lr
    mov r0, #0
    addne r0, r0, #1
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
loc_02055f3c:
    mov r1, lr
    mov r0, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
loc_02055f4c:
    ldr r1, [pc, #0x1c]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
loc_02055f60:
    mov r1, lr
    mov r0, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
    dcd 0x7FF00000
}
