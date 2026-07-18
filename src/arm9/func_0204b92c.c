// addr 0x204b92c size 0x8
// clz r0, r0
unsigned int func_0204b92c(unsigned int x) {
    unsigned int n;
    asm {
        clz n, x
    }
    return n;
}
