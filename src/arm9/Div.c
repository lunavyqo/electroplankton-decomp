// addr 0x02000474 size 0x4
// BIOS SWI wrapper (Thumb): svc #9; bx lr
#pragma thumb on
void Div(void) {
    asm {
        swi 9
    }
}
