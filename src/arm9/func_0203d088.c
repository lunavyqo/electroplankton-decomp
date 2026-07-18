// addr 0x0203d088 size 0x1c

extern unsigned char *data_02090f8c;

void func_02040314(int a);

void func_0203d088(void) {
    func_02040314(*(int *)(data_02090f8c + 0x40));
}
