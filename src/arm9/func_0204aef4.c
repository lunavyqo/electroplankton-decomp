// addr 0x0204aef4 size 0x1c — DC invalidate by MVA range
void func_0204aef4(unsigned int addr, int size) {
    unsigned int end = size + addr;
    addr &= ~0x1fu;
    do {
        asm {
            mcr p15, 0, addr, c7, c6, 1
        }
        addr += 0x20;
    } while ((int)addr < (int)end);
}
