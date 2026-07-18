// addr 0x0200037c size 0x4
// BIOS SWI wrapper (Thumb): svc #6; bx lr
#pragma thumb on
void Halt(void) {
    asm {
        swi 6
    }
}
