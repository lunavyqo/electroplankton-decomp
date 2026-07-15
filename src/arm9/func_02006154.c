// addr 0x02006154 size 0x108

extern int data_0206f658;

void func_02042f94(void);
void func_02045d94(void);
void func_02042ff4(void);

asm int func_02006154(int arg) {
    stmdb sp!, {r4, r5, lr}
    sub sp, sp, #4
    ldr r1, =data_0206f658
    mov r4, r0
    ldr r0, [r1]
    mov r1, #0
    add r0, r0, #4
    mov r2, #1
    bl func_02042f94
    ldr r0, =data_0206f658
    mov r1, #1
    ldr r0, [r0]
    mov r2, r1
    add r0, r0, #4
    bl func_02042f94
    ldr r0, =data_0206f658
    mov r1, #2
    ldr r0, [r0]
    mov r2, #1
    add r0, r0, #4
    bl func_02042f94
    ldr r0, =data_0206f658
    mov r1, #3
    ldr r0, [r0]
    mov r2, #1
    add r0, r0, #4
    bl func_02042f94
    mov r0, r4, lsl #12
    bl func_02045d94
    ldr r1, =0xe0590e
    mov r3, #0
    umull r5, lr, r0, r1
    mov r2, #0x800
    mla lr, r0, r3, lr
    mov ip, r0, asr #31
    mla lr, ip, r1, lr
    adds r2, r5, r2
    ldr r4, =data_0206f658
    adc r0, lr, #0
    mov r1, r2, lsr #12
    orr r1, r1, r0, lsl #20
    ldr r0, [r4]
    mov r1, r1, asr #12
    str r1, [r0, #0x48]
    ldr r1, [r4]
    add r0, r1, #4
    ldr r1, [r1, #0x48]
    bl func_02042ff4
    mov r0, r4
    ldr r2, [r0]
    ldrsb r1, [r2, #0x45]
    add r1, r1, #1
    strb r1, [r2, #0x45]
    ldr r1, [r0]
    ldrsb r0, [r1, #0x45]
    cmp r0, #0x10
    movge r0, #0
    strgeb r0, [r1, #0x45]
    ldr r0, =data_0206f658
    ldr r0, [r0]
    ldrsb r0, [r0, #0x45]
    add sp, sp, #4
    ldmia sp!, {r4, r5, lr}
    bx lr
}
