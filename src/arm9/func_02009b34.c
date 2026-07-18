// addr 0x02009b34 size 0x1c — dual base data_020893d8/data_02089414 store word at +0x18
extern unsigned char data_020893d8[];
extern unsigned char data_02089414[];

void func_02009b34(int which, int v) {
    unsigned char *p = (which == 0) ? data_020893d8 : data_02089414;
    *(int *)(p + 0x18) = v;
}
