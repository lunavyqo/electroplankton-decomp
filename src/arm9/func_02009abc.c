// addr 0x02009abc size 0x28 — dual base store negated coords at +0x20/+0x24

extern unsigned char data_020893d8[];
extern unsigned char data_02089414[];

void func_02009abc(int which, int a, int b) {
    unsigned char *p = (which == 0) ? data_020893d8 : data_02089414;
    *(int *)(p + 0x20) = -a;
    *(int *)(p + 0x24) = -b;
}
