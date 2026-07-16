// addr 0x02002d30 size 0x20

extern unsigned int data_0205d110;

void func_02002d30(unsigned int a) {
    if (a > 0x10000) {
        data_0205d110 = 0x10000;
    } else {
        data_0205d110 = a;
    }
}
