// addr 0x020556d4 size 0x318
// _d_add — double add (MWCC soft-float runtime)
void ext_02055f9c(void);

asm double func_020556d4(double a, double b)
{
    stmdb sp!, {r4, lr}
    eors r12, r1, r3
    eormi r3, r3, #0x80000000
    bmi ext_02055f9c
    subs r12, r0, r2
    sbcs lr, r1, r3
    bhs loc_02055700
    adds r2, r2, r12
    adc r3, r3, lr
    subs r0, r0, r12
    sbc r1, r1, lr
loc_02055700:
    mov lr, #0x80000000
    mov r12, r1, lsr #0x14
    orr r1, lr, r1, lsl #11
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #0xb
    movs r4, r12, lsl #0x15
    cmnne r4, #0x200000
    beq loc_020557fc
    mov r4, r3, lsr #0x14
    orr r3, lr, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs lr, r4, lsl #0x15
    beq loc_02055844
loc_02055738:
    subs r4, r12, r4
    beq loc_02055790
    cmp r4, #0x20
    ble loc_02055774
    cmp r4, #0x38
    movge r4, #0x3f
    sub r4, r4, #0x20
    rsb lr, r4, #0x20
    orrs lr, r2, r3, lsl lr
    mov r2, r3, lsr r4
    orrne r2, r2, #1
    adds r0, r0, r2
    adcs r1, r1, #0
    blo loc_020557b8
    b loc_0205579c
loc_02055774:
    rsb lr, r4, #0x20
    movs lr, r2, lsl lr
    rsb lr, r4, #0x20
    mov r2, r2, lsr r4
    orr r2, r2, r3, lsl lr
    mov r3, r3, lsr r4
    orrne r2, r2, #1
loc_02055790:
    adds r0, r0, r2
    adcs r1, r1, r3
    blo loc_020557b8
loc_0205579c:
    add r12, r12, #1
    and r4, r0, #1
    movs r1, r1, rrx
    orr r0, r4, r0, rrx
    mov lr, r12, lsl #0x15
    cmn lr, #0x200000
    beq loc_020559c8
loc_020557b8:
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    mov r1, r1, lsr #0xc
    orr r1, r1, r12, lsl #20
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
loc_020557fc:
    cmp r12, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bics r12, r12, #0x800
    beq loc_02055868
    orrs r4, r0, r1, lsl #1
    bne loc_020559a4
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    beq loc_02055990
    cmn r4, #0x200000
    bne loc_02055990
    orrs r4, r2, r3, lsl #1
    beq loc_02055990
    b loc_020559a4
loc_02055844:
    cmp r4, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bic r12, r12, #0x800
    bics r4, r4, #0x800
    beq loc_020558d4
    orrs r4, r2, r3, lsl #1
    bne loc_020559a4
    b loc_02055990
loc_02055868:
    orrs r4, r0, r1, lsl #1
    beq loc_020558a8
    mov r12, #1
    bic r1, r1, #0x80000000
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    cmnne r4, #0x200000
    mov r4, r4, lsr #0x15
    orr r4, r4, lr, lsr #20
    beq loc_02055844
    orr r3, r3, #0x80000000
    orr r12, r12, lr, lsr #20
    b loc_02055738
loc_020558a8:
    mov r12, r3, lsr #0x14
    mov r1, r3, lsl #0xb
    orr r1, r1, r2, lsr #21
    mov r0, r2, lsl #0xb
    movs r4, r12, lsl #0x15
    beq loc_0205595c
    cmn r4, #0x200000
    bne loc_0205595c
    orrs r4, r0, r1, lsl #1
    beq loc_02055990
    b loc_020559a8
loc_020558d4:
    orrs r4, r2, r3, lsl #1
    beq loc_0205596c
    mov r4, #1
    bic r3, r3, #0x80000000
    cmp r1, #0
    bpl loc_020558f8
    orr r12, r12, lr, lsr #20
    orr r4, r4, lr, lsr #20
    b loc_02055738
loc_020558f8:
    adds r0, r0, r2
    adcs r1, r1, r3
    blo loc_02055918
    add r12, r12, #1
    and r4, r0, #1
    movs r1, r1, rrx
    mov r0, r0, rrx
    orr r0, r0, r4
loc_02055918:
    cmp r1, #0
    subges r12, r12, #1
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, r12, lsl #20
    ldmeqia sp!, {r4, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqia sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, lr}
    bxeq lr
loc_0205595c:
    mov r1, r3
    mov r0, r2
    ldmia sp!, {r4, lr}
    bx lr
loc_0205596c:
    cmp r1, #0
    subges r12, r12, #1
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, r12, lsl #20
    ldmia sp!, {r4, lr}
    bx lr
loc_02055990:
    ldr r1, [pc, #0x50]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, lr}
    bx lr
loc_020559a4:
    mov r1, r3
loc_020559a8:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, lr}
    bx lr
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, lr}
    bx lr
loc_020559c8:
    cmp r12, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    ldr r1, [pc, #0xc]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, lr}
    bx lr
    dcd 0x7ff00000
}
