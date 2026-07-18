// addr 0x0203d0a4 size 0x24

extern unsigned char *data_02090f8c;

int func_02040338(int a);

void func_0203d0a4(void) {
    unsigned char *p = data_02090f8c;
    *(int *)(p + 0x40) = func_02040338(4);
}
