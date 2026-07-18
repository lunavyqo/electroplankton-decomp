// addr 0x0201f680 size 0x24 — tail to func_0201fc04(base+(a+b*6)*7, base[0xfd])

void func_0201fc04(unsigned char *cell, unsigned int v);

void func_0201f680(unsigned char *base, int a, int b) {
    func_0201fc04(base + (a + b * 6) * 7, base[0xfd]);
}
