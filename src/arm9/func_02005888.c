// addr 0x02005888 size 0x58

extern void *data_0206f344;
extern int data_0205856c[];

void func_02002654(void *p, int a, int b, int c, int d, int e);

void func_02005888(int idx, int e, int b) {
    int i = idx;
    while (i >= 0x10) {
        i -= 0x10;
    }
    func_02002654(data_0206f344, 6, b, data_0205856c[i], 0x50, e);
}
