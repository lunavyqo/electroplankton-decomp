// addr 0x0204b744 size 0x14 — clear CPSR I bit (enable IRQs), return prior I
unsigned int func_0204b744(void) {
    register unsigned int r0_val;
    asm {
        mrs r0_val, cpsr
        bic r1, r0_val, #0x80
        msr cpsr_c, r1
        and r0_val, r0_val, #0x80
    }
    return r0_val;
}
