// addr 0x020005b6 size 0x4
// BIOS SWI wrapper (Thumb): svc #12; bx lr
#pragma thumb on
void CpuFastSet(void) {
    asm {
        swi 12
    }
}
