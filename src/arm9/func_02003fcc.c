// addr 0x02003fcc size 0x54

extern int data_020584d4[];
extern int data_020584fc[];
extern void *data_0206ebe0;

void func_02002654(void *p, int a, int b, int c, int d, int e);

void func_02003fcc(int a) {
    func_02002654(data_0206ebe0, 0, 2, data_020584fc[a], 0x7f, data_020584d4[a]);
}
