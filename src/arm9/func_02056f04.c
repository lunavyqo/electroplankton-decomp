// addr 0x02056f04 size 0x3b8
// _f_div — single-precision float division (reciprocal table + Newton) (MWCC soft-float runtime)
asm void func_02056f04()
{
    stmdb sp!, {lr}
    mov ip, #0xff
    ands r3, ip, r0, lsr #23
    cmpne r3, #0xff
    beq loc_020570d8
    ands ip, ip, r1, lsr #23
    cmpne ip, #0xff
    beq loc_02057114
    orr r1, r1, #0x800000
    orr r0, r0, #0x800000
    bic r2, r0, #0xff000000
    bic lr, r1, #0xff000000
loc_02056f34:
    cmp r2, lr
    movlo r2, r2, lsl #1
    sublo r3, r3, #1
    teq r0, r1
    sub r0, pc, #0x94
    ldrb r1, [r0, lr, lsr #15]
    rsb lr, lr, #0
    mov r0, lr, asr #1
    mul r0, r1, r0
    add r0, r0, #0x80000000
    mov r0, r0, lsr #6
    mul r0, r1, r0
    mov r0, r0, lsr #0xe
    mul r1, lr, r0
    sub ip, r3, ip
    mov r1, r1, lsr #0xc
    mul r1, r0, r1
    mov r0, r0, lsl #0xe
    add r0, r0, r1, lsr #15
    umull r1, r0, r2, r0
    mov r3, r0
    orrmi r0, r0, #0x80000000
    adds ip, ip, #0x7e
    bmi loc_020571dc
    cmp ip, #0xfe
    bge loc_02057290
    add r0, r0, ip, lsl #23
    mov ip, r1, lsr #0x1c
    cmp ip, #7
    beq loc_020570b8
    add r0, r0, r1, lsr #31
    ldmia sp!, {lr}
    bx lr
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
loc_020570b8:
    mov r1, r3, lsl #1
    add r1, r1, #1
    rsb lr, lr, #0
    mul r1, lr, r1
    cmp r1, r2, lsl #24
    addmi r0, r0, #1
    ldmia sp!, {lr}
    bx lr
loc_020570d8:
    eor lr, r0, r1
    and lr, lr, #0x80000000
    cmp r3, #0
    beq loc_02057130
    movs r0, r0, lsl #9
    bne loc_02057278
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq loc_02057268
    cmp ip, #0xff
    blt loc_02057268
    cmp r1, #0
    beq loc_02057284
    b loc_02057260
loc_02057114:
    eor lr, r0, r1
    and lr, lr, #0x80000000
    cmp ip, #0
    beq loc_02057194
loc_02057124:
    movs r1, r1, lsl #9
    bne loc_02057260
    b loc_020572b0
loc_02057130:
    movs r2, r0, lsl #9
    beq loc_02057164
    clz r3, r2
    movs r2, r2, lsl r3
    rsb r3, r3, #0
    mov r2, r2, lsr #8
    ands ip, ip, r1, lsr #23
    beq loc_020571bc
    cmp ip, #0xff
    beq loc_02057124
    orr r1, r1, #0x800000
    bic lr, r1, #0xff000000
    b loc_02056f34
loc_02057164:
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq loc_02057188
    cmp ip, #0xff
    blt loc_020572b0
    cmp r1, #0
    beq loc_020572b0
    b loc_02057260
loc_02057188:
    cmp r1, #0
    beq loc_02057284
    b loc_020572b0
loc_02057194:
    movs ip, r1, lsl #9
    beq loc_02057268
    mov lr, ip
    clz ip, lr
    movs lr, lr, lsl ip
    rsb ip, ip, #0
    mov lr, lr, lsr #8
    orr r0, r0, #0x800000
    bic r2, r0, #0xff000000
    b loc_02056f34
loc_020571bc:
    movs ip, r1, lsl #9
    beq loc_02057268
    mov lr, ip
    clz ip, lr
    movs lr, lr, lsl ip
    rsb ip, ip, #0
    mov lr, lr, lsr #8
    b loc_02056f34
loc_020571dc:
    and r0, r0, #0x80000000
    cmn ip, #0x18
    beq loc_02057250
    bmi loc_020572a8
    add r1, ip, #0x17
    mov r2, r2, lsl r1
    rsb ip, ip, #0
    mov r3, r3, lsr ip
    orr r0, r0, r3
    rsb lr, lr, #0
    mul r1, lr, r3
    cmp r1, r2
    ldmeqia sp!, {lr}
    bxeq lr
    add r1, r1, lr
    cmp r1, r2
    beq loc_02057244
    addmi r0, r0, #1
    subpl r1, r1, lr
    add r1, lr, r1, lsl #1
    cmp r1, r2, lsl #1
    and r3, r0, #1
    addmi r0, r0, #1
    addeq r0, r0, r3
    ldmia sp!, {lr}
    bx lr
loc_02057244:
    add r0, r0, #1
    ldmia sp!, {lr}
    bx lr
loc_02057250:
    cmn r2, lr
    addne r0, r0, #1
    ldmia sp!, {lr}
    bx lr
loc_02057260:
    mov r0, r1
    b loc_02057278
loc_02057268:
    mov r0, #0xff000000
    orr r0, lr, r0, lsr #1
    ldmia sp!, {lr}
    bx lr
loc_02057278:
    mvn r0, #0x80000000
    ldmia sp!, {lr}
    bx lr
loc_02057284:
    mvn r0, #0x80000000
    ldmia sp!, {lr}
    bx lr
loc_02057290:
    tst r0, #0x80000000
    mov r0, #0xff000000
    movne r0, r0, asr #1
    moveq r0, r0, lsr #1
    ldmia sp!, {lr}
    bx lr
loc_020572a8:
    ldmia sp!, {lr}
    bx lr
loc_020572b0:
    mov r0, lr
    ldmia sp!, {lr}
    bx lr
}
