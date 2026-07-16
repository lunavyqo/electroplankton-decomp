// addr 0x02002950 size 0x98

extern void *data_020675b4;
extern int data_020675d8;
extern int data_0205d0cc;

void func_020448a8(void *a);
void *func_020448c4(int a, int b);
void func_0204b7d4(void);
void func_0204462c(void *a, void *b, void *c, int d);
int func_0204567c(void *a);
void func_020443f8(void *a);
void func_02002a98(void);

void func_02002950(int a, int b) {
    void *p;
    if (data_020675b4 != 0) {
        func_020448a8(data_020675b4);
    }
    p = func_020448c4(a, b);
    data_020675b4 = p;
    if (p == 0) {
        func_0204b7d4();
    }
    func_0204462c(&data_020675d8, &data_0205d0cc, data_020675b4, 0);
    if (func_0204567c(data_020675b4) == 0) {
        func_0204b7d4();
    }
    func_020443f8(&data_020675d8);
    func_02002a98();
}
