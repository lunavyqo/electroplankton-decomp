// addr 0x0201f7ec size 0x20 — set bit 2 at (b*6+a)*7

void func_0201f7ec(unsigned char *base, int a, int b) {
    int idx = (b * 6 + a) * 7;
    base[idx] = (unsigned char)(base[idx] | 4);
}
