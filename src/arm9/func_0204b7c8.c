// addr 0x0204b7c8 size 0xc
// delay: subs r0,#4; bhs loop; bx lr
void func_0204b7c8(unsigned int n) {
    asm {
    loop:
        subs n, n, #4
        bhs loop
    }
}
