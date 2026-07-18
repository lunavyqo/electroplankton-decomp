// addr 0x0200493c size 0x90

extern int data_0205d134[];
extern int data_0205d11c[];
extern unsigned char *data_0206ef30;

void func_02002654(void *p, int a, int b, int c, int d, int e);

void func_0200493c(int a, int b) {
    int note;
    int vol = 0x40;

    if (a > 5) {
        a = 5;
    }
    if (a < 0) {
        a = 0;
    }
    if (b > 5) {
        b = 5;
    }
    if (b < 0) {
        b = 0;
    }
    note = *(int *)((char *)data_0205d134 + b * 0x18 + (a << 2));
    if (note < 0x2a) {
        vol = 0x78;
        goto call;
    }
    if (note < 0x2e) {
        vol = 0x60;
    }
call:
    func_02002654(data_0206ef30 + 0x10, 3, 0xb, note, vol, data_0205d11c[a]);
}
