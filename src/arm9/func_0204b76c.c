// addr 0x0204b76c size 0x18 — restore CPSR I from state, return prior I
unsigned int func_0204b76c(register unsigned int state) {
    asm {
        mrs r1, cpsr
        bic r2, r1, #0x80
        orr r2, r2, state
        msr cpsr_c, r2
        and state, r1, #0x80
    }
    return state;
}
