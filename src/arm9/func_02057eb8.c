// addr 0x2057eb8 size 0x544
// _d_div soft-float double division (MWCC runtime)
asm void func_02057eb8()
{
    stmdb sp!, {r4, r5, r6, lr}
    ldr lr, [pc, #0x534]
    eor r4, r1, r3
    ands r12, lr, r1, lsr #19
    cmpne r12, lr
    beq loc_02058264
    bic r1, r1, lr, lsl #20
    orr r1, r1, #0x100000
    add r12, r12, r4, lsr #31
loc_02057edc:
    ands r4, lr, r3, lsr #19
    cmpne r4, lr
    beq loc_020582fc
    bic r3, r3, lr, lsl #20
    orr r3, r3, #0x100000
loc_02057ef0:
    sub r12, r12, r4
    cmp r1, r3
    cmpeq r0, r2
    bhs loc_02057f0c
    adds r0, r0, r0
    adc r1, r1, r1
    sub r12, r12, #2
loc_02057f0c:
    sub r4, pc, #0x24
    ldrb lr, [r4, r3, lsr #12]
    rsbs r2, r2, #0
    rsc r3, r3, #0
    mov r4, #0x20000000
    mla r5, lr, r3, r4
    mov r6, r3, lsl #0xa
    mov r5, r5, lsr #7
    mul lr, r5, lr
    orr r6, r6, r2, lsr #22
    mov lr, lr, lsr #0xd
    mul r5, lr, r6
    mov r6, r1, lsl #0xa
    orr r6, r6, r0, lsr #22
    mov r5, r5, lsr #0x10
    mul r5, lr, r5
    mov lr, lr, lsl #0xe
    add lr, lr, r5, lsr #16
    umull r5, r6, lr, r6
    umull r4, r5, r6, r2
    mla r5, r3, r6, r5
    mov r4, r4, lsr #0x1a
    orr r4, r4, r5, lsl #6
    add r4, r4, r0, lsl #2
    umull lr, r5, r4, lr
    mov r4, #0
    adds r5, r5, r6, lsl #24
    adc r4, r4, r6, lsr #8
    cmp r12, #0x800
    bge loc_020580f0
    add r12, r12, #0x7f0
    adds r12, r12, #0xc
    bmi loc_02058108
    orr r1, r4, r12, lsl #31
    bic r12, r12, #1
    add r1, r1, r12, lsl #19
    tst lr, #0x80000000
    bne loc_02057fe0
    rsbs r2, r2, #0
    mov r4, r4, lsl #1
    add r4, r4, r5, lsr #31
    mul lr, r2, r4
    mov r6, #0
    mov r4, r5, lsl #1
    orr r4, r4, #1
    umlal r6, lr, r4, r2
    rsc r3, r3, #0
    mla lr, r4, r3, lr
    cmp lr, r0, lsl #21
    bmi loc_02057fe0
    mov r0, r5
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_02057fe0:
    adds r0, r5, #1
    adc r1, r1, #0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_02057ff0:
    dcd 0xFDFEFFFF
    dcd 0xF9FAFBFC
    dcd 0xF5F6F7F8
    dcd 0xF1F2F3F4
    dcd 0xEEEFF0F0
    dcd 0xEAEBECED
    dcd 0xE7E8E9EA
    dcd 0xE4E5E6E6
    dcd 0xE1E2E2E3
    dcd 0xDEDFDFE0
    dcd 0xDBDCDCDD
    dcd 0xD8D9D9DA
    dcd 0xD5D6D7D7
    dcd 0xD2D3D4D4
    dcd 0xD0D0D1D2
    dcd 0xCDCECECF
    dcd 0xCBCBCCCC
    dcd 0xC8C9C9CA
    dcd 0xC6C6C7C8
    dcd 0xC3C4C5C5
    dcd 0xC1C2C2C3
    dcd 0xBFBFC0C0
    dcd 0xBDBDBEBE
    dcd 0xBABBBCBC
    dcd 0xB8B9B9BA
    dcd 0xB6B7B7B8
    dcd 0xB4B5B5B6
    dcd 0xB2B3B3B4
    dcd 0xB0B1B1B2
    dcd 0xAFAFAFB0
    dcd 0xADADAEAE
    dcd 0xABABACAC
    dcd 0xA9AAAAAA
    dcd 0xA7A8A8A9
    dcd 0xA6A6A7A7
    dcd 0xA4A4A5A5
    dcd 0xA2A3A3A4
    dcd 0xA1A1A2A2
    dcd 0x9FA0A0A0
    dcd 0x9E9E9E9F
    dcd 0x9C9D9D9D
    dcd 0x9B9B9B9C
    dcd 0x999A9A9A
    dcd 0x98989999
    dcd 0x96979798
    dcd 0x95959696
    dcd 0x94949495
    dcd 0x92939393
    dcd 0x91919292
    dcd 0x90909191
    dcd 0x8F8F8F90
    dcd 0x8D8E8E8E
    dcd 0x8C8C8D8D
    dcd 0x8B8B8C8C
    dcd 0x8A8A8A8B
    dcd 0x8989898A
    dcd 0x88888888
    dcd 0x86878787
    dcd 0x85868686
    dcd 0x84858585
    dcd 0x83838484
    dcd 0x82828383
    dcd 0x81818282
    dcd 0x80808181
loc_020580f0:
    movs r1, r12, lsl #0x1f
    orr r1, r1, #0x7f000000
    orr r1, r1, #0xf00000
    mov r0, #0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_02058108:
    mvn r6, r12, asr #1
    cmp r6, #0x34
    bgt loc_02058254
    beq loc_02058230
    cmp r6, #0x14
    bge loc_02058150
    rsb r6, r6, #0x13
    mov lr, r0, lsl r6
    rsb r6, r6, #0x14
    mov r0, r5, lsr r6
    rsb r6, r6, #0x20
    orr r0, r0, r4, lsl r6
    rsb r6, r6, #0x20
    mov r4, r4, lsr r6
    orr r1, r4, r12, lsl #31
    mov r12, lr
    mov lr, #0
    b loc_02058180
loc_02058150:
    rsb r6, r6, #0x33
    mov lr, r1, lsl r6
    mov r1, r12, lsl #0x1f
    rsb r6, r6, #0x20
    orr r12, lr, r0, lsr r6
    rsb r6, r6, #0x20
    mov lr, r0, lsl r6
    mov r5, r5, lsr #0x15
    orr r5, r5, r4, lsl #11
    rsb r6, r6, #0x1f
    mov r0, r5, lsr r6
    mov r4, #0
loc_02058180:
    rsbs r2, r2, #0
    mul r4, r2, r4
    mov r5, #0
    umlal r5, r4, r2, r0
    rsc r3, r3, #0
    mla r4, r0, r3, r4
    cmp r4, r12
    cmpeq r5, lr
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
    adds r5, r5, r2
    adc r4, r4, r3
    cmp r4, r12
    bmi loc_02058224
    bne loc_020581c8
    cmp r5, lr
    beq loc_02058214
    blo loc_02058224
loc_020581c8:
    subs r5, r5, r2
    sbc r4, r4, r3
loc_020581d0:
    adds r5, r5, r5
    adc r4, r4, r4
    adds r5, r5, r2
    adc r4, r4, r3
    adds lr, lr, lr
    adc r12, r12, r12
    cmp r4, r12
    bmi loc_02058214
    ldmneia sp!, {r4, r5, r6, lr}
    bxne lr
    cmp r5, lr
    blo loc_02058214
    ldmneia sp!, {r4, r5, r6, lr}
    bxne lr
    tst r0, #1
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
loc_02058214:
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_02058224:
    adds r0, r0, #1
    adc r1, r1, #0
    b loc_020581d0
loc_02058230:
    rsbs r2, r2, #0
    rsc r3, r3, #0
    cmp r1, r3
    cmpeq r0, r2
    mov r1, r12, lsl #0x1f
    mov r0, #0
    movne r0, #1
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_02058254:
    mov r1, r12, lsl #0x1f
    mov r0, #0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_02058264:
    orrs r5, r0, r1, lsl #1
    beq loc_02058388
    cmp r12, lr
    beq loc_020582cc
    movs r1, r1, lsl #0xc
    beq loc_020582a8
    clz r5, r1
    movs r1, r1, lsl r5
    sub r12, r12, r5
    add r5, r12, #0x1f
    mov r1, r1, lsr #0xb
    orr r1, r1, r0, lsr r5
    rsb r5, r5, #0x20
    mov r0, r0, lsl r5
    mov r12, r12, lsl #1
    orr r12, r12, r4, lsr #31
    b loc_02057edc
loc_020582a8:
    mvn r12, #0x13
    clz r5, r0
    movs r0, r0, lsl r5
    sub r12, r12, r5
    mov r1, r0, lsr #0xb
    mov r0, r0, lsl #0x15
    mov r12, r12, lsl #1
    orr r12, r12, r4, lsr #31
    b loc_02057edc
loc_020582cc:
    orrs r5, r0, r1, lsl #12
    bne loc_020583b0
    bic r5, r3, #0x80000000
    cmp r5, lr, lsl #19
    bhs loc_020582f0
    and r5, r3, #0x80000000
    eor r1, r5, r1
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_020582f0:
    orrs r5, r2, r3, lsl #12
    bne loc_020583d0
    b loc_020583e8
loc_020582fc:
    orrs r5, r2, r3, lsl #1
    beq loc_02058374
    cmp r4, lr
    beq loc_0205835c
    movs r3, r3, lsl #0xc
    beq loc_0205833c
    clz r5, r3
    movs r3, r3, lsl r5
    sub r4, r4, r5
    add r5, r4, #0x1f
    mov r3, r3, lsr #0xb
    orr r3, r3, r2, lsr r5
    rsb r5, r5, #0x20
    mov r2, r2, lsl r5
    mov r4, r4, lsl #1
    b loc_02057ef0
loc_0205833c:
    mvn r4, #0x13
    clz r5, r2
    movs r2, r2, lsl r5
    sub r4, r4, r5
    mov r3, r2, lsr #0xb
    mov r2, r2, lsl #0x15
    mov r4, r4, lsl #1
    b loc_02057ef0
loc_0205835c:
    orrs r5, r2, r3, lsl #12
    bne loc_020583d0
    mov r1, r12, lsl #0x1f
    mov r0, #0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_02058374:
    mov r1, r12, lsl #0x1f
    orr r1, r1, lr, lsl #19
    mov r0, #0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_02058388:
    orrs r5, r2, r3, lsl #1
    beq loc_020583e8
    bic r5, r3, #0x80000000
    cmp r5, lr, lsl #19
    cmpeq r2, #0
    bhi loc_020583d0
    eor r1, r1, r3
    and r1, r1, #0x80000000
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_020583b0:
    tst r1, #0x80000
    beq loc_020583e8
    bic r5, r3, #0x80000000
    cmp r5, lr, lsl #19
    cmpeq r2, #0
    bhi loc_020583d0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_020583d0:
    tst r3, #0x80000
    beq loc_020583e8
    mov r1, r3
    mov r0, r2
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_020583e8:
    orr r1, r1, #0x7f000000
    orr r1, r1, #0xf80000
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
loc_020583f8:
    dcd 0x00000FFE
}
