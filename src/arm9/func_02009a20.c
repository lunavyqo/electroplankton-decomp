// addr 0x02009a20 size 0x1c — dual base store halfword at +0x28
extern unsigned char data_020893d8[];
extern unsigned char data_02089414[];

void func_02009a20(int which, unsigned short v) {
    unsigned char *p = (which == 0) ? data_020893d8 : data_02089414;
    *(unsigned short *)(p + 0x28) = v;
}
