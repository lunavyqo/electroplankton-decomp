// addr 0x02002c3c size 0xf4

extern void *data_020675b8;
extern int data_02067664;
extern int data_0205d0e0;
extern int data_020675a8;
extern int data_020675ac;
extern int data_020675bc;
extern int data_0206759c;
extern int data_020675a4;

int func_0204f454(void);
void func_0204f464(int a);
void func_020422d4(void);
void *func_020448c4(int a, int b);
void func_0204b7d4(void);
void func_0204462c(void *a, void *b, void *c, int d);
int func_0204567c(void *a);
void func_02043118(void *a);
void func_020454f0(int a, void *b);
void func_02002a98(void);
void func_02003c98(void);
void func_02002644(int a);

void func_02002c3c(int a, int b) {
    void *p;
    if (func_0204f454() == 0) {
        func_0204f464(3);
    }
    func_020422d4();
    p = func_020448c4(a, b);
    data_020675b8 = p;
    if (p == 0) {
        func_0204b7d4();
    }
    func_0204462c(&data_02067664, &data_0205d0e0, data_020675b8, 0);
    if (func_0204567c(data_020675b8) == 0) {
        func_0204b7d4();
    }
    func_02043118(&data_020675a8);
    func_02043118(&data_020675ac);
    func_020454f0(0, data_020675b8);
    func_02002a98();
    func_02003c98();
    func_02002644(0xc350);
    data_020675bc = 0;
    data_0206759c = 0;
    data_020675a4 = 0;
}
