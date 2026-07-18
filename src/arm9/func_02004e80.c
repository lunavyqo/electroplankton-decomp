// addr 0x02004e80 size 0x88

extern unsigned char data_0206f13c;
extern unsigned char *data_0206f038;
extern void *data_020675b4;
extern unsigned char data_0206f034;
extern int data_020675b0;

void func_02002950(void);
void func_02043118(void *p);
void func_020454f0(int a, void *b);
void func_02003c54(int a);
void func_02002d50(int a);

void func_02004e80(void) {
    func_02002950();
    data_0206f038 = &data_0206f13c;
    func_02043118(data_0206f038);
    func_02043118((char *)data_0206f038 + 4);
    func_020454f0(4, data_020675b4);
    data_0206f034 = 0;
    func_02003c54(0x302);
    func_02002d50(0xc);
    data_020675b0 = 4;
}
