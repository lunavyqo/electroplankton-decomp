// addr 0x020002ca size 0x4
// BIOS SWI wrapper (Thumb): svc #18; bx lr
#pragma thumb on
void LZ77UnCompReadByCallbackWrite16bit(void) {
    asm {
        swi 18
    }
}
