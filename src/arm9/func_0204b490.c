// addr 0x0204b490 size 0x10 — enable MMU bit in CP15 control
unsigned int func_0204b490(void) {
    unsigned int v;
    asm {
        mrc p15, 0, v, c1, c0, 0
        orr v, v, #1
        mcr p15, 0, v, c1, c0, 0
    }
    return v;
}
