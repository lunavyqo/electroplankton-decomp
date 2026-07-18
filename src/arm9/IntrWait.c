// addr 0x02000324 size 0x4
// BIOS SWI wrapper (Thumb): svc #4; bx lr
#pragma thumb on
void IntrWait(void) {
    asm {
        swi 4
    }
}
