// addr 0x02004268 size 0x110

extern unsigned char *data_0206ece4;
extern unsigned char data_02058524[];
extern unsigned char data_02058494[];

void func_020430b4(void *p, int a);
void func_02002654(void *p, int a, int b, int c, int d, int e);

void func_02004268(int a, int b, int c, int d) {
    int t;
    int vol;
    int scaled;
    int idx;

    if (a >= 6) {
        do {
            a -= 6;
        } while (a >= 6);
    }
    if (b >= 0x168) {
        b = 0x168;
    }
    if (b < 0) {
        b = 0;
    }
    if (d == 0) {
        if (b == *(int *)(data_0206ece4 + (a << 2) + 0x60)) {
            return;
        }
    }
    func_020430b4(data_0206ece4 + (a << 2), 0);
    t = *(int *)(data_0206ece4 + a * 12 + 0x18) >> 12;
    vol = (t << 6) >> 8;
    scaled = b * 50;
    idx = scaled / 360;
    func_02002654(
        data_0206ece4 + (a << 2),
        1,
        a,
        (int)data_02058524[a] + (int)data_02058494[idx + 5],
        vol,
        c
    );
    *(int *)(data_0206ece4 + (a << 2) + 0x60) = b;
}
