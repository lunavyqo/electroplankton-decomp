// addr 0x020578b4 size 0x4c
// double→int (signed path, r4=1) soft-float (MWCC soft-float runtime)

void ext_02057910(void);
void ext_02057974(void);
void ext_02057cc4(void);
asm void func_020578b4()
{
    stmdb sp!, {r4, r5, r6, r7, r11, r12, lr}
    mov r4, #1
    orrs r5, r3, r2
    bne loc_020578cc
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
    bx lr
loc_020578cc:
    orrs r5, r1, r3
    bne ext_02057974
    mov r1, r2
    bl ext_02057cc4
    cmp r4, #0
    movne r0, r1
    mov r1, #0
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
    bx lr
    stmdb sp!, {r4, r5, r6, r7, r11, r12, lr}
    mov r4, r1
    orr r4, r4, #1
    b ext_02057910
}
