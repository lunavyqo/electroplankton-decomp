// addr 0x02055f8c size 0x3b4
// _d_sub — double-precision sub (soft-float) (MWCC soft-float runtime)

void ext_020556e4(void);
asm void func_02055f8c()
{
    stmdb sp!, {r4, lr}
    eors ip, r1, r3
    eormi r3, r3, #0x80000000
    bmi ext_020556e4
    subs ip, r0, r2
    sbcs lr, r1, r3
    bhs loc_02055fbc
    eor lr, lr, #0x80000000
    adds r2, r2, ip
    adc r3, r3, lr
    subs r0, r0, ip
    sbc r1, r1, lr
loc_02055fbc:
    mov lr, #0x80000000
    mov ip, r1, lsr #0x14
    orr r1, lr, r1, lsl #11
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #0xb
    movs r4, ip, lsl #0x15
    cmnne r4, #0x200000
    beq loc_020561c0
    mov r4, r3, lsr #0x14
    orr r3, lr, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs lr, r4, lsl #0x15
    beq loc_02056208
loc_02055ff4:
    subs r4, ip, r4
    beq loc_0205609c
    cmp r4, #0x20
    ble loc_02056030
    cmp r4, #0x38
    movge r4, #0x3f
    sub r4, r4, #0x20
    rsb lr, r4, #0x20
    orrs lr, r2, r3, lsl lr
    mov r2, r3, lsr r4
    orrne r2, r2, #1
    subs r0, r0, r2
    sbcs r1, r1, #0
    bmi loc_02056058
    b loc_02056148
loc_02056030:
    rsb lr, r4, #0x20
    movs lr, r2, lsl lr
    rsb lr, r4, #0x20
    mov r2, r2, lsr r4
    orr r2, r2, r3, lsl lr
    mov r3, r3, lsr r4
    orrne r2, r2, #1
    subs r0, r0, r2
    sbcs r1, r1, r3
    bpl loc_02056148
loc_02056058:
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    mov r1, r1, lsr #0xc
    orr r1, r1, ip, lsl #20
    tst r2, #0x80000000
    ldmeqia sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, lr}
    bx lr
loc_0205609c:
    subs r0, r0, r2
    sbc r1, r1, r3
    orrs lr, r1, r0
    beq loc_0205632c
    mov lr, ip, lsl #0x14
    and lr, lr, #0x80000000
    bic ip, ip, #0x800
    cmp r1, #0
    bmi loc_02056124
    bne loc_020560d4
    sub ip, ip, #0x20
    movs r1, r0
    mov r0, #0
    bmi loc_020560f0
loc_020560d4:
    clz r4, r1
    movs r1, r1, lsl r4
    rsb r4, r4, #0x20
    orr r1, r1, r0, lsr r4
    rsb r4, r4, #0x20
    mov r0, r0, lsl r4
    sub ip, ip, r4
loc_020560f0:
    cmp ip, #0
    bgt loc_0205612c
    rsb ip, ip, #0xc
    cmp ip, #0x20
    movge r0, r1
    movge r1, #0
    subge ip, ip, #0x20
    rsb r4, ip, #0x20
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    ldmia sp!, {r4, lr}
    bx lr
loc_02056124:
    cmp r1, #0
    subges ip, ip, #1
loc_0205612c:
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmia sp!, {r4, lr}
    bx lr
loc_02056148:
    mov lr, ip, lsl #0x14
    and lr, lr, #0x80000000
    bic ip, ip, #0x800
    cmp r1, #0
    bne loc_0205616c
    sub ip, ip, #0x20
    movs r1, r0
    mov r0, #0
    bmi loc_02056188
loc_0205616c:
    clz r4, r1
    movs r1, r1, lsl r4
    rsb r4, r4, #0x20
    orr r1, r1, r0, lsr r4
    rsb r4, r4, #0x20
    mov r0, r0, lsl r4
    sub ip, ip, r4
loc_02056188:
    cmp ip, #0
    orrgt ip, ip, lr, lsr #20
    bgt loc_02056058
    rsb ip, ip, #0xc
    cmp ip, #0x20
    movge r0, r1
    movge r1, #0
    subge ip, ip, #0x20
    rsb r4, ip, #0x20
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    ldmia sp!, {r4, lr}
    bx lr
loc_020561c0:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bics ip, ip, #0x800
    beq loc_0205622c
    orrs r4, r0, r1, lsl #1
    bne loc_02056308
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    beq loc_020562f4
    cmn r4, #0x200000
    bne loc_020562f4
    orrs r4, r2, r3, lsl #1
    beq loc_0205631c
    b loc_02056308
loc_02056208:
    cmp r4, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bic ip, ip, #0x800
    bics r4, r4, #0x800
    beq loc_020562a4
    orrs r4, r2, r3, lsl #1
    bne loc_02056308
    b loc_020562f4
loc_0205622c:
    orrs r4, r0, r1, lsl #1
    beq loc_0205626c
    mov ip, #1
    bic r1, r1, #0x80000000
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    cmnne r4, #0x200000
    mov r4, r4, lsr #0x15
    orr r4, r4, lr, lsr #20
    beq loc_02056208
    orr r3, r3, #0x80000000
    orr ip, ip, lr, lsr #20
    b loc_02055ff4
loc_0205626c:
    mov ip, r3, lsr #0x14
    mov r1, r3, lsl #0xb
    orr r1, r1, r2, lsr #21
    mov r0, r2, lsl #0xb
    movs r4, ip, lsl #0x15
    beq loc_02056298
    cmn r4, #0x200000
    bne loc_020562c0
    orrs r4, r0, r1, lsl #1
    bne loc_0205630c
    b loc_020562f4
loc_02056298:
    orrs r4, r0, r1, lsl #1
    beq loc_0205632c
    b loc_020562c0
loc_020562a4:
    orrs r4, r2, r3, lsl #1
    beq loc_020562d0
    mov r4, #1
    bic r3, r3, #0x80000000
    orr ip, ip, lr, lsr #20
    orr r4, r4, lr, lsr #20
    b loc_02055ff4
loc_020562c0:
    mov r1, r3
    mov r0, r2
    ldmia sp!, {r4, lr}
    bx lr
loc_020562d0:
    cmp r1, #0
    subges ip, ip, #1
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmia sp!, {r4, lr}
    bx lr
loc_020562f4:
    ldr r1, [pc, #0x40]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, lr}
    bx lr
loc_02056308:
    mov r1, r3
loc_0205630c:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, lr}
    bx lr
loc_0205631c:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, lr}
    bx lr
loc_0205632c:
    mov r1, #0
    mov r0, #0
    ldmia sp!, {r4, lr}
    bx lr
    dcd 0x7FF00000
}
