// addr 0x204b4b0 size 0x8
// mcr p15, #0, r0, c6, c1, #0
void func_0204b4b0(unsigned int value) {
    asm {
        mcr p15, 0, value, c6, c1, 0
    }
}
