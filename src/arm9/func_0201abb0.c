// addr 0x0201abb0 size 0x18 — self+0x40 = data_02062008[idx] (halfword)

extern unsigned short data_02062008[];

void func_0201abb0(unsigned char *self, int idx) {
    *(unsigned short *)(self + 0x40) = data_02062008[idx];
}
