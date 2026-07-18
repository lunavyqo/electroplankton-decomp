// addr 0x020095bc size 0x1c — dual base data_020893d8/data_02089414 store word at +0x1c
extern unsigned char data_020893d8[];
extern unsigned char data_02089414[];

void func_020095bc(int which, int v) {
    unsigned char *p = (which == 0) ? data_020893d8 : data_02089414;
    *(int *)(p + 0x1c) = v;
}
