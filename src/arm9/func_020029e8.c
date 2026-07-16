// addr 0x020029e8 size 0x3c

extern int data_02067664;
extern int data_020675ac;
extern int data_020675d8;

void func_020443f8(void *a);
void func_020455e4(void *a, int b, int c);

void func_020029e8(int a) {
    func_020443f8(&data_02067664);
    func_020455e4(&data_020675ac, 0, a);
    func_020443f8(&data_020675d8);
}
