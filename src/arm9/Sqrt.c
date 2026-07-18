// addr 0x0200069c size 0x4
// BIOS SWI wrapper (Thumb): svc #13; bx lr
#pragma thumb on
void Sqrt(void) {
    asm {
        swi 13
    }
}
