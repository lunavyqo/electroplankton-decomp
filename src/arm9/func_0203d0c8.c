// addr 0x0203d0c8 size 0x1c

extern unsigned char *data_02090f8c;

void func_02040c90(int a);

void func_0203d0c8(void) {
    func_02040c90(*(int *)(data_02090f8c + 0x48));
}
