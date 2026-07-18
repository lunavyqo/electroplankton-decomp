// addr 0x0201f774 size 0x18 — base[(b*6+a)*7 + 6]
unsigned char func_0201f774(unsigned char *base, int a, int b) {
    return *(base + (a + b * 6) * 7 + 6);
}
