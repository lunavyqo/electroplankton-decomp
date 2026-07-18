// addr 0x02000138 size 0x4
// BIOS SWI wrapper (Thumb): svc #0; bx lr
#pragma thumb on
void SoftReset(void) {
    asm {
        swi 0
    }
}
