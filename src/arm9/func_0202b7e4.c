// addr 0x0202b7e4 size 0x24

extern unsigned char data_020630f2[];
extern unsigned char data_020630f0[];

void func_0202b7e4(unsigned int *self, int flag) {
    unsigned char *p = (flag != 0) ? data_020630f2 : data_020630f0;
    *((unsigned char *)self + 0xd) = (unsigned char)flag;
    *self = *(unsigned short *)(p + 4);
}
