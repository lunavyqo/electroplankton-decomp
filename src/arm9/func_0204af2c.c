// addr 0x0204af2c size 0x24
asm void func_0204af2c(register unsigned int addr, register int size) {
    mov ip, #0
    add size, size, addr
    bic addr, addr, #0x1f
L0:
    mcr p15, 0, ip, c7, c10, 4
    mcr p15, 0, addr, c7, c14, 1
    add addr, addr, #0x20
    cmp addr, size
    blt L0
    bx lr
}
