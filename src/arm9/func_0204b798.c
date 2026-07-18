// addr 0x0204b798 size 0x18 — restore CPSR I|F from state, return prior I|F
unsigned int func_0204b798(register unsigned int state) {
    asm {
        mrs r1, cpsr
        bic r2, r1, #0xc0
        orr r2, r2, state
        msr cpsr_c, r2
        and state, r1, #0xc0
    }
    return state;
}
