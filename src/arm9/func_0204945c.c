// addr 0x0204945c size 0x18 — set EXMEMCNT bit 0x800
void func_0204945c(void) {
    volatile unsigned short *p = (volatile unsigned short *)0x04000204;
    *p = (unsigned short)(*p | 0x800);
}
