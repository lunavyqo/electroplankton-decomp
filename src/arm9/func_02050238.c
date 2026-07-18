// addr 0x02050238 size 0x18 — spin while data_02094704 == 1 (ip pool base; regperm from pure C)

extern int data_02094704;

asm void func_02050238(void) {
    ldr ip, [pc, #0xc]
L:
    ldr r0, [ip]
    cmp r0, #1
    beq L
    bx lr
    dcd data_02094704
}
