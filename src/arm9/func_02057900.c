// addr 0x2057900 size 0x1b0
void func_02057ab0(void);
asm void func_02057900()
{
    stmdb sp!, {r4, r5, r6, r7, r11, r12, lr}
    eor r4, r1, r3
    mov r4, r4, asr #1
    mov r4, r4, lsl #1
    orrs r5, r3, r2
    bne loc_02057920
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
    bx lr
loc_02057920:
    mov r5, r0, lsr #0x1f
    add r5, r5, r1
    mov r6, r2, lsr #0x1f
    add r6, r6, r3
    orrs r6, r5, r6
    bne loc_02057954
    mov r1, r2
    bl func_02057ab0
    ands r4, r4, #1
    movne r0, r1
    mov r1, r0, asr #0x1f
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
    bx lr
loc_02057954:
    cmp r1, #0
    bge loc_02057964
    rsbs r0, r0, #0
    rsc r1, r1, #0
loc_02057964:
    cmp r3, #0
    bge loc_02057974
    rsbs r2, r2, #0
    rsc r3, r3, #0
loc_02057974:
    orrs r5, r1, r0
    beq loc_02057a98
    mov r5, #0
    mov r6, #1
    cmp r3, #0
    bmi loc_020579a0
loc_0205798c:
    add r5, r5, #1
    adds r2, r2, r2
    adcs r3, r3, r3
    bpl loc_0205798c
    add r6, r6, r5
loc_020579a0:
    cmp r1, #0
    blt loc_020579c0
loc_020579a8:
    cmp r6, #1
    beq loc_020579c0
    sub r6, r6, #1
    adds r0, r0, r0
    adcs r1, r1, r1
    bpl loc_020579a8
loc_020579c0:
    mov r7, #0
    mov r12, #0
    mov r11, #0
    b loc_020579e8
loc_020579d0:
    orr r12, r12, #1
    subs r6, r6, #1
    beq loc_02057a40
    adds r0, r0, r0
    adcs r1, r1, r1
    adcs r7, r7, r7
loc_020579e8:
    subs r0, r0, r2
    sbcs r1, r1, r3
    sbcs r7, r7, #0
    adds r12, r12, r12
    adc r11, r11, r11
    cmp r7, #0
    bge loc_020579d0
loc_02057a04:
    subs r6, r6, #1
    beq loc_02057a38
    adds r0, r0, r0
    adcs r1, r1, r1
    adc r7, r7, r7
    adds r0, r0, r2
    adcs r1, r1, r3
    adc r7, r7, #0
    adds r12, r12, r12
    adc r11, r11, r11
    cmp r7, #0
    bge loc_020579d0
    b loc_02057a04
loc_02057a38:
    adds r0, r0, r2
    adc r1, r1, r3
loc_02057a40:
    ands r7, r4, #1
    moveq r0, r12
    moveq r1, r11
    beq loc_02057a78
    subs r7, r5, #0x20
    movge r0, r1, lsr r7
    bge loc_02057a9c
    rsb r7, r5, #0x20
    mov r0, r0, lsr r5
    orr r0, r0, r1, lsl r7
    mov r1, r1, lsr r5
    b loc_02057a78
    mov r0, r1, lsr r7
    mov r1, #0
loc_02057a78:
    cmp r4, #0
    blt loc_02057a88
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
    bx lr
loc_02057a88:
    rsbs r0, r0, #0
    rsc r1, r1, #0
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
    bx lr
loc_02057a98:
    mov r0, #0
loc_02057a9c:
    mov r1, #0
    cmp r4, #0
    blt loc_02057a88
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
    bx lr
}
