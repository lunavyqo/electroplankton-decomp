// addr 0x0204bf50 size 0x14 — word fill via predicated stmltia (SDK-style)
asm void func_0204bf50(register unsigned int val, register unsigned int *dst, register int nbytes) {
    add ip, dst, nbytes
L:
    cmp dst, ip
    stmltia dst!, {val}
    blt L
    bx lr
}
