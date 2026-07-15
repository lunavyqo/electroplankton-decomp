// addr 0x020065d4 size 0x120

extern int data_0206f65c;
extern int data_0206f658;
extern int data_0206f660;
extern int data_020675b4;
extern unsigned char data_020585ec;
extern int data_020675b0;

void func_02002950(void);
void func_02043118(void);
void func_020454f0(void);
void func_020455e4(void);
void func_02003c54(void);
void func_02002d50(void);

asm void func_020065d4(void) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r2, =data_0206f65c
    mov r3, #1
    str r3, [r2]
    bl func_02002950
    ldr r0, =data_0206f660
    ldr r1, =data_0206f658
    str r0, [r1]
    bl func_02043118
    ldr r0, =data_0206f658
    ldr r0, [r0]
    add r0, r0, #4
    bl func_02043118
    mov r5, #0
    mov r4, r5
    ldr r6, =data_0206f658
loop:
    ldr r0, [r6]
    add r0, r0, #8
    add r0, r0, r4
    bl func_02043118
    ldr r0, [r6]
    add r0, r0, #0x1c
    add r0, r0, r4
    bl func_02043118
    ldr r0, [r6]
    add r0, r0, #0x30
    add r0, r0, r4
    bl func_02043118
    add r5, r5, #1
    cmp r5, #5
    add r4, r4, #4
    blt loop
    ldr r0, =data_0206f658
    mov r2, #0
    ldr r1, [r0]
    mvn r3, #0
    strb r2, [r1, #0x44]
    ldr r1, [r0]
    mov r2, #0x78
    strb r3, [r1, #0x45]
    ldr r1, [r0]
    ldr r0, =data_020675b4
    str r2, [r1, #0x48]
    ldr r1, [r0]
    mov r0, #9
    bl func_020454f0
    ldr r0, =data_0206f658
    ldr r2, =data_020585ec
    ldr r0, [r0]
    mov r1, #9
    ldrb r3, [r0, #0x44]
    add r0, r0, #4
    ldrb r2, [r2, r3]
    bl func_020455e4
    mov r0, #0
    bl func_02003c54
    mov r0, #0
    bl func_02002d50
    ldr r1, =data_0206f65c
    mov r3, #0
    ldr r0, =data_020675b0
    mov r2, #9
    str r3, [r1]
    str r2, [r0]
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
}
