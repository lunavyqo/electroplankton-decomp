// addr 0x0203d110 size 0x1c

extern unsigned char *data_02090f8c;

void func_020407bc(int a);

void func_0203d110(void) {
    func_020407bc(*(int *)(data_02090f8c + 0x44));
}
