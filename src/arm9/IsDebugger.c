// addr 0x02000556 size 0x4
// BIOS SWI wrapper (Thumb): svc #15; bx lr
#pragma thumb on
void IsDebugger(void) {
    asm {
        swi 15
    }
}
