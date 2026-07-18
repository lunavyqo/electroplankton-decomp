// addr 0x02000262 size 0x4
// BIOS SWI wrapper (Thumb): svc #14; bx lr
#pragma thumb on
void GetCRC16(void) {
    asm {
        swi 14
    }
}
