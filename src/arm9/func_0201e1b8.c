// addr 0x0201e1b8 size 0x24 — mode@+0x14, load halfword table into +8

extern unsigned short data_0206226e;
extern unsigned short data_0206226c;

void func_0201e1b8(unsigned char *self, int mode) {
    unsigned short *p;
    *(int *)(self + 0x14) = mode;
    if (mode != 0) {
        p = &data_0206226e;
    } else {
        p = &data_0206226c;
    }
    *(int *)(self + 8) = *p;
}
