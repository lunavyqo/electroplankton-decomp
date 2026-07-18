// addr 0x0203d064 size 0x24 — tail to func_02040198(*(p+0x40), 0, 0)

extern unsigned char *data_02090f8c;

void func_02040198(int a, int b, int c);

void func_0203d064(void) {
    func_02040198(*(int *)(data_02090f8c + 0x40), 0, 0);
}
