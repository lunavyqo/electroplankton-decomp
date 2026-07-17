// addr 0x02003f3c size 0x48

extern void *data_0206ebe0;

void func_02002654(void *p, int a, int b, int c, int d, int e);

void func_02003f3c(int a) {
    func_02002654(data_0206ebe0, 0, 3, (a >> 4) + 0x3c, 0x20, (a >> 1) - 0x40);
}
