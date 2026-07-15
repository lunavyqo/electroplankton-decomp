// addr 0x02006a10 size 0x380

void func_020076f4(void);
void func_020091a4(void);
void func_02009290(void);

asm void func_02006a10(void) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #0x50
    mov r1, #0x3e8
    str r1, [sp]
    ldr r0, =0x020708a4
    ldr r1, =0x0206ffac
    ldrb r0, [r0, #0xa7f]
    mov r4, #0
    mov r3, r4
    add r1, r1, r0, lsl #8
    mov r0, #0x80
    mov r2, #0x7d0
    bl func_020076f4
    mov r1, r0, asr #3
    add r0, r0, r1, lsr #28
    mov r3, r0, asr #4
    ldr r0, =0x020708a4
    cmp r3, #0xff
    movgt r5, #0xff
    movle r5, r3
    ldrb r2, [r0, #0xa7e]
    ldr r1, =0x02070cac
    cmp r3, #0x23
    strb r5, [r1, r2]
    bge loc_02006af8
    ldrb r3, [r0, #0xa7e]
    mov r2, #0
    mov r5, r2
    ldr r1, =0x0206f8a4
loc_02006a84:
    subs r3, r3, #1
    addmi r3, r3, #0x100
    add r0, r1, r3
    add r0, r0, #0x1000
    ldrb r0, [r0, #0x408]
    cmp r0, #0x23
    blt loc_02006ab4
    add r5, r5, #1
    cmp r0, r2
    movgt r2, r0
    cmp r5, #5
    ble loc_02006a84
loc_02006ab4:
    ldr r0, =0x020708a4
    ldrb r0, [r0, #0xa83]
    cmp r0, #0
    movne r3, #0x2d
    moveq r3, #0x3c
    cmp r0, #0
    ldrne r0, =0x020708a4
    ldrneb r1, [r0, #0xa83]
    subne r1, r1, #1
    strneb r1, [r0, #0xa83]
    cmp r5, #5
    bgt loc_02006af8
    cmp r2, r3
    ldrge r0, =0x020708a4
    movge r1, #0x15
    movge r4, r2
    strgeb r1, [r0, #0xa83]
loc_02006af8:
    ldr r0, =0x020708a4
    cmp r4, #0
    ldrb r2, [r0, #0xa7e]
    ldr r1, =0x02070dac
    addne sp, sp, #0x50
    strb r4, [r1, r2]
    ldmneia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    bxne lr
    ldrb r1, [r0, #0xa7e]
    mov r5, #1
    mov r4, #0
    ldr r3, =0x0206f8a4
    mov r2, r4
loc_02006b2c:
    subs r1, r1, #1
    addmi r1, r1, #0x100
    cmp r4, #0x1f
    bge loc_02006b58
    add r0, r3, r1
    add r0, r0, #0x1000
    ldrb r0, [r0, #0x508]
    cmp r0, #0
    beq loc_02006b6c
    mov r5, #0
    b loc_02006b78
loc_02006b58:
    add r0, r3, r1
    add r0, r0, #0x1000
    ldrb r0, [r0, #0x508]
    cmp r0, #0
    moveq r5, r2
loc_02006b6c:
    add r4, r4, #1
    cmp r4, #0x1f
    ble loc_02006b2c
loc_02006b78:
    cmp r5, #0
    addeq sp, sp, #0x50
    ldmeqia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    bxeq lr
    mov r10, #0
    mov r4, r10
    mov r3, r10
    mov r7, #1
    mov r5, #0x3e8
    add r6, sp, #4
    ldr r8, =0x0206f8a4
    b loc_02006bec
loc_02006ba8:
    subs r1, r1, #1
    addmi r1, r1, #0x100
    add r2, r8, r1
    add r2, r2, #0x1000
    ldrb r9, [r2, #0x508]
    cmp r9, #0
    ble loc_02006bec
    sub r2, r7, #1
    cmp r10, r5
    movlt r5, r10
    cmp r10, r4
    movgt r4, r10
    str r10, [r6, r2, lsl #2]
    cmp r9, r0
    add r7, r7, #1
    movgt r0, r9
    mov r10, r3
loc_02006bec:
    cmp r7, #0x14
    bgt loc_02006c00
    add r10, r10, #1
    cmp r10, #0x1e
    ble loc_02006ba8
loc_02006c00:
    mov r6, #0x10
    mov r1, #0x3c
    mov r2, #0x64
    mov r3, #1
    str r6, [sp]
    bl func_020091a4
    mov r6, r0
    cmp r7, #3
    blt loc_02006cdc
    sub r0, r4, r5
    add r0, r0, #1
    cmp r0, #5
    ble loc_02006cdc
    cmp r7, #6
    movge r9, #5
    sublt r9, r7, #2
    cmp r9, #0
    blt loc_02006cdc
    ldr r1, =0x0205d2d4
    mov r0, #0x14
    mla r12, r9, r0, r1
    add r0, sp, #4
    mov r1, #0
    mov r2, #1
loc_02006c60:
    mov lr, r2
    mov r8, r1
loc_02006c68:
    rsb r3, r8, #4
    ldr r3, [r12, r3, lsl #2]
    cmp r3, #0
    bne loc_02006c88
    add r3, r8, #1
    cmp r7, r3
    movne lr, r1
    b loc_02006cb4
loc_02006c88:
    ldr r10, [r0, r8, lsl #2]
    cmp r10, #0x14
    movgt r10, r2
    movle r10, r1
    add r10, r10, #1
    cmp r10, r3
    movne lr, r1
    bne loc_02006cb4
    add r8, r8, #1
    cmp r8, #4
    ble loc_02006c68
loc_02006cb4:
    cmp lr, #0
    ldrne r0, =0x020712f8
    addne r1, r9, #0xc
    addne sp, sp, #0x50
    strneb r6, [r0, r1]
    ldmneia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    bxne lr
    sub r12, r12, #0x14
    subs r9, r9, #1
    bpl loc_02006c60
loc_02006cdc:
    cmp r7, #2
    blt loc_02006d5c
    sub r0, r4, r5
    add r0, r0, #1
    cmp r0, #5
    bgt loc_02006d5c
    cmp r4, #0xf
    mov r4, #0
    bgt loc_02006d24
    mov r0, r7
    mov r1, #2
    mov r2, #5
    bl func_02009290
    cmp r0, #0
    addne r4, r7, #5
    cmp r7, #0x14
    moveq r4, #0xb
    b loc_02006d44
loc_02006d24:
    mov r0, r7
    mov r1, #2
    mov r2, #5
    bl func_02009290
    cmp r0, #0
    movne r4, r7
    cmp r7, #0xa
    moveq r4, #6
loc_02006d44:
    cmp r4, #0
    ldrne r0, =0x020712f8
    add sp, sp, #0x50
    strneb r6, [r0, r4]
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
loc_02006d5c:
    cmp r7, #1
    ldreq r0, =0x020708a4
    streqb r6, [r0, #0xa55]
    add sp, sp, #0x50
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
}
