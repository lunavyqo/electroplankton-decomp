// addr 0x02009a04 size 0x1c — dual base load halfword at +0x28
extern unsigned char data_020893d8[];
extern unsigned char data_02089414[];

unsigned short func_02009a04(int which) {
    unsigned char *p = (which == 0) ? data_020893d8 : data_02089414;
    return *(unsigned short *)(p + 0x28);
}
