// addr 0x02000776 size 0x6
// BIOS SWI Mod (Thumb): svc #9; adds r0, r1, #0; bx lr
#pragma thumb on
void Mod(void) {
    asm {
        swi 9
        add r0, r1, #0
    }
}
