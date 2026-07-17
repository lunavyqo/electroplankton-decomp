// addr 0x02004884 size 0xb8

extern unsigned char *data_0206ef30;

void func_020455e4(void *a, int b, int c);

void func_02004884(unsigned int a) {
    switch (a) {
    case 0:
        func_020455e4(data_0206ef30 + 0x10, 3, 8);
        break;
    case 1:
        func_020455e4(data_0206ef30 + 0x10, 3, 8);
        break;
    case 2:
        func_020455e4(data_0206ef30 + 0x10, 3, 9);
        break;
    case 3:
        func_020455e4(data_0206ef30 + 0x10, 3, 0xa);
        break;
    }
}
