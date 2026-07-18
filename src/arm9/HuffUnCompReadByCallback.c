// addr 0x02000070 size 0x4
// BIOS SWI wrapper (Thumb): svc #19; bx lr
#pragma thumb on
void HuffUnCompReadByCallback(void) {
    asm {
        swi 19
    }
}
