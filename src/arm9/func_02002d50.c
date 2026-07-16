// addr 0x02002d50 size 0x20

extern unsigned char data_0205d0f8;

void func_02002d50(unsigned char a) {
    if (a == 0) {
        data_0205d0f8 = 1;
    } else {
        data_0205d0f8 = a;
    }
}
