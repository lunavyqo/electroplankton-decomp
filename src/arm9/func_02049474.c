// addr 0x02049474 size 0x18 — clear EXMEMCNT bit 0x800
void func_02049474(void) {
    volatile unsigned short *p = (volatile unsigned short *)0x04000204;
    *p = (unsigned short)(*p & ~0x800);
}
