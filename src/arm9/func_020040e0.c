// addr 0x020040e0 size 0x64

extern unsigned char data_0205d114[];
extern unsigned char data_020675a8;

void func_02002654(void *p, int a, int b, int c, int d, int e);

void func_020040e0(int a) {
    int t;
    if (a > 0x100) {
        a = 0x100;
    } else if (a < 0) {
        a = 0;
    }
    t = a >> 1;
    func_02002654(&data_020675a8, 1, 7, data_0205d114[a / 32], 0x7f, t - 0x40);
}
