// addr 0x020003f4 size 0x4
// BIOS SWI wrapper (Thumb): svc #17; bx lr
#pragma thumb on
void LZ77UnCompReadNormalWrite8bit(void) {
    asm {
        swi 17
    }
}
