// addr 0x020066f4 size 0xf0

extern unsigned char data_020708a4;
extern unsigned char data_02070cac;

void func_0200571c(void);

asm void func_020066f4(void) {
    stmdb sp!, {lr}
    sub sp, sp, #4
    ldr r0, =data_020708a4
    ldr r2, =data_02070cac
    ldrb r3, [r0, #0xa7e]
    ldrb r1, [r0, #0xa80]
    ldrb r2, [r2, r3]
    cmp r1, #0
    movne r1, #0
    strneb r1, [r0, #0xa81]
    addne sp, sp, #4
    ldmneia sp!, {lr}
    bxne lr
    ldrb r1, [r0, #0xa81]
    cmp r1, #0
    beq case0
    cmp r1, #1
    beq case1
    cmp r1, #2
    beq case2
    add sp, sp, #4
    ldmia sp!, {lr}
    bx lr
case0:
    cmp r2, #0x14
    addge r1, r1, #1
    strgeb r1, [r0, #0xa81]
    add sp, sp, #4
    ldmia sp!, {lr}
    bx lr
case1:
    cmp r2, #3
    addlt r2, r1, #1
    movlt r1, #0
    strltb r2, [r0, #0xa81]
    strltb r1, [r0, #0xa82]
    add sp, sp, #4
    ldmia sp!, {lr}
    bx lr
case2:
    cmp r2, #0x14
    movge r1, #1
    strgeb r1, [r0, #0xa81]
    addge sp, sp, #4
    ldmgeia sp!, {lr}
    bxge lr
    ldrb r1, [r0, #0xa82]
    add r1, r1, #1
    strb r1, [r0, #0xa82]
    ldrb r0, [r0, #0xa82]
    cmp r0, #0x21
    addls sp, sp, #4
    ldmlsia sp!, {lr}
    bxls lr
    bl func_0200571c
    ldr r0, =data_020708a4
    mov r1, #0
    strb r1, [r0, #0xa81]
    add sp, sp, #4
    ldmia sp!, {lr}
    bx lr
}
