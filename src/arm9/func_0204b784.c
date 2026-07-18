// addr 0x0204b784 size 0x14 — set CPSR I|F bits, return prior I|F
unsigned int func_0204b784(void) {
    register unsigned int r0_val;
    asm {
        mrs r0_val, cpsr
        orr r1, r0_val, #0xc0
        msr cpsr_c, r1
        and r0_val, r0_val, #0xc0
    }
    return r0_val;
}
