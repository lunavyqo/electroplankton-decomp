// addr 0x0204b7b0 size 0xc
// mrs r0, cpsr; and r0, r0, #0x1f — CPU mode bits
unsigned int func_0204b7b0(void) {
    register unsigned int cpsr;
    asm {
        mrs cpsr, cpsr
    }
    return cpsr & 0x1fu;
}
