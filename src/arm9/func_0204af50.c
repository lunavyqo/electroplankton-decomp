// addr 0x0204af50 size 0xc
// mcr p15, #0, r0, c7, c10, #4 — Data Synchronization Barrier
void func_0204af50(void) {
    unsigned int zero = 0;
    asm {
        mcr p15, 0, zero, c7, c10, 4
    }
}
