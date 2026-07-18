// addr 0x02000204 size 0x4
// BIOS SWI wrapper (Thumb): svc #16; bx lr
#pragma thumb on
void BitUnPack(void) {
    asm {
        swi 16
    }
}
