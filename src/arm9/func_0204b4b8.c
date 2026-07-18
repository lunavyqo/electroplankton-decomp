// addr 0x204b4b8 size 0x8
// mcr p15, #0, r0, c6, c2, #0
void func_0204b4b8(unsigned int value) {
    asm {
        mcr p15, 0, value, c6, c2, 0
    }
}
