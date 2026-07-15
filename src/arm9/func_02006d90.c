// addr 0x02006d90 size 0x680

void func_02007410(void);
void func_0200742c(void);
void func_020074e8(void);
void func_0200777c(void);
void func_020078a4(void);
void func_02007924(void);
void func_020091a4(void);
void func_02009290(void);
void func_02009328(void);

asm void func_02006d90(void) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0xfc
    ldr r0, =0x020708a4
    mov r1, #0x19
    ldrb r5, [r0, #0xa7e]
    mov r0, #0x78
    ldr r6, =0x02070eac
    str r1, [sp]
    str r0, [sp, #4]
    mov r0, #0x28
    str r0, [sp, #8]
    mov r0, #0x14
    str r0, [sp, #0xc]
    mov r0, #0xf
    str r0, [sp, #0x10]
    add r4, sp, #0x74
    str r4, [sp, #0x14]
    ldr r1, =0x0206feac
    mov r0, #0x80
    mov r2, #0x7d0
    mov r3, #0
    add r4, r6, r5, lsl #2
    bl func_02007924
    ldr r1, =0x0206f768
    cmp r0, #0x50
    ldr r2, [r1]
    add r2, r2, #1
    str r2, [r1]
    blt loc_02006e58
    bl func_020078a4
    ldr r1, =0x0206f760
    strh r0, [r4]
    ldr r0, [r1]
    mov r1, #8
    cmp r0, #0xff
    movgt r0, #0xff
    strb r0, [r4, #2]
    mov r0, #0x28
    str r0, [sp]
    str r1, [sp, #4]
    str r1, [sp, #8]
    ldr r0, =0x020712b0
    ldr r1, =0x0206feac
    str r0, [sp, #0xc]
    mov r0, #0x80
    mov r2, #0x7d0
    mov r3, #0x78
    bl func_0200777c
    strb r0, [r4, #3]
    b loc_02006e68
loc_02006e58:
    mov r0, #0
    strh r0, [r4]
    strb r0, [r4, #2]
    strb r0, [r4, #3]
loc_02006e68:
    ldr r0, =0x020708a4
    ldrh r3, [r4]
    ldrh r2, [r4, #2]
    ldr r1, =0x020712a4
    ldrb r11, [r0, #0xa7e]
    strh r3, [r1, #8]
    strh r2, [r1, #0xa]
    mov r2, #1
    mov r3, #0
loc_02006e8c:
    ldr r0, =0x02070eac
    mov r1, r11, lsl #2
    ldrh r0, [r0, r1]
    cmp r0, #0
    movne r2, #0
    bne loc_02006eb8
    subs r11, r11, #1
    add r3, r3, #1
    addmi r11, r11, #0x100
    cmp r3, #0x14
    blt loc_02006e8c
loc_02006eb8:
    ldr r0, =0x02070eac
    mov r1, r11, lsl #2
    ldrh r8, [r0, r1]
    cmp r8, #0
    moveq r2, #0
    cmp r2, #0
    addeq sp, sp, #0xfc
    ldmeqia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bxeq lr
    ldr r4, =0x0205d280
    add r10, sp, #0x7c
    add r7, sp, #0x90
    ldmia r4!, {r0, r1, r2, r3}
    mov r6, r10
    ldr r9, =0x0205d2ac
    stmia r10!, {r0, r1, r2, r3}
    ldr r4, [r4]
    mov r5, r7
    str r4, [r10]
    ldmia r9!, {r0, r1, r2, r3}
    stmia r7!, {r0, r1, r2, r3}
    mov r0, #0
    str r0, [sp, #0x24]
    ldmia r9!, {r0, r1, r2, r3}
    stmia r7!, {r0, r1, r2, r3}
    ldmia r9, {r0, r1}
    stmia r7, {r0, r1}
    ldr r0, [sp, #0x24]
    add r4, sp, #0xcc
    str r0, [r4]
    str r0, [r4, #4]
    str r0, [r4, #8]
    str r0, [r4, #0xc]
    str r0, [r4, #0x10]
    str r0, [sp, #0x30]
    str r0, [sp, #0x40]
    str r0, [sp, #0x3c]
    str r0, [sp, #0x38]
    str r0, [sp, #0x34]
    mov r0, #3
    str r0, [sp, #0x48]
    mov r0, #5
    str r0, [sp, #0x44]
    ldr r0, [sp, #0x24]
    str r11, [sp, #0x20]
    add r10, sp, #0xb8
    str r0, [sp, #0x2c]
    str r0, [sp, #0x28]
loc_02006f78:
    ldr r0, =0x02070eac
    mov r1, r11, lsl #2
    ldrh r9, [r0, r1]
    ldr r1, [sp, #0x28]
loc_02006f88:
    ldr r0, [r6, r1, lsl #2]
    cmp r0, #0
    bne loc_02006fa0
    add r1, r1, #1
    cmp r1, #5
    blt loc_02006f88
loc_02006fa0:
    cmp r1, #5
    bge loc_0200711c
    ldr r7, [sp, #0x2c]
loc_02006fac:
    ldr r0, [r6, r7, lsl #2]
    mov r1, r7, lsl #2
    cmp r0, #4
    addls pc, pc, r0, lsl #2
    b loc_020070a0
    b loc_020070a0
    b loc_02006fd4
    b loc_02007040
    b loc_02006fd4
    b loc_02007040
loc_02006fd4:
    cmp r0, #1
    ldr r0, [r4, r1]
    ldreq r2, [sp, #0x30]
    add r0, r0, #1
    str r0, [r4, r1]
    ldrne r2, [r5, r7, lsl #3]
    mov r0, r9
    mov r1, r8
    bl func_020074e8
    cmp r0, #0
    bne loc_020070a0
    cmp r9, #0
    bne loc_02007034
    mov r0, r7, lsl #2
    ldr r1, [r4, r7, lsl #2]
    cmp r1, #0xc
    blt loc_02007034
    ldr r1, [r6, r0]
    add r1, r1, #1
    str r1, [r6, r0]
    ldr r1, [sp, #0x34]
    str r1, [r10, r0]
    str r1, [r4, r0]
    b loc_020070a0
loc_02007034:
    ldr r0, [sp, #0x38]
    str r0, [r6, r7, lsl #2]
    b loc_020070a0
loc_02007040:
    ldr r3, [r10, r1]
    ldr r2, [r10, r1]
    cmp r3, #0x18
    add r2, r2, #1
    ldrgt r0, [sp, #0x3c]
    str r2, [r10, r1]
    strgt r0, [r6, r1]
    bgt loc_020070a0
    cmp r9, #0
    beq loc_020070a0
    add r0, r0, r0, lsr #31
    mov r0, r0, asr #1
    sub r3, r0, #1
    add r2, r5, r7, lsl #3
    ldr r2, [r2, r3, lsl #2]
    mov r0, r9
    mov r1, r8
    bl func_020074e8
    cmp r0, #0
    ldrne r0, [r6, r7, lsl #2]
    addne r0, r0, #1
    strne r0, [r6, r7, lsl #2]
    ldreq r0, [sp, #0x40]
    streq r0, [r6, r7, lsl #2]
loc_020070a0:
    cmp r7, #3
    ldrlt r1, [sp, #0x44]
    ldr r0, [r6, r7, lsl #2]
    ldrge r1, [sp, #0x48]
    cmp r0, r1
    bne loc_020070f4
    ldr r1, [sp, #0x24]
    mov r0, r11
    bl func_02007410
    mov r4, #0x10
    mov r1, #0x19
    mov r2, #0x32
    mov r3, #1
    str r4, [sp]
    bl func_020091a4
    ldr r1, =0x020712f8
    add r2, r7, #0x1a
    strb r0, [r1, r2]
    add sp, sp, #0xfc
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
loc_020070f4:
    add r7, r7, #1
    cmp r7, #5
    blt loc_02006fac
    ldr r0, [sp, #0x24]
    subs r11, r11, #1
    add r0, r0, #1
    addmi r11, r11, #0x100
    str r0, [sp, #0x24]
    cmp r0, #0xec
    blt loc_02006f78
loc_0200711c:
    mov r0, #0x300
    str r0, [sp, #0x58]
    mov r0, #0x200
    str r0, [sp, #0x5c]
    ldr r0, [sp, #0x58]
    mov r7, #0
    rsb r0, r0, #0
    str r0, [sp, #0x4c]
    ldr r0, [sp, #0x5c]
    str r7, [sp, #0x68]
    rsb r0, r0, #0
    str r0, [sp, #0x60]
    mvn r0, #0xff
    str r0, [sp, #0x50]
    mov r0, #0x100
    str r0, [sp, #0x54]
    mov r0, #1
    str r7, [sp, #0x70]
    str r7, [sp, #0x6c]
    str r0, [sp, #0x64]
loc_0200716c:
    cmp r7, #0
    ldrne r9, [sp, #0x4c]
    ldr r6, [sp, #0x20]
    ldreq r9, [sp, #0x50]
    cmp r7, #0
    ldrne r10, [sp, #0x54]
    ldr r11, [sp, #0x64]
    ldreq r10, [sp, #0x58]
    cmp r7, #0
    ldrne r0, [sp, #0x5c]
    ldr r5, [sp, #0x68]
    strne r0, [sp, #0x1c]
    ldreq r0, =0xfffe7960
    mov r2, r8
    streq r0, [sp, #0x1c]
    cmp r7, #0
    ldrne r0, =0x000186a0
    strne r0, [sp, #0x18]
    ldreq r0, [sp, #0x60]
    streq r0, [sp, #0x18]
loc_020071bc:
    ldr r0, =0x02070eac
    mov r1, r6, lsl #2
    ldrh r4, [r0, r1]
    cmp r4, #0
    bne loc_020071e0
    cmp r5, #0x18
    mov r4, r2
    ldrlt r11, [sp, #0x6c]
    b loc_02007214
loc_020071e0:
    sub r0, r4, r2
    mov r1, r9
    mov r2, r10
    bl func_02009290
    cmp r0, #0
    ldreq r11, [sp, #0x70]
    beq loc_02007214
    subs r6, r6, #1
    add r5, r5, #1
    addmi r6, r6, #0x100
    mov r2, r4
    cmp r5, #0x40
    blt loc_020071bc
loc_02007214:
    cmp r11, #0
    beq loc_02007278
    ldr r1, [sp, #0x1c]
    ldr r2, [sp, #0x18]
    sub r0, r8, r4
    bl func_02009290
    cmp r0, #0
    beq loc_02007278
    mov r0, r6
    mov r1, r5
    bl func_02007410
    cmp r7, #0
    movne r5, #0x1f
    mov r4, #0x10
    mov r1, #0x19
    mov r2, #0x32
    mov r3, #1
    moveq r5, #0x20
    str r4, [sp]
    bl func_020091a4
    ldr r1, =0x020712f8
    add sp, sp, #0xfc
    strb r0, [r1, r5]
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
loc_02007278:
    add r7, r7, #1
    cmp r7, #1
    ble loc_0200716c
    ldr r0, =0x0205d27c
    ldr r0, [r0]
    cmp r0, #0
    addeq sp, sp, #0xfc
    ldmeqia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bxeq lr
    ldr r0, [sp, #0x20]
    add r2, sp, #0x78
    mvn r1, #0x1f
    bl func_0200742c
    mov r5, r0
    mov r2, r8
    mov r4, #0
loc_020072b8:
    ldr r0, [sp, #0x20]
    mov r1, r0, lsl #2
    ldr r0, =0x02070eac
    ldrh r6, [r0, r1]
    sub r0, r6, r2
    bl func_02009328
    cmp r0, #0x200
    addgt sp, sp, #0xfc
    ldmgtia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bxgt lr
    ldr r0, [sp, #0x20]
    add r4, r4, #1
    subs r0, r0, #1
    str r0, [sp, #0x20]
    addmi r0, r0, #0x100
    strmi r0, [sp, #0x20]
    mov r2, r6
    cmp r4, #0xc
    blt loc_020072b8
    ldr r0, [sp, #0x78]
    cmp r0, #1
    bne loc_02007348
    cmp r5, #0x50
    blt loc_02007348
    mov r4, #0x10
    mov r0, r5
    mov r1, #0x50
    mov r2, #0x64
    mov r3, #1
    str r4, [sp]
    bl func_020091a4
    ldr r1, =0x020708a4
    add sp, sp, #0xfc
    strb r0, [r1, #0xa75]
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
loc_02007348:
    ldr r4, =0x0205d294
    add r3, sp, #0xe0
    mov r2, #0xc
loc_02007354:
    ldrb r1, [r4], #1
    ldrb r0, [r4], #1
    subs r2, r2, #1
    strb r1, [r3], #1
    strb r0, [r3], #1
    bne loc_02007354
    mov r4, #0x10
    mov r0, r5
    mov r1, #0x19
    mov r2, #0x32
    mov r3, #1
    str r4, [sp]
    bl func_020091a4
    ldr r3, =0x2aaaaaab
    mov r1, r8, lsr #0x1f
    smull r2, r4, r3, r8
    mov r4, r4, asr #9
    ldr r3, =0x00000c00
    add r4, r1, r4
    smull r1, r2, r3, r4
    sub r4, r8, r1
    mov r1, r4, asr #6
    add r2, sp, #0xe0
    add r1, r4, r1, lsr #25
    ldrb r2, [r2, r1, asr #7]
    ldr r1, =0x020712f8
    add r2, r2, #0x22
    strb r0, [r1, r2]
    add sp, sp, #0xfc
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
}
