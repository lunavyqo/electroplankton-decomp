// addr 0x02009b6c size 0x20 — dual base store two words at +0xc,+0x10
extern unsigned char data_020893d8[];
extern unsigned char data_02089414[];

void func_02009b6c(int which, int a, int b) {
    unsigned char *p = (which == 0) ? data_020893d8 : data_02089414;
    *(int *)(p + 0xc) = a;
    *(int *)(p + 0x10) = b;
}
