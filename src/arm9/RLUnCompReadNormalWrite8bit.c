// addr 0x02000718 size 0x4
// BIOS SWI wrapper (Thumb): svc #20; bx lr
#pragma thumb on
void RLUnCompReadNormalWrite8bit(void) {
    asm {
        swi 20
    }
}
