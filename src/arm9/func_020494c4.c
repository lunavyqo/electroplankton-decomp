// addr 0x020494c4 size 0x18 — set EXMEMCNT bit 0x80
void func_020494c4(void) {
    volatile unsigned short *p = (volatile unsigned short *)0x04000204;
    *p = (unsigned short)(*p | 0x80);
}
