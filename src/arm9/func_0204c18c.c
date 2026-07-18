// addr 0x204c18c size 0x8
// swp r0, r0, [r1]
unsigned int func_0204c18c(unsigned int value, unsigned int *ptr) {
    unsigned int old;
    asm {
        swp old, value, [ptr]
    }
    return old;
}
