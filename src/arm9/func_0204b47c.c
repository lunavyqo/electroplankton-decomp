// addr 0x0204b47c size 0x14 — DTCM base from CP15 c9 (mask 0xfffff000)
asm void func_0204b47c(void) {
    mrc p15, 0, r0, c9, c1, 0
    ldr r1, [pc, #4]
    and r0, r0, r1
    bx lr
    dcd 0xfffff000
}
