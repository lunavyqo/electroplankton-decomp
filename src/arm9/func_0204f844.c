// addr 0x0204f844 size 0x18

extern unsigned char data_020946c8;

void func_0204f844(unsigned short mask) {
    while ((*(volatile unsigned short *)(&data_020946c8 + 0x36) & mask) != 0) {
    }
}
