// addr 0x0200625c size 0x2d8

void func_02002654(void);
void func_02042ff4(void);
void func_02043124(void);

asm void func_0200625c(void) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #8
    mov r8, r0
    mov r7, r2
    mov r6, r3
    cmp r8, #5
    blt loc_02006284
loc_02006278:
    sub r8, r8, #5
    cmp r8, #5
    bge loc_02006278
loc_02006284:
    ldr r0, =0x0206f658
    ldr r2, =0x020585f0
    ldr r4, [r0]
    mov r0, #3
    ldrb r3, [r4, #0x44]
    cmp r1, #0
    mla r0, r3, r0, r2
    ldrb r0, [r1, r0]
    add r5, r8, r0
    bne loc_0200631c
    add r0, r4, #8
    add r0, r0, r8, lsl #2
    mov r1, #0
    bl func_02043124
    mov r0, r6, lsl #4
    rsb r1, r0, #0x7f
    mov r0, #0x64
    mul r3, r1, r0
    ldr r2, =0x81020409
    mov r0, r3, lsr #0x1f
    smull r1, r4, r2, r3
    add r4, r3, r4
    mov r4, r4, asr #6
    add r4, r0, r4
    str r4, [sp]
    mov r1, #0
    str r1, [sp, #4]
    ldr r0, =0x0206f658
    mov r2, r5
    ldr r0, [r0]
    mov r1, #9
    add r0, r0, #8
    add r0, r0, r8, lsl #2
    mov r3, #0x3c
    bl func_02002654
    add sp, sp, #8
    ldmia sp!, {r4, r5, r6, r7, r8, lr}
    bx lr
loc_0200631c:
    cmp r1, #1
    bne loc_02006394
    add r0, r4, #0x1c
    add r0, r0, r8, lsl #2
    mov r1, #0
    bl func_02043124
    mov r0, r6, lsl #4
    rsb r1, r0, #0x7f
    mov r0, #0x64
    mul r3, r1, r0
    ldr r2, =0x81020409
    mov r0, r3, lsr #0x1f
    smull r1, r4, r2, r3
    add r4, r3, r4
    mov r4, r4, asr #6
    add r4, r0, r4
    str r4, [sp]
    mov r1, #0
    str r1, [sp, #4]
    ldr r0, =0x0206f658
    mov r2, r5
    ldr r0, [r0]
    mov r1, #9
    add r0, r0, #0x1c
    add r0, r0, r8, lsl #2
    mov r3, #0x3c
    bl func_02002654
    add sp, sp, #8
    ldmia sp!, {r4, r5, r6, r7, r8, lr}
    bx lr
loc_02006394:
    cmp r7, #8
    blo loc_020063ac
loc_0200639c:
    sub r0, r7, #8
    and r7, r0, #0xff
    cmp r7, #8
    bhs loc_0200639c
loc_020063ac:
    add r0, r4, #0x30
    add r0, r0, r8, lsl #2
    mov r1, #0
    mov r4, r8, lsl #2
    bl func_02043124
    ldr r0, =0x0206f658
    ldr r0, [r0]
    ldrb r1, [r0, #0x44]
    cmp r1, #2
    bne loc_020064ac
    cmp r8, #2
    bne loc_020064ac
    cmp r7, #0
    beq loc_020063fc
    cmp r7, #3
    beq loc_020063fc
    cmp r7, #4
    beq loc_020063fc
    cmp r7, #7
    bne loc_02006454
loc_020063fc:
    mov r2, r6, lsl #4
    rsb r3, r2, #0x7f
    mov r2, #0x64
    mul ip, r3, r2
    ldr r3, =0x81020409
    ldr r6, =0x020585fc
    smull r2, lr, r3, ip
    add lr, ip, lr
    add r8, r0, #0x30
    mov lr, lr, asr #6
    mov r0, ip, lsr #0x1f
    add lr, r0, lr
    str lr, [sp]
    mov r0, #0
    str r0, [sp, #4]
    add r0, r6, r1, lsl #3
    ldrb r3, [r7, r0]
    mov r2, r5
    add r0, r8, r4
    mov r1, #9
    bl func_02002654
    b loc_02006500
loc_02006454:
    mov r2, r6, lsl #4
    rsb r3, r2, #0x7f
    mov r2, #0x64
    mul r8, r3, r2
    ldr r3, =0x81020409
    ldr r6, =0x020585fc
    smull r2, ip, r3, r8
    add ip, r8, ip
    add r2, r0, #0x30
    mov ip, ip, asr #6
    mov r0, r8, lsr #0x1f
    add ip, r0, ip
    str ip, [sp]
    mov r0, #0
    str r0, [sp, #4]
    add r0, r6, r1, lsl #3
    ldrb r3, [r7, r0]
    add r0, r2, r4
    add r2, r5, #3
    mov r1, #9
    bl func_02002654
    b loc_02006500
loc_020064ac:
    mov r2, r6, lsl #4
    rsb r3, r2, #0x7f
    mov r2, #0x64
    mul ip, r3, r2
    ldr r3, =0x81020409
    ldr r6, =0x020585fc
    smull r2, lr, r3, ip
    add lr, ip, lr
    add r8, r0, #0x30
    mov lr, lr, asr #6
    mov r0, ip, lsr #0x1f
    add lr, r0, lr
    str lr, [sp]
    mov r0, #0
    str r0, [sp, #4]
    add r0, r6, r1, lsl #3
    ldrb r3, [r7, r0]
    mov r2, r5
    add r0, r8, r4
    mov r1, #9
    bl func_02002654
loc_02006500:
    ldr r0, =0x0206f658
    ldr r1, [r0]
    add r0, r1, #0x30
    ldr r1, [r1, #0x48]
    add r0, r0, r4
    bl func_02042ff4
    add sp, sp, #8
    ldmia sp!, {r4, r5, r6, r7, r8, lr}
    bx lr
}
