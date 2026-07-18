// addr 0x02000630 size 0x4
// BIOS SWI wrapper (Thumb): svc #21; bx lr
#pragma thumb on
void RLUnCompReadByCallbackWrite16bit(void) {
    asm {
        swi 21
    }
}
