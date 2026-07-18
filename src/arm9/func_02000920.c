// addr 0x02000920 size 0x14
// Hand-asm SDK-style word fill (predicated stmlt writeback loop — no pure C)

asm void func_02000920(void) {
    add ip, r1, r2
Lloop:
    cmp r1, ip
    stmltia r1!, {r0}
    blt Lloop
    bx lr
}
