// addr 0x02006860 size 0x1b0

void func_020091a4(void);

asm void func_02006860(void) {
    stmdb sp!, {r4, lr}
    sub sp, sp, #8
    ldr r1, =0x020708a4
    ldr r2, =0x02070cac
    ldrb r3, [r1, #0xa7e]
    ldrb r0, [r1, #0xa84]
    mov r4, #0
    ldrb r3, [r2, r3]
    cmp r0, #0
    beq loc_0200689c
    cmp r0, #1
    beq loc_020068c0
    cmp r0, #2
    beq loc_02006954
    b loc_020069ac
loc_0200689c:
    cmp r3, #0x8c
    blt loc_020069ac
    ldr r0, =0x020712a4
    mov r2, #1
    strb r2, [r1, #0xa87]
    strb r2, [r1, #0xa84]
    strh r2, [r0, #0x50]
    strb r3, [r1, #0xa85]
    b loc_020069ac
loc_020068c0:
    cmp r3, #0x1e
    bge loc_02006934
    ldr r0, =0x020712a4
    ldrb r2, [r1, #0xa85]
    ldrh r3, [r0, #0x50]
    strb r2, [r1, #0xa86]
    strh r3, [r0, #0x52]
    cmp r3, #0x3c
    blo loc_0200691c
    ldr r2, =0x88888889
    mov r0, r3, lsr #0x1f
    smull r1, ip, r2, r3
    add ip, r3, ip
    mov ip, ip, asr #5
    add ip, r0, ip
    mov r4, #0x16
    cmp ip, #2
    movge r4, #0x17
    cmp ip, #5
    movge r4, #0x18
    cmp ip, #0xa
    movge r4, #0x19
    b loc_020069ac
loc_0200691c:
    cmp r3, #5
    movhs r0, #2
    strhsb r0, [r1, #0xa84]
    strhsb r4, [r1, #0xa88]
    strlob r4, [r1, #0xa84]
    b loc_020069ac
loc_02006934:
    ldrb r0, [r1, #0xa85]
    cmp r3, r0
    ldr r0, =0x020712a4
    strgtb r3, [r1, #0xa85]
    ldrh r1, [r0, #0x50]
    add r1, r1, #1
    strh r1, [r0, #0x50]
    b loc_020069ac
loc_02006954:
    ldrb r0, [r1, #0xa88]
    add r0, r0, #1
    strb r0, [r1, #0xa88]
    ldrb r0, [r1, #0xa88]
    cmp r0, #0x1e
    bls loc_02006988
    ldrb r0, [r1, #0xa87]
    mov r1, #0
    cmp r0, #4
    addls r4, r0, #0x11
    ldr r0, =0x020708a4
    strb r1, [r0, #0xa84]
    b loc_020069ac
loc_02006988:
    cmp r3, #0x8c
    blt loc_020069ac
    ldrb r3, [r1, #0xa87]
    mov r2, #1
    ldr r0, =0x020712a4
    add r3, r3, #1
    strb r3, [r1, #0xa87]
    strh r2, [r0, #0x50]
    strb r2, [r1, #0xa84]
loc_020069ac:
    cmp r4, #0
    addle sp, sp, #8
    ldmleia sp!, {r4, lr}
    bxle lr
    mov r1, #0x10
    ldr r0, =0x020708a4
    str r1, [sp]
    ldrb r0, [r0, #0xa85]
    mov r1, #0x8c
    mov r2, #0xff
    mov r3, #1
    bl func_020091a4
    ldr r2, =0x020712f8
    ldr r1, =0x020708a4
    strb r0, [r2, r4]
    mov r0, #0
    strb r0, [r1, #0xa84]
    add sp, sp, #8
    ldmia sp!, {r4, lr}
    bx lr
}
