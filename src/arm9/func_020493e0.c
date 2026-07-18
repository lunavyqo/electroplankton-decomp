// addr 0x020493e0 size 0xc
// sole arm9 r1 tail veneer: ldr r1,[pc]; bx r1; .word target
void func_02049514(void);

asm void func_020493e0(void) {
    ldr r1, [pc]
    bx r1
    dcd func_02049514
}
