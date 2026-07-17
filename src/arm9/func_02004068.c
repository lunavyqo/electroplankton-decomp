// addr 0x02004068 size 0x78

extern void *data_0206ebe0;
extern unsigned char data_0206ebe4;
extern void *data_020675b4;
extern int data_020675b0;

void func_02002950(void);
void func_02043118(void *p);
void func_020454f0(int a, void *b);
void func_02003c54(int a);
void func_02002d50(int a);

void func_02004068(void) {
    func_02002950();
    data_0206ebe0 = &data_0206ebe4;
    func_02043118(data_0206ebe0);
    func_02043118((char *)data_0206ebe0 + 4);
    func_020454f0(0, data_020675b4);
    func_02003c54(0x102);
    func_02002d50(0x18);
    data_020675b0 = 0;
}
