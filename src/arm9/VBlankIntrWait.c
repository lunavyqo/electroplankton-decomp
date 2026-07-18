// addr 0x0200019a size 0x4
// BIOS SWI wrapper (Thumb): svc #5; bx lr
#pragma thumb on
void VBlankIntrWait(void) {
    asm {
        swi 5
    }
}
