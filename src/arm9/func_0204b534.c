// addr 0x0204b534 size 0x14 — call pair without stack align pad
void func_0204b548(void);
void func_0204b5d8(void);

asm void func_0204b534(void) {
    stmdb sp!, {lr}
    bl func_0204b548
    bl func_0204b5d8
    ldmia sp!, {lr}
    bx lr
}
