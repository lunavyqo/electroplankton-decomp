// addr 0x0204bf64 size 0x18 — word copy via predicated ldm/stm writeback (SDK-style)

asm void func_0204bf64(register unsigned int *src, register unsigned int *dst, register int nbytes) {
    add ip, dst, nbytes
L:
    cmp dst, ip
    ldmltia src!, {nbytes}
    stmltia dst!, {nbytes}
    blt L
    bx lr
}
