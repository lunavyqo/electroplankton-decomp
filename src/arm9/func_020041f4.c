// addr 0x020041f4 size 0x74

extern unsigned char *data_0206ece4;

int func_02045db0(int a, int b);

void func_020041f4(int a, int b) {
    int off;
    unsigned char *base;
    unsigned char *p;
    int scaled;
    int v;

    if (a >= 6) {
        do {
            a -= 6;
        } while (a >= 6);
    }
    off = a * 12;
    scaled = b << 12;
    base = data_0206ece4;
    p = base + off;
    *(int *)(p + 0x18) = 0x100000;
    v = func_02045db0(*(int *)(data_0206ece4 + off + 0x18), scaled);
    *(int *)(data_0206ece4 + off + 0x1c) = v;
    *(int *)(data_0206ece4 + off + 0x20) = 1;
}
