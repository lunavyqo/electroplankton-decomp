// addr 0x020041ac size 0x48

extern unsigned char *data_0206ece4;

void func_020041ac(int a) {
    int off;
    unsigned char *p;

    if (a >= 6) {
        do {
            a -= 6;
        } while (a >= 6);
    }
    off = a * 12;
    p = data_0206ece4 + off;
    *(int *)(p + 0x20) = 0;
    p = data_0206ece4 + off;
    *(int *)(p + 0x18) = 0x100000;
}
