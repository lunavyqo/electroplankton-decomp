// addr 0x0204d0e0 size 0x20 — increment byte at data_02094560[index * 12 + 8]
extern unsigned char data_02094560[];

void func_0204d0e0(int index) {
    unsigned char *p = data_02094560 + index * 0xc;
    p[8] = (unsigned char)(p[8] + 1);
}
