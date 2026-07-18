// addr 0x020099e8 size 0x1c — dual base data_020893d8/data_02089414 store word at +0x2c
extern unsigned char data_020893d8[];
extern unsigned char data_02089414[];

void func_020099e8(int which, int v) {
    unsigned char *p = (which == 0) ? data_020893d8 : data_02089414;
    *(int *)(p + 0x2c) = v;
}
