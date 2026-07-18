// addr 0x02051434 size 0x18 — spin while data_02094780 == 1 (ip pool base; pure C uses r1)

extern int data_02094780;

asm void func_02051434(void) {
    ldr ip, [pc, #0xc]
L:
    ldr r0, [ip]
    cmp r0, #1
    beq L
    bx lr
    dcd data_02094780
}
