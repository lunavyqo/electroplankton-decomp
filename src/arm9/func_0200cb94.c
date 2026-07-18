// addr 0x0200cb94 size 0x1c — store halfword to two globals
extern unsigned short data_020898f8;
extern unsigned short data_020898f4;

void func_0200cb94(unsigned short v) {
    data_020898f8 = v;
    data_020898f4 = v;
}
