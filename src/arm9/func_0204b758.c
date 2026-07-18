// addr 0x0204b758 size 0x14 — set CPSR I bit (disable IRQs), return prior I
unsigned int func_0204b758(void) {
    register unsigned int r0_val;
    asm {
        mrs r0_val, cpsr
        orr r1, r0_val, #0x80
        msr cpsr_c, r1
        and r0_val, r0_val, #0x80
    }
    return r0_val;
}
