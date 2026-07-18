// addr 0x0203c458 size 0x18 — tail to func_02040198(*(p+0x40), 6, 0)

void func_02040198(int a, int b, int c);

void func_0203c458(int unused, unsigned char *p) {
    func_02040198(*(int *)(p + 0x40), 6, 0);
}
