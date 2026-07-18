// addr 0x0204b7bc size 0xc
// mcr p15, #0, r0, c7, c0, #4 — Wait For Interrupt
void func_0204b7bc(void) {
    unsigned int zero = 0;
    asm {
        mcr p15, 0, zero, c7, c0, 4
    }
}
