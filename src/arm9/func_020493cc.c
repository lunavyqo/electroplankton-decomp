// addr 0x020493cc size 0x14 — clear DTCM halfword at 0x027e0000
void func_020493cc(void) {
    *(volatile unsigned short *)0x027e0000 = 0;
}
