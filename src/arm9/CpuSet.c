// addr 0x020000dc size 0x4
// BIOS SWI wrapper (Thumb): svc #11; bx lr
#pragma thumb on
void CpuSet(void) {
    asm {
        swi 11
    }
}
