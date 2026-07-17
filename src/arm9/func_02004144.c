// addr 0x02004144 size 0x68

extern unsigned char *data_0206ece4;

void func_02004144(void) {
    int i;
    int off;
    unsigned char *base;
    unsigned char *ip;
    int v;

    i = 0;
    off = 0;
    do {
        base = data_0206ece4;
        ip = base + off;
        v = *(int *)(ip + 0x20);
        if (v != 0) {
            *(int *)(ip + 0x18) = *(int *)(ip + 0x18) - *(int *)(ip + 0x1c);
            base = data_0206ece4;
            ip = base + off;
            if (*(int *)(ip + 0x18) < 0) {
                *(int *)(ip + 0x18) = 0;
            }
        }
        i++;
        off += 0xc;
    } while (i < 6);
}
