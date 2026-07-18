// addr 0x0204af5c size 0x1c — IC invalidate by MVA range
void func_0204af5c(unsigned int addr, int size) {
    unsigned int end = size + addr;
    addr &= ~0x1fu;
    do {
        asm {
            mcr p15, 0, addr, c7, c5, 1
        }
        addr += 0x20;
    } while ((int)addr < (int)end);
}
