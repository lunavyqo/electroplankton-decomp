// addr 0x0204af10 size 0x1c — DC clean by MVA range
void func_0204af10(unsigned int addr, int size) {
    unsigned int end = size + addr;
    addr &= ~0x1fu;
    do {
        asm {
            mcr p15, 0, addr, c7, c10, 1
        }
        addr += 0x20;
    } while ((int)addr < (int)end);
}
