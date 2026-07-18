// addr 0x020004e4 size 0x4
// BIOS SWI wrapper (Thumb): svc #3; bx lr
#pragma thumb on
void WaitByLoop(void) {
    asm {
        swi 3
    }
}
