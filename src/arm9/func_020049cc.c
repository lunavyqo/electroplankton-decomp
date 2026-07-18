// addr 0x020049cc size 0xb4

extern unsigned char *data_0206ef30;
extern int data_0205d134[];
extern int data_0205d11c[];

void func_020430b4(void *p, int a);
void func_02002654(void *p, int a, int b, int c, int d, int e);

void func_020049cc(int a, int b, int c) {
    unsigned char *base;
    int note;

    if (a >= 4) {
        do {
            a -= 4;
        } while (a >= 4);
    }
    if (b > 5) {
        b = 5;
    }
    if (b < 0) {
        b = 0;
    }
    if (c > 5) {
        c = 5;
    }
    if (c < 0) {
        c = 0;
    }
    func_020430b4(data_0206ef30 + (a << 2), 0);
    base = data_0206ef30;
    note = *(int *)((char *)data_0205d134 + c * 0x18 + (b << 2));
    func_02002654(
        base + (a << 2),
        3,
        a + (*(int *)(base + 0x14) << 2),
        note,
        0x52,
        data_0205d11c[b]
    );
}
