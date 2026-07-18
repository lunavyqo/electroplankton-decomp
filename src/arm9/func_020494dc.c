// addr 0x020494dc size 0x18 — clear EXMEMCNT bit 0x80
void func_020494dc(void) {
    volatile unsigned short *p = (volatile unsigned short *)0x04000204;
    *p = (unsigned short)(*p & ~0x80);
}
